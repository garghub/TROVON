int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_1 ;
if ( V_7 -> V_8 == V_9 ) {
if ( V_3 == V_10 ) {
F_2 ( V_7 -> V_7 ,
L_1 ,
V_3 , V_7 -> V_8 ) ;
F_3 ( V_7 , V_7 -> V_11 . V_12 -> V_13 ,
1 ) ;
F_4 ( 10 ) ;
F_3 ( V_7 , V_7 -> V_11 . V_12 -> V_13 ,
0 ) ;
F_4 ( 330 ) ;
F_3 ( V_7 , V_7 -> V_11 . V_12 -> V_13 ,
1 ) ;
F_4 ( 10 ) ;
}
} else if ( V_7 -> V_8 == V_14 ) {
switch ( V_3 ) {
case V_15 :
if ( V_7 -> V_16 == V_17 )
V_5 = F_5 ( V_7 , V_4 ) ;
break;
default:
V_5 = - V_18 ;
break;
}
}
return V_5 ;
}
static void F_6 ( struct V_6 * V_7 )
{
F_3 ( V_7 , V_19 , 1 ) ;
F_4 ( 200 ) ;
F_3 ( V_7 , V_19 , 0 ) ;
F_4 ( 200 ) ;
F_3 ( V_7 , V_19 , 1 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_3 ( V_7 , V_20 , 1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_3 ( V_7 , V_21 , 0 ) ;
}
static inline void F_9 ( struct V_6 * V_7 )
{
V_7 -> V_11 = V_22 [ V_7 -> V_16 ] ;
}
void F_10 ( struct V_6 * V_7 )
{
F_9 ( V_7 ) ;
F_11 ( V_7 -> V_7 , L_2 ,
V_7 -> V_11 . V_23 , V_7 -> V_16 ) ;
if ( V_7 -> V_11 . V_12 ) {
F_12 ( V_7 , V_7 -> V_11 . V_12 -> V_13 , 1 ) ;
F_3 ( V_7 , V_7 -> V_11 . V_12 -> V_13 , 1 ) ;
}
if ( V_7 -> V_11 . V_24 >= 0 )
F_12 ( V_7 , V_7 -> V_11 . V_24 , 1 ) ;
F_13 ( V_7 , V_25 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_26 V_27 ;
struct V_28 V_29 ;
if ( V_7 -> V_8 == V_30 )
return;
V_27 . V_31 = V_32 | V_33 ;
V_27 . type = V_7 -> V_8 ;
V_27 . V_34 = V_7 -> V_35 ;
V_27 . V_36 = F_1 ;
F_15 ( V_7 , V_37 , V_38 , & V_27 ) ;
#if 0
if (tun_setup.type == TUNER_XC5000) {
static struct xc2028_ctrl ctrl = {
.fname = XC5000_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = 0;
};
struct v4l2_priv_tun_config cfg = {
.tuner = dev->tuner_type,
.priv = &ctrl,
};
tuner_call(dev, tuner, s_config, &cfg);
}
#endif
V_29 . V_37 = 0 ;
V_29 . type = V_39 ;
V_29 . V_40 = 9076 ;
V_7 -> V_41 = V_29 . V_40 ;
F_16 ( V_7 , V_37 , V_42 , & V_29 ) ;
}
static int F_17 ( struct V_6 * V_7 , struct V_43 * V_44 ,
T_1 * V_45 , int V_46 )
{
int V_47 = 0 ;
T_1 V_48 = 0 ;
int V_49 = V_46 ;
T_1 * V_50 = V_45 ;
int V_51 ;
struct V_52 V_53 = { . V_34 = V_44 -> V_34 , . V_54 = 0 ,
. V_55 = & V_48 , . V_46 = 1 } ;
struct V_52 V_56 = { . V_34 = V_44 -> V_34 , . V_54 = V_57 } ;
V_47 = F_18 ( V_44 -> V_58 , & V_53 , 1 ) ;
if ( V_47 < 0 ) {
F_19 ( V_7 -> V_7 , L_3 ) ;
return V_47 ;
}
while ( V_49 > 0 ) {
V_56 . V_46 = ( V_49 > 64 ) ? 64 : V_49 ;
V_56 . V_55 = V_50 ;
V_47 = F_18 ( V_44 -> V_58 , & V_56 , 1 ) ;
if ( V_47 < 0 ) {
F_19 ( V_7 -> V_7 , L_3 ) ;
return V_47 ;
}
V_50 += V_56 . V_46 ;
V_49 -= V_56 . V_46 ;
}
for ( V_51 = 0 ; V_51 + 15 < V_46 ; V_51 += 16 )
F_2 ( V_7 -> V_7 , L_4 ,
V_51 , 16 , & V_45 [ V_51 ] ) ;
return 0 ;
}
void F_20 ( struct V_6 * V_7 )
{
F_9 ( V_7 ) ;
V_7 -> V_8 = V_22 [ V_7 -> V_16 ] . V_8 ;
if ( V_22 [ V_7 -> V_16 ] . V_35 )
V_7 -> V_35 = V_22 [ V_7 -> V_16 ] . V_35 ;
if ( V_7 -> V_11 . V_59 == V_60 ) {
V_7 -> V_61 = F_21 ( & V_7 -> V_62 ,
F_22 ( V_7 , V_63 ) ,
L_5 , 0x88 >> 1 , NULL ) ;
if ( V_7 -> V_61 == NULL )
F_19 ( V_7 -> V_7 ,
L_6 ) ;
F_23 ( V_7 , V_64 , V_65 ) ;
}
if ( V_7 -> V_11 . V_8 != V_30 ) {
struct V_66 * V_67 = F_22 ( V_7 ,
V_7 -> V_11 . V_68 ) ;
V_7 -> V_69 = F_21 ( & V_7 -> V_62 ,
V_67 ,
L_7 ,
V_7 -> V_35 , NULL ) ;
if ( V_7 -> V_69 == NULL )
F_19 ( V_7 -> V_7 ,
L_8 ) ;
else
F_14 ( V_7 ) ;
}
switch ( V_7 -> V_16 ) {
case V_70 :
case V_71 :
{
struct V_72 V_73 ;
static T_1 V_74 [ 256 ] ;
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_58 = F_22 ( V_7 , V_75 ) ;
V_44 . V_34 = 0xa0 >> 1 ;
F_17 ( V_7 , & V_44 , V_74 , sizeof( V_74 ) ) ;
F_24 ( & V_44 ,
& V_73 , V_74 + 0xc0 ) ;
break;
}
}
}
int F_25 ( struct V_6 * V_7 )
{
return 0 ;
}
void F_26 ( struct V_6 * V_7 )
{
F_16 ( V_7 , V_76 , V_77 , 1 ) ;
}
void F_27 ( struct V_6 * V_7 )
{
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
F_30 ( V_7 ) ;
F_31 ( V_7 ) ;
F_32 ( & V_7 -> V_62 ) ;
F_33 ( V_7 -> V_78 ) ;
F_34 ( V_7 -> V_79 , & V_80 ) ;
}
static int F_35 ( struct V_6 * V_7 , struct V_81 * V_78 ,
int V_82 )
{
int V_83 = - V_84 ;
unsigned int V_85 , V_86 ;
V_7 -> V_78 = V_78 ;
F_36 ( & V_7 -> V_87 ) ;
F_36 ( & V_7 -> V_88 ) ;
F_36 ( & V_7 -> V_89 ) ;
F_36 ( & V_7 -> V_90 ) ;
F_37 ( & V_7 -> V_91 . V_92 ) ;
F_37 ( & V_7 -> V_93 . V_92 ) ;
F_37 ( & V_7 -> V_94 . V_92 ) ;
F_38 ( & V_7 -> V_95 ) ;
F_38 ( & V_7 -> V_96 ) ;
F_38 ( & V_7 -> V_97 ) ;
V_7 -> V_98 = V_98 ;
V_7 -> V_99 = V_99 ;
V_7 -> V_100 = V_100 ;
V_7 -> V_101 = V_101 ;
V_7 -> V_102 = V_102 ;
V_83 = F_39 ( V_7 ) ;
if ( V_83 < 0 ) {
F_19 ( V_7 -> V_7 , L_9 ) ;
return V_83 ;
}
if ( V_7 -> V_16 == V_103 ||
V_7 -> V_16 == V_104 ) {
F_40 ( V_7 , V_105 , 3 ) ;
F_40 ( V_7 , V_106 , 1 ) ;
}
F_10 ( V_7 ) ;
V_83 = F_25 ( V_7 ) ;
if ( V_83 ) {
F_19 ( V_7 -> V_7 , L_10 ) ;
return - V_84 ;
}
V_7 -> V_107 = V_7 -> V_11 . V_107 ;
V_83 = F_41 ( V_7 ) ;
if ( V_83 ) {
F_19 ( V_7 -> V_7 ,
L_11 ,
V_108 , V_83 ) ;
goto V_109;
}
F_20 ( V_7 ) ;
F_26 ( V_7 ) ;
V_86 = F_42 ( V_7 ) ;
V_85 = F_43 ( V_7 ) ;
V_7 -> V_110 = V_86 ;
V_7 -> V_111 = V_85 ;
V_7 -> V_112 = 0 ;
V_7 -> V_113 = 0 ;
V_83 = F_25 ( V_7 ) ;
if ( V_83 ) {
F_19 ( V_7 -> V_7 , L_12 ,
V_108 , V_83 ) ;
goto V_109;
}
F_44 ( & V_7 -> V_91 . V_114 . V_115 ) ;
F_44 ( & V_7 -> V_91 . V_114 . V_116 ) ;
F_44 ( & V_7 -> V_93 . V_114 . V_115 ) ;
F_44 ( & V_7 -> V_93 . V_114 . V_116 ) ;
F_45 ( V_7 ) ;
if ( V_7 -> V_11 . V_117 ) {
F_11 ( V_7 -> V_7 , L_13 , V_7 -> V_16 ) ;
if ( F_46 ( V_7 ) < 0 ) {
F_19 ( V_7 -> V_7 ,
L_14 ,
V_108 ) ;
}
}
V_83 = F_47 ( V_7 ) ;
if ( V_83 ) {
F_28 ( V_7 ) ;
goto V_118;
}
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
return 0 ;
V_118:
F_29 ( V_7 ) ;
V_109:
F_31 ( V_7 ) ;
return V_83 ;
}
static void F_50 ( struct V_119 * V_120 )
{
struct V_6 * V_7 = F_51 ( V_120 ,
struct V_6 , V_121 ) ;
if ( V_7 -> V_122 )
F_52 ( L_15 ) ;
if ( V_7 -> V_11 . V_123 )
F_52 ( L_16 ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_121 , F_50 ) ;
F_55 ( & V_7 -> V_121 ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
F_57 ( & V_7 -> V_121 ) ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_81 * V_78 ,
struct V_124 * V_125 ,
int V_126 )
{
struct V_124 * V_127 ;
int V_51 , V_128 ;
V_128 = V_7 -> V_129 . V_130 [ 0 ] . V_131 . V_132 + 1 ;
if ( V_128 >= V_7 -> V_133 ) {
F_19 ( V_7 -> V_7 ,
L_17 , V_128 ) ;
return - V_134 ;
}
V_127 = V_78 -> V_135 -> V_125 [ V_128 ] ;
V_7 -> V_91 . V_136 = V_127 -> V_137 [ 0 ] . V_138 [ V_126 ] . V_139 . V_140 ;
V_7 -> V_91 . V_141 = V_127 -> V_142 ;
F_11 ( V_7 -> V_7 ,
L_18 ,
V_7 -> V_91 . V_136 ,
V_7 -> V_91 . V_141 ) ;
V_7 -> V_91 . V_143 = F_59 ( & V_78 -> V_7 , 32 , V_7 -> V_91 . V_141 , V_144 ) ;
if ( V_7 -> V_91 . V_143 == NULL )
return - V_84 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_91 . V_141 ; V_51 ++ ) {
T_2 V_145 = F_60 ( V_127 -> V_137 [ V_51 ] . V_138 [ V_126 ] . V_139 . V_146 ) ;
V_7 -> V_91 . V_143 [ V_51 ] = ( V_145 & 0x07ff ) * ( ( ( V_145 & 0x1800 ) >> 11 ) + 1 ) ;
F_2 ( V_7 -> V_7 ,
L_19 , V_51 ,
V_7 -> V_91 . V_143 [ V_51 ] ) ;
}
V_128 = V_7 -> V_129 . V_130 [ 0 ] . V_131 . V_147 + 1 ;
if ( V_128 >= V_7 -> V_133 ) {
F_19 ( V_7 -> V_7 ,
L_20 , V_128 ) ;
return - V_134 ;
}
V_127 = V_78 -> V_135 -> V_125 [ V_128 ] ;
V_7 -> V_93 . V_136 =
V_127 -> V_137 [ 0 ] . V_138 [ V_126 ] . V_139 .
V_140 ;
V_7 -> V_93 . V_141 = V_127 -> V_142 ;
F_11 ( V_7 -> V_7 ,
L_21 ,
V_7 -> V_93 . V_136 ,
V_7 -> V_93 . V_141 ) ;
V_7 -> V_93 . V_143 = F_59 ( & V_78 -> V_7 , 32 , V_7 -> V_93 . V_141 , V_144 ) ;
if ( V_7 -> V_93 . V_143 == NULL )
return - V_84 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_93 . V_141 ; V_51 ++ ) {
T_2 V_145 =
F_60 ( V_127 -> V_137 [ V_51 ] . V_138 [ V_126 ] .
V_139 . V_146 ) ;
V_7 -> V_93 . V_143 [ V_51 ] =
( V_145 & 0x07ff ) * ( ( ( V_145 & 0x1800 ) >> 11 ) + 1 ) ;
F_2 ( V_7 -> V_7 ,
L_19 , V_51 ,
V_7 -> V_93 . V_143 [ V_51 ] ) ;
}
V_128 = V_7 -> V_129 . V_130 [ 0 ] . V_131 . V_148 + 1 ;
if ( V_128 >= V_7 -> V_133 ) {
F_19 ( V_7 -> V_7 ,
L_22 , V_128 ) ;
return - V_134 ;
}
V_127 = V_78 -> V_135 -> V_125 [ V_128 ] ;
V_7 -> V_94 . V_136 =
V_127 -> V_137 [ 0 ] . V_138 [ V_126 ] . V_139 .
V_140 ;
V_7 -> V_94 . V_141 = V_127 -> V_142 ;
F_11 ( V_7 -> V_7 ,
L_23 ,
V_7 -> V_94 . V_136 ,
V_7 -> V_94 . V_141 ) ;
V_7 -> V_94 . V_143 = F_59 ( & V_78 -> V_7 , 32 , V_7 -> V_94 . V_141 , V_144 ) ;
if ( V_7 -> V_94 . V_143 == NULL )
return - V_84 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_94 . V_141 ; V_51 ++ ) {
T_2 V_145 = F_60 ( V_127 -> V_137 [ V_51 ] . V_138 [ V_126 ] .
V_139 . V_146 ) ;
V_7 -> V_94 . V_143 [ V_51 ] =
( V_145 & 0x07ff ) * ( ( ( V_145 & 0x1800 ) >> 11 ) + 1 ) ;
F_2 ( V_7 -> V_7 ,
L_19 , V_51 ,
V_7 -> V_94 . V_143 [ V_51 ] ) ;
}
return 0 ;
}
static int F_61 ( struct V_124 * V_125 ,
const struct V_149 * V_150 )
{
struct V_81 * V_78 ;
struct V_151 * V_152 = & V_125 -> V_7 ;
struct V_124 * V_127 ;
struct V_6 * V_7 = NULL ;
int V_83 = - V_134 ;
int V_153 = 0 , V_154 ;
int V_51 , V_126 = 0 ;
char * V_155 ;
T_1 V_128 ;
struct V_156 * V_157 ;
V_154 = V_125 -> V_137 [ 0 ] . V_139 . V_158 ;
V_78 = F_62 ( F_63 ( V_125 ) ) ;
if ( V_154 != 1 )
return - V_134 ;
do {
V_153 = F_64 ( & V_80 , V_159 ) ;
if ( V_153 >= V_159 ) {
F_19 ( V_152 ,
L_24 ,
V_159 ) ;
return - V_84 ;
}
} while ( F_65 ( V_153 , & V_80 ) );
V_7 = F_66 ( & V_78 -> V_7 , sizeof( * V_7 ) , V_144 ) ;
if ( V_7 == NULL ) {
F_34 ( V_153 , & V_80 ) ;
return - V_84 ;
}
snprintf ( V_7 -> V_23 , 29 , L_25 , V_153 ) ;
V_7 -> V_79 = V_153 ;
V_7 -> V_16 = V_150 -> V_160 ;
V_7 -> V_91 . V_161 = - 1 ;
V_7 -> V_7 = V_152 ;
V_7 -> V_162 ++ ;
V_7 -> V_163 = 0 ;
V_7 -> V_164 = 0 ;
V_7 -> V_165 = 0 ;
V_7 -> V_122 = 1 ;
V_7 -> V_166 = - 1 ;
F_67 ( & V_7 -> V_167 , 0 ) ;
V_7 -> V_168 = 0 ;
V_7 -> V_133 = V_78 -> V_169 -> V_139 . V_170 ;
V_7 -> V_171 = 0 ;
V_7 -> V_172 = V_173 ;
switch ( V_78 -> V_155 ) {
case V_174 :
V_155 = L_26 ;
break;
case V_175 :
case V_176 :
V_155 = L_27 ;
break;
case V_177 :
V_155 = L_28 ;
break;
default:
V_155 = L_29 ;
}
F_11 ( V_152 ,
L_30 ,
V_78 -> V_178 ? V_78 -> V_178 : L_31 ,
V_78 -> V_179 ? V_78 -> V_179 : L_31 ,
V_155 ,
F_60 ( V_78 -> V_180 . V_181 ) ,
F_60 ( V_78 -> V_180 . V_182 ) ,
V_7 -> V_133 ) ;
V_7 -> V_162 ++ ;
V_153 = V_7 -> V_79 ;
V_157 = V_78 -> V_135 -> V_183 [ 0 ] ;
if ( V_157 -> V_184 != V_154 ) {
F_19 ( V_152 , L_32 ) ;
V_83 = - V_134 ;
goto V_185;
}
F_2 ( V_152 , L_33 , V_154 ) ;
F_68 ( V_125 , V_7 ) ;
V_83 = F_69 ( & V_125 -> V_7 , & V_7 -> V_62 ) ;
if ( V_83 ) {
F_19 ( V_152 , L_34 ) ;
goto V_186;
}
V_83 = F_35 ( V_7 , V_78 , V_153 ) ;
if ( V_83 )
goto V_187;
V_83 = F_58 ( V_7 , V_78 , V_125 , V_126 ) ;
if ( V_83 )
goto V_187;
if ( V_7 -> V_129 . V_188 != 0xff ) {
V_128 = V_7 -> V_129 . V_130 [ 0 ] . V_131 . V_189 + 1 ;
if ( V_128 >= V_7 -> V_133 ) {
F_19 ( V_152 , L_35 ,
V_128 ) ;
V_83 = - V_134 ;
goto V_190;
}
V_127 = V_78 -> V_135 -> V_125 [ V_128 ] ;
V_7 -> V_191 . V_136 =
V_127 -> V_137 [ 0 ] . V_138 [ V_126 ] .
V_139 . V_140 ;
V_7 -> V_191 . V_141 = V_127 -> V_142 ;
F_11 ( V_152 ,
L_36 ,
V_7 -> V_191 . V_136 ,
V_7 -> V_191 . V_141 ) ;
V_7 -> V_191 . V_143 = F_59 ( & V_78 -> V_7 , 32 , V_7 -> V_191 . V_141 , V_144 ) ;
if ( V_7 -> V_191 . V_143 == NULL ) {
V_83 = - V_84 ;
goto V_190;
}
for ( V_51 = 0 ; V_51 < V_7 -> V_191 . V_141 ; V_51 ++ ) {
T_2 V_145 = F_60 ( V_127 -> V_137 [ V_51 ] .
V_138 [ V_126 ] . V_139 .
V_146 ) ;
V_7 -> V_191 . V_143 [ V_51 ] =
( V_145 & 0x07ff ) * ( ( ( V_145 & 0x1800 ) >> 11 ) + 1 ) ;
F_2 ( V_152 , L_19 ,
V_51 , V_7 -> V_191 . V_143 [ V_51 ] ) ;
}
}
if ( V_7 -> V_16 == V_103 ) {
F_7 ( V_7 ) ;
F_6 ( V_7 ) ;
F_40 ( V_7 , V_105 , 3 ) ;
}
if ( V_7 -> V_16 == V_192 )
F_8 ( V_7 ) ;
F_53 ( V_7 ) ;
return 0 ;
V_190:
F_70 ( V_7 ) ;
F_30 ( V_7 ) ;
F_28 ( V_7 ) ;
F_71 ( V_7 ) ;
F_29 ( V_7 ) ;
F_31 ( V_7 ) ;
V_187:
F_32 ( & V_7 -> V_62 ) ;
V_186:
F_68 ( V_125 , NULL ) ;
V_185:
F_33 ( V_78 ) ;
F_34 ( V_7 -> V_79 , & V_80 ) ;
return V_83 ;
}
static void F_72 ( struct V_124 * V_125 )
{
struct V_6 * V_7 ;
V_7 = F_73 ( V_125 ) ;
F_68 ( V_125 , NULL ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_78 )
return;
V_7 -> V_193 |= V_194 ;
F_56 ( V_7 ) ;
F_74 ( & V_7 -> V_87 ) ;
F_75 ( & V_7 -> V_95 ) ;
if ( V_7 -> V_195 ) {
F_76 ( V_7 -> V_7 ,
L_37 ,
F_77 ( V_7 -> V_196 ) ) ;
F_30 ( V_7 ) ;
if ( V_7 -> V_172 )
F_78 ( V_7 ) ;
else
F_79 ( V_7 ) ;
F_80 ( & V_7 -> V_96 ) ;
F_80 ( & V_7 -> V_97 ) ;
} else {
}
F_70 ( V_7 ) ;
F_81 ( & V_7 -> V_87 ) ;
if ( ! V_7 -> V_195 )
F_27 ( V_7 ) ;
}
