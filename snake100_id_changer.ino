/* Minimum_Source*/

#define DYNAMIXEL_NUM 10
#define ID_TABLE_SIZE (DYNAMIXEL_NUM * 2)
#define PRESENT_ID_INDEX(i) (i * 2)
#define NEW_ID_INDEX(i) (i * 2 + 1)

int id_table[ID_TABLE_SIZE] = {
  1, 10,
  2, 20,
  3, 30,
  4, 40,
  5, 50,
  6, 60,
  7, 70,
  8, 80,
  9, 90,
  0, 100,
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 

}

