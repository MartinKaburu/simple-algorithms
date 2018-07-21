def true(): print("It's a palindrome")


def false(): print("Its not a palindrome")


def _palindrome(word):
    #print(word)
    for c in word:
      if not c.isalnum():
        del c
    if len(word) == 1: 
    	return true()
    if len(word) < 1:
        print("You did not enter a word")
        return false()
    word = word.replace(" ", "")
    word2 = word[::-1]
    print(word)
    if word2 == word: 
    	return true()
    else: 
    	return false()


_palindrome(input("Enter a word:"))
