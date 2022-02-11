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
V_35 ) ) {
F_9 ( L_1 ) ;
F_9 ( L_2 ,
V_20 -> V_32 , V_26 -> V_34 , V_26 -> V_33 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_36 & V_26 -> V_37 ) != V_26 -> V_38 ,
V_39 ) ) {
F_9 ( L_3 ) ;
F_9 ( L_4 ,
V_20 -> V_36 , V_26 -> V_38 , V_26 -> V_37 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_40 & V_26 -> V_41 ) != V_26 -> V_42 ,
V_43 ) ) {
F_9 ( L_5 ) ;
F_9 ( L_6 ,
V_20 -> V_40 , V_26 -> V_42 , V_26 -> V_41 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_44 & V_26 -> V_45 ) != V_26 -> V_46 ,
V_47 ) ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ,
V_20 -> V_44 , V_26 -> V_46 , V_26 -> V_45 ) ;
return 0 ;
}
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
V_51 ) ) {
F_9 ( L_9 ) ;
return 0 ;
}
if ( F_8 ( ( V_30 & V_26 -> V_52 . V_53 ) != V_26 -> V_54 . V_53 ,
V_55 ) ||
F_8 ( ( ( V_31 & V_26 -> V_56 . V_53 ) != V_26 -> V_57 . V_53 ) ,
V_58 ) ) {
F_9 ( L_10 ) ;
F_9 ( L_11 ,
& V_30 ,
& V_26 -> V_52 . V_53 ,
& V_26 -> V_54 . V_53 ,
V_26 -> V_59 & V_55 ? L_12 : L_13 ) ;
F_9 ( L_14 ,
& V_31 ,
& V_26 -> V_56 . V_53 ,
& V_26 -> V_57 . V_53 ,
V_26 -> V_59 & V_58 ? L_12 : L_13 ) ;
return 0 ;
}
V_10 = F_4 ( V_23 , V_26 -> V_60 , V_26 -> V_61 ) ;
if ( F_8 ( V_10 != 0 , V_62 ) ) {
F_9 ( L_15 ,
V_23 , V_26 -> V_60 ,
V_26 -> V_59 & V_62 ? L_12 : L_13 ) ;
return 0 ;
}
V_10 = F_4 ( V_24 , V_26 -> V_63 , V_26 -> V_64 ) ;
if ( F_8 ( V_10 != 0 , V_65 ) ) {
F_9 ( L_16 ,
V_24 , V_26 -> V_63 ,
V_26 -> V_59 & V_65 ? L_12 : L_13 ) ;
return 0 ;
}
return 1 ;
#undef F_8
}
static inline int F_10 ( const struct V_25 * V_66 )
{
if ( V_66 -> V_67 & ~ V_68 ) {
F_11 ( L_17 ,
V_66 -> V_67 & ~ V_68 ) ;
return 0 ;
}
if ( V_66 -> V_59 & ~ V_69 ) {
F_11 ( L_18 ,
V_66 -> V_59 & ~ V_69 ) ;
return 0 ;
}
return 1 ;
}
static unsigned int
F_12 ( struct V_70 * V_71 , const struct V_72 * V_73 )
{
F_13 ( L_19 ,
( const char * ) V_73 -> V_74 ) ;
return V_75 ;
}
static inline const struct V_76 *
F_14 ( const struct V_77 * V_78 )
{
return F_15 ( (struct V_77 * ) V_78 ) ;
}
static inline struct V_77 *
F_16 ( const void * V_79 , unsigned int V_80 )
{
return (struct V_77 * ) ( V_79 + V_80 ) ;
}
static inline
struct V_77 * F_17 ( const struct V_77 * V_81 )
{
return ( void * ) V_81 + V_81 -> V_82 ;
}
unsigned int F_18 ( struct V_70 * V_71 ,
unsigned int V_83 ,
const struct V_84 * V_85 ,
struct V_1 * V_86 )
{
static const char V_87 [ V_19 ] V_88 ( ( F_19 ( sizeof( long ) ) ) ) ;
unsigned int V_89 = V_75 ;
const struct V_20 * V_66 ;
struct V_77 * V_78 , * * V_90 ;
const char * V_23 , * V_24 ;
const void * V_91 ;
unsigned int V_92 , V_93 = 0 ;
const struct V_94 * V_95 ;
struct V_72 V_96 ;
unsigned int V_97 ;
if ( ! F_20 ( V_71 , F_21 ( V_71 -> V_22 ) ) )
return V_75 ;
V_23 = V_85 -> V_98 ? V_85 -> V_98 -> V_99 : V_87 ;
V_24 = V_85 -> V_100 ? V_85 -> V_100 -> V_99 : V_87 ;
F_22 () ;
V_97 = F_23 () ;
V_95 = V_86 -> V_95 ;
V_92 = F_24 () ;
F_25 () ;
V_91 = V_95 -> V_101 ;
V_90 = (struct V_77 * * ) V_95 -> V_90 [ V_92 ] ;
V_78 = F_16 ( V_91 , V_95 -> V_102 [ V_83 ] ) ;
V_96 . V_98 = V_85 -> V_98 ;
V_96 . V_100 = V_85 -> V_100 ;
V_96 . V_103 = V_83 ;
V_96 . V_104 = V_105 ;
V_96 . V_106 = false ;
V_66 = F_26 ( V_71 ) ;
do {
const struct V_76 * V_107 ;
struct V_108 * V_109 ;
if ( ! F_7 ( V_66 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_66 ) ) {
V_78 = F_17 ( V_78 ) ;
continue;
}
V_109 = F_27 ( & V_78 -> V_110 ) ;
F_28 ( * V_109 , F_21 ( V_71 -> V_22 ) , 1 ) ;
V_107 = F_14 ( V_78 ) ;
if ( ! V_107 -> V_111 . V_112 . V_113 -> V_113 ) {
int V_114 ;
V_114 = ( (struct V_115 * ) V_107 ) -> V_89 ;
if ( V_114 < 0 ) {
if ( V_114 != V_116 ) {
V_89 = ( unsigned int ) ( - V_114 ) - 1 ;
break;
}
if ( V_93 == 0 ) {
V_78 = F_16 ( V_91 ,
V_95 -> V_117 [ V_83 ] ) ;
} else {
V_78 = V_90 [ -- V_93 ] ;
V_78 = F_17 ( V_78 ) ;
}
continue;
}
if ( V_91 + V_114
!= F_17 ( V_78 ) ) {
V_90 [ V_93 ++ ] = V_78 ;
}
V_78 = F_16 ( V_91 , V_114 ) ;
continue;
}
V_96 . V_113 = V_107 -> V_111 . V_112 . V_113 ;
V_96 . V_74 = V_107 -> V_118 ;
V_89 = V_107 -> V_111 . V_112 . V_113 -> V_113 ( V_71 , & V_96 ) ;
V_66 = F_26 ( V_71 ) ;
if ( V_89 == V_119 )
V_78 = F_17 ( V_78 ) ;
else
break;
} while ( ! V_96 . V_106 );
F_29 ( V_97 ) ;
F_30 () ;
if ( V_96 . V_106 )
return V_75 ;
else
return V_89 ;
}
static inline bool F_31 ( const struct V_25 * V_66 )
{
static const struct V_25 V_120 ;
return memcmp ( V_66 , & V_120 , sizeof( V_120 ) ) == 0 ;
}
static int F_32 ( const struct V_94 * V_121 ,
unsigned int V_122 , void * V_123 )
{
unsigned int V_83 ;
for ( V_83 = 0 ; V_83 < V_124 ; V_83 ++ ) {
unsigned int V_125 = V_121 -> V_102 [ V_83 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_123 + V_125 ) ;
if ( ! ( V_122 & ( 1 << V_83 ) ) )
continue;
V_78 -> V_110 . V_126 = V_125 ;
for (; ; ) {
const struct V_115 * V_107
= ( void * ) F_14 ( V_78 ) ;
int V_127 = V_78 -> V_128 & ( 1 << V_83 ) ;
if ( V_78 -> V_128 & ( 1 << V_124 ) ) {
F_33 ( L_20 ,
V_83 , V_125 , V_78 -> V_128 ) ;
return 0 ;
}
V_78 -> V_128
|= ( ( 1 << V_83 ) | ( 1 << V_124 ) ) ;
if ( ( V_78 -> V_129 == sizeof( struct V_77 ) &&
( strcmp ( V_107 -> V_113 . V_111 . V_130 . V_99 ,
V_131 ) == 0 ) &&
V_107 -> V_89 < 0 && F_31 ( & V_78 -> V_66 ) ) ||
V_127 ) {
unsigned int V_132 , V_133 ;
if ( ( strcmp ( V_107 -> V_113 . V_111 . V_130 . V_99 ,
V_131 ) == 0 ) &&
V_107 -> V_89 < - V_134 - 1 ) {
F_11 ( L_21
L_22 ,
V_107 -> V_89 ) ;
return 0 ;
}
do {
V_78 -> V_128 ^= ( 1 << V_124 ) ;
V_132 = V_125 ;
V_125 = V_78 -> V_110 . V_126 ;
V_78 -> V_110 . V_126 = 0 ;
if ( V_125 == V_132 )
goto V_135;
V_78 = (struct V_77 * )
( V_123 + V_125 ) ;
} while ( V_132 == V_125 + V_78 -> V_82 );
V_133 = V_78 -> V_82 ;
V_78 = (struct V_77 * )
( V_123 + V_125 + V_133 ) ;
V_78 -> V_110 . V_126 = V_125 ;
V_125 += V_133 ;
} else {
int V_136 = V_107 -> V_89 ;
if ( strcmp ( V_107 -> V_113 . V_111 . V_130 . V_99 ,
V_131 ) == 0 &&
V_136 >= 0 ) {
if ( V_136 > V_121 -> V_133 -
sizeof( struct V_77 ) ) {
F_11 ( L_23
L_24 ,
V_136 ) ;
return 0 ;
}
F_11 ( L_25 ,
V_125 , V_136 ) ;
} else {
V_136 = V_125 + V_78 -> V_82 ;
}
V_78 = (struct V_77 * )
( V_123 + V_136 ) ;
V_78 -> V_110 . V_126 = V_125 ;
V_125 = V_136 ;
}
}
V_135:
F_11 ( L_26 , V_83 ) ;
}
return 1 ;
}
static inline int F_34 ( const struct V_77 * V_78 , const char * V_99 )
{
const struct V_76 * V_107 ;
if ( ! F_10 ( & V_78 -> V_66 ) ) {
F_11 ( L_27 , V_78 , V_99 ) ;
return - V_137 ;
}
if ( V_78 -> V_129 + sizeof( struct V_76 ) > V_78 -> V_82 )
return - V_137 ;
V_107 = F_14 ( V_78 ) ;
if ( V_78 -> V_129 + V_107 -> V_111 . V_138 > V_78 -> V_82 )
return - V_137 ;
return 0 ;
}
static inline int F_35 ( struct V_77 * V_78 , const char * V_99 )
{
struct V_76 * V_107 = F_15 ( V_78 ) ;
int V_10 ;
struct V_139 V_73 = {
. V_86 = V_99 ,
. V_140 = V_78 ,
. V_113 = V_107 -> V_111 . V_112 . V_113 ,
. V_74 = V_107 -> V_118 ,
. V_141 = V_78 -> V_128 ,
. V_104 = V_105 ,
} ;
V_10 = F_36 ( & V_73 , V_107 -> V_111 . V_138 - sizeof( * V_107 ) , 0 , false ) ;
if ( V_10 < 0 ) {
F_11 ( L_28 ,
V_107 -> V_111 . V_112 . V_113 -> V_99 ) ;
return V_10 ;
}
return 0 ;
}
static inline int
F_37 ( struct V_77 * V_78 , const char * V_99 , unsigned int V_133 )
{
struct V_76 * V_107 ;
struct V_142 * V_113 ;
int V_10 ;
V_10 = F_34 ( V_78 , V_99 ) ;
if ( V_10 )
return V_10 ;
V_78 -> V_110 . V_126 = F_38 () ;
if ( F_39 ( V_78 -> V_110 . V_126 ) )
return - V_143 ;
V_107 = F_15 ( V_78 ) ;
V_113 = F_40 ( V_105 , V_107 -> V_111 . V_130 . V_99 ,
V_107 -> V_111 . V_130 . V_144 ) ;
if ( F_41 ( V_113 ) ) {
F_11 ( L_29 , V_107 -> V_111 . V_130 . V_99 ) ;
V_10 = F_42 ( V_113 ) ;
goto V_100;
}
V_107 -> V_111 . V_112 . V_113 = V_113 ;
V_10 = F_35 ( V_78 , V_99 ) ;
if ( V_10 )
goto V_145;
return 0 ;
V_145:
F_43 ( V_107 -> V_111 . V_112 . V_113 -> V_146 ) ;
V_100:
F_44 ( V_78 -> V_110 . V_126 ) ;
return V_10 ;
}
static bool F_45 ( const struct V_77 * V_78 )
{
const struct V_76 * V_107 ;
unsigned int V_89 ;
if ( ! F_31 ( & V_78 -> V_66 ) )
return false ;
V_107 = F_14 ( V_78 ) ;
if ( strcmp ( V_107 -> V_111 . V_130 . V_99 , V_131 ) != 0 )
return false ;
V_89 = ( (struct V_115 * ) V_107 ) -> V_89 ;
V_89 = - V_89 - 1 ;
return V_89 == V_75 || V_89 == V_147 ;
}
static inline int F_46 ( struct V_77 * V_78 ,
struct V_94 * V_121 ,
const unsigned char * V_79 ,
const unsigned char * V_148 ,
const unsigned int * V_149 ,
const unsigned int * V_150 ,
unsigned int V_122 )
{
unsigned int V_151 ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_148 ) {
F_11 ( L_30 , V_78 ) ;
return - V_137 ;
}
if ( V_78 -> V_82
< sizeof( struct V_77 ) + sizeof( struct V_76 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_82 ) ;
return - V_137 ;
}
for ( V_151 = 0 ; V_151 < V_124 ; V_151 ++ ) {
if ( ! ( V_122 & ( 1 << V_151 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_149 [ V_151 ] )
V_121 -> V_102 [ V_151 ] = V_149 [ V_151 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_151 ] ) {
if ( ! F_45 ( V_78 ) ) {
F_48 ( L_32
L_33
L_34 ) ;
return - V_137 ;
}
V_121 -> V_117 [ V_151 ] = V_150 [ V_151 ] ;
}
}
V_78 -> V_110 = ( (struct V_108 ) { 0 , 0 } ) ;
V_78 -> V_128 = 0 ;
return 0 ;
}
static inline void F_49 ( struct V_77 * V_78 )
{
struct V_152 V_73 ;
struct V_76 * V_107 ;
V_107 = F_15 ( V_78 ) ;
V_73 . V_113 = V_107 -> V_111 . V_112 . V_113 ;
V_73 . V_74 = V_107 -> V_118 ;
V_73 . V_104 = V_105 ;
if ( V_73 . V_113 -> V_153 != NULL )
V_73 . V_113 -> V_153 ( & V_73 ) ;
F_43 ( V_73 . V_113 -> V_146 ) ;
F_44 ( V_78 -> V_110 . V_126 ) ;
}
static int F_50 ( struct V_94 * V_121 , void * V_123 ,
const struct V_154 * V_155 )
{
struct V_77 * V_156 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_121 -> V_133 = V_155 -> V_133 ;
V_121 -> V_157 = V_155 -> V_158 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
V_121 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_121 -> V_117 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_35 , V_121 -> V_133 ) ;
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_46 ( V_156 , V_121 , V_123 ,
V_123 + V_155 -> V_133 ,
V_155 -> V_102 ,
V_155 -> V_117 ,
V_155 -> V_122 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_156 ) -> V_111 . V_130 . V_99 ,
V_159 ) == 0 )
++ V_121 -> V_160 ;
}
F_11 ( L_36 , V_10 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_155 -> V_158 ) {
F_11 ( L_37 ,
V_9 , V_155 -> V_158 ) ;
return - V_137 ;
}
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
if ( ! ( V_155 -> V_122 & ( 1 << V_9 ) ) )
continue;
if ( V_121 -> V_102 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_155 -> V_102 [ V_9 ] ) ;
return - V_137 ;
}
if ( V_121 -> V_117 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_155 -> V_117 [ V_9 ] ) ;
return - V_137 ;
}
}
if ( ! F_32 ( V_121 , V_155 -> V_122 , V_123 ) ) {
F_11 ( L_40 ) ;
return - V_161 ;
}
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_37 ( V_156 , V_155 -> V_99 , V_155 -> V_133 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_51 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_49 ( V_156 ) ;
}
return V_10 ;
}
return V_10 ;
}
static void F_52 ( const struct V_94 * V_107 ,
struct V_108 V_110 [] )
{
struct V_77 * V_156 ;
unsigned int V_92 ;
unsigned int V_9 ;
F_53 (cpu) {
T_4 * V_162 = & F_54 ( V_163 , V_92 ) ;
V_9 = 0 ;
F_51 (iter, t->entries, t->size) {
struct V_108 * V_164 ;
T_5 V_165 , V_126 ;
unsigned int V_166 ;
V_164 = F_55 ( & V_156 -> V_110 , V_92 ) ;
do {
V_166 = F_56 ( V_162 ) ;
V_165 = V_164 -> V_165 ;
V_126 = V_164 -> V_126 ;
} while ( F_57 ( V_162 , V_166 ) );
F_28 ( V_110 [ V_9 ] , V_165 , V_126 ) ;
++ V_9 ;
}
}
}
static struct V_108 * F_58 ( const struct V_1 * V_86 )
{
unsigned int V_167 ;
struct V_108 * V_110 ;
const struct V_94 * V_95 = V_86 -> V_95 ;
V_167 = sizeof( struct V_108 ) * V_95 -> V_157 ;
V_110 = F_59 ( V_167 ) ;
if ( V_110 == NULL )
return F_60 ( - V_143 ) ;
F_52 ( V_95 , V_110 ) ;
return V_110 ;
}
static int F_61 ( unsigned int V_168 ,
const struct V_1 * V_86 ,
void T_6 * V_169 )
{
unsigned int V_170 , V_171 ;
const struct V_77 * V_78 ;
struct V_108 * V_110 ;
struct V_94 * V_95 = V_86 -> V_95 ;
int V_10 = 0 ;
void * V_172 ;
V_110 = F_58 ( V_86 ) ;
if ( F_41 ( V_110 ) )
return F_42 ( V_110 ) ;
V_172 = V_95 -> V_101 ;
if ( F_62 ( V_169 , V_172 , V_168 ) != 0 ) {
V_10 = - V_173 ;
goto V_174;
}
for ( V_170 = 0 , V_171 = 0 ; V_170 < V_168 ; V_170 += V_78 -> V_82 , V_171 ++ ) {
const struct V_76 * V_107 ;
V_78 = (struct V_77 * ) ( V_172 + V_170 ) ;
if ( F_62 ( V_169 + V_170
+ F_63 ( struct V_77 , V_110 ) ,
& V_110 [ V_171 ] ,
sizeof( V_110 [ V_171 ] ) ) != 0 ) {
V_10 = - V_173 ;
goto V_174;
}
V_107 = F_14 ( V_78 ) ;
if ( F_62 ( V_169 + V_170 + V_78 -> V_129
+ F_63 ( struct V_76 ,
V_111 . V_130 . V_99 ) ,
V_107 -> V_111 . V_112 . V_113 -> V_99 ,
strlen ( V_107 -> V_111 . V_112 . V_113 -> V_99 ) + 1 ) != 0 ) {
V_10 = - V_173 ;
goto V_174;
}
}
V_174:
F_64 ( V_110 ) ;
return V_10 ;
}
static void F_65 ( void * V_175 , const void * V_54 )
{
int V_114 = * ( V_176 * ) V_54 ;
if ( V_114 > 0 )
V_114 += F_66 ( V_105 , V_114 ) ;
memcpy ( V_175 , & V_114 , sizeof( V_114 ) ) ;
}
static int F_67 ( void T_6 * V_175 , const void * V_54 )
{
V_176 V_177 = * ( int * ) V_54 ;
if ( V_177 > 0 )
V_177 -= F_66 ( V_105 , V_177 ) ;
return F_62 ( V_175 , & V_177 , sizeof( V_177 ) ) ? - V_173 : 0 ;
}
static int F_68 ( const struct V_77 * V_78 ,
const struct V_94 * V_2 ,
const void * V_79 , struct V_94 * V_121 )
{
const struct V_76 * V_107 ;
unsigned int V_178 ;
int V_170 , V_9 , V_10 ;
V_170 = sizeof( struct V_77 ) - sizeof( struct V_179 ) ;
V_178 = ( void * ) V_78 - V_79 ;
V_107 = F_14 ( V_78 ) ;
V_170 += F_69 ( V_107 -> V_111 . V_112 . V_113 ) ;
V_121 -> V_133 -= V_170 ;
V_10 = F_70 ( V_105 , V_178 , V_170 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
if ( V_2 -> V_102 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_102 [ V_9 ] ) ) )
V_121 -> V_102 [ V_9 ] -= V_170 ;
if ( V_2 -> V_117 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_117 [ V_9 ] ) ) )
V_121 -> V_117 [ V_9 ] -= V_170 ;
}
return 0 ;
}
static int F_71 ( const struct V_94 * V_2 ,
struct V_94 * V_121 )
{
struct V_77 * V_156 ;
const void * V_172 ;
int V_10 ;
if ( ! V_121 || ! V_2 )
return - V_137 ;
memcpy ( V_121 , V_2 , F_63 ( struct V_94 , V_101 ) ) ;
V_121 -> V_180 = 0 ;
V_172 = V_2 -> V_101 ;
F_72 ( V_105 , V_2 -> V_157 ) ;
F_51 (iter, loc_cpu_entry, info->size) {
V_10 = F_68 ( V_156 , V_2 , V_172 , V_121 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_73 ( struct V_181 * V_181 , void T_6 * V_130 ,
const int * V_8 , int V_182 )
{
char V_99 [ V_183 ] ;
struct V_1 * V_107 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_184 ) ) {
F_11 ( L_41 , * V_8 ,
sizeof( struct V_184 ) ) ;
return - V_137 ;
}
if ( F_74 ( V_99 , V_130 , sizeof( V_99 ) ) != 0 )
return - V_173 ;
V_99 [ V_183 - 1 ] = '\0' ;
#ifdef F_75
if ( V_182 )
F_76 ( V_105 ) ;
#endif
V_107 = F_77 ( F_78 ( V_181 , V_105 , V_99 ) ,
L_42 , V_99 ) ;
if ( ! F_79 ( V_107 ) ) {
struct V_184 V_2 ;
const struct V_94 * V_95 = V_107 -> V_95 ;
#ifdef F_75
struct V_94 V_164 ;
if ( V_182 ) {
V_10 = F_71 ( V_95 , & V_164 ) ;
F_80 ( V_105 ) ;
V_95 = & V_164 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_122 = V_107 -> V_122 ;
memcpy ( V_2 . V_102 , V_95 -> V_102 ,
sizeof( V_2 . V_102 ) ) ;
memcpy ( V_2 . V_117 , V_95 -> V_117 ,
sizeof( V_2 . V_117 ) ) ;
V_2 . V_158 = V_95 -> V_157 ;
V_2 . V_133 = V_95 -> V_133 ;
strcpy ( V_2 . V_99 , V_99 ) ;
if ( F_62 ( V_130 , & V_2 , * V_8 ) != 0 )
V_10 = - V_173 ;
else
V_10 = 0 ;
F_81 ( V_107 ) ;
F_43 ( V_107 -> V_146 ) ;
} else
V_10 = V_107 ? F_42 ( V_107 ) : - V_185 ;
#ifdef F_75
if ( V_182 )
F_82 ( V_105 ) ;
#endif
return V_10 ;
}
static int F_83 ( struct V_181 * V_181 , struct V_186 T_6 * V_187 ,
const int * V_8 )
{
int V_10 ;
struct V_186 V_188 ;
struct V_1 * V_107 ;
if ( * V_8 < sizeof( V_188 ) ) {
F_11 ( L_43 , * V_8 , sizeof( V_188 ) ) ;
return - V_137 ;
}
if ( F_74 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_173 ;
if ( * V_8 != sizeof( struct V_186 ) + V_188 . V_133 ) {
F_11 ( L_44 , * V_8 ,
sizeof( struct V_186 ) + V_188 . V_133 ) ;
return - V_137 ;
}
V_107 = F_78 ( V_181 , V_105 , V_188 . V_99 ) ;
if ( ! F_79 ( V_107 ) ) {
const struct V_94 * V_95 = V_107 -> V_95 ;
F_11 ( L_45 ,
V_95 -> V_157 ) ;
if ( V_188 . V_133 == V_95 -> V_133 )
V_10 = F_61 ( V_95 -> V_133 ,
V_107 , V_187 -> V_189 ) ;
else {
F_11 ( L_46 ,
V_95 -> V_133 , V_188 . V_133 ) ;
V_10 = - V_190 ;
}
F_43 ( V_107 -> V_146 ) ;
F_81 ( V_107 ) ;
} else
V_10 = V_107 ? F_42 ( V_107 ) : - V_185 ;
return V_10 ;
}
static int F_84 ( struct V_181 * V_181 , const char * V_99 ,
unsigned int V_122 ,
struct V_94 * V_121 ,
unsigned int V_191 ,
void T_6 * V_192 )
{
int V_10 ;
struct V_1 * V_107 ;
struct V_94 * V_193 ;
struct V_108 * V_110 ;
void * V_194 ;
struct V_77 * V_156 ;
V_10 = 0 ;
V_110 = F_59 ( V_191 * sizeof( struct V_108 ) ) ;
if ( ! V_110 ) {
V_10 = - V_143 ;
goto V_100;
}
V_107 = F_77 ( F_78 ( V_181 , V_105 , V_99 ) ,
L_42 , V_99 ) ;
if ( F_79 ( V_107 ) ) {
V_10 = V_107 ? F_42 ( V_107 ) : - V_185 ;
goto V_195;
}
if ( V_122 != V_107 -> V_122 ) {
F_11 ( L_47 ,
V_122 , V_107 -> V_122 ) ;
V_10 = - V_137 ;
goto V_196;
}
V_193 = F_85 ( V_107 , V_191 , V_121 , & V_10 ) ;
if ( ! V_193 )
goto V_196;
F_11 ( L_48 ,
V_193 -> V_157 , V_193 -> V_180 , V_121 -> V_157 ) ;
if ( ( V_193 -> V_157 > V_193 -> V_180 ) ||
( V_121 -> V_157 <= V_193 -> V_180 ) )
F_43 ( V_107 -> V_146 ) ;
if ( ( V_193 -> V_157 > V_193 -> V_180 ) &&
( V_121 -> V_157 <= V_193 -> V_180 ) )
F_43 ( V_107 -> V_146 ) ;
F_52 ( V_193 , V_110 ) ;
V_194 = V_193 -> V_101 ;
F_51 (iter, loc_cpu_old_entry, oldinfo->size)
F_49 ( V_156 ) ;
F_86 ( V_193 ) ;
if ( F_62 ( V_192 , V_110 ,
sizeof( struct V_108 ) * V_191 ) != 0 ) {
F_87 ( L_49 ) ;
}
F_64 ( V_110 ) ;
F_81 ( V_107 ) ;
return V_10 ;
V_196:
F_43 ( V_107 -> V_146 ) ;
F_81 ( V_107 ) ;
V_195:
F_64 ( V_110 ) ;
V_100:
return V_10 ;
}
static int F_88 ( struct V_181 * V_181 , const void T_6 * V_130 ,
unsigned int V_8 )
{
int V_10 ;
struct V_154 V_164 ;
struct V_94 * V_121 ;
void * V_172 ;
struct V_77 * V_156 ;
if ( F_74 ( & V_164 , V_130 , sizeof( V_164 ) ) != 0 )
return - V_173 ;
if ( V_164 . V_191 >= V_197 / sizeof( struct V_108 ) )
return - V_143 ;
if ( V_164 . V_191 == 0 )
return - V_137 ;
V_164 . V_99 [ sizeof( V_164 . V_99 ) - 1 ] = 0 ;
V_121 = F_89 ( V_164 . V_133 ) ;
if ( ! V_121 )
return - V_143 ;
V_172 = V_121 -> V_101 ;
if ( F_74 ( V_172 , V_130 + sizeof( V_164 ) ,
V_164 . V_133 ) != 0 ) {
V_10 = - V_173 ;
goto V_198;
}
V_10 = F_50 ( V_121 , V_172 , & V_164 ) ;
if ( V_10 != 0 )
goto V_198;
F_11 ( L_50 ) ;
V_10 = F_84 ( V_181 , V_164 . V_99 , V_164 . V_122 , V_121 ,
V_164 . V_191 , V_164 . V_110 ) ;
if ( V_10 )
goto V_199;
return 0 ;
V_199:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_156 ) ;
V_198:
F_86 ( V_121 ) ;
return V_10 ;
}
static int F_90 ( struct V_181 * V_181 , const void T_6 * V_130 ,
unsigned int V_8 , int V_182 )
{
unsigned int V_9 ;
struct V_200 V_164 ;
struct V_108 * V_201 ;
unsigned int V_191 ;
const char * V_99 ;
int V_133 ;
void * V_202 ;
struct V_1 * V_107 ;
const struct V_94 * V_95 ;
int V_10 = 0 ;
struct V_77 * V_156 ;
unsigned int V_97 ;
#ifdef F_75
struct V_203 V_204 ;
if ( V_182 ) {
V_202 = & V_204 ;
V_133 = sizeof( struct V_203 ) ;
} else
#endif
{
V_202 = & V_164 ;
V_133 = sizeof( struct V_200 ) ;
}
if ( F_74 ( V_202 , V_130 , V_133 ) != 0 )
return - V_173 ;
#ifdef F_75
if ( V_182 ) {
V_191 = V_204 . V_191 ;
V_99 = V_204 . V_99 ;
} else
#endif
{
V_191 = V_164 . V_191 ;
V_99 = V_164 . V_99 ;
}
if ( V_8 != V_133 + V_191 * sizeof( struct V_108 ) )
return - V_137 ;
V_201 = F_91 ( V_8 - V_133 ) ;
if ( ! V_201 )
return - V_143 ;
if ( F_74 ( V_201 , V_130 + V_133 , V_8 - V_133 ) != 0 ) {
V_10 = - V_173 ;
goto free;
}
V_107 = F_78 ( V_181 , V_105 , V_99 ) ;
if ( F_79 ( V_107 ) ) {
V_10 = V_107 ? F_42 ( V_107 ) : - V_185 ;
goto free;
}
F_22 () ;
V_95 = V_107 -> V_95 ;
if ( V_95 -> V_157 != V_191 ) {
V_10 = - V_137 ;
goto V_205;
}
V_9 = 0 ;
V_97 = F_23 () ;
F_51 (iter, private->entries, private->size) {
struct V_108 * V_164 ;
V_164 = F_27 ( & V_156 -> V_110 ) ;
F_28 ( * V_164 , V_201 [ V_9 ] . V_165 , V_201 [ V_9 ] . V_126 ) ;
++ V_9 ;
}
F_29 ( V_97 ) ;
V_205:
F_30 () ;
F_81 ( V_107 ) ;
F_43 ( V_107 -> V_146 ) ;
free:
F_64 ( V_201 ) ;
return V_10 ;
}
static inline void F_92 ( struct V_179 * V_78 )
{
struct V_76 * V_107 ;
V_107 = F_93 ( V_78 ) ;
F_43 ( V_107 -> V_111 . V_112 . V_113 -> V_146 ) ;
}
static inline int
F_94 ( struct V_179 * V_78 ,
struct V_94 * V_121 ,
unsigned int * V_133 ,
const unsigned char * V_79 ,
const unsigned char * V_148 ,
const unsigned int * V_149 ,
const unsigned int * V_150 ,
const char * V_99 )
{
struct V_76 * V_107 ;
struct V_142 * V_113 ;
unsigned int V_178 ;
int V_10 , V_170 , V_151 ;
F_11 ( L_51 , V_78 ) ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_179 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_179 ) >= V_148 ) {
F_11 ( L_52 , V_78 , V_148 ) ;
return - V_137 ;
}
if ( V_78 -> V_82 < sizeof( struct V_179 ) +
sizeof( struct V_206 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_82 ) ;
return - V_137 ;
}
V_10 = F_34 ( (struct V_77 * ) V_78 , V_99 ) ;
if ( V_10 )
return V_10 ;
V_170 = sizeof( struct V_77 ) - sizeof( struct V_179 ) ;
V_178 = ( void * ) V_78 - ( void * ) V_79 ;
V_107 = F_93 ( V_78 ) ;
V_113 = F_40 ( V_105 , V_107 -> V_111 . V_130 . V_99 ,
V_107 -> V_111 . V_130 . V_144 ) ;
if ( F_41 ( V_113 ) ) {
F_11 ( L_53 ,
V_107 -> V_111 . V_130 . V_99 ) ;
V_10 = F_42 ( V_113 ) ;
goto V_100;
}
V_107 -> V_111 . V_112 . V_113 = V_113 ;
V_170 += F_69 ( V_113 ) ;
* V_133 += V_170 ;
V_10 = F_70 ( V_105 , V_178 , V_170 ) ;
if ( V_10 )
goto V_207;
for ( V_151 = 0 ; V_151 < V_124 ; V_151 ++ ) {
if ( ( unsigned char * ) V_78 - V_79 == V_149 [ V_151 ] )
V_121 -> V_102 [ V_151 ] = V_149 [ V_151 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_151 ] )
V_121 -> V_117 [ V_151 ] = V_150 [ V_151 ] ;
}
memset ( & V_78 -> V_110 , 0 , sizeof( V_78 -> V_110 ) ) ;
V_78 -> V_128 = 0 ;
return 0 ;
V_207:
F_43 ( V_107 -> V_111 . V_112 . V_113 -> V_146 ) ;
V_100:
return V_10 ;
}
static int
F_95 ( struct V_179 * V_78 , void * * V_208 ,
unsigned int * V_133 , const char * V_99 ,
struct V_94 * V_121 , unsigned char * V_79 )
{
struct V_76 * V_107 ;
struct V_142 * V_113 ;
struct V_77 * V_209 ;
unsigned int V_210 ;
int V_10 , V_151 ;
V_10 = 0 ;
V_210 = * V_133 ;
V_209 = (struct V_77 * ) * V_208 ;
memcpy ( V_209 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_209 -> V_110 , & V_78 -> V_110 , sizeof( V_78 -> V_110 ) ) ;
* V_208 += sizeof( struct V_77 ) ;
* V_133 += sizeof( struct V_77 ) - sizeof( struct V_179 ) ;
V_209 -> V_129 = V_78 -> V_129 - ( V_210 - * V_133 ) ;
V_107 = F_93 ( V_78 ) ;
V_113 = V_107 -> V_111 . V_112 . V_113 ;
F_96 ( V_107 , V_208 , V_133 ) ;
V_209 -> V_82 = V_78 -> V_82 - ( V_210 - * V_133 ) ;
for ( V_151 = 0 ; V_151 < V_124 ; V_151 ++ ) {
if ( ( unsigned char * ) V_209 - V_79 < V_121 -> V_102 [ V_151 ] )
V_121 -> V_102 [ V_151 ] -= V_210 - * V_133 ;
if ( ( unsigned char * ) V_209 - V_79 < V_121 -> V_117 [ V_151 ] )
V_121 -> V_117 [ V_151 ] -= V_210 - * V_133 ;
}
return V_10 ;
}
static int F_97 ( const char * V_99 ,
unsigned int V_122 ,
struct V_94 * * V_211 ,
void * * V_212 ,
unsigned int V_168 ,
unsigned int V_157 ,
unsigned int * V_149 ,
unsigned int * V_150 )
{
unsigned int V_9 , V_213 ;
struct V_94 * V_121 , * V_2 ;
void * V_125 , * V_123 , * V_214 ;
struct V_179 * V_215 ;
struct V_77 * V_216 ;
unsigned int V_133 ;
int V_10 = 0 ;
V_2 = * V_211 ;
V_123 = * V_212 ;
V_133 = V_168 ;
V_2 -> V_157 = V_157 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
V_2 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_2 -> V_117 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_54 , V_2 -> V_133 ) ;
V_213 = 0 ;
F_76 ( V_105 ) ;
F_72 ( V_105 , V_157 ) ;
F_51 (iter0, entry0, total_size) {
V_10 = F_94 ( V_215 , V_2 , & V_133 ,
V_123 ,
V_123 + V_168 ,
V_149 ,
V_150 ,
V_99 ) ;
if ( V_10 != 0 )
goto V_217;
++ V_213 ;
}
V_10 = - V_137 ;
if ( V_213 != V_157 ) {
F_11 ( L_55 ,
V_213 , V_157 ) ;
goto V_217;
}
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
if ( ! ( V_122 & ( 1 << V_9 ) ) )
continue;
if ( V_2 -> V_102 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_149 [ V_9 ] ) ;
goto V_217;
}
if ( V_2 -> V_117 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_150 [ V_9 ] ) ;
goto V_217;
}
}
V_10 = - V_143 ;
V_121 = F_89 ( V_133 ) ;
if ( ! V_121 )
goto V_217;
V_121 -> V_157 = V_157 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
V_121 -> V_102 [ V_9 ] = V_2 -> V_102 [ V_9 ] ;
V_121 -> V_117 [ V_9 ] = V_2 -> V_117 [ V_9 ] ;
}
V_214 = V_121 -> V_101 ;
V_125 = V_214 ;
V_133 = V_168 ;
F_51 (iter0, entry0, total_size) {
V_10 = F_95 ( V_215 , & V_125 , & V_133 ,
V_99 , V_121 , V_214 ) ;
if ( V_10 != 0 )
break;
}
F_80 ( V_105 ) ;
F_82 ( V_105 ) ;
if ( V_10 )
goto V_198;
V_10 = - V_161 ;
if ( ! F_32 ( V_121 , V_122 , V_214 ) )
goto V_198;
V_9 = 0 ;
F_51 (iter1, entry1, newinfo->size) {
V_216 -> V_110 . V_126 = F_38 () ;
if ( F_39 ( V_216 -> V_110 . V_126 ) ) {
V_10 = - V_143 ;
break;
}
V_10 = F_35 ( V_216 , V_99 ) ;
if ( V_10 != 0 ) {
F_44 ( V_216 -> V_110 . V_126 ) ;
break;
}
++ V_9 ;
if ( strcmp ( F_15 ( V_216 ) -> V_111 . V_130 . V_99 ,
V_159 ) == 0 )
++ V_121 -> V_160 ;
}
if ( V_10 ) {
int V_218 = V_9 ;
V_213 -= V_9 ;
F_51 (iter0, entry0, newinfo->size) {
if ( V_218 -- > 0 )
continue;
if ( V_213 -- == 0 )
break;
F_92 ( V_215 ) ;
}
F_51 (iter1, entry1, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_49 ( V_216 ) ;
}
F_86 ( V_121 ) ;
return V_10 ;
}
* V_211 = V_121 ;
* V_212 = V_214 ;
F_86 ( V_2 ) ;
return 0 ;
V_198:
F_86 ( V_121 ) ;
V_100:
F_51 (iter0, entry0, total_size) {
if ( V_213 -- == 0 )
break;
F_92 ( V_215 ) ;
}
return V_10 ;
V_217:
F_80 ( V_105 ) ;
F_82 ( V_105 ) ;
goto V_100;
}
static int F_98 ( struct V_181 * V_181 , void T_6 * V_130 ,
unsigned int V_8 )
{
int V_10 ;
struct V_219 V_164 ;
struct V_94 * V_121 ;
void * V_172 ;
struct V_77 * V_156 ;
if ( F_74 ( & V_164 , V_130 , sizeof( V_164 ) ) != 0 )
return - V_173 ;
if ( V_164 . V_133 >= V_197 / F_99 () )
return - V_143 ;
if ( V_164 . V_191 >= V_197 / sizeof( struct V_108 ) )
return - V_143 ;
if ( V_164 . V_191 == 0 )
return - V_137 ;
V_164 . V_99 [ sizeof( V_164 . V_99 ) - 1 ] = 0 ;
V_121 = F_89 ( V_164 . V_133 ) ;
if ( ! V_121 )
return - V_143 ;
V_172 = V_121 -> V_101 ;
if ( F_74 ( V_172 , V_130 + sizeof( V_164 ) , V_164 . V_133 ) != 0 ) {
V_10 = - V_173 ;
goto V_198;
}
V_10 = F_97 ( V_164 . V_99 , V_164 . V_122 ,
& V_121 , & V_172 , V_164 . V_133 ,
V_164 . V_158 , V_164 . V_102 ,
V_164 . V_117 ) ;
if ( V_10 != 0 )
goto V_198;
F_11 ( L_56 ) ;
V_10 = F_84 ( V_181 , V_164 . V_99 , V_164 . V_122 , V_121 ,
V_164 . V_191 , F_100 ( V_164 . V_110 ) ) ;
if ( V_10 )
goto V_199;
return 0 ;
V_199:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_156 ) ;
V_198:
F_86 ( V_121 ) ;
return V_10 ;
}
static int F_101 ( struct V_220 * V_221 , int V_222 , void T_6 * V_130 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_98 ( F_103 ( V_221 ) , V_130 , V_8 ) ;
break;
case V_227 :
V_10 = F_90 ( F_103 ( V_221 ) , V_130 , V_8 , 1 ) ;
break;
default:
F_11 ( L_57 , V_222 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
static int F_104 ( struct V_77 * V_78 , void T_6 * * V_208 ,
T_7 * V_133 ,
struct V_108 * V_110 ,
unsigned int V_9 )
{
struct V_76 * V_107 ;
struct V_179 T_6 * V_228 ;
T_8 V_129 , V_82 ;
T_7 V_210 ;
int V_10 ;
V_210 = * V_133 ;
V_228 = (struct V_179 T_6 * ) * V_208 ;
if ( F_62 ( V_228 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_62 ( & V_228 -> V_110 , & V_110 [ V_9 ] ,
sizeof( V_110 [ V_9 ] ) ) != 0 )
return - V_173 ;
* V_208 += sizeof( struct V_179 ) ;
* V_133 -= sizeof( struct V_77 ) - sizeof( struct V_179 ) ;
V_129 = V_78 -> V_129 - ( V_210 - * V_133 ) ;
V_107 = F_15 ( V_78 ) ;
V_10 = F_105 ( V_107 , V_208 , V_133 ) ;
if ( V_10 )
return V_10 ;
V_82 = V_78 -> V_82 - ( V_210 - * V_133 ) ;
if ( F_106 ( V_129 , & V_228 -> V_129 ) != 0 ||
F_106 ( V_82 , & V_228 -> V_82 ) != 0 )
return - V_173 ;
return 0 ;
}
static int F_107 ( unsigned int V_168 ,
struct V_1 * V_86 ,
void T_6 * V_169 )
{
struct V_108 * V_110 ;
const struct V_94 * V_95 = V_86 -> V_95 ;
void T_6 * V_125 ;
unsigned int V_133 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_156 ;
V_110 = F_58 ( V_86 ) ;
if ( F_41 ( V_110 ) )
return F_42 ( V_110 ) ;
V_125 = V_169 ;
V_133 = V_168 ;
F_51 (iter, private->entries, total_size) {
V_10 = F_104 ( V_156 , & V_125 ,
& V_133 , V_110 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_64 ( V_110 ) ;
return V_10 ;
}
static int F_108 ( struct V_181 * V_181 ,
struct V_229 T_6 * V_187 ,
int * V_8 )
{
int V_10 ;
struct V_229 V_188 ;
struct V_1 * V_107 ;
if ( * V_8 < sizeof( V_188 ) ) {
F_11 ( L_58 , * V_8 , sizeof( V_188 ) ) ;
return - V_137 ;
}
if ( F_74 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_173 ;
if ( * V_8 != sizeof( struct V_229 ) + V_188 . V_133 ) {
F_11 ( L_59 ,
* V_8 , sizeof( V_188 ) + V_188 . V_133 ) ;
return - V_137 ;
}
F_76 ( V_105 ) ;
V_107 = F_78 ( V_181 , V_105 , V_188 . V_99 ) ;
if ( ! F_79 ( V_107 ) ) {
const struct V_94 * V_95 = V_107 -> V_95 ;
struct V_94 V_2 ;
F_11 ( L_45 , V_95 -> V_157 ) ;
V_10 = F_71 ( V_95 , & V_2 ) ;
if ( ! V_10 && V_188 . V_133 == V_2 . V_133 ) {
V_10 = F_107 ( V_95 -> V_133 ,
V_107 , V_187 -> V_189 ) ;
} else if ( ! V_10 ) {
F_11 ( L_60 ,
V_95 -> V_133 , V_188 . V_133 ) ;
V_10 = - V_190 ;
}
F_80 ( V_105 ) ;
F_43 ( V_107 -> V_146 ) ;
F_81 ( V_107 ) ;
} else
V_10 = V_107 ? F_42 ( V_107 ) : - V_185 ;
F_82 ( V_105 ) ;
return V_10 ;
}
static int F_109 ( struct V_220 * V_221 , int V_222 , void T_6 * V_130 ,
int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_73 ( F_103 ( V_221 ) , V_130 , V_8 , 1 ) ;
break;
case V_231 :
V_10 = F_108 ( F_103 ( V_221 ) , V_130 , V_8 ) ;
break;
default:
V_10 = F_110 ( V_221 , V_222 , V_130 , V_8 ) ;
}
return V_10 ;
}
static int F_111 ( struct V_220 * V_221 , int V_222 , void T_6 * V_130 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_88 ( F_103 ( V_221 ) , V_130 , V_8 ) ;
break;
case V_227 :
V_10 = F_90 ( F_103 ( V_221 ) , V_130 , V_8 , 0 ) ;
break;
default:
F_11 ( L_57 , V_222 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
static int F_110 ( struct V_220 * V_221 , int V_222 , void T_6 * V_130 , int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_73 ( F_103 ( V_221 ) , V_130 , V_8 , 0 ) ;
break;
case V_231 :
V_10 = F_83 ( F_103 ( V_221 ) , V_130 , V_8 ) ;
break;
case V_232 : {
struct V_233 V_234 ;
if ( * V_8 != sizeof( V_234 ) ) {
V_10 = - V_137 ;
break;
}
if ( F_74 ( & V_234 , V_130 , sizeof( V_234 ) ) != 0 ) {
V_10 = - V_173 ;
break;
}
V_234 . V_99 [ sizeof( V_234 . V_99 ) - 1 ] = 0 ;
F_77 ( F_112 ( V_105 , V_234 . V_99 ,
V_234 . V_144 , 1 , & V_10 ) ,
L_61 , V_234 . V_99 ) ;
break;
}
default:
F_11 ( L_62 , V_222 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
struct V_1 * F_113 ( struct V_181 * V_181 ,
const struct V_1 * V_86 ,
const struct V_154 * V_155 )
{
int V_10 ;
struct V_94 * V_121 ;
struct V_94 V_235 = { 0 } ;
void * V_172 ;
struct V_1 * V_236 ;
V_121 = F_89 ( V_155 -> V_133 ) ;
if ( ! V_121 ) {
V_10 = - V_143 ;
goto V_100;
}
V_172 = V_121 -> V_101 ;
memcpy ( V_172 , V_155 -> V_101 , V_155 -> V_133 ) ;
V_10 = F_50 ( V_121 , V_172 , V_155 ) ;
F_11 ( L_63 , V_10 ) ;
if ( V_10 != 0 )
goto V_237;
V_236 = F_114 ( V_181 , V_86 , & V_235 , V_121 ) ;
if ( F_41 ( V_236 ) ) {
V_10 = F_42 ( V_236 ) ;
goto V_237;
}
return V_236 ;
V_237:
F_86 ( V_121 ) ;
V_100:
return F_60 ( V_10 ) ;
}
void F_115 ( struct V_1 * V_86 )
{
struct V_94 * V_95 ;
void * V_172 ;
struct V_238 * V_239 = V_86 -> V_146 ;
struct V_77 * V_156 ;
V_95 = F_116 ( V_86 ) ;
V_172 = V_95 -> V_101 ;
F_51 (iter, loc_cpu_entry, private->size)
F_49 ( V_156 ) ;
if ( V_95 -> V_157 > V_95 -> V_180 )
F_43 ( V_239 ) ;
F_86 ( V_95 ) ;
}
static int T_9 F_117 ( struct V_181 * V_181 )
{
return F_118 ( V_181 , V_105 ) ;
}
static void T_10 F_119 ( struct V_181 * V_181 )
{
F_120 ( V_181 , V_105 ) ;
}
static int T_11 F_121 ( void )
{
int V_10 ;
V_10 = F_122 ( & V_240 ) ;
if ( V_10 < 0 )
goto V_241;
V_10 = F_123 ( V_242 , F_124 ( V_242 ) ) ;
if ( V_10 < 0 )
goto V_243;
V_10 = F_125 ( & V_244 ) ;
if ( V_10 < 0 )
goto V_245;
F_126 ( V_246 L_64 ) ;
return 0 ;
V_245:
F_127 ( V_242 , F_124 ( V_242 ) ) ;
V_243:
F_128 ( & V_240 ) ;
V_241:
return V_10 ;
}
static void T_12 F_129 ( void )
{
F_130 ( & V_244 ) ;
F_127 ( V_242 , F_124 ( V_242 ) ) ;
F_128 ( & V_240 ) ;
}
