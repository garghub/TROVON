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
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) ) {
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= V_18 ;
} else {
V_14 = 1 ;
}
V_15 = F_1 ( V_2 , V_10 , V_19 ) ;
V_15 = F_10 ( V_15 ) ;
return V_14 && ( V_15 == V_20 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 ;
int V_21 ;
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 |= V_13 ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
return V_21 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
V_14 << V_22 |
V_20 ) ;
return V_21 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_23 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_23 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 ;
int V_21 ;
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ ( V_13 | V_24 | V_25 ) ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
return V_21 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = V_18 | V_26 | V_27 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
( V_14 ) << V_22 |
V_28 ) ;
return V_21 ;
}
static int F_17 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= 0x0f ;
if ( ! V_12 )
return V_29 ;
return ( V_12 & F_18 ( 3 ) )
? V_30
: V_31 ;
}
static int F_19 ( struct V_8 * V_9 )
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
static int F_20 ( struct V_8 * V_9 , unsigned V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned V_35 ;
int V_6 ;
switch ( V_34 ) {
case V_36 :
V_35 = F_21 ( V_37 , V_2 -> V_38 , V_39 ) ;
break;
case V_40 :
V_35 = F_21 ( V_37 , V_2 -> V_38 , V_41 ) ;
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
static int F_22 ( struct V_8 * V_9 , unsigned V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_15 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = V_14 << V_22 ;
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
static int F_23 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_48 = V_2 -> V_49 [ V_47 ] ;
return F_24 ( V_2 , V_48 ) ? 0 : ( F_25 ( V_48 ) * 1000 ) ;
}
static int
F_26 ( struct V_8 * V_9 , unsigned V_50 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_51 ,
V_50 ) ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 = F_1 ( V_2 , V_10 ,
V_51 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 &= V_2 -> V_53 - 1 ;
return F_25 ( V_2 -> V_49 [ V_52 ] ) * 1000 ;
}
static int
F_28 ( struct V_8 * V_9 , int V_54 , int V_55 ,
unsigned * V_50 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 = F_29 ( V_54 - 600000 , 12500 ) ;
if ( V_2 -> V_56 ) {
return V_2 -> V_56 ( V_2 -> V_57 , V_54 ) ;
} else {
F_3 ( V_2 , V_10 ,
V_58 , V_52 ) ;
}
return 0 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 ;
if ( V_2 -> V_59 )
return V_2 -> V_59 ( V_2 -> V_57 ) ;
V_52 = F_1 ( V_2 , V_10 ,
V_58 ) ;
return V_52 * 12500 + 600000 ;
}
static int F_31 ( struct V_8 * V_9 , int V_54 ,
int V_55 , unsigned * V_50 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_56 )
return V_2 -> V_56 ( V_2 -> V_57 , V_54 ) ;
return - V_60 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_59 )
return V_2 -> V_59 ( V_2 -> V_57 ) ;
return - V_60 ;
}
static int F_33 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return ( ( V_2 -> V_61 + ( V_47 * 100 ) ) * 1000 ) ;
}
static int
F_34 ( struct V_8 * V_9 , int V_54 , int V_55 ,
unsigned * V_50 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 ;
if ( ( V_54 / 1000 < V_2 -> V_61 ) || ( V_55 / 1000 > V_2 -> V_62 ) )
return - V_63 ;
V_52 = ( V_54 / 1000 - 1000 ) / 100 + 1 ;
* V_50 = V_52 ;
return F_3 ( V_2 , V_10 , V_51 , V_52 ) ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 = F_1 ( V_2 , V_10 ,
V_51 ) ;
if ( V_52 < 0 )
return V_52 ;
return ( 1000 + ( 100 * ( V_52 - 1 ) ) ) * 1000 ;
}
static int F_36 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_61 * 1000 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_61 * 1000 ;
}
static int F_38 ( struct V_8 * V_9 , unsigned V_47 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_64 = 0 ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_64 = 100000 ;
case 0 :
switch ( V_47 ) {
case 0 :
V_64 = 0 ;
break;
case 58 :
V_64 = 1350 * 1000 ;
break;
case 59 :
V_64 = 1500 * 1000 ;
break;
case 60 :
V_64 = 1800 * 1000 ;
break;
case 61 :
V_64 = 1900 * 1000 ;
break;
case 62 :
V_64 = 2100 * 1000 ;
break;
default:
V_64 += ( 600000 + ( 12500 * ( V_47 - 1 ) ) ) ;
}
break;
case V_67 :
switch ( V_47 ) {
case 0 :
V_64 = 0 ;
break;
case 58 :
V_64 = 2084 * 1000 ;
break;
case 59 :
V_64 = 2315 * 1000 ;
break;
case 60 :
V_64 = 2778 * 1000 ;
break;
case 61 :
V_64 = 2932 * 1000 ;
break;
case 62 :
V_64 = 3241 * 1000 ;
break;
default:
V_64 = ( 1852000 + ( 38600 * ( V_47 - 1 ) ) ) ;
}
break;
case V_66 | V_67 :
switch ( V_47 ) {
case 0 :
V_64 = 0 ;
break;
case 58 :
V_64 = 4167 * 1000 ;
break;
case 59 :
V_64 = 2315 * 1000 ;
break;
case 60 :
V_64 = 2778 * 1000 ;
break;
case 61 :
V_64 = 2932 * 1000 ;
break;
case 62 :
V_64 = 3241 * 1000 ;
break;
default:
V_64 = ( 2161000 + ( 38600 * ( V_47 - 1 ) ) ) ;
}
break;
}
return V_64 ;
}
static int
F_39 ( struct V_8 * V_9 , int V_54 , int V_55 ,
unsigned int * V_50 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 = 0 ;
switch ( V_2 -> V_65 ) {
case 0 :
if ( V_54 == 0 )
V_52 = 0 ;
else if ( ( V_54 >= 600000 ) && ( V_54 <= 1300000 ) ) {
int V_68 ;
V_52 = F_29 ( V_54 - 600000 , 12500 ) ;
V_52 ++ ;
V_68 = F_38 ( V_9 , V_52 ) ;
if ( V_68 > V_55 )
return - V_42 ;
}
else if ( ( V_54 > 1900000 ) && ( V_55 >= 2100000 ) )
V_52 = 62 ;
else if ( ( V_54 > 1800000 ) && ( V_55 >= 1900000 ) )
V_52 = 61 ;
else if ( ( V_54 > 1500000 ) && ( V_55 >= 1800000 ) )
V_52 = 60 ;
else if ( ( V_54 > 1350000 ) && ( V_55 >= 1500000 ) )
V_52 = 59 ;
else if ( ( V_54 > 1300000 ) && ( V_55 >= 1350000 ) )
V_52 = 58 ;
else
return - V_42 ;
break;
case V_66 :
if ( V_54 == 0 )
V_52 = 0 ;
else if ( ( V_54 >= 700000 ) && ( V_54 <= 1420000 ) ) {
int V_68 ;
V_52 = F_29 ( V_54 - 700000 , 12500 ) ;
V_52 ++ ;
V_68 = F_38 ( V_9 , V_52 ) ;
if ( V_68 > V_55 )
return - V_42 ;
}
else if ( ( V_54 > 1900000 ) && ( V_55 >= 2100000 ) )
V_52 = 62 ;
else if ( ( V_54 > 1800000 ) && ( V_55 >= 1900000 ) )
V_52 = 61 ;
else if ( ( V_54 > 1350000 ) && ( V_55 >= 1800000 ) )
V_52 = 60 ;
else if ( ( V_54 > 1350000 ) && ( V_55 >= 1500000 ) )
V_52 = 59 ;
else if ( ( V_54 > 1300000 ) && ( V_55 >= 1350000 ) )
V_52 = 58 ;
else
return - V_42 ;
break;
case V_67 :
if ( V_54 == 0 ) {
V_52 = 0 ;
} else if ( ( V_54 >= 1852000 ) && ( V_55 <= 4013600 ) ) {
V_52 = F_29 ( V_54 - 1852000 , 38600 ) ;
V_52 ++ ;
}
break;
case V_66 | V_67 :
if ( V_54 == 0 ) {
V_52 = 0 ;
} else if ( ( V_54 >= 2161000 ) && ( V_55 <= 4321000 ) ) {
V_52 = F_29 ( V_54 - 2161000 , 38600 ) ;
V_52 ++ ;
}
break;
}
* V_50 = V_52 ;
return F_3 ( V_2 , V_10 , V_69 ,
V_52 ) ;
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_1 ( V_2 , V_10 , V_69 ) ;
}
static T_1 F_41 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_70 ) ;
return V_5 ;
}
static T_1 F_42 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_71 ) ;
return V_5 ;
}
static int T_2 F_43 ( struct V_72 * V_73 )
{
int V_74 , V_38 ;
struct V_1 * V_2 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_8 * V_9 ;
struct V_79 * V_80 ;
const struct V_81 * V_82 ;
struct V_83 V_84 = { } ;
V_82 = F_44 ( V_85 , & V_73 -> V_86 ) ;
if ( V_82 ) {
V_2 = V_82 -> V_57 ;
V_38 = V_2 -> V_87 . V_38 ;
V_76 = F_45 ( & V_73 -> V_86 ,
V_73 -> V_86 . V_88 ) ;
V_80 = NULL ;
} else {
V_38 = V_73 -> V_38 ;
V_76 = V_73 -> V_86 . V_89 ;
for ( V_74 = 0 , V_2 = NULL ; V_74 < F_46 ( V_85 ) ; V_74 ++ ) {
V_2 = V_85 [ V_74 ] . V_57 ;
if ( V_2 && V_2 -> V_87 . V_38 == V_38 )
break;
}
if ( V_74 == F_46 ( V_85 ) )
return - V_60 ;
V_80 = V_76 -> V_90 ;
if ( ! V_80 )
return - V_42 ;
}
if ( ! V_2 )
return - V_60 ;
if ( ! V_76 )
return - V_42 ;
if ( V_80 ) {
V_2 -> V_16 = V_80 -> V_16 ;
V_2 -> V_57 = V_80 -> V_57 ;
V_2 -> V_56 = V_80 -> V_56 ;
V_2 -> V_59 = V_80 -> V_59 ;
}
V_78 = & V_76 -> V_91 ;
V_78 -> V_92 &= V_36 | V_40 ;
V_78 -> V_93 &= V_94
| V_95
| V_96 ;
switch ( V_38 ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_78 -> V_104 = true ;
break;
default:
break;
}
switch ( V_38 ) {
case V_105 :
if ( F_42 () & V_106 )
V_2 -> V_65 |= V_67 ;
if ( F_41 () & V_106 )
V_2 -> V_65 |= V_66 ;
break;
case V_107 :
if ( F_42 () & V_108 )
V_2 -> V_65 |= V_67 ;
if ( F_41 () & V_108 )
V_2 -> V_65 |= V_66 ;
break;
case V_109 :
if ( F_42 () & V_110 )
V_2 -> V_65 |= V_67 ;
if ( F_41 () & V_110 )
V_2 -> V_65 |= V_66 ;
break;
}
V_84 . V_86 = & V_73 -> V_86 ;
V_84 . V_111 = V_76 ;
V_84 . V_90 = V_2 ;
V_84 . V_88 = V_73 -> V_86 . V_88 ;
V_9 = F_47 ( & V_2 -> V_87 , & V_84 ) ;
if ( F_48 ( V_9 ) ) {
F_49 ( & V_73 -> V_86 , L_1 ,
V_2 -> V_87 . V_112 , F_50 ( V_9 ) ) ;
return F_50 ( V_9 ) ;
}
F_51 ( V_73 , V_9 ) ;
if ( F_52 () )
F_3 ( V_2 , V_10 , V_113 ,
V_2 -> V_114 ) ;
return 0 ;
}
static int T_3 F_53 ( struct V_72 * V_73 )
{
F_54 ( F_55 ( V_73 ) ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
return F_57 ( & V_115 ) ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_115 ) ;
}
