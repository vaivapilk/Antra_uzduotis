#include "pch.h"
#include "CppUnitTest.h"
#include "../Klases_2_0/Studentas.h"
#include "../Klases_2_0/Studentas.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodVardas)
		{
			std::string p = "Aaa";
			std::string v = "Bbb";
			Studentas st(v, p, { 5,6,7,8 }, 8);
			Assert::AreEqual(v, st.vardas());
		}
		TEST_METHOD(TestMethodGalutinisM)
		{
			std::string p = "Aaa";
			std::string v = "Bbb";
			Studentas st(v, p, { 5,6,7,8,8 }, 8);
			st.skaiciavimai();
			float g = 7.6;
			Assert::AreEqual(g, st.galutinis_m());
		}
		TEST_METHOD(TestMethodGalutinisV)
		{
			std::string p = "Aaa";
			std::string v = "Bbb";
			Studentas st(v, p, { 5,6,7,8,8 }, 8);
			st.skaiciavimai();
			float g = 7.58;
			Assert::AreEqual(g, st.galutinis_v());
		}
		TEST_METHOD(TestMethodSumaV)
		{
			std::string p = "Aaa";
			std::string v = "Bbb";
			Studentas st1(v, p, { 5,6,7 }, 8);
			Studentas st2(v, p, { 8,8 }, 0);
			st1 += st2;
			st1.skaiciavimai();
			float g = 7.52;
			Assert::AreEqual(g, st1.galutinis_v());
		}
	};
}
