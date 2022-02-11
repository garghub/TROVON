static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 )
{
T_1 V_8 ;
int V_9 ;
V_9 = ( V_7 / V_6 ) - 1 ;
if ( V_9 > 0xFF || V_9 < 0 ) {
F_6 ( V_2 -> V_10 -> V_11 ,
L_1 ) ;
return - V_12 ;
}
V_8 = F_1 ( V_2 , V_13 ) ;
V_8 &= ~ V_14 ;
F_3 ( V_2 , V_8 | ( V_9 << V_15 ) ,
V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_16 * V_17 , T_1 V_18 )
{
switch ( V_18 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_17 -> V_23 = V_24 ;
V_17 -> V_25 = V_26 ;
V_17 -> V_27 = V_28 ;
break;
case V_29 :
case V_30 :
V_17 -> V_23 = V_31 ;
V_17 -> V_25 = V_32 ;
V_17 -> V_27 = V_28 ;
break;
case V_33 :
case V_34 :
V_17 -> V_23 = V_35 ;
V_17 -> V_25 = V_36 ;
V_17 -> V_27 = V_28 ;
break;
case V_37 :
V_17 -> V_23 = V_38 ;
V_17 -> V_25 = V_39 ;
V_17 -> V_27 = V_28 ;
break;
case V_40 :
V_17 -> V_23 = V_41 ;
V_17 -> V_25 = V_39 ;
V_17 -> V_27 = V_28 ;
break;
case V_42 :
V_17 -> V_23 = V_38 ;
V_17 -> V_25 = V_39 ;
V_17 -> V_27 = V_43 ;
break;
case V_44 :
V_17 -> V_23 = V_41 ;
V_17 -> V_25 = V_39 ;
V_17 -> V_27 = V_43 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_17 -> V_23 = V_50 ;
V_17 -> V_25 = V_51 ;
V_17 -> V_27 = V_28 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_17 -> V_23 = V_50 ;
V_17 -> V_25 = V_60 ;
V_17 -> V_27 = V_28 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_17 -> V_23 = V_50 ;
V_17 -> V_25 = V_60 ;
V_17 -> V_27 = V_65 ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_17 -> V_23 = V_50 ;
V_17 -> V_25 = V_70 ;
V_17 -> V_27 = V_71 ;
break;
case V_72 :
V_17 -> V_23 = V_73 ;
V_17 -> V_25 = V_51 ;
V_17 -> V_27 = V_28 ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static void F_8 ( struct V_16 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
F_7 ( V_74 , V_78 -> V_79 ) ;
switch ( V_76 -> type ) {
case V_80 :
V_74 -> V_81 = 1 ;
V_74 -> V_82 = ( V_76 -> V_83 &
V_84 ) ? 1 : 0 ;
V_74 -> V_85 = ( V_76 -> V_83 &
V_86 ) ? 1 : 0 ;
V_74 -> V_87 = ( V_76 -> V_83 &
V_88 ) ? 1 : 0 ;
V_74 -> V_89 = V_90 ;
break;
case V_91 :
V_74 -> V_81 = 0 ;
if ( F_9 ( V_78 -> V_92 ) )
V_74 -> V_89 = V_93 ;
else
V_74 -> V_89 = V_94 ;
break;
case V_95 :
V_74 -> V_89 = V_96 ;
break;
default:
break;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_16 V_17 ;
unsigned long V_83 ;
T_1 V_97 = 0 ;
F_8 ( & V_17 , V_76 , V_78 ) ;
V_97 |= V_17 . V_27 << V_98 |
V_17 . V_23 << V_99 |
V_17 . V_100 << V_101 |
V_17 . V_82 << V_102 |
V_17 . V_85 << V_103 |
V_17 . V_87 << V_104 |
V_17 . V_81 << V_105 |
V_17 . V_89 << V_106 |
V_17 . V_107 << V_108 |
V_17 . V_109 << V_110 |
V_17 . V_111 << V_112 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
F_3 ( V_2 , V_97 , V_13 ) ;
F_3 ( V_2 ,
( V_78 -> V_114 - 1 ) | ( ( V_78 -> V_115 - 1 ) << 16 ) ,
V_116 ) ;
switch ( V_17 . V_89 ) {
case V_94 :
F_3 ( V_2 , 0x40030 , V_117 ) ;
F_3 ( V_2 , 0xFF0000 , V_118 ) ;
break;
case V_93 :
if ( V_78 -> V_114 == 720 && V_78 -> V_115 == 576 ) {
F_3 ( V_2 , 0x40596 | V_119 ,
V_117 ) ;
F_3 ( V_2 , 0xD07DF , V_120 ) ;
F_3 ( V_2 , 0xFF0000 , V_118 ) ;
} else if ( V_78 -> V_114 == 720 && V_78 -> V_115 == 480 ) {
F_3 ( V_2 , 0xD07DF | V_119 ,
V_117 ) ;
F_3 ( V_2 , 0x40596 , V_120 ) ;
F_3 ( V_2 , 0xFF0000 , V_118 ) ;
} else {
F_6 ( V_2 -> V_10 -> V_11 ,
L_2 ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
return - V_12 ;
}
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
F_3 ( V_2 , 0x40030 | V_119 ,
V_117 ) ;
F_3 ( V_2 , 0xFF0000 , V_118 ) ;
break;
case V_90 :
case V_96 :
F_3 ( V_2 , 0 , V_117 ) ;
break;
}
F_13 ( V_2 -> V_10 -> V_11 , L_3 ,
F_1 ( V_2 , V_13 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_4 ,
F_1 ( V_2 , V_125 ) ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
return 0 ;
}
bool F_14 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
T_1 V_126 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_126 =
( F_1 ( V_2 , V_13 ) &
V_127 ) >>
V_106 ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
switch ( V_126 ) {
case V_90 :
case V_96 :
case V_94 :
case V_121 :
case V_122 :
return false ;
case V_93 :
case V_123 :
case V_124 :
return true ;
default:
F_6 ( V_2 -> V_10 -> V_11 ,
L_5 , V_2 -> V_128 ) ;
return false ;
}
}
void F_15 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
unsigned long V_83 ;
T_1 V_131 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_131 = F_1 ( V_2 , V_125 ) ;
V_130 -> V_114 = ( V_131 & 0xFFFF ) + 1 ;
V_130 -> V_115 = ( V_131 >> 16 & 0xFFFF ) + 1 ;
V_131 = F_1 ( V_2 , V_132 ) ;
V_130 -> V_133 = ( V_131 & V_134 ) >> V_135 ;
V_130 -> V_136 = ( V_131 & V_137 ) >> V_138 ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
unsigned long V_83 ;
T_1 V_131 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
F_3 ( V_2 , ( V_130 -> V_114 - 1 ) | ( ( V_130 -> V_115 - 1 ) << 16 ) ,
V_125 ) ;
V_131 = F_1 ( V_2 , V_132 ) ;
V_131 &= ~ ( V_134 | V_137 ) ;
V_131 |= ( ( V_130 -> V_136 << V_138 ) | ( V_130 -> V_133 << V_135 ) ) ;
F_3 ( V_2 , V_131 , V_132 ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
}
void F_17 ( struct V_1 * V_2 , bool V_139 ,
T_1 V_140 , T_1 V_141 , T_1 V_142 ,
T_1 V_143 )
{
unsigned long V_83 ;
T_1 V_7 = F_18 ( V_2 -> V_144 ) ;
T_1 V_8 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_8 = F_1 ( V_2 , V_145 ) ;
if ( ! V_139 ) {
V_8 &= ~ V_146 ;
F_3 ( V_2 , V_8 , V_145 ) ;
} else {
F_5 ( V_2 , V_143 , V_7 ) ;
V_8 &= ~ ( V_147 | V_148 |
V_149 ) ;
V_8 |= V_146 ;
V_8 |= ( V_140 << V_150 ) |
( V_141 << V_151 ) |
( V_142 << V_152 ) ;
F_3 ( V_2 , V_8 , V_145 ) ;
}
F_12 ( & V_2 -> V_113 , V_83 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_153 ,
struct V_77 * V_78 )
{
struct V_16 V_17 ;
unsigned long V_83 ;
T_1 V_8 ;
if ( V_153 > 3 )
return - V_12 ;
F_7 ( & V_17 , V_78 -> V_79 ) ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_8 = F_1 ( V_2 , V_154 ) ;
V_8 &= ~ ( 0xff << ( V_153 * 8 ) ) ;
V_8 |= ( V_17 . V_25 << ( V_153 * 8 ) ) ;
F_3 ( V_2 , V_8 , V_154 ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_155 ,
T_1 V_156 , T_1 V_128 )
{
unsigned long V_83 ;
T_1 V_8 ;
if ( V_156 > 5 || V_128 > 3 )
return - V_12 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_8 = F_1 ( V_2 , V_157 ) ;
V_8 &= ~ ( V_158 | V_159 |
V_160 ) ;
V_8 |= ( V_156 << V_161 ) |
( V_128 << V_162 ) |
( V_155 << V_163 ) ;
F_3 ( V_2 , V_8 , V_157 ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , enum V_164 V_165 )
{
unsigned long V_83 ;
T_1 V_166 , V_167 ;
if ( V_165 == V_168 )
V_167 = V_169 ;
else
V_167 = V_170 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_166 = F_1 ( V_2 , V_13 ) ;
V_166 &= ~ V_171 ;
V_166 |= ( V_167 << V_172 ) ;
F_3 ( V_2 , V_166 , V_13 ) ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_10 , V_2 -> V_173 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_10 , V_2 -> V_173 ) ;
return 0 ;
}
struct V_1 * F_26 ( struct V_174 * V_10 , int V_128 )
{
unsigned long V_83 ;
struct V_1 * V_2 , * V_175 ;
if ( V_128 > 1 )
return F_27 ( - V_12 ) ;
V_2 = V_10 -> V_176 [ V_128 ] ;
V_175 = V_2 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
if ( V_2 -> V_177 ) {
V_175 = F_27 ( - V_178 ) ;
goto V_179;
}
V_2 -> V_177 = true ;
V_179:
F_12 ( & V_2 -> V_113 , V_83 ) ;
return V_175 ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
F_11 ( & V_2 -> V_113 , V_83 ) ;
V_2 -> V_177 = false ;
F_12 ( & V_2 -> V_113 , V_83 ) ;
}
int F_29 ( struct V_174 * V_10 , struct V_180 * V_11 , int V_128 ,
unsigned long V_4 , T_1 V_173 , struct V_181 * V_144 )
{
struct V_1 * V_2 ;
if ( V_128 > 1 )
return - V_182 ;
V_2 = F_30 ( V_11 , sizeof( * V_2 ) , V_183 ) ;
if ( ! V_2 )
return - V_184 ;
V_10 -> V_176 [ V_128 ] = V_2 ;
F_31 ( & V_2 -> V_113 ) ;
V_2 -> V_173 = V_173 ;
V_2 -> V_128 = V_128 ;
V_2 -> V_144 = V_144 ;
V_2 -> V_4 = F_32 ( V_11 , V_4 , V_185 ) ;
if ( ! V_2 -> V_4 )
return - V_184 ;
F_13 ( V_11 , L_6 ,
V_128 , V_4 , V_2 -> V_4 ) ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_33 ( struct V_174 * V_10 , int V_128 )
{
}
void F_34 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_10 -> V_11 , L_7 ,
F_1 ( V_2 , V_13 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_8 ,
F_1 ( V_2 , V_116 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_9 ,
F_1 ( V_2 , V_125 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_10 ,
F_1 ( V_2 , V_132 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_11 ,
F_1 ( V_2 , V_145 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_12 ,
F_1 ( V_2 , V_117 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_13 ,
F_1 ( V_2 , V_120 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_14 ,
F_1 ( V_2 , V_118 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_15 ,
F_1 ( V_2 , V_154 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_16 ,
F_1 ( V_2 , V_157 ) ) ;
}
