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
V_97 . V_88 = V_88 ;
F_23 ( V_89 -> V_99 & ( 1 << V_70 ) ) ;
F_24 () ;
V_98 = F_25 () ;
V_76 = V_89 -> V_76 ;
F_26 () ;
V_96 = F_27 () ;
V_93 = V_76 -> V_79 ;
V_94 = (struct V_44 * * ) V_76 -> V_94 [ V_96 ] ;
if ( F_28 ( & V_100 ) )
V_94 += V_76 -> V_101 * F_29 ( V_102 ) ;
V_47 = F_12 ( V_93 , V_76 -> V_80 [ V_70 ] ) ;
do {
const struct V_50 * V_57 ;
const struct V_103 * V_104 ;
struct V_105 * V_106 ;
F_23 ( V_47 ) ;
V_97 . V_107 = 0 ;
if ( ! F_3 ( V_6 , V_7 , V_8 , & V_47 -> V_16 ,
& V_97 . V_107 , & V_97 . V_12 , & V_97 . V_13 ) ) {
V_108:
V_47 = F_20 ( V_47 ) ;
continue;
}
F_30 (ematch, e) {
V_97 . V_109 = V_104 -> V_59 . V_60 . V_109 ;
V_97 . V_110 = V_104 -> V_63 ;
if ( ! V_97 . V_109 -> V_109 ( V_6 , & V_97 ) )
goto V_108;
}
V_106 = F_31 ( & V_47 -> V_111 ) ;
F_32 ( * V_106 , V_6 -> V_112 , 1 ) ;
V_57 = F_14 ( V_47 ) ;
F_23 ( V_57 -> V_59 . V_60 . V_58 ) ;
#if F_33 ( V_113 )
if ( F_34 ( V_6 -> V_114 ) )
F_17 ( V_88 -> V_69 , V_6 , V_70 , V_88 -> V_72 ,
V_88 -> V_73 , V_89 -> V_61 , V_76 , V_47 ) ;
#endif
if ( ! V_57 -> V_59 . V_60 . V_58 -> V_58 ) {
int V_115 ;
V_115 = ( (struct V_56 * ) V_57 ) -> V_65 ;
if ( V_115 < 0 ) {
if ( V_115 != V_116 ) {
V_65 = ( unsigned int ) ( - V_115 ) - 1 ;
break;
}
if ( V_95 == 0 )
V_47 = F_12 ( V_93 ,
V_76 -> V_117 [ V_70 ] ) ;
else
V_47 = F_20 ( V_94 [ -- V_95 ] ) ;
continue;
}
if ( V_93 + V_115 != F_20 ( V_47 ) &&
! ( V_47 -> V_16 . V_31 & V_118 ) ) {
V_94 [ V_95 ++ ] = V_47 ;
}
V_47 = F_12 ( V_93 , V_115 ) ;
continue;
}
V_97 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_97 . V_42 = V_57 -> V_63 ;
V_65 = V_57 -> V_59 . V_60 . V_58 -> V_58 ( V_6 , & V_97 ) ;
if ( V_65 == V_119 )
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
F_37 ( const struct V_75 * V_120 ,
unsigned int V_99 , void * V_121 ,
unsigned int * V_122 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_123 ; V_70 ++ ) {
unsigned int V_124 = V_120 -> V_80 [ V_70 ] ;
struct V_44 * V_47 = (struct V_44 * ) ( V_121 + V_124 ) ;
if ( ! ( V_99 & ( 1 << V_70 ) ) )
continue;
V_47 -> V_111 . V_125 = V_124 ;
for (; ; ) {
const struct V_56 * V_57
= ( void * ) F_14 ( V_47 ) ;
int V_126 = V_47 -> V_127 & ( 1 << V_70 ) ;
if ( V_47 -> V_127 & ( 1 << V_123 ) )
return 0 ;
V_47 -> V_127 |= ( ( 1 << V_70 ) | ( 1 << V_123 ) ) ;
if ( ( F_13 ( V_47 ) &&
( strcmp ( V_57 -> V_58 . V_59 . V_128 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < 0 ) || V_126 ) {
unsigned int V_129 , V_130 ;
if ( ( strcmp ( V_57 -> V_58 . V_59 . V_128 . V_61 ,
V_64 ) == 0 ) &&
V_57 -> V_65 < - V_131 - 1 )
return 0 ;
do {
V_47 -> V_127 ^= ( 1 << V_123 ) ;
V_129 = V_124 ;
V_124 = V_47 -> V_111 . V_125 ;
V_47 -> V_111 . V_125 = 0 ;
if ( V_124 == V_129 )
goto V_132;
V_47 = (struct V_44 * )
( V_121 + V_124 ) ;
} while ( V_129 == V_124 + V_47 -> V_86 );
V_130 = V_47 -> V_86 ;
V_47 = (struct V_44 * )
( V_121 + V_124 + V_130 ) ;
if ( V_124 + V_130 >= V_120 -> V_130 )
return 0 ;
V_47 -> V_111 . V_125 = V_124 ;
V_124 += V_130 ;
} else {
int V_133 = V_57 -> V_65 ;
if ( strcmp ( V_57 -> V_58 . V_59 . V_128 . V_61 ,
V_64 ) == 0 &&
V_133 >= 0 ) {
if ( ! F_38 ( V_122 , V_133 ,
V_120 -> V_134 ) )
return 0 ;
V_47 = (struct V_44 * )
( V_121 + V_133 ) ;
} else {
V_133 = V_124 + V_47 -> V_86 ;
if ( V_133 >= V_120 -> V_130 )
return 0 ;
}
V_47 = (struct V_44 * )
( V_121 + V_133 ) ;
V_47 -> V_111 . V_125 = V_124 ;
V_124 = V_133 ;
}
}
V_132: ;
}
return 1 ;
}
static void F_39 ( struct V_103 * V_135 , struct V_69 * V_69 )
{
struct V_136 V_41 ;
V_41 . V_69 = V_69 ;
V_41 . V_109 = V_135 -> V_59 . V_60 . V_109 ;
V_41 . V_110 = V_135 -> V_63 ;
V_41 . V_137 = V_138 ;
if ( V_41 . V_109 -> V_139 != NULL )
V_41 . V_109 -> V_139 ( & V_41 ) ;
F_40 ( V_41 . V_109 -> V_140 ) ;
}
static int F_41 ( struct V_103 * V_135 , struct V_141 * V_41 )
{
const struct V_9 * V_16 = V_41 -> V_142 ;
V_41 -> V_109 = V_135 -> V_59 . V_60 . V_109 ;
V_41 -> V_110 = V_135 -> V_63 ;
return F_42 ( V_41 , V_135 -> V_59 . V_143 - sizeof( * V_135 ) ,
V_16 -> V_35 , V_16 -> V_36 & V_37 ) ;
}
static int
F_43 ( struct V_103 * V_135 , struct V_141 * V_41 )
{
struct V_144 * V_109 ;
int V_14 ;
V_109 = F_44 ( V_138 , V_135 -> V_59 . V_128 . V_61 ,
V_135 -> V_59 . V_128 . V_145 ) ;
if ( F_45 ( V_109 ) )
return F_46 ( V_109 ) ;
V_135 -> V_59 . V_60 . V_109 = V_109 ;
V_14 = F_41 ( V_135 , V_41 ) ;
if ( V_14 )
goto V_146;
return 0 ;
V_146:
F_40 ( V_135 -> V_59 . V_60 . V_109 -> V_140 ) ;
return V_14 ;
}
static int F_47 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 )
{
struct V_50 * V_57 = F_15 ( V_47 ) ;
struct V_147 V_41 = {
. V_69 = V_69 ,
. V_89 = V_61 ,
. V_142 = V_47 ,
. V_58 = V_57 -> V_59 . V_60 . V_58 ,
. V_42 = V_57 -> V_63 ,
. V_148 = V_47 -> V_127 ,
. V_137 = V_138 ,
} ;
V_57 = F_15 ( V_47 ) ;
return F_48 ( & V_41 , V_57 -> V_59 . V_149 - sizeof( * V_57 ) ,
V_47 -> V_16 . V_35 ,
V_47 -> V_16 . V_36 & V_37 ) ;
}
static int
F_49 ( struct V_44 * V_47 , struct V_69 * V_69 , const char * V_61 ,
unsigned int V_130 ,
struct V_150 * V_151 )
{
struct V_50 * V_57 ;
struct V_152 * V_58 ;
int V_14 ;
unsigned int V_153 ;
struct V_141 V_154 ;
struct V_103 * V_104 ;
if ( ! F_50 ( V_151 , & V_47 -> V_111 ) )
return - V_155 ;
V_153 = 0 ;
V_154 . V_69 = V_69 ;
V_154 . V_89 = V_61 ;
V_154 . V_142 = & V_47 -> V_16 ;
V_154 . V_148 = V_47 -> V_127 ;
V_154 . V_137 = V_138 ;
F_30 (ematch, e) {
V_14 = F_43 ( V_104 , & V_154 ) ;
if ( V_14 != 0 )
goto V_156;
++ V_153 ;
}
V_57 = F_15 ( V_47 ) ;
V_58 = F_51 ( V_138 , V_57 -> V_59 . V_128 . V_61 ,
V_57 -> V_59 . V_128 . V_145 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_156;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_14 = F_47 ( V_47 , V_69 , V_61 ) ;
if ( V_14 )
goto V_146;
return 0 ;
V_146:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
V_156:
F_30 (ematch, e) {
if ( V_153 -- == 0 )
break;
F_39 ( V_104 , V_69 ) ;
}
F_52 ( & V_47 -> V_111 ) ;
return V_14 ;
}
static bool F_53 ( const struct V_44 * V_47 )
{
const struct V_50 * V_57 ;
unsigned int V_65 ;
if ( ! F_13 ( V_47 ) )
return false ;
V_57 = F_14 ( V_47 ) ;
if ( strcmp ( V_57 -> V_59 . V_128 . V_61 , V_64 ) != 0 )
return false ;
V_65 = ( (struct V_56 * ) V_57 ) -> V_65 ;
V_65 = - V_65 - 1 ;
return V_65 == V_43 || V_65 == V_157 ;
}
static int
F_54 ( struct V_44 * V_47 ,
struct V_75 * V_120 ,
const unsigned char * V_45 ,
const unsigned char * V_158 ,
const unsigned int * V_159 ,
const unsigned int * V_160 ,
unsigned int V_99 )
{
unsigned int V_161 ;
int V_146 ;
if ( ( unsigned long ) V_47 % F_55 ( struct V_44 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_44 ) >= V_158 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_158 )
return - V_162 ;
if ( V_47 -> V_86
< sizeof( struct V_44 ) + sizeof( struct V_50 ) )
return - V_162 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_162 ;
V_146 = F_56 ( V_47 , V_47 -> V_163 , V_47 -> V_49 ,
V_47 -> V_86 ) ;
if ( V_146 )
return V_146 ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ! ( V_99 & ( 1 << V_161 ) ) )
continue;
if ( ( unsigned char * ) V_47 - V_45 == V_159 [ V_161 ] )
V_120 -> V_80 [ V_161 ] = V_159 [ V_161 ] ;
if ( ( unsigned char * ) V_47 - V_45 == V_160 [ V_161 ] ) {
if ( ! F_53 ( V_47 ) )
return - V_162 ;
V_120 -> V_117 [ V_161 ] = V_160 [ V_161 ] ;
}
}
V_47 -> V_111 = ( (struct V_105 ) { 0 , 0 } ) ;
V_47 -> V_127 = 0 ;
return 0 ;
}
static void F_57 ( struct V_44 * V_47 , struct V_69 * V_69 )
{
struct V_164 V_41 ;
struct V_50 * V_57 ;
struct V_103 * V_104 ;
F_30 (ematch, e)
F_39 ( V_104 , V_69 ) ;
V_57 = F_15 ( V_47 ) ;
V_41 . V_69 = V_69 ;
V_41 . V_58 = V_57 -> V_59 . V_60 . V_58 ;
V_41 . V_42 = V_57 -> V_63 ;
V_41 . V_137 = V_138 ;
if ( V_41 . V_58 -> V_139 != NULL )
V_41 . V_58 -> V_139 ( & V_41 ) ;
F_40 ( V_41 . V_58 -> V_140 ) ;
F_52 ( & V_47 -> V_111 ) ;
}
static int
F_58 ( struct V_69 * V_69 , struct V_75 * V_120 , void * V_121 ,
const struct V_165 * V_166 )
{
struct V_150 V_151 = { 0 } ;
struct V_44 * V_78 ;
unsigned int * V_122 ;
unsigned int V_167 ;
int V_14 = 0 ;
V_120 -> V_130 = V_166 -> V_130 ;
V_120 -> V_134 = V_166 -> V_168 ;
for ( V_167 = 0 ; V_167 < V_123 ; V_167 ++ ) {
V_120 -> V_80 [ V_167 ] = 0xFFFFFFFF ;
V_120 -> V_117 [ V_167 ] = 0xFFFFFFFF ;
}
V_122 = F_59 ( V_120 -> V_134 ) ;
if ( ! V_122 )
return - V_155 ;
V_167 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_54 ( V_78 , V_120 , V_121 ,
V_121 + V_166 -> V_130 ,
V_166 -> V_80 ,
V_166 -> V_117 ,
V_166 -> V_99 ) ;
if ( V_14 != 0 )
goto V_169;
if ( V_167 < V_166 -> V_168 )
V_122 [ V_167 ] = ( void * ) V_78 - V_121 ;
++ V_167 ;
if ( strcmp ( F_15 ( V_78 ) -> V_59 . V_128 . V_61 ,
V_62 ) == 0 )
++ V_120 -> V_101 ;
}
V_14 = - V_162 ;
if ( V_167 != V_166 -> V_168 )
goto V_169;
for ( V_167 = 0 ; V_167 < V_123 ; V_167 ++ ) {
if ( ! ( V_166 -> V_99 & ( 1 << V_167 ) ) )
continue;
if ( V_120 -> V_80 [ V_167 ] == 0xFFFFFFFF )
goto V_169;
if ( V_120 -> V_117 [ V_167 ] == 0xFFFFFFFF )
goto V_169;
}
if ( ! F_37 ( V_120 , V_166 -> V_99 , V_121 , V_122 ) ) {
V_14 = - V_170 ;
goto V_169;
}
F_60 ( V_122 ) ;
V_167 = 0 ;
F_18 (iter, entry0, newinfo->size) {
V_14 = F_49 ( V_78 , V_69 , V_166 -> V_61 , V_166 -> V_130 ,
& V_151 ) ;
if ( V_14 != 0 )
break;
++ V_167 ;
}
if ( V_14 != 0 ) {
F_18 (iter, entry0, newinfo->size) {
if ( V_167 -- == 0 )
break;
F_57 ( V_78 , V_69 ) ;
}
return V_14 ;
}
return V_14 ;
V_169:
F_60 ( V_122 ) ;
return V_14 ;
}
static void
F_61 ( const struct V_75 * V_57 ,
struct V_105 V_111 [] )
{
struct V_44 * V_78 ;
unsigned int V_96 ;
unsigned int V_167 ;
F_62 (cpu) {
T_1 * V_51 = & F_63 ( V_171 , V_96 ) ;
V_167 = 0 ;
F_18 (iter, t->entries, t->size) {
struct V_105 * V_172 ;
T_2 V_173 , V_125 ;
unsigned int V_174 ;
V_172 = F_64 ( & V_78 -> V_111 , V_96 ) ;
do {
V_174 = F_65 ( V_51 ) ;
V_173 = V_172 -> V_173 ;
V_125 = V_172 -> V_125 ;
} while ( F_66 ( V_51 , V_174 ) );
F_32 ( V_111 [ V_167 ] , V_173 , V_125 ) ;
++ V_167 ;
}
}
}
static struct V_105 * F_67 ( const struct V_1 * V_89 )
{
unsigned int V_175 ;
struct V_105 * V_111 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
V_175 = sizeof( struct V_105 ) * V_76 -> V_134 ;
V_111 = F_68 ( V_175 ) ;
if ( V_111 == NULL )
return F_69 ( - V_155 ) ;
F_61 ( V_76 , V_111 ) ;
return V_111 ;
}
static int
F_70 ( unsigned int V_176 ,
const struct V_1 * V_89 ,
void T_3 * V_177 )
{
unsigned int V_178 , V_179 ;
const struct V_44 * V_47 ;
struct V_105 * V_111 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
int V_14 = 0 ;
const void * V_180 ;
V_111 = F_67 ( V_89 ) ;
if ( F_45 ( V_111 ) )
return F_46 ( V_111 ) ;
V_180 = V_76 -> V_79 ;
for ( V_178 = 0 , V_179 = 0 ; V_178 < V_176 ; V_178 += V_47 -> V_86 , V_179 ++ ) {
unsigned int V_167 ;
const struct V_103 * V_135 ;
const struct V_50 * V_57 ;
V_47 = (struct V_44 * ) ( V_180 + V_178 ) ;
if ( F_71 ( V_177 + V_178 , V_47 , sizeof( * V_47 ) ) ) {
V_14 = - V_181 ;
goto V_182;
}
if ( F_71 ( V_177 + V_178
+ F_72 ( struct V_44 , V_111 ) ,
& V_111 [ V_179 ] ,
sizeof( V_111 [ V_179 ] ) ) != 0 ) {
V_14 = - V_181 ;
goto V_182;
}
for ( V_167 = sizeof( struct V_44 ) ;
V_167 < V_47 -> V_49 ;
V_167 += V_135 -> V_59 . V_143 ) {
V_135 = ( void * ) V_47 + V_167 ;
if ( F_73 ( V_135 , V_177 + V_178 + V_167 ) ) {
V_14 = - V_181 ;
goto V_182;
}
}
V_57 = F_14 ( V_47 ) ;
if ( F_74 ( V_57 , V_177 + V_178 + V_47 -> V_49 ) ) {
V_14 = - V_181 ;
goto V_182;
}
}
V_182:
F_75 ( V_111 ) ;
return V_14 ;
}
static void F_76 ( void * V_24 , const void * V_20 )
{
int V_115 = * ( V_183 * ) V_20 ;
if ( V_115 > 0 )
V_115 += F_77 ( V_83 , V_115 ) ;
memcpy ( V_24 , & V_115 , sizeof( V_115 ) ) ;
}
static int F_78 ( void T_3 * V_24 , const void * V_20 )
{
V_183 V_184 = * ( int * ) V_20 ;
if ( V_184 > 0 )
V_184 -= F_77 ( V_83 , V_184 ) ;
return F_71 ( V_24 , & V_184 , sizeof( V_184 ) ) ? - V_181 : 0 ;
}
static int F_79 ( const struct V_44 * V_47 ,
const struct V_75 * V_2 ,
const void * V_45 , struct V_75 * V_120 )
{
const struct V_103 * V_104 ;
const struct V_50 * V_57 ;
unsigned int V_185 ;
int V_178 , V_167 , V_14 ;
V_178 = sizeof( struct V_44 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_47 - V_45 ;
F_30 (ematch, e)
V_178 += F_80 ( V_104 -> V_59 . V_60 . V_109 ) ;
V_57 = F_14 ( V_47 ) ;
V_178 += F_81 ( V_57 -> V_59 . V_60 . V_58 ) ;
V_120 -> V_130 -= V_178 ;
V_14 = F_82 ( V_83 , V_185 , V_178 ) ;
if ( V_14 )
return V_14 ;
for ( V_167 = 0 ; V_167 < V_123 ; V_167 ++ ) {
if ( V_2 -> V_80 [ V_167 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_80 [ V_167 ] ) ) )
V_120 -> V_80 [ V_167 ] -= V_178 ;
if ( V_2 -> V_117 [ V_167 ] &&
( V_47 < (struct V_44 * ) ( V_45 + V_2 -> V_117 [ V_167 ] ) ) )
V_120 -> V_117 [ V_167 ] -= V_178 ;
}
return 0 ;
}
static int F_83 ( const struct V_75 * V_2 ,
struct V_75 * V_120 )
{
struct V_44 * V_78 ;
const void * V_180 ;
int V_14 ;
if ( ! V_120 || ! V_2 )
return - V_162 ;
memcpy ( V_120 , V_2 , F_72 ( struct V_75 , V_79 ) ) ;
V_120 -> V_187 = 0 ;
V_180 = V_2 -> V_79 ;
F_84 ( V_83 , V_2 -> V_134 ) ;
F_18 (iter, loc_cpu_entry, info->size) {
V_14 = F_79 ( V_78 , V_2 , V_180 , V_120 ) ;
if ( V_14 != 0 )
return V_14 ;
}
return 0 ;
}
static int F_85 ( struct V_69 * V_69 , void T_3 * V_128 ,
const int * V_112 , int V_188 )
{
char V_61 [ V_189 ] ;
struct V_1 * V_57 ;
int V_14 ;
if ( * V_112 != sizeof( struct V_190 ) )
return - V_162 ;
if ( F_86 ( V_61 , V_128 , sizeof( V_61 ) ) != 0 )
return - V_181 ;
V_61 [ V_189 - 1 ] = '\0' ;
#ifdef F_87
if ( V_188 )
F_88 ( V_83 ) ;
#endif
V_57 = F_89 ( F_90 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( V_57 ) {
struct V_190 V_2 ;
const struct V_75 * V_76 = V_57 -> V_76 ;
#ifdef F_87
struct V_75 V_172 ;
if ( V_188 ) {
V_14 = F_83 ( V_76 , & V_172 ) ;
F_91 ( V_83 ) ;
V_76 = & V_172 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_99 = V_57 -> V_99 ;
memcpy ( V_2 . V_80 , V_76 -> V_80 ,
sizeof( V_2 . V_80 ) ) ;
memcpy ( V_2 . V_117 , V_76 -> V_117 ,
sizeof( V_2 . V_117 ) ) ;
V_2 . V_168 = V_76 -> V_134 ;
V_2 . V_130 = V_76 -> V_130 ;
strcpy ( V_2 . V_61 , V_61 ) ;
if ( F_71 ( V_128 , & V_2 , * V_112 ) != 0 )
V_14 = - V_181 ;
else
V_14 = 0 ;
F_92 ( V_57 ) ;
F_40 ( V_57 -> V_140 ) ;
} else
V_14 = - V_191 ;
#ifdef F_87
if ( V_188 )
F_93 ( V_83 ) ;
#endif
return V_14 ;
}
static int
F_94 ( struct V_69 * V_69 , struct V_192 T_3 * V_193 ,
const int * V_112 )
{
int V_14 ;
struct V_192 V_194 ;
struct V_1 * V_57 ;
if ( * V_112 < sizeof( V_194 ) )
return - V_162 ;
if ( F_86 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_112 != sizeof( struct V_192 ) + V_194 . V_130 )
return - V_162 ;
V_194 . V_61 [ sizeof( V_194 . V_61 ) - 1 ] = '\0' ;
V_57 = F_90 ( V_69 , V_83 , V_194 . V_61 ) ;
if ( V_57 ) {
struct V_75 * V_76 = V_57 -> V_76 ;
if ( V_194 . V_130 == V_76 -> V_130 )
V_14 = F_70 ( V_76 -> V_130 ,
V_57 , V_193 -> V_195 ) ;
else
V_14 = - V_196 ;
F_40 ( V_57 -> V_140 ) ;
F_92 ( V_57 ) ;
} else
V_14 = - V_191 ;
return V_14 ;
}
static int
F_95 ( struct V_69 * V_69 , const char * V_61 , unsigned int V_99 ,
struct V_75 * V_120 , unsigned int V_197 ,
void T_3 * V_198 )
{
int V_14 ;
struct V_1 * V_57 ;
struct V_75 * V_199 ;
struct V_105 * V_111 ;
struct V_44 * V_78 ;
V_14 = 0 ;
V_111 = F_68 ( V_197 * sizeof( struct V_105 ) ) ;
if ( ! V_111 ) {
V_14 = - V_155 ;
goto V_73;
}
V_57 = F_89 ( F_90 ( V_69 , V_83 , V_61 ) ,
L_3 , V_61 ) ;
if ( ! V_57 ) {
V_14 = - V_191 ;
goto V_200;
}
if ( V_99 != V_57 -> V_99 ) {
V_14 = - V_162 ;
goto V_201;
}
V_199 = F_96 ( V_57 , V_197 , V_120 , & V_14 ) ;
if ( ! V_199 )
goto V_201;
if ( ( V_199 -> V_134 > V_199 -> V_187 ) ||
( V_120 -> V_134 <= V_199 -> V_187 ) )
F_40 ( V_57 -> V_140 ) ;
if ( ( V_199 -> V_134 > V_199 -> V_187 ) &&
( V_120 -> V_134 <= V_199 -> V_187 ) )
F_40 ( V_57 -> V_140 ) ;
F_61 ( V_199 , V_111 ) ;
F_18 (iter, oldinfo->entries, oldinfo->size)
F_57 ( V_78 , V_69 ) ;
F_97 ( V_199 ) ;
if ( F_71 ( V_198 , V_111 ,
sizeof( struct V_105 ) * V_197 ) != 0 ) {
F_98 ( L_4 ) ;
}
F_75 ( V_111 ) ;
F_92 ( V_57 ) ;
return V_14 ;
V_201:
F_40 ( V_57 -> V_140 ) ;
F_92 ( V_57 ) ;
V_200:
F_75 ( V_111 ) ;
V_73:
return V_14 ;
}
static int
F_99 ( struct V_69 * V_69 , const void T_3 * V_128 , unsigned int V_112 )
{
int V_14 ;
struct V_165 V_172 ;
struct V_75 * V_120 ;
void * V_180 ;
struct V_44 * V_78 ;
if ( F_86 ( & V_172 , V_128 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_105 ) )
return - V_155 ;
if ( V_172 . V_197 == 0 )
return - V_162 ;
V_172 . V_61 [ sizeof( V_172 . V_61 ) - 1 ] = 0 ;
V_120 = F_100 ( V_172 . V_130 ) ;
if ( ! V_120 )
return - V_155 ;
V_180 = V_120 -> V_79 ;
if ( F_86 ( V_180 , V_128 + sizeof( V_172 ) ,
V_172 . V_130 ) != 0 ) {
V_14 = - V_181 ;
goto V_203;
}
V_14 = F_58 ( V_69 , V_120 , V_180 , & V_172 ) ;
if ( V_14 != 0 )
goto V_203;
V_14 = F_95 ( V_69 , V_172 . V_61 , V_172 . V_99 , V_120 ,
V_172 . V_197 , V_172 . V_111 ) ;
if ( V_14 )
goto V_204;
return 0 ;
V_204:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_78 , V_69 ) ;
V_203:
F_97 ( V_120 ) ;
return V_14 ;
}
static int
F_101 ( struct V_69 * V_69 , const void T_3 * V_128 , unsigned int V_112 ,
int V_188 )
{
unsigned int V_167 ;
struct V_205 V_172 ;
struct V_105 * V_206 ;
struct V_1 * V_57 ;
const struct V_75 * V_76 ;
int V_14 = 0 ;
struct V_44 * V_78 ;
unsigned int V_98 ;
V_206 = F_102 ( V_128 , V_112 , & V_172 , V_188 ) ;
if ( F_45 ( V_206 ) )
return F_46 ( V_206 ) ;
V_57 = F_90 ( V_69 , V_83 , V_172 . V_61 ) ;
if ( ! V_57 ) {
V_14 = - V_191 ;
goto free;
}
F_24 () ;
V_76 = V_57 -> V_76 ;
if ( V_76 -> V_134 != V_172 . V_197 ) {
V_14 = - V_162 ;
goto V_207;
}
V_167 = 0 ;
V_98 = F_25 () ;
F_18 (iter, private->entries, private->size) {
struct V_105 * V_172 ;
V_172 = F_31 ( & V_78 -> V_111 ) ;
F_32 ( * V_172 , V_206 [ V_167 ] . V_173 , V_206 [ V_167 ] . V_125 ) ;
++ V_167 ;
}
F_35 ( V_98 ) ;
V_207:
F_36 () ;
F_92 ( V_57 ) ;
F_40 ( V_57 -> V_140 ) ;
free:
F_75 ( V_206 ) ;
return V_14 ;
}
static int
F_103 ( struct V_44 * V_47 , void T_3 * * V_208 ,
unsigned int * V_130 , struct V_105 * V_111 ,
unsigned int V_167 )
{
struct V_50 * V_57 ;
struct V_186 T_3 * V_209 ;
T_4 V_49 , V_86 ;
T_5 V_210 ;
const struct V_103 * V_104 ;
int V_14 = 0 ;
V_210 = * V_130 ;
V_209 = (struct V_186 T_3 * ) * V_208 ;
if ( F_71 ( V_209 , V_47 , sizeof( struct V_44 ) ) != 0 ||
F_71 ( & V_209 -> V_111 , & V_111 [ V_167 ] ,
sizeof( V_111 [ V_167 ] ) ) != 0 )
return - V_181 ;
* V_208 += sizeof( struct V_186 ) ;
* V_130 -= sizeof( struct V_44 ) - sizeof( struct V_186 ) ;
F_30 (ematch, e) {
V_14 = F_104 ( V_104 , V_208 , V_130 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_49 = V_47 -> V_49 - ( V_210 - * V_130 ) ;
V_57 = F_15 ( V_47 ) ;
V_14 = F_105 ( V_57 , V_208 , V_130 ) ;
if ( V_14 )
return V_14 ;
V_86 = V_47 -> V_86 - ( V_210 - * V_130 ) ;
if ( F_106 ( V_49 , & V_209 -> V_49 ) != 0 ||
F_106 ( V_86 , & V_209 -> V_86 ) != 0 )
return - V_181 ;
return 0 ;
}
static int
F_107 ( struct V_103 * V_135 ,
const struct V_9 * V_16 ,
int * V_130 )
{
struct V_144 * V_109 ;
V_109 = F_44 ( V_138 , V_135 -> V_59 . V_128 . V_61 ,
V_135 -> V_59 . V_128 . V_145 ) ;
if ( F_45 ( V_109 ) )
return F_46 ( V_109 ) ;
V_135 -> V_59 . V_60 . V_109 = V_109 ;
* V_130 += F_80 ( V_109 ) ;
return 0 ;
}
static void F_108 ( struct V_186 * V_47 )
{
struct V_50 * V_57 ;
struct V_103 * V_104 ;
F_30 (ematch, e)
F_40 ( V_104 -> V_59 . V_60 . V_109 -> V_140 ) ;
V_57 = F_109 ( V_47 ) ;
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
}
static int
F_110 ( struct V_186 * V_47 ,
struct V_75 * V_120 ,
unsigned int * V_130 ,
const unsigned char * V_45 ,
const unsigned char * V_158 )
{
struct V_103 * V_104 ;
struct V_50 * V_57 ;
struct V_152 * V_58 ;
unsigned int V_185 ;
unsigned int V_153 ;
int V_14 , V_178 ;
if ( ( unsigned long ) V_47 % F_55 ( struct V_186 ) != 0 ||
( unsigned char * ) V_47 + sizeof( struct V_186 ) >= V_158 ||
( unsigned char * ) V_47 + V_47 -> V_86 > V_158 )
return - V_162 ;
if ( V_47 -> V_86 < sizeof( struct V_186 ) +
sizeof( struct V_211 ) )
return - V_162 ;
if ( ! F_9 ( & V_47 -> V_16 ) )
return - V_162 ;
V_14 = F_111 ( V_47 , V_47 -> V_163 ,
V_47 -> V_49 , V_47 -> V_86 ) ;
if ( V_14 )
return V_14 ;
V_178 = sizeof( struct V_44 ) - sizeof( struct V_186 ) ;
V_185 = ( void * ) V_47 - ( void * ) V_45 ;
V_153 = 0 ;
F_30 (ematch, e) {
V_14 = F_107 ( V_104 , & V_47 -> V_16 , & V_178 ) ;
if ( V_14 != 0 )
goto V_212;
++ V_153 ;
}
V_57 = F_109 ( V_47 ) ;
V_58 = F_51 ( V_138 , V_57 -> V_59 . V_128 . V_61 ,
V_57 -> V_59 . V_128 . V_145 ) ;
if ( F_45 ( V_58 ) ) {
V_14 = F_46 ( V_58 ) ;
goto V_212;
}
V_57 -> V_59 . V_60 . V_58 = V_58 ;
V_178 += F_81 ( V_58 ) ;
* V_130 += V_178 ;
V_14 = F_82 ( V_83 , V_185 , V_178 ) ;
if ( V_14 )
goto V_73;
return 0 ;
V_73:
F_40 ( V_57 -> V_59 . V_60 . V_58 -> V_140 ) ;
V_212:
F_30 (ematch, e) {
if ( V_153 -- == 0 )
break;
F_40 ( V_104 -> V_59 . V_60 . V_109 -> V_140 ) ;
}
return V_14 ;
}
static void
F_112 ( struct V_186 * V_47 , void * * V_208 ,
unsigned int * V_130 ,
struct V_75 * V_120 , unsigned char * V_45 )
{
struct V_50 * V_57 ;
struct V_44 * V_213 ;
unsigned int V_210 ;
int V_161 ;
struct V_103 * V_104 ;
V_210 = * V_130 ;
V_213 = (struct V_44 * ) * V_208 ;
memcpy ( V_213 , V_47 , sizeof( struct V_44 ) ) ;
memcpy ( & V_213 -> V_111 , & V_47 -> V_111 , sizeof( V_47 -> V_111 ) ) ;
* V_208 += sizeof( struct V_44 ) ;
* V_130 += sizeof( struct V_44 ) - sizeof( struct V_186 ) ;
F_30 (ematch, e)
F_113 ( V_104 , V_208 , V_130 ) ;
V_213 -> V_49 = V_47 -> V_49 - ( V_210 - * V_130 ) ;
V_57 = F_109 ( V_47 ) ;
F_114 ( V_57 , V_208 , V_130 ) ;
V_213 -> V_86 = V_47 -> V_86 - ( V_210 - * V_130 ) ;
for ( V_161 = 0 ; V_161 < V_123 ; V_161 ++ ) {
if ( ( unsigned char * ) V_213 - V_45 < V_120 -> V_80 [ V_161 ] )
V_120 -> V_80 [ V_161 ] -= V_210 - * V_130 ;
if ( ( unsigned char * ) V_213 - V_45 < V_120 -> V_117 [ V_161 ] )
V_120 -> V_117 [ V_161 ] -= V_210 - * V_130 ;
}
}
static int
F_115 ( struct V_69 * V_69 ,
struct V_75 * * V_214 ,
void * * V_215 ,
const struct V_216 * V_217 )
{
unsigned int V_167 , V_153 ;
struct V_75 * V_120 , * V_2 ;
void * V_124 , * V_121 , * V_218 ;
struct V_186 * V_219 ;
struct V_165 V_166 ;
unsigned int V_130 ;
int V_14 = 0 ;
V_2 = * V_214 ;
V_121 = * V_215 ;
V_130 = V_217 -> V_130 ;
V_2 -> V_134 = V_217 -> V_168 ;
V_153 = 0 ;
F_88 ( V_83 ) ;
F_84 ( V_83 , V_217 -> V_168 ) ;
F_18 (iter0, entry0, compatr->size) {
V_14 = F_110 ( V_219 , V_2 , & V_130 ,
V_121 ,
V_121 + V_217 -> V_130 ) ;
if ( V_14 != 0 )
goto V_220;
++ V_153 ;
}
V_14 = - V_162 ;
if ( V_153 != V_217 -> V_168 )
goto V_220;
V_14 = - V_155 ;
V_120 = F_100 ( V_130 ) ;
if ( ! V_120 )
goto V_220;
V_120 -> V_134 = V_217 -> V_168 ;
for ( V_167 = 0 ; V_167 < V_123 ; V_167 ++ ) {
V_120 -> V_80 [ V_167 ] = V_217 -> V_80 [ V_167 ] ;
V_120 -> V_117 [ V_167 ] = V_217 -> V_117 [ V_167 ] ;
}
V_218 = V_120 -> V_79 ;
V_124 = V_218 ;
V_130 = V_217 -> V_130 ;
F_18 (iter0, entry0, compatr->size)
F_112 ( V_219 , & V_124 , & V_130 ,
V_120 , V_218 ) ;
F_91 ( V_83 ) ;
F_93 ( V_83 ) ;
memcpy ( & V_166 , V_217 , sizeof( * V_217 ) ) ;
for ( V_167 = 0 ; V_167 < V_123 ; V_167 ++ ) {
V_166 . V_80 [ V_167 ] = V_120 -> V_80 [ V_167 ] ;
V_166 . V_117 [ V_167 ] = V_120 -> V_117 [ V_167 ] ;
}
V_166 . V_197 = 0 ;
V_166 . V_111 = NULL ;
V_166 . V_130 = V_120 -> V_130 ;
V_14 = F_58 ( V_69 , V_120 , V_218 , & V_166 ) ;
if ( V_14 )
goto V_203;
* V_214 = V_120 ;
* V_215 = V_218 ;
F_97 ( V_2 ) ;
return 0 ;
V_203:
F_97 ( V_120 ) ;
return V_14 ;
V_220:
F_91 ( V_83 ) ;
F_93 ( V_83 ) ;
F_18 (iter0, entry0, compatr->size) {
if ( V_153 -- == 0 )
break;
F_108 ( V_219 ) ;
}
return V_14 ;
}
static int
F_116 ( struct V_69 * V_69 , void T_3 * V_128 , unsigned int V_112 )
{
int V_14 ;
struct V_216 V_172 ;
struct V_75 * V_120 ;
void * V_180 ;
struct V_44 * V_78 ;
if ( F_86 ( & V_172 , V_128 , sizeof( V_172 ) ) != 0 )
return - V_181 ;
if ( V_172 . V_197 >= V_202 / sizeof( struct V_105 ) )
return - V_155 ;
if ( V_172 . V_197 == 0 )
return - V_162 ;
V_172 . V_61 [ sizeof( V_172 . V_61 ) - 1 ] = 0 ;
V_120 = F_100 ( V_172 . V_130 ) ;
if ( ! V_120 )
return - V_155 ;
V_180 = V_120 -> V_79 ;
if ( F_86 ( V_180 , V_128 + sizeof( V_172 ) ,
V_172 . V_130 ) != 0 ) {
V_14 = - V_181 ;
goto V_203;
}
V_14 = F_115 ( V_69 , & V_120 , & V_180 , & V_172 ) ;
if ( V_14 != 0 )
goto V_203;
V_14 = F_95 ( V_69 , V_172 . V_61 , V_172 . V_99 , V_120 ,
V_172 . V_197 , F_117 ( V_172 . V_111 ) ) ;
if ( V_14 )
goto V_204;
return 0 ;
V_204:
F_18 (iter, loc_cpu_entry, newinfo->size)
F_57 ( V_78 , V_69 ) ;
V_203:
F_97 ( V_120 ) ;
return V_14 ;
}
static int
F_118 ( struct V_221 * V_222 , int V_223 , void T_3 * V_128 ,
unsigned int V_112 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_116 ( F_120 ( V_222 ) , V_128 , V_112 ) ;
break;
case V_228 :
V_14 = F_101 ( F_120 ( V_222 ) , V_128 , V_112 , 1 ) ;
break;
default:
V_14 = - V_162 ;
}
return V_14 ;
}
static int
F_121 ( unsigned int V_176 , struct V_1 * V_89 ,
void T_3 * V_177 )
{
struct V_105 * V_111 ;
const struct V_75 * V_76 = V_89 -> V_76 ;
void T_3 * V_124 ;
unsigned int V_130 ;
int V_14 = 0 ;
unsigned int V_167 = 0 ;
struct V_44 * V_78 ;
V_111 = F_67 ( V_89 ) ;
if ( F_45 ( V_111 ) )
return F_46 ( V_111 ) ;
V_124 = V_177 ;
V_130 = V_176 ;
F_18 (iter, private->entries, total_size) {
V_14 = F_103 ( V_78 , & V_124 ,
& V_130 , V_111 , V_167 ++ ) ;
if ( V_14 != 0 )
break;
}
F_75 ( V_111 ) ;
return V_14 ;
}
static int
F_122 ( struct V_69 * V_69 , struct V_229 T_3 * V_193 ,
int * V_112 )
{
int V_14 ;
struct V_229 V_194 ;
struct V_1 * V_57 ;
if ( * V_112 < sizeof( V_194 ) )
return - V_162 ;
if ( F_86 ( & V_194 , V_193 , sizeof( V_194 ) ) != 0 )
return - V_181 ;
if ( * V_112 != sizeof( struct V_229 ) + V_194 . V_130 )
return - V_162 ;
V_194 . V_61 [ sizeof( V_194 . V_61 ) - 1 ] = '\0' ;
F_88 ( V_83 ) ;
V_57 = F_90 ( V_69 , V_83 , V_194 . V_61 ) ;
if ( V_57 ) {
const struct V_75 * V_76 = V_57 -> V_76 ;
struct V_75 V_2 ;
V_14 = F_83 ( V_76 , & V_2 ) ;
if ( ! V_14 && V_194 . V_130 == V_2 . V_130 )
V_14 = F_121 ( V_76 -> V_130 ,
V_57 , V_193 -> V_195 ) ;
else if ( ! V_14 )
V_14 = - V_196 ;
F_91 ( V_83 ) ;
F_40 ( V_57 -> V_140 ) ;
F_92 ( V_57 ) ;
} else
V_14 = - V_191 ;
F_93 ( V_83 ) ;
return V_14 ;
}
static int
F_123 ( struct V_221 * V_222 , int V_223 , void T_3 * V_128 , int * V_112 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_85 ( F_120 ( V_222 ) , V_128 , V_112 , 1 ) ;
break;
case V_231 :
V_14 = F_122 ( F_120 ( V_222 ) , V_128 , V_112 ) ;
break;
default:
V_14 = F_124 ( V_222 , V_223 , V_128 , V_112 ) ;
}
return V_14 ;
}
static int
F_125 ( struct V_221 * V_222 , int V_223 , void T_3 * V_128 , unsigned int V_112 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_227 :
V_14 = F_99 ( F_120 ( V_222 ) , V_128 , V_112 ) ;
break;
case V_228 :
V_14 = F_101 ( F_120 ( V_222 ) , V_128 , V_112 , 0 ) ;
break;
default:
V_14 = - V_162 ;
}
return V_14 ;
}
static int
F_124 ( struct V_221 * V_222 , int V_223 , void T_3 * V_128 , int * V_112 )
{
int V_14 ;
if ( ! F_119 ( F_120 ( V_222 ) -> V_224 , V_225 ) )
return - V_226 ;
switch ( V_223 ) {
case V_230 :
V_14 = F_85 ( F_120 ( V_222 ) , V_128 , V_112 , 0 ) ;
break;
case V_231 :
V_14 = F_94 ( F_120 ( V_222 ) , V_128 , V_112 ) ;
break;
case V_232 :
case V_233 : {
struct V_234 V_235 ;
int V_58 ;
if ( * V_112 != sizeof( V_235 ) ) {
V_14 = - V_162 ;
break;
}
if ( F_86 ( & V_235 , V_128 , sizeof( V_235 ) ) != 0 ) {
V_14 = - V_181 ;
break;
}
V_235 . V_61 [ sizeof( V_235 . V_61 ) - 1 ] = 0 ;
if ( V_223 == V_233 )
V_58 = 1 ;
else
V_58 = 0 ;
F_89 ( F_126 ( V_83 , V_235 . V_61 ,
V_235 . V_145 ,
V_58 , & V_14 ) ,
L_5 , V_235 . V_61 ) ;
break;
}
default:
V_14 = - V_162 ;
}
return V_14 ;
}
static void F_127 ( struct V_69 * V_69 , struct V_1 * V_89 )
{
struct V_75 * V_76 ;
void * V_180 ;
struct V_236 * V_237 = V_89 -> V_140 ;
struct V_44 * V_78 ;
V_76 = F_128 ( V_89 ) ;
V_180 = V_76 -> V_79 ;
F_18 (iter, loc_cpu_entry, private->size)
F_57 ( V_78 , V_69 ) ;
if ( V_76 -> V_134 > V_76 -> V_187 )
F_40 ( V_237 ) ;
F_97 ( V_76 ) ;
}
int F_129 ( struct V_69 * V_69 , const struct V_1 * V_89 ,
const struct V_165 * V_166 ,
const struct V_238 * V_239 ,
struct V_1 * * V_240 )
{
int V_14 ;
struct V_75 * V_120 ;
struct V_75 V_241 = { 0 } ;
void * V_180 ;
struct V_1 * V_242 ;
V_120 = F_100 ( V_166 -> V_130 ) ;
if ( ! V_120 )
return - V_155 ;
V_180 = V_120 -> V_79 ;
memcpy ( V_180 , V_166 -> V_79 , V_166 -> V_130 ) ;
V_14 = F_58 ( V_69 , V_120 , V_180 , V_166 ) ;
if ( V_14 != 0 )
goto V_169;
V_242 = F_130 ( V_69 , V_89 , & V_241 , V_120 ) ;
if ( F_45 ( V_242 ) ) {
V_14 = F_46 ( V_242 ) ;
goto V_169;
}
F_131 ( * V_240 , V_242 ) ;
V_14 = F_132 ( V_69 , V_239 , F_133 ( V_89 -> V_99 ) ) ;
if ( V_14 != 0 ) {
F_127 ( V_69 , V_242 ) ;
* V_240 = NULL ;
}
return V_14 ;
V_169:
F_97 ( V_120 ) ;
return V_14 ;
}
void F_134 ( struct V_69 * V_69 , struct V_1 * V_89 ,
const struct V_238 * V_239 )
{
F_135 ( V_69 , V_239 , F_133 ( V_89 -> V_99 ) ) ;
F_127 ( V_69 , V_89 ) ;
}
static inline bool
F_136 ( T_6 V_243 , T_6 V_244 , T_6 V_245 ,
T_6 type , T_6 V_246 ,
bool V_247 )
{
return ( type == V_243 && V_246 >= V_244 && V_246 <= V_245 )
^ V_247 ;
}
static bool
F_137 ( const struct V_5 * V_6 , struct V_40 * V_41 )
{
const struct V_248 * V_249 ;
struct V_248 V_250 ;
const struct V_251 * V_252 = V_41 -> V_110 ;
if ( V_41 -> V_12 != 0 )
return false ;
V_249 = F_138 ( V_6 , V_41 -> V_107 , sizeof( V_250 ) , & V_250 ) ;
if ( V_249 == NULL ) {
V_41 -> V_13 = true ;
return false ;
}
return F_136 ( V_252 -> type ,
V_252 -> V_246 [ 0 ] ,
V_252 -> V_246 [ 1 ] ,
V_249 -> V_253 , V_249 -> V_254 ,
! ! ( V_252 -> V_36 & V_255 ) ) ;
}
static int F_139 ( const struct V_141 * V_41 )
{
const struct V_251 * V_252 = V_41 -> V_110 ;
return ( V_252 -> V_36 & ~ V_255 ) ? - V_162 : 0 ;
}
static int T_7 F_140 ( struct V_69 * V_69 )
{
return F_141 ( V_69 , V_138 ) ;
}
static void T_8 F_142 ( struct V_69 * V_69 )
{
F_143 ( V_69 , V_138 ) ;
}
static int T_9 F_144 ( void )
{
int V_14 ;
V_14 = F_145 ( & V_256 ) ;
if ( V_14 < 0 )
goto V_257;
V_14 = F_146 ( V_258 , F_147 ( V_258 ) ) ;
if ( V_14 < 0 )
goto V_259;
V_14 = F_148 ( V_260 , F_147 ( V_260 ) ) ;
if ( V_14 < 0 )
goto V_261;
V_14 = F_149 ( & V_262 ) ;
if ( V_14 < 0 )
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
return V_14 ;
}
static void T_10 F_154 ( void )
{
F_155 ( & V_262 ) ;
F_151 ( V_260 , F_147 ( V_260 ) ) ;
F_152 ( V_258 , F_147 ( V_258 ) ) ;
F_153 ( & V_256 ) ;
}
