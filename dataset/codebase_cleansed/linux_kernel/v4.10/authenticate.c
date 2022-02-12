int main(int argc, char *argv[])
{
unsigned int timeout = 10000;
char *capdev;
int fd, ret;
if (argc != 2) {
printf("\nUsage: ./firmware <Path of the gb-cap-X dev>\n");
return 0;
}
capdev = argv[1];
printf("Opening %s authentication device\n", capdev);
fd = open(capdev, O_RDWR);
if (fd < 0) {
printf("Failed to open: %s\n", capdev);
return -1;
}
printf("Get UID\n");
ret = ioctl(fd, CAP_IOC_GET_ENDPOINT_UID, &uid);
if (ret < 0) {
printf("Failed to get UID: %s (%d)\n", capdev, ret);
ret = -1;
goto close_fd;
}
printf("UID received: 0x%llx\n", *(long long unsigned int *)(uid.uid));
printf("Get IMS certificate\n");
ret = ioctl(fd, CAP_IOC_GET_IMS_CERTIFICATE, &cert);
if (ret < 0) {
printf("Failed to get IMS certificate: %s (%d)\n", capdev, ret);
ret = -1;
goto close_fd;
}
printf("IMS Certificate size: %d\n", cert.cert_size);
printf("Authenticate module\n");
memcpy(authenticate.uid, uid.uid, 8);
ret = ioctl(fd, CAP_IOC_AUTHENTICATE, &authenticate);
if (ret < 0) {
printf("Failed to authenticate module: %s (%d)\n", capdev, ret);
ret = -1;
goto close_fd;
}
printf("Authenticated, result (%02x), sig-size (%02x)\n",
authenticate.result_code, authenticate.signature_size);
close_fd:
close(fd);
return ret;
}
