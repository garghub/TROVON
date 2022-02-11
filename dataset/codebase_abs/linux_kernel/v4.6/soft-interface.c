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
struct V_22 * V_23 ;
struct V_24 * V_25 = V_21 ;
T_1 V_26 [ V_27 ] ;
if ( ! F_12 ( V_25 -> V_28 ) )
return - V_29 ;
F_13 ( V_26 , V_6 -> V_30 ) ;
F_13 ( V_6 -> V_30 , V_25 -> V_28 ) ;
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
return 0 ;
F_15 () ;
F_16 (vlan, &bat_priv->softif_vlan_list, list) {
F_17 ( V_9 , V_26 , V_23 -> V_33 ,
L_1 , false ) ;
F_18 ( V_6 , V_25 -> V_28 , V_23 -> V_33 ,
V_34 , V_35 ) ;
}
F_19 () ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , int V_36 )
{
if ( ( V_36 < 68 ) || ( V_36 > F_21 ( V_6 ) ) )
return - V_37 ;
V_6 -> V_38 = V_36 ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 )
{
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_39 )
{
struct V_40 * V_40 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 ;
T_2 V_45 = F_24 ( V_46 ) ;
static const T_1 V_47 [ V_27 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_48 [ V_27 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
enum V_49 V_50 = V_51 ;
T_1 * V_52 = NULL , V_53 [ V_27 ] ;
struct V_54 * V_55 ;
unsigned int V_56 = 0 ;
int V_57 = V_2 -> V_3 , V_58 ;
unsigned long V_59 = 1 ;
bool V_60 = false , V_61 ;
unsigned short V_33 ;
T_3 V_62 ;
int V_63 ;
enum V_64 V_65 ;
struct V_66 * V_67 = NULL ;
int V_68 = V_69 ;
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
goto V_70;
V_39 -> V_71 = V_72 ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_73 ) ) {
case V_74 :
V_55 = F_28 ( V_2 ) ;
if ( V_55 -> V_75 != V_45 ) {
V_68 += V_76 ;
break;
}
case V_46 :
goto V_70;
}
F_29 ( V_2 , V_68 ) ;
if ( F_30 ( V_9 , V_2 , V_33 ) )
goto V_70;
V_40 = F_26 ( V_2 ) ;
if ( ! F_31 ( V_40 -> V_77 ) ) {
V_61 = F_18 ( V_39 , V_40 -> V_77 ,
V_33 , V_2 -> V_78 ,
V_2 -> V_79 ) ;
if ( ! V_61 )
goto V_70;
}
if ( F_32 ( V_40 -> V_80 , V_47 ) )
goto V_70;
if ( F_32 ( V_40 -> V_80 , V_48 ) )
goto V_70;
V_63 = F_14 ( & V_9 -> V_63 ) ;
if ( F_31 ( V_40 -> V_80 ) ) {
if ( V_63 == V_81 ) {
V_60 = true ;
goto V_82;
}
V_50 = F_33 ( V_2 , & V_56 ,
V_53 ) ;
V_40 = F_26 ( V_2 ) ;
if ( V_50 == V_51 ) {
V_60 = true ;
goto V_82;
}
if ( V_50 == V_83 )
V_52 = V_53 ;
else if ( ( V_63 == V_84 ) &&
( V_50 == V_85 ) )
goto V_70;
V_82:
if ( V_60 && ! F_34 ( V_40 -> V_80 ) ) {
V_65 = F_35 ( V_9 , V_2 ,
& V_67 ) ;
if ( V_65 == V_86 )
goto V_70;
if ( V_65 == V_87 )
V_60 = false ;
}
}
F_36 ( V_2 , 0 ) ;
if ( V_60 ) {
V_42 = F_37 ( V_9 ) ;
if ( ! V_42 )
goto V_70;
if ( F_38 ( V_9 , V_2 ) )
V_59 = F_39 ( V_88 ) ;
if ( F_1 ( V_2 , sizeof( * V_44 ) ) < 0 )
goto V_70;
V_44 = (struct V_43 * ) V_2 -> V_89 ;
V_44 -> V_90 = V_91 ;
V_44 -> V_92 = V_93 ;
V_44 -> V_94 = V_95 ;
V_44 -> V_96 = 0 ;
F_13 ( V_44 -> V_97 ,
V_42 -> V_98 -> V_30 ) ;
V_62 = F_40 ( & V_9 -> V_99 ) ;
V_44 -> V_62 = F_41 ( V_62 ) ;
F_42 ( V_9 , V_2 , V_59 ) ;
F_43 ( V_2 ) ;
} else {
if ( V_50 == V_85 ) {
V_58 = F_44 ( V_9 , V_2 ) ;
if ( V_58 )
goto V_70;
V_58 = F_45 ( V_9 , V_2 , V_33 ) ;
} else if ( V_67 ) {
V_58 = F_46 ( V_9 , V_2 ,
V_100 , 0 ,
V_67 , V_33 ) ;
} else {
if ( F_38 ( V_9 ,
V_2 ) )
goto V_70;
F_47 ( V_9 , V_2 ) ;
V_58 = F_48 ( V_9 , V_2 , V_52 ,
V_33 ) ;
}
if ( V_58 == V_101 )
goto V_102;
}
F_49 ( V_9 , V_12 ) ;
F_50 ( V_9 , V_14 , V_57 ) ;
goto V_103;
V_70:
F_43 ( V_2 ) ;
V_102:
F_49 ( V_9 , V_16 ) ;
V_103:
if ( V_42 )
F_51 ( V_42 ) ;
return V_104 ;
}
void F_52 ( struct V_5 * V_39 ,
struct V_1 * V_2 , struct V_41 * V_105 ,
int V_106 , struct V_66 * V_107 )
{
struct V_43 * V_43 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
T_2 V_45 = F_24 ( V_46 ) ;
struct V_54 * V_55 ;
struct V_40 * V_40 ;
unsigned short V_33 ;
bool V_108 ;
V_43 = (struct V_43 * ) V_2 -> V_89 ;
V_108 = ( V_43 -> V_94 == V_95 ) ;
if ( ! F_53 ( V_2 , V_106 ) )
goto V_70;
F_54 ( V_2 , V_106 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( F_57 ( ! F_53 ( V_2 , V_69 ) ) )
goto V_70;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_73 ) ) {
case V_74 :
if ( ! F_53 ( V_2 , V_109 ) )
goto V_70;
V_55 = (struct V_54 * ) V_2 -> V_89 ;
if ( V_55 -> V_75 != V_45 )
break;
case V_46 :
goto V_70;
}
V_2 -> V_110 = F_58 ( V_2 , V_39 ) ;
F_49 ( V_9 , V_18 ) ;
F_50 ( V_9 , V_20 ,
V_2 -> V_3 + V_69 ) ;
V_39 -> V_111 = V_72 ;
if ( F_59 ( V_9 , V_2 , V_33 , V_108 ) )
goto V_112;
if ( V_107 )
F_60 ( V_9 , V_107 ,
V_40 -> V_77 , V_33 ) ;
if ( F_31 ( V_40 -> V_80 ) ) {
if ( F_61 ( V_9 , V_33 ) &&
F_62 ( V_9 , V_40 -> V_77 ,
V_33 ) ) {
V_2 -> V_79 &= ~ V_9 -> V_113 ;
V_2 -> V_79 |= V_9 -> V_114 ;
}
} else if ( F_63 ( V_9 , V_40 -> V_77 ,
V_40 -> V_80 , V_33 ) ) {
goto V_70;
}
F_64 ( V_2 ) ;
goto V_112;
V_70:
F_43 ( V_2 ) ;
V_112:
return;
}
static void F_65 ( struct V_115 * V_116 )
{
struct V_22 * V_23 ;
V_23 = F_66 ( V_116 , struct V_22 , V_117 ) ;
F_67 ( & V_23 -> V_9 -> V_118 ) ;
F_68 ( & V_23 -> V_119 ) ;
F_69 ( & V_23 -> V_9 -> V_118 ) ;
F_70 ( V_23 , V_120 ) ;
}
void F_71 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return;
F_72 ( & V_23 -> V_117 , F_65 ) ;
}
struct V_22 * F_73 ( struct V_8 * V_9 ,
unsigned short V_33 )
{
struct V_22 * V_121 , * V_23 = NULL ;
F_15 () ;
F_16 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_121 -> V_33 != V_33 )
continue;
if ( ! F_74 ( & V_121 -> V_117 ) )
continue;
V_23 = V_121 ;
break;
}
F_19 () ;
return V_23 ;
}
int F_75 ( struct V_8 * V_9 , unsigned short V_33 )
{
struct V_22 * V_23 ;
int V_122 ;
V_23 = F_73 ( V_9 , V_33 ) ;
if ( V_23 ) {
F_71 ( V_23 ) ;
return - V_123 ;
}
V_23 = F_76 ( sizeof( * V_23 ) , V_124 ) ;
if ( ! V_23 )
return - V_125 ;
V_23 -> V_9 = V_9 ;
V_23 -> V_33 = V_33 ;
F_77 ( & V_23 -> V_117 ) ;
F_78 ( & V_23 -> V_126 , 0 ) ;
V_122 = F_79 ( V_9 -> V_39 , V_23 ) ;
if ( V_122 ) {
F_80 ( V_23 ) ;
return V_122 ;
}
F_67 ( & V_9 -> V_118 ) ;
F_81 ( & V_23 -> V_119 , & V_9 -> V_127 ) ;
F_69 ( & V_9 -> V_118 ) ;
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static void F_82 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
F_17 ( V_9 , V_9 -> V_39 -> V_30 ,
V_23 -> V_33 , L_2 , false ) ;
F_83 ( V_9 , V_23 ) ;
F_71 ( V_23 ) ;
}
static int F_84 ( struct V_5 * V_6 , T_2 V_128 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
int V_58 ;
if ( V_128 != F_24 ( V_74 ) )
return - V_37 ;
V_33 |= V_129 ;
V_23 = F_73 ( V_9 , V_33 ) ;
if ( ! V_23 )
return F_75 ( V_9 , V_33 ) ;
if ( ! V_23 -> V_130 ) {
V_58 = F_79 ( V_9 -> V_39 , V_23 ) ;
if ( V_58 ) {
F_71 ( V_23 ) ;
return V_58 ;
}
}
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 , T_2 V_128 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
if ( V_128 != F_24 ( V_74 ) )
return - V_37 ;
V_23 = F_73 ( V_9 , V_33 | V_129 ) ;
if ( ! V_23 )
return - V_131 ;
F_82 ( V_9 , V_23 ) ;
F_71 ( V_23 ) ;
return 0 ;
}
static void F_86 ( struct V_5 * V_6 ,
struct V_132 * V_133 ,
void * V_134 )
{
F_87 ( & V_133 -> V_135 , & V_136 ) ;
}
static void F_88 ( struct V_5 * V_6 )
{
F_87 ( & V_6 -> V_137 , & V_138 ) ;
F_89 ( V_6 , F_86 , NULL ) ;
}
static void F_90 ( struct V_139 * V_140 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_5 * V_39 ;
V_9 = F_66 ( V_140 , struct V_8 ,
V_141 ) ;
V_39 = V_9 -> V_39 ;
V_23 = F_73 ( V_9 , V_142 ) ;
if ( V_23 ) {
F_82 ( V_9 , V_23 ) ;
F_71 ( V_23 ) ;
}
F_91 ( V_39 ) ;
F_92 ( V_39 ) ;
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_143 ;
int V_58 ;
T_4 V_144 = sizeof( V_145 ) * V_146 ;
F_88 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_39 = V_6 ;
F_94 ( & V_9 -> V_141 , F_90 ) ;
V_9 -> V_147 = F_95 ( V_144 , F_96 ( V_145 ) ) ;
if ( ! V_9 -> V_147 )
return - V_125 ;
F_78 ( & V_9 -> V_148 , 1 ) ;
F_78 ( & V_9 -> V_149 , 0 ) ;
#ifdef F_97
F_78 ( & V_9 -> V_150 , 1 ) ;
#endif
#ifdef F_98
F_78 ( & V_9 -> V_151 , 1 ) ;
#endif
#ifdef F_99
V_9 -> V_152 . V_153 = V_142 ;
F_78 ( & V_9 -> V_154 , 1 ) ;
F_78 ( & V_9 -> V_152 . V_155 , 0 ) ;
F_78 ( & V_9 -> V_152 . V_156 , 0 ) ;
F_78 ( & V_9 -> V_152 . V_157 , 0 ) ;
F_78 ( & V_9 -> V_152 . V_158 , 0 ) ;
#endif
F_78 ( & V_9 -> V_63 , V_81 ) ;
F_78 ( & V_9 -> V_159 , 20 ) ;
F_78 ( & V_9 -> V_160 . V_161 , 100 ) ;
F_78 ( & V_9 -> V_160 . V_162 , 20 ) ;
F_78 ( & V_9 -> V_163 , 1000 ) ;
F_78 ( & V_9 -> V_164 , 30 ) ;
#ifdef F_100
F_78 ( & V_9 -> V_165 , 0 ) ;
#endif
F_78 ( & V_9 -> V_166 , 1 ) ;
F_78 ( & V_9 -> V_167 , V_168 ) ;
F_78 ( & V_9 -> V_169 , V_170 ) ;
F_78 ( & V_9 -> V_171 , V_172 ) ;
F_78 ( & V_9 -> V_31 , V_173 ) ;
F_78 ( & V_9 -> V_99 , 1 ) ;
F_78 ( & V_9 -> V_174 . V_175 , 0 ) ;
F_78 ( & V_9 -> V_174 . V_176 , 0 ) ;
F_78 ( & V_9 -> V_174 . V_177 , 0 ) ;
#ifdef F_97
F_78 ( & V_9 -> V_178 . V_179 , 0 ) ;
#endif
V_9 -> V_174 . V_180 = NULL ;
V_9 -> V_174 . V_181 = 0 ;
V_9 -> V_114 = 0 ;
V_9 -> V_113 = 0 ;
F_101 ( & V_143 , sizeof( V_143 ) ) ;
F_78 ( & V_9 -> V_182 , V_143 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_183 = 0 ;
F_102 ( V_9 ) ;
V_58 = F_103 ( V_9 , V_184 ) ;
if ( V_58 < 0 )
goto V_185;
V_58 = F_104 ( V_6 ) ;
if ( V_58 < 0 )
goto V_185;
V_58 = F_105 ( V_6 ) ;
if ( V_58 < 0 )
goto V_186;
return 0 ;
V_186:
F_106 ( V_6 ) ;
V_185:
F_107 ( V_9 -> V_147 ) ;
V_9 -> V_147 = NULL ;
return V_58 ;
}
static int F_108 ( struct V_5 * V_6 ,
struct V_5 * V_187 )
{
struct V_41 * V_188 ;
int V_58 = - V_37 ;
V_188 = F_109 ( V_187 ) ;
if ( ! V_188 || V_188 -> V_39 )
goto V_112;
V_58 = F_110 ( V_188 , V_6 -> V_189 ) ;
V_112:
if ( V_188 )
F_51 ( V_188 ) ;
return V_58 ;
}
static int F_111 ( struct V_5 * V_6 ,
struct V_5 * V_187 )
{
struct V_41 * V_188 ;
int V_58 = - V_37 ;
V_188 = F_109 ( V_187 ) ;
if ( ! V_188 || V_188 -> V_39 != V_6 )
goto V_112;
F_112 ( V_188 , V_190 ) ;
V_58 = 0 ;
V_112:
if ( V_188 )
F_51 ( V_188 ) ;
return V_58 ;
}
static void F_113 ( struct V_5 * V_6 )
{
F_106 ( V_6 ) ;
F_114 ( V_6 ) ;
F_115 () ;
F_116 ( V_6 ) ;
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_8 * V_191 = F_9 ( V_6 ) ;
F_118 ( V_6 ) ;
V_6 -> V_192 = & V_193 ;
V_6 -> V_194 = F_113 ;
V_6 -> V_195 |= V_196 ;
V_6 -> V_197 |= V_198 ;
V_6 -> V_38 = V_168 ;
F_119 ( V_6 ) ;
V_6 -> V_199 = & V_200 ;
memset ( V_191 , 0 , sizeof( * V_191 ) ) ;
}
struct V_5 * F_120 ( const char * V_189 )
{
struct V_5 * V_39 ;
int V_58 ;
V_39 = F_121 ( sizeof( struct V_8 ) , V_189 ,
V_201 , F_117 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_202 = & V_203 ;
V_58 = F_122 ( V_39 ) ;
if ( V_58 < 0 ) {
F_123 ( L_3 ,
V_189 , V_58 ) ;
F_116 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
void F_124 ( struct V_5 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
F_125 ( V_204 , & V_9 -> V_141 ) ;
}
static void F_126 ( struct V_5 * V_39 ,
struct V_205 * V_206 )
{
struct V_41 * V_188 ;
F_127 (hard_iface, &batadv_hardif_list, list) {
if ( V_188 -> V_39 == V_39 )
F_112 ( V_188 ,
V_190 ) ;
}
F_91 ( V_39 ) ;
F_128 ( V_39 , V_206 ) ;
}
int F_129 ( const struct V_5 * V_98 )
{
if ( V_98 -> V_192 -> V_207 == F_23 )
return 1 ;
return 0 ;
}
static int F_130 ( struct V_5 * V_6 , struct V_208 * V_209 )
{
V_209 -> V_210 = 0 ;
V_209 -> V_211 = 0 ;
F_131 ( V_209 , V_212 ) ;
V_209 -> V_213 = V_214 ;
V_209 -> V_215 = V_216 ;
V_209 -> V_217 = 0 ;
V_209 -> V_218 = V_219 ;
V_209 -> V_220 = V_221 ;
V_209 -> V_222 = 0 ;
V_209 -> V_223 = 0 ;
return 0 ;
}
static void F_132 ( struct V_5 * V_6 ,
struct V_224 * V_225 )
{
F_133 ( V_225 -> V_226 , L_4 , sizeof( V_225 -> V_226 ) ) ;
F_133 ( V_225 -> V_90 , V_227 , sizeof( V_225 -> V_90 ) ) ;
F_133 ( V_225 -> V_228 , L_5 , sizeof( V_225 -> V_228 ) ) ;
F_133 ( V_225 -> V_229 , L_6 , sizeof( V_225 -> V_229 ) ) ;
}
static T_3 F_134 ( struct V_5 * V_6 )
{
return - V_230 ;
}
static void F_135 ( struct V_5 * V_6 , T_3 V_231 )
{
}
static T_3 F_136 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_137 ( struct V_5 * V_6 , T_3 V_232 , T_1 * V_89 )
{
if ( V_232 == V_233 )
memcpy ( V_89 , V_234 ,
sizeof( V_234 ) ) ;
}
static void F_138 ( struct V_5 * V_6 ,
struct V_235 * V_10 , V_145 * V_89 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_236 ;
for ( V_236 = 0 ; V_236 < V_146 ; V_236 ++ )
V_89 [ V_236 ] = F_10 ( V_9 , V_236 ) ;
}
static int F_139 ( struct V_5 * V_6 , int V_232 )
{
if ( V_232 == V_233 )
return V_146 ;
return - V_230 ;
}
