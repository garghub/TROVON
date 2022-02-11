void * F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , V_4 ) ;
}
int
F_3 ( T_1 V_5 )
{
return ( V_5 == V_6 ) ||
( V_5 == V_7 ) ||
( V_5 == V_8 ) ||
( V_5 == V_9 ) ||
( V_5 == V_10 ) ||
( V_5 == V_11 ) ||
( V_5 == V_12 ) ;
}
static inline bool
F_4 ( const struct V_13 * V_14 ,
const char * V_15 ,
const char * V_16 ,
const struct V_17 * V_18 ,
unsigned int * V_19 ,
int * V_20 , bool * V_21 )
{
unsigned long V_22 ;
const struct V_23 * V_24 = F_5 ( V_14 ) ;
#define F_6 ( bool , T_2 ) ((bool) ^ !!(ip6info->invflags & (invflg)))
if ( F_6 ( F_7 ( & V_24 -> V_25 , & V_18 -> V_26 ,
& V_18 -> V_27 ) , V_28 ) ||
F_6 ( F_7 ( & V_24 -> V_29 , & V_18 -> V_30 ,
& V_18 -> V_31 ) , V_32 ) ) {
F_8 ( L_1 ) ;
return false ;
}
V_22 = F_9 ( V_15 , V_18 -> V_33 , V_18 -> V_34 ) ;
if ( F_6 ( V_22 != 0 , V_35 ) ) {
F_8 ( L_2 ,
V_15 , V_18 -> V_33 ,
V_18 -> V_36 & V_35 ? L_3 : L_4 ) ;
return false ;
}
V_22 = F_9 ( V_16 , V_18 -> V_37 , V_18 -> V_38 ) ;
if ( F_6 ( V_22 != 0 , V_39 ) ) {
F_8 ( L_5 ,
V_16 , V_18 -> V_37 ,
V_18 -> V_36 & V_39 ? L_3 : L_4 ) ;
return false ;
}
if( ( V_18 -> V_40 & V_41 ) ) {
int V_42 ;
unsigned short V_43 ;
V_42 = F_10 ( V_14 , V_19 , - 1 , & V_43 ) ;
if ( V_42 < 0 ) {
if ( V_43 == 0 )
* V_21 = true ;
return false ;
}
* V_20 = V_43 ;
F_8 ( L_6 ,
V_42 ,
V_18 -> V_36 & V_44 ? L_7 : L_4 ,
V_18 -> V_45 ) ;
if ( V_18 -> V_45 == V_42 ) {
if( V_18 -> V_36 & V_44 ) {
return false ;
}
return true ;
}
if ( ( V_18 -> V_45 != 0 ) &&
! ( V_18 -> V_36 & V_44 ) )
return false ;
}
return true ;
}
static bool
F_11 ( const struct V_17 * V_24 )
{
if ( V_24 -> V_40 & ~ V_46 ) {
F_12 ( L_8 ,
V_24 -> V_40 & ~ V_46 ) ;
return false ;
}
if ( V_24 -> V_36 & ~ V_47 ) {
F_12 ( L_9 ,
V_24 -> V_36 & ~ V_47 ) ;
return false ;
}
return true ;
}
static unsigned int
F_13 ( struct V_13 * V_14 , const struct V_48 * V_49 )
{
if ( F_14 () )
F_15 ( L_10 , ( const char * ) V_49 -> V_50 ) ;
return V_51 ;
}
static inline struct V_52 *
F_16 ( const void * V_53 , unsigned int V_54 )
{
return (struct V_52 * ) ( V_53 + V_54 ) ;
}
static inline bool F_17 ( const struct V_17 * V_24 )
{
static const struct V_17 V_55 ;
return memcmp ( V_24 , & V_55 , sizeof( V_55 ) ) == 0 ;
}
static inline const struct V_56 *
F_18 ( const struct V_52 * V_57 )
{
return F_19 ( (struct V_52 * ) V_57 ) ;
}
static inline int
F_20 ( const struct V_52 * V_58 , const struct V_52 * V_57 ,
const char * V_59 , const char * * V_60 ,
const char * * V_61 , unsigned int * V_62 )
{
const struct V_63 * V_64 = ( void * ) F_18 ( V_58 ) ;
if ( strcmp ( V_64 -> V_65 . V_66 . V_67 . V_65 -> V_68 , V_69 ) == 0 ) {
* V_60 = V_64 -> V_65 . V_70 ;
( * V_62 ) = 0 ;
} else if ( V_58 == V_57 ) {
( * V_62 ) ++ ;
if ( V_58 -> V_71 == sizeof( struct V_52 ) &&
strcmp ( V_64 -> V_65 . V_66 . V_67 . V_65 -> V_68 ,
V_72 ) == 0 &&
V_64 -> V_73 < 0 &&
F_17 ( & V_58 -> V_24 ) ) {
* V_61 = * V_60 == V_59
? V_74 [ V_75 ]
: V_74 [ V_76 ] ;
}
return 1 ;
} else
( * V_62 ) ++ ;
return 0 ;
}
static void F_21 ( const struct V_13 * V_14 ,
unsigned int V_77 ,
const struct V_78 * V_79 ,
const struct V_78 * V_80 ,
const char * V_81 ,
const struct V_82 * V_83 ,
const struct V_52 * V_57 )
{
const void * V_84 ;
const struct V_52 * V_85 ;
const char * V_59 , * V_60 , * V_61 ;
const struct V_52 * V_86 ;
unsigned int V_62 = 0 ;
V_84 = V_83 -> V_87 [ F_22 () ] ;
V_85 = F_16 ( V_84 , V_83 -> V_88 [ V_77 ] ) ;
V_59 = V_60 = V_89 [ V_77 ] ;
V_61 = V_74 [ V_90 ] ;
F_23 (iter, root, private->size - private->hook_entry[hook])
if ( F_20 ( V_86 , V_57 , V_59 ,
& V_60 , & V_61 , & V_62 ) != 0 )
break;
F_24 ( V_91 , V_77 , V_14 , V_79 , V_80 , & V_92 ,
L_11 ,
V_81 , V_60 , V_61 , V_62 ) ;
}
unsigned int
F_25 ( struct V_13 * V_14 ,
unsigned int V_77 ,
const struct V_78 * V_79 ,
const struct V_78 * V_80 ,
struct V_1 * V_93 )
{
static const char V_94 [ V_95 ] V_96 ( ( F_26 ( sizeof( long ) ) ) ) ;
unsigned int V_73 = V_51 ;
const char * V_15 , * V_16 ;
const void * V_84 ;
struct V_52 * V_57 , * * V_97 ;
unsigned int * V_98 , V_99 , V_100 ;
const struct V_82 * V_83 ;
struct V_48 V_101 ;
unsigned int V_102 ;
V_15 = V_79 ? V_79 -> V_68 : V_94 ;
V_16 = V_80 ? V_80 -> V_68 : V_94 ;
V_101 . V_21 = false ;
V_101 . V_79 = V_79 ;
V_101 . V_80 = V_80 ;
V_101 . V_103 = V_104 ;
V_101 . V_105 = V_77 ;
F_27 ( V_93 -> V_106 & ( 1 << V_77 ) ) ;
F_28 () ;
V_102 = F_29 () ;
V_83 = V_93 -> V_83 ;
V_100 = F_22 () ;
V_84 = V_83 -> V_87 [ V_100 ] ;
V_97 = (struct V_52 * * ) V_83 -> V_97 [ V_100 ] ;
V_98 = F_30 ( V_83 -> V_98 , V_100 ) ;
V_99 = * V_98 ;
V_57 = F_16 ( V_84 , V_83 -> V_88 [ V_77 ] ) ;
do {
const struct V_56 * V_64 ;
const struct V_107 * V_108 ;
F_27 ( V_57 ) ;
if ( ! F_4 ( V_14 , V_15 , V_16 , & V_57 -> V_24 ,
& V_101 . V_109 , & V_101 . V_20 , & V_101 . V_21 ) ) {
V_110:
V_57 = F_31 ( V_57 ) ;
continue;
}
F_32 (ematch, e) {
V_101 . V_111 = V_108 -> V_66 . V_67 . V_111 ;
V_101 . V_112 = V_108 -> V_70 ;
if ( ! V_101 . V_111 -> V_111 ( V_14 , & V_101 ) )
goto V_110;
}
F_33 ( V_57 -> V_113 , V_14 -> V_114 , 1 ) ;
V_64 = F_18 ( V_57 ) ;
F_27 ( V_64 -> V_66 . V_67 . V_65 ) ;
#if F_34 ( V_115 ) || \
F_34 ( V_116 )
if ( F_35 ( V_14 -> V_117 ) )
F_21 ( V_14 , V_77 , V_79 , V_80 ,
V_93 -> V_68 , V_83 , V_57 ) ;
#endif
if ( ! V_64 -> V_66 . V_67 . V_65 -> V_65 ) {
int V_118 ;
V_118 = ( (struct V_63 * ) V_64 ) -> V_73 ;
if ( V_118 < 0 ) {
if ( V_118 != V_119 ) {
V_73 = ( unsigned ) ( - V_118 ) - 1 ;
break;
}
if ( * V_98 <= V_99 )
V_57 = F_16 ( V_84 ,
V_83 -> V_120 [ V_77 ] ) ;
else
V_57 = F_31 ( V_97 [ -- * V_98 ] ) ;
continue;
}
if ( V_84 + V_118 != F_31 ( V_57 ) &&
! ( V_57 -> V_24 . V_40 & V_121 ) ) {
if ( * V_98 >= V_83 -> V_122 ) {
V_73 = V_51 ;
break;
}
V_97 [ ( * V_98 ) ++ ] = V_57 ;
}
V_57 = F_16 ( V_84 , V_118 ) ;
continue;
}
V_101 . V_65 = V_64 -> V_66 . V_67 . V_65 ;
V_101 . V_50 = V_64 -> V_70 ;
V_73 = V_64 -> V_66 . V_67 . V_65 -> V_65 ( V_14 , & V_101 ) ;
if ( V_73 == V_123 )
V_57 = F_31 ( V_57 ) ;
else
break;
} while ( ! V_101 . V_21 );
* V_98 = V_99 ;
F_36 ( V_102 ) ;
F_37 () ;
#ifdef F_38
return V_124 ;
#else
if ( V_101 . V_21 )
return V_51 ;
else return V_73 ;
#endif
}
static int
F_39 ( const struct V_82 * V_125 ,
unsigned int V_106 , void * V_126 )
{
unsigned int V_77 ;
for ( V_77 = 0 ; V_77 < V_127 ; V_77 ++ ) {
unsigned int V_128 = V_125 -> V_88 [ V_77 ] ;
struct V_52 * V_57 = (struct V_52 * ) ( V_126 + V_128 ) ;
if ( ! ( V_106 & ( 1 << V_77 ) ) )
continue;
V_57 -> V_113 . V_129 = V_128 ;
for (; ; ) {
const struct V_63 * V_64
= ( void * ) F_18 ( V_57 ) ;
int V_130 = V_57 -> V_131 & ( 1 << V_77 ) ;
if ( V_57 -> V_131 & ( 1 << V_127 ) ) {
F_40 ( L_12 ,
V_77 , V_128 , V_57 -> V_131 ) ;
return 0 ;
}
V_57 -> V_131 |= ( ( 1 << V_77 ) | ( 1 << V_127 ) ) ;
if ( ( V_57 -> V_71 == sizeof( struct V_52 ) &&
( strcmp ( V_64 -> V_65 . V_66 . V_132 . V_68 ,
V_72 ) == 0 ) &&
V_64 -> V_73 < 0 &&
F_17 ( & V_57 -> V_24 ) ) || V_130 ) {
unsigned int V_133 , V_134 ;
if ( ( strcmp ( V_64 -> V_65 . V_66 . V_132 . V_68 ,
V_72 ) == 0 ) &&
V_64 -> V_73 < - V_135 - 1 ) {
F_12 ( L_13
L_14 ,
V_64 -> V_73 ) ;
return 0 ;
}
do {
V_57 -> V_131 ^= ( 1 << V_127 ) ;
#ifdef F_41
if ( V_57 -> V_131
& ( 1 << V_127 ) ) {
F_12 ( L_15
L_16
L_17 ,
V_77 , V_128 ) ;
}
#endif
V_133 = V_128 ;
V_128 = V_57 -> V_113 . V_129 ;
V_57 -> V_113 . V_129 = 0 ;
if ( V_128 == V_133 )
goto V_136;
V_57 = (struct V_52 * )
( V_126 + V_128 ) ;
} while ( V_133 == V_128 + V_57 -> V_137 );
V_134 = V_57 -> V_137 ;
V_57 = (struct V_52 * )
( V_126 + V_128 + V_134 ) ;
V_57 -> V_113 . V_129 = V_128 ;
V_128 += V_134 ;
} else {
int V_138 = V_64 -> V_73 ;
if ( strcmp ( V_64 -> V_65 . V_66 . V_132 . V_68 ,
V_72 ) == 0 &&
V_138 >= 0 ) {
if ( V_138 > V_125 -> V_134 -
sizeof( struct V_52 ) ) {
F_12 ( L_18
L_19 ,
V_138 ) ;
return 0 ;
}
F_12 ( L_20 ,
V_128 , V_138 ) ;
} else {
V_138 = V_128 + V_57 -> V_137 ;
}
V_57 = (struct V_52 * )
( V_126 + V_138 ) ;
V_57 -> V_113 . V_129 = V_128 ;
V_128 = V_138 ;
}
}
V_136:
F_12 ( L_21 , V_77 ) ;
}
return 1 ;
}
static void F_42 ( struct V_107 * V_139 , struct V_140 * V_140 )
{
struct V_141 V_49 ;
V_49 . V_140 = V_140 ;
V_49 . V_111 = V_139 -> V_66 . V_67 . V_111 ;
V_49 . V_112 = V_139 -> V_70 ;
V_49 . V_103 = V_104 ;
if ( V_49 . V_111 -> V_142 != NULL )
V_49 . V_111 -> V_142 ( & V_49 ) ;
F_43 ( V_49 . V_111 -> V_143 ) ;
}
static int
F_44 ( const struct V_52 * V_57 , const char * V_68 )
{
const struct V_56 * V_64 ;
if ( ! F_11 ( & V_57 -> V_24 ) ) {
F_12 ( L_22 , V_57 , V_68 ) ;
return - V_144 ;
}
if ( V_57 -> V_71 + sizeof( struct V_56 ) >
V_57 -> V_137 )
return - V_144 ;
V_64 = F_18 ( V_57 ) ;
if ( V_57 -> V_71 + V_64 -> V_66 . V_145 > V_57 -> V_137 )
return - V_144 ;
return 0 ;
}
static int F_45 ( struct V_107 * V_139 , struct V_146 * V_49 )
{
const struct V_17 * V_24 = V_49 -> V_147 ;
int V_22 ;
V_49 -> V_111 = V_139 -> V_66 . V_67 . V_111 ;
V_49 -> V_112 = V_139 -> V_70 ;
V_22 = F_46 ( V_49 , V_139 -> V_66 . V_148 - sizeof( * V_139 ) ,
V_24 -> V_45 , V_24 -> V_36 & V_44 ) ;
if ( V_22 < 0 ) {
F_12 ( L_23 ,
V_49 . V_111 -> V_68 ) ;
return V_22 ;
}
return 0 ;
}
static int
F_47 ( struct V_107 * V_139 , struct V_146 * V_49 )
{
struct V_149 * V_111 ;
int V_22 ;
V_111 = F_48 ( V_104 , V_139 -> V_66 . V_132 . V_68 ,
V_139 -> V_66 . V_132 . V_150 ) ;
if ( F_49 ( V_111 ) ) {
F_12 ( L_24 , V_139 -> V_66 . V_132 . V_68 ) ;
return F_50 ( V_111 ) ;
}
V_139 -> V_66 . V_67 . V_111 = V_111 ;
V_22 = F_45 ( V_139 , V_49 ) ;
if ( V_22 )
goto V_151;
return 0 ;
V_151:
F_43 ( V_139 -> V_66 . V_67 . V_111 -> V_143 ) ;
return V_22 ;
}
static int F_51 ( struct V_52 * V_57 , struct V_140 * V_140 , const char * V_68 )
{
struct V_56 * V_64 = F_19 ( V_57 ) ;
struct V_152 V_49 = {
. V_140 = V_140 ,
. V_93 = V_68 ,
. V_147 = V_57 ,
. V_65 = V_64 -> V_66 . V_67 . V_65 ,
. V_50 = V_64 -> V_70 ,
. V_153 = V_57 -> V_131 ,
. V_103 = V_104 ,
} ;
int V_22 ;
V_64 = F_19 ( V_57 ) ;
V_22 = F_52 ( & V_49 , V_64 -> V_66 . V_145 - sizeof( * V_64 ) ,
V_57 -> V_24 . V_45 , V_57 -> V_24 . V_36 & V_44 ) ;
if ( V_22 < 0 ) {
F_12 ( L_23 ,
V_64 -> V_66 . V_67 . V_65 -> V_68 ) ;
return V_22 ;
}
return 0 ;
}
static int
F_53 ( struct V_52 * V_57 , struct V_140 * V_140 , const char * V_68 ,
unsigned int V_134 )
{
struct V_56 * V_64 ;
struct V_154 * V_65 ;
int V_22 ;
unsigned int V_155 ;
struct V_146 V_156 ;
struct V_107 * V_108 ;
V_22 = F_44 ( V_57 , V_68 ) ;
if ( V_22 )
return V_22 ;
V_155 = 0 ;
V_156 . V_140 = V_140 ;
V_156 . V_93 = V_68 ;
V_156 . V_147 = & V_57 -> V_24 ;
V_156 . V_153 = V_57 -> V_131 ;
V_156 . V_103 = V_104 ;
F_32 (ematch, e) {
V_22 = F_47 ( V_108 , & V_156 ) ;
if ( V_22 != 0 )
goto V_157;
++ V_155 ;
}
V_64 = F_19 ( V_57 ) ;
V_65 = F_54 ( V_104 , V_64 -> V_66 . V_132 . V_68 ,
V_64 -> V_66 . V_132 . V_150 ) ;
if ( F_49 ( V_65 ) ) {
F_12 ( L_25 , V_64 -> V_66 . V_132 . V_68 ) ;
V_22 = F_50 ( V_65 ) ;
goto V_157;
}
V_64 -> V_66 . V_67 . V_65 = V_65 ;
V_22 = F_51 ( V_57 , V_140 , V_68 ) ;
if ( V_22 )
goto V_151;
return 0 ;
V_151:
F_43 ( V_64 -> V_66 . V_67 . V_65 -> V_143 ) ;
V_157:
F_32 (ematch, e) {
if ( V_155 -- == 0 )
break;
F_42 ( V_108 , V_140 ) ;
}
return V_22 ;
}
static bool F_55 ( const struct V_52 * V_57 )
{
const struct V_56 * V_64 ;
unsigned int V_73 ;
if ( ! F_17 ( & V_57 -> V_24 ) )
return false ;
V_64 = F_18 ( V_57 ) ;
if ( strcmp ( V_64 -> V_66 . V_132 . V_68 , V_72 ) != 0 )
return false ;
V_73 = ( (struct V_63 * ) V_64 ) -> V_73 ;
V_73 = - V_73 - 1 ;
return V_73 == V_51 || V_73 == V_124 ;
}
static int
F_56 ( struct V_52 * V_57 ,
struct V_82 * V_125 ,
const unsigned char * V_53 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
unsigned int V_106 )
{
unsigned int V_161 ;
if ( ( unsigned long ) V_57 % F_57 ( struct V_52 ) != 0 ||
( unsigned char * ) V_57 + sizeof( struct V_52 ) >= V_158 ) {
F_12 ( L_26 , V_57 ) ;
return - V_144 ;
}
if ( V_57 -> V_137
< sizeof( struct V_52 ) + sizeof( struct V_56 ) ) {
F_12 ( L_27 ,
V_57 , V_57 -> V_137 ) ;
return - V_144 ;
}
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ! ( V_106 & ( 1 << V_161 ) ) )
continue;
if ( ( unsigned char * ) V_57 - V_53 == V_159 [ V_161 ] )
V_125 -> V_88 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_57 - V_53 == V_160 [ V_161 ] ) {
if ( ! F_55 ( V_57 ) ) {
F_40 ( L_28
L_29
L_30 ) ;
return - V_144 ;
}
V_125 -> V_120 [ V_161 ] = V_160 [ V_161 ] ;
}
}
V_57 -> V_113 = ( (struct V_162 ) { 0 , 0 } ) ;
V_57 -> V_131 = 0 ;
return 0 ;
}
static void F_58 ( struct V_52 * V_57 , struct V_140 * V_140 )
{
struct V_163 V_49 ;
struct V_56 * V_64 ;
struct V_107 * V_108 ;
F_32 (ematch, e)
F_42 ( V_108 , V_140 ) ;
V_64 = F_19 ( V_57 ) ;
V_49 . V_140 = V_140 ;
V_49 . V_65 = V_64 -> V_66 . V_67 . V_65 ;
V_49 . V_50 = V_64 -> V_70 ;
V_49 . V_103 = V_104 ;
if ( V_49 . V_65 -> V_142 != NULL )
V_49 . V_65 -> V_142 ( & V_49 ) ;
F_43 ( V_49 . V_65 -> V_143 ) ;
}
static int
F_59 ( struct V_140 * V_140 , struct V_82 * V_125 , void * V_126 ,
const struct V_164 * V_165 )
{
struct V_52 * V_86 ;
unsigned int V_166 ;
int V_22 = 0 ;
V_125 -> V_134 = V_165 -> V_134 ;
V_125 -> V_167 = V_165 -> V_168 ;
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
V_125 -> V_88 [ V_166 ] = 0xFFFFFFFF ;
V_125 -> V_120 [ V_166 ] = 0xFFFFFFFF ;
}
F_12 ( L_31 , V_125 -> V_134 ) ;
V_166 = 0 ;
F_23 (iter, entry0, newinfo->size) {
V_22 = F_56 ( V_86 , V_125 , V_126 ,
V_126 + V_165 -> V_134 ,
V_165 -> V_88 ,
V_165 -> V_120 ,
V_165 -> V_106 ) ;
if ( V_22 != 0 )
return V_22 ;
++ V_166 ;
if ( strcmp ( F_19 ( V_86 ) -> V_66 . V_132 . V_68 ,
V_69 ) == 0 )
++ V_125 -> V_122 ;
}
if ( V_166 != V_165 -> V_168 ) {
F_12 ( L_32 ,
V_166 , V_165 -> V_168 ) ;
return - V_144 ;
}
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
if ( ! ( V_165 -> V_106 & ( 1 << V_166 ) ) )
continue;
if ( V_125 -> V_88 [ V_166 ] == 0xFFFFFFFF ) {
F_12 ( L_33 ,
V_166 , V_165 -> V_88 [ V_166 ] ) ;
return - V_144 ;
}
if ( V_125 -> V_120 [ V_166 ] == 0xFFFFFFFF ) {
F_12 ( L_34 ,
V_166 , V_165 -> V_120 [ V_166 ] ) ;
return - V_144 ;
}
}
if ( ! F_39 ( V_125 , V_165 -> V_106 , V_126 ) )
return - V_169 ;
V_166 = 0 ;
F_23 (iter, entry0, newinfo->size) {
V_22 = F_53 ( V_86 , V_140 , V_165 -> V_68 , V_165 -> V_134 ) ;
if ( V_22 != 0 )
break;
++ V_166 ;
}
if ( V_22 != 0 ) {
F_23 (iter, entry0, newinfo->size) {
if ( V_166 -- == 0 )
break;
F_58 ( V_86 , V_140 ) ;
}
return V_22 ;
}
F_60 (i) {
if ( V_125 -> V_87 [ V_166 ] && V_125 -> V_87 [ V_166 ] != V_126 )
memcpy ( V_125 -> V_87 [ V_166 ] , V_126 , V_125 -> V_134 ) ;
}
return V_22 ;
}
static void
F_61 ( const struct V_82 * V_64 ,
struct V_162 V_113 [] )
{
struct V_52 * V_86 ;
unsigned int V_100 ;
unsigned int V_166 ;
F_60 (cpu) {
T_3 * V_58 = & F_62 ( V_170 , V_100 ) ;
V_166 = 0 ;
F_23 (iter, t->entries[cpu], t->size) {
T_4 V_171 , V_129 ;
unsigned int V_172 ;
do {
V_172 = F_63 ( V_58 ) ;
V_171 = V_86 -> V_113 . V_171 ;
V_129 = V_86 -> V_113 . V_129 ;
} while ( F_64 ( V_58 , V_172 ) );
F_33 ( V_113 [ V_166 ] , V_171 , V_129 ) ;
++ V_166 ;
}
}
}
static struct V_162 * F_65 ( const struct V_1 * V_93 )
{
unsigned int V_173 ;
struct V_162 * V_113 ;
const struct V_82 * V_83 = V_93 -> V_83 ;
V_173 = sizeof( struct V_162 ) * V_83 -> V_167 ;
V_113 = F_66 ( V_173 ) ;
if ( V_113 == NULL )
return F_67 ( - V_174 ) ;
F_61 ( V_83 , V_113 ) ;
return V_113 ;
}
static int
F_68 ( unsigned int V_175 ,
const struct V_1 * V_93 ,
void T_5 * V_176 )
{
unsigned int V_177 , V_178 ;
const struct V_52 * V_57 ;
struct V_162 * V_113 ;
const struct V_82 * V_83 = V_93 -> V_83 ;
int V_22 = 0 ;
const void * V_179 ;
V_113 = F_65 ( V_93 ) ;
if ( F_49 ( V_113 ) )
return F_50 ( V_113 ) ;
V_179 = V_83 -> V_87 [ F_69 () ] ;
if ( F_70 ( V_176 , V_179 , V_175 ) != 0 ) {
V_22 = - V_180 ;
goto V_181;
}
for ( V_177 = 0 , V_178 = 0 ; V_177 < V_175 ; V_177 += V_57 -> V_137 , V_178 ++ ) {
unsigned int V_166 ;
const struct V_107 * V_139 ;
const struct V_56 * V_64 ;
V_57 = (struct V_52 * ) ( V_179 + V_177 ) ;
if ( F_70 ( V_176 + V_177
+ F_71 ( struct V_52 , V_113 ) ,
& V_113 [ V_178 ] ,
sizeof( V_113 [ V_178 ] ) ) != 0 ) {
V_22 = - V_180 ;
goto V_181;
}
for ( V_166 = sizeof( struct V_52 ) ;
V_166 < V_57 -> V_71 ;
V_166 += V_139 -> V_66 . V_148 ) {
V_139 = ( void * ) V_57 + V_166 ;
if ( F_70 ( V_176 + V_177 + V_166
+ F_71 ( struct V_107 ,
V_66 . V_132 . V_68 ) ,
V_139 -> V_66 . V_67 . V_111 -> V_68 ,
strlen ( V_139 -> V_66 . V_67 . V_111 -> V_68 ) + 1 )
!= 0 ) {
V_22 = - V_180 ;
goto V_181;
}
}
V_64 = F_18 ( V_57 ) ;
if ( F_70 ( V_176 + V_177 + V_57 -> V_71
+ F_71 ( struct V_56 ,
V_66 . V_132 . V_68 ) ,
V_64 -> V_66 . V_67 . V_65 -> V_68 ,
strlen ( V_64 -> V_66 . V_67 . V_65 -> V_68 ) + 1 ) != 0 ) {
V_22 = - V_180 ;
goto V_181;
}
}
V_181:
F_72 ( V_113 ) ;
return V_22 ;
}
static void F_73 ( void * V_31 , const void * V_27 )
{
int V_118 = * ( V_182 * ) V_27 ;
if ( V_118 > 0 )
V_118 += F_74 ( V_91 , V_118 ) ;
memcpy ( V_31 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_75 ( void T_5 * V_31 , const void * V_27 )
{
V_182 V_183 = * ( int * ) V_27 ;
if ( V_183 > 0 )
V_183 -= F_74 ( V_91 , V_183 ) ;
return F_70 ( V_31 , & V_183 , sizeof( V_183 ) ) ? - V_180 : 0 ;
}
static int F_76 ( const struct V_52 * V_57 ,
const struct V_82 * V_2 ,
const void * V_53 , struct V_82 * V_125 )
{
const struct V_107 * V_108 ;
const struct V_56 * V_64 ;
unsigned int V_184 ;
int V_177 , V_166 , V_22 ;
V_177 = sizeof( struct V_52 ) - sizeof( struct V_185 ) ;
V_184 = ( void * ) V_57 - V_53 ;
F_32 (ematch, e)
V_177 += F_77 ( V_108 -> V_66 . V_67 . V_111 ) ;
V_64 = F_18 ( V_57 ) ;
V_177 += F_78 ( V_64 -> V_66 . V_67 . V_65 ) ;
V_125 -> V_134 -= V_177 ;
V_22 = F_79 ( V_91 , V_184 , V_177 ) ;
if ( V_22 )
return V_22 ;
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
if ( V_2 -> V_88 [ V_166 ] &&
( V_57 < (struct V_52 * ) ( V_53 + V_2 -> V_88 [ V_166 ] ) ) )
V_125 -> V_88 [ V_166 ] -= V_177 ;
if ( V_2 -> V_120 [ V_166 ] &&
( V_57 < (struct V_52 * ) ( V_53 + V_2 -> V_120 [ V_166 ] ) ) )
V_125 -> V_120 [ V_166 ] -= V_177 ;
}
return 0 ;
}
static int F_80 ( const struct V_82 * V_2 ,
struct V_82 * V_125 )
{
struct V_52 * V_86 ;
void * V_179 ;
int V_22 ;
if ( ! V_125 || ! V_2 )
return - V_144 ;
memcpy ( V_125 , V_2 , F_71 ( struct V_82 , V_87 ) ) ;
V_125 -> V_186 = 0 ;
V_179 = V_2 -> V_87 [ F_69 () ] ;
F_81 ( V_91 , V_2 -> V_167 ) ;
F_23 (iter, loc_cpu_entry, info->size) {
V_22 = F_76 ( V_86 , V_2 , V_179 , V_125 ) ;
if ( V_22 != 0 )
return V_22 ;
}
return 0 ;
}
static int F_82 ( struct V_140 * V_140 , void T_5 * V_132 ,
const int * V_114 , int V_187 )
{
char V_68 [ V_188 ] ;
struct V_1 * V_64 ;
int V_22 ;
if ( * V_114 != sizeof( struct V_189 ) ) {
F_12 ( L_35 , * V_114 ,
sizeof( struct V_189 ) ) ;
return - V_144 ;
}
if ( F_83 ( V_68 , V_132 , sizeof( V_68 ) ) != 0 )
return - V_180 ;
V_68 [ V_188 - 1 ] = '\0' ;
#ifdef F_84
if ( V_187 )
F_85 ( V_91 ) ;
#endif
V_64 = F_86 ( F_87 ( V_140 , V_91 , V_68 ) ,
L_36 , V_68 ) ;
if ( V_64 && ! F_49 ( V_64 ) ) {
struct V_189 V_2 ;
const struct V_82 * V_83 = V_64 -> V_83 ;
#ifdef F_84
struct V_82 V_190 ;
if ( V_187 ) {
V_22 = F_80 ( V_83 , & V_190 ) ;
F_88 ( V_91 ) ;
V_83 = & V_190 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_106 = V_64 -> V_106 ;
memcpy ( V_2 . V_88 , V_83 -> V_88 ,
sizeof( V_2 . V_88 ) ) ;
memcpy ( V_2 . V_120 , V_83 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_168 = V_83 -> V_167 ;
V_2 . V_134 = V_83 -> V_134 ;
strcpy ( V_2 . V_68 , V_68 ) ;
if ( F_70 ( V_132 , & V_2 , * V_114 ) != 0 )
V_22 = - V_180 ;
else
V_22 = 0 ;
F_89 ( V_64 ) ;
F_43 ( V_64 -> V_143 ) ;
} else
V_22 = V_64 ? F_50 ( V_64 ) : - V_191 ;
#ifdef F_84
if ( V_187 )
F_90 ( V_91 ) ;
#endif
return V_22 ;
}
static int
F_91 ( struct V_140 * V_140 , struct V_192 T_5 * V_193 ,
const int * V_114 )
{
int V_22 ;
struct V_192 V_194 ;
struct V_1 * V_64 ;
if ( * V_114 < sizeof( V_194 ) ) {
F_12 ( L_37 , * V_114 , sizeof( V_194 ) ) ;
return - V_144 ;
}
if ( F_83 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_180 ;
if ( * V_114 != sizeof( struct V_192 ) + V_194 . V_134 ) {
F_12 ( L_38 ,
* V_114 , sizeof( V_194 ) + V_194 . V_134 ) ;
return - V_144 ;
}
V_64 = F_87 ( V_140 , V_91 , V_194 . V_68 ) ;
if ( V_64 && ! F_49 ( V_64 ) ) {
struct V_82 * V_83 = V_64 -> V_83 ;
F_12 ( L_39 , V_83 -> V_167 ) ;
if ( V_194 . V_134 == V_83 -> V_134 )
V_22 = F_68 ( V_83 -> V_134 ,
V_64 , V_193 -> V_195 ) ;
else {
F_12 ( L_40 ,
V_83 -> V_134 , V_194 . V_134 ) ;
V_22 = - V_196 ;
}
F_43 ( V_64 -> V_143 ) ;
F_89 ( V_64 ) ;
} else
V_22 = V_64 ? F_50 ( V_64 ) : - V_191 ;
return V_22 ;
}
static int
F_92 ( struct V_140 * V_140 , const char * V_68 , unsigned int V_106 ,
struct V_82 * V_125 , unsigned int V_197 ,
void T_5 * V_198 )
{
int V_22 ;
struct V_1 * V_64 ;
struct V_82 * V_199 ;
struct V_162 * V_113 ;
const void * V_200 ;
struct V_52 * V_86 ;
V_22 = 0 ;
V_113 = F_66 ( V_197 * sizeof( struct V_162 ) ) ;
if ( ! V_113 ) {
V_22 = - V_174 ;
goto V_80;
}
V_64 = F_86 ( F_87 ( V_140 , V_91 , V_68 ) ,
L_36 , V_68 ) ;
if ( ! V_64 || F_49 ( V_64 ) ) {
V_22 = V_64 ? F_50 ( V_64 ) : - V_191 ;
goto V_201;
}
if ( V_106 != V_64 -> V_106 ) {
F_12 ( L_41 ,
V_106 , V_64 -> V_106 ) ;
V_22 = - V_144 ;
goto V_202;
}
V_199 = F_93 ( V_64 , V_197 , V_125 , & V_22 ) ;
if ( ! V_199 )
goto V_202;
F_12 ( L_42 ,
V_199 -> V_167 , V_199 -> V_186 , V_125 -> V_167 ) ;
if ( ( V_199 -> V_167 > V_199 -> V_186 ) ||
( V_125 -> V_167 <= V_199 -> V_186 ) )
F_43 ( V_64 -> V_143 ) ;
if ( ( V_199 -> V_167 > V_199 -> V_186 ) &&
( V_125 -> V_167 <= V_199 -> V_186 ) )
F_43 ( V_64 -> V_143 ) ;
F_61 ( V_199 , V_113 ) ;
V_200 = V_199 -> V_87 [ F_69 () ] ;
F_23 (iter, loc_cpu_old_entry, oldinfo->size)
F_58 ( V_86 , V_140 ) ;
F_94 ( V_199 ) ;
if ( F_70 ( V_198 , V_113 ,
sizeof( struct V_162 ) * V_197 ) != 0 )
V_22 = - V_180 ;
F_72 ( V_113 ) ;
F_89 ( V_64 ) ;
return V_22 ;
V_202:
F_43 ( V_64 -> V_143 ) ;
F_89 ( V_64 ) ;
V_201:
F_72 ( V_113 ) ;
V_80:
return V_22 ;
}
static int
F_95 ( struct V_140 * V_140 , const void T_5 * V_132 , unsigned int V_114 )
{
int V_22 ;
struct V_164 V_190 ;
struct V_82 * V_125 ;
void * V_179 ;
struct V_52 * V_86 ;
if ( F_83 ( & V_190 , V_132 , sizeof( V_190 ) ) != 0 )
return - V_180 ;
if ( V_190 . V_197 >= V_203 / sizeof( struct V_162 ) )
return - V_174 ;
V_190 . V_68 [ sizeof( V_190 . V_68 ) - 1 ] = 0 ;
V_125 = F_96 ( V_190 . V_134 ) ;
if ( ! V_125 )
return - V_174 ;
V_179 = V_125 -> V_87 [ F_69 () ] ;
if ( F_83 ( V_179 , V_132 + sizeof( V_190 ) ,
V_190 . V_134 ) != 0 ) {
V_22 = - V_180 ;
goto V_204;
}
V_22 = F_59 ( V_140 , V_125 , V_179 , & V_190 ) ;
if ( V_22 != 0 )
goto V_204;
F_12 ( L_43 ) ;
V_22 = F_92 ( V_140 , V_190 . V_68 , V_190 . V_106 , V_125 ,
V_190 . V_197 , V_190 . V_113 ) ;
if ( V_22 )
goto V_205;
return 0 ;
V_205:
F_23 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_86 , V_140 ) ;
V_204:
F_94 ( V_125 ) ;
return V_22 ;
}
static int
F_97 ( struct V_140 * V_140 , const void T_5 * V_132 , unsigned int V_114 ,
int V_187 )
{
unsigned int V_166 , V_206 ;
struct V_207 V_190 ;
struct V_162 * V_208 ;
unsigned int V_197 ;
char * V_68 ;
int V_134 ;
void * V_209 ;
struct V_1 * V_64 ;
const struct V_82 * V_83 ;
int V_22 = 0 ;
const void * V_179 ;
struct V_52 * V_86 ;
unsigned int V_102 ;
#ifdef F_84
struct V_210 V_211 ;
if ( V_187 ) {
V_209 = & V_211 ;
V_134 = sizeof( struct V_210 ) ;
} else
#endif
{
V_209 = & V_190 ;
V_134 = sizeof( struct V_207 ) ;
}
if ( F_83 ( V_209 , V_132 , V_134 ) != 0 )
return - V_180 ;
#ifdef F_84
if ( V_187 ) {
V_197 = V_211 . V_197 ;
V_68 = V_211 . V_68 ;
} else
#endif
{
V_197 = V_190 . V_197 ;
V_68 = V_190 . V_68 ;
}
if ( V_114 != V_134 + V_197 * sizeof( struct V_162 ) )
return - V_144 ;
V_208 = F_98 ( V_114 - V_134 ) ;
if ( ! V_208 )
return - V_174 ;
if ( F_83 ( V_208 , V_132 + V_134 , V_114 - V_134 ) != 0 ) {
V_22 = - V_180 ;
goto free;
}
V_64 = F_87 ( V_140 , V_91 , V_68 ) ;
if ( ! V_64 || F_49 ( V_64 ) ) {
V_22 = V_64 ? F_50 ( V_64 ) : - V_191 ;
goto free;
}
F_28 () ;
V_83 = V_64 -> V_83 ;
if ( V_83 -> V_167 != V_197 ) {
V_22 = - V_144 ;
goto V_212;
}
V_166 = 0 ;
V_206 = F_22 () ;
V_102 = F_29 () ;
V_179 = V_83 -> V_87 [ V_206 ] ;
F_23 (iter, loc_cpu_entry, private->size) {
F_33 ( V_86 -> V_113 , V_208 [ V_166 ] . V_171 , V_208 [ V_166 ] . V_129 ) ;
++ V_166 ;
}
F_36 ( V_102 ) ;
V_212:
F_37 () ;
F_89 ( V_64 ) ;
F_43 ( V_64 -> V_143 ) ;
free:
F_72 ( V_208 ) ;
return V_22 ;
}
static int
F_99 ( struct V_52 * V_57 , void T_5 * * V_213 ,
unsigned int * V_134 , struct V_162 * V_113 ,
unsigned int V_166 )
{
struct V_56 * V_64 ;
struct V_185 T_5 * V_214 ;
T_6 V_71 , V_137 ;
T_7 V_215 ;
const struct V_107 * V_108 ;
int V_22 = 0 ;
V_215 = * V_134 ;
V_214 = (struct V_185 T_5 * ) * V_213 ;
if ( F_70 ( V_214 , V_57 , sizeof( struct V_52 ) ) != 0 ||
F_70 ( & V_214 -> V_113 , & V_113 [ V_166 ] ,
sizeof( V_113 [ V_166 ] ) ) != 0 )
return - V_180 ;
* V_213 += sizeof( struct V_185 ) ;
* V_134 -= sizeof( struct V_52 ) - sizeof( struct V_185 ) ;
F_32 (ematch, e) {
V_22 = F_100 ( V_108 , V_213 , V_134 ) ;
if ( V_22 != 0 )
return V_22 ;
}
V_71 = V_57 -> V_71 - ( V_215 - * V_134 ) ;
V_64 = F_19 ( V_57 ) ;
V_22 = F_101 ( V_64 , V_213 , V_134 ) ;
if ( V_22 )
return V_22 ;
V_137 = V_57 -> V_137 - ( V_215 - * V_134 ) ;
if ( F_102 ( V_71 , & V_214 -> V_71 ) != 0 ||
F_102 ( V_137 , & V_214 -> V_137 ) != 0 )
return - V_180 ;
return 0 ;
}
static int
F_103 ( struct V_107 * V_139 ,
const char * V_68 ,
const struct V_17 * V_24 ,
unsigned int V_216 ,
int * V_134 )
{
struct V_149 * V_111 ;
V_111 = F_48 ( V_104 , V_139 -> V_66 . V_132 . V_68 ,
V_139 -> V_66 . V_132 . V_150 ) ;
if ( F_49 ( V_111 ) ) {
F_12 ( L_44 ,
V_139 -> V_66 . V_132 . V_68 ) ;
return F_50 ( V_111 ) ;
}
V_139 -> V_66 . V_67 . V_111 = V_111 ;
* V_134 += F_77 ( V_111 ) ;
return 0 ;
}
static void F_104 ( struct V_185 * V_57 )
{
struct V_56 * V_64 ;
struct V_107 * V_108 ;
F_32 (ematch, e)
F_43 ( V_108 -> V_66 . V_67 . V_111 -> V_143 ) ;
V_64 = F_105 ( V_57 ) ;
F_43 ( V_64 -> V_66 . V_67 . V_65 -> V_143 ) ;
}
static int
F_106 ( struct V_185 * V_57 ,
struct V_82 * V_125 ,
unsigned int * V_134 ,
const unsigned char * V_53 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
const char * V_68 )
{
struct V_107 * V_108 ;
struct V_56 * V_64 ;
struct V_154 * V_65 ;
unsigned int V_184 ;
unsigned int V_155 ;
int V_22 , V_177 , V_161 ;
F_12 ( L_45 , V_57 ) ;
if ( ( unsigned long ) V_57 % F_57 ( struct V_185 ) != 0 ||
( unsigned char * ) V_57 + sizeof( struct V_185 ) >= V_158 ) {
F_12 ( L_46 , V_57 , V_158 ) ;
return - V_144 ;
}
if ( V_57 -> V_137 < sizeof( struct V_185 ) +
sizeof( struct V_217 ) ) {
F_12 ( L_27 ,
V_57 , V_57 -> V_137 ) ;
return - V_144 ;
}
V_22 = F_44 ( (struct V_52 * ) V_57 , V_68 ) ;
if ( V_22 )
return V_22 ;
V_177 = sizeof( struct V_52 ) - sizeof( struct V_185 ) ;
V_184 = ( void * ) V_57 - ( void * ) V_53 ;
V_155 = 0 ;
F_32 (ematch, e) {
V_22 = F_103 ( V_108 , V_68 ,
& V_57 -> V_24 , V_57 -> V_131 , & V_177 ) ;
if ( V_22 != 0 )
goto V_218;
++ V_155 ;
}
V_64 = F_105 ( V_57 ) ;
V_65 = F_54 ( V_104 , V_64 -> V_66 . V_132 . V_68 ,
V_64 -> V_66 . V_132 . V_150 ) ;
if ( F_49 ( V_65 ) ) {
F_12 ( L_47 ,
V_64 -> V_66 . V_132 . V_68 ) ;
V_22 = F_50 ( V_65 ) ;
goto V_218;
}
V_64 -> V_66 . V_67 . V_65 = V_65 ;
V_177 += F_78 ( V_65 ) ;
* V_134 += V_177 ;
V_22 = F_79 ( V_91 , V_184 , V_177 ) ;
if ( V_22 )
goto V_80;
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ( unsigned char * ) V_57 - V_53 == V_159 [ V_161 ] )
V_125 -> V_88 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_57 - V_53 == V_160 [ V_161 ] )
V_125 -> V_120 [ V_161 ] = V_160 [ V_161 ] ;
}
memset ( & V_57 -> V_113 , 0 , sizeof( V_57 -> V_113 ) ) ;
V_57 -> V_131 = 0 ;
return 0 ;
V_80:
F_43 ( V_64 -> V_66 . V_67 . V_65 -> V_143 ) ;
V_218:
F_32 (ematch, e) {
if ( V_155 -- == 0 )
break;
F_43 ( V_108 -> V_66 . V_67 . V_111 -> V_143 ) ;
}
return V_22 ;
}
static int
F_107 ( struct V_185 * V_57 , void * * V_213 ,
unsigned int * V_134 , const char * V_68 ,
struct V_82 * V_125 , unsigned char * V_53 )
{
struct V_56 * V_64 ;
struct V_52 * V_219 ;
unsigned int V_215 ;
int V_22 , V_161 ;
struct V_107 * V_108 ;
V_22 = 0 ;
V_215 = * V_134 ;
V_219 = (struct V_52 * ) * V_213 ;
memcpy ( V_219 , V_57 , sizeof( struct V_52 ) ) ;
memcpy ( & V_219 -> V_113 , & V_57 -> V_113 , sizeof( V_57 -> V_113 ) ) ;
* V_213 += sizeof( struct V_52 ) ;
* V_134 += sizeof( struct V_52 ) - sizeof( struct V_185 ) ;
F_32 (ematch, e) {
V_22 = F_108 ( V_108 , V_213 , V_134 ) ;
if ( V_22 != 0 )
return V_22 ;
}
V_219 -> V_71 = V_57 -> V_71 - ( V_215 - * V_134 ) ;
V_64 = F_105 ( V_57 ) ;
F_109 ( V_64 , V_213 , V_134 ) ;
V_219 -> V_137 = V_57 -> V_137 - ( V_215 - * V_134 ) ;
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ( unsigned char * ) V_219 - V_53 < V_125 -> V_88 [ V_161 ] )
V_125 -> V_88 [ V_161 ] -= V_215 - * V_134 ;
if ( ( unsigned char * ) V_219 - V_53 < V_125 -> V_120 [ V_161 ] )
V_125 -> V_120 [ V_161 ] -= V_215 - * V_134 ;
}
return V_22 ;
}
static int F_110 ( struct V_52 * V_57 , struct V_140 * V_140 ,
const char * V_68 )
{
unsigned int V_155 ;
int V_22 = 0 ;
struct V_146 V_156 ;
struct V_107 * V_108 ;
V_155 = 0 ;
V_156 . V_140 = V_140 ;
V_156 . V_93 = V_68 ;
V_156 . V_147 = & V_57 -> V_24 ;
V_156 . V_153 = V_57 -> V_131 ;
V_156 . V_103 = V_104 ;
F_32 (ematch, e) {
V_22 = F_45 ( V_108 , & V_156 ) ;
if ( V_22 != 0 )
goto V_157;
++ V_155 ;
}
V_22 = F_51 ( V_57 , V_140 , V_68 ) ;
if ( V_22 )
goto V_157;
return 0 ;
V_157:
F_32 (ematch, e) {
if ( V_155 -- == 0 )
break;
F_42 ( V_108 , V_140 ) ;
}
return V_22 ;
}
static int
F_111 ( struct V_140 * V_140 ,
const char * V_68 ,
unsigned int V_106 ,
struct V_82 * * V_220 ,
void * * V_221 ,
unsigned int V_175 ,
unsigned int V_167 ,
unsigned int * V_159 ,
unsigned int * V_160 )
{
unsigned int V_166 , V_155 ;
struct V_82 * V_125 , * V_2 ;
void * V_128 , * V_126 , * V_222 ;
struct V_185 * V_223 ;
struct V_52 * V_224 ;
unsigned int V_134 ;
int V_22 = 0 ;
V_2 = * V_220 ;
V_126 = * V_221 ;
V_134 = V_175 ;
V_2 -> V_167 = V_167 ;
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
V_2 -> V_88 [ V_166 ] = 0xFFFFFFFF ;
V_2 -> V_120 [ V_166 ] = 0xFFFFFFFF ;
}
F_12 ( L_48 , V_2 -> V_134 ) ;
V_155 = 0 ;
F_85 ( V_91 ) ;
F_81 ( V_91 , V_167 ) ;
F_23 (iter0, entry0, total_size) {
V_22 = F_106 ( V_223 , V_2 , & V_134 ,
V_126 ,
V_126 + V_175 ,
V_159 ,
V_160 ,
V_68 ) ;
if ( V_22 != 0 )
goto V_225;
++ V_155 ;
}
V_22 = - V_144 ;
if ( V_155 != V_167 ) {
F_12 ( L_49 ,
V_155 , V_167 ) ;
goto V_225;
}
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
if ( ! ( V_106 & ( 1 << V_166 ) ) )
continue;
if ( V_2 -> V_88 [ V_166 ] == 0xFFFFFFFF ) {
F_12 ( L_33 ,
V_166 , V_159 [ V_166 ] ) ;
goto V_225;
}
if ( V_2 -> V_120 [ V_166 ] == 0xFFFFFFFF ) {
F_12 ( L_34 ,
V_166 , V_160 [ V_166 ] ) ;
goto V_225;
}
}
V_22 = - V_174 ;
V_125 = F_96 ( V_134 ) ;
if ( ! V_125 )
goto V_225;
V_125 -> V_167 = V_167 ;
for ( V_166 = 0 ; V_166 < V_127 ; V_166 ++ ) {
V_125 -> V_88 [ V_166 ] = V_2 -> V_88 [ V_166 ] ;
V_125 -> V_120 [ V_166 ] = V_2 -> V_120 [ V_166 ] ;
}
V_222 = V_125 -> V_87 [ F_69 () ] ;
V_128 = V_222 ;
V_134 = V_175 ;
F_23 (iter0, entry0, total_size) {
V_22 = F_107 ( V_223 , & V_128 , & V_134 ,
V_68 , V_125 , V_222 ) ;
if ( V_22 != 0 )
break;
}
F_88 ( V_91 ) ;
F_90 ( V_91 ) ;
if ( V_22 )
goto V_204;
V_22 = - V_169 ;
if ( ! F_39 ( V_125 , V_106 , V_222 ) )
goto V_204;
V_166 = 0 ;
F_23 (iter1, entry1, newinfo->size) {
V_22 = F_110 ( V_224 , V_140 , V_68 ) ;
if ( V_22 != 0 )
break;
++ V_166 ;
if ( strcmp ( F_19 ( V_224 ) -> V_66 . V_132 . V_68 ,
V_69 ) == 0 )
++ V_125 -> V_122 ;
}
if ( V_22 ) {
int V_226 = V_166 ;
V_155 -= V_166 ;
F_23 (iter0, entry0, newinfo->size) {
if ( V_226 -- > 0 )
continue;
if ( V_155 -- == 0 )
break;
F_104 ( V_223 ) ;
}
F_23 (iter1, entry1, newinfo->size) {
if ( V_166 -- == 0 )
break;
F_58 ( V_224 , V_140 ) ;
}
F_94 ( V_125 ) ;
return V_22 ;
}
F_60 (i)
if ( V_125 -> V_87 [ V_166 ] && V_125 -> V_87 [ V_166 ] != V_222 )
memcpy ( V_125 -> V_87 [ V_166 ] , V_222 , V_125 -> V_134 ) ;
* V_220 = V_125 ;
* V_221 = V_222 ;
F_94 ( V_2 ) ;
return 0 ;
V_204:
F_94 ( V_125 ) ;
V_80:
F_23 (iter0, entry0, total_size) {
if ( V_155 -- == 0 )
break;
F_104 ( V_223 ) ;
}
return V_22 ;
V_225:
F_88 ( V_91 ) ;
F_90 ( V_91 ) ;
goto V_80;
}
static int
F_112 ( struct V_140 * V_140 , void T_5 * V_132 , unsigned int V_114 )
{
int V_22 ;
struct V_227 V_190 ;
struct V_82 * V_125 ;
void * V_179 ;
struct V_52 * V_86 ;
if ( F_83 ( & V_190 , V_132 , sizeof( V_190 ) ) != 0 )
return - V_180 ;
if ( V_190 . V_134 >= V_203 / F_113 () )
return - V_174 ;
if ( V_190 . V_197 >= V_203 / sizeof( struct V_162 ) )
return - V_174 ;
V_190 . V_68 [ sizeof( V_190 . V_68 ) - 1 ] = 0 ;
V_125 = F_96 ( V_190 . V_134 ) ;
if ( ! V_125 )
return - V_174 ;
V_179 = V_125 -> V_87 [ F_69 () ] ;
if ( F_83 ( V_179 , V_132 + sizeof( V_190 ) ,
V_190 . V_134 ) != 0 ) {
V_22 = - V_180 ;
goto V_204;
}
V_22 = F_111 ( V_140 , V_190 . V_68 , V_190 . V_106 ,
& V_125 , & V_179 , V_190 . V_134 ,
V_190 . V_168 , V_190 . V_88 ,
V_190 . V_120 ) ;
if ( V_22 != 0 )
goto V_204;
F_12 ( L_50 ) ;
V_22 = F_92 ( V_140 , V_190 . V_68 , V_190 . V_106 , V_125 ,
V_190 . V_197 , F_114 ( V_190 . V_113 ) ) ;
if ( V_22 )
goto V_205;
return 0 ;
V_205:
F_23 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_86 , V_140 ) ;
V_204:
F_94 ( V_125 ) ;
return V_22 ;
}
static int
F_115 ( struct V_228 * V_229 , int V_230 , void T_5 * V_132 ,
unsigned int V_114 )
{
int V_22 ;
if ( ! F_116 ( V_231 ) )
return - V_232 ;
switch ( V_230 ) {
case V_233 :
V_22 = F_112 ( F_117 ( V_229 ) , V_132 , V_114 ) ;
break;
case V_234 :
V_22 = F_97 ( F_117 ( V_229 ) , V_132 , V_114 , 1 ) ;
break;
default:
F_12 ( L_51 , V_230 ) ;
V_22 = - V_144 ;
}
return V_22 ;
}
static int
F_118 ( unsigned int V_175 , struct V_1 * V_93 ,
void T_5 * V_176 )
{
struct V_162 * V_113 ;
const struct V_82 * V_83 = V_93 -> V_83 ;
void T_5 * V_128 ;
unsigned int V_134 ;
int V_22 = 0 ;
const void * V_179 ;
unsigned int V_166 = 0 ;
struct V_52 * V_86 ;
V_113 = F_65 ( V_93 ) ;
if ( F_49 ( V_113 ) )
return F_50 ( V_113 ) ;
V_179 = V_83 -> V_87 [ F_69 () ] ;
V_128 = V_176 ;
V_134 = V_175 ;
F_23 (iter, loc_cpu_entry, total_size) {
V_22 = F_99 ( V_86 , & V_128 ,
& V_134 , V_113 , V_166 ++ ) ;
if ( V_22 != 0 )
break;
}
F_72 ( V_113 ) ;
return V_22 ;
}
static int
F_119 ( struct V_140 * V_140 , struct V_235 T_5 * V_193 ,
int * V_114 )
{
int V_22 ;
struct V_235 V_194 ;
struct V_1 * V_64 ;
if ( * V_114 < sizeof( V_194 ) ) {
F_12 ( L_52 , * V_114 , sizeof( V_194 ) ) ;
return - V_144 ;
}
if ( F_83 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_180 ;
if ( * V_114 != sizeof( struct V_235 ) + V_194 . V_134 ) {
F_12 ( L_53 ,
* V_114 , sizeof( V_194 ) + V_194 . V_134 ) ;
return - V_144 ;
}
F_85 ( V_91 ) ;
V_64 = F_87 ( V_140 , V_91 , V_194 . V_68 ) ;
if ( V_64 && ! F_49 ( V_64 ) ) {
const struct V_82 * V_83 = V_64 -> V_83 ;
struct V_82 V_2 ;
F_12 ( L_39 , V_83 -> V_167 ) ;
V_22 = F_80 ( V_83 , & V_2 ) ;
if ( ! V_22 && V_194 . V_134 == V_2 . V_134 ) {
V_22 = F_118 ( V_83 -> V_134 ,
V_64 , V_193 -> V_195 ) ;
} else if ( ! V_22 ) {
F_12 ( L_54 ,
V_83 -> V_134 , V_194 . V_134 ) ;
V_22 = - V_196 ;
}
F_88 ( V_91 ) ;
F_43 ( V_64 -> V_143 ) ;
F_89 ( V_64 ) ;
} else
V_22 = V_64 ? F_50 ( V_64 ) : - V_191 ;
F_90 ( V_91 ) ;
return V_22 ;
}
static int
F_120 ( struct V_228 * V_229 , int V_230 , void T_5 * V_132 , int * V_114 )
{
int V_22 ;
if ( ! F_116 ( V_231 ) )
return - V_232 ;
switch ( V_230 ) {
case V_236 :
V_22 = F_82 ( F_117 ( V_229 ) , V_132 , V_114 , 1 ) ;
break;
case V_237 :
V_22 = F_119 ( F_117 ( V_229 ) , V_132 , V_114 ) ;
break;
default:
V_22 = F_121 ( V_229 , V_230 , V_132 , V_114 ) ;
}
return V_22 ;
}
static int
F_122 ( struct V_228 * V_229 , int V_230 , void T_5 * V_132 , unsigned int V_114 )
{
int V_22 ;
if ( ! F_116 ( V_231 ) )
return - V_232 ;
switch ( V_230 ) {
case V_233 :
V_22 = F_95 ( F_117 ( V_229 ) , V_132 , V_114 ) ;
break;
case V_234 :
V_22 = F_97 ( F_117 ( V_229 ) , V_132 , V_114 , 0 ) ;
break;
default:
F_12 ( L_51 , V_230 ) ;
V_22 = - V_144 ;
}
return V_22 ;
}
static int
F_121 ( struct V_228 * V_229 , int V_230 , void T_5 * V_132 , int * V_114 )
{
int V_22 ;
if ( ! F_116 ( V_231 ) )
return - V_232 ;
switch ( V_230 ) {
case V_236 :
V_22 = F_82 ( F_117 ( V_229 ) , V_132 , V_114 , 0 ) ;
break;
case V_237 :
V_22 = F_91 ( F_117 ( V_229 ) , V_132 , V_114 ) ;
break;
case V_238 :
case V_239 : {
struct V_240 V_241 ;
int V_65 ;
if ( * V_114 != sizeof( V_241 ) ) {
V_22 = - V_144 ;
break;
}
if ( F_83 ( & V_241 , V_132 , sizeof( V_241 ) ) != 0 ) {
V_22 = - V_180 ;
break;
}
V_241 . V_68 [ sizeof( V_241 . V_68 ) - 1 ] = 0 ;
if ( V_230 == V_239 )
V_65 = 1 ;
else
V_65 = 0 ;
F_86 ( F_123 ( V_91 , V_241 . V_68 ,
V_241 . V_150 ,
V_65 , & V_22 ) ,
L_55 , V_241 . V_68 ) ;
break;
}
default:
F_12 ( L_56 , V_230 ) ;
V_22 = - V_144 ;
}
return V_22 ;
}
struct V_1 * F_124 ( struct V_140 * V_140 ,
const struct V_1 * V_93 ,
const struct V_164 * V_165 )
{
int V_22 ;
struct V_82 * V_125 ;
struct V_82 V_242 = { 0 } ;
void * V_179 ;
struct V_1 * V_243 ;
V_125 = F_96 ( V_165 -> V_134 ) ;
if ( ! V_125 ) {
V_22 = - V_174 ;
goto V_80;
}
V_179 = V_125 -> V_87 [ F_69 () ] ;
memcpy ( V_179 , V_165 -> V_87 , V_165 -> V_134 ) ;
V_22 = F_59 ( V_140 , V_125 , V_179 , V_165 ) ;
if ( V_22 != 0 )
goto V_244;
V_243 = F_125 ( V_140 , V_93 , & V_242 , V_125 ) ;
if ( F_49 ( V_243 ) ) {
V_22 = F_50 ( V_243 ) ;
goto V_244;
}
return V_243 ;
V_244:
F_94 ( V_125 ) ;
V_80:
return F_67 ( V_22 ) ;
}
void F_126 ( struct V_140 * V_140 , struct V_1 * V_93 )
{
struct V_82 * V_83 ;
void * V_179 ;
struct V_245 * V_246 = V_93 -> V_143 ;
struct V_52 * V_86 ;
V_83 = F_127 ( V_93 ) ;
V_179 = V_83 -> V_87 [ F_69 () ] ;
F_23 (iter, loc_cpu_entry, private->size)
F_58 ( V_86 , V_140 ) ;
if ( V_83 -> V_167 > V_83 -> V_186 )
F_43 ( V_246 ) ;
F_94 ( V_83 ) ;
}
static inline bool
F_128 ( T_8 V_247 , T_8 V_248 , T_8 V_249 ,
T_8 type , T_8 V_250 ,
bool V_251 )
{
return ( type == V_247 && V_250 >= V_248 && V_250 <= V_249 )
^ V_251 ;
}
static bool
F_129 ( const struct V_13 * V_14 , struct V_48 * V_49 )
{
const struct V_252 * V_253 ;
struct V_252 V_254 ;
const struct V_255 * V_256 = V_49 -> V_112 ;
if ( V_49 -> V_20 != 0 )
return false ;
V_253 = F_130 ( V_14 , V_49 -> V_109 , sizeof( V_254 ) , & V_254 ) ;
if ( V_253 == NULL ) {
F_12 ( L_57 ) ;
V_49 -> V_21 = true ;
return false ;
}
return F_128 ( V_256 -> type ,
V_256 -> V_250 [ 0 ] ,
V_256 -> V_250 [ 1 ] ,
V_253 -> V_257 , V_253 -> V_258 ,
! ! ( V_256 -> V_36 & V_259 ) ) ;
}
static int F_131 ( const struct V_146 * V_49 )
{
const struct V_255 * V_256 = V_49 -> V_112 ;
return ( V_256 -> V_36 & ~ V_259 ) ? - V_144 : 0 ;
}
static int T_9 F_132 ( struct V_140 * V_140 )
{
return F_133 ( V_140 , V_104 ) ;
}
static void T_10 F_134 ( struct V_140 * V_140 )
{
F_135 ( V_140 , V_104 ) ;
}
static int T_11 F_136 ( void )
{
int V_22 ;
V_22 = F_137 ( & V_260 ) ;
if ( V_22 < 0 )
goto V_261;
V_22 = F_138 ( V_262 , F_139 ( V_262 ) ) ;
if ( V_22 < 0 )
goto V_263;
V_22 = F_140 ( V_264 , F_139 ( V_264 ) ) ;
if ( V_22 < 0 )
goto V_265;
V_22 = F_141 ( & V_266 ) ;
if ( V_22 < 0 )
goto V_267;
F_15 ( L_58 ) ;
return 0 ;
V_267:
F_142 ( V_264 , F_139 ( V_264 ) ) ;
V_265:
F_143 ( V_262 , F_139 ( V_262 ) ) ;
V_263:
F_144 ( & V_260 ) ;
V_261:
return V_22 ;
}
static void T_12 F_145 ( void )
{
F_146 ( & V_266 ) ;
F_142 ( V_264 , F_139 ( V_264 ) ) ;
F_143 ( V_262 , F_139 ( V_262 ) ) ;
F_144 ( & V_260 ) ;
}
int F_10 ( const struct V_13 * V_14 , unsigned int * V_54 ,
int V_65 , unsigned short * V_20 )
{
unsigned int V_172 = F_147 ( V_14 ) + sizeof( struct V_23 ) ;
T_1 V_5 = F_5 ( V_14 ) -> V_5 ;
unsigned int V_114 = V_14 -> V_114 - V_172 ;
if ( V_20 )
* V_20 = 0 ;
while ( V_5 != V_65 ) {
struct V_268 V_269 , * V_270 ;
unsigned int V_271 ;
if ( ( ! F_148 ( V_5 ) ) || V_5 == V_272 ) {
if ( V_65 < 0 )
break;
return - V_191 ;
}
V_270 = F_130 ( V_14 , V_172 , sizeof( V_269 ) , & V_269 ) ;
if ( V_270 == NULL )
return - V_273 ;
if ( V_5 == V_274 ) {
unsigned short V_43 ;
T_13 * V_275 ;
V_275 = F_130 ( V_14 ,
V_172 + F_71 ( struct V_276 ,
V_277 ) ,
sizeof( V_43 ) ,
& V_43 ) ;
if ( V_275 == NULL )
return - V_273 ;
V_43 = F_149 ( * V_275 ) & ~ 0x7 ;
if ( V_43 ) {
if ( V_65 < 0 &&
( ( ! F_148 ( V_270 -> V_5 ) ) ||
V_270 -> V_5 == V_272 ) ) {
if ( V_20 )
* V_20 = V_43 ;
return V_270 -> V_5 ;
}
return - V_191 ;
}
V_271 = 8 ;
} else if ( V_5 == V_278 )
V_271 = ( V_270 -> V_271 + 2 ) << 2 ;
else
V_271 = F_150 ( V_270 ) ;
V_5 = V_270 -> V_5 ;
V_114 -= V_271 ;
V_172 += V_271 ;
}
* V_54 = V_172 ;
return V_5 ;
}
