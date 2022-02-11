void F_1 ( void )
{
T_1 V_1 ;
V_2 = V_3 ;
V_4 = ( V_5 | V_6 |
V_7 ) ;
F_2 ( V_8 ) ;
F_3 ( V_9 ) ;
F_4 ( 115200 ) ;
F_5 ( V_10 ) = 0 ;
V_1 = F_5 ( V_10 ) ;
#if V_11 == 0
V_12 = V_13 ;
#elif V_11 == 1
V_14 = V_15 ;
#elif V_11 == 2
V_16 = V_17 ;
#elif V_11 == 3
V_18 = V_19 ;
#elif V_11 == 4
V_20 = V_21 ;
#elif V_11 == 5
V_22 = V_23 ;
#else
#error "Unknown irq level for gdbstub."
#endif
F_6 ( F_7 ( V_11 ) ,
V_24 ) ;
F_5 ( V_10 ) &= ~ V_25 ;
F_5 ( V_10 ) =
V_26 | F_8 ( V_11 ) ;
V_1 = F_5 ( V_10 ) ;
V_27 = V_28 | V_29 ;
F_9 (
F_10 ( V_11 + 1 ) ) ;
}
void F_4 ( unsigned V_30 )
{
unsigned V_31 ;
T_2 V_32 ;
V_31 = 18432000 / 16 / V_30 ;
V_32 = V_2 ;
V_2 |= V_33 ;
V_34 = V_31 & 0xff ;
V_35 = ( V_31 >> 8 ) & 0xff ;
V_2 = V_32 ;
}
int F_11 ( unsigned char * V_36 , int V_37 )
{
unsigned V_38 ;
T_2 V_39 , V_40 ;
#if F_12 ( V_41 )
int V_42 ;
#endif
* V_36 = 0xff ;
if ( V_43 ) {
* V_36 = V_43 ;
V_43 = 0 ;
return 0 ;
}
V_44:
V_38 = V_45 ;
F_13 () ;
if ( V_38 == V_46 ) {
if ( V_37 )
return - V_47 ;
#ifdef V_41
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ )
V_49 [ V_42 ] = 0 ;
#endif
goto V_44;
}
V_39 = V_50 [ V_38 ++ ] ;
V_40 = V_50 [ V_38 ++ ] ;
F_13 () ;
V_45 = V_38 & 0x00000fff ;
if ( V_40 & V_51 ) {
F_14 ( L_1 ) ;
return - V_52 ;
} else if ( V_40 & ( V_53 | V_54 | V_55 ) ) {
F_14 ( L_2 , V_40 ) ;
return - V_56 ;
} else {
F_14 ( L_3 , V_39 , V_40 ) ;
* V_36 = V_39 & 0x7f ;
return 0 ;
}
}
void F_15 ( unsigned char V_39 )
{
F_3 ( V_8 ) ;
F_16 ( V_57 ) ;
if ( V_39 == 0x0a ) {
V_58 = 0x0d ;
F_16 ( V_57 ) ;
}
V_58 = V_39 ;
F_2 ( V_8 ) ;
}
void F_17 ( void )
{
F_16 ( V_59 ) ;
F_16 ( V_57 ) ;
F_2 ( V_8 ) ;
}
