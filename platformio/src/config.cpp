/* Configuration options for esp32-weather-epd.
 * Copyright (C) 2022-2023  Luke Marzen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <Arduino.h>
#include "config.h"

// PINS
// ADC pin used to measure battery voltage
const uint8_t PIN_BAT_ADC  = 13; // A0 for micro-usb firebeetle
// Pins for Waveshare e-paper Driver Board
const uint8_t PIN_EPD_BUSY =  4; // 5 for micro-usb firebeetle
const uint8_t PIN_EPD_CS   =  5; //was 2
const uint8_t PIN_EPD_RST  = 21;
const uint8_t PIN_EPD_DC   = 22;
const uint8_t PIN_EPD_SCK  = 18;
const uint8_t PIN_EPD_MISO = 19; // 19 Master-In Slave-Out not used, as no data from display
const uint8_t PIN_EPD_MOSI = 23;
const uint8_t PIN_EPD_PWR  = 14; // Irrelevant if directly connected to 3.3V

// WIFI
const char *WIFI_SSID     = "DODO-98EA";
const char *WIFI_PASSWORD = "Sanjay55";
const unsigned long WIFI_TIMEOUT = 10000; // ms, WiFi connection timeout.

// OPENWEATHERMAP API
// OpenWeatherMap API key, https://openweathermap.org/
const String OWM_APIKEY   = "e67d8a8c6a3b3ecd0115b80807cd3a19";
const String OWM_ENDPOINT = "api.openweathermap.org";
// OpenWeatherMap One Call 2.5 API is deprecated for all new free users
// (accounts created after Summer 2022).
//
// Please note, that One Call API 3.0 is included in the "One Call by Call"
// subscription only. This separate subscription includes 1,000 calls/day for
// free and allows you to pay only for the number of API calls made to this
// product.
//
// Here’s how to subscribe and avoid any credit card changes:
// - Go to https://home.openweathermap.org/subscriptions/billing_info/onecall_30/base?key=base&service=onecall_30
// - Follow the instructions to complete the subscription.
// - Go to https://home.openweathermap.org/subscriptions and set the "Calls per
//   day (no more than)" to 1,000. This ensures you will never overrun the free
//   calls.
const String OWM_ONECALL_VERSION = "3.0";

// LOCATION
// Set your latitude and longitude.
// (used to get weather data as part of API requests to OpenWeatherMap)
const String LAT = "-37.8362";
const String LON = "144.6722";
// City name that will be shown in the top-right corner of the display.
const String CITY_STRING = "Melbourne";

// TIME
// For list of time zones see
// https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
const char *TIMEZONE = "AEST-10AEDT,M10.1.0,M4.1.0/3"; 
// Time format used when displaying sunrise/set times. (Max 11 characters)
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
// const char *TIME_FORMAT = "%l:%M%P"; // 12-hour ex: 1:23am  11:00pm
const char *TIME_FORMAT = "%H:%M";   // 24-hour ex: 01:23   23:00
// Time format used when displaying axis labels. (Max 11 characters)
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
// const char *HOUR_FORMAT = "%l%P"; // 12-hour ex: 1am  11pm
const char *HOUR_FORMAT = "%H";      // 24-hour ex: 01   23
// Date format used when displaying date in top-right corner.
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
const char *DATE_FORMAT = "%a, %B %e"; // ex: Sat, January 1
// Date/Time format used when displaying the last refresh time along the bottom
// of the screen.
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
const char *REFRESH_TIME_FORMAT = "%x %H:%M";
// NTP_SERVER_1 is the primary time server, while NTP_SERVER_2 is a fallback.
// pool.ntp.org will find the closest available NTP server to you.
const char *NTP_SERVER_1 = "pool.ntp.org";
const char *NTP_SERVER_2 = "time.nist.gov";
// If you encounter the 'Failed To Fetch The Time' error, try increasing
// NTP_TIMEOUT or select closer/lower latency time servers.
const unsigned long NTP_TIMEOUT = 20000; // ms
// Sleep duration in minutes. (aka how often esp32 will wake for an update)
// Aligned to the nearest minute boundary and must evenly divide 60.
// For example, if set to 30 (minutes) the display will update at 00 or 30
// minutes past the hour. (range: [2-60])
const long SLEEP_DURATION = 60;
// If BED_TIME == WAKE_TIME, then this battery saving feature will be disabled.
// (range: [0-23])
const int BED_TIME  = 19; // Last update at 00:00 (midnight) until WAKE_TIME.
const int WAKE_TIME = 05; // Hour of first update after BED_TIME, 06:00.

// HOURLY OUTLOOK GRAPH
// Number of hours to display on the outlook graph. (range: [8-48])
const int HOURLY_GRAPH_MAX = 24;

// BATTERY
// To protect the battery upon LOW_BATTERY_VOLTAGE, the display will cease to
// update until battery is charged again. The ESP32 will deep-sleep (consuming
// < 11μA), waking briefly check the voltage at the corresponding interval (in
// minutes). Once the battery voltage has fallen to CRIT_LOW_BATTERY_VOLTAGE,
// the esp32 will hibernate and a manual press of the reset (RST) button to
// begin operating again.
const float BATTERY_WARN_VOLTAGE     = 3.40; // (volts)
const float LOW_BATTERY_VOLTAGE      = 3.20; // (volts)
const float VERY_LOW_BATTERY_VOLTAGE = 3.10; // (volts)
const float CRIT_LOW_BATTERY_VOLTAGE = 3.00; // (volts)
const unsigned long LOW_BATTERY_SLEEP_INTERVAL      = 30;  // (minutes)
const unsigned long VERY_LOW_BATTERY_SLEEP_INTERVAL = 120; // (minutes)

// See config.h for the below options
// E-PAPER PANEL
// LOCALE
// UNITS
// AIR QUALITY INDEX
// WIND ICON PRECISION
// FONTS
// ALERTS
// BATTERY MONITORING

