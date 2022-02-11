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
V_75 = V_74 -> V_78 [ F_17 () ] ;
V_76 = F_11 ( V_75 , V_74 -> V_79 [ V_68 ] ) ;
V_50 = V_51 = V_80 [ V_68 ] ;
V_52 = V_65 [ V_81 ] ;
F_18 (iter, root, private->size - private->hook_entry[hook])
if ( F_15 ( V_77 , V_48 , V_50 ,
& V_51 , & V_52 , & V_53 ) != 0 )
break;
F_19 ( V_82 , V_68 , V_38 , V_70 , V_71 , & V_83 ,
L_13 ,
V_72 , V_51 , V_52 , V_53 ) ;
}
unsigned int
F_20 ( struct V_37 * V_38 ,
unsigned int V_68 ,
const struct V_69 * V_70 ,
const struct V_69 * V_71 ,
struct V_1 * V_84 )
{
static const char V_85 [ V_86 ] V_87 ( ( F_21 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_75 ;
struct V_43 * V_48 , * * V_88 ;
unsigned int * V_89 , V_90 , V_91 ;
const struct V_73 * V_74 ;
struct V_39 V_92 ;
unsigned int V_93 ;
V_6 = F_22 ( V_38 ) ;
V_7 = V_70 ? V_70 -> V_59 : V_85 ;
V_8 = V_71 ? V_71 -> V_59 : V_85 ;
V_92 . V_94 = F_23 ( V_6 -> V_95 ) & V_96 ;
V_92 . V_97 = F_24 ( V_38 ) ;
V_92 . V_98 = false ;
V_92 . V_70 = V_70 ;
V_92 . V_71 = V_71 ;
V_92 . V_99 = V_100 ;
V_92 . V_101 = V_68 ;
F_25 ( V_84 -> V_102 & ( 1 << V_68 ) ) ;
F_26 () ;
V_93 = F_27 () ;
V_74 = V_84 -> V_74 ;
V_91 = F_17 () ;
V_75 = V_74 -> V_78 [ V_91 ] ;
V_88 = (struct V_43 * * ) V_74 -> V_88 [ V_91 ] ;
V_89 = F_28 ( V_74 -> V_89 , V_91 ) ;
V_90 = * V_89 ;
V_48 = F_11 ( V_75 , V_74 -> V_79 [ V_68 ] ) ;
F_29 ( L_14 ,
V_84 -> V_59 , V_68 , V_90 ,
F_11 ( V_75 , V_74 -> V_103 [ V_68 ] ) ) ;
do {
const struct V_47 * V_55 ;
const struct V_104 * V_105 ;
F_25 ( V_48 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_48 -> V_6 , V_92 . V_94 ) ) {
V_106:
V_48 = F_30 ( V_48 ) ;
continue;
}
F_31 (ematch, e) {
V_92 . V_107 = V_105 -> V_57 . V_58 . V_107 ;
V_92 . V_108 = V_105 -> V_61 ;
if ( ! V_92 . V_107 -> V_107 ( V_38 , & V_92 ) )
goto V_106;
}
F_32 ( V_48 -> V_109 , V_38 -> V_110 , 1 ) ;
V_55 = F_14 ( V_48 ) ;
F_25 ( V_55 -> V_57 . V_58 . V_56 ) ;
#if F_33 ( V_111 ) || \
F_33 ( V_112 )
if ( F_34 ( V_38 -> V_113 ) )
F_16 ( V_38 , V_68 , V_70 , V_71 ,
V_84 -> V_59 , V_74 , V_48 ) ;
#endif
if ( ! V_55 -> V_57 . V_58 . V_56 -> V_56 ) {
int V_114 ;
V_114 = ( (struct V_54 * ) V_55 ) -> V_64 ;
if ( V_114 < 0 ) {
if ( V_114 != V_115 ) {
V_64 = ( unsigned int ) ( - V_114 ) - 1 ;
break;
}
if ( * V_89 <= V_90 ) {
V_48 = F_11 ( V_75 ,
V_74 -> V_103 [ V_68 ] ) ;
F_29 ( L_15
L_16 , V_48 ) ;
} else {
V_48 = V_88 [ -- * V_89 ] ;
F_29 ( L_17 ,
V_48 , * V_89 ) ;
V_48 = F_30 ( V_48 ) ;
}
continue;
}
if ( V_75 + V_114 != F_30 ( V_48 ) &&
! ( V_48 -> V_6 . V_32 & V_116 ) ) {
if ( * V_89 >= V_74 -> V_117 ) {
V_64 = V_42 ;
break;
}
V_88 [ ( * V_89 ) ++ ] = V_48 ;
F_29 ( L_18 ,
V_48 , * V_89 - 1 ) ;
}
V_48 = F_11 ( V_75 , V_114 ) ;
continue;
}
V_92 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_92 . V_41 = V_55 -> V_61 ;
V_64 = V_55 -> V_57 . V_58 . V_56 -> V_56 ( V_38 , & V_92 ) ;
V_6 = F_22 ( V_38 ) ;
if ( V_64 == V_118 )
V_48 = F_30 ( V_48 ) ;
else
break;
} while ( ! V_92 . V_98 );
F_29 ( L_19 ,
V_119 , * V_89 , V_90 ) ;
* V_89 = V_90 ;
F_35 ( V_93 ) ;
F_36 () ;
#ifdef F_37
return V_120 ;
#else
if ( V_92 . V_98 )
return V_42 ;
else return V_64 ;
#endif
}
static int
F_38 ( const struct V_73 * V_121 ,
unsigned int V_102 , void * V_122 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_123 ; V_68 ++ ) {
unsigned int V_124 = V_121 -> V_79 [ V_68 ] ;
struct V_43 * V_48 = (struct V_43 * ) ( V_122 + V_124 ) ;
if ( ! ( V_102 & ( 1 << V_68 ) ) )
continue;
V_48 -> V_109 . V_125 = V_124 ;
for (; ; ) {
const struct V_54 * V_55
= ( void * ) F_13 ( V_48 ) ;
int V_126 = V_48 -> V_127 & ( 1 << V_68 ) ;
if ( V_48 -> V_127 & ( 1 << V_123 ) ) {
F_39 ( L_20 ,
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
#ifdef F_40
if ( V_48 -> V_127
& ( 1 << V_123 ) ) {
F_8 ( L_23
L_24
L_25 ,
V_68 , V_124 ) ;
}
#endif
V_129 = V_124 ;
V_124 = V_48 -> V_109 . V_125 ;
V_48 -> V_109 . V_125 = 0 ;
if ( V_124 == V_129 )
goto V_132;
V_48 = (struct V_43 * )
( V_122 + V_124 ) ;
} while ( V_129 == V_124 + V_48 -> V_133 );
V_130 = V_48 -> V_133 ;
V_48 = (struct V_43 * )
( V_122 + V_124 + V_130 ) ;
V_48 -> V_109 . V_125 = V_124 ;
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
V_48 -> V_109 . V_125 = V_124 ;
V_124 = V_134 ;
}
}
V_132:
F_8 ( L_29 , V_68 ) ;
}
return 1 ;
}
static void F_41 ( struct V_104 * V_135 , struct V_136 * V_136 )
{
struct V_137 V_40 ;
V_40 . V_136 = V_136 ;
V_40 . V_107 = V_135 -> V_57 . V_58 . V_107 ;
V_40 . V_108 = V_135 -> V_61 ;
V_40 . V_99 = V_100 ;
if ( V_40 . V_107 -> V_138 != NULL )
V_40 . V_107 -> V_138 ( & V_40 ) ;
F_42 ( V_40 . V_107 -> V_139 ) ;
}
static int
F_43 ( const struct V_43 * V_48 , const char * V_59 )
{
const struct V_47 * V_55 ;
if ( ! F_7 ( & V_48 -> V_6 ) ) {
F_8 ( L_30 , V_48 , V_59 ) ;
return - V_140 ;
}
if ( V_48 -> V_62 + sizeof( struct V_47 ) >
V_48 -> V_133 )
return - V_140 ;
V_55 = F_13 ( V_48 ) ;
if ( V_48 -> V_62 + V_55 -> V_57 . V_141 > V_48 -> V_133 )
return - V_140 ;
return 0 ;
}
static int
F_44 ( struct V_104 * V_135 , struct V_142 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_143 ;
int V_12 ;
V_40 -> V_107 = V_135 -> V_57 . V_58 . V_107 ;
V_40 -> V_108 = V_135 -> V_61 ;
V_12 = F_45 ( V_40 , V_135 -> V_57 . V_144 - sizeof( * V_135 ) ,
V_6 -> V_29 , V_6 -> V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 , V_40 -> V_107 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_46 ( struct V_104 * V_135 , struct V_142 * V_40 )
{
struct V_145 * V_107 ;
int V_12 ;
V_107 = F_47 ( V_100 , V_135 -> V_57 . V_128 . V_59 ,
V_135 -> V_57 . V_128 . V_146 ) ;
if ( F_48 ( V_107 ) ) {
F_8 ( L_32 , V_135 -> V_57 . V_128 . V_59 ) ;
return F_49 ( V_107 ) ;
}
V_135 -> V_57 . V_58 . V_107 = V_107 ;
V_12 = F_44 ( V_135 , V_40 ) ;
if ( V_12 )
goto V_147;
return 0 ;
V_147:
F_42 ( V_135 -> V_57 . V_58 . V_107 -> V_139 ) ;
return V_12 ;
}
static int F_50 ( struct V_43 * V_48 , struct V_136 * V_136 , const char * V_59 )
{
struct V_47 * V_55 = F_14 ( V_48 ) ;
struct V_148 V_40 = {
. V_136 = V_136 ,
. V_84 = V_59 ,
. V_143 = V_48 ,
. V_56 = V_55 -> V_57 . V_58 . V_56 ,
. V_41 = V_55 -> V_61 ,
. V_149 = V_48 -> V_127 ,
. V_99 = V_100 ,
} ;
int V_12 ;
V_12 = F_51 ( & V_40 , V_55 -> V_57 . V_141 - sizeof( * V_55 ) ,
V_48 -> V_6 . V_29 , V_48 -> V_6 . V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_52 ( struct V_43 * V_48 , struct V_136 * V_136 , const char * V_59 ,
unsigned int V_130 )
{
struct V_47 * V_55 ;
struct V_150 * V_56 ;
int V_12 ;
unsigned int V_151 ;
struct V_142 V_152 ;
struct V_104 * V_105 ;
V_12 = F_43 ( V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_151 = 0 ;
V_152 . V_136 = V_136 ;
V_152 . V_84 = V_59 ;
V_152 . V_143 = & V_48 -> V_6 ;
V_152 . V_149 = V_48 -> V_127 ;
V_152 . V_99 = V_100 ;
F_31 (ematch, e) {
V_12 = F_46 ( V_105 , & V_152 ) ;
if ( V_12 != 0 )
goto V_153;
++ V_151 ;
}
V_55 = F_14 ( V_48 ) ;
V_56 = F_53 ( V_100 , V_55 -> V_57 . V_128 . V_59 ,
V_55 -> V_57 . V_128 . V_146 ) ;
if ( F_48 ( V_56 ) ) {
F_8 ( L_33 , V_55 -> V_57 . V_128 . V_59 ) ;
V_12 = F_49 ( V_56 ) ;
goto V_153;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_12 = F_50 ( V_48 , V_136 , V_59 ) ;
if ( V_12 )
goto V_147;
return 0 ;
V_147:
F_42 ( V_55 -> V_57 . V_58 . V_56 -> V_139 ) ;
V_153:
F_31 (ematch, e) {
if ( V_151 -- == 0 )
break;
F_41 ( V_105 , V_136 ) ;
}
return V_12 ;
}
static bool F_54 ( const struct V_43 * V_48 )
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
F_55 ( struct V_43 * V_48 ,
struct V_73 * V_121 ,
const unsigned char * V_44 ,
const unsigned char * V_154 ,
const unsigned int * V_155 ,
const unsigned int * V_156 ,
unsigned int V_102 )
{
unsigned int V_157 ;
if ( ( unsigned long ) V_48 % F_56 ( struct V_43 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_43 ) >= V_154 ) {
F_8 ( L_34 , V_48 ) ;
return - V_140 ;
}
if ( V_48 -> V_133
< sizeof( struct V_43 ) + sizeof( struct V_47 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_133 ) ;
return - V_140 ;
}
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ! ( V_102 & ( 1 << V_157 ) ) )
continue;
if ( ( unsigned char * ) V_48 - V_44 == V_155 [ V_157 ] )
V_121 -> V_79 [ V_157 ] = V_155 [ V_157 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_156 [ V_157 ] ) {
if ( ! F_54 ( V_48 ) ) {
F_39 ( L_36
L_37
L_38 ) ;
return - V_140 ;
}
V_121 -> V_103 [ V_157 ] = V_156 [ V_157 ] ;
}
}
V_48 -> V_109 = ( (struct V_158 ) { 0 , 0 } ) ;
V_48 -> V_127 = 0 ;
return 0 ;
}
static void
F_57 ( struct V_43 * V_48 , struct V_136 * V_136 )
{
struct V_159 V_40 ;
struct V_47 * V_55 ;
struct V_104 * V_105 ;
F_31 (ematch, e)
F_41 ( V_105 , V_136 ) ;
V_55 = F_14 ( V_48 ) ;
V_40 . V_136 = V_136 ;
V_40 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_40 . V_41 = V_55 -> V_61 ;
V_40 . V_99 = V_100 ;
if ( V_40 . V_56 -> V_138 != NULL )
V_40 . V_56 -> V_138 ( & V_40 ) ;
F_42 ( V_40 . V_56 -> V_139 ) ;
}
static int
F_58 ( struct V_136 * V_136 , struct V_73 * V_121 , void * V_122 ,
const struct V_160 * V_161 )
{
struct V_43 * V_77 ;
unsigned int V_162 ;
int V_12 = 0 ;
V_121 -> V_130 = V_161 -> V_130 ;
V_121 -> V_163 = V_161 -> V_164 ;
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
V_121 -> V_79 [ V_162 ] = 0xFFFFFFFF ;
V_121 -> V_103 [ V_162 ] = 0xFFFFFFFF ;
}
F_8 ( L_39 , V_121 -> V_130 ) ;
V_162 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_55 ( V_77 , V_121 , V_122 ,
V_122 + V_161 -> V_130 ,
V_161 -> V_79 ,
V_161 -> V_103 ,
V_161 -> V_102 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_162 ;
if ( strcmp ( F_14 ( V_77 ) -> V_57 . V_128 . V_59 ,
V_60 ) == 0 )
++ V_121 -> V_117 ;
}
if ( V_162 != V_161 -> V_164 ) {
F_8 ( L_40 ,
V_162 , V_161 -> V_164 ) ;
return - V_140 ;
}
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
if ( ! ( V_161 -> V_102 & ( 1 << V_162 ) ) )
continue;
if ( V_121 -> V_79 [ V_162 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_162 , V_161 -> V_79 [ V_162 ] ) ;
return - V_140 ;
}
if ( V_121 -> V_103 [ V_162 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_162 , V_161 -> V_103 [ V_162 ] ) ;
return - V_140 ;
}
}
if ( ! F_38 ( V_121 , V_161 -> V_102 , V_122 ) )
return - V_165 ;
V_162 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_52 ( V_77 , V_136 , V_161 -> V_59 , V_161 -> V_130 ) ;
if ( V_12 != 0 )
break;
++ V_162 ;
}
if ( V_12 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_162 -- == 0 )
break;
F_57 ( V_77 , V_136 ) ;
}
return V_12 ;
}
F_59 (i) {
if ( V_121 -> V_78 [ V_162 ] && V_121 -> V_78 [ V_162 ] != V_122 )
memcpy ( V_121 -> V_78 [ V_162 ] , V_122 , V_121 -> V_130 ) ;
}
return V_12 ;
}
static void
F_60 ( const struct V_73 * V_55 ,
struct V_158 V_109 [] )
{
struct V_43 * V_77 ;
unsigned int V_91 ;
unsigned int V_162 ;
F_59 (cpu) {
T_2 * V_49 = & F_61 ( V_166 , V_91 ) ;
V_162 = 0 ;
F_18 (iter, t->entries[cpu], t->size) {
T_3 V_167 , V_125 ;
unsigned int V_168 ;
do {
V_168 = F_62 ( V_49 ) ;
V_167 = V_77 -> V_109 . V_167 ;
V_125 = V_77 -> V_109 . V_125 ;
} while ( F_63 ( V_49 , V_168 ) );
F_32 ( V_109 [ V_162 ] , V_167 , V_125 ) ;
++ V_162 ;
}
}
}
static struct V_158 * F_64 ( const struct V_1 * V_84 )
{
unsigned int V_169 ;
struct V_158 * V_109 ;
const struct V_73 * V_74 = V_84 -> V_74 ;
V_169 = sizeof( struct V_158 ) * V_74 -> V_163 ;
V_109 = F_65 ( V_169 ) ;
if ( V_109 == NULL )
return F_66 ( - V_170 ) ;
F_60 ( V_74 , V_109 ) ;
return V_109 ;
}
static int
F_67 ( unsigned int V_171 ,
const struct V_1 * V_84 ,
void T_4 * V_172 )
{
unsigned int V_173 , V_174 ;
const struct V_43 * V_48 ;
struct V_158 * V_109 ;
const struct V_73 * V_74 = V_84 -> V_74 ;
int V_12 = 0 ;
const void * V_175 ;
V_109 = F_64 ( V_84 ) ;
if ( F_48 ( V_109 ) )
return F_49 ( V_109 ) ;
V_175 = V_74 -> V_78 [ F_68 () ] ;
if ( F_69 ( V_172 , V_175 , V_171 ) != 0 ) {
V_12 = - V_176 ;
goto V_177;
}
for ( V_173 = 0 , V_174 = 0 ; V_173 < V_171 ; V_173 += V_48 -> V_133 , V_174 ++ ) {
unsigned int V_162 ;
const struct V_104 * V_135 ;
const struct V_47 * V_55 ;
V_48 = (struct V_43 * ) ( V_175 + V_173 ) ;
if ( F_69 ( V_172 + V_173
+ F_70 ( struct V_43 , V_109 ) ,
& V_109 [ V_174 ] ,
sizeof( V_109 [ V_174 ] ) ) != 0 ) {
V_12 = - V_176 ;
goto V_177;
}
for ( V_162 = sizeof( struct V_43 ) ;
V_162 < V_48 -> V_62 ;
V_162 += V_135 -> V_57 . V_144 ) {
V_135 = ( void * ) V_48 + V_162 ;
if ( F_69 ( V_172 + V_173 + V_162
+ F_70 ( struct V_104 ,
V_57 . V_128 . V_59 ) ,
V_135 -> V_57 . V_58 . V_107 -> V_59 ,
strlen ( V_135 -> V_57 . V_58 . V_107 -> V_59 ) + 1 )
!= 0 ) {
V_12 = - V_176 ;
goto V_177;
}
}
V_55 = F_13 ( V_48 ) ;
if ( F_69 ( V_172 + V_173 + V_48 -> V_62
+ F_70 ( struct V_47 ,
V_57 . V_128 . V_59 ) ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ,
strlen ( V_55 -> V_57 . V_58 . V_56 -> V_59 ) + 1 ) != 0 ) {
V_12 = - V_176 ;
goto V_177;
}
}
V_177:
F_71 ( V_109 ) ;
return V_12 ;
}
static void F_72 ( void * V_20 , const void * V_16 )
{
int V_114 = * ( V_178 * ) V_16 ;
if ( V_114 > 0 )
V_114 += F_73 ( V_82 , V_114 ) ;
memcpy ( V_20 , & V_114 , sizeof( V_114 ) ) ;
}
static int F_74 ( void T_4 * V_20 , const void * V_16 )
{
V_178 V_179 = * ( int * ) V_16 ;
if ( V_179 > 0 )
V_179 -= F_73 ( V_82 , V_179 ) ;
return F_69 ( V_20 , & V_179 , sizeof( V_179 ) ) ? - V_176 : 0 ;
}
static int F_75 ( const struct V_43 * V_48 ,
const struct V_73 * V_2 ,
const void * V_44 , struct V_73 * V_121 )
{
const struct V_104 * V_105 ;
const struct V_47 * V_55 ;
unsigned int V_180 ;
int V_173 , V_162 , V_12 ;
V_173 = sizeof( struct V_43 ) - sizeof( struct V_181 ) ;
V_180 = ( void * ) V_48 - V_44 ;
F_31 (ematch, e)
V_173 += F_76 ( V_105 -> V_57 . V_58 . V_107 ) ;
V_55 = F_13 ( V_48 ) ;
V_173 += F_77 ( V_55 -> V_57 . V_58 . V_56 ) ;
V_121 -> V_130 -= V_173 ;
V_12 = F_78 ( V_82 , V_180 , V_173 ) ;
if ( V_12 )
return V_12 ;
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
if ( V_2 -> V_79 [ V_162 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_162 ] ) ) )
V_121 -> V_79 [ V_162 ] -= V_173 ;
if ( V_2 -> V_103 [ V_162 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_103 [ V_162 ] ) ) )
V_121 -> V_103 [ V_162 ] -= V_173 ;
}
return 0 ;
}
static int F_79 ( const struct V_73 * V_2 ,
struct V_73 * V_121 )
{
struct V_43 * V_77 ;
void * V_175 ;
int V_12 ;
if ( ! V_121 || ! V_2 )
return - V_140 ;
memcpy ( V_121 , V_2 , F_70 ( struct V_73 , V_78 ) ) ;
V_121 -> V_182 = 0 ;
V_175 = V_2 -> V_78 [ F_68 () ] ;
F_80 ( V_82 , V_2 -> V_163 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_12 = F_75 ( V_77 , V_2 , V_175 , V_121 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_81 ( struct V_136 * V_136 , void T_4 * V_128 ,
const int * V_110 , int V_183 )
{
char V_59 [ V_184 ] ;
struct V_1 * V_55 ;
int V_12 ;
if ( * V_110 != sizeof( struct V_185 ) ) {
F_8 ( L_43 , * V_110 ,
sizeof( struct V_185 ) ) ;
return - V_140 ;
}
if ( F_82 ( V_59 , V_128 , sizeof( V_59 ) ) != 0 )
return - V_176 ;
V_59 [ V_184 - 1 ] = '\0' ;
#ifdef F_83
if ( V_183 )
F_84 ( V_82 ) ;
#endif
V_55 = F_85 ( F_86 ( V_136 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( V_55 && ! F_48 ( V_55 ) ) {
struct V_185 V_2 ;
const struct V_73 * V_74 = V_55 -> V_74 ;
#ifdef F_83
struct V_73 V_186 ;
if ( V_183 ) {
V_12 = F_79 ( V_74 , & V_186 ) ;
F_87 ( V_82 ) ;
V_74 = & V_186 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_102 = V_55 -> V_102 ;
memcpy ( V_2 . V_79 , V_74 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_103 , V_74 -> V_103 ,
sizeof( V_2 . V_103 ) ) ;
V_2 . V_164 = V_74 -> V_163 ;
V_2 . V_130 = V_74 -> V_130 ;
strcpy ( V_2 . V_59 , V_59 ) ;
if ( F_69 ( V_128 , & V_2 , * V_110 ) != 0 )
V_12 = - V_176 ;
else
V_12 = 0 ;
F_88 ( V_55 ) ;
F_42 ( V_55 -> V_139 ) ;
} else
V_12 = V_55 ? F_49 ( V_55 ) : - V_187 ;
#ifdef F_83
if ( V_183 )
F_89 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_90 ( struct V_136 * V_136 , struct V_188 T_4 * V_189 ,
const int * V_110 )
{
int V_12 ;
struct V_188 V_190 ;
struct V_1 * V_55 ;
if ( * V_110 < sizeof( V_190 ) ) {
F_8 ( L_45 , * V_110 , sizeof( V_190 ) ) ;
return - V_140 ;
}
if ( F_82 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_176 ;
if ( * V_110 != sizeof( struct V_188 ) + V_190 . V_130 ) {
F_8 ( L_46 ,
* V_110 , sizeof( V_190 ) + V_190 . V_130 ) ;
return - V_140 ;
}
V_55 = F_86 ( V_136 , V_82 , V_190 . V_59 ) ;
if ( V_55 && ! F_48 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
F_8 ( L_47 , V_74 -> V_163 ) ;
if ( V_190 . V_130 == V_74 -> V_130 )
V_12 = F_67 ( V_74 -> V_130 ,
V_55 , V_189 -> V_191 ) ;
else {
F_8 ( L_48 ,
V_74 -> V_130 , V_190 . V_130 ) ;
V_12 = - V_192 ;
}
F_42 ( V_55 -> V_139 ) ;
F_88 ( V_55 ) ;
} else
V_12 = V_55 ? F_49 ( V_55 ) : - V_187 ;
return V_12 ;
}
static int
F_91 ( struct V_136 * V_136 , const char * V_59 , unsigned int V_102 ,
struct V_73 * V_121 , unsigned int V_193 ,
void T_4 * V_194 )
{
int V_12 ;
struct V_1 * V_55 ;
struct V_73 * V_195 ;
struct V_158 * V_109 ;
void * V_196 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_109 = F_65 ( V_193 * sizeof( struct V_158 ) ) ;
if ( ! V_109 ) {
V_12 = - V_170 ;
goto V_71;
}
V_55 = F_85 ( F_86 ( V_136 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( ! V_55 || F_48 ( V_55 ) ) {
V_12 = V_55 ? F_49 ( V_55 ) : - V_187 ;
goto V_197;
}
if ( V_102 != V_55 -> V_102 ) {
F_8 ( L_49 ,
V_102 , V_55 -> V_102 ) ;
V_12 = - V_140 ;
goto V_198;
}
V_195 = F_92 ( V_55 , V_193 , V_121 , & V_12 ) ;
if ( ! V_195 )
goto V_198;
F_8 ( L_50 ,
V_195 -> V_163 , V_195 -> V_182 , V_121 -> V_163 ) ;
if ( ( V_195 -> V_163 > V_195 -> V_182 ) ||
( V_121 -> V_163 <= V_195 -> V_182 ) )
F_42 ( V_55 -> V_139 ) ;
if ( ( V_195 -> V_163 > V_195 -> V_182 ) &&
( V_121 -> V_163 <= V_195 -> V_182 ) )
F_42 ( V_55 -> V_139 ) ;
F_60 ( V_195 , V_109 ) ;
V_196 = V_195 -> V_78 [ F_68 () ] ;
F_18 (iter, loc_cpu_old_entry, oldinfo->size)
F_57 ( V_77 , V_136 ) ;
F_93 ( V_195 ) ;
if ( F_69 ( V_194 , V_109 ,
sizeof( struct V_158 ) * V_193 ) != 0 )
V_12 = - V_176 ;
F_71 ( V_109 ) ;
F_88 ( V_55 ) ;
return V_12 ;
V_198:
F_42 ( V_55 -> V_139 ) ;
F_88 ( V_55 ) ;
V_197:
F_71 ( V_109 ) ;
V_71:
return V_12 ;
}
static int
F_94 ( struct V_136 * V_136 , const void T_4 * V_128 , unsigned int V_110 )
{
int V_12 ;
struct V_160 V_186 ;
struct V_73 * V_121 ;
void * V_175 ;
struct V_43 * V_77 ;
if ( F_82 ( & V_186 , V_128 , sizeof( V_186 ) ) != 0 )
return - V_176 ;
if ( V_186 . V_193 >= V_199 / sizeof( struct V_158 ) )
return - V_170 ;
V_186 . V_59 [ sizeof( V_186 . V_59 ) - 1 ] = 0 ;
V_121 = F_95 ( V_186 . V_130 ) ;
if ( ! V_121 )
return - V_170 ;
V_175 = V_121 -> V_78 [ F_68 () ] ;
if ( F_82 ( V_175 , V_128 + sizeof( V_186 ) ,
V_186 . V_130 ) != 0 ) {
V_12 = - V_176 ;
goto V_200;
}
V_12 = F_58 ( V_136 , V_121 , V_175 , & V_186 ) ;
if ( V_12 != 0 )
goto V_200;
F_8 ( L_51 ) ;
V_12 = F_91 ( V_136 , V_186 . V_59 , V_186 . V_102 , V_121 ,
V_186 . V_193 , V_186 . V_109 ) ;
if ( V_12 )
goto V_201;
return 0 ;
V_201:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_77 , V_136 ) ;
V_200:
F_93 ( V_121 ) ;
return V_12 ;
}
static int
F_96 ( struct V_136 * V_136 , const void T_4 * V_128 ,
unsigned int V_110 , int V_183 )
{
unsigned int V_162 , V_202 ;
struct V_203 V_186 ;
struct V_158 * V_204 ;
unsigned int V_193 ;
const char * V_59 ;
int V_130 ;
void * V_205 ;
struct V_1 * V_55 ;
const struct V_73 * V_74 ;
int V_12 = 0 ;
void * V_175 ;
struct V_43 * V_77 ;
unsigned int V_93 ;
#ifdef F_83
struct V_206 V_207 ;
if ( V_183 ) {
V_205 = & V_207 ;
V_130 = sizeof( struct V_206 ) ;
} else
#endif
{
V_205 = & V_186 ;
V_130 = sizeof( struct V_203 ) ;
}
if ( F_82 ( V_205 , V_128 , V_130 ) != 0 )
return - V_176 ;
#ifdef F_83
if ( V_183 ) {
V_193 = V_207 . V_193 ;
V_59 = V_207 . V_59 ;
} else
#endif
{
V_193 = V_186 . V_193 ;
V_59 = V_186 . V_59 ;
}
if ( V_110 != V_130 + V_193 * sizeof( struct V_158 ) )
return - V_140 ;
V_204 = F_97 ( V_110 - V_130 ) ;
if ( ! V_204 )
return - V_170 ;
if ( F_82 ( V_204 , V_128 + V_130 , V_110 - V_130 ) != 0 ) {
V_12 = - V_176 ;
goto free;
}
V_55 = F_86 ( V_136 , V_82 , V_59 ) ;
if ( ! V_55 || F_48 ( V_55 ) ) {
V_12 = V_55 ? F_49 ( V_55 ) : - V_187 ;
goto free;
}
F_26 () ;
V_74 = V_55 -> V_74 ;
if ( V_74 -> V_163 != V_193 ) {
V_12 = - V_140 ;
goto V_208;
}
V_162 = 0 ;
V_202 = F_17 () ;
V_175 = V_74 -> V_78 [ V_202 ] ;
V_93 = F_27 () ;
F_18 (iter, loc_cpu_entry, private->size) {
F_32 ( V_77 -> V_109 , V_204 [ V_162 ] . V_167 , V_204 [ V_162 ] . V_125 ) ;
++ V_162 ;
}
F_35 ( V_93 ) ;
V_208:
F_36 () ;
F_88 ( V_55 ) ;
F_42 ( V_55 -> V_139 ) ;
free:
F_71 ( V_204 ) ;
return V_12 ;
}
static int
F_98 ( struct V_43 * V_48 , void T_4 * * V_209 ,
unsigned int * V_130 , struct V_158 * V_109 ,
unsigned int V_162 )
{
struct V_47 * V_55 ;
struct V_181 T_4 * V_210 ;
T_5 V_62 , V_133 ;
T_6 V_211 ;
const struct V_104 * V_105 ;
int V_12 = 0 ;
V_211 = * V_130 ;
V_210 = (struct V_181 T_4 * ) * V_209 ;
if ( F_69 ( V_210 , V_48 , sizeof( struct V_43 ) ) != 0 ||
F_69 ( & V_210 -> V_109 , & V_109 [ V_162 ] ,
sizeof( V_109 [ V_162 ] ) ) != 0 )
return - V_176 ;
* V_209 += sizeof( struct V_181 ) ;
* V_130 -= sizeof( struct V_43 ) - sizeof( struct V_181 ) ;
F_31 (ematch, e) {
V_12 = F_99 ( V_105 , V_209 , V_130 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_62 = V_48 -> V_62 - ( V_211 - * V_130 ) ;
V_55 = F_14 ( V_48 ) ;
V_12 = F_100 ( V_55 , V_209 , V_130 ) ;
if ( V_12 )
return V_12 ;
V_133 = V_48 -> V_133 - ( V_211 - * V_130 ) ;
if ( F_101 ( V_62 , & V_210 -> V_62 ) != 0 ||
F_101 ( V_133 , & V_210 -> V_133 ) != 0 )
return - V_176 ;
return 0 ;
}
static int
F_102 ( struct V_104 * V_135 ,
const char * V_59 ,
const struct V_9 * V_6 ,
unsigned int V_212 ,
int * V_130 )
{
struct V_145 * V_107 ;
V_107 = F_47 ( V_100 , V_135 -> V_57 . V_128 . V_59 ,
V_135 -> V_57 . V_128 . V_146 ) ;
if ( F_48 ( V_107 ) ) {
F_8 ( L_52 ,
V_135 -> V_57 . V_128 . V_59 ) ;
return F_49 ( V_107 ) ;
}
V_135 -> V_57 . V_58 . V_107 = V_107 ;
* V_130 += F_76 ( V_107 ) ;
return 0 ;
}
static void F_103 ( struct V_181 * V_48 )
{
struct V_47 * V_55 ;
struct V_104 * V_105 ;
F_31 (ematch, e)
F_42 ( V_105 -> V_57 . V_58 . V_107 -> V_139 ) ;
V_55 = F_104 ( V_48 ) ;
F_42 ( V_55 -> V_57 . V_58 . V_56 -> V_139 ) ;
}
static int
F_105 ( struct V_181 * V_48 ,
struct V_73 * V_121 ,
unsigned int * V_130 ,
const unsigned char * V_44 ,
const unsigned char * V_154 ,
const unsigned int * V_155 ,
const unsigned int * V_156 ,
const char * V_59 )
{
struct V_104 * V_105 ;
struct V_47 * V_55 ;
struct V_150 * V_56 ;
unsigned int V_180 ;
unsigned int V_151 ;
int V_12 , V_173 , V_157 ;
F_8 ( L_53 , V_48 ) ;
if ( ( unsigned long ) V_48 % F_56 ( struct V_181 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_181 ) >= V_154 ) {
F_8 ( L_54 , V_48 , V_154 ) ;
return - V_140 ;
}
if ( V_48 -> V_133 < sizeof( struct V_181 ) +
sizeof( struct V_213 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_133 ) ;
return - V_140 ;
}
V_12 = F_43 ( (struct V_43 * ) V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_173 = sizeof( struct V_43 ) - sizeof( struct V_181 ) ;
V_180 = ( void * ) V_48 - ( void * ) V_44 ;
V_151 = 0 ;
F_31 (ematch, e) {
V_12 = F_102 ( V_105 , V_59 ,
& V_48 -> V_6 , V_48 -> V_127 , & V_173 ) ;
if ( V_12 != 0 )
goto V_214;
++ V_151 ;
}
V_55 = F_104 ( V_48 ) ;
V_56 = F_53 ( V_100 , V_55 -> V_57 . V_128 . V_59 ,
V_55 -> V_57 . V_128 . V_146 ) ;
if ( F_48 ( V_56 ) ) {
F_8 ( L_55 ,
V_55 -> V_57 . V_128 . V_59 ) ;
V_12 = F_49 ( V_56 ) ;
goto V_214;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_173 += F_77 ( V_56 ) ;
* V_130 += V_173 ;
V_12 = F_78 ( V_82 , V_180 , V_173 ) ;
if ( V_12 )
goto V_71;
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ( unsigned char * ) V_48 - V_44 == V_155 [ V_157 ] )
V_121 -> V_79 [ V_157 ] = V_155 [ V_157 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_156 [ V_157 ] )
V_121 -> V_103 [ V_157 ] = V_156 [ V_157 ] ;
}
memset ( & V_48 -> V_109 , 0 , sizeof( V_48 -> V_109 ) ) ;
V_48 -> V_127 = 0 ;
return 0 ;
V_71:
F_42 ( V_55 -> V_57 . V_58 . V_56 -> V_139 ) ;
V_214:
F_31 (ematch, e) {
if ( V_151 -- == 0 )
break;
F_42 ( V_105 -> V_57 . V_58 . V_107 -> V_139 ) ;
}
return V_12 ;
}
static int
F_106 ( struct V_181 * V_48 , void * * V_209 ,
unsigned int * V_130 , const char * V_59 ,
struct V_73 * V_121 , unsigned char * V_44 )
{
struct V_47 * V_55 ;
struct V_150 * V_56 ;
struct V_43 * V_215 ;
unsigned int V_211 ;
int V_12 , V_157 ;
struct V_104 * V_105 ;
V_12 = 0 ;
V_211 = * V_130 ;
V_215 = (struct V_43 * ) * V_209 ;
memcpy ( V_215 , V_48 , sizeof( struct V_43 ) ) ;
memcpy ( & V_215 -> V_109 , & V_48 -> V_109 , sizeof( V_48 -> V_109 ) ) ;
* V_209 += sizeof( struct V_43 ) ;
* V_130 += sizeof( struct V_43 ) - sizeof( struct V_181 ) ;
F_31 (ematch, e) {
V_12 = F_107 ( V_105 , V_209 , V_130 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_215 -> V_62 = V_48 -> V_62 - ( V_211 - * V_130 ) ;
V_55 = F_104 ( V_48 ) ;
V_56 = V_55 -> V_57 . V_58 . V_56 ;
F_108 ( V_55 , V_209 , V_130 ) ;
V_215 -> V_133 = V_48 -> V_133 - ( V_211 - * V_130 ) ;
for ( V_157 = 0 ; V_157 < V_123 ; V_157 ++ ) {
if ( ( unsigned char * ) V_215 - V_44 < V_121 -> V_79 [ V_157 ] )
V_121 -> V_79 [ V_157 ] -= V_211 - * V_130 ;
if ( ( unsigned char * ) V_215 - V_44 < V_121 -> V_103 [ V_157 ] )
V_121 -> V_103 [ V_157 ] -= V_211 - * V_130 ;
}
return V_12 ;
}
static int
F_109 ( struct V_43 * V_48 , struct V_136 * V_136 , const char * V_59 )
{
struct V_104 * V_105 ;
struct V_142 V_152 ;
unsigned int V_151 ;
int V_12 = 0 ;
V_151 = 0 ;
V_152 . V_136 = V_136 ;
V_152 . V_84 = V_59 ;
V_152 . V_143 = & V_48 -> V_6 ;
V_152 . V_149 = V_48 -> V_127 ;
V_152 . V_99 = V_100 ;
F_31 (ematch, e) {
V_12 = F_44 ( V_105 , & V_152 ) ;
if ( V_12 != 0 )
goto V_153;
++ V_151 ;
}
V_12 = F_50 ( V_48 , V_136 , V_59 ) ;
if ( V_12 )
goto V_153;
return 0 ;
V_153:
F_31 (ematch, e) {
if ( V_151 -- == 0 )
break;
F_41 ( V_105 , V_136 ) ;
}
return V_12 ;
}
static int
F_110 ( struct V_136 * V_136 ,
const char * V_59 ,
unsigned int V_102 ,
struct V_73 * * V_216 ,
void * * V_217 ,
unsigned int V_171 ,
unsigned int V_163 ,
unsigned int * V_155 ,
unsigned int * V_156 )
{
unsigned int V_162 , V_151 ;
struct V_73 * V_121 , * V_2 ;
void * V_124 , * V_122 , * V_218 ;
struct V_181 * V_219 ;
struct V_43 * V_220 ;
unsigned int V_130 ;
int V_12 ;
V_2 = * V_216 ;
V_122 = * V_217 ;
V_130 = V_171 ;
V_2 -> V_163 = V_163 ;
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
V_2 -> V_79 [ V_162 ] = 0xFFFFFFFF ;
V_2 -> V_103 [ V_162 ] = 0xFFFFFFFF ;
}
F_8 ( L_56 , V_2 -> V_130 ) ;
V_151 = 0 ;
F_84 ( V_82 ) ;
F_80 ( V_82 , V_163 ) ;
F_18 (iter0, entry0, total_size) {
V_12 = F_105 ( V_219 , V_2 , & V_130 ,
V_122 ,
V_122 + V_171 ,
V_155 ,
V_156 ,
V_59 ) ;
if ( V_12 != 0 )
goto V_221;
++ V_151 ;
}
V_12 = - V_140 ;
if ( V_151 != V_163 ) {
F_8 ( L_57 ,
V_151 , V_163 ) ;
goto V_221;
}
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
if ( ! ( V_102 & ( 1 << V_162 ) ) )
continue;
if ( V_2 -> V_79 [ V_162 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_162 , V_155 [ V_162 ] ) ;
goto V_221;
}
if ( V_2 -> V_103 [ V_162 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_162 , V_156 [ V_162 ] ) ;
goto V_221;
}
}
V_12 = - V_170 ;
V_121 = F_95 ( V_130 ) ;
if ( ! V_121 )
goto V_221;
V_121 -> V_163 = V_163 ;
for ( V_162 = 0 ; V_162 < V_123 ; V_162 ++ ) {
V_121 -> V_79 [ V_162 ] = V_2 -> V_79 [ V_162 ] ;
V_121 -> V_103 [ V_162 ] = V_2 -> V_103 [ V_162 ] ;
}
V_218 = V_121 -> V_78 [ F_68 () ] ;
V_124 = V_218 ;
V_130 = V_171 ;
F_18 (iter0, entry0, total_size) {
V_12 = F_106 ( V_219 , & V_124 , & V_130 ,
V_59 , V_121 , V_218 ) ;
if ( V_12 != 0 )
break;
}
F_87 ( V_82 ) ;
F_89 ( V_82 ) ;
if ( V_12 )
goto V_200;
V_12 = - V_165 ;
if ( ! F_38 ( V_121 , V_102 , V_218 ) )
goto V_200;
V_162 = 0 ;
F_18 (iter1, entry1, newinfo->size) {
V_12 = F_109 ( V_220 , V_136 , V_59 ) ;
if ( V_12 != 0 )
break;
++ V_162 ;
if ( strcmp ( F_14 ( V_220 ) -> V_57 . V_128 . V_59 ,
V_60 ) == 0 )
++ V_121 -> V_117 ;
}
if ( V_12 ) {
int V_222 = V_162 ;
V_151 -= V_162 ;
F_18 (iter0, entry0, newinfo->size) {
if ( V_222 -- > 0 )
continue;
if ( V_151 -- == 0 )
break;
F_103 ( V_219 ) ;
}
F_18 (iter1, entry1, newinfo->size) {
if ( V_162 -- == 0 )
break;
F_57 ( V_220 , V_136 ) ;
}
F_93 ( V_121 ) ;
return V_12 ;
}
F_59 (i)
if ( V_121 -> V_78 [ V_162 ] && V_121 -> V_78 [ V_162 ] != V_218 )
memcpy ( V_121 -> V_78 [ V_162 ] , V_218 , V_121 -> V_130 ) ;
* V_216 = V_121 ;
* V_217 = V_218 ;
F_93 ( V_2 ) ;
return 0 ;
V_200:
F_93 ( V_121 ) ;
V_71:
F_18 (iter0, entry0, total_size) {
if ( V_151 -- == 0 )
break;
F_103 ( V_219 ) ;
}
return V_12 ;
V_221:
F_87 ( V_82 ) ;
F_89 ( V_82 ) ;
goto V_71;
}
static int
F_111 ( struct V_136 * V_136 , void T_4 * V_128 , unsigned int V_110 )
{
int V_12 ;
struct V_223 V_186 ;
struct V_73 * V_121 ;
void * V_175 ;
struct V_43 * V_77 ;
if ( F_82 ( & V_186 , V_128 , sizeof( V_186 ) ) != 0 )
return - V_176 ;
if ( V_186 . V_130 >= V_199 / F_112 () )
return - V_170 ;
if ( V_186 . V_193 >= V_199 / sizeof( struct V_158 ) )
return - V_170 ;
V_186 . V_59 [ sizeof( V_186 . V_59 ) - 1 ] = 0 ;
V_121 = F_95 ( V_186 . V_130 ) ;
if ( ! V_121 )
return - V_170 ;
V_175 = V_121 -> V_78 [ F_68 () ] ;
if ( F_82 ( V_175 , V_128 + sizeof( V_186 ) ,
V_186 . V_130 ) != 0 ) {
V_12 = - V_176 ;
goto V_200;
}
V_12 = F_110 ( V_136 , V_186 . V_59 , V_186 . V_102 ,
& V_121 , & V_175 , V_186 . V_130 ,
V_186 . V_164 , V_186 . V_79 ,
V_186 . V_103 ) ;
if ( V_12 != 0 )
goto V_200;
F_8 ( L_58 ) ;
V_12 = F_91 ( V_136 , V_186 . V_59 , V_186 . V_102 , V_121 ,
V_186 . V_193 , F_113 ( V_186 . V_109 ) ) ;
if ( V_12 )
goto V_201;
return 0 ;
V_201:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_77 , V_136 ) ;
V_200:
F_93 ( V_121 ) ;
return V_12 ;
}
static int
F_114 ( struct V_224 * V_225 , int V_226 , void T_4 * V_128 ,
unsigned int V_110 )
{
int V_12 ;
if ( ! F_115 ( V_227 ) )
return - V_228 ;
switch ( V_226 ) {
case V_229 :
V_12 = F_111 ( F_116 ( V_225 ) , V_128 , V_110 ) ;
break;
case V_230 :
V_12 = F_96 ( F_116 ( V_225 ) , V_128 , V_110 , 1 ) ;
break;
default:
F_8 ( L_59 , V_226 ) ;
V_12 = - V_140 ;
}
return V_12 ;
}
static int
F_117 ( unsigned int V_171 , struct V_1 * V_84 ,
void T_4 * V_172 )
{
struct V_158 * V_109 ;
const struct V_73 * V_74 = V_84 -> V_74 ;
void T_4 * V_124 ;
unsigned int V_130 ;
int V_12 = 0 ;
const void * V_175 ;
unsigned int V_162 = 0 ;
struct V_43 * V_77 ;
V_109 = F_64 ( V_84 ) ;
if ( F_48 ( V_109 ) )
return F_49 ( V_109 ) ;
V_175 = V_74 -> V_78 [ F_68 () ] ;
V_124 = V_172 ;
V_130 = V_171 ;
F_18 (iter, loc_cpu_entry, total_size) {
V_12 = F_98 ( V_77 , & V_124 ,
& V_130 , V_109 , V_162 ++ ) ;
if ( V_12 != 0 )
break;
}
F_71 ( V_109 ) ;
return V_12 ;
}
static int
F_118 ( struct V_136 * V_136 , struct V_231 T_4 * V_189 ,
int * V_110 )
{
int V_12 ;
struct V_231 V_190 ;
struct V_1 * V_55 ;
if ( * V_110 < sizeof( V_190 ) ) {
F_8 ( L_60 , * V_110 , sizeof( V_190 ) ) ;
return - V_140 ;
}
if ( F_82 ( & V_190 , V_189 , sizeof( V_190 ) ) != 0 )
return - V_176 ;
if ( * V_110 != sizeof( struct V_231 ) + V_190 . V_130 ) {
F_8 ( L_61 ,
* V_110 , sizeof( V_190 ) + V_190 . V_130 ) ;
return - V_140 ;
}
F_84 ( V_82 ) ;
V_55 = F_86 ( V_136 , V_82 , V_190 . V_59 ) ;
if ( V_55 && ! F_48 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
struct V_73 V_2 ;
F_8 ( L_47 , V_74 -> V_163 ) ;
V_12 = F_79 ( V_74 , & V_2 ) ;
if ( ! V_12 && V_190 . V_130 == V_2 . V_130 ) {
V_12 = F_117 ( V_74 -> V_130 ,
V_55 , V_189 -> V_191 ) ;
} else if ( ! V_12 ) {
F_8 ( L_62 ,
V_74 -> V_130 , V_190 . V_130 ) ;
V_12 = - V_192 ;
}
F_87 ( V_82 ) ;
F_42 ( V_55 -> V_139 ) ;
F_88 ( V_55 ) ;
} else
V_12 = V_55 ? F_49 ( V_55 ) : - V_187 ;
F_89 ( V_82 ) ;
return V_12 ;
}
static int
F_119 ( struct V_224 * V_225 , int V_226 , void T_4 * V_128 , int * V_110 )
{
int V_12 ;
if ( ! F_115 ( V_227 ) )
return - V_228 ;
switch ( V_226 ) {
case V_232 :
V_12 = F_81 ( F_116 ( V_225 ) , V_128 , V_110 , 1 ) ;
break;
case V_233 :
V_12 = F_118 ( F_116 ( V_225 ) , V_128 , V_110 ) ;
break;
default:
V_12 = F_120 ( V_225 , V_226 , V_128 , V_110 ) ;
}
return V_12 ;
}
static int
F_121 ( struct V_224 * V_225 , int V_226 , void T_4 * V_128 , unsigned int V_110 )
{
int V_12 ;
if ( ! F_115 ( V_227 ) )
return - V_228 ;
switch ( V_226 ) {
case V_229 :
V_12 = F_94 ( F_116 ( V_225 ) , V_128 , V_110 ) ;
break;
case V_230 :
V_12 = F_96 ( F_116 ( V_225 ) , V_128 , V_110 , 0 ) ;
break;
default:
F_8 ( L_59 , V_226 ) ;
V_12 = - V_140 ;
}
return V_12 ;
}
static int
F_120 ( struct V_224 * V_225 , int V_226 , void T_4 * V_128 , int * V_110 )
{
int V_12 ;
if ( ! F_115 ( V_227 ) )
return - V_228 ;
switch ( V_226 ) {
case V_232 :
V_12 = F_81 ( F_116 ( V_225 ) , V_128 , V_110 , 0 ) ;
break;
case V_233 :
V_12 = F_90 ( F_116 ( V_225 ) , V_128 , V_110 ) ;
break;
case V_234 :
case V_235 : {
struct V_236 V_237 ;
int V_56 ;
if ( * V_110 != sizeof( V_237 ) ) {
V_12 = - V_140 ;
break;
}
if ( F_82 ( & V_237 , V_128 , sizeof( V_237 ) ) != 0 ) {
V_12 = - V_176 ;
break;
}
V_237 . V_59 [ sizeof( V_237 . V_59 ) - 1 ] = 0 ;
if ( V_226 == V_235 )
V_56 = 1 ;
else
V_56 = 0 ;
F_85 ( F_122 ( V_82 , V_237 . V_59 ,
V_237 . V_146 ,
V_56 , & V_12 ) ,
L_63 , V_237 . V_59 ) ;
break;
}
default:
F_8 ( L_64 , V_226 ) ;
V_12 = - V_140 ;
}
return V_12 ;
}
struct V_1 * F_123 ( struct V_136 * V_136 ,
const struct V_1 * V_84 ,
const struct V_160 * V_161 )
{
int V_12 ;
struct V_73 * V_121 ;
struct V_73 V_238 = { 0 } ;
void * V_175 ;
struct V_1 * V_239 ;
V_121 = F_95 ( V_161 -> V_130 ) ;
if ( ! V_121 ) {
V_12 = - V_170 ;
goto V_71;
}
V_175 = V_121 -> V_78 [ F_68 () ] ;
memcpy ( V_175 , V_161 -> V_78 , V_161 -> V_130 ) ;
V_12 = F_58 ( V_136 , V_121 , V_175 , V_161 ) ;
if ( V_12 != 0 )
goto V_240;
V_239 = F_124 ( V_136 , V_84 , & V_238 , V_121 ) ;
if ( F_48 ( V_239 ) ) {
V_12 = F_49 ( V_239 ) ;
goto V_240;
}
return V_239 ;
V_240:
F_93 ( V_121 ) ;
V_71:
return F_66 ( V_12 ) ;
}
void F_125 ( struct V_136 * V_136 , struct V_1 * V_84 )
{
struct V_73 * V_74 ;
void * V_175 ;
struct V_241 * V_242 = V_84 -> V_139 ;
struct V_43 * V_77 ;
V_74 = F_126 ( V_84 ) ;
V_175 = V_74 -> V_78 [ F_68 () ] ;
F_18 (iter, loc_cpu_entry, private->size)
F_57 ( V_77 , V_136 ) ;
if ( V_74 -> V_163 > V_74 -> V_182 )
F_42 ( V_242 ) ;
F_93 ( V_74 ) ;
}
static inline bool
F_127 ( T_7 V_243 , T_7 V_244 , T_7 V_245 ,
T_7 type , T_7 V_246 ,
bool V_247 )
{
return ( ( V_243 == 0xFF ) ||
( type == V_243 && V_246 >= V_244 && V_246 <= V_245 ) )
^ V_247 ;
}
static bool
F_128 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_248 * V_249 ;
struct V_248 V_250 ;
const struct V_251 * V_252 = V_40 -> V_108 ;
if ( V_40 -> V_94 != 0 )
return false ;
V_249 = F_129 ( V_38 , V_40 -> V_97 , sizeof( V_250 ) , & V_250 ) ;
if ( V_249 == NULL ) {
F_8 ( L_65 ) ;
V_40 -> V_98 = true ;
return false ;
}
return F_127 ( V_252 -> type ,
V_252 -> V_246 [ 0 ] ,
V_252 -> V_246 [ 1 ] ,
V_249 -> type , V_249 -> V_246 ,
! ! ( V_252 -> V_22 & V_253 ) ) ;
}
static int F_130 ( const struct V_142 * V_40 )
{
const struct V_251 * V_252 = V_40 -> V_108 ;
return ( V_252 -> V_22 & ~ V_253 ) ? - V_140 : 0 ;
}
static int T_8 F_131 ( struct V_136 * V_136 )
{
return F_132 ( V_136 , V_100 ) ;
}
static void T_9 F_133 ( struct V_136 * V_136 )
{
F_134 ( V_136 , V_100 ) ;
}
static int T_10 F_135 ( void )
{
int V_12 ;
V_12 = F_136 ( & V_254 ) ;
if ( V_12 < 0 )
goto V_255;
V_12 = F_137 ( V_256 , F_138 ( V_256 ) ) ;
if ( V_12 < 0 )
goto V_257;
V_12 = F_139 ( V_258 , F_138 ( V_258 ) ) ;
if ( V_12 < 0 )
goto V_259;
V_12 = F_140 ( & V_260 ) ;
if ( V_12 < 0 )
goto V_261;
F_141 ( L_66 ) ;
return 0 ;
V_261:
F_142 ( V_258 , F_138 ( V_258 ) ) ;
V_259:
F_143 ( V_256 , F_138 ( V_256 ) ) ;
V_257:
F_144 ( & V_254 ) ;
V_255:
return V_12 ;
}
static void T_11 F_145 ( void )
{
F_146 ( & V_260 ) ;
F_142 ( V_258 , F_138 ( V_258 ) ) ;
F_143 ( V_256 , F_138 ( V_256 ) ) ;
F_144 ( & V_254 ) ;
}
