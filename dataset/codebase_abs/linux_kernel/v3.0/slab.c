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
static void F_27 ( int V_38 )
{
struct V_39 * V_40 = V_41 ;
if ( V_36 != V_42 )
return;
for ( V_40 = V_41 ; V_40 -> V_43 != V_44 ; V_40 ++ ) {
struct V_45 * * V_46 ;
struct V_4 * V_47 ;
int V_48 ;
V_47 = V_40 -> V_49 -> V_50 [ V_38 ] ;
if ( ! V_47 || F_28 ( V_40 -> V_49 ) )
continue;
F_29 ( & V_47 -> V_12 , & V_51 ) ;
V_46 = V_47 -> V_10 ;
if ( ! V_46 || ( unsigned long ) V_46 == V_52 )
continue;
F_30 (r) {
if ( V_46 [ V_48 ] )
F_29 ( & V_46 [ V_48 ] -> V_53 ,
& V_54 ) ;
}
}
}
static inline void F_31 ( void )
{
int V_55 ;
F_30 (node)
F_27 ( V_55 ) ;
}
static void F_27 ( int V_38 )
{
}
static inline void F_31 ( void )
{
}
static inline struct V_45 * F_32 ( struct V_15 * V_16 )
{
return V_16 -> V_56 [ F_33 () ] ;
}
static inline struct V_15 * F_34 ( T_2 V_1 ,
T_5 V_57 )
{
struct V_39 * V_58 = V_41 ;
#if V_59
F_10 ( V_41 [ V_60 ] . V_49 == NULL ) ;
#endif
if ( ! V_1 )
return V_61 ;
while ( V_1 > V_58 -> V_43 )
V_58 ++ ;
#ifdef F_35
if ( F_36 ( V_57 & V_62 ) )
return V_58 -> V_63 ;
#endif
return V_58 -> V_49 ;
}
static struct V_15 * F_37 ( T_2 V_1 , T_5 V_57 )
{
return F_34 ( V_1 , V_57 ) ;
}
static T_2 F_38 ( T_2 V_64 , T_2 V_65 )
{
return F_39 ( sizeof( struct V_29 ) + V_64 * sizeof( V_66 ) , V_65 ) ;
}
static void F_40 ( unsigned long V_67 , T_2 V_21 ,
T_2 V_65 , int V_18 , T_2 * V_68 ,
unsigned int * V_69 )
{
int V_64 ;
T_2 V_70 ;
T_2 V_71 = V_72 << V_67 ;
if ( V_18 & V_73 ) {
V_70 = 0 ;
V_64 = V_71 / V_21 ;
if ( V_64 > V_74 )
V_64 = V_74 ;
} else {
V_64 = ( V_71 - sizeof( struct V_29 ) ) /
( V_21 + sizeof( V_66 ) ) ;
if ( F_38 ( V_64 , V_65 ) + V_64 * V_21
> V_71 )
V_64 -- ;
if ( V_64 > V_74 )
V_64 = V_74 ;
V_70 = F_38 ( V_64 , V_65 ) ;
}
* V_69 = V_64 ;
* V_68 = V_71 - V_64 * V_21 - V_70 ;
}
static void F_41 ( const char * V_75 , struct V_15 * V_16 ,
char * V_76 )
{
F_42 ( V_77 L_1 ,
V_75 , V_16 -> V_78 , V_76 ) ;
F_43 () ;
}
static int T_6 F_44 ( char * V_40 )
{
V_79 = 0 ;
return 1 ;
}
static void F_45 ( int V_80 )
{
int V_55 ;
V_55 = F_46 ( F_47 ( V_80 ) , V_81 ) ;
if ( V_55 == V_82 )
V_55 = F_48 ( V_81 ) ;
F_49 ( V_83 , V_80 ) = V_55 ;
}
static void F_50 ( void )
{
int V_55 = F_51 ( V_83 ) ;
V_55 = F_46 ( V_55 , V_81 ) ;
if ( F_36 ( V_55 >= V_82 ) )
V_55 = F_48 ( V_81 ) ;
F_52 ( V_83 , V_55 ) ;
}
static void T_7 F_53 ( int V_80 )
{
struct V_84 * V_85 = & F_49 ( V_86 , V_80 ) ;
if ( F_54 () && V_85 -> V_87 . V_88 == NULL ) {
F_45 ( V_80 ) ;
F_55 ( V_85 , V_89 ) ;
F_56 ( V_80 , V_85 ,
F_57 ( V_90 , V_80 ) ) ;
}
}
static struct V_45 * F_58 ( int V_55 , int V_91 ,
int V_92 , T_5 V_93 )
{
int V_94 = sizeof( void * ) * V_91 + sizeof( struct V_45 ) ;
struct V_45 * V_95 = NULL ;
V_95 = F_59 ( V_94 , V_93 , V_55 ) ;
F_60 ( V_95 ) ;
if ( V_95 ) {
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_91 ;
V_95 -> V_92 = V_92 ;
V_95 -> V_98 = 0 ;
F_6 ( & V_95 -> V_53 ) ;
}
return V_95 ;
}
static int F_61 ( struct V_45 * V_99 ,
struct V_45 * V_100 , unsigned int V_101 )
{
int V_102 = F_62 ( V_100 -> V_96 , V_101 , V_99 -> V_97 - V_99 -> V_96 ) ;
if ( ! V_102 )
return 0 ;
memcpy ( V_99 -> V_103 + V_99 -> V_96 , V_100 -> V_103 + V_100 -> V_96 - V_102 ,
sizeof( void * ) * V_102 ) ;
V_100 -> V_96 -= V_102 ;
V_99 -> V_96 += V_102 ;
return V_102 ;
}
static inline struct V_45 * * F_63 ( int V_55 , int V_97 , T_5 V_93 )
{
return (struct V_45 * * ) V_52 ;
}
static inline void F_64 ( struct V_45 * * V_104 )
{
}
static inline int F_65 ( struct V_15 * V_16 , void * V_17 )
{
return 0 ;
}
static inline void * F_66 ( struct V_15 * V_16 ,
T_5 V_18 )
{
return NULL ;
}
static inline void * F_67 ( struct V_15 * V_16 ,
T_5 V_18 , int V_105 )
{
return NULL ;
}
static struct V_45 * * F_63 ( int V_55 , int V_97 , T_5 V_93 )
{
struct V_45 * * V_104 ;
int V_94 = sizeof( void * ) * V_106 ;
int V_3 ;
if ( V_97 > 1 )
V_97 = 12 ;
V_104 = F_68 ( V_94 , V_93 , V_55 ) ;
if ( V_104 ) {
F_30 (i) {
if ( V_3 == V_55 || ! F_69 ( V_3 ) )
continue;
V_104 [ V_3 ] = F_58 ( V_55 , V_97 , 0xbaadf00d , V_93 ) ;
if ( ! V_104 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_70 ( V_104 [ V_3 ] ) ;
F_70 ( V_104 ) ;
return NULL ;
}
}
}
return V_104 ;
}
static void F_64 ( struct V_45 * * V_104 )
{
int V_3 ;
if ( ! V_104 )
return;
F_30 (i)
F_70 ( V_104 [ V_3 ] ) ;
F_70 ( V_104 ) ;
}
static void F_71 ( struct V_15 * V_16 ,
struct V_45 * V_107 , int V_55 )
{
struct V_4 * V_108 = V_16 -> V_50 [ V_55 ] ;
if ( V_107 -> V_96 ) {
F_72 ( & V_108 -> V_12 ) ;
if ( V_108 -> V_9 )
F_61 ( V_108 -> V_9 , V_107 , V_107 -> V_97 ) ;
F_73 ( V_16 , V_107 -> V_103 , V_107 -> V_96 , V_55 ) ;
V_107 -> V_96 = 0 ;
F_74 ( & V_108 -> V_12 ) ;
}
}
static void F_75 ( struct V_15 * V_16 , struct V_4 * V_47 )
{
int V_55 = F_51 ( V_83 ) ;
if ( V_47 -> V_10 ) {
struct V_45 * V_107 = V_47 -> V_10 [ V_55 ] ;
if ( V_107 && V_107 -> V_96 && F_76 ( & V_107 -> V_53 ) ) {
F_71 ( V_16 , V_107 , V_55 ) ;
F_77 ( & V_107 -> V_53 ) ;
}
}
}
static void F_78 ( struct V_15 * V_16 ,
struct V_45 * * V_10 )
{
int V_3 = 0 ;
struct V_45 * V_107 ;
unsigned long V_18 ;
F_79 (i) {
V_107 = V_10 [ V_3 ] ;
if ( V_107 ) {
F_80 ( & V_107 -> V_53 , V_18 ) ;
F_71 ( V_16 , V_107 , V_3 ) ;
F_81 ( & V_107 -> V_53 , V_18 ) ;
}
}
}
static inline int F_65 ( struct V_15 * V_16 , void * V_17 )
{
struct V_29 * V_109 = F_22 ( V_17 ) ;
int V_105 = V_109 -> V_105 ;
struct V_4 * V_47 ;
struct V_45 * V_10 = NULL ;
int V_55 ;
V_55 = F_82 () ;
if ( F_83 ( V_109 -> V_105 == V_55 ) )
return 0 ;
V_47 = V_16 -> V_50 [ V_55 ] ;
F_84 ( V_16 ) ;
if ( V_47 -> V_10 && V_47 -> V_10 [ V_105 ] ) {
V_10 = V_47 -> V_10 [ V_105 ] ;
F_72 ( & V_10 -> V_53 ) ;
if ( F_36 ( V_10 -> V_96 == V_10 -> V_97 ) ) {
F_85 ( V_16 ) ;
F_71 ( V_16 , V_10 , V_105 ) ;
}
V_10 -> V_103 [ V_10 -> V_96 ++ ] = V_17 ;
F_74 ( & V_10 -> V_53 ) ;
} else {
F_72 ( & ( V_16 -> V_50 [ V_105 ] ) -> V_12 ) ;
F_73 ( V_16 , & V_17 , 1 , V_105 ) ;
F_74 ( & ( V_16 -> V_50 [ V_105 ] ) -> V_12 ) ;
}
return 1 ;
}
static int F_86 ( int V_55 )
{
struct V_15 * V_16 ;
struct V_4 * V_47 ;
const int V_94 = sizeof( struct V_4 ) ;
F_87 (cachep, &cache_chain, next) {
if ( ! V_16 -> V_50 [ V_55 ] ) {
V_47 = F_59 ( V_94 , V_110 , V_55 ) ;
if ( ! V_47 )
return - V_111 ;
F_4 ( V_47 ) ;
V_47 -> V_112 = V_113 + V_114 +
( ( unsigned long ) V_16 ) % V_114 ;
V_16 -> V_50 [ V_55 ] = V_47 ;
}
F_88 ( & V_16 -> V_50 [ V_55 ] -> V_12 ) ;
V_16 -> V_50 [ V_55 ] -> V_115 =
( 1 + F_89 ( V_55 ) ) *
V_16 -> V_92 + V_16 -> V_69 ;
F_77 ( & V_16 -> V_50 [ V_55 ] -> V_12 ) ;
}
return 0 ;
}
static void T_7 F_90 ( long V_80 )
{
struct V_15 * V_16 ;
struct V_4 * V_47 = NULL ;
int V_55 = F_47 ( V_80 ) ;
const struct V_116 * V_117 = F_91 ( V_55 ) ;
F_87 (cachep, &cache_chain, next) {
struct V_45 * V_95 ;
struct V_45 * V_9 ;
struct V_45 * * V_10 ;
V_95 = V_16 -> V_56 [ V_80 ] ;
V_16 -> V_56 [ V_80 ] = NULL ;
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( ! V_47 )
goto V_118;
F_88 ( & V_47 -> V_12 ) ;
V_47 -> V_115 -= V_16 -> V_92 ;
if ( V_95 )
F_73 ( V_16 , V_95 -> V_103 , V_95 -> V_96 , V_55 ) ;
if ( ! F_92 ( V_117 ) ) {
F_77 ( & V_47 -> V_12 ) ;
goto V_118;
}
V_9 = V_47 -> V_9 ;
if ( V_9 ) {
F_73 ( V_16 , V_9 -> V_103 ,
V_9 -> V_96 , V_55 ) ;
V_47 -> V_9 = NULL ;
}
V_10 = V_47 -> V_10 ;
V_47 -> V_10 = NULL ;
F_77 ( & V_47 -> V_12 ) ;
F_70 ( V_9 ) ;
if ( V_10 ) {
F_78 ( V_16 , V_10 ) ;
F_64 ( V_10 ) ;
}
V_118:
F_70 ( V_95 ) ;
}
F_87 (cachep, &cache_chain, next) {
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( ! V_47 )
continue;
F_93 ( V_16 , V_47 , V_47 -> V_13 ) ;
}
}
static int T_7 F_94 ( long V_80 )
{
struct V_15 * V_16 ;
struct V_4 * V_47 = NULL ;
int V_55 = F_47 ( V_80 ) ;
int V_119 ;
V_119 = F_86 ( V_55 ) ;
if ( V_119 < 0 )
goto V_120;
F_87 (cachep, &cache_chain, next) {
struct V_45 * V_95 ;
struct V_45 * V_9 = NULL ;
struct V_45 * * V_10 = NULL ;
V_95 = F_58 ( V_55 , V_16 -> V_97 ,
V_16 -> V_92 , V_110 ) ;
if ( ! V_95 )
goto V_120;
if ( V_16 -> V_9 ) {
V_9 = F_58 ( V_55 ,
V_16 -> V_9 * V_16 -> V_92 ,
0xbaadf00d , V_110 ) ;
if ( ! V_9 ) {
F_70 ( V_95 ) ;
goto V_120;
}
}
if ( V_79 ) {
V_10 = F_63 ( V_55 , V_16 -> V_97 , V_110 ) ;
if ( ! V_10 ) {
F_70 ( V_9 ) ;
F_70 ( V_95 ) ;
goto V_120;
}
}
V_16 -> V_56 [ V_80 ] = V_95 ;
V_47 = V_16 -> V_50 [ V_55 ] ;
F_10 ( ! V_47 ) ;
F_88 ( & V_47 -> V_12 ) ;
if ( ! V_47 -> V_9 ) {
V_47 -> V_9 = V_9 ;
V_9 = NULL ;
}
#ifdef F_95
if ( ! V_47 -> V_10 ) {
V_47 -> V_10 = V_10 ;
V_10 = NULL ;
}
#endif
F_77 ( & V_47 -> V_12 ) ;
F_70 ( V_9 ) ;
F_64 ( V_10 ) ;
}
F_27 ( V_55 ) ;
return 0 ;
V_120:
F_90 ( V_80 ) ;
return - V_111 ;
}
static int T_7 F_96 ( struct V_121 * V_122 ,
unsigned long V_123 , void * V_124 )
{
long V_80 = ( long ) V_124 ;
int V_119 = 0 ;
switch ( V_123 ) {
case V_125 :
case V_126 :
F_97 ( & V_127 ) ;
V_119 = F_94 ( V_80 ) ;
F_98 ( & V_127 ) ;
break;
case V_128 :
case V_129 :
F_53 ( V_80 ) ;
break;
#ifdef F_99
case V_130 :
case V_131 :
F_100 ( & F_49 ( V_86 , V_80 ) ) ;
F_49 ( V_86 , V_80 ) . V_87 . V_88 = NULL ;
break;
case V_132 :
case V_133 :
F_53 ( V_80 ) ;
break;
case V_134 :
case V_135 :
#endif
case V_136 :
case V_137 :
F_97 ( & V_127 ) ;
F_90 ( V_80 ) ;
F_98 ( & V_127 ) ;
break;
}
return F_101 ( V_119 ) ;
}
static int T_8 F_102 ( int V_55 )
{
struct V_15 * V_16 ;
int V_138 = 0 ;
F_87 (cachep, &cache_chain, next) {
struct V_4 * V_47 ;
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( ! V_47 )
continue;
F_93 ( V_16 , V_47 , V_47 -> V_13 ) ;
if ( ! F_103 ( & V_47 -> V_6 ) ||
! F_103 ( & V_47 -> V_7 ) ) {
V_138 = - V_139 ;
break;
}
}
return V_138 ;
}
static int T_8 F_104 ( struct V_121 * V_140 ,
unsigned long V_123 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
int V_138 = 0 ;
int V_144 ;
V_144 = V_143 -> V_145 ;
if ( V_144 < 0 )
goto V_146;
switch ( V_123 ) {
case V_147 :
F_97 ( & V_127 ) ;
V_138 = F_86 ( V_144 ) ;
F_98 ( & V_127 ) ;
break;
case V_148 :
F_97 ( & V_127 ) ;
V_138 = F_102 ( V_144 ) ;
F_98 ( & V_127 ) ;
break;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
break;
}
V_146:
return F_101 ( V_138 ) ;
}
static void T_6 F_105 ( struct V_15 * V_16 , struct V_4 * V_153 ,
int V_105 )
{
struct V_4 * V_154 ;
V_154 = F_59 ( sizeof( struct V_4 ) , V_155 , V_105 ) ;
F_10 ( ! V_154 ) ;
memcpy ( V_154 , V_153 , sizeof( struct V_4 ) ) ;
F_6 ( & V_154 -> V_12 ) ;
F_106 ( V_16 , V_154 , V_105 ) ;
V_16 -> V_50 [ V_105 ] = V_154 ;
}
static void T_6 F_107 ( struct V_15 * V_16 , int V_156 )
{
int V_55 ;
F_79 (node) {
V_16 -> V_50 [ V_55 ] = & V_157 [ V_156 + V_55 ] ;
V_16 -> V_50 [ V_55 ] -> V_112 = V_113 +
V_114 +
( ( unsigned long ) V_16 ) % V_114 ;
}
}
void T_6 F_108 ( void )
{
T_2 V_68 ;
struct V_39 * V_158 ;
struct V_159 * V_160 ;
int V_3 ;
int V_161 ;
int V_55 ;
if ( F_109 () == 1 )
V_79 = 0 ;
for ( V_3 = 0 ; V_3 < V_162 ; V_3 ++ ) {
F_4 ( & V_157 [ V_3 ] ) ;
if ( V_3 < V_82 )
V_163 . V_50 [ V_3 ] = NULL ;
}
F_107 ( & V_163 , V_164 ) ;
if ( V_165 > ( 32 << 20 ) >> V_166 )
V_167 = V_168 ;
V_55 = F_82 () ;
F_5 ( & V_169 ) ;
F_110 ( & V_163 . V_27 , & V_169 ) ;
V_163 . V_170 = F_111 () ;
V_163 . V_56 [ F_33 () ] = & V_171 . V_25 ;
V_163 . V_50 [ V_55 ] = & V_157 [ V_164 + V_55 ] ;
V_163 . V_21 = F_112 ( struct V_15 , V_50 ) +
V_106 * sizeof( struct V_4 * ) ;
#if V_59
V_163 . F_8 = V_163 . V_21 ;
#endif
V_163 . V_21 = F_39 ( V_163 . V_21 ,
F_111 () ) ;
V_163 . V_35 =
F_113 ( V_163 . V_21 ) ;
for ( V_161 = 0 ; V_161 < V_172 ; V_161 ++ ) {
F_40 ( V_161 , V_163 . V_21 ,
F_111 () , 0 , & V_68 , & V_163 . V_69 ) ;
if ( V_163 . V_69 )
break;
}
F_10 ( ! V_163 . V_69 ) ;
V_163 . V_67 = V_161 ;
V_163 . V_173 = V_68 / V_163 . V_170 ;
V_163 . V_71 = F_39 ( V_163 . V_69 * sizeof( V_66 ) +
sizeof( struct V_29 ) , F_111 () ) ;
V_158 = V_41 ;
V_160 = V_159 ;
V_158 [ V_60 ] . V_49 = F_114 ( V_160 [ V_60 ] . V_78 ,
V_158 [ V_60 ] . V_43 ,
V_174 ,
V_175 | V_176 ,
NULL ) ;
if ( V_60 != V_177 ) {
V_158 [ V_177 ] . V_49 =
F_114 ( V_160 [ V_177 ] . V_78 ,
V_158 [ V_177 ] . V_43 ,
V_174 ,
V_175 | V_176 ,
NULL ) ;
}
V_178 = 0 ;
while ( V_158 -> V_43 != V_44 ) {
if ( ! V_158 -> V_49 ) {
V_158 -> V_49 = F_114 ( V_160 -> V_78 ,
V_158 -> V_43 ,
V_174 ,
V_175 | V_176 ,
NULL ) ;
}
#ifdef F_35
V_158 -> V_63 = F_114 (
V_160 -> V_179 ,
V_158 -> V_43 ,
V_174 ,
V_175 | V_180 |
V_176 ,
NULL ) ;
#endif
V_158 ++ ;
V_160 ++ ;
}
{
struct V_45 * V_154 ;
V_154 = F_115 ( sizeof( struct V_181 ) , V_155 ) ;
F_10 ( F_32 ( & V_163 ) != & V_171 . V_25 ) ;
memcpy ( V_154 , F_32 ( & V_163 ) ,
sizeof( struct V_181 ) ) ;
F_6 ( & V_154 -> V_53 ) ;
V_163 . V_56 [ F_33 () ] = V_154 ;
V_154 = F_115 ( sizeof( struct V_181 ) , V_155 ) ;
F_10 ( F_32 ( V_41 [ V_60 ] . V_49 )
!= & V_182 . V_25 ) ;
memcpy ( V_154 , F_32 ( V_41 [ V_60 ] . V_49 ) ,
sizeof( struct V_181 ) ) ;
F_6 ( & V_154 -> V_53 ) ;
V_41 [ V_60 ] . V_49 -> V_56 [ F_33 () ] =
V_154 ;
}
{
int V_144 ;
F_79 (nid) {
F_105 ( & V_163 , & V_157 [ V_164 + V_144 ] , V_144 ) ;
F_105 ( V_41 [ V_60 ] . V_49 ,
& V_157 [ V_183 + V_144 ] , V_144 ) ;
if ( V_60 != V_177 ) {
F_105 ( V_41 [ V_177 ] . V_49 ,
& V_157 [ V_184 + V_144 ] , V_144 ) ;
}
}
}
V_36 = V_37 ;
}
void T_6 F_116 ( void )
{
struct V_15 * V_16 ;
F_97 ( & V_127 ) ;
F_87 (cachep, &cache_chain, next)
if ( F_117 ( V_16 , V_155 ) )
F_118 () ;
F_98 ( & V_127 ) ;
V_36 = V_42 ;
F_31 () ;
F_119 ( & V_185 ) ;
#ifdef F_95
F_120 ( F_104 , V_186 ) ;
#endif
}
static int T_6 F_121 ( void )
{
int V_80 ;
F_122 (cpu)
F_53 ( V_80 ) ;
return 0 ;
}
static void * F_123 ( struct V_15 * V_16 , T_5 V_18 , int V_105 )
{
struct V_24 * V_24 ;
int V_187 ;
int V_3 ;
#ifndef F_124
V_18 |= V_188 ;
#endif
V_18 |= V_16 -> V_57 ;
if ( V_16 -> V_18 & V_189 )
V_18 |= V_190 ;
V_24 = F_125 ( V_105 , V_18 | V_191 , V_16 -> V_67 ) ;
if ( ! V_24 )
return NULL ;
V_187 = ( 1 << V_16 -> V_67 ) ;
if ( V_16 -> V_18 & V_189 )
F_126 ( F_127 ( V_24 ) ,
V_192 , V_187 ) ;
else
F_126 ( F_127 ( V_24 ) ,
V_193 , V_187 ) ;
for ( V_3 = 0 ; V_3 < V_187 ; V_3 ++ )
F_128 ( V_24 + V_3 ) ;
if ( V_194 && ! ( V_16 -> V_18 & V_195 ) ) {
F_129 ( V_24 , V_16 -> V_67 , V_18 , V_105 ) ;
if ( V_16 -> V_196 )
F_130 ( V_24 , V_187 ) ;
else
F_131 ( V_24 , V_187 ) ;
}
return F_132 ( V_24 ) ;
}
static void F_133 ( struct V_15 * V_16 , void * V_197 )
{
unsigned long V_3 = ( 1 << V_16 -> V_67 ) ;
struct V_24 * V_24 = F_134 ( V_197 ) ;
const unsigned long V_198 = V_3 ;
F_135 ( V_24 , V_16 -> V_67 ) ;
if ( V_16 -> V_18 & V_189 )
F_136 ( F_127 ( V_24 ) ,
V_192 , V_198 ) ;
else
F_136 ( F_127 ( V_24 ) ,
V_193 , V_198 ) ;
while ( V_3 -- ) {
F_10 ( ! F_17 ( V_24 ) ) ;
F_137 ( V_24 ) ;
V_24 ++ ;
}
if ( V_199 -> V_200 )
V_199 -> V_200 -> V_201 += V_198 ;
F_138 ( ( unsigned long ) V_197 , V_16 -> V_67 ) ;
}
static void F_139 ( struct V_202 * V_203 )
{
struct V_204 * V_204 = (struct V_204 * ) V_203 ;
struct V_15 * V_16 = V_204 -> V_16 ;
F_133 ( V_16 , V_204 -> V_197 ) ;
if ( F_28 ( V_16 ) )
F_140 ( V_16 -> V_205 , V_204 ) ;
}
static void F_141 ( struct V_15 * V_16 , unsigned long * V_197 ,
unsigned long V_206 )
{
int V_1 = F_8 ( V_16 ) ;
V_197 = ( unsigned long * ) & ( ( char * ) V_197 ) [ F_7 ( V_16 ) ] ;
if ( V_1 < 5 * sizeof( unsigned long ) )
return;
* V_197 ++ = 0x12345678 ;
* V_197 ++ = V_206 ;
* V_197 ++ = F_33 () ;
V_1 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_207 = & V_206 ;
unsigned long V_208 ;
while ( ! F_142 ( V_207 ) ) {
V_208 = * V_207 ++ ;
if ( F_143 ( V_208 ) ) {
* V_197 ++ = V_208 ;
V_1 -= sizeof( unsigned long ) ;
if ( V_1 <= sizeof( unsigned long ) )
break;
}
}
}
* V_197 ++ = 0x87654321 ;
}
static void F_144 ( struct V_15 * V_16 , void * V_197 , unsigned char V_209 )
{
int V_1 = F_8 ( V_16 ) ;
V_197 = & ( ( char * ) V_197 ) [ F_7 ( V_16 ) ] ;
memset ( V_197 , V_209 , V_1 ) ;
* ( unsigned char * ) ( V_197 + V_1 - 1 ) = V_210 ;
}
static void F_145 ( char * V_211 , int V_34 , int V_97 )
{
int V_3 ;
unsigned char error = 0 ;
int V_212 = 0 ;
F_42 ( V_77 L_2 , V_34 ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
if ( V_211 [ V_34 + V_3 ] != V_213 ) {
error = V_211 [ V_34 + V_3 ] ;
V_212 ++ ;
}
F_42 ( L_3 , ( unsigned char ) V_211 [ V_34 + V_3 ] ) ;
}
F_42 ( L_4 ) ;
if ( V_212 == 1 ) {
error ^= V_213 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_42 ( V_77 L_5
L_6 ) ;
#ifdef F_146
F_42 ( V_77 L_7
L_8 ) ;
#else
F_42 ( V_77 L_9 ) ;
#endif
}
}
}
static void F_147 ( struct V_15 * V_16 , void * V_17 , int V_214 )
{
int V_3 , V_1 ;
char * V_215 ;
if ( V_16 -> V_18 & V_19 ) {
F_42 ( V_77 L_10 ,
* F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
if ( V_16 -> V_18 & V_20 ) {
F_42 ( V_77 L_11 ,
* F_12 ( V_16 , V_17 ) ) ;
F_148 ( L_12 ,
( unsigned long ) * F_12 ( V_16 , V_17 ) ) ;
F_42 ( L_4 ) ;
}
V_215 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 && V_214 ; V_3 += 16 , V_214 -- ) {
int V_97 ;
V_97 = 16 ;
if ( V_3 + V_97 > V_1 )
V_97 = V_1 - V_3 ;
F_145 ( V_215 , V_3 , V_97 ) ;
}
}
static void F_149 ( struct V_15 * V_16 , void * V_17 )
{
char * V_215 ;
int V_1 , V_3 ;
int V_214 = 0 ;
V_215 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ ) {
char exp = V_213 ;
if ( V_3 == V_1 - 1 )
exp = V_210 ;
if ( V_215 [ V_3 ] != exp ) {
int V_97 ;
if ( V_214 == 0 ) {
F_42 ( V_77
L_13 ,
V_16 -> V_78 , V_215 , V_1 ) ;
F_147 ( V_16 , V_17 , 0 ) ;
}
V_3 = ( V_3 / 16 ) * 16 ;
V_97 = 16 ;
if ( V_3 + V_97 > V_1 )
V_97 = V_1 - V_3 ;
F_145 ( V_215 , V_3 , V_97 ) ;
V_3 += 16 ;
V_214 ++ ;
if ( V_214 > 5 )
break;
}
}
if ( V_214 != 0 ) {
struct V_29 * V_109 = F_22 ( V_17 ) ;
unsigned int V_216 ;
V_216 = F_24 ( V_16 , V_109 , V_17 ) ;
if ( V_216 ) {
V_17 = F_23 ( V_16 , V_109 , V_216 - 1 ) ;
V_215 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_42 ( V_77 L_14 ,
V_215 , V_1 ) ;
F_147 ( V_16 , V_17 , 2 ) ;
}
if ( V_216 + 1 < V_16 -> V_69 ) {
V_17 = F_23 ( V_16 , V_109 , V_216 + 1 ) ;
V_215 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_42 ( V_77 L_15 ,
V_215 , V_1 ) ;
F_147 ( V_16 , V_17 , 2 ) ;
}
}
}
static void F_150 ( struct V_15 * V_16 , struct V_29 * V_109 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_69 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_109 , V_3 ) ;
if ( V_16 -> V_18 & V_217 ) {
#ifdef F_151
if ( V_16 -> V_21 % V_72 == 0 &&
F_28 ( V_16 ) )
F_152 ( F_134 ( V_17 ) ,
V_16 -> V_21 / V_72 , 1 ) ;
else
F_149 ( V_16 , V_17 ) ;
#else
F_149 ( V_16 , V_17 ) ;
#endif
}
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_218 )
F_153 ( V_16 , L_16
L_17 ) ;
if ( * F_11 ( V_16 , V_17 ) != V_218 )
F_153 ( V_16 , L_18
L_17 ) ;
}
}
}
static void F_150 ( struct V_15 * V_16 , struct V_29 * V_109 )
{
}
static void F_154 ( struct V_15 * V_16 , struct V_29 * V_109 )
{
void * V_197 = V_109 -> V_33 - V_109 -> V_219 ;
F_150 ( V_16 , V_109 ) ;
if ( F_36 ( V_16 -> V_18 & V_220 ) ) {
struct V_204 * V_204 ;
V_204 = (struct V_204 * ) V_109 ;
V_204 -> V_16 = V_16 ;
V_204 -> V_197 = V_197 ;
F_155 ( & V_204 -> V_203 , F_139 ) ;
} else {
F_133 ( V_16 , V_197 ) ;
if ( F_28 ( V_16 ) )
F_140 ( V_16 -> V_205 , V_109 ) ;
}
}
static void F_156 ( struct V_15 * V_16 )
{
int V_3 ;
struct V_4 * V_47 ;
F_122 (i)
F_70 ( V_16 -> V_56 [ V_3 ] ) ;
F_79 (i) {
V_47 = V_16 -> V_50 [ V_3 ] ;
if ( V_47 ) {
F_70 ( V_47 -> V_9 ) ;
F_64 ( V_47 -> V_10 ) ;
F_70 ( V_47 ) ;
}
}
F_140 ( & V_163 , V_16 ) ;
}
static T_2 F_157 ( struct V_15 * V_16 ,
T_2 V_1 , T_2 V_65 , unsigned long V_18 )
{
unsigned long V_221 ;
T_2 V_68 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 <= V_222 ; V_67 ++ ) {
unsigned int V_69 ;
T_2 V_223 ;
F_40 ( V_67 , V_1 , V_65 , V_18 , & V_223 , & V_69 ) ;
if ( ! V_69 )
continue;
if ( V_18 & V_73 ) {
V_221 = V_1 - sizeof( struct V_29 ) ;
V_221 /= sizeof( V_66 ) ;
if ( V_69 > V_221 )
break;
}
V_16 -> V_69 = V_69 ;
V_16 -> V_67 = V_67 ;
V_68 = V_223 ;
if ( V_18 & V_189 )
break;
if ( V_67 >= V_167 )
break;
if ( V_68 * 8 <= ( V_72 << V_67 ) )
break;
}
return V_68 ;
}
static int T_9 F_158 ( struct V_15 * V_16 , T_5 V_93 )
{
if ( V_36 == V_42 )
return F_117 ( V_16 , V_93 ) ;
if ( V_36 == V_224 ) {
V_16 -> V_56 [ F_33 () ] = & V_182 . V_25 ;
F_107 ( V_16 , V_183 ) ;
if ( V_60 == V_177 )
V_36 = V_225 ;
else
V_36 = V_226 ;
} else {
V_16 -> V_56 [ F_33 () ] =
F_115 ( sizeof( struct V_181 ) , V_93 ) ;
if ( V_36 == V_226 ) {
F_107 ( V_16 , V_184 ) ;
V_36 = V_225 ;
} else {
int V_55 ;
F_79 (node) {
V_16 -> V_50 [ V_55 ] =
F_59 ( sizeof( struct V_4 ) ,
V_93 , V_55 ) ;
F_10 ( ! V_16 -> V_50 [ V_55 ] ) ;
F_4 ( V_16 -> V_50 [ V_55 ] ) ;
}
}
}
V_16 -> V_50 [ F_82 () ] -> V_112 =
V_113 + V_114 +
( ( unsigned long ) V_16 ) % V_114 ;
F_32 ( V_16 ) -> V_96 = 0 ;
F_32 ( V_16 ) -> V_97 = V_227 ;
F_32 ( V_16 ) -> V_92 = 1 ;
F_32 ( V_16 ) -> V_98 = 0 ;
V_16 -> V_92 = 1 ;
V_16 -> V_97 = V_227 ;
return 0 ;
}
struct V_15 *
F_114 ( const char * V_78 , T_2 V_1 , T_2 V_65 ,
unsigned long V_18 , void (* V_196)( void * ) )
{
T_2 V_68 , V_71 , V_228 ;
struct V_15 * V_16 = NULL , * V_229 ;
T_5 V_93 ;
if ( ! V_78 || F_159 () || ( V_1 < V_23 ) ||
V_1 > V_230 ) {
F_42 ( V_77 L_19 , V_231 ,
V_78 ) ;
F_118 () ;
}
if ( F_26 () ) {
F_160 () ;
F_97 ( & V_127 ) ;
}
F_87 (pc, &cache_chain, next) {
char V_232 ;
int V_233 ;
V_233 = F_161 ( V_229 -> V_78 , V_232 ) ;
if ( V_233 ) {
F_42 ( V_77
L_20 ,
V_229 -> V_21 ) ;
continue;
}
if ( ! strcmp ( V_229 -> V_78 , V_78 ) ) {
F_42 ( V_77
L_21 , V_78 ) ;
F_43 () ;
goto V_234;
}
}
#if V_59
F_162 ( strchr ( V_78 , ' ' ) ) ;
#if V_235
if ( V_1 < 4096 || F_163 ( V_1 - 1 ) == F_163 ( V_1 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_18 |= V_19 | V_20 ;
if ( ! ( V_18 & V_220 ) )
V_18 |= V_217 ;
#endif
if ( V_18 & V_220 )
F_10 ( V_18 & V_217 ) ;
#endif
F_10 ( V_18 & ~ V_236 ) ;
if ( V_1 & ( V_23 - 1 ) ) {
V_1 += ( V_23 - 1 ) ;
V_1 &= ~ ( V_23 - 1 ) ;
}
if ( V_18 & V_237 ) {
V_228 = F_111 () ;
while ( V_1 <= V_228 / 2 )
V_228 /= 2 ;
} else {
V_228 = V_23 ;
}
if ( V_18 & V_20 )
V_228 = V_23 ;
if ( V_18 & V_19 ) {
V_228 = V_22 ;
V_1 += V_22 - 1 ;
V_1 &= ~ ( V_22 - 1 ) ;
}
if ( V_228 < V_238 ) {
V_228 = V_238 ;
}
if ( V_228 < V_65 ) {
V_228 = V_65 ;
}
if ( V_228 > F_164 (unsigned long long) )
V_18 &= ~ ( V_19 | V_20 ) ;
V_65 = V_228 ;
if ( F_26 () )
V_93 = V_110 ;
else
V_93 = V_155 ;
V_16 = F_165 ( & V_163 , V_93 ) ;
if ( ! V_16 )
goto V_234;
#if V_59
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
#if V_235 && F_166 ( F_151 )
if ( V_1 >= V_41 [ V_177 + 1 ] . V_43
&& V_16 -> F_8 > F_111 () && F_39 ( V_1 , V_65 ) < V_72 ) {
V_16 -> F_7 += V_72 - F_39 ( V_1 , V_65 ) ;
V_1 = V_72 ;
}
#endif
#endif
if ( ( V_1 >= ( V_72 >> 3 ) ) && ! V_178 &&
! ( V_18 & V_239 ) )
V_18 |= V_73 ;
V_1 = F_39 ( V_1 , V_65 ) ;
V_68 = F_157 ( V_16 , V_1 , V_65 , V_18 ) ;
if ( ! V_16 -> V_69 ) {
F_42 ( V_77
L_22 , V_78 ) ;
F_140 ( & V_163 , V_16 ) ;
V_16 = NULL ;
goto V_234;
}
V_71 = F_39 ( V_16 -> V_69 * sizeof( V_66 )
+ sizeof( struct V_29 ) , V_65 ) ;
if ( V_18 & V_73 && V_68 >= V_71 ) {
V_18 &= ~ V_73 ;
V_68 -= V_71 ;
}
if ( V_18 & V_73 ) {
V_71 =
V_16 -> V_69 * sizeof( V_66 ) + sizeof( struct V_29 ) ;
#ifdef F_167
if ( V_1 % V_72 == 0 && V_18 & V_217 )
V_18 &= ~ ( V_19 | V_20 ) ;
#endif
}
V_16 -> V_170 = F_111 () ;
if ( V_16 -> V_170 < V_65 )
V_16 -> V_170 = V_65 ;
V_16 -> V_173 = V_68 / V_16 -> V_170 ;
V_16 -> V_71 = V_71 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_57 = 0 ;
if ( V_240 && ( V_18 & V_180 ) )
V_16 -> V_57 |= V_62 ;
V_16 -> V_21 = V_1 ;
V_16 -> V_35 = F_113 ( V_1 ) ;
if ( V_18 & V_73 ) {
V_16 -> V_205 = F_37 ( V_71 , 0u ) ;
F_10 ( F_168 ( V_16 -> V_205 ) ) ;
}
V_16 -> V_196 = V_196 ;
V_16 -> V_78 = V_78 ;
if ( F_158 ( V_16 , V_93 ) ) {
F_156 ( V_16 ) ;
V_16 = NULL ;
goto V_234;
}
F_110 ( & V_16 -> V_27 , & V_169 ) ;
V_234:
if ( ! V_16 && ( V_18 & V_176 ) )
F_169 ( L_23 ,
V_78 ) ;
if ( F_26 () ) {
F_98 ( & V_127 ) ;
F_170 () ;
}
return V_16 ;
}
static void F_171 ( void )
{
F_10 ( ! F_172 () ) ;
}
static void F_173 ( void )
{
F_10 ( F_172 () ) ;
}
static void F_174 ( struct V_15 * V_16 )
{
#ifdef F_175
F_171 () ;
F_176 ( & V_16 -> V_50 [ F_82 () ] -> V_12 ) ;
#endif
}
static void F_177 ( struct V_15 * V_16 , int V_55 )
{
#ifdef F_175
F_171 () ;
F_176 ( & V_16 -> V_50 [ V_55 ] -> V_12 ) ;
#endif
}
static void F_178 ( void * V_141 )
{
struct V_15 * V_16 = V_141 ;
struct V_45 * V_107 ;
int V_55 = F_82 () ;
F_171 () ;
V_107 = F_32 ( V_16 ) ;
F_72 ( & V_16 -> V_50 [ V_55 ] -> V_12 ) ;
F_73 ( V_16 , V_107 -> V_103 , V_107 -> V_96 , V_55 ) ;
F_74 ( & V_16 -> V_50 [ V_55 ] -> V_12 ) ;
V_107 -> V_96 = 0 ;
}
static void F_179 ( struct V_15 * V_16 )
{
struct V_4 * V_47 ;
int V_55 ;
F_180 ( F_178 , V_16 , 1 ) ;
F_173 () ;
F_79 (node) {
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( V_47 && V_47 -> V_10 )
F_78 ( V_16 , V_47 -> V_10 ) ;
}
F_79 (node) {
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( V_47 )
F_181 ( V_16 , V_47 , V_47 -> V_9 , 1 , V_55 ) ;
}
}
static int F_93 ( struct V_15 * V_25 ,
struct V_4 * V_47 , int V_241 )
{
struct V_28 * V_242 ;
int V_198 ;
struct V_29 * V_109 ;
V_198 = 0 ;
while ( V_198 < V_241 && ! F_103 ( & V_47 -> V_8 ) ) {
F_88 ( & V_47 -> V_12 ) ;
V_242 = V_47 -> V_8 . V_30 ;
if ( V_242 == & V_47 -> V_8 ) {
F_77 ( & V_47 -> V_12 ) ;
goto V_146;
}
V_109 = F_182 ( V_242 , struct V_29 , V_153 ) ;
#if V_59
F_10 ( V_109 -> V_243 ) ;
#endif
F_183 ( & V_109 -> V_153 ) ;
V_47 -> V_13 -= V_25 -> V_69 ;
F_77 ( & V_47 -> V_12 ) ;
F_154 ( V_25 , V_109 ) ;
V_198 ++ ;
}
V_146:
return V_198 ;
}
static int F_184 ( struct V_15 * V_16 )
{
int V_138 = 0 , V_3 = 0 ;
struct V_4 * V_47 ;
F_179 ( V_16 ) ;
F_173 () ;
F_79 (i) {
V_47 = V_16 -> V_50 [ V_3 ] ;
if ( ! V_47 )
continue;
F_93 ( V_16 , V_47 , V_47 -> V_13 ) ;
V_138 += ! F_103 ( & V_47 -> V_6 ) ||
! F_103 ( & V_47 -> V_7 ) ;
}
return ( V_138 ? 1 : 0 ) ;
}
int F_185 ( struct V_15 * V_16 )
{
int V_138 ;
F_10 ( ! V_16 || F_159 () ) ;
F_160 () ;
F_97 ( & V_127 ) ;
V_138 = F_184 ( V_16 ) ;
F_98 ( & V_127 ) ;
F_170 () ;
return V_138 ;
}
void F_186 ( struct V_15 * V_16 )
{
F_10 ( ! V_16 || F_159 () ) ;
F_160 () ;
F_97 ( & V_127 ) ;
F_183 ( & V_16 -> V_27 ) ;
if ( F_184 ( V_16 ) ) {
F_153 ( V_16 , L_24 ) ;
F_110 ( & V_16 -> V_27 , & V_169 ) ;
F_98 ( & V_127 ) ;
F_170 () ;
return;
}
if ( F_36 ( V_16 -> V_18 & V_220 ) )
F_187 () ;
F_156 ( V_16 ) ;
F_98 ( & V_127 ) ;
F_170 () ;
}
static struct V_29 * F_188 ( struct V_15 * V_16 , void * V_17 ,
int V_170 , T_5 V_244 ,
int V_105 )
{
struct V_29 * V_109 ;
if ( F_28 ( V_16 ) ) {
V_109 = F_189 ( V_16 -> V_205 ,
V_244 , V_105 ) ;
F_190 ( & V_109 -> V_153 , sizeof( struct V_28 ) ,
V_244 ) ;
if ( ! V_109 )
return NULL ;
} else {
V_109 = V_17 + V_170 ;
V_170 += V_16 -> V_71 ;
}
V_109 -> V_243 = 0 ;
V_109 -> V_219 = V_170 ;
V_109 -> V_33 = V_17 + V_170 ;
V_109 -> V_105 = V_105 ;
V_109 -> free = 0 ;
return V_109 ;
}
static inline V_66 * F_191 ( struct V_29 * V_109 )
{
return ( V_66 * ) ( V_109 + 1 ) ;
}
static void F_192 ( struct V_15 * V_16 ,
struct V_29 * V_109 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_69 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_109 , V_3 ) ;
#if V_59
if ( V_16 -> V_18 & V_217 )
F_144 ( V_16 , V_17 , V_213 ) ;
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = NULL ;
if ( V_16 -> V_18 & V_19 ) {
* F_9 ( V_16 , V_17 ) = V_218 ;
* F_11 ( V_16 , V_17 ) = V_218 ;
}
if ( V_16 -> V_196 && ! ( V_16 -> V_18 & V_217 ) )
V_16 -> V_196 ( V_17 + F_7 ( V_16 ) ) ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_11 ( V_16 , V_17 ) != V_218 )
F_153 ( V_16 , L_25
L_26 ) ;
if ( * F_9 ( V_16 , V_17 ) != V_218 )
F_153 ( V_16 , L_25
L_27 ) ;
}
if ( ( V_16 -> V_21 % V_72 ) == 0 &&
F_28 ( V_16 ) && V_16 -> V_18 & V_217 )
F_152 ( F_134 ( V_17 ) ,
V_16 -> V_21 / V_72 , 0 ) ;
#else
if ( V_16 -> V_196 )
V_16 -> V_196 ( V_17 ) ;
#endif
F_191 ( V_109 ) [ V_3 ] = V_3 + 1 ;
}
F_191 ( V_109 ) [ V_3 - 1 ] = V_245 ;
}
static void F_193 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_240 ) {
if ( V_18 & V_62 )
F_10 ( ! ( V_16 -> V_57 & V_62 ) ) ;
else
F_10 ( V_16 -> V_57 & V_62 ) ;
}
}
static void * F_194 ( struct V_15 * V_16 , struct V_29 * V_109 ,
int V_105 )
{
void * V_17 = F_23 ( V_16 , V_109 , V_109 -> free ) ;
V_66 V_27 ;
V_109 -> V_243 ++ ;
V_27 = F_191 ( V_109 ) [ V_109 -> free ] ;
#if V_59
F_191 ( V_109 ) [ V_109 -> free ] = V_246 ;
F_162 ( V_109 -> V_105 != V_105 ) ;
#endif
V_109 -> free = V_27 ;
return V_17 ;
}
static void F_195 ( struct V_15 * V_16 , struct V_29 * V_109 ,
void * V_17 , int V_105 )
{
unsigned int V_216 = F_24 ( V_16 , V_109 , V_17 ) ;
#if V_59
F_162 ( V_109 -> V_105 != V_105 ) ;
if ( F_191 ( V_109 ) [ V_216 ] + 1 <= V_74 + 1 ) {
F_42 ( V_77 L_28
L_29 , V_16 -> V_78 , V_17 ) ;
F_118 () ;
}
#endif
F_191 ( V_109 ) [ V_216 ] = V_109 -> free ;
V_109 -> free = V_216 ;
V_109 -> V_243 -- ;
}
static void F_196 ( struct V_15 * V_25 , struct V_29 * V_29 ,
void * V_197 )
{
int V_187 ;
struct V_24 * V_24 ;
V_24 = F_134 ( V_197 ) ;
V_187 = 1 ;
if ( F_83 ( ! F_197 ( V_24 ) ) )
V_187 <<= V_25 -> V_67 ;
do {
F_14 ( V_24 , V_25 ) ;
F_18 ( V_24 , V_29 ) ;
V_24 ++ ;
} while ( -- V_187 );
}
static int F_198 ( struct V_15 * V_16 ,
T_5 V_18 , int V_105 , void * V_17 )
{
struct V_29 * V_109 ;
T_2 V_34 ;
T_5 V_244 ;
struct V_4 * V_47 ;
F_10 ( V_18 & V_247 ) ;
V_244 = V_18 & ( V_248 | V_249 ) ;
F_171 () ;
V_47 = V_16 -> V_50 [ V_105 ] ;
F_72 ( & V_47 -> V_12 ) ;
V_34 = V_47 -> V_11 ;
V_47 -> V_11 ++ ;
if ( V_47 -> V_11 >= V_16 -> V_173 )
V_47 -> V_11 = 0 ;
F_74 ( & V_47 -> V_12 ) ;
V_34 *= V_16 -> V_170 ;
if ( V_244 & V_250 )
F_199 () ;
F_193 ( V_16 , V_18 ) ;
if ( ! V_17 )
V_17 = F_123 ( V_16 , V_244 , V_105 ) ;
if ( ! V_17 )
goto V_251;
V_109 = F_188 ( V_16 , V_17 , V_34 ,
V_244 & ~ V_248 , V_105 ) ;
if ( ! V_109 )
goto V_252;
F_196 ( V_16 , V_109 , V_17 ) ;
F_192 ( V_16 , V_109 ) ;
if ( V_244 & V_250 )
F_200 () ;
F_171 () ;
F_72 ( & V_47 -> V_12 ) ;
F_201 ( & V_109 -> V_153 , & ( V_47 -> V_8 ) ) ;
F_202 ( V_16 ) ;
V_47 -> V_13 += V_16 -> V_69 ;
F_74 ( & V_47 -> V_12 ) ;
return 1 ;
V_252:
F_133 ( V_16 , V_17 ) ;
V_251:
if ( V_244 & V_250 )
F_200 () ;
return 0 ;
}
static void F_203 ( const void * V_17 )
{
if ( ! F_204 ( V_17 ) ) {
F_42 ( V_77 L_30 ,
( unsigned long ) V_17 ) ;
F_118 () ;
}
}
static inline void F_205 ( struct V_15 * V_25 , void * V_31 )
{
unsigned long long V_253 , V_254 ;
V_253 = * F_9 ( V_25 , V_31 ) ;
V_254 = * F_11 ( V_25 , V_31 ) ;
if ( V_253 == V_255 && V_254 == V_255 )
return;
if ( V_253 == V_218 && V_254 == V_218 )
F_153 ( V_25 , L_31 ) ;
else
F_153 ( V_25 , L_32 ) ;
F_42 ( V_77 L_33 ,
V_31 , V_253 , V_254 ) ;
}
static void * F_206 ( struct V_15 * V_16 , void * V_17 ,
void * V_206 )
{
struct V_24 * V_24 ;
unsigned int V_216 ;
struct V_29 * V_109 ;
F_10 ( F_20 ( V_17 ) != V_16 ) ;
V_17 -= F_7 ( V_16 ) ;
F_203 ( V_17 ) ;
V_24 = F_21 ( V_17 ) ;
V_109 = F_19 ( V_24 ) ;
if ( V_16 -> V_18 & V_19 ) {
F_205 ( V_16 , V_17 ) ;
* F_9 ( V_16 , V_17 ) = V_218 ;
* F_11 ( V_16 , V_17 ) = V_218 ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_206 ;
V_216 = F_24 ( V_16 , V_109 , V_17 ) ;
F_10 ( V_216 >= V_16 -> V_69 ) ;
F_10 ( V_17 != F_23 ( V_16 , V_109 , V_216 ) ) ;
#ifdef F_207
F_191 ( V_109 ) [ V_216 ] = V_246 ;
#endif
if ( V_16 -> V_18 & V_217 ) {
#ifdef F_151
if ( ( V_16 -> V_21 % V_72 ) == 0 && F_28 ( V_16 ) ) {
F_141 ( V_16 , V_17 , ( unsigned long ) V_206 ) ;
F_152 ( F_134 ( V_17 ) ,
V_16 -> V_21 / V_72 , 0 ) ;
} else {
F_144 ( V_16 , V_17 , V_213 ) ;
}
#else
F_144 ( V_16 , V_17 , V_213 ) ;
#endif
}
return V_17 ;
}
static void F_208 ( struct V_15 * V_16 , struct V_29 * V_109 )
{
V_66 V_3 ;
int V_91 = 0 ;
for ( V_3 = V_109 -> free ; V_3 != V_245 ; V_3 = F_191 ( V_109 ) [ V_3 ] ) {
V_91 ++ ;
if ( V_91 > V_16 -> V_69 || V_3 >= V_16 -> V_69 )
goto V_120;
}
if ( V_91 != V_16 -> V_69 - V_109 -> V_243 ) {
V_120:
F_42 ( V_77 L_34
L_35 ,
V_16 -> V_78 , V_16 -> V_69 , V_109 , V_109 -> V_243 ) ;
for ( V_3 = 0 ;
V_3 < sizeof( * V_109 ) + V_16 -> V_69 * sizeof( V_66 ) ;
V_3 ++ ) {
if ( V_3 % 16 == 0 )
F_42 ( L_36 , V_3 ) ;
F_42 ( L_3 , ( ( unsigned char * ) V_109 ) [ V_3 ] ) ;
}
F_42 ( L_4 ) ;
F_118 () ;
}
}
static void * F_209 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_92 ;
struct V_4 * V_47 ;
struct V_45 * V_107 ;
int V_55 ;
V_256:
F_171 () ;
V_55 = F_82 () ;
V_107 = F_32 ( V_16 ) ;
V_92 = V_107 -> V_92 ;
if ( ! V_107 -> V_98 && V_92 > V_257 ) {
V_92 = V_257 ;
}
V_47 = V_16 -> V_50 [ V_55 ] ;
F_10 ( V_107 -> V_96 > 0 || ! V_47 ) ;
F_72 ( & V_47 -> V_12 ) ;
if ( V_47 -> V_9 && F_61 ( V_107 , V_47 -> V_9 , V_92 ) ) {
V_47 -> V_9 -> V_98 = 1 ;
goto V_258;
}
while ( V_92 > 0 ) {
struct V_28 * V_103 ;
struct V_29 * V_109 ;
V_103 = V_47 -> V_7 . V_27 ;
if ( V_103 == & V_47 -> V_7 ) {
V_47 -> V_14 = 1 ;
V_103 = V_47 -> V_8 . V_27 ;
if ( V_103 == & V_47 -> V_8 )
goto V_259;
}
V_109 = F_182 ( V_103 , struct V_29 , V_153 ) ;
F_208 ( V_16 , V_109 ) ;
F_174 ( V_16 ) ;
F_10 ( V_109 -> V_243 >= V_16 -> V_69 ) ;
while ( V_109 -> V_243 < V_16 -> V_69 && V_92 -- ) {
F_210 ( V_16 ) ;
F_211 ( V_16 ) ;
F_212 ( V_16 ) ;
V_107 -> V_103 [ V_107 -> V_96 ++ ] = F_194 ( V_16 , V_109 ,
V_55 ) ;
}
F_208 ( V_16 , V_109 ) ;
F_183 ( & V_109 -> V_153 ) ;
if ( V_109 -> free == V_245 )
F_110 ( & V_109 -> V_153 , & V_47 -> V_6 ) ;
else
F_110 ( & V_109 -> V_153 , & V_47 -> V_7 ) ;
}
V_259:
V_47 -> V_13 -= V_107 -> V_96 ;
V_258:
F_74 ( & V_47 -> V_12 ) ;
if ( F_36 ( ! V_107 -> V_96 ) ) {
int T_3 ;
T_3 = F_198 ( V_16 , V_18 | V_260 , V_55 , NULL ) ;
V_107 = F_32 ( V_16 ) ;
if ( ! T_3 && V_107 -> V_96 == 0 )
return NULL ;
if ( ! V_107 -> V_96 )
goto V_256;
}
V_107 -> V_98 = 1 ;
return V_107 -> V_103 [ -- V_107 -> V_96 ] ;
}
static inline void F_213 ( struct V_15 * V_16 ,
T_5 V_18 )
{
F_214 ( V_18 & V_250 ) ;
#if V_59
F_193 ( V_16 , V_18 ) ;
#endif
}
static void * F_215 ( struct V_15 * V_16 ,
T_5 V_18 , void * V_17 , void * V_206 )
{
if ( ! V_17 )
return V_17 ;
if ( V_16 -> V_18 & V_217 ) {
#ifdef F_151
if ( ( V_16 -> V_21 % V_72 ) == 0 && F_28 ( V_16 ) )
F_152 ( F_134 ( V_17 ) ,
V_16 -> V_21 / V_72 , 1 ) ;
else
F_149 ( V_16 , V_17 ) ;
#else
F_149 ( V_16 , V_17 ) ;
#endif
F_144 ( V_16 , V_17 , V_261 ) ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_206 ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_218 ||
* F_11 ( V_16 , V_17 ) != V_218 ) {
F_153 ( V_16 , L_37
L_38 ) ;
F_42 ( V_77
L_39 ,
V_17 , * F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
* F_9 ( V_16 , V_17 ) = V_255 ;
* F_11 ( V_16 , V_17 ) = V_255 ;
}
#ifdef F_207
{
struct V_29 * V_109 ;
unsigned V_216 ;
V_109 = F_19 ( F_21 ( V_17 ) ) ;
V_216 = ( unsigned ) ( V_17 - V_109 -> V_33 ) / V_16 -> V_21 ;
F_191 ( V_109 ) [ V_216 ] = V_262 ;
}
#endif
V_17 += F_7 ( V_16 ) ;
if ( V_16 -> V_196 && V_16 -> V_18 & V_217 )
V_16 -> V_196 ( V_17 ) ;
#if V_238
if ( ( T_4 ) V_17 & ( V_238 - 1 ) ) {
F_42 ( V_77 L_40 ,
V_17 , V_238 ) ;
}
#endif
return V_17 ;
}
static bool F_216 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_16 == & V_163 )
return false ;
return F_217 ( F_8 ( V_16 ) , V_18 , V_16 -> V_18 ) ;
}
static inline void * F_218 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_17 ;
struct V_45 * V_107 ;
F_171 () ;
V_107 = F_32 ( V_16 ) ;
if ( F_83 ( V_107 -> V_96 ) ) {
F_219 ( V_16 ) ;
V_107 -> V_98 = 1 ;
V_17 = V_107 -> V_103 [ -- V_107 -> V_96 ] ;
} else {
F_220 ( V_16 ) ;
V_17 = F_209 ( V_16 , V_18 ) ;
V_107 = F_32 ( V_16 ) ;
}
if ( V_17 )
F_221 ( & V_107 -> V_103 [ V_107 -> V_96 ] ) ;
return V_17 ;
}
static void * F_66 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_263 , V_264 ;
if ( F_159 () || ( V_18 & V_265 ) )
return NULL ;
V_263 = V_264 = F_82 () ;
F_222 () ;
if ( F_223 () && ( V_16 -> V_18 & V_266 ) )
V_263 = F_224 () ;
else if ( V_199 -> V_267 )
V_263 = F_225 ( V_199 -> V_267 ) ;
F_226 () ;
if ( V_263 != V_264 )
return F_67 ( V_16 , V_18 , V_263 ) ;
return NULL ;
}
static void * F_227 ( struct V_15 * V_25 , T_5 V_18 )
{
struct V_268 * V_268 ;
T_5 V_244 ;
struct V_269 * V_270 ;
struct V_271 * V_271 ;
enum V_272 V_273 = F_228 ( V_18 ) ;
void * V_31 = NULL ;
int V_144 ;
if ( V_18 & V_265 )
return NULL ;
F_222 () ;
V_268 = F_229 ( F_225 ( V_199 -> V_267 ) , V_18 ) ;
V_244 = V_18 & ( V_248 | V_249 ) ;
V_256:
F_230 (zone, z, zonelist, high_zoneidx) {
V_144 = F_231 ( V_271 ) ;
if ( F_232 ( V_271 , V_18 ) &&
V_25 -> V_50 [ V_144 ] &&
V_25 -> V_50 [ V_144 ] -> V_13 ) {
V_31 = F_67 ( V_25 ,
V_18 | V_260 , V_144 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
if ( V_244 & V_250 )
F_199 () ;
F_193 ( V_25 , V_18 ) ;
V_31 = F_123 ( V_25 , V_244 , F_82 () ) ;
if ( V_244 & V_250 )
F_200 () ;
if ( V_31 ) {
V_144 = F_233 ( F_134 ( V_31 ) ) ;
if ( F_198 ( V_25 , V_18 , V_144 , V_31 ) ) {
V_31 = F_67 ( V_25 ,
V_18 | V_260 , V_144 ) ;
if ( ! V_31 )
goto V_256;
} else {
V_31 = NULL ;
}
}
}
F_226 () ;
return V_31 ;
}
static void * F_67 ( struct V_15 * V_16 , T_5 V_18 ,
int V_105 )
{
struct V_28 * V_103 ;
struct V_29 * V_109 ;
struct V_4 * V_47 ;
void * V_31 ;
int T_3 ;
V_47 = V_16 -> V_50 [ V_105 ] ;
F_10 ( ! V_47 ) ;
V_256:
F_171 () ;
F_72 ( & V_47 -> V_12 ) ;
V_103 = V_47 -> V_7 . V_27 ;
if ( V_103 == & V_47 -> V_7 ) {
V_47 -> V_14 = 1 ;
V_103 = V_47 -> V_8 . V_27 ;
if ( V_103 == & V_47 -> V_8 )
goto V_259;
}
V_109 = F_182 ( V_103 , struct V_29 , V_153 ) ;
F_177 ( V_16 , V_105 ) ;
F_208 ( V_16 , V_109 ) ;
F_234 ( V_16 ) ;
F_211 ( V_16 ) ;
F_212 ( V_16 ) ;
F_10 ( V_109 -> V_243 == V_16 -> V_69 ) ;
V_31 = F_194 ( V_16 , V_109 , V_105 ) ;
F_208 ( V_16 , V_109 ) ;
V_47 -> V_13 -- ;
F_183 ( & V_109 -> V_153 ) ;
if ( V_109 -> free == V_245 )
F_110 ( & V_109 -> V_153 , & V_47 -> V_6 ) ;
else
F_110 ( & V_109 -> V_153 , & V_47 -> V_7 ) ;
F_74 ( & V_47 -> V_12 ) ;
goto V_274;
V_259:
F_74 ( & V_47 -> V_12 ) ;
T_3 = F_198 ( V_16 , V_18 | V_260 , V_105 , NULL ) ;
if ( T_3 )
goto V_256;
return F_227 ( V_16 , V_18 ) ;
V_274:
return V_31 ;
}
static T_1 void *
F_235 ( struct V_15 * V_16 , T_5 V_18 , int V_105 ,
void * V_206 )
{
unsigned long V_275 ;
void * V_154 ;
int F_225 = F_82 () ;
V_18 &= V_276 ;
F_236 ( V_18 ) ;
if ( F_216 ( V_16 , V_18 ) )
return NULL ;
F_213 ( V_16 , V_18 ) ;
F_237 ( V_275 ) ;
if ( V_105 == - 1 )
V_105 = F_225 ;
if ( F_36 ( ! V_16 -> V_50 [ V_105 ] ) ) {
V_154 = F_227 ( V_16 , V_18 ) ;
goto V_146;
}
if ( V_105 == F_225 ) {
V_154 = F_218 ( V_16 , V_18 ) ;
if ( V_154 )
goto V_146;
}
V_154 = F_67 ( V_16 , V_18 , V_105 ) ;
V_146:
F_238 ( V_275 ) ;
V_154 = F_215 ( V_16 , V_18 , V_154 , V_206 ) ;
F_239 ( V_154 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
if ( F_83 ( V_154 ) )
F_240 ( V_16 , V_18 , V_154 , F_8 ( V_16 ) ) ;
if ( F_36 ( ( V_18 & V_277 ) && V_154 ) )
memset ( V_154 , 0 , F_8 ( V_16 ) ) ;
return V_154 ;
}
static T_1 void *
F_241 ( struct V_15 * V_25 , T_5 V_18 )
{
void * V_17 ;
if ( F_36 ( V_199 -> V_18 & ( V_278 | V_279 ) ) ) {
V_17 = F_66 ( V_25 , V_18 ) ;
if ( V_17 )
goto V_146;
}
V_17 = F_218 ( V_25 , V_18 ) ;
if ( ! V_17 )
V_17 = F_67 ( V_25 , V_18 , F_82 () ) ;
V_146:
return V_17 ;
}
static T_1 void *
F_241 ( struct V_15 * V_16 , T_5 V_18 )
{
return F_218 ( V_16 , V_18 ) ;
}
static T_1 void *
F_242 ( struct V_15 * V_16 , T_5 V_18 , void * V_206 )
{
unsigned long V_275 ;
void * V_17 ;
V_18 &= V_276 ;
F_236 ( V_18 ) ;
if ( F_216 ( V_16 , V_18 ) )
return NULL ;
F_213 ( V_16 , V_18 ) ;
F_237 ( V_275 ) ;
V_17 = F_241 ( V_16 , V_18 ) ;
F_238 ( V_275 ) ;
V_17 = F_215 ( V_16 , V_18 , V_17 , V_206 ) ;
F_239 ( V_17 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
F_243 ( V_17 ) ;
if ( F_83 ( V_17 ) )
F_240 ( V_16 , V_18 , V_17 , F_8 ( V_16 ) ) ;
if ( F_36 ( ( V_18 & V_277 ) && V_17 ) )
memset ( V_17 , 0 , F_8 ( V_16 ) ) ;
return V_17 ;
}
static void F_73 ( struct V_15 * V_16 , void * * V_280 , int V_281 ,
int V_55 )
{
int V_3 ;
struct V_4 * V_47 ;
for ( V_3 = 0 ; V_3 < V_281 ; V_3 ++ ) {
void * V_17 = V_280 [ V_3 ] ;
struct V_29 * V_109 ;
V_109 = F_22 ( V_17 ) ;
V_47 = V_16 -> V_50 [ V_55 ] ;
F_183 ( & V_109 -> V_153 ) ;
F_177 ( V_16 , V_55 ) ;
F_208 ( V_16 , V_109 ) ;
F_195 ( V_16 , V_109 , V_17 , V_55 ) ;
F_244 ( V_16 ) ;
V_47 -> V_13 ++ ;
F_208 ( V_16 , V_109 ) ;
if ( V_109 -> V_243 == 0 ) {
if ( V_47 -> V_13 > V_47 -> V_115 ) {
V_47 -> V_13 -= V_16 -> V_69 ;
F_154 ( V_16 , V_109 ) ;
} else {
F_110 ( & V_109 -> V_153 , & V_47 -> V_8 ) ;
}
} else {
F_201 ( & V_109 -> V_153 , & V_47 -> V_7 ) ;
}
}
}
static void F_245 ( struct V_15 * V_16 , struct V_45 * V_107 )
{
int V_92 ;
struct V_4 * V_47 ;
int V_55 = F_82 () ;
V_92 = V_107 -> V_92 ;
#if V_59
F_10 ( ! V_92 || V_92 > V_107 -> V_96 ) ;
#endif
F_171 () ;
V_47 = V_16 -> V_50 [ V_55 ] ;
F_72 ( & V_47 -> V_12 ) ;
if ( V_47 -> V_9 ) {
struct V_45 * V_282 = V_47 -> V_9 ;
int V_101 = V_282 -> V_97 - V_282 -> V_96 ;
if ( V_101 ) {
if ( V_92 > V_101 )
V_92 = V_101 ;
memcpy ( & ( V_282 -> V_103 [ V_282 -> V_96 ] ) ,
V_107 -> V_103 , sizeof( void * ) * V_92 ) ;
V_282 -> V_96 += V_92 ;
goto V_283;
}
}
F_73 ( V_16 , V_107 -> V_103 , V_92 , V_55 ) ;
V_283:
#if V_284
{
int V_3 = 0 ;
struct V_28 * V_242 ;
V_242 = V_47 -> V_8 . V_27 ;
while ( V_242 != & ( V_47 -> V_8 ) ) {
struct V_29 * V_109 ;
V_109 = F_182 ( V_242 , struct V_29 , V_153 ) ;
F_10 ( V_109 -> V_243 ) ;
V_3 ++ ;
V_242 = V_242 -> V_27 ;
}
F_246 ( V_16 , V_3 ) ;
}
#endif
F_74 ( & V_47 -> V_12 ) ;
V_107 -> V_96 -= V_92 ;
memmove ( V_107 -> V_103 , & ( V_107 -> V_103 [ V_92 ] ) , sizeof( void * ) * V_107 -> V_96 ) ;
}
static inline void F_247 ( struct V_15 * V_16 , void * V_17 ,
void * V_206 )
{
struct V_45 * V_107 = F_32 ( V_16 ) ;
F_171 () ;
F_248 ( V_17 , V_16 -> V_18 ) ;
V_17 = F_206 ( V_16 , V_17 , V_206 ) ;
F_249 ( V_16 , V_17 , F_8 ( V_16 ) ) ;
if ( V_285 > 1 && F_65 ( V_16 , V_17 ) )
return;
if ( F_83 ( V_107 -> V_96 < V_107 -> V_97 ) ) {
F_250 ( V_16 ) ;
V_107 -> V_103 [ V_107 -> V_96 ++ ] = V_17 ;
return;
} else {
F_251 ( V_16 ) ;
F_245 ( V_16 , V_107 ) ;
V_107 -> V_103 [ V_107 -> V_96 ++ ] = V_17 ;
}
}
void * F_252 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_138 = F_242 ( V_16 , V_18 , F_253 ( 0 ) ) ;
F_254 ( V_286 , V_138 ,
F_8 ( V_16 ) , V_16 -> V_21 , V_18 ) ;
return V_138 ;
}
void *
F_255 ( T_2 V_1 , struct V_15 * V_16 , T_5 V_18 )
{
void * V_138 ;
V_138 = F_242 ( V_16 , V_18 , F_253 ( 0 ) ) ;
F_256 ( V_286 , V_138 ,
V_1 , F_13 ( V_16 ) , V_18 ) ;
return V_138 ;
}
void * F_189 ( struct V_15 * V_16 , T_5 V_18 , int V_105 )
{
void * V_138 = F_235 ( V_16 , V_18 , V_105 ,
F_253 ( 0 ) ) ;
F_257 ( V_286 , V_138 ,
F_8 ( V_16 ) , V_16 -> V_21 ,
V_18 , V_105 ) ;
return V_138 ;
}
void * F_258 ( T_2 V_1 ,
struct V_15 * V_16 ,
T_5 V_18 ,
int V_105 )
{
void * V_138 ;
V_138 = F_235 ( V_16 , V_18 , V_105 ,
F_253 ( 0 ) ) ;
F_259 ( V_286 , V_138 ,
V_1 , F_13 ( V_16 ) ,
V_18 , V_105 ) ;
return V_138 ;
}
static T_1 void *
F_260 ( T_2 V_1 , T_5 V_18 , int V_55 , void * V_206 )
{
struct V_15 * V_16 ;
V_16 = F_37 ( V_1 , V_18 ) ;
if ( F_36 ( F_168 ( V_16 ) ) )
return V_16 ;
return F_258 ( V_1 , V_16 , V_18 , V_55 ) ;
}
void * F_261 ( T_2 V_1 , T_5 V_18 , int V_55 )
{
return F_260 ( V_1 , V_18 , V_55 ,
F_253 ( 0 ) ) ;
}
void * F_262 ( T_2 V_1 , T_5 V_18 ,
int V_55 , unsigned long V_206 )
{
return F_260 ( V_1 , V_18 , V_55 , ( void * ) V_206 ) ;
}
void * F_261 ( T_2 V_1 , T_5 V_18 , int V_55 )
{
return F_260 ( V_1 , V_18 , V_55 , NULL ) ;
}
static T_1 void * F_263 ( T_2 V_1 , T_5 V_18 ,
void * V_206 )
{
struct V_15 * V_16 ;
void * V_138 ;
V_16 = F_34 ( V_1 , V_18 ) ;
if ( F_36 ( F_168 ( V_16 ) ) )
return V_16 ;
V_138 = F_242 ( V_16 , V_18 , V_206 ) ;
F_256 ( ( unsigned long ) V_206 , V_138 ,
V_1 , V_16 -> V_21 , V_18 ) ;
return V_138 ;
}
void * F_264 ( T_2 V_1 , T_5 V_18 )
{
return F_263 ( V_1 , V_18 , F_253 ( 0 ) ) ;
}
void * F_265 ( T_2 V_1 , T_5 V_18 , unsigned long V_206 )
{
return F_263 ( V_1 , V_18 , ( void * ) V_206 ) ;
}
void * F_264 ( T_2 V_1 , T_5 V_18 )
{
return F_263 ( V_1 , V_18 , NULL ) ;
}
void F_140 ( struct V_15 * V_16 , void * V_17 )
{
unsigned long V_18 ;
F_237 ( V_18 ) ;
F_266 ( V_17 , F_8 ( V_16 ) ) ;
if ( ! ( V_16 -> V_18 & V_287 ) )
F_267 ( V_17 , F_8 ( V_16 ) ) ;
F_247 ( V_16 , V_17 , F_253 ( 0 ) ) ;
F_238 ( V_18 ) ;
F_268 ( V_286 , V_17 ) ;
}
void F_70 ( const void * V_17 )
{
struct V_15 * V_288 ;
unsigned long V_18 ;
F_269 ( V_286 , V_17 ) ;
if ( F_36 ( F_168 ( V_17 ) ) )
return;
F_237 ( V_18 ) ;
F_203 ( V_17 ) ;
V_288 = F_20 ( V_17 ) ;
F_266 ( V_17 , F_8 ( V_288 ) ) ;
F_267 ( V_17 , F_8 ( V_288 ) ) ;
F_247 ( V_288 , ( void * ) V_17 , F_253 ( 0 ) ) ;
F_238 ( V_18 ) ;
}
unsigned int F_270 ( struct V_15 * V_16 )
{
return F_8 ( V_16 ) ;
}
static int F_271 ( struct V_15 * V_16 , T_5 V_93 )
{
int V_55 ;
struct V_4 * V_47 ;
struct V_45 * V_289 ;
struct V_45 * * V_290 = NULL ;
F_79 (node) {
if ( V_79 ) {
V_290 = F_63 ( V_55 , V_16 -> V_97 , V_93 ) ;
if ( ! V_290 )
goto V_291;
}
V_289 = NULL ;
if ( V_16 -> V_9 ) {
V_289 = F_58 ( V_55 ,
V_16 -> V_9 * V_16 -> V_92 ,
0xbaadf00d , V_93 ) ;
if ( ! V_289 ) {
F_64 ( V_290 ) ;
goto V_291;
}
}
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( V_47 ) {
struct V_45 * V_9 = V_47 -> V_9 ;
F_88 ( & V_47 -> V_12 ) ;
if ( V_9 )
F_73 ( V_16 , V_9 -> V_103 ,
V_9 -> V_96 , V_55 ) ;
V_47 -> V_9 = V_289 ;
if ( ! V_47 -> V_10 ) {
V_47 -> V_10 = V_290 ;
V_290 = NULL ;
}
V_47 -> V_115 = ( 1 + F_89 ( V_55 ) ) *
V_16 -> V_92 + V_16 -> V_69 ;
F_77 ( & V_47 -> V_12 ) ;
F_70 ( V_9 ) ;
F_64 ( V_290 ) ;
continue;
}
V_47 = F_59 ( sizeof( struct V_4 ) , V_93 , V_55 ) ;
if ( ! V_47 ) {
F_64 ( V_290 ) ;
F_70 ( V_289 ) ;
goto V_291;
}
F_4 ( V_47 ) ;
V_47 -> V_112 = V_113 + V_114 +
( ( unsigned long ) V_16 ) % V_114 ;
V_47 -> V_9 = V_289 ;
V_47 -> V_10 = V_290 ;
V_47 -> V_115 = ( 1 + F_89 ( V_55 ) ) *
V_16 -> V_92 + V_16 -> V_69 ;
V_16 -> V_50 [ V_55 ] = V_47 ;
}
return 0 ;
V_291:
if ( ! V_16 -> V_27 . V_27 ) {
V_55 -- ;
while ( V_55 >= 0 ) {
if ( V_16 -> V_50 [ V_55 ] ) {
V_47 = V_16 -> V_50 [ V_55 ] ;
F_70 ( V_47 -> V_9 ) ;
F_64 ( V_47 -> V_10 ) ;
F_70 ( V_47 ) ;
V_16 -> V_50 [ V_55 ] = NULL ;
}
V_55 -- ;
}
}
return - V_111 ;
}
static void F_272 ( void * V_292 )
{
struct V_293 * V_294 = V_292 ;
struct V_45 * V_295 ;
F_171 () ;
V_295 = F_32 ( V_294 -> V_16 ) ;
V_294 -> V_16 -> V_56 [ F_33 () ] = V_294 -> V_294 [ F_33 () ] ;
V_294 -> V_294 [ F_33 () ] = V_295 ;
}
static int F_273 ( struct V_15 * V_16 , int V_97 ,
int V_92 , int V_9 , T_5 V_93 )
{
struct V_293 * V_294 ;
int V_3 ;
V_294 = F_274 ( sizeof( * V_294 ) , V_93 ) ;
if ( ! V_294 )
return - V_111 ;
F_122 (i) {
V_294 -> V_294 [ V_3 ] = F_58 ( F_47 ( V_3 ) , V_97 ,
V_92 , V_93 ) ;
if ( ! V_294 -> V_294 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_70 ( V_294 -> V_294 [ V_3 ] ) ;
F_70 ( V_294 ) ;
return - V_111 ;
}
}
V_294 -> V_16 = V_16 ;
F_180 ( F_272 , ( void * ) V_294 , 1 ) ;
F_173 () ;
V_16 -> V_92 = V_92 ;
V_16 -> V_97 = V_97 ;
V_16 -> V_9 = V_9 ;
F_122 (i) {
struct V_45 * V_296 = V_294 -> V_294 [ V_3 ] ;
if ( ! V_296 )
continue;
F_88 ( & V_16 -> V_50 [ F_47 ( V_3 ) ] -> V_12 ) ;
F_73 ( V_16 , V_296 -> V_103 , V_296 -> V_96 , F_47 ( V_3 ) ) ;
F_77 ( & V_16 -> V_50 [ F_47 ( V_3 ) ] -> V_12 ) ;
F_70 ( V_296 ) ;
}
F_70 ( V_294 ) ;
return F_271 ( V_16 , V_93 ) ;
}
static int F_117 ( struct V_15 * V_16 , T_5 V_93 )
{
int V_119 ;
int V_97 , V_9 ;
if ( V_16 -> V_21 > 131072 )
V_97 = 1 ;
else if ( V_16 -> V_21 > V_72 )
V_97 = 8 ;
else if ( V_16 -> V_21 > 1024 )
V_97 = 24 ;
else if ( V_16 -> V_21 > 256 )
V_97 = 54 ;
else
V_97 = 120 ;
V_9 = 0 ;
if ( V_16 -> V_21 <= V_72 && F_275 () > 1 )
V_9 = 8 ;
#if V_59
if ( V_97 > 32 )
V_97 = 32 ;
#endif
V_119 = F_273 ( V_16 , V_97 , ( V_97 + 1 ) / 2 , V_9 , V_93 ) ;
if ( V_119 )
F_42 ( V_77 L_41 ,
V_16 -> V_78 , - V_119 ) ;
return V_119 ;
}
static void F_181 ( struct V_15 * V_16 , struct V_4 * V_47 ,
struct V_45 * V_107 , int V_297 , int V_55 )
{
int V_241 ;
if ( ! V_107 || ! V_107 -> V_96 )
return;
if ( V_107 -> V_98 && ! V_297 ) {
V_107 -> V_98 = 0 ;
} else {
F_88 ( & V_47 -> V_12 ) ;
if ( V_107 -> V_96 ) {
V_241 = V_297 ? V_107 -> V_96 : ( V_107 -> V_97 + 4 ) / 5 ;
if ( V_241 > V_107 -> V_96 )
V_241 = ( V_107 -> V_96 + 1 ) / 2 ;
F_73 ( V_16 , V_107 -> V_103 , V_241 , V_55 ) ;
V_107 -> V_96 -= V_241 ;
memmove ( V_107 -> V_103 , & ( V_107 -> V_103 [ V_241 ] ) ,
sizeof( void * ) * V_107 -> V_96 ) ;
}
F_77 ( & V_47 -> V_12 ) ;
}
}
static void V_89 ( struct V_298 * V_299 )
{
struct V_15 * V_300 ;
struct V_4 * V_47 ;
int V_55 = F_82 () ;
struct V_84 * V_87 = F_276 ( V_299 ) ;
if ( ! F_277 ( & V_127 ) )
goto V_146;
F_87 (searchp, &cache_chain, next) {
F_173 () ;
V_47 = V_300 -> V_50 [ V_55 ] ;
F_75 ( V_300 , V_47 ) ;
F_181 ( V_300 , V_47 , F_32 ( V_300 ) , 0 , V_55 ) ;
if ( F_278 ( V_47 -> V_112 , V_113 ) )
goto V_27;
V_47 -> V_112 = V_113 + V_114 ;
F_181 ( V_300 , V_47 , V_47 -> V_9 , 0 , V_55 ) ;
if ( V_47 -> V_14 )
V_47 -> V_14 = 0 ;
else {
int V_301 ;
V_301 = F_93 ( V_300 , V_47 , ( V_47 -> V_115 +
5 * V_300 -> V_69 - 1 ) / ( 5 * V_300 -> V_69 ) ) ;
F_279 ( V_300 , V_301 ) ;
}
V_27:
F_280 () ;
}
F_173 () ;
F_98 ( & V_127 ) ;
F_50 () ;
V_146:
F_281 ( V_87 , F_282 ( V_302 ) ) ;
}
static void F_283 ( struct V_303 * V_304 )
{
#if V_284
F_284 ( V_304 , L_42 ) ;
#else
F_284 ( V_304 , L_43 ) ;
#endif
F_284 ( V_304 , L_44
L_45 ) ;
F_284 ( V_304 , L_46 ) ;
F_284 ( V_304 , L_47 ) ;
#if V_284
F_284 ( V_304 , L_48
L_49 ) ;
F_284 ( V_304 , L_50 ) ;
#endif
F_285 ( V_304 , '\n' ) ;
}
static void * F_286 ( struct V_303 * V_304 , T_10 * V_305 )
{
T_10 V_306 = * V_305 ;
F_97 ( & V_127 ) ;
if ( ! V_306 )
F_283 ( V_304 ) ;
return F_287 ( & V_169 , * V_305 ) ;
}
static void * F_288 ( struct V_303 * V_304 , void * V_242 , T_10 * V_305 )
{
return F_289 ( V_242 , & V_169 , V_305 ) ;
}
static void F_290 ( struct V_303 * V_304 , void * V_242 )
{
F_98 ( & V_127 ) ;
}
static int F_291 ( struct V_303 * V_304 , void * V_242 )
{
struct V_15 * V_16 = F_182 ( V_242 , struct V_15 , V_27 ) ;
struct V_29 * V_109 ;
unsigned long V_307 ;
unsigned long V_308 ;
unsigned long V_309 = 0 ;
unsigned long V_310 , V_13 = 0 , V_311 = 0 ;
const char * V_78 ;
char * error = NULL ;
int V_55 ;
struct V_4 * V_47 ;
V_307 = 0 ;
V_310 = 0 ;
F_79 (node) {
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( ! V_47 )
continue;
F_173 () ;
F_88 ( & V_47 -> V_12 ) ;
F_87 (slabp, &l3->slabs_full, list) {
if ( V_109 -> V_243 != V_16 -> V_69 && ! error )
error = L_51 ;
V_307 += V_16 -> V_69 ;
V_309 ++ ;
}
F_87 (slabp, &l3->slabs_partial, list) {
if ( V_109 -> V_243 == V_16 -> V_69 && ! error )
error = L_52 ;
if ( ! V_109 -> V_243 && ! error )
error = L_53 ;
V_307 += V_109 -> V_243 ;
V_309 ++ ;
}
F_87 (slabp, &l3->slabs_free, list) {
if ( V_109 -> V_243 && ! error )
error = L_54 ;
V_310 ++ ;
}
V_13 += V_47 -> V_13 ;
if ( V_47 -> V_9 )
V_311 += V_47 -> V_9 -> V_96 ;
F_77 ( & V_47 -> V_12 ) ;
}
V_310 += V_309 ;
V_308 = V_310 * V_16 -> V_69 ;
if ( V_308 - V_307 != V_13 && ! error )
error = L_55 ;
V_78 = V_16 -> V_78 ;
if ( error )
F_42 ( V_77 L_56 , V_78 , error ) ;
F_292 ( V_304 , L_57 ,
V_78 , V_307 , V_308 , V_16 -> V_21 ,
V_16 -> V_69 , ( 1 << V_16 -> V_67 ) ) ;
F_292 ( V_304 , L_58 ,
V_16 -> V_97 , V_16 -> V_92 , V_16 -> V_9 ) ;
F_292 ( V_304 , L_59 ,
V_309 , V_310 , V_311 ) ;
#if V_284
{
unsigned long V_312 = V_16 -> V_313 ;
unsigned long V_314 = V_16 -> V_315 ;
unsigned long V_316 = V_16 -> V_316 ;
unsigned long V_317 = V_16 -> V_317 ;
unsigned long V_318 = V_16 -> V_318 ;
unsigned long V_319 = V_16 -> V_319 ;
unsigned long V_320 = V_16 -> V_320 ;
unsigned long V_321 = V_16 -> V_321 ;
unsigned long V_322 = V_16 -> V_323 ;
F_292 ( V_304 , L_60
L_61 ,
V_314 , V_312 , V_316 ,
V_317 , V_318 , V_319 , V_320 ,
V_321 , V_322 ) ;
}
{
unsigned long V_324 = F_293 ( & V_16 -> V_324 ) ;
unsigned long V_325 = F_293 ( & V_16 -> V_325 ) ;
unsigned long V_326 = F_293 ( & V_16 -> V_326 ) ;
unsigned long V_327 = F_293 ( & V_16 -> V_327 ) ;
F_292 ( V_304 , L_62 ,
V_324 , V_325 , V_326 , V_327 ) ;
}
#endif
F_285 ( V_304 , '\n' ) ;
return 0 ;
}
static T_11 F_294 ( struct V_328 * V_328 , const char T_12 * V_329 ,
T_2 V_330 , T_10 * V_331 )
{
char V_332 [ V_333 + 1 ] , * V_232 ;
int V_97 , V_92 , V_9 , V_233 ;
struct V_15 * V_16 ;
if ( V_330 > V_333 )
return - V_334 ;
if ( F_295 ( & V_332 , V_329 , V_330 ) )
return - V_335 ;
V_332 [ V_333 ] = '\0' ;
V_232 = strchr ( V_332 , ' ' ) ;
if ( ! V_232 )
return - V_334 ;
* V_232 = '\0' ;
V_232 ++ ;
if ( sscanf ( V_232 , L_63 , & V_97 , & V_92 , & V_9 ) != 3 )
return - V_334 ;
F_97 ( & V_127 ) ;
V_233 = - V_334 ;
F_87 (cachep, &cache_chain, next) {
if ( ! strcmp ( V_16 -> V_78 , V_332 ) ) {
if ( V_97 < 1 || V_92 < 1 ||
V_92 > V_97 || V_9 < 0 ) {
V_233 = 0 ;
} else {
V_233 = F_273 ( V_16 , V_97 ,
V_92 , V_9 ,
V_110 ) ;
}
break;
}
}
F_98 ( & V_127 ) ;
if ( V_233 >= 0 )
V_233 = V_330 ;
return V_233 ;
}
static int F_296 ( struct V_336 * V_336 , struct V_328 * V_328 )
{
return F_297 ( V_328 , & V_337 ) ;
}
static void * F_298 ( struct V_303 * V_304 , T_10 * V_305 )
{
F_97 ( & V_127 ) ;
return F_287 ( & V_169 , * V_305 ) ;
}
static inline int F_299 ( unsigned long * V_306 , unsigned long V_338 )
{
unsigned long * V_242 ;
int V_339 ;
if ( ! V_338 )
return 1 ;
V_339 = V_306 [ 1 ] ;
V_242 = V_306 + 2 ;
while ( V_339 ) {
int V_3 = V_339 / 2 ;
unsigned long * V_38 = V_242 + 2 * V_3 ;
if ( * V_38 == V_338 ) {
V_38 [ 1 ] ++ ;
return 1 ;
}
if ( * V_38 > V_338 ) {
V_339 = V_3 ;
} else {
V_242 = V_38 + 2 ;
V_339 -= V_3 + 1 ;
}
}
if ( ++ V_306 [ 1 ] == V_306 [ 0 ] )
return 0 ;
memmove ( V_242 + 2 , V_242 , V_306 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_242 - ( void * ) V_306 ) ) ;
V_242 [ 0 ] = V_338 ;
V_242 [ 1 ] = 1 ;
return 1 ;
}
static void F_300 ( unsigned long * V_306 , struct V_15 * V_288 , struct V_29 * V_40 )
{
void * V_242 ;
int V_3 ;
if ( V_306 [ 0 ] == V_306 [ 1 ] )
return;
for ( V_3 = 0 , V_242 = V_40 -> V_33 ; V_3 < V_288 -> V_69 ; V_3 ++ , V_242 += V_288 -> V_21 ) {
if ( F_191 ( V_40 ) [ V_3 ] != V_262 )
continue;
if ( ! F_299 ( V_306 , ( unsigned long ) * F_12 ( V_288 , V_242 ) ) )
return;
}
}
static void F_301 ( struct V_303 * V_304 , unsigned long V_340 )
{
#ifdef F_302
unsigned long V_34 , V_1 ;
char V_341 [ V_342 ] , V_78 [ V_343 ] ;
if ( F_303 ( V_340 , & V_1 , & V_34 , V_341 , V_78 ) == 0 ) {
F_292 ( V_304 , L_64 , V_78 , V_34 , V_1 ) ;
if ( V_341 [ 0 ] )
F_292 ( V_304 , L_65 , V_341 ) ;
return;
}
#endif
F_292 ( V_304 , L_66 , ( void * ) V_340 ) ;
}
static int F_304 ( struct V_303 * V_304 , void * V_242 )
{
struct V_15 * V_16 = F_182 ( V_242 , struct V_15 , V_27 ) ;
struct V_29 * V_109 ;
struct V_4 * V_47 ;
const char * V_78 ;
unsigned long * V_306 = V_304 -> V_344 ;
int V_55 ;
int V_3 ;
if ( ! ( V_16 -> V_18 & V_20 ) )
return 0 ;
if ( ! ( V_16 -> V_18 & V_19 ) )
return 0 ;
V_306 [ 1 ] = 0 ;
F_79 (node) {
V_47 = V_16 -> V_50 [ V_55 ] ;
if ( ! V_47 )
continue;
F_173 () ;
F_88 ( & V_47 -> V_12 ) ;
F_87 (slabp, &l3->slabs_full, list)
F_300 ( V_306 , V_16 , V_109 ) ;
F_87 (slabp, &l3->slabs_partial, list)
F_300 ( V_306 , V_16 , V_109 ) ;
F_77 ( & V_47 -> V_12 ) ;
}
V_78 = V_16 -> V_78 ;
if ( V_306 [ 0 ] == V_306 [ 1 ] ) {
F_98 ( & V_127 ) ;
V_304 -> V_344 = F_274 ( V_306 [ 0 ] * 4 * sizeof( unsigned long ) , V_110 ) ;
if ( ! V_304 -> V_344 ) {
V_304 -> V_344 = V_306 ;
F_97 ( & V_127 ) ;
return - V_111 ;
}
* ( unsigned long * ) V_304 -> V_344 = V_306 [ 0 ] * 2 ;
F_70 ( V_306 ) ;
F_97 ( & V_127 ) ;
V_304 -> V_330 = V_304 -> V_1 ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_306 [ 1 ] ; V_3 ++ ) {
F_292 ( V_304 , L_67 , V_78 , V_306 [ 2 * V_3 + 3 ] ) ;
F_301 ( V_304 , V_306 [ 2 * V_3 + 2 ] ) ;
F_285 ( V_304 , '\n' ) ;
}
return 0 ;
}
static int F_305 ( struct V_336 * V_336 , struct V_328 * V_328 )
{
unsigned long * V_306 = F_274 ( V_72 , V_110 ) ;
int V_138 = - V_111 ;
if ( V_306 ) {
V_138 = F_297 ( V_328 , & V_345 ) ;
if ( ! V_138 ) {
struct V_303 * V_304 = V_328 -> V_346 ;
* V_306 = V_72 / ( 2 * sizeof( unsigned long ) ) ;
V_304 -> V_344 = V_306 ;
V_306 = NULL ;
}
F_70 ( V_306 ) ;
}
return V_138 ;
}
static int T_6 F_306 ( void )
{
F_307 ( L_68 , V_347 | V_348 , NULL , & V_349 ) ;
#ifdef F_207
F_307 ( L_69 , 0 , NULL , & V_350 ) ;
#endif
return 0 ;
}
T_2 F_308 ( const void * V_17 )
{
F_10 ( ! V_17 ) ;
if ( F_36 ( V_17 == V_61 ) )
return 0 ;
return F_8 ( F_20 ( V_17 ) ) ;
}
