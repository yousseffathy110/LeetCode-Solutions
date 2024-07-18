const mergeAlternately = (wordOne, wordTwo) => {
  const word1 = wordOne.split("");
  const word2 = wordTwo.split("");
  const mergedArr = [];
  const maxLength = Math.max(word1.length, word2.length);

  for (let i = 0; i < maxLength; i++) {
    if (i < word1.length) mergedArr.push(word1[i]);
    if (i < word2.length) mergedArr.push(word2[i]);
  }
  return mergedArr.join("");
};
