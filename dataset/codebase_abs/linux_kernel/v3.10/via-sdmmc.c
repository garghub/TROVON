static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
F_2 ( L_1 ) ;
F_2 ( L_2 ,
F_3 ( V_3 + V_5 ) ,
F_3 ( V_3 + V_6 ) ,
F_3 ( V_3 + V_7 ) ) ;
F_2 ( L_3 ,
F_3 ( V_3 + V_8 ) ,
F_3 ( V_3 + V_9 ) ,
F_3 ( V_3 + V_10 ) ) ;
F_2 ( L_4 ,
F_3 ( V_3 + V_11 ) ,
F_3 ( V_3 + V_12 ) ,
F_3 ( V_3 + V_13 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_14 ;
F_2 ( L_5 ) ;
F_2 ( L_6 ,
F_5 ( V_3 + V_15 ) ,
F_5 ( V_3 + V_16 ) ,
F_5 ( V_3 + V_17 ) ) ;
F_2 ( L_7 ,
F_5 ( V_3 + V_18 ) ,
F_5 ( V_3 + V_19 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
void T_1 * V_3 ;
V_21 = & ( V_2 -> V_21 ) ;
V_3 = V_2 -> V_14 ;
V_21 -> V_22 = F_5 ( V_3 + V_15 ) ;
V_21 -> V_22 |=
V_23 | V_24 ;
V_21 -> V_25 = F_5 ( V_3 + V_16 ) ;
V_21 -> V_26 = F_5 ( V_3 + V_17 ) ;
V_21 -> V_27 = F_5 ( V_3 + V_18 ) ;
V_21 -> V_28 =
F_5 ( V_3 + V_19 ) ;
V_21 -> V_29 = F_5 ( V_3 + V_30 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
void T_1 * V_3 ;
V_21 = & ( V_2 -> V_21 ) ;
V_3 = V_2 -> V_14 ;
F_8 ( V_21 -> V_22 , V_3 + V_15 ) ;
F_8 ( V_21 -> V_25 , V_3 + V_16 ) ;
F_8 ( V_21 -> V_26 , V_3 + V_17 ) ;
F_8 ( V_21 -> V_27 , V_3 + V_18 ) ;
F_8 ( V_21 -> V_28 ,
V_3 + V_19 ) ;
F_8 ( V_21 -> V_29 , V_3 + V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
void T_1 * V_3 ;
V_32 = & ( V_2 -> V_32 ) ;
V_3 = V_2 -> V_4 ;
V_32 -> V_33 = F_3 ( V_3 + V_5 ) ;
V_32 -> V_34 = F_3 ( V_3 + V_6 ) ;
V_32 -> V_35 = F_3 ( V_3 + V_7 ) ;
V_32 -> V_36 = F_3 ( V_3 + V_8 ) ;
V_32 -> V_37 = F_3 ( V_3 + V_9 ) ;
V_32 -> V_38 = F_3 ( V_3 + V_10 ) ;
V_32 -> V_39 = F_3 ( V_3 + V_11 ) ;
V_32 -> V_40 = F_3 ( V_3 + V_41 ) ;
V_32 -> V_42 = F_3 ( V_3 + V_12 ) ;
V_32 -> V_43 = F_3 ( V_3 + V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
void T_1 * V_3 ;
V_32 = & ( V_2 -> V_32 ) ;
V_3 = V_2 -> V_4 ;
F_11 ( V_32 -> V_33 , V_3 + V_5 ) ;
F_11 ( V_32 -> V_34 , V_3 + V_6 ) ;
F_11 ( V_32 -> V_35 , V_3 + V_7 ) ;
F_11 ( V_32 -> V_36 , V_3 + V_8 ) ;
F_11 ( V_32 -> V_37 , V_3 + V_9 ) ;
F_11 ( V_32 -> V_38 , V_3 + V_10 ) ;
F_11 ( V_32 -> V_39 , V_3 + V_11 ) ;
F_11 ( V_32 -> V_40 , V_3 + V_41 ) ;
F_11 ( V_32 -> V_42 , V_3 + V_12 ) ;
F_11 ( V_32 -> V_43 , V_3 + V_13 ) ;
}
static void F_12 ( struct V_1 * V_44 )
{
if ( V_44 -> V_45 & V_46 )
F_13 ( 300 ) ;
else
F_13 ( 3 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_2 V_47 , T_3 V_48 , int V_49 , int V_50 )
{
void T_1 * V_3 ;
T_3 V_51 = 0 ;
if ( V_50 )
V_51 |= V_52 ;
if ( V_49 )
V_51 |= V_53 ;
V_3 = V_2 -> V_54 ;
F_11 ( V_47 , V_3 + V_55 ) ;
F_11 ( V_48 , V_3 + V_56 ) ;
F_11 ( V_51 , V_3 + V_57 ) ;
F_11 ( 0x01 , V_3 + V_58 ) ;
V_3 = V_2 -> V_14 ;
if ( F_5 ( V_3 + V_16 ) == V_59 ) {
F_15 ( V_2 -> V_60 -> V_61 , L_8 ) ;
F_8 ( V_62 , V_3 + V_16 ) ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
void T_1 * V_3 ;
T_3 V_65 ;
int V_48 ;
F_17 ( V_2 -> V_64 ) ;
F_18 ( V_64 -> V_66 > V_2 -> V_60 -> V_67 ) ;
F_18 ( V_64 -> V_68 > V_2 -> V_60 -> V_69 ) ;
V_2 -> V_64 = V_64 ;
V_48 = F_19 ( F_20 ( V_2 -> V_60 ) , V_64 -> V_70 , V_64 -> V_71 ,
( ( V_64 -> V_72 & V_73 ) ?
V_74 : V_75 ) ) ;
F_18 ( V_48 != 1 ) ;
F_14 ( V_2 , F_21 ( V_64 -> V_70 ) , F_22 ( V_64 -> V_70 ) ,
( V_64 -> V_72 & V_76 ) ? 1 : 0 , 1 ) ;
V_3 = V_2 -> V_4 ;
V_65 = V_64 -> V_66 - 1 ;
V_65 |= V_77 | V_78 ;
V_65 |= ( V_64 -> V_68 ) << 16 ;
F_11 ( V_65 , V_3 + V_8 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
void T_1 * V_3 = V_2 -> V_4 ;
T_3 V_81 = F_3 ( V_3 + V_82 ) ;
T_3 V_83 = F_3 ( V_3 + V_84 ) ;
T_3 V_85 = F_3 ( V_3 + V_86 ) ;
T_3 V_87 = F_3 ( V_3 + V_88 ) ;
if ( V_80 -> V_72 & V_89 ) {
V_80 -> V_90 [ 0 ] = ( ( V_91 ) ( V_83 ) ) |
( ( ( V_91 ) ( V_81 >> 24 ) ) << 8 ) |
( ( ( V_91 ) ( V_81 >> 16 ) ) << 16 ) |
( ( ( V_91 ) ( V_81 >> 8 ) ) << 24 ) ;
V_80 -> V_90 [ 1 ] = ( ( V_91 ) ( V_85 ) ) |
( ( ( V_91 ) ( V_83 >> 24 ) ) << 8 ) |
( ( ( V_91 ) ( V_83 >> 16 ) ) << 16 ) |
( ( ( V_91 ) ( V_83 >> 8 ) ) << 24 ) ;
V_80 -> V_90 [ 2 ] = ( ( V_91 ) ( V_87 ) ) |
( ( ( V_91 ) ( V_85 >> 24 ) ) << 8 ) |
( ( ( V_91 ) ( V_85 >> 16 ) ) << 16 ) |
( ( ( V_91 ) ( V_85 >> 8 ) ) << 24 ) ;
V_80 -> V_90 [ 3 ] = 0xff |
( ( ( ( V_91 ) ( V_87 >> 24 ) ) ) << 8 ) |
( ( ( V_91 ) ( V_87 >> 16 ) ) << 16 ) |
( ( ( V_91 ) ( V_87 >> 8 ) ) << 24 ) ;
} else {
V_81 >>= 8 ;
V_80 -> V_90 [ 0 ] = ( ( V_81 & 0xff ) << 24 ) |
( ( ( V_81 >> 8 ) & 0xff ) << 16 ) |
( ( ( V_81 >> 16 ) & 0xff ) << 8 ) | ( V_83 & 0xff ) ;
V_83 >>= 8 ;
V_80 -> V_90 [ 1 ] = ( ( V_83 & 0xff ) << 24 ) |
( ( ( V_83 >> 8 ) & 0xff ) << 16 ) |
( ( ( V_83 >> 16 ) & 0xff ) << 8 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
void T_1 * V_3 ;
struct V_63 * V_64 ;
T_3 V_92 = 0 ;
F_17 ( V_2 -> V_80 ) ;
V_64 = V_80 -> V_64 ;
F_25 ( & V_2 -> V_93 , V_94 + V_95 ) ;
V_2 -> V_80 = V_80 ;
V_92 = V_80 -> V_96 << 8 ;
switch ( F_26 ( V_80 ) ) {
case V_97 :
V_92 |= V_98 ;
break;
case V_99 :
V_92 |= V_100 ;
break;
case V_101 :
V_92 |= V_102 ;
break;
case V_103 :
V_92 |= V_104 ;
break;
case V_105 :
V_92 |= V_106 ;
break;
default:
F_27 ( L_9 , F_28 ( V_2 -> V_60 ) ) ;
break;
}
if ( ! ( V_80 -> V_64 ) )
goto V_107;
F_16 ( V_2 , V_64 ) ;
if ( V_64 -> V_68 > 1 ) {
if ( V_64 -> V_72 & V_76 ) {
V_92 |= V_108 ;
V_92 |= V_109 ;
} else {
V_92 |= V_110 ;
}
} else {
if ( V_64 -> V_72 & V_76 ) {
V_92 |= V_108 ;
V_92 |= V_111 ;
} else {
V_92 |= V_112 ;
}
}
V_107:
if ( V_80 == V_2 -> V_113 -> V_114 )
V_92 |= V_115 ;
V_92 |= V_116 ;
V_3 = V_2 -> V_4 ;
F_11 ( V_80 -> V_117 , V_3 + V_6 ) ;
F_11 ( V_92 , V_3 + V_5 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
F_18 ( ! V_2 -> V_64 ) ;
V_64 = V_2 -> V_64 ;
V_2 -> V_64 = NULL ;
if ( V_64 -> error )
V_64 -> V_118 = 0 ;
else
V_64 -> V_118 = V_64 -> V_68 * V_64 -> V_66 ;
F_30 ( F_20 ( V_2 -> V_60 ) , V_64 -> V_70 , V_64 -> V_71 ,
( ( V_64 -> V_72 & V_73 ) ?
V_74 : V_75 ) ) ;
if ( V_64 -> V_114 )
F_24 ( V_2 , V_64 -> V_114 ) ;
else
F_31 ( & V_2 -> V_119 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_2 -> V_80 ) ;
V_2 -> V_80 -> error = 0 ;
if ( ! V_2 -> V_80 -> V_64 )
F_31 ( & V_2 -> V_119 ) ;
V_2 -> V_80 = NULL ;
}
static void F_33 ( struct V_120 * V_60 , struct V_121 * V_113 )
{
void T_1 * V_3 ;
struct V_1 * V_2 ;
unsigned long V_72 ;
T_4 V_122 ;
V_2 = F_34 ( V_60 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
V_3 = V_2 -> V_14 ;
F_8 ( V_124 , V_3 + V_17 ) ;
V_122 = F_36 ( V_2 -> V_4 + V_11 ) ;
V_122 &= V_125 ;
F_37 ( V_122 , V_2 -> V_4 + V_11 ) ;
F_17 ( V_2 -> V_113 != NULL ) ;
V_2 -> V_113 = V_113 ;
V_122 = F_36 ( V_2 -> V_4 + V_11 ) ;
if ( ! ( V_122 & V_126 ) || V_2 -> V_127 ) {
V_2 -> V_113 -> V_80 -> error = - V_128 ;
F_31 ( & V_2 -> V_119 ) ;
} else {
F_24 ( V_2 , V_113 -> V_80 ) ;
}
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short V_129 , unsigned int V_130 )
{
unsigned long V_72 ;
V_91 V_131 ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
V_2 -> V_129 = ( 1 << V_129 ) ;
V_131 = F_5 ( V_2 -> V_14 + V_15 ) ;
if ( V_2 -> V_129 == V_132 )
V_131 &= ~ V_23 ;
else
V_131 |= V_23 ;
if ( V_130 )
V_131 |= V_24 ;
else
V_131 &= ~ V_24 ;
F_8 ( V_131 , V_2 -> V_14 + V_15 ) ;
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
F_12 ( V_2 ) ;
}
static void F_41 ( struct V_120 * V_60 , struct V_133 * V_134 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
void T_1 * V_3 ;
T_3 V_135 , V_136 ;
V_91 clock ;
V_2 = F_34 ( V_60 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
V_3 = V_2 -> V_4 ;
V_135 = F_3 ( V_3 + V_7 ) ;
V_136 = F_3 ( V_3 + V_13 ) ;
if ( V_134 -> V_137 == V_138 )
V_135 &= ~ V_139 ;
else
V_135 |= V_139 ;
if ( V_134 -> V_140 == V_141 )
V_135 &= ~ V_142 ;
else
V_135 |= V_142 ;
if ( V_134 -> V_143 == V_144 )
V_136 |= V_145 ;
else
V_136 &= ~ V_145 ;
F_11 ( V_135 , V_3 + V_7 ) ;
F_11 ( V_136 , V_3 + V_13 ) ;
if ( V_134 -> clock >= 48000000 )
clock = V_146 ;
else if ( V_134 -> clock >= 33000000 )
clock = V_147 ;
else if ( V_134 -> clock >= 24000000 )
clock = V_148 ;
else if ( V_134 -> clock >= 16000000 )
clock = V_149 ;
else if ( V_134 -> clock >= 12000000 )
clock = V_150 ;
else if ( V_134 -> clock >= 8000000 )
clock = V_62 ;
else
clock = V_59 ;
V_3 = V_2 -> V_14 ;
if ( F_5 ( V_3 + V_16 ) != clock )
F_8 ( clock , V_3 + V_16 ) ;
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
if ( V_134 -> V_140 != V_141 )
F_40 ( V_2 , V_134 -> V_151 , 1 ) ;
else
F_40 ( V_2 , V_134 -> V_151 , 0 ) ;
}
static int F_42 ( struct V_120 * V_60 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
T_4 V_122 ;
V_2 = F_34 ( V_60 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
V_122 = F_36 ( V_2 -> V_4 + V_11 ) ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
return ! ( V_122 & V_152 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned long V_72 ;
V_91 V_131 ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
V_131 = V_24 ;
if ( V_2 -> V_129 == V_132 )
V_131 &= V_23 ;
else
V_131 |= V_23 ;
F_8 ( V_131 , V_2 -> V_14 + V_15 ) ;
F_12 ( V_2 ) ;
V_131 |= V_153 ;
F_8 ( V_131 , V_2 -> V_14 + V_15 ) ;
F_13 ( 3 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
F_7 ( V_2 ) ;
F_10 ( V_2 ) ;
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_4 V_154 )
{
F_18 ( V_154 == 0 ) ;
if ( ! V_2 -> V_80 ) {
F_27 ( L_10
L_11 ,
F_28 ( V_2 -> V_60 ) , V_154 ) ;
return;
}
if ( V_154 & V_155 )
V_2 -> V_80 -> error = - V_156 ;
else if ( V_154 & V_157 )
V_2 -> V_80 -> error = - V_158 ;
if ( V_2 -> V_80 -> error )
F_31 ( & V_2 -> V_119 ) ;
else if ( V_154 & V_159 )
F_32 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_4 V_154 )
{
F_18 ( V_154 == 0 ) ;
if ( V_154 & V_160 )
V_2 -> V_64 -> error = - V_156 ;
else if ( V_154 & ( V_161 | V_162 ) )
V_2 -> V_64 -> error = - V_158 ;
F_29 ( V_2 ) ;
}
static T_5 F_46 ( int V_163 , void * V_164 )
{
struct V_1 * V_44 = V_164 ;
void T_1 * V_3 ;
V_91 V_165 ;
T_4 V_166 ;
T_5 V_167 ;
if ( ! V_44 )
return V_168 ;
F_47 ( & V_44 -> V_123 ) ;
V_3 = V_44 -> V_14 ;
V_165 = F_5 ( V_3 + V_19 ) ;
if ( ! ( V_165 & V_169 ) ) {
V_167 = V_168 ;
goto V_170;
}
V_3 = V_44 -> V_4 ;
V_166 = F_36 ( V_3 + V_11 ) ;
V_166 &= V_171 ;
V_166 &= ~ V_172 ;
if ( ! V_166 ) {
V_167 = V_168 ;
goto V_170;
}
if ( V_166 & V_173 ) {
F_37 ( V_166 & V_173 ,
V_3 + V_11 ) ;
F_48 ( & V_44 -> V_174 ) ;
}
V_166 &= ~ V_173 ;
if ( V_166 & V_175 ) {
F_37 ( V_166 & V_175 ,
V_3 + V_11 ) ;
F_44 ( V_44 , V_166 & V_175 ) ;
}
if ( V_166 & V_176 ) {
F_37 ( V_166 & V_176 ,
V_3 + V_11 ) ;
F_45 ( V_44 , V_166 & V_176 ) ;
}
V_166 &= ~ ( V_175 | V_176 ) ;
if ( V_166 ) {
F_27 ( L_12 ,
F_28 ( V_44 -> V_60 ) , V_166 ) ;
F_37 ( V_166 , V_3 + V_11 ) ;
}
V_167 = V_177 ;
F_38 () ;
V_170:
F_49 ( & V_44 -> V_123 ) ;
return V_167 ;
}
static void F_50 ( unsigned long V_178 )
{
struct V_1 * V_44 ;
unsigned long V_72 ;
V_44 = (struct V_1 * ) V_178 ;
F_35 ( & V_44 -> V_123 , V_72 ) ;
if ( V_44 -> V_113 ) {
F_27 ( L_13
L_14 , F_28 ( V_44 -> V_60 ) ,
V_44 -> V_113 -> V_80 -> V_96 ) ;
if ( V_44 -> V_64 ) {
F_11 ( V_179 ,
V_44 -> V_54 + V_57 ) ;
V_44 -> V_64 -> error = - V_156 ;
F_29 ( V_44 ) ;
} else {
if ( V_44 -> V_80 )
V_44 -> V_80 -> error = - V_156 ;
else
V_44 -> V_113 -> V_80 -> error = - V_156 ;
F_31 ( & V_44 -> V_119 ) ;
}
}
F_38 () ;
F_39 ( & V_44 -> V_123 , V_72 ) ;
}
static void F_51 ( unsigned long V_180 )
{
struct V_1 * V_2 ;
unsigned long V_72 ;
struct V_121 * V_113 ;
V_2 = (struct V_1 * ) V_180 ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
F_52 ( & V_2 -> V_93 ) ;
V_113 = V_2 -> V_113 ;
V_2 -> V_113 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_64 = NULL ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
F_53 ( V_2 -> V_60 , V_113 ) ;
}
static void F_54 ( struct V_181 * V_182 )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
unsigned long V_72 ;
T_4 V_122 ;
V_2 = F_55 ( V_182 , struct V_1 , V_174 ) ;
V_3 = V_2 -> V_54 ;
F_11 ( V_179 , V_3 + V_57 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
V_3 = V_2 -> V_14 ;
F_8 ( V_124 , V_3 + V_17 ) ;
V_3 = V_2 -> V_4 ;
V_122 = F_36 ( V_3 + V_11 ) ;
if ( ! ( V_122 & V_126 ) ) {
if ( V_2 -> V_113 ) {
F_27 ( L_15 ,
F_28 ( V_2 -> V_60 ) ) ;
V_2 -> V_113 -> V_80 -> error = - V_128 ;
F_31 ( & V_2 -> V_119 ) ;
}
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
F_43 ( V_2 ) ;
F_35 ( & V_2 -> V_123 , V_72 ) ;
}
F_38 () ;
F_39 ( & V_2 -> V_123 , V_72 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_56 ( V_2 -> V_60 , F_57 ( 500 ) ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_120 * V_60 = V_2 -> V_60 ;
void T_1 * V_3 ;
T_3 V_183 ;
T_3 V_122 ;
F_59 ( & V_2 -> V_93 ) ;
V_2 -> V_93 . V_64 = ( unsigned long ) V_2 ;
V_2 -> V_93 . V_184 = F_50 ;
F_60 ( & V_2 -> V_123 ) ;
V_60 -> V_185 = V_186 ;
V_60 -> V_187 = V_188 ;
V_60 -> V_189 = V_190 | V_191 | V_132 ;
V_60 -> V_192 = V_193 | V_194 ;
V_60 -> V_195 = & V_196 ;
V_60 -> V_197 = 1 ;
V_60 -> V_67 = V_198 ;
V_60 -> V_69 = V_199 ;
V_60 -> V_200 = V_60 -> V_67 * V_60 -> V_69 ;
V_60 -> V_201 = V_60 -> V_200 ;
F_61 ( & V_2 -> V_174 , F_54 ) ;
F_62 ( & V_2 -> V_119 , F_51 ,
( unsigned long ) V_2 ) ;
V_3 = V_2 -> V_4 ;
F_11 ( 0x0 , V_3 + V_10 ) ;
F_13 ( 1 ) ;
V_183 = V_77 | V_78 ;
F_11 ( V_183 , V_3 + V_8 ) ;
V_122 = F_36 ( V_3 + V_11 ) ;
V_122 &= V_125 ;
F_37 ( V_122 , V_3 + V_11 ) ;
V_122 = F_36 ( V_3 + V_202 ) ;
V_122 |= V_203 ;
F_37 ( V_122 , V_3 + V_202 ) ;
F_8 ( 0x0 , V_3 + V_13 ) ;
F_11 ( V_204 , V_3 + V_10 ) ;
F_13 ( 1 ) ;
}
static int F_63 ( struct V_205 * V_206 ,
const struct V_207 * V_208 )
{
struct V_120 * V_60 ;
struct V_1 * V_44 ;
T_3 V_209 , V_210 ;
V_91 V_131 ;
int V_211 ;
F_64 ( V_212
L_16 ,
F_65 ( V_206 ) , ( int ) V_206 -> V_213 , ( int ) V_206 -> V_214 ,
( int ) V_206 -> V_215 ) ;
V_211 = F_66 ( V_206 ) ;
if ( V_211 )
return V_211 ;
V_211 = F_67 ( V_206 , V_212 ) ;
if ( V_211 )
goto V_216;
F_68 ( V_206 , V_217 , 0 ) ;
F_68 ( V_206 , V_218 , 0 ) ;
V_60 = F_69 ( sizeof( struct V_1 ) , & V_206 -> V_219 ) ;
if ( ! V_60 ) {
V_211 = - V_220 ;
goto V_221;
}
V_44 = F_34 ( V_60 ) ;
V_44 -> V_60 = V_60 ;
F_70 ( & V_206 -> V_219 , V_44 ) ;
V_210 = F_71 ( V_206 , 0 ) ;
V_209 = F_72 ( V_206 , 0 ) ;
V_44 -> V_222 = F_73 ( V_209 , V_210 ) ;
if ( ! V_44 -> V_222 ) {
V_211 = - V_220 ;
goto V_223;
}
V_44 -> V_4 =
V_44 -> V_222 + V_224 ;
V_44 -> V_54 =
V_44 -> V_222 + V_225 ;
V_44 -> V_14 =
V_44 -> V_222 + V_226 ;
V_44 -> V_129 = V_132 ;
V_131 = V_23 | V_24 ;
F_8 ( V_131 , V_44 -> V_14 + V_15 ) ;
F_12 ( V_44 ) ;
V_131 |= V_153 ;
F_8 ( V_131 , V_44 -> V_14 + V_15 ) ;
F_13 ( 3 ) ;
F_58 ( V_44 ) ;
V_211 =
F_74 ( V_206 -> V_163 , F_46 , V_227 , V_212 ,
V_44 ) ;
if ( V_211 )
goto V_228;
F_8 ( V_229 ,
V_44 -> V_14 + V_18 ) ;
F_8 ( V_230 ,
V_44 -> V_14 + V_30 ) ;
if ( V_206 -> V_231 == V_232 &&
V_206 -> V_233 == 0x3891 )
V_44 -> V_45 = V_46 ;
F_75 ( V_60 ) ;
return 0 ;
V_228:
F_76 ( V_44 -> V_222 ) ;
V_223:
F_70 ( & V_206 -> V_219 , NULL ) ;
F_77 ( V_60 ) ;
V_221:
F_78 ( V_206 ) ;
V_216:
F_79 ( V_206 ) ;
return V_211 ;
}
static void F_80 ( struct V_205 * V_206 )
{
struct V_1 * V_44 = F_81 ( V_206 ) ;
unsigned long V_72 ;
V_91 V_131 ;
F_35 ( & V_44 -> V_123 , V_72 ) ;
V_44 -> V_127 = 1 ;
F_8 ( 0x0 , V_44 -> V_14 + V_18 ) ;
F_38 () ;
if ( V_44 -> V_113 ) {
F_27 ( L_17
L_18 , F_28 ( V_44 -> V_60 ) ) ;
F_11 ( V_179 ,
V_44 -> V_54 + V_57 ) ;
F_38 () ;
V_44 -> V_113 -> V_80 -> error = - V_128 ;
if ( V_44 -> V_113 -> V_114 )
V_44 -> V_113 -> V_114 -> error = - V_128 ;
F_31 ( & V_44 -> V_119 ) ;
}
F_39 ( & V_44 -> V_123 , V_72 ) ;
F_82 ( V_44 -> V_60 ) ;
F_83 ( V_206 -> V_163 , V_44 ) ;
F_84 ( & V_44 -> V_93 ) ;
F_85 ( & V_44 -> V_119 ) ;
V_131 = F_5 ( V_44 -> V_14 + V_15 ) ;
V_131 &= ~ V_24 ;
F_8 ( V_131 , V_44 -> V_14 + V_15 ) ;
F_76 ( V_44 -> V_222 ) ;
F_70 ( & V_206 -> V_219 , NULL ) ;
F_77 ( V_44 -> V_60 ) ;
F_78 ( V_206 ) ;
F_79 ( V_206 ) ;
F_64 ( V_212
L_19 ,
F_65 ( V_206 ) , ( int ) V_206 -> V_213 , ( int ) V_206 -> V_214 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_31 * V_234 ;
void T_1 * V_3 ;
T_3 V_183 ;
T_4 V_122 ;
V_234 = & ( V_2 -> V_32 ) ;
V_3 = V_2 -> V_4 ;
F_11 ( 0x0 , V_3 + V_10 ) ;
V_183 = V_77 | V_78 ;
F_11 ( V_183 , V_3 + V_8 ) ;
V_122 = F_36 ( V_3 + V_11 ) ;
V_122 &= V_125 ;
F_37 ( V_122 , V_3 + V_11 ) ;
V_122 = F_36 ( V_3 + V_202 ) ;
V_122 |= V_203 ;
F_37 ( V_122 , V_3 + V_202 ) ;
F_11 ( V_234 -> V_33 , V_3 + V_5 ) ;
F_11 ( V_234 -> V_34 , V_3 + V_6 ) ;
F_11 ( V_234 -> V_38 , V_3 + V_10 ) ;
F_11 ( V_234 -> V_40 , V_3 + V_41 ) ;
F_11 ( V_234 -> V_42 , V_3 + V_12 ) ;
F_11 ( V_234 -> V_43 , V_3 + V_13 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_87 ( struct V_205 * V_206 , T_6 V_235 )
{
struct V_1 * V_2 ;
int V_211 = 0 ;
V_2 = F_81 ( V_206 ) ;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
V_211 = F_88 ( V_2 -> V_60 ) ;
F_89 ( V_206 ) ;
F_90 ( V_206 , F_91 ( V_206 , V_235 ) , 0 ) ;
F_79 ( V_206 ) ;
F_92 ( V_206 , F_91 ( V_206 , V_235 ) ) ;
return V_211 ;
}
static int F_93 ( struct V_205 * V_206 )
{
struct V_1 * V_44 ;
int V_211 = 0 ;
V_91 V_131 ;
V_44 = F_81 ( V_206 ) ;
V_131 = V_24 ;
if ( V_44 -> V_129 == V_132 )
V_131 &= ~ V_23 ;
else
V_131 |= V_23 ;
F_8 ( V_131 , V_44 -> V_14 + V_15 ) ;
F_12 ( V_44 ) ;
V_131 |= V_153 ;
F_8 ( V_131 , V_44 -> V_14 + V_15 ) ;
F_13 ( 3 ) ;
F_13 ( 100 ) ;
F_92 ( V_206 , V_236 ) ;
F_94 ( V_206 ) ;
V_211 = F_66 ( V_206 ) ;
if ( V_211 )
return V_211 ;
F_7 ( V_44 ) ;
F_86 ( V_44 ) ;
V_211 = F_95 ( V_44 -> V_60 ) ;
return V_211 ;
}
