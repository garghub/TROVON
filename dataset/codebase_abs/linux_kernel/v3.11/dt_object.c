void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 , & V_2 -> V_6 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_5 ) ;
}
int F_5 ( const struct V_7 * V_8 ,
struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_3 * V_4 ;
if ( V_10 -> V_12 )
return 0 ;
F_6 (cb, &dev->dd_txn_callbacks, dtc_linkage) {
if ( V_4 -> V_13 == NULL ||
! ( V_4 -> V_14 & V_8 -> V_15 . V_16 ) )
continue;
V_11 = V_4 -> V_13 ( V_8 , V_10 , V_4 -> V_17 ) ;
if ( V_11 < 0 )
break;
}
return V_11 ;
}
int F_7 ( const struct V_7 * V_8 , struct V_9 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_3 * V_4 ;
int V_11 = 0 ;
if ( V_18 -> V_12 )
return 0 ;
F_6 (cb, &dev->dd_txn_callbacks, dtc_linkage) {
if ( V_4 -> V_20 == NULL ||
! ( V_4 -> V_14 & V_8 -> V_15 . V_16 ) )
continue;
V_11 = V_4 -> V_20 ( V_8 , V_18 , V_4 -> V_17 ) ;
if ( V_11 < 0 )
break;
}
return V_11 ;
}
void F_8 ( struct V_9 * V_18 )
{
struct V_3 * V_4 ;
if ( V_18 -> V_12 )
return;
F_6 (cb, &txn->th_dev->dd_txn_callbacks,
dtc_linkage) {
if ( V_4 -> V_21 )
V_4 -> V_21 ( V_18 , V_4 -> V_17 ) ;
}
}
int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_10 ( & V_2 -> V_6 ) ;
return F_11 ( & V_2 -> V_24 , V_23 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_24 ) ;
}
int F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 , struct V_29 * V_30 )
{
return F_15 ( & V_26 -> V_31 , V_28 , V_30 ) ;
}
void F_16 ( struct V_25 * V_26 )
{
F_17 ( & V_26 -> V_31 ) ;
}
int F_18 ( const struct V_7 * V_8 , struct V_25 * V_26 )
{
if ( V_26 -> V_32 == NULL )
V_26 -> V_33 -> V_34 ( V_8 , V_26 , & V_35 ) ;
return V_26 -> V_32 != NULL ;
}
enum V_36 F_19 ( T_1 V_37 )
{
enum V_36 V_38 ;
switch ( V_37 & V_39 ) {
case V_40 :
V_38 = V_41 ;
break;
case V_42 :
V_38 = V_43 ;
break;
case V_44 :
V_38 = V_45 ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_38 = V_50 ;
break;
default:
F_20 () ;
break;
}
return V_38 ;
}
int F_21 ( const struct V_7 * V_8 , struct V_25 * V_51 ,
const char * V_52 , struct V_53 * V_54 )
{
if ( F_18 ( V_8 , V_51 ) )
return F_22 ( V_8 , V_51 , (struct V_55 * ) V_54 ,
( const struct V_56 * ) V_52 , V_57 ) ;
return - V_58 ;
}
struct V_25 * F_23 ( const struct V_7 * V_8 ,
struct V_1 * V_2 , const struct V_53 * V_54 ,
struct V_29 * V_59 )
{
struct V_60 * V_61 , * V_62 ;
V_63 ;
V_61 = F_24 ( V_8 , V_59 , V_54 , NULL ) ;
if ( F_25 ( V_61 ) )
return ( void * ) V_61 ;
F_26 ( V_61 != NULL ) ;
F_6 (n, &lo->lo_header->loh_layers, lo_linkage) {
if ( V_62 -> V_64 == & V_2 -> V_24 )
return F_27 ( V_62 , struct V_25 , V_31 ) ;
}
return F_28 ( - V_65 ) ;
}
static int F_29 ( const struct V_7 * V_8 , const char * V_66 , void * V_67 )
{
struct V_68 * V_69 = V_67 ;
struct V_1 * V_70 = V_69 -> V_71 ;
struct V_53 * V_54 = V_69 -> V_72 ;
struct V_25 * V_26 = V_69 -> V_73 ;
int V_38 ;
V_38 = F_21 ( V_8 , V_26 , V_66 , V_54 ) ;
F_30 ( V_8 , & V_26 -> V_31 ) ;
if ( V_38 == 0 ) {
V_26 = F_31 ( V_8 , V_70 , V_54 ) ;
if ( F_25 ( V_26 ) )
V_38 = F_32 ( V_26 ) ;
}
V_69 -> V_73 = V_26 ;
return V_38 ;
}
int F_33 ( const struct V_7 * V_8 ,
char * V_74 , T_2 V_75 ,
void * V_67 )
{
char * V_76 ;
int V_11 = 0 ;
while ( 1 ) {
V_76 = F_34 ( & V_74 , L_1 ) ;
if ( V_76 == NULL )
break;
if ( V_76 [ 0 ] == 0 ) {
if ( ! V_74 || V_74 [ 0 ] == '\0' )
break;
continue;
}
V_11 = V_75 ( V_8 , V_76 , V_67 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
struct V_25 *
F_35 ( const struct V_7 * V_8 , struct V_1 * V_70 ,
const char * V_74 , struct V_53 * V_54 )
{
struct V_77 * V_78 = F_36 ( V_8 ) ;
struct V_68 * V_69 = & V_78 -> V_79 ;
struct V_25 * V_26 ;
char * V_80 = V_78 -> V_81 ;
int V_38 ;
V_69 -> V_71 = V_70 ;
V_69 -> V_72 = V_54 ;
strncpy ( V_80 , V_74 , V_82 ) ;
V_80 [ V_82 - 1 ] = '\0' ;
V_38 = V_70 -> V_83 -> V_84 ( V_8 , V_70 , V_54 ) ;
if ( V_38 == 0 ) {
V_26 = F_31 ( V_8 , V_70 , V_54 ) ;
if ( ! F_25 ( V_26 ) ) {
V_69 -> V_73 = V_26 ;
V_38 = F_33 ( V_8 , V_80 , F_29 , V_69 ) ;
if ( V_38 != 0 )
V_26 = F_28 ( V_38 ) ;
else
V_26 = V_69 -> V_73 ;
}
} else {
V_26 = F_28 ( V_38 ) ;
}
return V_26 ;
}
static struct V_25 * F_37 ( const struct V_7 * V_8 ,
struct V_1 * V_70 ,
struct V_25 * V_85 ,
const char * V_52 ,
struct V_53 * V_54 )
{
struct V_25 * V_86 ;
int V_38 ;
V_38 = F_21 ( V_8 , V_85 , V_52 , V_54 ) ;
if ( V_38 == 0 ) {
V_86 = F_31 ( V_8 , V_70 , V_54 ) ;
}
else
V_86 = F_28 ( V_38 ) ;
return V_86 ;
}
struct V_25 * F_38 ( const struct V_7 * V_8 ,
struct V_1 * V_70 ,
const char * V_87 ,
const char * V_88 ,
struct V_53 * V_54 )
{
struct V_25 * V_89 ;
struct V_25 * V_51 ;
V_51 = F_35 ( V_8 , V_70 , V_87 , V_54 ) ;
if ( ! F_25 ( V_51 ) ) {
V_89 = F_37 ( V_8 , V_70 , V_51 ,
V_88 , V_54 ) ;
F_30 ( V_8 , & V_51 -> V_31 ) ;
} else {
V_89 = V_51 ;
}
return V_89 ;
}
struct V_25 * F_39 ( const struct V_7 * V_8 ,
struct V_1 * V_70 ,
const struct V_53 * V_54 ,
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_25 * V_94 ;
struct V_9 * V_10 ;
int V_11 ;
V_63 ;
V_94 = F_31 ( V_8 , V_70 , V_54 ) ;
if ( F_25 ( V_94 ) )
RETURN ( V_94 ) ;
F_26 ( V_94 != NULL ) ;
if ( F_40 ( V_94 ) )
RETURN ( V_94 ) ;
V_10 = F_41 ( V_8 , V_70 ) ;
if ( F_25 ( V_10 ) )
GOTO ( V_95 , V_11 = F_32 ( V_10 ) ) ;
V_11 = F_42 ( V_8 , V_94 , V_93 , NULL , V_91 , V_10 ) ;
if ( V_11 )
GOTO ( V_96 , V_11 ) ;
V_11 = F_43 ( V_8 , V_70 , V_10 ) ;
if ( V_11 )
GOTO ( V_96 , V_11 ) ;
F_44 ( V_8 , V_94 , 0 ) ;
if ( F_40 ( V_94 ) )
GOTO ( V_97 , V_11 = 0 ) ;
F_45 ( V_98 , L_2 V_99 L_3 , F_46 ( V_54 ) ) ;
V_11 = F_47 ( V_8 , V_94 , V_93 , NULL , V_91 , V_10 ) ;
if ( V_11 )
GOTO ( V_97 , V_11 ) ;
F_26 ( F_40 ( V_94 ) ) ;
V_97:
F_48 ( V_8 , V_94 ) ;
V_96:
F_49 ( V_8 , V_70 , V_10 ) ;
V_95:
if ( V_11 ) {
F_30 ( V_8 , & V_94 -> V_31 ) ;
RETURN ( F_28 ( V_11 ) ) ;
}
RETURN ( V_94 ) ;
}
int F_50 ( void )
{
int V_38 ;
F_51 ( & V_56 ) ;
V_38 = F_52 ( & V_56 ) ;
return V_38 ;
}
void F_53 ( void )
{
F_54 ( & V_56 ) ;
}
int F_55 ( const struct V_7 * V_8 , struct V_25 * V_70 ,
struct V_100 * V_101 , T_3 * V_102 )
{
F_56 ( V_70 != NULL , L_4 ) ;
return V_70 -> V_103 -> V_104 ( V_8 , V_70 , V_101 , V_102 , V_57 ) ;
}
int F_57 ( const struct V_7 * V_8 , struct V_25 * V_70 ,
struct V_100 * V_101 , T_3 * V_102 )
{
int V_11 ;
F_56 ( V_70 != NULL , L_4 ) ;
V_11 = V_70 -> V_103 -> V_104 ( V_8 , V_70 , V_101 , V_102 , V_57 ) ;
if ( V_11 == V_101 -> V_105 )
V_11 = 0 ;
else if ( V_11 >= 0 )
V_11 = - V_106 ;
return V_11 ;
}
int F_58 ( const struct V_7 * V_8 , struct V_25 * V_70 ,
const struct V_100 * V_101 , T_3 * V_102 , struct V_9 * V_10 )
{
int V_11 ;
F_56 ( V_70 != NULL , L_5 ) ;
F_26 ( V_10 != NULL ) ;
F_26 ( V_70 -> V_103 ) ;
F_26 ( V_70 -> V_103 -> V_107 ) ;
V_11 = V_70 -> V_103 -> V_107 ( V_8 , V_70 , V_101 , V_102 , V_10 , V_57 , 1 ) ;
if ( V_11 == V_101 -> V_105 )
V_11 = 0 ;
else if ( V_11 >= 0 )
V_11 = - V_106 ;
return V_11 ;
}
int F_59 ( const struct V_7 * V_8 , struct V_25 * V_86 ,
struct V_9 * V_10 )
{
struct V_100 V_108 ;
char * V_109 = V_110 ;
F_26 ( V_86 ) ;
V_108 . V_111 = NULL ;
V_108 . V_105 = sizeof( V_112 ) ;
return F_60 ( V_8 , V_86 , & V_108 , V_109 , 0 , V_10 ) ;
}
void F_61 ( const struct V_7 * V_8 , struct V_25 * V_86 ,
V_112 V_113 , struct V_9 * V_10 )
{
struct V_100 V_108 ;
char * V_109 = V_110 ;
int V_11 ;
F_26 ( V_86 ) ;
V_108 . V_111 = & V_113 ;
V_108 . V_105 = sizeof( V_113 ) ;
V_11 = F_62 ( V_8 , V_86 , & V_108 , V_109 , 0 , V_10 , V_57 ) ;
if ( V_11 < 0 )
F_45 ( V_114 , L_6 , V_11 ) ;
return;
}
V_112 F_63 ( const struct V_7 * V_8 , struct V_25 * V_86 )
{
struct V_100 V_108 ;
char * V_109 = V_110 ;
V_112 V_113 ;
int V_11 ;
F_26 ( V_86 ) ;
V_108 . V_111 = & V_113 ;
V_108 . V_105 = sizeof( V_113 ) ;
V_11 = F_64 ( V_8 , V_86 , & V_108 , V_109 , V_57 ) ;
if ( V_11 != sizeof( V_113 ) ) {
F_45 ( V_114 , L_7 , V_11 ) ;
V_113 = 0 ;
}
return V_113 ;
}
static inline const struct V_115 * F_65 ( T_4 V_116 ,
T_1 V_37 )
{
if ( V_116 == V_117 ) {
if ( ! F_66 ( V_37 ) )
return F_28 ( - V_65 ) ;
return & V_118 ;
} else if ( V_116 == V_119 ) {
if ( ! F_66 ( V_37 ) )
return F_28 ( - V_65 ) ;
return & V_120 ;
} else if ( V_116 >= V_121 ) {
if ( ! F_67 ( V_37 ) )
return F_28 ( - V_58 ) ;
return & V_35 ;
}
return F_28 ( - V_122 ) ;
}
static int F_68 ( const struct V_7 * V_8 , union V_123 * V_124 ,
int V_125 , const struct V_126 * V_127 ,
struct V_128 * V_129 , T_1 V_130 , void * V_131 )
{
struct V_132 * V_133 = (struct V_132 * ) V_131 ;
struct V_134 * V_135 = & V_124 -> V_136 ;
char * V_66 ;
int V_11 , V_137 ;
V_63 ;
F_26 ( ( V_133 -> V_138 & V_139 ) == 0 ) ;
F_26 ( ( V_133 -> V_138 & V_140 ) == 0 ) ;
memset ( V_135 , 0 , V_141 ) ;
V_135 -> V_142 = V_143 ;
V_125 -= V_141 ;
V_137 = V_133 -> V_144 + V_133 -> V_145 ;
if ( ( V_133 -> V_138 & V_146 ) == 0 )
V_137 += sizeof( T_4 ) ;
V_66 = V_135 -> V_147 ;
do {
char * V_148 = V_66 ;
struct V_56 * V_149 ;
T_4 V_150 ;
V_150 = V_127 -> V_151 ( V_8 , V_129 ) ;
V_133 -> V_152 = V_150 ;
if ( F_69 ( V_153 ) ) {
if ( V_135 -> V_154 != 0 )
GOTO ( V_95 , V_11 = 0 ) ;
}
if ( V_125 < V_137 ) {
if ( V_135 -> V_154 == 0 )
GOTO ( V_95 , V_11 = - V_155 ) ;
GOTO ( V_95 , V_11 = 0 ) ;
}
if ( ( V_133 -> V_138 & V_146 ) == 0 ) {
memcpy ( V_148 , & V_150 , sizeof( V_150 ) ) ;
V_148 += sizeof( V_150 ) ;
}
F_26 ( V_127 -> V_156 ( V_8 , V_129 ) == V_133 -> V_145 ) ;
V_149 = V_127 -> V_149 ( V_8 , V_129 ) ;
memcpy ( V_148 , V_149 , V_133 -> V_145 ) ;
V_148 += V_133 -> V_145 ;
V_11 = V_127 -> V_157 ( V_8 , V_129 , (struct V_55 * ) V_148 , V_130 ) ;
if ( V_11 != - V_158 ) {
if ( V_11 != 0 )
GOTO ( V_95 , V_11 ) ;
V_135 -> V_154 ++ ;
if ( F_70 ( V_135 -> V_154 == 1 && V_133 -> V_159 == 0 ) )
V_133 -> V_160 = V_150 ;
V_66 = V_148 + V_133 -> V_144 ;
V_125 -= V_137 ;
}
do {
V_11 = V_127 -> V_161 ( V_8 , V_129 ) ;
} while ( V_11 == - V_158 );
} while ( V_11 == 0 );
GOTO ( V_95 , V_11 ) ;
V_95:
if ( V_11 >= 0 && V_135 -> V_154 > 0 )
V_133 -> V_159 ++ ;
if ( V_11 > 0 )
V_133 -> V_152 = V_162 ;
return V_11 ;
}
int F_71 ( const struct V_7 * V_8 , struct V_25 * V_26 ,
const struct V_163 * V_164 , T_5 V_165 ,
void * V_131 )
{
struct V_128 * V_129 ;
const struct V_126 * V_127 ;
unsigned int V_166 , V_125 , V_167 = 0 ;
int V_11 ;
V_63 ;
F_26 ( V_164 -> V_168 != NULL ) ;
F_26 ( V_26 -> V_32 != NULL ) ;
V_125 = V_164 -> V_169 ;
if ( V_125 <= 0 )
RETURN ( - V_106 ) ;
V_127 = & V_26 -> V_32 -> V_170 ;
F_26 ( V_127 != NULL ) ;
V_129 = V_127 -> V_171 ( V_8 , V_26 , V_164 -> V_172 , V_57 ) ;
if ( F_25 ( V_129 ) )
RETURN ( F_32 ( V_129 ) ) ;
V_11 = V_127 -> V_173 ( V_8 , V_129 , V_164 -> V_174 ) ;
if ( V_11 == 0 ) {
V_11 = V_127 -> V_161 ( V_8 , V_129 ) ;
} else if ( V_11 > 0 ) {
V_11 = 0 ;
}
for ( V_166 = 0 ; V_11 == 0 && V_125 > 0 ; V_166 ++ ) {
union V_123 * V_124 ;
int V_175 ;
F_26 ( V_166 < V_164 -> V_176 ) ;
V_124 = F_72 ( V_164 -> V_168 [ V_166 ] ) ;
for ( V_175 = 0 ; V_175 < V_177 ; V_175 ++ , V_124 ++ , V_125 -= V_178 ) {
V_11 = V_165 ( V_8 , V_124 , F_73 ( int , V_125 , V_178 ) ,
V_127 , V_129 , V_164 -> V_172 , V_131 ) ;
if ( V_11 < 0 )
break;
V_167 ++ ;
if ( V_11 > 0 )
break;
}
F_74 ( V_164 -> V_168 [ V_175 ] ) ;
}
V_127 -> V_179 ( V_8 , V_129 ) ;
V_127 -> V_180 ( V_8 , V_129 ) ;
if ( V_11 >= 0 )
V_11 = F_73 (unsigned int, nlupgs * LU_PAGE_SIZE, rdpg->rp_count) ;
RETURN ( V_11 ) ;
}
int F_75 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_132 * V_133 , const struct V_163 * V_164 )
{
const struct V_115 * V_181 ;
struct V_25 * V_26 ;
int V_11 ;
V_63 ;
if ( V_164 -> V_169 <= 0 && ( V_164 -> V_169 & ( V_178 - 1 ) ) != 0 )
RETURN ( - V_106 ) ;
if ( F_76 ( & V_133 -> V_182 ) >= V_121 )
RETURN ( - V_122 ) ;
if ( ! F_77 ( & V_133 -> V_182 ) )
RETURN ( - V_183 ) ;
V_26 = F_31 ( V_8 , V_2 , & V_133 -> V_182 ) ;
if ( F_25 ( V_26 ) )
RETURN ( F_32 ( V_26 ) ) ;
if ( F_40 ( V_26 ) == 0 )
GOTO ( V_95 , V_11 = - V_65 ) ;
V_181 = F_65 ( F_76 ( & V_133 -> V_182 ) ,
F_78 ( & V_26 -> V_31 ) ) ;
if ( F_25 ( V_181 ) )
GOTO ( V_95 , V_11 = F_32 ( V_181 ) ) ;
if ( V_26 -> V_32 == NULL ) {
V_11 = V_26 -> V_33 -> V_34 ( V_8 , V_26 , V_181 ) ;
if ( V_11 )
GOTO ( V_95 , V_11 ) ;
}
V_133 -> V_138 &= V_146 ;
V_133 -> V_145 = V_181 -> V_184 ;
if ( ( V_181 -> V_185 & V_186 ) != 0 ) {
V_133 -> V_138 |= V_139 ;
GOTO ( V_95 , V_11 = - V_122 ) ;
}
V_133 -> V_144 = V_181 -> V_187 ;
if ( ( V_181 -> V_185 & V_188 ) != 0 ) {
V_133 -> V_138 |= V_140 ;
GOTO ( V_95 , V_11 = - V_122 ) ;
}
if ( ( V_181 -> V_185 & V_189 ) != 0 )
V_133 -> V_138 |= V_190 ;
F_79 ( V_8 , V_26 , 0 ) ;
V_133 -> V_191 = F_63 ( V_8 , V_26 ) ;
V_11 = F_71 ( V_8 , V_26 , V_164 , F_68 , V_133 ) ;
F_80 ( V_8 , V_26 ) ;
if ( V_11 == 0 ) {
F_26 ( V_133 -> V_159 == 0 ) ;
V_133 -> V_152 = V_162 ;
}
GOTO ( V_95 , V_11 ) ;
V_95:
F_30 ( V_8 , & V_26 -> V_31 ) ;
return V_11 ;
}
int F_81 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , L_8 ,
( unsigned ) V_198 . V_199 ) ;
}
return V_11 ;
}
int F_83 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
T_1 V_200 = V_198 . V_199 >> 10 ;
T_4 V_38 = V_198 . V_201 ;
while ( V_200 >>= 1 )
V_38 <<= 1 ;
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , V_202 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_84 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
T_1 V_200 = V_198 . V_199 >> 10 ;
T_4 V_38 = V_198 . V_203 ;
while ( V_200 >>= 1 )
V_38 <<= 1 ;
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , V_202 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_85 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
T_1 V_200 = V_198 . V_199 >> 10 ;
T_4 V_38 = V_198 . V_204 ;
while ( V_200 >>= 1 )
V_38 <<= 1 ;
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , V_202 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_86 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , V_202 L_3 , V_198 . V_205 ) ;
}
return V_11 ;
}
int F_87 ( char * V_192 , char * * V_193 , T_6 V_194 ,
int V_195 , int * V_196 , void * V_67 )
{
struct V_1 * V_70 = V_67 ;
struct V_197 V_198 ;
int V_11 = F_82 ( NULL , V_70 , & V_198 ) ;
if ( V_11 == 0 ) {
* V_196 = 1 ;
V_11 = snprintf ( V_192 , V_195 , V_202 L_3 , V_198 . V_206 ) ;
}
return V_11 ;
}
