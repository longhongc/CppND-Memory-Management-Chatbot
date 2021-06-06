My main problem is about Task 5.
My understanding of Task 5:
The chatbot must first instaniate on the stack memory at chatlogic
The chatbot instance has to be passed down as below through move semantic of the chatbot object.
chatlogic -> rootnode -> other nodes
However, the chatlogic still has to be able to access to the chatbot resource, while not owning it.

My Questions:
I don't know how to make a ChatBot on the stack memory and move it to the rootnode, while maintaining a way to access the moved instance.
I konw how to do them seperately, but I don't know how to do them at the same time.
How can I get the memory address for chatlogic after I use move semantic on the instance and pass it down to rootnode?
