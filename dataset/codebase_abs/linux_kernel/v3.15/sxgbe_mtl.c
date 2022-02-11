static void F_1 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_5 ) ;
V_4 &= V_6 ;
switch ( V_2 & V_7 ) {
case V_8 :
V_4 &= V_8 ;
break;
case V_9 :
V_4 |= V_9 ;
break;
case V_10 :
V_4 |= V_10 ;
break;
}
F_3 ( V_4 , V_1 + V_5 ) ;
switch ( V_3 & V_11 ) {
case V_12 :
V_4 &= V_12 ;
break;
case V_13 :
V_4 |= V_13 ;
break;
}
F_3 ( V_4 , V_1 + V_5 ) ;
}
static void F_4 ( void T_1 * V_1 )
{
F_3 ( V_14 , V_1 + V_15 ) ;
F_3 ( V_14 , V_1 + V_16 ) ;
F_3 ( V_14 , V_1 + V_17 ) ;
}
static void F_5 ( void T_1 * V_1 , int V_18 ,
int V_19 )
{
T_2 V_20 , V_4 ;
V_20 = ( V_19 / V_21 ) - 1 ;
V_4 = F_2 ( V_1 + F_6 ( V_18 ) ) ;
V_4 |= ( V_20 << V_22 ) ;
F_3 ( V_4 , V_1 + F_6 ( V_18 ) ) ;
}
static void F_7 ( void T_1 * V_1 , int V_18 ,
int V_19 )
{
T_2 V_20 , V_4 ;
V_20 = ( V_19 / V_23 ) - 1 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 |= ( V_20 << V_22 ) ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_9 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_6 ( V_18 ) ) ;
V_4 |= V_24 ;
F_3 ( V_4 , V_1 + F_6 ( V_18 ) ) ;
}
static void F_10 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_6 ( V_18 ) ) ;
V_4 &= ~ V_24 ;
F_3 ( V_4 , V_1 + F_6 ( V_18 ) ) ;
}
static void F_11 ( void T_1 * V_1 , int V_18 ,
int V_25 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 &= ~ ( V_26 << V_27 ) ;
V_4 |= ( V_25 << V_27 ) ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_12 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 |= V_28 ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_13 ( void T_1 * V_1 , int V_18 ,
int V_25 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 &= ~ ( V_26 << V_29 ) ;
V_4 |= ( V_25 << V_29 ) ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_14 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 |= V_30 ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_15 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 &= ~ ( V_30 ) ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_16 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 |= V_31 ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_17 ( void T_1 * V_1 , int V_18 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
V_4 &= ~ ( V_31 ) ;
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
static void F_18 ( void T_1 * V_1 , int V_18 ,
int V_32 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_6 ( V_18 ) ) ;
if ( V_32 == V_33 ) {
V_4 |= V_33 ;
} else {
if ( V_32 <= 64 )
V_4 |= V_34 ;
else if ( V_32 <= 96 )
V_4 |= V_35 ;
else if ( V_32 <= 128 )
V_4 |= V_36 ;
else if ( V_32 <= 192 )
V_4 |= V_37 ;
else if ( V_32 <= 256 )
V_4 |= V_38 ;
else if ( V_32 <= 384 )
V_4 |= V_39 ;
else
V_4 |= V_40 ;
}
F_3 ( V_4 , V_1 + F_6 ( V_18 ) ) ;
}
static void F_19 ( void T_1 * V_1 , int V_18 ,
int V_41 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + F_8 ( V_18 ) ) ;
if ( V_41 == V_42 ) {
V_4 |= V_42 ;
} else {
if ( V_41 <= 64 )
V_4 |= V_43 ;
else if ( V_41 <= 96 )
V_4 |= V_44 ;
else if ( V_41 <= 128 )
V_4 |= V_45 ;
}
F_3 ( V_4 , V_1 + F_8 ( V_18 ) ) ;
}
const struct V_46 * F_20 ( void )
{
return & V_47 ;
}
