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
V_61 = F_24 ( V_8 , V_59 , V_54 , NULL ) ;
if ( F_25 ( V_61 ) )
return ( void * ) V_61 ;
F_26 ( V_61 != NULL ) ;
F_6 (n, &lo->lo_header->loh_layers, lo_linkage) {
if ( V_62 -> V_63 == & V_2 -> V_24 )
return F_27 ( V_62 , struct V_25 , V_31 ) ;
}
return F_28 ( - V_64 ) ;
}
static int F_29 ( const struct V_7 * V_8 , const char * V_65 , void * V_66 )
{
struct V_67 * V_68 = V_66 ;
struct V_1 * V_69 = V_68 -> V_70 ;
struct V_53 * V_54 = V_68 -> V_71 ;
struct V_25 * V_26 = V_68 -> V_72 ;
int V_38 ;
V_38 = F_21 ( V_8 , V_26 , V_65 , V_54 ) ;
F_30 ( V_8 , & V_26 -> V_31 ) ;
if ( V_38 == 0 ) {
V_26 = F_31 ( V_8 , V_69 , V_54 ) ;
if ( F_25 ( V_26 ) )
V_38 = F_32 ( V_26 ) ;
}
V_68 -> V_72 = V_26 ;
return V_38 ;
}
int F_33 ( const struct V_7 * V_8 ,
char * V_73 , T_2 V_74 ,
void * V_66 )
{
char * V_75 ;
int V_11 = 0 ;
while ( 1 ) {
V_75 = F_34 ( & V_73 , L_1 ) ;
if ( V_75 == NULL )
break;
if ( V_75 [ 0 ] == 0 ) {
if ( ! V_73 || V_73 [ 0 ] == '\0' )
break;
continue;
}
V_11 = V_74 ( V_8 , V_75 , V_66 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
struct V_25 *
F_35 ( const struct V_7 * V_8 , struct V_1 * V_69 ,
const char * V_73 , struct V_53 * V_54 )
{
struct V_76 * V_77 = F_36 ( V_8 ) ;
struct V_67 * V_68 = & V_77 -> V_78 ;
struct V_25 * V_26 ;
char * V_79 = V_77 -> V_80 ;
int V_38 ;
V_68 -> V_70 = V_69 ;
V_68 -> V_71 = V_54 ;
strncpy ( V_79 , V_73 , V_81 ) ;
V_79 [ V_81 - 1 ] = '\0' ;
V_38 = V_69 -> V_82 -> V_83 ( V_8 , V_69 , V_54 ) ;
if ( V_38 == 0 ) {
V_26 = F_31 ( V_8 , V_69 , V_54 ) ;
if ( ! F_25 ( V_26 ) ) {
V_68 -> V_72 = V_26 ;
V_38 = F_33 ( V_8 , V_79 , F_29 , V_68 ) ;
if ( V_38 != 0 )
V_26 = F_28 ( V_38 ) ;
else
V_26 = V_68 -> V_72 ;
}
} else {
V_26 = F_28 ( V_38 ) ;
}
return V_26 ;
}
static struct V_25 * F_37 ( const struct V_7 * V_8 ,
struct V_1 * V_69 ,
struct V_25 * V_84 ,
const char * V_52 ,
struct V_53 * V_54 )
{
struct V_25 * V_85 ;
int V_38 ;
V_38 = F_21 ( V_8 , V_84 , V_52 , V_54 ) ;
if ( V_38 == 0 ) {
V_85 = F_31 ( V_8 , V_69 , V_54 ) ;
}
else
V_85 = F_28 ( V_38 ) ;
return V_85 ;
}
struct V_25 * F_38 ( const struct V_7 * V_8 ,
struct V_1 * V_69 ,
const char * V_86 ,
const char * V_87 ,
struct V_53 * V_54 )
{
struct V_25 * V_88 ;
struct V_25 * V_51 ;
V_51 = F_35 ( V_8 , V_69 , V_86 , V_54 ) ;
if ( ! F_25 ( V_51 ) ) {
V_88 = F_37 ( V_8 , V_69 , V_51 ,
V_87 , V_54 ) ;
F_30 ( V_8 , & V_51 -> V_31 ) ;
} else {
V_88 = V_51 ;
}
return V_88 ;
}
struct V_25 * F_39 ( const struct V_7 * V_8 ,
struct V_1 * V_69 ,
const struct V_53 * V_54 ,
struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_25 * V_93 ;
struct V_9 * V_10 ;
int V_11 ;
V_93 = F_31 ( V_8 , V_69 , V_54 ) ;
if ( F_25 ( V_93 ) )
return V_93 ;
F_26 ( V_93 != NULL ) ;
if ( F_40 ( V_93 ) )
return V_93 ;
V_10 = F_41 ( V_8 , V_69 ) ;
if ( F_25 ( V_10 ) )
GOTO ( V_94 , V_11 = F_32 ( V_10 ) ) ;
V_11 = F_42 ( V_8 , V_93 , V_92 , NULL , V_90 , V_10 ) ;
if ( V_11 )
GOTO ( V_95 , V_11 ) ;
V_11 = F_43 ( V_8 , V_69 , V_10 ) ;
if ( V_11 )
GOTO ( V_95 , V_11 ) ;
F_44 ( V_8 , V_93 , 0 ) ;
if ( F_40 ( V_93 ) )
GOTO ( V_96 , V_11 = 0 ) ;
F_45 ( V_97 , L_2 V_98 L_3 , F_46 ( V_54 ) ) ;
V_11 = F_47 ( V_8 , V_93 , V_92 , NULL , V_90 , V_10 ) ;
if ( V_11 )
GOTO ( V_96 , V_11 ) ;
F_26 ( F_40 ( V_93 ) ) ;
V_96:
F_48 ( V_8 , V_93 ) ;
V_95:
F_49 ( V_8 , V_69 , V_10 ) ;
V_94:
if ( V_11 ) {
F_30 ( V_8 , & V_93 -> V_31 ) ;
return F_28 ( V_11 ) ;
}
return V_93 ;
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
int F_55 ( const struct V_7 * V_8 , struct V_25 * V_69 ,
struct V_99 * V_100 , T_3 * V_101 )
{
F_56 ( V_69 != NULL , L_4 ) ;
return V_69 -> V_102 -> V_103 ( V_8 , V_69 , V_100 , V_101 , V_57 ) ;
}
int F_57 ( const struct V_7 * V_8 , struct V_25 * V_69 ,
struct V_99 * V_100 , T_3 * V_101 )
{
int V_11 ;
F_56 ( V_69 != NULL , L_4 ) ;
V_11 = V_69 -> V_102 -> V_103 ( V_8 , V_69 , V_100 , V_101 , V_57 ) ;
if ( V_11 == V_100 -> V_104 )
V_11 = 0 ;
else if ( V_11 >= 0 )
V_11 = - V_105 ;
return V_11 ;
}
int F_58 ( const struct V_7 * V_8 , struct V_25 * V_69 ,
const struct V_99 * V_100 , T_3 * V_101 , struct V_9 * V_10 )
{
int V_11 ;
F_56 ( V_69 != NULL , L_5 ) ;
F_26 ( V_10 != NULL ) ;
F_26 ( V_69 -> V_102 ) ;
F_26 ( V_69 -> V_102 -> V_106 ) ;
V_11 = V_69 -> V_102 -> V_106 ( V_8 , V_69 , V_100 , V_101 , V_10 , V_57 , 1 ) ;
if ( V_11 == V_100 -> V_104 )
V_11 = 0 ;
else if ( V_11 >= 0 )
V_11 = - V_105 ;
return V_11 ;
}
int F_59 ( const struct V_7 * V_8 , struct V_25 * V_85 ,
struct V_9 * V_10 )
{
struct V_99 V_107 ;
char * V_108 = V_109 ;
F_26 ( V_85 ) ;
V_107 . V_110 = NULL ;
V_107 . V_104 = sizeof( V_111 ) ;
return F_60 ( V_8 , V_85 , & V_107 , V_108 , 0 , V_10 ) ;
}
void F_61 ( const struct V_7 * V_8 , struct V_25 * V_85 ,
V_111 V_112 , struct V_9 * V_10 )
{
struct V_99 V_107 ;
char * V_108 = V_109 ;
int V_11 ;
F_26 ( V_85 ) ;
V_107 . V_110 = & V_112 ;
V_107 . V_104 = sizeof( V_112 ) ;
V_11 = F_62 ( V_8 , V_85 , & V_107 , V_108 , 0 , V_10 , V_57 ) ;
if ( V_11 < 0 )
F_45 ( V_113 , L_6 , V_11 ) ;
return;
}
V_111 F_63 ( const struct V_7 * V_8 , struct V_25 * V_85 )
{
struct V_99 V_107 ;
char * V_108 = V_109 ;
V_111 V_112 ;
int V_11 ;
F_26 ( V_85 ) ;
V_107 . V_110 = & V_112 ;
V_107 . V_104 = sizeof( V_112 ) ;
V_11 = F_64 ( V_8 , V_85 , & V_107 , V_108 , V_57 ) ;
if ( V_11 != sizeof( V_112 ) ) {
F_45 ( V_113 , L_7 , V_11 ) ;
V_112 = 0 ;
}
return V_112 ;
}
static inline const struct V_114 * F_65 ( T_4 V_115 ,
T_1 V_37 )
{
if ( V_115 == V_116 ) {
if ( ! F_66 ( V_37 ) )
return F_28 ( - V_64 ) ;
return & V_117 ;
} else if ( V_115 == V_118 ) {
if ( ! F_66 ( V_37 ) )
return F_28 ( - V_64 ) ;
return & V_119 ;
} else if ( V_115 >= V_120 ) {
if ( ! F_67 ( V_37 ) )
return F_28 ( - V_58 ) ;
return & V_35 ;
}
return F_28 ( - V_121 ) ;
}
static int F_68 ( const struct V_7 * V_8 , union V_122 * V_123 ,
int V_124 , const struct V_125 * V_126 ,
struct V_127 * V_128 , T_1 V_129 , void * V_130 )
{
struct V_131 * V_132 = (struct V_131 * ) V_130 ;
struct V_133 * V_134 = & V_123 -> V_135 ;
char * V_65 ;
int V_11 , V_136 ;
F_26 ( ( V_132 -> V_137 & V_138 ) == 0 ) ;
F_26 ( ( V_132 -> V_137 & V_139 ) == 0 ) ;
memset ( V_134 , 0 , V_140 ) ;
V_134 -> V_141 = V_142 ;
V_124 -= V_140 ;
V_136 = V_132 -> V_143 + V_132 -> V_144 ;
if ( ( V_132 -> V_137 & V_145 ) == 0 )
V_136 += sizeof( T_4 ) ;
V_65 = V_134 -> V_146 ;
do {
char * V_147 = V_65 ;
struct V_56 * V_148 ;
T_4 V_149 ;
V_149 = V_126 -> V_150 ( V_8 , V_128 ) ;
V_132 -> V_151 = V_149 ;
if ( F_69 ( V_152 ) ) {
if ( V_134 -> V_153 != 0 )
GOTO ( V_94 , V_11 = 0 ) ;
}
if ( V_124 < V_136 ) {
if ( V_134 -> V_153 == 0 )
GOTO ( V_94 , V_11 = - V_154 ) ;
GOTO ( V_94 , V_11 = 0 ) ;
}
if ( ( V_132 -> V_137 & V_145 ) == 0 ) {
memcpy ( V_147 , & V_149 , sizeof( V_149 ) ) ;
V_147 += sizeof( V_149 ) ;
}
F_26 ( V_126 -> V_155 ( V_8 , V_128 ) == V_132 -> V_144 ) ;
V_148 = V_126 -> V_148 ( V_8 , V_128 ) ;
memcpy ( V_147 , V_148 , V_132 -> V_144 ) ;
V_147 += V_132 -> V_144 ;
V_11 = V_126 -> V_156 ( V_8 , V_128 , (struct V_55 * ) V_147 , V_129 ) ;
if ( V_11 != - V_157 ) {
if ( V_11 != 0 )
GOTO ( V_94 , V_11 ) ;
V_134 -> V_153 ++ ;
if ( F_70 ( V_134 -> V_153 == 1 && V_132 -> V_158 == 0 ) )
V_132 -> V_159 = V_149 ;
V_65 = V_147 + V_132 -> V_143 ;
V_124 -= V_136 ;
}
do {
V_11 = V_126 -> V_160 ( V_8 , V_128 ) ;
} while ( V_11 == - V_157 );
} while ( V_11 == 0 );
GOTO ( V_94 , V_11 ) ;
V_94:
if ( V_11 >= 0 && V_134 -> V_153 > 0 )
V_132 -> V_158 ++ ;
if ( V_11 > 0 )
V_132 -> V_151 = V_161 ;
return V_11 ;
}
int F_71 ( const struct V_7 * V_8 , struct V_25 * V_26 ,
const struct V_162 * V_163 , T_5 V_164 ,
void * V_130 )
{
struct V_127 * V_128 ;
const struct V_125 * V_126 ;
unsigned int V_165 , V_124 , V_166 = 0 ;
int V_11 ;
F_26 ( V_163 -> V_167 != NULL ) ;
F_26 ( V_26 -> V_32 != NULL ) ;
V_124 = V_163 -> V_168 ;
if ( V_124 <= 0 )
return - V_105 ;
V_126 = & V_26 -> V_32 -> V_169 ;
F_26 ( V_126 != NULL ) ;
V_128 = V_126 -> V_170 ( V_8 , V_26 , V_163 -> V_171 , V_57 ) ;
if ( F_25 ( V_128 ) )
return F_32 ( V_128 ) ;
V_11 = V_126 -> V_172 ( V_8 , V_128 , V_163 -> V_173 ) ;
if ( V_11 == 0 ) {
V_11 = V_126 -> V_160 ( V_8 , V_128 ) ;
} else if ( V_11 > 0 ) {
V_11 = 0 ;
}
for ( V_165 = 0 ; V_11 == 0 && V_124 > 0 ; V_165 ++ ) {
union V_122 * V_123 ;
int V_174 ;
F_26 ( V_165 < V_163 -> V_175 ) ;
V_123 = F_72 ( V_163 -> V_167 [ V_165 ] ) ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ , V_123 ++ , V_124 -= V_177 ) {
V_11 = V_164 ( V_8 , V_123 , F_73 ( int , V_124 , V_177 ) ,
V_126 , V_128 , V_163 -> V_171 , V_130 ) ;
if ( V_11 < 0 )
break;
V_166 ++ ;
if ( V_11 > 0 )
break;
}
F_74 ( V_163 -> V_167 [ V_174 ] ) ;
}
V_126 -> V_178 ( V_8 , V_128 ) ;
V_126 -> V_179 ( V_8 , V_128 ) ;
if ( V_11 >= 0 )
V_11 = F_73 (unsigned int, nlupgs * LU_PAGE_SIZE, rdpg->rp_count) ;
return V_11 ;
}
int F_75 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_131 * V_132 , const struct V_162 * V_163 )
{
const struct V_114 * V_180 ;
struct V_25 * V_26 ;
int V_11 ;
if ( V_163 -> V_168 <= 0 && ( V_163 -> V_168 & ( V_177 - 1 ) ) != 0 )
return - V_105 ;
if ( F_76 ( & V_132 -> V_181 ) >= V_120 )
return - V_121 ;
if ( ! F_77 ( & V_132 -> V_181 ) )
return - V_182 ;
V_26 = F_31 ( V_8 , V_2 , & V_132 -> V_181 ) ;
if ( F_25 ( V_26 ) )
return F_32 ( V_26 ) ;
if ( F_40 ( V_26 ) == 0 )
GOTO ( V_94 , V_11 = - V_64 ) ;
V_180 = F_65 ( F_76 ( & V_132 -> V_181 ) ,
F_78 ( & V_26 -> V_31 ) ) ;
if ( F_25 ( V_180 ) )
GOTO ( V_94 , V_11 = F_32 ( V_180 ) ) ;
if ( V_26 -> V_32 == NULL ) {
V_11 = V_26 -> V_33 -> V_34 ( V_8 , V_26 , V_180 ) ;
if ( V_11 )
GOTO ( V_94 , V_11 ) ;
}
V_132 -> V_137 &= V_145 ;
V_132 -> V_144 = V_180 -> V_183 ;
if ( ( V_180 -> V_184 & V_185 ) != 0 ) {
V_132 -> V_137 |= V_138 ;
GOTO ( V_94 , V_11 = - V_121 ) ;
}
V_132 -> V_143 = V_180 -> V_186 ;
if ( ( V_180 -> V_184 & V_187 ) != 0 ) {
V_132 -> V_137 |= V_139 ;
GOTO ( V_94 , V_11 = - V_121 ) ;
}
if ( ( V_180 -> V_184 & V_188 ) != 0 )
V_132 -> V_137 |= V_189 ;
F_79 ( V_8 , V_26 , 0 ) ;
V_132 -> V_190 = F_63 ( V_8 , V_26 ) ;
V_11 = F_71 ( V_8 , V_26 , V_163 , F_68 , V_132 ) ;
F_80 ( V_8 , V_26 ) ;
if ( V_11 == 0 ) {
F_26 ( V_132 -> V_158 == 0 ) ;
V_132 -> V_151 = V_161 ;
}
GOTO ( V_94 , V_11 ) ;
V_94:
F_30 ( V_8 , & V_26 -> V_31 ) ;
return V_11 ;
}
int F_81 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , L_8 ,
( unsigned ) V_197 . V_198 ) ;
}
return V_11 ;
}
int F_83 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
T_1 V_199 = V_197 . V_198 >> 10 ;
T_4 V_38 = V_197 . V_200 ;
while ( V_199 >>= 1 )
V_38 <<= 1 ;
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , V_201 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_84 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
T_1 V_199 = V_197 . V_198 >> 10 ;
T_4 V_38 = V_197 . V_202 ;
while ( V_199 >>= 1 )
V_38 <<= 1 ;
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , V_201 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_85 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
T_1 V_199 = V_197 . V_198 >> 10 ;
T_4 V_38 = V_197 . V_203 ;
while ( V_199 >>= 1 )
V_38 <<= 1 ;
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , V_201 L_3 , V_38 ) ;
}
return V_11 ;
}
int F_86 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , V_201 L_3 , V_197 . V_204 ) ;
}
return V_11 ;
}
int F_87 ( char * V_191 , char * * V_192 , T_6 V_193 ,
int V_194 , int * V_195 , void * V_66 )
{
struct V_1 * V_69 = V_66 ;
struct V_196 V_197 ;
int V_11 = F_82 ( NULL , V_69 , & V_197 ) ;
if ( V_11 == 0 ) {
* V_195 = 1 ;
V_11 = snprintf ( V_191 , V_194 , V_201 L_3 , V_197 . V_205 ) ;
}
return V_11 ;
}
