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
V_164 = F_104 ( V_185 , V_187 ) ;
if ( ! V_164 )
return NULL ;
F_105 ( V_164 , V_160 ) ;
V_164 -> V_188 . V_189 = V_186 ;
return V_164 ;
}
static struct V_164 * F_106 ( struct V_164 * * V_185 ,
unsigned int * V_160 ,
unsigned int V_186 ,
T_8 V_187 )
{
struct V_164 * V_190 = * V_185 ;
unsigned int V_191 = * V_160 ;
struct V_164 * V_165 = NULL ;
struct V_164 * * V_179 ;
if ( ! V_190 || V_191 >= V_190 -> V_188 . V_189 || ! V_186 )
return NULL ;
V_179 = & V_165 ;
while ( V_186 ) {
unsigned int V_189 ;
struct V_164 * V_164 ;
if ( ! V_190 ) {
F_107 ( NULL , L_14 , V_186 ) ;
goto V_139;
}
V_189 = F_98 (unsigned int, bi->bi_iter.bi_size - off, len) ;
V_164 = F_103 ( V_190 , V_191 , V_189 , V_187 ) ;
if ( ! V_164 )
goto V_139;
* V_179 = V_164 ;
V_179 = & V_164 -> V_167 ;
V_191 += V_189 ;
if ( V_191 == V_190 -> V_188 . V_189 ) {
V_190 = V_190 -> V_167 ;
V_191 = 0 ;
}
V_186 -= V_189 ;
}
* V_185 = V_190 ;
* V_160 = V_191 ;
return V_165 ;
V_139:
F_89 ( V_165 ) ;
return NULL ;
}
static void F_108 ( struct V_192 * V_193 )
{
if ( F_109 ( V_194 , & V_193 -> V_41 ) ) {
struct V_8 * V_9 ;
V_9 = V_193 -> V_195 -> V_9 ;
F_107 ( V_9 , L_15 ,
V_193 ) ;
}
}
static bool F_110 ( struct V_192 * V_193 )
{
F_111 () ;
return F_18 ( V_194 , & V_193 -> V_41 ) != 0 ;
}
static void F_112 ( struct V_192 * V_193 )
{
if ( F_109 ( V_196 , & V_193 -> V_41 ) ) {
struct V_8 * V_9 = NULL ;
if ( F_110 ( V_193 ) )
V_9 = V_193 -> V_195 -> V_9 ;
F_107 ( V_9 , L_16 ,
V_193 ) ;
}
}
static bool F_113 ( struct V_192 * V_193 )
{
F_111 () ;
return F_18 ( V_196 , & V_193 -> V_41 ) != 0 ;
}
static void F_114 ( struct V_192 * V_193 ,
bool V_197 )
{
if ( V_197 )
F_115 ( V_198 , & V_193 -> V_41 ) ;
F_115 ( V_199 , & V_193 -> V_41 ) ;
F_111 () ;
}
static bool F_116 ( struct V_192 * V_193 )
{
F_111 () ;
return F_18 ( V_199 , & V_193 -> V_41 ) != 0 ;
}
static bool F_117 ( struct V_192 * V_193 )
{
F_111 () ;
return F_18 ( V_198 , & V_193 -> V_41 ) != 0 ;
}
static bool F_118 ( struct V_192 * V_193 )
{
struct V_8 * V_9 = V_193 -> V_195 -> V_9 ;
return V_193 -> V_200 <
F_119 ( V_9 -> V_201 , F_66 ( & V_9 -> V_123 ) ) ;
}
static void F_120 ( struct V_192 * V_193 )
{
F_30 ( L_17 , V_67 , V_193 ,
F_121 ( & V_193 -> V_70 ) ) ;
F_45 ( & V_193 -> V_70 ) ;
}
static void F_122 ( struct V_192 * V_193 )
{
F_22 ( V_193 != NULL ) ;
F_30 ( L_17 , V_67 , V_193 ,
F_121 ( & V_193 -> V_70 ) ) ;
F_61 ( & V_193 -> V_70 , V_202 ) ;
}
static void F_123 ( struct V_203 * V_195 )
{
F_30 ( L_18 , V_67 , V_195 ,
F_121 ( & V_195 -> V_70 ) ) ;
F_45 ( & V_195 -> V_70 ) ;
}
static void F_124 ( struct V_203 * V_195 )
{
F_22 ( V_195 != NULL ) ;
F_30 ( L_18 , V_67 , V_195 ,
F_121 ( & V_195 -> V_70 ) ) ;
if ( F_125 ( V_195 ) )
F_61 ( & V_195 -> V_70 , V_204 ) ;
else
F_61 ( & V_195 -> V_70 , V_205 ) ;
}
static inline void F_126 ( struct V_203 * V_195 ,
struct V_192 * V_193 )
{
F_22 ( V_193 -> V_195 == NULL ) ;
V_193 -> V_195 = V_195 ;
V_193 -> V_148 = V_195 -> V_206 ;
F_22 ( ! F_110 ( V_193 ) ) ;
F_108 ( V_193 ) ;
F_22 ( V_193 -> V_148 != V_207 ) ;
V_195 -> V_206 ++ ;
F_38 ( & V_193 -> V_208 , & V_195 -> V_209 ) ;
F_30 ( L_19 , V_67 , V_195 , V_193 ,
V_193 -> V_148 ) ;
}
static inline void F_127 ( struct V_203 * V_195 ,
struct V_192 * V_193 )
{
F_22 ( V_193 -> V_148 != V_207 ) ;
F_30 ( L_19 , V_67 , V_195 , V_193 ,
V_193 -> V_148 ) ;
F_59 ( & V_193 -> V_208 ) ;
F_22 ( V_195 -> V_206 > 0 ) ;
V_195 -> V_206 -- ;
F_22 ( V_193 -> V_148 == V_195 -> V_206 ) ;
V_193 -> V_148 = V_207 ;
F_22 ( F_110 ( V_193 ) ) ;
F_22 ( V_193 -> V_195 == V_195 ) ;
V_193 -> V_195 = NULL ;
V_193 -> V_210 = NULL ;
F_122 ( V_193 ) ;
}
static bool F_128 ( enum V_211 type )
{
switch ( type ) {
case V_212 :
case V_213 :
case V_214 :
return true ;
default:
return false ;
}
}
static void F_129 ( struct V_192 * V_193 )
{
struct V_215 * V_216 = V_193 -> V_216 ;
F_30 ( L_20 , V_67 ,
V_193 , V_193 -> V_217 , V_193 -> V_160 ,
V_193 -> V_162 , V_216 ) ;
if ( F_110 ( V_193 ) ) {
F_130 ( V_193 -> V_210 != V_218 ) ;
F_123 ( V_193 -> V_195 ) ;
}
F_131 ( V_216 -> V_219 , V_216 , false ) ;
}
static void F_132 ( struct V_203 * V_195 )
{
F_30 ( L_21 , V_67 , V_195 ) ;
if ( ! V_195 -> V_220 ) {
struct V_192 * V_193 ;
V_120 V_221 = 0 ;
F_133 (img_request, obj_request)
V_221 += V_193 -> V_221 ;
V_195 -> V_221 = V_221 ;
}
if ( V_195 -> V_210 )
V_195 -> V_210 ( V_195 ) ;
else
F_124 ( V_195 ) ;
}
static void F_134 ( struct V_203 * V_195 )
{
F_115 ( V_222 , & V_195 -> V_41 ) ;
F_111 () ;
}
static bool F_135 ( struct V_203 * V_195 )
{
F_111 () ;
return F_18 ( V_222 , & V_195 -> V_41 ) != 0 ;
}
static void F_136 ( struct V_203 * V_195 )
{
F_115 ( V_223 , & V_195 -> V_41 ) ;
F_111 () ;
}
static bool F_137 ( struct V_203 * V_195 )
{
F_111 () ;
return F_18 ( V_223 , & V_195 -> V_41 ) != 0 ;
}
static void F_138 ( struct V_203 * V_195 )
{
F_115 ( V_224 , & V_195 -> V_41 ) ;
F_111 () ;
}
static void F_139 ( struct V_203 * V_195 )
{
F_140 ( V_224 , & V_195 -> V_41 ) ;
F_111 () ;
}
static bool F_125 ( struct V_203 * V_195 )
{
F_111 () ;
return F_18 ( V_224 , & V_195 -> V_41 ) != 0 ;
}
static void F_141 ( struct V_203 * V_195 )
{
F_115 ( V_225 , & V_195 -> V_41 ) ;
F_111 () ;
}
static void F_142 ( struct V_203 * V_195 )
{
F_140 ( V_225 , & V_195 -> V_41 ) ;
F_111 () ;
}
static bool F_143 ( struct V_203 * V_195 )
{
F_111 () ;
return F_18 ( V_225 , & V_195 -> V_41 ) != 0 ;
}
static enum V_100
F_144 ( struct V_203 * V_195 )
{
if ( F_135 ( V_195 ) )
return V_103 ;
else if ( F_137 ( V_195 ) )
return V_104 ;
else
return V_102 ;
}
static void
F_145 ( struct V_192 * V_193 )
{
V_120 V_221 = V_193 -> V_221 ;
V_120 V_162 = V_193 -> V_162 ;
F_30 ( L_22 , V_67 ,
V_193 , V_193 -> V_195 , V_193 -> V_220 ,
V_221 , V_162 ) ;
F_22 ( V_193 -> type != V_212 ) ;
if ( V_193 -> V_220 == - V_43 ) {
if ( V_193 -> type == V_213 )
F_91 ( V_193 -> V_226 , 0 ) ;
else
F_97 ( V_193 -> V_178 , 0 , V_162 ) ;
V_193 -> V_220 = 0 ;
} else if ( V_221 < V_162 && ! V_193 -> V_220 ) {
if ( V_193 -> type == V_213 )
F_91 ( V_193 -> V_226 , V_221 ) ;
else
F_97 ( V_193 -> V_178 , V_221 , V_162 ) ;
}
V_193 -> V_221 = V_162 ;
F_112 ( V_193 ) ;
}
static void F_146 ( struct V_192 * V_193 )
{
F_30 ( L_23 , V_67 , V_193 ,
V_193 -> V_210 ) ;
if ( V_193 -> V_210 )
V_193 -> V_210 ( V_193 ) ;
else
F_147 ( & V_193 -> V_227 ) ;
}
static void F_148 ( struct V_192 * V_193 , int V_228 )
{
V_193 -> V_220 = V_228 ;
V_193 -> V_221 = 0 ;
if ( F_110 ( V_193 ) ) {
F_130 ( V_193 -> V_210 != V_218 ) ;
F_123 ( V_193 -> V_195 ) ;
}
F_112 ( V_193 ) ;
F_146 ( V_193 ) ;
}
static void F_149 ( struct V_192 * V_193 )
{
struct V_203 * V_195 = NULL ;
struct V_8 * V_9 = NULL ;
bool V_229 = false ;
if ( F_110 ( V_193 ) ) {
V_195 = V_193 -> V_195 ;
V_229 = V_195 && F_143 ( V_195 ) ;
V_9 = V_195 -> V_9 ;
}
F_30 ( L_22 , V_67 ,
V_193 , V_195 , V_193 -> V_220 ,
V_193 -> V_221 , V_193 -> V_162 ) ;
if ( V_229 && V_193 -> V_220 == - V_43 &&
V_193 -> V_200 < V_9 -> V_201 )
F_150 ( V_193 ) ;
else if ( V_195 )
F_145 ( V_193 ) ;
else
F_112 ( V_193 ) ;
}
static void F_151 ( struct V_192 * V_193 )
{
F_30 ( L_24 , V_67 , V_193 ,
V_193 -> V_220 , V_193 -> V_162 ) ;
V_193 -> V_221 = V_193 -> V_162 ;
F_112 ( V_193 ) ;
}
static void F_152 ( struct V_192 * V_193 )
{
F_30 ( L_24 , V_67 , V_193 ,
V_193 -> V_220 , V_193 -> V_162 ) ;
V_193 -> V_221 = V_193 -> V_162 ;
if ( V_193 -> V_220 == - V_43 )
V_193 -> V_220 = 0 ;
F_112 ( V_193 ) ;
}
static void F_153 ( struct V_192 * V_193 )
{
F_30 ( L_25 , V_67 , V_193 ) ;
F_112 ( V_193 ) ;
}
static void F_154 ( struct V_192 * V_193 )
{
F_30 ( L_25 , V_67 , V_193 ) ;
if ( F_110 ( V_193 ) )
F_155 ( V_193 ) ;
else
F_112 ( V_193 ) ;
}
static void F_156 ( struct V_215 * V_216 )
{
struct V_192 * V_193 = V_216 -> V_230 ;
T_9 V_231 ;
F_30 ( L_26 , V_67 , V_216 ) ;
F_22 ( V_216 == V_193 -> V_216 ) ;
if ( F_110 ( V_193 ) ) {
F_22 ( V_193 -> V_195 ) ;
F_22 ( V_193 -> V_148 != V_207 ) ;
} else {
F_22 ( V_193 -> V_148 == V_207 ) ;
}
if ( V_216 -> V_232 < 0 )
V_193 -> V_220 = V_216 -> V_232 ;
V_193 -> V_221 = V_216 -> V_233 [ 0 ] . V_234 ;
F_22 ( V_193 -> V_221 < ( V_120 ) V_235 ) ;
V_231 = V_216 -> V_233 [ 0 ] . V_236 ;
switch ( V_231 ) {
case V_237 :
F_149 ( V_193 ) ;
break;
case V_238 :
F_22 ( V_216 -> V_233 [ 1 ] . V_236 == V_239 ||
V_216 -> V_233 [ 1 ] . V_236 == V_240 ) ;
case V_239 :
case V_240 :
F_151 ( V_193 ) ;
break;
case V_241 :
F_153 ( V_193 ) ;
break;
case V_242 :
case V_243 :
case V_244 :
F_152 ( V_193 ) ;
break;
case V_245 :
F_154 ( V_193 ) ;
break;
default:
F_107 ( NULL , L_27 ,
V_193 -> V_217 , V_231 ) ;
break;
}
if ( F_113 ( V_193 ) )
F_146 ( V_193 ) ;
}
static void F_157 ( struct V_192 * V_193 )
{
struct V_215 * V_216 = V_193 -> V_216 ;
F_22 ( F_110 ( V_193 ) ) ;
V_216 -> V_246 = V_193 -> V_195 -> V_55 ;
}
static void F_158 ( struct V_192 * V_193 )
{
struct V_215 * V_216 = V_193 -> V_216 ;
F_159 ( & V_216 -> V_247 ) ;
V_216 -> V_248 = V_193 -> V_160 ;
}
static struct V_215 *
F_160 ( struct V_8 * V_9 ,
struct V_118 * V_135 ,
int V_249 , unsigned int V_41 ,
struct V_192 * V_193 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_215 * V_252 ;
const char * V_253 = V_9 -> V_107 == 1 ?
V_254 : V_255 ;
V_252 = F_161 ( V_251 , V_135 , V_249 , false , V_256 ) ;
if ( ! V_252 )
return NULL ;
V_252 -> V_257 = V_41 ;
V_252 -> V_258 = F_156 ;
V_252 -> V_230 = V_193 ;
V_252 -> V_259 . V_260 = V_9 -> V_127 . V_129 ;
if ( F_162 ( & V_252 -> V_261 , V_256 , V_253 ,
V_9 -> V_123 . V_134 , V_193 -> V_217 ) )
goto V_262;
if ( F_163 ( V_252 , V_256 ) )
goto V_262;
return V_252 ;
V_262:
F_164 ( V_252 ) ;
return NULL ;
}
static struct V_215 * F_165 (
struct V_8 * V_9 ,
enum V_100 V_101 ,
unsigned int V_249 ,
struct V_192 * V_193 )
{
struct V_118 * V_135 = NULL ;
if ( F_110 ( V_193 ) &&
( V_101 == V_104 || V_101 == V_103 ) ) {
struct V_203 * V_195 = V_193 -> V_195 ;
if ( V_101 == V_103 ) {
F_22 ( F_135 ( V_195 ) ) ;
} else {
F_22 ( F_137 ( V_195 ) ) ;
}
V_135 = V_195 -> V_135 ;
}
F_22 ( V_249 == 1 || ( ( V_101 == V_103 ) && V_249 == 2 ) ) ;
return F_160 ( V_9 , V_135 , V_249 ,
( V_101 == V_103 || V_101 == V_104 ) ?
V_263 : V_264 , V_193 ) ;
}
static struct V_215 *
F_166 ( struct V_192 * V_193 )
{
struct V_203 * V_195 ;
int V_265 = 3 ;
F_22 ( F_110 ( V_193 ) ) ;
V_195 = V_193 -> V_195 ;
F_22 ( V_195 ) ;
F_22 ( F_135 ( V_195 ) ||
F_137 ( V_195 ) ) ;
if ( F_137 ( V_195 ) )
V_265 = 2 ;
return F_160 ( V_195 -> V_9 ,
V_195 -> V_135 , V_265 ,
V_263 , V_193 ) ;
}
static void F_167 ( struct V_215 * V_216 )
{
F_164 ( V_216 ) ;
}
static struct V_192 *
F_168 ( enum V_211 type )
{
struct V_192 * V_193 ;
F_22 ( F_128 ( type ) ) ;
V_193 = F_169 ( V_266 , V_256 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_148 = V_207 ;
V_193 -> type = type ;
F_33 ( & V_193 -> V_208 ) ;
F_170 ( & V_193 -> V_227 ) ;
F_32 ( & V_193 -> V_70 ) ;
F_30 ( L_28 , V_67 , V_193 ) ;
return V_193 ;
}
static void V_202 ( struct V_70 * V_70 )
{
struct V_192 * V_193 ;
V_193 = F_58 ( V_70 , struct V_192 , V_70 ) ;
F_30 ( L_25 , V_67 , V_193 ) ;
F_22 ( V_193 -> V_195 == NULL ) ;
F_22 ( V_193 -> V_148 == V_207 ) ;
if ( V_193 -> V_216 )
F_167 ( V_193 -> V_216 ) ;
F_22 ( F_128 ( V_193 -> type ) ) ;
switch ( V_193 -> type ) {
case V_212 :
break;
case V_213 :
if ( V_193 -> V_226 )
F_89 ( V_193 -> V_226 ) ;
break;
case V_214 :
if ( V_193 -> V_178 &&
! F_110 ( V_193 ) )
F_171 ( V_193 -> V_178 ,
V_193 -> V_267 ) ;
break;
}
F_172 ( V_266 , V_193 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_174 ( V_9 ) ;
F_175 ( V_9 -> V_268 ) ;
V_9 -> V_268 = NULL ;
V_9 -> V_201 = 0 ;
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
F_107 ( V_9 , L_29 ) ;
}
static bool F_177 ( struct V_8 * V_9 )
{
int V_2 = 0 ;
if ( ! V_9 -> V_268 )
return false ;
F_11 ( & V_9 -> V_270 ) ;
if ( V_9 -> V_201 )
V_2 = F_1 ( & V_9 -> V_269 ) ;
F_12 ( & V_9 -> V_270 ) ;
if ( V_2 < 0 )
F_107 ( V_9 , L_30 ) ;
return V_2 > 0 ;
}
static struct V_203 * F_178 (
struct V_8 * V_9 ,
V_120 V_160 , V_120 V_162 ,
enum V_100 V_101 ,
struct V_118 * V_135 )
{
struct V_203 * V_195 ;
V_195 = F_179 ( V_271 , V_256 ) ;
if ( ! V_195 )
return NULL ;
V_195 -> V_272 = NULL ;
V_195 -> V_9 = V_9 ;
V_195 -> V_160 = V_160 ;
V_195 -> V_162 = V_162 ;
V_195 -> V_41 = 0 ;
if ( V_101 == V_104 ) {
F_136 ( V_195 ) ;
V_195 -> V_135 = V_135 ;
} else if ( V_101 == V_103 ) {
F_134 ( V_195 ) ;
V_195 -> V_135 = V_135 ;
} else {
V_195 -> V_55 = V_9 -> V_54 -> V_55 ;
}
if ( F_177 ( V_9 ) )
F_141 ( V_195 ) ;
F_180 ( & V_195 -> V_273 ) ;
V_195 -> V_274 = 0 ;
V_195 -> V_210 = NULL ;
V_195 -> V_220 = 0 ;
V_195 -> V_206 = 0 ;
F_33 ( & V_195 -> V_209 ) ;
F_32 ( & V_195 -> V_70 ) ;
F_30 ( L_31 , V_67 , V_9 ,
F_53 ( V_101 ) , V_160 , V_162 , V_195 ) ;
return V_195 ;
}
static void V_205 ( struct V_70 * V_70 )
{
struct V_203 * V_195 ;
struct V_192 * V_193 ;
struct V_192 * V_275 ;
V_195 = F_58 ( V_70 , struct V_203 , V_70 ) ;
F_30 ( L_21 , V_67 , V_195 ) ;
F_181 (img_request, obj_request, next_obj_request)
F_127 ( V_195 , V_193 ) ;
F_22 ( V_195 -> V_206 == 0 ) ;
if ( F_143 ( V_195 ) ) {
F_142 ( V_195 ) ;
F_176 ( V_195 -> V_9 ) ;
}
if ( F_135 ( V_195 ) ||
F_137 ( V_195 ) )
F_73 ( V_195 -> V_135 ) ;
F_172 ( V_271 , V_195 ) ;
}
static struct V_203 * F_182 (
struct V_192 * V_193 ,
V_120 V_200 , V_120 V_162 )
{
struct V_203 * V_276 ;
struct V_8 * V_9 ;
F_22 ( V_193 -> V_195 ) ;
V_9 = V_193 -> V_195 -> V_9 ;
V_276 = F_178 ( V_9 -> V_277 , V_200 ,
V_162 , V_102 , NULL ) ;
if ( ! V_276 )
return NULL ;
F_138 ( V_276 ) ;
F_120 ( V_193 ) ;
V_276 -> V_193 = V_193 ;
return V_276 ;
}
static void V_204 ( struct V_70 * V_70 )
{
struct V_203 * V_276 ;
struct V_192 * V_278 ;
V_276 = F_58 ( V_70 , struct V_203 , V_70 ) ;
V_278 = V_276 -> V_193 ;
V_276 -> V_193 = NULL ;
F_122 ( V_278 ) ;
F_139 ( V_276 ) ;
V_205 ( V_70 ) ;
}
static bool F_183 ( struct V_192 * V_193 )
{
struct V_203 * V_195 ;
unsigned int V_221 ;
int V_220 ;
bool V_279 ;
F_22 ( F_110 ( V_193 ) ) ;
V_195 = V_193 -> V_195 ;
F_22 ( V_193 -> V_221 <= ( V_120 ) V_235 ) ;
V_221 = ( unsigned int ) V_193 -> V_221 ;
V_220 = V_193 -> V_220 ;
if ( V_220 ) {
struct V_8 * V_9 = V_195 -> V_9 ;
enum V_100 V_101 ;
if ( F_137 ( V_195 ) )
V_101 = V_104 ;
else if ( F_135 ( V_195 ) )
V_101 = V_103 ;
else
V_101 = V_102 ;
F_107 ( V_9 , L_32 ,
F_53 ( V_101 ) , V_193 -> V_162 ,
V_193 -> V_200 , V_193 -> V_160 ) ;
F_107 ( V_9 , L_33 ,
V_220 , V_221 ) ;
if ( ! V_195 -> V_220 )
V_195 -> V_220 = V_220 ;
V_221 = V_193 -> V_162 ;
}
if ( F_125 ( V_195 ) ) {
F_22 ( V_195 -> V_193 != NULL ) ;
V_279 = V_193 -> V_148 < V_195 -> V_206 - 1 ;
} else {
F_22 ( V_195 -> V_272 != NULL ) ;
V_279 = F_184 ( V_195 -> V_272 , V_220 , V_221 ) ;
if ( ! V_279 )
F_185 ( V_195 -> V_272 , V_220 ) ;
}
return V_279 ;
}
static void V_218 ( struct V_192 * V_193 )
{
struct V_203 * V_195 ;
T_6 V_148 = V_193 -> V_148 ;
bool V_279 = true ;
F_22 ( F_110 ( V_193 ) ) ;
V_195 = V_193 -> V_195 ;
F_30 ( L_34 , V_67 , V_195 , V_193 ) ;
F_22 ( V_195 != NULL ) ;
F_22 ( V_195 -> V_206 > 0 ) ;
F_22 ( V_148 != V_207 ) ;
F_22 ( V_148 < V_195 -> V_206 ) ;
F_17 ( & V_195 -> V_273 ) ;
if ( V_148 != V_195 -> V_274 )
goto V_58;
F_186 (img_request, obj_request) {
F_22 ( V_279 ) ;
F_22 ( V_148 < V_195 -> V_206 ) ;
if ( ! F_113 ( V_193 ) )
break;
V_279 = F_183 ( V_193 ) ;
V_148 ++ ;
}
F_22 ( V_279 ^ ( V_148 == V_195 -> V_206 ) ) ;
V_195 -> V_274 = V_148 ;
V_58:
F_19 ( & V_195 -> V_273 ) ;
F_124 ( V_195 ) ;
if ( ! V_279 )
F_132 ( V_195 ) ;
}
static void F_187 ( struct V_192 * V_193 ,
struct V_215 * V_280 ,
enum V_100 V_101 ,
unsigned int V_249 )
{
struct V_203 * V_195 = V_193 -> V_195 ;
struct V_8 * V_9 = V_195 -> V_9 ;
V_120 V_128 = F_66 ( & V_9 -> V_123 ) ;
V_120 V_160 = V_193 -> V_160 ;
V_120 V_162 = V_193 -> V_162 ;
V_120 V_281 ;
T_9 V_231 ;
if ( V_101 == V_104 ) {
if ( ! V_160 && V_162 == V_128 &&
( ! F_143 ( V_195 ) ||
! F_118 ( V_193 ) ) ) {
V_231 = V_242 ;
} else if ( ( V_160 + V_162 == V_128 ) ) {
V_231 = V_243 ;
} else {
F_11 ( & V_9 -> V_270 ) ;
V_281 = V_9 -> V_123 . V_146 ;
F_12 ( & V_9 -> V_270 ) ;
if ( V_193 -> V_200 + V_162 == V_281 )
V_231 = V_243 ;
else
V_231 = V_244 ;
}
} else if ( V_101 == V_103 ) {
if ( ! V_160 && V_162 == V_128 )
V_231 = V_240 ;
else
V_231 = V_239 ;
F_188 ( V_280 , V_249 ,
V_128 , V_128 ) ;
V_249 ++ ;
} else {
V_231 = V_237 ;
}
if ( V_231 == V_242 )
F_189 ( V_280 , V_249 , V_231 , 0 ) ;
else
F_190 ( V_280 , V_249 , V_231 ,
V_160 , V_162 , 0 , 0 ) ;
if ( V_193 -> type == V_213 )
F_191 ( V_280 , V_249 ,
V_193 -> V_226 , V_162 ) ;
else if ( V_193 -> type == V_214 )
F_192 ( V_280 , V_249 ,
V_193 -> V_178 , V_162 ,
V_160 & ~ V_183 , false , false ) ;
if ( V_101 == V_103 || V_101 == V_104 )
F_158 ( V_193 ) ;
else
F_157 ( V_193 ) ;
}
static int F_193 ( struct V_203 * V_195 ,
enum V_211 type ,
void * V_282 )
{
struct V_8 * V_9 = V_195 -> V_9 ;
struct V_192 * V_193 = NULL ;
struct V_192 * V_275 ;
struct V_164 * V_226 = NULL ;
unsigned int V_283 = 0 ;
struct V_177 * * V_178 = NULL ;
enum V_100 V_101 ;
V_120 V_200 ;
V_120 V_284 ;
F_30 ( L_35 , V_67 , V_195 ,
( int ) type , V_282 ) ;
V_200 = V_195 -> V_160 ;
V_284 = V_195 -> V_162 ;
F_22 ( V_284 > 0 ) ;
V_101 = F_144 ( V_195 ) ;
if ( type == V_213 ) {
V_226 = V_282 ;
F_22 ( V_200 ==
V_226 -> V_188 . V_285 << V_116 ) ;
} else if ( type == V_214 ) {
V_178 = V_282 ;
}
while ( V_284 ) {
struct V_215 * V_216 ;
V_120 V_217 = V_200 >> V_9 -> V_123 . V_124 ;
V_120 V_160 = F_87 ( V_9 , V_200 ) ;
V_120 V_162 = F_88 ( V_9 , V_200 , V_284 ) ;
V_193 = F_168 ( type ) ;
if ( ! V_193 )
goto V_286;
V_193 -> V_217 = V_217 ;
V_193 -> V_160 = V_160 ;
V_193 -> V_162 = V_162 ;
F_126 ( V_195 , V_193 ) ;
if ( type == V_213 ) {
unsigned int V_287 ;
F_22 ( V_162 <= ( V_120 ) V_235 ) ;
V_287 = ( unsigned int ) V_162 ;
V_193 -> V_226 =
F_106 ( & V_226 ,
& V_283 ,
V_287 ,
V_256 ) ;
if ( ! V_193 -> V_226 )
goto V_286;
} else if ( type == V_214 ) {
unsigned int V_267 ;
V_193 -> V_178 = V_178 ;
V_267 = ( T_6 ) F_194 ( V_160 , V_162 ) ;
V_193 -> V_267 = V_267 ;
if ( ( V_160 + V_162 ) & ~ V_183 )
V_267 -- ;
V_178 += V_267 ;
}
V_216 = F_165 ( V_9 , V_101 ,
( V_101 == V_103 ) ? 2 : 1 ,
V_193 ) ;
if ( ! V_216 )
goto V_286;
V_193 -> V_216 = V_216 ;
V_193 -> V_210 = V_218 ;
V_193 -> V_200 = V_200 ;
F_187 ( V_193 , V_216 , V_101 , 0 ) ;
V_200 += V_162 ;
V_284 -= V_162 ;
}
return 0 ;
V_286:
F_181 (img_request, obj_request, next_obj_request)
F_127 ( V_195 , V_193 ) ;
return - V_66 ;
}
static void
F_155 ( struct V_192 * V_193 )
{
struct V_203 * V_195 ;
struct V_8 * V_9 ;
struct V_177 * * V_178 ;
T_6 V_267 ;
F_30 ( L_25 , V_67 , V_193 ) ;
F_22 ( V_193 -> type == V_213 ||
V_193 -> type == V_212 ) ;
F_22 ( F_110 ( V_193 ) ) ;
V_195 = V_193 -> V_195 ;
F_22 ( V_195 ) ;
V_9 = V_195 -> V_9 ;
F_22 ( V_9 ) ;
V_178 = V_193 -> V_288 ;
F_22 ( V_178 != NULL ) ;
V_193 -> V_288 = NULL ;
V_267 = V_193 -> V_289 ;
F_22 ( V_267 ) ;
V_193 -> V_289 = 0 ;
F_171 ( V_178 , V_267 ) ;
if ( ! V_193 -> V_220 )
V_193 -> V_221 = V_193 -> V_162 ;
F_112 ( V_193 ) ;
}
static void
F_195 ( struct V_203 * V_195 )
{
struct V_192 * V_278 ;
struct V_215 * V_216 ;
struct V_8 * V_9 ;
struct V_177 * * V_178 ;
enum V_100 V_101 ;
T_6 V_267 ;
int V_290 ;
V_120 V_291 ;
F_22 ( F_125 ( V_195 ) ) ;
V_178 = V_195 -> V_288 ;
F_22 ( V_178 != NULL ) ;
V_195 -> V_288 = NULL ;
V_267 = V_195 -> V_289 ;
F_22 ( V_267 ) ;
V_195 -> V_289 = 0 ;
V_278 = V_195 -> V_193 ;
F_22 ( V_278 != NULL ) ;
F_22 ( F_128 ( V_278 -> type ) ) ;
V_290 = V_195 -> V_220 ;
V_291 = V_195 -> V_162 ;
F_22 ( V_290 || V_291 == V_195 -> V_221 ) ;
F_124 ( V_195 ) ;
F_22 ( V_278 -> V_195 ) ;
V_9 = V_278 -> V_195 -> V_9 ;
F_22 ( V_9 ) ;
if ( ! V_9 -> V_201 ) {
F_171 ( V_178 , V_267 ) ;
F_129 ( V_278 ) ;
return;
}
if ( V_290 )
goto V_139;
V_290 = - V_66 ;
V_216 = F_166 ( V_278 ) ;
if ( ! V_216 )
goto V_139;
F_167 ( V_278 -> V_216 ) ;
V_278 -> V_216 = V_216 ;
V_278 -> V_288 = V_178 ;
V_278 -> V_289 = V_267 ;
F_196 ( V_216 , 0 , V_245 , L_36 , L_37 ) ;
F_197 ( V_216 , 0 , V_178 , V_291 , 0 ,
false , false ) ;
V_101 = F_144 ( V_278 -> V_195 ) ;
F_187 ( V_278 , V_216 , V_101 , 1 ) ;
F_129 ( V_278 ) ;
return;
V_139:
F_171 ( V_178 , V_267 ) ;
F_148 ( V_278 , V_290 ) ;
}
static int F_198 ( struct V_192 * V_193 )
{
struct V_8 * V_9 = V_193 -> V_195 -> V_9 ;
struct V_203 * V_276 = NULL ;
V_120 V_200 ;
V_120 V_162 ;
struct V_177 * * V_178 = NULL ;
T_6 V_267 ;
int V_220 ;
F_22 ( V_9 -> V_277 != NULL ) ;
V_200 = V_193 -> V_200 - V_193 -> V_160 ;
V_162 = F_66 ( & V_9 -> V_123 ) ;
if ( V_200 + V_162 > V_9 -> V_201 ) {
F_22 ( V_200 < V_9 -> V_201 ) ;
V_162 = V_9 -> V_201 - V_200 ;
}
V_267 = ( T_6 ) F_194 ( 0 , V_162 ) ;
V_178 = F_199 ( V_267 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_220 = F_200 ( V_178 ) ;
V_178 = NULL ;
goto V_139;
}
V_220 = - V_66 ;
V_276 = F_182 ( V_193 ,
V_200 , V_162 ) ;
if ( ! V_276 )
goto V_139;
V_220 = F_193 ( V_276 , V_214 , V_178 ) ;
if ( V_220 )
goto V_139;
V_276 -> V_288 = V_178 ;
V_276 -> V_289 = V_267 ;
V_276 -> V_210 = F_195 ;
V_220 = F_201 ( V_276 ) ;
if ( ! V_220 )
return 0 ;
V_276 -> V_288 = NULL ;
V_276 -> V_289 = 0 ;
V_276 -> V_193 = NULL ;
F_122 ( V_193 ) ;
V_139:
if ( V_178 )
F_171 ( V_178 , V_267 ) ;
if ( V_276 )
F_124 ( V_276 ) ;
return V_220 ;
}
static void F_202 ( struct V_192 * V_193 )
{
struct V_192 * V_278 ;
struct V_8 * V_9 ;
int V_220 ;
F_22 ( ! F_110 ( V_193 ) ) ;
V_278 = V_193 -> V_193 ;
V_193 -> V_193 = NULL ;
F_122 ( V_278 ) ;
F_22 ( V_278 ) ;
F_22 ( V_278 -> V_195 ) ;
V_220 = V_193 -> V_220 ;
V_193 -> V_220 = 0 ;
F_30 ( L_38 , V_67 ,
V_193 , V_278 , V_220 ,
V_193 -> V_221 , V_193 -> V_162 ) ;
F_122 ( V_193 ) ;
V_9 = V_278 -> V_195 -> V_9 ;
if ( ! V_9 -> V_201 ) {
F_129 ( V_278 ) ;
return;
}
if ( ! V_220 ) {
F_114 ( V_278 , true ) ;
} else if ( V_220 == - V_43 ) {
F_114 ( V_278 , false ) ;
} else {
goto V_292;
}
V_220 = F_203 ( V_278 ) ;
if ( V_220 )
goto V_292;
return;
V_292:
F_148 ( V_278 , V_220 ) ;
}
static int F_204 ( struct V_192 * V_193 )
{
struct V_8 * V_9 = V_193 -> V_195 -> V_9 ;
struct V_192 * V_293 ;
struct V_177 * * V_178 ;
T_6 V_267 ;
T_7 V_110 ;
int V_48 ;
V_293 = F_168 ( V_214 ) ;
if ( ! V_293 )
return - V_66 ;
V_293 -> V_217 = V_193 -> V_217 ;
V_293 -> V_216 = F_165 ( V_9 , V_102 , 1 ,
V_293 ) ;
if ( ! V_293 -> V_216 ) {
V_48 = - V_66 ;
goto V_294;
}
V_110 = sizeof ( V_119 ) + sizeof ( V_295 ) + sizeof ( V_295 ) ;
V_267 = ( T_6 ) F_194 ( 0 , V_110 ) ;
V_178 = F_199 ( V_267 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_48 = F_200 ( V_178 ) ;
goto V_294;
}
F_189 ( V_293 -> V_216 , 0 , V_241 , 0 ) ;
F_205 ( V_293 -> V_216 , 0 , V_178 , V_110 , 0 ,
false , false ) ;
F_120 ( V_193 ) ;
V_293 -> V_193 = V_193 ;
V_293 -> V_178 = V_178 ;
V_293 -> V_267 = V_267 ;
V_293 -> V_210 = F_202 ;
F_129 ( V_293 ) ;
return 0 ;
V_294:
F_122 ( V_293 ) ;
return V_48 ;
}
static bool F_206 ( struct V_192 * V_193 )
{
struct V_203 * V_195 = V_193 -> V_195 ;
struct V_8 * V_9 = V_195 -> V_9 ;
if ( ! F_135 ( V_195 ) &&
! F_137 ( V_195 ) )
return true ;
if ( ! F_143 ( V_195 ) )
return true ;
if ( ! F_118 ( V_193 ) )
return true ;
if ( ! V_193 -> V_160 &&
V_193 -> V_162 == F_66 ( & V_9 -> V_123 ) )
return true ;
if ( F_116 ( V_193 ) &&
F_117 ( V_193 ) )
return true ;
return false ;
}
static int F_203 ( struct V_192 * V_193 )
{
F_22 ( F_110 ( V_193 ) ) ;
F_22 ( F_128 ( V_193 -> type ) ) ;
F_22 ( V_193 -> V_195 ) ;
if ( F_206 ( V_193 ) ) {
F_129 ( V_193 ) ;
return 0 ;
}
if ( F_116 ( V_193 ) )
return F_198 ( V_193 ) ;
return F_204 ( V_193 ) ;
}
static int F_201 ( struct V_203 * V_195 )
{
struct V_192 * V_193 ;
struct V_192 * V_275 ;
int V_48 = 0 ;
F_30 ( L_21 , V_67 , V_195 ) ;
F_123 ( V_195 ) ;
F_181 (img_request, obj_request, next_obj_request) {
V_48 = F_203 ( V_193 ) ;
if ( V_48 )
goto V_296;
}
V_296:
F_124 ( V_195 ) ;
return V_48 ;
}
static void F_207 ( struct V_203 * V_195 )
{
struct V_192 * V_193 ;
struct V_8 * V_9 ;
V_120 V_297 ;
V_120 V_298 ;
int V_290 ;
F_22 ( F_125 ( V_195 ) ) ;
V_193 = V_195 -> V_193 ;
V_298 = V_195 -> V_221 ;
V_290 = V_195 -> V_220 ;
F_124 ( V_195 ) ;
F_22 ( V_193 ) ;
F_22 ( V_193 -> V_195 ) ;
V_9 = V_193 -> V_195 -> V_9 ;
if ( ! V_9 -> V_201 ) {
F_129 ( V_193 ) ;
return;
}
V_193 -> V_220 = V_290 ;
if ( V_193 -> V_220 )
goto V_58;
F_22 ( V_193 -> V_200 < V_163 - V_193 -> V_162 ) ;
V_297 = V_193 -> V_200 + V_193 -> V_162 ;
if ( V_297 > V_9 -> V_201 ) {
V_120 V_221 = 0 ;
if ( V_193 -> V_200 < V_9 -> V_201 )
V_221 = V_9 -> V_201 -
V_193 -> V_200 ;
V_193 -> V_221 = F_208 ( V_298 , V_221 ) ;
} else {
V_193 -> V_221 = V_298 ;
}
V_58:
F_145 ( V_193 ) ;
F_146 ( V_193 ) ;
}
static void F_150 ( struct V_192 * V_193 )
{
struct V_203 * V_195 ;
int V_220 ;
F_22 ( F_110 ( V_193 ) ) ;
F_22 ( V_193 -> V_195 != NULL ) ;
F_22 ( V_193 -> V_220 == ( V_299 ) - V_43 ) ;
F_22 ( F_128 ( V_193 -> type ) ) ;
V_195 = F_182 ( V_193 ,
V_193 -> V_200 ,
V_193 -> V_162 ) ;
V_220 = - V_66 ;
if ( ! V_195 )
goto V_139;
if ( V_193 -> type == V_213 )
V_220 = F_193 ( V_195 , V_213 ,
V_193 -> V_226 ) ;
else
V_220 = F_193 ( V_195 , V_214 ,
V_193 -> V_178 ) ;
if ( V_220 )
goto V_139;
V_195 -> V_210 = F_207 ;
V_220 = F_201 ( V_195 ) ;
if ( V_220 )
goto V_139;
return;
V_139:
if ( V_195 )
F_124 ( V_195 ) ;
V_193 -> V_220 = V_220 ;
V_193 -> V_221 = 0 ;
F_112 ( V_193 ) ;
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
V_305 . V_303 = F_212 ( V_9 -> V_62 -> V_72 ) ;
V_305 . V_304 = V_9 -> V_307 ;
F_56 ( & V_9 -> V_306 ) ;
return V_305 ;
}
static void F_213 ( struct V_8 * V_9 ,
const struct V_300 * V_305 )
{
F_30 ( L_39 , V_67 , V_9 ,
V_9 -> V_308 . V_303 , V_9 -> V_308 . V_304 ,
V_305 -> V_303 , V_305 -> V_304 ) ;
V_9 -> V_308 = * V_305 ;
}
static void F_214 ( struct V_8 * V_9 , char * V_17 )
{
F_211 ( & V_9 -> V_306 ) ;
sprintf ( V_17 , L_40 , V_309 , V_9 -> V_307 ) ;
F_56 ( & V_9 -> V_306 ) ;
}
static int F_215 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_300 V_305 = F_210 ( V_9 ) ;
char V_310 [ 32 ] ;
int V_48 ;
F_130 ( F_9 ( V_9 ) ||
V_9 -> V_311 [ 0 ] != '\0' ) ;
F_214 ( V_9 , V_310 ) ;
V_48 = F_216 ( V_251 , & V_9 -> V_312 , & V_9 -> V_313 ,
V_314 , V_315 , V_310 ,
V_316 , L_41 , 0 ) ;
if ( V_48 )
return V_48 ;
V_9 -> V_10 = V_11 ;
strcpy ( V_9 -> V_311 , V_310 ) ;
F_213 ( V_9 , & V_305 ) ;
F_217 ( V_9 -> V_317 , & V_9 -> V_318 ) ;
return 0 ;
}
static void F_218 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
int V_48 ;
F_130 ( ! F_9 ( V_9 ) ||
V_9 -> V_311 [ 0 ] == '\0' ) ;
V_48 = F_219 ( V_251 , & V_9 -> V_312 , & V_9 -> V_313 ,
V_314 , V_9 -> V_311 ) ;
if ( V_48 && V_48 != - V_43 )
F_107 ( V_9 , L_42 , V_48 ) ;
V_9 -> V_10 = V_319 ;
V_9 -> V_311 [ 0 ] = '\0' ;
F_213 ( V_9 , & V_320 ) ;
F_217 ( V_9 -> V_317 , & V_9 -> V_321 ) ;
}
static int F_220 ( struct V_8 * V_9 ,
enum V_322 V_323 ,
struct V_177 * * * V_324 ,
T_7 * V_325 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_300 V_305 = F_210 ( V_9 ) ;
int V_326 = 4 + 8 + 8 + V_327 ;
char V_17 [ V_326 ] ;
void * V_328 = V_17 ;
F_30 ( L_43 , V_67 , V_9 , V_323 ) ;
F_221 ( & V_328 , 2 , 1 , V_326 - V_327 ) ;
F_222 ( & V_328 , V_323 ) ;
F_223 ( & V_328 , V_305 . V_303 ) ;
F_223 ( & V_328 , V_305 . V_304 ) ;
return F_224 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_17 , V_326 ,
V_329 , V_324 , V_325 ) ;
}
static void F_225 ( struct V_8 * V_9 ,
enum V_322 V_323 )
{
struct V_177 * * V_330 ;
T_7 V_331 ;
F_220 ( V_9 , V_323 , & V_330 , & V_331 ) ;
F_171 ( V_330 , F_194 ( 0 , V_331 ) ) ;
}
static void F_226 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_318 ) ;
F_225 ( V_9 , V_334 ) ;
}
static void F_227 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_321 ) ;
F_225 ( V_9 , V_335 ) ;
}
static int F_228 ( struct V_8 * V_9 )
{
struct V_177 * * V_330 ;
T_7 V_331 ;
bool V_336 = false ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_220 ( V_9 , V_337 ,
& V_330 , & V_331 ) ;
if ( V_48 && V_48 != - V_338 ) {
F_107 ( V_9 , L_45 , V_48 ) ;
goto V_58;
}
if ( V_331 > 0 && V_331 <= V_184 ) {
void * V_328 = F_229 ( V_330 [ 0 ] ) ;
void * const V_179 = V_328 + V_331 ;
T_6 V_339 ;
F_230 ( & V_328 , V_179 , V_339 , V_340 ) ;
while ( V_339 -- ) {
T_10 V_341 ;
T_6 V_186 ;
F_231 ( & V_328 , V_179 , 8 + 8 , V_340 ) ;
V_328 += 8 + 8 ;
F_230 ( & V_328 , V_179 , V_186 , V_340 ) ;
if ( ! V_186 )
continue;
if ( V_336 ) {
F_107 ( V_9 ,
L_46 ) ;
V_48 = - V_147 ;
goto V_58;
}
V_336 = true ;
V_48 = F_232 ( & V_328 , V_179 , 1 , L_47 ,
& V_341 , & V_186 ) ;
if ( V_48 ) {
F_107 ( V_9 ,
L_48 ,
V_48 ) ;
goto V_340;
}
V_48 = F_233 ( & V_328 ) ;
}
}
if ( ! V_336 ) {
F_107 ( V_9 , L_49 ) ;
V_48 = - V_338 ;
}
V_58:
F_171 ( V_330 , F_194 ( 0 , V_331 ) ) ;
return V_48 ;
V_340:
V_48 = - V_4 ;
goto V_58;
}
static void F_234 ( struct V_8 * V_9 , bool V_342 )
{
F_30 ( L_50 , V_67 , V_9 , V_342 ) ;
F_235 ( & V_9 -> V_343 ) ;
if ( V_342 )
F_236 ( & V_9 -> V_344 ) ;
else
F_237 ( & V_9 -> V_344 ) ;
}
static int F_238 ( struct V_8 * V_9 ,
struct V_345 * * V_346 , T_6 * V_347 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
T_10 V_348 ;
char * V_349 ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_239 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_314 ,
& V_348 , & V_349 , V_346 , V_347 ) ;
if ( V_48 )
return V_48 ;
if ( * V_347 == 0 ) {
F_30 ( L_51 , V_67 , V_9 ) ;
goto V_58;
}
if ( strcmp ( V_349 , V_316 ) ) {
F_107 ( V_9 , L_52 ,
V_349 ) ;
V_48 = - V_57 ;
goto V_58;
}
if ( V_348 == V_350 ) {
F_107 ( V_9 , L_53 ) ;
V_48 = - V_57 ;
goto V_58;
}
if ( strncmp ( ( * V_346 ) [ 0 ] . V_145 . V_310 , V_309 ,
strlen ( V_309 ) ) ) {
F_107 ( V_9 , L_54 ,
( * V_346 ) [ 0 ] . V_145 . V_310 ) ;
V_48 = - V_57 ;
goto V_58;
}
V_58:
F_41 ( V_349 ) ;
return V_48 ;
}
static int F_240 ( struct V_8 * V_9 ,
const struct V_345 * V_351 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_352 * V_353 ;
T_6 V_354 ;
V_120 V_310 ;
int V_138 ;
int V_48 ;
V_48 = F_241 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , & V_353 ,
& V_354 ) ;
if ( V_48 )
return V_48 ;
sscanf ( V_351 -> V_145 . V_310 , V_309 L_55 , & V_310 ) ;
for ( V_138 = 0 ; V_138 < V_354 ; V_138 ++ ) {
if ( ! memcmp ( & V_353 [ V_138 ] . V_355 , & V_351 -> V_356 . V_355 ,
sizeof( V_351 -> V_356 . V_355 ) ) &&
V_353 [ V_138 ] . V_310 == V_310 ) {
struct V_300 V_305 = {
. V_303 = F_65 ( V_353 [ V_138 ] . V_357 . V_358 ) ,
. V_304 = V_310 ,
} ;
F_30 ( L_56 , V_67 ,
V_9 , V_305 . V_303 , V_305 . V_304 ) ;
F_213 ( V_9 , & V_305 ) ;
V_48 = 1 ;
goto V_58;
}
}
F_30 ( L_57 , V_67 , V_9 ) ;
V_48 = 0 ;
V_58:
F_41 ( V_353 ) ;
return V_48 ;
}
static int F_242 ( struct V_8 * V_9 )
{
struct V_359 * V_72 = V_9 -> V_62 -> V_72 ;
struct V_345 * V_346 ;
T_6 V_347 ;
int V_48 ;
for (; ; ) {
V_48 = F_215 ( V_9 ) ;
if ( V_48 != - V_57 )
return V_48 ;
V_48 = F_238 ( V_9 , & V_346 , & V_347 ) ;
if ( V_48 )
return V_48 ;
if ( V_347 == 0 )
goto V_360;
V_48 = F_240 ( V_9 , V_346 ) ;
if ( V_48 ) {
if ( V_48 > 0 )
V_48 = 0 ;
goto V_58;
}
F_107 ( V_9 , L_58 ,
F_243 ( V_346 [ 0 ] . V_145 . V_357 ) ) ;
V_48 = F_244 ( & V_72 -> V_361 ,
& V_346 [ 0 ] . V_356 . V_355 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_59 ,
F_243 ( V_346 [ 0 ] . V_145 . V_357 ) , V_48 ) ;
goto V_58;
}
V_48 = F_245 ( & V_72 -> V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_314 ,
V_346 [ 0 ] . V_145 . V_310 ,
& V_346 [ 0 ] . V_145 . V_357 ) ;
if ( V_48 && V_48 != - V_43 )
goto V_58;
V_360:
F_246 ( V_346 , V_347 ) ;
}
V_58:
F_246 ( V_346 , V_347 ) ;
return V_48 ;
}
static enum V_362 F_247 ( struct V_8 * V_9 ,
int * V_363 )
{
enum V_362 V_10 ;
F_11 ( & V_9 -> V_14 ) ;
F_30 ( L_60 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( F_9 ( V_9 ) ) {
V_10 = V_9 -> V_10 ;
F_12 ( & V_9 -> V_14 ) ;
return V_10 ;
}
F_12 ( & V_9 -> V_14 ) ;
F_248 ( & V_9 -> V_14 ) ;
F_30 ( L_61 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( ! F_9 ( V_9 ) ) {
* V_363 = F_242 ( V_9 ) ;
if ( * V_363 )
F_107 ( V_9 , L_62 , * V_363 ) ;
}
V_10 = V_9 -> V_10 ;
F_249 ( & V_9 -> V_14 ) ;
return V_10 ;
}
static void F_250 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( F_251 ( V_333 ) ,
struct V_8 , V_343 ) ;
enum V_362 V_10 ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_360:
V_10 = F_247 ( V_9 , & V_48 ) ;
if ( V_10 != V_319 || V_48 == - V_364 ) {
if ( V_10 == V_11 )
F_234 ( V_9 , true ) ;
F_30 ( L_63 , V_67 ,
V_9 , V_10 , V_48 ) ;
return;
}
V_48 = F_228 ( V_9 ) ;
if ( V_48 == - V_338 ) {
goto V_360;
} else if ( V_48 == - V_38 ) {
F_107 ( V_9 , L_64 ) ;
if ( ! ( V_9 -> V_45 -> V_41 & V_365 ) ) {
F_115 ( V_366 , & V_9 -> V_41 ) ;
F_234 ( V_9 , false ) ;
}
} else if ( V_48 < 0 ) {
F_107 ( V_9 , L_65 , V_48 ) ;
F_252 ( V_9 -> V_317 , & V_9 -> V_343 ,
V_367 ) ;
} else {
F_30 ( L_66 , V_67 ,
V_9 ) ;
F_252 ( V_9 -> V_317 , & V_9 -> V_343 ,
F_253 ( 2 * V_329 * V_368 ) ) ;
}
}
static bool F_254 ( struct V_8 * V_9 )
{
F_30 ( L_60 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( V_9 -> V_10 != V_11 )
return false ;
V_9 -> V_10 = V_12 ;
F_255 ( & V_9 -> V_14 ) ;
F_256 ( & V_9 -> V_62 -> V_72 -> V_251 ) ;
F_12 ( & V_9 -> V_14 ) ;
F_248 ( & V_9 -> V_14 ) ;
F_30 ( L_61 , V_67 , V_9 ,
V_9 -> V_10 ) ;
if ( V_9 -> V_10 != V_12 )
return false ;
F_218 ( V_9 ) ;
F_235 ( & V_9 -> V_343 ) ;
return true ;
}
static void F_257 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( V_333 , struct V_8 ,
V_369 ) ;
F_248 ( & V_9 -> V_14 ) ;
F_254 ( V_9 ) ;
F_249 ( & V_9 -> V_14 ) ;
}
static void F_258 ( struct V_8 * V_9 , T_10 V_341 ,
void * * V_328 )
{
struct V_300 V_305 = { 0 } ;
if ( V_341 >= 2 ) {
V_305 . V_303 = F_259 ( V_328 ) ;
V_305 . V_304 = F_259 ( V_328 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( ! F_209 ( & V_305 , & V_320 ) ) {
F_248 ( & V_9 -> V_14 ) ;
if ( F_209 ( & V_305 , & V_9 -> V_308 ) ) {
F_249 ( & V_9 -> V_14 ) ;
return;
}
F_213 ( V_9 , & V_305 ) ;
F_255 ( & V_9 -> V_14 ) ;
} else {
F_11 ( & V_9 -> V_14 ) ;
}
if ( ! F_9 ( V_9 ) )
F_234 ( V_9 , false ) ;
F_12 ( & V_9 -> V_14 ) ;
}
static void F_260 ( struct V_8 * V_9 , T_10 V_341 ,
void * * V_328 )
{
struct V_300 V_305 = { 0 } ;
if ( V_341 >= 2 ) {
V_305 . V_303 = F_259 ( V_328 ) ;
V_305 . V_304 = F_259 ( V_328 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( ! F_209 ( & V_305 , & V_320 ) ) {
F_248 ( & V_9 -> V_14 ) ;
if ( ! F_209 ( & V_305 , & V_9 -> V_308 ) ) {
F_30 ( L_68 ,
V_67 , V_9 , V_305 . V_303 , V_305 . V_304 ,
V_9 -> V_308 . V_303 , V_9 -> V_308 . V_304 ) ;
F_249 ( & V_9 -> V_14 ) ;
return;
}
F_213 ( V_9 , & V_320 ) ;
F_255 ( & V_9 -> V_14 ) ;
} else {
F_11 ( & V_9 -> V_14 ) ;
}
if ( ! F_9 ( V_9 ) )
F_234 ( V_9 , false ) ;
F_12 ( & V_9 -> V_14 ) ;
}
static int F_261 ( struct V_8 * V_9 , T_10 V_341 ,
void * * V_328 )
{
struct V_300 V_370 = F_210 ( V_9 ) ;
struct V_300 V_305 = { 0 } ;
int V_220 = 1 ;
if ( V_341 >= 2 ) {
V_305 . V_303 = F_259 ( V_328 ) ;
V_305 . V_304 = F_259 ( V_328 ) ;
}
F_30 ( L_67 , V_67 , V_9 , V_305 . V_303 ,
V_305 . V_304 ) ;
if ( F_209 ( & V_305 , & V_370 ) )
return V_220 ;
F_11 ( & V_9 -> V_14 ) ;
if ( F_9 ( V_9 ) ) {
if ( V_9 -> V_10 == V_11 &&
F_209 ( & V_9 -> V_308 , & V_320 ) )
goto V_371;
V_220 = 0 ;
if ( V_9 -> V_10 == V_11 ) {
if ( ! V_9 -> V_372 -> V_99 ) {
F_30 ( L_69 ,
V_67 , V_9 ) ;
F_217 ( V_9 -> V_317 ,
& V_9 -> V_369 ) ;
} else {
V_220 = - V_38 ;
}
}
}
V_371:
F_12 ( & V_9 -> V_14 ) ;
return V_220 ;
}
static void F_262 ( struct V_8 * V_9 ,
V_120 V_373 , V_120 V_310 , V_299 * V_220 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
int V_326 = 4 + V_327 ;
char V_17 [ V_326 ] ;
int V_48 ;
if ( V_220 ) {
void * V_328 = V_17 ;
F_221 ( & V_328 , 1 , 1 ,
V_326 - V_327 ) ;
F_222 ( & V_328 , * V_220 ) ;
} else {
V_326 = 0 ;
}
V_48 = F_263 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_373 , V_310 ,
V_17 , V_326 ) ;
if ( V_48 )
F_107 ( V_9 , L_70 , V_48 ) ;
}
static void F_264 ( struct V_8 * V_9 , V_120 V_373 ,
V_120 V_310 )
{
F_30 ( L_44 , V_67 , V_9 ) ;
F_262 ( V_9 , V_373 , V_310 , NULL ) ;
}
static void F_265 ( struct V_8 * V_9 ,
V_120 V_373 , V_120 V_310 , V_299 V_220 )
{
F_30 ( L_71 , V_67 , V_9 , V_220 ) ;
F_262 ( V_9 , V_373 , V_310 , & V_220 ) ;
}
static void F_266 ( void * V_47 , V_120 V_373 , V_120 V_310 ,
V_120 V_374 , void * V_375 , T_7 V_376 )
{
struct V_8 * V_9 = V_47 ;
void * V_328 = V_375 ;
void * const V_179 = V_328 + V_376 ;
T_10 V_341 = 0 ;
T_6 V_186 ;
T_6 V_323 ;
int V_48 ;
F_30 ( L_72 ,
V_67 , V_9 , V_310 , V_373 , V_376 ) ;
if ( V_376 ) {
V_48 = F_232 ( & V_328 , V_179 , 1 , L_73 ,
& V_341 , & V_186 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_74 ,
V_48 ) ;
return;
}
V_323 = F_233 ( & V_328 ) ;
} else {
V_323 = V_377 ;
V_186 = 0 ;
}
F_30 ( L_75 , V_67 , V_9 , V_323 ) ;
switch ( V_323 ) {
case V_334 :
F_258 ( V_9 , V_341 , & V_328 ) ;
F_264 ( V_9 , V_373 , V_310 ) ;
break;
case V_335 :
F_260 ( V_9 , V_341 , & V_328 ) ;
F_264 ( V_9 , V_373 , V_310 ) ;
break;
case V_337 :
V_48 = F_261 ( V_9 , V_341 , & V_328 ) ;
if ( V_48 <= 0 )
F_265 ( V_9 , V_373 ,
V_310 , V_48 ) ;
else
F_264 ( V_9 , V_373 , V_310 ) ;
break;
case V_377 :
V_48 = F_267 ( V_9 ) ;
if ( V_48 )
F_107 ( V_9 , L_76 , V_48 ) ;
F_264 ( V_9 , V_373 , V_310 ) ;
break;
default:
if ( F_10 ( V_9 ) )
F_265 ( V_9 , V_373 ,
V_310 , - V_378 ) ;
else
F_264 ( V_9 , V_373 , V_310 ) ;
break;
}
}
static void F_268 ( void * V_47 , V_120 V_310 , int V_228 )
{
struct V_8 * V_9 = V_47 ;
F_107 ( V_9 , L_77 , V_228 ) ;
F_248 ( & V_9 -> V_14 ) ;
F_213 ( V_9 , & V_320 ) ;
F_249 ( & V_9 -> V_14 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_379 == V_380 ) {
F_269 ( V_9 ) ;
V_9 -> V_379 = V_381 ;
F_270 ( V_9 -> V_317 , & V_9 -> V_382 , 0 ) ;
}
F_56 ( & V_9 -> V_306 ) ;
}
static int F_271 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_383 * V_304 ;
F_22 ( ! V_9 -> V_384 ) ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_304 = F_272 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , F_266 ,
F_268 , V_9 ) ;
if ( F_35 ( V_304 ) )
return F_200 ( V_304 ) ;
V_9 -> V_384 = V_304 ;
return 0 ;
}
static void F_269 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
int V_48 ;
F_22 ( V_9 -> V_384 ) ;
F_30 ( L_44 , V_67 , V_9 ) ;
V_48 = F_273 ( V_251 , V_9 -> V_384 ) ;
if ( V_48 )
F_107 ( V_9 , L_78 , V_48 ) ;
V_9 -> V_384 = NULL ;
}
static int F_274 ( struct V_8 * V_9 )
{
int V_48 ;
F_211 ( & V_9 -> V_306 ) ;
F_22 ( V_9 -> V_379 == V_385 ) ;
V_48 = F_271 ( V_9 ) ;
if ( V_48 )
goto V_58;
V_9 -> V_379 = V_380 ;
V_9 -> V_307 = V_9 -> V_384 -> V_386 ;
V_58:
F_56 ( & V_9 -> V_306 ) ;
return V_48 ;
}
static void F_275 ( struct V_8 * V_9 )
{
F_30 ( L_44 , V_67 , V_9 ) ;
F_276 ( & V_9 -> V_382 ) ;
F_277 ( & V_9 -> V_318 ) ;
F_277 ( & V_9 -> V_321 ) ;
F_276 ( & V_9 -> V_343 ) ;
F_277 ( & V_9 -> V_369 ) ;
}
static void F_278 ( struct V_8 * V_9 )
{
F_130 ( F_279 ( & V_9 -> V_344 ) ) ;
F_275 ( V_9 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_379 == V_380 )
F_269 ( V_9 ) ;
V_9 -> V_379 = V_385 ;
F_56 ( & V_9 -> V_306 ) ;
F_280 ( & V_9 -> V_62 -> V_72 -> V_251 ) ;
}
static void F_281 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
char V_310 [ 32 ] ;
int V_48 ;
F_130 ( V_9 -> V_10 != V_11 ) ;
F_214 ( V_9 , V_310 ) ;
V_48 = F_282 ( V_251 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_314 ,
V_315 , V_9 -> V_311 ,
V_316 , V_310 ) ;
if ( V_48 ) {
if ( V_48 != - V_378 )
F_107 ( V_9 , L_79 ,
V_48 ) ;
if ( F_254 ( V_9 ) )
F_270 ( V_9 -> V_317 ,
& V_9 -> V_343 , 0 ) ;
} else {
strcpy ( V_9 -> V_311 , V_310 ) ;
}
}
static void F_283 ( struct V_332 * V_333 )
{
struct V_8 * V_9 = F_58 ( F_251 ( V_333 ) ,
struct V_8 , V_382 ) ;
int V_48 ;
F_30 ( L_44 , V_67 , V_9 ) ;
F_211 ( & V_9 -> V_306 ) ;
if ( V_9 -> V_379 != V_381 ) {
F_56 ( & V_9 -> V_306 ) ;
return;
}
V_48 = F_271 ( V_9 ) ;
if ( V_48 ) {
F_107 ( V_9 , L_80 , V_48 ) ;
if ( V_48 == - V_364 || V_48 == - V_43 ) {
F_115 ( V_366 , & V_9 -> V_41 ) ;
F_234 ( V_9 , true ) ;
} else {
F_270 ( V_9 -> V_317 ,
& V_9 -> V_382 ,
V_367 ) ;
}
F_56 ( & V_9 -> V_306 ) ;
return;
}
V_9 -> V_379 = V_380 ;
V_9 -> V_307 = V_9 -> V_384 -> V_386 ;
F_56 ( & V_9 -> V_306 ) ;
F_248 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_10 == V_11 )
F_281 ( V_9 ) ;
F_249 ( & V_9 -> V_14 ) ;
V_48 = F_267 ( V_9 ) ;
if ( V_48 )
F_107 ( V_9 , L_81 , V_48 ) ;
}
static int F_284 ( struct V_8 * V_9 ,
struct V_387 * V_388 ,
struct V_389 * V_390 ,
const char * V_391 ,
const void * V_392 ,
T_7 V_393 ,
void * V_394 ,
T_7 V_395 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_177 * V_396 = NULL ;
struct V_177 * V_397 ;
int V_48 ;
if ( V_392 ) {
if ( V_393 > V_184 )
return - V_398 ;
V_396 = F_285 ( V_68 ) ;
if ( ! V_396 )
return - V_66 ;
memcpy ( F_229 ( V_396 ) , V_392 , V_393 ) ;
}
V_397 = F_285 ( V_68 ) ;
if ( ! V_397 ) {
if ( V_396 )
F_286 ( V_396 ) ;
return - V_66 ;
}
V_48 = F_287 ( V_251 , V_388 , V_390 , V_399 , V_391 ,
V_264 , V_396 , V_393 ,
V_397 , & V_395 ) ;
if ( ! V_48 ) {
memcpy ( V_394 , F_229 ( V_397 ) , V_395 ) ;
V_48 = V_395 ;
}
if ( V_396 )
F_286 ( V_396 ) ;
F_286 ( V_397 ) ;
return V_48 ;
}
static void F_288 ( struct V_8 * V_9 )
{
F_289 ( V_400 ) ;
do {
F_30 ( L_82 , V_67 , V_9 ) ;
F_270 ( V_9 -> V_317 , & V_9 -> V_343 , 0 ) ;
F_290 ( & V_9 -> V_344 , & V_400 ,
V_401 ) ;
F_12 ( & V_9 -> V_14 ) ;
F_291 () ;
F_11 ( & V_9 -> V_14 ) ;
} while ( V_9 -> V_10 != V_11 &&
! F_18 ( V_366 , & V_9 -> V_41 ) );
F_292 ( & V_9 -> V_344 , & V_400 ) ;
}
static void F_293 ( struct V_332 * V_333 )
{
struct V_402 * V_272 = F_294 ( V_333 ) ;
struct V_8 * V_9 = V_272 -> V_403 -> V_404 ;
struct V_203 * V_195 ;
struct V_118 * V_135 = NULL ;
V_120 V_160 = ( V_120 ) F_295 ( V_272 ) << V_116 ;
V_120 V_162 = F_296 ( V_272 ) ;
enum V_100 V_101 ;
V_120 V_405 ;
bool V_406 ;
int V_220 ;
switch ( F_297 ( V_272 ) ) {
case V_407 :
case V_408 :
V_101 = V_104 ;
break;
case V_409 :
V_101 = V_103 ;
break;
case V_410 :
V_101 = V_102 ;
break;
default:
F_30 ( L_83 , V_67 , F_297 ( V_272 ) ) ;
V_220 = - V_147 ;
goto V_228;
}
if ( ! V_162 ) {
F_30 ( L_84 , V_67 ) ;
V_220 = 0 ;
goto V_411;
}
if ( V_101 != V_102 ) {
if ( V_9 -> V_36 . V_37 ) {
V_220 = - V_38 ;
goto V_411;
}
F_22 ( V_9 -> V_54 -> V_55 == V_56 ) ;
}
if ( ! F_18 ( V_412 , & V_9 -> V_41 ) ) {
F_30 ( L_85 ) ;
F_22 ( V_9 -> V_54 -> V_55 != V_56 ) ;
V_220 = - V_413 ;
goto V_411;
}
if ( V_160 && V_162 > V_163 - V_160 + 1 ) {
F_107 ( V_9 , L_86 , V_160 ,
V_162 ) ;
V_220 = - V_4 ;
goto V_411;
}
F_298 ( V_272 ) ;
F_11 ( & V_9 -> V_270 ) ;
V_405 = V_9 -> V_36 . V_110 ;
if ( V_101 != V_102 ) {
V_135 = V_9 -> V_123 . V_135 ;
F_299 ( V_135 ) ;
}
F_12 ( & V_9 -> V_270 ) ;
if ( V_160 + V_162 > V_405 ) {
F_107 ( V_9 , L_87 , V_160 ,
V_162 , V_405 ) ;
V_220 = - V_147 ;
goto V_411;
}
V_406 =
( V_9 -> V_123 . V_159 & V_414 ) &&
( V_101 != V_102 || V_9 -> V_372 -> V_97 ) ;
if ( V_406 ) {
F_11 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_10 != V_11 &&
! F_18 ( V_366 , & V_9 -> V_41 ) ) {
if ( V_9 -> V_372 -> V_99 ) {
F_107 ( V_9 , L_88 ) ;
V_220 = - V_38 ;
goto V_415;
}
F_288 ( V_9 ) ;
}
if ( F_18 ( V_366 , & V_9 -> V_41 ) ) {
V_220 = - V_364 ;
goto V_415;
}
}
V_195 = F_178 ( V_9 , V_160 , V_162 , V_101 ,
V_135 ) ;
if ( ! V_195 ) {
V_220 = - V_66 ;
goto V_415;
}
V_195 -> V_272 = V_272 ;
V_135 = NULL ;
if ( V_101 == V_104 )
V_220 = F_193 ( V_195 , V_212 ,
NULL ) ;
else
V_220 = F_193 ( V_195 , V_213 ,
V_272 -> V_164 ) ;
if ( V_220 )
goto V_416;
V_220 = F_201 ( V_195 ) ;
if ( V_220 )
goto V_416;
if ( V_406 )
F_12 ( & V_9 -> V_14 ) ;
return;
V_416:
F_124 ( V_195 ) ;
V_415:
if ( V_406 )
F_12 ( & V_9 -> V_14 ) ;
V_411:
if ( V_220 )
F_107 ( V_9 , L_89 ,
F_53 ( V_101 ) , V_162 , V_160 , V_220 ) ;
F_73 ( V_135 ) ;
V_228:
F_300 ( V_272 , V_220 ) ;
}
static int F_301 ( struct V_417 * V_418 ,
const struct V_419 * V_420 )
{
struct V_402 * V_272 = V_420 -> V_272 ;
struct V_332 * V_333 = F_302 ( V_272 ) ;
F_217 ( V_421 , V_333 ) ;
return V_422 ;
}
static void F_303 ( struct V_8 * V_9 )
{
F_304 ( V_9 -> V_45 -> V_423 ) ;
F_305 ( & V_9 -> V_424 ) ;
F_306 ( V_9 -> V_45 ) ;
V_9 -> V_45 = NULL ;
}
static int F_307 ( struct V_8 * V_9 ,
struct V_387 * V_388 ,
struct V_389 * V_390 ,
void * V_17 , int V_425 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_215 * V_252 ;
struct V_177 * * V_178 ;
int V_426 = F_194 ( 0 , V_425 ) ;
int V_48 ;
V_252 = F_161 ( V_251 , NULL , 1 , false , V_68 ) ;
if ( ! V_252 )
return - V_66 ;
F_308 ( & V_252 -> V_261 , V_388 ) ;
F_309 ( & V_252 -> V_259 , V_390 ) ;
V_252 -> V_257 = V_264 ;
V_48 = F_163 ( V_252 , V_68 ) ;
if ( V_48 )
goto V_427;
V_178 = F_199 ( V_426 , V_68 ) ;
if ( F_35 ( V_178 ) ) {
V_48 = F_200 ( V_178 ) ;
goto V_427;
}
F_190 ( V_252 , 0 , V_237 , 0 , V_425 , 0 , 0 ) ;
F_192 ( V_252 , 0 , V_178 , V_425 , 0 , false ,
true ) ;
F_131 ( V_251 , V_252 , false ) ;
V_48 = F_310 ( V_251 , V_252 ) ;
if ( V_48 >= 0 )
F_311 ( V_178 , V_17 , 0 , V_48 ) ;
V_427:
F_164 ( V_252 ) ;
return V_48 ;
}
static int F_312 ( struct V_8 * V_9 )
{
struct V_108 * V_109 = NULL ;
T_6 V_111 = 0 ;
V_120 V_428 = 0 ;
T_6 V_429 ;
int V_48 ;
do {
T_7 V_110 ;
F_41 ( V_109 ) ;
V_110 = sizeof ( * V_109 ) ;
V_110 += V_111 * sizeof ( struct V_142 ) ;
V_110 += V_428 ;
V_109 = F_31 ( V_110 , V_68 ) ;
if ( ! V_109 )
return - V_66 ;
V_48 = F_307 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , V_109 , V_110 ) ;
if ( V_48 < 0 )
goto V_58;
if ( ( T_7 ) V_48 < V_110 ) {
V_48 = - V_413 ;
F_107 ( V_9 , L_90 ,
V_110 , V_48 ) ;
goto V_58;
}
if ( ! F_63 ( V_109 ) ) {
V_48 = - V_413 ;
F_107 ( V_9 , L_91 ) ;
goto V_58;
}
V_428 = F_65 ( V_109 -> V_121 ) ;
V_429 = V_111 ;
V_111 = F_64 ( V_109 -> V_111 ) ;
} while ( V_111 != V_429 );
V_48 = F_69 ( V_9 , V_109 ) ;
V_58:
F_41 ( V_109 ) ;
return V_48 ;
}
static void F_313 ( struct V_8 * V_9 )
{
V_120 V_55 ;
if ( ! F_18 ( V_412 , & V_9 -> V_41 ) )
return;
V_55 = V_9 -> V_54 -> V_55 ;
if ( V_55 == V_56 )
return;
if ( F_77 ( V_9 , V_55 ) == V_155 )
F_140 ( V_412 , & V_9 -> V_41 ) ;
}
static void F_314 ( struct V_8 * V_9 )
{
T_11 V_110 ;
if ( F_18 ( V_412 , & V_9 -> V_41 ) &&
! F_18 ( V_40 , & V_9 -> V_41 ) ) {
V_110 = ( T_11 ) V_9 -> V_36 . V_110 / V_430 ;
F_30 ( L_92 , ( unsigned long long ) V_110 ) ;
F_315 ( V_9 -> V_45 , V_110 ) ;
F_316 ( V_9 -> V_45 ) ;
}
}
static int F_267 ( struct V_8 * V_9 )
{
V_120 V_405 ;
int V_48 ;
F_248 ( & V_9 -> V_270 ) ;
V_405 = V_9 -> V_36 . V_110 ;
V_48 = F_317 ( V_9 ) ;
if ( V_48 )
goto V_58;
if ( V_9 -> V_277 ) {
V_48 = F_318 ( V_9 ) ;
if ( V_48 )
goto V_58;
}
if ( V_9 -> V_54 -> V_55 == V_56 ) {
V_9 -> V_36 . V_110 = V_9 -> V_123 . V_146 ;
} else {
F_313 ( V_9 ) ;
}
V_58:
F_249 ( & V_9 -> V_270 ) ;
if ( ! V_48 && V_405 != V_9 -> V_36 . V_110 )
F_314 ( V_9 ) ;
return V_48 ;
}
static int F_319 ( struct V_431 * V_432 , struct V_402 * V_272 ,
unsigned int V_433 , unsigned int V_434 )
{
struct V_332 * V_333 = F_302 ( V_272 ) ;
F_320 ( V_333 , F_293 ) ;
return 0 ;
}
static int F_321 ( struct V_8 * V_9 )
{
struct V_44 * V_45 ;
struct V_435 * V_403 ;
V_120 V_161 ;
int V_228 ;
V_45 = F_322 ( V_24 ?
( 1 << V_6 ) :
V_436 ) ;
if ( ! V_45 )
return - V_66 ;
snprintf ( V_45 -> V_437 , sizeof( V_45 -> V_437 ) , V_399 L_93 ,
V_9 -> V_5 ) ;
V_45 -> V_438 = V_9 -> V_438 ;
V_45 -> V_439 = V_9 -> V_7 ;
if ( V_24 )
V_45 -> V_41 |= V_440 ;
V_45 -> V_441 = & V_442 ;
V_45 -> V_33 = V_9 ;
memset ( & V_9 -> V_424 , 0 , sizeof( V_9 -> V_424 ) ) ;
V_9 -> V_424 . V_443 = & V_444 ;
V_9 -> V_424 . V_93 = V_9 -> V_372 -> V_93 ;
V_9 -> V_424 . V_434 = V_445 ;
V_9 -> V_424 . V_41 = V_446 | V_447 ;
V_9 -> V_424 . V_448 = 1 ;
V_9 -> V_424 . V_449 = sizeof( struct V_332 ) ;
V_228 = F_323 ( & V_9 -> V_424 ) ;
if ( V_228 )
goto V_450;
V_403 = F_324 ( & V_9 -> V_424 ) ;
if ( F_35 ( V_403 ) ) {
V_228 = F_200 ( V_403 ) ;
goto V_451;
}
F_325 ( V_452 , V_403 ) ;
V_161 = F_66 ( & V_9 -> V_123 ) ;
F_326 ( V_403 , V_161 / V_430 ) ;
V_403 -> V_453 . V_454 = F_327 ( V_403 ) ;
F_328 ( V_403 , V_161 / V_430 ) ;
F_329 ( V_403 , V_161 ) ;
F_330 ( V_403 , V_161 ) ;
F_331 ( V_403 , V_161 ) ;
F_325 ( V_455 , V_403 ) ;
V_403 -> V_453 . V_456 = V_161 ;
V_403 -> V_453 . V_457 = V_161 ;
F_332 ( V_403 , V_161 / V_430 ) ;
F_333 ( V_403 , V_161 / V_430 ) ;
if ( ! F_334 ( V_9 -> V_62 -> V_72 , V_458 ) )
V_403 -> V_459 -> V_460 |= V_461 ;
F_130 ( ! F_335 ( V_403 ) ) ;
V_45 -> V_423 = V_403 ;
V_403 -> V_404 = V_9 ;
V_9 -> V_45 = V_45 ;
return 0 ;
V_451:
F_305 ( & V_9 -> V_424 ) ;
V_450:
F_306 ( V_45 ) ;
return V_228 ;
}
static struct V_8 * F_336 ( struct V_28 * V_29 )
{
return F_58 ( V_29 , struct V_8 , V_29 ) ;
}
static T_2 F_337 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_94 ,
( unsigned long long ) V_9 -> V_36 . V_110 ) ;
}
static T_2 F_338 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_95 ,
( unsigned long long ) V_9 -> V_36 . V_159 ) ;
}
static T_2 F_339 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
if ( V_9 -> V_438 )
return sprintf ( V_17 , L_96 , V_9 -> V_438 ) ;
return sprintf ( V_17 , L_97 ) ;
}
static T_2 F_340 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_96 , V_9 -> V_7 ) ;
}
static T_2 F_341 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
struct V_463 * V_464 =
F_342 ( V_9 -> V_62 -> V_72 ) ;
return sprintf ( V_17 , L_98 , & V_464 -> V_465 ,
F_64 ( V_464 -> V_466 ) ) ;
}
static T_2 F_343 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_99 ,
F_212 ( V_9 -> V_62 -> V_72 ) ) ;
}
static T_2 F_344 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_100 , & V_9 -> V_62 -> V_72 -> V_467 ) ;
}
static T_2 F_345 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_468 ) ;
}
static T_2 F_346 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_469 ) ;
}
static T_2 F_347 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_94 ,
( unsigned long long ) V_9 -> V_54 -> V_129 ) ;
}
static T_2 F_348 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
if ( V_9 -> V_54 -> V_470 )
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_470 ) ;
return sprintf ( V_17 , L_102 ) ;
}
static T_2 F_349 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_471 ) ;
}
static T_2 F_350 ( struct V_28 * V_29 ,
struct V_462 * V_22 ,
char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_101 , V_9 -> V_54 -> V_149 ) ;
}
static T_2 F_351 ( struct V_28 * V_29 ,
struct V_462 * V_22 , char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
return sprintf ( V_17 , L_94 , V_9 -> V_54 -> V_55 ) ;
}
static T_2 F_352 ( struct V_28 * V_29 ,
struct V_462 * V_22 ,
char * V_17 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
T_2 V_472 = 0 ;
if ( ! V_9 -> V_277 )
return sprintf ( V_17 , L_103 ) ;
for ( ; V_9 -> V_277 ; V_9 = V_9 -> V_277 ) {
struct V_473 * V_54 = V_9 -> V_268 ;
V_472 += sprintf ( & V_17 [ V_472 ] , L_104
L_105
L_106
L_107
L_108 ,
! V_472 ? L_41 : L_109 ,
V_54 -> V_129 , V_54 -> V_469 ,
V_54 -> V_471 , V_54 -> V_470 ? : L_110 ,
V_54 -> V_55 , V_54 -> V_149 ,
V_9 -> V_201 ) ;
}
return V_472 ;
}
static T_2 F_353 ( struct V_28 * V_29 ,
struct V_462 * V_22 ,
const char * V_17 ,
T_7 V_110 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
int V_48 ;
V_48 = F_267 ( V_9 ) ;
if ( V_48 )
return V_48 ;
return V_110 ;
}
static struct V_473 * F_354 ( struct V_473 * V_54 )
{
F_45 ( & V_54 -> V_70 ) ;
return V_54 ;
}
static void F_175 ( struct V_473 * V_54 )
{
if ( V_54 )
F_61 ( & V_54 -> V_70 , V_474 ) ;
}
static struct V_473 * F_355 ( void )
{
struct V_473 * V_54 ;
V_54 = F_356 ( sizeof ( * V_54 ) , V_68 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_129 = V_131 ;
V_54 -> V_55 = V_56 ;
F_32 ( & V_54 -> V_70 ) ;
return V_54 ;
}
static void V_474 ( struct V_70 * V_70 )
{
struct V_473 * V_54 = F_58 ( V_70 , struct V_473 , V_70 ) ;
F_41 ( V_54 -> V_469 ) ;
F_41 ( V_54 -> V_471 ) ;
F_41 ( V_54 -> V_470 ) ;
F_41 ( V_54 -> V_149 ) ;
F_41 ( V_54 ) ;
}
static void F_357 ( struct V_8 * V_9 )
{
F_130 ( V_9 -> V_379 != V_385 ) ;
F_130 ( V_9 -> V_10 != V_319 ) ;
F_358 ( & V_9 -> V_312 ) ;
F_359 ( & V_9 -> V_313 ) ;
F_41 ( V_9 -> V_468 ) ;
F_60 ( V_9 -> V_62 ) ;
F_175 ( V_9 -> V_54 ) ;
F_41 ( V_9 -> V_372 ) ;
F_41 ( V_9 ) ;
}
static void F_360 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_336 ( V_29 ) ;
bool V_475 = ! ! V_9 -> V_372 ;
if ( V_475 ) {
F_361 ( V_9 -> V_317 ) ;
F_362 ( & V_476 , V_9 -> V_5 ) ;
}
F_357 ( V_9 ) ;
if ( V_475 )
F_363 ( V_477 ) ;
}
static struct V_8 * F_364 ( struct V_62 * V_65 ,
struct V_473 * V_54 )
{
struct V_8 * V_9 ;
V_9 = F_356 ( sizeof( * V_9 ) , V_68 ) ;
if ( ! V_9 )
return NULL ;
F_180 ( & V_9 -> V_39 ) ;
F_33 ( & V_9 -> V_71 ) ;
F_365 ( & V_9 -> V_270 ) ;
V_9 -> V_123 . V_130 = V_131 ;
F_366 ( & V_9 -> V_312 ) ;
V_9 -> V_313 . V_260 = V_54 -> V_129 ;
F_367 ( & V_9 -> V_306 ) ;
V_9 -> V_379 = V_385 ;
F_368 ( & V_9 -> V_382 , F_283 ) ;
F_365 ( & V_9 -> V_14 ) ;
V_9 -> V_10 = V_319 ;
F_320 ( & V_9 -> V_318 , F_226 ) ;
F_320 ( & V_9 -> V_321 , F_227 ) ;
F_368 ( & V_9 -> V_343 , F_250 ) ;
F_320 ( & V_9 -> V_369 , F_257 ) ;
F_369 ( & V_9 -> V_344 ) ;
V_9 -> V_29 . V_16 = & V_478 ;
V_9 -> V_29 . type = & V_479 ;
V_9 -> V_29 . V_277 = & V_480 ;
F_370 ( & V_9 -> V_29 ) ;
V_9 -> V_62 = V_65 ;
V_9 -> V_54 = V_54 ;
return V_9 ;
}
static struct V_8 * F_371 ( struct V_62 * V_65 ,
struct V_473 * V_54 ,
struct V_82 * V_372 )
{
struct V_8 * V_9 ;
V_9 = F_364 ( V_65 , V_54 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_372 = V_372 ;
V_9 -> V_5 = F_372 ( & V_476 , 0 ,
F_8 ( 1 << V_481 ) ,
V_68 ) ;
if ( V_9 -> V_5 < 0 )
goto V_482;
sprintf ( V_9 -> V_357 , V_399 L_93 , V_9 -> V_5 ) ;
V_9 -> V_317 = F_373 ( L_111 , V_483 ,
V_9 -> V_357 ) ;
if ( ! V_9 -> V_317 )
goto V_484;
F_374 ( V_477 ) ;
F_30 ( L_112 , V_67 , V_9 , V_9 -> V_5 ) ;
return V_9 ;
V_484:
F_362 ( & V_476 , V_9 -> V_5 ) ;
V_482:
F_357 ( V_9 ) ;
return NULL ;
}
static void F_375 ( struct V_8 * V_9 )
{
if ( V_9 )
F_23 ( & V_9 -> V_29 ) ;
}
static int F_82 ( struct V_8 * V_9 , V_120 V_55 ,
T_10 * V_115 , V_120 * V_157 )
{
V_119 V_485 = F_376 ( V_55 ) ;
int V_48 ;
struct {
T_10 V_115 ;
V_119 V_110 ;
} V_486 ( ( V_487 ) ) V_488 = { 0 } ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_113 ,
& V_485 , sizeof( V_485 ) ,
& V_488 , sizeof( V_488 ) ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof ( V_488 ) )
return - V_489 ;
if ( V_115 ) {
* V_115 = V_488 . V_115 ;
F_30 ( L_115 , ( unsigned int ) * V_115 ) ;
}
* V_157 = F_65 ( V_488 . V_110 ) ;
F_30 ( L_116 ,
( unsigned long long ) V_55 ,
( unsigned long long ) * V_157 ) ;
return 0 ;
}
static int F_377 ( struct V_8 * V_9 )
{
return F_82 ( V_9 , V_56 ,
& V_9 -> V_123 . V_124 ,
& V_9 -> V_123 . V_146 ) ;
}
static int F_378 ( struct V_8 * V_9 )
{
void * V_490 ;
int V_48 ;
void * V_328 ;
V_490 = F_356 ( V_491 , V_68 ) ;
if ( ! V_490 )
return - V_66 ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_117 ,
NULL , 0 , V_490 , V_491 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_58;
V_328 = V_490 ;
V_9 -> V_123 . V_134 = F_379 ( & V_328 ,
V_328 + V_48 , NULL , V_256 ) ;
V_48 = 0 ;
if ( F_35 ( V_9 -> V_123 . V_134 ) ) {
V_48 = F_200 ( V_9 -> V_123 . V_134 ) ;
V_9 -> V_123 . V_134 = NULL ;
} else {
F_30 ( L_118 , V_9 -> V_123 . V_134 ) ;
}
V_58:
F_41 ( V_490 ) ;
return V_48 ;
}
static int F_84 ( struct V_8 * V_9 , V_120 V_55 ,
V_120 * V_158 )
{
V_119 V_485 = F_376 ( V_55 ) ;
struct {
V_119 V_159 ;
V_119 V_492 ;
} V_486 ( ( V_487 ) ) V_493 = { 0 } ;
V_120 V_494 ;
int V_48 ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_119 ,
& V_485 , sizeof( V_485 ) ,
& V_493 , sizeof( V_493 ) ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof ( V_493 ) )
return - V_489 ;
V_494 = F_65 ( V_493 . V_492 ) & ~ V_18 ;
if ( V_494 ) {
F_107 ( V_9 , L_120 ,
V_494 ) ;
return - V_413 ;
}
* V_158 = F_65 ( V_493 . V_159 ) ;
F_30 ( L_121 ,
( unsigned long long ) V_55 ,
( unsigned long long ) * V_158 ,
( unsigned long long ) F_65 ( V_493 . V_492 ) ) ;
return 0 ;
}
static int F_380 ( struct V_8 * V_9 )
{
return F_84 ( V_9 , V_56 ,
& V_9 -> V_123 . V_159 ) ;
}
static int F_318 ( struct V_8 * V_9 )
{
struct V_473 * V_268 ;
T_7 V_110 ;
void * V_490 = NULL ;
V_119 V_485 ;
void * V_328 ;
void * V_179 ;
V_120 V_129 ;
char * V_471 ;
V_120 V_55 ;
V_120 V_495 ;
int V_48 ;
V_268 = F_355 () ;
if ( ! V_268 )
return - V_66 ;
V_110 = sizeof ( V_119 ) +
sizeof ( V_295 ) + V_496 +
sizeof ( V_119 ) +
sizeof ( V_119 ) ;
V_490 = F_31 ( V_110 , V_68 ) ;
if ( ! V_490 ) {
V_48 = - V_66 ;
goto V_139;
}
V_485 = F_376 ( V_9 -> V_54 -> V_55 ) ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_122 ,
& V_485 , sizeof( V_485 ) , V_490 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_139;
V_328 = V_490 ;
V_179 = V_490 + V_48 ;
V_48 = - V_489 ;
F_381 ( & V_328 , V_179 , V_129 , V_139 ) ;
if ( V_129 == V_131 ) {
if ( V_9 -> V_201 ) {
V_9 -> V_201 = 0 ;
F_176 ( V_9 ) ;
F_382 ( L_123 ,
V_9 -> V_45 -> V_437 ) ;
}
goto V_58;
}
V_48 = - V_147 ;
if ( V_129 > ( V_120 ) V_497 ) {
F_107 ( NULL , L_124 ,
( unsigned long long ) V_129 , V_497 ) ;
goto V_139;
}
V_471 = F_379 ( & V_328 , V_179 , NULL , V_68 ) ;
if ( F_35 ( V_471 ) ) {
V_48 = F_200 ( V_471 ) ;
goto V_139;
}
F_381 ( & V_328 , V_179 , V_55 , V_139 ) ;
F_381 ( & V_328 , V_179 , V_495 , V_139 ) ;
if ( ! V_9 -> V_268 ) {
V_268 -> V_129 = V_129 ;
V_268 -> V_471 = V_471 ;
V_268 -> V_55 = V_55 ;
V_9 -> V_268 = V_268 ;
V_268 = NULL ;
} else {
F_41 ( V_471 ) ;
}
if ( ! V_495 ) {
if ( V_268 ) {
if ( V_9 -> V_201 )
F_107 ( V_9 ,
L_125 ) ;
} else {
F_107 ( V_9 , L_126 ) ;
}
}
V_9 -> V_201 = V_495 ;
V_58:
V_48 = 0 ;
V_139:
F_41 ( V_490 ) ;
F_175 ( V_268 ) ;
return V_48 ;
}
static int F_383 ( struct V_8 * V_9 )
{
struct {
V_119 V_125 ;
V_119 V_126 ;
} V_486 ( ( V_487 ) ) V_498 = { 0 } ;
T_7 V_110 = sizeof ( V_498 ) ;
void * V_328 ;
V_120 V_499 ;
V_120 V_125 ;
V_120 V_126 ;
int V_48 ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_127 ,
NULL , 0 , & V_498 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < V_110 )
return - V_489 ;
V_48 = - V_4 ;
V_499 = F_66 ( & V_9 -> V_123 ) ;
V_328 = & V_498 ;
V_125 = F_259 ( & V_328 ) ;
if ( V_125 != V_499 ) {
F_107 ( V_9 , L_128
L_129 ,
V_125 , V_499 ) ;
return - V_4 ;
}
V_126 = F_259 ( & V_328 ) ;
if ( V_126 != 1 ) {
F_107 ( V_9 , L_130
L_131 , V_126 ) ;
return - V_4 ;
}
V_9 -> V_123 . V_125 = V_125 ;
V_9 -> V_123 . V_126 = V_126 ;
return 0 ;
}
static int F_384 ( struct V_8 * V_9 )
{
V_119 V_130 ;
int V_48 ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_132 ,
NULL , 0 , & V_130 , sizeof( V_130 ) ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 < sizeof( V_130 ) )
return - V_500 ;
V_9 -> V_123 . V_130 = F_65 ( V_130 ) ;
F_130 ( V_9 -> V_123 . V_130 == V_131 ) ;
return 0 ;
}
static char * F_385 ( struct V_8 * V_9 )
{
F_386 ( V_388 ) ;
T_7 V_501 ;
char * V_471 ;
void * V_328 ;
void * V_179 ;
T_7 V_110 ;
void * V_490 = NULL ;
T_7 V_186 = 0 ;
char * V_470 = NULL ;
int V_48 ;
F_22 ( ! V_9 -> V_54 -> V_470 ) ;
V_186 = strlen ( V_9 -> V_54 -> V_471 ) ;
V_501 = sizeof ( V_295 ) + V_186 ;
V_471 = F_31 ( V_501 , V_68 ) ;
if ( ! V_471 )
return NULL ;
V_328 = V_471 ;
V_179 = V_471 + V_501 ;
F_387 ( & V_328 , V_179 , V_9 -> V_54 -> V_471 , ( T_6 ) V_186 ) ;
V_110 = sizeof ( V_295 ) + V_502 ;
V_490 = F_31 ( V_110 , V_68 ) ;
if ( ! V_490 )
goto V_58;
F_388 ( & V_388 , L_104 , V_503 ) ;
V_48 = F_284 ( V_9 , & V_388 , & V_9 -> V_313 ,
L_133 , V_471 , V_501 ,
V_490 , V_110 ) ;
if ( V_48 < 0 )
goto V_58;
V_328 = V_490 ;
V_179 = V_490 + V_48 ;
V_470 = F_379 ( & V_328 , V_179 , & V_186 , V_68 ) ;
if ( F_35 ( V_470 ) )
V_470 = NULL ;
else
F_30 ( L_134 , V_67 , V_470 , V_186 ) ;
V_58:
F_41 ( V_490 ) ;
F_41 ( V_471 ) ;
return V_470 ;
}
static V_120 F_389 ( struct V_8 * V_9 , const char * V_357 )
{
struct V_118 * V_135 = V_9 -> V_123 . V_135 ;
const char * V_149 ;
T_6 V_148 = 0 ;
V_149 = V_9 -> V_123 . V_136 ;
while ( V_148 < V_135 -> V_150 ) {
if ( ! strcmp ( V_357 , V_149 ) )
return V_135 -> V_143 [ V_148 ] ;
V_149 += strlen ( V_149 ) + 1 ;
V_148 ++ ;
}
return V_56 ;
}
static V_120 F_390 ( struct V_8 * V_9 , const char * V_357 )
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
if ( F_200 ( V_149 ) == - V_43 )
continue;
else
break;
}
V_78 = ! strcmp ( V_357 , V_149 ) ;
F_41 ( V_149 ) ;
}
return V_78 ? V_55 : V_56 ;
}
static V_120 F_391 ( struct V_8 * V_9 , const char * V_357 )
{
if ( V_9 -> V_107 == 1 )
return F_389 ( V_9 , V_357 ) ;
return F_390 ( V_9 , V_357 ) ;
}
static int F_392 ( struct V_8 * V_9 )
{
struct V_473 * V_54 = V_9 -> V_54 ;
F_22 ( V_54 -> V_129 != V_131 && V_54 -> V_469 ) ;
F_22 ( V_54 -> V_471 && V_54 -> V_470 ) ;
F_22 ( V_54 -> V_149 ) ;
if ( strcmp ( V_54 -> V_149 , V_156 ) ) {
V_120 V_55 ;
V_55 = F_391 ( V_9 , V_54 -> V_149 ) ;
if ( V_55 == V_56 )
return - V_43 ;
V_54 -> V_55 = V_55 ;
} else {
V_54 -> V_55 = V_56 ;
}
return 0 ;
}
static int F_393 ( struct V_8 * V_9 )
{
struct V_250 * V_251 = & V_9 -> V_62 -> V_72 -> V_251 ;
struct V_473 * V_54 = V_9 -> V_54 ;
const char * V_469 ;
const char * V_470 ;
const char * V_149 ;
int V_48 ;
F_22 ( V_54 -> V_129 != V_131 ) ;
F_22 ( V_54 -> V_471 ) ;
F_22 ( V_54 -> V_55 != V_56 ) ;
V_469 = F_394 ( V_251 -> V_504 , V_54 -> V_129 ) ;
if ( ! V_469 ) {
F_107 ( V_9 , L_135 , V_54 -> V_129 ) ;
return - V_147 ;
}
V_469 = F_75 ( V_469 , V_68 ) ;
if ( ! V_469 )
return - V_66 ;
V_470 = F_385 ( V_9 ) ;
if ( ! V_470 )
F_107 ( V_9 , L_136 ) ;
V_149 = F_79 ( V_9 , V_54 -> V_55 ) ;
if ( F_35 ( V_149 ) ) {
V_48 = F_200 ( V_149 ) ;
goto V_139;
}
V_54 -> V_469 = V_469 ;
V_54 -> V_470 = V_470 ;
V_54 -> V_149 = V_149 ;
return 0 ;
V_139:
F_41 ( V_470 ) ;
F_41 ( V_469 ) ;
return V_48 ;
}
static int F_395 ( struct V_8 * V_9 )
{
T_7 V_110 ;
int V_48 ;
void * V_490 ;
void * V_328 ;
void * V_179 ;
V_120 V_140 ;
T_6 V_111 ;
struct V_118 * V_135 ;
T_6 V_138 ;
V_110 = sizeof ( V_119 ) + sizeof ( V_295 ) +
V_505 * sizeof ( V_119 ) ;
V_490 = F_356 ( V_110 , V_68 ) ;
if ( ! V_490 )
return - V_66 ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_137 ,
NULL , 0 , V_490 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 )
goto V_58;
V_328 = V_490 ;
V_179 = V_490 + V_48 ;
V_48 = - V_489 ;
F_381 ( & V_328 , V_179 , V_140 , V_58 ) ;
F_230 ( & V_328 , V_179 , V_111 , V_58 ) ;
if ( V_111 > ( V_117 - sizeof ( struct V_118 ) )
/ sizeof ( V_120 ) ) {
V_48 = - V_4 ;
goto V_58;
}
if ( ! F_396 ( & V_328 , V_179 , V_111 * sizeof ( V_119 ) ) )
goto V_58;
V_48 = 0 ;
V_135 = F_71 ( V_111 , V_68 ) ;
if ( ! V_135 ) {
V_48 = - V_66 ;
goto V_58;
}
V_135 -> V_140 = V_140 ;
for ( V_138 = 0 ; V_138 < V_111 ; V_138 ++ )
V_135 -> V_143 [ V_138 ] = F_259 ( & V_328 ) ;
F_73 ( V_9 -> V_123 . V_135 ) ;
V_9 -> V_123 . V_135 = V_135 ;
F_30 ( L_138 ,
( unsigned long long ) V_140 , ( unsigned int ) V_111 ) ;
V_58:
F_41 ( V_490 ) ;
return V_48 ;
}
static const char * F_80 ( struct V_8 * V_9 ,
V_120 V_55 )
{
T_7 V_110 ;
void * V_490 ;
V_119 V_485 ;
int V_48 ;
void * V_328 ;
void * V_179 ;
char * V_149 ;
V_110 = sizeof ( V_295 ) + V_506 ;
V_490 = F_31 ( V_110 , V_68 ) ;
if ( ! V_490 )
return F_43 ( - V_66 ) ;
V_485 = F_376 ( V_55 ) ;
V_48 = F_284 ( V_9 , & V_9 -> V_312 ,
& V_9 -> V_313 , L_139 ,
& V_485 , sizeof( V_485 ) , V_490 , V_110 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 < 0 ) {
V_149 = F_43 ( V_48 ) ;
goto V_58;
}
V_328 = V_490 ;
V_179 = V_490 + V_48 ;
V_149 = F_379 ( & V_328 , V_179 , NULL , V_68 ) ;
if ( F_35 ( V_149 ) )
goto V_58;
F_30 ( L_140 ,
( unsigned long long ) V_55 , V_149 ) ;
V_58:
F_41 ( V_490 ) ;
return V_149 ;
}
static int F_397 ( struct V_8 * V_9 )
{
bool V_133 = V_9 -> V_123 . V_134 == NULL ;
int V_48 ;
V_48 = F_377 ( V_9 ) ;
if ( V_48 )
return V_48 ;
if ( V_133 ) {
V_48 = F_398 ( V_9 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_395 ( V_9 ) ;
if ( V_48 && V_133 ) {
F_41 ( V_9 -> V_123 . V_134 ) ;
V_9 -> V_123 . V_134 = NULL ;
}
return V_48 ;
}
static int F_317 ( struct V_8 * V_9 )
{
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_9 -> V_107 == 1 )
return F_312 ( V_9 ) ;
return F_397 ( V_9 ) ;
}
static inline T_7 F_399 ( const char * * V_17 )
{
const char * V_507 = L_141 ;
* V_17 += strspn ( * V_17 , V_507 ) ;
return strcspn ( * V_17 , V_507 ) ;
}
static inline char * F_400 ( const char * * V_17 , T_7 * V_508 )
{
char * V_509 ;
T_7 V_186 ;
V_186 = F_399 ( V_17 ) ;
V_509 = F_401 ( * V_17 , V_186 + 1 , V_68 ) ;
if ( ! V_509 )
return NULL ;
* ( V_509 + V_186 ) = '\0' ;
* V_17 += V_186 ;
if ( V_508 )
* V_508 = V_186 ;
return V_509 ;
}
static int F_402 ( const char * V_17 ,
struct V_63 * * V_64 ,
struct V_82 * * V_372 ,
struct V_473 * * V_473 )
{
T_7 V_186 ;
char * V_114 ;
const char * V_510 ;
char * V_149 ;
T_7 V_511 ;
struct V_473 * V_54 = NULL ;
struct V_82 * V_83 = NULL ;
struct V_63 * V_512 ;
int V_48 ;
V_186 = F_399 ( & V_17 ) ;
if ( ! V_186 ) {
F_107 ( NULL , L_142 ) ;
return - V_4 ;
}
V_510 = V_17 ;
V_511 = V_186 + 1 ;
V_17 += V_186 ;
V_48 = - V_4 ;
V_114 = F_400 ( & V_17 , NULL ) ;
if ( ! V_114 )
return - V_66 ;
if ( ! * V_114 ) {
F_107 ( NULL , L_143 ) ;
goto V_139;
}
V_54 = F_355 () ;
if ( ! V_54 )
goto V_513;
V_54 -> V_469 = F_400 ( & V_17 , NULL ) ;
if ( ! V_54 -> V_469 )
goto V_513;
if ( ! * V_54 -> V_469 ) {
F_107 ( NULL , L_144 ) ;
goto V_139;
}
V_54 -> V_470 = F_400 ( & V_17 , NULL ) ;
if ( ! V_54 -> V_470 )
goto V_513;
if ( ! * V_54 -> V_470 ) {
F_107 ( NULL , L_145 ) ;
goto V_139;
}
V_186 = F_399 ( & V_17 ) ;
if ( ! V_186 ) {
V_17 = V_156 ;
V_186 = sizeof ( V_156 ) - 1 ;
} else if ( V_186 > V_506 ) {
V_48 = - V_514 ;
goto V_139;
}
V_149 = F_401 ( V_17 , V_186 + 1 , V_68 ) ;
if ( ! V_149 )
goto V_513;
* ( V_149 + V_186 ) = '\0' ;
V_54 -> V_149 = V_149 ;
V_83 = F_356 ( sizeof ( * V_83 ) , V_68 ) ;
if ( ! V_83 )
goto V_513;
V_83 -> V_37 = V_515 ;
V_83 -> V_93 = V_516 ;
V_83 -> V_97 = V_517 ;
V_83 -> V_99 = V_518 ;
V_512 = F_403 ( V_114 , V_510 ,
V_510 + V_511 - 1 ,
F_49 , V_83 ) ;
if ( F_35 ( V_512 ) ) {
V_48 = F_200 ( V_512 ) ;
goto V_139;
}
F_41 ( V_114 ) ;
* V_64 = V_512 ;
* V_372 = V_83 ;
* V_473 = V_54 ;
return 0 ;
V_513:
V_48 = - V_66 ;
V_139:
F_41 ( V_83 ) ;
F_175 ( V_54 ) ;
F_41 ( V_114 ) ;
return V_48 ;
}
static int F_404 ( struct V_62 * V_65 , const char * V_469 )
{
struct V_63 * V_372 = V_65 -> V_72 -> V_114 ;
V_120 V_519 ;
int V_520 = 0 ;
int V_48 ;
V_360:
V_48 = F_405 ( V_65 -> V_72 -> V_251 . V_504 , V_469 ) ;
if ( V_48 == - V_43 && V_520 ++ < 1 ) {
V_48 = F_406 ( & V_65 -> V_72 -> V_361 , L_146 ,
& V_519 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_65 -> V_72 -> V_251 . V_504 -> V_521 < V_519 ) {
F_407 ( & V_65 -> V_72 -> V_251 ) ;
( void ) F_408 ( & V_65 -> V_72 -> V_361 ,
V_519 ,
V_372 -> V_522 ) ;
goto V_360;
} else {
return - V_43 ;
}
}
return V_48 ;
}
static void F_409 ( struct V_8 * V_9 )
{
F_248 ( & V_9 -> V_14 ) ;
if ( F_9 ( V_9 ) )
F_218 ( V_9 ) ;
F_249 ( & V_9 -> V_14 ) ;
}
static int F_410 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_123 . V_159 & V_414 ) ) {
F_107 ( V_9 , L_147 ) ;
return - V_4 ;
}
F_11 ( & V_9 -> V_14 ) ;
F_288 ( V_9 ) ;
F_12 ( & V_9 -> V_14 ) ;
if ( F_18 ( V_366 , & V_9 -> V_41 ) ) {
F_107 ( V_9 , L_148 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_411 ( struct V_8 * V_9 )
{
int V_48 ;
T_7 V_110 ;
F_386 ( V_388 ) ;
void * V_523 ;
char * V_471 ;
if ( V_9 -> V_54 -> V_471 ) {
V_9 -> V_107 = * V_9 -> V_54 -> V_471 ? 2 : 1 ;
return 0 ;
}
V_48 = F_162 ( & V_388 , V_68 , L_149 , V_524 ,
V_9 -> V_54 -> V_470 ) ;
if ( V_48 )
return V_48 ;
F_30 ( L_150 , V_388 . V_357 ) ;
V_110 = sizeof ( V_295 ) + V_496 ;
V_523 = F_356 ( V_110 , V_256 ) ;
if ( ! V_523 ) {
V_48 = - V_66 ;
goto V_58;
}
V_48 = F_284 ( V_9 , & V_388 , & V_9 -> V_313 ,
L_151 , NULL , 0 ,
V_523 , V_496 ) ;
F_30 ( L_114 , V_67 , V_48 ) ;
if ( V_48 == - V_43 ) {
V_471 = F_75 ( L_41 , V_68 ) ;
V_48 = V_471 ? 0 : - V_66 ;
if ( ! V_48 )
V_9 -> V_107 = 1 ;
} else if ( V_48 >= 0 ) {
void * V_328 = V_523 ;
V_471 = F_379 ( & V_328 , V_328 + V_48 ,
NULL , V_256 ) ;
V_48 = F_412 ( V_471 ) ;
if ( ! V_48 )
V_9 -> V_107 = 2 ;
}
if ( ! V_48 ) {
V_9 -> V_54 -> V_471 = V_471 ;
F_30 ( L_152 , V_471 ) ;
}
V_58:
F_41 ( V_523 ) ;
F_358 ( & V_388 ) ;
return V_48 ;
}
static void F_413 ( struct V_8 * V_9 )
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
static int F_398 ( struct V_8 * V_9 )
{
int V_48 ;
V_48 = F_378 ( V_9 ) ;
if ( V_48 )
goto V_139;
V_48 = F_380 ( V_9 ) ;
if ( V_48 )
goto V_139;
if ( V_9 -> V_123 . V_159 & V_525 ) {
V_48 = F_383 ( V_9 ) ;
if ( V_48 < 0 )
goto V_139;
}
if ( V_9 -> V_123 . V_159 & V_526 ) {
V_48 = F_384 ( V_9 ) ;
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
static int F_414 ( struct V_8 * V_9 , int V_527 )
{
struct V_8 * V_277 = NULL ;
int V_48 ;
if ( ! V_9 -> V_268 )
return 0 ;
if ( ++ V_527 > V_528 ) {
F_382 ( L_153 , V_527 ) ;
V_48 = - V_4 ;
goto V_139;
}
V_277 = F_364 ( V_9 -> V_62 , V_9 -> V_268 ) ;
if ( ! V_277 ) {
V_48 = - V_66 ;
goto V_139;
}
F_44 ( V_9 -> V_62 ) ;
F_354 ( V_9 -> V_268 ) ;
V_48 = F_415 ( V_277 , V_527 ) ;
if ( V_48 < 0 )
goto V_139;
V_9 -> V_277 = V_277 ;
F_416 ( & V_9 -> V_269 , 1 ) ;
return 0 ;
V_139:
F_173 ( V_9 ) ;
F_375 ( V_277 ) ;
return V_48 ;
}
static void F_417 ( struct V_8 * V_9 )
{
F_140 ( V_412 , & V_9 -> V_41 ) ;
F_86 ( V_9 ) ;
F_303 ( V_9 ) ;
if ( ! V_24 )
F_418 ( V_9 -> V_438 , V_9 -> V_357 ) ;
}
static int F_419 ( struct V_8 * V_9 )
{
int V_48 ;
if ( ! V_24 ) {
V_48 = F_420 ( 0 , V_9 -> V_357 ) ;
if ( V_48 < 0 )
goto V_529;
V_9 -> V_438 = V_48 ;
V_9 -> V_7 = 0 ;
} else {
V_9 -> V_438 = V_530 ;
V_9 -> V_7 = F_7 ( V_9 -> V_5 ) ;
}
V_48 = F_321 ( V_9 ) ;
if ( V_48 )
goto V_531;
V_48 = F_85 ( V_9 ) ;
if ( V_48 )
goto V_532;
F_315 ( V_9 -> V_45 , V_9 -> V_36 . V_110 / V_430 ) ;
F_26 ( V_9 -> V_45 , V_9 -> V_36 . V_37 ) ;
V_48 = F_421 ( & V_9 -> V_29 , L_93 , V_9 -> V_5 ) ;
if ( V_48 )
goto V_533;
F_115 ( V_412 , & V_9 -> V_41 ) ;
F_249 ( & V_9 -> V_270 ) ;
return 0 ;
V_533:
F_86 ( V_9 ) ;
V_532:
F_303 ( V_9 ) ;
V_531:
if ( ! V_24 )
F_418 ( V_9 -> V_438 , V_9 -> V_357 ) ;
V_529:
F_249 ( & V_9 -> V_270 ) ;
return V_48 ;
}
static int F_422 ( struct V_8 * V_9 )
{
struct V_473 * V_54 = V_9 -> V_54 ;
int V_48 ;
F_22 ( F_62 ( V_9 -> V_107 ) ) ;
if ( V_9 -> V_107 == 1 )
V_48 = F_162 ( & V_9 -> V_312 , V_68 , L_149 ,
V_54 -> V_470 , V_534 ) ;
else
V_48 = F_162 ( & V_9 -> V_312 , V_68 , L_149 ,
V_535 , V_54 -> V_471 ) ;
return V_48 ;
}
static void F_423 ( struct V_8 * V_9 )
{
F_413 ( V_9 ) ;
if ( V_9 -> V_372 )
F_278 ( V_9 ) ;
V_9 -> V_107 = 0 ;
F_41 ( V_9 -> V_54 -> V_471 ) ;
V_9 -> V_54 -> V_471 = NULL ;
}
static int F_415 ( struct V_8 * V_9 , int V_527 )
{
int V_48 ;
V_48 = F_411 ( V_9 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_422 ( V_9 ) ;
if ( V_48 )
goto V_536;
if ( ! V_527 ) {
V_48 = F_274 ( V_9 ) ;
if ( V_48 ) {
if ( V_48 == - V_43 )
F_382 ( L_154 ,
V_9 -> V_54 -> V_469 ,
V_9 -> V_54 -> V_470 ) ;
goto V_536;
}
}
V_48 = F_317 ( V_9 ) ;
if ( V_48 )
goto V_537;
if ( ! V_527 )
V_48 = F_392 ( V_9 ) ;
else
V_48 = F_393 ( V_9 ) ;
if ( V_48 ) {
if ( V_48 == - V_43 )
F_382 ( L_155 ,
V_9 -> V_54 -> V_469 ,
V_9 -> V_54 -> V_470 ,
V_9 -> V_54 -> V_149 ) ;
goto V_538;
}
if ( V_9 -> V_123 . V_159 & V_539 ) {
V_48 = F_318 ( V_9 ) ;
if ( V_48 )
goto V_538;
if ( ! V_527 && V_9 -> V_268 )
F_107 ( V_9 ,
L_156 ) ;
}
V_48 = F_414 ( V_9 , V_527 ) ;
if ( V_48 )
goto V_538;
F_30 ( L_157 ,
V_9 -> V_107 , V_9 -> V_312 . V_357 ) ;
return 0 ;
V_538:
F_413 ( V_9 ) ;
V_537:
if ( ! V_527 )
F_278 ( V_9 ) ;
V_536:
V_9 -> V_107 = 0 ;
F_41 ( V_9 -> V_54 -> V_471 ) ;
V_9 -> V_54 -> V_471 = NULL ;
return V_48 ;
}
static T_2 F_424 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
struct V_8 * V_9 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_82 * V_83 = NULL ;
struct V_473 * V_54 = NULL ;
struct V_62 * V_65 ;
bool V_37 ;
int V_540 ;
if ( ! F_425 ( V_477 ) )
return - V_541 ;
V_540 = F_402 ( V_17 , & V_64 , & V_83 , & V_54 ) ;
if ( V_540 < 0 )
goto V_58;
V_65 = F_54 ( V_64 ) ;
if ( F_35 ( V_65 ) ) {
V_540 = F_200 ( V_65 ) ;
goto V_542;
}
V_540 = F_404 ( V_65 , V_54 -> V_469 ) ;
if ( V_540 < 0 ) {
if ( V_540 == - V_43 )
F_382 ( L_158 , V_54 -> V_469 ) ;
goto V_543;
}
V_54 -> V_129 = ( V_120 ) V_540 ;
V_9 = F_371 ( V_65 , V_54 , V_83 ) ;
if ( ! V_9 ) {
V_540 = - V_66 ;
goto V_543;
}
V_65 = NULL ;
V_54 = NULL ;
V_83 = NULL ;
V_9 -> V_468 = F_75 ( V_17 , V_68 ) ;
if ( ! V_9 -> V_468 ) {
V_540 = - V_66 ;
goto V_544;
}
F_248 ( & V_9 -> V_270 ) ;
V_540 = F_415 ( V_9 , 0 ) ;
if ( V_540 < 0 ) {
F_249 ( & V_9 -> V_270 ) ;
goto V_544;
}
V_37 = V_9 -> V_372 -> V_37 ;
if ( V_9 -> V_54 -> V_55 != V_56 )
V_37 = true ;
V_9 -> V_36 . V_37 = V_37 ;
V_540 = F_419 ( V_9 ) ;
if ( V_540 )
goto V_545;
if ( V_9 -> V_372 -> V_99 ) {
V_540 = F_410 ( V_9 ) ;
if ( V_540 )
goto V_546;
}
V_540 = F_426 ( & V_9 -> V_29 ) ;
if ( V_540 )
goto V_547;
F_427 ( V_9 -> V_45 ) ;
F_428 ( V_9 -> V_45 -> V_423 ) ;
F_37 ( & V_548 ) ;
F_38 ( & V_9 -> V_71 , & V_549 ) ;
F_39 ( & V_548 ) ;
F_382 ( L_159 , V_9 -> V_45 -> V_437 ,
( unsigned long long ) F_429 ( V_9 -> V_45 ) << V_116 ,
V_9 -> V_123 . V_159 ) ;
V_540 = V_472 ;
V_58:
F_363 ( V_477 ) ;
return V_540 ;
V_547:
F_409 ( V_9 ) ;
V_546:
F_417 ( V_9 ) ;
V_545:
F_423 ( V_9 ) ;
V_544:
F_375 ( V_9 ) ;
V_543:
F_60 ( V_65 ) ;
V_542:
F_175 ( V_54 ) ;
F_41 ( V_83 ) ;
goto V_58;
}
static T_2 F_430 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
if ( V_24 )
return - V_4 ;
return F_424 ( V_16 , V_17 , V_472 ) ;
}
static T_2 F_431 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
return F_424 ( V_16 , V_17 , V_472 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
while ( V_9 -> V_277 ) {
struct V_8 * V_550 = V_9 ;
struct V_8 * V_551 = V_550 -> V_277 ;
struct V_8 * V_552 ;
while ( V_551 && ( V_552 = V_551 -> V_277 ) ) {
V_550 = V_551 ;
V_551 = V_552 ;
}
F_22 ( V_551 ) ;
F_423 ( V_551 ) ;
F_375 ( V_551 ) ;
V_550 -> V_277 = NULL ;
V_550 -> V_201 = 0 ;
F_22 ( V_550 -> V_268 ) ;
F_175 ( V_550 -> V_268 ) ;
V_550 -> V_268 = NULL ;
}
}
static T_2 F_432 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
struct V_8 * V_9 = NULL ;
struct V_553 * V_166 ;
int V_5 ;
char V_554 [ 6 ] ;
bool V_555 = false ;
bool V_556 = false ;
int V_48 ;
V_5 = - 1 ;
V_554 [ 0 ] = '\0' ;
sscanf ( V_17 , L_160 , & V_5 , V_554 ) ;
if ( V_5 < 0 ) {
F_52 ( L_161 ) ;
return - V_4 ;
}
if ( V_554 [ 0 ] != '\0' ) {
if ( ! strcmp ( V_554 , L_162 ) ) {
V_556 = true ;
} else {
F_52 ( L_163 , V_554 ) ;
return - V_4 ;
}
}
V_48 = - V_43 ;
F_37 ( & V_548 ) ;
F_433 (tmp, &rbd_dev_list) {
V_9 = F_434 ( V_166 , struct V_8 , V_71 ) ;
if ( V_9 -> V_5 == V_5 ) {
V_48 = 0 ;
break;
}
}
if ( ! V_48 ) {
F_17 ( & V_9 -> V_39 ) ;
if ( V_9 -> V_42 && ! V_556 )
V_48 = - V_57 ;
else
V_555 = F_109 ( V_40 ,
& V_9 -> V_41 ) ;
F_19 ( & V_9 -> V_39 ) ;
}
F_39 ( & V_548 ) ;
if ( V_48 < 0 || V_555 )
return V_48 ;
if ( V_556 ) {
F_435 ( V_9 -> V_45 -> V_423 ) ;
F_436 ( V_9 -> V_45 -> V_423 ) ;
}
F_437 ( V_9 -> V_45 ) ;
F_37 ( & V_548 ) ;
F_438 ( & V_9 -> V_71 ) ;
F_39 ( & V_548 ) ;
F_439 ( & V_9 -> V_29 ) ;
F_409 ( V_9 ) ;
F_417 ( V_9 ) ;
F_423 ( V_9 ) ;
F_375 ( V_9 ) ;
return V_472 ;
}
static T_2 F_440 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
if ( V_24 )
return - V_4 ;
return F_432 ( V_16 , V_17 , V_472 ) ;
}
static T_2 F_441 ( struct V_15 * V_16 ,
const char * V_17 ,
T_7 V_472 )
{
return F_432 ( V_16 , V_17 , V_472 ) ;
}
static int F_442 ( void )
{
int V_48 ;
V_48 = F_443 ( & V_480 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_444 ( & V_478 ) ;
if ( V_48 < 0 )
F_445 ( & V_480 ) ;
return V_48 ;
}
static void F_446 ( void )
{
F_447 ( & V_478 ) ;
F_445 ( & V_480 ) ;
}
static int F_448 ( void )
{
F_22 ( ! V_271 ) ;
V_271 = F_449 ( V_203 , 0 ) ;
if ( ! V_271 )
return - V_66 ;
F_22 ( ! V_266 ) ;
V_266 = F_449 ( V_192 , 0 ) ;
if ( ! V_266 )
goto V_139;
return 0 ;
V_139:
F_450 ( V_271 ) ;
V_271 = NULL ;
return - V_66 ;
}
static void F_451 ( void )
{
F_22 ( V_266 ) ;
F_450 ( V_266 ) ;
V_266 = NULL ;
F_22 ( V_271 ) ;
F_450 ( V_271 ) ;
V_271 = NULL ;
}
static int T_12 F_452 ( void )
{
int V_540 ;
if ( ! F_453 ( NULL ) ) {
F_107 ( NULL , L_164 ) ;
return - V_4 ;
}
V_540 = F_448 () ;
if ( V_540 )
return V_540 ;
V_421 = F_454 ( V_399 , V_483 , 0 ) ;
if ( ! V_421 ) {
V_540 = - V_66 ;
goto V_557;
}
if ( V_24 ) {
V_530 = F_420 ( 0 , V_399 ) ;
if ( V_530 < 0 ) {
V_540 = V_530 ;
goto V_558;
}
}
V_540 = F_442 () ;
if ( V_540 )
goto V_531;
if ( V_24 )
F_382 ( L_165 , V_530 ) ;
else
F_382 ( L_166 ) ;
return 0 ;
V_531:
if ( V_24 )
F_418 ( V_530 , V_399 ) ;
V_558:
F_361 ( V_421 ) ;
V_557:
F_451 () ;
return V_540 ;
}
static void T_13 F_455 ( void )
{
F_456 ( & V_476 ) ;
F_446 () ;
if ( V_24 )
F_418 ( V_530 , V_399 ) ;
F_361 ( V_421 ) ;
F_451 () ;
}
