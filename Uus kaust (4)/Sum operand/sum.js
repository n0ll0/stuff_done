let current = [2];

function sumOfArray(array) {
    let sumValue = 0;
    for (let n of array) {
        sumValue += n;   
    }
    return sumValue
}
function iterateSum(Array) {
    for (let i of Array) {
        current.push(Array.length);
        console.log(sumOfArray(Array));
        if (i > 10) break
    }
}

iterateSum(current);