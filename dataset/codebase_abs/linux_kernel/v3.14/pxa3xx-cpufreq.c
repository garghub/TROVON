static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( ( V_5 + 1 ) * sizeof( * V_7 ) , V_9 ) ;
if ( V_7 == NULL )
return - V_10 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ ) {
V_7 [ V_8 ] . V_11 = V_8 ;
V_7 [ V_8 ] . V_12 = V_4 [ V_8 ] . V_13 * 1000 ;
}
V_7 [ V_5 ] . V_11 = V_8 ;
V_7 [ V_5 ] . V_12 = V_14 ;
V_15 = V_4 ;
V_16 = V_5 ;
V_17 = V_7 ;
return F_3 ( V_2 , V_7 ) ;
}
static void F_4 ( struct V_3 * V_18 )
{
T_1 V_19 = V_20 | V_21 ;
T_1 V_22 = V_23 ;
T_1 V_24 ;
V_22 &= ~ ( V_20 | V_21 | V_25 ) ;
V_22 |= F_5 ( V_18 -> V_26 ) | F_6 ( V_18 -> V_27 ) ;
V_22 |= F_7 ( V_28 ) ;
V_24 = ( V_18 -> V_26 == 2 ) ? 0x3 : 0x2 ;
V_23 = V_22 ;
__asm__("mcr p14, 0, %0, c6, c0, 0\n" : : "r"(xclkcfg));
while ( ( V_29 & V_19 ) != ( V_22 & V_19 ) )
F_8 () ;
}
static void F_9 ( struct V_3 * V_18 )
{
T_1 V_19 ;
T_1 V_22 = V_23 ;
V_19 = V_30 | V_31 | V_32 |
V_33 ;
V_22 &= ~ V_19 ;
V_22 |= F_10 ( V_18 -> V_34 ) | F_11 ( V_18 -> V_35 ) |
F_12 ( V_18 -> V_36 ) | F_13 ( V_18 -> V_37 ) ;
V_23 = V_22 ;
while ( ( V_29 & V_19 ) != ( V_22 & V_19 ) )
F_8 () ;
}
static unsigned int F_14 ( unsigned int V_38 )
{
return F_15 ( 0 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_39 )
{
struct V_3 * V_40 ;
unsigned long V_41 ;
if ( V_2 -> V_38 != 0 )
return - V_42 ;
V_40 = & V_15 [ V_39 ] ;
F_17 ( V_41 ) ;
F_4 ( V_40 ) ;
F_9 ( V_40 ) ;
F_18 ( V_41 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_43 = - V_42 ;
V_2 -> V_44 = V_2 -> V_45 . V_46 = 104000 ;
V_2 -> V_47 = V_2 -> V_45 . V_48 =
( F_20 () ) ? 806000 : 624000 ;
V_2 -> V_45 . V_49 = 1000 ;
if ( F_21 () || F_22 () )
V_43 = F_1 ( V_2 , V_50 ,
F_23 ( V_50 ) ) ;
if ( F_20 () )
V_43 = F_1 ( V_2 , V_51 ,
F_23 ( V_51 ) ) ;
if ( V_43 ) {
F_24 ( L_1 ) ;
return V_43 ;
}
F_25 ( L_2 ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
if ( F_27 () )
return F_28 ( & V_52 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_52 ) ;
}
