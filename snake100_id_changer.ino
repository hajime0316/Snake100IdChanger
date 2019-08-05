/* Minimum_Source*/
#include "find_different_number.h"
#include <stdio.h>

#define DYNAMIXEL_NUM 2
#define ID_TABLE_SIZE (DYNAMIXEL_NUM * 2)
#define PRESENT_ID_INDEX(i) (i * 2)
#define NEW_ID_INDEX(i) (i * 2 + 1)

// Dynamixel 通信に関するマクロ
#define DXL_BUS_SERIAL1 1 //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2 //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3 //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#define BaudRate 3

// Dynamixel LEDの色に関するマクロ
#define ledred 1
#define ledgreen 2
#define ledblue 4
#define ledcyan (ledgreen | ledblue)
#define ledmagenta (ledblue | ledred)
#define ledyellow (ledred | ledgreen)
#define ledwhite (ledred | ledgreen | ledblue)

int id_table[ID_TABLE_SIZE] = {
  1, 7,
  101, 125
};

void setup() {
  // put your setup code here, to run once:
  
  // Dynamixelの初期化
  Dynamixel Dxl(DXL_BUS_SERIAL1);
  //XL-320の初期化をちょっと待つ
  delay(1000);
  Dxl.begin(3);
  delay(500); // このdelayがないと，100以上のIDを持つDxl
              // が動かない！

  // キーボード入力待ち
  while(SerialUSB.read() != 'g');

  // すべてのDynamixelに一時IDを設定(ID変更時にIDが被らないようにするため)
  for (int i = 0; i < DYNAMIXEL_NUM; i++)
  {
    int tmp_id;

    // 一時ID決定
    tmp_id = find_different_number(id_table, ID_TABLE_SIZE, 0, 254);
    
    SerialUSB.println(tmp_id);
    // 一時ID送信
    Dxl.setID(id_table[PRESENT_ID_INDEX(i)], tmp_id);
    // IDテーブル更新
    id_table[PRESENT_ID_INDEX(i)] = tmp_id;
  }

  // 新しいIDの設定
  for(int i = 0; i < DYNAMIXEL_NUM; i++) {
    Dxl.setID(id_table[PRESENT_ID_INDEX(i)], id_table[NEW_ID_INDEX(i)]);
  }
  
  // LEDを順番に点灯(順番通りに光らなかったら，なんか間違ってる)
  for (int i = 0; i < DYNAMIXEL_NUM; i++)
  {
    Dxl.ledOn(id_table[NEW_ID_INDEX(i)], ledblue);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 

}

