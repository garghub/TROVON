static T_1 F_1 ( struct V_1 * V_2 )
{
char V_3 [ V_4 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
int V_8 ;
struct V_9 V_10 ;
int V_11 = V_12 ;
snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_13 , V_2 -> V_14 , V_2 -> V_15 , 0 ) ;
while ( V_11 > 0 ) {
if ( V_9 ( V_3 , & V_10 ) == 0 )
break;
if ( V_16 != V_17 ) {
F_2 ( L_2 , V_3 ) ;
return - 1 ;
}
F_3 ( 10000 ) ;
V_11 -- ;
}
if ( V_11 == 0 )
F_2 ( L_3 ,
V_12 ) ;
else if ( V_11 < V_12 )
F_2 ( L_4 ,
V_12 - V_11 ) ;
V_6 = F_4 ( V_3 ) ;
if ( ! V_6 ) {
F_2 ( L_5 , V_3 ) ;
return - 1 ;
}
V_8 = F_5 ( V_6 ) ;
if ( V_8 ) {
F_2 ( L_6 , V_3 ) ;
F_6 ( V_6 ) ;
return - 1 ;
}
V_7 = atoi ( V_6 -> V_7 ) ;
F_6 ( V_6 ) ;
return V_7 ;
}
static struct V_18 * F_7 ( char * V_19 )
{
struct V_18 * V_20 = NULL ;
T_2 V_21 ;
int V_22 ;
V_20 = calloc ( 1 , sizeof( * V_20 ) ) ;
if ( ! V_20 ) {
F_2 ( L_7 ) ;
return NULL ;
}
V_20 -> V_23 = F_8 ( V_19 ) ;
if ( ! V_20 -> V_23 ) {
F_2 ( L_8 , V_19 ) ;
goto V_24;
}
F_9 ( V_20 -> V_23 , & V_20 -> V_2 ) ;
V_20 -> V_25 = F_1 ( & V_20 -> V_2 ) ;
if ( V_20 -> V_25 < 0 )
goto V_24;
V_21 = sizeof( * V_20 ) + V_20 -> V_2 . V_26 *
sizeof( struct V_27 ) ;
V_20 = realloc ( V_20 , V_21 ) ;
if ( ! V_20 ) {
F_2 ( L_9 ) ;
goto V_24;
}
for ( V_22 = 0 ; V_22 < V_20 -> V_2 . V_26 ; V_22 ++ )
F_10 ( & V_20 -> V_2 , V_22 , & V_20 -> V_28 [ V_22 ] ) ;
return V_20 ;
V_24:
if ( V_20 && V_20 -> V_23 )
F_11 ( V_20 -> V_23 ) ;
if ( V_20 )
free ( V_20 ) ;
return NULL ;
}
static int F_12 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_30 * V_32 ;
F_13 (dlist, dev, struct sysfs_device) {
if ( ! strncmp ( V_32 -> V_33 , V_31 -> V_33 , V_34 ) )
return 0 ;
}
return 1 ;
}
static void F_14 ( void * V_35 )
{
( void ) V_35 ;
}
static int F_15 ( void )
{
struct V_30 * V_36 ;
struct V_29 * V_37 ;
struct V_30 * V_23 ;
struct V_29 * V_38 ;
struct V_18 * V_20 ;
V_38 = F_16 ( sizeof( struct V_30 ) ,
F_14 ) ;
V_37 = F_17 ( V_39 -> V_40 ) ;
if ( ! V_37 ) {
F_2 ( L_10 V_41 L_11
L_12 ) ;
return 0 ;
}
F_13 (suintf_list, suintf, struct sysfs_device) {
V_23 = F_18 ( V_36 ) ;
if ( ! V_23 ) {
F_2 ( L_13 , V_36 -> V_42 ) ;
continue;
}
if ( F_12 ( V_38 , V_23 ) ) {
F_19 ( V_38 , V_23 ) ;
}
}
F_13 (sudev_list, sudev, struct sysfs_device) {
V_20 = F_7 ( V_23 -> V_13 ) ;
if ( ! V_20 ) {
F_2 ( L_14 ) ;
continue;
}
F_19 ( V_39 -> V_43 , V_20 ) ;
V_39 -> V_44 ++ ;
}
F_20 ( V_38 ) ;
return 0 ;
}
static struct V_40 * F_21 ( void )
{
char V_45 [] = L_15 ;
char V_46 [ V_4 ] ;
char V_47 [ V_4 ] ;
struct V_40 * V_48 ;
int V_8 ;
V_8 = F_22 ( V_46 , V_4 ) ;
if ( V_8 < 0 ) {
F_2 ( L_16 ) ;
return NULL ;
}
snprintf ( V_47 , V_4 , L_17 ,
V_46 , V_49 , V_45 , V_50 ,
V_41 ) ;
V_48 = F_23 ( V_47 ) ;
if ( ! V_48 ) {
F_2 ( L_18 ) ;
return NULL ;
}
return V_48 ;
}
static void F_24 ( void * V_32 )
{
struct V_18 * V_20 = V_32 ;
F_11 ( V_20 -> V_23 ) ;
free ( V_32 ) ;
}
int F_25 ( void )
{
int V_8 ;
V_39 = calloc ( 1 , sizeof( * V_39 ) ) ;
if ( ! V_39 ) {
F_2 ( L_7 ) ;
return - 1 ;
}
V_39 -> V_44 = 0 ;
V_39 -> V_43 =
F_16 ( sizeof( struct V_18 ) ,
F_24 ) ;
if ( ! V_39 -> V_43 ) {
F_2 ( L_19 ) ;
goto V_51;
}
V_39 -> V_40 = F_21 () ;
if ( ! V_39 -> V_40 )
goto V_52;
V_8 = F_15 () ;
if ( V_8 < 0 )
goto V_53;
return 0 ;
V_53:
F_26 ( V_39 -> V_40 ) ;
V_52:
F_20 ( V_39 -> V_43 ) ;
V_51:
free ( V_39 ) ;
V_39 = NULL ;
return - 1 ;
}
void F_27 ( void )
{
if ( ! V_39 )
return;
if ( V_39 -> V_43 )
F_20 ( V_39 -> V_43 ) ;
if ( V_39 -> V_40 )
F_26 ( V_39 -> V_40 ) ;
free ( V_39 ) ;
V_39 = NULL ;
}
int F_28 ( void )
{
int V_8 ;
if ( V_39 -> V_43 )
F_20 ( V_39 -> V_43 ) ;
V_39 -> V_44 = 0 ;
V_39 -> V_43 =
F_16 ( sizeof( struct V_18 ) ,
F_24 ) ;
if ( ! V_39 -> V_43 ) {
F_2 ( L_19 ) ;
return - 1 ;
}
V_8 = F_15 () ;
if ( V_8 < 0 )
return - 1 ;
return 0 ;
}
int F_29 ( struct V_18 * V_20 , int V_54 )
{
char V_55 [] = L_20 ;
char V_56 [ V_4 ] ;
struct V_5 * V_6 ;
char V_57 [ 30 ] ;
int V_58 ;
if ( V_20 -> V_25 != V_59 ) {
F_2 ( L_21 , V_20 -> V_2 . V_14 ) ;
switch ( V_20 -> V_25 ) {
case V_60 :
F_2 ( L_22 ) ;
break;
case V_61 :
F_2 ( L_23 ) ;
break;
default:
F_2 ( L_24 , V_20 -> V_25 ) ;
}
return - 1 ;
}
snprintf ( V_56 , sizeof( V_56 ) , L_25 ,
V_20 -> V_2 . V_13 , V_20 -> V_2 . V_14 ,
V_20 -> V_2 . V_15 , 0 , V_55 ) ;
V_6 = F_4 ( V_56 ) ;
if ( ! V_6 ) {
F_2 ( L_5 , V_56 ) ;
return - 1 ;
}
snprintf ( V_57 , sizeof( V_57 ) , L_26 , V_54 ) ;
F_2 ( L_27 , V_57 ) ;
V_58 = F_30 ( V_6 , V_57 , strlen ( V_57 ) ) ;
if ( V_58 < 0 ) {
F_2 ( L_28 ,
V_57 , V_56 ) ;
goto V_62;
}
F_2 ( L_29 , V_20 -> V_2 . V_14 ) ;
V_62:
F_6 ( V_6 ) ;
return V_58 ;
}
struct V_18 * F_31 ( int V_63 )
{
struct V_18 * V_20 ;
struct V_29 * V_29 = V_39 -> V_43 ;
int V_64 = 0 ;
F_13 (dlist, edev, struct usbip_exported_device) {
if ( V_63 == V_64 )
return V_20 ;
else
V_64 ++ ;
}
return NULL ;
}
