void F_1 ( void )
{
F_2 ( V_1 ) = V_2 ;
F_2 ( V_3 ) =
V_4 |
V_5 |
V_6 |
V_7 ;
F_3 ( V_8 ) ;
F_4 ( V_9 ) ;
F_2 ( V_10 ) = V_11 | V_12 ;
F_5 () ;
F_6 ( 6 , V_13 ) ;
}
void F_7 ( unsigned V_14 )
{
unsigned V_15 , V_16 , V_17 ;
T_1 V_18 ;
V_15 = V_19 / 16 / V_14 ;
V_16 = V_19 / 16 / V_15 ;
V_17 = V_19 / 16 / ( V_15 + 1 ) ;
if ( V_17 + ( V_16 - V_17 ) / 2 > V_14 )
V_15 ++ ;
V_18 = F_2 ( V_1 ) ;
F_2 ( V_1 ) |= V_20 ;
F_5 () ;
F_2 ( V_21 ) = V_15 & 0xff ;
F_2 ( V_22 ) = ( V_15 >> 8 ) & 0xff ;
F_5 () ;
F_2 ( V_1 ) = V_18 ;
F_5 () ;
}
void F_8 ( void )
{
unsigned V_23 , V_24 ;
V_23 = V_25 ;
while ( F_2 ( V_26 ) & V_27 ) {
V_24 = ( V_23 + 2 ) & 0xfff ;
if ( V_24 == V_28 )
break;
V_29 [ V_23 ++ ] = F_2 ( V_26 ) ;
V_29 [ V_23 ++ ] = F_2 ( V_30 ) ;
V_23 = V_24 ;
}
V_25 = V_23 ;
F_9 ( 15 ) ;
F_10 () ;
}
int F_11 ( unsigned char * V_31 , int V_32 )
{
unsigned V_23 ;
T_1 V_33 , V_34 ;
* V_31 = 0xff ;
if ( V_35 ) {
* V_31 = V_35 ;
V_35 = 0 ;
return 0 ;
}
V_36:
F_8 () ;
V_23 = V_28 ;
if ( V_23 == V_25 ) {
if ( V_32 )
return - V_37 ;
goto V_36;
}
V_34 = V_29 [ V_23 ++ ] ;
V_33 = V_29 [ V_23 ++ ] ;
V_28 = V_23 & 0x00000fff ;
if ( V_34 & V_38 ) {
F_12 ( L_1 ) ;
return - V_39 ;
}
else if ( V_34 & ( V_40 | V_41 | V_42 ) ) {
F_13 ( L_2 , V_34 ) ;
return - V_43 ;
}
else {
F_13 ( L_3 , V_33 , V_34 ) ;
* V_31 = V_33 & 0x7f ;
return 0 ;
}
}
void F_14 ( unsigned char V_33 )
{
F_4 ( V_8 ) ;
F_15 ( V_44 ) ;
if ( V_33 == 0x0a ) {
F_2 ( V_45 ) = 0x0d ;
F_5 () ;
F_15 ( V_44 ) ;
}
F_2 ( V_45 ) = V_33 ;
F_5 () ;
F_3 ( V_8 ) ;
}
void F_16 ( void )
{
F_15 ( V_46 ) ;
F_15 ( V_44 ) ;
F_3 ( V_8 ) ;
}
