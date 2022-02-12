GSList *local_interfaces_to_list(void)
{
GSList *interfaces = NULL;
#ifdef HAVE_GETIFADDRS
struct ifaddrs *ifap;
struct ifaddrs *ifa;
int family;
char ip[INET6_ADDRSTRLEN];
if (getifaddrs(&ifap)) {
goto end;
}
for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
if (ifa->ifa_addr == NULL)
continue;
family = ifa->ifa_addr->sa_family;
memset(ip, 0x0, INET6_ADDRSTRLEN);
switch (family) {
case AF_INET:
{
struct sockaddr_in *addr4 = (struct sockaddr_in *)ifa->ifa_addr;
ws_inet_ntop4(&addr4->sin_addr, ip, sizeof(ip));
break;
}
case AF_INET6:
{
struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)ifa->ifa_addr;
ws_inet_ntop6(&addr6->sin6_addr, ip, sizeof(ip));
break;
}
default:
break;
}
if (!g_strcmp0(ip, "127.0.0.1") || !g_strcmp0(ip, "::1"))
continue;
if (*ip) {
interfaces = g_slist_prepend(interfaces, g_strdup(ip));
}
}
freeifaddrs(ifap);
end:
#endif
return interfaces;
}
