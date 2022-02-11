static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , & V_4 ) ;
return V_4 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_4 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_11 , V_12 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_8 ) ;
F_7 ( & V_2 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_14 ) ;
V_11 = F_1 ( V_2 , V_15 ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
if ( V_12 > V_11 )
F_8 ( ( V_2 -> V_16 + 1 )
<< ( V_17 - V_18 )
| V_11 >> V_18 , & ( V_10 -> time ) ) ;
else
F_8 ( V_2 -> V_16
<< ( V_17 - V_18 )
| V_11 >> V_18 , & ( V_10 -> time ) ) ;
if ( F_1 ( V_2 , V_19 ) & V_20 )
V_10 -> V_21 = 1 ;
F_9 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_22 , V_11 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_8 ) ;
if ( V_10 -> V_21 ) {
F_11 ( & ( V_10 -> time ) , & V_11 ) ;
F_7 ( & V_2 -> V_13 ) ;
V_22 = F_1 ( V_2 , V_19 ) ;
if ( V_22 & V_20 ) {
F_12 ( V_8 , L_1 ) ;
}
F_3 ( V_2 , V_15 , V_11 << V_18 ) ;
V_22 &= ~ 0x07 ;
V_22 |= V_23 ;
V_22 |= V_20 ;
F_3 ( V_2 , V_19 , V_22 ) ;
F_9 ( & V_2 -> V_13 ) ;
} else {
F_7 ( & V_2 -> V_13 ) ;
V_22 = F_1 ( V_2 , V_19 ) ;
if ( V_22 & V_20 ) {
V_22 &= ~ 0x07 ;
V_22 |= ( V_23 ) ;
V_22 &= ~ ( V_20 ) ;
F_3 ( V_2 , V_19 ,
V_22 ) ;
}
F_9 ( & V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
unsigned long V_26 = 0 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_8 ) ;
do {
V_26 = F_1 ( V_2 , V_14 ) ;
F_14 () ;
} while ( V_26 != F_1 ( V_2 , V_14 ) );
F_8 ( V_2 -> V_16 << ( V_17 - V_18 ) |
V_26 >> V_18 , V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
unsigned long V_24 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_8 ) ;
F_11 ( V_25 , & V_24 ) ;
V_2 -> V_16 = V_24 >> ( V_17 - V_18 ) ;
F_3 ( V_2 , V_27 , V_2 -> V_16 ) ;
F_3 ( V_2 , V_14 , V_24 << V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , unsigned int V_28 ,
unsigned long V_29 )
{
switch ( V_28 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return 0 ;
default:
return - V_36 ;
}
}
static int F_17 ( struct V_7 * V_8 ,
unsigned int V_21 )
{
unsigned long V_22 = 0x0 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_8 ) ;
F_7 ( & V_2 -> V_13 ) ;
V_22 = F_1 ( V_2 , V_19 ) ;
if ( V_21 )
V_22 |= V_20 ;
else
V_22 &= ~ V_20 ;
F_3 ( V_2 , V_19 , V_22 ) ;
F_9 ( & V_2 -> V_13 ) ;
return 0 ;
}
static T_2 F_18 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
unsigned long V_22 = 0x0 ;
unsigned long V_39 = 0x0 ;
F_19 ( & V_2 -> V_13 ) ;
V_22 = F_1 ( V_2 , V_19 ) ;
if ( V_22 & V_23 ) {
V_22 &= ~ 0x07 ;
V_22 |= ( V_23 ) ;
V_22 &= ~ ( V_20 ) ;
}
F_3 ( V_2 , V_19 , V_22 ) ;
F_20 ( & V_2 -> V_13 ) ;
V_39 |= V_40 | V_41 ;
F_21 ( V_2 -> V_42 , 1 , V_39 ) ;
return V_43 ;
}
static int F_22 ( struct V_44 * V_45 )
{
int V_46 ;
unsigned long V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 = V_45 -> V_8 . V_50 ;
V_2 = F_23 ( & V_45 -> V_8 ,
sizeof( struct V_1 ) , V_51 ) ;
if ( V_2 == NULL )
return - V_52 ;
F_24 ( & V_2 -> V_13 ) ;
V_46 = F_25 ( V_49 , L_2 , & V_2 -> V_6 ) ;
if ( V_46 ) {
F_26 ( & V_45 -> V_8 , L_3 ) ;
return V_46 ;
}
F_27 ( V_45 , V_2 ) ;
F_28 ( & V_45 -> V_8 , 1 ) ;
V_2 -> V_5 = F_29 ( & V_45 -> V_8 ,
& V_53 ) ;
if ( F_30 ( V_2 -> V_5 ) ) {
V_46 = F_31 ( V_2 -> V_5 ) ;
F_26 ( & V_45 -> V_8 , L_4 ,
V_46 ) ;
return V_46 ;
}
V_47 = ( ( 32768 / V_54 ) / 2 ) - 1 ;
F_3 ( V_2 , V_55 , V_47 ) ;
F_3 ( V_2 , V_56 , V_57 ) ;
F_3 ( V_2 , V_15 , 0x0 ) ;
F_3 ( V_2 , V_58 , 0x0 ) ;
V_2 -> V_16 =
F_1 ( V_2 , V_27 ) ;
V_2 -> V_42 = F_32 ( & V_45 -> V_8 , V_45 -> V_59 ,
& V_60 , V_61 ) ;
if ( F_30 ( V_2 -> V_42 ) ) {
V_46 = F_31 ( V_2 -> V_42 ) ;
F_26 ( & V_45 -> V_8 , L_5 ) ;
return V_46 ;
}
V_2 -> V_37 = F_33 ( V_45 , 0 ) ;
V_46 = F_34 (
& V_45 -> V_8 ,
V_2 -> V_37 ,
F_18 ,
V_62 ,
V_45 -> V_59 ,
V_2 ) ;
if ( V_46 ) {
F_26 ( & V_45 -> V_8 , L_6 ) ;
return V_46 ;
}
return 0 ;
}
static int F_35 ( struct V_44 * V_45 )
{
F_28 ( & V_45 -> V_8 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
V_2 -> V_16 =
F_1 ( V_2 , V_27 ) ;
V_2 -> V_63 =
F_1 ( V_2 , V_14 ) ;
V_2 -> V_64 = V_2 -> V_16 ;
if ( F_37 ( V_8 ) && ! F_38 ( V_2 -> V_37 ) )
V_2 -> V_65 = 1 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 )
{
T_1 V_66 ;
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( V_57 != F_1 ( V_2 , V_56 ) ) {
T_1 V_47 ;
F_3 ( V_2 , V_56 , V_57 ) ;
V_47 = ( ( 32768 / V_54 ) / 2 ) - 1 ;
F_3 ( V_2 , V_55 , V_47 ) ;
F_3 ( V_2 , V_15 , 0x0 ) ;
F_3 ( V_2 , V_58 , 0x0 ) ;
}
V_2 -> V_16 = V_2 -> V_64 ;
V_66 = F_1 ( V_2 , V_14 ) ;
if ( V_66 <= V_2 -> V_63 )
V_2 -> V_16 ++ ;
F_3 ( V_2 , V_27 , V_2 -> V_16 ) ;
if ( F_37 ( V_8 ) && V_2 -> V_65 ) {
F_40 ( V_2 -> V_37 ) ;
V_2 -> V_65 = 0 ;
}
return 0 ;
}
