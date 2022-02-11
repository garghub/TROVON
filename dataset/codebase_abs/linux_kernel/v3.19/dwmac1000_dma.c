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
if ( V_8 )
V_9 |= V_19 ;
F_3 ( V_9 , V_1 + V_10 ) ;
F_3 ( V_5 , V_1 + V_20 ) ;
F_3 ( V_21 , V_1 + V_22 ) ;
F_3 ( V_6 , V_1 + V_23 ) ;
F_3 ( V_7 , V_1 + V_24 ) ;
return 0 ;
}
static void F_5 ( void T_1 * V_1 , int V_25 ,
int V_26 )
{
T_2 V_27 = F_2 ( V_1 + V_28 ) ;
if ( V_25 == V_29 ) {
F_6 ( L_1 ) ;
V_27 |= V_30 ;
V_27 |= V_31 ;
} else {
F_6 ( L_2 , V_25 ) ;
V_27 &= ~ V_30 ;
V_27 &= V_32 ;
if ( V_25 <= 32 )
V_27 |= V_33 ;
else if ( V_25 <= 64 )
V_27 |= V_34 ;
else if ( V_25 <= 128 )
V_27 |= V_35 ;
else if ( V_25 <= 192 )
V_27 |= V_36 ;
else
V_27 |= V_37 ;
}
if ( V_26 == V_29 ) {
F_6 ( L_3 ) ;
V_27 |= V_38 ;
} else {
F_6 ( L_4 , V_26 ) ;
V_27 &= ~ V_38 ;
V_27 &= V_39 ;
if ( V_26 <= 32 )
V_27 |= V_40 ;
else if ( V_26 <= 64 )
V_27 |= V_41 ;
else if ( V_26 <= 96 )
V_27 |= V_42 ;
else
V_27 |= V_43 ;
}
F_3 ( V_27 , V_1 + V_28 ) ;
}
static void F_7 ( void T_1 * V_1 )
{
int V_44 ;
F_8 ( L_5 ) ;
for ( V_44 = 0 ; V_44 < 22 ; V_44 ++ ) {
if ( ( V_44 < 9 ) || ( V_44 > 17 ) ) {
int V_45 = V_44 * 4 ;
F_9 ( L_6 , V_44 ,
( V_10 + V_45 ) ,
F_2 ( V_1 + V_10 + V_45 ) ) ;
}
}
}
static unsigned int F_10 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_46 ) ;
}
static void F_11 ( void T_1 * V_1 , T_2 V_47 )
{
F_3 ( V_47 , V_1 + V_48 ) ;
}
