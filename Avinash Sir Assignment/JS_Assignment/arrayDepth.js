function findDepth(arr) {
  let depth = 1;
  arr.forEach((currentvalue, index, copy) => {
    if(Array.isArray(currentvalue)) {
      depth = depth+findDepth(currentvalue);
    }
  });
  return depth;
}

let arrayDepth = findDepth([1, [2, [3, 4]]]);
console.log(arrayDepth);