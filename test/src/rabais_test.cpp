#include "rabais_test.h"

void GetRabaisTest::setUp() {
		this->objet_a_tester = new Rabais("data/clients.dat");
}

void GetRabaisTest::tearDown() {
		delete this->objet_a_tester;
}

void GetRabaisTest::test_dumb(){
    CPPUNIT_ASSERT_EQUAL(0,0);
}

    //Test que le rabais pour un employe est de 20%
void GetRabaisTest::test_code_client_plus_grand(){
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(10000, "Client", "Test", 25, "H7Y", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon le code client", 0.2f,rabais);
    delete clientTest;
}

    //Test que le rabais pour un client est pas 20%
void GetRabaisTest::test_code_client_plus_petit(){
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1000, "Client", "Test", 25, "H7Y", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon le code client", 0.05f,rabais);
    delete clientTest;
}

void GetRabaisTest::test_code_postal_G0X(){
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1000, "Client", "Test", 25, "H4L", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.02f, rabais);

    delete clientTest;
}


void GetRabaisTest::test_code_postal_H4L(){
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1000, "Client", "Test", 25, "H4L", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.01f, rabais);

    delete clientTest;
}


void GetRabaisTest::test_code_postal_H2X()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1000, "Client", "Test", 25, "H2X", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.01f, rabais);

    delete clientTest;
}

void GetRabaisTest::test_code_postal_invalide(){
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1000, "Client", "Test", 25, "H6T", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.00f, rabais);

    delete clientTest;
}

