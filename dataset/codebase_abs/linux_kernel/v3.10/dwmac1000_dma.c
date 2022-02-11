static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 , T_2 V_6 , T_2 V_7 , int V_8 )
{
T_2 V_9 = F_2 ( V_1 + V_10 ) ;
int V_11 ;
V_9 |= V_12 ;
F_3 ( V_9 , V_1 + V_10 ) ;
V_11 = 10 ;
while ( V_11 -- ) {
if ( ! ( F_2 ( V_1 + V_10 ) & V_12 ) )
break;
F_4 ( 10 ) ;
}
if ( V_11 < 0 )
return - V_13 ;
V_9 = V_14 | ( ( V_2 << V_15 ) |
( V_2 << V_16 ) ) ;
if ( V_3 )
V_9 |= V_17 ;
if ( V_4 )
V_9 |= V_18 ;
#ifdef F_5
V_9 |= V_19 ;
#endif
if ( V_8 )
V_9 |= V_20 ;
F_3 ( V_9 , V_1 + V_10 ) ;
F_3 ( V_5 , V_1 + V_21 ) ;
F_3 ( V_22 , V_1 + V_23 ) ;
F_3 ( V_6 , V_1 + V_24 ) ;
F_3 ( V_7 , V_1 + V_25 ) ;
return 0 ;
}
static void F_6 ( void T_1 * V_1 , int V_26 ,
int V_27 )
{
T_2 V_28 = F_2 ( V_1 + V_29 ) ;
if ( V_26 == V_30 ) {
F_7 ( V_31 L_1 ) ;
V_28 |= V_32 ;
V_28 |= V_33 ;
} else {
F_7 ( V_31 L_2 ,
V_26 ) ;
V_28 &= ~ V_32 ;
V_28 &= V_34 ;
if ( V_26 <= 32 )
V_28 |= V_35 ;
else if ( V_26 <= 64 )
V_28 |= V_36 ;
else if ( V_26 <= 128 )
V_28 |= V_37 ;
else if ( V_26 <= 192 )
V_28 |= V_38 ;
else
V_28 |= V_39 ;
}
if ( V_27 == V_30 ) {
F_7 ( V_31 L_3 ) ;
V_28 |= V_40 ;
} else {
F_7 ( V_31 L_4 ,
V_27 ) ;
V_28 &= ~ V_40 ;
V_28 &= V_41 ;
if ( V_27 <= 32 )
V_28 |= V_42 ;
else if ( V_27 <= 64 )
V_28 |= V_43 ;
else if ( V_27 <= 96 )
V_28 |= V_44 ;
else
V_28 |= V_45 ;
}
F_3 ( V_28 , V_1 + V_29 ) ;
}
static void F_8 ( void T_1 * V_1 )
{
int V_46 ;
F_9 ( L_5 ) ;
for ( V_46 = 0 ; V_46 < 22 ; V_46 ++ ) {
if ( ( V_46 < 9 ) || ( V_46 > 17 ) ) {
int V_47 = V_46 * 4 ;
F_10 ( L_6 , V_46 ,
( V_10 + V_47 ) ,
F_2 ( V_1 + V_10 + V_47 ) ) ;
}
}
}
static unsigned int F_11 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_48 ) ;
}
static void F_12 ( void T_1 * V_1 , T_2 V_49 )
{
F_3 ( V_49 , V_1 + V_50 ) ;
}
