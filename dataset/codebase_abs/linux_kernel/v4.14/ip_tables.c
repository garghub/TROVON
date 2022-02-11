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
V_96 . V_87 = V_87 ;
F_23 ( ! ( V_88 -> V_103 & ( 1 << V_69 ) ) ) ;
F_24 () ;
V_97 = F_25 () ;
V_75 = V_88 -> V_75 ;
V_95 = F_26 () ;
F_27 () ;
V_92 = V_75 -> V_78 ;
V_93 = (struct V_43 * * ) V_75 -> V_93 [ V_95 ] ;
if ( F_28 ( & V_104 ) )
V_93 += V_75 -> V_105 * F_29 ( V_106 ) ;
V_46 = F_9 ( V_92 , V_75 -> V_79 [ V_69 ] ) ;
do {
const struct V_49 * V_56 ;
const struct V_107 * V_108 ;
struct V_109 * V_110 ;
F_23 ( ! V_46 ) ;
if ( ! F_3 ( V_6 , V_7 , V_8 ,
& V_46 -> V_6 , V_96 . V_98 ) ) {
V_111:
V_46 = F_17 ( V_46 ) ;
continue;
}
F_30 (ematch, e) {
V_96 . V_112 = V_108 -> V_58 . V_59 . V_112 ;
V_96 . V_113 = V_108 -> V_62 ;
if ( ! V_96 . V_112 -> V_112 ( V_38 , & V_96 ) )
goto V_111;
}
V_110 = F_31 ( & V_46 -> V_114 ) ;
F_32 ( * V_110 , V_38 -> V_115 , 1 ) ;
V_56 = F_12 ( V_46 ) ;
F_23 ( ! V_56 -> V_58 . V_59 . V_57 ) ;
#if F_33 ( V_116 )
if ( F_34 ( V_38 -> V_117 ) )
F_14 ( V_87 -> V_68 , V_38 , V_69 , V_87 -> V_71 ,
V_87 -> V_72 , V_88 -> V_60 , V_75 , V_46 ) ;
#endif
if ( ! V_56 -> V_58 . V_59 . V_57 -> V_57 ) {
int V_118 ;
V_118 = ( (struct V_55 * ) V_56 ) -> V_64 ;
if ( V_118 < 0 ) {
if ( V_118 != V_119 ) {
V_64 = ( unsigned int ) ( - V_118 ) - 1 ;
break;
}
if ( V_94 == 0 ) {
V_46 = F_9 ( V_92 ,
V_75 -> V_120 [ V_69 ] ) ;
} else {
V_46 = V_93 [ -- V_94 ] ;
V_46 = F_17 ( V_46 ) ;
}
continue;
}
if ( V_92 + V_118 != F_17 ( V_46 ) &&
! ( V_46 -> V_6 . V_32 & V_121 ) )
V_93 [ V_94 ++ ] = V_46 ;
V_46 = F_9 ( V_92 , V_118 ) ;
continue;
}
V_96 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_96 . V_41 = V_56 -> V_62 ;
V_64 = V_56 -> V_58 . V_59 . V_57 -> V_57 ( V_38 , & V_96 ) ;
if ( V_64 == V_122 ) {
V_6 = F_20 ( V_38 ) ;
V_46 = F_17 ( V_46 ) ;
} else {
break;
}
} while ( ! V_96 . V_102 );
F_35 ( V_97 ) ;
F_36 () ;
if ( V_96 . V_102 )
return V_42 ;
else return V_64 ;
}
static int
F_37 ( const struct V_74 * V_123 ,
unsigned int V_103 , void * V_124 ,
unsigned int * V_125 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < V_126 ; V_69 ++ ) {
unsigned int V_127 = V_123 -> V_79 [ V_69 ] ;
struct V_43 * V_46 = V_124 + V_127 ;
if ( ! ( V_103 & ( 1 << V_69 ) ) )
continue;
V_46 -> V_114 . V_128 = V_127 ;
for (; ; ) {
const struct V_55 * V_56
= ( void * ) F_11 ( V_46 ) ;
int V_129 = V_46 -> V_130 & ( 1 << V_69 ) ;
if ( V_46 -> V_130 & ( 1 << V_126 ) )
return 0 ;
V_46 -> V_130 |= ( ( 1 << V_69 ) | ( 1 << V_126 ) ) ;
if ( ( F_10 ( V_46 ) &&
( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < 0 ) || V_129 ) {
unsigned int V_132 , V_133 ;
if ( ( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_63 ) == 0 ) &&
V_56 -> V_64 < - V_134 - 1 )
return 0 ;
do {
V_46 -> V_130 ^= ( 1 << V_126 ) ;
V_132 = V_127 ;
V_127 = V_46 -> V_114 . V_128 ;
V_46 -> V_114 . V_128 = 0 ;
if ( V_127 == V_132 )
goto V_135;
V_46 = V_124 + V_127 ;
} while ( V_132 == V_127 + V_46 -> V_85 );
V_133 = V_46 -> V_85 ;
V_46 = V_124 + V_127 + V_133 ;
if ( V_127 + V_133 >= V_123 -> V_133 )
return 0 ;
V_46 -> V_114 . V_128 = V_127 ;
V_127 += V_133 ;
} else {
int V_136 = V_56 -> V_64 ;
if ( strcmp ( V_56 -> V_57 . V_58 . V_131 . V_60 ,
V_63 ) == 0 &&
V_136 >= 0 ) {
if ( ! F_38 ( V_125 , V_136 ,
V_123 -> V_137 ) )
return 0 ;
V_46 = V_124 + V_136 ;
} else {
V_136 = V_127 + V_46 -> V_85 ;
if ( V_136 >= V_123 -> V_133 )
return 0 ;
}
V_46 = V_124 + V_136 ;
V_46 -> V_114 . V_128 = V_127 ;
V_127 = V_136 ;
}
}
V_135: ;
}
return 1 ;
}
static void F_39 ( struct V_107 * V_138 , struct V_68 * V_68 )
{
struct V_139 V_40 ;
V_40 . V_68 = V_68 ;
V_40 . V_112 = V_138 -> V_58 . V_59 . V_112 ;
V_40 . V_113 = V_138 -> V_62 ;
V_40 . V_140 = V_141 ;
if ( V_40 . V_112 -> V_142 != NULL )
V_40 . V_112 -> V_142 ( & V_40 ) ;
F_40 ( V_40 . V_112 -> V_143 ) ;
}
static int
F_41 ( struct V_107 * V_138 , struct V_144 * V_40 )
{
const struct V_9 * V_6 = V_40 -> V_145 ;
V_40 -> V_112 = V_138 -> V_58 . V_59 . V_112 ;
V_40 -> V_113 = V_138 -> V_62 ;
return F_42 ( V_40 , V_138 -> V_58 . V_146 - sizeof( * V_138 ) ,
V_6 -> V_28 , V_6 -> V_35 & V_29 ) ;
}
static int
F_43 ( struct V_107 * V_138 , struct V_144 * V_40 )
{
struct V_147 * V_112 ;
int V_12 ;
V_112 = F_44 ( V_141 , V_138 -> V_58 . V_131 . V_60 ,
V_138 -> V_58 . V_131 . V_148 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_138 -> V_58 . V_59 . V_112 = V_112 ;
V_12 = F_41 ( V_138 , V_40 ) ;
if ( V_12 )
goto V_149;
return 0 ;
V_149:
F_40 ( V_138 -> V_58 . V_59 . V_112 -> V_143 ) ;
return V_12 ;
}
static int F_47 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 )
{
struct V_49 * V_56 = F_12 ( V_46 ) ;
struct V_150 V_40 = {
. V_68 = V_68 ,
. V_88 = V_60 ,
. V_145 = V_46 ,
. V_57 = V_56 -> V_58 . V_59 . V_57 ,
. V_41 = V_56 -> V_62 ,
. V_151 = V_46 -> V_130 ,
. V_140 = V_141 ,
} ;
return F_48 ( & V_40 , V_56 -> V_58 . V_152 - sizeof( * V_56 ) ,
V_46 -> V_6 . V_28 , V_46 -> V_6 . V_35 & V_29 ) ;
}
static int
F_49 ( struct V_43 * V_46 , struct V_68 * V_68 , const char * V_60 ,
unsigned int V_133 ,
struct V_153 * V_154 )
{
struct V_49 * V_56 ;
struct V_155 * V_57 ;
int V_12 ;
unsigned int V_156 ;
struct V_144 V_157 ;
struct V_107 * V_108 ;
if ( ! F_50 ( V_154 , & V_46 -> V_114 ) )
return - V_158 ;
V_156 = 0 ;
V_157 . V_68 = V_68 ;
V_157 . V_88 = V_60 ;
V_157 . V_145 = & V_46 -> V_6 ;
V_157 . V_151 = V_46 -> V_130 ;
V_157 . V_140 = V_141 ;
F_30 (ematch, e) {
V_12 = F_43 ( V_108 , & V_157 ) ;
if ( V_12 != 0 )
goto V_159;
++ V_156 ;
}
V_56 = F_12 ( V_46 ) ;
V_57 = F_51 ( V_141 , V_56 -> V_58 . V_131 . V_60 ,
V_56 -> V_58 . V_131 . V_148 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_159;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_12 = F_47 ( V_46 , V_68 , V_60 ) ;
if ( V_12 )
goto V_149;
return 0 ;
V_149:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_143 ) ;
V_159:
F_30 (ematch, e) {
if ( V_156 -- == 0 )
break;
F_39 ( V_108 , V_68 ) ;
}
F_52 ( & V_46 -> V_114 ) ;
return V_12 ;
}
static bool F_53 ( const struct V_43 * V_46 )
{
const struct V_49 * V_56 ;
unsigned int V_64 ;
if ( ! F_10 ( V_46 ) )
return false ;
V_56 = F_11 ( V_46 ) ;
if ( strcmp ( V_56 -> V_58 . V_131 . V_60 , V_63 ) != 0 )
return false ;
V_64 = ( (struct V_55 * ) V_56 ) -> V_64 ;
V_64 = - V_64 - 1 ;
return V_64 == V_42 || V_64 == V_160 ;
}
static int
F_54 ( struct V_43 * V_46 ,
struct V_74 * V_123 ,
const unsigned char * V_44 ,
const unsigned char * V_161 ,
const unsigned int * V_162 ,
const unsigned int * V_163 ,
unsigned int V_103 )
{
unsigned int V_164 ;
int V_149 ;
if ( ( unsigned long ) V_46 % F_55 ( struct V_43 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_43 ) >= V_161 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_161 )
return - V_165 ;
if ( V_46 -> V_85
< sizeof( struct V_43 ) + sizeof( struct V_49 ) )
return - V_165 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_165 ;
V_149 = F_56 ( V_46 , V_46 -> V_166 , V_46 -> V_48 ,
V_46 -> V_85 ) ;
if ( V_149 )
return V_149 ;
for ( V_164 = 0 ; V_164 < V_126 ; V_164 ++ ) {
if ( ! ( V_103 & ( 1 << V_164 ) ) )
continue;
if ( ( unsigned char * ) V_46 - V_44 == V_162 [ V_164 ] )
V_123 -> V_79 [ V_164 ] = V_162 [ V_164 ] ;
if ( ( unsigned char * ) V_46 - V_44 == V_163 [ V_164 ] ) {
if ( ! F_53 ( V_46 ) )
return - V_165 ;
V_123 -> V_120 [ V_164 ] = V_163 [ V_164 ] ;
}
}
V_46 -> V_114 = ( (struct V_109 ) { 0 , 0 } ) ;
V_46 -> V_130 = 0 ;
return 0 ;
}
static void
F_57 ( struct V_43 * V_46 , struct V_68 * V_68 )
{
struct V_167 V_40 ;
struct V_49 * V_56 ;
struct V_107 * V_108 ;
F_30 (ematch, e)
F_39 ( V_108 , V_68 ) ;
V_56 = F_12 ( V_46 ) ;
V_40 . V_68 = V_68 ;
V_40 . V_57 = V_56 -> V_58 . V_59 . V_57 ;
V_40 . V_41 = V_56 -> V_62 ;
V_40 . V_140 = V_141 ;
if ( V_40 . V_57 -> V_142 != NULL )
V_40 . V_57 -> V_142 ( & V_40 ) ;
F_40 ( V_40 . V_57 -> V_143 ) ;
F_52 ( & V_46 -> V_114 ) ;
}
static int
F_58 ( struct V_68 * V_68 , struct V_74 * V_123 , void * V_124 ,
const struct V_168 * V_169 )
{
struct V_153 V_154 = { 0 } ;
struct V_43 * V_77 ;
unsigned int * V_125 ;
unsigned int V_170 ;
int V_12 = 0 ;
V_123 -> V_133 = V_169 -> V_133 ;
V_123 -> V_137 = V_169 -> V_171 ;
for ( V_170 = 0 ; V_170 < V_126 ; V_170 ++ ) {
V_123 -> V_79 [ V_170 ] = 0xFFFFFFFF ;
V_123 -> V_120 [ V_170 ] = 0xFFFFFFFF ;
}
V_125 = F_59 ( V_123 -> V_137 ) ;
if ( ! V_125 )
return - V_158 ;
V_170 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_54 ( V_77 , V_123 , V_124 ,
V_124 + V_169 -> V_133 ,
V_169 -> V_79 ,
V_169 -> V_120 ,
V_169 -> V_103 ) ;
if ( V_12 != 0 )
goto V_172;
if ( V_170 < V_169 -> V_171 )
V_125 [ V_170 ] = ( void * ) V_77 - V_124 ;
++ V_170 ;
if ( strcmp ( F_12 ( V_77 ) -> V_58 . V_131 . V_60 ,
V_61 ) == 0 )
++ V_123 -> V_105 ;
}
V_12 = - V_165 ;
if ( V_170 != V_169 -> V_171 )
goto V_172;
for ( V_170 = 0 ; V_170 < V_126 ; V_170 ++ ) {
if ( ! ( V_169 -> V_103 & ( 1 << V_170 ) ) )
continue;
if ( V_123 -> V_79 [ V_170 ] == 0xFFFFFFFF )
goto V_172;
if ( V_123 -> V_120 [ V_170 ] == 0xFFFFFFFF )
goto V_172;
}
if ( ! F_37 ( V_123 , V_169 -> V_103 , V_124 , V_125 ) ) {
V_12 = - V_173 ;
goto V_172;
}
F_60 ( V_125 ) ;
V_170 = 0 ;
F_15 (iter, entry0, newinfo->size) {
V_12 = F_49 ( V_77 , V_68 , V_169 -> V_60 , V_169 -> V_133 ,
& V_154 ) ;
if ( V_12 != 0 )
break;
++ V_170 ;
}
if ( V_12 != 0 ) {
F_15 (iter, entry0, newinfo->size) {
if ( V_170 -- == 0 )
break;
F_57 ( V_77 , V_68 ) ;
}
return V_12 ;
}
return V_12 ;
V_172:
F_60 ( V_125 ) ;
return V_12 ;
}
static void
F_61 ( const struct V_74 * V_56 ,
struct V_109 V_114 [] )
{
struct V_43 * V_77 ;
unsigned int V_95 ;
unsigned int V_170 ;
F_62 (cpu) {
T_1 * V_50 = & F_63 ( V_174 , V_95 ) ;
V_170 = 0 ;
F_15 (iter, t->entries, t->size) {
struct V_109 * V_175 ;
T_2 V_176 , V_128 ;
unsigned int V_177 ;
V_175 = F_64 ( & V_77 -> V_114 , V_95 ) ;
do {
V_177 = F_65 ( V_50 ) ;
V_176 = V_175 -> V_176 ;
V_128 = V_175 -> V_128 ;
} while ( F_66 ( V_50 , V_177 ) );
F_32 ( V_114 [ V_170 ] , V_176 , V_128 ) ;
++ V_170 ;
F_67 () ;
}
}
}
static struct V_109 * F_68 ( const struct V_1 * V_88 )
{
unsigned int V_178 ;
struct V_109 * V_114 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
V_178 = sizeof( struct V_109 ) * V_75 -> V_137 ;
V_114 = F_69 ( V_178 ) ;
if ( V_114 == NULL )
return F_70 ( - V_158 ) ;
F_61 ( V_75 , V_114 ) ;
return V_114 ;
}
static int
F_71 ( unsigned int V_179 ,
const struct V_1 * V_88 ,
void T_3 * V_180 )
{
unsigned int V_181 , V_182 ;
const struct V_43 * V_46 ;
struct V_109 * V_114 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
int V_12 = 0 ;
const void * V_183 ;
V_114 = F_68 ( V_88 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_183 = V_75 -> V_78 ;
for ( V_181 = 0 , V_182 = 0 ; V_181 < V_179 ; V_181 += V_46 -> V_85 , V_182 ++ ) {
unsigned int V_170 ;
const struct V_107 * V_138 ;
const struct V_49 * V_56 ;
V_46 = V_183 + V_181 ;
if ( F_72 ( V_180 + V_181 , V_46 , sizeof( * V_46 ) ) ) {
V_12 = - V_184 ;
goto V_185;
}
if ( F_72 ( V_180 + V_181
+ F_73 ( struct V_43 , V_114 ) ,
& V_114 [ V_182 ] ,
sizeof( V_114 [ V_182 ] ) ) != 0 ) {
V_12 = - V_184 ;
goto V_185;
}
for ( V_170 = sizeof( struct V_43 ) ;
V_170 < V_46 -> V_48 ;
V_170 += V_138 -> V_58 . V_146 ) {
V_138 = ( void * ) V_46 + V_170 ;
if ( F_74 ( V_138 , V_180 + V_181 + V_170 ) ) {
V_12 = - V_184 ;
goto V_185;
}
}
V_56 = F_11 ( V_46 ) ;
if ( F_75 ( V_56 , V_180 + V_181 + V_46 -> V_48 ) ) {
V_12 = - V_184 ;
goto V_185;
}
}
V_185:
F_76 ( V_114 ) ;
return V_12 ;
}
static void F_77 ( void * V_21 , const void * V_17 )
{
int V_118 = * ( V_186 * ) V_17 ;
if ( V_118 > 0 )
V_118 += F_78 ( V_82 , V_118 ) ;
memcpy ( V_21 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_79 ( void T_3 * V_21 , const void * V_17 )
{
V_186 V_187 = * ( int * ) V_17 ;
if ( V_187 > 0 )
V_187 -= F_78 ( V_82 , V_187 ) ;
return F_72 ( V_21 , & V_187 , sizeof( V_187 ) ) ? - V_184 : 0 ;
}
static int F_80 ( const struct V_43 * V_46 ,
const struct V_74 * V_2 ,
const void * V_44 , struct V_74 * V_123 )
{
const struct V_107 * V_108 ;
const struct V_49 * V_56 ;
unsigned int V_188 ;
int V_181 , V_170 , V_12 ;
V_181 = sizeof( struct V_43 ) - sizeof( struct V_189 ) ;
V_188 = ( void * ) V_46 - V_44 ;
F_30 (ematch, e)
V_181 += F_81 ( V_108 -> V_58 . V_59 . V_112 ) ;
V_56 = F_11 ( V_46 ) ;
V_181 += F_82 ( V_56 -> V_58 . V_59 . V_57 ) ;
V_123 -> V_133 -= V_181 ;
V_12 = F_83 ( V_82 , V_188 , V_181 ) ;
if ( V_12 )
return V_12 ;
for ( V_170 = 0 ; V_170 < V_126 ; V_170 ++ ) {
if ( V_2 -> V_79 [ V_170 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_79 [ V_170 ] ) ) )
V_123 -> V_79 [ V_170 ] -= V_181 ;
if ( V_2 -> V_120 [ V_170 ] &&
( V_46 < (struct V_43 * ) ( V_44 + V_2 -> V_120 [ V_170 ] ) ) )
V_123 -> V_120 [ V_170 ] -= V_181 ;
}
return 0 ;
}
static int F_84 ( const struct V_74 * V_2 ,
struct V_74 * V_123 )
{
struct V_43 * V_77 ;
const void * V_183 ;
int V_12 ;
if ( ! V_123 || ! V_2 )
return - V_165 ;
memcpy ( V_123 , V_2 , F_73 ( struct V_74 , V_78 ) ) ;
V_123 -> V_190 = 0 ;
V_183 = V_2 -> V_78 ;
F_85 ( V_82 , V_2 -> V_137 ) ;
F_15 (iter, loc_cpu_entry, info->size) {
V_12 = F_80 ( V_77 , V_2 , V_183 , V_123 ) ;
if ( V_12 != 0 )
return V_12 ;
}
return 0 ;
}
static int F_86 ( struct V_68 * V_68 , void T_3 * V_131 ,
const int * V_115 , int V_191 )
{
char V_60 [ V_192 ] ;
struct V_1 * V_56 ;
int V_12 ;
if ( * V_115 != sizeof( struct V_193 ) )
return - V_165 ;
if ( F_87 ( V_60 , V_131 , sizeof( V_60 ) ) != 0 )
return - V_184 ;
V_60 [ V_192 - 1 ] = '\0' ;
#ifdef F_88
if ( V_191 )
F_89 ( V_82 ) ;
#endif
V_56 = F_90 ( F_91 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( V_56 ) {
struct V_193 V_2 ;
const struct V_74 * V_75 = V_56 -> V_75 ;
#ifdef F_88
struct V_74 V_175 ;
if ( V_191 ) {
V_12 = F_84 ( V_75 , & V_175 ) ;
F_92 ( V_82 ) ;
V_75 = & V_175 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_103 = V_56 -> V_103 ;
memcpy ( V_2 . V_79 , V_75 -> V_79 ,
sizeof( V_2 . V_79 ) ) ;
memcpy ( V_2 . V_120 , V_75 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_171 = V_75 -> V_137 ;
V_2 . V_133 = V_75 -> V_133 ;
strcpy ( V_2 . V_60 , V_60 ) ;
if ( F_72 ( V_131 , & V_2 , * V_115 ) != 0 )
V_12 = - V_184 ;
else
V_12 = 0 ;
F_93 ( V_56 ) ;
F_40 ( V_56 -> V_143 ) ;
} else
V_12 = - V_194 ;
#ifdef F_88
if ( V_191 )
F_94 ( V_82 ) ;
#endif
return V_12 ;
}
static int
F_95 ( struct V_68 * V_68 , struct V_195 T_3 * V_196 ,
const int * V_115 )
{
int V_12 ;
struct V_195 V_197 ;
struct V_1 * V_56 ;
if ( * V_115 < sizeof( V_197 ) )
return - V_165 ;
if ( F_87 ( & V_197 , V_196 , sizeof( V_197 ) ) != 0 )
return - V_184 ;
if ( * V_115 != sizeof( struct V_195 ) + V_197 . V_133 )
return - V_165 ;
V_197 . V_60 [ sizeof( V_197 . V_60 ) - 1 ] = '\0' ;
V_56 = F_91 ( V_68 , V_82 , V_197 . V_60 ) ;
if ( V_56 ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
if ( V_197 . V_133 == V_75 -> V_133 )
V_12 = F_71 ( V_75 -> V_133 ,
V_56 , V_196 -> V_198 ) ;
else
V_12 = - V_199 ;
F_40 ( V_56 -> V_143 ) ;
F_93 ( V_56 ) ;
} else
V_12 = - V_194 ;
return V_12 ;
}
static int
F_96 ( struct V_68 * V_68 , const char * V_60 , unsigned int V_103 ,
struct V_74 * V_123 , unsigned int V_200 ,
void T_3 * V_201 )
{
int V_12 ;
struct V_1 * V_56 ;
struct V_74 * V_202 ;
struct V_109 * V_114 ;
struct V_43 * V_77 ;
V_12 = 0 ;
V_114 = F_69 ( V_200 * sizeof( struct V_109 ) ) ;
if ( ! V_114 ) {
V_12 = - V_158 ;
goto V_72;
}
V_56 = F_90 ( F_91 ( V_68 , V_82 , V_60 ) ,
L_3 , V_60 ) ;
if ( ! V_56 ) {
V_12 = - V_194 ;
goto V_203;
}
if ( V_103 != V_56 -> V_103 ) {
V_12 = - V_165 ;
goto V_204;
}
V_202 = F_97 ( V_56 , V_200 , V_123 , & V_12 ) ;
if ( ! V_202 )
goto V_204;
if ( ( V_202 -> V_137 > V_202 -> V_190 ) ||
( V_123 -> V_137 <= V_202 -> V_190 ) )
F_40 ( V_56 -> V_143 ) ;
if ( ( V_202 -> V_137 > V_202 -> V_190 ) &&
( V_123 -> V_137 <= V_202 -> V_190 ) )
F_40 ( V_56 -> V_143 ) ;
F_61 ( V_202 , V_114 ) ;
F_15 (iter, oldinfo->entries, oldinfo->size)
F_57 ( V_77 , V_68 ) ;
F_98 ( V_202 ) ;
if ( F_72 ( V_201 , V_114 ,
sizeof( struct V_109 ) * V_200 ) != 0 ) {
F_99 ( L_4 ) ;
}
F_76 ( V_114 ) ;
F_93 ( V_56 ) ;
return V_12 ;
V_204:
F_40 ( V_56 -> V_143 ) ;
F_93 ( V_56 ) ;
V_203:
F_76 ( V_114 ) ;
V_72:
return V_12 ;
}
static int
F_100 ( struct V_68 * V_68 , const void T_3 * V_131 , unsigned int V_115 )
{
int V_12 ;
struct V_168 V_175 ;
struct V_74 * V_123 ;
void * V_183 ;
struct V_43 * V_77 ;
if ( F_87 ( & V_175 , V_131 , sizeof( V_175 ) ) != 0 )
return - V_184 ;
if ( V_175 . V_200 >= V_205 / sizeof( struct V_109 ) )
return - V_158 ;
if ( V_175 . V_200 == 0 )
return - V_165 ;
V_175 . V_60 [ sizeof( V_175 . V_60 ) - 1 ] = 0 ;
V_123 = F_101 ( V_175 . V_133 ) ;
if ( ! V_123 )
return - V_158 ;
V_183 = V_123 -> V_78 ;
if ( F_87 ( V_183 , V_131 + sizeof( V_175 ) ,
V_175 . V_133 ) != 0 ) {
V_12 = - V_184 ;
goto V_206;
}
V_12 = F_58 ( V_68 , V_123 , V_183 , & V_175 ) ;
if ( V_12 != 0 )
goto V_206;
V_12 = F_96 ( V_68 , V_175 . V_60 , V_175 . V_103 , V_123 ,
V_175 . V_200 , V_175 . V_114 ) ;
if ( V_12 )
goto V_207;
return 0 ;
V_207:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_77 , V_68 ) ;
V_206:
F_98 ( V_123 ) ;
return V_12 ;
}
static int
F_102 ( struct V_68 * V_68 , const void T_3 * V_131 ,
unsigned int V_115 , int V_191 )
{
unsigned int V_170 ;
struct V_208 V_175 ;
struct V_109 * V_209 ;
struct V_1 * V_56 ;
const struct V_74 * V_75 ;
int V_12 = 0 ;
struct V_43 * V_77 ;
unsigned int V_97 ;
V_209 = F_103 ( V_131 , V_115 , & V_175 , V_191 ) ;
if ( F_45 ( V_209 ) )
return F_46 ( V_209 ) ;
V_56 = F_91 ( V_68 , V_82 , V_175 . V_60 ) ;
if ( ! V_56 ) {
V_12 = - V_194 ;
goto free;
}
F_24 () ;
V_75 = V_56 -> V_75 ;
if ( V_75 -> V_137 != V_175 . V_200 ) {
V_12 = - V_165 ;
goto V_210;
}
V_170 = 0 ;
V_97 = F_25 () ;
F_15 (iter, private->entries, private->size) {
struct V_109 * V_175 ;
V_175 = F_31 ( & V_77 -> V_114 ) ;
F_32 ( * V_175 , V_209 [ V_170 ] . V_176 , V_209 [ V_170 ] . V_128 ) ;
++ V_170 ;
}
F_35 ( V_97 ) ;
V_210:
F_36 () ;
F_93 ( V_56 ) ;
F_40 ( V_56 -> V_143 ) ;
free:
F_76 ( V_209 ) ;
return V_12 ;
}
static int
F_104 ( struct V_43 * V_46 , void T_3 * * V_211 ,
unsigned int * V_133 , struct V_109 * V_114 ,
unsigned int V_170 )
{
struct V_49 * V_56 ;
struct V_189 T_3 * V_212 ;
T_4 V_48 , V_85 ;
T_5 V_213 ;
const struct V_107 * V_108 ;
int V_12 = 0 ;
V_213 = * V_133 ;
V_212 = * V_211 ;
if ( F_72 ( V_212 , V_46 , sizeof( struct V_43 ) ) != 0 ||
F_72 ( & V_212 -> V_114 , & V_114 [ V_170 ] ,
sizeof( V_114 [ V_170 ] ) ) != 0 )
return - V_184 ;
* V_211 += sizeof( struct V_189 ) ;
* V_133 -= sizeof( struct V_43 ) - sizeof( struct V_189 ) ;
F_30 (ematch, e) {
V_12 = F_105 ( V_108 , V_211 , V_133 ) ;
if ( V_12 != 0 )
return V_12 ;
}
V_48 = V_46 -> V_48 - ( V_213 - * V_133 ) ;
V_56 = F_12 ( V_46 ) ;
V_12 = F_106 ( V_56 , V_211 , V_133 ) ;
if ( V_12 )
return V_12 ;
V_85 = V_46 -> V_85 - ( V_213 - * V_133 ) ;
if ( F_107 ( V_48 , & V_212 -> V_48 ) != 0 ||
F_107 ( V_85 , & V_212 -> V_85 ) != 0 )
return - V_184 ;
return 0 ;
}
static int
F_108 ( struct V_107 * V_138 ,
const struct V_9 * V_6 ,
int * V_133 )
{
struct V_147 * V_112 ;
V_112 = F_44 ( V_141 , V_138 -> V_58 . V_131 . V_60 ,
V_138 -> V_58 . V_131 . V_148 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_138 -> V_58 . V_59 . V_112 = V_112 ;
* V_133 += F_81 ( V_112 ) ;
return 0 ;
}
static void F_109 ( struct V_189 * V_46 )
{
struct V_49 * V_56 ;
struct V_107 * V_108 ;
F_30 (ematch, e)
F_40 ( V_108 -> V_58 . V_59 . V_112 -> V_143 ) ;
V_56 = F_110 ( V_46 ) ;
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_143 ) ;
}
static int
F_111 ( struct V_189 * V_46 ,
struct V_74 * V_123 ,
unsigned int * V_133 ,
const unsigned char * V_44 ,
const unsigned char * V_161 )
{
struct V_107 * V_108 ;
struct V_49 * V_56 ;
struct V_155 * V_57 ;
unsigned int V_188 ;
unsigned int V_156 ;
int V_12 , V_181 ;
if ( ( unsigned long ) V_46 % F_55 ( struct V_189 ) != 0 ||
( unsigned char * ) V_46 + sizeof( struct V_189 ) >= V_161 ||
( unsigned char * ) V_46 + V_46 -> V_85 > V_161 )
return - V_165 ;
if ( V_46 -> V_85 < sizeof( struct V_189 ) +
sizeof( struct V_214 ) )
return - V_165 ;
if ( ! F_6 ( & V_46 -> V_6 ) )
return - V_165 ;
V_12 = F_112 ( V_46 , V_46 -> V_166 ,
V_46 -> V_48 , V_46 -> V_85 ) ;
if ( V_12 )
return V_12 ;
V_181 = sizeof( struct V_43 ) - sizeof( struct V_189 ) ;
V_188 = ( void * ) V_46 - ( void * ) V_44 ;
V_156 = 0 ;
F_30 (ematch, e) {
V_12 = F_108 ( V_108 , & V_46 -> V_6 , & V_181 ) ;
if ( V_12 != 0 )
goto V_215;
++ V_156 ;
}
V_56 = F_110 ( V_46 ) ;
V_57 = F_51 ( V_141 , V_56 -> V_58 . V_131 . V_60 ,
V_56 -> V_58 . V_131 . V_148 ) ;
if ( F_45 ( V_57 ) ) {
V_12 = F_46 ( V_57 ) ;
goto V_215;
}
V_56 -> V_58 . V_59 . V_57 = V_57 ;
V_181 += F_82 ( V_57 ) ;
* V_133 += V_181 ;
V_12 = F_83 ( V_82 , V_188 , V_181 ) ;
if ( V_12 )
goto V_72;
return 0 ;
V_72:
F_40 ( V_56 -> V_58 . V_59 . V_57 -> V_143 ) ;
V_215:
F_30 (ematch, e) {
if ( V_156 -- == 0 )
break;
F_40 ( V_108 -> V_58 . V_59 . V_112 -> V_143 ) ;
}
return V_12 ;
}
static void
F_113 ( struct V_189 * V_46 , void * * V_211 ,
unsigned int * V_133 ,
struct V_74 * V_123 , unsigned char * V_44 )
{
struct V_49 * V_56 ;
struct V_43 * V_216 ;
unsigned int V_213 ;
int V_164 ;
struct V_107 * V_108 ;
V_213 = * V_133 ;
V_216 = * V_211 ;
memcpy ( V_216 , V_46 , sizeof( struct V_43 ) ) ;
memcpy ( & V_216 -> V_114 , & V_46 -> V_114 , sizeof( V_46 -> V_114 ) ) ;
* V_211 += sizeof( struct V_43 ) ;
* V_133 += sizeof( struct V_43 ) - sizeof( struct V_189 ) ;
F_30 (ematch, e)
F_114 ( V_108 , V_211 , V_133 ) ;
V_216 -> V_48 = V_46 -> V_48 - ( V_213 - * V_133 ) ;
V_56 = F_110 ( V_46 ) ;
F_115 ( V_56 , V_211 , V_133 ) ;
V_216 -> V_85 = V_46 -> V_85 - ( V_213 - * V_133 ) ;
for ( V_164 = 0 ; V_164 < V_126 ; V_164 ++ ) {
if ( ( unsigned char * ) V_216 - V_44 < V_123 -> V_79 [ V_164 ] )
V_123 -> V_79 [ V_164 ] -= V_213 - * V_133 ;
if ( ( unsigned char * ) V_216 - V_44 < V_123 -> V_120 [ V_164 ] )
V_123 -> V_120 [ V_164 ] -= V_213 - * V_133 ;
}
}
static int
F_116 ( struct V_68 * V_68 ,
struct V_74 * * V_217 ,
void * * V_218 ,
const struct V_219 * V_220 )
{
unsigned int V_170 , V_156 ;
struct V_74 * V_123 , * V_2 ;
void * V_127 , * V_124 , * V_221 ;
struct V_189 * V_222 ;
struct V_168 V_169 ;
unsigned int V_133 ;
int V_12 ;
V_2 = * V_217 ;
V_124 = * V_218 ;
V_133 = V_220 -> V_133 ;
V_2 -> V_137 = V_220 -> V_171 ;
V_156 = 0 ;
F_89 ( V_82 ) ;
F_85 ( V_82 , V_220 -> V_171 ) ;
F_15 (iter0, entry0, compatr->size) {
V_12 = F_111 ( V_222 , V_2 , & V_133 ,
V_124 ,
V_124 + V_220 -> V_133 ) ;
if ( V_12 != 0 )
goto V_223;
++ V_156 ;
}
V_12 = - V_165 ;
if ( V_156 != V_220 -> V_171 )
goto V_223;
V_12 = - V_158 ;
V_123 = F_101 ( V_133 ) ;
if ( ! V_123 )
goto V_223;
V_123 -> V_137 = V_220 -> V_171 ;
for ( V_170 = 0 ; V_170 < V_126 ; V_170 ++ ) {
V_123 -> V_79 [ V_170 ] = V_220 -> V_79 [ V_170 ] ;
V_123 -> V_120 [ V_170 ] = V_220 -> V_120 [ V_170 ] ;
}
V_221 = V_123 -> V_78 ;
V_127 = V_221 ;
V_133 = V_220 -> V_133 ;
F_15 (iter0, entry0, compatr->size)
F_113 ( V_222 , & V_127 , & V_133 ,
V_123 , V_221 ) ;
F_92 ( V_82 ) ;
F_94 ( V_82 ) ;
memcpy ( & V_169 , V_220 , sizeof( * V_220 ) ) ;
for ( V_170 = 0 ; V_170 < V_126 ; V_170 ++ ) {
V_169 . V_79 [ V_170 ] = V_123 -> V_79 [ V_170 ] ;
V_169 . V_120 [ V_170 ] = V_123 -> V_120 [ V_170 ] ;
}
V_169 . V_200 = 0 ;
V_169 . V_114 = NULL ;
V_169 . V_133 = V_123 -> V_133 ;
V_12 = F_58 ( V_68 , V_123 , V_221 , & V_169 ) ;
if ( V_12 )
goto V_206;
* V_217 = V_123 ;
* V_218 = V_221 ;
F_98 ( V_2 ) ;
return 0 ;
V_206:
F_98 ( V_123 ) ;
return V_12 ;
V_223:
F_92 ( V_82 ) ;
F_94 ( V_82 ) ;
F_15 (iter0, entry0, compatr->size) {
if ( V_156 -- == 0 )
break;
F_109 ( V_222 ) ;
}
return V_12 ;
}
static int
F_117 ( struct V_68 * V_68 , void T_3 * V_131 , unsigned int V_115 )
{
int V_12 ;
struct V_219 V_175 ;
struct V_74 * V_123 ;
void * V_183 ;
struct V_43 * V_77 ;
if ( F_87 ( & V_175 , V_131 , sizeof( V_175 ) ) != 0 )
return - V_184 ;
if ( V_175 . V_200 >= V_205 / sizeof( struct V_109 ) )
return - V_158 ;
if ( V_175 . V_200 == 0 )
return - V_165 ;
V_175 . V_60 [ sizeof( V_175 . V_60 ) - 1 ] = 0 ;
V_123 = F_101 ( V_175 . V_133 ) ;
if ( ! V_123 )
return - V_158 ;
V_183 = V_123 -> V_78 ;
if ( F_87 ( V_183 , V_131 + sizeof( V_175 ) ,
V_175 . V_133 ) != 0 ) {
V_12 = - V_184 ;
goto V_206;
}
V_12 = F_116 ( V_68 , & V_123 , & V_183 , & V_175 ) ;
if ( V_12 != 0 )
goto V_206;
V_12 = F_96 ( V_68 , V_175 . V_60 , V_175 . V_103 , V_123 ,
V_175 . V_200 , F_118 ( V_175 . V_114 ) ) ;
if ( V_12 )
goto V_207;
return 0 ;
V_207:
F_15 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_77 , V_68 ) ;
V_206:
F_98 ( V_123 ) ;
return V_12 ;
}
static int
F_119 ( struct V_224 * V_225 , int V_226 , void T_3 * V_131 ,
unsigned int V_115 )
{
int V_12 ;
if ( ! F_120 ( F_121 ( V_225 ) -> V_227 , V_228 ) )
return - V_229 ;
switch ( V_226 ) {
case V_230 :
V_12 = F_117 ( F_121 ( V_225 ) , V_131 , V_115 ) ;
break;
case V_231 :
V_12 = F_102 ( F_121 ( V_225 ) , V_131 , V_115 , 1 ) ;
break;
default:
V_12 = - V_165 ;
}
return V_12 ;
}
static int
F_122 ( unsigned int V_179 , struct V_1 * V_88 ,
void T_3 * V_180 )
{
struct V_109 * V_114 ;
const struct V_74 * V_75 = V_88 -> V_75 ;
void T_3 * V_127 ;
unsigned int V_133 ;
int V_12 = 0 ;
unsigned int V_170 = 0 ;
struct V_43 * V_77 ;
V_114 = F_68 ( V_88 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_127 = V_180 ;
V_133 = V_179 ;
F_15 (iter, private->entries, total_size) {
V_12 = F_104 ( V_77 , & V_127 ,
& V_133 , V_114 , V_170 ++ ) ;
if ( V_12 != 0 )
break;
}
F_76 ( V_114 ) ;
return V_12 ;
}
static int
F_123 ( struct V_68 * V_68 , struct V_232 T_3 * V_196 ,
int * V_115 )
{
int V_12 ;
struct V_232 V_197 ;
struct V_1 * V_56 ;
if ( * V_115 < sizeof( V_197 ) )
return - V_165 ;
if ( F_87 ( & V_197 , V_196 , sizeof( V_197 ) ) != 0 )
return - V_184 ;
if ( * V_115 != sizeof( struct V_232 ) + V_197 . V_133 )
return - V_165 ;
V_197 . V_60 [ sizeof( V_197 . V_60 ) - 1 ] = '\0' ;
F_89 ( V_82 ) ;
V_56 = F_91 ( V_68 , V_82 , V_197 . V_60 ) ;
if ( V_56 ) {
const struct V_74 * V_75 = V_56 -> V_75 ;
struct V_74 V_2 ;
V_12 = F_84 ( V_75 , & V_2 ) ;
if ( ! V_12 && V_197 . V_133 == V_2 . V_133 )
V_12 = F_122 ( V_75 -> V_133 ,
V_56 , V_196 -> V_198 ) ;
else if ( ! V_12 )
V_12 = - V_199 ;
F_92 ( V_82 ) ;
F_40 ( V_56 -> V_143 ) ;
F_93 ( V_56 ) ;
} else
V_12 = - V_194 ;
F_94 ( V_82 ) ;
return V_12 ;
}
static int
F_124 ( struct V_224 * V_225 , int V_226 , void T_3 * V_131 , int * V_115 )
{
int V_12 ;
if ( ! F_120 ( F_121 ( V_225 ) -> V_227 , V_228 ) )
return - V_229 ;
switch ( V_226 ) {
case V_233 :
V_12 = F_86 ( F_121 ( V_225 ) , V_131 , V_115 , 1 ) ;
break;
case V_234 :
V_12 = F_123 ( F_121 ( V_225 ) , V_131 , V_115 ) ;
break;
default:
V_12 = F_125 ( V_225 , V_226 , V_131 , V_115 ) ;
}
return V_12 ;
}
static int
F_126 ( struct V_224 * V_225 , int V_226 , void T_3 * V_131 , unsigned int V_115 )
{
int V_12 ;
if ( ! F_120 ( F_121 ( V_225 ) -> V_227 , V_228 ) )
return - V_229 ;
switch ( V_226 ) {
case V_230 :
V_12 = F_100 ( F_121 ( V_225 ) , V_131 , V_115 ) ;
break;
case V_231 :
V_12 = F_102 ( F_121 ( V_225 ) , V_131 , V_115 , 0 ) ;
break;
default:
V_12 = - V_165 ;
}
return V_12 ;
}
static int
F_125 ( struct V_224 * V_225 , int V_226 , void T_3 * V_131 , int * V_115 )
{
int V_12 ;
if ( ! F_120 ( F_121 ( V_225 ) -> V_227 , V_228 ) )
return - V_229 ;
switch ( V_226 ) {
case V_233 :
V_12 = F_86 ( F_121 ( V_225 ) , V_131 , V_115 , 0 ) ;
break;
case V_234 :
V_12 = F_95 ( F_121 ( V_225 ) , V_131 , V_115 ) ;
break;
case V_235 :
case V_236 : {
struct V_237 V_238 ;
int V_57 ;
if ( * V_115 != sizeof( V_238 ) ) {
V_12 = - V_165 ;
break;
}
if ( F_87 ( & V_238 , V_131 , sizeof( V_238 ) ) != 0 ) {
V_12 = - V_184 ;
break;
}
V_238 . V_60 [ sizeof( V_238 . V_60 ) - 1 ] = 0 ;
if ( V_226 == V_236 )
V_57 = 1 ;
else
V_57 = 0 ;
F_90 ( F_127 ( V_82 , V_238 . V_60 ,
V_238 . V_148 ,
V_57 , & V_12 ) ,
L_5 , V_238 . V_60 ) ;
break;
}
default:
V_12 = - V_165 ;
}
return V_12 ;
}
static void F_128 ( struct V_68 * V_68 , struct V_1 * V_88 )
{
struct V_74 * V_75 ;
void * V_183 ;
struct V_239 * V_240 = V_88 -> V_143 ;
struct V_43 * V_77 ;
V_75 = F_129 ( V_88 ) ;
V_183 = V_75 -> V_78 ;
F_15 (iter, loc_cpu_entry, private->size)
F_57 ( V_77 , V_68 ) ;
if ( V_75 -> V_137 > V_75 -> V_190 )
F_40 ( V_240 ) ;
F_98 ( V_75 ) ;
}
int F_130 ( struct V_68 * V_68 , const struct V_1 * V_88 ,
const struct V_168 * V_169 ,
const struct V_241 * V_242 , struct V_1 * * V_243 )
{
int V_12 ;
struct V_74 * V_123 ;
struct V_74 V_244 = { 0 } ;
void * V_183 ;
struct V_1 * V_245 ;
V_123 = F_101 ( V_169 -> V_133 ) ;
if ( ! V_123 )
return - V_158 ;
V_183 = V_123 -> V_78 ;
memcpy ( V_183 , V_169 -> V_78 , V_169 -> V_133 ) ;
V_12 = F_58 ( V_68 , V_123 , V_183 , V_169 ) ;
if ( V_12 != 0 )
goto V_172;
V_245 = F_131 ( V_68 , V_88 , & V_244 , V_123 ) ;
if ( F_45 ( V_245 ) ) {
V_12 = F_46 ( V_245 ) ;
goto V_172;
}
F_132 ( * V_243 , V_245 ) ;
V_12 = F_133 ( V_68 , V_242 , F_134 ( V_88 -> V_103 ) ) ;
if ( V_12 != 0 ) {
F_128 ( V_68 , V_245 ) ;
* V_243 = NULL ;
}
return V_12 ;
V_172:
F_98 ( V_123 ) ;
return V_12 ;
}
void F_135 ( struct V_68 * V_68 , struct V_1 * V_88 ,
const struct V_241 * V_242 )
{
F_136 ( V_68 , V_242 , F_134 ( V_88 -> V_103 ) ) ;
F_128 ( V_68 , V_88 ) ;
}
static inline bool
F_137 ( T_6 V_246 , T_6 V_247 , T_6 V_248 ,
T_6 type , T_6 V_249 ,
bool V_250 )
{
return ( ( V_246 == 0xFF ) ||
( type == V_246 && V_249 >= V_247 && V_249 <= V_248 ) )
^ V_250 ;
}
static bool
F_138 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
const struct V_251 * V_252 ;
struct V_251 V_253 ;
const struct V_254 * V_255 = V_40 -> V_113 ;
if ( V_40 -> V_98 != 0 )
return false ;
V_252 = F_139 ( V_38 , V_40 -> V_101 , sizeof( V_253 ) , & V_253 ) ;
if ( V_252 == NULL ) {
V_40 -> V_102 = true ;
return false ;
}
return F_137 ( V_255 -> type ,
V_255 -> V_249 [ 0 ] ,
V_255 -> V_249 [ 1 ] ,
V_252 -> type , V_252 -> V_249 ,
! ! ( V_255 -> V_35 & V_256 ) ) ;
}
static int F_140 ( const struct V_144 * V_40 )
{
const struct V_254 * V_255 = V_40 -> V_113 ;
return ( V_255 -> V_35 & ~ V_256 ) ? - V_165 : 0 ;
}
static int T_7 F_141 ( struct V_68 * V_68 )
{
return F_142 ( V_68 , V_141 ) ;
}
static void T_8 F_143 ( struct V_68 * V_68 )
{
F_144 ( V_68 , V_141 ) ;
}
static int T_9 F_145 ( void )
{
int V_12 ;
V_12 = F_146 ( & V_257 ) ;
if ( V_12 < 0 )
goto V_258;
V_12 = F_147 ( V_259 , F_148 ( V_259 ) ) ;
if ( V_12 < 0 )
goto V_260;
V_12 = F_149 ( V_261 , F_148 ( V_261 ) ) ;
if ( V_12 < 0 )
goto V_262;
V_12 = F_150 ( & V_263 ) ;
if ( V_12 < 0 )
goto V_264;
F_151 ( L_6 ) ;
return 0 ;
V_264:
F_152 ( V_261 , F_148 ( V_261 ) ) ;
V_262:
F_153 ( V_259 , F_148 ( V_259 ) ) ;
V_260:
F_154 ( & V_257 ) ;
V_258:
return V_12 ;
}
static void T_10 F_155 ( void )
{
F_156 ( & V_263 ) ;
F_152 ( V_261 , F_148 ( V_261 ) ) ;
F_153 ( V_259 , F_148 ( V_259 ) ) ;
F_154 ( & V_257 ) ;
}
