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
const struct V_44 * V_76 ;
const char * V_51 , * V_52 , * V_53 ;
const struct V_44 * V_77 ;
unsigned int V_54 = 0 ;
struct V_78 * V_78 = F_20 ( V_71 ? V_71 : V_72 ) ;
V_76 = F_14 ( V_75 -> V_79 , V_75 -> V_80 [ V_69 ] ) ;
V_51 = V_52 = V_81 [ V_69 ] ;
V_53 = V_66 [ V_82 ] ;
F_21 (iter, root, private->size - private->hook_entry[hook])
if ( F_18 ( V_77 , V_49 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_22 ( V_78 , V_83 , V_69 , V_6 , V_71 , V_72 , & V_84 ,
L_11 ,
V_73 , V_52 , V_53 , V_54 ) ;
}
unsigned int
F_23 ( struct V_5 * V_6 ,
unsigned int V_69 ,
const struct V_85 * V_86 ,
struct V_1 * V_87 )
{
static const char V_88 [ V_89 ] V_90 ( ( F_24 ( sizeof( long ) ) ) ) ;
unsigned int V_65 = V_43 ;
const char * V_7 , * V_8 ;
const void * V_91 ;
struct V_44 * V_49 , * * V_92 ;
unsigned int * V_93 , V_94 , V_95 ;
const struct V_74 * V_75 ;
struct V_40 V_96 ;
unsigned int V_97 ;
V_7 = V_86 -> V_71 ? V_86 -> V_71 -> V_60 : V_88 ;
V_8 = V_86 -> V_72 ? V_86 -> V_72 -> V_60 : V_88 ;
V_96 . V_13 = false ;
V_96 . V_71 = V_86 -> V_71 ;
V_96 . V_72 = V_86 -> V_72 ;
V_96 . V_98 = V_99 ;
V_96 . V_100 = V_69 ;
F_25 ( V_87 -> V_101 & ( 1 << V_69 ) ) ;
F_26 () ;
V_97 = F_27 () ;
V_75 = V_87 -> V_75 ;
F_28 () ;
V_95 = F_29 () ;
V_91 = V_75 -> V_79 ;
V_92 = (struct V_44 * * ) V_75 -> V_92 [ V_95 ] ;
V_93 = F_30 ( V_75 -> V_93 , V_95 ) ;
V_94 = * V_93 ;
V_49 = F_14 ( V_91 , V_75 -> V_80 [ V_69 ] ) ;
do {
const struct V_48 * V_56 ;
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
F_25 ( V_49 ) ;
V_96 . V_106 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_49 -> V_16 ,
& V_96 . V_106 , & V_96 . V_12 , & V_96 . V_13 ) ) {
V_107:
V_49 = F_31 ( V_49 ) ;
continue;
}
F_32 (ematch, e) {
V_96 . V_108 = V_103 -> V_58 . V_59 . V_108 ;
V_96 . V_109 = V_103 -> V_62 ;
if ( ! V_96 . V_108 -> V_108 ( V_6 , & V_96 ) )
goto V_107;
}
V_105 = F_33 ( & V_49 -> V_110 ) ;
F_34 ( * V_105 , V_6 -> V_111 , 1 ) ;
V_56 = F_16 ( V_49 ) ;
F_25 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_35 ( V_112 )
if ( F_36 ( V_6 -> V_113 ) )
F_19 ( V_6 , V_69 , V_86 -> V_71 , V_86 -> V_72 ,
V_87 -> V_60 , V_75 , V_49 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_114 ;
V_114 = ( (struct V_55 * ) V_56 ) -> V_65 ;
if ( V_114 < 0 ) {
if ( V_114 != V_115 ) {
V_65 = ( unsigned int ) ( - V_114 ) - 1 ;
break;
}
if ( * V_93 <= V_94 )
V_49 = F_14 ( V_91 ,
V_75 -> V_116 [ V_69 ] ) ;
else
V_49 = F_31 ( V_92 [ -- * V_93 ] ) ;
continue;
}
if ( V_91 + V_114 != F_31 ( V_49 ) &&
! ( V_49 -> V_16 . V_32 & V_117 ) ) {
if ( * V_93 >= V_75 -> V_118 ) {
V_65 = V_43 ;
break;
}
V_92 [ ( * V_93 ) ++ ] = V_49 ;
}
V_49 = F_14 ( V_91 , V_114 ) ;
continue;
}
V_96 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_96 . V_42 = V_56 -> V_62 ;
V_65 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_6 , & V_96 ) ;
if ( V_65 == V_119 )
V_49 = F_31 ( V_49 ) ;
else
break;
} while ( ! V_96 . V_13 );
* V_93 = V_94 ;
F_37 ( V_97 ) ;
F_38 () ;
#ifdef F_39
return V_120 ;
#else
if ( V_96 . V_13 )
return V_43 ;
else return V_65 ;
#endif
}
static int
F_40 ( const struct V_74 * V_121 ,
unsigned int V_101 , void * V_122 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_123 ; V_69 ++ ) {
unsigned int V_124 = V_121 -> V_80 [ V_69 ] ;
struct V_44 * V_49 = (struct V_44 * ) ( V_122 + V_124 ) ;
if ( ! ( V_101 & ( 1 << V_69 ) ) )
continue;
V_49 -> V_110 . V_125 = V_124 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_16 ( V_49 ) ;
int V_126 = V_49 -> V_127 & ( 1 << V_69 ) ;
if ( V_49 -> V_127 & ( 1 << V_123 ) ) {
F_41 ( L_12 ,
V_69 , V_124 , V_49 -> V_127 ) ;
return 0 ;
}
V_49 -> V_127 |= ( ( 1 << V_69 ) | ( 1 << V_123 ) ) ;
if ( ( V_49 -> V_63 == sizeof( struct V_44 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_128 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < 0 &&
F_15 ( & V_49 -> V_16 ) ) || V_126 ) {
unsigned int V_129 , V_130 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_128 . V_60 ,
V_64 ) == 0 ) &&
V_56 -> V_65 < - V_131 - 1 ) {
F_11 ( L_13
L_14 ,
V_56 -> V_65 ) ;
return 0 ;
}
do {
V_49 -> V_127 ^= ( 1 << V_123 ) ;
#ifdef F_42
if ( V_49 -> V_127
& ( 1 << V_123 ) ) {
F_11 ( L_15
L_16
L_17 ,
V_69 , V_124 ) ;
}
#endif
V_129 = V_124 ;
V_124 = V_49 -> V_110 . V_125 ;
V_49 -> V_110 . V_125 = 0 ;
if ( V_124 == V_129 )
goto V_132;
V_49 = (struct V_44 * )
( V_122 + V_124 ) ;
} while ( V_129 == V_124 + V_49 -> V_133 );
V_130 = V_49 -> V_133 ;
V_49 = (struct V_44 * )
( V_122 + V_124 + V_130 ) ;
V_49 -> V_110 . V_125 = V_124 ;
V_124 += V_130 ;
} else {
int V_134 = V_56 -> V_65 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_128 . V_60 ,
V_64 ) == 0 &&
V_134 >= 0 ) {
if ( V_134 > V_121 -> V_130 -
sizeof( struct V_44 ) ) {
F_11 ( L_18
L_19 ,
V_134 ) ;
return 0 ;
}
F_11 ( L_20 ,
V_124 , V_134 ) ;
} else {
V_134 = V_124 + V_49 -> V_133 ;
}
V_49 = (struct V_44 * )
( V_122 + V_134 ) ;
V_49 -> V_110 . V_125 = V_124 ;
V_124 = V_134 ;
}
}
V_132:
F_11 ( L_21 , V_69 ) ;
}
return 1 ;
}
static void F_43 ( struct V_102 * V_135 , struct V_78 * V_78 )
{
struct V_136 V_41 ;
V_41 . V_78 = V_78 ;
V_41 . V_108 = V_135 -> V_58 . V_59 . V_108 ;
V_41 . V_109 = V_135 -> V_62 ;
V_41 . V_98 = V_99 ;
if ( V_41 . V_108 -> V_137 != NULL )
V_41 . V_108 -> V_137 ( & V_41 ) ;
F_44 ( V_41 . V_108 -> V_138 ) ;
}
static int
F_45 ( const struct V_44 * V_49 , const char * V_60 )
{
const struct V_48 * V_56 ;
if ( ! F_10 ( & V_49 -> V_16 ) ) {
F_11 ( L_22 , V_49 , V_60 ) ;
return - V_139 ;
}
if ( V_49 -> V_63 + sizeof( struct V_48 ) >
V_49 -> V_133 )
return - V_139 ;
V_56 = F_16 ( V_49 ) ;
if ( V_49 -> V_63 + V_56 -> V_58 . V_140 > V_49 -> V_133 )
return - V_139 ;
return 0 ;
}
static int F_46 ( struct V_102 * V_135 , struct V_141 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_142 ;
int V_14 ;
V_41 -> V_108 = V_135 -> V_58 . V_59 . V_108 ;
V_41 -> V_109 = V_135 -> V_62 ;
V_14 = F_47 ( V_41 , V_135 -> V_58 . V_143 - sizeof( * V_135 ) ,
V_16 -> V_37 , V_16 -> V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_41 . V_108 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_48 ( struct V_102 * V_135 , struct V_141 * V_41 )
{
struct V_144 * V_108 ;
int V_14 ;
V_108 = F_49 ( V_99 , V_135 -> V_58 . V_128 . V_60 ,
V_135 -> V_58 . V_128 . V_145 ) ;
if ( F_50 ( V_108 ) ) {
F_11 ( L_24 , V_135 -> V_58 . V_128 . V_60 ) ;
return F_51 ( V_108 ) ;
}
V_135 -> V_58 . V_59 . V_108 = V_108 ;
V_14 = F_46 ( V_135 , V_41 ) ;
if ( V_14 )
goto V_146;
return 0 ;
V_146:
F_44 ( V_135 -> V_58 . V_59 . V_108 -> V_138 ) ;
return V_14 ;
}
static int F_52 ( struct V_44 * V_49 , struct V_78 * V_78 , const char * V_60 )
{
struct V_48 * V_56 = F_17 ( V_49 ) ;
struct V_147 V_41 = {
. V_78 = V_78 ,
. V_87 = V_60 ,
. V_142 = V_49 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_42 = V_56 -> V_62 ,
. V_148 = V_49 -> V_127 ,
. V_98 = V_99 ,
} ;
int V_14 ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_53 ( & V_41 , V_56 -> V_58 . V_140 - sizeof( * V_56 ) ,
V_49 -> V_16 . V_37 , V_49 -> V_16 . V_28 & V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( L_23 ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_54 ( struct V_44 * V_49 , struct V_78 * V_78 , const char * V_60 ,
unsigned int V_130 )
{
struct V_48 * V_56 ;
struct V_149 * V_57 ;
int V_14 ;
unsigned int V_150 ;
struct V_141 V_151 ;
struct V_102 * V_103 ;
V_14 = F_45 ( V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_49 -> V_110 . V_125 = F_55 () ;
if ( F_56 ( V_49 -> V_110 . V_125 ) )
return - V_152 ;
V_150 = 0 ;
V_151 . V_78 = V_78 ;
V_151 . V_87 = V_60 ;
V_151 . V_142 = & V_49 -> V_16 ;
V_151 . V_148 = V_49 -> V_127 ;
V_151 . V_98 = V_99 ;
F_32 (ematch, e) {
V_14 = F_48 ( V_103 , & V_151 ) ;
if ( V_14 != 0 )
goto V_153;
++ V_150 ;
}
V_56 = F_17 ( V_49 ) ;
V_57 = F_57 ( V_99 , V_56 -> V_58 . V_128 . V_60 ,
V_56 -> V_58 . V_128 . V_145 ) ;
if ( F_50 ( V_57 ) ) {
F_11 ( L_25 , V_56 -> V_58 . V_128 . V_60 ) ;
V_14 = F_51 ( V_57 ) ;
goto V_153;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_14 = F_52 ( V_49 , V_78 , V_60 ) ;
if ( V_14 )
goto V_146;
return 0 ;
V_146:
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_138 ) ;
V_153:
F_32 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_43 ( V_103 , V_78 ) ;
}
F_58 ( V_49 -> V_110 . V_125 ) ;
return V_14 ;
}
static bool F_59 ( const struct V_44 * V_49 )
{
const struct V_48 * V_56 ;
unsigned int V_65 ;
if ( ! F_15 ( & V_49 -> V_16 ) )
return false ;
V_56 = F_16 ( V_49 ) ;
if ( strcmp ( V_56 -> V_58 . V_128 . V_60 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_55 * ) V_56 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_120 ;
}
static int
F_60 ( struct V_44 * V_49 ,
struct V_74 * V_121 ,
const unsigned char * V_45 ,
const unsigned char * V_154 ,
const unsigned int * V_155 ,
const unsigned int * V_156 ,
unsigned int V_101 )
{
unsigned int V_157 ;
if ( ( unsigned long ) V_49 % F_61 ( struct V_44 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_44 ) >= V_154 ) {
F_11 ( L_26 , V_49 ) ;
return - V_139 ;
}
if ( V_49 -> V_133
< sizeof( struct V_44 ) + sizeof( struct V_48 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_133 ) ;
return - V_139 ;
}
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ! ( V_101 & ( 1 << V_157 ) ) )
continue;
if ( ( unsigned char * ) V_49 - V_45 == V_155 [ V_157 ] )
V_121 -> V_80 [ V_157 ] = V_155 [ V_157 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_156 [ V_157 ] ) {
if ( ! F_59 ( V_49 ) ) {
F_41 ( L_28
L_29
L_30 ) ;
return - V_139 ;
}
V_121 -> V_116 [ V_157 ] = V_156 [ V_157 ] ;
}
}
V_49 -> V_110 = ( (struct V_104 ) { 0 , 0 } ) ;
V_49 -> V_127 = 0 ;
return 0 ;
}
static void F_62 ( struct V_44 * V_49 , struct V_78 * V_78 )
{
struct V_158 V_41 ;
struct V_48 * V_56 ;
struct V_102 * V_103 ;
F_32 (ematch, e)
F_43 ( V_103 , V_78 ) ;
V_56 = F_17 ( V_49 ) ;
V_41 . V_78 = V_78 ;
V_41 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_41 . V_42 = V_56 -> V_62 ;
V_41 . V_98 = V_99 ;
if ( V_41 . V_57 -> V_137 != NULL )
V_41 . V_57 -> V_137 ( & V_41 ) ;
F_44 ( V_41 . V_57 -> V_138 ) ;
F_58 ( V_49 -> V_110 . V_125 ) ;
}
static int
F_63 ( struct V_78 * V_78 , struct V_74 * V_121 , void * V_122 ,
const struct V_159 * V_160 )
{
struct V_44 * V_77 ;
unsigned int V_161 ;
int V_14 = 0 ;
V_121 -> V_130 = V_160 -> V_130 ;
V_121 -> V_162 = V_160 -> V_163 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_121 -> V_80 [ V_161 ] = 0xFFFFFFFF ;
V_121 -> V_116 [ V_161 ] = 0xFFFFFFFF ;
}
F_11 ( L_31 , V_121 -> V_130 ) ;
V_161 = 0 ;
F_21 (iter, entry0, newinfo->size) {
V_14 = F_60 ( V_77 , V_121 , V_122 ,
V_122 + V_160 -> V_130 ,
V_160 -> V_80 ,
V_160 -> V_116 ,
V_160 -> V_101 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_161 ;
if ( strcmp ( F_17 ( V_77 ) -> V_58 . V_128 . V_60 ,
V_61 ) == 0 )
++ V_121 -> V_118 ;
}
if ( V_161 != V_160 -> V_163 ) {
F_11 ( L_32 ,
V_161 , V_160 -> V_163 ) ;
return - V_139 ;
}
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ! ( V_160 -> V_101 & ( 1 << V_161 ) ) )
continue;
if ( V_121 -> V_80 [ V_161 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_161 , V_160 -> V_80 [ V_161 ] ) ;
return - V_139 ;
}
if ( V_121 -> V_116 [ V_161 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_161 , V_160 -> V_116 [ V_161 ] ) ;
return - V_139 ;
}
}
if ( ! F_40 ( V_121 , V_160 -> V_101 , V_122 ) )
return - V_164 ;
V_161 = 0 ;
F_21 (iter, entry0, newinfo->size) {
V_14 = F_54 ( V_77 , V_78 , V_160 -> V_60 , V_160 -> V_130 ) ;
if ( V_14 != 0 )
break;
++ V_161 ;
}
if ( V_14 != 0 ) {
F_21 (iter, entry0, newinfo->size) {
if ( V_161 -- == 0 )
break;
F_62 ( V_77 , V_78 ) ;
}
return V_14 ;
}
return V_14 ;
}
static void
F_64 ( const struct V_74 * V_56 ,
struct V_104 V_110 [] )
{
struct V_44 * V_77 ;
unsigned int V_95 ;
unsigned int V_161 ;
F_65 (cpu) {
T_2 * V_50 = & F_66 ( V_165 , V_95 ) ;
V_161 = 0 ;
F_21 (iter, t->entries, t->size) {
struct V_104 * V_166 ;
T_3 V_167 , V_125 ;
unsigned int V_168 ;
V_166 = F_67 ( & V_77 -> V_110 , V_95 ) ;
do {
V_168 = F_68 ( V_50 ) ;
V_167 = V_166 -> V_167 ;
V_125 = V_166 -> V_125 ;
} while ( F_69 ( V_50 , V_168 ) );
F_34 ( V_110 [ V_161 ] , V_167 , V_125 ) ;
++ V_161 ;
}
}
}
static struct V_104 * F_70 ( const struct V_1 * V_87 )
{
unsigned int V_169 ;
struct V_104 * V_110 ;
const struct V_74 * V_75 = V_87 -> V_75 ;
V_169 = sizeof( struct V_104 ) * V_75 -> V_162 ;
V_110 = F_71 ( V_169 ) ;
if ( V_110 == NULL )
return F_72 ( - V_152 ) ;
F_64 ( V_75 , V_110 ) ;
return V_110 ;
}
static int
F_73 ( unsigned int V_170 ,
const struct V_1 * V_87 ,
void T_4 * V_171 )
{
unsigned int V_172 , V_173 ;
const struct V_44 * V_49 ;
struct V_104 * V_110 ;
const struct V_74 * V_75 = V_87 -> V_75 ;
int V_14 = 0 ;
const void * V_174 ;
V_110 = F_70 ( V_87 ) ;
if ( F_50 ( V_110 ) )
return F_51 ( V_110 ) ;
V_174 = V_75 -> V_79 ;
if ( F_74 ( V_171 , V_174 , V_170 ) != 0 ) {
V_14 = - V_175 ;
goto V_176;
}
for ( V_172 = 0 , V_173 = 0 ; V_172 < V_170 ; V_172 += V_49 -> V_133 , V_173 ++ ) {
unsigned int V_161 ;
const struct V_102 * V_135 ;
const struct V_48 * V_56 ;
V_49 = (struct V_44 * ) ( V_174 + V_172 ) ;
if ( F_74 ( V_171 + V_172
+ F_75 ( struct V_44 , V_110 ) ,
& V_110 [ V_173 ] ,
sizeof( V_110 [ V_173 ] ) ) != 0 ) {
V_14 = - V_175 ;
goto V_176;
}
for ( V_161 = sizeof( struct V_44 ) ;
V_161 < V_49 -> V_63 ;
V_161 += V_135 -> V_58 . V_143 ) {
V_135 = ( void * ) V_49 + V_161 ;
if ( F_74 ( V_171 + V_172 + V_161
+ F_75 ( struct V_102 ,
V_58 . V_128 . V_60 ) ,
V_135 -> V_58 . V_59 . V_108 -> V_60 ,
strlen ( V_135 -> V_58 . V_59 . V_108 -> V_60 ) + 1 )
!= 0 ) {
V_14 = - V_175 ;
goto V_176;
}
}
V_56 = F_16 ( V_49 ) ;
if ( F_74 ( V_171 + V_172 + V_49 -> V_63
+ F_75 ( struct V_48 ,
V_58 . V_128 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_14 = - V_175 ;
goto V_176;
}
}
V_176:
F_76 ( V_110 ) ;
return V_14 ;
}
static void F_77 ( void * V_23 , const void * V_19 )
{
int V_114 = * ( V_177 * ) V_19 ;
if ( V_114 > 0 )
V_114 += F_78 ( V_83 , V_114 ) ;
memcpy ( V_23 , & V_114 , sizeof( V_114 ) ) ;
}
static int F_79 ( void T_4 * V_23 , const void * V_19 )
{
V_177 V_178 = * ( int * ) V_19 ;
if ( V_178 > 0 )
V_178 -= F_78 ( V_83 , V_178 ) ;
return F_74 ( V_23 , & V_178 , sizeof( V_178 ) ) ? - V_175 : 0 ;
}
static int F_80 ( const struct V_44 * V_49 ,
const struct V_74 * V_2 ,
const void * V_45 , struct V_74 * V_121 )
{
const struct V_102 * V_103 ;
const struct V_48 * V_56 ;
unsigned int V_179 ;
int V_172 , V_161 , V_14 ;
V_172 = sizeof( struct V_44 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_49 - V_45 ;
F_32 (ematch, e)
V_172 += F_81 ( V_103 -> V_58 . V_59 . V_108 ) ;
V_56 = F_16 ( V_49 ) ;
V_172 += F_82 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_121 -> V_130 -= V_172 ;
V_14 = F_83 ( V_83 , V_179 , V_172 ) ;
if ( V_14 )
return V_14 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( V_2 -> V_80 [ V_161 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_161 ] ) ) )
V_121 -> V_80 [ V_161 ] -= V_172 ;
if ( V_2 -> V_116 [ V_161 ] &&
( V_49 < (struct V_44 * ) ( V_45 + V_2 -> V_116 [ V_161 ] ) ) )
V_121 -> V_116 [ V_161 ] -= V_172 ;
}
return 0 ;
}
static int F_84 ( const struct V_74 * V_2 ,
struct V_74 * V_121 )
{
struct V_44 * V_77 ;
const void * V_174 ;
int V_14 ;
if ( ! V_121 || ! V_2 )
return - V_139 ;
memcpy ( V_121 , V_2 , F_75 ( struct V_74 , V_79 ) ) ;
V_121 -> V_181 = 0 ;
V_174 = V_2 -> V_79 ;
F_85 ( V_83 , V_2 -> V_162 ) ;
F_21 (iter, loc_cpu_entry, info->size) {
V_14 = F_80 ( V_77 , V_2 , V_174 , V_121 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_86 ( struct V_78 * V_78 , void T_4 * V_128 ,
const int * V_111 , int V_182 )
{
char V_60 [ V_183 ] ;
struct V_1 * V_56 ;
int V_14 ;
if ( * V_111 != sizeof( struct V_184 ) ) {
F_11 ( L_35 , * V_111 ,
sizeof( struct V_184 ) ) ;
return - V_139 ;
}
if ( F_87 ( V_60 , V_128 , sizeof( V_60 ) ) != 0 )
return - V_175 ;
V_60 [ V_183 - 1 ] = '\0' ;
#ifdef F_88
if ( V_182 )
F_89 ( V_83 ) ;
#endif
V_56 = F_90 ( F_91 ( V_78 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
struct V_184 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_88
struct V_74 V_166 ;
if ( V_182 ) {
V_14 = F_84 ( V_75 , & V_166 ) ;
F_93 ( V_83 ) ;
V_75 = & V_166 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_101 = V_56 -> V_101 ;
memcpy ( V_2 . V_80 , V_75 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_116 , V_75 -> V_116 ,
sizeof( V_2 . V_116 ) ) ;
V_2 . V_163 = V_75 -> V_162 ;
V_2 . V_130 = V_75 -> V_130 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_74 ( V_128 , & V_2 , * V_111 ) != 0 )
V_14 = - V_175 ;
else
V_14 = 0 ;
F_94 ( V_56 ) ;
F_44 ( V_56 -> V_138 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_185 ;
#ifdef F_88
if ( V_182 )
F_95 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_96 ( struct V_78 * V_78 , struct V_186 T_4 * V_187 ,
const int * V_111 )
{
int V_14 ;
struct V_186 V_188 ;
struct V_1 * V_56 ;
if ( * V_111 < sizeof( V_188 ) ) {
F_11 ( L_37 , * V_111 , sizeof( V_188 ) ) ;
return - V_139 ;
}
if ( F_87 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_175 ;
if ( * V_111 != sizeof( struct V_186 ) + V_188 . V_130 ) {
F_11 ( L_38 ,
* V_111 , sizeof( V_188 ) + V_188 . V_130 ) ;
return - V_139 ;
}
V_56 = F_91 ( V_78 , V_83 , V_188 . V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
struct V_74 * V_75 = V_56 -> V_75 ;
F_11 ( L_39 , V_75 -> V_162 ) ;
if ( V_188 . V_130 == V_75 -> V_130 )
V_14 = F_73 ( V_75 -> V_130 ,
V_56 , V_187 -> V_189 ) ;
else {
F_11 ( L_40 ,
V_75 -> V_130 , V_188 . V_130 ) ;
V_14 = - V_190 ;
}
F_44 ( V_56 -> V_138 ) ;
F_94 ( V_56 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_185 ;
return V_14 ;
}
static int
F_97 ( struct V_78 * V_78 , const char * V_60 , unsigned int V_101 ,
struct V_74 * V_121 , unsigned int V_191 ,
void T_4 * V_192 )
{
int V_14 ;
struct V_1 * V_56 ;
struct V_74 * V_193 ;
struct V_104 * V_110 ;
struct V_44 * V_77 ;
V_14 = 0 ;
V_110 = F_71 ( V_191 * sizeof( struct V_104 ) ) ;
if ( ! V_110 ) {
V_14 = - V_152 ;
goto V_72;
}
V_56 = F_90 ( F_91 ( V_78 , V_83 , V_60 ) ,
L_36 , V_60 ) ;
if ( F_92 ( V_56 ) ) {
V_14 = V_56 ? F_51 ( V_56 ) : - V_185 ;
goto V_194;
}
if ( V_101 != V_56 -> V_101 ) {
F_11 ( L_41 ,
V_101 , V_56 -> V_101 ) ;
V_14 = - V_139 ;
goto V_195;
}
V_193 = F_98 ( V_56 , V_191 , V_121 , & V_14 ) ;
if ( ! V_193 )
goto V_195;
F_11 ( L_42 ,
V_193 -> V_162 , V_193 -> V_181 , V_121 -> V_162 ) ;
if ( ( V_193 -> V_162 > V_193 -> V_181 ) ||
( V_121 -> V_162 <= V_193 -> V_181 ) )
F_44 ( V_56 -> V_138 ) ;
if ( ( V_193 -> V_162 > V_193 -> V_181 ) &&
( V_121 -> V_162 <= V_193 -> V_181 ) )
F_44 ( V_56 -> V_138 ) ;
F_64 ( V_193 , V_110 ) ;
F_21 (iter, oldinfo->entries, oldinfo->size)
F_62 ( V_77 , V_78 ) ;
F_99 ( V_193 ) ;
if ( F_74 ( V_192 , V_110 ,
sizeof( struct V_104 ) * V_191 ) != 0 ) {
F_100 ( L_43 ) ;
}
F_76 ( V_110 ) ;
F_94 ( V_56 ) ;
return V_14 ;
V_195:
F_44 ( V_56 -> V_138 ) ;
F_94 ( V_56 ) ;
V_194:
F_76 ( V_110 ) ;
V_72:
return V_14 ;
}
static int
F_101 ( struct V_78 * V_78 , const void T_4 * V_128 , unsigned int V_111 )
{
int V_14 ;
struct V_159 V_166 ;
struct V_74 * V_121 ;
void * V_174 ;
struct V_44 * V_77 ;
if ( F_87 ( & V_166 , V_128 , sizeof( V_166 ) ) != 0 )
return - V_175 ;
if ( V_166 . V_191 >= V_196 / sizeof( struct V_104 ) )
return - V_152 ;
if ( V_166 . V_191 == 0 )
return - V_139 ;
V_166 . V_60 [ sizeof( V_166 . V_60 ) - 1 ] = 0 ;
V_121 = F_102 ( V_166 . V_130 ) ;
if ( ! V_121 )
return - V_152 ;
V_174 = V_121 -> V_79 ;
if ( F_87 ( V_174 , V_128 + sizeof( V_166 ) ,
V_166 . V_130 ) != 0 ) {
V_14 = - V_175 ;
goto V_197;
}
V_14 = F_63 ( V_78 , V_121 , V_174 , & V_166 ) ;
if ( V_14 != 0 )
goto V_197;
F_11 ( L_44 ) ;
V_14 = F_97 ( V_78 , V_166 . V_60 , V_166 . V_101 , V_121 ,
V_166 . V_191 , V_166 . V_110 ) ;
if ( V_14 )
goto V_198;
return 0 ;
V_198:
F_21 (iter, loc_cpu_entry, newinfo->size)
F_62 ( V_77 , V_78 ) ;
V_197:
F_99 ( V_121 ) ;
return V_14 ;
}
static int
F_103 ( struct V_78 * V_78 , const void T_4 * V_128 , unsigned int V_111 ,
int V_182 )
{
unsigned int V_161 ;
struct V_199 V_166 ;
struct V_104 * V_200 ;
unsigned int V_191 ;
char * V_60 ;
int V_130 ;
void * V_201 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_14 = 0 ;
struct V_44 * V_77 ;
unsigned int V_97 ;
#ifdef F_88
struct V_202 V_203 ;
if ( V_182 ) {
V_201 = & V_203 ;
V_130 = sizeof( struct V_202 ) ;
} else
#endif
{
V_201 = & V_166 ;
V_130 = sizeof( struct V_199 ) ;
}
if ( F_87 ( V_201 , V_128 , V_130 ) != 0 )
return - V_175 ;
#ifdef F_88
if ( V_182 ) {
V_191 = V_203 . V_191 ;
V_60 = V_203 . V_60 ;
} else
#endif
{
V_191 = V_166 . V_191 ;
V_60 = V_166 . V_60 ;
}
if ( V_111 != V_130 + V_191 * sizeof( struct V_104 ) )
return - V_139 ;
V_200 = F_104 ( V_111 - V_130 ) ;
if ( ! V_200 )
return - V_152 ;
if ( F_87 ( V_200 , V_128 + V_130 , V_111 - V_130 ) != 0 ) {
V_14 = - V_175 ;
goto free;
}
V_56 = F_91 ( V_78 , V_83 , V_60 ) ;
if ( F_92 ( V_56 ) ) {
V_14 = V_56 ? F_51 ( V_56 ) : - V_185 ;
goto free;
}
F_26 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_162 != V_191 ) {
V_14 = - V_139 ;
goto V_204;
}
V_161 = 0 ;
V_97 = F_27 () ;
F_21 (iter, private->entries, private->size) {
struct V_104 * V_166 ;
V_166 = F_33 ( & V_77 -> V_110 ) ;
F_34 ( * V_166 , V_200 [ V_161 ] . V_167 , V_200 [ V_161 ] . V_125 ) ;
++ V_161 ;
}
F_37 ( V_97 ) ;
V_204:
F_38 () ;
F_94 ( V_56 ) ;
F_44 ( V_56 -> V_138 ) ;
free:
F_76 ( V_200 ) ;
return V_14 ;
}
static int
F_105 ( struct V_44 * V_49 , void T_4 * * V_205 ,
unsigned int * V_130 , struct V_104 * V_110 ,
unsigned int V_161 )
{
struct V_48 * V_56 ;
struct V_180 T_4 * V_206 ;
T_5 V_63 , V_133 ;
T_6 V_207 ;
const struct V_102 * V_103 ;
int V_14 = 0 ;
V_207 = * V_130 ;
V_206 = (struct V_180 T_4 * ) * V_205 ;
if ( F_74 ( V_206 , V_49 , sizeof( struct V_44 ) ) != 0 ||
F_74 ( & V_206 -> V_110 , & V_110 [ V_161 ] ,
sizeof( V_110 [ V_161 ] ) ) != 0 )
return - V_175 ;
* V_205 += sizeof( struct V_180 ) ;
* V_130 -= sizeof( struct V_44 ) - sizeof( struct V_180 ) ;
F_32 (ematch, e) {
V_14 = F_106 ( V_103 , V_205 , V_130 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_63 = V_49 -> V_63 - ( V_207 - * V_130 ) ;
V_56 = F_17 ( V_49 ) ;
V_14 = F_107 ( V_56 , V_205 , V_130 ) ;
if ( V_14 )
return V_14 ;
V_133 = V_49 -> V_133 - ( V_207 - * V_130 ) ;
if ( F_108 ( V_63 , & V_206 -> V_63 ) != 0 ||
F_108 ( V_133 , & V_206 -> V_133 ) != 0 )
return - V_175 ;
return 0 ;
}
static int
F_109 ( struct V_102 * V_135 ,
const char * V_60 ,
const struct V_9 * V_16 ,
int * V_130 )
{
struct V_144 * V_108 ;
V_108 = F_49 ( V_99 , V_135 -> V_58 . V_128 . V_60 ,
V_135 -> V_58 . V_128 . V_145 ) ;
if ( F_50 ( V_108 ) ) {
F_11 ( L_45 ,
V_135 -> V_58 . V_128 . V_60 ) ;
return F_51 ( V_108 ) ;
}
V_135 -> V_58 . V_59 . V_108 = V_108 ;
* V_130 += F_81 ( V_108 ) ;
return 0 ;
}
static void F_110 ( struct V_180 * V_49 )
{
struct V_48 * V_56 ;
struct V_102 * V_103 ;
F_32 (ematch, e)
F_44 ( V_103 -> V_58 . V_59 . V_108 -> V_138 ) ;
V_56 = F_111 ( V_49 ) ;
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_138 ) ;
}
static int
F_112 ( struct V_180 * V_49 ,
struct V_74 * V_121 ,
unsigned int * V_130 ,
const unsigned char * V_45 ,
const unsigned char * V_154 ,
const unsigned int * V_155 ,
const unsigned int * V_156 ,
const char * V_60 )
{
struct V_102 * V_103 ;
struct V_48 * V_56 ;
struct V_149 * V_57 ;
unsigned int V_179 ;
unsigned int V_150 ;
int V_14 , V_172 , V_157 ;
F_11 ( L_46 , V_49 ) ;
if ( ( unsigned long ) V_49 % F_61 ( struct V_180 ) != 0 ||
( unsigned char * ) V_49 + sizeof( struct V_180 ) >= V_154 ) {
F_11 ( L_47 , V_49 , V_154 ) ;
return - V_139 ;
}
if ( V_49 -> V_133 < sizeof( struct V_180 ) +
sizeof( struct V_208 ) ) {
F_11 ( L_27 ,
V_49 , V_49 -> V_133 ) ;
return - V_139 ;
}
V_14 = F_45 ( (struct V_44 * ) V_49 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_172 = sizeof( struct V_44 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_49 - ( void * ) V_45 ;
V_150 = 0 ;
F_32 (ematch, e) {
V_14 = F_109 ( V_103 , V_60 , & V_49 -> V_16 , & V_172 ) ;
if ( V_14 != 0 )
goto V_209;
++ V_150 ;
}
V_56 = F_111 ( V_49 ) ;
V_57 = F_57 ( V_99 , V_56 -> V_58 . V_128 . V_60 ,
V_56 -> V_58 . V_128 . V_145 ) ;
if ( F_50 ( V_57 ) ) {
F_11 ( L_48 ,
V_56 -> V_58 . V_128 . V_60 ) ;
V_14 = F_51 ( V_57 ) ;
goto V_209;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_172 += F_82 ( V_57 ) ;
* V_130 += V_172 ;
V_14 = F_83 ( V_83 , V_179 , V_172 ) ;
if ( V_14 )
goto V_72;
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ( unsigned char * ) V_49 - V_45 == V_155 [ V_157 ] )
V_121 -> V_80 [ V_157 ] = V_155 [ V_157 ] ;
if ( ( unsigned char * ) V_49 - V_45 == V_156 [ V_157 ] )
V_121 -> V_116 [ V_157 ] = V_156 [ V_157 ] ;
}
memset ( & V_49 -> V_110 , 0 , sizeof( V_49 -> V_110 ) ) ;
V_49 -> V_127 = 0 ;
return 0 ;
V_72:
F_44 ( V_56 -> V_58 . V_59 . V_57 -> V_138 ) ;
V_209:
F_32 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_44 ( V_103 -> V_58 . V_59 . V_108 -> V_138 ) ;
}
return V_14 ;
}
static int
F_113 ( struct V_180 * V_49 , void * * V_205 ,
unsigned int * V_130 , const char * V_60 ,
struct V_74 * V_121 , unsigned char * V_45 )
{
struct V_48 * V_56 ;
struct V_44 * V_210 ;
unsigned int V_207 ;
int V_14 , V_157 ;
struct V_102 * V_103 ;
V_14 = 0 ;
V_207 = * V_130 ;
V_210 = (struct V_44 * ) * V_205 ;
memcpy ( V_210 , V_49 , sizeof( struct V_44 ) ) ;
memcpy ( & V_210 -> V_110 , & V_49 -> V_110 , sizeof( V_49 -> V_110 ) ) ;
* V_205 += sizeof( struct V_44 ) ;
* V_130 += sizeof( struct V_44 ) - sizeof( struct V_180 ) ;
F_32 (ematch, e) {
V_14 = F_114 ( V_103 , V_205 , V_130 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_210 -> V_63 = V_49 -> V_63 - ( V_207 - * V_130 ) ;
V_56 = F_111 ( V_49 ) ;
F_115 ( V_56 , V_205 , V_130 ) ;
V_210 -> V_133 = V_49 -> V_133 - ( V_207 - * V_130 ) ;
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ( unsigned char * ) V_210 - V_45 < V_121 -> V_80 [ V_157 ] )
V_121 -> V_80 [ V_157 ] -= V_207 - * V_130 ;
if ( ( unsigned char * ) V_210 - V_45 < V_121 -> V_116 [ V_157 ] )
V_121 -> V_116 [ V_157 ] -= V_207 - * V_130 ;
}
return V_14 ;
}
static int F_116 ( struct V_44 * V_49 , struct V_78 * V_78 ,
const char * V_60 )
{
unsigned int V_150 ;
int V_14 = 0 ;
struct V_141 V_151 ;
struct V_102 * V_103 ;
V_49 -> V_110 . V_125 = F_55 () ;
if ( F_56 ( V_49 -> V_110 . V_125 ) )
return - V_152 ;
V_150 = 0 ;
V_151 . V_78 = V_78 ;
V_151 . V_87 = V_60 ;
V_151 . V_142 = & V_49 -> V_16 ;
V_151 . V_148 = V_49 -> V_127 ;
V_151 . V_98 = V_99 ;
F_32 (ematch, e) {
V_14 = F_46 ( V_103 , & V_151 ) ;
if ( V_14 != 0 )
goto V_153;
++ V_150 ;
}
V_14 = F_52 ( V_49 , V_78 , V_60 ) ;
if ( V_14 )
goto V_153;
return 0 ;
V_153:
F_32 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_43 ( V_103 , V_78 ) ;
}
F_58 ( V_49 -> V_110 . V_125 ) ;
return V_14 ;
}
static int
F_117 ( struct V_78 * V_78 ,
const char * V_60 ,
unsigned int V_101 ,
struct V_74 * * V_211 ,
void * * V_212 ,
unsigned int V_170 ,
unsigned int V_162 ,
unsigned int * V_155 ,
unsigned int * V_156 )
{
unsigned int V_161 , V_150 ;
struct V_74 * V_121 , * V_2 ;
void * V_124 , * V_122 , * V_213 ;
struct V_180 * V_214 ;
struct V_44 * V_215 ;
unsigned int V_130 ;
int V_14 = 0 ;
V_2 = * V_211 ;
V_122 = * V_212 ;
V_130 = V_170 ;
V_2 -> V_162 = V_162 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_2 -> V_80 [ V_161 ] = 0xFFFFFFFF ;
V_2 -> V_116 [ V_161 ] = 0xFFFFFFFF ;
}
F_11 ( L_49 , V_2 -> V_130 ) ;
V_150 = 0 ;
F_89 ( V_83 ) ;
F_85 ( V_83 , V_162 ) ;
F_21 (iter0, entry0, total_size) {
V_14 = F_112 ( V_214 , V_2 , & V_130 ,
V_122 ,
V_122 + V_170 ,
V_155 ,
V_156 ,
V_60 ) ;
if ( V_14 != 0 )
goto V_216;
++ V_150 ;
}
V_14 = - V_139 ;
if ( V_150 != V_162 ) {
F_11 ( L_50 ,
V_150 , V_162 ) ;
goto V_216;
}
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ! ( V_101 & ( 1 << V_161 ) ) )
continue;
if ( V_2 -> V_80 [ V_161 ] == 0xFFFFFFFF ) {
F_11 ( L_33 ,
V_161 , V_155 [ V_161 ] ) ;
goto V_216;
}
if ( V_2 -> V_116 [ V_161 ] == 0xFFFFFFFF ) {
F_11 ( L_34 ,
V_161 , V_156 [ V_161 ] ) ;
goto V_216;
}
}
V_14 = - V_152 ;
V_121 = F_102 ( V_130 ) ;
if ( ! V_121 )
goto V_216;
V_121 -> V_162 = V_162 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_121 -> V_80 [ V_161 ] = V_2 -> V_80 [ V_161 ] ;
V_121 -> V_116 [ V_161 ] = V_2 -> V_116 [ V_161 ] ;
}
V_213 = V_121 -> V_79 ;
V_124 = V_213 ;
V_130 = V_170 ;
F_21 (iter0, entry0, total_size) {
V_14 = F_113 ( V_214 , & V_124 , & V_130 ,
V_60 , V_121 , V_213 ) ;
if ( V_14 != 0 )
break;
}
F_93 ( V_83 ) ;
F_95 ( V_83 ) ;
if ( V_14 )
goto V_197;
V_14 = - V_164 ;
if ( ! F_40 ( V_121 , V_101 , V_213 ) )
goto V_197;
V_161 = 0 ;
F_21 (iter1, entry1, newinfo->size) {
V_14 = F_116 ( V_215 , V_78 , V_60 ) ;
if ( V_14 != 0 )
break;
++ V_161 ;
if ( strcmp ( F_17 ( V_215 ) -> V_58 . V_128 . V_60 ,
V_61 ) == 0 )
++ V_121 -> V_118 ;
}
if ( V_14 ) {
int V_217 = V_161 ;
V_150 -= V_161 ;
F_21 (iter0, entry0, newinfo->size) {
if ( V_217 -- > 0 )
continue;
if ( V_150 -- == 0 )
break;
F_110 ( V_214 ) ;
}
F_21 (iter1, entry1, newinfo->size) {
if ( V_161 -- == 0 )
break;
F_62 ( V_215 , V_78 ) ;
}
F_99 ( V_121 ) ;
return V_14 ;
}
* V_211 = V_121 ;
* V_212 = V_213 ;
F_99 ( V_2 ) ;
return 0 ;
V_197:
F_99 ( V_121 ) ;
V_72:
F_21 (iter0, entry0, total_size) {
if ( V_150 -- == 0 )
break;
F_110 ( V_214 ) ;
}
return V_14 ;
V_216:
F_93 ( V_83 ) ;
F_95 ( V_83 ) ;
goto V_72;
}
static int
F_118 ( struct V_78 * V_78 , void T_4 * V_128 , unsigned int V_111 )
{
int V_14 ;
struct V_218 V_166 ;
struct V_74 * V_121 ;
void * V_174 ;
struct V_44 * V_77 ;
if ( F_87 ( & V_166 , V_128 , sizeof( V_166 ) ) != 0 )
return - V_175 ;
if ( V_166 . V_130 >= V_196 / F_119 () )
return - V_152 ;
if ( V_166 . V_191 >= V_196 / sizeof( struct V_104 ) )
return - V_152 ;
if ( V_166 . V_191 == 0 )
return - V_139 ;
V_166 . V_60 [ sizeof( V_166 . V_60 ) - 1 ] = 0 ;
V_121 = F_102 ( V_166 . V_130 ) ;
if ( ! V_121 )
return - V_152 ;
V_174 = V_121 -> V_79 ;
if ( F_87 ( V_174 , V_128 + sizeof( V_166 ) ,
V_166 . V_130 ) != 0 ) {
V_14 = - V_175 ;
goto V_197;
}
V_14 = F_117 ( V_78 , V_166 . V_60 , V_166 . V_101 ,
& V_121 , & V_174 , V_166 . V_130 ,
V_166 . V_163 , V_166 . V_80 ,
V_166 . V_116 ) ;
if ( V_14 != 0 )
goto V_197;
F_11 ( L_51 ) ;
V_14 = F_97 ( V_78 , V_166 . V_60 , V_166 . V_101 , V_121 ,
V_166 . V_191 , F_120 ( V_166 . V_110 ) ) ;
if ( V_14 )
goto V_198;
return 0 ;
V_198:
F_21 (iter, loc_cpu_entry, newinfo->size)
F_62 ( V_77 , V_78 ) ;
V_197:
F_99 ( V_121 ) ;
return V_14 ;
}
static int
F_121 ( struct V_219 * V_220 , int V_221 , void T_4 * V_128 ,
unsigned int V_111 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_14 = F_118 ( F_123 ( V_220 ) , V_128 , V_111 ) ;
break;
case V_226 :
V_14 = F_103 ( F_123 ( V_220 ) , V_128 , V_111 , 1 ) ;
break;
default:
F_11 ( L_52 , V_221 ) ;
V_14 = - V_139 ;
}
return V_14 ;
}
static int
F_124 ( unsigned int V_170 , struct V_1 * V_87 ,
void T_4 * V_171 )
{
struct V_104 * V_110 ;
const struct V_74 * V_75 = V_87 -> V_75 ;
void T_4 * V_124 ;
unsigned int V_130 ;
int V_14 = 0 ;
unsigned int V_161 = 0 ;
struct V_44 * V_77 ;
V_110 = F_70 ( V_87 ) ;
if ( F_50 ( V_110 ) )
return F_51 ( V_110 ) ;
V_124 = V_171 ;
V_130 = V_170 ;
F_21 (iter, private->entries, total_size) {
V_14 = F_105 ( V_77 , & V_124 ,
& V_130 , V_110 , V_161 ++ ) ;
if ( V_14 != 0 )
break;
}
F_76 ( V_110 ) ;
return V_14 ;
}
static int
F_125 ( struct V_78 * V_78 , struct V_227 T_4 * V_187 ,
int * V_111 )
{
int V_14 ;
struct V_227 V_188 ;
struct V_1 * V_56 ;
if ( * V_111 < sizeof( V_188 ) ) {
F_11 ( L_53 , * V_111 , sizeof( V_188 ) ) ;
return - V_139 ;
}
if ( F_87 ( & V_188 , V_187 , sizeof( V_188 ) ) != 0 )
return - V_175 ;
if ( * V_111 != sizeof( struct V_227 ) + V_188 . V_130 ) {
F_11 ( L_54 ,
* V_111 , sizeof( V_188 ) + V_188 . V_130 ) ;
return - V_139 ;
}
F_89 ( V_83 ) ;
V_56 = F_91 ( V_78 , V_83 , V_188 . V_60 ) ;
if ( ! F_92 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
F_11 ( L_39 , V_75 -> V_162 ) ;
V_14 = F_84 ( V_75 , & V_2 ) ;
if ( ! V_14 && V_188 . V_130 == V_2 . V_130 ) {
V_14 = F_124 ( V_75 -> V_130 ,
V_56 , V_187 -> V_189 ) ;
} else if ( ! V_14 ) {
F_11 ( L_55 ,
V_75 -> V_130 , V_188 . V_130 ) ;
V_14 = - V_190 ;
}
F_93 ( V_83 ) ;
F_44 ( V_56 -> V_138 ) ;
F_94 ( V_56 ) ;
} else
V_14 = V_56 ? F_51 ( V_56 ) : - V_185 ;
F_95 ( V_83 ) ;
return V_14 ;
}
static int
F_126 ( struct V_219 * V_220 , int V_221 , void T_4 * V_128 , int * V_111 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_228 :
V_14 = F_86 ( F_123 ( V_220 ) , V_128 , V_111 , 1 ) ;
break;
case V_229 :
V_14 = F_125 ( F_123 ( V_220 ) , V_128 , V_111 ) ;
break;
default:
V_14 = F_127 ( V_220 , V_221 , V_128 , V_111 ) ;
}
return V_14 ;
}
static int
F_128 ( struct V_219 * V_220 , int V_221 , void T_4 * V_128 , unsigned int V_111 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_225 :
V_14 = F_101 ( F_123 ( V_220 ) , V_128 , V_111 ) ;
break;
case V_226 :
V_14 = F_103 ( F_123 ( V_220 ) , V_128 , V_111 , 0 ) ;
break;
default:
F_11 ( L_52 , V_221 ) ;
V_14 = - V_139 ;
}
return V_14 ;
}
static int
F_127 ( struct V_219 * V_220 , int V_221 , void T_4 * V_128 , int * V_111 )
{
int V_14 ;
if ( ! F_122 ( F_123 ( V_220 ) -> V_222 , V_223 ) )
return - V_224 ;
switch ( V_221 ) {
case V_228 :
V_14 = F_86 ( F_123 ( V_220 ) , V_128 , V_111 , 0 ) ;
break;
case V_229 :
V_14 = F_96 ( F_123 ( V_220 ) , V_128 , V_111 ) ;
break;
case V_230 :
case V_231 : {
struct V_232 V_233 ;
int V_57 ;
if ( * V_111 != sizeof( V_233 ) ) {
V_14 = - V_139 ;
break;
}
if ( F_87 ( & V_233 , V_128 , sizeof( V_233 ) ) != 0 ) {
V_14 = - V_175 ;
break;
}
V_233 . V_60 [ sizeof( V_233 . V_60 ) - 1 ] = 0 ;
if ( V_221 == V_231 )
V_57 = 1 ;
else
V_57 = 0 ;
F_90 ( F_129 ( V_83 , V_233 . V_60 ,
V_233 . V_145 ,
V_57 , & V_14 ) ,
L_56 , V_233 . V_60 ) ;
break;
}
default:
F_11 ( L_57 , V_221 ) ;
V_14 = - V_139 ;
}
return V_14 ;
}
struct V_1 * F_130 ( struct V_78 * V_78 ,
const struct V_1 * V_87 ,
const struct V_159 * V_160 )
{
int V_14 ;
struct V_74 * V_121 ;
struct V_74 V_234 = { 0 } ;
void * V_174 ;
struct V_1 * V_235 ;
V_121 = F_102 ( V_160 -> V_130 ) ;
if ( ! V_121 ) {
V_14 = - V_152 ;
goto V_72;
}
V_174 = V_121 -> V_79 ;
memcpy ( V_174 , V_160 -> V_79 , V_160 -> V_130 ) ;
V_14 = F_63 ( V_78 , V_121 , V_174 , V_160 ) ;
if ( V_14 != 0 )
goto V_236;
V_235 = F_131 ( V_78 , V_87 , & V_234 , V_121 ) ;
if ( F_50 ( V_235 ) ) {
V_14 = F_51 ( V_235 ) ;
goto V_236;
}
return V_235 ;
V_236:
F_99 ( V_121 ) ;
V_72:
return F_72 ( V_14 ) ;
}
void F_132 ( struct V_78 * V_78 , struct V_1 * V_87 )
{
struct V_74 * V_75 ;
void * V_174 ;
struct V_237 * V_238 = V_87 -> V_138 ;
struct V_44 * V_77 ;
V_75 = F_133 ( V_87 ) ;
V_174 = V_75 -> V_79 ;
F_21 (iter, loc_cpu_entry, private->size)
F_62 ( V_77 , V_78 ) ;
if ( V_75 -> V_162 > V_75 -> V_181 )
F_44 ( V_238 ) ;
F_99 ( V_75 ) ;
}
static inline bool
F_134 ( T_7 V_239 , T_7 V_240 , T_7 V_241 ,
T_7 type , T_7 V_242 ,
bool V_243 )
{
return ( type == V_239 && V_242 >= V_240 && V_242 <= V_241 )
^ V_243 ;
}
static bool
F_135 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_244 * V_245 ;
struct V_244 V_246 ;
const struct V_247 * V_248 = V_41 -> V_109 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_245 = F_136 ( V_6 , V_41 -> V_106 , sizeof( V_246 ) , & V_246 ) ;
if ( V_245 == NULL ) {
F_11 ( L_58 ) ;
V_41 -> V_13 = true ;
return false ;
}
return F_134 ( V_248 -> type ,
V_248 -> V_242 [ 0 ] ,
V_248 -> V_242 [ 1 ] ,
V_245 -> V_249 , V_245 -> V_250 ,
! ! ( V_248 -> V_28 & V_251 ) ) ;
}
static int F_137 ( const struct V_141 * V_41 )
{
const struct V_247 * V_248 = V_41 -> V_109 ;
return ( V_248 -> V_28 & ~ V_251 ) ? - V_139 : 0 ;
}
static int T_8 F_138 ( struct V_78 * V_78 )
{
return F_139 ( V_78 , V_99 ) ;
}
static void T_9 F_140 ( struct V_78 * V_78 )
{
F_141 ( V_78 , V_99 ) ;
}
static int T_10 F_142 ( void )
{
int V_14 ;
V_14 = F_143 ( & V_252 ) ;
if ( V_14 < 0 )
goto V_253;
V_14 = F_144 ( V_254 , F_145 ( V_254 ) ) ;
if ( V_14 < 0 )
goto V_255;
V_14 = F_146 ( V_256 , F_145 ( V_256 ) ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_147 ( & V_258 ) ;
if ( V_14 < 0 )
goto V_259;
F_148 ( L_59 ) ;
return 0 ;
V_259:
F_149 ( V_256 , F_145 ( V_256 ) ) ;
V_257:
F_150 ( V_254 , F_145 ( V_254 ) ) ;
V_255:
F_151 ( & V_252 ) ;
V_253:
return V_14 ;
}
static void T_11 F_152 ( void )
{
F_153 ( & V_258 ) ;
F_149 ( V_256 , F_145 ( V_256 ) ) ;
F_150 ( V_254 , F_145 ( V_254 ) ) ;
F_151 ( & V_252 ) ;
}
