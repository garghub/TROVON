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
int V_76 = 0 ;
F_31 ( V_17 -> V_41 ) ;
F_32 ( V_2 -> V_77 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
switch ( V_66 ) {
case V_78 :
V_74 = V_79 ;
V_63 = V_67 ;
break;
case V_80 :
V_74 = 1 << V_69 -> V_71 ;
if ( V_67 == V_81 )
V_21 = 0 ;
if ( ( V_21 && V_14 && V_14 -> V_21 && ( V_14 -> V_21 != V_21 ) ) ||
( F_13 ( V_2 ) &&
( ( ( V_67 == V_81 )
&& ! ( V_4 & V_70 ) ) ||
( ( V_67 == V_82 )
&& ( V_4 & V_70 ) ) ) ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_83 , __LINE__ ) ;
V_76 = - V_84 ;
goto V_85;
}
if ( V_67 == V_81 )
V_63 = 1 << V_69 -> V_71 ;
V_2 -> V_21 = V_21 ;
break;
case V_86 :
case V_87 :
V_74 = 1 << V_69 -> V_73 ;
if ( ( V_2 -> V_37 & V_88 )
|| ( V_66 == V_86 ) )
V_66 = 0 ;
else
V_66 = 1 ;
if ( ! F_13 ( V_2 ) ) {
if ( V_2 -> V_89 && ! F_34 ( V_2 -> V_89 ) ) {
if ( ( V_66 && ! ( V_4 & V_72 ) ) ||
( ! V_66 && ( V_4 & V_72 ) ) ) {
F_35 ( V_2 -> V_89 ) ;
F_36 ( V_2 -> V_89 ) ;
} else {
V_2 -> V_90 =
F_37 ( V_2 -> V_89 ) ;
goto V_91;
}
}
if ( V_66 )
V_2 -> V_89 = F_38 ( & V_2 -> V_40 -> V_41 ,
L_4 ) ;
else
V_2 -> V_89 = F_38 ( & V_2 -> V_40 -> V_41 ,
L_5 ) ;
if ( F_39 ( F_34 ( V_2 -> V_89 ) ) ) {
V_76 = F_40 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
goto V_85;
}
V_76 = F_41 ( V_2 -> V_89 ) ;
if ( V_76 )
goto V_85;
V_2 -> V_90 = F_37 ( V_2 -> V_89 ) ;
if ( V_14 ) {
V_14 -> V_89 = V_2 -> V_89 ;
V_14 -> V_90 = V_2 -> V_90 ;
}
} else if ( ( ! V_66 && ( V_4 & V_72 ) )
|| ( V_66 && ! ( V_4 & V_72 ) ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_83 , __LINE__ ) ;
V_76 = - V_84 ;
goto V_85;
} else {
V_2 -> V_89 = V_14 -> V_89 ;
V_2 -> V_90 = V_14 -> V_90 ;
goto V_91;
}
if ( V_66 == 1 )
V_63 = 1 << V_69 -> V_73 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_6 ) ;
V_76 = - V_92 ;
goto V_85;
}
F_32 ( V_2 -> V_77 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 = ( V_4 & ~ V_74 ) | V_63 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
V_91:
F_42 ( V_17 -> V_41 ) ;
return 0 ;
V_85:
F_42 ( V_17 -> V_41 ) ;
return V_76 ;
}
static int F_43 ( struct V_16 * V_17 ,
unsigned int V_93 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
int V_94 , V_95 , V_96 , V_97 , V_98 ;
T_1 V_4 , V_99 = 0 ;
unsigned long V_75 ;
V_94 = V_2 -> V_7 -> V_100 ;
V_95 = V_2 -> V_7 -> V_101 ;
V_98 = 1 << V_2 -> V_7 -> V_8 ;
V_96 = V_102 << V_95 ;
V_97 = V_103 << V_94 ;
switch ( V_93 & V_104 ) {
case V_105 :
V_99 |= V_97 ;
V_99 |= ( V_106 << V_95 ) ;
break;
case V_107 :
V_99 |= V_97 ;
V_99 |= ( V_108 << V_95 ) ;
break;
case V_109 :
V_99 |= ( V_110 << V_95 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_7 ) ;
return - V_92 ;
}
switch ( V_93 & V_111 ) {
case V_112 :
break;
case V_113 :
if ( V_99 & V_97 )
V_99 &= ~ V_97 ;
else
V_99 |= V_97 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_8 ) ;
return - V_92 ;
}
switch ( V_93 & V_114 ) {
case V_115 :
V_99 |= V_98 ;
break;
case V_116 :
if ( V_2 -> V_90 == 0 )
F_30 ( V_17 , V_86 ,
0 , V_81 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_9 ) ;
return - V_92 ;
}
F_31 ( V_17 -> V_41 ) ;
F_32 ( V_2 -> V_77 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
if ( F_13 ( V_2 ) &&
( ( V_4 & ( V_96 | V_97 | V_98 ) ) != V_99 ) ) {
F_33 ( V_2 -> V_77 , V_75 ) ;
F_42 ( V_17 -> V_41 ) ;
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_83 , __LINE__ ) ;
return - V_84 ;
}
V_4 &= ~ ( V_96 | V_97 | V_98 ) ;
V_4 |= V_99 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
F_42 ( V_17 -> V_41 ) ;
return 0 ;
}
static int F_44 ( struct V_117 * V_118 ,
struct V_119 * V_120 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
T_1 V_4 , V_74 = 0 , V_63 = 0 ;
unsigned long V_75 ;
F_39 ( ! F_45 ( V_17 -> V_41 ) ) ;
if ( ! F_1 ( V_2 ) )
V_74 |= ( V_121 | V_122 ) ;
switch ( F_46 ( V_120 ) ) {
case 6 :
V_63 |= V_121 ;
case 4 :
V_63 |= V_122 ;
break;
case 2 :
if ( V_118 -> V_123 == V_124 )
V_2 -> V_125 . V_126 = 4 ;
else
V_2 -> V_127 . V_126 = 4 ;
break;
case 1 :
if ( V_118 -> V_123 == V_124 )
V_2 -> V_125 . V_126 = 2 ;
else
V_2 -> V_127 . V_126 = 2 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_10 ,
F_46 ( V_120 ) ) ;
return - V_92 ;
}
if ( F_1 ( V_2 ) )
V_74 |= V_128 ;
else
V_74 |= V_129 ;
if ( F_17 ( V_2 ) )
V_74 |= V_130 ;
switch ( F_47 ( V_120 ) ) {
case 8 :
if ( F_1 ( V_2 ) )
V_63 |= V_131 ;
else
V_63 |= V_132 ;
if ( F_17 ( V_2 ) )
V_63 |= V_133 ;
break;
case 16 :
if ( F_1 ( V_2 ) )
V_63 |= V_134 ;
else
V_63 |= V_135 ;
if ( F_17 ( V_2 ) )
V_63 |= V_136 ;
break;
case 24 :
if ( F_1 ( V_2 ) )
V_63 |= V_137 ;
else
V_63 |= V_138 ;
if ( F_17 ( V_2 ) )
V_63 |= V_139 ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 , L_11 ,
F_48 ( V_120 ) ) ;
return - V_92 ;
}
F_32 ( V_2 -> V_77 , V_75 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 = ( V_4 & ~ V_74 ) | V_63 ;
F_20 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
F_49 ( V_17 , & V_2 -> V_125 , & V_2 -> V_127 ) ;
V_2 -> V_140 = F_50 ( V_120 ) ;
return 0 ;
}
static int F_51 ( struct V_117 * V_118 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
F_31 ( V_17 -> V_41 ) ;
F_32 ( & V_77 , V_75 ) ;
V_2 -> V_18 |= V_19 ;
if ( F_17 ( V_14 ) )
V_2 -> V_18 &= ~ V_20 ;
else
V_2 -> V_18 |= V_20 ;
if ( ! F_13 ( V_2 ) && ( V_2 -> V_37 & V_141 ) )
F_20 ( V_142 , V_2 -> V_5 + V_10 ) ;
F_33 ( & V_77 , V_75 ) ;
return 0 ;
}
static void F_52 ( struct V_117 * V_118 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
F_32 ( & V_77 , V_75 ) ;
V_2 -> V_18 &= ~ V_19 ;
V_2 -> V_18 &= ~ V_20 ;
if ( F_16 ( V_14 ) )
V_14 -> V_18 |= V_20 ;
V_2 -> V_21 = 0 ;
V_2 -> V_33 = 0 ;
F_33 ( & V_77 , V_75 ) ;
F_42 ( V_17 -> V_41 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned V_21 , V_33 , V_51 ;
T_1 V_143 ;
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
return - V_92 ;
}
if ( ! V_21 ) {
if ( V_33 == 16 || V_33 == 32 )
V_21 = 256 ;
else
V_21 = 384 ;
}
if ( F_13 ( V_2 ) && ( F_18 ( V_2 ) != V_21 || F_21 ( V_2 ) != V_33 ) ) {
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_83 , __LINE__ ) ;
return - V_84 ;
}
F_22 ( V_2 , V_33 ) ;
F_19 ( V_2 , V_21 ) ;
if ( F_2 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_37 & V_88 ) ) {
V_143 = V_2 -> V_90 / V_2 -> V_140 / V_21 ;
F_20 ( ( ( V_143 - 1 ) << 8 ) | V_144 , V_2 -> V_5 + V_145 ) ;
F_54 ( & V_2 -> V_40 -> V_41 ,
L_13 ,
V_2 -> V_90 , V_143 , V_21 , V_33 ) ;
}
return 0 ;
}
static int F_55 ( struct V_117 * V_118 ,
int V_146 , struct V_16 * V_17 )
{
int V_147 = ( V_118 -> V_123 == V_148 ) ;
struct V_149 * V_150 = V_118 -> V_151 ;
struct V_1 * V_2 = F_14 ( V_150 -> V_152 ) ;
unsigned long V_75 ;
switch ( V_146 ) {
case V_153 :
case V_154 :
case V_155 :
F_31 ( V_17 -> V_41 ) ;
F_32 ( V_2 -> V_77 , V_75 ) ;
if ( F_53 ( V_2 ) ) {
F_33 ( V_2 -> V_77 , V_75 ) ;
return - V_92 ;
}
if ( V_147 )
F_26 ( V_2 , 1 ) ;
else
F_25 ( V_2 , 1 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
break;
case V_156 :
case V_157 :
case V_158 :
F_32 ( V_2 -> V_77 , V_75 ) ;
if ( V_147 ) {
F_26 ( V_2 , 0 ) ;
F_27 ( V_2 , V_159 ) ;
} else {
F_25 ( V_2 , 0 ) ;
F_27 ( V_2 , V_160 ) ;
}
F_33 ( V_2 -> V_77 , V_75 ) ;
F_42 ( V_17 -> V_41 ) ;
break;
}
return 0 ;
}
static int F_56 ( struct V_16 * V_17 ,
int V_161 , int div )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
switch ( V_161 ) {
case V_162 :
F_31 ( V_17 -> V_41 ) ;
if ( ( F_13 ( V_2 ) && div && ( F_21 ( V_2 ) != div ) )
|| ( V_14 && V_14 -> V_33 && ( V_14 -> V_33 != div ) ) ) {
F_42 ( V_17 -> V_41 ) ;
F_23 ( & V_2 -> V_40 -> V_41 ,
L_3 , V_83 , __LINE__ ) ;
return - V_84 ;
}
V_2 -> V_33 = div ;
F_42 ( V_17 -> V_41 ) ;
break;
default:
F_23 ( & V_2 -> V_40 -> V_41 ,
L_14 , V_161 ) ;
return - V_92 ;
}
return 0 ;
}
static T_3
F_57 ( struct V_117 * V_118 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
T_1 V_163 = F_3 ( V_2 -> V_5 + V_65 ) ;
T_3 V_164 ;
const struct V_68 * V_69 = V_2 -> V_7 ;
F_39 ( ! F_45 ( V_17 -> V_41 ) ) ;
if ( V_118 -> V_123 == V_148 )
V_164 = F_58 ( V_163 ) ;
else if ( F_1 ( V_2 ) )
V_164 = F_59 ( F_3 ( V_2 -> V_5 + V_64 ) ) ;
else
V_164 = ( V_163 >> V_69 -> V_165 ) & 0x7f ;
return V_164 ;
}
static int F_60 ( struct V_16 * V_17 )
{
return F_61 ( V_17 -> V_41 ) ;
}
static int F_62 ( struct V_16 * V_17 )
{
return F_63 ( V_17 -> V_41 ) ;
}
static int F_64 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_1 * V_14 = F_5 ( V_2 ) ;
unsigned long V_75 ;
F_31 ( V_17 -> V_41 ) ;
if ( F_1 ( V_2 ) ) {
F_49 ( V_17 , & V_14 -> V_13 -> V_125 ,
NULL ) ;
} else {
F_49 ( V_17 , & V_2 -> V_125 ,
& V_2 -> V_127 ) ;
if ( V_2 -> V_37 & V_141 )
F_20 ( V_142 , V_2 -> V_5 + V_10 ) ;
if ( V_2 -> V_37 & V_166 )
F_65 ( V_2 -> V_5 ,
V_2 -> V_13 -> V_167 . V_5 ) ;
}
V_2 -> V_21 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_90 = 0 ;
F_32 ( V_2 -> V_77 , V_75 ) ;
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , 0 ) ;
F_27 ( V_2 , V_160 ) ;
F_27 ( V_14 , V_160 ) ;
F_27 ( V_2 , V_159 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
if ( ! F_16 ( V_14 ) )
F_30 ( V_17 , V_80 ,
0 , V_81 ) ;
F_42 ( V_17 -> V_41 ) ;
return 0 ;
}
static int F_66 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_15 ( V_17 ) ;
unsigned long V_75 ;
F_31 ( V_17 -> V_41 ) ;
if ( ! F_1 ( V_2 ) ) {
if ( V_2 -> V_37 & V_141 ) {
F_32 ( V_2 -> V_77 , V_75 ) ;
F_20 ( 0 , V_2 -> V_5 + V_10 ) ;
F_33 ( V_2 -> V_77 , V_75 ) ;
}
}
F_42 ( V_17 -> V_41 ) ;
return 0 ;
}
static struct V_1 * F_67 ( struct V_168 * V_40 ,
const struct V_169 * V_170 ,
bool V_171 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( & V_40 -> V_41 , sizeof( struct V_1 ) , V_172 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_40 = V_40 ;
V_2 -> V_3 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_173 . V_174 = 1 ;
V_2 -> V_173 . V_175 = F_64 ;
V_2 -> V_173 . remove = F_66 ;
V_2 -> V_173 . V_176 = & V_177 ;
V_2 -> V_173 . V_178 = F_60 ;
V_2 -> V_173 . V_179 = F_62 ;
V_2 -> V_173 . V_180 . V_181 = 1 ;
V_2 -> V_173 . V_180 . V_182 = 2 ;
V_2 -> V_173 . V_180 . V_183 = V_170 -> V_184 ;
V_2 -> V_173 . V_180 . V_185 = V_186 ;
if ( ! V_171 ) {
V_2 -> V_173 . V_147 . V_181 = 1 ;
V_2 -> V_173 . V_147 . V_182 = 2 ;
V_2 -> V_173 . V_147 . V_183 = V_170 -> V_184 ;
V_2 -> V_173 . V_147 . V_185 = V_186 ;
}
return V_2 ;
}
static int F_69 ( struct V_187 * V_41 )
{
struct V_1 * V_2 = F_70 ( V_41 ) ;
V_2 -> V_188 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_2 -> V_189 = F_3 ( V_2 -> V_5 + V_10 ) ;
V_2 -> V_190 = F_3 ( V_2 -> V_5 + V_145 ) ;
if ( V_2 -> V_89 )
F_35 ( V_2 -> V_89 ) ;
F_35 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_71 ( struct V_187 * V_41 )
{
struct V_1 * V_2 = F_70 ( V_41 ) ;
int V_76 ;
V_76 = F_41 ( V_2 -> V_191 ) ;
if ( V_76 )
return V_76 ;
if ( V_2 -> V_89 ) {
V_76 = F_41 ( V_2 -> V_89 ) ;
if ( V_76 ) {
F_35 ( V_2 -> V_191 ) ;
return V_76 ;
}
}
F_20 ( V_2 -> V_189 , V_2 -> V_5 + V_10 ) ;
F_20 ( V_2 -> V_188 , V_2 -> V_5 + V_6 ) ;
F_20 ( V_2 -> V_190 , V_2 -> V_5 + V_145 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_193 . V_194 ; V_192 ++ ) {
if ( ! F_34 ( V_2 -> V_195 [ V_192 ] ) )
F_73 ( V_2 -> V_195 [ V_192 ] ) ;
}
}
static void F_74 ( struct V_168 * V_40 )
{
struct V_1 * V_2 = F_70 ( & V_40 -> V_41 ) ;
F_75 ( V_40 -> V_41 . V_196 ) ;
F_72 ( V_2 ) ;
}
static int F_76 ( struct V_168 * V_40 )
{
struct V_187 * V_41 = & V_40 -> V_41 ;
struct V_1 * V_2 = F_70 ( V_41 ) ;
const char * V_197 [ 2 ] = { L_5 , L_4 } ;
const char * V_198 [ 2 ] = { NULL } ;
const struct V_68 * V_199 = V_2 -> V_7 ;
struct V_191 * V_200 ;
int V_76 , V_192 ;
if ( ! F_77 ( V_41 -> V_196 , L_15 , NULL ) )
return 0 ;
for ( V_192 = 0 ; V_192 < F_78 ( V_198 ) ; V_192 ++ ) {
V_200 = F_38 ( V_41 , V_197 [ V_192 ] ) ;
if ( F_34 ( V_200 ) )
continue;
V_198 [ V_192 ] = F_79 ( V_200 ) ;
F_36 ( V_200 ) ;
}
if ( ! ( V_2 -> V_37 & V_88 ) ) {
T_1 V_63 = F_3 ( V_2 -> V_5 + V_145 ) ;
F_20 ( V_63 | V_144 , V_2 -> V_5 + V_145 ) ;
V_2 -> V_195 [ V_201 ] = F_80 ( V_41 ,
L_16 , V_198 , F_78 ( V_198 ) ,
V_202 | V_203 ,
V_2 -> V_5 + V_6 , V_199 -> V_73 ,
1 , 0 , V_2 -> V_77 ) ;
V_2 -> V_195 [ V_204 ] = F_81 ( V_41 ,
L_17 , L_16 ,
V_203 ,
V_2 -> V_5 + V_145 , 8 , 6 , 0 , V_2 -> V_77 ) ;
V_198 [ 0 ] = L_17 ;
V_2 -> V_193 . V_194 = 2 ;
}
F_82 ( V_41 -> V_196 ,
L_18 , 0 , & V_197 [ 0 ] ) ;
V_2 -> V_195 [ V_205 ] = F_83 ( V_41 , V_197 [ 0 ] ,
V_198 [ 0 ] , V_203 ,
V_2 -> V_5 + V_6 , V_199 -> V_71 ,
V_206 , V_2 -> V_77 ) ;
V_2 -> V_193 . V_194 += 1 ;
V_2 -> V_193 . V_207 = V_2 -> V_195 ;
V_76 = F_84 ( V_41 -> V_196 , V_208 ,
& V_2 -> V_193 ) ;
if ( V_76 < 0 ) {
F_23 ( V_41 , L_19 , V_76 ) ;
F_72 ( V_2 ) ;
}
return V_76 ;
}
static int F_85 ( struct V_168 * V_40 )
{
struct V_1 * V_3 , * V_13 = NULL ;
struct V_209 * V_210 = V_40 -> V_41 . V_211 ;
struct V_212 * V_213 ;
T_1 V_214 , V_37 = 0 , V_215 = 0 ;
struct V_216 * V_217 = V_40 -> V_41 . V_196 ;
const struct V_169 * V_170 ;
int V_76 ;
if ( F_86 ( V_218 ) && V_40 -> V_41 . V_196 )
V_170 = F_87 ( & V_40 -> V_41 ) ;
else
V_170 = (struct V_169 * )
F_88 ( V_40 ) -> V_219 ;
V_3 = F_67 ( V_40 , V_170 , false ) ;
if ( ! V_3 ) {
F_23 ( & V_40 -> V_41 , L_20 ) ;
return - V_220 ;
}
F_89 ( & V_3 -> V_221 ) ;
V_3 -> V_77 = & V_3 -> V_221 ;
if ( ! V_217 ) {
if ( V_210 == NULL ) {
F_23 ( & V_40 -> V_41 , L_21 ) ;
return - V_92 ;
}
V_3 -> V_125 . V_222 = V_210 -> V_125 ;
V_3 -> V_127 . V_222 = V_210 -> V_127 ;
V_3 -> V_223 = V_210 -> V_224 ;
V_37 = V_210 -> type . V_37 ;
V_215 = V_210 -> type . V_215 ;
} else {
V_37 = V_170 -> V_37 ;
if ( F_90 ( V_217 , L_22 ,
& V_215 ) ) {
if ( V_37 & V_166 ) {
F_91 ( & V_40 -> V_41 , L_23\
L_24 ) ;
}
}
}
V_213 = F_92 ( V_40 , V_225 , 0 ) ;
V_3 -> V_5 = F_93 ( & V_40 -> V_41 , V_213 ) ;
if ( F_34 ( V_3 -> V_5 ) )
return F_40 ( V_3 -> V_5 ) ;
V_214 = V_213 -> V_226 ;
V_3 -> V_191 = F_94 ( & V_40 -> V_41 , L_25 ) ;
if ( F_34 ( V_3 -> V_191 ) ) {
F_23 ( & V_40 -> V_41 , L_26 ) ;
return F_40 ( V_3 -> V_191 ) ;
}
V_76 = F_41 ( V_3 -> V_191 ) ;
if ( V_76 != 0 ) {
F_23 ( & V_40 -> V_41 , L_27 , V_76 ) ;
return V_76 ;
}
V_3 -> V_125 . V_5 = V_214 + V_227 ;
V_3 -> V_127 . V_5 = V_214 + V_228 ;
V_3 -> V_125 . V_229 = L_28 ;
V_3 -> V_127 . V_229 = L_29 ;
V_3 -> V_125 . V_126 = 4 ;
V_3 -> V_127 . V_126 = 4 ;
V_3 -> V_37 = V_37 ;
V_3 -> V_7 = V_170 -> V_230 ;
if ( V_37 & V_231 )
V_3 -> V_173 . V_180 . V_182 = 6 ;
V_76 = F_95 ( & V_40 -> V_41 , V_3 -> V_223 ,
NULL , NULL ) ;
if ( V_76 < 0 )
goto V_232;
V_76 = F_96 ( & V_40 -> V_41 ,
& V_233 ,
& V_3 -> V_173 , 1 ) ;
if ( V_76 < 0 )
goto V_232;
if ( V_37 & V_234 ) {
V_13 = F_67 ( V_40 , V_170 , true ) ;
if ( ! V_13 ) {
F_23 ( & V_40 -> V_41 , L_30 ) ;
V_76 = - V_220 ;
goto V_232;
}
V_13 -> V_77 = & V_3 -> V_221 ;
V_13 -> V_7 = V_3 -> V_7 ;
V_13 -> V_125 . V_5 = V_214 + V_235 ;
V_13 -> V_125 . V_229 = L_31 ;
if ( ! V_217 ) {
V_13 -> V_125 . V_222 = V_210 -> V_236 ;
V_13 -> V_223 = V_210 -> V_224 ;
}
V_13 -> V_125 . V_126 = 4 ;
V_13 -> V_5 = V_3 -> V_5 ;
V_13 -> V_191 = V_3 -> V_191 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_167 . V_5 = V_215 ;
V_13 -> V_3 = V_3 ;
V_3 -> V_13 = V_13 ;
V_76 = F_95 ( & V_40 -> V_41 ,
V_13 -> V_223 , L_31 , NULL ) ;
if ( V_76 < 0 )
goto V_232;
V_76 = F_96 ( & V_40 -> V_41 ,
& V_233 ,
& V_13 -> V_173 , 1 ) ;
if ( V_76 < 0 )
goto V_232;
}
if ( V_210 && V_210 -> V_237 && V_210 -> V_237 ( V_40 ) ) {
F_23 ( & V_40 -> V_41 , L_32 ) ;
V_76 = - V_92 ;
goto V_232;
}
F_97 ( & V_40 -> V_41 , V_3 ) ;
F_98 ( & V_40 -> V_41 ) ;
F_99 ( & V_40 -> V_41 ) ;
V_76 = F_76 ( V_40 ) ;
if ( ! V_76 )
return 0 ;
F_100 ( & V_40 -> V_41 ) ;
V_232:
F_35 ( V_3 -> V_191 ) ;
return V_76 ;
}
static int F_101 ( struct V_168 * V_40 )
{
struct V_1 * V_3 ;
V_3 = F_70 ( & V_40 -> V_41 ) ;
F_31 ( & V_40 -> V_41 ) ;
F_100 ( & V_40 -> V_41 ) ;
F_74 ( V_40 ) ;
F_35 ( V_3 -> V_191 ) ;
F_102 ( & V_40 -> V_41 ) ;
return 0 ;
}
