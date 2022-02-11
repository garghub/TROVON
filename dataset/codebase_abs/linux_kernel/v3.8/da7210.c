static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 -> V_7 . integer . V_7 [ 0 ] ) {
if ( F_3 ( V_6 , V_8 ) & V_9 ) {
F_4 ( V_6 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
}
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_12 ;
if ( V_4 -> V_7 . integer . V_7 [ 0 ] ) {
if ( F_3 ( V_6 , V_13 ) & V_14 )
goto V_15;
if ( ( F_3 ( V_6 , V_16 ) &
( V_17 | V_18 | V_19 |
V_20 ) ) != ( V_17 |
V_18 | V_19 | V_20 ) )
goto V_15;
V_12 = F_3 ( V_6 , V_21 ) ;
if ( ( ( V_12 & V_22 ) < V_23 ) ||
( ( ( V_12 & V_24 ) >> 4 ) <
V_23 ) )
goto V_15;
if ( ( ( F_3 ( V_6 , V_25 ) & V_26 ) <
V_27 ) ||
( ( F_3 ( V_6 , V_28 ) & V_29 ) <
V_27 ) )
goto V_15;
}
return F_5 ( V_2 , V_4 ) ;
V_15:
return - V_11 ;
}
static bool F_7 ( struct V_30 * V_10 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return false ;
default:
return true ;
}
}
static bool F_8 ( struct V_30 * V_10 ,
unsigned int V_31 )
{
switch ( V_31 ) {
case V_36 :
return true ;
default:
return false ;
}
}
static int F_9 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
T_2 V_45 ;
T_2 V_46 , V_47 ;
F_11 ( V_6 , V_48 ,
V_49 | V_50 ) ;
F_11 ( V_6 , V_51 , V_52 | V_53 ) ;
V_45 = 0xFC & F_3 ( V_6 , V_54 ) ;
switch ( F_12 ( V_40 ) ) {
case V_55 :
V_45 |= V_56 ;
break;
case V_57 :
V_45 |= V_58 ;
break;
case V_59 :
V_45 |= V_60 ;
break;
case V_61 :
V_45 |= V_62 ;
break;
default:
return - V_11 ;
}
F_11 ( V_6 , V_54 , V_45 ) ;
switch ( F_13 ( V_40 ) ) {
case 8000 :
V_46 = V_63 ;
V_47 = 3072000 ;
break;
case 11025 :
V_46 = V_64 ;
V_47 = 2822400 ;
break;
case 12000 :
V_46 = V_65 ;
V_47 = 3072000 ;
break;
case 16000 :
V_46 = V_66 ;
V_47 = 3072000 ;
break;
case 22050 :
V_46 = V_67 ;
V_47 = 2822400 ;
break;
case 32000 :
V_46 = V_68 ;
V_47 = 3072000 ;
break;
case 44100 :
V_46 = V_69 ;
V_47 = 2822400 ;
break;
case 48000 :
V_46 = V_70 ;
V_47 = 3072000 ;
break;
case 88200 :
V_46 = V_71 ;
V_47 = 2822400 ;
break;
case 96000 :
V_46 = V_72 ;
V_47 = 3072000 ;
break;
default:
return - V_11 ;
}
F_14 ( V_6 , V_73 , V_74 , 0 ) ;
F_14 ( V_6 , V_75 , V_76 , V_46 ) ;
if ( V_44 -> V_77 && ( V_44 -> V_77 != V_47 ) ) {
F_14 ( V_6 , V_78 , V_79 , 0 ) ;
if ( ! V_44 -> V_80 ) {
F_14 ( V_6 , V_75 ,
( V_81 |
V_82 ) ,
( V_81 |
V_82 ) ) ;
}
} else {
F_14 ( V_6 , V_75 , V_82 ,
V_82 ) ;
F_14 ( V_6 , V_78 , V_79 ,
V_79 ) ;
}
F_14 ( V_6 , V_73 ,
V_74 , V_74 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_83 , T_2 V_84 )
{
struct V_5 * V_6 = V_83 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
T_2 V_45 ;
T_2 V_85 ;
V_45 = 0x7f & F_3 ( V_6 , V_54 ) ;
V_85 = 0xfc & F_3 ( V_6 , V_51 ) ;
if ( ( F_3 ( V_6 , V_75 ) & V_86 ) &&
( ! ( F_3 ( V_6 , V_78 ) & V_79 ) ) )
return - V_11 ;
switch ( V_84 & V_87 ) {
case V_88 :
V_44 -> V_80 = 1 ;
V_45 |= V_89 ;
break;
case V_90 :
V_44 -> V_80 = 0 ;
V_45 |= V_91 ;
break;
default:
return - V_11 ;
}
switch ( V_84 & V_92 ) {
case V_93 :
V_85 |= V_94 ;
break;
case V_95 :
V_85 |= V_96 ;
break;
case V_97 :
V_85 |= V_98 ;
break;
default:
return - V_11 ;
}
V_45 |= V_99 ;
F_11 ( V_6 , V_54 , V_45 ) ;
F_11 ( V_6 , V_51 , V_85 ) ;
return 0 ;
}
static int F_16 ( struct V_41 * V_42 , int V_100 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_101 = F_3 ( V_6 , V_102 ) & 0xFB ;
if ( V_100 )
F_11 ( V_6 , V_102 , V_101 | 0x4 ) ;
else
F_11 ( V_6 , V_102 , V_101 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_83 ,
int V_103 , unsigned int V_104 , int V_105 )
{
struct V_5 * V_6 = V_83 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
switch ( V_103 ) {
case V_106 :
switch ( V_104 ) {
case 12000000 :
case 13000000 :
case 13500000 :
case 14400000 :
case 19200000 :
case 19680000 :
case 19800000 :
V_44 -> V_77 = V_104 ;
return 0 ;
default:
F_18 ( V_83 -> V_10 , L_2 ,
V_104 ) ;
return - V_11 ;
}
break;
default:
F_18 ( V_83 -> V_10 , L_3 , V_103 ) ;
return - V_11 ;
}
}
static int F_19 ( struct V_41 * V_83 , int V_107 ,
int V_108 , unsigned int V_109 , unsigned int V_110 )
{
struct V_5 * V_6 = V_83 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
T_1 V_111 , V_112 , V_113 , V_114 ;
if ( ! V_44 -> V_80 )
V_110 = 2822400 ;
for ( V_114 = 0 ; V_114 < F_20 ( V_115 ) ; V_114 ++ ) {
if ( ( V_109 == V_115 [ V_114 ] . V_109 ) &&
( V_44 -> V_80 == V_115 [ V_114 ] . V_116 ) &&
( V_110 == V_115 [ V_114 ] . V_110 ) ) {
V_111 = V_115 [ V_114 ] . V_117 ;
V_112 = V_115 [ V_114 ] . V_118 ;
V_113 = V_115 [ V_114 ] . V_119 ;
break;
}
}
if ( V_114 >= F_20 ( V_115 ) )
goto V_15;
F_14 ( V_6 , V_73 , V_74 , 0 ) ;
F_11 ( V_6 , V_120 , V_111 ) ;
F_11 ( V_6 , V_121 , V_112 ) ;
F_14 ( V_6 , V_78 ,
V_122 , V_113 ) ;
F_14 ( V_6 , V_75 , V_86 , V_86 ) ;
F_14 ( V_6 , V_73 , V_74 ,
V_74 ) ;
return 0 ;
V_15:
F_18 ( V_83 -> V_10 , L_4 , V_109 ) ;
return - V_11 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_43 * V_44 = F_10 ( V_6 ) ;
int V_123 ;
F_22 ( V_6 -> V_10 , L_5 , V_124 ) ;
V_6 -> V_125 = V_44 -> V_126 ;
V_123 = F_23 ( V_6 , 8 , 8 , V_127 ) ;
if ( V_123 < 0 ) {
F_18 ( V_6 -> V_10 , L_6 , V_123 ) ;
return V_123 ;
}
V_44 -> V_77 = 0 ;
V_44 -> V_80 = 0 ;
F_11 ( V_6 , V_8 , V_128 | V_129 ) ;
F_11 ( V_6 , V_130 , V_131 | V_132 ) ;
F_11 ( V_6 , V_133 , V_134 ) ;
F_11 ( V_6 , V_135 , V_136 ) ;
F_11 ( V_6 , V_137 , V_138 ) ;
F_11 ( V_6 , V_13 , V_139 | V_140 ) ;
F_11 ( V_6 , V_141 ,
V_142 | V_143 |
V_144 | V_145 ) ;
F_11 ( V_6 , V_146 , V_147 ) ;
F_11 ( V_6 , V_148 , V_149 ) ;
F_11 ( V_6 , V_150 ,
V_151 | V_152 |
V_153 | V_154 | V_155 ) ;
F_11 ( V_6 , V_156 , V_157 ) ;
F_11 ( V_6 , V_158 , V_159 ) ;
F_11 ( V_6 , V_160 , V_161 ) ;
F_11 ( V_6 , V_162 , V_163 |
V_164 | V_165 ) ;
F_11 ( V_6 , V_25 , V_166 ) ;
F_11 ( V_6 , V_28 , V_167 ) ;
F_11 ( V_6 , V_168 , V_169 ) ;
F_11 ( V_6 , V_78 , V_170 |
V_79 ) ;
F_11 ( V_6 , V_75 , V_70 ) ;
F_11 ( V_6 , V_73 , V_74 ) ;
F_22 ( V_6 -> V_10 , L_5 , V_124 ) ;
return 0 ;
}
static int F_24 ( struct V_171 * V_172 ,
const struct V_173 * V_174 )
{
struct V_43 * V_44 ;
int V_123 ;
V_44 = F_25 ( & V_172 -> V_10 , sizeof( struct V_43 ) ,
V_175 ) ;
if ( ! V_44 )
return - V_176 ;
F_26 ( V_172 , V_44 ) ;
V_44 -> V_126 = F_27 ( V_172 , & V_177 ) ;
if ( F_28 ( V_44 -> V_126 ) ) {
V_123 = F_29 ( V_44 -> V_126 ) ;
F_18 ( & V_172 -> V_10 , L_7 , V_123 ) ;
return V_123 ;
}
V_123 = F_30 ( V_44 -> V_126 , V_178 ,
F_20 ( V_178 ) ) ;
if ( V_123 != 0 )
F_31 ( & V_172 -> V_10 , L_8 , V_123 ) ;
V_123 = F_32 ( & V_172 -> V_10 ,
& V_179 , & V_180 , 1 ) ;
if ( V_123 < 0 )
F_18 ( & V_172 -> V_10 , L_9 , V_123 ) ;
return V_123 ;
}
static int F_33 ( struct V_171 * V_181 )
{
F_34 ( & V_181 -> V_10 ) ;
return 0 ;
}
static int F_35 ( struct V_182 * V_183 )
{
struct V_43 * V_44 ;
int V_123 ;
V_44 = F_25 ( & V_183 -> V_10 , sizeof( struct V_43 ) ,
V_175 ) ;
if ( ! V_44 )
return - V_176 ;
F_36 ( V_183 , V_44 ) ;
V_44 -> V_126 = F_37 ( V_183 , & V_184 ) ;
if ( F_28 ( V_44 -> V_126 ) ) {
V_123 = F_29 ( V_44 -> V_126 ) ;
F_18 ( & V_183 -> V_10 , L_10 , V_123 ) ;
return V_123 ;
}
V_123 = F_30 ( V_44 -> V_126 , V_185 ,
F_20 ( V_185 ) ) ;
if ( V_123 != 0 )
F_31 ( & V_183 -> V_10 , L_8 , V_123 ) ;
V_123 = F_32 ( & V_183 -> V_10 ,
& V_179 , & V_180 , 1 ) ;
return V_123 ;
}
static int F_38 ( struct V_182 * V_183 )
{
F_34 ( & V_183 -> V_10 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
int V_123 = 0 ;
#if F_40 ( V_186 ) || F_40 ( V_187 )
V_123 = F_41 ( & V_188 ) ;
#endif
#if F_40 ( V_189 )
V_123 = F_42 ( & V_190 ) ;
if ( V_123 ) {
F_43 ( V_191 L_11 ,
V_123 ) ;
}
#endif
return V_123 ;
}
static void T_4 F_44 ( void )
{
#if F_40 ( V_186 ) || F_40 ( V_187 )
F_45 ( & V_188 ) ;
#endif
#if F_40 ( V_189 )
F_46 ( & V_190 ) ;
#endif
}
