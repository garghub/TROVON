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
F_15 ( V_27 ) ;
V_35 = F_16 ( V_27 , & V_5 -> V_24 ,
V_37 ,
false , F_11 ) ;
if ( V_35 )
goto V_38;
V_5 -> V_24 . V_39 = & V_5 -> V_39 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_28 = V_28 ;
V_35 = F_17 ( & V_33 -> V_36 , 0 , 0 , V_40 ) ;
if ( V_35 < 0 )
goto V_41;
V_5 -> V_42 = V_35 ;
V_35 = 0 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_43 =
F_17 ( V_36 , 1 , 0 , V_40 ) ;
if ( V_5 -> V_43 < 0 ) {
V_35 = V_5 -> V_43 ;
goto V_44;
}
V_5 -> V_10 =
F_18 ( V_40 , L_10 ,
V_2 [ V_31 ] . V_10 ,
V_5 -> V_43 ) ;
if ( ! V_5 -> V_10 ) {
V_35 = - V_45 ;
goto V_46;
}
F_19 ( & V_5 -> V_47 ) ;
F_19 ( & V_5 -> V_48 ) ;
F_20 ( & V_5 -> V_49 ) ;
V_5 -> V_50 = NULL ;
V_5 -> V_51 = V_52 ;
F_6 ( V_5 ) ;
F_21 ( & V_5 -> V_53 , & V_33 -> V_54 ) ;
V_33 -> V_55 ++ ;
if ( V_31 != V_56 )
F_22 ( & V_5 -> V_24 ,
V_33 -> V_57 ,
0 ) ;
F_22 ( & V_5 -> V_24 ,
V_33 -> V_58 , 0 ) ;
if ( F_23 ( V_27 , V_59 ) ) {
F_22 ( & V_5 -> V_24 , V_33 -> V_60 , 0 ) ;
}
V_5 -> V_61 = NULL ;
V_46:
if ( V_35 )
F_24 ( V_36 , V_5 -> V_43 ) ;
V_44:
if ( V_35 )
F_24 ( & V_33 -> V_36 , V_5 -> V_42 ) ;
V_41:
if ( V_35 )
F_13 ( V_27 , & V_5 -> V_24 ) ;
V_38:
F_25 ( V_27 ) ;
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
return - V_45 ;
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
F_24 ( & V_2 [ V_5 -> V_31 ] . V_3 ,
V_5 -> V_43 ) ;
F_24 ( & V_27 -> V_34 . V_36 ,
V_5 -> V_42 ) ;
F_35 ( V_5 -> V_72 . V_73 ) ;
F_13 ( V_27 , & V_5 -> V_24 ) ;
F_35 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
F_29 ( & V_5 -> V_53 ) ;
V_27 -> V_34 . V_55 -- ;
F_27 ( V_5 -> V_74 && ! V_5 -> V_28 -> V_75 ) ;
if ( V_5 -> V_74 && V_5 -> V_28 -> V_75 )
V_5 -> V_28 -> V_75 ( V_5 ,
V_5 -> V_74 ) ;
F_36 ( & V_5 -> V_49 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_37 ( struct V_4 * V_5 )
{
int V_35 = 0 ;
if ( ! V_5 -> V_27 -> V_70 )
return 0 ;
F_38 ( & V_5 -> V_49 ) ;
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
F_44 ( & V_5 -> V_49 ) ;
return V_35 ;
}
void F_32 ( struct V_4 * V_5 )
{
F_38 ( & V_5 -> V_49 ) ;
if ( ! V_5 -> V_70 ) {
F_44 ( & V_5 -> V_49 ) ;
return;
}
if ( V_5 -> V_28 -> V_80 )
V_5 -> V_28 -> V_80 ( V_5 ) ;
F_43 ( V_5 ) ;
F_42 ( V_5 ) ;
V_5 -> V_70 = false ;
F_44 ( & V_5 -> V_49 ) ;
}
void F_45 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_46 (connector, &dev->mode_config.connector_list, head)
F_32 ( V_5 ) ;
}
int F_47 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_35 ;
F_46 (connector, &dev->mode_config.connector_list, head) {
V_35 = F_37 ( V_5 ) ;
if ( V_35 )
goto V_81;
}
return 0 ;
V_81:
F_44 ( & V_27 -> V_34 . V_49 ) ;
F_45 ( V_27 ) ;
return V_35 ;
}
const char * F_48 ( enum V_82 V_51 )
{
if ( V_51 == V_83 )
return L_11 ;
else if ( V_51 == V_84 )
return L_12 ;
else
return L_13 ;
}
const char * F_49 ( enum V_85 V_86 )
{
return V_87 [ V_86 ] . V_10 ;
}
int F_50 ( struct V_88 * V_89 ,
const T_1 * V_90 ,
unsigned int V_91 )
{
T_1 * V_92 = NULL ;
if ( ! V_90 && V_91 )
return - V_64 ;
if ( V_90 && V_91 ) {
V_92 = F_51 ( V_90 , sizeof( * V_90 ) * V_91 ,
V_40 ) ;
if ( ! V_92 )
return - V_45 ;
}
F_35 ( V_89 -> V_73 ) ;
V_89 -> V_73 = V_92 ;
V_89 -> V_93 = V_91 ;
return 0 ;
}
int F_52 ( struct V_26 * V_27 )
{
struct V_94 * V_95 ;
V_95 = F_53 ( V_27 , V_96 |
V_97 ,
L_14 , 0 ) ;
if ( ! V_95 )
return - V_45 ;
V_27 -> V_34 . V_57 = V_95 ;
V_95 = F_54 ( V_27 , 0 ,
L_15 , V_98 ,
F_2 ( V_98 ) ) ;
if ( ! V_95 )
return - V_45 ;
V_27 -> V_34 . V_58 = V_95 ;
V_95 = F_53 ( V_27 ,
V_96 |
V_97 ,
L_16 , 0 ) ;
if ( ! V_95 )
return - V_45 ;
V_27 -> V_34 . V_99 = V_95 ;
V_95 = F_53 ( V_27 ,
V_96 |
V_97 ,
L_17 , 0 ) ;
if ( ! V_95 )
return - V_45 ;
V_27 -> V_34 . V_100 = V_95 ;
return 0 ;
}
int F_55 ( struct V_26 * V_27 )
{
struct V_94 * V_101 ;
struct V_94 * V_102 ;
if ( V_27 -> V_34 . V_103 )
return 0 ;
V_101 =
F_54 ( V_27 , 0 ,
L_18 ,
V_104 ,
F_2 ( V_104 ) ) ;
V_27 -> V_34 . V_103 = V_101 ;
V_102 = F_54 ( V_27 , V_97 ,
L_19 ,
V_105 ,
F_2 ( V_105 ) ) ;
V_27 -> V_34 . V_106 = V_102 ;
return 0 ;
}
int F_56 ( struct V_26 * V_27 ,
unsigned int V_107 ,
const char * const V_48 [] )
{
struct V_94 * V_108 ;
struct V_94 * V_109 ;
unsigned int V_1 ;
if ( V_27 -> V_34 . V_110 )
return 0 ;
V_108 = F_54 ( V_27 , 0 ,
L_18 ,
V_111 ,
F_2 ( V_111 ) ) ;
if ( ! V_108 )
goto V_112;
V_27 -> V_34 . V_110 = V_108 ;
V_109 =
F_54 ( V_27 , V_97 ,
L_19 ,
V_113 ,
F_2 ( V_113 ) ) ;
if ( ! V_109 )
goto V_112;
V_27 -> V_34 . V_114 = V_109 ;
V_27 -> V_34 . V_115 =
F_57 ( V_27 , 0 , L_20 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_115 )
goto V_112;
V_27 -> V_34 . V_116 =
F_57 ( V_27 , 0 , L_21 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_116 )
goto V_112;
V_27 -> V_34 . V_117 =
F_57 ( V_27 , 0 , L_22 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_117 )
goto V_112;
V_27 -> V_34 . V_118 =
F_57 ( V_27 , 0 , L_23 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_118 )
goto V_112;
V_27 -> V_34 . V_119 =
F_53 ( V_27 , V_120 ,
L_24 , V_107 ) ;
if ( ! V_27 -> V_34 . V_119 )
goto V_112;
for ( V_1 = 0 ; V_1 < V_107 ; V_1 ++ )
F_58 ( V_27 -> V_34 . V_119 , V_1 ,
V_1 , V_48 [ V_1 ] ) ;
V_27 -> V_34 . V_121 =
F_57 ( V_27 , 0 , L_25 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_121 )
goto V_112;
V_27 -> V_34 . V_122 =
F_57 ( V_27 , 0 , L_26 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_122 )
goto V_112;
V_27 -> V_34 . V_123 =
F_57 ( V_27 , 0 , L_27 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_123 )
goto V_112;
V_27 -> V_34 . V_124 =
F_57 ( V_27 , 0 , L_28 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_124 )
goto V_112;
V_27 -> V_34 . V_125 =
F_57 ( V_27 , 0 , L_29 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_125 )
goto V_112;
V_27 -> V_34 . V_126 =
F_57 ( V_27 , 0 , L_30 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_126 )
goto V_112;
return 0 ;
V_112:
return - V_45 ;
}
int F_59 ( struct V_26 * V_27 )
{
struct V_94 * V_127 ;
if ( V_27 -> V_34 . V_128 )
return 0 ;
V_127 =
F_54 ( V_27 , 0 , L_31 ,
V_129 ,
F_2 ( V_129 ) ) ;
V_27 -> V_34 . V_128 = V_127 ;
return 0 ;
}
int F_60 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_130 )
return 0 ;
V_27 -> V_34 . V_130 =
F_54 ( V_27 , 0 , L_32 ,
V_131 ,
F_2 ( V_131 ) ) ;
if ( V_27 -> V_34 . V_130 == NULL )
return - V_45 ;
return 0 ;
}
int F_61 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_132 && V_27 -> V_34 . V_133 )
return 0 ;
V_27 -> V_34 . V_132 =
F_57 ( V_27 , V_97 , L_33 , 0 , 0xffffffff ) ;
V_27 -> V_34 . V_133 =
F_57 ( V_27 , V_97 , L_34 , 0 , 0xffffffff ) ;
if ( V_27 -> V_34 . V_132 == NULL ||
V_27 -> V_34 . V_133 == NULL )
return - V_45 ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 ,
const char * V_134 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
int V_35 ;
V_35 = F_63 ( V_27 ,
& V_5 -> V_135 ,
strlen ( V_134 ) + 1 ,
V_134 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_99 ) ;
return V_35 ;
}
int F_64 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
char V_136 [ 256 ] ;
int V_35 ;
if ( ! V_5 -> V_137 ) {
V_35 = F_63 ( V_27 ,
& V_5 -> V_138 ,
0 ,
NULL ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_100 ) ;
return V_35 ;
}
snprintf ( V_136 , 256 , L_35 ,
V_5 -> V_71 -> V_67 , V_5 -> V_139 ,
V_5 -> V_140 , V_5 -> V_141 ,
V_5 -> V_142 , V_5 -> V_143 ,
V_5 -> V_144 , V_5 -> V_145 ) ;
V_35 = F_63 ( V_27 ,
& V_5 -> V_138 ,
strlen ( V_136 ) + 1 ,
V_136 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_100 ) ;
return V_35 ;
}
int F_65 ( struct V_4 * V_5 ,
const struct V_146 * V_146 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
T_2 V_147 = 0 ;
int V_35 ;
if ( V_5 -> V_148 )
return 0 ;
if ( V_146 )
V_147 = V_149 * ( 1 + V_146 -> V_150 ) ;
V_35 = F_63 ( V_27 ,
& V_5 -> V_50 ,
V_147 ,
V_146 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_57 ) ;
return V_35 ;
}
int F_66 ( struct V_151 * V_152 ,
struct V_94 * V_153 ,
T_3 V_154 )
{
int V_35 = - V_64 ;
struct V_4 * V_5 = F_67 ( V_152 ) ;
if ( V_153 == V_5 -> V_27 -> V_34 . V_58 ) {
V_35 = (* V_5 -> V_28 -> V_155 )( V_5 , ( int ) V_154 ) ;
} else if ( V_5 -> V_28 -> V_156 )
V_35 = V_5 -> V_28 -> V_156 ( V_5 , V_153 , V_154 ) ;
if ( ! V_35 )
F_68 ( & V_5 -> V_24 , V_153 , V_154 ) ;
return V_35 ;
}
int F_69 ( struct V_26 * V_27 ,
void * V_157 , struct V_158 * V_159 )
{
struct V_160 * V_161 = V_157 ;
struct V_162 V_163 = {
. V_154 = V_161 -> V_154 ,
. V_164 = V_161 -> V_164 ,
. V_165 = V_161 -> V_166 ,
. V_167 = V_37
} ;
return F_70 ( V_27 , & V_163 , V_159 ) ;
}
static struct V_62 * F_71 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 )
return V_5 -> V_74 -> V_168 ;
return V_5 -> V_63 ;
}
static bool F_72 ( const struct V_68 * V_7 ,
const struct V_158 * V_159 )
{
if ( ! V_159 -> V_169 && F_73 ( V_7 ) )
return false ;
return true ;
}
int F_74 ( struct V_26 * V_27 , void * V_157 ,
struct V_158 * V_159 )
{
struct V_170 * V_171 = V_157 ;
struct V_4 * V_5 ;
struct V_62 * V_63 ;
struct V_68 * V_7 ;
int V_172 = 0 ;
int V_173 = 0 ;
int V_35 = 0 ;
int V_174 = 0 ;
int V_1 ;
struct V_175 V_176 ;
struct V_175 T_4 * V_177 ;
T_5 T_4 * V_178 ;
if ( ! F_23 ( V_27 , V_179 ) )
return - V_64 ;
memset ( & V_176 , 0 , sizeof( struct V_175 ) ) ;
F_38 ( & V_27 -> V_34 . V_49 ) ;
V_5 = F_75 ( V_27 , V_171 -> V_166 ) ;
if ( ! V_5 ) {
V_35 = - V_180 ;
goto V_38;
}
for ( V_1 = 0 ; V_1 < V_65 ; V_1 ++ )
if ( V_5 -> V_66 [ V_1 ] != 0 )
V_173 ++ ;
if ( V_171 -> V_181 == 0 ) {
V_5 -> V_28 -> V_182 ( V_5 ,
V_27 -> V_34 . V_183 ,
V_27 -> V_34 . V_184 ) ;
}
F_46 (mode, &connector->modes, head)
if ( F_72 ( V_7 , V_159 ) )
V_172 ++ ;
V_171 -> V_166 = V_5 -> V_24 . V_67 ;
V_171 -> V_31 = V_5 -> V_31 ;
V_171 -> V_43 = V_5 -> V_43 ;
V_171 -> V_185 = V_5 -> V_72 . V_186 ;
V_171 -> V_187 = V_5 -> V_72 . V_188 ;
V_171 -> V_189 = V_5 -> V_72 . V_85 ;
V_171 -> V_190 = V_5 -> V_51 ;
F_76 ( & V_27 -> V_34 . V_191 , NULL ) ;
V_63 = F_71 ( V_5 ) ;
if ( V_63 )
V_171 -> V_192 = V_63 -> V_24 . V_67 ;
else
V_171 -> V_192 = 0 ;
if ( ( V_171 -> V_181 >= V_172 ) && V_172 ) {
V_174 = 0 ;
V_177 = (struct V_175 T_4 * ) ( unsigned long ) V_171 -> V_193 ;
F_46 (mode, &connector->modes, head) {
if ( ! F_72 ( V_7 , V_159 ) )
continue;
F_77 ( & V_176 , V_7 ) ;
if ( F_78 ( V_177 + V_174 ,
& V_176 , sizeof( V_176 ) ) ) {
V_35 = - V_194 ;
goto V_195;
}
V_174 ++ ;
}
}
V_171 -> V_181 = V_172 ;
V_35 = F_79 ( & V_5 -> V_24 , V_159 -> V_196 ,
( T_5 T_4 * ) ( unsigned long ) ( V_171 -> V_197 ) ,
( T_3 T_4 * ) ( unsigned long ) ( V_171 -> V_198 ) ,
& V_171 -> V_199 ) ;
if ( V_35 )
goto V_195;
if ( ( V_171 -> V_200 >= V_173 ) && V_173 ) {
V_174 = 0 ;
V_178 = ( T_5 T_4 * ) ( unsigned long ) ( V_171 -> V_201 ) ;
for ( V_1 = 0 ; V_1 < V_65 ; V_1 ++ ) {
if ( V_5 -> V_66 [ V_1 ] != 0 ) {
if ( F_80 ( V_5 -> V_66 [ V_1 ] ,
V_178 + V_174 ) ) {
V_35 = - V_194 ;
goto V_195;
}
V_174 ++ ;
}
}
}
V_171 -> V_200 = V_173 ;
V_195:
F_81 ( & V_27 -> V_34 . V_191 ) ;
F_82 ( V_5 ) ;
V_38:
F_44 ( & V_27 -> V_34 . V_49 ) ;
return V_35 ;
}
static void F_83 ( struct V_23 * V_23 )
{
struct V_202 * V_203 = F_12 ( V_23 , struct V_202 , V_25 ) ;
struct V_26 * V_27 = V_203 -> V_27 ;
F_38 ( & V_27 -> V_34 . V_204 ) ;
F_84 ( & V_27 -> V_34 . V_205 , V_203 -> V_67 ) ;
F_44 ( & V_27 -> V_34 . V_204 ) ;
F_35 ( V_203 ) ;
}
void F_33 ( struct V_26 * V_27 ,
struct V_202 * V_203 )
{
F_85 ( & V_203 -> V_25 , F_83 ) ;
}
struct V_202 * F_86 ( struct V_26 * V_27 ,
char V_206 [ 8 ] )
{
struct V_202 * V_203 ;
int V_67 ;
F_38 ( & V_27 -> V_34 . V_204 ) ;
F_87 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_203 -> V_207 , V_206 , 8 ) ) {
if ( ! F_88 ( & V_203 -> V_25 ) )
V_203 = NULL ;
F_44 ( & V_27 -> V_34 . V_204 ) ;
return V_203 ;
}
}
F_44 ( & V_27 -> V_34 . V_204 ) ;
return NULL ;
}
struct V_202 * F_89 ( struct V_26 * V_27 ,
char V_206 [ 8 ] )
{
struct V_202 * V_203 ;
int V_35 ;
V_203 = F_90 ( sizeof( * V_203 ) , V_40 ) ;
if ( ! V_203 )
return F_91 ( - V_45 ) ;
F_92 ( & V_203 -> V_25 ) ;
memcpy ( V_203 -> V_207 , V_206 , 8 ) ;
V_203 -> V_27 = V_27 ;
F_38 ( & V_27 -> V_34 . V_204 ) ;
V_35 = F_93 ( & V_27 -> V_34 . V_205 , V_203 , 1 , 0 , V_40 ) ;
if ( V_35 >= 0 ) {
V_203 -> V_67 = V_35 ;
} else {
F_35 ( V_203 ) ;
V_203 = F_91 ( V_35 ) ;
}
F_44 ( & V_27 -> V_34 . V_204 ) ;
return V_203 ;
}
