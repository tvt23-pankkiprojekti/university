const express=require('express');
const router=express.Router();
const student=require('../models/student_model');

router.post('/',function(request, response){
    student.login(request.body.username, function(err,result){
        if(err){

        }
        else{
            console.log(result);
            //response.json(result[0].password);
            response.send(result[0].password);
        }
    });

});

module.exports=router;