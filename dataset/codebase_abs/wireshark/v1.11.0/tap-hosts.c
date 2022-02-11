static void
F_1 ( T_1 T_2 V_1 , T_1 V_2 , T_1 T_3 V_1 )
{
T_4 * V_3 = ( T_4 * ) V_2 ;
if( ( V_3 -> V_4 & V_5 ) == V_5 ) {
printf ( L_1 ,
V_3 -> V_6 ,
V_3 -> V_7 ) ;
}
}
static void
F_2 ( T_1 T_2 V_1 , T_1 V_2 , T_1 T_3 V_1 )
{
T_5 * V_8 = ( T_5 * ) V_2 ;
if( ( V_8 -> V_4 & V_5 ) == V_5 ) {
printf ( L_1 ,
V_8 -> V_9 ,
V_8 -> V_7 ) ;
}
}
static void
F_3 ( void * T_6 V_1 )
{
T_7 * V_10 ;
T_7 * V_11 ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_12 . V_13 ) ;
printf ( L_5 ) ;
V_10 = F_4 () ;
if( V_10 ) {
F_5 ( V_10 , F_1 , NULL ) ;
}
V_11 = F_6 () ;
if( V_11 ) {
F_5 ( V_11 , F_2 , NULL ) ;
}
}
static void
F_7 ( const char * V_14 , void * T_8 V_1 )
{
T_9 * V_15 ;
T_10 * * V_16 ;
T_11 V_17 ;
V_18 = FALSE ;
V_19 = FALSE ;
if( strcmp ( V_20 , V_14 ) == 0 ) {
V_18 = TRUE ;
V_19 = TRUE ;
} else {
V_16 = F_8 ( V_14 , L_6 , 0 ) ;
V_17 = 0 ;
while ( V_16 [ V_17 ] ) {
if ( strcmp ( L_7 , V_16 [ V_17 ] ) == 0 ) {
V_18 = TRUE ;
} else if ( strcmp ( L_8 , V_16 [ V_17 ] ) == 0 ) {
V_19 = TRUE ;
} else if ( V_17 > 0 ) {
fprintf ( V_21 , L_9 V_20 L_10 ) ;
exit ( 1 ) ;
}
V_17 ++ ;
}
F_9 ( V_16 ) ;
}
V_15 = F_10 ( L_11 , NULL , NULL , V_22 ,
NULL , NULL , F_3 ) ;
if( V_15 ) {
fprintf ( V_21 , L_12 V_20 L_13 ,
V_15 -> V_23 ) ;
F_11 ( V_15 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_12 ( void )
{
F_13 ( V_20 , F_7 , NULL ) ;
}
