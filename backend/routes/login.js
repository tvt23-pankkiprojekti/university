const express=require('express');
const router=express.Router();
const student=require('../models/student_model');
const bcrypt=require('bcryptjs');

router.post('/',function(request, response){
    if(request.body.username && request.body.password){
        student.login(request.body.username, function(err,result){
            if(err){
                console.log(err);
                response.send(err);
            }
            else{
                if(result.length >0){
                    bcrypt.compare(request.body.password, result[0].password, function(err, compareResult){
                        if(compareResult){
                            response.send(true);
                        }
                        else {
                            console.log("Väärä salasana");
                            response.send(false);
                        }
                    })
                }
                else {
                    console.log("tunnusta ei ole");
                    response.send(false);
                }

            }
        });
    }
    else {
        console.log("Tunnus tai salasana puuttuu")
        response.send(false);
    }


});

module.exports=router;