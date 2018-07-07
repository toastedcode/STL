#include "FS.h"
#include "LinkedList.hpp"
#include "ListMap.hpp"
#include "Logger.h"
#include "Properties.hpp"

List<String>* myList;
List<String>* myOtherList;

Map<String, String>* myMap;

Properties properties;

void setup()
{
   Serial.begin(9600);
   SPIFFS.begin();
   
   Logger::setLogger(new SerialLogger());

   Serial.printf("*************** Linked List Test ************************************\n\n");
   
   myList = new LinkedList<String>();
  
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

   myOtherList = new LinkedList<String>();

   *myOtherList = *myList;

   Serial.printf("myOtherList has %d items\n", myOtherList->length());
   
   for (List<String>::Iterator it = myOtherList->begin(); it != myOtherList->end(); it++)
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

   myMap->put("Kit", "Kat");

   Map<String, String>::Iterator foundIt = myMap->find("Kit");

   Serial.printf("foundIt: %s/%s\n", (*foundIt).key.c_str(), (*foundIt).value.c_str());
   
   (*myMap)["This"] = "That";
   (*myMap)["Tit"] = "Tat";

   foundIt = myMap->find("This");

   Serial.printf("foundIt: %s/%s\n", (*foundIt).key.c_str(), (*foundIt).value.c_str());

   Serial.printf("This is to %s, as Tit is to %s, and Kit is to %s\n",
                 (*myMap)["This"].c_str(),
                 (*myMap)["Tit"].c_str(),
                 (*myMap)["Kit"].c_str());

   Serial.printf("The key \"Kit\" %s in myMap\n", myMap->isSet("Kit") ? "is set" : "is not set");

   Serial.printf("The 2nd item in the map is [%s/%s]\n", myMap->item(1)->key.c_str(), myMap->item(1)->value.c_str());

   myMap->erase("Tit");

   Serial.printf("Now myMap has %d items\n", myMap->length());

   Serial.printf("*************** Properties Test ************************************\n\n");

   properties.load("/robox.properties");

   Serial.println(properties.toString().c_str());
}

void loop()
{
}
