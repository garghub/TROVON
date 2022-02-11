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
const char * V_12 ;
switch ( V_7 -> V_11 ) {
case V_13 :
V_12 = L_1 ;
break;
case V_14 :
V_12 = L_2 ;
break;
default:
case V_15 :
V_12 = L_3 ;
break;
}
F_9 ( L_4 , V_5 -> V_10 , V_12 ) ;
V_5 -> V_11 = V_7 -> V_11 ;
}
F_10 ( L_5 ,
V_5 -> V_10 ,
V_7 -> V_16 , V_7 -> V_17 ,
V_7 -> V_18 ? V_7 -> V_19 : 60 ,
V_7 -> V_20 ? L_6 : L_7 ,
V_7 -> V_21 ? L_8 : L_7 ,
V_7 -> V_22 ? L_9 : L_7 ) ;
}
static void F_11 ( struct V_23 * V_23 )
{
struct V_4 * V_5 =
F_12 ( V_23 , struct V_4 , V_24 . V_25 ) ;
struct V_26 * V_27 = V_5 -> V_27 ;
F_13 ( V_27 , & V_5 -> V_24 ) ;
V_5 -> V_28 -> V_29 ( V_5 ) ;
}
int F_14 ( struct V_26 * V_27 ,
struct V_4 * V_5 ,
const struct V_30 * V_28 ,
int V_31 )
{
struct V_32 * V_33 = & V_27 -> V_34 ;
int V_35 ;
struct V_3 * V_36 =
& V_2 [ V_31 ] . V_3 ;
V_35 = F_15 ( V_27 , & V_5 -> V_24 ,
V_37 ,
false , F_11 ) ;
if ( V_35 )
return V_35 ;
V_5 -> V_24 . V_38 = & V_5 -> V_38 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_28 = V_28 ;
V_35 = F_16 ( & V_33 -> V_36 , 0 , 0 , V_39 ) ;
if ( V_35 < 0 )
goto V_40;
V_5 -> V_41 = V_35 ;
V_35 = 0 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_42 =
F_16 ( V_36 , 1 , 0 , V_39 ) ;
if ( V_5 -> V_42 < 0 ) {
V_35 = V_5 -> V_42 ;
goto V_43;
}
V_5 -> V_10 =
F_17 ( V_39 , L_10 ,
V_2 [ V_31 ] . V_10 ,
V_5 -> V_42 ) ;
if ( ! V_5 -> V_10 ) {
V_35 = - V_44 ;
goto V_45;
}
F_18 ( & V_5 -> V_46 ) ;
F_18 ( & V_5 -> V_47 ) ;
F_19 ( & V_5 -> V_48 ) ;
V_5 -> V_49 = NULL ;
V_5 -> V_50 = V_51 ;
F_6 ( V_5 ) ;
F_20 ( & V_33 -> V_52 ) ;
F_21 ( & V_5 -> V_53 , & V_33 -> V_54 ) ;
V_33 -> V_55 ++ ;
F_22 ( & V_33 -> V_52 ) ;
if ( V_31 != V_56 )
F_23 ( & V_5 -> V_24 ,
V_33 -> V_57 ,
0 ) ;
F_23 ( & V_5 -> V_24 ,
V_33 -> V_58 , 0 ) ;
if ( F_24 ( V_27 , V_59 ) ) {
F_23 ( & V_5 -> V_24 , V_33 -> V_60 , 0 ) ;
}
V_5 -> V_61 = NULL ;
V_45:
if ( V_35 )
F_25 ( V_36 , V_5 -> V_42 ) ;
V_43:
if ( V_35 )
F_25 ( & V_33 -> V_36 , V_5 -> V_41 ) ;
V_40:
if ( V_35 )
F_13 ( V_27 , & V_5 -> V_24 ) ;
return V_35 ;
}
int F_26 ( struct V_4 * V_5 ,
struct V_62 * V_63 )
{
int V_1 ;
if ( F_27 ( V_5 -> V_63 ) )
return - V_64 ;
for ( V_1 = 0 ; V_1 < V_65 ; V_1 ++ ) {
if ( V_5 -> V_66 [ V_1 ] == 0 ) {
V_5 -> V_66 [ V_1 ] = V_63 -> V_24 . V_67 ;
return 0 ;
}
}
return - V_44 ;
}
static void F_28 ( struct V_4 * V_5 ,
struct V_68 * V_7 )
{
F_29 ( & V_7 -> V_53 ) ;
F_30 ( V_5 -> V_27 , V_7 ) ;
}
void F_31 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
struct V_68 * V_7 , * V_69 ;
if ( F_27 ( V_5 -> V_70 ) )
F_32 ( V_5 ) ;
if ( V_5 -> V_71 ) {
F_33 ( V_27 , V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
}
F_34 (mode, t, &connector->probed_modes, head)
F_28 ( V_5 , V_7 ) ;
F_34 (mode, t, &connector->modes, head)
F_28 ( V_5 , V_7 ) ;
F_25 ( & V_2 [ V_5 -> V_31 ] . V_3 ,
V_5 -> V_42 ) ;
F_25 ( & V_27 -> V_34 . V_36 ,
V_5 -> V_41 ) ;
F_35 ( V_5 -> V_72 . V_73 ) ;
F_13 ( V_27 , & V_5 -> V_24 ) ;
F_35 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
F_20 ( & V_27 -> V_34 . V_52 ) ;
F_29 ( & V_5 -> V_53 ) ;
V_27 -> V_34 . V_55 -- ;
F_22 ( & V_27 -> V_34 . V_52 ) ;
F_27 ( V_5 -> V_74 && ! V_5 -> V_28 -> V_75 ) ;
if ( V_5 -> V_74 && V_5 -> V_28 -> V_75 )
V_5 -> V_28 -> V_75 ( V_5 ,
V_5 -> V_74 ) ;
F_36 ( & V_5 -> V_48 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_37 ( struct V_4 * V_5 )
{
int V_35 = 0 ;
if ( ! V_5 -> V_27 -> V_70 )
return 0 ;
F_38 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_70 )
goto V_76;
V_35 = F_39 ( V_5 ) ;
if ( V_35 )
goto V_76;
V_35 = F_40 ( V_5 ) ;
if ( V_35 ) {
goto V_77;
}
if ( V_5 -> V_28 -> V_78 ) {
V_35 = V_5 -> V_28 -> V_78 ( V_5 ) ;
if ( V_35 )
goto V_79;
}
F_41 ( V_5 -> V_27 , & V_5 -> V_24 ) ;
V_5 -> V_70 = true ;
goto V_76;
V_79:
F_42 ( V_5 ) ;
V_77:
F_43 ( V_5 ) ;
V_76:
F_44 ( & V_5 -> V_48 ) ;
return V_35 ;
}
void F_32 ( struct V_4 * V_5 )
{
F_38 ( & V_5 -> V_48 ) ;
if ( ! V_5 -> V_70 ) {
F_44 ( & V_5 -> V_48 ) ;
return;
}
if ( V_5 -> V_28 -> V_80 )
V_5 -> V_28 -> V_80 ( V_5 ) ;
F_43 ( V_5 ) ;
F_42 ( V_5 ) ;
V_5 -> V_70 = false ;
F_44 ( & V_5 -> V_48 ) ;
}
void F_45 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
struct V_81 V_82 ;
F_46 ( V_27 , & V_82 ) ;
F_47 (connector, &conn_iter)
F_32 ( V_5 ) ;
F_48 ( & V_82 ) ;
}
int F_49 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
struct V_81 V_82 ;
int V_35 = 0 ;
F_46 ( V_27 , & V_82 ) ;
F_47 (connector, &conn_iter) {
V_35 = F_37 ( V_5 ) ;
if ( V_35 )
break;
}
F_48 ( & V_82 ) ;
if ( V_35 )
F_45 ( V_27 ) ;
return V_35 ;
}
const char * F_50 ( enum V_83 V_50 )
{
if ( V_50 == V_84 )
return L_11 ;
else if ( V_50 == V_85 )
return L_12 ;
else
return L_13 ;
}
void F_46 ( struct V_26 * V_27 ,
struct V_81 * V_86 )
{
V_86 -> V_27 = V_27 ;
V_86 -> V_87 = NULL ;
F_51 ( & V_88 , 0 , 1 , NULL , V_89 ) ;
}
struct V_4 *
F_52 ( struct V_81 * V_86 )
{
struct V_4 * V_90 = V_86 -> V_87 ;
struct V_32 * V_33 = & V_86 -> V_27 -> V_34 ;
struct V_91 * V_92 ;
unsigned long V_93 ;
F_53 ( & V_33 -> V_52 , V_93 ) ;
V_92 = V_90 ? & V_90 -> V_53 : & V_33 -> V_54 ;
do {
if ( V_92 -> V_94 == & V_33 -> V_54 ) {
V_86 -> V_87 = NULL ;
break;
}
V_92 = V_92 -> V_94 ;
V_86 -> V_87 = F_54 ( V_92 , struct V_4 , V_53 ) ;
} while ( ! F_55 ( & V_86 -> V_87 -> V_24 . V_25 ) );
F_56 ( & V_33 -> V_52 , V_93 ) ;
if ( V_90 )
F_57 ( V_90 ) ;
return V_86 -> V_87 ;
}
void F_48 ( struct V_81 * V_86 )
{
V_86 -> V_27 = NULL ;
if ( V_86 -> V_87 )
F_57 ( V_86 -> V_87 ) ;
F_58 ( & V_88 , 0 , V_89 ) ;
}
const char * F_59 ( enum V_95 V_96 )
{
return V_97 [ V_96 ] . V_10 ;
}
int F_60 ( struct V_98 * V_99 ,
const T_1 * V_100 ,
unsigned int V_101 )
{
T_1 * V_102 = NULL ;
if ( ! V_100 && V_101 )
return - V_64 ;
if ( V_100 && V_101 ) {
V_102 = F_61 ( V_100 , sizeof( * V_100 ) * V_101 ,
V_39 ) ;
if ( ! V_102 )
return - V_44 ;
}
F_35 ( V_99 -> V_73 ) ;
V_99 -> V_73 = V_102 ;
V_99 -> V_103 = V_101 ;
return 0 ;
}
int F_62 ( struct V_26 * V_27 )
{
struct V_104 * V_105 ;
V_105 = F_63 ( V_27 , V_106 |
V_107 ,
L_14 , 0 ) ;
if ( ! V_105 )
return - V_44 ;
V_27 -> V_34 . V_57 = V_105 ;
V_105 = F_64 ( V_27 , 0 ,
L_15 , V_108 ,
F_2 ( V_108 ) ) ;
if ( ! V_105 )
return - V_44 ;
V_27 -> V_34 . V_58 = V_105 ;
V_105 = F_63 ( V_27 ,
V_106 |
V_107 ,
L_16 , 0 ) ;
if ( ! V_105 )
return - V_44 ;
V_27 -> V_34 . V_109 = V_105 ;
V_105 = F_63 ( V_27 ,
V_106 |
V_107 ,
L_17 , 0 ) ;
if ( ! V_105 )
return - V_44 ;
V_27 -> V_34 . V_110 = V_105 ;
return 0 ;
}
int F_65 ( struct V_26 * V_27 )
{
struct V_104 * V_111 ;
struct V_104 * V_112 ;
if ( V_27 -> V_34 . V_113 )
return 0 ;
V_111 =
F_64 ( V_27 , 0 ,
L_18 ,
V_114 ,
F_2 ( V_114 ) ) ;
V_27 -> V_34 . V_113 = V_111 ;
V_112 = F_64 ( V_27 , V_107 ,
L_19 ,
V_115 ,
F_2 ( V_115 ) ) ;
V_27 -> V_34 . V_116 = V_112 ;
return 0 ;
}
int F_66 ( struct V_26 * V_27 ,
unsigned int V_117 ,
const char * const V_47 [] )
{
struct V_104 * V_118 ;
struct V_104 * V_119 ;
unsigned int V_1 ;
if ( V_27 -> V_34 . V_120 )
return 0 ;
V_118 = F_64 ( V_27 , 0 ,
L_18 ,
V_121 ,
F_2 ( V_121 ) ) ;
if ( ! V_118 )
goto V_122;
V_27 -> V_34 . V_120 = V_118 ;
V_119 =
F_64 ( V_27 , V_107 ,
L_19 ,
V_123 ,
F_2 ( V_123 ) ) ;
if ( ! V_119 )
goto V_122;
V_27 -> V_34 . V_124 = V_119 ;
V_27 -> V_34 . V_125 =
F_67 ( V_27 , 0 , L_20 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_125 )
goto V_122;
V_27 -> V_34 . V_126 =
F_67 ( V_27 , 0 , L_21 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_126 )
goto V_122;
V_27 -> V_34 . V_127 =
F_67 ( V_27 , 0 , L_22 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_127 )
goto V_122;
V_27 -> V_34 . V_128 =
F_67 ( V_27 , 0 , L_23 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_128 )
goto V_122;
V_27 -> V_34 . V_129 =
F_63 ( V_27 , V_130 ,
L_24 , V_117 ) ;
if ( ! V_27 -> V_34 . V_129 )
goto V_122;
for ( V_1 = 0 ; V_1 < V_117 ; V_1 ++ )
F_68 ( V_27 -> V_34 . V_129 , V_1 ,
V_1 , V_47 [ V_1 ] ) ;
V_27 -> V_34 . V_131 =
F_67 ( V_27 , 0 , L_25 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_131 )
goto V_122;
V_27 -> V_34 . V_132 =
F_67 ( V_27 , 0 , L_26 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_132 )
goto V_122;
V_27 -> V_34 . V_133 =
F_67 ( V_27 , 0 , L_27 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_133 )
goto V_122;
V_27 -> V_34 . V_134 =
F_67 ( V_27 , 0 , L_28 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_134 )
goto V_122;
V_27 -> V_34 . V_135 =
F_67 ( V_27 , 0 , L_29 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_135 )
goto V_122;
V_27 -> V_34 . V_136 =
F_67 ( V_27 , 0 , L_30 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_136 )
goto V_122;
return 0 ;
V_122:
return - V_44 ;
}
int F_69 ( struct V_26 * V_27 )
{
struct V_104 * V_137 ;
if ( V_27 -> V_34 . V_138 )
return 0 ;
V_137 =
F_64 ( V_27 , 0 , L_31 ,
V_139 ,
F_2 ( V_139 ) ) ;
V_27 -> V_34 . V_138 = V_137 ;
return 0 ;
}
int F_70 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_140 )
return 0 ;
V_27 -> V_34 . V_140 =
F_64 ( V_27 , 0 , L_32 ,
V_141 ,
F_2 ( V_141 ) ) ;
if ( V_27 -> V_34 . V_140 == NULL )
return - V_44 ;
return 0 ;
}
int F_71 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_142 && V_27 -> V_34 . V_143 )
return 0 ;
V_27 -> V_34 . V_142 =
F_67 ( V_27 , V_107 , L_33 , 0 , 0xffffffff ) ;
V_27 -> V_34 . V_143 =
F_67 ( V_27 , V_107 , L_34 , 0 , 0xffffffff ) ;
if ( V_27 -> V_34 . V_142 == NULL ||
V_27 -> V_34 . V_143 == NULL )
return - V_44 ;
return 0 ;
}
int F_72 ( struct V_4 * V_5 ,
const char * V_144 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
int V_35 ;
V_35 = F_73 ( V_27 ,
& V_5 -> V_145 ,
strlen ( V_144 ) + 1 ,
V_144 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_109 ) ;
return V_35 ;
}
int F_74 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
char V_146 [ 256 ] ;
int V_35 ;
if ( ! V_5 -> V_147 ) {
V_35 = F_73 ( V_27 ,
& V_5 -> V_148 ,
0 ,
NULL ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_110 ) ;
return V_35 ;
}
snprintf ( V_146 , 256 , L_35 ,
V_5 -> V_71 -> V_67 , V_5 -> V_149 ,
V_5 -> V_150 , V_5 -> V_151 ,
V_5 -> V_152 , V_5 -> V_153 ,
V_5 -> V_154 , V_5 -> V_155 ) ;
V_35 = F_73 ( V_27 ,
& V_5 -> V_148 ,
strlen ( V_146 ) + 1 ,
V_146 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_110 ) ;
return V_35 ;
}
int F_75 ( struct V_4 * V_5 ,
const struct V_156 * V_156 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
T_2 V_157 = 0 ;
int V_35 ;
if ( V_5 -> V_158 )
return 0 ;
if ( V_156 )
V_157 = V_159 * ( 1 + V_156 -> V_160 ) ;
V_35 = F_73 ( V_27 ,
& V_5 -> V_49 ,
V_157 ,
V_156 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_57 ) ;
return V_35 ;
}
int F_76 ( struct V_161 * V_162 ,
struct V_104 * V_163 ,
T_3 V_164 )
{
int V_35 = - V_64 ;
struct V_4 * V_5 = F_77 ( V_162 ) ;
if ( V_163 == V_5 -> V_27 -> V_34 . V_58 ) {
V_35 = (* V_5 -> V_28 -> V_165 )( V_5 , ( int ) V_164 ) ;
} else if ( V_5 -> V_28 -> V_166 )
V_35 = V_5 -> V_28 -> V_166 ( V_5 , V_163 , V_164 ) ;
if ( ! V_35 )
F_78 ( & V_5 -> V_24 , V_163 , V_164 ) ;
return V_35 ;
}
int F_79 ( struct V_26 * V_27 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_170 * V_171 = V_167 ;
struct V_172 V_173 = {
. V_164 = V_171 -> V_164 ,
. V_174 = V_171 -> V_174 ,
. V_175 = V_171 -> V_176 ,
. V_177 = V_37
} ;
return F_80 ( V_27 , & V_173 , V_169 ) ;
}
static struct V_62 * F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 )
return V_5 -> V_74 -> V_178 ;
return V_5 -> V_63 ;
}
static bool F_82 ( const struct V_68 * V_7 ,
const struct V_168 * V_169 )
{
if ( ! V_169 -> V_179 && F_83 ( V_7 ) )
return false ;
return true ;
}
int F_84 ( struct V_26 * V_27 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_180 * V_181 = V_167 ;
struct V_4 * V_5 ;
struct V_62 * V_63 ;
struct V_68 * V_7 ;
int V_182 = 0 ;
int V_183 = 0 ;
int V_35 = 0 ;
int V_184 = 0 ;
int V_1 ;
struct V_185 V_186 ;
struct V_185 T_4 * V_187 ;
T_5 T_4 * V_188 ;
if ( ! F_24 ( V_27 , V_189 ) )
return - V_64 ;
memset ( & V_186 , 0 , sizeof( struct V_185 ) ) ;
V_5 = F_85 ( V_27 , V_181 -> V_176 ) ;
if ( ! V_5 )
return - V_190 ;
F_86 ( & V_27 -> V_34 . V_191 , NULL ) ;
V_63 = F_81 ( V_5 ) ;
if ( V_63 )
V_181 -> V_192 = V_63 -> V_24 . V_67 ;
else
V_181 -> V_192 = 0 ;
V_35 = F_87 ( & V_5 -> V_24 , V_169 -> V_193 ,
( T_5 T_4 * ) ( unsigned long ) ( V_181 -> V_194 ) ,
( T_3 T_4 * ) ( unsigned long ) ( V_181 -> V_195 ) ,
& V_181 -> V_196 ) ;
F_88 ( & V_27 -> V_34 . V_191 ) ;
if ( V_35 )
goto V_197;
for ( V_1 = 0 ; V_1 < V_65 ; V_1 ++ )
if ( V_5 -> V_66 [ V_1 ] != 0 )
V_183 ++ ;
if ( ( V_181 -> V_198 >= V_183 ) && V_183 ) {
V_184 = 0 ;
V_188 = ( T_5 T_4 * ) ( unsigned long ) ( V_181 -> V_199 ) ;
for ( V_1 = 0 ; V_1 < V_65 ; V_1 ++ ) {
if ( V_5 -> V_66 [ V_1 ] != 0 ) {
if ( F_89 ( V_5 -> V_66 [ V_1 ] ,
V_188 + V_184 ) ) {
V_35 = - V_200 ;
goto V_197;
}
V_184 ++ ;
}
}
}
V_181 -> V_198 = V_183 ;
V_181 -> V_176 = V_5 -> V_24 . V_67 ;
V_181 -> V_31 = V_5 -> V_31 ;
V_181 -> V_42 = V_5 -> V_42 ;
F_38 ( & V_27 -> V_34 . V_48 ) ;
if ( V_181 -> V_201 == 0 ) {
V_5 -> V_28 -> V_202 ( V_5 ,
V_27 -> V_34 . V_203 ,
V_27 -> V_34 . V_204 ) ;
}
V_181 -> V_205 = V_5 -> V_72 . V_206 ;
V_181 -> V_207 = V_5 -> V_72 . V_208 ;
V_181 -> V_209 = V_5 -> V_72 . V_95 ;
V_181 -> V_210 = V_5 -> V_50 ;
F_90 (mode, &connector->modes, head)
if ( F_82 ( V_7 , V_169 ) )
V_182 ++ ;
if ( ( V_181 -> V_201 >= V_182 ) && V_182 ) {
V_184 = 0 ;
V_187 = (struct V_185 T_4 * ) ( unsigned long ) V_181 -> V_211 ;
F_90 (mode, &connector->modes, head) {
if ( ! F_82 ( V_7 , V_169 ) )
continue;
F_91 ( & V_186 , V_7 ) ;
if ( F_92 ( V_187 + V_184 ,
& V_186 , sizeof( V_186 ) ) ) {
V_35 = - V_200 ;
goto V_212;
}
V_184 ++ ;
}
}
V_181 -> V_201 = V_182 ;
V_212:
F_44 ( & V_27 -> V_34 . V_48 ) ;
V_197:
F_57 ( V_5 ) ;
return V_35 ;
}
static void F_93 ( struct V_23 * V_23 )
{
struct V_213 * V_214 = F_12 ( V_23 , struct V_213 , V_25 ) ;
struct V_26 * V_27 = V_214 -> V_27 ;
F_38 ( & V_27 -> V_34 . V_215 ) ;
F_94 ( & V_27 -> V_34 . V_216 , V_214 -> V_67 ) ;
F_44 ( & V_27 -> V_34 . V_215 ) ;
F_35 ( V_214 ) ;
}
void F_33 ( struct V_26 * V_27 ,
struct V_213 * V_214 )
{
F_95 ( & V_214 -> V_25 , F_93 ) ;
}
struct V_213 * F_96 ( struct V_26 * V_27 ,
char V_217 [ 8 ] )
{
struct V_213 * V_214 ;
int V_67 ;
F_38 ( & V_27 -> V_34 . V_215 ) ;
F_97 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_214 -> V_218 , V_217 , 8 ) ) {
if ( ! F_55 ( & V_214 -> V_25 ) )
V_214 = NULL ;
F_44 ( & V_27 -> V_34 . V_215 ) ;
return V_214 ;
}
}
F_44 ( & V_27 -> V_34 . V_215 ) ;
return NULL ;
}
struct V_213 * F_98 ( struct V_26 * V_27 ,
char V_217 [ 8 ] )
{
struct V_213 * V_214 ;
int V_35 ;
V_214 = F_99 ( sizeof( * V_214 ) , V_39 ) ;
if ( ! V_214 )
return F_100 ( - V_44 ) ;
F_101 ( & V_214 -> V_25 ) ;
memcpy ( V_214 -> V_218 , V_217 , 8 ) ;
V_214 -> V_27 = V_27 ;
F_38 ( & V_27 -> V_34 . V_215 ) ;
V_35 = F_102 ( & V_27 -> V_34 . V_216 , V_214 , 1 , 0 , V_39 ) ;
if ( V_35 >= 0 ) {
V_214 -> V_67 = V_35 ;
} else {
F_35 ( V_214 ) ;
V_214 = F_100 ( V_35 ) ;
}
F_44 ( & V_27 -> V_34 . V_215 ) ;
return V_214 ;
}
