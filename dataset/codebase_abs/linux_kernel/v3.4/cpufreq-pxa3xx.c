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
static int F_14 ( struct V_1 * V_2 )
{
return F_15 ( V_2 , V_17 ) ;
}
static unsigned int F_16 ( unsigned int V_38 )
{
return F_17 ( 0 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_39 ,
unsigned int V_40 )
{
struct V_3 * V_41 ;
struct V_42 V_4 ;
unsigned long V_43 ;
int V_44 ;
if ( V_2 -> V_38 != 0 )
return - V_45 ;
if ( F_19 ( V_2 , V_17 ,
V_39 , V_40 , & V_44 ) )
return - V_45 ;
V_41 = & V_15 [ V_44 ] ;
V_4 . V_46 = V_2 -> V_47 ;
V_4 . V_48 = V_41 -> V_13 * 1000 ;
V_4 . V_38 = V_2 -> V_38 ;
F_20 ( L_1 ,
V_4 . V_46 / 1000 , V_4 . V_48 / 1000 ,
( V_4 . V_46 == V_4 . V_48 ) ? L_2 : L_3 ) ;
if ( V_4 . V_46 == V_39 )
return 0 ;
F_21 ( & V_4 , V_49 ) ;
F_22 ( V_43 ) ;
F_4 ( V_41 ) ;
F_9 ( V_41 ) ;
F_23 ( V_43 ) ;
F_21 ( & V_4 , V_50 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_51 = - V_45 ;
V_2 -> V_52 . V_53 = 104000 ;
V_2 -> V_52 . V_54 = ( F_25 () ) ? 806000 : 624000 ;
V_2 -> V_52 . V_55 = 1000 ;
V_2 -> V_56 = F_17 ( 0 ) ;
V_2 -> V_47 = V_2 -> V_57 = V_2 -> V_56 ;
if ( F_26 () || F_27 () )
V_51 = F_1 ( V_2 , F_28 ( V_58 ) ) ;
if ( F_25 () )
V_51 = F_1 ( V_2 , F_28 ( V_59 ) ) ;
if ( V_51 ) {
F_29 ( L_4 ) ;
return V_51 ;
}
F_30 ( L_5 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
if ( F_32 () )
return F_33 ( & V_60 ) ;
return 0 ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_60 ) ;
}
