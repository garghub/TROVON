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
F_11 ( V_23 L_1 ,
V_16 -> V_24 ,
V_16 -> V_17 , V_16 -> V_25 ) ;
for ( V_1 = 0 ; V_1 < V_26 ; V_1 ++ )
F_12 ( F_3 ( V_1 ) ) ;
V_27 -> V_28 = 0 ;
for ( V_1 = 0 ; V_1 < F_13 ( V_27 -> V_29 ) ; V_1 ++ ) {
V_27 -> V_29 [ V_1 ] . V_30 = V_31 ;
V_27 -> V_29 [ V_1 ] . V_30 = 0 ;
}
#ifdef F_14
V_27 -> V_28 = V_32 ;
#else
V_27 -> V_28 = V_32 | V_33 ;
#endif
F_15 ( 0 , & V_34 -> V_35 ) ;
F_15 ( 0 , & V_34 -> V_36 ) ;
F_16 ( V_37 , 0 , 16 ) ;
V_2 = F_10 () ;
if ( V_2 & V_38 ) {
if ( ! ( V_2 & V_20 ) )
F_17 ( L_2 ) ;
else if ( ! ( V_2 & V_39 ) )
F_17 ( L_3 ) ;
else
F_17 ( L_4 ) ;
}
}
void T_1 F_18 ( unsigned int V_40 , unsigned int V_41 )
{
F_19 ( F_3 ( V_40 ) ,
V_42 + F_20 ( V_40 ) ,
V_43 ) ;
F_21 ( F_3 ( V_41 ) , V_43 ) ;
}
void T_1 F_22 ( unsigned int V_44 , unsigned int V_45 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ )
F_23 ( F_24 ( V_1 ) ,
V_42 + F_25 ( V_1 ) ,
V_1 , V_44 , ( 1 << V_1 ) & V_45 ) ;
}
void T_1 F_26 ( int V_29 )
{
struct V_46 V_47 = {
. V_48 = F_27 ( V_29 ) / 8 ,
} ;
unsigned long V_8 = V_7 [ V_29 ] . V_8 ;
unsigned long V_49 = V_7 [ V_29 ] . V_9 - V_8 + 1 ;
if ( ! ( V_5 -> V_6 [ V_29 ] & 0x8 ) )
return;
F_28 ( V_29 , V_8 , V_49 , & V_47 ) ;
}
