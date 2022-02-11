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
const struct V_83 * V_84 ,
struct V_1 * V_85 )
{
unsigned int V_86 = V_84 -> V_86 ;
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
V_23 = V_84 -> V_98 ? V_84 -> V_98 -> V_99 : V_87 ;
V_24 = V_84 -> V_100 ? V_84 -> V_100 -> V_99 : V_87 ;
F_22 () ;
V_97 = F_23 () ;
V_95 = V_85 -> V_95 ;
V_92 = F_24 () ;
F_25 () ;
V_91 = V_95 -> V_101 ;
V_90 = (struct V_77 * * ) V_95 -> V_90 [ V_92 ] ;
V_78 = F_16 ( V_91 , V_95 -> V_102 [ V_86 ] ) ;
V_96 . V_103 = V_84 -> V_103 ;
V_96 . V_98 = V_84 -> V_98 ;
V_96 . V_100 = V_84 -> V_100 ;
V_96 . V_104 = V_86 ;
V_96 . V_105 = V_106 ;
V_96 . V_107 = false ;
V_66 = F_26 ( V_71 ) ;
do {
const struct V_76 * V_108 ;
struct V_109 * V_110 ;
if ( ! F_7 ( V_66 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_66 ) ) {
V_78 = F_17 ( V_78 ) ;
continue;
}
V_110 = F_27 ( & V_78 -> V_111 ) ;
F_28 ( * V_110 , F_21 ( V_71 -> V_22 ) , 1 ) ;
V_108 = F_14 ( V_78 ) ;
if ( ! V_108 -> V_112 . V_113 . V_114 -> V_114 ) {
int V_115 ;
V_115 = ( (struct V_116 * ) V_108 ) -> V_89 ;
if ( V_115 < 0 ) {
if ( V_115 != V_117 ) {
V_89 = ( unsigned int ) ( - V_115 ) - 1 ;
break;
}
if ( V_93 == 0 ) {
V_78 = F_16 ( V_91 ,
V_95 -> V_118 [ V_86 ] ) ;
} else {
V_78 = V_90 [ -- V_93 ] ;
V_78 = F_17 ( V_78 ) ;
}
continue;
}
if ( V_91 + V_115
!= F_17 ( V_78 ) ) {
V_90 [ V_93 ++ ] = V_78 ;
}
V_78 = F_16 ( V_91 , V_115 ) ;
continue;
}
V_96 . V_114 = V_108 -> V_112 . V_113 . V_114 ;
V_96 . V_74 = V_108 -> V_119 ;
V_89 = V_108 -> V_112 . V_113 . V_114 -> V_114 ( V_71 , & V_96 ) ;
V_66 = F_26 ( V_71 ) ;
if ( V_89 == V_120 )
V_78 = F_17 ( V_78 ) ;
else
break;
} while ( ! V_96 . V_107 );
F_29 ( V_97 ) ;
F_30 () ;
if ( V_96 . V_107 )
return V_75 ;
else
return V_89 ;
}
static inline bool F_31 ( const struct V_25 * V_66 )
{
static const struct V_25 V_121 ;
return memcmp ( V_66 , & V_121 , sizeof( V_121 ) ) == 0 ;
}
static int F_32 ( const struct V_94 * V_122 ,
unsigned int V_123 , void * V_124 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_125 ; V_86 ++ ) {
unsigned int V_126 = V_122 -> V_102 [ V_86 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_124 + V_126 ) ;
if ( ! ( V_123 & ( 1 << V_86 ) ) )
continue;
V_78 -> V_111 . V_127 = V_126 ;
for (; ; ) {
const struct V_116 * V_108
= ( void * ) F_14 ( V_78 ) ;
int V_128 = V_78 -> V_129 & ( 1 << V_86 ) ;
if ( V_78 -> V_129 & ( 1 << V_125 ) ) {
F_33 ( L_20 ,
V_86 , V_126 , V_78 -> V_129 ) ;
return 0 ;
}
V_78 -> V_129
|= ( ( 1 << V_86 ) | ( 1 << V_125 ) ) ;
if ( ( V_78 -> V_130 == sizeof( struct V_77 ) &&
( strcmp ( V_108 -> V_114 . V_112 . V_131 . V_99 ,
V_132 ) == 0 ) &&
V_108 -> V_89 < 0 && F_31 ( & V_78 -> V_66 ) ) ||
V_128 ) {
unsigned int V_133 , V_134 ;
if ( ( strcmp ( V_108 -> V_114 . V_112 . V_131 . V_99 ,
V_132 ) == 0 ) &&
V_108 -> V_89 < - V_135 - 1 ) {
F_11 ( L_21
L_22 ,
V_108 -> V_89 ) ;
return 0 ;
}
do {
V_78 -> V_129 ^= ( 1 << V_125 ) ;
V_133 = V_126 ;
V_126 = V_78 -> V_111 . V_127 ;
V_78 -> V_111 . V_127 = 0 ;
if ( V_126 == V_133 )
goto V_136;
V_78 = (struct V_77 * )
( V_124 + V_126 ) ;
} while ( V_133 == V_126 + V_78 -> V_82 );
V_134 = V_78 -> V_82 ;
V_78 = (struct V_77 * )
( V_124 + V_126 + V_134 ) ;
V_78 -> V_111 . V_127 = V_126 ;
V_126 += V_134 ;
} else {
int V_137 = V_108 -> V_89 ;
if ( strcmp ( V_108 -> V_114 . V_112 . V_131 . V_99 ,
V_132 ) == 0 &&
V_137 >= 0 ) {
if ( V_137 > V_122 -> V_134 -
sizeof( struct V_77 ) ) {
F_11 ( L_23
L_24 ,
V_137 ) ;
return 0 ;
}
F_11 ( L_25 ,
V_126 , V_137 ) ;
} else {
V_137 = V_126 + V_78 -> V_82 ;
}
V_78 = (struct V_77 * )
( V_124 + V_137 ) ;
V_78 -> V_111 . V_127 = V_126 ;
V_126 = V_137 ;
}
}
V_136:
F_11 ( L_26 , V_86 ) ;
}
return 1 ;
}
static inline int F_34 ( const struct V_77 * V_78 , const char * V_99 )
{
const struct V_76 * V_108 ;
if ( ! F_10 ( & V_78 -> V_66 ) ) {
F_11 ( L_27 , V_78 , V_99 ) ;
return - V_138 ;
}
if ( V_78 -> V_130 + sizeof( struct V_76 ) > V_78 -> V_82 )
return - V_138 ;
V_108 = F_14 ( V_78 ) ;
if ( V_78 -> V_130 + V_108 -> V_112 . V_139 > V_78 -> V_82 )
return - V_138 ;
return 0 ;
}
static inline int F_35 ( struct V_77 * V_78 , const char * V_99 )
{
struct V_76 * V_108 = F_15 ( V_78 ) ;
int V_10 ;
struct V_140 V_73 = {
. V_85 = V_99 ,
. V_141 = V_78 ,
. V_114 = V_108 -> V_112 . V_113 . V_114 ,
. V_74 = V_108 -> V_119 ,
. V_142 = V_78 -> V_129 ,
. V_105 = V_106 ,
} ;
V_10 = F_36 ( & V_73 , V_108 -> V_112 . V_139 - sizeof( * V_108 ) , 0 , false ) ;
if ( V_10 < 0 ) {
F_11 ( L_28 ,
V_108 -> V_112 . V_113 . V_114 -> V_99 ) ;
return V_10 ;
}
return 0 ;
}
static inline int
F_37 ( struct V_77 * V_78 , const char * V_99 , unsigned int V_134 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
int V_10 ;
V_10 = F_34 ( V_78 , V_99 ) ;
if ( V_10 )
return V_10 ;
V_78 -> V_111 . V_127 = F_38 () ;
if ( F_39 ( V_78 -> V_111 . V_127 ) )
return - V_144 ;
V_108 = F_15 ( V_78 ) ;
V_114 = F_40 ( V_106 , V_108 -> V_112 . V_131 . V_99 ,
V_108 -> V_112 . V_131 . V_145 ) ;
if ( F_41 ( V_114 ) ) {
F_11 ( L_29 , V_108 -> V_112 . V_131 . V_99 ) ;
V_10 = F_42 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_10 = F_35 ( V_78 , V_99 ) ;
if ( V_10 )
goto V_146;
return 0 ;
V_146:
F_43 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
V_100:
F_44 ( V_78 -> V_111 . V_127 ) ;
return V_10 ;
}
static bool F_45 ( const struct V_77 * V_78 )
{
const struct V_76 * V_108 ;
unsigned int V_89 ;
if ( ! F_31 ( & V_78 -> V_66 ) )
return false ;
V_108 = F_14 ( V_78 ) ;
if ( strcmp ( V_108 -> V_112 . V_131 . V_99 , V_132 ) != 0 )
return false ;
V_89 = ( (struct V_116 * ) V_108 ) -> V_89 ;
V_89 = - V_89 - 1 ;
return V_89 == V_75 || V_89 == V_148 ;
}
static inline int F_46 ( struct V_77 * V_78 ,
struct V_94 * V_122 ,
const unsigned char * V_79 ,
const unsigned char * V_149 ,
const unsigned int * V_150 ,
const unsigned int * V_151 ,
unsigned int V_123 )
{
unsigned int V_152 ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_149 ) {
F_11 ( L_30 , V_78 ) ;
return - V_138 ;
}
if ( V_78 -> V_82
< sizeof( struct V_77 ) + sizeof( struct V_76 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_82 ) ;
return - V_138 ;
}
for ( V_152 = 0 ; V_152 < V_125 ; V_152 ++ ) {
if ( ! ( V_123 & ( 1 << V_152 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_152 ] )
V_122 -> V_102 [ V_152 ] = V_150 [ V_152 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_151 [ V_152 ] ) {
if ( ! F_45 ( V_78 ) ) {
F_48 ( L_32
L_33
L_34 ) ;
return - V_138 ;
}
V_122 -> V_118 [ V_152 ] = V_151 [ V_152 ] ;
}
}
V_78 -> V_111 = ( (struct V_109 ) { 0 , 0 } ) ;
V_78 -> V_129 = 0 ;
return 0 ;
}
static inline void F_49 ( struct V_77 * V_78 )
{
struct V_153 V_73 ;
struct V_76 * V_108 ;
V_108 = F_15 ( V_78 ) ;
V_73 . V_114 = V_108 -> V_112 . V_113 . V_114 ;
V_73 . V_74 = V_108 -> V_119 ;
V_73 . V_105 = V_106 ;
if ( V_73 . V_114 -> V_154 != NULL )
V_73 . V_114 -> V_154 ( & V_73 ) ;
F_43 ( V_73 . V_114 -> V_147 ) ;
F_44 ( V_78 -> V_111 . V_127 ) ;
}
static int F_50 ( struct V_94 * V_122 , void * V_124 ,
const struct V_155 * V_156 )
{
struct V_77 * V_157 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_122 -> V_134 = V_156 -> V_134 ;
V_122 -> V_158 = V_156 -> V_159 ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
V_122 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_122 -> V_118 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_35 , V_122 -> V_134 ) ;
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_46 ( V_157 , V_122 , V_124 ,
V_124 + V_156 -> V_134 ,
V_156 -> V_102 ,
V_156 -> V_118 ,
V_156 -> V_123 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_157 ) -> V_112 . V_131 . V_99 ,
V_160 ) == 0 )
++ V_122 -> V_161 ;
}
F_11 ( L_36 , V_10 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_156 -> V_159 ) {
F_11 ( L_37 ,
V_9 , V_156 -> V_159 ) ;
return - V_138 ;
}
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
if ( ! ( V_156 -> V_123 & ( 1 << V_9 ) ) )
continue;
if ( V_122 -> V_102 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_156 -> V_102 [ V_9 ] ) ;
return - V_138 ;
}
if ( V_122 -> V_118 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_156 -> V_118 [ V_9 ] ) ;
return - V_138 ;
}
}
if ( ! F_32 ( V_122 , V_156 -> V_123 , V_124 ) ) {
F_11 ( L_40 ) ;
return - V_162 ;
}
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_37 ( V_157 , V_156 -> V_99 , V_156 -> V_134 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_51 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_49 ( V_157 ) ;
}
return V_10 ;
}
return V_10 ;
}
static void F_52 ( const struct V_94 * V_108 ,
struct V_109 V_111 [] )
{
struct V_77 * V_157 ;
unsigned int V_92 ;
unsigned int V_9 ;
F_53 (cpu) {
T_4 * V_163 = & F_54 ( V_164 , V_92 ) ;
V_9 = 0 ;
F_51 (iter, t->entries, t->size) {
struct V_109 * V_165 ;
T_5 V_166 , V_127 ;
unsigned int V_167 ;
V_165 = F_55 ( & V_157 -> V_111 , V_92 ) ;
do {
V_167 = F_56 ( V_163 ) ;
V_166 = V_165 -> V_166 ;
V_127 = V_165 -> V_127 ;
} while ( F_57 ( V_163 , V_167 ) );
F_28 ( V_111 [ V_9 ] , V_166 , V_127 ) ;
++ V_9 ;
}
}
}
static struct V_109 * F_58 ( const struct V_1 * V_85 )
{
unsigned int V_168 ;
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
V_168 = sizeof( struct V_109 ) * V_95 -> V_158 ;
V_111 = F_59 ( V_168 ) ;
if ( V_111 == NULL )
return F_60 ( - V_144 ) ;
F_52 ( V_95 , V_111 ) ;
return V_111 ;
}
static int F_61 ( unsigned int V_169 ,
const struct V_1 * V_85 ,
void T_6 * V_170 )
{
unsigned int V_171 , V_172 ;
const struct V_77 * V_78 ;
struct V_109 * V_111 ;
struct V_94 * V_95 = V_85 -> V_95 ;
int V_10 = 0 ;
void * V_173 ;
V_111 = F_58 ( V_85 ) ;
if ( F_41 ( V_111 ) )
return F_42 ( V_111 ) ;
V_173 = V_95 -> V_101 ;
if ( F_62 ( V_170 , V_173 , V_169 ) != 0 ) {
V_10 = - V_174 ;
goto V_175;
}
for ( V_171 = 0 , V_172 = 0 ; V_171 < V_169 ; V_171 += V_78 -> V_82 , V_172 ++ ) {
const struct V_76 * V_108 ;
V_78 = (struct V_77 * ) ( V_173 + V_171 ) ;
if ( F_62 ( V_170 + V_171
+ F_63 ( struct V_77 , V_111 ) ,
& V_111 [ V_172 ] ,
sizeof( V_111 [ V_172 ] ) ) != 0 ) {
V_10 = - V_174 ;
goto V_175;
}
V_108 = F_14 ( V_78 ) ;
if ( F_62 ( V_170 + V_171 + V_78 -> V_130
+ F_63 ( struct V_76 ,
V_112 . V_131 . V_99 ) ,
V_108 -> V_112 . V_113 . V_114 -> V_99 ,
strlen ( V_108 -> V_112 . V_113 . V_114 -> V_99 ) + 1 ) != 0 ) {
V_10 = - V_174 ;
goto V_175;
}
}
V_175:
F_64 ( V_111 ) ;
return V_10 ;
}
static void F_65 ( void * V_176 , const void * V_54 )
{
int V_115 = * ( V_177 * ) V_54 ;
if ( V_115 > 0 )
V_115 += F_66 ( V_106 , V_115 ) ;
memcpy ( V_176 , & V_115 , sizeof( V_115 ) ) ;
}
static int F_67 ( void T_6 * V_176 , const void * V_54 )
{
V_177 V_178 = * ( int * ) V_54 ;
if ( V_178 > 0 )
V_178 -= F_66 ( V_106 , V_178 ) ;
return F_62 ( V_176 , & V_178 , sizeof( V_178 ) ) ? - V_174 : 0 ;
}
static int F_68 ( const struct V_77 * V_78 ,
const struct V_94 * V_2 ,
const void * V_79 , struct V_94 * V_122 )
{
const struct V_76 * V_108 ;
unsigned int V_179 ;
int V_171 , V_9 , V_10 ;
V_171 = sizeof( struct V_77 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_78 - V_79 ;
V_108 = F_14 ( V_78 ) ;
V_171 += F_69 ( V_108 -> V_112 . V_113 . V_114 ) ;
V_122 -> V_134 -= V_171 ;
V_10 = F_70 ( V_106 , V_179 , V_171 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
if ( V_2 -> V_102 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_102 [ V_9 ] ) ) )
V_122 -> V_102 [ V_9 ] -= V_171 ;
if ( V_2 -> V_118 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_118 [ V_9 ] ) ) )
V_122 -> V_118 [ V_9 ] -= V_171 ;
}
return 0 ;
}
static int F_71 ( const struct V_94 * V_2 ,
struct V_94 * V_122 )
{
struct V_77 * V_157 ;
const void * V_173 ;
int V_10 ;
if ( ! V_122 || ! V_2 )
return - V_138 ;
memcpy ( V_122 , V_2 , F_63 ( struct V_94 , V_101 ) ) ;
V_122 -> V_181 = 0 ;
V_173 = V_2 -> V_101 ;
F_72 ( V_106 , V_2 -> V_158 ) ;
F_51 (iter, loc_cpu_entry, info->size) {
V_10 = F_68 ( V_157 , V_2 , V_173 , V_122 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_73 ( struct V_103 * V_103 , void T_6 * V_131 ,
const int * V_8 , int V_182 )
{
char V_99 [ V_183 ] ;
struct V_1 * V_108 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_184 ) ) {
F_11 ( L_41 , * V_8 ,
sizeof( struct V_184 ) ) ;
return - V_138 ;
}
if ( F_74 ( V_99 , V_131 , sizeof( V_99 ) ) != 0 )
return - V_174 ;
V_99 [ V_183 - 1 ] = '\0' ;
#ifdef F_75
if ( V_182 )
F_76 ( V_106 ) ;
#endif
V_108 = F_77 ( F_78 ( V_103 , V_106 , V_99 ) ,
L_42 , V_99 ) ;
if ( ! F_79 ( V_108 ) ) {
struct V_184 V_2 ;
const struct V_94 * V_95 = V_108 -> V_95 ;
#ifdef F_75
struct V_94 V_165 ;
if ( V_182 ) {
V_10 = F_71 ( V_95 , & V_165 ) ;
F_80 ( V_106 ) ;
V_95 = & V_165 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_123 = V_108 -> V_123 ;
memcpy ( V_2 . V_102 , V_95 -> V_102 ,
sizeof( V_2 . V_102 ) ) ;
memcpy ( V_2 . V_118 , V_95 -> V_118 ,
sizeof( V_2 . V_118 ) ) ;
V_2 . V_159 = V_95 -> V_158 ;
V_2 . V_134 = V_95 -> V_134 ;
strcpy ( V_2 . V_99 , V_99 ) ;
if ( F_62 ( V_131 , & V_2 , * V_8 ) != 0 )
V_10 = - V_174 ;
else
V_10 = 0 ;
F_81 ( V_108 ) ;
F_43 ( V_108 -> V_147 ) ;
} else
V_10 = V_108 ? F_42 ( V_108 ) : - V_185 ;
#ifdef F_75
if ( V_182 )
F_82 ( V_106 ) ;
#endif
return V_10 ;
}
static int F_83 ( struct V_103 * V_103 , struct V_186 T_6 * V_187 ,
const int * V_8 )
{
int V_10 ;
struct V_186 V_188 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_188 ) ) {
F_11 ( L_43 , * V_8 , sizeof( V_188 ) ) ;
return - V_138 ;
}
if ( F_74 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_174 ;
if ( * V_8 != sizeof( struct V_186 ) + V_188 . V_134 ) {
F_11 ( L_44 , * V_8 ,
sizeof( struct V_186 ) + V_188 . V_134 ) ;
return - V_138 ;
}
V_108 = F_78 ( V_103 , V_106 , V_188 . V_99 ) ;
if ( ! F_79 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
F_11 ( L_45 ,
V_95 -> V_158 ) ;
if ( V_188 . V_134 == V_95 -> V_134 )
V_10 = F_61 ( V_95 -> V_134 ,
V_108 , V_187 -> V_189 ) ;
else {
F_11 ( L_46 ,
V_95 -> V_134 , V_188 . V_134 ) ;
V_10 = - V_190 ;
}
F_43 ( V_108 -> V_147 ) ;
F_81 ( V_108 ) ;
} else
V_10 = V_108 ? F_42 ( V_108 ) : - V_185 ;
return V_10 ;
}
static int F_84 ( struct V_103 * V_103 , const char * V_99 ,
unsigned int V_123 ,
struct V_94 * V_122 ,
unsigned int V_191 ,
void T_6 * V_192 )
{
int V_10 ;
struct V_1 * V_108 ;
struct V_94 * V_193 ;
struct V_109 * V_111 ;
void * V_194 ;
struct V_77 * V_157 ;
V_10 = 0 ;
V_111 = F_59 ( V_191 * sizeof( struct V_109 ) ) ;
if ( ! V_111 ) {
V_10 = - V_144 ;
goto V_100;
}
V_108 = F_77 ( F_78 ( V_103 , V_106 , V_99 ) ,
L_42 , V_99 ) ;
if ( F_79 ( V_108 ) ) {
V_10 = V_108 ? F_42 ( V_108 ) : - V_185 ;
goto V_195;
}
if ( V_123 != V_108 -> V_123 ) {
F_11 ( L_47 ,
V_123 , V_108 -> V_123 ) ;
V_10 = - V_138 ;
goto V_196;
}
V_193 = F_85 ( V_108 , V_191 , V_122 , & V_10 ) ;
if ( ! V_193 )
goto V_196;
F_11 ( L_48 ,
V_193 -> V_158 , V_193 -> V_181 , V_122 -> V_158 ) ;
if ( ( V_193 -> V_158 > V_193 -> V_181 ) ||
( V_122 -> V_158 <= V_193 -> V_181 ) )
F_43 ( V_108 -> V_147 ) ;
if ( ( V_193 -> V_158 > V_193 -> V_181 ) &&
( V_122 -> V_158 <= V_193 -> V_181 ) )
F_43 ( V_108 -> V_147 ) ;
F_52 ( V_193 , V_111 ) ;
V_194 = V_193 -> V_101 ;
F_51 (iter, loc_cpu_old_entry, oldinfo->size)
F_49 ( V_157 ) ;
F_86 ( V_193 ) ;
if ( F_62 ( V_192 , V_111 ,
sizeof( struct V_109 ) * V_191 ) != 0 ) {
F_87 ( L_49 ) ;
}
F_64 ( V_111 ) ;
F_81 ( V_108 ) ;
return V_10 ;
V_196:
F_43 ( V_108 -> V_147 ) ;
F_81 ( V_108 ) ;
V_195:
F_64 ( V_111 ) ;
V_100:
return V_10 ;
}
static int F_88 ( struct V_103 * V_103 , const void T_6 * V_131 ,
unsigned int V_8 )
{
int V_10 ;
struct V_155 V_165 ;
struct V_94 * V_122 ;
void * V_173 ;
struct V_77 * V_157 ;
if ( F_74 ( & V_165 , V_131 , sizeof( V_165 ) ) != 0 )
return - V_174 ;
if ( V_165 . V_191 >= V_197 / sizeof( struct V_109 ) )
return - V_144 ;
if ( V_165 . V_191 == 0 )
return - V_138 ;
V_165 . V_99 [ sizeof( V_165 . V_99 ) - 1 ] = 0 ;
V_122 = F_89 ( V_165 . V_134 ) ;
if ( ! V_122 )
return - V_144 ;
V_173 = V_122 -> V_101 ;
if ( F_74 ( V_173 , V_131 + sizeof( V_165 ) ,
V_165 . V_134 ) != 0 ) {
V_10 = - V_174 ;
goto V_198;
}
V_10 = F_50 ( V_122 , V_173 , & V_165 ) ;
if ( V_10 != 0 )
goto V_198;
F_11 ( L_50 ) ;
V_10 = F_84 ( V_103 , V_165 . V_99 , V_165 . V_123 , V_122 ,
V_165 . V_191 , V_165 . V_111 ) ;
if ( V_10 )
goto V_199;
return 0 ;
V_199:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_157 ) ;
V_198:
F_86 ( V_122 ) ;
return V_10 ;
}
static int F_90 ( struct V_103 * V_103 , const void T_6 * V_131 ,
unsigned int V_8 , int V_182 )
{
unsigned int V_9 ;
struct V_200 V_165 ;
struct V_109 * V_201 ;
unsigned int V_191 ;
const char * V_99 ;
int V_134 ;
void * V_202 ;
struct V_1 * V_108 ;
const struct V_94 * V_95 ;
int V_10 = 0 ;
struct V_77 * V_157 ;
unsigned int V_97 ;
#ifdef F_75
struct V_203 V_204 ;
if ( V_182 ) {
V_202 = & V_204 ;
V_134 = sizeof( struct V_203 ) ;
} else
#endif
{
V_202 = & V_165 ;
V_134 = sizeof( struct V_200 ) ;
}
if ( F_74 ( V_202 , V_131 , V_134 ) != 0 )
return - V_174 ;
#ifdef F_75
if ( V_182 ) {
V_191 = V_204 . V_191 ;
V_99 = V_204 . V_99 ;
} else
#endif
{
V_191 = V_165 . V_191 ;
V_99 = V_165 . V_99 ;
}
if ( V_8 != V_134 + V_191 * sizeof( struct V_109 ) )
return - V_138 ;
V_201 = F_91 ( V_8 - V_134 ) ;
if ( ! V_201 )
return - V_144 ;
if ( F_74 ( V_201 , V_131 + V_134 , V_8 - V_134 ) != 0 ) {
V_10 = - V_174 ;
goto free;
}
V_108 = F_78 ( V_103 , V_106 , V_99 ) ;
if ( F_79 ( V_108 ) ) {
V_10 = V_108 ? F_42 ( V_108 ) : - V_185 ;
goto free;
}
F_22 () ;
V_95 = V_108 -> V_95 ;
if ( V_95 -> V_158 != V_191 ) {
V_10 = - V_138 ;
goto V_205;
}
V_9 = 0 ;
V_97 = F_23 () ;
F_51 (iter, private->entries, private->size) {
struct V_109 * V_165 ;
V_165 = F_27 ( & V_157 -> V_111 ) ;
F_28 ( * V_165 , V_201 [ V_9 ] . V_166 , V_201 [ V_9 ] . V_127 ) ;
++ V_9 ;
}
F_29 ( V_97 ) ;
V_205:
F_30 () ;
F_81 ( V_108 ) ;
F_43 ( V_108 -> V_147 ) ;
free:
F_64 ( V_201 ) ;
return V_10 ;
}
static inline void F_92 ( struct V_180 * V_78 )
{
struct V_76 * V_108 ;
V_108 = F_93 ( V_78 ) ;
F_43 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
}
static inline int
F_94 ( struct V_180 * V_78 ,
struct V_94 * V_122 ,
unsigned int * V_134 ,
const unsigned char * V_79 ,
const unsigned char * V_149 ,
const unsigned int * V_150 ,
const unsigned int * V_151 ,
const char * V_99 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
unsigned int V_179 ;
int V_10 , V_171 , V_152 ;
F_11 ( L_51 , V_78 ) ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_180 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_180 ) >= V_149 ) {
F_11 ( L_52 , V_78 , V_149 ) ;
return - V_138 ;
}
if ( V_78 -> V_82 < sizeof( struct V_180 ) +
sizeof( struct V_206 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_82 ) ;
return - V_138 ;
}
V_10 = F_34 ( (struct V_77 * ) V_78 , V_99 ) ;
if ( V_10 )
return V_10 ;
V_171 = sizeof( struct V_77 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_78 - ( void * ) V_79 ;
V_108 = F_93 ( V_78 ) ;
V_114 = F_40 ( V_106 , V_108 -> V_112 . V_131 . V_99 ,
V_108 -> V_112 . V_131 . V_145 ) ;
if ( F_41 ( V_114 ) ) {
F_11 ( L_53 ,
V_108 -> V_112 . V_131 . V_99 ) ;
V_10 = F_42 ( V_114 ) ;
goto V_100;
}
V_108 -> V_112 . V_113 . V_114 = V_114 ;
V_171 += F_69 ( V_114 ) ;
* V_134 += V_171 ;
V_10 = F_70 ( V_106 , V_179 , V_171 ) ;
if ( V_10 )
goto V_207;
for ( V_152 = 0 ; V_152 < V_125 ; V_152 ++ ) {
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_152 ] )
V_122 -> V_102 [ V_152 ] = V_150 [ V_152 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_151 [ V_152 ] )
V_122 -> V_118 [ V_152 ] = V_151 [ V_152 ] ;
}
memset ( & V_78 -> V_111 , 0 , sizeof( V_78 -> V_111 ) ) ;
V_78 -> V_129 = 0 ;
return 0 ;
V_207:
F_43 ( V_108 -> V_112 . V_113 . V_114 -> V_147 ) ;
V_100:
return V_10 ;
}
static int
F_95 ( struct V_180 * V_78 , void * * V_208 ,
unsigned int * V_134 , const char * V_99 ,
struct V_94 * V_122 , unsigned char * V_79 )
{
struct V_76 * V_108 ;
struct V_143 * V_114 ;
struct V_77 * V_209 ;
unsigned int V_210 ;
int V_10 , V_152 ;
V_10 = 0 ;
V_210 = * V_134 ;
V_209 = (struct V_77 * ) * V_208 ;
memcpy ( V_209 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_209 -> V_111 , & V_78 -> V_111 , sizeof( V_78 -> V_111 ) ) ;
* V_208 += sizeof( struct V_77 ) ;
* V_134 += sizeof( struct V_77 ) - sizeof( struct V_180 ) ;
V_209 -> V_130 = V_78 -> V_130 - ( V_210 - * V_134 ) ;
V_108 = F_93 ( V_78 ) ;
V_114 = V_108 -> V_112 . V_113 . V_114 ;
F_96 ( V_108 , V_208 , V_134 ) ;
V_209 -> V_82 = V_78 -> V_82 - ( V_210 - * V_134 ) ;
for ( V_152 = 0 ; V_152 < V_125 ; V_152 ++ ) {
if ( ( unsigned char * ) V_209 - V_79 < V_122 -> V_102 [ V_152 ] )
V_122 -> V_102 [ V_152 ] -= V_210 - * V_134 ;
if ( ( unsigned char * ) V_209 - V_79 < V_122 -> V_118 [ V_152 ] )
V_122 -> V_118 [ V_152 ] -= V_210 - * V_134 ;
}
return V_10 ;
}
static int F_97 ( const char * V_99 ,
unsigned int V_123 ,
struct V_94 * * V_211 ,
void * * V_212 ,
unsigned int V_169 ,
unsigned int V_158 ,
unsigned int * V_150 ,
unsigned int * V_151 )
{
unsigned int V_9 , V_213 ;
struct V_94 * V_122 , * V_2 ;
void * V_126 , * V_124 , * V_214 ;
struct V_180 * V_215 ;
struct V_77 * V_216 ;
unsigned int V_134 ;
int V_10 = 0 ;
V_2 = * V_211 ;
V_124 = * V_212 ;
V_134 = V_169 ;
V_2 -> V_158 = V_158 ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
V_2 -> V_102 [ V_9 ] = 0xFFFFFFFF ;
V_2 -> V_118 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_54 , V_2 -> V_134 ) ;
V_213 = 0 ;
F_76 ( V_106 ) ;
F_72 ( V_106 , V_158 ) ;
F_51 (iter0, entry0, total_size) {
V_10 = F_94 ( V_215 , V_2 , & V_134 ,
V_124 ,
V_124 + V_169 ,
V_150 ,
V_151 ,
V_99 ) ;
if ( V_10 != 0 )
goto V_217;
++ V_213 ;
}
V_10 = - V_138 ;
if ( V_213 != V_158 ) {
F_11 ( L_55 ,
V_213 , V_158 ) ;
goto V_217;
}
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
if ( ! ( V_123 & ( 1 << V_9 ) ) )
continue;
if ( V_2 -> V_102 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_150 [ V_9 ] ) ;
goto V_217;
}
if ( V_2 -> V_118 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_151 [ V_9 ] ) ;
goto V_217;
}
}
V_10 = - V_144 ;
V_122 = F_89 ( V_134 ) ;
if ( ! V_122 )
goto V_217;
V_122 -> V_158 = V_158 ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
V_122 -> V_102 [ V_9 ] = V_2 -> V_102 [ V_9 ] ;
V_122 -> V_118 [ V_9 ] = V_2 -> V_118 [ V_9 ] ;
}
V_214 = V_122 -> V_101 ;
V_126 = V_214 ;
V_134 = V_169 ;
F_51 (iter0, entry0, total_size) {
V_10 = F_95 ( V_215 , & V_126 , & V_134 ,
V_99 , V_122 , V_214 ) ;
if ( V_10 != 0 )
break;
}
F_80 ( V_106 ) ;
F_82 ( V_106 ) ;
if ( V_10 )
goto V_198;
V_10 = - V_162 ;
if ( ! F_32 ( V_122 , V_123 , V_214 ) )
goto V_198;
V_9 = 0 ;
F_51 (iter1, entry1, newinfo->size) {
V_216 -> V_111 . V_127 = F_38 () ;
if ( F_39 ( V_216 -> V_111 . V_127 ) ) {
V_10 = - V_144 ;
break;
}
V_10 = F_35 ( V_216 , V_99 ) ;
if ( V_10 != 0 ) {
F_44 ( V_216 -> V_111 . V_127 ) ;
break;
}
++ V_9 ;
if ( strcmp ( F_15 ( V_216 ) -> V_112 . V_131 . V_99 ,
V_160 ) == 0 )
++ V_122 -> V_161 ;
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
F_86 ( V_122 ) ;
return V_10 ;
}
* V_211 = V_122 ;
* V_212 = V_214 ;
F_86 ( V_2 ) ;
return 0 ;
V_198:
F_86 ( V_122 ) ;
V_100:
F_51 (iter0, entry0, total_size) {
if ( V_213 -- == 0 )
break;
F_92 ( V_215 ) ;
}
return V_10 ;
V_217:
F_80 ( V_106 ) ;
F_82 ( V_106 ) ;
goto V_100;
}
static int F_98 ( struct V_103 * V_103 , void T_6 * V_131 ,
unsigned int V_8 )
{
int V_10 ;
struct V_219 V_165 ;
struct V_94 * V_122 ;
void * V_173 ;
struct V_77 * V_157 ;
if ( F_74 ( & V_165 , V_131 , sizeof( V_165 ) ) != 0 )
return - V_174 ;
if ( V_165 . V_134 >= V_197 / F_99 () )
return - V_144 ;
if ( V_165 . V_191 >= V_197 / sizeof( struct V_109 ) )
return - V_144 ;
if ( V_165 . V_191 == 0 )
return - V_138 ;
V_165 . V_99 [ sizeof( V_165 . V_99 ) - 1 ] = 0 ;
V_122 = F_89 ( V_165 . V_134 ) ;
if ( ! V_122 )
return - V_144 ;
V_173 = V_122 -> V_101 ;
if ( F_74 ( V_173 , V_131 + sizeof( V_165 ) , V_165 . V_134 ) != 0 ) {
V_10 = - V_174 ;
goto V_198;
}
V_10 = F_97 ( V_165 . V_99 , V_165 . V_123 ,
& V_122 , & V_173 , V_165 . V_134 ,
V_165 . V_159 , V_165 . V_102 ,
V_165 . V_118 ) ;
if ( V_10 != 0 )
goto V_198;
F_11 ( L_56 ) ;
V_10 = F_84 ( V_103 , V_165 . V_99 , V_165 . V_123 , V_122 ,
V_165 . V_191 , F_100 ( V_165 . V_111 ) ) ;
if ( V_10 )
goto V_199;
return 0 ;
V_199:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_157 ) ;
V_198:
F_86 ( V_122 ) ;
return V_10 ;
}
static int F_101 ( struct V_220 * V_221 , int V_222 , void T_6 * V_131 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_98 ( F_103 ( V_221 ) , V_131 , V_8 ) ;
break;
case V_227 :
V_10 = F_90 ( F_103 ( V_221 ) , V_131 , V_8 , 1 ) ;
break;
default:
F_11 ( L_57 , V_222 ) ;
V_10 = - V_138 ;
}
return V_10 ;
}
static int F_104 ( struct V_77 * V_78 , void T_6 * * V_208 ,
T_7 * V_134 ,
struct V_109 * V_111 ,
unsigned int V_9 )
{
struct V_76 * V_108 ;
struct V_180 T_6 * V_228 ;
T_8 V_130 , V_82 ;
T_7 V_210 ;
int V_10 ;
V_210 = * V_134 ;
V_228 = (struct V_180 T_6 * ) * V_208 ;
if ( F_62 ( V_228 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_62 ( & V_228 -> V_111 , & V_111 [ V_9 ] ,
sizeof( V_111 [ V_9 ] ) ) != 0 )
return - V_174 ;
* V_208 += sizeof( struct V_180 ) ;
* V_134 -= sizeof( struct V_77 ) - sizeof( struct V_180 ) ;
V_130 = V_78 -> V_130 - ( V_210 - * V_134 ) ;
V_108 = F_15 ( V_78 ) ;
V_10 = F_105 ( V_108 , V_208 , V_134 ) ;
if ( V_10 )
return V_10 ;
V_82 = V_78 -> V_82 - ( V_210 - * V_134 ) ;
if ( F_106 ( V_130 , & V_228 -> V_130 ) != 0 ||
F_106 ( V_82 , & V_228 -> V_82 ) != 0 )
return - V_174 ;
return 0 ;
}
static int F_107 ( unsigned int V_169 ,
struct V_1 * V_85 ,
void T_6 * V_170 )
{
struct V_109 * V_111 ;
const struct V_94 * V_95 = V_85 -> V_95 ;
void T_6 * V_126 ;
unsigned int V_134 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_157 ;
V_111 = F_58 ( V_85 ) ;
if ( F_41 ( V_111 ) )
return F_42 ( V_111 ) ;
V_126 = V_170 ;
V_134 = V_169 ;
F_51 (iter, private->entries, total_size) {
V_10 = F_104 ( V_157 , & V_126 ,
& V_134 , V_111 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_64 ( V_111 ) ;
return V_10 ;
}
static int F_108 ( struct V_103 * V_103 ,
struct V_229 T_6 * V_187 ,
int * V_8 )
{
int V_10 ;
struct V_229 V_188 ;
struct V_1 * V_108 ;
if ( * V_8 < sizeof( V_188 ) ) {
F_11 ( L_58 , * V_8 , sizeof( V_188 ) ) ;
return - V_138 ;
}
if ( F_74 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_174 ;
if ( * V_8 != sizeof( struct V_229 ) + V_188 . V_134 ) {
F_11 ( L_59 ,
* V_8 , sizeof( V_188 ) + V_188 . V_134 ) ;
return - V_138 ;
}
F_76 ( V_106 ) ;
V_108 = F_78 ( V_103 , V_106 , V_188 . V_99 ) ;
if ( ! F_79 ( V_108 ) ) {
const struct V_94 * V_95 = V_108 -> V_95 ;
struct V_94 V_2 ;
F_11 ( L_45 , V_95 -> V_158 ) ;
V_10 = F_71 ( V_95 , & V_2 ) ;
if ( ! V_10 && V_188 . V_134 == V_2 . V_134 ) {
V_10 = F_107 ( V_95 -> V_134 ,
V_108 , V_187 -> V_189 ) ;
} else if ( ! V_10 ) {
F_11 ( L_60 ,
V_95 -> V_134 , V_188 . V_134 ) ;
V_10 = - V_190 ;
}
F_80 ( V_106 ) ;
F_43 ( V_108 -> V_147 ) ;
F_81 ( V_108 ) ;
} else
V_10 = V_108 ? F_42 ( V_108 ) : - V_185 ;
F_82 ( V_106 ) ;
return V_10 ;
}
static int F_109 ( struct V_220 * V_221 , int V_222 , void T_6 * V_131 ,
int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_73 ( F_103 ( V_221 ) , V_131 , V_8 , 1 ) ;
break;
case V_231 :
V_10 = F_108 ( F_103 ( V_221 ) , V_131 , V_8 ) ;
break;
default:
V_10 = F_110 ( V_221 , V_222 , V_131 , V_8 ) ;
}
return V_10 ;
}
static int F_111 ( struct V_220 * V_221 , int V_222 , void T_6 * V_131 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_10 = F_88 ( F_103 ( V_221 ) , V_131 , V_8 ) ;
break;
case V_227 :
V_10 = F_90 ( F_103 ( V_221 ) , V_131 , V_8 , 0 ) ;
break;
default:
F_11 ( L_57 , V_222 ) ;
V_10 = - V_138 ;
}
return V_10 ;
}
static int F_110 ( struct V_220 * V_221 , int V_222 , void T_6 * V_131 , int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_230 :
V_10 = F_73 ( F_103 ( V_221 ) , V_131 , V_8 , 0 ) ;
break;
case V_231 :
V_10 = F_83 ( F_103 ( V_221 ) , V_131 , V_8 ) ;
break;
case V_232 : {
struct V_233 V_234 ;
if ( * V_8 != sizeof( V_234 ) ) {
V_10 = - V_138 ;
break;
}
if ( F_74 ( & V_234 , V_131 , sizeof( V_234 ) ) != 0 ) {
V_10 = - V_174 ;
break;
}
V_234 . V_99 [ sizeof( V_234 . V_99 ) - 1 ] = 0 ;
F_77 ( F_112 ( V_106 , V_234 . V_99 ,
V_234 . V_145 , 1 , & V_10 ) ,
L_61 , V_234 . V_99 ) ;
break;
}
default:
F_11 ( L_62 , V_222 ) ;
V_10 = - V_138 ;
}
return V_10 ;
}
struct V_1 * F_113 ( struct V_103 * V_103 ,
const struct V_1 * V_85 ,
const struct V_155 * V_156 )
{
int V_10 ;
struct V_94 * V_122 ;
struct V_94 V_235 = { 0 } ;
void * V_173 ;
struct V_1 * V_236 ;
V_122 = F_89 ( V_156 -> V_134 ) ;
if ( ! V_122 ) {
V_10 = - V_144 ;
goto V_100;
}
V_173 = V_122 -> V_101 ;
memcpy ( V_173 , V_156 -> V_101 , V_156 -> V_134 ) ;
V_10 = F_50 ( V_122 , V_173 , V_156 ) ;
F_11 ( L_63 , V_10 ) ;
if ( V_10 != 0 )
goto V_237;
V_236 = F_114 ( V_103 , V_85 , & V_235 , V_122 ) ;
if ( F_41 ( V_236 ) ) {
V_10 = F_42 ( V_236 ) ;
goto V_237;
}
return V_236 ;
V_237:
F_86 ( V_122 ) ;
V_100:
return F_60 ( V_10 ) ;
}
void F_115 ( struct V_1 * V_85 )
{
struct V_94 * V_95 ;
void * V_173 ;
struct V_238 * V_239 = V_85 -> V_147 ;
struct V_77 * V_157 ;
V_95 = F_116 ( V_85 ) ;
V_173 = V_95 -> V_101 ;
F_51 (iter, loc_cpu_entry, private->size)
F_49 ( V_157 ) ;
if ( V_95 -> V_158 > V_95 -> V_181 )
F_43 ( V_239 ) ;
F_86 ( V_95 ) ;
}
static int T_9 F_117 ( struct V_103 * V_103 )
{
return F_118 ( V_103 , V_106 ) ;
}
static void T_10 F_119 ( struct V_103 * V_103 )
{
F_120 ( V_103 , V_106 ) ;
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
F_126 ( L_64 ) ;
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
