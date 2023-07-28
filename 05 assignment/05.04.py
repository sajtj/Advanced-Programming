class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

    def get_gender(self):
        return self.gender

    def __str__(self):
        return f"Name: {self.name}, Age: {self.age}, Gender: {self.gender}"


class Student(Person):
    courses = list()

    def __init__(self, name, age, gender, student_id, courses):
        super().__init__(name, age, gender)
        self.student_id = student_id
        self.courses = courses

    def add_course(self, course):
        self.courses.append(course)

    def remove_course(self, course):
        self.courses.remove(course)

    def get_courses(self):
        return self.courses

    def __str__(self):
        return f"Name: {self.name}, Age: {self.age}, Gender: {self.gender}, Student ID: {self.student_id}, Courses: {self.courses}"


inpt = input().split()
x = int(input())
course = list()
for i in range(x):
    course.append(input())
obj = Student(inpt[0], inpt[1], inpt[2], inpt[3], course)
print(obj.__str__())
