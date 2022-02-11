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
const struct V_21 * V_82 ,
const struct V_21 * V_83 ,
struct V_1 * V_84 )
{
static const char V_85 [ V_19 ] V_86 ( ( F_18 ( sizeof( long ) ) ) ) ;
unsigned int V_87 = V_75 ;
const struct V_20 * V_66 ;
struct V_77 * V_78 , * V_88 ;
const char * V_23 , * V_24 ;
void * V_89 ;
const struct V_90 * V_91 ;
struct V_72 V_92 ;
unsigned int V_93 ;
if ( ! F_19 ( V_71 , F_20 ( V_71 -> V_22 ) ) )
return V_75 ;
V_23 = V_82 ? V_82 -> V_94 : V_85 ;
V_24 = V_83 ? V_83 -> V_94 : V_85 ;
F_21 () ;
V_93 = F_22 () ;
V_91 = V_84 -> V_91 ;
F_23 () ;
V_89 = V_91 -> V_95 [ F_24 () ] ;
V_78 = F_16 ( V_89 , V_91 -> V_96 [ V_81 ] ) ;
V_88 = F_16 ( V_89 , V_91 -> V_97 [ V_81 ] ) ;
V_92 . V_82 = V_82 ;
V_92 . V_83 = V_83 ;
V_92 . V_98 = V_81 ;
V_92 . V_99 = V_100 ;
V_92 . V_101 = false ;
V_66 = F_25 ( V_71 ) ;
do {
const struct V_76 * V_102 ;
if ( ! F_7 ( V_66 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_66 ) ) {
V_78 = F_26 ( V_78 ) ;
continue;
}
F_27 ( V_78 -> V_103 , F_20 ( V_71 -> V_22 ) , 1 ) ;
V_102 = F_14 ( V_78 ) ;
if ( ! V_102 -> V_104 . V_105 . V_106 -> V_106 ) {
int V_107 ;
V_107 = ( (struct V_108 * ) V_102 ) -> V_87 ;
if ( V_107 < 0 ) {
if ( V_107 != V_109 ) {
V_87 = ( unsigned int ) ( - V_107 ) - 1 ;
break;
}
V_78 = V_88 ;
V_88 = F_16 ( V_89 , V_88 -> V_110 ) ;
continue;
}
if ( V_89 + V_107
!= F_26 ( V_78 ) ) {
struct V_77 * V_111 = F_26 ( V_78 ) ;
V_111 -> V_110 = ( void * ) V_88 - V_89 ;
V_88 = V_111 ;
}
V_78 = F_16 ( V_89 , V_107 ) ;
continue;
}
V_92 . V_106 = V_102 -> V_104 . V_105 . V_106 ;
V_92 . V_74 = V_102 -> V_112 ;
V_87 = V_102 -> V_104 . V_105 . V_106 -> V_106 ( V_71 , & V_92 ) ;
V_66 = F_25 ( V_71 ) ;
if ( V_87 == V_113 )
V_78 = F_26 ( V_78 ) ;
else
break;
} while ( ! V_92 . V_101 );
F_28 ( V_93 ) ;
F_29 () ;
if ( V_92 . V_101 )
return V_75 ;
else
return V_87 ;
}
static inline bool F_30 ( const struct V_25 * V_66 )
{
static const struct V_25 V_114 ;
return memcmp ( V_66 , & V_114 , sizeof( V_114 ) ) == 0 ;
}
static int F_31 ( const struct V_90 * V_115 ,
unsigned int V_116 , void * V_117 )
{
unsigned int V_81 ;
for ( V_81 = 0 ; V_81 < V_118 ; V_81 ++ ) {
unsigned int V_119 = V_115 -> V_96 [ V_81 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_117 + V_119 ) ;
if ( ! ( V_116 & ( 1 << V_81 ) ) )
continue;
V_78 -> V_103 . V_120 = V_119 ;
for (; ; ) {
const struct V_108 * V_102
= ( void * ) F_14 ( V_78 ) ;
int V_121 = V_78 -> V_110 & ( 1 << V_81 ) ;
if ( V_78 -> V_110 & ( 1 << V_118 ) ) {
F_32 ( L_20 ,
V_81 , V_119 , V_78 -> V_110 ) ;
return 0 ;
}
V_78 -> V_110
|= ( ( 1 << V_81 ) | ( 1 << V_118 ) ) ;
if ( ( V_78 -> V_122 == sizeof( struct V_77 ) &&
( strcmp ( V_102 -> V_106 . V_104 . V_123 . V_94 ,
V_124 ) == 0 ) &&
V_102 -> V_87 < 0 && F_30 ( & V_78 -> V_66 ) ) ||
V_121 ) {
unsigned int V_125 , V_126 ;
if ( ( strcmp ( V_102 -> V_106 . V_104 . V_123 . V_94 ,
V_124 ) == 0 ) &&
V_102 -> V_87 < - V_127 - 1 ) {
F_11 ( L_21
L_22 ,
V_102 -> V_87 ) ;
return 0 ;
}
do {
V_78 -> V_110 ^= ( 1 << V_118 ) ;
V_125 = V_119 ;
V_119 = V_78 -> V_103 . V_120 ;
V_78 -> V_103 . V_120 = 0 ;
if ( V_119 == V_125 )
goto V_111;
V_78 = (struct V_77 * )
( V_117 + V_119 ) ;
} while ( V_125 == V_119 + V_78 -> V_128 );
V_126 = V_78 -> V_128 ;
V_78 = (struct V_77 * )
( V_117 + V_119 + V_126 ) ;
V_78 -> V_103 . V_120 = V_119 ;
V_119 += V_126 ;
} else {
int V_129 = V_102 -> V_87 ;
if ( strcmp ( V_102 -> V_106 . V_104 . V_123 . V_94 ,
V_124 ) == 0 &&
V_129 >= 0 ) {
if ( V_129 > V_115 -> V_126 -
sizeof( struct V_77 ) ) {
F_11 ( L_23
L_24 ,
V_129 ) ;
return 0 ;
}
F_11 ( L_25 ,
V_119 , V_129 ) ;
} else {
V_129 = V_119 + V_78 -> V_128 ;
}
V_78 = (struct V_77 * )
( V_117 + V_129 ) ;
V_78 -> V_103 . V_120 = V_119 ;
V_119 = V_129 ;
}
}
V_111:
F_11 ( L_26 , V_81 ) ;
}
return 1 ;
}
static inline int F_33 ( const struct V_77 * V_78 , const char * V_94 )
{
const struct V_76 * V_102 ;
if ( ! F_10 ( & V_78 -> V_66 ) ) {
F_11 ( L_27 , V_78 , V_94 ) ;
return - V_130 ;
}
if ( V_78 -> V_122 + sizeof( struct V_76 ) > V_78 -> V_128 )
return - V_130 ;
V_102 = F_14 ( V_78 ) ;
if ( V_78 -> V_122 + V_102 -> V_104 . V_131 > V_78 -> V_128 )
return - V_130 ;
return 0 ;
}
static inline int F_34 ( struct V_77 * V_78 , const char * V_94 )
{
struct V_76 * V_102 = F_15 ( V_78 ) ;
int V_10 ;
struct V_132 V_73 = {
. V_84 = V_94 ,
. V_133 = V_78 ,
. V_106 = V_102 -> V_104 . V_105 . V_106 ,
. V_74 = V_102 -> V_112 ,
. V_134 = V_78 -> V_110 ,
. V_99 = V_100 ,
} ;
V_10 = F_35 ( & V_73 , V_102 -> V_104 . V_131 - sizeof( * V_102 ) , 0 , false ) ;
if ( V_10 < 0 ) {
F_11 ( L_28 ,
V_102 -> V_104 . V_105 . V_106 -> V_94 ) ;
return V_10 ;
}
return 0 ;
}
static inline int
F_36 ( struct V_77 * V_78 , const char * V_94 , unsigned int V_126 )
{
struct V_76 * V_102 ;
struct V_135 * V_106 ;
int V_10 ;
V_10 = F_33 ( V_78 , V_94 ) ;
if ( V_10 )
return V_10 ;
V_102 = F_15 ( V_78 ) ;
V_106 = F_37 ( V_100 , V_102 -> V_104 . V_123 . V_94 ,
V_102 -> V_104 . V_123 . V_136 ) ;
if ( F_38 ( V_106 ) ) {
F_11 ( L_29 , V_102 -> V_104 . V_123 . V_94 ) ;
V_10 = F_39 ( V_106 ) ;
goto V_83;
}
V_102 -> V_104 . V_105 . V_106 = V_106 ;
V_10 = F_34 ( V_78 , V_94 ) ;
if ( V_10 )
goto V_137;
return 0 ;
V_137:
F_40 ( V_102 -> V_104 . V_105 . V_106 -> V_138 ) ;
V_83:
return V_10 ;
}
static bool F_41 ( const struct V_77 * V_78 )
{
const struct V_76 * V_102 ;
unsigned int V_87 ;
if ( ! F_30 ( & V_78 -> V_66 ) )
return false ;
V_102 = F_14 ( V_78 ) ;
if ( strcmp ( V_102 -> V_104 . V_123 . V_94 , V_124 ) != 0 )
return false ;
V_87 = ( (struct V_108 * ) V_102 ) -> V_87 ;
V_87 = - V_87 - 1 ;
return V_87 == V_75 || V_87 == V_139 ;
}
static inline int F_42 ( struct V_77 * V_78 ,
struct V_90 * V_115 ,
const unsigned char * V_79 ,
const unsigned char * V_140 ,
const unsigned int * V_141 ,
const unsigned int * V_142 ,
unsigned int V_116 )
{
unsigned int V_143 ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_140 ) {
F_11 ( L_30 , V_78 ) ;
return - V_130 ;
}
if ( V_78 -> V_128
< sizeof( struct V_77 ) + sizeof( struct V_76 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_128 ) ;
return - V_130 ;
}
for ( V_143 = 0 ; V_143 < V_118 ; V_143 ++ ) {
if ( ! ( V_116 & ( 1 << V_143 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_141 [ V_143 ] )
V_115 -> V_96 [ V_143 ] = V_141 [ V_143 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_142 [ V_143 ] ) {
if ( ! F_41 ( V_78 ) ) {
F_44 ( L_32
L_33
L_34 ) ;
return - V_130 ;
}
V_115 -> V_97 [ V_143 ] = V_142 [ V_143 ] ;
}
}
V_78 -> V_103 = ( (struct V_144 ) { 0 , 0 } ) ;
V_78 -> V_110 = 0 ;
return 0 ;
}
static inline void F_45 ( struct V_77 * V_78 )
{
struct V_145 V_73 ;
struct V_76 * V_102 ;
V_102 = F_15 ( V_78 ) ;
V_73 . V_106 = V_102 -> V_104 . V_105 . V_106 ;
V_73 . V_74 = V_102 -> V_112 ;
V_73 . V_99 = V_100 ;
if ( V_73 . V_106 -> V_146 != NULL )
V_73 . V_106 -> V_146 ( & V_73 ) ;
F_40 ( V_73 . V_106 -> V_138 ) ;
}
static int F_46 ( struct V_90 * V_115 , void * V_117 ,
const struct V_147 * V_148 )
{
struct V_77 * V_149 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_115 -> V_126 = V_148 -> V_126 ;
V_115 -> V_150 = V_148 -> V_151 ;
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
V_115 -> V_96 [ V_9 ] = 0xFFFFFFFF ;
V_115 -> V_97 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_35 , V_115 -> V_126 ) ;
V_9 = 0 ;
F_47 (iter, entry0, newinfo->size) {
V_10 = F_42 ( V_149 , V_115 , V_117 ,
V_117 + V_148 -> V_126 ,
V_148 -> V_96 ,
V_148 -> V_97 ,
V_148 -> V_116 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_149 ) -> V_104 . V_123 . V_94 ,
V_152 ) == 0 )
++ V_115 -> V_153 ;
}
F_11 ( L_36 , V_10 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_148 -> V_151 ) {
F_11 ( L_37 ,
V_9 , V_148 -> V_151 ) ;
return - V_130 ;
}
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
if ( ! ( V_148 -> V_116 & ( 1 << V_9 ) ) )
continue;
if ( V_115 -> V_96 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_148 -> V_96 [ V_9 ] ) ;
return - V_130 ;
}
if ( V_115 -> V_97 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_148 -> V_97 [ V_9 ] ) ;
return - V_130 ;
}
}
if ( ! F_31 ( V_115 , V_148 -> V_116 , V_117 ) ) {
F_11 ( L_40 ) ;
return - V_154 ;
}
V_9 = 0 ;
F_47 (iter, entry0, newinfo->size) {
V_10 = F_36 ( V_149 , V_148 -> V_94 , V_148 -> V_126 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_47 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_45 ( V_149 ) ;
}
return V_10 ;
}
F_48 (i) {
if ( V_115 -> V_95 [ V_9 ] && V_115 -> V_95 [ V_9 ] != V_117 )
memcpy ( V_115 -> V_95 [ V_9 ] , V_117 , V_115 -> V_126 ) ;
}
return V_10 ;
}
static void F_49 ( const struct V_90 * V_102 ,
struct V_144 V_103 [] )
{
struct V_77 * V_149 ;
unsigned int V_155 ;
unsigned int V_9 ;
F_48 (cpu) {
T_4 * V_156 = & F_50 ( V_157 , V_155 ) ;
V_9 = 0 ;
F_47 (iter, t->entries[cpu], t->size) {
T_5 V_158 , V_120 ;
unsigned int V_159 ;
do {
V_159 = F_51 ( V_156 ) ;
V_158 = V_149 -> V_103 . V_158 ;
V_120 = V_149 -> V_103 . V_120 ;
} while ( F_52 ( V_156 , V_159 ) );
F_27 ( V_103 [ V_9 ] , V_158 , V_120 ) ;
++ V_9 ;
}
}
}
static struct V_144 * F_53 ( const struct V_1 * V_84 )
{
unsigned int V_160 ;
struct V_144 * V_103 ;
const struct V_90 * V_91 = V_84 -> V_91 ;
V_160 = sizeof( struct V_144 ) * V_91 -> V_150 ;
V_103 = F_54 ( V_160 ) ;
if ( V_103 == NULL )
return F_55 ( - V_161 ) ;
F_49 ( V_91 , V_103 ) ;
return V_103 ;
}
static int F_56 ( unsigned int V_162 ,
const struct V_1 * V_84 ,
void T_6 * V_163 )
{
unsigned int V_164 , V_165 ;
const struct V_77 * V_78 ;
struct V_144 * V_103 ;
struct V_90 * V_91 = V_84 -> V_91 ;
int V_10 = 0 ;
void * V_166 ;
V_103 = F_53 ( V_84 ) ;
if ( F_38 ( V_103 ) )
return F_39 ( V_103 ) ;
V_166 = V_91 -> V_95 [ F_57 () ] ;
if ( F_58 ( V_163 , V_166 , V_162 ) != 0 ) {
V_10 = - V_167 ;
goto V_168;
}
for ( V_164 = 0 , V_165 = 0 ; V_164 < V_162 ; V_164 += V_78 -> V_128 , V_165 ++ ) {
const struct V_76 * V_102 ;
V_78 = (struct V_77 * ) ( V_166 + V_164 ) ;
if ( F_58 ( V_163 + V_164
+ F_59 ( struct V_77 , V_103 ) ,
& V_103 [ V_165 ] ,
sizeof( V_103 [ V_165 ] ) ) != 0 ) {
V_10 = - V_167 ;
goto V_168;
}
V_102 = F_14 ( V_78 ) ;
if ( F_58 ( V_163 + V_164 + V_78 -> V_122
+ F_59 ( struct V_76 ,
V_104 . V_123 . V_94 ) ,
V_102 -> V_104 . V_105 . V_106 -> V_94 ,
strlen ( V_102 -> V_104 . V_105 . V_106 -> V_94 ) + 1 ) != 0 ) {
V_10 = - V_167 ;
goto V_168;
}
}
V_168:
F_60 ( V_103 ) ;
return V_10 ;
}
static void F_61 ( void * V_169 , const void * V_54 )
{
int V_107 = * ( V_170 * ) V_54 ;
if ( V_107 > 0 )
V_107 += F_62 ( V_100 , V_107 ) ;
memcpy ( V_169 , & V_107 , sizeof( V_107 ) ) ;
}
static int F_63 ( void T_6 * V_169 , const void * V_54 )
{
V_170 V_171 = * ( int * ) V_54 ;
if ( V_171 > 0 )
V_171 -= F_62 ( V_100 , V_171 ) ;
return F_58 ( V_169 , & V_171 , sizeof( V_171 ) ) ? - V_167 : 0 ;
}
static int F_64 ( const struct V_77 * V_78 ,
const struct V_90 * V_2 ,
const void * V_79 , struct V_90 * V_115 )
{
const struct V_76 * V_102 ;
unsigned int V_172 ;
int V_164 , V_9 , V_10 ;
V_164 = sizeof( struct V_77 ) - sizeof( struct V_173 ) ;
V_172 = ( void * ) V_78 - V_79 ;
V_102 = F_14 ( V_78 ) ;
V_164 += F_65 ( V_102 -> V_104 . V_105 . V_106 ) ;
V_115 -> V_126 -= V_164 ;
V_10 = F_66 ( V_100 , V_172 , V_164 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
if ( V_2 -> V_96 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_96 [ V_9 ] ) ) )
V_115 -> V_96 [ V_9 ] -= V_164 ;
if ( V_2 -> V_97 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_97 [ V_9 ] ) ) )
V_115 -> V_97 [ V_9 ] -= V_164 ;
}
return 0 ;
}
static int F_67 ( const struct V_90 * V_2 ,
struct V_90 * V_115 )
{
struct V_77 * V_149 ;
void * V_166 ;
int V_10 ;
if ( ! V_115 || ! V_2 )
return - V_130 ;
memcpy ( V_115 , V_2 , F_59 ( struct V_90 , V_95 ) ) ;
V_115 -> V_174 = 0 ;
V_166 = V_2 -> V_95 [ F_57 () ] ;
F_68 ( V_100 , V_2 -> V_150 ) ;
F_47 (iter, loc_cpu_entry, info->size) {
V_10 = F_64 ( V_149 , V_2 , V_166 , V_115 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_69 ( struct V_175 * V_175 , void T_6 * V_123 ,
const int * V_8 , int V_176 )
{
char V_94 [ V_177 ] ;
struct V_1 * V_102 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_178 ) ) {
F_11 ( L_41 , * V_8 ,
sizeof( struct V_178 ) ) ;
return - V_130 ;
}
if ( F_70 ( V_94 , V_123 , sizeof( V_94 ) ) != 0 )
return - V_167 ;
V_94 [ V_177 - 1 ] = '\0' ;
#ifdef F_71
if ( V_176 )
F_72 ( V_100 ) ;
#endif
V_102 = F_73 ( F_74 ( V_175 , V_100 , V_94 ) ,
L_42 , V_94 ) ;
if ( ! F_75 ( V_102 ) ) {
struct V_178 V_2 ;
const struct V_90 * V_91 = V_102 -> V_91 ;
#ifdef F_71
struct V_90 V_179 ;
if ( V_176 ) {
V_10 = F_67 ( V_91 , & V_179 ) ;
F_76 ( V_100 ) ;
V_91 = & V_179 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_116 = V_102 -> V_116 ;
memcpy ( V_2 . V_96 , V_91 -> V_96 ,
sizeof( V_2 . V_96 ) ) ;
memcpy ( V_2 . V_97 , V_91 -> V_97 ,
sizeof( V_2 . V_97 ) ) ;
V_2 . V_151 = V_91 -> V_150 ;
V_2 . V_126 = V_91 -> V_126 ;
strcpy ( V_2 . V_94 , V_94 ) ;
if ( F_58 ( V_123 , & V_2 , * V_8 ) != 0 )
V_10 = - V_167 ;
else
V_10 = 0 ;
F_77 ( V_102 ) ;
F_40 ( V_102 -> V_138 ) ;
} else
V_10 = V_102 ? F_39 ( V_102 ) : - V_180 ;
#ifdef F_71
if ( V_176 )
F_78 ( V_100 ) ;
#endif
return V_10 ;
}
static int F_79 ( struct V_175 * V_175 , struct V_181 T_6 * V_182 ,
const int * V_8 )
{
int V_10 ;
struct V_181 V_183 ;
struct V_1 * V_102 ;
if ( * V_8 < sizeof( V_183 ) ) {
F_11 ( L_43 , * V_8 , sizeof( V_183 ) ) ;
return - V_130 ;
}
if ( F_70 ( & V_183 , V_182 , sizeof( V_183 ) ) != 0 )
return - V_167 ;
if ( * V_8 != sizeof( struct V_181 ) + V_183 . V_126 ) {
F_11 ( L_44 , * V_8 ,
sizeof( struct V_181 ) + V_183 . V_126 ) ;
return - V_130 ;
}
V_102 = F_74 ( V_175 , V_100 , V_183 . V_94 ) ;
if ( ! F_75 ( V_102 ) ) {
const struct V_90 * V_91 = V_102 -> V_91 ;
F_11 ( L_45 ,
V_91 -> V_150 ) ;
if ( V_183 . V_126 == V_91 -> V_126 )
V_10 = F_56 ( V_91 -> V_126 ,
V_102 , V_182 -> V_184 ) ;
else {
F_11 ( L_46 ,
V_91 -> V_126 , V_183 . V_126 ) ;
V_10 = - V_185 ;
}
F_40 ( V_102 -> V_138 ) ;
F_77 ( V_102 ) ;
} else
V_10 = V_102 ? F_39 ( V_102 ) : - V_180 ;
return V_10 ;
}
static int F_80 ( struct V_175 * V_175 , const char * V_94 ,
unsigned int V_116 ,
struct V_90 * V_115 ,
unsigned int V_186 ,
void T_6 * V_187 )
{
int V_10 ;
struct V_1 * V_102 ;
struct V_90 * V_188 ;
struct V_144 * V_103 ;
void * V_189 ;
struct V_77 * V_149 ;
V_10 = 0 ;
V_103 = F_54 ( V_186 * sizeof( struct V_144 ) ) ;
if ( ! V_103 ) {
V_10 = - V_161 ;
goto V_83;
}
V_102 = F_73 ( F_74 ( V_175 , V_100 , V_94 ) ,
L_42 , V_94 ) ;
if ( F_75 ( V_102 ) ) {
V_10 = V_102 ? F_39 ( V_102 ) : - V_180 ;
goto V_190;
}
if ( V_116 != V_102 -> V_116 ) {
F_11 ( L_47 ,
V_116 , V_102 -> V_116 ) ;
V_10 = - V_130 ;
goto V_191;
}
V_188 = F_81 ( V_102 , V_186 , V_115 , & V_10 ) ;
if ( ! V_188 )
goto V_191;
F_11 ( L_48 ,
V_188 -> V_150 , V_188 -> V_174 , V_115 -> V_150 ) ;
if ( ( V_188 -> V_150 > V_188 -> V_174 ) ||
( V_115 -> V_150 <= V_188 -> V_174 ) )
F_40 ( V_102 -> V_138 ) ;
if ( ( V_188 -> V_150 > V_188 -> V_174 ) &&
( V_115 -> V_150 <= V_188 -> V_174 ) )
F_40 ( V_102 -> V_138 ) ;
F_49 ( V_188 , V_103 ) ;
V_189 = V_188 -> V_95 [ F_57 () ] ;
F_47 (iter, loc_cpu_old_entry, oldinfo->size)
F_45 ( V_149 ) ;
F_82 ( V_188 ) ;
if ( F_58 ( V_187 , V_103 ,
sizeof( struct V_144 ) * V_186 ) != 0 ) {
F_83 ( L_49 ) ;
}
F_60 ( V_103 ) ;
F_77 ( V_102 ) ;
return V_10 ;
V_191:
F_40 ( V_102 -> V_138 ) ;
F_77 ( V_102 ) ;
V_190:
F_60 ( V_103 ) ;
V_83:
return V_10 ;
}
static int F_84 ( struct V_175 * V_175 , const void T_6 * V_123 ,
unsigned int V_8 )
{
int V_10 ;
struct V_147 V_179 ;
struct V_90 * V_115 ;
void * V_166 ;
struct V_77 * V_149 ;
if ( F_70 ( & V_179 , V_123 , sizeof( V_179 ) ) != 0 )
return - V_167 ;
if ( V_179 . V_186 >= V_192 / sizeof( struct V_144 ) )
return - V_161 ;
V_179 . V_94 [ sizeof( V_179 . V_94 ) - 1 ] = 0 ;
V_115 = F_85 ( V_179 . V_126 ) ;
if ( ! V_115 )
return - V_161 ;
V_166 = V_115 -> V_95 [ F_57 () ] ;
if ( F_70 ( V_166 , V_123 + sizeof( V_179 ) ,
V_179 . V_126 ) != 0 ) {
V_10 = - V_167 ;
goto V_193;
}
V_10 = F_46 ( V_115 , V_166 , & V_179 ) ;
if ( V_10 != 0 )
goto V_193;
F_11 ( L_50 ) ;
V_10 = F_80 ( V_175 , V_179 . V_94 , V_179 . V_116 , V_115 ,
V_179 . V_186 , V_179 . V_103 ) ;
if ( V_10 )
goto V_194;
return 0 ;
V_194:
F_47 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_149 ) ;
V_193:
F_82 ( V_115 ) ;
return V_10 ;
}
static int F_86 ( struct V_175 * V_175 , const void T_6 * V_123 ,
unsigned int V_8 , int V_176 )
{
unsigned int V_9 , V_195 ;
struct V_196 V_179 ;
struct V_144 * V_197 ;
unsigned int V_186 ;
const char * V_94 ;
int V_126 ;
void * V_198 ;
struct V_1 * V_102 ;
const struct V_90 * V_91 ;
int V_10 = 0 ;
void * V_166 ;
struct V_77 * V_149 ;
unsigned int V_93 ;
#ifdef F_71
struct V_199 V_200 ;
if ( V_176 ) {
V_198 = & V_200 ;
V_126 = sizeof( struct V_199 ) ;
} else
#endif
{
V_198 = & V_179 ;
V_126 = sizeof( struct V_196 ) ;
}
if ( F_70 ( V_198 , V_123 , V_126 ) != 0 )
return - V_167 ;
#ifdef F_71
if ( V_176 ) {
V_186 = V_200 . V_186 ;
V_94 = V_200 . V_94 ;
} else
#endif
{
V_186 = V_179 . V_186 ;
V_94 = V_179 . V_94 ;
}
if ( V_8 != V_126 + V_186 * sizeof( struct V_144 ) )
return - V_130 ;
V_197 = F_87 ( V_8 - V_126 ) ;
if ( ! V_197 )
return - V_161 ;
if ( F_70 ( V_197 , V_123 + V_126 , V_8 - V_126 ) != 0 ) {
V_10 = - V_167 ;
goto free;
}
V_102 = F_74 ( V_175 , V_100 , V_94 ) ;
if ( F_75 ( V_102 ) ) {
V_10 = V_102 ? F_39 ( V_102 ) : - V_180 ;
goto free;
}
F_21 () ;
V_91 = V_102 -> V_91 ;
if ( V_91 -> V_150 != V_186 ) {
V_10 = - V_130 ;
goto V_201;
}
V_9 = 0 ;
V_195 = F_24 () ;
V_166 = V_91 -> V_95 [ V_195 ] ;
V_93 = F_22 () ;
F_47 (iter, loc_cpu_entry, private->size) {
F_27 ( V_149 -> V_103 , V_197 [ V_9 ] . V_158 , V_197 [ V_9 ] . V_120 ) ;
++ V_9 ;
}
F_28 ( V_93 ) ;
V_201:
F_29 () ;
F_77 ( V_102 ) ;
F_40 ( V_102 -> V_138 ) ;
free:
F_60 ( V_197 ) ;
return V_10 ;
}
static inline void F_88 ( struct V_173 * V_78 )
{
struct V_76 * V_102 ;
V_102 = F_89 ( V_78 ) ;
F_40 ( V_102 -> V_104 . V_105 . V_106 -> V_138 ) ;
}
static inline int
F_90 ( struct V_173 * V_78 ,
struct V_90 * V_115 ,
unsigned int * V_126 ,
const unsigned char * V_79 ,
const unsigned char * V_140 ,
const unsigned int * V_141 ,
const unsigned int * V_142 ,
const char * V_94 )
{
struct V_76 * V_102 ;
struct V_135 * V_106 ;
unsigned int V_172 ;
int V_10 , V_164 , V_143 ;
F_11 ( L_51 , V_78 ) ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_173 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_173 ) >= V_140 ) {
F_11 ( L_52 , V_78 , V_140 ) ;
return - V_130 ;
}
if ( V_78 -> V_128 < sizeof( struct V_173 ) +
sizeof( struct V_202 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_128 ) ;
return - V_130 ;
}
V_10 = F_33 ( (struct V_77 * ) V_78 , V_94 ) ;
if ( V_10 )
return V_10 ;
V_164 = sizeof( struct V_77 ) - sizeof( struct V_173 ) ;
V_172 = ( void * ) V_78 - ( void * ) V_79 ;
V_102 = F_89 ( V_78 ) ;
V_106 = F_37 ( V_100 , V_102 -> V_104 . V_123 . V_94 ,
V_102 -> V_104 . V_123 . V_136 ) ;
if ( F_38 ( V_106 ) ) {
F_11 ( L_53 ,
V_102 -> V_104 . V_123 . V_94 ) ;
V_10 = F_39 ( V_106 ) ;
goto V_83;
}
V_102 -> V_104 . V_105 . V_106 = V_106 ;
V_164 += F_65 ( V_106 ) ;
* V_126 += V_164 ;
V_10 = F_66 ( V_100 , V_172 , V_164 ) ;
if ( V_10 )
goto V_203;
for ( V_143 = 0 ; V_143 < V_118 ; V_143 ++ ) {
if ( ( unsigned char * ) V_78 - V_79 == V_141 [ V_143 ] )
V_115 -> V_96 [ V_143 ] = V_141 [ V_143 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_142 [ V_143 ] )
V_115 -> V_97 [ V_143 ] = V_142 [ V_143 ] ;
}
memset ( & V_78 -> V_103 , 0 , sizeof( V_78 -> V_103 ) ) ;
V_78 -> V_110 = 0 ;
return 0 ;
V_203:
F_40 ( V_102 -> V_104 . V_105 . V_106 -> V_138 ) ;
V_83:
return V_10 ;
}
static int
F_91 ( struct V_173 * V_78 , void * * V_204 ,
unsigned int * V_126 , const char * V_94 ,
struct V_90 * V_115 , unsigned char * V_79 )
{
struct V_76 * V_102 ;
struct V_135 * V_106 ;
struct V_77 * V_205 ;
unsigned int V_206 ;
int V_10 , V_143 ;
V_10 = 0 ;
V_206 = * V_126 ;
V_205 = (struct V_77 * ) * V_204 ;
memcpy ( V_205 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_205 -> V_103 , & V_78 -> V_103 , sizeof( V_78 -> V_103 ) ) ;
* V_204 += sizeof( struct V_77 ) ;
* V_126 += sizeof( struct V_77 ) - sizeof( struct V_173 ) ;
V_205 -> V_122 = V_78 -> V_122 - ( V_206 - * V_126 ) ;
V_102 = F_89 ( V_78 ) ;
V_106 = V_102 -> V_104 . V_105 . V_106 ;
F_92 ( V_102 , V_204 , V_126 ) ;
V_205 -> V_128 = V_78 -> V_128 - ( V_206 - * V_126 ) ;
for ( V_143 = 0 ; V_143 < V_118 ; V_143 ++ ) {
if ( ( unsigned char * ) V_205 - V_79 < V_115 -> V_96 [ V_143 ] )
V_115 -> V_96 [ V_143 ] -= V_206 - * V_126 ;
if ( ( unsigned char * ) V_205 - V_79 < V_115 -> V_97 [ V_143 ] )
V_115 -> V_97 [ V_143 ] -= V_206 - * V_126 ;
}
return V_10 ;
}
static int F_93 ( const char * V_94 ,
unsigned int V_116 ,
struct V_90 * * V_207 ,
void * * V_208 ,
unsigned int V_162 ,
unsigned int V_150 ,
unsigned int * V_141 ,
unsigned int * V_142 )
{
unsigned int V_9 , V_209 ;
struct V_90 * V_115 , * V_2 ;
void * V_119 , * V_117 , * V_210 ;
struct V_173 * V_211 ;
struct V_77 * V_212 ;
unsigned int V_126 ;
int V_10 = 0 ;
V_2 = * V_207 ;
V_117 = * V_208 ;
V_126 = V_162 ;
V_2 -> V_150 = V_150 ;
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
V_2 -> V_96 [ V_9 ] = 0xFFFFFFFF ;
V_2 -> V_97 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_54 , V_2 -> V_126 ) ;
V_209 = 0 ;
F_72 ( V_100 ) ;
F_68 ( V_100 , V_150 ) ;
F_47 (iter0, entry0, total_size) {
V_10 = F_90 ( V_211 , V_2 , & V_126 ,
V_117 ,
V_117 + V_162 ,
V_141 ,
V_142 ,
V_94 ) ;
if ( V_10 != 0 )
goto V_213;
++ V_209 ;
}
V_10 = - V_130 ;
if ( V_209 != V_150 ) {
F_11 ( L_55 ,
V_209 , V_150 ) ;
goto V_213;
}
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
if ( ! ( V_116 & ( 1 << V_9 ) ) )
continue;
if ( V_2 -> V_96 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_141 [ V_9 ] ) ;
goto V_213;
}
if ( V_2 -> V_97 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_142 [ V_9 ] ) ;
goto V_213;
}
}
V_10 = - V_161 ;
V_115 = F_85 ( V_126 ) ;
if ( ! V_115 )
goto V_213;
V_115 -> V_150 = V_150 ;
for ( V_9 = 0 ; V_9 < V_118 ; V_9 ++ ) {
V_115 -> V_96 [ V_9 ] = V_2 -> V_96 [ V_9 ] ;
V_115 -> V_97 [ V_9 ] = V_2 -> V_97 [ V_9 ] ;
}
V_210 = V_115 -> V_95 [ F_57 () ] ;
V_119 = V_210 ;
V_126 = V_162 ;
F_47 (iter0, entry0, total_size) {
V_10 = F_91 ( V_211 , & V_119 , & V_126 ,
V_94 , V_115 , V_210 ) ;
if ( V_10 != 0 )
break;
}
F_76 ( V_100 ) ;
F_78 ( V_100 ) ;
if ( V_10 )
goto V_193;
V_10 = - V_154 ;
if ( ! F_31 ( V_115 , V_116 , V_210 ) )
goto V_193;
V_9 = 0 ;
F_47 (iter1, entry1, newinfo->size) {
V_10 = F_34 ( V_212 , V_94 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_212 ) -> V_104 . V_123 . V_94 ,
V_152 ) == 0 )
++ V_115 -> V_153 ;
}
if ( V_10 ) {
int V_214 = V_9 ;
V_209 -= V_9 ;
F_47 (iter0, entry0, newinfo->size) {
if ( V_214 -- > 0 )
continue;
if ( V_209 -- == 0 )
break;
F_88 ( V_211 ) ;
}
F_47 (iter1, entry1, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_45 ( V_212 ) ;
}
F_82 ( V_115 ) ;
return V_10 ;
}
F_48 (i)
if ( V_115 -> V_95 [ V_9 ] && V_115 -> V_95 [ V_9 ] != V_210 )
memcpy ( V_115 -> V_95 [ V_9 ] , V_210 , V_115 -> V_126 ) ;
* V_207 = V_115 ;
* V_208 = V_210 ;
F_82 ( V_2 ) ;
return 0 ;
V_193:
F_82 ( V_115 ) ;
V_83:
F_47 (iter0, entry0, total_size) {
if ( V_209 -- == 0 )
break;
F_88 ( V_211 ) ;
}
return V_10 ;
V_213:
F_76 ( V_100 ) ;
F_78 ( V_100 ) ;
goto V_83;
}
static int F_94 ( struct V_175 * V_175 , void T_6 * V_123 ,
unsigned int V_8 )
{
int V_10 ;
struct V_215 V_179 ;
struct V_90 * V_115 ;
void * V_166 ;
struct V_77 * V_149 ;
if ( F_70 ( & V_179 , V_123 , sizeof( V_179 ) ) != 0 )
return - V_167 ;
if ( V_179 . V_126 >= V_192 / F_95 () )
return - V_161 ;
if ( V_179 . V_186 >= V_192 / sizeof( struct V_144 ) )
return - V_161 ;
V_179 . V_94 [ sizeof( V_179 . V_94 ) - 1 ] = 0 ;
V_115 = F_85 ( V_179 . V_126 ) ;
if ( ! V_115 )
return - V_161 ;
V_166 = V_115 -> V_95 [ F_57 () ] ;
if ( F_70 ( V_166 , V_123 + sizeof( V_179 ) , V_179 . V_126 ) != 0 ) {
V_10 = - V_167 ;
goto V_193;
}
V_10 = F_93 ( V_179 . V_94 , V_179 . V_116 ,
& V_115 , & V_166 , V_179 . V_126 ,
V_179 . V_151 , V_179 . V_96 ,
V_179 . V_97 ) ;
if ( V_10 != 0 )
goto V_193;
F_11 ( L_56 ) ;
V_10 = F_80 ( V_175 , V_179 . V_94 , V_179 . V_116 , V_115 ,
V_179 . V_186 , F_96 ( V_179 . V_103 ) ) ;
if ( V_10 )
goto V_194;
return 0 ;
V_194:
F_47 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_149 ) ;
V_193:
F_82 ( V_115 ) ;
return V_10 ;
}
static int F_97 ( struct V_216 * V_217 , int V_218 , void T_6 * V_123 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_217 ) -> V_219 , V_220 ) )
return - V_221 ;
switch ( V_218 ) {
case V_222 :
V_10 = F_94 ( F_99 ( V_217 ) , V_123 , V_8 ) ;
break;
case V_223 :
V_10 = F_86 ( F_99 ( V_217 ) , V_123 , V_8 , 1 ) ;
break;
default:
F_11 ( L_57 , V_218 ) ;
V_10 = - V_130 ;
}
return V_10 ;
}
static int F_100 ( struct V_77 * V_78 , void T_6 * * V_204 ,
T_7 * V_126 ,
struct V_144 * V_103 ,
unsigned int V_9 )
{
struct V_76 * V_102 ;
struct V_173 T_6 * V_224 ;
T_8 V_122 , V_128 ;
T_7 V_206 ;
int V_10 ;
V_206 = * V_126 ;
V_224 = (struct V_173 T_6 * ) * V_204 ;
if ( F_58 ( V_224 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_58 ( & V_224 -> V_103 , & V_103 [ V_9 ] ,
sizeof( V_103 [ V_9 ] ) ) != 0 )
return - V_167 ;
* V_204 += sizeof( struct V_173 ) ;
* V_126 -= sizeof( struct V_77 ) - sizeof( struct V_173 ) ;
V_122 = V_78 -> V_122 - ( V_206 - * V_126 ) ;
V_102 = F_15 ( V_78 ) ;
V_10 = F_101 ( V_102 , V_204 , V_126 ) ;
if ( V_10 )
return V_10 ;
V_128 = V_78 -> V_128 - ( V_206 - * V_126 ) ;
if ( F_102 ( V_122 , & V_224 -> V_122 ) != 0 ||
F_102 ( V_128 , & V_224 -> V_128 ) != 0 )
return - V_167 ;
return 0 ;
}
static int F_103 ( unsigned int V_162 ,
struct V_1 * V_84 ,
void T_6 * V_163 )
{
struct V_144 * V_103 ;
const struct V_90 * V_91 = V_84 -> V_91 ;
void T_6 * V_119 ;
unsigned int V_126 ;
int V_10 = 0 ;
void * V_166 ;
unsigned int V_9 = 0 ;
struct V_77 * V_149 ;
V_103 = F_53 ( V_84 ) ;
if ( F_38 ( V_103 ) )
return F_39 ( V_103 ) ;
V_166 = V_91 -> V_95 [ F_57 () ] ;
V_119 = V_163 ;
V_126 = V_162 ;
F_47 (iter, loc_cpu_entry, total_size) {
V_10 = F_100 ( V_149 , & V_119 ,
& V_126 , V_103 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_60 ( V_103 ) ;
return V_10 ;
}
static int F_104 ( struct V_175 * V_175 ,
struct V_225 T_6 * V_182 ,
int * V_8 )
{
int V_10 ;
struct V_225 V_183 ;
struct V_1 * V_102 ;
if ( * V_8 < sizeof( V_183 ) ) {
F_11 ( L_58 , * V_8 , sizeof( V_183 ) ) ;
return - V_130 ;
}
if ( F_70 ( & V_183 , V_182 , sizeof( V_183 ) ) != 0 )
return - V_167 ;
if ( * V_8 != sizeof( struct V_225 ) + V_183 . V_126 ) {
F_11 ( L_59 ,
* V_8 , sizeof( V_183 ) + V_183 . V_126 ) ;
return - V_130 ;
}
F_72 ( V_100 ) ;
V_102 = F_74 ( V_175 , V_100 , V_183 . V_94 ) ;
if ( ! F_75 ( V_102 ) ) {
const struct V_90 * V_91 = V_102 -> V_91 ;
struct V_90 V_2 ;
F_11 ( L_45 , V_91 -> V_150 ) ;
V_10 = F_67 ( V_91 , & V_2 ) ;
if ( ! V_10 && V_183 . V_126 == V_2 . V_126 ) {
V_10 = F_103 ( V_91 -> V_126 ,
V_102 , V_182 -> V_184 ) ;
} else if ( ! V_10 ) {
F_11 ( L_60 ,
V_91 -> V_126 , V_183 . V_126 ) ;
V_10 = - V_185 ;
}
F_76 ( V_100 ) ;
F_40 ( V_102 -> V_138 ) ;
F_77 ( V_102 ) ;
} else
V_10 = V_102 ? F_39 ( V_102 ) : - V_180 ;
F_78 ( V_100 ) ;
return V_10 ;
}
static int F_105 ( struct V_216 * V_217 , int V_218 , void T_6 * V_123 ,
int * V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_217 ) -> V_219 , V_220 ) )
return - V_221 ;
switch ( V_218 ) {
case V_226 :
V_10 = F_69 ( F_99 ( V_217 ) , V_123 , V_8 , 1 ) ;
break;
case V_227 :
V_10 = F_104 ( F_99 ( V_217 ) , V_123 , V_8 ) ;
break;
default:
V_10 = F_106 ( V_217 , V_218 , V_123 , V_8 ) ;
}
return V_10 ;
}
static int F_107 ( struct V_216 * V_217 , int V_218 , void T_6 * V_123 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_217 ) -> V_219 , V_220 ) )
return - V_221 ;
switch ( V_218 ) {
case V_222 :
V_10 = F_84 ( F_99 ( V_217 ) , V_123 , V_8 ) ;
break;
case V_223 :
V_10 = F_86 ( F_99 ( V_217 ) , V_123 , V_8 , 0 ) ;
break;
default:
F_11 ( L_57 , V_218 ) ;
V_10 = - V_130 ;
}
return V_10 ;
}
static int F_106 ( struct V_216 * V_217 , int V_218 , void T_6 * V_123 , int * V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_217 ) -> V_219 , V_220 ) )
return - V_221 ;
switch ( V_218 ) {
case V_226 :
V_10 = F_69 ( F_99 ( V_217 ) , V_123 , V_8 , 0 ) ;
break;
case V_227 :
V_10 = F_79 ( F_99 ( V_217 ) , V_123 , V_8 ) ;
break;
case V_228 : {
struct V_229 V_230 ;
if ( * V_8 != sizeof( V_230 ) ) {
V_10 = - V_130 ;
break;
}
if ( F_70 ( & V_230 , V_123 , sizeof( V_230 ) ) != 0 ) {
V_10 = - V_167 ;
break;
}
V_230 . V_94 [ sizeof( V_230 . V_94 ) - 1 ] = 0 ;
F_73 ( F_108 ( V_100 , V_230 . V_94 ,
V_230 . V_136 , 1 , & V_10 ) ,
L_61 , V_230 . V_94 ) ;
break;
}
default:
F_11 ( L_62 , V_218 ) ;
V_10 = - V_130 ;
}
return V_10 ;
}
struct V_1 * F_109 ( struct V_175 * V_175 ,
const struct V_1 * V_84 ,
const struct V_147 * V_148 )
{
int V_10 ;
struct V_90 * V_115 ;
struct V_90 V_231 = { 0 } ;
void * V_166 ;
struct V_1 * V_232 ;
V_115 = F_85 ( V_148 -> V_126 ) ;
if ( ! V_115 ) {
V_10 = - V_161 ;
goto V_83;
}
V_166 = V_115 -> V_95 [ F_57 () ] ;
memcpy ( V_166 , V_148 -> V_95 , V_148 -> V_126 ) ;
V_10 = F_46 ( V_115 , V_166 , V_148 ) ;
F_11 ( L_63 , V_10 ) ;
if ( V_10 != 0 )
goto V_233;
V_232 = F_110 ( V_175 , V_84 , & V_231 , V_115 ) ;
if ( F_38 ( V_232 ) ) {
V_10 = F_39 ( V_232 ) ;
goto V_233;
}
return V_232 ;
V_233:
F_82 ( V_115 ) ;
V_83:
return F_55 ( V_10 ) ;
}
void F_111 ( struct V_1 * V_84 )
{
struct V_90 * V_91 ;
void * V_166 ;
struct V_234 * V_235 = V_84 -> V_138 ;
struct V_77 * V_149 ;
V_91 = F_112 ( V_84 ) ;
V_166 = V_91 -> V_95 [ F_57 () ] ;
F_47 (iter, loc_cpu_entry, private->size)
F_45 ( V_149 ) ;
if ( V_91 -> V_150 > V_91 -> V_174 )
F_40 ( V_235 ) ;
F_82 ( V_91 ) ;
}
static int T_9 F_113 ( struct V_175 * V_175 )
{
return F_114 ( V_175 , V_100 ) ;
}
static void T_10 F_115 ( struct V_175 * V_175 )
{
F_116 ( V_175 , V_100 ) ;
}
static int T_11 F_117 ( void )
{
int V_10 ;
V_10 = F_118 ( & V_236 ) ;
if ( V_10 < 0 )
goto V_237;
V_10 = F_119 ( V_238 , F_120 ( V_238 ) ) ;
if ( V_10 < 0 )
goto V_239;
V_10 = F_121 ( & V_240 ) ;
if ( V_10 < 0 )
goto V_241;
F_122 ( V_242 L_64 ) ;
return 0 ;
V_241:
F_123 ( V_238 , F_120 ( V_238 ) ) ;
V_239:
F_124 ( & V_236 ) ;
V_237:
return V_10 ;
}
static void T_12 F_125 ( void )
{
F_126 ( & V_240 ) ;
F_123 ( V_238 , F_120 ( V_238 ) ) ;
F_124 ( & V_236 ) ;
}
