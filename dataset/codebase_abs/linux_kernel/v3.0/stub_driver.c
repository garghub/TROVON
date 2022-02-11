static struct V_1 * F_1 ( void )
{
int V_2 ;
char V_3 [ V_4 ] ;
char V_5 [ V_4 ] ;
struct V_1 * V_6 ;
V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 < 0 ) {
F_3 ( L_1 ) ;
return NULL ;
}
snprintf ( V_5 , V_4 , L_2 ,
V_3 , V_7 , V_8 ,
V_9 ) ;
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 ) {
F_3 ( L_3 ) ;
return NULL ;
}
return V_6 ;
}
static T_1 F_5 ( struct V_10 * V_11 )
{
char V_12 [ V_4 ] ;
struct V_13 * V_14 ;
int V_15 = 0 ;
int V_2 ;
struct V_16 V_17 ;
int V_18 = V_19 ;
snprintf ( V_12 , V_4 , L_4 ,
V_11 -> V_20 , V_11 -> V_21 ,
V_11 -> V_22 ,
0 ) ;
while ( V_18 > 0 ) {
if ( V_16 ( V_12 , & V_17 ) == 0 )
break;
if ( V_23 != V_24 ) {
F_3 ( L_5 , V_12 ) ;
return - 1 ;
}
F_6 ( 10000 ) ;
V_18 -- ;
}
if ( V_18 == 0 )
F_3 ( L_6 ,
V_19 ) ;
else if ( V_18 < V_19 )
F_7 ( L_7 ,
V_19 - V_18 ) ;
V_14 = F_8 ( V_12 ) ;
if ( ! V_14 ) {
F_3 ( L_8 , V_12 ) ;
return - 1 ;
}
V_2 = F_9 ( V_14 ) ;
if ( V_2 ) {
F_3 ( L_9 , V_12 ) ;
F_10 ( V_14 ) ;
return - 1 ;
}
V_15 = atoi ( V_14 -> V_15 ) ;
F_10 ( V_14 ) ;
return V_15 ;
}
static void F_11 ( void * V_25 )
{
struct V_26 * V_27 =
(struct V_26 * ) V_25 ;
F_12 ( V_27 -> V_28 ) ;
free ( V_25 ) ;
}
static struct V_26 * F_13 ( char * V_29 )
{
struct V_26 * V_27 = NULL ;
V_27 = (struct V_26 * ) calloc ( 1 , sizeof( * V_27 ) ) ;
if ( ! V_27 ) {
F_3 ( L_10 ) ;
return NULL ;
}
V_27 -> V_28 = F_14 ( V_29 ) ;
if ( ! V_27 -> V_28 ) {
F_3 ( L_8 , V_29 ) ;
goto F_3;
}
F_15 ( V_27 -> V_28 , & V_27 -> V_11 ) ;
V_27 -> V_30 = F_5 ( & V_27 -> V_11 ) ;
if ( V_27 -> V_30 < 0 )
goto F_3;
T_2 V_31 = sizeof( * V_27 ) + V_27 -> V_11 . V_32 * sizeof( struct V_33 ) ;
V_27 = (struct V_26 * ) realloc ( V_27 , V_31 ) ;
if ( ! V_27 ) {
F_3 ( L_10 ) ;
goto F_3;
}
for ( int V_34 = 0 ; V_34 < V_27 -> V_11 . V_32 ; V_34 ++ )
F_16 ( & V_27 -> V_11 , V_34 , & V_27 -> V_35 [ V_34 ] ) ;
return V_27 ;
F_3:
if ( V_27 && V_27 -> V_28 )
F_12 ( V_27 -> V_28 ) ;
if ( V_27 )
free ( V_27 ) ;
return NULL ;
}
static int F_17 ( struct V_36 * V_36 , struct V_37 * V_38 )
{
struct V_37 * V_25 ;
F_18 (dlist, dev, struct sysfs_device) {
if ( ! strncmp ( V_25 -> V_39 , V_38 -> V_39 , V_40 ) )
return 0 ;
}
return 1 ;
}
static int F_19 ( void )
{
struct V_37 * V_41 ;
struct V_36 * V_42 ;
struct V_37 * V_28 ;
struct V_36 * V_43 ;
V_43 = F_20 ( sizeof( struct V_37 ) , V_44 ) ;
V_42 = F_21 ( V_6 -> V_1 ) ;
if ( ! V_42 ) {
printf ( L_11 ) ;
goto V_45;
}
F_18 (suinf_list, suinf, struct sysfs_device) {
V_28 = F_22 ( V_41 ) ;
if ( ! V_28 ) {
F_3 ( L_12 , V_41 -> V_46 ) ;
continue;
}
if ( F_17 ( V_43 , V_28 ) ) {
F_23 ( V_43 , V_28 ) ;
}
}
F_18 (sudev_list, sudev, struct sysfs_device) {
struct V_26 * V_27 ;
V_27 = F_13 ( V_28 -> V_20 ) ;
if ( ! V_27 ) {
F_3 ( L_13 ) ;
continue;
}
F_23 ( V_6 -> V_47 , ( void * ) V_27 ) ;
V_6 -> V_48 ++ ;
}
F_24 ( V_43 ) ;
V_45:
return 0 ;
}
int F_25 ( void )
{
int V_2 ;
if ( V_6 -> V_47 )
F_24 ( V_6 -> V_47 ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_47 = F_20 ( sizeof( struct V_26 ) ,
F_11 ) ;
if ( ! V_6 -> V_47 ) {
F_3 ( L_14 ) ;
return - 1 ;
}
V_2 = F_19 () ;
if ( V_2 < 0 )
return V_2 ;
return 0 ;
}
int F_26 ( void )
{
int V_2 ;
V_6 = (struct V_49 * ) calloc ( 1 , sizeof( * V_6 ) ) ;
if ( ! V_6 ) {
F_3 ( L_15 ) ;
return - 1 ;
}
V_6 -> V_48 = 0 ;
V_6 -> V_47 = F_20 ( sizeof( struct V_26 ) ,
F_11 ) ;
if ( ! V_6 -> V_47 ) {
F_3 ( L_14 ) ;
goto F_3;
}
V_6 -> V_1 = F_1 () ;
if ( ! V_6 -> V_1 )
goto F_3;
V_2 = F_19 () ;
if ( V_2 < 0 )
goto F_3;
return 0 ;
F_3:
if ( V_6 -> V_1 )
F_27 ( V_6 -> V_1 ) ;
if ( V_6 -> V_47 )
F_24 ( V_6 -> V_47 ) ;
free ( V_6 ) ;
V_6 = NULL ;
return - 1 ;
}
void F_28 ( void )
{
if ( ! V_6 )
return;
if ( V_6 -> V_47 )
F_24 ( V_6 -> V_47 ) ;
if ( V_6 -> V_1 )
F_27 ( V_6 -> V_1 ) ;
free ( V_6 ) ;
V_6 = NULL ;
}
int F_29 ( struct V_26 * V_27 , int V_50 )
{
char V_12 [ V_4 ] ;
struct V_13 * V_14 ;
char V_51 [ 30 ] ;
int V_2 ;
if ( V_27 -> V_30 != V_52 ) {
F_7 ( L_16 , V_27 -> V_11 . V_21 ) ;
switch( V_27 -> V_30 ) {
case V_53 :
F_7 ( L_17 ) ;
break;
case V_54 :
F_7 ( L_18 ) ;
break;
default:
F_7 ( L_19 , V_27 -> V_30 ) ;
}
return - 1 ;
}
snprintf ( V_12 , sizeof( V_12 ) , L_20 ,
V_27 -> V_11 . V_20 ,
V_27 -> V_11 . V_21 ,
V_27 -> V_11 . V_22 , 0 ,
L_21 ) ;
V_14 = F_8 ( V_12 ) ;
if ( ! V_14 ) {
F_3 ( L_8 , V_12 ) ;
return - 1 ;
}
snprintf ( V_51 , sizeof( V_51 ) , L_22 , V_50 ) ;
F_30 ( L_23 , V_51 ) ;
V_2 = F_31 ( V_14 , V_51 , strlen ( V_51 ) ) ;
if ( V_2 < 0 ) {
F_3 ( L_24 , V_51 , V_12 ) ;
goto V_55;
}
F_7 ( L_25 , V_27 -> V_11 . V_21 ) ;
V_55:
F_10 ( V_14 ) ;
return V_2 ;
}
struct V_26 * F_32 ( int V_56 )
{
struct V_26 * V_27 ;
struct V_36 * V_36 = V_6 -> V_47 ;
int V_57 = 0 ;
F_18 (dlist, edev, struct usbip_exported_device) {
if ( V_56 == V_57 )
return V_27 ;
else
V_57 ++ ;
}
return NULL ;
}
