static inline int F_1 ( int V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return 1 ;
return 0 ;
}
static inline int F_2 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 ) ;
}
static enum V_6 F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_4 ( V_8 , struct V_9 , V_11 ) ;
T_1 V_12 ;
int V_13 ;
int V_14 = 0 ;
for (; ; ) {
V_12 = F_5 ( V_8 ) ;
V_13 = F_6 ( V_8 , V_12 , V_10 -> V_15 ) ;
if ( ! V_13 )
break;
V_14 = F_7 ( V_10 , V_13 ) ;
}
return V_14 ? V_16 : V_17 ;
}
static
void F_8 ( struct V_9 * V_10 , T_2 V_18 , T_2 V_19 )
{
V_10 -> V_15 = F_9 ( V_18 ) ;
V_10 -> V_20 = V_19 ;
F_10 ( & V_10 -> V_21 ) ;
F_11 ( & V_10 -> V_11 ,
V_22 , V_23 ) ;
V_10 -> V_11 . V_24 = F_3 ;
}
static inline int F_12 ( void )
{
return V_25 >= 0 ;
}
static void F_13 ( struct V_7 * V_26 , T_1 V_18 )
{
unsigned long V_27 ;
T_1 V_28 , V_29 , V_12 ;
for (; ; ) {
if ( F_14 ( V_26 ) )
break;
V_12 = F_5 ( V_26 ) ;
F_6 ( V_26 , V_12 , V_18 ) ;
V_28 = F_15 ( V_26 ) ;
V_29 = F_16 ( V_26 ) ;
V_27 = F_17 ( F_18 ( V_29 , V_28 ) ) ;
F_19 ( V_26 , V_28 , V_27 ,
V_30 , 0 ) ;
}
}
static void F_20 ( struct V_9 * V_10 )
{
if ( ! F_12 () || V_10 -> V_20 == V_31 )
return;
if ( F_14 ( & V_10 -> V_11 ) )
return;
F_21 ( & V_10 -> V_21 ) ;
F_13 ( & V_10 -> V_11 , V_10 -> V_15 ) ;
F_22 ( & V_10 -> V_21 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
F_24 ( & V_10 -> V_11 ) ;
}
static inline struct V_32 * F_25 ( struct V_33 * V_34 )
{
return & V_34 -> V_32 ;
}
static enum V_6 F_26 ( struct V_7 * V_8 )
{
struct V_32 * V_35 =
F_4 ( V_8 , struct V_32 , V_36 ) ;
F_27 ( V_35 ) ;
return V_16 ;
}
static enum V_6 F_28 ( struct V_7 * V_8 )
{
struct V_32 * V_35 =
F_4 ( V_8 , struct V_32 , V_26 ) ;
T_1 V_12 ;
int V_13 ;
int V_14 = 0 ;
for (; ; ) {
V_12 = F_5 ( V_8 ) ;
V_13 = F_6 ( V_8 , V_12 , V_35 -> V_18 ) ;
if ( ! V_13 )
break;
V_14 = F_29 ( V_35 , V_13 ) ;
}
return V_14 ? V_16 : V_17 ;
}
static void F_30 ( struct V_32 * V_35 )
{
F_10 ( & V_35 -> V_37 ) ;
V_35 -> V_19 = 0 ;
V_35 -> V_38 = V_31 ;
V_35 -> V_18 = F_9 ( F_31 () ) ;
F_32 ( & V_35 -> V_39 ) ;
F_11 ( & V_35 -> V_26 , V_22 , V_23 ) ;
V_35 -> V_26 . V_24 = F_28 ;
F_11 ( & V_35 -> V_36 , V_22 , V_23 ) ;
V_35 -> V_36 . V_24 = F_26 ;
}
static void F_33 ( struct V_40 * V_40 )
{
V_40 -> V_41 = 0 ;
F_32 ( & V_40 -> V_42 ) ;
}
static void F_34 ( struct V_32 * V_35 )
{
while ( F_35 ( F_14 ( & V_35 -> V_26 ) ) ) {
F_22 ( & V_35 -> V_37 ) ;
F_24 ( & V_35 -> V_26 ) ;
F_21 ( & V_35 -> V_37 ) ;
if ( V_35 -> V_43 )
return;
}
V_35 -> V_43 = 1 ;
F_13 ( & V_35 -> V_26 , V_35 -> V_18 ) ;
}
static void F_36 ( struct V_32 * V_35 )
{
F_24 ( & V_35 -> V_26 ) ;
F_24 ( & V_35 -> V_36 ) ;
}
static void F_33 ( struct V_40 * V_40 ) {}
static void F_30 ( struct V_32 * V_35 ) {}
static void F_36 ( struct V_32 * V_35 ) {}
static inline struct V_32 * F_25 ( struct V_33 * V_34 )
{
return NULL ;
}
static inline int F_37 ( struct V_44 * V_44 )
{
#ifdef F_38
return V_44 -> V_45 ;
#else
return 0 ;
#endif
}
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
struct V_33 * V_34 ;
struct V_46 * V_47 ;
V_47 = F_39 ( V_5 , V_48 ,
F_40 ( & V_5 -> V_49 ) ||
F_40 ( & F_41 ( V_5 ) -> V_37 ) ) ;
V_34 = F_4 ( V_47 , struct V_33 , V_47 ) ;
return F_42 ( V_5 , V_34 ) ;
}
static inline void F_43 ( struct V_4 * V_5 , unsigned int V_45 )
{
#ifdef F_44
V_5 -> V_50 . V_40 = V_33 ( V_5 ) -> V_40 [ V_45 ] ;
V_5 -> V_50 . V_51 = V_33 ( V_5 ) -> V_50 [ V_45 ] ;
#endif
#ifdef F_45
V_5 -> V_52 . V_53 = V_33 ( V_5 ) -> V_53 [ V_45 ] ;
V_5 -> V_52 . V_51 = V_33 ( V_5 ) -> V_54 [ V_45 ] ;
#endif
}
static inline void F_43 ( struct V_4 * V_5 , unsigned int V_45 ) { }
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
return NULL ;
}
static void F_46 ( struct V_44 * V_44 )
{
T_3 V_27 ;
if ( V_44 -> V_55 > 0 )
return;
V_27 = F_47 ( F_37 ( V_44 ) ) - V_44 -> clock ;
V_44 -> clock += V_27 ;
F_48 ( V_44 , V_27 ) ;
}
int F_49 ( int V_45 )
{
return F_50 ( & F_51 ( V_45 ) -> V_37 ) ;
}
static int F_52 ( struct V_56 * V_57 , void * V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_60 [ V_59 ] ; V_59 ++ ) {
if ( ! ( V_61 & ( 1UL << V_59 ) ) )
F_53 ( V_57 , L_1 ) ;
F_54 ( V_57 , L_2 , V_60 [ V_59 ] ) ;
}
F_53 ( V_57 , L_3 ) ;
return 0 ;
}
static T_4
F_55 ( struct V_62 * V_63 , const char T_5 * V_64 ,
T_6 V_65 , T_7 * V_66 )
{
char V_67 [ 64 ] ;
char * V_68 ;
int V_69 = 0 ;
int V_59 ;
if ( V_65 > 63 )
V_65 = 63 ;
if ( F_56 ( & V_67 , V_64 , V_65 ) )
return - V_70 ;
V_67 [ V_65 ] = 0 ;
V_68 = F_57 ( V_67 ) ;
if ( strncmp ( V_68 , L_1 , 3 ) == 0 ) {
V_69 = 1 ;
V_68 += 3 ;
}
for ( V_59 = 0 ; V_60 [ V_59 ] ; V_59 ++ ) {
if ( strcmp ( V_68 , V_60 [ V_59 ] ) == 0 ) {
if ( V_69 )
V_61 &= ~ ( 1UL << V_59 ) ;
else
V_61 |= ( 1UL << V_59 ) ;
break;
}
}
if ( ! V_60 [ V_59 ] )
return - V_71 ;
* V_66 += V_65 ;
return V_65 ;
}
static int F_58 ( struct V_72 * V_72 , struct V_62 * V_63 )
{
return F_59 ( V_63 , F_52 , NULL ) ;
}
static T_8 int F_60 ( void )
{
F_61 ( L_4 , 0644 , NULL , NULL ,
& V_73 ) ;
return 0 ;
}
static inline T_2 F_62 ( void )
{
return ( T_2 ) V_74 * V_75 ;
}
static inline T_2 F_63 ( void )
{
if ( V_25 < 0 )
return V_31 ;
return ( T_2 ) V_25 * V_75 ;
}
static inline int F_64 ( struct V_44 * V_44 , struct V_4 * V_5 )
{
return V_44 -> V_76 == V_5 ;
}
static inline int F_65 ( struct V_44 * V_44 , struct V_4 * V_5 )
{
#ifdef F_38
return V_5 -> V_77 ;
#else
return F_64 ( V_44 , V_5 ) ;
#endif
}
static inline void F_66 ( struct V_44 * V_44 , struct V_4 * V_78 )
{
#ifdef F_38
V_78 -> V_77 = 1 ;
#endif
}
static inline void F_67 ( struct V_44 * V_44 , struct V_4 * V_79 )
{
#ifdef F_38
F_68 () ;
V_79 -> V_77 = 0 ;
#endif
#ifdef F_69
V_44 -> V_37 . V_80 = V_81 ;
#endif
F_70 ( & V_44 -> V_37 . V_82 , 0 , 0 , V_83 ) ;
F_71 ( & V_44 -> V_37 ) ;
}
static inline void F_66 ( struct V_44 * V_44 , struct V_4 * V_78 )
{
#ifdef F_38
V_78 -> V_77 = 1 ;
#endif
#ifdef F_72
F_71 ( & V_44 -> V_37 ) ;
#else
F_22 ( & V_44 -> V_37 ) ;
#endif
}
static inline void F_67 ( struct V_44 * V_44 , struct V_4 * V_79 )
{
#ifdef F_38
F_68 () ;
V_79 -> V_77 = 0 ;
#endif
#ifndef F_72
F_73 () ;
#endif
}
static inline struct V_44 * F_74 ( struct V_4 * V_5 )
__acquires( V_44 -> V_37 )
{
struct V_44 * V_44 ;
F_75 ( & V_5 -> V_49 ) ;
for (; ; ) {
V_44 = F_41 ( V_5 ) ;
F_21 ( & V_44 -> V_37 ) ;
if ( F_76 ( V_44 == F_41 ( V_5 ) ) )
return V_44 ;
F_22 ( & V_44 -> V_37 ) ;
}
}
static struct V_44 * F_77 ( struct V_4 * V_5 , unsigned long * V_84 )
__acquires( V_5 -> V_49 )
__acquires( V_44 -> V_37 )
{
struct V_44 * V_44 ;
for (; ; ) {
F_78 ( & V_5 -> V_49 , * V_84 ) ;
V_44 = F_41 ( V_5 ) ;
F_21 ( & V_44 -> V_37 ) ;
if ( F_76 ( V_44 == F_41 ( V_5 ) ) )
return V_44 ;
F_22 ( & V_44 -> V_37 ) ;
F_79 ( & V_5 -> V_49 , * V_84 ) ;
}
}
static void F_80 ( struct V_44 * V_44 )
__releases( V_44 -> V_37 )
{
F_22 ( & V_44 -> V_37 ) ;
}
static inline void
F_81 ( struct V_44 * V_44 , struct V_4 * V_5 , unsigned long * V_84 )
__releases( V_44 -> V_37 )
__releases( V_5 -> V_49 )
{
F_22 ( & V_44 -> V_37 ) ;
F_79 ( & V_5 -> V_49 , * V_84 ) ;
}
static struct V_44 * F_82 ( void )
__acquires( V_44 -> V_37 )
{
struct V_44 * V_44 ;
F_83 () ;
V_44 = F_84 () ;
F_21 ( & V_44 -> V_37 ) ;
return V_44 ;
}
static inline int F_85 ( struct V_44 * V_44 )
{
if ( ! F_86 ( V_85 ) )
return 0 ;
if ( ! F_87 ( F_37 ( V_44 ) ) )
return 0 ;
return F_88 ( & V_44 -> V_86 ) ;
}
static void F_89 ( struct V_44 * V_44 )
{
if ( F_14 ( & V_44 -> V_86 ) )
F_24 ( & V_44 -> V_86 ) ;
}
static enum V_6 F_90 ( struct V_7 * V_8 )
{
struct V_44 * V_44 = F_4 ( V_8 , struct V_44 , V_86 ) ;
F_91 ( F_37 ( V_44 ) != F_92 () ) ;
F_21 ( & V_44 -> V_37 ) ;
F_46 ( V_44 ) ;
V_44 -> V_76 -> V_87 -> V_88 ( V_44 , V_44 -> V_76 , 1 ) ;
F_22 ( & V_44 -> V_37 ) ;
return V_16 ;
}
static void F_93 ( void * V_89 )
{
struct V_44 * V_44 = V_89 ;
F_21 ( & V_44 -> V_37 ) ;
V_6 ( & V_44 -> V_86 ) ;
V_44 -> V_90 = 0 ;
F_22 ( & V_44 -> V_37 ) ;
}
static void F_94 ( struct V_44 * V_44 , T_2 V_91 )
{
struct V_7 * V_8 = & V_44 -> V_86 ;
T_1 time = F_95 ( V_8 -> V_92 -> V_93 () , V_91 ) ;
F_96 ( V_8 , time ) ;
if ( V_44 == F_84 () ) {
V_6 ( V_8 ) ;
} else if ( ! V_44 -> V_90 ) {
F_97 ( F_37 ( V_44 ) , & V_44 -> V_94 , 0 ) ;
V_44 -> V_90 = 1 ;
}
}
static int
F_98 ( struct V_95 * V_96 , unsigned long V_97 , void * V_98 )
{
int V_45 = ( int ) ( long ) V_98 ;
switch ( V_97 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
F_89 ( F_51 ( V_45 ) ) ;
return V_105 ;
}
return V_106 ;
}
static T_8 void F_99 ( void )
{
F_100 ( F_98 , 0 ) ;
}
static void F_94 ( struct V_44 * V_44 , T_2 V_91 )
{
F_19 ( & V_44 -> V_86 , F_9 ( V_91 ) , 0 ,
V_107 , 0 ) ;
}
static inline void F_99 ( void )
{
}
static void F_101 ( struct V_44 * V_44 )
{
#ifdef F_38
V_44 -> V_90 = 0 ;
V_44 -> V_94 . V_84 = 0 ;
V_44 -> V_94 . V_108 = F_93 ;
V_44 -> V_94 . V_109 = V_44 ;
#endif
F_11 ( & V_44 -> V_86 , V_22 , V_23 ) ;
V_44 -> V_86 . V_24 = F_90 ;
}
static inline void F_89 ( struct V_44 * V_44 )
{
}
static inline void F_101 ( struct V_44 * V_44 )
{
}
static inline void F_99 ( void )
{
}
static void F_102 ( struct V_4 * V_5 )
{
int V_45 ;
F_103 ( & F_41 ( V_5 ) -> V_37 ) ;
if ( F_104 ( V_5 ) )
return;
F_105 ( V_5 ) ;
V_45 = F_106 ( V_5 ) ;
if ( V_45 == F_92 () )
return;
F_107 () ;
if ( ! F_108 ( V_5 ) )
F_109 ( V_45 ) ;
}
static void F_110 ( int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_84 ;
if ( ! F_111 ( & V_44 -> V_37 , V_84 ) )
return;
F_102 ( F_112 ( V_45 ) ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
}
int F_113 ( void )
{
int V_45 = F_92 () ;
int V_59 ;
struct V_110 * V_111 ;
F_114 () ;
F_115 (cpu, sd) {
F_116 (i, sched_domain_span(sd)) {
if ( ! F_117 ( V_59 ) ) {
V_45 = V_59 ;
goto V_112;
}
}
}
V_112:
F_118 () ;
return V_45 ;
}
void F_119 ( int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
if ( V_45 == F_92 () )
return;
if ( V_44 -> V_76 != V_44 -> V_14 )
return;
F_105 ( V_44 -> V_14 ) ;
F_107 () ;
if ( ! F_108 ( V_44 -> V_14 ) )
F_109 ( V_45 ) ;
}
static inline bool F_120 ( void )
{
return F_117 ( F_92 () ) && F_84 () -> V_113 ;
}
static inline bool F_120 ( void )
{
return false ;
}
static T_2 F_121 ( void )
{
return ( T_2 ) V_114 * V_115 / 2 ;
}
static void F_122 ( struct V_44 * V_44 )
{
T_3 V_18 = F_121 () ;
while ( ( T_3 ) ( V_44 -> clock - V_44 -> V_116 ) > V_18 ) {
asm("" : "+rm" (rq->age_stamp));
V_44 -> V_116 += V_18 ;
V_44 -> V_117 /= 2 ;
}
}
static void F_123 ( struct V_44 * V_44 , T_2 V_118 )
{
V_44 -> V_117 += V_118 ;
F_122 ( V_44 ) ;
}
static void F_102 ( struct V_4 * V_5 )
{
F_103 ( & F_41 ( V_5 ) -> V_37 ) ;
F_105 ( V_5 ) ;
}
static void F_123 ( struct V_44 * V_44 , T_2 V_118 )
{
}
static void F_122 ( struct V_44 * V_44 )
{
}
static unsigned long
F_124 ( unsigned long V_119 , unsigned long V_120 ,
struct V_121 * V_122 )
{
T_2 V_123 ;
if ( F_76 ( V_120 > ( 1UL << V_124 ) ) )
V_123 = ( T_2 ) V_119 * F_125 ( V_120 ) ;
else
V_123 = ( T_2 ) V_119 ;
if ( ! V_122 -> V_125 ) {
unsigned long V_126 = F_125 ( V_122 -> V_120 ) ;
if ( V_127 > 32 && F_35 ( V_126 >= V_128 ) )
V_122 -> V_125 = 1 ;
else if ( F_35 ( ! V_126 ) )
V_122 -> V_125 = V_128 ;
else
V_122 -> V_125 = V_128 / V_126 ;
}
if ( F_35 ( V_123 > V_128 ) )
V_123 = F_126 ( F_126 ( V_123 , V_129 / 2 ) * V_122 -> V_125 ,
V_129 / 2 ) ;
else
V_123 = F_126 ( V_123 * V_122 -> V_125 , V_129 ) ;
return ( unsigned long ) F_127 ( V_123 , ( T_2 ) ( unsigned long ) V_130 ) ;
}
static inline void F_128 ( struct V_121 * V_122 , unsigned long V_131 )
{
V_122 -> V_120 += V_131 ;
V_122 -> V_125 = 0 ;
}
static inline void F_129 ( struct V_121 * V_122 , unsigned long V_132 )
{
V_122 -> V_120 -= V_132 ;
V_122 -> V_125 = 0 ;
}
static inline void F_130 ( struct V_121 * V_122 , unsigned long V_126 )
{
V_122 -> V_120 = V_126 ;
V_122 -> V_125 = 0 ;
}
static inline void F_131 ( struct V_4 * V_133 , T_2 V_134 ) {}
static inline void F_132 ( struct V_4 * V_133 ,
enum V_135 V_136 , T_9 V_137 ) {}
static inline void F_133 ( struct V_44 * V_44 , unsigned long V_138 )
{
F_128 ( & V_44 -> V_138 , V_138 ) ;
}
static inline void F_134 ( struct V_44 * V_44 , unsigned long V_138 )
{
F_129 ( & V_44 -> V_138 , V_138 ) ;
}
static int F_135 ( struct V_33 * V_139 ,
T_10 V_140 , T_10 V_141 , void * V_142 )
{
struct V_33 * V_51 , * V_143 ;
int V_144 ;
V_51 = V_139 ;
V_140:
V_144 = (* V_140)( V_51 , V_142 ) ;
if ( V_144 )
goto V_145;
F_136 (child, &parent->children, siblings) {
V_51 = V_143 ;
goto V_140;
V_141:
continue;
}
V_144 = (* V_141)( V_51 , V_142 ) ;
if ( V_144 || V_51 == V_139 )
goto V_145;
V_143 = V_51 ;
V_51 = V_51 -> V_51 ;
if ( V_51 )
goto V_141;
V_145:
return V_144 ;
}
static inline int F_137 ( T_10 V_140 , T_10 V_141 , void * V_142 )
{
return F_135 ( & V_146 , V_140 , V_141 , V_142 ) ;
}
static int F_138 ( struct V_33 * V_34 , void * V_142 )
{
return 0 ;
}
static unsigned long F_139 ( const int V_45 )
{
return F_51 ( V_45 ) -> V_138 . V_120 ;
}
static unsigned long F_140 ( int V_45 , int type )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_147 = F_139 ( V_45 ) ;
if ( type == 0 || ! F_86 ( V_148 ) )
return V_147 ;
return F_127 ( V_44 -> V_149 [ type - 1 ] , V_147 ) ;
}
static unsigned long F_141 ( int V_45 , int type )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_147 = F_139 ( V_45 ) ;
if ( type == 0 || ! F_86 ( V_148 ) )
return V_147 ;
return F_142 ( V_44 -> V_149 [ type - 1 ] , V_147 ) ;
}
static unsigned long F_143 ( int V_45 )
{
return F_51 ( V_45 ) -> V_150 ;
}
static unsigned long F_144 ( int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_151 = F_145 ( V_44 -> V_151 ) ;
if ( V_151 )
return V_44 -> V_138 . V_120 / V_151 ;
return 0 ;
}
static inline int F_146 ( struct V_44 * F_84 , struct V_44 * V_152 )
__releases( F_84 -> V_37 )
__acquires( V_152 -> V_37 )
__acquires( F_84 -> V_37 )
{
F_22 ( & F_84 -> V_37 ) ;
F_147 ( F_84 , V_152 ) ;
return 1 ;
}
static int F_146 ( struct V_44 * F_84 , struct V_44 * V_152 )
__releases( F_84 -> V_37 )
__acquires( V_152 -> V_37 )
__acquires( F_84 -> V_37 )
{
int V_144 = 0 ;
if ( F_35 ( ! F_148 ( & V_152 -> V_37 ) ) ) {
if ( V_152 < F_84 ) {
F_22 ( & F_84 -> V_37 ) ;
F_21 ( & V_152 -> V_37 ) ;
F_149 ( & F_84 -> V_37 ,
V_153 ) ;
V_144 = 1 ;
} else
F_149 ( & V_152 -> V_37 ,
V_153 ) ;
}
return V_144 ;
}
static int F_150 ( struct V_44 * F_84 , struct V_44 * V_152 )
{
if ( F_35 ( ! F_151 () ) ) {
F_22 ( & F_84 -> V_37 ) ;
F_152 ( 1 ) ;
}
return F_146 ( F_84 , V_152 ) ;
}
static inline void F_153 ( struct V_44 * F_84 , struct V_44 * V_152 )
__releases( V_152 -> V_37 )
{
F_22 ( & V_152 -> V_37 ) ;
F_154 ( & F_84 -> V_37 . V_82 , 0 , V_154 ) ;
}
static void F_147 ( struct V_44 * V_155 , struct V_44 * V_156 )
__acquires( V_155 -> V_37 )
__acquires( V_156 -> V_37 )
{
F_152 ( ! F_151 () ) ;
if ( V_155 == V_156 ) {
F_21 ( & V_155 -> V_37 ) ;
F_155 ( V_156 -> V_37 ) ;
} else {
if ( V_155 < V_156 ) {
F_21 ( & V_155 -> V_37 ) ;
F_149 ( & V_156 -> V_37 , V_153 ) ;
} else {
F_21 ( & V_156 -> V_37 ) ;
F_149 ( & V_155 -> V_37 , V_153 ) ;
}
}
}
static void F_156 ( struct V_44 * V_155 , struct V_44 * V_156 )
__releases( V_155 -> V_37 )
__releases( V_156 -> V_37 )
{
F_22 ( & V_155 -> V_37 ) ;
if ( V_155 != V_156 )
F_22 ( & V_156 -> V_37 ) ;
else
F_157 ( V_156 -> V_37 ) ;
}
static void F_147 ( struct V_44 * V_155 , struct V_44 * V_156 )
__acquires( V_155 -> V_37 )
__acquires( V_156 -> V_37 )
{
F_152 ( ! F_151 () ) ;
F_152 ( V_155 != V_156 ) ;
F_21 ( & V_155 -> V_37 ) ;
F_155 ( V_156 -> V_37 ) ;
}
static void F_156 ( struct V_44 * V_155 , struct V_44 * V_156 )
__releases( V_155 -> V_37 )
__releases( V_156 -> V_37 )
{
F_152 ( V_155 != V_156 ) ;
F_22 ( & V_155 -> V_37 ) ;
F_157 ( V_156 -> V_37 ) ;
}
static inline void F_158 ( struct V_4 * V_5 , unsigned int V_45 )
{
F_43 ( V_5 , V_45 ) ;
#ifdef F_38
F_68 () ;
F_159 ( V_5 ) -> V_45 = V_45 ;
#endif
}
static void F_160 ( struct V_44 * V_44 )
{
V_44 -> V_151 ++ ;
}
static void F_161 ( struct V_44 * V_44 )
{
V_44 -> V_151 -- ;
}
static void F_162 ( struct V_4 * V_5 )
{
int V_157 = V_5 -> V_158 - V_159 ;
struct V_121 * V_138 = & V_5 -> V_50 . V_138 ;
if ( V_5 -> V_1 == V_160 ) {
V_138 -> V_120 = F_163 ( V_161 ) ;
V_138 -> V_125 = V_162 ;
return;
}
V_138 -> V_120 = F_163 ( V_163 [ V_157 ] ) ;
V_138 -> V_125 = V_164 [ V_157 ] ;
}
static void F_164 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_84 )
{
F_46 ( V_44 ) ;
F_165 ( V_5 ) ;
V_5 -> V_87 -> F_164 ( V_44 , V_5 , V_84 ) ;
}
static void F_166 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_84 )
{
F_46 ( V_44 ) ;
F_167 ( V_5 ) ;
V_5 -> V_87 -> F_166 ( V_44 , V_5 , V_84 ) ;
}
static void F_168 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_84 )
{
if ( F_169 ( V_5 ) )
V_44 -> V_165 -- ;
F_164 ( V_44 , V_5 , V_84 ) ;
}
static void F_170 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_84 )
{
if ( F_169 ( V_5 ) )
V_44 -> V_165 ++ ;
F_166 ( V_44 , V_5 , V_84 ) ;
}
void F_171 ( void )
{
V_166 = 1 ;
}
void F_172 ( void )
{
V_166 = 0 ;
}
static inline void F_173 ( void )
{
F_174 ( V_167 . V_168 ) ;
F_68 () ;
}
static inline void F_175 ( void )
{
F_68 () ;
F_174 ( V_167 . V_168 ) ;
}
static inline T_2 F_176 ( int V_45 )
{
T_2 V_169 ;
unsigned V_170 ;
do {
V_170 = F_177 ( & F_178 ( V_167 , V_45 ) ) ;
V_169 = F_178 ( V_171 , V_45 ) +
F_178 ( V_172 , V_45 ) ;
} while ( F_179 ( & F_178 ( V_167 , V_45 ) , V_170 ) );
return V_169 ;
}
static inline void F_173 ( void )
{
}
static inline void F_175 ( void )
{
}
static inline T_2 F_176 ( int V_45 )
{
return F_178 ( V_171 , V_45 ) + F_178 ( V_172 , V_45 ) ;
}
void F_180 ( struct V_4 * V_76 )
{
unsigned long V_84 ;
T_3 V_27 ;
int V_45 ;
if ( ! V_166 )
return;
F_181 ( V_84 ) ;
V_45 = F_92 () ;
V_27 = F_47 ( V_45 ) - F_182 ( V_173 ) ;
F_183 ( V_173 , V_27 ) ;
F_173 () ;
if ( F_184 () )
F_183 ( V_172 , V_27 ) ;
else if ( F_185 () && V_76 != F_186 () )
F_183 ( V_171 , V_27 ) ;
F_175 () ;
F_187 ( V_84 ) ;
}
static inline T_2 F_188 ( T_2 V_174 )
{
if ( F_35 ( V_174 > V_175 ) )
return F_189 ( V_174 , V_176 ) ;
return F_190 ( V_174 , V_176 , & V_174 ) ;
}
static void F_48 ( struct V_44 * V_44 , T_3 V_27 )
{
#if F_191 ( V_177 ) || F_191 ( V_178 )
T_3 V_174 = 0 , V_179 = 0 ;
#endif
#ifdef V_177
V_179 = F_176 ( F_37 ( V_44 ) ) - V_44 -> V_180 ;
if ( V_179 > V_27 )
V_179 = V_27 ;
V_44 -> V_180 += V_179 ;
V_27 -= V_179 ;
#endif
#ifdef V_178
if ( F_192 ( ( & V_181 ) ) ) {
T_2 V_182 ;
V_174 = F_193 ( F_37 ( V_44 ) ) ;
V_174 -= V_44 -> V_183 ;
if ( F_35 ( V_174 > V_27 ) )
V_174 = V_27 ;
V_182 = F_188 ( V_174 ) ;
V_174 = V_182 * V_176 ;
V_44 -> V_183 += V_174 ;
V_27 -= V_174 ;
}
#endif
V_44 -> V_184 += V_27 ;
#if F_191 ( V_177 ) || F_191 ( V_178 )
if ( ( V_179 + V_174 ) && F_86 ( V_185 ) )
F_123 ( V_44 , V_179 + V_174 ) ;
#endif
}
static int F_194 ( void )
{
struct V_186 * V_187 = & V_188 . V_187 ;
unsigned long V_84 ;
T_2 V_189 ;
int V_144 = 0 ;
F_181 ( V_84 ) ;
V_189 = F_195 ( V_172 ) ;
if ( F_196 ( F_197 ( V_189 ) , V_187 -> V_190 ) )
V_144 = 1 ;
F_187 ( V_84 ) ;
return V_144 ;
}
static int F_198 ( void )
{
struct V_186 * V_187 = & V_188 . V_187 ;
unsigned long V_84 ;
T_2 V_189 ;
int V_144 = 0 ;
F_181 ( V_84 ) ;
V_189 = F_195 ( V_171 ) ;
if ( F_196 ( F_197 ( V_189 ) , V_187 -> V_191 ) )
V_144 = 1 ;
F_187 ( V_84 ) ;
return V_144 ;
}
void F_199 ( int V_45 , struct V_4 * V_192 )
{
struct V_193 V_194 = { . V_195 = V_159 - 1 } ;
struct V_4 * V_196 = F_51 ( V_45 ) -> V_192 ;
if ( V_192 ) {
F_200 ( V_192 , V_2 , & V_194 ) ;
V_192 -> V_87 = & V_197 ;
}
F_51 ( V_45 ) -> V_192 = V_192 ;
if ( V_196 ) {
V_196 -> V_87 = & V_198 ;
}
}
static inline int F_201 ( struct V_4 * V_5 )
{
return V_5 -> V_158 ;
}
static inline int F_202 ( struct V_4 * V_5 )
{
int V_157 ;
if ( F_2 ( V_5 ) )
V_157 = V_159 - 1 - V_5 -> V_199 ;
else
V_157 = F_201 ( V_5 ) ;
return V_157 ;
}
static int F_203 ( struct V_4 * V_5 )
{
V_5 -> F_202 = F_202 ( V_5 ) ;
if ( ! F_204 ( V_5 -> V_157 ) )
return V_5 -> F_202 ;
return V_5 -> V_157 ;
}
inline int F_205 ( const struct V_4 * V_5 )
{
return F_112 ( F_106 ( V_5 ) ) == V_5 ;
}
static inline void F_206 ( struct V_44 * V_44 , struct V_4 * V_5 ,
const struct V_87 * V_200 ,
int V_201 )
{
if ( V_200 != V_5 -> V_87 ) {
if ( V_200 -> V_202 )
V_200 -> V_202 ( V_44 , V_5 ) ;
V_5 -> V_87 -> V_203 ( V_44 , V_5 ) ;
} else if ( V_201 != V_5 -> V_157 )
V_5 -> V_87 -> V_204 ( V_44 , V_5 , V_201 ) ;
}
static void F_207 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_84 )
{
const struct V_87 * V_205 ;
if ( V_5 -> V_87 == V_44 -> V_76 -> V_87 ) {
V_44 -> V_76 -> V_87 -> F_207 ( V_44 , V_5 , V_84 ) ;
} else {
F_208 (class) {
if ( V_205 == V_44 -> V_76 -> V_87 )
break;
if ( V_205 == V_5 -> V_87 ) {
F_102 ( V_44 -> V_76 ) ;
break;
}
}
}
if ( V_44 -> V_76 -> V_206 && F_104 ( V_44 -> V_76 ) )
V_44 -> V_55 = 1 ;
}
static int
F_209 ( struct V_4 * V_5 , T_2 V_12 , struct V_110 * V_111 )
{
T_3 V_27 ;
if ( V_5 -> V_87 != & V_207 )
return 0 ;
if ( F_35 ( V_5 -> V_1 == V_160 ) )
return 0 ;
if ( F_86 ( V_208 ) && F_84 () -> V_151 &&
( & V_5 -> V_50 == F_210 ( & V_5 -> V_50 ) -> V_78 ||
& V_5 -> V_50 == F_210 ( & V_5 -> V_50 ) -> V_209 ) )
return 1 ;
if ( V_210 == - 1 )
return 1 ;
if ( V_210 == 0 )
return 0 ;
V_27 = V_12 - V_5 -> V_50 . V_211 ;
return V_27 < ( T_3 ) V_210 ;
}
void F_211 ( struct V_4 * V_5 , unsigned int V_212 )
{
#ifdef F_212
F_91 ( V_5 -> V_213 != V_214 && V_5 -> V_213 != V_215 &&
! ( F_159 ( V_5 ) -> V_216 & V_217 ) ) ;
#ifdef F_213
F_91 ( V_218 && ! ( F_40 ( & V_5 -> V_49 ) ||
F_40 ( & F_41 ( V_5 ) -> V_37 ) ) ) ;
#endif
#endif
F_214 ( V_5 , V_212 ) ;
if ( F_106 ( V_5 ) != V_212 ) {
V_5 -> V_50 . V_219 ++ ;
F_215 ( V_220 , 1 , NULL , 0 ) ;
}
F_158 ( V_5 , V_212 ) ;
}
unsigned long F_216 ( struct V_4 * V_5 , long V_221 )
{
unsigned long V_84 ;
int V_222 , V_206 ;
unsigned long V_223 ;
struct V_44 * V_44 ;
for (; ; ) {
V_44 = F_41 ( V_5 ) ;
while ( F_65 ( V_44 , V_5 ) ) {
if ( V_221 && F_35 ( V_5 -> V_213 != V_221 ) )
return 0 ;
F_217 () ;
}
V_44 = F_77 ( V_5 , & V_84 ) ;
F_218 ( V_5 ) ;
V_222 = F_65 ( V_44 , V_5 ) ;
V_206 = V_5 -> V_206 ;
V_223 = 0 ;
if ( ! V_221 || V_5 -> V_213 == V_221 )
V_223 = V_5 -> V_224 | V_225 ;
F_81 ( V_44 , V_5 , & V_84 ) ;
if ( F_35 ( ! V_223 ) )
break;
if ( F_35 ( V_222 ) ) {
F_217 () ;
continue;
}
if ( F_35 ( V_206 ) ) {
T_1 V_226 = F_219 ( 0 , V_175 / V_227 ) ;
F_220 ( V_228 ) ;
F_221 ( & V_226 , V_23 ) ;
continue;
}
break;
}
return V_223 ;
}
void F_222 ( struct V_4 * V_5 )
{
int V_45 ;
F_223 () ;
V_45 = F_106 ( V_5 ) ;
if ( ( V_45 != F_92 () ) && F_205 ( V_5 ) )
F_109 ( V_45 ) ;
F_224 () ;
}
static int F_225 ( int V_45 , struct V_4 * V_5 )
{
int V_229 ;
const struct V_230 * V_231 = F_226 ( F_227 ( V_45 ) ) ;
F_228 (dest_cpu, nodemask, cpu_active_mask)
if ( F_229 ( V_229 , F_230 ( V_5 ) ) )
return V_229 ;
V_229 = F_231 ( F_230 ( V_5 ) , V_232 ) ;
if ( V_229 < V_233 )
return V_229 ;
V_229 = F_232 ( V_5 ) ;
if ( V_5 -> V_234 && F_233 () ) {
F_234 ( V_235 L_5 ,
F_235 ( V_5 ) , V_5 -> V_236 , V_45 ) ;
}
return V_229 ;
}
static inline
int F_236 ( struct V_4 * V_5 , int V_237 , int V_238 )
{
int V_45 = V_5 -> V_87 -> F_236 ( V_5 , V_237 , V_238 ) ;
if ( F_35 ( ! F_229 ( V_45 , F_230 ( V_5 ) ) ||
! F_237 ( V_45 ) ) )
V_45 = F_225 ( F_106 ( V_5 ) , V_5 ) ;
return V_45 ;
}
static void F_238 ( T_2 * V_239 , T_2 V_240 )
{
T_3 V_241 = V_240 - * V_239 ;
* V_239 += V_241 >> 3 ;
}
static void
F_239 ( struct V_4 * V_5 , int V_45 , int V_238 )
{
#ifdef F_240
struct V_44 * V_44 = F_84 () ;
#ifdef F_38
int V_242 = F_92 () ;
if ( V_45 == V_242 ) {
F_241 ( V_44 , V_243 ) ;
F_241 ( V_5 , V_50 . V_244 . V_245 ) ;
} else {
struct V_110 * V_111 ;
F_241 ( V_5 , V_50 . V_244 . V_246 ) ;
F_114 () ;
F_115 (this_cpu, sd) {
if ( F_229 ( V_45 , F_242 ( V_111 ) ) ) {
F_241 ( V_111 , V_247 ) ;
break;
}
}
F_118 () ;
}
if ( V_238 & V_248 )
F_241 ( V_5 , V_50 . V_244 . V_249 ) ;
#endif
F_241 ( V_44 , V_250 ) ;
F_241 ( V_5 , V_50 . V_244 . V_251 ) ;
if ( V_238 & V_252 )
F_241 ( V_5 , V_50 . V_244 . V_253 ) ;
#endif
}
static void F_243 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_254 )
{
F_168 ( V_44 , V_5 , V_254 ) ;
V_5 -> V_206 = 1 ;
if ( V_5 -> V_84 & V_255 )
F_244 ( V_5 , F_37 ( V_44 ) ) ;
}
static void
F_245 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_238 )
{
F_246 ( V_5 , true ) ;
F_207 ( V_44 , V_5 , V_238 ) ;
V_5 -> V_213 = V_214 ;
#ifdef F_38
if ( V_5 -> V_87 -> V_256 )
V_5 -> V_87 -> V_256 ( V_44 , V_5 ) ;
if ( V_44 -> V_257 ) {
T_2 V_27 = V_44 -> clock - V_44 -> V_257 ;
T_2 F_142 = 2 * V_210 ;
if ( V_27 > F_142 )
V_44 -> V_258 = F_142 ;
else
F_238 ( & V_44 -> V_258 , V_27 ) ;
V_44 -> V_257 = 0 ;
}
#endif
}
static void
F_247 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_238 )
{
#ifdef F_38
if ( V_5 -> V_259 )
V_44 -> V_165 -- ;
#endif
F_243 ( V_44 , V_5 , V_260 | V_261 ) ;
F_245 ( V_44 , V_5 , V_238 ) ;
}
static int F_248 ( struct V_4 * V_5 , int V_238 )
{
struct V_44 * V_44 ;
int V_144 = 0 ;
V_44 = F_74 ( V_5 ) ;
if ( V_5 -> V_206 ) {
F_245 ( V_44 , V_5 , V_238 ) ;
V_144 = 1 ;
}
F_80 ( V_44 ) ;
return V_144 ;
}
static void F_249 ( void )
{
struct V_44 * V_44 = F_84 () ;
struct V_262 * V_263 = F_250 ( & V_44 -> V_264 ) ;
struct V_4 * V_5 ;
F_21 ( & V_44 -> V_37 ) ;
while ( V_263 ) {
V_5 = F_251 ( V_263 , struct V_4 , V_265 ) ;
V_263 = F_252 ( V_263 ) ;
F_247 ( V_44 , V_5 , 0 ) ;
}
F_22 ( & V_44 -> V_37 ) ;
}
void F_253 ( void )
{
if ( F_254 ( & F_84 () -> V_264 ) && ! F_120 () )
return;
F_255 () ;
F_249 () ;
if ( F_35 ( F_120 () && ! F_256 () ) ) {
F_84 () -> V_266 = 1 ;
F_257 ( V_267 ) ;
}
F_258 () ;
}
static void F_259 ( struct V_4 * V_5 , int V_45 )
{
if ( F_260 ( & V_5 -> V_265 , & F_51 ( V_45 ) -> V_264 ) )
F_109 ( V_45 ) ;
}
static int F_261 ( struct V_4 * V_5 , int V_238 )
{
struct V_44 * V_44 ;
int V_144 = 0 ;
V_44 = F_74 ( V_5 ) ;
if ( V_5 -> V_77 ) {
F_243 ( V_44 , V_5 , V_260 ) ;
F_245 ( V_44 , V_5 , V_238 ) ;
V_144 = 1 ;
}
F_80 ( V_44 ) ;
return V_144 ;
}
static void F_262 ( struct V_4 * V_5 , int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
#if F_191 ( F_38 )
if ( F_86 ( V_268 ) && V_45 != F_92 () ) {
F_47 ( V_45 ) ;
F_259 ( V_5 , V_45 ) ;
return;
}
#endif
F_21 ( & V_44 -> V_37 ) ;
F_247 ( V_44 , V_5 , 0 ) ;
F_22 ( & V_44 -> V_37 ) ;
}
static int
F_263 ( struct V_4 * V_5 , unsigned int V_213 , int V_238 )
{
unsigned long V_84 ;
int V_45 , V_269 = 0 ;
F_68 () ;
F_78 ( & V_5 -> V_49 , V_84 ) ;
if ( ! ( V_5 -> V_213 & V_213 ) )
goto V_145;
V_269 = 1 ;
V_45 = F_106 ( V_5 ) ;
if ( V_5 -> V_206 && F_248 ( V_5 , V_238 ) )
goto V_270;
#ifdef F_38
while ( V_5 -> V_77 ) {
#ifdef F_72
if ( F_261 ( V_5 , V_238 ) )
goto V_270;
#else
F_217 () ;
#endif
}
F_264 () ;
V_5 -> V_259 = ! ! F_169 ( V_5 ) ;
V_5 -> V_213 = V_215 ;
if ( V_5 -> V_87 -> V_271 )
V_5 -> V_87 -> V_271 ( V_5 ) ;
V_45 = F_236 ( V_5 , V_272 , V_238 ) ;
if ( F_106 ( V_5 ) != V_45 ) {
V_238 |= V_248 ;
F_211 ( V_5 , V_45 ) ;
}
#endif
F_262 ( V_5 , V_45 ) ;
V_270:
F_239 ( V_5 , V_45 , V_238 ) ;
V_145:
F_79 ( & V_5 -> V_49 , V_84 ) ;
return V_269 ;
}
static void F_265 ( struct V_4 * V_5 )
{
struct V_44 * V_44 = F_41 ( V_5 ) ;
F_152 ( V_44 != F_84 () ) ;
F_152 ( V_5 == V_81 ) ;
F_75 ( & V_44 -> V_37 ) ;
if ( ! F_148 ( & V_5 -> V_49 ) ) {
F_22 ( & V_44 -> V_37 ) ;
F_21 ( & V_5 -> V_49 ) ;
F_21 ( & V_44 -> V_37 ) ;
}
if ( ! ( V_5 -> V_213 & V_273 ) )
goto V_145;
if ( ! V_5 -> V_206 )
F_243 ( V_44 , V_5 , V_260 ) ;
F_245 ( V_44 , V_5 , 0 ) ;
F_239 ( V_5 , F_92 () , 0 ) ;
V_145:
F_22 ( & V_5 -> V_49 ) ;
}
int F_266 ( struct V_4 * V_5 )
{
return F_263 ( V_5 , V_274 , 0 ) ;
}
int F_267 ( struct V_4 * V_5 , unsigned int V_213 )
{
return F_263 ( V_5 , V_213 , 0 ) ;
}
static void F_268 ( struct V_4 * V_5 )
{
V_5 -> V_206 = 0 ;
V_5 -> V_50 . V_206 = 0 ;
V_5 -> V_50 . V_211 = 0 ;
V_5 -> V_50 . V_275 = 0 ;
V_5 -> V_50 . V_276 = 0 ;
V_5 -> V_50 . V_219 = 0 ;
V_5 -> V_50 . V_277 = 0 ;
F_32 ( & V_5 -> V_50 . V_278 ) ;
#ifdef F_240
memset ( & V_5 -> V_50 . V_244 , 0 , sizeof( V_5 -> V_50 . V_244 ) ) ;
#endif
F_32 ( & V_5 -> V_52 . V_279 ) ;
#ifdef F_269
F_270 ( & V_5 -> V_280 ) ;
#endif
}
void F_271 ( struct V_4 * V_5 )
{
unsigned long V_84 ;
int V_45 = F_272 () ;
F_268 ( V_5 ) ;
V_5 -> V_213 = V_214 ;
V_5 -> V_157 = V_81 -> F_202 ;
if ( F_35 ( V_5 -> V_281 ) ) {
if ( F_2 ( V_5 ) ) {
V_5 -> V_1 = V_282 ;
V_5 -> V_158 = F_273 ( 0 ) ;
V_5 -> V_199 = 0 ;
} else if ( F_274 ( V_5 -> V_158 ) < 0 )
V_5 -> V_158 = F_273 ( 0 ) ;
V_5 -> V_157 = V_5 -> F_202 = F_201 ( V_5 ) ;
F_162 ( V_5 ) ;
V_5 -> V_281 = 0 ;
}
if ( ! F_204 ( V_5 -> V_157 ) )
V_5 -> V_87 = & V_207 ;
if ( V_5 -> V_87 -> V_283 )
V_5 -> V_87 -> V_283 ( V_5 ) ;
F_78 ( & V_5 -> V_49 , V_84 ) ;
F_211 ( V_5 , V_45 ) ;
F_79 ( & V_5 -> V_49 , V_84 ) ;
#if F_191 ( F_240 ) || F_191 ( V_284 )
if ( F_76 ( F_275 () ) )
memset ( & V_5 -> V_285 , 0 , sizeof( V_5 -> V_285 ) ) ;
#endif
#if F_191 ( F_38 )
V_5 -> V_77 = 0 ;
#endif
#ifdef F_276
F_159 ( V_5 ) -> V_216 = 1 ;
#endif
#ifdef F_38
F_277 ( & V_5 -> V_286 , V_287 ) ;
#endif
F_278 () ;
}
void F_279 ( struct V_4 * V_5 )
{
unsigned long V_84 ;
struct V_44 * V_44 ;
F_78 ( & V_5 -> V_49 , V_84 ) ;
#ifdef F_38
F_211 ( V_5 , F_236 ( V_5 , V_288 , 0 ) ) ;
#endif
V_44 = F_74 ( V_5 ) ;
F_168 ( V_44 , V_5 , 0 ) ;
V_5 -> V_206 = 1 ;
F_280 ( V_5 , true ) ;
F_207 ( V_44 , V_5 , V_289 ) ;
#ifdef F_38
if ( V_5 -> V_87 -> V_256 )
V_5 -> V_87 -> V_256 ( V_44 , V_5 ) ;
#endif
F_81 ( V_44 , V_5 , & V_84 ) ;
}
void F_281 ( struct V_290 * V_291 )
{
F_282 ( & V_291 -> V_292 , & V_81 -> V_280 ) ;
}
void F_283 ( struct V_290 * V_291 )
{
F_284 ( & V_291 -> V_292 ) ;
}
static void F_285 ( struct V_4 * V_76 )
{
struct V_290 * V_291 ;
struct V_293 * V_294 ;
F_286 (notifier, node, &curr->preempt_notifiers, link)
V_291 -> V_295 -> V_296 ( V_291 , F_287 () ) ;
}
static void
F_288 ( struct V_4 * V_76 ,
struct V_4 * V_78 )
{
struct V_290 * V_291 ;
struct V_293 * V_294 ;
F_286 (notifier, node, &curr->preempt_notifiers, link)
V_291 -> V_295 -> V_297 ( V_291 , V_78 ) ;
}
static void F_285 ( struct V_4 * V_76 )
{
}
static void
F_288 ( struct V_4 * V_76 ,
struct V_4 * V_78 )
{
}
static inline void
F_289 ( struct V_44 * V_44 , struct V_4 * V_79 ,
struct V_4 * V_78 )
{
F_290 ( V_79 , V_78 ) ;
F_291 ( V_79 , V_78 ) ;
F_288 ( V_79 , V_78 ) ;
F_66 ( V_44 , V_78 ) ;
F_292 ( V_78 ) ;
F_293 ( V_79 , V_78 ) ;
}
static void F_294 ( struct V_44 * V_44 , struct V_4 * V_79 )
__releases( V_44 -> V_37 )
{
struct V_298 * V_234 = V_44 -> V_299 ;
long V_300 ;
V_44 -> V_299 = NULL ;
V_300 = V_79 -> V_213 ;
F_295 ( V_79 ) ;
#ifdef F_72
F_83 () ;
#endif
F_296 ( V_79 , V_81 ) ;
#ifdef F_72
F_73 () ;
#endif
F_67 ( V_44 , V_79 ) ;
F_285 ( V_81 ) ;
if ( V_234 )
F_297 ( V_234 ) ;
if ( F_35 ( V_300 == V_301 ) ) {
F_298 ( V_79 ) ;
F_299 ( V_79 ) ;
}
}
static inline void F_300 ( struct V_44 * V_44 , struct V_4 * V_79 )
{
if ( V_79 -> V_87 -> F_300 )
V_79 -> V_87 -> F_300 ( V_44 , V_79 ) ;
}
static inline void F_301 ( struct V_44 * V_44 )
{
if ( V_44 -> F_301 ) {
unsigned long V_84 ;
F_78 ( & V_44 -> V_37 , V_84 ) ;
if ( V_44 -> V_76 -> V_87 -> F_301 )
V_44 -> V_76 -> V_87 -> F_301 ( V_44 ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
V_44 -> F_301 = 0 ;
}
}
static inline void F_300 ( struct V_44 * V_44 , struct V_4 * V_5 )
{
}
static inline void F_301 ( struct V_44 * V_44 )
{
}
T_11 void F_302 ( struct V_4 * V_79 )
__releases( V_44 -> V_37 )
{
struct V_44 * V_44 = F_84 () ;
F_294 ( V_44 , V_79 ) ;
F_301 ( V_44 ) ;
#ifdef F_303
F_224 () ;
#endif
if ( V_81 -> V_302 )
F_304 ( F_305 ( V_81 ) , V_81 -> V_302 ) ;
}
static inline void
F_306 ( struct V_44 * V_44 , struct V_4 * V_79 ,
struct V_4 * V_78 )
{
struct V_298 * V_234 , * V_303 ;
F_289 ( V_44 , V_79 , V_78 ) ;
V_234 = V_78 -> V_234 ;
V_303 = V_79 -> V_304 ;
F_307 ( V_79 ) ;
if ( ! V_234 ) {
V_78 -> V_304 = V_303 ;
F_308 ( & V_303 -> V_305 ) ;
F_309 ( V_303 , V_78 ) ;
} else
F_310 ( V_303 , V_234 , V_78 ) ;
if ( ! V_79 -> V_234 ) {
V_79 -> V_304 = NULL ;
V_44 -> V_299 = V_303 ;
}
#ifndef F_303
F_311 ( & V_44 -> V_37 . V_82 , 1 , V_83 ) ;
#endif
F_312 ( V_79 , V_78 , V_79 ) ;
F_313 () ;
F_294 ( F_84 () , V_79 ) ;
}
unsigned long V_151 ( void )
{
unsigned long V_59 , V_306 = 0 ;
F_314 (i)
V_306 += F_51 ( V_59 ) -> V_151 ;
return V_306 ;
}
unsigned long V_165 ( void )
{
unsigned long V_59 , V_306 = 0 ;
F_315 (i)
V_306 += F_51 ( V_59 ) -> V_165 ;
if ( F_35 ( ( long ) V_306 < 0 ) )
V_306 = 0 ;
return V_306 ;
}
unsigned long long F_316 ( void )
{
int V_59 ;
unsigned long long V_306 = 0 ;
F_315 (i)
V_306 += F_51 ( V_59 ) -> V_307 ;
return V_306 ;
}
unsigned long F_317 ( void )
{
unsigned long V_59 , V_306 = 0 ;
F_315 (i)
V_306 += F_318 ( & F_51 ( V_59 ) -> F_317 ) ;
return V_306 ;
}
unsigned long F_319 ( int V_45 )
{
struct V_44 * V_308 = F_51 ( V_45 ) ;
return F_318 ( & V_308 -> F_317 ) ;
}
unsigned long F_320 ( void )
{
struct V_44 * V_308 = F_84 () ;
return V_308 -> V_149 [ 0 ] ;
}
static long F_321 ( struct V_44 * F_84 )
{
long V_309 , V_27 = 0 ;
V_309 = F_84 -> V_151 ;
V_309 += ( long ) F_84 -> V_165 ;
if ( V_309 != F_84 -> V_310 ) {
V_27 = V_309 - F_84 -> V_310 ;
F_84 -> V_310 = V_309 ;
}
return V_27 ;
}
static unsigned long
F_322 ( unsigned long V_138 , unsigned long exp , unsigned long V_311 )
{
V_138 *= exp ;
V_138 += V_311 * ( V_312 - exp ) ;
V_138 += 1UL << ( V_313 - 1 ) ;
return V_138 >> V_313 ;
}
static void F_323 ( struct V_44 * F_84 )
{
long V_27 ;
V_27 = F_321 ( F_84 ) ;
if ( V_27 )
F_324 ( V_27 , & V_314 ) ;
}
static long F_325 ( void )
{
long V_27 = 0 ;
if ( F_326 ( & V_314 ) )
V_27 = F_327 ( & V_314 , 0 ) ;
return V_27 ;
}
static unsigned long
F_328 ( unsigned long V_315 , unsigned int V_316 , unsigned int V_317 )
{
unsigned long V_318 = 1UL << V_316 ;
if ( V_317 ) for (; ; ) {
if ( V_317 & 1 ) {
V_318 *= V_315 ;
V_318 += 1UL << ( V_316 - 1 ) ;
V_318 >>= V_316 ;
}
V_317 >>= 1 ;
if ( ! V_317 )
break;
V_315 *= V_315 ;
V_315 += 1UL << ( V_316 - 1 ) ;
V_315 >>= V_316 ;
}
return V_318 ;
}
static unsigned long
F_329 ( unsigned long V_138 , unsigned long exp ,
unsigned long V_311 , unsigned int V_317 )
{
return F_322 ( V_138 , F_328 ( exp , V_313 , V_317 ) , V_311 ) ;
}
static void F_330 ( unsigned long V_319 )
{
long V_27 , V_311 , V_317 ;
if ( F_331 ( V_320 , V_321 ) )
return;
V_27 = F_325 () ;
if ( V_27 )
F_324 ( V_27 , & V_322 ) ;
if ( V_319 >= V_323 ) {
V_317 = V_319 / V_323 ;
V_311 = F_326 ( & V_322 ) ;
V_311 = V_311 > 0 ? V_311 * V_312 : 0 ;
V_324 [ 0 ] = F_329 ( V_324 [ 0 ] , V_325 , V_311 , V_317 ) ;
V_324 [ 1 ] = F_329 ( V_324 [ 1 ] , V_326 , V_311 , V_317 ) ;
V_324 [ 2 ] = F_329 ( V_324 [ 2 ] , V_327 , V_311 , V_317 ) ;
V_321 += V_317 * V_323 ;
}
}
static void F_323 ( struct V_44 * F_84 )
{
}
static inline long F_325 ( void )
{
return 0 ;
}
static void F_330 ( unsigned long V_319 )
{
}
void F_332 ( unsigned long * V_328 , unsigned long V_329 , int V_330 )
{
V_328 [ 0 ] = ( V_324 [ 0 ] + V_329 ) << V_330 ;
V_328 [ 1 ] = ( V_324 [ 1 ] + V_329 ) << V_330 ;
V_328 [ 2 ] = ( V_324 [ 2 ] + V_329 ) << V_330 ;
}
void F_333 ( unsigned long V_319 )
{
long V_311 ;
F_330 ( V_319 ) ;
if ( F_331 ( V_320 , V_321 + 10 ) )
return;
V_311 = F_326 ( & V_322 ) ;
V_311 = V_311 > 0 ? V_311 * V_312 : 0 ;
V_324 [ 0 ] = F_322 ( V_324 [ 0 ] , V_325 , V_311 ) ;
V_324 [ 1 ] = F_322 ( V_324 [ 1 ] , V_326 , V_311 ) ;
V_324 [ 2 ] = F_322 ( V_324 [ 2 ] , V_327 , V_311 ) ;
V_321 += V_323 ;
}
static void F_334 ( struct V_44 * F_84 )
{
long V_27 ;
if ( F_331 ( V_320 , F_84 -> V_321 ) )
return;
V_27 = F_321 ( F_84 ) ;
V_27 += F_325 () ;
if ( V_27 )
F_324 ( V_27 , & V_322 ) ;
F_84 -> V_321 += V_323 ;
}
static unsigned long
F_335 ( unsigned long V_138 , unsigned long V_331 , int V_136 )
{
int V_332 = 0 ;
if ( ! V_331 )
return V_138 ;
if ( V_331 >= V_333 [ V_136 ] )
return 0 ;
if ( V_136 == 1 )
return V_138 >> V_331 ;
while ( V_331 ) {
if ( V_331 % 2 )
V_138 = ( V_138 * V_334 [ V_136 ] [ V_332 ] ) >> V_335 ;
V_331 >>= 1 ;
V_332 ++ ;
}
return V_138 ;
}
static void F_336 ( struct V_44 * F_84 )
{
unsigned long V_336 = F_84 -> V_138 . V_120 ;
unsigned long V_337 = V_320 ;
unsigned long V_338 ;
int V_59 , V_339 ;
F_84 -> V_340 ++ ;
if ( V_337 == F_84 -> V_341 )
return;
V_338 = V_337 - F_84 -> V_341 ;
F_84 -> V_341 = V_337 ;
F_84 -> V_149 [ 0 ] = V_336 ;
for ( V_59 = 1 , V_339 = 2 ; V_59 < V_342 ; V_59 ++ , V_339 += V_339 ) {
unsigned long V_343 , V_344 ;
V_343 = F_84 -> V_149 [ V_59 ] ;
V_343 = F_335 ( V_343 , V_338 - 1 , V_59 ) ;
V_344 = V_336 ;
if ( V_344 > V_343 )
V_344 += V_339 - 1 ;
F_84 -> V_149 [ V_59 ] = ( V_343 * ( V_339 - 1 ) + V_344 ) >> V_59 ;
}
F_122 ( F_84 ) ;
}
static void F_337 ( struct V_44 * F_84 )
{
F_336 ( F_84 ) ;
F_334 ( F_84 ) ;
}
void F_338 ( void )
{
struct V_4 * V_5 = V_81 ;
unsigned long V_84 ;
int V_229 ;
F_78 ( & V_5 -> V_49 , V_84 ) ;
V_229 = V_5 -> V_87 -> F_236 ( V_5 , V_345 , 0 ) ;
if ( V_229 == F_92 () )
goto V_112;
if ( F_76 ( F_87 ( V_229 ) ) ) {
struct V_346 V_89 = { V_5 , V_229 } ;
F_79 ( & V_5 -> V_49 , V_84 ) ;
F_339 ( F_106 ( V_5 ) , V_347 , & V_89 ) ;
return;
}
V_112:
F_79 ( & V_5 -> V_49 , V_84 ) ;
}
static T_2 F_340 ( struct V_4 * V_5 , struct V_44 * V_44 )
{
T_2 V_348 = 0 ;
if ( F_64 ( V_44 , V_5 ) ) {
F_46 ( V_44 ) ;
V_348 = V_44 -> V_184 - V_5 -> V_50 . V_211 ;
if ( ( T_3 ) V_348 < 0 )
V_348 = 0 ;
}
return V_348 ;
}
unsigned long long F_341 ( struct V_4 * V_5 )
{
unsigned long V_84 ;
struct V_44 * V_44 ;
T_2 V_348 = 0 ;
V_44 = F_77 ( V_5 , & V_84 ) ;
V_348 = F_340 ( V_5 , V_44 ) ;
F_81 ( V_44 , V_5 , & V_84 ) ;
return V_348 ;
}
unsigned long long F_342 ( struct V_4 * V_5 )
{
unsigned long V_84 ;
struct V_44 * V_44 ;
T_2 V_348 = 0 ;
V_44 = F_77 ( V_5 , & V_84 ) ;
V_348 = V_5 -> V_50 . V_275 + F_340 ( V_5 , V_44 ) ;
F_81 ( V_44 , V_5 , & V_84 ) ;
return V_348 ;
}
void F_343 ( struct V_4 * V_5 , T_9 V_134 ,
T_9 V_349 )
{
struct V_186 * V_187 = & V_188 . V_187 ;
T_12 V_123 ;
V_5 -> V_350 = F_344 ( V_5 -> V_350 , V_134 ) ;
V_5 -> V_351 = F_344 ( V_5 -> V_351 , V_349 ) ;
F_345 ( V_5 , V_134 ) ;
V_123 = F_346 ( V_134 ) ;
if ( F_347 ( V_5 ) > 0 )
V_187 -> V_352 = F_348 ( V_187 -> V_352 , V_123 ) ;
else
V_187 -> V_353 = F_348 ( V_187 -> V_353 , V_123 ) ;
F_132 ( V_5 , V_354 , V_134 ) ;
F_349 ( V_5 ) ;
}
static void F_350 ( struct V_4 * V_5 , T_9 V_134 ,
T_9 V_349 )
{
T_12 V_123 ;
struct V_186 * V_187 = & V_188 . V_187 ;
V_123 = F_346 ( V_134 ) ;
V_5 -> V_350 = F_344 ( V_5 -> V_350 , V_134 ) ;
V_5 -> V_351 = F_344 ( V_5 -> V_351 , V_349 ) ;
F_345 ( V_5 , V_134 ) ;
V_5 -> V_355 = F_344 ( V_5 -> V_355 , V_134 ) ;
if ( F_347 ( V_5 ) > 0 ) {
V_187 -> V_352 = F_348 ( V_187 -> V_352 , V_123 ) ;
V_187 -> V_356 = F_348 ( V_187 -> V_356 , V_123 ) ;
} else {
V_187 -> V_353 = F_348 ( V_187 -> V_353 , V_123 ) ;
V_187 -> V_357 = F_348 ( V_187 -> V_357 , V_123 ) ;
}
}
static inline
void F_351 ( struct V_4 * V_5 , T_9 V_134 ,
T_9 V_349 , T_12 * V_358 )
{
T_12 V_123 = F_346 ( V_134 ) ;
V_5 -> V_359 = F_344 ( V_5 -> V_359 , V_134 ) ;
V_5 -> V_360 = F_344 ( V_5 -> V_360 , V_349 ) ;
F_352 ( V_5 , V_134 ) ;
* V_358 = F_348 ( * V_358 , V_123 ) ;
F_132 ( V_5 , V_361 , V_134 ) ;
F_349 ( V_5 ) ;
}
void F_353 ( struct V_4 * V_5 , int V_362 ,
T_9 V_134 , T_9 V_349 )
{
struct V_186 * V_187 = & V_188 . V_187 ;
T_12 * V_358 ;
if ( ( V_5 -> V_84 & V_363 ) && ( F_354 () - V_362 == 0 ) ) {
F_350 ( V_5 , V_134 , V_349 ) ;
return;
}
if ( F_184 () - V_362 )
V_358 = & V_187 -> V_190 ;
else if ( F_185 () )
V_358 = & V_187 -> V_191 ;
else
V_358 = & V_187 -> system ;
F_351 ( V_5 , V_134 , V_349 , V_358 ) ;
}
void F_355 ( T_9 V_134 )
{
struct V_186 * V_187 = & V_188 . V_187 ;
T_12 V_364 = F_346 ( V_134 ) ;
V_187 -> V_174 = F_348 ( V_187 -> V_174 , V_364 ) ;
}
void F_356 ( T_9 V_134 )
{
struct V_186 * V_187 = & V_188 . V_187 ;
T_12 V_364 = F_346 ( V_134 ) ;
struct V_44 * V_44 = F_84 () ;
if ( F_318 ( & V_44 -> F_317 ) > 0 )
V_187 -> V_365 = F_348 ( V_187 -> V_365 , V_364 ) ;
else
V_187 -> V_14 = F_348 ( V_187 -> V_14 , V_364 ) ;
}
static T_13 bool F_357 ( void )
{
#ifdef F_358
if ( F_192 ( & V_366 ) ) {
T_2 V_174 , V_182 = 0 ;
V_174 = F_193 ( F_92 () ) ;
V_174 -= F_84 () -> V_367 ;
V_182 = F_188 ( V_174 ) ;
F_84 () -> V_367 += V_182 * V_176 ;
F_355 ( V_182 ) ;
return V_182 ;
}
#endif
return false ;
}
static void F_359 ( struct V_4 * V_5 , int V_368 ,
struct V_44 * V_44 )
{
T_9 V_369 = F_360 ( V_370 ) ;
T_12 V_123 = F_346 ( V_370 ) ;
struct V_186 * V_187 = & V_188 . V_187 ;
if ( F_357 () )
return;
if ( F_194 () ) {
V_187 -> V_190 = F_348 ( V_187 -> V_190 , V_123 ) ;
} else if ( F_198 () ) {
V_187 -> V_191 = F_348 ( V_187 -> V_191 , V_123 ) ;
} else if ( F_186 () == V_5 ) {
F_351 ( V_5 , V_370 , V_369 ,
& V_187 -> V_191 ) ;
} else if ( V_368 ) {
F_343 ( V_5 , V_370 , V_369 ) ;
} else if ( V_5 == V_44 -> V_14 ) {
F_356 ( V_370 ) ;
} else if ( V_5 -> V_84 & V_363 ) {
F_350 ( V_5 , V_370 , V_369 ) ;
} else {
F_351 ( V_5 , V_370 , V_369 ,
& V_187 -> system ) ;
}
}
static void F_361 ( int V_319 )
{
int V_59 ;
struct V_44 * V_44 = F_84 () ;
for ( V_59 = 0 ; V_59 < V_319 ; V_59 ++ )
F_359 ( V_81 , 0 , V_44 ) ;
}
static void F_361 ( int V_319 ) {}
static void F_359 ( struct V_4 * V_5 , int V_368 ,
struct V_44 * V_44 ) {}
void F_362 ( struct V_4 * V_5 , int V_368 )
{
T_9 V_369 = F_360 ( V_370 ) ;
struct V_44 * V_44 = F_84 () ;
if ( V_166 ) {
F_359 ( V_5 , V_368 , V_44 ) ;
return;
}
if ( F_357 () )
return;
if ( V_368 )
F_343 ( V_5 , V_370 , V_369 ) ;
else if ( ( V_5 != V_44 -> V_14 ) || ( F_354 () != V_371 ) )
F_353 ( V_5 , V_371 , V_370 ,
V_369 ) ;
else
F_356 ( V_370 ) ;
}
void F_363 ( unsigned long V_319 )
{
F_355 ( F_364 ( V_319 ) ) ;
}
void F_365 ( unsigned long V_319 )
{
if ( V_166 ) {
F_361 ( V_319 ) ;
return;
}
F_356 ( F_364 ( V_319 ) ) ;
}
void F_366 ( struct V_4 * V_5 , T_9 * V_372 , T_9 * V_182 )
{
* V_372 = V_5 -> V_350 ;
* V_182 = V_5 -> V_359 ;
}
void F_367 ( struct V_4 * V_5 , T_9 * V_372 , T_9 * V_182 )
{
struct V_373 V_134 ;
F_368 ( V_5 , & V_134 ) ;
* V_372 = V_134 . V_350 ;
* V_182 = V_134 . V_359 ;
}
void F_366 ( struct V_4 * V_5 , T_9 * V_372 , T_9 * V_182 )
{
T_9 V_374 , V_350 = V_5 -> V_350 , V_147 = F_344 ( V_350 , V_5 -> V_359 ) ;
V_374 = F_369 ( V_5 -> V_50 . V_275 ) ;
if ( V_147 ) {
T_2 V_375 = V_374 ;
V_375 *= V_350 ;
F_370 ( V_375 , V_147 ) ;
V_350 = ( T_9 ) V_375 ;
} else
V_350 = V_374 ;
V_5 -> V_376 = F_142 ( V_5 -> V_376 , V_350 ) ;
V_5 -> V_377 = F_142 ( V_5 -> V_377 , F_371 ( V_374 , V_5 -> V_376 ) ) ;
* V_372 = V_5 -> V_376 ;
* V_182 = V_5 -> V_377 ;
}
void F_367 ( struct V_4 * V_5 , T_9 * V_372 , T_9 * V_182 )
{
struct V_378 * V_379 = V_5 -> signal ;
struct V_373 V_134 ;
T_9 V_374 , V_350 , V_147 ;
F_368 ( V_5 , & V_134 ) ;
V_147 = F_344 ( V_134 . V_350 , V_134 . V_359 ) ;
V_374 = F_369 ( V_134 . V_275 ) ;
if ( V_147 ) {
T_2 V_375 = V_374 ;
V_375 *= V_134 . V_350 ;
F_370 ( V_375 , V_147 ) ;
V_350 = ( T_9 ) V_375 ;
} else
V_350 = V_374 ;
V_379 -> V_376 = F_142 ( V_379 -> V_376 , V_350 ) ;
V_379 -> V_377 = F_142 ( V_379 -> V_377 ,
F_371 ( V_374 , V_379 -> V_376 ) ) ;
* V_372 = V_379 -> V_376 ;
* V_182 = V_379 -> V_377 ;
}
void F_372 ( void )
{
int V_45 = F_92 () ;
struct V_44 * V_44 = F_51 ( V_45 ) ;
struct V_4 * V_76 = V_44 -> V_76 ;
F_373 () ;
F_21 ( & V_44 -> V_37 ) ;
F_46 ( V_44 ) ;
F_337 ( V_44 ) ;
V_76 -> V_87 -> V_88 ( V_44 , V_76 , 0 ) ;
F_22 ( & V_44 -> V_37 ) ;
F_374 () ;
#ifdef F_38
V_44 -> V_266 = F_117 ( V_45 ) ;
F_375 ( V_44 , V_45 ) ;
#endif
}
T_14 unsigned long F_376 ( unsigned long V_380 )
{
if ( F_377 ( V_380 ) ) {
V_380 = V_381 ;
if ( F_377 ( V_380 ) )
V_380 = V_382 ;
}
return V_380 ;
}
void T_15 F_378 ( int V_137 )
{
#ifdef F_379
if ( F_380 ( ( V_216 () < 0 ) ) )
return;
#endif
V_216 () += V_137 ;
#ifdef F_379
F_380 ( ( V_216 () & V_383 ) >=
V_383 - 10 ) ;
#endif
if ( V_216 () == V_137 )
F_381 ( V_384 , F_376 ( V_385 ) ) ;
}
void T_15 F_382 ( int V_137 )
{
#ifdef F_379
if ( F_380 ( V_137 > V_216 () ) )
return;
if ( F_380 ( ( V_137 < V_383 ) &&
! ( V_216 () & V_383 ) ) )
return;
#endif
if ( V_216 () == V_137 )
F_383 ( V_384 , F_376 ( V_385 ) ) ;
V_216 () -= V_137 ;
}
static T_16 void F_384 ( struct V_4 * V_79 )
{
struct V_386 * V_387 = F_385 () ;
F_234 ( V_388 L_6 ,
V_79 -> V_236 , V_79 -> V_389 , V_216 () ) ;
F_386 ( V_79 ) ;
F_387 () ;
if ( F_151 () )
F_388 ( V_79 ) ;
if ( V_387 )
F_389 ( V_387 ) ;
else
F_390 () ;
}
static inline void F_391 ( struct V_4 * V_79 )
{
if ( F_35 ( F_392 () && ! V_79 -> V_390 ) )
F_384 ( V_79 ) ;
F_393 () ;
F_394 ( V_391 , F_395 ( 0 ) ) ;
F_241 ( F_84 () , V_392 ) ;
}
static void F_396 ( struct V_44 * V_44 , struct V_4 * V_79 )
{
if ( V_79 -> V_206 || V_44 -> V_55 < 0 )
F_46 ( V_44 ) ;
V_79 -> V_87 -> F_396 ( V_44 , V_79 ) ;
}
static inline struct V_4 *
F_397 ( struct V_44 * V_44 )
{
const struct V_87 * V_205 ;
struct V_4 * V_5 ;
if ( F_76 ( V_44 -> V_151 == V_44 -> V_393 . V_394 ) ) {
V_5 = V_207 . F_397 ( V_44 ) ;
if ( F_76 ( V_5 ) )
return V_5 ;
}
F_208 (class) {
V_5 = V_205 -> F_397 ( V_44 ) ;
if ( V_5 )
return V_5 ;
}
F_398 () ;
}
static void T_17 F_399 ( void )
{
struct V_4 * V_79 , * V_78 ;
unsigned long * V_395 ;
struct V_44 * V_44 ;
int V_45 ;
F_256:
F_223 () ;
V_45 = F_92 () ;
V_44 = F_51 ( V_45 ) ;
F_400 ( V_45 ) ;
V_79 = V_44 -> V_76 ;
F_391 ( V_79 ) ;
if ( F_86 ( V_85 ) )
F_89 ( V_44 ) ;
F_401 ( & V_44 -> V_37 ) ;
V_395 = & V_79 -> V_396 ;
if ( V_79 -> V_213 && ! ( V_216 () & V_217 ) ) {
if ( F_35 ( F_402 ( V_79 -> V_213 , V_79 ) ) ) {
V_79 -> V_213 = V_214 ;
} else {
F_170 ( V_44 , V_79 , V_397 ) ;
V_79 -> V_206 = 0 ;
if ( V_79 -> V_84 & V_255 ) {
struct V_4 * V_398 ;
V_398 = F_403 ( V_79 , V_45 ) ;
if ( V_398 )
F_265 ( V_398 ) ;
}
}
V_395 = & V_79 -> V_224 ;
}
F_300 ( V_44 , V_79 ) ;
if ( F_35 ( ! V_44 -> V_151 ) )
V_266 ( V_45 , V_44 ) ;
F_396 ( V_44 , V_79 ) ;
V_78 = F_397 ( V_44 ) ;
F_404 ( V_79 ) ;
V_44 -> V_55 = 0 ;
if ( F_76 ( V_79 != V_78 ) ) {
V_44 -> V_307 ++ ;
V_44 -> V_76 = V_78 ;
++ * V_395 ;
F_306 ( V_44 , V_79 , V_78 ) ;
V_45 = F_92 () ;
V_44 = F_51 ( V_45 ) ;
} else
F_71 ( & V_44 -> V_37 ) ;
F_301 ( V_44 ) ;
F_405 () ;
if ( F_256 () )
goto F_256;
}
static inline void F_406 ( struct V_4 * V_133 )
{
if ( ! V_133 -> V_213 )
return;
if ( F_407 ( V_133 ) )
F_408 ( V_133 ) ;
}
T_11 void T_17 F_409 ( void )
{
struct V_4 * V_133 = V_81 ;
F_406 ( V_133 ) ;
F_399 () ;
}
static inline bool F_410 ( struct V_399 * V_37 , struct V_4 * V_80 )
{
if ( V_37 -> V_80 != V_80 )
return false ;
F_313 () ;
return V_80 -> V_77 ;
}
int F_411 ( struct V_399 * V_37 , struct V_4 * V_80 )
{
if ( ! F_86 ( V_400 ) )
return 0 ;
F_114 () ;
while ( F_410 ( V_37 , V_80 ) ) {
if ( F_256 () )
break;
F_412 () ;
}
F_118 () ;
return V_37 -> V_80 == NULL ;
}
T_11 void T_17 T_14 F_413 ( void )
{
struct V_401 * V_402 = F_414 () ;
if ( F_76 ( V_402 -> V_216 || F_151 () ) )
return;
do {
F_415 ( V_217 ) ;
F_399 () ;
F_416 ( V_217 ) ;
F_313 () ;
} while ( F_256 () );
}
T_11 void T_17 F_417 ( void )
{
struct V_401 * V_402 = F_414 () ;
F_152 ( V_402 -> V_216 || ! F_151 () ) ;
do {
F_378 ( V_217 ) ;
F_73 () ;
F_399 () ;
F_83 () ;
F_382 ( V_217 ) ;
F_313 () ;
} while ( F_256 () );
}
int F_418 ( T_18 * V_76 , unsigned V_403 , int V_238 ,
void * V_404 )
{
return F_263 ( V_76 -> V_405 , V_403 , V_238 ) ;
}
static void F_419 ( T_19 * V_406 , unsigned int V_403 ,
int V_407 , int V_238 , void * V_404 )
{
T_18 * V_76 , * V_78 ;
F_420 (curr, next, &q->task_list, task_list) {
unsigned V_84 = V_76 -> V_84 ;
if ( V_76 -> V_108 ( V_76 , V_403 , V_238 , V_404 ) &&
( V_84 & V_408 ) && ! -- V_407 )
break;
}
}
void F_421 ( T_19 * V_406 , unsigned int V_403 ,
int V_407 , void * V_404 )
{
unsigned long V_84 ;
F_422 ( & V_406 -> V_37 , V_84 ) ;
F_419 ( V_406 , V_403 , V_407 , 0 , V_404 ) ;
F_423 ( & V_406 -> V_37 , V_84 ) ;
}
void F_424 ( T_19 * V_406 , unsigned int V_403 )
{
F_419 ( V_406 , V_403 , 1 , 0 , NULL ) ;
}
void F_425 ( T_19 * V_406 , unsigned int V_403 , void * V_404 )
{
F_419 ( V_406 , V_403 , 1 , 0 , V_404 ) ;
}
void F_426 ( T_19 * V_406 , unsigned int V_403 ,
int V_407 , void * V_404 )
{
unsigned long V_84 ;
int V_238 = V_252 ;
if ( F_35 ( ! V_406 ) )
return;
if ( F_35 ( ! V_407 ) )
V_238 = 0 ;
F_422 ( & V_406 -> V_37 , V_84 ) ;
F_419 ( V_406 , V_403 , V_407 , V_238 , V_404 ) ;
F_423 ( & V_406 -> V_37 , V_84 ) ;
}
void F_427 ( T_19 * V_406 , unsigned int V_403 , int V_407 )
{
F_426 ( V_406 , V_403 , V_407 , NULL ) ;
}
void F_428 ( struct V_409 * V_315 )
{
unsigned long V_84 ;
F_422 ( & V_315 -> V_410 . V_37 , V_84 ) ;
V_315 -> V_411 ++ ;
F_419 ( & V_315 -> V_410 , V_273 , 1 , 0 , NULL ) ;
F_423 ( & V_315 -> V_410 . V_37 , V_84 ) ;
}
void F_429 ( struct V_409 * V_315 )
{
unsigned long V_84 ;
F_422 ( & V_315 -> V_410 . V_37 , V_84 ) ;
V_315 -> V_411 += V_412 / 2 ;
F_419 ( & V_315 -> V_410 , V_273 , 0 , 0 , NULL ) ;
F_423 ( & V_315 -> V_410 . V_37 , V_84 ) ;
}
static inline long T_17
F_430 ( struct V_409 * V_315 , long V_413 , int V_213 )
{
if ( ! V_315 -> V_411 ) {
F_431 ( V_410 , V_81 ) ;
F_432 ( & V_315 -> V_410 , & V_410 ) ;
do {
if ( F_402 ( V_213 , V_81 ) ) {
V_413 = - V_414 ;
break;
}
F_433 ( V_213 ) ;
F_434 ( & V_315 -> V_410 . V_37 ) ;
V_413 = F_435 ( V_413 ) ;
F_436 ( & V_315 -> V_410 . V_37 ) ;
} while ( ! V_315 -> V_411 && V_413 );
F_437 ( & V_315 -> V_410 , & V_410 ) ;
if ( ! V_315 -> V_411 )
return V_413 ;
}
V_315 -> V_411 -- ;
return V_413 ? : 1 ;
}
static long T_17
F_438 ( struct V_409 * V_315 , long V_413 , int V_213 )
{
F_439 () ;
F_436 ( & V_315 -> V_410 . V_37 ) ;
V_413 = F_430 ( V_315 , V_413 , V_213 ) ;
F_434 ( & V_315 -> V_410 . V_37 ) ;
return V_413 ;
}
void T_17 F_440 ( struct V_409 * V_315 )
{
F_438 ( V_315 , V_415 , V_228 ) ;
}
unsigned long T_17
F_441 ( struct V_409 * V_315 , unsigned long V_413 )
{
return F_438 ( V_315 , V_413 , V_228 ) ;
}
int T_17 F_442 ( struct V_409 * V_315 )
{
long V_416 = F_438 ( V_315 , V_415 , V_417 ) ;
if ( V_416 == - V_414 )
return V_416 ;
return 0 ;
}
long T_17
F_443 ( struct V_409 * V_315 ,
unsigned long V_413 )
{
return F_438 ( V_315 , V_413 , V_417 ) ;
}
int T_17 F_444 ( struct V_409 * V_315 )
{
long V_416 = F_438 ( V_315 , V_415 , V_418 ) ;
if ( V_416 == - V_414 )
return V_416 ;
return 0 ;
}
long T_17
F_445 ( struct V_409 * V_315 ,
unsigned long V_413 )
{
return F_438 ( V_315 , V_413 , V_418 ) ;
}
bool F_446 ( struct V_409 * V_315 )
{
unsigned long V_84 ;
int V_144 = 1 ;
F_422 ( & V_315 -> V_410 . V_37 , V_84 ) ;
if ( ! V_315 -> V_411 )
V_144 = 0 ;
else
V_315 -> V_411 -- ;
F_423 ( & V_315 -> V_410 . V_37 , V_84 ) ;
return V_144 ;
}
bool F_447 ( struct V_409 * V_315 )
{
unsigned long V_84 ;
int V_144 = 1 ;
F_422 ( & V_315 -> V_410 . V_37 , V_84 ) ;
if ( ! V_315 -> V_411 )
V_144 = 0 ;
F_423 ( & V_315 -> V_410 . V_37 , V_84 ) ;
return V_144 ;
}
static long T_17
F_448 ( T_19 * V_406 , int V_213 , long V_413 )
{
unsigned long V_84 ;
T_18 V_410 ;
F_449 ( & V_410 , V_81 ) ;
F_433 ( V_213 ) ;
F_422 ( & V_406 -> V_37 , V_84 ) ;
F_450 ( V_406 , & V_410 ) ;
F_451 ( & V_406 -> V_37 ) ;
V_413 = F_435 ( V_413 ) ;
F_436 ( & V_406 -> V_37 ) ;
F_437 ( V_406 , & V_410 ) ;
F_423 ( & V_406 -> V_37 , V_84 ) ;
return V_413 ;
}
void T_17 F_452 ( T_19 * V_406 )
{
F_448 ( V_406 , V_417 , V_415 ) ;
}
long T_17
F_453 ( T_19 * V_406 , long V_413 )
{
return F_448 ( V_406 , V_417 , V_413 ) ;
}
void T_17 F_454 ( T_19 * V_406 )
{
F_448 ( V_406 , V_228 , V_415 ) ;
}
long T_17 F_455 ( T_19 * V_406 , long V_413 )
{
return F_448 ( V_406 , V_228 , V_413 ) ;
}
void F_456 ( struct V_4 * V_5 , int V_157 )
{
int V_201 , V_206 , V_222 ;
struct V_44 * V_44 ;
const struct V_87 * V_200 ;
F_152 ( V_157 < 0 || V_157 > V_287 ) ;
V_44 = F_74 ( V_5 ) ;
F_457 ( V_5 , V_157 ) ;
V_201 = V_5 -> V_157 ;
V_200 = V_5 -> V_87 ;
V_206 = V_5 -> V_206 ;
V_222 = F_64 ( V_44 , V_5 ) ;
if ( V_206 )
F_166 ( V_44 , V_5 , 0 ) ;
if ( V_222 )
V_5 -> V_87 -> F_396 ( V_44 , V_5 ) ;
if ( F_204 ( V_157 ) )
V_5 -> V_87 = & V_198 ;
else
V_5 -> V_87 = & V_207 ;
V_5 -> V_157 = V_157 ;
if ( V_222 )
V_5 -> V_87 -> V_419 ( V_44 ) ;
if ( V_206 )
F_164 ( V_44 , V_5 , V_201 < V_157 ? V_420 : 0 ) ;
F_206 ( V_44 , V_5 , V_200 , V_201 ) ;
F_80 ( V_44 ) ;
}
void F_458 ( struct V_4 * V_5 , long V_352 )
{
int V_421 , V_27 , V_206 ;
unsigned long V_84 ;
struct V_44 * V_44 ;
if ( F_347 ( V_5 ) == V_352 || V_352 < - 20 || V_352 > 19 )
return;
V_44 = F_77 ( V_5 , & V_84 ) ;
if ( F_2 ( V_5 ) ) {
V_5 -> V_158 = F_273 ( V_352 ) ;
goto V_422;
}
V_206 = V_5 -> V_206 ;
if ( V_206 )
F_166 ( V_44 , V_5 , 0 ) ;
V_5 -> V_158 = F_273 ( V_352 ) ;
F_162 ( V_5 ) ;
V_421 = V_5 -> V_157 ;
V_5 -> V_157 = F_203 ( V_5 ) ;
V_27 = V_5 -> V_157 - V_421 ;
if ( V_206 ) {
F_164 ( V_44 , V_5 , 0 ) ;
if ( V_27 < 0 || ( V_27 > 0 && F_65 ( V_44 , V_5 ) ) )
F_102 ( V_44 -> V_76 ) ;
}
V_422:
F_81 ( V_44 , V_5 , & V_84 ) ;
}
int F_459 ( const struct V_4 * V_5 , const int V_352 )
{
int V_423 = 20 - V_352 ;
return ( V_423 <= F_460 ( V_5 , V_424 ) ||
F_461 ( V_425 ) ) ;
}
int F_462 ( const struct V_4 * V_5 )
{
return V_5 -> V_157 - V_159 ;
}
int F_463 ( const struct V_4 * V_5 )
{
return F_347 ( V_5 ) ;
}
int F_117 ( int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
if ( V_44 -> V_76 != V_44 -> V_14 )
return 0 ;
if ( V_44 -> V_151 )
return 0 ;
#ifdef F_38
if ( ! F_254 ( & V_44 -> V_264 ) )
return 0 ;
#endif
return 1 ;
}
struct V_4 * F_464 ( int V_45 )
{
return F_51 ( V_45 ) -> V_14 ;
}
static struct V_4 * F_465 ( T_20 V_389 )
{
return V_389 ? F_466 ( V_389 ) : V_81 ;
}
static void
F_467 ( struct V_44 * V_44 , struct V_4 * V_5 , int V_1 , int V_157 )
{
V_5 -> V_1 = V_1 ;
V_5 -> V_199 = V_157 ;
V_5 -> F_202 = F_202 ( V_5 ) ;
V_5 -> V_157 = F_468 ( V_5 ) ;
if ( F_204 ( V_5 -> V_157 ) )
V_5 -> V_87 = & V_198 ;
else
V_5 -> V_87 = & V_207 ;
F_162 ( V_5 ) ;
}
static bool F_469 ( struct V_4 * V_5 )
{
const struct V_426 * V_426 = F_470 () , * V_427 ;
bool V_428 ;
F_114 () ;
V_427 = F_471 ( V_5 ) ;
if ( V_426 -> V_353 -> V_429 == V_427 -> V_353 -> V_429 )
V_428 = ( V_426 -> V_430 == V_427 -> V_430 ||
V_426 -> V_430 == V_427 -> V_431 ) ;
else
V_428 = false ;
F_118 () ;
return V_428 ;
}
static int F_472 ( struct V_4 * V_5 , int V_1 ,
const struct V_193 * V_194 , bool V_353 )
{
int V_432 , V_201 , V_433 = - 1 , V_206 , V_222 ;
unsigned long V_84 ;
const struct V_87 * V_200 ;
struct V_44 * V_44 ;
int V_434 ;
F_152 ( F_473 () ) ;
V_435:
if ( V_1 < 0 ) {
V_434 = V_5 -> V_281 ;
V_1 = V_433 = V_5 -> V_1 ;
} else {
V_434 = ! ! ( V_1 & V_436 ) ;
V_1 &= ~ V_436 ;
if ( V_1 != V_2 && V_1 != V_3 &&
V_1 != V_282 && V_1 != V_437 &&
V_1 != V_160 )
return - V_71 ;
}
if ( V_194 -> V_195 < 0 ||
( V_5 -> V_234 && V_194 -> V_195 > V_438 - 1 ) ||
( ! V_5 -> V_234 && V_194 -> V_195 > V_159 - 1 ) )
return - V_71 ;
if ( F_1 ( V_1 ) != ( V_194 -> V_195 != 0 ) )
return - V_71 ;
if ( V_353 && ! F_461 ( V_425 ) ) {
if ( F_1 ( V_1 ) ) {
unsigned long V_439 =
F_460 ( V_5 , V_440 ) ;
if ( V_1 != V_5 -> V_1 && ! V_439 )
return - V_441 ;
if ( V_194 -> V_195 > V_5 -> V_199 &&
V_194 -> V_195 > V_439 )
return - V_441 ;
}
if ( V_5 -> V_1 == V_160 && V_1 != V_160 ) {
if ( ! F_459 ( V_5 , F_347 ( V_5 ) ) )
return - V_441 ;
}
if ( ! F_469 ( V_5 ) )
return - V_441 ;
if ( V_5 -> V_281 && ! V_434 )
return - V_441 ;
}
if ( V_353 ) {
V_432 = F_474 ( V_5 ) ;
if ( V_432 )
return V_432 ;
}
V_44 = F_77 ( V_5 , & V_84 ) ;
if ( V_5 == V_44 -> V_192 ) {
F_81 ( V_44 , V_5 , & V_84 ) ;
return - V_71 ;
}
if ( F_35 ( V_1 == V_5 -> V_1 && ( ! F_1 ( V_1 ) ||
V_194 -> V_195 == V_5 -> V_199 ) ) ) {
F_80 ( V_44 ) ;
F_79 ( & V_5 -> V_49 , V_84 ) ;
return 0 ;
}
#ifdef F_45
if ( V_353 ) {
if ( F_12 () && F_1 ( V_1 ) &&
V_33 ( V_5 ) -> V_9 . V_20 == 0 &&
! F_475 ( V_33 ( V_5 ) ) ) {
F_81 ( V_44 , V_5 , & V_84 ) ;
return - V_441 ;
}
}
#endif
if ( F_35 ( V_433 != - 1 && V_433 != V_5 -> V_1 ) ) {
V_1 = V_433 = - 1 ;
F_81 ( V_44 , V_5 , & V_84 ) ;
goto V_435;
}
V_206 = V_5 -> V_206 ;
V_222 = F_64 ( V_44 , V_5 ) ;
if ( V_206 )
F_170 ( V_44 , V_5 , 0 ) ;
if ( V_222 )
V_5 -> V_87 -> F_396 ( V_44 , V_5 ) ;
V_5 -> V_281 = V_434 ;
V_201 = V_5 -> V_157 ;
V_200 = V_5 -> V_87 ;
F_467 ( V_44 , V_5 , V_1 , V_194 -> V_195 ) ;
if ( V_222 )
V_5 -> V_87 -> V_419 ( V_44 ) ;
if ( V_206 )
F_168 ( V_44 , V_5 , 0 ) ;
F_206 ( V_44 , V_5 , V_200 , V_201 ) ;
F_81 ( V_44 , V_5 , & V_84 ) ;
F_476 ( V_5 ) ;
return 0 ;
}
int F_477 ( struct V_4 * V_5 , int V_1 ,
const struct V_193 * V_194 )
{
return F_472 ( V_5 , V_1 , V_194 , true ) ;
}
int F_200 ( struct V_4 * V_5 , int V_1 ,
const struct V_193 * V_194 )
{
return F_472 ( V_5 , V_1 , V_194 , false ) ;
}
static int
F_478 ( T_20 V_389 , int V_1 , struct V_193 T_5 * V_194 )
{
struct V_193 V_442 ;
struct V_4 * V_5 ;
int V_432 ;
if ( ! V_194 || V_389 < 0 )
return - V_71 ;
if ( F_56 ( & V_442 , V_194 , sizeof( struct V_193 ) ) )
return - V_70 ;
F_114 () ;
V_432 = - V_443 ;
V_5 = F_465 ( V_389 ) ;
if ( V_5 != NULL )
V_432 = F_477 ( V_5 , V_1 , & V_442 ) ;
F_118 () ;
return V_432 ;
}
long F_479 ( T_20 V_389 , const struct V_230 * V_444 )
{
T_21 V_445 , V_446 ;
struct V_4 * V_5 ;
int V_432 ;
F_480 () ;
F_114 () ;
V_5 = F_465 ( V_389 ) ;
if ( ! V_5 ) {
F_118 () ;
F_481 () ;
return - V_443 ;
}
F_482 ( V_5 ) ;
F_118 () ;
if ( ! F_483 ( & V_445 , V_447 ) ) {
V_432 = - V_448 ;
goto V_449;
}
if ( ! F_483 ( & V_446 , V_447 ) ) {
V_432 = - V_448 ;
goto V_450;
}
V_432 = - V_441 ;
if ( ! F_469 ( V_5 ) && ! F_484 ( V_5 , V_425 ) )
goto V_422;
V_432 = F_474 ( V_5 ) ;
if ( V_432 )
goto V_422;
F_485 ( V_5 , V_445 ) ;
F_486 ( V_446 , V_444 , V_445 ) ;
V_451:
V_432 = F_487 ( V_5 , V_446 ) ;
if ( ! V_432 ) {
F_485 ( V_5 , V_445 ) ;
if ( ! F_488 ( V_446 , V_445 ) ) {
F_489 ( V_446 , V_445 ) ;
goto V_451;
}
}
V_422:
F_490 ( V_446 ) ;
V_450:
F_490 ( V_445 ) ;
V_449:
F_299 ( V_5 ) ;
F_481 () ;
return V_432 ;
}
static int F_491 ( unsigned long T_5 * V_452 , unsigned V_453 ,
struct V_230 * V_446 )
{
if ( V_453 < F_492 () )
F_493 ( V_446 ) ;
else if ( V_453 > F_492 () )
V_453 = F_492 () ;
return F_56 ( V_446 , V_452 , V_453 ) ? - V_70 : 0 ;
}
long F_494 ( T_20 V_389 , struct V_230 * V_454 )
{
struct V_4 * V_5 ;
unsigned long V_84 ;
int V_432 ;
F_480 () ;
F_114 () ;
V_432 = - V_443 ;
V_5 = F_465 ( V_389 ) ;
if ( ! V_5 )
goto V_422;
V_432 = F_495 ( V_5 ) ;
if ( V_432 )
goto V_422;
F_78 ( & V_5 -> V_49 , V_84 ) ;
F_486 ( V_454 , & V_5 -> V_445 , V_455 ) ;
F_79 ( & V_5 -> V_49 , V_84 ) ;
V_422:
F_118 () ;
F_481 () ;
return V_432 ;
}
static inline int F_496 ( void )
{
return F_256 () && ! ( V_216 () & V_217 ) ;
}
static void F_497 ( void )
{
F_378 ( V_217 ) ;
F_399 () ;
F_382 ( V_217 ) ;
}
int T_17 F_498 ( void )
{
if ( F_496 () ) {
F_497 () ;
return 1 ;
}
return 0 ;
}
int F_499 ( T_22 * V_37 )
{
int V_456 = F_496 () ;
int V_144 = 0 ;
F_75 ( V_37 ) ;
if ( F_500 ( V_37 ) || V_456 ) {
F_451 ( V_37 ) ;
if ( V_456 )
F_497 () ;
else
F_217 () ;
V_144 = 1 ;
F_501 ( V_37 ) ;
}
return V_144 ;
}
int T_17 F_502 ( void )
{
F_152 ( ! F_503 () ) ;
if ( F_496 () ) {
F_504 () ;
F_497 () ;
F_505 () ;
return 1 ;
}
return 0 ;
}
void T_17 F_506 ( void )
{
F_220 ( V_214 ) ;
F_507 () ;
}
bool T_17 F_508 ( struct V_4 * V_5 , bool V_457 )
{
struct V_4 * V_76 = V_81 ;
struct V_44 * V_44 , * V_458 ;
unsigned long V_84 ;
bool V_459 = 0 ;
F_181 ( V_84 ) ;
V_44 = F_84 () ;
V_451:
V_458 = F_41 ( V_5 ) ;
F_147 ( V_44 , V_458 ) ;
while ( F_41 ( V_5 ) != V_458 ) {
F_156 ( V_44 , V_458 ) ;
goto V_451;
}
if ( ! V_76 -> V_87 -> V_460 )
goto V_145;
if ( V_76 -> V_87 != V_5 -> V_87 )
goto V_145;
if ( F_65 ( V_458 , V_5 ) || V_5 -> V_213 )
goto V_145;
V_459 = V_76 -> V_87 -> V_460 ( V_44 , V_5 , V_457 ) ;
if ( V_459 ) {
F_241 ( V_44 , V_461 ) ;
if ( V_457 && V_44 != V_458 )
F_102 ( V_458 -> V_76 ) ;
}
V_145:
F_156 ( V_44 , V_458 ) ;
F_187 ( V_84 ) ;
if ( V_459 )
F_409 () ;
return V_459 ;
}
void T_17 F_509 ( void )
{
struct V_44 * V_44 = F_510 () ;
F_511 () ;
F_308 ( & V_44 -> F_317 ) ;
F_512 ( V_81 ) ;
V_81 -> V_462 = 1 ;
F_409 () ;
V_81 -> V_462 = 0 ;
F_513 ( & V_44 -> F_317 ) ;
F_514 () ;
}
long T_17 F_515 ( long V_413 )
{
struct V_44 * V_44 = F_510 () ;
long V_144 ;
F_511 () ;
F_308 ( & V_44 -> F_317 ) ;
F_512 ( V_81 ) ;
V_81 -> V_462 = 1 ;
V_144 = F_435 ( V_413 ) ;
V_81 -> V_462 = 0 ;
F_513 ( & V_44 -> F_317 ) ;
F_514 () ;
return V_144 ;
}
void F_516 ( struct V_4 * V_5 )
{
unsigned long free = 0 ;
unsigned V_213 ;
V_213 = V_5 -> V_213 ? F_517 ( V_5 -> V_213 ) + 1 : 0 ;
F_234 ( V_235 L_7 , V_5 -> V_236 ,
V_213 < sizeof( V_463 ) - 1 ? V_463 [ V_213 ] : '?' ) ;
#if V_127 == 32
if ( V_213 == V_214 )
F_234 ( V_464 L_8 ) ;
else
F_234 ( V_464 L_9 , F_518 ( V_5 ) ) ;
#else
if ( V_213 == V_214 )
F_234 ( V_464 L_10 ) ;
else
F_234 ( V_464 L_11 , F_518 ( V_5 ) ) ;
#endif
#ifdef F_519
free = F_520 ( V_5 ) ;
#endif
F_234 ( V_464 L_12 , free ,
F_235 ( V_5 ) , F_235 ( V_5 -> V_465 ) ,
( unsigned long ) F_159 ( V_5 ) -> V_84 ) ;
F_521 ( V_5 , NULL ) ;
}
void F_522 ( unsigned long V_466 )
{
struct V_4 * V_467 , * V_5 ;
#if V_127 == 32
F_234 ( V_235
L_13 ) ;
#else
F_234 ( V_235
L_14 ) ;
#endif
F_114 () ;
F_523 (g, p) {
F_524 () ;
if ( ! V_466 || ( V_5 -> V_213 & V_466 ) )
F_516 ( V_5 ) ;
} F_525 ( V_467 , V_5 ) ;
F_526 () ;
#ifdef F_212
F_527 () ;
#endif
F_118 () ;
if ( ! V_466 )
F_528 () ;
}
void T_23 F_529 ( struct V_4 * V_14 )
{
V_14 -> V_87 = & V_468 ;
}
void T_23 F_530 ( struct V_4 * V_14 , int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_84 ;
F_78 ( & V_44 -> V_37 , V_84 ) ;
F_268 ( V_14 ) ;
V_14 -> V_213 = V_214 ;
V_14 -> V_50 . V_211 = F_531 () ;
F_532 ( V_14 , F_533 ( V_45 ) ) ;
F_114 () ;
F_158 ( V_14 , V_45 ) ;
F_118 () ;
V_44 -> V_76 = V_44 -> V_14 = V_14 ;
#if F_191 ( F_38 )
V_14 -> V_77 = 1 ;
#endif
F_79 ( & V_44 -> V_37 , V_84 ) ;
F_159 ( V_14 ) -> V_216 = 0 ;
V_14 -> V_87 = & V_468 ;
F_534 ( V_14 , V_45 ) ;
#if F_191 ( F_38 )
sprintf ( V_14 -> V_236 , L_15 , V_469 , V_45 ) ;
#endif
}
static int F_535 ( void )
{
unsigned int V_470 = F_536 ( int , F_537 () , 8 ) ;
unsigned int V_471 ;
switch ( V_472 ) {
case V_473 :
V_471 = 1 ;
break;
case V_474 :
V_471 = V_470 ;
break;
case V_475 :
default:
V_471 = 1 + F_538 ( V_470 ) ;
break;
}
return V_471 ;
}
static void F_539 ( void )
{
unsigned int V_471 = F_535 () ;
#define F_540 ( T_24 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_540 ( V_476 ) ;
F_540 ( V_477 ) ;
F_540 ( V_478 ) ;
#undef F_540
}
static inline void F_541 ( void )
{
F_539 () ;
}
void F_532 ( struct V_4 * V_5 , const struct V_230 * V_446 )
{
if ( V_5 -> V_87 && V_5 -> V_87 -> V_479 )
V_5 -> V_87 -> V_479 ( V_5 , V_446 ) ;
F_489 ( & V_5 -> V_445 , V_446 ) ;
V_5 -> V_52 . V_480 = F_542 ( V_446 ) ;
}
int F_487 ( struct V_4 * V_5 , const struct V_230 * V_446 )
{
unsigned long V_84 ;
struct V_44 * V_44 ;
unsigned int V_229 ;
int V_144 = 0 ;
V_44 = F_77 ( V_5 , & V_84 ) ;
if ( F_543 ( & V_5 -> V_445 , V_446 ) )
goto V_145;
if ( ! F_544 ( V_446 , V_232 ) ) {
V_144 = - V_71 ;
goto V_145;
}
if ( F_35 ( ( V_5 -> V_84 & V_481 ) && V_5 != V_81 ) ) {
V_144 = - V_71 ;
goto V_145;
}
F_532 ( V_5 , V_446 ) ;
if ( F_229 ( F_106 ( V_5 ) , V_446 ) )
goto V_145;
V_229 = F_231 ( V_232 , V_446 ) ;
if ( V_5 -> V_206 ) {
struct V_346 V_89 = { V_5 , V_229 } ;
F_81 ( V_44 , V_5 , & V_84 ) ;
F_339 ( F_37 ( V_44 ) , V_347 , & V_89 ) ;
F_545 ( V_5 -> V_234 ) ;
return 0 ;
}
V_145:
F_81 ( V_44 , V_5 , & V_84 ) ;
return V_144 ;
}
static int F_546 ( struct V_4 * V_5 , int V_482 , int V_229 )
{
struct V_44 * V_483 , * V_484 ;
int V_144 = 0 ;
if ( F_35 ( ! F_87 ( V_229 ) ) )
return V_144 ;
V_484 = F_51 ( V_482 ) ;
V_483 = F_51 ( V_229 ) ;
F_21 ( & V_5 -> V_49 ) ;
F_147 ( V_484 , V_483 ) ;
if ( F_106 ( V_5 ) != V_482 )
goto V_411;
if ( ! F_229 ( V_229 , F_230 ( V_5 ) ) )
goto V_485;
if ( V_5 -> V_206 ) {
F_170 ( V_484 , V_5 , 0 ) ;
F_211 ( V_5 , V_229 ) ;
F_168 ( V_483 , V_5 , 0 ) ;
F_207 ( V_483 , V_5 , 0 ) ;
}
V_411:
V_144 = 1 ;
V_485:
F_156 ( V_484 , V_483 ) ;
F_22 ( & V_5 -> V_49 ) ;
return V_144 ;
}
static int V_347 ( void * V_142 )
{
struct V_346 * V_89 = V_142 ;
F_83 () ;
F_546 ( V_89 -> V_486 , F_287 () , V_89 -> V_229 ) ;
F_73 () ;
return 0 ;
}
void F_547 ( void )
{
struct V_298 * V_234 = V_81 -> V_304 ;
F_152 ( F_237 ( F_92 () ) ) ;
if ( V_234 != & V_487 )
F_310 ( V_234 , & V_487 , V_81 ) ;
F_297 ( V_234 ) ;
}
static void F_548 ( struct V_44 * V_484 )
{
struct V_44 * V_483 = F_51 ( F_549 ( V_232 ) ) ;
V_483 -> V_165 += V_484 -> V_165 ;
V_484 -> V_165 = 0 ;
}
static void F_550 ( struct V_44 * V_44 )
{
F_551 ( V_44 -> V_310 , & V_322 ) ;
V_44 -> V_310 = 0 ;
}
static void F_552 ( struct V_44 * V_44 )
{
struct V_40 * V_40 ;
F_553 (rq, cfs_rq) {
struct V_32 * V_35 = F_25 ( V_40 -> V_34 ) ;
if ( ! V_40 -> V_41 )
continue;
V_40 -> V_488 = V_35 -> V_38 ;
if ( F_554 ( V_40 ) )
F_555 ( V_40 ) ;
}
}
static void F_552 ( struct V_44 * V_44 ) {}
static void F_556 ( unsigned int V_489 )
{
struct V_44 * V_44 = F_51 ( V_489 ) ;
struct V_4 * V_78 , * V_192 = V_44 -> V_192 ;
int V_229 ;
V_44 -> V_192 = NULL ;
F_552 ( V_44 ) ;
for ( ; ; ) {
if ( V_44 -> V_151 == 1 )
break;
V_78 = F_397 ( V_44 ) ;
F_152 ( ! V_78 ) ;
V_78 -> V_87 -> F_396 ( V_44 , V_78 ) ;
V_229 = F_225 ( V_489 , V_78 ) ;
F_22 ( & V_44 -> V_37 ) ;
F_546 ( V_78 , V_489 , V_229 ) ;
F_21 ( & V_44 -> V_37 ) ;
}
V_44 -> V_192 = V_192 ;
}
static struct V_490 * F_557 ( int V_317 )
{
struct V_490 * V_491 =
F_558 ( V_317 , sizeof( struct V_490 ) , V_447 ) ;
return V_491 ;
}
static void F_559 ( struct V_490 * * V_492 )
{
struct V_490 * V_491 ;
for ( V_491 = * V_492 ; V_491 -> V_403 ; V_491 ++ ) {
if ( V_491 -> V_143 )
F_559 ( & V_491 -> V_143 ) ;
if ( V_491 -> V_493 == NULL )
F_560 ( V_491 -> V_494 ) ;
}
F_560 ( * V_492 ) ;
* V_492 = NULL ;
}
static void
F_561 ( struct V_490 * V_491 ,
const char * V_494 , void * V_142 , int V_495 ,
T_25 V_403 , V_493 * V_493 )
{
V_491 -> V_494 = V_494 ;
V_491 -> V_142 = V_142 ;
V_491 -> V_495 = V_495 ;
V_491 -> V_403 = V_403 ;
V_491 -> V_493 = V_493 ;
}
static struct V_490 *
F_562 ( struct V_110 * V_111 )
{
struct V_490 * V_496 = F_557 ( 13 ) ;
if ( V_496 == NULL )
return NULL ;
F_561 ( & V_496 [ 0 ] , L_16 , & V_111 -> V_497 ,
sizeof( long ) , 0644 , V_498 ) ;
F_561 ( & V_496 [ 1 ] , L_17 , & V_111 -> V_499 ,
sizeof( long ) , 0644 , V_498 ) ;
F_561 ( & V_496 [ 2 ] , L_18 , & V_111 -> V_500 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 3 ] , L_19 , & V_111 -> V_502 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 4 ] , L_20 , & V_111 -> V_503 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 5 ] , L_21 , & V_111 -> V_504 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 6 ] , L_22 , & V_111 -> V_505 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 7 ] , L_23 , & V_111 -> V_506 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 8 ] , L_24 , & V_111 -> V_507 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 9 ] , L_25 ,
& V_111 -> V_508 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 10 ] , L_26 , & V_111 -> V_84 ,
sizeof( int ) , 0644 , V_501 ) ;
F_561 ( & V_496 [ 11 ] , L_27 , V_111 -> T_24 ,
V_509 , 0444 , V_510 ) ;
return V_496 ;
}
static V_490 * F_563 ( int V_45 )
{
struct V_490 * V_491 , * V_496 ;
struct V_110 * V_111 ;
int V_511 = 0 , V_59 ;
char V_67 [ 32 ] ;
F_115 (cpu, sd)
V_511 ++ ;
V_491 = V_496 = F_557 ( V_511 + 1 ) ;
if ( V_496 == NULL )
return NULL ;
V_59 = 0 ;
F_115 (cpu, sd) {
snprintf ( V_67 , 32 , L_28 , V_59 ) ;
V_491 -> V_494 = F_564 ( V_67 , V_447 ) ;
V_491 -> V_403 = 0555 ;
V_491 -> V_143 = F_562 ( V_111 ) ;
V_491 ++ ;
V_59 ++ ;
}
return V_496 ;
}
static void F_565 ( void )
{
int V_59 , V_512 = F_566 () ;
struct V_490 * V_491 = F_557 ( V_512 + 1 ) ;
char V_67 [ 32 ] ;
F_567 ( V_513 [ 0 ] . V_143 ) ;
V_513 [ 0 ] . V_143 = V_491 ;
if ( V_491 == NULL )
return;
F_315 (i) {
snprintf ( V_67 , 32 , L_29 , V_59 ) ;
V_491 -> V_494 = F_564 ( V_67 , V_447 ) ;
V_491 -> V_403 = 0555 ;
V_491 -> V_143 = F_563 ( V_59 ) ;
V_491 ++ ;
}
F_567 ( V_514 ) ;
V_514 = F_568 ( V_515 ) ;
}
static void F_569 ( void )
{
if ( V_514 )
F_570 ( V_514 ) ;
V_514 = NULL ;
if ( V_513 [ 0 ] . V_143 )
F_559 ( & V_513 [ 0 ] . V_143 ) ;
}
static void F_565 ( void )
{
}
static void F_569 ( void )
{
}
static void F_571 ( struct V_44 * V_44 )
{
if ( ! V_44 -> V_516 ) {
const struct V_87 * V_205 ;
F_572 ( V_44 -> V_45 , V_44 -> V_517 -> V_516 ) ;
V_44 -> V_516 = 1 ;
F_208 (class) {
if ( V_205 -> V_518 )
V_205 -> V_518 ( V_44 ) ;
}
}
}
static void F_573 ( struct V_44 * V_44 )
{
if ( V_44 -> V_516 ) {
const struct V_87 * V_205 ;
F_208 (class) {
if ( V_205 -> V_519 )
V_205 -> V_519 ( V_44 ) ;
}
F_574 ( V_44 -> V_45 , V_44 -> V_517 -> V_516 ) ;
V_44 -> V_516 = 0 ;
}
}
static int T_23
F_575 ( struct V_95 * V_96 , unsigned long V_97 , void * V_98 )
{
int V_45 = ( long ) V_98 ;
unsigned long V_84 ;
struct V_44 * V_44 = F_51 ( V_45 ) ;
switch ( V_97 & ~ V_520 ) {
case V_521 :
V_44 -> V_321 = V_321 ;
break;
case V_522 :
F_78 ( & V_44 -> V_37 , V_84 ) ;
if ( V_44 -> V_517 ) {
F_152 ( ! F_229 ( V_45 , V_44 -> V_517 -> V_523 ) ) ;
F_571 ( V_44 ) ;
}
F_79 ( & V_44 -> V_37 , V_84 ) ;
break;
#ifdef F_576
case V_524 :
F_249 () ;
F_78 ( & V_44 -> V_37 , V_84 ) ;
if ( V_44 -> V_517 ) {
F_152 ( ! F_229 ( V_45 , V_44 -> V_517 -> V_523 ) ) ;
F_573 ( V_44 ) ;
}
F_556 ( V_45 ) ;
F_152 ( V_44 -> V_151 != 1 ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
F_548 ( V_44 ) ;
F_550 ( V_44 ) ;
break;
#endif
}
F_577 () ;
return V_105 ;
}
static int T_23 F_578 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
switch ( V_97 & ~ V_520 ) {
case V_522 :
case V_525 :
F_579 ( ( long ) V_98 , true ) ;
return V_105 ;
default:
return V_106 ;
}
}
static int T_23 F_580 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
switch ( V_97 & ~ V_520 ) {
case V_101 :
F_579 ( ( long ) V_98 , false ) ;
return V_105 ;
default:
return V_106 ;
}
}
static int T_8 F_581 ( void )
{
void * V_45 = ( void * ) ( long ) F_92 () ;
int V_526 ;
V_526 = F_575 ( & V_527 , V_521 , V_45 ) ;
F_152 ( V_526 == V_528 ) ;
F_575 ( & V_527 , V_522 , V_45 ) ;
F_582 ( & V_527 ) ;
F_583 ( F_578 , V_529 ) ;
F_583 ( F_580 , V_530 ) ;
return 0 ;
}
static int T_8 F_584 ( char * V_531 )
{
V_532 = 1 ;
return 0 ;
}
static int F_585 ( struct V_110 * V_111 , int V_45 , int V_533 ,
struct V_230 * V_534 )
{
struct V_535 * V_536 = V_111 -> V_537 ;
char V_531 [ 256 ] ;
F_586 ( V_531 , sizeof( V_531 ) , F_242 ( V_111 ) ) ;
F_493 ( V_534 ) ;
F_234 ( V_538 L_30 , V_533 , L_31 , V_533 ) ;
if ( ! ( V_111 -> V_84 & V_539 ) ) {
F_234 ( L_32 ) ;
if ( V_111 -> V_51 )
F_234 ( V_388 L_33
L_34 ) ;
return - 1 ;
}
F_234 ( V_464 L_35 , V_531 , V_111 -> T_24 ) ;
if ( ! F_229 ( V_45 , F_242 ( V_111 ) ) ) {
F_234 ( V_388 L_36
L_37 , V_45 ) ;
}
if ( ! F_229 ( V_45 , F_587 ( V_536 ) ) ) {
F_234 ( V_388 L_38
L_39 , V_45 ) ;
}
F_234 ( V_538 L_40 , V_533 + 1 , L_31 ) ;
do {
if ( ! V_536 ) {
F_234 ( L_3 ) ;
F_234 ( V_388 L_41 ) ;
break;
}
if ( ! V_536 -> V_540 -> V_541 ) {
F_234 ( V_464 L_3 ) ;
F_234 ( V_388 L_42
L_43 ) ;
break;
}
if ( ! F_542 ( F_587 ( V_536 ) ) ) {
F_234 ( V_464 L_3 ) ;
F_234 ( V_388 L_44 ) ;
break;
}
if ( F_544 ( V_534 , F_587 ( V_536 ) ) ) {
F_234 ( V_464 L_3 ) ;
F_234 ( V_388 L_45 ) ;
break;
}
F_588 ( V_534 , V_534 , F_587 ( V_536 ) ) ;
F_586 ( V_531 , sizeof( V_531 ) , F_587 ( V_536 ) ) ;
F_234 ( V_464 L_46 , V_531 ) ;
if ( V_536 -> V_540 -> V_541 != V_542 ) {
F_234 ( V_464 L_47 ,
V_536 -> V_540 -> V_541 ) ;
}
V_536 = V_536 -> V_78 ;
} while ( V_536 != V_111 -> V_537 );
F_234 ( V_464 L_3 ) ;
if ( ! F_543 ( F_242 ( V_111 ) , V_534 ) )
F_234 ( V_388 L_48 ) ;
if ( V_111 -> V_51 &&
! F_488 ( V_534 , F_242 ( V_111 -> V_51 ) ) )
F_234 ( V_388 L_49
L_50 ) ;
return 0 ;
}
static void F_589 ( struct V_110 * V_111 , int V_45 )
{
int V_533 = 0 ;
if ( ! V_532 )
return;
if ( ! V_111 ) {
F_234 ( V_538 L_51 , V_45 ) ;
return;
}
F_234 ( V_538 L_52 , V_45 ) ;
for (; ; ) {
if ( F_585 ( V_111 , V_45 , V_533 , V_543 ) )
break;
V_533 ++ ;
V_111 = V_111 -> V_51 ;
if ( ! V_111 )
break;
}
}
static int F_590 ( struct V_110 * V_111 )
{
if ( F_542 ( F_242 ( V_111 ) ) == 1 )
return 1 ;
if ( V_111 -> V_84 & ( V_539 |
V_544 |
V_288 |
V_345 |
V_545 |
V_546 ) ) {
if ( V_111 -> V_537 != V_111 -> V_537 -> V_78 )
return 0 ;
}
if ( V_111 -> V_84 & ( V_547 ) )
return 0 ;
return 1 ;
}
static int
F_591 ( struct V_110 * V_111 , struct V_110 * V_51 )
{
unsigned long V_548 = V_111 -> V_84 , V_549 = V_51 -> V_84 ;
if ( F_590 ( V_51 ) )
return 1 ;
if ( ! F_543 ( F_242 ( V_111 ) , F_242 ( V_51 ) ) )
return 0 ;
if ( V_51 -> V_537 == V_51 -> V_537 -> V_78 ) {
V_549 &= ~ ( V_539 |
V_544 |
V_288 |
V_345 |
V_545 |
V_546 ) ;
if ( V_550 == 1 )
V_549 &= ~ V_551 ;
}
if ( ~ V_548 & V_549 )
return 0 ;
return 1 ;
}
static void F_592 ( struct V_552 * V_553 )
{
struct V_554 * V_517 = F_4 ( V_553 , struct V_554 , V_553 ) ;
F_593 ( & V_517 -> V_555 ) ;
F_490 ( V_517 -> V_556 ) ;
F_490 ( V_517 -> V_516 ) ;
F_490 ( V_517 -> V_523 ) ;
F_560 ( V_517 ) ;
}
static void F_594 ( struct V_44 * V_44 , struct V_554 * V_517 )
{
struct V_554 * V_557 = NULL ;
unsigned long V_84 ;
F_78 ( & V_44 -> V_37 , V_84 ) ;
if ( V_44 -> V_517 ) {
V_557 = V_44 -> V_517 ;
if ( F_229 ( V_44 -> V_45 , V_557 -> V_516 ) )
F_573 ( V_44 ) ;
F_574 ( V_44 -> V_45 , V_557 -> V_523 ) ;
if ( ! F_595 ( & V_557 -> V_558 ) )
V_557 = NULL ;
}
F_308 ( & V_517 -> V_558 ) ;
V_44 -> V_517 = V_517 ;
F_572 ( V_44 -> V_45 , V_517 -> V_523 ) ;
if ( F_229 ( V_44 -> V_45 , V_232 ) )
F_571 ( V_44 ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
if ( V_557 )
F_596 ( & V_557 -> V_553 , F_592 ) ;
}
static int F_597 ( struct V_554 * V_517 )
{
memset ( V_517 , 0 , sizeof( * V_517 ) ) ;
if ( ! F_483 ( & V_517 -> V_523 , V_447 ) )
goto V_145;
if ( ! F_483 ( & V_517 -> V_516 , V_447 ) )
goto V_559;
if ( ! F_483 ( & V_517 -> V_556 , V_447 ) )
goto V_560;
if ( F_598 ( & V_517 -> V_555 ) != 0 )
goto V_561;
return 0 ;
V_561:
F_490 ( V_517 -> V_556 ) ;
V_560:
F_490 ( V_517 -> V_516 ) ;
V_559:
F_490 ( V_517 -> V_523 ) ;
V_145:
return - V_448 ;
}
static void F_599 ( void )
{
F_597 ( & V_562 ) ;
F_600 ( & V_562 . V_558 , 1 ) ;
}
static struct V_554 * F_601 ( void )
{
struct V_554 * V_517 ;
V_517 = F_602 ( sizeof( * V_517 ) , V_447 ) ;
if ( ! V_517 )
return NULL ;
if ( F_597 ( V_517 ) != 0 ) {
F_560 ( V_517 ) ;
return NULL ;
}
return V_517 ;
}
static void F_603 ( struct V_535 * V_563 , int V_564 )
{
struct V_535 * V_123 , * V_565 ;
if ( ! V_563 )
return;
V_565 = V_563 ;
do {
V_123 = V_563 -> V_78 ;
if ( V_564 && F_595 ( & V_563 -> V_540 -> V_566 ) )
F_560 ( V_563 -> V_540 ) ;
F_560 ( V_563 ) ;
V_563 = V_123 ;
} while ( V_563 != V_565 );
}
static void F_604 ( struct V_552 * V_553 )
{
struct V_110 * V_111 = F_4 ( V_553 , struct V_110 , V_553 ) ;
if ( V_111 -> V_84 & V_567 ) {
F_603 ( V_111 -> V_537 , 1 ) ;
} else if ( F_595 ( & V_111 -> V_537 -> V_566 ) ) {
F_560 ( V_111 -> V_537 -> V_540 ) ;
F_560 ( V_111 -> V_537 ) ;
}
F_560 ( V_111 ) ;
}
static void F_605 ( struct V_110 * V_111 , int V_45 )
{
F_606 ( & V_111 -> V_553 , F_604 ) ;
}
static void F_607 ( struct V_110 * V_111 , int V_45 )
{
for (; V_111 ; V_111 = V_111 -> V_51 )
F_605 ( V_111 , V_45 ) ;
}
static void
F_608 ( struct V_110 * V_111 , struct V_554 * V_517 , int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
struct V_110 * V_123 ;
for ( V_123 = V_111 ; V_123 ; ) {
struct V_110 * V_51 = V_123 -> V_51 ;
if ( ! V_51 )
break;
if ( F_591 ( V_123 , V_51 ) ) {
V_123 -> V_51 = V_51 -> V_51 ;
if ( V_51 -> V_51 )
V_51 -> V_51 -> V_143 = V_123 ;
F_605 ( V_51 , V_45 ) ;
} else
V_123 = V_123 -> V_51 ;
}
if ( V_111 && F_590 ( V_111 ) ) {
V_123 = V_111 ;
V_111 = V_111 -> V_51 ;
F_605 ( V_123 , V_45 ) ;
if ( V_111 )
V_111 -> V_143 = NULL ;
}
F_589 ( V_111 , V_45 ) ;
F_594 ( V_44 , V_517 ) ;
V_123 = V_44 -> V_111 ;
F_609 ( V_44 -> V_111 , V_111 ) ;
F_607 ( V_123 , V_45 ) ;
}
static int T_8 F_610 ( char * V_531 )
{
F_611 ( & V_568 ) ;
F_612 ( V_531 , V_568 ) ;
return 1 ;
}
static int F_613 ( int V_294 , T_26 * V_569 )
{
int V_59 , V_317 , V_137 , V_570 , V_571 = - 1 ;
V_570 = V_572 ;
for ( V_59 = 0 ; V_59 < V_550 ; V_59 ++ ) {
V_317 = ( V_294 + V_59 ) % V_550 ;
if ( ! F_614 ( V_317 ) )
continue;
if ( F_615 ( V_317 , * V_569 ) )
continue;
V_137 = F_616 ( V_294 , V_317 ) ;
if ( V_137 < V_570 ) {
V_570 = V_137 ;
V_571 = V_317 ;
}
}
if ( V_571 != - 1 )
F_617 ( V_571 , * V_569 ) ;
return V_571 ;
}
static void F_618 ( int V_294 , struct V_230 * V_523 )
{
T_26 V_569 ;
int V_59 ;
F_493 ( V_523 ) ;
F_619 ( V_569 ) ;
F_588 ( V_523 , V_523 , F_226 ( V_294 ) ) ;
F_617 ( V_294 , V_569 ) ;
for ( V_59 = 1 ; V_59 < V_573 ; V_59 ++ ) {
int V_574 = F_613 ( V_294 , & V_569 ) ;
if ( V_574 < 0 )
break;
F_588 ( V_523 , V_523 , F_226 ( V_574 ) ) ;
}
}
static const struct V_230 * F_620 ( int V_45 )
{
F_75 ( & V_575 ) ;
F_618 ( F_227 ( V_45 ) , V_543 ) ;
return V_543 ;
}
static const struct V_230 * F_621 ( int V_45 )
{
return V_576 ;
}
static const struct V_230 * F_622 ( int V_45 )
{
return F_226 ( F_227 ( V_45 ) ) ;
}
static int
F_623 ( struct V_110 * V_111 , int V_45 )
{
struct V_535 * V_565 = NULL , * V_209 = NULL , * V_537 = NULL , * V_563 ;
const struct V_230 * V_523 = F_242 ( V_111 ) ;
struct V_230 * V_577 = V_543 ;
struct V_578 * V_579 = V_111 -> V_405 ;
struct V_110 * V_143 ;
int V_59 ;
F_493 ( V_577 ) ;
F_116 (i, span) {
struct V_230 * V_580 ;
if ( F_229 ( V_59 , V_577 ) )
continue;
V_563 = F_624 ( sizeof( struct V_535 ) + F_492 () ,
V_447 , F_227 ( V_59 ) ) ;
if ( ! V_563 )
goto V_485;
V_580 = F_587 ( V_563 ) ;
V_143 = * F_625 ( V_579 -> V_111 , V_59 ) ;
if ( V_143 -> V_143 ) {
V_143 = V_143 -> V_143 ;
F_489 ( V_580 , F_242 ( V_143 ) ) ;
} else
F_572 ( V_59 , V_580 ) ;
F_588 ( V_577 , V_577 , V_580 ) ;
V_563 -> V_540 = * F_625 ( V_579 -> V_540 , F_626 ( V_580 ) ) ;
F_308 ( & V_563 -> V_540 -> V_566 ) ;
if ( F_229 ( V_45 , V_580 ) )
V_537 = V_563 ;
if ( ! V_565 )
V_565 = V_563 ;
if ( V_209 )
V_209 -> V_78 = V_563 ;
V_209 = V_563 ;
V_209 -> V_78 = V_565 ;
}
V_111 -> V_537 = V_537 ;
return 0 ;
V_485:
F_603 ( V_565 , 0 ) ;
return - V_448 ;
}
static int F_627 ( int V_45 , struct V_578 * V_579 , struct V_535 * * V_563 )
{
struct V_110 * V_111 = * F_625 ( V_579 -> V_111 , V_45 ) ;
struct V_110 * V_143 = V_111 -> V_143 ;
if ( V_143 )
V_45 = F_626 ( F_242 ( V_143 ) ) ;
if ( V_563 ) {
* V_563 = * F_625 ( V_579 -> V_563 , V_45 ) ;
( * V_563 ) -> V_540 = * F_625 ( V_579 -> V_540 , V_45 ) ;
F_600 ( & ( * V_563 ) -> V_540 -> V_566 , 1 ) ;
}
return V_45 ;
}
static int
F_628 ( struct V_110 * V_111 , int V_45 )
{
struct V_535 * V_565 = NULL , * V_209 = NULL ;
struct V_578 * V_579 = V_111 -> V_405 ;
const struct V_230 * V_523 = F_242 ( V_111 ) ;
struct V_230 * V_577 ;
int V_59 ;
F_627 ( V_45 , V_579 , & V_111 -> V_537 ) ;
F_308 ( & V_111 -> V_537 -> V_566 ) ;
if ( V_45 != F_626 ( F_242 ( V_111 ) ) )
return 0 ;
F_75 ( & V_575 ) ;
V_577 = V_543 ;
F_493 ( V_577 ) ;
F_116 (i, span) {
struct V_535 * V_563 ;
int V_536 = F_627 ( V_59 , V_579 , & V_563 ) ;
int V_332 ;
if ( F_229 ( V_59 , V_577 ) )
continue;
F_493 ( F_587 ( V_563 ) ) ;
V_563 -> V_540 -> V_541 = 0 ;
F_116 (j, span) {
if ( F_627 ( V_332 , V_579 , NULL ) != V_536 )
continue;
F_572 ( V_332 , V_577 ) ;
F_572 ( V_332 , F_587 ( V_563 ) ) ;
}
if ( ! V_565 )
V_565 = V_563 ;
if ( V_209 )
V_209 -> V_78 = V_563 ;
V_209 = V_563 ;
}
V_209 -> V_78 = V_565 ;
return 0 ;
}
static void F_629 ( int V_45 , struct V_110 * V_111 )
{
struct V_535 * V_563 = V_111 -> V_537 ;
F_567 ( ! V_111 || ! V_563 ) ;
do {
V_563 -> V_581 = F_542 ( F_587 ( V_563 ) ) ;
V_563 = V_563 -> V_78 ;
} while ( V_563 != V_111 -> V_537 );
if ( V_45 != F_630 ( V_563 ) )
return;
F_631 ( V_111 , V_45 ) ;
}
static int T_8 F_632 ( char * V_531 )
{
unsigned long V_137 ;
V_137 = F_633 ( V_531 , NULL , 0 ) ;
if ( V_137 < V_582 )
V_583 = V_137 ;
return 1 ;
}
static void F_634 ( struct V_110 * V_111 ,
struct V_584 * V_585 )
{
int V_586 ;
if ( ! V_585 || V_585 -> V_587 < 0 ) {
if ( V_583 < 0 )
return;
else
V_586 = V_583 ;
} else
V_586 = V_585 -> V_587 ;
if ( V_586 < V_111 -> V_533 ) {
V_111 -> V_84 &= ~ ( V_272 | V_544 ) ;
} else {
V_111 -> V_84 |= ( V_272 | V_544 ) ;
}
}
static void F_635 ( struct V_588 * V_589 , enum V_590 V_591 ,
const struct V_230 * V_592 )
{
switch ( V_591 ) {
case V_593 :
if ( ! F_318 ( & V_589 -> V_517 -> V_558 ) )
F_592 ( & V_589 -> V_517 -> V_553 ) ;
case V_594 :
F_636 ( V_589 -> V_111 ) ;
case V_595 :
F_637 ( V_592 ) ;
case V_596 :
break;
}
}
static enum V_590 F_638 ( struct V_588 * V_589 ,
const struct V_230 * V_592 )
{
memset ( V_589 , 0 , sizeof( * V_589 ) ) ;
if ( F_639 ( V_592 ) )
return V_595 ;
V_589 -> V_111 = F_640 ( struct V_110 * ) ;
if ( ! V_589 -> V_111 )
return V_595 ;
V_589 -> V_517 = F_601 () ;
if ( ! V_589 -> V_517 )
return V_594 ;
return V_593 ;
}
static void F_641 ( int V_45 , struct V_110 * V_111 )
{
struct V_578 * V_579 = V_111 -> V_405 ;
F_91 ( * F_625 ( V_579 -> V_111 , V_45 ) != V_111 ) ;
* F_625 ( V_579 -> V_111 , V_45 ) = NULL ;
if ( F_318 ( & ( * F_625 ( V_579 -> V_563 , V_45 ) ) -> V_566 ) )
* F_625 ( V_579 -> V_563 , V_45 ) = NULL ;
if ( F_318 ( & ( * F_625 ( V_579 -> V_540 , V_45 ) ) -> V_566 ) )
* F_625 ( V_579 -> V_540 , V_45 ) = NULL ;
}
static const struct V_230 * F_642 ( int V_45 )
{
return F_643 ( V_45 ) ;
}
static int F_639 ( const struct V_230 * V_592 )
{
struct V_597 * V_598 ;
int V_332 ;
for ( V_598 = V_599 ; V_598 -> V_600 ; V_598 ++ ) {
struct V_578 * V_579 = & V_598 -> V_142 ;
V_579 -> V_111 = F_640 ( struct V_110 * ) ;
if ( ! V_579 -> V_111 )
return - V_448 ;
V_579 -> V_563 = F_640 ( struct V_535 * ) ;
if ( ! V_579 -> V_563 )
return - V_448 ;
V_579 -> V_540 = F_640 ( struct V_601 * ) ;
if ( ! V_579 -> V_540 )
return - V_448 ;
F_116 (j, cpu_map) {
struct V_110 * V_111 ;
struct V_535 * V_563 ;
struct V_601 * V_540 ;
V_111 = F_624 ( sizeof( struct V_110 ) + F_492 () ,
V_447 , F_227 ( V_332 ) ) ;
if ( ! V_111 )
return - V_448 ;
* F_625 ( V_579 -> V_111 , V_332 ) = V_111 ;
V_563 = F_624 ( sizeof( struct V_535 ) + F_492 () ,
V_447 , F_227 ( V_332 ) ) ;
if ( ! V_563 )
return - V_448 ;
* F_625 ( V_579 -> V_563 , V_332 ) = V_563 ;
V_540 = F_624 ( sizeof( struct V_601 ) ,
V_447 , F_227 ( V_332 ) ) ;
if ( ! V_540 )
return - V_448 ;
* F_625 ( V_579 -> V_540 , V_332 ) = V_540 ;
}
}
return 0 ;
}
static void F_637 ( const struct V_230 * V_592 )
{
struct V_597 * V_598 ;
int V_332 ;
for ( V_598 = V_599 ; V_598 -> V_600 ; V_598 ++ ) {
struct V_578 * V_579 = & V_598 -> V_142 ;
F_116 (j, cpu_map) {
struct V_110 * V_111 = * F_625 ( V_579 -> V_111 , V_332 ) ;
if ( V_111 && ( V_111 -> V_84 & V_567 ) )
F_603 ( V_111 -> V_537 , 0 ) ;
F_560 ( * F_625 ( V_579 -> V_111 , V_332 ) ) ;
F_560 ( * F_625 ( V_579 -> V_563 , V_332 ) ) ;
F_560 ( * F_625 ( V_579 -> V_540 , V_332 ) ) ;
}
F_636 ( V_579 -> V_111 ) ;
F_636 ( V_579 -> V_563 ) ;
F_636 ( V_579 -> V_540 ) ;
}
}
struct V_110 * F_644 ( struct V_597 * V_598 ,
struct V_588 * V_589 , const struct V_230 * V_592 ,
struct V_584 * V_585 , struct V_110 * V_143 ,
int V_45 )
{
struct V_110 * V_111 = V_598 -> V_600 ( V_598 , V_45 ) ;
if ( ! V_111 )
return V_143 ;
F_634 ( V_111 , V_585 ) ;
F_486 ( F_242 ( V_111 ) , V_592 , V_598 -> V_454 ( V_45 ) ) ;
if ( V_143 ) {
V_111 -> V_533 = V_143 -> V_533 + 1 ;
V_582 = F_142 ( V_582 , V_111 -> V_533 ) ;
V_143 -> V_51 = V_111 ;
}
V_111 -> V_143 = V_143 ;
return V_111 ;
}
static int F_645 ( const struct V_230 * V_592 ,
struct V_584 * V_585 )
{
enum V_590 V_602 = V_596 ;
struct V_110 * V_111 ;
struct V_588 V_589 ;
int V_59 , V_144 = - V_448 ;
V_602 = F_638 ( & V_589 , V_592 ) ;
if ( V_602 != V_593 )
goto error;
F_116 (i, cpu_map) {
struct V_597 * V_598 ;
V_111 = NULL ;
for ( V_598 = V_599 ; V_598 -> V_600 ; V_598 ++ ) {
V_111 = F_644 ( V_598 , & V_589 , V_592 , V_585 , V_111 , V_59 ) ;
if ( V_598 -> V_84 & V_603 || F_86 ( V_604 ) )
V_111 -> V_84 |= V_567 ;
if ( F_543 ( V_592 , F_242 ( V_111 ) ) )
break;
}
while ( V_111 -> V_143 )
V_111 = V_111 -> V_143 ;
* F_625 ( V_589 . V_111 , V_59 ) = V_111 ;
}
F_116 (i, cpu_map) {
for ( V_111 = * F_625 ( V_589 . V_111 , V_59 ) ; V_111 ; V_111 = V_111 -> V_51 ) {
V_111 -> V_605 = F_542 ( F_242 ( V_111 ) ) ;
if ( V_111 -> V_84 & V_567 ) {
if ( F_623 ( V_111 , V_59 ) )
goto error;
} else {
if ( F_628 ( V_111 , V_59 ) )
goto error;
}
}
}
for ( V_59 = V_606 - 1 ; V_59 >= 0 ; V_59 -- ) {
if ( ! F_229 ( V_59 , V_592 ) )
continue;
for ( V_111 = * F_625 ( V_589 . V_111 , V_59 ) ; V_111 ; V_111 = V_111 -> V_51 ) {
F_641 ( V_59 , V_111 ) ;
F_629 ( V_59 , V_111 ) ;
}
}
F_114 () ;
F_116 (i, cpu_map) {
V_111 = * F_625 ( V_589 . V_111 , V_59 ) ;
F_608 ( V_111 , V_589 . V_517 , V_59 ) ;
}
F_118 () ;
V_144 = 0 ;
error:
F_635 ( & V_589 , V_602 , V_592 ) ;
return V_144 ;
}
T_21 * F_646 ( unsigned int V_607 )
{
int V_59 ;
T_21 * V_608 ;
V_608 = F_602 ( sizeof( * V_608 ) * V_607 , V_447 ) ;
if ( ! V_608 )
return NULL ;
for ( V_59 = 0 ; V_59 < V_607 ; V_59 ++ ) {
if ( ! F_483 ( & V_608 [ V_59 ] , V_447 ) ) {
F_647 ( V_608 , V_59 ) ;
return NULL ;
}
}
return V_608 ;
}
void F_647 ( T_21 V_608 [] , unsigned int V_607 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_607 ; V_59 ++ )
F_490 ( V_608 [ V_59 ] ) ;
F_560 ( V_608 ) ;
}
static int F_648 ( const struct V_230 * V_592 )
{
int V_526 ;
F_649 () ;
V_609 = 1 ;
V_610 = F_646 ( V_609 ) ;
if ( ! V_610 )
V_610 = & V_611 ;
F_650 ( V_610 [ 0 ] , V_592 , V_568 ) ;
V_612 = NULL ;
V_526 = F_645 ( V_610 [ 0 ] , NULL ) ;
F_565 () ;
return V_526 ;
}
static void F_651 ( const struct V_230 * V_592 )
{
int V_59 ;
F_114 () ;
F_116 (i, cpu_map)
F_608 ( NULL , & V_562 , V_59 ) ;
F_118 () ;
}
static int F_652 ( struct V_584 * V_613 , int V_614 ,
struct V_584 * V_615 , int V_616 )
{
struct V_584 V_123 ;
if ( ! V_615 && ! V_613 )
return 1 ;
V_123 = V_617 ;
return ! memcmp ( V_613 ? ( V_613 + V_614 ) : & V_123 ,
V_615 ? ( V_615 + V_616 ) : & V_123 ,
sizeof( struct V_584 ) ) ;
}
void F_653 ( int V_618 , T_21 V_619 [] ,
struct V_584 * V_620 )
{
int V_59 , V_332 , V_317 ;
int V_621 ;
F_654 ( & V_575 ) ;
F_569 () ;
V_621 = F_649 () ;
V_317 = V_619 ? V_618 : 0 ;
for ( V_59 = 0 ; V_59 < V_609 ; V_59 ++ ) {
for ( V_332 = 0 ; V_332 < V_317 && ! V_621 ; V_332 ++ ) {
if ( F_543 ( V_610 [ V_59 ] , V_619 [ V_332 ] )
&& F_652 ( V_612 , V_59 , V_620 , V_332 ) )
goto V_622;
}
F_651 ( V_610 [ V_59 ] ) ;
V_622:
;
}
if ( V_619 == NULL ) {
V_609 = 0 ;
V_619 = & V_611 ;
F_650 ( V_619 [ 0 ] , V_232 , V_568 ) ;
F_91 ( V_620 ) ;
}
for ( V_59 = 0 ; V_59 < V_618 ; V_59 ++ ) {
for ( V_332 = 0 ; V_332 < V_609 && ! V_621 ; V_332 ++ ) {
if ( F_543 ( V_619 [ V_59 ] , V_610 [ V_332 ] )
&& F_652 ( V_620 , V_59 , V_612 , V_332 ) )
goto V_623;
}
F_645 ( V_619 [ V_59 ] , V_620 ? V_620 + V_59 : NULL ) ;
V_623:
;
}
if ( V_610 != & V_611 )
F_647 ( V_610 , V_609 ) ;
F_560 ( V_612 ) ;
V_610 = V_619 ;
V_612 = V_620 ;
V_609 = V_618 ;
F_565 () ;
F_655 ( & V_575 ) ;
}
static void F_656 ( void )
{
F_480 () ;
F_653 ( 0 , NULL , NULL ) ;
F_657 () ;
F_481 () ;
}
static T_4 F_658 ( const char * V_67 , T_6 V_624 , int V_625 )
{
unsigned int V_533 = 0 ;
if ( sscanf ( V_67 , L_53 , & V_533 ) != 1 )
return - V_71 ;
if ( V_533 >= V_626 )
return - V_71 ;
if ( V_625 )
V_627 = V_533 ;
else
V_628 = V_533 ;
F_656 () ;
return V_624 ;
}
static T_4 F_659 ( struct V_629 * V_205 ,
struct V_630 * V_585 ,
char * V_631 )
{
return sprintf ( V_631 , L_54 , V_628 ) ;
}
static T_4 F_660 ( struct V_629 * V_205 ,
struct V_630 * V_585 ,
const char * V_67 , T_6 V_624 )
{
return F_658 ( V_67 , V_624 , 0 ) ;
}
static T_4 F_661 ( struct V_629 * V_632 ,
struct V_630 * V_585 ,
char * V_631 )
{
return sprintf ( V_631 , L_54 , V_627 ) ;
}
static T_4 F_662 ( struct V_629 * V_632 ,
struct V_630 * V_585 ,
const char * V_67 , T_6 V_624 )
{
return F_658 ( V_67 , V_624 , 1 ) ;
}
int T_8 F_663 ( struct V_629 * V_633 )
{
int V_526 = 0 ;
#ifdef F_664
if ( F_665 () )
V_526 = F_666 ( & V_633 -> V_634 . V_635 ,
& V_636 . V_585 ) ;
#endif
#ifdef F_667
if ( ! V_526 && F_668 () )
V_526 = F_666 ( & V_633 -> V_634 . V_635 ,
& V_637 . V_585 ) ;
#endif
return V_526 ;
}
static int F_669 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
switch ( V_97 & ~ V_520 ) {
case V_522 :
case V_525 :
F_670 () ;
return V_105 ;
default:
return V_106 ;
}
}
static int F_671 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
switch ( V_97 & ~ V_520 ) {
case V_101 :
F_670 () ;
return V_105 ;
default:
return V_106 ;
}
}
static int F_672 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
int V_45 = ( int ) ( long ) V_98 ;
switch ( V_97 ) {
case V_101 :
case V_102 :
F_673 ( F_51 ( V_45 ) ) ;
return V_105 ;
case V_525 :
case V_638 :
case V_522 :
case V_639 :
F_674 ( F_51 ( V_45 ) ) ;
return V_105 ;
default:
return V_106 ;
}
}
void T_8 F_675 ( void )
{
T_21 V_640 ;
F_483 ( & V_640 , V_447 ) ;
F_483 ( & V_611 , V_447 ) ;
F_480 () ;
F_654 ( & V_575 ) ;
F_648 ( V_232 ) ;
F_650 ( V_640 , V_576 , V_568 ) ;
if ( F_676 ( V_640 ) )
F_572 ( F_92 () , V_640 ) ;
F_655 ( & V_575 ) ;
F_481 () ;
F_100 ( F_669 , V_641 ) ;
F_100 ( F_671 , V_642 ) ;
F_100 ( F_672 , 0 ) ;
F_99 () ;
if ( F_487 ( V_81 , V_640 ) < 0 )
F_398 () ;
F_541 () ;
F_490 ( V_640 ) ;
F_677 () ;
}
void T_8 F_675 ( void )
{
F_541 () ;
}
int F_678 ( unsigned long V_380 )
{
return F_377 ( V_380 ) ||
( V_380 >= ( unsigned long ) V_643
&& V_380 < ( unsigned long ) V_644 ) ;
}
static void F_679 ( struct V_40 * V_40 )
{
V_40 -> V_645 = V_646 ;
F_32 ( & V_40 -> V_647 ) ;
V_40 -> V_648 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_680
V_40 -> V_649 = V_40 -> V_648 ;
#endif
}
static void F_681 ( struct V_53 * V_53 , struct V_44 * V_44 )
{
struct V_650 * V_651 ;
int V_59 ;
V_651 = & V_53 -> V_311 ;
for ( V_59 = 0 ; V_59 < V_159 ; V_59 ++ ) {
F_32 ( V_651 -> V_652 + V_59 ) ;
F_682 ( V_59 , V_651 -> V_653 ) ;
}
F_683 ( V_159 , V_651 -> V_653 ) ;
#if F_191 F_38
V_53 -> V_654 . V_76 = V_159 ;
V_53 -> V_654 . V_78 = V_159 ;
V_53 -> V_655 = 0 ;
V_53 -> V_656 = 0 ;
F_684 ( & V_53 -> V_286 ) ;
#endif
V_53 -> V_657 = 0 ;
V_53 -> V_658 = 0 ;
V_53 -> V_20 = 0 ;
F_10 ( & V_53 -> V_21 ) ;
}
static void F_685 ( struct V_33 * V_34 , struct V_40 * V_40 ,
struct V_659 * V_50 , int V_45 ,
struct V_659 * V_51 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
V_40 -> V_34 = V_34 ;
V_40 -> V_44 = V_44 ;
#ifdef F_38
V_40 -> V_660 = 1 ;
#endif
F_33 ( V_40 ) ;
V_34 -> V_40 [ V_45 ] = V_40 ;
V_34 -> V_50 [ V_45 ] = V_50 ;
if ( ! V_50 )
return;
if ( ! V_51 )
V_50 -> V_40 = & V_44 -> V_393 ;
else
V_50 -> V_40 = V_51 -> V_661 ;
V_50 -> V_661 = V_40 ;
F_130 ( & V_50 -> V_138 , 0 ) ;
V_50 -> V_51 = V_51 ;
}
static void F_686 ( struct V_33 * V_34 , struct V_53 * V_53 ,
struct V_662 * V_54 , int V_45 ,
struct V_662 * V_51 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
V_53 -> V_654 . V_76 = V_159 ;
V_53 -> V_663 = 0 ;
V_53 -> V_44 = V_44 ;
V_53 -> V_34 = V_34 ;
V_34 -> V_53 [ V_45 ] = V_53 ;
V_34 -> V_54 [ V_45 ] = V_54 ;
if ( ! V_54 )
return;
if ( ! V_51 )
V_54 -> V_53 = & V_44 -> V_52 ;
else
V_54 -> V_53 = V_51 -> V_661 ;
V_54 -> V_661 = V_53 ;
V_54 -> V_51 = V_51 ;
F_32 ( & V_54 -> V_279 ) ;
}
void T_8 F_687 ( void )
{
int V_59 , V_332 ;
unsigned long V_664 = 0 , V_665 ;
#ifdef F_44
V_664 += 2 * V_233 * sizeof( void * * ) ;
#endif
#ifdef F_45
V_664 += 2 * V_233 * sizeof( void * * ) ;
#endif
#ifdef F_688
V_664 += F_566 () * F_492 () ;
#endif
if ( V_664 ) {
V_665 = ( unsigned long ) F_689 ( V_664 , V_666 ) ;
#ifdef F_44
V_146 . V_50 = (struct V_659 * * ) V_665 ;
V_665 += V_233 * sizeof( void * * ) ;
V_146 . V_40 = (struct V_40 * * ) V_665 ;
V_665 += V_233 * sizeof( void * * ) ;
#endif
#ifdef F_45
V_146 . V_54 = (struct V_662 * * ) V_665 ;
V_665 += V_233 * sizeof( void * * ) ;
V_146 . V_53 = (struct V_53 * * ) V_665 ;
V_665 += V_233 * sizeof( void * * ) ;
#endif
#ifdef F_688
F_315 (i) {
F_178 ( V_667 , V_59 ) = ( void * ) V_665 ;
V_665 += F_492 () ;
}
#endif
}
#ifdef F_38
F_599 () ;
#endif
F_8 ( & V_668 ,
F_62 () , F_63 () ) ;
#ifdef F_45
F_8 ( & V_146 . V_9 ,
F_62 () , F_63 () ) ;
#endif
#ifdef F_690
F_691 ( & V_146 . V_669 , & V_670 ) ;
F_32 ( & V_146 . V_671 ) ;
F_692 ( & V_672 ) ;
#endif
F_315 (i) {
struct V_44 * V_44 ;
V_44 = F_51 ( V_59 ) ;
F_10 ( & V_44 -> V_37 ) ;
V_44 -> V_151 = 0 ;
V_44 -> V_310 = 0 ;
V_44 -> V_321 = V_320 + V_323 ;
F_679 ( & V_44 -> V_393 ) ;
F_681 ( & V_44 -> V_52 , V_44 ) ;
#ifdef F_44
V_146 . V_673 = V_674 ;
F_32 ( & V_44 -> V_675 ) ;
F_30 ( & V_146 . V_32 ) ;
F_685 ( & V_146 , & V_44 -> V_393 , NULL , V_59 , NULL ) ;
#endif
V_44 -> V_52 . V_20 = V_668 . V_20 ;
#ifdef F_45
F_32 ( & V_44 -> V_676 ) ;
F_686 ( & V_146 , & V_44 -> V_52 , NULL , V_59 , NULL ) ;
#endif
for ( V_332 = 0 ; V_332 < V_342 ; V_332 ++ )
V_44 -> V_149 [ V_332 ] = 0 ;
V_44 -> V_341 = V_320 ;
#ifdef F_38
V_44 -> V_111 = NULL ;
V_44 -> V_517 = NULL ;
V_44 -> V_150 = V_542 ;
V_44 -> F_301 = 0 ;
V_44 -> V_677 = 0 ;
V_44 -> V_678 = V_320 ;
V_44 -> V_679 = 0 ;
V_44 -> V_45 = V_59 ;
V_44 -> V_516 = 0 ;
V_44 -> V_257 = 0 ;
V_44 -> V_258 = 2 * V_210 ;
F_594 ( V_44 , & V_562 ) ;
#ifdef F_693
V_44 -> V_113 = 0 ;
#endif
#endif
F_101 ( V_44 ) ;
F_600 ( & V_44 -> F_317 , 0 ) ;
}
F_162 ( & V_672 ) ;
#ifdef F_269
F_270 ( & V_672 . V_280 ) ;
#endif
#ifdef F_38
F_694 ( V_267 , V_680 ) ;
#endif
#ifdef F_695
F_684 ( & V_672 . V_681 ) ;
#endif
F_308 ( & V_487 . V_305 ) ;
F_309 ( & V_487 , V_81 ) ;
F_530 ( V_81 , F_92 () ) ;
V_321 = V_320 + V_323 ;
V_81 -> V_87 = & V_207 ;
#ifdef F_38
F_696 ( & V_543 , V_666 ) ;
#ifdef F_693
F_696 ( & V_682 . V_683 , V_666 ) ;
F_483 ( & V_682 . V_684 , V_666 ) ;
F_600 ( & V_682 . V_685 , V_233 ) ;
F_600 ( & V_682 . V_686 , V_233 ) ;
F_600 ( & V_682 . V_687 , V_233 ) ;
#endif
if ( V_568 == NULL )
F_696 ( & V_568 , V_666 ) ;
#endif
V_688 = 1 ;
}
static inline int F_697 ( int V_689 )
{
int V_690 = ( V_216 () & ~ V_217 ) + F_698 () ;
return ( V_690 == V_689 ) ;
}
void F_699 ( const char * V_62 , int line , int V_689 )
{
static unsigned long V_691 ;
F_393 () ;
if ( ( F_697 ( V_689 ) && ! F_151 () ) ||
V_692 != V_693 || V_694 )
return;
if ( F_331 ( V_320 , V_691 + V_227 ) && V_691 )
return;
V_691 = V_320 ;
F_234 ( V_388
L_55 ,
V_62 , line ) ;
F_234 ( V_388
L_56 ,
F_700 () , F_151 () ,
V_81 -> V_389 , V_81 -> V_236 ) ;
F_386 ( V_81 ) ;
if ( F_151 () )
F_388 ( V_81 ) ;
F_390 () ;
}
static void F_701 ( struct V_44 * V_44 , struct V_4 * V_5 )
{
const struct V_87 * V_200 = V_5 -> V_87 ;
int V_421 = V_5 -> V_157 ;
int V_206 ;
V_206 = V_5 -> V_206 ;
if ( V_206 )
F_170 ( V_44 , V_5 , 0 ) ;
F_467 ( V_44 , V_5 , V_282 , 0 ) ;
if ( V_206 ) {
F_168 ( V_44 , V_5 , 0 ) ;
F_102 ( V_44 -> V_76 ) ;
}
F_206 ( V_44 , V_5 , V_200 , V_421 ) ;
}
void F_702 ( void )
{
struct V_4 * V_467 , * V_5 ;
unsigned long V_84 ;
struct V_44 * V_44 ;
F_703 ( & V_695 , V_84 ) ;
F_523 (g, p) {
if ( ! V_5 -> V_234 )
continue;
V_5 -> V_50 . V_211 = 0 ;
#ifdef F_240
V_5 -> V_50 . V_244 . V_696 = 0 ;
V_5 -> V_50 . V_244 . V_697 = 0 ;
V_5 -> V_50 . V_244 . V_698 = 0 ;
#endif
if ( ! F_704 ( V_5 ) ) {
if ( F_347 ( V_5 ) < 0 && V_5 -> V_234 )
F_458 ( V_5 , 0 ) ;
continue;
}
F_21 ( & V_5 -> V_49 ) ;
V_44 = F_74 ( V_5 ) ;
F_701 ( V_44 , V_5 ) ;
F_80 ( V_44 ) ;
F_22 ( & V_5 -> V_49 ) ;
} F_525 ( V_467 , V_5 ) ;
F_705 ( & V_695 , V_84 ) ;
}
struct V_4 * F_706 ( int V_45 )
{
return F_112 ( V_45 ) ;
}
void V_419 ( int V_45 , struct V_4 * V_5 )
{
F_112 ( V_45 ) = V_5 ;
}
static void F_707 ( struct V_33 * V_34 )
{
int V_59 ;
F_36 ( F_25 ( V_34 ) ) ;
F_315 (i) {
if ( V_34 -> V_40 )
F_560 ( V_34 -> V_40 [ V_59 ] ) ;
if ( V_34 -> V_50 )
F_560 ( V_34 -> V_50 [ V_59 ] ) ;
}
F_560 ( V_34 -> V_40 ) ;
F_560 ( V_34 -> V_50 ) ;
}
static
int F_708 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
struct V_40 * V_40 ;
struct V_659 * V_50 ;
int V_59 ;
V_34 -> V_40 = F_689 ( sizeof( V_40 ) * V_233 , V_447 ) ;
if ( ! V_34 -> V_40 )
goto V_526;
V_34 -> V_50 = F_689 ( sizeof( V_50 ) * V_233 , V_447 ) ;
if ( ! V_34 -> V_50 )
goto V_526;
V_34 -> V_673 = V_699 ;
F_30 ( F_25 ( V_34 ) ) ;
F_315 (i) {
V_40 = F_624 ( sizeof( struct V_40 ) ,
V_447 , F_227 ( V_59 ) ) ;
if ( ! V_40 )
goto V_526;
V_50 = F_624 ( sizeof( struct V_659 ) ,
V_447 , F_227 ( V_59 ) ) ;
if ( ! V_50 )
goto V_700;
F_679 ( V_40 ) ;
F_685 ( V_34 , V_40 , V_50 , V_59 , V_51 -> V_50 [ V_59 ] ) ;
}
return 1 ;
V_700:
F_560 ( V_40 ) ;
V_526:
return 0 ;
}
static inline void F_709 ( struct V_33 * V_34 , int V_45 )
{
struct V_44 * V_44 = F_51 ( V_45 ) ;
unsigned long V_84 ;
if ( ! V_34 -> V_40 [ V_45 ] -> V_701 )
return;
F_78 ( & V_44 -> V_37 , V_84 ) ;
F_710 ( V_34 -> V_40 [ V_45 ] ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
}
static inline void F_707 ( struct V_33 * V_34 )
{
}
static inline
int F_708 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
return 1 ;
}
static inline void F_709 ( struct V_33 * V_34 , int V_45 )
{
}
static void F_711 ( struct V_33 * V_34 )
{
int V_59 ;
if ( V_34 -> V_54 )
F_23 ( & V_34 -> V_9 ) ;
F_315 (i) {
if ( V_34 -> V_53 )
F_560 ( V_34 -> V_53 [ V_59 ] ) ;
if ( V_34 -> V_54 )
F_560 ( V_34 -> V_54 [ V_59 ] ) ;
}
F_560 ( V_34 -> V_53 ) ;
F_560 ( V_34 -> V_54 ) ;
}
static
int F_712 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
struct V_53 * V_53 ;
struct V_662 * V_54 ;
int V_59 ;
V_34 -> V_53 = F_689 ( sizeof( V_53 ) * V_233 , V_447 ) ;
if ( ! V_34 -> V_53 )
goto V_526;
V_34 -> V_54 = F_689 ( sizeof( V_54 ) * V_233 , V_447 ) ;
if ( ! V_34 -> V_54 )
goto V_526;
F_8 ( & V_34 -> V_9 ,
F_17 ( V_668 . V_15 ) , 0 ) ;
F_315 (i) {
V_53 = F_624 ( sizeof( struct V_53 ) ,
V_447 , F_227 ( V_59 ) ) ;
if ( ! V_53 )
goto V_526;
V_54 = F_624 ( sizeof( struct V_662 ) ,
V_447 , F_227 ( V_59 ) ) ;
if ( ! V_54 )
goto V_700;
F_681 ( V_53 , F_51 ( V_59 ) ) ;
V_53 -> V_20 = V_34 -> V_9 . V_20 ;
F_686 ( V_34 , V_53 , V_54 , V_59 , V_51 -> V_54 [ V_59 ] ) ;
}
return 1 ;
V_700:
F_560 ( V_53 ) ;
V_526:
return 0 ;
}
static inline void F_711 ( struct V_33 * V_34 )
{
}
static inline
int F_712 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
return 1 ;
}
static void F_713 ( struct V_33 * V_34 )
{
F_707 ( V_34 ) ;
F_711 ( V_34 ) ;
F_714 ( V_34 ) ;
F_560 ( V_34 ) ;
}
struct V_33 * F_715 ( struct V_33 * V_51 )
{
struct V_33 * V_34 ;
unsigned long V_84 ;
V_34 = F_689 ( sizeof( * V_34 ) , V_447 ) ;
if ( ! V_34 )
return F_716 ( - V_448 ) ;
if ( ! F_708 ( V_34 , V_51 ) )
goto V_526;
if ( ! F_712 ( V_34 , V_51 ) )
goto V_526;
F_422 ( & V_702 , V_84 ) ;
F_717 ( & V_34 -> V_669 , & V_670 ) ;
F_567 ( ! V_51 ) ;
V_34 -> V_51 = V_51 ;
F_32 ( & V_34 -> V_671 ) ;
F_717 ( & V_34 -> V_703 , & V_51 -> V_671 ) ;
F_423 ( & V_702 , V_84 ) ;
return V_34 ;
V_526:
F_713 ( V_34 ) ;
return F_716 ( - V_448 ) ;
}
static void F_718 ( struct V_552 * V_704 )
{
F_713 ( F_4 ( V_704 , struct V_33 , V_553 ) ) ;
}
void F_719 ( struct V_33 * V_34 )
{
unsigned long V_84 ;
int V_59 ;
F_315 (i)
F_709 ( V_34 , V_59 ) ;
F_422 ( & V_702 , V_84 ) ;
F_720 ( & V_34 -> V_669 ) ;
F_720 ( & V_34 -> V_703 ) ;
F_423 ( & V_702 , V_84 ) ;
F_606 ( & V_34 -> V_553 , F_718 ) ;
}
void F_721 ( struct V_4 * V_133 )
{
int V_206 , V_222 ;
unsigned long V_84 ;
struct V_44 * V_44 ;
V_44 = F_77 ( V_133 , & V_84 ) ;
V_222 = F_64 ( V_44 , V_133 ) ;
V_206 = V_133 -> V_206 ;
if ( V_206 )
F_166 ( V_44 , V_133 , 0 ) ;
if ( F_35 ( V_222 ) )
V_133 -> V_87 -> F_396 ( V_44 , V_133 ) ;
#ifdef F_44
if ( V_133 -> V_87 -> V_705 )
V_133 -> V_87 -> V_705 ( V_133 , V_206 ) ;
else
#endif
F_43 ( V_133 , F_106 ( V_133 ) ) ;
if ( F_35 ( V_222 ) )
V_133 -> V_87 -> V_419 ( V_44 ) ;
if ( V_206 )
F_164 ( V_44 , V_133 , 0 ) ;
F_81 ( V_44 , V_133 , & V_84 ) ;
}
int F_722 ( struct V_33 * V_34 , unsigned long V_673 )
{
int V_59 ;
unsigned long V_84 ;
if ( ! V_34 -> V_50 [ 0 ] )
return - V_71 ;
V_673 = F_723 ( V_673 , F_163 ( V_706 ) , F_163 ( V_707 ) ) ;
F_654 ( & V_708 ) ;
if ( V_34 -> V_673 == V_673 )
goto V_411;
V_34 -> V_673 = V_673 ;
F_315 (i) {
struct V_44 * V_44 = F_51 ( V_59 ) ;
struct V_659 * V_50 ;
V_50 = V_34 -> V_50 [ V_59 ] ;
F_78 ( & V_44 -> V_37 , V_84 ) ;
F_724 (se)
F_725 ( F_726 ( V_50 ) ) ;
F_79 ( & V_44 -> V_37 , V_84 ) ;
}
V_411:
F_655 ( & V_708 ) ;
return 0 ;
}
unsigned long F_727 ( struct V_33 * V_34 )
{
return V_34 -> V_673 ;
}
static unsigned long F_728 ( T_2 V_18 , T_2 V_19 )
{
if ( V_19 == V_31 )
return 1ULL << 20 ;
return F_729 ( V_19 << 20 , V_18 ) ;
}
static inline int F_730 ( struct V_33 * V_34 )
{
struct V_4 * V_467 , * V_5 ;
F_523 (g, p) {
if ( F_704 ( V_5 ) && F_731 ( & V_5 -> V_52 ) -> V_34 == V_34 )
return 1 ;
} F_525 ( V_467 , V_5 ) ;
return 0 ;
}
static int F_732 ( struct V_33 * V_34 , void * V_142 )
{
struct V_709 * V_589 = V_142 ;
struct V_33 * V_143 ;
unsigned long V_147 , V_306 = 0 ;
T_2 V_18 , V_19 ;
V_18 = F_17 ( V_34 -> V_9 . V_15 ) ;
V_19 = V_34 -> V_9 . V_20 ;
if ( V_34 == V_589 -> V_34 ) {
V_18 = V_589 -> V_15 ;
V_19 = V_589 -> V_20 ;
}
if ( V_19 > V_18 && V_19 != V_31 )
return - V_71 ;
if ( F_12 () && ! V_19 && F_730 ( V_34 ) )
return - V_710 ;
V_147 = F_728 ( V_18 , V_19 ) ;
if ( V_147 > F_728 ( F_62 () , F_63 () ) )
return - V_71 ;
F_136 (child, &tg->children, siblings) {
V_18 = F_17 ( V_143 -> V_9 . V_15 ) ;
V_19 = V_143 -> V_9 . V_20 ;
if ( V_143 == V_589 -> V_34 ) {
V_18 = V_589 -> V_15 ;
V_19 = V_589 -> V_20 ;
}
V_306 += F_728 ( V_18 , V_19 ) ;
}
if ( V_306 > V_147 )
return - V_71 ;
return 0 ;
}
static int F_733 ( struct V_33 * V_34 , T_2 V_18 , T_2 V_19 )
{
int V_144 ;
struct V_709 V_142 = {
. V_34 = V_34 ,
. V_15 = V_18 ,
. V_20 = V_19 ,
} ;
F_114 () ;
V_144 = F_137 ( F_732 , F_138 , & V_142 ) ;
F_118 () ;
return V_144 ;
}
static int F_734 ( struct V_33 * V_34 ,
T_2 V_15 , T_2 V_20 )
{
int V_59 , V_526 = 0 ;
F_654 ( & V_711 ) ;
F_735 ( & V_695 ) ;
V_526 = F_733 ( V_34 , V_15 , V_20 ) ;
if ( V_526 )
goto V_112;
F_401 ( & V_34 -> V_9 . V_21 ) ;
V_34 -> V_9 . V_15 = F_9 ( V_15 ) ;
V_34 -> V_9 . V_20 = V_20 ;
F_315 (i) {
struct V_53 * V_53 = V_34 -> V_53 [ V_59 ] ;
F_21 ( & V_53 -> V_21 ) ;
V_53 -> V_20 = V_20 ;
F_22 ( & V_53 -> V_21 ) ;
}
F_71 ( & V_34 -> V_9 . V_21 ) ;
V_112:
F_736 ( & V_695 ) ;
F_655 ( & V_711 ) ;
return V_526 ;
}
int F_737 ( struct V_33 * V_34 , long V_712 )
{
T_2 V_20 , V_15 ;
V_15 = F_17 ( V_34 -> V_9 . V_15 ) ;
V_20 = ( T_2 ) V_712 * V_75 ;
if ( V_712 < 0 )
V_20 = V_31 ;
return F_734 ( V_34 , V_15 , V_20 ) ;
}
long F_738 ( struct V_33 * V_34 )
{
T_2 V_712 ;
if ( V_34 -> V_9 . V_20 == V_31 )
return - 1 ;
V_712 = V_34 -> V_9 . V_20 ;
F_370 ( V_712 , V_75 ) ;
return V_712 ;
}
int F_739 ( struct V_33 * V_34 , long V_713 )
{
T_2 V_20 , V_15 ;
V_15 = ( T_2 ) V_713 * V_75 ;
V_20 = V_34 -> V_9 . V_20 ;
if ( V_15 == 0 )
return - V_71 ;
return F_734 ( V_34 , V_15 , V_20 ) ;
}
long F_740 ( struct V_33 * V_34 )
{
T_2 V_713 ;
V_713 = F_17 ( V_34 -> V_9 . V_15 ) ;
F_370 ( V_713 , V_75 ) ;
return V_713 ;
}
static int F_741 ( void )
{
T_2 V_19 , V_18 ;
int V_144 = 0 ;
if ( V_74 <= 0 )
return - V_71 ;
V_19 = F_63 () ;
V_18 = F_62 () ;
if ( V_19 > V_18 && V_19 != V_31 )
return - V_71 ;
F_654 ( & V_711 ) ;
F_735 ( & V_695 ) ;
V_144 = F_733 ( NULL , 0 , 0 ) ;
F_736 ( & V_695 ) ;
F_655 ( & V_711 ) ;
return V_144 ;
}
int F_742 ( struct V_33 * V_34 , struct V_4 * V_133 )
{
if ( F_704 ( V_133 ) && V_34 -> V_9 . V_20 == 0 )
return 0 ;
return 1 ;
}
static int F_741 ( void )
{
unsigned long V_84 ;
int V_59 ;
if ( V_74 <= 0 )
return - V_71 ;
if ( V_25 == 0 )
return - V_710 ;
F_78 ( & V_668 . V_21 , V_84 ) ;
F_315 (i) {
struct V_53 * V_53 = & F_51 ( V_59 ) -> V_52 ;
F_21 ( & V_53 -> V_21 ) ;
V_53 -> V_20 = F_63 () ;
F_22 ( & V_53 -> V_21 ) ;
}
F_79 ( & V_668 . V_21 , V_84 ) ;
return 0 ;
}
int F_743 ( struct V_490 * V_496 , int V_714 ,
void T_5 * V_715 , T_6 * V_716 ,
T_7 * V_66 )
{
int V_144 ;
int V_717 , V_718 ;
static F_744 ( V_399 ) ;
F_654 ( & V_399 ) ;
V_717 = V_74 ;
V_718 = V_25 ;
V_144 = F_745 ( V_496 , V_714 , V_715 , V_716 , V_66 ) ;
if ( ! V_144 && V_714 ) {
V_144 = F_741 () ;
if ( V_144 ) {
V_74 = V_717 ;
V_25 = V_718 ;
} else {
V_668 . V_20 = F_63 () ;
V_668 . V_15 =
F_9 ( F_62 () ) ;
}
}
F_655 ( & V_399 ) ;
return V_144 ;
}
static inline struct V_33 * F_746 ( struct V_719 * V_720 )
{
return F_4 ( V_46 ( V_720 , V_48 ) ,
struct V_33 , V_47 ) ;
}
static struct V_46 *
F_747 ( struct V_721 * V_722 , struct V_719 * V_720 )
{
struct V_33 * V_34 , * V_51 ;
if ( ! V_720 -> V_51 ) {
return & V_146 . V_47 ;
}
V_51 = F_746 ( V_720 -> V_51 ) ;
V_34 = F_715 ( V_51 ) ;
if ( F_748 ( V_34 ) )
return F_716 ( - V_448 ) ;
return & V_34 -> V_47 ;
}
static void
F_749 ( struct V_721 * V_722 , struct V_719 * V_720 )
{
struct V_33 * V_34 = F_746 ( V_720 ) ;
F_719 ( V_34 ) ;
}
static int
F_750 ( struct V_719 * V_720 , struct V_4 * V_133 )
{
#ifdef F_45
if ( ! F_742 ( F_746 ( V_720 ) , V_133 ) )
return - V_71 ;
#else
if ( V_133 -> V_87 != & V_207 )
return - V_71 ;
#endif
return 0 ;
}
static void
F_751 ( struct V_719 * V_720 , struct V_4 * V_133 )
{
F_721 ( V_133 ) ;
}
static void
F_752 ( struct V_721 * V_722 , struct V_719 * V_720 ,
struct V_719 * V_723 , struct V_4 * V_486 )
{
if ( ! ( V_486 -> V_84 & V_724 ) )
return;
F_721 ( V_486 ) ;
}
static int F_753 ( struct V_719 * V_720 , struct V_725 * V_725 ,
T_2 V_726 )
{
return F_722 ( F_746 ( V_720 ) , F_163 ( V_726 ) ) ;
}
static T_2 F_754 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
struct V_33 * V_34 = F_746 ( V_720 ) ;
return ( T_2 ) F_125 ( V_34 -> V_673 ) ;
}
static int F_755 ( struct V_33 * V_34 , T_2 V_18 , T_2 V_38 )
{
int V_59 , V_144 = 0 , V_41 ;
struct V_32 * V_35 = F_25 ( V_34 ) ;
if ( V_34 == & V_146 )
return - V_71 ;
if ( V_38 < V_728 || V_18 < V_728 )
return - V_71 ;
if ( V_18 > V_729 )
return - V_71 ;
F_654 ( & V_730 ) ;
V_144 = F_756 ( V_34 , V_18 , V_38 ) ;
if ( V_144 )
goto V_422;
V_41 = V_38 != V_31 ;
F_401 ( & V_35 -> V_37 ) ;
V_35 -> V_18 = F_9 ( V_18 ) ;
V_35 -> V_38 = V_38 ;
F_757 ( V_35 ) ;
if ( V_41 && V_35 -> V_43 ) {
V_35 -> V_43 = 0 ;
F_34 ( V_35 ) ;
}
F_71 ( & V_35 -> V_37 ) ;
F_315 (i) {
struct V_40 * V_40 = V_34 -> V_40 [ V_59 ] ;
struct V_44 * V_44 = F_758 ( V_40 ) ;
F_401 ( & V_44 -> V_37 ) ;
V_40 -> V_41 = V_41 ;
V_40 -> V_488 = 0 ;
if ( F_554 ( V_40 ) )
F_555 ( V_40 ) ;
F_71 ( & V_44 -> V_37 ) ;
}
V_422:
F_655 ( & V_730 ) ;
return V_144 ;
}
int F_759 ( struct V_33 * V_34 , long V_731 )
{
T_2 V_38 , V_18 ;
V_18 = F_17 ( F_25 ( V_34 ) -> V_18 ) ;
if ( V_731 < 0 )
V_38 = V_31 ;
else
V_38 = ( T_2 ) V_731 * V_75 ;
return F_755 ( V_34 , V_18 , V_38 ) ;
}
long F_760 ( struct V_33 * V_34 )
{
T_2 V_732 ;
if ( F_25 ( V_34 ) -> V_38 == V_31 )
return - 1 ;
V_732 = F_25 ( V_34 ) -> V_38 ;
F_370 ( V_732 , V_75 ) ;
return V_732 ;
}
int F_761 ( struct V_33 * V_34 , long V_733 )
{
T_2 V_38 , V_18 ;
V_18 = ( T_2 ) V_733 * V_75 ;
V_38 = F_25 ( V_34 ) -> V_38 ;
if ( V_18 <= 0 )
return - V_71 ;
return F_755 ( V_34 , V_18 , V_38 ) ;
}
long F_762 ( struct V_33 * V_34 )
{
T_2 V_733 ;
V_733 = F_17 ( F_25 ( V_34 ) -> V_18 ) ;
F_370 ( V_733 , V_75 ) ;
return V_733 ;
}
static T_3 F_763 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
return F_760 ( F_746 ( V_720 ) ) ;
}
static int F_764 ( struct V_719 * V_720 , struct V_725 * V_725 ,
T_3 V_731 )
{
return F_759 ( F_746 ( V_720 ) , V_731 ) ;
}
static T_2 F_765 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
return F_762 ( F_746 ( V_720 ) ) ;
}
static int F_766 ( struct V_719 * V_720 , struct V_725 * V_725 ,
T_2 V_733 )
{
return F_761 ( F_746 ( V_720 ) , V_733 ) ;
}
static T_2 F_767 ( struct V_33 * V_34 ,
struct V_734 * V_589 )
{
T_2 V_38 , V_18 ;
if ( V_34 == V_589 -> V_34 ) {
V_18 = V_589 -> V_18 ;
V_38 = V_589 -> V_38 ;
} else {
V_18 = F_762 ( V_34 ) ;
V_38 = F_760 ( V_34 ) ;
}
if ( V_38 == V_31 || V_38 == - 1 )
return V_31 ;
return F_728 ( V_18 , V_38 ) ;
}
static int F_768 ( struct V_33 * V_34 , void * V_142 )
{
struct V_734 * V_589 = V_142 ;
struct V_32 * V_35 = F_25 ( V_34 ) ;
T_3 V_38 = 0 , V_735 = - 1 ;
if ( ! V_34 -> V_51 ) {
V_38 = V_31 ;
} else {
struct V_32 * V_736 = F_25 ( V_34 -> V_51 ) ;
V_38 = F_767 ( V_34 , V_589 ) ;
V_735 = V_736 -> V_737 ;
if ( V_38 == V_31 )
V_38 = V_735 ;
else if ( V_735 != V_31 && V_38 > V_735 )
return - V_71 ;
}
V_35 -> V_737 = V_38 ;
return 0 ;
}
static int F_756 ( struct V_33 * V_34 , T_2 V_18 , T_2 V_38 )
{
int V_144 ;
struct V_734 V_142 = {
. V_34 = V_34 ,
. V_18 = V_18 ,
. V_38 = V_38 ,
} ;
if ( V_38 != V_31 ) {
F_370 ( V_142 . V_18 , V_75 ) ;
F_370 ( V_142 . V_38 , V_75 ) ;
}
F_114 () ;
V_144 = F_137 ( F_768 , F_138 , & V_142 ) ;
F_118 () ;
return V_144 ;
}
static int F_769 ( struct V_719 * V_720 , struct V_725 * V_727 ,
struct V_738 * V_739 )
{
struct V_33 * V_34 = F_746 ( V_720 ) ;
struct V_32 * V_35 = F_25 ( V_34 ) ;
V_739 -> V_740 ( V_739 , L_57 , V_35 -> V_741 ) ;
V_739 -> V_740 ( V_739 , L_58 , V_35 -> V_742 ) ;
V_739 -> V_740 ( V_739 , L_59 , V_35 -> V_743 ) ;
return 0 ;
}
static int F_770 ( struct V_719 * V_720 , struct V_725 * V_727 ,
T_3 V_137 )
{
return F_737 ( F_746 ( V_720 ) , V_137 ) ;
}
static T_3 F_771 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
return F_738 ( F_746 ( V_720 ) ) ;
}
static int F_772 ( struct V_719 * V_720 , struct V_725 * V_725 ,
T_2 V_713 )
{
return F_739 ( F_746 ( V_720 ) , V_713 ) ;
}
static T_2 F_773 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
return F_740 ( F_746 ( V_720 ) ) ;
}
static int F_774 ( struct V_721 * V_722 , struct V_719 * V_744 )
{
return F_775 ( V_744 , V_722 , V_745 , F_776 ( V_745 ) ) ;
}
static inline struct V_746 * F_777 ( struct V_719 * V_720 )
{
return F_4 ( V_46 ( V_720 , V_747 ) ,
struct V_746 , V_47 ) ;
}
static inline struct V_746 * F_778 ( struct V_4 * V_133 )
{
return F_4 ( F_779 ( V_133 , V_747 ) ,
struct V_746 , V_47 ) ;
}
static struct V_46 * F_780 (
struct V_721 * V_722 , struct V_719 * V_720 )
{
struct V_746 * V_748 = F_689 ( sizeof( * V_748 ) , V_447 ) ;
int V_59 ;
if ( ! V_748 )
goto V_145;
V_748 -> V_749 = F_640 ( T_2 ) ;
if ( ! V_748 -> V_749 )
goto V_750;
for ( V_59 = 0 ; V_59 < V_751 ; V_59 ++ )
if ( F_781 ( & V_748 -> V_187 [ V_59 ] , 0 ) )
goto V_752;
if ( V_720 -> V_51 )
V_748 -> V_51 = F_777 ( V_720 -> V_51 ) ;
return & V_748 -> V_47 ;
V_752:
while ( -- V_59 >= 0 )
F_782 ( & V_748 -> V_187 [ V_59 ] ) ;
F_636 ( V_748 -> V_749 ) ;
V_750:
F_560 ( V_748 ) ;
V_145:
return F_716 ( - V_448 ) ;
}
static void
F_783 ( struct V_721 * V_722 , struct V_719 * V_720 )
{
struct V_746 * V_748 = F_777 ( V_720 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_751 ; V_59 ++ )
F_782 ( & V_748 -> V_187 [ V_59 ] ) ;
F_636 ( V_748 -> V_749 ) ;
F_560 ( V_748 ) ;
}
static T_2 F_784 ( struct V_746 * V_748 , int V_45 )
{
T_2 * V_749 = F_625 ( V_748 -> V_749 , V_45 ) ;
T_2 V_142 ;
#ifndef F_680
F_401 ( & F_51 ( V_45 ) -> V_37 ) ;
V_142 = * V_749 ;
F_71 ( & F_51 ( V_45 ) -> V_37 ) ;
#else
V_142 = * V_749 ;
#endif
return V_142 ;
}
static void F_785 ( struct V_746 * V_748 , int V_45 , T_2 V_137 )
{
T_2 * V_749 = F_625 ( V_748 -> V_749 , V_45 ) ;
#ifndef F_680
F_401 ( & F_51 ( V_45 ) -> V_37 ) ;
* V_749 = V_137 ;
F_71 ( & F_51 ( V_45 ) -> V_37 ) ;
#else
* V_749 = V_137 ;
#endif
}
static T_2 F_786 ( struct V_719 * V_720 , struct V_725 * V_727 )
{
struct V_746 * V_748 = F_777 ( V_720 ) ;
T_2 V_753 = 0 ;
int V_59 ;
F_787 (i)
V_753 += F_784 ( V_748 , V_59 ) ;
return V_753 ;
}
static int F_788 ( struct V_719 * V_720 , struct V_725 * V_725 ,
T_2 V_754 )
{
struct V_746 * V_748 = F_777 ( V_720 ) ;
int V_526 = 0 ;
int V_59 ;
if ( V_754 ) {
V_526 = - V_71 ;
goto V_145;
}
F_787 (i)
F_785 ( V_748 , V_59 , 0 ) ;
V_145:
return V_526 ;
}
static int F_789 ( struct V_719 * V_719 , struct V_725 * V_727 ,
struct V_56 * V_57 )
{
struct V_746 * V_748 = F_777 ( V_719 ) ;
T_2 V_755 ;
int V_59 ;
F_787 (i) {
V_755 = F_784 ( V_748 , V_59 ) ;
F_54 ( V_57 , L_60 , ( unsigned long long ) V_755 ) ;
}
F_54 ( V_57 , L_3 ) ;
return 0 ;
}
static int F_790 ( struct V_719 * V_720 , struct V_725 * V_727 ,
struct V_738 * V_739 )
{
struct V_746 * V_748 = F_777 ( V_720 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_751 ; V_59 ++ ) {
T_3 V_137 = F_791 ( & V_748 -> V_187 [ V_59 ] ) ;
V_137 = F_792 ( V_137 ) ;
V_739 -> V_740 ( V_739 , V_756 [ V_59 ] , V_137 ) ;
}
return 0 ;
}
static int F_793 ( struct V_721 * V_722 , struct V_719 * V_720 )
{
return F_775 ( V_720 , V_722 , V_757 , F_776 ( V_757 ) ) ;
}
static void F_131 ( struct V_4 * V_133 , T_2 V_134 )
{
struct V_746 * V_748 ;
int V_45 ;
if ( F_35 ( ! V_758 . V_311 ) )
return;
V_45 = F_106 ( V_133 ) ;
F_114 () ;
V_748 = F_778 ( V_133 ) ;
for (; V_748 ; V_748 = V_748 -> V_51 ) {
T_2 * V_749 = F_625 ( V_748 -> V_749 , V_45 ) ;
* V_749 += V_134 ;
}
F_118 () ;
}
static void F_132 ( struct V_4 * V_133 ,
enum V_135 V_136 , T_9 V_137 )
{
struct V_746 * V_748 ;
int V_759 = V_760 ;
if ( F_35 ( ! V_758 . V_311 ) )
return;
F_114 () ;
V_748 = F_778 ( V_133 ) ;
do {
F_794 ( & V_748 -> V_187 [ V_136 ] , V_137 , V_759 ) ;
V_748 = V_748 -> V_51 ;
} while ( V_748 );
F_118 () ;
}
