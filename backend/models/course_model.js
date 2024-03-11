const db=require('../database');

const course={
    getAllCourses(callback){
        return db.query("SELECT * FROM course",callback);
    },
    getOneCourse(id, callback){
        return db.query("SELECT * FROM course WHERE idcourse=?",[id],callback);
    },
    addCourse(newCourse,callback){
        return db.query("INSERT INTO course(course_name, gredit_points) VALUES(?,?)",[newCourse.course_name, newCourse.gredit_points],callback);
    },
    updateCourse(id, updateCourse,callback){
        return db.query("UPDATE course SET course_name=?, gredit_points=? WHERE idcourse=?",[updateCourse.course_name, updateCourse.gredit_points, id],callback);
    },
    deleteCourse(id,callback){
        return db.query("DELETE FROM course WHERE idcourse=?",[id],callback);
    }
}

module.exports=course;