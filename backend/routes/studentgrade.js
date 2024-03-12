const express=require('express');
const router=express.Router();
const student=require('../models/student_model');

router.get('/:user',function(request, response){
    student.studentgrade(request.params.user, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

module.exports=router;