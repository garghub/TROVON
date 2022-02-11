static void F_1 ( T_1 V_1 , T_1 V_2 , const char * V_3 )
{
double V_4 = V_2 ? 1.0 * V_1 / V_2 : 0.0 ;
char V_5 [ 1024 ] ;
if ( V_6 == NULL ) {
T_2 * V_7 = F_2 ( TRUE , 5 ) ;
T_2 * V_8 = F_3 ( V_3 ) ;
V_6 = F_4 ( V_9 ) ;
V_10 = F_5 () ;
F_6 ( F_7 ( V_7 ) , V_8 , TRUE , FALSE , 3 ) ;
F_6 ( F_7 ( V_7 ) , V_10 , TRUE , TRUE , 3 ) ;
F_8 ( F_9 ( V_6 ) , V_7 ) ;
F_10 ( F_11 ( V_6 ) , L_1 ) ;
F_12 ( F_11 ( V_6 ) , 300 , 80 ) ;
F_13 ( F_11 ( V_6 ) , V_11 ) ;
F_14 ( V_6 ) ;
}
F_15 ( F_16 ( V_10 ) , V_4 ) ;
snprintf ( V_5 , sizeof( V_5 ) , L_2 V_12 L_3 V_12 , V_1 , V_2 ) ;
F_17 ( F_16 ( V_10 ) , V_5 ) ;
while ( F_18 () )
F_19 () ;
}
static void F_20 ( void )
{
F_21 ( V_6 ) ;
V_6 = NULL ;
}
void F_22 ( void )
{
V_13 = & V_14 ;
}
