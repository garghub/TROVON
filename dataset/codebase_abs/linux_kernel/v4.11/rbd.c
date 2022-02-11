static int F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
V_2 = ( unsigned int ) F_2 ( V_1 , 1 , 0 ) ;
if ( V_2 <= ( unsigned int ) V_3 )
return ( int ) V_2 ;
F_3 ( V_1 ) ;
return - V_4 ;
}
static int F_4 ( T_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 ) ;
if ( V_2 >= 0 )
return V_2 ;
F_6 ( V_1 ) ;
return - V_4 ;
}
static int F_7 ( int V_5 )
{
return V_5 << V_6 ;
}
static int F_8 ( int V_7 )
{
return V_7 >> V_6 ;
}
static bool F_9 ( struct V_8 * V_9 )
{
return ( V_9 -> V_10 . V_11 & V_12 ) &&
V_9 -> V_13 -> V_14 == V_15 &&
! V_9 -> V_16 . V_17 ;
}
static bool F_10 ( struct V_8 * V_9 )
{
return V_9 -> V_18 == V_19 ||
V_9 -> V_18 == V_20 ;
}
static bool F_11 ( struct V_8 * V_9 )
{
bool V_21 ;
F_12 ( & V_9 -> V_22 ) ;
V_21 = F_10 ( V_9 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_21 ;
}
static T_2 F_14 ( struct V_23 * V_24 , char * V_25 )
{
return sprintf ( V_25 , L_1 , V_26 ) ;
}
static T_3 F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 , int V_31 )
{
if ( ! V_32 &&
( V_30 == & V_33 . V_30 ||
V_30 == & V_34 . V_30 ) )
return 0 ;
return V_30 -> V_35 ;
}
static void F_16 ( struct V_36 * V_37 )
{
}
static int F_17 ( struct V_38 * V_39 , T_4 V_35 )
{
struct V_8 * V_9 = V_39 -> V_40 -> V_41 ;
bool V_42 = false ;
if ( ( V_35 & V_43 ) && V_9 -> V_16 . V_17 )
return - V_44 ;
F_18 ( & V_9 -> V_45 ) ;
if ( F_19 ( V_46 , & V_9 -> V_47 ) )
V_42 = true ;
else
V_9 -> V_48 ++ ;
F_20 ( & V_9 -> V_45 ) ;
if ( V_42 )
return - V_49 ;
( void ) F_21 ( & V_9 -> V_37 ) ;
return 0 ;
}
static void F_22 ( struct V_50 * V_51 , T_4 V_35 )
{
struct V_8 * V_9 = V_51 -> V_41 ;
unsigned long V_52 ;
F_18 ( & V_9 -> V_45 ) ;
V_52 = V_9 -> V_48 -- ;
F_20 ( & V_9 -> V_45 ) ;
F_23 ( V_52 > 0 ) ;
F_24 ( & V_9 -> V_37 ) ;
}
static int F_25 ( struct V_8 * V_9 , unsigned long V_53 )
{
int V_54 = 0 ;
int V_55 ;
bool V_56 ;
bool V_57 = false ;
if ( F_26 ( V_55 , ( int V_58 * ) ( V_53 ) ) )
return - V_59 ;
V_56 = V_55 ? true : false ;
if ( V_9 -> V_13 -> V_14 != V_15 && ! V_56 )
return - V_44 ;
F_18 ( & V_9 -> V_45 ) ;
if ( V_9 -> V_48 > 1 ) {
V_54 = - V_60 ;
goto V_61;
}
if ( V_9 -> V_16 . V_17 != V_56 ) {
V_9 -> V_16 . V_17 = V_56 ;
V_57 = true ;
}
V_61:
F_20 ( & V_9 -> V_45 ) ;
if ( V_54 == 0 && V_57 )
F_27 ( V_9 -> V_51 , V_56 ? 1 : 0 ) ;
return V_54 ;
}
static int F_28 ( struct V_38 * V_39 , T_4 V_35 ,
unsigned int V_62 , unsigned long V_53 )
{
struct V_8 * V_9 = V_39 -> V_40 -> V_41 ;
int V_54 = 0 ;
switch ( V_62 ) {
case V_63 :
V_54 = F_25 ( V_9 , V_53 ) ;
break;
default:
V_54 = - V_64 ;
}
return V_54 ;
}
static int F_29 ( struct V_38 * V_39 , T_4 V_35 ,
unsigned int V_62 , unsigned long V_53 )
{
return F_28 ( V_39 , V_35 , V_62 , V_53 ) ;
}
static struct V_65 * F_30 ( struct V_66 * V_67 )
{
struct V_65 * V_68 ;
int V_54 = - V_69 ;
F_31 ( L_2 , V_70 ) ;
V_68 = F_32 ( sizeof( struct V_65 ) , V_71 ) ;
if ( ! V_68 )
goto V_72;
F_33 ( & V_68 -> V_73 ) ;
F_34 ( & V_68 -> V_74 ) ;
V_68 -> V_75 = F_35 ( V_67 , V_68 , 0 , 0 ) ;
if ( F_36 ( V_68 -> V_75 ) )
goto V_76;
V_67 = NULL ;
V_54 = F_37 ( V_68 -> V_75 ) ;
if ( V_54 < 0 )
goto V_77;
F_38 ( & V_78 ) ;
F_39 ( & V_68 -> V_74 , & V_79 ) ;
F_40 ( & V_78 ) ;
F_31 ( L_3 , V_70 , V_68 ) ;
return V_68 ;
V_77:
F_41 ( V_68 -> V_75 ) ;
V_76:
F_42 ( V_68 ) ;
V_72:
if ( V_67 )
F_43 ( V_67 ) ;
F_31 ( L_4 , V_70 , V_54 ) ;
return F_44 ( V_54 ) ;
}
static struct V_65 * F_45 ( struct V_65 * V_68 )
{
F_46 ( & V_68 -> V_73 ) ;
return V_68 ;
}
static struct V_65 * F_47 ( struct V_66 * V_67 )
{
struct V_65 * V_80 ;
bool V_81 = false ;
if ( V_67 -> V_47 & V_82 )
return NULL ;
F_38 ( & V_78 ) ;
F_48 (client_node, &rbd_client_list, node) {
if ( ! F_49 ( V_67 , V_80 -> V_75 ) ) {
F_45 ( V_80 ) ;
V_81 = true ;
break;
}
}
F_40 ( & V_78 ) ;
return V_81 ? V_80 : NULL ;
}
static int F_50 ( char * V_83 , void * V_84 )
{
struct V_85 * V_86 = V_84 ;
T_5 V_87 [ V_88 ] ;
int V_89 , V_90 , V_54 ;
V_89 = F_51 ( V_83 , V_91 , V_87 ) ;
if ( V_89 < V_92 ) {
V_54 = F_52 ( & V_87 [ 0 ] , & V_90 ) ;
if ( V_54 < 0 ) {
F_53 ( L_5 , V_83 ) ;
return V_54 ;
}
F_31 ( L_6 , V_89 , V_90 ) ;
} else if ( V_89 > V_92 && V_89 < V_93 ) {
F_31 ( L_7 , V_89 , V_87 [ 0 ] . V_94 ) ;
} else {
F_31 ( L_8 , V_89 ) ;
}
switch ( V_89 ) {
case V_95 :
if ( V_90 < 1 ) {
F_53 ( L_9 ) ;
return - V_4 ;
}
V_86 -> V_96 = V_90 ;
break;
case V_97 :
V_86 -> V_17 = true ;
break;
case V_98 :
V_86 -> V_17 = false ;
break;
case V_99 :
V_86 -> V_100 = true ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static char * F_54 ( enum V_101 V_102 )
{
switch ( V_102 ) {
case V_103 :
return L_10 ;
case V_104 :
return L_11 ;
case V_105 :
return L_12 ;
default:
return L_13 ;
}
}
static struct V_65 * F_55 ( struct V_66 * V_67 )
{
struct V_65 * V_68 ;
F_56 ( & V_106 , V_107 ) ;
V_68 = F_47 ( V_67 ) ;
if ( V_68 )
F_43 ( V_67 ) ;
else
V_68 = F_30 ( V_67 ) ;
F_57 ( & V_106 ) ;
return V_68 ;
}
static void F_58 ( struct V_73 * V_73 )
{
struct V_65 * V_68 = F_59 ( V_73 , struct V_65 , V_73 ) ;
F_31 ( L_3 , V_70 , V_68 ) ;
F_38 ( & V_78 ) ;
F_60 ( & V_68 -> V_74 ) ;
F_40 ( & V_78 ) ;
F_41 ( V_68 -> V_75 ) ;
F_42 ( V_68 ) ;
}
static void F_61 ( struct V_65 * V_68 )
{
if ( V_68 )
F_62 ( & V_68 -> V_73 , F_58 ) ;
}
static bool F_63 ( T_6 V_108 )
{
return V_108 == 1 || V_108 == 2 ;
}
static bool F_64 ( struct V_109 * V_110 )
{
T_7 V_111 ;
T_6 V_112 ;
if ( memcmp ( & V_110 -> V_113 , V_114 , sizeof ( V_114 ) ) )
return false ;
if ( V_110 -> V_115 . V_116 < V_117 )
return false ;
if ( V_110 -> V_115 . V_116 > 8 * sizeof ( int ) - 1 )
return false ;
V_112 = F_65 ( V_110 -> V_112 ) ;
V_111 = V_118 - sizeof ( struct V_119 ) ;
if ( V_112 > V_111 / sizeof ( V_120 ) )
return false ;
V_111 -= V_112 * sizeof ( V_120 ) ;
if ( ( V_121 ) V_111 < F_66 ( V_110 -> V_122 ) )
return false ;
return true ;
}
static T_6 F_67 ( struct V_123 * V_10 )
{
return 1U << V_10 -> V_124 ;
}
static void F_68 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 . V_125 == 0 ||
V_9 -> V_10 . V_126 == 0 ) {
V_9 -> V_10 . V_125 = F_67 ( & V_9 -> V_10 ) ;
V_9 -> V_10 . V_126 = 1 ;
}
V_9 -> V_127 . V_125 = V_9 -> V_10 . V_125 ;
V_9 -> V_127 . V_126 = V_9 -> V_10 . V_126 ;
V_9 -> V_127 . V_128 = F_67 ( & V_9 -> V_10 ) ;
V_9 -> V_127 . V_129 = V_9 -> V_10 . V_130 == V_131 ?
V_9 -> V_13 -> V_129 : V_9 -> V_10 . V_130 ;
F_69 ( V_9 -> V_127 . V_132 , NULL ) ;
}
static int F_70 ( struct V_8 * V_9 ,
struct V_109 * V_110 )
{
struct V_123 * V_10 = & V_9 -> V_10 ;
bool V_133 = V_10 -> V_134 == NULL ;
struct V_119 * V_135 ;
char * V_134 = NULL ;
char * V_136 = NULL ;
V_121 * V_137 = NULL ;
T_6 V_112 ;
int V_54 = - V_69 ;
T_6 V_138 ;
if ( V_133 ) {
V_134 = F_71 ( V_110 -> V_134 ,
sizeof( V_110 -> V_134 ) ,
V_71 ) ;
if ( ! V_134 )
return - V_69 ;
}
V_112 = F_65 ( V_110 -> V_112 ) ;
V_135 = F_72 ( V_112 , V_71 ) ;
if ( ! V_135 )
goto V_139;
V_135 -> V_140 = F_66 ( V_110 -> V_141 ) ;
if ( V_112 ) {
struct V_142 * V_143 ;
V_121 V_122 = F_66 ( V_110 -> V_122 ) ;
if ( V_122 > ( V_121 ) V_118 )
goto V_144;
V_136 = F_32 ( V_122 , V_71 ) ;
if ( ! V_136 )
goto V_139;
V_137 = F_73 ( V_112 ,
sizeof( * V_10 -> V_137 ) ,
V_71 ) ;
if ( ! V_137 )
goto V_139;
memcpy ( V_136 , & V_110 -> V_143 [ V_112 ] , V_122 ) ;
V_143 = V_110 -> V_143 ;
for ( V_138 = 0 ; V_138 < V_112 ; V_138 ++ ) {
V_135 -> V_143 [ V_138 ] = F_66 ( V_143 [ V_138 ] . V_145 ) ;
V_137 [ V_138 ] = F_66 ( V_143 [ V_138 ] . V_146 ) ;
}
}
if ( V_133 ) {
V_10 -> V_134 = V_134 ;
V_10 -> V_124 = V_110 -> V_115 . V_116 ;
F_68 ( V_9 ) ;
} else {
F_74 ( V_10 -> V_135 ) ;
F_42 ( V_10 -> V_136 ) ;
F_42 ( V_10 -> V_137 ) ;
}
V_10 -> V_146 = F_66 ( V_110 -> V_146 ) ;
V_10 -> V_135 = V_135 ;
V_10 -> V_136 = V_136 ;
V_10 -> V_137 = V_137 ;
return 0 ;
V_144:
V_54 = - V_147 ;
V_139:
F_42 ( V_137 ) ;
F_42 ( V_136 ) ;
F_74 ( V_135 ) ;
F_42 ( V_134 ) ;
return V_54 ;
}
static const char * F_75 ( struct V_8 * V_9 , T_6 V_148 )
{
const char * V_149 ;
F_23 ( V_148 < V_9 -> V_10 . V_135 -> V_150 ) ;
V_149 = V_9 -> V_10 . V_136 ;
while ( V_148 -- )
V_149 += strlen ( V_149 ) + 1 ;
return F_76 ( V_149 , V_71 ) ;
}
static int F_77 ( const void * V_151 , const void * V_152 )
{
V_121 V_153 = * ( V_121 * ) V_151 ;
V_121 V_154 = * ( V_121 * ) V_152 ;
if ( V_153 < V_154 )
return 1 ;
return V_153 == V_154 ? 0 : - 1 ;
}
static T_6 F_78 ( struct V_8 * V_9 , V_121 V_14 )
{
struct V_119 * V_135 = V_9 -> V_10 . V_135 ;
V_121 * V_81 ;
V_81 = bsearch ( & V_14 , & V_135 -> V_143 , V_135 -> V_150 ,
sizeof ( V_14 ) , F_77 ) ;
return V_81 ? ( T_6 ) ( V_81 - & V_135 -> V_143 [ 0 ] ) : V_155 ;
}
static const char * F_79 ( struct V_8 * V_9 ,
V_121 V_14 )
{
T_6 V_148 ;
const char * V_149 ;
V_148 = F_78 ( V_9 , V_14 ) ;
if ( V_148 == V_155 )
return F_44 ( - V_49 ) ;
V_149 = F_75 ( V_9 , V_148 ) ;
return V_149 ? V_149 : F_44 ( - V_69 ) ;
}
static const char * F_80 ( struct V_8 * V_9 , V_121 V_14 )
{
if ( V_14 == V_15 )
return V_156 ;
F_23 ( F_63 ( V_9 -> V_108 ) ) ;
if ( V_9 -> V_108 == 1 )
return F_79 ( V_9 , V_14 ) ;
return F_81 ( V_9 , V_14 ) ;
}
static int F_82 ( struct V_8 * V_9 , V_121 V_14 ,
V_121 * V_157 )
{
F_23 ( F_63 ( V_9 -> V_108 ) ) ;
if ( V_14 == V_15 ) {
* V_157 = V_9 -> V_10 . V_146 ;
} else if ( V_9 -> V_108 == 1 ) {
T_6 V_148 ;
V_148 = F_78 ( V_9 , V_14 ) ;
if ( V_148 == V_155 )
return - V_49 ;
* V_157 = V_9 -> V_10 . V_137 [ V_148 ] ;
} else {
V_121 V_111 = 0 ;
int V_54 ;
V_54 = F_83 ( V_9 , V_14 , NULL , & V_111 ) ;
if ( V_54 )
return V_54 ;
* V_157 = V_111 ;
}
return 0 ;
}
static int F_84 ( struct V_8 * V_9 , V_121 V_14 ,
V_121 * V_158 )
{
F_23 ( F_63 ( V_9 -> V_108 ) ) ;
if ( V_14 == V_15 ) {
* V_158 = V_9 -> V_10 . V_11 ;
} else if ( V_9 -> V_108 == 1 ) {
* V_158 = 0 ;
} else {
V_121 V_11 = 0 ;
int V_54 ;
V_54 = F_85 ( V_9 , V_14 , & V_11 ) ;
if ( V_54 )
return V_54 ;
* V_158 = V_11 ;
}
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
V_121 V_14 = V_9 -> V_13 -> V_14 ;
V_121 V_111 = 0 ;
V_121 V_11 = 0 ;
int V_54 ;
V_54 = F_82 ( V_9 , V_14 , & V_111 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_84 ( V_9 , V_14 , & V_11 ) ;
if ( V_54 )
return V_54 ;
V_9 -> V_16 . V_111 = V_111 ;
V_9 -> V_16 . V_11 = V_11 ;
return 0 ;
}
static void F_87 ( struct V_8 * V_9 )
{
V_9 -> V_16 . V_111 = 0 ;
V_9 -> V_16 . V_11 = 0 ;
}
static V_121 F_88 ( struct V_8 * V_9 , V_121 V_159 )
{
V_121 V_160 = F_67 ( & V_9 -> V_10 ) ;
return V_159 & ( V_160 - 1 ) ;
}
static V_121 F_89 ( struct V_8 * V_9 ,
V_121 V_159 , V_121 V_161 )
{
V_121 V_160 = F_67 ( & V_9 -> V_10 ) ;
V_159 &= V_160 - 1 ;
F_23 ( V_161 <= V_162 - V_159 ) ;
if ( V_159 + V_161 > V_160 )
V_161 = V_160 - V_159 ;
return V_161 ;
}
static void F_90 ( struct V_163 * V_164 )
{
struct V_163 * V_165 ;
while ( V_164 ) {
V_165 = V_164 ;
V_164 = V_164 -> V_166 ;
F_91 ( V_165 ) ;
}
}
static void F_92 ( struct V_163 * V_164 , int V_167 )
{
struct V_168 V_169 ;
struct V_170 V_171 ;
unsigned long V_47 ;
void * V_25 ;
int V_172 = 0 ;
while ( V_164 ) {
F_93 (bv, chain, iter) {
if ( V_172 + V_169 . V_173 > V_167 ) {
int V_174 = F_94 ( V_167 - V_172 , 0 ) ;
V_25 = F_95 ( & V_169 , & V_47 ) ;
memset ( V_25 + V_174 , 0 ,
V_169 . V_173 - V_174 ) ;
F_96 ( V_169 . V_175 ) ;
F_97 ( V_25 , & V_47 ) ;
}
V_172 += V_169 . V_173 ;
}
V_164 = V_164 -> V_166 ;
}
}
static void F_98 ( struct V_176 * * V_177 , V_121 V_159 , V_121 V_178 )
{
struct V_176 * * V_176 = & V_177 [ V_159 >> V_179 ] ;
F_23 ( V_178 > V_159 ) ;
F_23 ( V_178 - V_159 <= ( V_121 ) V_118 ) ;
while ( V_159 < V_178 ) {
T_7 V_180 ;
T_7 V_161 ;
unsigned long V_47 ;
void * V_181 ;
V_180 = V_159 & ~ V_182 ;
V_161 = F_99 ( T_7 , V_183 - V_180 , V_178 - V_159 ) ;
F_100 ( V_47 ) ;
V_181 = F_101 ( * V_176 ) ;
memset ( V_181 + V_180 , 0 , V_161 ) ;
F_96 ( * V_176 ) ;
F_102 ( V_181 ) ;
F_103 ( V_47 ) ;
V_159 += V_161 ;
V_176 ++ ;
}
}
static struct V_163 * F_104 ( struct V_163 * V_184 ,
unsigned int V_159 ,
unsigned int V_185 ,
T_8 V_186 )
{
struct V_163 * V_163 ;
V_163 = F_105 ( V_184 , V_186 ) ;
if ( ! V_163 )
return NULL ;
F_106 ( V_163 , V_159 ) ;
V_163 -> V_187 . V_188 = V_185 ;
return V_163 ;
}
static struct V_163 * F_107 ( struct V_163 * * V_184 ,
unsigned int * V_159 ,
unsigned int V_185 ,
T_8 V_186 )
{
struct V_163 * V_189 = * V_184 ;
unsigned int V_190 = * V_159 ;
struct V_163 * V_164 = NULL ;
struct V_163 * * V_178 ;
if ( ! V_189 || V_190 >= V_189 -> V_187 . V_188 || ! V_185 )
return NULL ;
V_178 = & V_164 ;
while ( V_185 ) {
unsigned int V_188 ;
struct V_163 * V_163 ;
if ( ! V_189 ) {
F_108 ( NULL , L_14 , V_185 ) ;
goto V_139;
}
V_188 = F_99 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_163 = F_104 ( V_189 , V_190 , V_188 , V_186 ) ;
if ( ! V_163 )
goto V_139;
* V_178 = V_163 ;
V_178 = & V_163 -> V_166 ;
V_190 += V_188 ;
if ( V_190 == V_189 -> V_187 . V_188 ) {
V_189 = V_189 -> V_166 ;
V_190 = 0 ;
}
V_185 -= V_188 ;
}
* V_184 = V_189 ;
* V_159 = V_190 ;
return V_164 ;
V_139:
F_90 ( V_164 ) ;
return NULL ;
}
static void F_109 ( struct V_191 * V_192 )
{
if ( F_110 ( V_193 , & V_192 -> V_47 ) ) {
struct V_8 * V_9 ;
V_9 = V_192 -> V_194 -> V_9 ;
F_108 ( V_9 , L_15 ,
V_192 ) ;
}
}
static bool F_111 ( struct V_191 * V_192 )
{
F_112 () ;
return F_19 ( V_193 , & V_192 -> V_47 ) != 0 ;
}
static void F_113 ( struct V_191 * V_192 )
{
if ( F_110 ( V_195 , & V_192 -> V_47 ) ) {
struct V_8 * V_9 = NULL ;
if ( F_111 ( V_192 ) )
V_9 = V_192 -> V_194 -> V_9 ;
F_108 ( V_9 , L_16 ,
V_192 ) ;
}
}
static bool F_114 ( struct V_191 * V_192 )
{
F_112 () ;
return F_19 ( V_195 , & V_192 -> V_47 ) != 0 ;
}
static void F_115 ( struct V_191 * V_192 ,
bool V_196 )
{
if ( V_196 )
F_116 ( V_197 , & V_192 -> V_47 ) ;
F_116 ( V_198 , & V_192 -> V_47 ) ;
F_112 () ;
}
static bool F_117 ( struct V_191 * V_192 )
{
F_112 () ;
return F_19 ( V_198 , & V_192 -> V_47 ) != 0 ;
}
static bool F_118 ( struct V_191 * V_192 )
{
F_112 () ;
return F_19 ( V_197 , & V_192 -> V_47 ) != 0 ;
}
static bool F_119 ( struct V_191 * V_192 )
{
struct V_8 * V_9 = V_192 -> V_194 -> V_9 ;
return V_192 -> V_199 <
F_120 ( V_9 -> V_200 , F_67 ( & V_9 -> V_10 ) ) ;
}
static void F_121 ( struct V_191 * V_192 )
{
F_31 ( L_17 , V_70 , V_192 ,
F_122 ( & V_192 -> V_73 ) ) ;
F_46 ( & V_192 -> V_73 ) ;
}
static void F_123 ( struct V_191 * V_192 )
{
F_23 ( V_192 != NULL ) ;
F_31 ( L_17 , V_70 , V_192 ,
F_122 ( & V_192 -> V_73 ) ) ;
F_62 ( & V_192 -> V_73 , V_201 ) ;
}
static void F_124 ( struct V_202 * V_194 )
{
F_31 ( L_18 , V_70 , V_194 ,
F_122 ( & V_194 -> V_73 ) ) ;
F_46 ( & V_194 -> V_73 ) ;
}
static void F_125 ( struct V_202 * V_194 )
{
F_23 ( V_194 != NULL ) ;
F_31 ( L_18 , V_70 , V_194 ,
F_122 ( & V_194 -> V_73 ) ) ;
if ( F_126 ( V_194 ) )
F_62 ( & V_194 -> V_73 , V_203 ) ;
else
F_62 ( & V_194 -> V_73 , V_204 ) ;
}
static inline void F_127 ( struct V_202 * V_194 ,
struct V_191 * V_192 )
{
F_23 ( V_192 -> V_194 == NULL ) ;
V_192 -> V_194 = V_194 ;
V_192 -> V_148 = V_194 -> V_205 ;
F_23 ( ! F_111 ( V_192 ) ) ;
F_109 ( V_192 ) ;
F_23 ( V_192 -> V_148 != V_206 ) ;
V_194 -> V_205 ++ ;
F_39 ( & V_192 -> V_207 , & V_194 -> V_208 ) ;
F_31 ( L_19 , V_70 , V_194 , V_192 ,
V_192 -> V_148 ) ;
}
static inline void F_128 ( struct V_202 * V_194 ,
struct V_191 * V_192 )
{
F_23 ( V_192 -> V_148 != V_206 ) ;
F_31 ( L_19 , V_70 , V_194 , V_192 ,
V_192 -> V_148 ) ;
F_60 ( & V_192 -> V_207 ) ;
F_23 ( V_194 -> V_205 > 0 ) ;
V_194 -> V_205 -- ;
F_23 ( V_192 -> V_148 == V_194 -> V_205 ) ;
V_192 -> V_148 = V_206 ;
F_23 ( F_111 ( V_192 ) ) ;
F_23 ( V_192 -> V_194 == V_194 ) ;
V_192 -> V_194 = NULL ;
V_192 -> V_209 = NULL ;
F_123 ( V_192 ) ;
}
static bool F_129 ( enum V_210 type )
{
switch ( type ) {
case V_211 :
case V_212 :
case V_213 :
return true ;
default:
return false ;
}
}
static void F_130 ( struct V_191 * V_192 )
{
struct V_214 * V_215 = V_192 -> V_215 ;
F_31 ( L_20 , V_70 ,
V_192 , V_192 -> V_216 , V_192 -> V_159 ,
V_192 -> V_161 , V_215 ) ;
if ( F_111 ( V_192 ) ) {
F_131 ( V_192 -> V_209 != V_217 ) ;
F_124 ( V_192 -> V_194 ) ;
}
F_132 ( V_215 -> V_218 , V_215 , false ) ;
}
static void F_133 ( struct V_202 * V_194 )
{
F_31 ( L_21 , V_70 , V_194 ) ;
if ( ! V_194 -> V_219 ) {
struct V_191 * V_192 ;
V_121 V_220 = 0 ;
F_134 (img_request, obj_request)
V_220 += V_192 -> V_220 ;
V_194 -> V_220 = V_220 ;
}
if ( V_194 -> V_209 )
V_194 -> V_209 ( V_194 ) ;
else
F_125 ( V_194 ) ;
}
static void F_135 ( struct V_202 * V_194 )
{
F_116 ( V_221 , & V_194 -> V_47 ) ;
F_112 () ;
}
static bool F_136 ( struct V_202 * V_194 )
{
F_112 () ;
return F_19 ( V_221 , & V_194 -> V_47 ) != 0 ;
}
static void F_137 ( struct V_202 * V_194 )
{
F_116 ( V_222 , & V_194 -> V_47 ) ;
F_112 () ;
}
static bool F_138 ( struct V_202 * V_194 )
{
F_112 () ;
return F_19 ( V_222 , & V_194 -> V_47 ) != 0 ;
}
static void F_139 ( struct V_202 * V_194 )
{
F_116 ( V_223 , & V_194 -> V_47 ) ;
F_112 () ;
}
static void F_140 ( struct V_202 * V_194 )
{
F_141 ( V_223 , & V_194 -> V_47 ) ;
F_112 () ;
}
static bool F_126 ( struct V_202 * V_194 )
{
F_112 () ;
return F_19 ( V_223 , & V_194 -> V_47 ) != 0 ;
}
static void F_142 ( struct V_202 * V_194 )
{
F_116 ( V_224 , & V_194 -> V_47 ) ;
F_112 () ;
}
static void F_143 ( struct V_202 * V_194 )
{
F_141 ( V_224 , & V_194 -> V_47 ) ;
F_112 () ;
}
static bool F_144 ( struct V_202 * V_194 )
{
F_112 () ;
return F_19 ( V_224 , & V_194 -> V_47 ) != 0 ;
}
static enum V_101
F_145 ( struct V_202 * V_194 )
{
if ( F_136 ( V_194 ) )
return V_104 ;
else if ( F_138 ( V_194 ) )
return V_105 ;
else
return V_103 ;
}
static void
F_146 ( struct V_191 * V_192 )
{
V_121 V_220 = V_192 -> V_220 ;
V_121 V_161 = V_192 -> V_161 ;
F_31 ( L_22 , V_70 ,
V_192 , V_192 -> V_194 , V_192 -> V_219 ,
V_220 , V_161 ) ;
F_23 ( V_192 -> type != V_211 ) ;
if ( V_192 -> V_219 == - V_49 ) {
if ( V_192 -> type == V_212 )
F_92 ( V_192 -> V_225 , 0 ) ;
else
F_98 ( V_192 -> V_177 , 0 , V_161 ) ;
V_192 -> V_219 = 0 ;
} else if ( V_220 < V_161 && ! V_192 -> V_219 ) {
if ( V_192 -> type == V_212 )
F_92 ( V_192 -> V_225 , V_220 ) ;
else
F_98 ( V_192 -> V_177 , V_220 , V_161 ) ;
}
V_192 -> V_220 = V_161 ;
F_113 ( V_192 ) ;
}
static void F_147 ( struct V_191 * V_192 )
{
F_31 ( L_23 , V_70 , V_192 ,
V_192 -> V_209 ) ;
if ( V_192 -> V_209 )
V_192 -> V_209 ( V_192 ) ;
else
F_148 ( & V_192 -> V_226 ) ;
}
static void F_149 ( struct V_191 * V_192 , int V_227 )
{
V_192 -> V_219 = V_227 ;
V_192 -> V_220 = 0 ;
if ( F_111 ( V_192 ) ) {
F_131 ( V_192 -> V_209 != V_217 ) ;
F_124 ( V_192 -> V_194 ) ;
}
F_113 ( V_192 ) ;
F_147 ( V_192 ) ;
}
static void F_150 ( struct V_191 * V_192 )
{
struct V_202 * V_194 = NULL ;
struct V_8 * V_9 = NULL ;
bool V_228 = false ;
if ( F_111 ( V_192 ) ) {
V_194 = V_192 -> V_194 ;
V_228 = V_194 && F_144 ( V_194 ) ;
V_9 = V_194 -> V_9 ;
}
F_31 ( L_22 , V_70 ,
V_192 , V_194 , V_192 -> V_219 ,
V_192 -> V_220 , V_192 -> V_161 ) ;
if ( V_228 && V_192 -> V_219 == - V_49 &&
V_192 -> V_199 < V_9 -> V_200 )
F_151 ( V_192 ) ;
else if ( V_194 )
F_146 ( V_192 ) ;
else
F_113 ( V_192 ) ;
}
static void F_152 ( struct V_191 * V_192 )
{
F_31 ( L_24 , V_70 , V_192 ,
V_192 -> V_219 , V_192 -> V_161 ) ;
V_192 -> V_220 = V_192 -> V_161 ;
F_113 ( V_192 ) ;
}
static void F_153 ( struct V_191 * V_192 )
{
F_31 ( L_24 , V_70 , V_192 ,
V_192 -> V_219 , V_192 -> V_161 ) ;
V_192 -> V_220 = V_192 -> V_161 ;
if ( V_192 -> V_219 == - V_49 )
V_192 -> V_219 = 0 ;
F_113 ( V_192 ) ;
}
static void F_154 ( struct V_191 * V_192 )
{
F_31 ( L_25 , V_70 , V_192 ) ;
F_113 ( V_192 ) ;
}
static void F_155 ( struct V_191 * V_192 )
{
F_31 ( L_25 , V_70 , V_192 ) ;
if ( F_111 ( V_192 ) )
F_156 ( V_192 ) ;
else
F_113 ( V_192 ) ;
}
static void F_157 ( struct V_214 * V_215 )
{
struct V_191 * V_192 = V_215 -> V_229 ;
T_9 V_230 ;
F_31 ( L_26 , V_70 , V_215 ) ;
F_23 ( V_215 == V_192 -> V_215 ) ;
if ( F_111 ( V_192 ) ) {
F_23 ( V_192 -> V_194 ) ;
F_23 ( V_192 -> V_148 != V_206 ) ;
} else {
F_23 ( V_192 -> V_148 == V_206 ) ;
}
if ( V_215 -> V_231 < 0 )
V_192 -> V_219 = V_215 -> V_231 ;
V_192 -> V_220 = V_215 -> V_232 [ 0 ] . V_233 ;
F_23 ( V_192 -> V_220 < ( V_121 ) V_234 ) ;
V_230 = V_215 -> V_232 [ 0 ] . V_235 ;
switch ( V_230 ) {
case V_236 :
F_150 ( V_192 ) ;
break;
case V_237 :
F_23 ( V_215 -> V_232 [ 1 ] . V_235 == V_238 ||
V_215 -> V_232 [ 1 ] . V_235 == V_239 ) ;
case V_238 :
case V_239 :
F_152 ( V_192 ) ;
break;
case V_240 :
F_154 ( V_192 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
F_153 ( V_192 ) ;
break;
case V_244 :
F_155 ( V_192 ) ;
break;
default:
F_108 ( NULL , L_27 ,
V_192 -> V_216 , V_230 ) ;
break;
}
if ( F_114 ( V_192 ) )
F_147 ( V_192 ) ;
}
static void F_158 ( struct V_191 * V_192 )
{
struct V_214 * V_215 = V_192 -> V_215 ;
F_23 ( F_111 ( V_192 ) ) ;
V_215 -> V_245 = V_192 -> V_194 -> V_14 ;
}
static void F_159 ( struct V_191 * V_192 )
{
struct V_214 * V_215 = V_192 -> V_215 ;
V_215 -> V_246 = V_247 ;
V_215 -> V_248 = V_192 -> V_159 ;
}
static struct V_214 *
F_160 ( struct V_8 * V_9 ,
struct V_119 * V_135 ,
int V_249 , unsigned int V_47 ,
struct V_191 * V_192 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_214 * V_252 ;
const char * V_253 = V_9 -> V_108 == 1 ?
V_254 : V_255 ;
V_252 = F_161 ( V_251 , V_135 , V_249 , false , V_256 ) ;
if ( ! V_252 )
return NULL ;
V_252 -> V_257 = V_47 ;
V_252 -> V_258 = F_157 ;
V_252 -> V_229 = V_192 ;
V_252 -> V_259 . V_260 = V_9 -> V_127 . V_129 ;
if ( F_162 ( & V_252 -> V_261 , V_256 , V_253 ,
V_9 -> V_10 . V_134 , V_192 -> V_216 ) )
goto V_262;
if ( F_163 ( V_252 , V_256 ) )
goto V_262;
return V_252 ;
V_262:
F_164 ( V_252 ) ;
return NULL ;
}
static struct V_214 * F_165 (
struct V_8 * V_9 ,
enum V_101 V_102 ,
unsigned int V_249 ,
struct V_191 * V_192 )
{
struct V_119 * V_135 = NULL ;
if ( F_111 ( V_192 ) &&
( V_102 == V_105 || V_102 == V_104 ) ) {
struct V_202 * V_194 = V_192 -> V_194 ;
if ( V_102 == V_104 ) {
F_23 ( F_136 ( V_194 ) ) ;
} else {
F_23 ( F_138 ( V_194 ) ) ;
}
V_135 = V_194 -> V_135 ;
}
F_23 ( V_249 == 1 || ( ( V_102 == V_104 ) && V_249 == 2 ) ) ;
return F_160 ( V_9 , V_135 , V_249 ,
( V_102 == V_104 || V_102 == V_105 ) ?
V_263 : V_264 , V_192 ) ;
}
static struct V_214 *
F_166 ( struct V_191 * V_192 )
{
struct V_202 * V_194 ;
int V_265 = 3 ;
F_23 ( F_111 ( V_192 ) ) ;
V_194 = V_192 -> V_194 ;
F_23 ( V_194 ) ;
F_23 ( F_136 ( V_194 ) ||
F_138 ( V_194 ) ) ;
if ( F_138 ( V_194 ) )
V_265 = 2 ;
return F_160 ( V_194 -> V_9 ,
V_194 -> V_135 , V_265 ,
V_263 , V_192 ) ;
}
static void F_167 ( struct V_214 * V_215 )
{
F_164 ( V_215 ) ;
}
static struct V_191 *
F_168 ( enum V_210 type )
{
struct V_191 * V_192 ;
F_23 ( F_129 ( type ) ) ;
V_192 = F_169 ( V_266 , V_256 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_148 = V_206 ;
V_192 -> type = type ;
F_34 ( & V_192 -> V_207 ) ;
F_170 ( & V_192 -> V_226 ) ;
F_33 ( & V_192 -> V_73 ) ;
F_31 ( L_28 , V_70 , V_192 ) ;
return V_192 ;
}
static void V_201 ( struct V_73 * V_73 )
{
struct V_191 * V_192 ;
V_192 = F_59 ( V_73 , struct V_191 , V_73 ) ;
F_31 ( L_25 , V_70 , V_192 ) ;
F_23 ( V_192 -> V_194 == NULL ) ;
F_23 ( V_192 -> V_148 == V_206 ) ;
if ( V_192 -> V_215 )
F_167 ( V_192 -> V_215 ) ;
F_23 ( F_129 ( V_192 -> type ) ) ;
switch ( V_192 -> type ) {
case V_211 :
break;
case V_212 :
if ( V_192 -> V_225 )
F_90 ( V_192 -> V_225 ) ;
break;
case V_213 :
if ( V_192 -> V_177 &&
! F_111 ( V_192 ) )
F_171 ( V_192 -> V_177 ,
V_192 -> V_267 ) ;
break;
}
F_172 ( V_266 , V_192 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_174 ( V_9 ) ;
F_175 ( V_9 -> V_268 ) ;
V_9 -> V_268 = NULL ;
V_9 -> V_200 = 0 ;
}
static void F_176 ( struct V_8 * V_9 )
{
int V_2 ;
if ( ! V_9 -> V_268 )
return;
V_2 = F_4 ( & V_9 -> V_269 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_173 ( V_9 ) ;
else
F_108 ( V_9 , L_29 ) ;
}
static bool F_177 ( struct V_8 * V_9 )
{
int V_2 = 0 ;
if ( ! V_9 -> V_268 )
return false ;
F_12 ( & V_9 -> V_270 ) ;
if ( V_9 -> V_200 )
V_2 = F_1 ( & V_9 -> V_269 ) ;
F_13 ( & V_9 -> V_270 ) ;
if ( V_2 < 0 )
F_108 ( V_9 , L_30 ) ;
return V_2 > 0 ;
}
static struct V_202 * F_178 (
struct V_8 * V_9 ,
V_121 V_159 , V_121 V_161 ,
enum V_101 V_102 ,
struct V_119 * V_135 )
{
struct V_202 * V_194 ;
V_194 = F_179 ( V_271 , V_256 ) ;
if ( ! V_194 )
return NULL ;
V_194 -> V_272 = NULL ;
V_194 -> V_9 = V_9 ;
V_194 -> V_159 = V_159 ;
V_194 -> V_161 = V_161 ;
V_194 -> V_47 = 0 ;
if ( V_102 == V_105 ) {
F_137 ( V_194 ) ;
V_194 -> V_135 = V_135 ;
} else if ( V_102 == V_104 ) {
F_135 ( V_194 ) ;
V_194 -> V_135 = V_135 ;
} else {
V_194 -> V_14 = V_9 -> V_13 -> V_14 ;
}
if ( F_177 ( V_9 ) )
F_142 ( V_194 ) ;
F_180 ( & V_194 -> V_273 ) ;
V_194 -> V_274 = 0 ;
V_194 -> V_209 = NULL ;
V_194 -> V_219 = 0 ;
V_194 -> V_205 = 0 ;
F_34 ( & V_194 -> V_208 ) ;
F_33 ( & V_194 -> V_73 ) ;
F_31 ( L_31 , V_70 , V_9 ,
F_54 ( V_102 ) , V_159 , V_161 , V_194 ) ;
return V_194 ;
}
static void V_204 ( struct V_73 * V_73 )
{
struct V_202 * V_194 ;
struct V_191 * V_192 ;
struct V_191 * V_275 ;
V_194 = F_59 ( V_73 , struct V_202 , V_73 ) ;
F_31 ( L_21 , V_70 , V_194 ) ;
F_181 (img_request, obj_request, next_obj_request)
F_128 ( V_194 , V_192 ) ;
F_23 ( V_194 -> V_205 == 0 ) ;
if ( F_144 ( V_194 ) ) {
F_143 ( V_194 ) ;
F_176 ( V_194 -> V_9 ) ;
}
if ( F_136 ( V_194 ) ||
F_138 ( V_194 ) )
F_74 ( V_194 -> V_135 ) ;
F_172 ( V_271 , V_194 ) ;
}
static struct V_202 * F_182 (
struct V_191 * V_192 ,
V_121 V_199 , V_121 V_161 )
{
struct V_202 * V_276 ;
struct V_8 * V_9 ;
F_23 ( V_192 -> V_194 ) ;
V_9 = V_192 -> V_194 -> V_9 ;
V_276 = F_178 ( V_9 -> V_277 , V_199 ,
V_161 , V_103 , NULL ) ;
if ( ! V_276 )
return NULL ;
F_139 ( V_276 ) ;
F_121 ( V_192 ) ;
V_276 -> V_192 = V_192 ;
return V_276 ;
}
static void V_203 ( struct V_73 * V_73 )
{
struct V_202 * V_276 ;
struct V_191 * V_278 ;
V_276 = F_59 ( V_73 , struct V_202 , V_73 ) ;
V_278 = V_276 -> V_192 ;
V_276 -> V_192 = NULL ;
F_123 ( V_278 ) ;
F_140 ( V_276 ) ;
V_204 ( V_73 ) ;
}
static bool F_183 ( struct V_191 * V_192 )
{
struct V_202 * V_194 ;
unsigned int V_220 ;
int V_219 ;
bool V_279 ;
F_23 ( F_111 ( V_192 ) ) ;
V_194 = V_192 -> V_194 ;
F_23 ( V_192 -> V_220 <= ( V_121 ) V_234 ) ;
V_220 = ( unsigned int ) V_192 -> V_220 ;
V_219 = V_192 -> V_219 ;
if ( V_219 ) {
struct V_8 * V_9 = V_194 -> V_9 ;
enum V_101 V_102 ;
if ( F_138 ( V_194 ) )
V_102 = V_105 ;
else if ( F_136 ( V_194 ) )
V_102 = V_104 ;
else
V_102 = V_103 ;
F_108 ( V_9 , L_32 ,
F_54 ( V_102 ) , V_192 -> V_161 ,
V_192 -> V_199 , V_192 -> V_159 ) ;
F_108 ( V_9 , L_33 ,
V_219 , V_220 ) ;
if ( ! V_194 -> V_219 )
V_194 -> V_219 = V_219 ;
V_220 = V_192 -> V_161 ;
}
if ( F_126 ( V_194 ) ) {
F_23 ( V_194 -> V_192 != NULL ) ;
V_279 = V_192 -> V_148 < V_194 -> V_205 - 1 ;
} else {
F_23 ( V_194 -> V_272 != NULL ) ;
V_279 = F_184 ( V_194 -> V_272 , V_219 , V_220 ) ;
if ( ! V_279 )
F_185 ( V_194 -> V_272 , V_219 ) ;
}
return V_279 ;
}
static void V_217 ( struct V_191 * V_192 )
{
struct V_202 * V_194 ;
T_6 V_148 = V_192 -> V_148 ;
bool V_279 = true ;
F_23 ( F_111 ( V_192 ) ) ;
V_194 = V_192 -> V_194 ;
F_31 ( L_34 , V_70 , V_194 , V_192 ) ;
F_23 ( V_194 != NULL ) ;
F_23 ( V_194 -> V_205 > 0 ) ;
F_23 ( V_148 != V_206 ) ;
F_23 ( V_148 < V_194 -> V_205 ) ;
F_18 ( & V_194 -> V_273 ) ;
if ( V_148 != V_194 -> V_274 )
goto V_61;
F_186 (img_request, obj_request) {
F_23 ( V_279 ) ;
F_23 ( V_148 < V_194 -> V_205 ) ;
if ( ! F_114 ( V_192 ) )
break;
V_279 = F_183 ( V_192 ) ;
V_148 ++ ;
}
F_23 ( V_279 ^ ( V_148 == V_194 -> V_205 ) ) ;
V_194 -> V_274 = V_148 ;
V_61:
F_20 ( & V_194 -> V_273 ) ;
F_125 ( V_194 ) ;
if ( ! V_279 )
F_133 ( V_194 ) ;
}
static void F_187 ( struct V_191 * V_192 ,
struct V_214 * V_280 ,
enum V_101 V_102 ,
unsigned int V_249 )
{
struct V_202 * V_194 = V_192 -> V_194 ;
struct V_8 * V_9 = V_194 -> V_9 ;
V_121 V_128 = F_67 ( & V_9 -> V_10 ) ;
V_121 V_159 = V_192 -> V_159 ;
V_121 V_161 = V_192 -> V_161 ;
V_121 V_281 ;
T_9 V_230 ;
if ( V_102 == V_105 ) {
if ( ! V_159 && V_161 == V_128 &&
( ! F_144 ( V_194 ) ||
! F_119 ( V_192 ) ) ) {
V_230 = V_241 ;
} else if ( ( V_159 + V_161 == V_128 ) ) {
V_230 = V_242 ;
} else {
F_12 ( & V_9 -> V_270 ) ;
V_281 = V_9 -> V_10 . V_146 ;
F_13 ( & V_9 -> V_270 ) ;
if ( V_192 -> V_199 + V_161 == V_281 )
V_230 = V_242 ;
else
V_230 = V_243 ;
}
} else if ( V_102 == V_104 ) {
if ( ! V_159 && V_161 == V_128 )
V_230 = V_239 ;
else
V_230 = V_238 ;
F_188 ( V_280 , V_249 ,
V_128 , V_128 ) ;
V_249 ++ ;
} else {
V_230 = V_236 ;
}
if ( V_230 == V_241 )
F_189 ( V_280 , V_249 , V_230 , 0 ) ;
else
F_190 ( V_280 , V_249 , V_230 ,
V_159 , V_161 , 0 , 0 ) ;
if ( V_192 -> type == V_212 )
F_191 ( V_280 , V_249 ,
V_192 -> V_225 , V_161 ) ;
else if ( V_192 -> type == V_213 )
F_192 ( V_280 , V_249 ,
V_192 -> V_177 , V_161 ,
V_159 & ~ V_182 , false , false ) ;
if ( V_102 == V_104 || V_102 == V_105 )
F_159 ( V_192 ) ;
else
F_158 ( V_192 ) ;
}
static int F_193 ( struct V_202 * V_194 ,
enum V_210 type ,
void * V_282 )
{
struct V_8 * V_9 = V_194 -> V_9 ;
struct V_191 * V_192 = NULL ;
struct V_191 * V_275 ;
struct V_163 * V_225 = NULL ;
unsigned int V_283 = 0 ;
struct V_176 * * V_177 = NULL ;
enum V_101 V_102 ;
V_121 V_199 ;
V_121 V_284 ;
F_31 ( L_35 , V_70 , V_194 ,
( int ) type , V_282 ) ;
V_199 = V_194 -> V_159 ;
V_284 = V_194 -> V_161 ;
F_23 ( V_284 > 0 ) ;
V_102 = F_145 ( V_194 ) ;
if ( type == V_212 ) {
V_225 = V_282 ;
F_23 ( V_199 ==
V_225 -> V_187 . V_285 << V_117 ) ;
} else if ( type == V_213 ) {
V_177 = V_282 ;
}
while ( V_284 ) {
struct V_214 * V_215 ;
V_121 V_216 = V_199 >> V_9 -> V_10 . V_124 ;
V_121 V_159 = F_88 ( V_9 , V_199 ) ;
V_121 V_161 = F_89 ( V_9 , V_199 , V_284 ) ;
V_192 = F_168 ( type ) ;
if ( ! V_192 )
goto V_286;
V_192 -> V_216 = V_216 ;
V_192 -> V_159 = V_159 ;
V_192 -> V_161 = V_161 ;
F_127 ( V_194 , V_192 ) ;
if ( type == V_212 ) {
unsigned int V_287 ;
F_23 ( V_161 <= ( V_121 ) V_234 ) ;
V_287 = ( unsigned int ) V_161 ;
V_192 -> V_225 =
F_107 ( & V_225 ,
& V_283 ,
V_287 ,
V_256 ) ;
if ( ! V_192 -> V_225 )
goto V_286;
} else if ( type == V_213 ) {
unsigned int V_267 ;
V_192 -> V_177 = V_177 ;
V_267 = ( T_6 ) F_194 ( V_159 , V_161 ) ;
V_192 -> V_267 = V_267 ;
if ( ( V_159 + V_161 ) & ~ V_182 )
V_267 -- ;
V_177 += V_267 ;
}
V_215 = F_165 ( V_9 , V_102 ,
( V_102 == V_104 ) ? 2 : 1 ,
V_192 ) ;
if ( ! V_215 )
goto V_286;
V_192 -> V_215 = V_215 ;
V_192 -> V_209 = V_217 ;
V_192 -> V_199 = V_199 ;
F_187 ( V_192 , V_215 , V_102 , 0 ) ;
V_199 += V_161 ;
V_284 -= V_161 ;
}
return 0 ;
V_286:
F_181 (img_request, obj_request, next_obj_request)
F_128 ( V_194 , V_192 ) ;
return - V_69 ;
}
static void
F_156 ( struct V_191 * V_192 )
{
struct V_202 * V_194 ;
struct V_8 * V_9 ;
struct V_176 * * V_177 ;
T_6 V_267 ;
F_31 ( L_25 , V_70 , V_192 ) ;
F_23 ( V_192 -> type == V_212 ||
V_192 -> type == V_211 ) ;
F_23 ( F_111 ( V_192 ) ) ;
V_194 = V_192 -> V_194 ;
F_23 ( V_194 ) ;
V_9 = V_194 -> V_9 ;
F_23 ( V_9 ) ;
V_177 = V_192 -> V_288 ;
F_23 ( V_177 != NULL ) ;
V_192 -> V_288 = NULL ;
V_267 = V_192 -> V_289 ;
F_23 ( V_267 ) ;
V_192 -> V_289 = 0 ;
F_171 ( V_177 , V_267 ) ;
if ( ! V_192 -> V_219 )
V_192 -> V_220 = V_192 -> V_161 ;
F_113 ( V_192 ) ;
}
static void
F_195 ( struct V_202 * V_194 )
{
struct V_191 * V_278 ;
struct V_214 * V_215 ;
struct V_8 * V_9 ;
struct V_176 * * V_177 ;
enum V_101 V_102 ;
T_6 V_267 ;
int V_290 ;
V_121 V_291 ;
F_23 ( F_126 ( V_194 ) ) ;
V_177 = V_194 -> V_288 ;
F_23 ( V_177 != NULL ) ;
V_194 -> V_288 = NULL ;
V_267 = V_194 -> V_289 ;
F_23 ( V_267 ) ;
V_194 -> V_289 = 0 ;
V_278 = V_194 -> V_192 ;
F_23 ( V_278 != NULL ) ;
F_23 ( F_129 ( V_278 -> type ) ) ;
V_290 = V_194 -> V_219 ;
V_291 = V_194 -> V_161 ;
F_23 ( V_290 || V_291 == V_194 -> V_220 ) ;
F_125 ( V_194 ) ;
F_23 ( V_278 -> V_194 ) ;
V_9 = V_278 -> V_194 -> V_9 ;
F_23 ( V_9 ) ;
if ( ! V_9 -> V_200 ) {
F_171 ( V_177 , V_267 ) ;
F_130 ( V_278 ) ;
return;
}
if ( V_290 )
goto V_139;
V_290 = - V_69 ;
V_215 = F_166 ( V_278 ) ;
if ( ! V_215 )
goto V_139;
F_167 ( V_278 -> V_215 ) ;
V_278 -> V_215 = V_215 ;
V_278 -> V_288 = V_177 ;
V_278 -> V_289 = V_267 ;
F_196 ( V_215 , 0 , V_244 , L_36 , L_37 ) ;
F_197 ( V_215 , 0 , V_177 , V_291 , 0 ,
false , false ) ;
V_102 = F_145 ( V_278 -> V_194 ) ;
F_187 ( V_278 , V_215 , V_102 , 1 ) ;
F_130 ( V_278 ) ;
return;
V_139:
F_171 ( V_177 , V_267 ) ;
F_149 ( V_278 , V_290 ) ;
}
static int F_198 ( struct V_191 * V_192 )
{
struct V_8 * V_9 = V_192 -> V_194 -> V_9 ;
struct V_202 * V_276 = NULL ;
V_121 V_199 ;
V_121 V_161 ;
struct V_176 * * V_177 = NULL ;
T_6 V_267 ;
int V_219 ;
F_23 ( V_9 -> V_277 != NULL ) ;
V_199 = V_192 -> V_199 - V_192 -> V_159 ;
V_161 = F_67 ( & V_9 -> V_10 ) ;
if ( V_199 + V_161 > V_9 -> V_200 ) {
F_23 ( V_199 < V_9 -> V_200 ) ;
V_161 = V_9 -> V_200 - V_199 ;
}
V_267 = ( T_6 ) F_194 ( 0 , V_161 ) ;
V_177 = F_199 ( V_267 , V_71 ) ;
if ( F_36 ( V_177 ) ) {
V_219 = F_200 ( V_177 ) ;
V_177 = NULL ;
goto V_139;
}
V_219 = - V_69 ;
V_276 = F_182 ( V_192 ,
V_199 , V_161 ) ;
if ( ! V_276 )
goto V_139;
V_219 = F_193 ( V_276 , V_213 , V_177 ) ;
if ( V_219 )
goto V_139;
V_276 -> V_288 = V_177 ;
V_276 -> V_289 = V_267 ;
V_276 -> V_209 = F_195 ;
V_219 = F_201 ( V_276 ) ;
if ( ! V_219 )
return 0 ;
V_276 -> V_288 = NULL ;
V_276 -> V_289 = 0 ;
V_276 -> V_192 = NULL ;
F_123 ( V_192 ) ;
V_139:
if ( V_177 )
F_171 ( V_177 , V_267 ) ;
if ( V_276 )
F_125 ( V_276 ) ;
return V_219 ;
}
static void F_202 ( struct V_191 * V_192 )
{
struct V_191 * V_278 ;
struct V_8 * V_9 ;
int V_219 ;
F_23 ( ! F_111 ( V_192 ) ) ;
V_278 = V_192 -> V_192 ;
V_192 -> V_192 = NULL ;
F_123 ( V_278 ) ;
F_23 ( V_278 ) ;
F_23 ( V_278 -> V_194 ) ;
V_219 = V_192 -> V_219 ;
V_192 -> V_219 = 0 ;
F_31 ( L_38 , V_70 ,
V_192 , V_278 , V_219 ,
V_192 -> V_220 , V_192 -> V_161 ) ;
F_123 ( V_192 ) ;
V_9 = V_278 -> V_194 -> V_9 ;
if ( ! V_9 -> V_200 ) {
F_130 ( V_278 ) ;
return;
}
if ( ! V_219 ) {
F_115 ( V_278 , true ) ;
} else if ( V_219 == - V_49 ) {
F_115 ( V_278 , false ) ;
} else {
goto V_292;
}
V_219 = F_203 ( V_278 ) ;
if ( V_219 )
goto V_292;
return;
V_292:
F_149 ( V_278 , V_219 ) ;
}
static int F_204 ( struct V_191 * V_192 )
{
struct V_8 * V_9 = V_192 -> V_194 -> V_9 ;
struct V_191 * V_293 ;
struct V_176 * * V_177 ;
T_6 V_267 ;
T_7 V_111 ;
int V_54 ;
V_293 = F_168 ( V_213 ) ;
if ( ! V_293 )
return - V_69 ;
V_293 -> V_216 = V_192 -> V_216 ;
V_293 -> V_215 = F_165 ( V_9 , V_103 , 1 ,
V_293 ) ;
if ( ! V_293 -> V_215 ) {
V_54 = - V_69 ;
goto V_294;
}
V_111 = sizeof ( V_120 ) + sizeof ( V_295 ) + sizeof ( V_295 ) ;
V_267 = ( T_6 ) F_194 ( 0 , V_111 ) ;
V_177 = F_199 ( V_267 , V_71 ) ;
if ( F_36 ( V_177 ) ) {
V_54 = F_200 ( V_177 ) ;
goto V_294;
}
F_189 ( V_293 -> V_215 , 0 , V_240 , 0 ) ;
F_205 ( V_293 -> V_215 , 0 , V_177 , V_111 , 0 ,
false , false ) ;
F_121 ( V_192 ) ;
V_293 -> V_192 = V_192 ;
V_293 -> V_177 = V_177 ;
V_293 -> V_267 = V_267 ;
V_293 -> V_209 = F_202 ;
F_130 ( V_293 ) ;
return 0 ;
V_294:
F_123 ( V_293 ) ;
return V_54 ;
}
static bool F_206 ( struct V_191 * V_192 )
{
struct V_202 * V_194 = V_192 -> V_194 ;
struct V_8 * V_9 = V_194 -> V_9 ;
if ( ! F_136 ( V_194 ) &&
! F_138 ( V_194 ) )
return true ;
if ( ! F_144 ( V_194 ) )
return true ;
if ( ! F_119 ( V_192 ) )
return true ;
if ( ! V_192 -> V_159 &&
V_192 -> V_161 == F_67 ( & V_9 -> V_10 ) )
return true ;
if ( F_117 ( V_192 ) &&
F_118 ( V_192 ) )
return true ;
return false ;
}
static int F_203 ( struct V_191 * V_192 )
{
F_23 ( F_111 ( V_192 ) ) ;
F_23 ( F_129 ( V_192 -> type ) ) ;
F_23 ( V_192 -> V_194 ) ;
if ( F_206 ( V_192 ) ) {
F_130 ( V_192 ) ;
return 0 ;
}
if ( F_117 ( V_192 ) )
return F_198 ( V_192 ) ;
return F_204 ( V_192 ) ;
}
static int F_201 ( struct V_202 * V_194 )
{
struct V_191 * V_192 ;
struct V_191 * V_275 ;
int V_54 = 0 ;
F_31 ( L_21 , V_70 , V_194 ) ;
F_124 ( V_194 ) ;
F_181 (img_request, obj_request, next_obj_request) {
V_54 = F_203 ( V_192 ) ;
if ( V_54 )
goto V_296;
}
V_296:
F_125 ( V_194 ) ;
return V_54 ;
}
static void F_207 ( struct V_202 * V_194 )
{
struct V_191 * V_192 ;
struct V_8 * V_9 ;
V_121 V_297 ;
V_121 V_298 ;
int V_290 ;
F_23 ( F_126 ( V_194 ) ) ;
V_192 = V_194 -> V_192 ;
V_298 = V_194 -> V_220 ;
V_290 = V_194 -> V_219 ;
F_125 ( V_194 ) ;
F_23 ( V_192 ) ;
F_23 ( V_192 -> V_194 ) ;
V_9 = V_192 -> V_194 -> V_9 ;
if ( ! V_9 -> V_200 ) {
F_130 ( V_192 ) ;
return;
}
V_192 -> V_219 = V_290 ;
if ( V_192 -> V_219 )
goto V_61;
F_23 ( V_192 -> V_199 < V_162 - V_192 -> V_161 ) ;
V_297 = V_192 -> V_199 + V_192 -> V_161 ;
if ( V_297 > V_9 -> V_200 ) {
V_121 V_220 = 0 ;
if ( V_192 -> V_199 < V_9 -> V_200 )
V_220 = V_9 -> V_200 -
V_192 -> V_199 ;
V_192 -> V_220 = F_208 ( V_298 , V_220 ) ;
} else {
V_192 -> V_220 = V_298 ;
}
V_61:
F_146 ( V_192 ) ;
F_147 ( V_192 ) ;
}
static void F_151 ( struct V_191 * V_192 )
{
struct V_202 * V_194 ;
int V_219 ;
F_23 ( F_111 ( V_192 ) ) ;
F_23 ( V_192 -> V_194 != NULL ) ;
F_23 ( V_192 -> V_219 == ( V_299 ) - V_49 ) ;
F_23 ( F_129 ( V_192 -> type ) ) ;
V_194 = F_182 ( V_192 ,
V_192 -> V_199 ,
V_192 -> V_161 ) ;
V_219 = - V_69 ;
if ( ! V_194 )
goto V_139;
if ( V_192 -> type == V_212 )
V_219 = F_193 ( V_194 , V_212 ,
V_192 -> V_225 ) ;
else
V_219 = F_193 ( V_194 , V_213 ,
V_192 -> V_177 ) ;
if ( V_219 )
goto V_139;
V_194 -> V_209 = F_207 ;
V_219 = F_201 ( V_194 ) ;
if ( V_219 )
goto V_139;
return;
V_139:
if ( V_194 )
F_125 ( V_194 ) ;
V_192 -> V_219 = V_219 ;
V_192 -> V_220 = 0 ;
F_113 ( V_192 ) ;
}
static bool F_209 ( const struct V_300 * V_301 ,
const struct V_300 * V_302 )
{
return V_301 -> V_303 == V_302 -> V_303 && V_301 -> V_304 == V_302 -> V_304 ;
}
static struct V_300 F_210 ( struct V_8 * V_9 )
{
struct V_300 V_305 ;
F_211 ( & V_9 -> V_306 ) ;
V_305 . V_303 = F_212 ( V_9 -> V_65 -> V_75 ) ;
V_305 . V_304 = V_9 -> V_307 ;
F_57 ( & V_9 -> V_306 ) ;
return V_305 ;
}
static void F_213 ( struct V_8 * V_9 ,
const struct V_300 * V_305 )
{
F_31 ( L_39 , V_70 , V_9 ,
V_9 -> V_308 . V_303 , V_9 -> V_308 . V_304 ,
V_305 -> V_303 , V_305 -> V_304 ) ;
V_9 -> V_308 = * V_305 ;
}
static void F_214 ( struct V_8 * V_9 , char * V_25 )
{
F_211 ( & V_9 -> V_306 ) ;
sprintf ( V_25 , L_40 , V_309 , V_9 -> V_307 ) ;
F_57 ( & V_9 -> V_306 ) ;
}
static int F_215 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_300 V_305 = F_210 ( V_9 ) ;
char V_310 [ 32 ] ;
int V_54 ;
F_131 ( F_10 ( V_9 ) ) ;
F_214 ( V_9 , V_310 ) ;
V_54 = F_216 ( V_251 , & V_9 -> V_311 , & V_9 -> V_312 ,
V_313 , V_314 , V_310 ,
V_315 , L_41 , 0 ) ;
if ( V_54 )
return V_54 ;
V_9 -> V_18 = V_19 ;
F_213 ( V_9 , & V_305 ) ;
F_217 ( V_9 -> V_316 , & V_9 -> V_317 ) ;
return 0 ;
}
static int F_218 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
char V_310 [ 32 ] ;
int V_54 ;
F_131 ( ! F_10 ( V_9 ) ) ;
V_9 -> V_18 = V_318 ;
F_214 ( V_9 , V_310 ) ;
V_54 = F_219 ( V_251 , & V_9 -> V_311 , & V_9 -> V_312 ,
V_313 , V_310 ) ;
if ( V_54 && V_54 != - V_49 ) {
F_108 ( V_9 , L_42 , V_54 ) ;
return V_54 ;
}
F_213 ( V_9 , & V_319 ) ;
F_217 ( V_9 -> V_316 , & V_9 -> V_320 ) ;
return 0 ;
}
static int F_220 ( struct V_8 * V_9 ,
enum V_321 V_322 ,
struct V_176 * * * V_323 ,
T_7 * V_324 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_300 V_305 = F_210 ( V_9 ) ;
int V_325 = 4 + 8 + 8 + V_326 ;
char V_25 [ V_325 ] ;
void * V_327 = V_25 ;
F_31 ( L_43 , V_70 , V_9 , V_322 ) ;
F_221 ( & V_327 , 2 , 1 , V_325 - V_326 ) ;
F_222 ( & V_327 , V_322 ) ;
F_223 ( & V_327 , V_305 . V_303 ) ;
F_223 ( & V_327 , V_305 . V_304 ) ;
return F_224 ( V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , V_25 , V_325 ,
V_328 , V_323 , V_324 ) ;
}
static void F_225 ( struct V_8 * V_9 ,
enum V_321 V_322 )
{
struct V_176 * * V_329 ;
T_7 V_330 ;
F_220 ( V_9 , V_322 , & V_329 , & V_330 ) ;
F_171 ( V_329 , F_194 ( 0 , V_330 ) ) ;
}
static void F_226 ( struct V_331 * V_332 )
{
struct V_8 * V_9 = F_59 ( V_332 , struct V_8 ,
V_317 ) ;
F_225 ( V_9 , V_333 ) ;
}
static void F_227 ( struct V_331 * V_332 )
{
struct V_8 * V_9 = F_59 ( V_332 , struct V_8 ,
V_320 ) ;
F_225 ( V_9 , V_334 ) ;
}
static int F_228 ( struct V_8 * V_9 )
{
struct V_176 * * V_329 ;
T_7 V_330 ;
bool V_335 = false ;
int V_54 ;
F_31 ( L_44 , V_70 , V_9 ) ;
V_54 = F_220 ( V_9 , V_336 ,
& V_329 , & V_330 ) ;
if ( V_54 && V_54 != - V_337 ) {
F_108 ( V_9 , L_45 , V_54 ) ;
goto V_61;
}
if ( V_330 > 0 && V_330 <= V_183 ) {
void * V_327 = F_229 ( V_329 [ 0 ] ) ;
void * const V_178 = V_327 + V_330 ;
T_6 V_338 ;
F_230 ( & V_327 , V_178 , V_338 , V_339 ) ;
while ( V_338 -- ) {
T_10 V_340 ;
T_6 V_185 ;
F_231 ( & V_327 , V_178 , 8 + 8 , V_339 ) ;
V_327 += 8 + 8 ;
F_230 ( & V_327 , V_178 , V_185 , V_339 ) ;
if ( ! V_185 )
continue;
if ( V_335 ) {
F_108 ( V_9 ,
L_46 ) ;
V_54 = - V_147 ;
goto V_61;
}
V_335 = true ;
V_54 = F_232 ( & V_327 , V_178 , 1 , L_47 ,
& V_340 , & V_185 ) ;
if ( V_54 ) {
F_108 ( V_9 ,
L_48 ,
V_54 ) ;
goto V_339;
}
V_54 = F_233 ( & V_327 ) ;
}
}
if ( ! V_335 ) {
F_108 ( V_9 , L_49 ) ;
V_54 = - V_337 ;
}
V_61:
F_171 ( V_329 , F_194 ( 0 , V_330 ) ) ;
return V_54 ;
V_339:
V_54 = - V_4 ;
goto V_61;
}
static void F_234 ( struct V_8 * V_9 , bool V_341 )
{
F_31 ( L_50 , V_70 , V_9 , V_341 ) ;
F_235 ( & V_9 -> V_342 ) ;
if ( V_341 )
F_236 ( & V_9 -> V_343 ) ;
else
F_237 ( & V_9 -> V_343 ) ;
}
static int F_238 ( struct V_8 * V_9 ,
struct V_344 * * V_345 , T_6 * V_346 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
T_10 V_347 ;
char * V_348 ;
int V_54 ;
F_31 ( L_44 , V_70 , V_9 ) ;
V_54 = F_239 ( V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , V_313 ,
& V_347 , & V_348 , V_345 , V_346 ) ;
if ( V_54 )
return V_54 ;
if ( * V_346 == 0 ) {
F_31 ( L_51 , V_70 , V_9 ) ;
goto V_61;
}
if ( strcmp ( V_348 , V_315 ) ) {
F_108 ( V_9 , L_52 ,
V_348 ) ;
V_54 = - V_60 ;
goto V_61;
}
if ( V_347 == V_349 ) {
F_108 ( V_9 , L_53 ) ;
V_54 = - V_60 ;
goto V_61;
}
if ( strncmp ( ( * V_345 ) [ 0 ] . V_145 . V_310 , V_309 ,
strlen ( V_309 ) ) ) {
F_108 ( V_9 , L_54 ,
( * V_345 ) [ 0 ] . V_145 . V_310 ) ;
V_54 = - V_60 ;
goto V_61;
}
V_61:
F_42 ( V_348 ) ;
return V_54 ;
}
static int F_240 ( struct V_8 * V_9 ,
const struct V_344 * V_350 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_351 * V_352 ;
T_6 V_353 ;
V_121 V_310 ;
int V_138 ;
int V_54 ;
V_54 = F_241 ( V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , & V_352 ,
& V_353 ) ;
if ( V_54 )
return V_54 ;
sscanf ( V_350 -> V_145 . V_310 , V_309 L_55 , & V_310 ) ;
for ( V_138 = 0 ; V_138 < V_353 ; V_138 ++ ) {
if ( ! memcmp ( & V_352 [ V_138 ] . V_354 , & V_350 -> V_355 . V_354 ,
sizeof( V_350 -> V_355 . V_354 ) ) &&
V_352 [ V_138 ] . V_310 == V_310 ) {
struct V_300 V_305 = {
. V_303 = F_66 ( V_352 [ V_138 ] . V_356 . V_357 ) ,
. V_304 = V_310 ,
} ;
F_31 ( L_56 , V_70 ,
V_9 , V_305 . V_303 , V_305 . V_304 ) ;
F_213 ( V_9 , & V_305 ) ;
V_54 = 1 ;
goto V_61;
}
}
F_31 ( L_57 , V_70 , V_9 ) ;
V_54 = 0 ;
V_61:
F_42 ( V_352 ) ;
return V_54 ;
}
static int F_242 ( struct V_8 * V_9 )
{
struct V_358 * V_75 = V_9 -> V_65 -> V_75 ;
struct V_344 * V_345 ;
T_6 V_346 ;
int V_54 ;
for (; ; ) {
V_54 = F_215 ( V_9 ) ;
if ( V_54 != - V_60 )
return V_54 ;
V_54 = F_238 ( V_9 , & V_345 , & V_346 ) ;
if ( V_54 )
return V_54 ;
if ( V_346 == 0 )
goto V_359;
V_54 = F_240 ( V_9 , V_345 ) ;
if ( V_54 ) {
if ( V_54 > 0 )
V_54 = 0 ;
goto V_61;
}
F_108 ( V_9 , L_58 ,
F_243 ( V_345 [ 0 ] . V_145 . V_356 ) ) ;
V_54 = F_244 ( & V_75 -> V_360 ,
& V_345 [ 0 ] . V_355 . V_354 ) ;
if ( V_54 ) {
F_108 ( V_9 , L_59 ,
F_243 ( V_345 [ 0 ] . V_145 . V_356 ) , V_54 ) ;
goto V_61;
}
V_54 = F_245 ( & V_75 -> V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , V_313 ,
V_345 [ 0 ] . V_145 . V_310 ,
& V_345 [ 0 ] . V_145 . V_356 ) ;
if ( V_54 && V_54 != - V_49 )
goto V_61;
V_359:
F_246 ( V_345 , V_346 ) ;
}
V_61:
F_246 ( V_345 , V_346 ) ;
return V_54 ;
}
static enum V_361 F_247 ( struct V_8 * V_9 ,
int * V_362 )
{
enum V_361 V_18 ;
F_12 ( & V_9 -> V_22 ) ;
F_31 ( L_60 , V_70 , V_9 ,
V_9 -> V_18 ) ;
if ( F_10 ( V_9 ) ) {
V_18 = V_9 -> V_18 ;
F_13 ( & V_9 -> V_22 ) ;
return V_18 ;
}
F_13 ( & V_9 -> V_22 ) ;
F_248 ( & V_9 -> V_22 ) ;
F_31 ( L_61 , V_70 , V_9 ,
V_9 -> V_18 ) ;
if ( ! F_10 ( V_9 ) ) {
* V_362 = F_242 ( V_9 ) ;
if ( * V_362 )
F_108 ( V_9 , L_62 , * V_362 ) ;
}
V_18 = V_9 -> V_18 ;
F_249 ( & V_9 -> V_22 ) ;
return V_18 ;
}
static void F_250 ( struct V_331 * V_332 )
{
struct V_8 * V_9 = F_59 ( F_251 ( V_332 ) ,
struct V_8 , V_342 ) ;
enum V_361 V_18 ;
int V_54 ;
F_31 ( L_44 , V_70 , V_9 ) ;
V_359:
V_18 = F_247 ( V_9 , & V_54 ) ;
if ( V_18 != V_318 || V_54 == - V_363 ) {
if ( V_18 == V_19 )
F_234 ( V_9 , true ) ;
F_31 ( L_63 , V_70 ,
V_9 , V_18 , V_54 ) ;
return;
}
V_54 = F_228 ( V_9 ) ;
if ( V_54 == - V_337 ) {
goto V_359;
} else if ( V_54 < 0 ) {
F_108 ( V_9 , L_64 , V_54 ) ;
F_252 ( V_9 -> V_316 , & V_9 -> V_342 ,
V_364 ) ;
} else {
F_31 ( L_65 , V_70 ,
V_9 ) ;
F_252 ( V_9 -> V_316 , & V_9 -> V_342 ,
F_253 ( 2 * V_328 * V_365 ) ) ;
}
}
static bool F_254 ( struct V_8 * V_9 )
{
F_31 ( L_60 , V_70 , V_9 ,
V_9 -> V_18 ) ;
if ( V_9 -> V_18 != V_19 )
return false ;
V_9 -> V_18 = V_20 ;
F_255 ( & V_9 -> V_22 ) ;
F_256 ( & V_9 -> V_65 -> V_75 -> V_251 ) ;
F_13 ( & V_9 -> V_22 ) ;
F_248 ( & V_9 -> V_22 ) ;
F_31 ( L_61 , V_70 , V_9 ,
V_9 -> V_18 ) ;
if ( V_9 -> V_18 != V_20 )
return false ;
if ( ! F_218 ( V_9 ) )
F_235 ( & V_9 -> V_342 ) ;
return true ;
}
static void F_257 ( struct V_331 * V_332 )
{
struct V_8 * V_9 = F_59 ( V_332 , struct V_8 ,
V_366 ) ;
F_248 ( & V_9 -> V_22 ) ;
F_254 ( V_9 ) ;
F_249 ( & V_9 -> V_22 ) ;
}
static void F_258 ( struct V_8 * V_9 , T_10 V_340 ,
void * * V_327 )
{
struct V_300 V_305 = { 0 } ;
if ( V_340 >= 2 ) {
V_305 . V_303 = F_259 ( V_327 ) ;
V_305 . V_304 = F_259 ( V_327 ) ;
}
F_31 ( L_66 , V_70 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( ! F_209 ( & V_305 , & V_319 ) ) {
F_248 ( & V_9 -> V_22 ) ;
if ( F_209 ( & V_305 , & V_9 -> V_308 ) ) {
F_249 ( & V_9 -> V_22 ) ;
return;
}
F_213 ( V_9 , & V_305 ) ;
F_255 ( & V_9 -> V_22 ) ;
} else {
F_12 ( & V_9 -> V_22 ) ;
}
if ( ! F_10 ( V_9 ) )
F_234 ( V_9 , false ) ;
F_13 ( & V_9 -> V_22 ) ;
}
static void F_260 ( struct V_8 * V_9 , T_10 V_340 ,
void * * V_327 )
{
struct V_300 V_305 = { 0 } ;
if ( V_340 >= 2 ) {
V_305 . V_303 = F_259 ( V_327 ) ;
V_305 . V_304 = F_259 ( V_327 ) ;
}
F_31 ( L_66 , V_70 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( ! F_209 ( & V_305 , & V_319 ) ) {
F_248 ( & V_9 -> V_22 ) ;
if ( ! F_209 ( & V_305 , & V_9 -> V_308 ) ) {
F_31 ( L_67 ,
V_70 , V_9 , V_305 . V_303 , V_305 . V_304 ,
V_9 -> V_308 . V_303 , V_9 -> V_308 . V_304 ) ;
F_249 ( & V_9 -> V_22 ) ;
return;
}
F_213 ( V_9 , & V_319 ) ;
F_255 ( & V_9 -> V_22 ) ;
} else {
F_12 ( & V_9 -> V_22 ) ;
}
if ( ! F_10 ( V_9 ) )
F_234 ( V_9 , false ) ;
F_13 ( & V_9 -> V_22 ) ;
}
static bool F_261 ( struct V_8 * V_9 , T_10 V_340 ,
void * * V_327 )
{
struct V_300 V_367 = F_210 ( V_9 ) ;
struct V_300 V_305 = { 0 } ;
bool V_368 ;
if ( V_340 >= 2 ) {
V_305 . V_303 = F_259 ( V_327 ) ;
V_305 . V_304 = F_259 ( V_327 ) ;
}
F_31 ( L_66 , V_70 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( F_209 ( & V_305 , & V_367 ) )
return false ;
F_12 ( & V_9 -> V_22 ) ;
V_368 = F_10 ( V_9 ) ;
if ( V_9 -> V_18 == V_19 ) {
if ( ! F_209 ( & V_9 -> V_308 , & V_319 ) ) {
F_31 ( L_68 , V_70 ,
V_9 ) ;
F_217 ( V_9 -> V_316 , & V_9 -> V_366 ) ;
}
}
F_13 ( & V_9 -> V_22 ) ;
return V_368 ;
}
static void F_262 ( struct V_8 * V_9 ,
V_121 V_369 , V_121 V_310 , V_299 * V_219 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
int V_325 = 4 + V_326 ;
char V_25 [ V_325 ] ;
int V_54 ;
if ( V_219 ) {
void * V_327 = V_25 ;
F_221 ( & V_327 , 1 , 1 ,
V_325 - V_326 ) ;
F_222 ( & V_327 , * V_219 ) ;
} else {
V_325 = 0 ;
}
V_54 = F_263 ( V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , V_369 , V_310 ,
V_25 , V_325 ) ;
if ( V_54 )
F_108 ( V_9 , L_69 , V_54 ) ;
}
static void F_264 ( struct V_8 * V_9 , V_121 V_369 ,
V_121 V_310 )
{
F_31 ( L_44 , V_70 , V_9 ) ;
F_262 ( V_9 , V_369 , V_310 , NULL ) ;
}
static void F_265 ( struct V_8 * V_9 ,
V_121 V_369 , V_121 V_310 , V_299 V_219 )
{
F_31 ( L_70 , V_70 , V_9 , V_219 ) ;
F_262 ( V_9 , V_369 , V_310 , & V_219 ) ;
}
static void F_266 ( void * V_53 , V_121 V_369 , V_121 V_310 ,
V_121 V_370 , void * V_371 , T_7 V_372 )
{
struct V_8 * V_9 = V_53 ;
void * V_327 = V_371 ;
void * const V_178 = V_327 + V_372 ;
T_10 V_340 = 0 ;
T_6 V_185 ;
T_6 V_322 ;
int V_54 ;
F_31 ( L_71 ,
V_70 , V_9 , V_310 , V_369 , V_372 ) ;
if ( V_372 ) {
V_54 = F_232 ( & V_327 , V_178 , 1 , L_72 ,
& V_340 , & V_185 ) ;
if ( V_54 ) {
F_108 ( V_9 , L_73 ,
V_54 ) ;
return;
}
V_322 = F_233 ( & V_327 ) ;
} else {
V_322 = V_373 ;
V_185 = 0 ;
}
F_31 ( L_74 , V_70 , V_9 , V_322 ) ;
switch ( V_322 ) {
case V_333 :
F_258 ( V_9 , V_340 , & V_327 ) ;
F_264 ( V_9 , V_369 , V_310 ) ;
break;
case V_334 :
F_260 ( V_9 , V_340 , & V_327 ) ;
F_264 ( V_9 , V_369 , V_310 ) ;
break;
case V_336 :
if ( F_261 ( V_9 , V_340 , & V_327 ) )
F_265 ( V_9 , V_369 ,
V_310 , 0 ) ;
else
F_264 ( V_9 , V_369 , V_310 ) ;
break;
case V_373 :
V_54 = F_267 ( V_9 ) ;
if ( V_54 )
F_108 ( V_9 , L_75 , V_54 ) ;
F_264 ( V_9 , V_369 , V_310 ) ;
break;
default:
if ( F_11 ( V_9 ) )
F_265 ( V_9 , V_369 ,
V_310 , - V_374 ) ;
else
F_264 ( V_9 , V_369 , V_310 ) ;
break;
}
}
static void F_268 ( void * V_53 , V_121 V_310 , int V_227 )
{
struct V_8 * V_9 = V_53 ;
F_108 ( V_9 , L_76 , V_227 ) ;
F_248 ( & V_9 -> V_22 ) ;
F_213 ( V_9 , & V_319 ) ;
F_249 ( & V_9 -> V_22 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_375 == V_376 ) {
F_269 ( V_9 ) ;
V_9 -> V_375 = V_377 ;
F_270 ( V_9 -> V_316 , & V_9 -> V_378 , 0 ) ;
}
F_57 ( & V_9 -> V_306 ) ;
}
static int F_271 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_379 * V_304 ;
F_23 ( ! V_9 -> V_380 ) ;
F_31 ( L_44 , V_70 , V_9 ) ;
V_304 = F_272 ( V_251 , & V_9 -> V_311 ,
& V_9 -> V_312 , F_266 ,
F_268 , V_9 ) ;
if ( F_36 ( V_304 ) )
return F_200 ( V_304 ) ;
V_9 -> V_380 = V_304 ;
return 0 ;
}
static void F_269 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
int V_54 ;
F_23 ( V_9 -> V_380 ) ;
F_31 ( L_44 , V_70 , V_9 ) ;
V_54 = F_273 ( V_251 , V_9 -> V_380 ) ;
if ( V_54 )
F_108 ( V_9 , L_77 , V_54 ) ;
V_9 -> V_380 = NULL ;
}
static int F_274 ( struct V_8 * V_9 )
{
int V_54 ;
F_211 ( & V_9 -> V_306 ) ;
F_23 ( V_9 -> V_375 == V_381 ) ;
V_54 = F_271 ( V_9 ) ;
if ( V_54 )
goto V_61;
V_9 -> V_375 = V_376 ;
V_9 -> V_307 = V_9 -> V_380 -> V_382 ;
V_61:
F_57 ( & V_9 -> V_306 ) ;
return V_54 ;
}
static void F_275 ( struct V_8 * V_9 )
{
F_31 ( L_44 , V_70 , V_9 ) ;
F_276 ( & V_9 -> V_378 ) ;
F_277 ( & V_9 -> V_317 ) ;
F_277 ( & V_9 -> V_320 ) ;
F_276 ( & V_9 -> V_342 ) ;
F_277 ( & V_9 -> V_366 ) ;
}
static void F_278 ( struct V_8 * V_9 )
{
F_131 ( F_279 ( & V_9 -> V_343 ) ) ;
F_275 ( V_9 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_375 == V_376 )
F_269 ( V_9 ) ;
V_9 -> V_375 = V_381 ;
F_57 ( & V_9 -> V_306 ) ;
F_280 ( & V_9 -> V_65 -> V_75 -> V_251 ) ;
}
static void F_281 ( struct V_331 * V_332 )
{
struct V_8 * V_9 = F_59 ( F_251 ( V_332 ) ,
struct V_8 , V_378 ) ;
bool V_383 = false ;
bool V_384 = false ;
int V_54 ;
F_31 ( L_44 , V_70 , V_9 ) ;
F_248 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_18 == V_19 )
V_383 = F_254 ( V_9 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_375 != V_377 ) {
F_57 ( & V_9 -> V_306 ) ;
goto V_61;
}
V_54 = F_271 ( V_9 ) ;
if ( V_54 ) {
F_108 ( V_9 , L_78 , V_54 ) ;
if ( V_54 == - V_363 || V_54 == - V_49 ) {
F_116 ( V_385 , & V_9 -> V_47 ) ;
V_384 = true ;
} else {
F_270 ( V_9 -> V_316 ,
& V_9 -> V_378 ,
V_364 ) ;
}
F_57 ( & V_9 -> V_306 ) ;
goto V_61;
}
V_384 = true ;
V_9 -> V_375 = V_376 ;
V_9 -> V_307 = V_9 -> V_380 -> V_382 ;
F_57 ( & V_9 -> V_306 ) ;
V_54 = F_267 ( V_9 ) ;
if ( V_54 )
F_108 ( V_9 , L_79 , V_54 ) ;
if ( V_383 ) {
V_54 = F_242 ( V_9 ) ;
if ( V_54 )
F_108 ( V_9 , L_80 ,
V_54 ) ;
}
V_61:
F_249 ( & V_9 -> V_22 ) ;
if ( V_384 )
F_234 ( V_9 , true ) ;
}
static int F_282 ( struct V_8 * V_9 ,
struct V_386 * V_387 ,
struct V_388 * V_389 ,
const char * V_390 ,
const void * V_391 ,
T_7 V_392 ,
void * V_393 ,
T_7 V_394 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_176 * V_395 = NULL ;
struct V_176 * V_396 ;
int V_54 ;
if ( V_391 ) {
if ( V_392 > V_183 )
return - V_397 ;
V_395 = F_283 ( V_71 ) ;
if ( ! V_395 )
return - V_69 ;
memcpy ( F_229 ( V_395 ) , V_391 , V_392 ) ;
}
V_396 = F_283 ( V_71 ) ;
if ( ! V_396 ) {
if ( V_395 )
F_284 ( V_395 ) ;
return - V_69 ;
}
V_54 = F_285 ( V_251 , V_387 , V_389 , V_398 , V_390 ,
V_264 , V_395 , V_392 ,
V_396 , & V_394 ) ;
if ( ! V_54 ) {
memcpy ( V_393 , F_229 ( V_396 ) , V_394 ) ;
V_54 = V_394 ;
}
if ( V_395 )
F_284 ( V_395 ) ;
F_284 ( V_396 ) ;
return V_54 ;
}
static void F_286 ( struct V_8 * V_9 )
{
F_287 ( V_399 ) ;
do {
F_31 ( L_81 , V_70 , V_9 ) ;
F_270 ( V_9 -> V_316 , & V_9 -> V_342 , 0 ) ;
F_288 ( & V_9 -> V_343 , & V_399 ,
V_400 ) ;
F_13 ( & V_9 -> V_22 ) ;
F_289 () ;
F_12 ( & V_9 -> V_22 ) ;
} while ( V_9 -> V_18 != V_19 &&
! F_19 ( V_385 , & V_9 -> V_47 ) );
F_290 ( & V_9 -> V_343 , & V_399 ) ;
}
static void F_291 ( struct V_331 * V_332 )
{
struct V_401 * V_272 = F_292 ( V_332 ) ;
struct V_8 * V_9 = V_272 -> V_402 -> V_403 ;
struct V_202 * V_194 ;
struct V_119 * V_135 = NULL ;
V_121 V_159 = ( V_121 ) F_293 ( V_272 ) << V_117 ;
V_121 V_161 = F_294 ( V_272 ) ;
enum V_101 V_102 ;
V_121 V_404 ;
bool V_405 ;
int V_219 ;
switch ( F_295 ( V_272 ) ) {
case V_406 :
V_102 = V_105 ;
break;
case V_407 :
V_102 = V_104 ;
break;
case V_408 :
V_102 = V_103 ;
break;
default:
F_31 ( L_82 , V_70 , F_295 ( V_272 ) ) ;
V_219 = - V_147 ;
goto V_227;
}
if ( ! V_161 ) {
F_31 ( L_83 , V_70 ) ;
V_219 = 0 ;
goto V_409;
}
if ( V_102 != V_103 ) {
if ( V_9 -> V_16 . V_17 ) {
V_219 = - V_44 ;
goto V_409;
}
F_23 ( V_9 -> V_13 -> V_14 == V_15 ) ;
}
if ( ! F_19 ( V_410 , & V_9 -> V_47 ) ) {
F_31 ( L_84 ) ;
F_23 ( V_9 -> V_13 -> V_14 != V_15 ) ;
V_219 = - V_411 ;
goto V_409;
}
if ( V_159 && V_161 > V_162 - V_159 + 1 ) {
F_108 ( V_9 , L_85 , V_159 ,
V_161 ) ;
V_219 = - V_4 ;
goto V_409;
}
F_296 ( V_272 ) ;
F_12 ( & V_9 -> V_270 ) ;
V_404 = V_9 -> V_16 . V_111 ;
if ( V_102 != V_103 ) {
V_135 = V_9 -> V_10 . V_135 ;
F_297 ( V_135 ) ;
V_405 = F_9 ( V_9 ) ;
} else {
V_405 = V_9 -> V_412 -> V_100 &&
F_9 ( V_9 ) ;
}
F_13 ( & V_9 -> V_270 ) ;
if ( V_159 + V_161 > V_404 ) {
F_108 ( V_9 , L_86 , V_159 ,
V_161 , V_404 ) ;
V_219 = - V_147 ;
goto V_409;
}
if ( V_405 ) {
F_12 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_18 != V_19 &&
! F_19 ( V_385 , & V_9 -> V_47 ) )
F_286 ( V_9 ) ;
F_131 ( ( V_9 -> V_18 == V_19 ) ^
! F_19 ( V_385 , & V_9 -> V_47 ) ) ;
if ( F_19 ( V_385 , & V_9 -> V_47 ) ) {
V_219 = - V_363 ;
goto V_413;
}
}
V_194 = F_178 ( V_9 , V_159 , V_161 , V_102 ,
V_135 ) ;
if ( ! V_194 ) {
V_219 = - V_69 ;
goto V_413;
}
V_194 -> V_272 = V_272 ;
V_135 = NULL ;
if ( V_102 == V_105 )
V_219 = F_193 ( V_194 , V_211 ,
NULL ) ;
else
V_219 = F_193 ( V_194 , V_212 ,
V_272 -> V_163 ) ;
if ( V_219 )
goto V_414;
V_219 = F_201 ( V_194 ) ;
if ( V_219 )
goto V_414;
if ( V_405 )
F_13 ( & V_9 -> V_22 ) ;
return;
V_414:
F_125 ( V_194 ) ;
V_413:
if ( V_405 )
F_13 ( & V_9 -> V_22 ) ;
V_409:
if ( V_219 )
F_108 ( V_9 , L_87 ,
F_54 ( V_102 ) , V_161 , V_159 , V_219 ) ;
F_74 ( V_135 ) ;
V_227:
F_298 ( V_272 , V_219 ) ;
}
static int F_299 ( struct V_415 * V_416 ,
const struct V_417 * V_418 )
{
struct V_401 * V_272 = V_418 -> V_272 ;
struct V_331 * V_332 = F_300 ( V_272 ) ;
F_217 ( V_419 , V_332 ) ;
return V_420 ;
}
static void F_301 ( struct V_8 * V_9 )
{
struct V_50 * V_51 = V_9 -> V_51 ;
if ( ! V_51 )
return;
V_9 -> V_51 = NULL ;
if ( V_51 -> V_47 & V_421 ) {
F_302 ( V_51 ) ;
if ( V_51 -> V_422 )
F_303 ( V_51 -> V_422 ) ;
F_304 ( & V_9 -> V_423 ) ;
}
F_305 ( V_51 ) ;
}
static int F_306 ( struct V_8 * V_9 ,
struct V_386 * V_387 ,
struct V_388 * V_389 ,
void * V_25 , int V_424 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_214 * V_252 ;
struct V_176 * * V_177 ;
int V_425 = F_194 ( 0 , V_424 ) ;
int V_54 ;
V_252 = F_161 ( V_251 , NULL , 1 , false , V_71 ) ;
if ( ! V_252 )
return - V_69 ;
F_307 ( & V_252 -> V_261 , V_387 ) ;
F_308 ( & V_252 -> V_259 , V_389 ) ;
V_252 -> V_257 = V_264 ;
V_54 = F_163 ( V_252 , V_71 ) ;
if ( V_54 )
goto V_426;
V_177 = F_199 ( V_425 , V_71 ) ;
if ( F_36 ( V_177 ) ) {
V_54 = F_200 ( V_177 ) ;
goto V_426;
}
F_190 ( V_252 , 0 , V_236 , 0 , V_424 , 0 , 0 ) ;
F_192 ( V_252 , 0 , V_177 , V_424 , 0 , false ,
true ) ;
F_132 ( V_251 , V_252 , false ) ;
V_54 = F_309 ( V_251 , V_252 ) ;
if ( V_54 >= 0 )
F_310 ( V_177 , V_25 , 0 , V_54 ) ;
V_426:
F_164 ( V_252 ) ;
return V_54 ;
}
static int F_311 ( struct V_8 * V_9 )
{
struct V_109 * V_110 = NULL ;
T_6 V_112 = 0 ;
V_121 V_427 = 0 ;
T_6 V_428 ;
int V_54 ;
do {
T_7 V_111 ;
F_42 ( V_110 ) ;
V_111 = sizeof ( * V_110 ) ;
V_111 += V_112 * sizeof ( struct V_142 ) ;
V_111 += V_427 ;
V_110 = F_32 ( V_111 , V_71 ) ;
if ( ! V_110 )
return - V_69 ;
V_54 = F_306 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , V_110 , V_111 ) ;
if ( V_54 < 0 )
goto V_61;
if ( ( T_7 ) V_54 < V_111 ) {
V_54 = - V_411 ;
F_108 ( V_9 , L_88 ,
V_111 , V_54 ) ;
goto V_61;
}
if ( ! F_64 ( V_110 ) ) {
V_54 = - V_411 ;
F_108 ( V_9 , L_89 ) ;
goto V_61;
}
V_427 = F_66 ( V_110 -> V_122 ) ;
V_428 = V_112 ;
V_112 = F_65 ( V_110 -> V_112 ) ;
} while ( V_112 != V_428 );
V_54 = F_70 ( V_9 , V_110 ) ;
V_61:
F_42 ( V_110 ) ;
return V_54 ;
}
static void F_312 ( struct V_8 * V_9 )
{
V_121 V_14 ;
if ( ! F_19 ( V_410 , & V_9 -> V_47 ) )
return;
V_14 = V_9 -> V_13 -> V_14 ;
if ( V_14 == V_15 )
return;
if ( F_78 ( V_9 , V_14 ) == V_155 )
F_141 ( V_410 , & V_9 -> V_47 ) ;
}
static void F_313 ( struct V_8 * V_9 )
{
T_11 V_111 ;
if ( F_19 ( V_410 , & V_9 -> V_47 ) &&
! F_19 ( V_46 , & V_9 -> V_47 ) ) {
V_111 = ( T_11 ) V_9 -> V_16 . V_111 / V_429 ;
F_31 ( L_90 , ( unsigned long long ) V_111 ) ;
F_314 ( V_9 -> V_51 , V_111 ) ;
F_315 ( V_9 -> V_51 ) ;
}
}
static int F_267 ( struct V_8 * V_9 )
{
V_121 V_404 ;
int V_54 ;
F_248 ( & V_9 -> V_270 ) ;
V_404 = V_9 -> V_16 . V_111 ;
V_54 = F_316 ( V_9 ) ;
if ( V_54 )
goto V_61;
if ( V_9 -> V_277 ) {
V_54 = F_317 ( V_9 ) ;
if ( V_54 )
goto V_61;
}
if ( V_9 -> V_13 -> V_14 == V_15 ) {
V_9 -> V_16 . V_111 = V_9 -> V_10 . V_146 ;
} else {
F_312 ( V_9 ) ;
}
V_61:
F_249 ( & V_9 -> V_270 ) ;
if ( ! V_54 && V_404 != V_9 -> V_16 . V_111 )
F_313 ( V_9 ) ;
return V_54 ;
}
static int F_318 ( void * V_371 , struct V_401 * V_272 ,
unsigned int V_430 , unsigned int V_431 ,
unsigned int V_432 )
{
struct V_331 * V_332 = F_300 ( V_272 ) ;
F_319 ( V_332 , F_291 ) ;
return 0 ;
}
static int F_320 ( struct V_8 * V_9 )
{
struct V_50 * V_51 ;
struct V_433 * V_402 ;
V_121 V_160 ;
int V_227 ;
V_51 = F_321 ( V_32 ?
( 1 << V_6 ) :
V_434 ) ;
if ( ! V_51 )
return - V_69 ;
snprintf ( V_51 -> V_435 , sizeof( V_51 -> V_435 ) , V_398 L_91 ,
V_9 -> V_5 ) ;
V_51 -> V_436 = V_9 -> V_436 ;
V_51 -> V_437 = V_9 -> V_7 ;
if ( V_32 )
V_51 -> V_47 |= V_438 ;
V_51 -> V_439 = & V_440 ;
V_51 -> V_41 = V_9 ;
memset ( & V_9 -> V_423 , 0 , sizeof( V_9 -> V_423 ) ) ;
V_9 -> V_423 . V_441 = & V_442 ;
V_9 -> V_423 . V_96 = V_9 -> V_412 -> V_96 ;
V_9 -> V_423 . V_432 = V_443 ;
V_9 -> V_423 . V_47 = V_444 | V_445 ;
V_9 -> V_423 . V_446 = 1 ;
V_9 -> V_423 . V_447 = sizeof( struct V_331 ) ;
V_227 = F_322 ( & V_9 -> V_423 ) ;
if ( V_227 )
goto V_448;
V_402 = F_323 ( & V_9 -> V_423 ) ;
if ( F_36 ( V_402 ) ) {
V_227 = F_200 ( V_402 ) ;
goto V_449;
}
F_324 ( V_450 , V_402 ) ;
V_160 = F_67 ( & V_9 -> V_10 ) ;
F_325 ( V_402 , V_160 / V_429 ) ;
V_402 -> V_451 . V_452 = F_326 ( V_402 ) ;
F_327 ( V_402 , V_160 / V_429 ) ;
F_328 ( V_402 , V_160 ) ;
F_329 ( V_402 , V_160 ) ;
F_330 ( V_402 , V_160 ) ;
F_324 ( V_453 , V_402 ) ;
V_402 -> V_451 . V_454 = V_160 ;
V_402 -> V_451 . V_455 = V_160 ;
F_331 ( V_402 , V_160 / V_429 ) ;
V_402 -> V_451 . V_456 = 1 ;
if ( ! F_332 ( V_9 -> V_65 -> V_75 , V_457 ) )
V_402 -> V_458 -> V_459 |= V_460 ;
V_51 -> V_422 = V_402 ;
V_402 -> V_403 = V_9 ;
V_9 -> V_51 = V_51 ;
return 0 ;
V_449:
F_304 ( & V_9 -> V_423 ) ;
V_448:
F_305 ( V_51 ) ;
return V_227 ;
}
static struct V_8 * F_333 ( struct V_36 * V_37 )
{
return F_59 ( V_37 , struct V_8 , V_37 ) ;
}
static T_2 F_334 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_92 ,
( unsigned long long ) V_9 -> V_16 . V_111 ) ;
}
static T_2 F_335 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_93 ,
( unsigned long long ) V_9 -> V_16 . V_11 ) ;
}
static T_2 F_336 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
if ( V_9 -> V_436 )
return sprintf ( V_25 , L_94 , V_9 -> V_436 ) ;
return sprintf ( V_25 , L_95 ) ;
}
static T_2 F_337 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_94 , V_9 -> V_7 ) ;
}
static T_2 F_338 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
struct V_462 * V_463 =
F_339 ( V_9 -> V_65 -> V_75 ) ;
return sprintf ( V_25 , L_96 , & V_463 -> V_464 ,
F_65 ( V_463 -> V_465 ) ) ;
}
static T_2 F_340 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_97 ,
F_212 ( V_9 -> V_65 -> V_75 ) ) ;
}
static T_2 F_341 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_98 , & V_9 -> V_65 -> V_75 -> V_466 ) ;
}
static T_2 F_342 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_99 , V_9 -> V_467 ) ;
}
static T_2 F_343 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_99 , V_9 -> V_13 -> V_468 ) ;
}
static T_2 F_344 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_92 ,
( unsigned long long ) V_9 -> V_13 -> V_129 ) ;
}
static T_2 F_345 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
if ( V_9 -> V_13 -> V_469 )
return sprintf ( V_25 , L_99 , V_9 -> V_13 -> V_469 ) ;
return sprintf ( V_25 , L_100 ) ;
}
static T_2 F_346 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_99 , V_9 -> V_13 -> V_470 ) ;
}
static T_2 F_347 ( struct V_36 * V_37 ,
struct V_461 * V_30 ,
char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_99 , V_9 -> V_13 -> V_149 ) ;
}
static T_2 F_348 ( struct V_36 * V_37 ,
struct V_461 * V_30 , char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
return sprintf ( V_25 , L_92 , V_9 -> V_13 -> V_14 ) ;
}
static T_2 F_349 ( struct V_36 * V_37 ,
struct V_461 * V_30 ,
char * V_25 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
T_2 V_471 = 0 ;
if ( ! V_9 -> V_277 )
return sprintf ( V_25 , L_101 ) ;
for ( ; V_9 -> V_277 ; V_9 = V_9 -> V_277 ) {
struct V_472 * V_13 = V_9 -> V_268 ;
V_471 += sprintf ( & V_25 [ V_471 ] , L_102
L_103
L_104
L_105
L_106 ,
! V_471 ? L_41 : L_107 ,
V_13 -> V_129 , V_13 -> V_468 ,
V_13 -> V_470 , V_13 -> V_469 ? : L_108 ,
V_13 -> V_14 , V_13 -> V_149 ,
V_9 -> V_200 ) ;
}
return V_471 ;
}
static T_2 F_350 ( struct V_36 * V_37 ,
struct V_461 * V_30 ,
const char * V_25 ,
T_7 V_111 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
int V_54 ;
V_54 = F_267 ( V_9 ) ;
if ( V_54 )
return V_54 ;
return V_111 ;
}
static struct V_472 * F_351 ( struct V_472 * V_13 )
{
F_46 ( & V_13 -> V_73 ) ;
return V_13 ;
}
static void F_175 ( struct V_472 * V_13 )
{
if ( V_13 )
F_62 ( & V_13 -> V_73 , V_473 ) ;
}
static struct V_472 * F_352 ( void )
{
struct V_472 * V_13 ;
V_13 = F_353 ( sizeof ( * V_13 ) , V_71 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_129 = V_131 ;
V_13 -> V_14 = V_15 ;
F_33 ( & V_13 -> V_73 ) ;
return V_13 ;
}
static void V_473 ( struct V_73 * V_73 )
{
struct V_472 * V_13 = F_59 ( V_73 , struct V_472 , V_73 ) ;
F_42 ( V_13 -> V_468 ) ;
F_42 ( V_13 -> V_470 ) ;
F_42 ( V_13 -> V_469 ) ;
F_42 ( V_13 -> V_149 ) ;
F_42 ( V_13 ) ;
}
static void F_354 ( struct V_8 * V_9 )
{
F_131 ( V_9 -> V_375 != V_381 ) ;
F_131 ( V_9 -> V_18 != V_318 ) ;
F_355 ( & V_9 -> V_311 ) ;
F_356 ( & V_9 -> V_312 ) ;
F_42 ( V_9 -> V_467 ) ;
F_61 ( V_9 -> V_65 ) ;
F_175 ( V_9 -> V_13 ) ;
F_42 ( V_9 -> V_412 ) ;
F_42 ( V_9 ) ;
}
static void F_357 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_333 ( V_37 ) ;
bool V_474 = ! ! V_9 -> V_412 ;
if ( V_474 ) {
F_358 ( V_9 -> V_316 ) ;
F_359 ( & V_475 , V_9 -> V_5 ) ;
}
F_354 ( V_9 ) ;
if ( V_474 )
F_360 ( V_476 ) ;
}
static struct V_8 * F_361 ( struct V_65 * V_68 ,
struct V_472 * V_13 )
{
struct V_8 * V_9 ;
V_9 = F_353 ( sizeof( * V_9 ) , V_71 ) ;
if ( ! V_9 )
return NULL ;
F_180 ( & V_9 -> V_45 ) ;
F_34 ( & V_9 -> V_74 ) ;
F_362 ( & V_9 -> V_270 ) ;
V_9 -> V_10 . V_130 = V_131 ;
F_363 ( & V_9 -> V_311 ) ;
V_9 -> V_312 . V_260 = V_13 -> V_129 ;
F_364 ( & V_9 -> V_306 ) ;
V_9 -> V_375 = V_381 ;
F_365 ( & V_9 -> V_378 , F_281 ) ;
F_362 ( & V_9 -> V_22 ) ;
V_9 -> V_18 = V_318 ;
F_319 ( & V_9 -> V_317 , F_226 ) ;
F_319 ( & V_9 -> V_320 , F_227 ) ;
F_365 ( & V_9 -> V_342 , F_250 ) ;
F_319 ( & V_9 -> V_366 , F_257 ) ;
F_366 ( & V_9 -> V_343 ) ;
V_9 -> V_37 . V_24 = & V_477 ;
V_9 -> V_37 . type = & V_478 ;
V_9 -> V_37 . V_277 = & V_479 ;
F_367 ( & V_9 -> V_37 ) ;
V_9 -> V_65 = V_68 ;
V_9 -> V_13 = V_13 ;
return V_9 ;
}
static struct V_8 * F_368 ( struct V_65 * V_68 ,
struct V_472 * V_13 ,
struct V_85 * V_412 )
{
struct V_8 * V_9 ;
V_9 = F_361 ( V_68 , V_13 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_412 = V_412 ;
V_9 -> V_5 = F_369 ( & V_475 , 0 ,
F_8 ( 1 << V_480 ) ,
V_71 ) ;
if ( V_9 -> V_5 < 0 )
goto V_481;
sprintf ( V_9 -> V_356 , V_398 L_91 , V_9 -> V_5 ) ;
V_9 -> V_316 = F_370 ( L_109 , V_482 ,
V_9 -> V_356 ) ;
if ( ! V_9 -> V_316 )
goto V_483;
F_371 ( V_476 ) ;
F_31 ( L_110 , V_70 , V_9 , V_9 -> V_5 ) ;
return V_9 ;
V_483:
F_359 ( & V_475 , V_9 -> V_5 ) ;
V_481:
F_354 ( V_9 ) ;
return NULL ;
}
static void F_372 ( struct V_8 * V_9 )
{
if ( V_9 )
F_24 ( & V_9 -> V_37 ) ;
}
static int F_83 ( struct V_8 * V_9 , V_121 V_14 ,
T_10 * V_116 , V_121 * V_157 )
{
V_120 V_484 = F_373 ( V_14 ) ;
int V_54 ;
struct {
T_10 V_116 ;
V_120 V_111 ;
} V_485 ( ( V_486 ) ) V_487 = { 0 } ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_111 ,
& V_484 , sizeof( V_484 ) ,
& V_487 , sizeof( V_487 ) ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 < sizeof ( V_487 ) )
return - V_488 ;
if ( V_116 ) {
* V_116 = V_487 . V_116 ;
F_31 ( L_113 , ( unsigned int ) * V_116 ) ;
}
* V_157 = F_66 ( V_487 . V_111 ) ;
F_31 ( L_114 ,
( unsigned long long ) V_14 ,
( unsigned long long ) * V_157 ) ;
return 0 ;
}
static int F_374 ( struct V_8 * V_9 )
{
return F_83 ( V_9 , V_15 ,
& V_9 -> V_10 . V_124 ,
& V_9 -> V_10 . V_146 ) ;
}
static int F_375 ( struct V_8 * V_9 )
{
void * V_489 ;
int V_54 ;
void * V_327 ;
V_489 = F_353 ( V_490 , V_71 ) ;
if ( ! V_489 )
return - V_69 ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_115 ,
NULL , 0 , V_489 , V_490 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
goto V_61;
V_327 = V_489 ;
V_9 -> V_10 . V_134 = F_376 ( & V_327 ,
V_327 + V_54 , NULL , V_256 ) ;
V_54 = 0 ;
if ( F_36 ( V_9 -> V_10 . V_134 ) ) {
V_54 = F_200 ( V_9 -> V_10 . V_134 ) ;
V_9 -> V_10 . V_134 = NULL ;
} else {
F_31 ( L_116 , V_9 -> V_10 . V_134 ) ;
}
V_61:
F_42 ( V_489 ) ;
return V_54 ;
}
static int F_85 ( struct V_8 * V_9 , V_121 V_14 ,
V_121 * V_158 )
{
V_120 V_484 = F_373 ( V_14 ) ;
struct {
V_120 V_11 ;
V_120 V_491 ;
} V_485 ( ( V_486 ) ) V_492 = { 0 } ;
V_121 V_493 ;
int V_54 ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_117 ,
& V_484 , sizeof( V_484 ) ,
& V_492 , sizeof( V_492 ) ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 < sizeof ( V_492 ) )
return - V_488 ;
V_493 = F_66 ( V_492 . V_491 ) & ~ V_26 ;
if ( V_493 ) {
F_108 ( V_9 , L_118 ,
V_493 ) ;
return - V_411 ;
}
* V_158 = F_66 ( V_492 . V_11 ) ;
F_31 ( L_119 ,
( unsigned long long ) V_14 ,
( unsigned long long ) * V_158 ,
( unsigned long long ) F_66 ( V_492 . V_491 ) ) ;
return 0 ;
}
static int F_377 ( struct V_8 * V_9 )
{
return F_85 ( V_9 , V_15 ,
& V_9 -> V_10 . V_11 ) ;
}
static int F_317 ( struct V_8 * V_9 )
{
struct V_472 * V_268 ;
T_7 V_111 ;
void * V_489 = NULL ;
V_120 V_484 ;
void * V_327 ;
void * V_178 ;
V_121 V_129 ;
char * V_470 ;
V_121 V_14 ;
V_121 V_494 ;
int V_54 ;
V_268 = F_352 () ;
if ( ! V_268 )
return - V_69 ;
V_111 = sizeof ( V_120 ) +
sizeof ( V_295 ) + V_495 +
sizeof ( V_120 ) +
sizeof ( V_120 ) ;
V_489 = F_32 ( V_111 , V_71 ) ;
if ( ! V_489 ) {
V_54 = - V_69 ;
goto V_139;
}
V_484 = F_373 ( V_9 -> V_13 -> V_14 ) ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_120 ,
& V_484 , sizeof( V_484 ) , V_489 , V_111 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
goto V_139;
V_327 = V_489 ;
V_178 = V_489 + V_54 ;
V_54 = - V_488 ;
F_378 ( & V_327 , V_178 , V_129 , V_139 ) ;
if ( V_129 == V_131 ) {
if ( V_9 -> V_200 ) {
V_9 -> V_200 = 0 ;
F_176 ( V_9 ) ;
F_379 ( L_121 ,
V_9 -> V_51 -> V_435 ) ;
}
goto V_61;
}
V_54 = - V_147 ;
if ( V_129 > ( V_121 ) V_496 ) {
F_108 ( NULL , L_122 ,
( unsigned long long ) V_129 , V_496 ) ;
goto V_139;
}
V_470 = F_376 ( & V_327 , V_178 , NULL , V_71 ) ;
if ( F_36 ( V_470 ) ) {
V_54 = F_200 ( V_470 ) ;
goto V_139;
}
F_378 ( & V_327 , V_178 , V_14 , V_139 ) ;
F_378 ( & V_327 , V_178 , V_494 , V_139 ) ;
if ( ! V_9 -> V_268 ) {
V_268 -> V_129 = V_129 ;
V_268 -> V_470 = V_470 ;
V_268 -> V_14 = V_14 ;
V_9 -> V_268 = V_268 ;
V_268 = NULL ;
} else {
F_42 ( V_470 ) ;
}
if ( ! V_494 ) {
if ( V_268 ) {
if ( V_9 -> V_200 )
F_108 ( V_9 ,
L_123 ) ;
} else {
F_108 ( V_9 , L_124 ) ;
}
}
V_9 -> V_200 = V_494 ;
V_61:
V_54 = 0 ;
V_139:
F_42 ( V_489 ) ;
F_175 ( V_268 ) ;
return V_54 ;
}
static int F_380 ( struct V_8 * V_9 )
{
struct {
V_120 V_125 ;
V_120 V_126 ;
} V_485 ( ( V_486 ) ) V_497 = { 0 } ;
T_7 V_111 = sizeof ( V_497 ) ;
void * V_327 ;
V_121 V_498 ;
V_121 V_125 ;
V_121 V_126 ;
int V_54 ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_125 ,
NULL , 0 , & V_497 , V_111 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 < V_111 )
return - V_488 ;
V_54 = - V_4 ;
V_498 = F_67 ( & V_9 -> V_10 ) ;
V_327 = & V_497 ;
V_125 = F_259 ( & V_327 ) ;
if ( V_125 != V_498 ) {
F_108 ( V_9 , L_126
L_127 ,
V_125 , V_498 ) ;
return - V_4 ;
}
V_126 = F_259 ( & V_327 ) ;
if ( V_126 != 1 ) {
F_108 ( V_9 , L_128
L_129 , V_126 ) ;
return - V_4 ;
}
V_9 -> V_10 . V_125 = V_125 ;
V_9 -> V_10 . V_126 = V_126 ;
return 0 ;
}
static int F_381 ( struct V_8 * V_9 )
{
V_120 V_130 ;
int V_54 ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_130 ,
NULL , 0 , & V_130 , sizeof( V_130 ) ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 < sizeof( V_130 ) )
return - V_499 ;
V_9 -> V_10 . V_130 = F_66 ( V_130 ) ;
F_131 ( V_9 -> V_10 . V_130 == V_131 ) ;
return 0 ;
}
static char * F_382 ( struct V_8 * V_9 )
{
F_383 ( V_387 ) ;
T_7 V_500 ;
char * V_470 ;
void * V_327 ;
void * V_178 ;
T_7 V_111 ;
void * V_489 = NULL ;
T_7 V_185 = 0 ;
char * V_469 = NULL ;
int V_54 ;
F_23 ( ! V_9 -> V_13 -> V_469 ) ;
V_185 = strlen ( V_9 -> V_13 -> V_470 ) ;
V_500 = sizeof ( V_295 ) + V_185 ;
V_470 = F_32 ( V_500 , V_71 ) ;
if ( ! V_470 )
return NULL ;
V_327 = V_470 ;
V_178 = V_470 + V_500 ;
F_384 ( & V_327 , V_178 , V_9 -> V_13 -> V_470 , ( T_6 ) V_185 ) ;
V_111 = sizeof ( V_295 ) + V_501 ;
V_489 = F_32 ( V_111 , V_71 ) ;
if ( ! V_489 )
goto V_61;
F_385 ( & V_387 , L_102 , V_502 ) ;
V_54 = F_282 ( V_9 , & V_387 , & V_9 -> V_312 ,
L_131 , V_470 , V_500 ,
V_489 , V_111 ) ;
if ( V_54 < 0 )
goto V_61;
V_327 = V_489 ;
V_178 = V_489 + V_54 ;
V_469 = F_376 ( & V_327 , V_178 , & V_185 , V_71 ) ;
if ( F_36 ( V_469 ) )
V_469 = NULL ;
else
F_31 ( L_132 , V_70 , V_469 , V_185 ) ;
V_61:
F_42 ( V_489 ) ;
F_42 ( V_470 ) ;
return V_469 ;
}
static V_121 F_386 ( struct V_8 * V_9 , const char * V_356 )
{
struct V_119 * V_135 = V_9 -> V_10 . V_135 ;
const char * V_149 ;
T_6 V_148 = 0 ;
V_149 = V_9 -> V_10 . V_136 ;
while ( V_148 < V_135 -> V_150 ) {
if ( ! strcmp ( V_356 , V_149 ) )
return V_135 -> V_143 [ V_148 ] ;
V_149 += strlen ( V_149 ) + 1 ;
V_148 ++ ;
}
return V_15 ;
}
static V_121 F_387 ( struct V_8 * V_9 , const char * V_356 )
{
struct V_119 * V_135 = V_9 -> V_10 . V_135 ;
T_6 V_148 ;
bool V_81 = false ;
V_121 V_14 ;
for ( V_148 = 0 ; ! V_81 && V_148 < V_135 -> V_150 ; V_148 ++ ) {
const char * V_149 ;
V_14 = V_135 -> V_143 [ V_148 ] ;
V_149 = F_81 ( V_9 , V_14 ) ;
if ( F_36 ( V_149 ) ) {
if ( F_200 ( V_149 ) == - V_49 )
continue;
else
break;
}
V_81 = ! strcmp ( V_356 , V_149 ) ;
F_42 ( V_149 ) ;
}
return V_81 ? V_14 : V_15 ;
}
static V_121 F_388 ( struct V_8 * V_9 , const char * V_356 )
{
if ( V_9 -> V_108 == 1 )
return F_386 ( V_9 , V_356 ) ;
return F_387 ( V_9 , V_356 ) ;
}
static int F_389 ( struct V_8 * V_9 )
{
struct V_472 * V_13 = V_9 -> V_13 ;
F_23 ( V_13 -> V_129 != V_131 && V_13 -> V_468 ) ;
F_23 ( V_13 -> V_470 && V_13 -> V_469 ) ;
F_23 ( V_13 -> V_149 ) ;
if ( strcmp ( V_13 -> V_149 , V_156 ) ) {
V_121 V_14 ;
V_14 = F_388 ( V_9 , V_13 -> V_149 ) ;
if ( V_14 == V_15 )
return - V_49 ;
V_13 -> V_14 = V_14 ;
} else {
V_13 -> V_14 = V_15 ;
}
return 0 ;
}
static int F_390 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_65 -> V_75 -> V_251 ;
struct V_472 * V_13 = V_9 -> V_13 ;
const char * V_468 ;
const char * V_469 ;
const char * V_149 ;
int V_54 ;
F_23 ( V_13 -> V_129 != V_131 ) ;
F_23 ( V_13 -> V_470 ) ;
F_23 ( V_13 -> V_14 != V_15 ) ;
V_468 = F_391 ( V_251 -> V_503 , V_13 -> V_129 ) ;
if ( ! V_468 ) {
F_108 ( V_9 , L_133 , V_13 -> V_129 ) ;
return - V_147 ;
}
V_468 = F_76 ( V_468 , V_71 ) ;
if ( ! V_468 )
return - V_69 ;
V_469 = F_382 ( V_9 ) ;
if ( ! V_469 )
F_108 ( V_9 , L_134 ) ;
V_149 = F_80 ( V_9 , V_13 -> V_14 ) ;
if ( F_36 ( V_149 ) ) {
V_54 = F_200 ( V_149 ) ;
goto V_139;
}
V_13 -> V_468 = V_468 ;
V_13 -> V_469 = V_469 ;
V_13 -> V_149 = V_149 ;
return 0 ;
V_139:
F_42 ( V_469 ) ;
F_42 ( V_468 ) ;
return V_54 ;
}
static int F_392 ( struct V_8 * V_9 )
{
T_7 V_111 ;
int V_54 ;
void * V_489 ;
void * V_327 ;
void * V_178 ;
V_121 V_140 ;
T_6 V_112 ;
struct V_119 * V_135 ;
T_6 V_138 ;
V_111 = sizeof ( V_120 ) + sizeof ( V_295 ) +
V_504 * sizeof ( V_120 ) ;
V_489 = F_353 ( V_111 , V_71 ) ;
if ( ! V_489 )
return - V_69 ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_135 ,
NULL , 0 , V_489 , V_111 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 )
goto V_61;
V_327 = V_489 ;
V_178 = V_489 + V_54 ;
V_54 = - V_488 ;
F_378 ( & V_327 , V_178 , V_140 , V_61 ) ;
F_230 ( & V_327 , V_178 , V_112 , V_61 ) ;
if ( V_112 > ( V_118 - sizeof ( struct V_119 ) )
/ sizeof ( V_121 ) ) {
V_54 = - V_4 ;
goto V_61;
}
if ( ! F_393 ( & V_327 , V_178 , V_112 * sizeof ( V_120 ) ) )
goto V_61;
V_54 = 0 ;
V_135 = F_72 ( V_112 , V_71 ) ;
if ( ! V_135 ) {
V_54 = - V_69 ;
goto V_61;
}
V_135 -> V_140 = V_140 ;
for ( V_138 = 0 ; V_138 < V_112 ; V_138 ++ )
V_135 -> V_143 [ V_138 ] = F_259 ( & V_327 ) ;
F_74 ( V_9 -> V_10 . V_135 ) ;
V_9 -> V_10 . V_135 = V_135 ;
F_31 ( L_136 ,
( unsigned long long ) V_140 , ( unsigned int ) V_112 ) ;
V_61:
F_42 ( V_489 ) ;
return V_54 ;
}
static const char * F_81 ( struct V_8 * V_9 ,
V_121 V_14 )
{
T_7 V_111 ;
void * V_489 ;
V_120 V_484 ;
int V_54 ;
void * V_327 ;
void * V_178 ;
char * V_149 ;
V_111 = sizeof ( V_295 ) + V_505 ;
V_489 = F_32 ( V_111 , V_71 ) ;
if ( ! V_489 )
return F_44 ( - V_69 ) ;
V_484 = F_373 ( V_14 ) ;
V_54 = F_282 ( V_9 , & V_9 -> V_311 ,
& V_9 -> V_312 , L_137 ,
& V_484 , sizeof( V_484 ) , V_489 , V_111 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 < 0 ) {
V_149 = F_44 ( V_54 ) ;
goto V_61;
}
V_327 = V_489 ;
V_178 = V_489 + V_54 ;
V_149 = F_376 ( & V_327 , V_178 , NULL , V_71 ) ;
if ( F_36 ( V_149 ) )
goto V_61;
F_31 ( L_138 ,
( unsigned long long ) V_14 , V_149 ) ;
V_61:
F_42 ( V_489 ) ;
return V_149 ;
}
static int F_394 ( struct V_8 * V_9 )
{
bool V_133 = V_9 -> V_10 . V_134 == NULL ;
int V_54 ;
V_54 = F_374 ( V_9 ) ;
if ( V_54 )
return V_54 ;
if ( V_133 ) {
V_54 = F_395 ( V_9 ) ;
if ( V_54 )
return V_54 ;
}
V_54 = F_392 ( V_9 ) ;
if ( V_54 && V_133 ) {
F_42 ( V_9 -> V_10 . V_134 ) ;
V_9 -> V_10 . V_134 = NULL ;
}
return V_54 ;
}
static int F_316 ( struct V_8 * V_9 )
{
F_23 ( F_63 ( V_9 -> V_108 ) ) ;
if ( V_9 -> V_108 == 1 )
return F_311 ( V_9 ) ;
return F_394 ( V_9 ) ;
}
static inline T_7 F_396 ( const char * * V_25 )
{
const char * V_506 = L_139 ;
* V_25 += strspn ( * V_25 , V_506 ) ;
return strcspn ( * V_25 , V_506 ) ;
}
static inline char * F_397 ( const char * * V_25 , T_7 * V_507 )
{
char * V_508 ;
T_7 V_185 ;
V_185 = F_396 ( V_25 ) ;
V_508 = F_398 ( * V_25 , V_185 + 1 , V_71 ) ;
if ( ! V_508 )
return NULL ;
* ( V_508 + V_185 ) = '\0' ;
* V_25 += V_185 ;
if ( V_507 )
* V_507 = V_185 ;
return V_508 ;
}
static int F_399 ( const char * V_25 ,
struct V_66 * * V_67 ,
struct V_85 * * V_412 ,
struct V_472 * * V_472 )
{
T_7 V_185 ;
char * V_115 ;
const char * V_509 ;
char * V_149 ;
T_7 V_510 ;
struct V_472 * V_13 = NULL ;
struct V_85 * V_86 = NULL ;
struct V_66 * V_511 ;
int V_54 ;
V_185 = F_396 ( & V_25 ) ;
if ( ! V_185 ) {
F_108 ( NULL , L_140 ) ;
return - V_4 ;
}
V_509 = V_25 ;
V_510 = V_185 + 1 ;
V_25 += V_185 ;
V_54 = - V_4 ;
V_115 = F_397 ( & V_25 , NULL ) ;
if ( ! V_115 )
return - V_69 ;
if ( ! * V_115 ) {
F_108 ( NULL , L_141 ) ;
goto V_139;
}
V_13 = F_352 () ;
if ( ! V_13 )
goto V_512;
V_13 -> V_468 = F_397 ( & V_25 , NULL ) ;
if ( ! V_13 -> V_468 )
goto V_512;
if ( ! * V_13 -> V_468 ) {
F_108 ( NULL , L_142 ) ;
goto V_139;
}
V_13 -> V_469 = F_397 ( & V_25 , NULL ) ;
if ( ! V_13 -> V_469 )
goto V_512;
if ( ! * V_13 -> V_469 ) {
F_108 ( NULL , L_143 ) ;
goto V_139;
}
V_185 = F_396 ( & V_25 ) ;
if ( ! V_185 ) {
V_25 = V_156 ;
V_185 = sizeof ( V_156 ) - 1 ;
} else if ( V_185 > V_505 ) {
V_54 = - V_513 ;
goto V_139;
}
V_149 = F_398 ( V_25 , V_185 + 1 , V_71 ) ;
if ( ! V_149 )
goto V_512;
* ( V_149 + V_185 ) = '\0' ;
V_13 -> V_149 = V_149 ;
V_86 = F_353 ( sizeof ( * V_86 ) , V_71 ) ;
if ( ! V_86 )
goto V_512;
V_86 -> V_17 = V_514 ;
V_86 -> V_96 = V_515 ;
V_86 -> V_100 = V_516 ;
V_511 = F_400 ( V_115 , V_509 ,
V_509 + V_510 - 1 ,
F_50 , V_86 ) ;
if ( F_36 ( V_511 ) ) {
V_54 = F_200 ( V_511 ) ;
goto V_139;
}
F_42 ( V_115 ) ;
* V_67 = V_511 ;
* V_412 = V_86 ;
* V_472 = V_13 ;
return 0 ;
V_512:
V_54 = - V_69 ;
V_139:
F_42 ( V_86 ) ;
F_175 ( V_13 ) ;
F_42 ( V_115 ) ;
return V_54 ;
}
static int F_401 ( struct V_65 * V_68 , const char * V_468 )
{
struct V_66 * V_412 = V_68 -> V_75 -> V_115 ;
V_121 V_517 ;
int V_518 = 0 ;
int V_54 ;
V_359:
V_54 = F_402 ( V_68 -> V_75 -> V_251 . V_503 , V_468 ) ;
if ( V_54 == - V_49 && V_518 ++ < 1 ) {
V_54 = F_403 ( & V_68 -> V_75 -> V_360 , L_144 ,
& V_517 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_68 -> V_75 -> V_251 . V_503 -> V_519 < V_517 ) {
F_404 ( & V_68 -> V_75 -> V_251 ) ;
( void ) F_405 ( & V_68 -> V_75 -> V_360 ,
V_517 ,
V_412 -> V_520 ) ;
goto V_359;
} else {
return - V_49 ;
}
}
return V_54 ;
}
static int F_406 ( struct V_8 * V_9 )
{
int V_54 ;
T_7 V_111 ;
F_383 ( V_387 ) ;
void * V_521 ;
char * V_470 ;
if ( V_9 -> V_13 -> V_470 ) {
V_9 -> V_108 = * V_9 -> V_13 -> V_470 ? 2 : 1 ;
return 0 ;
}
V_54 = F_162 ( & V_387 , V_71 , L_145 , V_522 ,
V_9 -> V_13 -> V_469 ) ;
if ( V_54 )
return V_54 ;
F_31 ( L_146 , V_387 . V_356 ) ;
V_111 = sizeof ( V_295 ) + V_495 ;
V_521 = F_353 ( V_111 , V_256 ) ;
if ( ! V_521 ) {
V_54 = - V_69 ;
goto V_61;
}
V_54 = F_282 ( V_9 , & V_387 , & V_9 -> V_312 ,
L_147 , NULL , 0 ,
V_521 , V_495 ) ;
F_31 ( L_112 , V_70 , V_54 ) ;
if ( V_54 == - V_49 ) {
V_470 = F_76 ( L_41 , V_71 ) ;
V_54 = V_470 ? 0 : - V_69 ;
if ( ! V_54 )
V_9 -> V_108 = 1 ;
} else if ( V_54 >= 0 ) {
void * V_327 = V_521 ;
V_470 = F_376 ( & V_327 , V_327 + V_54 ,
NULL , V_256 ) ;
V_54 = F_407 ( V_470 ) ;
if ( ! V_54 )
V_9 -> V_108 = 2 ;
}
if ( ! V_54 ) {
V_9 -> V_13 -> V_470 = V_470 ;
F_31 ( L_148 , V_470 ) ;
}
V_61:
F_42 ( V_521 ) ;
F_355 ( & V_387 ) ;
return V_54 ;
}
static void F_408 ( struct V_8 * V_9 )
{
struct V_123 * V_10 ;
F_176 ( V_9 ) ;
V_10 = & V_9 -> V_10 ;
F_74 ( V_10 -> V_135 ) ;
F_42 ( V_10 -> V_137 ) ;
F_42 ( V_10 -> V_136 ) ;
F_42 ( V_10 -> V_134 ) ;
memset ( V_10 , 0 , sizeof ( * V_10 ) ) ;
}
static int F_395 ( struct V_8 * V_9 )
{
int V_54 ;
V_54 = F_375 ( V_9 ) ;
if ( V_54 )
goto V_139;
V_54 = F_377 ( V_9 ) ;
if ( V_54 )
goto V_139;
if ( V_9 -> V_10 . V_11 & V_523 ) {
V_54 = F_380 ( V_9 ) ;
if ( V_54 < 0 )
goto V_139;
}
if ( V_9 -> V_10 . V_11 & V_524 ) {
V_54 = F_381 ( V_9 ) ;
if ( V_54 )
goto V_139;
}
F_68 ( V_9 ) ;
return 0 ;
V_139:
V_9 -> V_10 . V_11 = 0 ;
F_42 ( V_9 -> V_10 . V_134 ) ;
V_9 -> V_10 . V_134 = NULL ;
return V_54 ;
}
static int F_409 ( struct V_8 * V_9 , int V_525 )
{
struct V_8 * V_277 = NULL ;
int V_54 ;
if ( ! V_9 -> V_268 )
return 0 ;
if ( ++ V_525 > V_526 ) {
F_379 ( L_149 , V_525 ) ;
V_54 = - V_4 ;
goto V_139;
}
V_277 = F_361 ( V_9 -> V_65 , V_9 -> V_268 ) ;
if ( ! V_277 ) {
V_54 = - V_69 ;
goto V_139;
}
F_45 ( V_9 -> V_65 ) ;
F_351 ( V_9 -> V_268 ) ;
V_54 = F_410 ( V_277 , V_525 ) ;
if ( V_54 < 0 )
goto V_139;
V_9 -> V_277 = V_277 ;
F_411 ( & V_9 -> V_269 , 1 ) ;
return 0 ;
V_139:
F_173 ( V_9 ) ;
F_372 ( V_277 ) ;
return V_54 ;
}
static int F_412 ( struct V_8 * V_9 )
{
int V_54 ;
if ( ! V_32 ) {
V_54 = F_413 ( 0 , V_9 -> V_356 ) ;
if ( V_54 < 0 )
goto V_527;
V_9 -> V_436 = V_54 ;
V_9 -> V_7 = 0 ;
} else {
V_9 -> V_436 = V_528 ;
V_9 -> V_7 = F_7 ( V_9 -> V_5 ) ;
}
V_54 = F_320 ( V_9 ) ;
if ( V_54 )
goto V_529;
V_54 = F_86 ( V_9 ) ;
if ( V_54 )
goto V_530;
F_314 ( V_9 -> V_51 , V_9 -> V_16 . V_111 / V_429 ) ;
F_27 ( V_9 -> V_51 , V_9 -> V_16 . V_17 ) ;
F_414 ( & V_9 -> V_37 , L_91 , V_9 -> V_5 ) ;
V_54 = F_415 ( & V_9 -> V_37 ) ;
if ( V_54 )
goto V_531;
F_116 ( V_410 , & V_9 -> V_47 ) ;
F_249 ( & V_9 -> V_270 ) ;
F_38 ( & V_532 ) ;
F_39 ( & V_9 -> V_74 , & V_533 ) ;
F_40 ( & V_532 ) ;
F_416 ( V_9 -> V_51 ) ;
F_379 ( L_150 , V_9 -> V_51 -> V_435 ,
( unsigned long long ) F_417 ( V_9 -> V_51 ) << V_117 ,
V_9 -> V_10 . V_11 ) ;
return V_54 ;
V_531:
F_87 ( V_9 ) ;
V_530:
F_301 ( V_9 ) ;
V_529:
if ( ! V_32 )
F_418 ( V_9 -> V_436 , V_9 -> V_356 ) ;
V_527:
F_249 ( & V_9 -> V_270 ) ;
return V_54 ;
}
static int F_419 ( struct V_8 * V_9 )
{
struct V_472 * V_13 = V_9 -> V_13 ;
int V_54 ;
F_23 ( F_63 ( V_9 -> V_108 ) ) ;
if ( V_9 -> V_108 == 1 )
V_54 = F_162 ( & V_9 -> V_311 , V_71 , L_145 ,
V_13 -> V_469 , V_534 ) ;
else
V_54 = F_162 ( & V_9 -> V_311 , V_71 , L_145 ,
V_535 , V_13 -> V_470 ) ;
return V_54 ;
}
static void F_420 ( struct V_8 * V_9 )
{
F_408 ( V_9 ) ;
V_9 -> V_108 = 0 ;
F_42 ( V_9 -> V_13 -> V_470 ) ;
V_9 -> V_13 -> V_470 = NULL ;
F_372 ( V_9 ) ;
}
static int F_410 ( struct V_8 * V_9 , int V_525 )
{
int V_54 ;
V_54 = F_406 ( V_9 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_419 ( V_9 ) ;
if ( V_54 )
goto V_536;
if ( ! V_525 ) {
V_54 = F_274 ( V_9 ) ;
if ( V_54 ) {
if ( V_54 == - V_49 )
F_379 ( L_151 ,
V_9 -> V_13 -> V_468 ,
V_9 -> V_13 -> V_469 ) ;
goto V_536;
}
}
V_54 = F_316 ( V_9 ) ;
if ( V_54 )
goto V_537;
if ( ! V_525 )
V_54 = F_389 ( V_9 ) ;
else
V_54 = F_390 ( V_9 ) ;
if ( V_54 ) {
if ( V_54 == - V_49 )
F_379 ( L_152 ,
V_9 -> V_13 -> V_468 ,
V_9 -> V_13 -> V_469 ,
V_9 -> V_13 -> V_149 ) ;
goto V_538;
}
if ( V_9 -> V_10 . V_11 & V_539 ) {
V_54 = F_317 ( V_9 ) ;
if ( V_54 )
goto V_538;
if ( ! V_525 && V_9 -> V_268 )
F_108 ( V_9 ,
L_153 ) ;
}
V_54 = F_409 ( V_9 , V_525 ) ;
if ( V_54 )
goto V_538;
F_31 ( L_154 ,
V_9 -> V_108 , V_9 -> V_311 . V_356 ) ;
return 0 ;
V_538:
F_408 ( V_9 ) ;
V_537:
if ( ! V_525 )
F_278 ( V_9 ) ;
V_536:
V_9 -> V_108 = 0 ;
F_42 ( V_9 -> V_13 -> V_470 ) ;
V_9 -> V_13 -> V_470 = NULL ;
return V_54 ;
}
static T_2 F_421 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
struct V_8 * V_9 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_85 * V_86 = NULL ;
struct V_472 * V_13 = NULL ;
struct V_65 * V_68 ;
bool V_17 ;
int V_540 ;
if ( ! F_422 ( V_476 ) )
return - V_541 ;
V_540 = F_399 ( V_25 , & V_67 , & V_86 , & V_13 ) ;
if ( V_540 < 0 )
goto V_61;
V_68 = F_55 ( V_67 ) ;
if ( F_36 ( V_68 ) ) {
V_540 = F_200 ( V_68 ) ;
goto V_542;
}
V_540 = F_401 ( V_68 , V_13 -> V_468 ) ;
if ( V_540 < 0 ) {
if ( V_540 == - V_49 )
F_379 ( L_155 , V_13 -> V_468 ) ;
goto V_543;
}
V_13 -> V_129 = ( V_121 ) V_540 ;
V_9 = F_368 ( V_68 , V_13 , V_86 ) ;
if ( ! V_9 ) {
V_540 = - V_69 ;
goto V_543;
}
V_68 = NULL ;
V_13 = NULL ;
V_86 = NULL ;
V_9 -> V_467 = F_76 ( V_25 , V_71 ) ;
if ( ! V_9 -> V_467 ) {
V_540 = - V_69 ;
goto V_544;
}
F_248 ( & V_9 -> V_270 ) ;
V_540 = F_410 ( V_9 , 0 ) ;
if ( V_540 < 0 ) {
F_249 ( & V_9 -> V_270 ) ;
goto V_544;
}
V_17 = V_9 -> V_412 -> V_17 ;
if ( V_9 -> V_13 -> V_14 != V_15 )
V_17 = true ;
V_9 -> V_16 . V_17 = V_17 ;
V_540 = F_412 ( V_9 ) ;
if ( V_540 ) {
F_278 ( V_9 ) ;
F_420 ( V_9 ) ;
goto V_61;
}
V_540 = V_471 ;
V_61:
F_360 ( V_476 ) ;
return V_540 ;
V_544:
F_372 ( V_9 ) ;
V_543:
F_61 ( V_68 ) ;
V_542:
F_175 ( V_13 ) ;
F_42 ( V_86 ) ;
goto V_61;
}
static T_2 F_423 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
if ( V_32 )
return - V_4 ;
return F_421 ( V_24 , V_25 , V_471 ) ;
}
static T_2 F_424 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
return F_421 ( V_24 , V_25 , V_471 ) ;
}
static void F_425 ( struct V_8 * V_9 )
{
F_301 ( V_9 ) ;
F_38 ( & V_532 ) ;
F_426 ( & V_9 -> V_74 ) ;
F_40 ( & V_532 ) ;
F_141 ( V_410 , & V_9 -> V_47 ) ;
F_427 ( & V_9 -> V_37 ) ;
F_87 ( V_9 ) ;
if ( ! V_32 )
F_418 ( V_9 -> V_436 , V_9 -> V_356 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
while ( V_9 -> V_277 ) {
struct V_8 * V_545 = V_9 ;
struct V_8 * V_546 = V_545 -> V_277 ;
struct V_8 * V_547 ;
while ( V_546 && ( V_547 = V_546 -> V_277 ) ) {
V_545 = V_546 ;
V_546 = V_547 ;
}
F_23 ( V_546 ) ;
F_420 ( V_546 ) ;
V_545 -> V_277 = NULL ;
V_545 -> V_200 = 0 ;
F_23 ( V_545 -> V_268 ) ;
F_175 ( V_545 -> V_268 ) ;
V_545 -> V_268 = NULL ;
}
}
static T_2 F_428 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
struct V_8 * V_9 = NULL ;
struct V_548 * V_165 ;
int V_5 ;
char V_549 [ 6 ] ;
bool V_550 = false ;
bool V_551 = false ;
int V_54 ;
V_5 = - 1 ;
V_549 [ 0 ] = '\0' ;
sscanf ( V_25 , L_156 , & V_5 , V_549 ) ;
if ( V_5 < 0 ) {
F_53 ( L_157 ) ;
return - V_4 ;
}
if ( V_549 [ 0 ] != '\0' ) {
if ( ! strcmp ( V_549 , L_158 ) ) {
V_551 = true ;
} else {
F_53 ( L_159 , V_549 ) ;
return - V_4 ;
}
}
V_54 = - V_49 ;
F_38 ( & V_532 ) ;
F_429 (tmp, &rbd_dev_list) {
V_9 = F_430 ( V_165 , struct V_8 , V_74 ) ;
if ( V_9 -> V_5 == V_5 ) {
V_54 = 0 ;
break;
}
}
if ( ! V_54 ) {
F_18 ( & V_9 -> V_45 ) ;
if ( V_9 -> V_48 && ! V_551 )
V_54 = - V_60 ;
else
V_550 = F_110 ( V_46 ,
& V_9 -> V_47 ) ;
F_20 ( & V_9 -> V_45 ) ;
}
F_40 ( & V_532 ) ;
if ( V_54 < 0 || V_550 )
return V_54 ;
if ( V_551 ) {
F_431 ( V_9 -> V_51 -> V_422 ) ;
F_432 ( V_9 -> V_51 -> V_422 ) ;
}
F_248 ( & V_9 -> V_22 ) ;
if ( F_10 ( V_9 ) )
F_218 ( V_9 ) ;
F_249 ( & V_9 -> V_22 ) ;
F_278 ( V_9 ) ;
F_425 ( V_9 ) ;
F_420 ( V_9 ) ;
return V_471 ;
}
static T_2 F_433 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
if ( V_32 )
return - V_4 ;
return F_428 ( V_24 , V_25 , V_471 ) ;
}
static T_2 F_434 ( struct V_23 * V_24 ,
const char * V_25 ,
T_7 V_471 )
{
return F_428 ( V_24 , V_25 , V_471 ) ;
}
static int F_435 ( void )
{
int V_54 ;
V_54 = F_436 ( & V_479 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_437 ( & V_477 ) ;
if ( V_54 < 0 )
F_438 ( & V_479 ) ;
return V_54 ;
}
static void F_439 ( void )
{
F_440 ( & V_477 ) ;
F_438 ( & V_479 ) ;
}
static int F_441 ( void )
{
F_23 ( ! V_271 ) ;
V_271 = F_442 ( V_202 , 0 ) ;
if ( ! V_271 )
return - V_69 ;
F_23 ( ! V_266 ) ;
V_266 = F_442 ( V_191 , 0 ) ;
if ( ! V_266 )
goto V_139;
return 0 ;
V_139:
F_443 ( V_271 ) ;
V_271 = NULL ;
return - V_69 ;
}
static void F_444 ( void )
{
F_23 ( V_266 ) ;
F_443 ( V_266 ) ;
V_266 = NULL ;
F_23 ( V_271 ) ;
F_443 ( V_271 ) ;
V_271 = NULL ;
}
static int T_12 F_445 ( void )
{
int V_540 ;
if ( ! F_446 ( NULL ) ) {
F_108 ( NULL , L_160 ) ;
return - V_4 ;
}
V_540 = F_441 () ;
if ( V_540 )
return V_540 ;
V_419 = F_447 ( V_398 , V_482 , 0 ) ;
if ( ! V_419 ) {
V_540 = - V_69 ;
goto V_552;
}
if ( V_32 ) {
V_528 = F_413 ( 0 , V_398 ) ;
if ( V_528 < 0 ) {
V_540 = V_528 ;
goto V_553;
}
}
V_540 = F_435 () ;
if ( V_540 )
goto V_529;
if ( V_32 )
F_379 ( L_161 , V_528 ) ;
else
F_379 ( L_162 ) ;
return 0 ;
V_529:
if ( V_32 )
F_418 ( V_528 , V_398 ) ;
V_553:
F_358 ( V_419 ) ;
V_552:
F_444 () ;
return V_540 ;
}
static void T_13 F_448 ( void )
{
F_449 ( & V_475 ) ;
F_439 () ;
if ( V_32 )
F_418 ( V_528 , V_398 ) ;
F_358 ( V_419 ) ;
F_444 () ;
}
