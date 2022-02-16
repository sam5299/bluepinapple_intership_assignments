function convert(funString) {
  let newString = "";
  if(funString.startsWith("(")) {
    let end_index = funString.indexOf("=>");
    let start_braces_present = funString.includes("{");
    let end_braces_present = funString.includes("}");

    if(start_braces_present && end_braces_present) {
       newString = "function"+funString.slice(0, end_index)+" " + funString.slice(end_index+2);
    } else {
       newString = "function"+funString.slice(0, end_index)+" {\n" + funString.slice(end_index+2)+" \n}";
    }
    return newString;
  } 
  if(funString.startsWith("function")) {
     let start_bracket = funString.indexOf("(");
     let end_bracket = funString.indexOf(")");
     
      newString = funString.slice(start_bracket,end_bracket+1)+" => "+funString.slice(end_bracket+1,funString.length);

     return newString;
  }
}

let converted = convert("(a,b)=> {console.log(a)}");

console.log(converted);
