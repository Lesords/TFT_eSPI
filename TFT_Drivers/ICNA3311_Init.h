// This is the command sequence that initialises the ICNA3311 driver
//
// This setup information uses simple 8-bit SPI writecommand() and writedata() functions
//
// See ST7735_Setup.h file for an alternative format

{
  writecommand(0xFE);
  writedata(0x00);

  writecommand(0xC4);
  writedata(0x80); // work
  // writedata(0x81); // src - not work

  writecommand(0x3A);
  // writedata(0x55);
  writedata(0x77); // src

  writecommand(0x35);
  writedata(0x00);

  writecommand(0x53);
  writedata(0x20);

  writecommand(0x51);
  writedata(0xFF);

  writecommand(0x63);
  writedata(0xFF);

  writecommand(0x2A);
  writedata(0x00);
  writedata(0x10);
  writedata(383 >> 8);
  writedata(383 & 0xff);

  writecommand(0x2B);
  writedata(0x00);
  writedata(0x00);
  writedata(447 >> 8);
  writedata(447 & 0xff);

  writecommand(0x3A);
  writedata(0x55);

  writecommand(0x11); // sleep out

  end_tft_write();
  delay(120);
  begin_tft_write();

  writecommand(0x29); // display on
#if 1

  delay(1); // look like dont' need 1000

  writecommand(0x2C);

  int cnt = 3;
  while (cnt --) {
    int ii = 448 * 368;
    while (ii--) {
      writedata(0xf8);
      writedata(0x00); // red
    }
    delay(1000);

    ii = 448 * 368;
    while (ii--) {
      writedata(0x00);
      writedata(0x1f); // blue
    }
    delay(1000);

    ii = 448 * 368;
    while (ii--) {
      writedata(0x0f);
      writedata(0xf0); // green
    }
    delay(1000);
  }
#endif
}
