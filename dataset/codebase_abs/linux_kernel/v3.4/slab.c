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
static T_9 void
F_129 ( struct V_15 * V_16 , T_5 V_62 , int V_114 )
{
struct V_4 * V_44 ;
struct V_29 * V_118 ;
unsigned long V_18 ;
int V_49 ;
F_46 ( V_197
L_2 ,
V_114 , V_62 ) ;
F_46 ( V_197 L_3 ,
V_16 -> V_83 , V_16 -> V_21 , V_16 -> V_72 ) ;
F_32 (node) {
unsigned long V_198 = 0 , V_199 = 0 , V_13 = 0 ;
unsigned long V_200 = 0 , V_201 = 0 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_86 ( & V_44 -> V_12 , V_18 ) ;
F_93 (slabp, &l3->slabs_full, list) {
V_198 += V_16 -> V_74 ;
V_200 ++ ;
}
F_93 (slabp, &l3->slabs_partial, list) {
V_198 += V_118 -> V_202 ;
V_200 ++ ;
}
F_93 (slabp, &l3->slabs_free, list)
V_201 ++ ;
V_13 += V_44 -> V_13 ;
F_87 ( & V_44 -> V_12 , V_18 ) ;
V_201 += V_200 ;
V_199 = V_201 * V_16 -> V_74 ;
F_46 ( V_197
L_4 ,
V_49 , V_200 , V_201 , V_198 , V_199 ,
V_13 ) ;
}
}
static void * F_130 ( struct V_15 * V_16 , T_5 V_18 , int V_114 )
{
struct V_24 * V_24 ;
int V_203 ;
int V_3 ;
#ifndef F_131
V_18 |= V_204 ;
#endif
V_18 |= V_16 -> V_62 ;
if ( V_16 -> V_18 & V_205 )
V_18 |= V_206 ;
V_24 = F_132 ( V_114 , V_18 | V_207 , V_16 -> V_72 ) ;
if ( ! V_24 ) {
if ( ! ( V_18 & V_208 ) && F_133 () )
F_129 ( V_16 , V_18 , V_114 ) ;
return NULL ;
}
V_203 = ( 1 << V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_205 )
F_134 ( F_135 ( V_24 ) ,
V_209 , V_203 ) ;
else
F_134 ( F_135 ( V_24 ) ,
V_210 , V_203 ) ;
for ( V_3 = 0 ; V_3 < V_203 ; V_3 ++ )
F_136 ( V_24 + V_3 ) ;
if ( V_211 && ! ( V_16 -> V_18 & V_212 ) ) {
F_137 ( V_24 , V_16 -> V_72 , V_18 , V_114 ) ;
if ( V_16 -> V_213 )
F_138 ( V_24 , V_203 ) ;
else
F_139 ( V_24 , V_203 ) ;
}
return F_140 ( V_24 ) ;
}
static void F_141 ( struct V_15 * V_16 , void * V_214 )
{
unsigned long V_3 = ( 1 << V_16 -> V_72 ) ;
struct V_24 * V_24 = F_142 ( V_214 ) ;
const unsigned long V_215 = V_3 ;
F_143 ( V_24 , V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_205 )
F_144 ( F_135 ( V_24 ) ,
V_209 , V_215 ) ;
else
F_144 ( F_135 ( V_24 ) ,
V_210 , V_215 ) ;
while ( V_3 -- ) {
F_10 ( ! F_17 ( V_24 ) ) ;
F_145 ( V_24 ) ;
V_24 ++ ;
}
if ( V_216 -> V_217 )
V_216 -> V_217 -> V_218 += V_215 ;
F_146 ( ( unsigned long ) V_214 , V_16 -> V_72 ) ;
}
static void F_147 ( struct V_219 * V_220 )
{
struct V_221 * V_221 = (struct V_221 * ) V_220 ;
struct V_15 * V_16 = V_221 -> V_16 ;
F_141 ( V_16 , V_221 -> V_214 ) ;
if ( F_34 ( V_16 ) )
F_148 ( V_16 -> V_222 , V_221 ) ;
}
static void F_149 ( struct V_15 * V_16 , unsigned long * V_214 ,
unsigned long V_223 )
{
int V_1 = F_8 ( V_16 ) ;
V_214 = ( unsigned long * ) & ( ( char * ) V_214 ) [ F_7 ( V_16 ) ] ;
if ( V_1 < 5 * sizeof( unsigned long ) )
return;
* V_214 ++ = 0x12345678 ;
* V_214 ++ = V_223 ;
* V_214 ++ = F_37 () ;
V_1 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_224 = & V_223 ;
unsigned long V_225 ;
while ( ! F_150 ( V_224 ) ) {
V_225 = * V_224 ++ ;
if ( F_151 ( V_225 ) ) {
* V_214 ++ = V_225 ;
V_1 -= sizeof( unsigned long ) ;
if ( V_1 <= sizeof( unsigned long ) )
break;
}
}
}
* V_214 ++ = 0x87654321 ;
}
static void F_152 ( struct V_15 * V_16 , void * V_214 , unsigned char V_226 )
{
int V_1 = F_8 ( V_16 ) ;
V_214 = & ( ( char * ) V_214 ) [ F_7 ( V_16 ) ] ;
memset ( V_214 , V_226 , V_1 ) ;
* ( unsigned char * ) ( V_214 + V_1 - 1 ) = V_227 ;
}
static void F_153 ( char * V_228 , int V_34 , int V_106 )
{
int V_3 ;
unsigned char error = 0 ;
int V_229 = 0 ;
F_46 ( V_82 L_5 , V_34 ) ;
for ( V_3 = 0 ; V_3 < V_106 ; V_3 ++ ) {
if ( V_228 [ V_34 + V_3 ] != V_230 ) {
error = V_228 [ V_34 + V_3 ] ;
V_229 ++ ;
}
}
F_154 ( V_231 , L_6 , 0 , 16 , 1 ,
& V_228 [ V_34 ] , V_106 , 1 ) ;
if ( V_229 == 1 ) {
error ^= V_230 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_46 ( V_82 L_7
L_8 ) ;
#ifdef F_155
F_46 ( V_82 L_9
L_10 ) ;
#else
F_46 ( V_82 L_11 ) ;
#endif
}
}
}
static void F_156 ( struct V_15 * V_16 , void * V_17 , int V_232 )
{
int V_3 , V_1 ;
char * V_233 ;
if ( V_16 -> V_18 & V_19 ) {
F_46 ( V_82 L_12 ,
* F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
if ( V_16 -> V_18 & V_20 ) {
F_46 ( V_82 L_13 ,
* F_12 ( V_16 , V_17 ) ) ;
F_157 ( L_14 ,
( unsigned long ) * F_12 ( V_16 , V_17 ) ) ;
F_46 ( L_15 ) ;
}
V_233 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 && V_232 ; V_3 += 16 , V_232 -- ) {
int V_106 ;
V_106 = 16 ;
if ( V_3 + V_106 > V_1 )
V_106 = V_1 - V_3 ;
F_153 ( V_233 , V_3 , V_106 ) ;
}
}
static void F_158 ( struct V_15 * V_16 , void * V_17 )
{
char * V_233 ;
int V_1 , V_3 ;
int V_232 = 0 ;
V_233 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ ) {
char exp = V_230 ;
if ( V_3 == V_1 - 1 )
exp = V_227 ;
if ( V_233 [ V_3 ] != exp ) {
int V_106 ;
if ( V_232 == 0 ) {
F_46 ( V_82
L_16 ,
F_159 () , V_16 -> V_83 , V_233 , V_1 ) ;
F_156 ( V_16 , V_17 , 0 ) ;
}
V_3 = ( V_3 / 16 ) * 16 ;
V_106 = 16 ;
if ( V_3 + V_106 > V_1 )
V_106 = V_1 - V_3 ;
F_153 ( V_233 , V_3 , V_106 ) ;
V_3 += 16 ;
V_232 ++ ;
if ( V_232 > 5 )
break;
}
}
if ( V_232 != 0 ) {
struct V_29 * V_118 = F_22 ( V_17 ) ;
unsigned int V_234 ;
V_234 = F_24 ( V_16 , V_118 , V_17 ) ;
if ( V_234 ) {
V_17 = F_23 ( V_16 , V_118 , V_234 - 1 ) ;
V_233 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_17 ,
V_233 , V_1 ) ;
F_156 ( V_16 , V_17 , 2 ) ;
}
if ( V_234 + 1 < V_16 -> V_74 ) {
V_17 = F_23 ( V_16 , V_118 , V_234 + 1 ) ;
V_233 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_18 ,
V_233 , V_1 ) ;
F_156 ( V_16 , V_17 , 2 ) ;
}
}
}
static void F_160 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_118 , V_3 ) ;
if ( V_16 -> V_18 & V_235 ) {
#ifdef F_161
if ( V_16 -> V_21 % V_77 == 0 &&
F_34 ( V_16 ) )
F_162 ( F_142 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_158 ( V_16 , V_17 ) ;
#else
F_158 ( V_16 , V_17 ) ;
#endif
}
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_236 )
F_163 ( V_16 , L_19
L_20 ) ;
if ( * F_11 ( V_16 , V_17 ) != V_236 )
F_163 ( V_16 , L_21
L_20 ) ;
}
}
}
static void F_160 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
}
static void F_164 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
void * V_214 = V_118 -> V_33 - V_118 -> V_237 ;
F_160 ( V_16 , V_118 ) ;
if ( F_40 ( V_16 -> V_18 & V_238 ) ) {
struct V_221 * V_221 ;
V_221 = (struct V_221 * ) V_118 ;
V_221 -> V_16 = V_16 ;
V_221 -> V_214 = V_214 ;
F_165 ( & V_221 -> V_220 , F_147 ) ;
} else {
F_141 ( V_16 , V_214 ) ;
if ( F_34 ( V_16 ) )
F_148 ( V_16 -> V_222 , V_118 ) ;
}
}
static void F_166 ( struct V_15 * V_16 )
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
F_148 ( & V_173 , V_16 ) ;
}
static T_2 F_167 ( struct V_15 * V_16 ,
T_2 V_1 , T_2 V_70 , unsigned long V_18 )
{
unsigned long V_239 ;
T_2 V_73 = 0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 <= V_240 ; V_72 ++ ) {
unsigned int V_74 ;
T_2 V_241 ;
F_44 ( V_72 , V_1 , V_70 , V_18 , & V_241 , & V_74 ) ;
if ( ! V_74 )
continue;
if ( V_18 & V_78 ) {
V_239 = V_1 - sizeof( struct V_29 ) ;
V_239 /= sizeof( V_71 ) ;
if ( V_74 > V_239 )
break;
}
V_16 -> V_74 = V_74 ;
V_16 -> V_72 = V_72 ;
V_73 = V_241 ;
if ( V_18 & V_205 )
break;
if ( V_72 >= V_86 )
break;
if ( V_73 * 8 <= ( V_77 << V_72 ) )
break;
}
return V_73 ;
}
static int T_10 F_168 ( struct V_15 * V_16 , T_5 V_102 )
{
if ( V_36 == V_194 )
return F_123 ( V_16 , V_102 ) ;
if ( V_36 == V_242 ) {
V_16 -> V_61 [ F_37 () ] = & V_191 . V_25 ;
F_113 ( V_16 , V_192 ) ;
if ( V_65 == V_186 )
V_36 = V_243 ;
else
V_36 = V_244 ;
} else {
V_16 -> V_61 [ F_37 () ] =
F_121 ( sizeof( struct V_190 ) , V_102 ) ;
if ( V_36 == V_244 ) {
F_113 ( V_16 , V_193 ) ;
V_36 = V_243 ;
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
F_36 ( V_16 ) -> V_106 = V_245 ;
F_36 ( V_16 ) -> V_101 = 1 ;
F_36 ( V_16 ) -> V_107 = 0 ;
V_16 -> V_101 = 1 ;
V_16 -> V_106 = V_245 ;
return 0 ;
}
struct V_15 *
F_120 ( const char * V_83 , T_2 V_1 , T_2 V_70 ,
unsigned long V_18 , void (* V_213)( void * ) )
{
T_2 V_73 , V_76 , V_246 ;
struct V_15 * V_16 = NULL , * V_247 ;
T_5 V_102 ;
if ( ! V_83 || F_169 () || ( V_1 < V_23 ) ||
V_1 > V_248 ) {
F_46 ( V_82 L_22 , V_249 ,
V_83 ) ;
F_124 () ;
}
if ( F_26 () ) {
F_170 () ;
F_103 ( & V_137 ) ;
}
F_93 (pc, &cache_chain, next) {
char V_250 ;
int V_251 ;
V_251 = F_171 ( V_247 -> V_83 , V_250 ) ;
if ( V_251 ) {
F_46 ( V_82
L_23 ,
V_247 -> V_21 ) ;
continue;
}
if ( ! strcmp ( V_247 -> V_83 , V_83 ) ) {
F_46 ( V_82
L_24 , V_83 ) ;
F_47 () ;
goto V_252;
}
}
#if V_64
F_172 ( strchr ( V_83 , ' ' ) ) ;
#if V_253
if ( V_1 < 4096 || F_173 ( V_1 - 1 ) == F_173 ( V_1 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_18 |= V_19 | V_20 ;
if ( ! ( V_18 & V_238 ) )
V_18 |= V_235 ;
#endif
if ( V_18 & V_238 )
F_10 ( V_18 & V_235 ) ;
#endif
F_10 ( V_18 & ~ V_254 ) ;
if ( V_1 & ( V_23 - 1 ) ) {
V_1 += ( V_23 - 1 ) ;
V_1 &= ~ ( V_23 - 1 ) ;
}
if ( V_18 & V_255 ) {
V_246 = F_117 () ;
while ( V_1 <= V_246 / 2 )
V_246 /= 2 ;
} else {
V_246 = V_23 ;
}
if ( V_18 & V_20 )
V_246 = V_23 ;
if ( V_18 & V_19 ) {
V_246 = V_22 ;
V_1 += V_22 - 1 ;
V_1 &= ~ ( V_22 - 1 ) ;
}
if ( V_246 < V_256 ) {
V_246 = V_256 ;
}
if ( V_246 < V_70 ) {
V_246 = V_70 ;
}
if ( V_246 > F_174 (unsigned long long) )
V_18 &= ~ ( V_19 | V_20 ) ;
V_70 = V_246 ;
if ( F_26 () )
V_102 = V_119 ;
else
V_102 = V_165 ;
V_16 = F_175 ( & V_173 , V_102 ) ;
if ( ! V_16 )
goto V_252;
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
#if V_253 && F_176 ( F_161 )
if ( V_1 >= V_54 [ V_186 + 1 ] . V_56
&& V_16 -> F_8 > F_117 () && F_43 ( V_1 , V_70 ) < V_77 ) {
V_16 -> F_7 += V_77 - F_43 ( V_1 , V_70 ) ;
V_1 = V_77 ;
}
#endif
#endif
if ( ( V_1 >= ( V_77 >> 3 ) ) && ! V_187 &&
! ( V_18 & V_257 ) )
V_18 |= V_78 ;
V_1 = F_43 ( V_1 , V_70 ) ;
V_73 = F_167 ( V_16 , V_1 , V_70 , V_18 ) ;
if ( ! V_16 -> V_74 ) {
F_46 ( V_82
L_25 , V_83 ) ;
F_148 ( & V_173 , V_16 ) ;
V_16 = NULL ;
goto V_252;
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
#ifdef F_177
if ( V_1 % V_77 == 0 && V_18 & V_235 )
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
if ( V_258 && ( V_18 & V_189 ) )
V_16 -> V_62 |= V_67 ;
V_16 -> V_21 = V_1 ;
V_16 -> V_35 = F_119 ( V_1 ) ;
if ( V_18 & V_78 ) {
V_16 -> V_222 = F_41 ( V_76 , 0u ) ;
F_10 ( F_178 ( V_16 -> V_222 ) ) ;
}
V_16 -> V_213 = V_213 ;
V_16 -> V_83 = V_83 ;
if ( F_168 ( V_16 , V_102 ) ) {
F_166 ( V_16 ) ;
V_16 = NULL ;
goto V_252;
}
if ( V_18 & V_130 ) {
F_179 ( V_18 & V_238 ) ;
F_31 ( V_16 ) ;
}
F_116 ( & V_16 -> V_27 , & V_178 ) ;
V_252:
if ( ! V_16 && ( V_18 & V_185 ) )
F_180 ( L_26 ,
V_83 ) ;
if ( F_26 () ) {
F_104 ( & V_137 ) ;
F_181 () ;
}
return V_16 ;
}
static void F_182 ( void )
{
F_10 ( ! F_183 () ) ;
}
static void F_184 ( void )
{
F_10 ( F_183 () ) ;
}
static void F_185 ( struct V_15 * V_16 )
{
#ifdef F_186
F_182 () ;
F_187 ( & V_16 -> V_46 [ F_88 () ] -> V_12 ) ;
#endif
}
static void F_188 ( struct V_15 * V_16 , int V_49 )
{
#ifdef F_186
F_182 () ;
F_187 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
#endif
}
static void F_189 ( void * V_151 )
{
struct V_15 * V_16 = V_151 ;
struct V_42 * V_116 ;
int V_49 = F_88 () ;
F_182 () ;
V_116 = F_36 ( V_16 ) ;
F_79 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
F_80 ( V_16 , V_116 -> V_112 , V_116 -> V_105 , V_49 ) ;
F_81 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
V_116 -> V_105 = 0 ;
}
static void F_190 ( struct V_15 * V_16 )
{
struct V_4 * V_44 ;
int V_49 ;
F_191 ( F_189 , V_16 , 1 ) ;
F_184 () ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 && V_44 -> V_10 )
F_85 ( V_16 , V_44 -> V_10 ) ;
}
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 )
F_192 ( V_16 , V_44 , V_44 -> V_9 , 1 , V_49 ) ;
}
}
static int F_99 ( struct V_15 * V_25 ,
struct V_4 * V_44 , int V_259 )
{
struct V_28 * V_260 ;
int V_215 ;
struct V_29 * V_118 ;
V_215 = 0 ;
while ( V_215 < V_259 && ! F_109 ( & V_44 -> V_8 ) ) {
F_94 ( & V_44 -> V_12 ) ;
V_260 = V_44 -> V_8 . V_30 ;
if ( V_260 == & V_44 -> V_8 ) {
F_84 ( & V_44 -> V_12 ) ;
goto V_156;
}
V_118 = F_193 ( V_260 , struct V_29 , V_163 ) ;
#if V_64
F_10 ( V_118 -> V_202 ) ;
#endif
F_194 ( & V_118 -> V_163 ) ;
V_44 -> V_13 -= V_25 -> V_74 ;
F_84 ( & V_44 -> V_12 ) ;
F_164 ( V_25 , V_118 ) ;
V_215 ++ ;
}
V_156:
return V_215 ;
}
static int F_195 ( struct V_15 * V_16 )
{
int V_148 = 0 , V_3 = 0 ;
struct V_4 * V_44 ;
F_190 ( V_16 ) ;
F_184 () ;
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
int F_196 ( struct V_15 * V_16 )
{
int V_148 ;
F_10 ( ! V_16 || F_169 () ) ;
F_170 () ;
F_103 ( & V_137 ) ;
V_148 = F_195 ( V_16 ) ;
F_104 ( & V_137 ) ;
F_181 () ;
return V_148 ;
}
void F_197 ( struct V_15 * V_16 )
{
F_10 ( ! V_16 || F_169 () ) ;
F_170 () ;
F_103 ( & V_137 ) ;
F_194 ( & V_16 -> V_27 ) ;
if ( F_195 ( V_16 ) ) {
F_163 ( V_16 , L_27 ) ;
F_116 ( & V_16 -> V_27 , & V_178 ) ;
F_104 ( & V_137 ) ;
F_181 () ;
return;
}
if ( F_40 ( V_16 -> V_18 & V_238 ) )
F_198 () ;
F_166 ( V_16 ) ;
F_104 ( & V_137 ) ;
F_181 () ;
}
static struct V_29 * F_199 ( struct V_15 * V_16 , void * V_17 ,
int V_179 , T_5 V_261 ,
int V_114 )
{
struct V_29 * V_118 ;
if ( F_34 ( V_16 ) ) {
V_118 = F_200 ( V_16 -> V_222 ,
V_261 , V_114 ) ;
F_201 ( & V_118 -> V_163 , sizeof( struct V_28 ) ,
V_261 ) ;
if ( ! V_118 )
return NULL ;
} else {
V_118 = V_17 + V_179 ;
V_179 += V_16 -> V_76 ;
}
V_118 -> V_202 = 0 ;
V_118 -> V_237 = V_179 ;
V_118 -> V_33 = V_17 + V_179 ;
V_118 -> V_114 = V_114 ;
V_118 -> free = 0 ;
return V_118 ;
}
static inline V_71 * F_202 ( struct V_29 * V_118 )
{
return ( V_71 * ) ( V_118 + 1 ) ;
}
static void F_203 ( struct V_15 * V_16 ,
struct V_29 * V_118 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_118 , V_3 ) ;
#if V_64
if ( V_16 -> V_18 & V_235 )
F_152 ( V_16 , V_17 , V_230 ) ;
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = NULL ;
if ( V_16 -> V_18 & V_19 ) {
* F_9 ( V_16 , V_17 ) = V_236 ;
* F_11 ( V_16 , V_17 ) = V_236 ;
}
if ( V_16 -> V_213 && ! ( V_16 -> V_18 & V_235 ) )
V_16 -> V_213 ( V_17 + F_7 ( V_16 ) ) ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_11 ( V_16 , V_17 ) != V_236 )
F_163 ( V_16 , L_28
L_29 ) ;
if ( * F_9 ( V_16 , V_17 ) != V_236 )
F_163 ( V_16 , L_28
L_30 ) ;
}
if ( ( V_16 -> V_21 % V_77 ) == 0 &&
F_34 ( V_16 ) && V_16 -> V_18 & V_235 )
F_162 ( F_142 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
#else
if ( V_16 -> V_213 )
V_16 -> V_213 ( V_17 ) ;
#endif
F_202 ( V_118 ) [ V_3 ] = V_3 + 1 ;
}
F_202 ( V_118 ) [ V_3 - 1 ] = V_262 ;
}
static void F_204 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_258 ) {
if ( V_18 & V_67 )
F_10 ( ! ( V_16 -> V_62 & V_67 ) ) ;
else
F_10 ( V_16 -> V_62 & V_67 ) ;
}
}
static void * F_205 ( struct V_15 * V_16 , struct V_29 * V_118 ,
int V_114 )
{
void * V_17 = F_23 ( V_16 , V_118 , V_118 -> free ) ;
V_71 V_27 ;
V_118 -> V_202 ++ ;
V_27 = F_202 ( V_118 ) [ V_118 -> free ] ;
#if V_64
F_202 ( V_118 ) [ V_118 -> free ] = V_263 ;
F_172 ( V_118 -> V_114 != V_114 ) ;
#endif
V_118 -> free = V_27 ;
return V_17 ;
}
static void F_206 ( struct V_15 * V_16 , struct V_29 * V_118 ,
void * V_17 , int V_114 )
{
unsigned int V_234 = F_24 ( V_16 , V_118 , V_17 ) ;
#if V_64
F_172 ( V_118 -> V_114 != V_114 ) ;
if ( F_202 ( V_118 ) [ V_234 ] + 1 <= V_79 + 1 ) {
F_46 ( V_82 L_31
L_32 , V_16 -> V_83 , V_17 ) ;
F_124 () ;
}
#endif
F_202 ( V_118 ) [ V_234 ] = V_118 -> free ;
V_118 -> free = V_234 ;
V_118 -> V_202 -- ;
}
static void F_207 ( struct V_15 * V_25 , struct V_29 * V_29 ,
void * V_214 )
{
int V_203 ;
struct V_24 * V_24 ;
V_24 = F_142 ( V_214 ) ;
V_203 = 1 ;
if ( F_89 ( ! F_208 ( V_24 ) ) )
V_203 <<= V_25 -> V_72 ;
do {
F_14 ( V_24 , V_25 ) ;
F_18 ( V_24 , V_29 ) ;
V_24 ++ ;
} while ( -- V_203 );
}
static int F_209 ( struct V_15 * V_16 ,
T_5 V_18 , int V_114 , void * V_17 )
{
struct V_29 * V_118 ;
T_2 V_34 ;
T_5 V_261 ;
struct V_4 * V_44 ;
F_10 ( V_18 & V_264 ) ;
V_261 = V_18 & ( V_265 | V_266 ) ;
F_182 () ;
V_44 = V_16 -> V_46 [ V_114 ] ;
F_79 ( & V_44 -> V_12 ) ;
V_34 = V_44 -> V_11 ;
V_44 -> V_11 ++ ;
if ( V_44 -> V_11 >= V_16 -> V_182 )
V_44 -> V_11 = 0 ;
F_81 ( & V_44 -> V_12 ) ;
V_34 *= V_16 -> V_179 ;
if ( V_261 & V_267 )
F_210 () ;
F_204 ( V_16 , V_18 ) ;
if ( ! V_17 )
V_17 = F_130 ( V_16 , V_261 , V_114 ) ;
if ( ! V_17 )
goto V_268;
V_118 = F_199 ( V_16 , V_17 , V_34 ,
V_261 & ~ V_265 , V_114 ) ;
if ( ! V_118 )
goto V_269;
F_207 ( V_16 , V_118 , V_17 ) ;
F_203 ( V_16 , V_118 ) ;
if ( V_261 & V_267 )
F_211 () ;
F_182 () ;
F_79 ( & V_44 -> V_12 ) ;
F_212 ( & V_118 -> V_163 , & ( V_44 -> V_8 ) ) ;
F_213 ( V_16 ) ;
V_44 -> V_13 += V_16 -> V_74 ;
F_81 ( & V_44 -> V_12 ) ;
return 1 ;
V_269:
F_141 ( V_16 , V_17 ) ;
V_268:
if ( V_261 & V_267 )
F_211 () ;
return 0 ;
}
static void F_214 ( const void * V_17 )
{
if ( ! F_215 ( V_17 ) ) {
F_46 ( V_82 L_33 ,
( unsigned long ) V_17 ) ;
F_124 () ;
}
}
static inline void F_216 ( struct V_15 * V_25 , void * V_31 )
{
unsigned long long V_270 , V_271 ;
V_270 = * F_9 ( V_25 , V_31 ) ;
V_271 = * F_11 ( V_25 , V_31 ) ;
if ( V_270 == V_272 && V_271 == V_272 )
return;
if ( V_270 == V_236 && V_271 == V_236 )
F_163 ( V_25 , L_34 ) ;
else
F_163 ( V_25 , L_35 ) ;
F_46 ( V_82 L_36 ,
V_31 , V_270 , V_271 ) ;
}
static void * F_217 ( struct V_15 * V_16 , void * V_17 ,
void * V_223 )
{
struct V_24 * V_24 ;
unsigned int V_234 ;
struct V_29 * V_118 ;
F_10 ( F_20 ( V_17 ) != V_16 ) ;
V_17 -= F_7 ( V_16 ) ;
F_214 ( V_17 ) ;
V_24 = F_21 ( V_17 ) ;
V_118 = F_19 ( V_24 ) ;
if ( V_16 -> V_18 & V_19 ) {
F_216 ( V_16 , V_17 ) ;
* F_9 ( V_16 , V_17 ) = V_236 ;
* F_11 ( V_16 , V_17 ) = V_236 ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_223 ;
V_234 = F_24 ( V_16 , V_118 , V_17 ) ;
F_10 ( V_234 >= V_16 -> V_74 ) ;
F_10 ( V_17 != F_23 ( V_16 , V_118 , V_234 ) ) ;
#ifdef F_218
F_202 ( V_118 ) [ V_234 ] = V_263 ;
#endif
if ( V_16 -> V_18 & V_235 ) {
#ifdef F_161
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) ) {
F_149 ( V_16 , V_17 , ( unsigned long ) V_223 ) ;
F_162 ( F_142 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
} else {
F_152 ( V_16 , V_17 , V_230 ) ;
}
#else
F_152 ( V_16 , V_17 , V_230 ) ;
#endif
}
return V_17 ;
}
static void F_219 ( struct V_15 * V_16 , struct V_29 * V_118 )
{
V_71 V_3 ;
int V_100 = 0 ;
for ( V_3 = V_118 -> free ; V_3 != V_262 ; V_3 = F_202 ( V_118 ) [ V_3 ] ) {
V_100 ++ ;
if ( V_100 > V_16 -> V_74 || V_3 >= V_16 -> V_74 )
goto V_129;
}
if ( V_100 != V_16 -> V_74 - V_118 -> V_202 ) {
V_129:
F_46 ( V_82 L_37
L_38 ,
V_16 -> V_83 , V_16 -> V_74 , V_118 , V_118 -> V_202 ,
F_159 () ) ;
F_154 ( V_82 , L_6 , V_273 , 16 , 1 , V_118 ,
sizeof( * V_118 ) + V_16 -> V_74 * sizeof( V_71 ) ,
1 ) ;
F_124 () ;
}
}
static void * F_220 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_101 ;
struct V_4 * V_44 ;
struct V_42 * V_116 ;
int V_49 ;
V_274:
F_182 () ;
V_49 = F_88 () ;
V_116 = F_36 ( V_16 ) ;
V_101 = V_116 -> V_101 ;
if ( ! V_116 -> V_107 && V_101 > V_275 ) {
V_101 = V_275 ;
}
V_44 = V_16 -> V_46 [ V_49 ] ;
F_10 ( V_116 -> V_105 > 0 || ! V_44 ) ;
F_79 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 && F_68 ( V_116 , V_44 -> V_9 , V_101 ) ) {
V_44 -> V_9 -> V_107 = 1 ;
goto V_276;
}
while ( V_101 > 0 ) {
struct V_28 * V_112 ;
struct V_29 * V_118 ;
V_112 = V_44 -> V_7 . V_27 ;
if ( V_112 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_112 = V_44 -> V_8 . V_27 ;
if ( V_112 == & V_44 -> V_8 )
goto V_277;
}
V_118 = F_193 ( V_112 , struct V_29 , V_163 ) ;
F_219 ( V_16 , V_118 ) ;
F_185 ( V_16 ) ;
F_10 ( V_118 -> V_202 >= V_16 -> V_74 ) ;
while ( V_118 -> V_202 < V_16 -> V_74 && V_101 -- ) {
F_221 ( V_16 ) ;
F_222 ( V_16 ) ;
F_223 ( V_16 ) ;
V_116 -> V_112 [ V_116 -> V_105 ++ ] = F_205 ( V_16 , V_118 ,
V_49 ) ;
}
F_219 ( V_16 , V_118 ) ;
F_194 ( & V_118 -> V_163 ) ;
if ( V_118 -> free == V_262 )
F_116 ( & V_118 -> V_163 , & V_44 -> V_6 ) ;
else
F_116 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
}
V_277:
V_44 -> V_13 -= V_116 -> V_105 ;
V_276:
F_81 ( & V_44 -> V_12 ) ;
if ( F_40 ( ! V_116 -> V_105 ) ) {
int T_3 ;
T_3 = F_209 ( V_16 , V_18 | V_278 , V_49 , NULL ) ;
V_116 = F_36 ( V_16 ) ;
if ( ! T_3 && V_116 -> V_105 == 0 )
return NULL ;
if ( ! V_116 -> V_105 )
goto V_274;
}
V_116 -> V_107 = 1 ;
return V_116 -> V_112 [ -- V_116 -> V_105 ] ;
}
static inline void F_224 ( struct V_15 * V_16 ,
T_5 V_18 )
{
F_225 ( V_18 & V_267 ) ;
#if V_64
F_204 ( V_16 , V_18 ) ;
#endif
}
static void * F_226 ( struct V_15 * V_16 ,
T_5 V_18 , void * V_17 , void * V_223 )
{
if ( ! V_17 )
return V_17 ;
if ( V_16 -> V_18 & V_235 ) {
#ifdef F_161
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) )
F_162 ( F_142 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_158 ( V_16 , V_17 ) ;
#else
F_158 ( V_16 , V_17 ) ;
#endif
F_152 ( V_16 , V_17 , V_279 ) ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_223 ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_236 ||
* F_11 ( V_16 , V_17 ) != V_236 ) {
F_163 ( V_16 , L_39
L_40 ) ;
F_46 ( V_82
L_41 ,
V_17 , * F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
* F_9 ( V_16 , V_17 ) = V_272 ;
* F_11 ( V_16 , V_17 ) = V_272 ;
}
#ifdef F_218
{
struct V_29 * V_118 ;
unsigned V_234 ;
V_118 = F_19 ( F_21 ( V_17 ) ) ;
V_234 = ( unsigned ) ( V_17 - V_118 -> V_33 ) / V_16 -> V_21 ;
F_202 ( V_118 ) [ V_234 ] = V_280 ;
}
#endif
V_17 += F_7 ( V_16 ) ;
if ( V_16 -> V_213 && V_16 -> V_18 & V_235 )
V_16 -> V_213 ( V_17 ) ;
if ( V_256 &&
( ( unsigned long ) V_17 & ( V_256 - 1 ) ) ) {
F_46 ( V_82 L_42 ,
V_17 , ( int ) V_256 ) ;
}
return V_17 ;
}
static bool F_227 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_16 == & V_173 )
return false ;
return F_228 ( F_8 ( V_16 ) , V_18 , V_16 -> V_18 ) ;
}
static inline void * F_229 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_17 ;
struct V_42 * V_116 ;
F_182 () ;
V_116 = F_36 ( V_16 ) ;
if ( F_89 ( V_116 -> V_105 ) ) {
F_230 ( V_16 ) ;
V_116 -> V_107 = 1 ;
V_17 = V_116 -> V_112 [ -- V_116 -> V_105 ] ;
} else {
F_231 ( V_16 ) ;
V_17 = F_220 ( V_16 , V_18 ) ;
V_116 = F_36 ( V_16 ) ;
}
if ( V_17 )
F_232 ( & V_116 -> V_112 [ V_116 -> V_105 ] ) ;
return V_17 ;
}
static void * F_73 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_281 , V_282 ;
if ( F_169 () || ( V_18 & V_283 ) )
return NULL ;
V_281 = V_282 = F_88 () ;
if ( F_233 () && ( V_16 -> V_18 & V_284 ) )
V_281 = F_234 () ;
else if ( V_216 -> V_285 )
V_281 = F_235 ( V_216 -> V_285 ) ;
if ( V_281 != V_282 )
return F_74 ( V_16 , V_18 , V_281 ) ;
return NULL ;
}
static void * F_236 ( struct V_15 * V_25 , T_5 V_18 )
{
struct V_286 * V_286 ;
T_5 V_261 ;
struct V_287 * V_288 ;
struct V_289 * V_289 ;
enum V_290 V_291 = F_237 ( V_18 ) ;
void * V_31 = NULL ;
int V_154 ;
unsigned int V_292 ;
if ( V_18 & V_283 )
return NULL ;
V_261 = V_18 & ( V_265 | V_266 ) ;
V_293:
V_292 = F_238 () ;
V_286 = F_239 ( F_235 ( V_216 -> V_285 ) , V_18 ) ;
V_274:
F_240 (zone, z, zonelist, high_zoneidx) {
V_154 = F_241 ( V_289 ) ;
if ( F_242 ( V_289 , V_18 ) &&
V_25 -> V_46 [ V_154 ] &&
V_25 -> V_46 [ V_154 ] -> V_13 ) {
V_31 = F_74 ( V_25 ,
V_18 | V_278 , V_154 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
if ( V_261 & V_267 )
F_210 () ;
F_204 ( V_25 , V_18 ) ;
V_31 = F_130 ( V_25 , V_261 , F_88 () ) ;
if ( V_261 & V_267 )
F_211 () ;
if ( V_31 ) {
V_154 = F_243 ( F_142 ( V_31 ) ) ;
if ( F_209 ( V_25 , V_18 , V_154 , V_31 ) ) {
V_31 = F_74 ( V_25 ,
V_18 | V_278 , V_154 ) ;
if ( ! V_31 )
goto V_274;
} else {
V_31 = NULL ;
}
}
}
if ( F_40 ( ! F_244 ( V_292 ) && ! V_31 ) )
goto V_293;
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
V_274:
F_182 () ;
F_79 ( & V_44 -> V_12 ) ;
V_112 = V_44 -> V_7 . V_27 ;
if ( V_112 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_112 = V_44 -> V_8 . V_27 ;
if ( V_112 == & V_44 -> V_8 )
goto V_277;
}
V_118 = F_193 ( V_112 , struct V_29 , V_163 ) ;
F_188 ( V_16 , V_114 ) ;
F_219 ( V_16 , V_118 ) ;
F_245 ( V_16 ) ;
F_222 ( V_16 ) ;
F_223 ( V_16 ) ;
F_10 ( V_118 -> V_202 == V_16 -> V_74 ) ;
V_31 = F_205 ( V_16 , V_118 , V_114 ) ;
F_219 ( V_16 , V_118 ) ;
V_44 -> V_13 -- ;
F_194 ( & V_118 -> V_163 ) ;
if ( V_118 -> free == V_262 )
F_116 ( & V_118 -> V_163 , & V_44 -> V_6 ) ;
else
F_116 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
F_81 ( & V_44 -> V_12 ) ;
goto V_294;
V_277:
F_81 ( & V_44 -> V_12 ) ;
T_3 = F_209 ( V_16 , V_18 | V_278 , V_114 , NULL ) ;
if ( T_3 )
goto V_274;
return F_236 ( V_16 , V_18 ) ;
V_294:
return V_31 ;
}
static T_1 void *
F_246 ( struct V_15 * V_16 , T_5 V_18 , int V_114 ,
void * V_223 )
{
unsigned long V_295 ;
void * V_164 ;
int F_235 = F_88 () ;
V_18 &= V_296 ;
F_247 ( V_18 ) ;
if ( F_227 ( V_16 , V_18 ) )
return NULL ;
F_224 ( V_16 , V_18 ) ;
F_248 ( V_295 ) ;
if ( V_114 == V_297 )
V_114 = F_235 ;
if ( F_40 ( ! V_16 -> V_46 [ V_114 ] ) ) {
V_164 = F_236 ( V_16 , V_18 ) ;
goto V_156;
}
if ( V_114 == F_235 ) {
V_164 = F_229 ( V_16 , V_18 ) ;
if ( V_164 )
goto V_156;
}
V_164 = F_74 ( V_16 , V_18 , V_114 ) ;
V_156:
F_249 ( V_295 ) ;
V_164 = F_226 ( V_16 , V_18 , V_164 , V_223 ) ;
F_250 ( V_164 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
if ( F_89 ( V_164 ) )
F_251 ( V_16 , V_18 , V_164 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_298 ) && V_164 ) )
memset ( V_164 , 0 , F_8 ( V_16 ) ) ;
return V_164 ;
}
static T_1 void *
F_252 ( struct V_15 * V_25 , T_5 V_18 )
{
void * V_17 ;
if ( F_40 ( V_216 -> V_18 & ( V_299 | V_300 ) ) ) {
V_17 = F_73 ( V_25 , V_18 ) ;
if ( V_17 )
goto V_156;
}
V_17 = F_229 ( V_25 , V_18 ) ;
if ( ! V_17 )
V_17 = F_74 ( V_25 , V_18 , F_88 () ) ;
V_156:
return V_17 ;
}
static T_1 void *
F_252 ( struct V_15 * V_16 , T_5 V_18 )
{
return F_229 ( V_16 , V_18 ) ;
}
static T_1 void *
F_253 ( struct V_15 * V_16 , T_5 V_18 , void * V_223 )
{
unsigned long V_295 ;
void * V_17 ;
V_18 &= V_296 ;
F_247 ( V_18 ) ;
if ( F_227 ( V_16 , V_18 ) )
return NULL ;
F_224 ( V_16 , V_18 ) ;
F_248 ( V_295 ) ;
V_17 = F_252 ( V_16 , V_18 ) ;
F_249 ( V_295 ) ;
V_17 = F_226 ( V_16 , V_18 , V_17 , V_223 ) ;
F_250 ( V_17 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
F_254 ( V_17 ) ;
if ( F_89 ( V_17 ) )
F_251 ( V_16 , V_18 , V_17 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_298 ) && V_17 ) )
memset ( V_17 , 0 , F_8 ( V_16 ) ) ;
return V_17 ;
}
static void F_80 ( struct V_15 * V_16 , void * * V_301 , int V_302 ,
int V_49 )
{
int V_3 ;
struct V_4 * V_44 ;
for ( V_3 = 0 ; V_3 < V_302 ; V_3 ++ ) {
void * V_17 = V_301 [ V_3 ] ;
struct V_29 * V_118 ;
V_118 = F_22 ( V_17 ) ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_194 ( & V_118 -> V_163 ) ;
F_188 ( V_16 , V_49 ) ;
F_219 ( V_16 , V_118 ) ;
F_206 ( V_16 , V_118 , V_17 , V_49 ) ;
F_255 ( V_16 ) ;
V_44 -> V_13 ++ ;
F_219 ( V_16 , V_118 ) ;
if ( V_118 -> V_202 == 0 ) {
if ( V_44 -> V_13 > V_44 -> V_124 ) {
V_44 -> V_13 -= V_16 -> V_74 ;
F_164 ( V_16 , V_118 ) ;
} else {
F_116 ( & V_118 -> V_163 , & V_44 -> V_8 ) ;
}
} else {
F_212 ( & V_118 -> V_163 , & V_44 -> V_7 ) ;
}
}
}
static void F_256 ( struct V_15 * V_16 , struct V_42 * V_116 )
{
int V_101 ;
struct V_4 * V_44 ;
int V_49 = F_88 () ;
V_101 = V_116 -> V_101 ;
#if V_64
F_10 ( ! V_101 || V_101 > V_116 -> V_105 ) ;
#endif
F_182 () ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_79 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 ) {
struct V_42 * V_303 = V_44 -> V_9 ;
int V_110 = V_303 -> V_106 - V_303 -> V_105 ;
if ( V_110 ) {
if ( V_101 > V_110 )
V_101 = V_110 ;
memcpy ( & ( V_303 -> V_112 [ V_303 -> V_105 ] ) ,
V_116 -> V_112 , sizeof( void * ) * V_101 ) ;
V_303 -> V_105 += V_101 ;
goto V_304;
}
}
F_80 ( V_16 , V_116 -> V_112 , V_101 , V_49 ) ;
V_304:
#if V_305
{
int V_3 = 0 ;
struct V_28 * V_260 ;
V_260 = V_44 -> V_8 . V_27 ;
while ( V_260 != & ( V_44 -> V_8 ) ) {
struct V_29 * V_118 ;
V_118 = F_193 ( V_260 , struct V_29 , V_163 ) ;
F_10 ( V_118 -> V_202 ) ;
V_3 ++ ;
V_260 = V_260 -> V_27 ;
}
F_257 ( V_16 , V_3 ) ;
}
#endif
F_81 ( & V_44 -> V_12 ) ;
V_116 -> V_105 -= V_101 ;
memmove ( V_116 -> V_112 , & ( V_116 -> V_112 [ V_101 ] ) , sizeof( void * ) * V_116 -> V_105 ) ;
}
static inline void F_258 ( struct V_15 * V_16 , void * V_17 ,
void * V_223 )
{
struct V_42 * V_116 = F_36 ( V_16 ) ;
F_182 () ;
F_259 ( V_17 , V_16 -> V_18 ) ;
V_17 = F_217 ( V_16 , V_17 , V_223 ) ;
F_260 ( V_16 , V_17 , F_8 ( V_16 ) ) ;
if ( V_306 > 1 && F_72 ( V_16 , V_17 ) )
return;
if ( F_89 ( V_116 -> V_105 < V_116 -> V_106 ) ) {
F_261 ( V_16 ) ;
} else {
F_262 ( V_16 ) ;
F_256 ( V_16 , V_116 ) ;
}
V_116 -> V_112 [ V_116 -> V_105 ++ ] = V_17 ;
}
void * F_263 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_148 = F_253 ( V_16 , V_18 , F_264 ( 0 ) ) ;
F_265 ( V_307 , V_148 ,
F_8 ( V_16 ) , V_16 -> V_21 , V_18 ) ;
return V_148 ;
}
void *
F_266 ( T_2 V_1 , struct V_15 * V_16 , T_5 V_18 )
{
void * V_148 ;
V_148 = F_253 ( V_16 , V_18 , F_264 ( 0 ) ) ;
F_267 ( V_307 , V_148 ,
V_1 , F_13 ( V_16 ) , V_18 ) ;
return V_148 ;
}
void * F_200 ( struct V_15 * V_16 , T_5 V_18 , int V_114 )
{
void * V_148 = F_246 ( V_16 , V_18 , V_114 ,
F_264 ( 0 ) ) ;
F_268 ( V_307 , V_148 ,
F_8 ( V_16 ) , V_16 -> V_21 ,
V_18 , V_114 ) ;
return V_148 ;
}
void * F_269 ( T_2 V_1 ,
struct V_15 * V_16 ,
T_5 V_18 ,
int V_114 )
{
void * V_148 ;
V_148 = F_246 ( V_16 , V_18 , V_114 ,
F_264 ( 0 ) ) ;
F_270 ( V_307 , V_148 ,
V_1 , F_13 ( V_16 ) ,
V_18 , V_114 ) ;
return V_148 ;
}
static T_1 void *
F_271 ( T_2 V_1 , T_5 V_18 , int V_49 , void * V_223 )
{
struct V_15 * V_16 ;
V_16 = F_41 ( V_1 , V_18 ) ;
if ( F_40 ( F_178 ( V_16 ) ) )
return V_16 ;
return F_269 ( V_1 , V_16 , V_18 , V_49 ) ;
}
void * F_272 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_271 ( V_1 , V_18 , V_49 ,
F_264 ( 0 ) ) ;
}
void * F_273 ( T_2 V_1 , T_5 V_18 ,
int V_49 , unsigned long V_223 )
{
return F_271 ( V_1 , V_18 , V_49 , ( void * ) V_223 ) ;
}
void * F_272 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_271 ( V_1 , V_18 , V_49 , NULL ) ;
}
static T_1 void * F_274 ( T_2 V_1 , T_5 V_18 ,
void * V_223 )
{
struct V_15 * V_16 ;
void * V_148 ;
V_16 = F_38 ( V_1 , V_18 ) ;
if ( F_40 ( F_178 ( V_16 ) ) )
return V_16 ;
V_148 = F_253 ( V_16 , V_18 , V_223 ) ;
F_267 ( ( unsigned long ) V_223 , V_148 ,
V_1 , V_16 -> V_21 , V_18 ) ;
return V_148 ;
}
void * F_275 ( T_2 V_1 , T_5 V_18 )
{
return F_274 ( V_1 , V_18 , F_264 ( 0 ) ) ;
}
void * F_276 ( T_2 V_1 , T_5 V_18 , unsigned long V_223 )
{
return F_274 ( V_1 , V_18 , ( void * ) V_223 ) ;
}
void * F_275 ( T_2 V_1 , T_5 V_18 )
{
return F_274 ( V_1 , V_18 , NULL ) ;
}
void F_148 ( struct V_15 * V_16 , void * V_17 )
{
unsigned long V_18 ;
F_248 ( V_18 ) ;
F_277 ( V_17 , F_8 ( V_16 ) ) ;
if ( ! ( V_16 -> V_18 & V_130 ) )
F_278 ( V_17 , F_8 ( V_16 ) ) ;
F_258 ( V_16 , V_17 , F_264 ( 0 ) ) ;
F_249 ( V_18 ) ;
F_279 ( V_307 , V_17 ) ;
}
void F_77 ( const void * V_17 )
{
struct V_15 * V_308 ;
unsigned long V_18 ;
F_280 ( V_307 , V_17 ) ;
if ( F_40 ( F_178 ( V_17 ) ) )
return;
F_248 ( V_18 ) ;
F_214 ( V_17 ) ;
V_308 = F_20 ( V_17 ) ;
F_277 ( V_17 , F_8 ( V_308 ) ) ;
F_278 ( V_17 , F_8 ( V_308 ) ) ;
F_258 ( V_308 , ( void * ) V_17 , F_264 ( 0 ) ) ;
F_249 ( V_18 ) ;
}
unsigned int F_281 ( struct V_15 * V_16 )
{
return F_8 ( V_16 ) ;
}
static int F_282 ( struct V_15 * V_16 , T_5 V_102 )
{
int V_49 ;
struct V_4 * V_44 ;
struct V_42 * V_309 ;
struct V_42 * * V_310 = NULL ;
F_32 (node) {
if ( V_84 ) {
V_310 = F_70 ( V_49 , V_16 -> V_106 , V_102 ) ;
if ( ! V_310 )
goto V_311;
}
V_309 = NULL ;
if ( V_16 -> V_9 ) {
V_309 = F_65 ( V_49 ,
V_16 -> V_9 * V_16 -> V_101 ,
0xbaadf00d , V_102 ) ;
if ( ! V_309 ) {
F_71 ( V_310 ) ;
goto V_311;
}
}
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 ) {
struct V_42 * V_9 = V_44 -> V_9 ;
F_94 ( & V_44 -> V_12 ) ;
if ( V_9 )
F_80 ( V_16 , V_9 -> V_112 ,
V_9 -> V_105 , V_49 ) ;
V_44 -> V_9 = V_309 ;
if ( ! V_44 -> V_10 ) {
V_44 -> V_10 = V_310 ;
V_310 = NULL ;
}
V_44 -> V_124 = ( 1 + F_95 ( V_49 ) ) *
V_16 -> V_101 + V_16 -> V_74 ;
F_84 ( & V_44 -> V_12 ) ;
F_77 ( V_9 ) ;
F_71 ( V_310 ) ;
continue;
}
V_44 = F_66 ( sizeof( struct V_4 ) , V_102 , V_49 ) ;
if ( ! V_44 ) {
F_71 ( V_310 ) ;
F_77 ( V_309 ) ;
goto V_311;
}
F_4 ( V_44 ) ;
V_44 -> V_121 = V_122 + V_123 +
( ( unsigned long ) V_16 ) % V_123 ;
V_44 -> V_9 = V_309 ;
V_44 -> V_10 = V_310 ;
V_44 -> V_124 = ( 1 + F_95 ( V_49 ) ) *
V_16 -> V_101 + V_16 -> V_74 ;
V_16 -> V_46 [ V_49 ] = V_44 ;
}
return 0 ;
V_311:
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
static void F_283 ( void * V_312 )
{
struct V_313 * V_314 = V_312 ;
struct V_42 * V_315 ;
F_182 () ;
V_315 = F_36 ( V_314 -> V_16 ) ;
V_314 -> V_16 -> V_61 [ F_37 () ] = V_314 -> V_314 [ F_37 () ] ;
V_314 -> V_314 [ F_37 () ] = V_315 ;
}
static int F_284 ( struct V_15 * V_16 , int V_106 ,
int V_101 , int V_9 , T_5 V_102 )
{
struct V_313 * V_314 ;
int V_3 ;
V_314 = F_285 ( sizeof( * V_314 ) + V_181 * sizeof( struct V_42 * ) ,
V_102 ) ;
if ( ! V_314 )
return - V_120 ;
F_128 (i) {
V_314 -> V_314 [ V_3 ] = F_65 ( F_54 ( V_3 ) , V_106 ,
V_101 , V_102 ) ;
if ( ! V_314 -> V_314 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_77 ( V_314 -> V_314 [ V_3 ] ) ;
F_77 ( V_314 ) ;
return - V_120 ;
}
}
V_314 -> V_16 = V_16 ;
F_191 ( F_283 , ( void * ) V_314 , 1 ) ;
F_184 () ;
V_16 -> V_101 = V_101 ;
V_16 -> V_106 = V_106 ;
V_16 -> V_9 = V_9 ;
F_128 (i) {
struct V_42 * V_316 = V_314 -> V_314 [ V_3 ] ;
if ( ! V_316 )
continue;
F_94 ( & V_16 -> V_46 [ F_54 ( V_3 ) ] -> V_12 ) ;
F_80 ( V_16 , V_316 -> V_112 , V_316 -> V_105 , F_54 ( V_3 ) ) ;
F_84 ( & V_16 -> V_46 [ F_54 ( V_3 ) ] -> V_12 ) ;
F_77 ( V_316 ) ;
}
F_77 ( V_314 ) ;
return F_282 ( V_16 , V_102 ) ;
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
if ( V_16 -> V_21 <= V_77 && F_286 () > 1 )
V_9 = 8 ;
#if V_64
if ( V_106 > 32 )
V_106 = 32 ;
#endif
V_128 = F_284 ( V_16 , V_106 , ( V_106 + 1 ) / 2 , V_9 , V_102 ) ;
if ( V_128 )
F_46 ( V_82 L_43 ,
V_16 -> V_83 , - V_128 ) ;
return V_128 ;
}
static void F_192 ( struct V_15 * V_16 , struct V_4 * V_44 ,
struct V_42 * V_116 , int V_317 , int V_49 )
{
int V_259 ;
if ( ! V_116 || ! V_116 -> V_105 )
return;
if ( V_116 -> V_107 && ! V_317 ) {
V_116 -> V_107 = 0 ;
} else {
F_94 ( & V_44 -> V_12 ) ;
if ( V_116 -> V_105 ) {
V_259 = V_317 ? V_116 -> V_105 : ( V_116 -> V_106 + 4 ) / 5 ;
if ( V_259 > V_116 -> V_105 )
V_259 = ( V_116 -> V_105 + 1 ) / 2 ;
F_80 ( V_16 , V_116 -> V_112 , V_259 , V_49 ) ;
V_116 -> V_105 -= V_259 ;
memmove ( V_116 -> V_112 , & ( V_116 -> V_112 [ V_259 ] ) ,
sizeof( void * ) * V_116 -> V_105 ) ;
}
F_84 ( & V_44 -> V_12 ) ;
}
}
static void V_98 ( struct V_318 * V_319 )
{
struct V_15 * V_320 ;
struct V_4 * V_44 ;
int V_49 = F_88 () ;
struct V_93 * V_96 = F_287 ( V_319 ) ;
if ( ! F_288 ( & V_137 ) )
goto V_156;
F_93 (searchp, &cache_chain, next) {
F_184 () ;
V_44 = V_320 -> V_46 [ V_49 ] ;
F_82 ( V_320 , V_44 ) ;
F_192 ( V_320 , V_44 , F_36 ( V_320 ) , 0 , V_49 ) ;
if ( F_289 ( V_44 -> V_121 , V_122 ) )
goto V_27;
V_44 -> V_121 = V_122 + V_123 ;
F_192 ( V_320 , V_44 , V_44 -> V_9 , 0 , V_49 ) ;
if ( V_44 -> V_14 )
V_44 -> V_14 = 0 ;
else {
int V_321 ;
V_321 = F_99 ( V_320 , V_44 , ( V_44 -> V_124 +
5 * V_320 -> V_74 - 1 ) / ( 5 * V_320 -> V_74 ) ) ;
F_290 ( V_320 , V_321 ) ;
}
V_27:
F_291 () ;
}
F_184 () ;
F_104 ( & V_137 ) ;
F_57 () ;
V_156:
F_292 ( V_96 , F_293 ( V_322 ) ) ;
}
static void F_294 ( struct V_323 * V_324 )
{
#if V_305
F_295 ( V_324 , L_44 ) ;
#else
F_295 ( V_324 , L_45 ) ;
#endif
F_295 ( V_324 , L_46
L_47 ) ;
F_295 ( V_324 , L_48 ) ;
F_295 ( V_324 , L_49 ) ;
#if V_305
F_295 ( V_324 , L_50
L_51 ) ;
F_295 ( V_324 , L_52 ) ;
#endif
F_296 ( V_324 , '\n' ) ;
}
static void * F_297 ( struct V_323 * V_324 , T_11 * V_325 )
{
T_11 V_326 = * V_325 ;
F_103 ( & V_137 ) ;
if ( ! V_326 )
F_294 ( V_324 ) ;
return F_298 ( & V_178 , * V_325 ) ;
}
static void * F_299 ( struct V_323 * V_324 , void * V_260 , T_11 * V_325 )
{
return F_300 ( V_260 , & V_178 , V_325 ) ;
}
static void F_301 ( struct V_323 * V_324 , void * V_260 )
{
F_104 ( & V_137 ) ;
}
static int F_302 ( struct V_323 * V_324 , void * V_260 )
{
struct V_15 * V_16 = F_193 ( V_260 , struct V_15 , V_27 ) ;
struct V_29 * V_118 ;
unsigned long V_198 ;
unsigned long V_199 ;
unsigned long V_200 = 0 ;
unsigned long V_201 , V_13 = 0 , V_327 = 0 ;
const char * V_83 ;
char * error = NULL ;
int V_49 ;
struct V_4 * V_44 ;
V_198 = 0 ;
V_201 = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_184 () ;
F_94 ( & V_44 -> V_12 ) ;
F_93 (slabp, &l3->slabs_full, list) {
if ( V_118 -> V_202 != V_16 -> V_74 && ! error )
error = L_53 ;
V_198 += V_16 -> V_74 ;
V_200 ++ ;
}
F_93 (slabp, &l3->slabs_partial, list) {
if ( V_118 -> V_202 == V_16 -> V_74 && ! error )
error = L_54 ;
if ( ! V_118 -> V_202 && ! error )
error = L_55 ;
V_198 += V_118 -> V_202 ;
V_200 ++ ;
}
F_93 (slabp, &l3->slabs_free, list) {
if ( V_118 -> V_202 && ! error )
error = L_56 ;
V_201 ++ ;
}
V_13 += V_44 -> V_13 ;
if ( V_44 -> V_9 )
V_327 += V_44 -> V_9 -> V_105 ;
F_84 ( & V_44 -> V_12 ) ;
}
V_201 += V_200 ;
V_199 = V_201 * V_16 -> V_74 ;
if ( V_199 - V_198 != V_13 && ! error )
error = L_57 ;
V_83 = V_16 -> V_83 ;
if ( error )
F_46 ( V_82 L_58 , V_83 , error ) ;
F_303 ( V_324 , L_59 ,
V_83 , V_198 , V_199 , V_16 -> V_21 ,
V_16 -> V_74 , ( 1 << V_16 -> V_72 ) ) ;
F_303 ( V_324 , L_60 ,
V_16 -> V_106 , V_16 -> V_101 , V_16 -> V_9 ) ;
F_303 ( V_324 , L_61 ,
V_200 , V_201 , V_327 ) ;
#if V_305
{
unsigned long V_328 = V_16 -> V_329 ;
unsigned long V_330 = V_16 -> V_331 ;
unsigned long V_332 = V_16 -> V_332 ;
unsigned long V_333 = V_16 -> V_333 ;
unsigned long V_334 = V_16 -> V_334 ;
unsigned long V_335 = V_16 -> V_335 ;
unsigned long V_336 = V_16 -> V_336 ;
unsigned long V_337 = V_16 -> V_337 ;
unsigned long V_338 = V_16 -> V_339 ;
F_303 ( V_324 , L_62
L_63 ,
V_330 , V_328 , V_332 ,
V_333 , V_334 , V_335 , V_336 ,
V_337 , V_338 ) ;
}
{
unsigned long V_340 = F_304 ( & V_16 -> V_340 ) ;
unsigned long V_341 = F_304 ( & V_16 -> V_341 ) ;
unsigned long V_342 = F_304 ( & V_16 -> V_342 ) ;
unsigned long V_343 = F_304 ( & V_16 -> V_343 ) ;
F_303 ( V_324 , L_64 ,
V_340 , V_341 , V_342 , V_343 ) ;
}
#endif
F_296 ( V_324 , '\n' ) ;
return 0 ;
}
static T_12 F_305 ( struct V_344 * V_344 , const char T_13 * V_345 ,
T_2 V_346 , T_11 * V_347 )
{
char V_348 [ V_349 + 1 ] , * V_250 ;
int V_106 , V_101 , V_9 , V_251 ;
struct V_15 * V_16 ;
if ( V_346 > V_349 )
return - V_350 ;
if ( F_306 ( & V_348 , V_345 , V_346 ) )
return - V_351 ;
V_348 [ V_349 ] = '\0' ;
V_250 = strchr ( V_348 , ' ' ) ;
if ( ! V_250 )
return - V_350 ;
* V_250 = '\0' ;
V_250 ++ ;
if ( sscanf ( V_250 , L_65 , & V_106 , & V_101 , & V_9 ) != 3 )
return - V_350 ;
F_103 ( & V_137 ) ;
V_251 = - V_350 ;
F_93 (cachep, &cache_chain, next) {
if ( ! strcmp ( V_16 -> V_83 , V_348 ) ) {
if ( V_106 < 1 || V_101 < 1 ||
V_101 > V_106 || V_9 < 0 ) {
V_251 = 0 ;
} else {
V_251 = F_284 ( V_16 , V_106 ,
V_101 , V_9 ,
V_119 ) ;
}
break;
}
}
F_104 ( & V_137 ) ;
if ( V_251 >= 0 )
V_251 = V_346 ;
return V_251 ;
}
static int F_307 ( struct V_352 * V_352 , struct V_344 * V_344 )
{
return F_308 ( V_344 , & V_353 ) ;
}
static void * F_309 ( struct V_323 * V_324 , T_11 * V_325 )
{
F_103 ( & V_137 ) ;
return F_298 ( & V_178 , * V_325 ) ;
}
static inline int F_310 ( unsigned long * V_326 , unsigned long V_354 )
{
unsigned long * V_260 ;
int V_355 ;
if ( ! V_354 )
return 1 ;
V_355 = V_326 [ 1 ] ;
V_260 = V_326 + 2 ;
while ( V_355 ) {
int V_3 = V_355 / 2 ;
unsigned long * V_41 = V_260 + 2 * V_3 ;
if ( * V_41 == V_354 ) {
V_41 [ 1 ] ++ ;
return 1 ;
}
if ( * V_41 > V_354 ) {
V_355 = V_3 ;
} else {
V_260 = V_41 + 2 ;
V_355 -= V_3 + 1 ;
}
}
if ( ++ V_326 [ 1 ] == V_326 [ 0 ] )
return 0 ;
memmove ( V_260 + 2 , V_260 , V_326 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_260 - ( void * ) V_326 ) ) ;
V_260 [ 0 ] = V_354 ;
V_260 [ 1 ] = 1 ;
return 1 ;
}
static void F_311 ( unsigned long * V_326 , struct V_15 * V_308 , struct V_29 * V_53 )
{
void * V_260 ;
int V_3 ;
if ( V_326 [ 0 ] == V_326 [ 1 ] )
return;
for ( V_3 = 0 , V_260 = V_53 -> V_33 ; V_3 < V_308 -> V_74 ; V_3 ++ , V_260 += V_308 -> V_21 ) {
if ( F_202 ( V_53 ) [ V_3 ] != V_280 )
continue;
if ( ! F_310 ( V_326 , ( unsigned long ) * F_12 ( V_308 , V_260 ) ) )
return;
}
}
static void F_312 ( struct V_323 * V_324 , unsigned long V_356 )
{
#ifdef F_313
unsigned long V_34 , V_1 ;
char V_357 [ V_358 ] , V_83 [ V_359 ] ;
if ( F_314 ( V_356 , & V_1 , & V_34 , V_357 , V_83 ) == 0 ) {
F_303 ( V_324 , L_66 , V_83 , V_34 , V_1 ) ;
if ( V_357 [ 0 ] )
F_303 ( V_324 , L_67 , V_357 ) ;
return;
}
#endif
F_303 ( V_324 , L_68 , ( void * ) V_356 ) ;
}
static int F_315 ( struct V_323 * V_324 , void * V_260 )
{
struct V_15 * V_16 = F_193 ( V_260 , struct V_15 , V_27 ) ;
struct V_29 * V_118 ;
struct V_4 * V_44 ;
const char * V_83 ;
unsigned long * V_326 = V_324 -> V_360 ;
int V_49 ;
int V_3 ;
if ( ! ( V_16 -> V_18 & V_20 ) )
return 0 ;
if ( ! ( V_16 -> V_18 & V_19 ) )
return 0 ;
V_326 [ 1 ] = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_184 () ;
F_94 ( & V_44 -> V_12 ) ;
F_93 (slabp, &l3->slabs_full, list)
F_311 ( V_326 , V_16 , V_118 ) ;
F_93 (slabp, &l3->slabs_partial, list)
F_311 ( V_326 , V_16 , V_118 ) ;
F_84 ( & V_44 -> V_12 ) ;
}
V_83 = V_16 -> V_83 ;
if ( V_326 [ 0 ] == V_326 [ 1 ] ) {
F_104 ( & V_137 ) ;
V_324 -> V_360 = F_285 ( V_326 [ 0 ] * 4 * sizeof( unsigned long ) , V_119 ) ;
if ( ! V_324 -> V_360 ) {
V_324 -> V_360 = V_326 ;
F_103 ( & V_137 ) ;
return - V_120 ;
}
* ( unsigned long * ) V_324 -> V_360 = V_326 [ 0 ] * 2 ;
F_77 ( V_326 ) ;
F_103 ( & V_137 ) ;
V_324 -> V_346 = V_324 -> V_1 ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_326 [ 1 ] ; V_3 ++ ) {
F_303 ( V_324 , L_69 , V_83 , V_326 [ 2 * V_3 + 3 ] ) ;
F_312 ( V_324 , V_326 [ 2 * V_3 + 2 ] ) ;
F_296 ( V_324 , '\n' ) ;
}
return 0 ;
}
static int F_316 ( struct V_352 * V_352 , struct V_344 * V_344 )
{
unsigned long * V_326 = F_285 ( V_77 , V_119 ) ;
int V_148 = - V_120 ;
if ( V_326 ) {
V_148 = F_308 ( V_344 , & V_361 ) ;
if ( ! V_148 ) {
struct V_323 * V_324 = V_344 -> V_362 ;
* V_326 = V_77 / ( 2 * sizeof( unsigned long ) ) ;
V_324 -> V_360 = V_326 ;
V_326 = NULL ;
}
F_77 ( V_326 ) ;
}
return V_148 ;
}
static int T_6 F_317 ( void )
{
F_318 ( L_70 , V_363 | V_364 , NULL , & V_365 ) ;
#ifdef F_218
F_318 ( L_71 , 0 , NULL , & V_366 ) ;
#endif
return 0 ;
}
T_2 F_319 ( const void * V_17 )
{
F_10 ( ! V_17 ) ;
if ( F_40 ( V_17 == V_66 ) )
return 0 ;
return F_8 ( F_20 ( V_17 ) ) ;
}
