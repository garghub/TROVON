static void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
if ( ( V_5 & V_10 ) && V_7 -> V_11 . V_12 )
return - V_13 ;
F_3 ( & V_14 , V_15 ) ;
( void ) F_4 ( & V_7 -> V_2 ) ;
F_5 ( V_4 , V_7 -> V_11 . V_12 ) ;
V_7 -> V_16 ++ ;
F_6 ( & V_14 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 , T_1 V_5 )
{
struct V_6 * V_7 = V_18 -> V_9 ;
F_3 ( & V_14 , V_15 ) ;
F_8 ( V_7 -> V_16 > 0 ) ;
V_7 -> V_16 -- ;
F_9 ( & V_7 -> V_2 ) ;
F_6 ( & V_14 ) ;
return 0 ;
}
static struct V_19 * F_10 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
int V_23 = - V_24 ;
F_11 ( L_1 ) ;
V_22 = F_12 ( sizeof( struct V_19 ) , V_25 ) ;
if ( ! V_22 )
goto V_26;
F_13 ( & V_22 -> V_27 ) ;
F_14 ( & V_22 -> V_28 ) ;
F_3 ( & V_14 , V_15 ) ;
V_22 -> V_29 = F_15 ( V_21 , V_22 , 0 , 0 ) ;
if ( F_16 ( V_22 -> V_29 ) )
goto V_30;
V_21 = NULL ;
V_23 = F_17 ( V_22 -> V_29 ) ;
if ( V_23 < 0 )
goto V_31;
F_18 ( & V_32 ) ;
F_19 ( & V_22 -> V_28 , & V_33 ) ;
F_20 ( & V_32 ) ;
F_6 ( & V_14 ) ;
F_11 ( L_2 , V_22 ) ;
return V_22 ;
V_31:
F_21 ( V_22 -> V_29 ) ;
V_30:
F_6 ( & V_14 ) ;
F_22 ( V_22 ) ;
V_26:
if ( V_21 )
F_23 ( V_21 ) ;
return F_24 ( V_23 ) ;
}
static struct V_19 * F_25 ( struct V_20 * V_21 )
{
struct V_19 * V_34 ;
bool V_35 = false ;
if ( V_21 -> V_36 & V_37 )
return NULL ;
F_18 ( & V_32 ) ;
F_26 (client_node, &rbd_client_list, node) {
if ( ! F_27 ( V_21 , V_34 -> V_29 ) ) {
F_28 ( & V_34 -> V_27 ) ;
V_35 = true ;
break;
}
}
F_20 ( & V_32 ) ;
return V_35 ? V_34 : NULL ;
}
static int F_29 ( char * V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
T_2 V_42 [ V_43 ] ;
int V_44 , V_45 , V_23 ;
V_44 = F_30 ( V_38 , V_46 , V_42 ) ;
if ( V_44 < 0 )
return - V_47 ;
if ( V_44 < V_48 ) {
V_23 = F_31 ( & V_42 [ 0 ] , & V_45 ) ;
if ( V_23 < 0 ) {
F_32 ( L_3
L_4 , V_38 ) ;
return V_23 ;
}
F_11 ( L_5 , V_44 , V_45 ) ;
} else if ( V_44 > V_48 && V_44 < V_49 ) {
F_11 ( L_6 , V_44 ,
V_42 [ 0 ] . V_50 ) ;
} else if ( V_44 > V_49 && V_44 < V_51 ) {
F_11 ( L_7 , V_44 ) ;
} else {
F_11 ( L_8 , V_44 ) ;
}
switch ( V_44 ) {
case V_52 :
V_41 -> V_12 = true ;
break;
case V_53 :
V_41 -> V_12 = false ;
break;
default:
F_8 ( false ) ;
break;
}
return 0 ;
}
static struct V_19 * F_33 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
V_22 = F_25 ( V_21 ) ;
if ( V_22 )
F_23 ( V_21 ) ;
else
V_22 = F_10 ( V_21 ) ;
return V_22 ;
}
static void F_34 ( struct V_27 * V_27 )
{
struct V_19 * V_22 = F_35 ( V_27 , struct V_19 , V_27 ) ;
F_11 ( L_9 , V_22 ) ;
F_18 ( & V_32 ) ;
F_36 ( & V_22 -> V_28 ) ;
F_20 ( & V_32 ) ;
F_21 ( V_22 -> V_29 ) ;
F_22 ( V_22 ) ;
}
static void F_37 ( struct V_19 * V_22 )
{
if ( V_22 )
F_38 ( & V_22 -> V_27 , F_34 ) ;
}
static void F_39 ( struct V_27 * V_27 )
{
struct V_54 * V_55 =
F_35 ( V_27 , struct V_54 , V_27 ) ;
F_11 ( L_10 , V_55 ) ;
F_22 ( V_55 ) ;
}
static bool F_40 ( T_3 V_56 )
{
return V_56 == 1 || V_56 == 2 ;
}
static bool F_41 ( struct V_57 * V_58 )
{
T_4 V_59 ;
T_3 V_60 ;
if ( memcmp ( & V_58 -> V_61 , V_62 , sizeof ( V_62 ) ) )
return false ;
if ( V_58 -> V_63 . V_64 < V_65 )
return false ;
if ( V_58 -> V_63 . V_64 > 8 * sizeof ( int ) - 1 )
return false ;
V_60 = F_42 ( V_58 -> V_60 ) ;
V_59 = V_66 - sizeof ( struct V_67 ) ;
if ( V_60 > V_59 / sizeof ( V_68 ) )
return false ;
V_59 -= V_60 * sizeof ( V_68 ) ;
if ( ( V_69 ) V_59 < F_43 ( V_58 -> V_70 ) )
return false ;
return true ;
}
static int F_44 ( struct V_71 * V_72 ,
struct V_57 * V_58 )
{
T_3 V_60 ;
T_4 V_73 ;
T_4 V_59 ;
T_3 V_74 ;
memset ( V_72 , 0 , sizeof ( * V_72 ) ) ;
V_60 = F_42 ( V_58 -> V_60 ) ;
V_73 = F_45 ( V_58 -> V_75 , sizeof ( V_58 -> V_75 ) ) ;
V_72 -> V_75 = F_12 ( V_73 + 1 , V_25 ) ;
if ( ! V_72 -> V_75 )
return - V_24 ;
memcpy ( V_72 -> V_75 , V_58 -> V_75 , V_73 ) ;
V_72 -> V_75 [ V_73 ] = '\0' ;
if ( V_60 ) {
V_69 V_70 = F_43 ( V_58 -> V_70 ) ;
if ( V_70 > ( V_69 ) V_66 )
return - V_76 ;
V_72 -> V_77 = F_12 ( V_70 , V_25 ) ;
if ( ! V_72 -> V_77 )
goto V_31;
memcpy ( V_72 -> V_77 , & V_58 -> V_78 [ V_60 ] ,
V_70 ) ;
V_59 = V_60 * sizeof ( * V_72 -> V_79 ) ;
V_72 -> V_79 = F_12 ( V_59 , V_25 ) ;
if ( ! V_72 -> V_79 )
goto V_31;
for ( V_74 = 0 ; V_74 < V_60 ; V_74 ++ )
V_72 -> V_79 [ V_74 ] =
F_43 ( V_58 -> V_78 [ V_74 ] . V_80 ) ;
} else {
F_46 ( V_58 -> V_70 ) ;
V_72 -> V_77 = NULL ;
V_72 -> V_79 = NULL ;
}
V_72 -> V_81 = 0 ;
V_72 -> V_82 = V_58 -> V_63 . V_64 ;
V_72 -> V_83 = V_58 -> V_63 . V_83 ;
V_72 -> V_84 = V_58 -> V_63 . V_84 ;
V_72 -> V_80 = F_43 ( V_58 -> V_80 ) ;
V_59 = sizeof ( struct V_67 ) ;
V_59 += V_60 * sizeof ( V_72 -> V_85 -> V_78 [ 0 ] ) ;
V_72 -> V_85 = F_47 ( V_59 , V_25 ) ;
if ( ! V_72 -> V_85 )
goto V_31;
F_48 ( & V_72 -> V_85 -> V_86 , 1 ) ;
V_72 -> V_85 -> V_87 = F_43 ( V_58 -> V_88 ) ;
V_72 -> V_85 -> V_89 = V_60 ;
for ( V_74 = 0 ; V_74 < V_60 ; V_74 ++ )
V_72 -> V_85 -> V_78 [ V_74 ] =
F_43 ( V_58 -> V_78 [ V_74 ] . V_90 ) ;
return 0 ;
V_31:
F_22 ( V_72 -> V_79 ) ;
V_72 -> V_79 = NULL ;
F_22 ( V_72 -> V_77 ) ;
V_72 -> V_77 = NULL ;
F_22 ( V_72 -> V_75 ) ;
V_72 -> V_75 = NULL ;
return - V_24 ;
}
static const char * F_49 ( struct V_6 * V_7 , V_69 V_91 )
{
struct V_92 * V_93 ;
if ( V_91 == V_94 )
return V_95 ;
F_26 (snap, &rbd_dev->snaps, node)
if ( V_91 == V_93 -> V_90 )
return V_93 -> V_96 ;
return NULL ;
}
static int F_50 ( struct V_6 * V_7 , const char * V_97 )
{
struct V_92 * V_93 ;
F_26 (snap, &rbd_dev->snaps, node) {
if ( ! strcmp ( V_97 , V_93 -> V_96 ) ) {
V_7 -> V_98 -> V_91 = V_93 -> V_90 ;
V_7 -> V_11 . V_59 = V_93 -> V_59 ;
V_7 -> V_11 . V_81 = V_93 -> V_81 ;
return 0 ;
}
}
return - V_99 ;
}
static int F_51 ( struct V_6 * V_7 )
{
int V_23 ;
if ( ! memcmp ( V_7 -> V_98 -> V_97 , V_95 ,
sizeof ( V_95 ) ) ) {
V_7 -> V_98 -> V_91 = V_94 ;
V_7 -> V_11 . V_59 = V_7 -> V_72 . V_80 ;
V_7 -> V_11 . V_81 = V_7 -> V_72 . V_81 ;
V_23 = 0 ;
} else {
V_23 = F_50 ( V_7 , V_7 -> V_98 -> V_97 ) ;
if ( V_23 < 0 )
goto V_100;
V_7 -> V_11 . V_12 = true ;
}
V_7 -> V_101 = true ;
V_100:
return V_23 ;
}
static void F_52 ( struct V_71 * V_72 )
{
F_22 ( V_72 -> V_75 ) ;
V_72 -> V_75 = NULL ;
F_22 ( V_72 -> V_79 ) ;
V_72 -> V_79 = NULL ;
F_22 ( V_72 -> V_77 ) ;
V_72 -> V_77 = NULL ;
F_53 ( V_72 -> V_85 ) ;
V_72 -> V_85 = NULL ;
}
static char * F_54 ( struct V_6 * V_7 , V_69 V_102 )
{
char * V_96 ;
V_69 V_103 ;
int V_23 ;
V_96 = F_12 ( V_104 + 1 , V_105 ) ;
if ( ! V_96 )
return NULL ;
V_103 = V_102 >> V_7 -> V_72 . V_82 ;
V_23 = snprintf ( V_96 , V_104 + 1 , L_11 ,
V_7 -> V_72 . V_75 , V_103 ) ;
if ( V_23 < 0 || V_23 > V_104 ) {
F_32 ( L_12 ,
V_103 , V_23 ) ;
F_22 ( V_96 ) ;
V_96 = NULL ;
}
return V_96 ;
}
static V_69 F_55 ( struct V_6 * V_7 , V_69 V_102 )
{
V_69 V_106 = ( V_69 ) 1 << V_7 -> V_72 . V_82 ;
return V_102 & ( V_106 - 1 ) ;
}
static V_69 F_56 ( struct V_6 * V_7 ,
V_69 V_102 , V_69 V_107 )
{
V_69 V_106 = ( V_69 ) 1 << V_7 -> V_72 . V_82 ;
V_102 &= V_106 - 1 ;
F_8 ( V_107 <= V_108 - V_102 ) ;
if ( V_102 + V_107 > V_106 )
V_107 = V_106 - V_102 ;
return V_107 ;
}
static int F_57 ( struct V_71 * V_72 ,
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
static V_69 F_58 ( struct V_71 * V_72 )
{
return 1 << V_72 -> V_82 ;
}
static void F_59 ( struct V_113 * V_114 )
{
struct V_113 * V_115 ;
while ( V_114 ) {
V_115 = V_114 ;
V_114 = V_114 -> V_116 ;
F_60 ( V_115 ) ;
}
}
static void F_61 ( struct V_113 * V_114 , int V_117 )
{
struct V_118 * V_119 ;
unsigned long V_36 ;
void * V_120 ;
int V_74 ;
int V_121 = 0 ;
while ( V_114 ) {
F_62 (bv, chain, i) {
if ( V_121 + V_119 -> V_122 > V_117 ) {
int V_123 = F_63 ( V_117 - V_121 , 0 ) ;
V_120 = F_64 ( V_119 , & V_36 ) ;
memset ( V_120 + V_123 , 0 ,
V_119 -> V_122 - V_123 ) ;
F_65 ( V_120 , & V_36 ) ;
}
V_121 += V_119 -> V_122 ;
}
V_114 = V_114 -> V_116 ;
}
}
static struct V_113 * F_66 ( struct V_113 * V_124 ,
unsigned int V_102 ,
unsigned int V_73 ,
T_5 V_125 )
{
struct V_118 * V_119 ;
unsigned int V_126 ;
unsigned short V_127 ;
unsigned int V_128 ;
unsigned short V_129 ;
unsigned short V_130 ;
struct V_113 * V_113 ;
if ( ! V_102 && V_73 == V_124 -> V_131 )
return F_67 ( V_124 , V_125 ) ;
if ( F_68 ( ! V_73 ) )
return NULL ;
if ( F_68 ( V_73 > V_124 -> V_131 ) )
return NULL ;
if ( F_68 ( V_102 > V_124 -> V_131 - V_73 ) )
return NULL ;
V_126 = V_102 ;
F_69 (bv, bio_src, idx, 0 ) {
if ( V_126 < V_119 -> V_122 )
break;
V_126 -= V_119 -> V_122 ;
}
V_128 = V_126 ;
V_126 += V_73 ;
F_69 (bv, bio_src, end_idx, idx) {
if ( V_126 <= V_119 -> V_122 )
break;
V_126 -= V_119 -> V_122 ;
}
V_130 = V_129 - V_127 + 1 ;
V_113 = F_70 ( V_125 , ( unsigned int ) V_130 ) ;
if ( ! V_113 )
return NULL ;
V_113 -> V_132 = V_124 -> V_132 ;
V_113 -> V_133 = V_124 -> V_133 + ( V_102 >> V_65 ) ;
V_113 -> V_134 = V_124 -> V_134 ;
V_113 -> V_135 |= 1 << V_136 ;
memcpy ( & V_113 -> V_137 [ 0 ] , & V_124 -> V_137 [ V_127 ] ,
V_130 * sizeof ( struct V_118 ) ) ;
V_113 -> V_137 [ 0 ] . V_138 += V_128 ;
if ( V_130 > 1 ) {
V_113 -> V_137 [ 0 ] . V_122 -= V_128 ;
V_113 -> V_137 [ V_130 - 1 ] . V_122 = V_126 ;
} else {
V_113 -> V_137 [ 0 ] . V_122 = V_73 ;
}
V_113 -> V_139 = V_130 ;
V_113 -> V_131 = V_73 ;
V_113 -> V_140 = 0 ;
return V_113 ;
}
static struct V_113 * F_71 ( struct V_113 * * V_124 ,
unsigned int * V_102 ,
unsigned int V_73 ,
T_5 V_125 )
{
struct V_113 * V_141 = * V_124 ;
unsigned int V_142 = * V_102 ;
struct V_113 * V_114 = NULL ;
struct V_113 * * V_143 ;
if ( ! V_141 || V_142 >= V_141 -> V_131 || ! V_73 )
return NULL ;
V_143 = & V_114 ;
while ( V_73 ) {
unsigned int V_131 ;
struct V_113 * V_113 ;
if ( ! V_141 )
goto V_31;
V_131 = F_72 (unsigned int, bi->bi_size - off, len) ;
V_113 = F_66 ( V_141 , V_142 , V_131 , V_125 ) ;
if ( ! V_113 )
goto V_31;
* V_143 = V_113 ;
V_143 = & V_113 -> V_116 ;
V_142 += V_131 ;
if ( V_142 == V_141 -> V_131 ) {
V_141 = V_141 -> V_116 ;
V_142 = 0 ;
}
V_73 -= V_131 ;
}
* V_124 = V_141 ;
* V_102 = V_142 ;
return V_114 ;
V_31:
F_59 ( V_114 ) ;
return NULL ;
}
static struct V_144 * F_73 ( int V_145 ,
int V_146 , T_3 V_147 )
{
struct V_144 * V_148 ;
V_148 = F_47 ( sizeof ( * V_148 ) * ( V_145 + 1 ) , V_105 ) ;
if ( ! V_148 )
return NULL ;
V_148 [ 0 ] . V_149 = V_146 ;
V_148 [ 0 ] . V_147 = V_147 ;
return V_148 ;
}
static void F_74 ( struct V_144 * V_148 )
{
F_22 ( V_148 ) ;
}
static void F_75 ( struct V_150 * V_151 ,
struct V_54 * V_55 ,
int V_152 ,
int V_23 , V_69 V_73 )
{
struct V_153 * V_154 ;
int V_155 , F_63 , V_74 ;
F_11 ( L_13 ,
V_55 , V_152 , V_23 , ( unsigned long long ) V_73 ) ;
if ( ! V_151 )
return;
if ( ! V_55 ) {
F_76 ( V_151 , V_23 , V_73 ) ;
return;
}
V_154 = V_151 -> V_154 ;
F_77 ( V_154 -> V_156 ) ;
V_55 -> V_157 [ V_152 ] . V_100 = 1 ;
V_55 -> V_157 [ V_152 ] . V_158 = V_23 ;
V_55 -> V_157 [ V_152 ] . V_159 = V_73 ;
F_63 = V_155 = V_55 -> V_160 ;
while ( F_63 < V_55 -> V_161 && V_55 -> V_157 [ F_63 ] . V_100 )
F_63 ++ ;
for ( V_74 = V_155 ; V_74 < F_63 ; V_74 ++ ) {
F_78 ( V_151 , V_55 -> V_157 [ V_74 ] . V_158 ,
V_55 -> V_157 [ V_74 ] . V_159 ) ;
V_55 -> V_160 ++ ;
F_38 ( & V_55 -> V_27 , F_39 ) ;
}
F_79 ( V_154 -> V_156 ) ;
}
static void F_80 ( struct V_162 * V_163 ,
int V_23 , V_69 V_73 )
{
F_75 ( V_163 -> V_151 , V_163 -> V_55 , V_163 -> V_164 , V_23 , V_73 ) ;
}
static int F_81 ( struct V_150 * V_151 ,
struct V_6 * V_7 ,
struct V_67 * V_85 ,
V_69 V_165 ,
const char * V_166 , V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_167 * * V_168 ,
int V_169 ,
int V_36 ,
struct V_144 * V_148 ,
struct V_54 * V_55 ,
int V_164 ,
void (* F_82)( struct V_170 * V_163 ,
struct V_171 * V_172 ) ,
struct V_170 * * V_173 ,
V_69 * V_174 )
{
struct V_170 * V_163 ;
struct V_175 * V_176 ;
int V_23 ;
V_69 V_177 ;
struct V_178 V_179 = V_180 ;
struct V_162 * V_181 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
V_181 = F_47 ( sizeof( * V_181 ) , V_105 ) ;
if ( ! V_181 ) {
if ( V_55 )
F_75 ( V_151 , V_55 , V_164 ,
- V_24 , V_73 ) ;
return - V_24 ;
}
if ( V_55 ) {
V_181 -> V_55 = V_55 ;
V_181 -> V_164 = V_164 ;
}
F_11 ( L_14 ,
V_166 , ( unsigned long long ) V_109 ,
( unsigned long long ) V_73 , V_55 , V_164 ) ;
V_185 = & V_7 -> V_19 -> V_29 -> V_185 ;
V_163 = F_83 ( V_185 , V_36 , V_85 , V_148 ,
false , V_105 , V_168 , V_113 ) ;
if ( ! V_163 ) {
V_23 = - V_24 ;
goto V_186;
}
V_163 -> V_187 = F_82 ;
V_181 -> V_151 = V_151 ;
V_181 -> V_113 = V_113 ;
V_181 -> V_168 = V_168 ;
V_181 -> V_73 = V_73 ;
V_163 -> V_188 = V_181 ;
V_183 = V_163 -> V_189 -> V_190 . V_191 ;
V_183 -> V_165 = F_84 ( V_94 ) ;
strncpy ( V_163 -> V_192 , V_166 , sizeof( V_163 -> V_192 ) ) ;
V_163 -> V_193 = strlen ( V_163 -> V_192 ) ;
V_176 = & V_163 -> V_194 ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_195 = F_85 ( 1 << V_196 ) ;
V_176 -> V_197 = F_85 ( 1 ) ;
V_176 -> V_198 = F_85 ( 1 << V_196 ) ;
V_176 -> V_199 = F_85 ( ( int ) V_7 -> V_98 -> V_200 ) ;
V_23 = F_86 ( V_185 , V_176 , V_165 , V_109 , & V_73 , & V_177 ,
V_163 , V_148 ) ;
F_8 ( V_23 == 0 ) ;
F_87 ( V_163 , V_109 , & V_73 ,
V_148 ,
V_85 ,
& V_179 ,
V_163 -> V_192 , V_163 -> V_193 ) ;
if ( V_173 ) {
F_88 ( V_185 , V_163 ) ;
* V_173 = V_163 ;
}
V_23 = F_89 ( V_185 , V_163 , false ) ;
if ( V_23 < 0 )
goto V_201;
if ( ! F_82 ) {
V_23 = F_90 ( V_185 , V_163 ) ;
if ( V_174 )
* V_174 = F_43 ( V_163 -> V_202 . V_203 ) ;
F_11 ( L_15 ,
( unsigned long long )
F_43 ( V_163 -> V_202 . V_203 ) ) ;
F_91 ( V_163 ) ;
}
return V_23 ;
V_201:
F_59 ( V_181 -> V_113 ) ;
F_91 ( V_163 ) ;
V_186:
F_80 ( V_181 , V_23 , V_73 ) ;
F_22 ( V_181 ) ;
return V_23 ;
}
static void F_92 ( struct V_170 * V_163 , struct V_171 * V_172 )
{
struct V_162 * V_181 = V_163 -> V_188 ;
struct V_204 * V_205 ;
struct V_206 * V_149 ;
T_6 V_158 ;
V_69 V_159 ;
int V_207 ;
V_205 = V_172 -> V_190 . V_191 ;
F_46 ( F_42 ( V_205 -> V_145 ) == 0 ) ;
V_149 = ( void * ) ( V_205 + 1 ) ;
V_158 = F_42 ( V_205 -> V_208 ) ;
V_159 = F_43 ( V_149 -> V_209 . V_107 ) ;
V_207 = ( F_93 ( V_149 -> V_149 ) == V_210 ) ;
F_11 ( L_16 ,
( unsigned long long ) V_159 , V_207 , ( int ) V_158 ) ;
if ( V_158 == - V_99 && V_207 ) {
F_61 ( V_181 -> V_113 , 0 ) ;
V_158 = 0 ;
} else if ( V_158 == 0 && V_207 && V_159 < V_181 -> V_73 ) {
F_61 ( V_181 -> V_113 , V_159 ) ;
V_159 = V_181 -> V_73 ;
}
F_80 ( V_181 , V_158 , V_159 ) ;
if ( V_181 -> V_113 )
F_59 ( V_181 -> V_113 ) ;
F_91 ( V_163 ) ;
F_22 ( V_181 ) ;
}
static void F_94 ( struct V_170 * V_163 , struct V_171 * V_172 )
{
F_91 ( V_163 ) ;
}
static int F_95 ( struct V_6 * V_7 ,
struct V_67 * V_85 ,
V_69 V_165 ,
int V_36 ,
struct V_144 * V_148 ,
const char * V_166 ,
V_69 V_109 , V_69 V_211 ,
char * V_212 ,
struct V_170 * * V_173 ,
V_69 * V_174 )
{
int V_23 ;
struct V_167 * * V_168 ;
int V_169 ;
F_8 ( V_148 != NULL ) ;
V_169 = F_96 ( V_109 , V_211 ) ;
V_168 = F_97 ( V_169 , V_25 ) ;
if ( F_16 ( V_168 ) )
return F_98 ( V_168 ) ;
V_23 = F_81 ( NULL , V_7 , V_85 , V_165 ,
V_166 , V_109 , V_211 , NULL ,
V_168 , V_169 ,
V_36 ,
V_148 ,
NULL , 0 ,
NULL ,
V_173 , V_174 ) ;
if ( V_23 < 0 )
goto V_100;
if ( ( V_36 & V_213 ) && V_212 )
V_23 = F_99 ( V_168 , V_212 , V_109 , V_23 ) ;
V_100:
F_100 ( V_168 , V_169 ) ;
return V_23 ;
}
static int F_101 ( struct V_150 * V_151 ,
struct V_6 * V_7 ,
struct V_67 * V_85 ,
V_69 V_109 , V_69 V_73 ,
struct V_113 * V_113 ,
struct V_54 * V_55 ,
int V_164 )
{
char * V_214 ;
V_69 V_215 ;
V_69 V_216 ;
int V_23 ;
struct V_144 * V_148 ;
T_3 V_147 ;
int V_146 ;
int V_36 ;
V_69 V_165 ;
V_214 = F_54 ( V_7 , V_109 ) ;
if ( ! V_214 )
return - V_24 ;
V_216 = F_56 ( V_7 , V_109 , V_73 ) ;
V_215 = F_55 ( V_7 , V_109 ) ;
if ( F_102 ( V_151 ) == V_217 ) {
V_146 = V_218 ;
V_36 = V_219 | V_220 ;
V_165 = V_94 ;
V_147 = V_216 ;
} else {
V_146 = V_210 ;
V_36 = V_213 ;
V_85 = NULL ;
V_165 = V_7 -> V_98 -> V_91 ;
V_147 = 0 ;
}
V_23 = - V_24 ;
V_148 = F_73 ( 1 , V_146 , V_147 ) ;
if ( ! V_148 )
goto V_100;
F_8 ( V_216 == V_73 ) ;
V_23 = F_81 ( V_151 , V_7 , V_85 , V_165 ,
V_214 , V_215 , V_216 ,
V_113 ,
NULL , 0 ,
V_36 ,
V_148 ,
V_55 , V_164 ,
F_92 , 0 , NULL ) ;
F_74 ( V_148 ) ;
V_100:
F_22 ( V_214 ) ;
return V_23 ;
}
static int F_103 ( struct V_6 * V_7 ,
V_69 V_165 ,
const char * V_166 ,
V_69 V_109 , V_69 V_73 ,
char * V_120 ,
V_69 * V_174 )
{
struct V_144 * V_148 ;
int V_23 ;
V_148 = F_73 ( 1 , V_210 , 0 ) ;
if ( ! V_148 )
return - V_24 ;
V_23 = F_95 ( V_7 , NULL ,
V_165 ,
V_213 ,
V_148 , V_166 , V_109 , V_73 , V_120 , NULL , V_174 ) ;
F_74 ( V_148 ) ;
return V_23 ;
}
static int F_104 ( struct V_6 * V_7 ,
V_69 V_174 ,
V_69 V_221 )
{
struct V_144 * V_148 ;
int V_23 ;
V_148 = F_73 ( 1 , V_222 , 0 ) ;
if ( ! V_148 )
return - V_24 ;
V_148 [ 0 ] . V_223 . V_174 = F_84 ( V_174 ) ;
V_148 [ 0 ] . V_223 . V_224 = V_221 ;
V_148 [ 0 ] . V_223 . V_225 = 0 ;
V_23 = F_81 ( NULL , V_7 , NULL , V_94 ,
V_7 -> V_226 , 0 , 0 , NULL ,
NULL , 0 ,
V_213 ,
V_148 ,
NULL , 0 ,
F_94 , 0 , NULL ) ;
F_74 ( V_148 ) ;
return V_23 ;
}
static void F_105 ( V_69 V_174 , V_69 V_221 , T_7 V_146 , void * V_227 )
{
struct V_6 * V_7 = (struct V_6 * ) V_227 ;
V_69 V_228 ;
int V_158 ;
if ( ! V_7 )
return;
F_11 ( L_17 ,
V_7 -> V_226 , ( unsigned long long ) V_221 ,
( unsigned int ) V_146 ) ;
V_158 = F_106 ( V_7 , & V_228 ) ;
if ( V_158 )
F_107 ( V_229 L_18
L_19 , V_7 -> V_230 , V_158 ) ;
F_104 ( V_7 , V_228 , V_221 ) ;
}
static int F_108 ( struct V_6 * V_7 )
{
struct V_144 * V_148 ;
struct V_184 * V_185 = & V_7 -> V_19 -> V_29 -> V_185 ;
int V_23 ;
V_148 = F_73 ( 1 , V_231 , 0 ) ;
if ( ! V_148 )
return - V_24 ;
V_23 = F_109 ( V_185 , F_105 , 0 ,
( void * ) V_7 , & V_7 -> V_232 ) ;
if ( V_23 < 0 )
goto V_233;
V_148 [ 0 ] . V_223 . V_174 = F_84 ( V_7 -> V_72 . V_234 ) ;
V_148 [ 0 ] . V_223 . V_224 = F_84 ( V_7 -> V_232 -> V_224 ) ;
V_148 [ 0 ] . V_223 . V_225 = 1 ;
V_23 = F_95 ( V_7 , NULL ,
V_94 ,
V_219 | V_220 ,
V_148 ,
V_7 -> V_226 ,
0 , 0 , NULL ,
& V_7 -> V_235 , NULL ) ;
if ( V_23 < 0 )
goto V_236;
F_74 ( V_148 ) ;
return 0 ;
V_236:
F_110 ( V_7 -> V_232 ) ;
V_7 -> V_232 = NULL ;
V_233:
F_74 ( V_148 ) ;
return V_23 ;
}
static int F_111 ( struct V_6 * V_7 )
{
struct V_144 * V_148 ;
int V_23 ;
V_148 = F_73 ( 1 , V_231 , 0 ) ;
if ( ! V_148 )
return - V_24 ;
V_148 [ 0 ] . V_223 . V_174 = 0 ;
V_148 [ 0 ] . V_223 . V_224 = F_84 ( V_7 -> V_232 -> V_224 ) ;
V_148 [ 0 ] . V_223 . V_225 = 0 ;
V_23 = F_95 ( V_7 , NULL ,
V_94 ,
V_219 | V_220 ,
V_148 ,
V_7 -> V_226 ,
0 , 0 , NULL , NULL , NULL ) ;
F_74 ( V_148 ) ;
F_110 ( V_7 -> V_232 ) ;
V_7 -> V_232 = NULL ;
return V_23 ;
}
static int F_112 ( struct V_6 * V_7 ,
const char * V_166 ,
const char * V_237 ,
const char * V_238 ,
const char * V_239 ,
T_4 V_240 ,
char * V_212 ,
T_4 V_211 ,
int V_36 ,
V_69 * V_174 )
{
struct V_144 * V_148 ;
int V_241 = strlen ( V_237 ) ;
int V_242 = strlen ( V_238 ) ;
int V_243 ;
int V_23 ;
V_243 = V_241 + V_242 + V_240 ;
V_148 = F_73 ( 1 , V_244 , V_243 ) ;
if ( ! V_148 )
return - V_24 ;
V_148 [ 0 ] . V_245 . V_237 = V_237 ;
V_148 [ 0 ] . V_245 . V_246 = ( V_247 ) V_241 ;
V_148 [ 0 ] . V_245 . V_238 = V_238 ;
V_148 [ 0 ] . V_245 . V_248 = ( V_247 ) V_242 ;
V_148 [ 0 ] . V_245 . V_249 = 0 ;
V_148 [ 0 ] . V_245 . V_250 = V_239 ;
V_148 [ 0 ] . V_245 . V_251 = V_240 ;
V_23 = F_95 ( V_7 , NULL ,
V_94 ,
V_36 , V_148 ,
V_166 , 0 , V_211 , V_212 ,
NULL , V_174 ) ;
F_74 ( V_148 ) ;
F_11 ( L_20 , V_23 ) ;
return V_23 ;
}
static struct V_54 * F_113 ( int V_252 )
{
struct V_54 * V_55 =
F_47 ( sizeof( struct V_54 ) +
sizeof( struct V_253 ) * V_252 ,
V_254 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_161 = V_252 ;
F_13 ( & V_55 -> V_27 ) ;
return V_55 ;
}
static void F_114 ( struct V_153 * V_154 )
{
struct V_6 * V_7 = V_154 -> V_255 ;
struct V_150 * V_151 ;
while ( ( V_151 = F_115 ( V_154 ) ) ) {
struct V_113 * V_113 ;
bool V_256 ;
unsigned int V_59 ;
V_69 V_109 ;
int V_257 , V_258 = 0 ;
struct V_54 * V_55 ;
struct V_67 * V_85 ;
unsigned int V_259 ;
F_11 ( L_21 ) ;
if ( ( V_151 -> V_260 != V_261 ) ) {
F_116 ( V_151 , 0 ) ;
continue;
}
V_256 = ( F_102 ( V_151 ) == V_217 ) ;
if ( V_256 && V_7 -> V_11 . V_12 ) {
F_116 ( V_151 , - V_13 ) ;
continue;
}
F_79 ( V_154 -> V_156 ) ;
F_117 ( & V_7 -> V_262 ) ;
if ( ! V_7 -> V_101 ) {
F_8 ( V_7 -> V_98 -> V_91 != V_94 ) ;
F_118 ( & V_7 -> V_262 ) ;
F_11 ( L_22 ) ;
F_77 ( V_154 -> V_156 ) ;
F_116 ( V_151 , - V_263 ) ;
continue;
}
V_85 = F_119 ( V_7 -> V_72 . V_85 ) ;
F_118 ( & V_7 -> V_262 ) ;
V_59 = F_120 ( V_151 ) ;
V_109 = F_121 ( V_151 ) * V_264 ;
V_113 = V_151 -> V_113 ;
F_11 ( L_23 ,
V_256 ? L_24 : L_25 ,
V_59 , ( unsigned long long ) F_121 ( V_151 ) * V_264 ) ;
V_257 = F_57 ( & V_7 -> V_72 , V_109 , V_59 ) ;
if ( V_257 <= 0 ) {
F_77 ( V_154 -> V_156 ) ;
F_116 ( V_151 , V_257 ) ;
F_53 ( V_85 ) ;
continue;
}
V_55 = F_113 ( V_257 ) ;
if ( ! V_55 ) {
F_77 ( V_154 -> V_156 ) ;
F_116 ( V_151 , - V_24 ) ;
F_53 ( V_85 ) ;
continue;
}
V_259 = 0 ;
do {
V_69 V_265 = F_56 ( V_7 , V_109 , V_59 ) ;
unsigned int V_266 ;
struct V_113 * V_267 ;
F_122 ( V_265 > ( V_69 ) V_268 ) ;
V_266 = ( unsigned int ) V_265 ;
F_11 ( L_26 , V_151 -> V_113 -> V_139 ) ;
F_28 ( & V_55 -> V_27 ) ;
V_267 = F_71 ( & V_113 ,
& V_259 , V_266 ,
V_254 ) ;
if ( V_267 )
( void ) F_101 ( V_151 , V_7 , V_85 ,
V_109 , V_266 ,
V_267 , V_55 , V_258 ) ;
else
F_75 ( V_151 , V_55 , V_258 ,
- V_24 , V_266 ) ;
V_59 -= V_266 ;
V_109 += V_266 ;
V_258 ++ ;
} while ( V_59 > 0 );
F_38 ( & V_55 -> V_27 , F_39 ) ;
F_77 ( V_154 -> V_156 ) ;
F_53 ( V_85 ) ;
}
}
static int F_123 ( struct V_153 * V_154 , struct V_269 * V_270 ,
struct V_118 * V_271 )
{
struct V_6 * V_7 = V_154 -> V_255 ;
T_8 V_272 ;
T_8 V_273 ;
T_8 V_274 ;
int V_23 ;
V_272 = F_124 ( V_270 -> V_132 ) + V_270 -> V_133 ;
V_273 = 1 << ( V_7 -> V_72 . V_82 - V_65 ) ;
V_274 = V_272 & ( V_273 - 1 ) ;
V_23 = ( int ) ( V_273 - V_274 ) << V_65 ;
if ( V_23 > V_270 -> V_131 )
V_23 -= V_270 -> V_131 ;
else
V_23 = 0 ;
F_8 ( V_271 -> V_122 <= V_275 ) ;
if ( V_23 > ( int ) V_271 -> V_122 || ! V_270 -> V_131 )
V_23 = ( int ) V_271 -> V_122 ;
return V_23 ;
}
static void F_125 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = V_7 -> V_18 ;
if ( ! V_18 )
return;
if ( V_18 -> V_36 & V_276 )
F_126 ( V_18 ) ;
if ( V_18 -> V_277 )
F_127 ( V_18 -> V_277 ) ;
F_128 ( V_18 ) ;
}
static struct V_57 *
F_129 ( struct V_6 * V_7 , V_69 * V_203 )
{
struct V_57 * V_58 = NULL ;
T_3 V_60 = 0 ;
V_69 V_278 = 0 ;
T_3 V_279 ;
int V_23 ;
do {
T_4 V_59 ;
F_22 ( V_58 ) ;
V_59 = sizeof ( * V_58 ) ;
V_59 += V_60 * sizeof ( struct V_280 ) ;
V_59 += V_278 ;
V_58 = F_12 ( V_59 , V_25 ) ;
if ( ! V_58 )
return F_24 ( - V_24 ) ;
V_23 = F_103 ( V_7 , V_94 ,
V_7 -> V_226 ,
0 , V_59 ,
( char * ) V_58 , V_203 ) ;
if ( V_23 < 0 )
goto V_31;
if ( F_46 ( ( T_4 ) V_23 < V_59 ) ) {
V_23 = - V_263 ;
F_107 ( L_27
L_28 ,
V_7 -> V_98 -> V_281 , V_59 , V_23 ) ;
goto V_31;
}
if ( ! F_41 ( V_58 ) ) {
V_23 = - V_263 ;
F_107 ( L_29 ,
V_7 -> V_98 -> V_281 ) ;
goto V_31;
}
V_278 = F_43 ( V_58 -> V_70 ) ;
V_279 = V_60 ;
V_60 = F_42 ( V_58 -> V_60 ) ;
} while ( V_60 != V_279 );
return V_58 ;
V_31:
F_22 ( V_58 ) ;
return F_24 ( V_23 ) ;
}
static int F_130 ( struct V_6 * V_7 ,
struct V_71 * V_72 )
{
struct V_57 * V_58 ;
V_69 V_174 = 0 ;
int V_23 ;
V_58 = F_129 ( V_7 , & V_174 ) ;
if ( F_16 ( V_58 ) )
return F_98 ( V_58 ) ;
V_23 = F_44 ( V_72 , V_58 ) ;
if ( V_23 >= 0 )
V_72 -> V_234 = V_174 ;
F_22 ( V_58 ) ;
return V_23 ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_92 * V_93 ;
struct V_92 * V_282 ;
F_132 (snap, next, &rbd_dev->snaps, node)
F_133 ( V_93 ) ;
}
static void F_134 ( struct V_6 * V_7 )
{
T_8 V_59 ;
if ( V_7 -> V_98 -> V_91 != V_94 )
return;
V_59 = ( T_8 ) V_7 -> V_72 . V_80 / V_264 ;
F_11 ( L_30 , ( unsigned long long ) V_59 ) ;
V_7 -> V_11 . V_59 = ( V_69 ) V_59 ;
F_135 ( V_7 -> V_18 , V_59 ) ;
}
static int F_136 ( struct V_6 * V_7 , V_69 * V_228 )
{
int V_23 ;
struct V_71 V_283 ;
V_23 = F_130 ( V_7 , & V_283 ) ;
if ( V_23 < 0 )
return V_23 ;
F_137 ( & V_7 -> V_262 ) ;
V_7 -> V_72 . V_80 = V_283 . V_80 ;
F_134 ( V_7 ) ;
F_22 ( V_7 -> V_72 . V_79 ) ;
F_22 ( V_7 -> V_72 . V_77 ) ;
F_53 ( V_7 -> V_72 . V_85 ) ;
if ( V_228 )
* V_228 = V_283 . V_234 ;
V_7 -> V_72 . V_234 = V_283 . V_234 ;
V_7 -> V_72 . V_80 = V_283 . V_80 ;
V_7 -> V_72 . V_85 = V_283 . V_85 ;
V_7 -> V_72 . V_77 = V_283 . V_77 ;
V_7 -> V_72 . V_79 = V_283 . V_79 ;
F_46 ( strcmp ( V_7 -> V_72 . V_75 , V_283 . V_75 ) ) ;
F_22 ( V_283 . V_75 ) ;
V_23 = F_138 ( V_7 ) ;
if ( ! V_23 )
V_23 = F_139 ( V_7 ) ;
F_140 ( & V_7 -> V_262 ) ;
return V_23 ;
}
static int F_106 ( struct V_6 * V_7 , V_69 * V_228 )
{
int V_23 ;
F_8 ( F_40 ( V_7 -> V_56 ) ) ;
F_3 ( & V_14 , V_15 ) ;
if ( V_7 -> V_56 == 1 )
V_23 = F_136 ( V_7 , V_228 ) ;
else
V_23 = F_141 ( V_7 , V_228 ) ;
F_6 ( & V_14 ) ;
return V_23 ;
}
static int F_142 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_153 * V_154 ;
V_69 V_106 ;
V_18 = F_143 ( V_284 ) ;
if ( ! V_18 )
return - V_24 ;
snprintf ( V_18 -> V_285 , sizeof( V_18 -> V_285 ) , V_229 L_31 ,
V_7 -> V_286 ) ;
V_18 -> V_230 = V_7 -> V_230 ;
V_18 -> V_287 = 0 ;
V_18 -> V_288 = & V_289 ;
V_18 -> V_9 = V_7 ;
V_154 = F_144 ( F_114 , & V_7 -> V_290 ) ;
if ( ! V_154 )
goto V_291;
F_145 ( V_154 , V_264 ) ;
V_106 = F_58 ( & V_7 -> V_72 ) ;
F_146 ( V_154 , V_106 / V_264 ) ;
F_147 ( V_154 , V_106 ) ;
F_148 ( V_154 , V_106 ) ;
F_149 ( V_154 , V_106 ) ;
F_150 ( V_154 , F_123 ) ;
V_18 -> V_277 = V_154 ;
V_154 -> V_255 = V_7 ;
V_7 -> V_18 = V_18 ;
F_135 ( V_7 -> V_18 , V_7 -> V_11 . V_59 / V_264 ) ;
return 0 ;
V_291:
F_128 ( V_18 ) ;
return - V_24 ;
}
static struct V_6 * F_151 ( struct V_1 * V_2 )
{
return F_35 ( V_2 , struct V_6 , V_2 ) ;
}
static T_9 F_152 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
T_8 V_59 ;
F_117 ( & V_7 -> V_262 ) ;
V_59 = F_153 ( V_7 -> V_18 ) ;
F_118 ( & V_7 -> V_262 ) ;
return sprintf ( V_120 , L_32 , ( unsigned long long ) V_59 * V_264 ) ;
}
static T_9 F_154 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_33 ,
( unsigned long long ) V_7 -> V_11 . V_81 ) ;
}
static T_9 F_155 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_34 , V_7 -> V_230 ) ;
}
static T_9 F_156 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_35 ,
F_157 ( V_7 -> V_19 -> V_29 ) ) ;
}
static T_9 F_158 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_36 , V_7 -> V_98 -> V_294 ) ;
}
static T_9 F_159 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_32 ,
( unsigned long long ) V_7 -> V_98 -> V_200 ) ;
}
static T_9 F_160 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
if ( V_7 -> V_98 -> V_281 )
return sprintf ( V_120 , L_36 , V_7 -> V_98 -> V_281 ) ;
return sprintf ( V_120 , L_37 ) ;
}
static T_9 F_161 ( struct V_1 * V_2 ,
struct V_292 * V_293 , char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_36 , V_7 -> V_98 -> V_295 ) ;
}
static T_9 F_162 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
return sprintf ( V_120 , L_36 , V_7 -> V_98 -> V_97 ) ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
char * V_120 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
struct V_296 * V_98 = V_7 -> V_297 ;
int V_298 ;
char * V_299 = V_120 ;
if ( ! V_98 )
return sprintf ( V_120 , L_38 ) ;
V_298 = sprintf ( V_299 , L_39 ,
( unsigned long long ) V_98 -> V_200 , V_98 -> V_294 ) ;
if ( V_298 < 0 )
return V_298 ;
V_299 += V_298 ;
V_298 = sprintf ( V_299 , L_40 , V_98 -> V_295 ,
V_98 -> V_281 ? V_98 -> V_281 : L_41 ) ;
if ( V_298 < 0 )
return V_298 ;
V_299 += V_298 ;
V_298 = sprintf ( V_299 , L_42 ,
( unsigned long long ) V_98 -> V_91 , V_98 -> V_97 ) ;
if ( V_298 < 0 )
return V_298 ;
V_299 += V_298 ;
V_298 = sprintf ( V_299 , L_43 , V_7 -> V_300 ) ;
if ( V_298 < 0 )
return V_298 ;
V_299 += V_298 ;
return ( T_9 ) ( V_299 - V_120 ) ;
}
static T_9 F_164 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
const char * V_120 ,
T_4 V_59 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
int V_23 ;
V_23 = F_106 ( V_7 , NULL ) ;
return V_23 < 0 ? V_23 : V_59 ;
}
static void F_165 ( struct V_1 * V_2 )
{
}
static T_9 F_166 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
char * V_120 )
{
struct V_92 * V_93 = F_35 ( V_2 , struct V_92 , V_2 ) ;
return sprintf ( V_120 , L_32 , ( unsigned long long ) V_93 -> V_59 ) ;
}
static T_9 F_167 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
char * V_120 )
{
struct V_92 * V_93 = F_35 ( V_2 , struct V_92 , V_2 ) ;
return sprintf ( V_120 , L_32 , ( unsigned long long ) V_93 -> V_90 ) ;
}
static T_9 F_168 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
char * V_120 )
{
struct V_92 * V_93 = F_35 ( V_2 , struct V_92 , V_2 ) ;
return sprintf ( V_120 , L_33 ,
( unsigned long long ) V_93 -> V_81 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_35 ( V_2 , struct V_92 , V_2 ) ;
F_22 ( V_93 -> V_96 ) ;
F_22 ( V_93 ) ;
}
static struct V_296 * F_170 ( struct V_296 * V_98 )
{
F_28 ( & V_98 -> V_27 ) ;
return V_98 ;
}
static void F_171 ( struct V_296 * V_98 )
{
if ( V_98 )
F_38 ( & V_98 -> V_27 , V_301 ) ;
}
static struct V_296 * F_172 ( void )
{
struct V_296 * V_98 ;
V_98 = F_47 ( sizeof ( * V_98 ) , V_25 ) ;
if ( ! V_98 )
return NULL ;
F_13 ( & V_98 -> V_27 ) ;
F_171 ( F_170 ( V_98 ) ) ;
return V_98 ;
}
static void V_301 ( struct V_27 * V_27 )
{
struct V_296 * V_98 = F_35 ( V_27 , struct V_296 , V_27 ) ;
F_22 ( V_98 -> V_294 ) ;
F_22 ( V_98 -> V_295 ) ;
F_22 ( V_98 -> V_281 ) ;
F_22 ( V_98 -> V_97 ) ;
F_22 ( V_98 ) ;
}
struct V_6 * F_173 ( struct V_19 * V_22 ,
struct V_296 * V_98 )
{
struct V_6 * V_7 ;
V_7 = F_47 ( sizeof ( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return NULL ;
F_174 ( & V_7 -> V_290 ) ;
F_14 ( & V_7 -> V_28 ) ;
F_14 ( & V_7 -> V_78 ) ;
F_175 ( & V_7 -> V_262 ) ;
V_7 -> V_98 = V_98 ;
V_7 -> V_19 = V_22 ;
return V_7 ;
}
static void F_176 ( struct V_6 * V_7 )
{
F_171 ( V_7 -> V_297 ) ;
F_22 ( V_7 -> V_226 ) ;
F_37 ( V_7 -> V_19 ) ;
F_171 ( V_7 -> V_98 ) ;
F_22 ( V_7 ) ;
}
static bool F_177 ( struct V_92 * V_93 )
{
bool V_23 = V_93 -> V_2 . type == & V_302 ;
bool V_303 = F_178 ( & V_93 -> V_2 ) ;
F_8 ( ! V_23 ^ V_303 ) ;
return V_23 ;
}
static void F_133 ( struct V_92 * V_93 )
{
F_36 ( & V_93 -> V_28 ) ;
if ( F_178 ( & V_93 -> V_2 ) )
F_179 ( & V_93 -> V_2 ) ;
}
static int F_180 ( struct V_92 * V_93 ,
struct V_1 * V_304 )
{
struct V_1 * V_2 = & V_93 -> V_2 ;
int V_23 ;
V_2 -> type = & V_302 ;
V_2 -> V_304 = V_304 ;
V_2 -> V_305 = F_169 ;
F_181 ( V_2 , L_44 , V_306 , V_93 -> V_96 ) ;
F_11 ( L_45 , V_307 , V_93 -> V_96 ) ;
V_23 = F_182 ( V_2 ) ;
return V_23 ;
}
static struct V_92 * F_183 ( struct V_6 * V_7 ,
const char * V_97 ,
V_69 V_91 , V_69 V_308 ,
V_69 V_309 )
{
struct V_92 * V_93 ;
int V_23 ;
V_93 = F_47 ( sizeof ( * V_93 ) , V_25 ) ;
if ( ! V_93 )
return F_24 ( - V_24 ) ;
V_23 = - V_24 ;
V_93 -> V_96 = F_184 ( V_97 , V_25 ) ;
if ( ! V_93 -> V_96 )
goto V_310;
V_93 -> V_90 = V_91 ;
V_93 -> V_59 = V_308 ;
V_93 -> V_81 = V_309 ;
return V_93 ;
V_310:
F_22 ( V_93 -> V_96 ) ;
F_22 ( V_93 ) ;
return F_24 ( V_23 ) ;
}
static char * F_185 ( struct V_6 * V_7 , T_3 V_311 ,
V_69 * V_308 , V_69 * V_309 )
{
char * V_97 ;
F_8 ( V_311 < V_7 -> V_72 . V_85 -> V_89 ) ;
* V_308 = V_7 -> V_72 . V_79 [ V_311 ] ;
* V_309 = 0 ;
V_97 = V_7 -> V_72 . V_77 ;
while ( V_311 -- )
V_97 += strlen ( V_97 ) + 1 ;
return V_97 ;
}
static int F_186 ( struct V_6 * V_7 , V_69 V_91 ,
T_7 * V_64 , V_69 * V_308 )
{
V_68 V_165 = F_84 ( V_91 ) ;
int V_23 ;
struct {
T_7 V_64 ;
V_68 V_59 ;
} V_312 ( ( V_313 ) ) V_314 = { 0 } ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_47 ,
( char * ) & V_165 , sizeof ( V_165 ) ,
( char * ) & V_314 , sizeof ( V_314 ) ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
return V_23 ;
* V_64 = V_314 . V_64 ;
* V_308 = F_43 ( V_314 . V_59 ) ;
F_11 ( L_49 ,
( unsigned long long ) V_91 , ( unsigned int ) * V_64 ,
( unsigned long long ) * V_308 ) ;
return 0 ;
}
static int F_187 ( struct V_6 * V_7 )
{
return F_186 ( V_7 , V_94 ,
& V_7 -> V_72 . V_82 ,
& V_7 -> V_72 . V_80 ) ;
}
static int F_188 ( struct V_6 * V_7 )
{
void * V_315 ;
int V_23 ;
void * V_316 ;
V_315 = F_47 ( V_317 , V_25 ) ;
if ( ! V_315 )
return - V_24 ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_50 ,
NULL , 0 ,
V_315 , V_317 ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
goto V_318;
V_23 = 0 ;
V_316 = V_315 ;
V_7 -> V_72 . V_75 = F_189 ( & V_316 ,
V_316 + V_317 ,
NULL , V_105 ) ;
if ( F_16 ( V_7 -> V_72 . V_75 ) ) {
V_23 = F_98 ( V_7 -> V_72 . V_75 ) ;
V_7 -> V_72 . V_75 = NULL ;
} else {
F_11 ( L_51 , V_7 -> V_72 . V_75 ) ;
}
V_318:
F_22 ( V_315 ) ;
return V_23 ;
}
static int F_190 ( struct V_6 * V_7 , V_69 V_91 ,
V_69 * V_309 )
{
V_68 V_165 = F_84 ( V_91 ) ;
struct {
V_68 V_81 ;
V_68 V_319 ;
} V_320 = { 0 } ;
V_69 V_319 ;
int V_23 ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_52 ,
( char * ) & V_165 , sizeof ( V_165 ) ,
( char * ) & V_320 , sizeof ( V_320 ) ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
return V_23 ;
V_319 = F_43 ( V_320 . V_319 ) ;
if ( V_319 & ~ V_321 )
return - V_263 ;
* V_309 = F_43 ( V_320 . V_81 ) ;
F_11 ( L_53 ,
( unsigned long long ) V_91 ,
( unsigned long long ) * V_309 ,
( unsigned long long ) F_43 ( V_320 . V_319 ) ) ;
return 0 ;
}
static int F_191 ( struct V_6 * V_7 )
{
return F_190 ( V_7 , V_94 ,
& V_7 -> V_72 . V_81 ) ;
}
static int F_192 ( struct V_6 * V_7 )
{
struct V_296 * V_297 ;
T_4 V_59 ;
void * V_315 = NULL ;
V_68 V_165 ;
void * V_316 ;
void * V_143 ;
char * V_295 ;
V_69 V_322 ;
T_4 V_73 = 0 ;
int V_23 ;
V_297 = F_172 () ;
if ( ! V_297 )
return - V_24 ;
V_59 = sizeof ( V_68 ) +
sizeof ( V_323 ) + V_324 +
sizeof ( V_68 ) +
sizeof ( V_68 ) ;
V_315 = F_12 ( V_59 , V_25 ) ;
if ( ! V_315 ) {
V_23 = - V_24 ;
goto V_31;
}
V_165 = F_84 ( V_94 ) ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_54 ,
( char * ) & V_165 , sizeof ( V_165 ) ,
( char * ) V_315 , V_59 ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
goto V_31;
V_23 = - V_112 ;
V_316 = V_315 ;
V_143 = ( char * ) V_315 + V_59 ;
F_193 ( & V_316 , V_143 , V_297 -> V_200 , V_31 ) ;
if ( V_297 -> V_200 == V_325 )
goto V_318;
V_295 = F_189 ( & V_316 , V_143 , & V_73 , V_25 ) ;
if ( F_16 ( V_295 ) ) {
V_23 = F_98 ( V_295 ) ;
goto V_31;
}
V_297 -> V_295 = V_295 ;
V_297 -> V_326 = V_73 ;
F_193 ( & V_316 , V_143 , V_297 -> V_91 , V_31 ) ;
F_193 ( & V_316 , V_143 , V_322 , V_31 ) ;
V_7 -> V_300 = V_322 ;
V_7 -> V_297 = V_297 ;
V_297 = NULL ;
V_318:
V_23 = 0 ;
V_31:
F_22 ( V_315 ) ;
F_171 ( V_297 ) ;
return V_23 ;
}
static char * F_194 ( struct V_6 * V_7 )
{
T_4 V_327 ;
char * V_295 ;
void * V_316 ;
void * V_143 ;
T_4 V_59 ;
void * V_315 = NULL ;
T_4 V_73 = 0 ;
char * V_281 = NULL ;
int V_23 ;
F_8 ( ! V_7 -> V_98 -> V_281 ) ;
V_327 = sizeof ( V_323 ) + V_7 -> V_98 -> V_326 ;
V_295 = F_12 ( V_327 , V_25 ) ;
if ( ! V_295 )
return NULL ;
V_316 = V_295 ;
V_143 = ( char * ) V_295 + V_327 ;
F_195 ( & V_316 , V_143 , V_7 -> V_98 -> V_295 ,
( T_3 ) V_7 -> V_98 -> V_326 ) ;
V_59 = sizeof ( V_323 ) + V_328 ;
V_315 = F_12 ( V_59 , V_25 ) ;
if ( ! V_315 )
goto V_318;
V_23 = F_112 ( V_7 , V_329 ,
L_46 , L_55 ,
V_295 , V_327 ,
( char * ) V_315 , V_59 ,
V_213 , NULL ) ;
if ( V_23 < 0 )
goto V_318;
V_316 = V_315 ;
V_143 = ( char * ) V_315 + V_59 ;
V_281 = F_189 ( & V_316 , V_143 , & V_73 , V_25 ) ;
if ( F_16 ( V_281 ) )
V_281 = NULL ;
else
F_11 ( L_56 , V_307 , V_281 , V_73 ) ;
V_318:
F_22 ( V_315 ) ;
F_22 ( V_295 ) ;
return V_281 ;
}
static int F_196 ( struct V_6 * V_7 )
{
struct V_184 * V_185 ;
const char * V_96 ;
void * V_315 = NULL ;
int V_23 ;
if ( V_7 -> V_98 -> V_294 )
return 0 ;
V_185 = & V_7 -> V_19 -> V_29 -> V_185 ;
V_96 = F_197 ( V_185 -> V_330 , V_7 -> V_98 -> V_200 ) ;
if ( ! V_96 )
return - V_76 ;
V_7 -> V_98 -> V_294 = F_184 ( V_96 , V_25 ) ;
if ( ! V_7 -> V_98 -> V_294 )
return - V_24 ;
V_96 = F_194 ( V_7 ) ;
if ( V_96 ) {
V_7 -> V_98 -> V_331 = strlen ( V_96 ) ;
V_7 -> V_98 -> V_281 = ( char * ) V_96 ;
} else {
F_107 ( V_229 L_57
L_58 ,
V_7 -> V_230 , V_7 -> V_98 -> V_295 ) ;
}
V_96 = F_49 ( V_7 , V_7 -> V_98 -> V_91 ) ;
if ( ! V_96 ) {
V_23 = - V_76 ;
goto V_31;
}
V_7 -> V_98 -> V_97 = F_184 ( V_96 , V_25 ) ;
if( ! V_7 -> V_98 -> V_97 )
goto V_31;
return 0 ;
V_31:
F_22 ( V_315 ) ;
F_22 ( V_7 -> V_98 -> V_294 ) ;
V_7 -> V_98 -> V_294 = NULL ;
return V_23 ;
}
static int F_198 ( struct V_6 * V_7 , V_69 * V_174 )
{
T_4 V_59 ;
int V_23 ;
void * V_315 ;
void * V_316 ;
void * V_143 ;
V_69 V_87 ;
T_3 V_60 ;
struct V_67 * V_85 ;
T_3 V_74 ;
V_59 = sizeof ( V_68 ) + sizeof ( V_323 ) +
V_332 * sizeof ( V_68 ) ;
V_315 = F_47 ( V_59 , V_25 ) ;
if ( ! V_315 )
return - V_24 ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_59 ,
NULL , 0 ,
V_315 , V_59 ,
V_213 , V_174 ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
goto V_318;
V_23 = - V_112 ;
V_316 = V_315 ;
V_143 = ( char * ) V_315 + V_59 ;
F_193 ( & V_316 , V_143 , V_87 , V_318 ) ;
F_199 ( & V_316 , V_143 , V_60 , V_318 ) ;
if ( V_60 > ( V_66 - sizeof ( struct V_67 ) )
/ sizeof ( V_69 ) ) {
V_23 = - V_47 ;
goto V_318;
}
if ( ! F_200 ( & V_316 , V_143 , V_60 * sizeof ( V_68 ) ) )
goto V_318;
V_59 = sizeof ( struct V_67 ) +
V_60 * sizeof ( V_85 -> V_78 [ 0 ] ) ;
V_85 = F_12 ( V_59 , V_25 ) ;
if ( ! V_85 ) {
V_23 = - V_24 ;
goto V_318;
}
F_48 ( & V_85 -> V_86 , 1 ) ;
V_85 -> V_87 = V_87 ;
V_85 -> V_89 = V_60 ;
for ( V_74 = 0 ; V_74 < V_60 ; V_74 ++ )
V_85 -> V_78 [ V_74 ] = F_201 ( & V_316 ) ;
V_7 -> V_72 . V_85 = V_85 ;
F_11 ( L_60 ,
( unsigned long long ) V_87 , ( unsigned int ) V_60 ) ;
V_318:
F_22 ( V_315 ) ;
return 0 ;
}
static char * F_202 ( struct V_6 * V_7 , T_3 V_311 )
{
T_4 V_59 ;
void * V_315 ;
V_68 V_91 ;
int V_23 ;
void * V_316 ;
void * V_143 ;
char * V_97 ;
V_59 = sizeof ( V_323 ) + V_333 ;
V_315 = F_12 ( V_59 , V_25 ) ;
if ( ! V_315 )
return F_24 ( - V_24 ) ;
V_91 = F_84 ( V_7 -> V_72 . V_85 -> V_78 [ V_311 ] ) ;
V_23 = F_112 ( V_7 , V_7 -> V_226 ,
L_46 , L_61 ,
( char * ) & V_91 , sizeof ( V_91 ) ,
V_315 , V_59 ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
goto V_318;
V_316 = V_315 ;
V_143 = ( char * ) V_315 + V_59 ;
V_97 = F_189 ( & V_316 , V_143 , NULL , V_25 ) ;
if ( F_16 ( V_97 ) ) {
V_23 = F_98 ( V_97 ) ;
goto V_318;
} else {
F_11 ( L_62 ,
( unsigned long long ) F_43 ( V_91 ) , V_97 ) ;
}
F_22 ( V_315 ) ;
return V_97 ;
V_318:
F_22 ( V_315 ) ;
return F_24 ( V_23 ) ;
}
static char * F_203 ( struct V_6 * V_7 , T_3 V_311 ,
V_69 * V_308 , V_69 * V_309 )
{
V_68 V_91 ;
T_7 V_64 ;
int V_23 ;
V_91 = V_7 -> V_72 . V_85 -> V_78 [ V_311 ] ;
V_23 = F_186 ( V_7 , V_91 , & V_64 , V_308 ) ;
if ( V_23 )
return F_24 ( V_23 ) ;
V_23 = F_190 ( V_7 , V_91 , V_309 ) ;
if ( V_23 )
return F_24 ( V_23 ) ;
return F_202 ( V_7 , V_311 ) ;
}
static char * F_204 ( struct V_6 * V_7 , T_3 V_311 ,
V_69 * V_308 , V_69 * V_309 )
{
if ( V_7 -> V_56 == 1 )
return F_185 ( V_7 , V_311 ,
V_308 , V_309 ) ;
if ( V_7 -> V_56 == 2 )
return F_203 ( V_7 , V_311 ,
V_308 , V_309 ) ;
return F_24 ( - V_47 ) ;
}
static int F_141 ( struct V_6 * V_7 , V_69 * V_228 )
{
int V_23 ;
V_247 V_82 ;
F_137 ( & V_7 -> V_262 ) ;
V_82 = V_7 -> V_72 . V_82 ,
V_23 = F_187 ( V_7 ) ;
if ( V_23 )
goto V_318;
if ( V_7 -> V_72 . V_82 != V_82 ) {
V_23 = - V_76 ;
goto V_318;
}
F_134 ( V_7 ) ;
V_23 = F_198 ( V_7 , V_228 ) ;
F_11 ( L_63 , V_23 ) ;
if ( V_23 )
goto V_318;
V_23 = F_138 ( V_7 ) ;
F_11 ( L_64 , V_23 ) ;
if ( V_23 )
goto V_318;
V_23 = F_139 ( V_7 ) ;
F_11 ( L_65 , V_23 ) ;
V_318:
F_140 ( & V_7 -> V_262 ) ;
return V_23 ;
}
static int F_138 ( struct V_6 * V_7 )
{
struct V_67 * V_85 = V_7 -> V_72 . V_85 ;
const T_3 V_60 = V_85 -> V_89 ;
struct V_334 * V_335 = & V_7 -> V_78 ;
struct V_334 * V_336 = V_335 -> V_282 ;
T_3 V_152 = 0 ;
F_11 ( L_66 , V_307 , ( unsigned int ) V_60 ) ;
while ( V_152 < V_60 || V_336 != V_335 ) {
V_69 V_91 ;
struct V_92 * V_93 ;
char * V_97 ;
V_69 V_308 = 0 ;
V_69 V_309 = 0 ;
V_91 = V_152 < V_60 ? V_85 -> V_78 [ V_152 ]
: V_94 ;
V_93 = V_336 != V_335 ? F_205 ( V_336 , struct V_92 , V_28 )
: NULL ;
F_8 ( ! V_93 || V_93 -> V_90 != V_94 ) ;
if ( V_91 == V_94 || ( V_93 && V_93 -> V_90 > V_91 ) ) {
struct V_334 * V_282 = V_336 -> V_282 ;
if ( V_7 -> V_98 -> V_91 == V_93 -> V_90 )
V_7 -> V_101 = false ;
F_133 ( V_93 ) ;
F_11 ( L_67 ,
V_7 -> V_98 -> V_91 == V_93 -> V_90 ?
L_68 : L_69 ,
( unsigned long long ) V_93 -> V_90 ) ;
V_336 = V_282 ;
continue;
}
V_97 = F_204 ( V_7 , V_152 ,
& V_308 , & V_309 ) ;
if ( F_16 ( V_97 ) )
return F_98 ( V_97 ) ;
F_11 ( L_70 , ( unsigned int ) V_60 ,
( unsigned long long ) V_91 ) ;
if ( ! V_93 || ( V_91 != V_94 && V_93 -> V_90 < V_91 ) ) {
struct V_92 * V_337 ;
V_337 = F_183 ( V_7 , V_97 ,
V_91 , V_308 , V_309 ) ;
if ( F_16 ( V_337 ) ) {
int V_310 = F_98 ( V_337 ) ;
F_11 ( L_71 , V_310 ) ;
return V_310 ;
}
F_11 ( L_72 , V_93 ? L_69 : L_73 ) ;
if ( V_93 )
F_19 ( & V_337 -> V_28 , & V_93 -> V_28 ) ;
else
F_19 ( & V_337 -> V_28 , V_335 ) ;
} else {
F_11 ( L_74 ) ;
F_8 ( V_93 -> V_59 == V_308 ) ;
F_8 ( ! strcmp ( V_93 -> V_96 , V_97 ) ) ;
F_8 ( V_93 -> V_81 == V_309 ) ;
V_336 = V_336 -> V_282 ;
}
V_152 ++ ;
}
F_11 ( L_75 , V_307 ) ;
return 0 ;
}
static int F_139 ( struct V_6 * V_7 )
{
struct V_92 * V_93 ;
int V_23 = 0 ;
F_11 ( L_76 , V_307 ) ;
if ( F_46 ( ! F_178 ( & V_7 -> V_2 ) ) )
return - V_76 ;
F_26 (snap, &rbd_dev->snaps, node) {
if ( ! F_177 ( V_93 ) ) {
V_23 = F_180 ( V_93 , & V_7 -> V_2 ) ;
if ( V_23 < 0 )
break;
}
}
F_11 ( L_77 , V_307 , V_23 ) ;
return V_23 ;
}
static int F_206 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
int V_23 ;
F_3 ( & V_14 , V_15 ) ;
V_2 = & V_7 -> V_2 ;
V_2 -> V_338 = & V_339 ;
V_2 -> type = & V_340 ;
V_2 -> V_304 = & V_341 ;
V_2 -> V_305 = V_342 ;
F_181 ( V_2 , L_31 , V_7 -> V_286 ) ;
V_23 = F_182 ( V_2 ) ;
F_6 ( & V_14 ) ;
return V_23 ;
}
static void F_207 ( struct V_6 * V_7 )
{
F_179 ( & V_7 -> V_2 ) ;
}
static int F_208 ( struct V_6 * V_7 )
{
int V_23 , V_158 ;
do {
V_23 = F_108 ( V_7 ) ;
if ( V_23 == - V_112 ) {
V_158 = F_106 ( V_7 , NULL ) ;
if ( V_158 < 0 )
return V_158 ;
}
} while ( V_23 == - V_112 );
return V_23 ;
}
static void F_209 ( struct V_6 * V_7 )
{
V_7 -> V_286 = F_210 ( & V_343 ) ;
F_18 ( & V_344 ) ;
F_19 ( & V_7 -> V_28 , & V_345 ) ;
F_20 ( & V_344 ) ;
F_11 ( L_78 , V_7 ,
( unsigned long long ) V_7 -> V_286 ) ;
}
static void F_211 ( struct V_6 * V_7 )
{
struct V_334 * V_115 ;
int V_346 = V_7 -> V_286 ;
int V_347 ;
F_8 ( V_346 > 0 ) ;
F_11 ( L_79 , V_7 ,
( unsigned long long ) V_7 -> V_286 ) ;
F_18 ( & V_344 ) ;
F_212 ( & V_7 -> V_28 ) ;
if ( V_346 != F_213 ( & V_343 ) ) {
F_20 ( & V_344 ) ;
return;
}
V_347 = 0 ;
F_214 (tmp, &rbd_dev_list) {
struct V_6 * V_7 ;
V_7 = F_205 ( V_115 , struct V_6 , V_28 ) ;
if ( V_7 -> V_286 > V_347 )
V_347 = V_7 -> V_286 ;
}
F_20 ( & V_344 ) ;
F_215 ( & V_343 , V_346 , V_347 ) ;
F_11 ( L_80 ) ;
}
static inline T_4 F_216 ( const char * * V_120 )
{
const char * V_348 = L_81 ;
* V_120 += strspn ( * V_120 , V_348 ) ;
return strcspn ( * V_120 , V_348 ) ;
}
static inline T_4 F_217 ( const char * * V_120 ,
char * V_44 ,
T_4 V_349 )
{
T_4 V_73 ;
V_73 = F_216 ( V_120 ) ;
if ( V_73 < V_349 ) {
memcpy ( V_44 , * V_120 , V_73 ) ;
* ( V_44 + V_73 ) = '\0' ;
}
* V_120 += V_73 ;
return V_73 ;
}
static inline char * F_218 ( const char * * V_120 , T_4 * V_350 )
{
char * V_351 ;
T_4 V_73 ;
V_73 = F_216 ( V_120 ) ;
V_351 = F_12 ( V_73 + 1 , V_25 ) ;
if ( ! V_351 )
return NULL ;
memcpy ( V_351 , * V_120 , V_73 ) ;
* ( V_351 + V_73 ) = '\0' ;
* V_120 += V_73 ;
if ( V_350 )
* V_350 = V_73 ;
return V_351 ;
}
static int F_219 ( const char * V_120 ,
struct V_20 * * V_21 ,
struct V_40 * * V_352 ,
struct V_296 * * V_296 )
{
T_4 V_73 ;
char * V_63 ;
const char * V_353 ;
T_4 V_354 ;
struct V_296 * V_98 = NULL ;
struct V_40 * V_41 = NULL ;
struct V_20 * V_355 ;
int V_23 ;
V_73 = F_216 ( & V_120 ) ;
if ( ! V_73 )
return - V_47 ;
V_353 = V_120 ;
V_354 = V_73 + 1 ;
V_120 += V_73 ;
V_23 = - V_47 ;
V_63 = F_218 ( & V_120 , NULL ) ;
if ( ! V_63 )
return - V_24 ;
if ( ! * V_63 )
goto V_31;
V_98 = F_172 () ;
if ( ! V_98 )
goto V_356;
V_98 -> V_294 = F_218 ( & V_120 , NULL ) ;
if ( ! V_98 -> V_294 )
goto V_356;
if ( ! * V_98 -> V_294 )
goto V_31;
V_98 -> V_281 = F_218 ( & V_120 , & V_98 -> V_331 ) ;
if ( ! V_98 -> V_281 )
goto V_356;
if ( ! * V_98 -> V_281 )
goto V_31;
V_73 = F_216 ( & V_120 ) ;
if ( ! V_73 ) {
V_120 = V_95 ;
V_73 = sizeof ( V_95 ) - 1 ;
} else if ( V_73 > V_333 ) {
V_23 = - V_357 ;
goto V_31;
}
V_98 -> V_97 = F_12 ( V_73 + 1 , V_25 ) ;
if ( ! V_98 -> V_97 )
goto V_356;
memcpy ( V_98 -> V_97 , V_120 , V_73 ) ;
* ( V_98 -> V_97 + V_73 ) = '\0' ;
V_41 = F_47 ( sizeof ( * V_41 ) , V_25 ) ;
if ( ! V_41 )
goto V_356;
V_41 -> V_12 = V_358 ;
V_355 = F_220 ( V_63 , V_353 ,
V_353 + V_354 - 1 ,
F_29 , V_41 ) ;
if ( F_16 ( V_355 ) ) {
V_23 = F_98 ( V_355 ) ;
goto V_31;
}
F_22 ( V_63 ) ;
* V_21 = V_355 ;
* V_352 = V_41 ;
* V_296 = V_98 ;
return 0 ;
V_356:
V_23 = - V_24 ;
V_31:
F_22 ( V_41 ) ;
F_171 ( V_98 ) ;
F_22 ( V_63 ) ;
return V_23 ;
}
static int F_221 ( struct V_6 * V_7 )
{
int V_23 ;
T_4 V_59 ;
char * V_166 ;
void * V_359 ;
void * V_316 ;
if ( V_7 -> V_98 -> V_295 )
return 0 ;
V_59 = sizeof ( V_360 ) + V_7 -> V_98 -> V_331 ;
V_166 = F_12 ( V_59 , V_105 ) ;
if ( ! V_166 )
return - V_24 ;
sprintf ( V_166 , L_44 , V_360 , V_7 -> V_98 -> V_281 ) ;
F_11 ( L_82 , V_166 ) ;
V_59 = sizeof ( V_323 ) + V_324 ;
V_359 = F_47 ( V_59 , V_105 ) ;
if ( ! V_359 ) {
V_23 = - V_24 ;
goto V_318;
}
V_23 = F_112 ( V_7 , V_166 ,
L_46 , L_83 ,
NULL , 0 ,
V_359 , V_324 ,
V_213 , NULL ) ;
F_11 ( L_48 , V_307 , V_23 ) ;
if ( V_23 < 0 )
goto V_318;
V_23 = 0 ;
V_316 = V_359 ;
V_7 -> V_98 -> V_295 = F_189 ( & V_316 ,
V_316 + V_324 ,
& V_7 -> V_98 -> V_326 ,
V_105 ) ;
if ( F_16 ( V_7 -> V_98 -> V_295 ) ) {
V_23 = F_98 ( V_7 -> V_98 -> V_295 ) ;
V_7 -> V_98 -> V_295 = NULL ;
} else {
F_11 ( L_84 , V_7 -> V_98 -> V_295 ) ;
}
V_318:
F_22 ( V_359 ) ;
F_22 ( V_166 ) ;
return V_23 ;
}
static int F_222 ( struct V_6 * V_7 )
{
int V_23 ;
T_4 V_59 ;
V_7 -> V_98 -> V_295 = F_184 ( L_69 , V_25 ) ;
if ( ! V_7 -> V_98 -> V_295 )
return - V_24 ;
V_7 -> V_98 -> V_326 = 0 ;
V_59 = V_7 -> V_98 -> V_331 + sizeof ( V_361 ) ;
V_7 -> V_226 = F_12 ( V_59 , V_25 ) ;
if ( ! V_7 -> V_226 ) {
V_23 = - V_24 ;
goto V_31;
}
sprintf ( V_7 -> V_226 , L_44 ,
V_7 -> V_98 -> V_281 , V_361 ) ;
V_23 = F_130 ( V_7 , & V_7 -> V_72 ) ;
if ( V_23 < 0 )
goto V_31;
V_7 -> V_297 = NULL ;
V_7 -> V_300 = 0 ;
V_7 -> V_56 = 1 ;
F_11 ( L_85 ,
V_7 -> V_226 ) ;
return 0 ;
V_31:
F_22 ( V_7 -> V_226 ) ;
V_7 -> V_226 = NULL ;
F_22 ( V_7 -> V_98 -> V_295 ) ;
V_7 -> V_98 -> V_295 = NULL ;
return V_23 ;
}
static int F_223 ( struct V_6 * V_7 )
{
T_4 V_59 ;
int V_23 ;
V_69 V_174 = 0 ;
V_59 = sizeof ( V_362 ) + V_7 -> V_98 -> V_326 ;
V_7 -> V_226 = F_12 ( V_59 , V_25 ) ;
if ( ! V_7 -> V_226 )
return - V_24 ;
sprintf ( V_7 -> V_226 , L_44 ,
V_362 , V_7 -> V_98 -> V_295 ) ;
V_23 = F_187 ( V_7 ) ;
if ( V_23 < 0 )
goto V_31;
V_23 = F_188 ( V_7 ) ;
if ( V_23 < 0 )
goto V_31;
V_23 = F_191 ( V_7 ) ;
if ( V_23 < 0 )
goto V_31;
if ( V_7 -> V_72 . V_81 & V_363 ) {
V_23 = F_192 ( V_7 ) ;
if ( V_23 < 0 )
goto V_31;
}
V_7 -> V_72 . V_83 = 0 ;
V_7 -> V_72 . V_84 = 0 ;
V_23 = F_198 ( V_7 , & V_174 ) ;
if ( V_23 )
goto V_31;
V_7 -> V_72 . V_234 = V_174 ;
V_7 -> V_56 = 2 ;
F_11 ( L_86 ,
V_7 -> V_226 ) ;
return 0 ;
V_31:
V_7 -> V_300 = 0 ;
F_171 ( V_7 -> V_297 ) ;
V_7 -> V_297 = NULL ;
F_22 ( V_7 -> V_226 ) ;
V_7 -> V_226 = NULL ;
F_22 ( V_7 -> V_72 . V_75 ) ;
V_7 -> V_72 . V_75 = NULL ;
return V_23 ;
}
static int F_224 ( struct V_6 * V_7 )
{
int V_23 ;
V_23 = F_138 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_196 ( V_7 ) ;
if ( V_23 )
goto V_364;
V_23 = F_51 ( V_7 ) ;
if ( V_23 )
goto V_364;
F_209 ( V_7 ) ;
F_225 ( V_365
< sizeof ( V_229 ) + V_366 ) ;
sprintf ( V_7 -> V_96 , L_87 , V_229 , V_7 -> V_286 ) ;
V_23 = F_226 ( 0 , V_7 -> V_96 ) ;
if ( V_23 < 0 )
goto V_367;
V_7 -> V_230 = V_23 ;
V_23 = F_142 ( V_7 ) ;
if ( V_23 )
goto V_368;
V_23 = F_206 ( V_7 ) ;
if ( V_23 )
goto V_369;
F_137 ( & V_7 -> V_262 ) ;
V_23 = F_139 ( V_7 ) ;
F_140 ( & V_7 -> V_262 ) ;
if ( V_23 )
goto V_370;
V_23 = F_208 ( V_7 ) ;
if ( V_23 )
goto V_370;
F_227 ( V_7 -> V_18 ) ;
F_228 ( L_88 , V_7 -> V_18 -> V_285 ,
( unsigned long long ) V_7 -> V_11 . V_59 ) ;
return V_23 ;
V_370:
F_207 ( V_7 ) ;
return V_23 ;
V_369:
F_125 ( V_7 ) ;
V_368:
F_229 ( V_7 -> V_230 , V_7 -> V_96 ) ;
V_367:
F_211 ( V_7 ) ;
V_364:
F_131 ( V_7 ) ;
return V_23 ;
}
static int F_230 ( struct V_6 * V_7 )
{
int V_23 ;
V_23 = F_221 ( V_7 ) ;
if ( V_23 )
V_23 = F_222 ( V_7 ) ;
else
V_23 = F_223 ( V_7 ) ;
if ( V_23 ) {
F_11 ( L_89 , V_23 ) ;
return V_23 ;
}
V_23 = F_224 ( V_7 ) ;
if ( V_23 )
F_52 ( & V_7 -> V_72 ) ;
return V_23 ;
}
static T_9 F_231 ( struct V_371 * V_338 ,
const char * V_120 ,
T_4 V_298 )
{
struct V_6 * V_7 = NULL ;
struct V_20 * V_21 = NULL ;
struct V_40 * V_41 = NULL ;
struct V_296 * V_98 = NULL ;
struct V_19 * V_22 ;
struct V_184 * V_185 ;
int V_158 = - V_24 ;
if ( ! F_232 ( V_372 ) )
return - V_373 ;
V_158 = F_219 ( V_120 , & V_21 , & V_41 , & V_98 ) ;
if ( V_158 < 0 )
goto V_374;
V_22 = F_33 ( V_21 ) ;
if ( F_16 ( V_22 ) ) {
V_158 = F_98 ( V_22 ) ;
goto V_375;
}
V_21 = NULL ;
V_185 = & V_22 -> V_29 -> V_185 ;
V_158 = F_233 ( V_185 -> V_330 , V_98 -> V_294 ) ;
if ( V_158 < 0 )
goto V_376;
V_98 -> V_200 = ( V_69 ) V_158 ;
V_7 = F_173 ( V_22 , V_98 ) ;
if ( ! V_7 )
goto V_376;
V_22 = NULL ;
V_98 = NULL ;
V_7 -> V_11 . V_12 = V_41 -> V_12 ;
F_22 ( V_41 ) ;
V_41 = NULL ;
V_158 = F_230 ( V_7 ) ;
if ( V_158 < 0 )
goto V_377;
return V_298 ;
V_377:
F_176 ( V_7 ) ;
V_376:
F_37 ( V_22 ) ;
V_375:
if ( V_21 )
F_23 ( V_21 ) ;
F_22 ( V_41 ) ;
F_171 ( V_98 ) ;
V_374:
F_234 ( V_372 ) ;
F_11 ( L_90 , V_120 ) ;
return ( T_9 ) V_158 ;
}
static struct V_6 * F_235 ( unsigned long V_286 )
{
struct V_334 * V_115 ;
struct V_6 * V_7 ;
F_18 ( & V_344 ) ;
F_236 (tmp, &rbd_dev_list) {
V_7 = F_205 ( V_115 , struct V_6 , V_28 ) ;
if ( V_7 -> V_286 == V_286 ) {
F_20 ( & V_344 ) ;
return V_7 ;
}
}
F_20 ( & V_344 ) ;
return NULL ;
}
static void V_342 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_151 ( V_2 ) ;
if ( V_7 -> V_235 ) {
struct V_378 * V_29 = V_7 -> V_19 -> V_29 ;
F_237 ( & V_29 -> V_185 ,
V_7 -> V_235 ) ;
}
if ( V_7 -> V_232 )
F_111 ( V_7 ) ;
F_125 ( V_7 ) ;
F_229 ( V_7 -> V_230 , V_7 -> V_96 ) ;
F_52 ( & V_7 -> V_72 ) ;
F_211 ( V_7 ) ;
F_8 ( V_7 -> V_19 != NULL ) ;
F_176 ( V_7 ) ;
F_234 ( V_372 ) ;
}
static T_9 F_238 ( struct V_371 * V_338 ,
const char * V_120 ,
T_4 V_298 )
{
struct V_6 * V_7 = NULL ;
int V_379 , V_158 ;
unsigned long V_380 ;
int V_23 = V_298 ;
V_158 = F_239 ( V_120 , 10 , & V_380 ) ;
if ( V_158 )
return V_158 ;
V_379 = ( int ) V_380 ;
if ( V_379 != V_380 )
return - V_47 ;
F_3 ( & V_14 , V_15 ) ;
V_7 = F_235 ( V_379 ) ;
if ( ! V_7 ) {
V_23 = - V_99 ;
goto V_100;
}
if ( V_7 -> V_16 ) {
V_23 = - V_381 ;
goto V_100;
}
F_131 ( V_7 ) ;
F_207 ( V_7 ) ;
V_100:
F_6 ( & V_14 ) ;
return V_23 ;
}
static int F_240 ( void )
{
int V_23 ;
V_23 = F_182 ( & V_341 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_241 ( & V_339 ) ;
if ( V_23 < 0 )
F_179 ( & V_341 ) ;
return V_23 ;
}
static void F_242 ( void )
{
F_243 ( & V_339 ) ;
F_179 ( & V_341 ) ;
}
int T_10 F_244 ( void )
{
int V_158 ;
V_158 = F_240 () ;
if ( V_158 )
return V_158 ;
F_228 ( L_91 V_382 L_92 ) ;
return 0 ;
}
void T_11 F_245 ( void )
{
F_242 () ;
}
