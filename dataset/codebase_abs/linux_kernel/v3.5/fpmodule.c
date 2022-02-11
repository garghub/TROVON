static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( V_3 == V_7 )
F_2 ( & V_6 -> V_8 ) ;
return V_9 ;
}
static int T_1 F_3 ( void )
{
if ( sizeof( V_10 ) > sizeof( union V_11 ) ) {
F_4 ( V_12 L_1 ) ;
return - V_13 ;
}
if ( sizeof( V_14 ) != 12 ) {
F_4 ( V_12 L_2 ) ;
return - V_13 ;
}
if ( V_15 [ 0 ] && strcmp ( V_15 , L_3 ) )
return 0 ;
F_4 ( V_16 L_4
V_17 L_5 ) ;
F_5 ( & V_18 ) ;
V_19 = V_20 ;
V_20 = V_21 ;
return 0 ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_18 ) ;
V_20 = V_19 ;
}
void F_8 ( signed char V_22 )
{
register unsigned int V_23 , V_24 ;
#ifdef F_9
if ( V_22 & V_25 )
F_4 ( V_26
L_6 ,
V_27 -> V_28 , V_27 -> V_29 , V_22 ,
F_10 ( 0 ) , F_11 () -> V_30 ) ;
#endif
V_23 = F_12 () ;
V_24 = 0 ;
if ( ( ! ( V_23 & V_31 ) ) && ( V_22 & V_32 ) )
V_24 |= V_32 ;
if ( ( ! ( V_23 & V_33 ) ) && ( V_22 & V_34 ) )
V_24 |= V_34 ;
if ( ( ! ( V_23 & V_35 ) ) && ( V_22 & V_36 ) )
V_24 |= V_36 ;
if ( ( ! ( V_23 & V_37 ) ) && ( V_22 & V_38 ) )
V_24 |= V_38 ;
if ( ( ! ( V_23 & V_39 ) ) && ( V_22 & V_40 ) )
V_24 |= V_40 ;
if ( V_24 )
F_13 ( V_23 | V_24 ) ;
if ( V_23 & ( V_22 << 16 ) )
F_14 ( V_41 , V_27 , 1 ) ;
}
