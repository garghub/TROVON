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
memcpy ( V_24 , V_6 -> V_28 , V_25 ) ;
memcpy ( V_6 -> V_28 , V_23 -> V_26 , V_25 ) ;
if ( F_13 ( & V_9 -> V_29 ) == V_30 ) {
F_14 ( V_9 , V_24 , V_31 ,
L_1 , false ) ;
F_15 ( V_6 , V_23 -> V_26 , V_31 ,
V_32 , V_33 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , int V_34 )
{
if ( ( V_34 < 68 ) || ( V_34 > F_17 ( V_6 ) ) )
return - V_35 ;
V_6 -> V_36 = V_34 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_37 )
{
struct V_38 * V_38 ;
struct V_8 * V_9 = F_9 ( V_37 ) ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
T_2 V_43 = F_20 ( V_44 ) ;
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
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_63;
V_37 -> V_64 = V_65 ;
V_60 = F_21 ( V_2 , 0 ) ;
V_38 = (struct V_38 * ) V_2 -> V_66 ;
switch ( F_22 ( V_38 -> V_67 ) ) {
case V_68 :
V_53 = (struct V_52 * ) V_2 -> V_66 ;
if ( V_53 -> V_69 != V_43 )
break;
case V_44 :
goto V_63;
}
if ( F_23 ( V_9 , V_2 , V_60 ) )
goto V_63;
V_38 = (struct V_38 * ) V_2 -> V_66 ;
if ( ! F_24 ( V_38 -> V_70 ) ) {
V_59 = F_15 ( V_37 , V_38 -> V_70 ,
V_60 , V_2 -> V_71 ,
V_2 -> V_72 ) ;
if ( ! V_59 )
goto V_63;
}
if ( F_25 ( V_38 -> V_73 , V_45 ) )
goto V_63;
if ( F_25 ( V_38 -> V_73 , V_46 ) )
goto V_63;
V_62 = F_13 ( & V_9 -> V_62 ) ;
if ( F_24 ( V_38 -> V_73 ) ) {
if ( V_62 == V_74 ) {
V_58 = true ;
goto V_75;
}
V_48 = F_26 ( V_2 , & V_54 ,
V_51 ) ;
V_38 = (struct V_38 * ) V_2 -> V_66 ;
if ( V_48 == V_49 ) {
V_58 = true ;
goto V_75;
}
if ( V_48 == V_76 )
V_50 = V_51 ;
else if ( ( V_62 == V_77 ) &&
( V_48 == V_78 ) )
goto V_63;
}
V_75:
F_27 ( V_2 , 0 ) ;
if ( V_58 ) {
V_40 = F_28 ( V_9 ) ;
if ( ! V_40 )
goto V_63;
if ( F_29 ( V_9 , V_2 ) )
V_57 = F_30 ( V_79 ) ;
if ( F_1 ( V_2 , sizeof( * V_42 ) ) < 0 )
goto V_63;
V_42 = (struct V_41 * ) V_2 -> V_66 ;
V_42 -> V_80 = V_81 ;
V_42 -> V_82 = V_83 ;
V_42 -> V_84 = V_85 ;
V_42 -> V_86 = 0 ;
memcpy ( V_42 -> V_87 ,
V_40 -> V_88 -> V_28 , V_25 ) ;
V_61 = F_31 ( & V_9 -> V_89 ) ;
V_42 -> V_61 = F_32 ( V_61 ) ;
F_33 ( V_9 , V_2 , V_57 ) ;
F_34 ( V_2 ) ;
} else {
if ( V_48 == V_78 ) {
V_56 = F_35 ( V_9 , V_2 ) ;
if ( V_56 )
goto V_63;
V_56 = F_36 ( V_9 , V_2 , V_60 ) ;
} else {
if ( F_29 ( V_9 ,
V_2 ) )
goto V_63;
F_37 ( V_9 , V_2 ) ;
V_56 = F_38 ( V_9 , V_2 , V_50 ,
V_60 ) ;
}
if ( V_56 == V_90 )
goto V_91;
}
F_39 ( V_9 , V_12 ) ;
F_40 ( V_9 , V_14 , V_55 ) ;
goto V_92;
V_63:
F_34 ( V_2 ) ;
V_91:
F_39 ( V_9 , V_16 ) ;
V_92:
if ( V_40 )
F_41 ( V_40 ) ;
return V_93 ;
}
void F_42 ( struct V_5 * V_37 ,
struct V_1 * V_2 , struct V_39 * V_94 ,
int V_95 , struct V_96 * V_97 )
{
struct V_41 * V_41 ;
struct V_8 * V_9 = F_9 ( V_37 ) ;
T_2 V_43 = F_20 ( V_44 ) ;
struct V_52 * V_53 ;
struct V_38 * V_38 ;
unsigned short V_60 ;
bool V_98 ;
V_41 = (struct V_41 * ) V_2 -> V_66 ;
V_98 = ( V_41 -> V_84 == V_85 ) ;
if ( ! F_43 ( V_2 , V_95 ) )
goto V_63;
F_44 ( V_2 , V_95 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
V_60 = F_21 ( V_2 , 0 ) ;
V_38 = F_47 ( V_2 ) ;
switch ( F_22 ( V_38 -> V_67 ) ) {
case V_68 :
V_53 = (struct V_52 * ) V_2 -> V_66 ;
if ( V_53 -> V_69 != V_43 )
break;
case V_44 :
goto V_63;
}
if ( F_48 ( ! F_43 ( V_2 , V_99 ) ) )
goto V_63;
V_2 -> V_100 = F_49 ( V_2 , V_37 ) ;
F_39 ( V_9 , V_18 ) ;
F_40 ( V_9 , V_20 ,
V_2 -> V_3 + V_99 ) ;
V_37 -> V_101 = V_65 ;
if ( F_50 ( V_9 , V_2 , V_60 , V_98 ) )
goto V_102;
if ( V_97 )
F_51 ( V_9 , V_97 ,
V_38 -> V_70 , V_60 ) ;
if ( F_24 ( V_38 -> V_73 ) ) {
if ( F_52 ( V_9 , V_60 ) &&
F_53 ( V_9 , V_38 -> V_70 ,
V_60 ) ) {
V_2 -> V_72 &= ~ V_9 -> V_103 ;
V_2 -> V_72 |= V_9 -> V_104 ;
}
} else if ( F_54 ( V_9 , V_38 -> V_70 ,
V_38 -> V_73 , V_60 ) ) {
goto V_63;
}
F_55 ( V_2 ) ;
goto V_102;
V_63:
F_34 ( V_2 ) ;
V_102:
return;
}
void F_56 ( struct V_105 * V_106 )
{
if ( F_57 ( & V_106 -> V_107 ) )
F_58 ( V_106 , V_108 ) ;
}
struct V_105 * F_59 ( struct V_8 * V_9 ,
unsigned short V_60 )
{
struct V_105 * V_109 , * V_110 = NULL ;
F_60 () ;
F_61 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_109 -> V_60 != V_60 )
continue;
if ( ! F_62 ( & V_109 -> V_107 ) )
continue;
V_110 = V_109 ;
break;
}
F_63 () ;
return V_110 ;
}
int F_64 ( struct V_8 * V_9 , unsigned short V_60 )
{
struct V_105 * V_110 ;
int V_111 ;
V_110 = F_59 ( V_9 , V_60 ) ;
if ( V_110 ) {
F_56 ( V_110 ) ;
return - V_112 ;
}
V_110 = F_65 ( sizeof( * V_110 ) , V_113 ) ;
if ( ! V_110 )
return - V_114 ;
V_110 -> V_60 = V_60 ;
F_66 ( & V_110 -> V_107 , 1 ) ;
F_66 ( & V_110 -> V_115 , 0 ) ;
V_111 = F_67 ( V_9 -> V_37 , V_110 ) ;
if ( V_111 ) {
F_68 ( V_110 ) ;
return V_111 ;
}
F_15 ( V_9 -> V_37 ,
V_9 -> V_37 -> V_28 , V_60 ,
V_32 , V_33 ) ;
F_69 ( & V_9 -> V_116 ) ;
F_70 ( & V_110 -> V_117 , & V_9 -> V_118 ) ;
F_71 ( & V_9 -> V_116 ) ;
return 0 ;
}
static void F_72 ( struct V_8 * V_9 ,
struct V_105 * V_110 )
{
F_69 ( & V_9 -> V_116 ) ;
F_73 ( & V_110 -> V_117 ) ;
F_71 ( & V_9 -> V_116 ) ;
F_74 ( V_9 , V_110 ) ;
F_14 ( V_9 , V_9 -> V_37 -> V_28 ,
V_110 -> V_60 , L_2 , false ) ;
F_56 ( V_110 ) ;
}
static int F_75 ( struct V_5 * V_6 , T_2 V_119 ,
unsigned short V_60 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
if ( V_119 != F_20 ( V_68 ) )
return - V_35 ;
V_60 |= V_120 ;
return F_64 ( V_9 , V_60 ) ;
}
static int F_76 ( struct V_5 * V_6 , T_2 V_119 ,
unsigned short V_60 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_105 * V_110 ;
if ( V_119 != F_20 ( V_68 ) )
return - V_35 ;
V_110 = F_59 ( V_9 , V_60 | V_120 ) ;
if ( ! V_110 )
return - V_121 ;
F_72 ( V_9 , V_110 ) ;
F_56 ( V_110 ) ;
return 0 ;
}
static void F_77 ( struct V_5 * V_6 ,
struct V_122 * V_123 ,
void * V_124 )
{
F_78 ( & V_123 -> V_125 , & V_126 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
F_78 ( & V_6 -> V_127 , & V_128 ) ;
F_80 ( V_6 , F_77 , NULL ) ;
}
static void F_81 ( struct V_129 * V_130 )
{
struct V_105 * V_110 ;
struct V_8 * V_9 ;
struct V_5 * V_37 ;
V_9 = F_82 ( V_130 , struct V_8 ,
V_131 ) ;
V_37 = V_9 -> V_37 ;
V_110 = F_59 ( V_9 , V_31 ) ;
if ( V_110 ) {
F_72 ( V_9 , V_110 ) ;
F_56 ( V_110 ) ;
}
F_83 ( V_37 ) ;
F_84 () ;
F_85 ( V_37 ) ;
F_86 () ;
}
static int F_87 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_132 ;
int V_56 ;
T_4 V_133 = sizeof( V_134 ) * V_135 ;
F_79 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_37 = V_6 ;
F_88 ( & V_9 -> V_131 , F_81 ) ;
V_9 -> V_136 = F_89 ( V_133 , F_90 ( V_134 ) ) ;
if ( ! V_9 -> V_136 )
return - V_114 ;
F_66 ( & V_9 -> V_137 , 1 ) ;
F_66 ( & V_9 -> V_138 , 0 ) ;
#ifdef F_91
F_66 ( & V_9 -> V_139 , 0 ) ;
#endif
#ifdef F_92
F_66 ( & V_9 -> V_140 , 1 ) ;
#endif
F_66 ( & V_9 -> V_62 , V_74 ) ;
F_66 ( & V_9 -> V_141 , 20 ) ;
F_66 ( & V_9 -> V_142 . V_143 , 100 ) ;
F_66 ( & V_9 -> V_142 . V_144 , 20 ) ;
F_66 ( & V_9 -> V_145 , 1000 ) ;
F_66 ( & V_9 -> V_146 , 15 ) ;
#ifdef F_93
F_66 ( & V_9 -> V_147 , 0 ) ;
#endif
F_66 ( & V_9 -> V_148 , 1 ) ;
F_66 ( & V_9 -> V_149 , V_150 ) ;
F_66 ( & V_9 -> V_151 , V_152 ) ;
F_66 ( & V_9 -> V_153 , V_154 ) ;
F_66 ( & V_9 -> V_29 , V_155 ) ;
F_66 ( & V_9 -> V_89 , 1 ) ;
F_66 ( & V_9 -> V_156 . V_157 , 0 ) ;
F_66 ( & V_9 -> V_156 . V_158 , 0 ) ;
F_66 ( & V_9 -> V_156 . V_159 , 0 ) ;
#ifdef F_91
F_66 ( & V_9 -> V_160 . V_161 , 0 ) ;
#endif
V_9 -> V_156 . V_162 = NULL ;
V_9 -> V_156 . V_163 = 0 ;
V_9 -> V_104 = 0 ;
V_9 -> V_103 = 0 ;
F_94 ( & V_132 , sizeof( V_132 ) ) ;
F_66 ( & V_9 -> V_164 , V_132 ) ;
V_9 -> V_40 = NULL ;
V_9 -> V_165 = 0 ;
F_95 ( V_9 ) ;
V_56 = F_96 ( V_9 , V_166 ) ;
if ( V_56 < 0 )
goto V_167;
V_56 = F_97 ( V_6 ) ;
if ( V_56 < 0 )
goto V_167;
V_56 = F_98 ( V_6 ) ;
if ( V_56 < 0 )
goto V_168;
return 0 ;
V_168:
F_99 ( V_6 ) ;
V_167:
F_100 ( V_9 -> V_136 ) ;
V_9 -> V_136 = NULL ;
return V_56 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_5 * V_169 )
{
struct V_39 * V_170 ;
int V_56 = - V_35 ;
V_170 = F_102 ( V_169 ) ;
if ( ! V_170 || V_170 -> V_37 != NULL )
goto V_102;
V_56 = F_103 ( V_170 , V_6 -> V_171 ) ;
V_102:
if ( V_170 )
F_41 ( V_170 ) ;
return V_56 ;
}
static int F_104 ( struct V_5 * V_6 ,
struct V_5 * V_169 )
{
struct V_39 * V_170 ;
int V_56 = - V_35 ;
V_170 = F_102 ( V_169 ) ;
if ( ! V_170 || V_170 -> V_37 != V_6 )
goto V_102;
F_105 ( V_170 , V_172 ) ;
V_56 = 0 ;
V_102:
if ( V_170 )
F_41 ( V_170 ) ;
return V_56 ;
}
static void F_106 ( struct V_5 * V_6 )
{
F_99 ( V_6 ) ;
F_107 ( V_6 ) ;
F_108 () ;
F_109 ( V_6 ) ;
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_8 * V_173 = F_9 ( V_6 ) ;
F_111 ( V_6 ) ;
V_6 -> V_174 = & V_175 ;
V_6 -> V_176 = F_106 ;
V_6 -> V_177 |= V_178 ;
V_6 -> V_179 = 0 ;
V_6 -> V_36 = V_150 ;
V_6 -> V_180 = F_112 () ;
F_113 ( V_6 ) ;
F_114 ( V_6 , & V_181 ) ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
}
struct V_5 * F_115 ( const char * V_171 )
{
struct V_5 * V_37 ;
int V_56 ;
V_37 = F_116 ( sizeof( struct V_8 ) , V_171 ,
F_110 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_182 = & V_183 ;
V_56 = F_117 ( V_37 ) ;
if ( V_56 < 0 ) {
F_118 ( L_3 ,
V_171 , V_56 ) ;
F_109 ( V_37 ) ;
return NULL ;
}
return V_37 ;
}
void F_119 ( struct V_5 * V_37 )
{
struct V_8 * V_9 = F_9 ( V_37 ) ;
F_120 ( V_184 , & V_9 -> V_131 ) ;
}
static void F_121 ( struct V_5 * V_37 ,
struct V_185 * V_186 )
{
struct V_39 * V_170 ;
F_122 (hard_iface, &batadv_hardif_list, list) {
if ( V_170 -> V_37 == V_37 )
F_105 ( V_170 ,
V_172 ) ;
}
F_83 ( V_37 ) ;
F_123 ( V_37 , V_186 ) ;
}
int F_124 ( const struct V_5 * V_88 )
{
if ( V_88 -> V_174 -> V_187 == F_19 )
return 1 ;
return 0 ;
}
static int F_125 ( struct V_5 * V_6 , struct V_188 * V_189 )
{
V_189 -> V_190 = 0 ;
V_189 -> V_191 = 0 ;
F_126 ( V_189 , V_192 ) ;
V_189 -> V_193 = V_194 ;
V_189 -> V_195 = V_196 ;
V_189 -> V_197 = 0 ;
V_189 -> V_198 = V_199 ;
V_189 -> V_200 = V_201 ;
V_189 -> V_202 = 0 ;
V_189 -> V_203 = 0 ;
return 0 ;
}
static void F_127 ( struct V_5 * V_6 ,
struct V_204 * V_205 )
{
F_128 ( V_205 -> V_206 , L_4 , sizeof( V_205 -> V_206 ) ) ;
F_128 ( V_205 -> V_80 , V_207 , sizeof( V_205 -> V_80 ) ) ;
F_128 ( V_205 -> V_208 , L_5 , sizeof( V_205 -> V_208 ) ) ;
F_128 ( V_205 -> V_209 , L_6 , sizeof( V_205 -> V_209 ) ) ;
}
static T_5 F_129 ( struct V_5 * V_6 )
{
return - V_210 ;
}
static void F_130 ( struct V_5 * V_6 , T_5 V_211 )
{
}
static T_5 F_131 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_132 ( struct V_5 * V_6 , T_3 V_212 ,
T_1 * V_66 )
{
if ( V_212 == V_213 )
memcpy ( V_66 , V_214 ,
sizeof( V_214 ) ) ;
}
static void F_133 ( struct V_5 * V_6 ,
struct V_215 * V_10 ,
V_134 * V_66 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_216 ;
for ( V_216 = 0 ; V_216 < V_135 ; V_216 ++ )
V_66 [ V_216 ] = F_10 ( V_9 , V_216 ) ;
}
static int F_134 ( struct V_5 * V_6 , int V_212 )
{
if ( V_212 == V_213 )
return V_135 ;
return - V_210 ;
}
