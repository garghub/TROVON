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
if ( F_4 ( V_10 , V_13 ,
( V_6 -> V_14 & V_10 -> V_15 . V_16 ) != V_10 -> V_17 . V_16 ) ||
F_4 ( V_10 , V_18 ,
( V_6 -> V_19 & V_10 -> V_20 . V_16 ) != V_10 -> V_21 . V_16 ) )
return false ;
V_12 = F_5 ( V_7 , V_10 -> V_22 , V_10 -> V_23 ) ;
if ( F_4 ( V_10 , V_24 , V_12 != 0 ) )
return false ;
V_12 = F_5 ( V_8 , V_10 -> V_25 , V_10 -> V_26 ) ;
if ( F_4 ( V_10 , V_27 , V_12 != 0 ) )
return false ;
if ( V_10 -> V_28 &&
F_4 ( V_10 , V_29 , V_6 -> V_30 != V_10 -> V_28 ) )
return false ;
if ( F_4 ( V_10 , V_31 ,
( V_10 -> V_32 & V_33 ) && ! V_11 ) )
return false ;
return true ;
}
static bool
F_6 ( const struct V_9 * V_6 )
{
if ( V_6 -> V_32 & ~ V_34 )
return false ;
if ( V_6 -> V_35 & ~ V_36 )
return false ;
return true ;
}
static unsigned int
F_7 ( struct V_37 * V_38 , const struct V_39 * V_40 )
{
F_8 ( L_1 , ( const char * ) V_40 -> V_41 ) ;
return V_42 ;
}
static inline struct V_43 *
F_9 ( const void * V_44 , unsigned int V_45 )
{
return (struct V_43 * ) ( V_44 + V_45 ) ;
}
static inline bool F_10 ( const struct V_43 * V_46 )
{
static const struct V_9 V_47 ;
return V_46 -> V_48 == sizeof( struct V_43 ) &&
memcmp ( & V_46 -> V_6 , & V_47 , sizeof( V_47 ) ) == 0 ;
}
static inline const struct V_49 *
F_11 ( const struct V_43 * V_46 )
{
return F_12 ( (struct V_43 * ) V_46 ) ;
}
static inline int
F_13 ( const struct V_43 * V_50 , const struct V_43 * V_46 ,
const char * V_51 , const char * * V_52 ,
const char * * V_53 , unsigned int * V_54 )
{
const struct V_55 * V_56 = ( void * ) F_11 ( V_50 ) ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 , V_61 ) == 0 ) {
* V_52 = V_56 -> V_57 . V_62 ;
( * V_54 ) = 0 ;
} else if ( V_50 == V_46 ) {
( * V_54 ) ++ ;
if ( F_10 ( V_50 ) &&
strcmp ( V_56 -> V_57 . V_58 . V_59 . V_57 -> V_60 ,
V_63 ) == 0 &&
V_56 -> V_64 < 0 ) {
* V_53 = * V_52 == V_51
? V_65 [ V_66 ]
: V_65 [ V_67 ] ;
}
return 1 ;
} else
( * V_54 ) ++ ;
return 0 ;
}
static void F_14 ( struct V_68 * V_68 ,
const struct V_37 * V_38 ,
unsigned int V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 ,
const char * V_73 ,
const struct V_74 * V_75 ,
const struct V_43 * V_46 )
{
const struct V_43 * V_76 ;
const char * V_51 , * V_52 , * V_53 ;
const struct V_43 * V_77 ;
unsigned int V_54 = 0 ;
V_76 = F_9 ( V_75 -> V_78 , V_75 -> V_79 [ V_69 ] ) ;
V_51 = V_52 = V_80 [ V_69 ] ;
V_53 = V_65 [ V_81 ] ;
F_15 (iter, root, private->size - private->hook_entry[hook])
if ( F_13 ( V_77 , V_46 , V_51 ,
& V_52 , & V_53 , & V_54 ) != 0 )
break;
F_16 ( V_68 , V_82 , V_69 , V_38 , V_71 , V_72 , & V_83 ,
L_2 ,
V_73 , V_52 , V_53 , V_54 ) ;
}
static inline
struct V_43 * F_17 ( const struct V_43 * V_84 )
{
return ( void * ) V_84 + V_84 -> V_85 ;
}
unsigned int
F_18 ( struct V_37 * V_38 ,
const struct V_86 * V_87 ,
struct V_1 * V_88 )
{
unsigned int V_69 = V_87 -> V_69 ;
static const char V_89 [ V_90 ] V_91 ( ( F_19 ( sizeof( long ) ) ) ) ;
const struct V_5 * V_6 ;
unsigned int V_64 = V_42 ;
const char * V_7 , * V_8 ;
const void * V_92 ;
struct V_43 * V_46 , * * V_93 ;
unsigned int V_94 , V_95 ;
const struct V_74 * V_75 ;
struct V_39 V_96 ;
unsigned int V_97 ;
V_94 = 0 ;
V_6 = F_20 ( V_38 ) ;
V_7 = V_87 -> V_71 ? V_87 -> V_71 -> V_60 : V_89 ;
V_8 = V_87 -> V_72 ? V_87 -> V_72 -> V_60 : V_89 ;
V_96 . V_98 = F_21 ( V_6 -> V_99 ) & V_100 ;
V_96 . V_101 = F_22 ( V_38 ) ;
V_96 . V_102 = false ;
V_96 . V_68 = V_87 -> V_68 ;
V_96 . V_71 = V_87 -> V_71 ;
V_96 . V_72 = V_87 -> V_72 ;
V_96 . V_103 = V_104 ;
V_96 . V_105 = V_69 ;
F_23 ( V_88 -> V_106 & ( 1 << V_69 ) ) ;
F_24 () ;
V_97 = F_25 () ;
V_75 = V_88 -> V_75 ;
V_95 = F_26 () ;
F_27 () ;
V_92 = V_75 -> V_78 ;
V_93 = (struct V_43 * * ) V_75 -> V_93 [ V_95 ] ;
if ( F_28 ( & V_107 ) )
V_93 += V_75 -> V_108 * F_29 ( V_109 ) ;
V_46 = F_9 ( V_92 , V_75 -> V_79 [ V_69 ] ) ;
do {
const struct V_49 * V_56 ;
const struct V_110 * V_111 ;
struct V_112 * V_113 ;
F_23 ( V_46 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_46 -> V_6 , V_96 . V_98 ) ) {
V_114:
V_46 = F_17 ( V_46 ) ;
continue;
}
F_30 (ematch, e) {
V_96 . V_115 = V_111 -> V_58 . V_59 . V_115 ;
V_96 . V_116 = V_111 -> V_62 ;
if ( ! V_96 . V_115 -> V_115 ( V_38 , & V_96 ) )
goto V_114;
}
V_113 = F_31 ( & V_46 -> V_117 ) ;
F_32 ( * V_113 , V_38 -> V_118 , 1 ) ;
V_56 = F_12 ( V_46 ) ;
F_23 ( V_56 -> V_58 . V_59 . V_57 ) ;
#if F_33 ( V_119 )
if ( F_34 ( V_38 -> V_120 ) )
F_14 ( V_87 -> V_68 , V_38 , V_69 , V_87 -> V_71 ,
V_87 -> V_72 , V_88 -> V_60 , V_75 , V_46 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_121 ;
V_121 = ( (struct V_55 * ) V_56 ) -> V_64 ;
if ( V_121 < 0 ) {
if ( V_121 != V_122 ) {
V_64 = ( unsigned int ) ( - V_121 ) - 1 ;
break;
}
if ( V_94 == 0 ) {
V_46 = F_9 ( V_92 ,
V_75 -> V_123 [ V_69 ] ) ;
} else {
V_46 = V_93 [ -- V_94 ] ;
V_46 = F_17 ( V_46 ) ;
}
continue;
}
if ( V_92 + V_121 != F_17 ( V_46 ) &&
! ( V_46 -> V_6 . V_32 & V_124 ) )
V_93 [ V_94 ++ ] = V_46 ;
V_46 = F_9 ( V_92 , V_121 ) ;
continue;
}
V_96 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_96 . V_41 = V_56 -> V_62 ;
V_64 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_38 , & V_96 ) ;
V_6 = F_20 ( V_38 ) ;
if ( V_64 == V_125 )
V_46 = F_17 ( V_46 ) ;
else
break;
} while ( ! V_96 . V_102 );
F_35 ( V_97 ) ;
F_36 () ;
if ( V_96 . V_102 )
return V_42 ;
else return V_64 ;
}
static int
F_37 ( const struct V_74 * V_126 ,
unsigned int V_106 , void * V_127 ,
unsigned int * V_128 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_129 ; V_69 ++ ) {
unsigned int V_130 = V_126 -> V_79 [ V_69 ] ;
struct V_43 * V_46 = (struct V_43 * ) ( V_127 + V_130 ) ;
if ( ! ( V_106 & ( 1 << V_69 ) ) )
continue;
V_46 -> V_117 . V_131 = V_130 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_11 ( V_46 ) ;
int V_132 = V_46 -> V_133 & ( 1 << V_69 ) ;
if ( V_46 -> V_133 & ( 1 << V_129 ) )
return 0 ;
V_46 -> V_133 |= ( ( 1 << V_69 ) | ( 1 << V_129 ) ) ;
if ( ( F_10 ( V_46 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_134 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < 0 ) || V_132 ) {
unsigned int V_135 , V_136 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_134 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < - V_137 - 1 )
return 0 ;
do {
V_46 -> V_133 ^= ( 1 << V_129 ) ;
V_135 = V_130 ;
V_130 = V_46 -> V_117 . V_131 ;
V_46 -> V_117 . V_131 = 0 ;
if ( V_130 == V_135 )
goto V_138;
V_46 = (struct V_43 * )
( V_127 + V_130 ) ;
} while ( V_135 == V_130 + V_46 -> V_85 );
V_136 = V_46 -> V_85 ;
V_46 = (struct V_43 * )
( V_127 + V_130 + V_136 ) ;
if ( V_130 + V_136 >= V_126 -> V_136 )
return 0 ;
V_46 -> V_117 . V_131 = V_130 ;
V_130 += V_136 ;
} else {
int V_139 = V_56 -> V_64 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_134 . V_60 ,
V_63 ) == 0 &&
V_139 >= 0 ) {
if ( ! F_38 ( V_128 , V_139 ,
V_126 -> V_140 ) )
return 0 ;
V_46 = (struct V_43 * )
( V_127 + V_139 ) ;
} else {
V_139 = V_130 + V_46 -> V_85 ;
if ( V_139 >= V_126 -> V_136 )
return 0 ;
}
V_46 = (struct V_43 * )
( V_127 + V_139 ) ;
V_46 -> V_117 . V_131 = V_130 ;
V_130 = V_139 ;
}
}
V_138: ;
}
return 1 ;
}
static void F_39 ( struct V_110 * V_141 , struct V_68 * V_68 )
{
struct V_142 V_40 ;
V_40 . V_68 = V_68 ;
V_40 . V_115 = V_141 -> V_58 . V_59 . V_115 ;
V_40 . V_116 = V_141 -> V_62 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_115 -> V_143 != NULL )
V_40 . V_115 -> V_143 ( & V_40 ) ;
F_40 ( V_40 . V_115 -> V_144 ) ;
}
static int
F_41 ( struct V_110 * V_141 , struct V_145 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_146 ;
V_40 -> V_115 = V_141 -> V_58 . V_59 . V_115 ;
V_40 -> V_116 = V_141 -> V_62 ;
return F_42 ( V_40 , V_141 -> V_58 . V_147 - sizeof( * V_141 ) ,
V_6 -> V_28 , V_6 -> V_35 & V_29 ) ;
}
static int
F_43 ( struct V_110 * V_141 , struct V_145 * V_40 )
{
struct V_148 * V_115 ;
int V_12 ;
V_115 = F_44 ( V_104 , V_141 -> V_58 . V_134 . V_60 ,
V_141 -> V_58 . V_134 . V_149 ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_141 -> V_58 . V_59 . V_115 = V_115 ;
V_12 = F_41 ( V_141 , V_40 ) ;
if ( V_12 )
goto V_150;
return 0 ;
V_150:
F_40 ( V_141 -> V_58 . V_59 . V_115 -> V_144 ) ;
return V_12 ;
}
static int F_47 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 )
{
struct V_49 * V_56 = F_12 ( V_46 ) ;
struct V_151 V_40 = {
. V_68 = V_68 ,
. V_88 = V_60 ,
. V_146 = V_46 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_41 = V_56 -> V_62 ,
. V_152 = V_46 -> V_133 ,
. V_103 = V_104 ,
} ;
return F_48 ( & V_40 , V_56 -> V_58 . V_153 - sizeof( * V_56 ) ,
V_46 -> V_6 . V_28 , V_46 -> V_6 . V_35 & V_29 ) ;
}
static int
F_49 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 ,
unsigned int V_136 )
{
struct V_49 * V_56 ;
struct V_154 * V_57 ;
int V_12 ;
unsigned int V_155 ;
struct V_145 V_156 ;
struct V_110 * V_111 ;
unsigned long V_131 ;
V_131 = F_50 () ;
if ( F_51 ( V_131 ) )
return - V_157 ;
V_46 -> V_117 . V_131 = V_131 ;
V_155 = 0 ;
V_156 . V_68 = V_68 ;
V_156 . V_88 = V_60 ;
V_156 . V_146 = & V_46 -> V_6 ;
V_156 . V_152 = V_46 -> V_133 ;
V_156 . V_103 = V_104 ;
F_30 (ematch, e) {
V_12 = F_43 ( V_111 , & V_156 ) ;
if ( V_12 != 0 )
goto V_158;
++ V_155 ;
}
V_56 = F_12 ( V_46 ) ;
V_57 = F_52 ( V_104 , V_56 -> V_58 . V_134 . V_60 ,
V_56 -> V_58 . V_134 . V_149 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_158;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_12 = F_47 ( V_46 , V_68 , V_60 ) ;
if ( V_12 )
goto V_150;
return 0 ;
V_150:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_144 ) ;
V_158:
F_30 (ematch, e) {
if ( V_155 -- == 0 )
break;
F_39 ( V_111 , V_68 ) ;
}
F_53 ( V_46 -> V_117 . V_131 ) ;
return V_12 ;
}
static bool F_54 ( const struct V_43 * V_46 )
{
const struct V_49 * V_56 ;
unsigned int V_64 ;
if ( ! F_10 ( V_46 ) )
return false ;
V_56 = F_11 ( V_46 ) ;
if ( strcmp ( V_56 -> V_58 . V_134 . V_60 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_55 * ) V_56 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_159 ;
}
static int
F_55 ( struct V_43 * V_46 ,
struct V_74 * V_126 ,
const unsigned char * V_44 ,
const unsigned char * V_160 ,
const unsigned int * V_161 ,
const unsigned int * V_162 ,
unsigned int V_106 )
{
unsigned int V_163 ;
int V_150 ;
if ( ( unsigned long ) V_46 % F_56 ( struct V_43 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_43 ) >= V_160 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_160 )
return - V_164 ;
if ( V_46 -> V_85
< sizeof( struct V_43 ) + sizeof( struct V_49 ) )
return - V_164 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_164 ;
V_150 = F_57 ( V_46 , V_46 -> V_165 , V_46 -> V_48 ,
V_46 -> V_85 ) ;
if ( V_150 )
return V_150 ;
for ( V_163 = 0 ; V_163 < V_129 ; V_163 ++ ) {
if ( ! ( V_106 & ( 1 << V_163 ) ) )
continue;
if ( ( unsigned char * ) V_46 - V_44 == V_161 [ V_163 ] )
V_126 -> V_79 [ V_163 ] = V_161 [ V_163 ] ;
if ( ( unsigned char * ) V_46 - V_44 == V_162 [ V_163 ] ) {
if ( ! F_54 ( V_46 ) )
return - V_164 ;
V_126 -> V_123 [ V_163 ] = V_162 [ V_163 ] ;
}
}
V_46 -> V_117 = ( (struct V_112 ) { 0 , 0 } ) ;
V_46 -> V_133 = 0 ;
return 0 ;
}
static void
F_58 ( struct V_43 * V_46 , struct V_68 * V_68 )
{
struct V_166 V_40 ;
struct V_49 * V_56 ;
struct V_110 * V_111 ;
F_30 (ematch, e)
F_39 ( V_111 , V_68 ) ;
V_56 = F_12 ( V_46 ) ;
V_40 . V_68 = V_68 ;
V_40 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_40 . V_41 = V_56 -> V_62 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_57 -> V_143 != NULL )
V_40 . V_57 -> V_143 ( & V_40 ) ;
F_40 ( V_40 . V_57 -> V_144 ) ;
F_53 ( V_46 -> V_117 . V_131 ) ;
}
static int
F_59 ( struct V_68 * V_68 , struct V_74 * V_126 , void * V_127 ,
const struct V_167 * V_168 )
{
struct V_43 * V_77 ;
unsigned int * V_128 ;
unsigned int V_169 ;
int V_12 = 0 ;
V_126 -> V_136 = V_168 -> V_136 ;
V_126 -> V_140 = V_168 -> V_170 ;
for ( V_169 = 0 ; V_169 < V_129 ; V_169 ++ ) {
V_126 -> V_79 [ V_169 ] = 0xFFFFFFFF ;
V_126 -> V_123 [ V_169 ] = 0xFFFFFFFF ;
}
V_128 = F_60 ( V_126 -> V_140 ) ;
if ( ! V_128 )
return - V_157 ;
V_169 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_55 ( V_77 , V_126 , V_127 ,
V_127 + V_168 -> V_136 ,
V_168 -> V_79 ,
V_168 -> V_123 ,
V_168 -> V_106 ) ;
if ( V_12 != 0 )
goto V_171;
if ( V_169 < V_168 -> V_170 )
V_128 [ V_169 ] = ( void * ) V_77 - V_127 ;
++ V_169 ;
if ( strcmp ( F_12 ( V_77 ) -> V_58 . V_134 . V_60 ,
V_61 ) == 0 )
++ V_126 -> V_108 ;
}
V_12 = - V_164 ;
if ( V_169 != V_168 -> V_170 )
goto V_171;
for ( V_169 = 0 ; V_169 < V_129 ; V_169 ++ ) {
if ( ! ( V_168 -> V_106 & ( 1 << V_169 ) ) )
continue;
if ( V_126 -> V_79 [ V_169 ] == 0xFFFFFFFF )
goto V_171;
if ( V_126 -> V_123 [ V_169 ] == 0xFFFFFFFF )
goto V_171;
}
if ( ! F_37 ( V_126 , V_168 -> V_106 , V_127 , V_128 ) ) {
V_12 = - V_172 ;
goto V_171;
}
F_61 ( V_128 ) ;
V_169 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_49 ( V_77 , V_68 , V_168 -> V_60 , V_168 -> V_136 ) ;
if ( V_12 != 0 )
break;
++ V_169 ;
}
if ( V_12 != 0 ) {
F_15 (iter, entry0, newinfo->size) {
if ( V_169 -- == 0 )
break;
F_58 ( V_77 , V_68 ) ;
}
return V_12 ;
}
return V_12 ;
V_171:
F_61 ( V_128 ) ;
return V_12 ;
}
static void
F_62 ( const struct V_74 * V_56 ,
struct V_112 V_117 [] )
{
struct V_43 * V_77 ;
unsigned int V_95 ;
unsigned int V_169 ;
F_63 (cpu) {
T_1 * V_50 = & F_64 ( V_173 , V_95 ) ;
V_169 = 0 ;
F_15 (iter, t->entries, t->size) {
struct V_112 * V_174 ;
T_2 V_175 , V_131 ;
unsigned int V_176 ;
V_174 = F_65 ( & V_77 -> V_117 , V_95 ) ;
do {
V_176 = F_66 ( V_50 ) ;
V_175 = V_174 -> V_175 ;
V_131 = V_174 -> V_131 ;
} while ( F_67 ( V_50 , V_176 ) );
F_32 ( V_117 [ V_169 ] , V_175 , V_131 ) ;
++ V_169 ;
}
}
}
static struct V_112 * F_68 ( const struct V_1 * V_88 )
{
unsigned int V_177 ;
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
V_177 = sizeof( struct V_112 ) * V_75 -> V_140 ;
V_117 = F_69 ( V_177 ) ;
if ( V_117 == NULL )
return F_70 ( - V_157 ) ;
F_62 ( V_75 , V_117 ) ;
return V_117 ;
}
static int
F_71 ( unsigned int V_178 ,
const struct V_1 * V_88 ,
void T_3 * V_179 )
{
unsigned int V_180 , V_181 ;
const struct V_43 * V_46 ;
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
int V_12 = 0 ;
const void * V_182 ;
V_117 = F_68 ( V_88 ) ;
if ( F_45 ( V_117 ) )
return F_46 ( V_117 ) ;
V_182 = V_75 -> V_78 ;
if ( F_72 ( V_179 , V_182 , V_178 ) != 0 ) {
V_12 = - V_183 ;
goto V_184;
}
for ( V_180 = 0 , V_181 = 0 ; V_180 < V_178 ; V_180 += V_46 -> V_85 , V_181 ++ ) {
unsigned int V_169 ;
const struct V_110 * V_141 ;
const struct V_49 * V_56 ;
V_46 = (struct V_43 * ) ( V_182 + V_180 ) ;
if ( F_72 ( V_179 + V_180
+ F_73 ( struct V_43 , V_117 ) ,
& V_117 [ V_181 ] ,
sizeof( V_117 [ V_181 ] ) ) != 0 ) {
V_12 = - V_183 ;
goto V_184;
}
for ( V_169 = sizeof( struct V_43 ) ;
V_169 < V_46 -> V_48 ;
V_169 += V_141 -> V_58 . V_147 ) {
V_141 = ( void * ) V_46 + V_169 ;
if ( F_72 ( V_179 + V_180 + V_169
+ F_73 ( struct V_110 ,
V_58 . V_134 . V_60 ) ,
V_141 -> V_58 . V_59 . V_115 -> V_60 ,
strlen ( V_141 -> V_58 . V_59 . V_115 -> V_60 ) + 1 )
!= 0 ) {
V_12 = - V_183 ;
goto V_184;
}
}
V_56 = F_11 ( V_46 ) ;
if ( F_72 ( V_179 + V_180 + V_46 -> V_48
+ F_73 ( struct V_49 ,
V_58 . V_134 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_12 = - V_183 ;
goto V_184;
}
}
V_184:
F_74 ( V_117 ) ;
return V_12 ;
}
static void F_75 ( void * V_21 , const void * V_17 )
{
int V_121 = * ( V_185 * ) V_17 ;
if ( V_121 > 0 )
V_121 += F_76 ( V_82 , V_121 ) ;
memcpy ( V_21 , & V_121 , sizeof( V_121 ) ) ;
}
static int F_77 ( void T_3 * V_21 , const void * V_17 )
{
V_185 V_186 = * ( int * ) V_17 ;
if ( V_186 > 0 )
V_186 -= F_76 ( V_82 , V_186 ) ;
return F_72 ( V_21 , & V_186 , sizeof( V_186 ) ) ? - V_183 : 0 ;
}
static int F_78 ( const struct V_43 * V_46 ,
const struct V_74 * V_2 ,
const void * V_44 , struct V_74 * V_126 )
{
const struct V_110 * V_111 ;
const struct V_49 * V_56 ;
unsigned int V_187 ;
int V_180 , V_169 , V_12 ;
V_180 = sizeof( struct V_43 ) - sizeof( struct V_188 ) ;
V_187 = ( void * ) V_46 - V_44 ;
F_30 (ematch, e)
V_180 += F_79 ( V_111 -> V_58 . V_59 . V_115 ) ;
V_56 = F_11 ( V_46 ) ;
V_180 += F_80 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_126 -> V_136 -= V_180 ;
V_12 = F_81 ( V_82 , V_187 , V_180 ) ;
if ( V_12 )
return V_12 ;
for ( V_169 = 0 ; V_169 < V_129 ; V_169 ++ ) {
if ( V_2 -> V_79 [ V_169 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_169 ] ) ) )
V_126 -> V_79 [ V_169 ] -= V_180 ;
if ( V_2 -> V_123 [ V_169 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_123 [ V_169 ] ) ) )
V_126 -> V_123 [ V_169 ] -= V_180 ;
}
return 0 ;
}
static int F_82 ( const struct V_74 * V_2 ,
struct V_74 * V_126 )
{
struct V_43 * V_77 ;
const void * V_182 ;
int V_12 ;
if ( ! V_126 || ! V_2 )
return - V_164 ;
memcpy ( V_126 , V_2 , F_73 ( struct V_74 , V_78 ) ) ;
V_126 -> V_189 = 0 ;
V_182 = V_2 -> V_78 ;
F_83 ( V_82 , V_2 -> V_140 ) ;
F_15 (iter, loc_cpu_entry, info->size) {
V_12 = F_78 ( V_77 , V_2 , V_182 , V_126 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_84 ( struct V_68 * V_68 , void T_3 * V_134 ,
const int * V_118 , int V_190 )
{
char V_60 [ V_191 ] ;
struct V_1 * V_56 ;
int V_12 ;
if ( * V_118 != sizeof( struct V_192 ) )
return - V_164 ;
if ( F_85 ( V_60 , V_134 , sizeof( V_60 ) ) != 0 )
return - V_183 ;
V_60 [ V_191 - 1 ] = '\0' ;
#ifdef F_86
if ( V_190 )
F_87 ( V_82 ) ;
#endif
V_56 = F_88 ( F_89 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( ! F_90 ( V_56 ) ) {
struct V_192 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_86
struct V_74 V_174 ;
if ( V_190 ) {
V_12 = F_82 ( V_75 , & V_174 ) ;
F_91 ( V_82 ) ;
V_75 = & V_174 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_106 = V_56 -> V_106 ;
memcpy ( V_2 . V_79 , V_75 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_123 , V_75 -> V_123 ,
sizeof( V_2 . V_123 ) ) ;
V_2 . V_170 = V_75 -> V_140 ;
V_2 . V_136 = V_75 -> V_136 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_72 ( V_134 , & V_2 , * V_118 ) != 0 )
V_12 = - V_183 ;
else
V_12 = 0 ;
F_92 ( V_56 ) ;
F_40 ( V_56 -> V_144 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_193 ;
#ifdef F_86
if ( V_190 )
F_93 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_94 ( struct V_68 * V_68 , struct V_194 T_3 * V_195 ,
const int * V_118 )
{
int V_12 ;
struct V_194 V_196 ;
struct V_1 * V_56 ;
if ( * V_118 < sizeof( V_196 ) )
return - V_164 ;
if ( F_85 ( & V_196 , V_195 , sizeof( V_196 ) ) != 0 )
return - V_183 ;
if ( * V_118 != sizeof( struct V_194 ) + V_196 . V_136 )
return - V_164 ;
V_196 . V_60 [ sizeof( V_196 . V_60 ) - 1 ] = '\0' ;
V_56 = F_89 ( V_68 , V_82 , V_196 . V_60 ) ;
if ( ! F_90 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
if ( V_196 . V_136 == V_75 -> V_136 )
V_12 = F_71 ( V_75 -> V_136 ,
V_56 , V_195 -> V_197 ) ;
else
V_12 = - V_198 ;
F_40 ( V_56 -> V_144 ) ;
F_92 ( V_56 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_193 ;
return V_12 ;
}
static int
F_95 ( struct V_68 * V_68 , const char * V_60 , unsigned int V_106 ,
struct V_74 * V_126 , unsigned int V_199 ,
void T_3 * V_200 )
{
int V_12 ;
struct V_1 * V_56 ;
struct V_74 * V_201 ;
struct V_112 * V_117 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_117 = F_69 ( V_199 * sizeof( struct V_112 ) ) ;
if ( ! V_117 ) {
V_12 = - V_157 ;
goto V_72;
}
V_56 = F_88 ( F_89 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( F_90 ( V_56 ) ) {
V_12 = V_56 ? F_46 ( V_56 ) : - V_193 ;
goto V_202;
}
if ( V_106 != V_56 -> V_106 ) {
V_12 = - V_164 ;
goto V_203;
}
V_201 = F_96 ( V_56 , V_199 , V_126 , & V_12 ) ;
if ( ! V_201 )
goto V_203;
if ( ( V_201 -> V_140 > V_201 -> V_189 ) ||
( V_126 -> V_140 <= V_201 -> V_189 ) )
F_40 ( V_56 -> V_144 ) ;
if ( ( V_201 -> V_140 > V_201 -> V_189 ) &&
( V_126 -> V_140 <= V_201 -> V_189 ) )
F_40 ( V_56 -> V_144 ) ;
F_62 ( V_201 , V_117 ) ;
F_15 (iter, oldinfo->entries, oldinfo->size)
F_58 ( V_77 , V_68 ) ;
F_97 ( V_201 ) ;
if ( F_72 ( V_200 , V_117 ,
sizeof( struct V_112 ) * V_199 ) != 0 ) {
F_98 ( L_4 ) ;
}
F_74 ( V_117 ) ;
F_92 ( V_56 ) ;
return V_12 ;
V_203:
F_40 ( V_56 -> V_144 ) ;
F_92 ( V_56 ) ;
V_202:
F_74 ( V_117 ) ;
V_72:
return V_12 ;
}
static int
F_99 ( struct V_68 * V_68 , const void T_3 * V_134 , unsigned int V_118 )
{
int V_12 ;
struct V_167 V_174 ;
struct V_74 * V_126 ;
void * V_182 ;
struct V_43 * V_77 ;
if ( F_85 ( & V_174 , V_134 , sizeof( V_174 ) ) != 0 )
return - V_183 ;
if ( V_174 . V_199 >= V_204 / sizeof( struct V_112 ) )
return - V_157 ;
if ( V_174 . V_199 == 0 )
return - V_164 ;
V_174 . V_60 [ sizeof( V_174 . V_60 ) - 1 ] = 0 ;
V_126 = F_100 ( V_174 . V_136 ) ;
if ( ! V_126 )
return - V_157 ;
V_182 = V_126 -> V_78 ;
if ( F_85 ( V_182 , V_134 + sizeof( V_174 ) ,
V_174 . V_136 ) != 0 ) {
V_12 = - V_183 ;
goto V_205;
}
V_12 = F_59 ( V_68 , V_126 , V_182 , & V_174 ) ;
if ( V_12 != 0 )
goto V_205;
V_12 = F_95 ( V_68 , V_174 . V_60 , V_174 . V_106 , V_126 ,
V_174 . V_199 , V_174 . V_117 ) ;
if ( V_12 )
goto V_206;
return 0 ;
V_206:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_77 , V_68 ) ;
V_205:
F_97 ( V_126 ) ;
return V_12 ;
}
static int
F_101 ( struct V_68 * V_68 , const void T_3 * V_134 ,
unsigned int V_118 , int V_190 )
{
unsigned int V_169 ;
struct V_207 V_174 ;
struct V_112 * V_208 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_12 = 0 ;
struct V_43 * V_77 ;
unsigned int V_97 ;
V_208 = F_102 ( V_134 , V_118 , & V_174 , V_190 ) ;
if ( F_45 ( V_208 ) )
return F_46 ( V_208 ) ;
V_56 = F_89 ( V_68 , V_82 , V_174 . V_60 ) ;
if ( F_90 ( V_56 ) ) {
V_12 = V_56 ? F_46 ( V_56 ) : - V_193 ;
goto free;
}
F_24 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_140 != V_174 . V_199 ) {
V_12 = - V_164 ;
goto V_209;
}
V_169 = 0 ;
V_97 = F_25 () ;
F_15 (iter, private->entries, private->size) {
struct V_112 * V_174 ;
V_174 = F_31 ( & V_77 -> V_117 ) ;
F_32 ( * V_174 , V_208 [ V_169 ] . V_175 , V_208 [ V_169 ] . V_131 ) ;
++ V_169 ;
}
F_35 ( V_97 ) ;
V_209:
F_36 () ;
F_92 ( V_56 ) ;
F_40 ( V_56 -> V_144 ) ;
free:
F_74 ( V_208 ) ;
return V_12 ;
}
static int
F_103 ( struct V_43 * V_46 , void T_3 * * V_210 ,
unsigned int * V_136 , struct V_112 * V_117 ,
unsigned int V_169 )
{
struct V_49 * V_56 ;
struct V_188 T_3 * V_211 ;
T_4 V_48 , V_85 ;
T_5 V_212 ;
const struct V_110 * V_111 ;
int V_12 = 0 ;
V_212 = * V_136 ;
V_211 = (struct V_188 T_3 * ) * V_210 ;
if ( F_72 ( V_211 , V_46 , sizeof( struct V_43 ) ) != 0 ||
F_72 ( & V_211 -> V_117 , & V_117 [ V_169 ] ,
sizeof( V_117 [ V_169 ] ) ) != 0 )
return - V_183 ;
* V_210 += sizeof( struct V_188 ) ;
* V_136 -= sizeof( struct V_43 ) - sizeof( struct V_188 ) ;
F_30 (ematch, e) {
V_12 = F_104 ( V_111 , V_210 , V_136 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_48 = V_46 -> V_48 - ( V_212 - * V_136 ) ;
V_56 = F_12 ( V_46 ) ;
V_12 = F_105 ( V_56 , V_210 , V_136 ) ;
if ( V_12 )
return V_12 ;
V_85 = V_46 -> V_85 - ( V_212 - * V_136 ) ;
if ( F_106 ( V_48 , & V_211 -> V_48 ) != 0 ||
F_106 ( V_85 , & V_211 -> V_85 ) != 0 )
return - V_183 ;
return 0 ;
}
static int
F_107 ( struct V_110 * V_141 ,
const struct V_9 * V_6 ,
int * V_136 )
{
struct V_148 * V_115 ;
V_115 = F_44 ( V_104 , V_141 -> V_58 . V_134 . V_60 ,
V_141 -> V_58 . V_134 . V_149 ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_141 -> V_58 . V_59 . V_115 = V_115 ;
* V_136 += F_79 ( V_115 ) ;
return 0 ;
}
static void F_108 ( struct V_188 * V_46 )
{
struct V_49 * V_56 ;
struct V_110 * V_111 ;
F_30 (ematch, e)
F_40 ( V_111 -> V_58 . V_59 . V_115 -> V_144 ) ;
V_56 = F_109 ( V_46 ) ;
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_144 ) ;
}
static int
F_110 ( struct V_188 * V_46 ,
struct V_74 * V_126 ,
unsigned int * V_136 ,
const unsigned char * V_44 ,
const unsigned char * V_160 )
{
struct V_110 * V_111 ;
struct V_49 * V_56 ;
struct V_154 * V_57 ;
unsigned int V_187 ;
unsigned int V_155 ;
int V_12 , V_180 ;
if ( ( unsigned long ) V_46 % F_56 ( struct V_188 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_188 ) >= V_160 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_160 )
return - V_164 ;
if ( V_46 -> V_85 < sizeof( struct V_188 ) +
sizeof( struct V_213 ) )
return - V_164 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_164 ;
V_12 = F_111 ( V_46 , V_46 -> V_165 ,
V_46 -> V_48 , V_46 -> V_85 ) ;
if ( V_12 )
return V_12 ;
V_180 = sizeof( struct V_43 ) - sizeof( struct V_188 ) ;
V_187 = ( void * ) V_46 - ( void * ) V_44 ;
V_155 = 0 ;
F_30 (ematch, e) {
V_12 = F_107 ( V_111 , & V_46 -> V_6 , & V_180 ) ;
if ( V_12 != 0 )
goto V_214;
++ V_155 ;
}
V_56 = F_109 ( V_46 ) ;
V_57 = F_52 ( V_104 , V_56 -> V_58 . V_134 . V_60 ,
V_56 -> V_58 . V_134 . V_149 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_214;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_180 += F_80 ( V_57 ) ;
* V_136 += V_180 ;
V_12 = F_81 ( V_82 , V_187 , V_180 ) ;
if ( V_12 )
goto V_72;
return 0 ;
V_72:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_144 ) ;
V_214:
F_30 (ematch, e) {
if ( V_155 -- == 0 )
break;
F_40 ( V_111 -> V_58 . V_59 . V_115 -> V_144 ) ;
}
return V_12 ;
}
static void
F_112 ( struct V_188 * V_46 , void * * V_210 ,
unsigned int * V_136 ,
struct V_74 * V_126 , unsigned char * V_44 )
{
struct V_49 * V_56 ;
struct V_154 * V_57 ;
struct V_43 * V_215 ;
unsigned int V_212 ;
int V_163 ;
struct V_110 * V_111 ;
V_212 = * V_136 ;
V_215 = (struct V_43 * ) * V_210 ;
memcpy ( V_215 , V_46 , sizeof( struct V_43 ) ) ;
memcpy ( & V_215 -> V_117 , & V_46 -> V_117 , sizeof( V_46 -> V_117 ) ) ;
* V_210 += sizeof( struct V_43 ) ;
* V_136 += sizeof( struct V_43 ) - sizeof( struct V_188 ) ;
F_30 (ematch, e)
F_113 ( V_111 , V_210 , V_136 ) ;
V_215 -> V_48 = V_46 -> V_48 - ( V_212 - * V_136 ) ;
V_56 = F_109 ( V_46 ) ;
V_57 = V_56 -> V_58 . V_59 . V_57 ;
F_114 ( V_56 , V_210 , V_136 ) ;
V_215 -> V_85 = V_46 -> V_85 - ( V_212 - * V_136 ) ;
for ( V_163 = 0 ; V_163 < V_129 ; V_163 ++ ) {
if ( ( unsigned char * ) V_215 - V_44 < V_126 -> V_79 [ V_163 ] )
V_126 -> V_79 [ V_163 ] -= V_212 - * V_136 ;
if ( ( unsigned char * ) V_215 - V_44 < V_126 -> V_123 [ V_163 ] )
V_126 -> V_123 [ V_163 ] -= V_212 - * V_136 ;
}
}
static int
F_115 ( struct V_68 * V_68 ,
struct V_74 * * V_216 ,
void * * V_217 ,
const struct V_218 * V_219 )
{
unsigned int V_169 , V_155 ;
struct V_74 * V_126 , * V_2 ;
void * V_130 , * V_127 , * V_220 ;
struct V_188 * V_221 ;
struct V_167 V_168 ;
unsigned int V_136 ;
int V_12 ;
V_2 = * V_216 ;
V_127 = * V_217 ;
V_136 = V_219 -> V_136 ;
V_2 -> V_140 = V_219 -> V_170 ;
V_155 = 0 ;
F_87 ( V_82 ) ;
F_83 ( V_82 , V_219 -> V_170 ) ;
F_15 (iter0, entry0, compatr->size) {
V_12 = F_110 ( V_221 , V_2 , & V_136 ,
V_127 ,
V_127 + V_219 -> V_136 ) ;
if ( V_12 != 0 )
goto V_222;
++ V_155 ;
}
V_12 = - V_164 ;
if ( V_155 != V_219 -> V_170 )
goto V_222;
V_12 = - V_157 ;
V_126 = F_100 ( V_136 ) ;
if ( ! V_126 )
goto V_222;
V_126 -> V_140 = V_219 -> V_170 ;
for ( V_169 = 0 ; V_169 < V_129 ; V_169 ++ ) {
V_126 -> V_79 [ V_169 ] = V_219 -> V_79 [ V_169 ] ;
V_126 -> V_123 [ V_169 ] = V_219 -> V_123 [ V_169 ] ;
}
V_220 = V_126 -> V_78 ;
V_130 = V_220 ;
V_136 = V_219 -> V_136 ;
F_15 (iter0, entry0, compatr->size)
F_112 ( V_221 , & V_130 , & V_136 ,
V_126 , V_220 ) ;
F_91 ( V_82 ) ;
F_93 ( V_82 ) ;
memcpy ( & V_168 , V_219 , sizeof( * V_219 ) ) ;
for ( V_169 = 0 ; V_169 < V_129 ; V_169 ++ ) {
V_168 . V_79 [ V_169 ] = V_126 -> V_79 [ V_169 ] ;
V_168 . V_123 [ V_169 ] = V_126 -> V_123 [ V_169 ] ;
}
V_168 . V_199 = 0 ;
V_168 . V_117 = NULL ;
V_168 . V_136 = V_126 -> V_136 ;
V_12 = F_59 ( V_68 , V_126 , V_220 , & V_168 ) ;
if ( V_12 )
goto V_205;
* V_216 = V_126 ;
* V_217 = V_220 ;
F_97 ( V_2 ) ;
return 0 ;
V_205:
F_97 ( V_126 ) ;
return V_12 ;
V_222:
F_91 ( V_82 ) ;
F_93 ( V_82 ) ;
F_15 (iter0, entry0, compatr->size) {
if ( V_155 -- == 0 )
break;
F_108 ( V_221 ) ;
}
return V_12 ;
}
static int
F_116 ( struct V_68 * V_68 , void T_3 * V_134 , unsigned int V_118 )
{
int V_12 ;
struct V_218 V_174 ;
struct V_74 * V_126 ;
void * V_182 ;
struct V_43 * V_77 ;
if ( F_85 ( & V_174 , V_134 , sizeof( V_174 ) ) != 0 )
return - V_183 ;
if ( V_174 . V_199 >= V_204 / sizeof( struct V_112 ) )
return - V_157 ;
if ( V_174 . V_199 == 0 )
return - V_164 ;
V_174 . V_60 [ sizeof( V_174 . V_60 ) - 1 ] = 0 ;
V_126 = F_100 ( V_174 . V_136 ) ;
if ( ! V_126 )
return - V_157 ;
V_182 = V_126 -> V_78 ;
if ( F_85 ( V_182 , V_134 + sizeof( V_174 ) ,
V_174 . V_136 ) != 0 ) {
V_12 = - V_183 ;
goto V_205;
}
V_12 = F_115 ( V_68 , & V_126 , & V_182 , & V_174 ) ;
if ( V_12 != 0 )
goto V_205;
V_12 = F_95 ( V_68 , V_174 . V_60 , V_174 . V_106 , V_126 ,
V_174 . V_199 , F_117 ( V_174 . V_117 ) ) ;
if ( V_12 )
goto V_206;
return 0 ;
V_206:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_77 , V_68 ) ;
V_205:
F_97 ( V_126 ) ;
return V_12 ;
}
static int
F_118 ( struct V_223 * V_224 , int V_225 , void T_3 * V_134 ,
unsigned int V_118 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_116 ( F_120 ( V_224 ) , V_134 , V_118 ) ;
break;
case V_230 :
V_12 = F_101 ( F_120 ( V_224 ) , V_134 , V_118 , 1 ) ;
break;
default:
V_12 = - V_164 ;
}
return V_12 ;
}
static int
F_121 ( unsigned int V_178 , struct V_1 * V_88 ,
void T_3 * V_179 )
{
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
void T_3 * V_130 ;
unsigned int V_136 ;
int V_12 = 0 ;
unsigned int V_169 = 0 ;
struct V_43 * V_77 ;
V_117 = F_68 ( V_88 ) ;
if ( F_45 ( V_117 ) )
return F_46 ( V_117 ) ;
V_130 = V_179 ;
V_136 = V_178 ;
F_15 (iter, private->entries, total_size) {
V_12 = F_103 ( V_77 , & V_130 ,
& V_136 , V_117 , V_169 ++ ) ;
if ( V_12 != 0 )
break;
}
F_74 ( V_117 ) ;
return V_12 ;
}
static int
F_122 ( struct V_68 * V_68 , struct V_231 T_3 * V_195 ,
int * V_118 )
{
int V_12 ;
struct V_231 V_196 ;
struct V_1 * V_56 ;
if ( * V_118 < sizeof( V_196 ) )
return - V_164 ;
if ( F_85 ( & V_196 , V_195 , sizeof( V_196 ) ) != 0 )
return - V_183 ;
if ( * V_118 != sizeof( struct V_231 ) + V_196 . V_136 )
return - V_164 ;
V_196 . V_60 [ sizeof( V_196 . V_60 ) - 1 ] = '\0' ;
F_87 ( V_82 ) ;
V_56 = F_89 ( V_68 , V_82 , V_196 . V_60 ) ;
if ( ! F_90 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
V_12 = F_82 ( V_75 , & V_2 ) ;
if ( ! V_12 && V_196 . V_136 == V_2 . V_136 )
V_12 = F_121 ( V_75 -> V_136 ,
V_56 , V_195 -> V_197 ) ;
else if ( ! V_12 )
V_12 = - V_198 ;
F_91 ( V_82 ) ;
F_40 ( V_56 -> V_144 ) ;
F_92 ( V_56 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_193 ;
F_93 ( V_82 ) ;
return V_12 ;
}
static int
F_123 ( struct V_223 * V_224 , int V_225 , void T_3 * V_134 , int * V_118 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_84 ( F_120 ( V_224 ) , V_134 , V_118 , 1 ) ;
break;
case V_233 :
V_12 = F_122 ( F_120 ( V_224 ) , V_134 , V_118 ) ;
break;
default:
V_12 = F_124 ( V_224 , V_225 , V_134 , V_118 ) ;
}
return V_12 ;
}
static int
F_125 ( struct V_223 * V_224 , int V_225 , void T_3 * V_134 , unsigned int V_118 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_229 :
V_12 = F_99 ( F_120 ( V_224 ) , V_134 , V_118 ) ;
break;
case V_230 :
V_12 = F_101 ( F_120 ( V_224 ) , V_134 , V_118 , 0 ) ;
break;
default:
V_12 = - V_164 ;
}
return V_12 ;
}
static int
F_124 ( struct V_223 * V_224 , int V_225 , void T_3 * V_134 , int * V_118 )
{
int V_12 ;
if ( ! F_119 ( F_120 ( V_224 ) -> V_226 , V_227 ) )
return - V_228 ;
switch ( V_225 ) {
case V_232 :
V_12 = F_84 ( F_120 ( V_224 ) , V_134 , V_118 , 0 ) ;
break;
case V_233 :
V_12 = F_94 ( F_120 ( V_224 ) , V_134 , V_118 ) ;
break;
case V_234 :
case V_235 : {
struct V_236 V_237 ;
int V_57 ;
if ( * V_118 != sizeof( V_237 ) ) {
V_12 = - V_164 ;
break;
}
if ( F_85 ( & V_237 , V_134 , sizeof( V_237 ) ) != 0 ) {
V_12 = - V_183 ;
break;
}
V_237 . V_60 [ sizeof( V_237 . V_60 ) - 1 ] = 0 ;
if ( V_225 == V_235 )
V_57 = 1 ;
else
V_57 = 0 ;
F_88 ( F_126 ( V_82 , V_237 . V_60 ,
V_237 . V_149 ,
V_57 , & V_12 ) ,
L_5 , V_237 . V_60 ) ;
break;
}
default:
V_12 = - V_164 ;
}
return V_12 ;
}
static void F_127 ( struct V_68 * V_68 , struct V_1 * V_88 )
{
struct V_74 * V_75 ;
void * V_182 ;
struct V_238 * V_239 = V_88 -> V_144 ;
struct V_43 * V_77 ;
V_75 = F_128 ( V_88 ) ;
V_182 = V_75 -> V_78 ;
F_15 (iter, loc_cpu_entry, private->size)
F_58 ( V_77 , V_68 ) ;
if ( V_75 -> V_140 > V_75 -> V_189 )
F_40 ( V_239 ) ;
F_97 ( V_75 ) ;
}
int F_129 ( struct V_68 * V_68 , const struct V_1 * V_88 ,
const struct V_167 * V_168 ,
const struct V_240 * V_241 , struct V_1 * * V_242 )
{
int V_12 ;
struct V_74 * V_126 ;
struct V_74 V_243 = { 0 } ;
void * V_182 ;
struct V_1 * V_244 ;
V_126 = F_100 ( V_168 -> V_136 ) ;
if ( ! V_126 )
return - V_157 ;
V_182 = V_126 -> V_78 ;
memcpy ( V_182 , V_168 -> V_78 , V_168 -> V_136 ) ;
V_12 = F_59 ( V_68 , V_126 , V_182 , V_168 ) ;
if ( V_12 != 0 )
goto V_171;
V_244 = F_130 ( V_68 , V_88 , & V_243 , V_126 ) ;
if ( F_45 ( V_244 ) ) {
V_12 = F_46 ( V_244 ) ;
goto V_171;
}
F_131 ( * V_242 , V_244 ) ;
V_12 = F_132 ( V_68 , V_241 , F_133 ( V_88 -> V_106 ) ) ;
if ( V_12 != 0 ) {
F_127 ( V_68 , V_244 ) ;
* V_242 = NULL ;
}
return V_12 ;
V_171:
F_97 ( V_126 ) ;
return V_12 ;
}
void F_134 ( struct V_68 * V_68 , struct V_1 * V_88 ,
const struct V_240 * V_241 )
{
F_135 ( V_68 , V_241 , F_133 ( V_88 -> V_106 ) ) ;
F_127 ( V_68 , V_88 ) ;
}
static inline bool
F_136 ( T_6 V_245 , T_6 V_246 , T_6 V_247 ,
T_6 type , T_6 V_248 ,
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
const struct V_253 * V_254 = V_40 -> V_116 ;
if ( V_40 -> V_98 != 0 )
return false ;
V_251 = F_138 ( V_38 , V_40 -> V_101 , sizeof( V_252 ) , & V_252 ) ;
if ( V_251 == NULL ) {
V_40 -> V_102 = true ;
return false ;
}
return F_136 ( V_254 -> type ,
V_254 -> V_248 [ 0 ] ,
V_254 -> V_248 [ 1 ] ,
V_251 -> type , V_251 -> V_248 ,
! ! ( V_254 -> V_35 & V_255 ) ) ;
}
static int F_139 ( const struct V_145 * V_40 )
{
const struct V_253 * V_254 = V_40 -> V_116 ;
return ( V_254 -> V_35 & ~ V_255 ) ? - V_164 : 0 ;
}
static int T_7 F_140 ( struct V_68 * V_68 )
{
return F_141 ( V_68 , V_104 ) ;
}
static void T_8 F_142 ( struct V_68 * V_68 )
{
F_143 ( V_68 , V_104 ) ;
}
static int T_9 F_144 ( void )
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
F_150 ( L_6 ) ;
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
static void T_10 F_154 ( void )
{
F_155 ( & V_262 ) ;
F_151 ( V_260 , F_147 ( V_260 ) ) ;
F_152 ( V_258 , F_147 ( V_258 ) ) ;
F_153 ( & V_256 ) ;
}
