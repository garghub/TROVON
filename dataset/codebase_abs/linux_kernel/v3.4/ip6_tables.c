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
if( ( V_10 -> V_32 & V_33 ) ) {
int V_34 ;
unsigned short V_35 ;
V_34 = F_9 ( V_6 , V_11 , - 1 , & V_35 ) ;
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
if( V_10 -> V_28 & V_36 ) {
return false ;
}
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
if ( F_13 () )
F_14 ( L_10 , ( const char * ) V_41 -> V_42 ) ;
return V_43 ;
}
static inline struct V_44 *
F_15 ( const void * V_45 , unsigned int V_46 )
{
return (struct V_44 * ) ( V_45 + V_46 ) ;
}
static inline bool F_16 ( const struct V_9 * V_16 )
{
static const struct V_9 V_47 ;
return memcmp ( V_16 , & V_47 , sizeof( V_47 ) ) == 0 ;
}
static inline const struct V_48 *
F_17 ( const struct V_44 * V_49 )
{
return F_18 ( (struct V_44 * ) V_49 ) ;
}
static inline int
F_19 ( const struct V_44 * V_50 , const struct V_44 * V_49 ,
const char * V_51 , const char * * V_52 ,
const char * * V_53 , unsigned int * V_54 )
{
const struct V_55 * V_56 = ( void * ) F_17 ( V_50 ) ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 , V_61 ) == 0 ) {
* V_52 = V_56 -> V_57 . V_62 ;
( * V_54 ) = 0 ;
} else if ( V_50 == V_49 ) {
( * V_54 ) ++ ;
if ( V_50 -> V_63 == sizeof( struct V_44 ) &&
strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 ,
V_64 ) == 0 &&
V_56 -> V_65 < 0 &&
F_16 ( & V_50 -> V_16 ) ) {
* V_53 = * V_52 == V_51
? V_66 [ V_67 ]
: V_66 [ V_68 ] ;
}
return 1 ;
} else
( * V_54 ) ++ ;
return 0 ;
}
static void F_20 ( const struct V_5 * V_6 ,
unsigned int V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 ,
const char * V_73 ,
const struct V_74 * V_75 ,
const struct V_44 * V_49 )
{
const void * V_76 ;
const struct V_44 * V_77 ;
const char * V_51 , * V_52 , * V_53 ;
const struct V_44 * V_78 ;
unsigned int V_54 = 0 ;
V_76 = V_75 -> V_79 [ F_21 () ] ;
V_77 = F_15 ( V_76 , V_75 -> V_80 [ V_69 ] ) ;
V_51 = V_52 = V_81 [ V_69 ] ;
V_53 = V_66 [ V_82 ] ;
F_22 (iter, root, private->size - private->hook_entry[hook])
if ( F_19 ( V_78 , V_49 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_23 ( V_83 , V_69 , V_6 , V_71 , V_72 , & V_84 ,
L_11 ,
V_73 , V_52 , V_53 , V_54 ) ;
}
unsigned int
F_24 ( struct V_5 * V_6 ,
unsigned int V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 ,
struct V_1 * V_85 )
{
static const char V_86 [ V_87 ] V_88 ( ( F_25 ( sizeof( long ) ) ) ) ;
unsigned int V_65 = V_43 ;
const char * V_7 , * V_8 ;
const void * V_76 ;
struct V_44 * V_49 , * * V_89 ;
unsigned int * V_90 , V_91 , V_92 ;
const struct V_74 * V_75 ;
struct V_40 V_93 ;
unsigned int V_94 ;
V_7 = V_71 ? V_71 -> V_60 : V_86 ;
V_8 = V_72 ? V_72 -> V_60 : V_86 ;
V_93 . V_13 = false ;
V_93 . V_71 = V_71 ;
V_93 . V_72 = V_72 ;
V_93 . V_95 = V_96 ;
V_93 . V_97 = V_69 ;
F_26 ( V_85 -> V_98 & ( 1 << V_69 ) ) ;
F_27 () ;
V_94 = F_28 () ;
V_75 = V_85 -> V_75 ;
V_92 = F_21 () ;
V_76 = V_75 -> V_79 [ V_92 ] ;
V_89 = (struct V_44 * * ) V_75 -> V_89 [ V_92 ] ;
V_90 = F_29 ( V_75 -> V_90 , V_92 ) ;
V_91 = * V_90 ;
V_49 = F_15 ( V_76 , V_75 -> V_80 [ V_69 ] ) ;
do {
const struct V_48 * V_56 ;
const struct V_99 * V_100 ;
F_26 ( V_49 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_49 -> V_16 ,
& V_93 . V_101 , & V_93 . V_12 , & V_93 . V_13 ) ) {
V_102:
V_49 = F_30 ( V_49 ) ;
continue;
}
F_31 (ematch, e) {
V_93 . V_103 = V_100 -> V_58 . V_59 . V_103 ;
V_93 . V_104 = V_100 -> V_62 ;
if ( ! V_93 . V_103 -> V_103 ( V_6 , & V_93 ) )
goto V_102;
}
F_32 ( V_49 -> V_105 , V_6 -> V_106 , 1 ) ;
V_56 = F_17 ( V_49 ) ;
F_26 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_33 ( V_107 ) || \
F_33 ( V_108 )
if ( F_34 ( V_6 -> V_109 ) )
F_20 ( V_6 , V_69 , V_71 , V_72 ,
V_85 -> V_60 , V_75 , V_49 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_110 ;
V_110 = ( (struct V_55 * ) V_56 ) -> V_65 ;
if ( V_110 < 0 ) {
if ( V_110 != V_111 ) {
V_65 = ( unsigned ) ( - V_110 ) - 1 ;
break;
}
if ( * V_90 <= V_91 )
V_49 = F_15 ( V_76 ,
V_75 -> V_112 [ V_69 ] ) ;
else
V_49 = F_30 ( V_89 [ -- * V_90 ] ) ;
continue;
}
if ( V_76 + V_110 != F_30 ( V_49 ) &&
! ( V_49 -> V_16 . V_32 & V_113 ) ) {
if ( * V_90 >= V_75 -> V_114 ) {
V_65 = V_43 ;
break;
}
V_89 [ ( * V_90 ) ++ ] = V_49 ;
}
V_49 = F_15 ( V_76 , V_110 ) ;
continue;
}
V_93 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_93 . V_42 = V_56 -> V_62 ;
V_65 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_6 , & V_93 ) ;
if ( V_65 == V_115 )
V_49 = F_30 ( V_49 ) ;
else
break;
} while ( ! V_93 . V_13 );
* V_90 = V_91 ;
F_35 ( V_94 ) ;
F_36 () ;
#ifdef F_37
return V_116 ;
#else
if ( V_93 . V_13 )
return V_43 ;
else return V_65 ;
#endif
}
static int
F_38 ( const struct V_74 * V_117 ,
unsigned int V_98 , void * V_118 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_119 ; V_69 ++ ) {
unsigned int V_120 = V_117 -> V_80 [ V_69 ] ;
struct V_44 * V_49 = (struct V_44 * ) ( V_118 + V_120 ) ;
if ( ! ( V_98 & ( 1 << V_69 ) ) )
continue;
V_49 -> V_105 . V_121 = V_120 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_17 ( V_49 ) ;
int V_122 = V_49 -> V_123 & ( 1 << V_69 ) ;
if ( V_49 -> V_123 & ( 1 << V_119 ) ) {
F_39 ( L_12 ,
V_69 , V_120 , V_49 -> V_123 ) ;
return 0 ;
}
V_49 -> V_123 |= ( ( 1 << V_69 ) | ( 1 << V_119 ) ) ;
if ( ( V_49 -> V_63 == sizeof( struct V_44 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_124 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < 0 &&
F_16 ( & V_49 -> V_16 ) ) || V_122 ) {
unsigned int V_125 , V_126 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_124 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < - V_127 - 1 ) {
F_11 ( L_13
L_14 ,
V_56 -> V_65 ) ;
return 0 ;
}
do {
V_49 -> V_123 ^= ( 1 << V_119 ) ;
#ifdef F_40
if ( V_49 -> V_123
& ( 1 << V_119 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_69 , V_120 ) ;
}
#endif
V_125 = V_120 ;
V_120 = V_49 -> V_105 . V_121 ;
V_49 -> V_105 . V_121 = 0 ;
if ( V_120 == V_125 )
goto V_128;
V_49 = (struct V_44 * )
( V_118 + V_120 ) ;
} while ( V_125 == V_120 + V_49 -> V_129 );
V_126 = V_49 -> V_129 ;
V_49 = (struct V_44 * )
( V_118 + V_120 + V_126 ) ;
V_49 -> V_105 . V_121 = V_120 ;
V_120 += V_126 ;
} else {
int V_130 = V_56 -> V_65 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_124 . V_60 ,
V_64 ) == 0 &&
V_130 >= 0 ) {
if ( V_130 > V_117 -> V_126 -
sizeof( struct V_44 ) ) {
F_11 ( L_18
L_19 ,
V_130 ) ;
return 0 ;
}
F_11 ( L_20 ,
V_120 , V_130 ) ;
} else {
V_130 = V_120 + V_49 -> V_129 ;
}
V_49 = (struct V_44 * )
( V_118 + V_130 ) ;
V_49 -> V_105 . V_121 = V_120 ;
V_120 = V_130 ;
}
}
V_128:
F_11 ( L_21 , V_69 ) ;
}
return 1 ;
}
static void F_41 ( struct V_99 * V_131 , struct V_132 * V_132 )
{
struct V_133 V_41 ;
V_41 . V_132 = V_132 ;
V_41 . V_103 = V_131 -> V_58 . V_59 . V_103 ;
V_41 . V_104 = V_131 -> V_62 ;
V_41 . V_95 = V_96 ;
if ( V_41 . V_103 -> V_134 != NULL )
V_41 . V_103 -> V_134 ( & V_41 ) ;
F_42 ( V_41 . V_103 -> V_135 ) ;
}
static int
F_43 ( const struct V_44 * V_49 , const char * V_60 )
{
const struct V_48 * V_56 ;
if ( ! F_10 ( & V_49 -> V_16 ) ) {
F_11 ( L_22 , V_49 , V_60 ) ;
return - V_136 ;
}
if ( V_49 -> V_63 + sizeof( struct V_48 ) >
V_49 -> V_129 )
return - V_136 ;
V_56 = F_17 ( V_49 ) ;
if ( V_49 -> V_63 + V_56 -> V_58 . V_137 > V_49 -> V_129 )
return - V_136 ;
return 0 ;
}
static int F_44 ( struct V_99 * V_131 , struct V_138 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_139 ;
int V_14 ;
V_41 -> V_103 = V_131 -> V_58 . V_59 . V_103 ;
V_41 -> V_104 = V_131 -> V_62 ;
V_14 = F_45 ( V_41 , V_131 -> V_58 . V_140 - sizeof( * V_131 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_41 . V_103 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_46 ( struct V_99 * V_131 , struct V_138 * V_41 )
{
struct V_141 * V_103 ;
int V_14 ;
V_103 = F_47 ( V_96 , V_131 -> V_58 . V_124 . V_60 ,
V_131 -> V_58 . V_124 . V_142 ) ;
if ( F_48 ( V_103 ) ) {
F_11 ( L_24 , V_131 -> V_58 . V_124 . V_60 ) ;
return F_49 ( V_103 ) ;
}
V_131 -> V_58 . V_59 . V_103 = V_103 ;
V_14 = F_44 ( V_131 , V_41 ) ;
if ( V_14 )
goto V_143;
return 0 ;
V_143:
F_42 ( V_131 -> V_58 . V_59 . V_103 -> V_135 ) ;
return V_14 ;
}
static int F_50 ( struct V_44 * V_49 , struct V_132 * V_132 , const char * V_60 )
{
struct V_48 * V_56 = F_18 ( V_49 ) ;
struct V_144 V_41 = {
. V_132 = V_132 ,
. V_85 = V_60 ,
. V_139 = V_49 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_42 = V_56 -> V_62 ,
. V_145 = V_49 -> V_123 ,
. V_95 = V_96 ,
} ;
int V_14 ;
V_56 = F_18 ( V_49 ) ;
V_14 = F_51 ( & V_41 , V_56 -> V_58 . V_137 - sizeof( * V_56 ) ,
V_49 -> V_16 . V_37 , V_49 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_52 ( struct V_44 * V_49 , struct V_132 * V_132 , const char * V_60 ,
unsigned int V_126 )
{
struct V_48 * V_56 ;
struct V_146 * V_57 ;
int V_14 ;
unsigned int V_147 ;
struct V_138 V_148 ;
struct V_99 * V_100 ;
V_14 = F_43 ( V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_147 = 0 ;
V_148 . V_132 = V_132 ;
V_148 . V_85 = V_60 ;
V_148 . V_139 = & V_49 -> V_16 ;
V_148 . V_145 = V_49 -> V_123 ;
V_148 . V_95 = V_96 ;
F_31 (ematch, e) {
V_14 = F_46 ( V_100 , & V_148 ) ;
if ( V_14 != 0 )
goto V_149;
++ V_147 ;
}
V_56 = F_18 ( V_49 ) ;
V_57 = F_53 ( V_96 , V_56 -> V_58 . V_124 . V_60 ,
V_56 -> V_58 . V_124 . V_142 ) ;
if ( F_48 ( V_57 ) ) {
F_11 ( L_25 , V_56 -> V_58 . V_124 . V_60 ) ;
V_14 = F_49 ( V_57 ) ;
goto V_149;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_14 = F_50 ( V_49 , V_132 , V_60 ) ;
if ( V_14 )
goto V_143;
return 0 ;
V_143:
F_42 ( V_56 -> V_58 . V_59 . V_57 -> V_135 ) ;
V_149:
F_31 (ematch, e) {
if ( V_147 -- == 0 )
break;
F_41 ( V_100 , V_132 ) ;
}
return V_14 ;
}
static bool F_54 ( const struct V_44 * V_49 )
{
const struct V_48 * V_56 ;
unsigned int V_65 ;
if ( ! F_16 ( & V_49 -> V_16 ) )
return false ;
V_56 = F_17 ( V_49 ) ;
if ( strcmp ( V_56 -> V_58 . V_124 . V_60 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_55 * ) V_56 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_116 ;
}
static int
F_55 ( struct V_44 * V_49 ,
struct V_74 * V_117 ,
const unsigned char * V_45 ,
const unsigned char * V_150 ,
const unsigned int * V_151 ,
const unsigned int * V_152 ,
unsigned int V_98 )
{
unsigned int V_153 ;
if ( ( unsigned long ) V_49 % F_56 ( struct V_44 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_44 ) >= V_150 ) {
F_11 ( L_26 , V_49 ) ;
return - V_136 ;
}
if ( V_49 -> V_129
< sizeof( struct V_44 ) + sizeof( struct V_48 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_129 ) ;
return - V_136 ;
}
for ( V_153 = 0 ; V_153 < V_119 ; V_153 ++ ) {
if ( ! ( V_98 & ( 1 << V_153 ) ) )
continue;
if ( ( unsigned char * ) V_49 - V_45 == V_151 [ V_153 ] )
V_117 -> V_80 [ V_153 ] = V_151 [ V_153 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_152 [ V_153 ] ) {
if ( ! F_54 ( V_49 ) ) {
F_39 ( L_28
L_29
L_30 ) ;
return - V_136 ;
}
V_117 -> V_112 [ V_153 ] = V_152 [ V_153 ] ;
}
}
V_49 -> V_105 = ( (struct V_154 ) { 0 , 0 } ) ;
V_49 -> V_123 = 0 ;
return 0 ;
}
static void F_57 ( struct V_44 * V_49 , struct V_132 * V_132 )
{
struct V_155 V_41 ;
struct V_48 * V_56 ;
struct V_99 * V_100 ;
F_31 (ematch, e)
F_41 ( V_100 , V_132 ) ;
V_56 = F_18 ( V_49 ) ;
V_41 . V_132 = V_132 ;
V_41 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_41 . V_42 = V_56 -> V_62 ;
V_41 . V_95 = V_96 ;
if ( V_41 . V_57 -> V_134 != NULL )
V_41 . V_57 -> V_134 ( & V_41 ) ;
F_42 ( V_41 . V_57 -> V_135 ) ;
}
static int
F_58 ( struct V_132 * V_132 , struct V_74 * V_117 , void * V_118 ,
const struct V_156 * V_157 )
{
struct V_44 * V_78 ;
unsigned int V_158 ;
int V_14 = 0 ;
V_117 -> V_126 = V_157 -> V_126 ;
V_117 -> V_159 = V_157 -> V_160 ;
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
V_117 -> V_80 [ V_158 ] = 0xFFFFFFFF ;
V_117 -> V_112 [ V_158 ] = 0xFFFFFFFF ;
}
F_11 ( L_31 , V_117 -> V_126 ) ;
V_158 = 0 ;
F_22 (iter, entry0, newinfo->size) {
V_14 = F_55 ( V_78 , V_117 , V_118 ,
V_118 + V_157 -> V_126 ,
V_157 -> V_80 ,
V_157 -> V_112 ,
V_157 -> V_98 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_158 ;
if ( strcmp ( F_18 ( V_78 ) -> V_58 . V_124 . V_60 ,
V_61 ) == 0 )
++ V_117 -> V_114 ;
}
if ( V_158 != V_157 -> V_160 ) {
F_11 ( L_32 ,
V_158 , V_157 -> V_160 ) ;
return - V_136 ;
}
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
if ( ! ( V_157 -> V_98 & ( 1 << V_158 ) ) )
continue;
if ( V_117 -> V_80 [ V_158 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_158 , V_157 -> V_80 [ V_158 ] ) ;
return - V_136 ;
}
if ( V_117 -> V_112 [ V_158 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_158 , V_157 -> V_112 [ V_158 ] ) ;
return - V_136 ;
}
}
if ( ! F_38 ( V_117 , V_157 -> V_98 , V_118 ) )
return - V_161 ;
V_158 = 0 ;
F_22 (iter, entry0, newinfo->size) {
V_14 = F_52 ( V_78 , V_132 , V_157 -> V_60 , V_157 -> V_126 ) ;
if ( V_14 != 0 )
break;
++ V_158 ;
}
if ( V_14 != 0 ) {
F_22 (iter, entry0, newinfo->size) {
if ( V_158 -- == 0 )
break;
F_57 ( V_78 , V_132 ) ;
}
return V_14 ;
}
F_59 (i) {
if ( V_117 -> V_79 [ V_158 ] && V_117 -> V_79 [ V_158 ] != V_118 )
memcpy ( V_117 -> V_79 [ V_158 ] , V_118 , V_117 -> V_126 ) ;
}
return V_14 ;
}
static void
F_60 ( const struct V_74 * V_56 ,
struct V_154 V_105 [] )
{
struct V_44 * V_78 ;
unsigned int V_92 ;
unsigned int V_158 ;
F_59 (cpu) {
T_2 * V_50 = & F_61 ( V_162 , V_92 ) ;
V_158 = 0 ;
F_22 (iter, t->entries[cpu], t->size) {
T_3 V_163 , V_121 ;
unsigned int V_164 ;
do {
V_164 = F_62 ( V_50 ) ;
V_163 = V_78 -> V_105 . V_163 ;
V_121 = V_78 -> V_105 . V_121 ;
} while ( F_63 ( V_50 , V_164 ) );
F_32 ( V_105 [ V_158 ] , V_163 , V_121 ) ;
++ V_158 ;
}
}
}
static struct V_154 * F_64 ( const struct V_1 * V_85 )
{
unsigned int V_165 ;
struct V_154 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
V_165 = sizeof( struct V_154 ) * V_75 -> V_159 ;
V_105 = F_65 ( V_165 ) ;
if ( V_105 == NULL )
return F_66 ( - V_166 ) ;
F_60 ( V_75 , V_105 ) ;
return V_105 ;
}
static int
F_67 ( unsigned int V_167 ,
const struct V_1 * V_85 ,
void T_4 * V_168 )
{
unsigned int V_169 , V_170 ;
const struct V_44 * V_49 ;
struct V_154 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
int V_14 = 0 ;
const void * V_171 ;
V_105 = F_64 ( V_85 ) ;
if ( F_48 ( V_105 ) )
return F_49 ( V_105 ) ;
V_171 = V_75 -> V_79 [ F_68 () ] ;
if ( F_69 ( V_168 , V_171 , V_167 ) != 0 ) {
V_14 = - V_172 ;
goto V_173;
}
for ( V_169 = 0 , V_170 = 0 ; V_169 < V_167 ; V_169 += V_49 -> V_129 , V_170 ++ ) {
unsigned int V_158 ;
const struct V_99 * V_131 ;
const struct V_48 * V_56 ;
V_49 = (struct V_44 * ) ( V_171 + V_169 ) ;
if ( F_69 ( V_168 + V_169
+ F_70 ( struct V_44 , V_105 ) ,
& V_105 [ V_170 ] ,
sizeof( V_105 [ V_170 ] ) ) != 0 ) {
V_14 = - V_172 ;
goto V_173;
}
for ( V_158 = sizeof( struct V_44 ) ;
V_158 < V_49 -> V_63 ;
V_158 += V_131 -> V_58 . V_140 ) {
V_131 = ( void * ) V_49 + V_158 ;
if ( F_69 ( V_168 + V_169 + V_158
+ F_70 ( struct V_99 ,
V_58 . V_124 . V_60 ) ,
V_131 -> V_58 . V_59 . V_103 -> V_60 ,
strlen ( V_131 -> V_58 . V_59 . V_103 -> V_60 ) + 1 )
!= 0 ) {
V_14 = - V_172 ;
goto V_173;
}
}
V_56 = F_17 ( V_49 ) ;
if ( F_69 ( V_168 + V_169 + V_49 -> V_63
+ F_70 ( struct V_48 ,
V_58 . V_124 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_14 = - V_172 ;
goto V_173;
}
}
V_173:
F_71 ( V_105 ) ;
return V_14 ;
}
static void F_72 ( void * V_23 , const void * V_19 )
{
int V_110 = * ( V_174 * ) V_19 ;
if ( V_110 > 0 )
V_110 += F_73 ( V_83 , V_110 ) ;
memcpy ( V_23 , & V_110 , sizeof( V_110 ) ) ;
}
static int F_74 ( void T_4 * V_23 , const void * V_19 )
{
V_174 V_175 = * ( int * ) V_19 ;
if ( V_175 > 0 )
V_175 -= F_73 ( V_83 , V_175 ) ;
return F_69 ( V_23 , & V_175 , sizeof( V_175 ) ) ? - V_172 : 0 ;
}
static int F_75 ( const struct V_44 * V_49 ,
const struct V_74 * V_2 ,
const void * V_45 , struct V_74 * V_117 )
{
const struct V_99 * V_100 ;
const struct V_48 * V_56 ;
unsigned int V_176 ;
int V_169 , V_158 , V_14 ;
V_169 = sizeof( struct V_44 ) - sizeof( struct V_177 ) ;
V_176 = ( void * ) V_49 - V_45 ;
F_31 (ematch, e)
V_169 += F_76 ( V_100 -> V_58 . V_59 . V_103 ) ;
V_56 = F_17 ( V_49 ) ;
V_169 += F_77 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_117 -> V_126 -= V_169 ;
V_14 = F_78 ( V_83 , V_176 , V_169 ) ;
if ( V_14 )
return V_14 ;
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
if ( V_2 -> V_80 [ V_158 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_158 ] ) ) )
V_117 -> V_80 [ V_158 ] -= V_169 ;
if ( V_2 -> V_112 [ V_158 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_112 [ V_158 ] ) ) )
V_117 -> V_112 [ V_158 ] -= V_169 ;
}
return 0 ;
}
static int F_79 ( const struct V_74 * V_2 ,
struct V_74 * V_117 )
{
struct V_44 * V_78 ;
void * V_171 ;
int V_14 ;
if ( ! V_117 || ! V_2 )
return - V_136 ;
memcpy ( V_117 , V_2 , F_70 ( struct V_74 , V_79 ) ) ;
V_117 -> V_178 = 0 ;
V_171 = V_2 -> V_79 [ F_68 () ] ;
F_80 ( V_83 , V_2 -> V_159 ) ;
F_22 (iter, loc_cpu_entry, info->size) {
V_14 = F_75 ( V_78 , V_2 , V_171 , V_117 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_81 ( struct V_132 * V_132 , void T_4 * V_124 ,
const int * V_106 , int V_179 )
{
char V_60 [ V_180 ] ;
struct V_1 * V_56 ;
int V_14 ;
if ( * V_106 != sizeof( struct V_181 ) ) {
F_11 ( L_35 , * V_106 ,
sizeof( struct V_181 ) ) ;
return - V_136 ;
}
if ( F_82 ( V_60 , V_124 , sizeof( V_60 ) ) != 0 )
return - V_172 ;
V_60 [ V_180 - 1 ] = '\0' ;
#ifdef F_83
if ( V_179 )
F_84 ( V_83 ) ;
#endif
V_56 = F_85 ( F_86 ( V_132 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( V_56 && ! F_48 ( V_56 ) ) {
struct V_181 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_83
struct V_74 V_182 ;
if ( V_179 ) {
V_14 = F_79 ( V_75 , & V_182 ) ;
F_87 ( V_83 ) ;
V_75 = & V_182 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_98 = V_56 -> V_98 ;
memcpy ( V_2 . V_80 , V_75 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_112 , V_75 -> V_112 ,
sizeof( V_2 . V_112 ) ) ;
V_2 . V_160 = V_75 -> V_159 ;
V_2 . V_126 = V_75 -> V_126 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_69 ( V_124 , & V_2 , * V_106 ) != 0 )
V_14 = - V_172 ;
else
V_14 = 0 ;
F_88 ( V_56 ) ;
F_42 ( V_56 -> V_135 ) ;
} else
V_14 = V_56 ? F_49 ( V_56 ) : - V_183 ;
#ifdef F_83
if ( V_179 )
F_89 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_90 ( struct V_132 * V_132 , struct V_184 T_4 * V_185 ,
const int * V_106 )
{
int V_14 ;
struct V_184 V_186 ;
struct V_1 * V_56 ;
if ( * V_106 < sizeof( V_186 ) ) {
F_11 ( L_37 , * V_106 , sizeof( V_186 ) ) ;
return - V_136 ;
}
if ( F_82 ( & V_186 , V_185 , sizeof( V_186 ) ) != 0 )
return - V_172 ;
if ( * V_106 != sizeof( struct V_184 ) + V_186 . V_126 ) {
F_11 ( L_38 ,
* V_106 , sizeof( V_186 ) + V_186 . V_126 ) ;
return - V_136 ;
}
V_56 = F_86 ( V_132 , V_83 , V_186 . V_60 ) ;
if ( V_56 && ! F_48 ( V_56 ) ) {
struct V_74 * V_75 = V_56 -> V_75 ;
F_11 ( L_39 , V_75 -> V_159 ) ;
if ( V_186 . V_126 == V_75 -> V_126 )
V_14 = F_67 ( V_75 -> V_126 ,
V_56 , V_185 -> V_187 ) ;
else {
F_11 ( L_40 ,
V_75 -> V_126 , V_186 . V_126 ) ;
V_14 = - V_188 ;
}
F_42 ( V_56 -> V_135 ) ;
F_88 ( V_56 ) ;
} else
V_14 = V_56 ? F_49 ( V_56 ) : - V_183 ;
return V_14 ;
}
static int
F_91 ( struct V_132 * V_132 , const char * V_60 , unsigned int V_98 ,
struct V_74 * V_117 , unsigned int V_189 ,
void T_4 * V_190 )
{
int V_14 ;
struct V_1 * V_56 ;
struct V_74 * V_191 ;
struct V_154 * V_105 ;
const void * V_192 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_105 = F_65 ( V_189 * sizeof( struct V_154 ) ) ;
if ( ! V_105 ) {
V_14 = - V_166 ;
goto V_72;
}
V_56 = F_85 ( F_86 ( V_132 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( ! V_56 || F_48 ( V_56 ) ) {
V_14 = V_56 ? F_49 ( V_56 ) : - V_183 ;
goto V_193;
}
if ( V_98 != V_56 -> V_98 ) {
F_11 ( L_41 ,
V_98 , V_56 -> V_98 ) ;
V_14 = - V_136 ;
goto V_194;
}
V_191 = F_92 ( V_56 , V_189 , V_117 , & V_14 ) ;
if ( ! V_191 )
goto V_194;
F_11 ( L_42 ,
V_191 -> V_159 , V_191 -> V_178 , V_117 -> V_159 ) ;
if ( ( V_191 -> V_159 > V_191 -> V_178 ) ||
( V_117 -> V_159 <= V_191 -> V_178 ) )
F_42 ( V_56 -> V_135 ) ;
if ( ( V_191 -> V_159 > V_191 -> V_178 ) &&
( V_117 -> V_159 <= V_191 -> V_178 ) )
F_42 ( V_56 -> V_135 ) ;
F_60 ( V_191 , V_105 ) ;
V_192 = V_191 -> V_79 [ F_68 () ] ;
F_22 (iter, loc_cpu_old_entry, oldinfo->size)
F_57 ( V_78 , V_132 ) ;
F_93 ( V_191 ) ;
if ( F_69 ( V_190 , V_105 ,
sizeof( struct V_154 ) * V_189 ) != 0 )
V_14 = - V_172 ;
F_71 ( V_105 ) ;
F_88 ( V_56 ) ;
return V_14 ;
V_194:
F_42 ( V_56 -> V_135 ) ;
F_88 ( V_56 ) ;
V_193:
F_71 ( V_105 ) ;
V_72:
return V_14 ;
}
static int
F_94 ( struct V_132 * V_132 , const void T_4 * V_124 , unsigned int V_106 )
{
int V_14 ;
struct V_156 V_182 ;
struct V_74 * V_117 ;
void * V_171 ;
struct V_44 * V_78 ;
if ( F_82 ( & V_182 , V_124 , sizeof( V_182 ) ) != 0 )
return - V_172 ;
if ( V_182 . V_189 >= V_195 / sizeof( struct V_154 ) )
return - V_166 ;
V_182 . V_60 [ sizeof( V_182 . V_60 ) - 1 ] = 0 ;
V_117 = F_95 ( V_182 . V_126 ) ;
if ( ! V_117 )
return - V_166 ;
V_171 = V_117 -> V_79 [ F_68 () ] ;
if ( F_82 ( V_171 , V_124 + sizeof( V_182 ) ,
V_182 . V_126 ) != 0 ) {
V_14 = - V_172 ;
goto V_196;
}
V_14 = F_58 ( V_132 , V_117 , V_171 , & V_182 ) ;
if ( V_14 != 0 )
goto V_196;
F_11 ( L_43 ) ;
V_14 = F_91 ( V_132 , V_182 . V_60 , V_182 . V_98 , V_117 ,
V_182 . V_189 , V_182 . V_105 ) ;
if ( V_14 )
goto V_197;
return 0 ;
V_197:
F_22 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_78 , V_132 ) ;
V_196:
F_93 ( V_117 ) ;
return V_14 ;
}
static int
F_96 ( struct V_132 * V_132 , const void T_4 * V_124 , unsigned int V_106 ,
int V_179 )
{
unsigned int V_158 , V_198 ;
struct V_199 V_182 ;
struct V_154 * V_200 ;
unsigned int V_189 ;
char * V_60 ;
int V_126 ;
void * V_201 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_14 = 0 ;
const void * V_171 ;
struct V_44 * V_78 ;
unsigned int V_94 ;
#ifdef F_83
struct V_202 V_203 ;
if ( V_179 ) {
V_201 = & V_203 ;
V_126 = sizeof( struct V_202 ) ;
} else
#endif
{
V_201 = & V_182 ;
V_126 = sizeof( struct V_199 ) ;
}
if ( F_82 ( V_201 , V_124 , V_126 ) != 0 )
return - V_172 ;
#ifdef F_83
if ( V_179 ) {
V_189 = V_203 . V_189 ;
V_60 = V_203 . V_60 ;
} else
#endif
{
V_189 = V_182 . V_189 ;
V_60 = V_182 . V_60 ;
}
if ( V_106 != V_126 + V_189 * sizeof( struct V_154 ) )
return - V_136 ;
V_200 = F_97 ( V_106 - V_126 ) ;
if ( ! V_200 )
return - V_166 ;
if ( F_82 ( V_200 , V_124 + V_126 , V_106 - V_126 ) != 0 ) {
V_14 = - V_172 ;
goto free;
}
V_56 = F_86 ( V_132 , V_83 , V_60 ) ;
if ( ! V_56 || F_48 ( V_56 ) ) {
V_14 = V_56 ? F_49 ( V_56 ) : - V_183 ;
goto free;
}
F_27 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_159 != V_189 ) {
V_14 = - V_136 ;
goto V_204;
}
V_158 = 0 ;
V_198 = F_21 () ;
V_94 = F_28 () ;
V_171 = V_75 -> V_79 [ V_198 ] ;
F_22 (iter, loc_cpu_entry, private->size) {
F_32 ( V_78 -> V_105 , V_200 [ V_158 ] . V_163 , V_200 [ V_158 ] . V_121 ) ;
++ V_158 ;
}
F_35 ( V_94 ) ;
V_204:
F_36 () ;
F_88 ( V_56 ) ;
F_42 ( V_56 -> V_135 ) ;
free:
F_71 ( V_200 ) ;
return V_14 ;
}
static int
F_98 ( struct V_44 * V_49 , void T_4 * * V_205 ,
unsigned int * V_126 , struct V_154 * V_105 ,
unsigned int V_158 )
{
struct V_48 * V_56 ;
struct V_177 T_4 * V_206 ;
T_5 V_63 , V_129 ;
T_6 V_207 ;
const struct V_99 * V_100 ;
int V_14 = 0 ;
V_207 = * V_126 ;
V_206 = (struct V_177 T_4 * ) * V_205 ;
if ( F_69 ( V_206 , V_49 , sizeof( struct V_44 ) ) != 0 ||
F_69 ( & V_206 -> V_105 , & V_105 [ V_158 ] ,
sizeof( V_105 [ V_158 ] ) ) != 0 )
return - V_172 ;
* V_205 += sizeof( struct V_177 ) ;
* V_126 -= sizeof( struct V_44 ) - sizeof( struct V_177 ) ;
F_31 (ematch, e) {
V_14 = F_99 ( V_100 , V_205 , V_126 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_63 = V_49 -> V_63 - ( V_207 - * V_126 ) ;
V_56 = F_18 ( V_49 ) ;
V_14 = F_100 ( V_56 , V_205 , V_126 ) ;
if ( V_14 )
return V_14 ;
V_129 = V_49 -> V_129 - ( V_207 - * V_126 ) ;
if ( F_101 ( V_63 , & V_206 -> V_63 ) != 0 ||
F_101 ( V_129 , & V_206 -> V_129 ) != 0 )
return - V_172 ;
return 0 ;
}
static int
F_102 ( struct V_99 * V_131 ,
const char * V_60 ,
const struct V_9 * V_16 ,
unsigned int V_208 ,
int * V_126 )
{
struct V_141 * V_103 ;
V_103 = F_47 ( V_96 , V_131 -> V_58 . V_124 . V_60 ,
V_131 -> V_58 . V_124 . V_142 ) ;
if ( F_48 ( V_103 ) ) {
F_11 ( L_44 ,
V_131 -> V_58 . V_124 . V_60 ) ;
return F_49 ( V_103 ) ;
}
V_131 -> V_58 . V_59 . V_103 = V_103 ;
* V_126 += F_76 ( V_103 ) ;
return 0 ;
}
static void F_103 ( struct V_177 * V_49 )
{
struct V_48 * V_56 ;
struct V_99 * V_100 ;
F_31 (ematch, e)
F_42 ( V_100 -> V_58 . V_59 . V_103 -> V_135 ) ;
V_56 = F_104 ( V_49 ) ;
F_42 ( V_56 -> V_58 . V_59 . V_57 -> V_135 ) ;
}
static int
F_105 ( struct V_177 * V_49 ,
struct V_74 * V_117 ,
unsigned int * V_126 ,
const unsigned char * V_45 ,
const unsigned char * V_150 ,
const unsigned int * V_151 ,
const unsigned int * V_152 ,
const char * V_60 )
{
struct V_99 * V_100 ;
struct V_48 * V_56 ;
struct V_146 * V_57 ;
unsigned int V_176 ;
unsigned int V_147 ;
int V_14 , V_169 , V_153 ;
F_11 ( L_45 , V_49 ) ;
if ( ( unsigned long ) V_49 % F_56 ( struct V_177 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_177 ) >= V_150 ) {
F_11 ( L_46 , V_49 , V_150 ) ;
return - V_136 ;
}
if ( V_49 -> V_129 < sizeof( struct V_177 ) +
sizeof( struct V_209 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_129 ) ;
return - V_136 ;
}
V_14 = F_43 ( (struct V_44 * ) V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_169 = sizeof( struct V_44 ) - sizeof( struct V_177 ) ;
V_176 = ( void * ) V_49 - ( void * ) V_45 ;
V_147 = 0 ;
F_31 (ematch, e) {
V_14 = F_102 ( V_100 , V_60 ,
& V_49 -> V_16 , V_49 -> V_123 , & V_169 ) ;
if ( V_14 != 0 )
goto V_210;
++ V_147 ;
}
V_56 = F_104 ( V_49 ) ;
V_57 = F_53 ( V_96 , V_56 -> V_58 . V_124 . V_60 ,
V_56 -> V_58 . V_124 . V_142 ) ;
if ( F_48 ( V_57 ) ) {
F_11 ( L_47 ,
V_56 -> V_58 . V_124 . V_60 ) ;
V_14 = F_49 ( V_57 ) ;
goto V_210;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_169 += F_77 ( V_57 ) ;
* V_126 += V_169 ;
V_14 = F_78 ( V_83 , V_176 , V_169 ) ;
if ( V_14 )
goto V_72;
for ( V_153 = 0 ; V_153 < V_119 ; V_153 ++ ) {
if ( ( unsigned char * ) V_49 - V_45 == V_151 [ V_153 ] )
V_117 -> V_80 [ V_153 ] = V_151 [ V_153 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_152 [ V_153 ] )
V_117 -> V_112 [ V_153 ] = V_152 [ V_153 ] ;
}
memset ( & V_49 -> V_105 , 0 , sizeof( V_49 -> V_105 ) ) ;
V_49 -> V_123 = 0 ;
return 0 ;
V_72:
F_42 ( V_56 -> V_58 . V_59 . V_57 -> V_135 ) ;
V_210:
F_31 (ematch, e) {
if ( V_147 -- == 0 )
break;
F_42 ( V_100 -> V_58 . V_59 . V_103 -> V_135 ) ;
}
return V_14 ;
}
static int
F_106 ( struct V_177 * V_49 , void * * V_205 ,
unsigned int * V_126 , const char * V_60 ,
struct V_74 * V_117 , unsigned char * V_45 )
{
struct V_48 * V_56 ;
struct V_44 * V_211 ;
unsigned int V_207 ;
int V_14 , V_153 ;
struct V_99 * V_100 ;
V_14 = 0 ;
V_207 = * V_126 ;
V_211 = (struct V_44 * ) * V_205 ;
memcpy ( V_211 , V_49 , sizeof( struct V_44 ) ) ;
memcpy ( & V_211 -> V_105 , & V_49 -> V_105 , sizeof( V_49 -> V_105 ) ) ;
* V_205 += sizeof( struct V_44 ) ;
* V_126 += sizeof( struct V_44 ) - sizeof( struct V_177 ) ;
F_31 (ematch, e) {
V_14 = F_107 ( V_100 , V_205 , V_126 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_211 -> V_63 = V_49 -> V_63 - ( V_207 - * V_126 ) ;
V_56 = F_104 ( V_49 ) ;
F_108 ( V_56 , V_205 , V_126 ) ;
V_211 -> V_129 = V_49 -> V_129 - ( V_207 - * V_126 ) ;
for ( V_153 = 0 ; V_153 < V_119 ; V_153 ++ ) {
if ( ( unsigned char * ) V_211 - V_45 < V_117 -> V_80 [ V_153 ] )
V_117 -> V_80 [ V_153 ] -= V_207 - * V_126 ;
if ( ( unsigned char * ) V_211 - V_45 < V_117 -> V_112 [ V_153 ] )
V_117 -> V_112 [ V_153 ] -= V_207 - * V_126 ;
}
return V_14 ;
}
static int F_109 ( struct V_44 * V_49 , struct V_132 * V_132 ,
const char * V_60 )
{
unsigned int V_147 ;
int V_14 = 0 ;
struct V_138 V_148 ;
struct V_99 * V_100 ;
V_147 = 0 ;
V_148 . V_132 = V_132 ;
V_148 . V_85 = V_60 ;
V_148 . V_139 = & V_49 -> V_16 ;
V_148 . V_145 = V_49 -> V_123 ;
V_148 . V_95 = V_96 ;
F_31 (ematch, e) {
V_14 = F_44 ( V_100 , & V_148 ) ;
if ( V_14 != 0 )
goto V_149;
++ V_147 ;
}
V_14 = F_50 ( V_49 , V_132 , V_60 ) ;
if ( V_14 )
goto V_149;
return 0 ;
V_149:
F_31 (ematch, e) {
if ( V_147 -- == 0 )
break;
F_41 ( V_100 , V_132 ) ;
}
return V_14 ;
}
static int
F_110 ( struct V_132 * V_132 ,
const char * V_60 ,
unsigned int V_98 ,
struct V_74 * * V_212 ,
void * * V_213 ,
unsigned int V_167 ,
unsigned int V_159 ,
unsigned int * V_151 ,
unsigned int * V_152 )
{
unsigned int V_158 , V_147 ;
struct V_74 * V_117 , * V_2 ;
void * V_120 , * V_118 , * V_214 ;
struct V_177 * V_215 ;
struct V_44 * V_216 ;
unsigned int V_126 ;
int V_14 = 0 ;
V_2 = * V_212 ;
V_118 = * V_213 ;
V_126 = V_167 ;
V_2 -> V_159 = V_159 ;
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
V_2 -> V_80 [ V_158 ] = 0xFFFFFFFF ;
V_2 -> V_112 [ V_158 ] = 0xFFFFFFFF ;
}
F_11 ( L_48 , V_2 -> V_126 ) ;
V_147 = 0 ;
F_84 ( V_83 ) ;
F_80 ( V_83 , V_159 ) ;
F_22 (iter0, entry0, total_size) {
V_14 = F_105 ( V_215 , V_2 , & V_126 ,
V_118 ,
V_118 + V_167 ,
V_151 ,
V_152 ,
V_60 ) ;
if ( V_14 != 0 )
goto V_217;
++ V_147 ;
}
V_14 = - V_136 ;
if ( V_147 != V_159 ) {
F_11 ( L_49 ,
V_147 , V_159 ) ;
goto V_217;
}
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
if ( ! ( V_98 & ( 1 << V_158 ) ) )
continue;
if ( V_2 -> V_80 [ V_158 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_158 , V_151 [ V_158 ] ) ;
goto V_217;
}
if ( V_2 -> V_112 [ V_158 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_158 , V_152 [ V_158 ] ) ;
goto V_217;
}
}
V_14 = - V_166 ;
V_117 = F_95 ( V_126 ) ;
if ( ! V_117 )
goto V_217;
V_117 -> V_159 = V_159 ;
for ( V_158 = 0 ; V_158 < V_119 ; V_158 ++ ) {
V_117 -> V_80 [ V_158 ] = V_2 -> V_80 [ V_158 ] ;
V_117 -> V_112 [ V_158 ] = V_2 -> V_112 [ V_158 ] ;
}
V_214 = V_117 -> V_79 [ F_68 () ] ;
V_120 = V_214 ;
V_126 = V_167 ;
F_22 (iter0, entry0, total_size) {
V_14 = F_106 ( V_215 , & V_120 , & V_126 ,
V_60 , V_117 , V_214 ) ;
if ( V_14 != 0 )
break;
}
F_87 ( V_83 ) ;
F_89 ( V_83 ) ;
if ( V_14 )
goto V_196;
V_14 = - V_161 ;
if ( ! F_38 ( V_117 , V_98 , V_214 ) )
goto V_196;
V_158 = 0 ;
F_22 (iter1, entry1, newinfo->size) {
V_14 = F_109 ( V_216 , V_132 , V_60 ) ;
if ( V_14 != 0 )
break;
++ V_158 ;
if ( strcmp ( F_18 ( V_216 ) -> V_58 . V_124 . V_60 ,
V_61 ) == 0 )
++ V_117 -> V_114 ;
}
if ( V_14 ) {
int V_218 = V_158 ;
V_147 -= V_158 ;
F_22 (iter0, entry0, newinfo->size) {
if ( V_218 -- > 0 )
continue;
if ( V_147 -- == 0 )
break;
F_103 ( V_215 ) ;
}
F_22 (iter1, entry1, newinfo->size) {
if ( V_158 -- == 0 )
break;
F_57 ( V_216 , V_132 ) ;
}
F_93 ( V_117 ) ;
return V_14 ;
}
F_59 (i)
if ( V_117 -> V_79 [ V_158 ] && V_117 -> V_79 [ V_158 ] != V_214 )
memcpy ( V_117 -> V_79 [ V_158 ] , V_214 , V_117 -> V_126 ) ;
* V_212 = V_117 ;
* V_213 = V_214 ;
F_93 ( V_2 ) ;
return 0 ;
V_196:
F_93 ( V_117 ) ;
V_72:
F_22 (iter0, entry0, total_size) {
if ( V_147 -- == 0 )
break;
F_103 ( V_215 ) ;
}
return V_14 ;
V_217:
F_87 ( V_83 ) ;
F_89 ( V_83 ) ;
goto V_72;
}
static int
F_111 ( struct V_132 * V_132 , void T_4 * V_124 , unsigned int V_106 )
{
int V_14 ;
struct V_219 V_182 ;
struct V_74 * V_117 ;
void * V_171 ;
struct V_44 * V_78 ;
if ( F_82 ( & V_182 , V_124 , sizeof( V_182 ) ) != 0 )
return - V_172 ;
if ( V_182 . V_126 >= V_195 / F_112 () )
return - V_166 ;
if ( V_182 . V_189 >= V_195 / sizeof( struct V_154 ) )
return - V_166 ;
V_182 . V_60 [ sizeof( V_182 . V_60 ) - 1 ] = 0 ;
V_117 = F_95 ( V_182 . V_126 ) ;
if ( ! V_117 )
return - V_166 ;
V_171 = V_117 -> V_79 [ F_68 () ] ;
if ( F_82 ( V_171 , V_124 + sizeof( V_182 ) ,
V_182 . V_126 ) != 0 ) {
V_14 = - V_172 ;
goto V_196;
}
V_14 = F_110 ( V_132 , V_182 . V_60 , V_182 . V_98 ,
& V_117 , & V_171 , V_182 . V_126 ,
V_182 . V_160 , V_182 . V_80 ,
V_182 . V_112 ) ;
if ( V_14 != 0 )
goto V_196;
F_11 ( L_50 ) ;
V_14 = F_91 ( V_132 , V_182 . V_60 , V_182 . V_98 , V_117 ,
V_182 . V_189 , F_113 ( V_182 . V_105 ) ) ;
if ( V_14 )
goto V_197;
return 0 ;
V_197:
F_22 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_78 , V_132 ) ;
V_196:
F_93 ( V_117 ) ;
return V_14 ;
}
static int
F_114 ( struct V_220 * V_221 , int V_222 , void T_4 * V_124 ,
unsigned int V_106 )
{
int V_14 ;
if ( ! F_115 ( V_223 ) )
return - V_224 ;
switch ( V_222 ) {
case V_225 :
V_14 = F_111 ( F_116 ( V_221 ) , V_124 , V_106 ) ;
break;
case V_226 :
V_14 = F_96 ( F_116 ( V_221 ) , V_124 , V_106 , 1 ) ;
break;
default:
F_11 ( L_51 , V_222 ) ;
V_14 = - V_136 ;
}
return V_14 ;
}
static int
F_117 ( unsigned int V_167 , struct V_1 * V_85 ,
void T_4 * V_168 )
{
struct V_154 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
void T_4 * V_120 ;
unsigned int V_126 ;
int V_14 = 0 ;
const void * V_171 ;
unsigned int V_158 = 0 ;
struct V_44 * V_78 ;
V_105 = F_64 ( V_85 ) ;
if ( F_48 ( V_105 ) )
return F_49 ( V_105 ) ;
V_171 = V_75 -> V_79 [ F_68 () ] ;
V_120 = V_168 ;
V_126 = V_167 ;
F_22 (iter, loc_cpu_entry, total_size) {
V_14 = F_98 ( V_78 , & V_120 ,
& V_126 , V_105 , V_158 ++ ) ;
if ( V_14 != 0 )
break;
}
F_71 ( V_105 ) ;
return V_14 ;
}
static int
F_118 ( struct V_132 * V_132 , struct V_227 T_4 * V_185 ,
int * V_106 )
{
int V_14 ;
struct V_227 V_186 ;
struct V_1 * V_56 ;
if ( * V_106 < sizeof( V_186 ) ) {
F_11 ( L_52 , * V_106 , sizeof( V_186 ) ) ;
return - V_136 ;
}
if ( F_82 ( & V_186 , V_185 , sizeof( V_186 ) ) != 0 )
return - V_172 ;
if ( * V_106 != sizeof( struct V_227 ) + V_186 . V_126 ) {
F_11 ( L_53 ,
* V_106 , sizeof( V_186 ) + V_186 . V_126 ) ;
return - V_136 ;
}
F_84 ( V_83 ) ;
V_56 = F_86 ( V_132 , V_83 , V_186 . V_60 ) ;
if ( V_56 && ! F_48 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
F_11 ( L_39 , V_75 -> V_159 ) ;
V_14 = F_79 ( V_75 , & V_2 ) ;
if ( ! V_14 && V_186 . V_126 == V_2 . V_126 ) {
V_14 = F_117 ( V_75 -> V_126 ,
V_56 , V_185 -> V_187 ) ;
} else if ( ! V_14 ) {
F_11 ( L_54 ,
V_75 -> V_126 , V_186 . V_126 ) ;
V_14 = - V_188 ;
}
F_87 ( V_83 ) ;
F_42 ( V_56 -> V_135 ) ;
F_88 ( V_56 ) ;
} else
V_14 = V_56 ? F_49 ( V_56 ) : - V_183 ;
F_89 ( V_83 ) ;
return V_14 ;
}
static int
F_119 ( struct V_220 * V_221 , int V_222 , void T_4 * V_124 , int * V_106 )
{
int V_14 ;
if ( ! F_115 ( V_223 ) )
return - V_224 ;
switch ( V_222 ) {
case V_228 :
V_14 = F_81 ( F_116 ( V_221 ) , V_124 , V_106 , 1 ) ;
break;
case V_229 :
V_14 = F_118 ( F_116 ( V_221 ) , V_124 , V_106 ) ;
break;
default:
V_14 = F_120 ( V_221 , V_222 , V_124 , V_106 ) ;
}
return V_14 ;
}
static int
F_121 ( struct V_220 * V_221 , int V_222 , void T_4 * V_124 , unsigned int V_106 )
{
int V_14 ;
if ( ! F_115 ( V_223 ) )
return - V_224 ;
switch ( V_222 ) {
case V_225 :
V_14 = F_94 ( F_116 ( V_221 ) , V_124 , V_106 ) ;
break;
case V_226 :
V_14 = F_96 ( F_116 ( V_221 ) , V_124 , V_106 , 0 ) ;
break;
default:
F_11 ( L_51 , V_222 ) ;
V_14 = - V_136 ;
}
return V_14 ;
}
static int
F_120 ( struct V_220 * V_221 , int V_222 , void T_4 * V_124 , int * V_106 )
{
int V_14 ;
if ( ! F_115 ( V_223 ) )
return - V_224 ;
switch ( V_222 ) {
case V_228 :
V_14 = F_81 ( F_116 ( V_221 ) , V_124 , V_106 , 0 ) ;
break;
case V_229 :
V_14 = F_90 ( F_116 ( V_221 ) , V_124 , V_106 ) ;
break;
case V_230 :
case V_231 : {
struct V_232 V_233 ;
int V_57 ;
if ( * V_106 != sizeof( V_233 ) ) {
V_14 = - V_136 ;
break;
}
if ( F_82 ( & V_233 , V_124 , sizeof( V_233 ) ) != 0 ) {
V_14 = - V_172 ;
break;
}
V_233 . V_60 [ sizeof( V_233 . V_60 ) - 1 ] = 0 ;
if ( V_222 == V_231 )
V_57 = 1 ;
else
V_57 = 0 ;
F_85 ( F_122 ( V_83 , V_233 . V_60 ,
V_233 . V_142 ,
V_57 , & V_14 ) ,
L_55 , V_233 . V_60 ) ;
break;
}
default:
F_11 ( L_56 , V_222 ) ;
V_14 = - V_136 ;
}
return V_14 ;
}
struct V_1 * F_123 ( struct V_132 * V_132 ,
const struct V_1 * V_85 ,
const struct V_156 * V_157 )
{
int V_14 ;
struct V_74 * V_117 ;
struct V_74 V_234 = { 0 } ;
void * V_171 ;
struct V_1 * V_235 ;
V_117 = F_95 ( V_157 -> V_126 ) ;
if ( ! V_117 ) {
V_14 = - V_166 ;
goto V_72;
}
V_171 = V_117 -> V_79 [ F_68 () ] ;
memcpy ( V_171 , V_157 -> V_79 , V_157 -> V_126 ) ;
V_14 = F_58 ( V_132 , V_117 , V_171 , V_157 ) ;
if ( V_14 != 0 )
goto V_236;
V_235 = F_124 ( V_132 , V_85 , & V_234 , V_117 ) ;
if ( F_48 ( V_235 ) ) {
V_14 = F_49 ( V_235 ) ;
goto V_236;
}
return V_235 ;
V_236:
F_93 ( V_117 ) ;
V_72:
return F_66 ( V_14 ) ;
}
void F_125 ( struct V_132 * V_132 , struct V_1 * V_85 )
{
struct V_74 * V_75 ;
void * V_171 ;
struct V_237 * V_238 = V_85 -> V_135 ;
struct V_44 * V_78 ;
V_75 = F_126 ( V_85 ) ;
V_171 = V_75 -> V_79 [ F_68 () ] ;
F_22 (iter, loc_cpu_entry, private->size)
F_57 ( V_78 , V_132 ) ;
if ( V_75 -> V_159 > V_75 -> V_178 )
F_42 ( V_238 ) ;
F_93 ( V_75 ) ;
}
static inline bool
F_127 ( T_7 V_239 , T_7 V_240 , T_7 V_241 ,
T_7 type , T_7 V_242 ,
bool V_243 )
{
return ( type == V_239 && V_242 >= V_240 && V_242 <= V_241 )
^ V_243 ;
}
static bool
F_128 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_244 * V_245 ;
struct V_244 V_246 ;
const struct V_247 * V_248 = V_41 -> V_104 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_245 = F_129 ( V_6 , V_41 -> V_101 , sizeof( V_246 ) , & V_246 ) ;
if ( V_245 == NULL ) {
F_11 ( L_57 ) ;
V_41 -> V_13 = true ;
return false ;
}
return F_127 ( V_248 -> type ,
V_248 -> V_242 [ 0 ] ,
V_248 -> V_242 [ 1 ] ,
V_245 -> V_249 , V_245 -> V_250 ,
! ! ( V_248 -> V_28 & V_251 ) ) ;
}
static int F_130 ( const struct V_138 * V_41 )
{
const struct V_247 * V_248 = V_41 -> V_104 ;
return ( V_248 -> V_28 & ~ V_251 ) ? - V_136 : 0 ;
}
static int T_8 F_131 ( struct V_132 * V_132 )
{
return F_132 ( V_132 , V_96 ) ;
}
static void T_9 F_133 ( struct V_132 * V_132 )
{
F_134 ( V_132 , V_96 ) ;
}
static int T_10 F_135 ( void )
{
int V_14 ;
V_14 = F_136 ( & V_252 ) ;
if ( V_14 < 0 )
goto V_253;
V_14 = F_137 ( V_254 , F_138 ( V_254 ) ) ;
if ( V_14 < 0 )
goto V_255;
V_14 = F_139 ( V_256 , F_138 ( V_256 ) ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_140 ( & V_258 ) ;
if ( V_14 < 0 )
goto V_259;
F_14 ( L_58 ) ;
return 0 ;
V_259:
F_141 ( V_256 , F_138 ( V_256 ) ) ;
V_257:
F_142 ( V_254 , F_138 ( V_254 ) ) ;
V_255:
F_143 ( & V_252 ) ;
V_253:
return V_14 ;
}
static void T_11 F_144 ( void )
{
F_145 ( & V_258 ) ;
F_141 ( V_256 , F_138 ( V_256 ) ) ;
F_142 ( V_254 , F_138 ( V_254 ) ) ;
F_143 ( & V_252 ) ;
}
int F_9 ( const struct V_5 * V_6 , unsigned int * V_46 ,
int V_57 , unsigned short * V_12 )
{
unsigned int V_164 = F_146 ( V_6 ) + sizeof( struct V_15 ) ;
T_12 V_260 = F_4 ( V_6 ) -> V_260 ;
unsigned int V_106 = V_6 -> V_106 - V_164 ;
if ( V_12 )
* V_12 = 0 ;
while ( V_260 != V_57 ) {
struct V_261 V_262 , * V_263 ;
unsigned int V_264 ;
if ( ( ! F_147 ( V_260 ) ) || V_260 == V_265 ) {
if ( V_57 < 0 )
break;
return - V_183 ;
}
V_263 = F_129 ( V_6 , V_164 , sizeof( V_262 ) , & V_262 ) ;
if ( V_263 == NULL )
return - V_266 ;
if ( V_260 == V_267 ) {
unsigned short V_35 ;
T_13 * V_268 ;
V_268 = F_129 ( V_6 ,
V_164 + F_70 ( struct V_269 ,
V_270 ) ,
sizeof( V_35 ) ,
& V_35 ) ;
if ( V_268 == NULL )
return - V_266 ;
V_35 = F_148 ( * V_268 ) & ~ 0x7 ;
if ( V_35 ) {
if ( V_57 < 0 &&
( ( ! F_147 ( V_263 -> V_260 ) ) ||
V_263 -> V_260 == V_265 ) ) {
if ( V_12 )
* V_12 = V_35 ;
return V_263 -> V_260 ;
}
return - V_183 ;
}
V_264 = 8 ;
} else if ( V_260 == V_271 )
V_264 = ( V_263 -> V_264 + 2 ) << 2 ;
else
V_264 = F_149 ( V_263 ) ;
V_260 = V_263 -> V_260 ;
V_106 -= V_264 ;
V_164 += V_264 ;
}
* V_46 = V_164 ;
return V_260 ;
}
