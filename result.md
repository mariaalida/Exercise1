Both the incrementing and the decrementing function shares a global variable. When running the functions, they run at the same time but are not communicating. This means that they may retrive the value of i at the same time and when i is refreshed, it is not both increased and decreased. 

