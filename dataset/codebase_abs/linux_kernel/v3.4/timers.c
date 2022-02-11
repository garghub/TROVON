static void F_1 ( void )
{
#ifdef F_2
F_3 ( F_2 | V_1 | V_2 ,
V_3 + V_4 ) ;
F_4 ( V_5 , V_6 ) ;
#ifdef F_5
F_3 ( F_2 | V_7 | V_2 ,
V_3 + V_8 ) ;
F_4 ( V_9 , V_10 ) ;
#endif
#endif
}
static T_1 F_6 ( int V_11 , void * V_12 )
{
F_7 ( V_13 | V_14 , F_8 ( V_15 ) ) ;
V_16 += V_17 ;
return F_9 ( V_11 , V_12 ) ;
}
static T_2 F_10 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
T_3 V_21 ;
T_4 V_22 ;
F_11 ( V_20 ) ;
V_22 = F_12 ( F_8 ( V_23 ) ) ;
V_21 = V_16 ;
F_13 ( V_20 ) ;
return V_21 + V_22 ;
}
void F_14 ( T_5 V_24 )
{
F_15 ( V_25 , F_8 ( V_26 ) ) ;
V_17 = V_27 / V_28 ;
F_16 ( V_17 - 1 , F_8 ( V_29 ) ) ;
F_15 ( V_30 | V_31 |
V_32 | V_33 , F_8 ( V_26 ) ) ;
F_17 ( & V_34 , V_27 ) ;
F_9 = V_24 ;
F_1 () ;
F_18 ( V_5 , & V_35 ) ;
#ifdef F_5
F_19 () ;
#endif
}
T_1 F_20 ( int V_11 , void * V_12 )
{
F_7 ( V_13 | V_14 , F_21 ( V_15 ) ) ;
if ( V_36 -> V_37 )
F_22 ( V_38 ) ;
return V_39 ;
}
void F_19 ( void )
{
F_23 ( V_40 L_1 ,
V_41 ) ;
F_15 ( V_25 , F_21 ( V_26 ) ) ;
F_16 ( ( ( V_42 / 16 ) / V_41 ) , F_21 ( V_29 ) ) ;
F_15 ( V_30 | V_31 |
V_32 | V_33 , F_21 ( V_26 ) ) ;
F_18 ( V_9 , & V_43 ) ;
}
