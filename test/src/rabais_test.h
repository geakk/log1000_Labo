#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/rabais.h"

class GetRabaisTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(GetRabaisTest);
    CPPUNIT_TEST(test_dumb);
    //CPPUNIT_TEST(test_code_client_plus_petit);
    CPPUNIT_TEST(test_code_client_plus_grand);
    CPPUNIT_TEST(test_code_postal_G0X);
    CPPUNIT_TEST(test_code_postal_H4L);
    CPPUNIT_TEST(test_code_postal_H2X);
    //CPPUNIT_TEST(test_code_postal_invalide);
    CPPUNIT_TEST(test_age_client);
    CPPUNIT_TEST(test_date_adhesion);
    CPPUNIT_TEST(test_montant_facture);


    /*
    CPPUNIT_TEST(test_code_client_plus_grand);
    */
    CPPUNIT_TEST_SUITE_END();
    
private:
	Rabais* objet_a_tester;
    
public:
	// Fonctions d'échafaudage
    void setUp();
    void tearDown();
    
    // Fonctions de tests
    //void test_code_postal_invalide();
    void test_code_postal_G0X();
    void test_code_postal_H4L();
    void test_code_postal_H2X();
    //void test_code_client_plus_petit();
    void test_code_client_plus_grand();
    void test_code_client_egal();
    void test_age_client();
    void test_date_adhesion();
    void test_montant_facture();
    
    void test_dumb();

};




