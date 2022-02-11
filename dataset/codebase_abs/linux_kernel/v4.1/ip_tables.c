void * F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , V_4 ) ;
}
static inline bool
F_3 ( const struct V_5 * V_6 ,
const char * V_7 ,
const char * V_8 ,
const struct V_9 * V_10 ,
int V_11 )
{
unsigned long V_12 ;
#define F_4 ( bool , T_1 ) ((bool) ^ !!(ipinfo->invflags & (invflg)))
if ( F_4 ( ( V_6 -> V_13 & V_10 -> V_14 . V_15 ) != V_10 -> V_16 . V_15 ,
V_17 ) ||
F_4 ( ( V_6 -> V_18 & V_10 -> V_19 . V_15 ) != V_10 -> V_20 . V_15 ,
V_21 ) ) {
F_5 ( L_1 ) ;
F_5 ( L_2 ,
& V_6 -> V_13 , & V_10 -> V_14 . V_15 , & V_10 -> V_16 . V_15 ,
V_10 -> V_22 & V_17 ? L_3 : L_4 ) ;
F_5 ( L_5 ,
& V_6 -> V_18 , & V_10 -> V_19 . V_15 , & V_10 -> V_20 . V_15 ,
V_10 -> V_22 & V_21 ? L_3 : L_4 ) ;
return false ;
}
V_12 = F_6 ( V_7 , V_10 -> V_23 , V_10 -> V_24 ) ;
if ( F_4 ( V_12 != 0 , V_25 ) ) {
F_5 ( L_6 ,
V_7 , V_10 -> V_23 ,
V_10 -> V_22 & V_25 ? L_3 : L_4 ) ;
return false ;
}
V_12 = F_6 ( V_8 , V_10 -> V_26 , V_10 -> V_27 ) ;
if ( F_4 ( V_12 != 0 , V_28 ) ) {
F_5 ( L_7 ,
V_8 , V_10 -> V_26 ,
V_10 -> V_22 & V_28 ? L_3 : L_4 ) ;
return false ;
}
if ( V_10 -> V_29 &&
F_4 ( V_6 -> V_30 != V_10 -> V_29 , V_31 ) ) {
F_5 ( L_8 ,
V_6 -> V_30 , V_10 -> V_29 ,
V_10 -> V_22 & V_31 ? L_3 : L_4 ) ;
return false ;
}
if ( F_4 ( ( V_10 -> V_32 & V_33 ) && ! V_11 , V_34 ) ) {
F_5 ( L_9 ,
V_10 -> V_22 & V_34 ? L_3 : L_4 ) ;
return false ;
}
return true ;
}
static bool
F_7 ( const struct V_9 * V_6 )
{
if ( V_6 -> V_32 & ~ V_35 ) {
F_8 ( L_10 ,
V_6 -> V_32 & ~ V_35 ) ;
return false ;
}
if ( V_6 -> V_22 & ~ V_36 ) {
F_8 ( L_11 ,
V_6 -> V_22 & ~ V_36 ) ;
return false ;
}
return true ;
}
static unsigned int
F_9 ( struct V_37 * V_38 , const struct V_39 * V_40 )
{
F_10 ( L_12 , ( const char * ) V_40 -> V_41 ) ;
return V_42 ;
}
static inline struct V_43 *
F_11 ( const void * V_44 , unsigned int V_45 )
{
return (struct V_43 * ) ( V_44 + V_45 ) ;
}
static inline bool F_12 ( const struct V_9 * V_6 )
{
static const struct V_9 V_46 ;
return memcmp ( V_6 , & V_46 , sizeof( V_46 ) ) == 0 ;
#undef F_4
}
static inline const struct V_47 *
F_13 ( const struct V_43 * V_48 )
{
return F_14 ( (struct V_43 * ) V_48 ) ;
}
static inline int
F_15 ( const struct V_43 * V_49 , const struct V_43 * V_48 ,
const char * V_50 , const char * * V_51 ,
const char * * V_52 , unsigned int * V_53 )
{
const struct V_54 * V_55 = ( void * ) F_13 ( V_49 ) ;
if ( strcmp ( V_55 -> V_56 . V_57 . V_58 . V_56 -> V_59 , V_60 ) == 0 ) {
* V_51 = V_55 -> V_56 . V_61 ;
( * V_53 ) = 0 ;
} else if ( V_49 == V_48 ) {
( * V_53 ) ++ ;
if ( V_49 -> V_62 == sizeof( struct V_43 ) &&
strcmp ( V_55 -> V_56 . V_57 . V_58 . V_56 -> V_59 ,
V_63 ) == 0 &&
V_55 -> V_64 < 0 &&
F_12 ( & V_49 -> V_6 ) ) {
* V_52 = * V_51 == V_50
? V_65 [ V_66 ]
: V_65 [ V_67 ] ;
}
return 1 ;
} else
( * V_53 ) ++ ;
return 0 ;
}
static void F_16 ( const struct V_37 * V_38 ,
unsigned int V_68 ,
const struct V_69 * V_70 ,
const struct V_69 * V_71 ,
const char * V_72 ,
const struct V_73 * V_74 ,
const struct V_43 * V_48 )
{
const void * V_75 ;
const struct V_43 * V_76 ;
const char * V_50 , * V_51 , * V_52 ;
const struct V_43 * V_77 ;
unsigned int V_53 = 0 ;
struct V_78 * V_78 = F_17 ( V_70 ? V_70 : V_71 ) ;
V_75 = V_74 -> V_79 [ F_18 () ] ;
V_76 = F_11 ( V_75 , V_74 -> V_80 [ V_68 ] ) ;
V_50 = V_51 = V_81 [ V_68 ] ;
V_52 = V_65 [ V_82 ] ;
F_19 (iter, root, private->size - private->hook_entry[hook])
if ( F_15 ( V_77 , V_48 , V_50 ,
& V_51 , & V_52 , & V_53 ) != 0 )
break;
F_20 ( V_78 , V_83 , V_68 , V_38 , V_70 , V_71 , & V_84 ,
L_13 ,
V_72 , V_51 , V_52 , V_53 ) ;
}
unsigned int
F_21 ( struct V_37 * V_38 ,
unsigned int V_68 ,
const struct V_85 * V_86 ,
struct V_1 * V_87 )
{
static const char V_88 [ V_89 ] V_90 ( ( F_22 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_75 ;
struct V_43 * V_48 , * * V_91 ;
unsigned int * V_92 , V_93 , V_94 ;
const struct V_73 * V_74 ;
struct V_39 V_95 ;
unsigned int V_96 ;
V_6 = F_23 ( V_38 ) ;
V_7 = V_86 -> V_70 ? V_86 -> V_70 -> V_59 : V_88 ;
V_8 = V_86 -> V_71 ? V_86 -> V_71 -> V_59 : V_88 ;
V_95 . V_97 = F_24 ( V_6 -> V_98 ) & V_99 ;
V_95 . V_100 = F_25 ( V_38 ) ;
V_95 . V_101 = false ;
V_95 . V_70 = V_86 -> V_70 ;
V_95 . V_71 = V_86 -> V_71 ;
V_95 . V_102 = V_103 ;
V_95 . V_104 = V_68 ;
F_26 ( V_87 -> V_105 & ( 1 << V_68 ) ) ;
F_27 () ;
V_96 = F_28 () ;
V_74 = V_87 -> V_74 ;
V_94 = F_18 () ;
F_29 () ;
V_75 = V_74 -> V_79 [ V_94 ] ;
V_91 = (struct V_43 * * ) V_74 -> V_91 [ V_94 ] ;
V_92 = F_30 ( V_74 -> V_92 , V_94 ) ;
V_93 = * V_92 ;
V_48 = F_11 ( V_75 , V_74 -> V_80 [ V_68 ] ) ;
F_31 ( L_14 ,
V_87 -> V_59 , V_68 , V_93 ,
F_11 ( V_75 , V_74 -> V_106 [ V_68 ] ) ) ;
do {
const struct V_47 * V_55 ;
const struct V_107 * V_108 ;
F_26 ( V_48 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_48 -> V_6 , V_95 . V_97 ) ) {
V_109:
V_48 = F_32 ( V_48 ) ;
continue;
}
F_33 (ematch, e) {
V_95 . V_110 = V_108 -> V_57 . V_58 . V_110 ;
V_95 . V_111 = V_108 -> V_61 ;
if ( ! V_95 . V_110 -> V_110 ( V_38 , & V_95 ) )
goto V_109;
}
F_34 ( V_48 -> V_112 , V_38 -> V_113 , 1 ) ;
V_55 = F_14 ( V_48 ) ;
F_26 ( V_55 -> V_57 . V_58 . V_56 ) ;
#if F_35 ( V_114 )
if ( F_36 ( V_38 -> V_115 ) )
F_16 ( V_38 , V_68 , V_86 -> V_70 , V_86 -> V_71 ,
V_87 -> V_59 , V_74 , V_48 ) ;
#endif
if ( ! V_55 -> V_57 . V_58 . V_56 -> V_56 ) {
int V_116 ;
V_116 = ( (struct V_54 * ) V_55 ) -> V_64 ;
if ( V_116 < 0 ) {
if ( V_116 != V_117 ) {
V_64 = ( unsigned int ) ( - V_116 ) - 1 ;
break;
}
if ( * V_92 <= V_93 ) {
V_48 = F_11 ( V_75 ,
V_74 -> V_106 [ V_68 ] ) ;
F_31 ( L_15
L_16 , V_48 ) ;
} else {
V_48 = V_91 [ -- * V_92 ] ;
F_31 ( L_17 ,
V_48 , * V_92 ) ;
V_48 = F_32 ( V_48 ) ;
}
continue;
}
if ( V_75 + V_116 != F_32 ( V_48 ) &&
! ( V_48 -> V_6 . V_32 & V_118 ) ) {
if ( * V_92 >= V_74 -> V_119 ) {
V_64 = V_42 ;
break;
}
V_91 [ ( * V_92 ) ++ ] = V_48 ;
F_31 ( L_18 ,
V_48 , * V_92 - 1 ) ;
}
V_48 = F_11 ( V_75 , V_116 ) ;
continue;
}
V_95 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_95 . V_41 = V_55 -> V_61 ;
V_64 = V_55 -> V_57 . V_58 . V_56 -> V_56 ( V_38 , & V_95 ) ;
V_6 = F_23 ( V_38 ) ;
if ( V_64 == V_120 )
V_48 = F_32 ( V_48 ) ;
else
break;
} while ( ! V_95 . V_101 );
F_31 ( L_19 ,
V_121 , * V_92 , V_93 ) ;
* V_92 = V_93 ;
F_37 ( V_96 ) ;
F_38 () ;
#ifdef F_39
return V_122 ;
#else
if ( V_95 . V_101 )
return V_42 ;
else return V_64 ;
#endif
}
static int
F_40 ( const struct V_73 * V_123 ,
unsigned int V_105 , void * V_124 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_125 ; V_68 ++ ) {
unsigned int V_126 = V_123 -> V_80 [ V_68 ] ;
struct V_43 * V_48 = (struct V_43 * ) ( V_124 + V_126 ) ;
if ( ! ( V_105 & ( 1 << V_68 ) ) )
continue;
V_48 -> V_112 . V_127 = V_126 ;
for (; ; ) {
const struct V_54 * V_55
= ( void * ) F_13 ( V_48 ) ;
int V_128 = V_48 -> V_129 & ( 1 << V_68 ) ;
if ( V_48 -> V_129 & ( 1 << V_125 ) ) {
F_41 ( L_20 ,
V_68 , V_126 , V_48 -> V_129 ) ;
return 0 ;
}
V_48 -> V_129 |= ( ( 1 << V_68 ) | ( 1 << V_125 ) ) ;
if ( ( V_48 -> V_62 == sizeof( struct V_43 ) &&
( strcmp ( V_55 -> V_56 . V_57 . V_130 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < 0 && F_12 ( & V_48 -> V_6 ) ) ||
V_128 ) {
unsigned int V_131 , V_132 ;
if ( ( strcmp ( V_55 -> V_56 . V_57 . V_130 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < - V_133 - 1 ) {
F_8 ( L_21
L_22 ,
V_55 -> V_64 ) ;
return 0 ;
}
do {
V_48 -> V_129 ^= ( 1 << V_125 ) ;
#ifdef F_42
if ( V_48 -> V_129
& ( 1 << V_125 ) ) {
F_8 ( L_23
L_24
L_25 ,
V_68 , V_126 ) ;
}
#endif
V_131 = V_126 ;
V_126 = V_48 -> V_112 . V_127 ;
V_48 -> V_112 . V_127 = 0 ;
if ( V_126 == V_131 )
goto V_134;
V_48 = (struct V_43 * )
( V_124 + V_126 ) ;
} while ( V_131 == V_126 + V_48 -> V_135 );
V_132 = V_48 -> V_135 ;
V_48 = (struct V_43 * )
( V_124 + V_126 + V_132 ) ;
V_48 -> V_112 . V_127 = V_126 ;
V_126 += V_132 ;
} else {
int V_136 = V_55 -> V_64 ;
if ( strcmp ( V_55 -> V_56 . V_57 . V_130 . V_59 ,
V_63 ) == 0 &&
V_136 >= 0 ) {
if ( V_136 > V_123 -> V_132 -
sizeof( struct V_43 ) ) {
F_8 ( L_26
L_27 ,
V_136 ) ;
return 0 ;
}
F_8 ( L_28 ,
V_126 , V_136 ) ;
} else {
V_136 = V_126 + V_48 -> V_135 ;
}
V_48 = (struct V_43 * )
( V_124 + V_136 ) ;
V_48 -> V_112 . V_127 = V_126 ;
V_126 = V_136 ;
}
}
V_134:
F_8 ( L_29 , V_68 ) ;
}
return 1 ;
}
static void F_43 ( struct V_107 * V_137 , struct V_78 * V_78 )
{
struct V_138 V_40 ;
V_40 . V_78 = V_78 ;
V_40 . V_110 = V_137 -> V_57 . V_58 . V_110 ;
V_40 . V_111 = V_137 -> V_61 ;
V_40 . V_102 = V_103 ;
if ( V_40 . V_110 -> V_139 != NULL )
V_40 . V_110 -> V_139 ( & V_40 ) ;
F_44 ( V_40 . V_110 -> V_140 ) ;
}
static int
F_45 ( const struct V_43 * V_48 , const char * V_59 )
{
const struct V_47 * V_55 ;
if ( ! F_7 ( & V_48 -> V_6 ) ) {
F_8 ( L_30 , V_48 , V_59 ) ;
return - V_141 ;
}
if ( V_48 -> V_62 + sizeof( struct V_47 ) >
V_48 -> V_135 )
return - V_141 ;
V_55 = F_13 ( V_48 ) ;
if ( V_48 -> V_62 + V_55 -> V_57 . V_142 > V_48 -> V_135 )
return - V_141 ;
return 0 ;
}
static int
F_46 ( struct V_107 * V_137 , struct V_143 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_144 ;
int V_12 ;
V_40 -> V_110 = V_137 -> V_57 . V_58 . V_110 ;
V_40 -> V_111 = V_137 -> V_61 ;
V_12 = F_47 ( V_40 , V_137 -> V_57 . V_145 - sizeof( * V_137 ) ,
V_6 -> V_29 , V_6 -> V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 , V_40 -> V_110 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_48 ( struct V_107 * V_137 , struct V_143 * V_40 )
{
struct V_146 * V_110 ;
int V_12 ;
V_110 = F_49 ( V_103 , V_137 -> V_57 . V_130 . V_59 ,
V_137 -> V_57 . V_130 . V_147 ) ;
if ( F_50 ( V_110 ) ) {
F_8 ( L_32 , V_137 -> V_57 . V_130 . V_59 ) ;
return F_51 ( V_110 ) ;
}
V_137 -> V_57 . V_58 . V_110 = V_110 ;
V_12 = F_46 ( V_137 , V_40 ) ;
if ( V_12 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_137 -> V_57 . V_58 . V_110 -> V_140 ) ;
return V_12 ;
}
static int F_52 ( struct V_43 * V_48 , struct V_78 * V_78 , const char * V_59 )
{
struct V_47 * V_55 = F_14 ( V_48 ) ;
struct V_149 V_40 = {
. V_78 = V_78 ,
. V_87 = V_59 ,
. V_144 = V_48 ,
. V_56 = V_55 -> V_57 . V_58 . V_56 ,
. V_41 = V_55 -> V_61 ,
. V_150 = V_48 -> V_129 ,
. V_102 = V_103 ,
} ;
int V_12 ;
V_12 = F_53 ( & V_40 , V_55 -> V_57 . V_142 - sizeof( * V_55 ) ,
V_48 -> V_6 . V_29 , V_48 -> V_6 . V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_54 ( struct V_43 * V_48 , struct V_78 * V_78 , const char * V_59 ,
unsigned int V_132 )
{
struct V_47 * V_55 ;
struct V_151 * V_56 ;
int V_12 ;
unsigned int V_152 ;
struct V_143 V_153 ;
struct V_107 * V_108 ;
V_12 = F_45 ( V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_152 = 0 ;
V_153 . V_78 = V_78 ;
V_153 . V_87 = V_59 ;
V_153 . V_144 = & V_48 -> V_6 ;
V_153 . V_150 = V_48 -> V_129 ;
V_153 . V_102 = V_103 ;
F_33 (ematch, e) {
V_12 = F_48 ( V_108 , & V_153 ) ;
if ( V_12 != 0 )
goto V_154;
++ V_152 ;
}
V_55 = F_14 ( V_48 ) ;
V_56 = F_55 ( V_103 , V_55 -> V_57 . V_130 . V_59 ,
V_55 -> V_57 . V_130 . V_147 ) ;
if ( F_50 ( V_56 ) ) {
F_8 ( L_33 , V_55 -> V_57 . V_130 . V_59 ) ;
V_12 = F_51 ( V_56 ) ;
goto V_154;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_12 = F_52 ( V_48 , V_78 , V_59 ) ;
if ( V_12 )
goto V_148;
return 0 ;
V_148:
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_140 ) ;
V_154:
F_33 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_108 , V_78 ) ;
}
return V_12 ;
}
static bool F_56 ( const struct V_43 * V_48 )
{
const struct V_47 * V_55 ;
unsigned int V_64 ;
if ( ! F_12 ( & V_48 -> V_6 ) )
return false ;
V_55 = F_13 ( V_48 ) ;
if ( strcmp ( V_55 -> V_57 . V_130 . V_59 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_54 * ) V_55 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_122 ;
}
static int
F_57 ( struct V_43 * V_48 ,
struct V_73 * V_123 ,
const unsigned char * V_44 ,
const unsigned char * V_155 ,
const unsigned int * V_156 ,
const unsigned int * V_157 ,
unsigned int V_105 )
{
unsigned int V_158 ;
if ( ( unsigned long ) V_48 % F_58 ( struct V_43 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_43 ) >= V_155 ) {
F_8 ( L_34 , V_48 ) ;
return - V_141 ;
}
if ( V_48 -> V_135
< sizeof( struct V_43 ) + sizeof( struct V_47 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_135 ) ;
return - V_141 ;
}
for ( V_158 = 0 ; V_158 < V_125 ; V_158 ++ ) {
if ( ! ( V_105 & ( 1 << V_158 ) ) )
continue;
if ( ( unsigned char * ) V_48 - V_44 == V_156 [ V_158 ] )
V_123 -> V_80 [ V_158 ] = V_156 [ V_158 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_157 [ V_158 ] ) {
if ( ! F_56 ( V_48 ) ) {
F_41 ( L_36
L_37
L_38 ) ;
return - V_141 ;
}
V_123 -> V_106 [ V_158 ] = V_157 [ V_158 ] ;
}
}
V_48 -> V_112 = ( (struct V_159 ) { 0 , 0 } ) ;
V_48 -> V_129 = 0 ;
return 0 ;
}
static void
F_59 ( struct V_43 * V_48 , struct V_78 * V_78 )
{
struct V_160 V_40 ;
struct V_47 * V_55 ;
struct V_107 * V_108 ;
F_33 (ematch, e)
F_43 ( V_108 , V_78 ) ;
V_55 = F_14 ( V_48 ) ;
V_40 . V_78 = V_78 ;
V_40 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_40 . V_41 = V_55 -> V_61 ;
V_40 . V_102 = V_103 ;
if ( V_40 . V_56 -> V_139 != NULL )
V_40 . V_56 -> V_139 ( & V_40 ) ;
F_44 ( V_40 . V_56 -> V_140 ) ;
}
static int
F_60 ( struct V_78 * V_78 , struct V_73 * V_123 , void * V_124 ,
const struct V_161 * V_162 )
{
struct V_43 * V_77 ;
unsigned int V_163 ;
int V_12 = 0 ;
V_123 -> V_132 = V_162 -> V_132 ;
V_123 -> V_164 = V_162 -> V_165 ;
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
V_123 -> V_80 [ V_163 ] = 0xFFFFFFFF ;
V_123 -> V_106 [ V_163 ] = 0xFFFFFFFF ;
}
F_8 ( L_39 , V_123 -> V_132 ) ;
V_163 = 0 ;
F_19 (iter, entry0, newinfo->size) {
V_12 = F_57 ( V_77 , V_123 , V_124 ,
V_124 + V_162 -> V_132 ,
V_162 -> V_80 ,
V_162 -> V_106 ,
V_162 -> V_105 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_163 ;
if ( strcmp ( F_14 ( V_77 ) -> V_57 . V_130 . V_59 ,
V_60 ) == 0 )
++ V_123 -> V_119 ;
}
if ( V_163 != V_162 -> V_165 ) {
F_8 ( L_40 ,
V_163 , V_162 -> V_165 ) ;
return - V_141 ;
}
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
if ( ! ( V_162 -> V_105 & ( 1 << V_163 ) ) )
continue;
if ( V_123 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_163 , V_162 -> V_80 [ V_163 ] ) ;
return - V_141 ;
}
if ( V_123 -> V_106 [ V_163 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_163 , V_162 -> V_106 [ V_163 ] ) ;
return - V_141 ;
}
}
if ( ! F_40 ( V_123 , V_162 -> V_105 , V_124 ) )
return - V_166 ;
V_163 = 0 ;
F_19 (iter, entry0, newinfo->size) {
V_12 = F_54 ( V_77 , V_78 , V_162 -> V_59 , V_162 -> V_132 ) ;
if ( V_12 != 0 )
break;
++ V_163 ;
}
if ( V_12 != 0 ) {
F_19 (iter, entry0, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_59 ( V_77 , V_78 ) ;
}
return V_12 ;
}
F_61 (i) {
if ( V_123 -> V_79 [ V_163 ] && V_123 -> V_79 [ V_163 ] != V_124 )
memcpy ( V_123 -> V_79 [ V_163 ] , V_124 , V_123 -> V_132 ) ;
}
return V_12 ;
}
static void
F_62 ( const struct V_73 * V_55 ,
struct V_159 V_112 [] )
{
struct V_43 * V_77 ;
unsigned int V_94 ;
unsigned int V_163 ;
F_61 (cpu) {
T_2 * V_49 = & F_63 ( V_167 , V_94 ) ;
V_163 = 0 ;
F_19 (iter, t->entries[cpu], t->size) {
T_3 V_168 , V_127 ;
unsigned int V_169 ;
do {
V_169 = F_64 ( V_49 ) ;
V_168 = V_77 -> V_112 . V_168 ;
V_127 = V_77 -> V_112 . V_127 ;
} while ( F_65 ( V_49 , V_169 ) );
F_34 ( V_112 [ V_163 ] , V_168 , V_127 ) ;
++ V_163 ;
}
}
}
static struct V_159 * F_66 ( const struct V_1 * V_87 )
{
unsigned int V_170 ;
struct V_159 * V_112 ;
const struct V_73 * V_74 = V_87 -> V_74 ;
V_170 = sizeof( struct V_159 ) * V_74 -> V_164 ;
V_112 = F_67 ( V_170 ) ;
if ( V_112 == NULL )
return F_68 ( - V_171 ) ;
F_62 ( V_74 , V_112 ) ;
return V_112 ;
}
static int
F_69 ( unsigned int V_172 ,
const struct V_1 * V_87 ,
void T_4 * V_173 )
{
unsigned int V_174 , V_175 ;
const struct V_43 * V_48 ;
struct V_159 * V_112 ;
const struct V_73 * V_74 = V_87 -> V_74 ;
int V_12 = 0 ;
const void * V_176 ;
V_112 = F_66 ( V_87 ) ;
if ( F_50 ( V_112 ) )
return F_51 ( V_112 ) ;
V_176 = V_74 -> V_79 [ F_70 () ] ;
if ( F_71 ( V_173 , V_176 , V_172 ) != 0 ) {
V_12 = - V_177 ;
goto V_178;
}
for ( V_174 = 0 , V_175 = 0 ; V_174 < V_172 ; V_174 += V_48 -> V_135 , V_175 ++ ) {
unsigned int V_163 ;
const struct V_107 * V_137 ;
const struct V_47 * V_55 ;
V_48 = (struct V_43 * ) ( V_176 + V_174 ) ;
if ( F_71 ( V_173 + V_174
+ F_72 ( struct V_43 , V_112 ) ,
& V_112 [ V_175 ] ,
sizeof( V_112 [ V_175 ] ) ) != 0 ) {
V_12 = - V_177 ;
goto V_178;
}
for ( V_163 = sizeof( struct V_43 ) ;
V_163 < V_48 -> V_62 ;
V_163 += V_137 -> V_57 . V_145 ) {
V_137 = ( void * ) V_48 + V_163 ;
if ( F_71 ( V_173 + V_174 + V_163
+ F_72 ( struct V_107 ,
V_57 . V_130 . V_59 ) ,
V_137 -> V_57 . V_58 . V_110 -> V_59 ,
strlen ( V_137 -> V_57 . V_58 . V_110 -> V_59 ) + 1 )
!= 0 ) {
V_12 = - V_177 ;
goto V_178;
}
}
V_55 = F_13 ( V_48 ) ;
if ( F_71 ( V_173 + V_174 + V_48 -> V_62
+ F_72 ( struct V_47 ,
V_57 . V_130 . V_59 ) ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ,
strlen ( V_55 -> V_57 . V_58 . V_56 -> V_59 ) + 1 ) != 0 ) {
V_12 = - V_177 ;
goto V_178;
}
}
V_178:
F_73 ( V_112 ) ;
return V_12 ;
}
static void F_74 ( void * V_20 , const void * V_16 )
{
int V_116 = * ( V_179 * ) V_16 ;
if ( V_116 > 0 )
V_116 += F_75 ( V_83 , V_116 ) ;
memcpy ( V_20 , & V_116 , sizeof( V_116 ) ) ;
}
static int F_76 ( void T_4 * V_20 , const void * V_16 )
{
V_179 V_180 = * ( int * ) V_16 ;
if ( V_180 > 0 )
V_180 -= F_75 ( V_83 , V_180 ) ;
return F_71 ( V_20 , & V_180 , sizeof( V_180 ) ) ? - V_177 : 0 ;
}
static int F_77 ( const struct V_43 * V_48 ,
const struct V_73 * V_2 ,
const void * V_44 , struct V_73 * V_123 )
{
const struct V_107 * V_108 ;
const struct V_47 * V_55 ;
unsigned int V_181 ;
int V_174 , V_163 , V_12 ;
V_174 = sizeof( struct V_43 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_48 - V_44 ;
F_33 (ematch, e)
V_174 += F_78 ( V_108 -> V_57 . V_58 . V_110 ) ;
V_55 = F_13 ( V_48 ) ;
V_174 += F_79 ( V_55 -> V_57 . V_58 . V_56 ) ;
V_123 -> V_132 -= V_174 ;
V_12 = F_80 ( V_83 , V_181 , V_174 ) ;
if ( V_12 )
return V_12 ;
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
if ( V_2 -> V_80 [ V_163 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_80 [ V_163 ] ) ) )
V_123 -> V_80 [ V_163 ] -= V_174 ;
if ( V_2 -> V_106 [ V_163 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_106 [ V_163 ] ) ) )
V_123 -> V_106 [ V_163 ] -= V_174 ;
}
return 0 ;
}
static int F_81 ( const struct V_73 * V_2 ,
struct V_73 * V_123 )
{
struct V_43 * V_77 ;
void * V_176 ;
int V_12 ;
if ( ! V_123 || ! V_2 )
return - V_141 ;
memcpy ( V_123 , V_2 , F_72 ( struct V_73 , V_79 ) ) ;
V_123 -> V_183 = 0 ;
V_176 = V_2 -> V_79 [ F_70 () ] ;
F_82 ( V_83 , V_2 -> V_164 ) ;
F_19 (iter, loc_cpu_entry, info->size) {
V_12 = F_77 ( V_77 , V_2 , V_176 , V_123 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_83 ( struct V_78 * V_78 , void T_4 * V_130 ,
const int * V_113 , int V_184 )
{
char V_59 [ V_185 ] ;
struct V_1 * V_55 ;
int V_12 ;
if ( * V_113 != sizeof( struct V_186 ) ) {
F_8 ( L_43 , * V_113 ,
sizeof( struct V_186 ) ) ;
return - V_141 ;
}
if ( F_84 ( V_59 , V_130 , sizeof( V_59 ) ) != 0 )
return - V_177 ;
V_59 [ V_185 - 1 ] = '\0' ;
#ifdef F_85
if ( V_184 )
F_86 ( V_83 ) ;
#endif
V_55 = F_87 ( F_88 ( V_78 , V_83 , V_59 ) ,
L_44 , V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
struct V_186 V_2 ;
const struct V_73 * V_74 = V_55 -> V_74 ;
#ifdef F_85
struct V_73 V_187 ;
if ( V_184 ) {
V_12 = F_81 ( V_74 , & V_187 ) ;
F_90 ( V_83 ) ;
V_74 = & V_187 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_105 = V_55 -> V_105 ;
memcpy ( V_2 . V_80 , V_74 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_106 , V_74 -> V_106 ,
sizeof( V_2 . V_106 ) ) ;
V_2 . V_165 = V_74 -> V_164 ;
V_2 . V_132 = V_74 -> V_132 ;
strcpy ( V_2 . V_59 , V_59 ) ;
if ( F_71 ( V_130 , & V_2 , * V_113 ) != 0 )
V_12 = - V_177 ;
else
V_12 = 0 ;
F_91 ( V_55 ) ;
F_44 ( V_55 -> V_140 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_188 ;
#ifdef F_85
if ( V_184 )
F_92 ( V_83 ) ;
#endif
return V_12 ;
}
static int
F_93 ( struct V_78 * V_78 , struct V_189 T_4 * V_190 ,
const int * V_113 )
{
int V_12 ;
struct V_189 V_191 ;
struct V_1 * V_55 ;
if ( * V_113 < sizeof( V_191 ) ) {
F_8 ( L_45 , * V_113 , sizeof( V_191 ) ) ;
return - V_141 ;
}
if ( F_84 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_177 ;
if ( * V_113 != sizeof( struct V_189 ) + V_191 . V_132 ) {
F_8 ( L_46 ,
* V_113 , sizeof( V_191 ) + V_191 . V_132 ) ;
return - V_141 ;
}
V_55 = F_88 ( V_78 , V_83 , V_191 . V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
F_8 ( L_47 , V_74 -> V_164 ) ;
if ( V_191 . V_132 == V_74 -> V_132 )
V_12 = F_69 ( V_74 -> V_132 ,
V_55 , V_190 -> V_192 ) ;
else {
F_8 ( L_48 ,
V_74 -> V_132 , V_191 . V_132 ) ;
V_12 = - V_193 ;
}
F_44 ( V_55 -> V_140 ) ;
F_91 ( V_55 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_188 ;
return V_12 ;
}
static int
F_94 ( struct V_78 * V_78 , const char * V_59 , unsigned int V_105 ,
struct V_73 * V_123 , unsigned int V_194 ,
void T_4 * V_195 )
{
int V_12 ;
struct V_1 * V_55 ;
struct V_73 * V_196 ;
struct V_159 * V_112 ;
void * V_197 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_112 = F_67 ( V_194 * sizeof( struct V_159 ) ) ;
if ( ! V_112 ) {
V_12 = - V_171 ;
goto V_71;
}
V_55 = F_87 ( F_88 ( V_78 , V_83 , V_59 ) ,
L_44 , V_59 ) ;
if ( F_89 ( V_55 ) ) {
V_12 = V_55 ? F_51 ( V_55 ) : - V_188 ;
goto V_198;
}
if ( V_105 != V_55 -> V_105 ) {
F_8 ( L_49 ,
V_105 , V_55 -> V_105 ) ;
V_12 = - V_141 ;
goto V_199;
}
V_196 = F_95 ( V_55 , V_194 , V_123 , & V_12 ) ;
if ( ! V_196 )
goto V_199;
F_8 ( L_50 ,
V_196 -> V_164 , V_196 -> V_183 , V_123 -> V_164 ) ;
if ( ( V_196 -> V_164 > V_196 -> V_183 ) ||
( V_123 -> V_164 <= V_196 -> V_183 ) )
F_44 ( V_55 -> V_140 ) ;
if ( ( V_196 -> V_164 > V_196 -> V_183 ) &&
( V_123 -> V_164 <= V_196 -> V_183 ) )
F_44 ( V_55 -> V_140 ) ;
F_62 ( V_196 , V_112 ) ;
V_197 = V_196 -> V_79 [ F_70 () ] ;
F_19 (iter, loc_cpu_old_entry, oldinfo->size)
F_59 ( V_77 , V_78 ) ;
F_96 ( V_196 ) ;
if ( F_71 ( V_195 , V_112 ,
sizeof( struct V_159 ) * V_194 ) != 0 ) {
F_97 ( L_51 ) ;
}
F_73 ( V_112 ) ;
F_91 ( V_55 ) ;
return V_12 ;
V_199:
F_44 ( V_55 -> V_140 ) ;
F_91 ( V_55 ) ;
V_198:
F_73 ( V_112 ) ;
V_71:
return V_12 ;
}
static int
F_98 ( struct V_78 * V_78 , const void T_4 * V_130 , unsigned int V_113 )
{
int V_12 ;
struct V_161 V_187 ;
struct V_73 * V_123 ;
void * V_176 ;
struct V_43 * V_77 ;
if ( F_84 ( & V_187 , V_130 , sizeof( V_187 ) ) != 0 )
return - V_177 ;
if ( V_187 . V_194 >= V_200 / sizeof( struct V_159 ) )
return - V_171 ;
if ( V_187 . V_194 == 0 )
return - V_141 ;
V_187 . V_59 [ sizeof( V_187 . V_59 ) - 1 ] = 0 ;
V_123 = F_99 ( V_187 . V_132 ) ;
if ( ! V_123 )
return - V_171 ;
V_176 = V_123 -> V_79 [ F_70 () ] ;
if ( F_84 ( V_176 , V_130 + sizeof( V_187 ) ,
V_187 . V_132 ) != 0 ) {
V_12 = - V_177 ;
goto V_201;
}
V_12 = F_60 ( V_78 , V_123 , V_176 , & V_187 ) ;
if ( V_12 != 0 )
goto V_201;
F_8 ( L_52 ) ;
V_12 = F_94 ( V_78 , V_187 . V_59 , V_187 . V_105 , V_123 ,
V_187 . V_194 , V_187 . V_112 ) ;
if ( V_12 )
goto V_202;
return 0 ;
V_202:
F_19 (iter, loc_cpu_entry, newinfo->size)
F_59 ( V_77 , V_78 ) ;
V_201:
F_96 ( V_123 ) ;
return V_12 ;
}
static int
F_100 ( struct V_78 * V_78 , const void T_4 * V_130 ,
unsigned int V_113 , int V_184 )
{
unsigned int V_163 , V_203 ;
struct V_204 V_187 ;
struct V_159 * V_205 ;
unsigned int V_194 ;
const char * V_59 ;
int V_132 ;
void * V_206 ;
struct V_1 * V_55 ;
const struct V_73 * V_74 ;
int V_12 = 0 ;
void * V_176 ;
struct V_43 * V_77 ;
unsigned int V_96 ;
#ifdef F_85
struct V_207 V_208 ;
if ( V_184 ) {
V_206 = & V_208 ;
V_132 = sizeof( struct V_207 ) ;
} else
#endif
{
V_206 = & V_187 ;
V_132 = sizeof( struct V_204 ) ;
}
if ( F_84 ( V_206 , V_130 , V_132 ) != 0 )
return - V_177 ;
#ifdef F_85
if ( V_184 ) {
V_194 = V_208 . V_194 ;
V_59 = V_208 . V_59 ;
} else
#endif
{
V_194 = V_187 . V_194 ;
V_59 = V_187 . V_59 ;
}
if ( V_113 != V_132 + V_194 * sizeof( struct V_159 ) )
return - V_141 ;
V_205 = F_101 ( V_113 - V_132 ) ;
if ( ! V_205 )
return - V_171 ;
if ( F_84 ( V_205 , V_130 + V_132 , V_113 - V_132 ) != 0 ) {
V_12 = - V_177 ;
goto free;
}
V_55 = F_88 ( V_78 , V_83 , V_59 ) ;
if ( F_89 ( V_55 ) ) {
V_12 = V_55 ? F_51 ( V_55 ) : - V_188 ;
goto free;
}
F_27 () ;
V_74 = V_55 -> V_74 ;
if ( V_74 -> V_164 != V_194 ) {
V_12 = - V_141 ;
goto V_209;
}
V_163 = 0 ;
V_203 = F_18 () ;
V_176 = V_74 -> V_79 [ V_203 ] ;
V_96 = F_28 () ;
F_19 (iter, loc_cpu_entry, private->size) {
F_34 ( V_77 -> V_112 , V_205 [ V_163 ] . V_168 , V_205 [ V_163 ] . V_127 ) ;
++ V_163 ;
}
F_37 ( V_96 ) ;
V_209:
F_38 () ;
F_91 ( V_55 ) ;
F_44 ( V_55 -> V_140 ) ;
free:
F_73 ( V_205 ) ;
return V_12 ;
}
static int
F_102 ( struct V_43 * V_48 , void T_4 * * V_210 ,
unsigned int * V_132 , struct V_159 * V_112 ,
unsigned int V_163 )
{
struct V_47 * V_55 ;
struct V_182 T_4 * V_211 ;
T_5 V_62 , V_135 ;
T_6 V_212 ;
const struct V_107 * V_108 ;
int V_12 = 0 ;
V_212 = * V_132 ;
V_211 = (struct V_182 T_4 * ) * V_210 ;
if ( F_71 ( V_211 , V_48 , sizeof( struct V_43 ) ) != 0 ||
F_71 ( & V_211 -> V_112 , & V_112 [ V_163 ] ,
sizeof( V_112 [ V_163 ] ) ) != 0 )
return - V_177 ;
* V_210 += sizeof( struct V_182 ) ;
* V_132 -= sizeof( struct V_43 ) - sizeof( struct V_182 ) ;
F_33 (ematch, e) {
V_12 = F_103 ( V_108 , V_210 , V_132 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_62 = V_48 -> V_62 - ( V_212 - * V_132 ) ;
V_55 = F_14 ( V_48 ) ;
V_12 = F_104 ( V_55 , V_210 , V_132 ) ;
if ( V_12 )
return V_12 ;
V_135 = V_48 -> V_135 - ( V_212 - * V_132 ) ;
if ( F_105 ( V_62 , & V_211 -> V_62 ) != 0 ||
F_105 ( V_135 , & V_211 -> V_135 ) != 0 )
return - V_177 ;
return 0 ;
}
static int
F_106 ( struct V_107 * V_137 ,
const char * V_59 ,
const struct V_9 * V_6 ,
unsigned int V_213 ,
int * V_132 )
{
struct V_146 * V_110 ;
V_110 = F_49 ( V_103 , V_137 -> V_57 . V_130 . V_59 ,
V_137 -> V_57 . V_130 . V_147 ) ;
if ( F_50 ( V_110 ) ) {
F_8 ( L_53 ,
V_137 -> V_57 . V_130 . V_59 ) ;
return F_51 ( V_110 ) ;
}
V_137 -> V_57 . V_58 . V_110 = V_110 ;
* V_132 += F_78 ( V_110 ) ;
return 0 ;
}
static void F_107 ( struct V_182 * V_48 )
{
struct V_47 * V_55 ;
struct V_107 * V_108 ;
F_33 (ematch, e)
F_44 ( V_108 -> V_57 . V_58 . V_110 -> V_140 ) ;
V_55 = F_108 ( V_48 ) ;
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_140 ) ;
}
static int
F_109 ( struct V_182 * V_48 ,
struct V_73 * V_123 ,
unsigned int * V_132 ,
const unsigned char * V_44 ,
const unsigned char * V_155 ,
const unsigned int * V_156 ,
const unsigned int * V_157 ,
const char * V_59 )
{
struct V_107 * V_108 ;
struct V_47 * V_55 ;
struct V_151 * V_56 ;
unsigned int V_181 ;
unsigned int V_152 ;
int V_12 , V_174 , V_158 ;
F_8 ( L_54 , V_48 ) ;
if ( ( unsigned long ) V_48 % F_58 ( struct V_182 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_182 ) >= V_155 ) {
F_8 ( L_55 , V_48 , V_155 ) ;
return - V_141 ;
}
if ( V_48 -> V_135 < sizeof( struct V_182 ) +
sizeof( struct V_214 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_135 ) ;
return - V_141 ;
}
V_12 = F_45 ( (struct V_43 * ) V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_174 = sizeof( struct V_43 ) - sizeof( struct V_182 ) ;
V_181 = ( void * ) V_48 - ( void * ) V_44 ;
V_152 = 0 ;
F_33 (ematch, e) {
V_12 = F_106 ( V_108 , V_59 ,
& V_48 -> V_6 , V_48 -> V_129 , & V_174 ) ;
if ( V_12 != 0 )
goto V_215;
++ V_152 ;
}
V_55 = F_108 ( V_48 ) ;
V_56 = F_55 ( V_103 , V_55 -> V_57 . V_130 . V_59 ,
V_55 -> V_57 . V_130 . V_147 ) ;
if ( F_50 ( V_56 ) ) {
F_8 ( L_56 ,
V_55 -> V_57 . V_130 . V_59 ) ;
V_12 = F_51 ( V_56 ) ;
goto V_215;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_174 += F_79 ( V_56 ) ;
* V_132 += V_174 ;
V_12 = F_80 ( V_83 , V_181 , V_174 ) ;
if ( V_12 )
goto V_71;
for ( V_158 = 0 ; V_158 < V_125 ; V_158 ++ ) {
if ( ( unsigned char * ) V_48 - V_44 == V_156 [ V_158 ] )
V_123 -> V_80 [ V_158 ] = V_156 [ V_158 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_157 [ V_158 ] )
V_123 -> V_106 [ V_158 ] = V_157 [ V_158 ] ;
}
memset ( & V_48 -> V_112 , 0 , sizeof( V_48 -> V_112 ) ) ;
V_48 -> V_129 = 0 ;
return 0 ;
V_71:
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_140 ) ;
V_215:
F_33 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_44 ( V_108 -> V_57 . V_58 . V_110 -> V_140 ) ;
}
return V_12 ;
}
static int
F_110 ( struct V_182 * V_48 , void * * V_210 ,
unsigned int * V_132 , const char * V_59 ,
struct V_73 * V_123 , unsigned char * V_44 )
{
struct V_47 * V_55 ;
struct V_151 * V_56 ;
struct V_43 * V_216 ;
unsigned int V_212 ;
int V_12 , V_158 ;
struct V_107 * V_108 ;
V_12 = 0 ;
V_212 = * V_132 ;
V_216 = (struct V_43 * ) * V_210 ;
memcpy ( V_216 , V_48 , sizeof( struct V_43 ) ) ;
memcpy ( & V_216 -> V_112 , & V_48 -> V_112 , sizeof( V_48 -> V_112 ) ) ;
* V_210 += sizeof( struct V_43 ) ;
* V_132 += sizeof( struct V_43 ) - sizeof( struct V_182 ) ;
F_33 (ematch, e) {
V_12 = F_111 ( V_108 , V_210 , V_132 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_216 -> V_62 = V_48 -> V_62 - ( V_212 - * V_132 ) ;
V_55 = F_108 ( V_48 ) ;
V_56 = V_55 -> V_57 . V_58 . V_56 ;
F_112 ( V_55 , V_210 , V_132 ) ;
V_216 -> V_135 = V_48 -> V_135 - ( V_212 - * V_132 ) ;
for ( V_158 = 0 ; V_158 < V_125 ; V_158 ++ ) {
if ( ( unsigned char * ) V_216 - V_44 < V_123 -> V_80 [ V_158 ] )
V_123 -> V_80 [ V_158 ] -= V_212 - * V_132 ;
if ( ( unsigned char * ) V_216 - V_44 < V_123 -> V_106 [ V_158 ] )
V_123 -> V_106 [ V_158 ] -= V_212 - * V_132 ;
}
return V_12 ;
}
static int
F_113 ( struct V_43 * V_48 , struct V_78 * V_78 , const char * V_59 )
{
struct V_107 * V_108 ;
struct V_143 V_153 ;
unsigned int V_152 ;
int V_12 = 0 ;
V_152 = 0 ;
V_153 . V_78 = V_78 ;
V_153 . V_87 = V_59 ;
V_153 . V_144 = & V_48 -> V_6 ;
V_153 . V_150 = V_48 -> V_129 ;
V_153 . V_102 = V_103 ;
F_33 (ematch, e) {
V_12 = F_46 ( V_108 , & V_153 ) ;
if ( V_12 != 0 )
goto V_154;
++ V_152 ;
}
V_12 = F_52 ( V_48 , V_78 , V_59 ) ;
if ( V_12 )
goto V_154;
return 0 ;
V_154:
F_33 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_43 ( V_108 , V_78 ) ;
}
return V_12 ;
}
static int
F_114 ( struct V_78 * V_78 ,
const char * V_59 ,
unsigned int V_105 ,
struct V_73 * * V_217 ,
void * * V_218 ,
unsigned int V_172 ,
unsigned int V_164 ,
unsigned int * V_156 ,
unsigned int * V_157 )
{
unsigned int V_163 , V_152 ;
struct V_73 * V_123 , * V_2 ;
void * V_126 , * V_124 , * V_219 ;
struct V_182 * V_220 ;
struct V_43 * V_221 ;
unsigned int V_132 ;
int V_12 ;
V_2 = * V_217 ;
V_124 = * V_218 ;
V_132 = V_172 ;
V_2 -> V_164 = V_164 ;
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
V_2 -> V_80 [ V_163 ] = 0xFFFFFFFF ;
V_2 -> V_106 [ V_163 ] = 0xFFFFFFFF ;
}
F_8 ( L_57 , V_2 -> V_132 ) ;
V_152 = 0 ;
F_86 ( V_83 ) ;
F_82 ( V_83 , V_164 ) ;
F_19 (iter0, entry0, total_size) {
V_12 = F_109 ( V_220 , V_2 , & V_132 ,
V_124 ,
V_124 + V_172 ,
V_156 ,
V_157 ,
V_59 ) ;
if ( V_12 != 0 )
goto V_222;
++ V_152 ;
}
V_12 = - V_141 ;
if ( V_152 != V_164 ) {
F_8 ( L_58 ,
V_152 , V_164 ) ;
goto V_222;
}
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
if ( ! ( V_105 & ( 1 << V_163 ) ) )
continue;
if ( V_2 -> V_80 [ V_163 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_163 , V_156 [ V_163 ] ) ;
goto V_222;
}
if ( V_2 -> V_106 [ V_163 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_163 , V_157 [ V_163 ] ) ;
goto V_222;
}
}
V_12 = - V_171 ;
V_123 = F_99 ( V_132 ) ;
if ( ! V_123 )
goto V_222;
V_123 -> V_164 = V_164 ;
for ( V_163 = 0 ; V_163 < V_125 ; V_163 ++ ) {
V_123 -> V_80 [ V_163 ] = V_2 -> V_80 [ V_163 ] ;
V_123 -> V_106 [ V_163 ] = V_2 -> V_106 [ V_163 ] ;
}
V_219 = V_123 -> V_79 [ F_70 () ] ;
V_126 = V_219 ;
V_132 = V_172 ;
F_19 (iter0, entry0, total_size) {
V_12 = F_110 ( V_220 , & V_126 , & V_132 ,
V_59 , V_123 , V_219 ) ;
if ( V_12 != 0 )
break;
}
F_90 ( V_83 ) ;
F_92 ( V_83 ) ;
if ( V_12 )
goto V_201;
V_12 = - V_166 ;
if ( ! F_40 ( V_123 , V_105 , V_219 ) )
goto V_201;
V_163 = 0 ;
F_19 (iter1, entry1, newinfo->size) {
V_12 = F_113 ( V_221 , V_78 , V_59 ) ;
if ( V_12 != 0 )
break;
++ V_163 ;
if ( strcmp ( F_14 ( V_221 ) -> V_57 . V_130 . V_59 ,
V_60 ) == 0 )
++ V_123 -> V_119 ;
}
if ( V_12 ) {
int V_223 = V_163 ;
V_152 -= V_163 ;
F_19 (iter0, entry0, newinfo->size) {
if ( V_223 -- > 0 )
continue;
if ( V_152 -- == 0 )
break;
F_107 ( V_220 ) ;
}
F_19 (iter1, entry1, newinfo->size) {
if ( V_163 -- == 0 )
break;
F_59 ( V_221 , V_78 ) ;
}
F_96 ( V_123 ) ;
return V_12 ;
}
F_61 (i)
if ( V_123 -> V_79 [ V_163 ] && V_123 -> V_79 [ V_163 ] != V_219 )
memcpy ( V_123 -> V_79 [ V_163 ] , V_219 , V_123 -> V_132 ) ;
* V_217 = V_123 ;
* V_218 = V_219 ;
F_96 ( V_2 ) ;
return 0 ;
V_201:
F_96 ( V_123 ) ;
V_71:
F_19 (iter0, entry0, total_size) {
if ( V_152 -- == 0 )
break;
F_107 ( V_220 ) ;
}
return V_12 ;
V_222:
F_90 ( V_83 ) ;
F_92 ( V_83 ) ;
goto V_71;
}
static int
F_115 ( struct V_78 * V_78 , void T_4 * V_130 , unsigned int V_113 )
{
int V_12 ;
struct V_224 V_187 ;
struct V_73 * V_123 ;
void * V_176 ;
struct V_43 * V_77 ;
if ( F_84 ( & V_187 , V_130 , sizeof( V_187 ) ) != 0 )
return - V_177 ;
if ( V_187 . V_132 >= V_200 / F_116 () )
return - V_171 ;
if ( V_187 . V_194 >= V_200 / sizeof( struct V_159 ) )
return - V_171 ;
if ( V_187 . V_194 == 0 )
return - V_141 ;
V_187 . V_59 [ sizeof( V_187 . V_59 ) - 1 ] = 0 ;
V_123 = F_99 ( V_187 . V_132 ) ;
if ( ! V_123 )
return - V_171 ;
V_176 = V_123 -> V_79 [ F_70 () ] ;
if ( F_84 ( V_176 , V_130 + sizeof( V_187 ) ,
V_187 . V_132 ) != 0 ) {
V_12 = - V_177 ;
goto V_201;
}
V_12 = F_114 ( V_78 , V_187 . V_59 , V_187 . V_105 ,
& V_123 , & V_176 , V_187 . V_132 ,
V_187 . V_165 , V_187 . V_80 ,
V_187 . V_106 ) ;
if ( V_12 != 0 )
goto V_201;
F_8 ( L_59 ) ;
V_12 = F_94 ( V_78 , V_187 . V_59 , V_187 . V_105 , V_123 ,
V_187 . V_194 , F_117 ( V_187 . V_112 ) ) ;
if ( V_12 )
goto V_202;
return 0 ;
V_202:
F_19 (iter, loc_cpu_entry, newinfo->size)
F_59 ( V_77 , V_78 ) ;
V_201:
F_96 ( V_123 ) ;
return V_12 ;
}
static int
F_118 ( struct V_225 * V_226 , int V_227 , void T_4 * V_130 ,
unsigned int V_113 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_231 :
V_12 = F_115 ( F_120 ( V_226 ) , V_130 , V_113 ) ;
break;
case V_232 :
V_12 = F_100 ( F_120 ( V_226 ) , V_130 , V_113 , 1 ) ;
break;
default:
F_8 ( L_60 , V_227 ) ;
V_12 = - V_141 ;
}
return V_12 ;
}
static int
F_121 ( unsigned int V_172 , struct V_1 * V_87 ,
void T_4 * V_173 )
{
struct V_159 * V_112 ;
const struct V_73 * V_74 = V_87 -> V_74 ;
void T_4 * V_126 ;
unsigned int V_132 ;
int V_12 = 0 ;
const void * V_176 ;
unsigned int V_163 = 0 ;
struct V_43 * V_77 ;
V_112 = F_66 ( V_87 ) ;
if ( F_50 ( V_112 ) )
return F_51 ( V_112 ) ;
V_176 = V_74 -> V_79 [ F_70 () ] ;
V_126 = V_173 ;
V_132 = V_172 ;
F_19 (iter, loc_cpu_entry, total_size) {
V_12 = F_102 ( V_77 , & V_126 ,
& V_132 , V_112 , V_163 ++ ) ;
if ( V_12 != 0 )
break;
}
F_73 ( V_112 ) ;
return V_12 ;
}
static int
F_122 ( struct V_78 * V_78 , struct V_233 T_4 * V_190 ,
int * V_113 )
{
int V_12 ;
struct V_233 V_191 ;
struct V_1 * V_55 ;
if ( * V_113 < sizeof( V_191 ) ) {
F_8 ( L_61 , * V_113 , sizeof( V_191 ) ) ;
return - V_141 ;
}
if ( F_84 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_177 ;
if ( * V_113 != sizeof( struct V_233 ) + V_191 . V_132 ) {
F_8 ( L_62 ,
* V_113 , sizeof( V_191 ) + V_191 . V_132 ) ;
return - V_141 ;
}
F_86 ( V_83 ) ;
V_55 = F_88 ( V_78 , V_83 , V_191 . V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
struct V_73 V_2 ;
F_8 ( L_47 , V_74 -> V_164 ) ;
V_12 = F_81 ( V_74 , & V_2 ) ;
if ( ! V_12 && V_191 . V_132 == V_2 . V_132 ) {
V_12 = F_121 ( V_74 -> V_132 ,
V_55 , V_190 -> V_192 ) ;
} else if ( ! V_12 ) {
F_8 ( L_63 ,
V_74 -> V_132 , V_191 . V_132 ) ;
V_12 = - V_193 ;
}
F_90 ( V_83 ) ;
F_44 ( V_55 -> V_140 ) ;
F_91 ( V_55 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_188 ;
F_92 ( V_83 ) ;
return V_12 ;
}
static int
F_123 ( struct V_225 * V_226 , int V_227 , void T_4 * V_130 , int * V_113 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_234 :
V_12 = F_83 ( F_120 ( V_226 ) , V_130 , V_113 , 1 ) ;
break;
case V_235 :
V_12 = F_122 ( F_120 ( V_226 ) , V_130 , V_113 ) ;
break;
default:
V_12 = F_124 ( V_226 , V_227 , V_130 , V_113 ) ;
}
return V_12 ;
}
static int
F_125 ( struct V_225 * V_226 , int V_227 , void T_4 * V_130 , unsigned int V_113 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_231 :
V_12 = F_98 ( F_120 ( V_226 ) , V_130 , V_113 ) ;
break;
case V_232 :
V_12 = F_100 ( F_120 ( V_226 ) , V_130 , V_113 , 0 ) ;
break;
default:
F_8 ( L_60 , V_227 ) ;
V_12 = - V_141 ;
}
return V_12 ;
}
static int
F_124 ( struct V_225 * V_226 , int V_227 , void T_4 * V_130 , int * V_113 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_234 :
V_12 = F_83 ( F_120 ( V_226 ) , V_130 , V_113 , 0 ) ;
break;
case V_235 :
V_12 = F_93 ( F_120 ( V_226 ) , V_130 , V_113 ) ;
break;
case V_236 :
case V_237 : {
struct V_238 V_239 ;
int V_56 ;
if ( * V_113 != sizeof( V_239 ) ) {
V_12 = - V_141 ;
break;
}
if ( F_84 ( & V_239 , V_130 , sizeof( V_239 ) ) != 0 ) {
V_12 = - V_177 ;
break;
}
V_239 . V_59 [ sizeof( V_239 . V_59 ) - 1 ] = 0 ;
if ( V_227 == V_237 )
V_56 = 1 ;
else
V_56 = 0 ;
F_87 ( F_126 ( V_83 , V_239 . V_59 ,
V_239 . V_147 ,
V_56 , & V_12 ) ,
L_64 , V_239 . V_59 ) ;
break;
}
default:
F_8 ( L_65 , V_227 ) ;
V_12 = - V_141 ;
}
return V_12 ;
}
struct V_1 * F_127 ( struct V_78 * V_78 ,
const struct V_1 * V_87 ,
const struct V_161 * V_162 )
{
int V_12 ;
struct V_73 * V_123 ;
struct V_73 V_240 = { 0 } ;
void * V_176 ;
struct V_1 * V_241 ;
V_123 = F_99 ( V_162 -> V_132 ) ;
if ( ! V_123 ) {
V_12 = - V_171 ;
goto V_71;
}
V_176 = V_123 -> V_79 [ F_70 () ] ;
memcpy ( V_176 , V_162 -> V_79 , V_162 -> V_132 ) ;
V_12 = F_60 ( V_78 , V_123 , V_176 , V_162 ) ;
if ( V_12 != 0 )
goto V_242;
V_241 = F_128 ( V_78 , V_87 , & V_240 , V_123 ) ;
if ( F_50 ( V_241 ) ) {
V_12 = F_51 ( V_241 ) ;
goto V_242;
}
return V_241 ;
V_242:
F_96 ( V_123 ) ;
V_71:
return F_68 ( V_12 ) ;
}
void F_129 ( struct V_78 * V_78 , struct V_1 * V_87 )
{
struct V_73 * V_74 ;
void * V_176 ;
struct V_243 * V_244 = V_87 -> V_140 ;
struct V_43 * V_77 ;
V_74 = F_130 ( V_87 ) ;
V_176 = V_74 -> V_79 [ F_70 () ] ;
F_19 (iter, loc_cpu_entry, private->size)
F_59 ( V_77 , V_78 ) ;
if ( V_74 -> V_164 > V_74 -> V_183 )
F_44 ( V_244 ) ;
F_96 ( V_74 ) ;
}
static inline bool
F_131 ( T_7 V_245 , T_7 V_246 , T_7 V_247 ,
T_7 type , T_7 V_248 ,
bool V_249 )
{
return ( ( V_245 == 0xFF ) ||
( type == V_245 && V_248 >= V_246 && V_248 <= V_247 ) )
^ V_249 ;
}
static bool
F_132 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_250 * V_251 ;
struct V_250 V_252 ;
const struct V_253 * V_254 = V_40 -> V_111 ;
if ( V_40 -> V_97 != 0 )
return false ;
V_251 = F_133 ( V_38 , V_40 -> V_100 , sizeof( V_252 ) , & V_252 ) ;
if ( V_251 == NULL ) {
F_8 ( L_66 ) ;
V_40 -> V_101 = true ;
return false ;
}
return F_131 ( V_254 -> type ,
V_254 -> V_248 [ 0 ] ,
V_254 -> V_248 [ 1 ] ,
V_251 -> type , V_251 -> V_248 ,
! ! ( V_254 -> V_22 & V_255 ) ) ;
}
static int F_134 ( const struct V_143 * V_40 )
{
const struct V_253 * V_254 = V_40 -> V_111 ;
return ( V_254 -> V_22 & ~ V_255 ) ? - V_141 : 0 ;
}
static int T_8 F_135 ( struct V_78 * V_78 )
{
return F_136 ( V_78 , V_103 ) ;
}
static void T_9 F_137 ( struct V_78 * V_78 )
{
F_138 ( V_78 , V_103 ) ;
}
static int T_10 F_139 ( void )
{
int V_12 ;
V_12 = F_140 ( & V_256 ) ;
if ( V_12 < 0 )
goto V_257;
V_12 = F_141 ( V_258 , F_142 ( V_258 ) ) ;
if ( V_12 < 0 )
goto V_259;
V_12 = F_143 ( V_260 , F_142 ( V_260 ) ) ;
if ( V_12 < 0 )
goto V_261;
V_12 = F_144 ( & V_262 ) ;
if ( V_12 < 0 )
goto V_263;
F_145 ( L_67 ) ;
return 0 ;
V_263:
F_146 ( V_260 , F_142 ( V_260 ) ) ;
V_261:
F_147 ( V_258 , F_142 ( V_258 ) ) ;
V_259:
F_148 ( & V_256 ) ;
V_257:
return V_12 ;
}
static void T_11 F_149 ( void )
{
F_150 ( & V_262 ) ;
F_146 ( V_260 , F_142 ( V_260 ) ) ;
F_147 ( V_258 , F_142 ( V_258 ) ) ;
F_148 ( & V_256 ) ;
}
