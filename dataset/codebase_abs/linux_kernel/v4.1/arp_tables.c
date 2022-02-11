void * F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , V_4 ) ;
}
static inline int F_3 ( const struct V_5 * V_6 ,
const char * V_7 , int V_8 )
{
int V_9 , V_10 ;
if ( V_8 > V_11 )
V_8 = V_11 ;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_10 |= ( V_7 [ V_9 ] ^ V_6 -> V_12 [ V_9 ] ) & V_6 -> V_13 [ V_9 ] ;
return V_10 != 0 ;
}
static unsigned long F_4 ( const char * V_14 , const char * V_15 , const char * V_16 )
{
#ifdef F_5
unsigned long V_10 = F_6 ( V_14 , V_15 , V_16 ) ;
#else
unsigned long V_10 = 0 ;
const T_1 * V_17 = ( const T_1 * ) V_14 ;
const T_1 * V_18 = ( const T_1 * ) V_15 ;
const T_1 * V_13 = ( const T_1 * ) V_16 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_19 / sizeof( T_1 ) ; V_9 ++ )
V_10 |= ( V_17 [ V_9 ] ^ V_18 [ V_9 ] ) & V_13 [ V_9 ] ;
#endif
return V_10 ;
}
static inline int F_7 ( const struct V_20 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 ,
const char * V_24 ,
const struct V_25 * V_26 )
{
const char * V_27 = ( char * ) ( V_20 + 1 ) ;
const char * V_28 , * V_29 ;
T_2 V_30 , V_31 ;
long V_10 ;
#define F_8 ( bool , T_3 ) ((bool) ^ !!(arpinfo->invflags & (invflg)))
if ( F_8 ( ( V_20 -> V_32 & V_26 -> V_33 ) != V_26 -> V_34 ,
V_35 ) ) {
F_9 ( L_1 ) ;
F_9 ( L_2 ,
V_20 -> V_32 , V_26 -> V_34 , V_26 -> V_33 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_36 & V_26 -> V_37 ) != V_26 -> V_38 ,
V_39 ) ) {
F_9 ( L_3 ) ;
F_9 ( L_4 ,
V_20 -> V_36 , V_26 -> V_38 , V_26 -> V_37 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_40 & V_26 -> V_41 ) != V_26 -> V_42 ,
V_43 ) ) {
F_9 ( L_5 ) ;
F_9 ( L_6 ,
V_20 -> V_40 , V_26 -> V_42 , V_26 -> V_41 ) ;
return 0 ;
}
if ( F_8 ( ( V_20 -> V_44 & V_26 -> V_45 ) != V_26 -> V_46 ,
V_47 ) ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ,
V_20 -> V_44 , V_26 -> V_46 , V_26 -> V_45 ) ;
return 0 ;
}
V_28 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_30 , V_27 , sizeof( V_49 ) ) ;
V_27 += sizeof( V_49 ) ;
V_29 = V_27 ;
V_27 += V_22 -> V_48 ;
memcpy ( & V_31 , V_27 , sizeof( V_49 ) ) ;
if ( F_8 ( F_3 ( & V_26 -> V_28 , V_28 , V_22 -> V_48 ) ,
V_50 ) ||
F_8 ( F_3 ( & V_26 -> V_29 , V_29 , V_22 -> V_48 ) ,
V_51 ) ) {
F_9 ( L_9 ) ;
return 0 ;
}
if ( F_8 ( ( V_30 & V_26 -> V_52 . V_53 ) != V_26 -> V_54 . V_53 ,
V_55 ) ||
F_8 ( ( ( V_31 & V_26 -> V_56 . V_53 ) != V_26 -> V_57 . V_53 ) ,
V_58 ) ) {
F_9 ( L_10 ) ;
F_9 ( L_11 ,
& V_30 ,
& V_26 -> V_52 . V_53 ,
& V_26 -> V_54 . V_53 ,
V_26 -> V_59 & V_55 ? L_12 : L_13 ) ;
F_9 ( L_14 ,
& V_31 ,
& V_26 -> V_56 . V_53 ,
& V_26 -> V_57 . V_53 ,
V_26 -> V_59 & V_58 ? L_12 : L_13 ) ;
return 0 ;
}
V_10 = F_4 ( V_23 , V_26 -> V_60 , V_26 -> V_61 ) ;
if ( F_8 ( V_10 != 0 , V_62 ) ) {
F_9 ( L_15 ,
V_23 , V_26 -> V_60 ,
V_26 -> V_59 & V_62 ? L_12 : L_13 ) ;
return 0 ;
}
V_10 = F_4 ( V_24 , V_26 -> V_63 , V_26 -> V_64 ) ;
if ( F_8 ( V_10 != 0 , V_65 ) ) {
F_9 ( L_16 ,
V_24 , V_26 -> V_63 ,
V_26 -> V_59 & V_65 ? L_12 : L_13 ) ;
return 0 ;
}
return 1 ;
#undef F_8
}
static inline int F_10 ( const struct V_25 * V_66 )
{
if ( V_66 -> V_67 & ~ V_68 ) {
F_11 ( L_17 ,
V_66 -> V_67 & ~ V_68 ) ;
return 0 ;
}
if ( V_66 -> V_59 & ~ V_69 ) {
F_11 ( L_18 ,
V_66 -> V_59 & ~ V_69 ) ;
return 0 ;
}
return 1 ;
}
static unsigned int
F_12 ( struct V_70 * V_71 , const struct V_72 * V_73 )
{
F_13 ( L_19 ,
( const char * ) V_73 -> V_74 ) ;
return V_75 ;
}
static inline const struct V_76 *
F_14 ( const struct V_77 * V_78 )
{
return F_15 ( (struct V_77 * ) V_78 ) ;
}
static inline struct V_77 *
F_16 ( const void * V_79 , unsigned int V_80 )
{
return (struct V_77 * ) ( V_79 + V_80 ) ;
}
unsigned int F_17 ( struct V_70 * V_71 ,
unsigned int V_81 ,
const struct V_82 * V_83 ,
struct V_1 * V_84 )
{
static const char V_85 [ V_19 ] V_86 ( ( F_18 ( sizeof( long ) ) ) ) ;
unsigned int V_87 = V_75 ;
const struct V_20 * V_66 ;
struct V_77 * V_78 , * V_88 ;
const char * V_23 , * V_24 ;
void * V_89 ;
const struct V_90 * V_91 ;
struct V_72 V_92 ;
unsigned int V_93 ;
if ( ! F_19 ( V_71 , F_20 ( V_71 -> V_22 ) ) )
return V_75 ;
V_23 = V_83 -> V_94 ? V_83 -> V_94 -> V_95 : V_85 ;
V_24 = V_83 -> V_96 ? V_83 -> V_96 -> V_95 : V_85 ;
F_21 () ;
V_93 = F_22 () ;
V_91 = V_84 -> V_91 ;
F_23 () ;
V_89 = V_91 -> V_97 [ F_24 () ] ;
V_78 = F_16 ( V_89 , V_91 -> V_98 [ V_81 ] ) ;
V_88 = F_16 ( V_89 , V_91 -> V_99 [ V_81 ] ) ;
V_92 . V_94 = V_83 -> V_94 ;
V_92 . V_96 = V_83 -> V_96 ;
V_92 . V_100 = V_81 ;
V_92 . V_101 = V_102 ;
V_92 . V_103 = false ;
V_66 = F_25 ( V_71 ) ;
do {
const struct V_76 * V_104 ;
if ( ! F_7 ( V_66 , V_71 -> V_22 , V_23 , V_24 , & V_78 -> V_66 ) ) {
V_78 = F_26 ( V_78 ) ;
continue;
}
F_27 ( V_78 -> V_105 , F_20 ( V_71 -> V_22 ) , 1 ) ;
V_104 = F_14 ( V_78 ) ;
if ( ! V_104 -> V_106 . V_107 . V_108 -> V_108 ) {
int V_109 ;
V_109 = ( (struct V_110 * ) V_104 ) -> V_87 ;
if ( V_109 < 0 ) {
if ( V_109 != V_111 ) {
V_87 = ( unsigned int ) ( - V_109 ) - 1 ;
break;
}
V_78 = V_88 ;
V_88 = F_16 ( V_89 , V_88 -> V_112 ) ;
continue;
}
if ( V_89 + V_109
!= F_26 ( V_78 ) ) {
struct V_77 * V_113 = F_26 ( V_78 ) ;
V_113 -> V_112 = ( void * ) V_88 - V_89 ;
V_88 = V_113 ;
}
V_78 = F_16 ( V_89 , V_109 ) ;
continue;
}
V_92 . V_108 = V_104 -> V_106 . V_107 . V_108 ;
V_92 . V_74 = V_104 -> V_114 ;
V_87 = V_104 -> V_106 . V_107 . V_108 -> V_108 ( V_71 , & V_92 ) ;
V_66 = F_25 ( V_71 ) ;
if ( V_87 == V_115 )
V_78 = F_26 ( V_78 ) ;
else
break;
} while ( ! V_92 . V_103 );
F_28 ( V_93 ) ;
F_29 () ;
if ( V_92 . V_103 )
return V_75 ;
else
return V_87 ;
}
static inline bool F_30 ( const struct V_25 * V_66 )
{
static const struct V_25 V_116 ;
return memcmp ( V_66 , & V_116 , sizeof( V_116 ) ) == 0 ;
}
static int F_31 ( const struct V_90 * V_117 ,
unsigned int V_118 , void * V_119 )
{
unsigned int V_81 ;
for ( V_81 = 0 ; V_81 < V_120 ; V_81 ++ ) {
unsigned int V_121 = V_117 -> V_98 [ V_81 ] ;
struct V_77 * V_78
= (struct V_77 * ) ( V_119 + V_121 ) ;
if ( ! ( V_118 & ( 1 << V_81 ) ) )
continue;
V_78 -> V_105 . V_122 = V_121 ;
for (; ; ) {
const struct V_110 * V_104
= ( void * ) F_14 ( V_78 ) ;
int V_123 = V_78 -> V_112 & ( 1 << V_81 ) ;
if ( V_78 -> V_112 & ( 1 << V_120 ) ) {
F_32 ( L_20 ,
V_81 , V_121 , V_78 -> V_112 ) ;
return 0 ;
}
V_78 -> V_112
|= ( ( 1 << V_81 ) | ( 1 << V_120 ) ) ;
if ( ( V_78 -> V_124 == sizeof( struct V_77 ) &&
( strcmp ( V_104 -> V_108 . V_106 . V_125 . V_95 ,
V_126 ) == 0 ) &&
V_104 -> V_87 < 0 && F_30 ( & V_78 -> V_66 ) ) ||
V_123 ) {
unsigned int V_127 , V_128 ;
if ( ( strcmp ( V_104 -> V_108 . V_106 . V_125 . V_95 ,
V_126 ) == 0 ) &&
V_104 -> V_87 < - V_129 - 1 ) {
F_11 ( L_21
L_22 ,
V_104 -> V_87 ) ;
return 0 ;
}
do {
V_78 -> V_112 ^= ( 1 << V_120 ) ;
V_127 = V_121 ;
V_121 = V_78 -> V_105 . V_122 ;
V_78 -> V_105 . V_122 = 0 ;
if ( V_121 == V_127 )
goto V_113;
V_78 = (struct V_77 * )
( V_119 + V_121 ) ;
} while ( V_127 == V_121 + V_78 -> V_130 );
V_128 = V_78 -> V_130 ;
V_78 = (struct V_77 * )
( V_119 + V_121 + V_128 ) ;
V_78 -> V_105 . V_122 = V_121 ;
V_121 += V_128 ;
} else {
int V_131 = V_104 -> V_87 ;
if ( strcmp ( V_104 -> V_108 . V_106 . V_125 . V_95 ,
V_126 ) == 0 &&
V_131 >= 0 ) {
if ( V_131 > V_117 -> V_128 -
sizeof( struct V_77 ) ) {
F_11 ( L_23
L_24 ,
V_131 ) ;
return 0 ;
}
F_11 ( L_25 ,
V_121 , V_131 ) ;
} else {
V_131 = V_121 + V_78 -> V_130 ;
}
V_78 = (struct V_77 * )
( V_119 + V_131 ) ;
V_78 -> V_105 . V_122 = V_121 ;
V_121 = V_131 ;
}
}
V_113:
F_11 ( L_26 , V_81 ) ;
}
return 1 ;
}
static inline int F_33 ( const struct V_77 * V_78 , const char * V_95 )
{
const struct V_76 * V_104 ;
if ( ! F_10 ( & V_78 -> V_66 ) ) {
F_11 ( L_27 , V_78 , V_95 ) ;
return - V_132 ;
}
if ( V_78 -> V_124 + sizeof( struct V_76 ) > V_78 -> V_130 )
return - V_132 ;
V_104 = F_14 ( V_78 ) ;
if ( V_78 -> V_124 + V_104 -> V_106 . V_133 > V_78 -> V_130 )
return - V_132 ;
return 0 ;
}
static inline int F_34 ( struct V_77 * V_78 , const char * V_95 )
{
struct V_76 * V_104 = F_15 ( V_78 ) ;
int V_10 ;
struct V_134 V_73 = {
. V_84 = V_95 ,
. V_135 = V_78 ,
. V_108 = V_104 -> V_106 . V_107 . V_108 ,
. V_74 = V_104 -> V_114 ,
. V_136 = V_78 -> V_112 ,
. V_101 = V_102 ,
} ;
V_10 = F_35 ( & V_73 , V_104 -> V_106 . V_133 - sizeof( * V_104 ) , 0 , false ) ;
if ( V_10 < 0 ) {
F_11 ( L_28 ,
V_104 -> V_106 . V_107 . V_108 -> V_95 ) ;
return V_10 ;
}
return 0 ;
}
static inline int
F_36 ( struct V_77 * V_78 , const char * V_95 , unsigned int V_128 )
{
struct V_76 * V_104 ;
struct V_137 * V_108 ;
int V_10 ;
V_10 = F_33 ( V_78 , V_95 ) ;
if ( V_10 )
return V_10 ;
V_104 = F_15 ( V_78 ) ;
V_108 = F_37 ( V_102 , V_104 -> V_106 . V_125 . V_95 ,
V_104 -> V_106 . V_125 . V_138 ) ;
if ( F_38 ( V_108 ) ) {
F_11 ( L_29 , V_104 -> V_106 . V_125 . V_95 ) ;
V_10 = F_39 ( V_108 ) ;
goto V_96;
}
V_104 -> V_106 . V_107 . V_108 = V_108 ;
V_10 = F_34 ( V_78 , V_95 ) ;
if ( V_10 )
goto V_139;
return 0 ;
V_139:
F_40 ( V_104 -> V_106 . V_107 . V_108 -> V_140 ) ;
V_96:
return V_10 ;
}
static bool F_41 ( const struct V_77 * V_78 )
{
const struct V_76 * V_104 ;
unsigned int V_87 ;
if ( ! F_30 ( & V_78 -> V_66 ) )
return false ;
V_104 = F_14 ( V_78 ) ;
if ( strcmp ( V_104 -> V_106 . V_125 . V_95 , V_126 ) != 0 )
return false ;
V_87 = ( (struct V_110 * ) V_104 ) -> V_87 ;
V_87 = - V_87 - 1 ;
return V_87 == V_75 || V_87 == V_141 ;
}
static inline int F_42 ( struct V_77 * V_78 ,
struct V_90 * V_117 ,
const unsigned char * V_79 ,
const unsigned char * V_142 ,
const unsigned int * V_143 ,
const unsigned int * V_144 ,
unsigned int V_118 )
{
unsigned int V_145 ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_77 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_77 ) >= V_142 ) {
F_11 ( L_30 , V_78 ) ;
return - V_132 ;
}
if ( V_78 -> V_130
< sizeof( struct V_77 ) + sizeof( struct V_76 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_130 ) ;
return - V_132 ;
}
for ( V_145 = 0 ; V_145 < V_120 ; V_145 ++ ) {
if ( ! ( V_118 & ( 1 << V_145 ) ) )
continue;
if ( ( unsigned char * ) V_78 - V_79 == V_143 [ V_145 ] )
V_117 -> V_98 [ V_145 ] = V_143 [ V_145 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_144 [ V_145 ] ) {
if ( ! F_41 ( V_78 ) ) {
F_44 ( L_32
L_33
L_34 ) ;
return - V_132 ;
}
V_117 -> V_99 [ V_145 ] = V_144 [ V_145 ] ;
}
}
V_78 -> V_105 = ( (struct V_146 ) { 0 , 0 } ) ;
V_78 -> V_112 = 0 ;
return 0 ;
}
static inline void F_45 ( struct V_77 * V_78 )
{
struct V_147 V_73 ;
struct V_76 * V_104 ;
V_104 = F_15 ( V_78 ) ;
V_73 . V_108 = V_104 -> V_106 . V_107 . V_108 ;
V_73 . V_74 = V_104 -> V_114 ;
V_73 . V_101 = V_102 ;
if ( V_73 . V_108 -> V_148 != NULL )
V_73 . V_108 -> V_148 ( & V_73 ) ;
F_40 ( V_73 . V_108 -> V_140 ) ;
}
static int F_46 ( struct V_90 * V_117 , void * V_119 ,
const struct V_149 * V_150 )
{
struct V_77 * V_151 ;
unsigned int V_9 ;
int V_10 = 0 ;
V_117 -> V_128 = V_150 -> V_128 ;
V_117 -> V_152 = V_150 -> V_153 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
V_117 -> V_98 [ V_9 ] = 0xFFFFFFFF ;
V_117 -> V_99 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_35 , V_117 -> V_128 ) ;
V_9 = 0 ;
F_47 (iter, entry0, newinfo->size) {
V_10 = F_42 ( V_151 , V_117 , V_119 ,
V_119 + V_150 -> V_128 ,
V_150 -> V_98 ,
V_150 -> V_99 ,
V_150 -> V_118 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_151 ) -> V_106 . V_125 . V_95 ,
V_154 ) == 0 )
++ V_117 -> V_155 ;
}
F_11 ( L_36 , V_10 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( V_9 != V_150 -> V_153 ) {
F_11 ( L_37 ,
V_9 , V_150 -> V_153 ) ;
return - V_132 ;
}
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
if ( ! ( V_150 -> V_118 & ( 1 << V_9 ) ) )
continue;
if ( V_117 -> V_98 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_150 -> V_98 [ V_9 ] ) ;
return - V_132 ;
}
if ( V_117 -> V_99 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_150 -> V_99 [ V_9 ] ) ;
return - V_132 ;
}
}
if ( ! F_31 ( V_117 , V_150 -> V_118 , V_119 ) ) {
F_11 ( L_40 ) ;
return - V_156 ;
}
V_9 = 0 ;
F_47 (iter, entry0, newinfo->size) {
V_10 = F_36 ( V_151 , V_150 -> V_95 , V_150 -> V_128 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
}
if ( V_10 != 0 ) {
F_47 (iter, entry0, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_45 ( V_151 ) ;
}
return V_10 ;
}
F_48 (i) {
if ( V_117 -> V_97 [ V_9 ] && V_117 -> V_97 [ V_9 ] != V_119 )
memcpy ( V_117 -> V_97 [ V_9 ] , V_119 , V_117 -> V_128 ) ;
}
return V_10 ;
}
static void F_49 ( const struct V_90 * V_104 ,
struct V_146 V_105 [] )
{
struct V_77 * V_151 ;
unsigned int V_157 ;
unsigned int V_9 ;
F_48 (cpu) {
T_4 * V_158 = & F_50 ( V_159 , V_157 ) ;
V_9 = 0 ;
F_47 (iter, t->entries[cpu], t->size) {
T_5 V_160 , V_122 ;
unsigned int V_161 ;
do {
V_161 = F_51 ( V_158 ) ;
V_160 = V_151 -> V_105 . V_160 ;
V_122 = V_151 -> V_105 . V_122 ;
} while ( F_52 ( V_158 , V_161 ) );
F_27 ( V_105 [ V_9 ] , V_160 , V_122 ) ;
++ V_9 ;
}
}
}
static struct V_146 * F_53 ( const struct V_1 * V_84 )
{
unsigned int V_162 ;
struct V_146 * V_105 ;
const struct V_90 * V_91 = V_84 -> V_91 ;
V_162 = sizeof( struct V_146 ) * V_91 -> V_152 ;
V_105 = F_54 ( V_162 ) ;
if ( V_105 == NULL )
return F_55 ( - V_163 ) ;
F_49 ( V_91 , V_105 ) ;
return V_105 ;
}
static int F_56 ( unsigned int V_164 ,
const struct V_1 * V_84 ,
void T_6 * V_165 )
{
unsigned int V_166 , V_167 ;
const struct V_77 * V_78 ;
struct V_146 * V_105 ;
struct V_90 * V_91 = V_84 -> V_91 ;
int V_10 = 0 ;
void * V_168 ;
V_105 = F_53 ( V_84 ) ;
if ( F_38 ( V_105 ) )
return F_39 ( V_105 ) ;
V_168 = V_91 -> V_97 [ F_57 () ] ;
if ( F_58 ( V_165 , V_168 , V_164 ) != 0 ) {
V_10 = - V_169 ;
goto V_170;
}
for ( V_166 = 0 , V_167 = 0 ; V_166 < V_164 ; V_166 += V_78 -> V_130 , V_167 ++ ) {
const struct V_76 * V_104 ;
V_78 = (struct V_77 * ) ( V_168 + V_166 ) ;
if ( F_58 ( V_165 + V_166
+ F_59 ( struct V_77 , V_105 ) ,
& V_105 [ V_167 ] ,
sizeof( V_105 [ V_167 ] ) ) != 0 ) {
V_10 = - V_169 ;
goto V_170;
}
V_104 = F_14 ( V_78 ) ;
if ( F_58 ( V_165 + V_166 + V_78 -> V_124
+ F_59 ( struct V_76 ,
V_106 . V_125 . V_95 ) ,
V_104 -> V_106 . V_107 . V_108 -> V_95 ,
strlen ( V_104 -> V_106 . V_107 . V_108 -> V_95 ) + 1 ) != 0 ) {
V_10 = - V_169 ;
goto V_170;
}
}
V_170:
F_60 ( V_105 ) ;
return V_10 ;
}
static void F_61 ( void * V_171 , const void * V_54 )
{
int V_109 = * ( V_172 * ) V_54 ;
if ( V_109 > 0 )
V_109 += F_62 ( V_102 , V_109 ) ;
memcpy ( V_171 , & V_109 , sizeof( V_109 ) ) ;
}
static int F_63 ( void T_6 * V_171 , const void * V_54 )
{
V_172 V_173 = * ( int * ) V_54 ;
if ( V_173 > 0 )
V_173 -= F_62 ( V_102 , V_173 ) ;
return F_58 ( V_171 , & V_173 , sizeof( V_173 ) ) ? - V_169 : 0 ;
}
static int F_64 ( const struct V_77 * V_78 ,
const struct V_90 * V_2 ,
const void * V_79 , struct V_90 * V_117 )
{
const struct V_76 * V_104 ;
unsigned int V_174 ;
int V_166 , V_9 , V_10 ;
V_166 = sizeof( struct V_77 ) - sizeof( struct V_175 ) ;
V_174 = ( void * ) V_78 - V_79 ;
V_104 = F_14 ( V_78 ) ;
V_166 += F_65 ( V_104 -> V_106 . V_107 . V_108 ) ;
V_117 -> V_128 -= V_166 ;
V_10 = F_66 ( V_102 , V_174 , V_166 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
if ( V_2 -> V_98 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_98 [ V_9 ] ) ) )
V_117 -> V_98 [ V_9 ] -= V_166 ;
if ( V_2 -> V_99 [ V_9 ] &&
( V_78 < (struct V_77 * ) ( V_79 + V_2 -> V_99 [ V_9 ] ) ) )
V_117 -> V_99 [ V_9 ] -= V_166 ;
}
return 0 ;
}
static int F_67 ( const struct V_90 * V_2 ,
struct V_90 * V_117 )
{
struct V_77 * V_151 ;
void * V_168 ;
int V_10 ;
if ( ! V_117 || ! V_2 )
return - V_132 ;
memcpy ( V_117 , V_2 , F_59 ( struct V_90 , V_97 ) ) ;
V_117 -> V_176 = 0 ;
V_168 = V_2 -> V_97 [ F_57 () ] ;
F_68 ( V_102 , V_2 -> V_152 ) ;
F_47 (iter, loc_cpu_entry, info->size) {
V_10 = F_64 ( V_151 , V_2 , V_168 , V_117 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_69 ( struct V_177 * V_177 , void T_6 * V_125 ,
const int * V_8 , int V_178 )
{
char V_95 [ V_179 ] ;
struct V_1 * V_104 ;
int V_10 ;
if ( * V_8 != sizeof( struct V_180 ) ) {
F_11 ( L_41 , * V_8 ,
sizeof( struct V_180 ) ) ;
return - V_132 ;
}
if ( F_70 ( V_95 , V_125 , sizeof( V_95 ) ) != 0 )
return - V_169 ;
V_95 [ V_179 - 1 ] = '\0' ;
#ifdef F_71
if ( V_178 )
F_72 ( V_102 ) ;
#endif
V_104 = F_73 ( F_74 ( V_177 , V_102 , V_95 ) ,
L_42 , V_95 ) ;
if ( ! F_75 ( V_104 ) ) {
struct V_180 V_2 ;
const struct V_90 * V_91 = V_104 -> V_91 ;
#ifdef F_71
struct V_90 V_181 ;
if ( V_178 ) {
V_10 = F_67 ( V_91 , & V_181 ) ;
F_76 ( V_102 ) ;
V_91 = & V_181 ;
}
#endif
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_118 = V_104 -> V_118 ;
memcpy ( V_2 . V_98 , V_91 -> V_98 ,
sizeof( V_2 . V_98 ) ) ;
memcpy ( V_2 . V_99 , V_91 -> V_99 ,
sizeof( V_2 . V_99 ) ) ;
V_2 . V_153 = V_91 -> V_152 ;
V_2 . V_128 = V_91 -> V_128 ;
strcpy ( V_2 . V_95 , V_95 ) ;
if ( F_58 ( V_125 , & V_2 , * V_8 ) != 0 )
V_10 = - V_169 ;
else
V_10 = 0 ;
F_77 ( V_104 ) ;
F_40 ( V_104 -> V_140 ) ;
} else
V_10 = V_104 ? F_39 ( V_104 ) : - V_182 ;
#ifdef F_71
if ( V_178 )
F_78 ( V_102 ) ;
#endif
return V_10 ;
}
static int F_79 ( struct V_177 * V_177 , struct V_183 T_6 * V_184 ,
const int * V_8 )
{
int V_10 ;
struct V_183 V_185 ;
struct V_1 * V_104 ;
if ( * V_8 < sizeof( V_185 ) ) {
F_11 ( L_43 , * V_8 , sizeof( V_185 ) ) ;
return - V_132 ;
}
if ( F_70 ( & V_185 , V_184 , sizeof( V_185 ) ) != 0 )
return - V_169 ;
if ( * V_8 != sizeof( struct V_183 ) + V_185 . V_128 ) {
F_11 ( L_44 , * V_8 ,
sizeof( struct V_183 ) + V_185 . V_128 ) ;
return - V_132 ;
}
V_104 = F_74 ( V_177 , V_102 , V_185 . V_95 ) ;
if ( ! F_75 ( V_104 ) ) {
const struct V_90 * V_91 = V_104 -> V_91 ;
F_11 ( L_45 ,
V_91 -> V_152 ) ;
if ( V_185 . V_128 == V_91 -> V_128 )
V_10 = F_56 ( V_91 -> V_128 ,
V_104 , V_184 -> V_186 ) ;
else {
F_11 ( L_46 ,
V_91 -> V_128 , V_185 . V_128 ) ;
V_10 = - V_187 ;
}
F_40 ( V_104 -> V_140 ) ;
F_77 ( V_104 ) ;
} else
V_10 = V_104 ? F_39 ( V_104 ) : - V_182 ;
return V_10 ;
}
static int F_80 ( struct V_177 * V_177 , const char * V_95 ,
unsigned int V_118 ,
struct V_90 * V_117 ,
unsigned int V_188 ,
void T_6 * V_189 )
{
int V_10 ;
struct V_1 * V_104 ;
struct V_90 * V_190 ;
struct V_146 * V_105 ;
void * V_191 ;
struct V_77 * V_151 ;
V_10 = 0 ;
V_105 = F_54 ( V_188 * sizeof( struct V_146 ) ) ;
if ( ! V_105 ) {
V_10 = - V_163 ;
goto V_96;
}
V_104 = F_73 ( F_74 ( V_177 , V_102 , V_95 ) ,
L_42 , V_95 ) ;
if ( F_75 ( V_104 ) ) {
V_10 = V_104 ? F_39 ( V_104 ) : - V_182 ;
goto V_192;
}
if ( V_118 != V_104 -> V_118 ) {
F_11 ( L_47 ,
V_118 , V_104 -> V_118 ) ;
V_10 = - V_132 ;
goto V_193;
}
V_190 = F_81 ( V_104 , V_188 , V_117 , & V_10 ) ;
if ( ! V_190 )
goto V_193;
F_11 ( L_48 ,
V_190 -> V_152 , V_190 -> V_176 , V_117 -> V_152 ) ;
if ( ( V_190 -> V_152 > V_190 -> V_176 ) ||
( V_117 -> V_152 <= V_190 -> V_176 ) )
F_40 ( V_104 -> V_140 ) ;
if ( ( V_190 -> V_152 > V_190 -> V_176 ) &&
( V_117 -> V_152 <= V_190 -> V_176 ) )
F_40 ( V_104 -> V_140 ) ;
F_49 ( V_190 , V_105 ) ;
V_191 = V_190 -> V_97 [ F_57 () ] ;
F_47 (iter, loc_cpu_old_entry, oldinfo->size)
F_45 ( V_151 ) ;
F_82 ( V_190 ) ;
if ( F_58 ( V_189 , V_105 ,
sizeof( struct V_146 ) * V_188 ) != 0 ) {
F_83 ( L_49 ) ;
}
F_60 ( V_105 ) ;
F_77 ( V_104 ) ;
return V_10 ;
V_193:
F_40 ( V_104 -> V_140 ) ;
F_77 ( V_104 ) ;
V_192:
F_60 ( V_105 ) ;
V_96:
return V_10 ;
}
static int F_84 ( struct V_177 * V_177 , const void T_6 * V_125 ,
unsigned int V_8 )
{
int V_10 ;
struct V_149 V_181 ;
struct V_90 * V_117 ;
void * V_168 ;
struct V_77 * V_151 ;
if ( F_70 ( & V_181 , V_125 , sizeof( V_181 ) ) != 0 )
return - V_169 ;
if ( V_181 . V_188 >= V_194 / sizeof( struct V_146 ) )
return - V_163 ;
if ( V_181 . V_188 == 0 )
return - V_132 ;
V_181 . V_95 [ sizeof( V_181 . V_95 ) - 1 ] = 0 ;
V_117 = F_85 ( V_181 . V_128 ) ;
if ( ! V_117 )
return - V_163 ;
V_168 = V_117 -> V_97 [ F_57 () ] ;
if ( F_70 ( V_168 , V_125 + sizeof( V_181 ) ,
V_181 . V_128 ) != 0 ) {
V_10 = - V_169 ;
goto V_195;
}
V_10 = F_46 ( V_117 , V_168 , & V_181 ) ;
if ( V_10 != 0 )
goto V_195;
F_11 ( L_50 ) ;
V_10 = F_80 ( V_177 , V_181 . V_95 , V_181 . V_118 , V_117 ,
V_181 . V_188 , V_181 . V_105 ) ;
if ( V_10 )
goto V_196;
return 0 ;
V_196:
F_47 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_151 ) ;
V_195:
F_82 ( V_117 ) ;
return V_10 ;
}
static int F_86 ( struct V_177 * V_177 , const void T_6 * V_125 ,
unsigned int V_8 , int V_178 )
{
unsigned int V_9 , V_197 ;
struct V_198 V_181 ;
struct V_146 * V_199 ;
unsigned int V_188 ;
const char * V_95 ;
int V_128 ;
void * V_200 ;
struct V_1 * V_104 ;
const struct V_90 * V_91 ;
int V_10 = 0 ;
void * V_168 ;
struct V_77 * V_151 ;
unsigned int V_93 ;
#ifdef F_71
struct V_201 V_202 ;
if ( V_178 ) {
V_200 = & V_202 ;
V_128 = sizeof( struct V_201 ) ;
} else
#endif
{
V_200 = & V_181 ;
V_128 = sizeof( struct V_198 ) ;
}
if ( F_70 ( V_200 , V_125 , V_128 ) != 0 )
return - V_169 ;
#ifdef F_71
if ( V_178 ) {
V_188 = V_202 . V_188 ;
V_95 = V_202 . V_95 ;
} else
#endif
{
V_188 = V_181 . V_188 ;
V_95 = V_181 . V_95 ;
}
if ( V_8 != V_128 + V_188 * sizeof( struct V_146 ) )
return - V_132 ;
V_199 = F_87 ( V_8 - V_128 ) ;
if ( ! V_199 )
return - V_163 ;
if ( F_70 ( V_199 , V_125 + V_128 , V_8 - V_128 ) != 0 ) {
V_10 = - V_169 ;
goto free;
}
V_104 = F_74 ( V_177 , V_102 , V_95 ) ;
if ( F_75 ( V_104 ) ) {
V_10 = V_104 ? F_39 ( V_104 ) : - V_182 ;
goto free;
}
F_21 () ;
V_91 = V_104 -> V_91 ;
if ( V_91 -> V_152 != V_188 ) {
V_10 = - V_132 ;
goto V_203;
}
V_9 = 0 ;
V_197 = F_24 () ;
V_168 = V_91 -> V_97 [ V_197 ] ;
V_93 = F_22 () ;
F_47 (iter, loc_cpu_entry, private->size) {
F_27 ( V_151 -> V_105 , V_199 [ V_9 ] . V_160 , V_199 [ V_9 ] . V_122 ) ;
++ V_9 ;
}
F_28 ( V_93 ) ;
V_203:
F_29 () ;
F_77 ( V_104 ) ;
F_40 ( V_104 -> V_140 ) ;
free:
F_60 ( V_199 ) ;
return V_10 ;
}
static inline void F_88 ( struct V_175 * V_78 )
{
struct V_76 * V_104 ;
V_104 = F_89 ( V_78 ) ;
F_40 ( V_104 -> V_106 . V_107 . V_108 -> V_140 ) ;
}
static inline int
F_90 ( struct V_175 * V_78 ,
struct V_90 * V_117 ,
unsigned int * V_128 ,
const unsigned char * V_79 ,
const unsigned char * V_142 ,
const unsigned int * V_143 ,
const unsigned int * V_144 ,
const char * V_95 )
{
struct V_76 * V_104 ;
struct V_137 * V_108 ;
unsigned int V_174 ;
int V_10 , V_166 , V_145 ;
F_11 ( L_51 , V_78 ) ;
if ( ( unsigned long ) V_78 % F_43 ( struct V_175 ) != 0 ||
( unsigned char * ) V_78 + sizeof( struct V_175 ) >= V_142 ) {
F_11 ( L_52 , V_78 , V_142 ) ;
return - V_132 ;
}
if ( V_78 -> V_130 < sizeof( struct V_175 ) +
sizeof( struct V_204 ) ) {
F_11 ( L_31 ,
V_78 , V_78 -> V_130 ) ;
return - V_132 ;
}
V_10 = F_33 ( (struct V_77 * ) V_78 , V_95 ) ;
if ( V_10 )
return V_10 ;
V_166 = sizeof( struct V_77 ) - sizeof( struct V_175 ) ;
V_174 = ( void * ) V_78 - ( void * ) V_79 ;
V_104 = F_89 ( V_78 ) ;
V_108 = F_37 ( V_102 , V_104 -> V_106 . V_125 . V_95 ,
V_104 -> V_106 . V_125 . V_138 ) ;
if ( F_38 ( V_108 ) ) {
F_11 ( L_53 ,
V_104 -> V_106 . V_125 . V_95 ) ;
V_10 = F_39 ( V_108 ) ;
goto V_96;
}
V_104 -> V_106 . V_107 . V_108 = V_108 ;
V_166 += F_65 ( V_108 ) ;
* V_128 += V_166 ;
V_10 = F_66 ( V_102 , V_174 , V_166 ) ;
if ( V_10 )
goto V_205;
for ( V_145 = 0 ; V_145 < V_120 ; V_145 ++ ) {
if ( ( unsigned char * ) V_78 - V_79 == V_143 [ V_145 ] )
V_117 -> V_98 [ V_145 ] = V_143 [ V_145 ] ;
if ( ( unsigned char * ) V_78 - V_79 == V_144 [ V_145 ] )
V_117 -> V_99 [ V_145 ] = V_144 [ V_145 ] ;
}
memset ( & V_78 -> V_105 , 0 , sizeof( V_78 -> V_105 ) ) ;
V_78 -> V_112 = 0 ;
return 0 ;
V_205:
F_40 ( V_104 -> V_106 . V_107 . V_108 -> V_140 ) ;
V_96:
return V_10 ;
}
static int
F_91 ( struct V_175 * V_78 , void * * V_206 ,
unsigned int * V_128 , const char * V_95 ,
struct V_90 * V_117 , unsigned char * V_79 )
{
struct V_76 * V_104 ;
struct V_137 * V_108 ;
struct V_77 * V_207 ;
unsigned int V_208 ;
int V_10 , V_145 ;
V_10 = 0 ;
V_208 = * V_128 ;
V_207 = (struct V_77 * ) * V_206 ;
memcpy ( V_207 , V_78 , sizeof( struct V_77 ) ) ;
memcpy ( & V_207 -> V_105 , & V_78 -> V_105 , sizeof( V_78 -> V_105 ) ) ;
* V_206 += sizeof( struct V_77 ) ;
* V_128 += sizeof( struct V_77 ) - sizeof( struct V_175 ) ;
V_207 -> V_124 = V_78 -> V_124 - ( V_208 - * V_128 ) ;
V_104 = F_89 ( V_78 ) ;
V_108 = V_104 -> V_106 . V_107 . V_108 ;
F_92 ( V_104 , V_206 , V_128 ) ;
V_207 -> V_130 = V_78 -> V_130 - ( V_208 - * V_128 ) ;
for ( V_145 = 0 ; V_145 < V_120 ; V_145 ++ ) {
if ( ( unsigned char * ) V_207 - V_79 < V_117 -> V_98 [ V_145 ] )
V_117 -> V_98 [ V_145 ] -= V_208 - * V_128 ;
if ( ( unsigned char * ) V_207 - V_79 < V_117 -> V_99 [ V_145 ] )
V_117 -> V_99 [ V_145 ] -= V_208 - * V_128 ;
}
return V_10 ;
}
static int F_93 ( const char * V_95 ,
unsigned int V_118 ,
struct V_90 * * V_209 ,
void * * V_210 ,
unsigned int V_164 ,
unsigned int V_152 ,
unsigned int * V_143 ,
unsigned int * V_144 )
{
unsigned int V_9 , V_211 ;
struct V_90 * V_117 , * V_2 ;
void * V_121 , * V_119 , * V_212 ;
struct V_175 * V_213 ;
struct V_77 * V_214 ;
unsigned int V_128 ;
int V_10 = 0 ;
V_2 = * V_209 ;
V_119 = * V_210 ;
V_128 = V_164 ;
V_2 -> V_152 = V_152 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
V_2 -> V_98 [ V_9 ] = 0xFFFFFFFF ;
V_2 -> V_99 [ V_9 ] = 0xFFFFFFFF ;
}
F_11 ( L_54 , V_2 -> V_128 ) ;
V_211 = 0 ;
F_72 ( V_102 ) ;
F_68 ( V_102 , V_152 ) ;
F_47 (iter0, entry0, total_size) {
V_10 = F_90 ( V_213 , V_2 , & V_128 ,
V_119 ,
V_119 + V_164 ,
V_143 ,
V_144 ,
V_95 ) ;
if ( V_10 != 0 )
goto V_215;
++ V_211 ;
}
V_10 = - V_132 ;
if ( V_211 != V_152 ) {
F_11 ( L_55 ,
V_211 , V_152 ) ;
goto V_215;
}
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
if ( ! ( V_118 & ( 1 << V_9 ) ) )
continue;
if ( V_2 -> V_98 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_38 ,
V_9 , V_143 [ V_9 ] ) ;
goto V_215;
}
if ( V_2 -> V_99 [ V_9 ] == 0xFFFFFFFF ) {
F_11 ( L_39 ,
V_9 , V_144 [ V_9 ] ) ;
goto V_215;
}
}
V_10 = - V_163 ;
V_117 = F_85 ( V_128 ) ;
if ( ! V_117 )
goto V_215;
V_117 -> V_152 = V_152 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ ) {
V_117 -> V_98 [ V_9 ] = V_2 -> V_98 [ V_9 ] ;
V_117 -> V_99 [ V_9 ] = V_2 -> V_99 [ V_9 ] ;
}
V_212 = V_117 -> V_97 [ F_57 () ] ;
V_121 = V_212 ;
V_128 = V_164 ;
F_47 (iter0, entry0, total_size) {
V_10 = F_91 ( V_213 , & V_121 , & V_128 ,
V_95 , V_117 , V_212 ) ;
if ( V_10 != 0 )
break;
}
F_76 ( V_102 ) ;
F_78 ( V_102 ) ;
if ( V_10 )
goto V_195;
V_10 = - V_156 ;
if ( ! F_31 ( V_117 , V_118 , V_212 ) )
goto V_195;
V_9 = 0 ;
F_47 (iter1, entry1, newinfo->size) {
V_10 = F_34 ( V_214 , V_95 ) ;
if ( V_10 != 0 )
break;
++ V_9 ;
if ( strcmp ( F_15 ( V_214 ) -> V_106 . V_125 . V_95 ,
V_154 ) == 0 )
++ V_117 -> V_155 ;
}
if ( V_10 ) {
int V_216 = V_9 ;
V_211 -= V_9 ;
F_47 (iter0, entry0, newinfo->size) {
if ( V_216 -- > 0 )
continue;
if ( V_211 -- == 0 )
break;
F_88 ( V_213 ) ;
}
F_47 (iter1, entry1, newinfo->size) {
if ( V_9 -- == 0 )
break;
F_45 ( V_214 ) ;
}
F_82 ( V_117 ) ;
return V_10 ;
}
F_48 (i)
if ( V_117 -> V_97 [ V_9 ] && V_117 -> V_97 [ V_9 ] != V_212 )
memcpy ( V_117 -> V_97 [ V_9 ] , V_212 , V_117 -> V_128 ) ;
* V_209 = V_117 ;
* V_210 = V_212 ;
F_82 ( V_2 ) ;
return 0 ;
V_195:
F_82 ( V_117 ) ;
V_96:
F_47 (iter0, entry0, total_size) {
if ( V_211 -- == 0 )
break;
F_88 ( V_213 ) ;
}
return V_10 ;
V_215:
F_76 ( V_102 ) ;
F_78 ( V_102 ) ;
goto V_96;
}
static int F_94 ( struct V_177 * V_177 , void T_6 * V_125 ,
unsigned int V_8 )
{
int V_10 ;
struct V_217 V_181 ;
struct V_90 * V_117 ;
void * V_168 ;
struct V_77 * V_151 ;
if ( F_70 ( & V_181 , V_125 , sizeof( V_181 ) ) != 0 )
return - V_169 ;
if ( V_181 . V_128 >= V_194 / F_95 () )
return - V_163 ;
if ( V_181 . V_188 >= V_194 / sizeof( struct V_146 ) )
return - V_163 ;
if ( V_181 . V_188 == 0 )
return - V_132 ;
V_181 . V_95 [ sizeof( V_181 . V_95 ) - 1 ] = 0 ;
V_117 = F_85 ( V_181 . V_128 ) ;
if ( ! V_117 )
return - V_163 ;
V_168 = V_117 -> V_97 [ F_57 () ] ;
if ( F_70 ( V_168 , V_125 + sizeof( V_181 ) , V_181 . V_128 ) != 0 ) {
V_10 = - V_169 ;
goto V_195;
}
V_10 = F_93 ( V_181 . V_95 , V_181 . V_118 ,
& V_117 , & V_168 , V_181 . V_128 ,
V_181 . V_153 , V_181 . V_98 ,
V_181 . V_99 ) ;
if ( V_10 != 0 )
goto V_195;
F_11 ( L_56 ) ;
V_10 = F_80 ( V_177 , V_181 . V_95 , V_181 . V_118 , V_117 ,
V_181 . V_188 , F_96 ( V_181 . V_105 ) ) ;
if ( V_10 )
goto V_196;
return 0 ;
V_196:
F_47 (iter, loc_cpu_entry, newinfo->size)
F_45 ( V_151 ) ;
V_195:
F_82 ( V_117 ) ;
return V_10 ;
}
static int F_97 ( struct V_218 * V_219 , int V_220 , void T_6 * V_125 ,
unsigned int V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_224 :
V_10 = F_94 ( F_99 ( V_219 ) , V_125 , V_8 ) ;
break;
case V_225 :
V_10 = F_86 ( F_99 ( V_219 ) , V_125 , V_8 , 1 ) ;
break;
default:
F_11 ( L_57 , V_220 ) ;
V_10 = - V_132 ;
}
return V_10 ;
}
static int F_100 ( struct V_77 * V_78 , void T_6 * * V_206 ,
T_7 * V_128 ,
struct V_146 * V_105 ,
unsigned int V_9 )
{
struct V_76 * V_104 ;
struct V_175 T_6 * V_226 ;
T_8 V_124 , V_130 ;
T_7 V_208 ;
int V_10 ;
V_208 = * V_128 ;
V_226 = (struct V_175 T_6 * ) * V_206 ;
if ( F_58 ( V_226 , V_78 , sizeof( struct V_77 ) ) != 0 ||
F_58 ( & V_226 -> V_105 , & V_105 [ V_9 ] ,
sizeof( V_105 [ V_9 ] ) ) != 0 )
return - V_169 ;
* V_206 += sizeof( struct V_175 ) ;
* V_128 -= sizeof( struct V_77 ) - sizeof( struct V_175 ) ;
V_124 = V_78 -> V_124 - ( V_208 - * V_128 ) ;
V_104 = F_15 ( V_78 ) ;
V_10 = F_101 ( V_104 , V_206 , V_128 ) ;
if ( V_10 )
return V_10 ;
V_130 = V_78 -> V_130 - ( V_208 - * V_128 ) ;
if ( F_102 ( V_124 , & V_226 -> V_124 ) != 0 ||
F_102 ( V_130 , & V_226 -> V_130 ) != 0 )
return - V_169 ;
return 0 ;
}
static int F_103 ( unsigned int V_164 ,
struct V_1 * V_84 ,
void T_6 * V_165 )
{
struct V_146 * V_105 ;
const struct V_90 * V_91 = V_84 -> V_91 ;
void T_6 * V_121 ;
unsigned int V_128 ;
int V_10 = 0 ;
void * V_168 ;
unsigned int V_9 = 0 ;
struct V_77 * V_151 ;
V_105 = F_53 ( V_84 ) ;
if ( F_38 ( V_105 ) )
return F_39 ( V_105 ) ;
V_168 = V_91 -> V_97 [ F_57 () ] ;
V_121 = V_165 ;
V_128 = V_164 ;
F_47 (iter, loc_cpu_entry, total_size) {
V_10 = F_100 ( V_151 , & V_121 ,
& V_128 , V_105 , V_9 ++ ) ;
if ( V_10 != 0 )
break;
}
F_60 ( V_105 ) ;
return V_10 ;
}
static int F_104 ( struct V_177 * V_177 ,
struct V_227 T_6 * V_184 ,
int * V_8 )
{
int V_10 ;
struct V_227 V_185 ;
struct V_1 * V_104 ;
if ( * V_8 < sizeof( V_185 ) ) {
F_11 ( L_58 , * V_8 , sizeof( V_185 ) ) ;
return - V_132 ;
}
if ( F_70 ( & V_185 , V_184 , sizeof( V_185 ) ) != 0 )
return - V_169 ;
if ( * V_8 != sizeof( struct V_227 ) + V_185 . V_128 ) {
F_11 ( L_59 ,
* V_8 , sizeof( V_185 ) + V_185 . V_128 ) ;
return - V_132 ;
}
F_72 ( V_102 ) ;
V_104 = F_74 ( V_177 , V_102 , V_185 . V_95 ) ;
if ( ! F_75 ( V_104 ) ) {
const struct V_90 * V_91 = V_104 -> V_91 ;
struct V_90 V_2 ;
F_11 ( L_45 , V_91 -> V_152 ) ;
V_10 = F_67 ( V_91 , & V_2 ) ;
if ( ! V_10 && V_185 . V_128 == V_2 . V_128 ) {
V_10 = F_103 ( V_91 -> V_128 ,
V_104 , V_184 -> V_186 ) ;
} else if ( ! V_10 ) {
F_11 ( L_60 ,
V_91 -> V_128 , V_185 . V_128 ) ;
V_10 = - V_187 ;
}
F_76 ( V_102 ) ;
F_40 ( V_104 -> V_140 ) ;
F_77 ( V_104 ) ;
} else
V_10 = V_104 ? F_39 ( V_104 ) : - V_182 ;
F_78 ( V_102 ) ;
return V_10 ;
}
static int F_105 ( struct V_218 * V_219 , int V_220 , void T_6 * V_125 ,
int * V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_228 :
V_10 = F_69 ( F_99 ( V_219 ) , V_125 , V_8 , 1 ) ;
break;
case V_229 :
V_10 = F_104 ( F_99 ( V_219 ) , V_125 , V_8 ) ;
break;
default:
V_10 = F_106 ( V_219 , V_220 , V_125 , V_8 ) ;
}
return V_10 ;
}
static int F_107 ( struct V_218 * V_219 , int V_220 , void T_6 * V_125 , unsigned int V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_224 :
V_10 = F_84 ( F_99 ( V_219 ) , V_125 , V_8 ) ;
break;
case V_225 :
V_10 = F_86 ( F_99 ( V_219 ) , V_125 , V_8 , 0 ) ;
break;
default:
F_11 ( L_57 , V_220 ) ;
V_10 = - V_132 ;
}
return V_10 ;
}
static int F_106 ( struct V_218 * V_219 , int V_220 , void T_6 * V_125 , int * V_8 )
{
int V_10 ;
if ( ! F_98 ( F_99 ( V_219 ) -> V_221 , V_222 ) )
return - V_223 ;
switch ( V_220 ) {
case V_228 :
V_10 = F_69 ( F_99 ( V_219 ) , V_125 , V_8 , 0 ) ;
break;
case V_229 :
V_10 = F_79 ( F_99 ( V_219 ) , V_125 , V_8 ) ;
break;
case V_230 : {
struct V_231 V_232 ;
if ( * V_8 != sizeof( V_232 ) ) {
V_10 = - V_132 ;
break;
}
if ( F_70 ( & V_232 , V_125 , sizeof( V_232 ) ) != 0 ) {
V_10 = - V_169 ;
break;
}
V_232 . V_95 [ sizeof( V_232 . V_95 ) - 1 ] = 0 ;
F_73 ( F_108 ( V_102 , V_232 . V_95 ,
V_232 . V_138 , 1 , & V_10 ) ,
L_61 , V_232 . V_95 ) ;
break;
}
default:
F_11 ( L_62 , V_220 ) ;
V_10 = - V_132 ;
}
return V_10 ;
}
struct V_1 * F_109 ( struct V_177 * V_177 ,
const struct V_1 * V_84 ,
const struct V_149 * V_150 )
{
int V_10 ;
struct V_90 * V_117 ;
struct V_90 V_233 = { 0 } ;
void * V_168 ;
struct V_1 * V_234 ;
V_117 = F_85 ( V_150 -> V_128 ) ;
if ( ! V_117 ) {
V_10 = - V_163 ;
goto V_96;
}
V_168 = V_117 -> V_97 [ F_57 () ] ;
memcpy ( V_168 , V_150 -> V_97 , V_150 -> V_128 ) ;
V_10 = F_46 ( V_117 , V_168 , V_150 ) ;
F_11 ( L_63 , V_10 ) ;
if ( V_10 != 0 )
goto V_235;
V_234 = F_110 ( V_177 , V_84 , & V_233 , V_117 ) ;
if ( F_38 ( V_234 ) ) {
V_10 = F_39 ( V_234 ) ;
goto V_235;
}
return V_234 ;
V_235:
F_82 ( V_117 ) ;
V_96:
return F_55 ( V_10 ) ;
}
void F_111 ( struct V_1 * V_84 )
{
struct V_90 * V_91 ;
void * V_168 ;
struct V_236 * V_237 = V_84 -> V_140 ;
struct V_77 * V_151 ;
V_91 = F_112 ( V_84 ) ;
V_168 = V_91 -> V_97 [ F_57 () ] ;
F_47 (iter, loc_cpu_entry, private->size)
F_45 ( V_151 ) ;
if ( V_91 -> V_152 > V_91 -> V_176 )
F_40 ( V_237 ) ;
F_82 ( V_91 ) ;
}
static int T_9 F_113 ( struct V_177 * V_177 )
{
return F_114 ( V_177 , V_102 ) ;
}
static void T_10 F_115 ( struct V_177 * V_177 )
{
F_116 ( V_177 , V_102 ) ;
}
static int T_11 F_117 ( void )
{
int V_10 ;
V_10 = F_118 ( & V_238 ) ;
if ( V_10 < 0 )
goto V_239;
V_10 = F_119 ( V_240 , F_120 ( V_240 ) ) ;
if ( V_10 < 0 )
goto V_241;
V_10 = F_121 ( & V_242 ) ;
if ( V_10 < 0 )
goto V_243;
F_122 ( V_244 L_64 ) ;
return 0 ;
V_243:
F_123 ( V_240 , F_120 ( V_240 ) ) ;
V_241:
F_124 ( & V_238 ) ;
V_239:
return V_10 ;
}
static void T_12 F_125 ( void )
{
F_126 ( & V_242 ) ;
F_123 ( V_240 , F_120 ( V_240 ) ) ;
F_124 ( & V_238 ) ;
}
