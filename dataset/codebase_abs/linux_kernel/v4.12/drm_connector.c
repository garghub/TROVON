void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( & V_2 [ V_1 ] . V_3 ) ;
}
void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_5 ( & V_2 [ V_1 ] . V_3 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 ;
char * V_9 = NULL ;
if ( F_7 ( V_5 -> V_10 , & V_9 ) )
return;
if ( ! F_8 ( V_9 ,
V_5 ,
V_7 ) )
return;
if ( V_7 -> V_11 ) {
F_9 ( L_1 , V_5 -> V_10 ,
F_10 ( V_7 -> V_11 ) ) ;
V_5 -> V_11 = V_7 -> V_11 ;
}
F_11 ( L_2 ,
V_5 -> V_10 ,
V_7 -> V_12 , V_7 -> V_13 ,
V_7 -> V_14 ? V_7 -> V_15 : 60 ,
V_7 -> V_16 ? L_3 : L_4 ,
V_7 -> V_17 ? L_5 : L_4 ,
V_7 -> V_18 ? L_6 : L_4 ) ;
}
static void F_12 ( struct V_19 * V_19 )
{
struct V_4 * V_5 =
F_13 ( V_19 , struct V_4 , V_20 . V_21 ) ;
struct V_22 * V_23 = V_5 -> V_23 ;
F_14 ( V_23 , & V_5 -> V_20 ) ;
V_5 -> V_24 -> V_25 ( V_5 ) ;
}
int F_15 ( struct V_22 * V_23 ,
struct V_4 * V_5 ,
const struct V_26 * V_24 ,
int V_27 )
{
struct V_28 * V_29 = & V_23 -> V_30 ;
int V_31 ;
struct V_3 * V_32 =
& V_2 [ V_27 ] . V_3 ;
V_31 = F_16 ( V_23 , & V_5 -> V_20 ,
V_33 ,
false , F_12 ) ;
if ( V_31 )
return V_31 ;
V_5 -> V_20 . V_34 = & V_5 -> V_34 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_24 = V_24 ;
V_31 = F_17 ( & V_29 -> V_32 , 0 , 0 , V_35 ) ;
if ( V_31 < 0 )
goto V_36;
V_5 -> V_37 = V_31 ;
V_31 = 0 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_38 =
F_17 ( V_32 , 1 , 0 , V_35 ) ;
if ( V_5 -> V_38 < 0 ) {
V_31 = V_5 -> V_38 ;
goto V_39;
}
V_5 -> V_10 =
F_18 ( V_35 , L_7 ,
V_2 [ V_27 ] . V_10 ,
V_5 -> V_38 ) ;
if ( ! V_5 -> V_10 ) {
V_31 = - V_40 ;
goto V_41;
}
F_19 ( & V_5 -> V_42 ) ;
F_19 ( & V_5 -> V_43 ) ;
F_20 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = NULL ;
V_5 -> V_46 = V_47 ;
F_6 ( V_5 ) ;
F_21 ( & V_29 -> V_48 ) ;
F_22 ( & V_5 -> V_49 , & V_29 -> V_50 ) ;
V_29 -> V_51 ++ ;
F_23 ( & V_29 -> V_48 ) ;
if ( V_27 != V_52 )
F_24 ( & V_5 -> V_20 ,
V_29 -> V_53 ,
0 ) ;
F_24 ( & V_5 -> V_20 ,
V_29 -> V_54 , 0 ) ;
F_24 ( & V_5 -> V_20 ,
V_29 -> V_55 ,
0 ) ;
if ( F_25 ( V_23 , V_56 ) ) {
F_24 ( & V_5 -> V_20 , V_29 -> V_57 , 0 ) ;
}
V_5 -> V_58 = NULL ;
V_41:
if ( V_31 )
F_26 ( V_32 , V_5 -> V_38 ) ;
V_39:
if ( V_31 )
F_26 ( & V_29 -> V_32 , V_5 -> V_37 ) ;
V_36:
if ( V_31 )
F_14 ( V_23 , & V_5 -> V_20 ) ;
return V_31 ;
}
int F_27 ( struct V_4 * V_5 ,
struct V_59 * V_60 )
{
int V_1 ;
if ( F_28 ( V_5 -> V_60 ) )
return - V_61 ;
for ( V_1 = 0 ; V_1 < V_62 ; V_1 ++ ) {
if ( V_5 -> V_63 [ V_1 ] == 0 ) {
V_5 -> V_63 [ V_1 ] = V_60 -> V_20 . V_64 ;
return 0 ;
}
}
return - V_40 ;
}
static void F_29 ( struct V_4 * V_5 ,
struct V_65 * V_7 )
{
F_30 ( & V_7 -> V_49 ) ;
F_31 ( V_5 -> V_23 , V_7 ) ;
}
void F_32 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
struct V_65 * V_7 , * V_66 ;
if ( F_28 ( V_5 -> V_67 ) )
F_33 ( V_5 ) ;
if ( V_5 -> V_68 ) {
F_34 ( V_23 , V_5 -> V_68 ) ;
V_5 -> V_68 = NULL ;
}
F_35 (mode, t, &connector->probed_modes, head)
F_29 ( V_5 , V_7 ) ;
F_35 (mode, t, &connector->modes, head)
F_29 ( V_5 , V_7 ) ;
F_26 ( & V_2 [ V_5 -> V_27 ] . V_3 ,
V_5 -> V_38 ) ;
F_26 ( & V_23 -> V_30 . V_32 ,
V_5 -> V_37 ) ;
F_36 ( V_5 -> V_69 . V_70 ) ;
F_14 ( V_23 , & V_5 -> V_20 ) ;
F_36 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
F_21 ( & V_23 -> V_30 . V_48 ) ;
F_30 ( & V_5 -> V_49 ) ;
V_23 -> V_30 . V_51 -- ;
F_23 ( & V_23 -> V_30 . V_48 ) ;
F_28 ( V_5 -> V_71 && ! V_5 -> V_24 -> V_72 ) ;
if ( V_5 -> V_71 && V_5 -> V_24 -> V_72 )
V_5 -> V_24 -> V_72 ( V_5 ,
V_5 -> V_71 ) ;
F_37 ( & V_5 -> V_44 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_38 ( struct V_4 * V_5 )
{
int V_31 = 0 ;
if ( ! V_5 -> V_23 -> V_67 )
return 0 ;
F_39 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_67 )
goto V_73;
V_31 = F_40 ( V_5 ) ;
if ( V_31 )
goto V_73;
V_31 = F_41 ( V_5 ) ;
if ( V_31 ) {
goto V_74;
}
if ( V_5 -> V_24 -> V_75 ) {
V_31 = V_5 -> V_24 -> V_75 ( V_5 ) ;
if ( V_31 )
goto V_76;
}
F_42 ( V_5 -> V_23 , & V_5 -> V_20 ) ;
V_5 -> V_67 = true ;
goto V_73;
V_76:
F_43 ( V_5 ) ;
V_74:
F_44 ( V_5 ) ;
V_73:
F_45 ( & V_5 -> V_44 ) ;
return V_31 ;
}
void F_33 ( struct V_4 * V_5 )
{
F_39 ( & V_5 -> V_44 ) ;
if ( ! V_5 -> V_67 ) {
F_45 ( & V_5 -> V_44 ) ;
return;
}
if ( V_5 -> V_24 -> V_77 )
V_5 -> V_24 -> V_77 ( V_5 ) ;
F_44 ( V_5 ) ;
F_43 ( V_5 ) ;
V_5 -> V_67 = false ;
F_45 ( & V_5 -> V_44 ) ;
}
void F_46 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
struct V_78 V_79 ;
F_47 ( V_23 , & V_79 ) ;
F_48 (connector, &conn_iter)
F_33 ( V_5 ) ;
F_49 ( & V_79 ) ;
}
int F_50 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
struct V_78 V_79 ;
int V_31 = 0 ;
F_47 ( V_23 , & V_79 ) ;
F_48 (connector, &conn_iter) {
V_31 = F_38 ( V_5 ) ;
if ( V_31 )
break;
}
F_49 ( & V_79 ) ;
if ( V_31 )
F_46 ( V_23 ) ;
return V_31 ;
}
const char * F_51 ( enum V_80 V_46 )
{
if ( V_46 == V_81 )
return L_8 ;
else if ( V_46 == V_82 )
return L_9 ;
else
return L_10 ;
}
const char * F_10 ( enum V_83 V_11 )
{
switch ( V_11 ) {
case V_84 :
return L_11 ;
case V_85 :
return L_12 ;
case V_86 :
return L_13 ;
case V_87 :
return L_14 ;
default:
return L_10 ;
}
}
void F_47 ( struct V_22 * V_23 ,
struct V_78 * V_88 )
{
V_88 -> V_23 = V_23 ;
V_88 -> V_89 = NULL ;
F_52 ( & V_90 , 0 , 1 , NULL , V_91 ) ;
}
struct V_4 *
F_53 ( struct V_78 * V_88 )
{
struct V_4 * V_92 = V_88 -> V_89 ;
struct V_28 * V_29 = & V_88 -> V_23 -> V_30 ;
struct V_93 * V_94 ;
unsigned long V_95 ;
F_54 ( & V_29 -> V_48 , V_95 ) ;
V_94 = V_92 ? & V_92 -> V_49 : & V_29 -> V_50 ;
do {
if ( V_94 -> V_96 == & V_29 -> V_50 ) {
V_88 -> V_89 = NULL ;
break;
}
V_94 = V_94 -> V_96 ;
V_88 -> V_89 = F_55 ( V_94 , struct V_4 , V_49 ) ;
} while ( ! F_56 ( & V_88 -> V_89 -> V_20 . V_21 ) );
F_57 ( & V_29 -> V_48 , V_95 ) ;
if ( V_92 )
F_58 ( V_92 ) ;
return V_88 -> V_89 ;
}
void F_49 ( struct V_78 * V_88 )
{
V_88 -> V_23 = NULL ;
if ( V_88 -> V_89 )
F_58 ( V_88 -> V_89 ) ;
F_59 ( & V_90 , 0 , V_91 ) ;
}
const char * F_60 ( enum V_97 V_98 )
{
return V_99 [ V_98 ] . V_10 ;
}
int F_61 ( struct V_100 * V_101 ,
const T_1 * V_102 ,
unsigned int V_103 )
{
T_1 * V_104 = NULL ;
if ( ! V_102 && V_103 )
return - V_61 ;
if ( V_102 && V_103 ) {
V_104 = F_62 ( V_102 , sizeof( * V_102 ) * V_103 ,
V_35 ) ;
if ( ! V_104 )
return - V_40 ;
}
F_36 ( V_101 -> V_70 ) ;
V_101 -> V_70 = V_104 ;
V_101 -> V_105 = V_103 ;
return 0 ;
}
int F_63 ( struct V_22 * V_23 )
{
struct V_106 * V_107 ;
V_107 = F_64 ( V_23 , V_108 |
V_109 ,
L_15 , 0 ) ;
if ( ! V_107 )
return - V_40 ;
V_23 -> V_30 . V_53 = V_107 ;
V_107 = F_65 ( V_23 , 0 ,
L_16 , V_110 ,
F_2 ( V_110 ) ) ;
if ( ! V_107 )
return - V_40 ;
V_23 -> V_30 . V_54 = V_107 ;
V_107 = F_64 ( V_23 ,
V_108 |
V_109 ,
L_17 , 0 ) ;
if ( ! V_107 )
return - V_40 ;
V_23 -> V_30 . V_111 = V_107 ;
V_107 = F_64 ( V_23 ,
V_108 |
V_109 ,
L_18 , 0 ) ;
if ( ! V_107 )
return - V_40 ;
V_23 -> V_30 . V_112 = V_107 ;
V_107 = F_65 ( V_23 , 0 , L_19 ,
V_113 ,
F_2 ( V_113 ) ) ;
if ( ! V_107 )
return - V_40 ;
V_23 -> V_30 . V_55 = V_107 ;
return 0 ;
}
int F_66 ( struct V_22 * V_23 )
{
struct V_106 * V_114 ;
struct V_106 * V_115 ;
if ( V_23 -> V_30 . V_116 )
return 0 ;
V_114 =
F_65 ( V_23 , 0 ,
L_20 ,
V_117 ,
F_2 ( V_117 ) ) ;
V_23 -> V_30 . V_116 = V_114 ;
V_115 = F_65 ( V_23 , V_109 ,
L_21 ,
V_118 ,
F_2 ( V_118 ) ) ;
V_23 -> V_30 . V_119 = V_115 ;
return 0 ;
}
int F_67 ( struct V_22 * V_23 ,
unsigned int V_120 ,
const char * const V_43 [] )
{
struct V_106 * V_121 ;
struct V_106 * V_122 ;
unsigned int V_1 ;
if ( V_23 -> V_30 . V_123 )
return 0 ;
V_121 = F_65 ( V_23 , 0 ,
L_20 ,
V_124 ,
F_2 ( V_124 ) ) ;
if ( ! V_121 )
goto V_125;
V_23 -> V_30 . V_123 = V_121 ;
V_122 =
F_65 ( V_23 , V_109 ,
L_21 ,
V_126 ,
F_2 ( V_126 ) ) ;
if ( ! V_122 )
goto V_125;
V_23 -> V_30 . V_127 = V_122 ;
V_23 -> V_30 . V_128 =
F_68 ( V_23 , 0 , L_22 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_128 )
goto V_125;
V_23 -> V_30 . V_129 =
F_68 ( V_23 , 0 , L_23 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_129 )
goto V_125;
V_23 -> V_30 . V_130 =
F_68 ( V_23 , 0 , L_24 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_130 )
goto V_125;
V_23 -> V_30 . V_131 =
F_68 ( V_23 , 0 , L_25 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_131 )
goto V_125;
V_23 -> V_30 . V_132 =
F_64 ( V_23 , V_133 ,
L_26 , V_120 ) ;
if ( ! V_23 -> V_30 . V_132 )
goto V_125;
for ( V_1 = 0 ; V_1 < V_120 ; V_1 ++ )
F_69 ( V_23 -> V_30 . V_132 , V_1 ,
V_1 , V_43 [ V_1 ] ) ;
V_23 -> V_30 . V_134 =
F_68 ( V_23 , 0 , L_27 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_134 )
goto V_125;
V_23 -> V_30 . V_135 =
F_68 ( V_23 , 0 , L_28 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_135 )
goto V_125;
V_23 -> V_30 . V_136 =
F_68 ( V_23 , 0 , L_29 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_136 )
goto V_125;
V_23 -> V_30 . V_137 =
F_68 ( V_23 , 0 , L_30 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_137 )
goto V_125;
V_23 -> V_30 . V_138 =
F_68 ( V_23 , 0 , L_31 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_138 )
goto V_125;
V_23 -> V_30 . V_139 =
F_68 ( V_23 , 0 , L_32 , 0 , 100 ) ;
if ( ! V_23 -> V_30 . V_139 )
goto V_125;
return 0 ;
V_125:
return - V_40 ;
}
int F_70 ( struct V_22 * V_23 )
{
struct V_106 * V_140 ;
if ( V_23 -> V_30 . V_141 )
return 0 ;
V_140 =
F_65 ( V_23 , 0 , L_33 ,
V_142 ,
F_2 ( V_142 ) ) ;
V_23 -> V_30 . V_141 = V_140 ;
return 0 ;
}
int F_71 ( struct V_22 * V_23 )
{
if ( V_23 -> V_30 . V_143 )
return 0 ;
V_23 -> V_30 . V_143 =
F_65 ( V_23 , 0 , L_34 ,
V_144 ,
F_2 ( V_144 ) ) ;
if ( V_23 -> V_30 . V_143 == NULL )
return - V_40 ;
return 0 ;
}
int F_72 ( struct V_22 * V_23 )
{
if ( V_23 -> V_30 . V_145 && V_23 -> V_30 . V_146 )
return 0 ;
V_23 -> V_30 . V_145 =
F_68 ( V_23 , V_109 , L_35 , 0 , 0xffffffff ) ;
V_23 -> V_30 . V_146 =
F_68 ( V_23 , V_109 , L_36 , 0 , 0xffffffff ) ;
if ( V_23 -> V_30 . V_145 == NULL ||
V_23 -> V_30 . V_146 == NULL )
return - V_40 ;
return 0 ;
}
int F_73 ( struct V_4 * V_5 ,
const char * V_147 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
int V_31 ;
V_31 = F_74 ( V_23 ,
& V_5 -> V_148 ,
strlen ( V_147 ) + 1 ,
V_147 ,
& V_5 -> V_20 ,
V_23 -> V_30 . V_111 ) ;
return V_31 ;
}
int F_75 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
char V_149 [ 256 ] ;
int V_31 ;
if ( ! V_5 -> V_150 ) {
V_31 = F_74 ( V_23 ,
& V_5 -> V_151 ,
0 ,
NULL ,
& V_5 -> V_20 ,
V_23 -> V_30 . V_112 ) ;
return V_31 ;
}
snprintf ( V_149 , 256 , L_37 ,
V_5 -> V_68 -> V_64 , V_5 -> V_152 ,
V_5 -> V_153 , V_5 -> V_154 ,
V_5 -> V_155 , V_5 -> V_156 ,
V_5 -> V_157 , V_5 -> V_158 ) ;
V_31 = F_74 ( V_23 ,
& V_5 -> V_151 ,
strlen ( V_149 ) + 1 ,
V_149 ,
& V_5 -> V_20 ,
V_23 -> V_30 . V_112 ) ;
return V_31 ;
}
int F_76 ( struct V_4 * V_5 ,
const struct V_159 * V_159 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
T_2 V_160 = 0 ;
int V_31 ;
if ( V_5 -> V_161 )
return 0 ;
if ( V_159 )
V_160 = V_162 * ( 1 + V_159 -> V_163 ) ;
V_31 = F_74 ( V_23 ,
& V_5 -> V_45 ,
V_160 ,
V_159 ,
& V_5 -> V_20 ,
V_23 -> V_30 . V_53 ) ;
return V_31 ;
}
void F_77 ( struct V_4 * V_5 ,
T_3 V_164 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
F_78 ( & V_23 -> V_30 . V_165 , NULL ) ;
V_5 -> V_71 -> V_164 = V_164 ;
F_79 ( & V_23 -> V_30 . V_165 ) ;
}
int F_80 ( struct V_166 * V_167 ,
struct V_106 * V_168 ,
T_3 V_169 )
{
int V_31 = - V_61 ;
struct V_4 * V_5 = F_81 ( V_167 ) ;
if ( V_168 == V_5 -> V_23 -> V_30 . V_54 ) {
V_31 = (* V_5 -> V_24 -> V_170 )( V_5 , ( int ) V_169 ) ;
} else if ( V_5 -> V_24 -> V_171 )
V_31 = V_5 -> V_24 -> V_171 ( V_5 , V_168 , V_169 ) ;
if ( ! V_31 )
F_82 ( & V_5 -> V_20 , V_168 , V_169 ) ;
return V_31 ;
}
int F_83 ( struct V_22 * V_23 ,
void * V_172 , struct V_173 * V_174 )
{
struct V_175 * V_176 = V_172 ;
struct V_177 V_178 = {
. V_169 = V_176 -> V_169 ,
. V_179 = V_176 -> V_179 ,
. V_180 = V_176 -> V_181 ,
. V_182 = V_33
} ;
return F_84 ( V_23 , & V_178 , V_174 ) ;
}
static struct V_59 * F_85 ( struct V_4 * V_5 )
{
if ( V_5 -> V_71 )
return V_5 -> V_71 -> V_183 ;
return V_5 -> V_60 ;
}
static bool F_86 ( const struct V_65 * V_7 ,
const struct V_173 * V_174 )
{
if ( ! V_174 -> V_184 && F_87 ( V_7 ) )
return false ;
return true ;
}
int F_88 ( struct V_22 * V_23 , void * V_172 ,
struct V_173 * V_174 )
{
struct V_185 * V_186 = V_172 ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
struct V_65 * V_7 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_31 = 0 ;
int V_189 = 0 ;
int V_1 ;
struct V_190 V_191 ;
struct V_190 T_4 * V_192 ;
T_5 T_4 * V_193 ;
if ( ! F_25 ( V_23 , V_194 ) )
return - V_61 ;
memset ( & V_191 , 0 , sizeof( struct V_190 ) ) ;
V_5 = F_89 ( V_23 , V_186 -> V_181 ) ;
if ( ! V_5 )
return - V_195 ;
for ( V_1 = 0 ; V_1 < V_62 ; V_1 ++ )
if ( V_5 -> V_63 [ V_1 ] != 0 )
V_188 ++ ;
if ( ( V_186 -> V_196 >= V_188 ) && V_188 ) {
V_189 = 0 ;
V_193 = ( T_5 T_4 * ) ( unsigned long ) ( V_186 -> V_197 ) ;
for ( V_1 = 0 ; V_1 < V_62 ; V_1 ++ ) {
if ( V_5 -> V_63 [ V_1 ] != 0 ) {
if ( F_90 ( V_5 -> V_63 [ V_1 ] ,
V_193 + V_189 ) ) {
V_31 = - V_198 ;
goto V_199;
}
V_189 ++ ;
}
}
}
V_186 -> V_196 = V_188 ;
V_186 -> V_181 = V_5 -> V_20 . V_64 ;
V_186 -> V_27 = V_5 -> V_27 ;
V_186 -> V_38 = V_5 -> V_38 ;
F_39 ( & V_23 -> V_30 . V_44 ) ;
if ( V_186 -> V_200 == 0 ) {
V_5 -> V_24 -> V_201 ( V_5 ,
V_23 -> V_30 . V_202 ,
V_23 -> V_30 . V_203 ) ;
}
V_186 -> V_204 = V_5 -> V_69 . V_205 ;
V_186 -> V_206 = V_5 -> V_69 . V_207 ;
V_186 -> V_208 = V_5 -> V_69 . V_97 ;
V_186 -> V_209 = V_5 -> V_46 ;
F_91 (mode, &connector->modes, head)
if ( F_86 ( V_7 , V_174 ) )
V_187 ++ ;
if ( ( V_186 -> V_200 >= V_187 ) && V_187 ) {
V_189 = 0 ;
V_192 = (struct V_190 T_4 * ) ( unsigned long ) V_186 -> V_210 ;
F_91 (mode, &connector->modes, head) {
if ( ! F_86 ( V_7 , V_174 ) )
continue;
F_92 ( & V_191 , V_7 ) ;
if ( F_93 ( V_192 + V_189 ,
& V_191 , sizeof( V_191 ) ) ) {
V_31 = - V_198 ;
F_45 ( & V_23 -> V_30 . V_44 ) ;
goto V_199;
}
V_189 ++ ;
}
}
V_186 -> V_200 = V_187 ;
F_45 ( & V_23 -> V_30 . V_44 ) ;
F_78 ( & V_23 -> V_30 . V_165 , NULL ) ;
V_60 = F_85 ( V_5 ) ;
if ( V_60 )
V_186 -> V_211 = V_60 -> V_20 . V_64 ;
else
V_186 -> V_211 = 0 ;
V_31 = F_94 ( & V_5 -> V_20 , V_174 -> V_212 ,
( T_5 T_4 * ) ( unsigned long ) ( V_186 -> V_213 ) ,
( T_3 T_4 * ) ( unsigned long ) ( V_186 -> V_214 ) ,
& V_186 -> V_215 ) ;
F_79 ( & V_23 -> V_30 . V_165 ) ;
V_199:
F_58 ( V_5 ) ;
return V_31 ;
}
static void F_95 ( struct V_19 * V_19 )
{
struct V_216 * V_217 = F_13 ( V_19 , struct V_216 , V_21 ) ;
struct V_22 * V_23 = V_217 -> V_23 ;
F_39 ( & V_23 -> V_30 . V_218 ) ;
F_96 ( & V_23 -> V_30 . V_219 , V_217 -> V_64 ) ;
F_45 ( & V_23 -> V_30 . V_218 ) ;
F_36 ( V_217 ) ;
}
void F_34 ( struct V_22 * V_23 ,
struct V_216 * V_217 )
{
F_97 ( & V_217 -> V_21 , F_95 ) ;
}
struct V_216 * F_98 ( struct V_22 * V_23 ,
char V_220 [ 8 ] )
{
struct V_216 * V_217 ;
int V_64 ;
F_39 ( & V_23 -> V_30 . V_218 ) ;
F_99 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_217 -> V_221 , V_220 , 8 ) ) {
if ( ! F_56 ( & V_217 -> V_21 ) )
V_217 = NULL ;
F_45 ( & V_23 -> V_30 . V_218 ) ;
return V_217 ;
}
}
F_45 ( & V_23 -> V_30 . V_218 ) ;
return NULL ;
}
struct V_216 * F_100 ( struct V_22 * V_23 ,
char V_220 [ 8 ] )
{
struct V_216 * V_217 ;
int V_31 ;
V_217 = F_101 ( sizeof( * V_217 ) , V_35 ) ;
if ( ! V_217 )
return F_102 ( - V_40 ) ;
F_103 ( & V_217 -> V_21 ) ;
memcpy ( V_217 -> V_221 , V_220 , 8 ) ;
V_217 -> V_23 = V_23 ;
F_39 ( & V_23 -> V_30 . V_218 ) ;
V_31 = F_104 ( & V_23 -> V_30 . V_219 , V_217 , 1 , 0 , V_35 ) ;
if ( V_31 >= 0 ) {
V_217 -> V_64 = V_31 ;
} else {
F_36 ( V_217 ) ;
V_217 = F_102 ( V_31 ) ;
}
F_45 ( & V_23 -> V_30 . V_218 ) ;
return V_217 ;
}
