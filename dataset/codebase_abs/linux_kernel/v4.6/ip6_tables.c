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
static inline bool F_15 ( const struct V_44 * V_47 )
{
static const struct V_9 V_48 ;
return V_47 -> V_49 == sizeof( struct V_44 ) &&
memcmp ( & V_47 -> V_16 , & V_48 , sizeof( V_48 ) ) == 0 ;
}
static inline const struct V_50 *
F_16 ( const struct V_44 * V_47 )
{
return F_17 ( (struct V_44 * ) V_47 ) ;
}
static inline int
F_18 ( const struct V_44 * V_51 , const struct V_44 * V_47 ,
const char * V_52 , const char * * V_53 ,
const char * * V_54 , unsigned int * V_55 )
{
const struct V_56 * V_57 = ( void * ) F_16 ( V_51 ) ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_60 . V_58 -> V_61 , V_62 ) == 0 ) {
* V_53 = V_57 -> V_58 . V_63 ;
( * V_55 ) = 0 ;
} else if ( V_51 == V_47 ) {
( * V_55 ) ++ ;
if ( F_15 ( V_51 ) &&
strcmp ( V_57 -> V_58 . V_59 . V_60 . V_58 -> V_61 ,
V_64 ) == 0 &&
V_57 -> V_65 < 0 ) {
* V_54 = * V_53 == V_52
? V_66 [ V_67 ]
: V_66 [ V_68 ] ;
}
return 1 ;
} else
( * V_55 ) ++ ;
return 0 ;
}
static void F_19 ( struct V_69 * V_69 ,
const struct V_5 * V_6 ,
unsigned int V_70 ,
const struct V_71 * V_72 ,
const struct V_71 * V_73 ,
const char * V_74 ,
const struct V_75 * V_76 ,
const struct V_44 * V_47 )
{
const struct V_44 * V_77 ;
const char * V_52 , * V_53 , * V_54 ;
const struct V_44 * V_78 ;
unsigned int V_55 = 0 ;
V_77 = F_14 ( V_76 -> V_79 , V_76 -> V_80 [ V_70 ] ) ;
V_52 = V_53 = V_81 [ V_70 ] ;
V_54 = V_66 [ V_82 ] ;
F_20 (iter, root, private->size - private->hook_entry[hook])
if ( F_18 ( V_78 , V_47 , V_52 ,
& V_53 , & V_54 , & V_55 ) != 0 )
break;
F_21 ( V_69 , V_83 , V_70 , V_6 , V_72 , V_73 , & V_84 ,
L_11 ,
V_74 , V_53 , V_54 , V_55 ) ;
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
struct V_44 * V_47 , * * V_94 ;
unsigned int V_95 , V_96 ;
const struct V_75 * V_76 ;
struct V_40 V_97 ;
unsigned int V_98 ;
V_95 = 0 ;
V_7 = V_88 -> V_72 ? V_88 -> V_72 -> V_61 : V_90 ;
V_8 = V_88 -> V_73 ? V_88 -> V_73 -> V_61 : V_90 ;
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
V_47 = F_14 ( V_93 , V_76 -> V_80 [ V_70 ] ) ;
do {
const struct V_50 * V_57 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
F_25 ( V_47 ) ;
V_97 . V_110 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_47 -> V_16 ,
& V_97 . V_110 , & V_97 . V_12 , & V_97 . V_13 ) ) {
V_111:
V_47 = F_22 ( V_47 ) ;
continue;
}
F_32 (ematch, e) {
V_97 . V_112 = V_107 -> V_59 . V_60 . V_112 ;
V_97 . V_113 = V_107 -> V_63 ;
if ( ! V_97 . V_112 -> V_112 ( V_6 , & V_97 ) )
goto V_111;
}
V_109 = F_33 ( & V_47 -> V_114 ) ;
F_34 ( * V_109 , V_6 -> V_115 , 1 ) ;
V_57 = F_16 ( V_47 ) ;
F_25 ( V_57 -> V_59 . V_60 . V_58 ) ;
#if F_35 ( V_116 )
if ( F_36 ( V_6 -> V_117 ) )
F_19 ( V_88 -> V_69 , V_6 , V_70 , V_88 -> V_72 ,
V_88 -> V_73 , V_89 -> V_61 , V_76 , V_47 ) ;
#endif
if ( ! V_57 -> V_59 . V_60 . V_58 -> V_58 ) {
int V_118 ;
V_118 = ( (struct V_56 * ) V_57 ) -> V_65 ;
if ( V_118 < 0 ) {
if ( V_118 != V_119 ) {
V_65 = ( unsigned int ) ( - V_118 ) - 1 ;
break;
}
if ( V_95 == 0 )
V_47 = F_14 ( V_93 ,
V_76 -> V_120 [ V_70 ] ) ;
else
V_47 = F_22 ( V_94 [ -- V_95 ] ) ;
continue;
}
if ( V_93 + V_118 != F_22 ( V_47 ) &&
! ( V_47 -> V_16 . V_32 & V_121 ) ) {
V_94 [ V_95 ++ ] = V_47 ;
}
V_47 = F_14 ( V_93 , V_118 ) ;
continue;
}
V_97 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_97 . V_42 = V_57 -> V_63 ;
V_65 = V_57 -> V_59 . V_60 . V_58 -> V_58 ( V_6 , & V_97 ) ;
if ( V_65 == V_122 )
V_47 = F_22 ( V_47 ) ;
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
struct V_44 * V_47 = (struct V_44 * ) ( V_125 + V_127 ) ;
if ( ! ( V_102 & ( 1 << V_70 ) ) )
continue;
V_47 -> V_114 . V_128 = V_127 ;
for (; ; ) {
const struct V_56 * V_57
= ( void * ) F_16 ( V_47 ) ;
int V_129 = V_47 -> V_130 & ( 1 << V_70 ) ;
if ( V_47 -> V_130 & ( 1 << V_126 ) ) {
F_41 ( L_12 ,
V_70 , V_127 , V_47 -> V_130 ) ;
return 0 ;
}
V_47 -> V_130 |= ( ( 1 << V_70 ) | ( 1 << V_126 ) ) ;
if ( ( F_15 ( V_47 ) &&
( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < 0 ) || V_129 ) {
unsigned int V_132 , V_133 ;
if ( ( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < - V_134 - 1 ) {
F_11 ( L_13
L_14 ,
V_57 -> V_65 ) ;
return 0 ;
}
do {
V_47 -> V_130 ^= ( 1 << V_126 ) ;
#ifdef F_42
if ( V_47 -> V_130
& ( 1 << V_126 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_70 , V_127 ) ;
}
#endif
V_132 = V_127 ;
V_127 = V_47 -> V_114 . V_128 ;
V_47 -> V_114 . V_128 = 0 ;
if ( V_127 == V_132 )
goto V_135;
V_47 = (struct V_44 * )
( V_125 + V_127 ) ;
} while ( V_132 == V_127 + V_47 -> V_86 );
V_133 = V_47 -> V_86 ;
V_47 = (struct V_44 * )
( V_125 + V_127 + V_133 ) ;
V_47 -> V_114 . V_128 = V_127 ;
V_127 += V_133 ;
} else {
int V_136 = V_57 -> V_65 ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
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
V_136 = V_127 + V_47 -> V_86 ;
}
V_47 = (struct V_44 * )
( V_125 + V_136 ) ;
V_47 -> V_114 . V_128 = V_127 ;
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
V_41 . V_112 = V_137 -> V_59 . V_60 . V_112 ;
V_41 . V_113 = V_137 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_112 -> V_139 != NULL )
V_41 . V_112 -> V_139 ( & V_41 ) ;
F_44 ( V_41 . V_112 -> V_140 ) ;
}
static int
F_45 ( const struct V_44 * V_47 )
{
const struct V_50 * V_57 ;
if ( ! F_10 ( & V_47 -> V_16 ) )
return - V_141 ;
if ( V_47 -> V_49 + sizeof( struct V_50 ) >
V_47 -> V_86 )
return - V_141 ;
V_57 = F_16 ( V_47 ) ;
if ( V_47 -> V_49 + V_57 -> V_59 . V_142 > V_47 -> V_86 )
return - V_141 ;
return 0 ;
}
static int F_46 ( struct V_106 * V_137 , struct V_143 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_144 ;
int V_14 ;
V_41 -> V_112 = V_137 -> V_59 . V_60 . V_112 ;
V_41 -> V_113 = V_137 -> V_63 ;
V_14 = F_47 ( V_41 , V_137 -> V_59 . V_145 - sizeof( * V_137 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_22 ,
V_41 . V_112 -> V_61 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_48 ( struct V_106 * V_137 , struct V_143 * V_41 )
{
struct V_146 * V_112 ;
int V_14 ;
V_112 = F_49 ( V_100 , V_137 -> V_59 . V_131 . V_61 ,
V_137 -> V_59 . V_131 . V_147 ) ;
if ( F_50 ( V_112 ) ) {
F_11 ( L_23 , V_137 -> V_59 . V_131 . V_61 ) ;
return F_51 ( V_112 ) ;
}
V_137 -> V_59 . V_60 . V_112 = V_112 ;
V_14 = F_46 ( V_137 , V_41 ) ;
if ( V_14 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_137 -> V_59 . V_60 . V_112 -> V_140 ) ;
return V_14 ;
}
static int F_52 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 )
{
struct V_50 * V_57 = F_17 ( V_47 ) ;
struct V_149 V_41 = {
. V_69 = V_69 ,
. V_89 = V_61 ,
. V_144 = V_47 ,
. V_58 = V_57 -> V_59 . V_60 . V_58 ,
. V_42 = V_57 -> V_63 ,
. V_150 = V_47 -> V_130 ,
. V_99 = V_100 ,
} ;
int V_14 ;
V_57 = F_17 ( V_47 ) ;
V_14 = F_53 ( & V_41 , V_57 -> V_59 . V_142 - sizeof( * V_57 ) ,
V_47 -> V_16 . V_37 , V_47 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_22 ,
V_57 -> V_59 . V_60 . V_58 -> V_61 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_54 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 ,
unsigned int V_133 )
{
struct V_50 * V_57 ;
struct V_151 * V_58 ;
int V_14 ;
unsigned int V_152 ;
struct V_143 V_153 ;
struct V_106 * V_107 ;
V_47 -> V_114 . V_128 = F_55 () ;
if ( F_56 ( V_47 -> V_114 . V_128 ) )
return - V_154 ;
V_152 = 0 ;
V_153 . V_69 = V_69 ;
V_153 . V_89 = V_61 ;
V_153 . V_144 = & V_47 -> V_16 ;
V_153 . V_150 = V_47 -> V_130 ;
V_153 . V_99 = V_100 ;
F_32 (ematch, e) {
V_14 = F_48 ( V_107 , & V_153 ) ;
if ( V_14 != 0 )
goto V_155;
++ V_152 ;
}
V_57 = F_17 ( V_47 ) ;
V_58 = F_57 ( V_100 , V_57 -> V_59 . V_131 . V_61 ,
V_57 -> V_59 . V_131 . V_147 ) ;
if ( F_50 ( V_58 ) ) {
F_11 ( L_24 , V_57 -> V_59 . V_131 . V_61 ) ;
V_14 = F_51 ( V_58 ) ;
goto V_155;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_14 = F_52 ( V_47 , V_69 , V_61 ) ;
if ( V_14 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
V_155:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_107 , V_69 ) ;
}
F_58 ( V_47 -> V_114 . V_128 ) ;
return V_14 ;
}
static bool F_59 ( const struct V_44 * V_47 )
{
const struct V_50 * V_57 ;
unsigned int V_65 ;
if ( ! F_15 ( V_47 ) )
return false ;
V_57 = F_16 ( V_47 ) ;
if ( strcmp ( V_57 -> V_59 . V_131 . V_61 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_56 * ) V_57 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_123 ;
}
static int
F_60 ( struct V_44 * V_47 ,
struct V_75 * V_124 ,
const unsigned char * V_45 ,
const unsigned char * V_156 ,
const unsigned int * V_157 ,
const unsigned int * V_158 ,
unsigned int V_102 )
{
unsigned int V_159 ;
int V_148 ;
if ( ( unsigned long ) V_47 % F_61 ( struct V_44 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_44 ) >= V_156 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_156 ) {
F_11 ( L_25 , V_47 ) ;
return - V_141 ;
}
if ( V_47 -> V_86
< sizeof( struct V_44 ) + sizeof( struct V_50 ) ) {
F_11 ( L_26 ,
V_47 , V_47 -> V_86 ) ;
return - V_141 ;
}
V_148 = F_45 ( V_47 ) ;
if ( V_148 )
return V_148 ;
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ! ( V_102 & ( 1 << V_159 ) ) )
continue;
if ( ( unsigned char * ) V_47 - V_45 == V_157 [ V_159 ] )
V_124 -> V_80 [ V_159 ] = V_157 [ V_159 ] ;
if ( ( unsigned char * ) V_47 - V_45 == V_158 [ V_159 ] ) {
if ( ! F_59 ( V_47 ) ) {
F_62 ( L_27
L_28
L_29 ) ;
return - V_141 ;
}
V_124 -> V_120 [ V_159 ] = V_158 [ V_159 ] ;
}
}
V_47 -> V_114 = ( (struct V_108 ) { 0 , 0 } ) ;
V_47 -> V_130 = 0 ;
return 0 ;
}
static void F_63 ( struct V_44 * V_47 , struct V_69 * V_69 )
{
struct V_160 V_41 ;
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_32 (ematch, e)
F_43 ( V_107 , V_69 ) ;
V_57 = F_17 ( V_47 ) ;
V_41 . V_69 = V_69 ;
V_41 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_41 . V_42 = V_57 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_58 -> V_139 != NULL )
V_41 . V_58 -> V_139 ( & V_41 ) ;
F_44 ( V_41 . V_58 -> V_140 ) ;
F_58 ( V_47 -> V_114 . V_128 ) ;
}
static int
F_64 ( struct V_69 * V_69 , struct V_75 * V_124 , void * V_125 ,
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
F_11 ( L_30 , V_124 -> V_133 ) ;
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
if ( strcmp ( F_17 ( V_78 ) -> V_59 . V_131 . V_61 ,
V_62 ) == 0 )
++ V_124 -> V_104 ;
}
if ( V_163 != V_162 -> V_165 ) {
F_11 ( L_31 ,
V_163 , V_162 -> V_165 ) ;
return - V_141 ;
}
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( ! ( V_162 -> V_102 & ( 1 << V_163 ) ) )
continue;
if ( V_124 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_32 ,
V_163 , V_162 -> V_80 [ V_163 ] ) ;
return - V_141 ;
}
if ( V_124 -> V_120 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_163 , V_162 -> V_120 [ V_163 ] ) ;
return - V_141 ;
}
}
if ( ! F_40 ( V_124 , V_162 -> V_102 , V_125 ) )
return - V_166 ;
V_163 = 0 ;
F_20 (iter, entry0, newinfo->size) {
V_14 = F_54 ( V_78 , V_69 , V_162 -> V_61 , V_162 -> V_133 ) ;
if ( V_14 != 0 )
break;
++ V_163 ;
}
if ( V_14 != 0 ) {
F_20 (iter, entry0, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_63 ( V_78 , V_69 ) ;
}
return V_14 ;
}
return V_14 ;
}
static void
F_65 ( const struct V_75 * V_57 ,
struct V_108 V_114 [] )
{
struct V_44 * V_78 ;
unsigned int V_96 ;
unsigned int V_163 ;
F_66 (cpu) {
T_2 * V_51 = & F_67 ( V_167 , V_96 ) ;
V_163 = 0 ;
F_20 (iter, t->entries, t->size) {
struct V_108 * V_168 ;
T_3 V_169 , V_128 ;
unsigned int V_170 ;
V_168 = F_68 ( & V_78 -> V_114 , V_96 ) ;
do {
V_170 = F_69 ( V_51 ) ;
V_169 = V_168 -> V_169 ;
V_128 = V_168 -> V_128 ;
} while ( F_70 ( V_51 , V_170 ) );
F_34 ( V_114 [ V_163 ] , V_169 , V_128 ) ;
++ V_163 ;
}
}
}
static struct V_108 * F_71 ( const struct V_1 * V_89 )
{
unsigned int V_171 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
V_171 = sizeof( struct V_108 ) * V_76 -> V_164 ;
V_114 = F_72 ( V_171 ) ;
if ( V_114 == NULL )
return F_73 ( - V_154 ) ;
F_65 ( V_76 , V_114 ) ;
return V_114 ;
}
static int
F_74 ( unsigned int V_172 ,
const struct V_1 * V_89 ,
void T_4 * V_173 )
{
unsigned int V_174 , V_175 ;
const struct V_44 * V_47 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
int V_14 = 0 ;
const void * V_176 ;
V_114 = F_71 ( V_89 ) ;
if ( F_50 ( V_114 ) )
return F_51 ( V_114 ) ;
V_176 = V_76 -> V_79 ;
if ( F_75 ( V_173 , V_176 , V_172 ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
for ( V_174 = 0 , V_175 = 0 ; V_174 < V_172 ; V_174 += V_47 -> V_86 , V_175 ++ ) {
unsigned int V_163 ;
const struct V_106 * V_137 ;
const struct V_50 * V_57 ;
V_47 = (struct V_44 * ) ( V_176 + V_174 ) ;
if ( F_75 ( V_173 + V_174
+ F_76 ( struct V_44 , V_114 ) ,
& V_114 [ V_175 ] ,
sizeof( V_114 [ V_175 ] ) ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
for ( V_163 = sizeof( struct V_44 ) ;
V_163 < V_47 -> V_49 ;
V_163 += V_137 -> V_59 . V_145 ) {
V_137 = ( void * ) V_47 + V_163 ;
if ( F_75 ( V_173 + V_174 + V_163
+ F_76 ( struct V_106 ,
V_59 . V_131 . V_61 ) ,
V_137 -> V_59 . V_60 . V_112 -> V_61 ,
strlen ( V_137 -> V_59 . V_60 . V_112 -> V_61 ) + 1 )
!= 0 ) {
V_14 = - V_177 ;
goto V_178;
}
}
V_57 = F_16 ( V_47 ) ;
if ( F_75 ( V_173 + V_174 + V_47 -> V_49
+ F_76 ( struct V_50 ,
V_59 . V_131 . V_61 ) ,
V_57 -> V_59 . V_60 . V_58 -> V_61 ,
strlen ( V_57 -> V_59 . V_60 . V_58 -> V_61 ) + 1 ) != 0 ) {
V_14 = - V_177 ;
goto V_178;
}
}
V_178:
F_77 ( V_114 ) ;
return V_14 ;
}
static void F_78 ( void * V_23 , const void * V_19 )
{
int V_118 = * ( V_179 * ) V_19 ;
if ( V_118 > 0 )
V_118 += F_79 ( V_83 , V_118 ) ;
memcpy ( V_23 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_80 ( void T_4 * V_23 , const void * V_19 )
{
V_179 V_180 = * ( int * ) V_19 ;
if ( V_180 > 0 )
V_180 -= F_79 ( V_83 , V_180 ) ;
return F_75 ( V_23 , & V_180 , sizeof( V_180 ) ) ? - V_177 : 0 ;
}
static int F_81 ( const struct V_44 * V_47 ,
const struct V_75 * V_2 ,
const void * V_45 , struct V_75 * V_124 )
{
const struct V_106 * V_107 ;
const struct V_50 * V_57 ;
unsigned int V_181 ;
int V_174 , V_163 , V_14 ;
V_174 = sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_47 - V_45 ;
F_32 (ematch, e)
V_174 += F_82 ( V_107 -> V_59 . V_60 . V_112 ) ;
V_57 = F_16 ( V_47 ) ;
V_174 += F_83 ( V_57 -> V_59 . V_60 . V_58 ) ;
V_124 -> V_133 -= V_174 ;
V_14 = F_84 ( V_83 , V_181 , V_174 ) ;
if ( V_14 )
return V_14 ;
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( V_2 -> V_80 [ V_163 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_163 ] ) ) )
V_124 -> V_80 [ V_163 ] -= V_174 ;
if ( V_2 -> V_120 [ V_163 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_120 [ V_163 ] ) ) )
V_124 -> V_120 [ V_163 ] -= V_174 ;
}
return 0 ;
}
static int F_85 ( const struct V_75 * V_2 ,
struct V_75 * V_124 )
{
struct V_44 * V_78 ;
const void * V_176 ;
int V_14 ;
if ( ! V_124 || ! V_2 )
return - V_141 ;
memcpy ( V_124 , V_2 , F_76 ( struct V_75 , V_79 ) ) ;
V_124 -> V_183 = 0 ;
V_176 = V_2 -> V_79 ;
F_86 ( V_83 , V_2 -> V_164 ) ;
F_20 (iter, loc_cpu_entry, info->size) {
V_14 = F_81 ( V_78 , V_2 , V_176 , V_124 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_87 ( struct V_69 * V_69 , void T_4 * V_131 ,
const int * V_115 , int V_184 )
{
char V_61 [ V_185 ] ;
struct V_1 * V_57 ;
int V_14 ;
if ( * V_115 != sizeof( struct V_186 ) ) {
F_11 ( L_34 , * V_115 ,
sizeof( struct V_186 ) ) ;
return - V_141 ;
}
if ( F_88 ( V_61 , V_131 , sizeof( V_61 ) ) != 0 )
return - V_177 ;
V_61 [ V_185 - 1 ] = '\0' ;
#ifdef F_89
if ( V_184 )
F_90 ( V_83 ) ;
#endif
V_57 = F_91 ( F_92 ( V_69 , V_83 , V_61 ) ,
L_35 , V_61 ) ;
if ( ! F_93 ( V_57 ) ) {
struct V_186 V_2 ;
const struct V_75 * V_76 = V_57 -> V_76 ;
#ifdef F_89
struct V_75 V_168 ;
if ( V_184 ) {
V_14 = F_85 ( V_76 , & V_168 ) ;
F_94 ( V_83 ) ;
V_76 = & V_168 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_102 = V_57 -> V_102 ;
memcpy ( V_2 . V_80 , V_76 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_120 , V_76 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_165 = V_76 -> V_164 ;
V_2 . V_133 = V_76 -> V_133 ;
strcpy ( V_2 . V_61 , V_61 ) ;
if ( F_75 ( V_131 , & V_2 , * V_115 ) != 0 )
V_14 = - V_177 ;
else
V_14 = 0 ;
F_95 ( V_57 ) ;
F_44 ( V_57 -> V_140 ) ;
} else
V_14 = V_57 ? F_51 ( V_57 ) : - V_187 ;
#ifdef F_89
if ( V_184 )
F_96 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_97 ( struct V_69 * V_69 , struct V_188 T_4 * V_189 ,
const int * V_115 )
{
int V_14 ;
struct V_188 V_190 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_190 ) ) {
F_11 ( L_36 , * V_115 , sizeof( V_190 ) ) ;
return - V_141 ;
}
if ( F_88 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_177 ;
if ( * V_115 != sizeof( struct V_188 ) + V_190 . V_133 ) {
F_11 ( L_37 ,
* V_115 , sizeof( V_190 ) + V_190 . V_133 ) ;
return - V_141 ;
}
V_190 . V_61 [ sizeof( V_190 . V_61 ) - 1 ] = '\0' ;
V_57 = F_92 ( V_69 , V_83 , V_190 . V_61 ) ;
if ( ! F_93 ( V_57 ) ) {
struct V_75 * V_76 = V_57 -> V_76 ;
F_11 ( L_38 , V_76 -> V_164 ) ;
if ( V_190 . V_133 == V_76 -> V_133 )
V_14 = F_74 ( V_76 -> V_133 ,
V_57 , V_189 -> V_191 ) ;
else {
F_11 ( L_39 ,
V_76 -> V_133 , V_190 . V_133 ) ;
V_14 = - V_192 ;
}
F_44 ( V_57 -> V_140 ) ;
F_95 ( V_57 ) ;
} else
V_14 = V_57 ? F_51 ( V_57 ) : - V_187 ;
return V_14 ;
}
static int
F_98 ( struct V_69 * V_69 , const char * V_61 , unsigned int V_102 ,
struct V_75 * V_124 , unsigned int V_193 ,
void T_4 * V_194 )
{
int V_14 ;
struct V_1 * V_57 ;
struct V_75 * V_195 ;
struct V_108 * V_114 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_114 = F_72 ( V_193 * sizeof( struct V_108 ) ) ;
if ( ! V_114 ) {
V_14 = - V_154 ;
goto V_73;
}
V_57 = F_91 ( F_92 ( V_69 , V_83 , V_61 ) ,
L_35 , V_61 ) ;
if ( F_93 ( V_57 ) ) {
V_14 = V_57 ? F_51 ( V_57 ) : - V_187 ;
goto V_196;
}
if ( V_102 != V_57 -> V_102 ) {
F_11 ( L_40 ,
V_102 , V_57 -> V_102 ) ;
V_14 = - V_141 ;
goto V_197;
}
V_195 = F_99 ( V_57 , V_193 , V_124 , & V_14 ) ;
if ( ! V_195 )
goto V_197;
F_11 ( L_41 ,
V_195 -> V_164 , V_195 -> V_183 , V_124 -> V_164 ) ;
if ( ( V_195 -> V_164 > V_195 -> V_183 ) ||
( V_124 -> V_164 <= V_195 -> V_183 ) )
F_44 ( V_57 -> V_140 ) ;
if ( ( V_195 -> V_164 > V_195 -> V_183 ) &&
( V_124 -> V_164 <= V_195 -> V_183 ) )
F_44 ( V_57 -> V_140 ) ;
F_65 ( V_195 , V_114 ) ;
F_20 (iter, oldinfo->entries, oldinfo->size)
F_63 ( V_78 , V_69 ) ;
F_100 ( V_195 ) ;
if ( F_75 ( V_194 , V_114 ,
sizeof( struct V_108 ) * V_193 ) != 0 ) {
F_101 ( L_42 ) ;
}
F_77 ( V_114 ) ;
F_95 ( V_57 ) ;
return V_14 ;
V_197:
F_44 ( V_57 -> V_140 ) ;
F_95 ( V_57 ) ;
V_196:
F_77 ( V_114 ) ;
V_73:
return V_14 ;
}
static int
F_102 ( struct V_69 * V_69 , const void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_161 V_168 ;
struct V_75 * V_124 ;
void * V_176 ;
struct V_44 * V_78 ;
if ( F_88 ( & V_168 , V_131 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_193 >= V_198 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_168 . V_193 == 0 )
return - V_141 ;
V_168 . V_61 [ sizeof( V_168 . V_61 ) - 1 ] = 0 ;
V_124 = F_103 ( V_168 . V_133 ) ;
if ( ! V_124 )
return - V_154 ;
V_176 = V_124 -> V_79 ;
if ( F_88 ( V_176 , V_131 + sizeof( V_168 ) ,
V_168 . V_133 ) != 0 ) {
V_14 = - V_177 ;
goto V_199;
}
V_14 = F_64 ( V_69 , V_124 , V_176 , & V_168 ) ;
if ( V_14 != 0 )
goto V_199;
F_11 ( L_43 ) ;
V_14 = F_98 ( V_69 , V_168 . V_61 , V_168 . V_102 , V_124 ,
V_168 . V_193 , V_168 . V_114 ) ;
if ( V_14 )
goto V_200;
return 0 ;
V_200:
F_20 (iter, loc_cpu_entry, newinfo->size)
F_63 ( V_78 , V_69 ) ;
V_199:
F_100 ( V_124 ) ;
return V_14 ;
}
static int
F_104 ( struct V_69 * V_69 , const void T_4 * V_131 , unsigned int V_115 ,
int V_184 )
{
unsigned int V_163 ;
struct V_201 V_168 ;
struct V_108 * V_202 ;
unsigned int V_193 ;
char * V_61 ;
int V_133 ;
void * V_203 ;
struct V_1 * V_57 ;
const struct V_75 * V_76 ;
int V_14 = 0 ;
struct V_44 * V_78 ;
unsigned int V_98 ;
#ifdef F_89
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
if ( F_88 ( V_203 , V_131 , V_133 ) != 0 )
return - V_177 ;
#ifdef F_89
if ( V_184 ) {
V_193 = V_205 . V_193 ;
V_61 = V_205 . V_61 ;
} else
#endif
{
V_193 = V_168 . V_193 ;
V_61 = V_168 . V_61 ;
}
if ( V_115 != V_133 + V_193 * sizeof( struct V_108 ) )
return - V_141 ;
V_202 = F_105 ( V_115 - V_133 ) ;
if ( ! V_202 )
return - V_154 ;
if ( F_88 ( V_202 , V_131 + V_133 , V_115 - V_133 ) != 0 ) {
V_14 = - V_177 ;
goto free;
}
V_57 = F_92 ( V_69 , V_83 , V_61 ) ;
if ( F_93 ( V_57 ) ) {
V_14 = V_57 ? F_51 ( V_57 ) : - V_187 ;
goto free;
}
F_26 () ;
V_76 = V_57 -> V_76 ;
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
F_95 ( V_57 ) ;
F_44 ( V_57 -> V_140 ) ;
free:
F_77 ( V_202 ) ;
return V_14 ;
}
static int
F_106 ( struct V_44 * V_47 , void T_4 * * V_207 ,
unsigned int * V_133 , struct V_108 * V_114 ,
unsigned int V_163 )
{
struct V_50 * V_57 ;
struct V_182 T_4 * V_208 ;
T_5 V_49 , V_86 ;
T_6 V_209 ;
const struct V_106 * V_107 ;
int V_14 = 0 ;
V_209 = * V_133 ;
V_208 = (struct V_182 T_4 * ) * V_207 ;
if ( F_75 ( V_208 , V_47 , sizeof( struct V_44 ) ) != 0 ||
F_75 ( & V_208 -> V_114 , & V_114 [ V_163 ] ,
sizeof( V_114 [ V_163 ] ) ) != 0 )
return - V_177 ;
* V_207 += sizeof( struct V_182 ) ;
* V_133 -= sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
F_32 (ematch, e) {
V_14 = F_107 ( V_107 , V_207 , V_133 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_49 = V_47 -> V_49 - ( V_209 - * V_133 ) ;
V_57 = F_17 ( V_47 ) ;
V_14 = F_108 ( V_57 , V_207 , V_133 ) ;
if ( V_14 )
return V_14 ;
V_86 = V_47 -> V_86 - ( V_209 - * V_133 ) ;
if ( F_109 ( V_49 , & V_208 -> V_49 ) != 0 ||
F_109 ( V_86 , & V_208 -> V_86 ) != 0 )
return - V_177 ;
return 0 ;
}
static int
F_110 ( struct V_106 * V_137 ,
const char * V_61 ,
const struct V_9 * V_16 ,
int * V_133 )
{
struct V_146 * V_112 ;
V_112 = F_49 ( V_100 , V_137 -> V_59 . V_131 . V_61 ,
V_137 -> V_59 . V_131 . V_147 ) ;
if ( F_50 ( V_112 ) ) {
F_11 ( L_44 ,
V_137 -> V_59 . V_131 . V_61 ) ;
return F_51 ( V_112 ) ;
}
V_137 -> V_59 . V_60 . V_112 = V_112 ;
* V_133 += F_82 ( V_112 ) ;
return 0 ;
}
static void F_111 ( struct V_182 * V_47 )
{
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_32 (ematch, e)
F_44 ( V_107 -> V_59 . V_60 . V_112 -> V_140 ) ;
V_57 = F_112 ( V_47 ) ;
F_44 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
}
static int
F_113 ( struct V_182 * V_47 ,
struct V_75 * V_124 ,
unsigned int * V_133 ,
const unsigned char * V_45 ,
const unsigned char * V_156 ,
const unsigned int * V_157 ,
const unsigned int * V_158 ,
const char * V_61 )
{
struct V_106 * V_107 ;
struct V_50 * V_57 ;
struct V_151 * V_58 ;
unsigned int V_181 ;
unsigned int V_152 ;
int V_14 , V_174 , V_159 ;
F_11 ( L_45 , V_47 ) ;
if ( ( unsigned long ) V_47 % F_61 ( struct V_182 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_182 ) >= V_156 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_156 ) {
F_11 ( L_46 , V_47 , V_156 ) ;
return - V_141 ;
}
if ( V_47 -> V_86 < sizeof( struct V_182 ) +
sizeof( struct V_210 ) ) {
F_11 ( L_26 ,
V_47 , V_47 -> V_86 ) ;
return - V_141 ;
}
V_14 = F_45 ( (struct V_44 * ) V_47 ) ;
if ( V_14 )
return V_14 ;
V_174 = sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_47 - ( void * ) V_45 ;
V_152 = 0 ;
F_32 (ematch, e) {
V_14 = F_110 ( V_107 , V_61 , & V_47 -> V_16 , & V_174 ) ;
if ( V_14 != 0 )
goto V_211;
++ V_152 ;
}
V_57 = F_112 ( V_47 ) ;
V_58 = F_57 ( V_100 , V_57 -> V_59 . V_131 . V_61 ,
V_57 -> V_59 . V_131 . V_147 ) ;
if ( F_50 ( V_58 ) ) {
F_11 ( L_47 ,
V_57 -> V_59 . V_131 . V_61 ) ;
V_14 = F_51 ( V_58 ) ;
goto V_211;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_174 += F_83 ( V_58 ) ;
* V_133 += V_174 ;
V_14 = F_84 ( V_83 , V_181 , V_174 ) ;
if ( V_14 )
goto V_73;
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ( unsigned char * ) V_47 - V_45 == V_157 [ V_159 ] )
V_124 -> V_80 [ V_159 ] = V_157 [ V_159 ] ;
if ( ( unsigned char * ) V_47 - V_45 == V_158 [ V_159 ] )
V_124 -> V_120 [ V_159 ] = V_158 [ V_159 ] ;
}
memset ( & V_47 -> V_114 , 0 , sizeof( V_47 -> V_114 ) ) ;
V_47 -> V_130 = 0 ;
return 0 ;
V_73:
F_44 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
V_211:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_44 ( V_107 -> V_59 . V_60 . V_112 -> V_140 ) ;
}
return V_14 ;
}
static int
F_114 ( struct V_182 * V_47 , void * * V_207 ,
unsigned int * V_133 , const char * V_61 ,
struct V_75 * V_124 , unsigned char * V_45 )
{
struct V_50 * V_57 ;
struct V_44 * V_212 ;
unsigned int V_209 ;
int V_14 , V_159 ;
struct V_106 * V_107 ;
V_14 = 0 ;
V_209 = * V_133 ;
V_212 = (struct V_44 * ) * V_207 ;
memcpy ( V_212 , V_47 , sizeof( struct V_44 ) ) ;
memcpy ( & V_212 -> V_114 , & V_47 -> V_114 , sizeof( V_47 -> V_114 ) ) ;
* V_207 += sizeof( struct V_44 ) ;
* V_133 += sizeof( struct V_44 ) - sizeof( struct V_182 ) ;
F_32 (ematch, e) {
V_14 = F_115 ( V_107 , V_207 , V_133 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_212 -> V_49 = V_47 -> V_49 - ( V_209 - * V_133 ) ;
V_57 = F_112 ( V_47 ) ;
F_116 ( V_57 , V_207 , V_133 ) ;
V_212 -> V_86 = V_47 -> V_86 - ( V_209 - * V_133 ) ;
for ( V_159 = 0 ; V_159 < V_126 ; V_159 ++ ) {
if ( ( unsigned char * ) V_212 - V_45 < V_124 -> V_80 [ V_159 ] )
V_124 -> V_80 [ V_159 ] -= V_209 - * V_133 ;
if ( ( unsigned char * ) V_212 - V_45 < V_124 -> V_120 [ V_159 ] )
V_124 -> V_120 [ V_159 ] -= V_209 - * V_133 ;
}
return V_14 ;
}
static int F_117 ( struct V_44 * V_47 , struct V_69 * V_69 ,
const char * V_61 )
{
unsigned int V_152 ;
int V_14 = 0 ;
struct V_143 V_153 ;
struct V_106 * V_107 ;
V_47 -> V_114 . V_128 = F_55 () ;
if ( F_56 ( V_47 -> V_114 . V_128 ) )
return - V_154 ;
V_152 = 0 ;
V_153 . V_69 = V_69 ;
V_153 . V_89 = V_61 ;
V_153 . V_144 = & V_47 -> V_16 ;
V_153 . V_150 = V_47 -> V_130 ;
V_153 . V_99 = V_100 ;
F_32 (ematch, e) {
V_14 = F_46 ( V_107 , & V_153 ) ;
if ( V_14 != 0 )
goto V_155;
++ V_152 ;
}
V_14 = F_52 ( V_47 , V_69 , V_61 ) ;
if ( V_14 )
goto V_155;
return 0 ;
V_155:
F_32 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_107 , V_69 ) ;
}
F_58 ( V_47 -> V_114 . V_128 ) ;
return V_14 ;
}
static int
F_118 ( struct V_69 * V_69 ,
const char * V_61 ,
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
F_11 ( L_48 , V_2 -> V_133 ) ;
V_152 = 0 ;
F_90 ( V_83 ) ;
F_86 ( V_83 , V_164 ) ;
F_20 (iter0, entry0, total_size) {
V_14 = F_113 ( V_216 , V_2 , & V_133 ,
V_125 ,
V_125 + V_172 ,
V_157 ,
V_158 ,
V_61 ) ;
if ( V_14 != 0 )
goto V_218;
++ V_152 ;
}
V_14 = - V_141 ;
if ( V_152 != V_164 ) {
F_11 ( L_49 ,
V_152 , V_164 ) ;
goto V_218;
}
for ( V_163 = 0 ; V_163 < V_126 ; V_163 ++ ) {
if ( ! ( V_102 & ( 1 << V_163 ) ) )
continue;
if ( V_2 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_32 ,
V_163 , V_157 [ V_163 ] ) ;
goto V_218;
}
if ( V_2 -> V_120 [ V_163 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_163 , V_158 [ V_163 ] ) ;
goto V_218;
}
}
V_14 = - V_154 ;
V_124 = F_103 ( V_133 ) ;
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
V_14 = F_114 ( V_216 , & V_127 , & V_133 ,
V_61 , V_124 , V_215 ) ;
if ( V_14 != 0 )
break;
}
F_94 ( V_83 ) ;
F_96 ( V_83 ) ;
if ( V_14 )
goto V_199;
V_14 = - V_166 ;
if ( ! F_40 ( V_124 , V_102 , V_215 ) )
goto V_199;
V_163 = 0 ;
F_20 (iter1, entry1, newinfo->size) {
V_14 = F_117 ( V_217 , V_69 , V_61 ) ;
if ( V_14 != 0 )
break;
++ V_163 ;
if ( strcmp ( F_17 ( V_217 ) -> V_59 . V_131 . V_61 ,
V_62 ) == 0 )
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
F_111 ( V_216 ) ;
}
F_20 (iter1, entry1, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_63 ( V_217 , V_69 ) ;
}
F_100 ( V_124 ) ;
return V_14 ;
}
* V_213 = V_124 ;
* V_214 = V_215 ;
F_100 ( V_2 ) ;
return 0 ;
V_199:
F_100 ( V_124 ) ;
V_73:
F_20 (iter0, entry0, total_size) {
if ( V_152 -- == 0 )
break;
F_111 ( V_216 ) ;
}
return V_14 ;
V_218:
F_94 ( V_83 ) ;
F_96 ( V_83 ) ;
goto V_73;
}
static int
F_119 ( struct V_69 * V_69 , void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_220 V_168 ;
struct V_75 * V_124 ;
void * V_176 ;
struct V_44 * V_78 ;
if ( F_88 ( & V_168 , V_131 , sizeof( V_168 ) ) != 0 )
return - V_177 ;
if ( V_168 . V_133 >= V_198 / F_120 () )
return - V_154 ;
if ( V_168 . V_193 >= V_198 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_168 . V_193 == 0 )
return - V_141 ;
V_168 . V_61 [ sizeof( V_168 . V_61 ) - 1 ] = 0 ;
V_124 = F_103 ( V_168 . V_133 ) ;
if ( ! V_124 )
return - V_154 ;
V_176 = V_124 -> V_79 ;
if ( F_88 ( V_176 , V_131 + sizeof( V_168 ) ,
V_168 . V_133 ) != 0 ) {
V_14 = - V_177 ;
goto V_199;
}
V_14 = F_118 ( V_69 , V_168 . V_61 , V_168 . V_102 ,
& V_124 , & V_176 , V_168 . V_133 ,
V_168 . V_165 , V_168 . V_80 ,
V_168 . V_120 ) ;
if ( V_14 != 0 )
goto V_199;
F_11 ( L_50 ) ;
V_14 = F_98 ( V_69 , V_168 . V_61 , V_168 . V_102 , V_124 ,
V_168 . V_193 , F_121 ( V_168 . V_114 ) ) ;
if ( V_14 )
goto V_200;
return 0 ;
V_200:
F_20 (iter, loc_cpu_entry, newinfo->size)
F_63 ( V_78 , V_69 ) ;
V_199:
F_100 ( V_124 ) ;
return V_14 ;
}
static int
F_122 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 ,
unsigned int V_115 )
{
int V_14 ;
if ( ! F_123 ( F_124 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_119 ( F_124 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_228 :
V_14 = F_104 ( F_124 ( V_222 ) , V_131 , V_115 , 1 ) ;
break;
default:
F_11 ( L_51 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
static int
F_125 ( unsigned int V_172 , struct V_1 * V_89 ,
void T_4 * V_173 )
{
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
void T_4 * V_127 ;
unsigned int V_133 ;
int V_14 = 0 ;
unsigned int V_163 = 0 ;
struct V_44 * V_78 ;
V_114 = F_71 ( V_89 ) ;
if ( F_50 ( V_114 ) )
return F_51 ( V_114 ) ;
V_127 = V_173 ;
V_133 = V_172 ;
F_20 (iter, private->entries, total_size) {
V_14 = F_106 ( V_78 , & V_127 ,
& V_133 , V_114 , V_163 ++ ) ;
if ( V_14 != 0 )
break;
}
F_77 ( V_114 ) ;
return V_14 ;
}
static int
F_126 ( struct V_69 * V_69 , struct V_229 T_4 * V_189 ,
int * V_115 )
{
int V_14 ;
struct V_229 V_190 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_190 ) ) {
F_11 ( L_52 , * V_115 , sizeof( V_190 ) ) ;
return - V_141 ;
}
if ( F_88 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_177 ;
if ( * V_115 != sizeof( struct V_229 ) + V_190 . V_133 ) {
F_11 ( L_53 ,
* V_115 , sizeof( V_190 ) + V_190 . V_133 ) ;
return - V_141 ;
}
V_190 . V_61 [ sizeof( V_190 . V_61 ) - 1 ] = '\0' ;
F_90 ( V_83 ) ;
V_57 = F_92 ( V_69 , V_83 , V_190 . V_61 ) ;
if ( ! F_93 ( V_57 ) ) {
const struct V_75 * V_76 = V_57 -> V_76 ;
struct V_75 V_2 ;
F_11 ( L_38 , V_76 -> V_164 ) ;
V_14 = F_85 ( V_76 , & V_2 ) ;
if ( ! V_14 && V_190 . V_133 == V_2 . V_133 ) {
V_14 = F_125 ( V_76 -> V_133 ,
V_57 , V_189 -> V_191 ) ;
} else if ( ! V_14 ) {
F_11 ( L_54 ,
V_76 -> V_133 , V_190 . V_133 ) ;
V_14 = - V_192 ;
}
F_94 ( V_83 ) ;
F_44 ( V_57 -> V_140 ) ;
F_95 ( V_57 ) ;
} else
V_14 = V_57 ? F_51 ( V_57 ) : - V_187 ;
F_96 ( V_83 ) ;
return V_14 ;
}
static int
F_127 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_123 ( F_124 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_87 ( F_124 ( V_222 ) , V_131 , V_115 , 1 ) ;
break;
case V_231 :
V_14 = F_126 ( F_124 ( V_222 ) , V_131 , V_115 ) ;
break;
default:
V_14 = F_128 ( V_222 , V_223 , V_131 , V_115 ) ;
}
return V_14 ;
}
static int
F_129 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , unsigned int V_115 )
{
int V_14 ;
if ( ! F_123 ( F_124 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_102 ( F_124 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_228 :
V_14 = F_104 ( F_124 ( V_222 ) , V_131 , V_115 , 0 ) ;
break;
default:
F_11 ( L_51 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
static int
F_128 ( struct V_221 * V_222 , int V_223 , void T_4 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_123 ( F_124 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_87 ( F_124 ( V_222 ) , V_131 , V_115 , 0 ) ;
break;
case V_231 :
V_14 = F_97 ( F_124 ( V_222 ) , V_131 , V_115 ) ;
break;
case V_232 :
case V_233 : {
struct V_234 V_235 ;
int V_58 ;
if ( * V_115 != sizeof( V_235 ) ) {
V_14 = - V_141 ;
break;
}
if ( F_88 ( & V_235 , V_131 , sizeof( V_235 ) ) != 0 ) {
V_14 = - V_177 ;
break;
}
V_235 . V_61 [ sizeof( V_235 . V_61 ) - 1 ] = 0 ;
if ( V_223 == V_233 )
V_58 = 1 ;
else
V_58 = 0 ;
F_91 ( F_130 ( V_83 , V_235 . V_61 ,
V_235 . V_147 ,
V_58 , & V_14 ) ,
L_55 , V_235 . V_61 ) ;
break;
}
default:
F_11 ( L_56 , V_223 ) ;
V_14 = - V_141 ;
}
return V_14 ;
}
static void F_131 ( struct V_69 * V_69 , struct V_1 * V_89 )
{
struct V_75 * V_76 ;
void * V_176 ;
struct V_236 * V_237 = V_89 -> V_140 ;
struct V_44 * V_78 ;
V_76 = F_132 ( V_89 ) ;
V_176 = V_76 -> V_79 ;
F_20 (iter, loc_cpu_entry, private->size)
F_63 ( V_78 , V_69 ) ;
if ( V_76 -> V_164 > V_76 -> V_183 )
F_44 ( V_237 ) ;
F_100 ( V_76 ) ;
}
int F_133 ( struct V_69 * V_69 , const struct V_1 * V_89 ,
const struct V_161 * V_162 ,
const struct V_238 * V_239 ,
struct V_1 * * V_240 )
{
int V_14 ;
struct V_75 * V_124 ;
struct V_75 V_241 = { 0 } ;
void * V_176 ;
struct V_1 * V_242 ;
V_124 = F_103 ( V_162 -> V_133 ) ;
if ( ! V_124 )
return - V_154 ;
V_176 = V_124 -> V_79 ;
memcpy ( V_176 , V_162 -> V_79 , V_162 -> V_133 ) ;
V_14 = F_64 ( V_69 , V_124 , V_176 , V_162 ) ;
if ( V_14 != 0 )
goto V_243;
V_242 = F_134 ( V_69 , V_89 , & V_241 , V_124 ) ;
if ( F_50 ( V_242 ) ) {
V_14 = F_51 ( V_242 ) ;
goto V_243;
}
F_135 ( * V_240 , V_242 ) ;
V_14 = F_136 ( V_69 , V_239 , F_137 ( V_89 -> V_102 ) ) ;
if ( V_14 != 0 ) {
F_131 ( V_69 , V_242 ) ;
* V_240 = NULL ;
}
return V_14 ;
V_243:
F_100 ( V_124 ) ;
return V_14 ;
}
void F_138 ( struct V_69 * V_69 , struct V_1 * V_89 ,
const struct V_238 * V_239 )
{
F_139 ( V_69 , V_239 , F_137 ( V_89 -> V_102 ) ) ;
F_131 ( V_69 , V_89 ) ;
}
static inline bool
F_140 ( T_7 V_244 , T_7 V_245 , T_7 V_246 ,
T_7 type , T_7 V_247 ,
bool V_248 )
{
return ( type == V_244 && V_247 >= V_245 && V_247 <= V_246 )
^ V_248 ;
}
static bool
F_141 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_249 * V_250 ;
struct V_249 V_251 ;
const struct V_252 * V_253 = V_41 -> V_113 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_250 = F_142 ( V_6 , V_41 -> V_110 , sizeof( V_251 ) , & V_251 ) ;
if ( V_250 == NULL ) {
F_11 ( L_57 ) ;
V_41 -> V_13 = true ;
return false ;
}
return F_140 ( V_253 -> type ,
V_253 -> V_247 [ 0 ] ,
V_253 -> V_247 [ 1 ] ,
V_250 -> V_254 , V_250 -> V_255 ,
! ! ( V_253 -> V_28 & V_256 ) ) ;
}
static int F_143 ( const struct V_143 * V_41 )
{
const struct V_252 * V_253 = V_41 -> V_113 ;
return ( V_253 -> V_28 & ~ V_256 ) ? - V_141 : 0 ;
}
static int T_8 F_144 ( struct V_69 * V_69 )
{
return F_145 ( V_69 , V_100 ) ;
}
static void T_9 F_146 ( struct V_69 * V_69 )
{
F_147 ( V_69 , V_100 ) ;
}
static int T_10 F_148 ( void )
{
int V_14 ;
V_14 = F_149 ( & V_257 ) ;
if ( V_14 < 0 )
goto V_258;
V_14 = F_150 ( V_259 , F_151 ( V_259 ) ) ;
if ( V_14 < 0 )
goto V_260;
V_14 = F_152 ( V_261 , F_151 ( V_261 ) ) ;
if ( V_14 < 0 )
goto V_262;
V_14 = F_153 ( & V_263 ) ;
if ( V_14 < 0 )
goto V_264;
F_154 ( L_58 ) ;
return 0 ;
V_264:
F_155 ( V_261 , F_151 ( V_261 ) ) ;
V_262:
F_156 ( V_259 , F_151 ( V_259 ) ) ;
V_260:
F_157 ( & V_257 ) ;
V_258:
return V_14 ;
}
static void T_11 F_158 ( void )
{
F_159 ( & V_263 ) ;
F_155 ( V_261 , F_151 ( V_261 ) ) ;
F_156 ( V_259 , F_151 ( V_259 ) ) ;
F_157 ( & V_257 ) ;
}
