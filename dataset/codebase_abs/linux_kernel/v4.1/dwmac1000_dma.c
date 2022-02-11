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
static T_2 F_5 ( T_2 V_25 , int V_26 )
{
V_25 &= ~ V_27 ;
V_25 &= ~ V_28 ;
if ( V_26 < 4096 ) {
V_25 &= ~ V_29 ;
F_6 ( L_1 ,
V_26 ) ;
} else {
V_25 |= V_29 ;
V_25 |= V_30 ;
V_25 |= V_31 ;
}
return V_25 ;
}
static void F_7 ( void T_1 * V_1 , int V_32 ,
int V_33 , int V_26 )
{
T_2 V_25 = F_2 ( V_1 + V_34 ) ;
if ( V_32 == V_35 ) {
F_6 ( L_2 ) ;
V_25 |= V_36 ;
V_25 |= V_37 ;
} else {
F_6 ( L_3 , V_32 ) ;
V_25 &= ~ V_36 ;
V_25 &= V_38 ;
if ( V_32 <= 32 )
V_25 |= V_39 ;
else if ( V_32 <= 64 )
V_25 |= V_40 ;
else if ( V_32 <= 128 )
V_25 |= V_41 ;
else if ( V_32 <= 192 )
V_25 |= V_42 ;
else
V_25 |= V_43 ;
}
if ( V_33 == V_35 ) {
F_6 ( L_4 ) ;
V_25 |= V_44 ;
} else {
F_6 ( L_5 , V_33 ) ;
V_25 &= ~ V_44 ;
V_25 &= V_45 ;
if ( V_33 <= 32 )
V_25 |= V_46 ;
else if ( V_33 <= 64 )
V_25 |= V_47 ;
else if ( V_33 <= 96 )
V_25 |= V_48 ;
else
V_25 |= V_49 ;
}
V_25 = F_5 ( V_25 , V_26 ) ;
F_3 ( V_25 , V_1 + V_34 ) ;
}
static void F_8 ( void T_1 * V_1 )
{
int V_50 ;
F_9 ( L_6 ) ;
for ( V_50 = 0 ; V_50 < 22 ; V_50 ++ ) {
if ( ( V_50 < 9 ) || ( V_50 > 17 ) ) {
int V_51 = V_50 * 4 ;
F_10 ( L_7 , V_50 ,
( V_10 + V_51 ) ,
F_2 ( V_1 + V_10 + V_51 ) ) ;
}
}
}
static unsigned int F_11 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_52 ) ;
}
static void F_12 ( void T_1 * V_1 , T_2 V_53 )
{
F_3 ( V_53 , V_1 + V_54 ) ;
}
