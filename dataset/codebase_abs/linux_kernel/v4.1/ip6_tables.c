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
static void F_19 ( const struct V_5 * V_6 ,
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
struct V_79 * V_79 = F_20 ( V_71 ? V_71 : V_72 ) ;
V_76 = V_75 -> V_80 [ F_21 () ] ;
V_77 = F_14 ( V_76 , V_75 -> V_81 [ V_69 ] ) ;
V_51 = V_52 = V_82 [ V_69 ] ;
V_53 = V_66 [ V_83 ] ;
F_22 (iter, root, private->size - private->hook_entry[hook])
if ( F_18 ( V_78 , V_49 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_23 ( V_79 , V_84 , V_69 , V_6 , V_71 , V_72 , & V_85 ,
L_11 ,
V_73 , V_52 , V_53 , V_54 ) ;
}
unsigned int
F_24 ( struct V_5 * V_6 ,
unsigned int V_69 ,
const struct V_86 * V_87 ,
struct V_1 * V_88 )
{
static const char V_89 [ V_90 ] V_91 ( ( F_25 ( sizeof( long ) ) ) ) ;
unsigned int V_65 = V_43 ;
const char * V_7 , * V_8 ;
const void * V_76 ;
struct V_44 * V_49 , * * V_92 ;
unsigned int * V_93 , V_94 , V_95 ;
const struct V_74 * V_75 ;
struct V_40 V_96 ;
unsigned int V_97 ;
V_7 = V_87 -> V_71 ? V_87 -> V_71 -> V_60 : V_89 ;
V_8 = V_87 -> V_72 ? V_87 -> V_72 -> V_60 : V_89 ;
V_96 . V_13 = false ;
V_96 . V_71 = V_87 -> V_71 ;
V_96 . V_72 = V_87 -> V_72 ;
V_96 . V_98 = V_99 ;
V_96 . V_100 = V_69 ;
F_26 ( V_88 -> V_101 & ( 1 << V_69 ) ) ;
F_27 () ;
V_97 = F_28 () ;
V_75 = V_88 -> V_75 ;
F_29 () ;
V_95 = F_21 () ;
V_76 = V_75 -> V_80 [ V_95 ] ;
V_92 = (struct V_44 * * ) V_75 -> V_92 [ V_95 ] ;
V_93 = F_30 ( V_75 -> V_93 , V_95 ) ;
V_94 = * V_93 ;
V_49 = F_14 ( V_76 , V_75 -> V_81 [ V_69 ] ) ;
do {
const struct V_48 * V_56 ;
const struct V_102 * V_103 ;
F_26 ( V_49 ) ;
V_96 . V_104 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_49 -> V_16 ,
& V_96 . V_104 , & V_96 . V_12 , & V_96 . V_13 ) ) {
V_105:
V_49 = F_31 ( V_49 ) ;
continue;
}
F_32 (ematch, e) {
V_96 . V_106 = V_103 -> V_58 . V_59 . V_106 ;
V_96 . V_107 = V_103 -> V_62 ;
if ( ! V_96 . V_106 -> V_106 ( V_6 , & V_96 ) )
goto V_105;
}
F_33 ( V_49 -> V_108 , V_6 -> V_109 , 1 ) ;
V_56 = F_16 ( V_49 ) ;
F_26 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_34 ( V_110 )
if ( F_35 ( V_6 -> V_111 ) )
F_19 ( V_6 , V_69 , V_87 -> V_71 , V_87 -> V_72 ,
V_88 -> V_60 , V_75 , V_49 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_112 ;
V_112 = ( (struct V_55 * ) V_56 ) -> V_65 ;
if ( V_112 < 0 ) {
if ( V_112 != V_113 ) {
V_65 = ( unsigned int ) ( - V_112 ) - 1 ;
break;
}
if ( * V_93 <= V_94 )
V_49 = F_14 ( V_76 ,
V_75 -> V_114 [ V_69 ] ) ;
else
V_49 = F_31 ( V_92 [ -- * V_93 ] ) ;
continue;
}
if ( V_76 + V_112 != F_31 ( V_49 ) &&
! ( V_49 -> V_16 . V_32 & V_115 ) ) {
if ( * V_93 >= V_75 -> V_116 ) {
V_65 = V_43 ;
break;
}
V_92 [ ( * V_93 ) ++ ] = V_49 ;
}
V_49 = F_14 ( V_76 , V_112 ) ;
continue;
}
V_96 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_96 . V_42 = V_56 -> V_62 ;
V_65 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_6 , & V_96 ) ;
if ( V_65 == V_117 )
V_49 = F_31 ( V_49 ) ;
else
break;
} while ( ! V_96 . V_13 );
* V_93 = V_94 ;
F_36 ( V_97 ) ;
F_37 () ;
#ifdef F_38
return V_118 ;
#else
if ( V_96 . V_13 )
return V_43 ;
else return V_65 ;
#endif
}
static int
F_39 ( const struct V_74 * V_119 ,
unsigned int V_101 , void * V_120 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_121 ; V_69 ++ ) {
unsigned int V_122 = V_119 -> V_81 [ V_69 ] ;
struct V_44 * V_49 = (struct V_44 * ) ( V_120 + V_122 ) ;
if ( ! ( V_101 & ( 1 << V_69 ) ) )
continue;
V_49 -> V_108 . V_123 = V_122 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_16 ( V_49 ) ;
int V_124 = V_49 -> V_125 & ( 1 << V_69 ) ;
if ( V_49 -> V_125 & ( 1 << V_121 ) ) {
F_40 ( L_12 ,
V_69 , V_122 , V_49 -> V_125 ) ;
return 0 ;
}
V_49 -> V_125 |= ( ( 1 << V_69 ) | ( 1 << V_121 ) ) ;
if ( ( V_49 -> V_63 == sizeof( struct V_44 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_126 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < 0 &&
F_15 ( & V_49 -> V_16 ) ) || V_124 ) {
unsigned int V_127 , V_128 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_126 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < - V_129 - 1 ) {
F_11 ( L_13
L_14 ,
V_56 -> V_65 ) ;
return 0 ;
}
do {
V_49 -> V_125 ^= ( 1 << V_121 ) ;
#ifdef F_41
if ( V_49 -> V_125
& ( 1 << V_121 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_69 , V_122 ) ;
}
#endif
V_127 = V_122 ;
V_122 = V_49 -> V_108 . V_123 ;
V_49 -> V_108 . V_123 = 0 ;
if ( V_122 == V_127 )
goto V_130;
V_49 = (struct V_44 * )
( V_120 + V_122 ) ;
} while ( V_127 == V_122 + V_49 -> V_131 );
V_128 = V_49 -> V_131 ;
V_49 = (struct V_44 * )
( V_120 + V_122 + V_128 ) ;
V_49 -> V_108 . V_123 = V_122 ;
V_122 += V_128 ;
} else {
int V_132 = V_56 -> V_65 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_126 . V_60 ,
V_64 ) == 0 &&
V_132 >= 0 ) {
if ( V_132 > V_119 -> V_128 -
sizeof( struct V_44 ) ) {
F_11 ( L_18
L_19 ,
V_132 ) ;
return 0 ;
}
F_11 ( L_20 ,
V_122 , V_132 ) ;
} else {
V_132 = V_122 + V_49 -> V_131 ;
}
V_49 = (struct V_44 * )
( V_120 + V_132 ) ;
V_49 -> V_108 . V_123 = V_122 ;
V_122 = V_132 ;
}
}
V_130:
F_11 ( L_21 , V_69 ) ;
}
return 1 ;
}
static void F_42 ( struct V_102 * V_133 , struct V_79 * V_79 )
{
struct V_134 V_41 ;
V_41 . V_79 = V_79 ;
V_41 . V_106 = V_133 -> V_58 . V_59 . V_106 ;
V_41 . V_107 = V_133 -> V_62 ;
V_41 . V_98 = V_99 ;
if ( V_41 . V_106 -> V_135 != NULL )
V_41 . V_106 -> V_135 ( & V_41 ) ;
F_43 ( V_41 . V_106 -> V_136 ) ;
}
static int
F_44 ( const struct V_44 * V_49 , const char * V_60 )
{
const struct V_48 * V_56 ;
if ( ! F_10 ( & V_49 -> V_16 ) ) {
F_11 ( L_22 , V_49 , V_60 ) ;
return - V_137 ;
}
if ( V_49 -> V_63 + sizeof( struct V_48 ) >
V_49 -> V_131 )
return - V_137 ;
V_56 = F_16 ( V_49 ) ;
if ( V_49 -> V_63 + V_56 -> V_58 . V_138 > V_49 -> V_131 )
return - V_137 ;
return 0 ;
}
static int F_45 ( struct V_102 * V_133 , struct V_139 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_140 ;
int V_14 ;
V_41 -> V_106 = V_133 -> V_58 . V_59 . V_106 ;
V_41 -> V_107 = V_133 -> V_62 ;
V_14 = F_46 ( V_41 , V_133 -> V_58 . V_141 - sizeof( * V_133 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_41 . V_106 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_47 ( struct V_102 * V_133 , struct V_139 * V_41 )
{
struct V_142 * V_106 ;
int V_14 ;
V_106 = F_48 ( V_99 , V_133 -> V_58 . V_126 . V_60 ,
V_133 -> V_58 . V_126 . V_143 ) ;
if ( F_49 ( V_106 ) ) {
F_11 ( L_24 , V_133 -> V_58 . V_126 . V_60 ) ;
return F_50 ( V_106 ) ;
}
V_133 -> V_58 . V_59 . V_106 = V_106 ;
V_14 = F_45 ( V_133 , V_41 ) ;
if ( V_14 )
goto V_144;
return 0 ;
V_144:
F_43 ( V_133 -> V_58 . V_59 . V_106 -> V_136 ) ;
return V_14 ;
}
static int F_51 ( struct V_44 * V_49 , struct V_79 * V_79 , const char * V_60 )
{
struct V_48 * V_56 = F_17 ( V_49 ) ;
struct V_145 V_41 = {
. V_79 = V_79 ,
. V_88 = V_60 ,
. V_140 = V_49 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_42 = V_56 -> V_62 ,
. V_146 = V_49 -> V_125 ,
. V_98 = V_99 ,
} ;
int V_14 ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_52 ( & V_41 , V_56 -> V_58 . V_138 - sizeof( * V_56 ) ,
V_49 -> V_16 . V_37 , V_49 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_53 ( struct V_44 * V_49 , struct V_79 * V_79 , const char * V_60 ,
unsigned int V_128 )
{
struct V_48 * V_56 ;
struct V_147 * V_57 ;
int V_14 ;
unsigned int V_148 ;
struct V_139 V_149 ;
struct V_102 * V_103 ;
V_14 = F_44 ( V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_148 = 0 ;
V_149 . V_79 = V_79 ;
V_149 . V_88 = V_60 ;
V_149 . V_140 = & V_49 -> V_16 ;
V_149 . V_146 = V_49 -> V_125 ;
V_149 . V_98 = V_99 ;
F_32 (ematch, e) {
V_14 = F_47 ( V_103 , & V_149 ) ;
if ( V_14 != 0 )
goto V_150;
++ V_148 ;
}
V_56 = F_17 ( V_49 ) ;
V_57 = F_54 ( V_99 , V_56 -> V_58 . V_126 . V_60 ,
V_56 -> V_58 . V_126 . V_143 ) ;
if ( F_49 ( V_57 ) ) {
F_11 ( L_25 , V_56 -> V_58 . V_126 . V_60 ) ;
V_14 = F_50 ( V_57 ) ;
goto V_150;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_14 = F_51 ( V_49 , V_79 , V_60 ) ;
if ( V_14 )
goto V_144;
return 0 ;
V_144:
F_43 ( V_56 -> V_58 . V_59 . V_57 -> V_136 ) ;
V_150:
F_32 (ematch, e) {
if ( V_148 -- == 0 )
break;
F_42 ( V_103 , V_79 ) ;
}
return V_14 ;
}
static bool F_55 ( const struct V_44 * V_49 )
{
const struct V_48 * V_56 ;
unsigned int V_65 ;
if ( ! F_15 ( & V_49 -> V_16 ) )
return false ;
V_56 = F_16 ( V_49 ) ;
if ( strcmp ( V_56 -> V_58 . V_126 . V_60 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_55 * ) V_56 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_118 ;
}
static int
F_56 ( struct V_44 * V_49 ,
struct V_74 * V_119 ,
const unsigned char * V_45 ,
const unsigned char * V_151 ,
const unsigned int * V_152 ,
const unsigned int * V_153 ,
unsigned int V_101 )
{
unsigned int V_154 ;
if ( ( unsigned long ) V_49 % F_57 ( struct V_44 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_44 ) >= V_151 ) {
F_11 ( L_26 , V_49 ) ;
return - V_137 ;
}
if ( V_49 -> V_131
< sizeof( struct V_44 ) + sizeof( struct V_48 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_131 ) ;
return - V_137 ;
}
for ( V_154 = 0 ; V_154 < V_121 ; V_154 ++ ) {
if ( ! ( V_101 & ( 1 << V_154 ) ) )
continue;
if ( ( unsigned char * ) V_49 - V_45 == V_152 [ V_154 ] )
V_119 -> V_81 [ V_154 ] = V_152 [ V_154 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_153 [ V_154 ] ) {
if ( ! F_55 ( V_49 ) ) {
F_40 ( L_28
L_29
L_30 ) ;
return - V_137 ;
}
V_119 -> V_114 [ V_154 ] = V_153 [ V_154 ] ;
}
}
V_49 -> V_108 = ( (struct V_155 ) { 0 , 0 } ) ;
V_49 -> V_125 = 0 ;
return 0 ;
}
static void F_58 ( struct V_44 * V_49 , struct V_79 * V_79 )
{
struct V_156 V_41 ;
struct V_48 * V_56 ;
struct V_102 * V_103 ;
F_32 (ematch, e)
F_42 ( V_103 , V_79 ) ;
V_56 = F_17 ( V_49 ) ;
V_41 . V_79 = V_79 ;
V_41 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_41 . V_42 = V_56 -> V_62 ;
V_41 . V_98 = V_99 ;
if ( V_41 . V_57 -> V_135 != NULL )
V_41 . V_57 -> V_135 ( & V_41 ) ;
F_43 ( V_41 . V_57 -> V_136 ) ;
}
static int
F_59 ( struct V_79 * V_79 , struct V_74 * V_119 , void * V_120 ,
const struct V_157 * V_158 )
{
struct V_44 * V_78 ;
unsigned int V_159 ;
int V_14 = 0 ;
V_119 -> V_128 = V_158 -> V_128 ;
V_119 -> V_160 = V_158 -> V_161 ;
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
V_119 -> V_81 [ V_159 ] = 0xFFFFFFFF ;
V_119 -> V_114 [ V_159 ] = 0xFFFFFFFF ;
}
F_11 ( L_31 , V_119 -> V_128 ) ;
V_159 = 0 ;
F_22 (iter, entry0, newinfo->size) {
V_14 = F_56 ( V_78 , V_119 , V_120 ,
V_120 + V_158 -> V_128 ,
V_158 -> V_81 ,
V_158 -> V_114 ,
V_158 -> V_101 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_159 ;
if ( strcmp ( F_17 ( V_78 ) -> V_58 . V_126 . V_60 ,
V_61 ) == 0 )
++ V_119 -> V_116 ;
}
if ( V_159 != V_158 -> V_161 ) {
F_11 ( L_32 ,
V_159 , V_158 -> V_161 ) ;
return - V_137 ;
}
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
if ( ! ( V_158 -> V_101 & ( 1 << V_159 ) ) )
continue;
if ( V_119 -> V_81 [ V_159 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_159 , V_158 -> V_81 [ V_159 ] ) ;
return - V_137 ;
}
if ( V_119 -> V_114 [ V_159 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_159 , V_158 -> V_114 [ V_159 ] ) ;
return - V_137 ;
}
}
if ( ! F_39 ( V_119 , V_158 -> V_101 , V_120 ) )
return - V_162 ;
V_159 = 0 ;
F_22 (iter, entry0, newinfo->size) {
V_14 = F_53 ( V_78 , V_79 , V_158 -> V_60 , V_158 -> V_128 ) ;
if ( V_14 != 0 )
break;
++ V_159 ;
}
if ( V_14 != 0 ) {
F_22 (iter, entry0, newinfo->size) {
if ( V_159 -- == 0 )
break;
F_58 ( V_78 , V_79 ) ;
}
return V_14 ;
}
F_60 (i) {
if ( V_119 -> V_80 [ V_159 ] && V_119 -> V_80 [ V_159 ] != V_120 )
memcpy ( V_119 -> V_80 [ V_159 ] , V_120 , V_119 -> V_128 ) ;
}
return V_14 ;
}
static void
F_61 ( const struct V_74 * V_56 ,
struct V_155 V_108 [] )
{
struct V_44 * V_78 ;
unsigned int V_95 ;
unsigned int V_159 ;
F_60 (cpu) {
T_2 * V_50 = & F_62 ( V_163 , V_95 ) ;
V_159 = 0 ;
F_22 (iter, t->entries[cpu], t->size) {
T_3 V_164 , V_123 ;
unsigned int V_165 ;
do {
V_165 = F_63 ( V_50 ) ;
V_164 = V_78 -> V_108 . V_164 ;
V_123 = V_78 -> V_108 . V_123 ;
} while ( F_64 ( V_50 , V_165 ) );
F_33 ( V_108 [ V_159 ] , V_164 , V_123 ) ;
++ V_159 ;
}
}
}
static struct V_155 * F_65 ( const struct V_1 * V_88 )
{
unsigned int V_166 ;
struct V_155 * V_108 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
V_166 = sizeof( struct V_155 ) * V_75 -> V_160 ;
V_108 = F_66 ( V_166 ) ;
if ( V_108 == NULL )
return F_67 ( - V_167 ) ;
F_61 ( V_75 , V_108 ) ;
return V_108 ;
}
static int
F_68 ( unsigned int V_168 ,
const struct V_1 * V_88 ,
void T_4 * V_169 )
{
unsigned int V_170 , V_171 ;
const struct V_44 * V_49 ;
struct V_155 * V_108 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
int V_14 = 0 ;
const void * V_172 ;
V_108 = F_65 ( V_88 ) ;
if ( F_49 ( V_108 ) )
return F_50 ( V_108 ) ;
V_172 = V_75 -> V_80 [ F_69 () ] ;
if ( F_70 ( V_169 , V_172 , V_168 ) != 0 ) {
V_14 = - V_173 ;
goto V_174;
}
for ( V_170 = 0 , V_171 = 0 ; V_170 < V_168 ; V_170 += V_49 -> V_131 , V_171 ++ ) {
unsigned int V_159 ;
const struct V_102 * V_133 ;
const struct V_48 * V_56 ;
V_49 = (struct V_44 * ) ( V_172 + V_170 ) ;
if ( F_70 ( V_169 + V_170
+ F_71 ( struct V_44 , V_108 ) ,
& V_108 [ V_171 ] ,
sizeof( V_108 [ V_171 ] ) ) != 0 ) {
V_14 = - V_173 ;
goto V_174;
}
for ( V_159 = sizeof( struct V_44 ) ;
V_159 < V_49 -> V_63 ;
V_159 += V_133 -> V_58 . V_141 ) {
V_133 = ( void * ) V_49 + V_159 ;
if ( F_70 ( V_169 + V_170 + V_159
+ F_71 ( struct V_102 ,
V_58 . V_126 . V_60 ) ,
V_133 -> V_58 . V_59 . V_106 -> V_60 ,
strlen ( V_133 -> V_58 . V_59 . V_106 -> V_60 ) + 1 )
!= 0 ) {
V_14 = - V_173 ;
goto V_174;
}
}
V_56 = F_16 ( V_49 ) ;
if ( F_70 ( V_169 + V_170 + V_49 -> V_63
+ F_71 ( struct V_48 ,
V_58 . V_126 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_14 = - V_173 ;
goto V_174;
}
}
V_174:
F_72 ( V_108 ) ;
return V_14 ;
}
static void F_73 ( void * V_23 , const void * V_19 )
{
int V_112 = * ( V_175 * ) V_19 ;
if ( V_112 > 0 )
V_112 += F_74 ( V_84 , V_112 ) ;
memcpy ( V_23 , & V_112 , sizeof( V_112 ) ) ;
}
static int F_75 ( void T_4 * V_23 , const void * V_19 )
{
V_175 V_176 = * ( int * ) V_19 ;
if ( V_176 > 0 )
V_176 -= F_74 ( V_84 , V_176 ) ;
return F_70 ( V_23 , & V_176 , sizeof( V_176 ) ) ? - V_173 : 0 ;
}
static int F_76 ( const struct V_44 * V_49 ,
const struct V_74 * V_2 ,
const void * V_45 , struct V_74 * V_119 )
{
const struct V_102 * V_103 ;
const struct V_48 * V_56 ;
unsigned int V_177 ;
int V_170 , V_159 , V_14 ;
V_170 = sizeof( struct V_44 ) - sizeof( struct V_178 ) ;
V_177 = ( void * ) V_49 - V_45 ;
F_32 (ematch, e)
V_170 += F_77 ( V_103 -> V_58 . V_59 . V_106 ) ;
V_56 = F_16 ( V_49 ) ;
V_170 += F_78 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_119 -> V_128 -= V_170 ;
V_14 = F_79 ( V_84 , V_177 , V_170 ) ;
if ( V_14 )
return V_14 ;
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
if ( V_2 -> V_81 [ V_159 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_81 [ V_159 ] ) ) )
V_119 -> V_81 [ V_159 ] -= V_170 ;
if ( V_2 -> V_114 [ V_159 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_114 [ V_159 ] ) ) )
V_119 -> V_114 [ V_159 ] -= V_170 ;
}
return 0 ;
}
static int F_80 ( const struct V_74 * V_2 ,
struct V_74 * V_119 )
{
struct V_44 * V_78 ;
void * V_172 ;
int V_14 ;
if ( ! V_119 || ! V_2 )
return - V_137 ;
memcpy ( V_119 , V_2 , F_71 ( struct V_74 , V_80 ) ) ;
V_119 -> V_179 = 0 ;
V_172 = V_2 -> V_80 [ F_69 () ] ;
F_81 ( V_84 , V_2 -> V_160 ) ;
F_22 (iter, loc_cpu_entry, info->size) {
V_14 = F_76 ( V_78 , V_2 , V_172 , V_119 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_82 ( struct V_79 * V_79 , void T_4 * V_126 ,
const int * V_109 , int V_180 )
{
char V_60 [ V_181 ] ;
struct V_1 * V_56 ;
int V_14 ;
if ( * V_109 != sizeof( struct V_182 ) ) {
F_11 ( L_35 , * V_109 ,
sizeof( struct V_182 ) ) ;
return - V_137 ;
}
if ( F_83 ( V_60 , V_126 , sizeof( V_60 ) ) != 0 )
return - V_173 ;
V_60 [ V_181 - 1 ] = '\0' ;
#ifdef F_84
if ( V_180 )
F_85 ( V_84 ) ;
#endif
V_56 = F_86 ( F_87 ( V_79 , V_84 , V_60 ) ,
L_36 , V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
struct V_182 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_84
struct V_74 V_183 ;
if ( V_180 ) {
V_14 = F_80 ( V_75 , & V_183 ) ;
F_89 ( V_84 ) ;
V_75 = & V_183 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_101 = V_56 -> V_101 ;
memcpy ( V_2 . V_81 , V_75 -> V_81 ,
sizeof( V_2 . V_81 ) ) ;
memcpy ( V_2 . V_114 , V_75 -> V_114 ,
sizeof( V_2 . V_114 ) ) ;
V_2 . V_161 = V_75 -> V_160 ;
V_2 . V_128 = V_75 -> V_128 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_70 ( V_126 , & V_2 , * V_109 ) != 0 )
V_14 = - V_173 ;
else
V_14 = 0 ;
F_90 ( V_56 ) ;
F_43 ( V_56 -> V_136 ) ;
} else
V_14 = V_56 ? F_50 ( V_56 ) : - V_184 ;
#ifdef F_84
if ( V_180 )
F_91 ( V_84 ) ;
#endif
return V_14 ;
}
static int
F_92 ( struct V_79 * V_79 , struct V_185 T_4 * V_186 ,
const int * V_109 )
{
int V_14 ;
struct V_185 V_187 ;
struct V_1 * V_56 ;
if ( * V_109 < sizeof( V_187 ) ) {
F_11 ( L_37 , * V_109 , sizeof( V_187 ) ) ;
return - V_137 ;
}
if ( F_83 ( & V_187 , V_186 , sizeof( V_187 ) ) != 0 )
return - V_173 ;
if ( * V_109 != sizeof( struct V_185 ) + V_187 . V_128 ) {
F_11 ( L_38 ,
* V_109 , sizeof( V_187 ) + V_187 . V_128 ) ;
return - V_137 ;
}
V_56 = F_87 ( V_79 , V_84 , V_187 . V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
struct V_74 * V_75 = V_56 -> V_75 ;
F_11 ( L_39 , V_75 -> V_160 ) ;
if ( V_187 . V_128 == V_75 -> V_128 )
V_14 = F_68 ( V_75 -> V_128 ,
V_56 , V_186 -> V_188 ) ;
else {
F_11 ( L_40 ,
V_75 -> V_128 , V_187 . V_128 ) ;
V_14 = - V_189 ;
}
F_43 ( V_56 -> V_136 ) ;
F_90 ( V_56 ) ;
} else
V_14 = V_56 ? F_50 ( V_56 ) : - V_184 ;
return V_14 ;
}
static int
F_93 ( struct V_79 * V_79 , const char * V_60 , unsigned int V_101 ,
struct V_74 * V_119 , unsigned int V_190 ,
void T_4 * V_191 )
{
int V_14 ;
struct V_1 * V_56 ;
struct V_74 * V_192 ;
struct V_155 * V_108 ;
const void * V_193 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_108 = F_66 ( V_190 * sizeof( struct V_155 ) ) ;
if ( ! V_108 ) {
V_14 = - V_167 ;
goto V_72;
}
V_56 = F_86 ( F_87 ( V_79 , V_84 , V_60 ) ,
L_36 , V_60 ) ;
if ( F_88 ( V_56 ) ) {
V_14 = V_56 ? F_50 ( V_56 ) : - V_184 ;
goto V_194;
}
if ( V_101 != V_56 -> V_101 ) {
F_11 ( L_41 ,
V_101 , V_56 -> V_101 ) ;
V_14 = - V_137 ;
goto V_195;
}
V_192 = F_94 ( V_56 , V_190 , V_119 , & V_14 ) ;
if ( ! V_192 )
goto V_195;
F_11 ( L_42 ,
V_192 -> V_160 , V_192 -> V_179 , V_119 -> V_160 ) ;
if ( ( V_192 -> V_160 > V_192 -> V_179 ) ||
( V_119 -> V_160 <= V_192 -> V_179 ) )
F_43 ( V_56 -> V_136 ) ;
if ( ( V_192 -> V_160 > V_192 -> V_179 ) &&
( V_119 -> V_160 <= V_192 -> V_179 ) )
F_43 ( V_56 -> V_136 ) ;
F_61 ( V_192 , V_108 ) ;
V_193 = V_192 -> V_80 [ F_69 () ] ;
F_22 (iter, loc_cpu_old_entry, oldinfo->size)
F_58 ( V_78 , V_79 ) ;
F_95 ( V_192 ) ;
if ( F_70 ( V_191 , V_108 ,
sizeof( struct V_155 ) * V_190 ) != 0 ) {
F_96 ( L_43 ) ;
}
F_72 ( V_108 ) ;
F_90 ( V_56 ) ;
return V_14 ;
V_195:
F_43 ( V_56 -> V_136 ) ;
F_90 ( V_56 ) ;
V_194:
F_72 ( V_108 ) ;
V_72:
return V_14 ;
}
static int
F_97 ( struct V_79 * V_79 , const void T_4 * V_126 , unsigned int V_109 )
{
int V_14 ;
struct V_157 V_183 ;
struct V_74 * V_119 ;
void * V_172 ;
struct V_44 * V_78 ;
if ( F_83 ( & V_183 , V_126 , sizeof( V_183 ) ) != 0 )
return - V_173 ;
if ( V_183 . V_190 >= V_196 / sizeof( struct V_155 ) )
return - V_167 ;
if ( V_183 . V_190 == 0 )
return - V_137 ;
V_183 . V_60 [ sizeof( V_183 . V_60 ) - 1 ] = 0 ;
V_119 = F_98 ( V_183 . V_128 ) ;
if ( ! V_119 )
return - V_167 ;
V_172 = V_119 -> V_80 [ F_69 () ] ;
if ( F_83 ( V_172 , V_126 + sizeof( V_183 ) ,
V_183 . V_128 ) != 0 ) {
V_14 = - V_173 ;
goto V_197;
}
V_14 = F_59 ( V_79 , V_119 , V_172 , & V_183 ) ;
if ( V_14 != 0 )
goto V_197;
F_11 ( L_44 ) ;
V_14 = F_93 ( V_79 , V_183 . V_60 , V_183 . V_101 , V_119 ,
V_183 . V_190 , V_183 . V_108 ) ;
if ( V_14 )
goto V_198;
return 0 ;
V_198:
F_22 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_79 ) ;
V_197:
F_95 ( V_119 ) ;
return V_14 ;
}
static int
F_99 ( struct V_79 * V_79 , const void T_4 * V_126 , unsigned int V_109 ,
int V_180 )
{
unsigned int V_159 , V_199 ;
struct V_200 V_183 ;
struct V_155 * V_201 ;
unsigned int V_190 ;
char * V_60 ;
int V_128 ;
void * V_202 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_14 = 0 ;
const void * V_172 ;
struct V_44 * V_78 ;
unsigned int V_97 ;
#ifdef F_84
struct V_203 V_204 ;
if ( V_180 ) {
V_202 = & V_204 ;
V_128 = sizeof( struct V_203 ) ;
} else
#endif
{
V_202 = & V_183 ;
V_128 = sizeof( struct V_200 ) ;
}
if ( F_83 ( V_202 , V_126 , V_128 ) != 0 )
return - V_173 ;
#ifdef F_84
if ( V_180 ) {
V_190 = V_204 . V_190 ;
V_60 = V_204 . V_60 ;
} else
#endif
{
V_190 = V_183 . V_190 ;
V_60 = V_183 . V_60 ;
}
if ( V_109 != V_128 + V_190 * sizeof( struct V_155 ) )
return - V_137 ;
V_201 = F_100 ( V_109 - V_128 ) ;
if ( ! V_201 )
return - V_167 ;
if ( F_83 ( V_201 , V_126 + V_128 , V_109 - V_128 ) != 0 ) {
V_14 = - V_173 ;
goto free;
}
V_56 = F_87 ( V_79 , V_84 , V_60 ) ;
if ( F_88 ( V_56 ) ) {
V_14 = V_56 ? F_50 ( V_56 ) : - V_184 ;
goto free;
}
F_27 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_160 != V_190 ) {
V_14 = - V_137 ;
goto V_205;
}
V_159 = 0 ;
V_199 = F_21 () ;
V_97 = F_28 () ;
V_172 = V_75 -> V_80 [ V_199 ] ;
F_22 (iter, loc_cpu_entry, private->size) {
F_33 ( V_78 -> V_108 , V_201 [ V_159 ] . V_164 , V_201 [ V_159 ] . V_123 ) ;
++ V_159 ;
}
F_36 ( V_97 ) ;
V_205:
F_37 () ;
F_90 ( V_56 ) ;
F_43 ( V_56 -> V_136 ) ;
free:
F_72 ( V_201 ) ;
return V_14 ;
}
static int
F_101 ( struct V_44 * V_49 , void T_4 * * V_206 ,
unsigned int * V_128 , struct V_155 * V_108 ,
unsigned int V_159 )
{
struct V_48 * V_56 ;
struct V_178 T_4 * V_207 ;
T_5 V_63 , V_131 ;
T_6 V_208 ;
const struct V_102 * V_103 ;
int V_14 = 0 ;
V_208 = * V_128 ;
V_207 = (struct V_178 T_4 * ) * V_206 ;
if ( F_70 ( V_207 , V_49 , sizeof( struct V_44 ) ) != 0 ||
F_70 ( & V_207 -> V_108 , & V_108 [ V_159 ] ,
sizeof( V_108 [ V_159 ] ) ) != 0 )
return - V_173 ;
* V_206 += sizeof( struct V_178 ) ;
* V_128 -= sizeof( struct V_44 ) - sizeof( struct V_178 ) ;
F_32 (ematch, e) {
V_14 = F_102 ( V_103 , V_206 , V_128 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_63 = V_49 -> V_63 - ( V_208 - * V_128 ) ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_103 ( V_56 , V_206 , V_128 ) ;
if ( V_14 )
return V_14 ;
V_131 = V_49 -> V_131 - ( V_208 - * V_128 ) ;
if ( F_104 ( V_63 , & V_207 -> V_63 ) != 0 ||
F_104 ( V_131 , & V_207 -> V_131 ) != 0 )
return - V_173 ;
return 0 ;
}
static int
F_105 ( struct V_102 * V_133 ,
const char * V_60 ,
const struct V_9 * V_16 ,
unsigned int V_209 ,
int * V_128 )
{
struct V_142 * V_106 ;
V_106 = F_48 ( V_99 , V_133 -> V_58 . V_126 . V_60 ,
V_133 -> V_58 . V_126 . V_143 ) ;
if ( F_49 ( V_106 ) ) {
F_11 ( L_45 ,
V_133 -> V_58 . V_126 . V_60 ) ;
return F_50 ( V_106 ) ;
}
V_133 -> V_58 . V_59 . V_106 = V_106 ;
* V_128 += F_77 ( V_106 ) ;
return 0 ;
}
static void F_106 ( struct V_178 * V_49 )
{
struct V_48 * V_56 ;
struct V_102 * V_103 ;
F_32 (ematch, e)
F_43 ( V_103 -> V_58 . V_59 . V_106 -> V_136 ) ;
V_56 = F_107 ( V_49 ) ;
F_43 ( V_56 -> V_58 . V_59 . V_57 -> V_136 ) ;
}
static int
F_108 ( struct V_178 * V_49 ,
struct V_74 * V_119 ,
unsigned int * V_128 ,
const unsigned char * V_45 ,
const unsigned char * V_151 ,
const unsigned int * V_152 ,
const unsigned int * V_153 ,
const char * V_60 )
{
struct V_102 * V_103 ;
struct V_48 * V_56 ;
struct V_147 * V_57 ;
unsigned int V_177 ;
unsigned int V_148 ;
int V_14 , V_170 , V_154 ;
F_11 ( L_46 , V_49 ) ;
if ( ( unsigned long ) V_49 % F_57 ( struct V_178 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_178 ) >= V_151 ) {
F_11 ( L_47 , V_49 , V_151 ) ;
return - V_137 ;
}
if ( V_49 -> V_131 < sizeof( struct V_178 ) +
sizeof( struct V_210 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_131 ) ;
return - V_137 ;
}
V_14 = F_44 ( (struct V_44 * ) V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_170 = sizeof( struct V_44 ) - sizeof( struct V_178 ) ;
V_177 = ( void * ) V_49 - ( void * ) V_45 ;
V_148 = 0 ;
F_32 (ematch, e) {
V_14 = F_105 ( V_103 , V_60 ,
& V_49 -> V_16 , V_49 -> V_125 , & V_170 ) ;
if ( V_14 != 0 )
goto V_211;
++ V_148 ;
}
V_56 = F_107 ( V_49 ) ;
V_57 = F_54 ( V_99 , V_56 -> V_58 . V_126 . V_60 ,
V_56 -> V_58 . V_126 . V_143 ) ;
if ( F_49 ( V_57 ) ) {
F_11 ( L_48 ,
V_56 -> V_58 . V_126 . V_60 ) ;
V_14 = F_50 ( V_57 ) ;
goto V_211;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_170 += F_78 ( V_57 ) ;
* V_128 += V_170 ;
V_14 = F_79 ( V_84 , V_177 , V_170 ) ;
if ( V_14 )
goto V_72;
for ( V_154 = 0 ; V_154 < V_121 ; V_154 ++ ) {
if ( ( unsigned char * ) V_49 - V_45 == V_152 [ V_154 ] )
V_119 -> V_81 [ V_154 ] = V_152 [ V_154 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_153 [ V_154 ] )
V_119 -> V_114 [ V_154 ] = V_153 [ V_154 ] ;
}
memset ( & V_49 -> V_108 , 0 , sizeof( V_49 -> V_108 ) ) ;
V_49 -> V_125 = 0 ;
return 0 ;
V_72:
F_43 ( V_56 -> V_58 . V_59 . V_57 -> V_136 ) ;
V_211:
F_32 (ematch, e) {
if ( V_148 -- == 0 )
break;
F_43 ( V_103 -> V_58 . V_59 . V_106 -> V_136 ) ;
}
return V_14 ;
}
static int
F_109 ( struct V_178 * V_49 , void * * V_206 ,
unsigned int * V_128 , const char * V_60 ,
struct V_74 * V_119 , unsigned char * V_45 )
{
struct V_48 * V_56 ;
struct V_44 * V_212 ;
unsigned int V_208 ;
int V_14 , V_154 ;
struct V_102 * V_103 ;
V_14 = 0 ;
V_208 = * V_128 ;
V_212 = (struct V_44 * ) * V_206 ;
memcpy ( V_212 , V_49 , sizeof( struct V_44 ) ) ;
memcpy ( & V_212 -> V_108 , & V_49 -> V_108 , sizeof( V_49 -> V_108 ) ) ;
* V_206 += sizeof( struct V_44 ) ;
* V_128 += sizeof( struct V_44 ) - sizeof( struct V_178 ) ;
F_32 (ematch, e) {
V_14 = F_110 ( V_103 , V_206 , V_128 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_212 -> V_63 = V_49 -> V_63 - ( V_208 - * V_128 ) ;
V_56 = F_107 ( V_49 ) ;
F_111 ( V_56 , V_206 , V_128 ) ;
V_212 -> V_131 = V_49 -> V_131 - ( V_208 - * V_128 ) ;
for ( V_154 = 0 ; V_154 < V_121 ; V_154 ++ ) {
if ( ( unsigned char * ) V_212 - V_45 < V_119 -> V_81 [ V_154 ] )
V_119 -> V_81 [ V_154 ] -= V_208 - * V_128 ;
if ( ( unsigned char * ) V_212 - V_45 < V_119 -> V_114 [ V_154 ] )
V_119 -> V_114 [ V_154 ] -= V_208 - * V_128 ;
}
return V_14 ;
}
static int F_112 ( struct V_44 * V_49 , struct V_79 * V_79 ,
const char * V_60 )
{
unsigned int V_148 ;
int V_14 = 0 ;
struct V_139 V_149 ;
struct V_102 * V_103 ;
V_148 = 0 ;
V_149 . V_79 = V_79 ;
V_149 . V_88 = V_60 ;
V_149 . V_140 = & V_49 -> V_16 ;
V_149 . V_146 = V_49 -> V_125 ;
V_149 . V_98 = V_99 ;
F_32 (ematch, e) {
V_14 = F_45 ( V_103 , & V_149 ) ;
if ( V_14 != 0 )
goto V_150;
++ V_148 ;
}
V_14 = F_51 ( V_49 , V_79 , V_60 ) ;
if ( V_14 )
goto V_150;
return 0 ;
V_150:
F_32 (ematch, e) {
if ( V_148 -- == 0 )
break;
F_42 ( V_103 , V_79 ) ;
}
return V_14 ;
}
static int
F_113 ( struct V_79 * V_79 ,
const char * V_60 ,
unsigned int V_101 ,
struct V_74 * * V_213 ,
void * * V_214 ,
unsigned int V_168 ,
unsigned int V_160 ,
unsigned int * V_152 ,
unsigned int * V_153 )
{
unsigned int V_159 , V_148 ;
struct V_74 * V_119 , * V_2 ;
void * V_122 , * V_120 , * V_215 ;
struct V_178 * V_216 ;
struct V_44 * V_217 ;
unsigned int V_128 ;
int V_14 = 0 ;
V_2 = * V_213 ;
V_120 = * V_214 ;
V_128 = V_168 ;
V_2 -> V_160 = V_160 ;
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
V_2 -> V_81 [ V_159 ] = 0xFFFFFFFF ;
V_2 -> V_114 [ V_159 ] = 0xFFFFFFFF ;
}
F_11 ( L_49 , V_2 -> V_128 ) ;
V_148 = 0 ;
F_85 ( V_84 ) ;
F_81 ( V_84 , V_160 ) ;
F_22 (iter0, entry0, total_size) {
V_14 = F_108 ( V_216 , V_2 , & V_128 ,
V_120 ,
V_120 + V_168 ,
V_152 ,
V_153 ,
V_60 ) ;
if ( V_14 != 0 )
goto V_218;
++ V_148 ;
}
V_14 = - V_137 ;
if ( V_148 != V_160 ) {
F_11 ( L_50 ,
V_148 , V_160 ) ;
goto V_218;
}
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
if ( ! ( V_101 & ( 1 << V_159 ) ) )
continue;
if ( V_2 -> V_81 [ V_159 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_159 , V_152 [ V_159 ] ) ;
goto V_218;
}
if ( V_2 -> V_114 [ V_159 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_159 , V_153 [ V_159 ] ) ;
goto V_218;
}
}
V_14 = - V_167 ;
V_119 = F_98 ( V_128 ) ;
if ( ! V_119 )
goto V_218;
V_119 -> V_160 = V_160 ;
for ( V_159 = 0 ; V_159 < V_121 ; V_159 ++ ) {
V_119 -> V_81 [ V_159 ] = V_2 -> V_81 [ V_159 ] ;
V_119 -> V_114 [ V_159 ] = V_2 -> V_114 [ V_159 ] ;
}
V_215 = V_119 -> V_80 [ F_69 () ] ;
V_122 = V_215 ;
V_128 = V_168 ;
F_22 (iter0, entry0, total_size) {
V_14 = F_109 ( V_216 , & V_122 , & V_128 ,
V_60 , V_119 , V_215 ) ;
if ( V_14 != 0 )
break;
}
F_89 ( V_84 ) ;
F_91 ( V_84 ) ;
if ( V_14 )
goto V_197;
V_14 = - V_162 ;
if ( ! F_39 ( V_119 , V_101 , V_215 ) )
goto V_197;
V_159 = 0 ;
F_22 (iter1, entry1, newinfo->size) {
V_14 = F_112 ( V_217 , V_79 , V_60 ) ;
if ( V_14 != 0 )
break;
++ V_159 ;
if ( strcmp ( F_17 ( V_217 ) -> V_58 . V_126 . V_60 ,
V_61 ) == 0 )
++ V_119 -> V_116 ;
}
if ( V_14 ) {
int V_219 = V_159 ;
V_148 -= V_159 ;
F_22 (iter0, entry0, newinfo->size) {
if ( V_219 -- > 0 )
continue;
if ( V_148 -- == 0 )
break;
F_106 ( V_216 ) ;
}
F_22 (iter1, entry1, newinfo->size) {
if ( V_159 -- == 0 )
break;
F_58 ( V_217 , V_79 ) ;
}
F_95 ( V_119 ) ;
return V_14 ;
}
F_60 (i)
if ( V_119 -> V_80 [ V_159 ] && V_119 -> V_80 [ V_159 ] != V_215 )
memcpy ( V_119 -> V_80 [ V_159 ] , V_215 , V_119 -> V_128 ) ;
* V_213 = V_119 ;
* V_214 = V_215 ;
F_95 ( V_2 ) ;
return 0 ;
V_197:
F_95 ( V_119 ) ;
V_72:
F_22 (iter0, entry0, total_size) {
if ( V_148 -- == 0 )
break;
F_106 ( V_216 ) ;
}
return V_14 ;
V_218:
F_89 ( V_84 ) ;
F_91 ( V_84 ) ;
goto V_72;
}
static int
F_114 ( struct V_79 * V_79 , void T_4 * V_126 , unsigned int V_109 )
{
int V_14 ;
struct V_220 V_183 ;
struct V_74 * V_119 ;
void * V_172 ;
struct V_44 * V_78 ;
if ( F_83 ( & V_183 , V_126 , sizeof( V_183 ) ) != 0 )
return - V_173 ;
if ( V_183 . V_128 >= V_196 / F_115 () )
return - V_167 ;
if ( V_183 . V_190 >= V_196 / sizeof( struct V_155 ) )
return - V_167 ;
if ( V_183 . V_190 == 0 )
return - V_137 ;
V_183 . V_60 [ sizeof( V_183 . V_60 ) - 1 ] = 0 ;
V_119 = F_98 ( V_183 . V_128 ) ;
if ( ! V_119 )
return - V_167 ;
V_172 = V_119 -> V_80 [ F_69 () ] ;
if ( F_83 ( V_172 , V_126 + sizeof( V_183 ) ,
V_183 . V_128 ) != 0 ) {
V_14 = - V_173 ;
goto V_197;
}
V_14 = F_113 ( V_79 , V_183 . V_60 , V_183 . V_101 ,
& V_119 , & V_172 , V_183 . V_128 ,
V_183 . V_161 , V_183 . V_81 ,
V_183 . V_114 ) ;
if ( V_14 != 0 )
goto V_197;
F_11 ( L_51 ) ;
V_14 = F_93 ( V_79 , V_183 . V_60 , V_183 . V_101 , V_119 ,
V_183 . V_190 , F_116 ( V_183 . V_108 ) ) ;
if ( V_14 )
goto V_198;
return 0 ;
V_198:
F_22 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_79 ) ;
V_197:
F_95 ( V_119 ) ;
return V_14 ;
}
static int
F_117 ( struct V_221 * V_222 , int V_223 , void T_4 * V_126 ,
unsigned int V_109 )
{
int V_14 ;
if ( ! F_118 ( F_119 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_114 ( F_119 ( V_222 ) , V_126 , V_109 ) ;
break;
case V_228 :
V_14 = F_99 ( F_119 ( V_222 ) , V_126 , V_109 , 1 ) ;
break;
default:
F_11 ( L_52 , V_223 ) ;
V_14 = - V_137 ;
}
return V_14 ;
}
static int
F_120 ( unsigned int V_168 , struct V_1 * V_88 ,
void T_4 * V_169 )
{
struct V_155 * V_108 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
void T_4 * V_122 ;
unsigned int V_128 ;
int V_14 = 0 ;
const void * V_172 ;
unsigned int V_159 = 0 ;
struct V_44 * V_78 ;
V_108 = F_65 ( V_88 ) ;
if ( F_49 ( V_108 ) )
return F_50 ( V_108 ) ;
V_172 = V_75 -> V_80 [ F_69 () ] ;
V_122 = V_169 ;
V_128 = V_168 ;
F_22 (iter, loc_cpu_entry, total_size) {
V_14 = F_101 ( V_78 , & V_122 ,
& V_128 , V_108 , V_159 ++ ) ;
if ( V_14 != 0 )
break;
}
F_72 ( V_108 ) ;
return V_14 ;
}
static int
F_121 ( struct V_79 * V_79 , struct V_229 T_4 * V_186 ,
int * V_109 )
{
int V_14 ;
struct V_229 V_187 ;
struct V_1 * V_56 ;
if ( * V_109 < sizeof( V_187 ) ) {
F_11 ( L_53 , * V_109 , sizeof( V_187 ) ) ;
return - V_137 ;
}
if ( F_83 ( & V_187 , V_186 , sizeof( V_187 ) ) != 0 )
return - V_173 ;
if ( * V_109 != sizeof( struct V_229 ) + V_187 . V_128 ) {
F_11 ( L_54 ,
* V_109 , sizeof( V_187 ) + V_187 . V_128 ) ;
return - V_137 ;
}
F_85 ( V_84 ) ;
V_56 = F_87 ( V_79 , V_84 , V_187 . V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
F_11 ( L_39 , V_75 -> V_160 ) ;
V_14 = F_80 ( V_75 , & V_2 ) ;
if ( ! V_14 && V_187 . V_128 == V_2 . V_128 ) {
V_14 = F_120 ( V_75 -> V_128 ,
V_56 , V_186 -> V_188 ) ;
} else if ( ! V_14 ) {
F_11 ( L_55 ,
V_75 -> V_128 , V_187 . V_128 ) ;
V_14 = - V_189 ;
}
F_89 ( V_84 ) ;
F_43 ( V_56 -> V_136 ) ;
F_90 ( V_56 ) ;
} else
V_14 = V_56 ? F_50 ( V_56 ) : - V_184 ;
F_91 ( V_84 ) ;
return V_14 ;
}
static int
F_122 ( struct V_221 * V_222 , int V_223 , void T_4 * V_126 , int * V_109 )
{
int V_14 ;
if ( ! F_118 ( F_119 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_82 ( F_119 ( V_222 ) , V_126 , V_109 , 1 ) ;
break;
case V_231 :
V_14 = F_121 ( F_119 ( V_222 ) , V_126 , V_109 ) ;
break;
default:
V_14 = F_123 ( V_222 , V_223 , V_126 , V_109 ) ;
}
return V_14 ;
}
static int
F_124 ( struct V_221 * V_222 , int V_223 , void T_4 * V_126 , unsigned int V_109 )
{
int V_14 ;
if ( ! F_118 ( F_119 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_97 ( F_119 ( V_222 ) , V_126 , V_109 ) ;
break;
case V_228 :
V_14 = F_99 ( F_119 ( V_222 ) , V_126 , V_109 , 0 ) ;
break;
default:
F_11 ( L_52 , V_223 ) ;
V_14 = - V_137 ;
}
return V_14 ;
}
static int
F_123 ( struct V_221 * V_222 , int V_223 , void T_4 * V_126 , int * V_109 )
{
int V_14 ;
if ( ! F_118 ( F_119 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_82 ( F_119 ( V_222 ) , V_126 , V_109 , 0 ) ;
break;
case V_231 :
V_14 = F_92 ( F_119 ( V_222 ) , V_126 , V_109 ) ;
break;
case V_232 :
case V_233 : {
struct V_234 V_235 ;
int V_57 ;
if ( * V_109 != sizeof( V_235 ) ) {
V_14 = - V_137 ;
break;
}
if ( F_83 ( & V_235 , V_126 , sizeof( V_235 ) ) != 0 ) {
V_14 = - V_173 ;
break;
}
V_235 . V_60 [ sizeof( V_235 . V_60 ) - 1 ] = 0 ;
if ( V_223 == V_233 )
V_57 = 1 ;
else
V_57 = 0 ;
F_86 ( F_125 ( V_84 , V_235 . V_60 ,
V_235 . V_143 ,
V_57 , & V_14 ) ,
L_56 , V_235 . V_60 ) ;
break;
}
default:
F_11 ( L_57 , V_223 ) ;
V_14 = - V_137 ;
}
return V_14 ;
}
struct V_1 * F_126 ( struct V_79 * V_79 ,
const struct V_1 * V_88 ,
const struct V_157 * V_158 )
{
int V_14 ;
struct V_74 * V_119 ;
struct V_74 V_236 = { 0 } ;
void * V_172 ;
struct V_1 * V_237 ;
V_119 = F_98 ( V_158 -> V_128 ) ;
if ( ! V_119 ) {
V_14 = - V_167 ;
goto V_72;
}
V_172 = V_119 -> V_80 [ F_69 () ] ;
memcpy ( V_172 , V_158 -> V_80 , V_158 -> V_128 ) ;
V_14 = F_59 ( V_79 , V_119 , V_172 , V_158 ) ;
if ( V_14 != 0 )
goto V_238;
V_237 = F_127 ( V_79 , V_88 , & V_236 , V_119 ) ;
if ( F_49 ( V_237 ) ) {
V_14 = F_50 ( V_237 ) ;
goto V_238;
}
return V_237 ;
V_238:
F_95 ( V_119 ) ;
V_72:
return F_67 ( V_14 ) ;
}
void F_128 ( struct V_79 * V_79 , struct V_1 * V_88 )
{
struct V_74 * V_75 ;
void * V_172 ;
struct V_239 * V_240 = V_88 -> V_136 ;
struct V_44 * V_78 ;
V_75 = F_129 ( V_88 ) ;
V_172 = V_75 -> V_80 [ F_69 () ] ;
F_22 (iter, loc_cpu_entry, private->size)
F_58 ( V_78 , V_79 ) ;
if ( V_75 -> V_160 > V_75 -> V_179 )
F_43 ( V_240 ) ;
F_95 ( V_75 ) ;
}
static inline bool
F_130 ( T_7 V_241 , T_7 V_242 , T_7 V_243 ,
T_7 type , T_7 V_244 ,
bool V_245 )
{
return ( type == V_241 && V_244 >= V_242 && V_244 <= V_243 )
^ V_245 ;
}
static bool
F_131 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_246 * V_247 ;
struct V_246 V_248 ;
const struct V_249 * V_250 = V_41 -> V_107 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_247 = F_132 ( V_6 , V_41 -> V_104 , sizeof( V_248 ) , & V_248 ) ;
if ( V_247 == NULL ) {
F_11 ( L_58 ) ;
V_41 -> V_13 = true ;
return false ;
}
return F_130 ( V_250 -> type ,
V_250 -> V_244 [ 0 ] ,
V_250 -> V_244 [ 1 ] ,
V_247 -> V_251 , V_247 -> V_252 ,
! ! ( V_250 -> V_28 & V_253 ) ) ;
}
static int F_133 ( const struct V_139 * V_41 )
{
const struct V_249 * V_250 = V_41 -> V_107 ;
return ( V_250 -> V_28 & ~ V_253 ) ? - V_137 : 0 ;
}
static int T_8 F_134 ( struct V_79 * V_79 )
{
return F_135 ( V_79 , V_99 ) ;
}
static void T_9 F_136 ( struct V_79 * V_79 )
{
F_137 ( V_79 , V_99 ) ;
}
static int T_10 F_138 ( void )
{
int V_14 ;
V_14 = F_139 ( & V_254 ) ;
if ( V_14 < 0 )
goto V_255;
V_14 = F_140 ( V_256 , F_141 ( V_256 ) ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_142 ( V_258 , F_141 ( V_258 ) ) ;
if ( V_14 < 0 )
goto V_259;
V_14 = F_143 ( & V_260 ) ;
if ( V_14 < 0 )
goto V_261;
F_144 ( L_59 ) ;
return 0 ;
V_261:
F_145 ( V_258 , F_141 ( V_258 ) ) ;
V_259:
F_146 ( V_256 , F_141 ( V_256 ) ) ;
V_257:
F_147 ( & V_254 ) ;
V_255:
return V_14 ;
}
static void T_11 F_148 ( void )
{
F_149 ( & V_260 ) ;
F_145 ( V_258 , F_141 ( V_258 ) ) ;
F_146 ( V_256 , F_141 ( V_256 ) ) ;
F_147 ( & V_254 ) ;
}
