const express=require('express');
const router=express.Router();
const student=require('../models/student_model');

router.get('/',function(request, response){
    student.getAllStudent(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result);
        }
    });
});

module.exports=router;