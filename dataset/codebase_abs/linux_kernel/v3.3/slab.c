static T_1 int F_1 ( const T_2 V_1 )
{
extern void V_2 ( void ) ;
if ( F_2 ( V_1 ) ) {
int V_3 = 0 ;
#define F_3 ( T_3 ) \
if (size <=x) \
return i; \
else \
i++;
#include <linux/kmalloc_sizes.h>
#undef F_3
V_2 () ;
} else
V_2 () ;
return 0 ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_6 ) ;
F_5 ( & V_5 -> V_7 ) ;
F_5 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = NULL ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = 0 ;
F_6 ( & V_5 -> V_12 ) ;
V_5 -> V_13 = 0 ;
V_5 -> V_14 = 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
return V_16 -> F_7 ;
}
static int F_8 ( struct V_15 * V_16 )
{
return V_16 -> F_8 ;
}
static unsigned long long * F_9 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_19 ) ) ;
return ( unsigned long long * ) ( V_17 + F_7 ( V_16 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_11 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_19 ) ) ;
if ( V_16 -> V_18 & V_20 )
return ( unsigned long long * ) ( V_17 + V_16 -> V_21 -
sizeof( unsigned long long ) -
V_22 ) ;
return ( unsigned long long * ) ( V_17 + V_16 -> V_21 -
sizeof( unsigned long long ) ) ;
}
static void * * F_12 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_20 ) ) ;
return ( void * * ) ( V_17 + V_16 -> V_21 - V_23 ) ;
}
T_2 F_13 ( struct V_15 * V_16 )
{
return V_16 -> V_21 ;
}
static inline void F_14 ( struct V_24 * V_24 , struct V_15 * V_25 )
{
V_24 -> V_26 . V_27 = (struct V_28 * ) V_25 ;
}
static inline struct V_15 * F_15 ( struct V_24 * V_24 )
{
V_24 = F_16 ( V_24 ) ;
F_10 ( ! F_17 ( V_24 ) ) ;
return (struct V_15 * ) V_24 -> V_26 . V_27 ;
}
static inline void F_18 ( struct V_24 * V_24 , struct V_29 * V_29 )
{
V_24 -> V_26 . V_30 = (struct V_28 * ) V_29 ;
}
static inline struct V_29 * F_19 ( struct V_24 * V_24 )
{
F_10 ( ! F_17 ( V_24 ) ) ;
return (struct V_29 * ) V_24 -> V_26 . V_30 ;
}
static inline struct V_15 * F_20 ( const void * V_31 )
{
struct V_24 * V_24 = F_21 ( V_31 ) ;
return F_15 ( V_24 ) ;
}
static inline struct V_29 * F_22 ( const void * V_31 )
{
struct V_24 * V_24 = F_21 ( V_31 ) ;
return F_19 ( V_24 ) ;
}
static inline void * F_23 ( struct V_15 * V_25 , struct V_29 * V_29 ,
unsigned int V_32 )
{
return V_29 -> V_33 + V_25 -> V_21 * V_32 ;
}
static inline unsigned int F_24 ( const struct V_15 * V_25 ,
const struct V_29 * V_29 , void * V_31 )
{
T_4 V_34 = ( V_31 - V_29 -> V_33 ) ;
return F_25 ( V_34 , V_25 -> V_35 ) ;
}
int F_26 ( void )
{
return V_36 >= V_37 ;
}
static void F_27 ( struct V_15 * V_16 ,
struct V_38 * V_39 , struct V_38 * V_40 ,
int V_41 )
{
struct V_42 * * V_43 ;
struct V_4 * V_44 ;
int V_45 ;
V_44 = V_16 -> V_46 [ V_41 ] ;
if ( ! V_44 )
return;
F_28 ( & V_44 -> V_12 , V_39 ) ;
V_43 = V_44 -> V_10 ;
if ( ! V_43 || ( unsigned long ) V_43 == V_47 )
return;
F_29 (r) {
if ( V_43 [ V_45 ] )
F_28 ( & V_43 [ V_45 ] -> V_48 , V_40 ) ;
}
}
static void F_30 ( struct V_15 * V_16 , int V_49 )
{
F_27 ( V_16 , & V_50 , & V_51 , V_49 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
int V_49 ;
F_32 (node)
F_30 ( V_16 , V_49 ) ;
}
static void F_33 ( int V_41 )
{
struct V_52 * V_53 = V_54 ;
if ( V_36 < V_55 )
return;
for ( V_53 = V_54 ; V_53 -> V_56 != V_57 ; V_53 ++ ) {
struct V_4 * V_44 ;
V_44 = V_53 -> V_58 -> V_46 [ V_41 ] ;
if ( ! V_44 || F_34 ( V_53 -> V_58 ) )
continue;
F_27 ( V_53 -> V_58 , & V_59 ,
& V_60 , V_41 ) ;
}
}
static inline void F_35 ( void )
{
int V_49 ;
F_29 (node)
F_33 ( V_49 ) ;
}
static void F_33 ( int V_41 )
{
}
static inline void F_35 ( void )
{
}
static void F_30 ( struct V_15 * V_16 , int V_49 )
{
}
static void F_31 ( struct V_15 * V_16 )
{
}
static inline struct V_42 * F_36 ( struct V_15 * V_16 )
{
return V_16 -> V_61 [ F_37 () ] ;
}
static inline struct V_15 * F_38 ( T_2 V_1 ,
T_5 V_62 )
{
struct V_52 * V_63 = V_54 ;
#if V_64
F_10 ( V_54 [ V_65 ] . V_58 == NULL ) ;
#endif
if ( ! V_1 )
return V_66 ;
while ( V_1 > V_63 -> V_56 )
V_63 ++ ;
#ifdef F_39
if ( F_40 ( V_62 & V_67 ) )
return V_63 -> V_68 ;
#endif
return V_63 -> V_58 ;
}
static struct V_15 * F_41 ( T_2 V_1 , T_5 V_62 )
{
return F_38 ( V_1 , V_62 ) ;
}
static T_2 F_42 ( T_2 V_69 , T_2 V_70 )
{
return F_43 ( sizeof( struct V_29 ) + V_69 * sizeof( V_71 ) , V_70 ) ;
}
static void F_44 ( unsigned long V_72 , T_2 V_21 ,
T_2 V_70 , int V_18 , T_2 * V_73 ,
unsigned int * V_74 )
{
int V_69 ;
T_2 V_75 ;
T_2 V_76 = V_77 << V_72 ;
if ( V_18 & V_78 ) {
V_75 = 0 ;
V_69 = V_76 / V_21 ;
if ( V_69 > V_79 )
V_69 = V_79 ;
} else {
V_69 = ( V_76 - sizeof( struct V_29 ) ) /
( V_21 + sizeof( V_71 ) ) ;
if ( F_42 ( V_69 , V_70 ) + V_69 * V_21
> V_76 )
V_69 -- ;
if ( V_69 > V_79 )
V_69 = V_79 ;
V_75 = F_42 ( V_69 , V_70 ) ;
}
* V_74 = V_69 ;
* V_73 = V_76 - V_69 * V_21 - V_75 ;
}
static void F_45 ( const char * V_80 , struct V_15 * V_16 ,
char * V_81 )
{
F_46 ( V_82 L_1 ,
V_80 , V_16 -> V_83 , V_81 ) ;
F_47 () ;
}
static int T_6 F_48 ( char * V_53 )
{
V_84 = 0 ;
return 1 ;
}
static int T_6 F_49 ( char * V_85 )
{
F_50 ( & V_85 , & V_86 ) ;
V_86 = V_86 < 0 ? 0 :
F_51 ( V_86 , V_87 - 1 ) ;
V_88 = true ;
return 1 ;
}
static void F_52 ( int V_89 )
{
int V_49 ;
V_49 = F_53 ( F_54 ( V_89 ) , V_90 ) ;
if ( V_49 == V_91 )
V_49 = F_55 ( V_90 ) ;
F_56 ( V_92 , V_89 ) = V_49 ;
}
static void F_57 ( void )
{
int V_49 = F_58 ( V_92 ) ;
V_49 = F_53 ( V_49 , V_90 ) ;
if ( F_40 ( V_49 >= V_91 ) )
V_49 = F_55 ( V_90 ) ;
F_59 ( V_92 , V_49 ) ;
}
static void T_7 F_60 ( int V_89 )
{
struct V_93 * V_94 = & F_56 ( V_95 , V_89 ) ;
if ( F_61 () && V_94 -> V_96 . V_97 == NULL ) {
F_52 ( V_89 ) ;
F_62 ( V_94 , V_98 ) ;
F_63 ( V_89 , V_94 ,
F_64 ( V_99 , V_89 ) ) ;
}
}
static struct V_42 * F_65 ( int V_49 , int V_100 ,
int V_101 , T_5 V_102 )
{
int V_103 = sizeof( void * ) * V_100 + sizeof( struct V_42 ) ;
struct V_42 * V_104 = NULL ;
V_104 = F_66 ( V_103 , V_102 , V_49 ) ;
F_67 ( V_104 ) ;
if ( V_104 ) {
V_104 -> V_105 = 0 ;
V_104 -> V_106 = V_100 ;
V_104 -> V_101 = V_101 ;
V_104 -> V_107 = 0 ;
F_6 ( & V_104 -> V_48 ) ;
}
return V_104 ;
}
static int F_68 ( struct V_42 * V_108 ,
struct V_42 * V_109 , unsigned int V_110 )
{
int V_111 = F_69 ( V_109 -> V_105 , V_110 , V_108 -> V_106 - V_108 -> V_105 ) ;
if ( ! V_111 )
return 0 ;
memcpy ( V_108 -> V_112 + V_108 -> V_105 , V_109 -> V_112 + V_109 -> V_105 - V_111 ,
sizeof( void * ) * V_111 ) ;
V_109 -> V_105 -= V_111 ;
V_108 -> V_105 += V_111 ;
return V_111 ;
}
static inline struct V_42 * * F_70 ( int V_49 , int V_106 , T_5 V_102 )
{
return (struct V_42 * * ) V_47 ;
}
static inline void F_71 ( struct V_42 * * V_113 )
{
}
static inline int F_72 ( struct V_15 * V_16 , void * V_17 )
{
return 0 ;
}
static inline void * F_73 ( struct V_15 * V_16 ,
T_5 V_18 )
{
return NULL ;
}
static inline void * F_74 ( struct V_15 * V_16 ,
T_5 V_18 , int V_114 )
{
return NULL ;
}
static struct V_42 * * F_70 ( int V_49 , int V_106 , T_5 V_102 )
{
struct V_42 * * V_113 ;
int V_103 = sizeof( void * ) * V_115 ;
int V_3 ;
if ( V_106 > 1 )
V_106 = 12 ;
V_113 = F_75 ( V_103 , V_102 , V_49 ) ;
if ( V_113 ) {
F_29 (i) {
if ( V_3 == V_49 || ! F_76 ( V_3 ) )
continue;
V_113 [ V_3 ] = F_65 ( V_49 , V_106 , 0xbaadf00d , V_102 ) ;
if ( ! V_113 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_77 ( V_113 [ V_3 ] ) ;
F_77 ( V_113 ) ;
return NULL ;
}
}
}
return V_113 ;
}
static void F_71 ( struct V_42 * * V_113 )
{
int V_3 ;
if ( ! V_113 )
return;
F_29 (i)
F_77 ( V_113 [ V_3 ] ) ;
F_77 ( V_113 ) ;
}
static void F_78 ( struct V_15 * V_16 ,
struct V_42 * V_116 , int V_49 )
{
struct V_4 * V_117 = V_16 -> V_46 [ V_49 ] ;
if ( V_116 -> V_105 ) {
F_79 ( & V_117 -> V_12 ) ;
if ( V_117 -> V_9 )
F_68 ( V_117 -> V_9 , V_116 , V_116 -> V_106 ) ;
F_80 ( V_16 , V_116 -> V_112 , V_116 -> V_105 , V_49 ) ;
V_116 -> V_105 = 0 ;
F_81 ( & V_117 -> V_12 ) ;
}
}
static void F_82 ( struct V_15 * V_16 , struct V_4 * V_44 )
{
int V_49 = F_58 ( V_92 ) ;
if ( V_44 -> V_10 ) {
struct V_42 * V_116 = V_44 -> V_10 [ V_49 ] ;
if ( V_116 && V_116 -> V_105 && F_83 ( & V_116 -> V_48 ) ) {
F_78 ( V_16 , V_116 , V_49 ) ;
F_84 ( & V_116 -> V_48 ) ;
}
}
}
static void F_85 ( struct V_15 * V_16 ,
struct V_42 * * V_10 )
{
int V_3 = 0 ;
struct V_42 * V_116 ;
unsigned long V_18 ;
F_32 (i) {
V_116 = V_10 [ V_3 ] ;
if ( V_116 ) {
F_86 ( & V_116 -> V_48 , V_18 ) ;
F_78 ( V_16 , V_116 , V_3 ) ;
F_87 ( & V_116 -> V_48 , V_18 ) ;
}
}
}
static inline int F_72 ( struct V_15 * V_16 , void * V_17 )
{
struct V_29 * V_118 = F_22 ( V_17 ) ;
int V_114 = V_118 -> V_114 ;
struct V_4 * V_44 ;
struct V_42 * V_10 = NULL ;
int V_49 ;
V_49 = F_88 () ;
if ( F_89 ( V_118 -> V_114 == V_49 ) )
return 0 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_90 ( V_16 ) ;
if ( V_44 -> V_10 && V_44 -> V_10 [ V_114 ] ) {
V_10 = V_44 -> V_10 [ V_114 ] ;
F_79 ( & V_10 -> V_48 ) ;
if ( F_40 ( V_10 -> V_105 == V_10 -> V_106 ) ) {
F_91 ( V_16 ) ;
F_78 ( V_16 , V_10 , V_114 ) ;
}
V_10 -> V_112 [ V_10 -> V_105 ++ ] = V_17 ;
F_81 ( & V_10 -> V_48 ) ;
} else {
F_79 ( & ( V_16 -> V_46 [ V_114 ] ) -> V_12 ) ;
F_80 ( V_16 , & V_17 , 1 , V_114 ) ;
F_81 ( & ( V_16 -> V_46 [ V_114 ] ) -> V_12 ) ;
}
return 1 ;
}
static int F_92 ( int V_49 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 ;
const int V_103 = sizeof( struct V_4 ) ;
F_93 (cachep, &cache_chain, next) {
if ( ! V_16 -> V_46 [ V_49 ] ) {
V_44 = F_66 ( V_103 , V_119 , V_49 ) ;
if ( ! V_44 )
return - V_120 ;
F_4 ( V_44 ) ;
V_44 -> V_121 = V_122 + V_123 +
( ( unsigned long ) V_16 ) % V_123 ;
V_16 -> V_46 [ V_49 ] = V_44 ;
}
F_94 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
V_16 -> V_46 [ V_49 ] -> V_124 =
( 1 + F_95 ( V_49 ) ) *
V_16 -> V_101 + V_16 -> V_74 ;
F_84 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
}
return 0 ;
}
static void T_7 F_96 ( long V_89 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 = NULL ;
int V_49 = F_54 ( V_89 ) ;
const struct V_125 * V_126 = F_97 ( V_49 ) ;
F_93 (cachep, &cache_chain, next) {
struct V_42 * V_104 ;
struct V_42 * V_9 ;
struct V_42 * * V_10 ;
V_104 = V_16 -> V_61 [ V_89 ] ;
V_16 -> V_61 [ V_89 ] = NULL ;
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
goto V_127;
F_94 ( & V_44 -> V_12 ) ;
V_44 -> V_124 -= V_16 -> V_101 ;
if ( V_104 )
F_80 ( V_16 , V_104 -> V_112 , V_104 -> V_105 , V_49 ) ;
if ( ! F_98 ( V_126 ) ) {
F_84 ( & V_44 -> V_12 ) ;
goto V_127;
}
V_9 = V_44 -> V_9 ;
if ( V_9 ) {
F_80 ( V_16 , V_9 -> V_112 ,
V_9 -> V_105 , V_49 ) ;
V_44 -> V_9 = NULL ;
}
V_10 = V_44 -> V_10 ;
V_44 -> V_10 = NULL ;
F_84 ( & V_44 -> V_12 ) ;
F_77 ( V_9 ) ;
if ( V_10 ) {
F_85 ( V_16 , V_10 ) ;
F_71 ( V_10 ) ;
}
V_127:
F_77 ( V_104 ) ;
}
F_93 (cachep, &cache_chain, next) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_99 ( V_16 , V_44 , V_44 -> V_13 ) ;
}
}
static int T_7 F_100 ( long V_89 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 = NULL ;
int V_49 = F_54 ( V_89 ) ;
int V_128 ;
V_128 = F_92 ( V_49 ) ;
if ( V_128 < 0 )
goto V_129;
F_93 (cachep, &cache_chain, next) {
struct V_42 * V_104 ;
struct V_42 * V_9 = NULL ;
struct V_42 * * V_10 = NULL ;
V_104 = F_65 ( V_49 , V_16 -> V_106 ,
V_16 -> V_101 , V_119 ) ;
if ( ! V_104 )
goto V_129;
if ( V_16 -> V_9 ) {
V_9 = F_65 ( V_49 ,
V_16 -> V_9 * V_16 -> V_101 ,
0xbaadf00d , V_119 ) ;
if ( ! V_9 ) {
F_77 ( V_104 ) ;
goto V_129;
}
}
if ( V_84 ) {
V_10 = F_70 ( V_49 , V_16 -> V_106 , V_119 ) ;
if ( ! V_10 ) {
F_77 ( V_9 ) ;
F_77 ( V_104 ) ;
goto V_129;
}
}
V_16 -> V_61 [ V_89 ] = V_104 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_10 ( ! V_44 ) ;
F_94 ( & V_44 -> V_12 ) ;
if ( ! V_44 -> V_9 ) {
V_44 -> V_9 = V_9 ;
V_9 = NULL ;
}
#ifdef F_101
if ( ! V_44 -> V_10 ) {
V_44 -> V_10 = V_10 ;
V_10 = NULL ;
}
#endif
F_84 ( & V_44 -> V_12 ) ;
F_77 ( V_9 ) ;
F_71 ( V_10 ) ;
if ( V_16 -> V_18 & V_130 )
F_30 ( V_16 , V_49 ) ;
}
F_33 ( V_49 ) ;
return 0 ;
V_129:
F_96 ( V_89 ) ;
return - V_120 ;
}
static int T_7 F_102 ( struct V_131 * V_132 ,
unsigned long V_133 , void * V_134 )
{
long V_89 = ( long ) V_134 ;
int V_128 = 0 ;
switch ( V_133 ) {
case V_135 :
case V_136 :
F_103 ( & V_137 ) ;
V_128 = F_100 ( V_89 ) ;
F_104 ( & V_137 ) ;
break;
case V_138 :
case V_139 :
F_60 ( V_89 ) ;
break;
#ifdef F_105
case V_140 :
case V_141 :
F_106 ( & F_56 ( V_95 , V_89 ) ) ;
F_56 ( V_95 , V_89 ) . V_96 . V_97 = NULL ;
break;
case V_142 :
case V_143 :
F_60 ( V_89 ) ;
break;
case V_144 :
case V_145 :
#endif
case V_146 :
case V_147 :
F_103 ( & V_137 ) ;
F_96 ( V_89 ) ;
F_104 ( & V_137 ) ;
break;
}
return F_107 ( V_128 ) ;
}
static int T_8 F_108 ( int V_49 )
{
struct V_15 * V_16 ;
int V_148 = 0 ;
F_93 (cachep, &cache_chain, next) {
struct V_4 * V_44 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_99 ( V_16 , V_44 , V_44 -> V_13 ) ;
if ( ! F_109 ( & V_44 -> V_6 ) ||
! F_109 ( & V_44 -> V_7 ) ) {
V_148 = - V_149 ;
break;
}
}
return V_148 ;
}
static int T_8 F_110 ( struct V_131 * V_150 ,
unsigned long V_133 , void * V_151 )
{
struct V_152 * V_153 = V_151 ;
int V_148 = 0 ;
int V_154 ;
V_154 = V_153 -> V_155 ;
if ( V_154 < 0 )
goto V_156;
switch ( V_133 ) {
case V_157 :
F_103 ( & V_137 ) ;
V_148 = F_92 ( V_154 ) ;
F_104 ( & V_137 ) ;
break;
case V_158 :
F_103 ( & V_137 ) ;
V_148 = F_108 ( V_154 ) ;
F_104 ( & V_137 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
case V_162 :
break;
}
V_156:
return F_107 ( V_148 ) ;
}
static void T_6 F_111 ( struct V_15 * V_16 , struct V_4 * V_163 ,
int V_114 )
{
struct V_4 * V_164 ;
V_164 = F_66 ( sizeof( struct V_4 ) , V_165 , V_114 ) ;
F_10 ( ! V_164 ) ;
memcpy ( V_164 , V_163 , sizeof( struct V_4 ) ) ;
F_6 ( & V_164 -> V_12 ) ;
F_112 ( V_16 , V_164 , V_114 ) ;
V_16 -> V_46 [ V_114 ] = V_164 ;
}
static void T_6 F_113 ( struct V_15 * V_16 , int V_166 )
{
int V_49 ;
F_32 (node) {
V_16 -> V_46 [ V_49 ] = & V_167 [ V_166 + V_49 ] ;
V_16 -> V_46 [ V_49 ] -> V_121 = V_122 +
V_123 +
( ( unsigned long ) V_16 ) % V_123 ;
}
}
void T_6 F_114 ( void )
{
T_2 V_73 ;
struct V_52 * V_168 ;
struct V_169 * V_170 ;
int V_3 ;
int V_171 ;
int V_49 ;
if ( F_115 () == 1 )
V_84 = 0 ;
for ( V_3 = 0 ; V_3 < V_172 ; V_3 ++ ) {
F_4 ( & V_167 [ V_3 ] ) ;
if ( V_3 < V_91 )
V_173 . V_46 [ V_3 ] = NULL ;
}
F_113 ( & V_173 , V_174 ) ;
if ( ! V_88 && V_175 > ( 32 << 20 ) >> V_176 )
V_86 = V_177 ;
V_49 = F_88 () ;
F_5 ( & V_178 ) ;
F_116 ( & V_173 . V_27 , & V_178 ) ;
V_173 . V_179 = F_117 () ;
V_173 . V_61 [ F_37 () ] = & V_180 . V_25 ;
V_173 . V_46 [ V_49 ] = & V_167 [ V_174 + V_49 ] ;
V_173 . V_21 = F_118 ( struct V_15 , V_61 [ V_181 ] ) +
V_115 * sizeof( struct V_4 * ) ;
#if V_64
V_173 . F_8 = V_173 . V_21 ;
#endif
V_173 . V_21 = F_43 ( V_173 . V_21 ,
F_117 () ) ;
V_173 . V_35 =
F_119 ( V_173 . V_21 ) ;
for ( V_171 = 0 ; V_171 < V_87 ; V_171 ++ ) {
F_44 ( V_171 , V_173 . V_21 ,
F_117 () , 0 , & V_73 , & V_173 . V_74 ) ;
if ( V_173 . V_74 )
break;
}
F_10 ( ! V_173 . V_74 ) ;
V_173 . V_72 = V_171 ;
V_173 . V_182 = V_73 / V_173 . V_179 ;
V_173 . V_76 = F_43 ( V_173 . V_74 * sizeof( V_71 ) +
sizeof( struct V_29 ) , F_117 () ) ;
V_168 = V_54 ;
V_170 = V_169 ;
V_168 [ V_65 ] . V_58 = F_120 ( V_170 [ V_65 ] . V_83 ,
V_168 [ V_65 ] . V_56 ,
V_183 ,
V_184 | V_185 ,
NULL ) ;
if ( V_65 != V_186 ) {
V_168 [ V_186 ] . V_58 =
F_120 ( V_170 [ V_186 ] . V_83 ,
V_168 [ V_186 ] . V_56 ,
V_183 ,
V_184 | V_185 ,
NULL ) ;
}
V_187 = 0 ;
while ( V_168 -> V_56 != V_57 ) {
if ( ! V_168 -> V_58 ) {
V_168 -> V_58 = F_120 ( V_170 -> V_83 ,
V_168 -> V_56 ,
V_183 ,
V_184 | V_185 ,
NULL ) ;
}
#ifdef F_39
V_168 -> V_68 = F_120 (
V_170 -> V_188 ,
V_168 -> V_56 ,
V_183 ,
V_184 | V_189 |
V_185 ,
NULL ) ;
#endif
V_168 ++ ;
V_170 ++ ;
}
{
struct V_42 * V_164 ;
V_164 = F_121 ( sizeof( struct V_190 ) , V_165 ) ;
F_10 ( F_36 ( & V_173 ) != & V_180 . V_25 ) ;
memcpy ( V_164 , F_36 ( & V_173 ) ,
sizeof( struct V_190 ) ) ;
F_6 ( & V_164 -> V_48 ) ;
V_173 . V_61 [ F_37 () ] = V_164 ;
V_164 = F_121 ( sizeof( struct V_190 ) , V_165 ) ;
F_10 ( F_36 ( V_54 [ V_65 ] . V_58 )
!= & V_191 . V_25 ) ;
memcpy ( V_164 , F_36 ( V_54 [ V_65 ] . V_58 ) ,
sizeof( struct V_190 ) ) ;
F_6 ( & V_164 -> V_48 ) ;
V_54 [ V_65 ] . V_58 -> V_61 [ F_37 () ] =
V_164 ;
}
{
int V_154 ;
F_32 (nid) {
F_111 ( & V_173 , & V_167 [ V_174 + V_154 ] , V_154 ) ;
F_111 ( V_54 [ V_65 ] . V_58 ,
& V_167 [ V_192 + V_154 ] , V_154 ) ;
if ( V_65 != V_186 ) {
F_111 ( V_54 [ V_186 ] . V_58 ,
& V_167 [ V_193 + V_154 ] , V_154 ) ;
}
}
}
V_36 = V_37 ;
}
void T_6 F_122 ( void )
{
struct V_15 * V_16 ;
V_36 = V_55 ;
F_35 () ;
F_103 ( & V_137 ) ;
F_93 (cachep, &cache_chain, next)
if ( F_123 ( V_16 , V_165 ) )
F_124 () ;
F_104 ( & V_137 ) ;
V_36 = V_194 ;
F_125 ( & V_195 ) ;
#ifdef F_101
F_126 ( F_110 , V_196 ) ;
#endif
}
static int T_6 F_127 ( void )
{
int V_89 ;
F_128 (cpu)
F_60 ( V_89 ) ;
return 0 ;
}
static void * F_129 ( struct V_15 * V_16 , T_5 V_18 , int V_114 )
{
struct V_24 * V_24 ;
int V_197 ;
int V_3 ;
#ifndef F_130
V_18 |= V_198 ;
#endif
V_18 |= V_16 -> V_62 ;
if ( V_16 -> V_18 & V_199 )
V_18 |= V_200 ;
V_24 = F_131 ( V_114 , V_18 | V_201 , V_16 -> V_72 ) ;
if ( ! V_24 )
return NULL ;
V_197 = ( 1 << V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_199 )
F_132 ( F_133 ( V_24 ) ,
V_202 , V_197 ) ;
else
F_132 ( F_133 ( V_24 ) ,
V_203 , V_197 ) ;
for ( V_3 = 0 ; V_3 < V_197 ; V_3 ++ )
F_134 ( V_24 + V_3 ) ;
if ( V_204 && ! ( V_16 -> V_18 & V_205 ) ) {
F_135 ( V_24 , V_16 -> V_72 , V_18 , V_114 ) ;
if ( V_16 -> V_206 )
F_136 ( V_24 , V_197 ) ;
else
F_137 ( V_24 , V_197 ) ;
}
return F_138 ( V_24 ) ;
}
static void F_139 ( struct V_15 * V_16 , void * V_207 )
{
unsigned long V_3 = ( 1 << V_16 -> V_72 ) ;
struct V_24 * V_24 = F_140 ( V_207 ) ;
const unsigned long V_208 = V_3 ;
F_141 ( V_24 , V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_199 )
F_142 ( F_133 ( V_24 ) ,
V_202 , V_208 ) ;
else
F_142 ( F_133 ( V_24 ) ,
V_203 , V_208 ) ;
while ( V_3 -- ) {
F_10 ( ! F_17 ( V_24 ) ) ;
F_143 ( V_24 ) ;
V_24 ++ ;
}
if ( V_209 -> V_210 )
V_209 -> V_210 -> V_211 += V_208 ;
F_144 ( ( unsigned long ) V_207 , V_16 -> V_72 ) ;
}
static void F_145 ( struct V_212 * V_213 )
{
struct V_214 * V_214 = (struct V_214 * ) V_213 ;
struct V_15 * V_16 = V_214 -> V_16 ;
F_139 ( V_16 , V_214 -> V_207 ) ;
if ( F_34 ( V_16 ) )
F_146 ( V_16 -> V_215 , V_214 ) ;
}
static void F_147 ( struct V_15 * V_16 , unsigned long * V_207 ,
unsigned long V_216 )
{
int V_1 = F_8 ( V_16 ) ;
V_207 = ( unsigned long * ) & ( ( char * ) V_207 ) [ F_7 ( V_16 ) ] ;
if ( V_1 < 5 * sizeof( unsigned long ) )
return;
* V_207 ++ = 0x12345678 ;
* V_207 ++ = V_216 ;
* V_207 ++ = F_37 () ;
V_1 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_217 = & V_216 ;
unsigned long V_218 ;
while ( ! F_148 ( V_217 ) ) {
V_218 = * V_217 ++ ;
if ( F_149 ( V_218 ) ) {
* V_207 ++ = V_218 ;
V_1 -= sizeof( unsigned long ) ;
if ( V_1 <= sizeof( unsigned long ) )
break;
}
}
}
* V_207 ++ = 0x87654321 ;
}
static void F_150 ( struct V_15 * V_16 , void * V_207 , unsigned char V_219 )
{
int V_1 = F_8 ( V_16 ) ;
V_207 = & ( ( char * ) V_207 ) [ F_7 ( V_16 ) ] ;
memset ( V_207 , V_219 , V_1 ) ;
* ( unsigned char * ) ( V_207 + V_1 - 1 ) = V_220 ;
}
static void F_151 ( char * V_221 , int V_34 , int V_106 )
{
int V_3 ;
unsigned char error = 0 ;
int V_222 = 0 ;
F_46 ( V_82 L_2 , V_34 ) ;
for ( V_3 = 0 ; V_3 < V_106 ; V_3 ++ ) {
if ( V_221 [ V_34 + V_3 ] != V_223 ) {
error = V_221 [ V_34 + V_3 ] ;
V_222 ++ ;
}
}
F_152 ( V_224 , L_3 , 0 , 16 , 1 ,
& V_221 [ V_34 ] , V_106 , 1 ) ;
if ( V_222 == 1 ) {
error ^= V_223 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_46 ( V_82 L_4
L_5 ) ;
#ifdef F_153
F_46 ( V_82 L_6
L_7 ) ;
#else
F_46 ( V_82 L_8 ) ;
#endif
}
}
}
static void F_154 ( struct V_15 * V_16 , void * V_17 , int V_225 )
{
int V_3 , V_1 ;
char * V_226 ;
if ( V_16 -> V_18 & V_19 ) {
F_46 ( V_82 L_9 ,
* F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
if ( V_16 -> V_18 & V_20 ) {
F_46 ( V_82 L_10 ,
* F_12 ( V_16 , V_17 ) ) ;
F_155 ( L_11 ,
( unsigned long ) * F_12 ( V_16 , V_17 ) ) ;
F_46 ( L_12 ) ;
}
V_226 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 && V_225 ; V_3 += 16 , V_225 -- ) {
int V_106 ;
V_106 = 16 ;
if ( V_3 + V_106 > V_1 )
V_106 = V_1 - V_3 ;
F_151 ( V_226 , V_3 , V_106 ) ;
}
}
static void F_156 ( struct V_15 * V_16 , void * V_17 )
{
char * V_226 ;
int V_1 , V_3 ;
int V_225 = 0 ;
V_226 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ ) {
char exp = V_223 ;
if ( V_3 == V_1 - 1 )
exp = V_220 ;
if ( V_226 [ V_3 ] != exp ) {
int V_106 ;
if ( V_225 == 0 ) {
F_46 ( V_82
L_13 ,
F_157 () , V_16 -> V_83 , V_226 , V_1 ) ;
F_154 ( V_16 , V_17 , 0 ) ;
}
V_3 = ( V_3 / 16 ) * 16 ;
V_106 = 16 ;
if ( V_3 + V_106 > V_1 )
V_106 = V_1 - V_3 ;
F_151 ( V_226 , V_3 , V_106 ) ;
V_3 += 16 ;
V_225 ++ ;
if ( V_225 > 5 )
break;
}
}
if ( V_225 != 0 ) {
struct V_29 * V_118 = F_22 ( V_17 ) ;
unsigned int V_227 ;
V_227 = F_24 ( V_16 , V_118 , V_17 ) ;
if ( V_227 ) {
V_17 = F_23 ( V_16 , V_118 , V_227 - 1 ) ;
V_226 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_14 ,
V_226 , V_1 ) ;
F_154 ( V_16 , V_17 , 2 ) ;
}
if ( V_227 + 1 < V_16 -> V_74 ) {
V_17 = F_23 ( V_16 , V_118 , V_227 + 1 ) ;
V_226 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_15 ,
V_226 , V_1 ) ;
F_154 ( V_16 , V_17 , 2 ) ;
}
}
}
static void F_158 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_118 , V_3 ) ;
if ( V_16 -> V_18 & V_228 ) {
#ifdef F_159
if ( V_16 -> V_21 % V_77 == 0 &&
F_34 ( V_16 ) )
F_160 ( F_140 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_156 ( V_16 , V_17 ) ;
#else
F_156 ( V_16 , V_17 ) ;
#endif
}
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_229 )
F_161 ( V_16 , L_16
L_17 ) ;
if ( * F_11 ( V_16 , V_17 ) != V_229 )
F_161 ( V_16 , L_18
L_17 ) ;
}
}
}
static void F_158 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
}
static void F_162 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
void * V_207 = V_118 -> V_33 - V_118 -> V_230 ;
F_158 ( V_16 , V_118 ) ;
if ( F_40 ( V_16 -> V_18 & V_231 ) ) {
struct V_214 * V_214 ;
V_214 = (struct V_214 * ) V_118 ;
V_214 -> V_16 = V_16 ;
V_214 -> V_207 = V_207 ;
F_163 ( & V_214 -> V_213 , F_145 ) ;
} else {
F_139 ( V_16 , V_207 ) ;
if ( F_34 ( V_16 ) )
F_146 ( V_16 -> V_215 , V_118 ) ;
}
}
static void F_164 ( struct V_15 * V_16 )
{
int V_3 ;
struct V_4 * V_44 ;
F_128 (i)
F_77 ( V_16 -> V_61 [ V_3 ] ) ;
F_32 (i) {
V_44 = V_16 -> V_46 [ V_3 ] ;
if ( V_44 ) {
F_77 ( V_44 -> V_9 ) ;
F_71 ( V_44 -> V_10 ) ;
F_77 ( V_44 ) ;
}
}
F_146 ( & V_173 , V_16 ) ;
}
static T_2 F_165 ( struct V_15 * V_16 ,
T_2 V_1 , T_2 V_70 , unsigned long V_18 )
{
unsigned long V_232 ;
T_2 V_73 = 0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 <= V_233 ; V_72 ++ ) {
unsigned int V_74 ;
T_2 V_234 ;
F_44 ( V_72 , V_1 , V_70 , V_18 , & V_234 , & V_74 ) ;
if ( ! V_74 )
continue;
if ( V_18 & V_78 ) {
V_232 = V_1 - sizeof( struct V_29 ) ;
V_232 /= sizeof( V_71 ) ;
if ( V_74 > V_232 )
break;
}
V_16 -> V_74 = V_74 ;
V_16 -> V_72 = V_72 ;
V_73 = V_234 ;
if ( V_18 & V_199 )
break;
if ( V_72 >= V_86 )
break;
if ( V_73 * 8 <= ( V_77 << V_72 ) )
break;
}
return V_73 ;
}
static int T_9 F_166 ( struct V_15 * V_16 , T_5 V_102 )
{
if ( V_36 == V_194 )
return F_123 ( V_16 , V_102 ) ;
if ( V_36 == V_235 ) {
V_16 -> V_61 [ F_37 () ] = & V_191 . V_25 ;
F_113 ( V_16 , V_192 ) ;
if ( V_65 == V_186 )
V_36 = V_236 ;
else
V_36 = V_237 ;
} else {
V_16 -> V_61 [ F_37 () ] =
F_121 ( sizeof( struct V_190 ) , V_102 ) ;
if ( V_36 == V_237 ) {
F_113 ( V_16 , V_193 ) ;
V_36 = V_236 ;
} else {
int V_49 ;
F_32 (node) {
V_16 -> V_46 [ V_49 ] =
F_66 ( sizeof( struct V_4 ) ,
V_102 , V_49 ) ;
F_10 ( ! V_16 -> V_46 [ V_49 ] ) ;
F_4 ( V_16 -> V_46 [ V_49 ] ) ;
}
}
}
V_16 -> V_46 [ F_88 () ] -> V_121 =
V_122 + V_123 +
( ( unsigned long ) V_16 ) % V_123 ;
F_36 ( V_16 ) -> V_105 = 0 ;
F_36 ( V_16 ) -> V_106 = V_238 ;
F_36 ( V_16 ) -> V_101 = 1 ;
F_36 ( V_16 ) -> V_107 = 0 ;
V_16 -> V_101 = 1 ;
V_16 -> V_106 = V_238 ;
return 0 ;
}
struct V_15 *
F_120 ( const char * V_83 , T_2 V_1 , T_2 V_70 ,
unsigned long V_18 , void (* V_206)( void * ) )
{
T_2 V_73 , V_76 , V_239 ;
struct V_15 * V_16 = NULL , * V_240 ;
T_5 V_102 ;
if ( ! V_83 || F_167 () || ( V_1 < V_23 ) ||
V_1 > V_241 ) {
F_46 ( V_82 L_19 , V_242 ,
V_83 ) ;
F_124 () ;
}
if ( F_26 () ) {
F_168 () ;
F_103 ( & V_137 ) ;
}
F_93 (pc, &cache_chain, next) {
char V_243 ;
int V_244 ;
V_244 = F_169 ( V_240 -> V_83 , V_243 ) ;
if ( V_244 ) {
F_46 ( V_82
L_20 ,
V_240 -> V_21 ) ;
continue;
}
if ( ! strcmp ( V_240 -> V_83 , V_83 ) ) {
F_46 ( V_82
L_21 , V_83 ) ;
F_47 () ;
goto V_245;
}
}
#if V_64
F_170 ( strchr ( V_83 , ' ' ) ) ;
#if V_246
if ( V_1 < 4096 || F_171 ( V_1 - 1 ) == F_171 ( V_1 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_18 |= V_19 | V_20 ;
if ( ! ( V_18 & V_231 ) )
V_18 |= V_228 ;
#endif
if ( V_18 & V_231 )
F_10 ( V_18 & V_228 ) ;
#endif
F_10 ( V_18 & ~ V_247 ) ;
if ( V_1 & ( V_23 - 1 ) ) {
V_1 += ( V_23 - 1 ) ;
V_1 &= ~ ( V_23 - 1 ) ;
}
if ( V_18 & V_248 ) {
V_239 = F_117 () ;
while ( V_1 <= V_239 / 2 )
V_239 /= 2 ;
} else {
V_239 = V_23 ;
}
if ( V_18 & V_20 )
V_239 = V_23 ;
if ( V_18 & V_19 ) {
V_239 = V_22 ;
V_1 += V_22 - 1 ;
V_1 &= ~ ( V_22 - 1 ) ;
}
if ( V_239 < V_249 ) {
V_239 = V_249 ;
}
if ( V_239 < V_70 ) {
V_239 = V_70 ;
}
if ( V_239 > F_172 (unsigned long long) )
V_18 &= ~ ( V_19 | V_20 ) ;
V_70 = V_239 ;
if ( F_26 () )
V_102 = V_119 ;
else
V_102 = V_165 ;
V_16 = F_173 ( & V_173 , V_102 ) ;
if ( ! V_16 )
goto V_245;
V_16 -> V_46 = (struct V_4 * * ) & V_16 -> V_61 [ V_181 ] ;
#if V_64
V_16 -> F_8 = V_1 ;
if ( V_18 & V_19 ) {
V_16 -> F_7 += sizeof( unsigned long long ) ;
V_1 += 2 * sizeof( unsigned long long ) ;
}
if ( V_18 & V_20 ) {
if ( V_18 & V_19 )
V_1 += V_22 ;
else
V_1 += V_23 ;
}
#if V_246 && F_174 ( F_159 )
if ( V_1 >= V_54 [ V_186 + 1 ] . V_56
&& V_16 -> F_8 > F_117 () && F_43 ( V_1 , V_70 ) < V_77 ) {
V_16 -> F_7 += V_77 - F_43 ( V_1 , V_70 ) ;
V_1 = V_77 ;
}
#endif
#endif
if ( ( V_1 >= ( V_77 >> 3 ) ) && ! V_187 &&
! ( V_18 & V_250 ) )
V_18 |= V_78 ;
V_1 = F_43 ( V_1 , V_70 ) ;
V_73 = F_165 ( V_16 , V_1 , V_70 , V_18 ) ;
if ( ! V_16 -> V_74 ) {
F_46 ( V_82
L_22 , V_83 ) ;
F_146 ( & V_173 , V_16 ) ;
V_16 = NULL ;
goto V_245;
}
V_76 = F_43 ( V_16 -> V_74 * sizeof( V_71 )
+ sizeof( struct V_29 ) , V_70 ) ;
if ( V_18 & V_78 && V_73 >= V_76 ) {
V_18 &= ~ V_78 ;
V_73 -= V_76 ;
}
if ( V_18 & V_78 ) {
V_76 =
V_16 -> V_74 * sizeof( V_71 ) + sizeof( struct V_29 ) ;
#ifdef F_175
if ( V_1 % V_77 == 0 && V_18 & V_228 )
V_18 &= ~ ( V_19 | V_20 ) ;
#endif
}
V_16 -> V_179 = F_117 () ;
if ( V_16 -> V_179 < V_70 )
V_16 -> V_179 = V_70 ;
V_16 -> V_182 = V_73 / V_16 -> V_179 ;
V_16 -> V_76 = V_76 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_62 = 0 ;
if ( V_251 && ( V_18 & V_189 ) )
V_16 -> V_62 |= V_67 ;
V_16 -> V_21 = V_1 ;
V_16 -> V_35 = F_119 ( V_1 ) ;
if ( V_18 & V_78 ) {
V_16 -> V_215 = F_41 ( V_76 , 0u ) ;
F_10 ( F_176 ( V_16 -> V_215 ) ) ;
}
V_16 -> V_206 = V_206 ;
V_16 -> V_83 = V_83 ;
if ( F_166 ( V_16 , V_102 ) ) {
F_164 ( V_16 ) ;
V_16 = NULL ;
goto V_245;
}
if ( V_18 & V_130 ) {
F_177 ( V_18 & V_231 ) ;
F_31 ( V_16 ) ;
}
F_116 ( & V_16 -> V_27 , & V_178 ) ;
V_245:
if ( ! V_16 && ( V_18 & V_185 ) )
F_178 ( L_23 ,
V_83 ) ;
if ( F_26 () ) {
F_104 ( & V_137 ) ;
F_179 () ;
}
return V_16 ;
}
static void F_180 ( void )
{
F_10 ( ! F_181 () ) ;
}
static void F_182 ( void )
{
F_10 ( F_181 () ) ;
}
static void F_183 ( struct V_15 * V_16 )
{
#ifdef F_184
F_180 () ;
F_185 ( & V_16 -> V_46 [ F_88 () ] -> V_12 ) ;
#endif
}
static void F_186 ( struct V_15 * V_16 , int V_49 )
{
#ifdef F_184
F_180 () ;
F_185 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
#endif
}
static void F_187 ( void * V_151 )
{
struct V_15 * V_16 = V_151 ;
struct V_42 * V_116 ;
int V_49 = F_88 () ;
F_180 () ;
V_116 = F_36 ( V_16 ) ;
F_79 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
F_80 ( V_16 , V_116 -> V_112 , V_116 -> V_105 , V_49 ) ;
F_81 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
V_116 -> V_105 = 0 ;
}
static void F_188 ( struct V_15 * V_16 )
{
struct V_4 * V_44 ;
int V_49 ;
F_189 ( F_187 , V_16 , 1 ) ;
F_182 () ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 && V_44 -> V_10 )
F_85 ( V_16 , V_44 -> V_10 ) ;
}
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 )
F_190 ( V_16 , V_44 , V_44 -> V_9 , 1 , V_49 ) ;
}
}
static int F_99 ( struct V_15 * V_25 ,
struct V_4 * V_44 , int V_252 )
{
struct V_28 * V_253 ;
int V_208 ;
struct V_29 * V_118 ;
V_208 = 0 ;
while ( V_208 < V_252 && ! F_109 ( & V_44 -> V_8 ) ) {
F_94 ( & V_44 -> V_12 ) ;
V_253 = V_44 -> V_8 . V_30 ;
if ( V_253 == & V_44 -> V_8 ) {
F_84 ( & V_44 -> V_12 ) ;
goto V_156;
}
V_118 = F_191 ( V_253 , struct V_29 , V_163 ) ;
#if V_64
F_10 ( V_118 -> V_254 ) ;
#endif
F_192 ( & V_118 -> V_163 ) ;
V_44 -> V_13 -= V_25 -> V_74 ;
F_84 ( & V_44 -> V_12 ) ;
F_162 ( V_25 , V_118 ) ;
V_208 ++ ;
}
V_156:
return V_208 ;
}
static int F_193 ( struct V_15 * V_16 )
{
int V_148 = 0 , V_3 = 0 ;
struct V_4 * V_44 ;
F_188 ( V_16 ) ;
F_182 () ;
F_32 (i) {
V_44 = V_16 -> V_46 [ V_3 ] ;
if ( ! V_44 )
continue;
F_99 ( V_16 , V_44 , V_44 -> V_13 ) ;
V_148 += ! F_109 ( & V_44 -> V_6 ) ||
! F_109 ( & V_44 -> V_7 ) ;
}
return ( V_148 ? 1 : 0 ) ;
}
int F_194 ( struct V_15 * V_16 )
{
int V_148 ;
F_10 ( ! V_16 || F_167 () ) ;
F_168 () ;
F_103 ( & V_137 ) ;
V_148 = F_193 ( V_16 ) ;
F_104 ( & V_137 ) ;
F_179 () ;
return V_148 ;
}
void F_195 ( struct V_15 * V_16 )
{
F_10 ( ! V_16 || F_167 () ) ;
F_168 () ;
F_103 ( & V_137 ) ;
F_192 ( & V_16 -> V_27 ) ;
if ( F_193 ( V_16 ) ) {
F_161 ( V_16 , L_24 ) ;
F_116 ( & V_16 -> V_27 , & V_178 ) ;
F_104 ( & V_137 ) ;
F_179 () ;
return;
}
if ( F_40 ( V_16 -> V_18 & V_231 ) )
F_196 () ;
F_164 ( V_16 ) ;
F_104 ( & V_137 ) ;
F_179 () ;
}
static struct V_29 * F_197 ( struct V_15 * V_16 , void * V_17 ,
int V_179 , T_5 V_255 ,
int V_114 )
{
struct V_29 * V_118 ;
if ( F_34 ( V_16 ) ) {
V_118 = F_198 ( V_16 -> V_215 ,
V_255 , V_114 ) ;
F_199 ( & V_118 -> V_163 , sizeof( struct V_28 ) ,
V_255 ) ;
if ( ! V_118 )
return NULL ;
} else {
V_118 = V_17 + V_179 ;
V_179 += V_16 -> V_76 ;
}
V_118 -> V_254 = 0 ;
V_118 -> V_230 = V_179 ;
V_118 -> V_33 = V_17 + V_179 ;
V_118 -> V_114 = V_114 ;
V_118 -> free = 0 ;
return V_118 ;
}
static inline V_71 * F_200 ( struct V_29 * V_118 )
{
return ( V_71 * ) ( V_118 + 1 ) ;
}
static void F_201 ( struct V_15 * V_16 ,
struct V_29 * V_118 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_118 , V_3 ) ;
#if V_64
if ( V_16 -> V_18 & V_228 )
F_150 ( V_16 , V_17 , V_223 ) ;
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = NULL ;
if ( V_16 -> V_18 & V_19 ) {
* F_9 ( V_16 , V_17 ) = V_229 ;
* F_11 ( V_16 , V_17 ) = V_229 ;
}
if ( V_16 -> V_206 && ! ( V_16 -> V_18 & V_228 ) )
V_16 -> V_206 ( V_17 + F_7 ( V_16 ) ) ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_11 ( V_16 , V_17 ) != V_229 )
F_161 ( V_16 , L_25
L_26 ) ;
if ( * F_9 ( V_16 , V_17 ) != V_229 )
F_161 ( V_16 , L_25
L_27 ) ;
}
if ( ( V_16 -> V_21 % V_77 ) == 0 &&
F_34 ( V_16 ) && V_16 -> V_18 & V_228 )
F_160 ( F_140 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
#else
if ( V_16 -> V_206 )
V_16 -> V_206 ( V_17 ) ;
#endif
F_200 ( V_118 ) [ V_3 ] = V_3 + 1 ;
}
F_200 ( V_118 ) [ V_3 - 1 ] = V_256 ;
}
static void F_202 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_251 ) {
if ( V_18 & V_67 )
F_10 ( ! ( V_16 -> V_62 & V_67 ) ) ;
else
F_10 ( V_16 -> V_62 & V_67 ) ;
}
}
static void * F_203 ( struct V_15 * V_16 , struct V_29 * V_118 ,
int V_114 )
{
void * V_17 = F_23 ( V_16 , V_118 , V_118 -> free ) ;
V_71 V_27 ;
V_118 -> V_254 ++ ;
V_27 = F_200 ( V_118 ) [ V_118 -> free ] ;
#if V_64
F_200 ( V_118 ) [ V_118 -> free ] = V_257 ;
F_170 ( V_118 -> V_114 != V_114 ) ;
#endif
V_118 -> free = V_27 ;
return V_17 ;
}
static void F_204 ( struct V_15 * V_16 , struct V_29 * V_118 ,
void * V_17 , int V_114 )
{
unsigned int V_227 = F_24 ( V_16 , V_118 , V_17 ) ;
#if V_64
F_170 ( V_118 -> V_114 != V_114 ) ;
if ( F_200 ( V_118 ) [ V_227 ] + 1 <= V_79 + 1 ) {
F_46 ( V_82 L_28
L_29 , V_16 -> V_83 , V_17 ) ;
F_124 () ;
}
#endif
F_200 ( V_118 ) [ V_227 ] = V_118 -> free ;
V_118 -> free = V_227 ;
V_118 -> V_254 -- ;
}
static void F_205 ( struct V_15 * V_25 , struct V_29 * V_29 ,
void * V_207 )
{
int V_197 ;
struct V_24 * V_24 ;
V_24 = F_140 ( V_207 ) ;
V_197 = 1 ;
if ( F_89 ( ! F_206 ( V_24 ) ) )
V_197 <<= V_25 -> V_72 ;
do {
F_14 ( V_24 , V_25 ) ;
F_18 ( V_24 , V_29 ) ;
V_24 ++ ;
} while ( -- V_197 );
}
static int F_207 ( struct V_15 * V_16 ,
T_5 V_18 , int V_114 , void * V_17 )
{
struct V_29 * V_118 ;
T_2 V_34 ;
T_5 V_255 ;
struct V_4 * V_44 ;
F_10 ( V_18 & V_258 ) ;
V_255 = V_18 & ( V_259 | V_260 ) ;
F_180 () ;
V_44 = V_16 -> V_46 [ V_114 ] ;
F_79 ( & V_44 -> V_12 ) ;
V_34 = V_44 -> V_11 ;
V_44 -> V_11 ++ ;
if ( V_44 -> V_11 >= V_16 -> V_182 )
V_44 -> V_11 = 0 ;
F_81 ( & V_44 -> V_12 ) ;
V_34 *= V_16 -> V_179 ;
if ( V_255 & V_261 )
F_208 () ;
F_202 ( V_16 , V_18 ) ;
if ( ! V_17 )
V_17 = F_129 ( V_16 , V_255 , V_114 ) ;
if ( ! V_17 )
goto V_262;
V_118 = F_197 ( V_16 , V_17 , V_34 ,
V_255 & ~ V_259 , V_114 ) ;
if ( ! V_118 )
goto V_263;
F_205 ( V_16 , V_118 , V_17 ) ;
F_201 ( V_16 , V_118 ) ;
if ( V_255 & V_261 )
F_209 () ;
F_180 () ;
F_79 ( & V_44 -> V_12 ) ;
F_210 ( & V_118 -> V_163 , & ( V_44 -> V_8 ) ) ;
F_211 ( V_16 ) ;
V_44 -> V_13 += V_16 -> V_74 ;
F_81 ( & V_44 -> V_12 ) ;
return 1 ;
V_263:
F_139 ( V_16 , V_17 ) ;
V_262:
if ( V_255 & V_261 )
F_209 () ;
return 0 ;
}
static void F_212 ( const void * V_17 )
{
if ( ! F_213 ( V_17 ) ) {
F_46 ( V_82 L_30 ,
( unsigned long ) V_17 ) ;
F_124 () ;
}
}
static inline void F_214 ( struct V_15 * V_25 , void * V_31 )
{
unsigned long long V_264 , V_265 ;
V_264 = * F_9 ( V_25 , V_31 ) ;
V_265 = * F_11 ( V_25 , V_31 ) ;
if ( V_264 == V_266 && V_265 == V_266 )
return;
if ( V_264 == V_229 && V_265 == V_229 )
F_161 ( V_25 , L_31 ) ;
else
F_161 ( V_25 , L_32 ) ;
F_46 ( V_82 L_33 ,
V_31 , V_264 , V_265 ) ;
}
static void * F_215 ( struct V_15 * V_16 , void * V_17 ,
void * V_216 )
{
struct V_24 * V_24 ;
unsigned int V_227 ;
struct V_29 * V_118 ;
F_10 ( F_20 ( V_17 ) != V_16 ) ;
V_17 -= F_7 ( V_16 ) ;
F_212 ( V_17 ) ;
V_24 = F_21 ( V_17 ) ;
V_118 = F_19 ( V_24 ) ;
if ( V_16 -> V_18 & V_19 ) {
F_214 ( V_16 , V_17 ) ;
* F_9 ( V_16 , V_17 ) = V_229 ;
* F_11 ( V_16 , V_17 ) = V_229 ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_216 ;
V_227 = F_24 ( V_16 , V_118 , V_17 ) ;
F_10 ( V_227 >= V_16 -> V_74 ) ;
F_10 ( V_17 != F_23 ( V_16 , V_118 , V_227 ) ) ;
#ifdef F_216
F_200 ( V_118 ) [ V_227 ] = V_257 ;
#endif
if ( V_16 -> V_18 & V_228 ) {
#ifdef F_159
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) ) {
F_147 ( V_16 , V_17 , ( unsigned long ) V_216 ) ;
F_160 ( F_140 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
} else {
F_150 ( V_16 , V_17 , V_223 ) ;
}
#else
F_150 ( V_16 , V_17 , V_223 ) ;
#endif
}
return V_17 ;
}
static void F_217 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
V_71 V_3 ;
int V_100 = 0 ;
for ( V_3 = V_118 -> free ; V_3 != V_256 ; V_3 = F_200 ( V_118 ) [ V_3 ] ) {
V_100 ++ ;
if ( V_100 > V_16 -> V_74 || V_3 >= V_16 -> V_74 )
goto V_129;
}
if ( V_100 != V_16 -> V_74 - V_118 -> V_254 ) {
V_129:
F_46 ( V_82 L_34
L_35 ,
V_16 -> V_83 , V_16 -> V_74 , V_118 , V_118 -> V_254 ,
F_157 () ) ;
F_152 ( V_82 , L_3 , V_267 , 16 , 1 , V_118 ,
sizeof( * V_118 ) + V_16 -> V_74 * sizeof( V_71 ) ,
1 ) ;
F_124 () ;
}
}
static void * F_218 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_101 ;
struct V_4 * V_44 ;
struct V_42 * V_116 ;
int V_49 ;
V_268:
F_180 () ;
V_49 = F_88 () ;
V_116 = F_36 ( V_16 ) ;
V_101 = V_116 -> V_101 ;
if ( ! V_116 -> V_107 && V_101 > V_269 ) {
V_101 = V_269 ;
}
V_44 = V_16 -> V_46 [ V_49 ] ;
F_10 ( V_116 -> V_105 > 0 || ! V_44 ) ;
F_79 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 && F_68 ( V_116 , V_44 -> V_9 , V_101 ) ) {
V_44 -> V_9 -> V_107 = 1 ;
goto V_270;
}
while ( V_101 > 0 ) {
struct V_28 * V_112 ;
struct V_29 * V_118 ;
V_112 = V_44 -> V_7 . V_27 ;
if ( V_112 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_112 = V_44 -> V_8 . V_27 ;
if ( V_112 == & V_44 -> V_8 )
goto V_271;
}
V_118 = F_191 ( V_112 , struct V_29 , V_163 ) ;
F_217 ( V_16 , V_118 ) ;
F_183 ( V_16 ) ;
F_10 ( V_118 -> V_254 >= V_16 -> V_74 ) ;
while ( V_118 -> V_254 < V_16 -> V_74 && V_101 -- ) {
F_219 ( V_16 ) ;
F_220 ( V_16 ) ;
F_221 ( V_16 ) ;
V_116 -> V_112 [ V_116 -> V_105 ++ ] = F_203 ( V_16 , V_118 ,
V_49 ) ;
}
F_217 ( V_16 , V_118 ) ;
F_192 ( & V_118 -> V_163 ) ;
if ( V_118 -> free == V_256 )
F_116 ( & V_118 -> V_163 , & V_44 -> V_6 ) ;
else
F_116 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
}
V_271:
V_44 -> V_13 -= V_116 -> V_105 ;
V_270:
F_81 ( & V_44 -> V_12 ) ;
if ( F_40 ( ! V_116 -> V_105 ) ) {
int T_3 ;
T_3 = F_207 ( V_16 , V_18 | V_272 , V_49 , NULL ) ;
V_116 = F_36 ( V_16 ) ;
if ( ! T_3 && V_116 -> V_105 == 0 )
return NULL ;
if ( ! V_116 -> V_105 )
goto V_268;
}
V_116 -> V_107 = 1 ;
return V_116 -> V_112 [ -- V_116 -> V_105 ] ;
}
static inline void F_222 ( struct V_15 * V_16 ,
T_5 V_18 )
{
F_223 ( V_18 & V_261 ) ;
#if V_64
F_202 ( V_16 , V_18 ) ;
#endif
}
static void * F_224 ( struct V_15 * V_16 ,
T_5 V_18 , void * V_17 , void * V_216 )
{
if ( ! V_17 )
return V_17 ;
if ( V_16 -> V_18 & V_228 ) {
#ifdef F_159
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) )
F_160 ( F_140 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_156 ( V_16 , V_17 ) ;
#else
F_156 ( V_16 , V_17 ) ;
#endif
F_150 ( V_16 , V_17 , V_273 ) ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_216 ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_229 ||
* F_11 ( V_16 , V_17 ) != V_229 ) {
F_161 ( V_16 , L_36
L_37 ) ;
F_46 ( V_82
L_38 ,
V_17 , * F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
* F_9 ( V_16 , V_17 ) = V_266 ;
* F_11 ( V_16 , V_17 ) = V_266 ;
}
#ifdef F_216
{
struct V_29 * V_118 ;
unsigned V_227 ;
V_118 = F_19 ( F_21 ( V_17 ) ) ;
V_227 = ( unsigned ) ( V_17 - V_118 -> V_33 ) / V_16 -> V_21 ;
F_200 ( V_118 ) [ V_227 ] = V_274 ;
}
#endif
V_17 += F_7 ( V_16 ) ;
if ( V_16 -> V_206 && V_16 -> V_18 & V_228 )
V_16 -> V_206 ( V_17 ) ;
if ( V_249 &&
( ( unsigned long ) V_17 & ( V_249 - 1 ) ) ) {
F_46 ( V_82 L_39 ,
V_17 , ( int ) V_249 ) ;
}
return V_17 ;
}
static bool F_225 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_16 == & V_173 )
return false ;
return F_226 ( F_8 ( V_16 ) , V_18 , V_16 -> V_18 ) ;
}
static inline void * F_227 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_17 ;
struct V_42 * V_116 ;
F_180 () ;
V_116 = F_36 ( V_16 ) ;
if ( F_89 ( V_116 -> V_105 ) ) {
F_228 ( V_16 ) ;
V_116 -> V_107 = 1 ;
V_17 = V_116 -> V_112 [ -- V_116 -> V_105 ] ;
} else {
F_229 ( V_16 ) ;
V_17 = F_218 ( V_16 , V_18 ) ;
V_116 = F_36 ( V_16 ) ;
}
if ( V_17 )
F_230 ( & V_116 -> V_112 [ V_116 -> V_105 ] ) ;
return V_17 ;
}
static void * F_73 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_275 , V_276 ;
if ( F_167 () || ( V_18 & V_277 ) )
return NULL ;
V_275 = V_276 = F_88 () ;
F_231 () ;
if ( F_232 () && ( V_16 -> V_18 & V_278 ) )
V_275 = F_233 () ;
else if ( V_209 -> V_279 )
V_275 = F_234 ( V_209 -> V_279 ) ;
F_235 () ;
if ( V_275 != V_276 )
return F_74 ( V_16 , V_18 , V_275 ) ;
return NULL ;
}
static void * F_236 ( struct V_15 * V_25 , T_5 V_18 )
{
struct V_280 * V_280 ;
T_5 V_255 ;
struct V_281 * V_282 ;
struct V_283 * V_283 ;
enum V_284 V_285 = F_237 ( V_18 ) ;
void * V_31 = NULL ;
int V_154 ;
if ( V_18 & V_277 )
return NULL ;
F_231 () ;
V_280 = F_238 ( F_234 ( V_209 -> V_279 ) , V_18 ) ;
V_255 = V_18 & ( V_259 | V_260 ) ;
V_268:
F_239 (zone, z, zonelist, high_zoneidx) {
V_154 = F_240 ( V_283 ) ;
if ( F_241 ( V_283 , V_18 ) &&
V_25 -> V_46 [ V_154 ] &&
V_25 -> V_46 [ V_154 ] -> V_13 ) {
V_31 = F_74 ( V_25 ,
V_18 | V_272 , V_154 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
if ( V_255 & V_261 )
F_208 () ;
F_202 ( V_25 , V_18 ) ;
V_31 = F_129 ( V_25 , V_255 , F_88 () ) ;
if ( V_255 & V_261 )
F_209 () ;
if ( V_31 ) {
V_154 = F_242 ( F_140 ( V_31 ) ) ;
if ( F_207 ( V_25 , V_18 , V_154 , V_31 ) ) {
V_31 = F_74 ( V_25 ,
V_18 | V_272 , V_154 ) ;
if ( ! V_31 )
goto V_268;
} else {
V_31 = NULL ;
}
}
}
F_235 () ;
return V_31 ;
}
static void * F_74 ( struct V_15 * V_16 , T_5 V_18 ,
int V_114 )
{
struct V_28 * V_112 ;
struct V_29 * V_118 ;
struct V_4 * V_44 ;
void * V_31 ;
int T_3 ;
V_44 = V_16 -> V_46 [ V_114 ] ;
F_10 ( ! V_44 ) ;
V_268:
F_180 () ;
F_79 ( & V_44 -> V_12 ) ;
V_112 = V_44 -> V_7 . V_27 ;
if ( V_112 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_112 = V_44 -> V_8 . V_27 ;
if ( V_112 == & V_44 -> V_8 )
goto V_271;
}
V_118 = F_191 ( V_112 , struct V_29 , V_163 ) ;
F_186 ( V_16 , V_114 ) ;
F_217 ( V_16 , V_118 ) ;
F_243 ( V_16 ) ;
F_220 ( V_16 ) ;
F_221 ( V_16 ) ;
F_10 ( V_118 -> V_254 == V_16 -> V_74 ) ;
V_31 = F_203 ( V_16 , V_118 , V_114 ) ;
F_217 ( V_16 , V_118 ) ;
V_44 -> V_13 -- ;
F_192 ( & V_118 -> V_163 ) ;
if ( V_118 -> free == V_256 )
F_116 ( & V_118 -> V_163 , & V_44 -> V_6 ) ;
else
F_116 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
F_81 ( & V_44 -> V_12 ) ;
goto V_286;
V_271:
F_81 ( & V_44 -> V_12 ) ;
T_3 = F_207 ( V_16 , V_18 | V_272 , V_114 , NULL ) ;
if ( T_3 )
goto V_268;
return F_236 ( V_16 , V_18 ) ;
V_286:
return V_31 ;
}
static T_1 void *
F_244 ( struct V_15 * V_16 , T_5 V_18 , int V_114 ,
void * V_216 )
{
unsigned long V_287 ;
void * V_164 ;
int F_234 = F_88 () ;
V_18 &= V_288 ;
F_245 ( V_18 ) ;
if ( F_225 ( V_16 , V_18 ) )
return NULL ;
F_222 ( V_16 , V_18 ) ;
F_246 ( V_287 ) ;
if ( V_114 == V_289 )
V_114 = F_234 ;
if ( F_40 ( ! V_16 -> V_46 [ V_114 ] ) ) {
V_164 = F_236 ( V_16 , V_18 ) ;
goto V_156;
}
if ( V_114 == F_234 ) {
V_164 = F_227 ( V_16 , V_18 ) ;
if ( V_164 )
goto V_156;
}
V_164 = F_74 ( V_16 , V_18 , V_114 ) ;
V_156:
F_247 ( V_287 ) ;
V_164 = F_224 ( V_16 , V_18 , V_164 , V_216 ) ;
F_248 ( V_164 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
if ( F_89 ( V_164 ) )
F_249 ( V_16 , V_18 , V_164 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_290 ) && V_164 ) )
memset ( V_164 , 0 , F_8 ( V_16 ) ) ;
return V_164 ;
}
static T_1 void *
F_250 ( struct V_15 * V_25 , T_5 V_18 )
{
void * V_17 ;
if ( F_40 ( V_209 -> V_18 & ( V_291 | V_292 ) ) ) {
V_17 = F_73 ( V_25 , V_18 ) ;
if ( V_17 )
goto V_156;
}
V_17 = F_227 ( V_25 , V_18 ) ;
if ( ! V_17 )
V_17 = F_74 ( V_25 , V_18 , F_88 () ) ;
V_156:
return V_17 ;
}
static T_1 void *
F_250 ( struct V_15 * V_16 , T_5 V_18 )
{
return F_227 ( V_16 , V_18 ) ;
}
static T_1 void *
F_251 ( struct V_15 * V_16 , T_5 V_18 , void * V_216 )
{
unsigned long V_287 ;
void * V_17 ;
V_18 &= V_288 ;
F_245 ( V_18 ) ;
if ( F_225 ( V_16 , V_18 ) )
return NULL ;
F_222 ( V_16 , V_18 ) ;
F_246 ( V_287 ) ;
V_17 = F_250 ( V_16 , V_18 ) ;
F_247 ( V_287 ) ;
V_17 = F_224 ( V_16 , V_18 , V_17 , V_216 ) ;
F_248 ( V_17 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
F_252 ( V_17 ) ;
if ( F_89 ( V_17 ) )
F_249 ( V_16 , V_18 , V_17 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_290 ) && V_17 ) )
memset ( V_17 , 0 , F_8 ( V_16 ) ) ;
return V_17 ;
}
static void F_80 ( struct V_15 * V_16 , void * * V_293 , int V_294 ,
int V_49 )
{
int V_3 ;
struct V_4 * V_44 ;
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
void * V_17 = V_293 [ V_3 ] ;
struct V_29 * V_118 ;
V_118 = F_22 ( V_17 ) ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_192 ( & V_118 -> V_163 ) ;
F_186 ( V_16 , V_49 ) ;
F_217 ( V_16 , V_118 ) ;
F_204 ( V_16 , V_118 , V_17 , V_49 ) ;
F_253 ( V_16 ) ;
V_44 -> V_13 ++ ;
F_217 ( V_16 , V_118 ) ;
if ( V_118 -> V_254 == 0 ) {
if ( V_44 -> V_13 > V_44 -> V_124 ) {
V_44 -> V_13 -= V_16 -> V_74 ;
F_162 ( V_16 , V_118 ) ;
} else {
F_116 ( & V_118 -> V_163 , & V_44 -> V_8 ) ;
}
} else {
F_210 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
}
}
}
static void F_254 ( struct V_15 * V_16 , struct V_42 * V_116 )
{
int V_101 ;
struct V_4 * V_44 ;
int V_49 = F_88 () ;
V_101 = V_116 -> V_101 ;
#if V_64
F_10 ( ! V_101 || V_101 > V_116 -> V_105 ) ;
#endif
F_180 () ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_79 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 ) {
struct V_42 * V_295 = V_44 -> V_9 ;
int V_110 = V_295 -> V_106 - V_295 -> V_105 ;
if ( V_110 ) {
if ( V_101 > V_110 )
V_101 = V_110 ;
memcpy ( & ( V_295 -> V_112 [ V_295 -> V_105 ] ) ,
V_116 -> V_112 , sizeof( void * ) * V_101 ) ;
V_295 -> V_105 += V_101 ;
goto V_296;
}
}
F_80 ( V_16 , V_116 -> V_112 , V_101 , V_49 ) ;
V_296:
#if V_297
{
int V_3 = 0 ;
struct V_28 * V_253 ;
V_253 = V_44 -> V_8 . V_27 ;
while ( V_253 != & ( V_44 -> V_8 ) ) {
struct V_29 * V_118 ;
V_118 = F_191 ( V_253 , struct V_29 , V_163 ) ;
F_10 ( V_118 -> V_254 ) ;
V_3 ++ ;
V_253 = V_253 -> V_27 ;
}
F_255 ( V_16 , V_3 ) ;
}
#endif
F_81 ( & V_44 -> V_12 ) ;
V_116 -> V_105 -= V_101 ;
memmove ( V_116 -> V_112 , & ( V_116 -> V_112 [ V_101 ] ) , sizeof( void * ) * V_116 -> V_105 ) ;
}
static inline void F_256 ( struct V_15 * V_16 , void * V_17 ,
void * V_216 )
{
struct V_42 * V_116 = F_36 ( V_16 ) ;
F_180 () ;
F_257 ( V_17 , V_16 -> V_18 ) ;
V_17 = F_215 ( V_16 , V_17 , V_216 ) ;
F_258 ( V_16 , V_17 , F_8 ( V_16 ) ) ;
if ( V_298 > 1 && F_72 ( V_16 , V_17 ) )
return;
if ( F_89 ( V_116 -> V_105 < V_116 -> V_106 ) ) {
F_259 ( V_16 ) ;
V_116 -> V_112 [ V_116 -> V_105 ++ ] = V_17 ;
return;
} else {
F_260 ( V_16 ) ;
F_254 ( V_16 , V_116 ) ;
V_116 -> V_112 [ V_116 -> V_105 ++ ] = V_17 ;
}
}
void * F_261 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_148 = F_251 ( V_16 , V_18 , F_262 ( 0 ) ) ;
F_263 ( V_299 , V_148 ,
F_8 ( V_16 ) , V_16 -> V_21 , V_18 ) ;
return V_148 ;
}
void *
F_264 ( T_2 V_1 , struct V_15 * V_16 , T_5 V_18 )
{
void * V_148 ;
V_148 = F_251 ( V_16 , V_18 , F_262 ( 0 ) ) ;
F_265 ( V_299 , V_148 ,
V_1 , F_13 ( V_16 ) , V_18 ) ;
return V_148 ;
}
void * F_198 ( struct V_15 * V_16 , T_5 V_18 , int V_114 )
{
void * V_148 = F_244 ( V_16 , V_18 , V_114 ,
F_262 ( 0 ) ) ;
F_266 ( V_299 , V_148 ,
F_8 ( V_16 ) , V_16 -> V_21 ,
V_18 , V_114 ) ;
return V_148 ;
}
void * F_267 ( T_2 V_1 ,
struct V_15 * V_16 ,
T_5 V_18 ,
int V_114 )
{
void * V_148 ;
V_148 = F_244 ( V_16 , V_18 , V_114 ,
F_262 ( 0 ) ) ;
F_268 ( V_299 , V_148 ,
V_1 , F_13 ( V_16 ) ,
V_18 , V_114 ) ;
return V_148 ;
}
static T_1 void *
F_269 ( T_2 V_1 , T_5 V_18 , int V_49 , void * V_216 )
{
struct V_15 * V_16 ;
V_16 = F_41 ( V_1 , V_18 ) ;
if ( F_40 ( F_176 ( V_16 ) ) )
return V_16 ;
return F_267 ( V_1 , V_16 , V_18 , V_49 ) ;
}
void * F_270 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_269 ( V_1 , V_18 , V_49 ,
F_262 ( 0 ) ) ;
}
void * F_271 ( T_2 V_1 , T_5 V_18 ,
int V_49 , unsigned long V_216 )
{
return F_269 ( V_1 , V_18 , V_49 , ( void * ) V_216 ) ;
}
void * F_270 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_269 ( V_1 , V_18 , V_49 , NULL ) ;
}
static T_1 void * F_272 ( T_2 V_1 , T_5 V_18 ,
void * V_216 )
{
struct V_15 * V_16 ;
void * V_148 ;
V_16 = F_38 ( V_1 , V_18 ) ;
if ( F_40 ( F_176 ( V_16 ) ) )
return V_16 ;
V_148 = F_251 ( V_16 , V_18 , V_216 ) ;
F_265 ( ( unsigned long ) V_216 , V_148 ,
V_1 , V_16 -> V_21 , V_18 ) ;
return V_148 ;
}
void * F_273 ( T_2 V_1 , T_5 V_18 )
{
return F_272 ( V_1 , V_18 , F_262 ( 0 ) ) ;
}
void * F_274 ( T_2 V_1 , T_5 V_18 , unsigned long V_216 )
{
return F_272 ( V_1 , V_18 , ( void * ) V_216 ) ;
}
void * F_273 ( T_2 V_1 , T_5 V_18 )
{
return F_272 ( V_1 , V_18 , NULL ) ;
}
void F_146 ( struct V_15 * V_16 , void * V_17 )
{
unsigned long V_18 ;
F_246 ( V_18 ) ;
F_275 ( V_17 , F_8 ( V_16 ) ) ;
if ( ! ( V_16 -> V_18 & V_130 ) )
F_276 ( V_17 , F_8 ( V_16 ) ) ;
F_256 ( V_16 , V_17 , F_262 ( 0 ) ) ;
F_247 ( V_18 ) ;
F_277 ( V_299 , V_17 ) ;
}
void F_77 ( const void * V_17 )
{
struct V_15 * V_300 ;
unsigned long V_18 ;
F_278 ( V_299 , V_17 ) ;
if ( F_40 ( F_176 ( V_17 ) ) )
return;
F_246 ( V_18 ) ;
F_212 ( V_17 ) ;
V_300 = F_20 ( V_17 ) ;
F_275 ( V_17 , F_8 ( V_300 ) ) ;
F_276 ( V_17 , F_8 ( V_300 ) ) ;
F_256 ( V_300 , ( void * ) V_17 , F_262 ( 0 ) ) ;
F_247 ( V_18 ) ;
}
unsigned int F_279 ( struct V_15 * V_16 )
{
return F_8 ( V_16 ) ;
}
static int F_280 ( struct V_15 * V_16 , T_5 V_102 )
{
int V_49 ;
struct V_4 * V_44 ;
struct V_42 * V_301 ;
struct V_42 * * V_302 = NULL ;
F_32 (node) {
if ( V_84 ) {
V_302 = F_70 ( V_49 , V_16 -> V_106 , V_102 ) ;
if ( ! V_302 )
goto V_303;
}
V_301 = NULL ;
if ( V_16 -> V_9 ) {
V_301 = F_65 ( V_49 ,
V_16 -> V_9 * V_16 -> V_101 ,
0xbaadf00d , V_102 ) ;
if ( ! V_301 ) {
F_71 ( V_302 ) ;
goto V_303;
}
}
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 ) {
struct V_42 * V_9 = V_44 -> V_9 ;
F_94 ( & V_44 -> V_12 ) ;
if ( V_9 )
F_80 ( V_16 , V_9 -> V_112 ,
V_9 -> V_105 , V_49 ) ;
V_44 -> V_9 = V_301 ;
if ( ! V_44 -> V_10 ) {
V_44 -> V_10 = V_302 ;
V_302 = NULL ;
}
V_44 -> V_124 = ( 1 + F_95 ( V_49 ) ) *
V_16 -> V_101 + V_16 -> V_74 ;
F_84 ( & V_44 -> V_12 ) ;
F_77 ( V_9 ) ;
F_71 ( V_302 ) ;
continue;
}
V_44 = F_66 ( sizeof( struct V_4 ) , V_102 , V_49 ) ;
if ( ! V_44 ) {
F_71 ( V_302 ) ;
F_77 ( V_301 ) ;
goto V_303;
}
F_4 ( V_44 ) ;
V_44 -> V_121 = V_122 + V_123 +
( ( unsigned long ) V_16 ) % V_123 ;
V_44 -> V_9 = V_301 ;
V_44 -> V_10 = V_302 ;
V_44 -> V_124 = ( 1 + F_95 ( V_49 ) ) *
V_16 -> V_101 + V_16 -> V_74 ;
V_16 -> V_46 [ V_49 ] = V_44 ;
}
return 0 ;
V_303:
if ( ! V_16 -> V_27 . V_27 ) {
V_49 -- ;
while ( V_49 >= 0 ) {
if ( V_16 -> V_46 [ V_49 ] ) {
V_44 = V_16 -> V_46 [ V_49 ] ;
F_77 ( V_44 -> V_9 ) ;
F_71 ( V_44 -> V_10 ) ;
F_77 ( V_44 ) ;
V_16 -> V_46 [ V_49 ] = NULL ;
}
V_49 -- ;
}
}
return - V_120 ;
}
static void F_281 ( void * V_304 )
{
struct V_305 * V_306 = V_304 ;
struct V_42 * V_307 ;
F_180 () ;
V_307 = F_36 ( V_306 -> V_16 ) ;
V_306 -> V_16 -> V_61 [ F_37 () ] = V_306 -> V_306 [ F_37 () ] ;
V_306 -> V_306 [ F_37 () ] = V_307 ;
}
static int F_282 ( struct V_15 * V_16 , int V_106 ,
int V_101 , int V_9 , T_5 V_102 )
{
struct V_305 * V_306 ;
int V_3 ;
V_306 = F_283 ( sizeof( * V_306 ) + V_181 * sizeof( struct V_42 * ) ,
V_102 ) ;
if ( ! V_306 )
return - V_120 ;
F_128 (i) {
V_306 -> V_306 [ V_3 ] = F_65 ( F_54 ( V_3 ) , V_106 ,
V_101 , V_102 ) ;
if ( ! V_306 -> V_306 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_77 ( V_306 -> V_306 [ V_3 ] ) ;
F_77 ( V_306 ) ;
return - V_120 ;
}
}
V_306 -> V_16 = V_16 ;
F_189 ( F_281 , ( void * ) V_306 , 1 ) ;
F_182 () ;
V_16 -> V_101 = V_101 ;
V_16 -> V_106 = V_106 ;
V_16 -> V_9 = V_9 ;
F_128 (i) {
struct V_42 * V_308 = V_306 -> V_306 [ V_3 ] ;
if ( ! V_308 )
continue;
F_94 ( & V_16 -> V_46 [ F_54 ( V_3 ) ] -> V_12 ) ;
F_80 ( V_16 , V_308 -> V_112 , V_308 -> V_105 , F_54 ( V_3 ) ) ;
F_84 ( & V_16 -> V_46 [ F_54 ( V_3 ) ] -> V_12 ) ;
F_77 ( V_308 ) ;
}
F_77 ( V_306 ) ;
return F_280 ( V_16 , V_102 ) ;
}
static int F_123 ( struct V_15 * V_16 , T_5 V_102 )
{
int V_128 ;
int V_106 , V_9 ;
if ( V_16 -> V_21 > 131072 )
V_106 = 1 ;
else if ( V_16 -> V_21 > V_77 )
V_106 = 8 ;
else if ( V_16 -> V_21 > 1024 )
V_106 = 24 ;
else if ( V_16 -> V_21 > 256 )
V_106 = 54 ;
else
V_106 = 120 ;
V_9 = 0 ;
if ( V_16 -> V_21 <= V_77 && F_284 () > 1 )
V_9 = 8 ;
#if V_64
if ( V_106 > 32 )
V_106 = 32 ;
#endif
V_128 = F_282 ( V_16 , V_106 , ( V_106 + 1 ) / 2 , V_9 , V_102 ) ;
if ( V_128 )
F_46 ( V_82 L_40 ,
V_16 -> V_83 , - V_128 ) ;
return V_128 ;
}
static void F_190 ( struct V_15 * V_16 , struct V_4 * V_44 ,
struct V_42 * V_116 , int V_309 , int V_49 )
{
int V_252 ;
if ( ! V_116 || ! V_116 -> V_105 )
return;
if ( V_116 -> V_107 && ! V_309 ) {
V_116 -> V_107 = 0 ;
} else {
F_94 ( & V_44 -> V_12 ) ;
if ( V_116 -> V_105 ) {
V_252 = V_309 ? V_116 -> V_105 : ( V_116 -> V_106 + 4 ) / 5 ;
if ( V_252 > V_116 -> V_105 )
V_252 = ( V_116 -> V_105 + 1 ) / 2 ;
F_80 ( V_16 , V_116 -> V_112 , V_252 , V_49 ) ;
V_116 -> V_105 -= V_252 ;
memmove ( V_116 -> V_112 , & ( V_116 -> V_112 [ V_252 ] ) ,
sizeof( void * ) * V_116 -> V_105 ) ;
}
F_84 ( & V_44 -> V_12 ) ;
}
}
static void V_98 ( struct V_310 * V_311 )
{
struct V_15 * V_312 ;
struct V_4 * V_44 ;
int V_49 = F_88 () ;
struct V_93 * V_96 = F_285 ( V_311 ) ;
if ( ! F_286 ( & V_137 ) )
goto V_156;
F_93 (searchp, &cache_chain, next) {
F_182 () ;
V_44 = V_312 -> V_46 [ V_49 ] ;
F_82 ( V_312 , V_44 ) ;
F_190 ( V_312 , V_44 , F_36 ( V_312 ) , 0 , V_49 ) ;
if ( F_287 ( V_44 -> V_121 , V_122 ) )
goto V_27;
V_44 -> V_121 = V_122 + V_123 ;
F_190 ( V_312 , V_44 , V_44 -> V_9 , 0 , V_49 ) ;
if ( V_44 -> V_14 )
V_44 -> V_14 = 0 ;
else {
int V_313 ;
V_313 = F_99 ( V_312 , V_44 , ( V_44 -> V_124 +
5 * V_312 -> V_74 - 1 ) / ( 5 * V_312 -> V_74 ) ) ;
F_288 ( V_312 , V_313 ) ;
}
V_27:
F_289 () ;
}
F_182 () ;
F_104 ( & V_137 ) ;
F_57 () ;
V_156:
F_290 ( V_96 , F_291 ( V_314 ) ) ;
}
static void F_292 ( struct V_315 * V_316 )
{
#if V_297
F_293 ( V_316 , L_41 ) ;
#else
F_293 ( V_316 , L_42 ) ;
#endif
F_293 ( V_316 , L_43
L_44 ) ;
F_293 ( V_316 , L_45 ) ;
F_293 ( V_316 , L_46 ) ;
#if V_297
F_293 ( V_316 , L_47
L_48 ) ;
F_293 ( V_316 , L_49 ) ;
#endif
F_294 ( V_316 , '\n' ) ;
}
static void * F_295 ( struct V_315 * V_316 , T_10 * V_317 )
{
T_10 V_318 = * V_317 ;
F_103 ( & V_137 ) ;
if ( ! V_318 )
F_292 ( V_316 ) ;
return F_296 ( & V_178 , * V_317 ) ;
}
static void * F_297 ( struct V_315 * V_316 , void * V_253 , T_10 * V_317 )
{
return F_298 ( V_253 , & V_178 , V_317 ) ;
}
static void F_299 ( struct V_315 * V_316 , void * V_253 )
{
F_104 ( & V_137 ) ;
}
static int F_300 ( struct V_315 * V_316 , void * V_253 )
{
struct V_15 * V_16 = F_191 ( V_253 , struct V_15 , V_27 ) ;
struct V_29 * V_118 ;
unsigned long V_319 ;
unsigned long V_320 ;
unsigned long V_321 = 0 ;
unsigned long V_322 , V_13 = 0 , V_323 = 0 ;
const char * V_83 ;
char * error = NULL ;
int V_49 ;
struct V_4 * V_44 ;
V_319 = 0 ;
V_322 = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_182 () ;
F_94 ( & V_44 -> V_12 ) ;
F_93 (slabp, &l3->slabs_full, list) {
if ( V_118 -> V_254 != V_16 -> V_74 && ! error )
error = L_50 ;
V_319 += V_16 -> V_74 ;
V_321 ++ ;
}
F_93 (slabp, &l3->slabs_partial, list) {
if ( V_118 -> V_254 == V_16 -> V_74 && ! error )
error = L_51 ;
if ( ! V_118 -> V_254 && ! error )
error = L_52 ;
V_319 += V_118 -> V_254 ;
V_321 ++ ;
}
F_93 (slabp, &l3->slabs_free, list) {
if ( V_118 -> V_254 && ! error )
error = L_53 ;
V_322 ++ ;
}
V_13 += V_44 -> V_13 ;
if ( V_44 -> V_9 )
V_323 += V_44 -> V_9 -> V_105 ;
F_84 ( & V_44 -> V_12 ) ;
}
V_322 += V_321 ;
V_320 = V_322 * V_16 -> V_74 ;
if ( V_320 - V_319 != V_13 && ! error )
error = L_54 ;
V_83 = V_16 -> V_83 ;
if ( error )
F_46 ( V_82 L_55 , V_83 , error ) ;
F_301 ( V_316 , L_56 ,
V_83 , V_319 , V_320 , V_16 -> V_21 ,
V_16 -> V_74 , ( 1 << V_16 -> V_72 ) ) ;
F_301 ( V_316 , L_57 ,
V_16 -> V_106 , V_16 -> V_101 , V_16 -> V_9 ) ;
F_301 ( V_316 , L_58 ,
V_321 , V_322 , V_323 ) ;
#if V_297
{
unsigned long V_324 = V_16 -> V_325 ;
unsigned long V_326 = V_16 -> V_327 ;
unsigned long V_328 = V_16 -> V_328 ;
unsigned long V_329 = V_16 -> V_329 ;
unsigned long V_330 = V_16 -> V_330 ;
unsigned long V_331 = V_16 -> V_331 ;
unsigned long V_332 = V_16 -> V_332 ;
unsigned long V_333 = V_16 -> V_333 ;
unsigned long V_334 = V_16 -> V_335 ;
F_301 ( V_316 , L_59
L_60 ,
V_326 , V_324 , V_328 ,
V_329 , V_330 , V_331 , V_332 ,
V_333 , V_334 ) ;
}
{
unsigned long V_336 = F_302 ( & V_16 -> V_336 ) ;
unsigned long V_337 = F_302 ( & V_16 -> V_337 ) ;
unsigned long V_338 = F_302 ( & V_16 -> V_338 ) ;
unsigned long V_339 = F_302 ( & V_16 -> V_339 ) ;
F_301 ( V_316 , L_61 ,
V_336 , V_337 , V_338 , V_339 ) ;
}
#endif
F_294 ( V_316 , '\n' ) ;
return 0 ;
}
static T_11 F_303 ( struct V_340 * V_340 , const char T_12 * V_341 ,
T_2 V_342 , T_10 * V_343 )
{
char V_344 [ V_345 + 1 ] , * V_243 ;
int V_106 , V_101 , V_9 , V_244 ;
struct V_15 * V_16 ;
if ( V_342 > V_345 )
return - V_346 ;
if ( F_304 ( & V_344 , V_341 , V_342 ) )
return - V_347 ;
V_344 [ V_345 ] = '\0' ;
V_243 = strchr ( V_344 , ' ' ) ;
if ( ! V_243 )
return - V_346 ;
* V_243 = '\0' ;
V_243 ++ ;
if ( sscanf ( V_243 , L_62 , & V_106 , & V_101 , & V_9 ) != 3 )
return - V_346 ;
F_103 ( & V_137 ) ;
V_244 = - V_346 ;
F_93 (cachep, &cache_chain, next) {
if ( ! strcmp ( V_16 -> V_83 , V_344 ) ) {
if ( V_106 < 1 || V_101 < 1 ||
V_101 > V_106 || V_9 < 0 ) {
V_244 = 0 ;
} else {
V_244 = F_282 ( V_16 , V_106 ,
V_101 , V_9 ,
V_119 ) ;
}
break;
}
}
F_104 ( & V_137 ) ;
if ( V_244 >= 0 )
V_244 = V_342 ;
return V_244 ;
}
static int F_305 ( struct V_348 * V_348 , struct V_340 * V_340 )
{
return F_306 ( V_340 , & V_349 ) ;
}
static void * F_307 ( struct V_315 * V_316 , T_10 * V_317 )
{
F_103 ( & V_137 ) ;
return F_296 ( & V_178 , * V_317 ) ;
}
static inline int F_308 ( unsigned long * V_318 , unsigned long V_350 )
{
unsigned long * V_253 ;
int V_351 ;
if ( ! V_350 )
return 1 ;
V_351 = V_318 [ 1 ] ;
V_253 = V_318 + 2 ;
while ( V_351 ) {
int V_3 = V_351 / 2 ;
unsigned long * V_41 = V_253 + 2 * V_3 ;
if ( * V_41 == V_350 ) {
V_41 [ 1 ] ++ ;
return 1 ;
}
if ( * V_41 > V_350 ) {
V_351 = V_3 ;
} else {
V_253 = V_41 + 2 ;
V_351 -= V_3 + 1 ;
}
}
if ( ++ V_318 [ 1 ] == V_318 [ 0 ] )
return 0 ;
memmove ( V_253 + 2 , V_253 , V_318 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_253 - ( void * ) V_318 ) ) ;
V_253 [ 0 ] = V_350 ;
V_253 [ 1 ] = 1 ;
return 1 ;
}
static void F_309 ( unsigned long * V_318 , struct V_15 * V_300 , struct V_29 * V_53 )
{
void * V_253 ;
int V_3 ;
if ( V_318 [ 0 ] == V_318 [ 1 ] )
return;
for ( V_3 = 0 , V_253 = V_53 -> V_33 ; V_3 < V_300 -> V_74 ; V_3 ++ , V_253 += V_300 -> V_21 ) {
if ( F_200 ( V_53 ) [ V_3 ] != V_274 )
continue;
if ( ! F_308 ( V_318 , ( unsigned long ) * F_12 ( V_300 , V_253 ) ) )
return;
}
}
static void F_310 ( struct V_315 * V_316 , unsigned long V_352 )
{
#ifdef F_311
unsigned long V_34 , V_1 ;
char V_353 [ V_354 ] , V_83 [ V_355 ] ;
if ( F_312 ( V_352 , & V_1 , & V_34 , V_353 , V_83 ) == 0 ) {
F_301 ( V_316 , L_63 , V_83 , V_34 , V_1 ) ;
if ( V_353 [ 0 ] )
F_301 ( V_316 , L_64 , V_353 ) ;
return;
}
#endif
F_301 ( V_316 , L_65 , ( void * ) V_352 ) ;
}
static int F_313 ( struct V_315 * V_316 , void * V_253 )
{
struct V_15 * V_16 = F_191 ( V_253 , struct V_15 , V_27 ) ;
struct V_29 * V_118 ;
struct V_4 * V_44 ;
const char * V_83 ;
unsigned long * V_318 = V_316 -> V_356 ;
int V_49 ;
int V_3 ;
if ( ! ( V_16 -> V_18 & V_20 ) )
return 0 ;
if ( ! ( V_16 -> V_18 & V_19 ) )
return 0 ;
V_318 [ 1 ] = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_182 () ;
F_94 ( & V_44 -> V_12 ) ;
F_93 (slabp, &l3->slabs_full, list)
F_309 ( V_318 , V_16 , V_118 ) ;
F_93 (slabp, &l3->slabs_partial, list)
F_309 ( V_318 , V_16 , V_118 ) ;
F_84 ( & V_44 -> V_12 ) ;
}
V_83 = V_16 -> V_83 ;
if ( V_318 [ 0 ] == V_318 [ 1 ] ) {
F_104 ( & V_137 ) ;
V_316 -> V_356 = F_283 ( V_318 [ 0 ] * 4 * sizeof( unsigned long ) , V_119 ) ;
if ( ! V_316 -> V_356 ) {
V_316 -> V_356 = V_318 ;
F_103 ( & V_137 ) ;
return - V_120 ;
}
* ( unsigned long * ) V_316 -> V_356 = V_318 [ 0 ] * 2 ;
F_77 ( V_318 ) ;
F_103 ( & V_137 ) ;
V_316 -> V_342 = V_316 -> V_1 ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_318 [ 1 ] ; V_3 ++ ) {
F_301 ( V_316 , L_66 , V_83 , V_318 [ 2 * V_3 + 3 ] ) ;
F_310 ( V_316 , V_318 [ 2 * V_3 + 2 ] ) ;
F_294 ( V_316 , '\n' ) ;
}
return 0 ;
}
static int F_314 ( struct V_348 * V_348 , struct V_340 * V_340 )
{
unsigned long * V_318 = F_283 ( V_77 , V_119 ) ;
int V_148 = - V_120 ;
if ( V_318 ) {
V_148 = F_306 ( V_340 , & V_357 ) ;
if ( ! V_148 ) {
struct V_315 * V_316 = V_340 -> V_358 ;
* V_318 = V_77 / ( 2 * sizeof( unsigned long ) ) ;
V_316 -> V_356 = V_318 ;
V_318 = NULL ;
}
F_77 ( V_318 ) ;
}
return V_148 ;
}
static int T_6 F_315 ( void )
{
F_316 ( L_67 , V_359 | V_360 , NULL , & V_361 ) ;
#ifdef F_216
F_316 ( L_68 , 0 , NULL , & V_362 ) ;
#endif
return 0 ;
}
T_2 F_317 ( const void * V_17 )
{
F_10 ( ! V_17 ) ;
if ( F_40 ( V_17 == V_66 ) )
return 0 ;
return F_8 ( F_20 ( V_17 ) ) ;
}
