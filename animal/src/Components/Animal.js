import React, { useState } from "react";
let animalList = [
  {
    id: 1,
    name: "Begul",
    category: "Animal",
    Image: require("./images/Begul.jpg"),
  },
  {
    id: 2,
    name: "Girafe",
    category: "Animal",
    Image: require("./images/Giraffe.webp"),
  },
  {
    id: 3,
    name: "Pitbull",
    category: "Animal",
    Image: require("./images/Pitbull.webp"),
  },
  {
    id: 4,
    name: "Jaguar",
    category: "Animal",
    Image: require("./images/Jaguar.jpg"),
  },
  {
    id: 5,
    name: "Panda",
    category: "Animal",
    Image: require("./images/Panda.webp"),
  },
  {
    id: 6,
    name: "Tiger",
    category: "Animal",
    Image: require("./images/Tiger.jpg"),
  },
  {
    id: 7,
    name: "Peocock",
    category: "Bird",
    Image: require("./images/Peocock.webp"),
  },
  {
    id: 8,
    name: "Kingfisher",
    category: "Bird",
    Image: require("./images/Kingfisher.webp"),
  },
  {
    id: 9,
    name: "Indian sparrow",
    category: "Bird",
    Image: require("./images/Sparrow.webp"),
  },
  {
    id: 10,
    name: "Parrot",
    category: "Bird",
    Image: require("./images/Parrot.webp"),
  },
];
// <li key={animal.id}>{animal.name}</li>;
function Animal() {
  let [selectedAnimal, setSelectedAnimal] = useState({});
  let [showAnimal, setShowAnimal] = useState(false);
  let showAnimalDetails = (
    <div className="card" style={{ width: "18rem" }}>
      <img
        className="card-img-top"
        src={selectedAnimal.Image}
        alt="Card image cap"
      />
      <div className="card-body">
        <h5 className="card-title">Id:{selectedAnimal.id}</h5>
        <h5 className="card-title">Name:{selectedAnimal.name}</h5>
        <h5 className="card-title">Category:{selectedAnimal.category}</h5>

        <p
          className="btn btn-primary"
          onClick={() => {
            setShowAnimal(false);
          }}
        >
          Back
        </p>
      </div>
    </div>
  );

  let showAnimalList = (
    <div
      style={{
        display: "flex",
        justifyContent: "space-arround",
        flexWrap: "wrap",
      }}
    >
      {animalList.map((animal) => (
        <div className="card m-4" style={{ width: "18rem" }} key={animal.id}>
          <img
            className="card-img-top"
            src={animal.Image}
            alt="Card image cap"
          />
          <div className="card-body">
            <h5 className="card-title">{animal.name}</h5>
            <p
              className="btn btn-primary"
              onClick={() => {
                setSelectedAnimal(animal);
                setShowAnimal(true);
              }}
            >
              View
            </p>
          </div>
        </div>
      ))}
    </div>
  );
  return <>{showAnimal ? showAnimalDetails : showAnimalList}</>;
}

export default Animal;
