static int F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 ,
T_2 V_4 )
{
T_2 V_5 = F_2 ( V_1 + V_6 ) ;
int V_7 ;
V_5 |= V_8 ;
F_3 ( V_5 , V_1 + V_6 ) ;
V_7 = 15000 ;
while ( V_7 -- ) {
if ( ! ( F_2 ( V_1 + V_6 ) & V_8 ) )
break;
}
if ( V_7 < 0 )
return - V_9 ;
V_5 = V_10 |
( ( V_2 << V_11 ) |
( V_2 << V_12 ) ) ;
#ifdef F_4
V_5 |= V_13 ;
#endif
F_3 ( V_5 , V_1 + V_6 ) ;
F_3 ( V_14 , V_1 + V_15 ) ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_3 ( V_4 , V_1 + V_17 ) ;
return 0 ;
}
static void F_5 ( void T_1 * V_1 , int V_18 ,
int V_19 )
{
T_2 V_20 = F_2 ( V_1 + V_21 ) ;
if ( V_18 == V_22 ) {
F_6 ( V_23 L_1 ) ;
V_20 |= V_24 ;
V_20 |= V_25 ;
} else {
F_6 ( V_23 L_2
L_3 , V_18 ) ;
V_20 &= ~ V_24 ;
V_20 &= V_26 ;
if ( V_18 <= 32 )
V_20 |= V_27 ;
else if ( V_18 <= 64 )
V_20 |= V_28 ;
else if ( V_18 <= 128 )
V_20 |= V_29 ;
else if ( V_18 <= 192 )
V_20 |= V_30 ;
else
V_20 |= V_31 ;
}
if ( V_19 == V_22 ) {
F_6 ( V_23 L_4 ) ;
V_20 |= V_32 ;
} else {
F_6 ( V_23 L_5
L_3 , V_19 ) ;
V_20 &= ~ V_32 ;
V_20 &= V_33 ;
if ( V_19 <= 32 )
V_20 |= V_34 ;
else if ( V_19 <= 64 )
V_20 |= V_35 ;
else if ( V_19 <= 96 )
V_20 |= V_36 ;
else
V_20 |= V_37 ;
}
F_3 ( V_20 , V_1 + V_21 ) ;
}
static void F_7 ( void * V_38 ,
struct V_39 * V_40 , void T_1 * V_1 )
{
return;
}
static void F_8 ( void T_1 * V_1 )
{
int V_41 ;
F_9 ( L_6 ) ;
for ( V_41 = 0 ; V_41 < 22 ; V_41 ++ ) {
if ( ( V_41 < 9 ) || ( V_41 > 17 ) ) {
int V_42 = V_41 * 4 ;
F_10 ( L_7 , V_41 ,
( V_6 + V_42 ) ,
F_2 ( V_1 + V_6 + V_42 ) ) ;
}
}
}
