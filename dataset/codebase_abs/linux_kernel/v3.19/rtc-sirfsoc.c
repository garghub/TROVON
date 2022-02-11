static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 , V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_6 = F_4 ( V_8 -> V_10 + V_11 ) ;
V_5 = F_4 ( V_8 -> V_10 + V_12 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_6 > V_5 )
F_5 ( ( V_8 -> V_13 + 1 )
<< ( V_14 - V_15 )
| V_5 >> V_15 , & ( V_4 -> time ) ) ;
else
F_5 ( V_8 -> V_13
<< ( V_14 - V_15 )
| V_5 >> V_15 , & ( V_4 -> time ) ) ;
if ( F_4 (
V_8 -> V_10 + V_16 ) & V_17 )
V_4 -> V_18 = 1 ;
F_6 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_19 , V_5 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_4 -> V_18 ) {
F_8 ( & ( V_4 -> time ) , & V_5 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_19 = F_4 (
V_8 -> V_10 + V_16 ) ;
if ( V_19 & V_17 ) {
F_9 ( V_2 , L_1 ) ;
}
F_10 (
V_5 << V_15 , V_8 -> V_10 + V_12 ) ;
V_19 &= ~ 0x07 ;
V_19 |= V_20 ;
V_19 |= V_17 ;
F_10 (
V_19 , V_8 -> V_10 + V_16 ) ;
F_6 ( & V_8 -> V_9 ) ;
} else {
F_3 ( & V_8 -> V_9 ) ;
V_19 = F_4 (
V_8 -> V_10 + V_16 ) ;
if ( V_19 & V_17 ) {
V_19 &= ~ 0x07 ;
V_19 |= ( V_20 ) ;
V_19 &= ~ ( V_17 ) ;
F_10 ( V_19 ,
V_8 -> V_10 + V_16 ) ;
}
F_6 ( & V_8 -> V_9 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
unsigned long V_23 = 0 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
do {
V_23 = F_4 ( V_8 -> V_10 + V_11 ) ;
F_12 () ;
} while ( V_23 != F_4 ( V_8 -> V_10 + V_11 ) );
F_5 ( V_8 -> V_13 << ( V_14 - V_15 ) |
V_23 >> V_15 , V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
unsigned long V_21 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
F_8 ( V_22 , & V_21 ) ;
V_8 -> V_13 = V_21 >> ( V_14 - V_15 ) ;
F_10 ( V_8 -> V_13 ,
V_8 -> V_10 + V_24 ) ;
F_10 (
V_21 << V_15 , V_8 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_25 ,
unsigned long V_26 )
{
switch ( V_25 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return 0 ;
default:
return - V_33 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
unsigned long V_19 = 0x0 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_19 = F_4 (
V_8 -> V_10 + V_16 ) ;
if ( V_18 )
V_19 |= V_17 ;
else
V_19 &= ~ V_17 ;
F_10 ( V_19 , V_8 -> V_10 + V_16 ) ;
F_6 ( & V_8 -> V_9 ) ;
return 0 ;
}
static T_1 F_16 ( int V_34 , void * V_35 )
{
struct V_7 * V_8 = V_35 ;
unsigned long V_19 = 0x0 ;
unsigned long V_36 = 0x0 ;
F_17 ( & V_8 -> V_9 ) ;
V_19 = F_4 ( V_8 -> V_10 + V_16 ) ;
if ( V_19 & V_20 ) {
V_19 &= ~ 0x07 ;
V_19 |= ( V_20 ) ;
V_19 &= ~ ( V_17 ) ;
}
F_10 ( V_19 , V_8 -> V_10 + V_16 ) ;
F_18 ( & V_8 -> V_9 ) ;
V_36 |= V_37 | V_38 ;
F_19 ( V_8 -> V_39 , 1 , V_36 ) ;
return V_40 ;
}
static int F_20 ( struct V_41 * V_42 )
{
int V_43 ;
unsigned long V_44 ;
struct V_7 * V_8 ;
struct V_45 * V_46 = V_42 -> V_2 . V_47 ;
V_8 = F_21 ( & V_42 -> V_2 ,
sizeof( struct V_7 ) , V_48 ) ;
if ( V_8 == NULL )
return - V_49 ;
F_22 ( & V_8 -> V_9 ) ;
V_43 = F_23 ( V_46 , L_2 , & V_8 -> V_10 ) ;
if ( V_43 ) {
F_24 ( & V_42 -> V_2 , L_3 ) ;
return V_43 ;
}
F_25 ( V_42 , V_8 ) ;
F_26 ( & V_42 -> V_2 , 1 ) ;
V_44 = ( ( 32768 / V_50 ) / 2 ) - 1 ;
F_10 ( V_44 , V_8 -> V_10 + V_51 ) ;
F_10 ( V_52 ,
V_8 -> V_10 + V_53 ) ;
F_10 ( 0x0 , V_8 -> V_10 + V_12 ) ;
F_10 ( 0x0 , V_8 -> V_10 + V_54 ) ;
V_8 -> V_13 =
F_4 ( V_8 -> V_10 + V_24 ) ;
V_8 -> V_39 = F_27 ( & V_42 -> V_2 , V_42 -> V_55 ,
& V_56 , V_57 ) ;
if ( F_28 ( V_8 -> V_39 ) ) {
V_43 = F_29 ( V_8 -> V_39 ) ;
F_24 ( & V_42 -> V_2 , L_4 ) ;
return V_43 ;
}
V_8 -> V_34 = F_30 ( V_42 , 0 ) ;
V_43 = F_31 (
& V_42 -> V_2 ,
V_8 -> V_34 ,
F_16 ,
V_58 ,
V_42 -> V_55 ,
V_8 ) ;
if ( V_43 ) {
F_24 ( & V_42 -> V_2 , L_5 ) ;
return V_43 ;
}
return 0 ;
}
static int F_32 ( struct V_41 * V_42 )
{
F_26 ( & V_42 -> V_2 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_13 =
F_4 ( V_8 -> V_10 + V_24 ) ;
V_8 -> V_59 =
F_4 ( V_8 -> V_10 + V_11 ) ;
V_8 -> V_60 = V_8 -> V_13 ;
if ( F_34 ( V_2 ) && ! F_35 ( V_8 -> V_34 ) )
V_8 -> V_61 = 1 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_2 V_62 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_52 != F_4 (
V_8 -> V_10 + V_53 ) ) {
T_2 V_44 ;
F_10 ( V_52 ,
V_8 -> V_10 + V_53 ) ;
V_44 = ( ( 32768 / V_50 ) / 2 ) - 1 ;
F_10 ( V_44 , V_8 -> V_10 + V_51 ) ;
F_10 ( 0x0 , V_8 -> V_10 + V_12 ) ;
F_10 ( 0x0 , V_8 -> V_10 + V_54 ) ;
}
V_8 -> V_13 = V_8 -> V_60 ;
V_62 = F_4 ( V_8 -> V_10 + V_11 ) ;
if ( V_62 <= V_8 -> V_59 )
V_8 -> V_13 ++ ;
F_10 ( V_8 -> V_13 ,
V_8 -> V_10 + V_24 ) ;
if ( F_34 ( V_2 ) && V_8 -> V_61 ) {
F_37 ( V_8 -> V_34 ) ;
V_8 -> V_61 = 0 ;
}
return 0 ;
}
