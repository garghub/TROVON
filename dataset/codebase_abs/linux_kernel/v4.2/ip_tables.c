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
const struct V_43 * V_75 ;
const char * V_50 , * V_51 , * V_52 ;
const struct V_43 * V_76 ;
unsigned int V_53 = 0 ;
struct V_77 * V_77 = F_17 ( V_70 ? V_70 : V_71 ) ;
V_75 = F_11 ( V_74 -> V_78 , V_74 -> V_79 [ V_68 ] ) ;
V_50 = V_51 = V_80 [ V_68 ] ;
V_52 = V_65 [ V_81 ] ;
F_18 (iter, root, private->size - private->hook_entry[hook])
if ( F_15 ( V_76 , V_48 , V_50 ,
& V_51 , & V_52 , & V_53 ) != 0 )
break;
F_19 ( V_77 , V_82 , V_68 , V_38 , V_70 , V_71 , & V_83 ,
L_13 ,
V_72 , V_51 , V_52 , V_53 ) ;
}
unsigned int
F_20 ( struct V_37 * V_38 ,
unsigned int V_68 ,
const struct V_84 * V_85 ,
struct V_1 * V_86 )
{
static const char V_87 [ V_88 ] V_89 ( ( F_21 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_90 ;
struct V_43 * V_48 , * * V_91 ;
unsigned int * V_92 , V_93 , V_94 ;
const struct V_73 * V_74 ;
struct V_39 V_95 ;
unsigned int V_96 ;
V_6 = F_22 ( V_38 ) ;
V_7 = V_85 -> V_70 ? V_85 -> V_70 -> V_59 : V_87 ;
V_8 = V_85 -> V_71 ? V_85 -> V_71 -> V_59 : V_87 ;
V_95 . V_97 = F_23 ( V_6 -> V_98 ) & V_99 ;
V_95 . V_100 = F_24 ( V_38 ) ;
V_95 . V_101 = false ;
V_95 . V_70 = V_85 -> V_70 ;
V_95 . V_71 = V_85 -> V_71 ;
V_95 . V_102 = V_103 ;
V_95 . V_104 = V_68 ;
F_25 ( V_86 -> V_105 & ( 1 << V_68 ) ) ;
F_26 () ;
V_96 = F_27 () ;
V_74 = V_86 -> V_74 ;
V_94 = F_28 () ;
F_29 () ;
V_90 = V_74 -> V_78 ;
V_91 = (struct V_43 * * ) V_74 -> V_91 [ V_94 ] ;
V_92 = F_30 ( V_74 -> V_92 , V_94 ) ;
V_93 = * V_92 ;
V_48 = F_11 ( V_90 , V_74 -> V_79 [ V_68 ] ) ;
F_31 ( L_14 ,
V_86 -> V_59 , V_68 , V_93 ,
F_11 ( V_90 , V_74 -> V_106 [ V_68 ] ) ) ;
do {
const struct V_47 * V_55 ;
const struct V_107 * V_108 ;
struct V_109 * V_110 ;
F_25 ( V_48 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_48 -> V_6 , V_95 . V_97 ) ) {
V_111:
V_48 = F_32 ( V_48 ) ;
continue;
}
F_33 (ematch, e) {
V_95 . V_112 = V_108 -> V_57 . V_58 . V_112 ;
V_95 . V_113 = V_108 -> V_61 ;
if ( ! V_95 . V_112 -> V_112 ( V_38 , & V_95 ) )
goto V_111;
}
V_110 = F_34 ( & V_48 -> V_114 ) ;
F_35 ( * V_110 , V_38 -> V_115 , 1 ) ;
V_55 = F_14 ( V_48 ) ;
F_25 ( V_55 -> V_57 . V_58 . V_56 ) ;
#if F_36 ( V_116 )
if ( F_37 ( V_38 -> V_117 ) )
F_16 ( V_38 , V_68 , V_85 -> V_70 , V_85 -> V_71 ,
V_86 -> V_59 , V_74 , V_48 ) ;
#endif
if ( ! V_55 -> V_57 . V_58 . V_56 -> V_56 ) {
int V_118 ;
V_118 = ( (struct V_54 * ) V_55 ) -> V_64 ;
if ( V_118 < 0 ) {
if ( V_118 != V_119 ) {
V_64 = ( unsigned int ) ( - V_118 ) - 1 ;
break;
}
if ( * V_92 <= V_93 ) {
V_48 = F_11 ( V_90 ,
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
if ( V_90 + V_118 != F_32 ( V_48 ) &&
! ( V_48 -> V_6 . V_32 & V_120 ) ) {
if ( * V_92 >= V_74 -> V_121 ) {
V_64 = V_42 ;
break;
}
V_91 [ ( * V_92 ) ++ ] = V_48 ;
F_31 ( L_18 ,
V_48 , * V_92 - 1 ) ;
}
V_48 = F_11 ( V_90 , V_118 ) ;
continue;
}
V_95 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_95 . V_41 = V_55 -> V_61 ;
V_64 = V_55 -> V_57 . V_58 . V_56 -> V_56 ( V_38 , & V_95 ) ;
V_6 = F_22 ( V_38 ) ;
if ( V_64 == V_122 )
V_48 = F_32 ( V_48 ) ;
else
break;
} while ( ! V_95 . V_101 );
F_31 ( L_19 ,
V_123 , * V_92 , V_93 ) ;
* V_92 = V_93 ;
F_38 ( V_96 ) ;
F_39 () ;
#ifdef F_40
return V_124 ;
#else
if ( V_95 . V_101 )
return V_42 ;
else return V_64 ;
#endif
}
static int
F_41 ( const struct V_73 * V_125 ,
unsigned int V_105 , void * V_126 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_127 ; V_68 ++ ) {
unsigned int V_128 = V_125 -> V_79 [ V_68 ] ;
struct V_43 * V_48 = (struct V_43 * ) ( V_126 + V_128 ) ;
if ( ! ( V_105 & ( 1 << V_68 ) ) )
continue;
V_48 -> V_114 . V_129 = V_128 ;
for (; ; ) {
const struct V_54 * V_55
= ( void * ) F_13 ( V_48 ) ;
int V_130 = V_48 -> V_131 & ( 1 << V_68 ) ;
if ( V_48 -> V_131 & ( 1 << V_127 ) ) {
F_42 ( L_20 ,
V_68 , V_128 , V_48 -> V_131 ) ;
return 0 ;
}
V_48 -> V_131 |= ( ( 1 << V_68 ) | ( 1 << V_127 ) ) ;
if ( ( V_48 -> V_62 == sizeof( struct V_43 ) &&
( strcmp ( V_55 -> V_56 . V_57 . V_132 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < 0 && F_12 ( & V_48 -> V_6 ) ) ||
V_130 ) {
unsigned int V_133 , V_134 ;
if ( ( strcmp ( V_55 -> V_56 . V_57 . V_132 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < - V_135 - 1 ) {
F_8 ( L_21
L_22 ,
V_55 -> V_64 ) ;
return 0 ;
}
do {
V_48 -> V_131 ^= ( 1 << V_127 ) ;
#ifdef F_43
if ( V_48 -> V_131
& ( 1 << V_127 ) ) {
F_8 ( L_23
L_24
L_25 ,
V_68 , V_128 ) ;
}
#endif
V_133 = V_128 ;
V_128 = V_48 -> V_114 . V_129 ;
V_48 -> V_114 . V_129 = 0 ;
if ( V_128 == V_133 )
goto V_136;
V_48 = (struct V_43 * )
( V_126 + V_128 ) ;
} while ( V_133 == V_128 + V_48 -> V_137 );
V_134 = V_48 -> V_137 ;
V_48 = (struct V_43 * )
( V_126 + V_128 + V_134 ) ;
V_48 -> V_114 . V_129 = V_128 ;
V_128 += V_134 ;
} else {
int V_138 = V_55 -> V_64 ;
if ( strcmp ( V_55 -> V_56 . V_57 . V_132 . V_59 ,
V_63 ) == 0 &&
V_138 >= 0 ) {
if ( V_138 > V_125 -> V_134 -
sizeof( struct V_43 ) ) {
F_8 ( L_26
L_27 ,
V_138 ) ;
return 0 ;
}
F_8 ( L_28 ,
V_128 , V_138 ) ;
} else {
V_138 = V_128 + V_48 -> V_137 ;
}
V_48 = (struct V_43 * )
( V_126 + V_138 ) ;
V_48 -> V_114 . V_129 = V_128 ;
V_128 = V_138 ;
}
}
V_136:
F_8 ( L_29 , V_68 ) ;
}
return 1 ;
}
static void F_44 ( struct V_107 * V_139 , struct V_77 * V_77 )
{
struct V_140 V_40 ;
V_40 . V_77 = V_77 ;
V_40 . V_112 = V_139 -> V_57 . V_58 . V_112 ;
V_40 . V_113 = V_139 -> V_61 ;
V_40 . V_102 = V_103 ;
if ( V_40 . V_112 -> V_141 != NULL )
V_40 . V_112 -> V_141 ( & V_40 ) ;
F_45 ( V_40 . V_112 -> V_142 ) ;
}
static int
F_46 ( const struct V_43 * V_48 , const char * V_59 )
{
const struct V_47 * V_55 ;
if ( ! F_7 ( & V_48 -> V_6 ) ) {
F_8 ( L_30 , V_48 , V_59 ) ;
return - V_143 ;
}
if ( V_48 -> V_62 + sizeof( struct V_47 ) >
V_48 -> V_137 )
return - V_143 ;
V_55 = F_13 ( V_48 ) ;
if ( V_48 -> V_62 + V_55 -> V_57 . V_144 > V_48 -> V_137 )
return - V_143 ;
return 0 ;
}
static int
F_47 ( struct V_107 * V_139 , struct V_145 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_146 ;
int V_12 ;
V_40 -> V_112 = V_139 -> V_57 . V_58 . V_112 ;
V_40 -> V_113 = V_139 -> V_61 ;
V_12 = F_48 ( V_40 , V_139 -> V_57 . V_147 - sizeof( * V_139 ) ,
V_6 -> V_29 , V_6 -> V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 , V_40 -> V_112 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_49 ( struct V_107 * V_139 , struct V_145 * V_40 )
{
struct V_148 * V_112 ;
int V_12 ;
V_112 = F_50 ( V_103 , V_139 -> V_57 . V_132 . V_59 ,
V_139 -> V_57 . V_132 . V_149 ) ;
if ( F_51 ( V_112 ) ) {
F_8 ( L_32 , V_139 -> V_57 . V_132 . V_59 ) ;
return F_52 ( V_112 ) ;
}
V_139 -> V_57 . V_58 . V_112 = V_112 ;
V_12 = F_47 ( V_139 , V_40 ) ;
if ( V_12 )
goto V_150;
return 0 ;
V_150:
F_45 ( V_139 -> V_57 . V_58 . V_112 -> V_142 ) ;
return V_12 ;
}
static int F_53 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 )
{
struct V_47 * V_55 = F_14 ( V_48 ) ;
struct V_151 V_40 = {
. V_77 = V_77 ,
. V_86 = V_59 ,
. V_146 = V_48 ,
. V_56 = V_55 -> V_57 . V_58 . V_56 ,
. V_41 = V_55 -> V_61 ,
. V_152 = V_48 -> V_131 ,
. V_102 = V_103 ,
} ;
int V_12 ;
V_12 = F_54 ( & V_40 , V_55 -> V_57 . V_144 - sizeof( * V_55 ) ,
V_48 -> V_6 . V_29 , V_48 -> V_6 . V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_55 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 ,
unsigned int V_134 )
{
struct V_47 * V_55 ;
struct V_153 * V_56 ;
int V_12 ;
unsigned int V_154 ;
struct V_145 V_155 ;
struct V_107 * V_108 ;
V_12 = F_46 ( V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_48 -> V_114 . V_129 = F_56 () ;
if ( F_57 ( V_48 -> V_114 . V_129 ) )
return - V_156 ;
V_154 = 0 ;
V_155 . V_77 = V_77 ;
V_155 . V_86 = V_59 ;
V_155 . V_146 = & V_48 -> V_6 ;
V_155 . V_152 = V_48 -> V_131 ;
V_155 . V_102 = V_103 ;
F_33 (ematch, e) {
V_12 = F_49 ( V_108 , & V_155 ) ;
if ( V_12 != 0 )
goto V_157;
++ V_154 ;
}
V_55 = F_14 ( V_48 ) ;
V_56 = F_58 ( V_103 , V_55 -> V_57 . V_132 . V_59 ,
V_55 -> V_57 . V_132 . V_149 ) ;
if ( F_51 ( V_56 ) ) {
F_8 ( L_33 , V_55 -> V_57 . V_132 . V_59 ) ;
V_12 = F_52 ( V_56 ) ;
goto V_157;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_12 = F_53 ( V_48 , V_77 , V_59 ) ;
if ( V_12 )
goto V_150;
return 0 ;
V_150:
F_45 ( V_55 -> V_57 . V_58 . V_56 -> V_142 ) ;
V_157:
F_33 (ematch, e) {
if ( V_154 -- == 0 )
break;
F_44 ( V_108 , V_77 ) ;
}
F_59 ( V_48 -> V_114 . V_129 ) ;
return V_12 ;
}
static bool F_60 ( const struct V_43 * V_48 )
{
const struct V_47 * V_55 ;
unsigned int V_64 ;
if ( ! F_12 ( & V_48 -> V_6 ) )
return false ;
V_55 = F_13 ( V_48 ) ;
if ( strcmp ( V_55 -> V_57 . V_132 . V_59 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_54 * ) V_55 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_124 ;
}
static int
F_61 ( struct V_43 * V_48 ,
struct V_73 * V_125 ,
const unsigned char * V_44 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
unsigned int V_105 )
{
unsigned int V_161 ;
if ( ( unsigned long ) V_48 % F_62 ( struct V_43 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_43 ) >= V_158 ) {
F_8 ( L_34 , V_48 ) ;
return - V_143 ;
}
if ( V_48 -> V_137
< sizeof( struct V_43 ) + sizeof( struct V_47 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_137 ) ;
return - V_143 ;
}
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ! ( V_105 & ( 1 << V_161 ) ) )
continue;
if ( ( unsigned char * ) V_48 - V_44 == V_159 [ V_161 ] )
V_125 -> V_79 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_160 [ V_161 ] ) {
if ( ! F_60 ( V_48 ) ) {
F_42 ( L_36
L_37
L_38 ) ;
return - V_143 ;
}
V_125 -> V_106 [ V_161 ] = V_160 [ V_161 ] ;
}
}
V_48 -> V_114 = ( (struct V_109 ) { 0 , 0 } ) ;
V_48 -> V_131 = 0 ;
return 0 ;
}
static void
F_63 ( struct V_43 * V_48 , struct V_77 * V_77 )
{
struct V_162 V_40 ;
struct V_47 * V_55 ;
struct V_107 * V_108 ;
F_33 (ematch, e)
F_44 ( V_108 , V_77 ) ;
V_55 = F_14 ( V_48 ) ;
V_40 . V_77 = V_77 ;
V_40 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_40 . V_41 = V_55 -> V_61 ;
V_40 . V_102 = V_103 ;
if ( V_40 . V_56 -> V_141 != NULL )
V_40 . V_56 -> V_141 ( & V_40 ) ;
F_45 ( V_40 . V_56 -> V_142 ) ;
F_59 ( V_48 -> V_114 . V_129 ) ;
}
static int
F_64 ( struct V_77 * V_77 , struct V_73 * V_125 , void * V_126 ,
const struct V_163 * V_164 )
{
struct V_43 * V_76 ;
unsigned int V_165 ;
int V_12 = 0 ;
V_125 -> V_134 = V_164 -> V_134 ;
V_125 -> V_166 = V_164 -> V_167 ;
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
V_125 -> V_79 [ V_165 ] = 0xFFFFFFFF ;
V_125 -> V_106 [ V_165 ] = 0xFFFFFFFF ;
}
F_8 ( L_39 , V_125 -> V_134 ) ;
V_165 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_61 ( V_76 , V_125 , V_126 ,
V_126 + V_164 -> V_134 ,
V_164 -> V_79 ,
V_164 -> V_106 ,
V_164 -> V_105 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_165 ;
if ( strcmp ( F_14 ( V_76 ) -> V_57 . V_132 . V_59 ,
V_60 ) == 0 )
++ V_125 -> V_121 ;
}
if ( V_165 != V_164 -> V_167 ) {
F_8 ( L_40 ,
V_165 , V_164 -> V_167 ) ;
return - V_143 ;
}
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
if ( ! ( V_164 -> V_105 & ( 1 << V_165 ) ) )
continue;
if ( V_125 -> V_79 [ V_165 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_165 , V_164 -> V_79 [ V_165 ] ) ;
return - V_143 ;
}
if ( V_125 -> V_106 [ V_165 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_165 , V_164 -> V_106 [ V_165 ] ) ;
return - V_143 ;
}
}
if ( ! F_41 ( V_125 , V_164 -> V_105 , V_126 ) )
return - V_168 ;
V_165 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_55 ( V_76 , V_77 , V_164 -> V_59 , V_164 -> V_134 ) ;
if ( V_12 != 0 )
break;
++ V_165 ;
}
if ( V_12 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_165 -- == 0 )
break;
F_63 ( V_76 , V_77 ) ;
}
return V_12 ;
}
return V_12 ;
}
static void
F_65 ( const struct V_73 * V_55 ,
struct V_109 V_114 [] )
{
struct V_43 * V_76 ;
unsigned int V_94 ;
unsigned int V_165 ;
F_66 (cpu) {
T_2 * V_49 = & F_67 ( V_169 , V_94 ) ;
V_165 = 0 ;
F_18 (iter, t->entries, t->size) {
struct V_109 * V_170 ;
T_3 V_171 , V_129 ;
unsigned int V_172 ;
V_170 = F_68 ( & V_76 -> V_114 , V_94 ) ;
do {
V_172 = F_69 ( V_49 ) ;
V_171 = V_170 -> V_171 ;
V_129 = V_170 -> V_129 ;
} while ( F_70 ( V_49 , V_172 ) );
F_35 ( V_114 [ V_165 ] , V_171 , V_129 ) ;
++ V_165 ;
}
}
}
static struct V_109 * F_71 ( const struct V_1 * V_86 )
{
unsigned int V_173 ;
struct V_109 * V_114 ;
const struct V_73 * V_74 = V_86 -> V_74 ;
V_173 = sizeof( struct V_109 ) * V_74 -> V_166 ;
V_114 = F_72 ( V_173 ) ;
if ( V_114 == NULL )
return F_73 ( - V_156 ) ;
F_65 ( V_74 , V_114 ) ;
return V_114 ;
}
static int
F_74 ( unsigned int V_174 ,
const struct V_1 * V_86 ,
void T_4 * V_175 )
{
unsigned int V_176 , V_177 ;
const struct V_43 * V_48 ;
struct V_109 * V_114 ;
const struct V_73 * V_74 = V_86 -> V_74 ;
int V_12 = 0 ;
const void * V_178 ;
V_114 = F_71 ( V_86 ) ;
if ( F_51 ( V_114 ) )
return F_52 ( V_114 ) ;
V_178 = V_74 -> V_78 ;
if ( F_75 ( V_175 , V_178 , V_174 ) != 0 ) {
V_12 = - V_179 ;
goto V_180;
}
for ( V_176 = 0 , V_177 = 0 ; V_176 < V_174 ; V_176 += V_48 -> V_137 , V_177 ++ ) {
unsigned int V_165 ;
const struct V_107 * V_139 ;
const struct V_47 * V_55 ;
V_48 = (struct V_43 * ) ( V_178 + V_176 ) ;
if ( F_75 ( V_175 + V_176
+ F_76 ( struct V_43 , V_114 ) ,
& V_114 [ V_177 ] ,
sizeof( V_114 [ V_177 ] ) ) != 0 ) {
V_12 = - V_179 ;
goto V_180;
}
for ( V_165 = sizeof( struct V_43 ) ;
V_165 < V_48 -> V_62 ;
V_165 += V_139 -> V_57 . V_147 ) {
V_139 = ( void * ) V_48 + V_165 ;
if ( F_75 ( V_175 + V_176 + V_165
+ F_76 ( struct V_107 ,
V_57 . V_132 . V_59 ) ,
V_139 -> V_57 . V_58 . V_112 -> V_59 ,
strlen ( V_139 -> V_57 . V_58 . V_112 -> V_59 ) + 1 )
!= 0 ) {
V_12 = - V_179 ;
goto V_180;
}
}
V_55 = F_13 ( V_48 ) ;
if ( F_75 ( V_175 + V_176 + V_48 -> V_62
+ F_76 ( struct V_47 ,
V_57 . V_132 . V_59 ) ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ,
strlen ( V_55 -> V_57 . V_58 . V_56 -> V_59 ) + 1 ) != 0 ) {
V_12 = - V_179 ;
goto V_180;
}
}
V_180:
F_77 ( V_114 ) ;
return V_12 ;
}
static void F_78 ( void * V_20 , const void * V_16 )
{
int V_118 = * ( V_181 * ) V_16 ;
if ( V_118 > 0 )
V_118 += F_79 ( V_82 , V_118 ) ;
memcpy ( V_20 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_80 ( void T_4 * V_20 , const void * V_16 )
{
V_181 V_182 = * ( int * ) V_16 ;
if ( V_182 > 0 )
V_182 -= F_79 ( V_82 , V_182 ) ;
return F_75 ( V_20 , & V_182 , sizeof( V_182 ) ) ? - V_179 : 0 ;
}
static int F_81 ( const struct V_43 * V_48 ,
const struct V_73 * V_2 ,
const void * V_44 , struct V_73 * V_125 )
{
const struct V_107 * V_108 ;
const struct V_47 * V_55 ;
unsigned int V_183 ;
int V_176 , V_165 , V_12 ;
V_176 = sizeof( struct V_43 ) - sizeof( struct V_184 ) ;
V_183 = ( void * ) V_48 - V_44 ;
F_33 (ematch, e)
V_176 += F_82 ( V_108 -> V_57 . V_58 . V_112 ) ;
V_55 = F_13 ( V_48 ) ;
V_176 += F_83 ( V_55 -> V_57 . V_58 . V_56 ) ;
V_125 -> V_134 -= V_176 ;
V_12 = F_84 ( V_82 , V_183 , V_176 ) ;
if ( V_12 )
return V_12 ;
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
if ( V_2 -> V_79 [ V_165 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_165 ] ) ) )
V_125 -> V_79 [ V_165 ] -= V_176 ;
if ( V_2 -> V_106 [ V_165 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_106 [ V_165 ] ) ) )
V_125 -> V_106 [ V_165 ] -= V_176 ;
}
return 0 ;
}
static int F_85 ( const struct V_73 * V_2 ,
struct V_73 * V_125 )
{
struct V_43 * V_76 ;
const void * V_178 ;
int V_12 ;
if ( ! V_125 || ! V_2 )
return - V_143 ;
memcpy ( V_125 , V_2 , F_76 ( struct V_73 , V_78 ) ) ;
V_125 -> V_185 = 0 ;
V_178 = V_2 -> V_78 ;
F_86 ( V_82 , V_2 -> V_166 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_12 = F_81 ( V_76 , V_2 , V_178 , V_125 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_87 ( struct V_77 * V_77 , void T_4 * V_132 ,
const int * V_115 , int V_186 )
{
char V_59 [ V_187 ] ;
struct V_1 * V_55 ;
int V_12 ;
if ( * V_115 != sizeof( struct V_188 ) ) {
F_8 ( L_43 , * V_115 ,
sizeof( struct V_188 ) ) ;
return - V_143 ;
}
if ( F_88 ( V_59 , V_132 , sizeof( V_59 ) ) != 0 )
return - V_179 ;
V_59 [ V_187 - 1 ] = '\0' ;
#ifdef F_89
if ( V_186 )
F_90 ( V_82 ) ;
#endif
V_55 = F_91 ( F_92 ( V_77 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( ! F_93 ( V_55 ) ) {
struct V_188 V_2 ;
const struct V_73 * V_74 = V_55 -> V_74 ;
#ifdef F_89
struct V_73 V_170 ;
if ( V_186 ) {
V_12 = F_85 ( V_74 , & V_170 ) ;
F_94 ( V_82 ) ;
V_74 = & V_170 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_105 = V_55 -> V_105 ;
memcpy ( V_2 . V_79 , V_74 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_106 , V_74 -> V_106 ,
sizeof( V_2 . V_106 ) ) ;
V_2 . V_167 = V_74 -> V_166 ;
V_2 . V_134 = V_74 -> V_134 ;
strcpy ( V_2 . V_59 , V_59 ) ;
if ( F_75 ( V_132 , & V_2 , * V_115 ) != 0 )
V_12 = - V_179 ;
else
V_12 = 0 ;
F_95 ( V_55 ) ;
F_45 ( V_55 -> V_142 ) ;
} else
V_12 = V_55 ? F_52 ( V_55 ) : - V_189 ;
#ifdef F_89
if ( V_186 )
F_96 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_97 ( struct V_77 * V_77 , struct V_190 T_4 * V_191 ,
const int * V_115 )
{
int V_12 ;
struct V_190 V_192 ;
struct V_1 * V_55 ;
if ( * V_115 < sizeof( V_192 ) ) {
F_8 ( L_45 , * V_115 , sizeof( V_192 ) ) ;
return - V_143 ;
}
if ( F_88 ( & V_192 , V_191 , sizeof( V_192 ) ) != 0 )
return - V_179 ;
if ( * V_115 != sizeof( struct V_190 ) + V_192 . V_134 ) {
F_8 ( L_46 ,
* V_115 , sizeof( V_192 ) + V_192 . V_134 ) ;
return - V_143 ;
}
V_55 = F_92 ( V_77 , V_82 , V_192 . V_59 ) ;
if ( ! F_93 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
F_8 ( L_47 , V_74 -> V_166 ) ;
if ( V_192 . V_134 == V_74 -> V_134 )
V_12 = F_74 ( V_74 -> V_134 ,
V_55 , V_191 -> V_193 ) ;
else {
F_8 ( L_48 ,
V_74 -> V_134 , V_192 . V_134 ) ;
V_12 = - V_194 ;
}
F_45 ( V_55 -> V_142 ) ;
F_95 ( V_55 ) ;
} else
V_12 = V_55 ? F_52 ( V_55 ) : - V_189 ;
return V_12 ;
}
static int
F_98 ( struct V_77 * V_77 , const char * V_59 , unsigned int V_105 ,
struct V_73 * V_125 , unsigned int V_195 ,
void T_4 * V_196 )
{
int V_12 ;
struct V_1 * V_55 ;
struct V_73 * V_197 ;
struct V_109 * V_114 ;
struct V_43 * V_76 ;
V_12 = 0 ;
V_114 = F_72 ( V_195 * sizeof( struct V_109 ) ) ;
if ( ! V_114 ) {
V_12 = - V_156 ;
goto V_71;
}
V_55 = F_91 ( F_92 ( V_77 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( F_93 ( V_55 ) ) {
V_12 = V_55 ? F_52 ( V_55 ) : - V_189 ;
goto V_198;
}
if ( V_105 != V_55 -> V_105 ) {
F_8 ( L_49 ,
V_105 , V_55 -> V_105 ) ;
V_12 = - V_143 ;
goto V_199;
}
V_197 = F_99 ( V_55 , V_195 , V_125 , & V_12 ) ;
if ( ! V_197 )
goto V_199;
F_8 ( L_50 ,
V_197 -> V_166 , V_197 -> V_185 , V_125 -> V_166 ) ;
if ( ( V_197 -> V_166 > V_197 -> V_185 ) ||
( V_125 -> V_166 <= V_197 -> V_185 ) )
F_45 ( V_55 -> V_142 ) ;
if ( ( V_197 -> V_166 > V_197 -> V_185 ) &&
( V_125 -> V_166 <= V_197 -> V_185 ) )
F_45 ( V_55 -> V_142 ) ;
F_65 ( V_197 , V_114 ) ;
F_18 (iter, oldinfo->entries, oldinfo->size)
F_63 ( V_76 , V_77 ) ;
F_100 ( V_197 ) ;
if ( F_75 ( V_196 , V_114 ,
sizeof( struct V_109 ) * V_195 ) != 0 ) {
F_101 ( L_51 ) ;
}
F_77 ( V_114 ) ;
F_95 ( V_55 ) ;
return V_12 ;
V_199:
F_45 ( V_55 -> V_142 ) ;
F_95 ( V_55 ) ;
V_198:
F_77 ( V_114 ) ;
V_71:
return V_12 ;
}
static int
F_102 ( struct V_77 * V_77 , const void T_4 * V_132 , unsigned int V_115 )
{
int V_12 ;
struct V_163 V_170 ;
struct V_73 * V_125 ;
void * V_178 ;
struct V_43 * V_76 ;
if ( F_88 ( & V_170 , V_132 , sizeof( V_170 ) ) != 0 )
return - V_179 ;
if ( V_170 . V_195 >= V_200 / sizeof( struct V_109 ) )
return - V_156 ;
if ( V_170 . V_195 == 0 )
return - V_143 ;
V_170 . V_59 [ sizeof( V_170 . V_59 ) - 1 ] = 0 ;
V_125 = F_103 ( V_170 . V_134 ) ;
if ( ! V_125 )
return - V_156 ;
V_178 = V_125 -> V_78 ;
if ( F_88 ( V_178 , V_132 + sizeof( V_170 ) ,
V_170 . V_134 ) != 0 ) {
V_12 = - V_179 ;
goto V_201;
}
V_12 = F_64 ( V_77 , V_125 , V_178 , & V_170 ) ;
if ( V_12 != 0 )
goto V_201;
F_8 ( L_52 ) ;
V_12 = F_98 ( V_77 , V_170 . V_59 , V_170 . V_105 , V_125 ,
V_170 . V_195 , V_170 . V_114 ) ;
if ( V_12 )
goto V_202;
return 0 ;
V_202:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_63 ( V_76 , V_77 ) ;
V_201:
F_100 ( V_125 ) ;
return V_12 ;
}
static int
F_104 ( struct V_77 * V_77 , const void T_4 * V_132 ,
unsigned int V_115 , int V_186 )
{
unsigned int V_165 ;
struct V_203 V_170 ;
struct V_109 * V_204 ;
unsigned int V_195 ;
const char * V_59 ;
int V_134 ;
void * V_205 ;
struct V_1 * V_55 ;
const struct V_73 * V_74 ;
int V_12 = 0 ;
struct V_43 * V_76 ;
unsigned int V_96 ;
#ifdef F_89
struct V_206 V_207 ;
if ( V_186 ) {
V_205 = & V_207 ;
V_134 = sizeof( struct V_206 ) ;
} else
#endif
{
V_205 = & V_170 ;
V_134 = sizeof( struct V_203 ) ;
}
if ( F_88 ( V_205 , V_132 , V_134 ) != 0 )
return - V_179 ;
#ifdef F_89
if ( V_186 ) {
V_195 = V_207 . V_195 ;
V_59 = V_207 . V_59 ;
} else
#endif
{
V_195 = V_170 . V_195 ;
V_59 = V_170 . V_59 ;
}
if ( V_115 != V_134 + V_195 * sizeof( struct V_109 ) )
return - V_143 ;
V_204 = F_105 ( V_115 - V_134 ) ;
if ( ! V_204 )
return - V_156 ;
if ( F_88 ( V_204 , V_132 + V_134 , V_115 - V_134 ) != 0 ) {
V_12 = - V_179 ;
goto free;
}
V_55 = F_92 ( V_77 , V_82 , V_59 ) ;
if ( F_93 ( V_55 ) ) {
V_12 = V_55 ? F_52 ( V_55 ) : - V_189 ;
goto free;
}
F_26 () ;
V_74 = V_55 -> V_74 ;
if ( V_74 -> V_166 != V_195 ) {
V_12 = - V_143 ;
goto V_208;
}
V_165 = 0 ;
V_96 = F_27 () ;
F_18 (iter, private->entries, private->size) {
struct V_109 * V_170 ;
V_170 = F_34 ( & V_76 -> V_114 ) ;
F_35 ( * V_170 , V_204 [ V_165 ] . V_171 , V_204 [ V_165 ] . V_129 ) ;
++ V_165 ;
}
F_38 ( V_96 ) ;
V_208:
F_39 () ;
F_95 ( V_55 ) ;
F_45 ( V_55 -> V_142 ) ;
free:
F_77 ( V_204 ) ;
return V_12 ;
}
static int
F_106 ( struct V_43 * V_48 , void T_4 * * V_209 ,
unsigned int * V_134 , struct V_109 * V_114 ,
unsigned int V_165 )
{
struct V_47 * V_55 ;
struct V_184 T_4 * V_210 ;
T_5 V_62 , V_137 ;
T_6 V_211 ;
const struct V_107 * V_108 ;
int V_12 = 0 ;
V_211 = * V_134 ;
V_210 = (struct V_184 T_4 * ) * V_209 ;
if ( F_75 ( V_210 , V_48 , sizeof( struct V_43 ) ) != 0 ||
F_75 ( & V_210 -> V_114 , & V_114 [ V_165 ] ,
sizeof( V_114 [ V_165 ] ) ) != 0 )
return - V_179 ;
* V_209 += sizeof( struct V_184 ) ;
* V_134 -= sizeof( struct V_43 ) - sizeof( struct V_184 ) ;
F_33 (ematch, e) {
V_12 = F_107 ( V_108 , V_209 , V_134 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_62 = V_48 -> V_62 - ( V_211 - * V_134 ) ;
V_55 = F_14 ( V_48 ) ;
V_12 = F_108 ( V_55 , V_209 , V_134 ) ;
if ( V_12 )
return V_12 ;
V_137 = V_48 -> V_137 - ( V_211 - * V_134 ) ;
if ( F_109 ( V_62 , & V_210 -> V_62 ) != 0 ||
F_109 ( V_137 , & V_210 -> V_137 ) != 0 )
return - V_179 ;
return 0 ;
}
static int
F_110 ( struct V_107 * V_139 ,
const char * V_59 ,
const struct V_9 * V_6 ,
int * V_134 )
{
struct V_148 * V_112 ;
V_112 = F_50 ( V_103 , V_139 -> V_57 . V_132 . V_59 ,
V_139 -> V_57 . V_132 . V_149 ) ;
if ( F_51 ( V_112 ) ) {
F_8 ( L_53 ,
V_139 -> V_57 . V_132 . V_59 ) ;
return F_52 ( V_112 ) ;
}
V_139 -> V_57 . V_58 . V_112 = V_112 ;
* V_134 += F_82 ( V_112 ) ;
return 0 ;
}
static void F_111 ( struct V_184 * V_48 )
{
struct V_47 * V_55 ;
struct V_107 * V_108 ;
F_33 (ematch, e)
F_45 ( V_108 -> V_57 . V_58 . V_112 -> V_142 ) ;
V_55 = F_112 ( V_48 ) ;
F_45 ( V_55 -> V_57 . V_58 . V_56 -> V_142 ) ;
}
static int
F_113 ( struct V_184 * V_48 ,
struct V_73 * V_125 ,
unsigned int * V_134 ,
const unsigned char * V_44 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
const char * V_59 )
{
struct V_107 * V_108 ;
struct V_47 * V_55 ;
struct V_153 * V_56 ;
unsigned int V_183 ;
unsigned int V_154 ;
int V_12 , V_176 , V_161 ;
F_8 ( L_54 , V_48 ) ;
if ( ( unsigned long ) V_48 % F_62 ( struct V_184 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_184 ) >= V_158 ) {
F_8 ( L_55 , V_48 , V_158 ) ;
return - V_143 ;
}
if ( V_48 -> V_137 < sizeof( struct V_184 ) +
sizeof( struct V_212 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_137 ) ;
return - V_143 ;
}
V_12 = F_46 ( (struct V_43 * ) V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_176 = sizeof( struct V_43 ) - sizeof( struct V_184 ) ;
V_183 = ( void * ) V_48 - ( void * ) V_44 ;
V_154 = 0 ;
F_33 (ematch, e) {
V_12 = F_110 ( V_108 , V_59 , & V_48 -> V_6 , & V_176 ) ;
if ( V_12 != 0 )
goto V_213;
++ V_154 ;
}
V_55 = F_112 ( V_48 ) ;
V_56 = F_58 ( V_103 , V_55 -> V_57 . V_132 . V_59 ,
V_55 -> V_57 . V_132 . V_149 ) ;
if ( F_51 ( V_56 ) ) {
F_8 ( L_56 ,
V_55 -> V_57 . V_132 . V_59 ) ;
V_12 = F_52 ( V_56 ) ;
goto V_213;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_176 += F_83 ( V_56 ) ;
* V_134 += V_176 ;
V_12 = F_84 ( V_82 , V_183 , V_176 ) ;
if ( V_12 )
goto V_71;
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ( unsigned char * ) V_48 - V_44 == V_159 [ V_161 ] )
V_125 -> V_79 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_160 [ V_161 ] )
V_125 -> V_106 [ V_161 ] = V_160 [ V_161 ] ;
}
memset ( & V_48 -> V_114 , 0 , sizeof( V_48 -> V_114 ) ) ;
V_48 -> V_131 = 0 ;
return 0 ;
V_71:
F_45 ( V_55 -> V_57 . V_58 . V_56 -> V_142 ) ;
V_213:
F_33 (ematch, e) {
if ( V_154 -- == 0 )
break;
F_45 ( V_108 -> V_57 . V_58 . V_112 -> V_142 ) ;
}
return V_12 ;
}
static int
F_114 ( struct V_184 * V_48 , void * * V_209 ,
unsigned int * V_134 , const char * V_59 ,
struct V_73 * V_125 , unsigned char * V_44 )
{
struct V_47 * V_55 ;
struct V_153 * V_56 ;
struct V_43 * V_214 ;
unsigned int V_211 ;
int V_12 , V_161 ;
struct V_107 * V_108 ;
V_12 = 0 ;
V_211 = * V_134 ;
V_214 = (struct V_43 * ) * V_209 ;
memcpy ( V_214 , V_48 , sizeof( struct V_43 ) ) ;
memcpy ( & V_214 -> V_114 , & V_48 -> V_114 , sizeof( V_48 -> V_114 ) ) ;
* V_209 += sizeof( struct V_43 ) ;
* V_134 += sizeof( struct V_43 ) - sizeof( struct V_184 ) ;
F_33 (ematch, e) {
V_12 = F_115 ( V_108 , V_209 , V_134 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_214 -> V_62 = V_48 -> V_62 - ( V_211 - * V_134 ) ;
V_55 = F_112 ( V_48 ) ;
V_56 = V_55 -> V_57 . V_58 . V_56 ;
F_116 ( V_55 , V_209 , V_134 ) ;
V_214 -> V_137 = V_48 -> V_137 - ( V_211 - * V_134 ) ;
for ( V_161 = 0 ; V_161 < V_127 ; V_161 ++ ) {
if ( ( unsigned char * ) V_214 - V_44 < V_125 -> V_79 [ V_161 ] )
V_125 -> V_79 [ V_161 ] -= V_211 - * V_134 ;
if ( ( unsigned char * ) V_214 - V_44 < V_125 -> V_106 [ V_161 ] )
V_125 -> V_106 [ V_161 ] -= V_211 - * V_134 ;
}
return V_12 ;
}
static int
F_117 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 )
{
struct V_107 * V_108 ;
struct V_145 V_155 ;
unsigned int V_154 ;
int V_12 = 0 ;
V_48 -> V_114 . V_129 = F_56 () ;
if ( F_57 ( V_48 -> V_114 . V_129 ) )
return - V_156 ;
V_154 = 0 ;
V_155 . V_77 = V_77 ;
V_155 . V_86 = V_59 ;
V_155 . V_146 = & V_48 -> V_6 ;
V_155 . V_152 = V_48 -> V_131 ;
V_155 . V_102 = V_103 ;
F_33 (ematch, e) {
V_12 = F_47 ( V_108 , & V_155 ) ;
if ( V_12 != 0 )
goto V_157;
++ V_154 ;
}
V_12 = F_53 ( V_48 , V_77 , V_59 ) ;
if ( V_12 )
goto V_157;
return 0 ;
V_157:
F_33 (ematch, e) {
if ( V_154 -- == 0 )
break;
F_44 ( V_108 , V_77 ) ;
}
F_59 ( V_48 -> V_114 . V_129 ) ;
return V_12 ;
}
static int
F_118 ( struct V_77 * V_77 ,
const char * V_59 ,
unsigned int V_105 ,
struct V_73 * * V_215 ,
void * * V_216 ,
unsigned int V_174 ,
unsigned int V_166 ,
unsigned int * V_159 ,
unsigned int * V_160 )
{
unsigned int V_165 , V_154 ;
struct V_73 * V_125 , * V_2 ;
void * V_128 , * V_126 , * V_217 ;
struct V_184 * V_218 ;
struct V_43 * V_219 ;
unsigned int V_134 ;
int V_12 ;
V_2 = * V_215 ;
V_126 = * V_216 ;
V_134 = V_174 ;
V_2 -> V_166 = V_166 ;
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
V_2 -> V_79 [ V_165 ] = 0xFFFFFFFF ;
V_2 -> V_106 [ V_165 ] = 0xFFFFFFFF ;
}
F_8 ( L_57 , V_2 -> V_134 ) ;
V_154 = 0 ;
F_90 ( V_82 ) ;
F_86 ( V_82 , V_166 ) ;
F_18 (iter0, entry0, total_size) {
V_12 = F_113 ( V_218 , V_2 , & V_134 ,
V_126 ,
V_126 + V_174 ,
V_159 ,
V_160 ,
V_59 ) ;
if ( V_12 != 0 )
goto V_220;
++ V_154 ;
}
V_12 = - V_143 ;
if ( V_154 != V_166 ) {
F_8 ( L_58 ,
V_154 , V_166 ) ;
goto V_220;
}
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
if ( ! ( V_105 & ( 1 << V_165 ) ) )
continue;
if ( V_2 -> V_79 [ V_165 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_165 , V_159 [ V_165 ] ) ;
goto V_220;
}
if ( V_2 -> V_106 [ V_165 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_165 , V_160 [ V_165 ] ) ;
goto V_220;
}
}
V_12 = - V_156 ;
V_125 = F_103 ( V_134 ) ;
if ( ! V_125 )
goto V_220;
V_125 -> V_166 = V_166 ;
for ( V_165 = 0 ; V_165 < V_127 ; V_165 ++ ) {
V_125 -> V_79 [ V_165 ] = V_2 -> V_79 [ V_165 ] ;
V_125 -> V_106 [ V_165 ] = V_2 -> V_106 [ V_165 ] ;
}
V_217 = V_125 -> V_78 ;
V_128 = V_217 ;
V_134 = V_174 ;
F_18 (iter0, entry0, total_size) {
V_12 = F_114 ( V_218 , & V_128 , & V_134 ,
V_59 , V_125 , V_217 ) ;
if ( V_12 != 0 )
break;
}
F_94 ( V_82 ) ;
F_96 ( V_82 ) ;
if ( V_12 )
goto V_201;
V_12 = - V_168 ;
if ( ! F_41 ( V_125 , V_105 , V_217 ) )
goto V_201;
V_165 = 0 ;
F_18 (iter1, entry1, newinfo->size) {
V_12 = F_117 ( V_219 , V_77 , V_59 ) ;
if ( V_12 != 0 )
break;
++ V_165 ;
if ( strcmp ( F_14 ( V_219 ) -> V_57 . V_132 . V_59 ,
V_60 ) == 0 )
++ V_125 -> V_121 ;
}
if ( V_12 ) {
int V_221 = V_165 ;
V_154 -= V_165 ;
F_18 (iter0, entry0, newinfo->size) {
if ( V_221 -- > 0 )
continue;
if ( V_154 -- == 0 )
break;
F_111 ( V_218 ) ;
}
F_18 (iter1, entry1, newinfo->size) {
if ( V_165 -- == 0 )
break;
F_63 ( V_219 , V_77 ) ;
}
F_100 ( V_125 ) ;
return V_12 ;
}
* V_215 = V_125 ;
* V_216 = V_217 ;
F_100 ( V_2 ) ;
return 0 ;
V_201:
F_100 ( V_125 ) ;
V_71:
F_18 (iter0, entry0, total_size) {
if ( V_154 -- == 0 )
break;
F_111 ( V_218 ) ;
}
return V_12 ;
V_220:
F_94 ( V_82 ) ;
F_96 ( V_82 ) ;
goto V_71;
}
static int
F_119 ( struct V_77 * V_77 , void T_4 * V_132 , unsigned int V_115 )
{
int V_12 ;
struct V_222 V_170 ;
struct V_73 * V_125 ;
void * V_178 ;
struct V_43 * V_76 ;
if ( F_88 ( & V_170 , V_132 , sizeof( V_170 ) ) != 0 )
return - V_179 ;
if ( V_170 . V_134 >= V_200 / F_120 () )
return - V_156 ;
if ( V_170 . V_195 >= V_200 / sizeof( struct V_109 ) )
return - V_156 ;
if ( V_170 . V_195 == 0 )
return - V_143 ;
V_170 . V_59 [ sizeof( V_170 . V_59 ) - 1 ] = 0 ;
V_125 = F_103 ( V_170 . V_134 ) ;
if ( ! V_125 )
return - V_156 ;
V_178 = V_125 -> V_78 ;
if ( F_88 ( V_178 , V_132 + sizeof( V_170 ) ,
V_170 . V_134 ) != 0 ) {
V_12 = - V_179 ;
goto V_201;
}
V_12 = F_118 ( V_77 , V_170 . V_59 , V_170 . V_105 ,
& V_125 , & V_178 , V_170 . V_134 ,
V_170 . V_167 , V_170 . V_79 ,
V_170 . V_106 ) ;
if ( V_12 != 0 )
goto V_201;
F_8 ( L_59 ) ;
V_12 = F_98 ( V_77 , V_170 . V_59 , V_170 . V_105 , V_125 ,
V_170 . V_195 , F_121 ( V_170 . V_114 ) ) ;
if ( V_12 )
goto V_202;
return 0 ;
V_202:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_63 ( V_76 , V_77 ) ;
V_201:
F_100 ( V_125 ) ;
return V_12 ;
}
static int
F_122 ( struct V_223 * V_224 , int V_225 , void T_4 * V_132 ,
unsigned int V_115 )
{
int V_12 ;
if ( ! F_123 ( F_124 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_119 ( F_124 ( V_224 ) , V_132 , V_115 ) ;
break;
case V_230 :
V_12 = F_104 ( F_124 ( V_224 ) , V_132 , V_115 , 1 ) ;
break;
default:
F_8 ( L_60 , V_225 ) ;
V_12 = - V_143 ;
}
return V_12 ;
}
static int
F_125 ( unsigned int V_174 , struct V_1 * V_86 ,
void T_4 * V_175 )
{
struct V_109 * V_114 ;
const struct V_73 * V_74 = V_86 -> V_74 ;
void T_4 * V_128 ;
unsigned int V_134 ;
int V_12 = 0 ;
unsigned int V_165 = 0 ;
struct V_43 * V_76 ;
V_114 = F_71 ( V_86 ) ;
if ( F_51 ( V_114 ) )
return F_52 ( V_114 ) ;
V_128 = V_175 ;
V_134 = V_174 ;
F_18 (iter, private->entries, total_size) {
V_12 = F_106 ( V_76 , & V_128 ,
& V_134 , V_114 , V_165 ++ ) ;
if ( V_12 != 0 )
break;
}
F_77 ( V_114 ) ;
return V_12 ;
}
static int
F_126 ( struct V_77 * V_77 , struct V_231 T_4 * V_191 ,
int * V_115 )
{
int V_12 ;
struct V_231 V_192 ;
struct V_1 * V_55 ;
if ( * V_115 < sizeof( V_192 ) ) {
F_8 ( L_61 , * V_115 , sizeof( V_192 ) ) ;
return - V_143 ;
}
if ( F_88 ( & V_192 , V_191 , sizeof( V_192 ) ) != 0 )
return - V_179 ;
if ( * V_115 != sizeof( struct V_231 ) + V_192 . V_134 ) {
F_8 ( L_62 ,
* V_115 , sizeof( V_192 ) + V_192 . V_134 ) ;
return - V_143 ;
}
F_90 ( V_82 ) ;
V_55 = F_92 ( V_77 , V_82 , V_192 . V_59 ) ;
if ( ! F_93 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
struct V_73 V_2 ;
F_8 ( L_47 , V_74 -> V_166 ) ;
V_12 = F_85 ( V_74 , & V_2 ) ;
if ( ! V_12 && V_192 . V_134 == V_2 . V_134 ) {
V_12 = F_125 ( V_74 -> V_134 ,
V_55 , V_191 -> V_193 ) ;
} else if ( ! V_12 ) {
F_8 ( L_63 ,
V_74 -> V_134 , V_192 . V_134 ) ;
V_12 = - V_194 ;
}
F_94 ( V_82 ) ;
F_45 ( V_55 -> V_142 ) ;
F_95 ( V_55 ) ;
} else
V_12 = V_55 ? F_52 ( V_55 ) : - V_189 ;
F_96 ( V_82 ) ;
return V_12 ;
}
static int
F_127 ( struct V_223 * V_224 , int V_225 , void T_4 * V_132 , int * V_115 )
{
int V_12 ;
if ( ! F_123 ( F_124 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_87 ( F_124 ( V_224 ) , V_132 , V_115 , 1 ) ;
break;
case V_233 :
V_12 = F_126 ( F_124 ( V_224 ) , V_132 , V_115 ) ;
break;
default:
V_12 = F_128 ( V_224 , V_225 , V_132 , V_115 ) ;
}
return V_12 ;
}
static int
F_129 ( struct V_223 * V_224 , int V_225 , void T_4 * V_132 , unsigned int V_115 )
{
int V_12 ;
if ( ! F_123 ( F_124 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_102 ( F_124 ( V_224 ) , V_132 , V_115 ) ;
break;
case V_230 :
V_12 = F_104 ( F_124 ( V_224 ) , V_132 , V_115 , 0 ) ;
break;
default:
F_8 ( L_60 , V_225 ) ;
V_12 = - V_143 ;
}
return V_12 ;
}
static int
F_128 ( struct V_223 * V_224 , int V_225 , void T_4 * V_132 , int * V_115 )
{
int V_12 ;
if ( ! F_123 ( F_124 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_87 ( F_124 ( V_224 ) , V_132 , V_115 , 0 ) ;
break;
case V_233 :
V_12 = F_97 ( F_124 ( V_224 ) , V_132 , V_115 ) ;
break;
case V_234 :
case V_235 : {
struct V_236 V_237 ;
int V_56 ;
if ( * V_115 != sizeof( V_237 ) ) {
V_12 = - V_143 ;
break;
}
if ( F_88 ( & V_237 , V_132 , sizeof( V_237 ) ) != 0 ) {
V_12 = - V_179 ;
break;
}
V_237 . V_59 [ sizeof( V_237 . V_59 ) - 1 ] = 0 ;
if ( V_225 == V_235 )
V_56 = 1 ;
else
V_56 = 0 ;
F_91 ( F_130 ( V_82 , V_237 . V_59 ,
V_237 . V_149 ,
V_56 , & V_12 ) ,
L_64 , V_237 . V_59 ) ;
break;
}
default:
F_8 ( L_65 , V_225 ) ;
V_12 = - V_143 ;
}
return V_12 ;
}
struct V_1 * F_131 ( struct V_77 * V_77 ,
const struct V_1 * V_86 ,
const struct V_163 * V_164 )
{
int V_12 ;
struct V_73 * V_125 ;
struct V_73 V_238 = { 0 } ;
void * V_178 ;
struct V_1 * V_239 ;
V_125 = F_103 ( V_164 -> V_134 ) ;
if ( ! V_125 ) {
V_12 = - V_156 ;
goto V_71;
}
V_178 = V_125 -> V_78 ;
memcpy ( V_178 , V_164 -> V_78 , V_164 -> V_134 ) ;
V_12 = F_64 ( V_77 , V_125 , V_178 , V_164 ) ;
if ( V_12 != 0 )
goto V_240;
V_239 = F_132 ( V_77 , V_86 , & V_238 , V_125 ) ;
if ( F_51 ( V_239 ) ) {
V_12 = F_52 ( V_239 ) ;
goto V_240;
}
return V_239 ;
V_240:
F_100 ( V_125 ) ;
V_71:
return F_73 ( V_12 ) ;
}
void F_133 ( struct V_77 * V_77 , struct V_1 * V_86 )
{
struct V_73 * V_74 ;
void * V_178 ;
struct V_241 * V_242 = V_86 -> V_142 ;
struct V_43 * V_76 ;
V_74 = F_134 ( V_86 ) ;
V_178 = V_74 -> V_78 ;
F_18 (iter, loc_cpu_entry, private->size)
F_63 ( V_76 , V_77 ) ;
if ( V_74 -> V_166 > V_74 -> V_185 )
F_45 ( V_242 ) ;
F_100 ( V_74 ) ;
}
static inline bool
F_135 ( T_7 V_243 , T_7 V_244 , T_7 V_245 ,
T_7 type , T_7 V_246 ,
bool V_247 )
{
return ( ( V_243 == 0xFF ) ||
( type == V_243 && V_246 >= V_244 && V_246 <= V_245 ) )
^ V_247 ;
}
static bool
F_136 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_248 * V_249 ;
struct V_248 V_250 ;
const struct V_251 * V_252 = V_40 -> V_113 ;
if ( V_40 -> V_97 != 0 )
return false ;
V_249 = F_137 ( V_38 , V_40 -> V_100 , sizeof( V_250 ) , & V_250 ) ;
if ( V_249 == NULL ) {
F_8 ( L_66 ) ;
V_40 -> V_101 = true ;
return false ;
}
return F_135 ( V_252 -> type ,
V_252 -> V_246 [ 0 ] ,
V_252 -> V_246 [ 1 ] ,
V_249 -> type , V_249 -> V_246 ,
! ! ( V_252 -> V_22 & V_253 ) ) ;
}
static int F_138 ( const struct V_145 * V_40 )
{
const struct V_251 * V_252 = V_40 -> V_113 ;
return ( V_252 -> V_22 & ~ V_253 ) ? - V_143 : 0 ;
}
static int T_8 F_139 ( struct V_77 * V_77 )
{
return F_140 ( V_77 , V_103 ) ;
}
static void T_9 F_141 ( struct V_77 * V_77 )
{
F_142 ( V_77 , V_103 ) ;
}
static int T_10 F_143 ( void )
{
int V_12 ;
V_12 = F_144 ( & V_254 ) ;
if ( V_12 < 0 )
goto V_255;
V_12 = F_145 ( V_256 , F_146 ( V_256 ) ) ;
if ( V_12 < 0 )
goto V_257;
V_12 = F_147 ( V_258 , F_146 ( V_258 ) ) ;
if ( V_12 < 0 )
goto V_259;
V_12 = F_148 ( & V_260 ) ;
if ( V_12 < 0 )
goto V_261;
F_149 ( L_67 ) ;
return 0 ;
V_261:
F_150 ( V_258 , F_146 ( V_258 ) ) ;
V_259:
F_151 ( V_256 , F_146 ( V_256 ) ) ;
V_257:
F_152 ( & V_254 ) ;
V_255:
return V_12 ;
}
static void T_11 F_153 ( void )
{
F_154 ( & V_260 ) ;
F_150 ( V_258 , F_146 ( V_258 ) ) ;
F_151 ( V_256 , F_146 ( V_256 ) ) ;
F_152 ( & V_254 ) ;
}
