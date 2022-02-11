int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
F_7 ( V_6 ) ;
return 0 ;
}
static struct V_7 * F_8 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_7 * V_10 = & V_9 -> V_10 ;
V_10 -> V_11 = F_10 ( V_9 , V_12 ) ;
V_10 -> V_13 = F_10 ( V_9 , V_14 ) ;
V_10 -> V_15 = F_10 ( V_9 , V_16 ) ;
V_10 -> V_17 = F_10 ( V_9 , V_18 ) ;
V_10 -> V_19 = F_10 ( V_9 , V_20 ) ;
return V_10 ;
}
static int F_11 ( struct V_5 * V_6 , void * V_21 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 = V_21 ;
T_1 V_24 [ V_25 ] ;
if ( ! F_12 ( V_23 -> V_26 ) )
return - V_27 ;
F_13 ( V_24 , V_6 -> V_28 ) ;
F_13 ( V_6 -> V_28 , V_23 -> V_26 ) ;
if ( F_14 ( & V_9 -> V_29 ) == V_30 ) {
F_15 ( V_9 , V_24 , V_31 ,
L_1 , false ) ;
F_16 ( V_6 , V_23 -> V_26 , V_31 ,
V_32 , V_33 ) ;
}
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , int V_34 )
{
if ( ( V_34 < 68 ) || ( V_34 > F_18 ( V_6 ) ) )
return - V_35 ;
V_6 -> V_36 = V_34 ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 )
{
}
static int F_20 ( struct V_1 * V_2 ,
struct V_5 * V_37 )
{
struct V_38 * V_38 ;
struct V_8 * V_9 = F_9 ( V_37 ) ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
T_2 V_43 = F_21 ( V_44 ) ;
static const T_1 V_45 [ V_25 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_46 [ V_25 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
enum V_47 V_48 = V_49 ;
T_1 * V_50 = NULL , V_51 [ V_25 ] ;
struct V_52 * V_53 ;
unsigned int V_54 = 0 ;
int V_55 = V_2 -> V_3 , V_56 ;
unsigned long V_57 = 1 ;
bool V_58 = false , V_59 ;
unsigned short V_60 ;
T_3 V_61 ;
int V_62 ;
enum V_63 V_64 ;
struct V_65 * V_66 = NULL ;
if ( F_14 ( & V_9 -> V_29 ) != V_30 )
goto V_67;
V_37 -> V_68 = V_69 ;
V_60 = F_22 ( V_2 , 0 ) ;
V_38 = F_23 ( V_2 ) ;
switch ( F_24 ( V_38 -> V_70 ) ) {
case V_71 :
V_53 = F_25 ( V_2 ) ;
if ( V_53 -> V_72 != V_43 )
break;
case V_44 :
goto V_67;
}
if ( F_26 ( V_9 , V_2 , V_60 ) )
goto V_67;
V_38 = F_23 ( V_2 ) ;
if ( ! F_27 ( V_38 -> V_73 ) ) {
V_59 = F_16 ( V_37 , V_38 -> V_73 ,
V_60 , V_2 -> V_74 ,
V_2 -> V_75 ) ;
if ( ! V_59 )
goto V_67;
}
if ( F_28 ( V_38 -> V_76 , V_45 ) )
goto V_67;
if ( F_28 ( V_38 -> V_76 , V_46 ) )
goto V_67;
V_62 = F_14 ( & V_9 -> V_62 ) ;
if ( F_27 ( V_38 -> V_76 ) ) {
if ( V_62 == V_77 ) {
V_58 = true ;
goto V_78;
}
V_48 = F_29 ( V_2 , & V_54 ,
V_51 ) ;
V_38 = F_23 ( V_2 ) ;
if ( V_48 == V_49 ) {
V_58 = true ;
goto V_78;
}
if ( V_48 == V_79 )
V_50 = V_51 ;
else if ( ( V_62 == V_80 ) &&
( V_48 == V_81 ) )
goto V_67;
V_78:
if ( V_58 && ! F_30 ( V_38 -> V_76 ) ) {
V_64 = F_31 ( V_9 , V_2 ,
& V_66 ) ;
if ( V_64 == V_82 )
goto V_67;
if ( V_64 == V_83 )
V_58 = false ;
}
}
F_32 ( V_2 , 0 ) ;
if ( V_58 ) {
V_40 = F_33 ( V_9 ) ;
if ( ! V_40 )
goto V_67;
if ( F_34 ( V_9 , V_2 ) )
V_57 = F_35 ( V_84 ) ;
if ( F_1 ( V_2 , sizeof( * V_42 ) ) < 0 )
goto V_67;
V_42 = (struct V_41 * ) V_2 -> V_85 ;
V_42 -> V_86 = V_87 ;
V_42 -> V_88 = V_89 ;
V_42 -> V_90 = V_91 ;
V_42 -> V_92 = 0 ;
F_13 ( V_42 -> V_93 ,
V_40 -> V_94 -> V_28 ) ;
V_61 = F_36 ( & V_9 -> V_95 ) ;
V_42 -> V_61 = F_37 ( V_61 ) ;
F_38 ( V_9 , V_2 , V_57 ) ;
F_39 ( V_2 ) ;
} else {
if ( V_48 == V_81 ) {
V_56 = F_40 ( V_9 , V_2 ) ;
if ( V_56 )
goto V_67;
V_56 = F_41 ( V_9 , V_2 , V_60 ) ;
} else if ( V_66 ) {
V_56 = F_42 ( V_9 , V_2 ,
V_96 , 0 ,
V_66 , V_60 ) ;
} else {
if ( F_34 ( V_9 ,
V_2 ) )
goto V_67;
F_43 ( V_9 , V_2 ) ;
V_56 = F_44 ( V_9 , V_2 , V_50 ,
V_60 ) ;
}
if ( V_56 == V_97 )
goto V_98;
}
F_45 ( V_9 , V_12 ) ;
F_46 ( V_9 , V_14 , V_55 ) ;
goto V_99;
V_67:
F_39 ( V_2 ) ;
V_98:
F_45 ( V_9 , V_16 ) ;
V_99:
if ( V_40 )
F_47 ( V_40 ) ;
return V_100 ;
}
void F_48 ( struct V_5 * V_37 ,
struct V_1 * V_2 , struct V_39 * V_101 ,
int V_102 , struct V_65 * V_103 )
{
struct V_41 * V_41 ;
struct V_8 * V_9 = F_9 ( V_37 ) ;
T_2 V_43 = F_21 ( V_44 ) ;
struct V_52 * V_53 ;
struct V_38 * V_38 ;
unsigned short V_60 ;
bool V_104 ;
V_41 = (struct V_41 * ) V_2 -> V_85 ;
V_104 = ( V_41 -> V_90 == V_91 ) ;
if ( ! F_49 ( V_2 , V_102 ) )
goto V_67;
F_50 ( V_2 , V_102 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_60 = F_22 ( V_2 , 0 ) ;
V_38 = F_23 ( V_2 ) ;
switch ( F_24 ( V_38 -> V_70 ) ) {
case V_71 :
V_53 = (struct V_52 * ) V_2 -> V_85 ;
if ( V_53 -> V_72 != V_43 )
break;
case V_44 :
goto V_67;
}
if ( F_53 ( ! F_49 ( V_2 , V_105 ) ) )
goto V_67;
V_2 -> V_106 = F_54 ( V_2 , V_37 ) ;
F_45 ( V_9 , V_18 ) ;
F_46 ( V_9 , V_20 ,
V_2 -> V_3 + V_105 ) ;
V_37 -> V_107 = V_69 ;
if ( F_55 ( V_9 , V_2 , V_60 , V_104 ) )
goto V_108;
if ( V_103 )
F_56 ( V_9 , V_103 ,
V_38 -> V_73 , V_60 ) ;
if ( F_27 ( V_38 -> V_76 ) ) {
if ( F_57 ( V_9 , V_60 ) &&
F_58 ( V_9 , V_38 -> V_73 ,
V_60 ) ) {
V_2 -> V_75 &= ~ V_9 -> V_109 ;
V_2 -> V_75 |= V_9 -> V_110 ;
}
} else if ( F_59 ( V_9 , V_38 -> V_73 ,
V_38 -> V_76 , V_60 ) ) {
goto V_67;
}
F_60 ( V_2 ) ;
goto V_108;
V_67:
F_39 ( V_2 ) ;
V_108:
return;
}
void F_61 ( struct V_111 * V_112 )
{
if ( F_62 ( & V_112 -> V_113 ) ) {
F_63 ( & V_112 -> V_9 -> V_114 ) ;
F_64 ( & V_112 -> V_115 ) ;
F_65 ( & V_112 -> V_9 -> V_114 ) ;
F_66 ( V_112 , V_116 ) ;
}
}
struct V_111 * F_67 ( struct V_8 * V_9 ,
unsigned short V_60 )
{
struct V_111 * V_117 , * V_112 = NULL ;
F_68 () ;
F_69 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_117 -> V_60 != V_60 )
continue;
if ( ! F_70 ( & V_117 -> V_113 ) )
continue;
V_112 = V_117 ;
break;
}
F_71 () ;
return V_112 ;
}
int F_72 ( struct V_8 * V_9 , unsigned short V_60 )
{
struct V_111 * V_112 ;
int V_118 ;
V_112 = F_67 ( V_9 , V_60 ) ;
if ( V_112 ) {
F_61 ( V_112 ) ;
return - V_119 ;
}
V_112 = F_73 ( sizeof( * V_112 ) , V_120 ) ;
if ( ! V_112 )
return - V_121 ;
V_112 -> V_9 = V_9 ;
V_112 -> V_60 = V_60 ;
F_74 ( & V_112 -> V_113 , 1 ) ;
F_74 ( & V_112 -> V_122 , 0 ) ;
V_118 = F_75 ( V_9 -> V_37 , V_112 ) ;
if ( V_118 ) {
F_76 ( V_112 ) ;
return V_118 ;
}
F_63 ( & V_9 -> V_114 ) ;
F_77 ( & V_112 -> V_115 , & V_9 -> V_123 ) ;
F_65 ( & V_9 -> V_114 ) ;
F_16 ( V_9 -> V_37 ,
V_9 -> V_37 -> V_28 , V_60 ,
V_32 , V_33 ) ;
return 0 ;
}
static void F_78 ( struct V_8 * V_9 ,
struct V_111 * V_112 )
{
F_15 ( V_9 , V_9 -> V_37 -> V_28 ,
V_112 -> V_60 , L_2 , false ) ;
F_79 ( V_9 , V_112 ) ;
F_61 ( V_112 ) ;
}
static int F_80 ( struct V_5 * V_6 , T_2 V_124 ,
unsigned short V_60 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_111 * V_112 ;
int V_56 ;
if ( V_124 != F_21 ( V_71 ) )
return - V_35 ;
V_60 |= V_125 ;
V_112 = F_67 ( V_9 , V_60 ) ;
if ( ! V_112 )
return F_72 ( V_9 , V_60 ) ;
if ( ! V_112 -> V_126 ) {
V_56 = F_75 ( V_9 -> V_37 , V_112 ) ;
if ( V_56 ) {
F_61 ( V_112 ) ;
return V_56 ;
}
}
F_16 ( V_9 -> V_37 ,
V_9 -> V_37 -> V_28 , V_60 ,
V_32 , V_33 ) ;
return 0 ;
}
static int F_81 ( struct V_5 * V_6 , T_2 V_124 ,
unsigned short V_60 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_111 * V_112 ;
if ( V_124 != F_21 ( V_71 ) )
return - V_35 ;
V_112 = F_67 ( V_9 , V_60 | V_125 ) ;
if ( ! V_112 )
return - V_127 ;
F_78 ( V_9 , V_112 ) ;
F_61 ( V_112 ) ;
return 0 ;
}
static void F_82 ( struct V_5 * V_6 ,
struct V_128 * V_129 ,
void * V_130 )
{
F_83 ( & V_129 -> V_131 , & V_132 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
F_83 ( & V_6 -> V_133 , & V_134 ) ;
F_85 ( V_6 , F_82 , NULL ) ;
}
static void F_86 ( struct V_135 * V_136 )
{
struct V_111 * V_112 ;
struct V_8 * V_9 ;
struct V_5 * V_37 ;
V_9 = F_87 ( V_136 , struct V_8 ,
V_137 ) ;
V_37 = V_9 -> V_37 ;
V_112 = F_67 ( V_9 , V_31 ) ;
if ( V_112 ) {
F_78 ( V_9 , V_112 ) ;
F_61 ( V_112 ) ;
}
F_88 ( V_37 ) ;
F_89 ( V_37 ) ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_138 ;
int V_56 ;
T_4 V_139 = sizeof( V_140 ) * V_141 ;
F_84 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_37 = V_6 ;
F_91 ( & V_9 -> V_137 , F_86 ) ;
V_9 -> V_142 = F_92 ( V_139 , F_93 ( V_140 ) ) ;
if ( ! V_9 -> V_142 )
return - V_121 ;
F_74 ( & V_9 -> V_143 , 1 ) ;
F_74 ( & V_9 -> V_144 , 0 ) ;
#ifdef F_94
F_74 ( & V_9 -> V_145 , 0 ) ;
#endif
#ifdef F_95
F_74 ( & V_9 -> V_146 , 1 ) ;
#endif
#ifdef F_96
V_9 -> V_147 . V_148 = V_31 ;
F_74 ( & V_9 -> V_149 , 1 ) ;
F_74 ( & V_9 -> V_147 . V_150 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_151 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_152 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_153 , 0 ) ;
#endif
F_74 ( & V_9 -> V_62 , V_77 ) ;
F_74 ( & V_9 -> V_154 , 20 ) ;
F_74 ( & V_9 -> V_155 . V_156 , 100 ) ;
F_74 ( & V_9 -> V_155 . V_157 , 20 ) ;
F_74 ( & V_9 -> V_158 , 1000 ) ;
F_74 ( & V_9 -> V_159 , 30 ) ;
#ifdef F_97
F_74 ( & V_9 -> V_160 , 0 ) ;
#endif
F_74 ( & V_9 -> V_161 , 1 ) ;
F_74 ( & V_9 -> V_162 , V_163 ) ;
F_74 ( & V_9 -> V_164 , V_165 ) ;
F_74 ( & V_9 -> V_166 , V_167 ) ;
F_74 ( & V_9 -> V_29 , V_168 ) ;
F_74 ( & V_9 -> V_95 , 1 ) ;
F_74 ( & V_9 -> V_169 . V_170 , 0 ) ;
F_74 ( & V_9 -> V_169 . V_171 , 0 ) ;
F_74 ( & V_9 -> V_169 . V_172 , 0 ) ;
#ifdef F_94
F_74 ( & V_9 -> V_173 . V_174 , 0 ) ;
#endif
V_9 -> V_169 . V_175 = NULL ;
V_9 -> V_169 . V_176 = 0 ;
V_9 -> V_110 = 0 ;
V_9 -> V_109 = 0 ;
F_98 ( & V_138 , sizeof( V_138 ) ) ;
F_74 ( & V_9 -> V_177 , V_138 ) ;
V_9 -> V_40 = NULL ;
V_9 -> V_178 = 0 ;
F_99 ( V_9 ) ;
V_56 = F_100 ( V_9 , V_179 ) ;
if ( V_56 < 0 )
goto V_180;
V_56 = F_101 ( V_6 ) ;
if ( V_56 < 0 )
goto V_180;
V_56 = F_102 ( V_6 ) ;
if ( V_56 < 0 )
goto V_181;
return 0 ;
V_181:
F_103 ( V_6 ) ;
V_180:
F_104 ( V_9 -> V_142 ) ;
V_9 -> V_142 = NULL ;
return V_56 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_5 * V_182 )
{
struct V_39 * V_183 ;
int V_56 = - V_35 ;
V_183 = F_106 ( V_182 ) ;
if ( ! V_183 || V_183 -> V_37 != NULL )
goto V_108;
V_56 = F_107 ( V_183 , V_6 -> V_184 ) ;
V_108:
if ( V_183 )
F_47 ( V_183 ) ;
return V_56 ;
}
static int F_108 ( struct V_5 * V_6 ,
struct V_5 * V_182 )
{
struct V_39 * V_183 ;
int V_56 = - V_35 ;
V_183 = F_106 ( V_182 ) ;
if ( ! V_183 || V_183 -> V_37 != V_6 )
goto V_108;
F_109 ( V_183 , V_185 ) ;
V_56 = 0 ;
V_108:
if ( V_183 )
F_47 ( V_183 ) ;
return V_56 ;
}
static void F_110 ( struct V_5 * V_6 )
{
F_103 ( V_6 ) ;
F_111 ( V_6 ) ;
F_112 () ;
F_113 ( V_6 ) ;
}
static void F_114 ( struct V_5 * V_6 )
{
struct V_8 * V_186 = F_9 ( V_6 ) ;
F_115 ( V_6 ) ;
V_6 -> V_187 = & V_188 ;
V_6 -> V_189 = F_110 ;
V_6 -> V_190 |= V_191 ;
V_6 -> V_192 = 0 ;
V_6 -> V_36 = V_163 ;
V_6 -> V_193 = F_116 () ;
F_117 ( V_6 ) ;
V_6 -> V_194 = & V_195 ;
memset ( V_186 , 0 , sizeof( * V_186 ) ) ;
}
struct V_5 * F_118 ( const char * V_184 )
{
struct V_5 * V_37 ;
int V_56 ;
V_37 = F_119 ( sizeof( struct V_8 ) , V_184 ,
V_196 , F_114 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_197 = & V_198 ;
V_56 = F_120 ( V_37 ) ;
if ( V_56 < 0 ) {
F_121 ( L_3 ,
V_184 , V_56 ) ;
F_113 ( V_37 ) ;
return NULL ;
}
return V_37 ;
}
void F_122 ( struct V_5 * V_37 )
{
struct V_8 * V_9 = F_9 ( V_37 ) ;
F_123 ( V_199 , & V_9 -> V_137 ) ;
}
static void F_124 ( struct V_5 * V_37 ,
struct V_200 * V_201 )
{
struct V_39 * V_183 ;
F_125 (hard_iface, &batadv_hardif_list, list) {
if ( V_183 -> V_37 == V_37 )
F_109 ( V_183 ,
V_185 ) ;
}
F_88 ( V_37 ) ;
F_126 ( V_37 , V_201 ) ;
}
int F_127 ( const struct V_5 * V_94 )
{
if ( V_94 -> V_187 -> V_202 == F_20 )
return 1 ;
return 0 ;
}
static int F_128 ( struct V_5 * V_6 , struct V_203 * V_204 )
{
V_204 -> V_205 = 0 ;
V_204 -> V_206 = 0 ;
F_129 ( V_204 , V_207 ) ;
V_204 -> V_208 = V_209 ;
V_204 -> V_210 = V_211 ;
V_204 -> V_212 = 0 ;
V_204 -> V_213 = V_214 ;
V_204 -> V_215 = V_216 ;
V_204 -> V_217 = 0 ;
V_204 -> V_218 = 0 ;
return 0 ;
}
static void F_130 ( struct V_5 * V_6 ,
struct V_219 * V_220 )
{
F_131 ( V_220 -> V_221 , L_4 , sizeof( V_220 -> V_221 ) ) ;
F_131 ( V_220 -> V_86 , V_222 , sizeof( V_220 -> V_86 ) ) ;
F_131 ( V_220 -> V_223 , L_5 , sizeof( V_220 -> V_223 ) ) ;
F_131 ( V_220 -> V_224 , L_6 , sizeof( V_220 -> V_224 ) ) ;
}
static T_5 F_132 ( struct V_5 * V_6 )
{
return - V_225 ;
}
static void F_133 ( struct V_5 * V_6 , T_5 V_226 )
{
}
static T_5 F_134 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_135 ( struct V_5 * V_6 , T_3 V_227 ,
T_1 * V_85 )
{
if ( V_227 == V_228 )
memcpy ( V_85 , V_229 ,
sizeof( V_229 ) ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_230 * V_10 ,
V_140 * V_85 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_231 ;
for ( V_231 = 0 ; V_231 < V_141 ; V_231 ++ )
V_85 [ V_231 ] = F_10 ( V_9 , V_231 ) ;
}
static int F_137 ( struct V_5 * V_6 , int V_227 )
{
if ( V_227 == V_228 )
return V_141 ;
return - V_225 ;
}
