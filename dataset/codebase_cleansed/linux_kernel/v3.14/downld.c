void squirt(int req_type, int bdid, struct image_info *ii)
{
struct downldio *dliop;
int size_buf;
int sfd;
struct stat sb;
if (ii->pathname) {
sfd = open(ii->pathname, O_RDONLY);
if (sfd < 0 ) {
myperror(ii->pathname);
goto squirt_end;
}
if (fstat(sfd, &sb) == -1 ) {
myperror(ii->pathname);
goto squirt_end;
}
ii->len = sb.st_size;
}
size_buf = ii->len + sizeof(struct downldio);
dliop = (struct downldio *) malloc(size_buf);
if (dliop == NULL) {
fprintf(stderr,"%s: can't get %d bytes of memory; aborting\n",
pgm, size_buf);
exit (1);
}
if (ii->pathname)
read(sfd, dliop->image.fi.fepimage, ii->len);
else
memcpy(dliop ->image.fi.fepimage, ii->image, ii->len);
dliop->req_type = req_type;
dliop->bdid = bdid;
dliop->image.fi.len = ii->len;
if (debugflag)
printf("sending %d bytes of %s %s from %s\n",
ii->len,
(ii->type == IFEP) ? "FEP" : (ii->type == IBIOS) ? "BIOS" : "CONFIG",
ii->name ? ii->name : "",
(ii->pathname) ? ii->pathname : "internal image" );
if (ioctl(fd, DIGI_DLREQ_SET, (char *) dliop) == -1) {
if(errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",pgm);
errorprint = 0;
}
sleep(2);
}
squirt_end:
if (ii->pathname) {
close(sfd);
}
free(dliop);
}
void consider_file_rescan(struct image_info *ii)
{
int sfd;
int len;
struct stat sb;
if (ii->pathname) {
sfd = open (ii->pathname, O_RDONLY) ;
if (sfd < 0 ) {
myperror(ii->pathname);
exit(1) ;
}
if( fstat(sfd,&sb) == -1 ) {
myperror(ii->pathname);
exit(1);
}
if (ii->image && (sb.st_mtime == ii->mtime))
goto end_rescan;
ii->len = len = sb.st_size;
ii->mtime = sb.st_mtime;
if ( ii->image ) {
free( ii->image );
}
ii->image = malloc(len) ;
if (ii->image == NULL) {
fprintf(stderr,
"%s: can't get %d bytes of memory; aborting\n",
pgm, len);
exit (1);
}
if (read(sfd, ii->image, len) < len) {
fprintf(stderr,"%s: read error on %s; aborting\n",
pgm, ii->pathname);
exit (1);
}
end_rescan:
close(sfd);
}
}
struct image_info * find_conc_image()
{
int x;
struct image_info *i = NULL;
for ( x = 0; x < nimages; x++ ) {
i=&image_list[x];
if(i->type != ICONC)
continue;
consider_file_rescan(i) ;
ip = (struct downld_t *) image_list[x].image;
if (ip == NULL) continue;
if ((dp->dl_type != 'P' ) && ( ip->dl_srev == dp->dl_srev ))
return i;
}
return NULL;
}
int main(int argc, char **argv)
{
struct downldio dlio;
int offset, bsize;
int x;
char *down, *image, *fname;
struct image_info *ii;
pgm = argv[0];
dp = &dlio.image.dl;
while((argc > 2) && !strcmp(argv[1],"-d")) {
debugflag++ ;
argc-- ;
argv++ ;
}
if(argc < 2) {
fprintf(stderr,
"usage: %s download-device [image-file] ...\n",
pgm);
exit(1);
}
if (debugflag == 0) {
switch (fork())
{
case 0:
break;
case -1:
return 1;
default:
return 0;
}
setsid();
fclose(stdin);
fclose(stdout);
fclose(stderr);
}
while (1) {
if( (fd = open(argv[1], O_RDWR)) == -1 ) {
sleep(1);
}
else
break;
}
nimages = argc - 2;
for (count = 0; images[count].type != IBAD; ++count) ;
nimages += count;
image_list = images;
for(x = 2; x < argc; x++) {
int xx;
if( (fname = strrchr(argv[x],'/')) == NULL)
fname = argv[x];
else
fname++;
for (xx = 0; xx < count; xx++) {
if (strcmp(fname, images[xx].fname) == 0 ) {
images[xx].pathname = argv[x];
images[xx].image = NULL;
}
}
}
sleep(3);
for(;;) {
if (debugflag)
printf("b4 get ioctl...");
if (ioctl(fd,DIGI_DLREQ_GET, &dlio) == -1 ) {
if (errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",
pgm);
errorprint = 0;
}
sleep(2);
} else {
if (debugflag)
printf("dlio.req_type is %d bd %d\n",
dlio.req_type,dlio.bdid);
switch(dlio.req_type) {
case DLREQ_BIOS:
for ( x = 0; x < nimages; x++ ) {
if(image_list[x].type != IBIOS)
continue;
if ((dlio.image.fi.type & FAMILY) ==
image_list[x].family) {
if ( image_list[x].family == T_CX ) {
if ((dlio.image.fi.type & BUSTYPE)
== T_PCIBUS ) {
if ( image_list[x].subtype
== T_PCIBUS )
break;
}
else {
break;
}
}
else if ( image_list[x].family == T_EPC ) {
if ((dlio.image.fi.type & BUSTYPE)
== T_PCIBUS ) {
if ( image_list[x].subtype
== T_PCIBUS )
break;
}
else {
if ( image_list[x].subtype
!= T_PCIBUS )
break;
}
}
else
break;
}
else if ((dlio.image.fi.type & SUBTYPE) == image_list[x].subtype) {
if ( image_list[x].subtype == T_PCXR ) {
break;
}
}
}
if ( x >= nimages) {
if(nodldprint) {
fprintf(stderr,
"%s: cannot find correct BIOS image\n",
pgm);
nodldprint = 0;
}
dlio.image.fi.type = -1;
if (ioctl(fd, DIGI_DLREQ_SET, &dlio) == -1) {
if (errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",
pgm);
errorprint = 0;
}
sleep(2);
}
break;
}
squirt(dlio.req_type, dlio.bdid, &image_list[x]);
break ;
case DLREQ_FEP:
for ( x = 0; x < nimages; x++ ) {
if(image_list[x].type != IFEP)
continue;
if( (dlio.image.fi.type & FAMILY) ==
image_list[x].family ) {
if ( image_list[x].family == T_CX ) {
if ((dlio.image.fi.type & BUSTYPE)
== T_PCIBUS ) {
if ( image_list[x].subtype
== T_PCIBUS )
break;
}
else {
break;
}
}
else if ( image_list[x].family == T_EPC ) {
if ((dlio.image.fi.type & BUSTYPE)
== T_PCIBUS ) {
if ( image_list[x].subtype
== T_PCIBUS )
break;
}
else {
if ( image_list[x].subtype
!= T_PCIBUS )
break;
}
}
else
break;
}
else if ((dlio.image.fi.type & SUBTYPE) == image_list[x].subtype) {
if ( image_list[x].subtype == T_PCXR ) {
break;
}
}
}
if ( x >= nimages) {
if(nodldprint) {
fprintf(stderr,
"%s: cannot find correct FEP image\n",
pgm);
nodldprint = 0;
}
dlio.image.fi.type=-1;
if( ioctl(fd,DIGI_DLREQ_SET,&dlio) == -1 ) {
if(errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",
pgm);
errorprint=0;
}
sleep(2);
}
break;
}
squirt(dlio.req_type, dlio.bdid, &image_list[x]);
break;
case DLREQ_DEVCREATE:
{
char string[1024];
#if 0
sprintf(string, "%s /proc/dgap/%d/mknod", DEFSHELL, dlio.bdid);
#endif
sprintf(string, "%s /usr/sbin/dgap_updatedevs %d", DEFSHELL, dlio.bdid);
system(string);
if (debugflag)
printf("Created Devices.\n");
if (ioctl(fd, DIGI_DLREQ_SET, &dlio) == -1 ) {
if(errorprint) {
fprintf(stderr, "%s: warning - DEVCREATE ioctl failed\n",pgm);
errorprint = 0;
}
sleep(2);
}
if (debugflag)
printf("After ioctl set - Created Device.\n");
}
break;
case DLREQ_CONFIG:
for ( x = 0; x < nimages; x++ ) {
if(image_list[x].type != ICONFIG)
continue;
else
break;
}
if ( x >= nimages) {
if(nodldprint) {
fprintf(stderr,
"%s: cannot find correct CONFIG image\n",
pgm);
nodldprint = 0;
}
dlio.image.fi.type=-1;
if (ioctl(fd, DIGI_DLREQ_SET, &dlio) == -1 ) {
if(errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",
pgm);
errorprint=0;
}
sleep(2);
}
break;
}
squirt(dlio.req_type, dlio.bdid, &image_list[x]);
break;
case DLREQ_CONC:
if ( dp->dl_seq == 0 ) {
for ( x = 0; x < nimages; x++ ) {
ii=&image_list[x];
if(image_list[x].type != ICONC)
continue;
consider_file_rescan(ii) ;
ip = (struct downld_t *) image_list[x].image;
if (ip == NULL) continue;
if ((dp->dl_type != 'P' ) &&
(ip->dl_lrev <= dp->dl_lrev ) &&
( dp->dl_lrev <= ip->dl_hrev))
break;
}
if ( x >= nimages ) {
if(nodldprint) {
fprintf(stderr,
"%s: cannot find correct download image %d\n",
pgm, dp->dl_lrev);
nodldprint=0;
}
continue;
}
} else {
if ((ii = find_conc_image()) == NULL ) {
fprintf(stderr,
"%s: can't find rest of download image??\n",
pgm);
continue;
}
}
offset = 1024 * dp->dl_seq;
if ( offset < ii->len ) {
if (( bsize = ii->len - offset ) > 1024 )
bsize = 1024;
dp->dl_srev = ip->dl_srev;
dp->dl_lrev = ip->dl_lrev;
dp->dl_hrev = ip->dl_hrev;
dp->dl_seg = (64 * dp->dl_seq) + ip->dl_seg;
dp->dl_size = bsize;
down = (char *)&dp->dl_data[0];
image = (char *)((char *)ip + offset);
memcpy(down, image, bsize);
}
else {
dp->dl_seg = ip->dl_seg;
dp->dl_size = 0;
if (ii->pathname)
if (ii->image) {
free(ii->image);
ii->image = NULL;
}
}
if (debugflag)
printf(
"sending conc dl section %d to %s from %s\n",
dp->dl_seq, ii->name,
ii->pathname ? ii->pathname : "Internal Image");
if (ioctl(fd, DIGI_DLREQ_SET, &dlio) == -1 ) {
if (errorprint) {
fprintf(stderr,
"%s: warning - download ioctl failed\n",
pgm);
errorprint=0;
}
sleep(2);
}
break;
}
}
if (debugflag > 1) {
printf("pausing: "); fflush(stdout);
fflush(stdin);
while(getchar() != '\n');
printf("continuing\n");
}
}
}
void myperror(char *s)
{
fprintf(stderr,"%s: %s: %s.\n",pgm, s, strerror(errno));
}
