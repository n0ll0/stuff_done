const Sqrt = (x) => {
    let Output = x/2;
    for (let i = 0; i < 50; i++) {
        Output -= (Output * Output - x) / (2 * Output);
    }
    return Output
}
function start(A) {
    console.log(Sqrt(A));
    console.log(Math.sqrt(A));
}
start(19051);