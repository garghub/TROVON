static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_9 != 2 )
return - V_10 ;
if ( V_8 [ 0 ] ) {
V_5 -> V_11 &= ~ V_8 [ 0 ] ;
V_5 -> V_11 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
F_6 ( V_5 -> V_11 , V_3 -> V_12 + V_13 ) ;
}
V_8 [ 1 ] = V_5 -> V_11 ;
return 2 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_9 != 2 )
return - V_10 ;
V_8 [ 1 ] = F_8 ( V_3 -> V_12 + V_14 ) ;
return 2 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
struct V_4 * V_5 ;
unsigned long V_12 ;
V_12 = V_16 -> V_17 [ 0 ] ;
F_10 ( V_18 L_1 , V_3 -> V_19 , V_12 ) ;
if ( ! F_11 ( V_12 , V_20 , L_2 ) ) {
F_10 ( L_3 ) ;
return - V_21 ;
}
V_3 -> V_22 = L_2 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_23 = 0 ;
if ( F_12 ( V_3 , 2 ) < 0 )
return - V_24 ;
V_5 = V_3 -> V_25 + 0 ;
V_5 -> type = V_26 ;
V_5 -> V_27 = V_28 ;
V_5 -> V_29 = 1 ;
V_5 -> V_30 = 8 ;
V_5 -> V_31 = F_5 ;
V_5 -> V_32 = & V_33 ;
V_5 = V_3 -> V_25 + 1 ;
V_5 -> type = V_34 ;
V_5 -> V_27 = V_35 ;
V_5 -> V_29 = 1 ;
V_5 -> V_30 = 8 ;
V_5 -> V_31 = F_7 ;
V_5 -> V_32 = & V_33 ;
F_10 ( V_18 L_4 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_10 ( V_18 L_5 , V_3 -> V_19 ) ;
if ( V_3 -> V_12 )
F_14 ( V_3 -> V_12 , V_20 ) ;
return 0 ;
}
