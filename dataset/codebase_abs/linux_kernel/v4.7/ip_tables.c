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
V_21 ) )
return false ;
V_12 = F_5 ( V_7 , V_10 -> V_22 , V_10 -> V_23 ) ;
if ( F_4 ( V_12 != 0 , V_24 ) )
return false ;
V_12 = F_5 ( V_8 , V_10 -> V_25 , V_10 -> V_26 ) ;
if ( F_4 ( V_12 != 0 , V_27 ) )
return false ;
if ( V_10 -> V_28 &&
F_4 ( V_6 -> V_29 != V_10 -> V_28 , V_30 ) )
return false ;
if ( F_4 ( ( V_10 -> V_31 & V_32 ) && ! V_11 , V_33 ) )
return false ;
return true ;
}
static bool
F_6 ( const struct V_9 * V_6 )
{
if ( V_6 -> V_31 & ~ V_34 )
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
#undef F_4
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
! ( V_46 -> V_6 . V_31 & V_124 ) )
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
static bool F_37 ( const struct V_74 * V_56 ,
const struct V_43 * V_57 )
{
struct V_43 * V_77 ;
F_15 (iter, t->entries, t->size) {
if ( V_77 == V_57 )
return true ;
}
return false ;
}
static int
F_38 ( const struct V_74 * V_126 ,
unsigned int V_106 , void * V_127 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_128 ; V_69 ++ ) {
unsigned int V_129 = V_126 -> V_79 [ V_69 ] ;
struct V_43 * V_46 = (struct V_43 * ) ( V_127 + V_129 ) ;
if ( ! ( V_106 & ( 1 << V_69 ) ) )
continue;
V_46 -> V_117 . V_130 = V_129 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_11 ( V_46 ) ;
int V_131 = V_46 -> V_132 & ( 1 << V_69 ) ;
if ( V_46 -> V_132 & ( 1 << V_128 ) )
return 0 ;
V_46 -> V_132 |= ( ( 1 << V_69 ) | ( 1 << V_128 ) ) ;
if ( ( F_10 ( V_46 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_133 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < 0 ) || V_131 ) {
unsigned int V_134 , V_135 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_133 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < - V_136 - 1 )
return 0 ;
do {
V_46 -> V_132 ^= ( 1 << V_128 ) ;
V_134 = V_129 ;
V_129 = V_46 -> V_117 . V_130 ;
V_46 -> V_117 . V_130 = 0 ;
if ( V_129 == V_134 )
goto V_137;
V_46 = (struct V_43 * )
( V_127 + V_129 ) ;
} while ( V_134 == V_129 + V_46 -> V_85 );
V_135 = V_46 -> V_85 ;
V_46 = (struct V_43 * )
( V_127 + V_129 + V_135 ) ;
if ( V_129 + V_135 >= V_126 -> V_135 )
return 0 ;
V_46 -> V_117 . V_130 = V_129 ;
V_129 += V_135 ;
} else {
int V_138 = V_56 -> V_64 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_133 . V_60 ,
V_63 ) == 0 &&
V_138 >= 0 ) {
V_46 = (struct V_43 * )
( V_127 + V_138 ) ;
if ( ! F_37 ( V_126 , V_46 ) )
return 0 ;
} else {
V_138 = V_129 + V_46 -> V_85 ;
if ( V_138 >= V_126 -> V_135 )
return 0 ;
}
V_46 = (struct V_43 * )
( V_127 + V_138 ) ;
V_46 -> V_117 . V_130 = V_129 ;
V_129 = V_138 ;
}
}
V_137: ;
}
return 1 ;
}
static void F_39 ( struct V_110 * V_139 , struct V_68 * V_68 )
{
struct V_140 V_40 ;
V_40 . V_68 = V_68 ;
V_40 . V_115 = V_139 -> V_58 . V_59 . V_115 ;
V_40 . V_116 = V_139 -> V_62 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_115 -> V_141 != NULL )
V_40 . V_115 -> V_141 ( & V_40 ) ;
F_40 ( V_40 . V_115 -> V_142 ) ;
}
static int
F_41 ( struct V_110 * V_139 , struct V_143 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_144 ;
V_40 -> V_115 = V_139 -> V_58 . V_59 . V_115 ;
V_40 -> V_116 = V_139 -> V_62 ;
return F_42 ( V_40 , V_139 -> V_58 . V_145 - sizeof( * V_139 ) ,
V_6 -> V_28 , V_6 -> V_35 & V_30 ) ;
}
static int
F_43 ( struct V_110 * V_139 , struct V_143 * V_40 )
{
struct V_146 * V_115 ;
int V_12 ;
V_115 = F_44 ( V_104 , V_139 -> V_58 . V_133 . V_60 ,
V_139 -> V_58 . V_133 . V_147 ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_139 -> V_58 . V_59 . V_115 = V_115 ;
V_12 = F_41 ( V_139 , V_40 ) ;
if ( V_12 )
goto V_148;
return 0 ;
V_148:
F_40 ( V_139 -> V_58 . V_59 . V_115 -> V_142 ) ;
return V_12 ;
}
static int F_47 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 )
{
struct V_49 * V_56 = F_12 ( V_46 ) ;
struct V_149 V_40 = {
. V_68 = V_68 ,
. V_88 = V_60 ,
. V_144 = V_46 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_41 = V_56 -> V_62 ,
. V_150 = V_46 -> V_132 ,
. V_103 = V_104 ,
} ;
return F_48 ( & V_40 , V_56 -> V_58 . V_151 - sizeof( * V_56 ) ,
V_46 -> V_6 . V_28 , V_46 -> V_6 . V_35 & V_30 ) ;
}
static int
F_49 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 ,
unsigned int V_135 )
{
struct V_49 * V_56 ;
struct V_152 * V_57 ;
int V_12 ;
unsigned int V_153 ;
struct V_143 V_154 ;
struct V_110 * V_111 ;
unsigned long V_130 ;
V_130 = F_50 () ;
if ( F_51 ( V_130 ) )
return - V_155 ;
V_46 -> V_117 . V_130 = V_130 ;
V_153 = 0 ;
V_154 . V_68 = V_68 ;
V_154 . V_88 = V_60 ;
V_154 . V_144 = & V_46 -> V_6 ;
V_154 . V_150 = V_46 -> V_132 ;
V_154 . V_103 = V_104 ;
F_30 (ematch, e) {
V_12 = F_43 ( V_111 , & V_154 ) ;
if ( V_12 != 0 )
goto V_156;
++ V_153 ;
}
V_56 = F_12 ( V_46 ) ;
V_57 = F_52 ( V_104 , V_56 -> V_58 . V_133 . V_60 ,
V_56 -> V_58 . V_133 . V_147 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_156;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_12 = F_47 ( V_46 , V_68 , V_60 ) ;
if ( V_12 )
goto V_148;
return 0 ;
V_148:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_142 ) ;
V_156:
F_30 (ematch, e) {
if ( V_153 -- == 0 )
break;
F_39 ( V_111 , V_68 ) ;
}
F_53 ( V_46 -> V_117 . V_130 ) ;
return V_12 ;
}
static bool F_54 ( const struct V_43 * V_46 )
{
const struct V_49 * V_56 ;
unsigned int V_64 ;
if ( ! F_10 ( V_46 ) )
return false ;
V_56 = F_11 ( V_46 ) ;
if ( strcmp ( V_56 -> V_58 . V_133 . V_60 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_55 * ) V_56 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_157 ;
}
static int
F_55 ( struct V_43 * V_46 ,
struct V_74 * V_126 ,
const unsigned char * V_44 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
unsigned int V_106 )
{
unsigned int V_161 ;
int V_148 ;
if ( ( unsigned long ) V_46 % F_56 ( struct V_43 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_43 ) >= V_158 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_158 )
return - V_162 ;
if ( V_46 -> V_85
< sizeof( struct V_43 ) + sizeof( struct V_49 ) )
return - V_162 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_162 ;
V_148 = F_57 ( V_46 , V_46 -> V_163 , V_46 -> V_48 ,
V_46 -> V_85 ) ;
if ( V_148 )
return V_148 ;
for ( V_161 = 0 ; V_161 < V_128 ; V_161 ++ ) {
if ( ! ( V_106 & ( 1 << V_161 ) ) )
continue;
if ( ( unsigned char * ) V_46 - V_44 == V_159 [ V_161 ] )
V_126 -> V_79 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_46 - V_44 == V_160 [ V_161 ] ) {
if ( ! F_54 ( V_46 ) )
return - V_162 ;
V_126 -> V_123 [ V_161 ] = V_160 [ V_161 ] ;
}
}
V_46 -> V_117 = ( (struct V_112 ) { 0 , 0 } ) ;
V_46 -> V_132 = 0 ;
return 0 ;
}
static void
F_58 ( struct V_43 * V_46 , struct V_68 * V_68 )
{
struct V_164 V_40 ;
struct V_49 * V_56 ;
struct V_110 * V_111 ;
F_30 (ematch, e)
F_39 ( V_111 , V_68 ) ;
V_56 = F_12 ( V_46 ) ;
V_40 . V_68 = V_68 ;
V_40 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_40 . V_41 = V_56 -> V_62 ;
V_40 . V_103 = V_104 ;
if ( V_40 . V_57 -> V_141 != NULL )
V_40 . V_57 -> V_141 ( & V_40 ) ;
F_40 ( V_40 . V_57 -> V_142 ) ;
F_53 ( V_46 -> V_117 . V_130 ) ;
}
static int
F_59 ( struct V_68 * V_68 , struct V_74 * V_126 , void * V_127 ,
const struct V_165 * V_166 )
{
struct V_43 * V_77 ;
unsigned int V_167 ;
int V_12 = 0 ;
V_126 -> V_135 = V_166 -> V_135 ;
V_126 -> V_168 = V_166 -> V_169 ;
for ( V_167 = 0 ; V_167 < V_128 ; V_167 ++ ) {
V_126 -> V_79 [ V_167 ] = 0xFFFFFFFF ;
V_126 -> V_123 [ V_167 ] = 0xFFFFFFFF ;
}
V_167 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_55 ( V_77 , V_126 , V_127 ,
V_127 + V_166 -> V_135 ,
V_166 -> V_79 ,
V_166 -> V_123 ,
V_166 -> V_106 ) ;
if ( V_12 != 0 )
return V_12 ;
++ V_167 ;
if ( strcmp ( F_12 ( V_77 ) -> V_58 . V_133 . V_60 ,
V_61 ) == 0 )
++ V_126 -> V_108 ;
}
if ( V_167 != V_166 -> V_169 )
return - V_162 ;
for ( V_167 = 0 ; V_167 < V_128 ; V_167 ++ ) {
if ( ! ( V_166 -> V_106 & ( 1 << V_167 ) ) )
continue;
if ( V_126 -> V_79 [ V_167 ] == 0xFFFFFFFF )
return - V_162 ;
if ( V_126 -> V_123 [ V_167 ] == 0xFFFFFFFF )
return - V_162 ;
}
if ( ! F_38 ( V_126 , V_166 -> V_106 , V_127 ) )
return - V_170 ;
V_167 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_49 ( V_77 , V_68 , V_166 -> V_60 , V_166 -> V_135 ) ;
if ( V_12 != 0 )
break;
++ V_167 ;
}
if ( V_12 != 0 ) {
F_15 (iter, entry0, newinfo->size) {
if ( V_167 -- == 0 )
break;
F_58 ( V_77 , V_68 ) ;
}
return V_12 ;
}
return V_12 ;
}
static void
F_60 ( const struct V_74 * V_56 ,
struct V_112 V_117 [] )
{
struct V_43 * V_77 ;
unsigned int V_95 ;
unsigned int V_167 ;
F_61 (cpu) {
T_2 * V_50 = & F_62 ( V_171 , V_95 ) ;
V_167 = 0 ;
F_15 (iter, t->entries, t->size) {
struct V_112 * V_172 ;
T_3 V_173 , V_130 ;
unsigned int V_174 ;
V_172 = F_63 ( & V_77 -> V_117 , V_95 ) ;
do {
V_174 = F_64 ( V_50 ) ;
V_173 = V_172 -> V_173 ;
V_130 = V_172 -> V_130 ;
} while ( F_65 ( V_50 , V_174 ) );
F_32 ( V_117 [ V_167 ] , V_173 , V_130 ) ;
++ V_167 ;
}
}
}
static struct V_112 * F_66 ( const struct V_1 * V_88 )
{
unsigned int V_175 ;
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
V_175 = sizeof( struct V_112 ) * V_75 -> V_168 ;
V_117 = F_67 ( V_175 ) ;
if ( V_117 == NULL )
return F_68 ( - V_155 ) ;
F_60 ( V_75 , V_117 ) ;
return V_117 ;
}
static int
F_69 ( unsigned int V_176 ,
const struct V_1 * V_88 ,
void T_4 * V_177 )
{
unsigned int V_178 , V_179 ;
const struct V_43 * V_46 ;
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
int V_12 = 0 ;
const void * V_180 ;
V_117 = F_66 ( V_88 ) ;
if ( F_45 ( V_117 ) )
return F_46 ( V_117 ) ;
V_180 = V_75 -> V_78 ;
if ( F_70 ( V_177 , V_180 , V_176 ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
for ( V_178 = 0 , V_179 = 0 ; V_178 < V_176 ; V_178 += V_46 -> V_85 , V_179 ++ ) {
unsigned int V_167 ;
const struct V_110 * V_139 ;
const struct V_49 * V_56 ;
V_46 = (struct V_43 * ) ( V_180 + V_178 ) ;
if ( F_70 ( V_177 + V_178
+ F_71 ( struct V_43 , V_117 ) ,
& V_117 [ V_179 ] ,
sizeof( V_117 [ V_179 ] ) ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
for ( V_167 = sizeof( struct V_43 ) ;
V_167 < V_46 -> V_48 ;
V_167 += V_139 -> V_58 . V_145 ) {
V_139 = ( void * ) V_46 + V_167 ;
if ( F_70 ( V_177 + V_178 + V_167
+ F_71 ( struct V_110 ,
V_58 . V_133 . V_60 ) ,
V_139 -> V_58 . V_59 . V_115 -> V_60 ,
strlen ( V_139 -> V_58 . V_59 . V_115 -> V_60 ) + 1 )
!= 0 ) {
V_12 = - V_181 ;
goto V_182;
}
}
V_56 = F_11 ( V_46 ) ;
if ( F_70 ( V_177 + V_178 + V_46 -> V_48
+ F_71 ( struct V_49 ,
V_58 . V_133 . V_60 ) ,
V_56 -> V_58 . V_59 . V_57 -> V_60 ,
strlen ( V_56 -> V_58 . V_59 . V_57 -> V_60 ) + 1 ) != 0 ) {
V_12 = - V_181 ;
goto V_182;
}
}
V_182:
F_72 ( V_117 ) ;
return V_12 ;
}
static void F_73 ( void * V_20 , const void * V_16 )
{
int V_121 = * ( V_183 * ) V_16 ;
if ( V_121 > 0 )
V_121 += F_74 ( V_82 , V_121 ) ;
memcpy ( V_20 , & V_121 , sizeof( V_121 ) ) ;
}
static int F_75 ( void T_4 * V_20 , const void * V_16 )
{
V_183 V_184 = * ( int * ) V_16 ;
if ( V_184 > 0 )
V_184 -= F_74 ( V_82 , V_184 ) ;
return F_70 ( V_20 , & V_184 , sizeof( V_184 ) ) ? - V_181 : 0 ;
}
static int F_76 ( const struct V_43 * V_46 ,
const struct V_74 * V_2 ,
const void * V_44 , struct V_74 * V_126 )
{
const struct V_110 * V_111 ;
const struct V_49 * V_56 ;
unsigned int V_185 ;
int V_178 , V_167 , V_12 ;
V_178 = sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_46 - V_44 ;
F_30 (ematch, e)
V_178 += F_77 ( V_111 -> V_58 . V_59 . V_115 ) ;
V_56 = F_11 ( V_46 ) ;
V_178 += F_78 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_126 -> V_135 -= V_178 ;
V_12 = F_79 ( V_82 , V_185 , V_178 ) ;
if ( V_12 )
return V_12 ;
for ( V_167 = 0 ; V_167 < V_128 ; V_167 ++ ) {
if ( V_2 -> V_79 [ V_167 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_167 ] ) ) )
V_126 -> V_79 [ V_167 ] -= V_178 ;
if ( V_2 -> V_123 [ V_167 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_123 [ V_167 ] ) ) )
V_126 -> V_123 [ V_167 ] -= V_178 ;
}
return 0 ;
}
static int F_80 ( const struct V_74 * V_2 ,
struct V_74 * V_126 )
{
struct V_43 * V_77 ;
const void * V_180 ;
int V_12 ;
if ( ! V_126 || ! V_2 )
return - V_162 ;
memcpy ( V_126 , V_2 , F_71 ( struct V_74 , V_78 ) ) ;
V_126 -> V_187 = 0 ;
V_180 = V_2 -> V_78 ;
F_81 ( V_82 , V_2 -> V_168 ) ;
F_15 (iter, loc_cpu_entry, info->size) {
V_12 = F_76 ( V_77 , V_2 , V_180 , V_126 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_82 ( struct V_68 * V_68 , void T_4 * V_133 ,
const int * V_118 , int V_188 )
{
char V_60 [ V_189 ] ;
struct V_1 * V_56 ;
int V_12 ;
if ( * V_118 != sizeof( struct V_190 ) )
return - V_162 ;
if ( F_83 ( V_60 , V_133 , sizeof( V_60 ) ) != 0 )
return - V_181 ;
V_60 [ V_189 - 1 ] = '\0' ;
#ifdef F_84
if ( V_188 )
F_85 ( V_82 ) ;
#endif
V_56 = F_86 ( F_87 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
struct V_190 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_84
struct V_74 V_172 ;
if ( V_188 ) {
V_12 = F_80 ( V_75 , & V_172 ) ;
F_89 ( V_82 ) ;
V_75 = & V_172 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_106 = V_56 -> V_106 ;
memcpy ( V_2 . V_79 , V_75 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_123 , V_75 -> V_123 ,
sizeof( V_2 . V_123 ) ) ;
V_2 . V_169 = V_75 -> V_168 ;
V_2 . V_135 = V_75 -> V_135 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_70 ( V_133 , & V_2 , * V_118 ) != 0 )
V_12 = - V_181 ;
else
V_12 = 0 ;
F_90 ( V_56 ) ;
F_40 ( V_56 -> V_142 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_191 ;
#ifdef F_84
if ( V_188 )
F_91 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_92 ( struct V_68 * V_68 , struct V_192 T_4 * V_193 ,
const int * V_118 )
{
int V_12 ;
struct V_192 V_194 ;
struct V_1 * V_56 ;
if ( * V_118 < sizeof( V_194 ) )
return - V_162 ;
if ( F_83 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_118 != sizeof( struct V_192 ) + V_194 . V_135 )
return - V_162 ;
V_194 . V_60 [ sizeof( V_194 . V_60 ) - 1 ] = '\0' ;
V_56 = F_87 ( V_68 , V_82 , V_194 . V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
if ( V_194 . V_135 == V_75 -> V_135 )
V_12 = F_69 ( V_75 -> V_135 ,
V_56 , V_193 -> V_195 ) ;
else
V_12 = - V_196 ;
F_40 ( V_56 -> V_142 ) ;
F_90 ( V_56 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_191 ;
return V_12 ;
}
static int
F_93 ( struct V_68 * V_68 , const char * V_60 , unsigned int V_106 ,
struct V_74 * V_126 , unsigned int V_197 ,
void T_4 * V_198 )
{
int V_12 ;
struct V_1 * V_56 ;
struct V_74 * V_199 ;
struct V_112 * V_117 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_117 = F_67 ( V_197 * sizeof( struct V_112 ) ) ;
if ( ! V_117 ) {
V_12 = - V_155 ;
goto V_72;
}
V_56 = F_86 ( F_87 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( F_88 ( V_56 ) ) {
V_12 = V_56 ? F_46 ( V_56 ) : - V_191 ;
goto V_200;
}
if ( V_106 != V_56 -> V_106 ) {
V_12 = - V_162 ;
goto V_201;
}
V_199 = F_94 ( V_56 , V_197 , V_126 , & V_12 ) ;
if ( ! V_199 )
goto V_201;
if ( ( V_199 -> V_168 > V_199 -> V_187 ) ||
( V_126 -> V_168 <= V_199 -> V_187 ) )
F_40 ( V_56 -> V_142 ) ;
if ( ( V_199 -> V_168 > V_199 -> V_187 ) &&
( V_126 -> V_168 <= V_199 -> V_187 ) )
F_40 ( V_56 -> V_142 ) ;
F_60 ( V_199 , V_117 ) ;
F_15 (iter, oldinfo->entries, oldinfo->size)
F_58 ( V_77 , V_68 ) ;
F_95 ( V_199 ) ;
if ( F_70 ( V_198 , V_117 ,
sizeof( struct V_112 ) * V_197 ) != 0 ) {
F_96 ( L_4 ) ;
}
F_72 ( V_117 ) ;
F_90 ( V_56 ) ;
return V_12 ;
V_201:
F_40 ( V_56 -> V_142 ) ;
F_90 ( V_56 ) ;
V_200:
F_72 ( V_117 ) ;
V_72:
return V_12 ;
}
static int
F_97 ( struct V_68 * V_68 , const void T_4 * V_133 , unsigned int V_118 )
{
int V_12 ;
struct V_165 V_172 ;
struct V_74 * V_126 ;
void * V_180 ;
struct V_43 * V_77 ;
if ( F_83 ( & V_172 , V_133 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_112 ) )
return - V_155 ;
if ( V_172 . V_197 == 0 )
return - V_162 ;
V_172 . V_60 [ sizeof( V_172 . V_60 ) - 1 ] = 0 ;
V_126 = F_98 ( V_172 . V_135 ) ;
if ( ! V_126 )
return - V_155 ;
V_180 = V_126 -> V_78 ;
if ( F_83 ( V_180 , V_133 + sizeof( V_172 ) ,
V_172 . V_135 ) != 0 ) {
V_12 = - V_181 ;
goto V_203;
}
V_12 = F_59 ( V_68 , V_126 , V_180 , & V_172 ) ;
if ( V_12 != 0 )
goto V_203;
V_12 = F_93 ( V_68 , V_172 . V_60 , V_172 . V_106 , V_126 ,
V_172 . V_197 , V_172 . V_117 ) ;
if ( V_12 )
goto V_204;
return 0 ;
V_204:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_77 , V_68 ) ;
V_203:
F_95 ( V_126 ) ;
return V_12 ;
}
static int
F_99 ( struct V_68 * V_68 , const void T_4 * V_133 ,
unsigned int V_118 , int V_188 )
{
unsigned int V_167 ;
struct V_205 V_172 ;
struct V_112 * V_206 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_12 = 0 ;
struct V_43 * V_77 ;
unsigned int V_97 ;
V_206 = F_100 ( V_133 , V_118 , & V_172 , V_188 ) ;
if ( F_45 ( V_206 ) )
return F_46 ( V_206 ) ;
V_56 = F_87 ( V_68 , V_82 , V_172 . V_60 ) ;
if ( F_88 ( V_56 ) ) {
V_12 = V_56 ? F_46 ( V_56 ) : - V_191 ;
goto free;
}
F_24 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_168 != V_172 . V_197 ) {
V_12 = - V_162 ;
goto V_207;
}
V_167 = 0 ;
V_97 = F_25 () ;
F_15 (iter, private->entries, private->size) {
struct V_112 * V_172 ;
V_172 = F_31 ( & V_77 -> V_117 ) ;
F_32 ( * V_172 , V_206 [ V_167 ] . V_173 , V_206 [ V_167 ] . V_130 ) ;
++ V_167 ;
}
F_35 ( V_97 ) ;
V_207:
F_36 () ;
F_90 ( V_56 ) ;
F_40 ( V_56 -> V_142 ) ;
free:
F_72 ( V_206 ) ;
return V_12 ;
}
static int
F_101 ( struct V_43 * V_46 , void T_4 * * V_208 ,
unsigned int * V_135 , struct V_112 * V_117 ,
unsigned int V_167 )
{
struct V_49 * V_56 ;
struct V_186 T_4 * V_209 ;
T_5 V_48 , V_85 ;
T_6 V_210 ;
const struct V_110 * V_111 ;
int V_12 = 0 ;
V_210 = * V_135 ;
V_209 = (struct V_186 T_4 * ) * V_208 ;
if ( F_70 ( V_209 , V_46 , sizeof( struct V_43 ) ) != 0 ||
F_70 ( & V_209 -> V_117 , & V_117 [ V_167 ] ,
sizeof( V_117 [ V_167 ] ) ) != 0 )
return - V_181 ;
* V_208 += sizeof( struct V_186 ) ;
* V_135 -= sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
F_30 (ematch, e) {
V_12 = F_102 ( V_111 , V_208 , V_135 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_48 = V_46 -> V_48 - ( V_210 - * V_135 ) ;
V_56 = F_12 ( V_46 ) ;
V_12 = F_103 ( V_56 , V_208 , V_135 ) ;
if ( V_12 )
return V_12 ;
V_85 = V_46 -> V_85 - ( V_210 - * V_135 ) ;
if ( F_104 ( V_48 , & V_209 -> V_48 ) != 0 ||
F_104 ( V_85 , & V_209 -> V_85 ) != 0 )
return - V_181 ;
return 0 ;
}
static int
F_105 ( struct V_110 * V_139 ,
const struct V_9 * V_6 ,
int * V_135 )
{
struct V_146 * V_115 ;
V_115 = F_44 ( V_104 , V_139 -> V_58 . V_133 . V_60 ,
V_139 -> V_58 . V_133 . V_147 ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_139 -> V_58 . V_59 . V_115 = V_115 ;
* V_135 += F_77 ( V_115 ) ;
return 0 ;
}
static void F_106 ( struct V_186 * V_46 )
{
struct V_49 * V_56 ;
struct V_110 * V_111 ;
F_30 (ematch, e)
F_40 ( V_111 -> V_58 . V_59 . V_115 -> V_142 ) ;
V_56 = F_107 ( V_46 ) ;
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_142 ) ;
}
static int
F_108 ( struct V_186 * V_46 ,
struct V_74 * V_126 ,
unsigned int * V_135 ,
const unsigned char * V_44 ,
const unsigned char * V_158 )
{
struct V_110 * V_111 ;
struct V_49 * V_56 ;
struct V_152 * V_57 ;
unsigned int V_185 ;
unsigned int V_153 ;
int V_12 , V_178 ;
if ( ( unsigned long ) V_46 % F_56 ( struct V_186 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_186 ) >= V_158 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_158 )
return - V_162 ;
if ( V_46 -> V_85 < sizeof( struct V_186 ) +
sizeof( struct V_211 ) )
return - V_162 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_162 ;
V_12 = F_109 ( V_46 , V_46 -> V_163 ,
V_46 -> V_48 , V_46 -> V_85 ) ;
if ( V_12 )
return V_12 ;
V_178 = sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_46 - ( void * ) V_44 ;
V_153 = 0 ;
F_30 (ematch, e) {
V_12 = F_105 ( V_111 , & V_46 -> V_6 , & V_178 ) ;
if ( V_12 != 0 )
goto V_212;
++ V_153 ;
}
V_56 = F_107 ( V_46 ) ;
V_57 = F_52 ( V_104 , V_56 -> V_58 . V_133 . V_60 ,
V_56 -> V_58 . V_133 . V_147 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_212;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_178 += F_78 ( V_57 ) ;
* V_135 += V_178 ;
V_12 = F_79 ( V_82 , V_185 , V_178 ) ;
if ( V_12 )
goto V_72;
return 0 ;
V_72:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_142 ) ;
V_212:
F_30 (ematch, e) {
if ( V_153 -- == 0 )
break;
F_40 ( V_111 -> V_58 . V_59 . V_115 -> V_142 ) ;
}
return V_12 ;
}
static void
F_110 ( struct V_186 * V_46 , void * * V_208 ,
unsigned int * V_135 ,
struct V_74 * V_126 , unsigned char * V_44 )
{
struct V_49 * V_56 ;
struct V_152 * V_57 ;
struct V_43 * V_213 ;
unsigned int V_210 ;
int V_161 ;
struct V_110 * V_111 ;
V_210 = * V_135 ;
V_213 = (struct V_43 * ) * V_208 ;
memcpy ( V_213 , V_46 , sizeof( struct V_43 ) ) ;
memcpy ( & V_213 -> V_117 , & V_46 -> V_117 , sizeof( V_46 -> V_117 ) ) ;
* V_208 += sizeof( struct V_43 ) ;
* V_135 += sizeof( struct V_43 ) - sizeof( struct V_186 ) ;
F_30 (ematch, e)
F_111 ( V_111 , V_208 , V_135 ) ;
V_213 -> V_48 = V_46 -> V_48 - ( V_210 - * V_135 ) ;
V_56 = F_107 ( V_46 ) ;
V_57 = V_56 -> V_58 . V_59 . V_57 ;
F_112 ( V_56 , V_208 , V_135 ) ;
V_213 -> V_85 = V_46 -> V_85 - ( V_210 - * V_135 ) ;
for ( V_161 = 0 ; V_161 < V_128 ; V_161 ++ ) {
if ( ( unsigned char * ) V_213 - V_44 < V_126 -> V_79 [ V_161 ] )
V_126 -> V_79 [ V_161 ] -= V_210 - * V_135 ;
if ( ( unsigned char * ) V_213 - V_44 < V_126 -> V_123 [ V_161 ] )
V_126 -> V_123 [ V_161 ] -= V_210 - * V_135 ;
}
}
static int
F_113 ( struct V_68 * V_68 ,
struct V_74 * * V_214 ,
void * * V_215 ,
const struct V_216 * V_217 )
{
unsigned int V_167 , V_153 ;
struct V_74 * V_126 , * V_2 ;
void * V_129 , * V_127 , * V_218 ;
struct V_186 * V_219 ;
struct V_165 V_166 ;
unsigned int V_135 ;
int V_12 ;
V_2 = * V_214 ;
V_127 = * V_215 ;
V_135 = V_217 -> V_135 ;
V_2 -> V_168 = V_217 -> V_169 ;
V_153 = 0 ;
F_85 ( V_82 ) ;
F_81 ( V_82 , V_217 -> V_169 ) ;
F_15 (iter0, entry0, compatr->size) {
V_12 = F_108 ( V_219 , V_2 , & V_135 ,
V_127 ,
V_127 + V_217 -> V_135 ) ;
if ( V_12 != 0 )
goto V_220;
++ V_153 ;
}
V_12 = - V_162 ;
if ( V_153 != V_217 -> V_169 )
goto V_220;
V_12 = - V_155 ;
V_126 = F_98 ( V_135 ) ;
if ( ! V_126 )
goto V_220;
V_126 -> V_168 = V_217 -> V_169 ;
for ( V_167 = 0 ; V_167 < V_128 ; V_167 ++ ) {
V_126 -> V_79 [ V_167 ] = V_217 -> V_79 [ V_167 ] ;
V_126 -> V_123 [ V_167 ] = V_217 -> V_123 [ V_167 ] ;
}
V_218 = V_126 -> V_78 ;
V_129 = V_218 ;
V_135 = V_217 -> V_135 ;
F_15 (iter0, entry0, compatr->size)
F_110 ( V_219 , & V_129 , & V_135 ,
V_126 , V_218 ) ;
F_89 ( V_82 ) ;
F_91 ( V_82 ) ;
memcpy ( & V_166 , V_217 , sizeof( * V_217 ) ) ;
for ( V_167 = 0 ; V_167 < V_128 ; V_167 ++ ) {
V_166 . V_79 [ V_167 ] = V_126 -> V_79 [ V_167 ] ;
V_166 . V_123 [ V_167 ] = V_126 -> V_123 [ V_167 ] ;
}
V_166 . V_197 = 0 ;
V_166 . V_117 = NULL ;
V_166 . V_135 = V_126 -> V_135 ;
V_12 = F_59 ( V_68 , V_126 , V_218 , & V_166 ) ;
if ( V_12 )
goto V_203;
* V_214 = V_126 ;
* V_215 = V_218 ;
F_95 ( V_2 ) ;
return 0 ;
V_203:
F_95 ( V_126 ) ;
return V_12 ;
V_220:
F_89 ( V_82 ) ;
F_91 ( V_82 ) ;
F_15 (iter0, entry0, compatr->size) {
if ( V_153 -- == 0 )
break;
F_106 ( V_219 ) ;
}
return V_12 ;
}
static int
F_114 ( struct V_68 * V_68 , void T_4 * V_133 , unsigned int V_118 )
{
int V_12 ;
struct V_216 V_172 ;
struct V_74 * V_126 ;
void * V_180 ;
struct V_43 * V_77 ;
if ( F_83 ( & V_172 , V_133 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_112 ) )
return - V_155 ;
if ( V_172 . V_197 == 0 )
return - V_162 ;
V_172 . V_60 [ sizeof( V_172 . V_60 ) - 1 ] = 0 ;
V_126 = F_98 ( V_172 . V_135 ) ;
if ( ! V_126 )
return - V_155 ;
V_180 = V_126 -> V_78 ;
if ( F_83 ( V_180 , V_133 + sizeof( V_172 ) ,
V_172 . V_135 ) != 0 ) {
V_12 = - V_181 ;
goto V_203;
}
V_12 = F_113 ( V_68 , & V_126 , & V_180 , & V_172 ) ;
if ( V_12 != 0 )
goto V_203;
V_12 = F_93 ( V_68 , V_172 . V_60 , V_172 . V_106 , V_126 ,
V_172 . V_197 , F_115 ( V_172 . V_117 ) ) ;
if ( V_12 )
goto V_204;
return 0 ;
V_204:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_77 , V_68 ) ;
V_203:
F_95 ( V_126 ) ;
return V_12 ;
}
static int
F_116 ( struct V_221 * V_222 , int V_223 , void T_4 * V_133 ,
unsigned int V_118 )
{
int V_12 ;
if ( ! F_117 ( F_118 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_12 = F_114 ( F_118 ( V_222 ) , V_133 , V_118 ) ;
break;
case V_228 :
V_12 = F_99 ( F_118 ( V_222 ) , V_133 , V_118 , 1 ) ;
break;
default:
V_12 = - V_162 ;
}
return V_12 ;
}
static int
F_119 ( unsigned int V_176 , struct V_1 * V_88 ,
void T_4 * V_177 )
{
struct V_112 * V_117 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
void T_4 * V_129 ;
unsigned int V_135 ;
int V_12 = 0 ;
unsigned int V_167 = 0 ;
struct V_43 * V_77 ;
V_117 = F_66 ( V_88 ) ;
if ( F_45 ( V_117 ) )
return F_46 ( V_117 ) ;
V_129 = V_177 ;
V_135 = V_176 ;
F_15 (iter, private->entries, total_size) {
V_12 = F_101 ( V_77 , & V_129 ,
& V_135 , V_117 , V_167 ++ ) ;
if ( V_12 != 0 )
break;
}
F_72 ( V_117 ) ;
return V_12 ;
}
static int
F_120 ( struct V_68 * V_68 , struct V_229 T_4 * V_193 ,
int * V_118 )
{
int V_12 ;
struct V_229 V_194 ;
struct V_1 * V_56 ;
if ( * V_118 < sizeof( V_194 ) )
return - V_162 ;
if ( F_83 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_118 != sizeof( struct V_229 ) + V_194 . V_135 )
return - V_162 ;
V_194 . V_60 [ sizeof( V_194 . V_60 ) - 1 ] = '\0' ;
F_85 ( V_82 ) ;
V_56 = F_87 ( V_68 , V_82 , V_194 . V_60 ) ;
if ( ! F_88 ( V_56 ) ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
V_12 = F_80 ( V_75 , & V_2 ) ;
if ( ! V_12 && V_194 . V_135 == V_2 . V_135 )
V_12 = F_119 ( V_75 -> V_135 ,
V_56 , V_193 -> V_195 ) ;
else if ( ! V_12 )
V_12 = - V_196 ;
F_89 ( V_82 ) ;
F_40 ( V_56 -> V_142 ) ;
F_90 ( V_56 ) ;
} else
V_12 = V_56 ? F_46 ( V_56 ) : - V_191 ;
F_91 ( V_82 ) ;
return V_12 ;
}
static int
F_121 ( struct V_221 * V_222 , int V_223 , void T_4 * V_133 , int * V_118 )
{
int V_12 ;
if ( ! F_117 ( F_118 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_12 = F_82 ( F_118 ( V_222 ) , V_133 , V_118 , 1 ) ;
break;
case V_231 :
V_12 = F_120 ( F_118 ( V_222 ) , V_133 , V_118 ) ;
break;
default:
V_12 = F_122 ( V_222 , V_223 , V_133 , V_118 ) ;
}
return V_12 ;
}
static int
F_123 ( struct V_221 * V_222 , int V_223 , void T_4 * V_133 , unsigned int V_118 )
{
int V_12 ;
if ( ! F_117 ( F_118 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_12 = F_97 ( F_118 ( V_222 ) , V_133 , V_118 ) ;
break;
case V_228 :
V_12 = F_99 ( F_118 ( V_222 ) , V_133 , V_118 , 0 ) ;
break;
default:
V_12 = - V_162 ;
}
return V_12 ;
}
static int
F_122 ( struct V_221 * V_222 , int V_223 , void T_4 * V_133 , int * V_118 )
{
int V_12 ;
if ( ! F_117 ( F_118 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_12 = F_82 ( F_118 ( V_222 ) , V_133 , V_118 , 0 ) ;
break;
case V_231 :
V_12 = F_92 ( F_118 ( V_222 ) , V_133 , V_118 ) ;
break;
case V_232 :
case V_233 : {
struct V_234 V_235 ;
int V_57 ;
if ( * V_118 != sizeof( V_235 ) ) {
V_12 = - V_162 ;
break;
}
if ( F_83 ( & V_235 , V_133 , sizeof( V_235 ) ) != 0 ) {
V_12 = - V_181 ;
break;
}
V_235 . V_60 [ sizeof( V_235 . V_60 ) - 1 ] = 0 ;
if ( V_223 == V_233 )
V_57 = 1 ;
else
V_57 = 0 ;
F_86 ( F_124 ( V_82 , V_235 . V_60 ,
V_235 . V_147 ,
V_57 , & V_12 ) ,
L_5 , V_235 . V_60 ) ;
break;
}
default:
V_12 = - V_162 ;
}
return V_12 ;
}
static void F_125 ( struct V_68 * V_68 , struct V_1 * V_88 )
{
struct V_74 * V_75 ;
void * V_180 ;
struct V_236 * V_237 = V_88 -> V_142 ;
struct V_43 * V_77 ;
V_75 = F_126 ( V_88 ) ;
V_180 = V_75 -> V_78 ;
F_15 (iter, loc_cpu_entry, private->size)
F_58 ( V_77 , V_68 ) ;
if ( V_75 -> V_168 > V_75 -> V_187 )
F_40 ( V_237 ) ;
F_95 ( V_75 ) ;
}
int F_127 ( struct V_68 * V_68 , const struct V_1 * V_88 ,
const struct V_165 * V_166 ,
const struct V_238 * V_239 , struct V_1 * * V_240 )
{
int V_12 ;
struct V_74 * V_126 ;
struct V_74 V_241 = { 0 } ;
void * V_180 ;
struct V_1 * V_242 ;
V_126 = F_98 ( V_166 -> V_135 ) ;
if ( ! V_126 )
return - V_155 ;
V_180 = V_126 -> V_78 ;
memcpy ( V_180 , V_166 -> V_78 , V_166 -> V_135 ) ;
V_12 = F_59 ( V_68 , V_126 , V_180 , V_166 ) ;
if ( V_12 != 0 )
goto V_243;
V_242 = F_128 ( V_68 , V_88 , & V_241 , V_126 ) ;
if ( F_45 ( V_242 ) ) {
V_12 = F_46 ( V_242 ) ;
goto V_243;
}
F_129 ( * V_240 , V_242 ) ;
V_12 = F_130 ( V_68 , V_239 , F_131 ( V_88 -> V_106 ) ) ;
if ( V_12 != 0 ) {
F_125 ( V_68 , V_242 ) ;
* V_240 = NULL ;
}
return V_12 ;
V_243:
F_95 ( V_126 ) ;
return V_12 ;
}
void F_132 ( struct V_68 * V_68 , struct V_1 * V_88 ,
const struct V_238 * V_239 )
{
F_133 ( V_68 , V_239 , F_131 ( V_88 -> V_106 ) ) ;
F_125 ( V_68 , V_88 ) ;
}
static inline bool
F_134 ( T_7 V_244 , T_7 V_245 , T_7 V_246 ,
T_7 type , T_7 V_247 ,
bool V_248 )
{
return ( ( V_244 == 0xFF ) ||
( type == V_244 && V_247 >= V_245 && V_247 <= V_246 ) )
^ V_248 ;
}
static bool
F_135 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_249 * V_250 ;
struct V_249 V_251 ;
const struct V_252 * V_253 = V_40 -> V_116 ;
if ( V_40 -> V_98 != 0 )
return false ;
V_250 = F_136 ( V_38 , V_40 -> V_101 , sizeof( V_251 ) , & V_251 ) ;
if ( V_250 == NULL ) {
V_40 -> V_102 = true ;
return false ;
}
return F_134 ( V_253 -> type ,
V_253 -> V_247 [ 0 ] ,
V_253 -> V_247 [ 1 ] ,
V_250 -> type , V_250 -> V_247 ,
! ! ( V_253 -> V_35 & V_254 ) ) ;
}
static int F_137 ( const struct V_143 * V_40 )
{
const struct V_252 * V_253 = V_40 -> V_116 ;
return ( V_253 -> V_35 & ~ V_254 ) ? - V_162 : 0 ;
}
static int T_8 F_138 ( struct V_68 * V_68 )
{
return F_139 ( V_68 , V_104 ) ;
}
static void T_9 F_140 ( struct V_68 * V_68 )
{
F_141 ( V_68 , V_104 ) ;
}
static int T_10 F_142 ( void )
{
int V_12 ;
V_12 = F_143 ( & V_255 ) ;
if ( V_12 < 0 )
goto V_256;
V_12 = F_144 ( V_257 , F_145 ( V_257 ) ) ;
if ( V_12 < 0 )
goto V_258;
V_12 = F_146 ( V_259 , F_145 ( V_259 ) ) ;
if ( V_12 < 0 )
goto V_260;
V_12 = F_147 ( & V_261 ) ;
if ( V_12 < 0 )
goto V_262;
F_148 ( L_6 ) ;
return 0 ;
V_262:
F_149 ( V_259 , F_145 ( V_259 ) ) ;
V_260:
F_150 ( V_257 , F_145 ( V_257 ) ) ;
V_258:
F_151 ( & V_255 ) ;
V_256:
return V_12 ;
}
static void T_11 F_152 ( void )
{
F_153 ( & V_261 ) ;
F_149 ( V_259 , F_145 ( V_259 ) ) ;
F_150 ( V_257 , F_145 ( V_257 ) ) ;
F_151 ( & V_255 ) ;
}
