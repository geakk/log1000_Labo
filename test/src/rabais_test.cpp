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

void GetRabaisTest::test_code_client_plus_grand(){
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 90102);
    CPPUNIT_ASSERT_EQUAL(0.2f,rabais);
}

void GetRabaisTest::test_code_client_plus_petit(){
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 12554);
    CPPUNIT_ASSERT_EQUAL(0.2f,rabais);
}