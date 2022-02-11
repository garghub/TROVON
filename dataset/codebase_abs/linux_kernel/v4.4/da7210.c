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
case 16 :
V_45 |= V_55 ;
break;
case 20 :
V_45 |= V_56 ;
break;
case 24 :
V_45 |= V_57 ;
break;
case 32 :
V_45 |= V_58 ;
break;
default:
return - V_11 ;
}
F_11 ( V_6 , V_54 , V_45 ) ;
switch ( F_13 ( V_40 ) ) {
case 8000 :
V_46 = V_59 ;
V_47 = 3072000 ;
break;
case 11025 :
V_46 = V_60 ;
V_47 = 2822400 ;
break;
case 12000 :
V_46 = V_61 ;
V_47 = 3072000 ;
break;
case 16000 :
V_46 = V_62 ;
V_47 = 3072000 ;
break;
case 22050 :
V_46 = V_63 ;
V_47 = 2822400 ;
break;
case 32000 :
V_46 = V_64 ;
V_47 = 3072000 ;
break;
case 44100 :
V_46 = V_65 ;
V_47 = 2822400 ;
break;
case 48000 :
V_46 = V_66 ;
V_47 = 3072000 ;
break;
case 88200 :
V_46 = V_67 ;
V_47 = 2822400 ;
break;
case 96000 :
V_46 = V_68 ;
V_47 = 3072000 ;
break;
default:
return - V_11 ;
}
F_14 ( V_6 , V_69 , V_70 , 0 ) ;
F_14 ( V_6 , V_71 , V_72 , V_46 ) ;
if ( V_44 -> V_73 && ( V_44 -> V_73 != V_47 ) ) {
F_14 ( V_6 , V_74 , V_75 , 0 ) ;
if ( ! V_44 -> V_76 ) {
F_14 ( V_6 , V_71 ,
( V_77 |
V_78 ) ,
( V_77 |
V_78 ) ) ;
}
} else {
F_14 ( V_6 , V_71 , V_78 ,
V_78 ) ;
F_14 ( V_6 , V_74 , V_75 ,
V_75 ) ;
}
F_14 ( V_6 , V_69 ,
V_70 , V_70 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_79 , T_2 V_80 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
T_2 V_45 ;
T_2 V_81 ;
V_45 = 0x7f & F_3 ( V_6 , V_54 ) ;
V_81 = 0xfc & F_3 ( V_6 , V_51 ) ;
if ( ( F_3 ( V_6 , V_71 ) & V_82 ) &&
( ! ( F_3 ( V_6 , V_74 ) & V_75 ) ) )
return - V_11 ;
switch ( V_80 & V_83 ) {
case V_84 :
V_44 -> V_76 = 1 ;
V_45 |= V_85 ;
break;
case V_86 :
V_44 -> V_76 = 0 ;
V_45 |= V_87 ;
break;
default:
return - V_11 ;
}
switch ( V_80 & V_88 ) {
case V_89 :
V_81 |= V_90 ;
break;
case V_91 :
V_81 |= V_92 ;
break;
case V_93 :
V_81 |= V_94 ;
break;
default:
return - V_11 ;
}
V_45 |= V_95 ;
F_11 ( V_6 , V_54 , V_45 ) ;
F_11 ( V_6 , V_51 , V_81 ) ;
return 0 ;
}
static int F_16 ( struct V_41 * V_42 , int V_96 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_97 = F_3 ( V_6 , V_98 ) & 0xFB ;
if ( V_96 )
F_11 ( V_6 , V_98 , V_97 | 0x4 ) ;
else
F_11 ( V_6 , V_98 , V_97 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_79 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
switch ( V_99 ) {
case V_102 :
switch ( V_100 ) {
case 12000000 :
case 13000000 :
case 13500000 :
case 14400000 :
case 19200000 :
case 19680000 :
case 19800000 :
V_44 -> V_73 = V_100 ;
return 0 ;
default:
F_18 ( V_79 -> V_10 , L_2 ,
V_100 ) ;
return - V_11 ;
}
break;
default:
F_18 ( V_79 -> V_10 , L_3 , V_99 ) ;
return - V_11 ;
}
}
static int F_19 ( struct V_41 * V_79 , int V_103 ,
int V_104 , unsigned int V_105 , unsigned int V_106 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_43 * V_44 = F_10 ( V_6 ) ;
T_1 V_107 , V_108 , V_109 , V_110 ;
if ( ! V_44 -> V_76 )
V_106 = 2822400 ;
for ( V_110 = 0 ; V_110 < F_20 ( V_111 ) ; V_110 ++ ) {
if ( ( V_105 == V_111 [ V_110 ] . V_105 ) &&
( V_44 -> V_76 == V_111 [ V_110 ] . V_112 ) &&
( V_106 == V_111 [ V_110 ] . V_106 ) ) {
V_107 = V_111 [ V_110 ] . V_113 ;
V_108 = V_111 [ V_110 ] . V_114 ;
V_109 = V_111 [ V_110 ] . V_115 ;
break;
}
}
if ( V_110 >= F_20 ( V_111 ) )
goto V_15;
F_14 ( V_6 , V_69 , V_70 , 0 ) ;
F_11 ( V_6 , V_116 , V_107 ) ;
F_11 ( V_6 , V_117 , V_108 ) ;
F_14 ( V_6 , V_74 ,
V_118 , V_109 ) ;
F_14 ( V_6 , V_71 , V_82 , V_82 ) ;
F_14 ( V_6 , V_69 , V_70 ,
V_70 ) ;
return 0 ;
V_15:
F_18 ( V_79 -> V_10 , L_4 , V_105 ) ;
return - V_11 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_43 * V_44 = F_10 ( V_6 ) ;
F_22 ( V_6 -> V_10 , L_5 , V_119 ) ;
V_44 -> V_73 = 0 ;
V_44 -> V_76 = 0 ;
F_11 ( V_6 , V_8 , V_120 | V_121 ) ;
F_11 ( V_6 , V_122 , V_123 | V_124 ) ;
F_11 ( V_6 , V_125 , V_126 ) ;
F_11 ( V_6 , V_127 , V_128 ) ;
F_11 ( V_6 , V_129 , V_130 ) ;
F_11 ( V_6 , V_13 , V_131 | V_132 ) ;
F_11 ( V_6 , V_133 ,
V_134 | V_135 |
V_136 | V_137 ) ;
F_11 ( V_6 , V_138 , V_139 ) ;
F_11 ( V_6 , V_140 , V_141 ) ;
F_11 ( V_6 , V_142 ,
V_143 | V_144 |
V_145 | V_146 | V_147 ) ;
F_11 ( V_6 , V_148 , V_149 ) ;
F_11 ( V_6 , V_150 , V_151 ) ;
F_11 ( V_6 , V_152 , V_153 ) ;
F_11 ( V_6 , V_154 , V_155 |
V_156 | V_157 ) ;
F_11 ( V_6 , V_25 , V_158 ) ;
F_11 ( V_6 , V_28 , V_159 ) ;
F_11 ( V_6 , V_160 , V_161 ) ;
F_11 ( V_6 , V_74 , V_162 |
V_75 ) ;
F_11 ( V_6 , V_71 , V_66 ) ;
F_11 ( V_6 , V_69 , V_70 ) ;
F_22 ( V_6 -> V_10 , L_5 , V_119 ) ;
return 0 ;
}
static int F_23 ( struct V_163 * V_164 ,
const struct V_165 * V_166 )
{
struct V_43 * V_44 ;
int V_167 ;
V_44 = F_24 ( & V_164 -> V_10 , sizeof( struct V_43 ) ,
V_168 ) ;
if ( ! V_44 )
return - V_169 ;
F_25 ( V_164 , V_44 ) ;
V_44 -> V_170 = F_26 ( V_164 , & V_171 ) ;
if ( F_27 ( V_44 -> V_170 ) ) {
V_167 = F_28 ( V_44 -> V_170 ) ;
F_18 ( & V_164 -> V_10 , L_6 , V_167 ) ;
return V_167 ;
}
V_167 = F_29 ( V_44 -> V_170 , V_172 ,
F_20 ( V_172 ) ) ;
if ( V_167 != 0 )
F_30 ( & V_164 -> V_10 , L_7 , V_167 ) ;
V_167 = F_31 ( & V_164 -> V_10 ,
& V_173 , & V_174 , 1 ) ;
if ( V_167 < 0 )
F_18 ( & V_164 -> V_10 , L_8 , V_167 ) ;
return V_167 ;
}
static int F_32 ( struct V_163 * V_175 )
{
F_33 ( & V_175 -> V_10 ) ;
return 0 ;
}
static int F_34 ( struct V_176 * V_177 )
{
struct V_43 * V_44 ;
int V_167 ;
V_44 = F_24 ( & V_177 -> V_10 , sizeof( struct V_43 ) ,
V_168 ) ;
if ( ! V_44 )
return - V_169 ;
F_35 ( V_177 , V_44 ) ;
V_44 -> V_170 = F_36 ( V_177 , & V_178 ) ;
if ( F_27 ( V_44 -> V_170 ) ) {
V_167 = F_28 ( V_44 -> V_170 ) ;
F_18 ( & V_177 -> V_10 , L_9 , V_167 ) ;
return V_167 ;
}
V_167 = F_29 ( V_44 -> V_170 , V_179 ,
F_20 ( V_179 ) ) ;
if ( V_167 != 0 )
F_30 ( & V_177 -> V_10 , L_7 , V_167 ) ;
V_167 = F_31 ( & V_177 -> V_10 ,
& V_173 , & V_174 , 1 ) ;
return V_167 ;
}
static int F_37 ( struct V_176 * V_177 )
{
F_33 ( & V_177 -> V_10 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
int V_167 = 0 ;
#if F_39 ( V_180 )
V_167 = F_40 ( & V_181 ) ;
#endif
#if F_41 ( V_182 )
V_167 = F_42 ( & V_183 ) ;
if ( V_167 ) {
F_43 ( V_184 L_10 ,
V_167 ) ;
}
#endif
return V_167 ;
}
static void T_4 F_44 ( void )
{
#if F_39 ( V_180 )
F_45 ( & V_181 ) ;
#endif
#if F_41 ( V_182 )
F_46 ( & V_183 ) ;
#endif
}
