static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
T_1 V_45 = F_3 ( V_44 , V_24 ) ;
if ( F_3 ( V_44 , V_26 ) & 0x180 )
V_45 &= ~ 0x4 ;
else
V_45 |= 0x4 ;
return F_4 ( V_44 , V_24 , V_45 ) ;
}
static inline int F_5 ( int V_46 , int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_6 ( V_49 ) ; V_48 ++ ) {
if ( V_49 [ V_48 ] . V_47 == V_47 && V_49 [ V_48 ] . V_46 == V_46 )
return V_48 ;
}
return - V_50 ;
}
static int F_7 ( struct V_51 * V_52 ,
int V_53 , unsigned int V_54 , int V_55 )
{
struct V_43 * V_44 = V_52 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
switch ( V_54 ) {
case 11289600 :
case 18432000 :
case 22579200 :
case 36864000 :
V_57 -> V_58 = & V_59 ;
V_57 -> V_60 = V_54 ;
return 0 ;
case 12288000 :
case 16934400 :
case 24576000 :
case 33868800 :
V_57 -> V_58 = & V_61 ;
V_57 -> V_60 = V_54 ;
return 0 ;
case 12000000 :
case 24000000 :
V_57 -> V_58 = & V_62 ;
V_57 -> V_60 = V_54 ;
return 0 ;
}
return - V_50 ;
}
static int F_9 ( struct V_51 * V_52 ,
unsigned int V_63 )
{
struct V_43 * V_44 = V_52 -> V_44 ;
T_1 V_64 = 0 ;
switch ( V_63 & V_65 ) {
case V_66 :
V_64 = 0x0040 ;
break;
case V_67 :
break;
default:
return - V_50 ;
}
switch ( V_63 & V_68 ) {
case V_69 :
V_64 |= 0x0002 ;
break;
case V_70 :
break;
case V_71 :
V_64 |= 0x0001 ;
break;
case V_72 :
V_64 |= 0x0003 ;
break;
case V_73 :
V_64 |= 0x0013 ;
break;
default:
return - V_50 ;
}
switch ( V_63 & V_74 ) {
case V_75 :
break;
case V_76 :
V_64 |= 0x0090 ;
break;
case V_77 :
V_64 |= 0x0080 ;
break;
case V_78 :
V_64 |= 0x0010 ;
break;
default:
return - V_50 ;
}
F_4 ( V_44 , V_9 , V_64 ) ;
return 0 ;
}
static int F_10 ( struct V_79 * V_80 ,
struct V_51 * V_81 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
if ( ! V_57 -> V_60 ) {
F_11 ( V_44 -> V_2 ,
L_1 ) ;
return - V_50 ;
}
F_12 ( V_80 -> V_82 , 0 ,
V_83 ,
V_57 -> V_58 ) ;
return 0 ;
}
static int F_13 ( struct V_79 * V_80 ,
struct V_84 * V_85 ,
struct V_51 * V_81 )
{
struct V_86 * V_87 = V_80 -> V_88 ;
struct V_43 * V_44 = V_87 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
T_1 V_64 = F_3 ( V_44 , V_9 ) & 0x1f3 ;
T_1 V_89 = F_3 ( V_44 , V_10 ) & 0x180 ;
int V_90 ;
V_90 = F_5 ( V_57 -> V_60 , F_14 ( V_85 ) ) ;
if ( V_90 < 0 ) {
V_90 = F_5 ( V_57 -> V_60 / 2 , F_14 ( V_85 ) ) ;
V_89 |= 0x40 ;
}
if ( V_90 < 0 ) {
F_11 ( V_44 -> V_2 ,
L_2 ,
F_14 ( V_85 ) , V_57 -> V_60 ) ;
return V_90 ;
}
switch ( F_15 ( V_85 ) ) {
case V_91 :
break;
case V_92 :
V_64 |= 0x0004 ;
break;
case V_93 :
V_64 |= 0x0008 ;
break;
case V_94 :
V_64 |= 0x000c ;
break;
}
F_4 ( V_44 , V_9 , V_64 ) ;
if ( V_90 >= 0 )
F_4 ( V_44 , V_10 , V_89 |
( V_49 [ V_90 ] . V_95 << 1 ) | V_49 [ V_90 ] . V_96 ) ;
return 0 ;
}
static int F_16 ( struct V_51 * V_81 , int V_97 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
T_1 V_98 = F_3 ( V_44 , V_8 ) & 0xfff7 ;
if ( V_97 )
F_4 ( V_44 , V_8 , V_98 | 0x8 ) ;
else
F_4 ( V_44 , V_8 , V_98 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_44 ,
enum V_99 V_100 )
{
struct V_56 * V_57 = F_8 ( V_44 ) ;
T_1 V_101 = F_3 ( V_44 , V_25 ) & ~ 0x1c1 ;
switch ( V_100 ) {
case V_102 :
break;
case V_103 :
F_4 ( V_44 , V_25 , V_101 | 0x00c0 ) ;
break;
case V_104 :
if ( V_44 -> V_105 . V_106 == V_107 ) {
F_18 ( V_57 -> V_108 ) ;
F_4 ( V_44 , V_25 , V_101 | 0x1c1 ) ;
F_19 ( 100 ) ;
}
F_4 ( V_44 , V_25 , V_101 | 0x0141 ) ;
break;
case V_107 :
F_4 ( V_44 , V_25 , 0x0000 ) ;
break;
}
V_44 -> V_105 . V_106 = V_100 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = F_8 ( V_44 ) ;
F_17 ( V_44 , V_107 ) ;
F_21 ( V_57 -> V_108 ) ;
return 0 ;
}
static int F_22 ( struct V_43 * V_44 )
{
F_17 ( V_44 , V_104 ) ;
return 0 ;
}
static int F_23 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = F_8 ( V_44 ) ;
int V_109 = 0 ;
V_44 -> V_110 = V_57 -> V_108 ;
V_109 = F_24 ( V_44 , 7 , 9 , V_111 ) ;
if ( V_109 < 0 ) {
F_11 ( V_44 -> V_2 , L_3 , V_109 ) ;
return V_109 ;
}
V_109 = F_25 ( V_44 ) ;
if ( V_109 < 0 ) {
F_11 ( V_44 -> V_2 , L_4 ) ;
return V_109 ;
}
F_26 ( V_44 , V_22 , 0x0100 , 0x0100 ) ;
F_26 ( V_44 , V_12 , 0x0100 , 0x0100 ) ;
F_26 ( V_44 , V_7 , 0x0100 , 0x0100 ) ;
F_26 ( V_44 , V_36 , 0x0100 , 0x0100 ) ;
F_26 ( V_44 , V_5 , 0x0100 , 0x0100 ) ;
F_17 ( V_44 , V_104 ) ;
return 0 ;
}
static int F_27 ( struct V_43 * V_44 )
{
F_17 ( V_44 , V_107 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_112 * V_113 )
{
struct V_56 * V_57 ;
int V_109 ;
V_57 = F_29 ( & V_113 -> V_2 , sizeof( struct V_56 ) ,
V_114 ) ;
if ( V_57 == NULL )
return - V_115 ;
V_57 -> V_108 = F_30 ( V_113 , & V_116 ) ;
if ( F_31 ( V_57 -> V_108 ) ) {
V_109 = F_32 ( V_57 -> V_108 ) ;
F_11 ( & V_113 -> V_2 , L_5 , V_109 ) ;
return V_109 ;
}
F_33 ( V_113 , V_57 ) ;
V_109 = F_34 ( & V_113 -> V_2 ,
& V_117 , & V_118 , 1 ) ;
if ( V_109 != 0 )
F_35 ( V_57 -> V_108 ) ;
return V_109 ;
}
static int T_3 F_36 ( struct V_112 * V_113 )
{
struct V_56 * V_57 = F_37 ( V_113 ) ;
F_38 ( & V_113 -> V_2 ) ;
F_35 ( V_57 -> V_108 ) ;
return 0 ;
}
static T_2 int F_39 ( struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
struct V_56 * V_57 ;
int V_109 ;
V_57 = F_29 ( & V_120 -> V_2 , sizeof( struct V_56 ) ,
V_114 ) ;
if ( V_57 == NULL )
return - V_115 ;
F_40 ( V_120 , V_57 ) ;
V_57 -> V_108 = F_41 ( V_120 , & V_116 ) ;
if ( F_31 ( V_57 -> V_108 ) ) {
V_109 = F_32 ( V_57 -> V_108 ) ;
F_11 ( & V_120 -> V_2 , L_5 , V_109 ) ;
return V_109 ;
}
V_109 = F_34 ( & V_120 -> V_2 ,
& V_117 , & V_118 , 1 ) ;
if ( V_109 != 0 )
F_35 ( V_57 -> V_108 ) ;
return V_109 ;
}
static T_3 int F_42 ( struct V_119 * V_123 )
{
struct V_56 * V_57 = F_43 ( V_123 ) ;
F_38 ( & V_123 -> V_2 ) ;
F_35 ( V_57 -> V_108 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
int V_109 = 0 ;
#if F_45 ( V_124 ) || F_45 ( V_125 )
V_109 = F_46 ( & V_126 ) ;
if ( V_109 != 0 ) {
F_47 ( V_127 L_6 ,
V_109 ) ;
}
#endif
#if F_45 ( V_128 )
V_109 = F_48 ( & V_129 ) ;
if ( V_109 != 0 ) {
F_47 ( V_127 L_7 ,
V_109 ) ;
}
#endif
return V_109 ;
}
static void T_5 F_49 ( void )
{
#if F_45 ( V_124 ) || F_45 ( V_125 )
F_50 ( & V_126 ) ;
#endif
#if F_45 ( V_128 )
F_51 ( & V_129 ) ;
#endif
}
