static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 =
& V_4 -> V_10 ;
if ( V_6 -> V_11 > 1 ) {
V_4 -> V_12 = 1 ;
V_9 -> V_13 = true ;
V_9 -> V_14 = true ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = V_6 -> V_18 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = V_6 -> V_23 ;
V_9 -> V_24 = 0 ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = 0 ;
F_3 ( V_2 -> V_7 ,
L_1 ,
V_27 , V_6 -> V_11 , V_9 -> V_17 ,
V_9 -> V_22 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_28 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
switch ( V_6 -> V_11 ) {
case 1 :
switch ( V_28 ) {
case 8000 :
V_30 -> V_31 =
V_32 ;
break;
case 16000 :
V_30 -> V_31 =
V_33 ;
break;
case 44100 :
V_30 -> V_31 =
V_34 ;
break;
case 48000 :
V_30 -> V_31 =
V_35 ;
break;
default:
F_5 ( V_2 -> V_7 ,
L_2 ,
V_27 , V_28 ) ;
return - V_36 ;
}
break;
case 2 :
V_30 -> V_31 = V_37 ;
break;
case 8 :
V_30 -> V_31 = V_38 ;
break;
case 16 :
V_30 -> V_31 = V_39 ;
break;
default:
F_5 ( V_2 -> V_7 ,
L_3 ,
V_27 , V_6 -> V_11 ) ;
return - V_36 ;
}
V_30 -> V_40 =
V_30 -> V_31 + 1 ;
F_3 ( V_2 -> V_7 , L_4 ,
V_27 ,
V_30 -> V_40 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_28 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
T_1 V_41 = V_42 ;
V_30 -> V_43 = 0 ;
switch ( V_6 -> V_11 ) {
case 1 :
V_41 = V_42 ;
break;
case 2 :
V_41 = V_44 ;
break;
case 8 :
V_41 = V_45 ;
break;
case 16 :
V_41 = V_46 ;
break;
default:
F_5 ( V_2 -> V_7 ,
L_3 ,
V_27 , V_6 -> V_11 ) ;
return - V_36 ;
}
V_30 -> V_47 = V_41 ;
V_30 -> V_48 = V_41 ;
V_30 -> V_49 = V_41 ;
V_30 -> V_50 = V_41 ;
V_30 -> V_51 = V_52 ;
V_30 -> V_53 = V_52 ;
V_30 -> V_54 = V_52 ;
V_30 -> V_55 = V_52 ;
return F_4 ( V_2 , V_28 , V_30 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_56 ,
struct V_3 * V_4 )
{
switch ( V_56 & V_57 ) {
case V_58 :
break;
case V_59 :
V_4 -> V_60 ^= 1 << V_61 ;
V_4 -> V_62 ^= 1 << V_63 ;
break;
default:
F_5 ( V_2 -> V_7 ,
L_5 ,
V_27 , V_56 ) ;
return - V_36 ;
}
switch ( V_56 & V_64 ) {
case V_65 :
F_3 ( V_2 -> V_7 , L_6 , V_27 ) ;
V_4 -> V_66 = 0x20 ;
V_4 -> V_67 = 0 ;
V_4 -> V_68 = 1 << V_69 ;
V_4 -> V_70 = 0 ;
V_4 -> V_71 = 0 ;
V_4 -> V_72 = 0x2 << V_73 ;
break;
case V_74 :
F_3 ( V_2 -> V_7 , L_7 , V_27 ) ;
V_4 -> V_70 = V_75 ;
V_4 -> V_68 = V_76 ;
V_4 -> V_71 = V_77 ;
V_4 -> V_67 = V_78 ;
V_4 -> V_72 = 1 << V_73 ;
break;
default:
F_5 ( V_2 -> V_7 , L_8 ,
V_27 , V_56 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_56 ,
struct V_29 * V_30 )
{
V_30 -> V_79 = V_80 ;
V_30 -> V_81 = V_80 ;
V_30 -> V_82 = V_83 ;
V_30 -> V_84 = V_83 ;
V_30 -> V_85 = V_86 ;
V_30 -> V_87 = V_86 ;
V_30 -> V_60 = F_9 ( V_88 ) ;
V_30 -> V_62 = V_88 << V_63 ;
if ( ( V_56 & V_89 ) == V_90 ) {
F_3 ( V_2 -> V_7 , L_9 , V_27 ) ;
V_30 -> V_91 = V_92 ;
V_30 -> V_93 = V_94 ;
V_30 -> V_95 = V_96 ;
V_30 -> V_97 = V_96 ;
} else {
F_3 ( V_2 -> V_7 , L_10 , V_27 ) ;
V_30 -> V_91 = V_94 ;
V_30 -> V_93 = V_92 ;
V_30 -> V_95 = V_98 ;
V_30 -> V_97 = V_98 ;
}
V_30 -> V_99 = V_100 ;
V_30 -> V_101 = V_100 ;
V_30 -> V_102 = V_103 ;
V_30 -> V_104 = V_105 ;
V_30 -> V_106 = V_107 ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 )
{
V_30 -> V_79 = V_108 ;
V_30 -> V_81 = V_108 ;
V_30 -> V_82 = V_109 ;
V_30 -> V_84 = V_109 ;
V_30 -> V_85 = V_86 ;
V_30 -> V_87 = V_86 ;
V_30 -> V_60 = F_9 ( V_110 ) ;
V_30 -> V_62 = V_110 << V_63 ;
V_30 -> V_48 = V_42 ;
V_30 -> V_50 = V_42 ;
V_30 -> V_47 = V_42 ;
V_30 -> V_49 = V_42 ;
V_30 -> V_53 = V_52 ;
V_30 -> V_55 = V_52 ;
V_30 -> V_51 = V_52 ;
V_30 -> V_54 = V_52 ;
V_30 -> V_91 = V_92 ;
V_30 -> V_93 = V_94 ;
V_30 -> V_95 = V_98 ;
V_30 -> V_97 = V_98 ;
V_30 -> V_101 = V_100 ;
V_30 -> V_99 = V_100 ;
V_30 -> V_102 = V_103 ;
V_30 -> V_104 = V_105 ;
V_30 -> V_106 = V_107 ;
return 0 ;
}
static int F_11 ( struct V_111 * V_112 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_29 * V_30 = & V_4 -> V_113 ;
struct V_114 * V_115 = V_112 -> V_115 ;
unsigned int V_56 = V_6 -> V_56 ;
int V_116 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_117 = V_6 -> V_118 ;
V_4 -> V_119 = V_120 ;
V_4 -> V_121 = V_122 ;
V_4 -> V_123 = 1 ;
V_4 -> V_124 = V_112 -> V_125 == V_126 ?
V_127 : V_128 ;
V_4 -> V_129 = V_130 ;
V_4 -> V_131 = V_115 -> V_28 ;
F_3 ( V_2 -> V_7 , L_11 ,
V_27 , V_4 -> V_117 , V_4 -> V_131 ) ;
V_30 -> V_40 = 1 ;
F_3 ( V_2 -> V_7 , L_12 , V_27 ,
V_115 -> V_28 , V_115 -> V_132 ) ;
switch ( V_56 &
( V_89 | V_64 ) ) {
case V_133 | V_74 :
F_3 ( V_2 -> V_7 , L_13 , V_27 ) ;
V_4 -> V_134 = 1 ;
V_4 -> V_135 = V_136 ;
break;
case V_133 | V_65 :
F_3 ( V_2 -> V_7 , L_13 , V_27 ) ;
V_4 -> V_129 = V_137 ;
V_4 -> V_135 = V_136 ;
V_116 = F_10 ( V_30 ) ;
if ( V_116 < 0 )
return V_116 ;
break;
case V_90 | V_74 :
case V_90 | V_65 :
case V_138 | V_74 :
case V_138 | V_65 :
F_3 ( V_2 -> V_7 , L_14 , V_27 ) ;
V_4 -> V_129 = V_137 ;
V_4 -> V_135 = V_139 ;
V_116 = F_8 ( V_2 , V_56 , V_30 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_1 ( V_2 , V_4 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_6 ( V_2 , V_115 -> V_28 , V_30 ) ;
if ( V_116 < 0 )
return V_116 ;
break;
default:
F_5 ( V_2 -> V_7 , L_15 ,
V_27 , V_56 ) ;
return - V_36 ;
}
return F_7 ( V_2 , V_56 , V_4 ) ;
}
static int F_12 ( struct V_111 * V_112 ,
struct V_1 * V_2 )
{
int V_116 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 , L_16 , V_27 , V_2 -> V_140 ,
F_13 ( V_112 ) ) ;
V_116 = F_14 ( V_6 -> V_141 ) ;
if ( V_116 != 0 ) {
F_5 ( V_6 -> V_142 -> V_7 ,
L_17 , V_27 ) ;
return V_116 ;
}
F_3 ( V_2 -> V_7 , L_18 , V_27 ) ;
V_116 = F_15 ( V_6 -> V_143 ) ;
if ( V_116 ) {
F_5 ( V_6 -> V_142 -> V_7 ,
L_19 , V_27 ) ;
goto V_144;
}
V_116 = F_15 ( V_6 -> V_145 ) ;
if ( V_116 ) {
F_5 ( V_6 -> V_142 -> V_7 ,
L_20 , V_27 ) ;
goto V_146;
}
return V_116 ;
V_146:
F_16 ( V_6 -> V_143 ) ;
V_144:
F_17 ( V_6 -> V_141 ) ;
return V_116 ;
}
static void F_18 ( struct V_111 * V_112 ,
struct V_1 * V_2 )
{
int V_116 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
bool V_147 = ( V_112 -> V_125 == V_126 ) ;
F_3 ( V_2 -> V_7 , L_16 , V_27 , V_2 -> V_140 ,
F_13 ( V_112 ) ) ;
if ( V_6 -> V_148 == 1 ) {
F_19 ( V_149 ,
L_21 , 50 ) ;
V_6 -> V_148 = 0 ;
}
if ( F_20 ( V_6 -> V_142 ,
V_147 ? V_127 : V_128 ) ) {
F_5 ( V_2 -> V_7 ,
L_22 ,
V_27 , V_2 -> V_140 , F_13 ( V_112 ) ) ;
}
F_16 ( V_6 -> V_145 ) ;
F_16 ( V_6 -> V_143 ) ;
V_116 = F_17 ( V_6 -> V_141 ) ;
if ( V_116 < 0 )
F_5 ( V_2 -> V_7 ,
L_23 ,
V_27 , V_116 ) ;
}
static int F_21 ( struct V_111 * V_112 ,
struct V_1 * V_2 )
{
int V_116 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_114 * V_115 = V_112 -> V_115 ;
struct V_3 V_4 ;
F_3 ( V_2 -> V_7 , L_24 , V_27 ,
V_2 -> V_140 , F_13 ( V_112 ) , V_115 -> V_28 ) ;
F_11 ( V_112 , V_2 , & V_4 ) ;
V_116 = F_22 ( V_6 -> V_142 , & V_4 ) ;
if ( V_116 < 0 ) {
F_5 ( V_2 -> V_7 , L_25 ,
V_27 , V_116 ) ;
return V_116 ;
}
if ( ( V_6 -> V_56 & V_64 ) &&
( V_6 -> V_142 -> V_150 > 19200000 ) ) {
F_19 ( V_149 ,
L_26 , 100 ) ;
V_6 -> V_148 = 1 ;
} else {
F_19 ( V_149 ,
L_26 , 50 ) ;
V_6 -> V_148 = 0 ;
}
return V_116 ;
}
static int F_23 ( struct V_111 * V_112 ,
struct V_151 * V_152 ,
struct V_1 * V_2 )
{
unsigned int V_153 , V_154 ;
struct V_114 * V_115 = V_112 -> V_115 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 , L_16 ,
V_27 , V_2 -> V_140 , F_13 ( V_112 ) ) ;
switch ( V_6 -> V_56 & V_89 ) {
case V_133 :
F_24 ( V_115 ,
V_155 ,
1 , 2 ) ;
break;
case V_138 :
case V_90 :
V_153 = V_112 -> V_125 == V_126 ?
V_6 -> V_18 :
V_6 -> V_23 ;
V_154 = F_25 ( V_153 ) ;
F_3 ( V_2 -> V_7 , L_27 , V_154 ) ;
F_24 ( V_115 ,
V_155 ,
V_154 , V_154 ) ;
break;
default:
F_5 ( V_2 -> V_7 ,
L_28 ,
V_27 , V_6 -> V_56 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 , L_29 , V_27 , V_2 -> V_140 ) ;
switch ( V_56 & ( V_89 |
V_64 ) ) {
case V_133 | V_74 :
case V_133 | V_65 :
case V_138 | V_74 :
case V_138 | V_65 :
case V_90 | V_74 :
case V_90 | V_65 :
break;
default:
F_5 ( V_2 -> V_7 ,
L_30 ,
V_27 , V_6 -> V_56 ) ;
return - V_36 ;
}
switch ( V_56 & V_57 ) {
case V_58 :
case V_59 :
case V_156 :
break;
default:
F_5 ( V_2 -> V_7 ,
L_31 ,
V_27 , V_6 -> V_56 ) ;
return - V_36 ;
}
V_6 -> V_56 = V_56 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_23 ,
int V_11 , int V_157 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
unsigned int V_158 ;
switch ( V_11 ) {
case 1 :
V_158 = 0x01 ;
break;
case 2 :
V_158 = 0x03 ;
break;
case 8 :
V_158 = 0xFF ;
break;
case 16 :
V_158 = 0xFFFF ;
break;
default:
F_5 ( V_2 -> V_7 , L_32 ,
V_27 , V_11 ) ;
return - V_36 ;
}
V_6 -> V_11 = V_11 ;
if ( ! ( V_157 == 16 ) ) {
F_5 ( V_2 -> V_7 , L_33 ,
V_27 , V_157 ) ;
return - V_36 ;
}
V_6 -> V_157 = V_157 ;
V_6 -> V_18 = V_18 & V_158 ;
V_6 -> V_23 = V_23 & V_158 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_159 , unsigned int V_160 , int V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 , L_34 ,
V_27 , V_2 -> V_140 , V_159 , V_160 ) ;
switch ( V_159 ) {
case V_162 :
V_6 -> V_118 = V_160 ;
break;
default:
F_5 ( V_2 -> V_7 , L_35 ,
V_27 , V_2 -> V_140 , V_159 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_29 ( struct V_111 * V_112 ,
int V_163 , struct V_1 * V_2 )
{
int V_116 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 , L_36 ,
V_27 , V_2 -> V_140 , F_13 ( V_112 ) ,
( int ) V_6 -> V_142 -> V_140 , V_163 ) ;
V_116 = F_30 ( V_6 -> V_142 , V_163 , V_112 -> V_125 ) ;
return V_116 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_164 * V_165 ;
struct V_164 * V_166 ;
V_165 = F_32 ( V_2 -> V_7 ,
sizeof( * V_165 ) ,
V_167 ) ;
if ( ! V_165 )
return - V_168 ;
V_166 = F_32 ( V_2 -> V_7 ,
sizeof( * V_166 ) ,
V_167 ) ;
if ( ! V_166 )
return - V_168 ;
V_165 -> V_169 = V_6 -> V_142 -> V_165 . V_170 ;
V_166 -> V_169 = V_6 -> V_142 -> V_166 . V_170 ;
V_165 -> V_171 = 4 ;
V_166 -> V_171 = 4 ;
F_33 ( V_2 , V_165 , V_166 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_172 * V_173 = V_2 -> V_7 -> V_174 ;
int V_116 ;
if ( ! V_173 ) {
V_116 = F_31 ( V_2 ) ;
return V_116 ;
}
V_6 -> V_142 -> V_165 . V_129 = V_6 -> V_157 ;
V_6 -> V_142 -> V_166 . V_129 = V_6 -> V_157 ;
F_33 ( V_2 ,
& V_6 -> V_142 -> V_165 ,
& V_6 -> V_142 -> V_166 ) ;
return 0 ;
}
static int F_35 ( struct V_175 * V_176 )
{
struct V_5 * V_6 ;
struct V_172 * V_173 = V_176 -> V_7 . V_174 ;
struct V_177 * V_178 = V_176 -> V_7 . V_179 ;
int V_116 = 0 ;
if ( ! V_173 && ! V_178 ) {
F_5 ( & V_176 -> V_7 , L_37 ) ;
return - V_180 ;
}
V_6 = F_32 ( & V_176 -> V_7 ,
sizeof( struct V_5 ) ,
V_167 ) ;
if ( ! V_6 )
return - V_168 ;
V_6 -> V_56 = 0 ;
V_6 -> V_11 = 1 ;
V_6 -> V_18 = 0x01 ;
V_6 -> V_23 = 0x01 ;
V_6 -> V_157 = 16 ;
V_6 -> V_118 = V_181 ;
V_6 -> V_141 = F_36 ( & V_176 -> V_7 , L_38 ) ;
if ( F_37 ( V_6 -> V_141 ) ) {
V_116 = ( int ) F_38 ( V_6 -> V_141 ) ;
F_5 ( & V_176 -> V_7 ,
L_39 ,
V_27 , V_116 ) ;
return V_116 ;
}
F_39 ( V_149 , ( char * ) V_176 -> V_182 , 50 ) ;
V_6 -> V_143 = F_40 ( & V_176 -> V_7 , L_40 ) ;
if ( F_37 ( V_6 -> V_143 ) ) {
V_116 = ( int ) F_38 ( V_6 -> V_143 ) ;
F_5 ( & V_176 -> V_7 ,
L_41 ,
V_27 , V_116 ) ;
return V_116 ;
}
V_6 -> V_145 = F_40 ( & V_176 -> V_7 , NULL ) ;
if ( F_37 ( V_6 -> V_145 ) ) {
V_116 = ( int ) F_38 ( V_6 -> V_145 ) ;
F_5 ( & V_176 -> V_7 ,
L_42 ,
V_27 , V_116 ) ;
return V_116 ;
}
V_116 = F_41 ( V_176 , & V_6 -> V_142 ,
V_176 -> V_7 . V_174 ) ;
if ( ! V_6 -> V_142 ) {
F_5 ( & V_176 -> V_7 ,
L_43 ,
V_27 , V_116 ) ;
return V_116 ;
}
F_42 ( & V_176 -> V_7 , V_6 ) ;
V_116 = F_43 ( & V_176 -> V_7 , & V_183 ,
& V_184 , 1 ) ;
if ( V_116 < 0 ) {
F_5 ( & V_176 -> V_7 , L_44 ,
V_27 , V_6 -> V_142 -> V_140 ) ;
return V_116 ;
}
V_116 = F_44 ( V_176 ) ;
if ( V_116 < 0 ) {
F_5 ( & V_176 -> V_7 ,
L_45 ,
V_27 ) ;
goto V_185;
}
return 0 ;
V_185:
F_45 ( & V_176 -> V_7 ) ;
return V_116 ;
}
static int F_46 ( struct V_175 * V_176 )
{
struct V_5 * V_6 = F_2 ( & V_176 -> V_7 ) ;
F_47 ( V_176 ) ;
F_45 ( & V_176 -> V_7 ) ;
F_48 ( V_149 , L_21 ) ;
F_49 ( V_176 , V_6 -> V_142 ) ;
return 0 ;
}
