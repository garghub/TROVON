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
V_96 . V_84 = V_84 ;
V_96 . V_103 = false ;
V_65 = F_24 ( V_71 ) ;
do {
const struct V_76 * V_104 ;
struct V_105 * V_106 ;
if ( ! F_7 ( V_65 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_65 ) ) {
V_78 = F_15 ( V_78 ) ;
continue;
}
V_106 = F_25 ( & V_78 -> V_107 ) ;
F_26 ( * V_106 , F_19 ( V_71 -> V_22 ) , 1 ) ;
V_104 = F_12 ( V_78 ) ;
if ( ! V_104 -> V_108 . V_109 . V_110 -> V_110 ) {
int V_111 ;
V_111 = ( (struct V_112 * ) V_104 ) -> V_89 ;
if ( V_111 < 0 ) {
if ( V_111 != V_113 ) {
V_89 = ( unsigned int ) ( - V_111 ) - 1 ;
break;
}
if ( V_93 == 0 ) {
V_78 = F_14 ( V_91 ,
V_95 -> V_114 [ V_86 ] ) ;
} else {
V_78 = V_90 [ -- V_93 ] ;
V_78 = F_15 ( V_78 ) ;
}
continue;
}
if ( V_91 + V_111
!= F_15 ( V_78 ) ) {
V_90 [ V_93 ++ ] = V_78 ;
}
V_78 = F_14 ( V_91 , V_111 ) ;
continue;
}
V_96 . V_110 = V_104 -> V_108 . V_109 . V_110 ;
V_96 . V_74 = V_104 -> V_115 ;
V_89 = V_104 -> V_108 . V_109 . V_110 -> V_110 ( V_71 , & V_96 ) ;
V_65 = F_24 ( V_71 ) ;
if ( V_89 == V_116 )
V_78 = F_15 ( V_78 ) ;
else
break;
} while ( ! V_96 . V_103 );
F_27 ( V_97 ) ;
F_28 () ;
if ( V_96 . V_103 )
return V_75 ;
else
return V_89 ;
}
static inline bool F_29 ( const struct V_77 * V_78 )
{
static const struct V_25 V_117 ;
return V_78 -> V_118 == sizeof( struct V_77 ) &&
memcmp ( & V_78 -> V_65 , & V_117 , sizeof( V_117 ) ) == 0 ;
}
static int F_30 ( const struct V_94 * V_119 ,
unsigned int V_120 , void * V_121 ,
unsigned int * V_122 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_123 ; V_86 ++ ) {
unsigned int V_124 = V_119 -> V_102 [ V_86 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_121 + V_124 ) ;
if ( ! ( V_120 & ( 1 << V_86 ) ) )
continue;
V_78 -> V_107 . V_125 = V_124 ;
for (; ; ) {
const struct V_112 * V_104
= ( void * ) F_12 ( V_78 ) ;
int V_126 = V_78 -> V_127 & ( 1 << V_86 ) ;
if ( V_78 -> V_127 & ( 1 << V_123 ) )
return 0 ;
V_78 -> V_127
|= ( ( 1 << V_86 ) | ( 1 << V_123 ) ) ;
if ( ( F_29 ( V_78 ) &&
( strcmp ( V_104 -> V_110 . V_108 . V_128 . V_99 ,
V_129 ) == 0 ) &&
V_104 -> V_89 < 0 ) || V_126 ) {
unsigned int V_130 , V_131 ;
if ( ( strcmp ( V_104 -> V_110 . V_108 . V_128 . V_99 ,
V_129 ) == 0 ) &&
V_104 -> V_89 < - V_132 - 1 )
return 0 ;
do {
V_78 -> V_127 ^= ( 1 << V_123 ) ;
V_130 = V_124 ;
V_124 = V_78 -> V_107 . V_125 ;
V_78 -> V_107 . V_125 = 0 ;
if ( V_124 == V_130 )
goto V_133;
V_78 = (struct V_77 * )
( V_121 + V_124 ) ;
} while ( V_130 == V_124 + V_78 -> V_82 );
V_131 = V_78 -> V_82 ;
V_78 = (struct V_77 * )
( V_121 + V_124 + V_131 ) ;
if ( V_124 + V_131 >= V_119 -> V_131 )
return 0 ;
V_78 -> V_107 . V_125 = V_124 ;
V_124 += V_131 ;
} else {
int V_134 = V_104 -> V_89 ;
if ( strcmp ( V_104 -> V_110 . V_108 . V_128 . V_99 ,
V_129 ) == 0 &&
V_134 >= 0 ) {
if ( ! F_31 ( V_122 , V_134 ,
V_119 -> V_135 ) )
return 0 ;
V_78 = (struct V_77 * )
( V_121 + V_134 ) ;
} else {
V_134 = V_124 + V_78 -> V_82 ;
if ( V_134 >= V_119 -> V_131 )
return 0 ;
}
V_78 = (struct V_77 * )
( V_121 + V_134 ) ;
V_78 -> V_107 . V_125 = V_124 ;
V_124 = V_134 ;
}
}
V_133: ;
}
return 1 ;
}
static inline int F_32 ( struct V_77 * V_78 , const char * V_99 )
{
struct V_76 * V_104 = F_13 ( V_78 ) ;
struct V_136 V_73 = {
. V_85 = V_99 ,
. V_137 = V_78 ,
. V_110 = V_104 -> V_108 . V_109 . V_110 ,
. V_74 = V_104 -> V_115 ,
. V_138 = V_78 -> V_127 ,
. V_139 = V_140 ,
} ;
return F_33 ( & V_73 , V_104 -> V_108 . V_141 - sizeof( * V_104 ) , 0 , false ) ;
}
static inline int
F_34 ( struct V_77 * V_78 , const char * V_99 , unsigned int V_131 ,
struct V_142 * V_143 )
{
struct V_76 * V_104 ;
struct V_144 * V_110 ;
int V_10 ;
if ( ! F_35 ( V_143 , & V_78 -> V_107 ) )
return - V_145 ;
V_104 = F_13 ( V_78 ) ;
V_110 = F_36 ( V_140 , V_104 -> V_108 . V_128 . V_99 ,
V_104 -> V_108 . V_128 . V_146 ) ;
if ( F_37 ( V_110 ) ) {
V_10 = F_38 ( V_110 ) ;
goto V_100;
}
V_104 -> V_108 . V_109 . V_110 = V_110 ;
V_10 = F_32 ( V_78 , V_99 ) ;
if ( V_10 )
goto V_147;
return 0 ;
V_147:
F_39 ( V_104 -> V_108 . V_109 . V_110 -> V_148 ) ;
V_100:
F_40 ( & V_78 -> V_107 ) ;
return V_10 ;
}
static bool F_41 ( const struct V_77 * V_78 )
{
const struct V_76 * V_104 ;
unsigned int V_89 ;
if ( ! F_29 ( V_78 ) )
return false ;
V_104 = F_12 ( V_78 ) ;
if ( strcmp ( V_104 -> V_108 . V_128 . V_99 , V_129 ) != 0 )
return false ;
V_89 = ( (struct V_112 * ) V_104 ) -> V_89 ;
V_89 = - V_89 - 1 ;
return V_89 == V_75 || V_89 == V_149 ;
}
static inline int F_42 ( struct V_77 * V_78 ,
struct V_94 * V_119 ,
const unsigned char * V_79 ,
const unsigned char * V_150 ,
const unsigned int * V_151 ,
const unsigned int * V_152 ,
unsigned int V_120 )
{
unsigned int V_153 ;
int V_147 ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_150 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_150 )
return - V_154 ;
if ( V_78 -> V_82
< sizeof( struct V_77 ) + sizeof( struct V_76 ) )
return - V_154 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_154 ;
V_147 = F_44 ( V_78 , V_78 -> V_155 , V_78 -> V_118 ,
V_78 -> V_82 ) ;
if ( V_147 )
return V_147 ;
for ( V_153 = 0 ; V_153 < V_123 ; V_153 ++ ) {
if ( ! ( V_120 & ( 1 << V_153 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_151 [ V_153 ] )
V_119 -> V_102 [ V_153 ] = V_151 [ V_153 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_152 [ V_153 ] ) {
if ( ! F_41 ( V_78 ) )
return - V_154 ;
V_119 -> V_114 [ V_153 ] = V_152 [ V_153 ] ;
}
}
V_78 -> V_107 = ( (struct V_105 ) { 0 , 0 } ) ;
V_78 -> V_127 = 0 ;
return 0 ;
}
static inline void F_45 ( struct V_77 * V_78 )
{
struct V_156 V_73 ;
struct V_76 * V_104 ;
V_104 = F_13 ( V_78 ) ;
V_73 . V_110 = V_104 -> V_108 . V_109 . V_110 ;
V_73 . V_74 = V_104 -> V_115 ;
V_73 . V_139 = V_140 ;
if ( V_73 . V_110 -> V_157 != NULL )
V_73 . V_110 -> V_157 ( & V_73 ) ;
F_39 ( V_73 . V_110 -> V_148 ) ;
F_40 ( & V_78 -> V_107 ) ;
}
static int F_46 ( struct V_94 * V_119 , void * V_121 ,
const struct V_158 * V_159 )
{
struct V_142 V_143 = { 0 } ;
struct V_77 * V_160 ;
unsigned int * V_122 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_119 -> V_131 = V_159 -> V_131 ;
V_119 -> V_135 = V_159 -> V_161 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_119 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_119 -> V_114 [ V_9 ] = 0xFFFFFFFF ;
}
V_122 = F_47 ( V_119 -> V_135 ) ;
if ( ! V_122 )
return - V_145 ;
V_9 = 0 ;
F_48 (iter, entry0, newinfo->size) {
V_10 = F_42 ( V_160 , V_119 , V_121 ,
V_121 + V_159 -> V_131 ,
V_159 -> V_102 ,
V_159 -> V_114 ,
V_159 -> V_120 ) ;
if ( V_10 != 0 )
goto V_162;
if ( V_9 < V_159 -> V_161 )
V_122 [ V_9 ] = ( void * ) V_160 - V_121 ;
++ V_9 ;
if ( strcmp ( F_13 ( V_160 ) -> V_108 . V_128 . V_99 ,
V_163 ) == 0 )
++ V_119 -> V_164 ;
}
if ( V_10 != 0 )
goto V_162;
V_10 = - V_154 ;
if ( V_9 != V_159 -> V_161 )
goto V_162;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
if ( ! ( V_159 -> V_120 & ( 1 << V_9 ) ) )
continue;
if ( V_119 -> V_102 [ V_9 ] == 0xFFFFFFFF )
goto V_162;
if ( V_119 -> V_114 [ V_9 ] == 0xFFFFFFFF )
goto V_162;
}
if ( ! F_30 ( V_119 , V_159 -> V_120 , V_121 , V_122 ) ) {
V_10 = - V_165 ;
goto V_162;
}
F_49 ( V_122 ) ;
V_9 = 0 ;
F_48 (iter, entry0, newinfo->size) {
V_10 = F_34 ( V_160 , V_159 -> V_99 , V_159 -> V_131 ,
& V_143 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_48 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_45 ( V_160 ) ;
}
return V_10 ;
}
return V_10 ;
V_162:
F_49 ( V_122 ) ;
return V_10 ;
}
static void F_50 ( const struct V_94 * V_104 ,
struct V_105 V_107 [] )
{
struct V_77 * V_160 ;
unsigned int V_92 ;
unsigned int V_9 ;
F_51 (cpu) {
T_3 * V_166 = & F_52 ( V_167 , V_92 ) ;
V_9 = 0 ;
F_48 (iter, t->entries, t->size) {
struct V_105 * V_168 ;
T_4 V_169 , V_125 ;
unsigned int V_170 ;
V_168 = F_53 ( & V_160 -> V_107 , V_92 ) ;
do {
V_170 = F_54 ( V_166 ) ;
V_169 = V_168 -> V_169 ;
V_125 = V_168 -> V_125 ;
} while ( F_55 ( V_166 , V_170 ) );
F_26 ( V_107 [ V_9 ] , V_169 , V_125 ) ;
++ V_9 ;
}
}
}
static struct V_105 * F_56 ( const struct V_1 * V_85 )
{
unsigned int V_171 ;
struct V_105 * V_107 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
V_171 = sizeof( struct V_105 ) * V_95 -> V_135 ;
V_107 = F_57 ( V_171 ) ;
if ( V_107 == NULL )
return F_58 ( - V_145 ) ;
F_50 ( V_95 , V_107 ) ;
return V_107 ;
}
static int F_59 ( unsigned int V_172 ,
const struct V_1 * V_85 ,
void T_5 * V_173 )
{
unsigned int V_174 , V_175 ;
const struct V_77 * V_78 ;
struct V_105 * V_107 ;
struct V_94 * V_95 = V_85 -> V_95 ;
int V_10 = 0 ;
void * V_176 ;
V_107 = F_56 ( V_85 ) ;
if ( F_37 ( V_107 ) )
return F_38 ( V_107 ) ;
V_176 = V_95 -> V_101 ;
for ( V_174 = 0 , V_175 = 0 ; V_174 < V_172 ; V_174 += V_78 -> V_82 , V_175 ++ ) {
const struct V_76 * V_104 ;
V_78 = (struct V_77 * ) ( V_176 + V_174 ) ;
if ( F_60 ( V_173 + V_174 , V_78 , sizeof( * V_78 ) ) ) {
V_10 = - V_177 ;
goto V_178;
}
if ( F_60 ( V_173 + V_174
+ F_61 ( struct V_77 , V_107 ) ,
& V_107 [ V_175 ] ,
sizeof( V_107 [ V_175 ] ) ) != 0 ) {
V_10 = - V_177 ;
goto V_178;
}
V_104 = F_12 ( V_78 ) ;
if ( F_62 ( V_104 , V_173 + V_174 + V_78 -> V_118 ) ) {
V_10 = - V_177 ;
goto V_178;
}
}
V_178:
F_63 ( V_107 ) ;
return V_10 ;
}
static void F_64 ( void * V_179 , const void * V_55 )
{
int V_111 = * ( V_180 * ) V_55 ;
if ( V_111 > 0 )
V_111 += F_65 ( V_140 , V_111 ) ;
memcpy ( V_179 , & V_111 , sizeof( V_111 ) ) ;
}
static int F_66 ( void T_5 * V_179 , const void * V_55 )
{
V_180 V_181 = * ( int * ) V_55 ;
if ( V_181 > 0 )
V_181 -= F_65 ( V_140 , V_181 ) ;
return F_60 ( V_179 , & V_181 , sizeof( V_181 ) ) ? - V_177 : 0 ;
}
static int F_67 ( const struct V_77 * V_78 ,
const struct V_94 * V_2 ,
const void * V_79 , struct V_94 * V_119 )
{
const struct V_76 * V_104 ;
unsigned int V_182 ;
int V_174 , V_9 , V_10 ;
V_174 = sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_78 - V_79 ;
V_104 = F_12 ( V_78 ) ;
V_174 += F_68 ( V_104 -> V_108 . V_109 . V_110 ) ;
V_119 -> V_131 -= V_174 ;
V_10 = F_69 ( V_140 , V_182 , V_174 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
if ( V_2 -> V_102 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_102 [ V_9 ] ) ) )
V_119 -> V_102 [ V_9 ] -= V_174 ;
if ( V_2 -> V_114 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_114 [ V_9 ] ) ) )
V_119 -> V_114 [ V_9 ] -= V_174 ;
}
return 0 ;
}
static int F_70 ( const struct V_94 * V_2 ,
struct V_94 * V_119 )
{
struct V_77 * V_160 ;
const void * V_176 ;
int V_10 ;
if ( ! V_119 || ! V_2 )
return - V_154 ;
memcpy ( V_119 , V_2 , F_61 ( struct V_94 , V_101 ) ) ;
V_119 -> V_184 = 0 ;
V_176 = V_2 -> V_101 ;
F_71 ( V_140 , V_2 -> V_135 ) ;
F_48 (iter, loc_cpu_entry, info->size) {
V_10 = F_67 ( V_160 , V_2 , V_176 , V_119 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_72 ( struct V_185 * V_185 , void T_5 * V_128 ,
const int * V_8 , int V_186 )
{
char V_99 [ V_187 ] ;
struct V_1 * V_104 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_188 ) )
return - V_154 ;
if ( F_73 ( V_99 , V_128 , sizeof( V_99 ) ) != 0 )
return - V_177 ;
V_99 [ V_187 - 1 ] = '\0' ;
#ifdef F_74
if ( V_186 )
F_75 ( V_140 ) ;
#endif
V_104 = F_76 ( F_77 ( V_185 , V_140 , V_99 ) ,
L_2 , V_99 ) ;
if ( V_104 ) {
struct V_188 V_2 ;
const struct V_94 * V_95 = V_104 -> V_95 ;
#ifdef F_74
struct V_94 V_168 ;
if ( V_186 ) {
V_10 = F_70 ( V_95 , & V_168 ) ;
F_78 ( V_140 ) ;
V_95 = & V_168 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_120 = V_104 -> V_120 ;
memcpy ( V_2 . V_102 , V_95 -> V_102 ,
sizeof( V_2 . V_102 ) ) ;
memcpy ( V_2 . V_114 , V_95 -> V_114 ,
sizeof( V_2 . V_114 ) ) ;
V_2 . V_161 = V_95 -> V_135 ;
V_2 . V_131 = V_95 -> V_131 ;
strcpy ( V_2 . V_99 , V_99 ) ;
if ( F_60 ( V_128 , & V_2 , * V_8 ) != 0 )
V_10 = - V_177 ;
else
V_10 = 0 ;
F_79 ( V_104 ) ;
F_39 ( V_104 -> V_148 ) ;
} else
V_10 = - V_189 ;
#ifdef F_74
if ( V_186 )
F_80 ( V_140 ) ;
#endif
return V_10 ;
}
static int F_81 ( struct V_185 * V_185 , struct V_190 T_5 * V_191 ,
const int * V_8 )
{
int V_10 ;
struct V_190 V_192 ;
struct V_1 * V_104 ;
if ( * V_8 < sizeof( V_192 ) )
return - V_154 ;
if ( F_73 ( & V_192 , V_191 , sizeof( V_192 ) ) != 0 )
return - V_177 ;
if ( * V_8 != sizeof( struct V_190 ) + V_192 . V_131 )
return - V_154 ;
V_192 . V_99 [ sizeof( V_192 . V_99 ) - 1 ] = '\0' ;
V_104 = F_77 ( V_185 , V_140 , V_192 . V_99 ) ;
if ( V_104 ) {
const struct V_94 * V_95 = V_104 -> V_95 ;
if ( V_192 . V_131 == V_95 -> V_131 )
V_10 = F_59 ( V_95 -> V_131 ,
V_104 , V_191 -> V_193 ) ;
else
V_10 = - V_194 ;
F_39 ( V_104 -> V_148 ) ;
F_79 ( V_104 ) ;
} else
V_10 = - V_189 ;
return V_10 ;
}
static int F_82 ( struct V_185 * V_185 , const char * V_99 ,
unsigned int V_120 ,
struct V_94 * V_119 ,
unsigned int V_195 ,
void T_5 * V_196 )
{
int V_10 ;
struct V_1 * V_104 ;
struct V_94 * V_197 ;
struct V_105 * V_107 ;
void * V_198 ;
struct V_77 * V_160 ;
V_10 = 0 ;
V_107 = F_57 ( V_195 * sizeof( struct V_105 ) ) ;
if ( ! V_107 ) {
V_10 = - V_145 ;
goto V_100;
}
V_104 = F_76 ( F_77 ( V_185 , V_140 , V_99 ) ,
L_2 , V_99 ) ;
if ( ! V_104 ) {
V_10 = - V_189 ;
goto V_199;
}
if ( V_120 != V_104 -> V_120 ) {
V_10 = - V_154 ;
goto V_200;
}
V_197 = F_83 ( V_104 , V_195 , V_119 , & V_10 ) ;
if ( ! V_197 )
goto V_200;
if ( ( V_197 -> V_135 > V_197 -> V_184 ) ||
( V_119 -> V_135 <= V_197 -> V_184 ) )
F_39 ( V_104 -> V_148 ) ;
if ( ( V_197 -> V_135 > V_197 -> V_184 ) &&
( V_119 -> V_135 <= V_197 -> V_184 ) )
F_39 ( V_104 -> V_148 ) ;
F_50 ( V_197 , V_107 ) ;
V_198 = V_197 -> V_101 ;
F_48 (iter, loc_cpu_old_entry, oldinfo->size)
F_45 ( V_160 ) ;
F_84 ( V_197 ) ;
if ( F_60 ( V_196 , V_107 ,
sizeof( struct V_105 ) * V_195 ) != 0 ) {
F_85 ( L_3 ) ;
}
F_63 ( V_107 ) ;
F_79 ( V_104 ) ;
return V_10 ;
V_200:
F_39 ( V_104 -> V_148 ) ;
F_79 ( V_104 ) ;
V_199:
F_63 ( V_107 ) ;
V_100:
return V_10 ;
}
static int F_86 ( struct V_185 * V_185 , const void T_5 * V_128 ,
unsigned int V_8 )
{
int V_10 ;
struct V_158 V_168 ;
struct V_94 * V_119 ;
void * V_176 ;
struct V_77 * V_160 ;
if ( F_73 ( & V_168 , V_128 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_195 >= V_201 / sizeof( struct V_105 ) )
return - V_145 ;
if ( V_168 . V_195 == 0 )
return - V_154 ;
V_168 . V_99 [ sizeof( V_168 . V_99 ) - 1 ] = 0 ;
V_119 = F_87 ( V_168 . V_131 ) ;
if ( ! V_119 )
return - V_145 ;
V_176 = V_119 -> V_101 ;
if ( F_73 ( V_176 , V_128 + sizeof( V_168 ) ,
V_168 . V_131 ) != 0 ) {
V_10 = - V_177 ;
goto V_202;
}
V_10 = F_46 ( V_119 , V_176 , & V_168 ) ;
if ( V_10 != 0 )
goto V_202;
V_10 = F_82 ( V_185 , V_168 . V_99 , V_168 . V_120 , V_119 ,
V_168 . V_195 , V_168 . V_107 ) ;
if ( V_10 )
goto V_203;
return 0 ;
V_203:
F_48 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_160 ) ;
V_202:
F_84 ( V_119 ) ;
return V_10 ;
}
static int F_88 ( struct V_185 * V_185 , const void T_5 * V_128 ,
unsigned int V_8 , int V_186 )
{
unsigned int V_9 ;
struct V_204 V_168 ;
struct V_105 * V_205 ;
struct V_1 * V_104 ;
const struct V_94 * V_95 ;
int V_10 = 0 ;
struct V_77 * V_160 ;
unsigned int V_97 ;
V_205 = F_89 ( V_128 , V_8 , & V_168 , V_186 ) ;
if ( F_37 ( V_205 ) )
return F_38 ( V_205 ) ;
V_104 = F_77 ( V_185 , V_140 , V_168 . V_99 ) ;
if ( ! V_104 ) {
V_10 = - V_189 ;
goto free;
}
F_20 () ;
V_95 = V_104 -> V_95 ;
if ( V_95 -> V_135 != V_168 . V_195 ) {
V_10 = - V_154 ;
goto V_206;
}
V_9 = 0 ;
V_97 = F_21 () ;
F_48 (iter, private->entries, private->size) {
struct V_105 * V_168 ;
V_168 = F_25 ( & V_160 -> V_107 ) ;
F_26 ( * V_168 , V_205 [ V_9 ] . V_169 , V_205 [ V_9 ] . V_125 ) ;
++ V_9 ;
}
F_27 ( V_97 ) ;
V_206:
F_28 () ;
F_79 ( V_104 ) ;
F_39 ( V_104 -> V_148 ) ;
free:
F_63 ( V_205 ) ;
return V_10 ;
}
static inline void F_90 ( struct V_183 * V_78 )
{
struct V_76 * V_104 ;
V_104 = F_91 ( V_78 ) ;
F_39 ( V_104 -> V_108 . V_109 . V_110 -> V_148 ) ;
}
static int
F_92 ( struct V_183 * V_78 ,
struct V_94 * V_119 ,
unsigned int * V_131 ,
const unsigned char * V_79 ,
const unsigned char * V_150 )
{
struct V_76 * V_104 ;
struct V_144 * V_110 ;
unsigned int V_182 ;
int V_10 , V_174 ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_183 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_183 ) >= V_150 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_150 )
return - V_154 ;
if ( V_78 -> V_82 < sizeof( struct V_183 ) +
sizeof( struct V_207 ) )
return - V_154 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_154 ;
V_10 = F_93 ( V_78 , V_78 -> V_155 , V_78 -> V_118 ,
V_78 -> V_82 ) ;
if ( V_10 )
return V_10 ;
V_174 = sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_78 - ( void * ) V_79 ;
V_104 = F_91 ( V_78 ) ;
V_110 = F_36 ( V_140 , V_104 -> V_108 . V_128 . V_99 ,
V_104 -> V_108 . V_128 . V_146 ) ;
if ( F_37 ( V_110 ) ) {
V_10 = F_38 ( V_110 ) ;
goto V_100;
}
V_104 -> V_108 . V_109 . V_110 = V_110 ;
V_174 += F_68 ( V_110 ) ;
* V_131 += V_174 ;
V_10 = F_69 ( V_140 , V_182 , V_174 ) ;
if ( V_10 )
goto V_208;
return 0 ;
V_208:
F_39 ( V_104 -> V_108 . V_109 . V_110 -> V_148 ) ;
V_100:
return V_10 ;
}
static void
F_94 ( struct V_183 * V_78 , void * * V_209 ,
unsigned int * V_131 ,
struct V_94 * V_119 , unsigned char * V_79 )
{
struct V_76 * V_104 ;
struct V_144 * V_110 ;
struct V_77 * V_210 ;
unsigned int V_211 ;
int V_153 ;
V_211 = * V_131 ;
V_210 = (struct V_77 * ) * V_209 ;
memcpy ( V_210 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_210 -> V_107 , & V_78 -> V_107 , sizeof( V_78 -> V_107 ) ) ;
* V_209 += sizeof( struct V_77 ) ;
* V_131 += sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_210 -> V_118 = V_78 -> V_118 - ( V_211 - * V_131 ) ;
V_104 = F_91 ( V_78 ) ;
V_110 = V_104 -> V_108 . V_109 . V_110 ;
F_95 ( V_104 , V_209 , V_131 ) ;
V_210 -> V_82 = V_78 -> V_82 - ( V_211 - * V_131 ) ;
for ( V_153 = 0 ; V_153 < V_123 ; V_153 ++ ) {
if ( ( unsigned char * ) V_210 - V_79 < V_119 -> V_102 [ V_153 ] )
V_119 -> V_102 [ V_153 ] -= V_211 - * V_131 ;
if ( ( unsigned char * ) V_210 - V_79 < V_119 -> V_114 [ V_153 ] )
V_119 -> V_114 [ V_153 ] -= V_211 - * V_131 ;
}
}
static int F_96 ( struct V_94 * * V_212 ,
void * * V_213 ,
const struct V_214 * V_215 )
{
unsigned int V_9 , V_216 ;
struct V_94 * V_119 , * V_2 ;
void * V_124 , * V_121 , * V_217 ;
struct V_183 * V_218 ;
struct V_158 V_159 ;
unsigned int V_131 ;
int V_10 = 0 ;
V_2 = * V_212 ;
V_121 = * V_213 ;
V_131 = V_215 -> V_131 ;
V_2 -> V_135 = V_215 -> V_161 ;
V_216 = 0 ;
F_75 ( V_140 ) ;
F_71 ( V_140 , V_215 -> V_161 ) ;
F_48 (iter0, entry0, compatr->size) {
V_10 = F_92 ( V_218 , V_2 , & V_131 ,
V_121 ,
V_121 + V_215 -> V_131 ) ;
if ( V_10 != 0 )
goto V_219;
++ V_216 ;
}
V_10 = - V_154 ;
if ( V_216 != V_215 -> V_161 )
goto V_219;
V_10 = - V_145 ;
V_119 = F_87 ( V_131 ) ;
if ( ! V_119 )
goto V_219;
V_119 -> V_135 = V_215 -> V_161 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_119 -> V_102 [ V_9 ] = V_215 -> V_102 [ V_9 ] ;
V_119 -> V_114 [ V_9 ] = V_215 -> V_114 [ V_9 ] ;
}
V_217 = V_119 -> V_101 ;
V_124 = V_217 ;
V_131 = V_215 -> V_131 ;
F_48 (iter0, entry0, compatr->size)
F_94 ( V_218 , & V_124 , & V_131 ,
V_119 , V_217 ) ;
F_78 ( V_140 ) ;
F_80 ( V_140 ) ;
memcpy ( & V_159 , V_215 , sizeof( * V_215 ) ) ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_159 . V_102 [ V_9 ] = V_119 -> V_102 [ V_9 ] ;
V_159 . V_114 [ V_9 ] = V_119 -> V_114 [ V_9 ] ;
}
V_159 . V_195 = 0 ;
V_159 . V_107 = NULL ;
V_159 . V_131 = V_119 -> V_131 ;
V_10 = F_46 ( V_119 , V_217 , & V_159 ) ;
if ( V_10 )
goto V_202;
* V_212 = V_119 ;
* V_213 = V_217 ;
F_84 ( V_2 ) ;
return 0 ;
V_202:
F_84 ( V_119 ) ;
return V_10 ;
V_219:
F_78 ( V_140 ) ;
F_80 ( V_140 ) ;
F_48 (iter0, entry0, compatr->size) {
if ( V_216 -- == 0 )
break;
F_90 ( V_218 ) ;
}
return V_10 ;
}
static int F_97 ( struct V_185 * V_185 , void T_5 * V_128 ,
unsigned int V_8 )
{
int V_10 ;
struct V_214 V_168 ;
struct V_94 * V_119 ;
void * V_176 ;
struct V_77 * V_160 ;
if ( F_73 ( & V_168 , V_128 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_195 >= V_201 / sizeof( struct V_105 ) )
return - V_145 ;
if ( V_168 . V_195 == 0 )
return - V_154 ;
V_168 . V_99 [ sizeof( V_168 . V_99 ) - 1 ] = 0 ;
V_119 = F_87 ( V_168 . V_131 ) ;
if ( ! V_119 )
return - V_145 ;
V_176 = V_119 -> V_101 ;
if ( F_73 ( V_176 , V_128 + sizeof( V_168 ) , V_168 . V_131 ) != 0 ) {
V_10 = - V_177 ;
goto V_202;
}
V_10 = F_96 ( & V_119 , & V_176 , & V_168 ) ;
if ( V_10 != 0 )
goto V_202;
V_10 = F_82 ( V_185 , V_168 . V_99 , V_168 . V_120 , V_119 ,
V_168 . V_195 , F_98 ( V_168 . V_107 ) ) ;
if ( V_10 )
goto V_203;
return 0 ;
V_203:
F_48 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_160 ) ;
V_202:
F_84 ( V_119 ) ;
return V_10 ;
}
static int F_99 ( struct V_220 * V_221 , int V_222 , void T_5 * V_128 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_100 ( F_101 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_97 ( F_101 ( V_221 ) , V_128 , V_8 ) ;
break;
case V_227 :
V_10 = F_88 ( F_101 ( V_221 ) , V_128 , V_8 , 1 ) ;
break;
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static int F_102 ( struct V_77 * V_78 , void T_5 * * V_209 ,
T_6 * V_131 ,
struct V_105 * V_107 ,
unsigned int V_9 )
{
struct V_76 * V_104 ;
struct V_183 T_5 * V_228 ;
T_7 V_118 , V_82 ;
T_6 V_211 ;
int V_10 ;
V_211 = * V_131 ;
V_228 = (struct V_183 T_5 * ) * V_209 ;
if ( F_60 ( V_228 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_60 ( & V_228 -> V_107 , & V_107 [ V_9 ] ,
sizeof( V_107 [ V_9 ] ) ) != 0 )
return - V_177 ;
* V_209 += sizeof( struct V_183 ) ;
* V_131 -= sizeof( struct V_77 ) - sizeof( struct V_183 ) ;
V_118 = V_78 -> V_118 - ( V_211 - * V_131 ) ;
V_104 = F_13 ( V_78 ) ;
V_10 = F_103 ( V_104 , V_209 , V_131 ) ;
if ( V_10 )
return V_10 ;
V_82 = V_78 -> V_82 - ( V_211 - * V_131 ) ;
if ( F_104 ( V_118 , & V_228 -> V_118 ) != 0 ||
F_104 ( V_82 , & V_228 -> V_82 ) != 0 )
return - V_177 ;
return 0 ;
}
static int F_105 ( unsigned int V_172 ,
struct V_1 * V_85 ,
void T_5 * V_173 )
{
struct V_105 * V_107 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
void T_5 * V_124 ;
unsigned int V_131 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_160 ;
V_107 = F_56 ( V_85 ) ;
if ( F_37 ( V_107 ) )
return F_38 ( V_107 ) ;
V_124 = V_173 ;
V_131 = V_172 ;
F_48 (iter, private->entries, total_size) {
V_10 = F_102 ( V_160 , & V_124 ,
& V_131 , V_107 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_63 ( V_107 ) ;
return V_10 ;
}
static int F_106 ( struct V_185 * V_185 ,
struct V_229 T_5 * V_191 ,
int * V_8 )
{
int V_10 ;
struct V_229 V_192 ;
struct V_1 * V_104 ;
if ( * V_8 < sizeof( V_192 ) )
return - V_154 ;
if ( F_73 ( & V_192 , V_191 , sizeof( V_192 ) ) != 0 )
return - V_177 ;
if ( * V_8 != sizeof( struct V_229 ) + V_192 . V_131 )
return - V_154 ;
V_192 . V_99 [ sizeof( V_192 . V_99 ) - 1 ] = '\0' ;
F_75 ( V_140 ) ;
V_104 = F_77 ( V_185 , V_140 , V_192 . V_99 ) ;
if ( V_104 ) {
const struct V_94 * V_95 = V_104 -> V_95 ;
struct V_94 V_2 ;
V_10 = F_70 ( V_95 , & V_2 ) ;
if ( ! V_10 && V_192 . V_131 == V_2 . V_131 ) {
V_10 = F_105 ( V_95 -> V_131 ,
V_104 , V_191 -> V_193 ) ;
} else if ( ! V_10 )
V_10 = - V_194 ;
F_78 ( V_140 ) ;
F_39 ( V_104 -> V_148 ) ;
F_79 ( V_104 ) ;
} else
V_10 = - V_189 ;
F_80 ( V_140 ) ;
return V_10 ;
}
static int F_107 ( struct V_220 * V_221 , int V_222 , void T_5 * V_128 ,
int * V_8 )
{
int V_10 ;
if ( ! F_100 ( F_101 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_72 ( F_101 ( V_221 ) , V_128 , V_8 , 1 ) ;
break;
case V_231 :
V_10 = F_106 ( F_101 ( V_221 ) , V_128 , V_8 ) ;
break;
default:
V_10 = F_108 ( V_221 , V_222 , V_128 , V_8 ) ;
}
return V_10 ;
}
static int F_109 ( struct V_220 * V_221 , int V_222 , void T_5 * V_128 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_100 ( F_101 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_86 ( F_101 ( V_221 ) , V_128 , V_8 ) ;
break;
case V_227 :
V_10 = F_88 ( F_101 ( V_221 ) , V_128 , V_8 , 0 ) ;
break;
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static int F_108 ( struct V_220 * V_221 , int V_222 , void T_5 * V_128 , int * V_8 )
{
int V_10 ;
if ( ! F_100 ( F_101 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_72 ( F_101 ( V_221 ) , V_128 , V_8 , 0 ) ;
break;
case V_231 :
V_10 = F_81 ( F_101 ( V_221 ) , V_128 , V_8 ) ;
break;
case V_232 : {
struct V_233 V_234 ;
if ( * V_8 != sizeof( V_234 ) ) {
V_10 = - V_154 ;
break;
}
if ( F_73 ( & V_234 , V_128 , sizeof( V_234 ) ) != 0 ) {
V_10 = - V_177 ;
break;
}
V_234 . V_99 [ sizeof( V_234 . V_99 ) - 1 ] = 0 ;
F_76 ( F_110 ( V_140 , V_234 . V_99 ,
V_234 . V_146 , 1 , & V_10 ) ,
L_4 , V_234 . V_99 ) ;
break;
}
default:
V_10 = - V_154 ;
}
return V_10 ;
}
static void F_111 ( struct V_1 * V_85 )
{
struct V_94 * V_95 ;
void * V_176 ;
struct V_235 * V_236 = V_85 -> V_148 ;
struct V_77 * V_160 ;
V_95 = F_112 ( V_85 ) ;
V_176 = V_95 -> V_101 ;
F_48 (iter, loc_cpu_entry, private->size)
F_45 ( V_160 ) ;
if ( V_95 -> V_135 > V_95 -> V_184 )
F_39 ( V_236 ) ;
F_84 ( V_95 ) ;
}
int F_113 ( struct V_185 * V_185 ,
const struct V_1 * V_85 ,
const struct V_158 * V_159 ,
const struct V_237 * V_238 ,
struct V_1 * * V_239 )
{
int V_10 ;
struct V_94 * V_119 ;
struct V_94 V_240 = { 0 } ;
void * V_176 ;
struct V_1 * V_241 ;
V_119 = F_87 ( V_159 -> V_131 ) ;
if ( ! V_119 )
return - V_145 ;
V_176 = V_119 -> V_101 ;
memcpy ( V_176 , V_159 -> V_101 , V_159 -> V_131 ) ;
V_10 = F_46 ( V_119 , V_176 , V_159 ) ;
if ( V_10 != 0 )
goto V_162;
V_241 = F_114 ( V_185 , V_85 , & V_240 , V_119 ) ;
if ( F_37 ( V_241 ) ) {
V_10 = F_38 ( V_241 ) ;
goto V_162;
}
F_115 ( * V_239 , V_241 ) ;
V_10 = F_116 ( V_185 , V_238 , F_117 ( V_85 -> V_120 ) ) ;
if ( V_10 != 0 ) {
F_111 ( V_241 ) ;
* V_239 = NULL ;
}
return V_10 ;
V_162:
F_84 ( V_119 ) ;
return V_10 ;
}
void F_118 ( struct V_185 * V_185 , struct V_1 * V_85 ,
const struct V_237 * V_238 )
{
F_119 ( V_185 , V_238 , F_117 ( V_85 -> V_120 ) ) ;
F_111 ( V_85 ) ;
}
static int T_8 F_120 ( struct V_185 * V_185 )
{
return F_121 ( V_185 , V_140 ) ;
}
static void T_9 F_122 ( struct V_185 * V_185 )
{
F_123 ( V_185 , V_140 ) ;
}
static int T_10 F_124 ( void )
{
int V_10 ;
V_10 = F_125 ( & V_242 ) ;
if ( V_10 < 0 )
goto V_243;
V_10 = F_126 ( V_244 , F_127 ( V_244 ) ) ;
if ( V_10 < 0 )
goto V_245;
V_10 = F_128 ( & V_246 ) ;
if ( V_10 < 0 )
goto V_247;
F_129 ( L_5 ) ;
return 0 ;
V_247:
F_130 ( V_244 , F_127 ( V_244 ) ) ;
V_245:
F_131 ( & V_242 ) ;
V_243:
return V_10 ;
}
static void T_11 F_132 ( void )
{
F_133 ( & V_246 ) ;
F_130 ( V_244 , F_127 ( V_244 ) ) ;
F_131 ( & V_242 ) ;
}
