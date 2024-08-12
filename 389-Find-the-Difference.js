const findTheDifference = (s, t) => {
    let first = s.split(\\).sort(),
        second = t.split(\\).sort();
    for (let i = 0; i < second.length; i++)
        if (first[i] !== second[i]) return second[i];
    return second[second.length - 1];
};