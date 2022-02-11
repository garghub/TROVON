static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ? true : false ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 -> V_4 + V_5 ) & V_6 ) ? true : false ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 )
return false ;
V_7 = F_3 ( V_2 -> V_4 + V_8 ) ;
if ( F_1 ( V_2 ) )
V_7 &= V_9 ;
else
V_7 &= V_10 ;
return V_7 ? true : false ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
return F_4 ( V_11 ) ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_5 ( V_2 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 )
return false ;
V_7 = F_3 ( V_2 -> V_4 + V_8 ) & V_13 ;
return V_7 ? true : false ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
return F_7 ( V_11 ) ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) || F_8 ( V_2 ) ;
}
static inline bool F_10 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) || F_5 ( V_2 ) ;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_7 ( V_2 ) ;
}
static inline bool F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 ) || F_10 ( V_2 ) ;
}
static inline struct V_1 * F_13 ( struct V_14 * V_15 )
{
return F_14 ( V_15 ) ;
}
static inline bool F_15 ( struct V_1 * V_2 )
{
if ( V_2 && ( V_2 -> V_16 & V_17 ) )
return true ;
else
return false ;
}
static inline bool F_16 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) && ( V_2 -> V_16 & V_18 ) )
return true ;
else
return false ;
}
static inline unsigned F_17 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( V_2 -> V_20 & V_21 )
V_19 = F_3 ( V_2 -> V_4 + V_5 ) >> V_22 ;
else
V_19 = ( F_3 ( V_2 -> V_4 + V_5 ) >> V_23 ) ;
V_19 &= V_24 ;
switch ( V_19 ) {
case 3 : return 768 ;
case 2 : return 384 ;
case 1 : return 512 ;
default: return 256 ;
}
}
static inline void F_18 ( struct V_1 * V_2 , unsigned V_19 )
{
T_1 V_25 = F_3 ( V_2 -> V_4 + V_5 ) ;
int V_26 ;
if ( V_2 -> V_20 & V_21 )
V_26 = V_22 ;
else
V_26 = V_23 ;
V_25 &= ~ ( V_24 << V_26 ) ;
switch ( V_19 ) {
case 768 :
V_25 |= ( V_27 << V_26 ) ;
break;
case 512 :
V_25 |= ( V_28 << V_26 ) ;
break;
case 384 :
V_25 |= ( V_29 << V_26 ) ;
break;
default:
V_25 |= ( V_30 << V_26 ) ;
break;
}
F_19 ( V_25 , V_2 -> V_4 + V_5 ) ;
}
static inline unsigned F_20 ( struct V_1 * V_2 )
{
T_1 V_31 ;
if ( V_2 -> V_20 & V_21 ) {
V_31 = F_3 ( V_2 -> V_4 + V_5 ) >> V_32 ;
V_31 &= V_33 ;
} else {
V_31 = F_3 ( V_2 -> V_4 + V_5 ) >> V_34 ;
V_31 &= V_35 ;
}
switch ( V_31 ) {
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
static inline void F_21 ( struct V_1 * V_2 , unsigned V_31 )
{
T_1 V_25 = F_3 ( V_2 -> V_4 + V_5 ) ;
int V_36 ;
int V_37 = V_2 -> V_20 & V_21 ;
if ( V_2 -> V_20 & V_21 ) {
V_36 = V_32 ;
V_25 &= ~ ( V_33 << V_36 ) ;
} else {
V_36 = V_34 ;
V_25 &= ~ ( V_35 << V_36 ) ;
}
if ( ! V_37 && V_31 > 48 ) {
F_22 ( & V_2 -> V_38 -> V_39 , L_1 ) ;
return;
}
switch ( V_31 ) {
case 48 :
V_25 |= ( V_40 << V_36 ) ;
break;
case 32 :
V_25 |= ( V_41 << V_36 ) ;
break;
case 24 :
V_25 |= ( V_42 << V_36 ) ;
break;
case 16 :
V_25 |= ( V_43 << V_36 ) ;
break;
case 64 :
V_25 |= ( V_44 << V_36 ) ;
break;
case 96 :
V_25 |= ( V_45 << V_36 ) ;
break;
case 128 :
V_25 |= ( V_46 << V_36 ) ;
break;
case 192 :
V_25 |= ( V_47 << V_36 ) ;
break;
case 256 :
V_25 |= ( V_48 << V_36 ) ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_2 ) ;
return;
}
F_19 ( V_25 , V_2 -> V_4 + V_5 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_49 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_49 = ( V_49 >> 13 ) & 0x3 ;
switch ( V_49 ) {
case 2 : return 24 ;
case 1 : return 8 ;
default: return 16 ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_50 )
{
void T_2 * V_4 = V_2 -> V_4 ;
T_1 V_51 = F_3 ( V_4 + V_8 ) ;
T_1 V_25 = F_3 ( V_4 + V_5 ) & ~ V_52 ;
if ( V_50 ) {
V_51 |= V_53 ;
V_51 &= ~ V_54 ;
if ( F_1 ( V_2 ) ) {
V_51 |= V_9 ;
V_51 &= ~ V_55 ;
} else {
V_51 |= V_10 ;
V_51 &= ~ V_56 ;
}
if ( F_9 ( V_2 ) )
V_25 |= V_57 ;
else
V_25 |= V_58 ;
} else {
if ( F_1 ( V_2 ) ) {
V_51 |= V_55 ;
V_51 &= ~ V_9 ;
} else {
V_51 |= V_56 ;
V_51 &= ~ V_10 ;
}
if ( F_5 ( V_2 ) ) {
F_19 ( V_51 , V_4 + V_8 ) ;
return;
}
V_51 |= V_54 ;
if ( F_9 ( V_2 ) )
V_25 |= V_59 ;
else
V_51 &= ~ V_53 ;
}
F_19 ( V_25 , V_4 + V_5 ) ;
F_19 ( V_51 , V_4 + V_8 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_50 )
{
void T_2 * V_4 = V_2 -> V_4 ;
T_1 V_51 = F_3 ( V_4 + V_8 ) ;
T_1 V_25 = F_3 ( V_4 + V_5 ) & ~ V_52 ;
if ( V_50 ) {
V_51 |= V_13 | V_53 ;
V_51 &= ~ ( V_60 | V_61 ) ;
if ( F_6 ( V_2 ) )
V_25 |= V_57 ;
else
V_25 |= V_59 ;
} else {
V_51 |= V_60 | V_61 ;
V_51 &= ~ V_13 ;
if ( F_6 ( V_2 ) )
V_25 |= V_58 ;
else
V_51 &= ~ V_53 ;
}
F_19 ( V_25 , V_4 + V_5 ) ;
F_19 ( V_51 , V_4 + V_8 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , T_1 V_62 )
{
void T_2 * V_63 ;
T_1 V_64 ;
if ( ! V_2 )
return;
if ( F_1 ( V_2 ) )
V_63 = V_2 -> V_4 + V_65 ;
else
V_63 = V_2 -> V_4 + V_66 ;
F_19 ( F_3 ( V_63 ) | V_62 , V_63 ) ;
V_64 = F_27 ( 1 ) / 1000 ;
while ( -- V_64 )
F_28 () ;
F_19 ( F_3 ( V_63 ) & ~ V_62 , V_63 ) ;
}
static int F_29 ( struct V_14 * V_15 ,
int V_67 , unsigned int V_19 , int V_68 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
T_1 V_25 = F_3 ( V_2 -> V_4 + V_5 ) ;
switch ( V_67 ) {
case V_69 :
if ( V_68 == V_70 )
V_19 = 0 ;
if ( ( V_19 && V_11 -> V_19 && ( V_11 -> V_19 != V_19 ) ) ||
( F_12 ( V_2 ) &&
( ( ( V_68 == V_70 )
&& ! ( V_25 & V_71 ) ) ||
( ( V_68 == V_72 )
&& ( V_25 & V_71 ) ) ) ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_3 , V_73 , __LINE__ ) ;
return - V_74 ;
}
if ( V_68 == V_70 )
V_25 |= V_71 ;
else
V_25 &= ~ V_71 ;
V_2 -> V_19 = V_19 ;
break;
case V_75 :
case V_76 :
if ( ( V_2 -> V_20 & V_77 )
|| ( V_67 == V_75 ) )
V_67 = 0 ;
else
V_67 = 1 ;
if ( ! F_12 ( V_2 ) ) {
if ( V_2 -> V_78 ) {
if ( ( V_67 && ! ( V_25 & V_79 ) ) ||
( ! V_67 && ( V_25 & V_79 ) ) ) {
F_30 ( V_2 -> V_78 ) ;
F_31 ( V_2 -> V_78 ) ;
} else {
V_2 -> V_80 =
F_32 ( V_2 -> V_78 ) ;
return 0 ;
}
}
if ( V_67 )
V_2 -> V_78 = F_33 ( & V_2 -> V_38 -> V_39 ,
L_4 ) ;
else
V_2 -> V_78 = F_33 ( & V_2 -> V_38 -> V_39 ,
L_5 ) ;
F_34 ( V_2 -> V_78 ) ;
V_2 -> V_80 = F_32 ( V_2 -> V_78 ) ;
if ( V_11 ) {
V_11 -> V_78 = V_2 -> V_78 ;
V_11 -> V_80 = V_2 -> V_80 ;
}
} else if ( ( ! V_67 && ( V_25 & V_79 ) )
|| ( V_67 && ! ( V_25 & V_79 ) ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_3 , V_73 , __LINE__ ) ;
return - V_74 ;
} else {
V_2 -> V_78 = V_11 -> V_78 ;
V_2 -> V_80 = V_11 -> V_80 ;
return 0 ;
}
if ( V_67 == 0 )
V_25 &= ~ V_79 ;
else
V_25 |= V_79 ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_6 ) ;
return - V_81 ;
}
F_19 ( V_25 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_14 * V_15 ,
unsigned int V_82 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_25 = F_3 ( V_2 -> V_4 + V_5 ) ;
int V_83 , V_84 , V_85 , V_86 ;
T_1 V_87 = 0 ;
if ( V_2 -> V_20 & V_21 ) {
V_83 = V_88 ;
V_84 = V_89 ;
} else {
V_83 = V_90 ;
V_84 = V_91 ;
}
V_85 = V_92 << V_84 ;
V_86 = V_93 << V_83 ;
switch ( V_82 & V_94 ) {
case V_95 :
V_87 |= V_86 ;
V_87 |= ( V_96 << V_84 ) ;
break;
case V_97 :
V_87 |= V_86 ;
V_87 |= ( V_98 << V_84 ) ;
break;
case V_99 :
V_87 |= ( V_100 << V_84 ) ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_7 ) ;
return - V_81 ;
}
switch ( V_82 & V_101 ) {
case V_102 :
break;
case V_103 :
if ( V_87 & V_86 )
V_87 &= ~ V_86 ;
else
V_87 |= V_86 ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_8 ) ;
return - V_81 ;
}
switch ( V_82 & V_104 ) {
case V_105 :
V_87 |= V_6 ;
break;
case V_106 :
if ( V_2 -> V_80 == 0 )
F_29 ( V_15 , V_75 ,
0 , V_70 ) ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_9 ) ;
return - V_81 ;
}
if ( F_12 ( V_2 ) &&
( ( V_25 & ( V_85 | V_86 | V_6 ) ) != V_87 ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_3 , V_73 , __LINE__ ) ;
return - V_74 ;
}
V_25 &= ~ ( V_85 | V_86 | V_6 ) ;
V_25 |= V_87 ;
F_19 ( V_25 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int F_36 ( struct V_107 * V_108 ,
struct V_109 * V_110 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_25 = F_3 ( V_2 -> V_4 + V_5 ) ;
if ( ! F_1 ( V_2 ) )
V_25 &= ~ ( V_111 | V_112 ) ;
switch ( F_37 ( V_110 ) ) {
case 6 :
V_25 |= V_111 ;
case 4 :
V_25 |= V_112 ;
break;
case 2 :
if ( V_108 -> V_113 == V_114 )
V_2 -> V_115 . V_116 = 4 ;
else
V_2 -> V_117 . V_116 = 4 ;
break;
case 1 :
if ( V_108 -> V_113 == V_114 )
V_2 -> V_115 . V_116 = 2 ;
else
V_2 -> V_117 . V_116 = 2 ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_10 ,
F_37 ( V_110 ) ) ;
return - V_81 ;
}
if ( F_1 ( V_2 ) )
V_25 &= ~ V_118 ;
else
V_25 &= ~ V_119 ;
if ( F_16 ( V_2 ) )
V_25 &= ~ V_120 ;
switch ( F_38 ( V_110 ) ) {
case V_121 :
if ( F_1 ( V_2 ) )
V_25 |= V_122 ;
else
V_25 |= V_123 ;
if ( F_16 ( V_2 ) )
V_25 |= V_124 ;
break;
case V_125 :
if ( F_1 ( V_2 ) )
V_25 |= V_126 ;
else
V_25 |= V_127 ;
if ( F_16 ( V_2 ) )
V_25 |= V_128 ;
break;
case V_129 :
if ( F_1 ( V_2 ) )
V_25 |= V_130 ;
else
V_25 |= V_131 ;
if ( F_16 ( V_2 ) )
V_25 |= V_132 ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 , L_11 ,
F_38 ( V_110 ) ) ;
return - V_81 ;
}
F_19 ( V_25 , V_2 -> V_4 + V_5 ) ;
F_39 ( V_15 , & V_2 -> V_115 , & V_2 -> V_117 ) ;
V_2 -> V_133 = F_40 ( V_110 ) ;
return 0 ;
}
static int F_41 ( struct V_107 * V_108 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned long V_134 ;
F_42 ( & V_135 , V_134 ) ;
V_2 -> V_16 |= V_17 ;
if ( F_16 ( V_11 ) )
V_2 -> V_16 &= ~ V_18 ;
else
V_2 -> V_16 |= V_18 ;
V_2 -> V_80 = 0 ;
if ( ! F_12 ( V_2 ) && ( V_2 -> V_20 & V_136 ) )
F_19 ( V_137 , V_2 -> V_4 + V_8 ) ;
F_43 ( & V_135 , V_134 ) ;
return 0 ;
}
static void F_44 ( struct V_107 * V_108 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned long V_134 ;
F_42 ( & V_135 , V_134 ) ;
V_2 -> V_16 &= ~ V_17 ;
V_2 -> V_16 &= ~ V_18 ;
if ( F_15 ( V_11 ) )
V_11 -> V_16 |= V_18 ;
V_2 -> V_19 = 0 ;
V_2 -> V_31 = 0 ;
F_43 ( & V_135 , V_134 ) ;
if ( ! F_15 ( V_11 ) )
F_29 ( V_15 , V_69 ,
0 , V_70 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned V_19 , V_31 , V_49 ;
T_1 V_138 ;
V_49 = F_23 ( V_2 ) ;
V_31 = V_2 -> V_31 ;
if ( ! V_31 && V_11 )
V_31 = V_11 -> V_31 ;
if ( ! V_31 )
V_31 = V_49 * 2 ;
V_19 = V_2 -> V_19 ;
if ( ! V_19 && V_11 )
V_19 = V_11 -> V_19 ;
if ( ( V_19 == 256 || V_19 == 512 ) && ( V_49 == 24 ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_12 , V_19 ) ;
return - V_81 ;
}
if ( ! V_19 ) {
if ( V_31 == 16 || V_31 == 32 )
V_19 = 256 ;
else
V_19 = 384 ;
}
if ( F_12 ( V_2 ) && ( F_17 ( V_2 ) != V_19 || F_20 ( V_2 ) != V_31 ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_3 , V_73 , __LINE__ ) ;
return - V_74 ;
}
F_21 ( V_2 , V_31 ) ;
F_18 ( V_2 , V_19 ) ;
if ( F_2 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_20 & V_77 ) ) {
V_138 = V_2 -> V_80 / V_2 -> V_133 / V_19 ;
F_19 ( ( ( V_138 - 1 ) << 8 ) | V_139 , V_2 -> V_4 + V_140 ) ;
F_46 ( & V_2 -> V_38 -> V_39 ,
L_13 ,
V_2 -> V_80 , V_138 , V_19 , V_31 ) ;
}
return 0 ;
}
static int F_47 ( struct V_107 * V_108 ,
int V_141 , struct V_14 * V_15 )
{
int V_142 = ( V_108 -> V_113 == V_143 ) ;
struct V_144 * V_145 = V_108 -> V_146 ;
struct V_1 * V_2 = F_13 ( V_145 -> V_147 ) ;
unsigned long V_134 ;
switch ( V_141 ) {
case V_148 :
case V_149 :
case V_150 :
F_48 ( V_134 ) ;
if ( F_45 ( V_2 ) ) {
F_49 ( V_134 ) ;
return - V_81 ;
}
if ( V_142 )
F_25 ( V_2 , 1 ) ;
else
F_24 ( V_2 , 1 ) ;
F_49 ( V_134 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
F_48 ( V_134 ) ;
if ( V_142 ) {
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , V_154 ) ;
} else {
F_24 ( V_2 , 0 ) ;
F_26 ( V_2 , V_155 ) ;
}
F_49 ( V_134 ) ;
break;
}
return 0 ;
}
static int F_50 ( struct V_14 * V_15 ,
int V_156 , int div )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
switch ( V_156 ) {
case V_157 :
if ( ( F_12 ( V_2 ) && div && ( F_20 ( V_2 ) != div ) )
|| ( V_11 && V_11 -> V_31 && ( V_11 -> V_31 != div ) ) ) {
F_22 ( & V_2 -> V_38 -> V_39 ,
L_3 , V_73 , __LINE__ ) ;
return - V_74 ;
}
V_2 -> V_31 = div ;
break;
default:
F_22 ( & V_2 -> V_38 -> V_39 ,
L_14 , V_156 ) ;
return - V_81 ;
}
return 0 ;
}
static T_3
F_51 ( struct V_107 * V_108 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_158 = F_3 ( V_2 -> V_4 + V_66 ) ;
T_3 V_159 ;
if ( V_108 -> V_113 == V_143 )
V_159 = F_52 ( V_158 ) ;
else if ( F_1 ( V_2 ) )
V_159 = F_53 ( F_3 ( V_2 -> V_4 + V_65 ) ) ;
else
V_159 = F_54 ( V_158 ) ;
return V_159 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
if ( V_15 -> V_7 ) {
V_2 -> V_160 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_2 -> V_161 = F_3 ( V_2 -> V_4 + V_8 ) ;
V_2 -> V_162 = F_3 ( V_2 -> V_4 + V_140 ) ;
}
return 0 ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
if ( V_15 -> V_7 ) {
F_19 ( V_2 -> V_161 , V_2 -> V_4 + V_8 ) ;
F_19 ( V_2 -> V_160 , V_2 -> V_4 + V_5 ) ;
F_19 ( V_2 -> V_162 , V_2 -> V_4 + V_140 ) ;
}
return 0 ;
}
static int F_57 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( V_11 && V_11 -> V_163 ) {
F_39 ( V_15 , & V_11 -> V_12 -> V_115 ,
NULL ) ;
goto V_164;
}
V_2 -> V_4 = F_58 ( V_2 -> V_165 , 0x100 ) ;
if ( V_2 -> V_4 == NULL ) {
F_22 ( & V_2 -> V_38 -> V_39 , L_15 ) ;
return - V_166 ;
}
V_2 -> V_163 = F_33 ( & V_2 -> V_38 -> V_39 , L_16 ) ;
if ( F_59 ( V_2 -> V_163 ) ) {
F_22 ( & V_2 -> V_38 -> V_39 , L_17 ) ;
F_60 ( V_2 -> V_4 ) ;
return - V_167 ;
}
F_34 ( V_2 -> V_163 ) ;
F_39 ( V_15 , & V_2 -> V_115 , & V_2 -> V_117 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_2 -> V_4 ;
V_11 -> V_163 = V_2 -> V_163 ;
}
if ( V_2 -> V_20 & V_136 )
F_19 ( V_137 , V_2 -> V_4 + V_8 ) ;
if ( V_2 -> V_20 & V_168 )
F_61 ( V_2 -> V_4 ,
V_2 -> V_12 -> V_169 . V_170 ) ;
V_164:
V_2 -> V_19 = 0 ;
V_2 -> V_31 = 0 ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , V_155 ) ;
F_26 ( V_11 , V_155 ) ;
F_26 ( V_2 , V_154 ) ;
if ( ! F_15 ( V_11 ) )
F_29 ( V_15 , V_69 ,
0 , V_70 ) ;
return 0 ;
}
static int F_62 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( ! V_11 || ! V_11 -> V_163 ) {
if ( V_2 -> V_20 & V_136 )
F_19 ( 0 , V_2 -> V_4 + V_8 ) ;
F_30 ( V_2 -> V_163 ) ;
F_31 ( V_2 -> V_163 ) ;
F_60 ( V_2 -> V_4 ) ;
}
V_2 -> V_163 = NULL ;
return 0 ;
}
static struct V_1 * F_63 ( struct V_171 * V_38 , bool V_172 )
{
struct V_1 * V_2 ;
int V_173 ;
V_2 = F_64 ( & V_38 -> V_39 , sizeof( struct V_1 ) , V_174 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_38 = V_38 ;
V_2 -> V_3 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_175 . V_176 = 1 ;
V_2 -> V_175 . V_177 = F_57 ;
V_2 -> V_175 . remove = F_62 ;
V_2 -> V_175 . V_178 = & V_179 ;
V_2 -> V_175 . V_180 = F_55 ;
V_2 -> V_175 . V_181 = F_56 ;
V_2 -> V_175 . V_182 . V_183 = 1 ;
V_2 -> V_175 . V_182 . V_184 = 2 ;
V_2 -> V_175 . V_182 . V_185 = V_186 ;
V_2 -> V_175 . V_182 . V_187 = V_188 ;
if ( ! V_172 ) {
V_2 -> V_175 . V_142 . V_183 = 1 ;
V_2 -> V_175 . V_142 . V_184 = 2 ;
V_2 -> V_175 . V_142 . V_185 = V_186 ;
V_2 -> V_175 . V_142 . V_187 = V_188 ;
F_65 ( & V_2 -> V_38 -> V_39 , V_2 ) ;
} else {
V_2 -> V_38 = F_66 ( L_18 , - 1 ) ;
if ( ! V_2 -> V_38 )
return NULL ;
V_2 -> V_38 -> V_39 . V_189 = & V_38 -> V_39 ;
F_67 ( V_2 -> V_38 , V_2 ) ;
V_173 = F_68 ( V_2 -> V_38 ) ;
if ( V_173 < 0 )
return NULL ;
}
return V_2 ;
}
static inline const struct V_190 * F_69 (
struct V_171 * V_38 )
{
#ifdef F_70
if ( V_38 -> V_39 . V_191 ) {
const struct V_192 * V_193 ;
V_193 = F_71 ( V_194 , V_38 -> V_39 . V_191 ) ;
return V_193 -> V_195 ;
} else
#endif
return (struct V_190 * )
F_72 ( V_38 ) -> V_196 ;
}
static int F_73 ( struct V_197 * V_39 )
{
struct V_1 * V_2 = F_74 ( V_39 ) ;
F_30 ( V_2 -> V_163 ) ;
return 0 ;
}
static int F_75 ( struct V_197 * V_39 )
{
struct V_1 * V_2 = F_74 ( V_39 ) ;
F_34 ( V_2 -> V_163 ) ;
return 0 ;
}
static int F_76 ( struct V_171 * V_38 )
{
struct V_1 * V_3 , * V_12 = NULL ;
struct V_198 * V_199 = V_38 -> V_39 . V_200 ;
struct V_201 * V_202 = NULL ;
struct V_203 * V_204 ;
T_1 V_205 , V_20 = 0 , V_206 = 0 ;
struct V_207 * V_208 = V_38 -> V_39 . V_191 ;
const struct V_190 * V_209 ;
int V_173 = 0 ;
V_209 = F_69 ( V_38 ) ;
if ( V_209 -> V_210 == V_211 ) {
V_12 = F_74 ( & V_38 -> V_39 ) ;
if ( ! V_12 ) {
F_22 ( & V_38 -> V_39 , L_19 ) ;
return - V_212 ;
}
F_77 ( & V_12 -> V_38 -> V_39 ,
& V_213 ,
& V_12 -> V_175 , 1 ) ;
F_78 ( & V_38 -> V_39 ) ;
return 0 ;
}
V_3 = F_63 ( V_38 , false ) ;
if ( ! V_3 ) {
F_22 ( & V_38 -> V_39 , L_20 ) ;
return - V_214 ;
}
if ( ! V_208 ) {
V_204 = F_79 ( V_38 , V_215 , 0 ) ;
if ( ! V_204 ) {
F_22 ( & V_38 -> V_39 ,
L_21 ) ;
return - V_166 ;
}
V_3 -> V_115 . V_216 = V_204 -> V_217 ;
V_204 = F_79 ( V_38 , V_215 , 1 ) ;
if ( ! V_204 ) {
F_22 ( & V_38 -> V_39 ,
L_22 ) ;
return - V_166 ;
}
V_3 -> V_117 . V_216 = V_204 -> V_217 ;
if ( V_199 == NULL ) {
F_22 ( & V_38 -> V_39 , L_23 ) ;
return - V_81 ;
}
if ( & V_199 -> type )
V_202 = & V_199 -> type . V_2 ;
if ( V_202 ) {
V_20 = V_202 -> V_20 ;
V_206 = V_202 -> V_206 ;
}
} else {
V_20 = V_209 -> V_20 ;
if ( F_80 ( V_208 , L_24 ,
& V_206 ) ) {
if ( V_20 & V_168 ) {
F_22 ( & V_38 -> V_39 , L_25\
L_26 ) ;
return - V_81 ;
}
}
}
V_204 = F_79 ( V_38 , V_218 , 0 ) ;
if ( ! V_204 ) {
F_22 ( & V_38 -> V_39 , L_27 ) ;
return - V_166 ;
}
if ( ! F_81 ( V_204 -> V_217 , F_82 ( V_204 ) ,
L_28 ) ) {
F_22 ( & V_38 -> V_39 , L_29 ) ;
return - V_219 ;
}
V_205 = V_204 -> V_217 ;
V_3 -> V_115 . V_170 = V_205 + V_220 ;
V_3 -> V_117 . V_170 = V_205 + V_221 ;
V_3 -> V_115 . V_222 =
(struct V_223 * ) & V_3 -> V_115 ;
V_3 -> V_115 . V_224 = L_30 ;
V_3 -> V_117 . V_222 =
(struct V_223 * ) & V_3 -> V_117 ;
V_3 -> V_117 . V_224 = L_31 ;
V_3 -> V_115 . V_116 = 4 ;
V_3 -> V_117 . V_116 = 4 ;
V_3 -> V_165 = V_205 ;
V_3 -> V_20 = V_20 ;
if ( V_20 & V_225 )
V_3 -> V_175 . V_182 . V_184 = 6 ;
if ( V_20 & V_168 ) {
V_12 = F_63 ( V_38 , true ) ;
if ( ! V_12 ) {
F_22 ( & V_38 -> V_39 , L_32 ) ;
V_173 = - V_214 ;
goto V_226;
}
V_12 -> V_115 . V_170 = V_205 + V_227 ;
V_12 -> V_115 . V_222 =
(struct V_223 * ) & V_12 -> V_115 ;
V_12 -> V_115 . V_224 = L_33 ;
if ( ! V_208 ) {
V_204 = F_79 ( V_38 , V_215 , 2 ) ;
if ( V_204 )
V_12 -> V_115 . V_216 = V_204 -> V_217 ;
}
V_12 -> V_115 . V_116 = 4 ;
V_12 -> V_165 = V_205 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_169 . V_170 = V_206 ;
V_12 -> V_3 = V_3 ;
V_3 -> V_12 = V_12 ;
}
if ( V_199 && V_199 -> V_228 && V_199 -> V_228 ( V_38 ) ) {
F_22 ( & V_38 -> V_39 , L_34 ) ;
V_173 = - V_81 ;
goto V_226;
}
F_77 ( & V_3 -> V_38 -> V_39 ,
& V_213 ,
& V_3 -> V_175 , 1 ) ;
F_83 ( & V_38 -> V_39 ) ;
F_78 ( & V_38 -> V_39 ) ;
return 0 ;
V_226:
if ( V_204 )
F_84 ( V_205 , F_82 ( V_204 ) ) ;
return V_173 ;
}
static int F_85 ( struct V_171 * V_38 )
{
struct V_1 * V_2 , * V_11 ;
struct V_203 * V_204 ;
V_2 = F_74 ( & V_38 -> V_39 ) ;
V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( V_11 ) {
V_11 -> V_3 = NULL ;
V_11 -> V_12 = NULL ;
} else {
F_86 ( & V_38 -> V_39 ) ;
V_204 = F_79 ( V_38 , V_218 , 0 ) ;
if ( V_204 )
F_84 ( V_204 -> V_217 , F_82 ( V_204 ) ) ;
}
V_2 -> V_3 = NULL ;
V_2 -> V_12 = NULL ;
F_87 ( & V_38 -> V_39 ) ;
return 0 ;
}
