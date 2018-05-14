#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


//Tests Konstruktor
TEST_CASE("vec2-constructorX", "[vector]") {
  REQUIRE(Vec2().x_==0);
}

TEST_CASE("vec2-constructorY", "[vector]") {
  REQUIRE(Vec2().y_==0);
}

TEST_CASE("vec2-constructorX_num", "[vector]") {
  REQUIRE(Vec2(1,2).x_==1);
}

TEST_CASE("vec2-constructorY_num", "[vector]") {
  REQUIRE(Vec2(1,2).y_==2);
}

//Tests Addition
TEST_CASE("vec2+=-1", "[vector]") {
  REQUIRE((Vec2()+= Vec2(2.0, 3.0)).x_==2.0f);
  REQUIRE((Vec2(2.0, 5.0) += Vec2(2.0, 1.5)).y_ == 6.5f);
}

TEST_CASE("vec2+=-2", "[vector]") {
  Vec2 test_vector1(2.0f,5.0f);
  Vec2 test_vector2(4.0f,1.0f);
  test_vector1+=test_vector2;
  REQUIRE(test_vector1.x_==6.0f);
  REQUIRE(test_vector1.y_==6.0f);
}

//Tests Subtraktion
TEST_CASE("vec2-=-1", "[vector]") {
  Vec2 test_vector1(2.0f,5.0f);
  Vec2 test_vector2(2.0f,4.0f);
  test_vector1-=test_vector2;
  REQUIRE(test_vector1.x_==0.0f);
  REQUIRE(test_vector1.y_==1.0f);
}

TEST_CASE("vec2-=-2", "[vector]") {
  Vec2 test_vector1(2.0f,5.0f);
  Vec2 test_vector2(4.0f,1.0f);
  test_vector1-=test_vector2;
  REQUIRE(test_vector1.x_==-2.0f);
  REQUIRE(test_vector1.y_==4.0f);
}

//Tests Multiplikation
TEST_CASE("vec2*=-1", "[vector]") {
  Vec2 test_vector1(2.0f,5.0f);
  test_vector1*=2;
  REQUIRE(test_vector1.x_==4.0f);
  REQUIRE(test_vector1.y_==10.0f);
}

TEST_CASE("vec2*=-2", "[vector]") {
  Vec2 test_vector1(1.0f,3.0f);
  test_vector1*=(-2);
  REQUIRE(test_vector1.x_==-2.0f);
  REQUIRE(test_vector1.y_==-6.0f);
}

//Tests Division 
TEST_CASE("vec2/=-1", "[vector]") {
  Vec2 test_vector1(2.0f,6.0f);
  float i = 2.0f;
  test_vector1/=i;
  REQUIRE(test_vector1.x_==1.0f);
  REQUIRE(test_vector1.y_==3.0f);
}

TEST_CASE("vec2/=-2", "[vector]") {
  Vec2 test_vector1(1.0f,-4.0f);
  test_vector1/=(-2);
  REQUIRE(test_vector1.x_==-0.5f);
  REQUIRE(test_vector1.y_==2.0f);
}

//Test 2.4 - Addition
  TEST_CASE("Addition", "[Vector]") {
    REQUIRE((Vec2(2.0, 3.0) + Vec2(2.0, 3.0)).x_==4.0f);
    REQUIRE((Vec2(2.0, 3.0) + Vec2(2.0, 3.0)).y_==6.0f);
  }

   TEST_CASE("Addition2", "[Vector]") {
    REQUIRE((Vec2(-2.0, -3.0) + Vec2(2.0, 4.0)).x_==0.0f);
    REQUIRE((Vec2(-2.0, -3.0) + Vec2(2.0, 4.0)).y_==1.0f);
  }

//Test 2.4 - Subtraktion
  TEST_CASE("Subtraktion", "[Vector]") {
    REQUIRE((Vec2(2.0, 3.0) - Vec2(2.0, 3.0)).x_==0.0f);
    REQUIRE((Vec2(2.0, 3.0) - Vec2(2.0, 5.0)).y_==-2.0f);
  }

   TEST_CASE("Subtraktion2", "[Vector]") {
    REQUIRE((Vec2(-2.0, -3.0) - Vec2(2.0, 4.0)).x_==-4.0f);
    REQUIRE((Vec2(-2.0, -3.0) - Vec2(2.0, 4.0)).y_==-7.0f);
  }

//Test 2.4 - Multiplikation
  TEST_CASE("Multiplikation-Vector1", "[Vector]") {
    REQUIRE((Vec2(2.0, 3.0) * 2).x_==4.0f);
    REQUIRE((Vec2(2.0, 3.0) * -2).y_==-6.0f);
  }

   TEST_CASE("Multiplikation-Vector12", "[Vector]") {
    REQUIRE((Vec2(-2.0, -3.0) * 0).x_==0.0f);
    REQUIRE((Vec2(-2.0, -3.0) * -2).y_==6.0f);
  } 

//Test 2.4 - Division
  TEST_CASE("Division_Vector1", "[Vector]") {
    REQUIRE((Vec2(2.0, 3.0) / 2).x_==1.0f);
    REQUIRE((Vec2(2.0, 6.0) / -2).y_==-3.0f);
  }

   TEST_CASE("Division2_Vector2", "[Vector]") {
    REQUIRE((Vec2(-2.0, -3.0) / 1).x_==-2.0f);
    REQUIRE((Vec2(-2.0, -2.0) / -2).y_==1.0f);
  } 

  //Test 2.4 - Multiplikation 2
  TEST_CASE("multiplication_vector2.1", "[Vector]") {
    REQUIRE((Vec2(2.0, 3.0) * 2).x_==4.0f);
    REQUIRE((Vec2(2.0, 3.0) * -2).y_==-6.0f);
  }

  TEST_CASE("multiplication_vector2.2", "[Vector]") {
    REQUIRE((Vec2(-2.0, -3.0) * 0).x_==0.0f);
    REQUIRE((Vec2(-2.0, -3.0) * -2).y_==6.0f);
  } 

  //Test Bonus == Operator
  TEST_CASE("equal.operator", "[Vector]") {
    Vec2 v1{0,5};
    Vec2 v2{2,3};
    Vec2 v3{2,3};
    REQUIRE((v1==v2)==false);
    REQUIRE((v1==v1)==true);
    REQUIRE((v2==v3)==true);
  } 

//Test 2.5 - Matritzen
 TEST_CASE("Matritzenkonstruktor-Standard", "[Matrix]") {
   Mat2 m1;
   REQUIRE(m1.arr[0]==1);
   REQUIRE(m1.arr[1]==0);
   REQUIRE(m1.arr[2]==0);
   REQUIRE(m1.arr[3]==1);
 }
 
  TEST_CASE("Matritzenkonstruktor-User", "[Matrix]") {
   REQUIRE(Mat2(1,2,3,4).arr[0]==1);
   REQUIRE(Mat2(1,2,3,4).arr[1]==2);
   REQUIRE(Mat2(1,2,3,4).arr[2]==3);
   REQUIRE(Mat2(1,2,3,4).arr[3]==4);
 }
  
  TEST_CASE("Matritzenkonstruktor-User2", "[Matrix]") {
   REQUIRE(Mat2(-1,2,3,4).arr[0]==-1);
   REQUIRE(Mat2(0,0,3,4).arr[1]==0);
   REQUIRE(Mat2(1,2,3.5,4).arr[2]==3.5);
   REQUIRE(Mat2(1,2,3,400).arr[3]==400);
 }

 TEST_CASE("Matritzenk-Multiplikation", "[Matrix]") {
   Mat2 m1(1,2,3,4);
   Mat2 m2(1,2,3,4);
   m1*=(m2);
   REQUIRE(m1.arr[0]==7);
   REQUIRE(m1.arr[1]==10);
   REQUIRE(m1.arr[2]==15);
   REQUIRE(m1.arr[3]==22);
 }

TEST_CASE("Matritzenk-Multiplikation2", "[Matrix]") {
   Mat2 m1(1,2,3,4);
   Mat2 m2;
   m1*=(m2);
   REQUIRE(m1.arr[0]==1);
   REQUIRE(m1.arr[1]==2);
   REQUIRE(m1.arr[2]==3);
   REQUIRE(m1.arr[3]==4);
 }

  TEST_CASE("Matritzen-Multiplikation-nonMember1", "[Matrix]") {
   REQUIRE((Mat2(1,2,3,4)* Mat2(1,2,3,4)).arr[0]==7);
   REQUIRE((Mat2(1,2,3,4)* Mat2(1,2,3,4)).arr[1]==10);
   REQUIRE((Mat2(1,2,3,4)* Mat2(1,2,3,4)).arr[2]==15);
   REQUIRE((Mat2(1,2,3,4)* Mat2(1,2,3,4)).arr[3]==22);
 }

TEST_CASE("Matritzen-Multiplikation-nonMember2", "[Matrix]") {
   REQUIRE((Mat2()* Mat2(1,2,3,4)).arr[0]==1);
   REQUIRE((Mat2()* Mat2(1,2,3,4)).arr[1]==2);
   REQUIRE((Mat2()* Mat2(1,2,3,4)).arr[2]==3);
   REQUIRE((Mat2()* Mat2(1,2,3,4)).arr[3]==4);
 }

//Test 2.6 - Matritzen

TEST_CASE("Matrix mit Vektor", "[matrix]") {
  REQUIRE(((Mat2(1,2,3,4)*Vec2(1,2))).x_==5);
  REQUIRE(((Mat2(1,2,3,4)*Vec2(1,2))).y_==11);
  REQUIRE(((Mat2(0,2,0,-4)*Vec2(1,2))).x_==4);
  REQUIRE(((Mat2(0,2,0,-4)*Vec2(1,2))).y_==-8);
}

TEST_CASE("Vektor mit Matrix", "[matrix]") {
REQUIRE(((Vec2(1,2)*Mat2(1,2,3,4))).x_==5);
  REQUIRE(((Vec2(1,2)*Mat2(1,2,3,4))).y_==11);
  REQUIRE((Vec2(1,2)*(Mat2(0,2,0,-4))).x_==4);
  REQUIRE(((Vec2(1,2)*Mat2(0,2,0,-4))).y_==-8);
} 

TEST_CASE("Determinante", "[matrix]") {
  Mat2 m1{1,2,3,4};
  Mat2 m2{1,2,1,1};
  Mat2 m3{8,5,0,-1};
  REQUIRE(m1.det()==(-2));
  REQUIRE(m2.det()==(-1));
  REQUIRE(m3.det()==(-8));
}

TEST_CASE("Matrix Inverse", "[matrix]") {
  Mat2 m1{1,2,3,4};
  Mat2 m2 = inverse(m1);
  REQUIRE(m2.arr[0]==(-2));
  REQUIRE(m2.arr[1]==1);
  REQUIRE(m2.arr[2]==(1.5));
  REQUIRE(m2.arr[3]==(-0.5));
}

TEST_CASE("Matrix Inverse2", "[matrix]") {
  Mat2 m1{-1,2,-2,0};
  Mat2 m2 = inverse(m1);
  REQUIRE(m2.arr[0]==(0));
  REQUIRE(m2.arr[1]==(-0.5));
  REQUIRE(m2.arr[2]==(0.5));
  REQUIRE(m2.arr[3]==(-0.25));
}

TEST_CASE("Matrix Transponiert", "[matrix]") {
  Mat2 m1{-1,2,-2,0};
  Mat2 m2 = transpose(m1);
  REQUIRE(m2.arr[0]==(-1));
  REQUIRE(m2.arr[1]==(-2));
  REQUIRE(m2.arr[2]==(2));
  REQUIRE(m2.arr[3]==(0));
}
TEST_CASE("Matrix Transponiert2", "[matrix]") {
  Mat2 m1{1,2,3,4};
  Mat2 m2 = transpose(m1);
  REQUIRE(m2.arr[0]==(1));
  REQUIRE(m2.arr[1]==(3));
  REQUIRE(m2.arr[2]==(2));
  REQUIRE(m2.arr[3]==(4));
}

TEST_CASE("Matrix Rotation", "[matrix]") {
  REQUIRE((make_rotation_mat2(1)).arr[0]==Approx(0.54).epsilon(0.1));
  REQUIRE((make_rotation_mat2(1)).arr[1]==Approx(-0.84).epsilon(0.1));
  REQUIRE((make_rotation_mat2(1)).arr[2]==Approx(0.84).epsilon(0.1));
  REQUIRE((make_rotation_mat2(1)).arr[3]==Approx(0.54).epsilon(0.1));
}

TEST_CASE("Matrix Rotation2", "[matrix]") {
  REQUIRE((make_rotation_mat2(0)).arr[0]==1);
  REQUIRE((make_rotation_mat2(0)).arr[1]==0);
  REQUIRE((make_rotation_mat2(0)).arr[2]==0);
  REQUIRE((make_rotation_mat2(0)).arr[3]==1);
}

//Aufgabe 2.7 - Color
TEST_CASE("Color", "[color]") {
  Color black{0.0};
  REQUIRE(black.r == 0.0);
  REQUIRE(black.g == 0.0);
  REQUIRE(black.b == 0.0);
  Color red{1.0f ,0.0f ,0.0f};
  REQUIRE(red.r == 1.0);
  REQUIRE(red.g == 0.0);
  REQUIRE(red.b == 0.0);
}

//Aufgabe 2.8 - Circle & Rectangle
TEST_CASE("Circle", "[circle]") {
  Circle c1;
  Circle c2{3,2,5};
  Circle c3{4};
  REQUIRE(c1.get_radius()==1.0f);
  REQUIRE(c2.get_radius()==3);
  REQUIRE(c3.get_radius()==4);
  REQUIRE((c1.get_center()).x_==0);
  REQUIRE((c2.get_center()).x_==2);
  REQUIRE((c3.get_center()).x_==0);
  REQUIRE((c1.get_center()).y_==0);
  REQUIRE((c2.get_center()).y_==5);
  REQUIRE((c3.get_center()).y_==0);
}

TEST_CASE("Circle-color", "[circle]") {
  Circle c1;
  Color co1{0.2, 0.5, 0.8};
  Circle c2{3, co1};
  Circle c3{co1};
  REQUIRE((c1.get_color()).r==0.0f);
  REQUIRE((c1.get_color()).g==0.0f);
  REQUIRE((c2.get_color()).r==0.2f);
  REQUIRE((c3.get_color()).b==0.8f);
}

TEST_CASE("Rectangle-color", "[circle]") {
  Rectangle r1;
  Color co1{0.2, 0.5, 0.8};
  Rectangle r2{co1};
  REQUIRE((r1.get_color()).r==0.0f);
  REQUIRE((r1.get_color()).g==0.0f);
  REQUIRE((r2.get_color()).r==0.2f);
  REQUIRE((r2.get_color()).b==0.8f);
}


TEST_CASE("Rectangle-Std-Konstruktor", "[rectangle]") {
  Rectangle r1;
  REQUIRE(r1.get_min()==Vec2(0,0));
  REQUIRE(r1.get_max()==Vec2(1,1));
}

TEST_CASE("Rectangle-User-Defined-Konstrukor", "[rectangle]") {
  Vec2 v1{2,5};
  Vec2 v2{3,1};
  Rectangle r1{v1,v2};
  REQUIRE(r1.get_min()==Vec2(2,1));
  REQUIRE(r1.get_max()==Vec2(3,5));
}

//Aufgabe 2.9
TEST_CASE("Circle-Circumference", "[rectangle]") {
  REQUIRE(Circle().circumference()==Approx(6.28).epsilon(0.01));
  REQUIRE(Circle(3).circumference()==Approx(18.85).epsilon(0.01));
  REQUIRE(Circle(5).circumference()==Approx(31.46).epsilon(0.01));
}

TEST_CASE("Rectangle-length", "[rectangle]") {
  REQUIRE(Rectangle().get_length()==1);
  Vec2 v1{2,3};
  Vec2 v2{5,7};
  Rectangle r1{v1, v2};
  REQUIRE(r1.get_length()==3);
}

TEST_CASE("Rectangle-height", "[rectangle]") {
  REQUIRE(Rectangle().get_height()==1);
  Vec2 v1{2,3};
  Vec2 v2{5,7};
  Rectangle r1{v1, v2};
  REQUIRE(r1.get_height()==4);
}

TEST_CASE("Rectangle-circumference", "[rectangle]") {
  REQUIRE(Rectangle().circumference()==4);
  Vec2 v1{2,3};
  Vec2 v2{5,7};
  Rectangle r1{v1, v2};
  REQUIRE(r1.circumference()==14);
}

//Aufgabe 2.13 - is inside
TEST_CASE("Circle_isinside", "[circle") {
  Circle c1{5};
  Vec2 in{1,2};
  Vec2 on{5,5};
  Vec2 out{70,80};
  REQUIRE(c1.is_inside(in)==true);
  REQUIRE(c1.is_inside(on)==false);
  REQUIRE(c1.is_inside(out)==false);
}

TEST_CASE("Rectangle", "[rectangle]") {
  Rectangle rec{Vec2(2,2), Vec2(6,6)};
  Vec2 in{3,3};
  Vec2 on{2,6};
  Vec2 out{70,80};
  REQUIRE(rec.is_inside(in)==true);
  REQUIRE(rec.is_inside(on)==false);
  REQUIRE(rec.is_inside(out)==false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);

}
