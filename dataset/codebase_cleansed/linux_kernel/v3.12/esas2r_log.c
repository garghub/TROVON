static const char *translate_esas2r_event_level_to_kernel(const long level)
{
switch (level) {
case ESAS2R_LOG_CRIT:
return KERN_CRIT;
case ESAS2R_LOG_WARN:
return KERN_WARNING;
case ESAS2R_LOG_INFO:
return KERN_INFO;
case ESAS2R_LOG_DEBG:
case ESAS2R_LOG_TRCE:
default:
return KERN_DEBUG;
}
}
static int esas2r_log_master(const long level,
const struct device *dev,
const char *format,
va_list args)
{
if (level <= event_log_level) {
unsigned long flags = 0;
int retval = 0;
char *buffer = event_buffer;
size_t buflen = EVENT_LOG_BUFF_SIZE;
const char *fmt_nodev = "%s%s: ";
const char *fmt_dev = "%s%s [%s, %s, %s]";
const char *slevel =
translate_esas2r_event_level_to_kernel(level);
spin_lock_irqsave(&event_buffer_lock, flags);
if (buffer == NULL) {
spin_unlock_irqrestore(&event_buffer_lock, flags);
return -1;
}
memset(buffer, 0, buflen);
if (dev == NULL) {
snprintf(buffer, buflen, fmt_nodev, slevel,
ESAS2R_DRVR_NAME);
} else {
snprintf(buffer, buflen, fmt_dev, slevel,
ESAS2R_DRVR_NAME,
(dev->driver ? dev->driver->name : "unknown"),
(dev->bus ? dev->bus->name : "unknown"),
dev_name(dev));
}
buffer += strlen(event_buffer);
buflen -= strlen(event_buffer);
retval = vsnprintf(buffer, buflen, format, args);
if (retval < 0) {
spin_unlock_irqrestore(&event_buffer_lock, flags);
return -1;
}
if (strlen(event_buffer) < buflen)
strcat(buffer, "\n");
printk(event_buffer);
spin_unlock_irqrestore(&event_buffer_lock, flags);
}
return 0;
}
int esas2r_log(const long level, const char *format, ...)
{
int retval = 0;
va_list args;
va_start(args, format);
retval = esas2r_log_master(level, NULL, format, args);
va_end(args);
return retval;
}
int esas2r_log_dev(const long level,
const struct device *dev,
const char *format,
...)
{
int retval = 0;
va_list args;
va_start(args, format);
retval = esas2r_log_master(level, dev, format, args);
va_end(args);
return retval;
}
int esas2r_log_hexdump(const long level,
const void *buf,
size_t len)
{
if (level <= event_log_level) {
print_hex_dump(translate_esas2r_event_level_to_kernel(level),
"", DUMP_PREFIX_OFFSET, 16, 1, buf,
len, true);
}
return 1;
}
