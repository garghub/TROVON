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
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
goto V_68;
V_39 -> V_69 = V_70 ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_71 ) ) {
case V_72 :
V_55 = F_28 ( V_2 ) ;
if ( V_55 -> V_73 != V_45 )
break;
case V_46 :
goto V_68;
}
if ( F_29 ( V_9 , V_2 , V_33 ) )
goto V_68;
V_40 = F_26 ( V_2 ) ;
if ( ! F_30 ( V_40 -> V_74 ) ) {
V_61 = F_18 ( V_39 , V_40 -> V_74 ,
V_33 , V_2 -> V_75 ,
V_2 -> V_76 ) ;
if ( ! V_61 )
goto V_68;
}
if ( F_31 ( V_40 -> V_77 , V_47 ) )
goto V_68;
if ( F_31 ( V_40 -> V_77 , V_48 ) )
goto V_68;
V_63 = F_14 ( & V_9 -> V_63 ) ;
if ( F_30 ( V_40 -> V_77 ) ) {
if ( V_63 == V_78 ) {
V_60 = true ;
goto V_79;
}
V_50 = F_32 ( V_2 , & V_56 ,
V_53 ) ;
V_40 = F_26 ( V_2 ) ;
if ( V_50 == V_51 ) {
V_60 = true ;
goto V_79;
}
if ( V_50 == V_80 )
V_52 = V_53 ;
else if ( ( V_63 == V_81 ) &&
( V_50 == V_82 ) )
goto V_68;
V_79:
if ( V_60 && ! F_33 ( V_40 -> V_77 ) ) {
V_65 = F_34 ( V_9 , V_2 ,
& V_67 ) ;
if ( V_65 == V_83 )
goto V_68;
if ( V_65 == V_84 )
V_60 = false ;
}
}
F_35 ( V_2 , 0 ) ;
if ( V_60 ) {
V_42 = F_36 ( V_9 ) ;
if ( ! V_42 )
goto V_68;
if ( F_37 ( V_9 , V_2 ) )
V_59 = F_38 ( V_85 ) ;
if ( F_1 ( V_2 , sizeof( * V_44 ) ) < 0 )
goto V_68;
V_44 = (struct V_43 * ) V_2 -> V_86 ;
V_44 -> V_87 = V_88 ;
V_44 -> V_89 = V_90 ;
V_44 -> V_91 = V_92 ;
V_44 -> V_93 = 0 ;
F_13 ( V_44 -> V_94 ,
V_42 -> V_95 -> V_30 ) ;
V_62 = F_39 ( & V_9 -> V_96 ) ;
V_44 -> V_62 = F_40 ( V_62 ) ;
F_41 ( V_9 , V_2 , V_59 ) ;
F_42 ( V_2 ) ;
} else {
if ( V_50 == V_82 ) {
V_58 = F_43 ( V_9 , V_2 ) ;
if ( V_58 )
goto V_68;
V_58 = F_44 ( V_9 , V_2 , V_33 ) ;
} else if ( V_67 ) {
V_58 = F_45 ( V_9 , V_2 ,
V_97 , 0 ,
V_67 , V_33 ) ;
} else {
if ( F_37 ( V_9 ,
V_2 ) )
goto V_68;
F_46 ( V_9 , V_2 ) ;
V_58 = F_47 ( V_9 , V_2 , V_52 ,
V_33 ) ;
}
if ( V_58 == V_98 )
goto V_99;
}
F_48 ( V_9 , V_12 ) ;
F_49 ( V_9 , V_14 , V_57 ) ;
goto V_100;
V_68:
F_42 ( V_2 ) ;
V_99:
F_48 ( V_9 , V_16 ) ;
V_100:
if ( V_42 )
F_50 ( V_42 ) ;
return V_101 ;
}
void F_51 ( struct V_5 * V_39 ,
struct V_1 * V_2 , struct V_41 * V_102 ,
int V_103 , struct V_66 * V_104 )
{
struct V_43 * V_43 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
T_2 V_45 = F_24 ( V_46 ) ;
struct V_54 * V_55 ;
struct V_40 * V_40 ;
unsigned short V_33 ;
bool V_105 ;
V_43 = (struct V_43 * ) V_2 -> V_86 ;
V_105 = ( V_43 -> V_91 == V_92 ) ;
if ( ! F_52 ( V_2 , V_103 ) )
goto V_68;
F_53 ( V_2 , V_103 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_71 ) ) {
case V_72 :
V_55 = (struct V_54 * ) V_2 -> V_86 ;
if ( V_55 -> V_73 != V_45 )
break;
case V_46 :
goto V_68;
}
if ( F_56 ( ! F_52 ( V_2 , V_106 ) ) )
goto V_68;
V_2 -> V_107 = F_57 ( V_2 , V_39 ) ;
F_48 ( V_9 , V_18 ) ;
F_49 ( V_9 , V_20 ,
V_2 -> V_3 + V_106 ) ;
V_39 -> V_108 = V_70 ;
if ( F_58 ( V_9 , V_2 , V_33 , V_105 ) )
goto V_109;
if ( V_104 )
F_59 ( V_9 , V_104 ,
V_40 -> V_74 , V_33 ) ;
if ( F_30 ( V_40 -> V_77 ) ) {
if ( F_60 ( V_9 , V_33 ) &&
F_61 ( V_9 , V_40 -> V_74 ,
V_33 ) ) {
V_2 -> V_76 &= ~ V_9 -> V_110 ;
V_2 -> V_76 |= V_9 -> V_111 ;
}
} else if ( F_62 ( V_9 , V_40 -> V_74 ,
V_40 -> V_77 , V_33 ) ) {
goto V_68;
}
F_63 ( V_2 ) ;
goto V_109;
V_68:
F_42 ( V_2 ) ;
V_109:
return;
}
void F_64 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return;
if ( F_65 ( & V_23 -> V_112 ) ) {
F_66 ( & V_23 -> V_9 -> V_113 ) ;
F_67 ( & V_23 -> V_114 ) ;
F_68 ( & V_23 -> V_9 -> V_113 ) ;
F_69 ( V_23 , V_115 ) ;
}
}
struct V_22 * F_70 ( struct V_8 * V_9 ,
unsigned short V_33 )
{
struct V_22 * V_116 , * V_23 = NULL ;
F_15 () ;
F_16 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_116 -> V_33 != V_33 )
continue;
if ( ! F_71 ( & V_116 -> V_112 ) )
continue;
V_23 = V_116 ;
break;
}
F_19 () ;
return V_23 ;
}
int F_72 ( struct V_8 * V_9 , unsigned short V_33 )
{
struct V_22 * V_23 ;
int V_117 ;
V_23 = F_70 ( V_9 , V_33 ) ;
if ( V_23 ) {
F_64 ( V_23 ) ;
return - V_118 ;
}
V_23 = F_73 ( sizeof( * V_23 ) , V_119 ) ;
if ( ! V_23 )
return - V_120 ;
V_23 -> V_9 = V_9 ;
V_23 -> V_33 = V_33 ;
F_74 ( & V_23 -> V_112 , 1 ) ;
F_74 ( & V_23 -> V_121 , 0 ) ;
V_117 = F_75 ( V_9 -> V_39 , V_23 ) ;
if ( V_117 ) {
F_76 ( V_23 ) ;
return V_117 ;
}
F_66 ( & V_9 -> V_113 ) ;
F_77 ( & V_23 -> V_114 , & V_9 -> V_122 ) ;
F_68 ( & V_9 -> V_113 ) ;
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static void F_78 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
F_17 ( V_9 , V_9 -> V_39 -> V_30 ,
V_23 -> V_33 , L_2 , false ) ;
F_79 ( V_9 , V_23 ) ;
F_64 ( V_23 ) ;
}
static int F_80 ( struct V_5 * V_6 , T_2 V_123 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
int V_58 ;
if ( V_123 != F_24 ( V_72 ) )
return - V_37 ;
V_33 |= V_124 ;
V_23 = F_70 ( V_9 , V_33 ) ;
if ( ! V_23 )
return F_72 ( V_9 , V_33 ) ;
if ( ! V_23 -> V_125 ) {
V_58 = F_75 ( V_9 -> V_39 , V_23 ) ;
if ( V_58 ) {
F_64 ( V_23 ) ;
return V_58 ;
}
}
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_81 ( struct V_5 * V_6 , T_2 V_123 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
if ( V_123 != F_24 ( V_72 ) )
return - V_37 ;
V_23 = F_70 ( V_9 , V_33 | V_124 ) ;
if ( ! V_23 )
return - V_126 ;
F_78 ( V_9 , V_23 ) ;
F_64 ( V_23 ) ;
return 0 ;
}
static void F_82 ( struct V_5 * V_6 ,
struct V_127 * V_128 ,
void * V_129 )
{
F_83 ( & V_128 -> V_130 , & V_131 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
F_83 ( & V_6 -> V_132 , & V_133 ) ;
F_85 ( V_6 , F_82 , NULL ) ;
}
static void F_86 ( struct V_134 * V_135 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_5 * V_39 ;
V_9 = F_87 ( V_135 , struct V_8 ,
V_136 ) ;
V_39 = V_9 -> V_39 ;
V_23 = F_70 ( V_9 , V_137 ) ;
if ( V_23 ) {
F_78 ( V_9 , V_23 ) ;
F_64 ( V_23 ) ;
}
F_88 ( V_39 ) ;
F_89 ( V_39 ) ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_138 ;
int V_58 ;
T_4 V_139 = sizeof( V_140 ) * V_141 ;
F_84 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_39 = V_6 ;
F_91 ( & V_9 -> V_136 , F_86 ) ;
V_9 -> V_142 = F_92 ( V_139 , F_93 ( V_140 ) ) ;
if ( ! V_9 -> V_142 )
return - V_120 ;
F_74 ( & V_9 -> V_143 , 1 ) ;
F_74 ( & V_9 -> V_144 , 0 ) ;
#ifdef F_94
F_74 ( & V_9 -> V_145 , 1 ) ;
#endif
#ifdef F_95
F_74 ( & V_9 -> V_146 , 1 ) ;
#endif
#ifdef F_96
V_9 -> V_147 . V_148 = V_137 ;
F_74 ( & V_9 -> V_149 , 1 ) ;
F_74 ( & V_9 -> V_147 . V_150 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_151 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_152 , 0 ) ;
F_74 ( & V_9 -> V_147 . V_153 , 0 ) ;
#endif
F_74 ( & V_9 -> V_63 , V_78 ) ;
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
F_74 ( & V_9 -> V_31 , V_168 ) ;
F_74 ( & V_9 -> V_96 , 1 ) ;
F_74 ( & V_9 -> V_169 . V_170 , 0 ) ;
F_74 ( & V_9 -> V_169 . V_171 , 0 ) ;
F_74 ( & V_9 -> V_169 . V_172 , 0 ) ;
#ifdef F_94
F_74 ( & V_9 -> V_173 . V_174 , 0 ) ;
#endif
V_9 -> V_169 . V_175 = NULL ;
V_9 -> V_169 . V_176 = 0 ;
V_9 -> V_111 = 0 ;
V_9 -> V_110 = 0 ;
F_98 ( & V_138 , sizeof( V_138 ) ) ;
F_74 ( & V_9 -> V_177 , V_138 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_178 = 0 ;
F_99 ( V_9 ) ;
V_58 = F_100 ( V_9 , V_179 ) ;
if ( V_58 < 0 )
goto V_180;
V_58 = F_101 ( V_6 ) ;
if ( V_58 < 0 )
goto V_180;
V_58 = F_102 ( V_6 ) ;
if ( V_58 < 0 )
goto V_181;
return 0 ;
V_181:
F_103 ( V_6 ) ;
V_180:
F_104 ( V_9 -> V_142 ) ;
V_9 -> V_142 = NULL ;
return V_58 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_5 * V_182 )
{
struct V_41 * V_183 ;
int V_58 = - V_37 ;
V_183 = F_106 ( V_182 ) ;
if ( ! V_183 || V_183 -> V_39 )
goto V_109;
V_58 = F_107 ( V_183 , V_6 -> V_184 ) ;
V_109:
if ( V_183 )
F_50 ( V_183 ) ;
return V_58 ;
}
static int F_108 ( struct V_5 * V_6 ,
struct V_5 * V_182 )
{
struct V_41 * V_183 ;
int V_58 = - V_37 ;
V_183 = F_106 ( V_182 ) ;
if ( ! V_183 || V_183 -> V_39 != V_6 )
goto V_109;
F_109 ( V_183 , V_185 ) ;
V_58 = 0 ;
V_109:
if ( V_183 )
F_50 ( V_183 ) ;
return V_58 ;
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
V_6 -> V_38 = V_163 ;
V_6 -> V_193 = F_116 () ;
F_117 ( V_6 ) ;
V_6 -> V_194 = & V_195 ;
memset ( V_186 , 0 , sizeof( * V_186 ) ) ;
}
struct V_5 * F_118 ( const char * V_184 )
{
struct V_5 * V_39 ;
int V_58 ;
V_39 = F_119 ( sizeof( struct V_8 ) , V_184 ,
V_196 , F_114 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_197 = & V_198 ;
V_58 = F_120 ( V_39 ) ;
if ( V_58 < 0 ) {
F_121 ( L_3 ,
V_184 , V_58 ) ;
F_113 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
void F_122 ( struct V_5 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
F_123 ( V_199 , & V_9 -> V_136 ) ;
}
static void F_124 ( struct V_5 * V_39 ,
struct V_200 * V_201 )
{
struct V_41 * V_183 ;
F_125 (hard_iface, &batadv_hardif_list, list) {
if ( V_183 -> V_39 == V_39 )
F_109 ( V_183 ,
V_185 ) ;
}
F_88 ( V_39 ) ;
F_126 ( V_39 , V_201 ) ;
}
int F_127 ( const struct V_5 * V_95 )
{
if ( V_95 -> V_187 -> V_202 == F_23 )
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
F_131 ( V_220 -> V_87 , V_222 , sizeof( V_220 -> V_87 ) ) ;
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
T_1 * V_86 )
{
if ( V_227 == V_228 )
memcpy ( V_86 , V_229 ,
sizeof( V_229 ) ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_230 * V_10 ,
V_140 * V_86 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_231 ;
for ( V_231 = 0 ; V_231 < V_141 ; V_231 ++ )
V_86 [ V_231 ] = F_10 ( V_9 , V_231 ) ;
}
static int F_137 ( struct V_5 * V_6 , int V_227 )
{
if ( V_227 == V_228 )
return V_141 ;
return - V_225 ;
}
