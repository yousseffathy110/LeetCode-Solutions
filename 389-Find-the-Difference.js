const findTheDifference = (s, t) => {
  let first = s.split(\\).sort();
  let second = t.split(\\).sort();
  for (let i = 0; i < second.length; i++)
    if (first[i] !== second[i]) return second[i];
};