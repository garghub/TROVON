T_1 *
F_1 ( void )
{
T_1 * V_1 , * V_2 ;
T_1 * V_3 ;
#ifdef F_2
T_1 * V_4 ;
#endif
int V_5 = 0 ;
V_2 = F_3 ( V_6 , 7 , FALSE ) ;
F_4 ( F_5 ( V_2 ) , 5 ) ;
V_1 = F_6 ( V_7 , 2 , FALSE ) ;
F_7 ( F_8 ( V_2 ) , V_1 , FALSE , FALSE , 0 ) ;
F_9 ( F_10 ( V_1 ) , 10 ) ;
F_11 ( F_10 ( V_1 ) , 15 ) ;
F_12 ( V_1 ) ;
V_3 = F_13 ( V_1 , V_5 ++ ,
L_1 ,
L_2 , V_8 ) ;
F_14 ( V_9 , sizeof( V_9 ) , L_3 , V_10 . V_11 ) ;
F_15 ( F_16 ( V_3 ) , V_9 ) ;
F_17 ( V_3 , L_4 ) ;
F_18 ( F_19 ( V_2 ) , V_12 , V_3 ) ;
#ifdef F_2
V_4 = F_13 ( V_1 , V_5 ++ ,
L_5 ,
L_6 , V_8 ) ;
F_14 ( V_8 , sizeof( V_8 ) , L_3 , V_10 . V_13 ) ;
F_15 ( F_16 ( V_4 ) , V_8 ) ;
F_17 ( V_4 , L_7 ) ;
F_18 ( F_19 ( V_2 ) , V_14 , V_4 ) ;
#endif
F_20 ( V_2 ) ;
return V_2 ;
}
void
F_21 ( T_1 * T_2 V_15 )
{
T_1 * V_3 ;
#ifdef F_2
T_1 * V_4 ;
#endif
V_3 = ( T_1 * ) F_22 ( F_19 ( T_2 ) , V_12 ) ;
V_10 . V_11 = strtol ( F_23 (
F_16 ( V_3 ) ) , NULL , 10 ) ;
if ( V_10 . V_11 < 100 || V_10 . V_11 > 10000 ) {
V_10 . V_11 = 3000 ;
}
#ifdef F_2
V_4 = ( T_1 * ) F_22 ( F_19 ( T_2 ) , V_14 ) ;
V_10 . V_13 = strtol ( F_23 (
F_16 ( V_4 ) ) , NULL , 10 ) ;
if ( V_10 . V_13 < 1 || V_10 . V_13 > 10 )
V_10 . V_13 = V_16 ;
#endif
}
void
F_24 ( T_1 * T_2 V_15 )
{
#if F_25 ( V_17 )
F_26 () ;
#endif
}
void
F_27 ( T_1 * T_2 V_15 )
{
}
