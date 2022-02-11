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
unsigned int F_17 ( struct V_70 * V_71 ,
unsigned int V_81 ,
const struct V_82 * V_83 ,
struct V_1 * V_84 )
{
static const char V_85 [ V_19 ] V_86 ( ( F_18 ( sizeof( long ) ) ) ) ;
unsigned int V_87 = V_75 ;
const struct V_20 * V_66 ;
struct V_77 * V_78 , * * V_88 ;
const char * V_23 , * V_24 ;
const void * V_89 ;
unsigned int V_90 , V_91 = 0 ;
const struct V_92 * V_93 ;
struct V_72 V_94 ;
unsigned int V_95 ;
if ( ! F_19 ( V_71 , F_20 ( V_71 -> V_22 ) ) )
return V_75 ;
V_23 = V_83 -> V_96 ? V_83 -> V_96 -> V_97 : V_85 ;
V_24 = V_83 -> V_98 ? V_83 -> V_98 -> V_97 : V_85 ;
F_21 () ;
V_95 = F_22 () ;
V_93 = V_84 -> V_93 ;
V_90 = F_23 () ;
F_24 () ;
V_89 = V_93 -> V_99 ;
V_88 = (struct V_77 * * ) V_93 -> V_88 [ V_90 ] ;
V_78 = F_16 ( V_89 , V_93 -> V_100 [ V_81 ] ) ;
V_94 . V_96 = V_83 -> V_96 ;
V_94 . V_98 = V_83 -> V_98 ;
V_94 . V_101 = V_81 ;
V_94 . V_102 = V_103 ;
V_94 . V_104 = false ;
V_66 = F_25 ( V_71 ) ;
do {
const struct V_76 * V_105 ;
struct V_106 * V_107 ;
if ( ! F_7 ( V_66 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_66 ) ) {
V_78 = F_26 ( V_78 ) ;
continue;
}
V_107 = F_27 ( & V_78 -> V_108 ) ;
F_28 ( * V_107 , F_20 ( V_71 -> V_22 ) , 1 ) ;
V_105 = F_14 ( V_78 ) ;
if ( ! V_105 -> V_109 . V_110 . V_111 -> V_111 ) {
int V_112 ;
V_112 = ( (struct V_113 * ) V_105 ) -> V_87 ;
if ( V_112 < 0 ) {
if ( V_112 != V_114 ) {
V_87 = ( unsigned int ) ( - V_112 ) - 1 ;
break;
}
if ( V_91 == 0 ) {
V_78 = F_16 ( V_89 ,
V_93 -> V_115 [ V_81 ] ) ;
} else {
V_78 = V_88 [ -- V_91 ] ;
V_78 = F_26 ( V_78 ) ;
}
continue;
}
if ( V_89 + V_112
!= F_26 ( V_78 ) ) {
if ( V_91 >= V_93 -> V_116 ) {
V_87 = V_75 ;
break;
}
V_88 [ V_91 ++ ] = V_78 ;
}
V_78 = F_16 ( V_89 , V_112 ) ;
continue;
}
V_94 . V_111 = V_105 -> V_109 . V_110 . V_111 ;
V_94 . V_74 = V_105 -> V_117 ;
V_87 = V_105 -> V_109 . V_110 . V_111 -> V_111 ( V_71 , & V_94 ) ;
V_66 = F_25 ( V_71 ) ;
if ( V_87 == V_118 )
V_78 = F_26 ( V_78 ) ;
else
break;
} while ( ! V_94 . V_104 );
F_29 ( V_95 ) ;
F_30 () ;
if ( V_94 . V_104 )
return V_75 ;
else
return V_87 ;
}
static inline bool F_31 ( const struct V_25 * V_66 )
{
static const struct V_25 V_119 ;
return memcmp ( V_66 , & V_119 , sizeof( V_119 ) ) == 0 ;
}
static int F_32 ( const struct V_92 * V_120 ,
unsigned int V_121 , void * V_122 )
{
unsigned int V_81 ;
for ( V_81 = 0 ; V_81 < V_123 ; V_81 ++ ) {
unsigned int V_124 = V_120 -> V_100 [ V_81 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_122 + V_124 ) ;
if ( ! ( V_121 & ( 1 << V_81 ) ) )
continue;
V_78 -> V_108 . V_125 = V_124 ;
for (; ; ) {
const struct V_113 * V_105
= ( void * ) F_14 ( V_78 ) ;
int V_126 = V_78 -> V_127 & ( 1 << V_81 ) ;
if ( V_78 -> V_127 & ( 1 << V_123 ) ) {
F_33 ( L_20 ,
V_81 , V_124 , V_78 -> V_127 ) ;
return 0 ;
}
V_78 -> V_127
|= ( ( 1 << V_81 ) | ( 1 << V_123 ) ) ;
if ( ( V_78 -> V_128 == sizeof( struct V_77 ) &&
( strcmp ( V_105 -> V_111 . V_109 . V_129 . V_97 ,
V_130 ) == 0 ) &&
V_105 -> V_87 < 0 && F_31 ( & V_78 -> V_66 ) ) ||
V_126 ) {
unsigned int V_131 , V_132 ;
if ( ( strcmp ( V_105 -> V_111 . V_109 . V_129 . V_97 ,
V_130 ) == 0 ) &&
V_105 -> V_87 < - V_133 - 1 ) {
F_11 ( L_21
L_22 ,
V_105 -> V_87 ) ;
return 0 ;
}
do {
V_78 -> V_127 ^= ( 1 << V_123 ) ;
V_131 = V_124 ;
V_124 = V_78 -> V_108 . V_125 ;
V_78 -> V_108 . V_125 = 0 ;
if ( V_124 == V_131 )
goto V_134;
V_78 = (struct V_77 * )
( V_122 + V_124 ) ;
} while ( V_131 == V_124 + V_78 -> V_135 );
V_132 = V_78 -> V_135 ;
V_78 = (struct V_77 * )
( V_122 + V_124 + V_132 ) ;
V_78 -> V_108 . V_125 = V_124 ;
V_124 += V_132 ;
} else {
int V_136 = V_105 -> V_87 ;
if ( strcmp ( V_105 -> V_111 . V_109 . V_129 . V_97 ,
V_130 ) == 0 &&
V_136 >= 0 ) {
if ( V_136 > V_120 -> V_132 -
sizeof( struct V_77 ) ) {
F_11 ( L_23
L_24 ,
V_136 ) ;
return 0 ;
}
F_11 ( L_25 ,
V_124 , V_136 ) ;
} else {
V_136 = V_124 + V_78 -> V_135 ;
}
V_78 = (struct V_77 * )
( V_122 + V_136 ) ;
V_78 -> V_108 . V_125 = V_124 ;
V_124 = V_136 ;
}
}
V_134:
F_11 ( L_26 , V_81 ) ;
}
return 1 ;
}
static inline int F_34 ( const struct V_77 * V_78 , const char * V_97 )
{
const struct V_76 * V_105 ;
if ( ! F_10 ( & V_78 -> V_66 ) ) {
F_11 ( L_27 , V_78 , V_97 ) ;
return - V_137 ;
}
if ( V_78 -> V_128 + sizeof( struct V_76 ) > V_78 -> V_135 )
return - V_137 ;
V_105 = F_14 ( V_78 ) ;
if ( V_78 -> V_128 + V_105 -> V_109 . V_138 > V_78 -> V_135 )
return - V_137 ;
return 0 ;
}
static inline int F_35 ( struct V_77 * V_78 , const char * V_97 )
{
struct V_76 * V_105 = F_15 ( V_78 ) ;
int V_10 ;
struct V_139 V_73 = {
. V_84 = V_97 ,
. V_140 = V_78 ,
. V_111 = V_105 -> V_109 . V_110 . V_111 ,
. V_74 = V_105 -> V_117 ,
. V_141 = V_78 -> V_127 ,
. V_102 = V_103 ,
} ;
V_10 = F_36 ( & V_73 , V_105 -> V_109 . V_138 - sizeof( * V_105 ) , 0 , false ) ;
if ( V_10 < 0 ) {
F_11 ( L_28 ,
V_105 -> V_109 . V_110 . V_111 -> V_97 ) ;
return V_10 ;
}
return 0 ;
}
static inline int
F_37 ( struct V_77 * V_78 , const char * V_97 , unsigned int V_132 )
{
struct V_76 * V_105 ;
struct V_142 * V_111 ;
int V_10 ;
V_10 = F_34 ( V_78 , V_97 ) ;
if ( V_10 )
return V_10 ;
V_78 -> V_108 . V_125 = F_38 () ;
if ( F_39 ( V_78 -> V_108 . V_125 ) )
return - V_143 ;
V_105 = F_15 ( V_78 ) ;
V_111 = F_40 ( V_103 , V_105 -> V_109 . V_129 . V_97 ,
V_105 -> V_109 . V_129 . V_144 ) ;
if ( F_41 ( V_111 ) ) {
F_11 ( L_29 , V_105 -> V_109 . V_129 . V_97 ) ;
V_10 = F_42 ( V_111 ) ;
goto V_98;
}
V_105 -> V_109 . V_110 . V_111 = V_111 ;
V_10 = F_35 ( V_78 , V_97 ) ;
if ( V_10 )
goto V_145;
return 0 ;
V_145:
F_43 ( V_105 -> V_109 . V_110 . V_111 -> V_146 ) ;
V_98:
F_44 ( V_78 -> V_108 . V_125 ) ;
return V_10 ;
}
static bool F_45 ( const struct V_77 * V_78 )
{
const struct V_76 * V_105 ;
unsigned int V_87 ;
if ( ! F_31 ( & V_78 -> V_66 ) )
return false ;
V_105 = F_14 ( V_78 ) ;
if ( strcmp ( V_105 -> V_109 . V_129 . V_97 , V_130 ) != 0 )
return false ;
V_87 = ( (struct V_113 * ) V_105 ) -> V_87 ;
V_87 = - V_87 - 1 ;
return V_87 == V_75 || V_87 == V_147 ;
}
static inline int F_46 ( struct V_77 * V_78 ,
struct V_92 * V_120 ,
const unsigned char * V_79 ,
const unsigned char * V_148 ,
const unsigned int * V_149 ,
const unsigned int * V_150 ,
unsigned int V_121 )
{
unsigned int V_151 ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_148 ) {
F_11 ( L_30 , V_78 ) ;
return - V_137 ;
}
if ( V_78 -> V_135
< sizeof( struct V_77 ) + sizeof( struct V_76 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_135 ) ;
return - V_137 ;
}
for ( V_151 = 0 ; V_151 < V_123 ; V_151 ++ ) {
if ( ! ( V_121 & ( 1 << V_151 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_149 [ V_151 ] )
V_120 -> V_100 [ V_151 ] = V_149 [ V_151 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_151 ] ) {
if ( ! F_45 ( V_78 ) ) {
F_48 ( L_32
L_33
L_34 ) ;
return - V_137 ;
}
V_120 -> V_115 [ V_151 ] = V_150 [ V_151 ] ;
}
}
V_78 -> V_108 = ( (struct V_106 ) { 0 , 0 } ) ;
V_78 -> V_127 = 0 ;
return 0 ;
}
static inline void F_49 ( struct V_77 * V_78 )
{
struct V_152 V_73 ;
struct V_76 * V_105 ;
V_105 = F_15 ( V_78 ) ;
V_73 . V_111 = V_105 -> V_109 . V_110 . V_111 ;
V_73 . V_74 = V_105 -> V_117 ;
V_73 . V_102 = V_103 ;
if ( V_73 . V_111 -> V_153 != NULL )
V_73 . V_111 -> V_153 ( & V_73 ) ;
F_43 ( V_73 . V_111 -> V_146 ) ;
F_44 ( V_78 -> V_108 . V_125 ) ;
}
static int F_50 ( struct V_92 * V_120 , void * V_122 ,
const struct V_154 * V_155 )
{
struct V_77 * V_156 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_120 -> V_132 = V_155 -> V_132 ;
V_120 -> V_157 = V_155 -> V_158 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_120 -> V_100 [ V_9 ] = 0xFFFFFFFF ;
V_120 -> V_115 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_35 , V_120 -> V_132 ) ;
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_46 ( V_156 , V_120 , V_122 ,
V_122 + V_155 -> V_132 ,
V_155 -> V_100 ,
V_155 -> V_115 ,
V_155 -> V_121 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_156 ) -> V_109 . V_129 . V_97 ,
V_159 ) == 0 )
++ V_120 -> V_116 ;
}
F_11 ( L_36 , V_10 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_155 -> V_158 ) {
F_11 ( L_37 ,
V_9 , V_155 -> V_158 ) ;
return - V_137 ;
}
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
if ( ! ( V_155 -> V_121 & ( 1 << V_9 ) ) )
continue;
if ( V_120 -> V_100 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_155 -> V_100 [ V_9 ] ) ;
return - V_137 ;
}
if ( V_120 -> V_115 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_155 -> V_115 [ V_9 ] ) ;
return - V_137 ;
}
}
if ( ! F_32 ( V_120 , V_155 -> V_121 , V_122 ) ) {
F_11 ( L_40 ) ;
return - V_160 ;
}
V_9 = 0 ;
F_51 (iter, entry0, newinfo->size) {
V_10 = F_37 ( V_156 , V_155 -> V_97 , V_155 -> V_132 ) ;
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
static void F_52 ( const struct V_92 * V_105 ,
struct V_106 V_108 [] )
{
struct V_77 * V_156 ;
unsigned int V_90 ;
unsigned int V_9 ;
F_53 (cpu) {
T_4 * V_161 = & F_54 ( V_162 , V_90 ) ;
V_9 = 0 ;
F_51 (iter, t->entries, t->size) {
struct V_106 * V_163 ;
T_5 V_164 , V_125 ;
unsigned int V_165 ;
V_163 = F_55 ( & V_156 -> V_108 , V_90 ) ;
do {
V_165 = F_56 ( V_161 ) ;
V_164 = V_163 -> V_164 ;
V_125 = V_163 -> V_125 ;
} while ( F_57 ( V_161 , V_165 ) );
F_28 ( V_108 [ V_9 ] , V_164 , V_125 ) ;
++ V_9 ;
}
}
}
static struct V_106 * F_58 ( const struct V_1 * V_84 )
{
unsigned int V_166 ;
struct V_106 * V_108 ;
const struct V_92 * V_93 = V_84 -> V_93 ;
V_166 = sizeof( struct V_106 ) * V_93 -> V_157 ;
V_108 = F_59 ( V_166 ) ;
if ( V_108 == NULL )
return F_60 ( - V_143 ) ;
F_52 ( V_93 , V_108 ) ;
return V_108 ;
}
static int F_61 ( unsigned int V_167 ,
const struct V_1 * V_84 ,
void T_6 * V_168 )
{
unsigned int V_169 , V_170 ;
const struct V_77 * V_78 ;
struct V_106 * V_108 ;
struct V_92 * V_93 = V_84 -> V_93 ;
int V_10 = 0 ;
void * V_171 ;
V_108 = F_58 ( V_84 ) ;
if ( F_41 ( V_108 ) )
return F_42 ( V_108 ) ;
V_171 = V_93 -> V_99 ;
if ( F_62 ( V_168 , V_171 , V_167 ) != 0 ) {
V_10 = - V_172 ;
goto V_173;
}
for ( V_169 = 0 , V_170 = 0 ; V_169 < V_167 ; V_169 += V_78 -> V_135 , V_170 ++ ) {
const struct V_76 * V_105 ;
V_78 = (struct V_77 * ) ( V_171 + V_169 ) ;
if ( F_62 ( V_168 + V_169
+ F_63 ( struct V_77 , V_108 ) ,
& V_108 [ V_170 ] ,
sizeof( V_108 [ V_170 ] ) ) != 0 ) {
V_10 = - V_172 ;
goto V_173;
}
V_105 = F_14 ( V_78 ) ;
if ( F_62 ( V_168 + V_169 + V_78 -> V_128
+ F_63 ( struct V_76 ,
V_109 . V_129 . V_97 ) ,
V_105 -> V_109 . V_110 . V_111 -> V_97 ,
strlen ( V_105 -> V_109 . V_110 . V_111 -> V_97 ) + 1 ) != 0 ) {
V_10 = - V_172 ;
goto V_173;
}
}
V_173:
F_64 ( V_108 ) ;
return V_10 ;
}
static void F_65 ( void * V_174 , const void * V_54 )
{
int V_112 = * ( V_175 * ) V_54 ;
if ( V_112 > 0 )
V_112 += F_66 ( V_103 , V_112 ) ;
memcpy ( V_174 , & V_112 , sizeof( V_112 ) ) ;
}
static int F_67 ( void T_6 * V_174 , const void * V_54 )
{
V_175 V_176 = * ( int * ) V_54 ;
if ( V_176 > 0 )
V_176 -= F_66 ( V_103 , V_176 ) ;
return F_62 ( V_174 , & V_176 , sizeof( V_176 ) ) ? - V_172 : 0 ;
}
static int F_68 ( const struct V_77 * V_78 ,
const struct V_92 * V_2 ,
const void * V_79 , struct V_92 * V_120 )
{
const struct V_76 * V_105 ;
unsigned int V_177 ;
int V_169 , V_9 , V_10 ;
V_169 = sizeof( struct V_77 ) - sizeof( struct V_178 ) ;
V_177 = ( void * ) V_78 - V_79 ;
V_105 = F_14 ( V_78 ) ;
V_169 += F_69 ( V_105 -> V_109 . V_110 . V_111 ) ;
V_120 -> V_132 -= V_169 ;
V_10 = F_70 ( V_103 , V_177 , V_169 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
if ( V_2 -> V_100 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_100 [ V_9 ] ) ) )
V_120 -> V_100 [ V_9 ] -= V_169 ;
if ( V_2 -> V_115 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_115 [ V_9 ] ) ) )
V_120 -> V_115 [ V_9 ] -= V_169 ;
}
return 0 ;
}
static int F_71 ( const struct V_92 * V_2 ,
struct V_92 * V_120 )
{
struct V_77 * V_156 ;
const void * V_171 ;
int V_10 ;
if ( ! V_120 || ! V_2 )
return - V_137 ;
memcpy ( V_120 , V_2 , F_63 ( struct V_92 , V_99 ) ) ;
V_120 -> V_179 = 0 ;
V_171 = V_2 -> V_99 ;
F_72 ( V_103 , V_2 -> V_157 ) ;
F_51 (iter, loc_cpu_entry, info->size) {
V_10 = F_68 ( V_156 , V_2 , V_171 , V_120 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_73 ( struct V_180 * V_180 , void T_6 * V_129 ,
const int * V_8 , int V_181 )
{
char V_97 [ V_182 ] ;
struct V_1 * V_105 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_183 ) ) {
F_11 ( L_41 , * V_8 ,
sizeof( struct V_183 ) ) ;
return - V_137 ;
}
if ( F_74 ( V_97 , V_129 , sizeof( V_97 ) ) != 0 )
return - V_172 ;
V_97 [ V_182 - 1 ] = '\0' ;
#ifdef F_75
if ( V_181 )
F_76 ( V_103 ) ;
#endif
V_105 = F_77 ( F_78 ( V_180 , V_103 , V_97 ) ,
L_42 , V_97 ) ;
if ( ! F_79 ( V_105 ) ) {
struct V_183 V_2 ;
const struct V_92 * V_93 = V_105 -> V_93 ;
#ifdef F_75
struct V_92 V_163 ;
if ( V_181 ) {
V_10 = F_71 ( V_93 , & V_163 ) ;
F_80 ( V_103 ) ;
V_93 = & V_163 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_121 = V_105 -> V_121 ;
memcpy ( V_2 . V_100 , V_93 -> V_100 ,
sizeof( V_2 . V_100 ) ) ;
memcpy ( V_2 . V_115 , V_93 -> V_115 ,
sizeof( V_2 . V_115 ) ) ;
V_2 . V_158 = V_93 -> V_157 ;
V_2 . V_132 = V_93 -> V_132 ;
strcpy ( V_2 . V_97 , V_97 ) ;
if ( F_62 ( V_129 , & V_2 , * V_8 ) != 0 )
V_10 = - V_172 ;
else
V_10 = 0 ;
F_81 ( V_105 ) ;
F_43 ( V_105 -> V_146 ) ;
} else
V_10 = V_105 ? F_42 ( V_105 ) : - V_184 ;
#ifdef F_75
if ( V_181 )
F_82 ( V_103 ) ;
#endif
return V_10 ;
}
static int F_83 ( struct V_180 * V_180 , struct V_185 T_6 * V_186 ,
const int * V_8 )
{
int V_10 ;
struct V_185 V_187 ;
struct V_1 * V_105 ;
if ( * V_8 < sizeof( V_187 ) ) {
F_11 ( L_43 , * V_8 , sizeof( V_187 ) ) ;
return - V_137 ;
}
if ( F_74 ( & V_187 , V_186 , sizeof( V_187 ) ) != 0 )
return - V_172 ;
if ( * V_8 != sizeof( struct V_185 ) + V_187 . V_132 ) {
F_11 ( L_44 , * V_8 ,
sizeof( struct V_185 ) + V_187 . V_132 ) ;
return - V_137 ;
}
V_105 = F_78 ( V_180 , V_103 , V_187 . V_97 ) ;
if ( ! F_79 ( V_105 ) ) {
const struct V_92 * V_93 = V_105 -> V_93 ;
F_11 ( L_45 ,
V_93 -> V_157 ) ;
if ( V_187 . V_132 == V_93 -> V_132 )
V_10 = F_61 ( V_93 -> V_132 ,
V_105 , V_186 -> V_188 ) ;
else {
F_11 ( L_46 ,
V_93 -> V_132 , V_187 . V_132 ) ;
V_10 = - V_189 ;
}
F_43 ( V_105 -> V_146 ) ;
F_81 ( V_105 ) ;
} else
V_10 = V_105 ? F_42 ( V_105 ) : - V_184 ;
return V_10 ;
}
static int F_84 ( struct V_180 * V_180 , const char * V_97 ,
unsigned int V_121 ,
struct V_92 * V_120 ,
unsigned int V_190 ,
void T_6 * V_191 )
{
int V_10 ;
struct V_1 * V_105 ;
struct V_92 * V_192 ;
struct V_106 * V_108 ;
void * V_193 ;
struct V_77 * V_156 ;
V_10 = 0 ;
V_108 = F_59 ( V_190 * sizeof( struct V_106 ) ) ;
if ( ! V_108 ) {
V_10 = - V_143 ;
goto V_98;
}
V_105 = F_77 ( F_78 ( V_180 , V_103 , V_97 ) ,
L_42 , V_97 ) ;
if ( F_79 ( V_105 ) ) {
V_10 = V_105 ? F_42 ( V_105 ) : - V_184 ;
goto V_194;
}
if ( V_121 != V_105 -> V_121 ) {
F_11 ( L_47 ,
V_121 , V_105 -> V_121 ) ;
V_10 = - V_137 ;
goto V_195;
}
V_192 = F_85 ( V_105 , V_190 , V_120 , & V_10 ) ;
if ( ! V_192 )
goto V_195;
F_11 ( L_48 ,
V_192 -> V_157 , V_192 -> V_179 , V_120 -> V_157 ) ;
if ( ( V_192 -> V_157 > V_192 -> V_179 ) ||
( V_120 -> V_157 <= V_192 -> V_179 ) )
F_43 ( V_105 -> V_146 ) ;
if ( ( V_192 -> V_157 > V_192 -> V_179 ) &&
( V_120 -> V_157 <= V_192 -> V_179 ) )
F_43 ( V_105 -> V_146 ) ;
F_52 ( V_192 , V_108 ) ;
V_193 = V_192 -> V_99 ;
F_51 (iter, loc_cpu_old_entry, oldinfo->size)
F_49 ( V_156 ) ;
F_86 ( V_192 ) ;
if ( F_62 ( V_191 , V_108 ,
sizeof( struct V_106 ) * V_190 ) != 0 ) {
F_87 ( L_49 ) ;
}
F_64 ( V_108 ) ;
F_81 ( V_105 ) ;
return V_10 ;
V_195:
F_43 ( V_105 -> V_146 ) ;
F_81 ( V_105 ) ;
V_194:
F_64 ( V_108 ) ;
V_98:
return V_10 ;
}
static int F_88 ( struct V_180 * V_180 , const void T_6 * V_129 ,
unsigned int V_8 )
{
int V_10 ;
struct V_154 V_163 ;
struct V_92 * V_120 ;
void * V_171 ;
struct V_77 * V_156 ;
if ( F_74 ( & V_163 , V_129 , sizeof( V_163 ) ) != 0 )
return - V_172 ;
if ( V_163 . V_190 >= V_196 / sizeof( struct V_106 ) )
return - V_143 ;
if ( V_163 . V_190 == 0 )
return - V_137 ;
V_163 . V_97 [ sizeof( V_163 . V_97 ) - 1 ] = 0 ;
V_120 = F_89 ( V_163 . V_132 ) ;
if ( ! V_120 )
return - V_143 ;
V_171 = V_120 -> V_99 ;
if ( F_74 ( V_171 , V_129 + sizeof( V_163 ) ,
V_163 . V_132 ) != 0 ) {
V_10 = - V_172 ;
goto V_197;
}
V_10 = F_50 ( V_120 , V_171 , & V_163 ) ;
if ( V_10 != 0 )
goto V_197;
F_11 ( L_50 ) ;
V_10 = F_84 ( V_180 , V_163 . V_97 , V_163 . V_121 , V_120 ,
V_163 . V_190 , V_163 . V_108 ) ;
if ( V_10 )
goto V_198;
return 0 ;
V_198:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_156 ) ;
V_197:
F_86 ( V_120 ) ;
return V_10 ;
}
static int F_90 ( struct V_180 * V_180 , const void T_6 * V_129 ,
unsigned int V_8 , int V_181 )
{
unsigned int V_9 ;
struct V_199 V_163 ;
struct V_106 * V_200 ;
unsigned int V_190 ;
const char * V_97 ;
int V_132 ;
void * V_201 ;
struct V_1 * V_105 ;
const struct V_92 * V_93 ;
int V_10 = 0 ;
struct V_77 * V_156 ;
unsigned int V_95 ;
#ifdef F_75
struct V_202 V_203 ;
if ( V_181 ) {
V_201 = & V_203 ;
V_132 = sizeof( struct V_202 ) ;
} else
#endif
{
V_201 = & V_163 ;
V_132 = sizeof( struct V_199 ) ;
}
if ( F_74 ( V_201 , V_129 , V_132 ) != 0 )
return - V_172 ;
#ifdef F_75
if ( V_181 ) {
V_190 = V_203 . V_190 ;
V_97 = V_203 . V_97 ;
} else
#endif
{
V_190 = V_163 . V_190 ;
V_97 = V_163 . V_97 ;
}
if ( V_8 != V_132 + V_190 * sizeof( struct V_106 ) )
return - V_137 ;
V_200 = F_91 ( V_8 - V_132 ) ;
if ( ! V_200 )
return - V_143 ;
if ( F_74 ( V_200 , V_129 + V_132 , V_8 - V_132 ) != 0 ) {
V_10 = - V_172 ;
goto free;
}
V_105 = F_78 ( V_180 , V_103 , V_97 ) ;
if ( F_79 ( V_105 ) ) {
V_10 = V_105 ? F_42 ( V_105 ) : - V_184 ;
goto free;
}
F_21 () ;
V_93 = V_105 -> V_93 ;
if ( V_93 -> V_157 != V_190 ) {
V_10 = - V_137 ;
goto V_204;
}
V_9 = 0 ;
V_95 = F_22 () ;
F_51 (iter, private->entries, private->size) {
struct V_106 * V_163 ;
V_163 = F_27 ( & V_156 -> V_108 ) ;
F_28 ( * V_163 , V_200 [ V_9 ] . V_164 , V_200 [ V_9 ] . V_125 ) ;
++ V_9 ;
}
F_29 ( V_95 ) ;
V_204:
F_30 () ;
F_81 ( V_105 ) ;
F_43 ( V_105 -> V_146 ) ;
free:
F_64 ( V_200 ) ;
return V_10 ;
}
static inline void F_92 ( struct V_178 * V_78 )
{
struct V_76 * V_105 ;
V_105 = F_93 ( V_78 ) ;
F_43 ( V_105 -> V_109 . V_110 . V_111 -> V_146 ) ;
}
static inline int
F_94 ( struct V_178 * V_78 ,
struct V_92 * V_120 ,
unsigned int * V_132 ,
const unsigned char * V_79 ,
const unsigned char * V_148 ,
const unsigned int * V_149 ,
const unsigned int * V_150 ,
const char * V_97 )
{
struct V_76 * V_105 ;
struct V_142 * V_111 ;
unsigned int V_177 ;
int V_10 , V_169 , V_151 ;
F_11 ( L_51 , V_78 ) ;
if ( ( unsigned long ) V_78 % F_47 ( struct V_178 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_178 ) >= V_148 ) {
F_11 ( L_52 , V_78 , V_148 ) ;
return - V_137 ;
}
if ( V_78 -> V_135 < sizeof( struct V_178 ) +
sizeof( struct V_205 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_135 ) ;
return - V_137 ;
}
V_10 = F_34 ( (struct V_77 * ) V_78 , V_97 ) ;
if ( V_10 )
return V_10 ;
V_169 = sizeof( struct V_77 ) - sizeof( struct V_178 ) ;
V_177 = ( void * ) V_78 - ( void * ) V_79 ;
V_105 = F_93 ( V_78 ) ;
V_111 = F_40 ( V_103 , V_105 -> V_109 . V_129 . V_97 ,
V_105 -> V_109 . V_129 . V_144 ) ;
if ( F_41 ( V_111 ) ) {
F_11 ( L_53 ,
V_105 -> V_109 . V_129 . V_97 ) ;
V_10 = F_42 ( V_111 ) ;
goto V_98;
}
V_105 -> V_109 . V_110 . V_111 = V_111 ;
V_169 += F_69 ( V_111 ) ;
* V_132 += V_169 ;
V_10 = F_70 ( V_103 , V_177 , V_169 ) ;
if ( V_10 )
goto V_206;
for ( V_151 = 0 ; V_151 < V_123 ; V_151 ++ ) {
if ( ( unsigned char * ) V_78 - V_79 == V_149 [ V_151 ] )
V_120 -> V_100 [ V_151 ] = V_149 [ V_151 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_150 [ V_151 ] )
V_120 -> V_115 [ V_151 ] = V_150 [ V_151 ] ;
}
memset ( & V_78 -> V_108 , 0 , sizeof( V_78 -> V_108 ) ) ;
V_78 -> V_127 = 0 ;
return 0 ;
V_206:
F_43 ( V_105 -> V_109 . V_110 . V_111 -> V_146 ) ;
V_98:
return V_10 ;
}
static int
F_95 ( struct V_178 * V_78 , void * * V_207 ,
unsigned int * V_132 , const char * V_97 ,
struct V_92 * V_120 , unsigned char * V_79 )
{
struct V_76 * V_105 ;
struct V_142 * V_111 ;
struct V_77 * V_208 ;
unsigned int V_209 ;
int V_10 , V_151 ;
V_10 = 0 ;
V_209 = * V_132 ;
V_208 = (struct V_77 * ) * V_207 ;
memcpy ( V_208 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_208 -> V_108 , & V_78 -> V_108 , sizeof( V_78 -> V_108 ) ) ;
* V_207 += sizeof( struct V_77 ) ;
* V_132 += sizeof( struct V_77 ) - sizeof( struct V_178 ) ;
V_208 -> V_128 = V_78 -> V_128 - ( V_209 - * V_132 ) ;
V_105 = F_93 ( V_78 ) ;
V_111 = V_105 -> V_109 . V_110 . V_111 ;
F_96 ( V_105 , V_207 , V_132 ) ;
V_208 -> V_135 = V_78 -> V_135 - ( V_209 - * V_132 ) ;
for ( V_151 = 0 ; V_151 < V_123 ; V_151 ++ ) {
if ( ( unsigned char * ) V_208 - V_79 < V_120 -> V_100 [ V_151 ] )
V_120 -> V_100 [ V_151 ] -= V_209 - * V_132 ;
if ( ( unsigned char * ) V_208 - V_79 < V_120 -> V_115 [ V_151 ] )
V_120 -> V_115 [ V_151 ] -= V_209 - * V_132 ;
}
return V_10 ;
}
static int F_97 ( const char * V_97 ,
unsigned int V_121 ,
struct V_92 * * V_210 ,
void * * V_211 ,
unsigned int V_167 ,
unsigned int V_157 ,
unsigned int * V_149 ,
unsigned int * V_150 )
{
unsigned int V_9 , V_212 ;
struct V_92 * V_120 , * V_2 ;
void * V_124 , * V_122 , * V_213 ;
struct V_178 * V_214 ;
struct V_77 * V_215 ;
unsigned int V_132 ;
int V_10 = 0 ;
V_2 = * V_210 ;
V_122 = * V_211 ;
V_132 = V_167 ;
V_2 -> V_157 = V_157 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_2 -> V_100 [ V_9 ] = 0xFFFFFFFF ;
V_2 -> V_115 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_54 , V_2 -> V_132 ) ;
V_212 = 0 ;
F_76 ( V_103 ) ;
F_72 ( V_103 , V_157 ) ;
F_51 (iter0, entry0, total_size) {
V_10 = F_94 ( V_214 , V_2 , & V_132 ,
V_122 ,
V_122 + V_167 ,
V_149 ,
V_150 ,
V_97 ) ;
if ( V_10 != 0 )
goto V_216;
++ V_212 ;
}
V_10 = - V_137 ;
if ( V_212 != V_157 ) {
F_11 ( L_55 ,
V_212 , V_157 ) ;
goto V_216;
}
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
if ( ! ( V_121 & ( 1 << V_9 ) ) )
continue;
if ( V_2 -> V_100 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_149 [ V_9 ] ) ;
goto V_216;
}
if ( V_2 -> V_115 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_150 [ V_9 ] ) ;
goto V_216;
}
}
V_10 = - V_143 ;
V_120 = F_89 ( V_132 ) ;
if ( ! V_120 )
goto V_216;
V_120 -> V_157 = V_157 ;
for ( V_9 = 0 ; V_9 < V_123 ; V_9 ++ ) {
V_120 -> V_100 [ V_9 ] = V_2 -> V_100 [ V_9 ] ;
V_120 -> V_115 [ V_9 ] = V_2 -> V_115 [ V_9 ] ;
}
V_213 = V_120 -> V_99 ;
V_124 = V_213 ;
V_132 = V_167 ;
F_51 (iter0, entry0, total_size) {
V_10 = F_95 ( V_214 , & V_124 , & V_132 ,
V_97 , V_120 , V_213 ) ;
if ( V_10 != 0 )
break;
}
F_80 ( V_103 ) ;
F_82 ( V_103 ) ;
if ( V_10 )
goto V_197;
V_10 = - V_160 ;
if ( ! F_32 ( V_120 , V_121 , V_213 ) )
goto V_197;
V_9 = 0 ;
F_51 (iter1, entry1, newinfo->size) {
V_215 -> V_108 . V_125 = F_38 () ;
if ( F_39 ( V_215 -> V_108 . V_125 ) ) {
V_10 = - V_143 ;
break;
}
V_10 = F_35 ( V_215 , V_97 ) ;
if ( V_10 != 0 ) {
F_44 ( V_215 -> V_108 . V_125 ) ;
break;
}
++ V_9 ;
if ( strcmp ( F_15 ( V_215 ) -> V_109 . V_129 . V_97 ,
V_159 ) == 0 )
++ V_120 -> V_116 ;
}
if ( V_10 ) {
int V_217 = V_9 ;
V_212 -= V_9 ;
F_51 (iter0, entry0, newinfo->size) {
if ( V_217 -- > 0 )
continue;
if ( V_212 -- == 0 )
break;
F_92 ( V_214 ) ;
}
F_51 (iter1, entry1, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_49 ( V_215 ) ;
}
F_86 ( V_120 ) ;
return V_10 ;
}
* V_210 = V_120 ;
* V_211 = V_213 ;
F_86 ( V_2 ) ;
return 0 ;
V_197:
F_86 ( V_120 ) ;
V_98:
F_51 (iter0, entry0, total_size) {
if ( V_212 -- == 0 )
break;
F_92 ( V_214 ) ;
}
return V_10 ;
V_216:
F_80 ( V_103 ) ;
F_82 ( V_103 ) ;
goto V_98;
}
static int F_98 ( struct V_180 * V_180 , void T_6 * V_129 ,
unsigned int V_8 )
{
int V_10 ;
struct V_218 V_163 ;
struct V_92 * V_120 ;
void * V_171 ;
struct V_77 * V_156 ;
if ( F_74 ( & V_163 , V_129 , sizeof( V_163 ) ) != 0 )
return - V_172 ;
if ( V_163 . V_132 >= V_196 / F_99 () )
return - V_143 ;
if ( V_163 . V_190 >= V_196 / sizeof( struct V_106 ) )
return - V_143 ;
if ( V_163 . V_190 == 0 )
return - V_137 ;
V_163 . V_97 [ sizeof( V_163 . V_97 ) - 1 ] = 0 ;
V_120 = F_89 ( V_163 . V_132 ) ;
if ( ! V_120 )
return - V_143 ;
V_171 = V_120 -> V_99 ;
if ( F_74 ( V_171 , V_129 + sizeof( V_163 ) , V_163 . V_132 ) != 0 ) {
V_10 = - V_172 ;
goto V_197;
}
V_10 = F_97 ( V_163 . V_97 , V_163 . V_121 ,
& V_120 , & V_171 , V_163 . V_132 ,
V_163 . V_158 , V_163 . V_100 ,
V_163 . V_115 ) ;
if ( V_10 != 0 )
goto V_197;
F_11 ( L_56 ) ;
V_10 = F_84 ( V_180 , V_163 . V_97 , V_163 . V_121 , V_120 ,
V_163 . V_190 , F_100 ( V_163 . V_108 ) ) ;
if ( V_10 )
goto V_198;
return 0 ;
V_198:
F_51 (iter, loc_cpu_entry, newinfo->size)
F_49 ( V_156 ) ;
V_197:
F_86 ( V_120 ) ;
return V_10 ;
}
static int F_101 ( struct V_219 * V_220 , int V_221 , void T_6 * V_129 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_10 = F_98 ( F_103 ( V_220 ) , V_129 , V_8 ) ;
break;
case V_226 :
V_10 = F_90 ( F_103 ( V_220 ) , V_129 , V_8 , 1 ) ;
break;
default:
F_11 ( L_57 , V_221 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
static int F_104 ( struct V_77 * V_78 , void T_6 * * V_207 ,
T_7 * V_132 ,
struct V_106 * V_108 ,
unsigned int V_9 )
{
struct V_76 * V_105 ;
struct V_178 T_6 * V_227 ;
T_8 V_128 , V_135 ;
T_7 V_209 ;
int V_10 ;
V_209 = * V_132 ;
V_227 = (struct V_178 T_6 * ) * V_207 ;
if ( F_62 ( V_227 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_62 ( & V_227 -> V_108 , & V_108 [ V_9 ] ,
sizeof( V_108 [ V_9 ] ) ) != 0 )
return - V_172 ;
* V_207 += sizeof( struct V_178 ) ;
* V_132 -= sizeof( struct V_77 ) - sizeof( struct V_178 ) ;
V_128 = V_78 -> V_128 - ( V_209 - * V_132 ) ;
V_105 = F_15 ( V_78 ) ;
V_10 = F_105 ( V_105 , V_207 , V_132 ) ;
if ( V_10 )
return V_10 ;
V_135 = V_78 -> V_135 - ( V_209 - * V_132 ) ;
if ( F_106 ( V_128 , & V_227 -> V_128 ) != 0 ||
F_106 ( V_135 , & V_227 -> V_135 ) != 0 )
return - V_172 ;
return 0 ;
}
static int F_107 ( unsigned int V_167 ,
struct V_1 * V_84 ,
void T_6 * V_168 )
{
struct V_106 * V_108 ;
const struct V_92 * V_93 = V_84 -> V_93 ;
void T_6 * V_124 ;
unsigned int V_132 ;
int V_10 = 0 ;
unsigned int V_9 = 0 ;
struct V_77 * V_156 ;
V_108 = F_58 ( V_84 ) ;
if ( F_41 ( V_108 ) )
return F_42 ( V_108 ) ;
V_124 = V_168 ;
V_132 = V_167 ;
F_51 (iter, private->entries, total_size) {
V_10 = F_104 ( V_156 , & V_124 ,
& V_132 , V_108 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_64 ( V_108 ) ;
return V_10 ;
}
static int F_108 ( struct V_180 * V_180 ,
struct V_228 T_6 * V_186 ,
int * V_8 )
{
int V_10 ;
struct V_228 V_187 ;
struct V_1 * V_105 ;
if ( * V_8 < sizeof( V_187 ) ) {
F_11 ( L_58 , * V_8 , sizeof( V_187 ) ) ;
return - V_137 ;
}
if ( F_74 ( & V_187 , V_186 , sizeof( V_187 ) ) != 0 )
return - V_172 ;
if ( * V_8 != sizeof( struct V_228 ) + V_187 . V_132 ) {
F_11 ( L_59 ,
* V_8 , sizeof( V_187 ) + V_187 . V_132 ) ;
return - V_137 ;
}
F_76 ( V_103 ) ;
V_105 = F_78 ( V_180 , V_103 , V_187 . V_97 ) ;
if ( ! F_79 ( V_105 ) ) {
const struct V_92 * V_93 = V_105 -> V_93 ;
struct V_92 V_2 ;
F_11 ( L_45 , V_93 -> V_157 ) ;
V_10 = F_71 ( V_93 , & V_2 ) ;
if ( ! V_10 && V_187 . V_132 == V_2 . V_132 ) {
V_10 = F_107 ( V_93 -> V_132 ,
V_105 , V_186 -> V_188 ) ;
} else if ( ! V_10 ) {
F_11 ( L_60 ,
V_93 -> V_132 , V_187 . V_132 ) ;
V_10 = - V_189 ;
}
F_80 ( V_103 ) ;
F_43 ( V_105 -> V_146 ) ;
F_81 ( V_105 ) ;
} else
V_10 = V_105 ? F_42 ( V_105 ) : - V_184 ;
F_82 ( V_103 ) ;
return V_10 ;
}
static int F_109 ( struct V_219 * V_220 , int V_221 , void T_6 * V_129 ,
int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_229 :
V_10 = F_73 ( F_103 ( V_220 ) , V_129 , V_8 , 1 ) ;
break;
case V_230 :
V_10 = F_108 ( F_103 ( V_220 ) , V_129 , V_8 ) ;
break;
default:
V_10 = F_110 ( V_220 , V_221 , V_129 , V_8 ) ;
}
return V_10 ;
}
static int F_111 ( struct V_219 * V_220 , int V_221 , void T_6 * V_129 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_10 = F_88 ( F_103 ( V_220 ) , V_129 , V_8 ) ;
break;
case V_226 :
V_10 = F_90 ( F_103 ( V_220 ) , V_129 , V_8 , 0 ) ;
break;
default:
F_11 ( L_57 , V_221 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
static int F_110 ( struct V_219 * V_220 , int V_221 , void T_6 * V_129 , int * V_8 )
{
int V_10 ;
if ( ! F_102 ( F_103 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_229 :
V_10 = F_73 ( F_103 ( V_220 ) , V_129 , V_8 , 0 ) ;
break;
case V_230 :
V_10 = F_83 ( F_103 ( V_220 ) , V_129 , V_8 ) ;
break;
case V_231 : {
struct V_232 V_233 ;
if ( * V_8 != sizeof( V_233 ) ) {
V_10 = - V_137 ;
break;
}
if ( F_74 ( & V_233 , V_129 , sizeof( V_233 ) ) != 0 ) {
V_10 = - V_172 ;
break;
}
V_233 . V_97 [ sizeof( V_233 . V_97 ) - 1 ] = 0 ;
F_77 ( F_112 ( V_103 , V_233 . V_97 ,
V_233 . V_144 , 1 , & V_10 ) ,
L_61 , V_233 . V_97 ) ;
break;
}
default:
F_11 ( L_62 , V_221 ) ;
V_10 = - V_137 ;
}
return V_10 ;
}
struct V_1 * F_113 ( struct V_180 * V_180 ,
const struct V_1 * V_84 ,
const struct V_154 * V_155 )
{
int V_10 ;
struct V_92 * V_120 ;
struct V_92 V_234 = { 0 } ;
void * V_171 ;
struct V_1 * V_235 ;
V_120 = F_89 ( V_155 -> V_132 ) ;
if ( ! V_120 ) {
V_10 = - V_143 ;
goto V_98;
}
V_171 = V_120 -> V_99 ;
memcpy ( V_171 , V_155 -> V_99 , V_155 -> V_132 ) ;
V_10 = F_50 ( V_120 , V_171 , V_155 ) ;
F_11 ( L_63 , V_10 ) ;
if ( V_10 != 0 )
goto V_236;
V_235 = F_114 ( V_180 , V_84 , & V_234 , V_120 ) ;
if ( F_41 ( V_235 ) ) {
V_10 = F_42 ( V_235 ) ;
goto V_236;
}
return V_235 ;
V_236:
F_86 ( V_120 ) ;
V_98:
return F_60 ( V_10 ) ;
}
void F_115 ( struct V_1 * V_84 )
{
struct V_92 * V_93 ;
void * V_171 ;
struct V_237 * V_238 = V_84 -> V_146 ;
struct V_77 * V_156 ;
V_93 = F_116 ( V_84 ) ;
V_171 = V_93 -> V_99 ;
F_51 (iter, loc_cpu_entry, private->size)
F_49 ( V_156 ) ;
if ( V_93 -> V_157 > V_93 -> V_179 )
F_43 ( V_238 ) ;
F_86 ( V_93 ) ;
}
static int T_9 F_117 ( struct V_180 * V_180 )
{
return F_118 ( V_180 , V_103 ) ;
}
static void T_10 F_119 ( struct V_180 * V_180 )
{
F_120 ( V_180 , V_103 ) ;
}
static int T_11 F_121 ( void )
{
int V_10 ;
V_10 = F_122 ( & V_239 ) ;
if ( V_10 < 0 )
goto V_240;
V_10 = F_123 ( V_241 , F_124 ( V_241 ) ) ;
if ( V_10 < 0 )
goto V_242;
V_10 = F_125 ( & V_243 ) ;
if ( V_10 < 0 )
goto V_244;
F_126 ( V_245 L_64 ) ;
return 0 ;
V_244:
F_127 ( V_241 , F_124 ( V_241 ) ) ;
V_242:
F_128 ( & V_239 ) ;
V_240:
return V_10 ;
}
static void T_12 F_129 ( void )
{
F_130 ( & V_243 ) ;
F_127 ( V_241 , F_124 ( V_241 ) ) ;
F_128 ( & V_239 ) ;
}
