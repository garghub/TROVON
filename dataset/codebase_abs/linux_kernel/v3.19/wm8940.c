static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
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
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_44 * V_45 ,
unsigned int V_46 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
T_1 V_49 = F_4 ( V_48 , V_8 ) & 0xFE67 ;
T_1 V_50 = F_4 ( V_48 , V_10 ) & 0x1fe ;
switch ( V_46 & V_51 ) {
case V_52 :
V_50 |= 1 ;
break;
case V_53 :
break;
default:
return - V_54 ;
}
F_5 ( V_48 , V_10 , V_50 ) ;
switch ( V_46 & V_55 ) {
case V_56 :
V_49 |= ( 2 << 3 ) ;
break;
case V_57 :
V_49 |= ( 1 << 3 ) ;
break;
case V_58 :
break;
case V_59 :
V_49 |= ( 3 << 3 ) ;
break;
case V_60 :
V_49 |= ( 3 << 3 ) | ( 1 << 7 ) ;
break;
}
switch ( V_46 & V_61 ) {
case V_62 :
break;
case V_63 :
V_49 |= ( 1 << 7 ) ;
break;
case V_64 :
V_49 |= ( 1 << 8 ) ;
break;
case V_65 :
V_49 |= ( 1 << 8 ) | ( 1 << 7 ) ;
break;
}
F_5 ( V_48 , V_8 , V_49 ) ;
return 0 ;
}
static int F_6 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_44 * V_70 )
{
struct V_47 * V_48 = V_70 -> V_48 ;
T_1 V_49 = F_4 ( V_48 , V_8 ) & 0xFD9F ;
T_1 V_71 = F_4 ( V_48 , V_11 ) & 0xFFF1 ;
T_1 V_72 = F_4 ( V_48 ,
V_9 ) & 0xFFDF ;
int V_73 ;
if ( V_67 -> V_74 == V_75
&& F_7 ( V_69 ) == 2 )
V_49 |= ( 1 << 9 ) ;
switch ( F_8 ( V_69 ) ) {
case 8000 :
V_71 |= ( 0x5 << 1 ) ;
break;
case 11025 :
V_71 |= ( 0x4 << 1 ) ;
break;
case 16000 :
V_71 |= ( 0x3 << 1 ) ;
break;
case 22050 :
V_71 |= ( 0x2 << 1 ) ;
break;
case 32000 :
V_71 |= ( 0x1 << 1 ) ;
break;
case 44100 :
case 48000 :
break;
}
V_73 = F_5 ( V_48 , V_11 , V_71 ) ;
if ( V_73 )
goto V_76;
switch ( F_9 ( V_69 ) ) {
case 8 :
V_72 = V_72 | ( 1 << 5 ) ;
break;
case 16 :
break;
case 20 :
V_49 |= ( 1 << 5 ) ;
break;
case 24 :
V_49 |= ( 2 << 5 ) ;
break;
case 32 :
V_49 |= ( 3 << 5 ) ;
break;
}
V_73 = F_5 ( V_48 , V_9 , V_72 ) ;
if ( V_73 )
goto V_76;
V_73 = F_5 ( V_48 , V_8 , V_49 ) ;
V_76:
return V_73 ;
}
static int F_10 ( struct V_44 * V_70 , int V_77 )
{
struct V_47 * V_48 = V_70 -> V_48 ;
T_1 V_78 = F_4 ( V_48 , V_14 ) & 0xffbf ;
if ( V_77 )
V_78 |= 0x40 ;
return F_5 ( V_48 , V_14 , V_78 ) ;
}
static int F_11 ( struct V_47 * V_48 ,
enum V_79 V_80 )
{
struct V_81 * V_82 = F_12 ( V_48 ) ;
T_1 V_83 ;
T_1 V_84 = F_4 ( V_48 , V_5 ) & 0x1F0 ;
int V_73 = 0 ;
switch ( V_80 ) {
case V_85 :
V_84 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_83 = F_4 ( V_48 , V_40 ) ;
V_73 = F_5 ( V_48 , V_40 , V_83 | 0x2 ) ;
if ( V_73 )
break;
V_73 = F_5 ( V_48 , V_5 , V_84 | 0x1 ) ;
break;
case V_86 :
V_84 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_73 = F_5 ( V_48 , V_5 , V_84 | 0x1 ) ;
break;
case V_87 :
if ( V_48 -> V_88 . V_89 == V_90 ) {
V_73 = F_13 ( V_82 -> V_91 ) ;
if ( V_73 < 0 ) {
F_14 ( V_48 -> V_2 , L_1 , V_73 ) ;
return V_73 ;
}
}
V_84 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_73 = F_5 ( V_48 , V_5 , V_84 | 0x2 ) ;
break;
case V_90 :
V_73 = F_5 ( V_48 , V_5 , V_84 ) ;
break;
}
V_48 -> V_88 . V_89 = V_80 ;
return V_73 ;
}
static void F_15 ( unsigned int V_92 , unsigned int V_93 )
{
unsigned long long V_94 ;
unsigned int V_95 , V_96 , V_97 ;
V_96 = V_92 / V_93 ;
if ( V_96 > 12 ) {
V_93 <<= 1 ;
V_98 . V_99 = 0 ;
V_96 = V_92 / V_93 ;
} else if ( V_96 < 3 ) {
V_93 >>= 2 ;
V_98 . V_99 = 3 ;
V_96 = V_92 / V_93 ;
} else if ( V_96 < 6 ) {
V_93 >>= 1 ;
V_98 . V_99 = 2 ;
V_96 = V_92 / V_93 ;
} else
V_98 . V_99 = 1 ;
if ( ( V_96 < 6 ) || ( V_96 > 12 ) )
F_16 ( V_100
L_2 ,
V_96 ) ;
V_98 . V_101 = V_96 ;
V_97 = V_92 % V_93 ;
V_94 = V_102 * ( long long ) V_97 ;
F_17 ( V_94 , V_93 ) ;
V_95 = V_94 & 0xFFFFFFFF ;
if ( ( V_95 % 10 ) >= 5 )
V_95 += 5 ;
V_95 /= 10 ;
V_98 . V_103 = V_95 ;
}
static int F_18 ( struct V_44 * V_45 , int V_104 ,
int V_93 , unsigned int V_105 , unsigned int V_106 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
T_1 V_3 ;
V_3 = F_4 ( V_48 , V_5 ) ;
F_5 ( V_48 , V_5 , V_3 & 0x1df ) ;
if ( V_105 == 0 || V_106 == 0 ) {
V_3 = F_4 ( V_48 , V_10 ) ;
F_5 ( V_48 , V_10 , V_3 & 0x0ff ) ;
F_5 ( V_48 , V_32 , ( 1 << 7 ) ) ;
return 0 ;
}
F_15 ( V_106 * 4 , V_105 ) ;
if ( V_98 . V_103 )
F_5 ( V_48 , V_32 ,
( V_98 . V_99 << 4 ) | V_98 . V_101 | ( 1 << 6 ) ) ;
else
F_5 ( V_48 , V_32 ,
( V_98 . V_99 << 4 ) | V_98 . V_101 ) ;
F_5 ( V_48 , V_33 , V_98 . V_103 >> 18 ) ;
F_5 ( V_48 , V_34 , ( V_98 . V_103 >> 9 ) & 0x1ff ) ;
F_5 ( V_48 , V_35 , V_98 . V_103 & 0x1ff ) ;
V_3 = F_4 ( V_48 , V_5 ) ;
F_5 ( V_48 , V_5 , V_3 | 0x020 ) ;
V_3 = F_4 ( V_48 , V_10 ) ;
F_5 ( V_48 , V_10 , V_3 | 0x100 ) ;
return 0 ;
}
static int F_19 ( struct V_44 * V_45 ,
int V_107 , unsigned int V_108 , int V_109 )
{
struct V_47 * V_48 = V_45 -> V_48 ;
struct V_81 * V_82 = F_12 ( V_48 ) ;
switch ( V_108 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_82 -> V_110 = V_108 ;
return 0 ;
}
return - V_54 ;
}
static int F_20 ( struct V_44 * V_45 ,
int V_111 , int div )
{
struct V_47 * V_48 = V_45 -> V_48 ;
T_1 V_3 ;
int V_73 = 0 ;
switch ( V_111 ) {
case V_112 :
V_3 = F_4 ( V_48 , V_10 ) & 0xFFE3 ;
V_73 = F_5 ( V_48 , V_10 , V_3 | ( div << 2 ) ) ;
break;
case V_113 :
V_3 = F_4 ( V_48 , V_10 ) & 0xFF1F ;
V_73 = F_5 ( V_48 , V_10 , V_3 | ( div << 5 ) ) ;
break;
case V_114 :
V_3 = F_4 ( V_48 , V_12 ) & 0xFFCF ;
V_73 = F_5 ( V_48 , V_12 , V_3 | ( div << 4 ) ) ;
break;
}
return V_73 ;
}
static int F_21 ( struct V_47 * V_48 )
{
struct V_115 * V_116 = V_48 -> V_2 -> V_117 ;
int V_73 ;
T_1 V_3 ;
V_73 = F_22 ( V_48 ) ;
if ( V_73 < 0 ) {
F_14 ( V_48 -> V_2 , L_3 ) ;
return V_73 ;
}
F_11 ( V_48 , V_87 ) ;
V_73 = F_5 ( V_48 , V_5 , 0x180 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( ! V_116 )
F_23 ( V_48 -> V_2 , L_4 ) ;
else {
V_3 = F_4 ( V_48 , V_40 ) ;
V_73 = F_5 ( V_48 , V_40 , V_3 | V_116 -> V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return V_73 ;
}
static int F_24 ( struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
struct V_81 * V_82 ;
int V_73 ;
V_82 = F_25 ( & V_120 -> V_2 , sizeof( struct V_81 ) ,
V_123 ) ;
if ( V_82 == NULL )
return - V_124 ;
V_82 -> V_91 = F_26 ( V_120 , & V_125 ) ;
if ( F_27 ( V_82 -> V_91 ) )
return F_28 ( V_82 -> V_91 ) ;
F_29 ( V_120 , V_82 ) ;
V_73 = F_30 ( & V_120 -> V_2 ,
& V_126 , & V_127 , 1 ) ;
return V_73 ;
}
static int F_31 ( struct V_119 * V_128 )
{
F_32 ( & V_128 -> V_2 ) ;
return 0 ;
}
