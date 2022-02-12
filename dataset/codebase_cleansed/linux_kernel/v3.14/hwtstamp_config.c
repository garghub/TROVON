static int
lookup_value(const char **names, int size, const char *name)
{
int value;
for (value = 0; value < size; value++)
if (names[value] && strcasecmp(names[value], name) == 0)
return value;
return -1;
}
static const char *
lookup_name(const char **names, int size, int value)
{
return (value >= 0 && value < size) ? names[value] : NULL;
}
static void list_names(FILE *f, const char **names, int size)
{
int value;
for (value = 0; value < size; value++)
if (names[value])
fprintf(f, " %s\n", names[value]);
}
static void usage(void)
{
fputs("Usage: hwtstamp_config if_name [tx_type rx_filter]\n"
"tx_type is any of (case-insensitive):\n",
stderr);
list_names(stderr, tx_types, N_TX_TYPES);
fputs("rx_filter is any of (case-insensitive):\n", stderr);
list_names(stderr, rx_filters, N_RX_FILTERS);
}
int main(int argc, char **argv)
{
struct ifreq ifr;
struct hwtstamp_config config;
const char *name;
int sock;
if ((argc != 2 && argc != 4) || (strlen(argv[1]) >= IFNAMSIZ)) {
usage();
return 2;
}
if (argc == 4) {
config.flags = 0;
config.tx_type = lookup_value(tx_types, N_TX_TYPES, argv[2]);
config.rx_filter = lookup_value(rx_filters, N_RX_FILTERS, argv[3]);
if (config.tx_type < 0 || config.rx_filter < 0) {
usage();
return 2;
}
}
sock = socket(AF_INET, SOCK_DGRAM, 0);
if (sock < 0) {
perror("socket");
return 1;
}
strcpy(ifr.ifr_name, argv[1]);
ifr.ifr_data = (caddr_t)&config;
if (ioctl(sock, (argc == 2) ? SIOCGHWTSTAMP : SIOCSHWTSTAMP, &ifr)) {
perror("ioctl");
return 1;
}
printf("flags = %#x\n", config.flags);
name = lookup_name(tx_types, N_TX_TYPES, config.tx_type);
if (name)
printf("tx_type = %s\n", name);
else
printf("tx_type = %d\n", config.tx_type);
name = lookup_name(rx_filters, N_RX_FILTERS, config.rx_filter);
if (name)
printf("rx_filter = %s\n", name);
else
printf("rx_filter = %d\n", config.rx_filter);
return 0;
}
