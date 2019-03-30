#include "rabais_test.h"

void GetRabaisTest::setUp() 
{
		this->objet_a_tester = new Rabais("data/clients.dat");
}

void GetRabaisTest::tearDown() 
{
		delete this->objet_a_tester;
}

void GetRabaisTest::test_dumb()
{
    CPPUNIT_ASSERT_EQUAL(0,0);
}

    //Test que le rabais pour un employe est de 20%
void GetRabaisTest::test_code_client_plus_grand()
{
    tm dateTest;
    dateTest.tm_year = 1998;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(100000, "Paul", "Paul", 69, "H4R", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());
   
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon le code client", 0.2f,rabais);
}

void GetRabaisTest::test_code_postal_G0X()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(9999, "Paul", "Eric", 23, "G0X", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.02f, rabais);
}


void GetRabaisTest::test_code_postal_H4L()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(1234, "Paul", "Luc", 29, "H4L", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.01f, rabais);
}


void GetRabaisTest::test_code_postal_H2X()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(3333, "Lafleur", "Jean", 39, "H2X", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la zone a un client", 0.01f, rabais);
}

void GetRabaisTest::test_age_client()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(10000, "Paul", "Jean", 66, "H4R", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon l'age du client", 0.05f, rabais);
}

void GetRabaisTest::test_date_adhesion()
{
    tm dateTest;
    dateTest.tm_year = 1998;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(2468, "Jean","Luc", 22, "H4R", dateTest);
    Facture facture;
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon la date d'adhesion", 0.05f, rabais);
}
    
void GetRabaisTest::test_montant_facture()
{
    tm dateTest;
    dateTest.tm_year = 2019;
    dateTest.tm_mon = 1;
    dateTest.tm_mday = 1;
    Client* clientTest = new Client(2468, "Martel","Sylvain", 33, "H4R", dateTest);
    Facture facture;
    facture.ajouterItem(1000);
    objet_a_tester->ajouterClient(clientTest);
    float rabais = this->objet_a_tester->getRabais(facture, clientTest->getID());

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Un rabais invalide est assigne selon le montant de la facture", 0.05f, rabais);
}
