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

router.get('/:usern',function(request,response){
    student.getOneStudent(request.params.usern, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.post('/',function(request, response){
    student.addStudent(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
            //response.send(result[0].affectedRows)
        }
    });
});

router.put('/:usern', function(request, response){
    student.updateStudent(request.params.usern, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            //response.json(result);
            console.log(result.affectedRows);
            response.json(result.affectedRows);
        }
    });
});

router.delete('/:usern',function(request, response){
    student.deleteStudent(request.params.usern, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            //response.json(result);
            console.log(result.affectedRows);
            response.json(result.affectedRows);
        }
    });
});

module.exports=router;