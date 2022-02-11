static inline int
F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_3 ,
& V_5 , V_2 -> V_7 + V_4 ) ;
return ( V_6 < 0 ) ? V_6 : V_5 ;
}
static inline int
F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 ,
T_1 V_5 )
{
return F_4 ( V_3 ,
V_5 , V_2 -> V_7 + V_4 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
return F_1 ( F_6 ( V_9 ) , V_10 ,
V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_12 & V_13 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 , V_15 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_1 ( V_2 , V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 &= V_18 ;
else
V_14 = 1 ;
V_15 = F_1 ( V_2 , V_10 , V_19 ) ;
V_15 = F_10 ( V_15 ) ;
return V_14 && ( V_15 == V_20 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 ;
int V_21 ;
V_14 = F_1 ( V_2 , V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 |= V_13 ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
F_12 ( V_2 -> V_22 ) ;
return V_21 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_1 ( V_2 , V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
V_14 << V_23 |
V_20 ) ;
F_12 ( V_2 -> V_22 ) ;
return V_21 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 ;
int V_21 ;
V_14 = F_1 ( V_2 , V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ ( V_13 | V_24 | V_25 ) ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
return V_21 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = V_18 | V_26 | V_27 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
( V_14 ) << V_23 |
V_28 ) ;
return V_21 ;
}
static int F_16 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= 0x0f ;
if ( ! V_12 )
return V_29 ;
return ( V_12 & F_17 ( 3 ) )
? V_30
: V_31 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_15 ;
V_15 = F_5 ( V_9 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , V_10 , V_19 ) ;
switch ( F_10 ( V_15 ) ) {
case V_20 :
return V_30 ;
case V_32 :
return V_31 ;
case V_28 :
case V_33 :
default:
break;
}
return V_29 ;
}
static int F_19 ( struct V_8 * V_9 , unsigned V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned V_35 ;
int V_6 ;
switch ( V_34 ) {
case V_36 :
V_35 = F_20 ( V_37 , V_2 -> V_38 , V_39 ) ;
break;
case V_40 :
V_35 = F_20 ( V_37 , V_2 -> V_38 , V_41 ) ;
break;
default:
return - V_42 ;
}
V_6 = F_5 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & ( V_25 | V_24 | V_13 ) ) )
return - V_43 ;
V_6 = F_4 ( V_44 ,
V_35 >> 8 , V_45 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_44 ,
V_35 & 0xff , V_46 ) ;
}
static int F_21 ( struct V_8 * V_9 , unsigned V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_15 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_1 ( V_2 , V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = V_14 << V_23 ;
switch ( V_34 ) {
case V_36 :
V_15 |= V_20 ;
break;
case V_40 :
V_15 |= V_32 ;
break;
default:
return - V_42 ;
}
return F_3 ( V_2 , V_10 , V_19 , V_15 ) ;
}
static int F_22 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_48 = V_2 -> V_49 [ V_47 ] ;
return F_23 ( V_48 ) ? 0 : ( F_24 ( V_48 ) * 1000 ) ;
}
static int
F_25 ( struct V_8 * V_9 , int V_50 , int V_51 ,
unsigned * V_52 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_2 -> V_54 ; V_53 ++ ) {
int V_48 = V_2 -> V_49 [ V_53 ] ;
int V_55 ;
if ( F_23 ( V_48 ) )
continue;
V_55 = F_24 ( V_48 ) * 1000 ;
if ( V_50 <= V_55 && V_55 <= V_51 ) {
* V_52 = V_53 ;
return F_3 ( V_2 , V_10 ,
V_56 , V_53 ) ;
}
}
return - V_57 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_53 = F_1 ( V_2 , V_10 ,
V_56 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 &= V_2 -> V_54 - 1 ;
return F_24 ( V_2 -> V_49 [ V_53 ] ) * 1000 ;
}
static int F_27 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return ( ( V_2 -> V_58 + ( V_47 * 100 ) ) * 1000 ) ;
}
static int
F_28 ( struct V_8 * V_9 , int V_50 , int V_51 ,
unsigned * V_52 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_53 ;
if ( ( V_50 / 1000 < V_2 -> V_58 ) || ( V_51 / 1000 > V_2 -> V_59 ) )
return - V_57 ;
V_53 = ( V_50 / 1000 - 1000 ) / 100 + 1 ;
* V_52 = V_53 ;
return F_3 ( V_2 , V_10 , V_56 , V_53 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_53 = F_1 ( V_2 , V_10 ,
V_56 ) ;
if ( V_53 < 0 )
return V_53 ;
return ( 1000 + ( 100 * ( V_53 - 1 ) ) ) * 1000 ;
}
static int F_30 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_58 * 1000 ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_58 * 1000 ;
}
static int F_32 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_60 = 0 ;
switch ( V_2 -> V_61 ) {
case V_62 :
V_60 = 100000 ;
case 0 :
switch ( V_47 ) {
case 0 :
V_60 = 0 ;
break;
case 58 :
V_60 = 1350 * 1000 ;
break;
case 59 :
V_60 = 1500 * 1000 ;
break;
case 60 :
V_60 = 1800 * 1000 ;
break;
case 61 :
V_60 = 1900 * 1000 ;
break;
case 62 :
V_60 = 2100 * 1000 ;
break;
default:
V_60 += ( 600000 + ( 12500 * ( V_47 - 1 ) ) ) ;
}
break;
case V_63 :
switch ( V_47 ) {
case 0 :
V_60 = 0 ;
break;
case 58 :
V_60 = 2084 * 1000 ;
break;
case 59 :
V_60 = 2315 * 1000 ;
break;
case 60 :
V_60 = 2778 * 1000 ;
break;
case 61 :
V_60 = 2932 * 1000 ;
break;
case 62 :
V_60 = 3241 * 1000 ;
break;
default:
V_60 = ( 1852000 + ( 38600 * ( V_47 - 1 ) ) ) ;
}
break;
case V_62 | V_63 :
switch ( V_47 ) {
case 0 :
V_60 = 0 ;
break;
case 58 :
V_60 = 4167 * 1000 ;
break;
case 59 :
V_60 = 2315 * 1000 ;
break;
case 60 :
V_60 = 2778 * 1000 ;
break;
case 61 :
V_60 = 2932 * 1000 ;
break;
case 62 :
V_60 = 3241 * 1000 ;
break;
default:
V_60 = ( 2161000 + ( 38600 * ( V_47 - 1 ) ) ) ;
}
break;
}
return V_60 ;
}
static int
F_33 ( struct V_8 * V_9 , int V_50 , int V_51 ,
unsigned int * V_52 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_53 = 0 ;
switch ( V_2 -> V_61 ) {
case 0 :
if ( V_50 == 0 )
V_53 = 0 ;
else if ( ( V_50 >= 600000 ) && ( V_51 <= 1300000 ) ) {
V_53 = ( V_50 - 600000 ) / 125 ;
if ( V_53 % 100 )
V_53 += 100 ;
V_53 /= 100 ;
V_53 ++ ;
}
else if ( ( V_50 > 1900000 ) && ( V_51 >= 2100000 ) )
V_53 = 62 ;
else if ( ( V_50 > 1800000 ) && ( V_51 >= 1900000 ) )
V_53 = 61 ;
else if ( ( V_50 > 1500000 ) && ( V_51 >= 1800000 ) )
V_53 = 60 ;
else if ( ( V_50 > 1350000 ) && ( V_51 >= 1500000 ) )
V_53 = 59 ;
else if ( ( V_50 > 1300000 ) && ( V_51 >= 1350000 ) )
V_53 = 58 ;
else
return - V_42 ;
break;
case V_62 :
if ( V_50 == 0 )
V_53 = 0 ;
else if ( ( V_50 >= 700000 ) && ( V_51 <= 1420000 ) ) {
V_53 = ( V_50 - 700000 ) / 125 ;
if ( V_53 % 100 )
V_53 += 100 ;
V_53 /= 100 ;
V_53 ++ ;
}
else if ( ( V_50 > 1900000 ) && ( V_51 >= 2100000 ) )
V_53 = 62 ;
else if ( ( V_50 > 1800000 ) && ( V_51 >= 1900000 ) )
V_53 = 61 ;
else if ( ( V_50 > 1350000 ) && ( V_51 >= 1800000 ) )
V_53 = 60 ;
else if ( ( V_50 > 1350000 ) && ( V_51 >= 1500000 ) )
V_53 = 59 ;
else if ( ( V_50 > 1300000 ) && ( V_51 >= 1350000 ) )
V_53 = 58 ;
else
return - V_42 ;
break;
case V_63 :
if ( V_50 == 0 )
V_53 = 0 ;
else if ( ( V_50 >= 1852000 ) && ( V_51 <= 4013600 ) ) {
V_53 = ( V_50 - 1852000 ) / 386 ;
if ( V_53 % 100 )
V_53 += 100 ;
V_53 /= 100 ;
V_53 ++ ;
}
break;
case V_62 | V_63 :
if ( V_50 == 0 )
V_53 = 0 ;
else if ( ( V_50 >= 2161000 ) && ( V_51 <= 4321000 ) ) {
V_53 = ( V_50 - 1852000 ) / 386 ;
if ( V_53 % 100 )
V_53 += 100 ;
V_53 /= 100 ;
V_53 ++ ;
}
break;
}
* V_52 = V_53 ;
return F_3 ( V_2 , V_10 , V_64 ,
V_53 ) ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_1 ( V_2 , V_10 , V_64 ) ;
}
static T_1 F_35 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_65 ) ;
return V_5 ;
}
static T_1 F_36 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_66 ) ;
return V_5 ;
}
static int T_2 F_37 ( struct V_67 * V_68 )
{
int V_69 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_8 * V_9 ;
for ( V_69 = 0 , V_2 = NULL ; V_69 < F_38 ( V_74 ) ; V_69 ++ ) {
if ( V_74 [ V_69 ] . V_75 . V_38 != V_68 -> V_38 )
continue;
V_2 = V_74 + V_69 ;
break;
}
if ( ! V_2 )
return - V_76 ;
V_71 = V_68 -> V_77 . V_78 ;
if ( ! V_71 )
return - V_42 ;
V_2 -> V_16 = ( unsigned long ) V_71 -> V_79 ;
V_73 = & V_71 -> V_80 ;
V_73 -> V_81 &= V_36 | V_40 ;
V_73 -> V_82 &= V_83
| V_84
| V_85 ;
switch ( V_68 -> V_38 ) {
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_73 -> V_93 = true ;
break;
default:
break;
}
switch ( V_68 -> V_38 ) {
case V_94 :
if ( F_36 () & V_95 )
V_2 -> V_61 |= V_63 ;
if ( F_35 () & V_95 )
V_2 -> V_61 |= V_62 ;
break;
case V_96 :
if ( F_36 () & V_97 )
V_2 -> V_61 |= V_63 ;
if ( F_35 () & V_97 )
V_2 -> V_61 |= V_62 ;
break;
case V_98 :
if ( F_36 () & V_99 )
V_2 -> V_61 |= V_63 ;
if ( F_35 () & V_99 )
V_2 -> V_61 |= V_62 ;
break;
}
V_9 = F_39 ( & V_2 -> V_75 , & V_68 -> V_77 , V_71 , V_2 ) ;
if ( F_40 ( V_9 ) ) {
F_41 ( & V_68 -> V_77 , L_1 ,
V_2 -> V_75 . V_100 , F_42 ( V_9 ) ) ;
return F_42 ( V_9 ) ;
}
F_43 ( V_68 , V_9 ) ;
if ( F_44 () )
F_3 ( V_2 , V_10 , V_101 ,
V_2 -> V_102 ) ;
return 0 ;
}
static int T_3 F_45 ( struct V_67 * V_68 )
{
F_46 ( F_47 ( V_68 ) ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_103 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_103 ) ;
}
