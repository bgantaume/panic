#ifdef WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hidapi.h"

#define MAX_STR 255

int main(int argc, char* argv[])
{

  printf("Hello From Panic Button Reader\n");

  int res;
  unsigned char buf[65];
  wchar_t wstr[MAX_STR];
  hid_device *handle;
  int i;

  // Initialize the hidapi library
  res = hid_init();

  // Open the device using the VID, PID,
  // and optionally the Serial number.
  handle = hid_open(0x1130, 0x0202, NULL);

  // Read the Product String
  res = hid_get_product_string(handle, wstr, MAX_STR);
  printf("Found: %ls\n", wstr);

  buf[0]=0;
  while (true) {

    res = hid_get_feature_report(handle, buf, 16);

    if (res && buf[1])
       printf("Button pressed!\n");
    //else
    // printf("nothing\n");
    usleep(100000);
  }
  // Finalize the hidapi library
  res = hid_exit();

  return 0;
}
             