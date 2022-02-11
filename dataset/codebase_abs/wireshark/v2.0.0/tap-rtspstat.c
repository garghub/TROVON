static void
F_1 ( T_1 * V_1 )
{
int V_2 ;
V_1 -> V_3 = F_2 ( V_4 , V_5 ) ;
for ( V_2 = 0 ; V_6 [ V_2 ] . V_7 ; V_2 ++ )
{
T_2 * V_8 = F_3 ( T_2 , 1 ) ;
T_3 * V_9 = F_3 ( T_3 , 1 ) ;
* V_8 = V_6 [ V_2 ] . V_10 ;
V_9 -> V_11 = 0 ;
V_9 -> V_12 = * V_8 ;
V_9 -> V_13 = V_6 [ V_2 ] . V_7 ;
V_9 -> V_1 = V_1 ;
F_4 ( V_9 -> V_1 -> V_3 , V_8 , V_9 ) ;
}
V_1 -> V_14 = F_2 ( V_15 , V_16 ) ;
}
static void
F_5 ( T_4 * V_8 V_17 , T_5 * V_18 , T_4 * V_19 )
{
if ( V_18 -> V_11 == 0 )
return;
printf ( V_19 , V_18 -> V_20 , V_18 -> V_11 ) ;
}
static void
F_6 ( T_2 * V_8 V_17 , T_3 * V_18 , char * V_19 )
{
if ( V_18 == NULL ) {
F_7 ( L_1 , * V_8 ) ;
exit ( V_21 ) ;
}
if ( V_18 -> V_11 == 0 )
return;
printf ( V_19 , V_18 -> V_12 , V_18 -> V_13 , V_18 -> V_11 ) ;
}
static void
F_8 ( T_4 * V_8 V_17 , T_3 * V_18 , T_6 T_7 V_17 )
{
V_18 -> V_11 = 0 ;
}
static void
F_9 ( T_4 * V_8 V_17 , T_5 * V_18 , T_6 T_7 V_17 )
{
V_18 -> V_11 = 0 ;
}
static void
F_10 ( void * V_22 )
{
T_1 * V_1 = ( T_1 * ) V_22 ;
F_11 ( V_1 -> V_3 , ( V_23 ) F_8 , NULL ) ;
F_11 ( V_1 -> V_14 , ( V_23 ) F_9 , NULL ) ;
}
static int
F_12 ( void * V_22 , T_8 * T_9 V_17 , T_10 * T_11 V_17 , const void * V_24 )
{
const T_12 * V_10 = ( const T_12 * ) V_24 ;
T_1 * V_1 = ( T_1 * ) V_22 ;
if ( V_10 -> V_12 != 0 ) {
T_13 * V_8 = F_3 ( T_13 , 1 ) ;
T_3 * V_9 ;
* V_8 = V_10 -> V_12 ;
V_9 = ( T_3 * ) F_13 (
V_1 -> V_3 ,
V_8 ) ;
if ( V_9 == NULL ) {
int V_2 = V_10 -> V_12 ;
if ( ( V_2 < 100 ) || ( V_2 >= 600 ) ) {
return 0 ;
}
else if ( V_2 < 200 ) {
* V_8 = 199 ;
}
else if ( V_2 < 300 ) {
* V_8 = 299 ;
}
else if ( V_2 < 400 ) {
* V_8 = 399 ;
}
else if ( V_2 < 500 ) {
* V_8 = 499 ;
}
else {
* V_8 = 599 ;
}
V_9 = ( T_3 * ) F_13 (
V_1 -> V_3 ,
V_8 ) ;
if ( V_9 == NULL )
return 0 ;
}
V_9 -> V_11 ++ ;
}
else if ( V_10 -> V_25 ) {
T_5 * V_9 ;
V_9 = ( T_5 * ) F_13 (
V_1 -> V_14 ,
V_10 -> V_25 ) ;
if ( V_9 == NULL ) {
V_9 = F_3 ( T_5 , 1 ) ;
V_9 -> V_20 = F_14 ( V_10 -> V_25 ) ;
V_9 -> V_11 = 1 ;
V_9 -> V_1 = V_1 ;
F_4 ( V_1 -> V_14 , V_9 -> V_20 , V_9 ) ;
} else {
V_9 -> V_11 ++ ;
}
} else {
return 0 ;
}
return 1 ;
}
static void
F_15 ( void * V_22 )
{
T_1 * V_1 = ( T_1 * ) V_22 ;
printf ( L_2 ) ;
printf ( L_3 ) ;
if ( ! V_1 -> V_26 [ 0 ] )
printf ( L_4 ) ;
else
printf ( L_5 , V_1 -> V_26 ) ;
printf ( L_6 ) ;
F_11 ( V_1 -> V_3 , ( V_23 ) F_6 ,
( T_6 ) L_7 ) ;
printf ( L_8 ) ;
F_11 ( V_1 -> V_14 , ( V_23 ) F_5 ,
( T_6 ) L_9 ) ;
printf ( L_3 ) ;
}
static void
F_16 ( const char * V_27 , void * T_14 V_17 )
{
T_1 * V_1 ;
const char * V_26 = NULL ;
T_15 * V_28 ;
if ( ! strncmp ( V_27 , L_10 , 10 ) ) {
V_26 = V_27 + 10 ;
} else {
V_26 = NULL ;
}
V_1 = ( T_1 * ) F_17 ( sizeof( T_1 ) ) ;
if ( V_26 ) {
V_1 -> V_26 = F_14 ( V_26 ) ;
} else {
V_1 -> V_26 = NULL ;
}
V_28 = F_18 (
L_11 ,
V_1 ,
V_26 ,
0 ,
F_10 ,
F_12 ,
F_15 ) ;
if ( V_28 ) {
F_19 ( V_1 -> V_26 ) ;
F_19 ( V_1 ) ;
fprintf ( V_29 , L_12 ,
V_28 -> V_30 ) ;
F_20 ( V_28 , TRUE ) ;
exit ( 1 ) ;
}
F_1 ( V_1 ) ;
}
void
F_21 ( void )
{
F_22 ( & V_31 , NULL ) ;
}
