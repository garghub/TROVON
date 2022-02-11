static struct V_1 * F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( L_1 , V_3 ) ;
if ( ! V_5 ) {
F_3 ( L_2 , V_3 ) ;
goto F_3;
}
F_4 ( V_5 , & V_2 -> V_6 ) ;
F_5 ( V_5 ) ;
struct V_7 * V_8 ;
F_6 (vhci_driver->cdev_list, cdev, struct class_device) {
if ( ! strncmp ( V_8 -> V_9 , V_2 -> V_6 . V_10 , strlen ( V_2 -> V_6 . V_10 ) ) ) {
struct V_7 * V_11 ;
V_11 = calloc ( 1 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
goto F_3;
memcpy ( V_11 , V_8 , sizeof( * V_11 ) ) ;
F_7 ( V_2 -> V_12 , ( void * ) V_11 ) ;
}
}
return V_2 ;
F_3:
return NULL ;
}
static int F_8 ( char * V_13 )
{
int V_14 = 0 ;
char * V_15 ;
for ( int V_16 = 0 ; V_16 < V_17 -> V_18 ; V_16 ++ )
F_9 ( & V_17 -> V_2 [ V_16 ] , sizeof( struct V_1 ) ) ;
V_15 = strchr ( V_13 , '\n' ) + 1 ;
while ( * V_15 != '\0' ) {
int V_19 , V_20 , V_21 , V_22 ;
unsigned long V_23 ;
char V_24 [ V_25 ] ;
V_14 = sscanf ( V_15 , L_3 ,
& V_19 , & V_20 , & V_21 ,
& V_22 , & V_23 , V_24 ) ;
if ( V_14 < 5 ) {
F_3 ( L_4 , V_14 ) ;
F_10 () ;
}
F_11 ( L_5 ,
V_19 , V_20 , V_21 , V_22 ) ;
F_11 ( L_6 , V_23 , V_24 ) ;
{
struct V_1 * V_2 = & V_17 -> V_2 [ V_19 ] ;
V_2 -> V_19 = V_19 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_26 = ( V_22 >> 16 ) ;
V_2 -> V_27 = ( V_22 & 0x0000ffff ) ;
V_2 -> V_12 = F_12 ( sizeof( struct V_7 ) ) ;
if ( ! V_2 -> V_12 ) {
F_3 ( L_7 ) ;
return - 1 ;
}
if ( V_2 -> V_20 != V_28 && V_2 -> V_20 != V_29 ) {
V_2 = F_1 ( V_2 , V_24 ) ;
if ( ! V_2 ) {
F_3 ( L_7 ) ;
return - 1 ;
}
}
}
V_15 = strchr ( V_15 , '\n' ) + 1 ;
}
F_11 ( L_8 ) ;
return 0 ;
}
static int F_13 ( struct V_30 * V_8 )
{
char V_31 [ V_32 ] ;
char V_9 [ V_32 ] ;
int V_14 ;
snprintf ( V_31 , sizeof( V_31 ) , L_9 , V_8 -> V_10 ) ;
V_14 = F_14 ( V_31 , V_9 , V_32 ) ;
if ( ! V_14 ) {
if ( ! strncmp ( V_9 , V_17 -> V_33 -> V_10 ,
strlen ( V_17 -> V_33 -> V_10 ) ) ) {
struct V_7 * V_8 ;
V_8 = calloc ( 1 , sizeof( * V_8 ) ) ;
if ( ! V_8 ) {
F_3 ( L_10 ) ;
return - 1 ;
}
F_7 ( V_17 -> V_12 , ( void * ) V_8 ) ;
strncpy ( V_8 -> V_31 , V_31 , sizeof( V_8 -> V_31 ) ) ;
strncpy ( V_8 -> V_9 , V_9 , sizeof( V_8 -> V_31 ) ) ;
F_11 ( L_11 , V_31 , V_9 ) ;
}
}
return 0 ;
}
static int F_15 ( char * V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_12 ;
struct V_30 * V_8 ;
int V_14 = 0 ;
V_36 = F_16 ( V_34 ) ;
if ( ! V_36 ) {
F_3 ( L_12 ) ;
return - 1 ;
}
F_11 ( L_13 , V_36 -> V_38 ) ;
V_12 = F_17 ( V_36 ) ;
if ( ! V_12 )
goto V_39;
F_6 (cdev_list, cdev, struct sysfs_class_device) {
F_11 ( L_14 , V_8 -> V_38 ) ;
V_14 = F_13 ( V_8 ) ;
if ( V_14 < 0 )
goto V_39;
}
V_39:
F_18 ( V_36 ) ;
return V_14 ;
}
static int F_19 ( void )
{
int V_14 ;
struct V_37 * V_40 ;
char * V_34 ;
V_40 = F_20 ( L_15 ) ;
if ( ! V_40 ) {
F_3 ( L_16 ) ;
return - 1 ;
}
F_6 (cname_list, cname, char) {
V_14 = F_15 ( V_34 ) ;
if ( V_14 < 0 ) {
F_21 ( V_40 ) ;
return - 1 ;
}
}
F_21 ( V_40 ) ;
V_14 = F_15 ( V_41 ) ;
if ( V_14 < 0 )
return - 1 ;
return 0 ;
}
static int F_22 ( void )
{
struct V_42 * V_43 ;
V_43 = F_23 ( V_17 -> V_33 , L_17 ) ;
if ( ! V_43 ) {
F_3 ( L_18 , L_17 , V_17 -> V_33 -> V_38 ) ;
return - 1 ;
}
F_11 ( L_19 , V_43 -> V_38 ,
V_43 -> V_10 , V_43 -> V_44 , V_43 -> V_45 ) ;
F_11 ( L_20 , V_43 -> V_13 ) ;
return F_8 ( V_43 -> V_13 ) ;
}
static int F_24 ( void )
{
int V_18 = 0 ;
struct V_42 * V_43 ;
V_43 = F_23 ( V_17 -> V_33 , L_17 ) ;
if ( ! V_43 ) {
F_3 ( L_18 , L_17 , V_17 -> V_33 -> V_38 ) ;
return - 1 ;
}
F_11 ( L_19 , V_43 -> V_38 ,
V_43 -> V_10 , V_43 -> V_44 , V_43 -> V_45 ) ;
F_11 ( L_20 , V_43 -> V_13 ) ;
{
char * V_15 ;
V_15 = strchr ( V_43 -> V_13 , '\n' ) + 1 ;
while ( * V_15 != '\0' ) {
V_15 = strchr ( V_15 , '\n' ) + 1 ;
V_18 += 1 ;
}
}
return V_18 ;
}
static int F_25 ( char * V_46 , char * V_47 )
{
struct V_48 * V_49 ;
char V_50 [ V_32 ] ;
struct V_4 * V_51 ;
struct V_37 * V_52 ;
int V_53 = 0 ;
snprintf ( V_50 , V_32 , L_21 ,
V_46 , V_54 , V_55 ,
V_56 ) ;
V_49 = F_26 ( V_50 ) ;
if ( ! V_49 ) {
F_27 ( L_22 , V_50 ) ;
F_27 ( L_23 ) ;
return - 1 ;
}
V_52 = F_28 ( V_49 ) ;
if ( ! V_52 ) {
F_3 ( L_24 ) ;
goto F_3;
}
F_6 (hc_devs, hc_dev, struct sysfs_device) {
strncpy ( V_47 , V_51 -> V_57 , V_25 ) ;
V_53 = 1 ;
}
F_3:
F_29 ( V_49 ) ;
if ( V_53 )
return 0 ;
F_3 ( L_25 ) ;
return - 1 ;
}
int F_30 ( void )
{
int V_14 ;
char V_47 [ V_25 ] ;
V_17 = (struct V_58 * ) calloc ( 1 , sizeof( * V_17 ) ) ;
if ( ! V_17 ) {
F_3 ( L_26 ) ;
return - 1 ;
}
V_14 = F_31 ( V_17 -> V_46 , V_32 ) ;
if ( V_14 < 0 ) {
F_3 ( L_27 ) ;
goto F_3;
}
V_14 = F_25 ( V_17 -> V_46 , V_47 ) ;
if ( V_14 < 0 )
goto F_3;
V_17 -> V_33 = F_2 ( L_28 , V_47 ) ;
if ( ! V_17 -> V_33 ) {
F_3 ( L_29 ) ;
goto F_3;
}
V_17 -> V_18 = F_24 () ;
F_27 ( L_30 , V_17 -> V_18 ) ;
V_17 -> V_12 = F_12 ( sizeof( struct V_7 ) ) ;
if ( ! V_17 -> V_12 )
goto F_3;
if ( F_19 () )
goto F_3;
if ( F_22 () )
goto F_3;
return 0 ;
F_3:
if ( V_17 -> V_12 )
F_32 ( V_17 -> V_12 ) ;
if ( V_17 -> V_33 )
F_5 ( V_17 -> V_33 ) ;
if ( V_17 )
free ( V_17 ) ;
V_17 = NULL ;
return - 1 ;
}
void F_33 ()
{
if ( ! V_17 )
return;
if ( V_17 -> V_12 )
F_32 ( V_17 -> V_12 ) ;
for ( int V_16 = 0 ; V_16 < V_17 -> V_18 ; V_16 ++ ) {
if ( V_17 -> V_2 [ V_16 ] . V_12 )
F_32 ( V_17 -> V_2 [ V_16 ] . V_12 ) ;
}
if ( V_17 -> V_33 )
F_5 ( V_17 -> V_33 ) ;
free ( V_17 ) ;
V_17 = NULL ;
}
int F_34 ( void )
{
if ( V_17 -> V_12 )
F_32 ( V_17 -> V_12 ) ;
for ( int V_16 = 0 ; V_16 < V_17 -> V_18 ; V_16 ++ ) {
if ( V_17 -> V_2 [ V_16 ] . V_12 )
F_32 ( V_17 -> V_2 [ V_16 ] . V_12 ) ;
}
V_17 -> V_12 = F_12 ( sizeof( struct V_7 ) ) ;
if ( ! V_17 -> V_12 )
goto F_3;
if ( F_19 () )
goto F_3;
if ( F_22 () )
goto F_3;
return 0 ;
F_3:
if ( V_17 -> V_12 )
F_32 ( V_17 -> V_12 ) ;
for ( int V_16 = 0 ; V_16 < V_17 -> V_18 ; V_16 ++ ) {
if ( V_17 -> V_2 [ V_16 ] . V_12 )
F_32 ( V_17 -> V_2 [ V_16 ] . V_12 ) ;
}
F_3 ( L_31 ) ;
return - 1 ;
}
int F_35 ( void )
{
for ( int V_16 = 0 ; V_16 < V_17 -> V_18 ; V_16 ++ ) {
if ( V_17 -> V_2 [ V_16 ] . V_20 == V_28 )
return V_16 ;
}
return - 1 ;
}
int F_36 ( T_1 V_19 , int V_59 , T_2 V_22 ,
T_2 V_21 ) {
struct V_42 * V_60 ;
char V_61 [ 200 ] ;
int V_14 ;
V_60 = F_23 ( V_17 -> V_33 , L_32 ) ;
if ( ! V_60 ) {
F_3 ( L_33 ) ;
return - 1 ;
}
snprintf ( V_61 , sizeof( V_61 ) , L_34 ,
V_19 , V_59 , V_22 , V_21 ) ;
F_11 ( L_35 , V_61 ) ;
V_14 = F_37 ( V_60 , V_61 , strlen ( V_61 ) ) ;
if ( V_14 < 0 ) {
F_3 ( L_36 ) ;
return - 1 ;
}
F_27 ( L_37 , V_19 ) ;
return 0 ;
}
static unsigned long F_38 ( T_1 V_26 , T_1 V_27 )
{
return ( V_26 << 16 ) | V_27 ;
}
int F_39 ( T_1 V_19 , int V_59 , T_1 V_26 ,
T_1 V_27 , T_2 V_21 )
{
int V_22 = F_38 ( V_26 , V_27 ) ;
return F_36 ( V_19 , V_59 , V_22 , V_21 ) ;
}
int F_40 ( T_1 V_19 )
{
struct V_42 * V_62 ;
char V_61 [ 200 ] ;
int V_14 ;
V_62 = F_23 ( V_17 -> V_33 , L_38 ) ;
if ( ! V_62 ) {
F_3 ( L_39 ) ;
return - 1 ;
}
snprintf ( V_61 , sizeof( V_61 ) , L_40 , V_19 ) ;
F_11 ( L_41 ) ;
F_11 ( L_35 , V_61 ) ;
V_14 = F_37 ( V_62 , V_61 , strlen ( V_61 ) ) ;
if ( V_14 < 0 ) {
F_3 ( L_42 ) ;
return - 1 ;
}
F_27 ( L_43 , V_19 ) ;
return 0 ;
}
