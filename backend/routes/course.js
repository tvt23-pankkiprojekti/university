const express=require('express');
const router=express.Router();
const course=require('../models/course_model');

router.get('/',function(request, response){
 course.getAllCourses(function(err, result){
    if(err){
        response.send(err);
    }
    else {
        response.json(result);
    }
 });
});

router.get('/:id',function(request, response){
    course.getOneCourse(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result[0]);
        }
    })
});

router.post('/',function(request, response){
    course.addCourse(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.put('/:id',function(request, response){
    course.updateCourse(request.params.id, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.delete('/:id', function(request, response){
    course.deleteCourse(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    });
});

module.exports=router;