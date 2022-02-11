static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 ,
int V_4 , int V_5 , T_2 V_6 , T_2 V_7 )
{
T_2 V_8 = F_2 ( V_1 + V_9 ) ;
int V_10 ;
V_8 |= V_11 ;
F_3 ( V_8 , V_1 + V_9 ) ;
V_10 = 10 ;
while ( V_10 -- ) {
if ( ! ( F_2 ( V_1 + V_9 ) & V_11 ) )
break;
F_4 ( 10 ) ;
}
if ( V_10 < 0 )
return - V_12 ;
V_8 = V_13 | ( ( V_2 << V_14 ) |
( V_2 << V_15 ) ) ;
if ( V_3 )
V_8 |= V_16 ;
if ( V_4 )
V_8 |= V_17 ;
#ifdef F_5
V_8 |= V_18 ;
#endif
F_3 ( V_8 , V_1 + V_9 ) ;
F_3 ( V_5 , V_1 + V_19 ) ;
F_3 ( V_20 , V_1 + V_21 ) ;
F_3 ( V_6 , V_1 + V_22 ) ;
F_3 ( V_7 , V_1 + V_23 ) ;
return 0 ;
}
static void F_6 ( void T_1 * V_1 , int V_24 ,
int V_25 )
{
T_2 V_26 = F_2 ( V_1 + V_27 ) ;
if ( V_24 == V_28 ) {
F_7 ( V_29 L_1 ) ;
V_26 |= V_30 ;
V_26 |= V_31 ;
} else {
F_7 ( V_29 L_2
L_3 , V_24 ) ;
V_26 &= ~ V_30 ;
V_26 &= V_32 ;
if ( V_24 <= 32 )
V_26 |= V_33 ;
else if ( V_24 <= 64 )
V_26 |= V_34 ;
else if ( V_24 <= 128 )
V_26 |= V_35 ;
else if ( V_24 <= 192 )
V_26 |= V_36 ;
else
V_26 |= V_37 ;
}
if ( V_25 == V_28 ) {
F_7 ( V_29 L_4 ) ;
V_26 |= V_38 ;
} else {
F_7 ( V_29 L_5
L_3 , V_25 ) ;
V_26 &= ~ V_38 ;
V_26 &= V_39 ;
if ( V_25 <= 32 )
V_26 |= V_40 ;
else if ( V_25 <= 64 )
V_26 |= V_41 ;
else if ( V_25 <= 96 )
V_26 |= V_42 ;
else
V_26 |= V_43 ;
}
F_3 ( V_26 , V_1 + V_27 ) ;
}
static void F_8 ( void T_1 * V_1 )
{
int V_44 ;
F_9 ( L_6 ) ;
for ( V_44 = 0 ; V_44 < 22 ; V_44 ++ ) {
if ( ( V_44 < 9 ) || ( V_44 > 17 ) ) {
int V_45 = V_44 * 4 ;
F_10 ( L_7 , V_44 ,
( V_9 + V_45 ) ,
F_2 ( V_1 + V_9 + V_45 ) ) ;
}
}
}
static unsigned int F_11 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_46 ) ;
}
static void F_12 ( void T_1 * V_1 , T_2 V_47 )
{
F_3 ( V_47 , V_1 + V_48 ) ;
}
