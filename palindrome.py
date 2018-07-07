def true(): print("It's a palindrome")


def false(): print("Its not a palindrome")


def _palindrome(word):
    if len(word) == 1: 
    	return true()
    if len(word) < 1:
        print("You did not enter a word")
        return false()
    if word[::-1] == word: 
    	return true()
    else: 
    	return false()


_palindrome(input("Enter a word:"))
