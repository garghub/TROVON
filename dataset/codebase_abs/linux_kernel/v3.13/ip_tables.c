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
const struct V_69 * V_70 ,
const struct V_69 * V_71 ,
struct V_1 * V_85 )
{
static const char V_86 [ V_87 ] V_88 ( ( F_22 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_75 ;
struct V_43 * V_48 , * * V_89 ;
unsigned int * V_90 , V_91 , V_92 ;
const struct V_73 * V_74 ;
struct V_39 V_93 ;
unsigned int V_94 ;
V_6 = F_23 ( V_38 ) ;
V_7 = V_70 ? V_70 -> V_59 : V_86 ;
V_8 = V_71 ? V_71 -> V_59 : V_86 ;
V_93 . V_95 = F_24 ( V_6 -> V_96 ) & V_97 ;
V_93 . V_98 = F_25 ( V_38 ) ;
V_93 . V_99 = false ;
V_93 . V_70 = V_70 ;
V_93 . V_71 = V_71 ;
V_93 . V_100 = V_101 ;
V_93 . V_102 = V_68 ;
F_26 ( V_85 -> V_103 & ( 1 << V_68 ) ) ;
F_27 () ;
V_94 = F_28 () ;
V_74 = V_85 -> V_74 ;
V_92 = F_18 () ;
F_29 () ;
V_75 = V_74 -> V_79 [ V_92 ] ;
V_89 = (struct V_43 * * ) V_74 -> V_89 [ V_92 ] ;
V_90 = F_30 ( V_74 -> V_90 , V_92 ) ;
V_91 = * V_90 ;
V_48 = F_11 ( V_75 , V_74 -> V_80 [ V_68 ] ) ;
F_31 ( L_14 ,
V_85 -> V_59 , V_68 , V_91 ,
F_11 ( V_75 , V_74 -> V_104 [ V_68 ] ) ) ;
do {
const struct V_47 * V_55 ;
const struct V_105 * V_106 ;
F_26 ( V_48 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_48 -> V_6 , V_93 . V_95 ) ) {
V_107:
V_48 = F_32 ( V_48 ) ;
continue;
}
F_33 (ematch, e) {
V_93 . V_108 = V_106 -> V_57 . V_58 . V_108 ;
V_93 . V_109 = V_106 -> V_61 ;
if ( ! V_93 . V_108 -> V_108 ( V_38 , & V_93 ) )
goto V_107;
}
F_34 ( V_48 -> V_110 , V_38 -> V_111 , 1 ) ;
V_55 = F_14 ( V_48 ) ;
F_26 ( V_55 -> V_57 . V_58 . V_56 ) ;
#if F_35 ( V_112 )
if ( F_36 ( V_38 -> V_113 ) )
F_16 ( V_38 , V_68 , V_70 , V_71 ,
V_85 -> V_59 , V_74 , V_48 ) ;
#endif
if ( ! V_55 -> V_57 . V_58 . V_56 -> V_56 ) {
int V_114 ;
V_114 = ( (struct V_54 * ) V_55 ) -> V_64 ;
if ( V_114 < 0 ) {
if ( V_114 != V_115 ) {
V_64 = ( unsigned int ) ( - V_114 ) - 1 ;
break;
}
if ( * V_90 <= V_91 ) {
V_48 = F_11 ( V_75 ,
V_74 -> V_104 [ V_68 ] ) ;
F_31 ( L_15
L_16 , V_48 ) ;
} else {
V_48 = V_89 [ -- * V_90 ] ;
F_31 ( L_17 ,
V_48 , * V_90 ) ;
V_48 = F_32 ( V_48 ) ;
}
continue;
}
if ( V_75 + V_114 != F_32 ( V_48 ) &&
! ( V_48 -> V_6 . V_32 & V_116 ) ) {
if ( * V_90 >= V_74 -> V_117 ) {
V_64 = V_42 ;
break;
}
V_89 [ ( * V_90 ) ++ ] = V_48 ;
F_31 ( L_18 ,
V_48 , * V_90 - 1 ) ;
}
V_48 = F_11 ( V_75 , V_114 ) ;
continue;
}
V_93 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_93 . V_41 = V_55 -> V_61 ;
V_64 = V_55 -> V_57 . V_58 . V_56 -> V_56 ( V_38 , & V_93 ) ;
V_6 = F_23 ( V_38 ) ;
if ( V_64 == V_118 )
V_48 = F_32 ( V_48 ) ;
else
break;
} while ( ! V_93 . V_99 );
F_31 ( L_19 ,
V_119 , * V_90 , V_91 ) ;
* V_90 = V_91 ;
F_37 ( V_94 ) ;
F_38 () ;
#ifdef F_39
return V_120 ;
#else
if ( V_93 . V_99 )
return V_42 ;
else return V_64 ;
#endif
}
static int
F_40 ( const struct V_73 * V_121 ,
unsigned int V_103 , void * V_122 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_123 ; V_68 ++ ) {
unsigned int V_124 = V_121 -> V_80 [ V_68 ] ;
struct V_43 * V_48 = (struct V_43 * ) ( V_122 + V_124 ) ;
if ( ! ( V_103 & ( 1 << V_68 ) ) )
continue;
V_48 -> V_110 . V_125 = V_124 ;
for (; ; ) {
const struct V_54 * V_55
= ( void * ) F_13 ( V_48 ) ;
int V_126 = V_48 -> V_127 & ( 1 << V_68 ) ;
if ( V_48 -> V_127 & ( 1 << V_123 ) ) {
F_41 ( L_20 ,
V_68 , V_124 , V_48 -> V_127 ) ;
return 0 ;
}
V_48 -> V_127 |= ( ( 1 << V_68 ) | ( 1 << V_123 ) ) ;
if ( ( V_48 -> V_62 == sizeof( struct V_43 ) &&
( strcmp ( V_55 -> V_56 . V_57 . V_128 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < 0 && F_12 ( & V_48 -> V_6 ) ) ||
V_126 ) {
unsigned int V_129 , V_130 ;
if ( ( strcmp ( V_55 -> V_56 . V_57 . V_128 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < - V_131 - 1 ) {
F_8 ( L_21
L_22 ,
V_55 -> V_64 ) ;
return 0 ;
}
do {
V_48 -> V_127 ^= ( 1 << V_123 ) ;
#ifdef F_42
if ( V_48 -> V_127
& ( 1 << V_123 ) ) {
F_8 ( L_23
L_24
L_25 ,
V_68 , V_124 ) ;
}
#endif
V_129 = V_124 ;
V_124 = V_48 -> V_110 . V_125 ;
V_48 -> V_110 . V_125 = 0 ;
if ( V_124 == V_129 )
goto V_132;
V_48 = (struct V_43 * )
( V_122 + V_124 ) ;
} while ( V_129 == V_124 + V_48 -> V_133 );
V_130 = V_48 -> V_133 ;
V_48 = (struct V_43 * )
( V_122 + V_124 + V_130 ) ;
V_48 -> V_110 . V_125 = V_124 ;
V_124 += V_130 ;
} else {
int V_134 = V_55 -> V_64 ;
if ( strcmp ( V_55 -> V_56 . V_57 . V_128 . V_59 ,
V_63 ) == 0 &&
V_134 >= 0 ) {
if ( V_134 > V_121 -> V_130 -
sizeof( struct V_43 ) ) {
F_8 ( L_26
L_27 ,
V_134 ) ;
return 0 ;
}
F_8 ( L_28 ,
V_124 , V_134 ) ;
} else {
V_134 = V_124 + V_48 -> V_133 ;
}
V_48 = (struct V_43 * )
( V_122 + V_134 ) ;
V_48 -> V_110 . V_125 = V_124 ;
V_124 = V_134 ;
}
}
V_132:
F_8 ( L_29 , V_68 ) ;
}
return 1 ;
}
static void F_43 ( struct V_105 * V_135 , struct V_78 * V_78 )
{
struct V_136 V_40 ;
V_40 . V_78 = V_78 ;
V_40 . V_108 = V_135 -> V_57 . V_58 . V_108 ;
V_40 . V_109 = V_135 -> V_61 ;
V_40 . V_100 = V_101 ;
if ( V_40 . V_108 -> V_137 != NULL )
V_40 . V_108 -> V_137 ( & V_40 ) ;
F_44 ( V_40 . V_108 -> V_138 ) ;
}
static int
F_45 ( const struct V_43 * V_48 , const char * V_59 )
{
const struct V_47 * V_55 ;
if ( ! F_7 ( & V_48 -> V_6 ) ) {
F_8 ( L_30 , V_48 , V_59 ) ;
return - V_139 ;
}
if ( V_48 -> V_62 + sizeof( struct V_47 ) >
V_48 -> V_133 )
return - V_139 ;
V_55 = F_13 ( V_48 ) ;
if ( V_48 -> V_62 + V_55 -> V_57 . V_140 > V_48 -> V_133 )
return - V_139 ;
return 0 ;
}
static int
F_46 ( struct V_105 * V_135 , struct V_141 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_142 ;
int V_12 ;
V_40 -> V_108 = V_135 -> V_57 . V_58 . V_108 ;
V_40 -> V_109 = V_135 -> V_61 ;
V_12 = F_47 ( V_40 , V_135 -> V_57 . V_143 - sizeof( * V_135 ) ,
V_6 -> V_29 , V_6 -> V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 , V_40 -> V_108 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_48 ( struct V_105 * V_135 , struct V_141 * V_40 )
{
struct V_144 * V_108 ;
int V_12 ;
V_108 = F_49 ( V_101 , V_135 -> V_57 . V_128 . V_59 ,
V_135 -> V_57 . V_128 . V_145 ) ;
if ( F_50 ( V_108 ) ) {
F_8 ( L_32 , V_135 -> V_57 . V_128 . V_59 ) ;
return F_51 ( V_108 ) ;
}
V_135 -> V_57 . V_58 . V_108 = V_108 ;
V_12 = F_46 ( V_135 , V_40 ) ;
if ( V_12 )
goto V_146;
return 0 ;
V_146:
F_44 ( V_135 -> V_57 . V_58 . V_108 -> V_138 ) ;
return V_12 ;
}
static int F_52 ( struct V_43 * V_48 , struct V_78 * V_78 , const char * V_59 )
{
struct V_47 * V_55 = F_14 ( V_48 ) ;
struct V_147 V_40 = {
. V_78 = V_78 ,
. V_85 = V_59 ,
. V_142 = V_48 ,
. V_56 = V_55 -> V_57 . V_58 . V_56 ,
. V_41 = V_55 -> V_61 ,
. V_148 = V_48 -> V_127 ,
. V_100 = V_101 ,
} ;
int V_12 ;
V_12 = F_53 ( & V_40 , V_55 -> V_57 . V_140 - sizeof( * V_55 ) ,
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
unsigned int V_130 )
{
struct V_47 * V_55 ;
struct V_149 * V_56 ;
int V_12 ;
unsigned int V_150 ;
struct V_141 V_151 ;
struct V_105 * V_106 ;
V_12 = F_45 ( V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_150 = 0 ;
V_151 . V_78 = V_78 ;
V_151 . V_85 = V_59 ;
V_151 . V_142 = & V_48 -> V_6 ;
V_151 . V_148 = V_48 -> V_127 ;
V_151 . V_100 = V_101 ;
F_33 (ematch, e) {
V_12 = F_48 ( V_106 , & V_151 ) ;
if ( V_12 != 0 )
goto V_152;
++ V_150 ;
}
V_55 = F_14 ( V_48 ) ;
V_56 = F_55 ( V_101 , V_55 -> V_57 . V_128 . V_59 ,
V_55 -> V_57 . V_128 . V_145 ) ;
if ( F_50 ( V_56 ) ) {
F_8 ( L_33 , V_55 -> V_57 . V_128 . V_59 ) ;
V_12 = F_51 ( V_56 ) ;
goto V_152;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_12 = F_52 ( V_48 , V_78 , V_59 ) ;
if ( V_12 )
goto V_146;
return 0 ;
V_146:
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_138 ) ;
V_152:
F_33 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_43 ( V_106 , V_78 ) ;
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
if ( strcmp ( V_55 -> V_57 . V_128 . V_59 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_54 * ) V_55 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_120 ;
}
static int
F_57 ( struct V_43 * V_48 ,
struct V_73 * V_121 ,
const unsigned char * V_44 ,
const unsigned char * V_153 ,
const unsigned int * V_154 ,
const unsigned int * V_155 ,
unsigned int V_103 )
{
unsigned int V_156 ;
if ( ( unsigned long ) V_48 % F_58 ( struct V_43 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_43 ) >= V_153 ) {
F_8 ( L_34 , V_48 ) ;
return - V_139 ;
}
if ( V_48 -> V_133
< sizeof( struct V_43 ) + sizeof( struct V_47 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_133 ) ;
return - V_139 ;
}
for ( V_156 = 0 ; V_156 < V_123 ; V_156 ++ ) {
if ( ! ( V_103 & ( 1 << V_156 ) ) )
continue;
if ( ( unsigned char * ) V_48 - V_44 == V_154 [ V_156 ] )
V_121 -> V_80 [ V_156 ] = V_154 [ V_156 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_155 [ V_156 ] ) {
if ( ! F_56 ( V_48 ) ) {
F_41 ( L_36
L_37
L_38 ) ;
return - V_139 ;
}
V_121 -> V_104 [ V_156 ] = V_155 [ V_156 ] ;
}
}
V_48 -> V_110 = ( (struct V_157 ) { 0 , 0 } ) ;
V_48 -> V_127 = 0 ;
return 0 ;
}
static void
F_59 ( struct V_43 * V_48 , struct V_78 * V_78 )
{
struct V_158 V_40 ;
struct V_47 * V_55 ;
struct V_105 * V_106 ;
F_33 (ematch, e)
F_43 ( V_106 , V_78 ) ;
V_55 = F_14 ( V_48 ) ;
V_40 . V_78 = V_78 ;
V_40 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_40 . V_41 = V_55 -> V_61 ;
V_40 . V_100 = V_101 ;
if ( V_40 . V_56 -> V_137 != NULL )
V_40 . V_56 -> V_137 ( & V_40 ) ;
F_44 ( V_40 . V_56 -> V_138 ) ;
}
static int
F_60 ( struct V_78 * V_78 , struct V_73 * V_121 , void * V_122 ,
const struct V_159 * V_160 )
{
struct V_43 * V_77 ;
unsigned int V_161 ;
int V_12 = 0 ;
V_121 -> V_130 = V_160 -> V_130 ;
V_121 -> V_162 = V_160 -> V_163 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_121 -> V_80 [ V_161 ] = 0xFFFFFFFF ;
V_121 -> V_104 [ V_161 ] = 0xFFFFFFFF ;
}
F_8 ( L_39 , V_121 -> V_130 ) ;
V_161 = 0 ;
F_19 (iter, entry0, newinfo->size) {
V_12 = F_57 ( V_77 , V_121 , V_122 ,
V_122 + V_160 -> V_130 ,
V_160 -> V_80 ,
V_160 -> V_104 ,
V_160 -> V_103 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_161 ;
if ( strcmp ( F_14 ( V_77 ) -> V_57 . V_128 . V_59 ,
V_60 ) == 0 )
++ V_121 -> V_117 ;
}
if ( V_161 != V_160 -> V_163 ) {
F_8 ( L_40 ,
V_161 , V_160 -> V_163 ) ;
return - V_139 ;
}
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ! ( V_160 -> V_103 & ( 1 << V_161 ) ) )
continue;
if ( V_121 -> V_80 [ V_161 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_161 , V_160 -> V_80 [ V_161 ] ) ;
return - V_139 ;
}
if ( V_121 -> V_104 [ V_161 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_161 , V_160 -> V_104 [ V_161 ] ) ;
return - V_139 ;
}
}
if ( ! F_40 ( V_121 , V_160 -> V_103 , V_122 ) )
return - V_164 ;
V_161 = 0 ;
F_19 (iter, entry0, newinfo->size) {
V_12 = F_54 ( V_77 , V_78 , V_160 -> V_59 , V_160 -> V_130 ) ;
if ( V_12 != 0 )
break;
++ V_161 ;
}
if ( V_12 != 0 ) {
F_19 (iter, entry0, newinfo->size) {
if ( V_161 -- == 0 )
break;
F_59 ( V_77 , V_78 ) ;
}
return V_12 ;
}
F_61 (i) {
if ( V_121 -> V_79 [ V_161 ] && V_121 -> V_79 [ V_161 ] != V_122 )
memcpy ( V_121 -> V_79 [ V_161 ] , V_122 , V_121 -> V_130 ) ;
}
return V_12 ;
}
static void
F_62 ( const struct V_73 * V_55 ,
struct V_157 V_110 [] )
{
struct V_43 * V_77 ;
unsigned int V_92 ;
unsigned int V_161 ;
F_61 (cpu) {
T_2 * V_49 = & F_63 ( V_165 , V_92 ) ;
V_161 = 0 ;
F_19 (iter, t->entries[cpu], t->size) {
T_3 V_166 , V_125 ;
unsigned int V_167 ;
do {
V_167 = F_64 ( V_49 ) ;
V_166 = V_77 -> V_110 . V_166 ;
V_125 = V_77 -> V_110 . V_125 ;
} while ( F_65 ( V_49 , V_167 ) );
F_34 ( V_110 [ V_161 ] , V_166 , V_125 ) ;
++ V_161 ;
}
}
}
static struct V_157 * F_66 ( const struct V_1 * V_85 )
{
unsigned int V_168 ;
struct V_157 * V_110 ;
const struct V_73 * V_74 = V_85 -> V_74 ;
V_168 = sizeof( struct V_157 ) * V_74 -> V_162 ;
V_110 = F_67 ( V_168 ) ;
if ( V_110 == NULL )
return F_68 ( - V_169 ) ;
F_62 ( V_74 , V_110 ) ;
return V_110 ;
}
static int
F_69 ( unsigned int V_170 ,
const struct V_1 * V_85 ,
void T_4 * V_171 )
{
unsigned int V_172 , V_173 ;
const struct V_43 * V_48 ;
struct V_157 * V_110 ;
const struct V_73 * V_74 = V_85 -> V_74 ;
int V_12 = 0 ;
const void * V_174 ;
V_110 = F_66 ( V_85 ) ;
if ( F_50 ( V_110 ) )
return F_51 ( V_110 ) ;
V_174 = V_74 -> V_79 [ F_70 () ] ;
if ( F_71 ( V_171 , V_174 , V_170 ) != 0 ) {
V_12 = - V_175 ;
goto V_176;
}
for ( V_172 = 0 , V_173 = 0 ; V_172 < V_170 ; V_172 += V_48 -> V_133 , V_173 ++ ) {
unsigned int V_161 ;
const struct V_105 * V_135 ;
const struct V_47 * V_55 ;
V_48 = (struct V_43 * ) ( V_174 + V_172 ) ;
if ( F_71 ( V_171 + V_172
+ F_72 ( struct V_43 , V_110 ) ,
& V_110 [ V_173 ] ,
sizeof( V_110 [ V_173 ] ) ) != 0 ) {
V_12 = - V_175 ;
goto V_176;
}
for ( V_161 = sizeof( struct V_43 ) ;
V_161 < V_48 -> V_62 ;
V_161 += V_135 -> V_57 . V_143 ) {
V_135 = ( void * ) V_48 + V_161 ;
if ( F_71 ( V_171 + V_172 + V_161
+ F_72 ( struct V_105 ,
V_57 . V_128 . V_59 ) ,
V_135 -> V_57 . V_58 . V_108 -> V_59 ,
strlen ( V_135 -> V_57 . V_58 . V_108 -> V_59 ) + 1 )
!= 0 ) {
V_12 = - V_175 ;
goto V_176;
}
}
V_55 = F_13 ( V_48 ) ;
if ( F_71 ( V_171 + V_172 + V_48 -> V_62
+ F_72 ( struct V_47 ,
V_57 . V_128 . V_59 ) ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ,
strlen ( V_55 -> V_57 . V_58 . V_56 -> V_59 ) + 1 ) != 0 ) {
V_12 = - V_175 ;
goto V_176;
}
}
V_176:
F_73 ( V_110 ) ;
return V_12 ;
}
static void F_74 ( void * V_20 , const void * V_16 )
{
int V_114 = * ( V_177 * ) V_16 ;
if ( V_114 > 0 )
V_114 += F_75 ( V_83 , V_114 ) ;
memcpy ( V_20 , & V_114 , sizeof( V_114 ) ) ;
}
static int F_76 ( void T_4 * V_20 , const void * V_16 )
{
V_177 V_178 = * ( int * ) V_16 ;
if ( V_178 > 0 )
V_178 -= F_75 ( V_83 , V_178 ) ;
return F_71 ( V_20 , & V_178 , sizeof( V_178 ) ) ? - V_175 : 0 ;
}
static int F_77 ( const struct V_43 * V_48 ,
const struct V_73 * V_2 ,
const void * V_44 , struct V_73 * V_121 )
{
const struct V_105 * V_106 ;
const struct V_47 * V_55 ;
unsigned int V_179 ;
int V_172 , V_161 , V_12 ;
V_172 = sizeof( struct V_43 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_48 - V_44 ;
F_33 (ematch, e)
V_172 += F_78 ( V_106 -> V_57 . V_58 . V_108 ) ;
V_55 = F_13 ( V_48 ) ;
V_172 += F_79 ( V_55 -> V_57 . V_58 . V_56 ) ;
V_121 -> V_130 -= V_172 ;
V_12 = F_80 ( V_83 , V_179 , V_172 ) ;
if ( V_12 )
return V_12 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( V_2 -> V_80 [ V_161 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_80 [ V_161 ] ) ) )
V_121 -> V_80 [ V_161 ] -= V_172 ;
if ( V_2 -> V_104 [ V_161 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_104 [ V_161 ] ) ) )
V_121 -> V_104 [ V_161 ] -= V_172 ;
}
return 0 ;
}
static int F_81 ( const struct V_73 * V_2 ,
struct V_73 * V_121 )
{
struct V_43 * V_77 ;
void * V_174 ;
int V_12 ;
if ( ! V_121 || ! V_2 )
return - V_139 ;
memcpy ( V_121 , V_2 , F_72 ( struct V_73 , V_79 ) ) ;
V_121 -> V_181 = 0 ;
V_174 = V_2 -> V_79 [ F_70 () ] ;
F_82 ( V_83 , V_2 -> V_162 ) ;
F_19 (iter, loc_cpu_entry, info->size) {
V_12 = F_77 ( V_77 , V_2 , V_174 , V_121 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_83 ( struct V_78 * V_78 , void T_4 * V_128 ,
const int * V_111 , int V_182 )
{
char V_59 [ V_183 ] ;
struct V_1 * V_55 ;
int V_12 ;
if ( * V_111 != sizeof( struct V_184 ) ) {
F_8 ( L_43 , * V_111 ,
sizeof( struct V_184 ) ) ;
return - V_139 ;
}
if ( F_84 ( V_59 , V_128 , sizeof( V_59 ) ) != 0 )
return - V_175 ;
V_59 [ V_183 - 1 ] = '\0' ;
#ifdef F_85
if ( V_182 )
F_86 ( V_83 ) ;
#endif
V_55 = F_87 ( F_88 ( V_78 , V_83 , V_59 ) ,
L_44 , V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
struct V_184 V_2 ;
const struct V_73 * V_74 = V_55 -> V_74 ;
#ifdef F_85
struct V_73 V_185 ;
if ( V_182 ) {
V_12 = F_81 ( V_74 , & V_185 ) ;
F_90 ( V_83 ) ;
V_74 = & V_185 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_103 = V_55 -> V_103 ;
memcpy ( V_2 . V_80 , V_74 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_104 , V_74 -> V_104 ,
sizeof( V_2 . V_104 ) ) ;
V_2 . V_163 = V_74 -> V_162 ;
V_2 . V_130 = V_74 -> V_130 ;
strcpy ( V_2 . V_59 , V_59 ) ;
if ( F_71 ( V_128 , & V_2 , * V_111 ) != 0 )
V_12 = - V_175 ;
else
V_12 = 0 ;
F_91 ( V_55 ) ;
F_44 ( V_55 -> V_138 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_186 ;
#ifdef F_85
if ( V_182 )
F_92 ( V_83 ) ;
#endif
return V_12 ;
}
static int
F_93 ( struct V_78 * V_78 , struct V_187 T_4 * V_188 ,
const int * V_111 )
{
int V_12 ;
struct V_187 V_189 ;
struct V_1 * V_55 ;
if ( * V_111 < sizeof( V_189 ) ) {
F_8 ( L_45 , * V_111 , sizeof( V_189 ) ) ;
return - V_139 ;
}
if ( F_84 ( & V_189 , V_188 , sizeof( V_189 ) ) != 0 )
return - V_175 ;
if ( * V_111 != sizeof( struct V_187 ) + V_189 . V_130 ) {
F_8 ( L_46 ,
* V_111 , sizeof( V_189 ) + V_189 . V_130 ) ;
return - V_139 ;
}
V_55 = F_88 ( V_78 , V_83 , V_189 . V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
F_8 ( L_47 , V_74 -> V_162 ) ;
if ( V_189 . V_130 == V_74 -> V_130 )
V_12 = F_69 ( V_74 -> V_130 ,
V_55 , V_188 -> V_190 ) ;
else {
F_8 ( L_48 ,
V_74 -> V_130 , V_189 . V_130 ) ;
V_12 = - V_191 ;
}
F_44 ( V_55 -> V_138 ) ;
F_91 ( V_55 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_186 ;
return V_12 ;
}
static int
F_94 ( struct V_78 * V_78 , const char * V_59 , unsigned int V_103 ,
struct V_73 * V_121 , unsigned int V_192 ,
void T_4 * V_193 )
{
int V_12 ;
struct V_1 * V_55 ;
struct V_73 * V_194 ;
struct V_157 * V_110 ;
void * V_195 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_110 = F_67 ( V_192 * sizeof( struct V_157 ) ) ;
if ( ! V_110 ) {
V_12 = - V_169 ;
goto V_71;
}
V_55 = F_87 ( F_88 ( V_78 , V_83 , V_59 ) ,
L_44 , V_59 ) ;
if ( F_89 ( V_55 ) ) {
V_12 = V_55 ? F_51 ( V_55 ) : - V_186 ;
goto V_196;
}
if ( V_103 != V_55 -> V_103 ) {
F_8 ( L_49 ,
V_103 , V_55 -> V_103 ) ;
V_12 = - V_139 ;
goto V_197;
}
V_194 = F_95 ( V_55 , V_192 , V_121 , & V_12 ) ;
if ( ! V_194 )
goto V_197;
F_8 ( L_50 ,
V_194 -> V_162 , V_194 -> V_181 , V_121 -> V_162 ) ;
if ( ( V_194 -> V_162 > V_194 -> V_181 ) ||
( V_121 -> V_162 <= V_194 -> V_181 ) )
F_44 ( V_55 -> V_138 ) ;
if ( ( V_194 -> V_162 > V_194 -> V_181 ) &&
( V_121 -> V_162 <= V_194 -> V_181 ) )
F_44 ( V_55 -> V_138 ) ;
F_62 ( V_194 , V_110 ) ;
V_195 = V_194 -> V_79 [ F_70 () ] ;
F_19 (iter, loc_cpu_old_entry, oldinfo->size)
F_59 ( V_77 , V_78 ) ;
F_96 ( V_194 ) ;
if ( F_71 ( V_193 , V_110 ,
sizeof( struct V_157 ) * V_192 ) != 0 )
V_12 = - V_175 ;
F_73 ( V_110 ) ;
F_91 ( V_55 ) ;
return V_12 ;
V_197:
F_44 ( V_55 -> V_138 ) ;
F_91 ( V_55 ) ;
V_196:
F_73 ( V_110 ) ;
V_71:
return V_12 ;
}
static int
F_97 ( struct V_78 * V_78 , const void T_4 * V_128 , unsigned int V_111 )
{
int V_12 ;
struct V_159 V_185 ;
struct V_73 * V_121 ;
void * V_174 ;
struct V_43 * V_77 ;
if ( F_84 ( & V_185 , V_128 , sizeof( V_185 ) ) != 0 )
return - V_175 ;
if ( V_185 . V_192 >= V_198 / sizeof( struct V_157 ) )
return - V_169 ;
V_185 . V_59 [ sizeof( V_185 . V_59 ) - 1 ] = 0 ;
V_121 = F_98 ( V_185 . V_130 ) ;
if ( ! V_121 )
return - V_169 ;
V_174 = V_121 -> V_79 [ F_70 () ] ;
if ( F_84 ( V_174 , V_128 + sizeof( V_185 ) ,
V_185 . V_130 ) != 0 ) {
V_12 = - V_175 ;
goto V_199;
}
V_12 = F_60 ( V_78 , V_121 , V_174 , & V_185 ) ;
if ( V_12 != 0 )
goto V_199;
F_8 ( L_51 ) ;
V_12 = F_94 ( V_78 , V_185 . V_59 , V_185 . V_103 , V_121 ,
V_185 . V_192 , V_185 . V_110 ) ;
if ( V_12 )
goto V_200;
return 0 ;
V_200:
F_19 (iter, loc_cpu_entry, newinfo->size)
F_59 ( V_77 , V_78 ) ;
V_199:
F_96 ( V_121 ) ;
return V_12 ;
}
static int
F_99 ( struct V_78 * V_78 , const void T_4 * V_128 ,
unsigned int V_111 , int V_182 )
{
unsigned int V_161 , V_201 ;
struct V_202 V_185 ;
struct V_157 * V_203 ;
unsigned int V_192 ;
const char * V_59 ;
int V_130 ;
void * V_204 ;
struct V_1 * V_55 ;
const struct V_73 * V_74 ;
int V_12 = 0 ;
void * V_174 ;
struct V_43 * V_77 ;
unsigned int V_94 ;
#ifdef F_85
struct V_205 V_206 ;
if ( V_182 ) {
V_204 = & V_206 ;
V_130 = sizeof( struct V_205 ) ;
} else
#endif
{
V_204 = & V_185 ;
V_130 = sizeof( struct V_202 ) ;
}
if ( F_84 ( V_204 , V_128 , V_130 ) != 0 )
return - V_175 ;
#ifdef F_85
if ( V_182 ) {
V_192 = V_206 . V_192 ;
V_59 = V_206 . V_59 ;
} else
#endif
{
V_192 = V_185 . V_192 ;
V_59 = V_185 . V_59 ;
}
if ( V_111 != V_130 + V_192 * sizeof( struct V_157 ) )
return - V_139 ;
V_203 = F_100 ( V_111 - V_130 ) ;
if ( ! V_203 )
return - V_169 ;
if ( F_84 ( V_203 , V_128 + V_130 , V_111 - V_130 ) != 0 ) {
V_12 = - V_175 ;
goto free;
}
V_55 = F_88 ( V_78 , V_83 , V_59 ) ;
if ( F_89 ( V_55 ) ) {
V_12 = V_55 ? F_51 ( V_55 ) : - V_186 ;
goto free;
}
F_27 () ;
V_74 = V_55 -> V_74 ;
if ( V_74 -> V_162 != V_192 ) {
V_12 = - V_139 ;
goto V_207;
}
V_161 = 0 ;
V_201 = F_18 () ;
V_174 = V_74 -> V_79 [ V_201 ] ;
V_94 = F_28 () ;
F_19 (iter, loc_cpu_entry, private->size) {
F_34 ( V_77 -> V_110 , V_203 [ V_161 ] . V_166 , V_203 [ V_161 ] . V_125 ) ;
++ V_161 ;
}
F_37 ( V_94 ) ;
V_207:
F_38 () ;
F_91 ( V_55 ) ;
F_44 ( V_55 -> V_138 ) ;
free:
F_73 ( V_203 ) ;
return V_12 ;
}
static int
F_101 ( struct V_43 * V_48 , void T_4 * * V_208 ,
unsigned int * V_130 , struct V_157 * V_110 ,
unsigned int V_161 )
{
struct V_47 * V_55 ;
struct V_180 T_4 * V_209 ;
T_5 V_62 , V_133 ;
T_6 V_210 ;
const struct V_105 * V_106 ;
int V_12 = 0 ;
V_210 = * V_130 ;
V_209 = (struct V_180 T_4 * ) * V_208 ;
if ( F_71 ( V_209 , V_48 , sizeof( struct V_43 ) ) != 0 ||
F_71 ( & V_209 -> V_110 , & V_110 [ V_161 ] ,
sizeof( V_110 [ V_161 ] ) ) != 0 )
return - V_175 ;
* V_208 += sizeof( struct V_180 ) ;
* V_130 -= sizeof( struct V_43 ) - sizeof( struct V_180 ) ;
F_33 (ematch, e) {
V_12 = F_102 ( V_106 , V_208 , V_130 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_62 = V_48 -> V_62 - ( V_210 - * V_130 ) ;
V_55 = F_14 ( V_48 ) ;
V_12 = F_103 ( V_55 , V_208 , V_130 ) ;
if ( V_12 )
return V_12 ;
V_133 = V_48 -> V_133 - ( V_210 - * V_130 ) ;
if ( F_104 ( V_62 , & V_209 -> V_62 ) != 0 ||
F_104 ( V_133 , & V_209 -> V_133 ) != 0 )
return - V_175 ;
return 0 ;
}
static int
F_105 ( struct V_105 * V_135 ,
const char * V_59 ,
const struct V_9 * V_6 ,
unsigned int V_211 ,
int * V_130 )
{
struct V_144 * V_108 ;
V_108 = F_49 ( V_101 , V_135 -> V_57 . V_128 . V_59 ,
V_135 -> V_57 . V_128 . V_145 ) ;
if ( F_50 ( V_108 ) ) {
F_8 ( L_52 ,
V_135 -> V_57 . V_128 . V_59 ) ;
return F_51 ( V_108 ) ;
}
V_135 -> V_57 . V_58 . V_108 = V_108 ;
* V_130 += F_78 ( V_108 ) ;
return 0 ;
}
static void F_106 ( struct V_180 * V_48 )
{
struct V_47 * V_55 ;
struct V_105 * V_106 ;
F_33 (ematch, e)
F_44 ( V_106 -> V_57 . V_58 . V_108 -> V_138 ) ;
V_55 = F_107 ( V_48 ) ;
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_138 ) ;
}
static int
F_108 ( struct V_180 * V_48 ,
struct V_73 * V_121 ,
unsigned int * V_130 ,
const unsigned char * V_44 ,
const unsigned char * V_153 ,
const unsigned int * V_154 ,
const unsigned int * V_155 ,
const char * V_59 )
{
struct V_105 * V_106 ;
struct V_47 * V_55 ;
struct V_149 * V_56 ;
unsigned int V_179 ;
unsigned int V_150 ;
int V_12 , V_172 , V_156 ;
F_8 ( L_53 , V_48 ) ;
if ( ( unsigned long ) V_48 % F_58 ( struct V_180 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_180 ) >= V_153 ) {
F_8 ( L_54 , V_48 , V_153 ) ;
return - V_139 ;
}
if ( V_48 -> V_133 < sizeof( struct V_180 ) +
sizeof( struct V_212 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_133 ) ;
return - V_139 ;
}
V_12 = F_45 ( (struct V_43 * ) V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_172 = sizeof( struct V_43 ) - sizeof( struct V_180 ) ;
V_179 = ( void * ) V_48 - ( void * ) V_44 ;
V_150 = 0 ;
F_33 (ematch, e) {
V_12 = F_105 ( V_106 , V_59 ,
& V_48 -> V_6 , V_48 -> V_127 , & V_172 ) ;
if ( V_12 != 0 )
goto V_213;
++ V_150 ;
}
V_55 = F_107 ( V_48 ) ;
V_56 = F_55 ( V_101 , V_55 -> V_57 . V_128 . V_59 ,
V_55 -> V_57 . V_128 . V_145 ) ;
if ( F_50 ( V_56 ) ) {
F_8 ( L_55 ,
V_55 -> V_57 . V_128 . V_59 ) ;
V_12 = F_51 ( V_56 ) ;
goto V_213;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_172 += F_79 ( V_56 ) ;
* V_130 += V_172 ;
V_12 = F_80 ( V_83 , V_179 , V_172 ) ;
if ( V_12 )
goto V_71;
for ( V_156 = 0 ; V_156 < V_123 ; V_156 ++ ) {
if ( ( unsigned char * ) V_48 - V_44 == V_154 [ V_156 ] )
V_121 -> V_80 [ V_156 ] = V_154 [ V_156 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_155 [ V_156 ] )
V_121 -> V_104 [ V_156 ] = V_155 [ V_156 ] ;
}
memset ( & V_48 -> V_110 , 0 , sizeof( V_48 -> V_110 ) ) ;
V_48 -> V_127 = 0 ;
return 0 ;
V_71:
F_44 ( V_55 -> V_57 . V_58 . V_56 -> V_138 ) ;
V_213:
F_33 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_44 ( V_106 -> V_57 . V_58 . V_108 -> V_138 ) ;
}
return V_12 ;
}
static int
F_109 ( struct V_180 * V_48 , void * * V_208 ,
unsigned int * V_130 , const char * V_59 ,
struct V_73 * V_121 , unsigned char * V_44 )
{
struct V_47 * V_55 ;
struct V_149 * V_56 ;
struct V_43 * V_214 ;
unsigned int V_210 ;
int V_12 , V_156 ;
struct V_105 * V_106 ;
V_12 = 0 ;
V_210 = * V_130 ;
V_214 = (struct V_43 * ) * V_208 ;
memcpy ( V_214 , V_48 , sizeof( struct V_43 ) ) ;
memcpy ( & V_214 -> V_110 , & V_48 -> V_110 , sizeof( V_48 -> V_110 ) ) ;
* V_208 += sizeof( struct V_43 ) ;
* V_130 += sizeof( struct V_43 ) - sizeof( struct V_180 ) ;
F_33 (ematch, e) {
V_12 = F_110 ( V_106 , V_208 , V_130 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_214 -> V_62 = V_48 -> V_62 - ( V_210 - * V_130 ) ;
V_55 = F_107 ( V_48 ) ;
V_56 = V_55 -> V_57 . V_58 . V_56 ;
F_111 ( V_55 , V_208 , V_130 ) ;
V_214 -> V_133 = V_48 -> V_133 - ( V_210 - * V_130 ) ;
for ( V_156 = 0 ; V_156 < V_123 ; V_156 ++ ) {
if ( ( unsigned char * ) V_214 - V_44 < V_121 -> V_80 [ V_156 ] )
V_121 -> V_80 [ V_156 ] -= V_210 - * V_130 ;
if ( ( unsigned char * ) V_214 - V_44 < V_121 -> V_104 [ V_156 ] )
V_121 -> V_104 [ V_156 ] -= V_210 - * V_130 ;
}
return V_12 ;
}
static int
F_112 ( struct V_43 * V_48 , struct V_78 * V_78 , const char * V_59 )
{
struct V_105 * V_106 ;
struct V_141 V_151 ;
unsigned int V_150 ;
int V_12 = 0 ;
V_150 = 0 ;
V_151 . V_78 = V_78 ;
V_151 . V_85 = V_59 ;
V_151 . V_142 = & V_48 -> V_6 ;
V_151 . V_148 = V_48 -> V_127 ;
V_151 . V_100 = V_101 ;
F_33 (ematch, e) {
V_12 = F_46 ( V_106 , & V_151 ) ;
if ( V_12 != 0 )
goto V_152;
++ V_150 ;
}
V_12 = F_52 ( V_48 , V_78 , V_59 ) ;
if ( V_12 )
goto V_152;
return 0 ;
V_152:
F_33 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_43 ( V_106 , V_78 ) ;
}
return V_12 ;
}
static int
F_113 ( struct V_78 * V_78 ,
const char * V_59 ,
unsigned int V_103 ,
struct V_73 * * V_215 ,
void * * V_216 ,
unsigned int V_170 ,
unsigned int V_162 ,
unsigned int * V_154 ,
unsigned int * V_155 )
{
unsigned int V_161 , V_150 ;
struct V_73 * V_121 , * V_2 ;
void * V_124 , * V_122 , * V_217 ;
struct V_180 * V_218 ;
struct V_43 * V_219 ;
unsigned int V_130 ;
int V_12 ;
V_2 = * V_215 ;
V_122 = * V_216 ;
V_130 = V_170 ;
V_2 -> V_162 = V_162 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_2 -> V_80 [ V_161 ] = 0xFFFFFFFF ;
V_2 -> V_104 [ V_161 ] = 0xFFFFFFFF ;
}
F_8 ( L_56 , V_2 -> V_130 ) ;
V_150 = 0 ;
F_86 ( V_83 ) ;
F_82 ( V_83 , V_162 ) ;
F_19 (iter0, entry0, total_size) {
V_12 = F_108 ( V_218 , V_2 , & V_130 ,
V_122 ,
V_122 + V_170 ,
V_154 ,
V_155 ,
V_59 ) ;
if ( V_12 != 0 )
goto V_220;
++ V_150 ;
}
V_12 = - V_139 ;
if ( V_150 != V_162 ) {
F_8 ( L_57 ,
V_150 , V_162 ) ;
goto V_220;
}
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ! ( V_103 & ( 1 << V_161 ) ) )
continue;
if ( V_2 -> V_80 [ V_161 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_161 , V_154 [ V_161 ] ) ;
goto V_220;
}
if ( V_2 -> V_104 [ V_161 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_161 , V_155 [ V_161 ] ) ;
goto V_220;
}
}
V_12 = - V_169 ;
V_121 = F_98 ( V_130 ) ;
if ( ! V_121 )
goto V_220;
V_121 -> V_162 = V_162 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
V_121 -> V_80 [ V_161 ] = V_2 -> V_80 [ V_161 ] ;
V_121 -> V_104 [ V_161 ] = V_2 -> V_104 [ V_161 ] ;
}
V_217 = V_121 -> V_79 [ F_70 () ] ;
V_124 = V_217 ;
V_130 = V_170 ;
F_19 (iter0, entry0, total_size) {
V_12 = F_109 ( V_218 , & V_124 , & V_130 ,
V_59 , V_121 , V_217 ) ;
if ( V_12 != 0 )
break;
}
F_90 ( V_83 ) ;
F_92 ( V_83 ) ;
if ( V_12 )
goto V_199;
V_12 = - V_164 ;
if ( ! F_40 ( V_121 , V_103 , V_217 ) )
goto V_199;
V_161 = 0 ;
F_19 (iter1, entry1, newinfo->size) {
V_12 = F_112 ( V_219 , V_78 , V_59 ) ;
if ( V_12 != 0 )
break;
++ V_161 ;
if ( strcmp ( F_14 ( V_219 ) -> V_57 . V_128 . V_59 ,
V_60 ) == 0 )
++ V_121 -> V_117 ;
}
if ( V_12 ) {
int V_221 = V_161 ;
V_150 -= V_161 ;
F_19 (iter0, entry0, newinfo->size) {
if ( V_221 -- > 0 )
continue;
if ( V_150 -- == 0 )
break;
F_106 ( V_218 ) ;
}
F_19 (iter1, entry1, newinfo->size) {
if ( V_161 -- == 0 )
break;
F_59 ( V_219 , V_78 ) ;
}
F_96 ( V_121 ) ;
return V_12 ;
}
F_61 (i)
if ( V_121 -> V_79 [ V_161 ] && V_121 -> V_79 [ V_161 ] != V_217 )
memcpy ( V_121 -> V_79 [ V_161 ] , V_217 , V_121 -> V_130 ) ;
* V_215 = V_121 ;
* V_216 = V_217 ;
F_96 ( V_2 ) ;
return 0 ;
V_199:
F_96 ( V_121 ) ;
V_71:
F_19 (iter0, entry0, total_size) {
if ( V_150 -- == 0 )
break;
F_106 ( V_218 ) ;
}
return V_12 ;
V_220:
F_90 ( V_83 ) ;
F_92 ( V_83 ) ;
goto V_71;
}
static int
F_114 ( struct V_78 * V_78 , void T_4 * V_128 , unsigned int V_111 )
{
int V_12 ;
struct V_222 V_185 ;
struct V_73 * V_121 ;
void * V_174 ;
struct V_43 * V_77 ;
if ( F_84 ( & V_185 , V_128 , sizeof( V_185 ) ) != 0 )
return - V_175 ;
if ( V_185 . V_130 >= V_198 / F_115 () )
return - V_169 ;
if ( V_185 . V_192 >= V_198 / sizeof( struct V_157 ) )
return - V_169 ;
V_185 . V_59 [ sizeof( V_185 . V_59 ) - 1 ] = 0 ;
V_121 = F_98 ( V_185 . V_130 ) ;
if ( ! V_121 )
return - V_169 ;
V_174 = V_121 -> V_79 [ F_70 () ] ;
if ( F_84 ( V_174 , V_128 + sizeof( V_185 ) ,
V_185 . V_130 ) != 0 ) {
V_12 = - V_175 ;
goto V_199;
}
V_12 = F_113 ( V_78 , V_185 . V_59 , V_185 . V_103 ,
& V_121 , & V_174 , V_185 . V_130 ,
V_185 . V_163 , V_185 . V_80 ,
V_185 . V_104 ) ;
if ( V_12 != 0 )
goto V_199;
F_8 ( L_58 ) ;
V_12 = F_94 ( V_78 , V_185 . V_59 , V_185 . V_103 , V_121 ,
V_185 . V_192 , F_116 ( V_185 . V_110 ) ) ;
if ( V_12 )
goto V_200;
return 0 ;
V_200:
F_19 (iter, loc_cpu_entry, newinfo->size)
F_59 ( V_77 , V_78 ) ;
V_199:
F_96 ( V_121 ) ;
return V_12 ;
}
static int
F_117 ( struct V_223 * V_224 , int V_225 , void T_4 * V_128 ,
unsigned int V_111 )
{
int V_12 ;
if ( ! F_118 ( F_119 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_114 ( F_119 ( V_224 ) , V_128 , V_111 ) ;
break;
case V_230 :
V_12 = F_99 ( F_119 ( V_224 ) , V_128 , V_111 , 1 ) ;
break;
default:
F_8 ( L_59 , V_225 ) ;
V_12 = - V_139 ;
}
return V_12 ;
}
static int
F_120 ( unsigned int V_170 , struct V_1 * V_85 ,
void T_4 * V_171 )
{
struct V_157 * V_110 ;
const struct V_73 * V_74 = V_85 -> V_74 ;
void T_4 * V_124 ;
unsigned int V_130 ;
int V_12 = 0 ;
const void * V_174 ;
unsigned int V_161 = 0 ;
struct V_43 * V_77 ;
V_110 = F_66 ( V_85 ) ;
if ( F_50 ( V_110 ) )
return F_51 ( V_110 ) ;
V_174 = V_74 -> V_79 [ F_70 () ] ;
V_124 = V_171 ;
V_130 = V_170 ;
F_19 (iter, loc_cpu_entry, total_size) {
V_12 = F_101 ( V_77 , & V_124 ,
& V_130 , V_110 , V_161 ++ ) ;
if ( V_12 != 0 )
break;
}
F_73 ( V_110 ) ;
return V_12 ;
}
static int
F_121 ( struct V_78 * V_78 , struct V_231 T_4 * V_188 ,
int * V_111 )
{
int V_12 ;
struct V_231 V_189 ;
struct V_1 * V_55 ;
if ( * V_111 < sizeof( V_189 ) ) {
F_8 ( L_60 , * V_111 , sizeof( V_189 ) ) ;
return - V_139 ;
}
if ( F_84 ( & V_189 , V_188 , sizeof( V_189 ) ) != 0 )
return - V_175 ;
if ( * V_111 != sizeof( struct V_231 ) + V_189 . V_130 ) {
F_8 ( L_61 ,
* V_111 , sizeof( V_189 ) + V_189 . V_130 ) ;
return - V_139 ;
}
F_86 ( V_83 ) ;
V_55 = F_88 ( V_78 , V_83 , V_189 . V_59 ) ;
if ( ! F_89 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
struct V_73 V_2 ;
F_8 ( L_47 , V_74 -> V_162 ) ;
V_12 = F_81 ( V_74 , & V_2 ) ;
if ( ! V_12 && V_189 . V_130 == V_2 . V_130 ) {
V_12 = F_120 ( V_74 -> V_130 ,
V_55 , V_188 -> V_190 ) ;
} else if ( ! V_12 ) {
F_8 ( L_62 ,
V_74 -> V_130 , V_189 . V_130 ) ;
V_12 = - V_191 ;
}
F_90 ( V_83 ) ;
F_44 ( V_55 -> V_138 ) ;
F_91 ( V_55 ) ;
} else
V_12 = V_55 ? F_51 ( V_55 ) : - V_186 ;
F_92 ( V_83 ) ;
return V_12 ;
}
static int
F_122 ( struct V_223 * V_224 , int V_225 , void T_4 * V_128 , int * V_111 )
{
int V_12 ;
if ( ! F_118 ( F_119 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_83 ( F_119 ( V_224 ) , V_128 , V_111 , 1 ) ;
break;
case V_233 :
V_12 = F_121 ( F_119 ( V_224 ) , V_128 , V_111 ) ;
break;
default:
V_12 = F_123 ( V_224 , V_225 , V_128 , V_111 ) ;
}
return V_12 ;
}
static int
F_124 ( struct V_223 * V_224 , int V_225 , void T_4 * V_128 , unsigned int V_111 )
{
int V_12 ;
if ( ! F_118 ( F_119 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_97 ( F_119 ( V_224 ) , V_128 , V_111 ) ;
break;
case V_230 :
V_12 = F_99 ( F_119 ( V_224 ) , V_128 , V_111 , 0 ) ;
break;
default:
F_8 ( L_59 , V_225 ) ;
V_12 = - V_139 ;
}
return V_12 ;
}
static int
F_123 ( struct V_223 * V_224 , int V_225 , void T_4 * V_128 , int * V_111 )
{
int V_12 ;
if ( ! F_118 ( F_119 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_83 ( F_119 ( V_224 ) , V_128 , V_111 , 0 ) ;
break;
case V_233 :
V_12 = F_93 ( F_119 ( V_224 ) , V_128 , V_111 ) ;
break;
case V_234 :
case V_235 : {
struct V_236 V_237 ;
int V_56 ;
if ( * V_111 != sizeof( V_237 ) ) {
V_12 = - V_139 ;
break;
}
if ( F_84 ( & V_237 , V_128 , sizeof( V_237 ) ) != 0 ) {
V_12 = - V_175 ;
break;
}
V_237 . V_59 [ sizeof( V_237 . V_59 ) - 1 ] = 0 ;
if ( V_225 == V_235 )
V_56 = 1 ;
else
V_56 = 0 ;
F_87 ( F_125 ( V_83 , V_237 . V_59 ,
V_237 . V_145 ,
V_56 , & V_12 ) ,
L_63 , V_237 . V_59 ) ;
break;
}
default:
F_8 ( L_64 , V_225 ) ;
V_12 = - V_139 ;
}
return V_12 ;
}
struct V_1 * F_126 ( struct V_78 * V_78 ,
const struct V_1 * V_85 ,
const struct V_159 * V_160 )
{
int V_12 ;
struct V_73 * V_121 ;
struct V_73 V_238 = { 0 } ;
void * V_174 ;
struct V_1 * V_239 ;
V_121 = F_98 ( V_160 -> V_130 ) ;
if ( ! V_121 ) {
V_12 = - V_169 ;
goto V_71;
}
V_174 = V_121 -> V_79 [ F_70 () ] ;
memcpy ( V_174 , V_160 -> V_79 , V_160 -> V_130 ) ;
V_12 = F_60 ( V_78 , V_121 , V_174 , V_160 ) ;
if ( V_12 != 0 )
goto V_240;
V_239 = F_127 ( V_78 , V_85 , & V_238 , V_121 ) ;
if ( F_50 ( V_239 ) ) {
V_12 = F_51 ( V_239 ) ;
goto V_240;
}
return V_239 ;
V_240:
F_96 ( V_121 ) ;
V_71:
return F_68 ( V_12 ) ;
}
void F_128 ( struct V_78 * V_78 , struct V_1 * V_85 )
{
struct V_73 * V_74 ;
void * V_174 ;
struct V_241 * V_242 = V_85 -> V_138 ;
struct V_43 * V_77 ;
V_74 = F_129 ( V_85 ) ;
V_174 = V_74 -> V_79 [ F_70 () ] ;
F_19 (iter, loc_cpu_entry, private->size)
F_59 ( V_77 , V_78 ) ;
if ( V_74 -> V_162 > V_74 -> V_181 )
F_44 ( V_242 ) ;
F_96 ( V_74 ) ;
}
static inline bool
F_130 ( T_7 V_243 , T_7 V_244 , T_7 V_245 ,
T_7 type , T_7 V_246 ,
bool V_247 )
{
return ( ( V_243 == 0xFF ) ||
( type == V_243 && V_246 >= V_244 && V_246 <= V_245 ) )
^ V_247 ;
}
static bool
F_131 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_248 * V_249 ;
struct V_248 V_250 ;
const struct V_251 * V_252 = V_40 -> V_109 ;
if ( V_40 -> V_95 != 0 )
return false ;
V_249 = F_132 ( V_38 , V_40 -> V_98 , sizeof( V_250 ) , & V_250 ) ;
if ( V_249 == NULL ) {
F_8 ( L_65 ) ;
V_40 -> V_99 = true ;
return false ;
}
return F_130 ( V_252 -> type ,
V_252 -> V_246 [ 0 ] ,
V_252 -> V_246 [ 1 ] ,
V_249 -> type , V_249 -> V_246 ,
! ! ( V_252 -> V_22 & V_253 ) ) ;
}
static int F_133 ( const struct V_141 * V_40 )
{
const struct V_251 * V_252 = V_40 -> V_109 ;
return ( V_252 -> V_22 & ~ V_253 ) ? - V_139 : 0 ;
}
static int T_8 F_134 ( struct V_78 * V_78 )
{
return F_135 ( V_78 , V_101 ) ;
}
static void T_9 F_136 ( struct V_78 * V_78 )
{
F_137 ( V_78 , V_101 ) ;
}
static int T_10 F_138 ( void )
{
int V_12 ;
V_12 = F_139 ( & V_254 ) ;
if ( V_12 < 0 )
goto V_255;
V_12 = F_140 ( V_256 , F_141 ( V_256 ) ) ;
if ( V_12 < 0 )
goto V_257;
V_12 = F_142 ( V_258 , F_141 ( V_258 ) ) ;
if ( V_12 < 0 )
goto V_259;
V_12 = F_143 ( & V_260 ) ;
if ( V_12 < 0 )
goto V_261;
F_144 ( L_66 ) ;
return 0 ;
V_261:
F_145 ( V_258 , F_141 ( V_258 ) ) ;
V_259:
F_146 ( V_256 , F_141 ( V_256 ) ) ;
V_257:
F_147 ( & V_254 ) ;
V_255:
return V_12 ;
}
static void T_11 F_148 ( void )
{
F_149 ( & V_260 ) ;
F_145 ( V_258 , F_141 ( V_258 ) ) ;
F_146 ( V_256 , F_141 ( V_256 ) ) ;
F_147 ( & V_254 ) ;
}
