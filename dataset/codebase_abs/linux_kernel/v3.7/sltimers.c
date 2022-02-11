T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_3 | V_4 , F_3 ( V_5 ) ) ;
if ( V_6 -> V_7 )
F_4 ( V_8 ) ;
return V_9 ;
}
void F_5 ( void )
{
F_6 ( V_10 L_1 ,
V_11 ) ;
F_7 ( V_12 , & V_13 ) ;
F_2 ( V_14 / V_11 - 1 , F_3 ( V_15 ) ) ;
F_2 ( V_16 | V_17 | V_18 ,
F_3 ( V_19 ) ) ;
}
static T_1 F_8 ( int V_1 , void * V_2 )
{
F_2 ( V_3 | V_4 , F_9 ( V_5 ) ) ;
V_20 += V_21 ;
return F_10 ( V_1 , V_2 ) ;
}
static T_2 F_11 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
T_3 V_25 , V_26 ;
F_12 ( V_24 ) ;
V_26 = F_13 ( F_9 ( V_27 ) ) ;
V_25 = V_20 ;
if ( F_13 ( F_9 ( V_5 ) ) & V_4 ) {
V_25 += V_21 ;
V_26 = F_13 ( F_9 ( V_27 ) ) ;
}
F_14 ( V_24 ) ;
return V_25 + ( ( V_21 - 1 ) - V_26 ) ;
}
void F_15 ( T_4 V_28 )
{
V_21 = V_14 / V_29 ;
F_2 ( V_21 - 1 , F_9 ( V_15 ) ) ;
F_2 ( V_16 | V_17 | V_18 ,
F_9 ( V_19 ) ) ;
V_20 = V_21 ;
F_10 = V_28 ;
F_7 ( V_30 , & V_31 ) ;
F_16 ( & V_32 , V_14 ) ;
#ifdef F_17
F_5 () ;
#endif
}
