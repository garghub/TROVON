static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_10 = & V_2 -> V_7 . V_11 ;
struct V_12 * V_13 ;
V_13 = & V_4 -> V_14 [ V_4 -> V_15 ++ ] ;
V_13 -> V_2 = V_2 ;
V_13 -> time = V_16 ;
V_13 -> V_17 = V_2 -> V_18 . V_19 ;
V_13 -> type = V_20 ;
switch ( V_13 -> V_17 ) {
case V_21 :
V_13 -> V_22 = V_6 -> V_7 . V_23 [ 0 ] ;
V_13 -> V_24 = V_6 -> V_25 ;
V_13 -> V_26 = F_2 ( & V_6 -> V_7 . V_26 ) ;
V_13 -> V_27 = V_6 -> V_7 . V_27 ;
V_13 -> V_28 . V_29 . V_30 = V_6 -> V_7 . V_30 ;
break;
case V_31 :
V_13 -> V_22 = V_10 -> V_32 ;
break;
default:
break;
} ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_33 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_33 -> V_11 ;
struct V_12 * V_13 = & V_4 -> V_14 [ V_4 -> V_15 ++ ] ;
V_13 -> V_2 = V_2 ;
V_13 -> time = V_16 ;
V_13 -> V_17 = V_2 -> V_18 . V_19 ;
V_13 -> type = V_34 ;
switch ( V_13 -> V_17 ) {
case V_21 :
V_13 -> V_22 = V_6 -> V_7 . V_23 [ 0 ] ;
V_13 -> V_24 = V_6 -> V_25 ;
V_13 -> V_26 = F_2 ( & V_6 -> V_7 . V_26 ) ;
V_13 -> V_27 = V_6 -> V_7 . V_27 ;
V_13 -> V_28 . V_35 . V_36 = V_6 -> V_36 ;
V_13 -> V_28 . V_35 . error = V_6 -> error ;
V_13 -> V_28 . V_35 . V_37 = V_6 -> V_38 . V_39 ;
V_13 -> V_28 . V_35 . V_40 = V_6 -> V_38 . V_41 . V_42 . V_40 ;
V_13 -> V_28 . V_35 . V_43 = V_6 -> V_38 . V_43 ;
break;
case V_31 :
V_13 -> V_22 = V_10 -> V_32 ;
V_13 -> V_28 . V_35 . V_36 = V_10 -> V_36 ;
break;
default:
break;
} ;
}
static int F_4 ( T_1 V_36 , T_1 error )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_45 ) ; V_44 ++ )
if ( ( V_45 [ V_44 ] . V_36 & V_36 ) == V_45 [ V_44 ] . V_36 &&
V_45 [ V_44 ] . error == error )
return V_44 ;
return - V_46 ;
}
static const char * F_6 ( T_1 V_36 , T_1 error )
{
int V_47 = F_4 ( V_36 , error ) ;
if ( V_47 >= 0 )
return V_45 [ V_47 ] . V_48 ;
return V_49 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_50 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
int V_52 = V_38 -> V_53 ;
if ( ( V_38 -> V_39 & V_54 ) &&
( ( V_52 && V_52 != 4 && V_52 != 8 ) ||
V_38 -> V_41 . V_42 . V_40 ) )
return V_55 << 16 ;
V_50 = F_4 ( V_6 -> V_36 , V_6 -> error ) ;
if ( V_50 >= 0 )
return V_38 -> V_43 | ( V_45 [ V_50 ] . V_56 << 16 ) ;
return V_38 -> V_43 | ( V_55 << 16 ) ;
}
static int F_8 ( T_1 V_36 , T_1 error )
{
int V_47 = F_4 ( V_36 , error ) ;
if ( V_47 >= 0 )
return V_45 [ V_47 ] . V_57 ;
return 1 ;
}
static const char * F_9 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_58 ) ; V_44 ++ )
if ( V_58 [ V_44 ] . V_59 == V_36 )
return V_58 [ V_44 ] . V_48 ;
return V_60 ;
}
static const char * F_10 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_61 ) ; V_44 ++ )
if ( V_61 [ V_44 ] . V_59 == V_36 )
return V_61 [ V_44 ] . V_48 ;
return V_60 ;
}
static const char * F_11 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_62 ) ; V_44 ++ )
if ( V_62 [ V_44 ] . V_62 == V_36 )
return V_62 [ V_44 ] . V_48 ;
return V_63 ;
}
static void F_12 ( struct V_64 * V_65 ,
enum V_66 V_67 )
{
switch ( V_65 -> V_67 ) {
case V_68 :
if ( V_67 == V_69 )
V_65 -> V_67 = V_67 ;
case V_69 :
break;
default:
if ( V_67 == V_68 )
V_65 -> V_70 = 0 ;
V_65 -> V_67 = V_67 ;
break;
}
}
static int F_13 ( struct V_3 * V_4 ,
enum V_71 V_72 )
{
int V_47 = 0 ;
switch ( V_4 -> V_72 ) {
case V_73 :
V_47 = - V_46 ;
break;
default:
V_4 -> V_72 = V_72 ;
break;
} ;
return V_47 ;
}
static void F_14 ( struct V_3 * V_4 ,
enum V_74 V_67 )
{
switch ( V_67 ) {
case V_75 :
if ( V_4 -> V_67 == V_76 )
V_4 -> V_67 = V_67 ;
break;
case V_77 :
if ( V_4 -> V_67 == V_78 )
V_4 -> V_67 = V_67 ;
break;
case V_76 :
if ( V_4 -> V_67 == V_79 )
V_4 -> V_67 = V_67 ;
break;
case V_80 :
switch ( V_4 -> V_67 ) {
case V_76 :
case V_81 :
case V_82 :
V_4 -> V_67 = V_67 ;
break;
default:
break;
} ;
break;
case V_83 :
if ( V_4 -> V_67 == V_75 )
V_4 -> V_67 = V_67 ;
break;
case V_79 :
case V_84 :
switch ( V_4 -> V_67 ) {
case V_85 :
case V_86 :
break;
default:
V_4 -> V_67 = V_67 ;
break;
} ;
break;
case V_78 :
case V_87 :
case V_82 :
case V_81 :
case V_85 :
case V_86 :
default:
V_4 -> V_67 = V_67 ;
break;
} ;
}
static void F_15 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 == V_81 ) {
if ( ! F_13 ( V_4 , V_88 ) ) {
F_16 ( V_4 -> V_89 ) ;
F_14 ( V_4 , V_80 ) ;
}
} else
V_4 -> V_90 = 1 ;
F_17 ( & V_4 -> V_91 ) ;
}
static void F_18 ( struct V_3 * V_4 ,
enum V_71 V_72 )
{
struct V_64 * V_65 ;
V_92 ;
F_16 ( V_4 -> V_89 ) ;
F_19 (tgt, &vhost->targets, queue)
F_12 ( V_65 , V_68 ) ;
F_13 ( V_4 , V_72 ) ;
F_14 ( V_4 , V_84 ) ;
V_4 -> V_93 |= V_94 ;
F_17 ( & V_4 -> V_91 ) ;
V_95 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
if ( V_4 -> V_67 == V_76 ) {
if ( ++ V_4 -> V_96 > V_97 ) {
F_21 ( V_4 -> V_98 ,
L_1 ) ;
F_18 ( V_4 , V_73 ) ;
return;
}
}
if ( ! F_13 ( V_4 , V_88 ) ) {
memset ( V_4 -> V_99 . V_100 , 0 , V_101 ) ;
V_4 -> V_99 . V_102 = 0 ;
F_19 (tgt, &vhost->targets, queue)
F_12 ( V_65 , V_68 ) ;
F_16 ( V_4 -> V_89 ) ;
F_14 ( V_4 , V_79 ) ;
V_4 -> V_103 = V_104 ;
F_17 ( & V_4 -> V_91 ) ;
}
}
static int F_22 ( struct V_3 * V_4 , T_2 V_105 , T_2 V_106 )
{
struct V_107 * V_108 = F_23 ( V_4 -> V_98 ) ;
return F_24 ( V_109 , V_108 -> V_110 , V_105 , V_106 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
F_26 ( V_4 , L_2 ) ;
return F_22 ( V_4 , 0xC001000000000000LL , 0 ) ;
}
static int F_27 ( struct V_3 * V_4 )
{
F_26 ( V_4 , L_3 ) ;
return F_22 ( V_4 , 0xC002000000000000LL , 0 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
long V_47 = 0 ;
struct V_107 * V_108 = F_23 ( V_4 -> V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
F_26 ( V_4 , L_4 ) ;
F_29 ( V_108 -> V_112 , V_4 ) ;
F_30 ( & V_4 -> V_113 ) ;
do {
if ( V_47 )
F_31 ( 100 ) ;
V_47 = F_24 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_32 ( V_47 ) );
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
F_33 ( V_4 -> V_98 , V_18 -> V_118 , V_101 , V_119 ) ;
F_34 ( ( unsigned long ) V_18 -> V_100 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
int V_47 = 0 ;
struct V_107 * V_108 = F_23 ( V_4 -> V_98 ) ;
do {
if ( V_47 )
F_31 ( 100 ) ;
V_47 = F_24 ( V_120 , V_108 -> V_110 ) ;
} while ( V_47 == V_121 || V_47 == V_115 || F_32 ( V_47 ) );
if ( V_47 )
F_21 ( V_4 -> V_98 , L_5 , V_47 ) ;
return V_47 ;
}
static int F_36 ( struct V_3 * V_4 )
{
int V_47 = 0 ;
unsigned long V_39 ;
struct V_107 * V_108 = F_23 ( V_4 -> V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
do {
if ( V_47 )
F_31 ( 100 ) ;
V_47 = F_24 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_32 ( V_47 ) );
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
F_14 ( V_4 , V_81 ) ;
memset ( V_18 -> V_100 , 0 , V_101 ) ;
V_18 -> V_102 = 0 ;
V_47 = F_24 ( V_123 , V_108 -> V_110 ,
V_18 -> V_118 , V_101 ) ;
if ( V_47 == V_124 )
F_38 ( V_4 -> V_98 , L_6 ) ;
else if ( V_47 != 0 )
F_38 ( V_4 -> V_98 , L_7 , V_47 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_47 ;
}
static int F_40 ( struct V_125 * V_126 ,
struct V_1 * V_2 )
{
int V_127 = V_2 - V_126 -> V_128 ;
if ( V_127 < 0 || V_127 >= V_126 -> V_129 )
return 0 ;
if ( V_2 != V_126 -> V_128 + V_127 )
return 0 ;
return 1 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
F_42 ( ! F_40 ( V_126 , V_2 ) ) ;
F_42 ( F_43 ( & V_2 -> free ) != 1 ) ;
F_44 ( & V_2 -> V_130 , & V_4 -> free ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = V_2 -> V_132 ;
if ( V_132 ) {
F_46 ( V_132 ) ;
V_132 -> V_133 ( V_132 ) ;
}
if ( V_2 -> V_134 )
F_47 ( V_2 -> V_134 ) ;
F_41 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_135 )
{
if ( V_2 -> V_132 ) {
V_2 -> V_132 -> V_56 = ( V_135 << 16 ) ;
V_2 -> V_136 = F_45 ;
} else
V_2 -> V_33 -> V_11 . V_36 = V_137 ;
F_49 ( & V_2 -> V_130 ) ;
F_50 ( & V_2 -> V_138 ) ;
F_3 ( V_2 ) ;
V_2 -> V_136 ( V_2 ) ;
}
static void F_51 ( struct V_3 * V_4 , int V_135 )
{
struct V_1 * V_2 , * V_139 ;
F_26 ( V_4 , L_8 ) ;
F_52 (evt, pos, &vhost->sent, queue)
F_48 ( V_2 , V_135 ) ;
}
static void F_53 ( struct V_3 * V_4 )
{
F_51 ( V_4 , V_55 ) ;
F_18 ( V_4 , V_140 ) ;
F_14 ( V_4 , V_85 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
if ( V_4 -> V_117 && V_4 -> V_67 != V_77 &&
! F_13 ( V_4 , V_88 ) ) {
F_16 ( V_4 -> V_89 ) ;
F_14 ( V_4 , V_78 ) ;
V_4 -> V_103 = V_141 ;
F_17 ( & V_4 -> V_91 ) ;
} else
F_53 ( V_4 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
unsigned long V_39 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_54 ( V_4 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
int V_57 = 0 ;
if ( V_4 -> V_67 == V_76 ) {
V_4 -> V_142 = 1 ;
if ( ++ V_4 -> V_96 > V_97 ) {
F_21 ( V_4 -> V_98 ,
L_1 ) ;
F_18 ( V_4 , V_73 ) ;
} else if ( V_4 -> V_96 == V_97 )
F_54 ( V_4 ) ;
else {
F_14 ( V_4 , V_79 ) ;
V_57 = 1 ;
}
}
F_17 ( & V_4 -> V_91 ) ;
return V_57 ;
}
static struct V_64 * F_57 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_58 ( V_144 -> V_98 . V_147 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
struct V_64 * V_65 ;
F_19 (tgt, &vhost->targets, queue)
if ( V_65 -> V_148 == V_144 -> V_149 ) {
F_60 ( & V_65 -> V_150 ) ;
return V_65 ;
}
return NULL ;
}
static struct V_64 * F_61 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_58 ( V_144 -> V_98 . V_147 ) ;
struct V_64 * V_65 ;
unsigned long V_39 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
V_65 = F_57 ( V_144 ) ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return V_65 ;
}
static void F_62 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
if ( V_4 -> V_72 == V_151 ) {
switch ( V_4 -> V_152 -> V_153 . V_154 / 100 ) {
case 1 :
F_63 ( V_146 ) = V_155 ;
break;
case 2 :
F_63 ( V_146 ) = V_156 ;
break;
case 4 :
F_63 ( V_146 ) = V_157 ;
break;
case 8 :
F_63 ( V_146 ) = V_158 ;
break;
case 10 :
F_63 ( V_146 ) = V_159 ;
break;
case 16 :
F_63 ( V_146 ) = V_160 ;
break;
default:
F_64 ( V_4 , 3 , L_9 ,
V_4 -> V_152 -> V_153 . V_154 / 100 ) ;
F_63 ( V_146 ) = V_161 ;
break;
}
} else
F_63 ( V_146 ) = V_161 ;
F_39 ( V_146 -> V_122 , V_39 ) ;
}
static void F_65 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
switch ( V_4 -> V_72 ) {
case V_88 :
case V_151 :
F_66 ( V_146 ) = V_162 ;
break;
case V_140 :
F_66 ( V_146 ) = V_163 ;
break;
case V_164 :
case V_73 :
F_66 ( V_146 ) = V_165 ;
break;
case V_166 :
F_66 ( V_146 ) = V_167 ;
break;
case V_116 :
F_66 ( V_146 ) = V_168 ;
break;
default:
F_64 ( V_4 , 3 , L_10 , V_4 -> V_72 ) ;
F_66 ( V_146 ) = V_168 ;
break;
}
F_39 ( V_146 -> V_122 , V_39 ) ;
}
static void F_67 ( struct V_169 * V_170 , T_3 V_171 )
{
if ( V_171 )
V_170 -> V_172 = V_171 ;
else
V_170 -> V_172 = 1 ;
}
static void F_68 ( struct V_150 * V_150 )
{
struct V_64 * V_65 = F_69 ( V_150 , struct V_64 , V_150 ) ;
F_70 ( V_65 ) ;
}
static void F_71 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_61 ( V_144 ) ;
F_72 ( V_144 ) = V_65 ? V_65 -> V_173 . V_174 : 0 ;
if ( V_65 )
F_73 ( & V_65 -> V_150 , F_68 ) ;
}
static void F_74 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_61 ( V_144 ) ;
F_72 ( V_144 ) = V_65 ? V_65 -> V_173 . V_175 : 0 ;
if ( V_65 )
F_73 ( & V_65 -> V_150 , F_68 ) ;
}
static void F_75 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_61 ( V_144 ) ;
F_76 ( V_144 ) = V_65 ? V_65 -> V_24 : - 1 ;
if ( V_65 )
F_73 ( & V_65 -> V_150 , F_68 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
long V_171 = F_78 ( V_4 -> V_176 ,
( ( V_4 -> V_72 == V_151 ||
V_4 -> V_72 == V_73 ||
V_4 -> V_72 == V_164 ) &&
V_4 -> V_67 == V_81 ) ,
( V_177 * V_178 ) ) ;
return V_171 ? 0 : - V_179 ;
}
static int F_79 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_59 ( V_146 ) ;
F_21 ( V_4 -> V_98 , L_11 ) ;
F_55 ( V_4 ) ;
return F_77 ( V_4 ) ;
}
static void F_80 ( struct V_3 * V_4 )
{
struct V_180 * V_181 ;
const char * V_48 ;
const unsigned int * V_182 ;
V_181 = F_81 ( L_12 ) ;
if ( ! V_181 )
return;
V_48 = F_82 ( V_181 , L_13 , NULL ) ;
if ( V_48 )
strncpy ( V_4 -> V_183 , V_48 , sizeof( V_4 -> V_183 ) ) ;
V_182 = F_82 ( V_181 , L_14 , NULL ) ;
if ( V_182 )
V_4 -> V_184 = * V_182 ;
F_83 ( V_181 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_104 * V_185 = & V_4 -> V_185 ;
struct V_180 * V_186 = V_4 -> V_98 -> V_186 ;
const char * V_187 ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
V_185 -> V_188 = V_189 ;
V_185 -> V_190 = V_191 << 9 ;
V_185 -> V_192 = sizeof( struct V_193 ) ;
V_185 -> V_194 = sizeof( struct V_51 ) ;
V_185 -> V_195 = V_4 -> V_184 ;
V_185 -> V_196 = 1 ;
V_185 -> V_197 = 3 ;
V_185 -> V_39 = V_198 ;
if ( V_4 -> V_199 )
V_185 -> V_39 |= V_200 ;
V_185 -> V_201 = V_202 + V_203 ;
V_185 -> V_204 = V_205 ;
V_185 -> V_206 . V_207 = V_4 -> V_99 . V_118 ;
V_185 -> V_206 . V_208 = V_4 -> V_99 . V_129 * sizeof( * V_4 -> V_99 . V_100 ) ;
strncpy ( V_185 -> V_183 , V_4 -> V_183 , V_209 ) ;
strncpy ( V_185 -> V_210 ,
F_85 ( & V_4 -> V_89 -> V_211 ) , V_209 ) ;
V_187 = F_82 ( V_186 , L_15 , NULL ) ;
V_187 = V_187 ? V_187 : F_85 ( V_4 -> V_98 ) ;
strncpy ( V_185 -> V_212 , V_187 , V_209 ) ;
}
static int F_86 ( struct V_3 * V_4 )
{
int V_44 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
V_92 ;
V_126 -> V_129 = V_202 + V_203 ;
V_126 -> V_128 = F_87 ( V_126 -> V_129 , sizeof( * V_126 -> V_128 ) , V_213 ) ;
if ( ! V_126 -> V_128 )
return - V_214 ;
V_126 -> V_215 = F_88 ( V_4 -> V_98 ,
V_126 -> V_129 * sizeof( * V_126 -> V_215 ) ,
& V_126 -> V_216 , 0 ) ;
if ( ! V_126 -> V_215 ) {
F_70 ( V_126 -> V_128 ) ;
return - V_214 ;
}
for ( V_44 = 0 ; V_44 < V_126 -> V_129 ; ++ V_44 ) {
struct V_1 * V_2 = & V_126 -> V_128 [ V_44 ] ;
F_89 ( & V_2 -> free , 1 ) ;
V_2 -> V_18 . V_217 = 0x80 ;
V_2 -> V_18 . V_218 = V_126 -> V_216 + ( sizeof( * V_2 -> V_33 ) * V_44 ) ;
V_2 -> V_33 = V_126 -> V_215 + V_44 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_219 = NULL ;
F_44 ( & V_2 -> V_130 , & V_4 -> free ) ;
}
V_95 ;
return 0 ;
}
static void F_90 ( struct V_3 * V_4 )
{
int V_44 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
V_92 ;
for ( V_44 = 0 ; V_44 < V_126 -> V_129 ; ++ V_44 ) {
F_49 ( & V_126 -> V_128 [ V_44 ] . V_130 ) ;
F_42 ( F_91 ( & V_126 -> V_128 [ V_44 ] . free ) != 1 ) ;
if ( V_126 -> V_128 [ V_44 ] . V_219 )
F_92 ( V_4 -> V_220 ,
V_126 -> V_128 [ V_44 ] . V_219 ,
V_126 -> V_128 [ V_44 ] . V_221 ) ;
}
F_70 ( V_126 -> V_128 ) ;
F_93 ( V_4 -> V_98 ,
V_126 -> V_129 * sizeof( * V_126 -> V_215 ) ,
V_126 -> V_215 , V_126 -> V_216 ) ;
V_95 ;
}
static struct V_1 * F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_42 ( F_95 ( & V_4 -> free ) ) ;
V_2 = F_96 ( V_4 -> free . V_222 , struct V_1 , V_130 ) ;
F_89 ( & V_2 -> free , 0 ) ;
F_49 ( & V_2 -> V_130 ) ;
return V_2 ;
}
static void F_97 ( struct V_1 * V_2 ,
void (* V_136) ( struct V_1 * ) , T_4 V_19 )
{
V_2 -> V_132 = NULL ;
V_2 -> V_223 = NULL ;
V_2 -> V_18 . V_19 = V_19 ;
V_2 -> V_136 = V_136 ;
V_2 -> V_134 = NULL ;
}
static void F_98 ( struct V_131 * V_224 , int V_225 ,
struct V_226 * V_227 )
{
int V_44 ;
struct V_228 * V_229 ;
F_99 (scmd, sg, nseg, i) {
V_227 [ V_44 ] . V_207 = F_100 ( V_229 ) ;
V_227 [ V_44 ] . V_208 = F_101 ( V_229 ) ;
V_227 [ V_44 ] . V_230 = 0 ;
}
}
static int F_102 ( struct V_131 * V_224 ,
struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_231 * V_98 )
{
int V_232 ;
struct V_226 * V_41 = & V_6 -> V_218 ;
struct V_3 * V_4 = F_103 ( V_98 ) ;
V_232 = F_104 ( V_224 ) ;
if ( ! V_232 ) {
V_6 -> V_39 |= V_233 ;
return 0 ;
} else if ( F_105 ( V_232 < 0 ) ) {
if ( V_4 -> V_234 > V_235 )
F_106 ( V_236 , V_224 , L_16 ) ;
return V_232 ;
}
if ( V_224 -> V_237 == V_238 ) {
V_6 -> V_39 |= V_239 ;
V_6 -> V_7 . V_240 |= V_241 ;
} else {
V_6 -> V_39 |= V_242 ;
V_6 -> V_7 . V_240 |= V_243 ;
}
if ( V_232 == 1 ) {
F_98 ( V_224 , V_232 , V_41 ) ;
return 0 ;
}
V_6 -> V_39 |= V_244 ;
if ( ! V_2 -> V_219 ) {
V_2 -> V_219 = F_107 ( V_4 -> V_220 , V_245 ,
& V_2 -> V_221 ) ;
if ( ! V_2 -> V_219 ) {
F_46 ( V_224 ) ;
if ( V_4 -> V_234 > V_235 )
F_106 ( V_236 , V_224 , L_17 ) ;
return - V_214 ;
}
}
F_98 ( V_224 , V_232 , V_2 -> V_219 ) ;
V_41 -> V_207 = V_2 -> V_221 ;
V_41 -> V_208 = V_232 * sizeof( struct V_226 ) ;
V_41 -> V_230 = 0 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_21 ( V_4 -> V_98 , L_18 , V_2 ) ;
F_55 ( V_4 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_171 )
{
T_2 * V_246 = ( T_2 * ) & V_2 -> V_18 ;
int V_47 ;
* V_2 -> V_33 = V_2 -> V_7 ;
if ( V_2 -> V_18 . V_19 == V_21 )
V_2 -> V_33 -> V_8 . V_247 = ( T_2 ) V_2 ;
else if ( V_2 -> V_18 . V_19 == V_31 )
V_2 -> V_33 -> V_11 . V_247 = ( T_2 ) V_2 ;
else
F_110 () ;
F_44 ( & V_2 -> V_130 , & V_4 -> V_248 ) ;
F_111 ( & V_2 -> V_138 ) ;
if ( V_171 ) {
V_2 -> V_138 . V_41 = ( unsigned long ) V_2 ;
V_2 -> V_138 . V_249 = V_16 + ( V_171 * V_178 ) ;
V_2 -> V_138 . V_250 = ( void (*) ( unsigned long ) ) F_108 ;
F_112 ( & V_2 -> V_138 ) ;
}
F_113 () ;
if ( ( V_47 = F_22 ( V_4 , V_246 [ 0 ] , V_246 [ 1 ] ) ) ) {
F_49 ( & V_2 -> V_130 ) ;
F_50 ( & V_2 -> V_138 ) ;
if ( V_47 == V_124 ) {
if ( F_114 () )
F_38 ( V_4 -> V_98 , L_19 ) ;
if ( V_2 -> V_132 )
F_46 ( V_2 -> V_132 ) ;
F_41 ( V_2 ) ;
return V_251 ;
}
F_21 ( V_4 -> V_98 , L_20 , V_47 ) ;
if ( V_2 -> V_132 ) {
V_2 -> V_132 -> V_56 = V_55 << 16 ;
V_2 -> V_136 = F_45 ;
} else
V_2 -> V_33 -> V_11 . V_36 = V_252 ;
V_2 -> V_136 ( V_2 ) ;
} else
F_1 ( V_2 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_33 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
struct V_131 * V_132 = V_2 -> V_132 ;
const char * V_50 = V_49 ;
int V_127 = F_4 ( V_6 -> V_36 , V_6 -> error ) ;
int V_253 = 0 ;
int V_40 = 0 ;
if ( V_127 >= 0 ) {
V_253 = V_45 [ V_127 ] . log ;
V_50 = V_45 [ V_127 ] . V_48 ;
}
if ( ! V_253 && ( V_4 -> V_234 <= ( V_235 + 1 ) ) )
return;
if ( V_38 -> V_39 & V_54 )
V_40 = V_38 -> V_41 . V_42 . V_40 ;
F_106 ( V_236 , V_132 , L_21
L_22 ,
V_132 -> V_132 [ 0 ] , V_50 , V_6 -> V_36 , V_6 -> error ,
V_38 -> V_39 , V_40 , F_116 ( V_132 ) , V_38 -> V_43 ) ;
}
static void F_117 ( struct V_254 * V_255 )
{
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
struct V_169 * V_170 = F_118 ( V_143 ( V_255 ) ) ;
struct V_64 * V_65 ;
F_19 (tgt, &vhost->targets, queue) {
if ( V_170 == V_65 -> V_170 ) {
F_12 ( V_65 , V_68 ) ;
break;
}
}
F_15 ( V_4 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_33 -> V_8 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
struct V_131 * V_132 = V_2 -> V_132 ;
T_3 V_256 = 0 ;
T_3 V_257 = V_38 -> V_258 ;
if ( V_132 ) {
if ( V_6 -> V_259 & V_260 )
F_120 ( V_132 , V_6 -> V_261 ) ;
else if ( V_38 -> V_39 & V_262 )
F_120 ( V_132 , V_38 -> V_263 ) ;
else
F_120 ( V_132 , 0 ) ;
if ( V_6 -> V_36 ) {
V_132 -> V_56 = F_7 ( V_6 ) ;
if ( V_38 -> V_39 & V_54 )
V_256 = V_38 -> V_53 ;
if ( ( V_257 + V_256 ) > V_264 )
V_257 = V_264 - V_256 ;
if ( ( V_38 -> V_39 & V_265 ) && V_38 -> V_258 && V_256 <= 8 )
memcpy ( V_132 -> V_266 , V_38 -> V_41 . V_267 + V_256 , V_257 ) ;
if ( ( V_6 -> V_36 & V_268 ) && ( V_6 -> error == V_269 ) )
F_117 ( V_132 -> V_231 ) ;
if ( ! V_132 -> V_56 && ( ! F_116 ( V_132 ) || ( V_38 -> V_39 & V_270 ) ) )
V_132 -> V_56 = ( V_55 << 16 ) ;
F_115 ( V_2 ) ;
}
if ( ! V_132 -> V_56 &&
( F_121 ( V_132 ) - F_116 ( V_132 ) < V_132 -> V_271 ) )
V_132 -> V_56 = ( V_55 << 16 ) ;
F_46 ( V_132 ) ;
V_132 -> V_133 ( V_132 ) ;
}
if ( V_2 -> V_134 )
F_47 ( V_2 -> V_134 ) ;
F_41 ( V_2 ) ;
}
static inline int F_122 ( struct V_3 * V_4 )
{
int V_56 = 0 ;
switch ( V_4 -> V_72 ) {
case V_164 :
case V_73 :
V_56 = V_272 << 16 ;
break;
case V_116 :
case V_88 :
case V_166 :
case V_140 :
V_56 = V_273 << 16 ;
break;
case V_151 :
V_56 = 0 ;
break;
} ;
return V_56 ;
}
static int F_123 ( struct V_131 * V_132 ,
void (* V_136) ( struct V_131 * ) )
{
struct V_3 * V_4 = F_59 ( V_132 -> V_231 -> V_89 ) ;
struct V_169 * V_170 = F_118 ( V_143 ( V_132 -> V_231 ) ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_4 V_247 [ 2 ] ;
int V_47 ;
if ( F_105 ( ( V_47 = F_124 ( V_170 ) ) ) ||
F_105 ( ( V_47 = F_122 ( V_4 ) ) ) ) {
V_132 -> V_56 = V_47 ;
V_136 ( V_132 ) ;
return 0 ;
}
V_132 -> V_56 = ( V_274 << 16 ) ;
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , F_119 , V_21 ) ;
V_2 -> V_132 = V_132 ;
V_132 -> V_133 = V_136 ;
V_6 = & V_2 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_153 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 + F_125 ( struct V_5 , V_38 ) ;
V_6 -> V_153 . V_208 = sizeof( V_6 -> V_38 ) ;
V_6 -> V_275 = V_276 ;
V_6 -> V_277 = sizeof( V_6 -> V_7 ) ;
V_6 -> V_278 = sizeof( V_6 -> V_38 ) ;
V_6 -> V_279 = ( unsigned long ) V_132 -> V_231 -> V_280 ;
V_6 -> V_25 = V_170 -> V_281 ;
V_6 -> V_7 . V_30 = F_121 ( V_132 ) ;
F_126 ( V_132 -> V_231 -> V_26 , & V_6 -> V_7 . V_26 ) ;
memcpy ( V_6 -> V_7 . V_23 , V_132 -> V_132 , V_132 -> V_282 ) ;
if ( F_127 ( V_132 , V_247 ) ) {
V_6 -> V_283 = V_247 [ 1 ] ;
switch ( V_247 [ 0 ] ) {
case V_284 :
V_6 -> V_7 . V_285 = V_286 ;
break;
case V_287 :
V_6 -> V_7 . V_285 = V_288 ;
break;
case V_289 :
V_6 -> V_7 . V_285 = V_290 ;
break;
} ;
}
if ( F_128 ( ! ( V_47 = F_102 ( V_132 , V_2 , V_6 , V_4 -> V_98 ) ) ) )
return F_109 ( V_2 , V_4 , 0 ) ;
F_41 ( V_2 ) ;
if ( V_47 == - V_214 )
return V_251 ;
if ( V_4 -> V_234 > V_235 )
F_106 ( V_236 , V_132 ,
L_23 , V_47 ) ;
V_132 -> V_56 = V_55 << 16 ;
V_136 ( V_132 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_41 ( V_2 ) ;
V_4 -> V_291 = 0 ;
F_130 ( V_4 -> V_98 , L_24 ) ;
}
static int F_131 ( struct V_292 * V_293 )
{
struct V_3 * V_4 = F_59 ( V_293 -> V_146 ) ;
unsigned long V_281 = ( unsigned long ) V_293 -> V_294 ;
struct V_1 * V_2 ;
struct V_295 * V_296 ;
unsigned long V_39 ;
int V_47 ;
V_92 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_291 || V_4 -> V_72 != V_151 ) {
F_54 ( V_4 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
V_4 -> V_291 = 1 ;
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , F_129 , V_31 ) ;
V_296 = & V_2 -> V_7 . V_296 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_297 . V_298 = 1 ;
V_296 -> V_297 . V_32 = V_299 ;
V_296 -> V_297 . V_300 = sizeof( * V_296 ) ;
V_296 -> V_24 = V_281 ;
V_296 -> V_279 = V_301 ;
V_296 -> V_302 = V_303 ;
V_47 = F_109 ( V_2 , V_4 , V_304 ) ;
if ( V_47 != 0 ) {
V_4 -> V_291 = 0 ;
F_21 ( V_4 -> V_98 , L_25 , V_47 ) ;
V_47 = - V_179 ;
} else
F_130 ( V_4 -> V_98 , L_26 ,
V_281 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
return V_47 ;
}
static int F_132 ( struct V_3 * V_4 , unsigned int V_281 )
{
struct V_305 * V_306 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
union V_307 V_308 ;
unsigned long V_39 ;
int V_47 = 0 , V_309 = 1 ;
V_92 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_24 == V_281 ) {
V_309 = 0 ;
break;
}
}
if ( ! V_309 )
goto V_310;
if ( F_105 ( ( V_47 = F_122 ( V_4 ) ) ) )
goto V_310;
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , V_311 , V_31 ) ;
V_306 = & V_2 -> V_7 . V_306 ;
memset ( V_306 , 0 , sizeof( * V_306 ) ) ;
V_306 -> V_297 . V_298 = 1 ;
V_306 -> V_297 . V_32 = V_312 ;
V_306 -> V_297 . V_300 = sizeof( * V_306 ) ;
V_306 -> V_24 = V_281 ;
V_2 -> V_223 = & V_308 ;
F_133 ( & V_2 -> V_313 ) ;
V_47 = F_109 ( V_2 , V_4 , V_304 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 )
return - V_179 ;
F_134 ( & V_2 -> V_313 ) ;
if ( V_308 . V_306 . V_297 . V_36 )
V_47 = - V_179 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_41 ( V_2 ) ;
V_310:
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
return V_47 ;
}
static int F_135 ( struct V_292 * V_293 )
{
struct V_3 * V_4 = F_59 ( V_293 -> V_146 ) ;
struct V_169 * V_170 = V_293 -> V_170 ;
struct V_314 * V_10 ;
struct V_1 * V_2 ;
union V_307 V_308 ;
unsigned long V_39 , V_281 = - 1 ;
unsigned int V_315 = V_293 -> V_316 -> V_317 ;
int V_47 = 0 , V_318 , V_319 , V_309 = 0 ;
T_3 V_320 , V_256 ;
V_92 ;
V_293 -> V_321 -> V_322 = 0 ;
if ( V_170 )
V_281 = V_170 -> V_281 ;
switch ( V_315 ) {
case V_323 :
V_281 = ( V_293 -> V_316 -> V_324 . V_325 . V_281 [ 0 ] << 16 ) |
( V_293 -> V_316 -> V_324 . V_325 . V_281 [ 1 ] << 8 ) |
V_293 -> V_316 -> V_324 . V_325 . V_281 [ 2 ] ;
case V_326 :
V_320 = V_327 ;
break;
case V_328 :
V_309 = 1 ;
V_281 = ( V_293 -> V_316 -> V_324 . V_329 . V_281 [ 0 ] << 16 ) |
( V_293 -> V_316 -> V_324 . V_329 . V_281 [ 1 ] << 8 ) |
V_293 -> V_316 -> V_324 . V_329 . V_281 [ 2 ] ;
case V_330 :
V_320 = V_331 ;
break;
default:
return - V_332 ;
} ;
if ( V_281 == - 1 )
return - V_46 ;
if ( ! F_136 ( & V_4 -> V_333 ) )
return - V_334 ;
V_293 -> V_294 = ( void * ) V_281 ;
V_318 = F_137 ( V_4 -> V_98 , V_293 -> V_335 . V_336 ,
V_293 -> V_335 . V_337 , V_238 ) ;
if ( ! V_318 ) {
F_138 ( & V_4 -> V_333 ) ;
return - V_214 ;
}
V_319 = F_137 ( V_4 -> V_98 , V_293 -> V_338 . V_336 ,
V_293 -> V_338 . V_337 , V_339 ) ;
if ( ! V_319 ) {
F_139 ( V_4 -> V_98 , V_293 -> V_335 . V_336 ,
V_293 -> V_335 . V_337 , V_238 ) ;
F_138 ( & V_4 -> V_333 ) ;
return - V_214 ;
}
if ( V_318 > 1 || V_319 > 1 ) {
V_47 = - V_46 ;
goto V_340;
}
if ( V_309 )
V_47 = F_132 ( V_4 , V_281 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( F_105 ( V_47 || ( V_170 && ( V_47 = F_124 ( V_170 ) ) ) ) ||
F_105 ( ( V_47 = F_122 ( V_4 ) ) ) ) {
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
goto V_340;
}
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , V_311 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_341 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_342 ;
V_10 -> V_297 . V_300 = sizeof( * V_10 ) - sizeof( V_10 -> V_343 ) - sizeof( V_10 -> V_7 ) ;
V_10 -> V_344 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 +
F_125 ( struct V_314 , V_7 ) ;
V_10 -> V_344 . V_208 = sizeof( V_10 -> V_7 ) ;
V_10 -> V_7 . V_282 = V_293 -> V_335 . V_277 ;
V_10 -> V_7 . V_256 = V_293 -> V_338 . V_277 ;
V_10 -> V_7 . V_39 = V_320 ;
V_10 -> V_7 . V_279 = V_301 ;
V_10 -> V_7 . V_8 . V_207 = F_100 ( V_293 -> V_335 . V_336 ) ;
V_10 -> V_7 . V_8 . V_208 = F_101 ( V_293 -> V_335 . V_336 ) ;
V_10 -> V_7 . V_38 . V_207 = F_100 ( V_293 -> V_338 . V_336 ) ;
V_10 -> V_7 . V_38 . V_208 = F_101 ( V_293 -> V_338 . V_336 ) ;
V_10 -> V_7 . V_24 = V_281 ;
V_10 -> V_7 . V_247 = ( T_2 ) V_2 ;
V_256 = V_10 -> V_7 . V_38 . V_208 ;
V_2 -> V_223 = & V_308 ;
F_133 ( & V_2 -> V_313 ) ;
V_47 = F_109 ( V_2 , V_4 , 0 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 ) {
V_47 = - V_179 ;
goto V_340;
}
F_134 ( & V_2 -> V_313 ) ;
if ( V_308 . V_341 . V_297 . V_36 )
V_47 = - V_179 ;
else
V_293 -> V_321 -> V_322 = V_256 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_41 ( V_2 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_293 -> V_321 -> V_56 = V_47 ;
V_293 -> V_345 ( V_293 ) ;
V_47 = 0 ;
V_340:
F_139 ( V_4 -> V_98 , V_293 -> V_335 . V_336 ,
V_293 -> V_335 . V_337 , V_238 ) ;
F_139 ( V_4 -> V_98 , V_293 -> V_338 . V_336 ,
V_293 -> V_338 . V_337 , V_339 ) ;
F_138 ( & V_4 -> V_333 ) ;
V_95 ;
return V_47 ;
}
static int F_140 ( struct V_254 * V_255 , int type , char * V_346 )
{
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
struct V_169 * V_170 = F_118 ( V_143 ( V_255 ) ) ;
struct V_5 * V_296 ;
struct V_1 * V_2 = NULL ;
union V_307 V_308 ;
struct V_51 * V_347 = & V_308 . V_8 . V_38 ;
int V_348 = - V_334 ;
unsigned long V_39 ;
int V_40 = 0 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_72 == V_151 ) {
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , V_311 , V_21 ) ;
V_296 = & V_2 -> V_7 . V_8 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_153 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 + F_125 ( struct V_5 , V_38 ) ;
V_296 -> V_153 . V_208 = sizeof( V_296 -> V_38 ) ;
V_296 -> V_275 = V_276 ;
V_296 -> V_277 = sizeof( V_296 -> V_7 ) ;
V_296 -> V_278 = sizeof( V_296 -> V_38 ) ;
V_296 -> V_279 = ( unsigned long ) V_255 -> V_280 ;
V_296 -> V_25 = V_170 -> V_281 ;
F_126 ( V_255 -> V_26 , & V_296 -> V_7 . V_26 ) ;
V_296 -> V_39 = ( V_233 | V_349 ) ;
V_296 -> V_7 . V_27 = type ;
V_2 -> V_223 = & V_308 ;
F_133 ( & V_2 -> V_313 ) ;
V_348 = F_109 ( V_2 , V_4 , V_304 ) ;
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_348 != 0 ) {
F_141 ( V_236 , V_255 , L_27 ,
V_346 , V_348 ) ;
return - V_179 ;
}
F_141 ( V_350 , V_255 , L_28 , V_346 ) ;
F_134 ( & V_2 -> V_313 ) ;
if ( V_308 . V_8 . V_36 )
V_40 = F_7 ( & V_308 . V_8 ) ;
if ( V_40 ) {
if ( V_347 -> V_39 & V_54 )
V_40 = V_347 -> V_41 . V_42 . V_40 ;
F_141 ( V_236 , V_255 , L_29
L_30 ,
V_346 , F_6 ( V_308 . V_8 . V_36 , V_308 . V_8 . error ) ,
V_308 . V_8 . V_36 , V_308 . V_8 . error , V_347 -> V_39 , V_40 ,
V_347 -> V_43 ) ;
V_348 = - V_179 ;
} else
F_141 ( V_350 , V_255 , L_31 , V_346 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_41 ( V_2 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_348 ;
}
static int F_142 ( struct V_1 * V_2 , void * V_170 )
{
struct V_169 * V_351 ;
if ( V_2 -> V_132 ) {
V_351 = F_118 ( V_143 ( V_2 -> V_132 -> V_231 ) ) ;
if ( V_351 == V_170 )
return 1 ;
}
return 0 ;
}
static int F_143 ( struct V_1 * V_2 , void * V_231 )
{
if ( V_2 -> V_132 && V_143 ( V_2 -> V_132 -> V_231 ) == V_231 )
return 1 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , void * V_231 )
{
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_231 )
return 1 ;
return 0 ;
}
static int F_145 ( struct V_3 * V_4 , void * V_231 ,
int (* F_146) ( struct V_1 * , void * ) )
{
struct V_1 * V_2 ;
F_147 ( V_313 ) ;
int V_352 ;
unsigned long V_39 ;
signed long V_171 = V_353 * V_178 ;
V_92 ;
do {
V_352 = 0 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_19 (evt, &vhost->sent, queue) {
if ( F_146 ( V_2 , V_231 ) ) {
V_2 -> V_134 = & V_313 ;
V_352 ++ ;
}
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_352 ) {
V_171 = F_148 ( & V_313 , V_171 ) ;
if ( ! V_171 ) {
V_352 = 0 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_19 (evt, &vhost->sent, queue) {
if ( F_146 ( V_2 , V_231 ) ) {
V_2 -> V_134 = NULL ;
V_352 ++ ;
}
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_352 )
F_21 ( V_4 -> V_98 , L_32 ) ;
V_95 ;
return V_352 ? V_354 : V_355 ;
}
}
} while ( V_352 );
V_95 ;
return V_355 ;
}
static int F_149 ( struct V_254 * V_255 , int type )
{
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
struct V_143 * V_144 = V_143 ( V_255 ) ;
struct V_169 * V_170 = F_118 ( V_144 ) ;
struct V_295 * V_296 ;
struct V_1 * V_2 , * V_356 ;
union V_307 V_38 ;
int V_348 = - V_334 ;
unsigned long V_39 ;
T_1 V_36 ;
V_92 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_356 = NULL ;
F_19 (evt, &vhost->sent, queue) {
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_255 ) {
V_356 = V_2 ;
break;
}
}
if ( ! V_356 ) {
if ( V_4 -> V_234 > V_235 )
F_141 ( V_350 , V_255 , L_33 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
if ( V_4 -> V_117 ) {
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , V_311 , V_31 ) ;
V_296 = & V_2 -> V_7 . V_296 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_297 . V_298 = 1 ;
V_296 -> V_297 . V_32 = V_299 ;
V_296 -> V_297 . V_300 = sizeof( * V_296 ) ;
V_296 -> V_24 = V_170 -> V_281 ;
F_126 ( V_255 -> V_26 , & V_296 -> V_26 ) ;
if ( ! ( V_4 -> V_152 -> V_153 . V_204 & V_357 ) )
type &= ~ V_358 ;
if ( V_4 -> V_72 == V_151 )
V_296 -> V_39 = ( type | V_359 ) ;
else
V_296 -> V_39 = ( ( type & V_358 ) | V_359 ) ;
V_296 -> V_279 = ( unsigned long ) V_255 -> V_280 ;
V_296 -> V_302 = ( unsigned long ) V_144 -> V_280 ;
V_2 -> V_223 = & V_38 ;
F_133 ( & V_2 -> V_313 ) ;
V_348 = F_109 ( V_2 , V_4 , V_304 ) ;
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_348 != 0 ) {
F_141 ( V_236 , V_255 , L_25 , V_348 ) ;
return - V_179 ;
}
F_141 ( V_350 , V_255 , L_34 ) ;
F_134 ( & V_2 -> V_313 ) ;
V_36 = V_38 . V_11 . V_36 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_41 ( V_2 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_36 != V_360 ) {
F_141 ( V_361 , V_255 , L_35 , V_36 ) ;
return - V_179 ;
}
F_141 ( V_350 , V_255 , L_36 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , void * V_230 )
{
unsigned long V_279 = ( unsigned long ) V_230 ;
if ( V_2 -> V_18 . V_19 == V_21 &&
V_2 -> V_7 . V_8 . V_279 == V_279 )
return 1 ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , void * F_146 )
{
if ( V_2 == F_146 )
return 1 ;
return 0 ;
}
static int F_152 ( struct V_254 * V_255 )
{
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
struct V_169 * V_170 = F_118 ( V_143 ( V_255 ) ) ;
struct V_5 * V_296 ;
struct V_1 * V_2 , * V_356 ;
union V_307 V_308 ;
struct V_51 * V_347 = & V_308 . V_8 . V_38 ;
int V_47 , V_348 = - V_334 ;
unsigned long V_39 , V_171 = V_362 ;
int V_40 = 0 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_356 = NULL ;
F_19 (evt, &vhost->sent, queue) {
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_255 ) {
V_356 = V_2 ;
break;
}
}
if ( ! V_356 ) {
if ( V_4 -> V_234 > V_235 )
F_141 ( V_350 , V_255 , L_37 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
if ( V_4 -> V_72 == V_151 ) {
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , V_311 , V_21 ) ;
V_296 = & V_2 -> V_7 . V_8 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_153 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 + F_125 ( struct V_5 , V_38 ) ;
V_296 -> V_153 . V_208 = sizeof( V_296 -> V_38 ) ;
V_296 -> V_275 = V_276 ;
V_296 -> V_277 = sizeof( V_296 -> V_7 ) ;
V_296 -> V_278 = sizeof( V_296 -> V_38 ) ;
V_296 -> V_279 = ( unsigned long ) V_255 -> V_280 ;
V_296 -> V_25 = V_170 -> V_281 ;
F_126 ( V_255 -> V_26 , & V_296 -> V_7 . V_26 ) ;
V_296 -> V_39 = ( V_233 | V_349 ) ;
V_296 -> V_7 . V_27 = V_363 ;
V_2 -> V_223 = & V_308 ;
F_133 ( & V_2 -> V_313 ) ;
V_348 = F_109 ( V_2 , V_4 , V_304 ) ;
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_348 != 0 ) {
F_141 ( V_236 , V_255 , L_38 , V_348 ) ;
return - V_179 ;
}
F_141 ( V_350 , V_255 , L_39 ) ;
V_171 = F_148 ( & V_2 -> V_313 , V_171 ) ;
if ( ! V_171 ) {
V_47 = F_149 ( V_255 , 0 ) ;
if ( ! V_47 ) {
V_47 = F_145 ( V_4 , V_255 -> V_280 , F_150 ) ;
if ( V_47 == V_355 )
V_47 = 0 ;
}
if ( V_47 ) {
F_141 ( V_350 , V_255 , L_40 ) ;
F_55 ( V_4 ) ;
V_348 = - V_179 ;
V_47 = F_145 ( V_4 , V_255 -> V_280 , F_150 ) ;
if ( V_47 == V_355 )
V_348 = 0 ;
V_47 = F_145 ( V_4 , V_2 , F_151 ) ;
if ( V_47 != V_355 ) {
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_53 ( V_4 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_348 = 0 ;
}
goto V_340;
}
}
if ( V_308 . V_8 . V_36 )
V_40 = F_7 ( & V_308 . V_8 ) ;
if ( V_40 ) {
if ( V_347 -> V_39 & V_54 )
V_40 = V_347 -> V_41 . V_42 . V_40 ;
F_141 ( V_236 , V_255 , L_41
L_30 ,
F_6 ( V_308 . V_8 . V_36 , V_308 . V_8 . error ) ,
V_308 . V_8 . V_36 , V_308 . V_8 . error , V_347 -> V_39 , V_40 ,
V_347 -> V_43 ) ;
V_348 = - V_179 ;
} else
F_141 ( V_350 , V_255 , L_42 ) ;
V_340:
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_41 ( V_2 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_348 ;
}
static int F_153 ( struct V_131 * V_8 )
{
struct V_254 * V_255 = V_8 -> V_231 ;
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
int V_364 , V_365 ;
int V_47 = V_354 ;
V_92 ;
V_365 = F_154 ( V_8 ) ;
F_77 ( V_4 ) ;
if ( V_365 != V_366 ) {
V_364 = F_149 ( V_255 , V_367 ) ;
F_152 ( V_255 ) ;
} else
V_364 = F_149 ( V_255 , V_358 ) ;
if ( ! V_364 )
V_47 = F_145 ( V_4 , V_255 , F_144 ) ;
if ( V_365 == V_366 && V_47 != V_354 )
V_47 = V_366 ;
V_95 ;
return V_47 ;
}
static int F_155 ( struct V_131 * V_8 )
{
struct V_254 * V_255 = V_8 -> V_231 ;
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
int V_364 , V_365 , V_368 = 0 ;
int V_47 = V_354 ;
V_92 ;
V_365 = F_154 ( V_8 ) ;
F_77 ( V_4 ) ;
if ( V_365 != V_366 ) {
V_364 = F_149 ( V_255 , V_369 ) ;
V_368 = F_140 ( V_255 , V_370 , L_43 ) ;
} else
V_364 = F_149 ( V_255 , V_358 ) ;
if ( ! V_364 && ! V_368 )
V_47 = F_145 ( V_4 , V_255 , F_144 ) ;
if ( V_365 == V_366 && V_47 != V_354 )
V_47 = V_366 ;
V_95 ;
return V_47 ;
}
static void F_156 ( struct V_254 * V_255 , void * V_41 )
{
unsigned long * V_47 = V_41 ;
* V_47 |= F_149 ( V_255 , V_358 ) ;
}
static void F_157 ( struct V_254 * V_255 , void * V_41 )
{
unsigned long * V_47 = V_41 ;
* V_47 |= F_149 ( V_255 , V_371 ) ;
}
static int F_158 ( struct V_131 * V_8 )
{
struct V_254 * V_255 = V_8 -> V_231 ;
struct V_3 * V_4 = F_59 ( V_255 -> V_89 ) ;
struct V_143 * V_144 = V_143 ( V_255 ) ;
int V_365 ;
int V_368 = 0 ;
int V_47 = V_354 ;
unsigned long V_364 = 0 ;
V_92 ;
V_365 = F_154 ( V_8 ) ;
F_77 ( V_4 ) ;
if ( V_365 != V_366 ) {
F_159 ( V_144 , & V_364 , F_157 ) ;
V_368 = F_140 ( V_255 , V_372 , L_44 ) ;
} else
F_159 ( V_144 , & V_364 , F_156 ) ;
if ( ! V_364 && ! V_368 )
V_47 = F_145 ( V_4 , V_144 , F_143 ) ;
if ( V_365 == V_366 && V_47 != V_354 )
V_47 = V_366 ;
V_95 ;
return V_47 ;
}
static int F_160 ( struct V_131 * V_8 )
{
int V_47 , V_365 ;
struct V_3 * V_4 = F_59 ( V_8 -> V_231 -> V_89 ) ;
V_365 = F_154 ( V_8 ) ;
F_21 ( V_4 -> V_98 , L_45 ) ;
V_47 = F_79 ( V_4 -> V_89 ) ;
if ( V_365 == V_366 )
return V_366 ;
return V_47 ? V_354 : V_355 ;
}
static void F_161 ( struct V_169 * V_170 )
{
struct V_145 * V_146 = F_162 ( V_170 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
struct V_169 * V_373 ;
struct V_254 * V_255 ;
unsigned long V_47 ;
V_92 ;
F_163 (sdev, shost) {
V_373 = F_118 ( V_143 ( V_255 ) ) ;
if ( V_373 != V_170 )
continue;
F_149 ( V_255 , V_358 ) ;
}
V_47 = F_145 ( V_4 , V_170 , F_142 ) ;
if ( V_47 == V_354 )
F_79 ( V_146 ) ;
V_95 ;
}
static const struct V_374 * F_164 ( T_2 V_375 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_376 ) ; V_44 ++ )
if ( V_376 [ V_44 ] . V_375 == V_375 )
return & V_376 [ V_44 ] ;
return & V_377 ;
}
static const char * F_165 ( enum V_378 V_72 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_379 ) ; V_44 ++ )
if ( V_379 [ V_44 ] . V_72 == V_72 )
return V_379 [ V_44 ] . V_346 ;
return L_46 ;
}
static void F_166 ( struct V_380 * V_18 ,
struct V_3 * V_4 )
{
const struct V_374 * V_346 = F_164 ( V_18 -> V_381 ) ;
struct V_64 * V_65 ;
F_64 ( V_4 , V_346 -> V_234 , L_47
L_48 , V_346 -> V_346 , V_18 -> V_24 , V_18 -> V_382 , V_18 -> V_174 ,
F_165 ( V_18 -> V_383 ) ) ;
switch ( V_18 -> V_381 ) {
case V_384 :
switch ( V_18 -> V_383 ) {
case V_385 :
F_18 ( V_4 , V_140 ) ;
break;
case V_386 :
F_18 ( V_4 , V_164 ) ;
break;
case V_387 :
case V_388 :
default:
V_4 -> V_93 |= V_389 ;
V_4 -> V_142 = 1 ;
F_54 ( V_4 ) ;
break;
} ;
break;
case V_390 :
V_4 -> V_93 |= V_389 ;
V_4 -> V_142 = 1 ;
F_54 ( V_4 ) ;
break;
case V_391 :
case V_392 :
V_4 -> V_93 |= V_393 ;
if ( V_4 -> V_72 < V_166 ) {
V_4 -> V_142 = 1 ;
F_54 ( V_4 ) ;
}
break;
case V_394 :
case V_395 :
V_4 -> V_93 |= V_393 ;
F_15 ( V_4 ) ;
break;
case V_396 :
case V_397 :
case V_398 :
F_19 (tgt, &vhost->targets, queue) {
if ( ! V_18 -> V_24 && ! V_18 -> V_382 && ! V_18 -> V_174 )
break;
if ( V_18 -> V_24 && V_65 -> V_24 != V_18 -> V_24 )
continue;
if ( V_18 -> V_382 && V_65 -> V_173 . V_175 != V_18 -> V_382 )
continue;
if ( V_18 -> V_174 && V_65 -> V_173 . V_174 != V_18 -> V_174 )
continue;
if ( V_65 -> V_399 && V_18 -> V_381 == V_396 )
V_65 -> V_400 = 1 ;
if ( ! V_65 -> V_399 || V_18 -> V_381 == V_398 ) {
F_12 ( V_65 , V_68 ) ;
F_15 ( V_4 ) ;
}
}
break;
case V_401 :
case V_402 :
F_18 ( V_4 , V_140 ) ;
break;
case V_403 :
F_18 ( V_4 , V_164 ) ;
break;
case V_404 :
F_18 ( V_4 , V_166 ) ;
break;
default:
F_21 ( V_4 -> V_98 , L_49 , V_18 -> V_381 ) ;
break;
} ;
}
static void F_167 ( struct V_405 * V_18 , struct V_3 * V_4 )
{
long V_47 ;
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_218 ;
switch ( V_18 -> V_217 ) {
case V_406 :
switch ( V_18 -> V_19 ) {
case V_407 :
F_130 ( V_4 -> V_98 , L_50 ) ;
V_47 = F_27 ( V_4 ) ;
if ( V_47 == 0 )
F_20 ( V_4 ) ;
else
F_21 ( V_4 -> V_98 , L_51 , V_47 ) ;
break;
case V_408 :
F_130 ( V_4 -> V_98 , L_52 ) ;
F_20 ( V_4 ) ;
break;
default:
F_21 ( V_4 -> V_98 , L_53 , V_18 -> V_19 ) ;
}
return;
case V_409 :
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
F_14 ( V_4 , V_81 ) ;
if ( V_18 -> V_19 == V_410 ) {
F_130 ( V_4 -> V_98 , L_54 ) ;
V_4 -> V_199 = 1 ;
F_51 ( V_4 , V_273 ) ;
F_18 ( V_4 , V_140 ) ;
F_14 ( V_4 , V_86 ) ;
} else {
F_21 ( V_4 -> V_98 , L_55 , V_18 -> V_19 ) ;
F_51 ( V_4 , V_55 ) ;
F_18 ( V_4 , V_140 ) ;
F_14 ( V_4 , V_85 ) ;
}
return;
case V_411 :
break;
default:
F_21 ( V_4 -> V_98 , L_56 , V_18 -> V_217 ) ;
return;
}
if ( V_18 -> V_19 == V_412 )
return;
if ( F_105 ( ! F_40 ( & V_4 -> V_126 , V_2 ) ) ) {
F_21 ( V_4 -> V_98 , L_57 ,
V_18 -> V_218 ) ;
return;
}
if ( F_105 ( F_91 ( & V_2 -> free ) ) ) {
F_21 ( V_4 -> V_98 , L_58 ,
V_18 -> V_218 ) ;
return;
}
F_50 ( & V_2 -> V_138 ) ;
F_49 ( & V_2 -> V_130 ) ;
F_3 ( V_2 ) ;
V_2 -> V_136 ( V_2 ) ;
}
static int F_168 ( struct V_145 * V_146 , unsigned long time )
{
unsigned long V_39 ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
int V_136 = 0 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
if ( time >= ( V_177 * V_178 ) ) {
F_130 ( V_4 -> V_98 , L_59
L_60 , V_177 ) ;
V_136 = 1 ;
}
if ( V_4 -> V_413 )
V_136 = 1 ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return V_136 ;
}
static int F_169 ( struct V_254 * V_255 )
{
struct V_145 * V_146 = V_255 -> V_89 ;
struct V_169 * V_170 = F_118 ( V_143 ( V_255 ) ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 = 0 ;
if ( ! V_170 || F_124 ( V_170 ) )
return - V_414 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
V_255 -> V_280 = ( void * ) ( unsigned long ) V_4 -> V_415 ++ ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_170 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_58 ( V_144 -> V_98 . V_147 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 = 0 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
V_144 -> V_280 = ( void * ) ( unsigned long ) V_4 -> V_415 ++ ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_171 ( struct V_254 * V_255 )
{
struct V_145 * V_146 = V_255 -> V_89 ;
unsigned long V_39 = 0 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
if ( V_255 -> type == V_416 )
V_255 -> V_417 = 1 ;
if ( V_255 -> V_418 ) {
F_172 ( V_255 , V_284 ) ;
F_173 ( V_255 , V_255 -> V_419 ) ;
} else
F_174 ( V_255 , V_255 -> V_419 ) ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_175 ( struct V_254 * V_255 , int V_420 ,
int V_421 )
{
if ( V_421 != V_422 )
return - V_423 ;
if ( V_420 > V_424 )
V_420 = V_424 ;
F_176 ( V_255 , 0 , V_420 ) ;
return V_255 -> V_419 ;
}
static int F_177 ( struct V_254 * V_255 , int V_425 )
{
if ( V_255 -> V_418 ) {
F_172 ( V_255 , V_425 ) ;
if ( V_425 )
F_173 ( V_255 , V_255 -> V_419 ) ;
else
F_174 ( V_255 , V_255 -> V_419 ) ;
} else
V_425 = 0 ;
return V_425 ;
}
static T_5 F_178 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_183 ) ;
}
static T_5 F_180 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_210 ) ;
}
static T_5 F_181 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_429 ) ;
}
static T_5 F_182 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_212 ) ;
}
static T_5 F_183 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_62 , V_4 -> V_152 -> V_153 . V_298 ) ;
}
static T_5 F_184 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
return snprintf ( V_428 , V_101 , L_63 , V_4 -> V_152 -> V_153 . V_204 ) ;
}
static T_5 F_185 ( struct V_231 * V_98 ,
struct V_426 * V_427 , char * V_428 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 = 0 ;
int V_208 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
V_208 = snprintf ( V_428 , V_101 , L_62 , V_4 -> V_234 ) ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return V_208 ;
}
static T_5 F_186 ( struct V_231 * V_98 ,
struct V_426 * V_427 ,
const char * V_428 , T_6 V_430 )
{
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 = 0 ;
F_37 ( V_146 -> V_122 , V_39 ) ;
V_4 -> V_234 = F_187 ( V_428 , NULL , 10 ) ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return strlen ( V_428 ) ;
}
static T_5 F_188 ( struct V_431 * V_432 , struct V_433 * V_434 ,
struct V_435 * V_436 ,
char * V_428 , T_7 V_437 , T_6 V_430 )
{
struct V_231 * V_98 = F_69 ( V_434 , struct V_231 , V_434 ) ;
struct V_145 * V_146 = F_179 ( V_98 ) ;
struct V_3 * V_4 = F_59 ( V_146 ) ;
unsigned long V_39 = 0 ;
int V_129 = V_438 ;
char * V_439 = ( char * ) V_4 -> V_14 ;
if ( V_437 > V_129 )
return 0 ;
if ( V_437 + V_430 > V_129 ) {
V_129 -= V_437 ;
V_430 = V_129 ;
}
F_37 ( V_146 -> V_122 , V_39 ) ;
memcpy ( V_428 , & V_439 [ V_437 ] , V_430 ) ;
F_39 ( V_146 -> V_122 , V_39 ) ;
return V_430 ;
}
static struct V_380 * F_189 ( struct V_3 * V_4 )
{
struct V_440 * V_99 = & V_4 -> V_99 ;
struct V_380 * V_18 ;
V_18 = & V_99 -> V_100 [ V_99 -> V_102 ] ;
if ( V_18 -> V_217 & 0x80 ) {
if ( ++ V_99 -> V_102 == V_99 -> V_129 )
V_99 -> V_102 = 0 ;
F_190 () ;
} else
V_18 = NULL ;
return V_18 ;
}
static struct V_405 * F_191 ( struct V_3 * V_4 )
{
struct V_111 * V_130 = & V_4 -> V_18 ;
struct V_405 * V_18 ;
V_18 = & V_130 -> V_100 [ V_130 -> V_102 ] ;
if ( V_18 -> V_217 & 0x80 ) {
if ( ++ V_130 -> V_102 == V_130 -> V_129 )
V_130 -> V_102 = 0 ;
F_190 () ;
} else
V_18 = NULL ;
return V_18 ;
}
static T_8 F_192 ( int V_112 , void * V_441 )
{
struct V_3 * V_4 = (struct V_3 * ) V_441 ;
unsigned long V_39 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_193 ( F_23 ( V_4 -> V_98 ) ) ;
F_194 ( & V_4 -> V_113 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_442 ;
}
static void F_195 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
struct V_107 * V_108 = F_23 ( V_4 -> V_98 ) ;
struct V_405 * V_18 ;
struct V_380 * V_206 ;
unsigned long V_39 ;
int V_136 = 0 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
while ( ! V_136 ) {
while ( ( V_206 = F_189 ( V_4 ) ) != NULL ) {
F_166 ( V_206 , V_4 ) ;
V_206 -> V_217 = 0 ;
F_196 () ;
}
while ( ( V_18 = F_191 ( V_4 ) ) != NULL ) {
F_167 ( V_18 , V_4 ) ;
V_18 -> V_217 = 0 ;
F_196 () ;
}
F_197 ( V_108 ) ;
if ( ( V_206 = F_189 ( V_4 ) ) != NULL ) {
F_193 ( V_108 ) ;
F_166 ( V_206 , V_4 ) ;
V_206 -> V_217 = 0 ;
F_196 () ;
} else if ( ( V_18 = F_191 ( V_4 ) ) != NULL ) {
F_193 ( V_108 ) ;
F_167 ( V_18 , V_4 ) ;
V_18 -> V_217 = 0 ;
F_196 () ;
} else
V_136 = 1 ;
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_198 ( struct V_64 * V_65 ,
void (* V_103) ( struct V_64 * ) )
{
F_12 ( V_65 , V_443 ) ;
V_65 -> V_103 = V_103 ;
F_17 ( & V_65 -> V_4 -> V_91 ) ;
}
static int F_199 ( struct V_64 * V_65 ,
void (* V_103) ( struct V_64 * ) )
{
if ( ++ V_65 -> V_96 > V_444 ) {
F_12 ( V_65 , V_68 ) ;
F_17 ( & V_65 -> V_4 -> V_91 ) ;
return 0 ;
} else
F_198 ( V_65 , V_103 ) ;
return 1 ;
}
static int F_200 ( T_1 V_39 )
{
int V_44 ;
int V_315 = ( V_39 & 0x0f00 ) >> 8 ;
for ( V_44 = 0 ; V_44 < F_5 ( V_445 ) ; V_44 ++ )
if ( V_445 [ V_44 ] . V_315 == V_315 )
return V_44 ;
return 0 ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_446 * V_38 = & V_2 -> V_33 -> V_447 ;
struct V_448 * V_449 = & V_38 -> V_449 ;
T_3 V_36 = V_38 -> V_297 . V_36 ;
int V_127 , V_450 = V_235 ;
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
switch ( V_36 ) {
case V_360 :
F_202 ( V_65 , L_64 ,
V_449 -> type , V_449 -> V_39 , V_449 -> V_453 ) ;
if ( V_449 -> type == V_276 ) {
V_127 = F_200 ( V_449 -> V_39 ) ;
if ( V_445 [ V_127 ] . V_117 ) {
if ( V_449 -> V_39 & V_454 ) {
V_65 -> V_399 = 0 ;
V_65 -> V_173 . V_455 = 0 ;
if ( V_449 -> V_453 & V_456 )
V_65 -> V_173 . V_455 |= V_457 ;
if ( V_449 -> V_453 & V_458 )
V_65 -> V_173 . V_455 |= V_459 ;
V_65 -> V_70 = 1 ;
} else
F_12 ( V_65 , V_68 ) ;
} else if ( V_445 [ V_127 ] . V_57 )
F_199 ( V_65 , V_460 ) ;
else
F_12 ( V_65 , V_68 ) ;
} else
F_12 ( V_65 , V_68 ) ;
break;
case V_137 :
break;
case V_252 :
F_199 ( V_65 , V_460 ) ;
break;
case V_461 :
default:
if ( ( V_38 -> V_36 & V_268 ) && V_38 -> error == V_269 )
V_450 += F_199 ( V_65 , V_462 ) ;
else if ( V_65 -> V_400 )
V_450 += F_199 ( V_65 , V_462 ) ;
else if ( F_8 ( V_38 -> V_36 , V_38 -> error ) )
V_450 += F_199 ( V_65 , V_460 ) ;
else
F_12 ( V_65 , V_68 ) ;
F_203 ( V_65 , V_450 , L_65 ,
F_6 ( V_38 -> V_36 , V_38 -> error ) ,
V_38 -> V_36 , V_38 -> error , V_36 ) ;
break;
} ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_41 ( V_2 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void V_460 ( struct V_64 * V_65 )
{
struct V_446 * V_447 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_451 >= V_463 )
return;
F_60 ( & V_65 -> V_150 ) ;
V_2 = F_94 ( V_4 ) ;
V_4 -> V_451 ++ ;
F_97 ( V_2 , F_201 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_447 = & V_2 -> V_7 . V_447 ;
memset ( V_447 , 0 , sizeof( * V_447 ) ) ;
V_447 -> V_297 . V_298 = 1 ;
V_447 -> V_297 . V_32 = V_464 ;
V_447 -> V_297 . V_300 = sizeof( * V_447 ) ;
V_447 -> V_24 = V_65 -> V_24 ;
V_447 -> V_449 . type = V_276 ;
V_447 -> V_449 . V_39 = V_454 ;
V_447 -> V_449 . V_453 = V_458 ;
F_12 ( V_65 , V_465 ) ;
if ( F_109 ( V_2 , V_4 , V_304 ) ) {
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
} else
F_202 ( V_65 , L_66 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_305 * V_38 = & V_2 -> V_33 -> V_306 ;
T_3 V_36 = V_38 -> V_297 . V_36 ;
int V_450 = V_235 ;
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
switch ( V_36 ) {
case V_360 :
F_202 ( V_65 , L_67 ) ;
if ( V_65 -> V_173 . V_175 &&
V_65 -> V_173 . V_175 != F_205 ( V_38 -> V_453 . V_175 ) ) {
V_4 -> V_90 = 1 ;
F_202 ( V_65 , L_68 ) ;
break;
}
V_65 -> V_173 . V_174 = F_205 ( V_38 -> V_453 . V_174 ) ;
V_65 -> V_173 . V_175 = F_205 ( V_38 -> V_453 . V_175 ) ;
V_65 -> V_173 . V_281 = V_65 -> V_24 ;
memcpy ( & V_65 -> V_453 , & V_38 -> V_453 ,
sizeof( V_65 -> V_453 ) ) ;
memcpy ( & V_65 -> V_466 , & V_38 -> V_466 ,
sizeof( V_65 -> V_466 ) ) ;
F_198 ( V_65 , V_460 ) ;
break;
case V_137 :
break;
case V_252 :
F_199 ( V_65 , V_462 ) ;
break;
case V_461 :
default:
if ( F_8 ( V_38 -> V_36 , V_38 -> error ) )
V_450 += F_199 ( V_65 , V_462 ) ;
else
F_12 ( V_65 , V_68 ) ;
F_203 ( V_65 , V_450 , L_69 ,
F_6 ( V_38 -> V_36 , V_38 -> error ) , V_38 -> V_36 , V_38 -> error ,
F_11 ( V_38 -> V_62 ) , V_38 -> V_62 ,
F_9 ( V_38 -> V_59 ) , V_38 -> V_59 , V_36 ) ;
break;
} ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_41 ( V_2 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void V_462 ( struct V_64 * V_65 )
{
struct V_305 * V_306 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_451 >= V_463 )
return;
F_60 ( & V_65 -> V_150 ) ;
V_65 -> V_400 = 0 ;
V_2 = F_94 ( V_4 ) ;
V_4 -> V_451 ++ ;
F_12 ( V_65 , V_465 ) ;
F_97 ( V_2 , F_204 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_306 = & V_2 -> V_7 . V_306 ;
memset ( V_306 , 0 , sizeof( * V_306 ) ) ;
V_306 -> V_297 . V_298 = 1 ;
V_306 -> V_297 . V_32 = V_312 ;
V_306 -> V_297 . V_300 = sizeof( * V_306 ) ;
V_306 -> V_24 = V_65 -> V_24 ;
if ( F_109 ( V_2 , V_4 , V_304 ) ) {
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
} else
F_202 ( V_65 , L_70 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_467 * V_38 = & V_2 -> V_33 -> V_468 ;
T_3 V_36 = V_38 -> V_297 . V_36 ;
V_4 -> V_451 -- ;
F_41 ( V_2 ) ;
F_12 ( V_65 , V_452 ) ;
switch ( V_36 ) {
case V_360 :
F_202 ( V_65 , L_71 ) ;
break;
case V_137 :
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_17 ( & V_4 -> V_91 ) ;
return;
case V_461 :
default:
F_207 ( V_65 , L_72 , V_36 ) ;
break;
} ;
if ( V_4 -> V_67 == V_83 )
F_198 ( V_65 , V_462 ) ;
else if ( V_4 -> V_67 == V_87 &&
V_65 -> V_24 != V_65 -> V_469 )
F_12 ( V_65 , V_68 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void F_208 ( struct V_64 * V_65 )
{
struct V_467 * V_10 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_451 >= V_463 )
return;
F_60 ( & V_65 -> V_150 ) ;
V_2 = F_94 ( V_4 ) ;
V_4 -> V_451 ++ ;
F_97 ( V_2 , F_206 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_10 = & V_2 -> V_7 . V_468 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_470 ;
V_10 -> V_297 . V_300 = sizeof( * V_10 ) ;
V_10 -> V_471 = V_65 -> V_24 ;
F_12 ( V_65 , V_465 ) ;
if ( F_109 ( V_2 , V_4 , V_304 ) ) {
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
} else
F_202 ( V_65 , L_73 ) ;
}
static int F_209 ( struct V_314 * V_10 ,
struct V_64 * V_65 )
{
if ( memcmp ( & V_10 -> V_343 . V_472 [ 2 ] , & V_65 -> V_173 . V_175 ,
sizeof( V_65 -> V_173 . V_175 ) ) )
return 1 ;
if ( memcmp ( & V_10 -> V_343 . V_472 [ 4 ] , & V_65 -> V_173 . V_174 ,
sizeof( V_65 -> V_173 . V_174 ) ) )
return 1 ;
if ( V_10 -> V_343 . V_472 [ 6 ] != V_65 -> V_24 )
return 1 ;
return 0 ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_314 * V_10 = & V_2 -> V_33 -> V_341 ;
T_3 V_36 = V_10 -> V_297 . V_36 ;
T_4 V_473 , V_59 ;
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
F_50 ( & V_65 -> V_138 ) ;
switch ( V_36 ) {
case V_360 :
F_202 ( V_65 , L_74 ) ;
if ( F_209 ( V_10 , V_65 ) )
F_12 ( V_65 , V_68 ) ;
break;
case V_137 :
break;
case V_461 :
default:
F_12 ( V_65 , V_68 ) ;
V_473 = ( V_10 -> V_343 . V_472 [ 1 ] & 0x00ff0000 ) >> 16 ;
V_59 = ( V_10 -> V_343 . V_472 [ 1 ] & 0x0000ff00 ) >> 8 ;
F_211 ( V_65 , L_75 ,
F_6 ( V_10 -> V_7 . V_36 , V_10 -> V_7 . error ) ,
V_10 -> V_7 . V_36 , V_10 -> V_7 . error ,
F_11 ( V_473 ) , V_473 ,
F_9 ( V_59 ) , V_59 , V_36 ) ;
break;
} ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_41 ( V_2 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_314 * V_10 = & V_2 -> V_7 . V_341 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_342 ;
V_10 -> V_297 . V_300 = sizeof( * V_10 ) - sizeof( V_10 -> V_343 ) - sizeof( V_10 -> V_7 ) ;
V_10 -> V_344 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 +
F_125 ( struct V_314 , V_7 ) ;
V_10 -> V_344 . V_208 = sizeof( V_10 -> V_7 ) ;
V_10 -> V_7 . V_282 = sizeof( V_10 -> V_343 . V_474 ) ;
V_10 -> V_7 . V_256 = sizeof( V_10 -> V_343 . V_472 ) ;
V_10 -> V_7 . V_8 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 +
F_125 ( struct V_314 , V_343 ) +
F_125 ( struct V_475 , V_474 ) ;
V_10 -> V_7 . V_8 . V_208 = sizeof( V_10 -> V_343 . V_474 ) ;
V_10 -> V_7 . V_38 . V_207 = ( T_2 ) V_2 -> V_18 . V_218 +
F_125 ( struct V_314 , V_343 ) +
F_125 ( struct V_475 , V_472 ) ;
V_10 -> V_7 . V_38 . V_208 = sizeof( V_10 -> V_343 . V_472 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_64 * V_65 = V_2 -> V_65 ;
F_202 ( V_65 , L_76 ) ;
V_4 -> V_476 -- ;
F_41 ( V_2 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void F_214 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
struct V_295 * V_296 ;
unsigned long V_39 ;
int V_47 ;
F_202 ( V_65 , L_77 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_476 >= V_463 ||
V_65 -> V_67 != V_465 ||
V_4 -> V_72 != V_88 ||
V_4 -> V_67 != V_87 ) {
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return;
}
V_4 -> V_476 ++ ;
F_60 ( & V_65 -> V_150 ) ;
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , F_213 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_296 = & V_2 -> V_7 . V_296 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_297 . V_298 = 1 ;
V_296 -> V_297 . V_32 = V_299 ;
V_296 -> V_297 . V_300 = sizeof( * V_296 ) ;
V_296 -> V_24 = V_65 -> V_24 ;
V_296 -> V_279 = V_65 -> V_279 ;
V_47 = F_109 ( V_2 , V_4 , V_304 ) ;
if ( V_47 ) {
F_207 ( V_65 , L_78 , V_47 ) ;
V_4 -> V_476 -- ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_54 ( V_4 ) ;
} else
F_202 ( V_65 , L_79 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_215 ( struct V_64 * V_65 )
{
struct V_314 * V_10 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_451 >= V_463 )
return;
F_60 ( & V_65 -> V_150 ) ;
V_2 = F_94 ( V_4 ) ;
V_4 -> V_451 ++ ;
F_97 ( V_2 , F_210 , V_31 ) ;
V_2 -> V_65 = V_65 ;
F_212 ( V_2 ) ;
V_10 = & V_2 -> V_7 . V_341 ;
V_10 -> V_7 . V_39 = V_327 ;
V_10 -> V_7 . V_24 = V_65 -> V_24 ;
V_10 -> V_7 . V_279 = V_65 -> V_279 ;
V_10 -> V_343 . V_474 [ 0 ] = V_477 ;
memcpy ( & V_10 -> V_343 . V_474 [ 2 ] , & V_4 -> V_152 -> V_153 . V_175 ,
sizeof( V_4 -> V_152 -> V_153 . V_175 ) ) ;
memcpy ( & V_10 -> V_343 . V_474 [ 4 ] , & V_4 -> V_152 -> V_153 . V_174 ,
sizeof( V_4 -> V_152 -> V_153 . V_174 ) ) ;
V_10 -> V_343 . V_474 [ 6 ] = V_4 -> V_152 -> V_153 . V_24 & 0x00ffffff ;
if ( F_216 ( & V_65 -> V_138 ) )
F_217 ( & V_65 -> V_138 , V_16 + ( V_478 * V_178 ) ) ;
else {
V_65 -> V_138 . V_41 = ( unsigned long ) V_65 ;
V_65 -> V_138 . V_249 = V_16 + ( V_478 * V_178 ) ;
V_65 -> V_138 . V_250 = ( void (*) ( unsigned long ) ) F_214 ;
F_112 ( & V_65 -> V_138 ) ;
}
F_12 ( V_65 , V_465 ) ;
if ( F_109 ( V_2 , V_4 , V_479 ) ) {
V_4 -> V_451 -- ;
F_50 ( & V_65 -> V_138 ) ;
F_12 ( V_65 , V_452 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
} else
F_202 ( V_65 , L_80 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_480 * V_38 = & V_2 -> V_33 -> V_481 ;
T_3 V_36 = V_38 -> V_297 . V_36 ;
int V_450 = V_235 ;
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
switch ( V_36 ) {
case V_360 :
F_202 ( V_65 , L_81 ) ;
V_65 -> V_469 = V_38 -> V_24 ;
if ( V_38 -> V_24 != V_65 -> V_24 )
F_198 ( V_65 , F_208 ) ;
else
F_198 ( V_65 , F_215 ) ;
break;
case V_137 :
break;
case V_252 :
F_199 ( V_65 , V_482 ) ;
break;
case V_461 :
default:
if ( ( V_38 -> V_36 & V_483 ) == V_483 &&
V_38 -> error == V_484 &&
V_38 -> V_59 == V_485 )
F_12 ( V_65 , V_68 ) ;
else if ( F_8 ( V_38 -> V_36 , V_38 -> error ) )
V_450 += F_199 ( V_65 , V_482 ) ;
else
F_12 ( V_65 , V_68 ) ;
F_203 ( V_65 , V_450 , L_82 ,
F_6 ( V_38 -> V_36 , V_38 -> error ) , V_38 -> V_36 , V_38 -> error ,
F_11 ( V_38 -> V_62 ) , V_38 -> V_62 ,
F_10 ( V_38 -> V_59 ) , V_38 -> V_59 , V_36 ) ;
break;
} ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_41 ( V_2 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void V_482 ( struct V_64 * V_65 )
{
struct V_480 * V_481 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_451 >= V_463 )
return;
F_60 ( & V_65 -> V_150 ) ;
V_2 = F_94 ( V_4 ) ;
V_4 -> V_451 ++ ;
V_2 -> V_65 = V_65 ;
F_97 ( V_2 , F_218 , V_31 ) ;
V_481 = & V_2 -> V_7 . V_481 ;
memset ( V_481 , 0 , sizeof( * V_481 ) ) ;
V_481 -> V_297 . V_298 = 1 ;
V_481 -> V_297 . V_32 = V_486 ;
V_481 -> V_297 . V_300 = sizeof( * V_481 ) ;
V_481 -> V_382 = V_65 -> V_173 . V_175 ;
F_12 ( V_65 , V_465 ) ;
if ( F_109 ( V_2 , V_4 , V_304 ) ) {
V_4 -> V_451 -- ;
F_12 ( V_65 , V_452 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
} else
F_202 ( V_65 , L_83 ) ;
}
static int F_219 ( struct V_3 * V_4 , T_2 V_24 )
{
struct V_64 * V_65 ;
unsigned long V_39 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_24 == V_24 ) {
if ( V_65 -> V_399 )
F_198 ( V_65 , F_208 ) ;
goto V_310;
}
}
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_65 = F_220 ( V_4 -> V_487 , V_488 ) ;
if ( ! V_65 ) {
F_21 ( V_4 -> V_98 , L_84 ,
V_24 ) ;
return - V_214 ;
}
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
V_65 -> V_24 = V_24 ;
V_65 -> V_469 = V_24 ;
V_65 -> V_4 = V_4 ;
V_65 -> V_399 = 1 ;
V_65 -> V_279 = V_4 -> V_415 ++ ;
F_111 ( & V_65 -> V_138 ) ;
F_221 ( & V_65 -> V_150 ) ;
F_198 ( V_65 , F_208 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( & V_65 -> V_130 , & V_4 -> V_489 ) ;
V_310:
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_222 ( struct V_3 * V_4 )
{
int V_44 , V_47 ;
for ( V_44 = 0 , V_47 = 0 ; ! V_47 && V_44 < V_4 -> V_490 ; V_44 ++ )
V_47 = F_219 ( V_4 ,
V_4 -> V_491 -> V_24 [ V_44 ] & V_492 ) ;
return V_47 ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_493 * V_38 = & V_2 -> V_33 -> V_494 ;
T_3 V_495 = V_38 -> V_297 . V_36 ;
int V_450 = V_235 ;
switch ( V_495 ) {
case V_360 :
F_26 ( V_4 , L_85 ) ;
V_4 -> V_490 = V_38 -> V_496 ;
F_14 ( V_4 , V_75 ) ;
break;
case V_461 :
V_450 += F_56 ( V_4 ) ;
F_64 ( V_4 , V_450 , L_86 ,
F_6 ( V_38 -> V_36 , V_38 -> error ) , V_38 -> V_36 , V_38 -> error ) ;
break;
case V_137 :
break;
default:
F_21 ( V_4 -> V_98 , L_87 , V_495 ) ;
F_18 ( V_4 , V_164 ) ;
break;
}
F_41 ( V_2 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void V_493 ( struct V_3 * V_4 )
{
struct V_493 * V_10 ;
struct V_1 * V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , F_223 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_494 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_497 ;
V_10 -> V_297 . V_300 = sizeof( * V_10 ) ;
V_10 -> V_498 = V_4 -> V_499 ;
V_10 -> V_500 . V_207 = V_4 -> V_501 ;
V_10 -> V_500 . V_208 = V_4 -> V_499 ;
F_14 ( V_4 , V_76 ) ;
if ( ! F_109 ( V_2 , V_4 , V_304 ) )
F_26 ( V_4 , L_88 ) ;
else
F_18 ( V_4 , V_164 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_495 = V_2 -> V_33 -> V_502 . V_297 . V_36 ;
struct V_503 * V_38 = & V_4 -> V_152 -> V_153 ;
unsigned int V_504 ;
int V_450 = V_235 ;
switch ( V_495 ) {
case V_360 :
F_41 ( V_2 ) ;
break;
case V_461 :
if ( F_8 ( V_38 -> V_36 , V_38 -> error ) )
V_450 += F_56 ( V_4 ) ;
else
F_18 ( V_4 , V_164 ) ;
F_64 ( V_4 , V_450 , L_89 ,
F_6 ( V_38 -> V_36 , V_38 -> error ) , V_38 -> V_36 , V_38 -> error ) ;
F_41 ( V_2 ) ;
return;
case V_252 :
F_56 ( V_4 ) ;
case V_137 :
F_41 ( V_2 ) ;
return;
default:
F_21 ( V_4 -> V_98 , L_90 , V_495 ) ;
F_18 ( V_4 , V_164 ) ;
F_41 ( V_2 ) ;
return;
}
V_4 -> V_199 = 0 ;
if ( ! ( V_38 -> V_39 & V_505 ) ) {
F_21 ( V_4 -> V_98 , L_91 ,
V_38 -> V_39 ) ;
F_18 ( V_4 , V_164 ) ;
F_17 ( & V_4 -> V_91 ) ;
return;
}
if ( V_38 -> V_201 <= V_203 ) {
F_21 ( V_4 -> V_98 , L_92 ,
V_38 -> V_201 ) ;
F_18 ( V_4 , V_164 ) ;
F_17 ( & V_4 -> V_91 ) ;
return;
}
V_4 -> V_117 = 1 ;
V_504 = F_225 ( ( V_506 ) ( V_38 -> V_190 >> 9 ) , V_191 ) ;
F_130 ( V_4 -> V_98 , L_93 ,
V_38 -> V_183 , V_38 -> V_210 , V_38 -> V_429 ,
V_38 -> V_212 , V_504 ) ;
F_226 ( V_4 -> V_89 ) = V_38 -> V_174 ;
F_227 ( V_4 -> V_89 ) = V_38 -> V_174 ;
F_228 ( V_4 -> V_89 ) = V_38 -> V_175 ;
F_229 ( V_4 -> V_89 ) = V_38 -> V_24 ;
F_230 ( V_4 -> V_89 ) = V_507 ;
F_231 ( V_4 -> V_89 ) = 0 ;
if ( V_38 -> V_453 . V_508 [ 0 ] & 0x80000000 )
F_231 ( V_4 -> V_89 ) |= V_509 ;
if ( V_38 -> V_453 . V_510 [ 0 ] & 0x80000000 )
F_231 ( V_4 -> V_89 ) |= V_511 ;
if ( V_38 -> V_453 . V_512 [ 0 ] & 0x80000000 )
F_231 ( V_4 -> V_89 ) |= V_513 ;
F_232 ( V_4 -> V_89 ) =
V_38 -> V_453 . V_297 . V_514 & 0x0fff ;
V_4 -> V_89 -> V_515 = V_38 -> V_201 - V_203 ;
V_4 -> V_89 -> V_516 = V_504 ;
F_14 ( V_4 , V_80 ) ;
F_17 ( & V_4 -> V_91 ) ;
}
static void V_104 ( struct V_3 * V_4 )
{
struct V_517 * V_10 ;
struct V_1 * V_2 = F_94 ( V_4 ) ;
F_80 ( V_4 ) ;
F_84 ( V_4 ) ;
F_97 ( V_2 , F_224 , V_31 ) ;
memcpy ( V_4 -> V_152 , & V_4 -> V_185 , sizeof( V_4 -> V_185 ) ) ;
V_10 = & V_2 -> V_7 . V_502 ;
memset ( V_10 , 0 , sizeof( struct V_517 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_518 ;
V_10 -> V_297 . V_300 = sizeof( struct V_517 ) ;
V_10 -> V_500 . V_207 = V_4 -> V_519 ;
V_10 -> V_500 . V_208 = sizeof( * V_4 -> V_152 ) ;
F_14 ( V_4 , V_76 ) ;
if ( ! F_109 ( V_2 , V_4 , V_304 ) )
F_26 ( V_4 , L_94 ) ;
else
F_18 ( V_4 , V_164 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_495 = V_2 -> V_33 -> V_520 . V_297 . V_36 ;
F_41 ( V_2 ) ;
switch ( V_495 ) {
case V_360 :
if ( F_95 ( & V_4 -> V_248 ) &&
V_4 -> V_67 == V_77 ) {
F_20 ( V_4 ) ;
return;
}
break;
case V_461 :
case V_521 :
case V_252 :
case V_137 :
default:
F_26 ( V_4 , L_95 , V_495 ) ;
break;
}
F_53 ( V_4 ) ;
}
static void V_141 ( struct V_3 * V_4 )
{
struct V_522 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_94 ( V_4 ) ;
F_97 ( V_2 , F_233 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_520 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_297 . V_298 = 1 ;
V_10 -> V_297 . V_32 = V_523 ;
V_10 -> V_297 . V_300 = sizeof( struct V_522 ) ;
F_14 ( V_4 , V_77 ) ;
if ( ! F_109 ( V_2 , V_4 , V_304 ) )
F_26 ( V_4 , L_96 ) ;
else
F_18 ( V_4 , V_164 ) ;
}
static int F_234 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_443 ||
V_65 -> V_67 == V_465 )
return 1 ;
}
return 0 ;
}
static int F_235 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
if ( F_236 () )
return 1 ;
switch ( V_4 -> V_67 ) {
case V_81 :
case V_76 :
case V_77 :
return 0 ;
case V_83 :
case V_87 :
if ( V_4 -> V_451 == V_463 )
return 0 ;
F_19 (tgt, &vhost->targets, queue)
if ( V_65 -> V_67 == V_443 )
return 1 ;
F_19 (tgt, &vhost->targets, queue)
if ( V_65 -> V_67 == V_465 )
return 0 ;
return 1 ;
case V_78 :
case V_79 :
case V_75 :
case V_84 :
case V_82 :
case V_80 :
case V_85 :
case V_86 :
default:
break;
} ;
return 1 ;
}
static int F_237 ( struct V_3 * V_4 )
{
unsigned long V_39 ;
int V_47 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_235 ( V_4 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_47 ;
}
static void F_238 ( struct V_3 * V_4 , int V_128 )
{
if ( V_128 & V_393 )
F_239 ( V_4 -> V_89 , F_240 () , V_524 , 0 ) ;
if ( ( V_128 & V_94 ) &&
V_4 -> V_72 >= V_166 )
F_239 ( V_4 -> V_89 , F_240 () , V_525 , 0 ) ;
if ( ( V_128 & V_389 ) &&
V_4 -> V_72 == V_88 )
F_239 ( V_4 -> V_89 , F_240 () , V_526 , 0 ) ;
}
static void F_241 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_169 * V_170 ;
unsigned long V_39 ;
F_202 ( V_65 , L_97 ) ;
V_170 = F_242 ( V_4 -> V_89 , 0 , & V_65 -> V_173 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_170 && V_65 -> V_67 == V_68 ) {
F_202 ( V_65 , L_98 ) ;
F_49 ( & V_65 -> V_130 ) ;
F_12 ( V_65 , V_69 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_243 ( V_170 ) ;
F_244 ( & V_65 -> V_138 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
return;
} else if ( V_170 && V_65 -> V_67 == V_69 ) {
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return;
}
if ( V_170 ) {
F_202 ( V_65 , L_99 ) ;
V_65 -> V_170 = V_170 ;
V_170 -> V_527 = V_65 -> V_453 . V_297 . V_514 & 0x0fff ;
V_170 -> V_528 = 0 ;
V_65 -> V_148 = V_170 -> V_529 ;
if ( V_65 -> V_453 . V_508 [ 0 ] & 0x80000000 )
V_170 -> V_528 |= V_509 ;
if ( V_65 -> V_453 . V_510 [ 0 ] & 0x80000000 )
V_170 -> V_528 |= V_511 ;
if ( V_65 -> V_453 . V_512 [ 0 ] & 0x80000000 )
V_170 -> V_528 |= V_513 ;
if ( V_170 -> V_530 )
F_245 ( V_170 -> V_530 , 1 ) ;
} else
F_202 ( V_65 , L_100 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_246 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
unsigned long V_39 ;
struct V_169 * V_170 ;
int V_47 ;
F_238 ( V_4 , V_4 -> V_93 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_4 -> V_93 = 0 ;
switch ( V_4 -> V_67 ) {
case V_81 :
case V_77 :
case V_76 :
break;
case V_85 :
V_4 -> V_67 = V_84 ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_36 ( V_4 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 == V_124 )
F_197 ( F_23 ( V_4 -> V_98 ) ) ;
if ( V_47 || ( V_47 = F_25 ( V_4 ) ) ||
( V_47 = F_197 ( F_23 ( V_4 -> V_98 ) ) ) ) {
F_18 ( V_4 , V_164 ) ;
F_21 ( V_4 -> V_98 , L_101 , V_47 ) ;
}
break;
case V_86 :
V_4 -> V_67 = V_84 ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_35 ( V_4 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 || ( V_47 = F_25 ( V_4 ) ) ) {
F_18 ( V_4 , V_164 ) ;
F_21 ( V_4 -> V_98 , L_102 , V_47 ) ;
}
break;
case V_78 :
V_4 -> V_103 ( V_4 ) ;
break;
case V_79 :
F_42 ( V_4 -> V_72 != V_88 ) ;
if ( V_4 -> V_142 ) {
V_4 -> V_142 = 0 ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_247 ( 15 ) ;
return;
} else
V_4 -> V_103 ( V_4 ) ;
break;
case V_80 :
F_19 (tgt, &vhost->targets, queue)
F_198 ( V_65 , V_482 ) ;
F_14 ( V_4 , V_87 ) ;
break;
case V_87 :
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_443 ) {
V_65 -> V_103 ( V_65 ) ;
break;
}
}
if ( ! F_234 ( V_4 ) )
F_14 ( V_4 , V_84 ) ;
break;
case V_84 :
case V_82 :
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_68 ) {
F_202 ( V_65 , L_98 ) ;
V_170 = V_65 -> V_170 ;
V_65 -> V_170 = NULL ;
F_49 ( & V_65 -> V_130 ) ;
F_12 ( V_65 , V_69 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_170 )
F_243 ( V_170 ) ;
F_244 ( & V_65 -> V_138 ) ;
F_73 ( & V_65 -> V_150 , F_68 ) ;
return;
}
}
if ( V_4 -> V_72 == V_88 ) {
if ( V_4 -> V_67 == V_82 ) {
if ( V_4 -> V_90 ) {
V_4 -> V_90 = 0 ;
F_16 ( V_4 -> V_89 ) ;
F_14 ( V_4 , V_80 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
} else {
F_13 ( V_4 , V_151 ) ;
F_14 ( V_4 , V_81 ) ;
F_17 ( & V_4 -> V_176 ) ;
F_248 ( & V_4 -> V_531 ) ;
V_4 -> V_96 = 0 ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_249 ( V_4 -> V_89 ) ;
}
return;
} else {
F_14 ( V_4 , V_79 ) ;
V_4 -> V_103 = V_493 ;
}
} else {
F_14 ( V_4 , V_81 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_249 ( V_4 -> V_89 ) ;
F_17 ( & V_4 -> V_176 ) ;
return;
}
break;
case V_75 :
F_14 ( V_4 , V_83 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_222 ( V_4 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
break;
case V_83 :
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_443 ) {
V_65 -> V_103 ( V_65 ) ;
break;
}
}
if ( ! F_234 ( V_4 ) )
F_14 ( V_4 , V_82 ) ;
break;
default:
break;
} ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static int F_250 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
int V_47 ;
F_251 ( V_532 , - 20 ) ;
while ( 1 ) {
V_47 = F_252 ( V_4 -> V_91 ,
F_237 ( V_4 ) ) ;
F_42 ( V_47 ) ;
if ( F_236 () )
break;
F_246 ( V_4 ) ;
}
F_26 ( V_4 , L_103 ) ;
return 0 ;
}
static int F_253 ( struct V_3 * V_4 )
{
int V_47 , V_533 = - V_214 ;
struct V_231 * V_98 = V_4 -> V_98 ;
struct V_107 * V_108 = F_23 ( V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
V_92 ;
V_18 -> V_100 = (struct V_405 * ) F_254 ( V_213 ) ;
if ( ! V_18 -> V_100 )
return - V_214 ;
V_18 -> V_129 = V_101 / sizeof( * V_18 -> V_100 ) ;
V_18 -> V_118 = F_255 ( V_98 , V_18 -> V_100 ,
V_101 , V_119 ) ;
if ( F_256 ( V_98 , V_18 -> V_118 ) )
goto V_534;
V_533 = V_47 = F_24 ( V_123 , V_108 -> V_110 ,
V_18 -> V_118 , V_101 ) ;
if ( V_47 == V_535 )
V_533 = V_47 = F_36 ( V_4 ) ;
if ( V_47 == V_124 )
F_38 ( V_98 , L_6 ) ;
else if ( V_47 ) {
F_38 ( V_98 , L_104 , V_47 ) ;
goto V_536;
}
V_533 = 0 ;
F_257 ( & V_4 -> V_113 , ( void * ) F_195 , ( unsigned long ) V_4 ) ;
if ( ( V_47 = F_258 ( V_108 -> V_112 , F_192 , 0 , V_537 , V_4 ) ) ) {
F_21 ( V_98 , L_105 , V_108 -> V_112 , V_47 ) ;
goto V_538;
}
if ( ( V_47 = F_197 ( V_108 ) ) ) {
F_21 ( V_98 , L_106 , V_47 ) ;
goto V_538;
}
V_18 -> V_102 = 0 ;
V_95 ;
return V_533 ;
V_538:
F_30 ( & V_4 -> V_113 ) ;
do {
V_47 = F_24 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_32 ( V_47 ) );
V_536:
F_33 ( V_98 , V_18 -> V_118 , V_101 , V_119 ) ;
V_534:
F_34 ( ( unsigned long ) V_18 -> V_100 ) ;
return V_533 ;
}
static void F_259 ( struct V_3 * V_4 )
{
struct V_440 * V_539 = & V_4 -> V_99 ;
V_92 ;
F_260 ( V_4 -> V_487 ) ;
F_70 ( V_4 -> V_14 ) ;
F_93 ( V_4 -> V_98 , V_4 -> V_499 , V_4 -> V_491 ,
V_4 -> V_501 ) ;
F_93 ( V_4 -> V_98 , sizeof( * V_4 -> V_152 ) ,
V_4 -> V_152 , V_4 -> V_519 ) ;
F_261 ( V_4 -> V_220 ) ;
F_33 ( V_4 -> V_98 , V_539 -> V_118 ,
V_539 -> V_129 * sizeof( * V_539 -> V_100 ) , V_119 ) ;
F_34 ( ( unsigned long ) V_539 -> V_100 ) ;
V_95 ;
}
static int F_262 ( struct V_3 * V_4 )
{
struct V_440 * V_539 = & V_4 -> V_99 ;
struct V_231 * V_98 = V_4 -> V_98 ;
V_92 ;
V_539 -> V_100 = (struct V_380 * ) F_254 ( V_213 ) ;
if ( ! V_539 -> V_100 ) {
F_21 ( V_98 , L_107 ) ;
goto V_540;
}
V_539 -> V_129 = V_101 / sizeof( struct V_380 ) ;
V_539 -> V_118 = F_255 ( V_98 , V_539 -> V_100 ,
V_539 -> V_129 * sizeof( * V_539 -> V_100 ) ,
V_119 ) ;
if ( F_256 ( V_98 , V_539 -> V_118 ) ) {
F_21 ( V_98 , L_108 ) ;
goto V_541;
}
V_4 -> V_220 = F_263 ( V_537 , V_98 ,
V_542 * sizeof( struct V_226 ) ,
sizeof( struct V_226 ) , 0 ) ;
if ( ! V_4 -> V_220 ) {
F_21 ( V_98 , L_109 ) ;
goto V_543;
}
V_4 -> V_152 = F_88 ( V_98 , sizeof( * V_4 -> V_152 ) ,
& V_4 -> V_519 , V_213 ) ;
if ( ! V_4 -> V_152 ) {
F_21 ( V_98 , L_110 ) ;
goto V_544;
}
V_4 -> V_499 = sizeof( V_4 -> V_491 -> V_24 [ 0 ] ) * V_545 ;
V_4 -> V_491 = F_88 ( V_98 , V_4 -> V_499 ,
& V_4 -> V_501 , V_213 ) ;
if ( ! V_4 -> V_491 ) {
F_21 ( V_98 , L_111 ) ;
goto V_546;
}
V_4 -> V_14 = F_87 ( V_547 ,
sizeof( struct V_12 ) , V_213 ) ;
if ( ! V_4 -> V_14 )
goto V_548;
V_4 -> V_487 = F_264 ( V_549 ,
sizeof( struct V_64 ) ) ;
if ( ! V_4 -> V_487 ) {
F_21 ( V_98 , L_112 ) ;
goto V_550;
}
V_95 ;
return 0 ;
V_550:
F_70 ( V_4 -> V_14 ) ;
V_548:
F_93 ( V_98 , V_4 -> V_499 , V_4 -> V_491 ,
V_4 -> V_501 ) ;
V_546:
F_93 ( V_98 , sizeof( * V_4 -> V_152 ) ,
V_4 -> V_152 , V_4 -> V_519 ) ;
V_544:
F_261 ( V_4 -> V_220 ) ;
V_543:
F_33 ( V_98 , V_539 -> V_118 ,
V_539 -> V_129 * sizeof( * V_539 -> V_100 ) , V_119 ) ;
V_541:
F_34 ( ( unsigned long ) V_539 -> V_100 ) ;
V_540:
V_95 ;
return - V_214 ;
}
static void F_265 ( struct V_551 * V_552 )
{
struct V_3 * V_4 = F_69 ( V_552 , struct V_3 ,
V_531 ) ;
struct V_64 * V_65 ;
struct V_169 * V_170 ;
unsigned long V_39 ;
int V_553 ;
V_92 ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
do {
V_553 = 0 ;
if ( V_4 -> V_72 != V_151 )
break;
F_19 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_70 ) {
V_553 = 1 ;
V_65 -> V_70 = 0 ;
F_60 ( & V_65 -> V_150 ) ;
V_170 = V_65 -> V_170 ;
if ( ! V_170 ) {
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_241 ( V_65 ) ;
} else if ( F_266 ( & V_170 -> V_98 ) ) {
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_202 ( V_65 , L_113 ) ;
F_267 ( V_170 , V_65 -> V_173 . V_455 ) ;
F_268 ( & V_170 -> V_98 ) ;
}
F_73 ( & V_65 -> V_150 , F_68 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
break;
}
}
} while( V_553 );
if ( V_4 -> V_72 == V_151 )
V_4 -> V_413 = 1 ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
}
static int F_269 ( struct V_107 * V_108 , const struct V_554 * V_149 )
{
struct V_3 * V_4 ;
struct V_145 * V_146 ;
struct V_231 * V_98 = & V_108 -> V_98 ;
int V_47 = - V_214 ;
V_92 ;
V_146 = F_270 ( & V_555 , sizeof( * V_4 ) ) ;
if ( ! V_146 ) {
F_21 ( V_98 , L_114 ) ;
goto V_340;
}
V_146 -> V_556 = V_557 ;
V_146 -> V_515 = V_202 ;
V_146 -> V_558 = V_558 ;
V_146 -> V_559 = V_545 ;
V_146 -> V_516 = V_191 ;
V_146 -> V_560 = V_561 ;
V_146 -> V_562 = V_146 -> V_563 ;
V_4 = F_59 ( V_146 ) ;
F_271 ( & V_4 -> V_248 ) ;
F_271 ( & V_4 -> free ) ;
F_271 ( & V_4 -> V_489 ) ;
sprintf ( V_4 -> V_48 , V_537 ) ;
V_4 -> V_89 = V_146 ;
V_4 -> V_98 = V_98 ;
V_4 -> V_184 = - 1 ;
V_4 -> V_234 = V_234 ;
V_4 -> V_415 = 1 ;
strcpy ( V_4 -> V_183 , L_115 ) ;
F_272 ( & V_4 -> V_91 ) ;
F_272 ( & V_4 -> V_176 ) ;
F_273 ( & V_4 -> V_531 , F_265 ) ;
F_274 ( & V_4 -> V_333 ) ;
if ( ( V_47 = F_262 ( V_4 ) ) )
goto V_564;
V_4 -> V_565 = F_275 ( F_250 , V_4 , L_116 , V_537 ,
V_146 -> V_563 ) ;
if ( F_276 ( V_4 -> V_565 ) ) {
F_21 ( V_98 , L_117 ,
F_277 ( V_4 -> V_565 ) ) ;
goto V_566;
}
if ( ( V_47 = F_253 ( V_4 ) ) ) {
F_21 ( V_98 , L_118 , V_47 ) ;
goto V_567;
}
if ( ( V_47 = F_86 ( V_4 ) ) ) {
F_21 ( V_98 , L_119 , V_47 ) ;
goto V_568;
}
if ( ( V_47 = F_278 ( V_146 , V_98 ) ) )
goto V_569;
F_279 ( V_146 ) = V_570 ;
if ( ( V_47 = F_280 ( & V_146 -> V_571 . V_434 ,
& V_572 ) ) ) {
F_21 ( V_98 , L_120 , V_47 ) ;
goto V_573;
}
if ( F_281 ( V_146 ) -> V_530 )
F_245 ( F_281 ( V_146 ) -> V_530 , 1 ) ;
F_282 ( V_98 , V_4 ) ;
F_283 ( & V_574 ) ;
F_44 ( & V_4 -> V_130 , & V_575 ) ;
F_284 ( & V_574 ) ;
F_25 ( V_4 ) ;
F_285 ( V_146 ) ;
return 0 ;
V_573:
F_286 ( V_146 ) ;
V_569:
F_90 ( V_4 ) ;
V_568:
F_28 ( V_4 ) ;
V_567:
F_287 ( V_4 -> V_565 ) ;
V_566:
F_259 ( V_4 ) ;
V_564:
F_288 ( V_146 ) ;
V_340:
V_95 ;
return V_47 ;
}
static int F_289 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = F_103 ( & V_108 -> V_98 ) ;
unsigned long V_39 ;
V_92 ;
F_290 ( & V_4 -> V_89 -> V_571 . V_434 , & V_572 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_18 ( V_4 , V_73 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_77 ( V_4 ) ;
F_28 ( V_4 ) ;
F_287 ( V_4 -> V_565 ) ;
F_291 ( V_4 -> V_89 ) ;
F_286 ( V_4 -> V_89 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_51 ( V_4 , V_55 ) ;
F_90 ( V_4 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_259 ( V_4 ) ;
F_283 ( & V_574 ) ;
F_49 ( & V_4 -> V_130 ) ;
F_284 ( & V_574 ) ;
F_288 ( V_4 -> V_89 ) ;
V_95 ;
return 0 ;
}
static int F_292 ( struct V_231 * V_98 )
{
unsigned long V_39 ;
struct V_3 * V_4 = F_103 ( V_98 ) ;
struct V_107 * V_108 = F_23 ( V_98 ) ;
F_37 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_193 ( V_108 ) ;
F_194 ( & V_4 -> V_113 ) ;
F_39 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
static unsigned long F_293 ( struct V_107 * V_108 )
{
unsigned long V_576 = V_202 * sizeof( union V_307 ) ;
return V_576 + ( ( 512 * 1024 ) * V_555 . V_577 ) ;
}
static int T_9 F_294 ( void )
{
int V_47 ;
if ( ! F_295 ( V_578 ) )
return - V_579 ;
F_296 (KERN_INFO IBMVFC_NAMEL_121 ,
IBMVFC_DRIVER_VERSION, IBMVFC_DRIVER_DATE) ;
V_557 = F_297 ( & V_580 ) ;
if ( ! V_557 )
return - V_214 ;
V_47 = F_298 ( & V_581 ) ;
if ( V_47 )
F_299 ( V_557 ) ;
return V_47 ;
}
static void T_10 F_300 ( void )
{
F_301 ( & V_581 ) ;
F_299 ( V_557 ) ;
}
