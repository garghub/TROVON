static void F_1 ( struct V_1 * V_2 )
{
double V_3 = V_2 -> V_4 ? 1.0 * V_2 -> V_5 / V_2 -> V_4 : 0.0 ;
char V_6 [ 1024 ] ;
if ( V_7 == NULL ) {
T_1 * V_8 = F_2 ( TRUE , 5 ) ;
T_1 * V_9 = F_3 ( V_2 -> V_10 ) ;
V_7 = F_4 ( V_11 ) ;
V_12 = F_5 () ;
F_6 ( F_7 ( V_8 ) , V_9 , TRUE , FALSE , 3 ) ;
F_6 ( F_7 ( V_8 ) , V_12 , TRUE , TRUE , 3 ) ;
F_8 ( F_9 ( V_7 ) , V_8 ) ;
F_10 ( F_11 ( V_7 ) , L_1 ) ;
F_12 ( F_11 ( V_7 ) , 300 , 80 ) ;
F_13 ( F_11 ( V_7 ) , V_13 ) ;
F_14 ( V_7 ) ;
}
F_15 ( F_16 ( V_12 ) , V_3 ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_2 V_14 L_3 V_14 , V_2 -> V_5 , V_2 -> V_4 ) ;
F_17 ( F_16 ( V_12 ) , V_6 ) ;
while ( F_18 () )
F_19 () ;
}
static void F_20 ( void )
{
F_21 ( V_7 ) ;
V_7 = NULL ;
}
void F_22 ( void )
{
V_15 = & V_16 ;
}
