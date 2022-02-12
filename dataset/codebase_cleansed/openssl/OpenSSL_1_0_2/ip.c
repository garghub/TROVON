int ip_initialise(void)
{
struct sigaction sa;
sa.sa_handler = SIG_IGN;
sa.sa_flags = 0;
sigemptyset(&sa.sa_mask);
if (sigaction(SIGPIPE, &sa, NULL) != 0)
return 0;
return 1;
}
int ip_create_listener_split(const char *ip, unsigned short port)
{
struct sockaddr_in in_addr;
int fd = -1;
int reuseVal = 1;
if ((fd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
goto err;
if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)(&reuseVal),
sizeof(reuseVal)) != 0)
goto err;
in_addr.sin_family = AF_INET;
memcpy(&in_addr.sin_addr.s_addr, ip, 4);
in_addr.sin_port = htons(port);
if (bind(fd, (struct sockaddr *)&in_addr, sizeof(struct sockaddr_in)) !=
0)
goto err;
if (listen(fd, IP_LISTENER_BACKLOG) != 0)
goto err;
return fd;
err:
if (fd != -1)
close(fd);
return -1;
}
int ip_create_connection_split(const char *ip, unsigned short port)
{
struct sockaddr_in in_addr;
int flags, fd = -1;
if ((fd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
goto err;
if (((flags = fcntl(fd, F_GETFL, 0)) < 0) ||
(fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0))
goto err;
in_addr.sin_family = AF_INET;
memcpy(&in_addr.sin_addr.s_addr, ip, 4);
in_addr.sin_port = htons(port);
if ((connect(fd, (struct sockaddr *)&in_addr,
sizeof(struct sockaddr_in)) != 0) && (errno != EINPROGRESS))
goto err;
return fd;
err:
if (fd != -1)
close(fd);
return -1;
}
int ip_parse_address(const char *address, const char **parsed_ip,
unsigned short *parsed_port, int accept_all_ip)
{
char buf[256];
struct hostent *lookup;
unsigned long port;
const char *ptr = strstr(address, ":");
const char *ip = all_local_ip;
if (!ptr) {
if (!accept_all_ip)
return 0;
ptr = address;
goto determine_port;
}
if ((ptr - address) > 255)
return 0;
memset(buf, 0, 256);
memcpy(buf, address, ptr - address);
ptr++;
if ((lookup = gethostbyname(buf)) == NULL) {
fprintf(stderr, "hostname lookup for '%s' failed\n", buf);
return 0;
}
ip = lookup->h_addr_list[0];
determine_port:
if (strlen(ptr) < 1)
return 0;
if (!int_strtoul(ptr, &port) || (port > 65535))
return 0;
*parsed_ip = ip;
*parsed_port = (unsigned short)port;
return 1;
}
int ip_create_listener(const char *address)
{
const char *ip;
unsigned short port;
if (!ip_parse_address(address, &ip, &port, 1))
return -1;
return ip_create_listener_split(ip, port);
}
int ip_create_connection(const char *address)
{
const char *ip;
unsigned short port;
if (!ip_parse_address(address, &ip, &port, 0))
return -1;
return ip_create_connection_split(ip, port);
}
int ip_accept_connection(int listen_fd)
{
return accept(listen_fd, NULL, NULL);
}
