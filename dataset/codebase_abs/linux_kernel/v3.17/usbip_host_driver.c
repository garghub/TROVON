static T_1 F_1 ( struct V_1 * V_2 )
{
char V_3 [ V_4 ] ;
int V_5 ;
int V_6 ;
char V_7 ;
int V_8 = 0 ;
snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_9 ) ;
V_5 = F_2 ( V_3 , V_10 ) ;
if ( V_5 < 0 ) {
F_3 ( L_2 , V_3 ) ;
return - 1 ;
}
V_6 = F_4 ( V_5 , & V_7 , 1 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 , V_3 ) ;
F_5 ( V_5 ) ;
return - 1 ;
}
V_8 = atoi ( & V_7 ) ;
return V_8 ;
}
static
struct V_11 * F_6 ( const char * V_12 )
{
struct V_11 * V_13 = NULL ;
struct V_11 * V_14 ;
T_2 V_15 ;
int V_16 ;
V_13 = calloc ( 1 , sizeof( struct V_11 ) ) ;
V_13 -> V_17 = F_7 ( V_18 , V_12 ) ;
if ( ! V_13 -> V_17 ) {
F_3 ( L_4 , V_12 ) ;
goto F_3;
}
F_8 ( V_13 -> V_17 , & V_13 -> V_2 ) ;
V_13 -> V_7 = F_1 ( & V_13 -> V_2 ) ;
if ( V_13 -> V_7 < 0 )
goto F_3;
V_15 = sizeof( struct V_11 ) +
V_13 -> V_2 . V_19 * sizeof( struct V_20 ) ;
V_14 = V_13 ;
V_13 = realloc ( V_13 , V_15 ) ;
if ( ! V_13 ) {
V_13 = V_14 ;
F_9 ( L_5 ) ;
goto F_3;
}
for ( V_16 = 0 ; V_16 < V_13 -> V_2 . V_19 ; V_16 ++ )
F_10 ( & V_13 -> V_2 , V_16 , & V_13 -> V_21 [ V_16 ] ) ;
return V_13 ;
F_3:
if ( V_13 -> V_17 )
F_11 ( V_13 -> V_17 ) ;
if ( V_13 )
free ( V_13 ) ;
return NULL ;
}
static int F_12 ( void )
{
struct V_11 * V_13 ;
struct V_22 * V_23 ;
struct V_24 * V_25 , * V_26 ;
struct V_27 * V_28 ;
const char * V_9 ;
const char * V_29 ;
V_23 = F_13 ( V_18 ) ;
F_14 ( V_23 , L_6 ) ;
F_15 ( V_23 ) ;
V_25 = F_16 ( V_23 ) ;
F_17 (dev_list_entry, devices) {
V_9 = F_18 ( V_26 ) ;
V_28 = F_7 ( V_18 , V_9 ) ;
if ( V_28 == NULL )
continue;
V_29 = F_19 ( V_28 ) ;
if ( V_29 != NULL && ! strcmp ( V_29 , V_30 ) ) {
V_13 = F_6 ( V_9 ) ;
if ( ! V_13 ) {
F_9 ( L_7 ) ;
continue;
}
F_20 ( & V_13 -> V_31 , & V_32 -> V_33 ) ;
V_32 -> V_34 ++ ;
}
}
return 0 ;
}
static void F_21 ( void )
{
struct V_35 * V_16 , * V_36 ;
struct V_11 * V_13 ;
F_22 (i, tmp, &host_driver->edev_list) {
V_13 = F_23 ( V_16 , struct V_11 , V_31 ) ;
F_24 ( V_16 ) ;
free ( V_13 ) ;
}
}
int F_25 ( void )
{
int V_37 ;
V_18 = F_26 () ;
if ( ! V_18 ) {
F_3 ( L_8 ) ;
return - 1 ;
}
V_32 = calloc ( 1 , sizeof( * V_32 ) ) ;
V_32 -> V_34 = 0 ;
F_27 ( & V_32 -> V_33 ) ;
V_37 = F_12 () ;
if ( V_37 < 0 )
goto V_38;
return 0 ;
V_38:
free ( V_32 ) ;
V_32 = NULL ;
F_28 ( V_18 ) ;
return - 1 ;
}
void F_29 ( void )
{
if ( ! V_32 )
return;
F_21 () ;
free ( V_32 ) ;
V_32 = NULL ;
F_28 ( V_18 ) ;
}
int F_30 ( void )
{
int V_37 ;
F_21 () ;
V_32 -> V_34 = 0 ;
F_27 ( & V_32 -> V_33 ) ;
V_37 = F_12 () ;
if ( V_37 < 0 )
return - 1 ;
return 0 ;
}
int F_31 ( struct V_11 * V_13 , int V_39 )
{
char V_40 [] = L_9 ;
char V_41 [ V_4 ] ;
char V_42 [ 30 ] ;
int V_43 ;
if ( V_13 -> V_7 != V_44 ) {
F_9 ( L_10 , V_13 -> V_2 . V_45 ) ;
switch ( V_13 -> V_7 ) {
case V_46 :
F_9 ( L_11 ) ;
break;
case V_47 :
F_9 ( L_12 ) ;
break;
default:
F_9 ( L_13 , V_13 -> V_7 ) ;
}
return - 1 ;
}
snprintf ( V_41 , sizeof( V_41 ) , L_14 ,
V_13 -> V_2 . V_9 , V_40 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_15 , V_39 ) ;
V_43 = F_32 ( V_41 , V_42 ,
strlen ( V_42 ) ) ;
if ( V_43 < 0 ) {
F_3 ( L_16 ,
V_42 , V_41 ) ;
return V_43 ;
}
F_33 ( L_17 , V_13 -> V_2 . V_45 ) ;
return V_43 ;
}
struct V_11 * F_34 ( int V_48 )
{
struct V_35 * V_16 ;
struct V_11 * V_13 ;
int V_49 = 0 ;
F_35 (i, &host_driver->edev_list) {
V_13 = F_23 ( V_16 , struct V_11 , V_31 ) ;
if ( V_48 == V_49 )
return V_13 ;
else
V_49 ++ ;
}
return NULL ;
}
