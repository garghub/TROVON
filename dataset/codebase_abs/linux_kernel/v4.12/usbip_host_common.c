static T_1 F_1 ( struct V_1 * V_2 )
{
char V_3 [ V_4 ] ;
int V_5 ;
int V_6 ;
int V_7 ;
char V_8 ;
int V_9 = 0 ;
V_5 = snprintf ( V_3 , sizeof( V_3 ) ,
L_1 , V_2 -> V_10 ) ;
if ( V_5 < 0 || ( unsigned int ) V_5 >= sizeof( V_3 ) ) {
F_2 ( L_2 , V_5 ,
( long unsigned ) sizeof( V_3 ) ) ;
return - 1 ;
}
V_6 = F_3 ( V_3 , V_11 ) ;
if ( V_6 < 0 ) {
F_2 ( L_3 , V_3 ) ;
return - 1 ;
}
V_7 = F_4 ( V_6 , & V_8 , 1 ) ;
if ( V_7 < 0 ) {
F_2 ( L_4 , V_3 ) ;
F_5 ( V_6 ) ;
return - 1 ;
}
V_9 = atoi ( & V_8 ) ;
return V_9 ;
}
static
struct V_12 * F_6 (
struct V_13 * V_14 , const char * V_15 )
{
struct V_12 * V_16 = NULL ;
struct V_12 * V_17 ;
T_2 V_5 ;
int V_18 ;
V_16 = calloc ( 1 , sizeof( struct V_12 ) ) ;
V_16 -> V_19 =
F_7 ( V_20 , V_15 ) ;
if ( ! V_16 -> V_19 ) {
F_2 ( L_5 , V_15 ) ;
goto F_2;
}
if ( V_14 -> V_21 . V_22 ( V_16 -> V_19 , & V_16 -> V_2 ) < 0 )
goto F_2;
V_16 -> V_8 = F_1 ( & V_16 -> V_2 ) ;
if ( V_16 -> V_8 < 0 )
goto F_2;
V_5 = sizeof( struct V_12 ) +
V_16 -> V_2 . V_23 * sizeof( struct V_24 ) ;
V_17 = V_16 ;
V_16 = realloc ( V_16 , V_5 ) ;
if ( ! V_16 ) {
V_16 = V_17 ;
F_8 ( L_6 ) ;
goto F_2;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_2 . V_23 ; V_18 ++ ) {
if ( ! V_14 -> V_21 . V_25 )
break;
V_14 -> V_21 . V_25 ( & V_16 -> V_2 , V_18 , & V_16 -> V_26 [ V_18 ] ) ;
}
return V_16 ;
F_2:
if ( V_16 -> V_19 )
F_9 ( V_16 -> V_19 ) ;
if ( V_16 )
free ( V_16 ) ;
return NULL ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_12 * V_16 ;
struct V_27 * V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
const char * V_10 ;
V_28 = F_11 ( V_20 ) ;
F_12 ( V_28 , V_14 -> V_34 ) ;
F_13 ( V_28 ) ;
V_30 = F_14 ( V_28 ) ;
F_15 (dev_list_entry, devices) {
V_10 = F_16 ( V_31 ) ;
V_33 = F_7 ( V_20 ,
V_10 ) ;
if ( V_33 == NULL )
continue;
if ( V_14 -> V_21 . V_35 ( V_33 ) ) {
V_16 = F_6 ( V_14 , V_10 ) ;
if ( ! V_16 ) {
F_8 ( L_7 ) ;
continue;
}
F_17 ( & V_16 -> V_36 , & V_14 -> V_37 ) ;
V_14 -> V_38 ++ ;
}
}
return 0 ;
}
static void F_18 ( struct V_39 * V_40 )
{
struct V_39 * V_18 , * V_41 ;
struct V_12 * V_16 ;
F_19 (i, tmp, devs) {
V_16 = F_20 ( V_18 , struct V_12 , V_36 ) ;
F_21 ( V_18 ) ;
free ( V_16 ) ;
}
}
int F_22 ( struct V_13 * V_14 )
{
int V_42 ;
V_20 = F_23 () ;
if ( ! V_20 ) {
F_2 ( L_8 ) ;
return - 1 ;
}
V_42 = F_10 ( V_14 ) ;
if ( V_42 < 0 )
goto F_2;
return 0 ;
F_2:
F_24 ( V_20 ) ;
return - 1 ;
}
void F_25 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_18 ( & V_14 -> V_37 ) ;
F_24 ( V_20 ) ;
}
int F_26 ( struct V_13 * V_14 )
{
int V_42 ;
F_18 ( & V_14 -> V_37 ) ;
V_14 -> V_38 = 0 ;
F_27 ( & V_14 -> V_37 ) ;
V_42 = F_10 ( V_14 ) ;
if ( V_42 < 0 )
return - 1 ;
return 0 ;
}
int F_28 ( struct V_12 * V_16 , int V_43 )
{
char V_44 [] = L_9 ;
char V_45 [ V_4 ] ;
int V_5 ;
char V_46 [ 30 ] ;
int V_47 ;
if ( V_16 -> V_8 != V_48 ) {
F_8 ( L_10 , V_16 -> V_2 . V_49 ) ;
switch ( V_16 -> V_8 ) {
case V_50 :
F_8 ( L_11 ) ;
break;
case V_51 :
F_8 ( L_12 ) ;
break;
default:
F_8 ( L_13 , V_16 -> V_8 ) ;
}
return - 1 ;
}
V_5 = snprintf ( V_45 , sizeof( V_45 ) , L_14 ,
V_16 -> V_2 . V_10 , V_44 ) ;
if ( V_5 < 0 || ( unsigned int ) V_5 >= sizeof( V_45 ) ) {
F_2 ( L_15 , V_5 ,
( long unsigned ) sizeof( V_45 ) ) ;
return - 1 ;
}
V_5 = snprintf ( V_46 , sizeof( V_46 ) , L_16 , V_43 ) ;
if ( V_5 < 0 || ( unsigned int ) V_5 >= sizeof( V_46 ) ) {
F_2 ( L_17 , V_5 ,
( long unsigned ) sizeof( V_46 ) ) ;
return - 1 ;
}
V_47 = F_29 ( V_45 , V_46 ,
strlen ( V_46 ) ) ;
if ( V_47 < 0 ) {
F_2 ( L_18 ,
V_46 , V_45 ) ;
return V_47 ;
}
F_30 ( L_19 , V_16 -> V_2 . V_49 ) ;
return V_47 ;
}
struct V_12 * F_31 (
struct V_13 * V_14 , int V_52 )
{
struct V_39 * V_18 ;
struct V_12 * V_16 ;
int V_53 = 0 ;
F_32 (i, &hdriver->edev_list) {
V_16 = F_20 ( V_18 , struct V_12 , V_36 ) ;
if ( V_52 == V_53 )
return V_16 ;
V_53 ++ ;
}
return NULL ;
}
