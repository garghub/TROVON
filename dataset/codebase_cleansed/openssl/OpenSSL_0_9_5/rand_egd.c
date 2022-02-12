int RAND_egd(const char *path)
{
return(-1);
}
int RAND_egd(const char *path)
{
int ret = -1;
struct sockaddr_un addr;
int len, num;
int fd = -1;
unsigned char buf[256];
memset(&addr, 0, sizeof(addr));
addr.sun_family = AF_UNIX;
if (strlen(path) > sizeof(addr.sun_path))
return (-1);
strcpy(addr.sun_path,path);
len = offsetof(struct sockaddr_un, sun_path) + strlen(path);
fd = socket(AF_UNIX, SOCK_STREAM, 0);
if (fd == -1) return (-1);
if (connect(fd, (struct sockaddr *)&addr, len) == -1) goto err;
buf[0] = 1;
buf[1] = 255;
write(fd, buf, 2);
if (read(fd, buf, 1) != 1) goto err;
if (buf[0] == 0) goto err;
num = read(fd, buf, 255);
if (num < 1) goto err;
RAND_seed(buf, num);
if (RAND_status() == 1)
ret = num;
err:
if (fd != -1) close(fd);
return(ret);
}
