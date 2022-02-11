static inline int F_1 ( int V_1 )
{
if ( F_2 ( V_1 == V_2 || V_1 == V_3 ) )
return 1 ;
return 0 ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 ) ;
}
static enum V_6 F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_5 ( V_8 , struct V_9 , V_11 ) ;
T_1 V_12 ;
int V_13 ;
int V_14 = 0 ;
for (; ; ) {
V_12 = F_6 ( V_8 ) ;
V_13 = F_7 ( V_8 , V_12 , V_10 -> V_15 ) ;
if ( ! V_13 )
break;
V_14 = F_8 ( V_10 , V_13 ) ;
}
return V_14 ? V_16 : V_17 ;
}
static
void F_9 ( struct V_9 * V_10 , T_2 V_18 , T_2 V_19 )
{
V_10 -> V_15 = F_10 ( V_18 ) ;
V_10 -> V_20 = V_19 ;
F_11 ( & V_10 -> V_21 ) ;
F_12 ( & V_10 -> V_11 ,
V_22 , V_23 ) ;
V_10 -> V_11 . V_24 = F_4 ;
}
static inline int F_13 ( void )
{
return V_25 >= 0 ;
}
static void F_14 ( struct V_9 * V_10 )
{
T_1 V_12 ;
if ( ! F_13 () || V_10 -> V_20 == V_26 )
return;
if ( F_15 ( & V_10 -> V_11 ) )
return;
F_16 ( & V_10 -> V_21 ) ;
for (; ; ) {
unsigned long V_27 ;
T_1 V_28 , V_29 ;
if ( F_15 ( & V_10 -> V_11 ) )
break;
V_12 = F_6 ( & V_10 -> V_11 ) ;
F_7 ( & V_10 -> V_11 , V_12 , V_10 -> V_15 ) ;
V_28 = F_17 ( & V_10 -> V_11 ) ;
V_29 = F_18 ( & V_10 -> V_11 ) ;
V_27 = F_19 ( F_20 ( V_29 , V_28 ) ) ;
F_21 ( & V_10 -> V_11 , V_28 , V_27 ,
V_30 , 0 ) ;
}
F_22 ( & V_10 -> V_21 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
F_24 ( & V_10 -> V_11 ) ;
}
static inline int F_25 ( struct V_31 * V_31 )
{
#ifdef F_26
return V_31 -> V_32 ;
#else
return 0 ;
#endif
}
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_36 = F_27 ( V_5 , V_37 ,
F_28 ( & V_5 -> V_38 ) ||
F_28 ( & F_29 ( V_5 ) -> V_39 ) ) ;
V_34 = F_5 ( V_36 , struct V_33 , V_36 ) ;
return F_30 ( V_5 , V_34 ) ;
}
static inline void F_31 ( struct V_4 * V_5 , unsigned int V_32 )
{
#ifdef F_32
V_5 -> V_40 . V_41 = V_33 ( V_5 ) -> V_41 [ V_32 ] ;
V_5 -> V_40 . V_42 = V_33 ( V_5 ) -> V_40 [ V_32 ] ;
#endif
#ifdef F_33
V_5 -> V_43 . V_44 = V_33 ( V_5 ) -> V_44 [ V_32 ] ;
V_5 -> V_43 . V_42 = V_33 ( V_5 ) -> V_45 [ V_32 ] ;
#endif
}
static inline void F_31 ( struct V_4 * V_5 , unsigned int V_32 ) { }
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
return NULL ;
}
static void F_34 ( struct V_31 * V_31 )
{
T_3 V_27 ;
if ( V_31 -> V_46 > 0 )
return;
V_27 = F_35 ( F_25 ( V_31 ) ) - V_31 -> clock ;
V_31 -> clock += V_27 ;
F_36 ( V_31 , V_27 ) ;
}
int F_37 ( int V_32 )
{
return F_38 ( & F_39 ( V_32 ) -> V_39 ) ;
}
static int F_40 ( struct V_47 * V_48 , void * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_51 [ V_50 ] ; V_50 ++ ) {
if ( ! ( V_52 & ( 1UL << V_50 ) ) )
F_41 ( V_48 , L_1 ) ;
F_42 ( V_48 , L_2 , V_51 [ V_50 ] ) ;
}
F_41 ( V_48 , L_3 ) ;
return 0 ;
}
static T_4
F_43 ( struct V_53 * V_54 , const char T_5 * V_55 ,
T_6 V_56 , T_7 * V_57 )
{
char V_58 [ 64 ] ;
char * V_59 ;
int V_60 = 0 ;
int V_50 ;
if ( V_56 > 63 )
V_56 = 63 ;
if ( F_44 ( & V_58 , V_55 , V_56 ) )
return - V_61 ;
V_58 [ V_56 ] = 0 ;
V_59 = F_45 ( V_58 ) ;
if ( strncmp ( V_59 , L_1 , 3 ) == 0 ) {
V_60 = 1 ;
V_59 += 3 ;
}
for ( V_50 = 0 ; V_51 [ V_50 ] ; V_50 ++ ) {
if ( strcmp ( V_59 , V_51 [ V_50 ] ) == 0 ) {
if ( V_60 )
V_52 &= ~ ( 1UL << V_50 ) ;
else
V_52 |= ( 1UL << V_50 ) ;
break;
}
}
if ( ! V_51 [ V_50 ] )
return - V_62 ;
* V_57 += V_56 ;
return V_56 ;
}
static int F_46 ( struct V_63 * V_63 , struct V_53 * V_54 )
{
return F_47 ( V_54 , F_40 , NULL ) ;
}
static T_8 int F_48 ( void )
{
F_49 ( L_4 , 0644 , NULL , NULL ,
& V_64 ) ;
return 0 ;
}
static inline T_2 F_50 ( void )
{
return ( T_2 ) V_65 * V_66 ;
}
static inline T_2 F_51 ( void )
{
if ( V_25 < 0 )
return V_26 ;
return ( T_2 ) V_25 * V_66 ;
}
static inline int F_52 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
return V_31 -> V_67 == V_5 ;
}
static inline int F_53 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
#ifdef F_26
return V_5 -> V_68 ;
#else
return F_52 ( V_31 , V_5 ) ;
#endif
}
static inline void F_54 ( struct V_31 * V_31 , struct V_4 * V_69 )
{
#ifdef F_26
V_69 -> V_68 = 1 ;
#endif
}
static inline void F_55 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
#ifdef F_26
F_56 () ;
V_70 -> V_68 = 0 ;
#endif
#ifdef F_57
V_31 -> V_39 . V_71 = V_72 ;
#endif
F_58 ( & V_31 -> V_39 . V_73 , 0 , 0 , V_74 ) ;
F_59 ( & V_31 -> V_39 ) ;
}
static inline void F_54 ( struct V_31 * V_31 , struct V_4 * V_69 )
{
#ifdef F_26
V_69 -> V_68 = 1 ;
#endif
#ifdef F_60
F_59 ( & V_31 -> V_39 ) ;
#else
F_22 ( & V_31 -> V_39 ) ;
#endif
}
static inline void F_55 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
#ifdef F_26
F_56 () ;
V_70 -> V_68 = 0 ;
#endif
#ifndef F_60
F_61 () ;
#endif
}
static inline struct V_31 * F_62 ( struct V_4 * V_5 )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
F_63 ( & V_5 -> V_38 ) ;
for (; ; ) {
V_31 = F_29 ( V_5 ) ;
F_16 ( & V_31 -> V_39 ) ;
if ( F_64 ( V_31 == F_29 ( V_5 ) ) )
return V_31 ;
F_22 ( & V_31 -> V_39 ) ;
}
}
static struct V_31 * F_65 ( struct V_4 * V_5 , unsigned long * V_75 )
__acquires( V_5 -> V_38 )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
for (; ; ) {
F_66 ( & V_5 -> V_38 , * V_75 ) ;
V_31 = F_29 ( V_5 ) ;
F_16 ( & V_31 -> V_39 ) ;
if ( F_64 ( V_31 == F_29 ( V_5 ) ) )
return V_31 ;
F_22 ( & V_31 -> V_39 ) ;
F_67 ( & V_5 -> V_38 , * V_75 ) ;
}
}
static void F_68 ( struct V_31 * V_31 )
__releases( V_31 -> V_39 )
{
F_22 ( & V_31 -> V_39 ) ;
}
static inline void
F_69 ( struct V_31 * V_31 , struct V_4 * V_5 , unsigned long * V_75 )
__releases( V_31 -> V_39 )
__releases( V_5 -> V_38 )
{
F_22 ( & V_31 -> V_39 ) ;
F_67 ( & V_5 -> V_38 , * V_75 ) ;
}
static struct V_31 * F_70 ( void )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
F_71 () ;
V_31 = F_72 () ;
F_16 ( & V_31 -> V_39 ) ;
return V_31 ;
}
static inline int F_73 ( struct V_31 * V_31 )
{
if ( ! F_74 ( V_76 ) )
return 0 ;
if ( ! F_75 ( F_25 ( V_31 ) ) )
return 0 ;
return F_76 ( & V_31 -> V_77 ) ;
}
static void F_77 ( struct V_31 * V_31 )
{
if ( F_15 ( & V_31 -> V_77 ) )
F_24 ( & V_31 -> V_77 ) ;
}
static enum V_6 F_78 ( struct V_7 * V_8 )
{
struct V_31 * V_31 = F_5 ( V_8 , struct V_31 , V_77 ) ;
F_79 ( F_25 ( V_31 ) != F_80 () ) ;
F_16 ( & V_31 -> V_39 ) ;
F_34 ( V_31 ) ;
V_31 -> V_67 -> V_78 -> V_79 ( V_31 , V_31 -> V_67 , 1 ) ;
F_22 ( & V_31 -> V_39 ) ;
return V_16 ;
}
static void F_81 ( void * V_80 )
{
struct V_31 * V_31 = V_80 ;
F_16 ( & V_31 -> V_39 ) ;
V_6 ( & V_31 -> V_77 ) ;
V_31 -> V_81 = 0 ;
F_22 ( & V_31 -> V_39 ) ;
}
static void F_82 ( struct V_31 * V_31 , T_2 V_82 )
{
struct V_7 * V_8 = & V_31 -> V_77 ;
T_1 time = F_83 ( V_8 -> V_83 -> V_84 () , V_82 ) ;
F_84 ( V_8 , time ) ;
if ( V_31 == F_72 () ) {
V_6 ( V_8 ) ;
} else if ( ! V_31 -> V_81 ) {
F_85 ( F_25 ( V_31 ) , & V_31 -> V_85 , 0 ) ;
V_31 -> V_81 = 1 ;
}
}
static int
F_86 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
int V_32 = ( int ) ( long ) V_89 ;
switch ( V_88 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
F_77 ( F_39 ( V_32 ) ) ;
return V_96 ;
}
return V_97 ;
}
static T_8 void F_87 ( void )
{
F_88 ( F_86 , 0 ) ;
}
static void F_82 ( struct V_31 * V_31 , T_2 V_82 )
{
F_21 ( & V_31 -> V_77 , F_10 ( V_82 ) , 0 ,
V_98 , 0 ) ;
}
static inline void F_87 ( void )
{
}
static void F_89 ( struct V_31 * V_31 )
{
#ifdef F_26
V_31 -> V_81 = 0 ;
V_31 -> V_85 . V_75 = 0 ;
V_31 -> V_85 . V_99 = F_81 ;
V_31 -> V_85 . V_100 = V_31 ;
#endif
F_12 ( & V_31 -> V_77 , V_22 , V_23 ) ;
V_31 -> V_77 . V_24 = F_78 ;
}
static inline void F_77 ( struct V_31 * V_31 )
{
}
static inline void F_89 ( struct V_31 * V_31 )
{
}
static inline void F_87 ( void )
{
}
static void F_90 ( struct V_4 * V_5 )
{
int V_32 ;
F_91 ( & F_29 ( V_5 ) -> V_39 ) ;
if ( F_92 ( V_5 ) )
return;
F_93 ( V_5 ) ;
V_32 = F_94 ( V_5 ) ;
if ( V_32 == F_80 () )
return;
F_95 () ;
if ( ! F_96 ( V_5 ) )
F_97 ( V_32 ) ;
}
static void F_98 ( int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_75 ;
if ( ! F_99 ( & V_31 -> V_39 , V_75 ) )
return;
F_90 ( F_100 ( V_32 ) ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
}
int F_101 ( void )
{
int V_32 = F_80 () ;
int V_50 ;
struct V_101 * V_102 ;
F_102 () ;
F_103 (cpu, sd) {
F_104 (i, sched_domain_span(sd)) {
if ( ! F_105 ( V_50 ) ) {
V_32 = V_50 ;
goto V_103;
}
}
}
V_103:
F_106 () ;
return V_32 ;
}
void F_107 ( int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
if ( V_32 == F_80 () )
return;
if ( V_31 -> V_67 != V_31 -> V_14 )
return;
F_93 ( V_31 -> V_14 ) ;
F_95 () ;
if ( ! F_96 ( V_31 -> V_14 ) )
F_97 ( V_32 ) ;
}
static T_2 F_108 ( void )
{
return ( T_2 ) V_104 * V_105 / 2 ;
}
static void F_109 ( struct V_31 * V_31 )
{
T_3 V_18 = F_108 () ;
while ( ( T_3 ) ( V_31 -> clock - V_31 -> V_106 ) > V_18 ) {
asm("" : "+rm" (rq->age_stamp));
V_31 -> V_106 += V_18 ;
V_31 -> V_107 /= 2 ;
}
}
static void F_110 ( struct V_31 * V_31 , T_2 V_108 )
{
V_31 -> V_107 += V_108 ;
F_109 ( V_31 ) ;
}
static void F_90 ( struct V_4 * V_5 )
{
F_91 ( & F_29 ( V_5 ) -> V_39 ) ;
F_93 ( V_5 ) ;
}
static void F_110 ( struct V_31 * V_31 , T_2 V_108 )
{
}
static void F_109 ( struct V_31 * V_31 )
{
}
static unsigned long
F_111 ( unsigned long V_109 , unsigned long V_110 ,
struct V_111 * V_112 )
{
T_2 V_113 ;
if ( F_64 ( V_110 > ( 1UL << V_114 ) ) )
V_113 = ( T_2 ) V_109 * F_112 ( V_110 ) ;
else
V_113 = ( T_2 ) V_109 ;
if ( ! V_112 -> V_115 ) {
unsigned long V_116 = F_112 ( V_112 -> V_110 ) ;
if ( V_117 > 32 && F_2 ( V_116 >= V_118 ) )
V_112 -> V_115 = 1 ;
else if ( F_2 ( ! V_116 ) )
V_112 -> V_115 = V_118 ;
else
V_112 -> V_115 = V_118 / V_116 ;
}
if ( F_2 ( V_113 > V_118 ) )
V_113 = F_113 ( F_113 ( V_113 , V_119 / 2 ) * V_112 -> V_115 ,
V_119 / 2 ) ;
else
V_113 = F_113 ( V_113 * V_112 -> V_115 , V_119 ) ;
return ( unsigned long ) F_114 ( V_113 , ( T_2 ) ( unsigned long ) V_120 ) ;
}
static inline void F_115 ( struct V_111 * V_112 , unsigned long V_121 )
{
V_112 -> V_110 += V_121 ;
V_112 -> V_115 = 0 ;
}
static inline void F_116 ( struct V_111 * V_112 , unsigned long V_122 )
{
V_112 -> V_110 -= V_122 ;
V_112 -> V_115 = 0 ;
}
static inline void F_117 ( struct V_111 * V_112 , unsigned long V_116 )
{
V_112 -> V_110 = V_116 ;
V_112 -> V_115 = 0 ;
}
static inline void F_118 ( struct V_4 * V_123 , T_2 V_124 ) {}
static inline void F_119 ( struct V_4 * V_123 ,
enum V_125 V_126 , T_9 V_127 ) {}
static inline void F_120 ( struct V_31 * V_31 , unsigned long V_128 )
{
F_115 ( & V_31 -> V_128 , V_128 ) ;
}
static inline void F_121 ( struct V_31 * V_31 , unsigned long V_128 )
{
F_116 ( & V_31 -> V_128 , V_128 ) ;
}
static int F_122 ( T_10 V_129 , T_10 V_130 , void * V_131 )
{
struct V_33 * V_42 , * V_132 ;
int V_133 ;
F_102 () ;
V_42 = & V_134 ;
V_129:
V_133 = (* V_129)( V_42 , V_131 ) ;
if ( V_133 )
goto V_135;
F_123 (child, &parent->children, siblings) {
V_42 = V_132 ;
goto V_129;
V_130:
continue;
}
V_133 = (* V_130)( V_42 , V_131 ) ;
if ( V_133 )
goto V_135;
V_132 = V_42 ;
V_42 = V_42 -> V_42 ;
if ( V_42 )
goto V_130;
V_135:
F_106 () ;
return V_133 ;
}
static int F_124 ( struct V_33 * V_34 , void * V_131 )
{
return 0 ;
}
static unsigned long F_125 ( const int V_32 )
{
return F_39 ( V_32 ) -> V_128 . V_110 ;
}
static unsigned long F_126 ( int V_32 , int type )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_136 = F_125 ( V_32 ) ;
if ( type == 0 || ! F_74 ( V_137 ) )
return V_136 ;
return F_114 ( V_31 -> V_138 [ type - 1 ] , V_136 ) ;
}
static unsigned long F_127 ( int V_32 , int type )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_136 = F_125 ( V_32 ) ;
if ( type == 0 || ! F_74 ( V_137 ) )
return V_136 ;
return F_128 ( V_31 -> V_138 [ type - 1 ] , V_136 ) ;
}
static unsigned long F_129 ( int V_32 )
{
return F_39 ( V_32 ) -> V_139 ;
}
static unsigned long F_130 ( int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_140 = F_131 ( V_31 -> V_140 ) ;
if ( V_140 )
V_31 -> V_141 = V_31 -> V_128 . V_110 / V_140 ;
else
V_31 -> V_141 = 0 ;
return V_31 -> V_141 ;
}
static int F_132 ( struct V_33 * V_34 , void * V_131 )
{
unsigned long V_128 ;
long V_32 = ( long ) V_131 ;
if ( ! V_34 -> V_42 ) {
V_128 = F_39 ( V_32 ) -> V_128 . V_110 ;
} else {
V_128 = V_34 -> V_42 -> V_41 [ V_32 ] -> V_142 ;
V_128 *= V_34 -> V_40 [ V_32 ] -> V_128 . V_110 ;
V_128 /= V_34 -> V_42 -> V_41 [ V_32 ] -> V_128 . V_110 + 1 ;
}
V_34 -> V_41 [ V_32 ] -> V_142 = V_128 ;
return 0 ;
}
static void F_133 ( long V_32 )
{
F_122 ( F_132 , F_124 , ( void * ) V_32 ) ;
}
static inline int F_134 ( struct V_31 * F_72 , struct V_31 * V_143 )
__releases( F_72 -> V_39 )
__acquires( V_143 -> V_39 )
__acquires( F_72 -> V_39 )
{
F_22 ( & F_72 -> V_39 ) ;
F_135 ( F_72 , V_143 ) ;
return 1 ;
}
static int F_134 ( struct V_31 * F_72 , struct V_31 * V_143 )
__releases( F_72 -> V_39 )
__acquires( V_143 -> V_39 )
__acquires( F_72 -> V_39 )
{
int V_133 = 0 ;
if ( F_2 ( ! F_136 ( & V_143 -> V_39 ) ) ) {
if ( V_143 < F_72 ) {
F_22 ( & F_72 -> V_39 ) ;
F_16 ( & V_143 -> V_39 ) ;
F_137 ( & F_72 -> V_39 ,
V_144 ) ;
V_133 = 1 ;
} else
F_137 ( & V_143 -> V_39 ,
V_144 ) ;
}
return V_133 ;
}
static int F_138 ( struct V_31 * F_72 , struct V_31 * V_143 )
{
if ( F_2 ( ! F_139 () ) ) {
F_22 ( & F_72 -> V_39 ) ;
F_140 ( 1 ) ;
}
return F_134 ( F_72 , V_143 ) ;
}
static inline void F_141 ( struct V_31 * F_72 , struct V_31 * V_143 )
__releases( V_143 -> V_39 )
{
F_22 ( & V_143 -> V_39 ) ;
F_142 ( & F_72 -> V_39 . V_73 , 0 , V_145 ) ;
}
static void F_135 ( struct V_31 * V_146 , struct V_31 * V_147 )
__acquires( V_146 -> V_39 )
__acquires( V_147 -> V_39 )
{
F_140 ( ! F_139 () ) ;
if ( V_146 == V_147 ) {
F_16 ( & V_146 -> V_39 ) ;
F_143 ( V_147 -> V_39 ) ;
} else {
if ( V_146 < V_147 ) {
F_16 ( & V_146 -> V_39 ) ;
F_137 ( & V_147 -> V_39 , V_144 ) ;
} else {
F_16 ( & V_147 -> V_39 ) ;
F_137 ( & V_146 -> V_39 , V_144 ) ;
}
}
}
static void F_144 ( struct V_31 * V_146 , struct V_31 * V_147 )
__releases( V_146 -> V_39 )
__releases( V_147 -> V_39 )
{
F_22 ( & V_146 -> V_39 ) ;
if ( V_146 != V_147 )
F_22 ( & V_147 -> V_39 ) ;
else
F_145 ( V_147 -> V_39 ) ;
}
static void F_135 ( struct V_31 * V_146 , struct V_31 * V_147 )
__acquires( V_146 -> V_39 )
__acquires( V_147 -> V_39 )
{
F_140 ( ! F_139 () ) ;
F_140 ( V_146 != V_147 ) ;
F_16 ( & V_146 -> V_39 ) ;
F_143 ( V_147 -> V_39 ) ;
}
static void F_144 ( struct V_31 * V_146 , struct V_31 * V_147 )
__releases( V_146 -> V_39 )
__releases( V_147 -> V_39 )
{
F_140 ( V_146 != V_147 ) ;
F_22 ( & V_146 -> V_39 ) ;
F_145 ( V_147 -> V_39 ) ;
}
static inline void F_146 ( struct V_4 * V_5 , unsigned int V_32 )
{
F_31 ( V_5 , V_32 ) ;
#ifdef F_26
F_56 () ;
F_147 ( V_5 ) -> V_32 = V_32 ;
#endif
}
static void F_148 ( struct V_31 * V_31 )
{
V_31 -> V_140 ++ ;
}
static void F_149 ( struct V_31 * V_31 )
{
V_31 -> V_140 -- ;
}
static void F_150 ( struct V_4 * V_5 )
{
int V_148 = V_5 -> V_149 - V_150 ;
struct V_111 * V_128 = & V_5 -> V_40 . V_128 ;
if ( V_5 -> V_1 == V_151 ) {
V_128 -> V_110 = F_151 ( V_152 ) ;
V_128 -> V_115 = V_153 ;
return;
}
V_128 -> V_110 = F_151 ( V_154 [ V_148 ] ) ;
V_128 -> V_115 = V_155 [ V_148 ] ;
}
static void F_152 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
F_34 ( V_31 ) ;
F_153 ( V_5 ) ;
V_5 -> V_78 -> F_152 ( V_31 , V_5 , V_75 ) ;
}
static void F_154 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
F_34 ( V_31 ) ;
F_155 ( V_5 ) ;
V_5 -> V_78 -> F_154 ( V_31 , V_5 , V_75 ) ;
}
static void F_156 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
if ( F_157 ( V_5 ) )
V_31 -> V_156 -- ;
F_152 ( V_31 , V_5 , V_75 ) ;
F_148 ( V_31 ) ;
}
static void F_158 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
if ( F_157 ( V_5 ) )
V_31 -> V_156 ++ ;
F_154 ( V_31 , V_5 , V_75 ) ;
F_149 ( V_31 ) ;
}
void F_159 ( void )
{
V_157 = 1 ;
}
void F_160 ( void )
{
V_157 = 0 ;
}
static inline void F_161 ( void )
{
F_162 ( V_158 . V_159 ) ;
F_56 () ;
}
static inline void F_163 ( void )
{
F_56 () ;
F_162 ( V_158 . V_159 ) ;
}
static inline T_2 F_164 ( int V_32 )
{
T_2 V_160 ;
unsigned V_161 ;
do {
V_161 = F_165 ( & F_166 ( V_158 , V_32 ) ) ;
V_160 = F_166 ( V_162 , V_32 ) +
F_166 ( V_163 , V_32 ) ;
} while ( F_167 ( & F_166 ( V_158 , V_32 ) , V_161 ) );
return V_160 ;
}
static inline void F_161 ( void )
{
}
static inline void F_163 ( void )
{
}
static inline T_2 F_164 ( int V_32 )
{
return F_166 ( V_162 , V_32 ) + F_166 ( V_163 , V_32 ) ;
}
void F_168 ( struct V_4 * V_67 )
{
unsigned long V_75 ;
T_3 V_27 ;
int V_32 ;
if ( ! V_157 )
return;
F_169 ( V_75 ) ;
V_32 = F_80 () ;
V_27 = F_35 ( V_32 ) - F_170 ( V_164 ) ;
F_171 ( V_164 , V_27 ) ;
F_161 () ;
if ( F_172 () )
F_171 ( V_163 , V_27 ) ;
else if ( F_173 () && V_67 != F_174 () )
F_171 ( V_162 , V_27 ) ;
F_163 () ;
F_175 ( V_75 ) ;
}
static void F_36 ( struct V_31 * V_31 , T_3 V_27 )
{
T_3 V_165 ;
V_165 = F_164 ( F_25 ( V_31 ) ) - V_31 -> V_166 ;
if ( V_165 > V_27 )
V_165 = V_27 ;
V_31 -> V_166 += V_165 ;
V_27 -= V_165 ;
V_31 -> V_167 += V_27 ;
if ( V_165 && F_74 ( V_168 ) )
F_110 ( V_31 , V_165 ) ;
}
static int F_176 ( void )
{
struct V_169 * V_170 = & V_171 . V_170 ;
unsigned long V_75 ;
T_2 V_172 ;
int V_133 = 0 ;
F_169 ( V_75 ) ;
V_172 = F_177 ( V_163 ) ;
if ( F_178 ( F_179 ( V_172 ) , V_170 -> V_173 ) )
V_133 = 1 ;
F_175 ( V_75 ) ;
return V_133 ;
}
static int F_180 ( void )
{
struct V_169 * V_170 = & V_171 . V_170 ;
unsigned long V_75 ;
T_2 V_172 ;
int V_133 = 0 ;
F_169 ( V_75 ) ;
V_172 = F_177 ( V_162 ) ;
if ( F_178 ( F_179 ( V_172 ) , V_170 -> V_174 ) )
V_133 = 1 ;
F_175 ( V_75 ) ;
return V_133 ;
}
static void F_36 ( struct V_31 * V_31 , T_3 V_27 )
{
V_31 -> V_167 += V_27 ;
}
void F_181 ( int V_32 , struct V_4 * V_175 )
{
struct V_176 V_177 = { . V_178 = V_150 - 1 } ;
struct V_4 * V_179 = F_39 ( V_32 ) -> V_175 ;
if ( V_175 ) {
F_182 ( V_175 , V_2 , & V_177 ) ;
V_175 -> V_78 = & V_180 ;
}
F_39 ( V_32 ) -> V_175 = V_175 ;
if ( V_179 ) {
V_179 -> V_78 = & V_181 ;
}
}
static inline int F_183 ( struct V_4 * V_5 )
{
return V_5 -> V_149 ;
}
static inline int F_184 ( struct V_4 * V_5 )
{
int V_148 ;
if ( F_3 ( V_5 ) )
V_148 = V_150 - 1 - V_5 -> V_182 ;
else
V_148 = F_183 ( V_5 ) ;
return V_148 ;
}
static int F_185 ( struct V_4 * V_5 )
{
V_5 -> F_184 = F_184 ( V_5 ) ;
if ( ! F_186 ( V_5 -> V_148 ) )
return V_5 -> F_184 ;
return V_5 -> V_148 ;
}
inline int F_187 ( const struct V_4 * V_5 )
{
return F_100 ( F_94 ( V_5 ) ) == V_5 ;
}
static inline void F_188 ( struct V_31 * V_31 , struct V_4 * V_5 ,
const struct V_78 * V_183 ,
int V_184 )
{
if ( V_183 != V_5 -> V_78 ) {
if ( V_183 -> V_185 )
V_183 -> V_185 ( V_31 , V_5 ) ;
V_5 -> V_78 -> V_186 ( V_31 , V_5 ) ;
} else if ( V_184 != V_5 -> V_148 )
V_5 -> V_78 -> V_187 ( V_31 , V_5 , V_184 ) ;
}
static void F_189 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
const struct V_78 * V_188 ;
if ( V_5 -> V_78 == V_31 -> V_67 -> V_78 ) {
V_31 -> V_67 -> V_78 -> F_189 ( V_31 , V_5 , V_75 ) ;
} else {
F_190 (class) {
if ( V_188 == V_31 -> V_67 -> V_78 )
break;
if ( V_188 == V_5 -> V_78 ) {
F_90 ( V_31 -> V_67 ) ;
break;
}
}
}
if ( V_31 -> V_67 -> V_189 && F_92 ( V_31 -> V_67 ) )
V_31 -> V_46 = 1 ;
}
static int
F_191 ( struct V_4 * V_5 , T_2 V_12 , struct V_101 * V_102 )
{
T_3 V_27 ;
if ( V_5 -> V_78 != & V_190 )
return 0 ;
if ( F_2 ( V_5 -> V_1 == V_151 ) )
return 0 ;
if ( F_74 ( V_191 ) && F_72 () -> V_140 &&
( & V_5 -> V_40 == F_192 ( & V_5 -> V_40 ) -> V_69 ||
& V_5 -> V_40 == F_192 ( & V_5 -> V_40 ) -> V_192 ) )
return 1 ;
if ( V_193 == - 1 )
return 1 ;
if ( V_193 == 0 )
return 0 ;
V_27 = V_12 - V_5 -> V_40 . V_194 ;
return V_27 < ( T_3 ) V_193 ;
}
void F_193 ( struct V_4 * V_5 , unsigned int V_195 )
{
#ifdef F_194
F_79 ( V_5 -> V_196 != V_197 && V_5 -> V_196 != V_198 &&
! ( F_147 ( V_5 ) -> V_199 & V_200 ) ) ;
#ifdef F_195
F_79 ( V_201 && ! ( F_28 ( & V_5 -> V_38 ) ||
F_28 ( & F_29 ( V_5 ) -> V_39 ) ) ) ;
#endif
#endif
F_196 ( V_5 , V_195 ) ;
if ( F_94 ( V_5 ) != V_195 ) {
V_5 -> V_40 . V_202 ++ ;
F_197 ( V_203 , 1 , 1 , NULL , 0 ) ;
}
F_146 ( V_5 , V_195 ) ;
}
unsigned long F_198 ( struct V_4 * V_5 , long V_204 )
{
unsigned long V_75 ;
int V_205 , V_189 ;
unsigned long V_206 ;
struct V_31 * V_31 ;
for (; ; ) {
V_31 = F_29 ( V_5 ) ;
while ( F_53 ( V_31 , V_5 ) ) {
if ( V_204 && F_2 ( V_5 -> V_196 != V_204 ) )
return 0 ;
F_199 () ;
}
V_31 = F_65 ( V_5 , & V_75 ) ;
F_200 ( V_5 ) ;
V_205 = F_53 ( V_31 , V_5 ) ;
V_189 = V_5 -> V_189 ;
V_206 = 0 ;
if ( ! V_204 || V_5 -> V_196 == V_204 )
V_206 = V_5 -> V_207 | V_208 ;
F_69 ( V_31 , V_5 , & V_75 ) ;
if ( F_2 ( ! V_206 ) )
break;
if ( F_2 ( V_205 ) ) {
F_199 () ;
continue;
}
if ( F_2 ( V_189 ) ) {
T_1 V_209 = F_201 ( 0 , V_210 / V_211 ) ;
F_202 ( V_212 ) ;
F_203 ( & V_209 , V_23 ) ;
continue;
}
break;
}
return V_206 ;
}
void F_204 ( struct V_4 * V_5 )
{
int V_32 ;
F_205 () ;
V_32 = F_94 ( V_5 ) ;
if ( ( V_32 != F_80 () ) && F_187 ( V_5 ) )
F_97 ( V_32 ) ;
F_206 () ;
}
static int F_207 ( int V_32 , struct V_4 * V_5 )
{
int V_213 ;
const struct V_214 * V_215 = F_208 ( F_209 ( V_32 ) ) ;
F_210 (dest_cpu, nodemask, cpu_active_mask)
if ( F_211 ( V_213 , & V_5 -> V_216 ) )
return V_213 ;
V_213 = F_212 ( & V_5 -> V_216 , V_217 ) ;
if ( V_213 < V_218 )
return V_213 ;
V_213 = F_213 ( V_5 ) ;
if ( V_5 -> V_219 && F_214 () ) {
F_215 ( V_220 L_5 ,
F_216 ( V_5 ) , V_5 -> V_221 , V_32 ) ;
}
return V_213 ;
}
static inline
int F_217 ( struct V_4 * V_5 , int V_222 , int V_223 )
{
int V_32 = V_5 -> V_78 -> F_217 ( V_5 , V_222 , V_223 ) ;
if ( F_2 ( ! F_211 ( V_32 , & V_5 -> V_216 ) ||
! F_218 ( V_32 ) ) )
V_32 = F_207 ( F_94 ( V_5 ) , V_5 ) ;
return V_32 ;
}
static void F_219 ( T_2 * V_224 , T_2 V_225 )
{
T_3 V_226 = V_225 - * V_224 ;
* V_224 += V_226 >> 3 ;
}
static void
F_220 ( struct V_4 * V_5 , int V_32 , int V_223 )
{
#ifdef F_221
struct V_31 * V_31 = F_72 () ;
#ifdef F_26
int V_227 = F_80 () ;
if ( V_32 == V_227 ) {
F_222 ( V_31 , V_228 ) ;
F_222 ( V_5 , V_40 . V_229 . V_230 ) ;
} else {
struct V_101 * V_102 ;
F_222 ( V_5 , V_40 . V_229 . V_231 ) ;
F_102 () ;
F_103 (this_cpu, sd) {
if ( F_211 ( V_32 , F_223 ( V_102 ) ) ) {
F_222 ( V_102 , V_232 ) ;
break;
}
}
F_106 () ;
}
if ( V_223 & V_233 )
F_222 ( V_5 , V_40 . V_229 . V_234 ) ;
#endif
F_222 ( V_31 , V_235 ) ;
F_222 ( V_5 , V_40 . V_229 . V_236 ) ;
if ( V_223 & V_237 )
F_222 ( V_5 , V_40 . V_229 . V_238 ) ;
#endif
}
static void F_224 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_239 )
{
F_156 ( V_31 , V_5 , V_239 ) ;
V_5 -> V_189 = 1 ;
if ( V_5 -> V_75 & V_240 )
F_225 ( V_5 , F_25 ( V_31 ) ) ;
}
static void
F_226 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_223 )
{
F_227 ( V_5 , true ) ;
F_189 ( V_31 , V_5 , V_223 ) ;
V_5 -> V_196 = V_197 ;
#ifdef F_26
if ( V_5 -> V_78 -> V_241 )
V_5 -> V_78 -> V_241 ( V_31 , V_5 ) ;
if ( F_2 ( V_31 -> V_242 ) ) {
T_2 V_27 = V_31 -> clock - V_31 -> V_242 ;
T_2 F_128 = 2 * V_193 ;
if ( V_27 > F_128 )
V_31 -> V_243 = F_128 ;
else
F_219 ( & V_31 -> V_243 , V_27 ) ;
V_31 -> V_242 = 0 ;
}
#endif
}
static void
F_228 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_223 )
{
#ifdef F_26
if ( V_5 -> V_244 )
V_31 -> V_156 -- ;
#endif
F_224 ( V_31 , V_5 , V_245 | V_246 ) ;
F_226 ( V_31 , V_5 , V_223 ) ;
}
static int F_229 ( struct V_4 * V_5 , int V_223 )
{
struct V_31 * V_31 ;
int V_133 = 0 ;
V_31 = F_62 ( V_5 ) ;
if ( V_5 -> V_189 ) {
F_226 ( V_31 , V_5 , V_223 ) ;
V_133 = 1 ;
}
F_68 ( V_31 ) ;
return V_133 ;
}
static void F_230 ( struct V_4 * V_247 )
{
struct V_31 * V_31 = F_72 () ;
F_16 ( & V_31 -> V_39 ) ;
while ( V_247 ) {
struct V_4 * V_5 = V_247 ;
V_247 = V_247 -> V_248 ;
F_228 ( V_31 , V_5 , 0 ) ;
}
F_22 ( & V_31 -> V_39 ) ;
}
static void F_231 ( void )
{
struct V_31 * V_31 = F_72 () ;
struct V_4 * V_247 = F_232 ( & V_31 -> V_249 , NULL ) ;
if ( ! V_247 )
return;
F_230 ( V_247 ) ;
}
void F_233 ( void )
{
struct V_31 * V_31 = F_72 () ;
struct V_4 * V_247 = F_232 ( & V_31 -> V_249 , NULL ) ;
if ( ! V_247 )
return;
F_234 () ;
F_230 ( V_247 ) ;
F_235 () ;
}
static void F_236 ( struct V_4 * V_5 , int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
struct V_4 * V_69 = V_31 -> V_249 ;
for (; ; ) {
struct V_4 * V_250 = V_69 ;
V_5 -> V_248 = V_69 ;
V_69 = F_237 ( & V_31 -> V_249 , V_250 , V_5 ) ;
if ( V_69 == V_250 )
break;
}
if ( ! V_69 )
F_97 ( V_32 ) ;
}
static int F_238 ( struct V_4 * V_5 , int V_223 )
{
struct V_31 * V_31 ;
int V_133 = 0 ;
V_31 = F_62 ( V_5 ) ;
if ( V_5 -> V_68 ) {
F_224 ( V_31 , V_5 , V_245 ) ;
F_226 ( V_31 , V_5 , V_223 ) ;
V_133 = 1 ;
}
F_68 ( V_31 ) ;
return V_133 ;
}
static void F_239 ( struct V_4 * V_5 , int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
#if F_240 ( F_26 )
if ( F_74 ( V_251 ) && V_32 != F_80 () ) {
F_35 ( V_32 ) ;
F_236 ( V_5 , V_32 ) ;
return;
}
#endif
F_16 ( & V_31 -> V_39 ) ;
F_228 ( V_31 , V_5 , 0 ) ;
F_22 ( & V_31 -> V_39 ) ;
}
static int
F_241 ( struct V_4 * V_5 , unsigned int V_196 , int V_223 )
{
unsigned long V_75 ;
int V_32 , V_252 = 0 ;
F_56 () ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
if ( ! ( V_5 -> V_196 & V_196 ) )
goto V_253;
V_252 = 1 ;
V_32 = F_94 ( V_5 ) ;
if ( V_5 -> V_189 && F_229 ( V_5 , V_223 ) )
goto V_254;
#ifdef F_26
while ( V_5 -> V_68 ) {
#ifdef F_60
if ( F_238 ( V_5 , V_223 ) )
goto V_254;
#else
F_199 () ;
#endif
}
F_242 () ;
V_5 -> V_244 = ! ! F_157 ( V_5 ) ;
V_5 -> V_196 = V_198 ;
if ( V_5 -> V_78 -> V_255 )
V_5 -> V_78 -> V_255 ( V_5 ) ;
V_32 = F_217 ( V_5 , V_256 , V_223 ) ;
if ( F_94 ( V_5 ) != V_32 ) {
V_223 |= V_233 ;
F_193 ( V_5 , V_32 ) ;
}
#endif
F_239 ( V_5 , V_32 ) ;
V_254:
F_220 ( V_5 , V_32 , V_223 ) ;
V_253:
F_67 ( & V_5 -> V_38 , V_75 ) ;
return V_252 ;
}
static void F_243 ( struct V_4 * V_5 )
{
struct V_31 * V_31 = F_29 ( V_5 ) ;
F_140 ( V_31 != F_72 () ) ;
F_140 ( V_5 == V_72 ) ;
F_63 ( & V_31 -> V_39 ) ;
if ( ! F_136 ( & V_5 -> V_38 ) ) {
F_22 ( & V_31 -> V_39 ) ;
F_16 ( & V_5 -> V_38 ) ;
F_16 ( & V_31 -> V_39 ) ;
}
if ( ! ( V_5 -> V_196 & V_257 ) )
goto V_253;
if ( ! V_5 -> V_189 )
F_224 ( V_31 , V_5 , V_245 ) ;
F_226 ( V_31 , V_5 , 0 ) ;
F_220 ( V_5 , F_80 () , 0 ) ;
V_253:
F_22 ( & V_5 -> V_38 ) ;
}
int F_244 ( struct V_4 * V_5 )
{
return F_241 ( V_5 , V_258 , 0 ) ;
}
int F_245 ( struct V_4 * V_5 , unsigned int V_196 )
{
return F_241 ( V_5 , V_196 , 0 ) ;
}
static void F_246 ( struct V_4 * V_5 )
{
V_5 -> V_189 = 0 ;
V_5 -> V_40 . V_189 = 0 ;
V_5 -> V_40 . V_194 = 0 ;
V_5 -> V_40 . V_259 = 0 ;
V_5 -> V_40 . V_260 = 0 ;
V_5 -> V_40 . V_202 = 0 ;
V_5 -> V_40 . V_261 = 0 ;
F_247 ( & V_5 -> V_40 . V_262 ) ;
#ifdef F_221
memset ( & V_5 -> V_40 . V_229 , 0 , sizeof( V_5 -> V_40 . V_229 ) ) ;
#endif
F_247 ( & V_5 -> V_43 . V_263 ) ;
#ifdef F_248
F_249 ( & V_5 -> V_264 ) ;
#endif
}
void F_250 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
int V_32 = F_251 () ;
F_246 ( V_5 ) ;
V_5 -> V_196 = V_197 ;
if ( F_2 ( V_5 -> V_265 ) ) {
if ( V_5 -> V_1 == V_2 || V_5 -> V_1 == V_3 ) {
V_5 -> V_1 = V_266 ;
V_5 -> F_184 = V_5 -> V_149 ;
}
if ( F_252 ( V_5 -> V_149 ) < 0 ) {
V_5 -> V_149 = F_253 ( 0 ) ;
V_5 -> F_184 = V_5 -> V_149 ;
F_150 ( V_5 ) ;
}
V_5 -> V_265 = 0 ;
}
V_5 -> V_148 = V_72 -> F_184 ;
if ( ! F_186 ( V_5 -> V_148 ) )
V_5 -> V_78 = & V_190 ;
if ( V_5 -> V_78 -> V_267 )
V_5 -> V_78 -> V_267 ( V_5 ) ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
F_193 ( V_5 , V_32 ) ;
F_67 ( & V_5 -> V_38 , V_75 ) ;
#if F_240 ( F_221 ) || F_240 ( V_268 )
if ( F_64 ( F_254 () ) )
memset ( & V_5 -> V_269 , 0 , sizeof( V_5 -> V_269 ) ) ;
#endif
#if F_240 ( F_26 )
V_5 -> V_68 = 0 ;
#endif
#ifdef F_255
F_147 ( V_5 ) -> V_199 = 1 ;
#endif
#ifdef F_26
F_256 ( & V_5 -> V_270 , V_271 ) ;
#endif
F_257 () ;
}
void F_258 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
#ifdef F_26
F_193 ( V_5 , F_217 ( V_5 , V_272 , 0 ) ) ;
#endif
V_31 = F_62 ( V_5 ) ;
F_156 ( V_31 , V_5 , 0 ) ;
V_5 -> V_189 = 1 ;
F_259 ( V_5 , true ) ;
F_189 ( V_31 , V_5 , V_273 ) ;
#ifdef F_26
if ( V_5 -> V_78 -> V_241 )
V_5 -> V_78 -> V_241 ( V_31 , V_5 ) ;
#endif
F_69 ( V_31 , V_5 , & V_75 ) ;
}
void F_260 ( struct V_274 * V_275 )
{
F_261 ( & V_275 -> V_276 , & V_72 -> V_264 ) ;
}
void F_262 ( struct V_274 * V_275 )
{
F_263 ( & V_275 -> V_276 ) ;
}
static void F_264 ( struct V_4 * V_67 )
{
struct V_274 * V_275 ;
struct V_277 * V_278 ;
F_265 (notifier, node, &curr->preempt_notifiers, link)
V_275 -> V_279 -> V_280 ( V_275 , F_266 () ) ;
}
static void
F_267 ( struct V_4 * V_67 ,
struct V_4 * V_69 )
{
struct V_274 * V_275 ;
struct V_277 * V_278 ;
F_265 (notifier, node, &curr->preempt_notifiers, link)
V_275 -> V_279 -> V_281 ( V_275 , V_69 ) ;
}
static void F_264 ( struct V_4 * V_67 )
{
}
static void
F_267 ( struct V_4 * V_67 ,
struct V_4 * V_69 )
{
}
static inline void
F_268 ( struct V_31 * V_31 , struct V_4 * V_70 ,
struct V_4 * V_69 )
{
F_269 ( V_70 , V_69 ) ;
F_270 ( V_70 , V_69 ) ;
F_267 ( V_70 , V_69 ) ;
F_54 ( V_31 , V_69 ) ;
F_271 ( V_69 ) ;
F_272 ( V_70 , V_69 ) ;
}
static void F_273 ( struct V_31 * V_31 , struct V_4 * V_70 )
__releases( V_31 -> V_39 )
{
struct V_282 * V_219 = V_31 -> V_283 ;
long V_284 ;
V_31 -> V_283 = NULL ;
V_284 = V_70 -> V_196 ;
F_274 ( V_70 ) ;
#ifdef F_60
F_71 () ;
#endif
F_275 ( V_72 ) ;
#ifdef F_60
F_61 () ;
#endif
F_55 ( V_31 , V_70 ) ;
F_264 ( V_72 ) ;
if ( V_219 )
F_276 ( V_219 ) ;
if ( F_2 ( V_284 == V_285 ) ) {
F_277 ( V_70 ) ;
F_278 ( V_70 ) ;
}
}
static inline void F_279 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
if ( V_70 -> V_78 -> F_279 )
V_70 -> V_78 -> F_279 ( V_31 , V_70 ) ;
}
static inline void F_280 ( struct V_31 * V_31 )
{
if ( V_31 -> F_280 ) {
unsigned long V_75 ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_67 -> V_78 -> F_280 )
V_31 -> V_67 -> V_78 -> F_280 ( V_31 ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
V_31 -> F_280 = 0 ;
}
}
static inline void F_279 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
}
static inline void F_280 ( struct V_31 * V_31 )
{
}
T_11 void F_281 ( struct V_4 * V_70 )
__releases( V_31 -> V_39 )
{
struct V_31 * V_31 = F_72 () ;
F_273 ( V_31 , V_70 ) ;
F_280 ( V_31 ) ;
#ifdef F_282
F_206 () ;
#endif
if ( V_72 -> V_286 )
F_283 ( F_284 ( V_72 ) , V_72 -> V_286 ) ;
}
static inline void
F_285 ( struct V_31 * V_31 , struct V_4 * V_70 ,
struct V_4 * V_69 )
{
struct V_282 * V_219 , * V_287 ;
F_268 ( V_31 , V_70 , V_69 ) ;
V_219 = V_69 -> V_219 ;
V_287 = V_70 -> V_288 ;
F_286 ( V_70 ) ;
if ( ! V_219 ) {
V_69 -> V_288 = V_287 ;
F_287 ( & V_287 -> V_289 ) ;
F_288 ( V_287 , V_69 ) ;
} else
F_289 ( V_287 , V_219 , V_69 ) ;
if ( ! V_70 -> V_219 ) {
V_70 -> V_288 = NULL ;
V_31 -> V_283 = V_287 ;
}
#ifndef F_282
F_290 ( & V_31 -> V_39 . V_73 , 1 , V_74 ) ;
#endif
F_291 ( V_70 , V_69 , V_70 ) ;
F_292 () ;
F_273 ( F_72 () , V_70 ) ;
}
unsigned long V_140 ( void )
{
unsigned long V_50 , V_290 = 0 ;
F_293 (i)
V_290 += F_39 ( V_50 ) -> V_140 ;
return V_290 ;
}
unsigned long V_156 ( void )
{
unsigned long V_50 , V_290 = 0 ;
F_294 (i)
V_290 += F_39 ( V_50 ) -> V_156 ;
if ( F_2 ( ( long ) V_290 < 0 ) )
V_290 = 0 ;
return V_290 ;
}
unsigned long long F_295 ( void )
{
int V_50 ;
unsigned long long V_290 = 0 ;
F_294 (i)
V_290 += F_39 ( V_50 ) -> V_291 ;
return V_290 ;
}
unsigned long F_296 ( void )
{
unsigned long V_50 , V_290 = 0 ;
F_294 (i)
V_290 += F_297 ( & F_39 ( V_50 ) -> F_296 ) ;
return V_290 ;
}
unsigned long F_298 ( int V_32 )
{
struct V_31 * V_292 = F_39 ( V_32 ) ;
return F_297 ( & V_292 -> F_296 ) ;
}
unsigned long F_299 ( void )
{
struct V_31 * V_292 = F_72 () ;
return V_292 -> V_138 [ 0 ] ;
}
static long F_300 ( struct V_31 * F_72 )
{
long V_293 , V_27 = 0 ;
V_293 = F_72 -> V_140 ;
V_293 += ( long ) F_72 -> V_156 ;
if ( V_293 != F_72 -> V_294 ) {
V_27 = V_293 - F_72 -> V_294 ;
F_72 -> V_294 = V_293 ;
}
return V_27 ;
}
static unsigned long
F_301 ( unsigned long V_128 , unsigned long exp , unsigned long V_295 )
{
V_128 *= exp ;
V_128 += V_295 * ( V_296 - exp ) ;
V_128 += 1UL << ( V_297 - 1 ) ;
return V_128 >> V_297 ;
}
static void F_302 ( struct V_31 * F_72 )
{
long V_27 ;
V_27 = F_300 ( F_72 ) ;
if ( V_27 )
F_303 ( V_27 , & V_298 ) ;
}
static long F_304 ( void )
{
long V_27 = 0 ;
if ( F_305 ( & V_298 ) )
V_27 = F_306 ( & V_298 , 0 ) ;
return V_27 ;
}
static unsigned long
F_307 ( unsigned long V_299 , unsigned int V_300 , unsigned int V_301 )
{
unsigned long V_302 = 1UL << V_300 ;
if ( V_301 ) for (; ; ) {
if ( V_301 & 1 ) {
V_302 *= V_299 ;
V_302 += 1UL << ( V_300 - 1 ) ;
V_302 >>= V_300 ;
}
V_301 >>= 1 ;
if ( ! V_301 )
break;
V_299 *= V_299 ;
V_299 += 1UL << ( V_300 - 1 ) ;
V_299 >>= V_300 ;
}
return V_302 ;
}
static unsigned long
F_308 ( unsigned long V_128 , unsigned long exp ,
unsigned long V_295 , unsigned int V_301 )
{
return F_301 ( V_128 , F_307 ( exp , V_297 , V_301 ) , V_295 ) ;
}
static void F_309 ( unsigned long V_303 )
{
long V_27 , V_295 , V_301 ;
if ( F_310 ( V_304 , V_305 ) )
return;
V_27 = F_304 () ;
if ( V_27 )
F_303 ( V_27 , & V_306 ) ;
if ( V_303 >= V_307 ) {
V_301 = V_303 / V_307 ;
V_295 = F_305 ( & V_306 ) ;
V_295 = V_295 > 0 ? V_295 * V_296 : 0 ;
V_308 [ 0 ] = F_308 ( V_308 [ 0 ] , V_309 , V_295 , V_301 ) ;
V_308 [ 1 ] = F_308 ( V_308 [ 1 ] , V_310 , V_295 , V_301 ) ;
V_308 [ 2 ] = F_308 ( V_308 [ 2 ] , V_311 , V_295 , V_301 ) ;
V_305 += V_301 * V_307 ;
}
}
static void F_302 ( struct V_31 * F_72 )
{
}
static inline long F_304 ( void )
{
return 0 ;
}
static void F_309 ( unsigned long V_303 )
{
}
void F_311 ( unsigned long * V_312 , unsigned long V_313 , int V_314 )
{
V_312 [ 0 ] = ( V_308 [ 0 ] + V_313 ) << V_314 ;
V_312 [ 1 ] = ( V_308 [ 1 ] + V_313 ) << V_314 ;
V_312 [ 2 ] = ( V_308 [ 2 ] + V_313 ) << V_314 ;
}
void F_312 ( unsigned long V_303 )
{
long V_295 ;
F_309 ( V_303 ) ;
if ( F_310 ( V_304 , V_305 + 10 ) )
return;
V_295 = F_305 ( & V_306 ) ;
V_295 = V_295 > 0 ? V_295 * V_296 : 0 ;
V_308 [ 0 ] = F_301 ( V_308 [ 0 ] , V_309 , V_295 ) ;
V_308 [ 1 ] = F_301 ( V_308 [ 1 ] , V_310 , V_295 ) ;
V_308 [ 2 ] = F_301 ( V_308 [ 2 ] , V_311 , V_295 ) ;
V_305 += V_307 ;
}
static void F_313 ( struct V_31 * F_72 )
{
long V_27 ;
if ( F_310 ( V_304 , F_72 -> V_305 ) )
return;
V_27 = F_300 ( F_72 ) ;
V_27 += F_304 () ;
if ( V_27 )
F_303 ( V_27 , & V_306 ) ;
F_72 -> V_305 += V_307 ;
}
static unsigned long
F_314 ( unsigned long V_128 , unsigned long V_315 , int V_126 )
{
int V_316 = 0 ;
if ( ! V_315 )
return V_128 ;
if ( V_315 >= V_317 [ V_126 ] )
return 0 ;
if ( V_126 == 1 )
return V_128 >> V_315 ;
while ( V_315 ) {
if ( V_315 % 2 )
V_128 = ( V_128 * V_318 [ V_126 ] [ V_316 ] ) >> V_319 ;
V_315 >>= 1 ;
V_316 ++ ;
}
return V_128 ;
}
static void F_315 ( struct V_31 * F_72 )
{
unsigned long V_320 = F_72 -> V_128 . V_110 ;
unsigned long V_321 = V_304 ;
unsigned long V_322 ;
int V_50 , V_323 ;
F_72 -> V_324 ++ ;
if ( V_321 == F_72 -> V_325 )
return;
V_322 = V_321 - F_72 -> V_325 ;
F_72 -> V_325 = V_321 ;
F_72 -> V_138 [ 0 ] = V_320 ;
for ( V_50 = 1 , V_323 = 2 ; V_50 < V_326 ; V_50 ++ , V_323 += V_323 ) {
unsigned long V_327 , V_328 ;
V_327 = F_72 -> V_138 [ V_50 ] ;
V_327 = F_314 ( V_327 , V_322 - 1 , V_50 ) ;
V_328 = V_320 ;
if ( V_328 > V_327 )
V_328 += V_323 - 1 ;
F_72 -> V_138 [ V_50 ] = ( V_327 * ( V_323 - 1 ) + V_328 ) >> V_50 ;
}
F_109 ( F_72 ) ;
}
static void F_316 ( struct V_31 * F_72 )
{
F_315 ( F_72 ) ;
F_313 ( F_72 ) ;
}
void F_317 ( void )
{
struct V_4 * V_5 = V_72 ;
unsigned long V_75 ;
int V_213 ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
V_213 = V_5 -> V_78 -> F_217 ( V_5 , V_329 , 0 ) ;
if ( V_213 == F_80 () )
goto V_103;
if ( F_64 ( F_75 ( V_213 ) ) ) {
struct V_330 V_80 = { V_5 , V_213 } ;
F_67 ( & V_5 -> V_38 , V_75 ) ;
F_318 ( F_94 ( V_5 ) , V_331 , & V_80 ) ;
return;
}
V_103:
F_67 ( & V_5 -> V_38 , V_75 ) ;
}
static T_2 F_319 ( struct V_4 * V_5 , struct V_31 * V_31 )
{
T_2 V_332 = 0 ;
if ( F_52 ( V_31 , V_5 ) ) {
F_34 ( V_31 ) ;
V_332 = V_31 -> V_167 - V_5 -> V_40 . V_194 ;
if ( ( T_3 ) V_332 < 0 )
V_332 = 0 ;
}
return V_332 ;
}
unsigned long long F_320 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
T_2 V_332 = 0 ;
V_31 = F_65 ( V_5 , & V_75 ) ;
V_332 = F_319 ( V_5 , V_31 ) ;
F_69 ( V_31 , V_5 , & V_75 ) ;
return V_332 ;
}
unsigned long long F_321 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
T_2 V_332 = 0 ;
V_31 = F_65 ( V_5 , & V_75 ) ;
V_332 = V_5 -> V_40 . V_259 + F_319 ( V_5 , V_31 ) ;
F_69 ( V_31 , V_5 , & V_75 ) ;
return V_332 ;
}
unsigned long long F_322 ( struct V_4 * V_5 )
{
struct V_333 V_334 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
T_2 V_332 ;
V_31 = F_65 ( V_5 , & V_75 ) ;
F_323 ( V_5 , & V_334 ) ;
V_332 = V_334 . V_259 + F_319 ( V_5 , V_31 ) ;
F_69 ( V_31 , V_5 , & V_75 ) ;
return V_332 ;
}
void F_324 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_335 )
{
struct V_169 * V_170 = & V_171 . V_170 ;
T_12 V_113 ;
V_5 -> V_336 = F_325 ( V_5 -> V_336 , V_124 ) ;
V_5 -> V_337 = F_325 ( V_5 -> V_337 , V_335 ) ;
F_326 ( V_5 , V_124 ) ;
V_113 = F_327 ( V_124 ) ;
if ( F_328 ( V_5 ) > 0 )
V_170 -> V_338 = F_329 ( V_170 -> V_338 , V_113 ) ;
else
V_170 -> V_339 = F_329 ( V_170 -> V_339 , V_113 ) ;
F_119 ( V_5 , V_340 , V_124 ) ;
F_330 ( V_5 ) ;
}
static void F_331 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_335 )
{
T_12 V_113 ;
struct V_169 * V_170 = & V_171 . V_170 ;
V_113 = F_327 ( V_124 ) ;
V_5 -> V_336 = F_325 ( V_5 -> V_336 , V_124 ) ;
V_5 -> V_337 = F_325 ( V_5 -> V_337 , V_335 ) ;
F_326 ( V_5 , V_124 ) ;
V_5 -> V_341 = F_325 ( V_5 -> V_341 , V_124 ) ;
if ( F_328 ( V_5 ) > 0 ) {
V_170 -> V_338 = F_329 ( V_170 -> V_338 , V_113 ) ;
V_170 -> V_342 = F_329 ( V_170 -> V_342 , V_113 ) ;
} else {
V_170 -> V_339 = F_329 ( V_170 -> V_339 , V_113 ) ;
V_170 -> V_343 = F_329 ( V_170 -> V_343 , V_113 ) ;
}
}
static inline
void F_332 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_335 , T_12 * V_344 )
{
T_12 V_113 = F_327 ( V_124 ) ;
V_5 -> V_345 = F_325 ( V_5 -> V_345 , V_124 ) ;
V_5 -> V_346 = F_325 ( V_5 -> V_346 , V_335 ) ;
F_333 ( V_5 , V_124 ) ;
* V_344 = F_329 ( * V_344 , V_113 ) ;
F_119 ( V_5 , V_347 , V_124 ) ;
F_330 ( V_5 ) ;
}
void F_334 ( struct V_4 * V_5 , int V_348 ,
T_9 V_124 , T_9 V_335 )
{
struct V_169 * V_170 = & V_171 . V_170 ;
T_12 * V_344 ;
if ( ( V_5 -> V_75 & V_349 ) && ( F_335 () - V_348 == 0 ) ) {
F_331 ( V_5 , V_124 , V_335 ) ;
return;
}
if ( F_172 () - V_348 )
V_344 = & V_170 -> V_173 ;
else if ( F_173 () )
V_344 = & V_170 -> V_174 ;
else
V_344 = & V_170 -> system ;
F_332 ( V_5 , V_124 , V_335 , V_344 ) ;
}
void F_336 ( T_9 V_124 )
{
struct V_169 * V_170 = & V_171 . V_170 ;
T_12 V_350 = F_327 ( V_124 ) ;
V_170 -> V_351 = F_329 ( V_170 -> V_351 , V_350 ) ;
}
void F_337 ( T_9 V_124 )
{
struct V_169 * V_170 = & V_171 . V_170 ;
T_12 V_350 = F_327 ( V_124 ) ;
struct V_31 * V_31 = F_72 () ;
if ( F_297 ( & V_31 -> F_296 ) > 0 )
V_170 -> V_352 = F_329 ( V_170 -> V_352 , V_350 ) ;
else
V_170 -> V_14 = F_329 ( V_170 -> V_14 , V_350 ) ;
}
static void F_338 ( struct V_4 * V_5 , int V_353 ,
struct V_31 * V_31 )
{
T_9 V_354 = F_339 ( V_355 ) ;
T_12 V_113 = F_327 ( V_355 ) ;
struct V_169 * V_170 = & V_171 . V_170 ;
if ( F_176 () ) {
V_170 -> V_173 = F_329 ( V_170 -> V_173 , V_113 ) ;
} else if ( F_180 () ) {
V_170 -> V_174 = F_329 ( V_170 -> V_174 , V_113 ) ;
} else if ( F_174 () == V_5 ) {
F_332 ( V_5 , V_355 , V_354 ,
& V_170 -> V_174 ) ;
} else if ( V_353 ) {
F_324 ( V_5 , V_355 , V_354 ) ;
} else if ( V_5 == V_31 -> V_14 ) {
F_337 ( V_355 ) ;
} else if ( V_5 -> V_75 & V_349 ) {
F_331 ( V_5 , V_355 , V_354 ) ;
} else {
F_332 ( V_5 , V_355 , V_354 ,
& V_170 -> system ) ;
}
}
static void F_340 ( int V_303 )
{
int V_50 ;
struct V_31 * V_31 = F_72 () ;
for ( V_50 = 0 ; V_50 < V_303 ; V_50 ++ )
F_338 ( V_72 , 0 , V_31 ) ;
}
static void F_340 ( int V_303 ) {}
static void F_338 ( struct V_4 * V_5 , int V_353 ,
struct V_31 * V_31 ) {}
void F_341 ( struct V_4 * V_5 , int V_353 )
{
T_9 V_354 = F_339 ( V_355 ) ;
struct V_31 * V_31 = F_72 () ;
if ( V_157 ) {
F_338 ( V_5 , V_353 , V_31 ) ;
return;
}
if ( V_353 )
F_324 ( V_5 , V_355 , V_354 ) ;
else if ( ( V_5 != V_31 -> V_14 ) || ( F_335 () != V_356 ) )
F_334 ( V_5 , V_356 , V_355 ,
V_354 ) ;
else
F_337 ( V_355 ) ;
}
void F_342 ( unsigned long V_303 )
{
F_336 ( F_343 ( V_303 ) ) ;
}
void F_344 ( unsigned long V_303 )
{
if ( V_157 ) {
F_340 ( V_303 ) ;
return;
}
F_337 ( F_343 ( V_303 ) ) ;
}
void F_345 ( struct V_4 * V_5 , T_9 * V_357 , T_9 * V_358 )
{
* V_357 = V_5 -> V_336 ;
* V_358 = V_5 -> V_345 ;
}
void F_346 ( struct V_4 * V_5 , T_9 * V_357 , T_9 * V_358 )
{
struct V_333 V_124 ;
F_323 ( V_5 , & V_124 ) ;
* V_357 = V_124 . V_336 ;
* V_358 = V_124 . V_345 ;
}
void F_345 ( struct V_4 * V_5 , T_9 * V_357 , T_9 * V_358 )
{
T_9 V_359 , V_336 = V_5 -> V_336 , V_136 = F_325 ( V_336 , V_5 -> V_345 ) ;
V_359 = F_347 ( V_5 -> V_40 . V_259 ) ;
if ( V_136 ) {
T_2 V_360 = V_359 ;
V_360 *= V_336 ;
F_348 ( V_360 , V_136 ) ;
V_336 = ( T_9 ) V_360 ;
} else
V_336 = V_359 ;
V_5 -> V_361 = F_128 ( V_5 -> V_361 , V_336 ) ;
V_5 -> V_362 = F_128 ( V_5 -> V_362 , F_349 ( V_359 , V_5 -> V_361 ) ) ;
* V_357 = V_5 -> V_361 ;
* V_358 = V_5 -> V_362 ;
}
void F_346 ( struct V_4 * V_5 , T_9 * V_357 , T_9 * V_358 )
{
struct V_363 * V_364 = V_5 -> signal ;
struct V_333 V_124 ;
T_9 V_359 , V_336 , V_136 ;
F_323 ( V_5 , & V_124 ) ;
V_136 = F_325 ( V_124 . V_336 , V_124 . V_345 ) ;
V_359 = F_347 ( V_124 . V_259 ) ;
if ( V_136 ) {
T_2 V_360 = V_359 ;
V_360 *= V_124 . V_336 ;
F_348 ( V_360 , V_136 ) ;
V_336 = ( T_9 ) V_360 ;
} else
V_336 = V_359 ;
V_364 -> V_361 = F_128 ( V_364 -> V_361 , V_336 ) ;
V_364 -> V_362 = F_128 ( V_364 -> V_362 ,
F_349 ( V_359 , V_364 -> V_361 ) ) ;
* V_357 = V_364 -> V_361 ;
* V_358 = V_364 -> V_362 ;
}
void F_350 ( void )
{
int V_32 = F_80 () ;
struct V_31 * V_31 = F_39 ( V_32 ) ;
struct V_4 * V_67 = V_31 -> V_67 ;
F_351 () ;
F_16 ( & V_31 -> V_39 ) ;
F_34 ( V_31 ) ;
F_316 ( V_31 ) ;
V_67 -> V_78 -> V_79 ( V_31 , V_67 , 0 ) ;
F_22 ( & V_31 -> V_39 ) ;
F_352 () ;
#ifdef F_26
V_31 -> V_365 = F_105 ( V_32 ) ;
F_353 ( V_31 , V_32 ) ;
#endif
}
T_13 unsigned long F_354 ( unsigned long V_366 )
{
if ( F_355 ( V_366 ) ) {
V_366 = V_367 ;
if ( F_355 ( V_366 ) )
V_366 = V_368 ;
}
return V_366 ;
}
void T_14 F_356 ( int V_127 )
{
#ifdef F_357
if ( F_358 ( ( V_199 () < 0 ) ) )
return;
#endif
V_199 () += V_127 ;
#ifdef F_357
F_358 ( ( V_199 () & V_369 ) >=
V_369 - 10 ) ;
#endif
if ( V_199 () == V_127 )
F_359 ( V_370 , F_354 ( V_371 ) ) ;
}
void T_14 F_360 ( int V_127 )
{
#ifdef F_357
if ( F_358 ( V_127 > V_199 () ) )
return;
if ( F_358 ( ( V_127 < V_369 ) &&
! ( V_199 () & V_369 ) ) )
return;
#endif
if ( V_199 () == V_127 )
F_361 ( V_370 , F_354 ( V_371 ) ) ;
V_199 () -= V_127 ;
}
static T_15 void F_362 ( struct V_4 * V_70 )
{
struct V_372 * V_373 = F_363 () ;
F_215 ( V_374 L_6 ,
V_70 -> V_221 , V_70 -> V_375 , V_199 () ) ;
F_364 ( V_70 ) ;
F_365 () ;
if ( F_139 () )
F_366 ( V_70 ) ;
if ( V_373 )
F_367 ( V_373 ) ;
else
F_368 () ;
}
static inline void F_369 ( struct V_4 * V_70 )
{
if ( F_2 ( F_370 () && ! V_70 -> V_376 ) )
F_362 ( V_70 ) ;
F_371 ( V_377 , F_372 ( 0 ) ) ;
F_222 ( F_72 () , V_378 ) ;
}
static void F_373 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
if ( V_70 -> V_189 || V_31 -> V_46 < 0 )
F_34 ( V_31 ) ;
V_70 -> V_78 -> F_373 ( V_31 , V_70 ) ;
}
static inline struct V_4 *
F_374 ( struct V_31 * V_31 )
{
const struct V_78 * V_188 ;
struct V_4 * V_5 ;
if ( F_64 ( V_31 -> V_140 == V_31 -> V_379 . V_140 ) ) {
V_5 = V_190 . F_374 ( V_31 ) ;
if ( F_64 ( V_5 ) )
return V_5 ;
}
F_190 (class) {
V_5 = V_188 -> F_374 ( V_31 ) ;
if ( V_5 )
return V_5 ;
}
F_375 () ;
}
T_11 void T_16 F_376 ( void )
{
struct V_4 * V_70 , * V_69 ;
unsigned long * V_380 ;
struct V_31 * V_31 ;
int V_32 ;
V_381:
F_205 () ;
V_32 = F_80 () ;
V_31 = F_39 ( V_32 ) ;
F_377 ( V_32 ) ;
V_70 = V_31 -> V_67 ;
F_369 ( V_70 ) ;
if ( F_74 ( V_76 ) )
F_77 ( V_31 ) ;
F_378 ( & V_31 -> V_39 ) ;
V_380 = & V_70 -> V_382 ;
if ( V_70 -> V_196 && ! ( V_199 () & V_200 ) ) {
if ( F_2 ( F_379 ( V_70 -> V_196 , V_70 ) ) ) {
V_70 -> V_196 = V_197 ;
} else {
F_158 ( V_31 , V_70 , V_383 ) ;
V_70 -> V_189 = 0 ;
if ( V_70 -> V_75 & V_240 ) {
struct V_4 * V_384 ;
V_384 = F_380 ( V_70 , V_32 ) ;
if ( V_384 )
F_243 ( V_384 ) ;
}
if ( F_381 ( V_70 ) ) {
F_22 ( & V_31 -> V_39 ) ;
F_382 ( V_70 ) ;
F_16 ( & V_31 -> V_39 ) ;
}
}
V_380 = & V_70 -> V_207 ;
}
F_279 ( V_31 , V_70 ) ;
if ( F_2 ( ! V_31 -> V_140 ) )
F_383 ( V_32 , V_31 ) ;
F_373 ( V_31 , V_70 ) ;
V_69 = F_374 ( V_31 ) ;
F_384 ( V_70 ) ;
V_31 -> V_46 = 0 ;
if ( F_64 ( V_70 != V_69 ) ) {
V_31 -> V_291 ++ ;
V_31 -> V_67 = V_69 ;
++ * V_380 ;
F_285 ( V_31 , V_70 , V_69 ) ;
V_32 = F_80 () ;
V_31 = F_39 ( V_32 ) ;
} else
F_59 ( & V_31 -> V_39 ) ;
F_280 ( V_31 ) ;
F_385 () ;
if ( V_381 () )
goto V_381;
}
static inline bool F_386 ( struct V_385 * V_39 , struct V_4 * V_71 )
{
bool V_133 = false ;
F_102 () ;
if ( V_39 -> V_71 != V_71 )
goto V_386;
F_292 () ;
V_133 = V_71 -> V_68 ;
V_386:
F_106 () ;
return V_133 ;
}
int F_387 ( struct V_385 * V_39 , struct V_4 * V_71 )
{
if ( ! F_74 ( V_387 ) )
return 0 ;
while ( F_386 ( V_39 , V_71 ) ) {
if ( V_381 () )
return 0 ;
F_388 () ;
}
if ( V_39 -> V_71 )
return 0 ;
return 1 ;
}
T_11 void T_16 T_13 F_389 ( void )
{
struct V_388 * V_389 = F_390 () ;
if ( F_64 ( V_389 -> V_199 || F_139 () ) )
return;
do {
F_391 ( V_200 ) ;
F_376 () ;
F_392 ( V_200 ) ;
F_292 () ;
} while ( V_381 () );
}
T_11 void T_16 F_393 ( void )
{
struct V_388 * V_389 = F_390 () ;
F_140 ( V_389 -> V_199 || ! F_139 () ) ;
do {
F_356 ( V_200 ) ;
F_61 () ;
F_376 () ;
F_71 () ;
F_360 ( V_200 ) ;
F_292 () ;
} while ( V_381 () );
}
int F_394 ( T_17 * V_67 , unsigned V_390 , int V_223 ,
void * V_391 )
{
return F_241 ( V_67 -> V_392 , V_390 , V_223 ) ;
}
static void F_395 ( T_18 * V_393 , unsigned int V_390 ,
int V_394 , int V_223 , void * V_391 )
{
T_17 * V_67 , * V_69 ;
F_396 (curr, next, &q->task_list, task_list) {
unsigned V_75 = V_67 -> V_75 ;
if ( V_67 -> V_99 ( V_67 , V_390 , V_223 , V_391 ) &&
( V_75 & V_395 ) && ! -- V_394 )
break;
}
}
void F_397 ( T_18 * V_393 , unsigned int V_390 ,
int V_394 , void * V_391 )
{
unsigned long V_75 ;
F_398 ( & V_393 -> V_39 , V_75 ) ;
F_395 ( V_393 , V_390 , V_394 , 0 , V_391 ) ;
F_399 ( & V_393 -> V_39 , V_75 ) ;
}
void F_400 ( T_18 * V_393 , unsigned int V_390 )
{
F_395 ( V_393 , V_390 , 1 , 0 , NULL ) ;
}
void F_401 ( T_18 * V_393 , unsigned int V_390 , void * V_391 )
{
F_395 ( V_393 , V_390 , 1 , 0 , V_391 ) ;
}
void F_402 ( T_18 * V_393 , unsigned int V_390 ,
int V_394 , void * V_391 )
{
unsigned long V_75 ;
int V_223 = V_237 ;
if ( F_2 ( ! V_393 ) )
return;
if ( F_2 ( ! V_394 ) )
V_223 = 0 ;
F_398 ( & V_393 -> V_39 , V_75 ) ;
F_395 ( V_393 , V_390 , V_394 , V_223 , V_391 ) ;
F_399 ( & V_393 -> V_39 , V_75 ) ;
}
void F_403 ( T_18 * V_393 , unsigned int V_390 , int V_394 )
{
F_402 ( V_393 , V_390 , V_394 , NULL ) ;
}
void F_404 ( struct V_396 * V_299 )
{
unsigned long V_75 ;
F_398 ( & V_299 -> V_397 . V_39 , V_75 ) ;
V_299 -> V_398 ++ ;
F_395 ( & V_299 -> V_397 , V_257 , 1 , 0 , NULL ) ;
F_399 ( & V_299 -> V_397 . V_39 , V_75 ) ;
}
void F_405 ( struct V_396 * V_299 )
{
unsigned long V_75 ;
F_398 ( & V_299 -> V_397 . V_39 , V_75 ) ;
V_299 -> V_398 += V_399 / 2 ;
F_395 ( & V_299 -> V_397 , V_257 , 0 , 0 , NULL ) ;
F_399 ( & V_299 -> V_397 . V_39 , V_75 ) ;
}
static inline long T_16
F_406 ( struct V_396 * V_299 , long V_400 , int V_196 )
{
if ( ! V_299 -> V_398 ) {
F_407 ( V_397 , V_72 ) ;
F_408 ( & V_299 -> V_397 , & V_397 ) ;
do {
if ( F_379 ( V_196 , V_72 ) ) {
V_400 = - V_401 ;
break;
}
F_409 ( V_196 ) ;
F_410 ( & V_299 -> V_397 . V_39 ) ;
V_400 = F_411 ( V_400 ) ;
F_412 ( & V_299 -> V_397 . V_39 ) ;
} while ( ! V_299 -> V_398 && V_400 );
F_413 ( & V_299 -> V_397 , & V_397 ) ;
if ( ! V_299 -> V_398 )
return V_400 ;
}
V_299 -> V_398 -- ;
return V_400 ? : 1 ;
}
static long T_16
F_414 ( struct V_396 * V_299 , long V_400 , int V_196 )
{
F_415 () ;
F_412 ( & V_299 -> V_397 . V_39 ) ;
V_400 = F_406 ( V_299 , V_400 , V_196 ) ;
F_410 ( & V_299 -> V_397 . V_39 ) ;
return V_400 ;
}
void T_16 F_416 ( struct V_396 * V_299 )
{
F_414 ( V_299 , V_402 , V_212 ) ;
}
unsigned long T_16
F_417 ( struct V_396 * V_299 , unsigned long V_400 )
{
return F_414 ( V_299 , V_400 , V_212 ) ;
}
int T_16 F_418 ( struct V_396 * V_299 )
{
long V_403 = F_414 ( V_299 , V_402 , V_404 ) ;
if ( V_403 == - V_401 )
return V_403 ;
return 0 ;
}
long T_16
F_419 ( struct V_396 * V_299 ,
unsigned long V_400 )
{
return F_414 ( V_299 , V_400 , V_404 ) ;
}
int T_16 F_420 ( struct V_396 * V_299 )
{
long V_403 = F_414 ( V_299 , V_402 , V_405 ) ;
if ( V_403 == - V_401 )
return V_403 ;
return 0 ;
}
long T_16
F_421 ( struct V_396 * V_299 ,
unsigned long V_400 )
{
return F_414 ( V_299 , V_400 , V_405 ) ;
}
bool F_422 ( struct V_396 * V_299 )
{
unsigned long V_75 ;
int V_133 = 1 ;
F_398 ( & V_299 -> V_397 . V_39 , V_75 ) ;
if ( ! V_299 -> V_398 )
V_133 = 0 ;
else
V_299 -> V_398 -- ;
F_399 ( & V_299 -> V_397 . V_39 , V_75 ) ;
return V_133 ;
}
bool F_423 ( struct V_396 * V_299 )
{
unsigned long V_75 ;
int V_133 = 1 ;
F_398 ( & V_299 -> V_397 . V_39 , V_75 ) ;
if ( ! V_299 -> V_398 )
V_133 = 0 ;
F_399 ( & V_299 -> V_397 . V_39 , V_75 ) ;
return V_133 ;
}
static long T_16
F_424 ( T_18 * V_393 , int V_196 , long V_400 )
{
unsigned long V_75 ;
T_17 V_397 ;
F_425 ( & V_397 , V_72 ) ;
F_409 ( V_196 ) ;
F_398 ( & V_393 -> V_39 , V_75 ) ;
F_426 ( V_393 , & V_397 ) ;
F_427 ( & V_393 -> V_39 ) ;
V_400 = F_411 ( V_400 ) ;
F_412 ( & V_393 -> V_39 ) ;
F_413 ( V_393 , & V_397 ) ;
F_399 ( & V_393 -> V_39 , V_75 ) ;
return V_400 ;
}
void T_16 F_428 ( T_18 * V_393 )
{
F_424 ( V_393 , V_404 , V_402 ) ;
}
long T_16
F_429 ( T_18 * V_393 , long V_400 )
{
return F_424 ( V_393 , V_404 , V_400 ) ;
}
void T_16 F_430 ( T_18 * V_393 )
{
F_424 ( V_393 , V_212 , V_402 ) ;
}
long T_16 F_431 ( T_18 * V_393 , long V_400 )
{
return F_424 ( V_393 , V_212 , V_400 ) ;
}
void F_432 ( struct V_4 * V_5 , int V_148 )
{
int V_184 , V_189 , V_205 ;
struct V_31 * V_31 ;
const struct V_78 * V_183 ;
F_140 ( V_148 < 0 || V_148 > V_271 ) ;
V_31 = F_62 ( V_5 ) ;
F_433 ( V_5 , V_148 ) ;
V_184 = V_5 -> V_148 ;
V_183 = V_5 -> V_78 ;
V_189 = V_5 -> V_189 ;
V_205 = F_52 ( V_31 , V_5 ) ;
if ( V_189 )
F_154 ( V_31 , V_5 , 0 ) ;
if ( V_205 )
V_5 -> V_78 -> F_373 ( V_31 , V_5 ) ;
if ( F_186 ( V_148 ) )
V_5 -> V_78 = & V_181 ;
else
V_5 -> V_78 = & V_190 ;
V_5 -> V_148 = V_148 ;
if ( V_205 )
V_5 -> V_78 -> V_406 ( V_31 ) ;
if ( V_189 )
F_152 ( V_31 , V_5 , V_184 < V_148 ? V_407 : 0 ) ;
F_188 ( V_31 , V_5 , V_183 , V_184 ) ;
F_68 ( V_31 ) ;
}
void F_434 ( struct V_4 * V_5 , long V_338 )
{
int V_408 , V_27 , V_189 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
if ( F_328 ( V_5 ) == V_338 || V_338 < - 20 || V_338 > 19 )
return;
V_31 = F_65 ( V_5 , & V_75 ) ;
if ( F_3 ( V_5 ) ) {
V_5 -> V_149 = F_253 ( V_338 ) ;
goto V_135;
}
V_189 = V_5 -> V_189 ;
if ( V_189 )
F_154 ( V_31 , V_5 , 0 ) ;
V_5 -> V_149 = F_253 ( V_338 ) ;
F_150 ( V_5 ) ;
V_408 = V_5 -> V_148 ;
V_5 -> V_148 = F_185 ( V_5 ) ;
V_27 = V_5 -> V_148 - V_408 ;
if ( V_189 ) {
F_152 ( V_31 , V_5 , 0 ) ;
if ( V_27 < 0 || ( V_27 > 0 && F_53 ( V_31 , V_5 ) ) )
F_90 ( V_31 -> V_67 ) ;
}
V_135:
F_69 ( V_31 , V_5 , & V_75 ) ;
}
int F_435 ( const struct V_4 * V_5 , const int V_338 )
{
int V_409 = 20 - V_338 ;
return ( V_409 <= F_436 ( V_5 , V_410 ) ||
F_437 ( V_411 ) ) ;
}
int F_438 ( const struct V_4 * V_5 )
{
return V_5 -> V_148 - V_150 ;
}
int F_439 ( const struct V_4 * V_5 )
{
return F_328 ( V_5 ) ;
}
int F_105 ( int V_32 )
{
return F_100 ( V_32 ) == F_39 ( V_32 ) -> V_14 ;
}
struct V_4 * F_440 ( int V_32 )
{
return F_39 ( V_32 ) -> V_14 ;
}
static struct V_4 * F_441 ( T_19 V_375 )
{
return V_375 ? F_442 ( V_375 ) : V_72 ;
}
static void
F_443 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_1 , int V_148 )
{
V_5 -> V_1 = V_1 ;
V_5 -> V_182 = V_148 ;
V_5 -> F_184 = F_184 ( V_5 ) ;
V_5 -> V_148 = F_444 ( V_5 ) ;
if ( F_186 ( V_5 -> V_148 ) )
V_5 -> V_78 = & V_181 ;
else
V_5 -> V_78 = & V_190 ;
F_150 ( V_5 ) ;
}
static bool F_445 ( struct V_4 * V_5 )
{
const struct V_412 * V_412 = F_446 () , * V_413 ;
bool V_414 ;
F_102 () ;
V_413 = F_447 ( V_5 ) ;
if ( V_412 -> V_339 -> V_415 == V_413 -> V_339 -> V_415 )
V_414 = ( V_412 -> V_416 == V_413 -> V_416 ||
V_412 -> V_416 == V_413 -> V_417 ) ;
else
V_414 = false ;
F_106 () ;
return V_414 ;
}
static int F_448 ( struct V_4 * V_5 , int V_1 ,
const struct V_176 * V_177 , bool V_339 )
{
int V_418 , V_184 , V_419 = - 1 , V_189 , V_205 ;
unsigned long V_75 ;
const struct V_78 * V_183 ;
struct V_31 * V_31 ;
int V_420 ;
F_140 ( F_449 () ) ;
V_421:
if ( V_1 < 0 ) {
V_420 = V_5 -> V_265 ;
V_1 = V_419 = V_5 -> V_1 ;
} else {
V_420 = ! ! ( V_1 & V_422 ) ;
V_1 &= ~ V_422 ;
if ( V_1 != V_2 && V_1 != V_3 &&
V_1 != V_266 && V_1 != V_423 &&
V_1 != V_151 )
return - V_62 ;
}
if ( V_177 -> V_178 < 0 ||
( V_5 -> V_219 && V_177 -> V_178 > V_424 - 1 ) ||
( ! V_5 -> V_219 && V_177 -> V_178 > V_150 - 1 ) )
return - V_62 ;
if ( F_1 ( V_1 ) != ( V_177 -> V_178 != 0 ) )
return - V_62 ;
if ( V_339 && ! F_437 ( V_411 ) ) {
if ( F_1 ( V_1 ) ) {
unsigned long V_425 =
F_436 ( V_5 , V_426 ) ;
if ( V_1 != V_5 -> V_1 && ! V_425 )
return - V_427 ;
if ( V_177 -> V_178 > V_5 -> V_182 &&
V_177 -> V_178 > V_425 )
return - V_427 ;
}
if ( V_5 -> V_1 == V_151 && V_1 != V_151 ) {
if ( ! F_435 ( V_5 , F_328 ( V_5 ) ) )
return - V_427 ;
}
if ( ! F_445 ( V_5 ) )
return - V_427 ;
if ( V_5 -> V_265 && ! V_420 )
return - V_427 ;
}
if ( V_339 ) {
V_418 = F_450 ( V_5 ) ;
if ( V_418 )
return V_418 ;
}
V_31 = F_65 ( V_5 , & V_75 ) ;
if ( V_5 == V_31 -> V_175 ) {
F_69 ( V_31 , V_5 , & V_75 ) ;
return - V_62 ;
}
if ( F_2 ( V_1 == V_5 -> V_1 && ( ! F_1 ( V_1 ) ||
V_177 -> V_178 == V_5 -> V_182 ) ) ) {
F_68 ( V_31 ) ;
F_67 ( & V_5 -> V_38 , V_75 ) ;
return 0 ;
}
#ifdef F_33
if ( V_339 ) {
if ( F_13 () && F_1 ( V_1 ) &&
V_33 ( V_5 ) -> V_9 . V_20 == 0 &&
! F_451 ( V_33 ( V_5 ) ) ) {
F_69 ( V_31 , V_5 , & V_75 ) ;
return - V_427 ;
}
}
#endif
if ( F_2 ( V_419 != - 1 && V_419 != V_5 -> V_1 ) ) {
V_1 = V_419 = - 1 ;
F_69 ( V_31 , V_5 , & V_75 ) ;
goto V_421;
}
V_189 = V_5 -> V_189 ;
V_205 = F_52 ( V_31 , V_5 ) ;
if ( V_189 )
F_158 ( V_31 , V_5 , 0 ) ;
if ( V_205 )
V_5 -> V_78 -> F_373 ( V_31 , V_5 ) ;
V_5 -> V_265 = V_420 ;
V_184 = V_5 -> V_148 ;
V_183 = V_5 -> V_78 ;
F_443 ( V_31 , V_5 , V_1 , V_177 -> V_178 ) ;
if ( V_205 )
V_5 -> V_78 -> V_406 ( V_31 ) ;
if ( V_189 )
F_156 ( V_31 , V_5 , 0 ) ;
F_188 ( V_31 , V_5 , V_183 , V_184 ) ;
F_69 ( V_31 , V_5 , & V_75 ) ;
F_452 ( V_5 ) ;
return 0 ;
}
int F_453 ( struct V_4 * V_5 , int V_1 ,
const struct V_176 * V_177 )
{
return F_448 ( V_5 , V_1 , V_177 , true ) ;
}
int F_182 ( struct V_4 * V_5 , int V_1 ,
const struct V_176 * V_177 )
{
return F_448 ( V_5 , V_1 , V_177 , false ) ;
}
static int
F_454 ( T_19 V_375 , int V_1 , struct V_176 T_5 * V_177 )
{
struct V_176 V_428 ;
struct V_4 * V_5 ;
int V_418 ;
if ( ! V_177 || V_375 < 0 )
return - V_62 ;
if ( F_44 ( & V_428 , V_177 , sizeof( struct V_176 ) ) )
return - V_61 ;
F_102 () ;
V_418 = - V_429 ;
V_5 = F_441 ( V_375 ) ;
if ( V_5 != NULL )
V_418 = F_453 ( V_5 , V_1 , & V_428 ) ;
F_106 () ;
return V_418 ;
}
long F_455 ( T_19 V_375 , const struct V_214 * V_430 )
{
T_20 V_216 , V_431 ;
struct V_4 * V_5 ;
int V_418 ;
F_456 () ;
F_102 () ;
V_5 = F_441 ( V_375 ) ;
if ( ! V_5 ) {
F_106 () ;
F_457 () ;
return - V_429 ;
}
F_458 ( V_5 ) ;
F_106 () ;
if ( ! F_459 ( & V_216 , V_432 ) ) {
V_418 = - V_433 ;
goto V_434;
}
if ( ! F_459 ( & V_431 , V_432 ) ) {
V_418 = - V_433 ;
goto V_435;
}
V_418 = - V_427 ;
if ( ! F_445 ( V_5 ) && ! F_460 ( V_5 , V_411 ) )
goto V_135;
V_418 = F_450 ( V_5 ) ;
if ( V_418 )
goto V_135;
F_461 ( V_5 , V_216 ) ;
F_462 ( V_431 , V_430 , V_216 ) ;
V_436:
V_418 = F_463 ( V_5 , V_431 ) ;
if ( ! V_418 ) {
F_461 ( V_5 , V_216 ) ;
if ( ! F_464 ( V_431 , V_216 ) ) {
F_465 ( V_431 , V_216 ) ;
goto V_436;
}
}
V_135:
F_466 ( V_431 ) ;
V_435:
F_466 ( V_216 ) ;
V_434:
F_278 ( V_5 ) ;
F_457 () ;
return V_418 ;
}
static int F_467 ( unsigned long T_5 * V_437 , unsigned V_438 ,
struct V_214 * V_431 )
{
if ( V_438 < F_468 () )
F_469 ( V_431 ) ;
else if ( V_438 > F_468 () )
V_438 = F_468 () ;
return F_44 ( V_431 , V_437 , V_438 ) ? - V_61 : 0 ;
}
long F_470 ( T_19 V_375 , struct V_214 * V_439 )
{
struct V_4 * V_5 ;
unsigned long V_75 ;
int V_418 ;
F_456 () ;
F_102 () ;
V_418 = - V_429 ;
V_5 = F_441 ( V_375 ) ;
if ( ! V_5 )
goto V_135;
V_418 = F_471 ( V_5 ) ;
if ( V_418 )
goto V_135;
F_66 ( & V_5 -> V_38 , V_75 ) ;
F_462 ( V_439 , & V_5 -> V_216 , V_440 ) ;
F_67 ( & V_5 -> V_38 , V_75 ) ;
V_135:
F_106 () ;
F_457 () ;
return V_418 ;
}
static inline int F_472 ( void )
{
return V_381 () && ! ( V_199 () & V_200 ) ;
}
static void F_473 ( void )
{
F_356 ( V_200 ) ;
F_376 () ;
F_360 ( V_200 ) ;
}
int T_16 F_474 ( void )
{
if ( F_472 () ) {
F_473 () ;
return 1 ;
}
return 0 ;
}
int F_475 ( T_21 * V_39 )
{
int V_441 = F_472 () ;
int V_133 = 0 ;
F_63 ( V_39 ) ;
if ( F_476 ( V_39 ) || V_441 ) {
F_427 ( V_39 ) ;
if ( V_441 )
F_473 () ;
else
F_199 () ;
V_133 = 1 ;
F_477 ( V_39 ) ;
}
return V_133 ;
}
int T_16 F_478 ( void )
{
F_140 ( ! F_479 () ) ;
if ( F_472 () ) {
F_480 () ;
F_473 () ;
F_481 () ;
return 1 ;
}
return 0 ;
}
void T_16 F_482 ( void )
{
F_202 ( V_197 ) ;
F_483 () ;
}
bool T_16 F_484 ( struct V_4 * V_5 , bool V_442 )
{
struct V_4 * V_67 = V_72 ;
struct V_31 * V_31 , * V_443 ;
unsigned long V_75 ;
bool V_444 = 0 ;
F_169 ( V_75 ) ;
V_31 = F_72 () ;
V_436:
V_443 = F_29 ( V_5 ) ;
F_135 ( V_31 , V_443 ) ;
while ( F_29 ( V_5 ) != V_443 ) {
F_144 ( V_31 , V_443 ) ;
goto V_436;
}
if ( ! V_67 -> V_78 -> V_445 )
goto V_253;
if ( V_67 -> V_78 != V_5 -> V_78 )
goto V_253;
if ( F_53 ( V_443 , V_5 ) || V_5 -> V_196 )
goto V_253;
V_444 = V_67 -> V_78 -> V_445 ( V_31 , V_5 , V_442 ) ;
if ( V_444 ) {
F_222 ( V_31 , V_446 ) ;
if ( V_442 && V_31 != V_443 )
F_90 ( V_443 -> V_67 ) ;
}
V_253:
F_144 ( V_31 , V_443 ) ;
F_175 ( V_75 ) ;
if ( V_444 )
F_376 () ;
return V_444 ;
}
void T_16 F_485 ( void )
{
struct V_31 * V_31 = F_486 () ;
F_487 () ;
F_287 ( & V_31 -> F_296 ) ;
F_488 ( V_72 ) ;
V_72 -> V_447 = 1 ;
F_376 () ;
V_72 -> V_447 = 0 ;
F_489 ( & V_31 -> F_296 ) ;
F_490 () ;
}
long T_16 F_491 ( long V_400 )
{
struct V_31 * V_31 = F_486 () ;
long V_133 ;
F_487 () ;
F_287 ( & V_31 -> F_296 ) ;
F_488 ( V_72 ) ;
V_72 -> V_447 = 1 ;
V_133 = F_411 ( V_400 ) ;
V_72 -> V_447 = 0 ;
F_489 ( & V_31 -> F_296 ) ;
F_490 () ;
return V_133 ;
}
void F_492 ( struct V_4 * V_5 )
{
unsigned long free = 0 ;
unsigned V_196 ;
V_196 = V_5 -> V_196 ? F_493 ( V_5 -> V_196 ) + 1 : 0 ;
F_215 ( V_220 L_7 , V_5 -> V_221 ,
V_196 < sizeof( V_448 ) - 1 ? V_448 [ V_196 ] : '?' ) ;
#if V_117 == 32
if ( V_196 == V_197 )
F_215 ( V_449 L_8 ) ;
else
F_215 ( V_449 L_9 , F_494 ( V_5 ) ) ;
#else
if ( V_196 == V_197 )
F_215 ( V_449 L_10 ) ;
else
F_215 ( V_449 L_11 , F_494 ( V_5 ) ) ;
#endif
#ifdef F_495
free = F_496 ( V_5 ) ;
#endif
F_215 ( V_449 L_12 , free ,
F_216 ( V_5 ) , F_216 ( V_5 -> V_450 ) ,
( unsigned long ) F_147 ( V_5 ) -> V_75 ) ;
F_497 ( V_5 , NULL ) ;
}
void F_498 ( unsigned long V_451 )
{
struct V_4 * V_452 , * V_5 ;
#if V_117 == 32
F_215 ( V_220
L_13 ) ;
#else
F_215 ( V_220
L_14 ) ;
#endif
F_499 ( & V_453 ) ;
F_500 (g, p) {
F_501 () ;
if ( ! V_451 || ( V_5 -> V_196 & V_451 ) )
F_492 ( V_5 ) ;
} F_502 ( V_452 , V_5 ) ;
F_503 () ;
#ifdef F_194
F_504 () ;
#endif
F_505 ( & V_453 ) ;
if ( ! V_451 )
F_506 () ;
}
void T_22 F_507 ( struct V_4 * V_14 )
{
V_14 -> V_78 = & V_454 ;
}
void T_22 F_508 ( struct V_4 * V_14 , int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_75 ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
F_246 ( V_14 ) ;
V_14 -> V_196 = V_197 ;
V_14 -> V_40 . V_194 = F_509 () ;
F_510 ( V_14 , F_511 ( V_32 ) ) ;
F_102 () ;
F_146 ( V_14 , V_32 ) ;
F_106 () ;
V_31 -> V_67 = V_31 -> V_14 = V_14 ;
#if F_240 ( F_26 )
V_14 -> V_68 = 1 ;
#endif
F_67 ( & V_31 -> V_39 , V_75 ) ;
F_147 ( V_14 ) -> V_199 = 0 ;
V_14 -> V_78 = & V_454 ;
F_512 ( V_14 , V_32 ) ;
}
static int F_513 ( void )
{
unsigned int V_455 = F_514 ( int , F_515 () , 8 ) ;
unsigned int V_456 ;
switch ( V_457 ) {
case V_458 :
V_456 = 1 ;
break;
case V_459 :
V_456 = V_455 ;
break;
case V_460 :
default:
V_456 = 1 + F_516 ( V_455 ) ;
break;
}
return V_456 ;
}
static void F_517 ( void )
{
unsigned int V_456 = F_513 () ;
#define F_518 ( T_23 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_518 ( V_461 ) ;
F_518 ( V_462 ) ;
F_518 ( V_463 ) ;
#undef F_518
}
static inline void F_519 ( void )
{
F_517 () ;
}
void F_510 ( struct V_4 * V_5 , const struct V_214 * V_431 )
{
if ( V_5 -> V_78 && V_5 -> V_78 -> V_464 )
V_5 -> V_78 -> V_464 ( V_5 , V_431 ) ;
else {
F_465 ( & V_5 -> V_216 , V_431 ) ;
V_5 -> V_43 . V_465 = F_520 ( V_431 ) ;
}
}
int F_463 ( struct V_4 * V_5 , const struct V_214 * V_431 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
unsigned int V_213 ;
int V_133 = 0 ;
V_31 = F_65 ( V_5 , & V_75 ) ;
if ( F_521 ( & V_5 -> V_216 , V_431 ) )
goto V_253;
if ( ! F_522 ( V_431 , V_217 ) ) {
V_133 = - V_62 ;
goto V_253;
}
if ( F_2 ( ( V_5 -> V_75 & V_466 ) && V_5 != V_72 ) ) {
V_133 = - V_62 ;
goto V_253;
}
F_510 ( V_5 , V_431 ) ;
if ( F_211 ( F_94 ( V_5 ) , V_431 ) )
goto V_253;
V_213 = F_212 ( V_217 , V_431 ) ;
if ( V_5 -> V_189 ) {
struct V_330 V_80 = { V_5 , V_213 } ;
F_69 ( V_31 , V_5 , & V_75 ) ;
F_318 ( F_25 ( V_31 ) , V_331 , & V_80 ) ;
F_523 ( V_5 -> V_219 ) ;
return 0 ;
}
V_253:
F_69 ( V_31 , V_5 , & V_75 ) ;
return V_133 ;
}
static int F_524 ( struct V_4 * V_5 , int V_467 , int V_213 )
{
struct V_31 * V_468 , * V_469 ;
int V_133 = 0 ;
if ( F_2 ( ! F_75 ( V_213 ) ) )
return V_133 ;
V_469 = F_39 ( V_467 ) ;
V_468 = F_39 ( V_213 ) ;
F_16 ( & V_5 -> V_38 ) ;
F_135 ( V_469 , V_468 ) ;
if ( F_94 ( V_5 ) != V_467 )
goto V_398;
if ( ! F_211 ( V_213 , & V_5 -> V_216 ) )
goto V_386;
if ( V_5 -> V_189 ) {
F_158 ( V_469 , V_5 , 0 ) ;
F_193 ( V_5 , V_213 ) ;
F_156 ( V_468 , V_5 , 0 ) ;
F_189 ( V_468 , V_5 , 0 ) ;
}
V_398:
V_133 = 1 ;
V_386:
F_144 ( V_469 , V_468 ) ;
F_22 ( & V_5 -> V_38 ) ;
return V_133 ;
}
static int V_331 ( void * V_131 )
{
struct V_330 * V_80 = V_131 ;
F_71 () ;
F_524 ( V_80 -> V_470 , F_266 () , V_80 -> V_213 ) ;
F_61 () ;
return 0 ;
}
void F_525 ( void )
{
struct V_282 * V_219 = V_72 -> V_288 ;
F_140 ( F_218 ( F_80 () ) ) ;
if ( V_219 != & V_471 )
F_289 ( V_219 , & V_471 , V_72 ) ;
F_276 ( V_219 ) ;
}
static void F_526 ( struct V_31 * V_469 )
{
struct V_31 * V_468 = F_39 ( F_527 ( V_217 ) ) ;
V_468 -> V_156 += V_469 -> V_156 ;
V_469 -> V_156 = 0 ;
}
static void F_528 ( struct V_31 * V_31 )
{
F_529 ( V_31 -> V_294 , & V_306 ) ;
V_31 -> V_294 = 0 ;
}
static void F_530 ( unsigned int V_472 )
{
struct V_31 * V_31 = F_39 ( V_472 ) ;
struct V_4 * V_69 , * V_175 = V_31 -> V_175 ;
int V_213 ;
V_31 -> V_175 = NULL ;
for ( ; ; ) {
if ( V_31 -> V_140 == 1 )
break;
V_69 = F_374 ( V_31 ) ;
F_140 ( ! V_69 ) ;
V_69 -> V_78 -> F_373 ( V_31 , V_69 ) ;
V_213 = F_207 ( V_472 , V_69 ) ;
F_22 ( & V_31 -> V_39 ) ;
F_524 ( V_69 , V_472 , V_213 ) ;
F_16 ( & V_31 -> V_39 ) ;
}
V_31 -> V_175 = V_175 ;
}
static struct V_473 * F_531 ( int V_301 )
{
struct V_473 * V_474 =
F_532 ( V_301 , sizeof( struct V_473 ) , V_432 ) ;
return V_474 ;
}
static void F_533 ( struct V_473 * * V_475 )
{
struct V_473 * V_474 ;
for ( V_474 = * V_475 ; V_474 -> V_390 ; V_474 ++ ) {
if ( V_474 -> V_132 )
F_533 ( & V_474 -> V_132 ) ;
if ( V_474 -> V_476 == NULL )
F_534 ( V_474 -> V_477 ) ;
}
F_534 ( * V_475 ) ;
* V_475 = NULL ;
}
static void
F_535 ( struct V_473 * V_474 ,
const char * V_477 , void * V_131 , int V_478 ,
T_24 V_390 , V_476 * V_476 )
{
V_474 -> V_477 = V_477 ;
V_474 -> V_131 = V_131 ;
V_474 -> V_478 = V_478 ;
V_474 -> V_390 = V_390 ;
V_474 -> V_476 = V_476 ;
}
static struct V_473 *
F_536 ( struct V_101 * V_102 )
{
struct V_473 * V_479 = F_531 ( 13 ) ;
if ( V_479 == NULL )
return NULL ;
F_535 ( & V_479 [ 0 ] , L_15 , & V_102 -> V_480 ,
sizeof( long ) , 0644 , V_481 ) ;
F_535 ( & V_479 [ 1 ] , L_16 , & V_102 -> V_482 ,
sizeof( long ) , 0644 , V_481 ) ;
F_535 ( & V_479 [ 2 ] , L_17 , & V_102 -> V_483 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 3 ] , L_18 , & V_102 -> V_485 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 4 ] , L_19 , & V_102 -> V_486 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 5 ] , L_20 , & V_102 -> V_487 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 6 ] , L_21 , & V_102 -> V_488 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 7 ] , L_22 , & V_102 -> V_489 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 8 ] , L_23 , & V_102 -> V_490 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 9 ] , L_24 ,
& V_102 -> V_491 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 10 ] , L_25 , & V_102 -> V_75 ,
sizeof( int ) , 0644 , V_484 ) ;
F_535 ( & V_479 [ 11 ] , L_26 , V_102 -> T_23 ,
V_492 , 0444 , V_493 ) ;
return V_479 ;
}
static V_473 * F_537 ( int V_32 )
{
struct V_473 * V_474 , * V_479 ;
struct V_101 * V_102 ;
int V_494 = 0 , V_50 ;
char V_58 [ 32 ] ;
F_103 (cpu, sd)
V_494 ++ ;
V_474 = V_479 = F_531 ( V_494 + 1 ) ;
if ( V_479 == NULL )
return NULL ;
V_50 = 0 ;
F_103 (cpu, sd) {
snprintf ( V_58 , 32 , L_27 , V_50 ) ;
V_474 -> V_477 = F_538 ( V_58 , V_432 ) ;
V_474 -> V_390 = 0555 ;
V_474 -> V_132 = F_536 ( V_102 ) ;
V_474 ++ ;
V_50 ++ ;
}
return V_479 ;
}
static void F_539 ( void )
{
int V_50 , V_495 = F_540 () ;
struct V_473 * V_474 = F_531 ( V_495 + 1 ) ;
char V_58 [ 32 ] ;
F_541 ( V_496 [ 0 ] . V_132 ) ;
V_496 [ 0 ] . V_132 = V_474 ;
if ( V_474 == NULL )
return;
F_294 (i) {
snprintf ( V_58 , 32 , L_28 , V_50 ) ;
V_474 -> V_477 = F_538 ( V_58 , V_432 ) ;
V_474 -> V_390 = 0555 ;
V_474 -> V_132 = F_537 ( V_50 ) ;
V_474 ++ ;
}
F_541 ( V_497 ) ;
V_497 = F_542 ( V_498 ) ;
}
static void F_543 ( void )
{
if ( V_497 )
F_544 ( V_497 ) ;
V_497 = NULL ;
if ( V_496 [ 0 ] . V_132 )
F_533 ( & V_496 [ 0 ] . V_132 ) ;
}
static void F_539 ( void )
{
}
static void F_543 ( void )
{
}
static void F_545 ( struct V_31 * V_31 )
{
if ( ! V_31 -> V_499 ) {
const struct V_78 * V_188 ;
F_546 ( V_31 -> V_32 , V_31 -> V_500 -> V_499 ) ;
V_31 -> V_499 = 1 ;
F_190 (class) {
if ( V_188 -> V_501 )
V_188 -> V_501 ( V_31 ) ;
}
}
}
static void F_547 ( struct V_31 * V_31 )
{
if ( V_31 -> V_499 ) {
const struct V_78 * V_188 ;
F_190 (class) {
if ( V_188 -> V_502 )
V_188 -> V_502 ( V_31 ) ;
}
F_548 ( V_31 -> V_32 , V_31 -> V_500 -> V_499 ) ;
V_31 -> V_499 = 0 ;
}
}
static int T_22
F_549 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
int V_32 = ( long ) V_89 ;
unsigned long V_75 ;
struct V_31 * V_31 = F_39 ( V_32 ) ;
switch ( V_88 & ~ V_503 ) {
case V_504 :
V_31 -> V_305 = V_305 ;
break;
case V_505 :
F_66 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_500 ) {
F_140 ( ! F_211 ( V_32 , V_31 -> V_500 -> V_506 ) ) ;
F_545 ( V_31 ) ;
}
F_67 ( & V_31 -> V_39 , V_75 ) ;
break;
#ifdef F_550
case V_507 :
F_231 () ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_500 ) {
F_140 ( ! F_211 ( V_32 , V_31 -> V_500 -> V_506 ) ) ;
F_547 ( V_31 ) ;
}
F_530 ( V_32 ) ;
F_140 ( V_31 -> V_140 != 1 ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
F_526 ( V_31 ) ;
F_528 ( V_31 ) ;
break;
#endif
}
F_551 () ;
return V_96 ;
}
static int T_22 F_552 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
switch ( V_88 & ~ V_503 ) {
case V_505 :
case V_508 :
F_553 ( ( long ) V_89 , true ) ;
return V_96 ;
default:
return V_97 ;
}
}
static int T_22 F_554 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
switch ( V_88 & ~ V_503 ) {
case V_92 :
F_553 ( ( long ) V_89 , false ) ;
return V_96 ;
default:
return V_97 ;
}
}
static int T_8 F_555 ( void )
{
void * V_32 = ( void * ) ( long ) F_80 () ;
int V_509 ;
V_509 = F_549 ( & V_510 , V_504 , V_32 ) ;
F_140 ( V_509 == V_511 ) ;
F_549 ( & V_510 , V_505 , V_32 ) ;
F_556 ( & V_510 ) ;
F_557 ( F_552 , V_512 ) ;
F_557 ( F_554 , V_513 ) ;
return 0 ;
}
static int T_8 F_558 ( char * V_514 )
{
V_515 = 1 ;
return 0 ;
}
static int F_559 ( struct V_101 * V_102 , int V_32 , int V_516 ,
struct V_214 * V_517 )
{
struct V_518 * V_519 = V_102 -> V_520 ;
char V_514 [ 256 ] ;
F_560 ( V_514 , sizeof( V_514 ) , F_223 ( V_102 ) ) ;
F_469 ( V_517 ) ;
F_215 ( V_521 L_29 , V_516 , L_30 , V_516 ) ;
if ( ! ( V_102 -> V_75 & V_522 ) ) {
F_215 ( L_31 ) ;
if ( V_102 -> V_42 )
F_215 ( V_374 L_32
L_33 ) ;
return - 1 ;
}
F_215 ( V_449 L_34 , V_514 , V_102 -> T_23 ) ;
if ( ! F_211 ( V_32 , F_223 ( V_102 ) ) ) {
F_215 ( V_374 L_35
L_36 , V_32 ) ;
}
if ( ! F_211 ( V_32 , F_561 ( V_519 ) ) ) {
F_215 ( V_374 L_37
L_38 , V_32 ) ;
}
F_215 ( V_521 L_39 , V_516 + 1 , L_30 ) ;
do {
if ( ! V_519 ) {
F_215 ( L_3 ) ;
F_215 ( V_374 L_40 ) ;
break;
}
if ( ! V_519 -> V_523 -> V_524 ) {
F_215 ( V_449 L_3 ) ;
F_215 ( V_374 L_41
L_42 ) ;
break;
}
if ( ! F_520 ( F_561 ( V_519 ) ) ) {
F_215 ( V_449 L_3 ) ;
F_215 ( V_374 L_43 ) ;
break;
}
if ( F_522 ( V_517 , F_561 ( V_519 ) ) ) {
F_215 ( V_449 L_3 ) ;
F_215 ( V_374 L_44 ) ;
break;
}
F_562 ( V_517 , V_517 , F_561 ( V_519 ) ) ;
F_560 ( V_514 , sizeof( V_514 ) , F_561 ( V_519 ) ) ;
F_215 ( V_449 L_45 , V_514 ) ;
if ( V_519 -> V_523 -> V_524 != V_525 ) {
F_215 ( V_449 L_46 ,
V_519 -> V_523 -> V_524 ) ;
}
V_519 = V_519 -> V_69 ;
} while ( V_519 != V_102 -> V_520 );
F_215 ( V_449 L_3 ) ;
if ( ! F_521 ( F_223 ( V_102 ) , V_517 ) )
F_215 ( V_374 L_47 ) ;
if ( V_102 -> V_42 &&
! F_464 ( V_517 , F_223 ( V_102 -> V_42 ) ) )
F_215 ( V_374 L_48
L_49 ) ;
return 0 ;
}
static void F_563 ( struct V_101 * V_102 , int V_32 )
{
int V_516 = 0 ;
if ( ! V_515 )
return;
if ( ! V_102 ) {
F_215 ( V_521 L_50 , V_32 ) ;
return;
}
F_215 ( V_521 L_51 , V_32 ) ;
for (; ; ) {
if ( F_559 ( V_102 , V_32 , V_516 , V_526 ) )
break;
V_516 ++ ;
V_102 = V_102 -> V_42 ;
if ( ! V_102 )
break;
}
}
static int F_564 ( struct V_101 * V_102 )
{
if ( F_520 ( F_223 ( V_102 ) ) == 1 )
return 1 ;
if ( V_102 -> V_75 & ( V_522 |
V_527 |
V_272 |
V_329 |
V_528 |
V_529 ) ) {
if ( V_102 -> V_520 != V_102 -> V_520 -> V_69 )
return 0 ;
}
if ( V_102 -> V_75 & ( V_530 ) )
return 0 ;
return 1 ;
}
static int
F_565 ( struct V_101 * V_102 , struct V_101 * V_42 )
{
unsigned long V_531 = V_102 -> V_75 , V_532 = V_42 -> V_75 ;
if ( F_564 ( V_42 ) )
return 1 ;
if ( ! F_521 ( F_223 ( V_102 ) , F_223 ( V_42 ) ) )
return 0 ;
if ( V_42 -> V_520 == V_42 -> V_520 -> V_69 ) {
V_532 &= ~ ( V_522 |
V_527 |
V_272 |
V_329 |
V_528 |
V_529 ) ;
if ( V_533 == 1 )
V_532 &= ~ V_534 ;
}
if ( ~ V_531 & V_532 )
return 0 ;
return 1 ;
}
static void F_566 ( struct V_535 * V_536 )
{
struct V_537 * V_500 = F_5 ( V_536 , struct V_537 , V_536 ) ;
F_567 ( & V_500 -> V_538 ) ;
F_466 ( V_500 -> V_539 ) ;
F_466 ( V_500 -> V_499 ) ;
F_466 ( V_500 -> V_506 ) ;
F_534 ( V_500 ) ;
}
static void F_568 ( struct V_31 * V_31 , struct V_537 * V_500 )
{
struct V_537 * V_540 = NULL ;
unsigned long V_75 ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_500 ) {
V_540 = V_31 -> V_500 ;
if ( F_211 ( V_31 -> V_32 , V_540 -> V_499 ) )
F_547 ( V_31 ) ;
F_548 ( V_31 -> V_32 , V_540 -> V_506 ) ;
if ( ! F_569 ( & V_540 -> V_541 ) )
V_540 = NULL ;
}
F_287 ( & V_500 -> V_541 ) ;
V_31 -> V_500 = V_500 ;
F_546 ( V_31 -> V_32 , V_500 -> V_506 ) ;
if ( F_211 ( V_31 -> V_32 , V_217 ) )
F_545 ( V_31 ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
if ( V_540 )
F_570 ( & V_540 -> V_536 , F_566 ) ;
}
static int F_571 ( struct V_537 * V_500 )
{
memset ( V_500 , 0 , sizeof( * V_500 ) ) ;
if ( ! F_459 ( & V_500 -> V_506 , V_432 ) )
goto V_253;
if ( ! F_459 ( & V_500 -> V_499 , V_432 ) )
goto V_542;
if ( ! F_459 ( & V_500 -> V_539 , V_432 ) )
goto V_543;
if ( F_572 ( & V_500 -> V_538 ) != 0 )
goto V_544;
return 0 ;
V_544:
F_466 ( V_500 -> V_539 ) ;
V_543:
F_466 ( V_500 -> V_499 ) ;
V_542:
F_466 ( V_500 -> V_506 ) ;
V_253:
return - V_433 ;
}
static void F_573 ( void )
{
F_571 ( & V_545 ) ;
F_574 ( & V_545 . V_541 , 1 ) ;
}
static struct V_537 * F_575 ( void )
{
struct V_537 * V_500 ;
V_500 = F_576 ( sizeof( * V_500 ) , V_432 ) ;
if ( ! V_500 )
return NULL ;
if ( F_571 ( V_500 ) != 0 ) {
F_534 ( V_500 ) ;
return NULL ;
}
return V_500 ;
}
static void F_577 ( struct V_518 * V_546 , int V_547 )
{
struct V_518 * V_113 , * V_548 ;
if ( ! V_546 )
return;
V_548 = V_546 ;
do {
V_113 = V_546 -> V_69 ;
if ( V_547 && F_569 ( & V_546 -> V_523 -> V_549 ) )
F_534 ( V_546 -> V_523 ) ;
F_534 ( V_546 ) ;
V_546 = V_113 ;
} while ( V_546 != V_548 );
}
static void F_578 ( struct V_535 * V_536 )
{
struct V_101 * V_102 = F_5 ( V_536 , struct V_101 , V_536 ) ;
if ( V_102 -> V_75 & V_550 ) {
F_577 ( V_102 -> V_520 , 1 ) ;
} else if ( F_569 ( & V_102 -> V_520 -> V_549 ) ) {
F_534 ( V_102 -> V_520 -> V_523 ) ;
F_534 ( V_102 -> V_520 ) ;
}
F_534 ( V_102 ) ;
}
static void F_579 ( struct V_101 * V_102 , int V_32 )
{
F_580 ( & V_102 -> V_536 , F_578 ) ;
}
static void F_581 ( struct V_101 * V_102 , int V_32 )
{
for (; V_102 ; V_102 = V_102 -> V_42 )
F_579 ( V_102 , V_32 ) ;
}
static void
F_582 ( struct V_101 * V_102 , struct V_537 * V_500 , int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
struct V_101 * V_113 ;
for ( V_113 = V_102 ; V_113 ; ) {
struct V_101 * V_42 = V_113 -> V_42 ;
if ( ! V_42 )
break;
if ( F_565 ( V_113 , V_42 ) ) {
V_113 -> V_42 = V_42 -> V_42 ;
if ( V_42 -> V_42 )
V_42 -> V_42 -> V_132 = V_113 ;
F_579 ( V_42 , V_32 ) ;
} else
V_113 = V_113 -> V_42 ;
}
if ( V_102 && F_564 ( V_102 ) ) {
V_113 = V_102 ;
V_102 = V_102 -> V_42 ;
F_579 ( V_113 , V_32 ) ;
if ( V_102 )
V_102 -> V_132 = NULL ;
}
F_563 ( V_102 , V_32 ) ;
F_568 ( V_31 , V_500 ) ;
V_113 = V_31 -> V_102 ;
F_583 ( V_31 -> V_102 , V_102 ) ;
F_581 ( V_113 , V_32 ) ;
}
static int T_8 F_584 ( char * V_514 )
{
F_585 ( & V_551 ) ;
F_586 ( V_514 , V_551 ) ;
return 1 ;
}
static int F_587 ( int V_278 , T_25 * V_552 )
{
int V_50 , V_301 , V_127 , V_553 , V_554 = - 1 ;
V_553 = V_555 ;
for ( V_50 = 0 ; V_50 < V_533 ; V_50 ++ ) {
V_301 = ( V_278 + V_50 ) % V_533 ;
if ( ! F_588 ( V_301 ) )
continue;
if ( F_589 ( V_301 , * V_552 ) )
continue;
V_127 = F_590 ( V_278 , V_301 ) ;
if ( V_127 < V_553 ) {
V_553 = V_127 ;
V_554 = V_301 ;
}
}
if ( V_554 != - 1 )
F_591 ( V_554 , * V_552 ) ;
return V_554 ;
}
static void F_592 ( int V_278 , struct V_214 * V_506 )
{
T_25 V_552 ;
int V_50 ;
F_469 ( V_506 ) ;
F_593 ( V_552 ) ;
F_562 ( V_506 , V_506 , F_208 ( V_278 ) ) ;
F_591 ( V_278 , V_552 ) ;
for ( V_50 = 1 ; V_50 < V_556 ; V_50 ++ ) {
int V_557 = F_587 ( V_278 , & V_552 ) ;
if ( V_557 < 0 )
break;
F_562 ( V_506 , V_506 , F_208 ( V_557 ) ) ;
}
}
static const struct V_214 * F_594 ( int V_32 )
{
F_63 ( & V_558 ) ;
F_592 ( F_209 ( V_32 ) , V_526 ) ;
return V_526 ;
}
static const struct V_214 * F_595 ( int V_32 )
{
return V_559 ;
}
static const struct V_214 * F_596 ( int V_32 )
{
return F_208 ( F_209 ( V_32 ) ) ;
}
static int
F_597 ( struct V_101 * V_102 , int V_32 )
{
struct V_518 * V_548 = NULL , * V_192 = NULL , * V_520 = NULL , * V_546 ;
const struct V_214 * V_506 = F_223 ( V_102 ) ;
struct V_214 * V_560 = V_526 ;
struct V_561 * V_562 = V_102 -> V_392 ;
struct V_101 * V_132 ;
int V_50 ;
F_469 ( V_560 ) ;
F_104 (i, span) {
struct V_214 * V_563 ;
if ( F_211 ( V_50 , V_560 ) )
continue;
V_546 = F_598 ( sizeof( struct V_518 ) + F_468 () ,
V_432 , F_209 ( V_50 ) ) ;
if ( ! V_546 )
goto V_386;
V_563 = F_561 ( V_546 ) ;
V_132 = * F_599 ( V_562 -> V_102 , V_50 ) ;
if ( V_132 -> V_132 ) {
V_132 = V_132 -> V_132 ;
F_465 ( V_563 , F_223 ( V_132 ) ) ;
} else
F_546 ( V_50 , V_563 ) ;
F_562 ( V_560 , V_560 , V_563 ) ;
V_546 -> V_523 = * F_599 ( V_562 -> V_523 , F_600 ( V_563 ) ) ;
F_287 ( & V_546 -> V_523 -> V_549 ) ;
if ( F_211 ( V_32 , V_563 ) )
V_520 = V_546 ;
if ( ! V_548 )
V_548 = V_546 ;
if ( V_192 )
V_192 -> V_69 = V_546 ;
V_192 = V_546 ;
V_192 -> V_69 = V_548 ;
}
V_102 -> V_520 = V_520 ;
return 0 ;
V_386:
F_577 ( V_548 , 0 ) ;
return - V_433 ;
}
static int F_601 ( int V_32 , struct V_561 * V_562 , struct V_518 * * V_546 )
{
struct V_101 * V_102 = * F_599 ( V_562 -> V_102 , V_32 ) ;
struct V_101 * V_132 = V_102 -> V_132 ;
if ( V_132 )
V_32 = F_600 ( F_223 ( V_132 ) ) ;
if ( V_546 ) {
* V_546 = * F_599 ( V_562 -> V_546 , V_32 ) ;
( * V_546 ) -> V_523 = * F_599 ( V_562 -> V_523 , V_32 ) ;
F_574 ( & ( * V_546 ) -> V_523 -> V_549 , 1 ) ;
}
return V_32 ;
}
static int
F_602 ( struct V_101 * V_102 , int V_32 )
{
struct V_518 * V_548 = NULL , * V_192 = NULL ;
struct V_561 * V_562 = V_102 -> V_392 ;
const struct V_214 * V_506 = F_223 ( V_102 ) ;
struct V_214 * V_560 ;
int V_50 ;
F_601 ( V_32 , V_562 , & V_102 -> V_520 ) ;
F_287 ( & V_102 -> V_520 -> V_549 ) ;
if ( V_32 != F_600 ( F_223 ( V_102 ) ) )
return 0 ;
F_63 ( & V_558 ) ;
V_560 = V_526 ;
F_469 ( V_560 ) ;
F_104 (i, span) {
struct V_518 * V_546 ;
int V_519 = F_601 ( V_50 , V_562 , & V_546 ) ;
int V_316 ;
if ( F_211 ( V_50 , V_560 ) )
continue;
F_469 ( F_561 ( V_546 ) ) ;
V_546 -> V_523 -> V_524 = 0 ;
F_104 (j, span) {
if ( F_601 ( V_316 , V_562 , NULL ) != V_519 )
continue;
F_546 ( V_316 , V_560 ) ;
F_546 ( V_316 , F_561 ( V_546 ) ) ;
}
if ( ! V_548 )
V_548 = V_546 ;
if ( V_192 )
V_192 -> V_69 = V_546 ;
V_192 = V_546 ;
}
V_192 -> V_69 = V_548 ;
return 0 ;
}
static void F_603 ( int V_32 , struct V_101 * V_102 )
{
struct V_518 * V_546 = V_102 -> V_520 ;
F_541 ( ! V_102 || ! V_546 ) ;
do {
V_546 -> V_564 = F_520 ( F_561 ( V_546 ) ) ;
V_546 = V_546 -> V_69 ;
} while ( V_546 != V_102 -> V_520 );
if ( V_32 != F_604 ( V_546 ) )
return;
F_605 ( V_102 , V_32 ) ;
}
static int T_8 F_606 ( char * V_514 )
{
unsigned long V_127 ;
V_127 = F_607 ( V_514 , NULL , 0 ) ;
if ( V_127 < V_565 )
V_566 = V_127 ;
return 1 ;
}
static void F_608 ( struct V_101 * V_102 ,
struct V_567 * V_568 )
{
int V_569 ;
if ( ! V_568 || V_568 -> V_570 < 0 ) {
if ( V_566 < 0 )
return;
else
V_569 = V_566 ;
} else
V_569 = V_568 -> V_570 ;
if ( V_569 < V_102 -> V_516 ) {
V_102 -> V_75 &= ~ ( V_256 | V_527 ) ;
} else {
V_102 -> V_75 |= ( V_256 | V_527 ) ;
}
}
static void F_609 ( struct V_571 * V_572 , enum V_573 V_574 ,
const struct V_214 * V_575 )
{
switch ( V_574 ) {
case V_576 :
if ( ! F_297 ( & V_572 -> V_500 -> V_541 ) )
F_566 ( & V_572 -> V_500 -> V_536 ) ;
case V_577 :
F_610 ( V_572 -> V_102 ) ;
case V_578 :
F_611 ( V_575 ) ;
case V_579 :
break;
}
}
static enum V_573 F_612 ( struct V_571 * V_572 ,
const struct V_214 * V_575 )
{
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
if ( F_613 ( V_575 ) )
return V_578 ;
V_572 -> V_102 = F_614 ( struct V_101 * ) ;
if ( ! V_572 -> V_102 )
return V_578 ;
V_572 -> V_500 = F_575 () ;
if ( ! V_572 -> V_500 )
return V_577 ;
return V_576 ;
}
static void F_615 ( int V_32 , struct V_101 * V_102 )
{
struct V_561 * V_562 = V_102 -> V_392 ;
F_79 ( * F_599 ( V_562 -> V_102 , V_32 ) != V_102 ) ;
* F_599 ( V_562 -> V_102 , V_32 ) = NULL ;
if ( F_297 ( & ( * F_599 ( V_562 -> V_546 , V_32 ) ) -> V_549 ) )
* F_599 ( V_562 -> V_546 , V_32 ) = NULL ;
if ( F_297 ( & ( * F_599 ( V_562 -> V_523 , V_32 ) ) -> V_549 ) )
* F_599 ( V_562 -> V_523 , V_32 ) = NULL ;
}
static const struct V_214 * F_616 ( int V_32 )
{
return F_617 ( V_32 ) ;
}
static int F_613 ( const struct V_214 * V_575 )
{
struct V_580 * V_581 ;
int V_316 ;
for ( V_581 = V_582 ; V_581 -> V_583 ; V_581 ++ ) {
struct V_561 * V_562 = & V_581 -> V_131 ;
V_562 -> V_102 = F_614 ( struct V_101 * ) ;
if ( ! V_562 -> V_102 )
return - V_433 ;
V_562 -> V_546 = F_614 ( struct V_518 * ) ;
if ( ! V_562 -> V_546 )
return - V_433 ;
V_562 -> V_523 = F_614 ( struct V_584 * ) ;
if ( ! V_562 -> V_523 )
return - V_433 ;
F_104 (j, cpu_map) {
struct V_101 * V_102 ;
struct V_518 * V_546 ;
struct V_584 * V_523 ;
V_102 = F_598 ( sizeof( struct V_101 ) + F_468 () ,
V_432 , F_209 ( V_316 ) ) ;
if ( ! V_102 )
return - V_433 ;
* F_599 ( V_562 -> V_102 , V_316 ) = V_102 ;
V_546 = F_598 ( sizeof( struct V_518 ) + F_468 () ,
V_432 , F_209 ( V_316 ) ) ;
if ( ! V_546 )
return - V_433 ;
* F_599 ( V_562 -> V_546 , V_316 ) = V_546 ;
V_523 = F_598 ( sizeof( struct V_584 ) ,
V_432 , F_209 ( V_316 ) ) ;
if ( ! V_523 )
return - V_433 ;
* F_599 ( V_562 -> V_523 , V_316 ) = V_523 ;
}
}
return 0 ;
}
static void F_611 ( const struct V_214 * V_575 )
{
struct V_580 * V_581 ;
int V_316 ;
for ( V_581 = V_582 ; V_581 -> V_583 ; V_581 ++ ) {
struct V_561 * V_562 = & V_581 -> V_131 ;
F_104 (j, cpu_map) {
struct V_101 * V_102 = * F_599 ( V_562 -> V_102 , V_316 ) ;
if ( V_102 && ( V_102 -> V_75 & V_550 ) )
F_577 ( V_102 -> V_520 , 0 ) ;
F_534 ( * F_599 ( V_562 -> V_546 , V_316 ) ) ;
F_534 ( * F_599 ( V_562 -> V_523 , V_316 ) ) ;
}
F_610 ( V_562 -> V_102 ) ;
F_610 ( V_562 -> V_546 ) ;
F_610 ( V_562 -> V_523 ) ;
}
}
struct V_101 * F_618 ( struct V_580 * V_581 ,
struct V_571 * V_572 , const struct V_214 * V_575 ,
struct V_567 * V_568 , struct V_101 * V_132 ,
int V_32 )
{
struct V_101 * V_102 = V_581 -> V_583 ( V_581 , V_32 ) ;
if ( ! V_102 )
return V_132 ;
F_608 ( V_102 , V_568 ) ;
F_462 ( F_223 ( V_102 ) , V_575 , V_581 -> V_439 ( V_32 ) ) ;
if ( V_132 ) {
V_102 -> V_516 = V_132 -> V_516 + 1 ;
V_565 = F_128 ( V_565 , V_102 -> V_516 ) ;
V_132 -> V_42 = V_102 ;
}
V_102 -> V_132 = V_132 ;
return V_102 ;
}
static int F_619 ( const struct V_214 * V_575 ,
struct V_567 * V_568 )
{
enum V_573 V_585 = V_579 ;
struct V_101 * V_102 ;
struct V_571 V_572 ;
int V_50 , V_133 = - V_433 ;
V_585 = F_612 ( & V_572 , V_575 ) ;
if ( V_585 != V_576 )
goto error;
F_104 (i, cpu_map) {
struct V_580 * V_581 ;
V_102 = NULL ;
for ( V_581 = V_582 ; V_581 -> V_583 ; V_581 ++ ) {
V_102 = F_618 ( V_581 , & V_572 , V_575 , V_568 , V_102 , V_50 ) ;
if ( V_581 -> V_75 & V_586 || F_74 ( V_587 ) )
V_102 -> V_75 |= V_550 ;
if ( F_521 ( V_575 , F_223 ( V_102 ) ) )
break;
}
while ( V_102 -> V_132 )
V_102 = V_102 -> V_132 ;
* F_599 ( V_572 . V_102 , V_50 ) = V_102 ;
}
F_104 (i, cpu_map) {
for ( V_102 = * F_599 ( V_572 . V_102 , V_50 ) ; V_102 ; V_102 = V_102 -> V_42 ) {
V_102 -> V_588 = F_520 ( F_223 ( V_102 ) ) ;
if ( V_102 -> V_75 & V_550 ) {
if ( F_597 ( V_102 , V_50 ) )
goto error;
} else {
if ( F_602 ( V_102 , V_50 ) )
goto error;
}
}
}
for ( V_50 = V_589 - 1 ; V_50 >= 0 ; V_50 -- ) {
if ( ! F_211 ( V_50 , V_575 ) )
continue;
for ( V_102 = * F_599 ( V_572 . V_102 , V_50 ) ; V_102 ; V_102 = V_102 -> V_42 ) {
F_615 ( V_50 , V_102 ) ;
F_603 ( V_50 , V_102 ) ;
}
}
F_102 () ;
F_104 (i, cpu_map) {
V_102 = * F_599 ( V_572 . V_102 , V_50 ) ;
F_582 ( V_102 , V_572 . V_500 , V_50 ) ;
}
F_106 () ;
V_133 = 0 ;
error:
F_609 ( & V_572 , V_585 , V_575 ) ;
return V_133 ;
}
T_20 * F_620 ( unsigned int V_590 )
{
int V_50 ;
T_20 * V_591 ;
V_591 = F_576 ( sizeof( * V_591 ) * V_590 , V_432 ) ;
if ( ! V_591 )
return NULL ;
for ( V_50 = 0 ; V_50 < V_590 ; V_50 ++ ) {
if ( ! F_459 ( & V_591 [ V_50 ] , V_432 ) ) {
F_621 ( V_591 , V_50 ) ;
return NULL ;
}
}
return V_591 ;
}
void F_621 ( T_20 V_591 [] , unsigned int V_590 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_590 ; V_50 ++ )
F_466 ( V_591 [ V_50 ] ) ;
F_534 ( V_591 ) ;
}
static int F_622 ( const struct V_214 * V_575 )
{
int V_509 ;
F_623 () ;
V_592 = 1 ;
V_593 = F_620 ( V_592 ) ;
if ( ! V_593 )
V_593 = & V_594 ;
F_624 ( V_593 [ 0 ] , V_575 , V_551 ) ;
V_595 = NULL ;
V_509 = F_619 ( V_593 [ 0 ] , NULL ) ;
F_539 () ;
return V_509 ;
}
static void F_625 ( const struct V_214 * V_575 )
{
int V_50 ;
F_102 () ;
F_104 (i, cpu_map)
F_582 ( NULL , & V_545 , V_50 ) ;
F_106 () ;
}
static int F_626 ( struct V_567 * V_596 , int V_597 ,
struct V_567 * V_598 , int V_599 )
{
struct V_567 V_113 ;
if ( ! V_598 && ! V_596 )
return 1 ;
V_113 = V_600 ;
return ! memcmp ( V_596 ? ( V_596 + V_597 ) : & V_113 ,
V_598 ? ( V_598 + V_599 ) : & V_113 ,
sizeof( struct V_567 ) ) ;
}
void F_627 ( int V_601 , T_20 V_602 [] ,
struct V_567 * V_603 )
{
int V_50 , V_316 , V_301 ;
int V_604 ;
F_628 ( & V_558 ) ;
F_543 () ;
V_604 = F_623 () ;
V_301 = V_602 ? V_601 : 0 ;
for ( V_50 = 0 ; V_50 < V_592 ; V_50 ++ ) {
for ( V_316 = 0 ; V_316 < V_301 && ! V_604 ; V_316 ++ ) {
if ( F_521 ( V_593 [ V_50 ] , V_602 [ V_316 ] )
&& F_626 ( V_595 , V_50 , V_603 , V_316 ) )
goto V_605;
}
F_625 ( V_593 [ V_50 ] ) ;
V_605:
;
}
if ( V_602 == NULL ) {
V_592 = 0 ;
V_602 = & V_594 ;
F_624 ( V_602 [ 0 ] , V_217 , V_551 ) ;
F_79 ( V_603 ) ;
}
for ( V_50 = 0 ; V_50 < V_601 ; V_50 ++ ) {
for ( V_316 = 0 ; V_316 < V_592 && ! V_604 ; V_316 ++ ) {
if ( F_521 ( V_602 [ V_50 ] , V_593 [ V_316 ] )
&& F_626 ( V_603 , V_50 , V_595 , V_316 ) )
goto V_606;
}
F_619 ( V_602 [ V_50 ] , V_603 ? V_603 + V_50 : NULL ) ;
V_606:
;
}
if ( V_593 != & V_594 )
F_621 ( V_593 , V_592 ) ;
F_534 ( V_595 ) ;
V_593 = V_602 ;
V_595 = V_603 ;
V_592 = V_601 ;
F_539 () ;
F_629 ( & V_558 ) ;
}
static void F_630 ( void )
{
F_456 () ;
F_627 ( 0 , NULL , NULL ) ;
F_631 () ;
F_457 () ;
}
static T_4 F_632 ( const char * V_58 , T_6 V_607 , int V_608 )
{
unsigned int V_516 = 0 ;
if ( sscanf ( V_58 , L_52 , & V_516 ) != 1 )
return - V_62 ;
if ( V_516 >= V_609 )
return - V_62 ;
if ( V_608 )
V_610 = V_516 ;
else
V_611 = V_516 ;
F_630 () ;
return V_607 ;
}
static T_4 F_633 ( struct V_612 * V_188 ,
struct V_613 * V_568 ,
char * V_614 )
{
return sprintf ( V_614 , L_53 , V_611 ) ;
}
static T_4 F_634 ( struct V_612 * V_188 ,
struct V_613 * V_568 ,
const char * V_58 , T_6 V_607 )
{
return F_632 ( V_58 , V_607 , 0 ) ;
}
static T_4 F_635 ( struct V_612 * V_615 ,
struct V_613 * V_568 ,
char * V_614 )
{
return sprintf ( V_614 , L_53 , V_610 ) ;
}
static T_4 F_636 ( struct V_612 * V_615 ,
struct V_613 * V_568 ,
const char * V_58 , T_6 V_607 )
{
return F_632 ( V_58 , V_607 , 1 ) ;
}
int T_8 F_637 ( struct V_612 * V_616 )
{
int V_509 = 0 ;
#ifdef F_638
if ( F_639 () )
V_509 = F_640 ( & V_616 -> V_617 . V_618 ,
& V_619 . V_568 ) ;
#endif
#ifdef F_641
if ( ! V_509 && F_642 () )
V_509 = F_640 ( & V_616 -> V_617 . V_618 ,
& V_620 . V_568 ) ;
#endif
return V_509 ;
}
static int F_643 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
switch ( V_88 & ~ V_503 ) {
case V_505 :
case V_508 :
F_644 () ;
return V_96 ;
default:
return V_97 ;
}
}
static int F_645 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
switch ( V_88 & ~ V_503 ) {
case V_92 :
F_644 () ;
return V_96 ;
default:
return V_97 ;
}
}
static int F_646 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
int V_32 = ( int ) ( long ) V_89 ;
switch ( V_88 ) {
case V_92 :
case V_93 :
F_647 ( F_39 ( V_32 ) ) ;
return V_96 ;
case V_508 :
case V_621 :
case V_505 :
case V_622 :
F_648 ( F_39 ( V_32 ) ) ;
return V_96 ;
default:
return V_97 ;
}
}
void T_8 F_649 ( void )
{
T_20 V_623 ;
F_459 ( & V_623 , V_432 ) ;
F_459 ( & V_594 , V_432 ) ;
F_456 () ;
F_628 ( & V_558 ) ;
F_622 ( V_217 ) ;
F_624 ( V_623 , V_559 , V_551 ) ;
if ( F_650 ( V_623 ) )
F_546 ( F_80 () , V_623 ) ;
F_629 ( & V_558 ) ;
F_457 () ;
F_88 ( F_643 , V_624 ) ;
F_88 ( F_645 , V_625 ) ;
F_88 ( F_646 , 0 ) ;
F_87 () ;
if ( F_463 ( V_72 , V_623 ) < 0 )
F_375 () ;
F_519 () ;
F_466 ( V_623 ) ;
F_651 () ;
}
void T_8 F_649 ( void )
{
F_519 () ;
}
int F_652 ( unsigned long V_366 )
{
return F_355 ( V_366 ) ||
( V_366 >= ( unsigned long ) V_626
&& V_366 < ( unsigned long ) V_627 ) ;
}
static void F_653 ( struct V_41 * V_41 , struct V_31 * V_31 )
{
V_41 -> V_628 = V_629 ;
F_247 ( & V_41 -> V_630 ) ;
#ifdef F_32
V_41 -> V_31 = V_31 ;
#ifdef F_26
V_41 -> V_631 = 1 ;
#endif
#endif
V_41 -> V_632 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_654
V_41 -> V_633 = V_41 -> V_632 ;
#endif
}
static void F_655 ( struct V_44 * V_44 , struct V_31 * V_31 )
{
struct V_634 * V_635 ;
int V_50 ;
V_635 = & V_44 -> V_295 ;
for ( V_50 = 0 ; V_50 < V_150 ; V_50 ++ ) {
F_247 ( V_635 -> V_636 + V_50 ) ;
F_656 ( V_50 , V_635 -> V_637 ) ;
}
F_657 ( V_150 , V_635 -> V_637 ) ;
#if F_240 F_26 || F_240 F_33
V_44 -> V_638 . V_67 = V_150 ;
#ifdef F_26
V_44 -> V_638 . V_69 = V_150 ;
#endif
#endif
#ifdef F_26
V_44 -> V_639 = 0 ;
V_44 -> V_640 = 0 ;
F_658 ( & V_44 -> V_270 , & V_31 -> V_39 ) ;
#endif
V_44 -> V_641 = 0 ;
V_44 -> V_642 = 0 ;
V_44 -> V_20 = 0 ;
F_11 ( & V_44 -> V_21 ) ;
#ifdef F_33
V_44 -> V_643 = 0 ;
V_44 -> V_31 = V_31 ;
#endif
}
static void F_659 ( struct V_33 * V_34 , struct V_41 * V_41 ,
struct V_644 * V_40 , int V_32 ,
struct V_644 * V_42 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
V_34 -> V_41 [ V_32 ] = V_41 ;
F_653 ( V_41 , V_31 ) ;
V_41 -> V_34 = V_34 ;
V_34 -> V_40 [ V_32 ] = V_40 ;
if ( ! V_40 )
return;
if ( ! V_42 )
V_40 -> V_41 = & V_31 -> V_379 ;
else
V_40 -> V_41 = V_42 -> V_645 ;
V_40 -> V_645 = V_41 ;
F_117 ( & V_40 -> V_128 , 0 ) ;
V_40 -> V_42 = V_42 ;
}
static void F_660 ( struct V_33 * V_34 , struct V_44 * V_44 ,
struct V_646 * V_45 , int V_32 ,
struct V_646 * V_42 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
V_34 -> V_44 [ V_32 ] = V_44 ;
F_655 ( V_44 , V_31 ) ;
V_44 -> V_34 = V_34 ;
V_44 -> V_20 = V_34 -> V_9 . V_20 ;
V_34 -> V_45 [ V_32 ] = V_45 ;
if ( ! V_45 )
return;
if ( ! V_42 )
V_45 -> V_44 = & V_31 -> V_43 ;
else
V_45 -> V_44 = V_42 -> V_645 ;
V_45 -> V_645 = V_44 ;
V_45 -> V_42 = V_42 ;
F_247 ( & V_45 -> V_263 ) ;
}
void T_8 F_661 ( void )
{
int V_50 , V_316 ;
unsigned long V_647 = 0 , V_648 ;
#ifdef F_32
V_647 += 2 * V_218 * sizeof( void * * ) ;
#endif
#ifdef F_33
V_647 += 2 * V_218 * sizeof( void * * ) ;
#endif
#ifdef F_662
V_647 += F_540 () * F_468 () ;
#endif
if ( V_647 ) {
V_648 = ( unsigned long ) F_663 ( V_647 , V_649 ) ;
#ifdef F_32
V_134 . V_40 = (struct V_644 * * ) V_648 ;
V_648 += V_218 * sizeof( void * * ) ;
V_134 . V_41 = (struct V_41 * * ) V_648 ;
V_648 += V_218 * sizeof( void * * ) ;
#endif
#ifdef F_33
V_134 . V_45 = (struct V_646 * * ) V_648 ;
V_648 += V_218 * sizeof( void * * ) ;
V_134 . V_44 = (struct V_44 * * ) V_648 ;
V_648 += V_218 * sizeof( void * * ) ;
#endif
#ifdef F_662
F_294 (i) {
F_166 ( V_650 , V_50 ) = ( void * ) V_648 ;
V_648 += F_468 () ;
}
#endif
}
#ifdef F_26
F_573 () ;
#endif
F_9 ( & V_651 ,
F_50 () , F_51 () ) ;
#ifdef F_33
F_9 ( & V_134 . V_9 ,
F_50 () , F_51 () ) ;
#endif
#ifdef F_664
F_665 ( & V_134 . V_247 , & V_652 ) ;
F_247 ( & V_134 . V_653 ) ;
F_666 ( & V_654 ) ;
#endif
F_294 (i) {
struct V_31 * V_31 ;
V_31 = F_39 ( V_50 ) ;
F_11 ( & V_31 -> V_39 ) ;
V_31 -> V_140 = 0 ;
V_31 -> V_294 = 0 ;
V_31 -> V_305 = V_304 + V_307 ;
F_653 ( & V_31 -> V_379 , V_31 ) ;
F_655 ( & V_31 -> V_43 , V_31 ) ;
#ifdef F_32
V_134 . V_655 = V_656 ;
F_247 ( & V_31 -> V_657 ) ;
F_659 ( & V_134 , & V_31 -> V_379 , NULL , V_50 , NULL ) ;
#endif
V_31 -> V_43 . V_20 = V_651 . V_20 ;
#ifdef F_33
F_247 ( & V_31 -> V_658 ) ;
F_660 ( & V_134 , & V_31 -> V_43 , NULL , V_50 , NULL ) ;
#endif
for ( V_316 = 0 ; V_316 < V_326 ; V_316 ++ )
V_31 -> V_138 [ V_316 ] = 0 ;
V_31 -> V_325 = V_304 ;
#ifdef F_26
V_31 -> V_102 = NULL ;
V_31 -> V_500 = NULL ;
V_31 -> V_139 = V_525 ;
V_31 -> F_280 = 0 ;
V_31 -> V_659 = 0 ;
V_31 -> V_660 = V_304 ;
V_31 -> V_661 = 0 ;
V_31 -> V_32 = V_50 ;
V_31 -> V_499 = 0 ;
V_31 -> V_242 = 0 ;
V_31 -> V_243 = 2 * V_193 ;
F_568 ( V_31 , & V_545 ) ;
#ifdef F_667
V_31 -> V_662 = 0 ;
F_668 ( & F_166 ( V_663 , V_50 ) ) ;
#endif
#endif
F_89 ( V_31 ) ;
F_574 ( & V_31 -> F_296 , 0 ) ;
}
F_150 ( & V_654 ) ;
#ifdef F_248
F_249 ( & V_654 . V_264 ) ;
#endif
#ifdef F_26
F_669 ( V_664 , V_665 ) ;
#endif
#ifdef F_670
F_658 ( & V_654 . V_666 , & V_654 . V_38 ) ;
#endif
F_287 ( & V_471 . V_289 ) ;
F_288 ( & V_471 , V_72 ) ;
F_508 ( V_72 , F_80 () ) ;
V_305 = V_304 + V_307 ;
V_72 -> V_78 = & V_190 ;
F_671 ( & V_667 , V_649 ) ;
#ifdef F_26
F_671 ( & V_526 , V_649 ) ;
#ifdef F_667
F_671 ( & V_668 . V_669 , V_649 ) ;
F_459 ( & V_668 . V_670 , V_649 ) ;
F_574 ( & V_668 . V_671 , V_218 ) ;
F_574 ( & V_668 . V_672 , V_218 ) ;
F_574 ( & V_668 . V_673 , V_218 ) ;
#endif
if ( V_551 == NULL )
F_671 ( & V_551 , V_649 ) ;
#endif
V_674 = 1 ;
}
static inline int F_672 ( int V_675 )
{
int V_676 = ( V_199 () & ~ V_200 ) + F_673 () ;
return ( V_676 == V_675 ) ;
}
void F_674 ( const char * V_53 , int line , int V_675 )
{
#ifdef F_675
static unsigned long V_677 ;
if ( ( F_672 ( V_675 ) && ! F_139 () ) ||
V_678 != V_679 || V_680 )
return;
if ( F_310 ( V_304 , V_677 + V_211 ) && V_677 )
return;
V_677 = V_304 ;
F_215 ( V_374
L_54 ,
V_53 , line ) ;
F_215 ( V_374
L_55 ,
F_675 () , F_139 () ,
V_72 -> V_375 , V_72 -> V_221 ) ;
F_364 ( V_72 ) ;
if ( F_139 () )
F_366 ( V_72 ) ;
F_368 () ;
#endif
}
static void F_676 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
const struct V_78 * V_183 = V_5 -> V_78 ;
int V_408 = V_5 -> V_148 ;
int V_189 ;
V_189 = V_5 -> V_189 ;
if ( V_189 )
F_158 ( V_31 , V_5 , 0 ) ;
F_443 ( V_31 , V_5 , V_266 , 0 ) ;
if ( V_189 ) {
F_156 ( V_31 , V_5 , 0 ) ;
F_90 ( V_31 -> V_67 ) ;
}
F_188 ( V_31 , V_5 , V_183 , V_408 ) ;
}
void F_677 ( void )
{
struct V_4 * V_452 , * V_5 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
F_678 ( & V_453 , V_75 ) ;
F_500 (g, p) {
if ( ! V_5 -> V_219 )
continue;
V_5 -> V_40 . V_194 = 0 ;
#ifdef F_221
V_5 -> V_40 . V_229 . V_681 = 0 ;
V_5 -> V_40 . V_229 . V_682 = 0 ;
V_5 -> V_40 . V_229 . V_683 = 0 ;
#endif
if ( ! F_679 ( V_5 ) ) {
if ( F_328 ( V_5 ) < 0 && V_5 -> V_219 )
F_434 ( V_5 , 0 ) ;
continue;
}
F_16 ( & V_5 -> V_38 ) ;
V_31 = F_62 ( V_5 ) ;
F_676 ( V_31 , V_5 ) ;
F_68 ( V_31 ) ;
F_22 ( & V_5 -> V_38 ) ;
} F_502 ( V_452 , V_5 ) ;
F_680 ( & V_453 , V_75 ) ;
}
struct V_4 * F_681 ( int V_32 )
{
return F_100 ( V_32 ) ;
}
void V_406 ( int V_32 , struct V_4 * V_5 )
{
F_100 ( V_32 ) = V_5 ;
}
static void F_682 ( struct V_33 * V_34 )
{
int V_50 ;
F_294 (i) {
if ( V_34 -> V_41 )
F_534 ( V_34 -> V_41 [ V_50 ] ) ;
if ( V_34 -> V_40 )
F_534 ( V_34 -> V_40 [ V_50 ] ) ;
}
F_534 ( V_34 -> V_41 ) ;
F_534 ( V_34 -> V_40 ) ;
}
static
int F_683 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
struct V_41 * V_41 ;
struct V_644 * V_40 ;
int V_50 ;
V_34 -> V_41 = F_663 ( sizeof( V_41 ) * V_218 , V_432 ) ;
if ( ! V_34 -> V_41 )
goto V_509;
V_34 -> V_40 = F_663 ( sizeof( V_40 ) * V_218 , V_432 ) ;
if ( ! V_34 -> V_40 )
goto V_509;
V_34 -> V_655 = V_684 ;
F_294 (i) {
V_41 = F_598 ( sizeof( struct V_41 ) ,
V_432 , F_209 ( V_50 ) ) ;
if ( ! V_41 )
goto V_509;
V_40 = F_598 ( sizeof( struct V_644 ) ,
V_432 , F_209 ( V_50 ) ) ;
if ( ! V_40 )
goto V_685;
F_659 ( V_34 , V_41 , V_40 , V_50 , V_42 -> V_40 [ V_50 ] ) ;
}
return 1 ;
V_685:
F_534 ( V_41 ) ;
V_509:
return 0 ;
}
static inline void F_684 ( struct V_33 * V_34 , int V_32 )
{
struct V_31 * V_31 = F_39 ( V_32 ) ;
unsigned long V_75 ;
if ( ! V_34 -> V_41 [ V_32 ] -> V_686 )
return;
F_66 ( & V_31 -> V_39 , V_75 ) ;
F_685 ( V_34 -> V_41 [ V_32 ] ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
}
static inline void F_682 ( struct V_33 * V_34 )
{
}
static inline
int F_683 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
return 1 ;
}
static inline void F_684 ( struct V_33 * V_34 , int V_32 )
{
}
static void F_686 ( struct V_33 * V_34 )
{
int V_50 ;
F_23 ( & V_34 -> V_9 ) ;
F_294 (i) {
if ( V_34 -> V_44 )
F_534 ( V_34 -> V_44 [ V_50 ] ) ;
if ( V_34 -> V_45 )
F_534 ( V_34 -> V_45 [ V_50 ] ) ;
}
F_534 ( V_34 -> V_44 ) ;
F_534 ( V_34 -> V_45 ) ;
}
static
int F_687 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
struct V_44 * V_44 ;
struct V_646 * V_45 ;
int V_50 ;
V_34 -> V_44 = F_663 ( sizeof( V_44 ) * V_218 , V_432 ) ;
if ( ! V_34 -> V_44 )
goto V_509;
V_34 -> V_45 = F_663 ( sizeof( V_45 ) * V_218 , V_432 ) ;
if ( ! V_34 -> V_45 )
goto V_509;
F_9 ( & V_34 -> V_9 ,
F_19 ( V_651 . V_15 ) , 0 ) ;
F_294 (i) {
V_44 = F_598 ( sizeof( struct V_44 ) ,
V_432 , F_209 ( V_50 ) ) ;
if ( ! V_44 )
goto V_509;
V_45 = F_598 ( sizeof( struct V_646 ) ,
V_432 , F_209 ( V_50 ) ) ;
if ( ! V_45 )
goto V_685;
F_660 ( V_34 , V_44 , V_45 , V_50 , V_42 -> V_45 [ V_50 ] ) ;
}
return 1 ;
V_685:
F_534 ( V_44 ) ;
V_509:
return 0 ;
}
static inline void F_686 ( struct V_33 * V_34 )
{
}
static inline
int F_687 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
return 1 ;
}
static void F_688 ( struct V_33 * V_34 )
{
F_682 ( V_34 ) ;
F_686 ( V_34 ) ;
F_689 ( V_34 ) ;
F_534 ( V_34 ) ;
}
struct V_33 * F_690 ( struct V_33 * V_42 )
{
struct V_33 * V_34 ;
unsigned long V_75 ;
V_34 = F_663 ( sizeof( * V_34 ) , V_432 ) ;
if ( ! V_34 )
return F_691 ( - V_433 ) ;
if ( ! F_683 ( V_34 , V_42 ) )
goto V_509;
if ( ! F_687 ( V_34 , V_42 ) )
goto V_509;
F_398 ( & V_687 , V_75 ) ;
F_692 ( & V_34 -> V_247 , & V_652 ) ;
F_541 ( ! V_42 ) ;
V_34 -> V_42 = V_42 ;
F_247 ( & V_34 -> V_653 ) ;
F_692 ( & V_34 -> V_688 , & V_42 -> V_653 ) ;
F_399 ( & V_687 , V_75 ) ;
return V_34 ;
V_509:
F_688 ( V_34 ) ;
return F_691 ( - V_433 ) ;
}
static void F_693 ( struct V_535 * V_689 )
{
F_688 ( F_5 ( V_689 , struct V_33 , V_536 ) ) ;
}
void F_694 ( struct V_33 * V_34 )
{
unsigned long V_75 ;
int V_50 ;
F_294 (i)
F_684 ( V_34 , V_50 ) ;
F_398 ( & V_687 , V_75 ) ;
F_695 ( & V_34 -> V_247 ) ;
F_695 ( & V_34 -> V_688 ) ;
F_399 ( & V_687 , V_75 ) ;
F_580 ( & V_34 -> V_536 , F_693 ) ;
}
void F_696 ( struct V_4 * V_123 )
{
int V_189 , V_205 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
V_31 = F_65 ( V_123 , & V_75 ) ;
V_205 = F_52 ( V_31 , V_123 ) ;
V_189 = V_123 -> V_189 ;
if ( V_189 )
F_154 ( V_31 , V_123 , 0 ) ;
if ( F_2 ( V_205 ) )
V_123 -> V_78 -> F_373 ( V_31 , V_123 ) ;
#ifdef F_32
if ( V_123 -> V_78 -> V_690 )
V_123 -> V_78 -> V_690 ( V_123 , V_189 ) ;
else
#endif
F_31 ( V_123 , F_94 ( V_123 ) ) ;
if ( F_2 ( V_205 ) )
V_123 -> V_78 -> V_406 ( V_31 ) ;
if ( V_189 )
F_152 ( V_31 , V_123 , 0 ) ;
F_69 ( V_31 , V_123 , & V_75 ) ;
}
int F_697 ( struct V_33 * V_34 , unsigned long V_655 )
{
int V_50 ;
unsigned long V_75 ;
if ( ! V_34 -> V_40 [ 0 ] )
return - V_62 ;
V_655 = F_698 ( V_655 , F_151 ( V_691 ) , F_151 ( V_692 ) ) ;
F_628 ( & V_693 ) ;
if ( V_34 -> V_655 == V_655 )
goto V_398;
V_34 -> V_655 = V_655 ;
F_294 (i) {
struct V_31 * V_31 = F_39 ( V_50 ) ;
struct V_644 * V_40 ;
V_40 = V_34 -> V_40 [ V_50 ] ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
F_699 (se)
F_700 ( F_701 ( V_40 ) ) ;
F_67 ( & V_31 -> V_39 , V_75 ) ;
}
V_398:
F_629 ( & V_693 ) ;
return 0 ;
}
unsigned long F_702 ( struct V_33 * V_34 )
{
return V_34 -> V_655 ;
}
static unsigned long F_703 ( T_2 V_18 , T_2 V_19 )
{
if ( V_19 == V_26 )
return 1ULL << 20 ;
return F_704 ( V_19 << 20 , V_18 ) ;
}
static inline int F_705 ( struct V_33 * V_34 )
{
struct V_4 * V_452 , * V_5 ;
F_500 (g, p) {
if ( F_679 ( V_5 ) && F_706 ( & V_5 -> V_43 ) -> V_34 == V_34 )
return 1 ;
} F_502 ( V_452 , V_5 ) ;
return 0 ;
}
static int F_707 ( struct V_33 * V_34 , void * V_131 )
{
struct V_694 * V_572 = V_131 ;
struct V_33 * V_132 ;
unsigned long V_136 , V_290 = 0 ;
T_2 V_18 , V_19 ;
V_18 = F_19 ( V_34 -> V_9 . V_15 ) ;
V_19 = V_34 -> V_9 . V_20 ;
if ( V_34 == V_572 -> V_34 ) {
V_18 = V_572 -> V_15 ;
V_19 = V_572 -> V_20 ;
}
if ( V_19 > V_18 && V_19 != V_26 )
return - V_62 ;
if ( F_13 () && ! V_19 && F_705 ( V_34 ) )
return - V_695 ;
V_136 = F_703 ( V_18 , V_19 ) ;
if ( V_136 > F_703 ( F_50 () , F_51 () ) )
return - V_62 ;
F_123 (child, &tg->children, siblings) {
V_18 = F_19 ( V_132 -> V_9 . V_15 ) ;
V_19 = V_132 -> V_9 . V_20 ;
if ( V_132 == V_572 -> V_34 ) {
V_18 = V_572 -> V_15 ;
V_19 = V_572 -> V_20 ;
}
V_290 += F_703 ( V_18 , V_19 ) ;
}
if ( V_290 > V_136 )
return - V_62 ;
return 0 ;
}
static int F_708 ( struct V_33 * V_34 , T_2 V_18 , T_2 V_19 )
{
struct V_694 V_131 = {
. V_34 = V_34 ,
. V_15 = V_18 ,
. V_20 = V_19 ,
} ;
return F_122 ( F_707 , F_124 , & V_131 ) ;
}
static int F_709 ( struct V_33 * V_34 ,
T_2 V_15 , T_2 V_20 )
{
int V_50 , V_509 = 0 ;
F_628 ( & V_696 ) ;
F_499 ( & V_453 ) ;
V_509 = F_708 ( V_34 , V_15 , V_20 ) ;
if ( V_509 )
goto V_103;
F_378 ( & V_34 -> V_9 . V_21 ) ;
V_34 -> V_9 . V_15 = F_10 ( V_15 ) ;
V_34 -> V_9 . V_20 = V_20 ;
F_294 (i) {
struct V_44 * V_44 = V_34 -> V_44 [ V_50 ] ;
F_16 ( & V_44 -> V_21 ) ;
V_44 -> V_20 = V_20 ;
F_22 ( & V_44 -> V_21 ) ;
}
F_59 ( & V_34 -> V_9 . V_21 ) ;
V_103:
F_505 ( & V_453 ) ;
F_629 ( & V_696 ) ;
return V_509 ;
}
int F_710 ( struct V_33 * V_34 , long V_697 )
{
T_2 V_20 , V_15 ;
V_15 = F_19 ( V_34 -> V_9 . V_15 ) ;
V_20 = ( T_2 ) V_697 * V_66 ;
if ( V_697 < 0 )
V_20 = V_26 ;
return F_709 ( V_34 , V_15 , V_20 ) ;
}
long F_711 ( struct V_33 * V_34 )
{
T_2 V_697 ;
if ( V_34 -> V_9 . V_20 == V_26 )
return - 1 ;
V_697 = V_34 -> V_9 . V_20 ;
F_348 ( V_697 , V_66 ) ;
return V_697 ;
}
int F_712 ( struct V_33 * V_34 , long V_698 )
{
T_2 V_20 , V_15 ;
V_15 = ( T_2 ) V_698 * V_66 ;
V_20 = V_34 -> V_9 . V_20 ;
if ( V_15 == 0 )
return - V_62 ;
return F_709 ( V_34 , V_15 , V_20 ) ;
}
long F_713 ( struct V_33 * V_34 )
{
T_2 V_698 ;
V_698 = F_19 ( V_34 -> V_9 . V_15 ) ;
F_348 ( V_698 , V_66 ) ;
return V_698 ;
}
static int F_714 ( void )
{
T_2 V_19 , V_18 ;
int V_133 = 0 ;
if ( V_65 <= 0 )
return - V_62 ;
V_19 = F_51 () ;
V_18 = F_50 () ;
if ( V_19 > V_18 && V_19 != V_26 )
return - V_62 ;
F_628 ( & V_696 ) ;
F_499 ( & V_453 ) ;
V_133 = F_708 ( NULL , 0 , 0 ) ;
F_505 ( & V_453 ) ;
F_629 ( & V_696 ) ;
return V_133 ;
}
int F_715 ( struct V_33 * V_34 , struct V_4 * V_123 )
{
if ( F_679 ( V_123 ) && V_34 -> V_9 . V_20 == 0 )
return 0 ;
return 1 ;
}
static int F_714 ( void )
{
unsigned long V_75 ;
int V_50 ;
if ( V_65 <= 0 )
return - V_62 ;
if ( V_25 == 0 )
return - V_695 ;
F_66 ( & V_651 . V_21 , V_75 ) ;
F_294 (i) {
struct V_44 * V_44 = & F_39 ( V_50 ) -> V_43 ;
F_16 ( & V_44 -> V_21 ) ;
V_44 -> V_20 = F_51 () ;
F_22 ( & V_44 -> V_21 ) ;
}
F_67 ( & V_651 . V_21 , V_75 ) ;
return 0 ;
}
int F_716 ( struct V_473 * V_479 , int V_699 ,
void T_5 * V_700 , T_6 * V_701 ,
T_7 * V_57 )
{
int V_133 ;
int V_702 , V_703 ;
static F_717 ( V_385 ) ;
F_628 ( & V_385 ) ;
V_702 = V_65 ;
V_703 = V_25 ;
V_133 = F_718 ( V_479 , V_699 , V_700 , V_701 , V_57 ) ;
if ( ! V_133 && V_699 ) {
V_133 = F_714 () ;
if ( V_133 ) {
V_65 = V_702 ;
V_25 = V_703 ;
} else {
V_651 . V_20 = F_51 () ;
V_651 . V_15 =
F_10 ( F_50 () ) ;
}
}
F_629 ( & V_385 ) ;
return V_133 ;
}
static inline struct V_33 * F_719 ( struct V_704 * V_705 )
{
return F_5 ( V_35 ( V_705 , V_37 ) ,
struct V_33 , V_36 ) ;
}
static struct V_35 *
F_720 ( struct V_706 * V_707 , struct V_704 * V_705 )
{
struct V_33 * V_34 , * V_42 ;
if ( ! V_705 -> V_42 ) {
return & V_134 . V_36 ;
}
V_42 = F_719 ( V_705 -> V_42 ) ;
V_34 = F_690 ( V_42 ) ;
if ( F_721 ( V_34 ) )
return F_691 ( - V_433 ) ;
return & V_34 -> V_36 ;
}
static void
F_722 ( struct V_706 * V_707 , struct V_704 * V_705 )
{
struct V_33 * V_34 = F_719 ( V_705 ) ;
F_694 ( V_34 ) ;
}
static int
F_723 ( struct V_704 * V_705 , struct V_4 * V_123 )
{
#ifdef F_33
if ( ! F_715 ( F_719 ( V_705 ) , V_123 ) )
return - V_62 ;
#else
if ( V_123 -> V_78 != & V_190 )
return - V_62 ;
#endif
return 0 ;
}
static void
F_724 ( struct V_704 * V_705 , struct V_4 * V_123 )
{
F_696 ( V_123 ) ;
}
static void
F_725 ( struct V_706 * V_707 , struct V_704 * V_705 ,
struct V_704 * V_708 , struct V_4 * V_470 )
{
if ( ! ( V_470 -> V_75 & V_709 ) )
return;
F_696 ( V_470 ) ;
}
static int F_726 ( struct V_704 * V_705 , struct V_710 * V_710 ,
T_2 V_711 )
{
return F_697 ( F_719 ( V_705 ) , F_151 ( V_711 ) ) ;
}
static T_2 F_727 ( struct V_704 * V_705 , struct V_710 * V_712 )
{
struct V_33 * V_34 = F_719 ( V_705 ) ;
return ( T_2 ) F_112 ( V_34 -> V_655 ) ;
}
static int F_728 ( struct V_704 * V_705 , struct V_710 * V_712 ,
T_3 V_127 )
{
return F_710 ( F_719 ( V_705 ) , V_127 ) ;
}
static T_3 F_729 ( struct V_704 * V_705 , struct V_710 * V_712 )
{
return F_711 ( F_719 ( V_705 ) ) ;
}
static int F_730 ( struct V_704 * V_705 , struct V_710 * V_710 ,
T_2 V_698 )
{
return F_712 ( F_719 ( V_705 ) , V_698 ) ;
}
static T_2 F_731 ( struct V_704 * V_705 , struct V_710 * V_712 )
{
return F_713 ( F_719 ( V_705 ) ) ;
}
static int F_732 ( struct V_706 * V_707 , struct V_704 * V_713 )
{
return F_733 ( V_713 , V_707 , V_714 , F_734 ( V_714 ) ) ;
}
static inline struct V_715 * F_735 ( struct V_704 * V_705 )
{
return F_5 ( V_35 ( V_705 , V_716 ) ,
struct V_715 , V_36 ) ;
}
static inline struct V_715 * F_736 ( struct V_4 * V_123 )
{
return F_5 ( F_737 ( V_123 , V_716 ) ,
struct V_715 , V_36 ) ;
}
static struct V_35 * F_738 (
struct V_706 * V_707 , struct V_704 * V_705 )
{
struct V_715 * V_717 = F_663 ( sizeof( * V_717 ) , V_432 ) ;
int V_50 ;
if ( ! V_717 )
goto V_253;
V_717 -> V_718 = F_614 ( T_2 ) ;
if ( ! V_717 -> V_718 )
goto V_719;
for ( V_50 = 0 ; V_50 < V_720 ; V_50 ++ )
if ( F_739 ( & V_717 -> V_170 [ V_50 ] , 0 ) )
goto V_721;
if ( V_705 -> V_42 )
V_717 -> V_42 = F_735 ( V_705 -> V_42 ) ;
return & V_717 -> V_36 ;
V_721:
while ( -- V_50 >= 0 )
F_740 ( & V_717 -> V_170 [ V_50 ] ) ;
F_610 ( V_717 -> V_718 ) ;
V_719:
F_534 ( V_717 ) ;
V_253:
return F_691 ( - V_433 ) ;
}
static void
F_741 ( struct V_706 * V_707 , struct V_704 * V_705 )
{
struct V_715 * V_717 = F_735 ( V_705 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_720 ; V_50 ++ )
F_740 ( & V_717 -> V_170 [ V_50 ] ) ;
F_610 ( V_717 -> V_718 ) ;
F_534 ( V_717 ) ;
}
static T_2 F_742 ( struct V_715 * V_717 , int V_32 )
{
T_2 * V_718 = F_599 ( V_717 -> V_718 , V_32 ) ;
T_2 V_131 ;
#ifndef F_654
F_378 ( & F_39 ( V_32 ) -> V_39 ) ;
V_131 = * V_718 ;
F_59 ( & F_39 ( V_32 ) -> V_39 ) ;
#else
V_131 = * V_718 ;
#endif
return V_131 ;
}
static void F_743 ( struct V_715 * V_717 , int V_32 , T_2 V_127 )
{
T_2 * V_718 = F_599 ( V_717 -> V_718 , V_32 ) ;
#ifndef F_654
F_378 ( & F_39 ( V_32 ) -> V_39 ) ;
* V_718 = V_127 ;
F_59 ( & F_39 ( V_32 ) -> V_39 ) ;
#else
* V_718 = V_127 ;
#endif
}
static T_2 F_744 ( struct V_704 * V_705 , struct V_710 * V_712 )
{
struct V_715 * V_717 = F_735 ( V_705 ) ;
T_2 V_722 = 0 ;
int V_50 ;
F_745 (i)
V_722 += F_742 ( V_717 , V_50 ) ;
return V_722 ;
}
static int F_746 ( struct V_704 * V_705 , struct V_710 * V_710 ,
T_2 V_723 )
{
struct V_715 * V_717 = F_735 ( V_705 ) ;
int V_509 = 0 ;
int V_50 ;
if ( V_723 ) {
V_509 = - V_62 ;
goto V_253;
}
F_745 (i)
F_743 ( V_717 , V_50 , 0 ) ;
V_253:
return V_509 ;
}
static int F_747 ( struct V_704 * V_704 , struct V_710 * V_712 ,
struct V_47 * V_48 )
{
struct V_715 * V_717 = F_735 ( V_704 ) ;
T_2 V_724 ;
int V_50 ;
F_745 (i) {
V_724 = F_742 ( V_717 , V_50 ) ;
F_42 ( V_48 , L_56 , ( unsigned long long ) V_724 ) ;
}
F_42 ( V_48 , L_3 ) ;
return 0 ;
}
static int F_748 ( struct V_704 * V_705 , struct V_710 * V_712 ,
struct V_725 * V_726 )
{
struct V_715 * V_717 = F_735 ( V_705 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_720 ; V_50 ++ ) {
T_3 V_127 = F_749 ( & V_717 -> V_170 [ V_50 ] ) ;
V_127 = F_750 ( V_127 ) ;
V_726 -> V_727 ( V_726 , V_728 [ V_50 ] , V_127 ) ;
}
return 0 ;
}
static int F_751 ( struct V_706 * V_707 , struct V_704 * V_705 )
{
return F_733 ( V_705 , V_707 , V_729 , F_734 ( V_729 ) ) ;
}
static void F_118 ( struct V_4 * V_123 , T_2 V_124 )
{
struct V_715 * V_717 ;
int V_32 ;
if ( F_2 ( ! V_730 . V_295 ) )
return;
V_32 = F_94 ( V_123 ) ;
F_102 () ;
V_717 = F_736 ( V_123 ) ;
for (; V_717 ; V_717 = V_717 -> V_42 ) {
T_2 * V_718 = F_599 ( V_717 -> V_718 , V_32 ) ;
* V_718 += V_124 ;
}
F_106 () ;
}
static void F_119 ( struct V_4 * V_123 ,
enum V_125 V_126 , T_9 V_127 )
{
struct V_715 * V_717 ;
int V_731 = V_732 ;
if ( F_2 ( ! V_730 . V_295 ) )
return;
F_102 () ;
V_717 = F_736 ( V_123 ) ;
do {
F_752 ( & V_717 -> V_170 [ V_126 ] , V_127 , V_731 ) ;
V_717 = V_717 -> V_42 ;
} while ( V_717 );
F_106 () ;
}
