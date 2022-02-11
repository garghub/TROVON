static void
F_1 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 T_5 V_1 )
{
V_2 -> V_3 = 0 ;
}
static void
F_2 ( T_1 * T_2 V_1 , T_3 * V_2 , T_1 * V_4 )
{
if ( ( V_2 == NULL ) || ( V_2 -> V_3 == 0 ) )
return;
printf ( V_4 , V_2 -> V_5 , V_2 -> V_3 ) ;
}
static void
F_3 ( void * V_6 )
{
T_6 * V_7 = ( T_6 * ) V_6 ;
F_4 ( V_7 -> V_8 , ( V_9 ) F_1 , NULL ) ;
}
static int
F_5 ( void * V_6 , T_7 * T_8 V_1 , T_9 * T_10 V_1 , const void * V_10 )
{
T_6 * V_7 = ( T_6 * ) V_6 ;
const T_11 V_11 = ( const T_11 ) V_10 ;
T_3 * V_12 ;
if ( V_7 == NULL )
return 0 ;
V_12 = ( T_3 * ) F_6 (
V_7 -> V_8 ,
V_11 ) ;
if ( ! V_12 ) {
V_12 = F_7 ( T_3 , 1 ) ;
V_12 -> V_3 = 1 ;
V_12 -> V_5 = V_11 ;
V_12 -> V_7 = V_7 ;
F_8 (
V_7 -> V_8 ,
( T_4 ) V_11 ,
V_12 ) ;
} else {
V_12 -> V_3 ++ ;
}
return 1 ;
}
static void
F_9 ( void * V_6 )
{
T_6 * V_7 = ( T_6 * ) V_6 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
if ( V_7 -> V_13 == NULL )
printf ( L_3 ) ;
else
printf ( L_4 , V_7 -> V_13 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
F_4 ( V_7 -> V_8 , ( V_9 ) F_2 ,
( T_4 ) L_7 ) ;
printf ( L_2 ) ;
}
static void
F_10 ( const char * V_14 , void * T_12 V_1 )
{
T_6 * V_7 ;
const char * V_13 = NULL ;
T_13 * V_15 ;
if ( ! strncmp ( V_14 , L_8 , 11 ) ) {
V_13 = V_14 + 11 ;
} else {
V_13 = NULL ;
}
V_7 = F_7 ( T_6 , 1 ) ;
V_7 -> V_8 = F_11 ( V_16 , V_17 ) ;
if( V_13 ) {
V_7 -> V_13 = F_12 ( V_13 ) ;
} else {
V_7 -> V_13 = NULL ;
}
V_7 -> V_18 = 0 ;
V_15 = F_13 (
L_9 ,
V_7 ,
V_13 ,
0 ,
F_3 ,
F_5 ,
F_9 ) ;
if ( V_15 ) {
F_14 ( V_7 -> V_13 ) ;
F_14 ( V_7 ) ;
fprintf ( V_19 , L_10 ,
V_15 -> V_20 ) ;
F_15 ( V_15 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_16 ( void )
{
F_17 ( L_8 , F_10 , NULL ) ;
}
