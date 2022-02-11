static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
}
static int F_4 ( struct V_12 * V_13 )
{
return V_13 -> F_4 ;
}
static unsigned long long * F_5 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_16 ) ) ;
return ( unsigned long long * ) ( V_14 + F_4 ( V_13 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_7 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_16 ) ) ;
if ( V_13 -> V_15 & V_17 )
return ( unsigned long long * ) ( V_14 + V_13 -> V_18 -
sizeof( unsigned long long ) -
V_19 ) ;
return ( unsigned long long * ) ( V_14 + V_13 -> V_18 -
sizeof( unsigned long long ) ) ;
}
static void * * F_8 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_17 ) ) ;
return ( void * * ) ( V_14 + V_13 -> V_18 - V_20 ) ;
}
static inline bool F_9 ( struct V_12 * V_13 )
{
return F_10 ( & V_13 -> V_21 ) == 1 ;
}
static inline void F_11 ( struct V_12 * V_13 )
{
F_12 ( & V_13 -> V_21 , 1 ) ;
}
static inline void F_13 ( struct V_12 * V_13 )
{
if ( F_9 ( V_13 ) )
F_12 ( & V_13 -> V_21 , 0 ) ;
}
static inline void F_13 ( struct V_12 * V_13 ) {}
static inline struct V_12 * F_14 ( const void * V_22 )
{
struct V_23 * V_23 = F_15 ( V_22 ) ;
return V_23 -> V_24 ;
}
static inline void * F_16 ( struct V_12 * V_25 , struct V_23 * V_23 ,
unsigned int V_26 )
{
return V_23 -> V_27 + V_25 -> V_18 * V_26 ;
}
static inline unsigned int F_17 ( const struct V_12 * V_25 ,
const struct V_23 * V_23 , void * V_22 )
{
T_1 V_28 = ( V_22 - V_23 -> V_27 ) ;
return F_18 ( V_28 , V_25 -> V_29 ) ;
}
static inline struct V_30 * F_19 ( struct V_12 * V_13 )
{
return F_20 ( V_13 -> V_31 ) ;
}
static unsigned int F_21 ( unsigned long V_32 , T_2 V_33 ,
unsigned long V_15 , T_2 * V_34 )
{
unsigned int V_35 ;
T_2 V_36 = V_37 << V_32 ;
if ( V_15 & ( V_38 | V_39 ) ) {
V_35 = V_36 / V_33 ;
* V_34 = V_36 % V_33 ;
} else {
V_35 = V_36 / ( V_33 + sizeof( V_40 ) ) ;
* V_34 = V_36 %
( V_33 + sizeof( V_40 ) ) ;
}
return V_35 ;
}
static void F_22 ( const char * V_41 , struct V_12 * V_13 ,
char * V_42 )
{
F_23 ( L_1 ,
V_41 , V_13 -> V_43 , V_42 ) ;
F_24 () ;
F_25 ( V_44 , V_45 ) ;
}
static int T_3 F_26 ( char * V_46 )
{
V_47 = 0 ;
return 1 ;
}
static int T_3 F_27 ( char * V_48 )
{
F_28 ( & V_48 , & V_49 ) ;
V_49 = V_49 < 0 ? 0 :
F_29 ( V_49 , V_50 - 1 ) ;
V_51 = true ;
return 1 ;
}
static void F_30 ( int V_52 )
{
int V_53 ;
V_53 = F_31 ( F_32 ( V_52 ) , V_54 ) ;
if ( V_53 == V_55 )
V_53 = F_33 ( V_54 ) ;
F_34 ( V_56 , V_52 ) = V_53 ;
}
static void F_35 ( void )
{
int V_53 = F_36 ( V_56 ) ;
V_53 = F_31 ( V_53 , V_54 ) ;
if ( F_37 ( V_53 >= V_55 ) )
V_53 = F_33 ( V_54 ) ;
F_38 ( V_56 , V_53 ) ;
}
static void F_39 ( int V_52 )
{
struct V_57 * V_58 = & F_34 ( V_59 , V_52 ) ;
if ( F_40 () && V_58 -> V_60 . V_61 == NULL ) {
F_30 ( V_52 ) ;
F_41 ( V_58 , V_62 ) ;
F_42 ( V_52 , V_58 ,
F_43 ( V_63 , V_52 ) ) ;
}
}
static void F_44 ( struct V_30 * V_64 , int V_65 , int V_66 )
{
F_45 ( V_64 ) ;
if ( V_64 ) {
V_64 -> V_67 = 0 ;
V_64 -> V_65 = V_65 ;
V_64 -> V_68 = V_66 ;
V_64 -> V_69 = 0 ;
}
}
static struct V_30 * F_46 ( int V_53 , int V_70 ,
int V_68 , T_4 V_71 )
{
T_2 V_72 = sizeof( void * ) * V_70 + sizeof( struct V_30 ) ;
struct V_30 * V_64 = NULL ;
V_64 = F_47 ( V_72 , V_71 , V_53 ) ;
F_44 ( V_64 , V_70 , V_68 ) ;
return V_64 ;
}
static T_5 void F_48 ( struct V_12 * V_13 ,
struct V_23 * V_23 , void * V_14 )
{
struct V_1 * V_73 ;
int V_74 ;
F_49 ( V_75 ) ;
V_74 = F_50 ( V_23 ) ;
V_73 = F_51 ( V_13 , V_74 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_13 , & V_14 , 1 , V_74 , & V_75 ) ;
F_54 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
}
static int F_56 ( struct V_30 * V_76 ,
struct V_30 * V_77 , unsigned int V_78 )
{
int V_79 = F_57 ( V_77 -> V_67 , V_78 , V_76 -> V_65 - V_76 -> V_67 ) ;
if ( ! V_79 )
return 0 ;
memcpy ( V_76 -> V_80 + V_76 -> V_67 , V_77 -> V_80 + V_77 -> V_67 - V_79 ,
sizeof( void * ) * V_79 ) ;
V_77 -> V_67 -= V_79 ;
V_76 -> V_67 += V_79 ;
return V_79 ;
}
static inline struct V_81 * * F_58 ( int V_53 ,
int V_65 , T_4 V_71 )
{
return (struct V_81 * * ) V_82 ;
}
static inline void F_59 ( struct V_81 * * V_83 )
{
}
static inline int F_60 ( struct V_12 * V_13 , void * V_14 )
{
return 0 ;
}
static inline void * F_61 ( struct V_12 * V_13 ,
T_4 V_15 )
{
return NULL ;
}
static inline void * F_62 ( struct V_12 * V_13 ,
T_4 V_15 , int V_84 )
{
return NULL ;
}
static inline T_4 F_63 ( T_4 V_15 )
{
return V_15 & ~ V_85 ;
}
static struct V_81 * F_64 ( int V_53 , int V_70 ,
int V_66 , T_4 V_71 )
{
T_2 V_72 = sizeof( void * ) * V_70 + sizeof( struct V_81 ) ;
struct V_81 * V_86 = NULL ;
V_86 = F_47 ( V_72 , V_71 , V_53 ) ;
F_44 ( & V_86 -> V_64 , V_70 , V_66 ) ;
F_3 ( & V_86 -> V_87 ) ;
return V_86 ;
}
static struct V_81 * * F_58 ( int V_53 , int V_65 , T_4 V_71 )
{
struct V_81 * * V_88 ;
T_2 V_72 = sizeof( void * ) * V_89 ;
int V_90 ;
if ( V_65 > 1 )
V_65 = 12 ;
V_88 = F_65 ( V_72 , V_71 , V_53 ) ;
if ( ! V_88 )
return NULL ;
F_66 (i) {
if ( V_90 == V_53 || ! F_67 ( V_90 ) )
continue;
V_88 [ V_90 ] = F_64 ( V_53 , V_65 , 0xbaadf00d , V_71 ) ;
if ( ! V_88 [ V_90 ] ) {
for ( V_90 -- ; V_90 >= 0 ; V_90 -- )
F_68 ( V_88 [ V_90 ] ) ;
F_68 ( V_88 ) ;
return NULL ;
}
}
return V_88 ;
}
static void F_59 ( struct V_81 * * V_88 )
{
int V_90 ;
if ( ! V_88 )
return;
F_66 (i)
F_68 ( V_88 [ V_90 ] ) ;
F_68 ( V_88 ) ;
}
static void F_69 ( struct V_12 * V_13 ,
struct V_30 * V_64 , int V_53 ,
struct V_91 * V_75 )
{
struct V_1 * V_73 = F_51 ( V_13 , V_53 ) ;
if ( V_64 -> V_67 ) {
F_52 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 )
F_56 ( V_73 -> V_6 , V_64 , V_64 -> V_65 ) ;
F_53 ( V_13 , V_64 -> V_80 , V_64 -> V_67 , V_53 , V_75 ) ;
V_64 -> V_67 = 0 ;
F_54 ( & V_73 -> V_9 ) ;
}
}
static void F_70 ( struct V_12 * V_13 , struct V_1 * V_73 )
{
int V_53 = F_36 ( V_56 ) ;
if ( V_73 -> V_7 ) {
struct V_81 * V_86 = V_73 -> V_7 [ V_53 ] ;
struct V_30 * V_64 ;
if ( V_86 ) {
V_64 = & V_86 -> V_64 ;
if ( V_64 -> V_67 && F_71 ( & V_86 -> V_87 ) ) {
F_49 ( V_75 ) ;
F_69 ( V_13 , V_64 , V_53 , & V_75 ) ;
F_72 ( & V_86 -> V_87 ) ;
F_55 ( V_13 , & V_75 ) ;
}
}
}
}
static void F_73 ( struct V_12 * V_13 ,
struct V_81 * * V_7 )
{
int V_90 = 0 ;
struct V_81 * V_86 ;
struct V_30 * V_64 ;
unsigned long V_15 ;
F_74 (i) {
V_86 = V_7 [ V_90 ] ;
if ( V_86 ) {
F_49 ( V_75 ) ;
V_64 = & V_86 -> V_64 ;
F_75 ( & V_86 -> V_87 , V_15 ) ;
F_69 ( V_13 , V_64 , V_90 , & V_75 ) ;
F_76 ( & V_86 -> V_87 , V_15 ) ;
F_55 ( V_13 , & V_75 ) ;
}
}
}
static int F_77 ( struct V_12 * V_13 , void * V_14 ,
int V_53 , int V_74 )
{
struct V_1 * V_73 ;
struct V_81 * V_7 = NULL ;
struct V_30 * V_64 ;
F_49 ( V_75 ) ;
V_73 = F_51 ( V_13 , V_53 ) ;
F_78 ( V_13 ) ;
if ( V_73 -> V_7 && V_73 -> V_7 [ V_74 ] ) {
V_7 = V_73 -> V_7 [ V_74 ] ;
V_64 = & V_7 -> V_64 ;
F_52 ( & V_7 -> V_87 ) ;
if ( F_37 ( V_64 -> V_67 == V_64 -> V_65 ) ) {
F_79 ( V_13 ) ;
F_69 ( V_13 , V_64 , V_74 , & V_75 ) ;
}
V_64 -> V_80 [ V_64 -> V_67 ++ ] = V_14 ;
F_54 ( & V_7 -> V_87 ) ;
F_55 ( V_13 , & V_75 ) ;
} else {
V_73 = F_51 ( V_13 , V_74 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_13 , & V_14 , 1 , V_74 , & V_75 ) ;
F_54 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
}
return 1 ;
}
static inline int F_60 ( struct V_12 * V_13 , void * V_14 )
{
int V_74 = F_50 ( F_80 ( V_14 ) ) ;
int V_53 = F_81 () ;
if ( F_82 ( V_53 == V_74 ) )
return 0 ;
return F_77 ( V_13 , V_14 , V_53 , V_74 ) ;
}
static inline T_4 F_63 ( T_4 V_15 )
{
return ( V_15 | V_92 | V_93 ) & ~ ( V_94 | V_85 ) ;
}
static int F_83 ( int V_53 )
{
struct V_12 * V_13 ;
struct V_1 * V_73 ;
const T_2 V_72 = sizeof( struct V_1 ) ;
F_84 (cachep, &slab_caches, list) {
V_73 = F_51 ( V_13 , V_53 ) ;
if ( ! V_73 ) {
V_73 = F_47 ( V_72 , V_95 , V_53 ) ;
if ( ! V_73 )
return - V_96 ;
F_1 ( V_73 ) ;
V_73 -> V_97 = V_98 + V_99 +
( ( unsigned long ) V_13 ) % V_99 ;
V_13 -> V_53 [ V_53 ] = V_73 ;
}
F_85 ( & V_73 -> V_9 ) ;
V_73 -> V_100 =
( 1 + F_86 ( V_53 ) ) *
V_13 -> V_68 + V_13 -> V_35 ;
F_72 ( & V_73 -> V_9 ) ;
}
return 0 ;
}
static inline int F_87 ( struct V_12 * V_13 ,
struct V_1 * V_73 )
{
return ( V_73 -> V_10 + V_13 -> V_35 - 1 ) / V_13 -> V_35 ;
}
static void F_88 ( long V_52 )
{
struct V_12 * V_13 ;
struct V_1 * V_73 = NULL ;
int V_53 = F_32 ( V_52 ) ;
const struct V_101 * V_102 = F_89 ( V_53 ) ;
F_84 (cachep, &slab_caches, list) {
struct V_30 * V_103 ;
struct V_30 * V_6 ;
struct V_81 * * V_7 ;
F_49 ( V_75 ) ;
V_73 = F_51 ( V_13 , V_53 ) ;
if ( ! V_73 )
continue;
F_85 ( & V_73 -> V_9 ) ;
V_73 -> V_100 -= V_13 -> V_68 ;
V_103 = F_90 ( V_13 -> V_31 , V_52 ) ;
if ( V_103 ) {
F_53 ( V_13 , V_103 -> V_80 , V_103 -> V_67 , V_53 , & V_75 ) ;
V_103 -> V_67 = 0 ;
}
if ( ! F_91 ( V_102 ) ) {
F_72 ( & V_73 -> V_9 ) ;
goto V_104;
}
V_6 = V_73 -> V_6 ;
if ( V_6 ) {
F_53 ( V_13 , V_6 -> V_80 ,
V_6 -> V_67 , V_53 , & V_75 ) ;
V_73 -> V_6 = NULL ;
}
V_7 = V_73 -> V_7 ;
V_73 -> V_7 = NULL ;
F_72 ( & V_73 -> V_9 ) ;
F_68 ( V_6 ) ;
if ( V_7 ) {
F_73 ( V_13 , V_7 ) ;
F_59 ( V_7 ) ;
}
V_104:
F_55 ( V_13 , & V_75 ) ;
}
F_84 (cachep, &slab_caches, list) {
V_73 = F_51 ( V_13 , V_53 ) ;
if ( ! V_73 )
continue;
F_92 ( V_13 , V_73 , F_87 ( V_13 , V_73 ) ) ;
}
}
static int F_93 ( long V_52 )
{
struct V_12 * V_13 ;
struct V_1 * V_73 = NULL ;
int V_53 = F_32 ( V_52 ) ;
int V_105 ;
V_105 = F_83 ( V_53 ) ;
if ( V_105 < 0 )
goto V_106;
F_84 (cachep, &slab_caches, list) {
struct V_30 * V_6 = NULL ;
struct V_81 * * V_7 = NULL ;
if ( V_13 -> V_6 ) {
V_6 = F_46 ( V_53 ,
V_13 -> V_6 * V_13 -> V_68 ,
0xbaadf00d , V_95 ) ;
if ( ! V_6 )
goto V_106;
}
if ( V_47 ) {
V_7 = F_58 ( V_53 , V_13 -> V_65 , V_95 ) ;
if ( ! V_7 ) {
F_68 ( V_6 ) ;
goto V_106;
}
}
V_73 = F_51 ( V_13 , V_53 ) ;
F_6 ( ! V_73 ) ;
F_85 ( & V_73 -> V_9 ) ;
if ( ! V_73 -> V_6 ) {
V_73 -> V_6 = V_6 ;
V_6 = NULL ;
}
#ifdef F_94
if ( ! V_73 -> V_7 ) {
V_73 -> V_7 = V_7 ;
V_7 = NULL ;
}
#endif
F_72 ( & V_73 -> V_9 ) ;
F_68 ( V_6 ) ;
F_59 ( V_7 ) ;
}
return 0 ;
V_106:
F_88 ( V_52 ) ;
return - V_96 ;
}
static int F_95 ( struct V_107 * V_108 ,
unsigned long V_109 , void * V_110 )
{
long V_52 = ( long ) V_110 ;
int V_105 = 0 ;
switch ( V_109 ) {
case V_111 :
case V_112 :
F_96 ( & V_113 ) ;
V_105 = F_93 ( V_52 ) ;
F_97 ( & V_113 ) ;
break;
case V_114 :
case V_115 :
F_39 ( V_52 ) ;
break;
#ifdef F_98
case V_116 :
case V_117 :
F_99 ( & F_34 ( V_59 , V_52 ) ) ;
F_34 ( V_59 , V_52 ) . V_60 . V_61 = NULL ;
break;
case V_118 :
case V_119 :
F_39 ( V_52 ) ;
break;
case V_120 :
case V_121 :
#endif
case V_122 :
case V_123 :
F_96 ( & V_113 ) ;
F_88 ( V_52 ) ;
F_97 ( & V_113 ) ;
break;
}
return F_100 ( V_105 ) ;
}
static int T_6 F_101 ( int V_53 )
{
struct V_12 * V_13 ;
int V_124 = 0 ;
F_84 (cachep, &slab_caches, list) {
struct V_1 * V_73 ;
V_73 = F_51 ( V_13 , V_53 ) ;
if ( ! V_73 )
continue;
F_92 ( V_13 , V_73 , F_87 ( V_13 , V_73 ) ) ;
if ( ! F_102 ( & V_73 -> V_3 ) ||
! F_102 ( & V_73 -> V_4 ) ) {
V_124 = - V_125 ;
break;
}
}
return V_124 ;
}
static int T_6 F_103 ( struct V_107 * V_126 ,
unsigned long V_109 , void * V_127 )
{
struct V_128 * V_129 = V_127 ;
int V_124 = 0 ;
int V_130 ;
V_130 = V_129 -> V_131 ;
if ( V_130 < 0 )
goto V_132;
switch ( V_109 ) {
case V_133 :
F_96 ( & V_113 ) ;
V_124 = F_83 ( V_130 ) ;
F_97 ( & V_113 ) ;
break;
case V_134 :
F_96 ( & V_113 ) ;
V_124 = F_101 ( V_130 ) ;
F_97 ( & V_113 ) ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
break;
}
V_132:
return F_100 ( V_124 ) ;
}
static void T_3 F_104 ( struct V_12 * V_13 , struct V_1 * V_75 ,
int V_84 )
{
struct V_1 * V_139 ;
V_139 = F_47 ( sizeof( struct V_1 ) , V_140 , V_84 ) ;
F_6 ( ! V_139 ) ;
memcpy ( V_139 , V_75 , sizeof( struct V_1 ) ) ;
F_3 ( & V_139 -> V_9 ) ;
F_105 ( V_13 , V_139 , V_84 ) ;
V_13 -> V_53 [ V_84 ] = V_139 ;
}
static void T_3 F_106 ( struct V_12 * V_13 , int V_141 )
{
int V_53 ;
F_74 (node) {
V_13 -> V_53 [ V_53 ] = & V_142 [ V_141 + V_53 ] ;
V_13 -> V_53 [ V_53 ] -> V_97 = V_98 +
V_99 +
( ( unsigned long ) V_13 ) % V_99 ;
}
}
void T_3 F_107 ( void )
{
int V_90 ;
F_108 ( sizeof( ( (struct V_23 * ) NULL ) -> V_143 ) <
sizeof( struct V_144 ) ) ;
V_12 = & V_145 ;
if ( F_109 () == 1 )
V_47 = 0 ;
for ( V_90 = 0 ; V_90 < V_146 ; V_90 ++ )
F_1 ( & V_142 [ V_90 ] ) ;
if ( ! V_51 && V_147 > ( 32 << 20 ) >> V_148 )
V_49 = V_149 ;
F_110 ( V_12 , L_2 ,
F_111 ( struct V_12 , V_53 ) +
V_89 * sizeof( struct V_1 * ) ,
V_150 ) ;
F_112 ( & V_12 -> V_75 , & V_151 ) ;
V_152 = V_153 ;
V_154 [ V_155 ] = F_113 ( L_3 ,
F_114 ( V_155 ) , V_156 ) ;
V_152 = V_157 ;
F_115 () ;
V_158 = 0 ;
{
int V_130 ;
F_74 (nid) {
F_104 ( V_12 , & V_142 [ V_159 + V_130 ] , V_130 ) ;
F_104 ( V_154 [ V_155 ] ,
& V_142 [ V_160 + V_130 ] , V_130 ) ;
}
}
F_116 ( V_156 ) ;
}
void T_3 F_117 ( void )
{
struct V_12 * V_13 ;
V_152 = V_161 ;
F_96 ( & V_113 ) ;
F_84 (cachep, &slab_caches, list)
if ( F_118 ( V_13 , V_140 ) )
F_119 () ;
F_97 ( & V_113 ) ;
V_152 = V_162 ;
F_120 ( & V_163 ) ;
#ifdef F_94
F_121 ( F_103 , V_164 ) ;
#endif
}
static int T_3 F_122 ( void )
{
int V_52 ;
F_123 (cpu)
F_39 ( V_52 ) ;
V_152 = V_162 ;
return 0 ;
}
static T_5 void
F_124 ( struct V_12 * V_13 , T_4 V_165 , int V_84 )
{
#if V_166
struct V_1 * V_73 ;
struct V_23 * V_23 ;
unsigned long V_15 ;
int V_53 ;
static F_125 ( V_167 , V_168 ,
V_169 ) ;
if ( ( V_165 & V_93 ) || ! F_126 ( & V_167 ) )
return;
F_127 ( L_4 ,
V_84 , V_165 , & V_165 ) ;
F_127 ( L_5 ,
V_13 -> V_43 , V_13 -> V_18 , V_13 -> V_32 ) ;
F_128 (cachep, node, n) {
unsigned long V_170 = 0 , V_171 = 0 , V_10 = 0 ;
unsigned long V_172 = 0 , V_173 = 0 ;
F_75 ( & V_73 -> V_9 , V_15 ) ;
F_84 (page, &n->slabs_full, lru) {
V_170 += V_13 -> V_35 ;
V_172 ++ ;
}
F_84 (page, &n->slabs_partial, lru) {
V_170 += V_23 -> V_174 ;
V_172 ++ ;
}
F_84 (page, &n->slabs_free, lru)
V_173 ++ ;
V_10 += V_73 -> V_10 ;
F_76 ( & V_73 -> V_9 , V_15 ) ;
V_173 += V_172 ;
V_171 = V_173 * V_13 -> V_35 ;
F_127 ( L_6 ,
V_53 , V_172 , V_173 , V_170 , V_171 ,
V_10 ) ;
}
#endif
}
static struct V_23 * F_129 ( struct V_12 * V_13 , T_4 V_15 ,
int V_84 )
{
struct V_23 * V_23 ;
int V_175 ;
V_15 |= V_13 -> V_176 ;
if ( V_13 -> V_15 & V_177 )
V_15 |= V_178 ;
V_23 = F_130 ( V_84 , V_15 | V_179 , V_13 -> V_32 ) ;
if ( ! V_23 ) {
F_124 ( V_13 , V_15 , V_84 ) ;
return NULL ;
}
if ( F_131 ( V_23 , V_15 , V_13 -> V_32 , V_13 ) ) {
F_132 ( V_23 , V_13 -> V_32 ) ;
return NULL ;
}
V_175 = ( 1 << V_13 -> V_32 ) ;
if ( V_13 -> V_15 & V_177 )
F_133 ( F_134 ( V_23 ) ,
V_180 , V_175 ) ;
else
F_133 ( F_134 ( V_23 ) ,
V_181 , V_175 ) ;
F_135 ( V_23 ) ;
if ( F_136 () && F_137 ( V_23 ) )
F_138 ( V_23 ) ;
if ( V_182 && ! ( V_13 -> V_15 & V_183 ) ) {
F_139 ( V_23 , V_13 -> V_32 , V_15 , V_84 ) ;
if ( V_13 -> V_184 )
F_140 ( V_23 , V_175 ) ;
else
F_141 ( V_23 , V_175 ) ;
}
return V_23 ;
}
static void F_142 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
int V_185 = V_13 -> V_32 ;
unsigned long V_186 = ( 1 << V_185 ) ;
F_143 ( V_23 , V_185 ) ;
if ( V_13 -> V_15 & V_177 )
F_144 ( F_134 ( V_23 ) ,
V_180 , V_186 ) ;
else
F_144 ( F_134 ( V_23 ) ,
V_181 , V_186 ) ;
F_6 ( ! F_145 ( V_23 ) ) ;
F_146 ( V_23 ) ;
F_147 ( V_23 ) ;
F_148 ( V_23 ) ;
V_23 -> V_187 = NULL ;
if ( V_188 -> V_189 )
V_188 -> V_189 -> V_190 += V_186 ;
F_149 ( V_23 , V_185 , V_13 ) ;
F_132 ( V_23 , V_185 ) ;
}
static void F_150 ( struct V_144 * V_191 )
{
struct V_12 * V_13 ;
struct V_23 * V_23 ;
V_23 = F_151 ( V_191 , struct V_23 , V_144 ) ;
V_13 = V_23 -> V_24 ;
F_142 ( V_13 , V_23 ) ;
}
static bool F_152 ( struct V_12 * V_13 )
{
if ( F_153 () && F_154 ( V_13 ) &&
( V_13 -> V_18 % V_37 ) == 0 )
return true ;
return false ;
}
static void F_155 ( struct V_12 * V_13 , unsigned long * V_192 ,
unsigned long V_193 )
{
int V_18 = V_13 -> V_194 ;
V_192 = ( unsigned long * ) & ( ( char * ) V_192 ) [ F_4 ( V_13 ) ] ;
if ( V_18 < 5 * sizeof( unsigned long ) )
return;
* V_192 ++ = 0x12345678 ;
* V_192 ++ = V_193 ;
* V_192 ++ = F_156 () ;
V_18 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_195 = & V_193 ;
unsigned long V_196 ;
while ( ! F_157 ( V_195 ) ) {
V_196 = * V_195 ++ ;
if ( F_158 ( V_196 ) ) {
* V_192 ++ = V_196 ;
V_18 -= sizeof( unsigned long ) ;
if ( V_18 <= sizeof( unsigned long ) )
break;
}
}
}
* V_192 ++ = 0x87654321 ;
}
static void F_159 ( struct V_12 * V_13 , void * V_14 ,
int V_197 , unsigned long V_193 )
{
if ( ! F_152 ( V_13 ) )
return;
if ( V_193 )
F_155 ( V_13 , V_14 , V_193 ) ;
F_160 ( F_80 ( V_14 ) , V_13 -> V_18 / V_37 , V_197 ) ;
}
static inline void F_159 ( struct V_12 * V_13 , void * V_14 ,
int V_197 , unsigned long V_193 ) {}
static void F_161 ( struct V_12 * V_13 , void * V_192 , unsigned char V_198 )
{
int V_18 = V_13 -> V_194 ;
V_192 = & ( ( char * ) V_192 ) [ F_4 ( V_13 ) ] ;
memset ( V_192 , V_198 , V_18 ) ;
* ( unsigned char * ) ( V_192 + V_18 - 1 ) = V_199 ;
}
static void F_162 ( char * V_200 , int V_28 , int V_65 )
{
int V_90 ;
unsigned char error = 0 ;
int V_201 = 0 ;
F_23 ( L_7 , V_28 ) ;
for ( V_90 = 0 ; V_90 < V_65 ; V_90 ++ ) {
if ( V_200 [ V_28 + V_90 ] != V_202 ) {
error = V_200 [ V_28 + V_90 ] ;
V_201 ++ ;
}
}
F_163 ( V_203 , L_8 , 0 , 16 , 1 ,
& V_200 [ V_28 ] , V_65 , 1 ) ;
if ( V_201 == 1 ) {
error ^= V_202 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_23 ( L_9 ) ;
#ifdef F_164
F_23 ( L_10 ) ;
#else
F_23 ( L_11 ) ;
#endif
}
}
}
static void F_165 ( struct V_12 * V_13 , void * V_14 , int V_204 )
{
int V_90 , V_18 ;
char * V_205 ;
if ( V_13 -> V_15 & V_16 ) {
F_23 ( L_12 ,
* F_5 ( V_13 , V_14 ) ,
* F_7 ( V_13 , V_14 ) ) ;
}
if ( V_13 -> V_15 & V_17 ) {
F_23 ( L_13 ,
* F_8 ( V_13 , V_14 ) ,
* F_8 ( V_13 , V_14 ) ) ;
}
V_205 = ( char * ) V_14 + F_4 ( V_13 ) ;
V_18 = V_13 -> V_194 ;
for ( V_90 = 0 ; V_90 < V_18 && V_204 ; V_90 += 16 , V_204 -- ) {
int V_65 ;
V_65 = 16 ;
if ( V_90 + V_65 > V_18 )
V_65 = V_18 - V_90 ;
F_162 ( V_205 , V_90 , V_65 ) ;
}
}
static void F_166 ( struct V_12 * V_13 , void * V_14 )
{
char * V_205 ;
int V_18 , V_90 ;
int V_204 = 0 ;
if ( F_152 ( V_13 ) )
return;
V_205 = ( char * ) V_14 + F_4 ( V_13 ) ;
V_18 = V_13 -> V_194 ;
for ( V_90 = 0 ; V_90 < V_18 ; V_90 ++ ) {
char exp = V_202 ;
if ( V_90 == V_18 - 1 )
exp = V_199 ;
if ( V_205 [ V_90 ] != exp ) {
int V_65 ;
if ( V_204 == 0 ) {
F_23 ( L_14 ,
F_167 () , V_13 -> V_43 ,
V_205 , V_18 ) ;
F_165 ( V_13 , V_14 , 0 ) ;
}
V_90 = ( V_90 / 16 ) * 16 ;
V_65 = 16 ;
if ( V_90 + V_65 > V_18 )
V_65 = V_18 - V_90 ;
F_162 ( V_205 , V_90 , V_65 ) ;
V_90 += 16 ;
V_204 ++ ;
if ( V_204 > 5 )
break;
}
}
if ( V_204 != 0 ) {
struct V_23 * V_23 = F_15 ( V_14 ) ;
unsigned int V_206 ;
V_206 = F_17 ( V_13 , V_23 , V_14 ) ;
if ( V_206 ) {
V_14 = F_16 ( V_13 , V_23 , V_206 - 1 ) ;
V_205 = ( char * ) V_14 + F_4 ( V_13 ) ;
F_23 ( L_15 , V_205 , V_18 ) ;
F_165 ( V_13 , V_14 , 2 ) ;
}
if ( V_206 + 1 < V_13 -> V_35 ) {
V_14 = F_16 ( V_13 , V_23 , V_206 + 1 ) ;
V_205 = ( char * ) V_14 + F_4 ( V_13 ) ;
F_23 ( L_16 , V_205 , V_18 ) ;
F_165 ( V_13 , V_14 , 2 ) ;
}
}
}
static void F_168 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
int V_90 ;
if ( F_169 ( V_13 ) && V_13 -> V_15 & V_207 ) {
F_161 ( V_13 , V_23 -> V_208 - F_4 ( V_13 ) ,
V_202 ) ;
}
for ( V_90 = 0 ; V_90 < V_13 -> V_35 ; V_90 ++ ) {
void * V_14 = F_16 ( V_13 , V_23 , V_90 ) ;
if ( V_13 -> V_15 & V_207 ) {
F_166 ( V_13 , V_14 ) ;
F_159 ( V_13 , V_14 , 1 , 0 ) ;
}
if ( V_13 -> V_15 & V_16 ) {
if ( * F_5 ( V_13 , V_14 ) != V_209 )
F_170 ( V_13 , L_17 ) ;
if ( * F_7 ( V_13 , V_14 ) != V_209 )
F_170 ( V_13 , L_18 ) ;
}
}
}
static void F_168 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
}
static void F_171 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
void * V_208 ;
V_208 = V_23 -> V_208 ;
F_168 ( V_13 , V_23 ) ;
if ( F_37 ( V_13 -> V_15 & V_210 ) )
F_172 ( & V_23 -> V_144 , F_150 ) ;
else
F_142 ( V_13 , V_23 ) ;
if ( F_154 ( V_13 ) )
F_173 ( V_13 -> V_211 , V_208 ) ;
}
static void F_55 ( struct V_12 * V_13 , struct V_91 * V_75 )
{
struct V_23 * V_23 , * V_73 ;
F_174 (page, n, list, lru) {
F_175 ( & V_23 -> V_143 ) ;
F_171 ( V_13 , V_23 ) ;
}
}
static T_2 F_176 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_34 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 <= V_212 ; V_32 ++ ) {
unsigned int V_35 ;
T_2 V_213 ;
V_35 = F_21 ( V_32 , V_18 , V_15 , & V_213 ) ;
if ( ! V_35 )
continue;
if ( V_35 > V_214 )
break;
if ( V_15 & V_39 ) {
struct V_12 * V_211 ;
T_2 V_215 ;
V_215 = V_35 * sizeof( V_40 ) ;
V_211 = F_177 ( V_215 , 0u ) ;
if ( ! V_211 )
continue;
if ( F_154 ( V_211 ) )
continue;
if ( V_211 -> V_18 > V_13 -> V_18 / 2 )
continue;
}
V_13 -> V_35 = V_35 ;
V_13 -> V_32 = V_32 ;
V_34 = V_213 ;
if ( V_15 & V_177 )
break;
if ( V_32 >= V_49 )
break;
if ( V_34 * 8 <= ( V_37 << V_32 ) )
break;
}
return V_34 ;
}
static struct V_30 T_7 * F_178 (
struct V_12 * V_13 , int V_70 , int V_68 )
{
int V_52 ;
T_2 V_18 ;
struct V_30 T_7 * V_31 ;
V_18 = sizeof( void * ) * V_70 + sizeof( struct V_30 ) ;
V_31 = F_179 ( V_18 , sizeof( void * ) ) ;
if ( ! V_31 )
return NULL ;
F_180 (cpu) {
F_44 ( F_90 ( V_31 , V_52 ) ,
V_70 , V_68 ) ;
}
return V_31 ;
}
static int T_8 F_181 ( struct V_12 * V_13 , T_4 V_71 )
{
if ( V_152 >= V_162 )
return F_118 ( V_13 , V_71 ) ;
V_13 -> V_31 = F_178 ( V_13 , 1 , 1 ) ;
if ( ! V_13 -> V_31 )
return 1 ;
if ( V_152 == V_216 ) {
F_106 ( V_12 , V_159 ) ;
} else if ( V_152 == V_153 ) {
F_106 ( V_13 , V_160 ) ;
} else {
int V_53 ;
F_74 (node) {
V_13 -> V_53 [ V_53 ] = F_47 (
sizeof( struct V_1 ) , V_71 , V_53 ) ;
F_6 ( ! V_13 -> V_53 [ V_53 ] ) ;
F_1 ( V_13 -> V_53 [ V_53 ] ) ;
}
}
V_13 -> V_53 [ F_81 () ] -> V_97 =
V_98 + V_99 +
( ( unsigned long ) V_13 ) % V_99 ;
F_19 ( V_13 ) -> V_67 = 0 ;
F_19 ( V_13 ) -> V_65 = V_217 ;
F_19 ( V_13 ) -> V_68 = 1 ;
F_19 ( V_13 ) -> V_69 = 0 ;
V_13 -> V_68 = 1 ;
V_13 -> V_65 = V_217 ;
return 0 ;
}
unsigned long F_182 ( unsigned long V_194 ,
unsigned long V_15 , const char * V_43 ,
void (* V_184)( void * ) )
{
return V_15 ;
}
struct V_12 *
F_183 ( const char * V_43 , T_2 V_18 , T_2 V_218 ,
unsigned long V_15 , void (* V_184)( void * ) )
{
struct V_12 * V_13 ;
V_13 = F_184 ( V_18 , V_218 , V_15 , V_43 , V_184 ) ;
if ( V_13 ) {
V_13 -> V_219 ++ ;
V_13 -> V_194 = F_185 ( int , V_13 -> V_194 , V_18 ) ;
}
return V_13 ;
}
static bool F_186 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_220 ;
V_13 -> V_35 = 0 ;
if ( V_13 -> V_184 || V_15 & V_210 )
return false ;
V_220 = F_176 ( V_13 , V_18 ,
V_15 | V_38 ) ;
if ( ! V_13 -> V_35 )
return false ;
if ( V_13 -> V_35 * sizeof( V_40 ) > V_13 -> V_194 )
return false ;
V_13 -> V_221 = V_220 / V_13 -> V_222 ;
return true ;
}
static bool F_187 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_220 ;
V_13 -> V_35 = 0 ;
if ( V_15 & V_223 )
return false ;
V_220 = F_176 ( V_13 , V_18 , V_15 | V_39 ) ;
if ( ! V_13 -> V_35 )
return false ;
if ( V_220 >= V_13 -> V_35 * sizeof( V_40 ) )
return false ;
V_13 -> V_221 = V_220 / V_13 -> V_222 ;
return true ;
}
static bool F_188 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_220 ;
V_13 -> V_35 = 0 ;
V_220 = F_176 ( V_13 , V_18 , V_15 ) ;
if ( ! V_13 -> V_35 )
return false ;
V_13 -> V_221 = V_220 / V_13 -> V_222 ;
return true ;
}
int
F_189 ( struct V_12 * V_13 , unsigned long V_15 )
{
T_2 V_224 = V_20 ;
T_4 V_71 ;
int V_105 ;
T_2 V_18 = V_13 -> V_18 ;
#if V_166
#if V_225
if ( V_18 < 4096 || F_190 ( V_18 - 1 ) == F_190 ( V_18 - 1 + V_19 +
2 * sizeof( unsigned long long ) ) )
V_15 |= V_16 | V_17 ;
if ( ! ( V_15 & V_210 ) )
V_15 |= V_207 ;
#endif
#endif
if ( V_18 & ( V_20 - 1 ) ) {
V_18 += ( V_20 - 1 ) ;
V_18 &= ~ ( V_20 - 1 ) ;
}
if ( V_15 & V_16 ) {
V_224 = V_19 ;
V_18 += V_19 - 1 ;
V_18 &= ~ ( V_19 - 1 ) ;
}
if ( V_224 < V_13 -> V_218 ) {
V_224 = V_13 -> V_218 ;
}
if ( V_224 > F_191 (unsigned long long) )
V_15 &= ~ ( V_16 | V_17 ) ;
V_13 -> V_218 = V_224 ;
V_13 -> V_222 = F_192 () ;
if ( V_13 -> V_222 < V_13 -> V_218 )
V_13 -> V_222 = V_13 -> V_218 ;
if ( F_193 () )
V_71 = V_95 ;
else
V_71 = V_140 ;
#if V_166
if ( V_15 & V_16 ) {
V_13 -> F_4 += sizeof( unsigned long long ) ;
V_18 += 2 * sizeof( unsigned long long ) ;
}
if ( V_15 & V_17 ) {
if ( V_15 & V_16 )
V_18 += V_19 ;
else
V_18 += V_20 ;
}
#endif
F_194 ( V_13 , & V_18 , & V_15 ) ;
V_18 = F_195 ( V_18 , V_13 -> V_218 ) ;
if ( V_226 && V_18 < V_227 )
V_18 = F_195 ( V_227 , V_13 -> V_218 ) ;
#if V_166
if ( F_153 () && ( V_15 & V_207 ) &&
V_18 >= 256 && V_13 -> V_194 > F_192 () ) {
if ( V_18 < V_37 || V_18 % V_37 == 0 ) {
T_2 V_228 = F_195 ( V_18 , V_37 ) ;
if ( F_187 ( V_13 , V_228 , V_15 ) ) {
V_15 |= V_39 ;
V_13 -> F_4 += V_228 - V_18 ;
V_18 = V_228 ;
goto V_229;
}
}
}
#endif
if ( F_186 ( V_13 , V_18 , V_15 ) ) {
V_15 |= V_38 ;
goto V_229;
}
if ( F_187 ( V_13 , V_18 , V_15 ) ) {
V_15 |= V_39 ;
goto V_229;
}
if ( F_188 ( V_13 , V_18 , V_15 ) )
goto V_229;
return - V_230 ;
V_229:
V_13 -> V_215 = V_13 -> V_35 * sizeof( V_40 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_176 = V_231 ;
if ( V_232 && ( V_15 & V_233 ) )
V_13 -> V_176 |= V_234 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_29 = F_196 ( V_18 ) ;
#if V_166
if ( F_197 ( V_235 ) &&
( V_13 -> V_15 & V_207 ) &&
F_152 ( V_13 ) )
V_13 -> V_15 &= ~ ( V_16 | V_17 ) ;
#endif
if ( F_154 ( V_13 ) ) {
V_13 -> V_211 =
F_177 ( V_13 -> V_215 , 0u ) ;
}
V_105 = F_181 ( V_13 , V_71 ) ;
if ( V_105 ) {
F_198 ( V_13 ) ;
return V_105 ;
}
return 0 ;
}
static void F_199 ( void )
{
F_6 ( ! F_200 () ) ;
}
static void F_201 ( void )
{
F_6 ( F_200 () ) ;
}
static void F_202 ( struct V_12 * V_13 )
{
#ifdef F_203
F_199 () ;
F_204 ( & F_51 ( V_13 , F_81 () ) -> V_9 ) ;
#endif
}
static void F_205 ( struct V_12 * V_13 , int V_53 )
{
#ifdef F_203
F_199 () ;
F_204 ( & F_51 ( V_13 , V_53 ) -> V_9 ) ;
#endif
}
static void F_206 ( void * V_127 )
{
struct V_12 * V_13 = V_127 ;
struct V_30 * V_64 ;
int V_53 = F_81 () ;
struct V_1 * V_73 ;
F_49 ( V_75 ) ;
F_199 () ;
V_64 = F_19 ( V_13 ) ;
V_73 = F_51 ( V_13 , V_53 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_13 , V_64 -> V_80 , V_64 -> V_67 , V_53 , & V_75 ) ;
F_54 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
V_64 -> V_67 = 0 ;
}
static void F_207 ( struct V_12 * V_13 )
{
struct V_1 * V_73 ;
int V_53 ;
F_208 ( F_206 , V_13 , 1 ) ;
F_201 () ;
F_128 (cachep, node, n)
if ( V_73 -> V_7 )
F_73 ( V_13 , V_73 -> V_7 ) ;
F_128 (cachep, node, n)
F_209 ( V_13 , V_73 , V_73 -> V_6 , 1 , V_53 ) ;
}
static int F_92 ( struct V_12 * V_25 ,
struct V_1 * V_73 , int V_236 )
{
struct V_91 * V_237 ;
int V_186 ;
struct V_23 * V_23 ;
V_186 = 0 ;
while ( V_186 < V_236 && ! F_102 ( & V_73 -> V_5 ) ) {
F_85 ( & V_73 -> V_9 ) ;
V_237 = V_73 -> V_5 . V_238 ;
if ( V_237 == & V_73 -> V_5 ) {
F_72 ( & V_73 -> V_9 ) ;
goto V_132;
}
V_23 = F_210 ( V_237 , struct V_23 , V_143 ) ;
F_175 ( & V_23 -> V_143 ) ;
V_73 -> V_10 -= V_25 -> V_35 ;
F_72 ( & V_73 -> V_9 ) ;
F_171 ( V_25 , V_23 ) ;
V_186 ++ ;
}
V_132:
return V_186 ;
}
int F_211 ( struct V_12 * V_13 , bool V_239 )
{
int V_124 = 0 ;
int V_53 ;
struct V_1 * V_73 ;
F_207 ( V_13 ) ;
F_201 () ;
F_128 (cachep, node, n) {
F_92 ( V_13 , V_73 , F_87 ( V_13 , V_73 ) ) ;
V_124 += ! F_102 ( & V_73 -> V_3 ) ||
! F_102 ( & V_73 -> V_4 ) ;
}
return ( V_124 ? 1 : 0 ) ;
}
int F_212 ( struct V_12 * V_13 )
{
return F_211 ( V_13 , false ) ;
}
void F_198 ( struct V_12 * V_13 )
{
int V_90 ;
struct V_1 * V_73 ;
F_213 ( V_13 -> V_31 ) ;
F_128 (cachep, i, n) {
F_68 ( V_73 -> V_6 ) ;
F_59 ( V_73 -> V_7 ) ;
F_68 ( V_73 ) ;
V_13 -> V_53 [ V_90 ] = NULL ;
}
}
static void * F_214 ( struct V_12 * V_13 ,
struct V_23 * V_23 , int V_222 ,
T_4 V_240 , int V_84 )
{
void * V_208 ;
void * V_192 = F_215 ( V_23 ) ;
V_23 -> V_27 = V_192 + V_222 ;
V_23 -> V_174 = 0 ;
if ( F_169 ( V_13 ) )
V_208 = NULL ;
else if ( F_154 ( V_13 ) ) {
V_208 = F_216 ( V_13 -> V_211 ,
V_240 , V_84 ) ;
if ( ! V_208 )
return NULL ;
} else {
V_208 = V_192 + ( V_37 << V_13 -> V_32 ) -
V_13 -> V_215 ;
}
return V_208 ;
}
static inline V_40 F_217 ( struct V_23 * V_23 , unsigned int V_26 )
{
return ( ( V_40 * ) V_23 -> V_208 ) [ V_26 ] ;
}
static inline void F_218 ( struct V_23 * V_23 ,
unsigned int V_26 , V_40 V_198 )
{
( ( V_40 * ) ( V_23 -> V_208 ) ) [ V_26 ] = V_198 ;
}
static void F_219 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
#if V_166
int V_90 ;
for ( V_90 = 0 ; V_90 < V_13 -> V_35 ; V_90 ++ ) {
void * V_14 = F_16 ( V_13 , V_23 , V_90 ) ;
if ( V_13 -> V_15 & V_17 )
* F_8 ( V_13 , V_14 ) = NULL ;
if ( V_13 -> V_15 & V_16 ) {
* F_5 ( V_13 , V_14 ) = V_209 ;
* F_7 ( V_13 , V_14 ) = V_209 ;
}
if ( V_13 -> V_184 && ! ( V_13 -> V_15 & V_207 ) ) {
F_220 ( V_13 ,
V_14 + F_4 ( V_13 ) ) ;
V_13 -> V_184 ( V_14 + F_4 ( V_13 ) ) ;
F_221 (
V_13 , V_14 + F_4 ( V_13 ) ) ;
}
if ( V_13 -> V_15 & V_16 ) {
if ( * F_7 ( V_13 , V_14 ) != V_209 )
F_170 ( V_13 , L_19 ) ;
if ( * F_5 ( V_13 , V_14 ) != V_209 )
F_170 ( V_13 , L_20 ) ;
}
if ( V_13 -> V_15 & V_207 ) {
F_161 ( V_13 , V_14 , V_202 ) ;
F_159 ( V_13 , V_14 , 0 , 0 ) ;
}
}
#endif
}
static void F_222 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
int V_90 ;
void * V_14 ;
F_219 ( V_13 , V_23 ) ;
if ( F_169 ( V_13 ) ) {
V_23 -> V_208 = F_16 ( V_13 , V_23 , V_13 -> V_35 - 1 ) +
F_4 ( V_13 ) ;
}
for ( V_90 = 0 ; V_90 < V_13 -> V_35 ; V_90 ++ ) {
if ( V_166 == 0 && V_13 -> V_184 ) {
V_14 = F_16 ( V_13 , V_23 , V_90 ) ;
F_220 ( V_13 , V_14 ) ;
V_13 -> V_184 ( V_14 ) ;
F_221 ( V_13 , V_14 ) ;
}
F_218 ( V_23 , V_90 , V_90 ) ;
}
}
static void F_223 ( struct V_12 * V_13 , T_4 V_15 )
{
if ( V_232 ) {
if ( V_15 & V_234 )
F_6 ( ! ( V_13 -> V_176 & V_234 ) ) ;
else
F_6 ( V_13 -> V_176 & V_234 ) ;
}
}
static void * F_224 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
void * V_14 ;
V_14 = F_16 ( V_13 , V_23 , F_217 ( V_23 , V_23 -> V_174 ) ) ;
V_23 -> V_174 ++ ;
#if V_166
if ( V_13 -> V_15 & V_17 )
F_13 ( V_13 ) ;
#endif
return V_14 ;
}
static void F_225 ( struct V_12 * V_13 ,
struct V_23 * V_23 , void * V_14 )
{
unsigned int V_206 = F_17 ( V_13 , V_23 , V_14 ) ;
#if V_166
unsigned int V_90 ;
for ( V_90 = V_23 -> V_174 ; V_90 < V_13 -> V_35 ; V_90 ++ ) {
if ( F_217 ( V_23 , V_90 ) == V_206 ) {
F_23 ( L_21 ,
V_13 -> V_43 , V_14 ) ;
F_119 () ;
}
}
#endif
V_23 -> V_174 -- ;
if ( ! V_23 -> V_208 )
V_23 -> V_208 = V_14 + F_4 ( V_13 ) ;
F_218 ( V_23 , V_23 -> V_174 , V_206 ) ;
}
static void F_226 ( struct V_12 * V_25 , struct V_23 * V_23 ,
void * V_208 )
{
V_23 -> V_24 = V_25 ;
V_23 -> V_208 = V_208 ;
}
static int F_227 ( struct V_12 * V_13 ,
T_4 V_15 , int V_84 , struct V_23 * V_23 )
{
void * V_208 ;
T_2 V_28 ;
T_4 V_240 ;
struct V_1 * V_73 ;
if ( F_37 ( V_15 & V_241 ) ) {
F_228 ( L_22 , V_15 & V_241 ) ;
F_119 () ;
}
V_240 = V_15 & ( V_242 | V_243 ) ;
F_199 () ;
V_73 = F_51 ( V_13 , V_84 ) ;
F_52 ( & V_73 -> V_9 ) ;
V_28 = V_73 -> V_8 ;
V_73 -> V_8 ++ ;
if ( V_73 -> V_8 >= V_13 -> V_221 )
V_73 -> V_8 = 0 ;
F_54 ( & V_73 -> V_9 ) ;
V_28 *= V_13 -> V_222 ;
if ( F_229 ( V_240 ) )
F_230 () ;
F_223 ( V_13 , V_15 ) ;
if ( ! V_23 )
V_23 = F_129 ( V_13 , V_240 , V_84 ) ;
if ( ! V_23 )
goto V_244;
V_208 = F_214 ( V_13 , V_23 , V_28 ,
V_240 & ~ V_242 , V_84 ) ;
if ( F_154 ( V_13 ) && ! V_208 )
goto V_245;
F_226 ( V_13 , V_23 , V_208 ) ;
F_231 ( V_23 ) ;
F_222 ( V_13 , V_23 ) ;
if ( F_229 ( V_240 ) )
F_232 () ;
F_199 () ;
F_52 ( & V_73 -> V_9 ) ;
F_233 ( & V_23 -> V_143 , & ( V_73 -> V_5 ) ) ;
F_234 ( V_13 ) ;
V_73 -> V_10 += V_13 -> V_35 ;
F_54 ( & V_73 -> V_9 ) ;
return 1 ;
V_245:
F_142 ( V_13 , V_23 ) ;
V_244:
if ( F_229 ( V_240 ) )
F_232 () ;
return 0 ;
}
static void F_235 ( const void * V_14 )
{
if ( ! F_236 ( V_14 ) ) {
F_23 ( L_23 ,
( unsigned long ) V_14 ) ;
F_119 () ;
}
}
static inline void F_237 ( struct V_12 * V_25 , void * V_22 )
{
unsigned long long V_246 , V_247 ;
V_246 = * F_5 ( V_25 , V_22 ) ;
V_247 = * F_7 ( V_25 , V_22 ) ;
if ( V_246 == V_248 && V_247 == V_248 )
return;
if ( V_246 == V_209 && V_247 == V_209 )
F_170 ( V_25 , L_24 ) ;
else
F_170 ( V_25 , L_25 ) ;
F_23 ( L_26 ,
V_22 , V_246 , V_247 ) ;
}
static void * F_238 ( struct V_12 * V_13 , void * V_14 ,
unsigned long V_193 )
{
unsigned int V_206 ;
struct V_23 * V_23 ;
F_6 ( F_14 ( V_14 ) != V_13 ) ;
V_14 -= F_4 ( V_13 ) ;
F_235 ( V_14 ) ;
V_23 = F_15 ( V_14 ) ;
if ( V_13 -> V_15 & V_16 ) {
F_237 ( V_13 , V_14 ) ;
* F_5 ( V_13 , V_14 ) = V_209 ;
* F_7 ( V_13 , V_14 ) = V_209 ;
}
if ( V_13 -> V_15 & V_17 ) {
F_13 ( V_13 ) ;
* F_8 ( V_13 , V_14 ) = ( void * ) V_193 ;
}
V_206 = F_17 ( V_13 , V_23 , V_14 ) ;
F_6 ( V_206 >= V_13 -> V_35 ) ;
F_6 ( V_14 != F_16 ( V_13 , V_23 , V_206 ) ) ;
if ( V_13 -> V_15 & V_207 ) {
F_161 ( V_13 , V_14 , V_202 ) ;
F_159 ( V_13 , V_14 , 0 , V_193 ) ;
}
return V_14 ;
}
static inline void F_239 ( struct V_12 * V_13 ,
void * * V_75 )
{
#if V_166
void * V_249 = * V_75 ;
void * V_14 ;
while ( V_249 ) {
V_14 = V_249 - F_4 ( V_13 ) ;
V_249 = * ( void * * ) V_249 ;
F_161 ( V_13 , V_14 , V_202 ) ;
}
#endif
}
static inline void F_240 ( struct V_12 * V_13 ,
struct V_1 * V_73 , struct V_23 * V_23 ,
void * * V_75 )
{
F_175 ( & V_23 -> V_143 ) ;
if ( V_23 -> V_174 == V_13 -> V_35 ) {
F_112 ( & V_23 -> V_143 , & V_73 -> V_3 ) ;
if ( F_169 ( V_13 ) ) {
#if V_166
if ( V_13 -> V_15 & V_207 ) {
void * * V_14 = V_23 -> V_208 ;
* V_14 = * V_75 ;
* V_75 = V_14 ;
}
#endif
V_23 -> V_208 = NULL ;
}
} else
F_112 ( & V_23 -> V_143 , & V_73 -> V_4 ) ;
}
struct V_23 * F_241 ( struct V_1 * V_73 , bool V_250 )
{
struct V_23 * V_23 ;
V_23 = F_242 ( & V_73 -> V_4 ,
struct V_23 , V_143 ) ;
if ( ! V_23 ) {
V_73 -> V_11 = 1 ;
V_23 = F_242 ( & V_73 -> V_5 ,
struct V_23 , V_143 ) ;
}
if ( F_136 () )
return F_243 ( V_73 , V_23 , V_250 ) ;
return V_23 ;
}
static T_5 void * F_244 ( struct V_12 * V_13 ,
struct V_1 * V_73 , T_4 V_15 )
{
struct V_23 * V_23 ;
void * V_22 ;
void * V_75 = NULL ;
if ( ! F_245 ( V_15 ) )
return NULL ;
F_52 ( & V_73 -> V_9 ) ;
V_23 = F_241 ( V_73 , true ) ;
if ( ! V_23 ) {
F_54 ( & V_73 -> V_9 ) ;
return NULL ;
}
V_22 = F_224 ( V_13 , V_23 ) ;
V_73 -> V_10 -- ;
F_240 ( V_13 , V_73 , V_23 , & V_75 ) ;
F_54 ( & V_73 -> V_9 ) ;
F_239 ( V_13 , & V_75 ) ;
return V_22 ;
}
static void * F_246 ( struct V_12 * V_13 , T_4 V_15 )
{
int V_68 ;
struct V_1 * V_73 ;
struct V_30 * V_64 ;
int V_53 ;
void * V_75 = NULL ;
F_199 () ;
V_53 = F_81 () ;
V_251:
V_64 = F_19 ( V_13 ) ;
V_68 = V_64 -> V_68 ;
if ( ! V_64 -> V_69 && V_68 > V_252 ) {
V_68 = V_252 ;
}
V_73 = F_51 ( V_13 , V_53 ) ;
F_6 ( V_64 -> V_67 > 0 || ! V_73 ) ;
F_52 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 && F_56 ( V_64 , V_73 -> V_6 , V_68 ) ) {
V_73 -> V_6 -> V_69 = 1 ;
goto V_253;
}
while ( V_68 > 0 ) {
struct V_23 * V_23 ;
V_23 = F_241 ( V_73 , false ) ;
if ( ! V_23 )
goto V_254;
F_202 ( V_13 ) ;
F_6 ( V_23 -> V_174 >= V_13 -> V_35 ) ;
while ( V_23 -> V_174 < V_13 -> V_35 && V_68 -- ) {
F_247 ( V_13 ) ;
F_248 ( V_13 ) ;
F_249 ( V_13 ) ;
V_64 -> V_80 [ V_64 -> V_67 ++ ] = F_224 ( V_13 , V_23 ) ;
}
F_240 ( V_13 , V_73 , V_23 , & V_75 ) ;
}
V_254:
V_73 -> V_10 -= V_64 -> V_67 ;
V_253:
F_54 ( & V_73 -> V_9 ) ;
F_239 ( V_13 , & V_75 ) ;
if ( F_37 ( ! V_64 -> V_67 ) ) {
int V_255 ;
if ( F_136 () ) {
void * V_22 = F_244 ( V_13 , V_73 , V_15 ) ;
if ( V_22 )
return V_22 ;
}
V_255 = F_227 ( V_13 , F_63 ( V_15 ) , V_53 , NULL ) ;
V_64 = F_19 ( V_13 ) ;
V_53 = F_81 () ;
if ( ! V_255 && V_64 -> V_67 == 0 )
return NULL ;
if ( ! V_64 -> V_67 )
goto V_251;
}
V_64 -> V_69 = 1 ;
return V_64 -> V_80 [ -- V_64 -> V_67 ] ;
}
static inline void F_250 ( struct V_12 * V_13 ,
T_4 V_15 )
{
F_251 ( F_229 ( V_15 ) ) ;
#if V_166
F_223 ( V_13 , V_15 ) ;
#endif
}
static void * F_252 ( struct V_12 * V_13 ,
T_4 V_15 , void * V_14 , unsigned long V_193 )
{
if ( ! V_14 )
return V_14 ;
if ( V_13 -> V_15 & V_207 ) {
F_166 ( V_13 , V_14 ) ;
F_159 ( V_13 , V_14 , 1 , 0 ) ;
F_161 ( V_13 , V_14 , V_256 ) ;
}
if ( V_13 -> V_15 & V_17 )
* F_8 ( V_13 , V_14 ) = ( void * ) V_193 ;
if ( V_13 -> V_15 & V_16 ) {
if ( * F_5 ( V_13 , V_14 ) != V_209 ||
* F_7 ( V_13 , V_14 ) != V_209 ) {
F_170 ( V_13 , L_27 ) ;
F_23 ( L_26 ,
V_14 , * F_5 ( V_13 , V_14 ) ,
* F_7 ( V_13 , V_14 ) ) ;
}
* F_5 ( V_13 , V_14 ) = V_248 ;
* F_7 ( V_13 , V_14 ) = V_248 ;
}
V_14 += F_4 ( V_13 ) ;
if ( V_13 -> V_184 && V_13 -> V_15 & V_207 )
V_13 -> V_184 ( V_14 ) ;
if ( V_257 &&
( ( unsigned long ) V_14 & ( V_257 - 1 ) ) ) {
F_23 ( L_28 ,
V_14 , ( int ) V_257 ) ;
}
return V_14 ;
}
static inline void * F_253 ( struct V_12 * V_13 , T_4 V_15 )
{
void * V_14 ;
struct V_30 * V_64 ;
F_199 () ;
V_64 = F_19 ( V_13 ) ;
if ( F_82 ( V_64 -> V_67 ) ) {
V_64 -> V_69 = 1 ;
V_14 = V_64 -> V_80 [ -- V_64 -> V_67 ] ;
F_254 ( V_13 ) ;
goto V_132;
}
F_255 ( V_13 ) ;
V_14 = F_246 ( V_13 , V_15 ) ;
V_64 = F_19 ( V_13 ) ;
V_132:
if ( V_14 )
F_256 ( & V_64 -> V_80 [ V_64 -> V_67 ] ) ;
return V_14 ;
}
static void * F_61 ( struct V_12 * V_13 , T_4 V_15 )
{
int V_258 , V_259 ;
if ( F_257 () || ( V_15 & V_92 ) )
return NULL ;
V_258 = V_259 = F_81 () ;
if ( F_258 () && ( V_13 -> V_15 & V_260 ) )
V_258 = F_259 () ;
else if ( V_188 -> V_261 )
V_258 = F_260 () ;
if ( V_258 != V_259 )
return F_62 ( V_13 , V_15 , V_258 ) ;
return NULL ;
}
static void * F_261 ( struct V_12 * V_25 , T_4 V_15 )
{
struct V_262 * V_262 ;
T_4 V_240 ;
struct V_263 * V_264 ;
struct V_265 * V_265 ;
enum V_266 V_267 = F_262 ( V_15 ) ;
void * V_22 = NULL ;
int V_130 ;
unsigned int V_268 ;
if ( V_15 & V_92 )
return NULL ;
V_240 = V_15 & ( V_242 | V_243 ) ;
V_269:
V_268 = F_263 () ;
V_262 = F_264 ( F_260 () , V_15 ) ;
V_251:
F_265 (zone, z, zonelist, high_zoneidx) {
V_130 = F_266 ( V_265 ) ;
if ( F_267 ( V_265 , V_15 ) &&
F_51 ( V_25 , V_130 ) &&
F_51 ( V_25 , V_130 ) -> V_10 ) {
V_22 = F_62 ( V_25 ,
F_63 ( V_15 ) , V_130 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
struct V_23 * V_23 ;
if ( F_229 ( V_240 ) )
F_230 () ;
F_223 ( V_25 , V_15 ) ;
V_23 = F_129 ( V_25 , V_240 , F_81 () ) ;
if ( F_229 ( V_240 ) )
F_232 () ;
if ( V_23 ) {
V_130 = F_50 ( V_23 ) ;
if ( F_227 ( V_25 , V_15 , V_130 , V_23 ) ) {
V_22 = F_62 ( V_25 ,
F_63 ( V_15 ) , V_130 ) ;
if ( ! V_22 )
goto V_251;
} else {
V_22 = NULL ;
}
}
}
if ( F_37 ( ! V_22 && F_268 ( V_268 ) ) )
goto V_269;
return V_22 ;
}
static void * F_62 ( struct V_12 * V_13 , T_4 V_15 ,
int V_84 )
{
struct V_23 * V_23 ;
struct V_1 * V_73 ;
void * V_22 ;
void * V_75 = NULL ;
int V_255 ;
F_269 ( V_84 < 0 || V_84 >= V_55 ) ;
V_73 = F_51 ( V_13 , V_84 ) ;
F_6 ( ! V_73 ) ;
V_251:
F_199 () ;
F_52 ( & V_73 -> V_9 ) ;
V_23 = F_241 ( V_73 , false ) ;
if ( ! V_23 )
goto V_254;
F_205 ( V_13 , V_84 ) ;
F_270 ( V_13 ) ;
F_248 ( V_13 ) ;
F_249 ( V_13 ) ;
F_6 ( V_23 -> V_174 == V_13 -> V_35 ) ;
V_22 = F_224 ( V_13 , V_23 ) ;
V_73 -> V_10 -- ;
F_240 ( V_13 , V_73 , V_23 , & V_75 ) ;
F_54 ( & V_73 -> V_9 ) ;
F_239 ( V_13 , & V_75 ) ;
goto V_229;
V_254:
F_54 ( & V_73 -> V_9 ) ;
V_255 = F_227 ( V_13 , F_63 ( V_15 ) , V_84 , NULL ) ;
if ( V_255 )
goto V_251;
return F_261 ( V_13 , V_15 ) ;
V_229:
return V_22 ;
}
static T_9 void *
F_271 ( struct V_12 * V_13 , T_4 V_15 , int V_84 ,
unsigned long V_193 )
{
unsigned long V_270 ;
void * V_139 ;
int V_271 = F_81 () ;
V_15 &= V_272 ;
V_13 = F_272 ( V_13 , V_15 ) ;
if ( F_37 ( ! V_13 ) )
return NULL ;
F_250 ( V_13 , V_15 ) ;
F_273 ( V_270 ) ;
if ( V_84 == V_273 )
V_84 = V_271 ;
if ( F_37 ( ! F_51 ( V_13 , V_84 ) ) ) {
V_139 = F_261 ( V_13 , V_15 ) ;
goto V_132;
}
if ( V_84 == V_271 ) {
V_139 = F_253 ( V_13 , V_15 ) ;
if ( V_139 )
goto V_132;
}
V_139 = F_62 ( V_13 , V_15 , V_84 ) ;
V_132:
F_274 ( V_270 ) ;
V_139 = F_252 ( V_13 , V_15 , V_139 , V_193 ) ;
if ( F_37 ( V_15 & V_274 ) && V_139 )
memset ( V_139 , 0 , V_13 -> V_194 ) ;
F_275 ( V_13 , V_15 , 1 , & V_139 ) ;
return V_139 ;
}
static T_9 void *
F_276 ( struct V_12 * V_25 , T_4 V_15 )
{
void * V_14 ;
if ( V_188 -> V_261 || F_258 () ) {
V_14 = F_61 ( V_25 , V_15 ) ;
if ( V_14 )
goto V_132;
}
V_14 = F_253 ( V_25 , V_15 ) ;
if ( ! V_14 )
V_14 = F_62 ( V_25 , V_15 , F_81 () ) ;
V_132:
return V_14 ;
}
static T_9 void *
F_276 ( struct V_12 * V_13 , T_4 V_15 )
{
return F_253 ( V_13 , V_15 ) ;
}
static T_9 void *
F_277 ( struct V_12 * V_13 , T_4 V_15 , unsigned long V_193 )
{
unsigned long V_270 ;
void * V_14 ;
V_15 &= V_272 ;
V_13 = F_272 ( V_13 , V_15 ) ;
if ( F_37 ( ! V_13 ) )
return NULL ;
F_250 ( V_13 , V_15 ) ;
F_273 ( V_270 ) ;
V_14 = F_276 ( V_13 , V_15 ) ;
F_274 ( V_270 ) ;
V_14 = F_252 ( V_13 , V_15 , V_14 , V_193 ) ;
F_278 ( V_14 ) ;
if ( F_37 ( V_15 & V_274 ) && V_14 )
memset ( V_14 , 0 , V_13 -> V_194 ) ;
F_275 ( V_13 , V_15 , 1 , & V_14 ) ;
return V_14 ;
}
static void F_53 ( struct V_12 * V_13 , void * * V_275 ,
int V_276 , int V_53 , struct V_91 * V_75 )
{
int V_90 ;
struct V_1 * V_73 = F_51 ( V_13 , V_53 ) ;
for ( V_90 = 0 ; V_90 < V_276 ; V_90 ++ ) {
void * V_14 ;
struct V_23 * V_23 ;
V_14 = V_275 [ V_90 ] ;
V_23 = F_15 ( V_14 ) ;
F_175 ( & V_23 -> V_143 ) ;
F_205 ( V_13 , V_53 ) ;
F_225 ( V_13 , V_23 , V_14 ) ;
F_279 ( V_13 ) ;
V_73 -> V_10 ++ ;
if ( V_23 -> V_174 == 0 ) {
if ( V_73 -> V_10 > V_73 -> V_100 ) {
V_73 -> V_10 -= V_13 -> V_35 ;
F_233 ( & V_23 -> V_143 , V_75 ) ;
} else {
F_112 ( & V_23 -> V_143 , & V_73 -> V_5 ) ;
}
} else {
F_233 ( & V_23 -> V_143 , & V_73 -> V_4 ) ;
}
}
}
static void F_280 ( struct V_12 * V_13 , struct V_30 * V_64 )
{
int V_68 ;
struct V_1 * V_73 ;
int V_53 = F_81 () ;
F_49 ( V_75 ) ;
V_68 = V_64 -> V_68 ;
F_199 () ;
V_73 = F_51 ( V_13 , V_53 ) ;
F_52 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 ) {
struct V_30 * V_277 = V_73 -> V_6 ;
int V_78 = V_277 -> V_65 - V_277 -> V_67 ;
if ( V_78 ) {
if ( V_68 > V_78 )
V_68 = V_78 ;
memcpy ( & ( V_277 -> V_80 [ V_277 -> V_67 ] ) ,
V_64 -> V_80 , sizeof( void * ) * V_68 ) ;
V_277 -> V_67 += V_68 ;
goto V_278;
}
}
F_53 ( V_13 , V_64 -> V_80 , V_68 , V_53 , & V_75 ) ;
V_278:
#if V_279
{
int V_90 = 0 ;
struct V_23 * V_23 ;
F_84 (page, &n->slabs_free, lru) {
F_6 ( V_23 -> V_174 ) ;
V_90 ++ ;
}
F_281 ( V_13 , V_90 ) ;
}
#endif
F_54 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
V_64 -> V_67 -= V_68 ;
memmove ( V_64 -> V_80 , & ( V_64 -> V_80 [ V_68 ] ) , sizeof( void * ) * V_64 -> V_67 ) ;
}
static inline void F_282 ( struct V_12 * V_13 , void * V_14 ,
unsigned long V_193 )
{
struct V_30 * V_64 = F_19 ( V_13 ) ;
F_283 ( V_13 , V_14 ) ;
F_199 () ;
F_284 ( V_14 , V_13 -> V_15 ) ;
V_14 = F_238 ( V_13 , V_14 , V_193 ) ;
F_285 ( V_13 , V_14 , V_13 -> V_194 ) ;
if ( V_280 > 1 && F_60 ( V_13 , V_14 ) )
return;
if ( V_64 -> V_67 < V_64 -> V_65 ) {
F_286 ( V_13 ) ;
} else {
F_287 ( V_13 ) ;
F_280 ( V_13 , V_64 ) ;
}
if ( F_136 () ) {
struct V_23 * V_23 = F_15 ( V_14 ) ;
if ( F_37 ( F_288 ( V_23 ) ) ) {
F_48 ( V_13 , V_23 , V_14 ) ;
return;
}
}
V_64 -> V_80 [ V_64 -> V_67 ++ ] = V_14 ;
}
void * F_289 ( struct V_12 * V_13 , T_4 V_15 )
{
void * V_124 = F_277 ( V_13 , V_15 , V_281 ) ;
F_290 ( V_13 , V_124 , V_15 ) ;
F_291 ( V_281 , V_124 ,
V_13 -> V_194 , V_13 -> V_18 , V_15 ) ;
return V_124 ;
}
static T_9 void
F_292 ( struct V_12 * V_46 , T_4 V_15 ,
T_2 V_18 , void * * V_237 , unsigned long V_193 )
{
T_2 V_90 ;
for ( V_90 = 0 ; V_90 < V_18 ; V_90 ++ )
V_237 [ V_90 ] = F_252 ( V_46 , V_15 , V_237 [ V_90 ] , V_193 ) ;
}
int F_293 ( struct V_12 * V_46 , T_4 V_15 , T_2 V_18 ,
void * * V_237 )
{
T_2 V_90 ;
V_46 = F_272 ( V_46 , V_15 ) ;
if ( ! V_46 )
return 0 ;
F_250 ( V_46 , V_15 ) ;
F_232 () ;
for ( V_90 = 0 ; V_90 < V_18 ; V_90 ++ ) {
void * V_14 = F_276 ( V_46 , V_15 ) ;
if ( F_37 ( ! V_14 ) )
goto error;
V_237 [ V_90 ] = V_14 ;
}
F_230 () ;
F_292 ( V_46 , V_15 , V_18 , V_237 , V_281 ) ;
if ( F_37 ( V_15 & V_274 ) )
for ( V_90 = 0 ; V_90 < V_18 ; V_90 ++ )
memset ( V_237 [ V_90 ] , 0 , V_46 -> V_194 ) ;
F_275 ( V_46 , V_15 , V_18 , V_237 ) ;
return V_18 ;
error:
F_230 () ;
F_292 ( V_46 , V_15 , V_90 , V_237 , V_281 ) ;
F_275 ( V_46 , V_15 , V_90 , V_237 ) ;
F_294 ( V_46 , V_90 , V_237 ) ;
return 0 ;
}
void *
F_295 ( struct V_12 * V_13 , T_4 V_15 , T_2 V_18 )
{
void * V_124 ;
V_124 = F_277 ( V_13 , V_15 , V_281 ) ;
F_296 ( V_13 , V_124 , V_18 , V_15 ) ;
F_297 ( V_281 , V_124 ,
V_18 , V_13 -> V_18 , V_15 ) ;
return V_124 ;
}
void * F_216 ( struct V_12 * V_13 , T_4 V_15 , int V_84 )
{
void * V_124 = F_271 ( V_13 , V_15 , V_84 , V_281 ) ;
F_290 ( V_13 , V_124 , V_15 ) ;
F_298 ( V_281 , V_124 ,
V_13 -> V_194 , V_13 -> V_18 ,
V_15 , V_84 ) ;
return V_124 ;
}
void * F_299 ( struct V_12 * V_13 ,
T_4 V_15 ,
int V_84 ,
T_2 V_18 )
{
void * V_124 ;
V_124 = F_271 ( V_13 , V_15 , V_84 , V_281 ) ;
F_296 ( V_13 , V_124 , V_18 , V_15 ) ;
F_300 ( V_281 , V_124 ,
V_18 , V_13 -> V_18 ,
V_15 , V_84 ) ;
return V_124 ;
}
static T_9 void *
F_301 ( T_2 V_18 , T_4 V_15 , int V_53 , unsigned long V_193 )
{
struct V_12 * V_13 ;
void * V_124 ;
V_13 = F_177 ( V_18 , V_15 ) ;
if ( F_37 ( F_302 ( V_13 ) ) )
return V_13 ;
V_124 = F_299 ( V_13 , V_15 , V_53 , V_18 ) ;
F_296 ( V_13 , V_124 , V_18 , V_15 ) ;
return V_124 ;
}
void * F_303 ( T_2 V_18 , T_4 V_15 , int V_53 )
{
return F_301 ( V_18 , V_15 , V_53 , V_281 ) ;
}
void * F_304 ( T_2 V_18 , T_4 V_15 ,
int V_53 , unsigned long V_193 )
{
return F_301 ( V_18 , V_15 , V_53 , V_193 ) ;
}
static T_9 void * F_305 ( T_2 V_18 , T_4 V_15 ,
unsigned long V_193 )
{
struct V_12 * V_13 ;
void * V_124 ;
V_13 = F_177 ( V_18 , V_15 ) ;
if ( F_37 ( F_302 ( V_13 ) ) )
return V_13 ;
V_124 = F_277 ( V_13 , V_15 , V_193 ) ;
F_296 ( V_13 , V_124 , V_18 , V_15 ) ;
F_297 ( V_193 , V_124 ,
V_18 , V_13 -> V_18 , V_15 ) ;
return V_124 ;
}
void * F_306 ( T_2 V_18 , T_4 V_15 )
{
return F_305 ( V_18 , V_15 , V_281 ) ;
}
void * F_307 ( T_2 V_18 , T_4 V_15 , unsigned long V_193 )
{
return F_305 ( V_18 , V_15 , V_193 ) ;
}
void F_173 ( struct V_12 * V_13 , void * V_14 )
{
unsigned long V_15 ;
V_13 = F_308 ( V_13 , V_14 ) ;
if ( ! V_13 )
return;
F_273 ( V_15 ) ;
F_309 ( V_14 , V_13 -> V_194 ) ;
if ( ! ( V_13 -> V_15 & V_282 ) )
F_310 ( V_14 , V_13 -> V_194 ) ;
F_282 ( V_13 , V_14 , V_281 ) ;
F_274 ( V_15 ) ;
F_311 ( V_281 , V_14 ) ;
}
void F_312 ( struct V_12 * V_283 , T_2 V_18 , void * * V_237 )
{
struct V_12 * V_46 ;
T_2 V_90 ;
F_232 () ;
for ( V_90 = 0 ; V_90 < V_18 ; V_90 ++ ) {
void * V_14 = V_237 [ V_90 ] ;
if ( ! V_283 )
V_46 = F_14 ( V_14 ) ;
else
V_46 = F_308 ( V_283 , V_14 ) ;
F_309 ( V_14 , V_46 -> V_194 ) ;
if ( ! ( V_46 -> V_15 & V_282 ) )
F_310 ( V_14 , V_46 -> V_194 ) ;
F_282 ( V_46 , V_14 , V_281 ) ;
}
F_230 () ;
}
void F_68 ( const void * V_14 )
{
struct V_12 * V_284 ;
unsigned long V_15 ;
F_313 ( V_281 , V_14 ) ;
if ( F_37 ( F_302 ( V_14 ) ) )
return;
F_273 ( V_15 ) ;
F_235 ( V_14 ) ;
V_284 = F_14 ( V_14 ) ;
F_309 ( V_14 , V_284 -> V_194 ) ;
F_310 ( V_14 , V_284 -> V_194 ) ;
F_282 ( V_284 , ( void * ) V_14 , V_281 ) ;
F_274 ( V_15 ) ;
}
static int F_314 ( struct V_12 * V_13 , T_4 V_71 )
{
int V_53 ;
struct V_1 * V_73 ;
struct V_30 * V_285 ;
struct V_81 * * V_286 = NULL ;
F_74 (node) {
if ( V_47 ) {
V_286 = F_58 ( V_53 , V_13 -> V_65 , V_71 ) ;
if ( ! V_286 )
goto V_287;
}
V_285 = NULL ;
if ( V_13 -> V_6 ) {
V_285 = F_46 ( V_53 ,
V_13 -> V_6 * V_13 -> V_68 ,
0xbaadf00d , V_71 ) ;
if ( ! V_285 ) {
F_59 ( V_286 ) ;
goto V_287;
}
}
V_73 = F_51 ( V_13 , V_53 ) ;
if ( V_73 ) {
struct V_30 * V_6 = V_73 -> V_6 ;
F_49 ( V_75 ) ;
F_85 ( & V_73 -> V_9 ) ;
if ( V_6 )
F_53 ( V_13 , V_6 -> V_80 ,
V_6 -> V_67 , V_53 , & V_75 ) ;
V_73 -> V_6 = V_285 ;
if ( ! V_73 -> V_7 ) {
V_73 -> V_7 = V_286 ;
V_286 = NULL ;
}
V_73 -> V_100 = ( 1 + F_86 ( V_53 ) ) *
V_13 -> V_68 + V_13 -> V_35 ;
F_72 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
F_68 ( V_6 ) ;
F_59 ( V_286 ) ;
continue;
}
V_73 = F_47 ( sizeof( struct V_1 ) , V_71 , V_53 ) ;
if ( ! V_73 ) {
F_59 ( V_286 ) ;
F_68 ( V_285 ) ;
goto V_287;
}
F_1 ( V_73 ) ;
V_73 -> V_97 = V_98 + V_99 +
( ( unsigned long ) V_13 ) % V_99 ;
V_73 -> V_6 = V_285 ;
V_73 -> V_7 = V_286 ;
V_73 -> V_100 = ( 1 + F_86 ( V_53 ) ) *
V_13 -> V_68 + V_13 -> V_35 ;
V_13 -> V_53 [ V_53 ] = V_73 ;
}
return 0 ;
V_287:
if ( ! V_13 -> V_75 . V_249 ) {
V_53 -- ;
while ( V_53 >= 0 ) {
V_73 = F_51 ( V_13 , V_53 ) ;
if ( V_73 ) {
F_68 ( V_73 -> V_6 ) ;
F_59 ( V_73 -> V_7 ) ;
F_68 ( V_73 ) ;
V_13 -> V_53 [ V_53 ] = NULL ;
}
V_53 -- ;
}
}
return - V_96 ;
}
static int F_315 ( struct V_12 * V_13 , int V_65 ,
int V_68 , int V_6 , T_4 V_71 )
{
struct V_30 T_7 * V_31 , * V_238 ;
int V_52 ;
V_31 = F_178 ( V_13 , V_65 , V_68 ) ;
if ( ! V_31 )
return - V_96 ;
V_238 = V_13 -> V_31 ;
V_13 -> V_31 = V_31 ;
F_316 () ;
F_201 () ;
V_13 -> V_68 = V_68 ;
V_13 -> V_65 = V_65 ;
V_13 -> V_6 = V_6 ;
if ( ! V_238 )
goto V_288;
F_123 (cpu) {
F_49 ( V_75 ) ;
int V_53 ;
struct V_1 * V_73 ;
struct V_30 * V_64 = F_90 ( V_238 , V_52 ) ;
V_53 = F_32 ( V_52 ) ;
V_73 = F_51 ( V_13 , V_53 ) ;
F_85 ( & V_73 -> V_9 ) ;
F_53 ( V_13 , V_64 -> V_80 , V_64 -> V_67 , V_53 , & V_75 ) ;
F_72 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
}
F_213 ( V_238 ) ;
V_288:
return F_314 ( V_13 , V_71 ) ;
}
static int F_317 ( struct V_12 * V_13 , int V_65 ,
int V_68 , int V_6 , T_4 V_71 )
{
int V_124 ;
struct V_12 * V_284 ;
V_124 = F_315 ( V_13 , V_65 , V_68 , V_6 , V_71 ) ;
if ( V_152 < V_162 )
return V_124 ;
if ( ( V_124 < 0 ) || ! F_318 ( V_13 ) )
return V_124 ;
F_319 ( & V_113 ) ;
F_320 (c, cachep) {
F_315 ( V_284 , V_65 , V_68 , V_6 , V_71 ) ;
}
return V_124 ;
}
static int F_118 ( struct V_12 * V_13 , T_4 V_71 )
{
int V_105 ;
int V_65 = 0 ;
int V_6 = 0 ;
int V_68 = 0 ;
if ( ! F_318 ( V_13 ) ) {
struct V_12 * V_289 = F_321 ( V_13 ) ;
V_65 = V_289 -> V_65 ;
V_6 = V_289 -> V_6 ;
V_68 = V_289 -> V_68 ;
}
if ( V_65 && V_6 && V_68 )
goto V_290;
if ( V_13 -> V_18 > 131072 )
V_65 = 1 ;
else if ( V_13 -> V_18 > V_37 )
V_65 = 8 ;
else if ( V_13 -> V_18 > 1024 )
V_65 = 24 ;
else if ( V_13 -> V_18 > 256 )
V_65 = 54 ;
else
V_65 = 120 ;
V_6 = 0 ;
if ( V_13 -> V_18 <= V_37 && F_322 () > 1 )
V_6 = 8 ;
#if V_166
if ( V_65 > 32 )
V_65 = 32 ;
#endif
V_68 = ( V_65 + 1 ) / 2 ;
V_290:
V_105 = F_317 ( V_13 , V_65 , V_68 , V_6 , V_71 ) ;
if ( V_105 )
F_23 ( L_29 ,
V_13 -> V_43 , - V_105 ) ;
return V_105 ;
}
static void F_209 ( struct V_12 * V_13 , struct V_1 * V_73 ,
struct V_30 * V_64 , int V_291 , int V_53 )
{
F_49 ( V_75 ) ;
int V_236 ;
if ( ! V_64 || ! V_64 -> V_67 )
return;
if ( V_64 -> V_69 && ! V_291 ) {
V_64 -> V_69 = 0 ;
} else {
F_85 ( & V_73 -> V_9 ) ;
if ( V_64 -> V_67 ) {
V_236 = V_291 ? V_64 -> V_67 : ( V_64 -> V_65 + 4 ) / 5 ;
if ( V_236 > V_64 -> V_67 )
V_236 = ( V_64 -> V_67 + 1 ) / 2 ;
F_53 ( V_13 , V_64 -> V_80 , V_236 , V_53 , & V_75 ) ;
V_64 -> V_67 -= V_236 ;
memmove ( V_64 -> V_80 , & ( V_64 -> V_80 [ V_236 ] ) ,
sizeof( void * ) * V_64 -> V_67 ) ;
}
F_72 ( & V_73 -> V_9 ) ;
F_55 ( V_13 , & V_75 ) ;
}
}
static void V_62 ( struct V_292 * V_293 )
{
struct V_12 * V_294 ;
struct V_1 * V_73 ;
int V_53 = F_81 () ;
struct V_57 * V_60 = F_323 ( V_293 ) ;
if ( ! F_324 ( & V_113 ) )
goto V_132;
F_84 (searchp, &slab_caches, list) {
F_201 () ;
V_73 = F_51 ( V_294 , V_53 ) ;
F_70 ( V_294 , V_73 ) ;
F_209 ( V_294 , V_73 , F_19 ( V_294 ) , 0 , V_53 ) ;
if ( F_325 ( V_73 -> V_97 , V_98 ) )
goto V_249;
V_73 -> V_97 = V_98 + V_99 ;
F_209 ( V_294 , V_73 , V_73 -> V_6 , 0 , V_53 ) ;
if ( V_73 -> V_11 )
V_73 -> V_11 = 0 ;
else {
int V_295 ;
V_295 = F_92 ( V_294 , V_73 , ( V_73 -> V_100 +
5 * V_294 -> V_35 - 1 ) / ( 5 * V_294 -> V_35 ) ) ;
F_326 ( V_294 , V_295 ) ;
}
V_249:
F_327 () ;
}
F_201 () ;
F_97 ( & V_113 ) ;
F_35 () ;
V_132:
F_328 ( V_60 , F_329 ( V_296 ) ) ;
}
void F_330 ( struct V_12 * V_13 , struct V_297 * V_298 )
{
struct V_23 * V_23 ;
unsigned long V_170 ;
unsigned long V_171 ;
unsigned long V_172 = 0 ;
unsigned long V_173 , V_10 = 0 , V_299 = 0 ;
const char * V_43 ;
char * error = NULL ;
int V_53 ;
struct V_1 * V_73 ;
V_170 = 0 ;
V_173 = 0 ;
F_128 (cachep, node, n) {
F_201 () ;
F_85 ( & V_73 -> V_9 ) ;
F_84 (page, &n->slabs_full, lru) {
if ( V_23 -> V_174 != V_13 -> V_35 && ! error )
error = L_30 ;
V_170 += V_13 -> V_35 ;
V_172 ++ ;
}
F_84 (page, &n->slabs_partial, lru) {
if ( V_23 -> V_174 == V_13 -> V_35 && ! error )
error = L_31 ;
if ( ! V_23 -> V_174 && ! error )
error = L_31 ;
V_170 += V_23 -> V_174 ;
V_172 ++ ;
}
F_84 (page, &n->slabs_free, lru) {
if ( V_23 -> V_174 && ! error )
error = L_32 ;
V_173 ++ ;
}
V_10 += V_73 -> V_10 ;
if ( V_73 -> V_6 )
V_299 += V_73 -> V_6 -> V_67 ;
F_72 ( & V_73 -> V_9 ) ;
}
V_173 += V_172 ;
V_171 = V_173 * V_13 -> V_35 ;
if ( V_171 - V_170 != V_10 && ! error )
error = L_33 ;
V_43 = V_13 -> V_43 ;
if ( error )
F_23 ( L_34 , V_43 , error ) ;
V_298 -> V_170 = V_170 ;
V_298 -> V_171 = V_171 ;
V_298 -> V_172 = V_172 ;
V_298 -> V_173 = V_173 ;
V_298 -> V_299 = V_299 ;
V_298 -> V_65 = V_13 -> V_65 ;
V_298 -> V_68 = V_13 -> V_68 ;
V_298 -> V_6 = V_13 -> V_6 ;
V_298 -> V_300 = V_13 -> V_35 ;
V_298 -> V_301 = V_13 -> V_32 ;
}
void F_331 ( struct V_302 * V_303 , struct V_12 * V_13 )
{
#if V_279
{
unsigned long V_304 = V_13 -> V_305 ;
unsigned long V_306 = V_13 -> V_307 ;
unsigned long V_308 = V_13 -> V_308 ;
unsigned long V_309 = V_13 -> V_309 ;
unsigned long V_310 = V_13 -> V_310 ;
unsigned long V_311 = V_13 -> V_311 ;
unsigned long V_312 = V_13 -> V_312 ;
unsigned long V_313 = V_13 -> V_313 ;
unsigned long V_314 = V_13 -> V_315 ;
F_332 ( V_303 , L_35 ,
V_306 , V_304 , V_308 ,
V_309 , V_310 , V_311 , V_312 ,
V_313 , V_314 ) ;
}
{
unsigned long V_316 = F_10 ( & V_13 -> V_316 ) ;
unsigned long V_317 = F_10 ( & V_13 -> V_317 ) ;
unsigned long V_318 = F_10 ( & V_13 -> V_318 ) ;
unsigned long V_319 = F_10 ( & V_13 -> V_319 ) ;
F_332 ( V_303 , L_36 ,
V_316 , V_317 , V_318 , V_319 ) ;
}
#endif
}
T_10 F_333 ( struct V_320 * V_320 , const char T_11 * V_321 ,
T_2 V_322 , T_12 * V_323 )
{
char V_324 [ V_325 + 1 ] , * V_326 ;
int V_65 , V_68 , V_6 , V_327 ;
struct V_12 * V_13 ;
if ( V_322 > V_325 )
return - V_328 ;
if ( F_334 ( & V_324 , V_321 , V_322 ) )
return - V_329 ;
V_324 [ V_325 ] = '\0' ;
V_326 = strchr ( V_324 , ' ' ) ;
if ( ! V_326 )
return - V_328 ;
* V_326 = '\0' ;
V_326 ++ ;
if ( sscanf ( V_326 , L_37 , & V_65 , & V_68 , & V_6 ) != 3 )
return - V_328 ;
F_96 ( & V_113 ) ;
V_327 = - V_328 ;
F_84 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_13 -> V_43 , V_324 ) ) {
if ( V_65 < 1 || V_68 < 1 ||
V_68 > V_65 || V_6 < 0 ) {
V_327 = 0 ;
} else {
V_327 = F_317 ( V_13 , V_65 ,
V_68 , V_6 ,
V_95 ) ;
}
break;
}
}
F_97 ( & V_113 ) ;
if ( V_327 >= 0 )
V_327 = V_322 ;
return V_327 ;
}
static inline int F_335 ( unsigned long * V_73 , unsigned long V_330 )
{
unsigned long * V_237 ;
int V_331 ;
if ( ! V_330 )
return 1 ;
V_331 = V_73 [ 1 ] ;
V_237 = V_73 + 2 ;
while ( V_331 ) {
int V_90 = V_331 / 2 ;
unsigned long * V_332 = V_237 + 2 * V_90 ;
if ( * V_332 == V_330 ) {
V_332 [ 1 ] ++ ;
return 1 ;
}
if ( * V_332 > V_330 ) {
V_331 = V_90 ;
} else {
V_237 = V_332 + 2 ;
V_331 -= V_90 + 1 ;
}
}
if ( ++ V_73 [ 1 ] == V_73 [ 0 ] )
return 0 ;
memmove ( V_237 + 2 , V_237 , V_73 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_237 - ( void * ) V_73 ) ) ;
V_237 [ 0 ] = V_330 ;
V_237 [ 1 ] = 1 ;
return 1 ;
}
static void F_336 ( unsigned long * V_73 , struct V_12 * V_284 ,
struct V_23 * V_23 )
{
void * V_237 ;
int V_90 , V_333 ;
unsigned long V_330 ;
if ( V_73 [ 0 ] == V_73 [ 1 ] )
return;
for ( V_90 = 0 , V_237 = V_23 -> V_27 ; V_90 < V_284 -> V_35 ; V_90 ++ , V_237 += V_284 -> V_18 ) {
bool V_174 = true ;
for ( V_333 = V_23 -> V_174 ; V_333 < V_284 -> V_35 ; V_333 ++ ) {
if ( F_217 ( V_23 , V_333 ) == V_90 ) {
V_174 = false ;
break;
}
}
if ( ! V_174 )
continue;
if ( F_337 ( & V_330 , F_8 ( V_284 , V_237 ) , sizeof( V_330 ) ) )
continue;
if ( ! F_335 ( V_73 , V_330 ) )
return;
}
}
static void F_338 ( struct V_302 * V_303 , unsigned long V_334 )
{
#ifdef F_339
unsigned long V_28 , V_18 ;
char V_335 [ V_336 ] , V_43 [ V_337 ] ;
if ( F_340 ( V_334 , & V_18 , & V_28 , V_335 , V_43 ) == 0 ) {
F_332 ( V_303 , L_38 , V_43 , V_28 , V_18 ) ;
if ( V_335 [ 0 ] )
F_332 ( V_303 , L_39 , V_335 ) ;
return;
}
#endif
F_332 ( V_303 , L_40 , ( void * ) V_334 ) ;
}
static int F_341 ( struct V_302 * V_303 , void * V_237 )
{
struct V_12 * V_13 = F_210 ( V_237 , struct V_12 , V_75 ) ;
struct V_23 * V_23 ;
struct V_1 * V_73 ;
const char * V_43 ;
unsigned long * V_255 = V_303 -> V_338 ;
int V_53 ;
int V_90 ;
if ( ! ( V_13 -> V_15 & V_17 ) )
return 0 ;
if ( ! ( V_13 -> V_15 & V_16 ) )
return 0 ;
do {
F_11 ( V_13 ) ;
F_207 ( V_13 ) ;
V_255 [ 1 ] = 0 ;
F_128 (cachep, node, n) {
F_201 () ;
F_85 ( & V_73 -> V_9 ) ;
F_84 (page, &n->slabs_full, lru)
F_336 ( V_255 , V_13 , V_23 ) ;
F_84 (page, &n->slabs_partial, lru)
F_336 ( V_255 , V_13 , V_23 ) ;
F_72 ( & V_73 -> V_9 ) ;
}
} while ( ! F_9 ( V_13 ) );
V_43 = V_13 -> V_43 ;
if ( V_255 [ 0 ] == V_255 [ 1 ] ) {
F_97 ( & V_113 ) ;
V_303 -> V_338 = F_342 ( V_255 [ 0 ] * 4 * sizeof( unsigned long ) , V_95 ) ;
if ( ! V_303 -> V_338 ) {
V_303 -> V_338 = V_255 ;
F_96 ( & V_113 ) ;
return - V_96 ;
}
* ( unsigned long * ) V_303 -> V_338 = V_255 [ 0 ] * 2 ;
F_68 ( V_255 ) ;
F_96 ( & V_113 ) ;
V_303 -> V_322 = V_303 -> V_18 ;
return 0 ;
}
for ( V_90 = 0 ; V_90 < V_255 [ 1 ] ; V_90 ++ ) {
F_332 ( V_303 , L_41 , V_43 , V_255 [ 2 * V_90 + 3 ] ) ;
F_338 ( V_303 , V_255 [ 2 * V_90 + 2 ] ) ;
F_343 ( V_303 , '\n' ) ;
}
return 0 ;
}
static int F_344 ( struct V_339 * V_339 , struct V_320 * V_320 )
{
unsigned long * V_73 ;
V_73 = F_345 ( V_320 , & V_340 , V_37 ) ;
if ( ! V_73 )
return - V_96 ;
* V_73 = V_37 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_346 ( void )
{
#ifdef F_347
F_348 ( L_42 , 0 , NULL , & V_341 ) ;
#endif
return 0 ;
}
T_2 F_349 ( const void * V_14 )
{
T_2 V_18 ;
F_6 ( ! V_14 ) ;
if ( F_37 ( V_14 == V_342 ) )
return 0 ;
V_18 = F_14 ( V_14 ) -> V_194 ;
F_350 ( V_14 , V_18 , V_140 ) ;
return V_18 ;
}
