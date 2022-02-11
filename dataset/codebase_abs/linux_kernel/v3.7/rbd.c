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
if ( ( V_7 & V_10 ) && V_4 -> V_11 . V_12 )
return - V_13 ;
F_2 ( V_4 ) ;
F_7 ( V_6 , V_4 -> V_11 . V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , T_1 V_7 )
{
struct V_3 * V_4 = V_15 -> V_9 ;
F_4 ( V_4 ) ;
return 0 ;
}
static struct V_16 * F_9 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
int V_20 = - V_21 ;
F_10 ( L_1 ) ;
V_19 = F_11 ( sizeof( struct V_16 ) , V_22 ) ;
if ( ! V_19 )
goto V_23;
F_12 ( & V_19 -> V_24 ) ;
F_13 ( & V_19 -> V_25 ) ;
F_14 ( & V_26 , V_27 ) ;
V_19 -> V_28 = F_15 ( V_18 , V_19 , 0 , 0 ) ;
if ( F_16 ( V_19 -> V_28 ) )
goto V_29;
V_18 = NULL ;
V_20 = F_17 ( V_19 -> V_28 ) ;
if ( V_20 < 0 )
goto V_30;
F_18 ( & V_31 ) ;
F_19 ( & V_19 -> V_25 , & V_32 ) ;
F_20 ( & V_31 ) ;
F_21 ( & V_26 ) ;
F_10 ( L_2 , V_19 ) ;
return V_19 ;
V_30:
F_22 ( V_19 -> V_28 ) ;
V_29:
F_21 ( & V_26 ) ;
F_23 ( V_19 ) ;
V_23:
if ( V_18 )
F_24 ( V_18 ) ;
return F_25 ( V_20 ) ;
}
static struct V_16 * F_26 ( struct V_17 * V_18 )
{
struct V_16 * V_33 ;
bool V_34 = false ;
if ( V_18 -> V_35 & V_36 )
return NULL ;
F_18 ( & V_31 ) ;
F_27 (client_node, &rbd_client_list, node) {
if ( ! F_28 ( V_18 , V_33 -> V_28 ) ) {
F_29 ( & V_33 -> V_24 ) ;
V_34 = true ;
break;
}
}
F_20 ( & V_31 ) ;
return V_34 ? V_33 : NULL ;
}
static int F_30 ( char * V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
T_2 V_41 [ V_42 ] ;
int V_43 , V_44 , V_20 ;
V_43 = F_31 ( V_37 , V_45 , V_41 ) ;
if ( V_43 < 0 )
return - V_46 ;
if ( V_43 < V_47 ) {
V_20 = F_32 ( & V_41 [ 0 ] , & V_44 ) ;
if ( V_20 < 0 ) {
F_33 ( L_3
L_4 , V_37 ) ;
return V_20 ;
}
F_10 ( L_5 , V_43 , V_44 ) ;
} else if ( V_43 > V_47 && V_43 < V_48 ) {
F_10 ( L_6 , V_43 ,
V_41 [ 0 ] . V_49 ) ;
} else if ( V_43 > V_48 && V_43 < V_50 ) {
F_10 ( L_7 , V_43 ) ;
} else {
F_10 ( L_8 , V_43 ) ;
}
switch ( V_43 ) {
case V_51 :
V_40 -> V_12 = true ;
break;
case V_52 :
V_40 -> V_12 = false ;
break;
default:
F_34 ( false ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , const char * V_53 ,
T_3 V_54 , char * V_55 )
{
struct V_39 * V_40 = & V_4 -> V_40 ;
struct V_17 * V_18 ;
struct V_16 * V_19 ;
V_40 -> V_12 = V_56 ;
V_18 = F_36 ( V_55 , V_53 ,
V_53 + V_54 ,
F_30 , V_40 ) ;
if ( F_16 ( V_18 ) )
return F_37 ( V_18 ) ;
V_19 = F_26 ( V_18 ) ;
if ( V_19 ) {
F_24 ( V_18 ) ;
} else {
V_19 = F_9 ( V_18 ) ;
if ( F_16 ( V_19 ) )
return F_37 ( V_19 ) ;
}
V_4 -> V_16 = V_19 ;
return 0 ;
}
static void F_38 ( struct V_24 * V_24 )
{
struct V_16 * V_19 = F_39 ( V_24 , struct V_16 , V_24 ) ;
F_10 ( L_9 , V_19 ) ;
F_18 ( & V_31 ) ;
F_40 ( & V_19 -> V_25 ) ;
F_20 ( & V_31 ) ;
F_22 ( V_19 -> V_28 ) ;
F_23 ( V_19 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_16 -> V_24 , F_38 ) ;
V_4 -> V_16 = NULL ;
}
static void F_43 ( struct V_24 * V_24 )
{
struct V_57 * V_58 =
F_39 ( V_24 , struct V_57 , V_24 ) ;
F_10 ( L_10 , V_58 ) ;
F_23 ( V_58 ) ;
}
static bool F_44 ( T_4 V_59 )
{
return V_59 == 1 || V_59 == 2 ;
}
static bool F_45 ( struct V_60 * V_61 )
{
T_3 V_62 ;
T_4 V_63 ;
if ( memcmp ( & V_61 -> V_64 , V_65 , sizeof ( V_65 ) ) )
return false ;
V_63 = F_46 ( V_61 -> V_63 ) ;
V_62 = V_66 - sizeof ( struct V_67 ) ;
if ( V_63 > V_62 / sizeof ( V_68 ) )
return false ;
V_62 -= V_63 * sizeof ( V_68 ) ;
if ( ( V_69 ) V_62 < F_47 ( V_61 -> V_70 ) )
return false ;
return true ;
}
static int F_48 ( struct V_71 * V_72 ,
struct V_60 * V_61 )
{
T_4 V_63 ;
T_3 V_73 ;
T_3 V_62 ;
T_4 V_74 ;
memset ( V_72 , 0 , sizeof ( * V_72 ) ) ;
V_63 = F_46 ( V_61 -> V_63 ) ;
V_73 = F_49 ( V_61 -> V_75 , sizeof ( V_61 -> V_75 ) ) ;
V_72 -> V_75 = F_11 ( V_73 + 1 , V_22 ) ;
if ( ! V_72 -> V_75 )
return - V_21 ;
memcpy ( V_72 -> V_75 , V_61 -> V_75 , V_73 ) ;
V_72 -> V_75 [ V_73 ] = '\0' ;
if ( V_63 ) {
V_69 V_70 = F_47 ( V_61 -> V_70 ) ;
if ( V_70 > ( V_69 ) V_66 )
return - V_76 ;
V_72 -> V_77 = F_11 ( V_70 , V_22 ) ;
if ( ! V_72 -> V_77 )
goto V_30;
memcpy ( V_72 -> V_77 , & V_61 -> V_78 [ V_63 ] ,
V_70 ) ;
V_62 = V_63 * sizeof ( * V_72 -> V_79 ) ;
V_72 -> V_79 = F_11 ( V_62 , V_22 ) ;
if ( ! V_72 -> V_79 )
goto V_30;
for ( V_74 = 0 ; V_74 < V_63 ; V_74 ++ )
V_72 -> V_79 [ V_74 ] =
F_47 ( V_61 -> V_78 [ V_74 ] . V_80 ) ;
} else {
F_50 ( V_61 -> V_70 ) ;
V_72 -> V_77 = NULL ;
V_72 -> V_79 = NULL ;
}
V_72 -> V_81 = 0 ;
V_72 -> V_82 = V_61 -> V_55 . V_83 ;
V_72 -> V_84 = V_61 -> V_55 . V_84 ;
V_72 -> V_85 = V_61 -> V_55 . V_85 ;
V_72 -> V_80 = F_47 ( V_61 -> V_80 ) ;
V_62 = sizeof ( struct V_67 ) ;
V_62 += V_63 * sizeof ( V_72 -> V_86 -> V_78 [ 0 ] ) ;
V_72 -> V_86 = F_51 ( V_62 , V_22 ) ;
if ( ! V_72 -> V_86 )
goto V_30;
F_52 ( & V_72 -> V_86 -> V_87 , 1 ) ;
V_72 -> V_86 -> V_88 = F_47 ( V_61 -> V_89 ) ;
V_72 -> V_86 -> V_90 = V_63 ;
for ( V_74 = 0 ; V_74 < V_63 ; V_74 ++ )
V_72 -> V_86 -> V_78 [ V_74 ] =
F_47 ( V_61 -> V_78 [ V_74 ] . V_91 ) ;
return 0 ;
V_30:
F_23 ( V_72 -> V_79 ) ;
V_72 -> V_79 = NULL ;
F_23 ( V_72 -> V_77 ) ;
V_72 -> V_77 = NULL ;
F_23 ( V_72 -> V_75 ) ;
V_72 -> V_75 = NULL ;
return - V_21 ;
}
static int F_53 ( struct V_3 * V_4 , const char * V_92 )
{
struct V_93 * V_94 ;
F_27 (snap, &rbd_dev->snaps, node) {
if ( ! strcmp ( V_92 , V_94 -> V_95 ) ) {
V_4 -> V_11 . V_96 = V_94 -> V_91 ;
V_4 -> V_11 . V_62 = V_94 -> V_62 ;
V_4 -> V_11 . V_81 = V_94 -> V_81 ;
return 0 ;
}
}
return - V_97 ;
}
static int F_54 ( struct V_3 * V_4 , char * V_92 )
{
int V_20 ;
if ( ! memcmp ( V_92 , V_98 ,
sizeof ( V_98 ) ) ) {
V_4 -> V_11 . V_96 = V_99 ;
V_4 -> V_11 . V_62 = V_4 -> V_72 . V_80 ;
V_4 -> V_11 . V_81 = V_4 -> V_72 . V_81 ;
V_4 -> V_11 . V_100 = false ;
V_4 -> V_11 . V_12 = V_4 -> V_40 . V_12 ;
V_20 = 0 ;
} else {
V_20 = F_53 ( V_4 , V_92 ) ;
if ( V_20 < 0 )
goto V_101;
V_4 -> V_11 . V_100 = true ;
V_4 -> V_11 . V_12 = true ;
}
V_4 -> V_11 . V_92 = V_92 ;
V_101:
return V_20 ;
}
static void F_55 ( struct V_71 * V_72 )
{
F_23 ( V_72 -> V_75 ) ;
V_72 -> V_75 = NULL ;
F_23 ( V_72 -> V_79 ) ;
V_72 -> V_79 = NULL ;
F_23 ( V_72 -> V_77 ) ;
V_72 -> V_77 = NULL ;
F_56 ( V_72 -> V_86 ) ;
V_72 -> V_86 = NULL ;
}
static char * F_57 ( struct V_3 * V_4 , V_69 V_102 )
{
char * V_95 ;
V_69 V_103 ;
int V_20 ;
V_95 = F_11 ( V_104 + 1 , V_105 ) ;
if ( ! V_95 )
return NULL ;
V_103 = V_102 >> V_4 -> V_72 . V_82 ;
V_20 = snprintf ( V_95 , V_104 , L_11 ,
V_4 -> V_72 . V_75 , V_103 ) ;
if ( V_20 < 0 || V_20 >= V_104 ) {
F_33 ( L_12 ,
V_103 , V_20 ) ;
F_23 ( V_95 ) ;
V_95 = NULL ;
}
return V_95 ;
}
static V_69 F_58 ( struct V_3 * V_4 , V_69 V_102 )
{
V_69 V_106 = ( V_69 ) 1 << V_4 -> V_72 . V_82 ;
return V_102 & ( V_106 - 1 ) ;
}
static V_69 F_59 ( struct V_3 * V_4 ,
V_69 V_102 , V_69 V_107 )
{
V_69 V_106 = ( V_69 ) 1 << V_4 -> V_72 . V_82 ;
V_102 &= V_106 - 1 ;
F_34 ( V_107 <= V_108 - V_102 ) ;
if ( V_102 + V_107 > V_106 )
V_107 = V_106 - V_102 ;
return V_107 ;
}
static int F_60 ( struct V_71 * V_72 ,
V_69 V_109 , V_69 V_73 )
{
V_69 V_110 ;
V_69 V_111 ;
if ( ! V_73 )
return 0 ;
if ( V_73 - 1 > V_108 - V_109 )
return - V_112 ;
V_110 = V_109 >> V_72 -> V_82 ;
V_111 = ( V_109 + V_73 - 1 ) >> V_72 -> V_82 ;
return V_111 - V_110 + 1 ;
}
static V_69 F_61 ( struct V_71 * V_72 )
{
return 1 << V_72 -> V_82 ;
}
static void F_62 ( struct V_113 * V_114 )
{
struct V_113 * V_115 ;
while ( V_114 ) {
V_115 = V_114 ;
V_114 = V_114 -> V_116 ;
F_63 ( V_115 ) ;
}
}
static void F_64 ( struct V_113 * V_114 , int V_117 )
{
struct V_118 * V_119 ;
unsigned long V_35 ;
void * V_120 ;
int V_74 ;
int V_121 = 0 ;
while ( V_114 ) {
F_65 (bv, chain, i) {
if ( V_121 + V_119 -> V_122 > V_117 ) {
int V_123 = F_66 ( V_117 - V_121 , 0 ) ;
V_120 = F_67 ( V_119 , & V_35 ) ;
memset ( V_120 + V_123 , 0 ,
V_119 -> V_122 - V_123 ) ;
F_68 ( V_120 , & V_35 ) ;
}
V_121 += V_119 -> V_122 ;
}
V_114 = V_114 -> V_116 ;
}
}
static struct V_113 * F_69 ( struct V_113 * * V_124 , struct V_113 * * V_125 ,
struct V_126 * * V_127 ,
int V_73 , T_5 V_128 )
{
struct V_113 * V_129 = * V_124 ;
struct V_113 * V_130 = NULL ;
struct V_113 * V_131 ;
int V_132 = 0 ;
if ( * V_127 ) {
F_70 ( * V_127 ) ;
* V_127 = NULL ;
}
while ( V_129 && ( V_132 < V_73 ) ) {
struct V_113 * V_115 ;
V_115 = F_71 ( V_128 , V_129 -> V_133 ) ;
if ( ! V_115 )
goto V_134;
V_128 &= ~ V_135 ;
if ( V_132 + V_129 -> V_136 > V_73 ) {
struct V_126 * V_127 ;
F_10 ( L_13
L_14 ,
V_132 , V_73 - V_132 , V_129 -> V_136 ) ;
V_127 = F_72 ( V_129 , ( V_73 - V_132 ) / V_137 ) ;
if ( ! V_127 )
goto V_134;
F_73 ( V_115 , & V_127 -> V_138 ) ;
* V_125 = & V_127 -> V_139 ;
} else {
F_73 ( V_115 , V_129 ) ;
* V_125 = V_129 -> V_116 ;
}
V_115 -> V_140 = NULL ;
V_115 -> V_116 = NULL ;
if ( V_130 )
V_131 -> V_116 = V_115 ;
else
V_130 = V_115 ;
V_131 = V_115 ;
V_129 = V_129 -> V_116 ;
V_132 += V_115 -> V_136 ;
}
F_34 ( V_132 == V_73 ) ;
* V_124 = V_129 ;
return V_130 ;
V_134:
F_10 ( L_15 ) ;
F_62 ( V_130 ) ;
return NULL ;
}
static struct V_141 * F_74 ( int V_142 ,
int V_143 , T_4 V_144 )
{
struct V_141 * V_145 ;
V_145 = F_51 ( sizeof ( * V_145 ) * ( V_142 + 1 ) , V_105 ) ;
if ( ! V_145 )
return NULL ;
V_145 [ 0 ] . V_146 = V_143 ;
V_145 [ 0 ] . V_144 = V_144 ;
return V_145 ;
}
static void F_75 ( struct V_141 * V_145 )
{
F_23 ( V_145 ) ;
}
static void F_76 ( struct V_147 * V_148 ,
struct V_57 * V_58 ,
int V_149 ,
int V_20 , V_69 V_73 )
{
struct V_150 * V_151 ;
int V_152 , F_66 , V_74 ;
F_10 ( L_16 ,
V_58 , V_149 , V_20 , ( unsigned long long ) V_73 ) ;
if ( ! V_148 )
return;
if ( ! V_58 ) {
F_77 ( V_148 , V_20 , V_73 ) ;
return;
}
V_151 = V_148 -> V_151 ;
F_78 ( V_151 -> V_153 ) ;
V_58 -> V_154 [ V_149 ] . V_101 = 1 ;
V_58 -> V_154 [ V_149 ] . V_155 = V_20 ;
V_58 -> V_154 [ V_149 ] . V_156 = V_73 ;
F_66 = V_152 = V_58 -> V_157 ;
while ( F_66 < V_58 -> V_132 && V_58 -> V_154 [ F_66 ] . V_101 )
F_66 ++ ;
for ( V_74 = V_152 ; V_74 < F_66 ; V_74 ++ ) {
F_79 ( V_148 , V_58 -> V_154 [ V_74 ] . V_155 ,
V_58 -> V_154 [ V_74 ] . V_156 ) ;
V_58 -> V_157 ++ ;
F_42 ( & V_58 -> V_24 , F_43 ) ;
}
F_80 ( V_151 -> V_153 ) ;
}
static void F_81 ( struct V_158 * V_159 ,
int V_20 , V_69 V_73 )
{
F_76 ( V_159 -> V_148 , V_159 -> V_58 , V_159 -> V_160 , V_20 , V_73 ) ;
}
static int F_82 ( struct V_147 * V_148 ,
struct V_3 * V_4 ,
struct V_67 * V_86 ,
V_69 V_161 ,
const char * V_162 , V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_163 * * V_164 ,
int V_165 ,
int V_35 ,
struct V_141 * V_145 ,
struct V_57 * V_58 ,
int V_160 ,
void (* F_83)( struct V_166 * V_159 ,
struct V_167 * V_168 ) ,
struct V_166 * * V_169 ,
V_69 * V_170 )
{
struct V_166 * V_159 ;
struct V_171 * V_172 ;
int V_20 ;
V_69 V_173 ;
struct V_174 V_175 = V_176 ;
struct V_158 * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
V_177 = F_51 ( sizeof( * V_177 ) , V_105 ) ;
if ( ! V_177 ) {
if ( V_58 )
F_76 ( V_148 , V_58 , V_160 ,
- V_21 , V_73 ) ;
return - V_21 ;
}
if ( V_58 ) {
V_177 -> V_58 = V_58 ;
V_177 -> V_160 = V_160 ;
}
F_10 ( L_17 , V_162 ,
( unsigned long long ) V_109 , ( unsigned long long ) V_73 ) ;
V_181 = & V_4 -> V_16 -> V_28 -> V_181 ;
V_159 = F_84 ( V_181 , V_35 , V_86 , V_145 ,
false , V_105 , V_164 , V_113 ) ;
if ( ! V_159 ) {
V_20 = - V_21 ;
goto V_182;
}
V_159 -> V_183 = F_83 ;
V_177 -> V_148 = V_148 ;
V_177 -> V_113 = V_113 ;
V_177 -> V_164 = V_164 ;
V_177 -> V_73 = V_73 ;
V_159 -> V_184 = V_177 ;
V_179 = V_159 -> V_185 -> V_186 . V_187 ;
V_179 -> V_161 = F_85 ( V_99 ) ;
strncpy ( V_159 -> V_188 , V_162 , sizeof( V_159 -> V_188 ) ) ;
V_159 -> V_189 = strlen ( V_159 -> V_188 ) ;
V_172 = & V_159 -> V_190 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
V_172 -> V_191 = F_86 ( 1 << V_192 ) ;
V_172 -> V_193 = F_86 ( 1 ) ;
V_172 -> V_194 = F_86 ( 1 << V_192 ) ;
V_172 -> V_195 = F_86 ( V_4 -> V_196 ) ;
V_20 = F_87 ( V_181 , V_172 , V_161 , V_109 , & V_73 , & V_173 ,
V_159 , V_145 ) ;
F_34 ( V_20 == 0 ) ;
F_88 ( V_159 , V_109 , & V_73 ,
V_145 ,
V_86 ,
& V_175 ,
V_159 -> V_188 , V_159 -> V_189 ) ;
if ( V_169 ) {
F_89 ( V_181 , V_159 ) ;
* V_169 = V_159 ;
}
V_20 = F_90 ( V_181 , V_159 , false ) ;
if ( V_20 < 0 )
goto V_197;
if ( ! F_83 ) {
V_20 = F_91 ( V_181 , V_159 ) ;
if ( V_170 )
* V_170 = F_47 ( V_159 -> V_198 . V_199 ) ;
F_10 ( L_18 ,
( unsigned long long )
F_47 ( V_159 -> V_198 . V_199 ) ) ;
F_92 ( V_159 ) ;
}
return V_20 ;
V_197:
F_62 ( V_177 -> V_113 ) ;
F_92 ( V_159 ) ;
V_182:
F_81 ( V_177 , V_20 , V_73 ) ;
F_23 ( V_177 ) ;
return V_20 ;
}
static void F_93 ( struct V_166 * V_159 , struct V_167 * V_168 )
{
struct V_158 * V_177 = V_159 -> V_184 ;
struct V_200 * V_201 ;
struct V_202 * V_146 ;
T_6 V_155 ;
V_69 V_156 ;
int V_203 ;
V_201 = V_168 -> V_186 . V_187 ;
F_50 ( F_46 ( V_201 -> V_142 ) == 0 ) ;
V_146 = ( void * ) ( V_201 + 1 ) ;
V_155 = F_46 ( V_201 -> V_204 ) ;
V_156 = F_47 ( V_146 -> V_205 . V_107 ) ;
V_203 = ( F_94 ( V_146 -> V_146 ) == V_206 ) ;
F_10 ( L_19 ,
( unsigned long long ) V_156 , V_203 , ( int ) V_155 ) ;
if ( V_155 == - V_97 && V_203 ) {
F_64 ( V_177 -> V_113 , 0 ) ;
V_155 = 0 ;
} else if ( V_155 == 0 && V_203 && V_156 < V_177 -> V_73 ) {
F_64 ( V_177 -> V_113 , V_156 ) ;
V_156 = V_177 -> V_73 ;
}
F_81 ( V_177 , V_155 , V_156 ) ;
if ( V_177 -> V_113 )
F_62 ( V_177 -> V_113 ) ;
F_92 ( V_159 ) ;
F_23 ( V_177 ) ;
}
static void F_95 ( struct V_166 * V_159 , struct V_167 * V_168 )
{
F_92 ( V_159 ) ;
}
static int F_96 ( struct V_3 * V_4 ,
struct V_67 * V_86 ,
V_69 V_161 ,
int V_35 ,
struct V_141 * V_145 ,
const char * V_162 ,
V_69 V_109 , V_69 V_207 ,
char * V_208 ,
struct V_166 * * V_169 ,
V_69 * V_170 )
{
int V_20 ;
struct V_163 * * V_164 ;
int V_165 ;
F_34 ( V_145 != NULL ) ;
V_165 = F_97 ( V_109 , V_207 ) ;
V_164 = F_98 ( V_165 , V_22 ) ;
if ( F_16 ( V_164 ) )
return F_37 ( V_164 ) ;
V_20 = F_82 ( NULL , V_4 , V_86 , V_161 ,
V_162 , V_109 , V_207 , NULL ,
V_164 , V_165 ,
V_35 ,
V_145 ,
NULL , 0 ,
NULL ,
V_169 , V_170 ) ;
if ( V_20 < 0 )
goto V_101;
if ( ( V_35 & V_209 ) && V_208 )
V_20 = F_99 ( V_164 , V_208 , V_109 , V_20 ) ;
V_101:
F_100 ( V_164 , V_165 ) ;
return V_20 ;
}
static int F_101 ( struct V_147 * V_148 ,
struct V_3 * V_4 ,
struct V_67 * V_86 ,
V_69 V_161 ,
int V_143 , int V_35 ,
V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_57 * V_58 ,
int V_160 )
{
char * V_210 ;
V_69 V_211 ;
V_69 V_212 ;
int V_20 ;
struct V_141 * V_145 ;
T_4 V_144 ;
V_210 = F_57 ( V_4 , V_109 ) ;
if ( ! V_210 )
return - V_21 ;
V_212 = F_59 ( V_4 , V_109 , V_73 ) ;
V_211 = F_58 ( V_4 , V_109 ) ;
V_144 = ( V_35 & V_213 ? V_212 : 0 ) ;
V_20 = - V_21 ;
V_145 = F_74 ( 1 , V_143 , V_144 ) ;
if ( ! V_145 )
goto V_101;
F_34 ( V_212 == V_73 ) ;
V_20 = F_82 ( V_148 , V_4 , V_86 , V_161 ,
V_210 , V_211 , V_212 ,
V_113 ,
NULL , 0 ,
V_35 ,
V_145 ,
V_58 , V_160 ,
F_93 , 0 , NULL ) ;
F_75 ( V_145 ) ;
V_101:
F_23 ( V_210 ) ;
return V_20 ;
}
static int F_102 ( struct V_147 * V_148 ,
struct V_3 * V_4 ,
struct V_67 * V_86 ,
V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_57 * V_58 ,
int V_160 )
{
return F_101 ( V_148 , V_4 , V_86 , V_99 ,
V_214 ,
V_213 | V_215 ,
V_109 , V_73 , V_113 , V_58 , V_160 ) ;
}
static int F_103 ( struct V_147 * V_148 ,
struct V_3 * V_4 ,
V_69 V_161 ,
V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_57 * V_58 ,
int V_160 )
{
return F_101 ( V_148 , V_4 , NULL ,
V_161 ,
V_206 ,
V_209 ,
V_109 , V_73 , V_113 , V_58 , V_160 ) ;
}
static int F_104 ( struct V_3 * V_4 ,
V_69 V_161 ,
const char * V_162 ,
V_69 V_109 , V_69 V_73 ,
char * V_120 ,
V_69 * V_170 )
{
struct V_141 * V_145 ;
int V_20 ;
V_145 = F_74 ( 1 , V_206 , 0 ) ;
if ( ! V_145 )
return - V_21 ;
V_20 = F_96 ( V_4 , NULL ,
V_161 ,
V_209 ,
V_145 , V_162 , V_109 , V_73 , V_120 , NULL , V_170 ) ;
F_75 ( V_145 ) ;
return V_20 ;
}
static int F_105 ( struct V_3 * V_4 ,
V_69 V_170 ,
V_69 V_216 )
{
struct V_141 * V_145 ;
int V_20 ;
V_145 = F_74 ( 1 , V_217 , 0 ) ;
if ( ! V_145 )
return - V_21 ;
V_145 [ 0 ] . V_218 . V_170 = F_85 ( V_170 ) ;
V_145 [ 0 ] . V_218 . V_219 = V_216 ;
V_145 [ 0 ] . V_218 . V_220 = 0 ;
V_20 = F_82 ( NULL , V_4 , NULL , V_99 ,
V_4 -> V_221 , 0 , 0 , NULL ,
NULL , 0 ,
V_209 ,
V_145 ,
NULL , 0 ,
F_95 , 0 , NULL ) ;
F_75 ( V_145 ) ;
return V_20 ;
}
static void F_106 ( V_69 V_170 , V_69 V_216 , T_7 V_143 , void * V_222 )
{
struct V_3 * V_4 = (struct V_3 * ) V_222 ;
V_69 V_223 ;
int V_155 ;
if ( ! V_4 )
return;
F_10 ( L_20 ,
V_4 -> V_221 , ( unsigned long long ) V_216 ,
( unsigned int ) V_143 ) ;
V_155 = F_107 ( V_4 , & V_223 ) ;
if ( V_155 )
F_108 ( V_224 L_21
L_22 , V_4 -> V_225 , V_155 ) ;
F_105 ( V_4 , V_223 , V_216 ) ;
}
static int F_109 ( struct V_3 * V_4 )
{
struct V_141 * V_145 ;
struct V_180 * V_181 = & V_4 -> V_16 -> V_28 -> V_181 ;
int V_20 ;
V_145 = F_74 ( 1 , V_226 , 0 ) ;
if ( ! V_145 )
return - V_21 ;
V_20 = F_110 ( V_181 , F_106 , 0 ,
( void * ) V_4 , & V_4 -> V_227 ) ;
if ( V_20 < 0 )
goto V_228;
V_145 [ 0 ] . V_218 . V_170 = F_85 ( V_4 -> V_72 . V_229 ) ;
V_145 [ 0 ] . V_218 . V_219 = F_85 ( V_4 -> V_227 -> V_219 ) ;
V_145 [ 0 ] . V_218 . V_220 = 1 ;
V_20 = F_96 ( V_4 , NULL ,
V_99 ,
V_213 | V_215 ,
V_145 ,
V_4 -> V_221 ,
0 , 0 , NULL ,
& V_4 -> V_230 , NULL ) ;
if ( V_20 < 0 )
goto V_231;
F_75 ( V_145 ) ;
return 0 ;
V_231:
F_111 ( V_4 -> V_227 ) ;
V_4 -> V_227 = NULL ;
V_228:
F_75 ( V_145 ) ;
return V_20 ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_141 * V_145 ;
int V_20 ;
V_145 = F_74 ( 1 , V_226 , 0 ) ;
if ( ! V_145 )
return - V_21 ;
V_145 [ 0 ] . V_218 . V_170 = 0 ;
V_145 [ 0 ] . V_218 . V_219 = F_85 ( V_4 -> V_227 -> V_219 ) ;
V_145 [ 0 ] . V_218 . V_220 = 0 ;
V_20 = F_96 ( V_4 , NULL ,
V_99 ,
V_213 | V_215 ,
V_145 ,
V_4 -> V_221 ,
0 , 0 , NULL , NULL , NULL ) ;
F_75 ( V_145 ) ;
F_111 ( V_4 -> V_227 ) ;
V_4 -> V_227 = NULL ;
return V_20 ;
}
static int F_113 ( struct V_3 * V_4 ,
const char * V_162 ,
const char * V_232 ,
const char * V_233 ,
const char * V_234 ,
T_3 V_235 ,
char * V_208 ,
T_3 V_207 ,
int V_35 ,
V_69 * V_170 )
{
struct V_141 * V_145 ;
int V_236 = strlen ( V_232 ) ;
int V_237 = strlen ( V_233 ) ;
int V_238 ;
int V_20 ;
V_238 = V_236 + V_237 + V_235 ;
V_145 = F_74 ( 1 , V_239 , V_238 ) ;
if ( ! V_145 )
return - V_21 ;
V_145 [ 0 ] . V_240 . V_232 = V_232 ;
V_145 [ 0 ] . V_240 . V_241 = ( V_242 ) V_236 ;
V_145 [ 0 ] . V_240 . V_233 = V_233 ;
V_145 [ 0 ] . V_240 . V_243 = ( V_242 ) V_237 ;
V_145 [ 0 ] . V_240 . V_244 = 0 ;
V_145 [ 0 ] . V_240 . V_245 = V_234 ;
V_145 [ 0 ] . V_240 . V_246 = V_235 ;
V_20 = F_96 ( V_4 , NULL ,
V_99 ,
V_35 , V_145 ,
V_162 , 0 , V_207 , V_208 ,
NULL , V_170 ) ;
F_75 ( V_145 ) ;
F_10 ( L_23 , V_20 ) ;
return V_20 ;
}
static struct V_57 * F_114 ( int V_247 )
{
struct V_57 * V_58 =
F_51 ( sizeof( struct V_57 ) +
sizeof( struct V_248 ) * V_247 ,
V_249 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_132 = V_247 ;
F_12 ( & V_58 -> V_24 ) ;
return V_58 ;
}
static void F_115 ( struct V_150 * V_151 )
{
struct V_3 * V_4 = V_151 -> V_250 ;
struct V_147 * V_148 ;
struct V_126 * V_127 = NULL ;
while ( ( V_148 = F_116 ( V_151 ) ) ) {
struct V_113 * V_113 ;
struct V_113 * V_251 , * V_252 = NULL ;
bool V_253 ;
unsigned int V_62 ;
V_69 V_254 = 0 ;
V_69 V_109 ;
int V_255 , V_256 = 0 ;
struct V_57 * V_58 ;
struct V_67 * V_86 ;
F_10 ( L_24 ) ;
if ( ( V_148 -> V_257 != V_258 ) ) {
F_117 ( V_148 , 0 ) ;
continue;
}
V_253 = ( F_118 ( V_148 ) == V_259 ) ;
V_62 = F_119 ( V_148 ) ;
V_109 = F_120 ( V_148 ) * V_137 ;
V_251 = V_148 -> V_113 ;
if ( V_253 && V_4 -> V_11 . V_12 ) {
F_117 ( V_148 , - V_13 ) ;
continue;
}
F_80 ( V_151 -> V_153 ) ;
F_121 ( & V_4 -> V_260 ) ;
if ( V_4 -> V_11 . V_96 != V_99 &&
! V_4 -> V_11 . V_100 ) {
F_122 ( & V_4 -> V_260 ) ;
F_10 ( L_25 ) ;
F_78 ( V_151 -> V_153 ) ;
F_117 ( V_148 , - V_261 ) ;
continue;
}
V_86 = F_123 ( V_4 -> V_72 . V_86 ) ;
F_122 ( & V_4 -> V_260 ) ;
F_10 ( L_26 ,
V_253 ? L_27 : L_28 ,
V_62 , ( unsigned long long ) F_120 ( V_148 ) * V_137 ) ;
V_255 = F_60 ( & V_4 -> V_72 , V_109 , V_62 ) ;
if ( V_255 <= 0 ) {
F_78 ( V_151 -> V_153 ) ;
F_117 ( V_148 , V_255 ) ;
F_56 ( V_86 ) ;
continue;
}
V_58 = F_114 ( V_255 ) ;
if ( ! V_58 ) {
F_78 ( V_151 -> V_153 ) ;
F_117 ( V_148 , - V_21 ) ;
F_56 ( V_86 ) ;
continue;
}
do {
F_10 ( L_29 , V_148 -> V_113 -> V_262 ) ;
V_254 = F_59 ( V_4 , V_109 , V_62 ) ;
F_29 ( & V_58 -> V_24 ) ;
V_113 = F_69 ( & V_251 , & V_252 , & V_127 ,
V_254 , V_249 ) ;
if ( ! V_113 ) {
F_76 ( V_148 , V_58 , V_256 ,
- V_21 , V_254 ) ;
goto V_263;
}
if ( V_253 )
F_102 ( V_148 , V_4 ,
V_86 ,
V_109 ,
V_254 , V_113 ,
V_58 , V_256 ) ;
else
F_103 ( V_148 , V_4 ,
V_4 -> V_11 . V_96 ,
V_109 ,
V_254 , V_113 ,
V_58 , V_256 ) ;
V_263:
V_62 -= V_254 ;
V_109 += V_254 ;
V_256 ++ ;
V_251 = V_252 ;
} while ( V_62 > 0 );
F_42 ( & V_58 -> V_24 , F_43 ) ;
if ( V_127 )
F_70 ( V_127 ) ;
F_78 ( V_151 -> V_153 ) ;
F_56 ( V_86 ) ;
}
}
static int F_124 ( struct V_150 * V_151 , struct V_264 * V_265 ,
struct V_118 * V_266 )
{
struct V_3 * V_4 = V_151 -> V_250 ;
unsigned int V_267 ;
T_8 V_268 ;
unsigned int V_269 ;
int F_66 ;
V_267 = 1 << ( V_4 -> V_72 . V_82 - V_270 ) ;
V_268 = V_265 -> V_271 + F_125 ( V_265 -> V_140 ) ;
V_269 = V_265 -> V_136 >> V_270 ;
F_66 = ( V_267 - ( ( V_268 & ( V_267 - 1 ) )
+ V_269 ) ) << V_270 ;
if ( F_66 < 0 )
F_66 = 0 ;
if ( F_66 <= V_266 -> V_122 && V_269 == 0 )
return V_266 -> V_122 ;
return F_66 ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
if ( ! V_15 )
return;
if ( V_15 -> V_35 & V_272 )
F_127 ( V_15 ) ;
if ( V_15 -> V_273 )
F_128 ( V_15 -> V_273 ) ;
F_129 ( V_15 ) ;
}
static struct V_60 *
F_130 ( struct V_3 * V_4 , V_69 * V_199 )
{
struct V_60 * V_61 = NULL ;
T_4 V_63 = 0 ;
V_69 V_274 = 0 ;
T_4 V_275 ;
int V_20 ;
do {
T_3 V_62 ;
F_23 ( V_61 ) ;
V_62 = sizeof ( * V_61 ) ;
V_62 += V_63 * sizeof ( struct V_276 ) ;
V_62 += V_274 ;
V_61 = F_11 ( V_62 , V_22 ) ;
if ( ! V_61 )
return F_25 ( - V_21 ) ;
V_20 = F_104 ( V_4 , V_99 ,
V_4 -> V_221 ,
0 , V_62 ,
( char * ) V_61 , V_199 ) ;
if ( V_20 < 0 )
goto V_30;
if ( F_50 ( ( T_3 ) V_20 < V_62 ) ) {
V_20 = - V_261 ;
F_108 ( L_30
L_31 ,
V_4 -> V_277 , V_62 , V_20 ) ;
goto V_30;
}
if ( ! F_45 ( V_61 ) ) {
V_20 = - V_261 ;
F_108 ( L_32 ,
V_4 -> V_277 ) ;
goto V_30;
}
V_274 = F_47 ( V_61 -> V_70 ) ;
V_275 = V_63 ;
V_63 = F_46 ( V_61 -> V_63 ) ;
} while ( V_63 != V_275 );
return V_61 ;
V_30:
F_23 ( V_61 ) ;
return F_25 ( V_20 ) ;
}
static int F_131 ( struct V_3 * V_4 ,
struct V_71 * V_72 )
{
struct V_60 * V_61 ;
V_69 V_170 = 0 ;
int V_20 ;
V_61 = F_130 ( V_4 , & V_170 ) ;
if ( F_16 ( V_61 ) )
return F_37 ( V_61 ) ;
V_20 = F_48 ( V_72 , V_61 ) ;
if ( V_20 >= 0 )
V_72 -> V_229 = V_170 ;
F_23 ( V_61 ) ;
return V_20 ;
}
static void F_132 ( struct V_3 * V_4 )
{
struct V_93 * V_94 ;
struct V_93 * V_125 ;
F_133 (snap, next, &rbd_dev->snaps, node)
F_134 ( V_94 ) ;
}
static int F_135 ( struct V_3 * V_4 , V_69 * V_223 )
{
int V_20 ;
struct V_71 V_278 ;
V_20 = F_131 ( V_4 , & V_278 ) ;
if ( V_20 < 0 )
return V_20 ;
F_136 ( & V_4 -> V_260 ) ;
if ( V_4 -> V_11 . V_96 == V_99 ) {
T_8 V_62 = ( T_8 ) V_278 . V_80 / V_137 ;
if ( V_62 != ( T_8 ) V_4 -> V_11 . V_62 ) {
F_10 ( L_33 ,
( unsigned long long ) V_62 ) ;
V_4 -> V_11 . V_62 = ( V_69 ) V_62 ;
F_137 ( V_4 -> V_15 , V_62 ) ;
}
}
F_23 ( V_4 -> V_72 . V_79 ) ;
F_23 ( V_4 -> V_72 . V_77 ) ;
F_56 ( V_4 -> V_72 . V_86 ) ;
if ( V_223 )
* V_223 = V_278 . V_229 ;
V_4 -> V_72 . V_229 = V_278 . V_229 ;
V_4 -> V_72 . V_80 = V_278 . V_80 ;
V_4 -> V_72 . V_86 = V_278 . V_86 ;
V_4 -> V_72 . V_77 = V_278 . V_77 ;
V_4 -> V_72 . V_79 = V_278 . V_79 ;
F_50 ( strcmp ( V_4 -> V_72 . V_75 , V_278 . V_75 ) ) ;
F_23 ( V_278 . V_75 ) ;
V_20 = F_138 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_139 ( V_4 ) ;
F_140 ( & V_4 -> V_260 ) ;
return V_20 ;
}
static int F_107 ( struct V_3 * V_4 , V_69 * V_223 )
{
int V_20 ;
F_14 ( & V_26 , V_27 ) ;
V_20 = F_135 ( V_4 , V_223 ) ;
F_21 ( & V_26 ) ;
return V_20 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_150 * V_151 ;
V_69 V_106 ;
V_15 = F_142 ( V_279 ) ;
if ( ! V_15 )
return - V_21 ;
snprintf ( V_15 -> V_280 , sizeof( V_15 -> V_280 ) , V_224 L_34 ,
V_4 -> V_281 ) ;
V_15 -> V_225 = V_4 -> V_225 ;
V_15 -> V_282 = 0 ;
V_15 -> V_283 = & V_284 ;
V_15 -> V_9 = V_4 ;
V_151 = F_143 ( F_115 , & V_4 -> V_285 ) ;
if ( ! V_151 )
goto V_286;
F_144 ( V_151 , V_137 ) ;
V_106 = F_61 ( & V_4 -> V_72 ) ;
F_145 ( V_151 , V_106 / V_137 ) ;
F_146 ( V_151 , V_106 ) ;
F_147 ( V_151 , V_106 ) ;
F_148 ( V_151 , V_106 ) ;
F_149 ( V_151 , F_124 ) ;
V_15 -> V_273 = V_151 ;
V_151 -> V_250 = V_4 ;
V_4 -> V_15 = V_15 ;
F_137 ( V_4 -> V_15 , V_4 -> V_11 . V_62 / V_137 ) ;
return 0 ;
V_286:
F_129 ( V_15 ) ;
return - V_21 ;
}
static struct V_3 * F_150 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , struct V_3 , V_2 ) ;
}
static T_9 F_151 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
T_8 V_62 ;
F_121 ( & V_4 -> V_260 ) ;
V_62 = F_152 ( V_4 -> V_15 ) ;
F_122 ( & V_4 -> V_260 ) ;
return sprintf ( V_120 , L_35 , ( unsigned long long ) V_62 * V_137 ) ;
}
static T_9 F_153 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_36 ,
( unsigned long long ) V_4 -> V_11 . V_81 ) ;
}
static T_9 F_154 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_37 , V_4 -> V_225 ) ;
}
static T_9 F_155 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_38 ,
F_156 ( V_4 -> V_16 -> V_28 ) ) ;
}
static T_9 F_157 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_39 , V_4 -> V_289 ) ;
}
static T_9 F_158 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_37 , V_4 -> V_196 ) ;
}
static T_9 F_159 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_39 , V_4 -> V_277 ) ;
}
static T_9 F_160 ( struct V_1 * V_2 ,
struct V_287 * V_288 , char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_39 , V_4 -> V_290 ) ;
}
static T_9 F_161 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
char * V_120 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
return sprintf ( V_120 , L_39 , V_4 -> V_11 . V_92 ) ;
}
static T_9 F_162 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
const char * V_120 ,
T_3 V_62 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
int V_20 ;
V_20 = F_107 ( V_4 , NULL ) ;
return V_20 < 0 ? V_20 : V_62 ;
}
static void F_163 ( struct V_1 * V_2 )
{
}
static T_9 F_164 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
char * V_120 )
{
struct V_93 * V_94 = F_39 ( V_2 , struct V_93 , V_2 ) ;
return sprintf ( V_120 , L_35 , ( unsigned long long ) V_94 -> V_62 ) ;
}
static T_9 F_165 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
char * V_120 )
{
struct V_93 * V_94 = F_39 ( V_2 , struct V_93 , V_2 ) ;
return sprintf ( V_120 , L_35 , ( unsigned long long ) V_94 -> V_91 ) ;
}
static T_9 F_166 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
char * V_120 )
{
struct V_93 * V_94 = F_39 ( V_2 , struct V_93 , V_2 ) ;
return sprintf ( V_120 , L_36 ,
( unsigned long long ) V_94 -> V_81 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_39 ( V_2 , struct V_93 , V_2 ) ;
F_23 ( V_94 -> V_95 ) ;
F_23 ( V_94 ) ;
}
static bool F_168 ( struct V_93 * V_94 )
{
bool V_20 = V_94 -> V_2 . type == & V_291 ;
bool V_292 = F_169 ( & V_94 -> V_2 ) ;
F_34 ( ! V_20 ^ V_292 ) ;
return V_20 ;
}
static void F_134 ( struct V_93 * V_94 )
{
F_40 ( & V_94 -> V_25 ) ;
if ( F_169 ( & V_94 -> V_2 ) )
F_170 ( & V_94 -> V_2 ) ;
}
static int F_171 ( struct V_93 * V_94 ,
struct V_1 * V_293 )
{
struct V_1 * V_2 = & V_94 -> V_2 ;
int V_20 ;
V_2 -> type = & V_291 ;
V_2 -> V_293 = V_293 ;
V_2 -> V_294 = F_167 ;
F_172 ( V_2 , L_40 , V_94 -> V_95 ) ;
F_10 ( L_41 , V_295 , V_94 -> V_95 ) ;
V_20 = F_173 ( V_2 ) ;
return V_20 ;
}
static struct V_93 * F_174 ( struct V_3 * V_4 ,
const char * V_92 ,
V_69 V_96 , V_69 V_296 ,
V_69 V_297 )
{
struct V_93 * V_94 ;
int V_20 ;
V_94 = F_51 ( sizeof ( * V_94 ) , V_22 ) ;
if ( ! V_94 )
return F_25 ( - V_21 ) ;
V_20 = - V_21 ;
V_94 -> V_95 = F_175 ( V_92 , V_22 ) ;
if ( ! V_94 -> V_95 )
goto V_298;
V_94 -> V_91 = V_96 ;
V_94 -> V_62 = V_296 ;
V_94 -> V_81 = V_297 ;
return V_94 ;
V_298:
F_23 ( V_94 -> V_95 ) ;
F_23 ( V_94 ) ;
return F_25 ( V_20 ) ;
}
static char * F_176 ( struct V_3 * V_4 , T_4 V_299 ,
V_69 * V_296 , V_69 * V_297 )
{
char * V_92 ;
F_34 ( V_299 < V_4 -> V_72 . V_86 -> V_90 ) ;
* V_296 = V_4 -> V_72 . V_79 [ V_299 ] ;
* V_297 = 0 ;
V_92 = V_4 -> V_72 . V_77 ;
while ( V_299 -- )
V_92 += strlen ( V_92 ) + 1 ;
return V_92 ;
}
static int F_177 ( struct V_3 * V_4 , V_69 V_96 ,
T_7 * V_83 , V_69 * V_296 )
{
V_68 V_161 = F_85 ( V_96 ) ;
int V_20 ;
struct {
T_7 V_83 ;
V_68 V_62 ;
} V_300 ( ( V_301 ) ) V_302 = { 0 } ;
V_20 = F_113 ( V_4 , V_4 -> V_221 ,
L_42 , L_43 ,
( char * ) & V_161 , sizeof ( V_161 ) ,
( char * ) & V_302 , sizeof ( V_302 ) ,
V_209 , NULL ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_83 = V_302 . V_83 ;
* V_296 = F_47 ( V_302 . V_62 ) ;
F_10 ( L_45 ,
( unsigned long long ) V_96 , ( unsigned int ) * V_83 ,
( unsigned long long ) * V_296 ) ;
return 0 ;
}
static int F_178 ( struct V_3 * V_4 )
{
return F_177 ( V_4 , V_99 ,
& V_4 -> V_72 . V_82 ,
& V_4 -> V_72 . V_80 ) ;
}
static int F_179 ( struct V_3 * V_4 )
{
void * V_303 ;
int V_20 ;
void * V_304 ;
V_303 = F_51 ( V_305 , V_22 ) ;
if ( ! V_303 )
return - V_21 ;
V_20 = F_113 ( V_4 , V_4 -> V_221 ,
L_42 , L_46 ,
NULL , 0 ,
V_303 , V_305 ,
V_209 , NULL ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
goto V_306;
V_304 = V_303 ;
V_4 -> V_72 . V_75 = F_180 ( & V_304 ,
V_304 + V_305 ,
NULL , V_105 ) ;
if ( F_16 ( V_4 -> V_72 . V_75 ) ) {
V_20 = F_37 ( V_4 -> V_72 . V_75 ) ;
V_4 -> V_72 . V_75 = NULL ;
} else {
F_10 ( L_47 , V_4 -> V_72 . V_75 ) ;
}
V_306:
F_23 ( V_303 ) ;
return V_20 ;
}
static int F_181 ( struct V_3 * V_4 , V_69 V_96 ,
V_69 * V_297 )
{
V_68 V_161 = F_85 ( V_96 ) ;
struct {
V_68 V_81 ;
V_68 V_307 ;
} V_308 = { 0 } ;
int V_20 ;
V_20 = F_113 ( V_4 , V_4 -> V_221 ,
L_42 , L_48 ,
( char * ) & V_161 , sizeof ( V_161 ) ,
( char * ) & V_308 , sizeof ( V_308 ) ,
V_209 , NULL ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_297 = F_47 ( V_308 . V_81 ) ;
F_10 ( L_49 ,
( unsigned long long ) V_96 ,
( unsigned long long ) * V_297 ,
( unsigned long long ) F_47 ( V_308 . V_307 ) ) ;
return 0 ;
}
static int F_182 ( struct V_3 * V_4 )
{
return F_181 ( V_4 , V_99 ,
& V_4 -> V_72 . V_81 ) ;
}
static int F_183 ( struct V_3 * V_4 , V_69 * V_170 )
{
T_3 V_62 ;
int V_20 ;
void * V_303 ;
void * V_304 ;
void * V_309 ;
V_69 V_88 ;
T_4 V_63 ;
struct V_67 * V_86 ;
T_4 V_74 ;
V_62 = sizeof ( V_68 ) + sizeof ( V_310 ) +
V_311 * sizeof ( V_68 ) ;
V_303 = F_51 ( V_62 , V_22 ) ;
if ( ! V_303 )
return - V_21 ;
V_20 = F_113 ( V_4 , V_4 -> V_221 ,
L_42 , L_50 ,
NULL , 0 ,
V_303 , V_62 ,
V_209 , V_170 ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
goto V_306;
V_20 = - V_112 ;
V_304 = V_303 ;
V_309 = ( char * ) V_303 + V_62 ;
F_184 ( & V_304 , V_309 , V_88 , V_306 ) ;
F_185 ( & V_304 , V_309 , V_63 , V_306 ) ;
if ( V_63 > ( V_66 - sizeof ( struct V_67 ) )
/ sizeof ( V_69 ) ) {
V_20 = - V_46 ;
goto V_306;
}
if ( ! F_186 ( & V_304 , V_309 , V_63 * sizeof ( V_68 ) ) )
goto V_306;
V_62 = sizeof ( struct V_67 ) +
V_63 * sizeof ( V_86 -> V_78 [ 0 ] ) ;
V_86 = F_11 ( V_62 , V_22 ) ;
if ( ! V_86 ) {
V_20 = - V_21 ;
goto V_306;
}
F_52 ( & V_86 -> V_87 , 1 ) ;
V_86 -> V_88 = V_88 ;
V_86 -> V_90 = V_63 ;
for ( V_74 = 0 ; V_74 < V_63 ; V_74 ++ )
V_86 -> V_78 [ V_74 ] = F_187 ( & V_304 ) ;
V_4 -> V_72 . V_86 = V_86 ;
F_10 ( L_51 ,
( unsigned long long ) V_88 , ( unsigned int ) V_63 ) ;
V_306:
F_23 ( V_303 ) ;
return 0 ;
}
static char * F_188 ( struct V_3 * V_4 , T_4 V_299 )
{
T_3 V_62 ;
void * V_303 ;
V_68 V_96 ;
int V_20 ;
void * V_304 ;
void * V_309 ;
T_3 V_312 ;
char * V_92 ;
V_62 = sizeof ( V_310 ) + V_313 ;
V_303 = F_11 ( V_62 , V_22 ) ;
if ( ! V_303 )
return F_25 ( - V_21 ) ;
V_96 = F_85 ( V_4 -> V_72 . V_86 -> V_78 [ V_299 ] ) ;
V_20 = F_113 ( V_4 , V_4 -> V_221 ,
L_42 , L_52 ,
( char * ) & V_96 , sizeof ( V_96 ) ,
V_303 , V_62 ,
V_209 , NULL ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
goto V_306;
V_304 = V_303 ;
V_309 = ( char * ) V_303 + V_62 ;
V_312 = 0 ;
V_92 = F_180 ( & V_304 , V_309 , & V_312 ,
V_22 ) ;
if ( F_16 ( V_92 ) ) {
V_20 = F_37 ( V_92 ) ;
goto V_306;
} else {
F_10 ( L_53 ,
( unsigned long long ) F_47 ( V_96 ) , V_92 ) ;
}
F_23 ( V_303 ) ;
return V_92 ;
V_306:
F_23 ( V_303 ) ;
return F_25 ( V_20 ) ;
}
static char * F_189 ( struct V_3 * V_4 , T_4 V_299 ,
V_69 * V_296 , V_69 * V_297 )
{
V_68 V_96 ;
T_7 V_83 ;
int V_20 ;
V_96 = V_4 -> V_72 . V_86 -> V_78 [ V_299 ] ;
V_20 = F_177 ( V_4 , V_96 , & V_83 , V_296 ) ;
if ( V_20 )
return F_25 ( V_20 ) ;
V_20 = F_181 ( V_4 , V_96 , V_297 ) ;
if ( V_20 )
return F_25 ( V_20 ) ;
return F_188 ( V_4 , V_299 ) ;
}
static char * F_190 ( struct V_3 * V_4 , T_4 V_299 ,
V_69 * V_296 , V_69 * V_297 )
{
if ( V_4 -> V_59 == 1 )
return F_176 ( V_4 , V_299 ,
V_296 , V_297 ) ;
if ( V_4 -> V_59 == 2 )
return F_189 ( V_4 , V_299 ,
V_296 , V_297 ) ;
return F_25 ( - V_46 ) ;
}
static int F_138 ( struct V_3 * V_4 )
{
struct V_67 * V_86 = V_4 -> V_72 . V_86 ;
const T_4 V_63 = V_86 -> V_90 ;
struct V_314 * V_315 = & V_4 -> V_78 ;
struct V_314 * V_316 = V_315 -> V_125 ;
T_4 V_149 = 0 ;
F_10 ( L_54 , V_295 , ( unsigned int ) V_63 ) ;
while ( V_149 < V_63 || V_316 != V_315 ) {
V_69 V_96 ;
struct V_93 * V_94 ;
char * V_92 ;
V_69 V_296 = 0 ;
V_69 V_297 = 0 ;
V_96 = V_149 < V_63 ? V_86 -> V_78 [ V_149 ]
: V_99 ;
V_94 = V_316 != V_315 ? F_191 ( V_316 , struct V_93 , V_25 )
: NULL ;
F_34 ( ! V_94 || V_94 -> V_91 != V_99 ) ;
if ( V_96 == V_99 || ( V_94 && V_94 -> V_91 > V_96 ) ) {
struct V_314 * V_125 = V_316 -> V_125 ;
if ( V_4 -> V_11 . V_96 == V_94 -> V_91 )
V_4 -> V_11 . V_100 = false ;
F_134 ( V_94 ) ;
F_10 ( L_55 ,
V_4 -> V_11 . V_96 == V_94 -> V_91 ?
L_56 : L_57 ,
( unsigned long long ) V_94 -> V_91 ) ;
V_316 = V_125 ;
continue;
}
V_92 = F_190 ( V_4 , V_149 ,
& V_296 , & V_297 ) ;
if ( F_16 ( V_92 ) )
return F_37 ( V_92 ) ;
F_10 ( L_58 , ( unsigned int ) V_63 ,
( unsigned long long ) V_96 ) ;
if ( ! V_94 || ( V_96 != V_99 && V_94 -> V_91 < V_96 ) ) {
struct V_93 * V_317 ;
V_317 = F_174 ( V_4 , V_92 ,
V_96 , V_296 , V_297 ) ;
if ( F_16 ( V_317 ) ) {
int V_298 = F_37 ( V_317 ) ;
F_10 ( L_59 , V_298 ) ;
return V_298 ;
}
F_10 ( L_60 , V_94 ? L_57 : L_61 ) ;
if ( V_94 )
F_19 ( & V_317 -> V_25 , & V_94 -> V_25 ) ;
else
F_19 ( & V_317 -> V_25 , V_315 ) ;
} else {
F_10 ( L_62 ) ;
F_34 ( V_94 -> V_62 == V_296 ) ;
F_34 ( ! strcmp ( V_94 -> V_95 , V_92 ) ) ;
F_34 ( V_94 -> V_81 == V_297 ) ;
V_316 = V_316 -> V_125 ;
}
V_149 ++ ;
}
F_10 ( L_63 , V_295 ) ;
return 0 ;
}
static int F_139 ( struct V_3 * V_4 )
{
struct V_93 * V_94 ;
int V_20 = 0 ;
F_10 ( L_64 , V_295 ) ;
if ( F_50 ( ! F_169 ( & V_4 -> V_2 ) ) )
return - V_76 ;
F_27 (snap, &rbd_dev->snaps, node) {
if ( ! F_168 ( V_94 ) ) {
V_20 = F_171 ( V_94 , & V_4 -> V_2 ) ;
if ( V_20 < 0 )
break;
}
}
F_10 ( L_65 , V_295 , V_20 ) ;
return V_20 ;
}
static int F_192 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_20 ;
F_14 ( & V_26 , V_27 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_318 = & V_319 ;
V_2 -> type = & V_320 ;
V_2 -> V_293 = & V_321 ;
V_2 -> V_294 = V_322 ;
F_172 ( V_2 , L_34 , V_4 -> V_281 ) ;
V_20 = F_173 ( V_2 ) ;
F_21 ( & V_26 ) ;
return V_20 ;
}
static void F_193 ( struct V_3 * V_4 )
{
F_170 ( & V_4 -> V_2 ) ;
}
static int F_194 ( struct V_3 * V_4 )
{
int V_20 , V_155 ;
do {
V_20 = F_109 ( V_4 ) ;
if ( V_20 == - V_112 ) {
V_155 = F_107 ( V_4 , NULL ) ;
if ( V_155 < 0 )
return V_155 ;
}
} while ( V_20 == - V_112 );
return V_20 ;
}
static void F_195 ( struct V_3 * V_4 )
{
V_4 -> V_281 = F_196 ( & V_323 ) ;
F_18 ( & V_324 ) ;
F_19 ( & V_4 -> V_25 , & V_325 ) ;
F_20 ( & V_324 ) ;
F_10 ( L_66 , V_4 ,
( unsigned long long ) V_4 -> V_281 ) ;
}
static void F_197 ( struct V_3 * V_4 )
{
struct V_314 * V_115 ;
int V_326 = V_4 -> V_281 ;
int V_327 ;
F_34 ( V_326 > 0 ) ;
F_10 ( L_67 , V_4 ,
( unsigned long long ) V_4 -> V_281 ) ;
F_18 ( & V_324 ) ;
F_198 ( & V_4 -> V_25 ) ;
if ( V_326 != F_199 ( & V_323 ) ) {
F_20 ( & V_324 ) ;
return;
}
V_327 = 0 ;
F_200 (tmp, &rbd_dev_list) {
struct V_3 * V_4 ;
V_4 = F_191 ( V_115 , struct V_3 , V_25 ) ;
if ( V_326 > V_327 )
V_327 = V_326 ;
}
F_20 ( & V_324 ) ;
F_201 ( & V_323 , V_326 , V_327 ) ;
F_10 ( L_68 ) ;
}
static inline T_3 F_202 ( const char * * V_120 )
{
const char * V_328 = L_69 ;
* V_120 += strspn ( * V_120 , V_328 ) ;
return strcspn ( * V_120 , V_328 ) ;
}
static inline T_3 F_203 ( const char * * V_120 ,
char * V_43 ,
T_3 V_329 )
{
T_3 V_73 ;
V_73 = F_202 ( V_120 ) ;
if ( V_73 < V_329 ) {
memcpy ( V_43 , * V_120 , V_73 ) ;
* ( V_43 + V_73 ) = '\0' ;
}
* V_120 += V_73 ;
return V_73 ;
}
static inline char * F_204 ( const char * * V_120 , T_3 * V_330 )
{
char * V_331 ;
T_3 V_73 ;
V_73 = F_202 ( V_120 ) ;
V_331 = F_11 ( V_73 + 1 , V_22 ) ;
if ( ! V_331 )
return NULL ;
memcpy ( V_331 , * V_120 , V_73 ) ;
* ( V_331 + V_73 ) = '\0' ;
* V_120 += V_73 ;
if ( V_330 )
* V_330 = V_73 ;
return V_331 ;
}
static char * F_205 ( struct V_3 * V_4 ,
const char * V_120 ,
const char * * V_332 ,
T_3 * V_333 ,
char * V_55 ,
T_3 V_334 )
{
T_3 V_73 ;
char * V_335 = F_25 ( - V_46 ) ;
char * V_92 ;
V_73 = F_202 ( & V_120 ) ;
if ( ! V_73 )
return V_335 ;
* V_333 = V_73 + 1 ;
* V_332 = V_120 ;
V_120 += V_73 ;
V_73 = F_203 ( & V_120 , V_55 , V_334 ) ;
if ( ! V_73 || V_73 >= V_334 )
return V_335 ;
V_335 = F_25 ( - V_21 ) ;
V_4 -> V_289 = F_204 ( & V_120 , NULL ) ;
if ( ! V_4 -> V_289 )
goto V_30;
V_4 -> V_277 = F_204 ( & V_120 , & V_4 -> V_336 ) ;
if ( ! V_4 -> V_277 )
goto V_30;
V_73 = F_202 ( & V_120 ) ;
if ( ! V_73 ) {
V_120 = V_98 ;
V_73 = sizeof ( V_98 ) - 1 ;
}
V_92 = F_11 ( V_73 + 1 , V_22 ) ;
if ( ! V_92 )
goto V_30;
memcpy ( V_92 , V_120 , V_73 ) ;
* ( V_92 + V_73 ) = '\0' ;
F_10 ( L_70 , V_92 , V_73 ) ;
return V_92 ;
V_30:
F_23 ( V_4 -> V_277 ) ;
V_4 -> V_277 = NULL ;
V_4 -> V_336 = 0 ;
F_23 ( V_4 -> V_289 ) ;
V_4 -> V_289 = NULL ;
return V_335 ;
}
static int F_206 ( struct V_3 * V_4 )
{
int V_20 ;
T_3 V_62 ;
char * V_162 ;
void * V_337 ;
void * V_304 ;
V_62 = sizeof ( V_338 ) + V_4 -> V_336 ;
V_162 = F_11 ( V_62 , V_105 ) ;
if ( ! V_162 )
return - V_21 ;
sprintf ( V_162 , L_71 , V_338 , V_4 -> V_277 ) ;
F_10 ( L_72 , V_162 ) ;
V_62 = sizeof ( V_310 ) + V_339 ;
V_337 = F_51 ( V_62 , V_105 ) ;
if ( ! V_337 ) {
V_20 = - V_21 ;
goto V_306;
}
V_20 = F_113 ( V_4 , V_162 ,
L_42 , L_73 ,
NULL , 0 ,
V_337 , V_339 ,
V_209 , NULL ) ;
F_10 ( L_44 , V_295 , V_20 ) ;
if ( V_20 < 0 )
goto V_306;
V_304 = V_337 ;
V_4 -> V_290 = F_180 ( & V_304 ,
V_304 + V_339 ,
& V_4 -> V_340 ,
V_105 ) ;
if ( F_16 ( V_4 -> V_290 ) ) {
V_20 = F_37 ( V_4 -> V_290 ) ;
V_4 -> V_290 = NULL ;
} else {
F_10 ( L_74 , V_4 -> V_290 ) ;
}
V_306:
F_23 ( V_337 ) ;
F_23 ( V_162 ) ;
return V_20 ;
}
static int F_207 ( struct V_3 * V_4 )
{
int V_20 ;
T_3 V_62 ;
V_4 -> V_290 = F_175 ( L_57 , V_22 ) ;
if ( ! V_4 -> V_290 )
return - V_21 ;
V_4 -> V_340 = 0 ;
V_62 = V_4 -> V_336 + sizeof ( V_341 ) ;
V_4 -> V_221 = F_11 ( V_62 , V_22 ) ;
if ( ! V_4 -> V_221 ) {
V_20 = - V_21 ;
goto V_30;
}
sprintf ( V_4 -> V_221 , L_71 , V_4 -> V_277 , V_341 ) ;
V_20 = F_131 ( V_4 , & V_4 -> V_72 ) ;
if ( V_20 < 0 )
goto V_30;
V_4 -> V_59 = 1 ;
F_10 ( L_75 ,
V_4 -> V_221 ) ;
return 0 ;
V_30:
F_23 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
F_23 ( V_4 -> V_290 ) ;
V_4 -> V_290 = NULL ;
return V_20 ;
}
static int F_208 ( struct V_3 * V_4 )
{
T_3 V_62 ;
int V_20 ;
V_69 V_170 = 0 ;
V_62 = sizeof ( V_342 ) + V_4 -> V_340 ;
V_4 -> V_221 = F_11 ( V_62 , V_22 ) ;
if ( ! V_4 -> V_221 )
return - V_21 ;
sprintf ( V_4 -> V_221 , L_71 ,
V_342 , V_4 -> V_290 ) ;
V_20 = F_178 ( V_4 ) ;
if ( V_20 < 0 )
goto V_30;
V_20 = F_179 ( V_4 ) ;
if ( V_20 < 0 )
goto V_30;
V_20 = F_182 ( V_4 ) ;
if ( V_20 < 0 )
goto V_30;
V_4 -> V_72 . V_84 = 0 ;
V_4 -> V_72 . V_85 = 0 ;
V_20 = F_183 ( V_4 , & V_170 ) ;
if ( V_20 )
goto V_30;
V_4 -> V_72 . V_229 = V_170 ;
V_4 -> V_59 = 2 ;
F_10 ( L_76 ,
V_4 -> V_221 ) ;
return - V_343 ;
V_30:
F_23 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
F_23 ( V_4 -> V_72 . V_75 ) ;
V_4 -> V_72 . V_75 = NULL ;
return V_20 ;
}
static int F_209 ( struct V_3 * V_4 )
{
int V_20 ;
V_20 = F_206 ( V_4 ) ;
if ( V_20 )
V_20 = F_207 ( V_4 ) ;
else
V_20 = F_208 ( V_4 ) ;
if ( V_20 )
F_10 ( L_77 , V_20 ) ;
return V_20 ;
}
static T_9 F_210 ( struct V_344 * V_318 ,
const char * V_120 ,
T_3 V_345 )
{
char * V_55 ;
struct V_3 * V_4 = NULL ;
const char * V_332 = NULL ;
T_3 V_333 = 0 ;
struct V_180 * V_181 ;
int V_155 = - V_21 ;
char * V_92 ;
if ( ! F_211 ( V_346 ) )
return - V_347 ;
V_55 = F_11 ( V_345 , V_22 ) ;
if ( ! V_55 )
goto V_348;
V_4 = F_51 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
goto V_348;
F_212 ( & V_4 -> V_285 ) ;
F_13 ( & V_4 -> V_25 ) ;
F_13 ( & V_4 -> V_78 ) ;
F_213 ( & V_4 -> V_260 ) ;
V_92 = F_205 ( V_4 , V_120 ,
& V_332 , & V_333 , V_55 , V_345 ) ;
if ( F_16 ( V_92 ) ) {
V_155 = F_37 ( V_92 ) ;
goto V_348;
}
V_155 = F_35 ( V_4 , V_332 , V_333 - 1 , V_55 ) ;
if ( V_155 < 0 )
goto V_349;
V_181 = & V_4 -> V_16 -> V_28 -> V_181 ;
V_155 = F_214 ( V_181 -> V_350 , V_4 -> V_289 ) ;
if ( V_155 < 0 )
goto V_351;
V_4 -> V_196 = V_155 ;
V_155 = F_209 ( V_4 ) ;
if ( V_155 < 0 )
goto V_351;
F_34 ( F_44 ( V_4 -> V_59 ) ) ;
V_155 = F_138 ( V_4 ) ;
if ( V_155 )
goto V_352;
V_155 = F_54 ( V_4 , V_92 ) ;
if ( V_155 )
goto V_352;
F_195 ( V_4 ) ;
F_215 ( V_353
< sizeof ( V_224 ) + V_354 ) ;
sprintf ( V_4 -> V_95 , L_78 , V_224 , V_4 -> V_281 ) ;
V_155 = F_216 ( 0 , V_4 -> V_95 ) ;
if ( V_155 < 0 )
goto V_355;
V_4 -> V_225 = V_155 ;
V_155 = F_141 ( V_4 ) ;
if ( V_155 )
goto V_356;
V_155 = F_192 ( V_4 ) ;
if ( V_155 )
goto V_357;
F_136 ( & V_4 -> V_260 ) ;
V_155 = F_139 ( V_4 ) ;
F_140 ( & V_4 -> V_260 ) ;
if ( V_155 )
goto V_358;
V_155 = F_194 ( V_4 ) ;
if ( V_155 )
goto V_358;
F_217 ( V_4 -> V_15 ) ;
F_218 ( L_79 , V_4 -> V_15 -> V_280 ,
( unsigned long long ) V_4 -> V_11 . V_62 ) ;
return V_345 ;
V_358:
F_193 ( V_4 ) ;
F_23 ( V_55 ) ;
return V_155 ;
V_357:
F_126 ( V_4 ) ;
V_356:
F_219 ( V_4 -> V_225 , V_4 -> V_95 ) ;
V_355:
F_197 ( V_4 ) ;
V_352:
F_55 ( & V_4 -> V_72 ) ;
V_351:
F_23 ( V_4 -> V_221 ) ;
F_41 ( V_4 ) ;
F_23 ( V_4 -> V_290 ) ;
V_349:
F_23 ( V_4 -> V_11 . V_92 ) ;
F_23 ( V_4 -> V_277 ) ;
F_23 ( V_4 -> V_289 ) ;
V_348:
F_23 ( V_4 ) ;
F_23 ( V_55 ) ;
F_10 ( L_80 , V_120 ) ;
F_220 ( V_346 ) ;
return ( T_9 ) V_155 ;
}
static struct V_3 * F_221 ( unsigned long V_281 )
{
struct V_314 * V_115 ;
struct V_3 * V_4 ;
F_18 ( & V_324 ) ;
F_222 (tmp, &rbd_dev_list) {
V_4 = F_191 ( V_115 , struct V_3 , V_25 ) ;
if ( V_4 -> V_281 == V_281 ) {
F_20 ( & V_324 ) ;
return V_4 ;
}
}
F_20 ( & V_324 ) ;
return NULL ;
}
static void V_322 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_150 ( V_2 ) ;
if ( V_4 -> V_230 ) {
struct V_359 * V_28 = V_4 -> V_16 -> V_28 ;
F_223 ( & V_28 -> V_181 ,
V_4 -> V_230 ) ;
}
if ( V_4 -> V_227 )
F_112 ( V_4 ) ;
F_41 ( V_4 ) ;
F_126 ( V_4 ) ;
F_219 ( V_4 -> V_225 , V_4 -> V_95 ) ;
F_55 ( & V_4 -> V_72 ) ;
F_23 ( V_4 -> V_11 . V_92 ) ;
F_23 ( V_4 -> V_290 ) ;
F_23 ( V_4 -> V_221 ) ;
F_23 ( V_4 -> V_289 ) ;
F_23 ( V_4 -> V_277 ) ;
F_197 ( V_4 ) ;
F_23 ( V_4 ) ;
F_220 ( V_346 ) ;
}
static T_9 F_224 ( struct V_344 * V_318 ,
const char * V_120 ,
T_3 V_345 )
{
struct V_3 * V_4 = NULL ;
int V_360 , V_155 ;
unsigned long V_361 ;
int V_20 = V_345 ;
V_155 = F_225 ( V_120 , 10 , & V_361 ) ;
if ( V_155 )
return V_155 ;
V_360 = ( int ) V_361 ;
if ( V_360 != V_361 )
return - V_46 ;
F_14 ( & V_26 , V_27 ) ;
V_4 = F_221 ( V_360 ) ;
if ( ! V_4 ) {
V_20 = - V_97 ;
goto V_101;
}
F_132 ( V_4 ) ;
F_193 ( V_4 ) ;
V_101:
F_21 ( & V_26 ) ;
return V_20 ;
}
static int F_226 ( void )
{
int V_20 ;
V_20 = F_173 ( & V_321 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_227 ( & V_319 ) ;
if ( V_20 < 0 )
F_170 ( & V_321 ) ;
return V_20 ;
}
static void F_228 ( void )
{
F_229 ( & V_319 ) ;
F_170 ( & V_321 ) ;
}
int T_10 F_230 ( void )
{
int V_155 ;
V_155 = F_226 () ;
if ( V_155 )
return V_155 ;
F_218 ( L_81 V_362 L_82 ) ;
return 0 ;
}
void T_11 F_231 ( void )
{
F_228 () ;
}
