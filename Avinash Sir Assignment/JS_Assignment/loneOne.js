function countLoneOnes(number) {
  let one_count = 0;
  let last_reminder = null;
  let current_reminder = null;
  while(number > 0) {
    current_reminder = number%10;
    if(last_reminder == 1 && current_reminder==1) {
      one_count--;
    }
    if(last_reminder!=1 && current_reminder==1) {
      one_count++;
    }
    last_reminder = current_reminder;
    number = parseInt(number / 10);
  }
  console.log(one_count);
}

countLoneOnes(1101);