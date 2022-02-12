int main(int argc, char ** argv)
{
bootblock bootblock_from_disk;
bootblock bootloader_image;
int dev, fd;
int i;
int nread;
if(argc != 3) {
fprintf(stderr, "Usage: %s device lxboot\n", argv[0]);
exit(0);
}
dev = open(argv[1], O_RDWR);
if(dev < 0) {
perror(argv[1]);
exit(0);
}
fd = open(argv[2], O_RDONLY);
if(fd < 0) {
perror(argv[2]);
close(dev);
exit(0);
}
nread = read(fd, &bootloader_image, sizeof(bootblock));
if(nread != sizeof(bootblock)) {
perror("lxboot read");
fprintf(stderr, "expected %zd, got %d\n", sizeof(bootblock), nread);
exit(0);
}
nread = read(dev, &bootblock_from_disk, sizeof(bootblock));
if(nread != sizeof(bootblock)) {
perror("bootblock read");
fprintf(stderr, "expected %zd, got %d\n", sizeof(bootblock), nread);
exit(0);
}
bootloader_image.bootblock_label = bootblock_from_disk.bootblock_label;
bootloader_image.bootblock_checksum = 0;
for(i = 0; i < 63; i++) {
bootloader_image.bootblock_checksum +=
bootloader_image.bootblock_quadwords[i];
}
lseek(dev, 0L, SEEK_SET);
if(write(dev, &bootloader_image, sizeof(bootblock)) != sizeof(bootblock)) {
perror("bootblock write");
exit(0);
}
close(fd);
close(dev);
exit(0);
}
