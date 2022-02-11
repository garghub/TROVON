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
F_22 ( V_86 ) ;
if ( V_84 )
F_11 ( V_19 , 1 ) ;
else
F_6 ( V_19 , 1 ) ;
F_23 ( V_86 ) ;
break;
case V_94 :
case V_95 :
case V_96 :
F_22 ( V_86 ) ;
if ( V_84 )
F_11 ( V_19 , 0 ) ;
else
F_6 ( V_19 , 0 ) ;
F_23 ( V_86 ) ;
break;
default:
V_87 = - V_44 ;
break;
}
V_93:
return V_87 ;
}
static int F_24 ( struct V_2 * V_3 ,
int V_97 , int div )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_98 ;
F_7 ( L_20 , V_24 , V_3 , V_97 , div ) ;
switch ( V_97 ) {
case V_99 :
switch ( div ) {
case 16 :
div = V_100 ;
break;
case 32 :
div = V_101 ;
break;
case 24 :
div = V_102 ;
break;
case 48 :
div = V_103 ;
break;
default:
return - V_44 ;
}
V_98 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_98 &= ~ V_104 ;
F_10 ( V_98 | div , V_19 -> V_21 + V_27 ) ;
F_7 ( L_21 , V_24 , F_8 ( V_19 -> V_21 + V_27 ) ) ;
break;
case V_105 :
switch ( div ) {
case 256 :
div = V_106 ;
break;
case 384 :
div = V_107 ;
break;
case 512 :
div = V_108 ;
break;
case 768 :
div = V_109 ;
break;
default:
return - V_44 ;
}
V_98 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_98 &= ~ V_110 ;
F_10 ( V_98 | div , V_19 -> V_21 + V_27 ) ;
F_7 ( L_21 , V_24 , F_8 ( V_19 -> V_21 + V_27 ) ) ;
break;
case V_111 :
if ( div >= 0 ) {
F_10 ( ( div << 8 ) | V_112 ,
V_19 -> V_21 + V_113 ) ;
} else {
F_10 ( 0x0 , V_19 -> V_21 + V_113 ) ;
}
F_7 ( L_22 , V_24 , F_8 ( V_19 -> V_21 + V_113 ) ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static T_3 F_25 ( struct V_54 * V_55 ,
struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
T_1 V_98 = F_8 ( V_19 -> V_21 + V_25 ) ;
T_3 V_114 ;
if ( V_55 -> V_61 == V_62 )
V_114 = F_26 ( V_98 ) ;
else
V_114 = F_27 ( V_98 ) ;
return V_114 ;
}
struct V_115 * F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
if ( V_38 & V_72 )
return V_19 -> V_116 ;
else
return V_19 -> V_117 ;
}
int F_29 ( struct V_118 * V_119 ,
unsigned int * V_120 ,
unsigned int V_121 , struct V_115 * V_115 )
{
unsigned long V_122 = F_30 ( V_115 ) ;
unsigned int div ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_125 ;
unsigned int V_126 ;
signed int V_127 = 0 ;
unsigned int V_128 = 0 ;
unsigned int V_129 = 0 ;
unsigned int V_130 = 0 ;
unsigned int V_131 = V_132 ;
F_7 ( L_23 , V_122 ) ;
if ( V_120 == NULL )
V_120 = V_133 ;
for ( V_125 = 0 ; V_125 < F_31 ( V_133 ) ; V_125 ++ ) {
V_126 = V_133 [ V_125 ] ;
V_123 = V_122 / V_126 ;
div = V_123 / V_121 ;
if ( ( V_123 % V_121 ) > ( V_121 / 2 ) )
div ++ ;
if ( div <= 1 )
continue;
V_124 = V_122 / ( V_126 * div ) ;
V_127 = V_124 - V_121 ;
F_4 ( V_6 L_24 ,
V_126 , div , V_124 , V_127 ) ;
V_127 = abs ( V_127 ) ;
if ( V_127 < V_131 ) {
V_128 = V_126 ;
V_129 = div ;
V_130 = V_124 ;
V_131 = V_127 ;
}
if ( V_127 == 0 )
break;
}
F_4 ( V_6 L_25 ,
V_128 , V_129 , V_130 ) ;
V_119 -> V_134 = V_128 ;
V_119 -> V_135 = V_129 ;
return 0 ;
}
int F_32 ( struct V_2 * V_58 ,
struct V_1 * V_19 ,
unsigned long V_136 )
{
struct V_137 * V_32 = V_58 -> V_32 ;
unsigned int V_38 ;
V_19 -> V_32 = V_32 ;
F_33 ( V_58 , V_19 ) ;
V_19 -> V_117 = F_34 ( V_32 , L_26 ) ;
if ( F_35 ( V_19 -> V_117 ) ) {
F_9 ( V_32 , L_27 ) ;
F_36 ( V_19 -> V_21 ) ;
return - V_138 ;
}
F_37 ( V_19 -> V_117 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_38 |= V_30 ;
F_10 ( V_38 , V_19 -> V_21 + V_27 ) ;
F_6 ( V_19 , 0 ) ;
F_11 ( V_19 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
T_1 V_38 ;
if ( V_58 -> V_139 ) {
V_19 -> V_140 = F_8 ( V_19 -> V_21 + V_27 ) ;
V_19 -> V_141 = F_8 ( V_19 -> V_21 + V_26 ) ;
V_19 -> V_142 = F_8 ( V_19 -> V_21 + V_113 ) ;
V_38 = F_8 ( V_19 -> V_21 + V_27 ) ;
if ( V_38 & V_17 )
F_39 ( L_28 , V_24 ) ;
if ( V_38 & V_16 )
F_39 ( L_29 , V_24 ) ;
if ( V_38 & V_18 )
F_39 ( L_30 , V_24 ) ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_58 )
{
struct V_1 * V_19 = F_1 ( V_58 ) ;
F_41 ( L_31 ,
V_58 -> V_139 , V_19 -> V_140 , V_19 -> V_141 ) ;
if ( V_58 -> V_139 ) {
F_10 ( V_19 -> V_141 , V_19 -> V_21 + V_26 ) ;
F_10 ( V_19 -> V_140 , V_19 -> V_21 + V_27 ) ;
F_10 ( V_19 -> V_142 , V_19 -> V_21 + V_113 ) ;
F_10 ( V_89 | V_90 ,
V_19 -> V_21 + V_25 ) ;
F_42 ( 250 ) ;
F_10 ( 0x0 , V_19 -> V_21 + V_25 ) ;
}
return 0 ;
}
int F_43 ( struct V_137 * V_32 , int V_143 ,
struct V_144 * V_145 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 = (struct V_148 * ) V_147 -> V_149 ;
V_149 -> V_150 = F_21 ;
if ( ! V_149 -> V_151 )
V_149 -> V_151 = F_17 ;
V_149 -> V_152 = F_15 ;
V_149 -> V_153 = F_24 ;
V_149 -> V_154 = F_20 ;
if ( ! V_149 -> V_114 )
V_149 -> V_114 = F_25 ;
V_147 -> V_155 = F_38 ;
V_147 -> V_156 = F_40 ;
return F_44 ( V_32 , V_145 , V_147 , 1 ) ;
}
