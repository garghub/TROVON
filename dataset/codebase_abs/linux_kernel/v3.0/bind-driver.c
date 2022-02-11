static void F_1 ( void )
{
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
#if 0
printf(" --allusbip make all devices exportable\n");
printf(" --export-to host export the device to 'host'\n");
printf(" --unexport host unexport a device previously exported to 'host'\n");
printf(" --busid busid the busid used for --export-to\n");
#endif
}
static int F_2 ( char * V_1 , int V_2 )
{
int V_3 ;
int V_4 ;
char V_5 [ V_6 + 4 ] ;
if ( F_3 ( V_1 , V_6 ) > V_6 - 1 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
V_3 = F_5 ( V_7 , V_8 ) ;
if ( V_3 < 0 )
return - 1 ;
if ( V_2 )
snprintf ( V_5 , V_6 + 4 , L_8 , V_1 ) ;
else
snprintf ( V_5 , V_6 + 4 , L_9 , V_1 ) ;
F_6 ( L_10 , V_5 , V_7 ) ;
V_4 = F_7 ( V_3 , V_5 , sizeof( V_5 ) ) ;
if ( V_4 < 0 ) {
F_8 ( V_3 ) ;
return - 1 ;
}
F_8 ( V_3 ) ;
return 0 ;
}
static int F_9 ( char * V_1 )
{
char V_9 [ V_10 ] ;
int V_3 ;
int V_4 ;
snprintf ( V_9 , sizeof( V_9 ) , V_11 , V_1 ) ;
V_3 = F_5 ( V_9 , V_8 ) ;
if ( V_3 < 0 ) {
F_4 ( L_11 , V_3 ) ;
return - 1 ;
}
V_4 = F_7 ( V_3 , V_1 , F_3 ( V_1 , V_6 ) ) ;
if ( V_4 < 0 ) {
F_4 ( L_12 , V_4 ) ;
F_8 ( V_3 ) ;
return - 1 ;
}
F_8 ( V_3 ) ;
return 0 ;
}
static int F_10 ( char * V_1 , int V_12 , int V_13 )
{
char V_14 [ V_6 ] ;
F_6 ( L_13 ) ;
snprintf ( V_14 , V_6 , L_14 , V_1 , V_12 , V_13 ) ;
return F_9 ( V_14 ) ;
}
static int F_11 ( char * V_1 , char * V_15 )
{
char V_16 [ V_10 ] ;
int V_3 ;
int V_4 ;
snprintf ( V_16 , sizeof( V_16 ) , V_17 , V_15 ) ;
V_3 = F_5 ( V_16 , V_8 ) ;
if ( V_3 < 0 )
return - 1 ;
V_4 = F_7 ( V_3 , V_1 , F_3 ( V_1 , V_6 ) ) ;
if ( V_4 < 0 ) {
F_8 ( V_3 ) ;
return - 1 ;
}
F_8 ( V_3 ) ;
return 0 ;
}
static int F_12 ( char * V_1 , int V_12 , int V_13 , char * V_15 )
{
char V_14 [ V_6 ] ;
snprintf ( V_14 , V_6 , L_14 , V_1 , V_12 , V_13 ) ;
return F_11 ( V_14 , V_15 ) ;
}
static int F_13 ( char * V_1 )
{
int V_12 = 0 ;
int V_18 = 0 ;
int V_19 = 0 ;
int V_20 ;
int V_21 = 0 ;
V_12 = F_14 ( V_1 ) ;
V_18 = F_15 ( V_1 ) ;
V_19 = F_16 ( V_1 ) ;
if ( V_12 < 0 || V_18 < 0 || V_19 < 0 ) {
F_4 ( L_15 ) ;
return - 1 ;
}
if ( V_19 == 0x09 ) {
F_17 ( L_16 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
char V_15 [ V_10 ] ;
int V_4 ;
F_18 ( & V_15 , sizeof( V_15 ) ) ;
F_19 ( V_1 , V_12 , V_20 , V_15 , V_10 - 1 ) ;
F_6 ( L_17 , V_1 , V_12 , V_20 , V_15 ) ;
if ( ! strncmp ( L_18 , V_15 , V_10 ) )
continue;
#if 0
if (!strncmp("usbip", driver, PATH_MAX))
continue;
#endif
V_4 = F_10 ( V_1 , V_12 , V_20 ) ;
if ( V_4 < 0 ) {
F_4 ( L_19 ,
V_1 , V_12 , V_20 ) ;
V_21 = 1 ;
}
}
if ( V_21 )
return - 1 ;
else
return 0 ;
}
static int F_20 ( char * V_1 )
{
int V_12 = 0 ;
int V_18 = 0 ;
int V_20 ;
int V_21 = 0 ;
V_12 = F_14 ( V_1 ) ;
V_18 = F_15 ( V_1 ) ;
if ( V_12 < 0 || V_18 < 0 ) {
F_4 ( L_15 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
int V_4 ;
V_4 = F_12 ( V_1 , V_12 , V_20 , L_20 ) ;
if ( V_4 < 0 ) {
F_4 ( L_21 ,
V_1 , V_12 , V_20 ) ;
V_21 = 1 ;
}
}
if ( V_21 )
return - 1 ;
else
return 0 ;
}
static int F_21 ( char * V_1 )
{
int V_4 ;
V_4 = F_13 ( V_1 ) ;
if ( V_4 < 0 ) {
F_4 ( L_22 , V_1 ) ;
return - 1 ;
}
V_4 = F_2 ( V_1 , 1 ) ;
if ( V_4 < 0 ) {
F_4 ( L_23 , V_1 ) ;
return - 1 ;
}
V_4 = F_20 ( V_1 ) ;
if ( V_4 < 0 ) {
F_4 ( L_24 , V_1 ) ;
F_2 ( V_1 , 0 ) ;
return - 1 ;
}
F_17 ( L_25 , V_1 ) ;
return 0 ;
}
static int F_22 ( char * V_1 )
{
int V_4 ;
int V_22 ;
V_22 = F_14 ( V_1 ) ;
if ( V_22 < 0 ) {
F_4 ( L_26 , V_1 ) ;
return - 1 ;
}
V_4 = F_2 ( V_1 , 0 ) ;
if ( V_4 < 0 ) {
F_4 ( L_27 , V_1 ) ;
return - 1 ;
}
V_4 = F_23 ( V_1 , V_22 ) ;
if ( V_4 < 0 ) {
F_4 ( L_26 , V_1 ) ;
return - 1 ;
}
F_17 ( L_28 , V_1 ) ;
return 0 ;
}
static int F_24 ( char * V_1 )
{
int V_4 ;
T_1 V_23 ;
T_2 V_24 [ 1 ] ;
V_4 = regcomp ( & V_23 , L_29 , V_25 | V_26 ) ;
if ( V_4 < 0 )
F_25 ( L_30 , strerror ( V_27 ) ) ;
V_4 = regexec ( & V_23 , V_1 , 0 , V_24 , 0 ) ;
if ( V_4 )
return 0 ;
return 1 ;
}
static int F_26 ( void )
{
T_3 * V_28 ;
V_28 = F_27 ( L_31 ) ;
if ( ! V_28 )
F_25 ( L_32 , strerror ( V_27 ) ) ;
printf ( L_33 ) ;
for (; ; ) {
struct V_29 * V_29 ;
char * V_1 ;
V_29 = F_28 ( V_28 ) ;
if ( ! V_29 )
break;
V_1 = V_29 -> V_30 ;
if ( F_24 ( V_1 ) ) {
char V_31 [ 100 ] = { '\0' } ;
char V_15 [ 100 ] = { '\0' } ;
int V_32 , V_33 = 0 ;
int V_20 ;
V_32 = F_14 ( V_1 ) ;
V_33 = F_15 ( V_1 ) ;
F_29 ( V_1 , V_31 , sizeof( V_31 ) ) ;
printf ( L_34 , V_1 , V_31 ) ;
for ( V_20 = 0 ; V_20 < V_33 ; V_20 ++ ) {
F_19 ( V_1 , V_32 , V_20 , V_15 , sizeof( V_15 ) ) ;
printf ( L_35 , V_1 , V_32 , V_20 , V_15 ) ;
}
printf ( L_36 ) ;
}
}
F_30 ( V_28 ) ;
return 0 ;
}
static int F_31 ( void )
{
T_3 * V_28 ;
V_28 = F_27 ( L_31 ) ;
if ( ! V_28 )
F_25 ( L_32 , strerror ( V_27 ) ) ;
for (; ; ) {
struct V_29 * V_29 ;
char * V_1 ;
V_29 = F_28 ( V_28 ) ;
if ( ! V_29 )
break;
V_1 = V_29 -> V_30 ;
if ( F_24 ( V_1 ) ) {
char V_31 [ 100 ] = { '\0' } ;
char V_15 [ 100 ] = { '\0' } ;
int V_32 , V_33 = 0 ;
int V_20 ;
V_32 = F_14 ( V_1 ) ;
V_33 = F_15 ( V_1 ) ;
F_29 ( V_1 , V_31 , sizeof( V_31 ) ) ;
printf ( L_37 , V_1 , V_31 ) ;
for ( V_20 = 0 ; V_20 < V_33 ; V_20 ++ ) {
F_19 ( V_1 , V_32 , V_20 , V_15 , sizeof( V_15 ) ) ;
printf ( L_38 , V_1 , V_32 , V_20 , V_15 ) ;
}
printf ( L_36 ) ;
}
}
F_30 ( V_28 ) ;
return 0 ;
}
int main ( int V_34 , char * * V_35 )
{
char * V_1 = NULL ;
char * T_4 V_36 ( ( V_37 ) ) = NULL ;
enum {
V_38 = 0 ,
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43 ,
V_44 ,
V_45 ,
V_46 ,
} V_47 = V_38 ;
if ( F_32 () != 0 )
F_4 ( L_39 ) ;
for (; ; ) {
int V_48 ;
int V_49 = 0 ;
V_48 = F_33 ( V_34 , V_35 , L_40 , V_50 , & V_49 ) ;
if ( V_48 == - 1 )
break;
switch ( V_48 ) {
case 'u' :
V_47 = V_39 ;
V_1 = V_51 ;
break;
case 'o' :
V_47 = V_40 ;
V_1 = V_51 ;
break;
case 'l' :
V_47 = V_41 ;
break;
case 'L' :
V_47 = V_42 ;
break;
case 'a' :
V_47 = V_43 ;
break;
case 'b' :
V_1 = V_51 ;
break;
case 'e' :
V_47 = V_44 ;
T_4 = V_51 ;
break;
case 'x' :
V_47 = V_45 ;
T_4 = V_51 ;
break;
case 'h' :
case '?' :
V_47 = V_46 ;
break;
default:
F_25 ( L_41 ) ;
}
}
switch ( V_47 ) {
case V_39 :
F_21 ( V_1 ) ;
break;
case V_40 :
F_22 ( V_1 ) ;
break;
case V_41 :
F_26 () ;
break;
case V_42 :
F_31 () ;
break;
#if 0
case cmd_allusbip:
allusbip();
break;
case cmd_export_to:
export_to(remote_host, busid);
break;
case cmd_unexport:
unexport_from(remote_host, busid);
break;
#endif
case V_46 :
case V_38 :
F_1 () ;
break;
default:
F_25 ( L_42 ) ;
}
return 0 ;
}
