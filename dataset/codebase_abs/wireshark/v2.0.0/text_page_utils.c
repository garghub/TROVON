T_1 * F_1 ( const char * V_1 )
{
T_1 * V_2 , * V_3 , * V_4 ;
V_2 = F_2 ( V_5 , 0 , FALSE ) ;
F_3 ( F_4 ( V_2 ) , 1 ) ;
V_3 = F_5 ( NULL , NULL ) ;
F_6 ( F_7 ( V_3 ) ,
V_6 ) ;
F_8 ( F_9 ( V_2 ) , V_3 , TRUE , TRUE , 0 ) ;
F_10 ( F_7 ( V_3 ) ,
V_7 , V_7 ) ;
V_4 = F_11 () ;
F_12 ( F_13 ( V_4 ) , FALSE ) ;
F_14 ( F_13 ( V_4 ) , V_8 ) ;
F_15 ( F_13 ( V_4 ) , FALSE ) ;
F_16 ( F_17 ( V_2 ) , V_9 , V_4 ) ;
F_18 ( V_2 , V_1 ) ;
F_19 ( F_4 ( V_3 ) , V_4 ) ;
F_20 ( V_3 ) ;
F_20 ( V_4 ) ;
return V_2 ;
}
static void F_21 ( T_1 * V_10 , const char * V_11 , int V_12 )
{
T_1 * V_4 = ( T_1 * ) F_22 ( F_17 ( V_10 ) , V_9 ) ;
T_2 * V_13 = F_23 ( F_13 ( V_4 ) ) ;
T_3 V_14 ;
F_24 ( V_13 , & V_14 ) ;
#if F_25 ( 3 , 0 , 0 )
F_26 ( F_27 ( V_4 ) , F_28 () ) ;
#else
F_29 ( F_27 ( V_4 ) , F_28 () ) ;
#endif
if ( ! F_30 ( V_11 , - 1 , NULL ) )
printf ( L_1 , V_11 ) ;
F_31 ( V_13 , & V_14 , V_11 , V_12 ) ;
}
static void F_18 ( T_1 * V_10 , const char * V_1 )
{
T_4 * V_15 ;
char line [ 4096 + 1 ] ;
V_15 = F_32 ( V_1 , L_2 ) ;
if ( V_15 != NULL ) {
while ( fgets ( line , sizeof line , V_15 ) != NULL ) {
F_21 ( V_10 , line , ( int ) strlen ( line ) ) ;
}
if( ferror ( V_15 ) ) {
F_33 ( V_16 , V_17 , L_3 ,
V_1 , F_34 ( V_18 ) ) ;
}
fclose ( V_15 ) ;
} else {
F_33 ( V_16 , V_17 , L_4 ,
V_1 , F_34 ( V_18 ) ) ;
}
}
static void F_35 ( T_1 * V_10 )
{
T_2 * V_13 = F_23 ( F_13 ( F_22 ( F_17 ( V_10 ) , V_9 ) ) ) ;
F_36 ( V_13 , L_5 , 0 ) ;
}
void F_37 ( T_1 * V_10 , const char * V_1 )
{
F_35 ( V_10 ) ;
F_18 ( V_10 , V_1 ) ;
}
