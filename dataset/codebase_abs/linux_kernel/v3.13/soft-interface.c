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
V_32 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , int V_33 )
{
if ( ( V_33 < 68 ) || ( V_33 > F_17 ( V_6 ) ) )
return - V_34 ;
V_6 -> V_35 = V_33 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_36 )
{
struct V_37 * V_37 ;
struct V_8 * V_9 = F_9 ( V_36 ) ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
T_2 V_42 = F_20 ( V_43 ) ;
static const T_1 V_44 [ V_25 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_45 [ V_25 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
struct V_46 * V_47 ;
unsigned int V_48 = 0 ;
int V_49 = V_2 -> V_3 , V_50 ;
unsigned long V_51 = 1 ;
bool V_52 = false , V_53 ;
unsigned short V_54 ;
T_3 V_55 ;
if ( F_13 ( & V_9 -> V_29 ) != V_30 )
goto V_56;
V_36 -> V_57 = V_58 ;
V_54 = F_21 ( V_2 , 0 ) ;
V_37 = (struct V_37 * ) V_2 -> V_59 ;
switch ( F_22 ( V_37 -> V_60 ) ) {
case V_61 :
V_47 = (struct V_46 * ) V_2 -> V_59 ;
if ( V_47 -> V_62 != V_42 )
break;
case V_43 :
goto V_56;
}
if ( F_23 ( V_9 , V_2 , V_54 ) )
goto V_56;
V_37 = (struct V_37 * ) V_2 -> V_59 ;
if ( ! F_24 ( V_37 -> V_63 ) ) {
V_53 = F_15 ( V_36 , V_37 -> V_63 ,
V_54 , V_2 -> V_64 ) ;
if ( ! V_53 )
goto V_56;
}
if ( F_25 ( V_37 -> V_65 , V_44 ) )
goto V_56;
if ( F_25 ( V_37 -> V_65 , V_45 ) )
goto V_56;
if ( F_24 ( V_37 -> V_65 ) ) {
V_52 = true ;
switch ( F_13 ( & V_9 -> V_66 ) ) {
case V_67 :
V_50 = F_26 ( V_2 , & V_48 ) ;
if ( V_50 )
goto V_56;
break;
case V_68 :
V_50 = F_26 ( V_2 , & V_48 ) ;
if ( V_50 )
V_52 = false ;
break;
case V_69 :
default:
break;
}
}
F_27 ( V_2 , 0 ) ;
if ( V_52 ) {
V_39 = F_28 ( V_9 ) ;
if ( ! V_39 )
goto V_56;
if ( F_29 ( V_9 , V_2 ) )
V_51 = F_30 ( V_70 ) ;
if ( F_1 ( V_2 , sizeof( * V_41 ) ) < 0 )
goto V_56;
V_41 = (struct V_40 * ) V_2 -> V_59 ;
V_41 -> V_71 = V_72 ;
V_41 -> V_73 = V_74 ;
V_41 -> V_75 = V_76 ;
V_41 -> V_77 = 0 ;
memcpy ( V_41 -> V_78 ,
V_39 -> V_79 -> V_28 , V_25 ) ;
V_55 = F_31 ( & V_9 -> V_80 ) ;
V_41 -> V_55 = F_32 ( V_55 ) ;
F_33 ( V_9 , V_2 , V_51 ) ;
F_34 ( V_2 ) ;
} else {
if ( F_13 ( & V_9 -> V_66 ) != V_69 ) {
V_50 = F_35 ( V_9 , V_2 ) ;
if ( V_50 )
goto V_56;
}
if ( F_29 ( V_9 , V_2 ) )
goto V_56;
F_36 ( V_9 , V_2 ) ;
if ( F_24 ( V_37 -> V_65 ) )
V_50 = F_37 ( V_9 , V_2 , V_54 ) ;
else
V_50 = F_38 ( V_9 , V_2 , V_54 ) ;
if ( V_50 == V_81 )
goto V_82;
}
F_39 ( V_9 , V_12 ) ;
F_40 ( V_9 , V_14 , V_49 ) ;
goto V_83;
V_56:
F_34 ( V_2 ) ;
V_82:
F_39 ( V_9 , V_16 ) ;
V_83:
if ( V_39 )
F_41 ( V_39 ) ;
return V_84 ;
}
void F_42 ( struct V_5 * V_36 ,
struct V_1 * V_2 , struct V_38 * V_85 ,
int V_86 , struct V_87 * V_88 )
{
struct V_40 * V_40 ;
struct V_8 * V_9 = F_9 ( V_36 ) ;
T_2 V_42 = F_20 ( V_43 ) ;
struct V_46 * V_47 ;
struct V_37 * V_37 ;
unsigned short V_54 ;
bool V_89 ;
V_40 = (struct V_40 * ) V_2 -> V_59 ;
V_89 = ( V_40 -> V_75 == V_76 ) ;
if ( ! F_43 ( V_2 , V_86 ) )
goto V_56;
F_44 ( V_2 , V_86 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
V_54 = F_21 ( V_2 , 0 ) ;
V_37 = F_47 ( V_2 ) ;
switch ( F_22 ( V_37 -> V_60 ) ) {
case V_61 :
V_47 = (struct V_46 * ) V_2 -> V_59 ;
if ( V_47 -> V_62 != V_42 )
break;
case V_43 :
goto V_56;
}
if ( F_48 ( ! F_43 ( V_2 , V_90 ) ) )
goto V_56;
V_2 -> V_91 = F_49 ( V_2 , V_36 ) ;
F_39 ( V_9 , V_18 ) ;
F_40 ( V_9 , V_20 ,
V_2 -> V_3 + V_90 ) ;
V_36 -> V_92 = V_58 ;
if ( F_50 ( V_9 , V_2 , V_54 , V_89 ) )
goto V_93;
if ( V_88 )
F_51 ( V_9 , V_88 ,
V_37 -> V_63 , V_54 ) ;
if ( F_52 ( V_9 , V_37 -> V_63 , V_37 -> V_65 ,
V_54 ) )
goto V_56;
F_53 ( V_2 ) ;
goto V_93;
V_56:
F_34 ( V_2 ) ;
V_93:
return;
}
void F_54 ( struct V_94 * V_95 )
{
if ( F_55 ( & V_95 -> V_96 ) )
F_56 ( V_95 , V_97 ) ;
}
struct V_94 * F_57 ( struct V_8 * V_9 ,
unsigned short V_54 )
{
struct V_94 * V_98 , * V_99 = NULL ;
F_58 () ;
F_59 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_98 -> V_54 != V_54 )
continue;
if ( ! F_60 ( & V_98 -> V_96 ) )
continue;
V_99 = V_98 ;
break;
}
F_61 () ;
return V_99 ;
}
int F_62 ( struct V_8 * V_9 , unsigned short V_54 )
{
struct V_94 * V_99 ;
int V_100 ;
V_99 = F_57 ( V_9 , V_54 ) ;
if ( V_99 ) {
F_54 ( V_99 ) ;
return - V_101 ;
}
V_99 = F_63 ( sizeof( * V_99 ) , V_102 ) ;
if ( ! V_99 )
return - V_103 ;
V_99 -> V_54 = V_54 ;
F_64 ( & V_99 -> V_96 , 1 ) ;
F_64 ( & V_99 -> V_104 , 0 ) ;
V_100 = F_65 ( V_9 -> V_36 , V_99 ) ;
if ( V_100 ) {
F_66 ( V_99 ) ;
return V_100 ;
}
F_15 ( V_9 -> V_36 ,
V_9 -> V_36 -> V_28 , V_54 ,
V_32 ) ;
F_67 ( & V_9 -> V_105 ) ;
F_68 ( & V_99 -> V_106 , & V_9 -> V_107 ) ;
F_69 ( & V_9 -> V_105 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 ,
struct V_94 * V_99 )
{
F_67 ( & V_9 -> V_105 ) ;
F_71 ( & V_99 -> V_106 ) ;
F_69 ( & V_9 -> V_105 ) ;
F_72 ( V_9 , V_99 ) ;
F_14 ( V_9 , V_9 -> V_36 -> V_28 ,
V_99 -> V_54 , L_2 , false ) ;
F_54 ( V_99 ) ;
}
static int F_73 ( struct V_5 * V_6 , T_2 V_108 ,
unsigned short V_54 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
if ( V_108 != F_20 ( V_61 ) )
return - V_34 ;
V_54 |= V_109 ;
return F_62 ( V_9 , V_54 ) ;
}
static int F_74 ( struct V_5 * V_6 , T_2 V_108 ,
unsigned short V_54 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_94 * V_99 ;
if ( V_108 != F_20 ( V_61 ) )
return - V_34 ;
V_99 = F_57 ( V_9 , V_54 | V_109 ) ;
if ( ! V_99 )
return - V_110 ;
F_70 ( V_9 , V_99 ) ;
F_54 ( V_99 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
void * V_113 )
{
F_76 ( & V_112 -> V_114 , & V_115 ) ;
}
static void F_77 ( struct V_5 * V_6 )
{
F_76 ( & V_6 -> V_116 , & V_117 ) ;
F_78 ( V_6 , F_75 , NULL ) ;
}
static void F_79 ( struct V_118 * V_119 )
{
struct V_94 * V_99 ;
struct V_8 * V_9 ;
struct V_5 * V_36 ;
V_9 = F_80 ( V_119 , struct V_8 ,
V_120 ) ;
V_36 = V_9 -> V_36 ;
V_99 = F_57 ( V_9 , V_31 ) ;
if ( V_99 ) {
F_70 ( V_9 , V_99 ) ;
F_54 ( V_99 ) ;
}
F_81 ( V_36 ) ;
F_82 () ;
F_83 ( V_36 ) ;
F_84 () ;
}
static int F_85 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_121 ;
int V_50 ;
T_4 V_122 = sizeof( V_123 ) * V_124 ;
F_77 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_36 = V_6 ;
F_86 ( & V_9 -> V_120 , F_79 ) ;
V_9 -> V_125 = F_87 ( V_122 , F_88 ( V_123 ) ) ;
if ( ! V_9 -> V_125 )
return - V_103 ;
F_64 ( & V_9 -> V_126 , 1 ) ;
F_64 ( & V_9 -> V_127 , 0 ) ;
#ifdef F_89
F_64 ( & V_9 -> V_128 , 0 ) ;
#endif
#ifdef F_90
F_64 ( & V_9 -> V_129 , 1 ) ;
#endif
F_64 ( & V_9 -> V_66 , V_69 ) ;
F_64 ( & V_9 -> V_130 , 20 ) ;
F_64 ( & V_9 -> V_131 . V_132 , 100 ) ;
F_64 ( & V_9 -> V_131 . V_133 , 20 ) ;
F_64 ( & V_9 -> V_134 , 1000 ) ;
F_64 ( & V_9 -> V_135 , 30 ) ;
#ifdef F_91
F_64 ( & V_9 -> V_136 , 0 ) ;
#endif
F_64 ( & V_9 -> V_137 , 1 ) ;
F_64 ( & V_9 -> V_138 , V_139 ) ;
F_64 ( & V_9 -> V_140 , V_141 ) ;
F_64 ( & V_9 -> V_142 , V_143 ) ;
F_64 ( & V_9 -> V_29 , V_144 ) ;
F_64 ( & V_9 -> V_80 , 1 ) ;
F_64 ( & V_9 -> V_145 . V_146 , 0 ) ;
F_64 ( & V_9 -> V_145 . V_147 , 0 ) ;
F_64 ( & V_9 -> V_145 . V_148 , 0 ) ;
#ifdef F_89
F_64 ( & V_9 -> V_149 . V_150 , 0 ) ;
#endif
V_9 -> V_145 . V_151 = NULL ;
V_9 -> V_145 . V_152 = 0 ;
F_92 ( & V_121 , sizeof( V_121 ) ) ;
F_64 ( & V_9 -> V_153 , V_121 ) ;
V_9 -> V_39 = NULL ;
V_9 -> V_154 = 0 ;
F_93 ( V_9 ) ;
V_50 = F_94 ( V_9 , V_155 ) ;
if ( V_50 < 0 )
goto V_156;
V_50 = F_95 ( V_6 ) ;
if ( V_50 < 0 )
goto V_156;
V_50 = F_96 ( V_6 ) ;
if ( V_50 < 0 )
goto V_157;
return 0 ;
V_157:
F_97 ( V_6 ) ;
V_156:
F_98 ( V_9 -> V_125 ) ;
V_9 -> V_125 = NULL ;
return V_50 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_5 * V_158 )
{
struct V_38 * V_159 ;
int V_50 = - V_34 ;
V_159 = F_100 ( V_158 ) ;
if ( ! V_159 || V_159 -> V_36 != NULL )
goto V_93;
V_50 = F_101 ( V_159 , V_6 -> V_160 ) ;
V_93:
if ( V_159 )
F_41 ( V_159 ) ;
return V_50 ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_5 * V_158 )
{
struct V_38 * V_159 ;
int V_50 = - V_34 ;
V_159 = F_100 ( V_158 ) ;
if ( ! V_159 || V_159 -> V_36 != V_6 )
goto V_93;
F_103 ( V_159 , V_161 ) ;
V_50 = 0 ;
V_93:
if ( V_159 )
F_41 ( V_159 ) ;
return V_50 ;
}
static void F_104 ( struct V_5 * V_6 )
{
F_97 ( V_6 ) ;
F_105 ( V_6 ) ;
F_106 () ;
F_107 ( V_6 ) ;
}
static void F_108 ( struct V_5 * V_6 )
{
struct V_8 * V_162 = F_9 ( V_6 ) ;
F_109 ( V_6 ) ;
V_6 -> V_163 = & V_164 ;
V_6 -> V_165 = F_104 ;
V_6 -> V_166 |= V_167 ;
V_6 -> V_168 = 0 ;
V_6 -> V_35 = V_139 ;
V_6 -> V_169 = F_110 () ;
F_111 ( V_6 ) ;
F_112 ( V_6 , & V_170 ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
}
struct V_5 * F_113 ( const char * V_160 )
{
struct V_5 * V_36 ;
int V_50 ;
V_36 = F_114 ( sizeof( struct V_8 ) , V_160 ,
F_108 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_171 = & V_172 ;
V_50 = F_115 ( V_36 ) ;
if ( V_50 < 0 ) {
F_116 ( L_3 ,
V_160 , V_50 ) ;
F_107 ( V_36 ) ;
return NULL ;
}
return V_36 ;
}
void F_117 ( struct V_5 * V_36 )
{
struct V_8 * V_9 = F_9 ( V_36 ) ;
F_118 ( V_173 , & V_9 -> V_120 ) ;
}
static void F_119 ( struct V_5 * V_36 ,
struct V_174 * V_175 )
{
struct V_38 * V_159 ;
F_120 (hard_iface, &batadv_hardif_list, list) {
if ( V_159 -> V_36 == V_36 )
F_103 ( V_159 ,
V_161 ) ;
}
F_81 ( V_36 ) ;
F_121 ( V_36 , V_175 ) ;
}
int F_122 ( const struct V_5 * V_79 )
{
if ( V_79 -> V_163 -> V_176 == F_19 )
return 1 ;
return 0 ;
}
static int F_123 ( struct V_5 * V_6 , struct V_177 * V_178 )
{
V_178 -> V_179 = 0 ;
V_178 -> V_180 = 0 ;
F_124 ( V_178 , V_181 ) ;
V_178 -> V_182 = V_183 ;
V_178 -> V_184 = V_185 ;
V_178 -> V_186 = 0 ;
V_178 -> V_187 = V_188 ;
V_178 -> V_189 = V_190 ;
V_178 -> V_191 = 0 ;
V_178 -> V_192 = 0 ;
return 0 ;
}
static void F_125 ( struct V_5 * V_6 ,
struct V_193 * V_194 )
{
F_126 ( V_194 -> V_195 , L_4 , sizeof( V_194 -> V_195 ) ) ;
F_126 ( V_194 -> V_71 , V_196 , sizeof( V_194 -> V_71 ) ) ;
F_126 ( V_194 -> V_197 , L_5 , sizeof( V_194 -> V_197 ) ) ;
F_126 ( V_194 -> V_198 , L_6 , sizeof( V_194 -> V_198 ) ) ;
}
static T_5 F_127 ( struct V_5 * V_6 )
{
return - V_199 ;
}
static void F_128 ( struct V_5 * V_6 , T_5 V_200 )
{
}
static T_5 F_129 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_130 ( struct V_5 * V_6 , T_3 V_201 ,
T_1 * V_59 )
{
if ( V_201 == V_202 )
memcpy ( V_59 , V_203 ,
sizeof( V_203 ) ) ;
}
static void F_131 ( struct V_5 * V_6 ,
struct V_204 * V_10 ,
V_123 * V_59 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_205 ;
for ( V_205 = 0 ; V_205 < V_124 ; V_205 ++ )
V_59 [ V_205 ] = F_10 ( V_9 , V_205 ) ;
}
static int F_132 ( struct V_5 * V_6 , int V_201 )
{
if ( V_201 == V_202 )
return V_124 ;
return - V_199 ;
}
