// JS code to genrate a random number wothout using any in-built class or function

let counter = 1
let prevRand = 1

const rand = (max = 10) => {
    time = new Date().getTime();
    randValue = ((time / counter) / (prevRand + 1)) % max;
    counter++;
    prevRand = randValue;
    return parseInt(randValue);
}

console.log(rand())
console.log(rand())
console.log(rand(750))
console.log(rand(11350))
console.log(rand(45232))