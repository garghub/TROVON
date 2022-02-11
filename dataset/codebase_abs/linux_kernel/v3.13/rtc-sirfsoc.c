static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 , V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
F_3 () ;
V_6 = F_4 ( V_8 -> V_9 + V_10 ) ;
V_5 = F_4 ( V_8 -> V_9 + V_11 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_6 > V_5 )
F_5 ( ( V_8 -> V_12 + 1 )
<< ( V_13 - V_14 )
| V_5 >> V_14 , & ( V_4 -> time ) ) ;
else
F_5 ( V_8 -> V_12
<< ( V_13 - V_14 )
| V_5 >> V_14 , & ( V_4 -> time ) ) ;
if ( F_4 (
V_8 -> V_9 + V_15 ) & V_16 )
V_4 -> V_17 = 1 ;
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_18 , V_5 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_4 -> V_17 ) {
F_8 ( & ( V_4 -> time ) , & V_5 ) ;
F_3 () ;
V_18 = F_4 (
V_8 -> V_9 + V_15 ) ;
if ( V_18 & V_16 ) {
F_9 ( V_2 , L_1 ) ;
}
F_10 (
V_5 << V_14 , V_8 -> V_9 + V_11 ) ;
V_18 &= ~ 0x07 ;
V_18 |= V_19 ;
V_18 |= V_16 ;
F_10 (
V_18 , V_8 -> V_9 + V_15 ) ;
F_6 () ;
} else {
F_3 () ;
V_18 = F_4 (
V_8 -> V_9 + V_15 ) ;
if ( V_18 & V_16 ) {
V_18 &= ~ 0x07 ;
V_18 |= ( V_19 ) ;
V_18 &= ~ ( V_16 ) ;
F_10 ( V_18 ,
V_8 -> V_9 + V_15 ) ;
}
F_6 () ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned long V_22 = 0 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
do {
V_22 = F_4 ( V_8 -> V_9 + V_10 ) ;
F_12 () ;
} while ( V_22 != F_4 ( V_8 -> V_9 + V_10 ) );
F_5 ( V_8 -> V_12 << ( V_13 - V_14 ) |
V_22 >> V_14 , V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned long V_20 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
F_8 ( V_21 , & V_20 ) ;
V_8 -> V_12 = V_20 >> ( V_13 - V_14 ) ;
F_10 ( V_8 -> V_12 ,
V_8 -> V_9 + V_23 ) ;
F_10 (
V_20 << V_14 , V_8 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_24 ,
unsigned long V_25 )
{
switch ( V_24 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
return 0 ;
default:
return - V_32 ;
}
}
static T_1 F_15 ( int V_33 , void * V_34 )
{
struct V_7 * V_8 = V_34 ;
unsigned long V_18 = 0x0 ;
unsigned long V_35 = 0x0 ;
V_18 = F_4 ( V_8 -> V_9 + V_15 ) ;
if ( V_18 & V_19 ) {
V_18 &= ~ 0x07 ;
V_18 |= ( V_19 ) ;
V_18 &= ~ ( V_16 ) ;
}
F_10 ( V_18 , V_8 -> V_9 + V_15 ) ;
V_35 |= V_36 | V_37 ;
F_16 ( V_8 -> V_38 , 1 , V_35 ) ;
return V_39 ;
}
static int F_17 ( struct V_40 * V_41 )
{
int V_42 ;
unsigned long V_43 ;
struct V_7 * V_8 ;
struct V_44 * V_45 = V_41 -> V_2 . V_46 ;
V_8 = F_18 ( & V_41 -> V_2 ,
sizeof( struct V_7 ) , V_47 ) ;
if ( V_8 == NULL ) {
F_19 ( & V_41 -> V_2 ,
L_2 ,
V_41 -> V_48 ) ;
return - V_49 ;
}
V_42 = F_20 ( V_45 , L_3 , & V_8 -> V_9 ) ;
if ( V_42 ) {
F_19 ( & V_41 -> V_2 , L_4 ) ;
return V_42 ;
}
F_21 ( V_41 , V_8 ) ;
F_22 ( & V_41 -> V_2 , 1 ) ;
V_43 = ( ( 32768 / V_50 ) / 2 ) - 1 ;
F_10 ( V_43 , V_8 -> V_9 + V_51 ) ;
V_8 -> V_38 = F_23 ( & V_41 -> V_2 , V_41 -> V_48 ,
& V_52 , V_53 ) ;
if ( F_24 ( V_8 -> V_38 ) ) {
V_42 = F_25 ( V_8 -> V_38 ) ;
F_19 ( & V_41 -> V_2 , L_5 ) ;
return V_42 ;
}
F_10 ( V_54 ,
V_8 -> V_9 + V_55 ) ;
F_10 ( 0x0 , V_8 -> V_9 + V_11 ) ;
F_10 ( 0x0 , V_8 -> V_9 + V_56 ) ;
V_8 -> V_12 =
F_4 ( V_8 -> V_9 + V_23 ) ;
V_8 -> V_33 = F_26 ( V_41 , 0 ) ;
V_42 = F_27 (
& V_41 -> V_2 ,
V_8 -> V_33 ,
F_15 ,
V_57 ,
V_41 -> V_48 ,
V_8 ) ;
if ( V_42 ) {
F_19 ( & V_41 -> V_2 , L_6 ) ;
return V_42 ;
}
return 0 ;
}
static int F_28 ( struct V_40 * V_41 )
{
F_22 ( & V_41 -> V_2 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_30 ( V_2 ) ;
struct V_7 * V_8 = F_31 ( V_41 ) ;
V_8 -> V_12 =
F_4 ( V_8 -> V_9 + V_23 ) ;
V_8 -> V_58 =
F_4 ( V_8 -> V_9 + V_10 ) ;
V_8 -> V_59 = V_8 -> V_12 ;
if ( F_32 ( & V_41 -> V_2 ) && ! F_33 ( V_8 -> V_33 ) )
V_8 -> V_60 = 1 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_2 V_61 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_54 != F_4 (
V_8 -> V_9 + V_55 ) ) {
T_2 V_43 ;
F_10 ( V_54 ,
V_8 -> V_9 + V_55 ) ;
V_43 = ( ( 32768 / V_50 ) / 2 ) - 1 ;
F_10 ( V_43 , V_8 -> V_9 + V_51 ) ;
F_10 ( 0x0 , V_8 -> V_9 + V_11 ) ;
F_10 ( 0x0 , V_8 -> V_9 + V_56 ) ;
}
V_8 -> V_12 = V_8 -> V_59 ;
V_61 = F_4 ( V_8 -> V_9 + V_10 ) ;
if ( V_61 <= V_8 -> V_58 )
V_8 -> V_12 ++ ;
F_10 ( V_8 -> V_12 ,
V_8 -> V_9 + V_23 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_30 ( V_2 ) ;
struct V_7 * V_8 = F_31 ( V_41 ) ;
F_35 ( V_2 ) ;
if ( F_32 ( & V_41 -> V_2 ) && V_8 -> V_60 ) {
F_37 ( V_8 -> V_33 ) ;
V_8 -> V_60 = 0 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_30 ( V_2 ) ;
struct V_7 * V_8 = F_31 ( V_41 ) ;
if ( F_32 ( & V_41 -> V_2 ) && V_8 -> V_60 ) {
F_37 ( V_8 -> V_33 ) ;
V_8 -> V_60 = 0 ;
}
return 0 ;
}
