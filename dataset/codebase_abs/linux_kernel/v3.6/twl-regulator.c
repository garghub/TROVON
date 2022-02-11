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
int V_14 ;
int V_21 ;
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ ( V_13 | V_23 | V_24 ) ;
V_21 = F_3 ( V_2 , V_10 , V_11 , V_14 ) ;
return V_21 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_21 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = V_18 | V_25 | V_26 ;
V_21 = F_3 ( V_2 , V_10 , V_19 ,
( V_14 ) << V_22 |
V_27 ) ;
return V_21 ;
}
static int F_15 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= 0x0f ;
if ( ! V_12 )
return V_28 ;
return ( V_12 & F_16 ( 3 ) )
? V_29
: V_30 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_15 ;
V_15 = F_5 ( V_9 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , V_10 , V_19 ) ;
switch ( F_10 ( V_15 ) ) {
case V_20 :
return V_29 ;
case V_31 :
return V_30 ;
case V_27 :
case V_32 :
default:
break;
}
return V_28 ;
}
static int F_18 ( struct V_8 * V_9 , unsigned V_33 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned V_34 ;
int V_6 ;
switch ( V_33 ) {
case V_35 :
V_34 = F_19 ( V_36 , V_2 -> V_37 , V_38 ) ;
break;
case V_39 :
V_34 = F_19 ( V_36 , V_2 -> V_37 , V_40 ) ;
break;
default:
return - V_41 ;
}
V_6 = F_5 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & ( V_24 | V_23 | V_13 ) ) )
return - V_42 ;
V_6 = F_4 ( V_43 ,
V_34 >> 8 , V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_43 ,
V_34 & 0xff , V_45 ) ;
}
static int F_20 ( struct V_8 * V_9 , unsigned V_33 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_14 = 0 ;
int V_15 ;
if ( ! ( F_9 () && ( V_2 -> V_16 & V_17 ) ) )
V_14 = F_5 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = V_14 << V_22 ;
switch ( V_33 ) {
case V_35 :
V_15 |= V_20 ;
break;
case V_39 :
V_15 |= V_31 ;
break;
default:
return - V_41 ;
}
return F_3 ( V_2 , V_10 , V_19 , V_15 ) ;
}
static int F_21 ( struct V_8 * V_9 , unsigned V_46 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_47 = V_2 -> V_48 [ V_46 ] ;
return F_22 ( V_2 , V_47 ) ? 0 : ( F_23 ( V_47 ) * 1000 ) ;
}
static int
F_24 ( struct V_8 * V_9 , unsigned V_49 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_50 ,
V_49 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_51 = F_1 ( V_2 , V_10 ,
V_50 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= V_2 -> V_52 - 1 ;
return F_23 ( V_2 -> V_48 [ V_51 ] ) * 1000 ;
}
static int
F_26 ( struct V_8 * V_9 , int V_53 , int V_54 ,
unsigned * V_49 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_51 = F_27 ( V_53 - 600000 , 12500 ) ;
if ( V_2 -> V_55 ) {
return V_2 -> V_55 ( V_2 -> V_56 , V_53 ) ;
} else {
F_3 ( V_2 , V_10 ,
V_57 , V_51 ) ;
}
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_51 ;
if ( V_2 -> V_58 )
return V_2 -> V_58 ( V_2 -> V_56 ) ;
V_51 = F_1 ( V_2 , V_10 ,
V_57 ) ;
return V_51 * 12500 + 600000 ;
}
static int F_29 ( struct V_8 * V_9 , int V_53 ,
int V_54 , unsigned * V_49 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_55 )
return V_2 -> V_55 ( V_2 -> V_56 , V_53 ) ;
return - V_59 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_2 -> V_58 )
return V_2 -> V_58 ( V_2 -> V_56 ) ;
return - V_59 ;
}
static int F_31 ( struct V_8 * V_9 , unsigned V_60 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
switch ( V_60 ) {
case 0 :
return 0 ;
case 1 ... 24 :
return ( V_2 -> V_61 + 100 * ( V_60 - 1 ) ) * 1000 ;
case 25 ... 30 :
return - V_41 ;
case 31 :
return 2750000 ;
default:
return - V_41 ;
}
}
static int
F_32 ( struct V_8 * V_9 , unsigned V_49 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_50 ,
V_49 ) ;
}
static int F_33 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_51 = F_1 ( V_2 , V_10 , V_50 ) ;
return V_51 ;
}
static int F_34 ( struct V_8 * V_9 , unsigned V_46 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_61 * 1000 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return V_2 -> V_61 * 1000 ;
}
static int F_36 ( struct V_8 * V_9 , unsigned V_46 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_62 = 0 ;
switch ( V_2 -> V_63 ) {
case V_64 :
V_62 = 100000 ;
case 0 :
switch ( V_46 ) {
case 0 :
V_62 = 0 ;
break;
case 58 :
V_62 = 1350 * 1000 ;
break;
case 59 :
V_62 = 1500 * 1000 ;
break;
case 60 :
V_62 = 1800 * 1000 ;
break;
case 61 :
V_62 = 1900 * 1000 ;
break;
case 62 :
V_62 = 2100 * 1000 ;
break;
default:
V_62 += ( 600000 + ( 12500 * ( V_46 - 1 ) ) ) ;
}
break;
case V_65 :
switch ( V_46 ) {
case 0 :
V_62 = 0 ;
break;
case 58 :
V_62 = 2084 * 1000 ;
break;
case 59 :
V_62 = 2315 * 1000 ;
break;
case 60 :
V_62 = 2778 * 1000 ;
break;
case 61 :
V_62 = 2932 * 1000 ;
break;
case 62 :
V_62 = 3241 * 1000 ;
break;
default:
V_62 = ( 1852000 + ( 38600 * ( V_46 - 1 ) ) ) ;
}
break;
case V_64 | V_65 :
switch ( V_46 ) {
case 0 :
V_62 = 0 ;
break;
case 58 :
V_62 = 4167 * 1000 ;
break;
case 59 :
V_62 = 2315 * 1000 ;
break;
case 60 :
V_62 = 2778 * 1000 ;
break;
case 61 :
V_62 = 2932 * 1000 ;
break;
case 62 :
V_62 = 3241 * 1000 ;
break;
default:
V_62 = ( 2161000 + ( 38600 * ( V_46 - 1 ) ) ) ;
}
break;
}
return V_62 ;
}
static int
F_37 ( struct V_8 * V_9 , int V_53 , int V_54 ,
unsigned int * V_49 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_51 = 0 ;
switch ( V_2 -> V_63 ) {
case 0 :
if ( V_53 == 0 )
V_51 = 0 ;
else if ( ( V_53 >= 600000 ) && ( V_53 <= 1300000 ) ) {
int V_66 ;
V_51 = F_27 ( V_53 - 600000 , 12500 ) ;
V_51 ++ ;
V_66 = F_36 ( V_9 , V_51 ) ;
if ( V_66 > V_54 )
return - V_41 ;
}
else if ( ( V_53 > 1900000 ) && ( V_54 >= 2100000 ) )
V_51 = 62 ;
else if ( ( V_53 > 1800000 ) && ( V_54 >= 1900000 ) )
V_51 = 61 ;
else if ( ( V_53 > 1500000 ) && ( V_54 >= 1800000 ) )
V_51 = 60 ;
else if ( ( V_53 > 1350000 ) && ( V_54 >= 1500000 ) )
V_51 = 59 ;
else if ( ( V_53 > 1300000 ) && ( V_54 >= 1350000 ) )
V_51 = 58 ;
else
return - V_41 ;
break;
case V_64 :
if ( V_53 == 0 )
V_51 = 0 ;
else if ( ( V_53 >= 700000 ) && ( V_53 <= 1420000 ) ) {
int V_66 ;
V_51 = F_27 ( V_53 - 700000 , 12500 ) ;
V_51 ++ ;
V_66 = F_36 ( V_9 , V_51 ) ;
if ( V_66 > V_54 )
return - V_41 ;
}
else if ( ( V_53 > 1900000 ) && ( V_54 >= 2100000 ) )
V_51 = 62 ;
else if ( ( V_53 > 1800000 ) && ( V_54 >= 1900000 ) )
V_51 = 61 ;
else if ( ( V_53 > 1350000 ) && ( V_54 >= 1800000 ) )
V_51 = 60 ;
else if ( ( V_53 > 1350000 ) && ( V_54 >= 1500000 ) )
V_51 = 59 ;
else if ( ( V_53 > 1300000 ) && ( V_54 >= 1350000 ) )
V_51 = 58 ;
else
return - V_41 ;
break;
case V_65 :
if ( V_53 == 0 ) {
V_51 = 0 ;
} else if ( ( V_53 >= 1852000 ) && ( V_54 <= 4013600 ) ) {
V_51 = F_27 ( V_53 - 1852000 , 38600 ) ;
V_51 ++ ;
}
break;
case V_64 | V_65 :
if ( V_53 == 0 ) {
V_51 = 0 ;
} else if ( ( V_53 >= 2161000 ) && ( V_54 <= 4321000 ) ) {
V_51 = F_27 ( V_53 - 2161000 , 38600 ) ;
V_51 ++ ;
}
break;
}
* V_49 = V_51 ;
return F_3 ( V_2 , V_10 , V_67 ,
V_51 ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_1 ( V_2 , V_10 , V_67 ) ;
}
static T_1 F_39 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_68 ) ;
return V_5 ;
}
static T_1 F_40 ( void )
{
T_1 V_5 ;
F_2 ( V_10 , & V_5 ,
V_69 ) ;
return V_5 ;
}
static int T_2 F_41 ( struct V_70 * V_71 )
{
int V_72 , V_37 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_8 * V_9 ;
struct V_77 * V_78 ;
const struct V_79 * V_80 ;
struct V_81 V_82 = { } ;
V_80 = F_42 ( V_83 , & V_71 -> V_84 ) ;
if ( V_80 ) {
V_2 = V_80 -> V_56 ;
V_37 = V_2 -> V_85 . V_37 ;
V_74 = F_43 ( & V_71 -> V_84 ,
V_71 -> V_84 . V_86 ) ;
V_78 = NULL ;
} else {
V_37 = V_71 -> V_37 ;
V_74 = V_71 -> V_84 . V_87 ;
for ( V_72 = 0 , V_2 = NULL ; V_72 < F_44 ( V_83 ) ; V_72 ++ ) {
V_2 = V_83 [ V_72 ] . V_56 ;
if ( V_2 && V_2 -> V_85 . V_37 == V_37 )
break;
}
if ( V_72 == F_44 ( V_83 ) )
return - V_59 ;
V_78 = V_74 -> V_88 ;
if ( ! V_78 )
return - V_41 ;
}
if ( ! V_2 )
return - V_59 ;
if ( ! V_74 )
return - V_41 ;
if ( V_78 ) {
V_2 -> V_16 = V_78 -> V_16 ;
V_2 -> V_56 = V_78 -> V_56 ;
V_2 -> V_55 = V_78 -> V_55 ;
V_2 -> V_58 = V_78 -> V_58 ;
}
V_76 = & V_74 -> V_89 ;
V_76 -> V_90 &= V_35 | V_39 ;
V_76 -> V_91 &= V_92
| V_93
| V_94 ;
switch ( V_37 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_76 -> V_102 = true ;
break;
default:
break;
}
switch ( V_37 ) {
case V_103 :
if ( F_40 () & V_104 )
V_2 -> V_63 |= V_65 ;
if ( F_39 () & V_104 )
V_2 -> V_63 |= V_64 ;
break;
case V_105 :
if ( F_40 () & V_106 )
V_2 -> V_63 |= V_65 ;
if ( F_39 () & V_106 )
V_2 -> V_63 |= V_64 ;
break;
case V_107 :
if ( F_40 () & V_108 )
V_2 -> V_63 |= V_65 ;
if ( F_39 () & V_108 )
V_2 -> V_63 |= V_64 ;
break;
}
V_82 . V_84 = & V_71 -> V_84 ;
V_82 . V_109 = V_74 ;
V_82 . V_88 = V_2 ;
V_82 . V_86 = V_71 -> V_84 . V_86 ;
V_9 = F_45 ( & V_2 -> V_85 , & V_82 ) ;
if ( F_46 ( V_9 ) ) {
F_47 ( & V_71 -> V_84 , L_1 ,
V_2 -> V_85 . V_110 , F_48 ( V_9 ) ) ;
return F_48 ( V_9 ) ;
}
F_49 ( V_71 , V_9 ) ;
if ( F_50 () )
F_3 ( V_2 , V_10 , V_111 ,
V_2 -> V_112 ) ;
return 0 ;
}
static int T_3 F_51 ( struct V_70 * V_71 )
{
F_52 ( F_53 ( V_71 ) ) ;
return 0 ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_113 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_113 ) ;
}
