const db=require('../database');

const student={
    getAllStudent(callback){
        return db.query("SELECT * FROM student",callback);
    }
}

module.exports=student;