const mysql=require('mysql2');
const dotenv=require('dotenv');
const { dot } = require('node:test/reporters');
dotenv.config();

//const conn="mysql://uniuser:unipass@127.0.0.1:3306/university";

const connection=mysql.createPool(process.env.MySQL_DB);

module.exports=connection;