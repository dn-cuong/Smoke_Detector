const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

app.get('/', (req, res) => {
    io.emit('smoke', true);
    res.sendStatus(200);
});

app.get('/main', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

io.on('connection', () => {
    console.log('a user connected');
});

server.listen(3000, () => {
    console.log('listening on *:3000');
});