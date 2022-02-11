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
if ( F_5 ( V_10 , V_17 ,
F_6 ( & V_16 -> V_18 , & V_10 -> V_19 ,
& V_10 -> V_20 ) ) ||
F_5 ( V_10 , V_21 ,
F_6 ( & V_16 -> V_22 , & V_10 -> V_23 ,
& V_10 -> V_24 ) ) )
return false ;
V_14 = F_7 ( V_7 , V_10 -> V_25 , V_10 -> V_26 ) ;
if ( F_5 ( V_10 , V_27 , V_14 != 0 ) )
return false ;
V_14 = F_7 ( V_8 , V_10 -> V_28 , V_10 -> V_29 ) ;
if ( F_5 ( V_10 , V_30 , V_14 != 0 ) )
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
static int
F_37 ( const struct V_75 * V_123 ,
unsigned int V_102 , void * V_124 ,
unsigned int * V_125 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_126 ; V_70 ++ ) {
unsigned int V_127 = V_123 -> V_80 [ V_70 ] ;
struct V_44 * V_47 = (struct V_44 * ) ( V_124 + V_127 ) ;
if ( ! ( V_102 & ( 1 << V_70 ) ) )
continue;
V_47 -> V_114 . V_128 = V_127 ;
for (; ; ) {
const struct V_56 * V_57
= ( void * ) F_14 ( V_47 ) ;
int V_129 = V_47 -> V_130 & ( 1 << V_70 ) ;
if ( V_47 -> V_130 & ( 1 << V_126 ) )
return 0 ;
V_47 -> V_130 |= ( ( 1 << V_70 ) | ( 1 << V_126 ) ) ;
if ( ( F_13 ( V_47 ) &&
( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < 0 ) || V_129 ) {
unsigned int V_132 , V_133 ;
if ( ( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < - V_134 - 1 )
return 0 ;
do {
V_47 -> V_130 ^= ( 1 << V_126 ) ;
V_132 = V_127 ;
V_127 = V_47 -> V_114 . V_128 ;
V_47 -> V_114 . V_128 = 0 ;
if ( V_127 == V_132 )
goto V_135;
V_47 = (struct V_44 * )
( V_124 + V_127 ) ;
} while ( V_132 == V_127 + V_47 -> V_86 );
V_133 = V_47 -> V_86 ;
V_47 = (struct V_44 * )
( V_124 + V_127 + V_133 ) ;
if ( V_127 + V_133 >= V_123 -> V_133 )
return 0 ;
V_47 -> V_114 . V_128 = V_127 ;
V_127 += V_133 ;
} else {
int V_136 = V_57 -> V_65 ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_131 . V_61 ,
V_64 ) == 0 &&
V_136 >= 0 ) {
if ( ! F_38 ( V_125 , V_136 ,
V_123 -> V_137 ) )
return 0 ;
V_47 = (struct V_44 * )
( V_124 + V_136 ) ;
} else {
V_136 = V_127 + V_47 -> V_86 ;
if ( V_136 >= V_123 -> V_133 )
return 0 ;
}
V_47 = (struct V_44 * )
( V_124 + V_136 ) ;
V_47 -> V_114 . V_128 = V_127 ;
V_127 = V_136 ;
}
}
V_135: ;
}
return 1 ;
}
static void F_39 ( struct V_106 * V_138 , struct V_69 * V_69 )
{
struct V_139 V_41 ;
V_41 . V_69 = V_69 ;
V_41 . V_112 = V_138 -> V_59 . V_60 . V_112 ;
V_41 . V_113 = V_138 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_112 -> V_140 != NULL )
V_41 . V_112 -> V_140 ( & V_41 ) ;
F_40 ( V_41 . V_112 -> V_141 ) ;
}
static int F_41 ( struct V_106 * V_138 , struct V_142 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_143 ;
V_41 -> V_112 = V_138 -> V_59 . V_60 . V_112 ;
V_41 -> V_113 = V_138 -> V_63 ;
return F_42 ( V_41 , V_138 -> V_59 . V_144 - sizeof( * V_138 ) ,
V_16 -> V_35 , V_16 -> V_36 & V_37 ) ;
}
static int
F_43 ( struct V_106 * V_138 , struct V_142 * V_41 )
{
struct V_145 * V_112 ;
int V_14 ;
V_112 = F_44 ( V_100 , V_138 -> V_59 . V_131 . V_61 ,
V_138 -> V_59 . V_131 . V_146 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_138 -> V_59 . V_60 . V_112 = V_112 ;
V_14 = F_41 ( V_138 , V_41 ) ;
if ( V_14 )
goto V_147;
return 0 ;
V_147:
F_40 ( V_138 -> V_59 . V_60 . V_112 -> V_141 ) ;
return V_14 ;
}
static int F_47 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 )
{
struct V_50 * V_57 = F_15 ( V_47 ) ;
struct V_148 V_41 = {
. V_69 = V_69 ,
. V_89 = V_61 ,
. V_143 = V_47 ,
. V_58 = V_57 -> V_59 . V_60 . V_58 ,
. V_42 = V_57 -> V_63 ,
. V_149 = V_47 -> V_130 ,
. V_99 = V_100 ,
} ;
V_57 = F_15 ( V_47 ) ;
return F_48 ( & V_41 , V_57 -> V_59 . V_150 - sizeof( * V_57 ) ,
V_47 -> V_16 . V_35 ,
V_47 -> V_16 . V_36 & V_37 ) ;
}
static int
F_49 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 ,
unsigned int V_133 )
{
struct V_50 * V_57 ;
struct V_151 * V_58 ;
int V_14 ;
unsigned int V_152 ;
struct V_142 V_153 ;
struct V_106 * V_107 ;
unsigned long V_128 ;
V_128 = F_50 () ;
if ( F_51 ( V_128 ) )
return - V_154 ;
V_47 -> V_114 . V_128 = V_128 ;
V_152 = 0 ;
V_153 . V_69 = V_69 ;
V_153 . V_89 = V_61 ;
V_153 . V_143 = & V_47 -> V_16 ;
V_153 . V_149 = V_47 -> V_130 ;
V_153 . V_99 = V_100 ;
F_30 (ematch, e) {
V_14 = F_43 ( V_107 , & V_153 ) ;
if ( V_14 != 0 )
goto V_155;
++ V_152 ;
}
V_57 = F_15 ( V_47 ) ;
V_58 = F_52 ( V_100 , V_57 -> V_59 . V_131 . V_61 ,
V_57 -> V_59 . V_131 . V_146 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_155;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_14 = F_47 ( V_47 , V_69 , V_61 ) ;
if ( V_14 )
goto V_147;
return 0 ;
V_147:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_141 ) ;
V_155:
F_30 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_39 ( V_107 , V_69 ) ;
}
F_53 ( V_47 -> V_114 . V_128 ) ;
return V_14 ;
}
static bool F_54 ( const struct V_44 * V_47 )
{
const struct V_50 * V_57 ;
unsigned int V_65 ;
if ( ! F_13 ( V_47 ) )
return false ;
V_57 = F_14 ( V_47 ) ;
if ( strcmp ( V_57 -> V_59 . V_131 . V_61 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_56 * ) V_57 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_156 ;
}
static int
F_55 ( struct V_44 * V_47 ,
struct V_75 * V_123 ,
const unsigned char * V_45 ,
const unsigned char * V_157 ,
const unsigned int * V_158 ,
const unsigned int * V_159 ,
unsigned int V_102 )
{
unsigned int V_160 ;
int V_147 ;
if ( ( unsigned long ) V_47 % F_56 ( struct V_44 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_44 ) >= V_157 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_157 )
return - V_161 ;
if ( V_47 -> V_86
< sizeof( struct V_44 ) + sizeof( struct V_50 ) )
return - V_161 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_161 ;
V_147 = F_57 ( V_47 , V_47 -> V_162 , V_47 -> V_49 ,
V_47 -> V_86 ) ;
if ( V_147 )
return V_147 ;
for ( V_160 = 0 ; V_160 < V_126 ; V_160 ++ ) {
if ( ! ( V_102 & ( 1 << V_160 ) ) )
continue;
if ( ( unsigned char * ) V_47 - V_45 == V_158 [ V_160 ] )
V_123 -> V_80 [ V_160 ] = V_158 [ V_160 ] ;
if ( ( unsigned char * ) V_47 - V_45 == V_159 [ V_160 ] ) {
if ( ! F_54 ( V_47 ) )
return - V_161 ;
V_123 -> V_120 [ V_160 ] = V_159 [ V_160 ] ;
}
}
V_47 -> V_114 = ( (struct V_108 ) { 0 , 0 } ) ;
V_47 -> V_130 = 0 ;
return 0 ;
}
static void F_58 ( struct V_44 * V_47 , struct V_69 * V_69 )
{
struct V_163 V_41 ;
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_30 (ematch, e)
F_39 ( V_107 , V_69 ) ;
V_57 = F_15 ( V_47 ) ;
V_41 . V_69 = V_69 ;
V_41 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_41 . V_42 = V_57 -> V_63 ;
V_41 . V_99 = V_100 ;
if ( V_41 . V_58 -> V_140 != NULL )
V_41 . V_58 -> V_140 ( & V_41 ) ;
F_40 ( V_41 . V_58 -> V_141 ) ;
F_53 ( V_47 -> V_114 . V_128 ) ;
}
static int
F_59 ( struct V_69 * V_69 , struct V_75 * V_123 , void * V_124 ,
const struct V_164 * V_165 )
{
struct V_44 * V_78 ;
unsigned int * V_125 ;
unsigned int V_166 ;
int V_14 = 0 ;
V_123 -> V_133 = V_165 -> V_133 ;
V_123 -> V_137 = V_165 -> V_167 ;
for ( V_166 = 0 ; V_166 < V_126 ; V_166 ++ ) {
V_123 -> V_80 [ V_166 ] = 0xFFFFFFFF ;
V_123 -> V_120 [ V_166 ] = 0xFFFFFFFF ;
}
V_125 = F_60 ( V_123 -> V_137 ) ;
if ( ! V_125 )
return - V_154 ;
V_166 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_55 ( V_78 , V_123 , V_124 ,
V_124 + V_165 -> V_133 ,
V_165 -> V_80 ,
V_165 -> V_120 ,
V_165 -> V_102 ) ;
if ( V_14 != 0 )
goto V_168;
if ( V_166 < V_165 -> V_167 )
V_125 [ V_166 ] = ( void * ) V_78 - V_124 ;
++ V_166 ;
if ( strcmp ( F_15 ( V_78 ) -> V_59 . V_131 . V_61 ,
V_62 ) == 0 )
++ V_123 -> V_104 ;
}
V_14 = - V_161 ;
if ( V_166 != V_165 -> V_167 )
goto V_168;
for ( V_166 = 0 ; V_166 < V_126 ; V_166 ++ ) {
if ( ! ( V_165 -> V_102 & ( 1 << V_166 ) ) )
continue;
if ( V_123 -> V_80 [ V_166 ] == 0xFFFFFFFF )
goto V_168;
if ( V_123 -> V_120 [ V_166 ] == 0xFFFFFFFF )
goto V_168;
}
if ( ! F_37 ( V_123 , V_165 -> V_102 , V_124 , V_125 ) ) {
V_14 = - V_169 ;
goto V_168;
}
F_61 ( V_125 ) ;
V_166 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_49 ( V_78 , V_69 , V_165 -> V_61 , V_165 -> V_133 ) ;
if ( V_14 != 0 )
break;
++ V_166 ;
}
if ( V_14 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_166 -- == 0 )
break;
F_58 ( V_78 , V_69 ) ;
}
return V_14 ;
}
return V_14 ;
V_168:
F_61 ( V_125 ) ;
return V_14 ;
}
static void
F_62 ( const struct V_75 * V_57 ,
struct V_108 V_114 [] )
{
struct V_44 * V_78 ;
unsigned int V_96 ;
unsigned int V_166 ;
F_63 (cpu) {
T_1 * V_51 = & F_64 ( V_170 , V_96 ) ;
V_166 = 0 ;
F_18 (iter, t->entries, t->size) {
struct V_108 * V_171 ;
T_2 V_172 , V_128 ;
unsigned int V_173 ;
V_171 = F_65 ( & V_78 -> V_114 , V_96 ) ;
do {
V_173 = F_66 ( V_51 ) ;
V_172 = V_171 -> V_172 ;
V_128 = V_171 -> V_128 ;
} while ( F_67 ( V_51 , V_173 ) );
F_32 ( V_114 [ V_166 ] , V_172 , V_128 ) ;
++ V_166 ;
}
}
}
static struct V_108 * F_68 ( const struct V_1 * V_89 )
{
unsigned int V_174 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
V_174 = sizeof( struct V_108 ) * V_76 -> V_137 ;
V_114 = F_69 ( V_174 ) ;
if ( V_114 == NULL )
return F_70 ( - V_154 ) ;
F_62 ( V_76 , V_114 ) ;
return V_114 ;
}
static int
F_71 ( unsigned int V_175 ,
const struct V_1 * V_89 ,
void T_3 * V_176 )
{
unsigned int V_177 , V_178 ;
const struct V_44 * V_47 ;
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
int V_14 = 0 ;
const void * V_179 ;
V_114 = F_68 ( V_89 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_179 = V_76 -> V_79 ;
if ( F_72 ( V_176 , V_179 , V_175 ) != 0 ) {
V_14 = - V_180 ;
goto V_181;
}
for ( V_177 = 0 , V_178 = 0 ; V_177 < V_175 ; V_177 += V_47 -> V_86 , V_178 ++ ) {
unsigned int V_166 ;
const struct V_106 * V_138 ;
const struct V_50 * V_57 ;
V_47 = (struct V_44 * ) ( V_179 + V_177 ) ;
if ( F_72 ( V_176 + V_177
+ F_73 ( struct V_44 , V_114 ) ,
& V_114 [ V_178 ] ,
sizeof( V_114 [ V_178 ] ) ) != 0 ) {
V_14 = - V_180 ;
goto V_181;
}
for ( V_166 = sizeof( struct V_44 ) ;
V_166 < V_47 -> V_49 ;
V_166 += V_138 -> V_59 . V_144 ) {
V_138 = ( void * ) V_47 + V_166 ;
if ( F_72 ( V_176 + V_177 + V_166
+ F_73 ( struct V_106 ,
V_59 . V_131 . V_61 ) ,
V_138 -> V_59 . V_60 . V_112 -> V_61 ,
strlen ( V_138 -> V_59 . V_60 . V_112 -> V_61 ) + 1 )
!= 0 ) {
V_14 = - V_180 ;
goto V_181;
}
}
V_57 = F_14 ( V_47 ) ;
if ( F_72 ( V_176 + V_177 + V_47 -> V_49
+ F_73 ( struct V_50 ,
V_59 . V_131 . V_61 ) ,
V_57 -> V_59 . V_60 . V_58 -> V_61 ,
strlen ( V_57 -> V_59 . V_60 . V_58 -> V_61 ) + 1 ) != 0 ) {
V_14 = - V_180 ;
goto V_181;
}
}
V_181:
F_74 ( V_114 ) ;
return V_14 ;
}
static void F_75 ( void * V_24 , const void * V_20 )
{
int V_118 = * ( V_182 * ) V_20 ;
if ( V_118 > 0 )
V_118 += F_76 ( V_83 , V_118 ) ;
memcpy ( V_24 , & V_118 , sizeof( V_118 ) ) ;
}
static int F_77 ( void T_3 * V_24 , const void * V_20 )
{
V_182 V_183 = * ( int * ) V_20 ;
if ( V_183 > 0 )
V_183 -= F_76 ( V_83 , V_183 ) ;
return F_72 ( V_24 , & V_183 , sizeof( V_183 ) ) ? - V_180 : 0 ;
}
static int F_78 ( const struct V_44 * V_47 ,
const struct V_75 * V_2 ,
const void * V_45 , struct V_75 * V_123 )
{
const struct V_106 * V_107 ;
const struct V_50 * V_57 ;
unsigned int V_184 ;
int V_177 , V_166 , V_14 ;
V_177 = sizeof( struct V_44 ) - sizeof( struct V_185 ) ;
V_184 = ( void * ) V_47 - V_45 ;
F_30 (ematch, e)
V_177 += F_79 ( V_107 -> V_59 . V_60 . V_112 ) ;
V_57 = F_14 ( V_47 ) ;
V_177 += F_80 ( V_57 -> V_59 . V_60 . V_58 ) ;
V_123 -> V_133 -= V_177 ;
V_14 = F_81 ( V_83 , V_184 , V_177 ) ;
if ( V_14 )
return V_14 ;
for ( V_166 = 0 ; V_166 < V_126 ; V_166 ++ ) {
if ( V_2 -> V_80 [ V_166 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_166 ] ) ) )
V_123 -> V_80 [ V_166 ] -= V_177 ;
if ( V_2 -> V_120 [ V_166 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_120 [ V_166 ] ) ) )
V_123 -> V_120 [ V_166 ] -= V_177 ;
}
return 0 ;
}
static int F_82 ( const struct V_75 * V_2 ,
struct V_75 * V_123 )
{
struct V_44 * V_78 ;
const void * V_179 ;
int V_14 ;
if ( ! V_123 || ! V_2 )
return - V_161 ;
memcpy ( V_123 , V_2 , F_73 ( struct V_75 , V_79 ) ) ;
V_123 -> V_186 = 0 ;
V_179 = V_2 -> V_79 ;
F_83 ( V_83 , V_2 -> V_137 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_14 = F_78 ( V_78 , V_2 , V_179 , V_123 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_84 ( struct V_69 * V_69 , void T_3 * V_131 ,
const int * V_115 , int V_187 )
{
char V_61 [ V_188 ] ;
struct V_1 * V_57 ;
int V_14 ;
if ( * V_115 != sizeof( struct V_189 ) )
return - V_161 ;
if ( F_85 ( V_61 , V_131 , sizeof( V_61 ) ) != 0 )
return - V_180 ;
V_61 [ V_188 - 1 ] = '\0' ;
#ifdef F_86
if ( V_187 )
F_87 ( V_83 ) ;
#endif
V_57 = F_88 ( F_89 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( ! F_90 ( V_57 ) ) {
struct V_189 V_2 ;
const struct V_75 * V_76 = V_57 -> V_76 ;
#ifdef F_86
struct V_75 V_171 ;
if ( V_187 ) {
V_14 = F_82 ( V_76 , & V_171 ) ;
F_91 ( V_83 ) ;
V_76 = & V_171 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_102 = V_57 -> V_102 ;
memcpy ( V_2 . V_80 , V_76 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_120 , V_76 -> V_120 ,
sizeof( V_2 . V_120 ) ) ;
V_2 . V_167 = V_76 -> V_137 ;
V_2 . V_133 = V_76 -> V_133 ;
strcpy ( V_2 . V_61 , V_61 ) ;
if ( F_72 ( V_131 , & V_2 , * V_115 ) != 0 )
V_14 = - V_180 ;
else
V_14 = 0 ;
F_92 ( V_57 ) ;
F_40 ( V_57 -> V_141 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_190 ;
#ifdef F_86
if ( V_187 )
F_93 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_94 ( struct V_69 * V_69 , struct V_191 T_3 * V_192 ,
const int * V_115 )
{
int V_14 ;
struct V_191 V_193 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_193 ) )
return - V_161 ;
if ( F_85 ( & V_193 , V_192 , sizeof( V_193 ) ) != 0 )
return - V_180 ;
if ( * V_115 != sizeof( struct V_191 ) + V_193 . V_133 )
return - V_161 ;
V_193 . V_61 [ sizeof( V_193 . V_61 ) - 1 ] = '\0' ;
V_57 = F_89 ( V_69 , V_83 , V_193 . V_61 ) ;
if ( ! F_90 ( V_57 ) ) {
struct V_75 * V_76 = V_57 -> V_76 ;
if ( V_193 . V_133 == V_76 -> V_133 )
V_14 = F_71 ( V_76 -> V_133 ,
V_57 , V_192 -> V_194 ) ;
else
V_14 = - V_195 ;
F_40 ( V_57 -> V_141 ) ;
F_92 ( V_57 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_190 ;
return V_14 ;
}
static int
F_95 ( struct V_69 * V_69 , const char * V_61 , unsigned int V_102 ,
struct V_75 * V_123 , unsigned int V_196 ,
void T_3 * V_197 )
{
int V_14 ;
struct V_1 * V_57 ;
struct V_75 * V_198 ;
struct V_108 * V_114 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_114 = F_69 ( V_196 * sizeof( struct V_108 ) ) ;
if ( ! V_114 ) {
V_14 = - V_154 ;
goto V_73;
}
V_57 = F_88 ( F_89 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( F_90 ( V_57 ) ) {
V_14 = V_57 ? F_46 ( V_57 ) : - V_190 ;
goto V_199;
}
if ( V_102 != V_57 -> V_102 ) {
V_14 = - V_161 ;
goto V_200;
}
V_198 = F_96 ( V_57 , V_196 , V_123 , & V_14 ) ;
if ( ! V_198 )
goto V_200;
if ( ( V_198 -> V_137 > V_198 -> V_186 ) ||
( V_123 -> V_137 <= V_198 -> V_186 ) )
F_40 ( V_57 -> V_141 ) ;
if ( ( V_198 -> V_137 > V_198 -> V_186 ) &&
( V_123 -> V_137 <= V_198 -> V_186 ) )
F_40 ( V_57 -> V_141 ) ;
F_62 ( V_198 , V_114 ) ;
F_18 (iter, oldinfo->entries, oldinfo->size)
F_58 ( V_78 , V_69 ) ;
F_97 ( V_198 ) ;
if ( F_72 ( V_197 , V_114 ,
sizeof( struct V_108 ) * V_196 ) != 0 ) {
F_98 ( L_4 ) ;
}
F_74 ( V_114 ) ;
F_92 ( V_57 ) ;
return V_14 ;
V_200:
F_40 ( V_57 -> V_141 ) ;
F_92 ( V_57 ) ;
V_199:
F_74 ( V_114 ) ;
V_73:
return V_14 ;
}
static int
F_99 ( struct V_69 * V_69 , const void T_3 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_164 V_171 ;
struct V_75 * V_123 ;
void * V_179 ;
struct V_44 * V_78 ;
if ( F_85 ( & V_171 , V_131 , sizeof( V_171 ) ) != 0 )
return - V_180 ;
if ( V_171 . V_196 >= V_201 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_171 . V_196 == 0 )
return - V_161 ;
V_171 . V_61 [ sizeof( V_171 . V_61 ) - 1 ] = 0 ;
V_123 = F_100 ( V_171 . V_133 ) ;
if ( ! V_123 )
return - V_154 ;
V_179 = V_123 -> V_79 ;
if ( F_85 ( V_179 , V_131 + sizeof( V_171 ) ,
V_171 . V_133 ) != 0 ) {
V_14 = - V_180 ;
goto V_202;
}
V_14 = F_59 ( V_69 , V_123 , V_179 , & V_171 ) ;
if ( V_14 != 0 )
goto V_202;
V_14 = F_95 ( V_69 , V_171 . V_61 , V_171 . V_102 , V_123 ,
V_171 . V_196 , V_171 . V_114 ) ;
if ( V_14 )
goto V_203;
return 0 ;
V_203:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_69 ) ;
V_202:
F_97 ( V_123 ) ;
return V_14 ;
}
static int
F_101 ( struct V_69 * V_69 , const void T_3 * V_131 , unsigned int V_115 ,
int V_187 )
{
unsigned int V_166 ;
struct V_204 V_171 ;
struct V_108 * V_205 ;
struct V_1 * V_57 ;
const struct V_75 * V_76 ;
int V_14 = 0 ;
struct V_44 * V_78 ;
unsigned int V_98 ;
V_205 = F_102 ( V_131 , V_115 , & V_171 , V_187 ) ;
if ( F_45 ( V_205 ) )
return F_46 ( V_205 ) ;
V_57 = F_89 ( V_69 , V_83 , V_171 . V_61 ) ;
if ( F_90 ( V_57 ) ) {
V_14 = V_57 ? F_46 ( V_57 ) : - V_190 ;
goto free;
}
F_24 () ;
V_76 = V_57 -> V_76 ;
if ( V_76 -> V_137 != V_171 . V_196 ) {
V_14 = - V_161 ;
goto V_206;
}
V_166 = 0 ;
V_98 = F_25 () ;
F_18 (iter, private->entries, private->size) {
struct V_108 * V_171 ;
V_171 = F_31 ( & V_78 -> V_114 ) ;
F_32 ( * V_171 , V_205 [ V_166 ] . V_172 , V_205 [ V_166 ] . V_128 ) ;
++ V_166 ;
}
F_35 ( V_98 ) ;
V_206:
F_36 () ;
F_92 ( V_57 ) ;
F_40 ( V_57 -> V_141 ) ;
free:
F_74 ( V_205 ) ;
return V_14 ;
}
static int
F_103 ( struct V_44 * V_47 , void T_3 * * V_207 ,
unsigned int * V_133 , struct V_108 * V_114 ,
unsigned int V_166 )
{
struct V_50 * V_57 ;
struct V_185 T_3 * V_208 ;
T_4 V_49 , V_86 ;
T_5 V_209 ;
const struct V_106 * V_107 ;
int V_14 = 0 ;
V_209 = * V_133 ;
V_208 = (struct V_185 T_3 * ) * V_207 ;
if ( F_72 ( V_208 , V_47 , sizeof( struct V_44 ) ) != 0 ||
F_72 ( & V_208 -> V_114 , & V_114 [ V_166 ] ,
sizeof( V_114 [ V_166 ] ) ) != 0 )
return - V_180 ;
* V_207 += sizeof( struct V_185 ) ;
* V_133 -= sizeof( struct V_44 ) - sizeof( struct V_185 ) ;
F_30 (ematch, e) {
V_14 = F_104 ( V_107 , V_207 , V_133 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_49 = V_47 -> V_49 - ( V_209 - * V_133 ) ;
V_57 = F_15 ( V_47 ) ;
V_14 = F_105 ( V_57 , V_207 , V_133 ) ;
if ( V_14 )
return V_14 ;
V_86 = V_47 -> V_86 - ( V_209 - * V_133 ) ;
if ( F_106 ( V_49 , & V_208 -> V_49 ) != 0 ||
F_106 ( V_86 , & V_208 -> V_86 ) != 0 )
return - V_180 ;
return 0 ;
}
static int
F_107 ( struct V_106 * V_138 ,
const struct V_9 * V_16 ,
int * V_133 )
{
struct V_145 * V_112 ;
V_112 = F_44 ( V_100 , V_138 -> V_59 . V_131 . V_61 ,
V_138 -> V_59 . V_131 . V_146 ) ;
if ( F_45 ( V_112 ) )
return F_46 ( V_112 ) ;
V_138 -> V_59 . V_60 . V_112 = V_112 ;
* V_133 += F_79 ( V_112 ) ;
return 0 ;
}
static void F_108 ( struct V_185 * V_47 )
{
struct V_50 * V_57 ;
struct V_106 * V_107 ;
F_30 (ematch, e)
F_40 ( V_107 -> V_59 . V_60 . V_112 -> V_141 ) ;
V_57 = F_109 ( V_47 ) ;
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_141 ) ;
}
static int
F_110 ( struct V_185 * V_47 ,
struct V_75 * V_123 ,
unsigned int * V_133 ,
const unsigned char * V_45 ,
const unsigned char * V_157 )
{
struct V_106 * V_107 ;
struct V_50 * V_57 ;
struct V_151 * V_58 ;
unsigned int V_184 ;
unsigned int V_152 ;
int V_14 , V_177 ;
if ( ( unsigned long ) V_47 % F_56 ( struct V_185 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_185 ) >= V_157 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_157 )
return - V_161 ;
if ( V_47 -> V_86 < sizeof( struct V_185 ) +
sizeof( struct V_210 ) )
return - V_161 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_161 ;
V_14 = F_111 ( V_47 , V_47 -> V_162 ,
V_47 -> V_49 , V_47 -> V_86 ) ;
if ( V_14 )
return V_14 ;
V_177 = sizeof( struct V_44 ) - sizeof( struct V_185 ) ;
V_184 = ( void * ) V_47 - ( void * ) V_45 ;
V_152 = 0 ;
F_30 (ematch, e) {
V_14 = F_107 ( V_107 , & V_47 -> V_16 , & V_177 ) ;
if ( V_14 != 0 )
goto V_211;
++ V_152 ;
}
V_57 = F_109 ( V_47 ) ;
V_58 = F_52 ( V_100 , V_57 -> V_59 . V_131 . V_61 ,
V_57 -> V_59 . V_131 . V_146 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_211;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_177 += F_80 ( V_58 ) ;
* V_133 += V_177 ;
V_14 = F_81 ( V_83 , V_184 , V_177 ) ;
if ( V_14 )
goto V_73;
return 0 ;
V_73:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_141 ) ;
V_211:
F_30 (ematch, e) {
if ( V_152 -- == 0 )
break;
F_40 ( V_107 -> V_59 . V_60 . V_112 -> V_141 ) ;
}
return V_14 ;
}
static void
F_112 ( struct V_185 * V_47 , void * * V_207 ,
unsigned int * V_133 ,
struct V_75 * V_123 , unsigned char * V_45 )
{
struct V_50 * V_57 ;
struct V_44 * V_212 ;
unsigned int V_209 ;
int V_160 ;
struct V_106 * V_107 ;
V_209 = * V_133 ;
V_212 = (struct V_44 * ) * V_207 ;
memcpy ( V_212 , V_47 , sizeof( struct V_44 ) ) ;
memcpy ( & V_212 -> V_114 , & V_47 -> V_114 , sizeof( V_47 -> V_114 ) ) ;
* V_207 += sizeof( struct V_44 ) ;
* V_133 += sizeof( struct V_44 ) - sizeof( struct V_185 ) ;
F_30 (ematch, e)
F_113 ( V_107 , V_207 , V_133 ) ;
V_212 -> V_49 = V_47 -> V_49 - ( V_209 - * V_133 ) ;
V_57 = F_109 ( V_47 ) ;
F_114 ( V_57 , V_207 , V_133 ) ;
V_212 -> V_86 = V_47 -> V_86 - ( V_209 - * V_133 ) ;
for ( V_160 = 0 ; V_160 < V_126 ; V_160 ++ ) {
if ( ( unsigned char * ) V_212 - V_45 < V_123 -> V_80 [ V_160 ] )
V_123 -> V_80 [ V_160 ] -= V_209 - * V_133 ;
if ( ( unsigned char * ) V_212 - V_45 < V_123 -> V_120 [ V_160 ] )
V_123 -> V_120 [ V_160 ] -= V_209 - * V_133 ;
}
}
static int
F_115 ( struct V_69 * V_69 ,
struct V_75 * * V_213 ,
void * * V_214 ,
const struct V_215 * V_216 )
{
unsigned int V_166 , V_152 ;
struct V_75 * V_123 , * V_2 ;
void * V_127 , * V_124 , * V_217 ;
struct V_185 * V_218 ;
struct V_164 V_165 ;
unsigned int V_133 ;
int V_14 = 0 ;
V_2 = * V_213 ;
V_124 = * V_214 ;
V_133 = V_216 -> V_133 ;
V_2 -> V_137 = V_216 -> V_167 ;
V_152 = 0 ;
F_87 ( V_83 ) ;
F_83 ( V_83 , V_216 -> V_167 ) ;
F_18 (iter0, entry0, compatr->size) {
V_14 = F_110 ( V_218 , V_2 , & V_133 ,
V_124 ,
V_124 + V_216 -> V_133 ) ;
if ( V_14 != 0 )
goto V_219;
++ V_152 ;
}
V_14 = - V_161 ;
if ( V_152 != V_216 -> V_167 )
goto V_219;
V_14 = - V_154 ;
V_123 = F_100 ( V_133 ) ;
if ( ! V_123 )
goto V_219;
V_123 -> V_137 = V_216 -> V_167 ;
for ( V_166 = 0 ; V_166 < V_126 ; V_166 ++ ) {
V_123 -> V_80 [ V_166 ] = V_216 -> V_80 [ V_166 ] ;
V_123 -> V_120 [ V_166 ] = V_216 -> V_120 [ V_166 ] ;
}
V_217 = V_123 -> V_79 ;
V_127 = V_217 ;
V_133 = V_216 -> V_133 ;
F_18 (iter0, entry0, compatr->size)
F_112 ( V_218 , & V_127 , & V_133 ,
V_123 , V_217 ) ;
F_91 ( V_83 ) ;
F_93 ( V_83 ) ;
memcpy ( & V_165 , V_216 , sizeof( * V_216 ) ) ;
for ( V_166 = 0 ; V_166 < V_126 ; V_166 ++ ) {
V_165 . V_80 [ V_166 ] = V_123 -> V_80 [ V_166 ] ;
V_165 . V_120 [ V_166 ] = V_123 -> V_120 [ V_166 ] ;
}
V_165 . V_196 = 0 ;
V_165 . V_114 = NULL ;
V_165 . V_133 = V_123 -> V_133 ;
V_14 = F_59 ( V_69 , V_123 , V_217 , & V_165 ) ;
if ( V_14 )
goto V_202;
* V_213 = V_123 ;
* V_214 = V_217 ;
F_97 ( V_2 ) ;
return 0 ;
V_202:
F_97 ( V_123 ) ;
return V_14 ;
V_219:
F_91 ( V_83 ) ;
F_93 ( V_83 ) ;
F_18 (iter0, entry0, compatr->size) {
if ( V_152 -- == 0 )
break;
F_108 ( V_218 ) ;
}
return V_14 ;
}
static int
F_116 ( struct V_69 * V_69 , void T_3 * V_131 , unsigned int V_115 )
{
int V_14 ;
struct V_215 V_171 ;
struct V_75 * V_123 ;
void * V_179 ;
struct V_44 * V_78 ;
if ( F_85 ( & V_171 , V_131 , sizeof( V_171 ) ) != 0 )
return - V_180 ;
if ( V_171 . V_196 >= V_201 / sizeof( struct V_108 ) )
return - V_154 ;
if ( V_171 . V_196 == 0 )
return - V_161 ;
V_171 . V_61 [ sizeof( V_171 . V_61 ) - 1 ] = 0 ;
V_123 = F_100 ( V_171 . V_133 ) ;
if ( ! V_123 )
return - V_154 ;
V_179 = V_123 -> V_79 ;
if ( F_85 ( V_179 , V_131 + sizeof( V_171 ) ,
V_171 . V_133 ) != 0 ) {
V_14 = - V_180 ;
goto V_202;
}
V_14 = F_115 ( V_69 , & V_123 , & V_179 , & V_171 ) ;
if ( V_14 != 0 )
goto V_202;
V_14 = F_95 ( V_69 , V_171 . V_61 , V_171 . V_102 , V_123 ,
V_171 . V_196 , F_117 ( V_171 . V_114 ) ) ;
if ( V_14 )
goto V_203;
return 0 ;
V_203:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_58 ( V_78 , V_69 ) ;
V_202:
F_97 ( V_123 ) ;
return V_14 ;
}
static int
F_118 ( struct V_220 * V_221 , int V_222 , void T_3 * V_131 ,
unsigned int V_115 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_14 = F_116 ( F_120 ( V_221 ) , V_131 , V_115 ) ;
break;
case V_227 :
V_14 = F_101 ( F_120 ( V_221 ) , V_131 , V_115 , 1 ) ;
break;
default:
V_14 = - V_161 ;
}
return V_14 ;
}
static int
F_121 ( unsigned int V_175 , struct V_1 * V_89 ,
void T_3 * V_176 )
{
struct V_108 * V_114 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
void T_3 * V_127 ;
unsigned int V_133 ;
int V_14 = 0 ;
unsigned int V_166 = 0 ;
struct V_44 * V_78 ;
V_114 = F_68 ( V_89 ) ;
if ( F_45 ( V_114 ) )
return F_46 ( V_114 ) ;
V_127 = V_176 ;
V_133 = V_175 ;
F_18 (iter, private->entries, total_size) {
V_14 = F_103 ( V_78 , & V_127 ,
& V_133 , V_114 , V_166 ++ ) ;
if ( V_14 != 0 )
break;
}
F_74 ( V_114 ) ;
return V_14 ;
}
static int
F_122 ( struct V_69 * V_69 , struct V_228 T_3 * V_192 ,
int * V_115 )
{
int V_14 ;
struct V_228 V_193 ;
struct V_1 * V_57 ;
if ( * V_115 < sizeof( V_193 ) )
return - V_161 ;
if ( F_85 ( & V_193 , V_192 , sizeof( V_193 ) ) != 0 )
return - V_180 ;
if ( * V_115 != sizeof( struct V_228 ) + V_193 . V_133 )
return - V_161 ;
V_193 . V_61 [ sizeof( V_193 . V_61 ) - 1 ] = '\0' ;
F_87 ( V_83 ) ;
V_57 = F_89 ( V_69 , V_83 , V_193 . V_61 ) ;
if ( ! F_90 ( V_57 ) ) {
const struct V_75 * V_76 = V_57 -> V_76 ;
struct V_75 V_2 ;
V_14 = F_82 ( V_76 , & V_2 ) ;
if ( ! V_14 && V_193 . V_133 == V_2 . V_133 )
V_14 = F_121 ( V_76 -> V_133 ,
V_57 , V_192 -> V_194 ) ;
else if ( ! V_14 )
V_14 = - V_195 ;
F_91 ( V_83 ) ;
F_40 ( V_57 -> V_141 ) ;
F_92 ( V_57 ) ;
} else
V_14 = V_57 ? F_46 ( V_57 ) : - V_190 ;
F_93 ( V_83 ) ;
return V_14 ;
}
static int
F_123 ( struct V_220 * V_221 , int V_222 , void T_3 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_229 :
V_14 = F_84 ( F_120 ( V_221 ) , V_131 , V_115 , 1 ) ;
break;
case V_230 :
V_14 = F_122 ( F_120 ( V_221 ) , V_131 , V_115 ) ;
break;
default:
V_14 = F_124 ( V_221 , V_222 , V_131 , V_115 ) ;
}
return V_14 ;
}
static int
F_125 ( struct V_220 * V_221 , int V_222 , void T_3 * V_131 , unsigned int V_115 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_226 :
V_14 = F_99 ( F_120 ( V_221 ) , V_131 , V_115 ) ;
break;
case V_227 :
V_14 = F_101 ( F_120 ( V_221 ) , V_131 , V_115 , 0 ) ;
break;
default:
V_14 = - V_161 ;
}
return V_14 ;
}
static int
F_124 ( struct V_220 * V_221 , int V_222 , void T_3 * V_131 , int * V_115 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_221 ) -> V_223 , V_224 ) )
return - V_225 ;
switch ( V_222 ) {
case V_229 :
V_14 = F_84 ( F_120 ( V_221 ) , V_131 , V_115 , 0 ) ;
break;
case V_230 :
V_14 = F_94 ( F_120 ( V_221 ) , V_131 , V_115 ) ;
break;
case V_231 :
case V_232 : {
struct V_233 V_234 ;
int V_58 ;
if ( * V_115 != sizeof( V_234 ) ) {
V_14 = - V_161 ;
break;
}
if ( F_85 ( & V_234 , V_131 , sizeof( V_234 ) ) != 0 ) {
V_14 = - V_180 ;
break;
}
V_234 . V_61 [ sizeof( V_234 . V_61 ) - 1 ] = 0 ;
if ( V_222 == V_232 )
V_58 = 1 ;
else
V_58 = 0 ;
F_88 ( F_126 ( V_83 , V_234 . V_61 ,
V_234 . V_146 ,
V_58 , & V_14 ) ,
L_5 , V_234 . V_61 ) ;
break;
}
default:
V_14 = - V_161 ;
}
return V_14 ;
}
static void F_127 ( struct V_69 * V_69 , struct V_1 * V_89 )
{
struct V_75 * V_76 ;
void * V_179 ;
struct V_235 * V_236 = V_89 -> V_141 ;
struct V_44 * V_78 ;
V_76 = F_128 ( V_89 ) ;
V_179 = V_76 -> V_79 ;
F_18 (iter, loc_cpu_entry, private->size)
F_58 ( V_78 , V_69 ) ;
if ( V_76 -> V_137 > V_76 -> V_186 )
F_40 ( V_236 ) ;
F_97 ( V_76 ) ;
}
int F_129 ( struct V_69 * V_69 , const struct V_1 * V_89 ,
const struct V_164 * V_165 ,
const struct V_237 * V_238 ,
struct V_1 * * V_239 )
{
int V_14 ;
struct V_75 * V_123 ;
struct V_75 V_240 = { 0 } ;
void * V_179 ;
struct V_1 * V_241 ;
V_123 = F_100 ( V_165 -> V_133 ) ;
if ( ! V_123 )
return - V_154 ;
V_179 = V_123 -> V_79 ;
memcpy ( V_179 , V_165 -> V_79 , V_165 -> V_133 ) ;
V_14 = F_59 ( V_69 , V_123 , V_179 , V_165 ) ;
if ( V_14 != 0 )
goto V_168;
V_241 = F_130 ( V_69 , V_89 , & V_240 , V_123 ) ;
if ( F_45 ( V_241 ) ) {
V_14 = F_46 ( V_241 ) ;
goto V_168;
}
F_131 ( * V_239 , V_241 ) ;
V_14 = F_132 ( V_69 , V_238 , F_133 ( V_89 -> V_102 ) ) ;
if ( V_14 != 0 ) {
F_127 ( V_69 , V_241 ) ;
* V_239 = NULL ;
}
return V_14 ;
V_168:
F_97 ( V_123 ) ;
return V_14 ;
}
void F_134 ( struct V_69 * V_69 , struct V_1 * V_89 ,
const struct V_237 * V_238 )
{
F_135 ( V_69 , V_238 , F_133 ( V_89 -> V_102 ) ) ;
F_127 ( V_69 , V_89 ) ;
}
static inline bool
F_136 ( T_6 V_242 , T_6 V_243 , T_6 V_244 ,
T_6 type , T_6 V_245 ,
bool V_246 )
{
return ( type == V_242 && V_245 >= V_243 && V_245 <= V_244 )
^ V_246 ;
}
static bool
F_137 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_247 * V_248 ;
struct V_247 V_249 ;
const struct V_250 * V_251 = V_41 -> V_113 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_248 = F_138 ( V_6 , V_41 -> V_110 , sizeof( V_249 ) , & V_249 ) ;
if ( V_248 == NULL ) {
V_41 -> V_13 = true ;
return false ;
}
return F_136 ( V_251 -> type ,
V_251 -> V_245 [ 0 ] ,
V_251 -> V_245 [ 1 ] ,
V_248 -> V_252 , V_248 -> V_253 ,
! ! ( V_251 -> V_36 & V_254 ) ) ;
}
static int F_139 ( const struct V_142 * V_41 )
{
const struct V_250 * V_251 = V_41 -> V_113 ;
return ( V_251 -> V_36 & ~ V_254 ) ? - V_161 : 0 ;
}
static int T_7 F_140 ( struct V_69 * V_69 )
{
return F_141 ( V_69 , V_100 ) ;
}
static void T_8 F_142 ( struct V_69 * V_69 )
{
F_143 ( V_69 , V_100 ) ;
}
static int T_9 F_144 ( void )
{
int V_14 ;
V_14 = F_145 ( & V_255 ) ;
if ( V_14 < 0 )
goto V_256;
V_14 = F_146 ( V_257 , F_147 ( V_257 ) ) ;
if ( V_14 < 0 )
goto V_258;
V_14 = F_148 ( V_259 , F_147 ( V_259 ) ) ;
if ( V_14 < 0 )
goto V_260;
V_14 = F_149 ( & V_261 ) ;
if ( V_14 < 0 )
goto V_262;
F_150 ( L_6 ) ;
return 0 ;
V_262:
F_151 ( V_259 , F_147 ( V_259 ) ) ;
V_260:
F_152 ( V_257 , F_147 ( V_257 ) ) ;
V_258:
F_153 ( & V_255 ) ;
V_256:
return V_14 ;
}
static void T_10 F_154 ( void )
{
F_155 ( & V_261 ) ;
F_151 ( V_259 , F_147 ( V_259 ) ) ;
F_152 ( V_257 , F_147 ( V_257 ) ) ;
F_153 ( & V_255 ) ;
}
