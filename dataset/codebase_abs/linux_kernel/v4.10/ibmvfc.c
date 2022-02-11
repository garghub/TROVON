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
V_13 -> V_24 = F_2 ( V_6 -> V_25 ) ;
V_13 -> V_26 = F_3 ( & V_6 -> V_7 . V_26 ) ;
V_13 -> V_27 = V_6 -> V_7 . V_27 ;
V_13 -> V_28 . V_29 . V_30 = F_4 ( V_6 -> V_7 . V_30 ) ;
break;
case V_31 :
V_13 -> V_22 = F_4 ( V_10 -> V_32 ) ;
break;
default:
break;
} ;
}
static void F_5 ( struct V_1 * V_2 )
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
V_13 -> V_24 = F_2 ( V_6 -> V_25 ) ;
V_13 -> V_26 = F_3 ( & V_6 -> V_7 . V_26 ) ;
V_13 -> V_27 = V_6 -> V_7 . V_27 ;
V_13 -> V_28 . V_35 . V_36 = F_6 ( V_6 -> V_36 ) ;
V_13 -> V_28 . V_35 . error = F_6 ( V_6 -> error ) ;
V_13 -> V_28 . V_35 . V_37 = V_6 -> V_38 . V_39 ;
V_13 -> V_28 . V_35 . V_40 = V_6 -> V_38 . V_41 . V_42 . V_40 ;
V_13 -> V_28 . V_35 . V_43 = V_6 -> V_38 . V_43 ;
break;
case V_31 :
V_13 -> V_22 = F_4 ( V_10 -> V_32 ) ;
V_13 -> V_28 . V_35 . V_36 = F_6 ( V_10 -> V_36 ) ;
break;
default:
break;
} ;
}
static int F_7 ( T_1 V_36 , T_1 error )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_45 ) ; V_44 ++ )
if ( ( V_45 [ V_44 ] . V_36 & V_36 ) == V_45 [ V_44 ] . V_36 &&
V_45 [ V_44 ] . error == error )
return V_44 ;
return - V_46 ;
}
static const char * F_9 ( T_1 V_36 , T_1 error )
{
int V_47 = F_7 ( V_36 , error ) ;
if ( V_47 >= 0 )
return V_45 [ V_47 ] . V_48 ;
return V_49 ;
}
static int F_10 ( struct V_5 * V_6 )
{
int V_50 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
int V_52 = F_4 ( V_38 -> V_53 ) ;
if ( ( V_38 -> V_39 & V_54 ) &&
( ( V_52 && V_52 != 4 && V_52 != 8 ) ||
V_38 -> V_41 . V_42 . V_40 ) )
return V_55 << 16 ;
V_50 = F_7 ( F_6 ( V_6 -> V_36 ) , F_6 ( V_6 -> error ) ) ;
if ( V_50 >= 0 )
return V_38 -> V_43 | ( V_45 [ V_50 ] . V_56 << 16 ) ;
return V_38 -> V_43 | ( V_55 << 16 ) ;
}
static int F_11 ( T_1 V_36 , T_1 error )
{
int V_47 = F_7 ( V_36 , error ) ;
if ( V_47 >= 0 )
return V_45 [ V_47 ] . V_57 ;
return 1 ;
}
static const char * F_12 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_58 ) ; V_44 ++ )
if ( V_58 [ V_44 ] . V_59 == V_36 )
return V_58 [ V_44 ] . V_48 ;
return V_60 ;
}
static const char * F_13 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_61 ) ; V_44 ++ )
if ( V_61 [ V_44 ] . V_59 == V_36 )
return V_61 [ V_44 ] . V_48 ;
return V_60 ;
}
static const char * F_14 ( T_1 V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_62 ) ; V_44 ++ )
if ( V_62 [ V_44 ] . V_62 == V_36 )
return V_62 [ V_44 ] . V_48 ;
return V_63 ;
}
static void F_15 ( struct V_64 * V_65 ,
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
static int F_16 ( struct V_3 * V_4 ,
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
static void F_17 ( struct V_3 * V_4 ,
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
static void F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 == V_81 ) {
if ( ! F_16 ( V_4 , V_88 ) ) {
F_19 ( V_4 -> V_89 ) ;
F_17 ( V_4 , V_80 ) ;
}
} else
V_4 -> V_90 = 1 ;
F_20 ( & V_4 -> V_91 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
enum V_71 V_72 )
{
struct V_64 * V_65 ;
V_92 ;
F_19 ( V_4 -> V_89 ) ;
F_22 (tgt, &vhost->targets, queue)
F_15 ( V_65 , V_68 ) ;
F_16 ( V_4 , V_72 ) ;
F_17 ( V_4 , V_84 ) ;
V_4 -> V_93 |= V_94 ;
F_20 ( & V_4 -> V_91 ) ;
V_95 ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
if ( V_4 -> V_67 == V_76 ) {
if ( ++ V_4 -> V_96 > V_97 ) {
F_24 ( V_4 -> V_98 ,
L_1 ) ;
F_21 ( V_4 , V_73 ) ;
return;
}
}
if ( ! F_16 ( V_4 , V_88 ) ) {
memset ( V_4 -> V_99 . V_100 , 0 , V_101 ) ;
V_4 -> V_99 . V_102 = 0 ;
F_22 (tgt, &vhost->targets, queue)
F_15 ( V_65 , V_68 ) ;
F_19 ( V_4 -> V_89 ) ;
F_17 ( V_4 , V_79 ) ;
V_4 -> V_103 = V_104 ;
F_20 ( & V_4 -> V_91 ) ;
}
}
static int F_25 ( struct V_3 * V_4 , T_2 V_105 , T_2 V_106 )
{
struct V_107 * V_108 = F_26 ( V_4 -> V_98 ) ;
return F_27 ( V_109 , V_108 -> V_110 , V_105 , V_106 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
F_29 ( V_4 , L_2 ) ;
return F_25 ( V_4 , 0xC001000000000000LL , 0 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
F_29 ( V_4 , L_3 ) ;
return F_25 ( V_4 , 0xC002000000000000LL , 0 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
long V_47 = 0 ;
struct V_107 * V_108 = F_26 ( V_4 -> V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
F_29 ( V_4 , L_4 ) ;
F_32 ( V_108 -> V_112 , V_4 ) ;
F_33 ( & V_4 -> V_113 ) ;
do {
if ( V_47 )
F_34 ( 100 ) ;
V_47 = F_27 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_35 ( V_47 ) );
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
F_36 ( V_4 -> V_98 , V_18 -> V_118 , V_101 , V_119 ) ;
F_37 ( ( unsigned long ) V_18 -> V_100 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
int V_47 = 0 ;
struct V_107 * V_108 = F_26 ( V_4 -> V_98 ) ;
do {
if ( V_47 )
F_34 ( 100 ) ;
V_47 = F_27 ( V_120 , V_108 -> V_110 ) ;
} while ( V_47 == V_121 || V_47 == V_115 || F_35 ( V_47 ) );
if ( V_47 )
F_24 ( V_4 -> V_98 , L_5 , V_47 ) ;
return V_47 ;
}
static int F_39 ( struct V_3 * V_4 )
{
int V_47 = 0 ;
unsigned long V_39 ;
struct V_107 * V_108 = F_26 ( V_4 -> V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
do {
if ( V_47 )
F_34 ( 100 ) ;
V_47 = F_27 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_35 ( V_47 ) );
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
memset ( V_18 -> V_100 , 0 , V_101 ) ;
V_18 -> V_102 = 0 ;
V_47 = F_27 ( V_123 , V_108 -> V_110 ,
V_18 -> V_118 , V_101 ) ;
if ( V_47 == V_124 )
F_41 ( V_4 -> V_98 , L_6 ) ;
else if ( V_47 != 0 )
F_41 ( V_4 -> V_98 , L_7 , V_47 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_47 ;
}
static int F_43 ( struct V_125 * V_126 ,
struct V_1 * V_2 )
{
int V_127 = V_2 - V_126 -> V_128 ;
if ( V_127 < 0 || V_127 >= V_126 -> V_129 )
return 0 ;
if ( V_2 != V_126 -> V_128 + V_127 )
return 0 ;
return 1 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
F_45 ( ! F_43 ( V_126 , V_2 ) ) ;
F_45 ( F_46 ( & V_2 -> free ) != 1 ) ;
F_47 ( & V_2 -> V_130 , & V_4 -> free ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = V_2 -> V_132 ;
if ( V_132 ) {
F_49 ( V_132 ) ;
V_132 -> V_133 ( V_132 ) ;
}
if ( V_2 -> V_134 )
F_50 ( V_2 -> V_134 ) ;
F_44 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_135 )
{
if ( V_2 -> V_132 ) {
V_2 -> V_132 -> V_56 = ( V_135 << 16 ) ;
V_2 -> V_136 = F_48 ;
} else
V_2 -> V_33 -> V_11 . V_36 = F_52 ( V_137 ) ;
F_53 ( & V_2 -> V_130 ) ;
F_54 ( & V_2 -> V_138 ) ;
F_5 ( V_2 ) ;
V_2 -> V_136 ( V_2 ) ;
}
static void F_55 ( struct V_3 * V_4 , int V_135 )
{
struct V_1 * V_2 , * V_139 ;
F_29 ( V_4 , L_8 ) ;
F_56 (evt, pos, &vhost->sent, queue)
F_51 ( V_2 , V_135 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_55 ( V_4 , V_55 ) ;
F_21 ( V_4 , V_140 ) ;
F_17 ( V_4 , V_85 ) ;
}
static void F_58 ( struct V_3 * V_4 )
{
if ( V_4 -> V_117 && V_4 -> V_67 != V_77 &&
! F_16 ( V_4 , V_88 ) ) {
F_19 ( V_4 -> V_89 ) ;
F_17 ( V_4 , V_78 ) ;
V_4 -> V_103 = V_141 ;
F_20 ( & V_4 -> V_91 ) ;
} else
F_57 ( V_4 ) ;
}
static void F_59 ( struct V_3 * V_4 )
{
unsigned long V_39 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_58 ( V_4 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
int V_57 = 0 ;
if ( V_4 -> V_67 == V_76 ) {
V_4 -> V_142 = 1 ;
if ( ++ V_4 -> V_96 > V_97 ) {
F_24 ( V_4 -> V_98 ,
L_1 ) ;
F_21 ( V_4 , V_73 ) ;
} else if ( V_4 -> V_96 == V_97 )
F_58 ( V_4 ) ;
else {
F_17 ( V_4 , V_79 ) ;
V_57 = 1 ;
}
}
F_20 ( & V_4 -> V_91 ) ;
return V_57 ;
}
static struct V_64 * F_61 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_62 ( V_144 -> V_98 . V_147 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
struct V_64 * V_65 ;
F_22 (tgt, &vhost->targets, queue)
if ( V_65 -> V_148 == V_144 -> V_149 ) {
F_64 ( & V_65 -> V_150 ) ;
return V_65 ;
}
return NULL ;
}
static struct V_64 * F_65 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_62 ( V_144 -> V_98 . V_147 ) ;
struct V_64 * V_65 ;
unsigned long V_39 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
V_65 = F_61 ( V_144 ) ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return V_65 ;
}
static void F_66 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
if ( V_4 -> V_72 == V_151 ) {
switch ( F_2 ( V_4 -> V_152 -> V_153 . V_154 ) / 100 ) {
case 1 :
F_67 ( V_146 ) = V_155 ;
break;
case 2 :
F_67 ( V_146 ) = V_156 ;
break;
case 4 :
F_67 ( V_146 ) = V_157 ;
break;
case 8 :
F_67 ( V_146 ) = V_158 ;
break;
case 10 :
F_67 ( V_146 ) = V_159 ;
break;
case 16 :
F_67 ( V_146 ) = V_160 ;
break;
default:
F_68 ( V_4 , 3 , L_9 ,
F_2 ( V_4 -> V_152 -> V_153 . V_154 ) / 100 ) ;
F_67 ( V_146 ) = V_161 ;
break;
}
} else
F_67 ( V_146 ) = V_161 ;
F_42 ( V_146 -> V_122 , V_39 ) ;
}
static void F_69 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
switch ( V_4 -> V_72 ) {
case V_88 :
case V_151 :
F_70 ( V_146 ) = V_162 ;
break;
case V_140 :
F_70 ( V_146 ) = V_163 ;
break;
case V_164 :
case V_73 :
F_70 ( V_146 ) = V_165 ;
break;
case V_166 :
F_70 ( V_146 ) = V_167 ;
break;
case V_116 :
F_70 ( V_146 ) = V_168 ;
break;
default:
F_68 ( V_4 , 3 , L_10 , V_4 -> V_72 ) ;
F_70 ( V_146 ) = V_168 ;
break;
}
F_42 ( V_146 -> V_122 , V_39 ) ;
}
static void F_71 ( struct V_169 * V_170 , T_3 V_171 )
{
if ( V_171 )
V_170 -> V_172 = V_171 ;
else
V_170 -> V_172 = 1 ;
}
static void F_72 ( struct V_150 * V_150 )
{
struct V_64 * V_65 = F_73 ( V_150 , struct V_64 , V_150 ) ;
F_74 ( V_65 ) ;
}
static void F_75 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_65 ( V_144 ) ;
F_76 ( V_144 ) = V_65 ? V_65 -> V_173 . V_174 : 0 ;
if ( V_65 )
F_77 ( & V_65 -> V_150 , F_72 ) ;
}
static void F_78 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_65 ( V_144 ) ;
F_76 ( V_144 ) = V_65 ? V_65 -> V_173 . V_175 : 0 ;
if ( V_65 )
F_77 ( & V_65 -> V_150 , F_72 ) ;
}
static void F_79 ( struct V_143 * V_144 )
{
struct V_64 * V_65 = F_65 ( V_144 ) ;
F_80 ( V_144 ) = V_65 ? V_65 -> V_24 : - 1 ;
if ( V_65 )
F_77 ( & V_65 -> V_150 , F_72 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
long V_171 = F_82 ( V_4 -> V_176 ,
( ( V_4 -> V_72 == V_151 ||
V_4 -> V_72 == V_73 ||
V_4 -> V_72 == V_164 ) &&
V_4 -> V_67 == V_81 ) ,
( V_177 * V_178 ) ) ;
return V_171 ? 0 : - V_179 ;
}
static int F_83 ( struct V_145 * V_146 )
{
struct V_3 * V_4 = F_63 ( V_146 ) ;
F_24 ( V_4 -> V_98 , L_11 ) ;
F_59 ( V_4 ) ;
return F_81 ( V_4 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_180 * V_181 ;
const char * V_48 ;
const unsigned int * V_182 ;
V_181 = F_85 ( L_12 ) ;
if ( ! V_181 )
return;
V_48 = F_86 ( V_181 , L_13 , NULL ) ;
if ( V_48 )
strncpy ( V_4 -> V_183 , V_48 , sizeof( V_4 -> V_183 ) ) ;
V_182 = F_86 ( V_181 , L_14 , NULL ) ;
if ( V_182 )
V_4 -> V_184 = * V_182 ;
F_87 ( V_181 ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_104 * V_185 = & V_4 -> V_185 ;
struct V_180 * V_186 = V_4 -> V_98 -> V_186 ;
const char * V_187 ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
V_185 -> V_188 = F_89 ( V_189 ) ;
V_185 -> V_190 = F_90 ( V_191 << 9 ) ;
V_185 -> V_192 = F_89 ( sizeof( struct V_193 ) ) ;
V_185 -> V_194 = F_89 ( sizeof( struct V_51 ) ) ;
V_185 -> V_195 = F_89 ( V_4 -> V_184 ) ;
V_185 -> V_196 = F_89 ( 1 ) ;
V_185 -> V_197 = F_52 ( 3 ) ;
V_185 -> V_39 = F_52 ( V_198 ) ;
if ( V_4 -> V_199 )
V_185 -> V_39 |= F_52 ( V_200 ) ;
V_185 -> V_201 = F_89 ( V_202 + V_203 ) ;
V_185 -> V_204 = F_90 ( V_205 ) ;
V_185 -> V_206 . V_207 = F_90 ( V_4 -> V_99 . V_118 ) ;
V_185 -> V_206 . V_208 = F_89 ( V_4 -> V_99 . V_129 * sizeof( * V_4 -> V_99 . V_100 ) ) ;
strncpy ( V_185 -> V_183 , V_4 -> V_183 , V_209 ) ;
strncpy ( V_185 -> V_210 ,
F_91 ( & V_4 -> V_89 -> V_211 ) , V_209 ) ;
V_187 = F_86 ( V_186 , L_15 , NULL ) ;
V_187 = V_187 ? V_187 : F_91 ( V_4 -> V_98 ) ;
strncpy ( V_185 -> V_212 , V_187 , V_209 ) ;
}
static int F_92 ( struct V_3 * V_4 )
{
int V_44 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
V_92 ;
V_126 -> V_129 = V_202 + V_203 ;
V_126 -> V_128 = F_93 ( V_126 -> V_129 , sizeof( * V_126 -> V_128 ) , V_213 ) ;
if ( ! V_126 -> V_128 )
return - V_214 ;
V_126 -> V_215 = F_94 ( V_4 -> V_98 ,
V_126 -> V_129 * sizeof( * V_126 -> V_215 ) ,
& V_126 -> V_216 , 0 ) ;
if ( ! V_126 -> V_215 ) {
F_74 ( V_126 -> V_128 ) ;
return - V_214 ;
}
for ( V_44 = 0 ; V_44 < V_126 -> V_129 ; ++ V_44 ) {
struct V_1 * V_2 = & V_126 -> V_128 [ V_44 ] ;
F_95 ( & V_2 -> free , 1 ) ;
V_2 -> V_18 . V_217 = 0x80 ;
V_2 -> V_18 . V_218 = F_90 ( V_126 -> V_216 + ( sizeof( * V_2 -> V_33 ) * V_44 ) ) ;
V_2 -> V_33 = V_126 -> V_215 + V_44 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_219 = NULL ;
F_47 ( & V_2 -> V_130 , & V_4 -> free ) ;
}
V_95 ;
return 0 ;
}
static void F_96 ( struct V_3 * V_4 )
{
int V_44 ;
struct V_125 * V_126 = & V_4 -> V_126 ;
V_92 ;
for ( V_44 = 0 ; V_44 < V_126 -> V_129 ; ++ V_44 ) {
F_53 ( & V_126 -> V_128 [ V_44 ] . V_130 ) ;
F_45 ( F_97 ( & V_126 -> V_128 [ V_44 ] . free ) != 1 ) ;
if ( V_126 -> V_128 [ V_44 ] . V_219 )
F_98 ( V_4 -> V_220 ,
V_126 -> V_128 [ V_44 ] . V_219 ,
V_126 -> V_128 [ V_44 ] . V_221 ) ;
}
F_74 ( V_126 -> V_128 ) ;
F_99 ( V_4 -> V_98 ,
V_126 -> V_129 * sizeof( * V_126 -> V_215 ) ,
V_126 -> V_215 , V_126 -> V_216 ) ;
V_95 ;
}
static struct V_1 * F_100 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_45 ( F_101 ( & V_4 -> free ) ) ;
V_2 = F_102 ( V_4 -> free . V_222 , struct V_1 , V_130 ) ;
F_95 ( & V_2 -> free , 0 ) ;
F_53 ( & V_2 -> V_130 ) ;
return V_2 ;
}
static void F_103 ( struct V_1 * V_2 ,
void (* V_136) ( struct V_1 * ) , T_4 V_19 )
{
V_2 -> V_132 = NULL ;
V_2 -> V_223 = NULL ;
V_2 -> V_18 . V_19 = V_19 ;
V_2 -> V_136 = V_136 ;
V_2 -> V_134 = NULL ;
}
static void F_104 ( struct V_131 * V_224 , int V_225 ,
struct V_226 * V_227 )
{
int V_44 ;
struct V_228 * V_229 ;
F_105 (scmd, sg, nseg, i) {
V_227 [ V_44 ] . V_207 = F_90 ( F_106 ( V_229 ) ) ;
V_227 [ V_44 ] . V_208 = F_89 ( F_107 ( V_229 ) ) ;
V_227 [ V_44 ] . V_230 = 0 ;
}
}
static int F_108 ( struct V_131 * V_224 ,
struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_231 * V_98 )
{
int V_232 ;
struct V_226 * V_41 = & V_6 -> V_218 ;
struct V_3 * V_4 = F_109 ( V_98 ) ;
if ( V_233 )
V_6 -> V_39 |= F_52 ( V_234 ) ;
V_232 = F_110 ( V_224 ) ;
if ( ! V_232 ) {
V_6 -> V_39 |= F_52 ( V_235 ) ;
return 0 ;
} else if ( F_111 ( V_232 < 0 ) ) {
if ( V_4 -> V_236 > V_237 )
F_112 ( V_238 , V_224 , L_16 ) ;
return V_232 ;
}
if ( V_224 -> V_239 == V_240 ) {
V_6 -> V_39 |= F_52 ( V_241 ) ;
V_6 -> V_7 . V_242 |= V_243 ;
} else {
V_6 -> V_39 |= F_52 ( V_244 ) ;
V_6 -> V_7 . V_242 |= V_245 ;
}
if ( V_232 == 1 ) {
F_104 ( V_224 , V_232 , V_41 ) ;
return 0 ;
}
V_6 -> V_39 |= F_52 ( V_246 ) ;
if ( ! V_2 -> V_219 ) {
V_2 -> V_219 = F_113 ( V_4 -> V_220 , V_247 ,
& V_2 -> V_221 ) ;
if ( ! V_2 -> V_219 ) {
F_49 ( V_224 ) ;
if ( V_4 -> V_236 > V_237 )
F_112 ( V_238 , V_224 , L_17 ) ;
return - V_214 ;
}
}
F_104 ( V_224 , V_232 , V_2 -> V_219 ) ;
V_41 -> V_207 = F_90 ( V_2 -> V_221 ) ;
V_41 -> V_208 = F_89 ( V_232 * sizeof( struct V_226 ) ) ;
V_41 -> V_230 = 0 ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_24 ( V_4 -> V_98 , L_18 , V_2 ) ;
F_59 ( V_4 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_171 )
{
T_5 * V_248 = ( T_5 * ) & V_2 -> V_18 ;
int V_47 ;
* V_2 -> V_33 = V_2 -> V_7 ;
if ( V_2 -> V_18 . V_19 == V_21 )
V_2 -> V_33 -> V_8 . V_249 = F_90 ( ( T_2 ) V_2 ) ;
else if ( V_2 -> V_18 . V_19 == V_31 )
V_2 -> V_33 -> V_11 . V_249 = F_90 ( ( T_2 ) V_2 ) ;
else
F_116 () ;
F_47 ( & V_2 -> V_130 , & V_4 -> V_250 ) ;
F_117 ( & V_2 -> V_138 ) ;
if ( V_171 ) {
V_2 -> V_138 . V_41 = ( unsigned long ) V_2 ;
V_2 -> V_138 . V_251 = V_16 + ( V_171 * V_178 ) ;
V_2 -> V_138 . V_252 = ( void (*) ( unsigned long ) ) F_114 ;
F_118 ( & V_2 -> V_138 ) ;
}
F_119 () ;
if ( ( V_47 = F_25 ( V_4 , F_2 ( V_248 [ 0 ] ) ,
F_2 ( V_248 [ 1 ] ) ) ) ) {
F_53 ( & V_2 -> V_130 ) ;
F_54 ( & V_2 -> V_138 ) ;
if ( V_47 == V_124 ) {
if ( F_120 () )
F_41 ( V_4 -> V_98 , L_19 ) ;
if ( V_2 -> V_132 )
F_49 ( V_2 -> V_132 ) ;
F_44 ( V_2 ) ;
return V_253 ;
}
F_24 ( V_4 -> V_98 , L_20 , V_47 ) ;
if ( V_2 -> V_132 ) {
V_2 -> V_132 -> V_56 = V_55 << 16 ;
V_2 -> V_136 = F_48 ;
} else
V_2 -> V_33 -> V_11 . V_36 = F_52 ( V_254 ) ;
V_2 -> V_136 ( V_2 ) ;
} else
F_1 ( V_2 ) ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_33 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
struct V_131 * V_132 = V_2 -> V_132 ;
const char * V_50 = V_49 ;
int V_127 = F_7 ( F_6 ( V_6 -> V_36 ) , F_6 ( V_6 -> error ) ) ;
int V_255 = 0 ;
int V_40 = 0 ;
if ( V_127 >= 0 ) {
V_255 = V_45 [ V_127 ] . log ;
V_50 = V_45 [ V_127 ] . V_48 ;
}
if ( ! V_255 && ( V_4 -> V_236 <= ( V_237 + 1 ) ) )
return;
if ( V_38 -> V_39 & V_54 )
V_40 = V_38 -> V_41 . V_42 . V_40 ;
F_112 ( V_238 , V_132 , L_21
L_22 ,
V_132 -> V_132 [ 0 ] , V_50 , V_6 -> V_36 , V_6 -> error ,
V_38 -> V_39 , V_40 , F_122 ( V_132 ) , V_38 -> V_43 ) ;
}
static void F_123 ( struct V_256 * V_257 )
{
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
struct V_169 * V_170 = F_124 ( V_143 ( V_257 ) ) ;
struct V_64 * V_65 ;
F_22 (tgt, &vhost->targets, queue) {
if ( V_170 == V_65 -> V_170 ) {
F_15 ( V_65 , V_68 ) ;
break;
}
}
F_18 ( V_4 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_33 -> V_8 ;
struct V_51 * V_38 = & V_6 -> V_38 ;
struct V_131 * V_132 = V_2 -> V_132 ;
T_3 V_258 = 0 ;
T_3 V_259 = F_4 ( V_38 -> V_260 ) ;
if ( V_132 ) {
if ( F_6 ( V_6 -> V_261 ) & V_262 )
F_126 ( V_132 , F_4 ( V_6 -> V_263 ) ) ;
else if ( V_38 -> V_39 & V_264 )
F_126 ( V_132 , F_4 ( V_38 -> V_265 ) ) ;
else
F_126 ( V_132 , 0 ) ;
if ( V_6 -> V_36 ) {
V_132 -> V_56 = F_10 ( V_6 ) ;
if ( V_38 -> V_39 & V_54 )
V_258 = F_4 ( V_38 -> V_53 ) ;
if ( ( V_259 + V_258 ) > V_266 )
V_259 = V_266 - V_258 ;
if ( ( V_38 -> V_39 & V_267 ) && V_38 -> V_260 && V_258 <= 8 )
memcpy ( V_132 -> V_268 , V_38 -> V_41 . V_269 + V_258 , V_259 ) ;
if ( ( F_6 ( V_6 -> V_36 ) & V_270 ) &&
( F_6 ( V_6 -> error ) == V_271 ) )
F_123 ( V_132 -> V_231 ) ;
if ( ! V_132 -> V_56 && ( ! F_122 ( V_132 ) || ( V_38 -> V_39 & V_272 ) ) )
V_132 -> V_56 = ( V_55 << 16 ) ;
F_121 ( V_2 ) ;
}
if ( ! V_132 -> V_56 &&
( F_127 ( V_132 ) - F_122 ( V_132 ) < V_132 -> V_273 ) )
V_132 -> V_56 = ( V_55 << 16 ) ;
F_49 ( V_132 ) ;
V_132 -> V_133 ( V_132 ) ;
}
if ( V_2 -> V_134 )
F_50 ( V_2 -> V_134 ) ;
F_44 ( V_2 ) ;
}
static inline int F_128 ( struct V_3 * V_4 )
{
int V_56 = 0 ;
switch ( V_4 -> V_72 ) {
case V_164 :
case V_73 :
V_56 = V_274 << 16 ;
break;
case V_116 :
case V_88 :
case V_166 :
case V_140 :
V_56 = V_275 << 16 ;
break;
case V_151 :
V_56 = 0 ;
break;
} ;
return V_56 ;
}
static int F_129 ( struct V_131 * V_132 ,
void (* V_136) ( struct V_131 * ) )
{
struct V_3 * V_4 = F_63 ( V_132 -> V_231 -> V_89 ) ;
struct V_169 * V_170 = F_124 ( V_143 ( V_132 -> V_231 ) ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_47 ;
if ( F_111 ( ( V_47 = F_130 ( V_170 ) ) ) ||
F_111 ( ( V_47 = F_128 ( V_4 ) ) ) ) {
V_132 -> V_56 = V_47 ;
V_136 ( V_132 ) ;
return 0 ;
}
V_132 -> V_56 = ( V_276 << 16 ) ;
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , F_125 , V_21 ) ;
V_2 -> V_132 = V_132 ;
V_132 -> V_133 = V_136 ;
V_6 = & V_2 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_153 . V_207 = F_90 ( F_2 ( V_2 -> V_18 . V_218 ) + F_131 ( struct V_5 , V_38 ) ) ;
V_6 -> V_153 . V_208 = F_89 ( sizeof( V_6 -> V_38 ) ) ;
V_6 -> V_277 = F_89 ( V_278 ) ;
V_6 -> V_279 = F_89 ( sizeof( V_6 -> V_7 ) ) ;
V_6 -> V_280 = F_89 ( sizeof( V_6 -> V_38 ) ) ;
V_6 -> V_281 = F_89 ( ( unsigned long ) V_132 -> V_231 -> V_282 ) ;
V_6 -> V_25 = F_90 ( V_170 -> V_283 ) ;
V_6 -> V_7 . V_30 = F_89 ( F_127 ( V_132 ) ) ;
F_132 ( V_132 -> V_231 -> V_26 , & V_6 -> V_7 . V_26 ) ;
memcpy ( V_6 -> V_7 . V_23 , V_132 -> V_132 , V_132 -> V_284 ) ;
if ( V_132 -> V_39 & V_285 ) {
V_6 -> V_286 = F_90 ( V_132 -> V_249 ) ;
V_6 -> V_7 . V_287 = V_288 ;
}
if ( F_133 ( ! ( V_47 = F_108 ( V_132 , V_2 , V_6 , V_4 -> V_98 ) ) ) )
return F_115 ( V_2 , V_4 , 0 ) ;
F_44 ( V_2 ) ;
if ( V_47 == - V_214 )
return V_253 ;
if ( V_4 -> V_236 > V_237 )
F_112 ( V_238 , V_132 ,
L_23 , V_47 ) ;
V_132 -> V_56 = V_55 << 16 ;
V_136 ( V_132 ) ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_44 ( V_2 ) ;
V_4 -> V_289 = 0 ;
F_135 ( V_4 -> V_98 , L_24 ) ;
}
static int F_136 ( struct V_290 * V_291 )
{
struct V_3 * V_4 = F_63 ( F_137 ( V_291 ) ) ;
unsigned long V_283 = ( unsigned long ) V_291 -> V_292 ;
struct V_1 * V_2 ;
struct V_293 * V_294 ;
unsigned long V_39 ;
int V_47 ;
V_92 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_289 || V_4 -> V_72 != V_151 ) {
F_58 ( V_4 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
V_4 -> V_289 = 1 ;
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , F_134 , V_31 ) ;
V_294 = & V_2 -> V_7 . V_294 ;
memset ( V_294 , 0 , sizeof( * V_294 ) ) ;
V_294 -> V_295 . V_296 = F_89 ( 1 ) ;
V_294 -> V_295 . V_32 = F_89 ( V_297 ) ;
V_294 -> V_295 . V_298 = F_52 ( sizeof( * V_294 ) ) ;
V_294 -> V_24 = F_90 ( V_283 ) ;
V_294 -> V_281 = F_89 ( V_299 ) ;
V_294 -> V_300 = F_89 ( V_301 ) ;
V_47 = F_115 ( V_2 , V_4 , V_302 ) ;
if ( V_47 != 0 ) {
V_4 -> V_289 = 0 ;
F_24 ( V_4 -> V_98 , L_25 , V_47 ) ;
V_47 = - V_179 ;
} else
F_135 ( V_4 -> V_98 , L_26 ,
V_283 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
return V_47 ;
}
static int F_138 ( struct V_3 * V_4 , unsigned int V_283 )
{
struct V_303 * V_304 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
union V_305 V_306 ;
unsigned long V_39 ;
int V_47 = 0 , V_307 = 1 ;
V_92 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_24 == V_283 ) {
V_307 = 0 ;
break;
}
}
if ( ! V_307 )
goto V_308;
if ( F_111 ( ( V_47 = F_128 ( V_4 ) ) ) )
goto V_308;
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , V_309 , V_31 ) ;
V_304 = & V_2 -> V_7 . V_304 ;
memset ( V_304 , 0 , sizeof( * V_304 ) ) ;
V_304 -> V_295 . V_296 = F_89 ( 1 ) ;
V_304 -> V_295 . V_32 = F_89 ( V_310 ) ;
V_304 -> V_295 . V_298 = F_52 ( sizeof( * V_304 ) ) ;
V_304 -> V_24 = F_90 ( V_283 ) ;
V_2 -> V_223 = & V_306 ;
F_139 ( & V_2 -> V_311 ) ;
V_47 = F_115 ( V_2 , V_4 , V_302 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 )
return - V_179 ;
F_140 ( & V_2 -> V_311 ) ;
if ( V_306 . V_304 . V_295 . V_36 )
V_47 = - V_179 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( V_2 ) ;
V_308:
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
return V_47 ;
}
static int F_141 ( struct V_290 * V_291 )
{
struct V_3 * V_4 = F_63 ( F_137 ( V_291 ) ) ;
struct V_169 * V_170 = F_142 ( V_291 ) ;
struct V_312 * V_10 ;
struct V_1 * V_2 ;
union V_305 V_306 ;
unsigned long V_39 , V_283 = - 1 ;
struct V_313 * V_314 = V_291 -> V_315 ;
struct V_316 * V_317 = V_291 -> V_318 ;
unsigned int V_319 = V_314 -> V_320 ;
int V_47 = 0 , V_321 , V_322 , V_307 = 0 ;
T_3 V_323 , V_258 ;
V_92 ;
V_317 -> V_324 = 0 ;
if ( V_170 )
V_283 = V_170 -> V_283 ;
switch ( V_319 ) {
case V_325 :
V_283 = ( V_314 -> V_326 . V_327 . V_283 [ 0 ] << 16 ) |
( V_314 -> V_326 . V_327 . V_283 [ 1 ] << 8 ) |
V_314 -> V_326 . V_327 . V_283 [ 2 ] ;
case V_328 :
V_323 = V_329 ;
break;
case V_330 :
V_307 = 1 ;
V_283 = ( V_314 -> V_326 . V_331 . V_283 [ 0 ] << 16 ) |
( V_314 -> V_326 . V_331 . V_283 [ 1 ] << 8 ) |
V_314 -> V_326 . V_331 . V_283 [ 2 ] ;
case V_332 :
V_323 = V_333 ;
break;
default:
return - V_334 ;
} ;
if ( V_283 == - 1 )
return - V_46 ;
if ( ! F_143 ( & V_4 -> V_335 ) )
return - V_336 ;
V_291 -> V_292 = ( void * ) V_283 ;
V_321 = F_144 ( V_4 -> V_98 , V_291 -> V_337 . V_338 ,
V_291 -> V_337 . V_339 , V_240 ) ;
if ( ! V_321 ) {
F_145 ( & V_4 -> V_335 ) ;
return - V_214 ;
}
V_322 = F_144 ( V_4 -> V_98 , V_291 -> V_340 . V_338 ,
V_291 -> V_340 . V_339 , V_341 ) ;
if ( ! V_322 ) {
F_146 ( V_4 -> V_98 , V_291 -> V_337 . V_338 ,
V_291 -> V_337 . V_339 , V_240 ) ;
F_145 ( & V_4 -> V_335 ) ;
return - V_214 ;
}
if ( V_321 > 1 || V_322 > 1 ) {
V_47 = - V_46 ;
goto V_342;
}
if ( V_307 )
V_47 = F_138 ( V_4 , V_283 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( F_111 ( V_47 || ( V_170 && ( V_47 = F_130 ( V_170 ) ) ) ) ||
F_111 ( ( V_47 = F_128 ( V_4 ) ) ) ) {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
goto V_342;
}
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , V_309 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_343 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_344 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( * V_10 ) - sizeof( V_10 -> V_345 ) - sizeof( V_10 -> V_7 ) ) ;
V_10 -> V_346 . V_207 = F_90 ( F_2 ( V_2 -> V_18 . V_218 ) +
F_131 ( struct V_312 , V_7 ) ) ;
V_10 -> V_346 . V_208 = F_89 ( sizeof( V_10 -> V_7 ) ) ;
V_10 -> V_7 . V_284 = F_89 ( V_291 -> V_337 . V_279 ) ;
V_10 -> V_7 . V_258 = F_89 ( V_291 -> V_340 . V_279 ) ;
V_10 -> V_7 . V_39 = F_89 ( V_323 ) ;
V_10 -> V_7 . V_281 = F_89 ( V_299 ) ;
V_10 -> V_7 . V_8 . V_207 = F_90 ( F_106 ( V_291 -> V_337 . V_338 ) ) ;
V_10 -> V_7 . V_8 . V_208 = F_89 ( F_107 ( V_291 -> V_337 . V_338 ) ) ;
V_10 -> V_7 . V_38 . V_207 = F_90 ( F_106 ( V_291 -> V_340 . V_338 ) ) ;
V_10 -> V_7 . V_38 . V_208 = F_89 ( F_107 ( V_291 -> V_340 . V_338 ) ) ;
V_10 -> V_7 . V_24 = F_90 ( V_283 ) ;
V_10 -> V_7 . V_249 = F_90 ( ( T_2 ) V_2 ) ;
V_258 = F_4 ( V_10 -> V_7 . V_38 . V_208 ) ;
V_2 -> V_223 = & V_306 ;
F_139 ( & V_2 -> V_311 ) ;
V_47 = F_115 ( V_2 , V_4 , 0 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 ) {
V_47 = - V_179 ;
goto V_342;
}
F_140 ( & V_2 -> V_311 ) ;
if ( V_306 . V_343 . V_295 . V_36 )
V_47 = - V_179 ;
else
V_317 -> V_324 = V_258 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( V_2 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_317 -> V_56 = V_47 ;
F_147 ( V_291 , V_317 -> V_56 ,
V_317 -> V_324 ) ;
V_47 = 0 ;
V_342:
F_146 ( V_4 -> V_98 , V_291 -> V_337 . V_338 ,
V_291 -> V_337 . V_339 , V_240 ) ;
F_146 ( V_4 -> V_98 , V_291 -> V_340 . V_338 ,
V_291 -> V_340 . V_339 , V_341 ) ;
F_145 ( & V_4 -> V_335 ) ;
V_95 ;
return V_47 ;
}
static int F_148 ( struct V_256 * V_257 , int type , char * V_347 )
{
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
struct V_169 * V_170 = F_124 ( V_143 ( V_257 ) ) ;
struct V_5 * V_294 ;
struct V_1 * V_2 = NULL ;
union V_305 V_306 ;
struct V_51 * V_348 = & V_306 . V_8 . V_38 ;
int V_349 = - V_336 ;
unsigned long V_39 ;
int V_40 = 0 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_72 == V_151 ) {
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , V_309 , V_21 ) ;
V_294 = & V_2 -> V_7 . V_8 ;
memset ( V_294 , 0 , sizeof( * V_294 ) ) ;
V_294 -> V_153 . V_207 = F_90 ( F_2 ( V_2 -> V_18 . V_218 ) + F_131 ( struct V_5 , V_38 ) ) ;
V_294 -> V_153 . V_208 = F_89 ( sizeof( V_294 -> V_38 ) ) ;
V_294 -> V_277 = F_89 ( V_278 ) ;
V_294 -> V_279 = F_89 ( sizeof( V_294 -> V_7 ) ) ;
V_294 -> V_280 = F_89 ( sizeof( V_294 -> V_38 ) ) ;
V_294 -> V_281 = F_89 ( ( unsigned long ) V_257 -> V_282 ) ;
V_294 -> V_25 = F_90 ( V_170 -> V_283 ) ;
F_132 ( V_257 -> V_26 , & V_294 -> V_7 . V_26 ) ;
V_294 -> V_39 = F_52 ( ( V_235 | V_350 ) ) ;
V_294 -> V_7 . V_27 = type ;
V_2 -> V_223 = & V_306 ;
F_139 ( & V_2 -> V_311 ) ;
V_349 = F_115 ( V_2 , V_4 , V_302 ) ;
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_349 != 0 ) {
F_149 ( V_238 , V_257 , L_27 ,
V_347 , V_349 ) ;
return - V_179 ;
}
F_149 ( V_351 , V_257 , L_28 , V_347 ) ;
F_140 ( & V_2 -> V_311 ) ;
if ( V_306 . V_8 . V_36 )
V_40 = F_10 ( & V_306 . V_8 ) ;
if ( V_40 ) {
if ( V_348 -> V_39 & V_54 )
V_40 = V_348 -> V_41 . V_42 . V_40 ;
F_149 ( V_238 , V_257 , L_29
L_30 , V_347 ,
F_9 ( F_6 ( V_306 . V_8 . V_36 ) , F_6 ( V_306 . V_8 . error ) ) ,
V_306 . V_8 . V_36 , V_306 . V_8 . error , V_348 -> V_39 , V_40 ,
V_348 -> V_43 ) ;
V_349 = - V_179 ;
} else
F_149 ( V_351 , V_257 , L_31 , V_347 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( V_2 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_349 ;
}
static int F_150 ( struct V_1 * V_2 , void * V_170 )
{
struct V_169 * V_352 ;
if ( V_2 -> V_132 ) {
V_352 = F_124 ( V_143 ( V_2 -> V_132 -> V_231 ) ) ;
if ( V_352 == V_170 )
return 1 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , void * V_231 )
{
if ( V_2 -> V_132 && V_143 ( V_2 -> V_132 -> V_231 ) == V_231 )
return 1 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 , void * V_231 )
{
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_231 )
return 1 ;
return 0 ;
}
static int F_153 ( struct V_3 * V_4 , void * V_231 ,
int (* F_154) ( struct V_1 * , void * ) )
{
struct V_1 * V_2 ;
F_155 ( V_311 ) ;
int V_353 ;
unsigned long V_39 ;
signed long V_171 = V_354 * V_178 ;
V_92 ;
do {
V_353 = 0 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_22 (evt, &vhost->sent, queue) {
if ( F_154 ( V_2 , V_231 ) ) {
V_2 -> V_134 = & V_311 ;
V_353 ++ ;
}
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_353 ) {
V_171 = F_156 ( & V_311 , V_171 ) ;
if ( ! V_171 ) {
V_353 = 0 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_22 (evt, &vhost->sent, queue) {
if ( F_154 ( V_2 , V_231 ) ) {
V_2 -> V_134 = NULL ;
V_353 ++ ;
}
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_353 )
F_24 ( V_4 -> V_98 , L_32 ) ;
V_95 ;
return V_353 ? V_355 : V_356 ;
}
}
} while ( V_353 );
V_95 ;
return V_356 ;
}
static int F_157 ( struct V_256 * V_257 , int type )
{
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
struct V_143 * V_144 = V_143 ( V_257 ) ;
struct V_169 * V_170 = F_124 ( V_144 ) ;
struct V_293 * V_294 ;
struct V_1 * V_2 , * V_357 ;
union V_305 V_38 ;
int V_349 = - V_336 ;
unsigned long V_39 ;
T_1 V_36 ;
V_92 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_357 = NULL ;
F_22 (evt, &vhost->sent, queue) {
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_257 ) {
V_357 = V_2 ;
break;
}
}
if ( ! V_357 ) {
if ( V_4 -> V_236 > V_237 )
F_149 ( V_351 , V_257 , L_33 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
if ( V_4 -> V_117 ) {
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , V_309 , V_31 ) ;
V_294 = & V_2 -> V_7 . V_294 ;
memset ( V_294 , 0 , sizeof( * V_294 ) ) ;
V_294 -> V_295 . V_296 = F_89 ( 1 ) ;
V_294 -> V_295 . V_32 = F_89 ( V_297 ) ;
V_294 -> V_295 . V_298 = F_52 ( sizeof( * V_294 ) ) ;
V_294 -> V_24 = F_90 ( V_170 -> V_283 ) ;
F_132 ( V_257 -> V_26 , & V_294 -> V_26 ) ;
if ( ! ( F_2 ( V_4 -> V_152 -> V_153 . V_204 ) & V_358 ) )
type &= ~ V_359 ;
if ( V_4 -> V_72 == V_151 )
V_294 -> V_39 = F_89 ( ( type | V_360 ) ) ;
else
V_294 -> V_39 = F_89 ( ( ( type & V_359 ) | V_360 ) ) ;
V_294 -> V_281 = F_89 ( ( unsigned long ) V_257 -> V_282 ) ;
V_294 -> V_300 = F_89 ( ( unsigned long ) V_144 -> V_282 ) ;
V_2 -> V_223 = & V_38 ;
F_139 ( & V_2 -> V_311 ) ;
V_349 = F_115 ( V_2 , V_4 , V_302 ) ;
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_349 != 0 ) {
F_149 ( V_238 , V_257 , L_25 , V_349 ) ;
return 0 ;
}
F_149 ( V_351 , V_257 , L_34 ) ;
F_140 ( & V_2 -> V_311 ) ;
V_36 = F_6 ( V_38 . V_11 . V_36 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( V_2 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_36 != V_361 ) {
F_149 ( V_362 , V_257 , L_35 , V_36 ) ;
switch ( V_36 ) {
case V_137 :
case V_254 :
return 0 ;
default:
return - V_179 ;
} ;
}
F_149 ( V_351 , V_257 , L_36 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 , void * V_230 )
{
unsigned long V_281 = ( unsigned long ) V_230 ;
if ( V_2 -> V_18 . V_19 == V_21 &&
F_4 ( V_2 -> V_7 . V_8 . V_281 ) == V_281 )
return 1 ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 , void * F_154 )
{
if ( V_2 == F_154 )
return 1 ;
return 0 ;
}
static int F_160 ( struct V_256 * V_257 )
{
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
struct V_169 * V_170 = F_124 ( V_143 ( V_257 ) ) ;
struct V_5 * V_294 ;
struct V_1 * V_2 , * V_357 ;
union V_305 V_306 ;
struct V_51 * V_348 = & V_306 . V_8 . V_38 ;
int V_47 , V_349 = - V_336 ;
unsigned long V_39 , V_171 = V_363 ;
int V_40 = 0 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_357 = NULL ;
F_22 (evt, &vhost->sent, queue) {
if ( V_2 -> V_132 && V_2 -> V_132 -> V_231 == V_257 ) {
V_357 = V_2 ;
break;
}
}
if ( ! V_357 ) {
if ( V_4 -> V_236 > V_237 )
F_149 ( V_351 , V_257 , L_37 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
if ( V_4 -> V_72 == V_151 ) {
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , V_309 , V_21 ) ;
V_294 = & V_2 -> V_7 . V_8 ;
memset ( V_294 , 0 , sizeof( * V_294 ) ) ;
V_294 -> V_153 . V_207 = F_90 ( F_2 ( V_2 -> V_18 . V_218 ) + F_131 ( struct V_5 , V_38 ) ) ;
V_294 -> V_153 . V_208 = F_89 ( sizeof( V_294 -> V_38 ) ) ;
V_294 -> V_277 = F_89 ( V_278 ) ;
V_294 -> V_279 = F_89 ( sizeof( V_294 -> V_7 ) ) ;
V_294 -> V_280 = F_89 ( sizeof( V_294 -> V_38 ) ) ;
V_294 -> V_281 = F_89 ( ( unsigned long ) V_257 -> V_282 ) ;
V_294 -> V_25 = F_90 ( V_170 -> V_283 ) ;
F_132 ( V_257 -> V_26 , & V_294 -> V_7 . V_26 ) ;
V_294 -> V_39 = F_52 ( ( V_235 | V_350 ) ) ;
V_294 -> V_7 . V_27 = V_364 ;
V_2 -> V_223 = & V_306 ;
F_139 ( & V_2 -> V_311 ) ;
V_349 = F_115 ( V_2 , V_4 , V_302 ) ;
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_349 != 0 ) {
F_149 ( V_238 , V_257 , L_38 , V_349 ) ;
return - V_179 ;
}
F_149 ( V_351 , V_257 , L_39 ) ;
V_171 = F_156 ( & V_2 -> V_311 , V_171 ) ;
if ( ! V_171 ) {
V_47 = F_157 ( V_257 , 0 ) ;
if ( ! V_47 ) {
V_47 = F_153 ( V_4 , V_257 -> V_282 , F_158 ) ;
if ( V_47 == V_356 )
V_47 = 0 ;
}
if ( V_47 ) {
F_149 ( V_351 , V_257 , L_40 ) ;
F_59 ( V_4 ) ;
V_349 = - V_179 ;
V_47 = F_153 ( V_4 , V_257 -> V_282 , F_158 ) ;
if ( V_47 == V_356 )
V_349 = 0 ;
V_47 = F_153 ( V_4 , V_2 , F_159 ) ;
if ( V_47 != V_356 ) {
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_57 ( V_4 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_349 = 0 ;
}
goto V_342;
}
}
if ( V_306 . V_8 . V_36 )
V_40 = F_10 ( & V_306 . V_8 ) ;
if ( V_40 ) {
if ( V_348 -> V_39 & V_54 )
V_40 = V_348 -> V_41 . V_42 . V_40 ;
F_149 ( V_238 , V_257 , L_41
L_30 ,
F_9 ( F_6 ( V_306 . V_8 . V_36 ) , F_6 ( V_306 . V_8 . error ) ) ,
V_306 . V_8 . V_36 , V_306 . V_8 . error , V_348 -> V_39 , V_40 ,
V_348 -> V_43 ) ;
V_349 = - V_179 ;
} else
F_149 ( V_351 , V_257 , L_42 ) ;
V_342:
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_44 ( V_2 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_349 ;
}
static int F_161 ( struct V_131 * V_8 )
{
struct V_256 * V_257 = V_8 -> V_231 ;
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
int V_365 , V_366 ;
int V_47 = V_355 ;
V_92 ;
V_366 = F_162 ( V_8 ) ;
F_81 ( V_4 ) ;
if ( V_366 != V_367 ) {
V_365 = F_157 ( V_257 , V_368 ) ;
F_160 ( V_257 ) ;
} else
V_365 = F_157 ( V_257 , V_359 ) ;
if ( ! V_365 )
V_47 = F_153 ( V_4 , V_257 , F_152 ) ;
if ( V_366 == V_367 && V_47 != V_355 )
V_47 = V_367 ;
V_95 ;
return V_47 ;
}
static int F_163 ( struct V_131 * V_8 )
{
struct V_256 * V_257 = V_8 -> V_231 ;
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
int V_365 , V_366 , V_369 = 0 ;
int V_47 = V_355 ;
V_92 ;
V_366 = F_162 ( V_8 ) ;
F_81 ( V_4 ) ;
if ( V_366 != V_367 ) {
V_365 = F_157 ( V_257 , V_370 ) ;
V_369 = F_148 ( V_257 , V_371 , L_43 ) ;
} else
V_365 = F_157 ( V_257 , V_359 ) ;
if ( ! V_365 && ! V_369 )
V_47 = F_153 ( V_4 , V_257 , F_152 ) ;
if ( V_366 == V_367 && V_47 != V_355 )
V_47 = V_367 ;
V_95 ;
return V_47 ;
}
static void F_164 ( struct V_256 * V_257 , void * V_41 )
{
unsigned long * V_47 = V_41 ;
* V_47 |= F_157 ( V_257 , V_359 ) ;
}
static void F_165 ( struct V_256 * V_257 , void * V_41 )
{
unsigned long * V_47 = V_41 ;
* V_47 |= F_157 ( V_257 , V_372 ) ;
}
static int F_166 ( struct V_131 * V_8 )
{
struct V_256 * V_257 = V_8 -> V_231 ;
struct V_3 * V_4 = F_63 ( V_257 -> V_89 ) ;
struct V_143 * V_144 = V_143 ( V_257 ) ;
int V_366 ;
int V_369 = 0 ;
int V_47 = V_355 ;
unsigned long V_365 = 0 ;
V_92 ;
V_366 = F_162 ( V_8 ) ;
F_81 ( V_4 ) ;
if ( V_366 != V_367 ) {
F_167 ( V_144 , & V_365 , F_165 ) ;
V_369 = F_148 ( V_257 , V_373 , L_44 ) ;
} else
F_167 ( V_144 , & V_365 , F_164 ) ;
if ( ! V_365 && ! V_369 )
V_47 = F_153 ( V_4 , V_144 , F_151 ) ;
if ( V_366 == V_367 && V_47 != V_355 )
V_47 = V_367 ;
V_95 ;
return V_47 ;
}
static int F_168 ( struct V_131 * V_8 )
{
int V_47 , V_366 ;
struct V_3 * V_4 = F_63 ( V_8 -> V_231 -> V_89 ) ;
V_366 = F_162 ( V_8 ) ;
F_24 ( V_4 -> V_98 , L_45 ) ;
V_47 = F_83 ( V_4 -> V_89 ) ;
if ( V_366 == V_367 )
return V_367 ;
return V_47 ? V_355 : V_356 ;
}
static void F_169 ( struct V_169 * V_170 )
{
struct V_145 * V_146 = F_170 ( V_170 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
struct V_169 * V_374 ;
struct V_256 * V_257 ;
unsigned long V_47 ;
V_92 ;
F_171 (sdev, shost) {
V_374 = F_124 ( V_143 ( V_257 ) ) ;
if ( V_374 != V_170 )
continue;
F_157 ( V_257 , V_359 ) ;
}
V_47 = F_153 ( V_4 , V_170 , F_150 ) ;
if ( V_47 == V_355 )
F_83 ( V_146 ) ;
V_95 ;
}
static const struct V_375 * F_172 ( T_2 V_376 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_377 ) ; V_44 ++ )
if ( V_377 [ V_44 ] . V_376 == V_376 )
return & V_377 [ V_44 ] ;
return & V_378 ;
}
static const char * F_173 ( enum V_379 V_72 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_380 ) ; V_44 ++ )
if ( V_380 [ V_44 ] . V_72 == V_72 )
return V_380 [ V_44 ] . V_347 ;
return L_46 ;
}
static void F_174 ( struct V_381 * V_18 ,
struct V_3 * V_4 )
{
const struct V_375 * V_347 = F_172 ( F_2 ( V_18 -> V_382 ) ) ;
struct V_64 * V_65 ;
F_68 ( V_4 , V_347 -> V_236 , L_47
L_48 , V_347 -> V_347 , F_2 ( V_18 -> V_24 ) ,
F_2 ( V_18 -> V_383 ) , F_2 ( V_18 -> V_174 ) ,
F_173 ( V_18 -> V_384 ) ) ;
switch ( F_2 ( V_18 -> V_382 ) ) {
case V_385 :
switch ( V_18 -> V_384 ) {
case V_386 :
F_21 ( V_4 , V_140 ) ;
break;
case V_387 :
F_21 ( V_4 , V_164 ) ;
break;
case V_388 :
case V_389 :
default:
V_4 -> V_93 |= V_390 ;
V_4 -> V_142 = 1 ;
F_58 ( V_4 ) ;
break;
} ;
break;
case V_391 :
V_4 -> V_93 |= V_390 ;
V_4 -> V_142 = 1 ;
F_58 ( V_4 ) ;
break;
case V_392 :
case V_393 :
V_4 -> V_93 |= V_394 ;
if ( V_4 -> V_72 < V_166 ) {
V_4 -> V_142 = 1 ;
F_58 ( V_4 ) ;
}
break;
case V_395 :
case V_396 :
V_4 -> V_93 |= V_394 ;
F_18 ( V_4 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
F_22 (tgt, &vhost->targets, queue) {
if ( ! V_18 -> V_24 && ! V_18 -> V_383 && ! V_18 -> V_174 )
break;
if ( V_18 -> V_24 && F_90 ( V_65 -> V_24 ) != V_18 -> V_24 )
continue;
if ( V_18 -> V_383 && F_90 ( V_65 -> V_173 . V_175 ) != V_18 -> V_383 )
continue;
if ( V_18 -> V_174 && F_90 ( V_65 -> V_173 . V_174 ) != V_18 -> V_174 )
continue;
if ( V_65 -> V_400 && F_2 ( V_18 -> V_382 ) == V_397 )
V_65 -> V_401 = 1 ;
if ( ! V_65 -> V_400 || F_2 ( V_18 -> V_382 ) == V_399 ) {
F_15 ( V_65 , V_68 ) ;
F_18 ( V_4 ) ;
}
}
break;
case V_402 :
case V_403 :
F_21 ( V_4 , V_140 ) ;
break;
case V_404 :
F_21 ( V_4 , V_164 ) ;
break;
case V_405 :
F_21 ( V_4 , V_166 ) ;
break;
default:
F_24 ( V_4 -> V_98 , L_49 , V_18 -> V_382 ) ;
break;
} ;
}
static void F_175 ( struct V_406 * V_18 , struct V_3 * V_4 )
{
long V_47 ;
struct V_1 * V_2 = (struct V_1 * ) F_2 ( V_18 -> V_218 ) ;
switch ( V_18 -> V_217 ) {
case V_407 :
switch ( V_18 -> V_19 ) {
case V_408 :
F_135 ( V_4 -> V_98 , L_50 ) ;
V_47 = F_30 ( V_4 ) ;
if ( V_47 == 0 )
F_23 ( V_4 ) ;
else
F_24 ( V_4 -> V_98 , L_51 , V_47 ) ;
break;
case V_409 :
F_135 ( V_4 -> V_98 , L_52 ) ;
F_23 ( V_4 ) ;
break;
default:
F_24 ( V_4 -> V_98 , L_53 , V_18 -> V_19 ) ;
}
return;
case V_410 :
V_4 -> V_72 = V_116 ;
V_4 -> V_117 = 0 ;
F_17 ( V_4 , V_81 ) ;
if ( V_18 -> V_19 == V_411 ) {
F_135 ( V_4 -> V_98 , L_54 ) ;
V_4 -> V_199 = 1 ;
F_55 ( V_4 , V_275 ) ;
F_21 ( V_4 , V_140 ) ;
F_17 ( V_4 , V_86 ) ;
} else {
F_24 ( V_4 -> V_98 , L_55 , V_18 -> V_19 ) ;
F_55 ( V_4 , V_55 ) ;
F_21 ( V_4 , V_140 ) ;
F_17 ( V_4 , V_85 ) ;
}
return;
case V_412 :
break;
default:
F_24 ( V_4 -> V_98 , L_56 , V_18 -> V_217 ) ;
return;
}
if ( V_18 -> V_19 == V_413 )
return;
if ( F_111 ( ! F_43 ( & V_4 -> V_126 , V_2 ) ) ) {
F_24 ( V_4 -> V_98 , L_57 ,
V_18 -> V_218 ) ;
return;
}
if ( F_111 ( F_97 ( & V_2 -> free ) ) ) {
F_24 ( V_4 -> V_98 , L_58 ,
V_18 -> V_218 ) ;
return;
}
F_54 ( & V_2 -> V_138 ) ;
F_53 ( & V_2 -> V_130 ) ;
F_5 ( V_2 ) ;
V_2 -> V_136 ( V_2 ) ;
}
static int F_176 ( struct V_145 * V_146 , unsigned long time )
{
unsigned long V_39 ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
int V_136 = 0 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
if ( time >= ( V_177 * V_178 ) ) {
F_135 ( V_4 -> V_98 , L_59
L_60 , V_177 ) ;
V_136 = 1 ;
}
if ( V_4 -> V_414 )
V_136 = 1 ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return V_136 ;
}
static int F_177 ( struct V_256 * V_257 )
{
struct V_145 * V_146 = V_257 -> V_89 ;
struct V_169 * V_170 = F_124 ( V_143 ( V_257 ) ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 = 0 ;
if ( ! V_170 || F_130 ( V_170 ) )
return - V_415 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
V_257 -> V_282 = ( void * ) ( unsigned long ) V_4 -> V_416 ++ ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_178 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = F_62 ( V_144 -> V_98 . V_147 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 = 0 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
V_144 -> V_282 = ( void * ) ( unsigned long ) V_4 -> V_416 ++ ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_179 ( struct V_256 * V_257 )
{
struct V_145 * V_146 = V_257 -> V_89 ;
unsigned long V_39 = 0 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
if ( V_257 -> type == V_417 )
V_257 -> V_418 = 1 ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_180 ( struct V_256 * V_257 , int V_419 )
{
if ( V_419 > V_420 )
V_419 = V_420 ;
return F_181 ( V_257 , V_419 ) ;
}
static T_6 F_182 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_183 ) ;
}
static T_6 F_184 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_210 ) ;
}
static T_6 F_185 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_424 ) ;
}
static T_6 F_186 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_61 ,
V_4 -> V_152 -> V_153 . V_212 ) ;
}
static T_6 F_187 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_62 , V_4 -> V_152 -> V_153 . V_296 ) ;
}
static T_6 F_188 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
return snprintf ( V_423 , V_101 , L_63 , V_4 -> V_152 -> V_153 . V_204 ) ;
}
static T_6 F_189 ( struct V_231 * V_98 ,
struct V_421 * V_422 , char * V_423 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 = 0 ;
int V_208 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
V_208 = snprintf ( V_423 , V_101 , L_62 , V_4 -> V_236 ) ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return V_208 ;
}
static T_6 F_190 ( struct V_231 * V_98 ,
struct V_421 * V_422 ,
const char * V_423 , T_7 V_425 )
{
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 = 0 ;
F_40 ( V_146 -> V_122 , V_39 ) ;
V_4 -> V_236 = F_191 ( V_423 , NULL , 10 ) ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return strlen ( V_423 ) ;
}
static T_6 F_192 ( struct V_426 * V_427 , struct V_428 * V_429 ,
struct V_430 * V_431 ,
char * V_423 , T_8 V_432 , T_7 V_425 )
{
struct V_231 * V_98 = F_73 ( V_429 , struct V_231 , V_429 ) ;
struct V_145 * V_146 = F_183 ( V_98 ) ;
struct V_3 * V_4 = F_63 ( V_146 ) ;
unsigned long V_39 = 0 ;
int V_129 = V_433 ;
char * V_434 = ( char * ) V_4 -> V_14 ;
if ( V_432 > V_129 )
return 0 ;
if ( V_432 + V_425 > V_129 ) {
V_129 -= V_432 ;
V_425 = V_129 ;
}
F_40 ( V_146 -> V_122 , V_39 ) ;
memcpy ( V_423 , & V_434 [ V_432 ] , V_425 ) ;
F_42 ( V_146 -> V_122 , V_39 ) ;
return V_425 ;
}
static struct V_381 * F_193 ( struct V_3 * V_4 )
{
struct V_435 * V_99 = & V_4 -> V_99 ;
struct V_381 * V_18 ;
V_18 = & V_99 -> V_100 [ V_99 -> V_102 ] ;
if ( V_18 -> V_217 & 0x80 ) {
if ( ++ V_99 -> V_102 == V_99 -> V_129 )
V_99 -> V_102 = 0 ;
F_194 () ;
} else
V_18 = NULL ;
return V_18 ;
}
static struct V_406 * F_195 ( struct V_3 * V_4 )
{
struct V_111 * V_130 = & V_4 -> V_18 ;
struct V_406 * V_18 ;
V_18 = & V_130 -> V_100 [ V_130 -> V_102 ] ;
if ( V_18 -> V_217 & 0x80 ) {
if ( ++ V_130 -> V_102 == V_130 -> V_129 )
V_130 -> V_102 = 0 ;
F_194 () ;
} else
V_18 = NULL ;
return V_18 ;
}
static T_9 F_196 ( int V_112 , void * V_436 )
{
struct V_3 * V_4 = (struct V_3 * ) V_436 ;
unsigned long V_39 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_197 ( F_26 ( V_4 -> V_98 ) ) ;
F_198 ( & V_4 -> V_113 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_437 ;
}
static void F_199 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
struct V_107 * V_108 = F_26 ( V_4 -> V_98 ) ;
struct V_406 * V_18 ;
struct V_381 * V_206 ;
unsigned long V_39 ;
int V_136 = 0 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
while ( ! V_136 ) {
while ( ( V_206 = F_193 ( V_4 ) ) != NULL ) {
F_174 ( V_206 , V_4 ) ;
V_206 -> V_217 = 0 ;
F_200 () ;
}
while ( ( V_18 = F_195 ( V_4 ) ) != NULL ) {
F_175 ( V_18 , V_4 ) ;
V_18 -> V_217 = 0 ;
F_200 () ;
}
F_201 ( V_108 ) ;
if ( ( V_206 = F_193 ( V_4 ) ) != NULL ) {
F_197 ( V_108 ) ;
F_174 ( V_206 , V_4 ) ;
V_206 -> V_217 = 0 ;
F_200 () ;
} else if ( ( V_18 = F_195 ( V_4 ) ) != NULL ) {
F_197 ( V_108 ) ;
F_175 ( V_18 , V_4 ) ;
V_18 -> V_217 = 0 ;
F_200 () ;
} else
V_136 = 1 ;
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_202 ( struct V_64 * V_65 ,
void (* V_103) ( struct V_64 * ) )
{
F_15 ( V_65 , V_438 ) ;
V_65 -> V_103 = V_103 ;
F_20 ( & V_65 -> V_4 -> V_91 ) ;
}
static int F_203 ( struct V_64 * V_65 ,
void (* V_103) ( struct V_64 * ) )
{
if ( ++ V_65 -> V_96 > V_439 ) {
F_15 ( V_65 , V_68 ) ;
F_20 ( & V_65 -> V_4 -> V_91 ) ;
return 0 ;
} else
F_202 ( V_65 , V_103 ) ;
return 1 ;
}
static int F_204 ( T_1 V_39 )
{
int V_44 ;
int V_319 = ( V_39 & 0x0f00 ) >> 8 ;
for ( V_44 = 0 ; V_44 < F_8 ( V_440 ) ; V_44 ++ )
if ( V_440 [ V_44 ] . V_319 == V_319 )
return V_44 ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_441 * V_38 = & V_2 -> V_33 -> V_442 ;
struct V_443 * V_444 = & V_38 -> V_444 ;
T_3 V_36 = F_6 ( V_38 -> V_295 . V_36 ) ;
int V_127 , V_445 = V_237 ;
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
switch ( V_36 ) {
case V_361 :
F_206 ( V_65 , L_64 ,
V_444 -> type , V_444 -> V_39 , V_444 -> V_448 ) ;
if ( V_444 -> type == V_278 ) {
V_127 = F_204 ( F_6 ( V_444 -> V_39 ) ) ;
if ( V_440 [ V_127 ] . V_117 ) {
if ( F_6 ( V_444 -> V_39 ) & V_449 ) {
V_65 -> V_400 = 0 ;
V_65 -> V_173 . V_450 = 0 ;
if ( F_4 ( V_444 -> V_448 ) & V_451 )
V_65 -> V_173 . V_450 |= V_452 ;
if ( F_4 ( V_444 -> V_448 ) & V_453 )
V_65 -> V_173 . V_450 |= V_454 ;
V_65 -> V_70 = 1 ;
} else
F_15 ( V_65 , V_68 ) ;
} else if ( V_440 [ V_127 ] . V_57 )
F_203 ( V_65 , V_455 ) ;
else
F_15 ( V_65 , V_68 ) ;
} else
F_15 ( V_65 , V_68 ) ;
break;
case V_137 :
break;
case V_254 :
F_203 ( V_65 , V_455 ) ;
break;
case V_456 :
default:
if ( ( F_6 ( V_38 -> V_36 ) & V_270 ) &&
F_6 ( V_38 -> error ) == V_271 )
V_445 += F_203 ( V_65 , V_457 ) ;
else if ( V_65 -> V_401 )
V_445 += F_203 ( V_65 , V_457 ) ;
else if ( F_11 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) )
V_445 += F_203 ( V_65 , V_455 ) ;
else
F_15 ( V_65 , V_68 ) ;
F_207 ( V_65 , V_445 , L_65 ,
F_9 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) ,
V_38 -> V_36 , V_38 -> error , V_36 ) ;
break;
} ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_44 ( V_2 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void V_455 ( struct V_64 * V_65 )
{
struct V_441 * V_442 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_446 >= V_458 )
return;
F_64 ( & V_65 -> V_150 ) ;
V_2 = F_100 ( V_4 ) ;
V_4 -> V_446 ++ ;
F_103 ( V_2 , F_205 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_442 = & V_2 -> V_7 . V_442 ;
memset ( V_442 , 0 , sizeof( * V_442 ) ) ;
V_442 -> V_295 . V_296 = F_89 ( 1 ) ;
V_442 -> V_295 . V_32 = F_89 ( V_459 ) ;
V_442 -> V_295 . V_298 = F_52 ( sizeof( * V_442 ) ) ;
V_442 -> V_24 = F_90 ( V_65 -> V_24 ) ;
V_442 -> V_444 . type = V_278 ;
V_442 -> V_444 . V_39 = F_52 ( V_449 ) ;
V_442 -> V_444 . V_448 = F_89 ( V_453 ) ;
V_442 -> V_444 . V_448 |= F_89 ( V_460 ) ;
if ( V_233 )
V_442 -> V_444 . V_448 |= F_89 ( V_461 ) ;
F_15 ( V_65 , V_462 ) ;
if ( F_115 ( V_2 , V_4 , V_302 ) ) {
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
} else
F_206 ( V_65 , L_66 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_303 * V_38 = & V_2 -> V_33 -> V_304 ;
T_3 V_36 = F_6 ( V_38 -> V_295 . V_36 ) ;
int V_445 = V_237 ;
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
switch ( V_36 ) {
case V_361 :
F_206 ( V_65 , L_67 ) ;
if ( V_65 -> V_173 . V_175 &&
V_65 -> V_173 . V_175 != F_209 ( V_38 -> V_448 . V_175 ) ) {
V_4 -> V_90 = 1 ;
F_206 ( V_65 , L_68 ) ;
break;
}
V_65 -> V_173 . V_174 = F_209 ( V_38 -> V_448 . V_174 ) ;
V_65 -> V_173 . V_175 = F_209 ( V_38 -> V_448 . V_175 ) ;
V_65 -> V_173 . V_283 = V_65 -> V_24 ;
memcpy ( & V_65 -> V_448 , & V_38 -> V_448 ,
sizeof( V_65 -> V_448 ) ) ;
memcpy ( & V_65 -> V_463 , & V_38 -> V_463 ,
sizeof( V_65 -> V_463 ) ) ;
F_202 ( V_65 , V_455 ) ;
break;
case V_137 :
break;
case V_254 :
F_203 ( V_65 , V_457 ) ;
break;
case V_456 :
default:
if ( F_11 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) )
V_445 += F_203 ( V_65 , V_457 ) ;
else
F_15 ( V_65 , V_68 ) ;
F_207 ( V_65 , V_445 , L_69 ,
F_9 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) , V_38 -> V_36 , V_38 -> error ,
F_14 ( F_6 ( V_38 -> V_62 ) ) , V_38 -> V_62 ,
F_12 ( F_6 ( V_38 -> V_59 ) ) , V_38 -> V_59 , V_36 ) ;
break;
} ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_44 ( V_2 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void V_457 ( struct V_64 * V_65 )
{
struct V_303 * V_304 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_446 >= V_458 )
return;
F_64 ( & V_65 -> V_150 ) ;
V_65 -> V_401 = 0 ;
V_2 = F_100 ( V_4 ) ;
V_4 -> V_446 ++ ;
F_15 ( V_65 , V_462 ) ;
F_103 ( V_2 , F_208 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_304 = & V_2 -> V_7 . V_304 ;
memset ( V_304 , 0 , sizeof( * V_304 ) ) ;
V_304 -> V_295 . V_296 = F_89 ( 1 ) ;
V_304 -> V_295 . V_32 = F_89 ( V_310 ) ;
V_304 -> V_295 . V_298 = F_52 ( sizeof( * V_304 ) ) ;
V_304 -> V_24 = F_90 ( V_65 -> V_24 ) ;
if ( F_115 ( V_2 , V_4 , V_302 ) ) {
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
} else
F_206 ( V_65 , L_70 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_464 * V_38 = & V_2 -> V_33 -> V_465 ;
T_3 V_36 = F_6 ( V_38 -> V_295 . V_36 ) ;
V_4 -> V_446 -- ;
F_44 ( V_2 ) ;
F_15 ( V_65 , V_447 ) ;
switch ( V_36 ) {
case V_361 :
F_206 ( V_65 , L_71 ) ;
break;
case V_137 :
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_20 ( & V_4 -> V_91 ) ;
return;
case V_456 :
default:
F_211 ( V_65 , L_72 , V_36 ) ;
break;
} ;
if ( V_4 -> V_67 == V_83 )
F_202 ( V_65 , V_457 ) ;
else if ( V_4 -> V_67 == V_87 &&
V_65 -> V_24 != V_65 -> V_466 )
F_15 ( V_65 , V_68 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void F_212 ( struct V_64 * V_65 )
{
struct V_464 * V_10 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_446 >= V_458 )
return;
F_64 ( & V_65 -> V_150 ) ;
V_2 = F_100 ( V_4 ) ;
V_4 -> V_446 ++ ;
F_103 ( V_2 , F_210 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_10 = & V_2 -> V_7 . V_465 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_467 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( * V_10 ) ) ;
V_10 -> V_468 = F_90 ( V_65 -> V_24 ) ;
F_15 ( V_65 , V_462 ) ;
if ( F_115 ( V_2 , V_4 , V_302 ) ) {
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
} else
F_206 ( V_65 , L_73 ) ;
}
static int F_213 ( struct V_312 * V_10 ,
struct V_64 * V_65 )
{
if ( memcmp ( & V_10 -> V_345 . V_469 [ 2 ] , & V_65 -> V_173 . V_175 ,
sizeof( V_65 -> V_173 . V_175 ) ) )
return 1 ;
if ( memcmp ( & V_10 -> V_345 . V_469 [ 4 ] , & V_65 -> V_173 . V_174 ,
sizeof( V_65 -> V_173 . V_174 ) ) )
return 1 ;
if ( F_4 ( V_10 -> V_345 . V_469 [ 6 ] ) != V_65 -> V_24 )
return 1 ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_312 * V_10 = & V_2 -> V_33 -> V_343 ;
T_3 V_36 = F_6 ( V_10 -> V_295 . V_36 ) ;
T_4 V_470 , V_59 ;
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
F_54 ( & V_65 -> V_138 ) ;
switch ( V_36 ) {
case V_361 :
F_206 ( V_65 , L_74 ) ;
if ( F_213 ( V_10 , V_65 ) )
F_15 ( V_65 , V_68 ) ;
break;
case V_137 :
break;
case V_456 :
default:
F_15 ( V_65 , V_68 ) ;
V_470 = ( F_4 ( V_10 -> V_345 . V_469 [ 1 ] ) & 0x00ff0000 ) >> 16 ;
V_59 = ( F_4 ( V_10 -> V_345 . V_469 [ 1 ] ) & 0x0000ff00 ) >> 8 ;
F_215 ( V_65 , L_75 ,
F_9 ( F_6 ( V_10 -> V_7 . V_36 ) , F_6 ( V_10 -> V_7 . error ) ) ,
V_10 -> V_7 . V_36 , V_10 -> V_7 . error ,
F_14 ( V_470 ) , V_470 ,
F_12 ( V_59 ) , V_59 , V_36 ) ;
break;
} ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_44 ( V_2 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_312 * V_10 = & V_2 -> V_7 . V_343 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_344 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( * V_10 ) - sizeof( V_10 -> V_345 ) - sizeof( V_10 -> V_7 ) ) ;
V_10 -> V_346 . V_207 = F_90 ( ( T_2 ) F_2 ( V_2 -> V_18 . V_218 ) +
F_131 ( struct V_312 , V_7 ) ) ;
V_10 -> V_346 . V_208 = F_89 ( sizeof( V_10 -> V_7 ) ) ;
V_10 -> V_7 . V_284 = F_89 ( sizeof( V_10 -> V_345 . V_471 ) ) ;
V_10 -> V_7 . V_258 = F_89 ( sizeof( V_10 -> V_345 . V_469 ) ) ;
V_10 -> V_7 . V_8 . V_207 = F_90 ( ( T_2 ) F_2 ( V_2 -> V_18 . V_218 ) +
F_131 ( struct V_312 , V_345 ) +
F_131 ( struct V_472 , V_471 ) ) ;
V_10 -> V_7 . V_8 . V_208 = F_89 ( sizeof( V_10 -> V_345 . V_471 ) ) ;
V_10 -> V_7 . V_38 . V_207 = F_90 ( ( T_2 ) F_2 ( V_2 -> V_18 . V_218 ) +
F_131 ( struct V_312 , V_345 ) +
F_131 ( struct V_472 , V_469 ) ) ;
V_10 -> V_7 . V_38 . V_208 = F_89 ( sizeof( V_10 -> V_345 . V_469 ) ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_64 * V_65 = V_2 -> V_65 ;
F_206 ( V_65 , L_76 ) ;
V_4 -> V_473 -- ;
F_44 ( V_2 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void F_218 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
struct V_293 * V_294 ;
unsigned long V_39 ;
int V_47 ;
F_206 ( V_65 , L_77 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_4 -> V_473 >= V_458 ||
V_65 -> V_67 != V_462 ||
V_4 -> V_72 != V_88 ||
V_4 -> V_67 != V_87 ) {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return;
}
V_4 -> V_473 ++ ;
F_64 ( & V_65 -> V_150 ) ;
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , F_217 , V_31 ) ;
V_2 -> V_65 = V_65 ;
V_294 = & V_2 -> V_7 . V_294 ;
memset ( V_294 , 0 , sizeof( * V_294 ) ) ;
V_294 -> V_295 . V_296 = F_89 ( 1 ) ;
V_294 -> V_295 . V_32 = F_89 ( V_297 ) ;
V_294 -> V_295 . V_298 = F_52 ( sizeof( * V_294 ) ) ;
V_294 -> V_24 = F_90 ( V_65 -> V_24 ) ;
V_294 -> V_281 = F_89 ( V_65 -> V_281 ) ;
V_47 = F_115 ( V_2 , V_4 , V_302 ) ;
if ( V_47 ) {
F_211 ( V_65 , L_78 , V_47 ) ;
V_4 -> V_473 -- ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_58 ( V_4 ) ;
} else
F_206 ( V_65 , L_79 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_219 ( struct V_64 * V_65 )
{
struct V_312 * V_10 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_446 >= V_458 )
return;
F_64 ( & V_65 -> V_150 ) ;
V_2 = F_100 ( V_4 ) ;
V_4 -> V_446 ++ ;
F_103 ( V_2 , F_214 , V_31 ) ;
V_2 -> V_65 = V_65 ;
F_216 ( V_2 ) ;
V_10 = & V_2 -> V_7 . V_343 ;
V_10 -> V_7 . V_39 = F_89 ( V_329 ) ;
V_10 -> V_7 . V_24 = F_90 ( V_65 -> V_24 ) ;
V_10 -> V_7 . V_281 = F_89 ( V_65 -> V_281 ) ;
V_10 -> V_345 . V_471 [ 0 ] = F_89 ( V_474 ) ;
memcpy ( & V_10 -> V_345 . V_471 [ 2 ] , & V_4 -> V_152 -> V_153 . V_175 ,
sizeof( V_4 -> V_152 -> V_153 . V_175 ) ) ;
memcpy ( & V_10 -> V_345 . V_471 [ 4 ] , & V_4 -> V_152 -> V_153 . V_174 ,
sizeof( V_4 -> V_152 -> V_153 . V_174 ) ) ;
V_10 -> V_345 . V_471 [ 6 ] = F_89 ( F_2 ( V_4 -> V_152 -> V_153 . V_24 ) & 0x00ffffff ) ;
if ( F_220 ( & V_65 -> V_138 ) )
F_221 ( & V_65 -> V_138 , V_16 + ( V_475 * V_178 ) ) ;
else {
V_65 -> V_138 . V_41 = ( unsigned long ) V_65 ;
V_65 -> V_138 . V_251 = V_16 + ( V_475 * V_178 ) ;
V_65 -> V_138 . V_252 = ( void (*) ( unsigned long ) ) F_218 ;
F_118 ( & V_65 -> V_138 ) ;
}
F_15 ( V_65 , V_462 ) ;
if ( F_115 ( V_2 , V_4 , V_476 ) ) {
V_4 -> V_446 -- ;
F_54 ( & V_65 -> V_138 ) ;
F_15 ( V_65 , V_447 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
} else
F_206 ( V_65 , L_80 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_477 * V_38 = & V_2 -> V_33 -> V_478 ;
T_3 V_36 = F_6 ( V_38 -> V_295 . V_36 ) ;
int V_445 = V_237 ;
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
switch ( V_36 ) {
case V_361 :
F_206 ( V_65 , L_81 ) ;
V_65 -> V_466 = F_2 ( V_38 -> V_24 ) ;
if ( F_2 ( V_38 -> V_24 ) != V_65 -> V_24 )
F_202 ( V_65 , F_212 ) ;
else
F_202 ( V_65 , F_219 ) ;
break;
case V_137 :
break;
case V_254 :
F_203 ( V_65 , V_479 ) ;
break;
case V_456 :
default:
if ( ( F_6 ( V_38 -> V_36 ) & V_480 ) == V_480 &&
F_6 ( V_38 -> error ) == V_481 &&
F_6 ( V_38 -> V_59 ) == V_482 )
F_15 ( V_65 , V_68 ) ;
else if ( F_11 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) )
V_445 += F_203 ( V_65 , V_479 ) ;
else
F_15 ( V_65 , V_68 ) ;
F_207 ( V_65 , V_445 , L_82 ,
F_9 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) ,
V_38 -> V_36 , V_38 -> error , F_14 ( F_6 ( V_38 -> V_62 ) ) ,
V_38 -> V_62 , F_13 ( F_6 ( V_38 -> V_59 ) ) ,
V_38 -> V_59 , V_36 ) ;
break;
} ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_44 ( V_2 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void V_479 ( struct V_64 * V_65 )
{
struct V_477 * V_478 ;
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_1 * V_2 ;
if ( V_4 -> V_446 >= V_458 )
return;
F_64 ( & V_65 -> V_150 ) ;
V_2 = F_100 ( V_4 ) ;
V_4 -> V_446 ++ ;
V_2 -> V_65 = V_65 ;
F_103 ( V_2 , F_222 , V_31 ) ;
V_478 = & V_2 -> V_7 . V_478 ;
memset ( V_478 , 0 , sizeof( * V_478 ) ) ;
V_478 -> V_295 . V_296 = F_89 ( 1 ) ;
V_478 -> V_295 . V_32 = F_89 ( V_483 ) ;
V_478 -> V_295 . V_298 = F_52 ( sizeof( * V_478 ) ) ;
V_478 -> V_383 = F_90 ( V_65 -> V_173 . V_175 ) ;
F_15 ( V_65 , V_462 ) ;
if ( F_115 ( V_2 , V_4 , V_302 ) ) {
V_4 -> V_446 -- ;
F_15 ( V_65 , V_447 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
} else
F_206 ( V_65 , L_83 ) ;
}
static int F_223 ( struct V_3 * V_4 , T_2 V_24 )
{
struct V_64 * V_65 ;
unsigned long V_39 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_24 == V_24 ) {
if ( V_65 -> V_400 )
F_202 ( V_65 , F_212 ) ;
goto V_308;
}
}
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_65 = F_224 ( V_4 -> V_484 , V_485 ) ;
if ( ! V_65 ) {
F_24 ( V_4 -> V_98 , L_84 ,
V_24 ) ;
return - V_214 ;
}
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
V_65 -> V_24 = V_24 ;
V_65 -> V_466 = V_24 ;
V_65 -> V_4 = V_4 ;
V_65 -> V_400 = 1 ;
V_65 -> V_281 = V_4 -> V_416 ++ ;
F_117 ( & V_65 -> V_138 ) ;
F_225 ( & V_65 -> V_150 ) ;
F_202 ( V_65 , F_212 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_47 ( & V_65 -> V_130 , & V_4 -> V_486 ) ;
V_308:
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
static int F_226 ( struct V_3 * V_4 )
{
int V_44 , V_47 ;
for ( V_44 = 0 , V_47 = 0 ; ! V_47 && V_44 < V_4 -> V_487 ; V_44 ++ )
V_47 = F_223 ( V_4 ,
F_4 ( V_4 -> V_488 -> V_24 [ V_44 ] ) &
V_489 ) ;
return V_47 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_490 * V_38 = & V_2 -> V_33 -> V_491 ;
T_3 V_492 = F_6 ( V_38 -> V_295 . V_36 ) ;
int V_445 = V_237 ;
switch ( V_492 ) {
case V_361 :
F_29 ( V_4 , L_85 ) ;
V_4 -> V_487 = F_4 ( V_38 -> V_493 ) ;
F_17 ( V_4 , V_75 ) ;
break;
case V_456 :
V_445 += F_60 ( V_4 ) ;
F_68 ( V_4 , V_445 , L_86 ,
F_9 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) ,
V_38 -> V_36 , V_38 -> error ) ;
break;
case V_137 :
break;
default:
F_24 ( V_4 -> V_98 , L_87 , V_492 ) ;
F_21 ( V_4 , V_164 ) ;
break;
}
F_44 ( V_2 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void V_490 ( struct V_3 * V_4 )
{
struct V_490 * V_10 ;
struct V_1 * V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , F_227 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_491 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_494 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( * V_10 ) ) ;
V_10 -> V_495 = F_89 ( V_4 -> V_496 ) ;
V_10 -> V_497 . V_207 = F_90 ( V_4 -> V_498 ) ;
V_10 -> V_497 . V_208 = F_89 ( V_4 -> V_496 ) ;
F_17 ( V_4 , V_76 ) ;
if ( ! F_115 ( V_2 , V_4 , V_302 ) )
F_29 ( V_4 , L_88 ) ;
else
F_21 ( V_4 , V_164 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_492 = F_6 ( V_2 -> V_33 -> V_499 . V_295 . V_36 ) ;
struct V_500 * V_38 = & V_4 -> V_152 -> V_153 ;
unsigned int V_501 ;
int V_445 = V_237 ;
switch ( V_492 ) {
case V_361 :
F_44 ( V_2 ) ;
break;
case V_456 :
if ( F_11 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) )
V_445 += F_60 ( V_4 ) ;
else
F_21 ( V_4 , V_164 ) ;
F_68 ( V_4 , V_445 , L_89 ,
F_9 ( F_6 ( V_38 -> V_36 ) , F_6 ( V_38 -> error ) ) ,
V_38 -> V_36 , V_38 -> error ) ;
F_44 ( V_2 ) ;
return;
case V_254 :
F_60 ( V_4 ) ;
case V_137 :
F_44 ( V_2 ) ;
return;
default:
F_24 ( V_4 -> V_98 , L_90 , V_492 ) ;
F_21 ( V_4 , V_164 ) ;
F_44 ( V_2 ) ;
return;
}
V_4 -> V_199 = 0 ;
if ( ! ( F_4 ( V_38 -> V_39 ) & V_502 ) ) {
F_24 ( V_4 -> V_98 , L_91 ,
V_38 -> V_39 ) ;
F_21 ( V_4 , V_164 ) ;
F_20 ( & V_4 -> V_91 ) ;
return;
}
if ( F_4 ( V_38 -> V_201 ) <= V_203 ) {
F_24 ( V_4 -> V_98 , L_92 ,
V_38 -> V_201 ) ;
F_21 ( V_4 , V_164 ) ;
F_20 ( & V_4 -> V_91 ) ;
return;
}
V_4 -> V_117 = 1 ;
V_501 = F_229 ( ( V_503 ) ( F_2 ( V_38 -> V_190 ) >> 9 ) , V_191 ) ;
F_135 ( V_4 -> V_98 , L_93 ,
V_38 -> V_183 , V_38 -> V_210 , V_38 -> V_424 ,
V_38 -> V_212 , V_501 ) ;
F_230 ( V_4 -> V_89 ) = F_2 ( V_38 -> V_174 ) ;
F_231 ( V_4 -> V_89 ) = F_2 ( V_38 -> V_174 ) ;
F_232 ( V_4 -> V_89 ) = F_2 ( V_38 -> V_175 ) ;
F_233 ( V_4 -> V_89 ) = F_2 ( V_38 -> V_24 ) ;
F_234 ( V_4 -> V_89 ) = V_504 ;
F_235 ( V_4 -> V_89 ) = 0 ;
if ( F_4 ( V_38 -> V_448 . V_505 [ 0 ] ) & 0x80000000 )
F_235 ( V_4 -> V_89 ) |= V_506 ;
if ( F_4 ( V_38 -> V_448 . V_507 [ 0 ] ) & 0x80000000 )
F_235 ( V_4 -> V_89 ) |= V_508 ;
if ( F_4 ( V_38 -> V_448 . V_509 [ 0 ] ) & 0x80000000 )
F_235 ( V_4 -> V_89 ) |= V_510 ;
F_236 ( V_4 -> V_89 ) =
F_6 ( V_38 -> V_448 . V_295 . V_511 ) & 0x0fff ;
V_4 -> V_89 -> V_512 = F_4 ( V_38 -> V_201 ) - V_203 ;
V_4 -> V_89 -> V_513 = V_501 ;
F_17 ( V_4 , V_80 ) ;
F_20 ( & V_4 -> V_91 ) ;
}
static void V_104 ( struct V_3 * V_4 )
{
struct V_514 * V_10 ;
struct V_1 * V_2 = F_100 ( V_4 ) ;
F_84 ( V_4 ) ;
F_88 ( V_4 ) ;
F_103 ( V_2 , F_228 , V_31 ) ;
memcpy ( V_4 -> V_152 , & V_4 -> V_185 , sizeof( V_4 -> V_185 ) ) ;
V_10 = & V_2 -> V_7 . V_499 ;
memset ( V_10 , 0 , sizeof( struct V_514 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_515 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( struct V_514 ) ) ;
V_10 -> V_497 . V_207 = F_90 ( V_4 -> V_516 ) ;
V_10 -> V_497 . V_208 = F_89 ( sizeof( * V_4 -> V_152 ) ) ;
F_17 ( V_4 , V_76 ) ;
if ( ! F_115 ( V_2 , V_4 , V_302 ) )
F_29 ( V_4 , L_94 ) ;
else
F_21 ( V_4 , V_164 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_492 = F_6 ( V_2 -> V_33 -> V_517 . V_295 . V_36 ) ;
F_44 ( V_2 ) ;
switch ( V_492 ) {
case V_361 :
if ( F_101 ( & V_4 -> V_250 ) &&
V_4 -> V_67 == V_77 ) {
F_23 ( V_4 ) ;
return;
}
break;
case V_456 :
case V_518 :
case V_254 :
case V_137 :
default:
F_29 ( V_4 , L_95 , V_492 ) ;
break;
}
F_57 ( V_4 ) ;
}
static void V_141 ( struct V_3 * V_4 )
{
struct V_519 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_100 ( V_4 ) ;
F_103 ( V_2 , F_237 , V_31 ) ;
V_10 = & V_2 -> V_7 . V_517 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_295 . V_296 = F_89 ( 1 ) ;
V_10 -> V_295 . V_32 = F_89 ( V_520 ) ;
V_10 -> V_295 . V_298 = F_52 ( sizeof( struct V_519 ) ) ;
F_17 ( V_4 , V_77 ) ;
if ( ! F_115 ( V_2 , V_4 , V_302 ) )
F_29 ( V_4 , L_96 ) ;
else
F_21 ( V_4 , V_164 ) ;
}
static int F_238 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_438 ||
V_65 -> V_67 == V_462 )
return 1 ;
}
return 0 ;
}
static int F_239 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
if ( F_240 () )
return 1 ;
switch ( V_4 -> V_67 ) {
case V_81 :
case V_76 :
case V_77 :
return 0 ;
case V_83 :
case V_87 :
if ( V_4 -> V_446 == V_458 )
return 0 ;
F_22 (tgt, &vhost->targets, queue)
if ( V_65 -> V_67 == V_438 )
return 1 ;
F_22 (tgt, &vhost->targets, queue)
if ( V_65 -> V_67 == V_462 )
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
static int F_241 ( struct V_3 * V_4 )
{
unsigned long V_39 ;
int V_47 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_239 ( V_4 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return V_47 ;
}
static void F_242 ( struct V_3 * V_4 , int V_128 )
{
if ( V_128 & V_394 )
F_243 ( V_4 -> V_89 , F_244 () , V_521 , 0 ) ;
if ( ( V_128 & V_94 ) &&
V_4 -> V_72 >= V_166 )
F_243 ( V_4 -> V_89 , F_244 () , V_522 , 0 ) ;
if ( ( V_128 & V_390 ) &&
V_4 -> V_72 == V_88 )
F_243 ( V_4 -> V_89 , F_244 () , V_523 , 0 ) ;
}
static void F_245 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = V_65 -> V_4 ;
struct V_169 * V_170 ;
unsigned long V_39 ;
F_206 ( V_65 , L_97 ) ;
V_170 = F_246 ( V_4 -> V_89 , 0 , & V_65 -> V_173 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_170 && V_65 -> V_67 == V_68 ) {
F_206 ( V_65 , L_98 ) ;
F_53 ( & V_65 -> V_130 ) ;
F_15 ( V_65 , V_69 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_247 ( V_170 ) ;
F_248 ( & V_65 -> V_138 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
return;
} else if ( V_170 && V_65 -> V_67 == V_69 ) {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return;
}
if ( V_170 ) {
F_206 ( V_65 , L_99 ) ;
V_65 -> V_170 = V_170 ;
V_170 -> V_524 = F_6 ( V_65 -> V_448 . V_295 . V_511 ) & 0x0fff ;
V_170 -> V_525 = 0 ;
V_65 -> V_148 = V_170 -> V_526 ;
if ( F_4 ( V_65 -> V_448 . V_505 [ 0 ] ) & 0x80000000 )
V_170 -> V_525 |= V_506 ;
if ( F_4 ( V_65 -> V_448 . V_507 [ 0 ] ) & 0x80000000 )
V_170 -> V_525 |= V_508 ;
if ( F_4 ( V_65 -> V_448 . V_509 [ 0 ] ) & 0x80000000 )
V_170 -> V_525 |= V_510 ;
if ( V_170 -> V_527 )
F_249 ( V_170 -> V_527 , 1 ) ;
} else
F_206 ( V_65 , L_100 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static void F_250 ( struct V_3 * V_4 )
{
struct V_64 * V_65 ;
unsigned long V_39 ;
struct V_169 * V_170 ;
int V_47 ;
F_242 ( V_4 , V_4 -> V_93 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_4 -> V_93 = 0 ;
switch ( V_4 -> V_67 ) {
case V_81 :
case V_77 :
case V_76 :
break;
case V_85 :
V_4 -> V_67 = V_84 ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_39 ( V_4 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 == V_124 )
F_201 ( F_26 ( V_4 -> V_98 ) ) ;
if ( V_47 || ( V_47 = F_28 ( V_4 ) ) ||
( V_47 = F_201 ( F_26 ( V_4 -> V_98 ) ) ) ) {
F_21 ( V_4 , V_164 ) ;
F_24 ( V_4 -> V_98 , L_101 , V_47 ) ;
}
break;
case V_86 :
V_4 -> V_67 = V_84 ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_47 = F_38 ( V_4 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_47 || ( V_47 = F_28 ( V_4 ) ) ) {
F_21 ( V_4 , V_164 ) ;
F_24 ( V_4 -> V_98 , L_102 , V_47 ) ;
}
break;
case V_78 :
V_4 -> V_103 ( V_4 ) ;
break;
case V_79 :
F_45 ( V_4 -> V_72 != V_88 ) ;
if ( V_4 -> V_142 ) {
V_4 -> V_142 = 0 ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_251 ( 15 ) ;
return;
} else
V_4 -> V_103 ( V_4 ) ;
break;
case V_80 :
F_22 (tgt, &vhost->targets, queue)
F_202 ( V_65 , V_479 ) ;
F_17 ( V_4 , V_87 ) ;
break;
case V_87 :
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_438 ) {
V_65 -> V_103 ( V_65 ) ;
break;
}
}
if ( ! F_238 ( V_4 ) )
F_17 ( V_4 , V_84 ) ;
break;
case V_84 :
case V_82 :
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_68 ) {
F_206 ( V_65 , L_98 ) ;
V_170 = V_65 -> V_170 ;
V_65 -> V_170 = NULL ;
F_53 ( & V_65 -> V_130 ) ;
F_15 ( V_65 , V_69 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
if ( V_170 )
F_247 ( V_170 ) ;
F_248 ( & V_65 -> V_138 ) ;
F_77 ( & V_65 -> V_150 , F_72 ) ;
return;
}
}
if ( V_4 -> V_72 == V_88 ) {
if ( V_4 -> V_67 == V_82 ) {
if ( V_4 -> V_90 ) {
V_4 -> V_90 = 0 ;
F_19 ( V_4 -> V_89 ) ;
F_17 ( V_4 , V_80 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
} else {
F_16 ( V_4 , V_151 ) ;
F_17 ( V_4 , V_81 ) ;
F_20 ( & V_4 -> V_176 ) ;
F_252 ( & V_4 -> V_528 ) ;
V_4 -> V_96 = 0 ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_253 ( V_4 -> V_89 ) ;
}
return;
} else {
F_17 ( V_4 , V_79 ) ;
V_4 -> V_103 = V_490 ;
}
} else {
F_17 ( V_4 , V_81 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_253 ( V_4 -> V_89 ) ;
F_20 ( & V_4 -> V_176 ) ;
return;
}
break;
case V_75 :
F_17 ( V_4 , V_83 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_226 ( V_4 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
break;
case V_83 :
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_67 == V_438 ) {
V_65 -> V_103 ( V_65 ) ;
break;
}
}
if ( ! F_238 ( V_4 ) )
F_17 ( V_4 , V_82 ) ;
break;
default:
break;
} ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
static int F_254 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
int V_47 ;
F_255 ( V_529 , V_530 ) ;
while ( 1 ) {
V_47 = F_256 ( V_4 -> V_91 ,
F_241 ( V_4 ) ) ;
F_45 ( V_47 ) ;
if ( F_240 () )
break;
F_250 ( V_4 ) ;
}
F_29 ( V_4 , L_103 ) ;
return 0 ;
}
static int F_257 ( struct V_3 * V_4 )
{
int V_47 , V_531 = - V_214 ;
struct V_231 * V_98 = V_4 -> V_98 ;
struct V_107 * V_108 = F_26 ( V_98 ) ;
struct V_111 * V_18 = & V_4 -> V_18 ;
V_92 ;
V_18 -> V_100 = (struct V_406 * ) F_258 ( V_213 ) ;
if ( ! V_18 -> V_100 )
return - V_214 ;
V_18 -> V_129 = V_101 / sizeof( * V_18 -> V_100 ) ;
V_18 -> V_118 = F_259 ( V_98 , V_18 -> V_100 ,
V_101 , V_119 ) ;
if ( F_260 ( V_98 , V_18 -> V_118 ) )
goto V_532;
V_531 = V_47 = F_27 ( V_123 , V_108 -> V_110 ,
V_18 -> V_118 , V_101 ) ;
if ( V_47 == V_533 )
V_531 = V_47 = F_39 ( V_4 ) ;
if ( V_47 == V_124 )
F_41 ( V_98 , L_6 ) ;
else if ( V_47 ) {
F_41 ( V_98 , L_104 , V_47 ) ;
goto V_534;
}
V_531 = 0 ;
F_261 ( & V_4 -> V_113 , ( void * ) F_199 , ( unsigned long ) V_4 ) ;
if ( ( V_47 = F_262 ( V_108 -> V_112 , F_196 , 0 , V_535 , V_4 ) ) ) {
F_24 ( V_98 , L_105 , V_108 -> V_112 , V_47 ) ;
goto V_536;
}
if ( ( V_47 = F_201 ( V_108 ) ) ) {
F_24 ( V_98 , L_106 , V_47 ) ;
goto V_536;
}
V_18 -> V_102 = 0 ;
V_95 ;
return V_531 ;
V_536:
F_33 ( & V_4 -> V_113 ) ;
do {
V_47 = F_27 ( V_114 , V_108 -> V_110 ) ;
} while ( V_47 == V_115 || F_35 ( V_47 ) );
V_534:
F_36 ( V_98 , V_18 -> V_118 , V_101 , V_119 ) ;
V_532:
F_37 ( ( unsigned long ) V_18 -> V_100 ) ;
return V_531 ;
}
static void F_263 ( struct V_3 * V_4 )
{
struct V_435 * V_537 = & V_4 -> V_99 ;
V_92 ;
F_264 ( V_4 -> V_484 ) ;
F_74 ( V_4 -> V_14 ) ;
F_99 ( V_4 -> V_98 , V_4 -> V_496 , V_4 -> V_488 ,
V_4 -> V_498 ) ;
F_99 ( V_4 -> V_98 , sizeof( * V_4 -> V_152 ) ,
V_4 -> V_152 , V_4 -> V_516 ) ;
F_265 ( V_4 -> V_220 ) ;
F_36 ( V_4 -> V_98 , V_537 -> V_118 ,
V_537 -> V_129 * sizeof( * V_537 -> V_100 ) , V_119 ) ;
F_37 ( ( unsigned long ) V_537 -> V_100 ) ;
V_95 ;
}
static int F_266 ( struct V_3 * V_4 )
{
struct V_435 * V_537 = & V_4 -> V_99 ;
struct V_231 * V_98 = V_4 -> V_98 ;
V_92 ;
V_537 -> V_100 = (struct V_381 * ) F_258 ( V_213 ) ;
if ( ! V_537 -> V_100 ) {
F_24 ( V_98 , L_107 ) ;
goto V_538;
}
V_537 -> V_129 = V_101 / sizeof( struct V_381 ) ;
V_537 -> V_118 = F_259 ( V_98 , V_537 -> V_100 ,
V_537 -> V_129 * sizeof( * V_537 -> V_100 ) ,
V_119 ) ;
if ( F_260 ( V_98 , V_537 -> V_118 ) ) {
F_24 ( V_98 , L_108 ) ;
goto V_539;
}
V_4 -> V_220 = F_267 ( V_535 , V_98 ,
V_540 * sizeof( struct V_226 ) ,
sizeof( struct V_226 ) , 0 ) ;
if ( ! V_4 -> V_220 ) {
F_24 ( V_98 , L_109 ) ;
goto V_541;
}
V_4 -> V_152 = F_94 ( V_98 , sizeof( * V_4 -> V_152 ) ,
& V_4 -> V_516 , V_213 ) ;
if ( ! V_4 -> V_152 ) {
F_24 ( V_98 , L_110 ) ;
goto V_542;
}
V_4 -> V_496 = sizeof( V_4 -> V_488 -> V_24 [ 0 ] ) * V_543 ;
V_4 -> V_488 = F_94 ( V_98 , V_4 -> V_496 ,
& V_4 -> V_498 , V_213 ) ;
if ( ! V_4 -> V_488 ) {
F_24 ( V_98 , L_111 ) ;
goto V_544;
}
V_4 -> V_14 = F_93 ( V_545 ,
sizeof( struct V_12 ) , V_213 ) ;
if ( ! V_4 -> V_14 )
goto V_546;
V_4 -> V_484 = F_268 ( V_547 ,
sizeof( struct V_64 ) ) ;
if ( ! V_4 -> V_484 ) {
F_24 ( V_98 , L_112 ) ;
goto V_548;
}
V_95 ;
return 0 ;
V_548:
F_74 ( V_4 -> V_14 ) ;
V_546:
F_99 ( V_98 , V_4 -> V_496 , V_4 -> V_488 ,
V_4 -> V_498 ) ;
V_544:
F_99 ( V_98 , sizeof( * V_4 -> V_152 ) ,
V_4 -> V_152 , V_4 -> V_516 ) ;
V_542:
F_265 ( V_4 -> V_220 ) ;
V_541:
F_36 ( V_98 , V_537 -> V_118 ,
V_537 -> V_129 * sizeof( * V_537 -> V_100 ) , V_119 ) ;
V_539:
F_37 ( ( unsigned long ) V_537 -> V_100 ) ;
V_538:
V_95 ;
return - V_214 ;
}
static void F_269 ( struct V_549 * V_550 )
{
struct V_3 * V_4 = F_73 ( V_550 , struct V_3 ,
V_528 ) ;
struct V_64 * V_65 ;
struct V_169 * V_170 ;
unsigned long V_39 ;
int V_551 ;
V_92 ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
do {
V_551 = 0 ;
if ( V_4 -> V_72 != V_151 )
break;
F_22 (tgt, &vhost->targets, queue) {
if ( V_65 -> V_70 ) {
V_551 = 1 ;
V_65 -> V_70 = 0 ;
F_64 ( & V_65 -> V_150 ) ;
V_170 = V_65 -> V_170 ;
if ( ! V_170 ) {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_245 ( V_65 ) ;
} else if ( F_270 ( & V_170 -> V_98 ) ) {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_206 ( V_65 , L_113 ) ;
F_271 ( V_170 , V_65 -> V_173 . V_450 ) ;
F_272 ( & V_170 -> V_98 ) ;
} else {
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
}
F_77 ( & V_65 -> V_150 , F_72 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
break;
}
}
} while( V_551 );
if ( V_4 -> V_72 == V_151 )
V_4 -> V_414 = 1 ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
V_95 ;
}
static int F_273 ( struct V_107 * V_108 , const struct V_552 * V_149 )
{
struct V_3 * V_4 ;
struct V_145 * V_146 ;
struct V_231 * V_98 = & V_108 -> V_98 ;
int V_47 = - V_214 ;
V_92 ;
V_146 = F_274 ( & V_553 , sizeof( * V_4 ) ) ;
if ( ! V_146 ) {
F_24 ( V_98 , L_114 ) ;
goto V_342;
}
V_146 -> V_554 = V_555 ;
V_146 -> V_512 = V_202 ;
V_146 -> V_556 = V_556 ;
V_146 -> V_557 = V_543 ;
V_146 -> V_513 = V_191 ;
V_146 -> V_558 = V_559 ;
V_146 -> V_560 = V_146 -> V_561 ;
V_4 = F_63 ( V_146 ) ;
F_275 ( & V_4 -> V_250 ) ;
F_275 ( & V_4 -> free ) ;
F_275 ( & V_4 -> V_486 ) ;
sprintf ( V_4 -> V_48 , V_535 ) ;
V_4 -> V_89 = V_146 ;
V_4 -> V_98 = V_98 ;
V_4 -> V_184 = - 1 ;
V_4 -> V_236 = V_236 ;
V_4 -> V_416 = 1 ;
strcpy ( V_4 -> V_183 , L_115 ) ;
F_276 ( & V_4 -> V_91 ) ;
F_276 ( & V_4 -> V_176 ) ;
F_277 ( & V_4 -> V_528 , F_269 ) ;
F_278 ( & V_4 -> V_335 ) ;
if ( ( V_47 = F_266 ( V_4 ) ) )
goto V_562;
V_4 -> V_563 = F_279 ( F_254 , V_4 , L_116 , V_535 ,
V_146 -> V_561 ) ;
if ( F_280 ( V_4 -> V_563 ) ) {
F_24 ( V_98 , L_117 ,
F_281 ( V_4 -> V_563 ) ) ;
goto V_564;
}
if ( ( V_47 = F_257 ( V_4 ) ) ) {
F_24 ( V_98 , L_118 , V_47 ) ;
goto V_565;
}
if ( ( V_47 = F_92 ( V_4 ) ) ) {
F_24 ( V_98 , L_119 , V_47 ) ;
goto V_566;
}
if ( ( V_47 = F_282 ( V_146 , V_98 ) ) )
goto V_567;
F_283 ( V_146 ) = V_568 ;
if ( ( V_47 = F_284 ( & V_146 -> V_569 . V_429 ,
& V_570 ) ) ) {
F_24 ( V_98 , L_120 , V_47 ) ;
goto V_571;
}
if ( F_285 ( V_146 ) -> V_527 )
F_249 ( F_285 ( V_146 ) -> V_527 , 1 ) ;
F_286 ( V_98 , V_4 ) ;
F_287 ( & V_572 ) ;
F_47 ( & V_4 -> V_130 , & V_573 ) ;
F_288 ( & V_572 ) ;
F_28 ( V_4 ) ;
F_289 ( V_146 ) ;
return 0 ;
V_571:
F_290 ( V_146 ) ;
V_567:
F_96 ( V_4 ) ;
V_566:
F_31 ( V_4 ) ;
V_565:
F_291 ( V_4 -> V_563 ) ;
V_564:
F_263 ( V_4 ) ;
V_562:
F_292 ( V_146 ) ;
V_342:
V_95 ;
return V_47 ;
}
static int F_293 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = F_109 ( & V_108 -> V_98 ) ;
unsigned long V_39 ;
V_92 ;
F_294 ( & V_4 -> V_89 -> V_569 . V_429 , & V_570 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_21 ( V_4 , V_73 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_81 ( V_4 ) ;
F_31 ( V_4 ) ;
F_291 ( V_4 -> V_563 ) ;
F_295 ( V_4 -> V_89 ) ;
F_290 ( V_4 -> V_89 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_55 ( V_4 , V_55 ) ;
F_96 ( V_4 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_263 ( V_4 ) ;
F_287 ( & V_572 ) ;
F_53 ( & V_4 -> V_130 ) ;
F_288 ( & V_572 ) ;
F_292 ( V_4 -> V_89 ) ;
V_95 ;
return 0 ;
}
static int F_296 ( struct V_231 * V_98 )
{
unsigned long V_39 ;
struct V_3 * V_4 = F_109 ( V_98 ) ;
struct V_107 * V_108 = F_26 ( V_98 ) ;
F_40 ( V_4 -> V_89 -> V_122 , V_39 ) ;
F_197 ( V_108 ) ;
F_198 ( & V_4 -> V_113 ) ;
F_42 ( V_4 -> V_89 -> V_122 , V_39 ) ;
return 0 ;
}
static unsigned long F_297 ( struct V_107 * V_108 )
{
unsigned long V_574 = V_202 * sizeof( union V_305 ) ;
return V_574 + ( ( 512 * 1024 ) * V_553 . V_575 ) ;
}
static int T_10 F_298 ( void )
{
int V_47 ;
if ( ! F_299 ( V_576 ) )
return - V_577 ;
F_300 (KERN_INFO IBMVFC_NAMEL_121 ,
IBMVFC_DRIVER_VERSION, IBMVFC_DRIVER_DATE) ;
V_555 = F_301 ( & V_578 ) ;
if ( ! V_555 )
return - V_214 ;
V_47 = F_302 ( & V_579 ) ;
if ( V_47 )
F_303 ( V_555 ) ;
return V_47 ;
}
static void T_11 F_304 ( void )
{
F_305 ( & V_579 ) ;
F_303 ( V_555 ) ;
}
