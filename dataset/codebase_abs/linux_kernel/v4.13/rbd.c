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
return V_9 -> V_10 == V_11 ||
V_9 -> V_10 == V_12 ;
}
static bool F_10 ( struct V_8 * V_9 )
{
bool V_13 ;
F_11 ( & V_9 -> V_14 ) ;
V_13 = F_9 ( V_9 ) ;
F_12 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static T_2 F_13 ( struct V_15 * V_16 , char * V_17 )
{
return sprintf ( V_17 , L_1 , V_18 ) ;
}
static T_3 F_14 ( struct V_19 * V_20 ,
struct V_21 * V_22 , int V_23 )
{
if ( ! V_24 &&
( V_22 == & V_25 . V_22 ||
V_22 == & V_26 . V_22 ) )
return 0 ;
return V_22 -> V_27 ;
}
static void F_15 ( struct V_28 * V_29 )
{
}
static int F_16 ( struct V_30 * V_31 , T_4 V_27 )
{
struct V_8 * V_9 = V_31 -> V_32 -> V_33 ;
bool V_34 = false ;
if ( ( V_27 & V_35 ) && V_9 -> V_36 . V_37 )
return - V_38 ;
F_17 ( & V_9 -> V_39 ) ;
if ( F_18 ( V_40 , & V_9 -> V_41 ) )
V_34 = true ;
else
V_9 -> V_42 ++ ;
F_19 ( & V_9 -> V_39 ) ;
if ( V_34 )
return - V_43 ;
( void ) F_20 ( & V_9 -> V_29 ) ;
return 0 ;
}
static void F_21 ( struct V_44 * V_45 , T_4 V_27 )
{
struct V_8 * V_9 = V_45 -> V_33 ;
unsigned long V_46 ;
F_17 ( & V_9 -> V_39 ) ;
V_46 = V_9 -> V_42 -- ;
F_19 ( & V_9 -> V_39 ) ;
F_22 ( V_46 > 0 ) ;
F_23 ( & V_9 -> V_29 ) ;
}
static int F_24 ( struct V_8 * V_9 , unsigned long V_47 )
{
int V_48 = 0 ;
int V_49 ;
bool V_50 ;
bool V_51 = false ;
if ( F_25 ( V_49 , ( int V_52 * ) ( V_47 ) ) )
return - V_53 ;
V_50 = V_49 ? true : false ;
if ( V_9 -> V_54 -> V_55 != V_56 && ! V_50 )
return - V_38 ;
F_17 ( & V_9 -> V_39 ) ;
if ( V_9 -> V_42 > 1 ) {
V_48 = - V_57 ;
goto V_58;
}
if ( V_9 -> V_36 . V_37 != V_50 ) {
V_9 -> V_36 . V_37 = V_50 ;
V_51 = true ;
}
V_58:
F_19 ( & V_9 -> V_39 ) ;
if ( V_48 == 0 && V_51 )
F_26 ( V_9 -> V_45 , V_50 ? 1 : 0 ) ;
return V_48 ;
}
static int F_27 ( struct V_30 * V_31 , T_4 V_27 ,
unsigned int V_59 , unsigned long V_47 )
{
struct V_8 * V_9 = V_31 -> V_32 -> V_33 ;
int V_48 = 0 ;
switch ( V_59 ) {
case V_60 :
V_48 = F_24 ( V_9 , V_47 ) ;
break;
default:
V_48 = - V_61 ;
}
return V_48 ;
}
static int F_28 ( struct V_30 * V_31 , T_4 V_27 ,
unsigned int V_59 , unsigned long V_47 )
{
return F_27 ( V_31 , V_27 , V_59 , V_47 ) ;
}
static struct V_62 * F_29 ( struct V_63 * V_64 )
{
struct V_62 * V_65 ;
int V_48 = - V_66 ;
F_30 ( L_2 , V_67 ) ;
V_65 = F_31 ( sizeof( struct V_62 ) , V_68 ) ;
if ( ! V_65 )
goto V_69;
F_32 ( & V_65 -> V_70 ) ;
F_33 ( & V_65 -> V_71 ) ;
V_65 -> V_72 = F_34 ( V_64 , V_65 ) ;
if ( F_35 ( V_65 -> V_72 ) )
goto V_73;
V_64 = NULL ;
V_48 = F_36 ( V_65 -> V_72 ) ;
if ( V_48 < 0 )
goto V_74;
F_37 ( & V_75 ) ;
F_38 ( & V_65 -> V_71 , & V_76 ) ;
F_39 ( & V_75 ) ;
F_30 ( L_3 , V_67 , V_65 ) ;
return V_65 ;
V_74:
F_40 ( V_65 -> V_72 ) ;
V_73:
F_41 ( V_65 ) ;
V_69:
if ( V_64 )
F_42 ( V_64 ) ;
F_30 ( L_4 , V_67 , V_48 ) ;
return F_43 ( V_48 ) ;
}
static struct V_62 * F_44 ( struct V_62 * V_65 )
{
F_45 ( & V_65 -> V_70 ) ;
return V_65 ;
}
static struct V_62 * F_46 ( struct V_63 * V_64 )
{
struct V_62 * V_77 ;
bool V_78 = false ;
if ( V_64 -> V_41 & V_79 )
return NULL ;
F_37 ( & V_75 ) ;
F_47 (client_node, &rbd_client_list, node) {
if ( ! F_48 ( V_64 , V_77 -> V_72 ) ) {
F_44 ( V_77 ) ;
V_78 = true ;
break;
}
}
F_39 ( & V_75 ) ;
return V_78 ? V_77 : NULL ;
}
static int F_49 ( char * V_80 , void * V_81 )
{
struct V_82 * V_83 = V_81 ;
T_5 V_84 [ V_85 ] ;
int V_86 , V_87 , V_48 ;
V_86 = F_50 ( V_80 , V_88 , V_84 ) ;
if ( V_86 < V_89 ) {
V_48 = F_51 ( & V_84 [ 0 ] , & V_87 ) ;
if ( V_48 < 0 ) {
F_52 ( L_5 , V_80 ) ;
return V_48 ;
}
F_30 ( L_6 , V_86 , V_87 ) ;
} else if ( V_86 > V_89 && V_86 < V_90 ) {
F_30 ( L_7 , V_86 , V_84 [ 0 ] . V_91 ) ;
} else {
F_30 ( L_8 , V_86 ) ;
}
switch ( V_86 ) {
case V_92 :
if ( V_87 < 1 ) {
F_52 ( L_9 ) ;
return - V_4 ;
}
V_83 -> V_93 = V_87 ;
break;
case V_94 :
V_83 -> V_37 = true ;
break;
case V_95 :
V_83 -> V_37 = false ;
break;
case V_96 :
V_83 -> V_97 = true ;
break;
case V_98 :
V_83 -> V_99 = true ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static char * F_53 ( enum V_100 V_101 )
{
switch ( V_101 ) {
case V_102 :
return L_10 ;
case V_103 :
return L_11 ;
case V_104 :
return L_12 ;
default:
return L_13 ;
}
}
static struct V_62 * F_54 ( struct V_63 * V_64 )
{
struct V_62 * V_65 ;
F_55 ( & V_105 , V_106 ) ;
V_65 = F_46 ( V_64 ) ;
if ( V_65 )
F_42 ( V_64 ) ;
else
V_65 = F_29 ( V_64 ) ;
F_56 ( & V_105 ) ;
return V_65 ;
}
static void F_57 ( struct V_70 * V_70 )
{
struct V_62 * V_65 = F_58 ( V_70 , struct V_62 , V_70 ) ;
F_30 ( L_3 , V_67 , V_65 ) ;
F_37 ( & V_75 ) ;
F_59 ( & V_65 -> V_71 ) ;
F_39 ( & V_75 ) ;
F_40 ( V_65 -> V_72 ) ;
F_41 ( V_65 ) ;
}
static void F_60 ( struct V_62 * V_65 )
{
if ( V_65 )
F_61 ( & V_65 -> V_70 , F_57 ) ;
}
static bool F_62 ( T_6 V_107 )
{
return V_107 == 1 || V_107 == 2 ;
}
static bool F_63 ( struct V_108 * V_109 )
{
T_7 V_110 ;
T_6 V_111 ;
if ( memcmp ( & V_109 -> V_112 , V_113 , sizeof ( V_113 ) ) )
return false ;
if ( V_109 -> V_114 . V_115 < V_116 )
return false ;
if ( V_109 -> V_114 . V_115 > 8 * sizeof ( int ) - 1 )
return false ;
V_111 = F_64 ( V_109 -> V_111 ) ;
V_110 = V_117 - sizeof ( struct V_118 ) ;
if ( V_111 > V_110 / sizeof ( V_119 ) )
return false ;
V_110 -= V_111 * sizeof ( V_119 ) ;
if ( ( V_120 ) V_110 < F_65 ( V_109 -> V_121 ) )
return false ;
return true ;
}
static T_6 F_66 ( struct V_122 * V_123 )
{
return 1U << V_123 -> V_124 ;
}
static void F_67 ( struct V_8 * V_9 )
{
if ( V_9 -> V_123 . V_125 == 0 ||
V_9 -> V_123 . V_126 == 0 ) {
V_9 -> V_123 . V_125 = F_66 ( & V_9 -> V_123 ) ;
V_9 -> V_123 . V_126 = 1 ;
}
V_9 -> V_127 . V_125 = V_9 -> V_123 . V_125 ;
V_9 -> V_127 . V_126 = V_9 -> V_123 . V_126 ;
V_9 -> V_127 . V_128 = F_66 ( & V_9 -> V_123 ) ;
V_9 -> V_127 . V_129 = V_9 -> V_123 . V_130 == V_131 ?
V_9 -> V_54 -> V_129 : V_9 -> V_123 . V_130 ;
F_68 ( V_9 -> V_127 . V_132 , NULL ) ;
}
static int F_69 ( struct V_8 * V_9 ,
struct V_108 * V_109 )
{
struct V_122 * V_123 = & V_9 -> V_123 ;
bool V_133 = V_123 -> V_134 == NULL ;
struct V_118 * V_135 ;
char * V_134 = NULL ;
char * V_136 = NULL ;
V_120 * V_137 = NULL ;
T_6 V_111 ;
int V_48 = - V_66 ;
T_6 V_138 ;
if ( V_133 ) {
V_134 = F_70 ( V_109 -> V_134 ,
sizeof( V_109 -> V_134 ) ,
V_68 ) ;
if ( ! V_134 )
return - V_66 ;
}
V_111 = F_64 ( V_109 -> V_111 ) ;
V_135 = F_71 ( V_111 , V_68 ) ;
if ( ! V_135 )
goto V_139;
V_135 -> V_140 = F_65 ( V_109 -> V_141 ) ;
if ( V_111 ) {
struct V_142 * V_143 ;
V_120 V_121 = F_65 ( V_109 -> V_121 ) ;
if ( V_121 > ( V_120 ) V_117 )
goto V_144;
V_136 = F_31 ( V_121 , V_68 ) ;
if ( ! V_136 )
goto V_139;
V_137 = F_72 ( V_111 ,
sizeof( * V_123 -> V_137 ) ,
V_68 ) ;
if ( ! V_137 )
goto V_139;
memcpy ( V_136 , & V_109 -> V_143 [ V_111 ] , V_121 ) ;
V_143 = V_109 -> V_143 ;
for ( V_138 = 0 ; V_138 < V_111 ; V_138 ++ ) {
V_135 -> V_143 [ V_138 ] = F_65 ( V_143 [ V_138 ] . V_145 ) ;
V_137 [ V_138 ] = F_65 ( V_143 [ V_138 ] . V_146 ) ;
}
}
if ( V_133 ) {
V_123 -> V_134 = V_134 ;
V_123 -> V_124 = V_109 -> V_114 . V_115 ;
F_67 ( V_9 ) ;
} else {
F_73 ( V_123 -> V_135 ) ;
F_41 ( V_123 -> V_136 ) ;
F_41 ( V_123 -> V_137 ) ;
}
V_123 -> V_146 = F_65 ( V_109 -> V_146 ) ;
V_123 -> V_135 = V_135 ;
V_123 -> V_136 = V_136 ;
V_123 -> V_137 = V_137 ;
return 0 ;
V_144:
V_48 = - V_147 ;
V_139:
F_41 ( V_137 ) ;
F_41 ( V_136 ) ;
F_73 ( V_135 ) ;
F_41 ( V_134 ) ;
return V_48 ;
}
static const char * F_74 ( struct V_8 * V_9 , T_6 V_148 )
{
const char * V_149 ;
F_22 ( V_148 < V_9 -> V_123 . V_135 -> V_150 ) ;
V_149 = V_9 -> V_123 . V_136 ;
while ( V_148 -- )
V_149 += strlen ( V_149 ) + 1 ;
return F_75 ( V_149 , V_68 ) ;
}
static int F_76 ( const void * V_151 , const void * V_152 )
{
V_120 V_153 = * ( V_120 * ) V_151 ;
V_120 V_154 = * ( V_120 * ) V_152 ;
if ( V_153 < V_154 )
return 1 ;
return V_153 == V_154 ? 0 : - 1 ;
}
static T_6 F_77 ( struct V_8 * V_9 , V_120 V_55 )
{
struct V_118 * V_135 = V_9 -> V_123 . V_135 ;
V_120 * V_78 ;
V_78 = bsearch ( & V_55 , & V_135 -> V_143 , V_135 -> V_150 ,
sizeof ( V_55 ) , F_76 ) ;
return V_78 ? ( T_6 ) ( V_78 - & V_135 -> V_143 [ 0 ] ) : V_155 ;
}
static const char * F_78 ( struct V_8 * V_9 ,
V_120 V_55 )
{
T_6 V_148 ;
const char * V_149 ;
V_148 = F_77 ( V_9 , V_55 ) ;
if ( V_148 == V_155 )
return F_43 ( - V_43 ) ;
V_149 = F_74 ( V_9 , V_148 ) ;
return V_149 ? V_149 : F_43 ( - V_66 ) ;
}
static const char * F_79 ( struct V_8 * V_9 , V_120 V_55 )
{
if ( V_55 == V_56 )
return V_156 ;
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_9 -> V_107 == 1 )
return F_78 ( V_9 , V_55 ) ;
return F_80 ( V_9 , V_55 ) ;
}
static int F_81 ( struct V_8 * V_9 , V_120 V_55 ,
V_120 * V_157 )
{
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_55 == V_56 ) {
* V_157 = V_9 -> V_123 . V_146 ;
} else if ( V_9 -> V_107 == 1 ) {
T_6 V_148 ;
V_148 = F_77 ( V_9 , V_55 ) ;
if ( V_148 == V_155 )
return - V_43 ;
* V_157 = V_9 -> V_123 . V_137 [ V_148 ] ;
} else {
V_120 V_110 = 0 ;
int V_48 ;
V_48 = F_82 ( V_9 , V_55 , NULL , & V_110 ) ;
if ( V_48 )
return V_48 ;
* V_157 = V_110 ;
}
return 0 ;
}
static int F_83 ( struct V_8 * V_9 , V_120 V_55 ,
V_120 * V_158 )
{
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_55 == V_56 ) {
* V_158 = V_9 -> V_123 . V_159 ;
} else if ( V_9 -> V_107 == 1 ) {
* V_158 = 0 ;
} else {
V_120 V_159 = 0 ;
int V_48 ;
V_48 = F_84 ( V_9 , V_55 , & V_159 ) ;
if ( V_48 )
return V_48 ;
* V_158 = V_159 ;
}
return 0 ;
}
static int F_85 ( struct V_8 * V_9 )
{
V_120 V_55 = V_9 -> V_54 -> V_55 ;
V_120 V_110 = 0 ;
V_120 V_159 = 0 ;
int V_48 ;
V_48 = F_81 ( V_9 , V_55 , & V_110 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_83 ( V_9 , V_55 , & V_159 ) ;
if ( V_48 )
return V_48 ;
V_9 -> V_36 . V_110 = V_110 ;
V_9 -> V_36 . V_159 = V_159 ;
return 0 ;
}
static void F_86 ( struct V_8 * V_9 )
{
V_9 -> V_36 . V_110 = 0 ;
V_9 -> V_36 . V_159 = 0 ;
}
static V_120 F_87 ( struct V_8 * V_9 , V_120 V_160 )
{
V_120 V_161 = F_66 ( & V_9 -> V_123 ) ;
return V_160 & ( V_161 - 1 ) ;
}
static V_120 F_88 ( struct V_8 * V_9 ,
V_120 V_160 , V_120 V_162 )
{
V_120 V_161 = F_66 ( & V_9 -> V_123 ) ;
V_160 &= V_161 - 1 ;
F_22 ( V_162 <= V_163 - V_160 ) ;
if ( V_160 + V_162 > V_161 )
V_162 = V_161 - V_160 ;
return V_162 ;
}
static void F_89 ( struct V_164 * V_165 )
{
struct V_164 * V_166 ;
while ( V_165 ) {
V_166 = V_165 ;
V_165 = V_165 -> V_167 ;
F_90 ( V_166 ) ;
}
}
static void F_91 ( struct V_164 * V_165 , int V_168 )
{
struct V_169 V_170 ;
struct V_171 V_172 ;
unsigned long V_41 ;
void * V_17 ;
int V_173 = 0 ;
while ( V_165 ) {
F_92 (bv, chain, iter) {
if ( V_173 + V_170 . V_174 > V_168 ) {
int V_175 = F_93 ( V_168 - V_173 , 0 ) ;
V_17 = F_94 ( & V_170 , & V_41 ) ;
memset ( V_17 + V_175 , 0 ,
V_170 . V_174 - V_175 ) ;
F_95 ( V_170 . V_176 ) ;
F_96 ( V_17 , & V_41 ) ;
}
V_173 += V_170 . V_174 ;
}
V_165 = V_165 -> V_167 ;
}
}
static void F_97 ( struct V_177 * * V_178 , V_120 V_160 , V_120 V_179 )
{
struct V_177 * * V_177 = & V_178 [ V_160 >> V_180 ] ;
F_22 ( V_179 > V_160 ) ;
F_22 ( V_179 - V_160 <= ( V_120 ) V_117 ) ;
while ( V_160 < V_179 ) {
T_7 V_181 ;
T_7 V_162 ;
unsigned long V_41 ;
void * V_182 ;
V_181 = V_160 & ~ V_183 ;
V_162 = F_98 ( T_7 , V_184 - V_181 , V_179 - V_160 ) ;
F_99 ( V_41 ) ;
V_182 = F_100 ( * V_177 ) ;
memset ( V_182 + V_181 , 0 , V_162 ) ;
F_95 ( * V_177 ) ;
F_101 ( V_182 ) ;
F_102 ( V_41 ) ;
V_160 += V_162 ;
V_177 ++ ;
}
}
static struct V_164 * F_103 ( struct V_164 * V_185 ,
unsigned int V_160 ,
unsigned int V_186 ,
T_8 V_187 )
{
struct V_164 * V_164 ;
V_164 = F_104 ( V_185 , V_187 , V_188 ) ;
if ( ! V_164 )
return NULL ;
F_105 ( V_164 , V_160 ) ;
V_164 -> V_189 . V_190 = V_186 ;
return V_164 ;
}
static struct V_164 * F_106 ( struct V_164 * * V_185 ,
unsigned int * V_160 ,
unsigned int V_186 ,
T_8 V_187 )
{
struct V_164 * V_191 = * V_185 ;
unsigned int V_192 = * V_160 ;
struct V_164 * V_165 = NULL ;
struct V_164 * * V_179 ;
if ( ! V_191 || V_192 >= V_191 -> V_189 . V_190 || ! V_186 )
return NULL ;
V_179 = & V_165 ;
while ( V_186 ) {
unsigned int V_190 ;
struct V_164 * V_164 ;
if ( ! V_191 ) {
F_107 ( NULL , L_14 , V_186 ) ;
goto V_139;
}
V_190 = F_98 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_164 = F_103 ( V_191 , V_192 , V_190 , V_187 ) ;
if ( ! V_164 )
goto V_139;
* V_179 = V_164 ;
V_179 = & V_164 -> V_167 ;
V_192 += V_190 ;
if ( V_192 == V_191 -> V_189 . V_190 ) {
V_191 = V_191 -> V_167 ;
V_192 = 0 ;
}
V_186 -= V_190 ;
}
* V_185 = V_191 ;
* V_160 = V_192 ;
return V_165 ;
V_139:
F_89 ( V_165 ) ;
return NULL ;
}
static void F_108 ( struct V_193 * V_194 )
{
if ( F_109 ( V_195 , & V_194 -> V_41 ) ) {
struct V_8 * V_9 ;
V_9 = V_194 -> V_196 -> V_9 ;
F_107 ( V_9 , L_15 ,
V_194 ) ;
}
}
static bool F_110 ( struct V_193 * V_194 )
{
F_111 () ;
return F_18 ( V_195 , & V_194 -> V_41 ) != 0 ;
}
static void F_112 ( struct V_193 * V_194 )
{
if ( F_109 ( V_197 , & V_194 -> V_41 ) ) {
struct V_8 * V_9 = NULL ;
if ( F_110 ( V_194 ) )
V_9 = V_194 -> V_196 -> V_9 ;
F_107 ( V_9 , L_16 ,
V_194 ) ;
}
}
static bool F_113 ( struct V_193 * V_194 )
{
F_111 () ;
return F_18 ( V_197 , & V_194 -> V_41 ) != 0 ;
}
static void F_114 ( struct V_193 * V_194 ,
bool V_198 )
{
if ( V_198 )
F_115 ( V_199 , & V_194 -> V_41 ) ;
F_115 ( V_200 , & V_194 -> V_41 ) ;
F_111 () ;
}
static bool F_116 ( struct V_193 * V_194 )
{
F_111 () ;
return F_18 ( V_200 , & V_194 -> V_41 ) != 0 ;
}
static bool F_117 ( struct V_193 * V_194 )
{
F_111 () ;
return F_18 ( V_199 , & V_194 -> V_41 ) != 0 ;
}
static bool F_118 ( struct V_193 * V_194 )
{
struct V_8 * V_9 = V_194 -> V_196 -> V_9 ;
return V_194 -> V_201 <
F_119 ( V_9 -> V_202 , F_66 ( & V_9 -> V_123 ) ) ;
}
static void F_120 ( struct V_193 * V_194 )
{
F_30 ( L_17 , V_67 , V_194 ,
F_121 ( & V_194 -> V_70 ) ) ;
F_45 ( & V_194 -> V_70 ) ;
}
static void F_122 ( struct V_193 * V_194 )
{
F_22 ( V_194 != NULL ) ;
F_30 ( L_17 , V_67 , V_194 ,
F_121 ( & V_194 -> V_70 ) ) ;
F_61 ( & V_194 -> V_70 , V_203 ) ;
}
static void F_123 ( struct V_204 * V_196 )
{
F_30 ( L_18 , V_67 , V_196 ,
F_121 ( & V_196 -> V_70 ) ) ;
F_45 ( & V_196 -> V_70 ) ;
}
static void F_124 ( struct V_204 * V_196 )
{
F_22 ( V_196 != NULL ) ;
F_30 ( L_18 , V_67 , V_196 ,
F_121 ( & V_196 -> V_70 ) ) ;
if ( F_125 ( V_196 ) )
F_61 ( & V_196 -> V_70 , V_205 ) ;
else
F_61 ( & V_196 -> V_70 , V_206 ) ;
}
static inline void F_126 ( struct V_204 * V_196 ,
struct V_193 * V_194 )
{
F_22 ( V_194 -> V_196 == NULL ) ;
V_194 -> V_196 = V_196 ;
V_194 -> V_148 = V_196 -> V_207 ;
F_22 ( ! F_110 ( V_194 ) ) ;
F_108 ( V_194 ) ;
F_22 ( V_194 -> V_148 != V_208 ) ;
V_196 -> V_207 ++ ;
F_38 ( & V_194 -> V_209 , & V_196 -> V_210 ) ;
F_30 ( L_19 , V_67 , V_196 , V_194 ,
V_194 -> V_148 ) ;
}
static inline void F_127 ( struct V_204 * V_196 ,
struct V_193 * V_194 )
{
F_22 ( V_194 -> V_148 != V_208 ) ;
F_30 ( L_19 , V_67 , V_196 , V_194 ,
V_194 -> V_148 ) ;
F_59 ( & V_194 -> V_209 ) ;
F_22 ( V_196 -> V_207 > 0 ) ;
V_196 -> V_207 -- ;
F_22 ( V_194 -> V_148 == V_196 -> V_207 ) ;
V_194 -> V_148 = V_208 ;
F_22 ( F_110 ( V_194 ) ) ;
F_22 ( V_194 -> V_196 == V_196 ) ;
V_194 -> V_196 = NULL ;
V_194 -> V_211 = NULL ;
F_122 ( V_194 ) ;
}
static bool F_128 ( enum V_212 type )
{
switch ( type ) {
case V_213 :
case V_214 :
case V_215 :
return true ;
default:
return false ;
}
}
static void F_129 ( struct V_193 * V_194 )
{
struct V_216 * V_217 = V_194 -> V_217 ;
F_30 ( L_20 , V_67 ,
V_194 , V_194 -> V_218 , V_194 -> V_160 ,
V_194 -> V_162 , V_217 ) ;
if ( F_110 ( V_194 ) ) {
F_130 ( V_194 -> V_211 != V_219 ) ;
F_123 ( V_194 -> V_196 ) ;
}
F_131 ( V_217 -> V_220 , V_217 , false ) ;
}
static void F_132 ( struct V_204 * V_196 )
{
F_30 ( L_21 , V_67 , V_196 ) ;
if ( ! V_196 -> V_221 ) {
struct V_193 * V_194 ;
V_120 V_222 = 0 ;
F_133 (img_request, obj_request)
V_222 += V_194 -> V_222 ;
V_196 -> V_222 = V_222 ;
}
if ( V_196 -> V_211 )
V_196 -> V_211 ( V_196 ) ;
else
F_124 ( V_196 ) ;
}
static void F_134 ( struct V_204 * V_196 )
{
F_115 ( V_223 , & V_196 -> V_41 ) ;
F_111 () ;
}
static bool F_135 ( struct V_204 * V_196 )
{
F_111 () ;
return F_18 ( V_223 , & V_196 -> V_41 ) != 0 ;
}
static void F_136 ( struct V_204 * V_196 )
{
F_115 ( V_224 , & V_196 -> V_41 ) ;
F_111 () ;
}
static bool F_137 ( struct V_204 * V_196 )
{
F_111 () ;
return F_18 ( V_224 , & V_196 -> V_41 ) != 0 ;
}
static void F_138 ( struct V_204 * V_196 )
{
F_115 ( V_225 , & V_196 -> V_41 ) ;
F_111 () ;
}
static void F_139 ( struct V_204 * V_196 )
{
F_140 ( V_225 , & V_196 -> V_41 ) ;
F_111 () ;
}
static bool F_125 ( struct V_204 * V_196 )
{
F_111 () ;
return F_18 ( V_225 , & V_196 -> V_41 ) != 0 ;
}
static void F_141 ( struct V_204 * V_196 )
{
F_115 ( V_226 , & V_196 -> V_41 ) ;
F_111 () ;
}
static void F_142 ( struct V_204 * V_196 )
{
F_140 ( V_226 , & V_196 -> V_41 ) ;
F_111 () ;
}
static bool F_143 ( struct V_204 * V_196 )
{
F_111 () ;
return F_18 ( V_226 , & V_196 -> V_41 ) != 0 ;
}
static enum V_100
F_144 ( struct V_204 * V_196 )
{
if ( F_135 ( V_196 ) )
return V_103 ;
else if ( F_137 ( V_196 ) )
return V_104 ;
else
return V_102 ;
}
static void
F_145 ( struct V_193 * V_194 )
{
V_120 V_222 = V_194 -> V_222 ;
V_120 V_162 = V_194 -> V_162 ;
F_30 ( L_22 , V_67 ,
V_194 , V_194 -> V_196 , V_194 -> V_221 ,
V_222 , V_162 ) ;
F_22 ( V_194 -> type != V_213 ) ;
if ( V_194 -> V_221 == - V_43 ) {
if ( V_194 -> type == V_214 )
F_91 ( V_194 -> V_227 , 0 ) ;
else
F_97 ( V_194 -> V_178 , 0 , V_162 ) ;
V_194 -> V_221 = 0 ;
} else if ( V_222 < V_162 && ! V_194 -> V_221 ) {
if ( V_194 -> type == V_214 )
F_91 ( V_194 -> V_227 , V_222 ) ;
else
F_97 ( V_194 -> V_178 , V_222 , V_162 ) ;
}
V_194 -> V_222 = V_162 ;
F_112 ( V_194 ) ;
}
static void F_146 ( struct V_193 * V_194 )
{
F_30 ( L_23 , V_67 , V_194 ,
V_194 -> V_211 ) ;
if ( V_194 -> V_211 )
V_194 -> V_211 ( V_194 ) ;
else
F_147 ( & V_194 -> V_228 ) ;
}
static void F_148 ( struct V_193 * V_194 , int V_229 )
{
V_194 -> V_221 = V_229 ;
V_194 -> V_222 = 0 ;
if ( F_110 ( V_194 ) ) {
F_130 ( V_194 -> V_211 != V_219 ) ;
F_123 ( V_194 -> V_196 ) ;
}
F_112 ( V_194 ) ;
F_146 ( V_194 ) ;
}
static void F_149 ( struct V_193 * V_194 )
{
struct V_204 * V_196 = NULL ;
struct V_8 * V_9 = NULL ;
bool V_230 = false ;
if ( F_110 ( V_194 ) ) {
V_196 = V_194 -> V_196 ;
V_230 = V_196 && F_143 ( V_196 ) ;
V_9 = V_196 -> V_9 ;
}
F_30 ( L_22 , V_67 ,
V_194 , V_196 , V_194 -> V_221 ,
V_194 -> V_222 , V_194 -> V_162 ) ;
if ( V_230 && V_194 -> V_221 == - V_43 &&
V_194 -> V_201 < V_9 -> V_202 )
F_150 ( V_194 ) ;
else if ( V_196 )
F_145 ( V_194 ) ;
else
F_112 ( V_194 ) ;
}
static void F_151 ( struct V_193 * V_194 )
{
F_30 ( L_24 , V_67 , V_194 ,
V_194 -> V_221 , V_194 -> V_162 ) ;
V_194 -> V_222 = V_194 -> V_162 ;
F_112 ( V_194 ) ;
}
static void F_152 ( struct V_193 * V_194 )
{
F_30 ( L_24 , V_67 , V_194 ,
V_194 -> V_221 , V_194 -> V_162 ) ;
V_194 -> V_222 = V_194 -> V_162 ;
if ( V_194 -> V_221 == - V_43 )
V_194 -> V_221 = 0 ;
F_112 ( V_194 ) ;
}
static void F_153 ( struct V_193 * V_194 )
{
F_30 ( L_25 , V_67 , V_194 ) ;
F_112 ( V_194 ) ;
}
static void F_154 ( struct V_193 * V_194 )
{
F_30 ( L_25 , V_67 , V_194 ) ;
if ( F_110 ( V_194 ) )
F_155 ( V_194 ) ;
else
F_112 ( V_194 ) ;
}
static void F_156 ( struct V_216 * V_217 )
{
struct V_193 * V_194 = V_217 -> V_231 ;
T_9 V_232 ;
F_30 ( L_26 , V_67 , V_217 ) ;
F_22 ( V_217 == V_194 -> V_217 ) ;
if ( F_110 ( V_194 ) ) {
F_22 ( V_194 -> V_196 ) ;
F_22 ( V_194 -> V_148 != V_208 ) ;
} else {
F_22 ( V_194 -> V_148 == V_208 ) ;
}
if ( V_217 -> V_233 < 0 )
V_194 -> V_221 = V_217 -> V_233 ;
V_194 -> V_222 = V_217 -> V_234 [ 0 ] . V_235 ;
F_22 ( V_194 -> V_222 < ( V_120 ) V_236 ) ;
V_232 = V_217 -> V_234 [ 0 ] . V_237 ;
switch ( V_232 ) {
case V_238 :
F_149 ( V_194 ) ;
break;
case V_239 :
F_22 ( V_217 -> V_234 [ 1 ] . V_237 == V_240 ||
V_217 -> V_234 [ 1 ] . V_237 == V_241 ) ;
case V_240 :
case V_241 :
F_151 ( V_194 ) ;
break;
case V_242 :
F_153 ( V_194 ) ;
break;
case V_243 :
case V_244 :
case V_245 :
F_152 ( V_194 ) ;
break;
case V_246 :
F_154 ( V_194 ) ;
break;
default:
F_107 ( NULL , L_27 ,
V_194 -> V_218 , V_232 ) ;
break;
}
if ( F_113 ( V_194 ) )
F_146 ( V_194 ) ;
}
static void F_157 ( struct V_193 * V_194 )
{
struct V_216 * V_217 = V_194 -> V_217 ;
F_22 ( F_110 ( V_194 ) ) ;
V_217 -> V_247 = V_194 -> V_196 -> V_55 ;
}
static void F_158 ( struct V_193 * V_194 )
{
struct V_216 * V_217 = V_194 -> V_217 ;
F_159 ( & V_217 -> V_248 ) ;
V_217 -> V_249 = V_194 -> V_160 ;
}
static struct V_216 *
F_160 ( struct V_8 * V_9 ,
struct V_118 * V_135 ,
int V_250 , unsigned int V_41 ,
struct V_193 * V_194 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_216 * V_253 ;
const char * V_254 = V_9 -> V_107 == 1 ?
V_255 : V_256 ;
V_253 = F_161 ( V_252 , V_135 , V_250 , false , V_257 ) ;
if ( ! V_253 )
return NULL ;
V_253 -> V_258 = V_41 ;
V_253 -> V_259 = F_156 ;
V_253 -> V_231 = V_194 ;
V_253 -> V_260 . V_261 = V_9 -> V_127 . V_129 ;
if ( F_162 ( & V_253 -> V_262 , V_257 , V_254 ,
V_9 -> V_123 . V_134 , V_194 -> V_218 ) )
goto V_263;
if ( F_163 ( V_253 , V_257 ) )
goto V_263;
return V_253 ;
V_263:
F_164 ( V_253 ) ;
return NULL ;
}
static struct V_216 * F_165 (
struct V_8 * V_9 ,
enum V_100 V_101 ,
unsigned int V_250 ,
struct V_193 * V_194 )
{
struct V_118 * V_135 = NULL ;
if ( F_110 ( V_194 ) &&
( V_101 == V_104 || V_101 == V_103 ) ) {
struct V_204 * V_196 = V_194 -> V_196 ;
if ( V_101 == V_103 ) {
F_22 ( F_135 ( V_196 ) ) ;
} else {
F_22 ( F_137 ( V_196 ) ) ;
}
V_135 = V_196 -> V_135 ;
}
F_22 ( V_250 == 1 || ( ( V_101 == V_103 ) && V_250 == 2 ) ) ;
return F_160 ( V_9 , V_135 , V_250 ,
( V_101 == V_103 || V_101 == V_104 ) ?
V_264 : V_265 , V_194 ) ;
}
static struct V_216 *
F_166 ( struct V_193 * V_194 )
{
struct V_204 * V_196 ;
int V_266 = 3 ;
F_22 ( F_110 ( V_194 ) ) ;
V_196 = V_194 -> V_196 ;
F_22 ( V_196 ) ;
F_22 ( F_135 ( V_196 ) ||
F_137 ( V_196 ) ) ;
if ( F_137 ( V_196 ) )
V_266 = 2 ;
return F_160 ( V_196 -> V_9 ,
V_196 -> V_135 , V_266 ,
V_264 , V_194 ) ;
}
static void F_167 ( struct V_216 * V_217 )
{
F_164 ( V_217 ) ;
}
static struct V_193 *
F_168 ( enum V_212 type )
{
struct V_193 * V_194 ;
F_22 ( F_128 ( type ) ) ;
V_194 = F_169 ( V_267 , V_257 ) ;
if ( ! V_194 )
return NULL ;
V_194 -> V_148 = V_208 ;
V_194 -> type = type ;
F_33 ( & V_194 -> V_209 ) ;
F_170 ( & V_194 -> V_228 ) ;
F_32 ( & V_194 -> V_70 ) ;
F_30 ( L_28 , V_67 , V_194 ) ;
return V_194 ;
}
static void V_203 ( struct V_70 * V_70 )
{
struct V_193 * V_194 ;
V_194 = F_58 ( V_70 , struct V_193 , V_70 ) ;
F_30 ( L_25 , V_67 , V_194 ) ;
F_22 ( V_194 -> V_196 == NULL ) ;
F_22 ( V_194 -> V_148 == V_208 ) ;
if ( V_194 -> V_217 )
F_167 ( V_194 -> V_217 ) ;
F_22 ( F_128 ( V_194 -> type ) ) ;
switch ( V_194 -> type ) {
case V_213 :
break;
case V_214 :
if ( V_194 -> V_227 )
F_89 ( V_194 -> V_227 ) ;
break;
case V_215 :
if ( V_194 -> V_178 &&
! F_110 ( V_194 ) )
F_171 ( V_194 -> V_178 ,
V_194 -> V_268 ) ;
break;
}
F_172 ( V_267 , V_194 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_174 ( V_9 ) ;
F_175 ( V_9 -> V_269 ) ;
V_9 -> V_269 = NULL ;
V_9 -> V_202 = 0 ;
}
static void F_176 ( struct V_8 * V_9 )
{
int V_2 ;
if ( ! V_9 -> V_269 )
return;
V_2 = F_4 ( & V_9 -> V_270 ) ;
if ( V_2 > 0 )
return;
if ( ! V_2 )
F_173 ( V_9 ) ;
else
F_107 ( V_9 , L_29 ) ;
}
static bool F_177 ( struct V_8 * V_9 )
{
int V_2 = 0 ;
if ( ! V_9 -> V_269 )
return false ;
F_11 ( & V_9 -> V_271 ) ;
if ( V_9 -> V_202 )
V_2 = F_1 ( & V_9 -> V_270 ) ;
F_12 ( & V_9 -> V_271 ) ;
if ( V_2 < 0 )
F_107 ( V_9 , L_30 ) ;
return V_2 > 0 ;
}
static struct V_204 * F_178 (
struct V_8 * V_9 ,
V_120 V_160 , V_120 V_162 ,
enum V_100 V_101 ,
struct V_118 * V_135 )
{
struct V_204 * V_196 ;
V_196 = F_179 ( V_272 , V_257 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_273 = NULL ;
V_196 -> V_9 = V_9 ;
V_196 -> V_160 = V_160 ;
V_196 -> V_162 = V_162 ;
V_196 -> V_41 = 0 ;
if ( V_101 == V_104 ) {
F_136 ( V_196 ) ;
V_196 -> V_135 = V_135 ;
} else if ( V_101 == V_103 ) {
F_134 ( V_196 ) ;
V_196 -> V_135 = V_135 ;
} else {
V_196 -> V_55 = V_9 -> V_54 -> V_55 ;
}
if ( F_177 ( V_9 ) )
F_141 ( V_196 ) ;
F_180 ( & V_196 -> V_274 ) ;
V_196 -> V_275 = 0 ;
V_196 -> V_211 = NULL ;
V_196 -> V_221 = 0 ;
V_196 -> V_207 = 0 ;
F_33 ( & V_196 -> V_210 ) ;
F_32 ( & V_196 -> V_70 ) ;
F_30 ( L_31 , V_67 , V_9 ,
F_53 ( V_101 ) , V_160 , V_162 , V_196 ) ;
return V_196 ;
}
static void V_206 ( struct V_70 * V_70 )
{
struct V_204 * V_196 ;
struct V_193 * V_194 ;
struct V_193 * V_276 ;
V_196 = F_58 ( V_70 , struct V_204 , V_70 ) ;
F_30 ( L_21 , V_67 , V_196 ) ;
F_181 (img_request, obj_request, next_obj_request)
F_127 ( V_196 , V_194 ) ;
F_22 ( V_196 -> V_207 == 0 ) ;
if ( F_143 ( V_196 ) ) {
F_142 ( V_196 ) ;
F_176 ( V_196 -> V_9 ) ;
}
if ( F_135 ( V_196 ) ||
F_137 ( V_196 ) )
F_73 ( V_196 -> V_135 ) ;
F_172 ( V_272 , V_196 ) ;
}
static struct V_204 * F_182 (
struct V_193 * V_194 ,
V_120 V_201 , V_120 V_162 )
{
struct V_204 * V_277 ;
struct V_8 * V_9 ;
F_22 ( V_194 -> V_196 ) ;
V_9 = V_194 -> V_196 -> V_9 ;
V_277 = F_178 ( V_9 -> V_278 , V_201 ,
V_162 , V_102 , NULL ) ;
if ( ! V_277 )
return NULL ;
F_138 ( V_277 ) ;
F_120 ( V_194 ) ;
V_277 -> V_194 = V_194 ;
return V_277 ;
}
static void V_205 ( struct V_70 * V_70 )
{
struct V_204 * V_277 ;
struct V_193 * V_279 ;
V_277 = F_58 ( V_70 , struct V_204 , V_70 ) ;
V_279 = V_277 -> V_194 ;
V_277 -> V_194 = NULL ;
F_122 ( V_279 ) ;
F_139 ( V_277 ) ;
V_206 ( V_70 ) ;
}
static bool F_183 ( struct V_193 * V_194 )
{
struct V_204 * V_196 ;
unsigned int V_222 ;
int V_221 ;
bool V_280 ;
F_22 ( F_110 ( V_194 ) ) ;
V_196 = V_194 -> V_196 ;
F_22 ( V_194 -> V_222 <= ( V_120 ) V_236 ) ;
V_222 = ( unsigned int ) V_194 -> V_222 ;
V_221 = V_194 -> V_221 ;
if ( V_221 ) {
struct V_8 * V_9 = V_196 -> V_9 ;
enum V_100 V_101 ;
if ( F_137 ( V_196 ) )
V_101 = V_104 ;
else if ( F_135 ( V_196 ) )
V_101 = V_103 ;
else
V_101 = V_102 ;
F_107 ( V_9 , L_32 ,
F_53 ( V_101 ) , V_194 -> V_162 ,
V_194 -> V_201 , V_194 -> V_160 ) ;
F_107 ( V_9 , L_33 ,
V_221 , V_222 ) ;
if ( ! V_196 -> V_221 )
V_196 -> V_221 = V_221 ;
V_222 = V_194 -> V_162 ;
}
if ( F_125 ( V_196 ) ) {
F_22 ( V_196 -> V_194 != NULL ) ;
V_280 = V_194 -> V_148 < V_196 -> V_207 - 1 ;
} else {
T_10 V_281 = F_184 ( V_221 ) ;
F_22 ( V_196 -> V_273 != NULL ) ;
V_280 = F_185 ( V_196 -> V_273 , V_281 , V_222 ) ;
if ( ! V_280 )
F_186 ( V_196 -> V_273 , V_281 ) ;
}
return V_280 ;
}
static void V_219 ( struct V_193 * V_194 )
{
struct V_204 * V_196 ;
T_6 V_148 = V_194 -> V_148 ;
bool V_280 = true ;
F_22 ( F_110 ( V_194 ) ) ;
V_196 = V_194 -> V_196 ;
F_30 ( L_34 , V_67 , V_196 , V_194 ) ;
F_22 ( V_196 != NULL ) ;
F_22 ( V_196 -> V_207 > 0 ) ;
F_22 ( V_148 != V_208 ) ;
F_22 ( V_148 < V_196 -> V_207 ) ;
F_17 ( & V_196 -> V_274 ) ;
if ( V_148 != V_196 -> V_275 )
goto V_58;
F_187 (img_request, obj_request) {
F_22 ( V_280 ) ;
F_22 ( V_148 < V_196 -> V_207 ) ;
if ( ! F_113 ( V_194 ) )
break;
V_280 = F_183 ( V_194 ) ;
V_148 ++ ;
}
F_22 ( V_280 ^ ( V_148 == V_196 -> V_207 ) ) ;
V_196 -> V_275 = V_148 ;
V_58:
F_19 ( & V_196 -> V_274 ) ;
F_124 ( V_196 ) ;
if ( ! V_280 )
F_132 ( V_196 ) ;
}
static void F_188 ( struct V_193 * V_194 ,
struct V_216 * V_282 ,
enum V_100 V_101 ,
unsigned int V_250 )
{
struct V_204 * V_196 = V_194 -> V_196 ;
struct V_8 * V_9 = V_196 -> V_9 ;
V_120 V_128 = F_66 ( & V_9 -> V_123 ) ;
V_120 V_160 = V_194 -> V_160 ;
V_120 V_162 = V_194 -> V_162 ;
V_120 V_283 ;
T_9 V_232 ;
if ( V_101 == V_104 ) {
if ( ! V_160 && V_162 == V_128 &&
( ! F_143 ( V_196 ) ||
! F_118 ( V_194 ) ) ) {
V_232 = V_243 ;
} else if ( ( V_160 + V_162 == V_128 ) ) {
V_232 = V_244 ;
} else {
F_11 ( & V_9 -> V_271 ) ;
V_283 = V_9 -> V_123 . V_146 ;
F_12 ( & V_9 -> V_271 ) ;
if ( V_194 -> V_201 + V_162 == V_283 )
V_232 = V_244 ;
else
V_232 = V_245 ;
}
} else if ( V_101 == V_103 ) {
if ( ! V_160 && V_162 == V_128 )
V_232 = V_241 ;
else
V_232 = V_240 ;
F_189 ( V_282 , V_250 ,
V_128 , V_128 ) ;
V_250 ++ ;
} else {
V_232 = V_238 ;
}
if ( V_232 == V_243 )
F_190 ( V_282 , V_250 , V_232 , 0 ) ;
else
F_191 ( V_282 , V_250 , V_232 ,
V_160 , V_162 , 0 , 0 ) ;
if ( V_194 -> type == V_214 )
F_192 ( V_282 , V_250 ,
V_194 -> V_227 , V_162 ) ;
else if ( V_194 -> type == V_215 )
F_193 ( V_282 , V_250 ,
V_194 -> V_178 , V_162 ,
V_160 & ~ V_183 , false , false ) ;
if ( V_101 == V_103 || V_101 == V_104 )
F_158 ( V_194 ) ;
else
F_157 ( V_194 ) ;
}
static int F_194 ( struct V_204 * V_196 ,
enum V_212 type ,
void * V_284 )
{
struct V_8 * V_9 = V_196 -> V_9 ;
struct V_193 * V_194 = NULL ;
struct V_193 * V_276 ;
struct V_164 * V_227 = NULL ;
unsigned int V_285 = 0 ;
struct V_177 * * V_178 = NULL ;
enum V_100 V_101 ;
V_120 V_201 ;
V_120 V_286 ;
F_30 ( L_35 , V_67 , V_196 ,
( int ) type , V_284 ) ;
V_201 = V_196 -> V_160 ;
V_286 = V_196 -> V_162 ;
F_22 ( V_286 > 0 ) ;
V_101 = F_144 ( V_196 ) ;
if ( type == V_214 ) {
V_227 = V_284 ;
F_22 ( V_201 ==
V_227 -> V_189 . V_287 << V_116 ) ;
} else if ( type == V_215 ) {
V_178 = V_284 ;
}
while ( V_286 ) {
struct V_216 * V_217 ;
V_120 V_218 = V_201 >> V_9 -> V_123 . V_124 ;
V_120 V_160 = F_87 ( V_9 , V_201 ) ;
V_120 V_162 = F_88 ( V_9 , V_201 , V_286 ) ;
V_194 = F_168 ( type ) ;
if ( ! V_194 )
goto V_288;
V_194 -> V_218 = V_218 ;
V_194 -> V_160 = V_160 ;
V_194 -> V_162 = V_162 ;
F_126 ( V_196 , V_194 ) ;
if ( type == V_214 ) {
unsigned int V_289 ;
F_22 ( V_162 <= ( V_120 ) V_236 ) ;
V_289 = ( unsigned int ) V_162 ;
V_194 -> V_227 =
F_106 ( & V_227 ,
& V_285 ,
V_289 ,
V_257 ) ;
if ( ! V_194 -> V_227 )
goto V_288;
} else if ( type == V_215 ) {
unsigned int V_268 ;
V_194 -> V_178 = V_178 ;
V_268 = ( T_6 ) F_195 ( V_160 , V_162 ) ;
V_194 -> V_268 = V_268 ;
if ( ( V_160 + V_162 ) & ~ V_183 )
V_268 -- ;
V_178 += V_268 ;
}
V_217 = F_165 ( V_9 , V_101 ,
( V_101 == V_103 ) ? 2 : 1 ,
V_194 ) ;
if ( ! V_217 )
goto V_288;
V_194 -> V_217 = V_217 ;
V_194 -> V_211 = V_219 ;
V_194 -> V_201 = V_201 ;
F_188 ( V_194 , V_217 , V_101 , 0 ) ;
V_201 += V_162 ;
V_286 -= V_162 ;
}
return 0 ;
V_288:
F_181 (img_request, obj_request, next_obj_request)
F_127 ( V_196 , V_194 ) ;
return - V_66 ;
}
static void
F_155 ( struct V_193 * V_194 )
{
struct V_204 * V_196 ;
struct V_8 * V_9 ;
struct V_177 * * V_178 ;
T_6 V_268 ;
F_30 ( L_25 , V_67 , V_194 ) ;
F_22 ( V_194 -> type == V_214 ||
V_194 -> type == V_213 ) ;
F_22 ( F_110 ( V_194 ) ) ;
V_196 = V_194 -> V_196 ;
F_22 ( V_196 ) ;
V_9 = V_196 -> V_9 ;
F_22 ( V_9 ) ;
V_178 = V_194 -> V_290 ;
F_22 ( V_178 != NULL ) ;
V_194 -> V_290 = NULL ;
V_268 = V_194 -> V_291 ;
F_22 ( V_268 ) ;
V_194 -> V_291 = 0 ;
F_171 ( V_178 , V_268 ) ;
if ( ! V_194 -> V_221 )
V_194 -> V_222 = V_194 -> V_162 ;
F_112 ( V_194 ) ;
}
static void
F_196 ( struct V_204 * V_196 )
{
struct V_193 * V_279 ;
struct V_216 * V_217 ;
struct V_8 * V_9 ;
struct V_177 * * V_178 ;
enum V_100 V_101 ;
T_6 V_268 ;
int V_292 ;
V_120 V_293 ;
F_22 ( F_125 ( V_196 ) ) ;
V_178 = V_196 -> V_290 ;
F_22 ( V_178 != NULL ) ;
V_196 -> V_290 = NULL ;
V_268 = V_196 -> V_291 ;
F_22 ( V_268 ) ;
V_196 -> V_291 = 0 ;
V_279 = V_196 -> V_194 ;
F_22 ( V_279 != NULL ) ;
F_22 ( F_128 ( V_279 -> type ) ) ;
V_292 = V_196 -> V_221 ;
V_293 = V_196 -> V_162 ;
F_22 ( V_292 || V_293 == V_196 -> V_222 ) ;
F_124 ( V_196 ) ;
F_22 ( V_279 -> V_196 ) ;
V_9 = V_279 -> V_196 -> V_9 ;
F_22 ( V_9 ) ;
if ( ! V_9 -> V_202 ) {
F_171 ( V_178 , V_268 ) ;
F_129 ( V_279 ) ;
return;
}
if ( V_292 )
goto V_139;
V_292 = - V_66 ;
V_217 = F_166 ( V_279 ) ;
if ( ! V_217 )
goto V_139;
F_167 ( V_279 -> V_217 ) ;
V_279 -> V_217 = V_217 ;
V_279 -> V_290 = V_178 ;
V_279 -> V_291 = V_268 ;
F_197 ( V_217 , 0 , V_246 , L_36 , L_37 ) ;
F_198 ( V_217 , 0 , V_178 , V_293 , 0 ,
false , false ) ;
V_101 = F_144 ( V_279 -> V_196 ) ;
F_188 ( V_279 , V_217 , V_101 , 1 ) ;
F_129 ( V_279 ) ;
return;
V_139:
F_171 ( V_178 , V_268 ) ;
F_148 ( V_279 , V_292 ) ;
}
static int F_199 ( struct V_193 * V_194 )
{
struct V_8 * V_9 = V_194 -> V_196 -> V_9 ;
struct V_204 * V_277 = NULL ;
V_120 V_201 ;
V_120 V_162 ;
struct V_177 * * V_178 = NULL ;
T_6 V_268 ;
int V_221 ;
F_22 ( V_9 -> V_278 != NULL ) ;
V_201 = V_194 -> V_201 - V_194 -> V_160 ;
V_162 = F_66 ( & V_9 -> V_123 ) ;
if ( V_201 + V_162 > V_9 -> V_202 ) {
F_22 ( V_201 < V_9 -> V_202 ) ;
V_162 = V_9 -> V_202 - V_201 ;
}
V_268 = ( T_6 ) F_195 ( 0 , V_162 ) ;
V_178 = F_200 ( V_268 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_221 = F_201 ( V_178 ) ;
V_178 = NULL ;
goto V_139;
}
V_221 = - V_66 ;
V_277 = F_182 ( V_194 ,
V_201 , V_162 ) ;
if ( ! V_277 )
goto V_139;
V_221 = F_194 ( V_277 , V_215 , V_178 ) ;
if ( V_221 )
goto V_139;
V_277 -> V_290 = V_178 ;
V_277 -> V_291 = V_268 ;
V_277 -> V_211 = F_196 ;
V_221 = F_202 ( V_277 ) ;
if ( ! V_221 )
return 0 ;
V_277 -> V_290 = NULL ;
V_277 -> V_291 = 0 ;
V_277 -> V_194 = NULL ;
F_122 ( V_194 ) ;
V_139:
if ( V_178 )
F_171 ( V_178 , V_268 ) ;
if ( V_277 )
F_124 ( V_277 ) ;
return V_221 ;
}
static void F_203 ( struct V_193 * V_194 )
{
struct V_193 * V_279 ;
struct V_8 * V_9 ;
int V_221 ;
F_22 ( ! F_110 ( V_194 ) ) ;
V_279 = V_194 -> V_194 ;
V_194 -> V_194 = NULL ;
F_122 ( V_279 ) ;
F_22 ( V_279 ) ;
F_22 ( V_279 -> V_196 ) ;
V_221 = V_194 -> V_221 ;
V_194 -> V_221 = 0 ;
F_30 ( L_38 , V_67 ,
V_194 , V_279 , V_221 ,
V_194 -> V_222 , V_194 -> V_162 ) ;
F_122 ( V_194 ) ;
V_9 = V_279 -> V_196 -> V_9 ;
if ( ! V_9 -> V_202 ) {
F_129 ( V_279 ) ;
return;
}
if ( ! V_221 ) {
F_114 ( V_279 , true ) ;
} else if ( V_221 == - V_43 ) {
F_114 ( V_279 , false ) ;
} else {
goto V_294;
}
V_221 = F_204 ( V_279 ) ;
if ( V_221 )
goto V_294;
return;
V_294:
F_148 ( V_279 , V_221 ) ;
}
static int F_205 ( struct V_193 * V_194 )
{
struct V_8 * V_9 = V_194 -> V_196 -> V_9 ;
struct V_193 * V_295 ;
struct V_177 * * V_178 ;
T_6 V_268 ;
T_7 V_110 ;
int V_48 ;
V_295 = F_168 ( V_215 ) ;
if ( ! V_295 )
return - V_66 ;
V_295 -> V_218 = V_194 -> V_218 ;
V_295 -> V_217 = F_165 ( V_9 , V_102 , 1 ,
V_295 ) ;
if ( ! V_295 -> V_217 ) {
V_48 = - V_66 ;
goto V_296;
}
V_110 = sizeof ( V_119 ) + sizeof ( V_297 ) + sizeof ( V_297 ) ;
V_268 = ( T_6 ) F_195 ( 0 , V_110 ) ;
V_178 = F_200 ( V_268 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_48 = F_201 ( V_178 ) ;
goto V_296;
}
F_190 ( V_295 -> V_217 , 0 , V_242 , 0 ) ;
F_206 ( V_295 -> V_217 , 0 , V_178 , V_110 , 0 ,
false , false ) ;
F_120 ( V_194 ) ;
V_295 -> V_194 = V_194 ;
V_295 -> V_178 = V_178 ;
V_295 -> V_268 = V_268 ;
V_295 -> V_211 = F_203 ;
F_129 ( V_295 ) ;
return 0 ;
V_296:
F_122 ( V_295 ) ;
return V_48 ;
}
static bool F_207 ( struct V_193 * V_194 )
{
struct V_204 * V_196 = V_194 -> V_196 ;
struct V_8 * V_9 = V_196 -> V_9 ;
if ( ! F_135 ( V_196 ) &&
! F_137 ( V_196 ) )
return true ;
if ( ! F_143 ( V_196 ) )
return true ;
if ( ! F_118 ( V_194 ) )
return true ;
if ( ! V_194 -> V_160 &&
V_194 -> V_162 == F_66 ( & V_9 -> V_123 ) )
return true ;
if ( F_116 ( V_194 ) &&
F_117 ( V_194 ) )
return true ;
return false ;
}
static int F_204 ( struct V_193 * V_194 )
{
F_22 ( F_110 ( V_194 ) ) ;
F_22 ( F_128 ( V_194 -> type ) ) ;
F_22 ( V_194 -> V_196 ) ;
if ( F_207 ( V_194 ) ) {
F_129 ( V_194 ) ;
return 0 ;
}
if ( F_116 ( V_194 ) )
return F_199 ( V_194 ) ;
return F_205 ( V_194 ) ;
}
static int F_202 ( struct V_204 * V_196 )
{
struct V_193 * V_194 ;
struct V_193 * V_276 ;
int V_48 = 0 ;
F_30 ( L_21 , V_67 , V_196 ) ;
F_123 ( V_196 ) ;
F_181 (img_request, obj_request, next_obj_request) {
V_48 = F_204 ( V_194 ) ;
if ( V_48 )
goto V_298;
}
V_298:
F_124 ( V_196 ) ;
return V_48 ;
}
static void F_208 ( struct V_204 * V_196 )
{
struct V_193 * V_194 ;
struct V_8 * V_9 ;
V_120 V_299 ;
V_120 V_300 ;
int V_292 ;
F_22 ( F_125 ( V_196 ) ) ;
V_194 = V_196 -> V_194 ;
V_300 = V_196 -> V_222 ;
V_292 = V_196 -> V_221 ;
F_124 ( V_196 ) ;
F_22 ( V_194 ) ;
F_22 ( V_194 -> V_196 ) ;
V_9 = V_194 -> V_196 -> V_9 ;
if ( ! V_9 -> V_202 ) {
F_129 ( V_194 ) ;
return;
}
V_194 -> V_221 = V_292 ;
if ( V_194 -> V_221 )
goto V_58;
F_22 ( V_194 -> V_201 < V_163 - V_194 -> V_162 ) ;
V_299 = V_194 -> V_201 + V_194 -> V_162 ;
if ( V_299 > V_9 -> V_202 ) {
V_120 V_222 = 0 ;
if ( V_194 -> V_201 < V_9 -> V_202 )
V_222 = V_9 -> V_202 -
V_194 -> V_201 ;
V_194 -> V_222 = F_209 ( V_300 , V_222 ) ;
} else {
V_194 -> V_222 = V_300 ;
}
V_58:
F_145 ( V_194 ) ;
F_146 ( V_194 ) ;
}
static void F_150 ( struct V_193 * V_194 )
{
struct V_204 * V_196 ;
int V_221 ;
F_22 ( F_110 ( V_194 ) ) ;
F_22 ( V_194 -> V_196 != NULL ) ;
F_22 ( V_194 -> V_221 == ( V_301 ) - V_43 ) ;
F_22 ( F_128 ( V_194 -> type ) ) ;
V_196 = F_182 ( V_194 ,
V_194 -> V_201 ,
V_194 -> V_162 ) ;
V_221 = - V_66 ;
if ( ! V_196 )
goto V_139;
if ( V_194 -> type == V_214 )
V_221 = F_194 ( V_196 , V_214 ,
V_194 -> V_227 ) ;
else
V_221 = F_194 ( V_196 , V_215 ,
V_194 -> V_178 ) ;
if ( V_221 )
goto V_139;
V_196 -> V_211 = F_208 ;
V_221 = F_202 ( V_196 ) ;
if ( V_221 )
goto V_139;
return;
V_139:
if ( V_196 )
F_124 ( V_196 ) ;
V_194 -> V_221 = V_221 ;
V_194 -> V_222 = 0 ;
F_112 ( V_194 ) ;
}
static bool F_210 ( const struct V_302 * V_303 ,
const struct V_302 * V_304 )
{
return V_303 -> V_305 == V_304 -> V_305 && V_303 -> V_306 == V_304 -> V_306 ;
}
static struct V_302 F_211 ( struct V_8 * V_9 )
{
struct V_302 V_307 ;
F_212 ( & V_9 -> V_308 ) ;
V_307 . V_305 = F_213 ( V_9 -> V_62 -> V_72 ) ;
V_307 . V_306 = V_9 -> V_309 ;
F_56 ( & V_9 -> V_308 ) ;
return V_307 ;
}
static void F_214 ( struct V_8 * V_9 ,
const struct V_302 * V_307 )
{
F_30 ( L_39 , V_67 , V_9 ,
V_9 -> V_310 . V_305 , V_9 -> V_310 . V_306 ,
V_307 -> V_305 , V_307 -> V_306 ) ;
V_9 -> V_310 = * V_307 ;
}
static void F_215 ( struct V_8 * V_9 , char * V_17 )
{
F_212 ( & V_9 -> V_308 ) ;
sprintf ( V_17 , L_40 , V_311 , V_9 -> V_309 ) ;
F_56 ( & V_9 -> V_308 ) ;
}
static int F_216 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_302 V_307 = F_211 ( V_9 ) ;
char V_312 [ 32 ] ;
int V_48 ;
F_130 ( F_9 ( V_9 ) ||
V_9 -> V_313 [ 0 ] != '\0' ) ;
F_215 ( V_9 , V_312 ) ;
V_48 = F_217 ( V_252 , & V_9 -> V_314 , & V_9 -> V_315 ,
V_316 , V_317 , V_312 ,
V_318 , L_41 , 0 ) ;
if ( V_48 )
return V_48 ;
V_9 -> V_10 = V_11 ;
strcpy ( V_9 -> V_313 , V_312 ) ;
F_214 ( V_9 , & V_307 ) ;
F_218 ( V_9 -> V_319 , & V_9 -> V_320 ) ;
return 0 ;
}
static void F_219 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
int V_48 ;
F_130 ( ! F_9 ( V_9 ) ||
V_9 -> V_313 [ 0 ] == '\0' ) ;
V_48 = F_220 ( V_252 , & V_9 -> V_314 , & V_9 -> V_315 ,
V_316 , V_9 -> V_313 ) ;
if ( V_48 && V_48 != - V_43 )
F_107 ( V_9 , L_42 , V_48 ) ;
V_9 -> V_10 = V_321 ;
V_9 -> V_313 [ 0 ] = '\0' ;
F_214 ( V_9 , & V_322 ) ;
F_218 ( V_9 -> V_319 , & V_9 -> V_323 ) ;
}
static int F_221 ( struct V_8 * V_9 ,
enum V_324 V_325 ,
struct V_177 * * * V_326 ,
T_7 * V_327 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_302 V_307 = F_211 ( V_9 ) ;
int V_328 = 4 + 8 + 8 + V_329 ;
char V_17 [ V_328 ] ;
void * V_330 = V_17 ;
F_30 ( L_43 , V_67 , V_9 , V_325 ) ;
F_222 ( & V_330 , 2 , 1 , V_328 - V_329 ) ;
F_223 ( & V_330 , V_325 ) ;
F_224 ( & V_330 , V_307 . V_305 ) ;
F_224 ( & V_330 , V_307 . V_306 ) ;
return F_225 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_17 , V_328 ,
V_331 , V_326 , V_327 ) ;
}
static void F_226 ( struct V_8 * V_9 ,
enum V_324 V_325 )
{
struct V_177 * * V_332 ;
T_7 V_333 ;
F_221 ( V_9 , V_325 , & V_332 , & V_333 ) ;
F_171 ( V_332 , F_195 ( 0 , V_333 ) ) ;
}
static void F_227 ( struct V_334 * V_335 )
{
struct V_8 * V_9 = F_58 ( V_335 , struct V_8 ,
V_320 ) ;
F_226 ( V_9 , V_336 ) ;
}
static void F_228 ( struct V_334 * V_335 )
{
struct V_8 * V_9 = F_58 ( V_335 , struct V_8 ,
V_323 ) ;
F_226 ( V_9 , V_337 ) ;
}
static int F_229 ( struct V_8 * V_9 )
{
struct V_177 * * V_332 ;
T_7 V_333 ;
bool V_338 = false ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_221 ( V_9 , V_339 ,
& V_332 , & V_333 ) ;
if ( V_48 && V_48 != - V_340 ) {
F_107 ( V_9 , L_45 , V_48 ) ;
goto V_58;
}
if ( V_333 > 0 && V_333 <= V_184 ) {
void * V_330 = F_230 ( V_332 [ 0 ] ) ;
void * const V_179 = V_330 + V_333 ;
T_6 V_341 ;
F_231 ( & V_330 , V_179 , V_341 , V_342 ) ;
while ( V_341 -- ) {
T_11 V_343 ;
T_6 V_186 ;
F_232 ( & V_330 , V_179 , 8 + 8 , V_342 ) ;
V_330 += 8 + 8 ;
F_231 ( & V_330 , V_179 , V_186 , V_342 ) ;
if ( ! V_186 )
continue;
if ( V_338 ) {
F_107 ( V_9 ,
L_46 ) ;
V_48 = - V_147 ;
goto V_58;
}
V_338 = true ;
V_48 = F_233 ( & V_330 , V_179 , 1 , L_47 ,
& V_343 , & V_186 ) ;
if ( V_48 ) {
F_107 ( V_9 ,
L_48 ,
V_48 ) ;
goto V_342;
}
V_48 = F_234 ( & V_330 ) ;
}
}
if ( ! V_338 ) {
F_107 ( V_9 , L_49 ) ;
V_48 = - V_340 ;
}
V_58:
F_171 ( V_332 , F_195 ( 0 , V_333 ) ) ;
return V_48 ;
V_342:
V_48 = - V_4 ;
goto V_58;
}
static void F_235 ( struct V_8 * V_9 , bool V_344 )
{
F_30 ( L_50 , V_67 , V_9 , V_344 ) ;
F_236 ( & V_9 -> V_345 ) ;
if ( V_344 )
F_237 ( & V_9 -> V_346 ) ;
else
F_238 ( & V_9 -> V_346 ) ;
}
static int F_239 ( struct V_8 * V_9 ,
struct V_347 * * V_348 , T_6 * V_349 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
T_11 V_350 ;
char * V_351 ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_240 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_316 ,
& V_350 , & V_351 , V_348 , V_349 ) ;
if ( V_48 )
return V_48 ;
if ( * V_349 == 0 ) {
F_30 ( L_51 , V_67 , V_9 ) ;
goto V_58;
}
if ( strcmp ( V_351 , V_318 ) ) {
F_107 ( V_9 , L_52 ,
V_351 ) ;
V_48 = - V_57 ;
goto V_58;
}
if ( V_350 == V_352 ) {
F_107 ( V_9 , L_53 ) ;
V_48 = - V_57 ;
goto V_58;
}
if ( strncmp ( ( * V_348 ) [ 0 ] . V_145 . V_312 , V_311 ,
strlen ( V_311 ) ) ) {
F_107 ( V_9 , L_54 ,
( * V_348 ) [ 0 ] . V_145 . V_312 ) ;
V_48 = - V_57 ;
goto V_58;
}
V_58:
F_41 ( V_351 ) ;
return V_48 ;
}
static int F_241 ( struct V_8 * V_9 ,
const struct V_347 * V_353 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_354 * V_355 ;
T_6 V_356 ;
V_120 V_312 ;
int V_138 ;
int V_48 ;
V_48 = F_242 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , & V_355 ,
& V_356 ) ;
if ( V_48 )
return V_48 ;
sscanf ( V_353 -> V_145 . V_312 , V_311 L_55 , & V_312 ) ;
for ( V_138 = 0 ; V_138 < V_356 ; V_138 ++ ) {
if ( ! memcmp ( & V_355 [ V_138 ] . V_357 , & V_353 -> V_358 . V_357 ,
sizeof( V_353 -> V_358 . V_357 ) ) &&
V_355 [ V_138 ] . V_312 == V_312 ) {
struct V_302 V_307 = {
. V_305 = F_65 ( V_355 [ V_138 ] . V_359 . V_360 ) ,
. V_306 = V_312 ,
} ;
F_30 ( L_56 , V_67 ,
V_9 , V_307 . V_305 , V_307 . V_306 ) ;
F_214 ( V_9 , & V_307 ) ;
V_48 = 1 ;
goto V_58;
}
}
F_30 ( L_57 , V_67 , V_9 ) ;
V_48 = 0 ;
V_58:
F_41 ( V_355 ) ;
return V_48 ;
}
static int F_243 ( struct V_8 * V_9 )
{
struct V_361 * V_72 = V_9 -> V_62 -> V_72 ;
struct V_347 * V_348 ;
T_6 V_349 ;
int V_48 ;
for (; ; ) {
V_48 = F_216 ( V_9 ) ;
if ( V_48 != - V_57 )
return V_48 ;
V_48 = F_239 ( V_9 , & V_348 , & V_349 ) ;
if ( V_48 )
return V_48 ;
if ( V_349 == 0 )
goto V_362;
V_48 = F_241 ( V_9 , V_348 ) ;
if ( V_48 ) {
if ( V_48 > 0 )
V_48 = 0 ;
goto V_58;
}
F_107 ( V_9 , L_58 ,
F_244 ( V_348 [ 0 ] . V_145 . V_359 ) ) ;
V_48 = F_245 ( & V_72 -> V_363 ,
& V_348 [ 0 ] . V_358 . V_357 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_59 ,
F_244 ( V_348 [ 0 ] . V_145 . V_359 ) , V_48 ) ;
goto V_58;
}
V_48 = F_246 ( & V_72 -> V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_316 ,
V_348 [ 0 ] . V_145 . V_312 ,
& V_348 [ 0 ] . V_145 . V_359 ) ;
if ( V_48 && V_48 != - V_43 )
goto V_58;
V_362:
F_247 ( V_348 , V_349 ) ;
}
V_58:
F_247 ( V_348 , V_349 ) ;
return V_48 ;
}
static enum V_364 F_248 ( struct V_8 * V_9 ,
int * V_365 )
{
enum V_364 V_10 ;
F_11 ( & V_9 -> V_14 ) ;
F_30 ( L_60 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( F_9 ( V_9 ) ) {
V_10 = V_9 -> V_10 ;
F_12 ( & V_9 -> V_14 ) ;
return V_10 ;
}
F_12 ( & V_9 -> V_14 ) ;
F_249 ( & V_9 -> V_14 ) ;
F_30 ( L_61 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( ! F_9 ( V_9 ) ) {
* V_365 = F_243 ( V_9 ) ;
if ( * V_365 )
F_107 ( V_9 , L_62 , * V_365 ) ;
}
V_10 = V_9 -> V_10 ;
F_250 ( & V_9 -> V_14 ) ;
return V_10 ;
}
static void F_251 ( struct V_334 * V_335 )
{
struct V_8 * V_9 = F_58 ( F_252 ( V_335 ) ,
struct V_8 , V_345 ) ;
enum V_364 V_10 ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_362:
V_10 = F_248 ( V_9 , & V_48 ) ;
if ( V_10 != V_321 || V_48 == - V_366 ) {
if ( V_10 == V_11 )
F_235 ( V_9 , true ) ;
F_30 ( L_63 , V_67 ,
V_9 , V_10 , V_48 ) ;
return;
}
V_48 = F_229 ( V_9 ) ;
if ( V_48 == - V_340 ) {
goto V_362;
} else if ( V_48 == - V_38 ) {
F_107 ( V_9 , L_64 ) ;
if ( ! ( V_9 -> V_45 -> V_41 & V_367 ) ) {
F_115 ( V_368 , & V_9 -> V_41 ) ;
F_235 ( V_9 , false ) ;
}
} else if ( V_48 < 0 ) {
F_107 ( V_9 , L_65 , V_48 ) ;
F_253 ( V_9 -> V_319 , & V_9 -> V_345 ,
V_369 ) ;
} else {
F_30 ( L_66 , V_67 ,
V_9 ) ;
F_253 ( V_9 -> V_319 , & V_9 -> V_345 ,
F_254 ( 2 * V_331 * V_370 ) ) ;
}
}
static bool F_255 ( struct V_8 * V_9 )
{
F_30 ( L_60 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( V_9 -> V_10 != V_11 )
return false ;
V_9 -> V_10 = V_12 ;
F_256 ( & V_9 -> V_14 ) ;
F_257 ( & V_9 -> V_62 -> V_72 -> V_252 ) ;
F_12 ( & V_9 -> V_14 ) ;
F_249 ( & V_9 -> V_14 ) ;
F_30 ( L_61 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( V_9 -> V_10 != V_12 )
return false ;
F_219 ( V_9 ) ;
F_236 ( & V_9 -> V_345 ) ;
return true ;
}
static void F_258 ( struct V_334 * V_335 )
{
struct V_8 * V_9 = F_58 ( V_335 , struct V_8 ,
V_371 ) ;
F_249 ( & V_9 -> V_14 ) ;
F_255 ( V_9 ) ;
F_250 ( & V_9 -> V_14 ) ;
}
static void F_259 ( struct V_8 * V_9 , T_11 V_343 ,
void * * V_330 )
{
struct V_302 V_307 = { 0 } ;
if ( V_343 >= 2 ) {
V_307 . V_305 = F_260 ( V_330 ) ;
V_307 . V_306 = F_260 ( V_330 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_307 . V_305 ,
V_307 . V_306 ) ;
if ( ! F_210 ( & V_307 , & V_322 ) ) {
F_249 ( & V_9 -> V_14 ) ;
if ( F_210 ( & V_307 , & V_9 -> V_310 ) ) {
F_250 ( & V_9 -> V_14 ) ;
return;
}
F_214 ( V_9 , & V_307 ) ;
F_256 ( & V_9 -> V_14 ) ;
} else {
F_11 ( & V_9 -> V_14 ) ;
}
if ( ! F_9 ( V_9 ) )
F_235 ( V_9 , false ) ;
F_12 ( & V_9 -> V_14 ) ;
}
static void F_261 ( struct V_8 * V_9 , T_11 V_343 ,
void * * V_330 )
{
struct V_302 V_307 = { 0 } ;
if ( V_343 >= 2 ) {
V_307 . V_305 = F_260 ( V_330 ) ;
V_307 . V_306 = F_260 ( V_330 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_307 . V_305 ,
V_307 . V_306 ) ;
if ( ! F_210 ( & V_307 , & V_322 ) ) {
F_249 ( & V_9 -> V_14 ) ;
if ( ! F_210 ( & V_307 , & V_9 -> V_310 ) ) {
F_30 ( L_68 ,
V_67 , V_9 , V_307 . V_305 , V_307 . V_306 ,
V_9 -> V_310 . V_305 , V_9 -> V_310 . V_306 ) ;
F_250 ( & V_9 -> V_14 ) ;
return;
}
F_214 ( V_9 , & V_322 ) ;
F_256 ( & V_9 -> V_14 ) ;
} else {
F_11 ( & V_9 -> V_14 ) ;
}
if ( ! F_9 ( V_9 ) )
F_235 ( V_9 , false ) ;
F_12 ( & V_9 -> V_14 ) ;
}
static int F_262 ( struct V_8 * V_9 , T_11 V_343 ,
void * * V_330 )
{
struct V_302 V_372 = F_211 ( V_9 ) ;
struct V_302 V_307 = { 0 } ;
int V_221 = 1 ;
if ( V_343 >= 2 ) {
V_307 . V_305 = F_260 ( V_330 ) ;
V_307 . V_306 = F_260 ( V_330 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_307 . V_305 ,
V_307 . V_306 ) ;
if ( F_210 ( & V_307 , & V_372 ) )
return V_221 ;
F_11 ( & V_9 -> V_14 ) ;
if ( F_9 ( V_9 ) ) {
if ( V_9 -> V_10 == V_11 &&
F_210 ( & V_9 -> V_310 , & V_322 ) )
goto V_373;
V_221 = 0 ;
if ( V_9 -> V_10 == V_11 ) {
if ( ! V_9 -> V_374 -> V_99 ) {
F_30 ( L_69 ,
V_67 , V_9 ) ;
F_218 ( V_9 -> V_319 ,
& V_9 -> V_371 ) ;
} else {
V_221 = - V_38 ;
}
}
}
V_373:
F_12 ( & V_9 -> V_14 ) ;
return V_221 ;
}
static void F_263 ( struct V_8 * V_9 ,
V_120 V_375 , V_120 V_312 , V_301 * V_221 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
int V_328 = 4 + V_329 ;
char V_17 [ V_328 ] ;
int V_48 ;
if ( V_221 ) {
void * V_330 = V_17 ;
F_222 ( & V_330 , 1 , 1 ,
V_328 - V_329 ) ;
F_223 ( & V_330 , * V_221 ) ;
} else {
V_328 = 0 ;
}
V_48 = F_264 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_375 , V_312 ,
V_17 , V_328 ) ;
if ( V_48 )
F_107 ( V_9 , L_70 , V_48 ) ;
}
static void F_265 ( struct V_8 * V_9 , V_120 V_375 ,
V_120 V_312 )
{
F_30 ( L_44 , V_67 , V_9 ) ;
F_263 ( V_9 , V_375 , V_312 , NULL ) ;
}
static void F_266 ( struct V_8 * V_9 ,
V_120 V_375 , V_120 V_312 , V_301 V_221 )
{
F_30 ( L_71 , V_67 , V_9 , V_221 ) ;
F_263 ( V_9 , V_375 , V_312 , & V_221 ) ;
}
static void F_267 ( void * V_47 , V_120 V_375 , V_120 V_312 ,
V_120 V_376 , void * V_377 , T_7 V_378 )
{
struct V_8 * V_9 = V_47 ;
void * V_330 = V_377 ;
void * const V_179 = V_330 + V_378 ;
T_11 V_343 = 0 ;
T_6 V_186 ;
T_6 V_325 ;
int V_48 ;
F_30 ( L_72 ,
V_67 , V_9 , V_312 , V_375 , V_378 ) ;
if ( V_378 ) {
V_48 = F_233 ( & V_330 , V_179 , 1 , L_73 ,
& V_343 , & V_186 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_74 ,
V_48 ) ;
return;
}
V_325 = F_234 ( & V_330 ) ;
} else {
V_325 = V_379 ;
V_186 = 0 ;
}
F_30 ( L_75 , V_67 , V_9 , V_325 ) ;
switch ( V_325 ) {
case V_336 :
F_259 ( V_9 , V_343 , & V_330 ) ;
F_265 ( V_9 , V_375 , V_312 ) ;
break;
case V_337 :
F_261 ( V_9 , V_343 , & V_330 ) ;
F_265 ( V_9 , V_375 , V_312 ) ;
break;
case V_339 :
V_48 = F_262 ( V_9 , V_343 , & V_330 ) ;
if ( V_48 <= 0 )
F_266 ( V_9 , V_375 ,
V_312 , V_48 ) ;
else
F_265 ( V_9 , V_375 , V_312 ) ;
break;
case V_379 :
V_48 = F_268 ( V_9 ) ;
if ( V_48 )
F_107 ( V_9 , L_76 , V_48 ) ;
F_265 ( V_9 , V_375 , V_312 ) ;
break;
default:
if ( F_10 ( V_9 ) )
F_266 ( V_9 , V_375 ,
V_312 , - V_380 ) ;
else
F_265 ( V_9 , V_375 , V_312 ) ;
break;
}
}
static void F_269 ( void * V_47 , V_120 V_312 , int V_229 )
{
struct V_8 * V_9 = V_47 ;
F_107 ( V_9 , L_77 , V_229 ) ;
F_249 ( & V_9 -> V_14 ) ;
F_214 ( V_9 , & V_322 ) ;
F_250 ( & V_9 -> V_14 ) ;
F_212 ( & V_9 -> V_308 ) ;
if ( V_9 -> V_381 == V_382 ) {
F_270 ( V_9 ) ;
V_9 -> V_381 = V_383 ;
F_271 ( V_9 -> V_319 , & V_9 -> V_384 , 0 ) ;
}
F_56 ( & V_9 -> V_308 ) ;
}
static int F_272 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_385 * V_306 ;
F_22 ( ! V_9 -> V_386 ) ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_306 = F_273 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , F_267 ,
F_269 , V_9 ) ;
if ( F_35 ( V_306 ) )
return F_201 ( V_306 ) ;
V_9 -> V_386 = V_306 ;
return 0 ;
}
static void F_270 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
int V_48 ;
F_22 ( V_9 -> V_386 ) ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_274 ( V_252 , V_9 -> V_386 ) ;
if ( V_48 )
F_107 ( V_9 , L_78 , V_48 ) ;
V_9 -> V_386 = NULL ;
}
static int F_275 ( struct V_8 * V_9 )
{
int V_48 ;
F_212 ( & V_9 -> V_308 ) ;
F_22 ( V_9 -> V_381 == V_387 ) ;
V_48 = F_272 ( V_9 ) ;
if ( V_48 )
goto V_58;
V_9 -> V_381 = V_382 ;
V_9 -> V_309 = V_9 -> V_386 -> V_388 ;
V_58:
F_56 ( & V_9 -> V_308 ) ;
return V_48 ;
}
static void F_276 ( struct V_8 * V_9 )
{
F_30 ( L_44 , V_67 , V_9 ) ;
F_277 ( & V_9 -> V_384 ) ;
F_278 ( & V_9 -> V_320 ) ;
F_278 ( & V_9 -> V_323 ) ;
F_277 ( & V_9 -> V_345 ) ;
F_278 ( & V_9 -> V_371 ) ;
}
static void F_279 ( struct V_8 * V_9 )
{
F_130 ( F_280 ( & V_9 -> V_346 ) ) ;
F_276 ( V_9 ) ;
F_212 ( & V_9 -> V_308 ) ;
if ( V_9 -> V_381 == V_382 )
F_270 ( V_9 ) ;
V_9 -> V_381 = V_387 ;
F_56 ( & V_9 -> V_308 ) ;
F_281 ( & V_9 -> V_62 -> V_72 -> V_252 ) ;
}
static void F_282 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
char V_312 [ 32 ] ;
int V_48 ;
F_130 ( V_9 -> V_10 != V_11 ) ;
F_215 ( V_9 , V_312 ) ;
V_48 = F_283 ( V_252 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_316 ,
V_317 , V_9 -> V_313 ,
V_318 , V_312 ) ;
if ( V_48 ) {
if ( V_48 != - V_380 )
F_107 ( V_9 , L_79 ,
V_48 ) ;
if ( F_255 ( V_9 ) )
F_271 ( V_9 -> V_319 ,
& V_9 -> V_345 , 0 ) ;
} else {
strcpy ( V_9 -> V_313 , V_312 ) ;
}
}
static void F_284 ( struct V_334 * V_335 )
{
struct V_8 * V_9 = F_58 ( F_252 ( V_335 ) ,
struct V_8 , V_384 ) ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
F_212 ( & V_9 -> V_308 ) ;
if ( V_9 -> V_381 != V_383 ) {
F_56 ( & V_9 -> V_308 ) ;
return;
}
V_48 = F_272 ( V_9 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_80 , V_48 ) ;
if ( V_48 == - V_366 || V_48 == - V_43 ) {
F_115 ( V_368 , & V_9 -> V_41 ) ;
F_235 ( V_9 , true ) ;
} else {
F_271 ( V_9 -> V_319 ,
& V_9 -> V_384 ,
V_369 ) ;
}
F_56 ( & V_9 -> V_308 ) ;
return;
}
V_9 -> V_381 = V_382 ;
V_9 -> V_309 = V_9 -> V_386 -> V_388 ;
F_56 ( & V_9 -> V_308 ) ;
F_249 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_10 == V_11 )
F_282 ( V_9 ) ;
F_250 ( & V_9 -> V_14 ) ;
V_48 = F_268 ( V_9 ) ;
if ( V_48 )
F_107 ( V_9 , L_81 , V_48 ) ;
}
static int F_285 ( struct V_8 * V_9 ,
struct V_389 * V_390 ,
struct V_391 * V_392 ,
const char * V_393 ,
const void * V_394 ,
T_7 V_395 ,
void * V_396 ,
T_7 V_397 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_177 * V_398 = NULL ;
struct V_177 * V_399 ;
int V_48 ;
if ( V_394 ) {
if ( V_395 > V_184 )
return - V_400 ;
V_398 = F_286 ( V_68 ) ;
if ( ! V_398 )
return - V_66 ;
memcpy ( F_230 ( V_398 ) , V_394 , V_395 ) ;
}
V_399 = F_286 ( V_68 ) ;
if ( ! V_399 ) {
if ( V_398 )
F_287 ( V_398 ) ;
return - V_66 ;
}
V_48 = F_288 ( V_252 , V_390 , V_392 , V_401 , V_393 ,
V_265 , V_398 , V_395 ,
V_399 , & V_397 ) ;
if ( ! V_48 ) {
memcpy ( V_396 , F_230 ( V_399 ) , V_397 ) ;
V_48 = V_397 ;
}
if ( V_398 )
F_287 ( V_398 ) ;
F_287 ( V_399 ) ;
return V_48 ;
}
static void F_289 ( struct V_8 * V_9 )
{
F_290 ( V_402 ) ;
do {
F_30 ( L_82 , V_67 , V_9 ) ;
F_271 ( V_9 -> V_319 , & V_9 -> V_345 , 0 ) ;
F_291 ( & V_9 -> V_346 , & V_402 ,
V_403 ) ;
F_12 ( & V_9 -> V_14 ) ;
F_292 () ;
F_11 ( & V_9 -> V_14 ) ;
} while ( V_9 -> V_10 != V_11 &&
! F_18 ( V_368 , & V_9 -> V_41 ) );
F_293 ( & V_9 -> V_346 , & V_402 ) ;
}
static void F_294 ( struct V_334 * V_335 )
{
struct V_404 * V_273 = F_295 ( V_335 ) ;
struct V_8 * V_9 = V_273 -> V_405 -> V_406 ;
struct V_204 * V_196 ;
struct V_118 * V_135 = NULL ;
V_120 V_160 = ( V_120 ) F_296 ( V_273 ) << V_116 ;
V_120 V_162 = F_297 ( V_273 ) ;
enum V_100 V_101 ;
V_120 V_407 ;
bool V_408 ;
int V_221 ;
switch ( F_298 ( V_273 ) ) {
case V_409 :
case V_410 :
V_101 = V_104 ;
break;
case V_411 :
V_101 = V_103 ;
break;
case V_412 :
V_101 = V_102 ;
break;
default:
F_30 ( L_83 , V_67 , F_298 ( V_273 ) ) ;
V_221 = - V_147 ;
goto V_229;
}
if ( ! V_162 ) {
F_30 ( L_84 , V_67 ) ;
V_221 = 0 ;
goto V_413;
}
if ( V_101 != V_102 ) {
if ( V_9 -> V_36 . V_37 ) {
V_221 = - V_38 ;
goto V_413;
}
F_22 ( V_9 -> V_54 -> V_55 == V_56 ) ;
}
if ( ! F_18 ( V_414 , & V_9 -> V_41 ) ) {
F_30 ( L_85 ) ;
F_22 ( V_9 -> V_54 -> V_55 != V_56 ) ;
V_221 = - V_415 ;
goto V_413;
}
if ( V_160 && V_162 > V_163 - V_160 + 1 ) {
F_107 ( V_9 , L_86 , V_160 ,
V_162 ) ;
V_221 = - V_4 ;
goto V_413;
}
F_299 ( V_273 ) ;
F_11 ( & V_9 -> V_271 ) ;
V_407 = V_9 -> V_36 . V_110 ;
if ( V_101 != V_102 ) {
V_135 = V_9 -> V_123 . V_135 ;
F_300 ( V_135 ) ;
}
F_12 ( & V_9 -> V_271 ) ;
if ( V_160 + V_162 > V_407 ) {
F_107 ( V_9 , L_87 , V_160 ,
V_162 , V_407 ) ;
V_221 = - V_147 ;
goto V_413;
}
V_408 =
( V_9 -> V_123 . V_159 & V_416 ) &&
( V_101 != V_102 || V_9 -> V_374 -> V_97 ) ;
if ( V_408 ) {
F_11 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_10 != V_11 &&
! F_18 ( V_368 , & V_9 -> V_41 ) ) {
if ( V_9 -> V_374 -> V_99 ) {
F_107 ( V_9 , L_88 ) ;
V_221 = - V_38 ;
goto V_417;
}
F_289 ( V_9 ) ;
}
if ( F_18 ( V_368 , & V_9 -> V_41 ) ) {
V_221 = - V_366 ;
goto V_417;
}
}
V_196 = F_178 ( V_9 , V_160 , V_162 , V_101 ,
V_135 ) ;
if ( ! V_196 ) {
V_221 = - V_66 ;
goto V_417;
}
V_196 -> V_273 = V_273 ;
V_135 = NULL ;
if ( V_101 == V_104 )
V_221 = F_194 ( V_196 , V_213 ,
NULL ) ;
else
V_221 = F_194 ( V_196 , V_214 ,
V_273 -> V_164 ) ;
if ( V_221 )
goto V_418;
V_221 = F_202 ( V_196 ) ;
if ( V_221 )
goto V_418;
if ( V_408 )
F_12 ( & V_9 -> V_14 ) ;
return;
V_418:
F_124 ( V_196 ) ;
V_417:
if ( V_408 )
F_12 ( & V_9 -> V_14 ) ;
V_413:
if ( V_221 )
F_107 ( V_9 , L_89 ,
F_53 ( V_101 ) , V_162 , V_160 , V_221 ) ;
F_73 ( V_135 ) ;
V_229:
F_301 ( V_273 , F_184 ( V_221 ) ) ;
}
static T_10 F_302 ( struct V_419 * V_420 ,
const struct V_421 * V_422 )
{
struct V_404 * V_273 = V_422 -> V_273 ;
struct V_334 * V_335 = F_303 ( V_273 ) ;
F_218 ( V_423 , V_335 ) ;
return V_424 ;
}
static void F_304 ( struct V_8 * V_9 )
{
F_305 ( V_9 -> V_45 -> V_425 ) ;
F_306 ( & V_9 -> V_426 ) ;
F_307 ( V_9 -> V_45 ) ;
V_9 -> V_45 = NULL ;
}
static int F_308 ( struct V_8 * V_9 ,
struct V_389 * V_390 ,
struct V_391 * V_392 ,
void * V_17 , int V_427 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_216 * V_253 ;
struct V_177 * * V_178 ;
int V_428 = F_195 ( 0 , V_427 ) ;
int V_48 ;
V_253 = F_161 ( V_252 , NULL , 1 , false , V_68 ) ;
if ( ! V_253 )
return - V_66 ;
F_309 ( & V_253 -> V_262 , V_390 ) ;
F_310 ( & V_253 -> V_260 , V_392 ) ;
V_253 -> V_258 = V_265 ;
V_48 = F_163 ( V_253 , V_68 ) ;
if ( V_48 )
goto V_429;
V_178 = F_200 ( V_428 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_48 = F_201 ( V_178 ) ;
goto V_429;
}
F_191 ( V_253 , 0 , V_238 , 0 , V_427 , 0 , 0 ) ;
F_193 ( V_253 , 0 , V_178 , V_427 , 0 , false ,
true ) ;
F_131 ( V_252 , V_253 , false ) ;
V_48 = F_311 ( V_252 , V_253 ) ;
if ( V_48 >= 0 )
F_312 ( V_178 , V_17 , 0 , V_48 ) ;
V_429:
F_164 ( V_253 ) ;
return V_48 ;
}
static int F_313 ( struct V_8 * V_9 )
{
struct V_108 * V_109 = NULL ;
T_6 V_111 = 0 ;
V_120 V_430 = 0 ;
T_6 V_431 ;
int V_48 ;
do {
T_7 V_110 ;
F_41 ( V_109 ) ;
V_110 = sizeof ( * V_109 ) ;
V_110 += V_111 * sizeof ( struct V_142 ) ;
V_110 += V_430 ;
V_109 = F_31 ( V_110 , V_68 ) ;
if ( ! V_109 )
return - V_66 ;
V_48 = F_308 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , V_109 , V_110 ) ;
if ( V_48 < 0 )
goto V_58;
if ( ( T_7 ) V_48 < V_110 ) {
V_48 = - V_415 ;
F_107 ( V_9 , L_90 ,
V_110 , V_48 ) ;
goto V_58;
}
if ( ! F_63 ( V_109 ) ) {
V_48 = - V_415 ;
F_107 ( V_9 , L_91 ) ;
goto V_58;
}
V_430 = F_65 ( V_109 -> V_121 ) ;
V_431 = V_111 ;
V_111 = F_64 ( V_109 -> V_111 ) ;
} while ( V_111 != V_431 );
V_48 = F_69 ( V_9 , V_109 ) ;
V_58:
F_41 ( V_109 ) ;
return V_48 ;
}
static void F_314 ( struct V_8 * V_9 )
{
V_120 V_55 ;
if ( ! F_18 ( V_414 , & V_9 -> V_41 ) )
return;
V_55 = V_9 -> V_54 -> V_55 ;
if ( V_55 == V_56 )
return;
if ( F_77 ( V_9 , V_55 ) == V_155 )
F_140 ( V_414 , & V_9 -> V_41 ) ;
}
static void F_315 ( struct V_8 * V_9 )
{
T_12 V_110 ;
if ( F_18 ( V_414 , & V_9 -> V_41 ) &&
! F_18 ( V_40 , & V_9 -> V_41 ) ) {
V_110 = ( T_12 ) V_9 -> V_36 . V_110 / V_432 ;
F_30 ( L_92 , ( unsigned long long ) V_110 ) ;
F_316 ( V_9 -> V_45 , V_110 ) ;
F_317 ( V_9 -> V_45 ) ;
}
}
static int F_268 ( struct V_8 * V_9 )
{
V_120 V_407 ;
int V_48 ;
F_249 ( & V_9 -> V_271 ) ;
V_407 = V_9 -> V_36 . V_110 ;
V_48 = F_318 ( V_9 ) ;
if ( V_48 )
goto V_58;
if ( V_9 -> V_278 ) {
V_48 = F_319 ( V_9 ) ;
if ( V_48 )
goto V_58;
}
if ( V_9 -> V_54 -> V_55 == V_56 ) {
V_9 -> V_36 . V_110 = V_9 -> V_123 . V_146 ;
} else {
F_314 ( V_9 ) ;
}
V_58:
F_250 ( & V_9 -> V_271 ) ;
if ( ! V_48 && V_407 != V_9 -> V_36 . V_110 )
F_315 ( V_9 ) ;
return V_48 ;
}
static int F_320 ( struct V_433 * V_434 , struct V_404 * V_273 ,
unsigned int V_435 , unsigned int V_436 )
{
struct V_334 * V_335 = F_303 ( V_273 ) ;
F_321 ( V_335 , F_294 ) ;
return 0 ;
}
static int F_322 ( struct V_8 * V_9 )
{
struct V_44 * V_45 ;
struct V_437 * V_405 ;
V_120 V_161 ;
int V_229 ;
V_45 = F_323 ( V_24 ?
( 1 << V_6 ) :
V_438 ) ;
if ( ! V_45 )
return - V_66 ;
snprintf ( V_45 -> V_439 , sizeof( V_45 -> V_439 ) , V_401 L_93 ,
V_9 -> V_5 ) ;
V_45 -> V_440 = V_9 -> V_440 ;
V_45 -> V_441 = V_9 -> V_7 ;
if ( V_24 )
V_45 -> V_41 |= V_442 ;
V_45 -> V_443 = & V_444 ;
V_45 -> V_33 = V_9 ;
memset ( & V_9 -> V_426 , 0 , sizeof( V_9 -> V_426 ) ) ;
V_9 -> V_426 . V_445 = & V_446 ;
V_9 -> V_426 . V_93 = V_9 -> V_374 -> V_93 ;
V_9 -> V_426 . V_436 = V_447 ;
V_9 -> V_426 . V_41 = V_448 | V_449 ;
V_9 -> V_426 . V_450 = 1 ;
V_9 -> V_426 . V_451 = sizeof( struct V_334 ) ;
V_229 = F_324 ( & V_9 -> V_426 ) ;
if ( V_229 )
goto V_452;
V_405 = F_325 ( & V_9 -> V_426 ) ;
if ( F_35 ( V_405 ) ) {
V_229 = F_201 ( V_405 ) ;
goto V_453;
}
F_326 ( V_454 , V_405 ) ;
V_161 = F_66 ( & V_9 -> V_123 ) ;
F_327 ( V_405 , V_161 / V_432 ) ;
V_405 -> V_455 . V_456 = F_328 ( V_405 ) ;
F_329 ( V_405 , V_161 / V_432 ) ;
F_330 ( V_405 , V_161 ) ;
F_331 ( V_405 , V_161 ) ;
F_332 ( V_405 , V_161 ) ;
F_326 ( V_457 , V_405 ) ;
V_405 -> V_455 . V_458 = V_161 ;
V_405 -> V_455 . V_459 = V_161 ;
F_333 ( V_405 , V_161 / V_432 ) ;
F_334 ( V_405 , V_161 / V_432 ) ;
if ( ! F_335 ( V_9 -> V_62 -> V_72 , V_460 ) )
V_405 -> V_461 -> V_462 |= V_463 ;
F_130 ( ! F_336 ( V_405 ) ) ;
V_45 -> V_425 = V_405 ;
V_405 -> V_406 = V_9 ;
V_9 -> V_45 = V_45 ;
return 0 ;
V_453:
F_306 ( & V_9 -> V_426 ) ;
V_452:
F_307 ( V_45 ) ;
return V_229 ;
}
static struct V_8 * F_337 ( struct V_28 * V_29 )
{
return F_58 ( V_29 , struct V_8 , V_29 ) ;
}
static T_2 F_338 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_94 ,
( unsigned long long ) V_9 -> V_36 . V_110 ) ;
}
static T_2 F_339 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_95 ,
( unsigned long long ) V_9 -> V_36 . V_159 ) ;
}
static T_2 F_340 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
if ( V_9 -> V_440 )
return sprintf ( V_17 , L_96 , V_9 -> V_440 ) ;
return sprintf ( V_17 , L_97 ) ;
}
static T_2 F_341 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_96 , V_9 -> V_7 ) ;
}
static T_2 F_342 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
struct V_465 * V_466 =
F_343 ( V_9 -> V_62 -> V_72 ) ;
return sprintf ( V_17 , L_98 , & V_466 -> V_467 ,
F_64 ( V_466 -> V_468 ) ) ;
}
static T_2 F_344 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_99 ,
F_213 ( V_9 -> V_62 -> V_72 ) ) ;
}
static T_2 F_345 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_100 , & V_9 -> V_62 -> V_72 -> V_469 ) ;
}
static T_2 F_346 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_470 ) ;
}
static T_2 F_347 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_471 ) ;
}
static T_2 F_348 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_94 ,
( unsigned long long ) V_9 -> V_54 -> V_129 ) ;
}
static T_2 F_349 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
if ( V_9 -> V_54 -> V_472 )
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_472 ) ;
return sprintf ( V_17 , L_102 ) ;
}
static T_2 F_350 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_473 ) ;
}
static T_2 F_351 ( struct V_28 * V_29 ,
struct V_464 * V_22 ,
char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_149 ) ;
}
static T_2 F_352 ( struct V_28 * V_29 ,
struct V_464 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
return sprintf ( V_17 , L_94 , V_9 -> V_54 -> V_55 ) ;
}
static T_2 F_353 ( struct V_28 * V_29 ,
struct V_464 * V_22 ,
char * V_17 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
T_2 V_474 = 0 ;
if ( ! V_9 -> V_278 )
return sprintf ( V_17 , L_103 ) ;
for ( ; V_9 -> V_278 ; V_9 = V_9 -> V_278 ) {
struct V_475 * V_54 = V_9 -> V_269 ;
V_474 += sprintf ( & V_17 [ V_474 ] , L_104
L_105
L_106
L_107
L_108 ,
! V_474 ? L_41 : L_109 ,
V_54 -> V_129 , V_54 -> V_471 ,
V_54 -> V_473 , V_54 -> V_472 ? : L_110 ,
V_54 -> V_55 , V_54 -> V_149 ,
V_9 -> V_202 ) ;
}
return V_474 ;
}
static T_2 F_354 ( struct V_28 * V_29 ,
struct V_464 * V_22 ,
const char * V_17 ,
T_7 V_110 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
int V_48 ;
V_48 = F_268 ( V_9 ) ;
if ( V_48 )
return V_48 ;
return V_110 ;
}
static struct V_475 * F_355 ( struct V_475 * V_54 )
{
F_45 ( & V_54 -> V_70 ) ;
return V_54 ;
}
static void F_175 ( struct V_475 * V_54 )
{
if ( V_54 )
F_61 ( & V_54 -> V_70 , V_476 ) ;
}
static struct V_475 * F_356 ( void )
{
struct V_475 * V_54 ;
V_54 = F_357 ( sizeof ( * V_54 ) , V_68 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_129 = V_131 ;
V_54 -> V_55 = V_56 ;
F_32 ( & V_54 -> V_70 ) ;
return V_54 ;
}
static void V_476 ( struct V_70 * V_70 )
{
struct V_475 * V_54 = F_58 ( V_70 , struct V_475 , V_70 ) ;
F_41 ( V_54 -> V_471 ) ;
F_41 ( V_54 -> V_473 ) ;
F_41 ( V_54 -> V_472 ) ;
F_41 ( V_54 -> V_149 ) ;
F_41 ( V_54 ) ;
}
static void F_358 ( struct V_8 * V_9 )
{
F_130 ( V_9 -> V_381 != V_387 ) ;
F_130 ( V_9 -> V_10 != V_321 ) ;
F_359 ( & V_9 -> V_314 ) ;
F_360 ( & V_9 -> V_315 ) ;
F_41 ( V_9 -> V_470 ) ;
F_60 ( V_9 -> V_62 ) ;
F_175 ( V_9 -> V_54 ) ;
F_41 ( V_9 -> V_374 ) ;
F_41 ( V_9 ) ;
}
static void F_361 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_337 ( V_29 ) ;
bool V_477 = ! ! V_9 -> V_374 ;
if ( V_477 ) {
F_362 ( V_9 -> V_319 ) ;
F_363 ( & V_478 , V_9 -> V_5 ) ;
}
F_358 ( V_9 ) ;
if ( V_477 )
F_364 ( V_479 ) ;
}
static struct V_8 * F_365 ( struct V_62 * V_65 ,
struct V_475 * V_54 )
{
struct V_8 * V_9 ;
V_9 = F_357 ( sizeof( * V_9 ) , V_68 ) ;
if ( ! V_9 )
return NULL ;
F_180 ( & V_9 -> V_39 ) ;
F_33 ( & V_9 -> V_71 ) ;
F_366 ( & V_9 -> V_271 ) ;
V_9 -> V_123 . V_130 = V_131 ;
F_367 ( & V_9 -> V_314 ) ;
V_9 -> V_315 . V_261 = V_54 -> V_129 ;
F_368 ( & V_9 -> V_308 ) ;
V_9 -> V_381 = V_387 ;
F_369 ( & V_9 -> V_384 , F_284 ) ;
F_366 ( & V_9 -> V_14 ) ;
V_9 -> V_10 = V_321 ;
F_321 ( & V_9 -> V_320 , F_227 ) ;
F_321 ( & V_9 -> V_323 , F_228 ) ;
F_369 ( & V_9 -> V_345 , F_251 ) ;
F_321 ( & V_9 -> V_371 , F_258 ) ;
F_370 ( & V_9 -> V_346 ) ;
V_9 -> V_29 . V_16 = & V_480 ;
V_9 -> V_29 . type = & V_481 ;
V_9 -> V_29 . V_278 = & V_482 ;
F_371 ( & V_9 -> V_29 ) ;
V_9 -> V_62 = V_65 ;
V_9 -> V_54 = V_54 ;
return V_9 ;
}
static struct V_8 * F_372 ( struct V_62 * V_65 ,
struct V_475 * V_54 ,
struct V_82 * V_374 )
{
struct V_8 * V_9 ;
V_9 = F_365 ( V_65 , V_54 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_374 = V_374 ;
V_9 -> V_5 = F_373 ( & V_478 , 0 ,
F_8 ( 1 << V_483 ) ,
V_68 ) ;
if ( V_9 -> V_5 < 0 )
goto V_484;
sprintf ( V_9 -> V_359 , V_401 L_93 , V_9 -> V_5 ) ;
V_9 -> V_319 = F_374 ( L_111 , V_485 ,
V_9 -> V_359 ) ;
if ( ! V_9 -> V_319 )
goto V_486;
F_375 ( V_479 ) ;
F_30 ( L_112 , V_67 , V_9 , V_9 -> V_5 ) ;
return V_9 ;
V_486:
F_363 ( & V_478 , V_9 -> V_5 ) ;
V_484:
F_358 ( V_9 ) ;
return NULL ;
}
static void F_376 ( struct V_8 * V_9 )
{
if ( V_9 )
F_23 ( & V_9 -> V_29 ) ;
}
static int F_82 ( struct V_8 * V_9 , V_120 V_55 ,
T_11 * V_115 , V_120 * V_157 )
{
V_119 V_487 = F_377 ( V_55 ) ;
int V_48 ;
struct {
T_11 V_115 ;
V_119 V_110 ;
} V_488 ( ( V_489 ) ) V_490 = { 0 } ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_113 ,
& V_487 , sizeof( V_487 ) ,
& V_490 , sizeof( V_490 ) ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof ( V_490 ) )
return - V_491 ;
if ( V_115 ) {
* V_115 = V_490 . V_115 ;
F_30 ( L_115 , ( unsigned int ) * V_115 ) ;
}
* V_157 = F_65 ( V_490 . V_110 ) ;
F_30 ( L_116 ,
( unsigned long long ) V_55 ,
( unsigned long long ) * V_157 ) ;
return 0 ;
}
static int F_378 ( struct V_8 * V_9 )
{
return F_82 ( V_9 , V_56 ,
& V_9 -> V_123 . V_124 ,
& V_9 -> V_123 . V_146 ) ;
}
static int F_379 ( struct V_8 * V_9 )
{
void * V_492 ;
int V_48 ;
void * V_330 ;
V_492 = F_357 ( V_493 , V_68 ) ;
if ( ! V_492 )
return - V_66 ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_117 ,
NULL , 0 , V_492 , V_493 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_58;
V_330 = V_492 ;
V_9 -> V_123 . V_134 = F_380 ( & V_330 ,
V_330 + V_48 , NULL , V_257 ) ;
V_48 = 0 ;
if ( F_35 ( V_9 -> V_123 . V_134 ) ) {
V_48 = F_201 ( V_9 -> V_123 . V_134 ) ;
V_9 -> V_123 . V_134 = NULL ;
} else {
F_30 ( L_118 , V_9 -> V_123 . V_134 ) ;
}
V_58:
F_41 ( V_492 ) ;
return V_48 ;
}
static int F_84 ( struct V_8 * V_9 , V_120 V_55 ,
V_120 * V_158 )
{
V_119 V_487 = F_377 ( V_55 ) ;
struct {
V_119 V_159 ;
V_119 V_494 ;
} V_488 ( ( V_489 ) ) V_495 = { 0 } ;
V_120 V_496 ;
int V_48 ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_119 ,
& V_487 , sizeof( V_487 ) ,
& V_495 , sizeof( V_495 ) ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof ( V_495 ) )
return - V_491 ;
V_496 = F_65 ( V_495 . V_494 ) & ~ V_18 ;
if ( V_496 ) {
F_107 ( V_9 , L_120 ,
V_496 ) ;
return - V_415 ;
}
* V_158 = F_65 ( V_495 . V_159 ) ;
F_30 ( L_121 ,
( unsigned long long ) V_55 ,
( unsigned long long ) * V_158 ,
( unsigned long long ) F_65 ( V_495 . V_494 ) ) ;
return 0 ;
}
static int F_381 ( struct V_8 * V_9 )
{
return F_84 ( V_9 , V_56 ,
& V_9 -> V_123 . V_159 ) ;
}
static int F_319 ( struct V_8 * V_9 )
{
struct V_475 * V_269 ;
T_7 V_110 ;
void * V_492 = NULL ;
V_119 V_487 ;
void * V_330 ;
void * V_179 ;
V_120 V_129 ;
char * V_473 ;
V_120 V_55 ;
V_120 V_497 ;
int V_48 ;
V_269 = F_356 () ;
if ( ! V_269 )
return - V_66 ;
V_110 = sizeof ( V_119 ) +
sizeof ( V_297 ) + V_498 +
sizeof ( V_119 ) +
sizeof ( V_119 ) ;
V_492 = F_31 ( V_110 , V_68 ) ;
if ( ! V_492 ) {
V_48 = - V_66 ;
goto V_139;
}
V_487 = F_377 ( V_9 -> V_54 -> V_55 ) ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_122 ,
& V_487 , sizeof( V_487 ) , V_492 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_139;
V_330 = V_492 ;
V_179 = V_492 + V_48 ;
V_48 = - V_491 ;
F_382 ( & V_330 , V_179 , V_129 , V_139 ) ;
if ( V_129 == V_131 ) {
if ( V_9 -> V_202 ) {
V_9 -> V_202 = 0 ;
F_176 ( V_9 ) ;
F_383 ( L_123 ,
V_9 -> V_45 -> V_439 ) ;
}
goto V_58;
}
V_48 = - V_147 ;
if ( V_129 > ( V_120 ) V_499 ) {
F_107 ( NULL , L_124 ,
( unsigned long long ) V_129 , V_499 ) ;
goto V_139;
}
V_473 = F_380 ( & V_330 , V_179 , NULL , V_68 ) ;
if ( F_35 ( V_473 ) ) {
V_48 = F_201 ( V_473 ) ;
goto V_139;
}
F_382 ( & V_330 , V_179 , V_55 , V_139 ) ;
F_382 ( & V_330 , V_179 , V_497 , V_139 ) ;
if ( ! V_9 -> V_269 ) {
V_269 -> V_129 = V_129 ;
V_269 -> V_473 = V_473 ;
V_269 -> V_55 = V_55 ;
V_9 -> V_269 = V_269 ;
V_269 = NULL ;
} else {
F_41 ( V_473 ) ;
}
if ( ! V_497 ) {
if ( V_269 ) {
if ( V_9 -> V_202 )
F_107 ( V_9 ,
L_125 ) ;
} else {
F_107 ( V_9 , L_126 ) ;
}
}
V_9 -> V_202 = V_497 ;
V_58:
V_48 = 0 ;
V_139:
F_41 ( V_492 ) ;
F_175 ( V_269 ) ;
return V_48 ;
}
static int F_384 ( struct V_8 * V_9 )
{
struct {
V_119 V_125 ;
V_119 V_126 ;
} V_488 ( ( V_489 ) ) V_500 = { 0 } ;
T_7 V_110 = sizeof ( V_500 ) ;
void * V_330 ;
V_120 V_501 ;
V_120 V_125 ;
V_120 V_126 ;
int V_48 ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_127 ,
NULL , 0 , & V_500 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < V_110 )
return - V_491 ;
V_48 = - V_4 ;
V_501 = F_66 ( & V_9 -> V_123 ) ;
V_330 = & V_500 ;
V_125 = F_260 ( & V_330 ) ;
if ( V_125 != V_501 ) {
F_107 ( V_9 , L_128
L_129 ,
V_125 , V_501 ) ;
return - V_4 ;
}
V_126 = F_260 ( & V_330 ) ;
if ( V_126 != 1 ) {
F_107 ( V_9 , L_130
L_131 , V_126 ) ;
return - V_4 ;
}
V_9 -> V_123 . V_125 = V_125 ;
V_9 -> V_123 . V_126 = V_126 ;
return 0 ;
}
static int F_385 ( struct V_8 * V_9 )
{
V_119 V_130 ;
int V_48 ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_132 ,
NULL , 0 , & V_130 , sizeof( V_130 ) ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof( V_130 ) )
return - V_502 ;
V_9 -> V_123 . V_130 = F_65 ( V_130 ) ;
F_130 ( V_9 -> V_123 . V_130 == V_131 ) ;
return 0 ;
}
static char * F_386 ( struct V_8 * V_9 )
{
F_387 ( V_390 ) ;
T_7 V_503 ;
char * V_473 ;
void * V_330 ;
void * V_179 ;
T_7 V_110 ;
void * V_492 = NULL ;
T_7 V_186 = 0 ;
char * V_472 = NULL ;
int V_48 ;
F_22 ( ! V_9 -> V_54 -> V_472 ) ;
V_186 = strlen ( V_9 -> V_54 -> V_473 ) ;
V_503 = sizeof ( V_297 ) + V_186 ;
V_473 = F_31 ( V_503 , V_68 ) ;
if ( ! V_473 )
return NULL ;
V_330 = V_473 ;
V_179 = V_473 + V_503 ;
F_388 ( & V_330 , V_179 , V_9 -> V_54 -> V_473 , ( T_6 ) V_186 ) ;
V_110 = sizeof ( V_297 ) + V_504 ;
V_492 = F_31 ( V_110 , V_68 ) ;
if ( ! V_492 )
goto V_58;
F_389 ( & V_390 , L_104 , V_505 ) ;
V_48 = F_285 ( V_9 , & V_390 , & V_9 -> V_315 ,
L_133 , V_473 , V_503 ,
V_492 , V_110 ) ;
if ( V_48 < 0 )
goto V_58;
V_330 = V_492 ;
V_179 = V_492 + V_48 ;
V_472 = F_380 ( & V_330 , V_179 , & V_186 , V_68 ) ;
if ( F_35 ( V_472 ) )
V_472 = NULL ;
else
F_30 ( L_134 , V_67 , V_472 , V_186 ) ;
V_58:
F_41 ( V_492 ) ;
F_41 ( V_473 ) ;
return V_472 ;
}
static V_120 F_390 ( struct V_8 * V_9 , const char * V_359 )
{
struct V_118 * V_135 = V_9 -> V_123 . V_135 ;
const char * V_149 ;
T_6 V_148 = 0 ;
V_149 = V_9 -> V_123 . V_136 ;
while ( V_148 < V_135 -> V_150 ) {
if ( ! strcmp ( V_359 , V_149 ) )
return V_135 -> V_143 [ V_148 ] ;
V_149 += strlen ( V_149 ) + 1 ;
V_148 ++ ;
}
return V_56 ;
}
static V_120 F_391 ( struct V_8 * V_9 , const char * V_359 )
{
struct V_118 * V_135 = V_9 -> V_123 . V_135 ;
T_6 V_148 ;
bool V_78 = false ;
V_120 V_55 ;
for ( V_148 = 0 ; ! V_78 && V_148 < V_135 -> V_150 ; V_148 ++ ) {
const char * V_149 ;
V_55 = V_135 -> V_143 [ V_148 ] ;
V_149 = F_80 ( V_9 , V_55 ) ;
if ( F_35 ( V_149 ) ) {
if ( F_201 ( V_149 ) == - V_43 )
continue;
else
break;
}
V_78 = ! strcmp ( V_359 , V_149 ) ;
F_41 ( V_149 ) ;
}
return V_78 ? V_55 : V_56 ;
}
static V_120 F_392 ( struct V_8 * V_9 , const char * V_359 )
{
if ( V_9 -> V_107 == 1 )
return F_390 ( V_9 , V_359 ) ;
return F_391 ( V_9 , V_359 ) ;
}
static int F_393 ( struct V_8 * V_9 )
{
struct V_475 * V_54 = V_9 -> V_54 ;
F_22 ( V_54 -> V_129 != V_131 && V_54 -> V_471 ) ;
F_22 ( V_54 -> V_473 && V_54 -> V_472 ) ;
F_22 ( V_54 -> V_149 ) ;
if ( strcmp ( V_54 -> V_149 , V_156 ) ) {
V_120 V_55 ;
V_55 = F_392 ( V_9 , V_54 -> V_149 ) ;
if ( V_55 == V_56 )
return - V_43 ;
V_54 -> V_55 = V_55 ;
} else {
V_54 -> V_55 = V_56 ;
}
return 0 ;
}
static int F_394 ( struct V_8 * V_9 )
{
struct V_251 * V_252 = & V_9 -> V_62 -> V_72 -> V_252 ;
struct V_475 * V_54 = V_9 -> V_54 ;
const char * V_471 ;
const char * V_472 ;
const char * V_149 ;
int V_48 ;
F_22 ( V_54 -> V_129 != V_131 ) ;
F_22 ( V_54 -> V_473 ) ;
F_22 ( V_54 -> V_55 != V_56 ) ;
V_471 = F_395 ( V_252 -> V_506 , V_54 -> V_129 ) ;
if ( ! V_471 ) {
F_107 ( V_9 , L_135 , V_54 -> V_129 ) ;
return - V_147 ;
}
V_471 = F_75 ( V_471 , V_68 ) ;
if ( ! V_471 )
return - V_66 ;
V_472 = F_386 ( V_9 ) ;
if ( ! V_472 )
F_107 ( V_9 , L_136 ) ;
V_149 = F_79 ( V_9 , V_54 -> V_55 ) ;
if ( F_35 ( V_149 ) ) {
V_48 = F_201 ( V_149 ) ;
goto V_139;
}
V_54 -> V_471 = V_471 ;
V_54 -> V_472 = V_472 ;
V_54 -> V_149 = V_149 ;
return 0 ;
V_139:
F_41 ( V_472 ) ;
F_41 ( V_471 ) ;
return V_48 ;
}
static int F_396 ( struct V_8 * V_9 )
{
T_7 V_110 ;
int V_48 ;
void * V_492 ;
void * V_330 ;
void * V_179 ;
V_120 V_140 ;
T_6 V_111 ;
struct V_118 * V_135 ;
T_6 V_138 ;
V_110 = sizeof ( V_119 ) + sizeof ( V_297 ) +
V_507 * sizeof ( V_119 ) ;
V_492 = F_357 ( V_110 , V_68 ) ;
if ( ! V_492 )
return - V_66 ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_137 ,
NULL , 0 , V_492 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_58;
V_330 = V_492 ;
V_179 = V_492 + V_48 ;
V_48 = - V_491 ;
F_382 ( & V_330 , V_179 , V_140 , V_58 ) ;
F_231 ( & V_330 , V_179 , V_111 , V_58 ) ;
if ( V_111 > ( V_117 - sizeof ( struct V_118 ) )
/ sizeof ( V_120 ) ) {
V_48 = - V_4 ;
goto V_58;
}
if ( ! F_397 ( & V_330 , V_179 , V_111 * sizeof ( V_119 ) ) )
goto V_58;
V_48 = 0 ;
V_135 = F_71 ( V_111 , V_68 ) ;
if ( ! V_135 ) {
V_48 = - V_66 ;
goto V_58;
}
V_135 -> V_140 = V_140 ;
for ( V_138 = 0 ; V_138 < V_111 ; V_138 ++ )
V_135 -> V_143 [ V_138 ] = F_260 ( & V_330 ) ;
F_73 ( V_9 -> V_123 . V_135 ) ;
V_9 -> V_123 . V_135 = V_135 ;
F_30 ( L_138 ,
( unsigned long long ) V_140 , ( unsigned int ) V_111 ) ;
V_58:
F_41 ( V_492 ) ;
return V_48 ;
}
static const char * F_80 ( struct V_8 * V_9 ,
V_120 V_55 )
{
T_7 V_110 ;
void * V_492 ;
V_119 V_487 ;
int V_48 ;
void * V_330 ;
void * V_179 ;
char * V_149 ;
V_110 = sizeof ( V_297 ) + V_508 ;
V_492 = F_31 ( V_110 , V_68 ) ;
if ( ! V_492 )
return F_43 ( - V_66 ) ;
V_487 = F_377 ( V_55 ) ;
V_48 = F_285 ( V_9 , & V_9 -> V_314 ,
& V_9 -> V_315 , L_139 ,
& V_487 , sizeof( V_487 ) , V_492 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 ) {
V_149 = F_43 ( V_48 ) ;
goto V_58;
}
V_330 = V_492 ;
V_179 = V_492 + V_48 ;
V_149 = F_380 ( & V_330 , V_179 , NULL , V_68 ) ;
if ( F_35 ( V_149 ) )
goto V_58;
F_30 ( L_140 ,
( unsigned long long ) V_55 , V_149 ) ;
V_58:
F_41 ( V_492 ) ;
return V_149 ;
}
static int F_398 ( struct V_8 * V_9 )
{
bool V_133 = V_9 -> V_123 . V_134 == NULL ;
int V_48 ;
V_48 = F_378 ( V_9 ) ;
if ( V_48 )
return V_48 ;
if ( V_133 ) {
V_48 = F_399 ( V_9 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_396 ( V_9 ) ;
if ( V_48 && V_133 ) {
F_41 ( V_9 -> V_123 . V_134 ) ;
V_9 -> V_123 . V_134 = NULL ;
}
return V_48 ;
}
static int F_318 ( struct V_8 * V_9 )
{
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_9 -> V_107 == 1 )
return F_313 ( V_9 ) ;
return F_398 ( V_9 ) ;
}
static inline T_7 F_400 ( const char * * V_17 )
{
const char * V_509 = L_141 ;
* V_17 += strspn ( * V_17 , V_509 ) ;
return strcspn ( * V_17 , V_509 ) ;
}
static inline char * F_401 ( const char * * V_17 , T_7 * V_510 )
{
char * V_511 ;
T_7 V_186 ;
V_186 = F_400 ( V_17 ) ;
V_511 = F_402 ( * V_17 , V_186 + 1 , V_68 ) ;
if ( ! V_511 )
return NULL ;
* ( V_511 + V_186 ) = '\0' ;
* V_17 += V_186 ;
if ( V_510 )
* V_510 = V_186 ;
return V_511 ;
}
static int F_403 ( const char * V_17 ,
struct V_63 * * V_64 ,
struct V_82 * * V_374 ,
struct V_475 * * V_475 )
{
T_7 V_186 ;
char * V_114 ;
const char * V_512 ;
char * V_149 ;
T_7 V_513 ;
struct V_475 * V_54 = NULL ;
struct V_82 * V_83 = NULL ;
struct V_63 * V_514 ;
int V_48 ;
V_186 = F_400 ( & V_17 ) ;
if ( ! V_186 ) {
F_107 ( NULL , L_142 ) ;
return - V_4 ;
}
V_512 = V_17 ;
V_513 = V_186 + 1 ;
V_17 += V_186 ;
V_48 = - V_4 ;
V_114 = F_401 ( & V_17 , NULL ) ;
if ( ! V_114 )
return - V_66 ;
if ( ! * V_114 ) {
F_107 ( NULL , L_143 ) ;
goto V_139;
}
V_54 = F_356 () ;
if ( ! V_54 )
goto V_515;
V_54 -> V_471 = F_401 ( & V_17 , NULL ) ;
if ( ! V_54 -> V_471 )
goto V_515;
if ( ! * V_54 -> V_471 ) {
F_107 ( NULL , L_144 ) ;
goto V_139;
}
V_54 -> V_472 = F_401 ( & V_17 , NULL ) ;
if ( ! V_54 -> V_472 )
goto V_515;
if ( ! * V_54 -> V_472 ) {
F_107 ( NULL , L_145 ) ;
goto V_139;
}
V_186 = F_400 ( & V_17 ) ;
if ( ! V_186 ) {
V_17 = V_156 ;
V_186 = sizeof ( V_156 ) - 1 ;
} else if ( V_186 > V_508 ) {
V_48 = - V_516 ;
goto V_139;
}
V_149 = F_402 ( V_17 , V_186 + 1 , V_68 ) ;
if ( ! V_149 )
goto V_515;
* ( V_149 + V_186 ) = '\0' ;
V_54 -> V_149 = V_149 ;
V_83 = F_357 ( sizeof ( * V_83 ) , V_68 ) ;
if ( ! V_83 )
goto V_515;
V_83 -> V_37 = V_517 ;
V_83 -> V_93 = V_518 ;
V_83 -> V_97 = V_519 ;
V_83 -> V_99 = V_520 ;
V_514 = F_404 ( V_114 , V_512 ,
V_512 + V_513 - 1 ,
F_49 , V_83 ) ;
if ( F_35 ( V_514 ) ) {
V_48 = F_201 ( V_514 ) ;
goto V_139;
}
F_41 ( V_114 ) ;
* V_64 = V_514 ;
* V_374 = V_83 ;
* V_475 = V_54 ;
return 0 ;
V_515:
V_48 = - V_66 ;
V_139:
F_41 ( V_83 ) ;
F_175 ( V_54 ) ;
F_41 ( V_114 ) ;
return V_48 ;
}
static int F_405 ( struct V_62 * V_65 , const char * V_471 )
{
struct V_63 * V_374 = V_65 -> V_72 -> V_114 ;
V_120 V_521 ;
int V_522 = 0 ;
int V_48 ;
V_362:
V_48 = F_406 ( V_65 -> V_72 -> V_252 . V_506 , V_471 ) ;
if ( V_48 == - V_43 && V_522 ++ < 1 ) {
V_48 = F_407 ( & V_65 -> V_72 -> V_363 , L_146 ,
& V_521 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_65 -> V_72 -> V_252 . V_506 -> V_523 < V_521 ) {
F_408 ( & V_65 -> V_72 -> V_252 ) ;
( void ) F_409 ( & V_65 -> V_72 -> V_363 ,
V_521 ,
V_374 -> V_524 ) ;
goto V_362;
} else {
return - V_43 ;
}
}
return V_48 ;
}
static void F_410 ( struct V_8 * V_9 )
{
F_249 ( & V_9 -> V_14 ) ;
if ( F_9 ( V_9 ) )
F_219 ( V_9 ) ;
F_250 ( & V_9 -> V_14 ) ;
}
static int F_411 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_123 . V_159 & V_416 ) ) {
F_107 ( V_9 , L_147 ) ;
return - V_4 ;
}
F_11 ( & V_9 -> V_14 ) ;
F_289 ( V_9 ) ;
F_12 ( & V_9 -> V_14 ) ;
if ( F_18 ( V_368 , & V_9 -> V_41 ) ) {
F_107 ( V_9 , L_148 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_412 ( struct V_8 * V_9 )
{
int V_48 ;
T_7 V_110 ;
F_387 ( V_390 ) ;
void * V_525 ;
char * V_473 ;
if ( V_9 -> V_54 -> V_473 ) {
V_9 -> V_107 = * V_9 -> V_54 -> V_473 ? 2 : 1 ;
return 0 ;
}
V_48 = F_162 ( & V_390 , V_68 , L_149 , V_526 ,
V_9 -> V_54 -> V_472 ) ;
if ( V_48 )
return V_48 ;
F_30 ( L_150 , V_390 . V_359 ) ;
V_110 = sizeof ( V_297 ) + V_498 ;
V_525 = F_357 ( V_110 , V_257 ) ;
if ( ! V_525 ) {
V_48 = - V_66 ;
goto V_58;
}
V_48 = F_285 ( V_9 , & V_390 , & V_9 -> V_315 ,
L_151 , NULL , 0 ,
V_525 , V_498 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 == - V_43 ) {
V_473 = F_75 ( L_41 , V_68 ) ;
V_48 = V_473 ? 0 : - V_66 ;
if ( ! V_48 )
V_9 -> V_107 = 1 ;
} else if ( V_48 >= 0 ) {
void * V_330 = V_525 ;
V_473 = F_380 ( & V_330 , V_330 + V_48 ,
NULL , V_257 ) ;
V_48 = F_413 ( V_473 ) ;
if ( ! V_48 )
V_9 -> V_107 = 2 ;
}
if ( ! V_48 ) {
V_9 -> V_54 -> V_473 = V_473 ;
F_30 ( L_152 , V_473 ) ;
}
V_58:
F_41 ( V_525 ) ;
F_359 ( & V_390 ) ;
return V_48 ;
}
static void F_414 ( struct V_8 * V_9 )
{
struct V_122 * V_123 ;
F_176 ( V_9 ) ;
V_123 = & V_9 -> V_123 ;
F_73 ( V_123 -> V_135 ) ;
F_41 ( V_123 -> V_137 ) ;
F_41 ( V_123 -> V_136 ) ;
F_41 ( V_123 -> V_134 ) ;
memset ( V_123 , 0 , sizeof ( * V_123 ) ) ;
}
static int F_399 ( struct V_8 * V_9 )
{
int V_48 ;
V_48 = F_379 ( V_9 ) ;
if ( V_48 )
goto V_139;
V_48 = F_381 ( V_9 ) ;
if ( V_48 )
goto V_139;
if ( V_9 -> V_123 . V_159 & V_527 ) {
V_48 = F_384 ( V_9 ) ;
if ( V_48 < 0 )
goto V_139;
}
if ( V_9 -> V_123 . V_159 & V_528 ) {
V_48 = F_385 ( V_9 ) ;
if ( V_48 )
goto V_139;
}
F_67 ( V_9 ) ;
return 0 ;
V_139:
V_9 -> V_123 . V_159 = 0 ;
F_41 ( V_9 -> V_123 . V_134 ) ;
V_9 -> V_123 . V_134 = NULL ;
return V_48 ;
}
static int F_415 ( struct V_8 * V_9 , int V_529 )
{
struct V_8 * V_278 = NULL ;
int V_48 ;
if ( ! V_9 -> V_269 )
return 0 ;
if ( ++ V_529 > V_530 ) {
F_383 ( L_153 , V_529 ) ;
V_48 = - V_4 ;
goto V_139;
}
V_278 = F_365 ( V_9 -> V_62 , V_9 -> V_269 ) ;
if ( ! V_278 ) {
V_48 = - V_66 ;
goto V_139;
}
F_44 ( V_9 -> V_62 ) ;
F_355 ( V_9 -> V_269 ) ;
V_48 = F_416 ( V_278 , V_529 ) ;
if ( V_48 < 0 )
goto V_139;
V_9 -> V_278 = V_278 ;
F_417 ( & V_9 -> V_270 , 1 ) ;
return 0 ;
V_139:
F_173 ( V_9 ) ;
F_376 ( V_278 ) ;
return V_48 ;
}
static void F_418 ( struct V_8 * V_9 )
{
F_140 ( V_414 , & V_9 -> V_41 ) ;
F_86 ( V_9 ) ;
F_304 ( V_9 ) ;
if ( ! V_24 )
F_419 ( V_9 -> V_440 , V_9 -> V_359 ) ;
}
static int F_420 ( struct V_8 * V_9 )
{
int V_48 ;
if ( ! V_24 ) {
V_48 = F_421 ( 0 , V_9 -> V_359 ) ;
if ( V_48 < 0 )
goto V_531;
V_9 -> V_440 = V_48 ;
V_9 -> V_7 = 0 ;
} else {
V_9 -> V_440 = V_532 ;
V_9 -> V_7 = F_7 ( V_9 -> V_5 ) ;
}
V_48 = F_322 ( V_9 ) ;
if ( V_48 )
goto V_533;
V_48 = F_85 ( V_9 ) ;
if ( V_48 )
goto V_534;
F_316 ( V_9 -> V_45 , V_9 -> V_36 . V_110 / V_432 ) ;
F_26 ( V_9 -> V_45 , V_9 -> V_36 . V_37 ) ;
V_48 = F_422 ( & V_9 -> V_29 , L_93 , V_9 -> V_5 ) ;
if ( V_48 )
goto V_535;
F_115 ( V_414 , & V_9 -> V_41 ) ;
F_250 ( & V_9 -> V_271 ) ;
return 0 ;
V_535:
F_86 ( V_9 ) ;
V_534:
F_304 ( V_9 ) ;
V_533:
if ( ! V_24 )
F_419 ( V_9 -> V_440 , V_9 -> V_359 ) ;
V_531:
F_250 ( & V_9 -> V_271 ) ;
return V_48 ;
}
static int F_423 ( struct V_8 * V_9 )
{
struct V_475 * V_54 = V_9 -> V_54 ;
int V_48 ;
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_9 -> V_107 == 1 )
V_48 = F_162 ( & V_9 -> V_314 , V_68 , L_149 ,
V_54 -> V_472 , V_536 ) ;
else
V_48 = F_162 ( & V_9 -> V_314 , V_68 , L_149 ,
V_537 , V_54 -> V_473 ) ;
return V_48 ;
}
static void F_424 ( struct V_8 * V_9 )
{
F_414 ( V_9 ) ;
if ( V_9 -> V_374 )
F_279 ( V_9 ) ;
V_9 -> V_107 = 0 ;
F_41 ( V_9 -> V_54 -> V_473 ) ;
V_9 -> V_54 -> V_473 = NULL ;
}
static int F_416 ( struct V_8 * V_9 , int V_529 )
{
int V_48 ;
V_48 = F_412 ( V_9 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_423 ( V_9 ) ;
if ( V_48 )
goto V_538;
if ( ! V_529 ) {
V_48 = F_275 ( V_9 ) ;
if ( V_48 ) {
if ( V_48 == - V_43 )
F_383 ( L_154 ,
V_9 -> V_54 -> V_471 ,
V_9 -> V_54 -> V_472 ) ;
goto V_538;
}
}
V_48 = F_318 ( V_9 ) ;
if ( V_48 )
goto V_539;
if ( ! V_529 )
V_48 = F_393 ( V_9 ) ;
else
V_48 = F_394 ( V_9 ) ;
if ( V_48 ) {
if ( V_48 == - V_43 )
F_383 ( L_155 ,
V_9 -> V_54 -> V_471 ,
V_9 -> V_54 -> V_472 ,
V_9 -> V_54 -> V_149 ) ;
goto V_540;
}
if ( V_9 -> V_123 . V_159 & V_541 ) {
V_48 = F_319 ( V_9 ) ;
if ( V_48 )
goto V_540;
if ( ! V_529 && V_9 -> V_269 )
F_107 ( V_9 ,
L_156 ) ;
}
V_48 = F_415 ( V_9 , V_529 ) ;
if ( V_48 )
goto V_540;
F_30 ( L_157 ,
V_9 -> V_107 , V_9 -> V_314 . V_359 ) ;
return 0 ;
V_540:
F_414 ( V_9 ) ;
V_539:
if ( ! V_529 )
F_279 ( V_9 ) ;
V_538:
V_9 -> V_107 = 0 ;
F_41 ( V_9 -> V_54 -> V_473 ) ;
V_9 -> V_54 -> V_473 = NULL ;
return V_48 ;
}
static T_2 F_425 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
struct V_8 * V_9 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_82 * V_83 = NULL ;
struct V_475 * V_54 = NULL ;
struct V_62 * V_65 ;
bool V_37 ;
int V_542 ;
if ( ! F_426 ( V_479 ) )
return - V_543 ;
V_542 = F_403 ( V_17 , & V_64 , & V_83 , & V_54 ) ;
if ( V_542 < 0 )
goto V_58;
V_65 = F_54 ( V_64 ) ;
if ( F_35 ( V_65 ) ) {
V_542 = F_201 ( V_65 ) ;
goto V_544;
}
V_542 = F_405 ( V_65 , V_54 -> V_471 ) ;
if ( V_542 < 0 ) {
if ( V_542 == - V_43 )
F_383 ( L_158 , V_54 -> V_471 ) ;
goto V_545;
}
V_54 -> V_129 = ( V_120 ) V_542 ;
V_9 = F_372 ( V_65 , V_54 , V_83 ) ;
if ( ! V_9 ) {
V_542 = - V_66 ;
goto V_545;
}
V_65 = NULL ;
V_54 = NULL ;
V_83 = NULL ;
V_9 -> V_470 = F_75 ( V_17 , V_68 ) ;
if ( ! V_9 -> V_470 ) {
V_542 = - V_66 ;
goto V_546;
}
F_249 ( & V_9 -> V_271 ) ;
V_542 = F_416 ( V_9 , 0 ) ;
if ( V_542 < 0 ) {
F_250 ( & V_9 -> V_271 ) ;
goto V_546;
}
V_37 = V_9 -> V_374 -> V_37 ;
if ( V_9 -> V_54 -> V_55 != V_56 )
V_37 = true ;
V_9 -> V_36 . V_37 = V_37 ;
V_542 = F_420 ( V_9 ) ;
if ( V_542 )
goto V_547;
if ( V_9 -> V_374 -> V_99 ) {
V_542 = F_411 ( V_9 ) ;
if ( V_542 )
goto V_548;
}
V_542 = F_427 ( & V_9 -> V_29 ) ;
if ( V_542 )
goto V_549;
F_428 ( V_9 -> V_45 ) ;
F_429 ( V_9 -> V_45 -> V_425 ) ;
F_37 ( & V_550 ) ;
F_38 ( & V_9 -> V_71 , & V_551 ) ;
F_39 ( & V_550 ) ;
F_383 ( L_159 , V_9 -> V_45 -> V_439 ,
( unsigned long long ) F_430 ( V_9 -> V_45 ) << V_116 ,
V_9 -> V_123 . V_159 ) ;
V_542 = V_474 ;
V_58:
F_364 ( V_479 ) ;
return V_542 ;
V_549:
F_410 ( V_9 ) ;
V_548:
F_418 ( V_9 ) ;
V_547:
F_424 ( V_9 ) ;
V_546:
F_376 ( V_9 ) ;
V_545:
F_60 ( V_65 ) ;
V_544:
F_175 ( V_54 ) ;
F_41 ( V_83 ) ;
goto V_58;
}
static T_2 F_431 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
if ( V_24 )
return - V_4 ;
return F_425 ( V_16 , V_17 , V_474 ) ;
}
static T_2 F_432 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
return F_425 ( V_16 , V_17 , V_474 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
while ( V_9 -> V_278 ) {
struct V_8 * V_552 = V_9 ;
struct V_8 * V_553 = V_552 -> V_278 ;
struct V_8 * V_554 ;
while ( V_553 && ( V_554 = V_553 -> V_278 ) ) {
V_552 = V_553 ;
V_553 = V_554 ;
}
F_22 ( V_553 ) ;
F_424 ( V_553 ) ;
F_376 ( V_553 ) ;
V_552 -> V_278 = NULL ;
V_552 -> V_202 = 0 ;
F_22 ( V_552 -> V_269 ) ;
F_175 ( V_552 -> V_269 ) ;
V_552 -> V_269 = NULL ;
}
}
static T_2 F_433 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
struct V_8 * V_9 = NULL ;
struct V_555 * V_166 ;
int V_5 ;
char V_556 [ 6 ] ;
bool V_557 = false ;
bool V_558 = false ;
int V_48 ;
V_5 = - 1 ;
V_556 [ 0 ] = '\0' ;
sscanf ( V_17 , L_160 , & V_5 , V_556 ) ;
if ( V_5 < 0 ) {
F_52 ( L_161 ) ;
return - V_4 ;
}
if ( V_556 [ 0 ] != '\0' ) {
if ( ! strcmp ( V_556 , L_162 ) ) {
V_558 = true ;
} else {
F_52 ( L_163 , V_556 ) ;
return - V_4 ;
}
}
V_48 = - V_43 ;
F_37 ( & V_550 ) ;
F_434 (tmp, &rbd_dev_list) {
V_9 = F_435 ( V_166 , struct V_8 , V_71 ) ;
if ( V_9 -> V_5 == V_5 ) {
V_48 = 0 ;
break;
}
}
if ( ! V_48 ) {
F_17 ( & V_9 -> V_39 ) ;
if ( V_9 -> V_42 && ! V_558 )
V_48 = - V_57 ;
else
V_557 = F_109 ( V_40 ,
& V_9 -> V_41 ) ;
F_19 ( & V_9 -> V_39 ) ;
}
F_39 ( & V_550 ) ;
if ( V_48 < 0 || V_557 )
return V_48 ;
if ( V_558 ) {
F_436 ( V_9 -> V_45 -> V_425 ) ;
F_437 ( V_9 -> V_45 -> V_425 ) ;
}
F_438 ( V_9 -> V_45 ) ;
F_37 ( & V_550 ) ;
F_439 ( & V_9 -> V_71 ) ;
F_39 ( & V_550 ) ;
F_440 ( & V_9 -> V_29 ) ;
F_410 ( V_9 ) ;
F_418 ( V_9 ) ;
F_424 ( V_9 ) ;
F_376 ( V_9 ) ;
return V_474 ;
}
static T_2 F_441 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
if ( V_24 )
return - V_4 ;
return F_433 ( V_16 , V_17 , V_474 ) ;
}
static T_2 F_442 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_474 )
{
return F_433 ( V_16 , V_17 , V_474 ) ;
}
static int F_443 ( void )
{
int V_48 ;
V_48 = F_444 ( & V_482 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_445 ( & V_480 ) ;
if ( V_48 < 0 )
F_446 ( & V_482 ) ;
return V_48 ;
}
static void F_447 ( void )
{
F_448 ( & V_480 ) ;
F_446 ( & V_482 ) ;
}
static int F_449 ( void )
{
F_22 ( ! V_272 ) ;
V_272 = F_450 ( V_204 , 0 ) ;
if ( ! V_272 )
return - V_66 ;
F_22 ( ! V_267 ) ;
V_267 = F_450 ( V_193 , 0 ) ;
if ( ! V_267 )
goto V_139;
F_22 ( ! V_188 ) ;
V_188 = F_451 ( V_559 , 0 , 0 ) ;
if ( ! V_188 )
goto V_560;
return 0 ;
V_560:
F_452 ( V_267 ) ;
V_267 = NULL ;
V_139:
F_452 ( V_272 ) ;
V_272 = NULL ;
return - V_66 ;
}
static void F_453 ( void )
{
F_22 ( V_267 ) ;
F_452 ( V_267 ) ;
V_267 = NULL ;
F_22 ( V_272 ) ;
F_452 ( V_272 ) ;
V_272 = NULL ;
F_22 ( V_188 ) ;
F_454 ( V_188 ) ;
V_188 = NULL ;
}
static int T_13 F_455 ( void )
{
int V_542 ;
if ( ! F_456 ( NULL ) ) {
F_107 ( NULL , L_164 ) ;
return - V_4 ;
}
V_542 = F_449 () ;
if ( V_542 )
return V_542 ;
V_423 = F_457 ( V_401 , V_485 , 0 ) ;
if ( ! V_423 ) {
V_542 = - V_66 ;
goto V_561;
}
if ( V_24 ) {
V_532 = F_421 ( 0 , V_401 ) ;
if ( V_532 < 0 ) {
V_542 = V_532 ;
goto V_562;
}
}
V_542 = F_443 () ;
if ( V_542 )
goto V_533;
if ( V_24 )
F_383 ( L_165 , V_532 ) ;
else
F_383 ( L_166 ) ;
return 0 ;
V_533:
if ( V_24 )
F_419 ( V_532 , V_401 ) ;
V_562:
F_362 ( V_423 ) ;
V_561:
F_453 () ;
return V_542 ;
}
static void T_14 F_458 ( void )
{
F_459 ( & V_478 ) ;
F_447 () ;
if ( V_24 )
F_419 ( V_532 , V_401 ) ;
F_362 ( V_423 ) ;
F_453 () ;
}
