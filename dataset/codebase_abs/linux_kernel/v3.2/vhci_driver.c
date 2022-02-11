static struct V_1 * F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( L_1 , V_3 ) ;
if ( ! V_5 ) {
F_3 ( L_2 , V_3 ) ;
goto V_6;
}
F_4 ( V_5 , & V_2 -> V_7 ) ;
F_5 ( V_5 ) ;
struct V_8 * V_9 ;
F_6 (vhci_driver->cdev_list, cdev,
struct usbip_class_device) {
if ( ! strncmp ( V_9 -> V_10 , V_2 -> V_7 . V_11 ,
strlen ( V_2 -> V_7 . V_11 ) ) ) {
struct V_8 * V_12 ;
V_12 = calloc ( 1 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
goto V_6;
memcpy ( V_12 , V_9 , sizeof( * V_12 ) ) ;
F_7 ( V_2 -> V_13 , ( void * ) V_12 ) ;
}
}
return V_2 ;
V_6:
return NULL ;
}
static int F_8 ( char * V_14 )
{
int V_15 = 0 ;
char * V_16 ;
for ( int V_17 = 0 ; V_17 < V_18 -> V_19 ; V_17 ++ )
memset ( & V_18 -> V_2 [ V_17 ] , 0 , sizeof( V_18 -> V_2 [ V_17 ] ) ) ;
V_16 = strchr ( V_14 , '\n' ) + 1 ;
while ( * V_16 != '\0' ) {
int V_20 , V_21 , V_22 , V_23 ;
unsigned long V_24 ;
char V_25 [ V_26 ] ;
V_15 = sscanf ( V_16 , L_3 ,
& V_20 , & V_21 , & V_22 ,
& V_23 , & V_24 , V_25 ) ;
if ( V_15 < 5 ) {
F_3 ( L_4 , V_15 ) ;
F_9 () ;
}
F_3 ( L_5 ,
V_20 , V_21 , V_22 , V_23 ) ;
F_3 ( L_6 , V_24 , V_25 ) ;
{
struct V_1 * V_2 = & V_18 -> V_2 [ V_20 ] ;
V_2 -> V_20 = V_20 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_27 = ( V_23 >> 16 ) ;
V_2 -> V_28 = ( V_23 & 0x0000ffff ) ;
V_2 -> V_13 = F_10 ( sizeof( struct V_8 ) ) ;
if ( ! V_2 -> V_13 ) {
F_3 ( L_7 ) ;
return - 1 ;
}
if ( V_2 -> V_21 != V_29 && V_2 -> V_21 != V_30 ) {
V_2 = F_1 ( V_2 , V_25 ) ;
if ( ! V_2 ) {
F_3 ( L_8 ) ;
return - 1 ;
}
}
}
V_16 = strchr ( V_16 , '\n' ) + 1 ;
}
F_3 ( L_9 ) ;
return 0 ;
}
static int F_11 ( struct V_31 * V_9 )
{
char V_32 [ V_33 ] ;
char V_10 [ V_33 ] ;
int V_15 ;
struct V_8 * V_34 ;
snprintf ( V_32 , sizeof( V_32 ) , L_10 , V_9 -> V_11 ) ;
V_15 = F_12 ( V_32 , V_10 , sizeof( V_10 ) ) ;
if ( V_15 == 0 ) {
if ( ! strncmp ( V_10 , V_18 -> V_35 -> V_11 ,
strlen ( V_18 -> V_35 -> V_11 ) ) ) {
V_34 = calloc ( 1 , sizeof( * V_34 ) ) ;
if ( ! V_34 ) {
F_3 ( L_11 ) ;
return - 1 ;
}
F_7 ( V_18 -> V_13 , V_34 ) ;
strncpy ( V_34 -> V_32 , V_32 ,
sizeof( V_34 -> V_32 ) ) ;
strncpy ( V_34 -> V_10 , V_10 ,
sizeof( V_34 -> V_10 ) ) ;
F_3 ( L_12 , V_32 , V_10 ) ;
}
}
return 0 ;
}
static int F_13 ( char * V_36 )
{
struct V_37 * V_38 ;
struct V_39 * V_13 ;
struct V_31 * V_9 ;
int V_15 = 0 ;
V_38 = F_14 ( V_36 ) ;
if ( ! V_38 ) {
F_3 ( L_13 ) ;
return - 1 ;
}
F_3 ( L_14 , V_38 -> V_40 ) ;
V_13 = F_15 ( V_38 ) ;
if ( ! V_13 )
goto V_41;
F_6 (cdev_list, cdev, struct sysfs_class_device) {
F_3 ( L_15 , V_9 -> V_40 ) ;
V_15 = F_11 ( V_9 ) ;
if ( V_15 < 0 )
goto V_41;
}
V_41:
F_16 ( V_38 ) ;
return V_15 ;
}
static int F_17 ( void )
{
int V_15 ;
struct V_39 * V_42 ;
char * V_36 ;
char V_43 [ V_33 ] ;
char V_32 [ V_33 ] ;
V_15 = F_18 ( V_43 , V_33 ) ;
if ( V_15 < 0 ) {
F_3 ( L_16 ) ;
return - 1 ;
}
snprintf ( V_32 , sizeof( V_32 ) , L_17 , V_43 ,
V_44 ) ;
V_42 = F_19 ( V_32 ) ;
if ( ! V_42 ) {
F_3 ( L_18 ) ;
return - 1 ;
}
F_6 (cname_list, cname, char) {
V_15 = F_13 ( V_36 ) ;
if ( V_15 < 0 ) {
F_20 ( V_42 ) ;
return - 1 ;
}
}
F_20 ( V_42 ) ;
V_15 = F_13 ( V_45 ) ;
if ( V_15 < 0 )
return - 1 ;
return 0 ;
}
static int F_21 ( void )
{
struct V_46 * V_47 ;
V_47 = F_22 ( V_18 -> V_35 , L_19 ) ;
if ( ! V_47 ) {
F_3 ( L_20 ,
V_18 -> V_35 -> V_40 ) ;
return - 1 ;
}
F_3 ( L_21 ,
V_47 -> V_40 , V_47 -> V_11 , V_47 -> V_48 ,
V_47 -> V_49 , V_47 -> V_14 ) ;
return F_8 ( V_47 -> V_14 ) ;
}
static int F_23 ( void )
{
char * V_16 ;
int V_19 = 0 ;
struct V_46 * V_47 ;
V_47 = F_22 ( V_18 -> V_35 , L_19 ) ;
if ( ! V_47 ) {
F_3 ( L_20 ,
V_18 -> V_35 -> V_40 ) ;
return - 1 ;
}
F_3 ( L_21 ,
V_47 -> V_40 , V_47 -> V_11 , V_47 -> V_48 ,
V_47 -> V_49 , V_47 -> V_14 ) ;
V_16 = strchr ( V_47 -> V_14 , '\n' ) + 1 ;
while ( * V_16 != '\0' ) {
V_16 = strchr ( V_16 , '\n' ) + 1 ;
V_19 += 1 ;
}
return V_19 ;
}
static int F_24 ( char * V_43 , char * V_50 )
{
struct V_51 * V_52 ;
char V_53 [ V_33 ] ;
struct V_4 * V_54 ;
struct V_39 * V_55 ;
int V_56 = 0 ;
snprintf ( V_53 , V_33 , L_22 , V_43 ,
V_57 , V_58 , V_59 ,
V_60 ) ;
V_52 = F_25 ( V_53 ) ;
if ( ! V_52 ) {
F_3 ( L_23 , V_53 ) ;
F_3 ( L_24 V_61 L_25
V_60 L_26 ) ;
return - 1 ;
}
V_55 = F_26 ( V_52 ) ;
if ( ! V_55 ) {
F_3 ( L_27 ) ;
goto V_6;
}
F_6 (hc_devs, hc_dev, struct sysfs_device) {
strncpy ( V_50 , V_54 -> V_62 , V_26 ) ;
V_56 = 1 ;
}
V_6:
F_27 ( V_52 ) ;
if ( V_56 )
return 0 ;
F_3 ( L_28 , V_50 ) ;
return - 1 ;
}
int F_28 ( void )
{
int V_15 ;
char V_50 [ V_26 ] ;
V_18 = (struct V_63 * ) calloc ( 1 , sizeof( * V_18 ) ) ;
if ( ! V_18 ) {
F_3 ( L_11 ) ;
return - 1 ;
}
V_15 = F_18 ( V_18 -> V_43 , V_33 ) ;
if ( V_15 < 0 ) {
F_3 ( L_16 ) ;
goto V_6;
}
V_15 = F_24 ( V_18 -> V_43 , V_50 ) ;
if ( V_15 < 0 )
goto V_6;
V_18 -> V_35 = F_2 ( V_58 ,
V_50 ) ;
if ( ! V_18 -> V_35 ) {
F_3 ( L_29 ) ;
goto V_6;
}
V_18 -> V_19 = F_23 () ;
F_3 ( L_30 , V_18 -> V_19 ) ;
V_18 -> V_13 = F_10 ( sizeof( struct V_8 ) ) ;
if ( ! V_18 -> V_13 )
goto V_6;
if ( F_17 () )
goto V_6;
if ( F_21 () )
goto V_6;
return 0 ;
V_6:
if ( V_18 -> V_13 )
F_29 ( V_18 -> V_13 ) ;
if ( V_18 -> V_35 )
F_5 ( V_18 -> V_35 ) ;
if ( V_18 )
free ( V_18 ) ;
V_18 = NULL ;
return - 1 ;
}
void F_30 ()
{
if ( ! V_18 )
return;
if ( V_18 -> V_13 )
F_29 ( V_18 -> V_13 ) ;
for ( int V_17 = 0 ; V_17 < V_18 -> V_19 ; V_17 ++ ) {
if ( V_18 -> V_2 [ V_17 ] . V_13 )
F_29 ( V_18 -> V_2 [ V_17 ] . V_13 ) ;
}
if ( V_18 -> V_35 )
F_5 ( V_18 -> V_35 ) ;
free ( V_18 ) ;
V_18 = NULL ;
}
int F_31 ( void )
{
if ( V_18 -> V_13 )
F_29 ( V_18 -> V_13 ) ;
for ( int V_17 = 0 ; V_17 < V_18 -> V_19 ; V_17 ++ ) {
if ( V_18 -> V_2 [ V_17 ] . V_13 )
F_29 ( V_18 -> V_2 [ V_17 ] . V_13 ) ;
}
V_18 -> V_13 = F_10 ( sizeof( struct V_8 ) ) ;
if ( ! V_18 -> V_13 )
goto V_6;
if ( F_17 () )
goto V_6;
if ( F_21 () )
goto V_6;
return 0 ;
V_6:
if ( V_18 -> V_13 )
F_29 ( V_18 -> V_13 ) ;
for ( int V_17 = 0 ; V_17 < V_18 -> V_19 ; V_17 ++ ) {
if ( V_18 -> V_2 [ V_17 ] . V_13 )
F_29 ( V_18 -> V_2 [ V_17 ] . V_13 ) ;
}
F_3 ( L_31 ) ;
return - 1 ;
}
int F_32 ( void )
{
for ( int V_17 = 0 ; V_17 < V_18 -> V_19 ; V_17 ++ ) {
if ( V_18 -> V_2 [ V_17 ] . V_21 == V_29 )
return V_17 ;
}
return - 1 ;
}
int F_33 ( T_1 V_20 , int V_64 , T_2 V_23 ,
T_2 V_22 ) {
struct V_46 * V_65 ;
char V_66 [ 200 ] ;
int V_15 ;
V_65 = F_22 ( V_18 -> V_35 , L_32 ) ;
if ( ! V_65 ) {
F_3 ( L_33 ,
V_18 -> V_35 -> V_40 ) ;
return - 1 ;
}
snprintf ( V_66 , sizeof( V_66 ) , L_34 ,
V_20 , V_64 , V_23 , V_22 ) ;
F_3 ( L_35 , V_66 ) ;
V_15 = F_34 ( V_65 , V_66 , strlen ( V_66 ) ) ;
if ( V_15 < 0 ) {
F_3 ( L_36 ) ;
return - 1 ;
}
F_3 ( L_37 , V_20 ) ;
return 0 ;
}
static unsigned long F_35 ( T_1 V_27 , T_1 V_28 )
{
return ( V_27 << 16 ) | V_28 ;
}
int F_36 ( T_1 V_20 , int V_64 , T_1 V_27 ,
T_1 V_28 , T_2 V_22 )
{
int V_23 = F_35 ( V_27 , V_28 ) ;
return F_33 ( V_20 , V_64 , V_23 , V_22 ) ;
}
int F_37 ( T_1 V_20 )
{
struct V_46 * V_67 ;
char V_66 [ 200 ] ;
int V_15 ;
V_67 = F_22 ( V_18 -> V_35 , L_38 ) ;
if ( ! V_67 ) {
F_3 ( L_39 ,
V_18 -> V_35 -> V_40 ) ;
return - 1 ;
}
snprintf ( V_66 , sizeof( V_66 ) , L_40 , V_20 ) ;
F_3 ( L_35 , V_66 ) ;
V_15 = F_34 ( V_67 , V_66 , strlen ( V_66 ) ) ;
if ( V_15 < 0 ) {
F_3 ( L_36 ) ;
return - 1 ;
}
F_3 ( L_41 , V_20 ) ;
return 0 ;
}
