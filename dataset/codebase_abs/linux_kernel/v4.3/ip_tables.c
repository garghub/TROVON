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
static inline
struct V_43 * F_20 ( const struct V_43 * V_84 )
{
return ( void * ) V_84 + V_84 -> V_85 ;
}
unsigned int
F_21 ( struct V_37 * V_38 ,
unsigned int V_68 ,
const struct V_86 * V_87 ,
struct V_1 * V_88 )
{
static const char V_89 [ V_90 ] V_91 ( ( F_22 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_92 ;
struct V_43 * V_48 , * * V_93 ;
unsigned int V_94 , V_95 ;
const struct V_73 * V_74 ;
struct V_39 V_96 ;
unsigned int V_97 ;
V_94 = 0 ;
V_6 = F_23 ( V_38 ) ;
V_7 = V_87 -> V_70 ? V_87 -> V_70 -> V_59 : V_89 ;
V_8 = V_87 -> V_71 ? V_87 -> V_71 -> V_59 : V_89 ;
V_96 . V_98 = F_24 ( V_6 -> V_99 ) & V_100 ;
V_96 . V_101 = F_25 ( V_38 ) ;
V_96 . V_102 = false ;
V_96 . V_70 = V_87 -> V_70 ;
V_96 . V_71 = V_87 -> V_71 ;
V_96 . V_103 = V_104 ;
V_96 . V_105 = V_68 ;
F_26 ( V_88 -> V_106 & ( 1 << V_68 ) ) ;
F_27 () ;
V_97 = F_28 () ;
V_74 = V_88 -> V_74 ;
V_95 = F_29 () ;
F_30 () ;
V_92 = V_74 -> V_78 ;
V_93 = (struct V_43 * * ) V_74 -> V_93 [ V_95 ] ;
if ( F_31 ( & V_107 ) )
V_93 += V_74 -> V_108 * F_32 ( V_109 ) ;
V_48 = F_11 ( V_92 , V_74 -> V_79 [ V_68 ] ) ;
F_33 ( L_14 ,
V_88 -> V_59 , V_68 ,
F_11 ( V_92 , V_74 -> V_110 [ V_68 ] ) ) ;
do {
const struct V_47 * V_55 ;
const struct V_111 * V_112 ;
struct V_113 * V_114 ;
F_26 ( V_48 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_48 -> V_6 , V_96 . V_98 ) ) {
V_115:
V_48 = F_20 ( V_48 ) ;
continue;
}
F_34 (ematch, e) {
V_96 . V_116 = V_112 -> V_57 . V_58 . V_116 ;
V_96 . V_117 = V_112 -> V_61 ;
if ( ! V_96 . V_116 -> V_116 ( V_38 , & V_96 ) )
goto V_115;
}
V_114 = F_35 ( & V_48 -> V_118 ) ;
F_36 ( * V_114 , V_38 -> V_119 , 1 ) ;
V_55 = F_14 ( V_48 ) ;
F_26 ( V_55 -> V_57 . V_58 . V_56 ) ;
#if F_37 ( V_120 )
if ( F_38 ( V_38 -> V_121 ) )
F_16 ( V_38 , V_68 , V_87 -> V_70 , V_87 -> V_71 ,
V_88 -> V_59 , V_74 , V_48 ) ;
#endif
if ( ! V_55 -> V_57 . V_58 . V_56 -> V_56 ) {
int V_122 ;
V_122 = ( (struct V_54 * ) V_55 ) -> V_64 ;
if ( V_122 < 0 ) {
if ( V_122 != V_123 ) {
V_64 = ( unsigned int ) ( - V_122 ) - 1 ;
break;
}
if ( V_94 == 0 ) {
V_48 = F_11 ( V_92 ,
V_74 -> V_110 [ V_68 ] ) ;
F_33 ( L_15
L_16 , V_48 ) ;
} else {
V_48 = V_93 [ -- V_94 ] ;
F_33 ( L_17 ,
V_48 , V_94 ) ;
V_48 = F_20 ( V_48 ) ;
}
continue;
}
if ( V_92 + V_122 != F_20 ( V_48 ) &&
! ( V_48 -> V_6 . V_32 & V_124 ) ) {
V_93 [ V_94 ++ ] = V_48 ;
F_33 ( L_18 ,
V_48 , V_94 - 1 ) ;
}
V_48 = F_11 ( V_92 , V_122 ) ;
continue;
}
V_96 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_96 . V_41 = V_55 -> V_61 ;
V_64 = V_55 -> V_57 . V_58 . V_56 -> V_56 ( V_38 , & V_96 ) ;
V_6 = F_23 ( V_38 ) ;
if ( V_64 == V_125 )
V_48 = F_20 ( V_48 ) ;
else
break;
} while ( ! V_96 . V_102 );
F_33 ( L_19 , V_126 , V_94 ) ;
F_39 ( V_97 ) ;
F_40 () ;
#ifdef F_41
return V_127 ;
#else
if ( V_96 . V_102 )
return V_42 ;
else return V_64 ;
#endif
}
static int
F_42 ( const struct V_73 * V_128 ,
unsigned int V_106 , void * V_129 )
{
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_130 ; V_68 ++ ) {
unsigned int V_131 = V_128 -> V_79 [ V_68 ] ;
struct V_43 * V_48 = (struct V_43 * ) ( V_129 + V_131 ) ;
if ( ! ( V_106 & ( 1 << V_68 ) ) )
continue;
V_48 -> V_118 . V_132 = V_131 ;
for (; ; ) {
const struct V_54 * V_55
= ( void * ) F_13 ( V_48 ) ;
int V_133 = V_48 -> V_134 & ( 1 << V_68 ) ;
if ( V_48 -> V_134 & ( 1 << V_130 ) ) {
F_43 ( L_20 ,
V_68 , V_131 , V_48 -> V_134 ) ;
return 0 ;
}
V_48 -> V_134 |= ( ( 1 << V_68 ) | ( 1 << V_130 ) ) ;
if ( ( V_48 -> V_62 == sizeof( struct V_43 ) &&
( strcmp ( V_55 -> V_56 . V_57 . V_135 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < 0 && F_12 ( & V_48 -> V_6 ) ) ||
V_133 ) {
unsigned int V_136 , V_137 ;
if ( ( strcmp ( V_55 -> V_56 . V_57 . V_135 . V_59 ,
V_63 ) == 0 ) &&
V_55 -> V_64 < - V_138 - 1 ) {
F_8 ( L_21
L_22 ,
V_55 -> V_64 ) ;
return 0 ;
}
do {
V_48 -> V_134 ^= ( 1 << V_130 ) ;
#ifdef F_44
if ( V_48 -> V_134
& ( 1 << V_130 ) ) {
F_8 ( L_23
L_24
L_25 ,
V_68 , V_131 ) ;
}
#endif
V_136 = V_131 ;
V_131 = V_48 -> V_118 . V_132 ;
V_48 -> V_118 . V_132 = 0 ;
if ( V_131 == V_136 )
goto V_139;
V_48 = (struct V_43 * )
( V_129 + V_131 ) ;
} while ( V_136 == V_131 + V_48 -> V_85 );
V_137 = V_48 -> V_85 ;
V_48 = (struct V_43 * )
( V_129 + V_131 + V_137 ) ;
V_48 -> V_118 . V_132 = V_131 ;
V_131 += V_137 ;
} else {
int V_140 = V_55 -> V_64 ;
if ( strcmp ( V_55 -> V_56 . V_57 . V_135 . V_59 ,
V_63 ) == 0 &&
V_140 >= 0 ) {
if ( V_140 > V_128 -> V_137 -
sizeof( struct V_43 ) ) {
F_8 ( L_26
L_27 ,
V_140 ) ;
return 0 ;
}
F_8 ( L_28 ,
V_131 , V_140 ) ;
} else {
V_140 = V_131 + V_48 -> V_85 ;
}
V_48 = (struct V_43 * )
( V_129 + V_140 ) ;
V_48 -> V_118 . V_132 = V_131 ;
V_131 = V_140 ;
}
}
V_139:
F_8 ( L_29 , V_68 ) ;
}
return 1 ;
}
static void F_45 ( struct V_111 * V_141 , struct V_77 * V_77 )
{
struct V_142 V_40 ;
V_40 . V_77 = V_77 ;
V_40 . V_116 = V_141 -> V_57 . V_58 . V_116 ;
V_40 . V_117 = V_141 -> V_61 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_116 -> V_143 != NULL )
V_40 . V_116 -> V_143 ( & V_40 ) ;
F_46 ( V_40 . V_116 -> V_144 ) ;
}
static int
F_47 ( const struct V_43 * V_48 , const char * V_59 )
{
const struct V_47 * V_55 ;
if ( ! F_7 ( & V_48 -> V_6 ) ) {
F_8 ( L_30 , V_48 , V_59 ) ;
return - V_145 ;
}
if ( V_48 -> V_62 + sizeof( struct V_47 ) >
V_48 -> V_85 )
return - V_145 ;
V_55 = F_13 ( V_48 ) ;
if ( V_48 -> V_62 + V_55 -> V_57 . V_146 > V_48 -> V_85 )
return - V_145 ;
return 0 ;
}
static int
F_48 ( struct V_111 * V_141 , struct V_147 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_148 ;
int V_12 ;
V_40 -> V_116 = V_141 -> V_57 . V_58 . V_116 ;
V_40 -> V_117 = V_141 -> V_61 ;
V_12 = F_49 ( V_40 , V_141 -> V_57 . V_149 - sizeof( * V_141 ) ,
V_6 -> V_29 , V_6 -> V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 , V_40 -> V_116 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_50 ( struct V_111 * V_141 , struct V_147 * V_40 )
{
struct V_150 * V_116 ;
int V_12 ;
V_116 = F_51 ( V_104 , V_141 -> V_57 . V_135 . V_59 ,
V_141 -> V_57 . V_135 . V_151 ) ;
if ( F_52 ( V_116 ) ) {
F_8 ( L_32 , V_141 -> V_57 . V_135 . V_59 ) ;
return F_53 ( V_116 ) ;
}
V_141 -> V_57 . V_58 . V_116 = V_116 ;
V_12 = F_48 ( V_141 , V_40 ) ;
if ( V_12 )
goto V_152;
return 0 ;
V_152:
F_46 ( V_141 -> V_57 . V_58 . V_116 -> V_144 ) ;
return V_12 ;
}
static int F_54 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 )
{
struct V_47 * V_55 = F_14 ( V_48 ) ;
struct V_153 V_40 = {
. V_77 = V_77 ,
. V_88 = V_59 ,
. V_148 = V_48 ,
. V_56 = V_55 -> V_57 . V_58 . V_56 ,
. V_41 = V_55 -> V_61 ,
. V_154 = V_48 -> V_134 ,
. V_103 = V_104 ,
} ;
int V_12 ;
V_12 = F_55 ( & V_40 , V_55 -> V_57 . V_146 - sizeof( * V_55 ) ,
V_48 -> V_6 . V_29 , V_48 -> V_6 . V_22 & V_31 ) ;
if ( V_12 < 0 ) {
F_8 ( L_31 ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ) ;
return V_12 ;
}
return 0 ;
}
static int
F_56 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 ,
unsigned int V_137 )
{
struct V_47 * V_55 ;
struct V_155 * V_56 ;
int V_12 ;
unsigned int V_156 ;
struct V_147 V_157 ;
struct V_111 * V_112 ;
V_12 = F_47 ( V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_48 -> V_118 . V_132 = F_57 () ;
if ( F_58 ( V_48 -> V_118 . V_132 ) )
return - V_158 ;
V_156 = 0 ;
V_157 . V_77 = V_77 ;
V_157 . V_88 = V_59 ;
V_157 . V_148 = & V_48 -> V_6 ;
V_157 . V_154 = V_48 -> V_134 ;
V_157 . V_103 = V_104 ;
F_34 (ematch, e) {
V_12 = F_50 ( V_112 , & V_157 ) ;
if ( V_12 != 0 )
goto V_159;
++ V_156 ;
}
V_55 = F_14 ( V_48 ) ;
V_56 = F_59 ( V_104 , V_55 -> V_57 . V_135 . V_59 ,
V_55 -> V_57 . V_135 . V_151 ) ;
if ( F_52 ( V_56 ) ) {
F_8 ( L_33 , V_55 -> V_57 . V_135 . V_59 ) ;
V_12 = F_53 ( V_56 ) ;
goto V_159;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_12 = F_54 ( V_48 , V_77 , V_59 ) ;
if ( V_12 )
goto V_152;
return 0 ;
V_152:
F_46 ( V_55 -> V_57 . V_58 . V_56 -> V_144 ) ;
V_159:
F_34 (ematch, e) {
if ( V_156 -- == 0 )
break;
F_45 ( V_112 , V_77 ) ;
}
F_60 ( V_48 -> V_118 . V_132 ) ;
return V_12 ;
}
static bool F_61 ( const struct V_43 * V_48 )
{
const struct V_47 * V_55 ;
unsigned int V_64 ;
if ( ! F_12 ( & V_48 -> V_6 ) )
return false ;
V_55 = F_13 ( V_48 ) ;
if ( strcmp ( V_55 -> V_57 . V_135 . V_59 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_54 * ) V_55 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_127 ;
}
static int
F_62 ( struct V_43 * V_48 ,
struct V_73 * V_128 ,
const unsigned char * V_44 ,
const unsigned char * V_160 ,
const unsigned int * V_161 ,
const unsigned int * V_162 ,
unsigned int V_106 )
{
unsigned int V_163 ;
if ( ( unsigned long ) V_48 % F_63 ( struct V_43 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_43 ) >= V_160 ) {
F_8 ( L_34 , V_48 ) ;
return - V_145 ;
}
if ( V_48 -> V_85
< sizeof( struct V_43 ) + sizeof( struct V_47 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_85 ) ;
return - V_145 ;
}
for ( V_163 = 0 ; V_163 < V_130 ; V_163 ++ ) {
if ( ! ( V_106 & ( 1 << V_163 ) ) )
continue;
if ( ( unsigned char * ) V_48 - V_44 == V_161 [ V_163 ] )
V_128 -> V_79 [ V_163 ] = V_161 [ V_163 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_162 [ V_163 ] ) {
if ( ! F_61 ( V_48 ) ) {
F_43 ( L_36
L_37
L_38 ) ;
return - V_145 ;
}
V_128 -> V_110 [ V_163 ] = V_162 [ V_163 ] ;
}
}
V_48 -> V_118 = ( (struct V_113 ) { 0 , 0 } ) ;
V_48 -> V_134 = 0 ;
return 0 ;
}
static void
F_64 ( struct V_43 * V_48 , struct V_77 * V_77 )
{
struct V_164 V_40 ;
struct V_47 * V_55 ;
struct V_111 * V_112 ;
F_34 (ematch, e)
F_45 ( V_112 , V_77 ) ;
V_55 = F_14 ( V_48 ) ;
V_40 . V_77 = V_77 ;
V_40 . V_56 = V_55 -> V_57 . V_58 . V_56 ;
V_40 . V_41 = V_55 -> V_61 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_56 -> V_143 != NULL )
V_40 . V_56 -> V_143 ( & V_40 ) ;
F_46 ( V_40 . V_56 -> V_144 ) ;
F_60 ( V_48 -> V_118 . V_132 ) ;
}
static int
F_65 ( struct V_77 * V_77 , struct V_73 * V_128 , void * V_129 ,
const struct V_165 * V_166 )
{
struct V_43 * V_76 ;
unsigned int V_167 ;
int V_12 = 0 ;
V_128 -> V_137 = V_166 -> V_137 ;
V_128 -> V_168 = V_166 -> V_169 ;
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
V_128 -> V_79 [ V_167 ] = 0xFFFFFFFF ;
V_128 -> V_110 [ V_167 ] = 0xFFFFFFFF ;
}
F_8 ( L_39 , V_128 -> V_137 ) ;
V_167 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_62 ( V_76 , V_128 , V_129 ,
V_129 + V_166 -> V_137 ,
V_166 -> V_79 ,
V_166 -> V_110 ,
V_166 -> V_106 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_167 ;
if ( strcmp ( F_14 ( V_76 ) -> V_57 . V_135 . V_59 ,
V_60 ) == 0 )
++ V_128 -> V_108 ;
}
if ( V_167 != V_166 -> V_169 ) {
F_8 ( L_40 ,
V_167 , V_166 -> V_169 ) ;
return - V_145 ;
}
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
if ( ! ( V_166 -> V_106 & ( 1 << V_167 ) ) )
continue;
if ( V_128 -> V_79 [ V_167 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_167 , V_166 -> V_79 [ V_167 ] ) ;
return - V_145 ;
}
if ( V_128 -> V_110 [ V_167 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_167 , V_166 -> V_110 [ V_167 ] ) ;
return - V_145 ;
}
}
if ( ! F_42 ( V_128 , V_166 -> V_106 , V_129 ) )
return - V_170 ;
V_167 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_12 = F_56 ( V_76 , V_77 , V_166 -> V_59 , V_166 -> V_137 ) ;
if ( V_12 != 0 )
break;
++ V_167 ;
}
if ( V_12 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_167 -- == 0 )
break;
F_64 ( V_76 , V_77 ) ;
}
return V_12 ;
}
return V_12 ;
}
static void
F_66 ( const struct V_73 * V_55 ,
struct V_113 V_118 [] )
{
struct V_43 * V_76 ;
unsigned int V_95 ;
unsigned int V_167 ;
F_67 (cpu) {
T_2 * V_49 = & F_68 ( V_171 , V_95 ) ;
V_167 = 0 ;
F_18 (iter, t->entries, t->size) {
struct V_113 * V_172 ;
T_3 V_173 , V_132 ;
unsigned int V_174 ;
V_172 = F_69 ( & V_76 -> V_118 , V_95 ) ;
do {
V_174 = F_70 ( V_49 ) ;
V_173 = V_172 -> V_173 ;
V_132 = V_172 -> V_132 ;
} while ( F_71 ( V_49 , V_174 ) );
F_36 ( V_118 [ V_167 ] , V_173 , V_132 ) ;
++ V_167 ;
}
}
}
static struct V_113 * F_72 ( const struct V_1 * V_88 )
{
unsigned int V_175 ;
struct V_113 * V_118 ;
const struct V_73 * V_74 = V_88 -> V_74 ;
V_175 = sizeof( struct V_113 ) * V_74 -> V_168 ;
V_118 = F_73 ( V_175 ) ;
if ( V_118 == NULL )
return F_74 ( - V_158 ) ;
F_66 ( V_74 , V_118 ) ;
return V_118 ;
}
static int
F_75 ( unsigned int V_176 ,
const struct V_1 * V_88 ,
void T_4 * V_177 )
{
unsigned int V_178 , V_179 ;
const struct V_43 * V_48 ;
struct V_113 * V_118 ;
const struct V_73 * V_74 = V_88 -> V_74 ;
int V_12 = 0 ;
const void * V_180 ;
V_118 = F_72 ( V_88 ) ;
if ( F_52 ( V_118 ) )
return F_53 ( V_118 ) ;
V_180 = V_74 -> V_78 ;
if ( F_76 ( V_177 , V_180 , V_176 ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
for ( V_178 = 0 , V_179 = 0 ; V_178 < V_176 ; V_178 += V_48 -> V_85 , V_179 ++ ) {
unsigned int V_167 ;
const struct V_111 * V_141 ;
const struct V_47 * V_55 ;
V_48 = (struct V_43 * ) ( V_180 + V_178 ) ;
if ( F_76 ( V_177 + V_178
+ F_77 ( struct V_43 , V_118 ) ,
& V_118 [ V_179 ] ,
sizeof( V_118 [ V_179 ] ) ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
for ( V_167 = sizeof( struct V_43 ) ;
V_167 < V_48 -> V_62 ;
V_167 += V_141 -> V_57 . V_149 ) {
V_141 = ( void * ) V_48 + V_167 ;
if ( F_76 ( V_177 + V_178 + V_167
+ F_77 ( struct V_111 ,
V_57 . V_135 . V_59 ) ,
V_141 -> V_57 . V_58 . V_116 -> V_59 ,
strlen ( V_141 -> V_57 . V_58 . V_116 -> V_59 ) + 1 )
!= 0 ) {
V_12 = - V_181 ;
goto V_182;
}
}
V_55 = F_13 ( V_48 ) ;
if ( F_76 ( V_177 + V_178 + V_48 -> V_62
+ F_77 ( struct V_47 ,
V_57 . V_135 . V_59 ) ,
V_55 -> V_57 . V_58 . V_56 -> V_59 ,
strlen ( V_55 -> V_57 . V_58 . V_56 -> V_59 ) + 1 ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
}
V_182:
F_78 ( V_118 ) ;
return V_12 ;
}
static void F_79 ( void * V_20 , const void * V_16 )
{
int V_122 = * ( V_183 * ) V_16 ;
if ( V_122 > 0 )
V_122 += F_80 ( V_82 , V_122 ) ;
memcpy ( V_20 , & V_122 , sizeof( V_122 ) ) ;
}
static int F_81 ( void T_4 * V_20 , const void * V_16 )
{
V_183 V_184 = * ( int * ) V_16 ;
if ( V_184 > 0 )
V_184 -= F_80 ( V_82 , V_184 ) ;
return F_76 ( V_20 , & V_184 , sizeof( V_184 ) ) ? - V_181 : 0 ;
}
static int F_82 ( const struct V_43 * V_48 ,
const struct V_73 * V_2 ,
const void * V_44 , struct V_73 * V_128 )
{
const struct V_111 * V_112 ;
const struct V_47 * V_55 ;
unsigned int V_185 ;
int V_178 , V_167 , V_12 ;
V_178 = sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_48 - V_44 ;
F_34 (ematch, e)
V_178 += F_83 ( V_112 -> V_57 . V_58 . V_116 ) ;
V_55 = F_13 ( V_48 ) ;
V_178 += F_84 ( V_55 -> V_57 . V_58 . V_56 ) ;
V_128 -> V_137 -= V_178 ;
V_12 = F_85 ( V_82 , V_185 , V_178 ) ;
if ( V_12 )
return V_12 ;
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
if ( V_2 -> V_79 [ V_167 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_167 ] ) ) )
V_128 -> V_79 [ V_167 ] -= V_178 ;
if ( V_2 -> V_110 [ V_167 ] &&
( V_48 < (struct V_43 * ) ( V_44 + V_2 -> V_110 [ V_167 ] ) ) )
V_128 -> V_110 [ V_167 ] -= V_178 ;
}
return 0 ;
}
static int F_86 ( const struct V_73 * V_2 ,
struct V_73 * V_128 )
{
struct V_43 * V_76 ;
const void * V_180 ;
int V_12 ;
if ( ! V_128 || ! V_2 )
return - V_145 ;
memcpy ( V_128 , V_2 , F_77 ( struct V_73 , V_78 ) ) ;
V_128 -> V_187 = 0 ;
V_180 = V_2 -> V_78 ;
F_87 ( V_82 , V_2 -> V_168 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_12 = F_82 ( V_76 , V_2 , V_180 , V_128 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_88 ( struct V_77 * V_77 , void T_4 * V_135 ,
const int * V_119 , int V_188 )
{
char V_59 [ V_189 ] ;
struct V_1 * V_55 ;
int V_12 ;
if ( * V_119 != sizeof( struct V_190 ) ) {
F_8 ( L_43 , * V_119 ,
sizeof( struct V_190 ) ) ;
return - V_145 ;
}
if ( F_89 ( V_59 , V_135 , sizeof( V_59 ) ) != 0 )
return - V_181 ;
V_59 [ V_189 - 1 ] = '\0' ;
#ifdef F_90
if ( V_188 )
F_91 ( V_82 ) ;
#endif
V_55 = F_92 ( F_93 ( V_77 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( ! F_94 ( V_55 ) ) {
struct V_190 V_2 ;
const struct V_73 * V_74 = V_55 -> V_74 ;
#ifdef F_90
struct V_73 V_172 ;
if ( V_188 ) {
V_12 = F_86 ( V_74 , & V_172 ) ;
F_95 ( V_82 ) ;
V_74 = & V_172 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_106 = V_55 -> V_106 ;
memcpy ( V_2 . V_79 , V_74 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_110 , V_74 -> V_110 ,
sizeof( V_2 . V_110 ) ) ;
V_2 . V_169 = V_74 -> V_168 ;
V_2 . V_137 = V_74 -> V_137 ;
strcpy ( V_2 . V_59 , V_59 ) ;
if ( F_76 ( V_135 , & V_2 , * V_119 ) != 0 )
V_12 = - V_181 ;
else
V_12 = 0 ;
F_96 ( V_55 ) ;
F_46 ( V_55 -> V_144 ) ;
} else
V_12 = V_55 ? F_53 ( V_55 ) : - V_191 ;
#ifdef F_90
if ( V_188 )
F_97 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_98 ( struct V_77 * V_77 , struct V_192 T_4 * V_193 ,
const int * V_119 )
{
int V_12 ;
struct V_192 V_194 ;
struct V_1 * V_55 ;
if ( * V_119 < sizeof( V_194 ) ) {
F_8 ( L_45 , * V_119 , sizeof( V_194 ) ) ;
return - V_145 ;
}
if ( F_89 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_119 != sizeof( struct V_192 ) + V_194 . V_137 ) {
F_8 ( L_46 ,
* V_119 , sizeof( V_194 ) + V_194 . V_137 ) ;
return - V_145 ;
}
V_55 = F_93 ( V_77 , V_82 , V_194 . V_59 ) ;
if ( ! F_94 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
F_8 ( L_47 , V_74 -> V_168 ) ;
if ( V_194 . V_137 == V_74 -> V_137 )
V_12 = F_75 ( V_74 -> V_137 ,
V_55 , V_193 -> V_195 ) ;
else {
F_8 ( L_48 ,
V_74 -> V_137 , V_194 . V_137 ) ;
V_12 = - V_196 ;
}
F_46 ( V_55 -> V_144 ) ;
F_96 ( V_55 ) ;
} else
V_12 = V_55 ? F_53 ( V_55 ) : - V_191 ;
return V_12 ;
}
static int
F_99 ( struct V_77 * V_77 , const char * V_59 , unsigned int V_106 ,
struct V_73 * V_128 , unsigned int V_197 ,
void T_4 * V_198 )
{
int V_12 ;
struct V_1 * V_55 ;
struct V_73 * V_199 ;
struct V_113 * V_118 ;
struct V_43 * V_76 ;
V_12 = 0 ;
V_118 = F_73 ( V_197 * sizeof( struct V_113 ) ) ;
if ( ! V_118 ) {
V_12 = - V_158 ;
goto V_71;
}
V_55 = F_92 ( F_93 ( V_77 , V_82 , V_59 ) ,
L_44 , V_59 ) ;
if ( F_94 ( V_55 ) ) {
V_12 = V_55 ? F_53 ( V_55 ) : - V_191 ;
goto V_200;
}
if ( V_106 != V_55 -> V_106 ) {
F_8 ( L_49 ,
V_106 , V_55 -> V_106 ) ;
V_12 = - V_145 ;
goto V_201;
}
V_199 = F_100 ( V_55 , V_197 , V_128 , & V_12 ) ;
if ( ! V_199 )
goto V_201;
F_8 ( L_50 ,
V_199 -> V_168 , V_199 -> V_187 , V_128 -> V_168 ) ;
if ( ( V_199 -> V_168 > V_199 -> V_187 ) ||
( V_128 -> V_168 <= V_199 -> V_187 ) )
F_46 ( V_55 -> V_144 ) ;
if ( ( V_199 -> V_168 > V_199 -> V_187 ) &&
( V_128 -> V_168 <= V_199 -> V_187 ) )
F_46 ( V_55 -> V_144 ) ;
F_66 ( V_199 , V_118 ) ;
F_18 (iter, oldinfo->entries, oldinfo->size)
F_64 ( V_76 , V_77 ) ;
F_101 ( V_199 ) ;
if ( F_76 ( V_198 , V_118 ,
sizeof( struct V_113 ) * V_197 ) != 0 ) {
F_102 ( L_51 ) ;
}
F_78 ( V_118 ) ;
F_96 ( V_55 ) ;
return V_12 ;
V_201:
F_46 ( V_55 -> V_144 ) ;
F_96 ( V_55 ) ;
V_200:
F_78 ( V_118 ) ;
V_71:
return V_12 ;
}
static int
F_103 ( struct V_77 * V_77 , const void T_4 * V_135 , unsigned int V_119 )
{
int V_12 ;
struct V_165 V_172 ;
struct V_73 * V_128 ;
void * V_180 ;
struct V_43 * V_76 ;
if ( F_89 ( & V_172 , V_135 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_113 ) )
return - V_158 ;
if ( V_172 . V_197 == 0 )
return - V_145 ;
V_172 . V_59 [ sizeof( V_172 . V_59 ) - 1 ] = 0 ;
V_128 = F_104 ( V_172 . V_137 ) ;
if ( ! V_128 )
return - V_158 ;
V_180 = V_128 -> V_78 ;
if ( F_89 ( V_180 , V_135 + sizeof( V_172 ) ,
V_172 . V_137 ) != 0 ) {
V_12 = - V_181 ;
goto V_203;
}
V_12 = F_65 ( V_77 , V_128 , V_180 , & V_172 ) ;
if ( V_12 != 0 )
goto V_203;
F_8 ( L_52 ) ;
V_12 = F_99 ( V_77 , V_172 . V_59 , V_172 . V_106 , V_128 ,
V_172 . V_197 , V_172 . V_118 ) ;
if ( V_12 )
goto V_204;
return 0 ;
V_204:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_64 ( V_76 , V_77 ) ;
V_203:
F_101 ( V_128 ) ;
return V_12 ;
}
static int
F_105 ( struct V_77 * V_77 , const void T_4 * V_135 ,
unsigned int V_119 , int V_188 )
{
unsigned int V_167 ;
struct V_205 V_172 ;
struct V_113 * V_206 ;
unsigned int V_197 ;
const char * V_59 ;
int V_137 ;
void * V_207 ;
struct V_1 * V_55 ;
const struct V_73 * V_74 ;
int V_12 = 0 ;
struct V_43 * V_76 ;
unsigned int V_97 ;
#ifdef F_90
struct V_208 V_209 ;
if ( V_188 ) {
V_207 = & V_209 ;
V_137 = sizeof( struct V_208 ) ;
} else
#endif
{
V_207 = & V_172 ;
V_137 = sizeof( struct V_205 ) ;
}
if ( F_89 ( V_207 , V_135 , V_137 ) != 0 )
return - V_181 ;
#ifdef F_90
if ( V_188 ) {
V_197 = V_209 . V_197 ;
V_59 = V_209 . V_59 ;
} else
#endif
{
V_197 = V_172 . V_197 ;
V_59 = V_172 . V_59 ;
}
if ( V_119 != V_137 + V_197 * sizeof( struct V_113 ) )
return - V_145 ;
V_206 = F_106 ( V_119 - V_137 ) ;
if ( ! V_206 )
return - V_158 ;
if ( F_89 ( V_206 , V_135 + V_137 , V_119 - V_137 ) != 0 ) {
V_12 = - V_181 ;
goto free;
}
V_55 = F_93 ( V_77 , V_82 , V_59 ) ;
if ( F_94 ( V_55 ) ) {
V_12 = V_55 ? F_53 ( V_55 ) : - V_191 ;
goto free;
}
F_27 () ;
V_74 = V_55 -> V_74 ;
if ( V_74 -> V_168 != V_197 ) {
V_12 = - V_145 ;
goto V_210;
}
V_167 = 0 ;
V_97 = F_28 () ;
F_18 (iter, private->entries, private->size) {
struct V_113 * V_172 ;
V_172 = F_35 ( & V_76 -> V_118 ) ;
F_36 ( * V_172 , V_206 [ V_167 ] . V_173 , V_206 [ V_167 ] . V_132 ) ;
++ V_167 ;
}
F_39 ( V_97 ) ;
V_210:
F_40 () ;
F_96 ( V_55 ) ;
F_46 ( V_55 -> V_144 ) ;
free:
F_78 ( V_206 ) ;
return V_12 ;
}
static int
F_107 ( struct V_43 * V_48 , void T_4 * * V_211 ,
unsigned int * V_137 , struct V_113 * V_118 ,
unsigned int V_167 )
{
struct V_47 * V_55 ;
struct V_186 T_4 * V_212 ;
T_5 V_62 , V_85 ;
T_6 V_213 ;
const struct V_111 * V_112 ;
int V_12 = 0 ;
V_213 = * V_137 ;
V_212 = (struct V_186 T_4 * ) * V_211 ;
if ( F_76 ( V_212 , V_48 , sizeof( struct V_43 ) ) != 0 ||
F_76 ( & V_212 -> V_118 , & V_118 [ V_167 ] ,
sizeof( V_118 [ V_167 ] ) ) != 0 )
return - V_181 ;
* V_211 += sizeof( struct V_186 ) ;
* V_137 -= sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
F_34 (ematch, e) {
V_12 = F_108 ( V_112 , V_211 , V_137 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_62 = V_48 -> V_62 - ( V_213 - * V_137 ) ;
V_55 = F_14 ( V_48 ) ;
V_12 = F_109 ( V_55 , V_211 , V_137 ) ;
if ( V_12 )
return V_12 ;
V_85 = V_48 -> V_85 - ( V_213 - * V_137 ) ;
if ( F_110 ( V_62 , & V_212 -> V_62 ) != 0 ||
F_110 ( V_85 , & V_212 -> V_85 ) != 0 )
return - V_181 ;
return 0 ;
}
static int
F_111 ( struct V_111 * V_141 ,
const char * V_59 ,
const struct V_9 * V_6 ,
int * V_137 )
{
struct V_150 * V_116 ;
V_116 = F_51 ( V_104 , V_141 -> V_57 . V_135 . V_59 ,
V_141 -> V_57 . V_135 . V_151 ) ;
if ( F_52 ( V_116 ) ) {
F_8 ( L_53 ,
V_141 -> V_57 . V_135 . V_59 ) ;
return F_53 ( V_116 ) ;
}
V_141 -> V_57 . V_58 . V_116 = V_116 ;
* V_137 += F_83 ( V_116 ) ;
return 0 ;
}
static void F_112 ( struct V_186 * V_48 )
{
struct V_47 * V_55 ;
struct V_111 * V_112 ;
F_34 (ematch, e)
F_46 ( V_112 -> V_57 . V_58 . V_116 -> V_144 ) ;
V_55 = F_113 ( V_48 ) ;
F_46 ( V_55 -> V_57 . V_58 . V_56 -> V_144 ) ;
}
static int
F_114 ( struct V_186 * V_48 ,
struct V_73 * V_128 ,
unsigned int * V_137 ,
const unsigned char * V_44 ,
const unsigned char * V_160 ,
const unsigned int * V_161 ,
const unsigned int * V_162 ,
const char * V_59 )
{
struct V_111 * V_112 ;
struct V_47 * V_55 ;
struct V_155 * V_56 ;
unsigned int V_185 ;
unsigned int V_156 ;
int V_12 , V_178 , V_163 ;
F_8 ( L_54 , V_48 ) ;
if ( ( unsigned long ) V_48 % F_63 ( struct V_186 ) != 0 ||
( unsigned char * ) V_48 + sizeof( struct V_186 ) >= V_160 ) {
F_8 ( L_55 , V_48 , V_160 ) ;
return - V_145 ;
}
if ( V_48 -> V_85 < sizeof( struct V_186 ) +
sizeof( struct V_214 ) ) {
F_8 ( L_35 ,
V_48 , V_48 -> V_85 ) ;
return - V_145 ;
}
V_12 = F_47 ( (struct V_43 * ) V_48 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_178 = sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_48 - ( void * ) V_44 ;
V_156 = 0 ;
F_34 (ematch, e) {
V_12 = F_111 ( V_112 , V_59 , & V_48 -> V_6 , & V_178 ) ;
if ( V_12 != 0 )
goto V_215;
++ V_156 ;
}
V_55 = F_113 ( V_48 ) ;
V_56 = F_59 ( V_104 , V_55 -> V_57 . V_135 . V_59 ,
V_55 -> V_57 . V_135 . V_151 ) ;
if ( F_52 ( V_56 ) ) {
F_8 ( L_56 ,
V_55 -> V_57 . V_135 . V_59 ) ;
V_12 = F_53 ( V_56 ) ;
goto V_215;
}
V_55 -> V_57 . V_58 . V_56 = V_56 ;
V_178 += F_84 ( V_56 ) ;
* V_137 += V_178 ;
V_12 = F_85 ( V_82 , V_185 , V_178 ) ;
if ( V_12 )
goto V_71;
for ( V_163 = 0 ; V_163 < V_130 ; V_163 ++ ) {
if ( ( unsigned char * ) V_48 - V_44 == V_161 [ V_163 ] )
V_128 -> V_79 [ V_163 ] = V_161 [ V_163 ] ;
if ( ( unsigned char * ) V_48 - V_44 == V_162 [ V_163 ] )
V_128 -> V_110 [ V_163 ] = V_162 [ V_163 ] ;
}
memset ( & V_48 -> V_118 , 0 , sizeof( V_48 -> V_118 ) ) ;
V_48 -> V_134 = 0 ;
return 0 ;
V_71:
F_46 ( V_55 -> V_57 . V_58 . V_56 -> V_144 ) ;
V_215:
F_34 (ematch, e) {
if ( V_156 -- == 0 )
break;
F_46 ( V_112 -> V_57 . V_58 . V_116 -> V_144 ) ;
}
return V_12 ;
}
static int
F_115 ( struct V_186 * V_48 , void * * V_211 ,
unsigned int * V_137 , const char * V_59 ,
struct V_73 * V_128 , unsigned char * V_44 )
{
struct V_47 * V_55 ;
struct V_155 * V_56 ;
struct V_43 * V_216 ;
unsigned int V_213 ;
int V_12 , V_163 ;
struct V_111 * V_112 ;
V_12 = 0 ;
V_213 = * V_137 ;
V_216 = (struct V_43 * ) * V_211 ;
memcpy ( V_216 , V_48 , sizeof( struct V_43 ) ) ;
memcpy ( & V_216 -> V_118 , & V_48 -> V_118 , sizeof( V_48 -> V_118 ) ) ;
* V_211 += sizeof( struct V_43 ) ;
* V_137 += sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
F_34 (ematch, e) {
V_12 = F_116 ( V_112 , V_211 , V_137 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_216 -> V_62 = V_48 -> V_62 - ( V_213 - * V_137 ) ;
V_55 = F_113 ( V_48 ) ;
V_56 = V_55 -> V_57 . V_58 . V_56 ;
F_117 ( V_55 , V_211 , V_137 ) ;
V_216 -> V_85 = V_48 -> V_85 - ( V_213 - * V_137 ) ;
for ( V_163 = 0 ; V_163 < V_130 ; V_163 ++ ) {
if ( ( unsigned char * ) V_216 - V_44 < V_128 -> V_79 [ V_163 ] )
V_128 -> V_79 [ V_163 ] -= V_213 - * V_137 ;
if ( ( unsigned char * ) V_216 - V_44 < V_128 -> V_110 [ V_163 ] )
V_128 -> V_110 [ V_163 ] -= V_213 - * V_137 ;
}
return V_12 ;
}
static int
F_118 ( struct V_43 * V_48 , struct V_77 * V_77 , const char * V_59 )
{
struct V_111 * V_112 ;
struct V_147 V_157 ;
unsigned int V_156 ;
int V_12 = 0 ;
V_48 -> V_118 . V_132 = F_57 () ;
if ( F_58 ( V_48 -> V_118 . V_132 ) )
return - V_158 ;
V_156 = 0 ;
V_157 . V_77 = V_77 ;
V_157 . V_88 = V_59 ;
V_157 . V_148 = & V_48 -> V_6 ;
V_157 . V_154 = V_48 -> V_134 ;
V_157 . V_103 = V_104 ;
F_34 (ematch, e) {
V_12 = F_48 ( V_112 , & V_157 ) ;
if ( V_12 != 0 )
goto V_159;
++ V_156 ;
}
V_12 = F_54 ( V_48 , V_77 , V_59 ) ;
if ( V_12 )
goto V_159;
return 0 ;
V_159:
F_34 (ematch, e) {
if ( V_156 -- == 0 )
break;
F_45 ( V_112 , V_77 ) ;
}
F_60 ( V_48 -> V_118 . V_132 ) ;
return V_12 ;
}
static int
F_119 ( struct V_77 * V_77 ,
const char * V_59 ,
unsigned int V_106 ,
struct V_73 * * V_217 ,
void * * V_218 ,
unsigned int V_176 ,
unsigned int V_168 ,
unsigned int * V_161 ,
unsigned int * V_162 )
{
unsigned int V_167 , V_156 ;
struct V_73 * V_128 , * V_2 ;
void * V_131 , * V_129 , * V_219 ;
struct V_186 * V_220 ;
struct V_43 * V_221 ;
unsigned int V_137 ;
int V_12 ;
V_2 = * V_217 ;
V_129 = * V_218 ;
V_137 = V_176 ;
V_2 -> V_168 = V_168 ;
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
V_2 -> V_79 [ V_167 ] = 0xFFFFFFFF ;
V_2 -> V_110 [ V_167 ] = 0xFFFFFFFF ;
}
F_8 ( L_57 , V_2 -> V_137 ) ;
V_156 = 0 ;
F_91 ( V_82 ) ;
F_87 ( V_82 , V_168 ) ;
F_18 (iter0, entry0, total_size) {
V_12 = F_114 ( V_220 , V_2 , & V_137 ,
V_129 ,
V_129 + V_176 ,
V_161 ,
V_162 ,
V_59 ) ;
if ( V_12 != 0 )
goto V_222;
++ V_156 ;
}
V_12 = - V_145 ;
if ( V_156 != V_168 ) {
F_8 ( L_58 ,
V_156 , V_168 ) ;
goto V_222;
}
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
if ( ! ( V_106 & ( 1 << V_167 ) ) )
continue;
if ( V_2 -> V_79 [ V_167 ] == 0xFFFFFFFF ) {
F_8 ( L_41 ,
V_167 , V_161 [ V_167 ] ) ;
goto V_222;
}
if ( V_2 -> V_110 [ V_167 ] == 0xFFFFFFFF ) {
F_8 ( L_42 ,
V_167 , V_162 [ V_167 ] ) ;
goto V_222;
}
}
V_12 = - V_158 ;
V_128 = F_104 ( V_137 ) ;
if ( ! V_128 )
goto V_222;
V_128 -> V_168 = V_168 ;
for ( V_167 = 0 ; V_167 < V_130 ; V_167 ++ ) {
V_128 -> V_79 [ V_167 ] = V_2 -> V_79 [ V_167 ] ;
V_128 -> V_110 [ V_167 ] = V_2 -> V_110 [ V_167 ] ;
}
V_219 = V_128 -> V_78 ;
V_131 = V_219 ;
V_137 = V_176 ;
F_18 (iter0, entry0, total_size) {
V_12 = F_115 ( V_220 , & V_131 , & V_137 ,
V_59 , V_128 , V_219 ) ;
if ( V_12 != 0 )
break;
}
F_95 ( V_82 ) ;
F_97 ( V_82 ) ;
if ( V_12 )
goto V_203;
V_12 = - V_170 ;
if ( ! F_42 ( V_128 , V_106 , V_219 ) )
goto V_203;
V_167 = 0 ;
F_18 (iter1, entry1, newinfo->size) {
V_12 = F_118 ( V_221 , V_77 , V_59 ) ;
if ( V_12 != 0 )
break;
++ V_167 ;
if ( strcmp ( F_14 ( V_221 ) -> V_57 . V_135 . V_59 ,
V_60 ) == 0 )
++ V_128 -> V_108 ;
}
if ( V_12 ) {
int V_223 = V_167 ;
V_156 -= V_167 ;
F_18 (iter0, entry0, newinfo->size) {
if ( V_223 -- > 0 )
continue;
if ( V_156 -- == 0 )
break;
F_112 ( V_220 ) ;
}
F_18 (iter1, entry1, newinfo->size) {
if ( V_167 -- == 0 )
break;
F_64 ( V_221 , V_77 ) ;
}
F_101 ( V_128 ) ;
return V_12 ;
}
* V_217 = V_128 ;
* V_218 = V_219 ;
F_101 ( V_2 ) ;
return 0 ;
V_203:
F_101 ( V_128 ) ;
V_71:
F_18 (iter0, entry0, total_size) {
if ( V_156 -- == 0 )
break;
F_112 ( V_220 ) ;
}
return V_12 ;
V_222:
F_95 ( V_82 ) ;
F_97 ( V_82 ) ;
goto V_71;
}
static int
F_120 ( struct V_77 * V_77 , void T_4 * V_135 , unsigned int V_119 )
{
int V_12 ;
struct V_224 V_172 ;
struct V_73 * V_128 ;
void * V_180 ;
struct V_43 * V_76 ;
if ( F_89 ( & V_172 , V_135 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_137 >= V_202 / F_121 () )
return - V_158 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_113 ) )
return - V_158 ;
if ( V_172 . V_197 == 0 )
return - V_145 ;
V_172 . V_59 [ sizeof( V_172 . V_59 ) - 1 ] = 0 ;
V_128 = F_104 ( V_172 . V_137 ) ;
if ( ! V_128 )
return - V_158 ;
V_180 = V_128 -> V_78 ;
if ( F_89 ( V_180 , V_135 + sizeof( V_172 ) ,
V_172 . V_137 ) != 0 ) {
V_12 = - V_181 ;
goto V_203;
}
V_12 = F_119 ( V_77 , V_172 . V_59 , V_172 . V_106 ,
& V_128 , & V_180 , V_172 . V_137 ,
V_172 . V_169 , V_172 . V_79 ,
V_172 . V_110 ) ;
if ( V_12 != 0 )
goto V_203;
F_8 ( L_59 ) ;
V_12 = F_99 ( V_77 , V_172 . V_59 , V_172 . V_106 , V_128 ,
V_172 . V_197 , F_122 ( V_172 . V_118 ) ) ;
if ( V_12 )
goto V_204;
return 0 ;
V_204:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_64 ( V_76 , V_77 ) ;
V_203:
F_101 ( V_128 ) ;
return V_12 ;
}
static int
F_123 ( struct V_225 * V_226 , int V_227 , void T_4 * V_135 ,
unsigned int V_119 )
{
int V_12 ;
if ( ! F_124 ( F_125 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_231 :
V_12 = F_120 ( F_125 ( V_226 ) , V_135 , V_119 ) ;
break;
case V_232 :
V_12 = F_105 ( F_125 ( V_226 ) , V_135 , V_119 , 1 ) ;
break;
default:
F_8 ( L_60 , V_227 ) ;
V_12 = - V_145 ;
}
return V_12 ;
}
static int
F_126 ( unsigned int V_176 , struct V_1 * V_88 ,
void T_4 * V_177 )
{
struct V_113 * V_118 ;
const struct V_73 * V_74 = V_88 -> V_74 ;
void T_4 * V_131 ;
unsigned int V_137 ;
int V_12 = 0 ;
unsigned int V_167 = 0 ;
struct V_43 * V_76 ;
V_118 = F_72 ( V_88 ) ;
if ( F_52 ( V_118 ) )
return F_53 ( V_118 ) ;
V_131 = V_177 ;
V_137 = V_176 ;
F_18 (iter, private->entries, total_size) {
V_12 = F_107 ( V_76 , & V_131 ,
& V_137 , V_118 , V_167 ++ ) ;
if ( V_12 != 0 )
break;
}
F_78 ( V_118 ) ;
return V_12 ;
}
static int
F_127 ( struct V_77 * V_77 , struct V_233 T_4 * V_193 ,
int * V_119 )
{
int V_12 ;
struct V_233 V_194 ;
struct V_1 * V_55 ;
if ( * V_119 < sizeof( V_194 ) ) {
F_8 ( L_61 , * V_119 , sizeof( V_194 ) ) ;
return - V_145 ;
}
if ( F_89 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_119 != sizeof( struct V_233 ) + V_194 . V_137 ) {
F_8 ( L_62 ,
* V_119 , sizeof( V_194 ) + V_194 . V_137 ) ;
return - V_145 ;
}
F_91 ( V_82 ) ;
V_55 = F_93 ( V_77 , V_82 , V_194 . V_59 ) ;
if ( ! F_94 ( V_55 ) ) {
const struct V_73 * V_74 = V_55 -> V_74 ;
struct V_73 V_2 ;
F_8 ( L_47 , V_74 -> V_168 ) ;
V_12 = F_86 ( V_74 , & V_2 ) ;
if ( ! V_12 && V_194 . V_137 == V_2 . V_137 ) {
V_12 = F_126 ( V_74 -> V_137 ,
V_55 , V_193 -> V_195 ) ;
} else if ( ! V_12 ) {
F_8 ( L_63 ,
V_74 -> V_137 , V_194 . V_137 ) ;
V_12 = - V_196 ;
}
F_95 ( V_82 ) ;
F_46 ( V_55 -> V_144 ) ;
F_96 ( V_55 ) ;
} else
V_12 = V_55 ? F_53 ( V_55 ) : - V_191 ;
F_97 ( V_82 ) ;
return V_12 ;
}
static int
F_128 ( struct V_225 * V_226 , int V_227 , void T_4 * V_135 , int * V_119 )
{
int V_12 ;
if ( ! F_124 ( F_125 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_234 :
V_12 = F_88 ( F_125 ( V_226 ) , V_135 , V_119 , 1 ) ;
break;
case V_235 :
V_12 = F_127 ( F_125 ( V_226 ) , V_135 , V_119 ) ;
break;
default:
V_12 = F_129 ( V_226 , V_227 , V_135 , V_119 ) ;
}
return V_12 ;
}
static int
F_130 ( struct V_225 * V_226 , int V_227 , void T_4 * V_135 , unsigned int V_119 )
{
int V_12 ;
if ( ! F_124 ( F_125 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_231 :
V_12 = F_103 ( F_125 ( V_226 ) , V_135 , V_119 ) ;
break;
case V_232 :
V_12 = F_105 ( F_125 ( V_226 ) , V_135 , V_119 , 0 ) ;
break;
default:
F_8 ( L_60 , V_227 ) ;
V_12 = - V_145 ;
}
return V_12 ;
}
static int
F_129 ( struct V_225 * V_226 , int V_227 , void T_4 * V_135 , int * V_119 )
{
int V_12 ;
if ( ! F_124 ( F_125 ( V_226 ) -> V_228 , V_229 ) )
return - V_230 ;
switch ( V_227 ) {
case V_234 :
V_12 = F_88 ( F_125 ( V_226 ) , V_135 , V_119 , 0 ) ;
break;
case V_235 :
V_12 = F_98 ( F_125 ( V_226 ) , V_135 , V_119 ) ;
break;
case V_236 :
case V_237 : {
struct V_238 V_239 ;
int V_56 ;
if ( * V_119 != sizeof( V_239 ) ) {
V_12 = - V_145 ;
break;
}
if ( F_89 ( & V_239 , V_135 , sizeof( V_239 ) ) != 0 ) {
V_12 = - V_181 ;
break;
}
V_239 . V_59 [ sizeof( V_239 . V_59 ) - 1 ] = 0 ;
if ( V_227 == V_237 )
V_56 = 1 ;
else
V_56 = 0 ;
F_92 ( F_131 ( V_82 , V_239 . V_59 ,
V_239 . V_151 ,
V_56 , & V_12 ) ,
L_64 , V_239 . V_59 ) ;
break;
}
default:
F_8 ( L_65 , V_227 ) ;
V_12 = - V_145 ;
}
return V_12 ;
}
struct V_1 * F_132 ( struct V_77 * V_77 ,
const struct V_1 * V_88 ,
const struct V_165 * V_166 )
{
int V_12 ;
struct V_73 * V_128 ;
struct V_73 V_240 = { 0 } ;
void * V_180 ;
struct V_1 * V_241 ;
V_128 = F_104 ( V_166 -> V_137 ) ;
if ( ! V_128 ) {
V_12 = - V_158 ;
goto V_71;
}
V_180 = V_128 -> V_78 ;
memcpy ( V_180 , V_166 -> V_78 , V_166 -> V_137 ) ;
V_12 = F_65 ( V_77 , V_128 , V_180 , V_166 ) ;
if ( V_12 != 0 )
goto V_242;
V_241 = F_133 ( V_77 , V_88 , & V_240 , V_128 ) ;
if ( F_52 ( V_241 ) ) {
V_12 = F_53 ( V_241 ) ;
goto V_242;
}
return V_241 ;
V_242:
F_101 ( V_128 ) ;
V_71:
return F_74 ( V_12 ) ;
}
void F_134 ( struct V_77 * V_77 , struct V_1 * V_88 )
{
struct V_73 * V_74 ;
void * V_180 ;
struct V_243 * V_244 = V_88 -> V_144 ;
struct V_43 * V_76 ;
V_74 = F_135 ( V_88 ) ;
V_180 = V_74 -> V_78 ;
F_18 (iter, loc_cpu_entry, private->size)
F_64 ( V_76 , V_77 ) ;
if ( V_74 -> V_168 > V_74 -> V_187 )
F_46 ( V_244 ) ;
F_101 ( V_74 ) ;
}
static inline bool
F_136 ( T_7 V_245 , T_7 V_246 , T_7 V_247 ,
T_7 type , T_7 V_248 ,
bool V_249 )
{
return ( ( V_245 == 0xFF ) ||
( type == V_245 && V_248 >= V_246 && V_248 <= V_247 ) )
^ V_249 ;
}
static bool
F_137 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_250 * V_251 ;
struct V_250 V_252 ;
const struct V_253 * V_254 = V_40 -> V_117 ;
if ( V_40 -> V_98 != 0 )
return false ;
V_251 = F_138 ( V_38 , V_40 -> V_101 , sizeof( V_252 ) , & V_252 ) ;
if ( V_251 == NULL ) {
F_8 ( L_66 ) ;
V_40 -> V_102 = true ;
return false ;
}
return F_136 ( V_254 -> type ,
V_254 -> V_248 [ 0 ] ,
V_254 -> V_248 [ 1 ] ,
V_251 -> type , V_251 -> V_248 ,
! ! ( V_254 -> V_22 & V_255 ) ) ;
}
static int F_139 ( const struct V_147 * V_40 )
{
const struct V_253 * V_254 = V_40 -> V_117 ;
return ( V_254 -> V_22 & ~ V_255 ) ? - V_145 : 0 ;
}
static int T_8 F_140 ( struct V_77 * V_77 )
{
return F_141 ( V_77 , V_104 ) ;
}
static void T_9 F_142 ( struct V_77 * V_77 )
{
F_143 ( V_77 , V_104 ) ;
}
static int T_10 F_144 ( void )
{
int V_12 ;
V_12 = F_145 ( & V_256 ) ;
if ( V_12 < 0 )
goto V_257;
V_12 = F_146 ( V_258 , F_147 ( V_258 ) ) ;
if ( V_12 < 0 )
goto V_259;
V_12 = F_148 ( V_260 , F_147 ( V_260 ) ) ;
if ( V_12 < 0 )
goto V_261;
V_12 = F_149 ( & V_262 ) ;
if ( V_12 < 0 )
goto V_263;
F_150 ( L_67 ) ;
return 0 ;
V_263:
F_151 ( V_260 , F_147 ( V_260 ) ) ;
V_261:
F_152 ( V_258 , F_147 ( V_258 ) ) ;
V_259:
F_153 ( & V_256 ) ;
V_257:
return V_12 ;
}
static void T_11 F_154 ( void )
{
F_155 ( & V_262 ) ;
F_151 ( V_260 , F_147 ( V_260 ) ) ;
F_152 ( V_258 , F_147 ( V_258 ) ) ;
F_153 ( & V_256 ) ;
}
