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
char * V_9 , * V_10 ;
printf ( L_1 ) ;
printf ( L_2 , L_3 , L_4 , L_5 , L_4 , L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ) ;
V_8 = F_2 ( setlocale ( V_11 , NULL ) ) ;
setlocale ( V_11 , L_14 ) ;
V_2 = V_12 . V_13 ;
V_2 = F_3 ( V_2 ) ;
while ( V_2 )
{
V_3 = ( T_3 * ) ( V_2 -> V_14 ) ;
if ( V_3 -> V_4 > 95 ) {
if ( V_3 -> V_15 != NULL ) {
V_4 = F_4 ( NULL , V_3 -> V_15 ) ;
} else{
V_4 = F_5 ( NULL , L_15 , V_3 -> V_4 ) ;
}
} else{
V_4 = F_6 ( NULL , V_3 -> V_4 , & V_16 , L_16 ) ;
}
V_5 = ( V_3 -> V_17 . V_18 + V_3 -> V_17 . V_19 * 65536 )
- V_3 -> V_17 . V_20 + 1 ;
V_6 = V_5 - V_3 -> V_17 . V_21 ;
if ( V_5 ) {
V_7 = ( double ) ( V_6 * 100 ) / ( double ) V_5 ;
} else {
V_7 = 0 ;
}
V_9 = F_7 ( NULL , & ( V_3 -> V_9 ) ) ;
V_10 = F_7 ( NULL , & ( V_3 -> V_22 ) ) ;
printf ( L_17 ,
V_9 ,
V_3 -> V_23 ,
V_10 ,
V_3 -> V_24 ,
V_3 -> V_25 ,
V_4 ,
V_3 -> V_26 ,
V_6 , V_7 ,
V_3 -> V_17 . V_27 ,
V_3 -> V_17 . V_28 ,
V_3 -> V_17 . V_29 ,
( V_3 -> V_30 ) ? L_18 : L_19 ) ;
V_2 = F_8 ( V_2 ) ;
F_9 ( NULL , V_9 ) ;
F_9 ( NULL , V_10 ) ;
F_9 ( NULL , V_4 ) ;
}
printf ( L_20 ) ;
setlocale ( V_11 , V_8 ) ;
F_10 ( V_8 ) ;
}
static void
F_11 ( const char * T_7 V_1 , void * T_8 V_1 )
{
T_9 * V_31 ;
V_31 =
F_12 ( L_21 , & V_12 , NULL , 0 ,
V_32 ,
V_33 ,
F_1 ) ;
if ( V_31 != NULL )
{
F_13 ( V_31 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_14 ( void )
{
F_15 ( & V_34 , NULL ) ;
}
