void * F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , V_4 ) ;
}
static inline bool
F_3 ( const struct V_5 * V_6 ,
const char * V_7 ,
const char * V_8 ,
const struct V_9 * V_10 ,
unsigned int * V_11 ,
int * V_12 , bool * V_13 )
{
unsigned long V_14 ;
const struct V_15 * V_16 = F_4 ( V_6 ) ;
#define F_5 ( bool , T_1 ) ((bool) ^ !!(ip6info->invflags & (invflg)))
if ( F_5 ( F_6 ( & V_16 -> V_17 , & V_10 -> V_18 ,
& V_10 -> V_19 ) , V_20 ) ||
F_5 ( F_6 ( & V_16 -> V_21 , & V_10 -> V_22 ,
& V_10 -> V_23 ) , V_24 ) ) {
F_7 ( L_1 ) ;
return false ;
}
V_14 = F_8 ( V_7 , V_10 -> V_25 , V_10 -> V_26 ) ;
if ( F_5 ( V_14 != 0 , V_27 ) ) {
F_7 ( L_2 ,
V_7 , V_10 -> V_25 ,
V_10 -> V_28 & V_27 ? L_3 : L_4 ) ;
return false ;
}
V_14 = F_8 ( V_8 , V_10 -> V_29 , V_10 -> V_30 ) ;
if ( F_5 ( V_14 != 0 , V_31 ) ) {
F_7 ( L_5 ,
V_8 , V_10 -> V_29 ,
V_10 -> V_28 & V_31 ? L_3 : L_4 ) ;
return false ;
}
if ( V_10 -> V_32 & V_33 ) {
int V_34 ;
unsigned short V_35 ;
V_34 = F_9 ( V_6 , V_11 , - 1 , & V_35 , NULL ) ;
if ( V_34 < 0 ) {
if ( V_35 == 0 )
* V_13 = true ;
return false ;
}
* V_12 = V_35 ;
F_7 ( L_6 ,
V_34 ,
V_10 -> V_28 & V_36 ? L_7 : L_4 ,
V_10 -> V_37 ) ;
if ( V_10 -> V_37 == V_34 ) {
if ( V_10 -> V_28 & V_36 )
return false ;
return true ;
}
if ( ( V_10 -> V_37 != 0 ) &&
! ( V_10 -> V_28 & V_36 ) )
return false ;
}
return true ;
}
static bool
F_10 ( const struct V_9 * V_16 )
{
if ( V_16 -> V_32 & ~ V_38 ) {
F_11 ( L_8 ,
V_16 -> V_32 & ~ V_38 ) ;
return false ;
}
if ( V_16 -> V_28 & ~ V_39 ) {
F_11 ( L_9 ,
V_16 -> V_28 & ~ V_39 ) ;
return false ;
}
return true ;
}
static unsigned int
F_12 ( struct V_5 * V_6 , const struct V_40 * V_41 )
{
F_13 ( L_10 , ( const char * ) V_41 -> V_42 ) ;
return V_43 ;
}
static inline struct V_44 *
F_14 ( const void * V_45 , unsigned int V_46 )
{
return (struct V_44 * ) ( V_45 + V_46 ) ;
}
static inline bool F_15 ( const struct V_9 * V_16 )
{
static const struct V_9 V_47 ;
return memcmp ( V_16 , & V_47 , sizeof( V_47 ) ) == 0 ;
}
static inline const struct V_48 *
F_16 ( const struct V_44 * V_49 )
{
return F_17 ( (struct V_44 * ) V_49 ) ;
}
static inline int
F_18 ( const struct V_44 * V_50 , const struct V_44 * V_49 ,
const char * V_51 , const char * * V_52 ,
const char * * V_53 , unsigned int * V_54 )
{
const struct V_55 * V_56 = ( void * ) F_16 ( V_50 ) ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 , V_61 ) == 0 ) {
* V_52 = V_56 -> V_57 . V_62 ;
( * V_54 ) = 0 ;
} else if ( V_50 == V_49 ) {
( * V_54 ) ++ ;
if ( V_50 -> V_63 == sizeof( struct V_44 ) &&
strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 ,
V_64 ) == 0 &&
V_56 -> V_65 < 0 &&
F_15 ( & V_50 -> V_16 ) ) {
* V_53 = * V_52 == V_51
? V_66 [ V_67 ]
: V_66 [ V_68 ] ;
}
return 1 ;
} else
( * V_54 ) ++ ;
return 0 ;
}
static void F_19 ( struct V_69 * V_69 ,
const struct V_5 * V_6 ,
unsigned int V_70 ,
const struct V_71 * V_72 ,
const struct V_71 * V_73 ,
const char * V_74 ,
const struct V_75 * V_76 ,
const struct V_44 * V_49 )
{
const struct V_44 * V_77 ;
const char * V_51 , * V_52 , * V_53 ;
const struct V_44 * V_78 ;
unsigned int V_54 = 0 ;
V_77 = F_14 ( V_76 -> V_79 , V_76 -> V_80 [ V_70 ] ) ;
V_51 = V_52 = V_81 [ V_70 ] ;
V_53 = V_66 [ V_82 ] ;
F_20 (iter, root, private->size - private->hook_entry[hook])
if ( F_18 ( V_78 , V_49 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_21 ( V_69 , V_83 , V_70 , V_6 , V_72 , V_73 , & V_84 ,
L_11 ,
V_74 , V_52 , V_53 , V_54 ) ;
}
static inline struct V_44 *
F_22 ( const struct V_44 * V_85 )
{
return ( void * ) V_85 + V_85 -> V_86 ;
}
unsigned int
F_23 ( struct V_5 * V_6 ,
const struct V_87 * V_88 ,
struct V_1 * V_89 )
{
unsigned int V_70 = V_88 -> V_70 ;
static const char V_90 [ V_91 ] V_92 ( ( F_24 ( sizeof( long ) ) ) ) ;
unsigned int V_65 = V_43 ;
const char * V_7 , * V_8 ;
const void * V_93 ;
struct V_44 * V_49 , * * V_94 ;
unsigned int V_95 , V_96 ;
const struct V_75 * V_76 ;
struct V_40 V_97 ;
unsigned int V_98 ;
V_95 = 0 ;
V_7 = V_88 -> V_72 ? V_88 -> V_72 -> V_60 : V_90 ;
V_8 = V_88 -> V_73 ? V_88 -> V_73 -> V_60 : V_90 ;
V_97 . V_13 = false ;
V_97 . V_69 = V_88 -> V_69 ;
V_97 . V_72 = V_88 -> V_72 ;
V_97 . V_73 = V_88 -> V_73 ;
V_97 . V_99 = V_100 ;
V_97 . V_101 = V_70 ;
F_25 ( V_89 -> V_102 & ( 1 << V_70 ) ) ;
F_26 () ;
V_98 = F_27 () ;
V_76 = V_89 -> V_76 ;
F_28 () ;
V_96 = F_29 () ;
V_93 = V_76 -> V_79 ;
V_94 = (struct V_44 * * ) V_76 -> V_94 [ V_96 ] ;
if ( F_30 ( & V_103 ) )
V_94 += V_76 -> V_104 * F_31 ( V_105 ) ;
V_49 = F_14 ( V_93 , V_76 -> V_80 [ V_70 ] ) ;
do {
const struct V_48 * V_56 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
F_25 ( V_49 ) ;
V_97 . V_110 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_49 -> V_16 ,
& V_97 . V_110 , & V_97 . V_12 , & V_97 . V_13 ) ) {
V_111:
V_49 = F_22 ( V_49 ) ;
continue;
}
F_32 (ematch, e) {
V_97 . V_112 = V_107 -> V_58 . V_59 . V_112 ;
V_97 . V_113 = V_107 -> V_62 ;
if ( ! V_97 . V_112 -> V_112 ( V_6 , & V_97 ) )
goto V_111;
}
V_109 = F_33 ( & V_49 -> V_114 ) ;
F_34 ( * V_109 , V_6 -> V_115 , 1 ) ;
V_56 = F_16 ( V_49 ) ;
F_25 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_35 ( V_116 )
if ( F_36 ( V_6 -> V_117 ) )
F_19 ( V_88 -> V_69 , V_6 , V_70 , V_88 -> V_72 ,
V_88 -> V_73 , V_89 -> V_60 , V_76 , V_49 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_118 ;
V_118 = ( (struct V_55 * ) V_56 ) -> V_65 ;
if ( V_118 < 0 ) {
if ( V_118 != V_119 ) {
V_65 = ( unsigned int ) ( - V_118 ) - 1 ;
break;
}
if ( V_95 == 0 )
V_49 = F_14 ( V_93 ,
V_76 -> V_120 [ V_70 ] ) ;
else
V_49 = F_22 ( V_94 [ -- V_95 ] ) ;
continue;
}
if ( V_93 + V_118 != F_22 ( V_49 ) &&
! ( V_49 -> V_16 . V_32 & V_121 ) ) {
V_94 [ V_95 ++ ] = V_49 ;
}
V_49 = F_14 ( V_93 , V_118 ) ;
continue;
}
V_97 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_97 . V_42 = V_56 -> V_62 ;
V_65 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_6 , & V_97 ) ;
if ( V_65 == V_122 )
V_49 = F_22 ( V_49 ) ;
else
break;
} while ( ! V_97 . V_13 );
F_37 ( V_98 ) ;
F_38 () ;
#ifdef F_39
return V_123 ;
#else
if ( V_97 . V_13 )
return V_43 ;
else return V_65 ;
#endif
}
static int
F_40 ( const struct V_75 * V_124 ,
unsigned int V_102 , void * V_125 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_126 ; V_70 ++ ) {
unsigned int V_127 = V_124 -> V_80 [ V_70 ] ;
struct V_44 * V_49 = (struct V_44 * ) ( V_125 + V_127 ) ;
if ( ! ( V_102 & ( 1 << V_70 ) ) )
continue;
V_49 -> V_114 . V_128 = V_127 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_16 ( V_49 ) ;
int V_129 = V_49 -> V_130 & ( 1 << V_70 ) ;
if ( V_49 -> V_130 & ( 1 << V_126 ) ) {
F_41 ( L_12 ,
V_70 , V_127 , V_49 -> V_130 ) ;
return 0 ;
}
V_49 -> V_130 |= ( ( 1 << V_70 ) | ( 1 << V_126 ) ) ;
if ( ( V_49 -> V_63 == sizeof( struct V_44 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < 0 &&
F_15 ( & V_49 -> V_16 ) ) || V_129 ) {
unsigned int V_132 , V_133 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < - V_134 - 1 ) {
F_11 ( L_13
L_14 ,
V_56 -> V_65 ) ;
return 0 ;
}
do {
V_49 -> V_130 ^= ( 1 << V_126 ) ;
#ifdef F_42
if ( V_49 -> V_130
& ( 1 << V_126 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_70 , V_127 ) ;
}
#endif
V_132 = V_127 ;
V_127 = V_49 -> V_114 . V_128 ;
V_49 -> V_114 . V_128 = 0 ;
if ( V_127 == V_132 )
goto V_135;
V_49 = (struct V_44 * )
( V_125 + V_127 ) ;
} while ( V_132 == V_127 + V_49 -> V_86 );
V_133 = V_49 -> V_86 ;
V_49 = (struct V_44 * )
( V_125 + V_127 + V_133 ) ;
V_49 -> V_114 . V_128 = V_127 ;
V_127 += V_133 ;
} else {
int V_136 = V_56 -> V_65 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_64 ) == 0 &&
V_136 >= 0 ) {
if ( V_136 > V_124 -> V_133 -
sizeof( struct V_44 ) ) {
F_11 ( L_18
L_19 ,
V_136 ) ;
return 0 ;
}
F_11 ( L_20 ,
V_127 , V_136 ) ;
} else {
V_136 = V_127 + V_49 -> V_86 ;
}
V_49 = (struct V_44 * )
( V_125 + V_136 ) ;
V_49 -> V_114 . V_128 = V_127 ;
V_127 = V_136 ;
}
}
V_135:
F_11 ( L_21 , V_70 ) ;
}
return 1 ;
}
static void F_43 ( struct V_106 * V_137 , struct V_69 * V_69 )
{
struct V_138 V_41 ;
V_41 . V_69 = V_69 ;
V_41 . V_112 = V_137 -> V_58 . V_59 . V_112 ;
V_41 . V_113 = V_137 -> V_62 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_112 -> V_139 != NULL )
V_41 . V_112 -> V_139 ( & V_41 ) ;
F_44 ( V_41 . V_112 -> V_140 ) ;
}
static int
F_45 ( const struct V_44 * V_49 , const char * V_60 )
{
const struct V_48 * V_56 ;
if ( ! F_10 ( & V_49 -> V_16 ) ) {
F_11 ( L_22 , V_49 , V_60 ) ;
return - V_141 ;
}
if ( V_49 -> V_63 + sizeof( struct V_48 ) >
V_49 -> V_86 )
return - V_141 ;
V_56 = F_16 ( V_49 ) ;
if ( V_49 -> V_63 + V_56 -> V_58 . V_142 > V_49 -> V_86 )
return - V_141 ;
return 0 ;
}
static int F_46 ( struct V_106 * V_137 , struct V_143 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_144 ;
int V_14 ;
V_41 -> V_112 = V_137 -> V_58 . V_59 . V_112 ;
V_41 -> V_113 = V_137 -> V_62 ;
V_14 = F_47 ( V_41 , V_137 -> V_58 . V_145 - sizeof( * V_137 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_41 . V_112 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_48 ( struct V_106 * V_137 , struct V_143 * V_41 )
{
struct V_146 * V_112 ;
int V_14 ;
V_112 = F_49 ( V_100 , V_137 -> V_58 . V_131 . V_60 ,
V_137 -> V_58 . V_131 . V_147 ) ;
if ( F_50 ( V_112 ) ) {
F_11 ( L_24 , V_137 -> V_58 . V_131 . V_60 ) ;
return F_51 ( V_112 ) ;
}
V_137 -> V_58 . V_59 . V_112 = V_112 ;
V_14 = F_46 ( V_137 , V_41 ) ;
if ( V_14 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_137 -> V_58 . V_59 . V_112 -> V_140 ) ;
return V_14 ;
}
static int F_52 ( struct V_44 * V_49 , struct V_69 * V_69 , const char * V_60 )
{
struct V_48 * V_56 = F_17 ( V_49 ) ;
struct V_149 V_41 = {
. V_69 = V_69 ,
. V_89 = V_60 ,
. V_144 = V_49 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_42 = V_56 -> V_62 ,
. V_150 = V_49 -> V_130 ,
. V_99 = V_100 ,
} ;
int V_14 ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_53 ( & V_41 , V_56 -> V_58 . V_142 - sizeof( * V_56 ) ,
V_49 -> V_16 . V_37 , V_49 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_54 ( struct V_44 * V_49 , struct V_69 * V_69 , const char * V_60 ,
unsigned int V_133 )
{
struct V_48 * V_56 ;
struct V_151 * V_57 ;
int V_14 ;
unsigned int V_152 ;
struct V_143 V_153 ;
struct V_106 * V_107 ;
V_14 = F_45 ( V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_49 -> V_114 . V_128 = F_55 () ;
if ( F_56 ( V_49 -> V_114 . V_128 ) )
return - V_154 ;
V_152 = 0 ;
V_153 . V_69 = V_69 ;
V_153 . V_89 = V_60 ;
V_153 . V_144 = & V_49 -> V_16 ;
V_153 . V_150 = V_49 -> V_130 ;
V_153 . V_99 = V_100 ;
F_32 (ematch, e) {
V_14 = F_48 ( V_107 , & V_153 ) ;
if ( V_14 != 0 )
goto V_155;
++ V_152 ;
}
V_56 = F_17 ( V_49 ) ;
V_57 = F_57 ( V_100 , V_56 -> V_58 . V_131 . V_60 ,
V_56 -> V_58 . V_131 . V_147 ) ;
if ( F_50 ( V_57 ) ) {
F_11 ( L_25 , V_56 -> V_58 . V_131 . V_60 ) ;
V_14 = F_51 ( V_57 ) ;
goto V_155;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_14 = F_52 ( V_49 , V_69 , V_60 ) ;
if ( V_14 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_140 ) ;
V_155:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_107 , V_69 ) ;
}
F_58 ( V_49 -> V_114 . V_128 ) ;
return V_14 ;
}
static bool F_59 ( const struct V_44 * V_49 )
{
const struct V_48 * V_56 ;
unsigned int V_65 ;
if ( ! F_15 ( & V_49 -> V_16 ) )
return false ;
V_56 = F_16 ( V_49 ) ;
if ( strcmp ( V_56 -> V_58 . V_131 . V_60 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_55 * ) V_56 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_123 ;
}
static int
F_60 ( struct V_44 * V_49 ,
struct V_75 * V_124 ,
const unsigned char * V_45 ,
const unsigned char * V_156 ,
const unsigned int * V_157 ,
const unsigned int * V_158 ,
unsigned int V_102 )
{
unsigned int V_159 ;
if ( ( unsigned long ) V_49 % F_61 ( struct V_44 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_44 ) >= V_156 ) {
F_11 ( L_26 , V_49 ) ;
return - V_141 ;
}
if ( V_49 -> V_86
< sizeof( struct V_44 ) + sizeof( struct V_48 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_86 ) ;
return - V_141 ;
}
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ! ( V_102 & ( 1 << V_159 ) ) )
continue;
if ( ( unsigned char * ) V_49 - V_45 == V_157 [ V_159 ] )
V_124 -> V_80 [ V_159 ] = V_157 [ V_159 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_158 [ V_159 ] ) {
if ( ! F_59 ( V_49 ) ) {
F_41 ( L_28
L_29
L_30 ) ;
return - V_141 ;
}
V_124 -> V_120 [ V_159 ] = V_158 [ V_159 ] ;
}
}
V_49 -> V_114 = ( (struct V_108 ) { 0 , 0 } ) ;
V_49 -> V_130 = 0 ;
return 0 ;
}
static void F_62 ( struct V_44 * V_49 , struct V_69 * V_69 )
{
struct V_160 V_41 ;
struct V_48 * V_56 ;
struct V_106 * V_107 ;
F_32 (ematch, e)
F_43 ( V_107 , V_69 ) ;
V_56 = F_17 ( V_49 ) ;
V_41 . V_69 = V_69 ;
V_41 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_41 . V_42 = V_56 -> V_62 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_57 -> V_139 != NULL )
V_41 . V_57 -> V_139 ( & V_41 ) ;
F_44 ( V_41 . V_57 -> V_140 ) ;
F_58 ( V_49 -> V_114 . V_128 ) ;
}
static int
F_63 ( struct V_69 * V_69 , struct V_75 * V_124 , void * V_125 ,
const struct V_161 * V_162 )
{
struct V_44 * V_78 ;
unsigned int V_163 ;
int V_14 = 0 ;
V_124 -> V_133 = V_162 -> V_133 ;
V_124 -> V_164 = V_162 -> V_165 ;
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
V_124 -> V_80 [ V_163 ] = 0xFFFFFFFF ;
V_124 -> V_120 [ V_163 ] = 0xFFFFFFFF ;
}
F_11 ( L_31 , V_124 -> V_133 ) ;
V_163 = 0 ;
F_20 (iter, entry0, newinfo->size) {
V_14 = F_60 ( V_78 , V_124 , V_125 ,
V_125 + V_162 -> V_133 ,
V_162 -> V_80 ,
V_162 -> V_120 ,
V_162 -> V_102 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_163 ;
if ( strcmp ( F_17 ( V_78 ) -> V_58 . V_131 . V_60 ,
V_61 ) == 0 )
++ V_124 -> V_104 ;
}
if ( V_163 != V_162 -> V_165 ) {
F_11 ( L_32 ,
V_163 , V_162 -> V_165 ) ;
return - V_141 ;
}
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( ! ( V_162 -> V_102 & ( 1 << V_163 ) ) )
continue;
if ( V_124 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_163 , V_162 -> V_80 [ V_163 ] ) ;
return - V_141 ;
}
if ( V_124 -> V_120 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_163 , V_162 -> V_120 [ V_163 ] ) ;
return - V_141 ;
}
}
if ( ! F_40 ( V_124 , V_162 -> V_102 , V_125 ) )
return - V_166 ;
V_163 = 0 ;
F_20 (iter, entry0, newinfo->size) {
V_14 = F_54 ( V_78 , V_69 , V_162 -> V_60 , V_162 -> V_133 ) ;
if ( V_14 != 0 )
break;
++ V_163 ;
}
if ( V_14 != 0 ) {
F_20 (iter, entry0, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_62 ( V_78 , V_69 ) ;
}
return V_14 ;
}
return V_14 ;
}
static void
F_64 ( const struct V_75 * V_56 ,
struct V_108 V_114 [] )
{
struct V_44 * V_78 ;
unsigned int V_96 ;
unsigned int V_163 ;
F_65 (cpu) {
T_2 * V_50 = & F_66 ( V_167 , V_96 ) ;
V_163 = 0 ;
F_20 (iter, t->entries, t->size) {
struct V_108 * V_168 ;
T_3 V_169 , V_128 ;
unsigned int V_170 ;
V_168 = F_67 ( & V_78 -> V_114 , V_96 ) ;
do {
V_170 = F_68 ( V_50 ) ;
V_169 = V_168 -> V_169 ;
V_128 = V_168 -> V_128 ;
} while ( F_69 ( V_50 , V_170 ) );
F_34 ( V_114 [ V_163 ] , V_169 , V_128 ) ;
++ V_163 ;
}
}
}
static struct V_108 * F_70 ( const struct V_1 * V_89 )
{
unsigned int V_171 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
V_171 = sizeof( struct V_108 ) * V_76 -> V_164 ;
V_114 = F_71 ( V_171 ) ;
if ( V_114 == NULL )
return F_72 ( - V_154 ) ;
F_64 ( V_76 , V_114 ) ;
return V_114 ;
}
static int
F_73 ( unsigned int V_172 ,
const struct V_1 * V_89 ,
void T_4 * V_173 )
{
unsigned int V_174 , V_175 ;
const struct V_44 * V_49 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
int V_14 = 0 ;
const void * V_176 ;
V_114 = F_70 ( V_89 ) ;
if ( F_50 ( V_114 ) )
return F_51 ( V_114 ) ;
V_176 = V_76 -> V_79 ;
if ( F_74 ( V_173 , V_176 , V_172 ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
for ( V_174 = 0 , V_175 = 0 ; V_174 < V_172 ; V_174 += V_49 -> V_86 , V_175 ++ ) {
unsigned int V_163 ;
const struct V_106 * V_137 ;
const struct V_48 * V_56 ;
V_49 = (struct V_44 * ) ( V_176 + V_174 ) ;
if ( F_74 ( V_173 + V_174
+ F_75 ( struct V_44 , V_114 ) ,
& V_114 [ V_175 ] ,
sizeof( V_114 [ V_175 ] ) ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
for ( V_163 = sizeof( struct V_44 ) ;
V_163 < V_49 -> V_63 ;
V_163 += V_137 -> V_58 . V_145 ) {
V_137 = ( void * ) V_49 + V_163 ;
if ( F_74 ( V_173 + V_174 + V_163
+ F_75 ( struct V_106 ,
V_58 . V_131 . V_60 ) ,
V_137 -> V_58 . V_59 . V_112 -> V_60 ,
strlen ( V_137 -> V_58 . V_59 . V_112 -> V_60 ) + 1 )
!= 0 ) {
V_14 = - V_177 ;
goto V_178;
}
}
V_56 = F_16 ( V_49 ) ;
if ( F_74 ( V_173 + V_174 + V_49 -> V_63
+ F_75 ( struct V_48 ,
V_58 . V_131 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
}
V_178:
F_76 ( V_114 ) ;
return V_14 ;
}
static void F_77 ( void * V_23 , const void * V_19 )
{
int V_118 = * ( V_179 * ) V_19 ;
if ( V_118 > 0 )
V_118 += F_78 ( V_83 , V_118 ) ;
memcpy ( V_23 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_79 ( void T_4 * V_23 , const void * V_19 )
{
V_179 V_180 = * ( int * ) V_19 ;
if ( V_180 > 0 )
V_180 -= F_78 ( V_83 , V_180 ) ;
return F_74 ( V_23 , & V_180 , sizeof( V_180 ) ) ? - V_177 : 0 ;
}
static int F_80 ( const struct V_44 * V_49 ,
const struct V_75 * V_2 ,
const void * V_45 , struct V_75 * V_124 )
{
const struct V_106 * V_107 ;
const struct V_48 * V_56 ;
unsigned int V_181 ;
int V_174 , V_163 , V_14 ;
V_174 = sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_49 - V_45 ;
F_32 (ematch, e)
V_174 += F_81 ( V_107 -> V_58 . V_59 . V_112 ) ;
V_56 = F_16 ( V_49 ) ;
V_174 += F_82 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_124 -> V_133 -= V_174 ;
V_14 = F_83 ( V_83 , V_181 , V_174 ) ;
if ( V_14 )
return V_14 ;
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( V_2 -> V_80 [ V_163 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_163 ] ) ) )
V_124 -> V_80 [ V_163 ] -= V_174 ;
if ( V_2 -> V_120 [ V_163 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_120 [ V_163 ] ) ) )
V_124 -> V_120 [ V_163 ] -= V_174 ;
}
return 0 ;
}
static int F_84 ( const struct V_75 * V_2 ,
struct V_75 * V_124 )
{
struct V_44 * V_78 ;
const void * V_176 ;
int V_14 ;
if ( ! V_124 || ! V_2 )
return - V_141 ;
memcpy ( V_124 , V_2 , F_75 ( struct V_75 , V_79 ) ) ;
V_124 -> V_183 = 0 ;
V_176 = V_2 -> V_79 ;
F_85 ( V_83 , V_2 -> V_164 ) ;
F_20 (iter, loc_cpu_entry, info->size) {
V_14 = F_80 ( V_78 , V_2 , V_176 , V_124 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_86 ( struct V_69 * V_69 , void T_4 * V_131 ,
const int * V_115 , int V_184 )
{
char V_60 [ V_185 ] ;
struct V_1 * V_56 ;
int V_14 ;
if ( * V_115 != sizeof( struct V_186 ) ) {
F_11 ( L_35 , * V_115 ,
sizeof( struct V_186 ) ) ;
return - V_141 ;
}
if ( F_87 ( V_60 , V_131 , sizeof( V_60 ) ) != 0 )
return - V_177 ;
V_60 [ V_185 - 1 ] = '\0' ;
#ifdef F_88
if ( V_184 )
F_89 ( V_83 ) ;
#endif
V_56 = F_90 ( F_91 ( V_69 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
struct V_186 V_2 ;
const struct V_75 * V_76 = V_56 -> V_76 ;
#ifdef F_88
struct V_75 V_168 ;
if ( V_184 ) {
V_14 = F_84 ( V_76 , & V_168 ) ;
F_93 ( V_83 ) ;
V_76 = & V_168 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_102 = V_56 -> V_102 ;
memcpy ( V_2 . V_80 , V_76 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_120 , V_76 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_165 = V_76 -> V_164 ;
V_2 . V_133 = V_76 -> V_133 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_74 ( V_131 , & V_2 , * V_115 ) != 0 )
V_14 = - V_177 ;
else
V_14 = 0 ;
F_94 ( V_56 ) ;
F_44 ( V_56 -> V_140 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_187 ;
#ifdef F_88
if ( V_184 )
F_95 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_96 ( struct V_69 * V_69 , struct V_188 T_4 * V_189 ,
const int * V_115 )
{
int V_14 ;
struct V_188 V_190 ;
struct V_1 * V_56 ;
if ( * V_115 < sizeof( V_190 ) ) {
F_11 ( L_37 , * V_115 , sizeof( V_190 ) ) ;
return - V_141 ;
}
if ( F_87 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_177 ;
if ( * V_115 != sizeof( struct V_188 ) + V_190 . V_133 ) {
F_11 ( L_38 ,
* V_115 , sizeof( V_190 ) + V_190 . V_133 ) ;
return - V_141 ;
}
V_56 = F_91 ( V_69 , V_83 , V_190 . V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
struct V_75 * V_76 = V_56 -> V_76 ;
F_11 ( L_39 , V_76 -> V_164 ) ;
if ( V_190 . V_133 == V_76 -> V_133 )
V_14 = F_73 ( V_76 -> V_133 ,
V_56 , V_189 -> V_191 ) ;
else {
F_11 ( L_40 ,
V_76 -> V_133 , V_190 . V_133 ) ;
V_14 = - V_192 ;
}
F_44 ( V_56 -> V_140 ) ;
F_94 ( V_56 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_187 ;
return V_14 ;
}
static int
F_97 ( struct V_69 * V_69 , const char * V_60 , unsigned int V_102 ,
struct V_75 * V_124 , unsigned int V_193 ,
void T_4 * V_194 )
{
int V_14 ;
struct V_1 * V_56 ;
struct V_75 * V_195 ;
struct V_108 * V_114 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_114 = F_71 ( V_193 * sizeof( struct V_108 ) ) ;
if ( ! V_114 ) {
V_14 = - V_154 ;
goto V_73;
}
V_56 = F_90 ( F_91 ( V_69 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( F_92 ( V_56 ) ) {
V_14 = V_56 ? F_51 ( V_56 ) : - V_187 ;
goto V_196;
}
if ( V_102 != V_56 -> V_102 ) {
F_11 ( L_41 ,
V_102 , V_56 -> V_102 ) ;
V_14 = - V_141 ;
goto V_197;
}
V_195 = F_98 ( V_56 , V_193 , V_124 , & V_14 ) ;
if ( ! V_195 )
goto V_197;
F_11 ( L_42 ,
V_195 -> V_164 , V_195 -> V_183 , V_124 -> V_164 ) ;
if ( ( V_195 -> V_164 > V_195 -> V_183 ) ||
( V_124 -> V_164 <= V_195 -> V_183 ) )
F_44 ( V_56 -> V_140 ) ;
if ( ( V_195 -> V_164 > V_195 -> V_183 ) &&
( V_124 -> V_164 <= V_195 -> V_183 ) )
F_44 ( V_56 -> V_140 ) ;
F_64 ( V_195 , V_114 ) ;
F_20 (iter, oldinfo->entries, oldinfo->size)
F_62 ( V_78 , V_69 ) ;
F_99 ( V_195 ) ;
if ( F_74 ( V_194 , V_114 ,
sizeof( struct V_108 ) * V_193 ) != 0 ) {
F_100 ( L_43 ) ;
}
F_76 ( V_114 ) ;
F_94 ( V_56 ) ;
return V_14 ;
V_197:
F_44 ( V_56 -> V_140 ) ;
F_94 ( V_56 ) ;
V_196:
F_76 ( V_114 ) ;
V_73:
return V_14 ;
}
static int
F_101 ( struct V_69 * V_69 , const void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_161 V_168 ;
struct V_75 * V_124 ;
void * V_176 ;
struct V_44 * V_78 ;
if ( F_87 ( & V_168 , V_131 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_193 >= V_198 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_168 . V_193 == 0 )
return - V_141 ;
V_168 . V_60 [ sizeof( V_168 . V_60 ) - 1 ] = 0 ;
V_124 = F_102 ( V_168 . V_133 ) ;
if ( ! V_124 )
return - V_154 ;
V_176 = V_124 -> V_79 ;
if ( F_87 ( V_176 , V_131 + sizeof( V_168 ) ,
V_168 . V_133 ) != 0 ) {
V_14 = - V_177 ;
goto V_199;
}
V_14 = F_63 ( V_69 , V_124 , V_176 , & V_168 ) ;
if ( V_14 != 0 )
goto V_199;
F_11 ( L_44 ) ;
V_14 = F_97 ( V_69 , V_168 . V_60 , V_168 . V_102 , V_124 ,
V_168 . V_193 , V_168 . V_114 ) ;
if ( V_14 )
goto V_200;
return 0 ;
V_200:
F_20 (iter, loc_cpu_entry, newinfo->size)
F_62 ( V_78 , V_69 ) ;
V_199:
F_99 ( V_124 ) ;
return V_14 ;
}
static int
F_103 ( struct V_69 * V_69 , const void T_4 * V_131 , unsigned int V_115 ,
int V_184 )
{
unsigned int V_163 ;
struct V_201 V_168 ;
struct V_108 * V_202 ;
unsigned int V_193 ;
char * V_60 ;
int V_133 ;
void * V_203 ;
struct V_1 * V_56 ;
const struct V_75 * V_76 ;
int V_14 = 0 ;
struct V_44 * V_78 ;
unsigned int V_98 ;
#ifdef F_88
struct V_204 V_205 ;
if ( V_184 ) {
V_203 = & V_205 ;
V_133 = sizeof( struct V_204 ) ;
} else
#endif
{
V_203 = & V_168 ;
V_133 = sizeof( struct V_201 ) ;
}
if ( F_87 ( V_203 , V_131 , V_133 ) != 0 )
return - V_177 ;
#ifdef F_88
if ( V_184 ) {
V_193 = V_205 . V_193 ;
V_60 = V_205 . V_60 ;
} else
#endif
{
V_193 = V_168 . V_193 ;
V_60 = V_168 . V_60 ;
}
if ( V_115 != V_133 + V_193 * sizeof( struct V_108 ) )
return - V_141 ;
V_202 = F_104 ( V_115 - V_133 ) ;
if ( ! V_202 )
return - V_154 ;
if ( F_87 ( V_202 , V_131 + V_133 , V_115 - V_133 ) != 0 ) {
V_14 = - V_177 ;
goto free;
}
V_56 = F_91 ( V_69 , V_83 , V_60 ) ;
if ( F_92 ( V_56 ) ) {
V_14 = V_56 ? F_51 ( V_56 ) : - V_187 ;
goto free;
}
F_26 () ;
V_76 = V_56 -> V_76 ;
if ( V_76 -> V_164 != V_193 ) {
V_14 = - V_141 ;
goto V_206;
}
V_163 = 0 ;
V_98 = F_27 () ;
F_20 (iter, private->entries, private->size) {
struct V_108 * V_168 ;
V_168 = F_33 ( & V_78 -> V_114 ) ;
F_34 ( * V_168 , V_202 [ V_163 ] . V_169 , V_202 [ V_163 ] . V_128 ) ;
++ V_163 ;
}
F_37 ( V_98 ) ;
V_206:
F_38 () ;
F_94 ( V_56 ) ;
F_44 ( V_56 -> V_140 ) ;
free:
F_76 ( V_202 ) ;
return V_14 ;
}
static int
F_105 ( struct V_44 * V_49 , void T_4 * * V_207 ,
unsigned int * V_133 , struct V_108 * V_114 ,
unsigned int V_163 )
{
struct V_48 * V_56 ;
struct V_182 T_4 * V_208 ;
T_5 V_63 , V_86 ;
T_6 V_209 ;
const struct V_106 * V_107 ;
int V_14 = 0 ;
V_209 = * V_133 ;
V_208 = (struct V_182 T_4 * ) * V_207 ;
if ( F_74 ( V_208 , V_49 , sizeof( struct V_44 ) ) != 0 ||
F_74 ( & V_208 -> V_114 , & V_114 [ V_163 ] ,
sizeof( V_114 [ V_163 ] ) ) != 0 )
return - V_177 ;
* V_207 += sizeof( struct V_182 ) ;
* V_133 -= sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
F_32 (ematch, e) {
V_14 = F_106 ( V_107 , V_207 , V_133 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_63 = V_49 -> V_63 - ( V_209 - * V_133 ) ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_107 ( V_56 , V_207 , V_133 ) ;
if ( V_14 )
return V_14 ;
V_86 = V_49 -> V_86 - ( V_209 - * V_133 ) ;
if ( F_108 ( V_63 , & V_208 -> V_63 ) != 0 ||
F_108 ( V_86 , & V_208 -> V_86 ) != 0 )
return - V_177 ;
return 0 ;
}
static int
F_109 ( struct V_106 * V_137 ,
const char * V_60 ,
const struct V_9 * V_16 ,
int * V_133 )
{
struct V_146 * V_112 ;
V_112 = F_49 ( V_100 , V_137 -> V_58 . V_131 . V_60 ,
V_137 -> V_58 . V_131 . V_147 ) ;
if ( F_50 ( V_112 ) ) {
F_11 ( L_45 ,
V_137 -> V_58 . V_131 . V_60 ) ;
return F_51 ( V_112 ) ;
}
V_137 -> V_58 . V_59 . V_112 = V_112 ;
* V_133 += F_81 ( V_112 ) ;
return 0 ;
}
static void F_110 ( struct V_182 * V_49 )
{
struct V_48 * V_56 ;
struct V_106 * V_107 ;
F_32 (ematch, e)
F_44 ( V_107 -> V_58 . V_59 . V_112 -> V_140 ) ;
V_56 = F_111 ( V_49 ) ;
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_140 ) ;
}
static int
F_112 ( struct V_182 * V_49 ,
struct V_75 * V_124 ,
unsigned int * V_133 ,
const unsigned char * V_45 ,
const unsigned char * V_156 ,
const unsigned int * V_157 ,
const unsigned int * V_158 ,
const char * V_60 )
{
struct V_106 * V_107 ;
struct V_48 * V_56 ;
struct V_151 * V_57 ;
unsigned int V_181 ;
unsigned int V_152 ;
int V_14 , V_174 , V_159 ;
F_11 ( L_46 , V_49 ) ;
if ( ( unsigned long ) V_49 % F_61 ( struct V_182 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_182 ) >= V_156 ) {
F_11 ( L_47 , V_49 , V_156 ) ;
return - V_141 ;
}
if ( V_49 -> V_86 < sizeof( struct V_182 ) +
sizeof( struct V_210 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_86 ) ;
return - V_141 ;
}
V_14 = F_45 ( (struct V_44 * ) V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_174 = sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_49 - ( void * ) V_45 ;
V_152 = 0 ;
F_32 (ematch, e) {
V_14 = F_109 ( V_107 , V_60 , & V_49 -> V_16 , & V_174 ) ;
if ( V_14 != 0 )
goto V_211;
++ V_152 ;
}
V_56 = F_111 ( V_49 ) ;
V_57 = F_57 ( V_100 , V_56 -> V_58 . V_131 . V_60 ,
V_56 -> V_58 . V_131 . V_147 ) ;
if ( F_50 ( V_57 ) ) {
F_11 ( L_48 ,
V_56 -> V_58 . V_131 . V_60 ) ;
V_14 = F_51 ( V_57 ) ;
goto V_211;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_174 += F_82 ( V_57 ) ;
* V_133 += V_174 ;
V_14 = F_83 ( V_83 , V_181 , V_174 ) ;
if ( V_14 )
goto V_73;
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ( unsigned char * ) V_49 - V_45 == V_157 [ V_159 ] )
V_124 -> V_80 [ V_159 ] = V_157 [ V_159 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_158 [ V_159 ] )
V_124 -> V_120 [ V_159 ] = V_158 [ V_159 ] ;
}
memset ( & V_49 -> V_114 , 0 , sizeof( V_49 -> V_114 ) ) ;
V_49 -> V_130 = 0 ;
return 0 ;
V_73:
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_140 ) ;
V_211:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_44 ( V_107 -> V_58 . V_59 . V_112 -> V_140 ) ;
}
return V_14 ;
}
static int
F_113 ( struct V_182 * V_49 , void * * V_207 ,
unsigned int * V_133 , const char * V_60 ,
struct V_75 * V_124 , unsigned char * V_45 )
{
struct V_48 * V_56 ;
struct V_44 * V_212 ;
unsigned int V_209 ;
int V_14 , V_159 ;
struct V_106 * V_107 ;
V_14 = 0 ;
V_209 = * V_133 ;
V_212 = (struct V_44 * ) * V_207 ;
memcpy ( V_212 , V_49 , sizeof( struct V_44 ) ) ;
memcpy ( & V_212 -> V_114 , & V_49 -> V_114 , sizeof( V_49 -> V_114 ) ) ;
* V_207 += sizeof( struct V_44 ) ;
* V_133 += sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
F_32 (ematch, e) {
V_14 = F_114 ( V_107 , V_207 , V_133 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_212 -> V_63 = V_49 -> V_63 - ( V_209 - * V_133 ) ;
V_56 = F_111 ( V_49 ) ;
F_115 ( V_56 , V_207 , V_133 ) ;
V_212 -> V_86 = V_49 -> V_86 - ( V_209 - * V_133 ) ;
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ( unsigned char * ) V_212 - V_45 < V_124 -> V_80 [ V_159 ] )
V_124 -> V_80 [ V_159 ] -= V_209 - * V_133 ;
if ( ( unsigned char * ) V_212 - V_45 < V_124 -> V_120 [ V_159 ] )
V_124 -> V_120 [ V_159 ] -= V_209 - * V_133 ;
}
return V_14 ;
}
static int F_116 ( struct V_44 * V_49 , struct V_69 * V_69 ,
const char * V_60 )
{
unsigned int V_152 ;
int V_14 = 0 ;
struct V_143 V_153 ;
struct V_106 * V_107 ;
V_49 -> V_114 . V_128 = F_55 () ;
if ( F_56 ( V_49 -> V_114 . V_128 ) )
return - V_154 ;
V_152 = 0 ;
V_153 . V_69 = V_69 ;
V_153 . V_89 = V_60 ;
V_153 . V_144 = & V_49 -> V_16 ;
V_153 . V_150 = V_49 -> V_130 ;
V_153 . V_99 = V_100 ;
F_32 (ematch, e) {
V_14 = F_46 ( V_107 , & V_153 ) ;
if ( V_14 != 0 )
goto V_155;
++ V_152 ;
}
V_14 = F_52 ( V_49 , V_69 , V_60 ) ;
if ( V_14 )
goto V_155;
return 0 ;
V_155:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_107 , V_69 ) ;
}
F_58 ( V_49 -> V_114 . V_128 ) ;
return V_14 ;
}
static int
F_117 ( struct V_69 * V_69 ,
const char * V_60 ,
unsigned int V_102 ,
struct V_75 * * V_213 ,
void * * V_214 ,
unsigned int V_172 ,
unsigned int V_164 ,
unsigned int * V_157 ,
unsigned int * V_158 )
{
unsigned int V_163 , V_152 ;
struct V_75 * V_124 , * V_2 ;
void * V_127 , * V_125 , * V_215 ;
struct V_182 * V_216 ;
struct V_44 * V_217 ;
unsigned int V_133 ;
int V_14 = 0 ;
V_2 = * V_213 ;
V_125 = * V_214 ;
V_133 = V_172 ;
V_2 -> V_164 = V_164 ;
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
V_2 -> V_80 [ V_163 ] = 0xFFFFFFFF ;
V_2 -> V_120 [ V_163 ] = 0xFFFFFFFF ;
}
F_11 ( L_49 , V_2 -> V_133 ) ;
V_152 = 0 ;
F_89 ( V_83 ) ;
F_85 ( V_83 , V_164 ) ;
F_20 (iter0, entry0, total_size) {
V_14 = F_112 ( V_216 , V_2 , & V_133 ,
V_125 ,
V_125 + V_172 ,
V_157 ,
V_158 ,
V_60 ) ;
if ( V_14 != 0 )
goto V_218;
++ V_152 ;
}
V_14 = - V_141 ;
if ( V_152 != V_164 ) {
F_11 ( L_50 ,
V_152 , V_164 ) ;
goto V_218;
}
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( ! ( V_102 & ( 1 << V_163 ) ) )
continue;
if ( V_2 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_163 , V_157 [ V_163 ] ) ;
goto V_218;
}
if ( V_2 -> V_120 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_163 , V_158 [ V_163 ] ) ;
goto V_218;
}
}
V_14 = - V_154 ;
V_124 = F_102 ( V_133 ) ;
if ( ! V_124 )
goto V_218;
V_124 -> V_164 = V_164 ;
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
V_124 -> V_80 [ V_163 ] = V_2 -> V_80 [ V_163 ] ;
V_124 -> V_120 [ V_163 ] = V_2 -> V_120 [ V_163 ] ;
}
V_215 = V_124 -> V_79 ;
V_127 = V_215 ;
V_133 = V_172 ;
F_20 (iter0, entry0, total_size) {
V_14 = F_113 ( V_216 , & V_127 , & V_133 ,
V_60 , V_124 , V_215 ) ;
if ( V_14 != 0 )
break;
}
F_93 ( V_83 ) ;
F_95 ( V_83 ) ;
if ( V_14 )
goto V_199;
V_14 = - V_166 ;
if ( ! F_40 ( V_124 , V_102 , V_215 ) )
goto V_199;
V_163 = 0 ;
F_20 (iter1, entry1, newinfo->size) {
V_14 = F_116 ( V_217 , V_69 , V_60 ) ;
if ( V_14 != 0 )
break;
++ V_163 ;
if ( strcmp ( F_17 ( V_217 ) -> V_58 . V_131 . V_60 ,
V_61 ) == 0 )
++ V_124 -> V_104 ;
}
if ( V_14 ) {
int V_219 = V_163 ;
V_152 -= V_163 ;
F_20 (iter0, entry0, newinfo->size) {
if ( V_219 -- > 0 )
continue;
if ( V_152 -- == 0 )
break;
F_110 ( V_216 ) ;
}
F_20 (iter1, entry1, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_62 ( V_217 , V_69 ) ;
}
F_99 ( V_124 ) ;
return V_14 ;
}
* V_213 = V_124 ;
* V_214 = V_215 ;
F_99 ( V_2 ) ;
return 0 ;
V_199:
F_99 ( V_124 ) ;
V_73:
F_20 (iter0, entry0, total_size) {
if ( V_152 -- == 0 )
break;
F_110 ( V_216 ) ;
}
return V_14 ;
V_218:
F_93 ( V_83 ) ;
F_95 ( V_83 ) ;
goto V_73;
}
static int
F_118 ( struct V_69 * V_69 , void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_220 V_168 ;
struct V_75 * V_124 ;
void * V_176 ;
struct V_44 * V_78 ;
if ( F_87 ( & V_168 , V_131 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_133 >= V_198 / F_119 () )
return - V_154 ;
if ( V_168 . V_193 >= V_198 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_168 . V_193 == 0 )
return - V_141 ;
V_168 . V_60 [ sizeof( V_168 . V_60 ) - 1 ] = 0 ;
V_124 = F_102 ( V_168 . V_133 ) ;
if ( ! V_124 )
return - V_154 ;
V_176 = V_124 -> V_79 ;
if ( F_87 ( V_176 , V_131 + sizeof( V_168 ) ,
V_168 . V_133 ) != 0 ) {
V_14 = - V_177 ;
goto V_199;
}
V_14 = F_117 ( V_69 , V_168 . V_60 , V_168 . V_102 ,
& V_124 , & V_176 , V_168 . V_133 ,
V_168 . V_165 , V_168 . V_80 ,
V_168 . V_120 ) ;
if ( V_14 != 0 )
goto V_199;
F_11 ( L_51 ) ;
V_14 = F_97 ( V_69 , V_168 . V_60 , V_168 . V_102 , V_124 ,
V_168 . V_193 , F_120 ( V_168 . V_114 ) ) ;
if ( V_14 )
goto V_200;
return 0 ;
V_200:
F_20 (iter, loc_cpu_entry, newinfo->size)
F_62 ( V_78 , V_69 ) ;
V_199:
F_99 ( V_124 ) ;
return V_14 ;
}
static int
F_121 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 ,
unsigned int V_115 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_118 ( F_123 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_228 :
V_14 = F_103 ( F_123 ( V_222 ) , V_131 , V_115 , 1 ) ;
break;
default:
F_11 ( L_52 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
static int
F_124 ( unsigned int V_172 , struct V_1 * V_89 ,
void T_4 * V_173 )
{
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
void T_4 * V_127 ;
unsigned int V_133 ;
int V_14 = 0 ;
unsigned int V_163 = 0 ;
struct V_44 * V_78 ;
V_114 = F_70 ( V_89 ) ;
if ( F_50 ( V_114 ) )
return F_51 ( V_114 ) ;
V_127 = V_173 ;
V_133 = V_172 ;
F_20 (iter, private->entries, total_size) {
V_14 = F_105 ( V_78 , & V_127 ,
& V_133 , V_114 , V_163 ++ ) ;
if ( V_14 != 0 )
break;
}
F_76 ( V_114 ) ;
return V_14 ;
}
static int
F_125 ( struct V_69 * V_69 , struct V_229 T_4 * V_189 ,
int * V_115 )
{
int V_14 ;
struct V_229 V_190 ;
struct V_1 * V_56 ;
if ( * V_115 < sizeof( V_190 ) ) {
F_11 ( L_53 , * V_115 , sizeof( V_190 ) ) ;
return - V_141 ;
}
if ( F_87 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_177 ;
if ( * V_115 != sizeof( struct V_229 ) + V_190 . V_133 ) {
F_11 ( L_54 ,
* V_115 , sizeof( V_190 ) + V_190 . V_133 ) ;
return - V_141 ;
}
F_89 ( V_83 ) ;
V_56 = F_91 ( V_69 , V_83 , V_190 . V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
const struct V_75 * V_76 = V_56 -> V_76 ;
struct V_75 V_2 ;
F_11 ( L_39 , V_76 -> V_164 ) ;
V_14 = F_84 ( V_76 , & V_2 ) ;
if ( ! V_14 && V_190 . V_133 == V_2 . V_133 ) {
V_14 = F_124 ( V_76 -> V_133 ,
V_56 , V_189 -> V_191 ) ;
} else if ( ! V_14 ) {
F_11 ( L_55 ,
V_76 -> V_133 , V_190 . V_133 ) ;
V_14 = - V_192 ;
}
F_93 ( V_83 ) ;
F_44 ( V_56 -> V_140 ) ;
F_94 ( V_56 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_187 ;
F_95 ( V_83 ) ;
return V_14 ;
}
static int
F_126 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_86 ( F_123 ( V_222 ) , V_131 , V_115 , 1 ) ;
break;
case V_231 :
V_14 = F_125 ( F_123 ( V_222 ) , V_131 , V_115 ) ;
break;
default:
V_14 = F_127 ( V_222 , V_223 , V_131 , V_115 ) ;
}
return V_14 ;
}
static int
F_128 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_101 ( F_123 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_228 :
V_14 = F_103 ( F_123 ( V_222 ) , V_131 , V_115 , 0 ) ;
break;
default:
F_11 ( L_52 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
static int
F_127 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_86 ( F_123 ( V_222 ) , V_131 , V_115 , 0 ) ;
break;
case V_231 :
V_14 = F_96 ( F_123 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_232 :
case V_233 : {
struct V_234 V_235 ;
int V_57 ;
if ( * V_115 != sizeof( V_235 ) ) {
V_14 = - V_141 ;
break;
}
if ( F_87 ( & V_235 , V_131 , sizeof( V_235 ) ) != 0 ) {
V_14 = - V_177 ;
break;
}
V_235 . V_60 [ sizeof( V_235 . V_60 ) - 1 ] = 0 ;
if ( V_223 == V_233 )
V_57 = 1 ;
else
V_57 = 0 ;
F_90 ( F_129 ( V_83 , V_235 . V_60 ,
V_235 . V_147 ,
V_57 , & V_14 ) ,
L_56 , V_235 . V_60 ) ;
break;
}
default:
F_11 ( L_57 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
struct V_1 * F_130 ( struct V_69 * V_69 ,
const struct V_1 * V_89 ,
const struct V_161 * V_162 )
{
int V_14 ;
struct V_75 * V_124 ;
struct V_75 V_236 = { 0 } ;
void * V_176 ;
struct V_1 * V_237 ;
V_124 = F_102 ( V_162 -> V_133 ) ;
if ( ! V_124 ) {
V_14 = - V_154 ;
goto V_73;
}
V_176 = V_124 -> V_79 ;
memcpy ( V_176 , V_162 -> V_79 , V_162 -> V_133 ) ;
V_14 = F_63 ( V_69 , V_124 , V_176 , V_162 ) ;
if ( V_14 != 0 )
goto V_238;
V_237 = F_131 ( V_69 , V_89 , & V_236 , V_124 ) ;
if ( F_50 ( V_237 ) ) {
V_14 = F_51 ( V_237 ) ;
goto V_238;
}
return V_237 ;
V_238:
F_99 ( V_124 ) ;
V_73:
return F_72 ( V_14 ) ;
}
void F_132 ( struct V_69 * V_69 , struct V_1 * V_89 )
{
struct V_75 * V_76 ;
void * V_176 ;
struct V_239 * V_240 = V_89 -> V_140 ;
struct V_44 * V_78 ;
V_76 = F_133 ( V_89 ) ;
V_176 = V_76 -> V_79 ;
F_20 (iter, loc_cpu_entry, private->size)
F_62 ( V_78 , V_69 ) ;
if ( V_76 -> V_164 > V_76 -> V_183 )
F_44 ( V_240 ) ;
F_99 ( V_76 ) ;
}
static inline bool
F_134 ( T_7 V_241 , T_7 V_242 , T_7 V_243 ,
T_7 type , T_7 V_244 ,
bool V_245 )
{
return ( type == V_241 && V_244 >= V_242 && V_244 <= V_243 )
^ V_245 ;
}
static bool
F_135 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_246 * V_247 ;
struct V_246 V_248 ;
const struct V_249 * V_250 = V_41 -> V_113 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_247 = F_136 ( V_6 , V_41 -> V_110 , sizeof( V_248 ) , & V_248 ) ;
if ( V_247 == NULL ) {
F_11 ( L_58 ) ;
V_41 -> V_13 = true ;
return false ;
}
return F_134 ( V_250 -> type ,
V_250 -> V_244 [ 0 ] ,
V_250 -> V_244 [ 1 ] ,
V_247 -> V_251 , V_247 -> V_252 ,
! ! ( V_250 -> V_28 & V_253 ) ) ;
}
static int F_137 ( const struct V_143 * V_41 )
{
const struct V_249 * V_250 = V_41 -> V_113 ;
return ( V_250 -> V_28 & ~ V_253 ) ? - V_141 : 0 ;
}
static int T_8 F_138 ( struct V_69 * V_69 )
{
return F_139 ( V_69 , V_100 ) ;
}
static void T_9 F_140 ( struct V_69 * V_69 )
{
F_141 ( V_69 , V_100 ) ;
}
static int T_10 F_142 ( void )
{
int V_14 ;
V_14 = F_143 ( & V_254 ) ;
if ( V_14 < 0 )
goto V_255;
V_14 = F_144 ( V_256 , F_145 ( V_256 ) ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_146 ( V_258 , F_145 ( V_258 ) ) ;
if ( V_14 < 0 )
goto V_259;
V_14 = F_147 ( & V_260 ) ;
if ( V_14 < 0 )
goto V_261;
F_148 ( L_59 ) ;
return 0 ;
V_261:
F_149 ( V_258 , F_145 ( V_258 ) ) ;
V_259:
F_150 ( V_256 , F_145 ( V_256 ) ) ;
V_257:
F_151 ( & V_254 ) ;
V_255:
return V_14 ;
}
static void T_11 F_152 ( void )
{
F_153 ( & V_260 ) ;
F_149 ( V_258 , F_145 ( V_258 ) ) ;
F_150 ( V_256 , F_145 ( V_256 ) ) ;
F_151 ( & V_254 ) ;
}
