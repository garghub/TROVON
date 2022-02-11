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
V_76 = V_75 -> V_79 [ F_20 () ] ;
V_77 = F_14 ( V_76 , V_75 -> V_80 [ V_69 ] ) ;
V_51 = V_52 = V_81 [ V_69 ] ;
V_53 = V_66 [ V_82 ] ;
F_21 (iter, root, private->size - private->hook_entry[hook])
if ( F_18 ( V_78 , V_49 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_22 ( V_83 , V_69 , V_6 , V_71 , V_72 , & V_84 ,
L_11 ,
V_73 , V_52 , V_53 , V_54 ) ;
}
unsigned int
F_23 ( struct V_5 * V_6 ,
unsigned int V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 ,
struct V_1 * V_85 )
{
static const char V_86 [ V_87 ] V_88 ( ( F_24 ( sizeof( long ) ) ) ) ;
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
F_25 ( V_85 -> V_98 & ( 1 << V_69 ) ) ;
F_26 () ;
V_94 = F_27 () ;
V_75 = V_85 -> V_75 ;
V_92 = F_20 () ;
V_76 = V_75 -> V_79 [ V_92 ] ;
V_89 = (struct V_44 * * ) V_75 -> V_89 [ V_92 ] ;
V_90 = F_28 ( V_75 -> V_90 , V_92 ) ;
V_91 = * V_90 ;
V_49 = F_14 ( V_76 , V_75 -> V_80 [ V_69 ] ) ;
do {
const struct V_48 * V_56 ;
const struct V_99 * V_100 ;
F_25 ( V_49 ) ;
V_93 . V_101 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_49 -> V_16 ,
& V_93 . V_101 , & V_93 . V_12 , & V_93 . V_13 ) ) {
V_102:
V_49 = F_29 ( V_49 ) ;
continue;
}
F_30 (ematch, e) {
V_93 . V_103 = V_100 -> V_58 . V_59 . V_103 ;
V_93 . V_104 = V_100 -> V_62 ;
if ( ! V_93 . V_103 -> V_103 ( V_6 , & V_93 ) )
goto V_102;
}
F_31 ( V_49 -> V_105 , V_6 -> V_106 , 1 ) ;
V_56 = F_16 ( V_49 ) ;
F_25 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_32 ( V_107 )
if ( F_33 ( V_6 -> V_108 ) )
F_19 ( V_6 , V_69 , V_71 , V_72 ,
V_85 -> V_60 , V_75 , V_49 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_109 ;
V_109 = ( (struct V_55 * ) V_56 ) -> V_65 ;
if ( V_109 < 0 ) {
if ( V_109 != V_110 ) {
V_65 = ( unsigned int ) ( - V_109 ) - 1 ;
break;
}
if ( * V_90 <= V_91 )
V_49 = F_14 ( V_76 ,
V_75 -> V_111 [ V_69 ] ) ;
else
V_49 = F_29 ( V_89 [ -- * V_90 ] ) ;
continue;
}
if ( V_76 + V_109 != F_29 ( V_49 ) &&
! ( V_49 -> V_16 . V_32 & V_112 ) ) {
if ( * V_90 >= V_75 -> V_113 ) {
V_65 = V_43 ;
break;
}
V_89 [ ( * V_90 ) ++ ] = V_49 ;
}
V_49 = F_14 ( V_76 , V_109 ) ;
continue;
}
V_93 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_93 . V_42 = V_56 -> V_62 ;
V_65 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_6 , & V_93 ) ;
if ( V_65 == V_114 )
V_49 = F_29 ( V_49 ) ;
else
break;
} while ( ! V_93 . V_13 );
* V_90 = V_91 ;
F_34 ( V_94 ) ;
F_35 () ;
#ifdef F_36
return V_115 ;
#else
if ( V_93 . V_13 )
return V_43 ;
else return V_65 ;
#endif
}
static int
F_37 ( const struct V_74 * V_116 ,
unsigned int V_98 , void * V_117 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_118 ; V_69 ++ ) {
unsigned int V_119 = V_116 -> V_80 [ V_69 ] ;
struct V_44 * V_49 = (struct V_44 * ) ( V_117 + V_119 ) ;
if ( ! ( V_98 & ( 1 << V_69 ) ) )
continue;
V_49 -> V_105 . V_120 = V_119 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_16 ( V_49 ) ;
int V_121 = V_49 -> V_122 & ( 1 << V_69 ) ;
if ( V_49 -> V_122 & ( 1 << V_118 ) ) {
F_38 ( L_12 ,
V_69 , V_119 , V_49 -> V_122 ) ;
return 0 ;
}
V_49 -> V_122 |= ( ( 1 << V_69 ) | ( 1 << V_118 ) ) ;
if ( ( V_49 -> V_63 == sizeof( struct V_44 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_123 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < 0 &&
F_15 ( & V_49 -> V_16 ) ) || V_121 ) {
unsigned int V_124 , V_125 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_123 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < - V_126 - 1 ) {
F_11 ( L_13
L_14 ,
V_56 -> V_65 ) ;
return 0 ;
}
do {
V_49 -> V_122 ^= ( 1 << V_118 ) ;
#ifdef F_39
if ( V_49 -> V_122
& ( 1 << V_118 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_69 , V_119 ) ;
}
#endif
V_124 = V_119 ;
V_119 = V_49 -> V_105 . V_120 ;
V_49 -> V_105 . V_120 = 0 ;
if ( V_119 == V_124 )
goto V_127;
V_49 = (struct V_44 * )
( V_117 + V_119 ) ;
} while ( V_124 == V_119 + V_49 -> V_128 );
V_125 = V_49 -> V_128 ;
V_49 = (struct V_44 * )
( V_117 + V_119 + V_125 ) ;
V_49 -> V_105 . V_120 = V_119 ;
V_119 += V_125 ;
} else {
int V_129 = V_56 -> V_65 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_123 . V_60 ,
V_64 ) == 0 &&
V_129 >= 0 ) {
if ( V_129 > V_116 -> V_125 -
sizeof( struct V_44 ) ) {
F_11 ( L_18
L_19 ,
V_129 ) ;
return 0 ;
}
F_11 ( L_20 ,
V_119 , V_129 ) ;
} else {
V_129 = V_119 + V_49 -> V_128 ;
}
V_49 = (struct V_44 * )
( V_117 + V_129 ) ;
V_49 -> V_105 . V_120 = V_119 ;
V_119 = V_129 ;
}
}
V_127:
F_11 ( L_21 , V_69 ) ;
}
return 1 ;
}
static void F_40 ( struct V_99 * V_130 , struct V_131 * V_131 )
{
struct V_132 V_41 ;
V_41 . V_131 = V_131 ;
V_41 . V_103 = V_130 -> V_58 . V_59 . V_103 ;
V_41 . V_104 = V_130 -> V_62 ;
V_41 . V_95 = V_96 ;
if ( V_41 . V_103 -> V_133 != NULL )
V_41 . V_103 -> V_133 ( & V_41 ) ;
F_41 ( V_41 . V_103 -> V_134 ) ;
}
static int
F_42 ( const struct V_44 * V_49 , const char * V_60 )
{
const struct V_48 * V_56 ;
if ( ! F_10 ( & V_49 -> V_16 ) ) {
F_11 ( L_22 , V_49 , V_60 ) ;
return - V_135 ;
}
if ( V_49 -> V_63 + sizeof( struct V_48 ) >
V_49 -> V_128 )
return - V_135 ;
V_56 = F_16 ( V_49 ) ;
if ( V_49 -> V_63 + V_56 -> V_58 . V_136 > V_49 -> V_128 )
return - V_135 ;
return 0 ;
}
static int F_43 ( struct V_99 * V_130 , struct V_137 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_138 ;
int V_14 ;
V_41 -> V_103 = V_130 -> V_58 . V_59 . V_103 ;
V_41 -> V_104 = V_130 -> V_62 ;
V_14 = F_44 ( V_41 , V_130 -> V_58 . V_139 - sizeof( * V_130 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_41 . V_103 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_45 ( struct V_99 * V_130 , struct V_137 * V_41 )
{
struct V_140 * V_103 ;
int V_14 ;
V_103 = F_46 ( V_96 , V_130 -> V_58 . V_123 . V_60 ,
V_130 -> V_58 . V_123 . V_141 ) ;
if ( F_47 ( V_103 ) ) {
F_11 ( L_24 , V_130 -> V_58 . V_123 . V_60 ) ;
return F_48 ( V_103 ) ;
}
V_130 -> V_58 . V_59 . V_103 = V_103 ;
V_14 = F_43 ( V_130 , V_41 ) ;
if ( V_14 )
goto V_142;
return 0 ;
V_142:
F_41 ( V_130 -> V_58 . V_59 . V_103 -> V_134 ) ;
return V_14 ;
}
static int F_49 ( struct V_44 * V_49 , struct V_131 * V_131 , const char * V_60 )
{
struct V_48 * V_56 = F_17 ( V_49 ) ;
struct V_143 V_41 = {
. V_131 = V_131 ,
. V_85 = V_60 ,
. V_138 = V_49 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_42 = V_56 -> V_62 ,
. V_144 = V_49 -> V_122 ,
. V_95 = V_96 ,
} ;
int V_14 ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_50 ( & V_41 , V_56 -> V_58 . V_136 - sizeof( * V_56 ) ,
V_49 -> V_16 . V_37 , V_49 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_51 ( struct V_44 * V_49 , struct V_131 * V_131 , const char * V_60 ,
unsigned int V_125 )
{
struct V_48 * V_56 ;
struct V_145 * V_57 ;
int V_14 ;
unsigned int V_146 ;
struct V_137 V_147 ;
struct V_99 * V_100 ;
V_14 = F_42 ( V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_146 = 0 ;
V_147 . V_131 = V_131 ;
V_147 . V_85 = V_60 ;
V_147 . V_138 = & V_49 -> V_16 ;
V_147 . V_144 = V_49 -> V_122 ;
V_147 . V_95 = V_96 ;
F_30 (ematch, e) {
V_14 = F_45 ( V_100 , & V_147 ) ;
if ( V_14 != 0 )
goto V_148;
++ V_146 ;
}
V_56 = F_17 ( V_49 ) ;
V_57 = F_52 ( V_96 , V_56 -> V_58 . V_123 . V_60 ,
V_56 -> V_58 . V_123 . V_141 ) ;
if ( F_47 ( V_57 ) ) {
F_11 ( L_25 , V_56 -> V_58 . V_123 . V_60 ) ;
V_14 = F_48 ( V_57 ) ;
goto V_148;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_14 = F_49 ( V_49 , V_131 , V_60 ) ;
if ( V_14 )
goto V_142;
return 0 ;
V_142:
F_41 ( V_56 -> V_58 . V_59 . V_57 -> V_134 ) ;
V_148:
F_30 (ematch, e) {
if ( V_146 -- == 0 )
break;
F_40 ( V_100 , V_131 ) ;
}
return V_14 ;
}
static bool F_53 ( const struct V_44 * V_49 )
{
const struct V_48 * V_56 ;
unsigned int V_65 ;
if ( ! F_15 ( & V_49 -> V_16 ) )
return false ;
V_56 = F_16 ( V_49 ) ;
if ( strcmp ( V_56 -> V_58 . V_123 . V_60 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_55 * ) V_56 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_115 ;
}
static int
F_54 ( struct V_44 * V_49 ,
struct V_74 * V_116 ,
const unsigned char * V_45 ,
const unsigned char * V_149 ,
const unsigned int * V_150 ,
const unsigned int * V_151 ,
unsigned int V_98 )
{
unsigned int V_152 ;
if ( ( unsigned long ) V_49 % F_55 ( struct V_44 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_44 ) >= V_149 ) {
F_11 ( L_26 , V_49 ) ;
return - V_135 ;
}
if ( V_49 -> V_128
< sizeof( struct V_44 ) + sizeof( struct V_48 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_128 ) ;
return - V_135 ;
}
for ( V_152 = 0 ; V_152 < V_118 ; V_152 ++ ) {
if ( ! ( V_98 & ( 1 << V_152 ) ) )
continue;
if ( ( unsigned char * ) V_49 - V_45 == V_150 [ V_152 ] )
V_116 -> V_80 [ V_152 ] = V_150 [ V_152 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_151 [ V_152 ] ) {
if ( ! F_53 ( V_49 ) ) {
F_38 ( L_28
L_29
L_30 ) ;
return - V_135 ;
}
V_116 -> V_111 [ V_152 ] = V_151 [ V_152 ] ;
}
}
V_49 -> V_105 = ( (struct V_153 ) { 0 , 0 } ) ;
V_49 -> V_122 = 0 ;
return 0 ;
}
static void F_56 ( struct V_44 * V_49 , struct V_131 * V_131 )
{
struct V_154 V_41 ;
struct V_48 * V_56 ;
struct V_99 * V_100 ;
F_30 (ematch, e)
F_40 ( V_100 , V_131 ) ;
V_56 = F_17 ( V_49 ) ;
V_41 . V_131 = V_131 ;
V_41 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_41 . V_42 = V_56 -> V_62 ;
V_41 . V_95 = V_96 ;
if ( V_41 . V_57 -> V_133 != NULL )
V_41 . V_57 -> V_133 ( & V_41 ) ;
F_41 ( V_41 . V_57 -> V_134 ) ;
}
static int
F_57 ( struct V_131 * V_131 , struct V_74 * V_116 , void * V_117 ,
const struct V_155 * V_156 )
{
struct V_44 * V_78 ;
unsigned int V_157 ;
int V_14 = 0 ;
V_116 -> V_125 = V_156 -> V_125 ;
V_116 -> V_158 = V_156 -> V_159 ;
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
V_116 -> V_80 [ V_157 ] = 0xFFFFFFFF ;
V_116 -> V_111 [ V_157 ] = 0xFFFFFFFF ;
}
F_11 ( L_31 , V_116 -> V_125 ) ;
V_157 = 0 ;
F_21 (iter, entry0, newinfo->size) {
V_14 = F_54 ( V_78 , V_116 , V_117 ,
V_117 + V_156 -> V_125 ,
V_156 -> V_80 ,
V_156 -> V_111 ,
V_156 -> V_98 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_157 ;
if ( strcmp ( F_17 ( V_78 ) -> V_58 . V_123 . V_60 ,
V_61 ) == 0 )
++ V_116 -> V_113 ;
}
if ( V_157 != V_156 -> V_159 ) {
F_11 ( L_32 ,
V_157 , V_156 -> V_159 ) ;
return - V_135 ;
}
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
if ( ! ( V_156 -> V_98 & ( 1 << V_157 ) ) )
continue;
if ( V_116 -> V_80 [ V_157 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_157 , V_156 -> V_80 [ V_157 ] ) ;
return - V_135 ;
}
if ( V_116 -> V_111 [ V_157 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_157 , V_156 -> V_111 [ V_157 ] ) ;
return - V_135 ;
}
}
if ( ! F_37 ( V_116 , V_156 -> V_98 , V_117 ) )
return - V_160 ;
V_157 = 0 ;
F_21 (iter, entry0, newinfo->size) {
V_14 = F_51 ( V_78 , V_131 , V_156 -> V_60 , V_156 -> V_125 ) ;
if ( V_14 != 0 )
break;
++ V_157 ;
}
if ( V_14 != 0 ) {
F_21 (iter, entry0, newinfo->size) {
if ( V_157 -- == 0 )
break;
F_56 ( V_78 , V_131 ) ;
}
return V_14 ;
}
F_58 (i) {
if ( V_116 -> V_79 [ V_157 ] && V_116 -> V_79 [ V_157 ] != V_117 )
memcpy ( V_116 -> V_79 [ V_157 ] , V_117 , V_116 -> V_125 ) ;
}
return V_14 ;
}
static void
F_59 ( const struct V_74 * V_56 ,
struct V_153 V_105 [] )
{
struct V_44 * V_78 ;
unsigned int V_92 ;
unsigned int V_157 ;
F_58 (cpu) {
T_2 * V_50 = & F_60 ( V_161 , V_92 ) ;
V_157 = 0 ;
F_21 (iter, t->entries[cpu], t->size) {
T_3 V_162 , V_120 ;
unsigned int V_163 ;
do {
V_163 = F_61 ( V_50 ) ;
V_162 = V_78 -> V_105 . V_162 ;
V_120 = V_78 -> V_105 . V_120 ;
} while ( F_62 ( V_50 , V_163 ) );
F_31 ( V_105 [ V_157 ] , V_162 , V_120 ) ;
++ V_157 ;
}
}
}
static struct V_153 * F_63 ( const struct V_1 * V_85 )
{
unsigned int V_164 ;
struct V_153 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
V_164 = sizeof( struct V_153 ) * V_75 -> V_158 ;
V_105 = F_64 ( V_164 ) ;
if ( V_105 == NULL )
return F_65 ( - V_165 ) ;
F_59 ( V_75 , V_105 ) ;
return V_105 ;
}
static int
F_66 ( unsigned int V_166 ,
const struct V_1 * V_85 ,
void T_4 * V_167 )
{
unsigned int V_168 , V_169 ;
const struct V_44 * V_49 ;
struct V_153 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
int V_14 = 0 ;
const void * V_170 ;
V_105 = F_63 ( V_85 ) ;
if ( F_47 ( V_105 ) )
return F_48 ( V_105 ) ;
V_170 = V_75 -> V_79 [ F_67 () ] ;
if ( F_68 ( V_167 , V_170 , V_166 ) != 0 ) {
V_14 = - V_171 ;
goto V_172;
}
for ( V_168 = 0 , V_169 = 0 ; V_168 < V_166 ; V_168 += V_49 -> V_128 , V_169 ++ ) {
unsigned int V_157 ;
const struct V_99 * V_130 ;
const struct V_48 * V_56 ;
V_49 = (struct V_44 * ) ( V_170 + V_168 ) ;
if ( F_68 ( V_167 + V_168
+ F_69 ( struct V_44 , V_105 ) ,
& V_105 [ V_169 ] ,
sizeof( V_105 [ V_169 ] ) ) != 0 ) {
V_14 = - V_171 ;
goto V_172;
}
for ( V_157 = sizeof( struct V_44 ) ;
V_157 < V_49 -> V_63 ;
V_157 += V_130 -> V_58 . V_139 ) {
V_130 = ( void * ) V_49 + V_157 ;
if ( F_68 ( V_167 + V_168 + V_157
+ F_69 ( struct V_99 ,
V_58 . V_123 . V_60 ) ,
V_130 -> V_58 . V_59 . V_103 -> V_60 ,
strlen ( V_130 -> V_58 . V_59 . V_103 -> V_60 ) + 1 )
!= 0 ) {
V_14 = - V_171 ;
goto V_172;
}
}
V_56 = F_16 ( V_49 ) ;
if ( F_68 ( V_167 + V_168 + V_49 -> V_63
+ F_69 ( struct V_48 ,
V_58 . V_123 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_14 = - V_171 ;
goto V_172;
}
}
V_172:
F_70 ( V_105 ) ;
return V_14 ;
}
static void F_71 ( void * V_23 , const void * V_19 )
{
int V_109 = * ( V_173 * ) V_19 ;
if ( V_109 > 0 )
V_109 += F_72 ( V_83 , V_109 ) ;
memcpy ( V_23 , & V_109 , sizeof( V_109 ) ) ;
}
static int F_73 ( void T_4 * V_23 , const void * V_19 )
{
V_173 V_174 = * ( int * ) V_19 ;
if ( V_174 > 0 )
V_174 -= F_72 ( V_83 , V_174 ) ;
return F_68 ( V_23 , & V_174 , sizeof( V_174 ) ) ? - V_171 : 0 ;
}
static int F_74 ( const struct V_44 * V_49 ,
const struct V_74 * V_2 ,
const void * V_45 , struct V_74 * V_116 )
{
const struct V_99 * V_100 ;
const struct V_48 * V_56 ;
unsigned int V_175 ;
int V_168 , V_157 , V_14 ;
V_168 = sizeof( struct V_44 ) - sizeof( struct V_176 ) ;
V_175 = ( void * ) V_49 - V_45 ;
F_30 (ematch, e)
V_168 += F_75 ( V_100 -> V_58 . V_59 . V_103 ) ;
V_56 = F_16 ( V_49 ) ;
V_168 += F_76 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_116 -> V_125 -= V_168 ;
V_14 = F_77 ( V_83 , V_175 , V_168 ) ;
if ( V_14 )
return V_14 ;
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
if ( V_2 -> V_80 [ V_157 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_157 ] ) ) )
V_116 -> V_80 [ V_157 ] -= V_168 ;
if ( V_2 -> V_111 [ V_157 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_111 [ V_157 ] ) ) )
V_116 -> V_111 [ V_157 ] -= V_168 ;
}
return 0 ;
}
static int F_78 ( const struct V_74 * V_2 ,
struct V_74 * V_116 )
{
struct V_44 * V_78 ;
void * V_170 ;
int V_14 ;
if ( ! V_116 || ! V_2 )
return - V_135 ;
memcpy ( V_116 , V_2 , F_69 ( struct V_74 , V_79 ) ) ;
V_116 -> V_177 = 0 ;
V_170 = V_2 -> V_79 [ F_67 () ] ;
F_79 ( V_83 , V_2 -> V_158 ) ;
F_21 (iter, loc_cpu_entry, info->size) {
V_14 = F_74 ( V_78 , V_2 , V_170 , V_116 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_80 ( struct V_131 * V_131 , void T_4 * V_123 ,
const int * V_106 , int V_178 )
{
char V_60 [ V_179 ] ;
struct V_1 * V_56 ;
int V_14 ;
if ( * V_106 != sizeof( struct V_180 ) ) {
F_11 ( L_35 , * V_106 ,
sizeof( struct V_180 ) ) ;
return - V_135 ;
}
if ( F_81 ( V_60 , V_123 , sizeof( V_60 ) ) != 0 )
return - V_171 ;
V_60 [ V_179 - 1 ] = '\0' ;
#ifdef F_82
if ( V_178 )
F_83 ( V_83 ) ;
#endif
V_56 = F_84 ( F_85 ( V_131 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( ! F_86 ( V_56 ) ) {
struct V_180 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_82
struct V_74 V_181 ;
if ( V_178 ) {
V_14 = F_78 ( V_75 , & V_181 ) ;
F_87 ( V_83 ) ;
V_75 = & V_181 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_98 = V_56 -> V_98 ;
memcpy ( V_2 . V_80 , V_75 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_111 , V_75 -> V_111 ,
sizeof( V_2 . V_111 ) ) ;
V_2 . V_159 = V_75 -> V_158 ;
V_2 . V_125 = V_75 -> V_125 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_68 ( V_123 , & V_2 , * V_106 ) != 0 )
V_14 = - V_171 ;
else
V_14 = 0 ;
F_88 ( V_56 ) ;
F_41 ( V_56 -> V_134 ) ;
} else
V_14 = V_56 ? F_48 ( V_56 ) : - V_182 ;
#ifdef F_82
if ( V_178 )
F_89 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_90 ( struct V_131 * V_131 , struct V_183 T_4 * V_184 ,
const int * V_106 )
{
int V_14 ;
struct V_183 V_185 ;
struct V_1 * V_56 ;
if ( * V_106 < sizeof( V_185 ) ) {
F_11 ( L_37 , * V_106 , sizeof( V_185 ) ) ;
return - V_135 ;
}
if ( F_81 ( & V_185 , V_184 , sizeof( V_185 ) ) != 0 )
return - V_171 ;
if ( * V_106 != sizeof( struct V_183 ) + V_185 . V_125 ) {
F_11 ( L_38 ,
* V_106 , sizeof( V_185 ) + V_185 . V_125 ) ;
return - V_135 ;
}
V_56 = F_85 ( V_131 , V_83 , V_185 . V_60 ) ;
if ( ! F_86 ( V_56 ) ) {
struct V_74 * V_75 = V_56 -> V_75 ;
F_11 ( L_39 , V_75 -> V_158 ) ;
if ( V_185 . V_125 == V_75 -> V_125 )
V_14 = F_66 ( V_75 -> V_125 ,
V_56 , V_184 -> V_186 ) ;
else {
F_11 ( L_40 ,
V_75 -> V_125 , V_185 . V_125 ) ;
V_14 = - V_187 ;
}
F_41 ( V_56 -> V_134 ) ;
F_88 ( V_56 ) ;
} else
V_14 = V_56 ? F_48 ( V_56 ) : - V_182 ;
return V_14 ;
}
static int
F_91 ( struct V_131 * V_131 , const char * V_60 , unsigned int V_98 ,
struct V_74 * V_116 , unsigned int V_188 ,
void T_4 * V_189 )
{
int V_14 ;
struct V_1 * V_56 ;
struct V_74 * V_190 ;
struct V_153 * V_105 ;
const void * V_191 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_105 = F_64 ( V_188 * sizeof( struct V_153 ) ) ;
if ( ! V_105 ) {
V_14 = - V_165 ;
goto V_72;
}
V_56 = F_84 ( F_85 ( V_131 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( F_86 ( V_56 ) ) {
V_14 = V_56 ? F_48 ( V_56 ) : - V_182 ;
goto V_192;
}
if ( V_98 != V_56 -> V_98 ) {
F_11 ( L_41 ,
V_98 , V_56 -> V_98 ) ;
V_14 = - V_135 ;
goto V_193;
}
V_190 = F_92 ( V_56 , V_188 , V_116 , & V_14 ) ;
if ( ! V_190 )
goto V_193;
F_11 ( L_42 ,
V_190 -> V_158 , V_190 -> V_177 , V_116 -> V_158 ) ;
if ( ( V_190 -> V_158 > V_190 -> V_177 ) ||
( V_116 -> V_158 <= V_190 -> V_177 ) )
F_41 ( V_56 -> V_134 ) ;
if ( ( V_190 -> V_158 > V_190 -> V_177 ) &&
( V_116 -> V_158 <= V_190 -> V_177 ) )
F_41 ( V_56 -> V_134 ) ;
F_59 ( V_190 , V_105 ) ;
V_191 = V_190 -> V_79 [ F_67 () ] ;
F_21 (iter, loc_cpu_old_entry, oldinfo->size)
F_56 ( V_78 , V_131 ) ;
F_93 ( V_190 ) ;
if ( F_68 ( V_189 , V_105 ,
sizeof( struct V_153 ) * V_188 ) != 0 )
V_14 = - V_171 ;
F_70 ( V_105 ) ;
F_88 ( V_56 ) ;
return V_14 ;
V_193:
F_41 ( V_56 -> V_134 ) ;
F_88 ( V_56 ) ;
V_192:
F_70 ( V_105 ) ;
V_72:
return V_14 ;
}
static int
F_94 ( struct V_131 * V_131 , const void T_4 * V_123 , unsigned int V_106 )
{
int V_14 ;
struct V_155 V_181 ;
struct V_74 * V_116 ;
void * V_170 ;
struct V_44 * V_78 ;
if ( F_81 ( & V_181 , V_123 , sizeof( V_181 ) ) != 0 )
return - V_171 ;
if ( V_181 . V_188 >= V_194 / sizeof( struct V_153 ) )
return - V_165 ;
V_181 . V_60 [ sizeof( V_181 . V_60 ) - 1 ] = 0 ;
V_116 = F_95 ( V_181 . V_125 ) ;
if ( ! V_116 )
return - V_165 ;
V_170 = V_116 -> V_79 [ F_67 () ] ;
if ( F_81 ( V_170 , V_123 + sizeof( V_181 ) ,
V_181 . V_125 ) != 0 ) {
V_14 = - V_171 ;
goto V_195;
}
V_14 = F_57 ( V_131 , V_116 , V_170 , & V_181 ) ;
if ( V_14 != 0 )
goto V_195;
F_11 ( L_43 ) ;
V_14 = F_91 ( V_131 , V_181 . V_60 , V_181 . V_98 , V_116 ,
V_181 . V_188 , V_181 . V_105 ) ;
if ( V_14 )
goto V_196;
return 0 ;
V_196:
F_21 (iter, loc_cpu_entry, newinfo->size)
F_56 ( V_78 , V_131 ) ;
V_195:
F_93 ( V_116 ) ;
return V_14 ;
}
static int
F_96 ( struct V_131 * V_131 , const void T_4 * V_123 , unsigned int V_106 ,
int V_178 )
{
unsigned int V_157 , V_197 ;
struct V_198 V_181 ;
struct V_153 * V_199 ;
unsigned int V_188 ;
char * V_60 ;
int V_125 ;
void * V_200 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_14 = 0 ;
const void * V_170 ;
struct V_44 * V_78 ;
unsigned int V_94 ;
#ifdef F_82
struct V_201 V_202 ;
if ( V_178 ) {
V_200 = & V_202 ;
V_125 = sizeof( struct V_201 ) ;
} else
#endif
{
V_200 = & V_181 ;
V_125 = sizeof( struct V_198 ) ;
}
if ( F_81 ( V_200 , V_123 , V_125 ) != 0 )
return - V_171 ;
#ifdef F_82
if ( V_178 ) {
V_188 = V_202 . V_188 ;
V_60 = V_202 . V_60 ;
} else
#endif
{
V_188 = V_181 . V_188 ;
V_60 = V_181 . V_60 ;
}
if ( V_106 != V_125 + V_188 * sizeof( struct V_153 ) )
return - V_135 ;
V_199 = F_97 ( V_106 - V_125 ) ;
if ( ! V_199 )
return - V_165 ;
if ( F_81 ( V_199 , V_123 + V_125 , V_106 - V_125 ) != 0 ) {
V_14 = - V_171 ;
goto free;
}
V_56 = F_85 ( V_131 , V_83 , V_60 ) ;
if ( F_86 ( V_56 ) ) {
V_14 = V_56 ? F_48 ( V_56 ) : - V_182 ;
goto free;
}
F_26 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_158 != V_188 ) {
V_14 = - V_135 ;
goto V_203;
}
V_157 = 0 ;
V_197 = F_20 () ;
V_94 = F_27 () ;
V_170 = V_75 -> V_79 [ V_197 ] ;
F_21 (iter, loc_cpu_entry, private->size) {
F_31 ( V_78 -> V_105 , V_199 [ V_157 ] . V_162 , V_199 [ V_157 ] . V_120 ) ;
++ V_157 ;
}
F_34 ( V_94 ) ;
V_203:
F_35 () ;
F_88 ( V_56 ) ;
F_41 ( V_56 -> V_134 ) ;
free:
F_70 ( V_199 ) ;
return V_14 ;
}
static int
F_98 ( struct V_44 * V_49 , void T_4 * * V_204 ,
unsigned int * V_125 , struct V_153 * V_105 ,
unsigned int V_157 )
{
struct V_48 * V_56 ;
struct V_176 T_4 * V_205 ;
T_5 V_63 , V_128 ;
T_6 V_206 ;
const struct V_99 * V_100 ;
int V_14 = 0 ;
V_206 = * V_125 ;
V_205 = (struct V_176 T_4 * ) * V_204 ;
if ( F_68 ( V_205 , V_49 , sizeof( struct V_44 ) ) != 0 ||
F_68 ( & V_205 -> V_105 , & V_105 [ V_157 ] ,
sizeof( V_105 [ V_157 ] ) ) != 0 )
return - V_171 ;
* V_204 += sizeof( struct V_176 ) ;
* V_125 -= sizeof( struct V_44 ) - sizeof( struct V_176 ) ;
F_30 (ematch, e) {
V_14 = F_99 ( V_100 , V_204 , V_125 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_63 = V_49 -> V_63 - ( V_206 - * V_125 ) ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_100 ( V_56 , V_204 , V_125 ) ;
if ( V_14 )
return V_14 ;
V_128 = V_49 -> V_128 - ( V_206 - * V_125 ) ;
if ( F_101 ( V_63 , & V_205 -> V_63 ) != 0 ||
F_101 ( V_128 , & V_205 -> V_128 ) != 0 )
return - V_171 ;
return 0 ;
}
static int
F_102 ( struct V_99 * V_130 ,
const char * V_60 ,
const struct V_9 * V_16 ,
unsigned int V_207 ,
int * V_125 )
{
struct V_140 * V_103 ;
V_103 = F_46 ( V_96 , V_130 -> V_58 . V_123 . V_60 ,
V_130 -> V_58 . V_123 . V_141 ) ;
if ( F_47 ( V_103 ) ) {
F_11 ( L_44 ,
V_130 -> V_58 . V_123 . V_60 ) ;
return F_48 ( V_103 ) ;
}
V_130 -> V_58 . V_59 . V_103 = V_103 ;
* V_125 += F_75 ( V_103 ) ;
return 0 ;
}
static void F_103 ( struct V_176 * V_49 )
{
struct V_48 * V_56 ;
struct V_99 * V_100 ;
F_30 (ematch, e)
F_41 ( V_100 -> V_58 . V_59 . V_103 -> V_134 ) ;
V_56 = F_104 ( V_49 ) ;
F_41 ( V_56 -> V_58 . V_59 . V_57 -> V_134 ) ;
}
static int
F_105 ( struct V_176 * V_49 ,
struct V_74 * V_116 ,
unsigned int * V_125 ,
const unsigned char * V_45 ,
const unsigned char * V_149 ,
const unsigned int * V_150 ,
const unsigned int * V_151 ,
const char * V_60 )
{
struct V_99 * V_100 ;
struct V_48 * V_56 ;
struct V_145 * V_57 ;
unsigned int V_175 ;
unsigned int V_146 ;
int V_14 , V_168 , V_152 ;
F_11 ( L_45 , V_49 ) ;
if ( ( unsigned long ) V_49 % F_55 ( struct V_176 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_176 ) >= V_149 ) {
F_11 ( L_46 , V_49 , V_149 ) ;
return - V_135 ;
}
if ( V_49 -> V_128 < sizeof( struct V_176 ) +
sizeof( struct V_208 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_128 ) ;
return - V_135 ;
}
V_14 = F_42 ( (struct V_44 * ) V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_168 = sizeof( struct V_44 ) - sizeof( struct V_176 ) ;
V_175 = ( void * ) V_49 - ( void * ) V_45 ;
V_146 = 0 ;
F_30 (ematch, e) {
V_14 = F_102 ( V_100 , V_60 ,
& V_49 -> V_16 , V_49 -> V_122 , & V_168 ) ;
if ( V_14 != 0 )
goto V_209;
++ V_146 ;
}
V_56 = F_104 ( V_49 ) ;
V_57 = F_52 ( V_96 , V_56 -> V_58 . V_123 . V_60 ,
V_56 -> V_58 . V_123 . V_141 ) ;
if ( F_47 ( V_57 ) ) {
F_11 ( L_47 ,
V_56 -> V_58 . V_123 . V_60 ) ;
V_14 = F_48 ( V_57 ) ;
goto V_209;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_168 += F_76 ( V_57 ) ;
* V_125 += V_168 ;
V_14 = F_77 ( V_83 , V_175 , V_168 ) ;
if ( V_14 )
goto V_72;
for ( V_152 = 0 ; V_152 < V_118 ; V_152 ++ ) {
if ( ( unsigned char * ) V_49 - V_45 == V_150 [ V_152 ] )
V_116 -> V_80 [ V_152 ] = V_150 [ V_152 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_151 [ V_152 ] )
V_116 -> V_111 [ V_152 ] = V_151 [ V_152 ] ;
}
memset ( & V_49 -> V_105 , 0 , sizeof( V_49 -> V_105 ) ) ;
V_49 -> V_122 = 0 ;
return 0 ;
V_72:
F_41 ( V_56 -> V_58 . V_59 . V_57 -> V_134 ) ;
V_209:
F_30 (ematch, e) {
if ( V_146 -- == 0 )
break;
F_41 ( V_100 -> V_58 . V_59 . V_103 -> V_134 ) ;
}
return V_14 ;
}
static int
F_106 ( struct V_176 * V_49 , void * * V_204 ,
unsigned int * V_125 , const char * V_60 ,
struct V_74 * V_116 , unsigned char * V_45 )
{
struct V_48 * V_56 ;
struct V_44 * V_210 ;
unsigned int V_206 ;
int V_14 , V_152 ;
struct V_99 * V_100 ;
V_14 = 0 ;
V_206 = * V_125 ;
V_210 = (struct V_44 * ) * V_204 ;
memcpy ( V_210 , V_49 , sizeof( struct V_44 ) ) ;
memcpy ( & V_210 -> V_105 , & V_49 -> V_105 , sizeof( V_49 -> V_105 ) ) ;
* V_204 += sizeof( struct V_44 ) ;
* V_125 += sizeof( struct V_44 ) - sizeof( struct V_176 ) ;
F_30 (ematch, e) {
V_14 = F_107 ( V_100 , V_204 , V_125 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_210 -> V_63 = V_49 -> V_63 - ( V_206 - * V_125 ) ;
V_56 = F_104 ( V_49 ) ;
F_108 ( V_56 , V_204 , V_125 ) ;
V_210 -> V_128 = V_49 -> V_128 - ( V_206 - * V_125 ) ;
for ( V_152 = 0 ; V_152 < V_118 ; V_152 ++ ) {
if ( ( unsigned char * ) V_210 - V_45 < V_116 -> V_80 [ V_152 ] )
V_116 -> V_80 [ V_152 ] -= V_206 - * V_125 ;
if ( ( unsigned char * ) V_210 - V_45 < V_116 -> V_111 [ V_152 ] )
V_116 -> V_111 [ V_152 ] -= V_206 - * V_125 ;
}
return V_14 ;
}
static int F_109 ( struct V_44 * V_49 , struct V_131 * V_131 ,
const char * V_60 )
{
unsigned int V_146 ;
int V_14 = 0 ;
struct V_137 V_147 ;
struct V_99 * V_100 ;
V_146 = 0 ;
V_147 . V_131 = V_131 ;
V_147 . V_85 = V_60 ;
V_147 . V_138 = & V_49 -> V_16 ;
V_147 . V_144 = V_49 -> V_122 ;
V_147 . V_95 = V_96 ;
F_30 (ematch, e) {
V_14 = F_43 ( V_100 , & V_147 ) ;
if ( V_14 != 0 )
goto V_148;
++ V_146 ;
}
V_14 = F_49 ( V_49 , V_131 , V_60 ) ;
if ( V_14 )
goto V_148;
return 0 ;
V_148:
F_30 (ematch, e) {
if ( V_146 -- == 0 )
break;
F_40 ( V_100 , V_131 ) ;
}
return V_14 ;
}
static int
F_110 ( struct V_131 * V_131 ,
const char * V_60 ,
unsigned int V_98 ,
struct V_74 * * V_211 ,
void * * V_212 ,
unsigned int V_166 ,
unsigned int V_158 ,
unsigned int * V_150 ,
unsigned int * V_151 )
{
unsigned int V_157 , V_146 ;
struct V_74 * V_116 , * V_2 ;
void * V_119 , * V_117 , * V_213 ;
struct V_176 * V_214 ;
struct V_44 * V_215 ;
unsigned int V_125 ;
int V_14 = 0 ;
V_2 = * V_211 ;
V_117 = * V_212 ;
V_125 = V_166 ;
V_2 -> V_158 = V_158 ;
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
V_2 -> V_80 [ V_157 ] = 0xFFFFFFFF ;
V_2 -> V_111 [ V_157 ] = 0xFFFFFFFF ;
}
F_11 ( L_48 , V_2 -> V_125 ) ;
V_146 = 0 ;
F_83 ( V_83 ) ;
F_79 ( V_83 , V_158 ) ;
F_21 (iter0, entry0, total_size) {
V_14 = F_105 ( V_214 , V_2 , & V_125 ,
V_117 ,
V_117 + V_166 ,
V_150 ,
V_151 ,
V_60 ) ;
if ( V_14 != 0 )
goto V_216;
++ V_146 ;
}
V_14 = - V_135 ;
if ( V_146 != V_158 ) {
F_11 ( L_49 ,
V_146 , V_158 ) ;
goto V_216;
}
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
if ( ! ( V_98 & ( 1 << V_157 ) ) )
continue;
if ( V_2 -> V_80 [ V_157 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_157 , V_150 [ V_157 ] ) ;
goto V_216;
}
if ( V_2 -> V_111 [ V_157 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_157 , V_151 [ V_157 ] ) ;
goto V_216;
}
}
V_14 = - V_165 ;
V_116 = F_95 ( V_125 ) ;
if ( ! V_116 )
goto V_216;
V_116 -> V_158 = V_158 ;
for ( V_157 = 0 ; V_157 < V_118 ; V_157 ++ ) {
V_116 -> V_80 [ V_157 ] = V_2 -> V_80 [ V_157 ] ;
V_116 -> V_111 [ V_157 ] = V_2 -> V_111 [ V_157 ] ;
}
V_213 = V_116 -> V_79 [ F_67 () ] ;
V_119 = V_213 ;
V_125 = V_166 ;
F_21 (iter0, entry0, total_size) {
V_14 = F_106 ( V_214 , & V_119 , & V_125 ,
V_60 , V_116 , V_213 ) ;
if ( V_14 != 0 )
break;
}
F_87 ( V_83 ) ;
F_89 ( V_83 ) ;
if ( V_14 )
goto V_195;
V_14 = - V_160 ;
if ( ! F_37 ( V_116 , V_98 , V_213 ) )
goto V_195;
V_157 = 0 ;
F_21 (iter1, entry1, newinfo->size) {
V_14 = F_109 ( V_215 , V_131 , V_60 ) ;
if ( V_14 != 0 )
break;
++ V_157 ;
if ( strcmp ( F_17 ( V_215 ) -> V_58 . V_123 . V_60 ,
V_61 ) == 0 )
++ V_116 -> V_113 ;
}
if ( V_14 ) {
int V_217 = V_157 ;
V_146 -= V_157 ;
F_21 (iter0, entry0, newinfo->size) {
if ( V_217 -- > 0 )
continue;
if ( V_146 -- == 0 )
break;
F_103 ( V_214 ) ;
}
F_21 (iter1, entry1, newinfo->size) {
if ( V_157 -- == 0 )
break;
F_56 ( V_215 , V_131 ) ;
}
F_93 ( V_116 ) ;
return V_14 ;
}
F_58 (i)
if ( V_116 -> V_79 [ V_157 ] && V_116 -> V_79 [ V_157 ] != V_213 )
memcpy ( V_116 -> V_79 [ V_157 ] , V_213 , V_116 -> V_125 ) ;
* V_211 = V_116 ;
* V_212 = V_213 ;
F_93 ( V_2 ) ;
return 0 ;
V_195:
F_93 ( V_116 ) ;
V_72:
F_21 (iter0, entry0, total_size) {
if ( V_146 -- == 0 )
break;
F_103 ( V_214 ) ;
}
return V_14 ;
V_216:
F_87 ( V_83 ) ;
F_89 ( V_83 ) ;
goto V_72;
}
static int
F_111 ( struct V_131 * V_131 , void T_4 * V_123 , unsigned int V_106 )
{
int V_14 ;
struct V_218 V_181 ;
struct V_74 * V_116 ;
void * V_170 ;
struct V_44 * V_78 ;
if ( F_81 ( & V_181 , V_123 , sizeof( V_181 ) ) != 0 )
return - V_171 ;
if ( V_181 . V_125 >= V_194 / F_112 () )
return - V_165 ;
if ( V_181 . V_188 >= V_194 / sizeof( struct V_153 ) )
return - V_165 ;
V_181 . V_60 [ sizeof( V_181 . V_60 ) - 1 ] = 0 ;
V_116 = F_95 ( V_181 . V_125 ) ;
if ( ! V_116 )
return - V_165 ;
V_170 = V_116 -> V_79 [ F_67 () ] ;
if ( F_81 ( V_170 , V_123 + sizeof( V_181 ) ,
V_181 . V_125 ) != 0 ) {
V_14 = - V_171 ;
goto V_195;
}
V_14 = F_110 ( V_131 , V_181 . V_60 , V_181 . V_98 ,
& V_116 , & V_170 , V_181 . V_125 ,
V_181 . V_159 , V_181 . V_80 ,
V_181 . V_111 ) ;
if ( V_14 != 0 )
goto V_195;
F_11 ( L_50 ) ;
V_14 = F_91 ( V_131 , V_181 . V_60 , V_181 . V_98 , V_116 ,
V_181 . V_188 , F_113 ( V_181 . V_105 ) ) ;
if ( V_14 )
goto V_196;
return 0 ;
V_196:
F_21 (iter, loc_cpu_entry, newinfo->size)
F_56 ( V_78 , V_131 ) ;
V_195:
F_93 ( V_116 ) ;
return V_14 ;
}
static int
F_114 ( struct V_219 * V_220 , int V_221 , void T_4 * V_123 ,
unsigned int V_106 )
{
int V_14 ;
if ( ! F_115 ( F_116 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_14 = F_111 ( F_116 ( V_220 ) , V_123 , V_106 ) ;
break;
case V_226 :
V_14 = F_96 ( F_116 ( V_220 ) , V_123 , V_106 , 1 ) ;
break;
default:
F_11 ( L_51 , V_221 ) ;
V_14 = - V_135 ;
}
return V_14 ;
}
static int
F_117 ( unsigned int V_166 , struct V_1 * V_85 ,
void T_4 * V_167 )
{
struct V_153 * V_105 ;
const struct V_74 * V_75 = V_85 -> V_75 ;
void T_4 * V_119 ;
unsigned int V_125 ;
int V_14 = 0 ;
const void * V_170 ;
unsigned int V_157 = 0 ;
struct V_44 * V_78 ;
V_105 = F_63 ( V_85 ) ;
if ( F_47 ( V_105 ) )
return F_48 ( V_105 ) ;
V_170 = V_75 -> V_79 [ F_67 () ] ;
V_119 = V_167 ;
V_125 = V_166 ;
F_21 (iter, loc_cpu_entry, total_size) {
V_14 = F_98 ( V_78 , & V_119 ,
& V_125 , V_105 , V_157 ++ ) ;
if ( V_14 != 0 )
break;
}
F_70 ( V_105 ) ;
return V_14 ;
}
static int
F_118 ( struct V_131 * V_131 , struct V_227 T_4 * V_184 ,
int * V_106 )
{
int V_14 ;
struct V_227 V_185 ;
struct V_1 * V_56 ;
if ( * V_106 < sizeof( V_185 ) ) {
F_11 ( L_52 , * V_106 , sizeof( V_185 ) ) ;
return - V_135 ;
}
if ( F_81 ( & V_185 , V_184 , sizeof( V_185 ) ) != 0 )
return - V_171 ;
if ( * V_106 != sizeof( struct V_227 ) + V_185 . V_125 ) {
F_11 ( L_53 ,
* V_106 , sizeof( V_185 ) + V_185 . V_125 ) ;
return - V_135 ;
}
F_83 ( V_83 ) ;
V_56 = F_85 ( V_131 , V_83 , V_185 . V_60 ) ;
if ( ! F_86 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
F_11 ( L_39 , V_75 -> V_158 ) ;
V_14 = F_78 ( V_75 , & V_2 ) ;
if ( ! V_14 && V_185 . V_125 == V_2 . V_125 ) {
V_14 = F_117 ( V_75 -> V_125 ,
V_56 , V_184 -> V_186 ) ;
} else if ( ! V_14 ) {
F_11 ( L_54 ,
V_75 -> V_125 , V_185 . V_125 ) ;
V_14 = - V_187 ;
}
F_87 ( V_83 ) ;
F_41 ( V_56 -> V_134 ) ;
F_88 ( V_56 ) ;
} else
V_14 = V_56 ? F_48 ( V_56 ) : - V_182 ;
F_89 ( V_83 ) ;
return V_14 ;
}
static int
F_119 ( struct V_219 * V_220 , int V_221 , void T_4 * V_123 , int * V_106 )
{
int V_14 ;
if ( ! F_115 ( F_116 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_228 :
V_14 = F_80 ( F_116 ( V_220 ) , V_123 , V_106 , 1 ) ;
break;
case V_229 :
V_14 = F_118 ( F_116 ( V_220 ) , V_123 , V_106 ) ;
break;
default:
V_14 = F_120 ( V_220 , V_221 , V_123 , V_106 ) ;
}
return V_14 ;
}
static int
F_121 ( struct V_219 * V_220 , int V_221 , void T_4 * V_123 , unsigned int V_106 )
{
int V_14 ;
if ( ! F_115 ( F_116 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_14 = F_94 ( F_116 ( V_220 ) , V_123 , V_106 ) ;
break;
case V_226 :
V_14 = F_96 ( F_116 ( V_220 ) , V_123 , V_106 , 0 ) ;
break;
default:
F_11 ( L_51 , V_221 ) ;
V_14 = - V_135 ;
}
return V_14 ;
}
static int
F_120 ( struct V_219 * V_220 , int V_221 , void T_4 * V_123 , int * V_106 )
{
int V_14 ;
if ( ! F_115 ( F_116 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_228 :
V_14 = F_80 ( F_116 ( V_220 ) , V_123 , V_106 , 0 ) ;
break;
case V_229 :
V_14 = F_90 ( F_116 ( V_220 ) , V_123 , V_106 ) ;
break;
case V_230 :
case V_231 : {
struct V_232 V_233 ;
int V_57 ;
if ( * V_106 != sizeof( V_233 ) ) {
V_14 = - V_135 ;
break;
}
if ( F_81 ( & V_233 , V_123 , sizeof( V_233 ) ) != 0 ) {
V_14 = - V_171 ;
break;
}
V_233 . V_60 [ sizeof( V_233 . V_60 ) - 1 ] = 0 ;
if ( V_221 == V_231 )
V_57 = 1 ;
else
V_57 = 0 ;
F_84 ( F_122 ( V_83 , V_233 . V_60 ,
V_233 . V_141 ,
V_57 , & V_14 ) ,
L_55 , V_233 . V_60 ) ;
break;
}
default:
F_11 ( L_56 , V_221 ) ;
V_14 = - V_135 ;
}
return V_14 ;
}
struct V_1 * F_123 ( struct V_131 * V_131 ,
const struct V_1 * V_85 ,
const struct V_155 * V_156 )
{
int V_14 ;
struct V_74 * V_116 ;
struct V_74 V_234 = { 0 } ;
void * V_170 ;
struct V_1 * V_235 ;
V_116 = F_95 ( V_156 -> V_125 ) ;
if ( ! V_116 ) {
V_14 = - V_165 ;
goto V_72;
}
V_170 = V_116 -> V_79 [ F_67 () ] ;
memcpy ( V_170 , V_156 -> V_79 , V_156 -> V_125 ) ;
V_14 = F_57 ( V_131 , V_116 , V_170 , V_156 ) ;
if ( V_14 != 0 )
goto V_236;
V_235 = F_124 ( V_131 , V_85 , & V_234 , V_116 ) ;
if ( F_47 ( V_235 ) ) {
V_14 = F_48 ( V_235 ) ;
goto V_236;
}
return V_235 ;
V_236:
F_93 ( V_116 ) ;
V_72:
return F_65 ( V_14 ) ;
}
void F_125 ( struct V_131 * V_131 , struct V_1 * V_85 )
{
struct V_74 * V_75 ;
void * V_170 ;
struct V_237 * V_238 = V_85 -> V_134 ;
struct V_44 * V_78 ;
V_75 = F_126 ( V_85 ) ;
V_170 = V_75 -> V_79 [ F_67 () ] ;
F_21 (iter, loc_cpu_entry, private->size)
F_56 ( V_78 , V_131 ) ;
if ( V_75 -> V_158 > V_75 -> V_177 )
F_41 ( V_238 ) ;
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
static int F_130 ( const struct V_137 * V_41 )
{
const struct V_247 * V_248 = V_41 -> V_104 ;
return ( V_248 -> V_28 & ~ V_251 ) ? - V_135 : 0 ;
}
static int T_8 F_131 ( struct V_131 * V_131 )
{
return F_132 ( V_131 , V_96 ) ;
}
static void T_9 F_133 ( struct V_131 * V_131 )
{
F_134 ( V_131 , V_96 ) ;
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
F_141 ( L_58 ) ;
return 0 ;
V_259:
F_142 ( V_256 , F_138 ( V_256 ) ) ;
V_257:
F_143 ( V_254 , F_138 ( V_254 ) ) ;
V_255:
F_144 ( & V_252 ) ;
V_253:
return V_14 ;
}
static void T_11 F_145 ( void )
{
F_146 ( & V_258 ) ;
F_142 ( V_256 , F_138 ( V_256 ) ) ;
F_143 ( V_254 , F_138 ( V_254 ) ) ;
F_144 ( & V_252 ) ;
}
