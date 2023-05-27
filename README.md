# CompletedLibrary
An online library need a new software solution. The requirements are:
1. User management system
- There are 3 types of user: administrator, member and guest

- Administrator can manage books (add, show, hide, remove, edit, manage book collections)
- Administrator cannot borrow / return books.

- Member can borrow, return books.
- Member can subscribe/unsubscribe to any book collection.
- Member have start and end year of membership

- Guest can only read a number of pages for each book in the sample book collection.
- Guest does not need to login, require no information but will be given a temporary  

- All user are able to search for book by title, serialnumber
- Every registered user have ID, userame, password, phone number and full name
- Admin and Member is be able to login and logout of the system
- There is one root administrator account with username/password root/root, but number of administrator accounts should can be increased in the future.  
- Guest is be able to register as a member anytime.

2. Book management system
- Books have title, unique serialnumber (6 digits), author name, number of pages, number of free to read pages
- Books can be added, removed, edit information, show publicly or hide by administrator
- Books can be added or removed from collections (Trending, Best selling, New ...) by administrator

3. Collection management system
- A collection is a set of books with: collection ID, collection name, list of books
- A collection can only be created, edited by administrator
- A collection also have a list of subscribed users. Only subscribed user can ask for list of book in the collection.
