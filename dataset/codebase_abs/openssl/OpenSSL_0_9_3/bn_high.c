int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , T_1 * V_4 , int V_5 )
{
int V_6 , V_7 = 0 , V_8 = 0 ;
T_1 V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ;
T_2 V_20 , V_21 ;
F_2 ( V_1 , V_2 , V_3 ) ;
F_3 ( V_1 , V_1 , V_5 * V_22 ) ;
return ( 1 ) ;
V_6 = ( V_5 + 1 ) / 2 ;
#ifdef F_4
fprintf ( stdout , L_1 , V_5 , V_6 ) ;
#endif
F_5 ( stdout , V_2 , L_2 ) ;
F_5 ( stdout , V_3 , L_3 ) ;
F_5 ( stdout , V_4 , L_4 ) ;
F_6 ( & V_14 ) ; F_6 ( & V_13 ) ;
F_6 ( & V_16 ) ; F_6 ( & V_15 ) ;
F_6 ( & V_9 ) ; F_6 ( & V_10 ) ; F_6 ( & V_11 ) ;
F_6 ( & V_18 ) ; F_6 ( & V_19 ) ;
F_6 ( & V_12 ) ; F_6 ( & V_17 ) ;
F_7 ( & V_14 , V_2 , V_6 ) ;
F_8 ( & V_13 , V_2 , V_6 ) ;
F_7 ( & V_16 , V_3 , V_6 ) ;
F_8 ( & V_15 , V_3 , V_6 ) ;
F_7 ( & V_18 , V_4 , V_6 ) ;
F_8 ( & V_19 , V_4 , V_6 ) ;
F_5 ( stdout , & V_14 , L_5 ) ;
F_5 ( stdout , & V_13 , L_6 ) ;
F_5 ( stdout , & V_16 , L_7 ) ;
F_5 ( stdout , & V_15 , L_8 ) ;
F_5 ( stdout , & V_18 , L_9 ) ;
F_5 ( stdout , & V_19 , L_10 ) ;
F_9 ( & V_9 , & V_14 , & V_13 ) ;
F_9 ( & V_10 , & V_15 , & V_16 ) ;
F_2 ( & V_17 , & V_9 , & V_10 ) ;
F_2 ( & V_12 , & V_13 , & V_15 ) ;
F_10 ( & V_17 , & V_17 , & V_12 ) ;
F_10 ( & V_10 , & V_17 , & V_18 ) ;
F_5 ( stdout , & V_10 , L_11 ) ;
if ( V_6 < V_10 . V_23 ) V_10 . V_23 = V_6 ;
#if 0
bn_set_low(&t3,&t2,w2);
#endif
F_5 ( stdout , & V_10 , L_12 ) ;
F_9 ( & V_9 , & V_19 , & V_10 ) ;
if ( V_9 . V_24 )
{
F_5 ( stdout , & V_9 , L_13 ) ;
F_11 ( & V_10 ) ;
F_12 ( & V_10 , V_6 * V_22 ) ;
F_10 ( & V_9 , & V_10 , & V_9 ) ;
F_5 ( stdout , & V_9 , L_14 ) ;
V_7 = 1 ;
}
F_13 ( & V_9 , & V_9 , V_6 * V_22 ) ;
F_10 ( & V_9 , & V_9 , & V_18 ) ;
if ( V_6 * 2 < V_9 . V_23 ) V_9 . V_23 = V_6 * 2 ;
#if 0
BN_add(&m,&m,&t1);
debug_BN_print(stdout,&t1," s10\n");
debug_BN_print(stdout,&m," s21\n");
debug_BN_print(stdout,&h," s32\n");
BN_lshift(&m,&m,w2*BN_BITS2);
BN_lshift(&h,&h,w2*2*BN_BITS2);
BN_add(r,&m,&t1);
BN_add(r,r,&h);
BN_rshift(r,r,w2*2*BN_BITS2);
#else
F_10 ( & V_17 , & V_17 , & V_9 ) ;
F_8 ( & V_11 , & V_9 , V_6 ) ;
F_10 ( & V_17 , & V_17 , & V_11 ) ;
F_8 ( & V_11 , & V_17 , V_6 ) ;
F_10 ( V_1 , & V_12 , & V_11 ) ;
#endif
#ifdef F_4
printf ( L_15 , V_7 ) ;
#endif
F_5 ( stdout , V_1 , L_16 ) ;
F_14 ( & V_9 ) ; F_14 ( & V_10 ) ;
F_14 ( & V_17 ) ; F_14 ( & V_12 ) ;
return ( 1 ) ;
}
