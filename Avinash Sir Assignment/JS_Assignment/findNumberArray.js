function findNumberArray(arr) {
  let number_arr = [];

  arr.forEach((currentValue, index, copy) => {
    if(currentValue.search(/[0-9]/)!=-1) number_arr.push(currentValue);
  });
  return number_arr;
}

let arr = ["abc", "xyz"];

let result_arr = findNumberArray(arr);

console.log(result_arr);