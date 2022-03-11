function getChilds(arr, parentId) {
  let result = arr.filter((currentValue) => currentValue.parent == parentId);
  result.forEach((element) => {
    tempResult = getChilds(arr, element.id);
    result = [...result, ...tempResult];
  });
  return result;
}

let treeArray = [
  { id: 0, value: "Zero", parent: -1 },
  { id: 1, value: "One", parent: 0 },
  { id: 2, value: "Two", parent: 1 },
  { id: 3, value: "Three", parent: 1 },
  { id: 4, value: "Four", parent: 1 },
  { id: 5, value: "Five", parent: 1 },
  { id: 6, value: "Six", parent: 4 },
  { id: 7, value: "Seven", parent: 4 },
  { id: 8, value: "Eight", parent: 5 },
  { id: 9, value: "Nine", parent: 5 },
  { id: 10, value: "Ten", parent: 7 },
  { id: 11, value: "Eleven", parent: 7 },
  { id: 12, value: "Twelve", parent: 5 },
  { id: 13, value: "Thirteen", parent: 6 },
  { id: 14, value: "Fourteen", parent: 9 },
  { id: 15, value: "Fifteen", parent: 13 },
  { id: 16, value: "Sixteen", parent: 13 },
  { id: 17, value: "Seventeen", parent: 16 },
  { id: 18, value: "Eighteen", parent: 16 },
];

let parentId = 4;
let childArray = getChilds(treeArray, parentId);
console.log("Child tree from node having id :" + parentId);
console.table(childArray);

// old logic for getting childrens of result array
/*
let visited = [];

function selfCalled(childArray) {
  console.log("called");
  childArray.forEach((element) => {
    if (!visited.includes(element.id)) {
      visited.push(element.id);
      let result = getChilds(treeArray, element.id);
      if (result.length != 0) {
        result.forEach((ele) => {
          childArray.push(ele);
        });
        selfCalled(childArray);
      }
    }
  });
}
selfCalled(childArray);
console.log(visited);
*/
