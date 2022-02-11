static void
F_1 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 T_5 V_1 )
{
V_2 -> V_3 = 0 ;
}
static void
F_2 ( T_6 * T_2 , T_3 * V_2 , char * V_4 )
{
if ( V_2 && ( V_2 -> V_3 != 0 ) )
printf ( V_4 , * T_2 , V_2 -> V_3 , V_2 -> V_5 ) ;
}
static void
F_3 ( T_4 T_2 , T_4 V_6 , T_4 T_7 V_1 )
{
F_4 ( T_2 ) ;
F_4 ( V_6 ) ;
}
static void
F_5 ( void * V_7 )
{
T_8 * V_8 = V_7 ;
T_9 V_9 ;
for( V_9 = 1 ; V_9 <= V_8 -> V_10 ; V_9 ++ )
{
V_8 -> V_11 [ V_9 ] . V_3 = 0 ;
}
F_6 ( V_8 -> V_12 , ( V_13 ) F_1 , NULL ) ;
}
static T_6
F_7 ( T_6 V_14 )
{
if ( V_14 <= 0x09 ) return V_14 ;
if ( V_14 >= 0x40 ) {
if ( V_14 <= 0x44 ) {
return V_14 - 54 ;
} else if ( V_14 == 0x60 || V_14 == 0x61 ) {
return V_14 - 81 ;
}
}
return 0 ;
}
static T_6
F_8 ( T_6 V_14 )
{
if ( V_14 <= 0x09 )
return V_14 ;
if ( V_14 <= 14 )
return V_14 + 54 ;
if ( V_14 <= 16 )
return V_14 + 81 ;
return 0 ;
}
static int
F_9 ( void * V_7 , T_10 * T_11 V_1 , T_12 * T_13 V_1 , const void * V_15 )
{
T_8 * V_8 = V_7 ;
const T_14 * V_6 = V_15 ;
T_6 V_16 = F_7 ( V_6 -> V_14 ) ;
int V_17 = 0 ;
if ( V_6 -> V_18 != 0 ) {
T_6 * T_2 = F_10 ( sizeof( T_6 ) ) ;
T_3 * V_19 ;
* T_2 = V_6 -> V_18 ;
V_19 = F_11 (
V_8 -> V_12 ,
T_2 ) ;
if ( ! V_19 ) {
V_19 = F_10 ( sizeof( T_3 ) ) ;
V_19 -> V_3 = 1 ;
V_19 -> V_5 = NULL ;
F_12 (
V_8 -> V_12 ,
T_2 ,
V_19 ) ;
} else {
V_19 -> V_3 ++ ;
}
V_17 = 1 ;
}
if ( V_16 != 0 ) {
V_8 -> V_11 [ V_16 ] . V_3 ++ ;
V_17 = 1 ;
}
return V_17 ;
}
static void
F_13 ( void * V_7 )
{
T_8 * V_8 = V_7 ;
T_9 V_9 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , L_5 , L_6 , L_5 , L_6 ) ;
for( V_9 = 1 ; V_9 <= ( ( V_8 -> V_10 + 1 ) / 2 ) ; V_9 ++ )
{
T_9 V_20 = V_9 + V_8 -> V_10 / 2 ;
printf ( L_7 , V_8 -> V_11 [ V_9 ] . type , V_8 -> V_11 [ V_9 ] . V_3 ) ;
printf ( L_8 ) ;
if ( V_20 < ( V_8 -> V_10 ) )
printf ( L_9 , V_8 -> V_11 [ V_20 ] . type , V_8 -> V_11 [ V_20 ] . V_3 ) ;
else
printf ( L_1 ) ;
}
printf ( L_10 ) ;
printf ( L_11 ) ;
F_6 ( V_8 -> V_12 , ( V_13 ) F_2 ,
L_12 ) ;
printf ( L_2 ) ;
}
static void
F_14 ( const char * V_21 , void * T_15 V_1 )
{
T_8 * V_8 ;
const char * V_22 = NULL ;
T_9 V_9 ;
T_16 * V_23 ;
T_3 * V_19 ;
const T_17 * V_24 ;
if ( ! strncmp ( V_21 , L_13 , 9 ) ) {
V_22 = V_21 + 9 ;
} else {
V_22 = NULL ;
}
V_8 = F_10 ( sizeof( T_8 ) ) ;
V_8 -> V_12 = F_15 ( V_25 , V_26 ) ;
V_24 = F_16 ( & V_27 ) ;
for ( V_9 = 0 ; V_24 [ V_9 ] . V_28 ; V_9 ++ )
{
T_6 * T_2 ;
V_19 = F_10 ( sizeof( T_3 ) ) ;
T_2 = F_10 ( sizeof( T_6 ) ) ;
V_19 -> V_3 = 0 ;
V_19 -> V_5 = V_24 [ V_9 ] . V_28 ;
* T_2 = V_24 [ V_9 ] . V_6 ;
F_12 (
V_8 -> V_12 ,
T_2 ,
V_19 ) ;
}
V_8 -> V_10 = 16 ;
V_8 -> V_11 = F_10 ( ( V_8 -> V_10 + 1 ) * sizeof( V_29 ) ) ;
if( V_22 ) {
V_8 -> V_22 = F_17 ( V_22 ) ;
} else {
V_8 -> V_22 = NULL ;
}
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ )
{
V_8 -> V_11 [ V_9 ] . V_3 = 0 ;
V_8 -> V_11 [ V_9 ] . type = F_18 ( F_8 ( V_9 ) , & V_30 ) ;
}
V_23 = F_19 (
L_14 ,
V_8 ,
V_22 ,
0 ,
F_5 ,
F_9 ,
F_13 ) ;
if ( V_23 ) {
F_4 ( V_8 -> V_11 ) ;
F_4 ( V_8 -> V_22 ) ;
F_4 ( V_8 ) ;
F_6 ( V_8 -> V_12 , ( V_13 ) F_3 , NULL ) ;
F_20 ( V_8 -> V_12 ) ;
fprintf ( V_31 , L_15 ,
V_23 -> V_32 ) ;
F_21 ( V_23 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_22 ( void )
{
F_23 ( L_13 , F_14 , NULL ) ;
}
