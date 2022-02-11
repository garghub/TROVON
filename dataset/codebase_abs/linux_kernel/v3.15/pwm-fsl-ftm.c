static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_4 ( V_6 -> V_7 [ V_8 ] ) ;
}
static void F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_6 ( V_6 -> V_7 [ V_8 ] ) ;
}
static int F_7 ( struct V_1 * V_6 ,
enum V_9 V_10 )
{
unsigned long V_11 , V_12 ;
unsigned long long V_13 ;
V_11 = F_8 ( V_6 -> V_7 [ V_8 ] ) ;
if ( ! V_11 )
return - V_14 ;
V_12 = F_8 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
if ( ! V_12 )
return - V_14 ;
switch ( V_10 ) {
case V_8 :
V_6 -> V_16 = 1 ;
break;
case V_17 :
V_13 = 2 * V_12 - 1 ;
F_9 ( V_13 , V_11 ) ;
V_6 -> V_16 = V_13 ;
break;
case V_18 :
V_13 = 4 * V_12 - 1 ;
F_9 ( V_13 , V_11 ) ;
V_6 -> V_16 = V_13 ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static unsigned long F_10 ( struct V_1 * V_6 ,
unsigned long V_19 )
{
unsigned long long V_20 , V_21 ;
V_20 = F_8 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
V_20 = V_20 * V_19 ;
F_9 ( V_20 , 1000000000UL ) ;
do {
V_21 = V_20 ;
F_9 ( V_21 , ( 1 << V_6 -> V_16 ) ) ;
if ( V_21 <= 0xFFFF )
return ( unsigned long ) V_21 ;
} while ( ++ V_6 -> V_16 < 8 );
return 0 ;
}
static unsigned long F_11 ( struct V_1 * V_6 ,
unsigned long V_19 ,
enum V_9 V_10 )
{
int V_22 ;
V_22 = F_7 ( V_6 , V_10 ) ;
if ( V_22 ) {
F_12 ( V_6 -> V_3 . V_23 ,
L_1 ,
V_22 ) ;
return 0 ;
}
return F_10 ( V_6 , V_19 ) ;
}
static unsigned long F_13 ( struct V_1 * V_6 ,
unsigned long V_19 )
{
enum V_9 V_24 , V_25 ;
unsigned long V_26 , V_27 , V_28 ;
V_28 = F_11 ( V_6 , V_19 ,
V_8 ) ;
if ( V_28 ) {
V_6 -> V_15 = V_8 ;
return V_28 ;
}
V_26 = F_8 ( V_6 -> V_7 [ V_17 ] ) ;
V_27 = F_8 ( V_6 -> V_7 [ V_18 ] ) ;
if ( V_26 > V_27 ) {
V_24 = V_17 ;
V_25 = V_18 ;
} else {
V_24 = V_18 ;
V_25 = V_17 ;
}
V_28 = F_11 ( V_6 , V_19 , V_24 ) ;
if ( V_28 ) {
V_6 -> V_15 = V_24 ;
return V_28 ;
}
V_6 -> V_15 = V_25 ;
return F_11 ( V_6 , V_19 , V_25 ) ;
}
static unsigned long F_14 ( struct V_1 * V_6 ,
unsigned long V_19 ,
unsigned long V_29 )
{
unsigned long long V_30 , V_31 ;
V_30 = F_15 ( V_6 -> V_32 + V_33 ) ;
V_31 = V_29 * ( V_30 + 1 ) ;
F_9 ( V_31 , V_19 ) ;
return ( unsigned long ) V_31 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_29 , int V_19 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_30 , V_34 , V_31 ;
F_17 ( & V_6 -> V_35 ) ;
if ( V_6 -> V_19 && V_6 -> V_19 != V_19 ) {
F_12 ( V_6 -> V_3 . V_23 ,
L_2 ,
V_5 -> V_36 ) ;
F_18 ( & V_6 -> V_35 ) ;
return - V_37 ;
}
if ( ! V_6 -> V_19 && V_29 ) {
V_34 = F_13 ( V_6 , V_19 ) ;
if ( ! V_34 ) {
F_12 ( V_6 -> V_3 . V_23 , L_3 ) ;
F_18 ( & V_6 -> V_35 ) ;
return - V_14 ;
}
V_30 = F_15 ( V_6 -> V_32 + V_38 ) ;
V_30 &= ~ ( V_39 << V_40 ) ;
V_30 |= V_6 -> V_16 ;
F_19 ( V_30 , V_6 -> V_32 + V_38 ) ;
F_19 ( V_34 - 1 , V_6 -> V_32 + V_33 ) ;
V_6 -> V_19 = V_19 ;
}
F_18 ( & V_6 -> V_35 ) ;
V_31 = F_14 ( V_6 , V_19 , V_29 ) ;
F_19 ( V_41 | V_42 , V_6 -> V_32 + F_20 ( V_5 -> V_36 ) ) ;
F_19 ( V_31 , V_6 -> V_32 + F_21 ( V_5 -> V_36 ) ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
enum V_43 V_44 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_30 ;
V_30 = F_15 ( V_6 -> V_32 + V_45 ) ;
if ( V_44 == V_46 )
V_30 |= F_23 ( V_5 -> V_36 ) ;
else
V_30 &= ~ F_23 ( V_5 -> V_36 ) ;
F_19 ( V_30 , V_6 -> V_32 + V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_6 )
{
T_1 V_30 ;
int V_22 ;
if ( V_6 -> V_47 != 0 )
return 0 ;
V_30 = F_15 ( V_6 -> V_32 + V_38 ) ;
V_30 &= ~ ( V_48 << V_49 ) ;
V_30 |= F_25 ( V_6 -> V_15 ) ;
F_19 ( V_30 , V_6 -> V_32 + V_38 ) ;
V_22 = F_4 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
if ( V_22 )
return V_22 ;
V_22 = F_4 ( V_6 -> V_7 [ V_50 ] ) ;
if ( V_22 ) {
F_6 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
return V_22 ;
}
V_6 -> V_47 ++ ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_30 ;
int V_22 ;
F_17 ( & V_6 -> V_35 ) ;
V_30 = F_15 ( V_6 -> V_32 + V_51 ) ;
V_30 &= ~ F_23 ( V_5 -> V_36 ) ;
F_19 ( V_30 , V_6 -> V_32 + V_51 ) ;
V_22 = F_24 ( V_6 ) ;
F_18 ( & V_6 -> V_35 ) ;
return V_22 ;
}
static void F_27 ( struct V_1 * V_6 )
{
T_1 V_30 ;
if ( V_6 -> V_47 == 0 )
return;
if ( -- V_6 -> V_47 > 0 )
return;
V_30 = F_15 ( V_6 -> V_32 + V_38 ) ;
V_30 &= ~ ( V_48 << V_49 ) ;
F_19 ( V_30 , V_6 -> V_32 + V_38 ) ;
F_6 ( V_6 -> V_7 [ V_50 ] ) ;
F_6 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
}
static void F_28 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_30 ;
F_17 ( & V_6 -> V_35 ) ;
V_30 = F_15 ( V_6 -> V_32 + V_51 ) ;
V_30 |= F_23 ( V_5 -> V_36 ) ;
F_19 ( V_30 , V_6 -> V_32 + V_51 ) ;
F_27 ( V_6 ) ;
V_30 = F_15 ( V_6 -> V_32 + V_51 ) ;
if ( ( V_30 & 0xFF ) == 0xFF )
V_6 -> V_19 = 0 ;
F_18 ( & V_6 -> V_35 ) ;
}
static int F_29 ( struct V_1 * V_6 )
{
int V_22 ;
V_22 = F_4 ( V_6 -> V_7 [ V_8 ] ) ;
if ( V_22 )
return V_22 ;
F_19 ( 0x00 , V_6 -> V_32 + V_52 ) ;
F_19 ( 0x00 , V_6 -> V_32 + V_53 ) ;
F_19 ( 0xFF , V_6 -> V_32 + V_51 ) ;
F_6 ( V_6 -> V_7 [ V_8 ] ) ;
return 0 ;
}
static int F_30 ( struct V_54 * V_55 )
{
struct V_1 * V_6 ;
struct V_56 * V_57 ;
int V_22 ;
V_6 = F_31 ( & V_55 -> V_23 , sizeof( * V_6 ) , V_58 ) ;
if ( ! V_6 )
return - V_59 ;
F_32 ( & V_6 -> V_35 ) ;
V_6 -> V_3 . V_23 = & V_55 -> V_23 ;
V_57 = F_33 ( V_55 , V_60 , 0 ) ;
V_6 -> V_32 = F_34 ( & V_55 -> V_23 , V_57 ) ;
if ( F_35 ( V_6 -> V_32 ) )
return F_36 ( V_6 -> V_32 ) ;
V_6 -> V_7 [ V_8 ] = F_37 ( & V_55 -> V_23 , L_4 ) ;
if ( F_35 ( V_6 -> V_7 [ V_8 ] ) ) {
F_12 ( & V_55 -> V_23 , L_5 ) ;
return F_36 ( V_6 -> V_7 [ V_8 ] ) ;
}
V_6 -> V_7 [ V_17 ] = F_37 ( V_6 -> V_3 . V_23 , L_6 ) ;
if ( F_35 ( V_6 -> V_7 [ V_17 ] ) )
return F_36 ( V_6 -> V_7 [ V_17 ] ) ;
V_6 -> V_7 [ V_18 ] = F_37 ( V_6 -> V_3 . V_23 , L_7 ) ;
if ( F_35 ( V_6 -> V_7 [ V_18 ] ) )
return F_36 ( V_6 -> V_7 [ V_18 ] ) ;
V_6 -> V_7 [ V_50 ] =
F_37 ( V_6 -> V_3 . V_23 , L_8 ) ;
if ( F_35 ( V_6 -> V_7 [ V_50 ] ) )
return F_36 ( V_6 -> V_7 [ V_50 ] ) ;
V_6 -> V_3 . V_61 = & V_62 ;
V_6 -> V_3 . V_63 = V_64 ;
V_6 -> V_3 . V_65 = 3 ;
V_6 -> V_3 . V_32 = - 1 ;
V_6 -> V_3 . V_66 = 8 ;
V_22 = F_38 ( & V_6 -> V_3 ) ;
if ( V_22 < 0 ) {
F_12 ( & V_55 -> V_23 , L_9 , V_22 ) ;
return V_22 ;
}
F_39 ( V_55 , V_6 ) ;
return F_29 ( V_6 ) ;
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_6 = F_41 ( V_55 ) ;
return F_42 ( & V_6 -> V_3 ) ;
}
