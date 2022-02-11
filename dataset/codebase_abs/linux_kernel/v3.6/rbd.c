static void F_1 ( struct V_1 * V_2 )
{
}
static struct V_1 * F_2 ( struct V_3 * V_4 )
{
return F_3 ( & V_4 -> V_2 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_2 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_9 ;
if ( ( V_7 & V_10 ) && V_4 -> V_11 )
return - V_12 ;
F_2 ( V_4 ) ;
F_7 ( V_6 , V_4 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 , T_1 V_7 )
{
struct V_3 * V_4 = V_14 -> V_9 ;
F_4 ( V_4 ) ;
return 0 ;
}
static struct V_15 * F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_15 * V_20 ;
int V_21 = - V_22 ;
F_10 ( L_1 ) ;
V_20 = F_11 ( sizeof( struct V_15 ) , V_23 ) ;
if ( ! V_20 )
goto V_24;
F_12 ( & V_20 -> V_25 ) ;
F_13 ( & V_20 -> V_26 ) ;
F_14 ( & V_27 , V_28 ) ;
V_20 -> V_29 = F_15 ( V_17 , V_20 , 0 , 0 ) ;
if ( F_16 ( V_20 -> V_29 ) )
goto V_30;
V_17 = NULL ;
V_21 = F_17 ( V_20 -> V_29 ) ;
if ( V_21 < 0 )
goto V_31;
V_20 -> V_19 = V_19 ;
F_18 ( & V_32 ) ;
F_19 ( & V_20 -> V_26 , & V_33 ) ;
F_20 ( & V_32 ) ;
F_21 ( & V_27 ) ;
F_10 ( L_2 , V_20 ) ;
return V_20 ;
V_31:
F_22 ( V_20 -> V_29 ) ;
V_30:
F_21 ( & V_27 ) ;
F_23 ( V_20 ) ;
V_24:
if ( V_17 )
F_24 ( V_17 ) ;
return F_25 ( V_21 ) ;
}
static struct V_15 * F_26 ( struct V_16 * V_17 )
{
struct V_15 * V_34 ;
if ( V_17 -> V_35 & V_36 )
return NULL ;
F_27 (client_node, &rbd_client_list, node)
if ( ! F_28 ( V_17 , V_34 -> V_29 ) )
return V_34 ;
return NULL ;
}
static int F_29 ( char * V_37 , void * V_38 )
{
struct V_18 * V_19 = V_38 ;
T_2 V_39 [ V_40 ] ;
int V_41 , V_42 , V_21 ;
V_41 = F_30 ( V_37 , V_43 , V_39 ) ;
if ( V_41 < 0 )
return - V_44 ;
if ( V_41 < V_45 ) {
V_21 = F_31 ( & V_39 [ 0 ] , & V_42 ) ;
if ( V_21 < 0 ) {
F_32 ( L_3
L_4 , V_37 ) ;
return V_21 ;
}
F_10 ( L_5 , V_41 , V_42 ) ;
} else if ( V_41 > V_45 && V_41 < V_46 ) {
F_10 ( L_6 , V_41 ,
V_39 [ 0 ] . V_47 ) ;
} else {
F_10 ( L_7 , V_41 ) ;
}
switch ( V_41 ) {
case V_48 :
V_19 -> V_49 = V_42 ;
break;
default:
F_33 ( V_41 ) ;
}
return 0 ;
}
static struct V_15 * F_34 ( const char * V_50 ,
T_3 V_51 ,
char * V_52 )
{
struct V_15 * V_20 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_19 = F_35 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return F_25 ( - V_22 ) ;
V_19 -> V_49 = V_53 ;
V_17 = F_36 ( V_52 , V_50 ,
V_50 + V_51 ,
F_29 , V_19 ) ;
if ( F_16 ( V_17 ) ) {
F_23 ( V_19 ) ;
return F_37 ( V_17 ) ;
}
F_18 ( & V_32 ) ;
V_20 = F_26 ( V_17 ) ;
if ( V_20 ) {
F_38 ( & V_20 -> V_25 ) ;
F_20 ( & V_32 ) ;
F_24 ( V_17 ) ;
F_23 ( V_19 ) ;
return V_20 ;
}
F_20 ( & V_32 ) ;
V_20 = F_9 ( V_17 , V_19 ) ;
if ( F_16 ( V_20 ) )
F_23 ( V_19 ) ;
return V_20 ;
}
static void F_39 ( struct V_25 * V_25 )
{
struct V_15 * V_20 = F_40 ( V_25 , struct V_15 , V_25 ) ;
F_10 ( L_8 , V_20 ) ;
F_18 ( & V_32 ) ;
F_41 ( & V_20 -> V_26 ) ;
F_20 ( & V_32 ) ;
F_22 ( V_20 -> V_29 ) ;
F_23 ( V_20 -> V_19 ) ;
F_23 ( V_20 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
F_43 ( & V_4 -> V_15 -> V_25 , F_39 ) ;
V_4 -> V_15 = NULL ;
}
static void F_44 ( struct V_25 * V_25 )
{
struct V_54 * V_55 =
F_40 ( V_25 , struct V_54 , V_25 ) ;
F_10 ( L_9 , V_55 ) ;
F_23 ( V_55 ) ;
}
static bool F_45 ( struct V_56 * V_57 )
{
return ! memcmp ( & V_57 -> V_58 ,
V_59 , sizeof ( V_59 ) ) ;
}
static int F_46 ( struct V_60 * V_61 ,
struct V_56 * V_57 ,
T_4 V_62 )
{
T_4 V_63 ;
if ( ! F_45 ( V_57 ) )
return - V_64 ;
V_63 = F_47 ( V_57 -> V_63 ) ;
if ( V_63 > ( V_65 - sizeof( struct V_66 ) )
/ sizeof ( V_67 ) )
return - V_44 ;
V_61 -> V_68 = F_11 ( sizeof( struct V_66 ) +
V_63 * sizeof( V_67 ) ,
V_23 ) ;
if ( ! V_61 -> V_68 )
return - V_22 ;
if ( V_63 ) {
V_61 -> V_69 = F_48 ( V_57 -> V_69 ) ;
V_61 -> V_70 = F_11 ( V_61 -> V_69 ,
V_23 ) ;
if ( ! V_61 -> V_70 )
goto V_71;
V_61 -> V_72 = F_11 ( V_63 * sizeof( V_67 ) ,
V_23 ) ;
if ( ! V_61 -> V_72 )
goto V_73;
} else {
F_49 ( V_57 -> V_69 ) ;
V_61 -> V_69 = 0 ;
V_61 -> V_70 = NULL ;
V_61 -> V_72 = NULL ;
}
V_61 -> V_74 = F_11 ( sizeof ( V_57 -> V_75 ) + 1 ,
V_23 ) ;
if ( ! V_61 -> V_74 )
goto V_76;
memcpy ( V_61 -> V_74 , V_57 -> V_75 ,
sizeof( V_57 -> V_75 ) ) ;
V_61 -> V_74 [ sizeof ( V_57 -> V_75 ) ] = '\0' ;
V_61 -> V_77 = F_48 ( V_57 -> V_77 ) ;
V_61 -> V_78 = V_57 -> V_52 . V_79 ;
V_61 -> V_80 = V_57 -> V_52 . V_80 ;
V_61 -> V_81 = V_57 -> V_52 . V_81 ;
F_50 ( & V_61 -> V_68 -> V_82 , 1 ) ;
V_61 -> V_68 -> V_83 = F_48 ( V_57 -> V_84 ) ;
V_61 -> V_68 -> V_85 = V_63 ;
V_61 -> V_86 = V_63 ;
if ( V_63 && V_62 == V_63 ) {
int V_87 ;
for ( V_87 = 0 ; V_87 < V_63 ; V_87 ++ ) {
V_61 -> V_68 -> V_88 [ V_87 ] =
F_48 ( V_57 -> V_88 [ V_87 ] . V_89 ) ;
V_61 -> V_72 [ V_87 ] =
F_48 ( V_57 -> V_88 [ V_87 ] . V_77 ) ;
}
memcpy ( V_61 -> V_70 , & V_57 -> V_88 [ V_63 ] ,
V_61 -> V_69 ) ;
}
return 0 ;
V_76:
F_23 ( V_61 -> V_72 ) ;
V_61 -> V_72 = NULL ;
V_73:
F_23 ( V_61 -> V_70 ) ;
V_61 -> V_70 = NULL ;
V_71:
F_23 ( V_61 -> V_68 ) ;
V_61 -> V_68 = NULL ;
return - V_22 ;
}
static int F_51 ( struct V_60 * V_61 , const char * V_90 ,
V_67 * V_83 , V_67 * V_91 )
{
int V_87 ;
char * V_92 = V_61 -> V_70 ;
for ( V_87 = 0 ; V_87 < V_61 -> V_86 ; V_87 ++ ) {
if ( ! strcmp ( V_90 , V_92 ) ) {
if ( V_83 )
* V_83 = V_61 -> V_68 -> V_88 [ V_87 ] ;
if ( V_91 )
* V_91 = V_61 -> V_72 [ V_87 ] ;
return V_87 ;
}
V_92 += strlen ( V_92 ) + 1 ;
}
return - V_93 ;
}
static int F_52 ( struct V_3 * V_4 , V_67 * V_91 )
{
int V_21 ;
F_53 ( & V_4 -> V_94 ) ;
if ( ! memcmp ( V_4 -> V_90 , V_95 ,
sizeof ( V_95 ) ) ) {
V_4 -> V_96 = V_97 ;
V_4 -> V_98 = false ;
V_4 -> V_11 = 0 ;
if ( V_91 )
* V_91 = V_4 -> V_61 . V_77 ;
} else {
V_67 V_96 = 0 ;
V_21 = F_51 ( & V_4 -> V_61 , V_4 -> V_90 ,
& V_96 , V_91 ) ;
if ( V_21 < 0 )
goto V_99;
V_4 -> V_96 = V_96 ;
V_4 -> V_98 = true ;
V_4 -> V_11 = 1 ;
}
V_21 = 0 ;
V_99:
F_54 ( & V_4 -> V_94 ) ;
return V_21 ;
}
static void F_55 ( struct V_60 * V_61 )
{
F_23 ( V_61 -> V_74 ) ;
F_23 ( V_61 -> V_72 ) ;
F_23 ( V_61 -> V_70 ) ;
F_56 ( V_61 -> V_68 ) ;
}
static V_67 F_57 ( struct V_60 * V_61 ,
const char * V_74 ,
V_67 V_100 , V_67 V_101 ,
char * V_102 , V_67 * V_103 )
{
V_67 V_104 = V_100 >> V_61 -> V_78 ;
if ( V_102 )
snprintf ( V_102 , V_105 ,
L_10 , V_74 , V_104 ) ;
V_100 = V_100 & ( ( 1 << V_61 -> V_78 ) - 1 ) ;
V_101 = F_58 ( V_67 , V_101 , ( 1 << V_61 -> V_78 ) - V_100 ) ;
if ( V_103 )
* V_103 = V_100 ;
return V_101 ;
}
static int F_59 ( struct V_60 * V_61 ,
V_67 V_100 , V_67 V_101 )
{
V_67 V_106 = V_100 >> V_61 -> V_78 ;
V_67 V_107 = ( V_100 + V_101 - 1 ) >> V_61 -> V_78 ;
return V_107 - V_106 + 1 ;
}
static V_67 F_60 ( struct V_60 * V_61 )
{
return 1 << V_61 -> V_78 ;
}
static void F_61 ( struct V_108 * V_109 )
{
struct V_108 * V_110 ;
while ( V_109 ) {
V_110 = V_109 ;
V_109 = V_109 -> V_111 ;
F_62 ( V_110 ) ;
}
}
static void F_63 ( struct V_108 * V_109 , int V_112 )
{
struct V_113 * V_114 ;
unsigned long V_35 ;
void * V_115 ;
int V_87 ;
int V_116 = 0 ;
while ( V_109 ) {
F_64 (bv, chain, i) {
if ( V_116 + V_114 -> V_117 > V_112 ) {
int V_118 = F_65 ( V_112 - V_116 , 0 ) ;
V_115 = F_66 ( V_114 , & V_35 ) ;
memset ( V_115 + V_118 , 0 ,
V_114 -> V_117 - V_118 ) ;
F_67 ( V_115 , & V_35 ) ;
}
V_116 += V_114 -> V_117 ;
}
V_109 = V_109 -> V_111 ;
}
}
static struct V_108 * F_68 ( struct V_108 * * V_119 , struct V_108 * * V_120 ,
struct V_121 * * V_122 ,
int V_101 , T_5 V_123 )
{
struct V_108 * V_110 , * V_124 = * V_119 , * V_125 = NULL , * V_126 = NULL ;
int V_127 = 0 ;
if ( * V_122 ) {
F_69 ( * V_122 ) ;
* V_122 = NULL ;
}
while ( V_124 && ( V_127 < V_101 ) ) {
V_110 = F_70 ( V_123 , V_124 -> V_128 ) ;
if ( ! V_110 )
goto V_129;
if ( V_127 + V_124 -> V_130 > V_101 ) {
struct V_121 * V_122 ;
F_10 ( L_11
L_12 ,
V_127 , V_101 - V_127 , V_124 -> V_130 ) ;
V_122 = F_71 ( V_124 , ( V_101 - V_127 ) / V_131 ) ;
if ( ! V_122 )
goto V_129;
F_72 ( V_110 , & V_122 -> V_132 ) ;
* V_120 = & V_122 -> V_133 ;
} else {
F_72 ( V_110 , V_124 ) ;
* V_120 = V_124 -> V_111 ;
}
V_110 -> V_134 = NULL ;
V_123 &= ~ V_135 ;
V_110 -> V_111 = NULL ;
if ( ! V_125 ) {
V_125 = V_126 = V_110 ;
} else {
V_126 -> V_111 = V_110 ;
V_126 = V_110 ;
}
V_124 = V_124 -> V_111 ;
V_127 += V_110 -> V_130 ;
}
F_33 ( V_127 < V_101 ) ;
if ( V_126 )
V_126 -> V_111 = NULL ;
* V_119 = V_124 ;
return V_125 ;
V_129:
F_10 ( L_13 ) ;
F_61 ( V_125 ) ;
return NULL ;
}
static struct V_136 * F_73 ( int V_137 ,
int V_138 , T_4 V_139 )
{
struct V_136 * V_140 ;
V_140 = F_35 ( sizeof ( * V_140 ) * ( V_137 + 1 ) , V_141 ) ;
if ( ! V_140 )
return NULL ;
V_140 [ 0 ] . V_142 = V_138 ;
V_140 [ 0 ] . V_139 = V_139 ;
return V_140 ;
}
static void F_74 ( struct V_136 * V_140 )
{
F_23 ( V_140 ) ;
}
static void F_75 ( struct V_143 * V_144 ,
struct V_54 * V_55 ,
int V_145 ,
int V_21 , V_67 V_101 )
{
struct V_146 * V_147 ;
int V_148 , F_65 , V_87 ;
F_10 ( L_14 ,
V_55 , V_145 , V_21 , ( unsigned long long ) V_101 ) ;
if ( ! V_144 )
return;
if ( ! V_55 ) {
F_76 ( V_144 , V_21 , V_101 ) ;
return;
}
V_147 = V_144 -> V_147 ;
F_77 ( V_147 -> V_149 ) ;
V_55 -> V_150 [ V_145 ] . V_99 = 1 ;
V_55 -> V_150 [ V_145 ] . V_151 = V_21 ;
V_55 -> V_150 [ V_145 ] . V_152 = V_101 ;
F_65 = V_148 = V_55 -> V_153 ;
while ( F_65 < V_55 -> V_127 && V_55 -> V_150 [ F_65 ] . V_99 )
F_65 ++ ;
for ( V_87 = V_148 ; V_87 < F_65 ; V_87 ++ ) {
F_78 ( V_144 , V_55 -> V_150 [ V_87 ] . V_151 ,
V_55 -> V_150 [ V_87 ] . V_152 ) ;
V_55 -> V_153 ++ ;
F_43 ( & V_55 -> V_25 , F_44 ) ;
}
F_79 ( V_147 -> V_149 ) ;
}
static void F_80 ( struct V_154 * V_155 ,
int V_21 , V_67 V_101 )
{
F_75 ( V_155 -> V_144 , V_155 -> V_55 , V_155 -> V_156 , V_21 , V_101 ) ;
}
static int F_81 ( struct V_143 * V_144 ,
struct V_3 * V_4 ,
struct V_66 * V_68 ,
V_67 V_157 ,
const char * V_158 , V_67 V_100 , V_67 V_101 ,
struct V_108 * V_108 ,
struct V_159 * * V_160 ,
int V_161 ,
int V_35 ,
struct V_136 * V_140 ,
struct V_54 * V_55 ,
int V_156 ,
void (* F_82)( struct V_162 * V_155 ,
struct V_163 * V_164 ) ,
struct V_162 * * V_165 ,
V_67 * V_166 )
{
struct V_162 * V_155 ;
struct V_167 * V_168 ;
int V_21 ;
V_67 V_169 ;
struct V_170 V_171 = V_172 ;
struct V_154 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
V_173 = F_35 ( sizeof( * V_173 ) , V_141 ) ;
if ( ! V_173 ) {
if ( V_55 )
F_75 ( V_144 , V_55 , V_156 ,
- V_22 , V_101 ) ;
return - V_22 ;
}
if ( V_55 ) {
V_173 -> V_55 = V_55 ;
V_173 -> V_156 = V_156 ;
}
F_10 ( L_15 , V_158 ,
( unsigned long long ) V_100 , ( unsigned long long ) V_101 ) ;
V_177 = & V_4 -> V_15 -> V_29 -> V_177 ;
V_155 = F_83 ( V_177 , V_35 , V_68 , V_140 ,
false , V_141 , V_160 , V_108 ) ;
if ( ! V_155 ) {
V_21 = - V_22 ;
goto V_178;
}
V_155 -> V_179 = F_82 ;
V_173 -> V_144 = V_144 ;
V_173 -> V_108 = V_108 ;
V_173 -> V_160 = V_160 ;
V_173 -> V_101 = V_101 ;
V_155 -> V_180 = V_173 ;
V_175 = V_155 -> V_181 -> V_182 . V_183 ;
V_175 -> V_157 = F_84 ( V_97 ) ;
strncpy ( V_155 -> V_184 , V_158 , sizeof( V_155 -> V_184 ) ) ;
V_155 -> V_185 = strlen ( V_155 -> V_184 ) ;
V_168 = & V_155 -> V_186 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_187 = F_85 ( 1 << V_188 ) ;
V_168 -> V_189 = F_85 ( 1 ) ;
V_168 -> V_190 = F_85 ( 1 << V_188 ) ;
V_168 -> V_191 = F_85 ( V_4 -> V_192 ) ;
F_86 ( V_177 , V_168 , V_157 , V_100 , & V_101 , & V_169 ,
V_155 , V_140 ) ;
F_87 ( V_155 , V_100 , & V_101 ,
V_140 ,
V_68 ,
& V_171 ,
V_155 -> V_184 , V_155 -> V_185 ) ;
if ( V_165 ) {
F_88 ( V_177 , V_155 ) ;
* V_165 = V_155 ;
}
V_21 = F_89 ( V_177 , V_155 , false ) ;
if ( V_21 < 0 )
goto V_193;
if ( ! F_82 ) {
V_21 = F_90 ( V_177 , V_155 ) ;
if ( V_166 )
* V_166 = F_48 ( V_155 -> V_194 . V_195 ) ;
F_10 ( L_16 ,
( unsigned long long )
F_48 ( V_155 -> V_194 . V_195 ) ) ;
F_91 ( V_155 ) ;
}
return V_21 ;
V_193:
F_61 ( V_173 -> V_108 ) ;
F_91 ( V_155 ) ;
V_178:
F_80 ( V_173 , V_21 , V_101 ) ;
F_23 ( V_173 ) ;
return V_21 ;
}
static void F_92 ( struct V_162 * V_155 , struct V_163 * V_164 )
{
struct V_154 * V_173 = V_155 -> V_180 ;
struct V_196 * V_197 ;
struct V_198 * V_142 ;
T_6 V_151 ;
V_67 V_152 ;
int V_199 ;
V_197 = V_164 -> V_182 . V_183 ;
F_49 ( F_47 ( V_197 -> V_137 ) == 0 ) ;
V_142 = ( void * ) ( V_197 + 1 ) ;
V_151 = F_47 ( V_197 -> V_200 ) ;
V_152 = F_48 ( V_142 -> V_201 . V_202 ) ;
V_199 = ( F_93 ( V_142 -> V_142 ) == V_203 ) ;
F_10 ( L_17 ,
( unsigned long long ) V_152 , V_199 , ( int ) V_151 ) ;
if ( V_151 == - V_93 && V_199 ) {
F_63 ( V_173 -> V_108 , 0 ) ;
V_151 = 0 ;
} else if ( V_151 == 0 && V_199 && V_152 < V_173 -> V_101 ) {
F_63 ( V_173 -> V_108 , V_152 ) ;
V_152 = V_173 -> V_101 ;
}
F_80 ( V_173 , V_151 , V_152 ) ;
if ( V_173 -> V_108 )
F_61 ( V_173 -> V_108 ) ;
F_91 ( V_155 ) ;
F_23 ( V_173 ) ;
}
static void F_94 ( struct V_162 * V_155 , struct V_163 * V_164 )
{
F_91 ( V_155 ) ;
}
static int F_95 ( struct V_3 * V_4 ,
struct V_66 * V_68 ,
V_67 V_157 ,
int V_35 ,
struct V_136 * V_140 ,
const char * V_158 ,
V_67 V_100 , V_67 V_101 ,
char * V_115 ,
struct V_162 * * V_165 ,
V_67 * V_166 )
{
int V_21 ;
struct V_159 * * V_160 ;
int V_161 ;
F_33 ( V_140 == NULL ) ;
V_161 = F_96 ( V_100 , V_101 ) ;
V_160 = F_97 ( V_161 , V_23 ) ;
if ( F_16 ( V_160 ) )
return F_98 ( V_160 ) ;
V_21 = F_81 ( NULL , V_4 , V_68 , V_157 ,
V_158 , V_100 , V_101 , NULL ,
V_160 , V_161 ,
V_35 ,
V_140 ,
NULL , 0 ,
NULL ,
V_165 , V_166 ) ;
if ( V_21 < 0 )
goto V_99;
if ( ( V_35 & V_204 ) && V_115 )
V_21 = F_99 ( V_160 , V_115 , V_100 , V_21 ) ;
V_99:
F_100 ( V_160 , V_161 ) ;
return V_21 ;
}
static int F_101 ( struct V_143 * V_144 ,
struct V_3 * V_4 ,
struct V_66 * V_68 ,
V_67 V_157 ,
int V_138 , int V_35 ,
V_67 V_100 , V_67 V_101 ,
struct V_108 * V_108 ,
struct V_54 * V_55 ,
int V_156 )
{
char * V_102 ;
V_67 V_205 ;
V_67 V_206 ;
int V_21 ;
struct V_136 * V_140 ;
T_4 V_139 ;
V_102 = F_11 ( V_105 + 1 , V_141 ) ;
if ( ! V_102 )
return - V_22 ;
V_206 = F_57 ( & V_4 -> V_61 ,
V_4 -> V_61 . V_74 ,
V_100 , V_101 ,
V_102 , & V_205 ) ;
V_139 = ( V_35 & V_207 ? V_206 : 0 ) ;
V_21 = - V_22 ;
V_140 = F_73 ( 1 , V_138 , V_139 ) ;
if ( ! V_140 )
goto V_99;
F_33 ( V_206 < V_101 ) ;
V_21 = F_81 ( V_144 , V_4 , V_68 , V_157 ,
V_102 , V_205 , V_206 ,
V_108 ,
NULL , 0 ,
V_35 ,
V_140 ,
V_55 , V_156 ,
F_92 , 0 , NULL ) ;
F_74 ( V_140 ) ;
V_99:
F_23 ( V_102 ) ;
return V_21 ;
}
static int F_102 ( struct V_143 * V_144 ,
struct V_3 * V_4 ,
struct V_66 * V_68 ,
V_67 V_100 , V_67 V_101 ,
struct V_108 * V_108 ,
struct V_54 * V_55 ,
int V_156 )
{
return F_101 ( V_144 , V_4 , V_68 , V_97 ,
V_208 ,
V_207 | V_209 ,
V_100 , V_101 , V_108 , V_55 , V_156 ) ;
}
static int F_103 ( struct V_143 * V_144 ,
struct V_3 * V_4 ,
V_67 V_157 ,
V_67 V_100 , V_67 V_101 ,
struct V_108 * V_108 ,
struct V_54 * V_55 ,
int V_156 )
{
return F_101 ( V_144 , V_4 , NULL ,
V_157 ,
V_203 ,
V_204 ,
V_100 , V_101 , V_108 , V_55 , V_156 ) ;
}
static int F_104 ( struct V_3 * V_4 ,
V_67 V_157 ,
const char * V_158 ,
V_67 V_100 , V_67 V_101 ,
char * V_115 ,
V_67 * V_166 )
{
struct V_136 * V_140 ;
int V_21 ;
V_140 = F_73 ( 1 , V_203 , 0 ) ;
if ( ! V_140 )
return - V_22 ;
V_21 = F_95 ( V_4 , NULL ,
V_157 ,
V_204 ,
V_140 , V_158 , V_100 , V_101 , V_115 , NULL , V_166 ) ;
F_74 ( V_140 ) ;
return V_21 ;
}
static int F_105 ( struct V_3 * V_4 ,
V_67 V_166 ,
V_67 V_210 )
{
struct V_136 * V_140 ;
int V_21 ;
V_140 = F_73 ( 1 , V_211 , 0 ) ;
if ( ! V_140 )
return - V_22 ;
V_140 [ 0 ] . V_212 . V_166 = F_84 ( V_166 ) ;
V_140 [ 0 ] . V_212 . V_213 = V_210 ;
V_140 [ 0 ] . V_212 . V_214 = 0 ;
V_21 = F_81 ( NULL , V_4 , NULL , V_97 ,
V_4 -> V_215 , 0 , 0 , NULL ,
NULL , 0 ,
V_204 ,
V_140 ,
NULL , 0 ,
F_94 , 0 , NULL ) ;
F_74 ( V_140 ) ;
return V_21 ;
}
static void F_106 ( V_67 V_166 , V_67 V_210 , T_7 V_138 , void * V_216 )
{
struct V_3 * V_4 = (struct V_3 * ) V_216 ;
V_67 V_217 ;
int V_151 ;
if ( ! V_4 )
return;
F_10 ( L_18 ,
V_4 -> V_215 , ( unsigned long long ) V_210 ,
( unsigned int ) V_138 ) ;
V_151 = F_107 ( V_4 , & V_217 ) ;
if ( V_151 )
F_108 ( V_218 L_19
L_20 , V_4 -> V_219 , V_151 ) ;
F_105 ( V_4 , V_217 , V_210 ) ;
}
static int F_109 ( struct V_3 * V_4 )
{
struct V_136 * V_140 ;
struct V_176 * V_177 = & V_4 -> V_15 -> V_29 -> V_177 ;
int V_21 ;
V_140 = F_73 ( 1 , V_220 , 0 ) ;
if ( ! V_140 )
return - V_22 ;
V_21 = F_110 ( V_177 , F_106 , 0 ,
( void * ) V_4 , & V_4 -> V_221 ) ;
if ( V_21 < 0 )
goto V_222;
V_140 [ 0 ] . V_212 . V_166 = F_84 ( V_4 -> V_61 . V_223 ) ;
V_140 [ 0 ] . V_212 . V_213 = F_84 ( V_4 -> V_221 -> V_213 ) ;
V_140 [ 0 ] . V_212 . V_214 = 1 ;
V_21 = F_95 ( V_4 , NULL ,
V_97 ,
V_207 | V_209 ,
V_140 ,
V_4 -> V_215 ,
0 , 0 , NULL ,
& V_4 -> V_224 , NULL ) ;
if ( V_21 < 0 )
goto V_225;
F_74 ( V_140 ) ;
return 0 ;
V_225:
F_111 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
V_222:
F_74 ( V_140 ) ;
return V_21 ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_136 * V_140 ;
int V_21 ;
V_140 = F_73 ( 1 , V_220 , 0 ) ;
if ( ! V_140 )
return - V_22 ;
V_140 [ 0 ] . V_212 . V_166 = 0 ;
V_140 [ 0 ] . V_212 . V_213 = F_84 ( V_4 -> V_221 -> V_213 ) ;
V_140 [ 0 ] . V_212 . V_214 = 0 ;
V_21 = F_95 ( V_4 , NULL ,
V_97 ,
V_207 | V_209 ,
V_140 ,
V_4 -> V_215 ,
0 , 0 , NULL , NULL , NULL ) ;
F_74 ( V_140 ) ;
F_111 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
return V_21 ;
}
static void F_113 ( V_67 V_166 , V_67 V_210 , T_7 V_138 , void * V_216 )
{
struct V_3 * V_4 = (struct V_3 * ) V_216 ;
if ( ! V_4 )
return;
F_10 ( L_21 ,
V_4 -> V_215 , ( unsigned long long ) V_210 ,
( unsigned int ) V_138 ) ;
}
static int F_114 ( struct V_3 * V_4 )
{
struct V_136 * V_140 ;
struct V_176 * V_177 = & V_4 -> V_15 -> V_29 -> V_177 ;
struct V_226 * V_227 ;
struct V_228 V_229 ;
int V_139 = sizeof( T_4 ) + sizeof( T_4 ) ;
int V_21 ;
V_140 = F_73 ( 1 , V_230 , V_139 ) ;
if ( ! V_140 )
return - V_22 ;
V_229 . V_4 = V_4 ;
V_21 = F_110 ( V_177 , F_113 , 1 ,
( void * ) & V_229 , & V_227 ) ;
if ( V_21 < 0 )
goto V_222;
V_140 [ 0 ] . V_212 . V_166 = 1 ;
V_140 [ 0 ] . V_212 . V_214 = 1 ;
V_140 [ 0 ] . V_212 . V_213 = V_227 -> V_213 ;
V_140 [ 0 ] . V_212 . V_231 = V_232 ;
V_140 [ 0 ] . V_212 . V_233 = 12 ;
V_21 = F_95 ( V_4 , NULL ,
V_97 ,
V_207 | V_209 ,
V_140 ,
V_4 -> V_215 ,
0 , 0 , NULL , NULL , NULL ) ;
if ( V_21 < 0 )
goto V_225;
V_21 = F_115 ( V_227 , V_234 ) ;
F_10 ( L_22 , V_21 ) ;
F_74 ( V_140 ) ;
return 0 ;
V_225:
F_111 ( V_227 ) ;
V_222:
F_74 ( V_140 ) ;
return V_21 ;
}
static int F_116 ( struct V_3 * V_4 ,
const char * V_158 ,
const char * V_235 ,
const char * V_236 ,
const char * V_216 ,
int V_101 ,
V_67 * V_166 )
{
struct V_136 * V_140 ;
int V_237 = strlen ( V_235 ) ;
int V_238 = strlen ( V_236 ) ;
int V_21 ;
V_140 = F_73 ( 1 , V_239 ,
V_237 + V_238 + V_101 ) ;
if ( ! V_140 )
return - V_22 ;
V_140 [ 0 ] . V_240 . V_235 = V_235 ;
V_140 [ 0 ] . V_240 . V_241 = ( V_242 ) V_237 ;
V_140 [ 0 ] . V_240 . V_236 = V_236 ;
V_140 [ 0 ] . V_240 . V_243 = ( V_242 ) V_238 ;
V_140 [ 0 ] . V_240 . V_244 = 0 ;
V_140 [ 0 ] . V_240 . V_245 = V_216 ;
V_140 [ 0 ] . V_240 . V_246 = V_101 ;
V_21 = F_95 ( V_4 , NULL ,
V_97 ,
V_207 | V_209 ,
V_140 ,
V_158 , 0 , 0 , NULL , NULL , V_166 ) ;
F_74 ( V_140 ) ;
F_10 ( L_23 , V_21 ) ;
return V_21 ;
}
static struct V_54 * F_117 ( int V_247 )
{
struct V_54 * V_55 =
F_35 ( sizeof( struct V_54 ) +
sizeof( struct V_248 ) * V_247 ,
V_249 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_127 = V_247 ;
F_12 ( & V_55 -> V_25 ) ;
return V_55 ;
}
static void F_118 ( struct V_146 * V_147 )
{
struct V_3 * V_4 = V_147 -> V_250 ;
struct V_143 * V_144 ;
struct V_121 * V_122 = NULL ;
while ( ( V_144 = F_119 ( V_147 ) ) ) {
struct V_108 * V_108 ;
struct V_108 * V_251 , * V_252 = NULL ;
bool V_253 ;
unsigned int V_91 ;
V_67 V_254 = 0 ;
V_67 V_100 ;
int V_255 , V_256 = 0 ;
struct V_54 * V_55 ;
struct V_66 * V_68 ;
if ( ! V_144 )
break;
F_10 ( L_24 ) ;
if ( ( V_144 -> V_257 != V_258 ) ) {
F_120 ( V_144 , 0 ) ;
continue;
}
V_253 = ( F_121 ( V_144 ) == V_259 ) ;
V_91 = F_122 ( V_144 ) ;
V_100 = F_123 ( V_144 ) * V_131 ;
V_251 = V_144 -> V_108 ;
if ( V_253 && V_4 -> V_11 ) {
F_120 ( V_144 , - V_12 ) ;
continue;
}
F_79 ( V_147 -> V_149 ) ;
F_124 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_96 != V_97 && ! V_4 -> V_98 ) {
F_125 ( & V_4 -> V_94 ) ;
F_10 ( L_25 ) ;
F_77 ( V_147 -> V_149 ) ;
F_120 ( V_144 , - V_64 ) ;
continue;
}
V_68 = F_126 ( V_4 -> V_61 . V_68 ) ;
F_125 ( & V_4 -> V_94 ) ;
F_10 ( L_26 ,
V_253 ? L_27 : L_28 ,
V_91 , ( unsigned long long ) F_123 ( V_144 ) * V_131 ) ;
V_255 = F_59 ( & V_4 -> V_61 , V_100 , V_91 ) ;
V_55 = F_117 ( V_255 ) ;
if ( ! V_55 ) {
F_77 ( V_147 -> V_149 ) ;
F_120 ( V_144 , - V_22 ) ;
F_56 ( V_68 ) ;
continue;
}
do {
F_10 ( L_29 , V_144 -> V_108 -> V_260 ) ;
V_254 = F_57 ( & V_4 -> V_61 ,
V_4 -> V_61 . V_74 ,
V_100 , V_91 ,
NULL , NULL ) ;
F_38 ( & V_55 -> V_25 ) ;
V_108 = F_68 ( & V_251 , & V_252 , & V_122 ,
V_254 , V_249 ) ;
if ( ! V_108 ) {
F_75 ( V_144 , V_55 , V_256 ,
- V_22 , V_254 ) ;
goto V_261;
}
if ( V_253 )
F_102 ( V_144 , V_4 ,
V_68 ,
V_100 ,
V_254 , V_108 ,
V_55 , V_256 ) ;
else
F_103 ( V_144 , V_4 ,
V_4 -> V_96 ,
V_100 ,
V_254 , V_108 ,
V_55 , V_256 ) ;
V_261:
V_91 -= V_254 ;
V_100 += V_254 ;
V_256 ++ ;
V_251 = V_252 ;
} while ( V_91 > 0 );
F_43 ( & V_55 -> V_25 , F_44 ) ;
if ( V_122 )
F_69 ( V_122 ) ;
F_77 ( V_147 -> V_149 ) ;
F_56 ( V_68 ) ;
}
}
static int F_127 ( struct V_146 * V_147 , struct V_262 * V_263 ,
struct V_113 * V_264 )
{
struct V_3 * V_4 = V_147 -> V_250 ;
unsigned int V_265 ;
T_8 V_266 ;
unsigned int V_267 ;
int F_65 ;
V_265 = 1 << ( V_4 -> V_61 . V_78 - V_268 ) ;
V_266 = V_263 -> V_269 + F_128 ( V_263 -> V_134 ) ;
V_267 = V_263 -> V_130 >> V_268 ;
F_65 = ( V_265 - ( ( V_266 & ( V_265 - 1 ) )
+ V_267 ) ) << V_268 ;
if ( F_65 < 0 )
F_65 = 0 ;
if ( F_65 <= V_264 -> V_117 && V_267 == 0 )
return V_264 -> V_117 ;
return F_65 ;
}
static void F_129 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
if ( ! V_14 )
return;
F_55 ( & V_4 -> V_61 ) ;
if ( V_14 -> V_35 & V_270 )
F_130 ( V_14 ) ;
if ( V_14 -> V_271 )
F_131 ( V_14 -> V_271 ) ;
F_132 ( V_14 ) ;
}
static int F_133 ( struct V_3 * V_4 ,
struct V_60 * V_61 )
{
T_9 V_151 ;
struct V_56 * V_272 ;
T_4 V_63 = 0 ;
V_67 V_166 ;
T_3 V_101 ;
V_101 = sizeof ( * V_272 ) ;
while ( 1 ) {
V_272 = F_11 ( V_101 , V_23 ) ;
if ( ! V_272 )
return - V_22 ;
V_151 = F_104 ( V_4 ,
V_97 ,
V_4 -> V_215 ,
0 , V_101 ,
( char * ) V_272 , & V_166 ) ;
if ( V_151 < 0 )
goto V_273;
V_151 = F_46 ( V_61 , V_272 , V_63 ) ;
if ( V_151 < 0 ) {
if ( V_151 == - V_64 )
F_108 ( L_30
L_31 ,
V_4 -> V_274 ) ;
goto V_273;
}
if ( V_63 == V_61 -> V_86 )
break;
V_63 = V_61 -> V_86 ;
V_101 = sizeof ( * V_272 ) +
V_63 * sizeof( struct V_275 ) +
V_61 -> V_69 ;
F_55 ( V_61 ) ;
F_23 ( V_272 ) ;
}
V_61 -> V_223 = V_166 ;
V_273:
F_23 ( V_272 ) ;
return V_151 ;
}
static int F_134 ( struct V_3 * V_4 ,
const char * V_90 ,
T_5 V_276 )
{
int V_277 = strlen ( V_90 ) ;
V_67 V_278 ;
int V_21 ;
void * V_216 , * V_92 , * V_279 ;
struct V_280 * V_281 ;
if ( V_4 -> V_96 != V_97 )
return - V_44 ;
V_281 = & V_4 -> V_15 -> V_29 -> V_281 ;
V_21 = F_135 ( V_281 , V_4 -> V_192 , & V_278 ) ;
F_10 ( L_32 , ( unsigned long long ) V_278 ) ;
if ( V_21 < 0 )
return V_21 ;
V_216 = F_11 ( V_277 + 16 , V_276 ) ;
if ( ! V_216 )
return - V_22 ;
V_92 = V_216 ;
V_279 = V_216 + V_277 + 16 ;
F_136 ( & V_92 , V_279 , V_90 , V_277 , V_282 ) ;
F_137 ( & V_92 , V_279 , V_278 , V_282 ) ;
V_21 = F_116 ( V_4 , V_4 -> V_215 ,
L_33 , L_34 ,
V_216 , V_92 - V_216 , NULL ) ;
F_23 ( V_216 ) ;
return V_21 < 0 ? V_21 : 0 ;
V_282:
return - V_283 ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_284 * V_285 ;
struct V_284 * V_120 ;
F_139 (snap, next, &rbd_dev->snaps, node)
F_140 ( V_285 ) ;
}
static int F_141 ( struct V_3 * V_4 , V_67 * V_217 )
{
int V_21 ;
struct V_60 V_286 ;
V_21 = F_133 ( V_4 , & V_286 ) ;
if ( V_21 < 0 )
return V_21 ;
F_53 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_96 == V_97 ) {
T_8 V_91 = ( T_8 ) V_286 . V_77 / V_131 ;
F_10 ( L_35 , ( unsigned long long ) V_91 ) ;
F_142 ( V_4 -> V_14 , V_91 ) ;
}
F_23 ( V_4 -> V_61 . V_72 ) ;
F_23 ( V_4 -> V_61 . V_70 ) ;
F_56 ( V_4 -> V_61 . V_68 ) ;
if ( V_217 )
* V_217 = V_286 . V_223 ;
V_4 -> V_61 . V_223 = V_286 . V_223 ;
V_4 -> V_61 . V_77 = V_286 . V_77 ;
V_4 -> V_61 . V_86 = V_286 . V_86 ;
V_4 -> V_61 . V_68 = V_286 . V_68 ;
V_4 -> V_61 . V_70 = V_286 . V_70 ;
V_4 -> V_61 . V_69 = V_286 . V_69 ;
V_4 -> V_61 . V_72 = V_286 . V_72 ;
F_49 ( strcmp ( V_4 -> V_61 . V_74 , V_286 . V_74 ) ) ;
F_23 ( V_286 . V_74 ) ;
V_21 = F_143 ( V_4 ) ;
F_54 ( & V_4 -> V_94 ) ;
return V_21 ;
}
static int F_107 ( struct V_3 * V_4 , V_67 * V_217 )
{
int V_21 ;
F_14 ( & V_27 , V_28 ) ;
V_21 = F_141 ( V_4 , V_217 ) ;
F_21 ( & V_27 ) ;
return V_21 ;
}
static int F_144 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
struct V_146 * V_147 ;
int V_151 ;
V_67 V_287 ;
V_67 V_288 = 0 ;
V_151 = F_133 ( V_4 , & V_4 -> V_61 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_143 ( V_4 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_52 ( V_4 , & V_288 ) ;
if ( V_151 )
return V_151 ;
V_151 = - V_22 ;
V_14 = F_145 ( V_289 ) ;
if ( ! V_14 )
goto V_290;
snprintf ( V_14 -> V_291 , sizeof( V_14 -> V_291 ) , V_218 L_36 ,
V_4 -> V_292 ) ;
V_14 -> V_219 = V_4 -> V_219 ;
V_14 -> V_293 = 0 ;
V_14 -> V_294 = & V_295 ;
V_14 -> V_9 = V_4 ;
V_151 = - V_22 ;
V_147 = F_146 ( F_118 , & V_4 -> V_296 ) ;
if ( ! V_147 )
goto V_297;
F_147 ( V_147 , V_131 ) ;
V_287 = F_60 ( & V_4 -> V_61 ) ;
F_148 ( V_147 , V_287 / V_131 ) ;
F_149 ( V_147 , V_287 ) ;
F_150 ( V_147 , V_287 ) ;
F_151 ( V_147 , V_287 ) ;
F_152 ( V_147 , F_127 ) ;
V_14 -> V_271 = V_147 ;
V_147 -> V_250 = V_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_147 = V_147 ;
F_142 ( V_14 , V_288 / V_131 ) ;
F_153 ( V_14 ) ;
F_154 ( L_37 ,
V_14 -> V_291 , ( unsigned long long ) V_288 ) ;
return 0 ;
V_297:
F_132 ( V_14 ) ;
V_290:
return V_151 ;
}
static struct V_3 * F_155 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , struct V_3 , V_2 ) ;
}
static T_9 F_156 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
T_8 V_91 ;
F_124 ( & V_4 -> V_94 ) ;
V_91 = F_157 ( V_4 -> V_14 ) ;
F_125 ( & V_4 -> V_94 ) ;
return sprintf ( V_115 , L_38 , ( unsigned long long ) V_91 * V_131 ) ;
}
static T_9 F_158 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_39 , V_4 -> V_219 ) ;
}
static T_9 F_159 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_40 ,
F_160 ( V_4 -> V_15 -> V_29 ) ) ;
}
static T_9 F_161 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_41 , V_4 -> V_300 ) ;
}
static T_9 F_162 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_39 , V_4 -> V_192 ) ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
struct V_298 * V_299 , char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_41 , V_4 -> V_274 ) ;
}
static T_9 F_164 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
char * V_115 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
return sprintf ( V_115 , L_41 , V_4 -> V_90 ) ;
}
static T_9 F_165 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
const char * V_115 ,
T_3 V_91 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
int V_21 ;
V_21 = F_107 ( V_4 , NULL ) ;
return V_21 < 0 ? V_21 : V_91 ;
}
static void F_166 ( struct V_1 * V_2 )
{
}
static T_9 F_167 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
char * V_115 )
{
struct V_284 * V_285 = F_40 ( V_2 , struct V_284 , V_2 ) ;
return sprintf ( V_115 , L_38 , ( unsigned long long ) V_285 -> V_91 ) ;
}
static T_9 F_168 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
char * V_115 )
{
struct V_284 * V_285 = F_40 ( V_2 , struct V_284 , V_2 ) ;
return sprintf ( V_115 , L_38 , ( unsigned long long ) V_285 -> V_89 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_284 * V_285 = F_40 ( V_2 , struct V_284 , V_2 ) ;
F_23 ( V_285 -> V_301 ) ;
F_23 ( V_285 ) ;
}
static void F_140 ( struct V_284 * V_285 )
{
F_41 ( & V_285 -> V_26 ) ;
F_170 ( & V_285 -> V_2 ) ;
}
static int F_171 ( struct V_284 * V_285 ,
struct V_1 * V_302 )
{
struct V_1 * V_2 = & V_285 -> V_2 ;
int V_21 ;
V_2 -> type = & V_303 ;
V_2 -> V_302 = V_302 ;
V_2 -> V_304 = F_169 ;
F_172 ( V_2 , L_42 , V_285 -> V_301 ) ;
V_21 = F_173 ( V_2 ) ;
return V_21 ;
}
static struct V_284 * F_174 ( struct V_3 * V_4 ,
int V_87 , const char * V_301 )
{
struct V_284 * V_285 ;
int V_21 ;
V_285 = F_35 ( sizeof ( * V_285 ) , V_23 ) ;
if ( ! V_285 )
return F_25 ( - V_22 ) ;
V_21 = - V_22 ;
V_285 -> V_301 = F_175 ( V_301 , V_23 ) ;
if ( ! V_285 -> V_301 )
goto V_305;
V_285 -> V_91 = V_4 -> V_61 . V_72 [ V_87 ] ;
V_285 -> V_89 = V_4 -> V_61 . V_68 -> V_88 [ V_87 ] ;
if ( F_176 ( & V_4 -> V_2 ) ) {
V_21 = F_171 ( V_285 , & V_4 -> V_2 ) ;
if ( V_21 < 0 )
goto V_305;
}
return V_285 ;
V_305:
F_23 ( V_285 -> V_301 ) ;
F_23 ( V_285 ) ;
return F_25 ( V_21 ) ;
}
const char * F_177 ( const char * V_301 , const char * V_306 )
{
if ( V_301 < V_306 + 2 )
return NULL ;
V_301 -= 2 ;
while ( * V_301 ) {
if ( V_301 == V_306 )
return V_306 ;
V_301 -- ;
}
return V_301 + 1 ;
}
static int F_143 ( struct V_3 * V_4 )
{
const char * V_301 , * V_307 ;
int V_87 = V_4 -> V_61 . V_86 ;
struct V_284 * V_285 , * V_308 = NULL ;
struct V_309 * V_92 , * V_310 ;
V_307 = V_4 -> V_61 . V_70 ;
V_301 = V_307 + V_4 -> V_61 . V_69 ;
F_178 (p, n, &rbd_dev->snaps) {
V_67 V_311 ;
V_308 = F_179 ( V_92 , struct V_284 , V_26 ) ;
if ( V_87 )
V_311 = V_4 -> V_61 . V_68 -> V_88 [ V_87 - 1 ] ;
if ( ! V_87 || V_308 -> V_89 < V_311 ) {
if ( V_4 -> V_96 == V_308 -> V_89 )
V_4 -> V_98 = false ;
F_140 ( V_308 ) ;
continue;
}
if ( V_308 -> V_89 == V_311 ) {
V_87 -- ;
V_301 = F_177 ( V_301 , V_307 ) ;
continue;
}
for (; V_87 > 0 ;
V_87 -- , V_301 = F_177 ( V_301 , V_307 ) ) {
if ( ! V_301 ) {
F_49 ( 1 ) ;
return - V_44 ;
}
V_311 = V_4 -> V_61 . V_68 -> V_88 [ V_87 ] ;
if ( V_311 >= V_308 -> V_89 )
break;
V_285 = F_174 ( V_4 , V_87 - 1 , V_301 ) ;
if ( F_16 ( V_285 ) )
return F_98 ( V_285 ) ;
F_180 ( & V_285 -> V_26 , V_310 ) ;
V_92 = & V_285 -> V_26 ;
}
}
for (; V_87 > 0 ; V_87 -- ) {
V_301 = F_177 ( V_301 , V_307 ) ;
if ( ! V_301 ) {
F_49 ( 1 ) ;
return - V_44 ;
}
V_285 = F_174 ( V_4 , V_87 - 1 , V_301 ) ;
if ( F_16 ( V_285 ) )
return F_98 ( V_285 ) ;
F_180 ( & V_285 -> V_26 , & V_4 -> V_88 ) ;
}
return 0 ;
}
static int F_181 ( struct V_3 * V_4 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_284 * V_285 ;
F_14 ( & V_27 , V_28 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_312 = & V_313 ;
V_2 -> type = & V_314 ;
V_2 -> V_302 = & V_315 ;
V_2 -> V_304 = V_316 ;
F_172 ( V_2 , L_36 , V_4 -> V_292 ) ;
V_21 = F_173 ( V_2 ) ;
if ( V_21 < 0 )
goto V_290;
F_27 (snap, &rbd_dev->snaps, node) {
V_21 = F_171 ( V_285 , & V_4 -> V_2 ) ;
if ( V_21 < 0 )
break;
}
V_290:
F_21 ( & V_27 ) ;
return V_21 ;
}
static void F_182 ( struct V_3 * V_4 )
{
F_170 ( & V_4 -> V_2 ) ;
}
static int F_183 ( struct V_3 * V_4 )
{
int V_21 , V_151 ;
do {
V_21 = F_109 ( V_4 ) ;
if ( V_21 == - V_283 ) {
V_151 = F_107 ( V_4 , NULL ) ;
if ( V_151 < 0 )
return V_151 ;
}
} while ( V_21 == - V_283 );
return V_21 ;
}
static void F_184 ( struct V_3 * V_4 )
{
V_4 -> V_292 = F_185 ( & V_317 ) ;
F_18 ( & V_318 ) ;
F_19 ( & V_4 -> V_26 , & V_319 ) ;
F_20 ( & V_318 ) ;
}
static void F_186 ( struct V_3 * V_4 )
{
struct V_309 * V_110 ;
int V_320 = V_4 -> V_292 ;
int V_321 ;
F_33 ( V_320 < 1 ) ;
F_18 ( & V_318 ) ;
F_187 ( & V_4 -> V_26 ) ;
if ( V_320 != F_188 ( & V_317 ) ) {
F_20 ( & V_318 ) ;
return;
}
V_321 = 0 ;
F_189 (tmp, &rbd_dev_list) {
struct V_3 * V_4 ;
V_4 = F_179 ( V_110 , struct V_3 , V_26 ) ;
if ( V_320 > V_321 )
V_321 = V_320 ;
}
F_20 ( & V_318 ) ;
F_190 ( & V_317 , V_320 , V_321 ) ;
}
static inline T_3 F_191 ( const char * * V_115 )
{
const char * V_322 = L_43 ;
* V_115 += strspn ( * V_115 , V_322 ) ;
return strcspn ( * V_115 , V_322 ) ;
}
static inline T_3 F_192 ( const char * * V_115 ,
char * V_41 ,
T_3 V_323 )
{
T_3 V_101 ;
V_101 = F_191 ( V_115 ) ;
if ( V_101 < V_323 ) {
memcpy ( V_41 , * V_115 , V_101 ) ;
* ( V_41 + V_101 ) = '\0' ;
}
* V_115 += V_101 ;
return V_101 ;
}
static inline char * F_193 ( const char * * V_115 , T_3 * V_324 )
{
char * V_325 ;
T_3 V_101 ;
V_101 = F_191 ( V_115 ) ;
V_325 = F_11 ( V_101 + 1 , V_23 ) ;
if ( ! V_325 )
return NULL ;
memcpy ( V_325 , * V_115 , V_101 ) ;
* ( V_325 + V_101 ) = '\0' ;
* V_115 += V_101 ;
if ( V_324 )
* V_324 = V_101 ;
return V_325 ;
}
static int F_194 ( struct V_3 * V_4 ,
const char * V_115 ,
const char * * V_326 ,
T_3 * V_327 ,
char * V_52 ,
T_3 V_328 )
{
T_3 V_101 ;
int V_21 ;
V_101 = F_191 ( & V_115 ) ;
if ( ! V_101 )
return - V_44 ;
* V_327 = V_101 + 1 ;
* V_326 = V_115 ;
V_115 += V_101 ;
V_101 = F_192 ( & V_115 , V_52 , V_328 ) ;
if ( ! V_101 || V_101 >= V_328 )
return - V_44 ;
V_21 = - V_22 ;
V_4 -> V_300 = F_193 ( & V_115 , NULL ) ;
if ( ! V_4 -> V_300 )
goto V_31;
V_4 -> V_274 = F_193 ( & V_115 , & V_4 -> V_329 ) ;
if ( ! V_4 -> V_274 )
goto V_31;
V_4 -> V_215 = F_11 ( V_4 -> V_329
+ sizeof ( V_330 ) ,
V_23 ) ;
if ( ! V_4 -> V_215 )
goto V_31;
sprintf ( V_4 -> V_215 , L_44 , V_4 -> V_274 , V_330 ) ;
V_4 -> V_90 = F_193 ( & V_115 , & V_101 ) ;
if ( ! V_4 -> V_90 )
goto V_31;
if ( ! V_101 ) {
F_23 ( V_4 -> V_90 ) ;
V_4 -> V_90
= F_11 ( sizeof ( V_95 ) , V_23 ) ;
if ( ! V_4 -> V_90 )
goto V_31;
memcpy ( V_4 -> V_90 , V_95 ,
sizeof ( V_95 ) ) ;
}
return 0 ;
V_31:
F_23 ( V_4 -> V_215 ) ;
F_23 ( V_4 -> V_274 ) ;
F_23 ( V_4 -> V_300 ) ;
V_4 -> V_300 = NULL ;
return V_21 ;
}
static T_9 F_195 ( struct V_331 * V_312 ,
const char * V_115 ,
T_3 V_332 )
{
char * V_52 ;
struct V_3 * V_4 = NULL ;
const char * V_326 = NULL ;
T_3 V_327 = 0 ;
struct V_176 * V_177 ;
int V_151 = - V_22 ;
if ( ! F_196 ( V_333 ) )
return - V_334 ;
V_52 = F_11 ( V_332 , V_23 ) ;
if ( ! V_52 )
goto V_335;
V_4 = F_35 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_335;
F_197 ( & V_4 -> V_296 ) ;
F_13 ( & V_4 -> V_26 ) ;
F_13 ( & V_4 -> V_88 ) ;
F_198 ( & V_4 -> V_94 ) ;
F_184 ( V_4 ) ;
F_199 ( V_336
< sizeof ( V_218 ) + V_337 ) ;
sprintf ( V_4 -> V_301 , L_45 , V_218 , V_4 -> V_292 ) ;
V_151 = F_194 ( V_4 , V_115 , & V_326 , & V_327 ,
V_52 , V_332 ) ;
if ( V_151 )
goto V_338;
V_4 -> V_15 = F_34 ( V_326 , V_327 - 1 ,
V_52 ) ;
if ( F_16 ( V_4 -> V_15 ) ) {
V_151 = F_98 ( V_4 -> V_15 ) ;
goto V_338;
}
V_177 = & V_4 -> V_15 -> V_29 -> V_177 ;
V_151 = F_200 ( V_177 -> V_339 , V_4 -> V_300 ) ;
if ( V_151 < 0 )
goto V_340;
V_4 -> V_192 = V_151 ;
V_151 = F_201 ( 0 , V_4 -> V_301 ) ;
if ( V_151 < 0 )
goto V_340;
V_4 -> V_219 = V_151 ;
V_151 = F_181 ( V_4 ) ;
if ( V_151 )
goto V_341;
V_151 = F_144 ( V_4 ) ;
if ( V_151 )
goto V_342;
V_151 = F_183 ( V_4 ) ;
if ( V_151 )
goto V_342;
return V_332 ;
V_342:
F_182 ( V_4 ) ;
F_23 ( V_52 ) ;
return V_151 ;
V_341:
F_202 ( V_4 -> V_219 , V_4 -> V_301 ) ;
V_340:
F_42 ( V_4 ) ;
V_338:
if ( V_4 -> V_300 ) {
F_23 ( V_4 -> V_90 ) ;
F_23 ( V_4 -> V_215 ) ;
F_23 ( V_4 -> V_274 ) ;
F_23 ( V_4 -> V_300 ) ;
}
F_186 ( V_4 ) ;
V_335:
F_23 ( V_4 ) ;
F_23 ( V_52 ) ;
F_10 ( L_46 , V_115 ) ;
F_203 ( V_333 ) ;
return ( T_9 ) V_151 ;
}
static struct V_3 * F_204 ( unsigned long V_292 )
{
struct V_309 * V_110 ;
struct V_3 * V_4 ;
F_18 ( & V_318 ) ;
F_205 (tmp, &rbd_dev_list) {
V_4 = F_179 ( V_110 , struct V_3 , V_26 ) ;
if ( V_4 -> V_292 == V_292 ) {
F_20 ( & V_318 ) ;
return V_4 ;
}
}
F_20 ( & V_318 ) ;
return NULL ;
}
static void V_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
if ( V_4 -> V_224 ) {
struct V_343 * V_29 = V_4 -> V_15 -> V_29 ;
F_206 ( & V_29 -> V_177 ,
V_4 -> V_224 ) ;
}
if ( V_4 -> V_221 )
F_112 ( V_4 ) ;
F_42 ( V_4 ) ;
F_129 ( V_4 ) ;
F_202 ( V_4 -> V_219 , V_4 -> V_301 ) ;
F_23 ( V_4 -> V_90 ) ;
F_23 ( V_4 -> V_215 ) ;
F_23 ( V_4 -> V_300 ) ;
F_23 ( V_4 -> V_274 ) ;
F_186 ( V_4 ) ;
F_23 ( V_4 ) ;
F_203 ( V_333 ) ;
}
static T_9 F_207 ( struct V_331 * V_312 ,
const char * V_115 ,
T_3 V_332 )
{
struct V_3 * V_4 = NULL ;
int V_344 , V_151 ;
unsigned long V_345 ;
int V_21 = V_332 ;
V_151 = F_208 ( V_115 , 10 , & V_345 ) ;
if ( V_151 )
return V_151 ;
V_344 = ( int ) V_345 ;
if ( V_344 != V_345 )
return - V_44 ;
F_14 ( & V_27 , V_28 ) ;
V_4 = F_204 ( V_344 ) ;
if ( ! V_4 ) {
V_21 = - V_93 ;
goto V_99;
}
F_138 ( V_4 ) ;
F_182 ( V_4 ) ;
V_99:
F_21 ( & V_27 ) ;
return V_21 ;
}
static T_9 F_209 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
const char * V_115 ,
T_3 V_332 )
{
struct V_3 * V_4 = F_155 ( V_2 ) ;
int V_21 ;
char * V_301 = F_11 ( V_332 + 1 , V_23 ) ;
if ( ! V_301 )
return - V_22 ;
snprintf ( V_301 , V_332 , L_47 , V_115 ) ;
F_14 ( & V_27 , V_28 ) ;
V_21 = F_134 ( V_4 ,
V_301 , V_23 ) ;
if ( V_21 < 0 )
goto V_346;
V_21 = F_141 ( V_4 , NULL ) ;
if ( V_21 < 0 )
goto V_346;
F_21 ( & V_27 ) ;
F_114 ( V_4 ) ;
V_21 = V_332 ;
F_23 ( V_301 ) ;
return V_21 ;
V_346:
F_21 ( & V_27 ) ;
F_23 ( V_301 ) ;
return V_21 ;
}
static int F_210 ( void )
{
int V_21 ;
V_21 = F_173 ( & V_315 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_211 ( & V_313 ) ;
if ( V_21 < 0 )
F_170 ( & V_315 ) ;
return V_21 ;
}
static void F_212 ( void )
{
F_213 ( & V_313 ) ;
F_170 ( & V_315 ) ;
}
int T_10 F_214 ( void )
{
int V_151 ;
V_151 = F_210 () ;
if ( V_151 )
return V_151 ;
F_154 ( L_48 V_347 L_49 ) ;
return 0 ;
}
void T_11 F_215 ( void )
{
F_212 () ;
}
