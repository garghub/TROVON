void * F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , V_4 ) ;
}
static inline int F_3 ( const struct V_5 * V_6 ,
const char * V_7 , int V_8 )
{
int V_9 , V_10 ;
if ( V_8 > V_11 )
V_8 = V_11 ;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_10 |= ( V_7 [ V_9 ] ^ V_6 -> V_12 [ V_9 ] ) & V_6 -> V_13 [ V_9 ] ;
return V_10 != 0 ;
}
static unsigned long F_4 ( const char * V_14 , const char * V_15 , const char * V_16 )
{
#ifdef F_5
unsigned long V_10 = F_6 ( V_14 , V_15 , V_16 ) ;
#else
unsigned long V_10 = 0 ;
const T_1 * V_17 = ( const T_1 * ) V_14 ;
const T_1 * V_18 = ( const T_1 * ) V_15 ;
const T_1 * V_13 = ( const T_1 * ) V_16 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_19 / sizeof( T_1 ) ; V_9 ++ )
V_10 |= ( V_17 [ V_9 ] ^ V_18 [ V_9 ] ) & V_13 [ V_9 ] ;
#endif
return V_10 ;
}
static inline int F_7 ( const struct V_20 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 ,
const char * V_24 ,
const struct V_25 * V_26 )
{
const char * V_27 = ( char * ) ( V_20 + 1 ) ;
const char * V_28 , * V_29 ;
T_2 V_30 , V_31 ;
long V_10 ;
if ( F_8 ( V_26 , V_32 ,
( V_20 -> V_33 & V_26 -> V_34 ) != V_26 -> V_35 ) )
return 0 ;
if ( F_8 ( V_26 , V_36 ,
( V_20 -> V_37 & V_26 -> V_38 ) != V_26 -> V_39 ) )
return 0 ;
if ( F_8 ( V_26 , V_40 ,
( V_20 -> V_41 & V_26 -> V_42 ) != V_26 -> V_43 ) )
return 0 ;
if ( F_8 ( V_26 , V_44 ,
( V_20 -> V_45 & V_26 -> V_46 ) != V_26 -> V_47 ) )
return 0 ;
V_28 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_30 , V_27 , sizeof( V_49 ) ) ;
V_27 += sizeof( V_49 ) ;
V_29 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_31 , V_27 , sizeof( V_49 ) ) ;
if ( F_8 ( V_26 , V_50 ,
F_3 ( & V_26 -> V_28 , V_28 ,
V_22 -> V_48 ) ) ||
F_8 ( V_26 , V_51 ,
F_3 ( & V_26 -> V_29 , V_29 ,
V_22 -> V_48 ) ) )
return 0 ;
if ( F_8 ( V_26 , V_52 ,
( V_30 & V_26 -> V_53 . V_54 ) != V_26 -> V_55 . V_54 ) ||
F_8 ( V_26 , V_56 ,
( V_31 & V_26 -> V_57 . V_54 ) != V_26 -> V_58 . V_54 ) )
return 0 ;
V_10 = F_4 ( V_23 , V_26 -> V_59 , V_26 -> V_60 ) ;
if ( F_8 ( V_26 , V_61 , V_10 != 0 ) )
return 0 ;
V_10 = F_4 ( V_24 , V_26 -> V_62 , V_26 -> V_63 ) ;
if ( F_8 ( V_26 , V_64 , V_10 != 0 ) )
return 0 ;
return 1 ;
}
static inline int F_9 ( const struct V_25 * V_65 )
{
if ( V_65 -> V_66 & ~ V_67 )
return 0 ;
if ( V_65 -> V_68 & ~ V_69 )
return 0 ;
return 1 ;
}
static unsigned int
F_10 ( struct V_70 * V_71 , const struct V_72 * V_73 )
{
F_11 ( L_1 ,
( const char * ) V_73 -> V_74 ) ;
return V_75 ;
}
static inline const struct V_76 *
F_12 ( const struct V_77 * V_78 )
{
return F_13 ( (struct V_77 * ) V_78 ) ;
}
static inline struct V_77 *
F_14 ( const void * V_79 , unsigned int V_80 )
{
return (struct V_77 * ) ( V_79 + V_80 ) ;
}
static inline
struct V_77 * F_15 ( const struct V_77 * V_81 )
{
return ( void * ) V_81 + V_81 -> V_82 ;
}
unsigned int F_16 ( struct V_70 * V_71 ,
const struct V_83 * V_84 ,
struct V_1 * V_85 )
{
unsigned int V_86 = V_84 -> V_86 ;
static const char V_87 [ V_19 ] V_88 ( ( F_17 ( sizeof( long ) ) ) ) ;
unsigned int V_89 = V_75 ;
const struct V_20 * V_65 ;
struct V_77 * V_78 , * * V_90 ;
const char * V_23 , * V_24 ;
const void * V_91 ;
unsigned int V_92 , V_93 = 0 ;
const struct V_94 * V_95 ;
struct V_72 V_96 ;
unsigned int V_97 ;
if ( ! F_18 ( V_71 , F_19 ( V_71 -> V_22 ) ) )
return V_75 ;
V_23 = V_84 -> V_98 ? V_84 -> V_98 -> V_99 : V_87 ;
V_24 = V_84 -> V_100 ? V_84 -> V_100 -> V_99 : V_87 ;
F_20 () ;
V_97 = F_21 () ;
V_95 = V_85 -> V_95 ;
V_92 = F_22 () ;
F_23 () ;
V_91 = V_95 -> V_101 ;
V_90 = (struct V_77 * * ) V_95 -> V_90 [ V_92 ] ;
V_78 = F_14 ( V_91 , V_95 -> V_102 [ V_86 ] ) ;
V_96 . V_103 = V_84 -> V_103 ;
V_96 . V_98 = V_84 -> V_98 ;
V_96 . V_100 = V_84 -> V_100 ;
V_96 . V_104 = V_86 ;
V_96 . V_105 = V_106 ;
V_96 . V_107 = false ;
V_65 = F_24 ( V_71 ) ;
do {
const struct V_76 * V_108 ;
struct V_109 * V_110 ;
if ( ! F_7 ( V_65 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_65 ) ) {
V_78 = F_15 ( V_78 ) ;
continue;
}
V_110 = F_25 ( & V_78 -> V_111 ) ;
F_26 ( * V_110 , F_19 ( V_71 -> V_22 ) , 1 ) ;
V_108 = F_12 ( V_78 ) ;
if ( ! V_108 -> V_112 . V_113 . V_114 -> V_114 ) {
int V_115 ;
V_115 = ( (struct V_116 * ) V_108 ) -> V_89 ;
if ( V_115 < 0 ) {
if ( V_115 != V_117 ) {
V_89 = ( unsigned int ) ( - V_115 ) - 1 ;
break;
}
if ( V_93 == 0 ) {
V_78 = F_14 ( V_91 ,
V_95 -> V_118 [ V_86 ] ) ;
} else {
V_78 = V_90 [ -- V_93 ] ;
V_78 = F_15 ( V_78 ) ;
}
continue;
}
if ( V_91 + V_115
!= F_15 ( V_78 ) ) {
V_90 [ V_93 ++ ] = V_78 ;
}
V_78 = F_14 ( V_91 , V_115 ) ;
continue;
}
V_96 . V_114 = V_108 -> V_112 . V_113 . V_114 ;
V_96 . V_74 = V_108 -> V_119 ;
V_89 = V_108 -> V_112 . V_113 . V_114 -> V_114 ( V_71 , & V_96 ) ;
V_65 = F_24 ( V_71 ) ;
if ( V_89 == V_120 )
V_78 = F_15 ( V_78 ) ;
else
break;
} while ( ! V_96 . V_107 );
F_27 ( V_97 ) ;
F_28 () ;
if ( V_96 . V_107 )
return V_75 ;
else
return V_89 ;
}
static inline bool F_29 ( const struct V_77 * V_78 )
{
static const struct V_25 V_121 ;
return V_78 -> V_122 == sizeof( struct V_77 ) &&
memcmp ( & V_78 -> V_65 , & V_121 , sizeof( V_121 ) ) == 0 ;
}
static int F_30 ( const struct V_94 * V_123 ,
unsigned int V_124 , void * V_125 ,
unsigned int * V_126 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_127 ; V_86 ++ ) {
unsigned int V_128 = V_123 -> V_102 [ V_86 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_125 + V_128 ) ;
if ( ! ( V_124 & ( 1 << V_86 ) ) )
continue;
V_78 -> V_111 . V_129 = V_128 ;
for (; ; ) {
const struct V_116 * V_108
= ( void * ) F_12 ( V_78 ) ;
int V_130 = V_78 -> V_131 & ( 1 << V_86 ) ;
if ( V_78 -> V_131 & ( 1 << V_127 ) )
return 0 ;
V_78 -> V_131
|= ( ( 1 << V_86 ) | ( 1 << V_127 ) ) ;
if ( ( F_29 ( V_78 ) &&
( strcmp ( V_108 -> V_114 . V_112 . V_132 . V_99 ,
V_133 ) == 0 ) &&
V_108 -> V_89 < 0 ) || V_130 ) {
unsigned int V_134 , V_135 ;
if ( ( strcmp ( V_108 -> V_114 . V_112 . V_132 . V_99 ,
V_133 ) == 0 ) &&
V_108 -> V_89 < - V_136 - 1 )
return 0 ;
do {
V_78 -> V_131 ^= ( 1 << V_127 ) ;
V_134 = V_128 ;
V_128 = V_78 -> V_111 . V_129 ;
V_78 -> V_111 . V_129 = 0 ;
if ( V_128 == V_134 )
goto V_137;
V_78 = (struct V_77 * )
( V_125 + V_128 ) ;
} while ( V_134 == V_128 + V_78 -> V_82 );
V_135 = V_78 -> V_82 ;
V_78 = (struct V_77 * )
( V_125 + V_128 + V_135 ) ;
if ( V_128 + V_135 >= V_123 -> V_135 )
return 0 ;
V_78 -> V_111 . V_129 = V_128 ;
V_128 += V_135 ;
} else {
int V_138 = V_108 -> V_89 ;
if ( strcmp ( V_108 -> V_114 . V_112 . V_132 . V_99 ,
V_133 ) == 0 &&
V_138 >= 0 ) {
if ( ! F_31 ( V_126 , V_138 ,
V_123 -> V_139 ) )
return 0 ;
V_78 = (struct V_77 * )
( V_125 + V_138 ) ;
} else {
V_138 = V_128 + V_78 -> V_82 ;
if ( V_138 >= V_123 -> V_135 )
return 0 ;
}
V_78 = (struct V_77 * )
( V_125 + V_138 ) ;
V_78 -> V_111 . V_129 = V_128 ;
V_128 = V_138 ;
}
}
V_137: ;
}
return 1 ;
}
static inline int F_32 ( struct V_77 * V_78 , const char * V_99 )
{
struct V_76 * V_108 = F_13 ( V_78 ) ;
struct V_140 V_73 = {
. V_85 = V_99 ,
. V_141 = V_78 ,
. V_114 = V_108 -> V_112 . V_113 . V_114 ,
. V_74 = V_108 -> V_119 ,
. V_142 = V_78 -> V_131 ,
. V_105 = V_106 ,
} ;
return F_33 ( & V_73 , V_108 -> V_112 . V_143 - sizeof( * V_108 ) , 0 , false ) ;
}
static inline int
F_34 ( struct V_77 * V_78 , const char * V_99 , unsigned int V_135 )
{
struct V_76 * V_108 ;
struct V_144 * V_114 ;
unsigned long V_129 ;
int V_10 ;
V_129 = F_35 () ;
if ( F_36 ( V_129 ) )
return - V_145 ;
V_78 -> V_111 . V_129 = V_129 ;
V_108 = F_13 ( V_78 ) ;
V_114 = F_37 ( V_106 , V_108 -> V_112 . V_132 . V_99 ,
V_108 -> V_112 . V_132 . V_146 ) ;
if ( F_38 ( V_114 ) ) {
V_10 = F_39 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_10 = F_32 ( V_78 , V_99 ) ;
if ( V_10 )
goto V_147;
return 0 ;
V_147:
F_40 ( V_108 -> V_112 . V_113 . V_114 -> V_148 ) ;
V_100:
F_41 ( V_78 -> V_111 . V_129 ) ;
return V_10 ;
}
static bool F_42 ( const struct V_77 * V_78 )
{
const struct V_76 * V_108 ;
unsigned int V_89 ;
if ( ! F_29 ( V_78 ) )
return false ;
V_108 = F_12 ( V_78 ) ;
if ( strcmp ( V_108 -> V_112 . V_132 . V_99 , V_133 ) != 0 )
return false ;
V_89 = ( (struct V_116 * ) V_108 ) -> V_89 ;
V_89 = - V_89 - 1 ;
return V_89 == V_75 || V_89 == V_149 ;
}
static inline int F_43 ( struct V_77 * V_78 ,
struct V_94 * V_123 ,
const unsigned char * V_79 ,
const unsigned char * V_150 ,
const unsigned int * V_151 ,
const unsigned int * V_152 ,
unsigned int V_124 )
{
unsigned int V_153 ;
int V_147 ;
if ( ( unsigned long ) V_78 % F_44 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_150 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_150 )
return - V_154 ;
if ( V_78 -> V_82
< sizeof( struct V_77 ) + sizeof( struct V_76 ) )
return - V_154 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_154 ;
V_147 = F_45 ( V_78 , V_78 -> V_155 , V_78 -> V_122 ,
V_78 -> V_82 ) ;
if ( V_147 )
return V_147 ;
for ( V_153 = 0 ; V_153 < V_127 ; V_153 ++ ) {
if ( ! ( V_124 & ( 1 << V_153 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_151 [ V_153 ] )
V_123 -> V_102 [ V_153 ] = V_151 [ V_153 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_152 [ V_153 ] ) {
if ( ! F_42 ( V_78 ) )
return - V_154 ;
V_123 -> V_118 [ V_153 ] = V_152 [ V_153 ] ;
}
}
V_78 -> V_111 = ( (struct V_109 ) { 0 , 0 } ) ;
V_78 -> V_131 = 0 ;
return 0 ;
}
static inline void F_46 ( struct V_77 * V_78 )
{
struct V_156 V_73 ;
struct V_76 * V_108 ;
V_108 = F_13 ( V_78 ) ;
V_73 . V_114 = V_108 -> V_112 . V_113 . V_114 ;
V_73 . V_74 = V_108 -> V_119 ;
V_73 . V_105 = V_106 ;
if ( V_73 . V_114 -> V_157 != NULL )
V_73 . V_114 -> V_157 ( & V_73 ) ;
F_40 ( V_73 . V_114 -> V_148 ) ;
F_41 ( V_78 -> V_111 . V_129 ) ;
}
static int F_47 ( struct V_94 * V_123 , void * V_125 ,
const struct V_158 * V_159 )
{
struct V_77 * V_160 ;
unsigned int * V_126 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_123 -> V_135 = V_159 -> V_135 ;
V_123 -> V_139 = V_159 -> V_161 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_123 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_123 -> V_118 [ V_9 ] = 0xFFFFFFFF ;
}
V_126 = F_48 ( V_123 -> V_139 ) ;
if ( ! V_126 )
return - V_145 ;
V_9 = 0 ;
F_49 (iter, entry0, newinfo->size) {
V_10 = F_43 ( V_160 , V_123 , V_125 ,
V_125 + V_159 -> V_135 ,
V_159 -> V_102 ,
V_159 -> V_118 ,
V_159 -> V_124 ) ;
if ( V_10 != 0 )
goto V_162;
if ( V_9 < V_159 -> V_161 )
V_126 [ V_9 ] = ( void * ) V_160 - V_125 ;
++ V_9 ;
if ( strcmp ( F_13 ( V_160 ) -> V_112 . V_132 . V_99 ,
V_163 ) == 0 )
++ V_123 -> V_164 ;
}
if ( V_10 != 0 )
goto V_162;
V_10 = - V_154 ;
if ( V_9 != V_159 -> V_161 )
goto V_162;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
if ( ! ( V_159 -> V_124 & ( 1 << V_9 ) ) )
continue;
if ( V_123 -> V_102 [ V_9 ] == 0xFFFFFFFF )
goto V_162;
if ( V_123 -> V_118 [ V_9 ] == 0xFFFFFFFF )
goto V_162;
}
if ( ! F_30 ( V_123 , V_159 -> V_124 , V_125 , V_126 ) ) {
V_10 = - V_165 ;
goto V_162;
}
F_50 ( V_126 ) ;
V_9 = 0 ;
F_49 (iter, entry0, newinfo->size) {
V_10 = F_34 ( V_160 , V_159 -> V_99 , V_159 -> V_135 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_49 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_46 ( V_160 ) ;
}
return V_10 ;
}
return V_10 ;
V_162:
F_50 ( V_126 ) ;
return V_10 ;
}
static void F_51 ( const struct V_94 * V_108 ,
struct V_109 V_111 [] )
{
struct V_77 * V_160 ;
unsigned int V_92 ;
unsigned int V_9 ;
F_52 (cpu) {
T_3 * V_166 = & F_53 ( V_167 , V_92 ) ;
V_9 = 0 ;
F_49 (iter, t->entries, t->size) {
struct V_109 * V_168 ;
T_4 V_169 , V_129 ;
unsigned int V_170 ;
V_168 = F_54 ( & V_160 -> V_111 , V_92 ) ;
do {
V_170 = F_55 ( V_166 ) ;
V_169 = V_168 -> V_169 ;
V_129 = V_168 -> V_129 ;
} while ( F_56 ( V_166 , V_170 ) );
F_26 ( V_111 [ V_9 ] , V_169 , V_129 ) ;
++ V_9 ;
}
}
}
static struct V_109 * F_57 ( const struct V_1 * V_85 )
{
unsigned int V_171 ;
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
V_171 = sizeof( struct V_109 ) * V_95 -> V_139 ;
V_111 = F_58 ( V_171 ) ;
if ( V_111 == NULL )
return F_59 ( - V_145 ) ;
F_51 ( V_95 , V_111 ) ;
return V_111 ;
}
static int F_60 ( unsigned int V_172 ,
const struct V_1 * V_85 ,
void T_5 * V_173 )
{
unsigned int V_174 , V_175 ;
const struct V_77 * V_78 ;
struct V_109 * V_111 ;
struct V_94 * V_95 = V_85 -> V_95 ;
int V_10 = 0 ;
void * V_176 ;
V_111 = F_57 ( V_85 ) ;
if ( F_38 ( V_111 ) )
return F_39 ( V_111 ) ;
V_176 = V_95 -> V_101 ;
if ( F_61 ( V_173 , V_176 , V_172 ) != 0 ) {
V_10 = - V_177 ;
goto V_178;
}
for ( V_174 = 0 , V_175 = 0 ; V_174 < V_172 ; V_174 += V_78 -> V_82 , V_175 ++ ) {
const struct V_76 * V_108 ;
V_78 = (struct V_77 * ) ( V_176 + V_174 ) ;
if ( F_61 ( V_173 + V_174
+ F_62 ( struct V_77 , V_111 ) ,
& V_111 [ V_175 ] ,
sizeof( V_111 [ V_175 ] ) ) != 0 ) {
V_10 = - V_177 ;
goto V_178;
}
V_108 = F_12 ( V_78 ) ;
if ( F_61 ( V_173 + V_174 + V_78 -> V_122
+ F_62 ( struct V_76 ,
V_112 . V_132 . V_99 ) ,
V_108 -> V_112 . V_113 . V_114 -> V_99 ,
strlen ( V_108 -> V_112 . V_113 . V_114 -> V_99 ) + 1 ) != 0 ) {
V_10 = - V_177 ;
goto V_178;
}
}
V_178:
F_63 ( V_111 ) ;
return V_10 ;
}
static void F_64 ( void * V_179 , const void * V_55 )
{
int V_115 = * ( V_180 * ) V_55 ;
if ( V_115 > 0 )
V_115 += F_65 ( V_106 , V_115 ) ;
memcpy ( V_179 , & V_115 , sizeof( V_115 ) ) ;
}
static int F_66 ( void T_5 * V_179 , const void * V_55 )
{
V_180 V_181 = * ( int * ) V_55 ;
if ( V_181 > 0 )
V_181 -= F_65 ( V_106 , V_181 ) ;
return F_61 ( V_179 , & V_181 , sizeof( V_181 ) ) ? - V_177 : 0 ;
}
static int F_67 ( const struct V_77 * V_78 ,
const struct V_94 * V_2 ,
const void * V_79 , struct V_94 * V_123 )
{
const struct V_76 * V_108 ;
unsigned int V_182 ;
int V_174 , V_9 , V_10 ;
V_174 = sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_78 - V_79 ;
V_108 = F_12 ( V_78 ) ;
V_174 += F_68 ( V_108 -> V_112 . V_113 . V_114 ) ;
V_123 -> V_135 -= V_174 ;
V_10 = F_69 ( V_106 , V_182 , V_174 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
if ( V_2 -> V_102 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_102 [ V_9 ] ) ) )
V_123 -> V_102 [ V_9 ] -= V_174 ;
if ( V_2 -> V_118 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_118 [ V_9 ] ) ) )
V_123 -> V_118 [ V_9 ] -= V_174 ;
}
return 0 ;
}
static int F_70 ( const struct V_94 * V_2 ,
struct V_94 * V_123 )
{
struct V_77 * V_160 ;
const void * V_176 ;
int V_10 ;
if ( ! V_123 || ! V_2 )
return - V_154 ;
memcpy ( V_123 , V_2 , F_62 ( struct V_94 , V_101 ) ) ;
V_123 -> V_184 = 0 ;
V_176 = V_2 -> V_101 ;
F_71 ( V_106 , V_2 -> V_139 ) ;
F_49 (iter, loc_cpu_entry, info->size) {
V_10 = F_67 ( V_160 , V_2 , V_176 , V_123 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_72 ( struct V_103 * V_103 , void T_5 * V_132 ,
const int * V_8 , int V_185 )
{
char V_99 [ V_186 ] ;
struct V_1 * V_108 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_187 ) )
return - V_154 ;
if ( F_73 ( V_99 , V_132 , sizeof( V_99 ) ) != 0 )
return - V_177 ;
V_99 [ V_186 - 1 ] = '\0' ;
#ifdef F_74
if ( V_185 )
F_75 ( V_106 ) ;
#endif
V_108 = F_76 ( F_77 ( V_103 , V_106 , V_99 ) ,
L_2 , V_99 ) ;
if ( ! F_78 ( V_108 ) ) {
struct V_187 V_2 ;
const struct V_94 * V_95 = V_108 -> V_95 ;
#ifdef F_74
struct V_94 V_168 ;
if ( V_185 ) {
V_10 = F_70 ( V_95 , & V_168 ) ;
F_79 ( V_106 ) ;
V_95 = & V_168 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_124 = V_108 -> V_124 ;
memcpy ( V_2 . V_102 , V_95 -> V_102 ,
sizeof( V_2 . V_102 ) ) ;
memcpy ( V_2 . V_118 , V_95 -> V_118 ,
sizeof( V_2 . V_118 ) ) ;
V_2 . V_161 = V_95 -> V_139 ;
V_2 . V_135 = V_95 -> V_135 ;
strcpy ( V_2 . V_99 , V_99 ) ;
if ( F_61 ( V_132 , & V_2 , * V_8 ) != 0 )
V_10 = - V_177 ;
else
V_10 = 0 ;
F_80 ( V_108 ) ;
F_40 ( V_108 -> V_148 ) ;
} else
V_10 = V_108 ? F_39 ( V_108 ) : - V_188 ;
#ifdef F_74
if ( V_185 )
F_81 ( V_106 ) ;
#endif
return V_10 ;
}
static int F_82 ( struct V_103 * V_103 , struct V_189 T_5 * V_190 ,
const int * V_8 )
{
int V_10 ;
struct V_189 V_191 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_191 ) )
return - V_154 ;
if ( F_73 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_177 ;
if ( * V_8 != sizeof( struct V_189 ) + V_191 . V_135 )
return - V_154 ;
V_191 . V_99 [ sizeof( V_191 . V_99 ) - 1 ] = '\0' ;
V_108 = F_77 ( V_103 , V_106 , V_191 . V_99 ) ;
if ( ! F_78 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
if ( V_191 . V_135 == V_95 -> V_135 )
V_10 = F_60 ( V_95 -> V_135 ,
V_108 , V_190 -> V_192 ) ;
else
V_10 = - V_193 ;
F_40 ( V_108 -> V_148 ) ;
F_80 ( V_108 ) ;
} else
V_10 = V_108 ? F_39 ( V_108 ) : - V_188 ;
return V_10 ;
}
static int F_83 ( struct V_103 * V_103 , const char * V_99 ,
unsigned int V_124 ,
struct V_94 * V_123 ,
unsigned int V_194 ,
void T_5 * V_195 )
{
int V_10 ;
struct V_1 * V_108 ;
struct V_94 * V_196 ;
struct V_109 * V_111 ;
void * V_197 ;
struct V_77 * V_160 ;
V_10 = 0 ;
V_111 = F_58 ( V_194 * sizeof( struct V_109 ) ) ;
if ( ! V_111 ) {
V_10 = - V_145 ;
goto V_100;
}
V_108 = F_76 ( F_77 ( V_103 , V_106 , V_99 ) ,
L_2 , V_99 ) ;
if ( F_78 ( V_108 ) ) {
V_10 = V_108 ? F_39 ( V_108 ) : - V_188 ;
goto V_198;
}
if ( V_124 != V_108 -> V_124 ) {
V_10 = - V_154 ;
goto V_199;
}
V_196 = F_84 ( V_108 , V_194 , V_123 , & V_10 ) ;
if ( ! V_196 )
goto V_199;
if ( ( V_196 -> V_139 > V_196 -> V_184 ) ||
( V_123 -> V_139 <= V_196 -> V_184 ) )
F_40 ( V_108 -> V_148 ) ;
if ( ( V_196 -> V_139 > V_196 -> V_184 ) &&
( V_123 -> V_139 <= V_196 -> V_184 ) )
F_40 ( V_108 -> V_148 ) ;
F_51 ( V_196 , V_111 ) ;
V_197 = V_196 -> V_101 ;
F_49 (iter, loc_cpu_old_entry, oldinfo->size)
F_46 ( V_160 ) ;
F_85 ( V_196 ) ;
if ( F_61 ( V_195 , V_111 ,
sizeof( struct V_109 ) * V_194 ) != 0 ) {
F_86 ( L_3 ) ;
}
F_63 ( V_111 ) ;
F_80 ( V_108 ) ;
return V_10 ;
V_199:
F_40 ( V_108 -> V_148 ) ;
F_80 ( V_108 ) ;
V_198:
F_63 ( V_111 ) ;
V_100:
return V_10 ;
}
static int F_87 ( struct V_103 * V_103 , const void T_5 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
struct V_158 V_168 ;
struct V_94 * V_123 ;
void * V_176 ;
struct V_77 * V_160 ;
if ( F_73 ( & V_168 , V_132 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_194 >= V_200 / sizeof( struct V_109 ) )
return - V_145 ;
if ( V_168 . V_194 == 0 )
return - V_154 ;
V_168 . V_99 [ sizeof( V_168 . V_99 ) - 1 ] = 0 ;
V_123 = F_88 ( V_168 . V_135 ) ;
if ( ! V_123 )
return - V_145 ;
V_176 = V_123 -> V_101 ;
if ( F_73 ( V_176 , V_132 + sizeof( V_168 ) ,
V_168 . V_135 ) != 0 ) {
V_10 = - V_177 ;
goto V_201;
}
V_10 = F_47 ( V_123 , V_176 , & V_168 ) ;
if ( V_10 != 0 )
goto V_201;
V_10 = F_83 ( V_103 , V_168 . V_99 , V_168 . V_124 , V_123 ,
V_168 . V_194 , V_168 . V_111 ) ;
if ( V_10 )
goto V_202;
return 0 ;
V_202:
F_49 (iter, loc_cpu_entry, newinfo->size)
F_46 ( V_160 ) ;
V_201:
F_85 ( V_123 ) ;
return V_10 ;
}
static int F_89 ( struct V_103 * V_103 , const void T_5 * V_132 ,
unsigned int V_8 , int V_185 )
{
unsigned int V_9 ;
struct V_203 V_168 ;
struct V_109 * V_204 ;
struct V_1 * V_108 ;
const struct V_94 * V_95 ;
int V_10 = 0 ;
struct V_77 * V_160 ;
unsigned int V_97 ;
V_204 = F_90 ( V_132 , V_8 , & V_168 , V_185 ) ;
if ( F_38 ( V_204 ) )
return F_39 ( V_204 ) ;
V_108 = F_77 ( V_103 , V_106 , V_168 . V_99 ) ;
if ( F_78 ( V_108 ) ) {
V_10 = V_108 ? F_39 ( V_108 ) : - V_188 ;
goto free;
}
F_20 () ;
V_95 = V_108 -> V_95 ;
if ( V_95 -> V_139 != V_168 . V_194 ) {
V_10 = - V_154 ;
goto V_205;
}
V_9 = 0 ;
V_97 = F_21 () ;
F_49 (iter, private->entries, private->size) {
struct V_109 * V_168 ;
V_168 = F_25 ( & V_160 -> V_111 ) ;
F_26 ( * V_168 , V_204 [ V_9 ] . V_169 , V_204 [ V_9 ] . V_129 ) ;
++ V_9 ;
}
F_27 ( V_97 ) ;
V_205:
F_28 () ;
F_80 ( V_108 ) ;
F_40 ( V_108 -> V_148 ) ;
free:
F_63 ( V_204 ) ;
return V_10 ;
}
static inline void F_91 ( struct V_183 * V_78 )
{
struct V_76 * V_108 ;
V_108 = F_92 ( V_78 ) ;
F_40 ( V_108 -> V_112 . V_113 . V_114 -> V_148 ) ;
}
static int
F_93 ( struct V_183 * V_78 ,
struct V_94 * V_123 ,
unsigned int * V_135 ,
const unsigned char * V_79 ,
const unsigned char * V_150 )
{
struct V_76 * V_108 ;
struct V_144 * V_114 ;
unsigned int V_182 ;
int V_10 , V_174 ;
if ( ( unsigned long ) V_78 % F_44 ( struct V_183 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_183 ) >= V_150 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_150 )
return - V_154 ;
if ( V_78 -> V_82 < sizeof( struct V_183 ) +
sizeof( struct V_206 ) )
return - V_154 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_154 ;
V_10 = F_94 ( V_78 , V_78 -> V_155 , V_78 -> V_122 ,
V_78 -> V_82 ) ;
if ( V_10 )
return V_10 ;
V_174 = sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_78 - ( void * ) V_79 ;
V_108 = F_92 ( V_78 ) ;
V_114 = F_37 ( V_106 , V_108 -> V_112 . V_132 . V_99 ,
V_108 -> V_112 . V_132 . V_146 ) ;
if ( F_38 ( V_114 ) ) {
V_10 = F_39 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_174 += F_68 ( V_114 ) ;
* V_135 += V_174 ;
V_10 = F_69 ( V_106 , V_182 , V_174 ) ;
if ( V_10 )
goto V_207;
return 0 ;
V_207:
F_40 ( V_108 -> V_112 . V_113 . V_114 -> V_148 ) ;
V_100:
return V_10 ;
}
static void
F_95 ( struct V_183 * V_78 , void * * V_208 ,
unsigned int * V_135 ,
struct V_94 * V_123 , unsigned char * V_79 )
{
struct V_76 * V_108 ;
struct V_144 * V_114 ;
struct V_77 * V_209 ;
unsigned int V_210 ;
int V_153 ;
V_210 = * V_135 ;
V_209 = (struct V_77 * ) * V_208 ;
memcpy ( V_209 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_209 -> V_111 , & V_78 -> V_111 , sizeof( V_78 -> V_111 ) ) ;
* V_208 += sizeof( struct V_77 ) ;
* V_135 += sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_209 -> V_122 = V_78 -> V_122 - ( V_210 - * V_135 ) ;
V_108 = F_92 ( V_78 ) ;
V_114 = V_108 -> V_112 . V_113 . V_114 ;
F_96 ( V_108 , V_208 , V_135 ) ;
V_209 -> V_82 = V_78 -> V_82 - ( V_210 - * V_135 ) ;
for ( V_153 = 0 ; V_153 < V_127 ; V_153 ++ ) {
if ( ( unsigned char * ) V_209 - V_79 < V_123 -> V_102 [ V_153 ] )
V_123 -> V_102 [ V_153 ] -= V_210 - * V_135 ;
if ( ( unsigned char * ) V_209 - V_79 < V_123 -> V_118 [ V_153 ] )
V_123 -> V_118 [ V_153 ] -= V_210 - * V_135 ;
}
}
static int F_97 ( struct V_94 * * V_211 ,
void * * V_212 ,
const struct V_213 * V_214 )
{
unsigned int V_9 , V_215 ;
struct V_94 * V_123 , * V_2 ;
void * V_128 , * V_125 , * V_216 ;
struct V_183 * V_217 ;
struct V_158 V_159 ;
unsigned int V_135 ;
int V_10 = 0 ;
V_2 = * V_211 ;
V_125 = * V_212 ;
V_135 = V_214 -> V_135 ;
V_2 -> V_139 = V_214 -> V_161 ;
V_215 = 0 ;
F_75 ( V_106 ) ;
F_71 ( V_106 , V_214 -> V_161 ) ;
F_49 (iter0, entry0, compatr->size) {
V_10 = F_93 ( V_217 , V_2 , & V_135 ,
V_125 ,
V_125 + V_214 -> V_135 ) ;
if ( V_10 != 0 )
goto V_218;
++ V_215 ;
}
V_10 = - V_154 ;
if ( V_215 != V_214 -> V_161 )
goto V_218;
V_10 = - V_145 ;
V_123 = F_88 ( V_135 ) ;
if ( ! V_123 )
goto V_218;
V_123 -> V_139 = V_214 -> V_161 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_123 -> V_102 [ V_9 ] = V_214 -> V_102 [ V_9 ] ;
V_123 -> V_118 [ V_9 ] = V_214 -> V_118 [ V_9 ] ;
}
V_216 = V_123 -> V_101 ;
V_128 = V_216 ;
V_135 = V_214 -> V_135 ;
F_49 (iter0, entry0, compatr->size)
F_95 ( V_217 , & V_128 , & V_135 ,
V_123 , V_216 ) ;
F_79 ( V_106 ) ;
F_81 ( V_106 ) ;
memcpy ( & V_159 , V_214 , sizeof( * V_214 ) ) ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_159 . V_102 [ V_9 ] = V_123 -> V_102 [ V_9 ] ;
V_159 . V_118 [ V_9 ] = V_123 -> V_118 [ V_9 ] ;
}
V_159 . V_194 = 0 ;
V_159 . V_111 = NULL ;
V_159 . V_135 = V_123 -> V_135 ;
V_10 = F_47 ( V_123 , V_216 , & V_159 ) ;
if ( V_10 )
goto V_201;
* V_211 = V_123 ;
* V_212 = V_216 ;
F_85 ( V_2 ) ;
return 0 ;
V_201:
F_85 ( V_123 ) ;
return V_10 ;
V_218:
F_79 ( V_106 ) ;
F_81 ( V_106 ) ;
F_49 (iter0, entry0, compatr->size) {
if ( V_215 -- == 0 )
break;
F_91 ( V_217 ) ;
}
return V_10 ;
}
static int F_98 ( struct V_103 * V_103 , void T_5 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
struct V_213 V_168 ;
struct V_94 * V_123 ;
void * V_176 ;
struct V_77 * V_160 ;
if ( F_73 ( & V_168 , V_132 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_194 >= V_200 / sizeof( struct V_109 ) )
return - V_145 ;
if ( V_168 . V_194 == 0 )
return - V_154 ;
V_168 . V_99 [ sizeof( V_168 . V_99 ) - 1 ] = 0 ;
V_123 = F_88 ( V_168 . V_135 ) ;
if ( ! V_123 )
return - V_145 ;
V_176 = V_123 -> V_101 ;
if ( F_73 ( V_176 , V_132 + sizeof( V_168 ) , V_168 . V_135 ) != 0 ) {
V_10 = - V_177 ;
goto V_201;
}
V_10 = F_97 ( & V_123 , & V_176 , & V_168 ) ;
if ( V_10 != 0 )
goto V_201;
V_10 = F_83 ( V_103 , V_168 . V_99 , V_168 . V_124 , V_123 ,
V_168 . V_194 , F_99 ( V_168 . V_111 ) ) ;
if ( V_10 )
goto V_202;
return 0 ;
V_202:
F_49 (iter, loc_cpu_entry, newinfo->size)
F_46 ( V_160 ) ;
V_201:
F_85 ( V_123 ) ;
return V_10 ;
}
static int F_100 ( struct V_219 * V_220 , int V_221 , void T_5 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_101 ( F_102 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_10 = F_98 ( F_102 ( V_220 ) , V_132 , V_8 ) ;
break;
case V_226 :
V_10 = F_89 ( F_102 ( V_220 ) , V_132 , V_8 , 1 ) ;
break;
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static int F_103 ( struct V_77 * V_78 , void T_5 * * V_208 ,
T_6 * V_135 ,
struct V_109 * V_111 ,
unsigned int V_9 )
{
struct V_76 * V_108 ;
struct V_183 T_5 * V_227 ;
T_7 V_122 , V_82 ;
T_6 V_210 ;
int V_10 ;
V_210 = * V_135 ;
V_227 = (struct V_183 T_5 * ) * V_208 ;
if ( F_61 ( V_227 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_61 ( & V_227 -> V_111 , & V_111 [ V_9 ] ,
sizeof( V_111 [ V_9 ] ) ) != 0 )
return - V_177 ;
* V_208 += sizeof( struct V_183 ) ;
* V_135 -= sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_122 = V_78 -> V_122 - ( V_210 - * V_135 ) ;
V_108 = F_13 ( V_78 ) ;
V_10 = F_104 ( V_108 , V_208 , V_135 ) ;
if ( V_10 )
return V_10 ;
V_82 = V_78 -> V_82 - ( V_210 - * V_135 ) ;
if ( F_105 ( V_122 , & V_227 -> V_122 ) != 0 ||
F_105 ( V_82 , & V_227 -> V_82 ) != 0 )
return - V_177 ;
return 0 ;
}
static int F_106 ( unsigned int V_172 ,
struct V_1 * V_85 ,
void T_5 * V_173 )
{
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
void T_5 * V_128 ;
unsigned int V_135 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_160 ;
V_111 = F_57 ( V_85 ) ;
if ( F_38 ( V_111 ) )
return F_39 ( V_111 ) ;
V_128 = V_173 ;
V_135 = V_172 ;
F_49 (iter, private->entries, total_size) {
V_10 = F_103 ( V_160 , & V_128 ,
& V_135 , V_111 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_63 ( V_111 ) ;
return V_10 ;
}
static int F_107 ( struct V_103 * V_103 ,
struct V_228 T_5 * V_190 ,
int * V_8 )
{
int V_10 ;
struct V_228 V_191 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_191 ) )
return - V_154 ;
if ( F_73 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_177 ;
if ( * V_8 != sizeof( struct V_228 ) + V_191 . V_135 )
return - V_154 ;
V_191 . V_99 [ sizeof( V_191 . V_99 ) - 1 ] = '\0' ;
F_75 ( V_106 ) ;
V_108 = F_77 ( V_103 , V_106 , V_191 . V_99 ) ;
if ( ! F_78 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
struct V_94 V_2 ;
V_10 = F_70 ( V_95 , & V_2 ) ;
if ( ! V_10 && V_191 . V_135 == V_2 . V_135 ) {
V_10 = F_106 ( V_95 -> V_135 ,
V_108 , V_190 -> V_192 ) ;
} else if ( ! V_10 )
V_10 = - V_193 ;
F_79 ( V_106 ) ;
F_40 ( V_108 -> V_148 ) ;
F_80 ( V_108 ) ;
} else
V_10 = V_108 ? F_39 ( V_108 ) : - V_188 ;
F_81 ( V_106 ) ;
return V_10 ;
}
static int F_108 ( struct V_219 * V_220 , int V_221 , void T_5 * V_132 ,
int * V_8 )
{
int V_10 ;
if ( ! F_101 ( F_102 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_229 :
V_10 = F_72 ( F_102 ( V_220 ) , V_132 , V_8 , 1 ) ;
break;
case V_230 :
V_10 = F_107 ( F_102 ( V_220 ) , V_132 , V_8 ) ;
break;
default:
V_10 = F_109 ( V_220 , V_221 , V_132 , V_8 ) ;
}
return V_10 ;
}
static int F_110 ( struct V_219 * V_220 , int V_221 , void T_5 * V_132 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_101 ( F_102 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_10 = F_87 ( F_102 ( V_220 ) , V_132 , V_8 ) ;
break;
case V_226 :
V_10 = F_89 ( F_102 ( V_220 ) , V_132 , V_8 , 0 ) ;
break;
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static int F_109 ( struct V_219 * V_220 , int V_221 , void T_5 * V_132 , int * V_8 )
{
int V_10 ;
if ( ! F_101 ( F_102 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_229 :
V_10 = F_72 ( F_102 ( V_220 ) , V_132 , V_8 , 0 ) ;
break;
case V_230 :
V_10 = F_82 ( F_102 ( V_220 ) , V_132 , V_8 ) ;
break;
case V_231 : {
struct V_232 V_233 ;
if ( * V_8 != sizeof( V_233 ) ) {
V_10 = - V_154 ;
break;
}
if ( F_73 ( & V_233 , V_132 , sizeof( V_233 ) ) != 0 ) {
V_10 = - V_177 ;
break;
}
V_233 . V_99 [ sizeof( V_233 . V_99 ) - 1 ] = 0 ;
F_76 ( F_111 ( V_106 , V_233 . V_99 ,
V_233 . V_146 , 1 , & V_10 ) ,
L_4 , V_233 . V_99 ) ;
break;
}
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static void F_112 ( struct V_1 * V_85 )
{
struct V_94 * V_95 ;
void * V_176 ;
struct V_234 * V_235 = V_85 -> V_148 ;
struct V_77 * V_160 ;
V_95 = F_113 ( V_85 ) ;
V_176 = V_95 -> V_101 ;
F_49 (iter, loc_cpu_entry, private->size)
F_46 ( V_160 ) ;
if ( V_95 -> V_139 > V_95 -> V_184 )
F_40 ( V_235 ) ;
F_85 ( V_95 ) ;
}
int F_114 ( struct V_103 * V_103 ,
const struct V_1 * V_85 ,
const struct V_158 * V_159 ,
const struct V_236 * V_237 ,
struct V_1 * * V_238 )
{
int V_10 ;
struct V_94 * V_123 ;
struct V_94 V_239 = { 0 } ;
void * V_176 ;
struct V_1 * V_240 ;
V_123 = F_88 ( V_159 -> V_135 ) ;
if ( ! V_123 )
return - V_145 ;
V_176 = V_123 -> V_101 ;
memcpy ( V_176 , V_159 -> V_101 , V_159 -> V_135 ) ;
V_10 = F_47 ( V_123 , V_176 , V_159 ) ;
if ( V_10 != 0 )
goto V_162;
V_240 = F_115 ( V_103 , V_85 , & V_239 , V_123 ) ;
if ( F_38 ( V_240 ) ) {
V_10 = F_39 ( V_240 ) ;
goto V_162;
}
F_116 ( * V_238 , V_240 ) ;
V_10 = F_117 ( V_103 , V_237 , F_118 ( V_85 -> V_124 ) ) ;
if ( V_10 != 0 ) {
F_112 ( V_240 ) ;
* V_238 = NULL ;
}
return V_10 ;
V_162:
F_85 ( V_123 ) ;
return V_10 ;
}
void F_119 ( struct V_103 * V_103 , struct V_1 * V_85 ,
const struct V_236 * V_237 )
{
F_120 ( V_103 , V_237 , F_118 ( V_85 -> V_124 ) ) ;
F_112 ( V_85 ) ;
}
static int T_8 F_121 ( struct V_103 * V_103 )
{
return F_122 ( V_103 , V_106 ) ;
}
static void T_9 F_123 ( struct V_103 * V_103 )
{
F_124 ( V_103 , V_106 ) ;
}
static int T_10 F_125 ( void )
{
int V_10 ;
V_10 = F_126 ( & V_241 ) ;
if ( V_10 < 0 )
goto V_242;
V_10 = F_127 ( V_243 , F_128 ( V_243 ) ) ;
if ( V_10 < 0 )
goto V_244;
V_10 = F_129 ( & V_245 ) ;
if ( V_10 < 0 )
goto V_246;
F_130 ( L_5 ) ;
return 0 ;
V_246:
F_131 ( V_243 , F_128 ( V_243 ) ) ;
V_244:
F_132 ( & V_241 ) ;
V_242:
return V_10 ;
}
static void T_11 F_133 ( void )
{
F_134 ( & V_245 ) ;
F_131 ( V_243 , F_128 ( V_243 ) ) ;
F_132 ( & V_241 ) ;
}
