void T_1 F_1 ( void )
{
F_2 ( F_3 ( 2 ) ) ;
}
void T_1 F_4 ( void )
{
int V_1 ;
unsigned int V_2 ;
F_5 ( F_6 () , V_3 ,
V_4 ) ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
if ( ! ( V_5 -> V_6 [ V_1 ] & 0x8 ) )
continue;
V_7 [ V_1 ] . V_8 = ( unsigned long ) F_7 ( V_1 ) ;
V_7 [ V_1 ] . V_9 =
V_7 [ V_1 ] . V_8 + F_8 ( V_1 ) - 1 ;
F_9 ( & V_10 , & V_7 [ V_1 ] ) ;
}
V_11 = V_12 / 2 ;
V_13 = V_12 / V_14 / 2 ;
if ( V_15 )
V_16 -> V_17 |= V_18 ;
V_16 -> V_17 &= ~ V_19 ;
if ( F_10 () & V_20 )
V_16 -> V_17 &= ~ V_21 ;
else
V_16 -> V_17 |= V_21 ;
V_16 -> V_17 |= V_22 ;
F_11 ( L_1 ,
V_16 -> V_23 , V_16 -> V_17 ,
V_16 -> V_24 ) ;
for ( V_1 = 0 ; V_1 < V_25 ; V_1 ++ )
F_12 ( F_3 ( V_1 ) ) ;
V_26 -> V_27 = 0 ;
for ( V_1 = 0 ; V_1 < F_13 ( V_26 -> V_28 ) ; V_1 ++ ) {
V_26 -> V_28 [ V_1 ] . V_29 = V_30 ;
V_26 -> V_28 [ V_1 ] . V_29 = 0 ;
}
#ifdef F_14
V_26 -> V_27 = V_31 ;
#else
V_26 -> V_27 = V_31 | V_32 ;
#endif
F_15 ( 0 , & V_33 -> V_34 ) ;
F_15 ( 0 , & V_33 -> V_35 ) ;
V_2 = F_10 () ;
if ( V_2 & V_36 ) {
if ( ! ( V_2 & V_20 ) )
F_11 ( L_2 ) ;
else if ( ! ( V_2 & V_37 ) )
F_11 ( L_3 ) ;
else
F_11 ( L_4 ) ;
}
}
void T_1 F_16 ( unsigned int V_38 , unsigned int V_39 )
{
F_17 ( F_3 ( V_38 ) ,
V_40 + F_18 ( V_38 ) ,
V_41 ) ;
F_19 ( F_3 ( V_39 ) , V_41 ) ;
}
void T_1 F_20 ( unsigned int V_42 , unsigned int V_43 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ )
F_21 ( F_22 ( V_1 ) ,
V_40 + F_23 ( V_1 ) ,
V_1 , V_42 , ( 1 << V_1 ) & V_43 ) ;
}
void T_1 F_24 ( int V_28 )
{
struct V_44 V_45 = {
. V_46 = F_25 ( V_28 ) / 8 ,
} ;
unsigned long V_8 = V_7 [ V_28 ] . V_8 ;
unsigned long V_47 = V_7 [ V_28 ] . V_9 - V_8 + 1 ;
if ( ! ( V_5 -> V_6 [ V_28 ] & 0x8 ) )
return;
F_26 ( V_28 , V_8 , V_47 , & V_45 ) ;
}
