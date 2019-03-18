#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/rabais.h"

class GetRabaisTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(GetRabaisTest);
    CPPUNIT_TEST(test_dumb);
    CPPUNIT_TEST(test_code_client_plus_petit);
    CPPUNIT_TEST(test_code_client_plus_grand);
    CPPUNIT_TEST_SUITE_END();
    
private:
	Rabais* objet_a_tester;
    
public:
	// Fonctions d'échafaudage
    void setUp();
    void tearDown();
    
    // Fonctions de tests
    void test_code_client_plus_petit();
    void test_code_client_plus_grand();
    void test_code_client_egal();
    void test_modulo_diviseur_positif();
    void test_modulo_diviseur_tres_positif();
    void test_dumb();
};




