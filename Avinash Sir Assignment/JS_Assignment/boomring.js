function countBoomring(arr) {
  let count_boomring = 0;
  if(arr.length < 3) return count_boomring;

  for(let i=0; i<arr.length-2; i++) {
    if(arr[i] === arr[i+2]) count_boomring++;
  }

  return count_boomring;
}

let count = countBoomring([3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]);
console.log(count);