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
& V_10 -> V_23 ) , V_24 ) )
return false ;
V_14 = F_7 ( V_7 , V_10 -> V_25 , V_10 -> V_26 ) ;
if ( F_5 ( V_14 != 0 , V_27 ) )
return false ;
V_14 = F_7 ( V_8 , V_10 -> V_28 , V_10 -> V_29 ) ;
if ( F_5 ( V_14 != 0 , V_30 ) )
return false ;
if ( V_10 -> V_31 & V_32 ) {
int V_33 ;
unsigned short V_34 ;
V_33 = F_8 ( V_6 , V_11 , - 1 , & V_34 , NULL ) ;
if ( V_33 < 0 ) {
if ( V_34 == 0 )
* V_13 = true ;
return false ;
}
* V_12 = V_34 ;
if ( V_10 -> V_35 == V_33 ) {
if ( V_10 -> V_36 & V_37 )
return false ;
return true ;
}
if ( ( V_10 -> V_35 != 0 ) &&
! ( V_10 -> V_36 & V_37 ) )
return false ;
}
return true ;
}
static bool
F_9 ( const struct V_9 * V_16 )
{
if ( V_16 -> V_31 & ~ V_38 )
return false ;
if ( V_16 -> V_36 & ~ V_39 )
return false ;
return true ;
}
static unsigned int
F_10 ( struct V_5 * V_6 , const struct V_40 * V_41 )
{
F_11 ( L_1 , ( const char * ) V_41 -> V_42 ) ;
return V_43 ;
}
static inline struct V_44 *
F_12 ( const void * V_45 , unsigned int V_46 )
{
return (struct V_44 * ) ( V_45 + V_46 ) ;
}
static inline bool F_13 ( const struct V_44 * V_47 )
{
static const struct V_9 V_48 ;
return V_47 -> V_49 == sizeof( struct V_44 ) &&
memcmp ( & V_47 -> V_16 , & V_48 , sizeof( V_48 ) ) == 0 ;
}
static inline const struct V_50 *
F_14 ( const struct V_44 * V_47 )
{
return F_15 ( (struct V_44 * ) V_47 ) ;
}
static inline int
F_16 ( const struct V_44 * V_51 , const struct V_44 * V_47 ,
const char * V_52 , const char * * V_53 ,
const char * * V_54 , unsigned int * V_55 )
{
const struct V_56 * V_57 = ( void * ) F_14 ( V_51 ) ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_60 . V_58 -> V_61 , V_62 ) == 0 ) {
* V_53 = V_57 -> V_58 . V_63 ;
( * V_55 ) = 0 ;
} else if ( V_51 == V_47 ) {
( * V_55 ) ++ ;
if ( F_13 ( V_51 ) &&
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
static void F_17 ( struct V_69 * V_69 ,
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
V_77 = F_12 ( V_76 -> V_79 , V_76 -> V_80 [ V_70 ] ) ;
V_52 = V_53 = V_81 [ V_70 ] ;
V_54 = V_66 [ V_82 ] ;
F_18 (iter, root, private->size - private->hook_entry[hook])
if ( F_16 ( V_78 , V_47 , V_52 ,
& V_53 , & V_54 , & V_55 ) != 0 )
break;
F_19 ( V_69 , V_83 , V_70 , V_6 , V_72 , V_73 , & V_84 ,
L_2 ,
V_74 , V_53 , V_54 , V_55 ) ;
}
static inline struct V_44 *
F_20 ( const struct V_44 * V_85 )
{
return ( void * ) V_85 + V_85 -> V_86 ;
}
unsigned int
F_21 ( struct V_5 * V_6 ,
const struct V_87 * V_88 ,
struct V_1 * V_89 )
{
unsigned int V_70 = V_88 -> V_70 ;
static const char V_90 [ V_91 ] V_92 ( ( F_22 ( sizeof( long ) ) ) ) ;
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
F_23 ( V_89 -> V_102 & ( 1 << V_70 ) ) ;
F_24 () ;
V_98 = F_25 () ;
V_76 = V_89 -> V_76 ;
F_26 () ;
V_96 = F_27 () ;
V_93 = V_76 -> V_79 ;
V_94 = (struct V_44 * * ) V_76 -> V_94 [ V_96 ] ;
if ( F_28 ( & V_103 ) )
V_94 += V_76 -> V_104 * F_29 ( V_105 ) ;
V_47 = F_12 ( V_93 , V_76 -> V_80 [ V_70 ] ) ;
do {
const struct V_50 * V_57 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
F_23 ( V_47 ) ;
V_97 . V_110 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_47 -> V_16 ,
& V_97 . V_110 , & V_97 . V_12 , & V_97 . V_13 ) ) {
V_111:
V_47 = F_20 ( V_47 ) ;
continue;
}
F_30 (ematch, e) {
V_97 . V_112 = V_107 -> V_59 . V_60 . V_112 ;
V_97 . V_113 = V_107 -> V_63 ;
if ( ! V_97 . V_112 -> V_112 ( V_6 , & V_97 ) )
goto V_111;
}
V_109 = F_31 ( & V_47 -> V_114 ) ;
F_32 ( * V_109 , V_6 -> V_115 , 1 ) ;
V_57 = F_14 ( V_47 ) ;
F_23 ( V_57 -> V_59 . V_60 . V_58 ) ;
#if F_33 ( V_116 )
if ( F_34 ( V_6 -> V_117 ) )
F_17 ( V_88 -> V_69 , V_6 , V_70 , V_88 -> V_72 ,
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
V_47 = F_12 ( V_93 ,
V_76 -> V_120 [ V_70 ] ) ;
else
V_47 = F_20 ( V_94 [ -- V_95 ] ) ;
continue;
}
if ( V_93 + V_118 != F_20 ( V_47 ) &&
! ( V_47 -> V_16 . V_31 & V_121 ) ) {
V_94 [ V_95 ++ ] = V_47 ;
}
V_47 = F_12 ( V_93 , V_118 ) ;
continue;
}
V_97 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_97 . V_42 = V_57 -> V_63 ;
V_65 = V_57 -> V_59 . V_60 . V_58 -> V_58 ( V_6 , & V_97 ) ;
if ( V_65 == V_122 )
V_47 = F_20 ( V_47 ) ;
else
break;
} while ( ! V_97 . V_13 );
F_35 ( V_98 ) ;
F_36 () ;
if ( V_97 . V_13 )
return V_43 ;
else return V_65 ;
}
static bool F_37 ( const struct V_75 * V_57 ,
const struct V_44 * V_58 )
{
struct V_44 * V_78 ;
F_18 (iter, t->entries, t->size) {
if ( V_78 == V_58 )
return true ;
}
return false ;
}
static int
F_38 ( const struct V_75 * V_123 ,
unsigned int V_102 , void * V_124 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_125 ; V_70 ++ ) {
unsigned int V_126 = V_123 -> V_80 [ V_70 ] ;
struct V_44 * V_47 = (struct V_44 * ) ( V_124 + V_126 ) ;
if ( ! ( V_102 & ( 1 << V_70 ) ) )
continue;
V_47 -> V_114 . V_127 = V_126 ;
for (; ; ) {
const struct V_56 * V_57
= ( void * ) F_14 ( V_47 ) ;
int V_128 = V_47 -> V_129 & ( 1 << V_70 ) ;
if ( V_47 -> V_129 & ( 1 << V_125 ) )
return 0 ;
V_47 -> V_129 |= ( ( 1 << V_70 ) | ( 1 << V_125 ) ) ;
if ( ( F_13 ( V_47 ) &&
( strcmp ( V_57 -> V_58 . V_59 . V_130 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < 0 ) || V_128 ) {
unsigned int V_131 , V_132 ;
if ( ( strcmp ( V_57 -> V_58 . V_59 . V_130 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < - V_133 - 1 )
return 0 ;
do {
V_47 -> V_129 ^= ( 1 << V_125 ) ;
V_131 = V_126 ;
V_126 = V_47 -> V_114 . V_127 ;
V_47 -> V_114 . V_127 = 0 ;
if ( V_126 == V_131 )
goto V_134;
V_47 = (struct V_44 * )
( V_124 + V_126 ) ;
} while ( V_131 == V_126 + V_47 -> V_86 );
V_132 = V_47 -> V_86 ;
V_47 = (struct V_44 * )
( V_124 + V_126 + V_132 ) ;
if ( V_126 + V_132 >= V_123 -> V_132 )
return 0 ;
V_47 -> V_114 . V_127 = V_126 ;
V_126 += V_132 ;
} else {
int V_135 = V_57 -> V_65 ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_130 . V_61 ,
V_64 ) == 0 &&
V_135 >= 0 ) {
V_47 = (struct V_44 * )
( V_124 + V_135 ) ;
if ( ! F_37 ( V_123 , V_47 ) )
return 0 ;
} else {
V_135 = V_126 + V_47 -> V_86 ;
if ( V_135 >= V_123 -> V_132 )
return 0 ;
}
V_47 = (struct V_44 * )
( V_124 + V_135 ) ;
V_47 -> V_114 . V_127 = V_126 ;
V_126 = V_135 ;
}
}
V_134: ;
}
return 1 ;
}
static void F_39 ( struct V_106 * V_136 , struct V_69 * V_69 )
{
struct V_137 V_41 ;
V_41 . V_69 = V_69 ;
V_41 . V_112 = V_136 -> V_59 . V_60 . V_112 ;
V_41 . V_113 = V_136 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_112 -> V_138 != NULL )
V_41 . V_112 -> V_138 ( & V_41 ) ;
F_40 ( V_41 . V_112 -> V_139 ) ;
}
static int F_41 ( struct V_106 * V_136 , struct V_140 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_141 ;
V_41 -> V_112 = V_136 -> V_59 . V_60 . V_112 ;
V_41 -> V_113 = V_136 -> V_63 ;
return F_42 ( V_41 , V_136 -> V_59 . V_142 - sizeof( * V_136 ) ,
V_16 -> V_35 , V_16 -> V_36 & V_37 ) ;
}
static int
F_43 ( struct V_106 * V_136 , struct V_140 * V_41 )
{
struct V_143 * V_112 ;
int V_14 ;
V_112 = F_44 ( V_100 , V_136 -> V_59 . V_130 . V_61 ,
V_136 -> V_59 . V_130 . V_144 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_136 -> V_59 . V_60 . V_112 = V_112 ;
V_14 = F_41 ( V_136 , V_41 ) ;
if ( V_14 )
goto V_145;
return 0 ;
V_145:
F_40 ( V_136 -> V_59 . V_60 . V_112 -> V_139 ) ;
return V_14 ;
}
static int F_47 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 )
{
struct V_50 * V_57 = F_15 ( V_47 ) ;
struct V_146 V_41 = {
. V_69 = V_69 ,
. V_89 = V_61 ,
. V_141 = V_47 ,
. V_58 = V_57 -> V_59 . V_60 . V_58 ,
. V_42 = V_57 -> V_63 ,
. V_147 = V_47 -> V_129 ,
. V_99 = V_100 ,
} ;
V_57 = F_15 ( V_47 ) ;
return F_48 ( & V_41 , V_57 -> V_59 . V_148 - sizeof( * V_57 ) ,
V_47 -> V_16 . V_35 ,
V_47 -> V_16 . V_36 & V_37 ) ;
}
static int
F_49 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 ,
unsigned int V_132 )
{
struct V_50 * V_57 ;
struct V_149 * V_58 ;
int V_14 ;
unsigned int V_150 ;
struct V_140 V_151 ;
struct V_106 * V_107 ;
unsigned long V_127 ;
V_127 = F_50 () ;
if ( F_51 ( V_127 ) )
return - V_152 ;
V_47 -> V_114 . V_127 = V_127 ;
V_150 = 0 ;
V_151 . V_69 = V_69 ;
V_151 . V_89 = V_61 ;
V_151 . V_141 = & V_47 -> V_16 ;
V_151 . V_147 = V_47 -> V_129 ;
V_151 . V_99 = V_100 ;
F_30 (ematch, e) {
V_14 = F_43 ( V_107 , & V_151 ) ;
if ( V_14 != 0 )
goto V_153;
++ V_150 ;
}
V_57 = F_15 ( V_47 ) ;
V_58 = F_52 ( V_100 , V_57 -> V_59 . V_130 . V_61 ,
V_57 -> V_59 . V_130 . V_144 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_153;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_14 = F_47 ( V_47 , V_69 , V_61 ) ;
if ( V_14 )
goto V_145;
return 0 ;
V_145:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_139 ) ;
V_153:
F_30 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_39 ( V_107 , V_69 ) ;
}
F_53 ( V_47 -> V_114 . V_127 ) ;
return V_14 ;
}
static bool F_54 ( const struct V_44 * V_47 )
{
const struct V_50 * V_57 ;
unsigned int V_65 ;
if ( ! F_13 ( V_47 ) )
return false ;
V_57 = F_14 ( V_47 ) ;
if ( strcmp ( V_57 -> V_59 . V_130 . V_61 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_56 * ) V_57 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_154 ;
}
static int
F_55 ( struct V_44 * V_47 ,
struct V_75 * V_123 ,
const unsigned char * V_45 ,
const unsigned char * V_155 ,
const unsigned int * V_156 ,
const unsigned int * V_157 ,
unsigned int V_102 )
{
unsigned int V_158 ;
int V_145 ;
if ( ( unsigned long ) V_47 % F_56 ( struct V_44 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_44 ) >= V_155 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_155 )
return - V_159 ;
if ( V_47 -> V_86
< sizeof( struct V_44 ) + sizeof( struct V_50 ) )
return - V_159 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_159 ;
V_145 = F_57 ( V_47 , V_47 -> V_160 , V_47 -> V_49 ,
V_47 -> V_86 ) ;
if ( V_145 )
return V_145 ;
for ( V_158 = 0 ; V_158 < V_125 ; V_158 ++ ) {
if ( ! ( V_102 & ( 1 << V_158 ) ) )
continue;
if ( ( unsigned char * ) V_47 - V_45 == V_156 [ V_158 ] )
V_123 -> V_80 [ V_158 ] = V_156 [ V_158 ] ;
if ( ( unsigned char * ) V_47 - V_45 == V_157 [ V_158 ] ) {
if ( ! F_54 ( V_47 ) )
return - V_159 ;
V_123 -> V_120 [ V_158 ] = V_157 [ V_158 ] ;
}
}
V_47 -> V_114 = ( (struct V_108 ) { 0 , 0 } ) ;
V_47 -> V_129 = 0 ;
return 0 ;
}
static void F_58 ( struct V_44 * V_47 , struct V_69 * V_69 )
{
struct V_161 V_41 ;
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_30 (ematch, e)
F_39 ( V_107 , V_69 ) ;
V_57 = F_15 ( V_47 ) ;
V_41 . V_69 = V_69 ;
V_41 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_41 . V_42 = V_57 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_58 -> V_138 != NULL )
V_41 . V_58 -> V_138 ( & V_41 ) ;
F_40 ( V_41 . V_58 -> V_139 ) ;
F_53 ( V_47 -> V_114 . V_127 ) ;
}
static int
F_59 ( struct V_69 * V_69 , struct V_75 * V_123 , void * V_124 ,
const struct V_162 * V_163 )
{
struct V_44 * V_78 ;
unsigned int V_164 ;
int V_14 = 0 ;
V_123 -> V_132 = V_163 -> V_132 ;
V_123 -> V_165 = V_163 -> V_166 ;
for ( V_164 = 0 ; V_164 < V_125 ; V_164 ++ ) {
V_123 -> V_80 [ V_164 ] = 0xFFFFFFFF ;
V_123 -> V_120 [ V_164 ] = 0xFFFFFFFF ;
}
V_164 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_55 ( V_78 , V_123 , V_124 ,
V_124 + V_163 -> V_132 ,
V_163 -> V_80 ,
V_163 -> V_120 ,
V_163 -> V_102 ) ;
if ( V_14 != 0 )
return V_14 ;
++ V_164 ;
if ( strcmp ( F_15 ( V_78 ) -> V_59 . V_130 . V_61 ,
V_62 ) == 0 )
++ V_123 -> V_104 ;
}
if ( V_164 != V_163 -> V_166 )
return - V_159 ;
for ( V_164 = 0 ; V_164 < V_125 ; V_164 ++ ) {
if ( ! ( V_163 -> V_102 & ( 1 << V_164 ) ) )
continue;
if ( V_123 -> V_80 [ V_164 ] == 0xFFFFFFFF )
return - V_159 ;
if ( V_123 -> V_120 [ V_164 ] == 0xFFFFFFFF )
return - V_159 ;
}
if ( ! F_38 ( V_123 , V_163 -> V_102 , V_124 ) )
return - V_167 ;
V_164 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_49 ( V_78 , V_69 , V_163 -> V_61 , V_163 -> V_132 ) ;
if ( V_14 != 0 )
break;
++ V_164 ;
}
if ( V_14 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_164 -- == 0 )
break;
F_58 ( V_78 , V_69 ) ;
}
return V_14 ;
}
return V_14 ;
}
static void
F_60 ( const struct V_75 * V_57 ,
struct V_108 V_114 [] )
{
struct V_44 * V_78 ;
unsigned int V_96 ;
unsigned int V_164 ;
F_61 (cpu) {
T_2 * V_51 = & F_62 ( V_168 , V_96 ) ;
V_164 = 0 ;
F_18 (iter, t->entries, t->size) {
struct V_108 * V_169 ;
T_3 V_170 , V_127 ;
unsigned int V_171 ;
V_169 = F_63 ( & V_78 -> V_114 , V_96 ) ;
do {
V_171 = F_64 ( V_51 ) ;
V_170 = V_169 -> V_170 ;
V_127 = V_169 -> V_127 ;
} while ( F_65 ( V_51 , V_171 ) );
F_32 ( V_114 [ V_164 ] , V_170 , V_127 ) ;
++ V_164 ;
}
}
}
static struct V_108 * F_66 ( const struct V_1 * V_89 )
{
unsigned int V_172 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
V_172 = sizeof( struct V_108 ) * V_76 -> V_165 ;
V_114 = F_67 ( V_172 ) ;
if ( V_114 == NULL )
return F_68 ( - V_152 ) ;
F_60 ( V_76 , V_114 ) ;
return V_114 ;
}
static int
F_69 ( unsigned int V_173 ,
const struct V_1 * V_89 ,
void T_4 * V_174 )
{
unsigned int V_175 , V_176 ;
const struct V_44 * V_47 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
int V_14 = 0 ;
const void * V_177 ;
V_114 = F_66 ( V_89 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_177 = V_76 -> V_79 ;
if ( F_70 ( V_174 , V_177 , V_173 ) != 0 ) {
V_14 = - V_178 ;
goto V_179;
}
for ( V_175 = 0 , V_176 = 0 ; V_175 < V_173 ; V_175 += V_47 -> V_86 , V_176 ++ ) {
unsigned int V_164 ;
const struct V_106 * V_136 ;
const struct V_50 * V_57 ;
V_47 = (struct V_44 * ) ( V_177 + V_175 ) ;
if ( F_70 ( V_174 + V_175
+ F_71 ( struct V_44 , V_114 ) ,
& V_114 [ V_176 ] ,
sizeof( V_114 [ V_176 ] ) ) != 0 ) {
V_14 = - V_178 ;
goto V_179;
}
for ( V_164 = sizeof( struct V_44 ) ;
V_164 < V_47 -> V_49 ;
V_164 += V_136 -> V_59 . V_142 ) {
V_136 = ( void * ) V_47 + V_164 ;
if ( F_70 ( V_174 + V_175 + V_164
+ F_71 ( struct V_106 ,
V_59 . V_130 . V_61 ) ,
V_136 -> V_59 . V_60 . V_112 -> V_61 ,
strlen ( V_136 -> V_59 . V_60 . V_112 -> V_61 ) + 1 )
!= 0 ) {
V_14 = - V_178 ;
goto V_179;
}
}
V_57 = F_14 ( V_47 ) ;
if ( F_70 ( V_174 + V_175 + V_47 -> V_49
+ F_71 ( struct V_50 ,
V_59 . V_130 . V_61 ) ,
V_57 -> V_59 . V_60 . V_58 -> V_61 ,
strlen ( V_57 -> V_59 . V_60 . V_58 -> V_61 ) + 1 ) != 0 ) {
V_14 = - V_178 ;
goto V_179;
}
}
V_179:
F_72 ( V_114 ) ;
return V_14 ;
}
static void F_73 ( void * V_23 , const void * V_19 )
{
int V_118 = * ( V_180 * ) V_19 ;
if ( V_118 > 0 )
V_118 += F_74 ( V_83 , V_118 ) ;
memcpy ( V_23 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_75 ( void T_4 * V_23 , const void * V_19 )
{
V_180 V_181 = * ( int * ) V_19 ;
if ( V_181 > 0 )
V_181 -= F_74 ( V_83 , V_181 ) ;
return F_70 ( V_23 , & V_181 , sizeof( V_181 ) ) ? - V_178 : 0 ;
}
static int F_76 ( const struct V_44 * V_47 ,
const struct V_75 * V_2 ,
const void * V_45 , struct V_75 * V_123 )
{
const struct V_106 * V_107 ;
const struct V_50 * V_57 ;
unsigned int V_182 ;
int V_175 , V_164 , V_14 ;
V_175 = sizeof( struct V_44 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_47 - V_45 ;
F_30 (ematch, e)
V_175 += F_77 ( V_107 -> V_59 . V_60 . V_112 ) ;
V_57 = F_14 ( V_47 ) ;
V_175 += F_78 ( V_57 -> V_59 . V_60 . V_58 ) ;
V_123 -> V_132 -= V_175 ;
V_14 = F_79 ( V_83 , V_182 , V_175 ) ;
if ( V_14 )
return V_14 ;
for ( V_164 = 0 ; V_164 < V_125 ; V_164 ++ ) {
if ( V_2 -> V_80 [ V_164 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_164 ] ) ) )
V_123 -> V_80 [ V_164 ] -= V_175 ;
if ( V_2 -> V_120 [ V_164 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_120 [ V_164 ] ) ) )
V_123 -> V_120 [ V_164 ] -= V_175 ;
}
return 0 ;
}
static int F_80 ( const struct V_75 * V_2 ,
struct V_75 * V_123 )
{
struct V_44 * V_78 ;
const void * V_177 ;
int V_14 ;
if ( ! V_123 || ! V_2 )
return - V_159 ;
memcpy ( V_123 , V_2 , F_71 ( struct V_75 , V_79 ) ) ;
V_123 -> V_184 = 0 ;
V_177 = V_2 -> V_79 ;
F_81 ( V_83 , V_2 -> V_165 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_14 = F_76 ( V_78 , V_2 , V_177 , V_123 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_82 ( struct V_69 * V_69 , void T_4 * V_130 ,
const int * V_115 , int V_185 )
{
char V_61 [ V_186 ] ;
struct V_1 * V_57 ;
int V_14 ;
if ( * V_115 != sizeof( struct V_187 ) )
return - V_159 ;
if ( F_83 ( V_61 , V_130 , sizeof( V_61 ) ) != 0 )
return - V_178 ;
V_61 [ V_186 - 1 ] = '\0' ;
#ifdef F_84
if ( V_185 )
F_85 ( V_83 ) ;
#endif
V_57 = F_86 ( F_87 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( ! F_88 ( V_57 ) ) {
struct V_187 V_2 ;
const struct V_75 * V_76 = V_57 -> V_76 ;
#ifdef F_84
struct V_75 V_169 ;
if ( V_185 ) {
V_14 = F_80 ( V_76 , & V_169 ) ;
F_89 ( V_83 ) ;
V_76 = & V_169 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_102 = V_57 -> V_102 ;
memcpy ( V_2 . V_80 , V_76 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_120 , V_76 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_166 = V_76 -> V_165 ;
V_2 . V_132 = V_76 -> V_132 ;
strcpy ( V_2 . V_61 , V_61 ) ;
if ( F_70 ( V_130 , & V_2 , * V_115 ) != 0 )
V_14 = - V_178 ;
else
V_14 = 0 ;
F_90 ( V_57 ) ;
F_40 ( V_57 -> V_139 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_188 ;
#ifdef F_84
if ( V_185 )
F_91 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_92 ( struct V_69 * V_69 , struct V_189 T_4 * V_190 ,
const int * V_115 )
{
int V_14 ;
struct V_189 V_191 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_191 ) )
return - V_159 ;
if ( F_83 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_178 ;
if ( * V_115 != sizeof( struct V_189 ) + V_191 . V_132 )
return - V_159 ;
V_191 . V_61 [ sizeof( V_191 . V_61 ) - 1 ] = '\0' ;
V_57 = F_87 ( V_69 , V_83 , V_191 . V_61 ) ;
if ( ! F_88 ( V_57 ) ) {
struct V_75 * V_76 = V_57 -> V_76 ;
if ( V_191 . V_132 == V_76 -> V_132 )
V_14 = F_69 ( V_76 -> V_132 ,
V_57 , V_190 -> V_192 ) ;
else
V_14 = - V_193 ;
F_40 ( V_57 -> V_139 ) ;
F_90 ( V_57 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_188 ;
return V_14 ;
}
static int
F_93 ( struct V_69 * V_69 , const char * V_61 , unsigned int V_102 ,
struct V_75 * V_123 , unsigned int V_194 ,
void T_4 * V_195 )
{
int V_14 ;
struct V_1 * V_57 ;
struct V_75 * V_196 ;
struct V_108 * V_114 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_114 = F_67 ( V_194 * sizeof( struct V_108 ) ) ;
if ( ! V_114 ) {
V_14 = - V_152 ;
goto V_73;
}
V_57 = F_86 ( F_87 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( F_88 ( V_57 ) ) {
V_14 = V_57 ? F_46 ( V_57 ) : - V_188 ;
goto V_197;
}
if ( V_102 != V_57 -> V_102 ) {
V_14 = - V_159 ;
goto V_198;
}
V_196 = F_94 ( V_57 , V_194 , V_123 , & V_14 ) ;
if ( ! V_196 )
goto V_198;
if ( ( V_196 -> V_165 > V_196 -> V_184 ) ||
( V_123 -> V_165 <= V_196 -> V_184 ) )
F_40 ( V_57 -> V_139 ) ;
if ( ( V_196 -> V_165 > V_196 -> V_184 ) &&
( V_123 -> V_165 <= V_196 -> V_184 ) )
F_40 ( V_57 -> V_139 ) ;
F_60 ( V_196 , V_114 ) ;
F_18 (iter, oldinfo->entries, oldinfo->size)
F_58 ( V_78 , V_69 ) ;
F_95 ( V_196 ) ;
if ( F_70 ( V_195 , V_114 ,
sizeof( struct V_108 ) * V_194 ) != 0 ) {
F_96 ( L_4 ) ;
}
F_72 ( V_114 ) ;
F_90 ( V_57 ) ;
return V_14 ;
V_198:
F_40 ( V_57 -> V_139 ) ;
F_90 ( V_57 ) ;
V_197:
F_72 ( V_114 ) ;
V_73:
return V_14 ;
}
static int
F_97 ( struct V_69 * V_69 , const void T_4 * V_130 , unsigned int V_115 )
{
int V_14 ;
struct V_162 V_169 ;
struct V_75 * V_123 ;
void * V_177 ;
struct V_44 * V_78 ;
if ( F_83 ( & V_169 , V_130 , sizeof( V_169 ) ) != 0 )
return - V_178 ;
if ( V_169 . V_194 >= V_199 / sizeof( struct V_108 ) )
return - V_152 ;
if ( V_169 . V_194 == 0 )
return - V_159 ;
V_169 . V_61 [ sizeof( V_169 . V_61 ) - 1 ] = 0 ;
V_123 = F_98 ( V_169 . V_132 ) ;
if ( ! V_123 )
return - V_152 ;
V_177 = V_123 -> V_79 ;
if ( F_83 ( V_177 , V_130 + sizeof( V_169 ) ,
V_169 . V_132 ) != 0 ) {
V_14 = - V_178 ;
goto V_200;
}
V_14 = F_59 ( V_69 , V_123 , V_177 , & V_169 ) ;
if ( V_14 != 0 )
goto V_200;
V_14 = F_93 ( V_69 , V_169 . V_61 , V_169 . V_102 , V_123 ,
V_169 . V_194 , V_169 . V_114 ) ;
if ( V_14 )
goto V_201;
return 0 ;
V_201:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_69 ) ;
V_200:
F_95 ( V_123 ) ;
return V_14 ;
}
static int
F_99 ( struct V_69 * V_69 , const void T_4 * V_130 , unsigned int V_115 ,
int V_185 )
{
unsigned int V_164 ;
struct V_202 V_169 ;
struct V_108 * V_203 ;
struct V_1 * V_57 ;
const struct V_75 * V_76 ;
int V_14 = 0 ;
struct V_44 * V_78 ;
unsigned int V_98 ;
V_203 = F_100 ( V_130 , V_115 , & V_169 , V_185 ) ;
if ( F_45 ( V_203 ) )
return F_46 ( V_203 ) ;
V_57 = F_87 ( V_69 , V_83 , V_169 . V_61 ) ;
if ( F_88 ( V_57 ) ) {
V_14 = V_57 ? F_46 ( V_57 ) : - V_188 ;
goto free;
}
F_24 () ;
V_76 = V_57 -> V_76 ;
if ( V_76 -> V_165 != V_169 . V_194 ) {
V_14 = - V_159 ;
goto V_204;
}
V_164 = 0 ;
V_98 = F_25 () ;
F_18 (iter, private->entries, private->size) {
struct V_108 * V_169 ;
V_169 = F_31 ( & V_78 -> V_114 ) ;
F_32 ( * V_169 , V_203 [ V_164 ] . V_170 , V_203 [ V_164 ] . V_127 ) ;
++ V_164 ;
}
F_35 ( V_98 ) ;
V_204:
F_36 () ;
F_90 ( V_57 ) ;
F_40 ( V_57 -> V_139 ) ;
free:
F_72 ( V_203 ) ;
return V_14 ;
}
static int
F_101 ( struct V_44 * V_47 , void T_4 * * V_205 ,
unsigned int * V_132 , struct V_108 * V_114 ,
unsigned int V_164 )
{
struct V_50 * V_57 ;
struct V_183 T_4 * V_206 ;
T_5 V_49 , V_86 ;
T_6 V_207 ;
const struct V_106 * V_107 ;
int V_14 = 0 ;
V_207 = * V_132 ;
V_206 = (struct V_183 T_4 * ) * V_205 ;
if ( F_70 ( V_206 , V_47 , sizeof( struct V_44 ) ) != 0 ||
F_70 ( & V_206 -> V_114 , & V_114 [ V_164 ] ,
sizeof( V_114 [ V_164 ] ) ) != 0 )
return - V_178 ;
* V_205 += sizeof( struct V_183 ) ;
* V_132 -= sizeof( struct V_44 ) - sizeof( struct V_183 ) ;
F_30 (ematch, e) {
V_14 = F_102 ( V_107 , V_205 , V_132 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_49 = V_47 -> V_49 - ( V_207 - * V_132 ) ;
V_57 = F_15 ( V_47 ) ;
V_14 = F_103 ( V_57 , V_205 , V_132 ) ;
if ( V_14 )
return V_14 ;
V_86 = V_47 -> V_86 - ( V_207 - * V_132 ) ;
if ( F_104 ( V_49 , & V_206 -> V_49 ) != 0 ||
F_104 ( V_86 , & V_206 -> V_86 ) != 0 )
return - V_178 ;
return 0 ;
}
static int
F_105 ( struct V_106 * V_136 ,
const struct V_9 * V_16 ,
int * V_132 )
{
struct V_143 * V_112 ;
V_112 = F_44 ( V_100 , V_136 -> V_59 . V_130 . V_61 ,
V_136 -> V_59 . V_130 . V_144 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_136 -> V_59 . V_60 . V_112 = V_112 ;
* V_132 += F_77 ( V_112 ) ;
return 0 ;
}
static void F_106 ( struct V_183 * V_47 )
{
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_30 (ematch, e)
F_40 ( V_107 -> V_59 . V_60 . V_112 -> V_139 ) ;
V_57 = F_107 ( V_47 ) ;
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_139 ) ;
}
static int
F_108 ( struct V_183 * V_47 ,
struct V_75 * V_123 ,
unsigned int * V_132 ,
const unsigned char * V_45 ,
const unsigned char * V_155 )
{
struct V_106 * V_107 ;
struct V_50 * V_57 ;
struct V_149 * V_58 ;
unsigned int V_182 ;
unsigned int V_150 ;
int V_14 , V_175 ;
if ( ( unsigned long ) V_47 % F_56 ( struct V_183 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_183 ) >= V_155 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_155 )
return - V_159 ;
if ( V_47 -> V_86 < sizeof( struct V_183 ) +
sizeof( struct V_208 ) )
return - V_159 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_159 ;
V_14 = F_109 ( V_47 , V_47 -> V_160 ,
V_47 -> V_49 , V_47 -> V_86 ) ;
if ( V_14 )
return V_14 ;
V_175 = sizeof( struct V_44 ) - sizeof( struct V_183 ) ;
V_182 = ( void * ) V_47 - ( void * ) V_45 ;
V_150 = 0 ;
F_30 (ematch, e) {
V_14 = F_105 ( V_107 , & V_47 -> V_16 , & V_175 ) ;
if ( V_14 != 0 )
goto V_209;
++ V_150 ;
}
V_57 = F_107 ( V_47 ) ;
V_58 = F_52 ( V_100 , V_57 -> V_59 . V_130 . V_61 ,
V_57 -> V_59 . V_130 . V_144 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_209;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_175 += F_78 ( V_58 ) ;
* V_132 += V_175 ;
V_14 = F_79 ( V_83 , V_182 , V_175 ) ;
if ( V_14 )
goto V_73;
return 0 ;
V_73:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_139 ) ;
V_209:
F_30 (ematch, e) {
if ( V_150 -- == 0 )
break;
F_40 ( V_107 -> V_59 . V_60 . V_112 -> V_139 ) ;
}
return V_14 ;
}
static void
F_110 ( struct V_183 * V_47 , void * * V_205 ,
unsigned int * V_132 ,
struct V_75 * V_123 , unsigned char * V_45 )
{
struct V_50 * V_57 ;
struct V_44 * V_210 ;
unsigned int V_207 ;
int V_158 ;
struct V_106 * V_107 ;
V_207 = * V_132 ;
V_210 = (struct V_44 * ) * V_205 ;
memcpy ( V_210 , V_47 , sizeof( struct V_44 ) ) ;
memcpy ( & V_210 -> V_114 , & V_47 -> V_114 , sizeof( V_47 -> V_114 ) ) ;
* V_205 += sizeof( struct V_44 ) ;
* V_132 += sizeof( struct V_44 ) - sizeof( struct V_183 ) ;
F_30 (ematch, e)
F_111 ( V_107 , V_205 , V_132 ) ;
V_210 -> V_49 = V_47 -> V_49 - ( V_207 - * V_132 ) ;
V_57 = F_107 ( V_47 ) ;
F_112 ( V_57 , V_205 , V_132 ) ;
V_210 -> V_86 = V_47 -> V_86 - ( V_207 - * V_132 ) ;
for ( V_158 = 0 ; V_158 < V_125 ; V_158 ++ ) {
if ( ( unsigned char * ) V_210 - V_45 < V_123 -> V_80 [ V_158 ] )
V_123 -> V_80 [ V_158 ] -= V_207 - * V_132 ;
if ( ( unsigned char * ) V_210 - V_45 < V_123 -> V_120 [ V_158 ] )
V_123 -> V_120 [ V_158 ] -= V_207 - * V_132 ;
}
}
static int
F_113 ( struct V_69 * V_69 ,
struct V_75 * * V_211 ,
void * * V_212 ,
const struct V_213 * V_214 )
{
unsigned int V_164 , V_150 ;
struct V_75 * V_123 , * V_2 ;
void * V_126 , * V_124 , * V_215 ;
struct V_183 * V_216 ;
struct V_162 V_163 ;
unsigned int V_132 ;
int V_14 = 0 ;
V_2 = * V_211 ;
V_124 = * V_212 ;
V_132 = V_214 -> V_132 ;
V_2 -> V_165 = V_214 -> V_166 ;
V_150 = 0 ;
F_85 ( V_83 ) ;
F_81 ( V_83 , V_214 -> V_166 ) ;
F_18 (iter0, entry0, compatr->size) {
V_14 = F_108 ( V_216 , V_2 , & V_132 ,
V_124 ,
V_124 + V_214 -> V_132 ) ;
if ( V_14 != 0 )
goto V_217;
++ V_150 ;
}
V_14 = - V_159 ;
if ( V_150 != V_214 -> V_166 )
goto V_217;
V_14 = - V_152 ;
V_123 = F_98 ( V_132 ) ;
if ( ! V_123 )
goto V_217;
V_123 -> V_165 = V_214 -> V_166 ;
for ( V_164 = 0 ; V_164 < V_125 ; V_164 ++ ) {
V_123 -> V_80 [ V_164 ] = V_214 -> V_80 [ V_164 ] ;
V_123 -> V_120 [ V_164 ] = V_214 -> V_120 [ V_164 ] ;
}
V_215 = V_123 -> V_79 ;
V_126 = V_215 ;
V_132 = V_214 -> V_132 ;
F_18 (iter0, entry0, compatr->size)
F_110 ( V_216 , & V_126 , & V_132 ,
V_123 , V_215 ) ;
F_89 ( V_83 ) ;
F_91 ( V_83 ) ;
memcpy ( & V_163 , V_214 , sizeof( * V_214 ) ) ;
for ( V_164 = 0 ; V_164 < V_125 ; V_164 ++ ) {
V_163 . V_80 [ V_164 ] = V_123 -> V_80 [ V_164 ] ;
V_163 . V_120 [ V_164 ] = V_123 -> V_120 [ V_164 ] ;
}
V_163 . V_194 = 0 ;
V_163 . V_114 = NULL ;
V_163 . V_132 = V_123 -> V_132 ;
V_14 = F_59 ( V_69 , V_123 , V_215 , & V_163 ) ;
if ( V_14 )
goto V_200;
* V_211 = V_123 ;
* V_212 = V_215 ;
F_95 ( V_2 ) ;
return 0 ;
V_200:
F_95 ( V_123 ) ;
return V_14 ;
V_217:
F_89 ( V_83 ) ;
F_91 ( V_83 ) ;
F_18 (iter0, entry0, compatr->size) {
if ( V_150 -- == 0 )
break;
F_106 ( V_216 ) ;
}
return V_14 ;
}
static int
F_114 ( struct V_69 * V_69 , void T_4 * V_130 , unsigned int V_115 )
{
int V_14 ;
struct V_213 V_169 ;
struct V_75 * V_123 ;
void * V_177 ;
struct V_44 * V_78 ;
if ( F_83 ( & V_169 , V_130 , sizeof( V_169 ) ) != 0 )
return - V_178 ;
if ( V_169 . V_194 >= V_199 / sizeof( struct V_108 ) )
return - V_152 ;
if ( V_169 . V_194 == 0 )
return - V_159 ;
V_169 . V_61 [ sizeof( V_169 . V_61 ) - 1 ] = 0 ;
V_123 = F_98 ( V_169 . V_132 ) ;
if ( ! V_123 )
return - V_152 ;
V_177 = V_123 -> V_79 ;
if ( F_83 ( V_177 , V_130 + sizeof( V_169 ) ,
V_169 . V_132 ) != 0 ) {
V_14 = - V_178 ;
goto V_200;
}
V_14 = F_113 ( V_69 , & V_123 , & V_177 , & V_169 ) ;
if ( V_14 != 0 )
goto V_200;
V_14 = F_93 ( V_69 , V_169 . V_61 , V_169 . V_102 , V_123 ,
V_169 . V_194 , F_115 ( V_169 . V_114 ) ) ;
if ( V_14 )
goto V_201;
return 0 ;
V_201:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_69 ) ;
V_200:
F_95 ( V_123 ) ;
return V_14 ;
}
static int
F_116 ( struct V_218 * V_219 , int V_220 , void T_4 * V_130 ,
unsigned int V_115 )
{
int V_14 ;
if ( ! F_117 ( F_118 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_224 :
V_14 = F_114 ( F_118 ( V_219 ) , V_130 , V_115 ) ;
break;
case V_225 :
V_14 = F_99 ( F_118 ( V_219 ) , V_130 , V_115 , 1 ) ;
break;
default:
V_14 = - V_159 ;
}
return V_14 ;
}
static int
F_119 ( unsigned int V_173 , struct V_1 * V_89 ,
void T_4 * V_174 )
{
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
void T_4 * V_126 ;
unsigned int V_132 ;
int V_14 = 0 ;
unsigned int V_164 = 0 ;
struct V_44 * V_78 ;
V_114 = F_66 ( V_89 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_126 = V_174 ;
V_132 = V_173 ;
F_18 (iter, private->entries, total_size) {
V_14 = F_101 ( V_78 , & V_126 ,
& V_132 , V_114 , V_164 ++ ) ;
if ( V_14 != 0 )
break;
}
F_72 ( V_114 ) ;
return V_14 ;
}
static int
F_120 ( struct V_69 * V_69 , struct V_226 T_4 * V_190 ,
int * V_115 )
{
int V_14 ;
struct V_226 V_191 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_191 ) )
return - V_159 ;
if ( F_83 ( & V_191 , V_190 , sizeof( V_191 ) ) != 0 )
return - V_178 ;
if ( * V_115 != sizeof( struct V_226 ) + V_191 . V_132 )
return - V_159 ;
V_191 . V_61 [ sizeof( V_191 . V_61 ) - 1 ] = '\0' ;
F_85 ( V_83 ) ;
V_57 = F_87 ( V_69 , V_83 , V_191 . V_61 ) ;
if ( ! F_88 ( V_57 ) ) {
const struct V_75 * V_76 = V_57 -> V_76 ;
struct V_75 V_2 ;
V_14 = F_80 ( V_76 , & V_2 ) ;
if ( ! V_14 && V_191 . V_132 == V_2 . V_132 )
V_14 = F_119 ( V_76 -> V_132 ,
V_57 , V_190 -> V_192 ) ;
else if ( ! V_14 )
V_14 = - V_193 ;
F_89 ( V_83 ) ;
F_40 ( V_57 -> V_139 ) ;
F_90 ( V_57 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_188 ;
F_91 ( V_83 ) ;
return V_14 ;
}
static int
F_121 ( struct V_218 * V_219 , int V_220 , void T_4 * V_130 , int * V_115 )
{
int V_14 ;
if ( ! F_117 ( F_118 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_227 :
V_14 = F_82 ( F_118 ( V_219 ) , V_130 , V_115 , 1 ) ;
break;
case V_228 :
V_14 = F_120 ( F_118 ( V_219 ) , V_130 , V_115 ) ;
break;
default:
V_14 = F_122 ( V_219 , V_220 , V_130 , V_115 ) ;
}
return V_14 ;
}
static int
F_123 ( struct V_218 * V_219 , int V_220 , void T_4 * V_130 , unsigned int V_115 )
{
int V_14 ;
if ( ! F_117 ( F_118 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_224 :
V_14 = F_97 ( F_118 ( V_219 ) , V_130 , V_115 ) ;
break;
case V_225 :
V_14 = F_99 ( F_118 ( V_219 ) , V_130 , V_115 , 0 ) ;
break;
default:
V_14 = - V_159 ;
}
return V_14 ;
}
static int
F_122 ( struct V_218 * V_219 , int V_220 , void T_4 * V_130 , int * V_115 )
{
int V_14 ;
if ( ! F_117 ( F_118 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_227 :
V_14 = F_82 ( F_118 ( V_219 ) , V_130 , V_115 , 0 ) ;
break;
case V_228 :
V_14 = F_92 ( F_118 ( V_219 ) , V_130 , V_115 ) ;
break;
case V_229 :
case V_230 : {
struct V_231 V_232 ;
int V_58 ;
if ( * V_115 != sizeof( V_232 ) ) {
V_14 = - V_159 ;
break;
}
if ( F_83 ( & V_232 , V_130 , sizeof( V_232 ) ) != 0 ) {
V_14 = - V_178 ;
break;
}
V_232 . V_61 [ sizeof( V_232 . V_61 ) - 1 ] = 0 ;
if ( V_220 == V_230 )
V_58 = 1 ;
else
V_58 = 0 ;
F_86 ( F_124 ( V_83 , V_232 . V_61 ,
V_232 . V_144 ,
V_58 , & V_14 ) ,
L_5 , V_232 . V_61 ) ;
break;
}
default:
V_14 = - V_159 ;
}
return V_14 ;
}
static void F_125 ( struct V_69 * V_69 , struct V_1 * V_89 )
{
struct V_75 * V_76 ;
void * V_177 ;
struct V_233 * V_234 = V_89 -> V_139 ;
struct V_44 * V_78 ;
V_76 = F_126 ( V_89 ) ;
V_177 = V_76 -> V_79 ;
F_18 (iter, loc_cpu_entry, private->size)
F_58 ( V_78 , V_69 ) ;
if ( V_76 -> V_165 > V_76 -> V_184 )
F_40 ( V_234 ) ;
F_95 ( V_76 ) ;
}
int F_127 ( struct V_69 * V_69 , const struct V_1 * V_89 ,
const struct V_162 * V_163 ,
const struct V_235 * V_236 ,
struct V_1 * * V_237 )
{
int V_14 ;
struct V_75 * V_123 ;
struct V_75 V_238 = { 0 } ;
void * V_177 ;
struct V_1 * V_239 ;
V_123 = F_98 ( V_163 -> V_132 ) ;
if ( ! V_123 )
return - V_152 ;
V_177 = V_123 -> V_79 ;
memcpy ( V_177 , V_163 -> V_79 , V_163 -> V_132 ) ;
V_14 = F_59 ( V_69 , V_123 , V_177 , V_163 ) ;
if ( V_14 != 0 )
goto V_240;
V_239 = F_128 ( V_69 , V_89 , & V_238 , V_123 ) ;
if ( F_45 ( V_239 ) ) {
V_14 = F_46 ( V_239 ) ;
goto V_240;
}
F_129 ( * V_237 , V_239 ) ;
V_14 = F_130 ( V_69 , V_236 , F_131 ( V_89 -> V_102 ) ) ;
if ( V_14 != 0 ) {
F_125 ( V_69 , V_239 ) ;
* V_237 = NULL ;
}
return V_14 ;
V_240:
F_95 ( V_123 ) ;
return V_14 ;
}
void F_132 ( struct V_69 * V_69 , struct V_1 * V_89 ,
const struct V_235 * V_236 )
{
F_133 ( V_69 , V_236 , F_131 ( V_89 -> V_102 ) ) ;
F_125 ( V_69 , V_89 ) ;
}
static inline bool
F_134 ( T_7 V_241 , T_7 V_242 , T_7 V_243 ,
T_7 type , T_7 V_244 ,
bool V_245 )
{
return ( type == V_241 && V_244 >= V_242 && V_244 <= V_243 )
^ V_245 ;
}
static bool
F_135 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_246 * V_247 ;
struct V_246 V_248 ;
const struct V_249 * V_250 = V_41 -> V_113 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_247 = F_136 ( V_6 , V_41 -> V_110 , sizeof( V_248 ) , & V_248 ) ;
if ( V_247 == NULL ) {
V_41 -> V_13 = true ;
return false ;
}
return F_134 ( V_250 -> type ,
V_250 -> V_244 [ 0 ] ,
V_250 -> V_244 [ 1 ] ,
V_247 -> V_251 , V_247 -> V_252 ,
! ! ( V_250 -> V_36 & V_253 ) ) ;
}
static int F_137 ( const struct V_140 * V_41 )
{
const struct V_249 * V_250 = V_41 -> V_113 ;
return ( V_250 -> V_36 & ~ V_253 ) ? - V_159 : 0 ;
}
static int T_8 F_138 ( struct V_69 * V_69 )
{
return F_139 ( V_69 , V_100 ) ;
}
static void T_9 F_140 ( struct V_69 * V_69 )
{
F_141 ( V_69 , V_100 ) ;
}
static int T_10 F_142 ( void )
{
int V_14 ;
V_14 = F_143 ( & V_254 ) ;
if ( V_14 < 0 )
goto V_255;
V_14 = F_144 ( V_256 , F_145 ( V_256 ) ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_146 ( V_258 , F_145 ( V_258 ) ) ;
if ( V_14 < 0 )
goto V_259;
V_14 = F_147 ( & V_260 ) ;
if ( V_14 < 0 )
goto V_261;
F_148 ( L_6 ) ;
return 0 ;
V_261:
F_149 ( V_258 , F_145 ( V_258 ) ) ;
V_259:
F_150 ( V_256 , F_145 ( V_256 ) ) ;
V_257:
F_151 ( & V_254 ) ;
V_255:
return V_14 ;
}
static void T_11 F_152 ( void )
{
F_153 ( & V_260 ) ;
F_149 ( V_258 , F_145 ( V_258 ) ) ;
F_150 ( V_256 , F_145 ( V_256 ) ) ;
F_151 ( & V_254 ) ;
}
