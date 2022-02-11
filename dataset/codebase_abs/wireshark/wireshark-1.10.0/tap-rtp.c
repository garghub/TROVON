static void
F_1 ( void * T_1 V_1 )
{
T_2 * V_2 ;
T_3 * V_3 ;
T_4 * V_4 ;
T_5 V_5 ;
T_6 V_6 ;
double V_7 ;
char * V_8 ;
printf ( L_1 ) ;
printf ( L_2 , L_3 , L_4 , L_5 , L_4 , L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ) ;
V_8 = setlocale ( V_9 , NULL ) ;
setlocale ( V_9 , L_14 ) ;
V_2 = V_10 . V_11 ;
V_2 = F_2 ( V_2 ) ;
while ( V_2 )
{
V_3 = ( T_3 * ) ( V_2 -> V_12 ) ;
if( V_3 -> V_13 > 95 ) {
if( V_3 -> V_14 != NULL ) {
V_4 = F_3 ( V_3 -> V_14 ) ;
} else{
V_4 = F_4 ( L_15 , V_3 -> V_13 ) ;
}
} else{
V_4 = F_3 ( F_5 ( V_3 -> V_13 , & V_15 ,
L_16 ) ) ;
}
V_5 = ( V_3 -> V_16 . V_17 + V_3 -> V_16 . V_18 * 65536 )
- V_3 -> V_16 . V_19 + 1 ;
V_6 = V_5 - V_3 -> V_16 . V_20 ;
if ( V_5 ) {
V_7 = ( double ) ( V_6 * 100 ) / ( double ) V_5 ;
} else {
V_7 = 0 ;
}
printf ( L_17 ,
F_6 ( & ( V_3 -> V_21 ) ) ,
V_3 -> V_22 ,
F_6 ( & ( V_3 -> V_23 ) ) ,
V_3 -> V_24 ,
V_3 -> V_25 ,
V_4 ,
V_3 -> V_26 ,
V_6 , V_7 ,
V_3 -> V_16 . V_27 ,
V_3 -> V_16 . V_28 ,
V_3 -> V_16 . V_29 ,
( V_3 -> V_30 ) ? L_18 : L_19 ) ;
V_2 = F_7 ( V_2 ) ;
F_8 ( V_4 ) ;
}
printf ( L_20 ) ;
setlocale ( V_9 , V_8 ) ;
}
static void
F_9 ( const char * T_7 V_1 , void * T_8 V_1 )
{
T_9 * V_31 ;
V_31 =
F_10 ( L_21 , & V_10 , NULL , 0 ,
V_32 ,
V_33 ,
F_1 ) ;
if ( V_31 != NULL )
{
F_11 ( V_31 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_12 ( void )
{
F_13 ( L_22 , F_9 , NULL ) ;
}
