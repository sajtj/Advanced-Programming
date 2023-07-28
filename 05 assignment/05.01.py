class User:
    def __init__(self, username, email, password):
        self.username = username
        self.email = email
        self.password = password
        self.friends = []

    def createPost(self, content):
        post = Post(self.username, content)
        return post

    def addFriend(self, user):
        self.friends.append(user)


class Post:
    def __init__(self, author, content):
        self.author = author
        self.content = content
        self.likes = []
        self.comments = []

    def addLike(self, user):
        self.likes.append(user)

    def addComment(self, user, comment):
        self.comments.append((user, comment))

    def getLikesCount(self):
        return int(self.likes[0][0])

    def getComments(self):
        return self.comments


class Comment:
    def __init__(self, author, content):
        self.author = author
        self.content = content


n = int(input())

users = {}
posts = []
default_user = User('default', '', '')
for _ in range(n):
    command = input().split()
    if command[0] == '1':
        post_content = command[1]
        post = default_user.createPost(post_content)
        posts.append(post)

    elif command[0] == '2':
        friend_username = command[1]
        default_user.addFriend(friend_username)

    elif command[0] == '3':
        post_arg = command[1]
        if post_arg.startswith('post'):
            post_index = int(post_arg[4:]) - 1
        else:
            post_index = int(post_arg) - 1
        user = command[2:]
        posts[post_index].addLike(user)

    elif command[0] == '4':
        post_arg = command[1]
        if post_arg.startswith('post'):
            post_index = int(post_arg[4:]) - 1
        else:
            post_index = int(post_arg) - 1
        comment_content = ' '.join(command[2:-1])
        user = command[-1]
        posts[post_index].addComment(user, comment_content)

    elif command[0] == '5':
        post_arg = command[1]
        if post_arg.startswith('post'):
            post_index = int(post_arg[4:]) - 1
        else:
            post_index = int(post_arg) - 1
        post = posts[post_index]
        likes_count = post.getLikesCount()
        liked_users = post.likes

        if likes_count > 0:
            print(" ".join(liked_users[0]))
        else:
            print(likes_count)

    elif command[0] == '6':
        post_arg = command[1]
        if post_arg.startswith('post'):
            post_index = int(post_arg[4:]) - 1
        else:
            post_index = int(post_arg) - 1
        post = posts[post_index]
        comments = post.getComments()

        for comment in comments:
            print(comment[0], ':', comment[1], end=" ")
        print("")
