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
T_1 V_9 ;
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
V_17 -> V_23 = V_49 ;
V_17 -> V_25 = V_50 ;
V_17 -> V_27 = V_28 ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_17 -> V_23 = V_49 ;
V_17 -> V_25 = V_59 ;
V_17 -> V_27 = V_28 ;
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_17 -> V_23 = V_49 ;
V_17 -> V_25 = V_59 ;
V_17 -> V_27 = V_64 ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_17 -> V_23 = V_49 ;
V_17 -> V_25 = V_69 ;
V_17 -> V_27 = V_70 ;
break;
case V_71 :
V_17 -> V_23 = V_72 ;
V_17 -> V_25 = V_50 ;
V_17 -> V_27 = V_28 ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static void F_8 ( struct V_16 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
F_7 ( V_73 , V_77 -> V_78 ) ;
switch ( V_75 -> type ) {
case V_79 :
V_73 -> V_80 = 1 ;
V_73 -> V_81 = ( V_75 -> V_82 &
V_83 ) ? 1 : 0 ;
V_73 -> V_84 = ( V_75 -> V_82 &
V_85 ) ? 1 : 0 ;
V_73 -> V_86 = ( V_75 -> V_82 &
V_87 ) ? 1 : 0 ;
V_73 -> V_88 = V_89 ;
break;
case V_90 :
V_73 -> V_80 = 0 ;
if ( F_9 ( V_77 -> V_91 ) )
V_73 -> V_88 = V_92 ;
else
V_73 -> V_88 = V_93 ;
break;
case V_94 :
V_73 -> V_88 = V_95 ;
break;
default:
break;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_16 V_17 ;
unsigned long V_82 ;
T_1 V_96 = 0 ;
F_8 ( & V_17 , V_75 , V_77 ) ;
V_96 |= V_17 . V_27 << V_97 |
V_17 . V_23 << V_98 |
V_17 . V_99 << V_100 |
V_17 . V_81 << V_101 |
V_17 . V_84 << V_102 |
V_17 . V_86 << V_103 |
V_17 . V_80 << V_104 |
V_17 . V_88 << V_105 |
V_17 . V_106 << V_107 |
V_17 . V_108 << V_109 |
V_17 . V_110 << V_111 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
F_3 ( V_2 , V_96 , V_13 ) ;
F_3 ( V_2 ,
( V_77 -> V_113 - 1 ) | ( ( V_77 -> V_114 - 1 ) << 16 ) ,
V_115 ) ;
switch ( V_17 . V_88 ) {
case V_93 :
F_3 ( V_2 , 0x40030 , V_116 ) ;
F_3 ( V_2 , 0xFF0000 , V_117 ) ;
break;
case V_92 :
if ( V_77 -> V_113 == 720 && V_77 -> V_114 == 576 ) {
F_3 ( V_2 , 0x40596 | V_118 ,
V_116 ) ;
F_3 ( V_2 , 0xD07DF , V_119 ) ;
F_3 ( V_2 , 0xFF0000 , V_117 ) ;
} else if ( V_77 -> V_113 == 720 && V_77 -> V_114 == 480 ) {
F_3 ( V_2 , 0xD07DF | V_118 ,
V_116 ) ;
F_3 ( V_2 , 0x40596 , V_119 ) ;
F_3 ( V_2 , 0xFF0000 , V_117 ) ;
} else {
F_6 ( V_2 -> V_10 -> V_11 ,
L_2 ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
return - V_12 ;
}
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
F_3 ( V_2 , 0x40030 | V_118 ,
V_116 ) ;
F_3 ( V_2 , 0xFF0000 , V_117 ) ;
break;
case V_89 :
case V_95 :
F_3 ( V_2 , 0 , V_116 ) ;
break;
}
F_13 ( V_2 -> V_10 -> V_11 , L_3 ,
F_1 ( V_2 , V_13 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_4 ,
F_1 ( V_2 , V_124 ) ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
return 0 ;
}
bool F_14 ( struct V_1 * V_2 )
{
unsigned long V_82 ;
T_1 V_125 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_125 =
( F_1 ( V_2 , V_13 ) &
V_126 ) >>
V_105 ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
switch ( V_125 ) {
case V_89 :
case V_95 :
case V_93 :
case V_120 :
case V_121 :
return false ;
case V_92 :
case V_122 :
case V_123 :
return true ;
default:
F_6 ( V_2 -> V_10 -> V_11 ,
L_5 , V_2 -> V_127 ) ;
return false ;
}
}
void F_15 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
unsigned long V_82 ;
T_1 V_130 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_130 = F_1 ( V_2 , V_124 ) ;
V_129 -> V_113 = ( V_130 & 0xFFFF ) + 1 ;
V_129 -> V_114 = ( V_130 >> 16 & 0xFFFF ) + 1 ;
V_130 = F_1 ( V_2 , V_131 ) ;
V_129 -> V_132 = ( V_130 & V_133 ) >> V_134 ;
V_129 -> V_135 = ( V_130 & V_136 ) >> V_137 ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
unsigned long V_82 ;
T_1 V_130 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
F_3 ( V_2 , ( V_129 -> V_113 - 1 ) | ( ( V_129 -> V_114 - 1 ) << 16 ) ,
V_124 ) ;
V_130 = F_1 ( V_2 , V_131 ) ;
V_130 &= ~ ( V_133 | V_136 ) ;
V_130 |= ( ( V_129 -> V_135 << V_137 ) | ( V_129 -> V_132 << V_134 ) ) ;
F_3 ( V_2 , V_130 , V_131 ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
}
void F_17 ( struct V_1 * V_2 , bool V_138 ,
T_1 V_139 , T_1 V_140 , T_1 V_141 ,
T_1 V_142 )
{
unsigned long V_82 ;
T_1 V_7 = F_18 ( V_2 -> V_143 ) ;
T_1 V_8 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_8 = F_1 ( V_2 , V_144 ) ;
if ( V_138 == false ) {
V_8 &= ~ V_145 ;
F_3 ( V_2 , V_8 , V_144 ) ;
} else {
F_5 ( V_2 , V_142 , V_7 ) ;
V_8 &= ~ ( V_146 | V_147 |
V_148 ) ;
V_8 |= V_145 ;
V_8 |= ( V_139 << V_149 ) |
( V_140 << V_150 ) |
( V_141 << V_151 ) ;
F_3 ( V_2 , V_8 , V_144 ) ;
}
F_12 ( & V_2 -> V_112 , V_82 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_152 ,
struct V_76 * V_77 )
{
struct V_16 V_17 ;
unsigned long V_82 ;
T_1 V_8 ;
if ( V_152 > 3 )
return - V_12 ;
F_7 ( & V_17 , V_77 -> V_78 ) ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_8 = F_1 ( V_2 , V_153 ) ;
V_8 &= ~ ( 0xff << ( V_152 * 8 ) ) ;
V_8 |= ( V_17 . V_25 << ( V_152 * 8 ) ) ;
F_3 ( V_2 , V_8 , V_153 ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_154 ,
T_1 V_155 , T_1 V_127 )
{
unsigned long V_82 ;
T_1 V_8 ;
if ( V_155 > 5 || V_127 > 3 )
return - V_12 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_8 = F_1 ( V_2 , V_156 ) ;
V_8 &= ~ ( V_157 | V_158 |
V_159 ) ;
V_8 |= ( V_155 << V_160 ) |
( V_127 << V_161 ) |
( V_154 << V_162 ) ;
F_3 ( V_2 , V_8 , V_156 ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , enum V_163 V_164 )
{
unsigned long V_82 ;
T_1 V_165 , V_166 ;
if ( V_164 == V_167 )
V_166 = V_168 ;
else
V_166 = V_169 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_165 = F_1 ( V_2 , V_13 ) ;
V_165 &= ~ V_170 ;
V_165 |= ( V_166 << V_171 ) ;
F_3 ( V_2 , V_165 , V_13 ) ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_10 , V_2 -> V_172 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_10 , V_2 -> V_172 ) ;
return 0 ;
}
struct V_1 * F_26 ( struct V_173 * V_10 , int V_127 )
{
unsigned long V_82 ;
struct V_1 * V_2 , * V_174 ;
if ( V_127 > 1 )
return F_27 ( - V_12 ) ;
V_2 = V_10 -> V_175 [ V_127 ] ;
V_174 = V_2 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
if ( V_2 -> V_176 ) {
V_174 = F_27 ( - V_177 ) ;
goto V_178;
}
V_2 -> V_176 = true ;
V_178:
F_12 ( & V_2 -> V_112 , V_82 ) ;
return V_174 ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned long V_82 ;
F_11 ( & V_2 -> V_112 , V_82 ) ;
V_2 -> V_176 = false ;
F_12 ( & V_2 -> V_112 , V_82 ) ;
}
int F_29 ( struct V_173 * V_10 , struct V_179 * V_11 , int V_127 ,
unsigned long V_4 , T_1 V_172 , struct V_180 * V_143 )
{
struct V_1 * V_2 ;
if ( V_127 > 1 )
return - V_181 ;
V_2 = F_30 ( V_11 , sizeof( * V_2 ) , V_182 ) ;
if ( ! V_2 )
return - V_183 ;
V_10 -> V_175 [ V_127 ] = V_2 ;
F_31 ( & V_2 -> V_112 ) ;
V_2 -> V_172 = V_172 ;
V_2 -> V_127 = V_127 ;
V_2 -> V_143 = V_143 ;
V_2 -> V_4 = F_32 ( V_11 , V_4 , V_184 ) ;
if ( ! V_2 -> V_4 )
return - V_183 ;
F_13 ( V_11 , L_6 ,
V_127 , V_4 , V_2 -> V_4 ) ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_33 ( struct V_173 * V_10 , int V_127 )
{
}
void F_34 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_10 -> V_11 , L_7 ,
F_1 ( V_2 , V_13 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_8 ,
F_1 ( V_2 , V_115 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_9 ,
F_1 ( V_2 , V_124 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_10 ,
F_1 ( V_2 , V_131 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_11 ,
F_1 ( V_2 , V_144 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_12 ,
F_1 ( V_2 , V_116 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_13 ,
F_1 ( V_2 , V_119 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_14 ,
F_1 ( V_2 , V_117 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_15 ,
F_1 ( V_2 , V_153 ) ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_16 ,
F_1 ( V_2 , V_156 ) ) ;
}
