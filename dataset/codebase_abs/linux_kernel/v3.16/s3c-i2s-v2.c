static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( const char * V_4 , T_1 V_5 )
{
F_4 ( V_6 L_1 , V_4 ,
F_5 ( V_5 , V_7 ) ,
F_5 ( V_5 , V_8 ) ,
F_5 ( V_5 , V_9 ) ,
F_5 ( V_5 , V_10 ) ,
F_5 ( V_5 , V_11 ) ) ;
F_4 ( V_6 L_2 ,
V_4 ,
F_5 ( V_5 , V_12 ) ,
F_5 ( V_5 , V_13 ) ,
F_5 ( V_5 , V_14 ) ,
F_5 ( V_5 , V_15 ) ) ;
F_4 ( V_6 L_3 , V_4 ,
F_5 ( V_5 , V_16 ) ,
F_5 ( V_5 , V_17 ) ,
F_5 ( V_5 , V_18 ) ) ;
}
static inline void F_3 ( const char * V_4 , T_1 V_5 )
{
}
static void F_6 ( struct V_1 * V_19 , int V_20 )
{
void T_2 * V_21 = V_19 -> V_21 ;
T_1 V_22 , V_5 , V_23 ;
F_7 ( L_4 , V_24 , V_20 ) ;
V_22 = F_8 ( V_21 + V_25 ) ;
V_5 = F_8 ( V_21 + V_26 ) ;
V_23 = F_8 ( V_21 + V_27 ) ;
F_7 ( L_5 , V_24 , V_5 , V_23 , V_22 ) ;
if ( V_20 ) {
V_5 |= V_16 | V_18 ;
V_5 &= ~ V_12 ;
V_5 &= ~ V_14 ;
switch ( V_23 & V_28 ) {
case V_29 :
case V_30 :
break;
case V_31 :
V_23 &= ~ V_28 ;
V_23 |= V_30 ;
break;
default:
F_9 ( V_19 -> V_32 , L_6 ,
V_23 & V_28 ) ;
break;
}
F_10 ( V_5 , V_21 + V_26 ) ;
F_10 ( V_23 , V_21 + V_27 ) ;
} else {
V_5 |= V_12 ;
V_5 |= V_14 ;
V_5 &= ~ V_16 ;
switch ( V_23 & V_28 ) {
case V_30 :
V_23 &= ~ V_28 ;
V_23 |= V_31 ;
break;
case V_29 :
V_23 &= ~ V_28 ;
V_5 &= ~ V_18 ;
break;
default:
F_9 ( V_19 -> V_32 , L_7 ,
V_23 & V_28 ) ;
break;
}
F_10 ( V_23 , V_21 + V_27 ) ;
F_10 ( V_5 , V_21 + V_26 ) ;
}
V_22 = F_8 ( V_21 + V_25 ) ;
F_3 ( V_24 , V_5 ) ;
F_7 ( L_5 , V_24 , V_5 , V_23 , V_22 ) ;
}
static void F_11 ( struct V_1 * V_19 , int V_20 )
{
void T_2 * V_21 = V_19 -> V_21 ;
T_1 V_22 , V_5 , V_23 ;
F_7 ( L_4 , V_24 , V_20 ) ;
V_22 = F_8 ( V_21 + V_25 ) ;
V_5 = F_8 ( V_21 + V_26 ) ;
V_23 = F_8 ( V_21 + V_27 ) ;
F_7 ( L_5 , V_24 , V_5 , V_23 , V_22 ) ;
if ( V_20 ) {
V_5 |= V_17 | V_18 ;
V_5 &= ~ V_13 ;
V_5 &= ~ V_15 ;
switch ( V_23 & V_28 ) {
case V_30 :
case V_31 :
break;
case V_29 :
V_23 &= ~ V_28 ;
V_23 |= V_30 ;
break;
default:
F_9 ( V_19 -> V_32 , L_8 ,
V_23 & V_28 ) ;
}
F_10 ( V_23 , V_21 + V_27 ) ;
F_10 ( V_5 , V_21 + V_26 ) ;
} else {
V_5 &= ~ V_17 ;
V_5 |= V_13 ;
V_5 |= V_15 ;
switch ( V_23 & V_28 ) {
case V_31 :
V_5 &= ~ V_18 ;
V_23 &= ~ V_28 ;
break;
case V_30 :
V_23 &= ~ V_28 ;
V_23 |= V_29 ;
break;
default:
F_9 ( V_19 -> V_32 , L_9 ,
V_23 & V_28 ) ;
}
F_10 ( V_5 , V_21 + V_26 ) ;
F_10 ( V_23 , V_21 + V_27 ) ;
}
V_22 = F_8 ( V_21 + V_25 ) ;
F_7 ( L_5 , V_24 , V_5 , V_23 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_19 )
{
T_1 V_33 ;
unsigned long V_34 = F_13 ( 5 ) ;
F_7 ( L_10 , V_24 ) ;
while ( -- V_34 ) {
V_33 = F_8 ( V_19 -> V_21 + V_26 ) ;
if ( V_33 & V_7 )
break;
F_14 () ;
}
if ( ! V_34 ) {
F_4 ( V_35 L_11 , V_24 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
unsigned int V_37 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_38 ;
F_7 ( L_10 , V_24 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
F_7 ( L_12 , V_38 ) ;
switch ( V_37 & V_39 ) {
case V_40 :
V_19 -> V_41 = 0 ;
V_38 |= V_42 ;
break;
case V_43 :
V_19 -> V_41 = 1 ;
V_38 &= ~ V_42 ;
break;
default:
F_16 ( L_13 ) ;
return - V_44 ;
}
V_38 &= ~ V_45 ;
switch ( V_37 & V_46 ) {
case V_47 :
V_38 |= V_48 ;
V_38 |= V_49 ;
break;
case V_50 :
V_38 |= V_48 ;
V_38 |= V_51 ;
break;
case V_52 :
V_38 &= ~ V_48 ;
V_38 |= V_53 ;
break;
default:
F_16 ( L_14 ) ;
return - V_44 ;
}
F_10 ( V_38 , V_19 -> V_21 + V_27 ) ;
F_7 ( L_15 , V_38 ) ;
return 0 ;
}
static int F_17 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
struct V_59 * V_60 ;
T_1 V_38 ;
F_7 ( L_10 , V_24 ) ;
if ( V_55 -> V_61 == V_62 )
V_60 = V_19 -> V_63 ;
else
V_60 = V_19 -> V_64 ;
F_18 ( V_58 , V_55 , V_60 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
F_7 ( L_16 , V_24 , V_38 ) ;
V_38 &= ~ V_65 ;
switch ( F_19 ( V_57 ) ) {
case 8 :
V_38 |= V_66 ;
break;
case 16 :
break;
case 24 :
V_38 |= V_67 ;
break;
}
F_10 ( V_38 , V_19 -> V_21 + V_27 ) ;
F_7 ( L_17 , V_24 , V_38 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
int V_68 , unsigned int V_69 , int V_70 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
F_7 ( L_10 , V_24 ) ;
F_7 ( L_18 , V_24 , V_38 ) ;
switch ( V_68 ) {
case V_71 :
V_38 &= ~ V_72 ;
break;
case V_73 :
V_38 |= V_72 ;
break;
case V_74 :
if ( ! ( V_19 -> V_75 & V_76 ) )
return - V_44 ;
switch ( V_70 ) {
case V_77 :
V_38 |= V_78 ;
break;
case V_79 :
V_38 &= ~ V_78 ;
break;
default:
return - V_44 ;
}
break;
default:
return - V_44 ;
}
F_10 ( V_38 , V_19 -> V_21 + V_27 ) ;
F_7 ( L_19 , V_24 , V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_54 * V_55 , int V_80 ,
struct V_2 * V_58 )
{
struct V_81 * V_82 = V_55 -> V_83 ;
struct V_1 * V_19 = F_1 ( V_82 -> V_3 ) ;
int V_84 = ( V_55 -> V_61 == V_85 ) ;
unsigned long V_86 ;
int V_87 = 0 ;
struct V_59 * V_60 =
F_22 ( V_82 -> V_3 , V_55 ) ;
F_7 ( L_10 , V_24 ) ;
switch ( V_80 ) {
case V_88 :
F_10 ( V_84 ? V_89 : V_90 ,
V_19 -> V_21 + V_25 ) ;
F_10 ( 0x0 , V_19 -> V_21 + V_25 ) ;
case V_91 :
case V_92 :
if ( ! V_19 -> V_41 ) {
V_87 = F_12 ( V_19 ) ;
if ( V_87 )
goto V_93;
}
F_23 ( V_86 ) ;
if ( V_84 )
F_11 ( V_19 , 1 ) ;
else
F_6 ( V_19 , 1 ) ;
F_24 ( V_86 ) ;
F_25 ( V_60 -> V_94 , V_95 ) ;
break;
case V_96 :
case V_97 :
case V_98 :
F_23 ( V_86 ) ;
if ( V_84 )
F_11 ( V_19 , 0 ) ;
else
F_6 ( V_19 , 0 ) ;
F_24 ( V_86 ) ;
break;
default:
V_87 = - V_44 ;
break;
}
V_93:
return V_87 ;
}
static int F_26 ( struct V_2 * V_3 ,
int V_99 , int div )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_100 ;
F_7 ( L_20 , V_24 , V_3 , V_99 , div ) ;
switch ( V_99 ) {
case V_101 :
switch ( div ) {
case 16 :
div = V_102 ;
break;
case 32 :
div = V_103 ;
break;
case 24 :
div = V_104 ;
break;
case 48 :
div = V_105 ;
break;
default:
return - V_44 ;
}
V_100 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_100 &= ~ V_106 ;
F_10 ( V_100 | div , V_19 -> V_21 + V_27 ) ;
F_7 ( L_21 , V_24 , F_8 ( V_19 -> V_21 + V_27 ) ) ;
break;
case V_107 :
switch ( div ) {
case 256 :
div = V_108 ;
break;
case 384 :
div = V_109 ;
break;
case 512 :
div = V_110 ;
break;
case 768 :
div = V_111 ;
break;
default:
return - V_44 ;
}
V_100 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_100 &= ~ V_112 ;
F_10 ( V_100 | div , V_19 -> V_21 + V_27 ) ;
F_7 ( L_21 , V_24 , F_8 ( V_19 -> V_21 + V_27 ) ) ;
break;
case V_113 :
if ( div >= 0 ) {
F_10 ( ( div << 8 ) | V_114 ,
V_19 -> V_21 + V_115 ) ;
} else {
F_10 ( 0x0 , V_19 -> V_21 + V_115 ) ;
}
F_7 ( L_22 , V_24 , F_8 ( V_19 -> V_21 + V_115 ) ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static T_3 F_27 ( struct V_54 * V_55 ,
struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
T_1 V_100 = F_8 ( V_19 -> V_21 + V_25 ) ;
T_3 V_116 ;
if ( V_55 -> V_61 == V_62 )
V_116 = F_28 ( V_100 ) ;
else
V_116 = F_29 ( V_100 ) ;
return V_116 ;
}
struct V_117 * F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
if ( V_38 & V_72 )
return V_19 -> V_118 ;
else
return V_19 -> V_119 ;
}
int F_31 ( struct V_120 * V_121 ,
unsigned int * V_122 ,
unsigned int V_123 , struct V_117 * V_117 )
{
unsigned long V_124 = F_32 ( V_117 ) ;
unsigned int div ;
unsigned int V_125 ;
unsigned int V_126 ;
unsigned int V_127 ;
unsigned int V_128 ;
signed int V_129 = 0 ;
unsigned int V_130 = 0 ;
unsigned int V_131 = 0 ;
unsigned int V_132 = 0 ;
unsigned int V_133 = V_134 ;
F_7 ( L_23 , V_124 ) ;
if ( V_122 == NULL )
V_122 = V_135 ;
for ( V_127 = 0 ; V_127 < F_33 ( V_135 ) ; V_127 ++ ) {
V_128 = V_135 [ V_127 ] ;
V_125 = V_124 / V_128 ;
div = V_125 / V_123 ;
if ( ( V_125 % V_123 ) > ( V_123 / 2 ) )
div ++ ;
if ( div <= 1 )
continue;
V_126 = V_124 / ( V_128 * div ) ;
V_129 = V_126 - V_123 ;
F_4 ( V_6 L_24 ,
V_128 , div , V_126 , V_129 ) ;
V_129 = abs ( V_129 ) ;
if ( V_129 < V_133 ) {
V_130 = V_128 ;
V_131 = div ;
V_132 = V_126 ;
V_133 = V_129 ;
}
if ( V_129 == 0 )
break;
}
F_4 ( V_6 L_25 ,
V_130 , V_131 , V_132 ) ;
V_121 -> V_136 = V_130 ;
V_121 -> V_137 = V_131 ;
return 0 ;
}
int F_34 ( struct V_2 * V_58 ,
struct V_1 * V_19 ,
unsigned long V_138 )
{
struct V_139 * V_32 = V_58 -> V_32 ;
unsigned int V_38 ;
V_19 -> V_32 = V_32 ;
F_35 ( V_58 , V_19 ) ;
V_19 -> V_21 = F_36 ( V_138 , 0x100 ) ;
if ( V_19 -> V_21 == NULL ) {
F_9 ( V_32 , L_26 ) ;
return - V_140 ;
}
V_19 -> V_119 = F_37 ( V_32 , L_27 ) ;
if ( F_38 ( V_19 -> V_119 ) ) {
F_9 ( V_32 , L_28 ) ;
F_39 ( V_19 -> V_21 ) ;
return - V_141 ;
}
F_40 ( V_19 -> V_119 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_38 |= V_30 ;
F_10 ( V_38 , V_19 -> V_21 + V_27 ) ;
F_6 ( V_19 , 0 ) ;
F_11 ( V_19 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
T_1 V_38 ;
if ( V_58 -> V_142 ) {
V_19 -> V_143 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_19 -> V_144 = F_8 ( V_19 -> V_21 + V_26 ) ;
V_19 -> V_145 = F_8 ( V_19 -> V_21 + V_115 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
if ( V_38 & V_17 )
F_42 ( L_29 , V_24 ) ;
if ( V_38 & V_16 )
F_42 ( L_30 , V_24 ) ;
if ( V_38 & V_18 )
F_42 ( L_31 , V_24 ) ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
F_44 ( L_32 ,
V_58 -> V_142 , V_19 -> V_143 , V_19 -> V_144 ) ;
if ( V_58 -> V_142 ) {
F_10 ( V_19 -> V_144 , V_19 -> V_21 + V_26 ) ;
F_10 ( V_19 -> V_143 , V_19 -> V_21 + V_27 ) ;
F_10 ( V_19 -> V_145 , V_19 -> V_21 + V_115 ) ;
F_10 ( V_89 | V_90 ,
V_19 -> V_21 + V_25 ) ;
F_45 ( 250 ) ;
F_10 ( 0x0 , V_19 -> V_21 + V_25 ) ;
}
return 0 ;
}
int F_46 ( struct V_139 * V_32 , int V_146 ,
struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_151 * V_152 = V_150 -> V_152 ;
V_152 -> V_153 = F_21 ;
if ( ! V_152 -> V_154 )
V_152 -> V_154 = F_17 ;
V_152 -> V_155 = F_15 ;
V_152 -> V_156 = F_26 ;
V_152 -> V_157 = F_20 ;
if ( ! V_152 -> V_116 )
V_152 -> V_116 = F_27 ;
V_150 -> V_158 = F_41 ;
V_150 -> V_159 = F_43 ;
return F_47 ( V_32 , V_148 , V_150 , 1 ) ;
}
