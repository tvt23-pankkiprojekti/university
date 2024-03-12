const db=require('../database');
const bcrypt=require('bcryptjs');

const student={
    getAllStudent(callback){
        return db.query("SELECT * FROM student",callback);
    },
    addStudent(newStudent, callback){
        bcrypt.hash(newStudent.password,10,function(err,hashedPassword){
            return db.query("INSERT INTO student VALUES(?,?,?,?,?,?)",[newStudent.username,newStudent.fname,newStudent.lname, newStudent.streetaddress,newStudent.email,hashedPassword],callback);
        });
    },
    updateStudent(un,updateData, callback){
        bcrypt.hash(updateData.password, 10,function(err,hashedPassword){
            return db.query("UPDATE student SET fname=?, lname=?,email=?,streetaddress=?,password=? WHERE username=?",[updateData.fname, updateData.lname, updateData.email, updateData.streetaddress, hashedPassword, un],callback);
        });

    },
    getOneStudent(un, callback){
        return db.query("SELECT * FROM student WHERE username=?",[un],callback);

    },
    deleteStudent(un, callback){
        return db.query("DELETE FROM student WHERE username=?",[un],callback);
    },
    login(un, callback){
        return db.query("SELECT password FROM student WHERE username=?",[un], callback);
    },
    studentgrade(un, callback){
        return db.query("select course_name, gredit_points,grade, DATE_FORMAT(grade_date,'%d.%m.%Y') as grade_date        from student inner join grade on student.username=grade.username  inner join course on grade.idcourse=course.idcourse WHERE student.username=?",[un],callback);
    }
}

module.exports=student;