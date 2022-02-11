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
F_4 ( L_1 ) ;
return - V_12 ;
}
if ( sizeof( V_13 ) != 12 ) {
F_4 ( L_2 ) ;
return - V_12 ;
}
if ( V_14 [ 0 ] && strcmp ( V_14 , L_3 ) )
return 0 ;
F_5 ( L_4
V_15 L_5 ) ;
F_6 ( & V_16 ) ;
V_17 = V_18 ;
V_18 = V_19 ;
return 0 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_16 ) ;
V_18 = V_17 ;
}
void F_9 ( signed char V_20 )
{
register unsigned int V_21 , V_22 ;
#ifdef F_10
if ( V_20 & V_23 )
F_11 ( V_24
L_6 ,
V_25 -> V_26 , V_25 -> V_27 , V_20 ,
F_12 ( 0 ) , F_13 () -> V_28 ) ;
#endif
V_21 = F_14 () ;
V_22 = 0 ;
if ( ( ! ( V_21 & V_29 ) ) && ( V_20 & V_30 ) )
V_22 |= V_30 ;
if ( ( ! ( V_21 & V_31 ) ) && ( V_20 & V_32 ) )
V_22 |= V_32 ;
if ( ( ! ( V_21 & V_33 ) ) && ( V_20 & V_34 ) )
V_22 |= V_34 ;
if ( ( ! ( V_21 & V_35 ) ) && ( V_20 & V_36 ) )
V_22 |= V_36 ;
if ( ( ! ( V_21 & V_37 ) ) && ( V_20 & V_38 ) )
V_22 |= V_38 ;
if ( V_22 )
F_15 ( V_21 | V_22 ) ;
if ( V_21 & ( V_20 << 16 ) )
F_16 ( V_39 , V_25 , 1 ) ;
}
