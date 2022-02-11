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
static int F_11 ( void )
{
int V_21 ;
int V_22 = 10 ;
T_1 V_15 ;
do {
V_21 = F_2 ( V_23 , & V_15 ,
V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_15 & V_25 ) )
return 0 ;
F_12 ( 1 ) ;
V_22 -- ;
} while ( V_22 );
return - V_26 ;
}
static int F_13 ( unsigned V_27 )
{
T_1 V_15 ;
int V_21 ;
V_21 = F_2 ( V_23 , & V_15 ,
V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_4 ( V_23 , V_15 | V_28 ,
V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_11 () ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_4 ( V_23 , V_27 >> 8 ,
V_29 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_4 ( V_23 , V_27 & 0xff ,
V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_11 () ;
if ( V_21 < 0 )
return V_21 ;
return F_4 ( V_23 , V_15 ,
V_24 ) ;
}
static int F_14 ( struct V_8 * V_9 )
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
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
V_14 << V_31 |
V_20 ) ;
return V_21 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 ;
int V_21 ;
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ ( V_13 | V_32 | V_33 ) ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
return V_21 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = V_18 | V_34 | V_35 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
( V_14 ) << V_31 |
V_36 ) ;
return V_21 ;
}
static int F_18 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= 0x0f ;
if ( ! V_12 )
return V_37 ;
return ( V_12 & F_19 ( 3 ) )
? V_38
: V_39 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_15 ;
V_15 = F_5 ( V_9 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , V_10 , V_19 ) ;
switch ( F_10 ( V_15 ) ) {
case V_20 :
return V_38 ;
case V_40 :
return V_39 ;
case V_36 :
case V_41 :
default:
break;
}
return V_37 ;
}
static int F_21 ( struct V_8 * V_9 , unsigned V_42 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned V_43 ;
switch ( V_42 ) {
case V_44 :
V_43 = F_22 ( V_45 , V_2 -> V_46 , V_47 ) ;
break;
case V_48 :
V_43 = F_22 ( V_45 , V_2 -> V_46 , V_49 ) ;
break;
default:
return - V_50 ;
}
return F_13 ( V_43 ) ;
}
static inline unsigned int F_23 ( unsigned int V_42 )
{
switch ( V_42 ) {
case V_47 :
return V_44 ;
case V_49 :
return V_48 ;
default:
return - V_50 ;
}
}
static int F_24 ( struct V_8 * V_9 , unsigned V_42 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_15 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = V_14 << V_31 ;
switch ( V_42 ) {
case V_44 :
V_15 |= V_20 ;
break;
case V_48 :
V_15 |= V_40 ;
break;
default:
return - V_50 ;
}
return F_3 ( V_2 , V_10 , V_19 , V_15 ) ;
}
static int F_25 ( struct V_8 * V_9 , unsigned V_51 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_52 = V_2 -> V_53 [ V_51 ] ;
return F_26 ( V_2 , V_52 ) ? 0 : ( F_27 ( V_52 ) * 1000 ) ;
}
static int
F_28 ( struct V_8 * V_9 , unsigned V_54 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_55 ,
V_54 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_56 = F_1 ( V_2 , V_10 , V_55 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= V_2 -> V_57 - 1 ;
return V_56 ;
}
static int
F_30 ( struct V_8 * V_9 , int V_58 , int V_59 ,
unsigned * V_54 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_56 = F_31 ( V_58 - 600000 , 12500 ) ;
if ( V_2 -> V_60 ) {
return V_2 -> V_60 ( V_2 -> V_61 , V_58 ) ;
} else {
F_3 ( V_2 , V_10 ,
V_62 , V_56 ) ;
}
return 0 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_56 ;
if ( V_2 -> V_63 )
return V_2 -> V_63 ( V_2 -> V_61 ) ;
V_56 = F_1 ( V_2 , V_10 ,
V_62 ) ;
return V_56 * 12500 + 600000 ;
}
static int F_33 ( struct V_8 * V_9 , int V_58 ,
int V_59 , unsigned * V_54 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_60 )
return V_2 -> V_60 ( V_2 -> V_61 , V_58 ) ;
return - V_64 ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_63 )
return V_2 -> V_63 ( V_2 -> V_61 ) ;
return - V_64 ;
}
static int F_35 ( struct V_8 * V_9 , unsigned V_65 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
switch ( V_65 ) {
case 0 :
return 0 ;
case 1 ... 24 :
return ( V_2 -> V_66 + 100 * ( V_65 - 1 ) ) * 1000 ;
case 25 ... 30 :
return - V_50 ;
case 31 :
return 2750000 ;
default:
return - V_50 ;
}
}
static int
F_36 ( struct V_8 * V_9 , unsigned V_54 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_55 ,
V_54 ) ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_56 = F_1 ( V_2 , V_10 , V_55 ) ;
return V_56 ;
}
static int F_38 ( struct V_8 * V_9 , unsigned V_51 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_67 = 0 ;
switch ( V_2 -> V_68 ) {
case V_69 :
V_67 = 100000 ;
case 0 :
switch ( V_51 ) {
case 0 :
V_67 = 0 ;
break;
case 58 :
V_67 = 1350 * 1000 ;
break;
case 59 :
V_67 = 1500 * 1000 ;
break;
case 60 :
V_67 = 1800 * 1000 ;
break;
case 61 :
V_67 = 1900 * 1000 ;
break;
case 62 :
V_67 = 2100 * 1000 ;
break;
default:
V_67 += ( 600000 + ( 12500 * ( V_51 - 1 ) ) ) ;
}
break;
case V_70 :
switch ( V_51 ) {
case 0 :
V_67 = 0 ;
break;
case 58 :
V_67 = 2084 * 1000 ;
break;
case 59 :
V_67 = 2315 * 1000 ;
break;
case 60 :
V_67 = 2778 * 1000 ;
break;
case 61 :
V_67 = 2932 * 1000 ;
break;
case 62 :
V_67 = 3241 * 1000 ;
break;
default:
V_67 = ( 1852000 + ( 38600 * ( V_51 - 1 ) ) ) ;
}
break;
case V_69 | V_70 :
switch ( V_51 ) {
case 0 :
V_67 = 0 ;
break;
case 58 :
V_67 = 4167 * 1000 ;
break;
case 59 :
V_67 = 2315 * 1000 ;
break;
case 60 :
V_67 = 2778 * 1000 ;
break;
case 61 :
V_67 = 2932 * 1000 ;
break;
case 62 :
V_67 = 3241 * 1000 ;
break;
default:
V_67 = ( 2161000 + ( 38600 * ( V_51 - 1 ) ) ) ;
}
break;
}
return V_67 ;
}
static int F_39 ( struct V_8 * V_9 , int V_58 ,
int V_59 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_56 = 0 ;
switch ( V_2 -> V_68 ) {
case 0 :
if ( V_58 == 0 )
V_56 = 0 ;
else if ( ( V_58 >= 600000 ) && ( V_58 <= 1300000 ) ) {
V_56 = F_31 ( V_58 - 600000 , 12500 ) ;
V_56 ++ ;
}
else if ( ( V_58 > 1900000 ) && ( V_58 <= 2100000 ) )
V_56 = 62 ;
else if ( ( V_58 > 1800000 ) && ( V_58 <= 1900000 ) )
V_56 = 61 ;
else if ( ( V_58 > 1500000 ) && ( V_58 <= 1800000 ) )
V_56 = 60 ;
else if ( ( V_58 > 1350000 ) && ( V_58 <= 1500000 ) )
V_56 = 59 ;
else if ( ( V_58 > 1300000 ) && ( V_58 <= 1350000 ) )
V_56 = 58 ;
else
return - V_50 ;
break;
case V_69 :
if ( V_58 == 0 )
V_56 = 0 ;
else if ( ( V_58 >= 700000 ) && ( V_58 <= 1420000 ) ) {
V_56 = F_31 ( V_58 - 700000 , 12500 ) ;
V_56 ++ ;
}
else if ( ( V_58 > 1900000 ) && ( V_58 <= 2100000 ) )
V_56 = 62 ;
else if ( ( V_58 > 1800000 ) && ( V_58 <= 1900000 ) )
V_56 = 61 ;
else if ( ( V_58 > 1350000 ) && ( V_58 <= 1800000 ) )
V_56 = 60 ;
else if ( ( V_58 > 1350000 ) && ( V_58 <= 1500000 ) )
V_56 = 59 ;
else if ( ( V_58 > 1300000 ) && ( V_58 <= 1350000 ) )
V_56 = 58 ;
else
return - V_50 ;
break;
case V_70 :
if ( V_58 == 0 ) {
V_56 = 0 ;
} else if ( ( V_58 >= 1852000 ) && ( V_59 <= 4013600 ) ) {
V_56 = F_31 ( V_58 - 1852000 , 38600 ) ;
V_56 ++ ;
}
break;
case V_69 | V_70 :
if ( V_58 == 0 ) {
V_56 = 0 ;
} else if ( ( V_58 >= 2161000 ) && ( V_58 <= 4321000 ) ) {
V_56 = F_31 ( V_58 - 2161000 , 38600 ) ;
V_56 ++ ;
}
break;
}
return V_56 ;
}
static int F_40 ( struct V_8 * V_9 ,
unsigned int V_54 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_71 ,
V_54 ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_1 ( V_2 , V_10 , V_71 ) ;
}
static T_1 F_42 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_72 ) ;
return V_5 ;
}
static T_1 F_43 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_73 ) ;
return V_5 ;
}
static int F_44 ( struct V_74 * V_75 )
{
int V_76 , V_46 ;
struct V_1 * V_2 ;
const struct V_1 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_8 * V_9 ;
struct V_82 * V_83 ;
const struct V_84 * V_85 ;
struct V_86 V_87 = { } ;
V_85 = F_45 ( V_88 , & V_75 -> V_89 ) ;
if ( V_85 ) {
V_77 = V_85 -> V_61 ;
V_46 = V_77 -> V_90 . V_46 ;
V_79 = F_46 ( & V_75 -> V_89 ,
V_75 -> V_89 . V_91 ,
& V_77 -> V_90 ) ;
V_83 = NULL ;
} else {
V_46 = V_75 -> V_46 ;
V_79 = F_47 ( & V_75 -> V_89 ) ;
for ( V_76 = 0 , V_77 = NULL ; V_76 < F_48 ( V_88 ) ; V_76 ++ ) {
V_77 = V_88 [ V_76 ] . V_61 ;
if ( V_77 && V_77 -> V_90 . V_46 == V_46 )
break;
}
if ( V_76 == F_48 ( V_88 ) )
return - V_64 ;
V_83 = V_79 -> V_92 ;
if ( ! V_83 )
return - V_50 ;
}
if ( ! V_77 )
return - V_64 ;
if ( ! V_79 )
return - V_50 ;
V_2 = F_49 ( & V_75 -> V_89 , V_77 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
if ( V_83 ) {
V_2 -> V_16 = V_83 -> V_16 ;
V_2 -> V_61 = V_83 -> V_61 ;
V_2 -> V_60 = V_83 -> V_60 ;
V_2 -> V_63 = V_83 -> V_63 ;
}
V_81 = & V_79 -> V_95 ;
V_81 -> V_96 &= V_44 | V_48 ;
V_81 -> V_97 &= V_98
| V_99
| V_100 ;
switch ( V_46 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_81 -> V_108 = true ;
break;
default:
break;
}
switch ( V_46 ) {
case V_109 :
if ( F_43 () & V_110 )
V_2 -> V_68 |= V_70 ;
if ( F_42 () & V_110 )
V_2 -> V_68 |= V_69 ;
break;
case V_111 :
if ( F_43 () & V_112 )
V_2 -> V_68 |= V_70 ;
if ( F_42 () & V_112 )
V_2 -> V_68 |= V_69 ;
break;
case V_113 :
if ( F_43 () & V_114 )
V_2 -> V_68 |= V_70 ;
if ( F_42 () & V_114 )
V_2 -> V_68 |= V_69 ;
break;
}
V_87 . V_89 = & V_75 -> V_89 ;
V_87 . V_115 = V_79 ;
V_87 . V_92 = V_2 ;
V_87 . V_91 = V_75 -> V_89 . V_91 ;
V_9 = F_50 ( & V_75 -> V_89 , & V_2 -> V_90 , & V_87 ) ;
if ( F_51 ( V_9 ) ) {
F_52 ( & V_75 -> V_89 , L_1 ,
V_2 -> V_90 . V_116 , F_53 ( V_9 ) ) ;
return F_53 ( V_9 ) ;
}
F_54 ( V_75 , V_9 ) ;
if ( F_55 () )
F_3 ( V_2 , V_10 , V_117 ,
V_2 -> V_118 ) ;
return 0 ;
}
static int T_2 F_56 ( void )
{
return F_57 ( & V_119 ) ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_119 ) ;
}
