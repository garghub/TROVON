static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_2 ( V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( void )
{
F_5 ( 4 , 1 , 0 , 1 , L_1 ) ;
F_5 ( 5 , 1 , 0 , 1 , L_2 ) ;
F_5 ( 6 , 1 , 0 , 1 , L_3 ) ;
F_2 ( 0 , V_7 ) ;
F_2 ( 0 , V_6 ) ;
F_2 ( 0 , V_8 ) ;
F_2 ( V_9 , V_10 ) ;
F_2 ( 0 , V_11 ) ;
F_6 ( V_12 , V_13 , V_10 ) ;
F_6 ( 0 , V_14 , V_11 ) ;
F_6 ( V_15 , V_16 , V_11 ) ;
F_6 ( V_17 , V_18 , V_11 ) ;
F_6 ( 0 , V_19 , V_10 ) ;
F_7 ( V_20 ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_22 , V_25 , 0 ) ;
int V_26 = 0 ;
if ( ! V_24 )
return - V_27 ;
V_24 = F_10 ( & V_22 -> V_28 , V_24 -> V_29 ,
F_11 ( V_24 ) , F_12 ( & V_22 -> V_28 ) ) ;
if ( ! V_24 ) {
F_13 ( & V_22 -> V_28 , L_4 ) ;
return - V_30 ;
}
V_31 = F_14 ( & V_22 -> V_28 , V_24 -> V_29 ,
F_11 ( V_24 ) ) ;
if ( ! V_31 ) {
F_13 ( & V_22 -> V_28 , L_5 ) ;
return - V_32 ;
}
V_26 = F_15 ( & V_33 ) ;
if ( ! V_26 )
V_26 = F_4 () ;
return V_26 ;
}
int T_2 F_16 ( void )
{
int V_26 = F_17 ( & V_34 ) ;
if ( V_26 )
F_18 ( L_6 ) ;
return V_26 ;
}
