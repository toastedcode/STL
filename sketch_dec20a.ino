#include "LinkedList.hpp"
#include "ListMap.hpp"
#include "Properties.hpp"

List<String>* myList;

Map<String, String>* myMap;

Properties properties;

void setup()
{
   Serial.begin(9600);
   Serial.printf("*************** Linked List Test ************************************\n\n");
   
   myList = new LinkedList<String>();

   Serial.println("Here1");
  
   myList->add("This");
   myList->add("is");
   myList->add("my");
   myList->add("list");

   Serial.printf("myList has %d items\n", myList->length());

   for (List<String>::Iterator it = myList->begin(); it != myList->end(); it++)
   {
     Serial.printf("%s ", (*it).c_str());
   }
   Serial.printf(".\n");

   Serial.printf("myList %s This\n", myList->contains("This") ? "contains" : "does not contain");

   Serial.printf("The 2nd item in the list is %s\n", myList->item(1)->c_str());

   myList->remove("This");

   Serial.printf("Now myList has %d items\n", myList->length());

   myList->clear();

   Serial.printf("After clearn, myList has %d items\n", myList->length());
   
   Serial.printf("*************** List Map Test ************************************\n\n");
   
   myMap = new ListMap<String, String>();
   
   Serial.println("Here 0");

   myMap->put("Kit", "Kat");

   Serial.println("Here 0.5");

   Serial.printf("%s/%s", (*(myMap->find("Kit"))).key.c_str(), (*(myMap->find("Kit"))).value.c_str());

/*
   (*myMap)["This"] = "that";
   Serial.println("Here 0.5");
   
   (*myMap)["Tit"] = "tat";

   Serial.println("Here 1");
   
   myMap->put("Kit", "Kat");

   Serial.println("Here 2");

   Serial.printf("This is to $s, as Tit is to %s, and Kit is to %s\n",
                 (*myMap)["This"].c_str(),
                 (*myMap)["Tit"].c_str(),
                 (*myMap)["Kit"].c_str());

   Serial.println("Here 3");

   Serial.printf("The key \"Kit\" %s in myMap\n", myMap->isSet("Kit") ? "is set" : "is not set");

   Serial.printf("The 2nd item in the map is [%s/%s]\n", myMap->item(1)->key.c_str(), myMap->item(1)->value.c_str());

   Map<String, String>::Iterator findIt = myMap->find("Kit");
   Serial.printf("Found %s\n", (*findIt).value.c_str());

   myMap->erase("Tit");

   Serial.printf("Now myMap has %d items\n", myMap->length());
   */
}

void loop()
{
}
