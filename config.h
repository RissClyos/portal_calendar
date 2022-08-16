#define WIFI_NAME "name"
#define WIFI_PASS "password"

#define SHOW_DAY
#define SHOW_MONTH
// #define SHOW_YEAR

/**
 * If timezone should be looked up based on IP address using a 3rd-party service.
 */
#define AUTOMATIC_TIME_ZONE
/**
 * The Olson name for your timezone. Requires connection with a 3rd-party service to translate this to
 * the POSIX timezone specification. If AUTOMATIC_TIME_ZONE is set, this will only serve as a backup to that.
 */
#define MANUAL_TIME_ZONE "America/Chicago"
/**
 * The full POSIX specification for your timezone. If AUTOMATIC_TIME_ZONE or MANUAL_TIME_ZONE are set, this will
 * only serve as a backup to those. If not, then no 3rd-party timezone services will be used, however this will
 * need to be changed if your timezone or DST laws change in the future.
 */
#define POSIX_TIME_ZONE "CST6CDT,M3.2.0,M11.1.0"

#define NTP_SERVERS "pool.ntp.org", "time.google.com"

/**
 * How long we'll wait for an NTP sync before giving up
 */
#define NTP_TIMEOUT_SECONDS 10

/**
 * Controls how long before midnight the processor is woken up to sync with NTP so it can have an accurate time for the date changeover.
 * This should be set to the maximum possible amount you expect the internal clock to be off in one day, since it will sleep for an entire day
 * and be woken at this time.
 * 
 * If the clock is running +MINUTES_BEFORE_MIDNIGHT_TO_SYNC fast per day, then in reality it will be woken up MINUTES_BEFORE_MIDNIGHT_TO_SYNC * 2
 * minutes before midnight, which is the maximum duration the NTP measurement will be deemed acceptable for. Any faster than that, and multiple
 * NTP syncs will happen per day, which wastes battery.
 * 
 * If the clock is running -MINUTES_BEFORE_MIDNIGHT_TO_SYNC slow per day, then it will wake up and sync exactly at midnight. Any slower than that,
 * and it won't wake wake up in time for midnight and the date changeover will be late.
 */
#define MINUTES_BEFORE_MIDNIGHT_TO_SYNC 30

/**
 * How many hours we'll go without internet before showing an error. This really shouldn't be longer than a couple days, since the internal
 * clock in the ESP32 is usually off by double-digit minutes per day.
 */
#define ERROR_AFTER_HOURS_WITHOUT_INTERNET 24

/**
 * How long to wait before retrying after an error connecting to WiFi or syncing with NTP.
 */
#define ERROR_RETRY_INTERVAL_MINUTES 60

// Pin assignments

#define SPI_BUS         HSPI
#define RESET_PIN       33
#define DC_PIN          23
#define CS_PIN          15
#define BUSY_PIN        27
