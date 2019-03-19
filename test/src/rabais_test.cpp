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
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 90102);
    CPPUNIT_ASSERT_EQUAL(0.2f,rabais);
}

    //Test que le rabais pour un client est pas 20%
void GetRabaisTest::test_code_client_plus_petit(){
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 12554);
    CPPUNIT_ASSERT_EQUAL(0.05f,rabais);
}

void GetRabaisTest::test_code_postal_G0X(){
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 10456);

    CPPUNIT_ASSERT_EQUAL(0.02f,rabais);
}


void GetRabaisTest::test_code_postal_H4L(){

}


void GetRabaisTest::test_code_postal_H2X(){

}

void GetRabaisTest::test_code_postal_invalide(){
    Facture facture;
    float rabais = this-> objet_a_tester->getRabais(facture, 14770);
    CPPUNIT_ASSERT_EQUAL(0.0f,rabais);

    rabais = this-> objet_a_tester->getRabais(facture, 10456);
    CPPUNIT_ASSERT_EQUAL(0.0f,rabais);

    rabais = this-> objet_a_tester->getRabais(facture, 10456);
    CPPUNIT_ASSERT_EQUAL(0.0f,rabais);

}

