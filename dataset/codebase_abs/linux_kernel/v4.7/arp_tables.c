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
#define F_8 ( bool , T_3 ) ((bool) ^ !!(arpinfo->invflags & (invflg)))
if ( F_8 ( ( V_20 -> V_32 & V_26 -> V_33 ) != V_26 -> V_34 ,
V_35 ) )
return 0 ;
if ( F_8 ( ( V_20 -> V_36 & V_26 -> V_37 ) != V_26 -> V_38 ,
V_39 ) )
return 0 ;
if ( F_8 ( ( V_20 -> V_40 & V_26 -> V_41 ) != V_26 -> V_42 ,
V_43 ) )
return 0 ;
if ( F_8 ( ( V_20 -> V_44 & V_26 -> V_45 ) != V_26 -> V_46 ,
V_47 ) )
return 0 ;
V_28 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_30 , V_27 , sizeof( V_49 ) ) ;
V_27 += sizeof( V_49 ) ;
V_29 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_31 , V_27 , sizeof( V_49 ) ) ;
if ( F_8 ( F_3 ( & V_26 -> V_28 , V_28 , V_22 -> V_48 ) ,
V_50 ) ||
F_8 ( F_3 ( & V_26 -> V_29 , V_29 , V_22 -> V_48 ) ,
V_51 ) )
return 0 ;
if ( F_8 ( ( V_30 & V_26 -> V_52 . V_53 ) != V_26 -> V_54 . V_53 ,
V_55 ) ||
F_8 ( ( ( V_31 & V_26 -> V_56 . V_53 ) != V_26 -> V_57 . V_53 ) ,
V_58 ) )
return 0 ;
V_10 = F_4 ( V_23 , V_26 -> V_59 , V_26 -> V_60 ) ;
if ( F_8 ( V_10 != 0 , V_61 ) )
return 0 ;
V_10 = F_4 ( V_24 , V_26 -> V_62 , V_26 -> V_63 ) ;
if ( F_8 ( V_10 != 0 , V_64 ) )
return 0 ;
return 1 ;
#undef F_8
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
static bool F_30 ( const struct V_94 * V_108 ,
const struct V_77 * V_114 )
{
struct V_77 * V_123 ;
F_31 (iter, t->entries, t->size) {
if ( V_123 == V_114 )
return true ;
}
return false ;
}
static int F_32 ( const struct V_94 * V_124 ,
unsigned int V_125 , void * V_126 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_127 ; V_86 ++ ) {
unsigned int V_128 = V_124 -> V_102 [ V_86 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_126 + V_128 ) ;
if ( ! ( V_125 & ( 1 << V_86 ) ) )
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
( V_126 + V_128 ) ;
} while ( V_134 == V_128 + V_78 -> V_82 );
V_135 = V_78 -> V_82 ;
V_78 = (struct V_77 * )
( V_126 + V_128 + V_135 ) ;
if ( V_128 + V_135 >= V_124 -> V_135 )
return 0 ;
V_78 -> V_111 . V_129 = V_128 ;
V_128 += V_135 ;
} else {
int V_138 = V_108 -> V_89 ;
if ( strcmp ( V_108 -> V_114 . V_112 . V_132 . V_99 ,
V_133 ) == 0 &&
V_138 >= 0 ) {
V_78 = (struct V_77 * )
( V_126 + V_138 ) ;
if ( ! F_30 ( V_124 , V_78 ) )
return 0 ;
} else {
V_138 = V_128 + V_78 -> V_82 ;
if ( V_138 >= V_124 -> V_135 )
return 0 ;
}
V_78 = (struct V_77 * )
( V_126 + V_138 ) ;
V_78 -> V_111 . V_129 = V_128 ;
V_128 = V_138 ;
}
}
V_137: ;
}
return 1 ;
}
static inline int F_33 ( struct V_77 * V_78 , const char * V_99 )
{
struct V_76 * V_108 = F_13 ( V_78 ) ;
struct V_139 V_73 = {
. V_85 = V_99 ,
. V_140 = V_78 ,
. V_114 = V_108 -> V_112 . V_113 . V_114 ,
. V_74 = V_108 -> V_119 ,
. V_141 = V_78 -> V_131 ,
. V_105 = V_106 ,
} ;
return F_34 ( & V_73 , V_108 -> V_112 . V_142 - sizeof( * V_108 ) , 0 , false ) ;
}
static inline int
F_35 ( struct V_77 * V_78 , const char * V_99 , unsigned int V_135 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
unsigned long V_129 ;
int V_10 ;
V_129 = F_36 () ;
if ( F_37 ( V_129 ) )
return - V_144 ;
V_78 -> V_111 . V_129 = V_129 ;
V_108 = F_13 ( V_78 ) ;
V_114 = F_38 ( V_106 , V_108 -> V_112 . V_132 . V_99 ,
V_108 -> V_112 . V_132 . V_145 ) ;
if ( F_39 ( V_114 ) ) {
V_10 = F_40 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_10 = F_33 ( V_78 , V_99 ) ;
if ( V_10 )
goto V_146;
return 0 ;
V_146:
F_41 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
V_100:
F_42 ( V_78 -> V_111 . V_129 ) ;
return V_10 ;
}
static bool F_43 ( const struct V_77 * V_78 )
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
return V_89 == V_75 || V_89 == V_148 ;
}
static inline int F_44 ( struct V_77 * V_78 ,
struct V_94 * V_124 ,
const unsigned char * V_79 ,
const unsigned char * V_149 ,
const unsigned int * V_150 ,
const unsigned int * V_151 ,
unsigned int V_125 )
{
unsigned int V_152 ;
int V_146 ;
if ( ( unsigned long ) V_78 % F_45 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_149 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_149 )
return - V_153 ;
if ( V_78 -> V_82
< sizeof( struct V_77 ) + sizeof( struct V_76 ) )
return - V_153 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_153 ;
V_146 = F_46 ( V_78 , V_78 -> V_154 , V_78 -> V_122 ,
V_78 -> V_82 ) ;
if ( V_146 )
return V_146 ;
for ( V_152 = 0 ; V_152 < V_127 ; V_152 ++ ) {
if ( ! ( V_125 & ( 1 << V_152 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_152 ] )
V_124 -> V_102 [ V_152 ] = V_150 [ V_152 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_151 [ V_152 ] ) {
if ( ! F_43 ( V_78 ) )
return - V_153 ;
V_124 -> V_118 [ V_152 ] = V_151 [ V_152 ] ;
}
}
V_78 -> V_111 = ( (struct V_109 ) { 0 , 0 } ) ;
V_78 -> V_131 = 0 ;
return 0 ;
}
static inline void F_47 ( struct V_77 * V_78 )
{
struct V_155 V_73 ;
struct V_76 * V_108 ;
V_108 = F_13 ( V_78 ) ;
V_73 . V_114 = V_108 -> V_112 . V_113 . V_114 ;
V_73 . V_74 = V_108 -> V_119 ;
V_73 . V_105 = V_106 ;
if ( V_73 . V_114 -> V_156 != NULL )
V_73 . V_114 -> V_156 ( & V_73 ) ;
F_41 ( V_73 . V_114 -> V_147 ) ;
F_42 ( V_78 -> V_111 . V_129 ) ;
}
static int F_48 ( struct V_94 * V_124 , void * V_126 ,
const struct V_157 * V_158 )
{
struct V_77 * V_123 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_124 -> V_135 = V_158 -> V_135 ;
V_124 -> V_159 = V_158 -> V_160 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_124 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_124 -> V_118 [ V_9 ] = 0xFFFFFFFF ;
}
V_9 = 0 ;
F_31 (iter, entry0, newinfo->size) {
V_10 = F_44 ( V_123 , V_124 , V_126 ,
V_126 + V_158 -> V_135 ,
V_158 -> V_102 ,
V_158 -> V_118 ,
V_158 -> V_125 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_13 ( V_123 ) -> V_112 . V_132 . V_99 ,
V_161 ) == 0 )
++ V_124 -> V_162 ;
}
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_158 -> V_160 )
return - V_153 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
if ( ! ( V_158 -> V_125 & ( 1 << V_9 ) ) )
continue;
if ( V_124 -> V_102 [ V_9 ] == 0xFFFFFFFF )
return - V_153 ;
if ( V_124 -> V_118 [ V_9 ] == 0xFFFFFFFF )
return - V_153 ;
}
if ( ! F_32 ( V_124 , V_158 -> V_125 , V_126 ) )
return - V_163 ;
V_9 = 0 ;
F_31 (iter, entry0, newinfo->size) {
V_10 = F_35 ( V_123 , V_158 -> V_99 , V_158 -> V_135 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_31 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_47 ( V_123 ) ;
}
return V_10 ;
}
return V_10 ;
}
static void F_49 ( const struct V_94 * V_108 ,
struct V_109 V_111 [] )
{
struct V_77 * V_123 ;
unsigned int V_92 ;
unsigned int V_9 ;
F_50 (cpu) {
T_4 * V_164 = & F_51 ( V_165 , V_92 ) ;
V_9 = 0 ;
F_31 (iter, t->entries, t->size) {
struct V_109 * V_166 ;
T_5 V_167 , V_129 ;
unsigned int V_168 ;
V_166 = F_52 ( & V_123 -> V_111 , V_92 ) ;
do {
V_168 = F_53 ( V_164 ) ;
V_167 = V_166 -> V_167 ;
V_129 = V_166 -> V_129 ;
} while ( F_54 ( V_164 , V_168 ) );
F_26 ( V_111 [ V_9 ] , V_167 , V_129 ) ;
++ V_9 ;
}
}
}
static struct V_109 * F_55 ( const struct V_1 * V_85 )
{
unsigned int V_169 ;
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
V_169 = sizeof( struct V_109 ) * V_95 -> V_159 ;
V_111 = F_56 ( V_169 ) ;
if ( V_111 == NULL )
return F_57 ( - V_144 ) ;
F_49 ( V_95 , V_111 ) ;
return V_111 ;
}
static int F_58 ( unsigned int V_170 ,
const struct V_1 * V_85 ,
void T_6 * V_171 )
{
unsigned int V_172 , V_173 ;
const struct V_77 * V_78 ;
struct V_109 * V_111 ;
struct V_94 * V_95 = V_85 -> V_95 ;
int V_10 = 0 ;
void * V_174 ;
V_111 = F_55 ( V_85 ) ;
if ( F_39 ( V_111 ) )
return F_40 ( V_111 ) ;
V_174 = V_95 -> V_101 ;
if ( F_59 ( V_171 , V_174 , V_170 ) != 0 ) {
V_10 = - V_175 ;
goto V_176;
}
for ( V_172 = 0 , V_173 = 0 ; V_172 < V_170 ; V_172 += V_78 -> V_82 , V_173 ++ ) {
const struct V_76 * V_108 ;
V_78 = (struct V_77 * ) ( V_174 + V_172 ) ;
if ( F_59 ( V_171 + V_172
+ F_60 ( struct V_77 , V_111 ) ,
& V_111 [ V_173 ] ,
sizeof( V_111 [ V_173 ] ) ) != 0 ) {
V_10 = - V_175 ;
goto V_176;
}
V_108 = F_12 ( V_78 ) ;
if ( F_59 ( V_171 + V_172 + V_78 -> V_122
+ F_60 ( struct V_76 ,
V_112 . V_132 . V_99 ) ,
V_108 -> V_112 . V_113 . V_114 -> V_99 ,
strlen ( V_108 -> V_112 . V_113 . V_114 -> V_99 ) + 1 ) != 0 ) {
V_10 = - V_175 ;
goto V_176;
}
}
V_176:
F_61 ( V_111 ) ;
return V_10 ;
}
static void F_62 ( void * V_177 , const void * V_54 )
{
int V_115 = * ( V_178 * ) V_54 ;
if ( V_115 > 0 )
V_115 += F_63 ( V_106 , V_115 ) ;
memcpy ( V_177 , & V_115 , sizeof( V_115 ) ) ;
}
static int F_64 ( void T_6 * V_177 , const void * V_54 )
{
V_178 V_179 = * ( int * ) V_54 ;
if ( V_179 > 0 )
V_179 -= F_63 ( V_106 , V_179 ) ;
return F_59 ( V_177 , & V_179 , sizeof( V_179 ) ) ? - V_175 : 0 ;
}
static int F_65 ( const struct V_77 * V_78 ,
const struct V_94 * V_2 ,
const void * V_79 , struct V_94 * V_124 )
{
const struct V_76 * V_108 ;
unsigned int V_180 ;
int V_172 , V_9 , V_10 ;
V_172 = sizeof( struct V_77 ) - sizeof( struct V_181 ) ;
V_180 = ( void * ) V_78 - V_79 ;
V_108 = F_12 ( V_78 ) ;
V_172 += F_66 ( V_108 -> V_112 . V_113 . V_114 ) ;
V_124 -> V_135 -= V_172 ;
V_10 = F_67 ( V_106 , V_180 , V_172 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
if ( V_2 -> V_102 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_102 [ V_9 ] ) ) )
V_124 -> V_102 [ V_9 ] -= V_172 ;
if ( V_2 -> V_118 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_118 [ V_9 ] ) ) )
V_124 -> V_118 [ V_9 ] -= V_172 ;
}
return 0 ;
}
static int F_68 ( const struct V_94 * V_2 ,
struct V_94 * V_124 )
{
struct V_77 * V_123 ;
const void * V_174 ;
int V_10 ;
if ( ! V_124 || ! V_2 )
return - V_153 ;
memcpy ( V_124 , V_2 , F_60 ( struct V_94 , V_101 ) ) ;
V_124 -> V_182 = 0 ;
V_174 = V_2 -> V_101 ;
F_69 ( V_106 , V_2 -> V_159 ) ;
F_31 (iter, loc_cpu_entry, info->size) {
V_10 = F_65 ( V_123 , V_2 , V_174 , V_124 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_70 ( struct V_103 * V_103 , void T_6 * V_132 ,
const int * V_8 , int V_183 )
{
char V_99 [ V_184 ] ;
struct V_1 * V_108 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_185 ) )
return - V_153 ;
if ( F_71 ( V_99 , V_132 , sizeof( V_99 ) ) != 0 )
return - V_175 ;
V_99 [ V_184 - 1 ] = '\0' ;
#ifdef F_72
if ( V_183 )
F_73 ( V_106 ) ;
#endif
V_108 = F_74 ( F_75 ( V_103 , V_106 , V_99 ) ,
L_2 , V_99 ) ;
if ( ! F_76 ( V_108 ) ) {
struct V_185 V_2 ;
const struct V_94 * V_95 = V_108 -> V_95 ;
#ifdef F_72
struct V_94 V_166 ;
if ( V_183 ) {
V_10 = F_68 ( V_95 , & V_166 ) ;
F_77 ( V_106 ) ;
V_95 = & V_166 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_125 = V_108 -> V_125 ;
memcpy ( V_2 . V_102 , V_95 -> V_102 ,
sizeof( V_2 . V_102 ) ) ;
memcpy ( V_2 . V_118 , V_95 -> V_118 ,
sizeof( V_2 . V_118 ) ) ;
V_2 . V_160 = V_95 -> V_159 ;
V_2 . V_135 = V_95 -> V_135 ;
strcpy ( V_2 . V_99 , V_99 ) ;
if ( F_59 ( V_132 , & V_2 , * V_8 ) != 0 )
V_10 = - V_175 ;
else
V_10 = 0 ;
F_78 ( V_108 ) ;
F_41 ( V_108 -> V_147 ) ;
} else
V_10 = V_108 ? F_40 ( V_108 ) : - V_186 ;
#ifdef F_72
if ( V_183 )
F_79 ( V_106 ) ;
#endif
return V_10 ;
}
static int F_80 ( struct V_103 * V_103 , struct V_187 T_6 * V_188 ,
const int * V_8 )
{
int V_10 ;
struct V_187 V_189 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_189 ) )
return - V_153 ;
if ( F_71 ( & V_189 , V_188 , sizeof( V_189 ) ) != 0 )
return - V_175 ;
if ( * V_8 != sizeof( struct V_187 ) + V_189 . V_135 )
return - V_153 ;
V_189 . V_99 [ sizeof( V_189 . V_99 ) - 1 ] = '\0' ;
V_108 = F_75 ( V_103 , V_106 , V_189 . V_99 ) ;
if ( ! F_76 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
if ( V_189 . V_135 == V_95 -> V_135 )
V_10 = F_58 ( V_95 -> V_135 ,
V_108 , V_188 -> V_190 ) ;
else
V_10 = - V_191 ;
F_41 ( V_108 -> V_147 ) ;
F_78 ( V_108 ) ;
} else
V_10 = V_108 ? F_40 ( V_108 ) : - V_186 ;
return V_10 ;
}
static int F_81 ( struct V_103 * V_103 , const char * V_99 ,
unsigned int V_125 ,
struct V_94 * V_124 ,
unsigned int V_192 ,
void T_6 * V_193 )
{
int V_10 ;
struct V_1 * V_108 ;
struct V_94 * V_194 ;
struct V_109 * V_111 ;
void * V_195 ;
struct V_77 * V_123 ;
V_10 = 0 ;
V_111 = F_56 ( V_192 * sizeof( struct V_109 ) ) ;
if ( ! V_111 ) {
V_10 = - V_144 ;
goto V_100;
}
V_108 = F_74 ( F_75 ( V_103 , V_106 , V_99 ) ,
L_2 , V_99 ) ;
if ( F_76 ( V_108 ) ) {
V_10 = V_108 ? F_40 ( V_108 ) : - V_186 ;
goto V_196;
}
if ( V_125 != V_108 -> V_125 ) {
V_10 = - V_153 ;
goto V_197;
}
V_194 = F_82 ( V_108 , V_192 , V_124 , & V_10 ) ;
if ( ! V_194 )
goto V_197;
if ( ( V_194 -> V_159 > V_194 -> V_182 ) ||
( V_124 -> V_159 <= V_194 -> V_182 ) )
F_41 ( V_108 -> V_147 ) ;
if ( ( V_194 -> V_159 > V_194 -> V_182 ) &&
( V_124 -> V_159 <= V_194 -> V_182 ) )
F_41 ( V_108 -> V_147 ) ;
F_49 ( V_194 , V_111 ) ;
V_195 = V_194 -> V_101 ;
F_31 (iter, loc_cpu_old_entry, oldinfo->size)
F_47 ( V_123 ) ;
F_83 ( V_194 ) ;
if ( F_59 ( V_193 , V_111 ,
sizeof( struct V_109 ) * V_192 ) != 0 ) {
F_84 ( L_3 ) ;
}
F_61 ( V_111 ) ;
F_78 ( V_108 ) ;
return V_10 ;
V_197:
F_41 ( V_108 -> V_147 ) ;
F_78 ( V_108 ) ;
V_196:
F_61 ( V_111 ) ;
V_100:
return V_10 ;
}
static int F_85 ( struct V_103 * V_103 , const void T_6 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
struct V_157 V_166 ;
struct V_94 * V_124 ;
void * V_174 ;
struct V_77 * V_123 ;
if ( F_71 ( & V_166 , V_132 , sizeof( V_166 ) ) != 0 )
return - V_175 ;
if ( V_166 . V_192 >= V_198 / sizeof( struct V_109 ) )
return - V_144 ;
if ( V_166 . V_192 == 0 )
return - V_153 ;
V_166 . V_99 [ sizeof( V_166 . V_99 ) - 1 ] = 0 ;
V_124 = F_86 ( V_166 . V_135 ) ;
if ( ! V_124 )
return - V_144 ;
V_174 = V_124 -> V_101 ;
if ( F_71 ( V_174 , V_132 + sizeof( V_166 ) ,
V_166 . V_135 ) != 0 ) {
V_10 = - V_175 ;
goto V_199;
}
V_10 = F_48 ( V_124 , V_174 , & V_166 ) ;
if ( V_10 != 0 )
goto V_199;
V_10 = F_81 ( V_103 , V_166 . V_99 , V_166 . V_125 , V_124 ,
V_166 . V_192 , V_166 . V_111 ) ;
if ( V_10 )
goto V_200;
return 0 ;
V_200:
F_31 (iter, loc_cpu_entry, newinfo->size)
F_47 ( V_123 ) ;
V_199:
F_83 ( V_124 ) ;
return V_10 ;
}
static int F_87 ( struct V_103 * V_103 , const void T_6 * V_132 ,
unsigned int V_8 , int V_183 )
{
unsigned int V_9 ;
struct V_201 V_166 ;
struct V_109 * V_202 ;
struct V_1 * V_108 ;
const struct V_94 * V_95 ;
int V_10 = 0 ;
struct V_77 * V_123 ;
unsigned int V_97 ;
V_202 = F_88 ( V_132 , V_8 , & V_166 , V_183 ) ;
if ( F_39 ( V_202 ) )
return F_40 ( V_202 ) ;
V_108 = F_75 ( V_103 , V_106 , V_166 . V_99 ) ;
if ( F_76 ( V_108 ) ) {
V_10 = V_108 ? F_40 ( V_108 ) : - V_186 ;
goto free;
}
F_20 () ;
V_95 = V_108 -> V_95 ;
if ( V_95 -> V_159 != V_166 . V_192 ) {
V_10 = - V_153 ;
goto V_203;
}
V_9 = 0 ;
V_97 = F_21 () ;
F_31 (iter, private->entries, private->size) {
struct V_109 * V_166 ;
V_166 = F_25 ( & V_123 -> V_111 ) ;
F_26 ( * V_166 , V_202 [ V_9 ] . V_167 , V_202 [ V_9 ] . V_129 ) ;
++ V_9 ;
}
F_27 ( V_97 ) ;
V_203:
F_28 () ;
F_78 ( V_108 ) ;
F_41 ( V_108 -> V_147 ) ;
free:
F_61 ( V_202 ) ;
return V_10 ;
}
static inline void F_89 ( struct V_181 * V_78 )
{
struct V_76 * V_108 ;
V_108 = F_90 ( V_78 ) ;
F_41 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
}
static int
F_91 ( struct V_181 * V_78 ,
struct V_94 * V_124 ,
unsigned int * V_135 ,
const unsigned char * V_79 ,
const unsigned char * V_149 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
unsigned int V_180 ;
int V_10 , V_172 ;
if ( ( unsigned long ) V_78 % F_45 ( struct V_181 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_181 ) >= V_149 ||
( unsigned char * ) V_78 + V_78 -> V_82 > V_149 )
return - V_153 ;
if ( V_78 -> V_82 < sizeof( struct V_181 ) +
sizeof( struct V_204 ) )
return - V_153 ;
if ( ! F_9 ( & V_78 -> V_65 ) )
return - V_153 ;
V_10 = F_92 ( V_78 , V_78 -> V_154 , V_78 -> V_122 ,
V_78 -> V_82 ) ;
if ( V_10 )
return V_10 ;
V_172 = sizeof( struct V_77 ) - sizeof( struct V_181 ) ;
V_180 = ( void * ) V_78 - ( void * ) V_79 ;
V_108 = F_90 ( V_78 ) ;
V_114 = F_38 ( V_106 , V_108 -> V_112 . V_132 . V_99 ,
V_108 -> V_112 . V_132 . V_145 ) ;
if ( F_39 ( V_114 ) ) {
V_10 = F_40 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_172 += F_66 ( V_114 ) ;
* V_135 += V_172 ;
V_10 = F_67 ( V_106 , V_180 , V_172 ) ;
if ( V_10 )
goto V_205;
return 0 ;
V_205:
F_41 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
V_100:
return V_10 ;
}
static void
F_93 ( struct V_181 * V_78 , void * * V_206 ,
unsigned int * V_135 ,
struct V_94 * V_124 , unsigned char * V_79 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
struct V_77 * V_207 ;
unsigned int V_208 ;
int V_152 ;
V_208 = * V_135 ;
V_207 = (struct V_77 * ) * V_206 ;
memcpy ( V_207 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_207 -> V_111 , & V_78 -> V_111 , sizeof( V_78 -> V_111 ) ) ;
* V_206 += sizeof( struct V_77 ) ;
* V_135 += sizeof( struct V_77 ) - sizeof( struct V_181 ) ;
V_207 -> V_122 = V_78 -> V_122 - ( V_208 - * V_135 ) ;
V_108 = F_90 ( V_78 ) ;
V_114 = V_108 -> V_112 . V_113 . V_114 ;
F_94 ( V_108 , V_206 , V_135 ) ;
V_207 -> V_82 = V_78 -> V_82 - ( V_208 - * V_135 ) ;
for ( V_152 = 0 ; V_152 < V_127 ; V_152 ++ ) {
if ( ( unsigned char * ) V_207 - V_79 < V_124 -> V_102 [ V_152 ] )
V_124 -> V_102 [ V_152 ] -= V_208 - * V_135 ;
if ( ( unsigned char * ) V_207 - V_79 < V_124 -> V_118 [ V_152 ] )
V_124 -> V_118 [ V_152 ] -= V_208 - * V_135 ;
}
}
static int F_95 ( struct V_94 * * V_209 ,
void * * V_210 ,
const struct V_211 * V_212 )
{
unsigned int V_9 , V_213 ;
struct V_94 * V_124 , * V_2 ;
void * V_128 , * V_126 , * V_214 ;
struct V_181 * V_215 ;
struct V_157 V_158 ;
unsigned int V_135 ;
int V_10 = 0 ;
V_2 = * V_209 ;
V_126 = * V_210 ;
V_135 = V_212 -> V_135 ;
V_2 -> V_159 = V_212 -> V_160 ;
V_213 = 0 ;
F_73 ( V_106 ) ;
F_69 ( V_106 , V_212 -> V_160 ) ;
F_31 (iter0, entry0, compatr->size) {
V_10 = F_91 ( V_215 , V_2 , & V_135 ,
V_126 ,
V_126 + V_212 -> V_135 ) ;
if ( V_10 != 0 )
goto V_216;
++ V_213 ;
}
V_10 = - V_153 ;
if ( V_213 != V_212 -> V_160 )
goto V_216;
V_10 = - V_144 ;
V_124 = F_86 ( V_135 ) ;
if ( ! V_124 )
goto V_216;
V_124 -> V_159 = V_212 -> V_160 ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_124 -> V_102 [ V_9 ] = V_2 -> V_102 [ V_9 ] ;
V_124 -> V_118 [ V_9 ] = V_2 -> V_118 [ V_9 ] ;
}
V_214 = V_124 -> V_101 ;
V_128 = V_214 ;
V_135 = V_212 -> V_135 ;
F_31 (iter0, entry0, compatr->size)
F_93 ( V_215 , & V_128 , & V_135 ,
V_124 , V_214 ) ;
F_77 ( V_106 ) ;
F_79 ( V_106 ) ;
memcpy ( & V_158 , V_212 , sizeof( * V_212 ) ) ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_158 . V_102 [ V_9 ] = V_124 -> V_102 [ V_9 ] ;
V_158 . V_118 [ V_9 ] = V_124 -> V_118 [ V_9 ] ;
}
V_158 . V_192 = 0 ;
V_158 . V_111 = NULL ;
V_158 . V_135 = V_124 -> V_135 ;
V_10 = F_48 ( V_124 , V_214 , & V_158 ) ;
if ( V_10 )
goto V_199;
* V_209 = V_124 ;
* V_210 = V_214 ;
F_83 ( V_2 ) ;
return 0 ;
V_199:
F_83 ( V_124 ) ;
return V_10 ;
V_216:
F_77 ( V_106 ) ;
F_79 ( V_106 ) ;
F_31 (iter0, entry0, compatr->size) {
if ( V_213 -- == 0 )
break;
F_89 ( V_215 ) ;
}
return V_10 ;
}
static int F_96 ( struct V_103 * V_103 , void T_6 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
struct V_211 V_166 ;
struct V_94 * V_124 ;
void * V_174 ;
struct V_77 * V_123 ;
if ( F_71 ( & V_166 , V_132 , sizeof( V_166 ) ) != 0 )
return - V_175 ;
if ( V_166 . V_192 >= V_198 / sizeof( struct V_109 ) )
return - V_144 ;
if ( V_166 . V_192 == 0 )
return - V_153 ;
V_166 . V_99 [ sizeof( V_166 . V_99 ) - 1 ] = 0 ;
V_124 = F_86 ( V_166 . V_135 ) ;
if ( ! V_124 )
return - V_144 ;
V_174 = V_124 -> V_101 ;
if ( F_71 ( V_174 , V_132 + sizeof( V_166 ) , V_166 . V_135 ) != 0 ) {
V_10 = - V_175 ;
goto V_199;
}
V_10 = F_95 ( & V_124 , & V_174 , & V_166 ) ;
if ( V_10 != 0 )
goto V_199;
V_10 = F_81 ( V_103 , V_166 . V_99 , V_166 . V_125 , V_124 ,
V_166 . V_192 , F_97 ( V_166 . V_111 ) ) ;
if ( V_10 )
goto V_200;
return 0 ;
V_200:
F_31 (iter, loc_cpu_entry, newinfo->size)
F_47 ( V_123 ) ;
V_199:
F_83 ( V_124 ) ;
return V_10 ;
}
static int F_98 ( struct V_217 * V_218 , int V_219 , void T_6 * V_132 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_99 ( F_100 ( V_218 ) -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_219 ) {
case V_223 :
V_10 = F_96 ( F_100 ( V_218 ) , V_132 , V_8 ) ;
break;
case V_224 :
V_10 = F_87 ( F_100 ( V_218 ) , V_132 , V_8 , 1 ) ;
break;
default:
V_10 = - V_153 ;
}
return V_10 ;
}
static int F_101 ( struct V_77 * V_78 , void T_6 * * V_206 ,
T_7 * V_135 ,
struct V_109 * V_111 ,
unsigned int V_9 )
{
struct V_76 * V_108 ;
struct V_181 T_6 * V_225 ;
T_8 V_122 , V_82 ;
T_7 V_208 ;
int V_10 ;
V_208 = * V_135 ;
V_225 = (struct V_181 T_6 * ) * V_206 ;
if ( F_59 ( V_225 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_59 ( & V_225 -> V_111 , & V_111 [ V_9 ] ,
sizeof( V_111 [ V_9 ] ) ) != 0 )
return - V_175 ;
* V_206 += sizeof( struct V_181 ) ;
* V_135 -= sizeof( struct V_77 ) - sizeof( struct V_181 ) ;
V_122 = V_78 -> V_122 - ( V_208 - * V_135 ) ;
V_108 = F_13 ( V_78 ) ;
V_10 = F_102 ( V_108 , V_206 , V_135 ) ;
if ( V_10 )
return V_10 ;
V_82 = V_78 -> V_82 - ( V_208 - * V_135 ) ;
if ( F_103 ( V_122 , & V_225 -> V_122 ) != 0 ||
F_103 ( V_82 , & V_225 -> V_82 ) != 0 )
return - V_175 ;
return 0 ;
}
static int F_104 ( unsigned int V_170 ,
struct V_1 * V_85 ,
void T_6 * V_171 )
{
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
void T_6 * V_128 ;
unsigned int V_135 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_123 ;
V_111 = F_55 ( V_85 ) ;
if ( F_39 ( V_111 ) )
return F_40 ( V_111 ) ;
V_128 = V_171 ;
V_135 = V_170 ;
F_31 (iter, private->entries, total_size) {
V_10 = F_101 ( V_123 , & V_128 ,
& V_135 , V_111 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_61 ( V_111 ) ;
return V_10 ;
}
static int F_105 ( struct V_103 * V_103 ,
struct V_226 T_6 * V_188 ,
int * V_8 )
{
int V_10 ;
struct V_226 V_189 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_189 ) )
return - V_153 ;
if ( F_71 ( & V_189 , V_188 , sizeof( V_189 ) ) != 0 )
return - V_175 ;
if ( * V_8 != sizeof( struct V_226 ) + V_189 . V_135 )
return - V_153 ;
V_189 . V_99 [ sizeof( V_189 . V_99 ) - 1 ] = '\0' ;
F_73 ( V_106 ) ;
V_108 = F_75 ( V_103 , V_106 , V_189 . V_99 ) ;
if ( ! F_76 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
struct V_94 V_2 ;
V_10 = F_68 ( V_95 , & V_2 ) ;
if ( ! V_10 && V_189 . V_135 == V_2 . V_135 ) {
V_10 = F_104 ( V_95 -> V_135 ,
V_108 , V_188 -> V_190 ) ;
} else if ( ! V_10 )
V_10 = - V_191 ;
F_77 ( V_106 ) ;
F_41 ( V_108 -> V_147 ) ;
F_78 ( V_108 ) ;
} else
V_10 = V_108 ? F_40 ( V_108 ) : - V_186 ;
F_79 ( V_106 ) ;
return V_10 ;
}
static int F_106 ( struct V_217 * V_218 , int V_219 , void T_6 * V_132 ,
int * V_8 )
{
int V_10 ;
if ( ! F_99 ( F_100 ( V_218 ) -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_219 ) {
case V_227 :
V_10 = F_70 ( F_100 ( V_218 ) , V_132 , V_8 , 1 ) ;
break;
case V_228 :
V_10 = F_105 ( F_100 ( V_218 ) , V_132 , V_8 ) ;
break;
default:
V_10 = F_107 ( V_218 , V_219 , V_132 , V_8 ) ;
}
return V_10 ;
}
static int F_108 ( struct V_217 * V_218 , int V_219 , void T_6 * V_132 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_99 ( F_100 ( V_218 ) -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_219 ) {
case V_223 :
V_10 = F_85 ( F_100 ( V_218 ) , V_132 , V_8 ) ;
break;
case V_224 :
V_10 = F_87 ( F_100 ( V_218 ) , V_132 , V_8 , 0 ) ;
break;
default:
V_10 = - V_153 ;
}
return V_10 ;
}
static int F_107 ( struct V_217 * V_218 , int V_219 , void T_6 * V_132 , int * V_8 )
{
int V_10 ;
if ( ! F_99 ( F_100 ( V_218 ) -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_219 ) {
case V_227 :
V_10 = F_70 ( F_100 ( V_218 ) , V_132 , V_8 , 0 ) ;
break;
case V_228 :
V_10 = F_80 ( F_100 ( V_218 ) , V_132 , V_8 ) ;
break;
case V_229 : {
struct V_230 V_231 ;
if ( * V_8 != sizeof( V_231 ) ) {
V_10 = - V_153 ;
break;
}
if ( F_71 ( & V_231 , V_132 , sizeof( V_231 ) ) != 0 ) {
V_10 = - V_175 ;
break;
}
V_231 . V_99 [ sizeof( V_231 . V_99 ) - 1 ] = 0 ;
F_74 ( F_109 ( V_106 , V_231 . V_99 ,
V_231 . V_145 , 1 , & V_10 ) ,
L_4 , V_231 . V_99 ) ;
break;
}
default:
V_10 = - V_153 ;
}
return V_10 ;
}
static void F_110 ( struct V_1 * V_85 )
{
struct V_94 * V_95 ;
void * V_174 ;
struct V_232 * V_233 = V_85 -> V_147 ;
struct V_77 * V_123 ;
V_95 = F_111 ( V_85 ) ;
V_174 = V_95 -> V_101 ;
F_31 (iter, loc_cpu_entry, private->size)
F_47 ( V_123 ) ;
if ( V_95 -> V_159 > V_95 -> V_182 )
F_41 ( V_233 ) ;
F_83 ( V_95 ) ;
}
int F_112 ( struct V_103 * V_103 ,
const struct V_1 * V_85 ,
const struct V_157 * V_158 ,
const struct V_234 * V_235 ,
struct V_1 * * V_236 )
{
int V_10 ;
struct V_94 * V_124 ;
struct V_94 V_237 = { 0 } ;
void * V_174 ;
struct V_1 * V_238 ;
V_124 = F_86 ( V_158 -> V_135 ) ;
if ( ! V_124 )
return - V_144 ;
V_174 = V_124 -> V_101 ;
memcpy ( V_174 , V_158 -> V_101 , V_158 -> V_135 ) ;
V_10 = F_48 ( V_124 , V_174 , V_158 ) ;
if ( V_10 != 0 )
goto V_239;
V_238 = F_113 ( V_103 , V_85 , & V_237 , V_124 ) ;
if ( F_39 ( V_238 ) ) {
V_10 = F_40 ( V_238 ) ;
goto V_239;
}
F_114 ( * V_236 , V_238 ) ;
V_10 = F_115 ( V_103 , V_235 , F_116 ( V_85 -> V_125 ) ) ;
if ( V_10 != 0 ) {
F_110 ( V_238 ) ;
* V_236 = NULL ;
}
return V_10 ;
V_239:
F_83 ( V_124 ) ;
return V_10 ;
}
void F_117 ( struct V_103 * V_103 , struct V_1 * V_85 ,
const struct V_234 * V_235 )
{
F_118 ( V_103 , V_235 , F_116 ( V_85 -> V_125 ) ) ;
F_110 ( V_85 ) ;
}
static int T_9 F_119 ( struct V_103 * V_103 )
{
return F_120 ( V_103 , V_106 ) ;
}
static void T_10 F_121 ( struct V_103 * V_103 )
{
F_122 ( V_103 , V_106 ) ;
}
static int T_11 F_123 ( void )
{
int V_10 ;
V_10 = F_124 ( & V_240 ) ;
if ( V_10 < 0 )
goto V_241;
V_10 = F_125 ( V_242 , F_126 ( V_242 ) ) ;
if ( V_10 < 0 )
goto V_243;
V_10 = F_127 ( & V_244 ) ;
if ( V_10 < 0 )
goto V_245;
F_128 ( L_5 ) ;
return 0 ;
V_245:
F_129 ( V_242 , F_126 ( V_242 ) ) ;
V_243:
F_130 ( & V_240 ) ;
V_241:
return V_10 ;
}
static void T_12 F_131 ( void )
{
F_132 ( & V_244 ) ;
F_129 ( V_242 , F_126 ( V_242 ) ) ;
F_130 ( & V_240 ) ;
}
