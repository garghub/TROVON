static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ? true : false ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
return ( V_4 & ( 1 << V_2 -> V_7 -> V_8 ) ) ? true : false ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
T_1 V_9 ;
if ( ! V_2 )
return false ;
V_9 = F_3 ( V_2 -> V_5 + V_10 ) ;
if ( F_1 ( V_2 ) )
V_9 &= V_11 ;
else
V_9 &= V_12 ;
return V_9 ? true : false ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ? : V_2 -> V_13 ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = F_5 ( V_2 ) ;
return F_4 ( V_14 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_6 ( V_2 ) ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
T_1 V_9 ;
if ( ! V_2 )
return false ;
V_9 = F_3 ( V_2 -> V_5 + V_10 ) & V_15 ;
return V_9 ? true : false ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = F_5 ( V_2 ) ;
return F_8 ( V_14 ) ;
}
static inline bool F_10 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) || F_9 ( V_2 ) ;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) || F_6 ( V_2 ) ;
}
static inline bool F_12 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_8 ( V_2 ) ;
}
static inline bool F_13 ( struct V_1 * V_2 )
{
return F_12 ( V_2 ) || F_11 ( V_2 ) ;
}
static inline struct V_1 * F_14 ( struct V_16 * V_17 )
{
return F_15 ( V_17 ) ;
}
static inline bool F_16 ( struct V_1 * V_2 )
{
if ( V_2 && ( V_2 -> V_18 & V_19 ) )
return true ;
else
return false ;
}
static inline bool F_17 ( struct V_1 * V_2 )
{
if ( F_16 ( V_2 ) && ( V_2 -> V_18 & V_20 ) )
return true ;
else
return false ;
}
static inline unsigned F_18 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_3 ( V_2 -> V_5 + V_6 ) >> V_2 -> V_7 -> V_22 ;
V_21 &= V_2 -> V_7 -> V_23 ;
switch ( V_21 ) {
case 7 : return 192 ;
case 6 : return 96 ;
case 5 : return 128 ;
case 4 : return 64 ;
case 3 : return 768 ;
case 2 : return 384 ;
case 1 : return 512 ;
default: return 256 ;
}
}
static inline void F_19 ( struct V_1 * V_2 , unsigned V_21 )
{
T_1 V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
int V_24 = V_2 -> V_7 -> V_22 ;
V_4 &= ~ ( V_2 -> V_7 -> V_23 << V_24 ) ;
switch ( V_21 ) {
case 192 :
V_4 |= ( V_25 << V_24 ) ;
break;
case 96 :
V_4 |= ( V_26 << V_24 ) ;
break;
case 128 :
V_4 |= ( V_27 << V_24 ) ;
break;
case 64 :
V_4 |= ( V_28 << V_24 ) ;
break;
case 768 :
V_4 |= ( V_29 << V_24 ) ;
break;
case 512 :
V_4 |= ( V_30 << V_24 ) ;
break;
case 384 :
V_4 |= ( V_31 << V_24 ) ;
break;
default:
V_4 |= ( V_32 << V_24 ) ;
break;
}
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static inline unsigned F_21 ( struct V_1 * V_2 )
{
T_1 V_33 ;
V_33 = F_3 ( V_2 -> V_5 + V_6 ) >> V_2 -> V_7 -> V_34 ;
V_33 &= V_2 -> V_7 -> V_35 ;
switch ( V_33 ) {
case 8 : return 256 ;
case 7 : return 192 ;
case 6 : return 128 ;
case 5 : return 96 ;
case 4 : return 64 ;
case 3 : return 24 ;
case 2 : return 16 ;
case 1 : return 48 ;
default: return 32 ;
}
}
static inline void F_22 ( struct V_1 * V_2 , unsigned V_33 )
{
T_1 V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
int V_36 = V_2 -> V_37 & V_38 ;
int V_39 = V_2 -> V_7 -> V_34 ;
if ( ! V_36 && V_33 > 48 ) {
F_23 ( & V_2 -> V_40 -> V_41 , L_1 ) ;
return;
}
V_4 &= ~ ( V_2 -> V_7 -> V_35 << V_39 ) ;
switch ( V_33 ) {
case 48 :
V_4 |= ( V_42 << V_39 ) ;
break;
case 32 :
V_4 |= ( V_43 << V_39 ) ;
break;
case 24 :
V_4 |= ( V_44 << V_39 ) ;
break;
case 16 :
V_4 |= ( V_45 << V_39 ) ;
break;
case 64 :
V_4 |= ( V_46 << V_39 ) ;
break;
case 96 :
V_4 |= ( V_47 << V_39 ) ;
break;
case 128 :
V_4 |= ( V_48 << V_39 ) ;
break;
case 192 :
V_4 |= ( V_49 << V_39 ) ;
break;
case 256 :
V_4 |= ( V_50 << V_39 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_2 ) ;
return;
}
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
int V_51 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_51 = ( V_51 >> 13 ) & 0x3 ;
switch ( V_51 ) {
case 2 : return 24 ;
case 1 : return 8 ;
default: return 16 ;
}
}
static void F_25 ( struct V_1 * V_2 , int V_52 )
{
void T_2 * V_5 = V_2 -> V_5 ;
int V_53 = V_2 -> V_7 -> V_53 ;
T_1 V_54 = F_3 ( V_5 + V_10 ) ;
T_1 V_4 = F_3 ( V_5 + V_6 ) & ~ ( 3 << V_53 ) ;
if ( V_52 ) {
V_54 |= V_55 ;
V_54 &= ~ V_56 ;
if ( F_1 ( V_2 ) ) {
V_54 |= V_11 ;
V_54 &= ~ V_57 ;
} else {
V_54 |= V_12 ;
V_54 &= ~ V_58 ;
}
if ( F_10 ( V_2 ) )
V_4 |= 2 << V_53 ;
else
V_4 |= 0 << V_53 ;
} else {
if ( F_1 ( V_2 ) ) {
V_54 |= V_57 ;
V_54 &= ~ V_11 ;
} else {
V_54 |= V_58 ;
V_54 &= ~ V_12 ;
}
if ( F_6 ( V_2 ) ) {
F_20 ( V_54 , V_5 + V_10 ) ;
return;
}
V_54 |= V_56 ;
if ( F_10 ( V_2 ) )
V_4 |= 1 << V_53 ;
else
V_54 &= ~ V_55 ;
}
F_20 ( V_4 , V_5 + V_6 ) ;
F_20 ( V_54 , V_5 + V_10 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_52 )
{
void T_2 * V_5 = V_2 -> V_5 ;
int V_53 = V_2 -> V_7 -> V_53 ;
T_1 V_54 = F_3 ( V_5 + V_10 ) ;
T_1 V_4 = F_3 ( V_5 + V_6 ) & ~ ( 3 << V_53 ) ;
if ( V_52 ) {
V_54 |= V_15 | V_55 ;
V_54 &= ~ ( V_59 | V_60 ) ;
if ( F_7 ( V_2 ) )
V_4 |= 2 << V_53 ;
else
V_4 |= 1 << V_53 ;
} else {
V_54 |= V_59 | V_60 ;
V_54 &= ~ V_15 ;
if ( F_7 ( V_2 ) )
V_4 |= 0 << V_53 ;
else
V_54 &= ~ V_55 ;
}
F_20 ( V_4 , V_5 + V_6 ) ;
F_20 ( V_54 , V_5 + V_10 ) ;
}
static inline void F_27 ( struct V_1 * V_2 , T_1 V_61 )
{
void T_2 * V_62 ;
T_1 V_63 ;
if ( ! V_2 )
return;
if ( F_1 ( V_2 ) )
V_62 = V_2 -> V_5 + V_64 ;
else
V_62 = V_2 -> V_5 + V_65 ;
F_20 ( F_3 ( V_62 ) | V_61 , V_62 ) ;
V_63 = F_28 ( 1 ) / 1000 ;
while ( -- V_63 )
F_29 () ;
F_20 ( F_3 ( V_62 ) & ~ V_61 , V_62 ) ;
}
static int F_30 ( struct V_16 * V_17 ,
int V_66 , unsigned int V_21 , int V_67 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
const struct V_68 * V_69 = V_2 -> V_7 ;
unsigned int V_70 = 1 << V_69 -> V_71 ;
unsigned int V_72 = 1 << V_69 -> V_73 ;
T_1 V_4 , V_74 , V_63 = 0 ;
unsigned long V_75 ;
F_31 ( V_2 -> V_76 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
switch ( V_66 ) {
case V_77 :
V_74 = V_78 ;
V_63 = V_67 ;
break;
case V_79 :
V_74 = 1 << V_69 -> V_71 ;
if ( V_67 == V_80 )
V_21 = 0 ;
if ( ( V_21 && V_14 && V_14 -> V_21 && ( V_14 -> V_21 != V_21 ) ) ||
( F_13 ( V_2 ) &&
( ( ( V_67 == V_80 )
&& ! ( V_4 & V_70 ) ) ||
( ( V_67 == V_81 )
&& ( V_4 & V_70 ) ) ) ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_82 , __LINE__ ) ;
return - V_83 ;
}
if ( V_67 == V_80 )
V_63 = 1 << V_69 -> V_71 ;
V_2 -> V_21 = V_21 ;
break;
case V_84 :
case V_85 :
V_74 = 1 << V_69 -> V_73 ;
if ( ( V_2 -> V_37 & V_86 )
|| ( V_66 == V_84 ) )
V_66 = 0 ;
else
V_66 = 1 ;
if ( ! F_13 ( V_2 ) ) {
if ( V_2 -> V_87 && ! F_33 ( V_2 -> V_87 ) ) {
if ( ( V_66 && ! ( V_4 & V_72 ) ) ||
( ! V_66 && ( V_4 & V_72 ) ) ) {
F_34 ( V_2 -> V_87 ) ;
F_35 ( V_2 -> V_87 ) ;
} else {
V_2 -> V_88 =
F_36 ( V_2 -> V_87 ) ;
return 0 ;
}
}
if ( V_66 )
V_2 -> V_87 = F_37 ( & V_2 -> V_40 -> V_41 ,
L_4 ) ;
else
V_2 -> V_87 = F_37 ( & V_2 -> V_40 -> V_41 ,
L_5 ) ;
if ( F_38 ( F_33 ( V_2 -> V_87 ) ) )
return F_39 ( V_2 -> V_87 ) ;
F_40 ( V_2 -> V_87 ) ;
V_2 -> V_88 = F_36 ( V_2 -> V_87 ) ;
if ( V_14 ) {
V_14 -> V_87 = V_2 -> V_87 ;
V_14 -> V_88 = V_2 -> V_88 ;
}
} else if ( ( ! V_66 && ( V_4 & V_72 ) )
|| ( V_66 && ! ( V_4 & V_72 ) ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_82 , __LINE__ ) ;
return - V_83 ;
} else {
V_2 -> V_87 = V_14 -> V_87 ;
V_2 -> V_88 = V_14 -> V_88 ;
return 0 ;
}
if ( V_66 == 1 )
V_63 = 1 << V_69 -> V_73 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_6 ) ;
return - V_89 ;
}
F_31 ( V_2 -> V_76 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 = ( V_4 & ~ V_74 ) | V_63 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 ,
unsigned int V_90 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
int V_91 , V_92 , V_93 , V_94 , V_95 ;
T_1 V_4 , V_96 = 0 ;
unsigned long V_75 ;
V_91 = V_2 -> V_7 -> V_97 ;
V_92 = V_2 -> V_7 -> V_98 ;
V_95 = 1 << V_2 -> V_7 -> V_8 ;
V_93 = V_99 << V_92 ;
V_94 = V_100 << V_91 ;
switch ( V_90 & V_101 ) {
case V_102 :
V_96 |= V_94 ;
V_96 |= ( V_103 << V_92 ) ;
break;
case V_104 :
V_96 |= V_94 ;
V_96 |= ( V_105 << V_92 ) ;
break;
case V_106 :
V_96 |= ( V_107 << V_92 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_7 ) ;
return - V_89 ;
}
switch ( V_90 & V_108 ) {
case V_109 :
break;
case V_110 :
if ( V_96 & V_94 )
V_96 &= ~ V_94 ;
else
V_96 |= V_94 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_8 ) ;
return - V_89 ;
}
switch ( V_90 & V_111 ) {
case V_112 :
V_96 |= V_95 ;
break;
case V_113 :
if ( V_2 -> V_88 == 0 )
F_30 ( V_17 , V_84 ,
0 , V_80 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_9 ) ;
return - V_89 ;
}
F_31 ( V_2 -> V_76 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
if ( F_13 ( V_2 ) &&
( ( V_4 & ( V_93 | V_94 | V_95 ) ) != V_96 ) ) {
F_32 ( V_2 -> V_76 , V_75 ) ;
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_82 , __LINE__ ) ;
return - V_83 ;
}
V_4 &= ~ ( V_93 | V_94 | V_95 ) ;
V_4 |= V_96 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
return 0 ;
}
static int F_42 ( struct V_114 * V_115 ,
struct V_116 * V_117 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
T_1 V_4 , V_74 = 0 , V_63 = 0 ;
unsigned long V_75 ;
if ( ! F_1 ( V_2 ) )
V_74 |= ( V_118 | V_119 ) ;
switch ( F_43 ( V_117 ) ) {
case 6 :
V_63 |= V_118 ;
case 4 :
V_63 |= V_119 ;
break;
case 2 :
if ( V_115 -> V_120 == V_121 )
V_2 -> V_122 . V_123 = 4 ;
else
V_2 -> V_124 . V_123 = 4 ;
break;
case 1 :
if ( V_115 -> V_120 == V_121 )
V_2 -> V_122 . V_123 = 2 ;
else
V_2 -> V_124 . V_123 = 2 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_10 ,
F_43 ( V_117 ) ) ;
return - V_89 ;
}
if ( F_1 ( V_2 ) )
V_74 |= V_125 ;
else
V_74 |= V_126 ;
if ( F_17 ( V_2 ) )
V_74 |= V_127 ;
switch ( F_44 ( V_117 ) ) {
case 8 :
if ( F_1 ( V_2 ) )
V_63 |= V_128 ;
else
V_63 |= V_129 ;
if ( F_17 ( V_2 ) )
V_63 |= V_130 ;
break;
case 16 :
if ( F_1 ( V_2 ) )
V_63 |= V_131 ;
else
V_63 |= V_132 ;
if ( F_17 ( V_2 ) )
V_63 |= V_133 ;
break;
case 24 :
if ( F_1 ( V_2 ) )
V_63 |= V_134 ;
else
V_63 |= V_135 ;
if ( F_17 ( V_2 ) )
V_63 |= V_136 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_11 ,
F_45 ( V_117 ) ) ;
return - V_89 ;
}
F_31 ( V_2 -> V_76 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 = ( V_4 & ~ V_74 ) | V_63 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
F_46 ( V_17 , & V_2 -> V_122 , & V_2 -> V_124 ) ;
V_2 -> V_137 = F_47 ( V_117 ) ;
return 0 ;
}
static int F_48 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
F_31 ( & V_76 , V_75 ) ;
V_2 -> V_18 |= V_19 ;
if ( F_17 ( V_14 ) )
V_2 -> V_18 &= ~ V_20 ;
else
V_2 -> V_18 |= V_20 ;
if ( ! F_13 ( V_2 ) && ( V_2 -> V_37 & V_138 ) )
F_20 ( V_139 , V_2 -> V_5 + V_10 ) ;
F_32 ( & V_76 , V_75 ) ;
return 0 ;
}
static void F_49 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
F_31 ( & V_76 , V_75 ) ;
V_2 -> V_18 &= ~ V_19 ;
V_2 -> V_18 &= ~ V_20 ;
if ( F_16 ( V_14 ) )
V_14 -> V_18 |= V_20 ;
V_2 -> V_21 = 0 ;
V_2 -> V_33 = 0 ;
F_32 ( & V_76 , V_75 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned V_21 , V_33 , V_51 ;
T_1 V_140 ;
V_51 = F_24 ( V_2 ) ;
V_33 = V_2 -> V_33 ;
if ( ! V_33 && V_14 )
V_33 = V_14 -> V_33 ;
if ( ! V_33 )
V_33 = V_51 * 2 ;
V_21 = V_2 -> V_21 ;
if ( ! V_21 && V_14 )
V_21 = V_14 -> V_21 ;
if ( ( V_21 == 256 || V_21 == 512 ) && ( V_51 == 24 ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_12 , V_21 ) ;
return - V_89 ;
}
if ( ! V_21 ) {
if ( V_33 == 16 || V_33 == 32 )
V_21 = 256 ;
else
V_21 = 384 ;
}
if ( F_13 ( V_2 ) && ( F_18 ( V_2 ) != V_21 || F_21 ( V_2 ) != V_33 ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_82 , __LINE__ ) ;
return - V_83 ;
}
F_22 ( V_2 , V_33 ) ;
F_19 ( V_2 , V_21 ) ;
if ( F_2 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_37 & V_86 ) ) {
V_140 = V_2 -> V_88 / V_2 -> V_137 / V_21 ;
F_20 ( ( ( V_140 - 1 ) << 8 ) | V_141 , V_2 -> V_5 + V_142 ) ;
F_51 ( & V_2 -> V_40 -> V_41 ,
L_13 ,
V_2 -> V_88 , V_140 , V_21 , V_33 ) ;
}
return 0 ;
}
static int F_52 ( struct V_114 * V_115 ,
int V_143 , struct V_16 * V_17 )
{
int V_144 = ( V_115 -> V_120 == V_145 ) ;
struct V_146 * V_147 = V_115 -> V_148 ;
struct V_1 * V_2 = F_14 ( V_147 -> V_149 ) ;
unsigned long V_75 ;
switch ( V_143 ) {
case V_150 :
case V_151 :
case V_152 :
F_31 ( V_2 -> V_76 , V_75 ) ;
if ( F_50 ( V_2 ) ) {
F_32 ( V_2 -> V_76 , V_75 ) ;
return - V_89 ;
}
if ( V_144 )
F_26 ( V_2 , 1 ) ;
else
F_25 ( V_2 , 1 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
break;
case V_153 :
case V_154 :
case V_155 :
F_31 ( V_2 -> V_76 , V_75 ) ;
if ( V_144 ) {
F_26 ( V_2 , 0 ) ;
F_27 ( V_2 , V_156 ) ;
} else {
F_25 ( V_2 , 0 ) ;
F_27 ( V_2 , V_157 ) ;
}
F_32 ( V_2 -> V_76 , V_75 ) ;
break;
}
return 0 ;
}
static int F_53 ( struct V_16 * V_17 ,
int V_158 , int div )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
switch ( V_158 ) {
case V_159 :
if ( ( F_13 ( V_2 ) && div && ( F_21 ( V_2 ) != div ) )
|| ( V_14 && V_14 -> V_33 && ( V_14 -> V_33 != div ) ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_82 , __LINE__ ) ;
return - V_83 ;
}
V_2 -> V_33 = div ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 ,
L_14 , V_158 ) ;
return - V_89 ;
}
return 0 ;
}
static T_3
F_54 ( struct V_114 * V_115 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
T_1 V_160 = F_3 ( V_2 -> V_5 + V_65 ) ;
T_3 V_161 ;
const struct V_68 * V_69 = V_2 -> V_7 ;
if ( V_115 -> V_120 == V_145 )
V_161 = F_55 ( V_160 ) ;
else if ( F_1 ( V_2 ) )
V_161 = F_56 ( F_3 ( V_2 -> V_5 + V_64 ) ) ;
else
V_161 = ( V_160 >> V_69 -> V_162 ) & 0x7f ;
return V_161 ;
}
static int F_57 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
V_2 -> V_163 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_2 -> V_164 = F_3 ( V_2 -> V_5 + V_10 ) ;
V_2 -> V_165 = F_3 ( V_2 -> V_5 + V_142 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_20 ( V_2 -> V_164 , V_2 -> V_5 + V_10 ) ;
F_20 ( V_2 -> V_163 , V_2 -> V_5 + V_6 ) ;
F_20 ( V_2 -> V_165 , V_2 -> V_5 + V_142 ) ;
return 0 ;
}
static int F_59 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
if ( F_1 ( V_2 ) ) {
F_46 ( V_17 , & V_14 -> V_13 -> V_122 ,
NULL ) ;
} else {
F_46 ( V_17 , & V_2 -> V_122 ,
& V_2 -> V_124 ) ;
if ( V_2 -> V_37 & V_138 )
F_20 ( V_139 , V_2 -> V_5 + V_10 ) ;
if ( V_2 -> V_37 & V_166 )
F_60 ( V_2 -> V_5 ,
V_2 -> V_13 -> V_167 . V_168 ) ;
}
V_2 -> V_21 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_88 = 0 ;
F_31 ( V_2 -> V_76 , V_75 ) ;
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , 0 ) ;
F_27 ( V_2 , V_157 ) ;
F_27 ( V_14 , V_157 ) ;
F_27 ( V_2 , V_156 ) ;
F_32 ( V_2 -> V_76 , V_75 ) ;
if ( ! F_16 ( V_14 ) )
F_30 ( V_17 , V_79 ,
0 , V_80 ) ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_15 ( V_17 ) ;
if ( ! F_1 ( V_2 ) ) {
if ( V_2 -> V_37 & V_138 ) {
F_62 ( V_2 -> V_76 ) ;
F_20 ( 0 , V_2 -> V_5 + V_10 ) ;
F_63 ( V_2 -> V_76 ) ;
}
}
return 0 ;
}
static struct V_1 * F_64 ( struct V_169 * V_40 , bool V_170 )
{
struct V_1 * V_2 ;
int V_171 ;
V_2 = F_65 ( & V_40 -> V_41 , sizeof( struct V_1 ) , V_172 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_40 = V_40 ;
V_2 -> V_3 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_173 . V_174 = 1 ;
V_2 -> V_173 . V_175 = F_59 ;
V_2 -> V_173 . remove = F_61 ;
V_2 -> V_173 . V_176 = & V_177 ;
V_2 -> V_173 . V_178 = F_57 ;
V_2 -> V_173 . V_179 = F_58 ;
V_2 -> V_173 . V_180 . V_181 = 1 ;
V_2 -> V_173 . V_180 . V_182 = 2 ;
V_2 -> V_173 . V_180 . V_183 = V_184 ;
V_2 -> V_173 . V_180 . V_185 = V_186 ;
if ( ! V_170 ) {
V_2 -> V_173 . V_144 . V_181 = 1 ;
V_2 -> V_173 . V_144 . V_182 = 2 ;
V_2 -> V_173 . V_144 . V_183 = V_184 ;
V_2 -> V_173 . V_144 . V_185 = V_186 ;
F_66 ( & V_2 -> V_40 -> V_41 , V_2 ) ;
} else {
V_2 -> V_40 = F_67 ( L_15 , - 1 ) ;
if ( ! V_2 -> V_40 )
return NULL ;
V_2 -> V_40 -> V_41 . V_187 = & V_40 -> V_41 ;
F_68 ( V_2 -> V_40 , V_2 ) ;
V_171 = F_69 ( V_2 -> V_40 ) ;
if ( V_171 < 0 )
return NULL ;
}
return V_2 ;
}
static inline const struct V_188 * F_70 (
struct V_169 * V_40 )
{
if ( F_71 ( V_189 ) && V_40 -> V_41 . V_190 ) {
const struct V_191 * V_192 ;
V_192 = F_72 ( V_193 , V_40 -> V_41 . V_190 ) ;
return V_192 ? V_192 -> V_194 : NULL ;
} else {
return (struct V_188 * )
F_73 ( V_40 ) -> V_195 ;
}
}
static int F_74 ( struct V_196 * V_41 )
{
struct V_1 * V_2 = F_75 ( V_41 ) ;
F_34 ( V_2 -> V_197 ) ;
return 0 ;
}
static int F_76 ( struct V_196 * V_41 )
{
struct V_1 * V_2 = F_75 ( V_41 ) ;
F_40 ( V_2 -> V_197 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
int V_198 ;
for ( V_198 = 0 ; V_198 < V_2 -> V_199 . V_200 ; V_198 ++ ) {
if ( ! F_33 ( V_2 -> V_201 [ V_198 ] ) )
F_78 ( V_2 -> V_201 [ V_198 ] ) ;
}
}
static void F_79 ( struct V_169 * V_40 )
{
struct V_1 * V_2 = F_75 ( & V_40 -> V_41 ) ;
F_80 ( V_40 -> V_41 . V_190 ) ;
F_77 ( V_2 ) ;
}
static int F_81 ( struct V_169 * V_40 )
{
struct V_196 * V_41 = & V_40 -> V_41 ;
struct V_1 * V_2 = F_75 ( V_41 ) ;
const char * V_202 [ 2 ] = { L_5 , L_4 } ;
const char * V_203 [ 2 ] = { NULL } ;
const struct V_68 * V_204 = V_2 -> V_7 ;
struct V_197 * V_205 ;
int V_171 , V_198 ;
if ( ! F_82 ( V_41 -> V_190 , L_16 , NULL ) )
return 0 ;
for ( V_198 = 0 ; V_198 < F_83 ( V_203 ) ; V_198 ++ ) {
V_205 = F_37 ( V_41 , V_202 [ V_198 ] ) ;
if ( F_33 ( V_205 ) )
continue;
V_203 [ V_198 ] = F_84 ( V_205 ) ;
F_35 ( V_205 ) ;
}
if ( ! ( V_2 -> V_37 & V_86 ) ) {
T_1 V_63 = F_3 ( V_2 -> V_5 + V_142 ) ;
F_20 ( V_63 | V_141 , V_2 -> V_5 + V_142 ) ;
V_2 -> V_201 [ V_206 ] = F_85 ( NULL ,
L_17 , V_203 , F_83 ( V_203 ) ,
V_207 | V_208 ,
V_2 -> V_5 + V_6 , V_204 -> V_73 ,
1 , 0 , V_2 -> V_76 ) ;
V_2 -> V_201 [ V_209 ] = F_86 ( NULL ,
L_18 , L_17 ,
V_208 ,
V_2 -> V_5 + V_142 , 8 , 6 , 0 , V_2 -> V_76 ) ;
V_203 [ 0 ] = L_18 ;
V_2 -> V_199 . V_200 = 2 ;
}
F_87 ( V_41 -> V_190 ,
L_19 , 0 , & V_202 [ 0 ] ) ;
V_2 -> V_201 [ V_210 ] = F_88 ( NULL , V_202 [ 0 ] ,
V_203 [ 0 ] , V_208 ,
V_2 -> V_5 + V_6 , V_204 -> V_71 ,
V_211 , V_2 -> V_76 ) ;
V_2 -> V_199 . V_200 += 1 ;
V_2 -> V_199 . V_212 = V_2 -> V_201 ;
V_171 = F_89 ( V_41 -> V_190 , V_213 ,
& V_2 -> V_199 ) ;
if ( V_171 < 0 ) {
F_23 ( V_41 , L_20 , V_171 ) ;
F_77 ( V_2 ) ;
}
return V_171 ;
}
static int F_90 ( struct V_169 * V_40 )
{
struct V_1 * V_3 , * V_13 = NULL ;
struct V_214 * V_215 = V_40 -> V_41 . V_216 ;
struct V_217 * V_218 = NULL ;
struct V_219 * V_220 ;
T_1 V_221 , V_37 = 0 , V_222 = 0 ;
struct V_223 * V_224 = V_40 -> V_41 . V_190 ;
const struct V_188 * V_225 ;
int V_171 ;
V_225 = F_70 ( V_40 ) ;
if ( V_225 -> V_226 == V_227 ) {
V_13 = F_75 ( & V_40 -> V_41 ) ;
if ( ! V_13 ) {
F_23 ( & V_40 -> V_41 , L_21 ) ;
return - V_228 ;
}
V_171 = F_91 ( & V_13 -> V_40 -> V_41 ,
& V_229 ,
& V_13 -> V_173 , 1 ) ;
if ( V_171 != 0 )
return V_171 ;
return F_92 ( & V_40 -> V_41 ,
V_13 -> V_230 ) ;
}
V_3 = F_64 ( V_40 , false ) ;
if ( ! V_3 ) {
F_23 ( & V_40 -> V_41 , L_22 ) ;
return - V_231 ;
}
F_93 ( & V_3 -> V_232 ) ;
V_3 -> V_76 = & V_3 -> V_232 ;
if ( ! V_224 ) {
if ( V_215 == NULL ) {
F_23 ( & V_40 -> V_41 , L_23 ) ;
return - V_89 ;
}
V_3 -> V_122 . V_233 = V_215 -> V_122 ;
V_3 -> V_124 . V_233 = V_215 -> V_124 ;
V_3 -> V_230 = V_215 -> V_234 ;
if ( & V_215 -> type )
V_218 = & V_215 -> type . V_2 ;
if ( V_218 ) {
V_37 = V_218 -> V_37 ;
V_222 = V_218 -> V_222 ;
}
} else {
V_37 = V_225 -> V_37 ;
if ( F_94 ( V_224 , L_24 ,
& V_222 ) ) {
if ( V_37 & V_166 ) {
F_95 ( & V_40 -> V_41 , L_25\
L_26 ) ;
}
}
}
V_220 = F_96 ( V_40 , V_235 , 0 ) ;
V_3 -> V_5 = F_97 ( & V_40 -> V_41 , V_220 ) ;
if ( F_33 ( V_3 -> V_5 ) )
return F_39 ( V_3 -> V_5 ) ;
V_221 = V_220 -> V_236 ;
V_3 -> V_197 = F_98 ( & V_40 -> V_41 , L_27 ) ;
if ( F_33 ( V_3 -> V_197 ) ) {
F_23 ( & V_40 -> V_41 , L_28 ) ;
return F_39 ( V_3 -> V_197 ) ;
}
V_171 = F_40 ( V_3 -> V_197 ) ;
if ( V_171 != 0 ) {
F_23 ( & V_40 -> V_41 , L_29 , V_171 ) ;
return V_171 ;
}
V_3 -> V_122 . V_168 = V_221 + V_237 ;
V_3 -> V_124 . V_168 = V_221 + V_238 ;
V_3 -> V_122 . V_239 = L_30 ;
V_3 -> V_124 . V_239 = L_31 ;
V_3 -> V_122 . V_123 = 4 ;
V_3 -> V_124 . V_123 = 4 ;
V_3 -> V_37 = V_37 ;
V_3 -> V_7 = V_225 -> V_240 ;
if ( V_37 & V_241 )
V_3 -> V_173 . V_180 . V_182 = 6 ;
if ( V_37 & V_242 ) {
V_13 = F_64 ( V_40 , true ) ;
if ( ! V_13 ) {
F_23 ( & V_40 -> V_41 , L_32 ) ;
return - V_231 ;
}
V_13 -> V_76 = & V_3 -> V_232 ;
V_13 -> V_7 = V_3 -> V_7 ;
V_13 -> V_122 . V_168 = V_221 + V_243 ;
V_13 -> V_122 . V_239 = L_33 ;
if ( ! V_224 ) {
V_13 -> V_122 . V_233 = V_215 -> V_244 ;
V_13 -> V_230 = V_215 -> V_234 ;
}
V_13 -> V_122 . V_123 = 4 ;
V_13 -> V_5 = V_3 -> V_5 ;
V_13 -> V_197 = V_3 -> V_197 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_167 . V_168 = V_222 ;
V_13 -> V_3 = V_3 ;
V_3 -> V_13 = V_13 ;
}
if ( V_215 && V_215 -> V_245 && V_215 -> V_245 ( V_40 ) ) {
F_23 ( & V_40 -> V_41 , L_34 ) ;
return - V_89 ;
}
F_91 ( & V_3 -> V_40 -> V_41 ,
& V_229 ,
& V_3 -> V_173 , 1 ) ;
F_99 ( & V_40 -> V_41 ) ;
V_171 = F_92 ( & V_40 -> V_41 , V_3 -> V_230 ) ;
if ( V_171 != 0 )
return V_171 ;
return F_81 ( V_40 ) ;
}
static int F_100 ( struct V_169 * V_40 )
{
struct V_1 * V_2 , * V_14 ;
V_2 = F_75 ( & V_40 -> V_41 ) ;
V_14 = F_5 ( V_2 ) ;
if ( V_14 ) {
V_14 -> V_3 = NULL ;
V_14 -> V_13 = NULL ;
} else {
F_101 ( & V_40 -> V_41 ) ;
}
if ( ! F_1 ( V_2 ) ) {
F_79 ( V_40 ) ;
F_34 ( V_2 -> V_197 ) ;
}
V_2 -> V_3 = NULL ;
V_2 -> V_13 = NULL ;
return 0 ;
}
