int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * * V_4 ;
int V_5 = - V_6 ;
F_2 ( & V_7 ) ;
for ( V_4 = & V_8 ; ( V_3 = * V_4 ) != NULL ; V_4 = & V_3 -> V_9 )
if ( ! strcmp ( V_2 -> V_10 , V_3 -> V_10 ) )
goto V_11;
if ( V_2 -> V_12 == NULL )
V_2 -> V_12 = V_13 . V_12 ;
if ( V_2 -> V_14 == NULL ) {
if ( V_2 -> V_15 == NULL )
V_2 -> V_14 = V_13 . V_14 ;
else
goto V_16;
}
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = V_13 . V_15 ;
if ( V_2 -> V_17 ) {
const struct V_18 * V_19 = V_2 -> V_17 ;
if ( ! ( V_19 -> V_20 && V_19 -> V_21 && V_19 -> V_22 ) )
goto V_16;
if ( V_19 -> V_23 && ! ( V_19 -> V_24 && V_19 -> V_25 ) )
goto V_16;
}
V_2 -> V_9 = NULL ;
* V_4 = V_2 ;
V_5 = 0 ;
V_11:
F_3 ( & V_7 ) ;
return V_5 ;
V_16:
V_5 = - V_26 ;
goto V_11;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * * V_4 ;
int V_27 = - V_28 ;
F_2 ( & V_7 ) ;
for ( V_4 = & V_8 ; ( V_3 = * V_4 ) != NULL ; V_4 = & V_3 -> V_9 )
if ( V_3 == V_2 )
break;
if ( V_3 ) {
* V_4 = V_3 -> V_9 ;
V_3 -> V_9 = NULL ;
V_27 = 0 ;
}
F_3 ( & V_7 ) ;
return V_27 ;
}
void F_5 ( char * V_29 , T_1 V_30 )
{
F_6 ( & V_7 ) ;
F_7 ( V_29 , V_31 -> V_10 , V_30 ) ;
F_8 ( & V_7 ) ;
}
static struct V_1 * F_9 ( const char * V_29 )
{
struct V_1 * V_3 = NULL ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( ! strcmp ( V_29 , V_3 -> V_10 ) ) {
if ( ! F_10 ( V_3 -> V_32 ) )
V_3 = NULL ;
break;
}
}
return V_3 ;
}
int F_11 ( const char * V_29 )
{
const struct V_1 * V_33 ;
if ( ! F_12 ( V_34 ) )
return - V_35 ;
F_2 ( & V_7 ) ;
V_33 = F_9 ( V_29 ) ;
if ( ! V_33 ) {
F_3 ( & V_7 ) ;
F_13 ( L_1 , V_29 ) ;
F_2 ( & V_7 ) ;
V_33 = F_9 ( V_29 ) ;
}
if ( V_33 ) {
F_14 ( V_31 -> V_32 ) ;
V_31 = V_33 ;
}
F_3 ( & V_7 ) ;
return V_33 ? 0 : - V_28 ;
}
static int T_2 F_15 ( void )
{
return F_11 ( V_36 ) ;
}
static struct V_37 * F_16 ( struct V_37 * V_38 , T_3 V_39 )
{
struct V_37 * V_3 ;
if ( ! F_17 ( V_38 ) )
return ( V_38 -> V_39 == V_39 ? V_38 : NULL ) ;
if ( ! ( V_38 -> V_40 & V_41 ) &&
V_38 -> V_39 == V_39 )
return V_38 ;
F_18 (qdisc_dev(root)->qdisc_hash, q, hash, handle) {
if ( V_3 -> V_39 == V_39 )
return V_3 ;
}
return NULL ;
}
void F_19 ( struct V_37 * V_3 , bool V_42 )
{
if ( ( V_3 -> V_43 != V_44 ) && ! ( V_3 -> V_40 & V_45 ) ) {
F_20 () ;
F_21 ( F_17 ( V_3 ) -> V_46 , & V_3 -> V_47 , V_3 -> V_39 ) ;
if ( V_42 )
V_3 -> V_40 |= V_48 ;
}
}
void F_22 ( struct V_37 * V_3 )
{
if ( ( V_3 -> V_43 != V_44 ) && ! ( V_3 -> V_40 & V_45 ) ) {
F_20 () ;
F_23 ( & V_3 -> V_47 ) ;
}
}
struct V_37 * F_24 ( struct V_49 * V_50 , T_3 V_39 )
{
struct V_37 * V_3 ;
if ( ! V_39 )
return NULL ;
V_3 = F_16 ( V_50 -> V_51 , V_39 ) ;
if ( V_3 )
goto V_11;
if ( F_25 ( V_50 ) )
V_3 = F_16 (
F_25 ( V_50 ) -> V_52 ,
V_39 ) ;
V_11:
return V_3 ;
}
static struct V_37 * F_26 ( struct V_37 * V_53 , T_3 V_54 )
{
unsigned long V_55 ;
struct V_37 * V_22 ;
const struct V_18 * V_19 = V_53 -> V_33 -> V_17 ;
if ( V_19 == NULL )
return NULL ;
V_55 = V_19 -> V_20 ( V_53 , V_54 ) ;
if ( V_55 == 0 )
return NULL ;
V_22 = V_19 -> V_22 ( V_53 , V_55 ) ;
return V_22 ;
}
static struct V_1 * F_27 ( struct V_56 * V_57 )
{
struct V_1 * V_3 = NULL ;
if ( V_57 ) {
F_6 ( & V_7 ) ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
if ( F_28 ( V_57 , V_3 -> V_10 ) == 0 ) {
if ( ! F_10 ( V_3 -> V_32 ) )
V_3 = NULL ;
break;
}
}
F_8 ( & V_7 ) ;
}
return V_3 ;
}
static T_4 F_29 ( struct V_58 * V_59 , T_5 * V_60 )
{
int V_61 = F_30 ( V_59 -> V_62 , 48 ) ;
int V_63 = F_30 ( V_61 + 1 , 48 ) ;
int V_64 = V_61 >> V_59 -> V_65 ;
int V_66 = ( V_63 >> V_59 -> V_65 ) - 1 ;
if ( ( V_59 -> V_67 > ( 100000000 / 8 ) ) || ( V_60 [ 0 ] == 0 ) ) {
F_31 ( L_2 ) ;
return V_68 ;
}
if ( ( V_66 > V_64 ) && ( V_66 < 256 )
&& ( V_60 [ V_64 ] == V_60 [ V_66 ] ) ) {
F_31 ( L_3 ,
V_64 , V_66 , V_60 [ V_66 ] ) ;
return V_69 ;
}
return V_68 ;
}
struct V_70 * F_32 ( struct V_58 * V_59 ,
struct V_56 * V_71 )
{
struct V_70 * V_60 ;
if ( V_71 == NULL || V_59 -> V_67 == 0 || V_59 -> V_65 == 0 ||
F_33 ( V_71 ) != V_72 )
return NULL ;
for ( V_60 = V_73 ; V_60 ; V_60 = V_60 -> V_9 ) {
if ( ! memcmp ( & V_60 -> V_67 , V_59 , sizeof( struct V_58 ) ) &&
! memcmp ( & V_60 -> V_74 , F_34 ( V_71 ) , 1024 ) ) {
V_60 -> V_75 ++ ;
return V_60 ;
}
}
V_60 = F_35 ( sizeof( * V_60 ) , V_76 ) ;
if ( V_60 ) {
V_60 -> V_67 = * V_59 ;
V_60 -> V_75 = 1 ;
memcpy ( V_60 -> V_74 , F_34 ( V_71 ) , 1024 ) ;
if ( V_59 -> V_77 == V_78 )
V_59 -> V_77 = F_29 ( V_59 , V_60 -> V_74 ) ;
V_60 -> V_9 = V_73 ;
V_73 = V_60 ;
}
return V_60 ;
}
void F_36 ( struct V_70 * V_71 )
{
struct V_70 * V_60 , * * V_79 ;
if ( ! V_71 || -- V_71 -> V_75 )
return;
for ( V_79 = & V_73 ;
( V_60 = * V_79 ) != NULL ;
V_79 = & V_60 -> V_9 ) {
if ( V_60 == V_71 ) {
* V_79 = V_60 -> V_9 ;
F_37 ( V_60 ) ;
return;
}
}
}
static struct V_80 * F_38 ( struct V_56 * V_81 )
{
struct V_56 * V_82 [ V_83 + 1 ] ;
struct V_80 * V_84 ;
struct V_85 * V_86 ;
unsigned int V_87 = 0 ;
T_6 * V_71 = NULL ;
int V_27 ;
V_27 = F_39 ( V_82 , V_83 , V_81 , V_88 , NULL ) ;
if ( V_27 < 0 )
return F_40 ( V_27 ) ;
if ( ! V_82 [ V_89 ] )
return F_40 ( - V_26 ) ;
V_86 = F_34 ( V_82 [ V_89 ] ) ;
if ( V_86 -> V_87 > 0 ) {
if ( ! V_82 [ V_90 ] )
return F_40 ( - V_26 ) ;
V_71 = F_34 ( V_82 [ V_90 ] ) ;
V_87 = F_33 ( V_82 [ V_90 ] ) / sizeof( T_6 ) ;
}
if ( V_87 != V_86 -> V_87 || ( ! V_71 && V_87 > 0 ) )
return F_40 ( - V_26 ) ;
F_41 (stab, &qdisc_stab_list, list) {
if ( memcmp ( & V_84 -> V_91 , V_86 , sizeof( * V_86 ) ) )
continue;
if ( V_87 > 0 && memcmp ( V_84 -> V_74 , V_71 , V_87 * sizeof( T_6 ) ) )
continue;
V_84 -> V_75 ++ ;
return V_84 ;
}
V_84 = F_35 ( sizeof( * V_84 ) + V_87 * sizeof( T_6 ) , V_76 ) ;
if ( ! V_84 )
return F_40 ( - V_92 ) ;
V_84 -> V_75 = 1 ;
V_84 -> V_91 = * V_86 ;
if ( V_87 > 0 )
memcpy ( V_84 -> V_74 , V_71 , V_87 * sizeof( T_6 ) ) ;
F_42 ( & V_84 -> V_93 , & V_94 ) ;
return V_84 ;
}
static void F_43 ( struct V_95 * V_96 )
{
F_37 ( F_44 ( V_96 , struct V_80 , V_97 ) ) ;
}
void F_45 ( struct V_80 * V_71 )
{
if ( ! V_71 )
return;
if ( -- V_71 -> V_75 == 0 ) {
F_46 ( & V_71 -> V_93 ) ;
F_47 ( & V_71 -> V_97 , F_43 ) ;
}
}
static int F_48 ( struct V_98 * V_99 , struct V_80 * V_84 )
{
struct V_56 * V_100 ;
V_100 = F_49 ( V_99 , V_101 ) ;
if ( V_100 == NULL )
goto V_102;
if ( F_50 ( V_99 , V_89 , sizeof( V_84 -> V_91 ) , & V_84 -> V_91 ) )
goto V_102;
F_51 ( V_99 , V_100 ) ;
return V_99 -> V_30 ;
V_102:
return - 1 ;
}
void F_52 ( struct V_98 * V_99 ,
const struct V_80 * V_84 )
{
int V_103 , V_104 ;
V_103 = V_99 -> V_30 + V_84 -> V_91 . V_105 ;
if ( F_53 ( ! V_84 -> V_91 . V_87 ) )
goto V_11;
V_104 = V_103 + V_84 -> V_91 . V_106 ;
if ( F_53 ( V_104 < 0 ) )
V_104 = 0 ;
V_104 >>= V_84 -> V_91 . V_65 ;
if ( F_54 ( V_104 < V_84 -> V_91 . V_87 ) )
V_103 = V_84 -> V_74 [ V_104 ] ;
else
V_103 = V_84 -> V_74 [ V_84 -> V_91 . V_87 - 1 ] *
( V_104 / V_84 -> V_91 . V_87 ) +
V_84 -> V_74 [ V_104 % V_84 -> V_91 . V_87 ] ;
V_103 <<= V_84 -> V_91 . V_107 ;
V_11:
if ( F_53 ( V_103 < 1 ) )
V_103 = 1 ;
F_55 ( V_99 ) -> V_103 = V_103 ;
}
void F_56 ( const char * V_108 , struct V_37 * V_51 )
{
if ( ! ( V_51 -> V_40 & V_109 ) ) {
F_57 ( L_4 ,
V_108 , V_51 -> V_33 -> V_10 , V_51 -> V_39 >> 16 ) ;
V_51 -> V_40 |= V_109 ;
}
}
static enum V_110 F_58 ( struct V_111 * V_112 )
{
struct F_58 * V_113 = F_44 ( V_112 , struct F_58 ,
V_112 ) ;
F_59 () ;
F_60 ( F_61 ( V_113 -> V_51 ) ) ;
F_62 () ;
return V_114 ;
}
void F_63 ( struct F_58 * V_113 , struct V_37 * V_51 )
{
F_64 ( & V_113 -> V_112 , V_115 , V_116 ) ;
V_113 -> V_112 . V_117 = F_58 ;
V_113 -> V_51 = V_51 ;
}
void F_65 ( struct F_58 * V_113 , T_7 V_118 )
{
if ( F_66 ( V_119 ,
& F_67 ( V_113 -> V_51 ) -> V_120 ) )
return;
if ( V_113 -> V_121 == V_118 )
return;
V_113 -> V_121 = V_118 ;
F_68 ( & V_113 -> V_112 ,
F_69 ( V_118 ) ,
V_116 ) ;
}
void F_70 ( struct F_58 * V_113 )
{
F_71 ( & V_113 -> V_112 ) ;
}
static struct V_122 * F_72 ( unsigned int V_123 )
{
struct V_122 * V_124 ;
unsigned int V_125 ;
V_124 = F_73 ( V_123 , sizeof( struct V_122 ) , V_76 ) ;
if ( V_124 != NULL ) {
for ( V_125 = 0 ; V_125 < V_123 ; V_125 ++ )
F_74 ( & V_124 [ V_125 ] ) ;
}
return V_124 ;
}
void F_75 ( struct V_37 * V_126 , struct V_127 * V_128 )
{
struct V_129 * V_55 ;
struct V_130 * V_9 ;
struct V_122 * V_131 , * V_132 ;
unsigned int V_133 , V_134 , V_135 ;
unsigned int V_125 , V_124 ;
if ( V_128 -> V_136 * 4 <= V_128 -> V_137 * 3 )
return;
V_133 = V_128 -> V_137 * 2 ;
V_134 = V_133 - 1 ;
V_131 = F_72 ( V_133 ) ;
if ( V_131 == NULL )
return;
V_132 = V_128 -> V_47 ;
V_135 = V_128 -> V_137 ;
F_76 ( V_126 ) ;
for ( V_125 = 0 ; V_125 < V_135 ; V_125 ++ ) {
F_77 (cl, next, &ohash[i], hnode) {
V_124 = F_78 ( V_55 -> V_54 , V_134 ) ;
F_79 ( & V_55 -> V_138 , & V_131 [ V_124 ] ) ;
}
}
V_128 -> V_47 = V_131 ;
V_128 -> V_137 = V_133 ;
V_128 -> V_139 = V_134 ;
F_80 ( V_126 ) ;
F_81 ( V_132 ) ;
}
int F_82 ( struct V_127 * V_128 )
{
unsigned int V_140 = 4 ;
V_128 -> V_47 = F_72 ( V_140 ) ;
if ( V_128 -> V_47 == NULL )
return - V_92 ;
V_128 -> V_137 = V_140 ;
V_128 -> V_139 = V_140 - 1 ;
V_128 -> V_136 = 0 ;
return 0 ;
}
void F_83 ( struct V_127 * V_128 )
{
F_81 ( V_128 -> V_47 ) ;
}
void F_84 ( struct V_127 * V_128 ,
struct V_129 * V_55 )
{
unsigned int V_124 ;
F_85 ( & V_55 -> V_138 ) ;
V_124 = F_78 ( V_55 -> V_54 , V_128 -> V_139 ) ;
F_79 ( & V_55 -> V_138 , & V_128 -> V_47 [ V_124 ] ) ;
V_128 -> V_136 ++ ;
}
void F_86 ( struct V_127 * V_128 ,
struct V_129 * V_55 )
{
F_87 ( & V_55 -> V_138 ) ;
V_128 -> V_136 -- ;
}
static T_3 F_88 ( struct V_49 * V_50 )
{
int V_125 = 0x8000 ;
static T_3 V_141 = F_89 ( 0x80000000U , 0 ) ;
do {
V_141 += F_89 ( 0x10000U , 0 ) ;
if ( V_141 == F_89 ( V_44 , 0 ) )
V_141 = F_89 ( 0x80000000U , 0 ) ;
if ( ! F_24 ( V_50 , V_141 ) )
return V_141 ;
F_90 () ;
} while ( -- V_125 > 0 );
return 0 ;
}
void F_91 ( struct V_37 * V_126 , unsigned int V_123 ,
unsigned int V_30 )
{
const struct V_18 * V_19 ;
unsigned long V_55 ;
T_3 V_142 ;
bool V_143 ;
int V_144 ;
if ( V_123 == 0 && V_30 == 0 )
return;
V_144 = F_92 ( int , V_123 , 0 ) ;
F_59 () ;
while ( ( V_142 = V_126 -> V_43 ) ) {
if ( F_93 ( V_142 ) == F_93 ( V_145 ) )
break;
if ( V_126 -> V_40 & V_146 )
break;
V_143 = ! V_126 -> V_3 . V_147 && ! F_94 ( ! V_123 ) ;
V_126 = F_24 ( F_17 ( V_126 ) , F_93 ( V_142 ) ) ;
if ( V_126 == NULL ) {
F_94 ( V_142 != V_44 ) ;
break;
}
V_19 = V_126 -> V_33 -> V_17 ;
if ( V_143 && V_19 -> V_148 ) {
V_55 = V_19 -> V_20 ( V_126 , V_142 ) ;
V_19 -> V_148 ( V_126 , V_55 ) ;
}
V_126 -> V_3 . V_147 -= V_123 ;
V_126 -> V_149 . V_150 -= V_30 ;
F_95 ( V_126 , V_144 ) ;
}
F_62 () ;
}
static int F_96 ( struct V_98 * V_99 , struct V_37 * V_3 , T_3 V_151 ,
T_3 V_152 , T_3 V_153 , T_6 V_40 , int V_154 )
{
struct V_155 T_8 * V_156 = NULL ;
struct V_157 T_8 * V_158 = NULL ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
unsigned char * V_163 = F_97 ( V_99 ) ;
struct V_164 V_165 ;
struct V_80 * V_84 ;
T_5 V_147 ;
F_90 () ;
V_162 = F_98 ( V_99 , V_152 , V_153 , V_154 , sizeof( * V_160 ) , V_40 ) ;
if ( ! V_162 )
goto V_166;
V_160 = F_99 ( V_162 ) ;
V_160 -> V_167 = V_168 ;
V_160 -> V_169 = 0 ;
V_160 -> V_170 = 0 ;
V_160 -> V_171 = F_17 ( V_3 ) -> V_172 ;
V_160 -> V_173 = V_151 ;
V_160 -> V_174 = V_3 -> V_39 ;
V_160 -> V_175 = F_100 ( & V_3 -> V_75 ) ;
if ( F_101 ( V_99 , V_176 , V_3 -> V_33 -> V_10 ) )
goto V_102;
if ( V_3 -> V_33 -> V_177 && V_3 -> V_33 -> V_177 ( V_3 , V_99 ) < 0 )
goto V_102;
V_147 = V_3 -> V_3 . V_147 ;
V_84 = F_102 ( V_3 -> V_84 ) ;
if ( V_84 && F_48 ( V_99 , V_84 ) < 0 )
goto V_102;
if ( F_103 ( V_99 , V_178 , V_179 , V_180 ,
NULL , & V_165 , V_181 ) < 0 )
goto V_102;
if ( V_3 -> V_33 -> V_182 && V_3 -> V_33 -> V_182 ( V_3 , & V_165 ) < 0 )
goto V_102;
if ( F_104 ( V_3 ) ) {
V_156 = V_3 -> V_156 ;
V_158 = V_3 -> V_158 ;
}
if ( F_105 ( F_106 ( V_3 ) ,
& V_165 , V_156 , & V_3 -> V_183 ) < 0 ||
F_107 ( & V_165 , & V_3 -> V_184 ) < 0 ||
F_108 ( & V_165 , V_158 , & V_3 -> V_149 , V_147 ) < 0 )
goto V_102;
if ( F_109 ( & V_165 ) < 0 )
goto V_102;
V_162 -> V_185 = F_97 ( V_99 ) - V_163 ;
return V_99 -> V_30 ;
V_166:
V_102:
F_110 ( V_99 , V_163 ) ;
return - 1 ;
}
static bool F_111 ( struct V_37 * V_3 , bool V_186 )
{
if ( V_3 -> V_40 & V_41 )
return true ;
if ( ( V_3 -> V_40 & V_48 ) && ! V_186 )
return true ;
return false ;
}
static int F_112 ( struct V_187 * V_187 , struct V_98 * V_188 ,
struct V_161 * V_123 , T_3 V_151 ,
struct V_37 * V_189 , struct V_37 * V_190 )
{
struct V_98 * V_99 ;
T_3 V_152 = V_188 ? F_113 ( V_188 ) . V_152 : 0 ;
V_99 = F_114 ( V_191 , V_76 ) ;
if ( ! V_99 )
return - V_192 ;
if ( V_189 && ! F_111 ( V_189 , false ) ) {
if ( F_96 ( V_99 , V_189 , V_151 , V_152 , V_123 -> V_193 ,
0 , V_194 ) < 0 )
goto V_195;
}
if ( V_190 && ! F_111 ( V_190 , false ) ) {
if ( F_96 ( V_99 , V_190 , V_151 , V_152 , V_123 -> V_193 ,
V_189 ? V_196 : 0 , V_197 ) < 0 )
goto V_195;
}
if ( V_99 -> V_30 )
return F_115 ( V_99 , V_187 , V_152 , V_198 ,
V_123 -> V_199 & V_200 ) ;
V_195:
F_116 ( V_99 ) ;
return - V_26 ;
}
static void F_117 ( struct V_187 * V_187 , struct V_98 * V_99 ,
struct V_161 * V_123 , T_3 V_151 ,
struct V_37 * V_189 , struct V_37 * V_190 )
{
if ( V_190 || V_189 )
F_112 ( V_187 , V_99 , V_123 , V_151 , V_189 , V_190 ) ;
if ( V_189 )
F_118 ( V_189 ) ;
}
static int F_119 ( struct V_49 * V_50 , struct V_37 * V_43 ,
struct V_98 * V_99 , struct V_161 * V_123 , T_3 V_54 ,
struct V_37 * V_190 , struct V_37 * V_189 )
{
struct V_37 * V_3 = V_189 ;
struct V_187 * V_187 = F_120 ( V_50 ) ;
int V_27 = 0 ;
if ( V_43 == NULL ) {
unsigned int V_125 , V_201 , V_202 ;
V_202 = 0 ;
V_201 = V_50 -> V_203 ;
if ( ( V_3 && V_3 -> V_40 & V_45 ) ||
( V_190 && V_190 -> V_40 & V_45 ) ) {
V_201 = 1 ;
V_202 = 1 ;
if ( ! F_25 ( V_50 ) )
return - V_28 ;
}
if ( V_50 -> V_40 & V_204 )
F_121 ( V_50 ) ;
if ( V_190 && V_190 -> V_33 -> V_205 )
goto V_206;
for ( V_125 = 0 ; V_125 < V_201 ; V_125 ++ ) {
struct V_207 * V_208 = F_25 ( V_50 ) ;
if ( ! V_202 )
V_208 = F_122 ( V_50 , V_125 ) ;
V_189 = F_123 ( V_208 , V_190 ) ;
if ( V_190 && V_125 > 0 )
F_124 ( V_190 ) ;
if ( ! V_202 )
F_118 ( V_189 ) ;
}
V_206:
if ( ! V_202 ) {
F_117 ( V_187 , V_99 , V_123 , V_54 ,
V_50 -> V_51 , V_190 ) ;
if ( V_190 && ! V_190 -> V_33 -> V_205 )
F_124 ( V_190 ) ;
V_50 -> V_51 = V_190 ? : & V_209 ;
if ( V_190 && V_190 -> V_33 -> V_205 )
V_190 -> V_33 -> V_205 ( V_190 ) ;
} else {
F_117 ( V_187 , V_99 , V_123 , V_54 , V_189 , V_190 ) ;
}
if ( V_50 -> V_40 & V_204 )
F_125 ( V_50 ) ;
} else {
const struct V_18 * V_19 = V_43 -> V_33 -> V_17 ;
V_27 = - V_210 ;
if ( V_19 && V_19 -> V_211 ) {
unsigned long V_55 = V_19 -> V_20 ( V_43 , V_54 ) ;
if ( V_55 )
V_27 = V_19 -> V_211 ( V_43 , V_55 , V_190 , & V_189 ) ;
else
V_27 = - V_28 ;
}
if ( ! V_27 )
F_117 ( V_187 , V_99 , V_123 , V_54 , V_189 , V_190 ) ;
}
return V_27 ;
}
static struct V_37 * F_126 ( struct V_49 * V_50 ,
struct V_207 * V_208 ,
struct V_37 * V_53 , T_3 V_43 , T_3 V_39 ,
struct V_56 * * V_212 , int * V_213 )
{
int V_27 ;
struct V_56 * V_57 = V_212 [ V_176 ] ;
struct V_37 * V_126 ;
struct V_1 * V_33 ;
struct V_80 * V_84 ;
V_33 = F_27 ( V_57 ) ;
#ifdef F_127
if ( V_33 == NULL && V_57 != NULL ) {
char V_29 [ V_214 ] ;
if ( F_128 ( V_29 , V_57 , V_214 ) < V_214 ) {
F_129 () ;
F_13 ( L_1 , V_29 ) ;
F_130 () ;
V_33 = F_27 ( V_57 ) ;
if ( V_33 != NULL ) {
F_14 ( V_33 -> V_32 ) ;
V_27 = - V_215 ;
goto V_195;
}
}
}
#endif
V_27 = - V_28 ;
if ( V_33 == NULL )
goto V_195;
V_126 = F_131 ( V_208 , V_33 ) ;
if ( F_132 ( V_126 ) ) {
V_27 = F_133 ( V_126 ) ;
goto V_216;
}
V_126 -> V_43 = V_43 ;
if ( V_39 == V_145 ) {
V_126 -> V_40 |= V_45 ;
V_39 = F_89 ( V_145 , 0 ) ;
F_134 ( F_135 ( V_126 ) , & V_217 ) ;
} else {
if ( V_39 == 0 ) {
V_39 = F_88 ( V_50 ) ;
V_27 = - V_92 ;
if ( V_39 == 0 )
goto V_218;
}
F_134 ( F_135 ( V_126 ) , & V_219 ) ;
if ( ! F_136 ( V_50 ) )
V_126 -> V_40 |= V_220 ;
}
V_126 -> V_39 = V_39 ;
if ( ( V_50 -> V_221 & V_222 ) && ( V_50 -> V_223 == 0 ) ) {
V_50 -> V_223 = V_224 ;
F_137 ( V_50 , L_5 ) ;
}
if ( ! V_33 -> V_225 || ( V_27 = V_33 -> V_225 ( V_126 , V_212 [ V_226 ] ) ) == 0 ) {
if ( F_104 ( V_126 ) ) {
V_126 -> V_156 =
F_138 ( struct V_155 ) ;
if ( ! V_126 -> V_156 )
goto V_227;
V_126 -> V_158 = F_139 ( struct V_157 ) ;
if ( ! V_126 -> V_158 )
goto V_227;
}
if ( V_212 [ V_101 ] ) {
V_84 = F_38 ( V_212 [ V_101 ] ) ;
if ( F_132 ( V_84 ) ) {
V_27 = F_133 ( V_84 ) ;
goto V_227;
}
F_140 ( V_126 -> V_84 , V_84 ) ;
}
if ( V_212 [ V_228 ] ) {
T_9 * V_229 ;
V_27 = - V_210 ;
if ( V_126 -> V_40 & V_230 )
goto V_227;
if ( ( V_126 -> V_43 != V_44 ) &&
! ( V_126 -> V_40 & V_45 ) &&
( ! V_53 || ! ( V_53 -> V_40 & V_230 ) ) )
V_229 = F_106 ( V_126 ) ;
else
V_229 = & V_126 -> V_229 ;
V_27 = F_141 ( & V_126 -> V_183 ,
V_126 -> V_156 ,
& V_126 -> V_184 ,
NULL ,
V_229 ,
V_212 [ V_228 ] ) ;
if ( V_27 )
goto V_227;
}
F_19 ( V_126 , false ) ;
return V_126 ;
}
if ( V_33 -> V_231 )
V_33 -> V_231 ( V_126 ) ;
V_218:
F_142 ( V_50 ) ;
F_37 ( ( char * ) V_126 - V_126 -> V_232 ) ;
V_216:
F_14 ( V_33 -> V_32 ) ;
V_195:
* V_213 = V_27 ;
return NULL ;
V_227:
F_143 ( V_126 -> V_156 ) ;
F_143 ( V_126 -> V_158 ) ;
F_45 ( F_102 ( V_126 -> V_84 ) ) ;
if ( V_33 -> V_231 )
V_33 -> V_231 ( V_126 ) ;
goto V_218;
}
static int F_144 ( struct V_37 * V_126 , struct V_56 * * V_212 )
{
struct V_80 * V_233 , * V_84 = NULL ;
int V_27 = 0 ;
if ( V_212 [ V_226 ] ) {
if ( V_126 -> V_33 -> V_234 == NULL )
return - V_26 ;
V_27 = V_126 -> V_33 -> V_234 ( V_126 , V_212 [ V_226 ] ) ;
if ( V_27 )
return V_27 ;
}
if ( V_212 [ V_101 ] ) {
V_84 = F_38 ( V_212 [ V_101 ] ) ;
if ( F_132 ( V_84 ) )
return F_133 ( V_84 ) ;
}
V_233 = F_102 ( V_126 -> V_84 ) ;
F_140 ( V_126 -> V_84 , V_84 ) ;
F_45 ( V_233 ) ;
if ( V_212 [ V_228 ] ) {
if ( V_126 -> V_40 & V_230 )
goto V_11;
F_145 ( & V_126 -> V_183 ,
V_126 -> V_156 ,
& V_126 -> V_184 ,
NULL ,
F_106 ( V_126 ) ,
V_212 [ V_228 ] ) ;
}
V_11:
return 0 ;
}
static int F_146 ( struct V_37 * V_3 , struct V_37 * V_53 , int V_235 )
{
struct V_236 V_237 ;
if ( V_3 -> V_33 -> V_17 == NULL )
return 0 ;
V_237 . V_238 . V_239 = V_237 . V_238 . V_206 = V_237 . V_238 . V_240 = 0 ;
V_237 . V_238 . V_241 = V_242 ;
V_237 . V_235 = V_235 ;
V_237 . V_53 = V_53 ;
V_3 -> V_33 -> V_17 -> V_21 ( V_3 , & V_237 . V_238 ) ;
return V_237 . V_238 . V_239 ? - V_243 : 0 ;
}
static int
V_242 ( struct V_37 * V_3 , unsigned long V_55 , struct V_244 * V_238 )
{
struct V_37 * V_22 ;
const struct V_18 * V_19 = V_3 -> V_33 -> V_17 ;
struct V_236 * V_237 = (struct V_236 * ) V_238 ;
V_22 = V_19 -> V_22 ( V_3 , V_55 ) ;
if ( V_22 ) {
if ( V_22 == V_237 -> V_53 || V_237 -> V_235 > 7 )
return - V_243 ;
return F_146 ( V_22 , V_237 -> V_53 , V_237 -> V_235 + 1 ) ;
}
return 0 ;
}
static int F_147 ( struct V_98 * V_99 , struct V_161 * V_123 ,
struct V_245 * V_246 )
{
struct V_187 * V_187 = F_148 ( V_99 -> V_247 ) ;
struct V_159 * V_160 = F_99 ( V_123 ) ;
struct V_56 * V_212 [ V_248 + 1 ] ;
struct V_49 * V_50 ;
T_3 V_151 ;
struct V_37 * V_3 = NULL ;
struct V_37 * V_53 = NULL ;
int V_27 ;
if ( ( V_123 -> V_249 != V_250 ) &&
! F_149 ( V_99 , V_187 -> V_251 , V_34 ) )
return - V_35 ;
V_27 = F_150 ( V_123 , sizeof( * V_160 ) , V_212 , V_248 , NULL , V_246 ) ;
if ( V_27 < 0 )
return V_27 ;
V_50 = F_151 ( V_187 , V_160 -> V_171 ) ;
if ( ! V_50 )
return - V_252 ;
V_151 = V_160 -> V_173 ;
if ( V_151 ) {
if ( V_151 != V_44 ) {
if ( F_93 ( V_151 ) != F_93 ( V_145 ) ) {
V_53 = F_24 ( V_50 , F_93 ( V_151 ) ) ;
if ( ! V_53 )
return - V_28 ;
V_3 = F_26 ( V_53 , V_151 ) ;
} else if ( F_25 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_52 ;
}
} else {
V_3 = V_50 -> V_51 ;
}
if ( ! V_3 )
return - V_28 ;
if ( V_160 -> V_174 && V_3 -> V_39 != V_160 -> V_174 )
return - V_26 ;
} else {
V_3 = F_24 ( V_50 , V_160 -> V_174 ) ;
if ( ! V_3 )
return - V_28 ;
}
if ( V_212 [ V_176 ] && F_28 ( V_212 [ V_176 ] , V_3 -> V_33 -> V_10 ) )
return - V_26 ;
if ( V_123 -> V_249 == V_194 ) {
if ( ! V_151 )
return - V_26 ;
if ( V_3 -> V_39 == 0 )
return - V_28 ;
V_27 = F_119 ( V_50 , V_53 , V_99 , V_123 , V_151 , NULL , V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
} else {
F_112 ( V_187 , V_99 , V_123 , V_151 , NULL , V_3 ) ;
}
return 0 ;
}
static int F_152 ( struct V_98 * V_99 , struct V_161 * V_123 ,
struct V_245 * V_246 )
{
struct V_187 * V_187 = F_148 ( V_99 -> V_247 ) ;
struct V_159 * V_160 ;
struct V_56 * V_212 [ V_248 + 1 ] ;
struct V_49 * V_50 ;
T_3 V_151 ;
struct V_37 * V_3 , * V_53 ;
int V_27 ;
if ( ! F_149 ( V_99 , V_187 -> V_251 , V_34 ) )
return - V_35 ;
V_253:
V_27 = F_150 ( V_123 , sizeof( * V_160 ) , V_212 , V_248 , NULL , V_246 ) ;
if ( V_27 < 0 )
return V_27 ;
V_160 = F_99 ( V_123 ) ;
V_151 = V_160 -> V_173 ;
V_3 = V_53 = NULL ;
V_50 = F_151 ( V_187 , V_160 -> V_171 ) ;
if ( ! V_50 )
return - V_252 ;
if ( V_151 ) {
if ( V_151 != V_44 ) {
if ( V_151 != V_145 ) {
V_53 = F_24 ( V_50 , F_93 ( V_151 ) ) ;
if ( ! V_53 )
return - V_28 ;
V_3 = F_26 ( V_53 , V_151 ) ;
} else if ( F_153 ( V_50 ) ) {
V_3 = F_25 ( V_50 ) -> V_52 ;
}
} else {
V_3 = V_50 -> V_51 ;
}
if ( V_3 && V_3 -> V_39 == 0 )
V_3 = NULL ;
if ( ! V_3 || ! V_160 -> V_174 || V_3 -> V_39 != V_160 -> V_174 ) {
if ( V_160 -> V_174 ) {
if ( V_3 && ! ( V_123 -> V_199 & V_196 ) )
return - V_6 ;
if ( F_154 ( V_160 -> V_174 ) )
return - V_26 ;
V_3 = F_24 ( V_50 , V_160 -> V_174 ) ;
if ( ! V_3 )
goto V_254;
if ( V_123 -> V_199 & V_255 )
return - V_6 ;
if ( V_212 [ V_176 ] && F_28 ( V_212 [ V_176 ] , V_3 -> V_33 -> V_10 ) )
return - V_26 ;
if ( V_3 == V_53 ||
( V_53 && F_146 ( V_3 , V_53 , 0 ) ) )
return - V_243 ;
F_124 ( V_3 ) ;
goto V_211;
} else {
if ( ! V_3 )
goto V_254;
if ( ( V_123 -> V_199 & V_256 ) &&
( V_123 -> V_199 & V_196 ) &&
( ( V_123 -> V_199 & V_255 ) ||
( V_212 [ V_176 ] &&
F_28 ( V_212 [ V_176 ] , V_3 -> V_33 -> V_10 ) ) ) )
goto V_254;
}
}
} else {
if ( ! V_160 -> V_174 )
return - V_26 ;
V_3 = F_24 ( V_50 , V_160 -> V_174 ) ;
}
if ( V_3 == NULL )
return - V_28 ;
if ( V_123 -> V_199 & V_255 )
return - V_6 ;
if ( V_212 [ V_176 ] && F_28 ( V_212 [ V_176 ] , V_3 -> V_33 -> V_10 ) )
return - V_26 ;
V_27 = F_144 ( V_3 , V_212 ) ;
if ( V_27 == 0 )
F_112 ( V_187 , V_99 , V_123 , V_151 , NULL , V_3 ) ;
return V_27 ;
V_254:
if ( ! ( V_123 -> V_199 & V_256 ) )
return - V_28 ;
if ( V_151 == V_145 ) {
if ( F_25 ( V_50 ) )
V_3 = F_126 ( V_50 , F_25 ( V_50 ) , V_53 ,
V_160 -> V_173 , V_160 -> V_173 ,
V_212 , & V_27 ) ;
else
V_27 = - V_28 ;
} else {
struct V_207 * V_208 ;
if ( V_53 && V_53 -> V_33 -> V_17 && V_53 -> V_33 -> V_17 -> V_257 )
V_208 = V_53 -> V_33 -> V_17 -> V_257 ( V_53 , V_160 ) ;
else if ( V_53 )
V_208 = V_53 -> V_208 ;
else
V_208 = F_122 ( V_50 , 0 ) ;
V_3 = F_126 ( V_50 , V_208 , V_53 ,
V_160 -> V_173 , V_160 -> V_174 ,
V_212 , & V_27 ) ;
}
if ( V_3 == NULL ) {
if ( V_27 == - V_215 )
goto V_253;
return V_27 ;
}
V_211:
V_27 = F_119 ( V_50 , V_53 , V_99 , V_123 , V_151 , V_3 , NULL ) ;
if ( V_27 ) {
if ( V_3 )
F_118 ( V_3 ) ;
return V_27 ;
}
return 0 ;
}
static int F_155 ( struct V_37 * V_38 , struct V_98 * V_99 ,
struct V_258 * V_259 ,
int * V_260 , int V_261 , bool V_262 ,
bool V_186 )
{
int V_263 = 0 , V_264 = * V_260 ;
struct V_37 * V_3 ;
int V_163 ;
if ( ! V_38 )
return 0 ;
V_3 = V_38 ;
if ( V_264 < V_261 ) {
V_264 ++ ;
} else {
if ( ! F_111 ( V_3 , V_186 ) &&
F_96 ( V_99 , V_3 , V_3 -> V_43 , F_113 ( V_259 -> V_99 ) . V_152 ,
V_259 -> V_162 -> V_193 , V_265 ,
V_197 ) <= 0 )
goto V_266;
V_264 ++ ;
}
if ( ! F_17 ( V_38 ) || ! V_262 )
goto V_11;
F_156 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( V_264 < V_261 ) {
V_264 ++ ;
continue;
}
if ( ! F_111 ( V_3 , V_186 ) &&
F_96 ( V_99 , V_3 , V_3 -> V_43 , F_113 ( V_259 -> V_99 ) . V_152 ,
V_259 -> V_162 -> V_193 , V_265 ,
V_197 ) <= 0 )
goto V_266;
V_264 ++ ;
}
V_11:
* V_260 = V_264 ;
return V_263 ;
V_266:
V_263 = - 1 ;
goto V_11;
}
static int F_157 ( struct V_98 * V_99 , struct V_258 * V_259 )
{
struct V_187 * V_187 = F_148 ( V_99 -> V_247 ) ;
int V_267 , V_264 ;
int V_268 , V_261 ;
struct V_49 * V_50 ;
const struct V_161 * V_162 = V_259 -> V_162 ;
struct V_159 * V_160 = F_99 ( V_162 ) ;
struct V_56 * V_212 [ V_248 + 1 ] ;
int V_27 ;
V_268 = V_259 -> args [ 0 ] ;
V_261 = V_264 = V_259 -> args [ 1 ] ;
V_267 = 0 ;
F_20 () ;
V_27 = F_150 ( V_162 , sizeof( * V_160 ) , V_212 , V_248 , NULL , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
F_158 (net, dev) {
struct V_207 * V_208 ;
if ( V_267 < V_268 )
goto V_269;
if ( V_267 > V_268 )
V_261 = 0 ;
V_264 = 0 ;
if ( F_155 ( V_50 -> V_51 , V_99 , V_259 , & V_264 , V_261 ,
true , V_212 [ V_270 ] ) < 0 )
goto V_266;
V_208 = F_25 ( V_50 ) ;
if ( V_208 &&
F_155 ( V_208 -> V_52 , V_99 , V_259 ,
& V_264 , V_261 , false ,
V_212 [ V_270 ] ) < 0 )
goto V_266;
V_269:
V_267 ++ ;
}
V_266:
V_259 -> args [ 0 ] = V_267 ;
V_259 -> args [ 1 ] = V_264 ;
return V_99 -> V_30 ;
}
static int F_159 ( struct V_98 * V_99 , struct V_37 * V_3 ,
unsigned long V_55 ,
T_3 V_152 , T_3 V_153 , T_6 V_40 , int V_154 )
{
struct V_159 * V_160 ;
struct V_161 * V_162 ;
unsigned char * V_163 = F_97 ( V_99 ) ;
struct V_164 V_165 ;
const struct V_18 * V_17 = V_3 -> V_33 -> V_17 ;
F_90 () ;
V_162 = F_98 ( V_99 , V_152 , V_153 , V_154 , sizeof( * V_160 ) , V_40 ) ;
if ( ! V_162 )
goto V_166;
V_160 = F_99 ( V_162 ) ;
V_160 -> V_167 = V_168 ;
V_160 -> V_169 = 0 ;
V_160 -> V_170 = 0 ;
V_160 -> V_171 = F_17 ( V_3 ) -> V_172 ;
V_160 -> V_173 = V_3 -> V_39 ;
V_160 -> V_174 = V_3 -> V_39 ;
V_160 -> V_175 = 0 ;
if ( F_101 ( V_99 , V_176 , V_3 -> V_33 -> V_10 ) )
goto V_102;
if ( V_17 -> V_177 && V_17 -> V_177 ( V_3 , V_55 , V_99 , V_160 ) < 0 )
goto V_102;
if ( F_103 ( V_99 , V_178 , V_179 , V_180 ,
NULL , & V_165 , V_181 ) < 0 )
goto V_102;
if ( V_17 -> V_182 && V_17 -> V_182 ( V_3 , V_55 , & V_165 ) < 0 )
goto V_102;
if ( F_109 ( & V_165 ) < 0 )
goto V_102;
V_162 -> V_185 = F_97 ( V_99 ) - V_163 ;
return V_99 -> V_30 ;
V_166:
V_102:
F_110 ( V_99 , V_163 ) ;
return - 1 ;
}
static int F_160 ( struct V_187 * V_187 , struct V_98 * V_188 ,
struct V_161 * V_123 , struct V_37 * V_3 ,
unsigned long V_55 , int V_154 )
{
struct V_98 * V_99 ;
T_3 V_152 = V_188 ? F_113 ( V_188 ) . V_152 : 0 ;
V_99 = F_114 ( V_191 , V_76 ) ;
if ( ! V_99 )
return - V_192 ;
if ( F_159 ( V_99 , V_3 , V_55 , V_152 , V_123 -> V_193 , 0 , V_154 ) < 0 ) {
F_116 ( V_99 ) ;
return - V_26 ;
}
return F_115 ( V_99 , V_187 , V_152 , V_198 ,
V_123 -> V_199 & V_200 ) ;
}
static int F_161 ( struct V_187 * V_187 ,
const struct V_18 * V_19 ,
struct V_98 * V_188 , struct V_161 * V_123 ,
struct V_37 * V_3 , unsigned long V_55 )
{
T_3 V_152 = V_188 ? F_113 ( V_188 ) . V_152 : 0 ;
struct V_98 * V_99 ;
int V_27 = 0 ;
if ( ! V_19 -> V_271 )
return - V_210 ;
V_99 = F_114 ( V_191 , V_76 ) ;
if ( ! V_99 )
return - V_192 ;
if ( F_159 ( V_99 , V_3 , V_55 , V_152 , V_123 -> V_193 , 0 ,
V_272 ) < 0 ) {
F_116 ( V_99 ) ;
return - V_26 ;
}
V_27 = V_19 -> V_271 ( V_3 , V_55 ) ;
if ( V_27 ) {
F_116 ( V_99 ) ;
return V_27 ;
}
return F_115 ( V_99 , V_187 , V_152 , V_198 ,
V_123 -> V_199 & V_200 ) ;
}
static int F_162 ( struct V_273 * V_274 , void * V_123 , struct V_275 * V_237 )
{
struct V_276 * V_277 = ( void * ) V_237 ;
if ( V_274 -> V_33 -> V_278 ) {
F_163 ( V_274 ) ;
V_274 -> V_33 -> V_278 ( V_123 , V_277 -> V_54 , V_277 -> V_55 ) ;
F_164 ( V_274 ) ;
}
return 0 ;
}
static void F_165 ( struct V_37 * V_3 , T_3 V_152 , T_3 V_151 ,
unsigned long V_279 )
{
const struct V_18 * V_19 = V_3 -> V_33 -> V_17 ;
struct V_23 * V_280 ;
struct V_281 * V_282 ;
unsigned long V_55 ;
V_55 = V_19 -> V_20 ( V_3 , V_152 ) ;
if ( ! V_55 )
return;
V_280 = V_19 -> V_23 ( V_3 , V_55 ) ;
if ( ! V_280 )
return;
F_41 (chain, &block->chain_list, list) {
struct V_273 * V_274 ;
for ( V_274 = F_102 ( V_282 -> V_283 ) ;
V_274 ; V_274 = F_102 ( V_274 -> V_9 ) ) {
struct V_276 V_237 = {} ;
V_237 . V_238 . V_241 = F_162 ;
V_237 . V_54 = V_151 ;
V_237 . V_55 = V_279 ;
V_274 -> V_33 -> V_21 ( V_274 , & V_237 . V_238 ) ;
}
}
}
static void F_165 ( struct V_37 * V_3 , T_3 V_152 , T_3 V_151 ,
unsigned long V_279 )
{
}
static int F_166 ( struct V_98 * V_99 , struct V_161 * V_123 ,
struct V_245 * V_246 )
{
struct V_187 * V_187 = F_148 ( V_99 -> V_247 ) ;
struct V_159 * V_160 = F_99 ( V_123 ) ;
struct V_56 * V_212 [ V_248 + 1 ] ;
struct V_49 * V_50 ;
struct V_37 * V_3 = NULL ;
const struct V_18 * V_19 ;
unsigned long V_55 = 0 ;
unsigned long V_279 ;
T_3 V_152 ;
T_3 V_151 ;
T_3 V_284 ;
int V_27 ;
if ( ( V_123 -> V_249 != V_285 ) &&
! F_149 ( V_99 , V_187 -> V_251 , V_34 ) )
return - V_35 ;
V_27 = F_150 ( V_123 , sizeof( * V_160 ) , V_212 , V_248 , NULL , V_246 ) ;
if ( V_27 < 0 )
return V_27 ;
V_50 = F_151 ( V_187 , V_160 -> V_171 ) ;
if ( ! V_50 )
return - V_252 ;
V_152 = V_160 -> V_173 ;
V_151 = V_160 -> V_174 ;
V_284 = F_93 ( V_151 ) ;
if ( V_152 != V_44 ) {
T_3 V_286 = F_93 ( V_152 ) ;
if ( V_284 && V_286 ) {
if ( V_284 != V_286 )
return - V_26 ;
} else if ( V_286 ) {
V_284 = V_286 ;
} else if ( V_284 == 0 )
V_284 = V_50 -> V_51 -> V_39 ;
if ( V_152 )
V_152 = F_89 ( V_284 , V_152 ) ;
} else {
if ( V_284 == 0 )
V_284 = V_50 -> V_51 -> V_39 ;
}
V_3 = F_24 ( V_50 , V_284 ) ;
if ( ! V_3 )
return - V_28 ;
V_19 = V_3 -> V_33 -> V_17 ;
if ( V_19 == NULL )
return - V_26 ;
if ( V_151 == 0 ) {
if ( V_152 == V_44 )
V_151 = V_284 ;
} else
V_151 = F_89 ( V_284 , V_151 ) ;
if ( V_151 )
V_55 = V_19 -> V_20 ( V_3 , V_151 ) ;
if ( V_55 == 0 ) {
V_27 = - V_28 ;
if ( V_123 -> V_249 != V_287 ||
! ( V_123 -> V_199 & V_256 ) )
goto V_11;
} else {
switch ( V_123 -> V_249 ) {
case V_287 :
V_27 = - V_6 ;
if ( V_123 -> V_199 & V_255 )
goto V_11;
break;
case V_272 :
V_27 = F_161 ( V_187 , V_19 , V_99 , V_123 , V_3 , V_55 ) ;
F_165 ( V_3 , V_152 , V_151 , 0 ) ;
goto V_11;
case V_285 :
V_27 = F_160 ( V_187 , V_99 , V_123 , V_3 , V_55 , V_287 ) ;
goto V_11;
default:
V_27 = - V_26 ;
goto V_11;
}
}
V_279 = V_55 ;
V_27 = - V_210 ;
if ( V_19 -> V_234 )
V_27 = V_19 -> V_234 ( V_3 , V_151 , V_152 , V_212 , & V_279 ) ;
if ( V_27 == 0 ) {
F_160 ( V_187 , V_99 , V_123 , V_3 , V_279 , V_287 ) ;
if ( V_55 != V_279 )
F_165 ( V_3 , V_152 , V_151 , V_279 ) ;
}
V_11:
return V_27 ;
}
static int F_167 ( struct V_37 * V_3 , unsigned long V_55 ,
struct V_244 * V_237 )
{
struct V_288 * V_277 = (struct V_288 * ) V_237 ;
return F_159 ( V_277 -> V_99 , V_3 , V_55 , F_113 ( V_277 -> V_259 -> V_99 ) . V_152 ,
V_277 -> V_259 -> V_162 -> V_193 , V_265 ,
V_287 ) ;
}
static int F_168 ( struct V_37 * V_3 , struct V_98 * V_99 ,
struct V_159 * V_160 , struct V_258 * V_259 ,
int * V_289 , int V_290 )
{
struct V_288 V_237 ;
if ( F_111 ( V_3 , false ) ||
* V_289 < V_290 || ! V_3 -> V_33 -> V_17 ||
( V_160 -> V_173 &&
F_93 ( V_160 -> V_173 ) != V_3 -> V_39 ) ) {
( * V_289 ) ++ ;
return 0 ;
}
if ( * V_289 > V_290 )
memset ( & V_259 -> args [ 1 ] , 0 , sizeof( V_259 -> args ) - sizeof( V_259 -> args [ 0 ] ) ) ;
V_237 . V_238 . V_241 = F_167 ;
V_237 . V_99 = V_99 ;
V_237 . V_259 = V_259 ;
V_237 . V_238 . V_239 = 0 ;
V_237 . V_238 . V_206 = V_259 -> args [ 1 ] ;
V_237 . V_238 . V_240 = 0 ;
V_3 -> V_33 -> V_17 -> V_21 ( V_3 , & V_237 . V_238 ) ;
V_259 -> args [ 1 ] = V_237 . V_238 . V_240 ;
if ( V_237 . V_238 . V_239 )
return - 1 ;
( * V_289 ) ++ ;
return 0 ;
}
static int F_169 ( struct V_37 * V_38 , struct V_98 * V_99 ,
struct V_159 * V_160 , struct V_258 * V_259 ,
int * V_289 , int V_290 )
{
struct V_37 * V_3 ;
int V_163 ;
if ( ! V_38 )
return 0 ;
if ( F_168 ( V_38 , V_99 , V_160 , V_259 , V_289 , V_290 ) < 0 )
return - 1 ;
if ( ! F_17 ( V_38 ) )
return 0 ;
if ( V_160 -> V_173 ) {
V_3 = F_16 ( V_38 , F_93 ( V_160 -> V_173 ) ) ;
if ( V_3 && F_168 ( V_3 , V_99 , V_160 , V_259 , V_289 , V_290 ) < 0 )
return - 1 ;
return 0 ;
}
F_156 (qdisc_dev(root)->qdisc_hash, b, q, hash) {
if ( F_168 ( V_3 , V_99 , V_160 , V_259 , V_289 , V_290 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_170 ( struct V_98 * V_99 , struct V_258 * V_259 )
{
struct V_159 * V_160 = F_99 ( V_259 -> V_162 ) ;
struct V_187 * V_187 = F_148 ( V_99 -> V_247 ) ;
struct V_207 * V_208 ;
struct V_49 * V_50 ;
int V_291 , V_290 ;
if ( V_185 ( V_259 -> V_162 ) < sizeof( * V_160 ) )
return 0 ;
V_50 = F_171 ( V_187 , V_160 -> V_171 ) ;
if ( ! V_50 )
return 0 ;
V_290 = V_259 -> args [ 0 ] ;
V_291 = 0 ;
if ( F_169 ( V_50 -> V_51 , V_99 , V_160 , V_259 , & V_291 , V_290 ) < 0 )
goto V_266;
V_208 = F_25 ( V_50 ) ;
if ( V_208 &&
F_169 ( V_208 -> V_52 , V_99 , V_160 , V_259 ,
& V_291 , V_290 ) < 0 )
goto V_266;
V_266:
V_259 -> args [ 0 ] = V_291 ;
F_142 ( V_50 ) ;
return V_99 -> V_30 ;
}
static int F_172 ( struct V_292 * V_153 , void * V_293 )
{
F_173 ( V_153 , L_6 ,
( T_3 ) V_294 , ( T_3 ) F_174 ( 1 ) ,
1000000 ,
( T_3 ) V_295 / V_296 ) ;
return 0 ;
}
static int F_175 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_176 ( V_298 , F_172 , NULL ) ;
}
static int T_10 F_177 ( struct V_187 * V_187 )
{
struct V_299 * V_300 ;
V_300 = F_178 ( L_7 , 0 , V_187 -> V_301 , & V_302 ) ;
if ( V_300 == NULL )
return - V_92 ;
return 0 ;
}
static void T_11 F_179 ( struct V_187 * V_187 )
{
F_180 ( L_7 , V_187 -> V_301 ) ;
}
static int T_10 F_177 ( struct V_187 * V_187 )
{
return 0 ;
}
static void T_11 F_179 ( struct V_187 * V_187 )
{
}
static int T_2 F_181 ( void )
{
int V_27 ;
V_27 = F_182 ( & V_303 ) ;
if ( V_27 ) {
F_183 ( L_8
L_9 ) ;
return V_27 ;
}
F_1 ( & V_304 ) ;
F_1 ( & V_305 ) ;
F_1 ( & V_306 ) ;
F_1 ( & V_307 ) ;
F_1 ( & V_308 ) ;
F_1 ( & V_309 ) ;
F_184 ( V_310 , V_197 , F_152 , NULL , 0 ) ;
F_184 ( V_310 , V_194 , F_147 , NULL , 0 ) ;
F_184 ( V_310 , V_250 , F_147 , F_157 ,
0 ) ;
F_184 ( V_310 , V_287 , F_166 , NULL , 0 ) ;
F_184 ( V_310 , V_272 , F_166 , NULL , 0 ) ;
F_184 ( V_310 , V_285 , F_166 , F_170 ,
0 ) ;
return 0 ;
}
