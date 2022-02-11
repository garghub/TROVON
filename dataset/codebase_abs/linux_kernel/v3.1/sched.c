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
static void F_13 ( struct V_9 * V_10 )
{
T_1 V_12 ;
if ( ! F_12 () || V_10 -> V_20 == V_26 )
return;
if ( F_14 ( & V_10 -> V_11 ) )
return;
F_15 ( & V_10 -> V_21 ) ;
for (; ; ) {
unsigned long V_27 ;
T_1 V_28 , V_29 ;
if ( F_14 ( & V_10 -> V_11 ) )
break;
V_12 = F_5 ( & V_10 -> V_11 ) ;
F_6 ( & V_10 -> V_11 , V_12 , V_10 -> V_15 ) ;
V_28 = F_16 ( & V_10 -> V_11 ) ;
V_29 = F_17 ( & V_10 -> V_11 ) ;
V_27 = F_18 ( F_19 ( V_29 , V_28 ) ) ;
F_20 ( & V_10 -> V_11 , V_28 , V_27 ,
V_30 , 0 ) ;
}
F_21 ( & V_10 -> V_21 ) ;
}
static void F_22 ( struct V_9 * V_10 )
{
F_23 ( & V_10 -> V_11 ) ;
}
static inline int F_24 ( struct V_31 * V_31 )
{
#ifdef F_25
return V_31 -> V_32 ;
#else
return 0 ;
#endif
}
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_36 = F_26 ( V_5 , V_37 ,
F_27 ( & V_5 -> V_38 ) ||
F_27 ( & F_28 ( V_5 ) -> V_39 ) ) ;
V_34 = F_4 ( V_36 , struct V_33 , V_36 ) ;
return F_29 ( V_5 , V_34 ) ;
}
static inline void F_30 ( struct V_4 * V_5 , unsigned int V_32 )
{
#ifdef F_31
V_5 -> V_40 . V_41 = V_33 ( V_5 ) -> V_41 [ V_32 ] ;
V_5 -> V_40 . V_42 = V_33 ( V_5 ) -> V_40 [ V_32 ] ;
#endif
#ifdef F_32
V_5 -> V_43 . V_44 = V_33 ( V_5 ) -> V_44 [ V_32 ] ;
V_5 -> V_43 . V_42 = V_33 ( V_5 ) -> V_45 [ V_32 ] ;
#endif
}
static inline void F_30 ( struct V_4 * V_5 , unsigned int V_32 ) { }
static inline struct V_33 * V_33 ( struct V_4 * V_5 )
{
return NULL ;
}
static void F_33 ( struct V_31 * V_31 )
{
T_3 V_27 ;
if ( V_31 -> V_46 > 0 )
return;
V_27 = F_34 ( F_24 ( V_31 ) ) - V_31 -> clock ;
V_31 -> clock += V_27 ;
F_35 ( V_31 , V_27 ) ;
}
int F_36 ( int V_32 )
{
return F_37 ( & F_38 ( V_32 ) -> V_39 ) ;
}
static int F_39 ( struct V_47 * V_48 , void * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_51 [ V_50 ] ; V_50 ++ ) {
if ( ! ( V_52 & ( 1UL << V_50 ) ) )
F_40 ( V_48 , L_1 ) ;
F_41 ( V_48 , L_2 , V_51 [ V_50 ] ) ;
}
F_40 ( V_48 , L_3 ) ;
return 0 ;
}
static T_4
F_42 ( struct V_53 * V_54 , const char T_5 * V_55 ,
T_6 V_56 , T_7 * V_57 )
{
char V_58 [ 64 ] ;
char * V_59 ;
int V_60 = 0 ;
int V_50 ;
if ( V_56 > 63 )
V_56 = 63 ;
if ( F_43 ( & V_58 , V_55 , V_56 ) )
return - V_61 ;
V_58 [ V_56 ] = 0 ;
V_59 = F_44 ( V_58 ) ;
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
static int F_45 ( struct V_63 * V_63 , struct V_53 * V_54 )
{
return F_46 ( V_54 , F_39 , NULL ) ;
}
static T_8 int F_47 ( void )
{
F_48 ( L_4 , 0644 , NULL , NULL ,
& V_64 ) ;
return 0 ;
}
static inline T_2 F_49 ( void )
{
return ( T_2 ) V_65 * V_66 ;
}
static inline T_2 F_50 ( void )
{
if ( V_25 < 0 )
return V_26 ;
return ( T_2 ) V_25 * V_66 ;
}
static inline int F_51 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
return V_31 -> V_67 == V_5 ;
}
static inline int F_52 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
#ifdef F_25
return V_5 -> V_68 ;
#else
return F_51 ( V_31 , V_5 ) ;
#endif
}
static inline void F_53 ( struct V_31 * V_31 , struct V_4 * V_69 )
{
#ifdef F_25
V_69 -> V_68 = 1 ;
#endif
}
static inline void F_54 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
#ifdef F_25
F_55 () ;
V_70 -> V_68 = 0 ;
#endif
#ifdef F_56
V_31 -> V_39 . V_71 = V_72 ;
#endif
F_57 ( & V_31 -> V_39 . V_73 , 0 , 0 , V_74 ) ;
F_58 ( & V_31 -> V_39 ) ;
}
static inline void F_53 ( struct V_31 * V_31 , struct V_4 * V_69 )
{
#ifdef F_25
V_69 -> V_68 = 1 ;
#endif
#ifdef F_59
F_58 ( & V_31 -> V_39 ) ;
#else
F_21 ( & V_31 -> V_39 ) ;
#endif
}
static inline void F_54 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
#ifdef F_25
F_55 () ;
V_70 -> V_68 = 0 ;
#endif
#ifndef F_59
F_60 () ;
#endif
}
static inline struct V_31 * F_61 ( struct V_4 * V_5 )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
F_62 ( & V_5 -> V_38 ) ;
for (; ; ) {
V_31 = F_28 ( V_5 ) ;
F_15 ( & V_31 -> V_39 ) ;
if ( F_63 ( V_31 == F_28 ( V_5 ) ) )
return V_31 ;
F_21 ( & V_31 -> V_39 ) ;
}
}
static struct V_31 * F_64 ( struct V_4 * V_5 , unsigned long * V_75 )
__acquires( V_5 -> V_38 )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
for (; ; ) {
F_65 ( & V_5 -> V_38 , * V_75 ) ;
V_31 = F_28 ( V_5 ) ;
F_15 ( & V_31 -> V_39 ) ;
if ( F_63 ( V_31 == F_28 ( V_5 ) ) )
return V_31 ;
F_21 ( & V_31 -> V_39 ) ;
F_66 ( & V_5 -> V_38 , * V_75 ) ;
}
}
static void F_67 ( struct V_31 * V_31 )
__releases( V_31 -> V_39 )
{
F_21 ( & V_31 -> V_39 ) ;
}
static inline void
F_68 ( struct V_31 * V_31 , struct V_4 * V_5 , unsigned long * V_75 )
__releases( V_31 -> V_39 )
__releases( V_5 -> V_38 )
{
F_21 ( & V_31 -> V_39 ) ;
F_66 ( & V_5 -> V_38 , * V_75 ) ;
}
static struct V_31 * F_69 ( void )
__acquires( V_31 -> V_39 )
{
struct V_31 * V_31 ;
F_70 () ;
V_31 = F_71 () ;
F_15 ( & V_31 -> V_39 ) ;
return V_31 ;
}
static inline int F_72 ( struct V_31 * V_31 )
{
if ( ! F_73 ( V_76 ) )
return 0 ;
if ( ! F_74 ( F_24 ( V_31 ) ) )
return 0 ;
return F_75 ( & V_31 -> V_77 ) ;
}
static void F_76 ( struct V_31 * V_31 )
{
if ( F_14 ( & V_31 -> V_77 ) )
F_23 ( & V_31 -> V_77 ) ;
}
static enum V_6 F_77 ( struct V_7 * V_8 )
{
struct V_31 * V_31 = F_4 ( V_8 , struct V_31 , V_77 ) ;
F_78 ( F_24 ( V_31 ) != F_79 () ) ;
F_15 ( & V_31 -> V_39 ) ;
F_33 ( V_31 ) ;
V_31 -> V_67 -> V_78 -> V_79 ( V_31 , V_31 -> V_67 , 1 ) ;
F_21 ( & V_31 -> V_39 ) ;
return V_16 ;
}
static void F_80 ( void * V_80 )
{
struct V_31 * V_31 = V_80 ;
F_15 ( & V_31 -> V_39 ) ;
V_6 ( & V_31 -> V_77 ) ;
V_31 -> V_81 = 0 ;
F_21 ( & V_31 -> V_39 ) ;
}
static void F_81 ( struct V_31 * V_31 , T_2 V_82 )
{
struct V_7 * V_8 = & V_31 -> V_77 ;
T_1 time = F_82 ( V_8 -> V_83 -> V_84 () , V_82 ) ;
F_83 ( V_8 , time ) ;
if ( V_31 == F_71 () ) {
V_6 ( V_8 ) ;
} else if ( ! V_31 -> V_81 ) {
F_84 ( F_24 ( V_31 ) , & V_31 -> V_85 , 0 ) ;
V_31 -> V_81 = 1 ;
}
}
static int
F_85 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
int V_32 = ( int ) ( long ) V_89 ;
switch ( V_88 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
F_76 ( F_38 ( V_32 ) ) ;
return V_96 ;
}
return V_97 ;
}
static T_8 void F_86 ( void )
{
F_87 ( F_85 , 0 ) ;
}
static void F_81 ( struct V_31 * V_31 , T_2 V_82 )
{
F_20 ( & V_31 -> V_77 , F_9 ( V_82 ) , 0 ,
V_98 , 0 ) ;
}
static inline void F_86 ( void )
{
}
static void F_88 ( struct V_31 * V_31 )
{
#ifdef F_25
V_31 -> V_81 = 0 ;
V_31 -> V_85 . V_75 = 0 ;
V_31 -> V_85 . V_99 = F_80 ;
V_31 -> V_85 . V_100 = V_31 ;
#endif
F_11 ( & V_31 -> V_77 , V_22 , V_23 ) ;
V_31 -> V_77 . V_24 = F_77 ;
}
static inline void F_76 ( struct V_31 * V_31 )
{
}
static inline void F_88 ( struct V_31 * V_31 )
{
}
static inline void F_86 ( void )
{
}
static void F_89 ( struct V_4 * V_5 )
{
int V_32 ;
F_90 ( & F_28 ( V_5 ) -> V_39 ) ;
if ( F_91 ( V_5 ) )
return;
F_92 ( V_5 ) ;
V_32 = F_93 ( V_5 ) ;
if ( V_32 == F_79 () )
return;
F_94 () ;
if ( ! F_95 ( V_5 ) )
F_96 ( V_32 ) ;
}
static void F_97 ( int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_75 ;
if ( ! F_98 ( & V_31 -> V_39 , V_75 ) )
return;
F_89 ( F_99 ( V_32 ) ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
}
int F_100 ( void )
{
int V_32 = F_79 () ;
int V_50 ;
struct V_101 * V_102 ;
F_101 () ;
F_102 (cpu, sd) {
F_103 (i, sched_domain_span(sd)) {
if ( ! F_104 ( V_50 ) ) {
V_32 = V_50 ;
goto V_103;
}
}
}
V_103:
F_105 () ;
return V_32 ;
}
void F_106 ( int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
if ( V_32 == F_79 () )
return;
if ( V_31 -> V_67 != V_31 -> V_14 )
return;
F_92 ( V_31 -> V_14 ) ;
F_94 () ;
if ( ! F_95 ( V_31 -> V_14 ) )
F_96 ( V_32 ) ;
}
static T_2 F_107 ( void )
{
return ( T_2 ) V_104 * V_105 / 2 ;
}
static void F_108 ( struct V_31 * V_31 )
{
T_3 V_18 = F_107 () ;
while ( ( T_3 ) ( V_31 -> clock - V_31 -> V_106 ) > V_18 ) {
asm("" : "+rm" (rq->age_stamp));
V_31 -> V_106 += V_18 ;
V_31 -> V_107 /= 2 ;
}
}
static void F_109 ( struct V_31 * V_31 , T_2 V_108 )
{
V_31 -> V_107 += V_108 ;
F_108 ( V_31 ) ;
}
static void F_89 ( struct V_4 * V_5 )
{
F_90 ( & F_28 ( V_5 ) -> V_39 ) ;
F_92 ( V_5 ) ;
}
static void F_109 ( struct V_31 * V_31 , T_2 V_108 )
{
}
static void F_108 ( struct V_31 * V_31 )
{
}
static unsigned long
F_110 ( unsigned long V_109 , unsigned long V_110 ,
struct V_111 * V_112 )
{
T_2 V_113 ;
if ( F_63 ( V_110 > ( 1UL << V_114 ) ) )
V_113 = ( T_2 ) V_109 * F_111 ( V_110 ) ;
else
V_113 = ( T_2 ) V_109 ;
if ( ! V_112 -> V_115 ) {
unsigned long V_116 = F_111 ( V_112 -> V_110 ) ;
if ( V_117 > 32 && F_112 ( V_116 >= V_118 ) )
V_112 -> V_115 = 1 ;
else if ( F_112 ( ! V_116 ) )
V_112 -> V_115 = V_118 ;
else
V_112 -> V_115 = V_118 / V_116 ;
}
if ( F_112 ( V_113 > V_118 ) )
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
F_101 () ;
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
F_105 () ;
return V_133 ;
}
static int F_124 ( struct V_33 * V_34 , void * V_131 )
{
return 0 ;
}
static unsigned long F_125 ( const int V_32 )
{
return F_38 ( V_32 ) -> V_128 . V_110 ;
}
static unsigned long F_126 ( int V_32 , int type )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_136 = F_125 ( V_32 ) ;
if ( type == 0 || ! F_73 ( V_137 ) )
return V_136 ;
return F_114 ( V_31 -> V_138 [ type - 1 ] , V_136 ) ;
}
static unsigned long F_127 ( int V_32 , int type )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_136 = F_125 ( V_32 ) ;
if ( type == 0 || ! F_73 ( V_137 ) )
return V_136 ;
return F_128 ( V_31 -> V_138 [ type - 1 ] , V_136 ) ;
}
static unsigned long F_129 ( int V_32 )
{
return F_38 ( V_32 ) -> V_139 ;
}
static unsigned long F_130 ( int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_140 = F_131 ( V_31 -> V_140 ) ;
if ( V_140 )
V_31 -> V_141 = V_31 -> V_128 . V_110 / V_140 ;
else
V_31 -> V_141 = 0 ;
return V_31 -> V_141 ;
}
static inline int F_132 ( struct V_31 * F_71 , struct V_31 * V_142 )
__releases( F_71 -> V_39 )
__acquires( V_142 -> V_39 )
__acquires( F_71 -> V_39 )
{
F_21 ( & F_71 -> V_39 ) ;
F_133 ( F_71 , V_142 ) ;
return 1 ;
}
static int F_132 ( struct V_31 * F_71 , struct V_31 * V_142 )
__releases( F_71 -> V_39 )
__acquires( V_142 -> V_39 )
__acquires( F_71 -> V_39 )
{
int V_133 = 0 ;
if ( F_112 ( ! F_134 ( & V_142 -> V_39 ) ) ) {
if ( V_142 < F_71 ) {
F_21 ( & F_71 -> V_39 ) ;
F_15 ( & V_142 -> V_39 ) ;
F_135 ( & F_71 -> V_39 ,
V_143 ) ;
V_133 = 1 ;
} else
F_135 ( & V_142 -> V_39 ,
V_143 ) ;
}
return V_133 ;
}
static int F_136 ( struct V_31 * F_71 , struct V_31 * V_142 )
{
if ( F_112 ( ! F_137 () ) ) {
F_21 ( & F_71 -> V_39 ) ;
F_138 ( 1 ) ;
}
return F_132 ( F_71 , V_142 ) ;
}
static inline void F_139 ( struct V_31 * F_71 , struct V_31 * V_142 )
__releases( V_142 -> V_39 )
{
F_21 ( & V_142 -> V_39 ) ;
F_140 ( & F_71 -> V_39 . V_73 , 0 , V_144 ) ;
}
static void F_133 ( struct V_31 * V_145 , struct V_31 * V_146 )
__acquires( V_145 -> V_39 )
__acquires( V_146 -> V_39 )
{
F_138 ( ! F_137 () ) ;
if ( V_145 == V_146 ) {
F_15 ( & V_145 -> V_39 ) ;
F_141 ( V_146 -> V_39 ) ;
} else {
if ( V_145 < V_146 ) {
F_15 ( & V_145 -> V_39 ) ;
F_135 ( & V_146 -> V_39 , V_143 ) ;
} else {
F_15 ( & V_146 -> V_39 ) ;
F_135 ( & V_145 -> V_39 , V_143 ) ;
}
}
}
static void F_142 ( struct V_31 * V_145 , struct V_31 * V_146 )
__releases( V_145 -> V_39 )
__releases( V_146 -> V_39 )
{
F_21 ( & V_145 -> V_39 ) ;
if ( V_145 != V_146 )
F_21 ( & V_146 -> V_39 ) ;
else
F_143 ( V_146 -> V_39 ) ;
}
static void F_133 ( struct V_31 * V_145 , struct V_31 * V_146 )
__acquires( V_145 -> V_39 )
__acquires( V_146 -> V_39 )
{
F_138 ( ! F_137 () ) ;
F_138 ( V_145 != V_146 ) ;
F_15 ( & V_145 -> V_39 ) ;
F_141 ( V_146 -> V_39 ) ;
}
static void F_142 ( struct V_31 * V_145 , struct V_31 * V_146 )
__releases( V_145 -> V_39 )
__releases( V_146 -> V_39 )
{
F_138 ( V_145 != V_146 ) ;
F_21 ( & V_145 -> V_39 ) ;
F_143 ( V_146 -> V_39 ) ;
}
static inline void F_144 ( struct V_4 * V_5 , unsigned int V_32 )
{
F_30 ( V_5 , V_32 ) ;
#ifdef F_25
F_55 () ;
F_145 ( V_5 ) -> V_32 = V_32 ;
#endif
}
static void F_146 ( struct V_31 * V_31 )
{
V_31 -> V_140 ++ ;
}
static void F_147 ( struct V_31 * V_31 )
{
V_31 -> V_140 -- ;
}
static void F_148 ( struct V_4 * V_5 )
{
int V_147 = V_5 -> V_148 - V_149 ;
struct V_111 * V_128 = & V_5 -> V_40 . V_128 ;
if ( V_5 -> V_1 == V_150 ) {
V_128 -> V_110 = F_149 ( V_151 ) ;
V_128 -> V_115 = V_152 ;
return;
}
V_128 -> V_110 = F_149 ( V_153 [ V_147 ] ) ;
V_128 -> V_115 = V_154 [ V_147 ] ;
}
static void F_150 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
F_33 ( V_31 ) ;
F_151 ( V_5 ) ;
V_5 -> V_78 -> F_150 ( V_31 , V_5 , V_75 ) ;
}
static void F_152 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
F_33 ( V_31 ) ;
F_153 ( V_5 ) ;
V_5 -> V_78 -> F_152 ( V_31 , V_5 , V_75 ) ;
}
static void F_154 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
if ( F_155 ( V_5 ) )
V_31 -> V_155 -- ;
F_150 ( V_31 , V_5 , V_75 ) ;
F_146 ( V_31 ) ;
}
static void F_156 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
if ( F_155 ( V_5 ) )
V_31 -> V_155 ++ ;
F_152 ( V_31 , V_5 , V_75 ) ;
F_147 ( V_31 ) ;
}
void F_157 ( void )
{
V_156 = 1 ;
}
void F_158 ( void )
{
V_156 = 0 ;
}
static inline void F_159 ( void )
{
F_160 ( V_157 . V_158 ) ;
F_55 () ;
}
static inline void F_161 ( void )
{
F_55 () ;
F_160 ( V_157 . V_158 ) ;
}
static inline T_2 F_162 ( int V_32 )
{
T_2 V_159 ;
unsigned V_160 ;
do {
V_160 = F_163 ( & F_164 ( V_157 , V_32 ) ) ;
V_159 = F_164 ( V_161 , V_32 ) +
F_164 ( V_162 , V_32 ) ;
} while ( F_165 ( & F_164 ( V_157 , V_32 ) , V_160 ) );
return V_159 ;
}
static inline void F_159 ( void )
{
}
static inline void F_161 ( void )
{
}
static inline T_2 F_162 ( int V_32 )
{
return F_164 ( V_161 , V_32 ) + F_164 ( V_162 , V_32 ) ;
}
void F_166 ( struct V_4 * V_67 )
{
unsigned long V_75 ;
T_3 V_27 ;
int V_32 ;
if ( ! V_156 )
return;
F_167 ( V_75 ) ;
V_32 = F_79 () ;
V_27 = F_34 ( V_32 ) - F_168 ( V_163 ) ;
F_169 ( V_163 , V_27 ) ;
F_159 () ;
if ( F_170 () )
F_169 ( V_162 , V_27 ) ;
else if ( F_171 () && V_67 != F_172 () )
F_169 ( V_161 , V_27 ) ;
F_161 () ;
F_173 ( V_75 ) ;
}
static inline T_2 F_174 ( T_2 V_164 )
{
if ( F_112 ( V_164 > V_165 ) )
return F_175 ( V_164 , V_166 ) ;
return F_176 ( V_164 , V_166 , & V_164 ) ;
}
static void F_35 ( struct V_31 * V_31 , T_3 V_27 )
{
#if F_177 ( V_167 ) || F_177 ( V_168 )
T_3 V_164 = 0 , V_169 = 0 ;
#endif
#ifdef V_167
V_169 = F_162 ( F_24 ( V_31 ) ) - V_31 -> V_170 ;
if ( V_169 > V_27 )
V_169 = V_27 ;
V_31 -> V_170 += V_169 ;
V_27 -= V_169 ;
#endif
#ifdef V_168
if ( F_178 ( ( & V_171 ) ) ) {
T_2 V_172 ;
V_164 = F_179 ( F_24 ( V_31 ) ) ;
V_164 -= V_31 -> V_173 ;
if ( F_112 ( V_164 > V_27 ) )
V_164 = V_27 ;
V_172 = F_174 ( V_164 ) ;
V_164 = V_172 * V_166 ;
V_31 -> V_173 += V_164 ;
V_27 -= V_164 ;
}
#endif
V_31 -> V_174 += V_27 ;
#if F_177 ( V_167 ) || F_177 ( V_168 )
if ( ( V_169 + V_164 ) && F_73 ( V_175 ) )
F_109 ( V_31 , V_169 + V_164 ) ;
#endif
}
static int F_180 ( void )
{
struct V_176 * V_177 = & V_178 . V_177 ;
unsigned long V_75 ;
T_2 V_179 ;
int V_133 = 0 ;
F_167 ( V_75 ) ;
V_179 = F_181 ( V_162 ) ;
if ( F_182 ( F_183 ( V_179 ) , V_177 -> V_180 ) )
V_133 = 1 ;
F_173 ( V_75 ) ;
return V_133 ;
}
static int F_184 ( void )
{
struct V_176 * V_177 = & V_178 . V_177 ;
unsigned long V_75 ;
T_2 V_179 ;
int V_133 = 0 ;
F_167 ( V_75 ) ;
V_179 = F_181 ( V_161 ) ;
if ( F_182 ( F_183 ( V_179 ) , V_177 -> V_181 ) )
V_133 = 1 ;
F_173 ( V_75 ) ;
return V_133 ;
}
void F_185 ( int V_32 , struct V_4 * V_182 )
{
struct V_183 V_184 = { . V_185 = V_149 - 1 } ;
struct V_4 * V_186 = F_38 ( V_32 ) -> V_182 ;
if ( V_182 ) {
F_186 ( V_182 , V_2 , & V_184 ) ;
V_182 -> V_78 = & V_187 ;
}
F_38 ( V_32 ) -> V_182 = V_182 ;
if ( V_186 ) {
V_186 -> V_78 = & V_188 ;
}
}
static inline int F_187 ( struct V_4 * V_5 )
{
return V_5 -> V_148 ;
}
static inline int F_188 ( struct V_4 * V_5 )
{
int V_147 ;
if ( F_2 ( V_5 ) )
V_147 = V_149 - 1 - V_5 -> V_189 ;
else
V_147 = F_187 ( V_5 ) ;
return V_147 ;
}
static int F_189 ( struct V_4 * V_5 )
{
V_5 -> F_188 = F_188 ( V_5 ) ;
if ( ! F_190 ( V_5 -> V_147 ) )
return V_5 -> F_188 ;
return V_5 -> V_147 ;
}
inline int F_191 ( const struct V_4 * V_5 )
{
return F_99 ( F_93 ( V_5 ) ) == V_5 ;
}
static inline void F_192 ( struct V_31 * V_31 , struct V_4 * V_5 ,
const struct V_78 * V_190 ,
int V_191 )
{
if ( V_190 != V_5 -> V_78 ) {
if ( V_190 -> V_192 )
V_190 -> V_192 ( V_31 , V_5 ) ;
V_5 -> V_78 -> V_193 ( V_31 , V_5 ) ;
} else if ( V_191 != V_5 -> V_147 )
V_5 -> V_78 -> V_194 ( V_31 , V_5 , V_191 ) ;
}
static void F_193 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_75 )
{
const struct V_78 * V_195 ;
if ( V_5 -> V_78 == V_31 -> V_67 -> V_78 ) {
V_31 -> V_67 -> V_78 -> F_193 ( V_31 , V_5 , V_75 ) ;
} else {
F_194 (class) {
if ( V_195 == V_31 -> V_67 -> V_78 )
break;
if ( V_195 == V_5 -> V_78 ) {
F_89 ( V_31 -> V_67 ) ;
break;
}
}
}
if ( V_31 -> V_67 -> V_196 && F_91 ( V_31 -> V_67 ) )
V_31 -> V_46 = 1 ;
}
static int
F_195 ( struct V_4 * V_5 , T_2 V_12 , struct V_101 * V_102 )
{
T_3 V_27 ;
if ( V_5 -> V_78 != & V_197 )
return 0 ;
if ( F_112 ( V_5 -> V_1 == V_150 ) )
return 0 ;
if ( F_73 ( V_198 ) && F_71 () -> V_140 &&
( & V_5 -> V_40 == F_196 ( & V_5 -> V_40 ) -> V_69 ||
& V_5 -> V_40 == F_196 ( & V_5 -> V_40 ) -> V_199 ) )
return 1 ;
if ( V_200 == - 1 )
return 1 ;
if ( V_200 == 0 )
return 0 ;
V_27 = V_12 - V_5 -> V_40 . V_201 ;
return V_27 < ( T_3 ) V_200 ;
}
void F_197 ( struct V_4 * V_5 , unsigned int V_202 )
{
#ifdef F_198
F_78 ( V_5 -> V_203 != V_204 && V_5 -> V_203 != V_205 &&
! ( F_145 ( V_5 ) -> V_206 & V_207 ) ) ;
#ifdef F_199
F_78 ( V_208 && ! ( F_27 ( & V_5 -> V_38 ) ||
F_27 ( & F_28 ( V_5 ) -> V_39 ) ) ) ;
#endif
#endif
F_200 ( V_5 , V_202 ) ;
if ( F_93 ( V_5 ) != V_202 ) {
V_5 -> V_40 . V_209 ++ ;
F_201 ( V_210 , 1 , NULL , 0 ) ;
}
F_144 ( V_5 , V_202 ) ;
}
unsigned long F_202 ( struct V_4 * V_5 , long V_211 )
{
unsigned long V_75 ;
int V_212 , V_196 ;
unsigned long V_213 ;
struct V_31 * V_31 ;
for (; ; ) {
V_31 = F_28 ( V_5 ) ;
while ( F_52 ( V_31 , V_5 ) ) {
if ( V_211 && F_112 ( V_5 -> V_203 != V_211 ) )
return 0 ;
F_203 () ;
}
V_31 = F_64 ( V_5 , & V_75 ) ;
F_204 ( V_5 ) ;
V_212 = F_52 ( V_31 , V_5 ) ;
V_196 = V_5 -> V_196 ;
V_213 = 0 ;
if ( ! V_211 || V_5 -> V_203 == V_211 )
V_213 = V_5 -> V_214 | V_215 ;
F_68 ( V_31 , V_5 , & V_75 ) ;
if ( F_112 ( ! V_213 ) )
break;
if ( F_112 ( V_212 ) ) {
F_203 () ;
continue;
}
if ( F_112 ( V_196 ) ) {
T_1 V_216 = F_205 ( 0 , V_165 / V_217 ) ;
F_206 ( V_218 ) ;
F_207 ( & V_216 , V_23 ) ;
continue;
}
break;
}
return V_213 ;
}
void F_208 ( struct V_4 * V_5 )
{
int V_32 ;
F_209 () ;
V_32 = F_93 ( V_5 ) ;
if ( ( V_32 != F_79 () ) && F_191 ( V_5 ) )
F_96 ( V_32 ) ;
F_210 () ;
}
static int F_211 ( int V_32 , struct V_4 * V_5 )
{
int V_219 ;
const struct V_220 * V_221 = F_212 ( F_213 ( V_32 ) ) ;
F_214 (dest_cpu, nodemask, cpu_active_mask)
if ( F_215 ( V_219 , & V_5 -> V_222 ) )
return V_219 ;
V_219 = F_216 ( & V_5 -> V_222 , V_223 ) ;
if ( V_219 < V_224 )
return V_219 ;
V_219 = F_217 ( V_5 ) ;
if ( V_5 -> V_225 && F_218 () ) {
F_219 ( V_226 L_5 ,
F_220 ( V_5 ) , V_5 -> V_227 , V_32 ) ;
}
return V_219 ;
}
static inline
int F_221 ( struct V_4 * V_5 , int V_228 , int V_229 )
{
int V_32 = V_5 -> V_78 -> F_221 ( V_5 , V_228 , V_229 ) ;
if ( F_112 ( ! F_215 ( V_32 , & V_5 -> V_222 ) ||
! F_222 ( V_32 ) ) )
V_32 = F_211 ( F_93 ( V_5 ) , V_5 ) ;
return V_32 ;
}
static void F_223 ( T_2 * V_230 , T_2 V_231 )
{
T_3 V_232 = V_231 - * V_230 ;
* V_230 += V_232 >> 3 ;
}
static void
F_224 ( struct V_4 * V_5 , int V_32 , int V_229 )
{
#ifdef F_225
struct V_31 * V_31 = F_71 () ;
#ifdef F_25
int V_233 = F_79 () ;
if ( V_32 == V_233 ) {
F_226 ( V_31 , V_234 ) ;
F_226 ( V_5 , V_40 . V_235 . V_236 ) ;
} else {
struct V_101 * V_102 ;
F_226 ( V_5 , V_40 . V_235 . V_237 ) ;
F_101 () ;
F_102 (this_cpu, sd) {
if ( F_215 ( V_32 , F_227 ( V_102 ) ) ) {
F_226 ( V_102 , V_238 ) ;
break;
}
}
F_105 () ;
}
if ( V_229 & V_239 )
F_226 ( V_5 , V_40 . V_235 . V_240 ) ;
#endif
F_226 ( V_31 , V_241 ) ;
F_226 ( V_5 , V_40 . V_235 . V_242 ) ;
if ( V_229 & V_243 )
F_226 ( V_5 , V_40 . V_235 . V_244 ) ;
#endif
}
static void F_228 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_245 )
{
F_154 ( V_31 , V_5 , V_245 ) ;
V_5 -> V_196 = 1 ;
if ( V_5 -> V_75 & V_246 )
F_229 ( V_5 , F_24 ( V_31 ) ) ;
}
static void
F_230 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_229 )
{
F_231 ( V_5 , true ) ;
F_193 ( V_31 , V_5 , V_229 ) ;
V_5 -> V_203 = V_204 ;
#ifdef F_25
if ( V_5 -> V_78 -> V_247 )
V_5 -> V_78 -> V_247 ( V_31 , V_5 ) ;
if ( V_31 -> V_248 ) {
T_2 V_27 = V_31 -> clock - V_31 -> V_248 ;
T_2 F_128 = 2 * V_200 ;
if ( V_27 > F_128 )
V_31 -> V_249 = F_128 ;
else
F_223 ( & V_31 -> V_249 , V_27 ) ;
V_31 -> V_248 = 0 ;
}
#endif
}
static void
F_232 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_229 )
{
#ifdef F_25
if ( V_5 -> V_250 )
V_31 -> V_155 -- ;
#endif
F_228 ( V_31 , V_5 , V_251 | V_252 ) ;
F_230 ( V_31 , V_5 , V_229 ) ;
}
static int F_233 ( struct V_4 * V_5 , int V_229 )
{
struct V_31 * V_31 ;
int V_133 = 0 ;
V_31 = F_61 ( V_5 ) ;
if ( V_5 -> V_196 ) {
F_230 ( V_31 , V_5 , V_229 ) ;
V_133 = 1 ;
}
F_67 ( V_31 ) ;
return V_133 ;
}
static void F_234 ( struct V_4 * V_253 )
{
struct V_31 * V_31 = F_71 () ;
F_15 ( & V_31 -> V_39 ) ;
while ( V_253 ) {
struct V_4 * V_5 = V_253 ;
V_253 = V_253 -> V_254 ;
F_232 ( V_31 , V_5 , 0 ) ;
}
F_21 ( & V_31 -> V_39 ) ;
}
static void F_235 ( void )
{
struct V_31 * V_31 = F_71 () ;
struct V_4 * V_253 = F_236 ( & V_31 -> V_255 , NULL ) ;
if ( ! V_253 )
return;
F_234 ( V_253 ) ;
}
void F_237 ( void )
{
struct V_31 * V_31 = F_71 () ;
struct V_4 * V_253 = F_236 ( & V_31 -> V_255 , NULL ) ;
if ( ! V_253 )
return;
F_238 () ;
F_234 ( V_253 ) ;
F_239 () ;
}
static void F_240 ( struct V_4 * V_5 , int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
struct V_4 * V_69 = V_31 -> V_255 ;
for (; ; ) {
struct V_4 * V_256 = V_69 ;
V_5 -> V_254 = V_69 ;
V_69 = F_241 ( & V_31 -> V_255 , V_256 , V_5 ) ;
if ( V_69 == V_256 )
break;
}
if ( ! V_69 )
F_96 ( V_32 ) ;
}
static int F_242 ( struct V_4 * V_5 , int V_229 )
{
struct V_31 * V_31 ;
int V_133 = 0 ;
V_31 = F_61 ( V_5 ) ;
if ( V_5 -> V_68 ) {
F_228 ( V_31 , V_5 , V_251 ) ;
F_230 ( V_31 , V_5 , V_229 ) ;
V_133 = 1 ;
}
F_67 ( V_31 ) ;
return V_133 ;
}
static void F_243 ( struct V_4 * V_5 , int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
#if F_177 ( F_25 )
if ( F_73 ( V_257 ) && V_32 != F_79 () ) {
F_34 ( V_32 ) ;
F_240 ( V_5 , V_32 ) ;
return;
}
#endif
F_15 ( & V_31 -> V_39 ) ;
F_232 ( V_31 , V_5 , 0 ) ;
F_21 ( & V_31 -> V_39 ) ;
}
static int
F_244 ( struct V_4 * V_5 , unsigned int V_203 , int V_229 )
{
unsigned long V_75 ;
int V_32 , V_258 = 0 ;
F_55 () ;
F_65 ( & V_5 -> V_38 , V_75 ) ;
if ( ! ( V_5 -> V_203 & V_203 ) )
goto V_259;
V_258 = 1 ;
V_32 = F_93 ( V_5 ) ;
if ( V_5 -> V_196 && F_233 ( V_5 , V_229 ) )
goto V_260;
#ifdef F_25
while ( V_5 -> V_68 ) {
#ifdef F_59
if ( F_242 ( V_5 , V_229 ) )
goto V_260;
#else
F_203 () ;
#endif
}
F_245 () ;
V_5 -> V_250 = ! ! F_155 ( V_5 ) ;
V_5 -> V_203 = V_205 ;
if ( V_5 -> V_78 -> V_261 )
V_5 -> V_78 -> V_261 ( V_5 ) ;
V_32 = F_221 ( V_5 , V_262 , V_229 ) ;
if ( F_93 ( V_5 ) != V_32 ) {
V_229 |= V_239 ;
F_197 ( V_5 , V_32 ) ;
}
#endif
F_243 ( V_5 , V_32 ) ;
V_260:
F_224 ( V_5 , V_32 , V_229 ) ;
V_259:
F_66 ( & V_5 -> V_38 , V_75 ) ;
return V_258 ;
}
static void F_246 ( struct V_4 * V_5 )
{
struct V_31 * V_31 = F_28 ( V_5 ) ;
F_138 ( V_31 != F_71 () ) ;
F_138 ( V_5 == V_72 ) ;
F_62 ( & V_31 -> V_39 ) ;
if ( ! F_134 ( & V_5 -> V_38 ) ) {
F_21 ( & V_31 -> V_39 ) ;
F_15 ( & V_5 -> V_38 ) ;
F_15 ( & V_31 -> V_39 ) ;
}
if ( ! ( V_5 -> V_203 & V_263 ) )
goto V_259;
if ( ! V_5 -> V_196 )
F_228 ( V_31 , V_5 , V_251 ) ;
F_230 ( V_31 , V_5 , 0 ) ;
F_224 ( V_5 , F_79 () , 0 ) ;
V_259:
F_21 ( & V_5 -> V_38 ) ;
}
int F_247 ( struct V_4 * V_5 )
{
return F_244 ( V_5 , V_264 , 0 ) ;
}
int F_248 ( struct V_4 * V_5 , unsigned int V_203 )
{
return F_244 ( V_5 , V_203 , 0 ) ;
}
static void F_249 ( struct V_4 * V_5 )
{
V_5 -> V_196 = 0 ;
V_5 -> V_40 . V_196 = 0 ;
V_5 -> V_40 . V_201 = 0 ;
V_5 -> V_40 . V_265 = 0 ;
V_5 -> V_40 . V_266 = 0 ;
V_5 -> V_40 . V_209 = 0 ;
V_5 -> V_40 . V_267 = 0 ;
F_250 ( & V_5 -> V_40 . V_268 ) ;
#ifdef F_225
memset ( & V_5 -> V_40 . V_235 , 0 , sizeof( V_5 -> V_40 . V_235 ) ) ;
#endif
F_250 ( & V_5 -> V_43 . V_269 ) ;
#ifdef F_251
F_252 ( & V_5 -> V_270 ) ;
#endif
}
void F_253 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
int V_32 = F_254 () ;
F_249 ( V_5 ) ;
V_5 -> V_203 = V_204 ;
if ( F_112 ( V_5 -> V_271 ) ) {
if ( V_5 -> V_1 == V_2 || V_5 -> V_1 == V_3 ) {
V_5 -> V_1 = V_272 ;
V_5 -> F_188 = V_5 -> V_148 ;
}
if ( F_255 ( V_5 -> V_148 ) < 0 ) {
V_5 -> V_148 = F_256 ( 0 ) ;
V_5 -> F_188 = V_5 -> V_148 ;
F_148 ( V_5 ) ;
}
V_5 -> V_271 = 0 ;
}
V_5 -> V_147 = V_72 -> F_188 ;
if ( ! F_190 ( V_5 -> V_147 ) )
V_5 -> V_78 = & V_197 ;
if ( V_5 -> V_78 -> V_273 )
V_5 -> V_78 -> V_273 ( V_5 ) ;
F_65 ( & V_5 -> V_38 , V_75 ) ;
F_197 ( V_5 , V_32 ) ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
#if F_177 ( F_225 ) || F_177 ( V_274 )
if ( F_63 ( F_257 () ) )
memset ( & V_5 -> V_275 , 0 , sizeof( V_5 -> V_275 ) ) ;
#endif
#if F_177 ( F_25 )
V_5 -> V_68 = 0 ;
#endif
#ifdef F_258
F_145 ( V_5 ) -> V_206 = 1 ;
#endif
#ifdef F_25
F_259 ( & V_5 -> V_276 , V_277 ) ;
#endif
F_260 () ;
}
void F_261 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
F_65 ( & V_5 -> V_38 , V_75 ) ;
#ifdef F_25
F_197 ( V_5 , F_221 ( V_5 , V_278 , 0 ) ) ;
#endif
V_31 = F_61 ( V_5 ) ;
F_154 ( V_31 , V_5 , 0 ) ;
V_5 -> V_196 = 1 ;
F_262 ( V_5 , true ) ;
F_193 ( V_31 , V_5 , V_279 ) ;
#ifdef F_25
if ( V_5 -> V_78 -> V_247 )
V_5 -> V_78 -> V_247 ( V_31 , V_5 ) ;
#endif
F_68 ( V_31 , V_5 , & V_75 ) ;
}
void F_263 ( struct V_280 * V_281 )
{
F_264 ( & V_281 -> V_282 , & V_72 -> V_270 ) ;
}
void F_265 ( struct V_280 * V_281 )
{
F_266 ( & V_281 -> V_282 ) ;
}
static void F_267 ( struct V_4 * V_67 )
{
struct V_280 * V_281 ;
struct V_283 * V_284 ;
F_268 (notifier, node, &curr->preempt_notifiers, link)
V_281 -> V_285 -> V_286 ( V_281 , F_269 () ) ;
}
static void
F_270 ( struct V_4 * V_67 ,
struct V_4 * V_69 )
{
struct V_280 * V_281 ;
struct V_283 * V_284 ;
F_268 (notifier, node, &curr->preempt_notifiers, link)
V_281 -> V_285 -> V_287 ( V_281 , V_69 ) ;
}
static void F_267 ( struct V_4 * V_67 )
{
}
static void
F_270 ( struct V_4 * V_67 ,
struct V_4 * V_69 )
{
}
static inline void
F_271 ( struct V_31 * V_31 , struct V_4 * V_70 ,
struct V_4 * V_69 )
{
F_272 ( V_70 , V_69 ) ;
F_273 ( V_70 , V_69 ) ;
F_270 ( V_70 , V_69 ) ;
F_53 ( V_31 , V_69 ) ;
F_274 ( V_69 ) ;
F_275 ( V_70 , V_69 ) ;
}
static void F_276 ( struct V_31 * V_31 , struct V_4 * V_70 )
__releases( V_31 -> V_39 )
{
struct V_288 * V_225 = V_31 -> V_289 ;
long V_290 ;
V_31 -> V_289 = NULL ;
V_290 = V_70 -> V_203 ;
F_277 ( V_70 ) ;
#ifdef F_59
F_70 () ;
#endif
F_278 ( V_70 , V_72 ) ;
#ifdef F_59
F_60 () ;
#endif
F_54 ( V_31 , V_70 ) ;
F_267 ( V_72 ) ;
if ( V_225 )
F_279 ( V_225 ) ;
if ( F_112 ( V_290 == V_291 ) ) {
F_280 ( V_70 ) ;
F_281 ( V_70 ) ;
}
}
static inline void F_282 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
if ( V_70 -> V_78 -> F_282 )
V_70 -> V_78 -> F_282 ( V_31 , V_70 ) ;
}
static inline void F_283 ( struct V_31 * V_31 )
{
if ( V_31 -> F_283 ) {
unsigned long V_75 ;
F_65 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_67 -> V_78 -> F_283 )
V_31 -> V_67 -> V_78 -> F_283 ( V_31 ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
V_31 -> F_283 = 0 ;
}
}
static inline void F_282 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
}
static inline void F_283 ( struct V_31 * V_31 )
{
}
T_11 void F_284 ( struct V_4 * V_70 )
__releases( V_31 -> V_39 )
{
struct V_31 * V_31 = F_71 () ;
F_276 ( V_31 , V_70 ) ;
F_283 ( V_31 ) ;
#ifdef F_285
F_210 () ;
#endif
if ( V_72 -> V_292 )
F_286 ( F_287 ( V_72 ) , V_72 -> V_292 ) ;
}
static inline void
F_288 ( struct V_31 * V_31 , struct V_4 * V_70 ,
struct V_4 * V_69 )
{
struct V_288 * V_225 , * V_293 ;
F_271 ( V_31 , V_70 , V_69 ) ;
V_225 = V_69 -> V_225 ;
V_293 = V_70 -> V_294 ;
F_289 ( V_70 ) ;
if ( ! V_225 ) {
V_69 -> V_294 = V_293 ;
F_290 ( & V_293 -> V_295 ) ;
F_291 ( V_293 , V_69 ) ;
} else
F_292 ( V_293 , V_225 , V_69 ) ;
if ( ! V_70 -> V_225 ) {
V_70 -> V_294 = NULL ;
V_31 -> V_289 = V_293 ;
}
#ifndef F_285
F_293 ( & V_31 -> V_39 . V_73 , 1 , V_74 ) ;
#endif
F_294 ( V_70 , V_69 , V_70 ) ;
F_295 () ;
F_276 ( F_71 () , V_70 ) ;
}
unsigned long V_140 ( void )
{
unsigned long V_50 , V_296 = 0 ;
F_296 (i)
V_296 += F_38 ( V_50 ) -> V_140 ;
return V_296 ;
}
unsigned long V_155 ( void )
{
unsigned long V_50 , V_296 = 0 ;
F_297 (i)
V_296 += F_38 ( V_50 ) -> V_155 ;
if ( F_112 ( ( long ) V_296 < 0 ) )
V_296 = 0 ;
return V_296 ;
}
unsigned long long F_298 ( void )
{
int V_50 ;
unsigned long long V_296 = 0 ;
F_297 (i)
V_296 += F_38 ( V_50 ) -> V_297 ;
return V_296 ;
}
unsigned long F_299 ( void )
{
unsigned long V_50 , V_296 = 0 ;
F_297 (i)
V_296 += F_300 ( & F_38 ( V_50 ) -> F_299 ) ;
return V_296 ;
}
unsigned long F_301 ( int V_32 )
{
struct V_31 * V_298 = F_38 ( V_32 ) ;
return F_300 ( & V_298 -> F_299 ) ;
}
unsigned long F_302 ( void )
{
struct V_31 * V_298 = F_71 () ;
return V_298 -> V_138 [ 0 ] ;
}
static long F_303 ( struct V_31 * F_71 )
{
long V_299 , V_27 = 0 ;
V_299 = F_71 -> V_140 ;
V_299 += ( long ) F_71 -> V_155 ;
if ( V_299 != F_71 -> V_300 ) {
V_27 = V_299 - F_71 -> V_300 ;
F_71 -> V_300 = V_299 ;
}
return V_27 ;
}
static unsigned long
F_304 ( unsigned long V_128 , unsigned long exp , unsigned long V_301 )
{
V_128 *= exp ;
V_128 += V_301 * ( V_302 - exp ) ;
V_128 += 1UL << ( V_303 - 1 ) ;
return V_128 >> V_303 ;
}
static void F_305 ( struct V_31 * F_71 )
{
long V_27 ;
V_27 = F_303 ( F_71 ) ;
if ( V_27 )
F_306 ( V_27 , & V_304 ) ;
}
static long F_307 ( void )
{
long V_27 = 0 ;
if ( F_308 ( & V_304 ) )
V_27 = F_309 ( & V_304 , 0 ) ;
return V_27 ;
}
static unsigned long
F_310 ( unsigned long V_305 , unsigned int V_306 , unsigned int V_307 )
{
unsigned long V_308 = 1UL << V_306 ;
if ( V_307 ) for (; ; ) {
if ( V_307 & 1 ) {
V_308 *= V_305 ;
V_308 += 1UL << ( V_306 - 1 ) ;
V_308 >>= V_306 ;
}
V_307 >>= 1 ;
if ( ! V_307 )
break;
V_305 *= V_305 ;
V_305 += 1UL << ( V_306 - 1 ) ;
V_305 >>= V_306 ;
}
return V_308 ;
}
static unsigned long
F_311 ( unsigned long V_128 , unsigned long exp ,
unsigned long V_301 , unsigned int V_307 )
{
return F_304 ( V_128 , F_310 ( exp , V_303 , V_307 ) , V_301 ) ;
}
static void F_312 ( unsigned long V_309 )
{
long V_27 , V_301 , V_307 ;
if ( F_313 ( V_310 , V_311 ) )
return;
V_27 = F_307 () ;
if ( V_27 )
F_306 ( V_27 , & V_312 ) ;
if ( V_309 >= V_313 ) {
V_307 = V_309 / V_313 ;
V_301 = F_308 ( & V_312 ) ;
V_301 = V_301 > 0 ? V_301 * V_302 : 0 ;
V_314 [ 0 ] = F_311 ( V_314 [ 0 ] , V_315 , V_301 , V_307 ) ;
V_314 [ 1 ] = F_311 ( V_314 [ 1 ] , V_316 , V_301 , V_307 ) ;
V_314 [ 2 ] = F_311 ( V_314 [ 2 ] , V_317 , V_301 , V_307 ) ;
V_311 += V_307 * V_313 ;
}
}
static void F_305 ( struct V_31 * F_71 )
{
}
static inline long F_307 ( void )
{
return 0 ;
}
static void F_312 ( unsigned long V_309 )
{
}
void F_314 ( unsigned long * V_318 , unsigned long V_319 , int V_320 )
{
V_318 [ 0 ] = ( V_314 [ 0 ] + V_319 ) << V_320 ;
V_318 [ 1 ] = ( V_314 [ 1 ] + V_319 ) << V_320 ;
V_318 [ 2 ] = ( V_314 [ 2 ] + V_319 ) << V_320 ;
}
void F_315 ( unsigned long V_309 )
{
long V_301 ;
F_312 ( V_309 ) ;
if ( F_313 ( V_310 , V_311 + 10 ) )
return;
V_301 = F_308 ( & V_312 ) ;
V_301 = V_301 > 0 ? V_301 * V_302 : 0 ;
V_314 [ 0 ] = F_304 ( V_314 [ 0 ] , V_315 , V_301 ) ;
V_314 [ 1 ] = F_304 ( V_314 [ 1 ] , V_316 , V_301 ) ;
V_314 [ 2 ] = F_304 ( V_314 [ 2 ] , V_317 , V_301 ) ;
V_311 += V_313 ;
}
static void F_316 ( struct V_31 * F_71 )
{
long V_27 ;
if ( F_313 ( V_310 , F_71 -> V_311 ) )
return;
V_27 = F_303 ( F_71 ) ;
V_27 += F_307 () ;
if ( V_27 )
F_306 ( V_27 , & V_312 ) ;
F_71 -> V_311 += V_313 ;
}
static unsigned long
F_317 ( unsigned long V_128 , unsigned long V_321 , int V_126 )
{
int V_322 = 0 ;
if ( ! V_321 )
return V_128 ;
if ( V_321 >= V_323 [ V_126 ] )
return 0 ;
if ( V_126 == 1 )
return V_128 >> V_321 ;
while ( V_321 ) {
if ( V_321 % 2 )
V_128 = ( V_128 * V_324 [ V_126 ] [ V_322 ] ) >> V_325 ;
V_321 >>= 1 ;
V_322 ++ ;
}
return V_128 ;
}
static void F_318 ( struct V_31 * F_71 )
{
unsigned long V_326 = F_71 -> V_128 . V_110 ;
unsigned long V_327 = V_310 ;
unsigned long V_328 ;
int V_50 , V_329 ;
F_71 -> V_330 ++ ;
if ( V_327 == F_71 -> V_331 )
return;
V_328 = V_327 - F_71 -> V_331 ;
F_71 -> V_331 = V_327 ;
F_71 -> V_138 [ 0 ] = V_326 ;
for ( V_50 = 1 , V_329 = 2 ; V_50 < V_332 ; V_50 ++ , V_329 += V_329 ) {
unsigned long V_333 , V_334 ;
V_333 = F_71 -> V_138 [ V_50 ] ;
V_333 = F_317 ( V_333 , V_328 - 1 , V_50 ) ;
V_334 = V_326 ;
if ( V_334 > V_333 )
V_334 += V_329 - 1 ;
F_71 -> V_138 [ V_50 ] = ( V_333 * ( V_329 - 1 ) + V_334 ) >> V_50 ;
}
F_108 ( F_71 ) ;
}
static void F_319 ( struct V_31 * F_71 )
{
F_318 ( F_71 ) ;
F_316 ( F_71 ) ;
}
void F_320 ( void )
{
struct V_4 * V_5 = V_72 ;
unsigned long V_75 ;
int V_219 ;
F_65 ( & V_5 -> V_38 , V_75 ) ;
V_219 = V_5 -> V_78 -> F_221 ( V_5 , V_335 , 0 ) ;
if ( V_219 == F_79 () )
goto V_103;
if ( F_63 ( F_74 ( V_219 ) ) ) {
struct V_336 V_80 = { V_5 , V_219 } ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
F_321 ( F_93 ( V_5 ) , V_337 , & V_80 ) ;
return;
}
V_103:
F_66 ( & V_5 -> V_38 , V_75 ) ;
}
static T_2 F_322 ( struct V_4 * V_5 , struct V_31 * V_31 )
{
T_2 V_338 = 0 ;
if ( F_51 ( V_31 , V_5 ) ) {
F_33 ( V_31 ) ;
V_338 = V_31 -> V_174 - V_5 -> V_40 . V_201 ;
if ( ( T_3 ) V_338 < 0 )
V_338 = 0 ;
}
return V_338 ;
}
unsigned long long F_323 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
T_2 V_338 = 0 ;
V_31 = F_64 ( V_5 , & V_75 ) ;
V_338 = F_322 ( V_5 , V_31 ) ;
F_68 ( V_31 , V_5 , & V_75 ) ;
return V_338 ;
}
unsigned long long F_324 ( struct V_4 * V_5 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
T_2 V_338 = 0 ;
V_31 = F_64 ( V_5 , & V_75 ) ;
V_338 = V_5 -> V_40 . V_265 + F_322 ( V_5 , V_31 ) ;
F_68 ( V_31 , V_5 , & V_75 ) ;
return V_338 ;
}
void F_325 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_339 )
{
struct V_176 * V_177 = & V_178 . V_177 ;
T_12 V_113 ;
V_5 -> V_340 = F_326 ( V_5 -> V_340 , V_124 ) ;
V_5 -> V_341 = F_326 ( V_5 -> V_341 , V_339 ) ;
F_327 ( V_5 , V_124 ) ;
V_113 = F_328 ( V_124 ) ;
if ( F_329 ( V_5 ) > 0 )
V_177 -> V_342 = F_330 ( V_177 -> V_342 , V_113 ) ;
else
V_177 -> V_343 = F_330 ( V_177 -> V_343 , V_113 ) ;
F_119 ( V_5 , V_344 , V_124 ) ;
F_331 ( V_5 ) ;
}
static void F_332 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_339 )
{
T_12 V_113 ;
struct V_176 * V_177 = & V_178 . V_177 ;
V_113 = F_328 ( V_124 ) ;
V_5 -> V_340 = F_326 ( V_5 -> V_340 , V_124 ) ;
V_5 -> V_341 = F_326 ( V_5 -> V_341 , V_339 ) ;
F_327 ( V_5 , V_124 ) ;
V_5 -> V_345 = F_326 ( V_5 -> V_345 , V_124 ) ;
if ( F_329 ( V_5 ) > 0 ) {
V_177 -> V_342 = F_330 ( V_177 -> V_342 , V_113 ) ;
V_177 -> V_346 = F_330 ( V_177 -> V_346 , V_113 ) ;
} else {
V_177 -> V_343 = F_330 ( V_177 -> V_343 , V_113 ) ;
V_177 -> V_347 = F_330 ( V_177 -> V_347 , V_113 ) ;
}
}
static inline
void F_333 ( struct V_4 * V_5 , T_9 V_124 ,
T_9 V_339 , T_12 * V_348 )
{
T_12 V_113 = F_328 ( V_124 ) ;
V_5 -> V_349 = F_326 ( V_5 -> V_349 , V_124 ) ;
V_5 -> V_350 = F_326 ( V_5 -> V_350 , V_339 ) ;
F_334 ( V_5 , V_124 ) ;
* V_348 = F_330 ( * V_348 , V_113 ) ;
F_119 ( V_5 , V_351 , V_124 ) ;
F_331 ( V_5 ) ;
}
void F_335 ( struct V_4 * V_5 , int V_352 ,
T_9 V_124 , T_9 V_339 )
{
struct V_176 * V_177 = & V_178 . V_177 ;
T_12 * V_348 ;
if ( ( V_5 -> V_75 & V_353 ) && ( F_336 () - V_352 == 0 ) ) {
F_332 ( V_5 , V_124 , V_339 ) ;
return;
}
if ( F_170 () - V_352 )
V_348 = & V_177 -> V_180 ;
else if ( F_171 () )
V_348 = & V_177 -> V_181 ;
else
V_348 = & V_177 -> system ;
F_333 ( V_5 , V_124 , V_339 , V_348 ) ;
}
void F_337 ( T_9 V_124 )
{
struct V_176 * V_177 = & V_178 . V_177 ;
T_12 V_354 = F_328 ( V_124 ) ;
V_177 -> V_164 = F_330 ( V_177 -> V_164 , V_354 ) ;
}
void F_338 ( T_9 V_124 )
{
struct V_176 * V_177 = & V_178 . V_177 ;
T_12 V_354 = F_328 ( V_124 ) ;
struct V_31 * V_31 = F_71 () ;
if ( F_300 ( & V_31 -> F_299 ) > 0 )
V_177 -> V_355 = F_330 ( V_177 -> V_355 , V_354 ) ;
else
V_177 -> V_14 = F_330 ( V_177 -> V_14 , V_354 ) ;
}
static T_13 bool F_339 ( void )
{
#ifdef F_340
if ( F_178 ( & V_356 ) ) {
T_2 V_164 , V_172 = 0 ;
V_164 = F_179 ( F_79 () ) ;
V_164 -= F_71 () -> V_357 ;
V_172 = F_174 ( V_164 ) ;
F_71 () -> V_357 += V_172 * V_166 ;
F_337 ( V_172 ) ;
return V_172 ;
}
#endif
return false ;
}
static void F_341 ( struct V_4 * V_5 , int V_358 ,
struct V_31 * V_31 )
{
T_9 V_359 = F_342 ( V_360 ) ;
T_12 V_113 = F_328 ( V_360 ) ;
struct V_176 * V_177 = & V_178 . V_177 ;
if ( F_339 () )
return;
if ( F_180 () ) {
V_177 -> V_180 = F_330 ( V_177 -> V_180 , V_113 ) ;
} else if ( F_184 () ) {
V_177 -> V_181 = F_330 ( V_177 -> V_181 , V_113 ) ;
} else if ( F_172 () == V_5 ) {
F_333 ( V_5 , V_360 , V_359 ,
& V_177 -> V_181 ) ;
} else if ( V_358 ) {
F_325 ( V_5 , V_360 , V_359 ) ;
} else if ( V_5 == V_31 -> V_14 ) {
F_338 ( V_360 ) ;
} else if ( V_5 -> V_75 & V_353 ) {
F_332 ( V_5 , V_360 , V_359 ) ;
} else {
F_333 ( V_5 , V_360 , V_359 ,
& V_177 -> system ) ;
}
}
static void F_343 ( int V_309 )
{
int V_50 ;
struct V_31 * V_31 = F_71 () ;
for ( V_50 = 0 ; V_50 < V_309 ; V_50 ++ )
F_341 ( V_72 , 0 , V_31 ) ;
}
static void F_343 ( int V_309 ) {}
static void F_341 ( struct V_4 * V_5 , int V_358 ,
struct V_31 * V_31 ) {}
void F_344 ( struct V_4 * V_5 , int V_358 )
{
T_9 V_359 = F_342 ( V_360 ) ;
struct V_31 * V_31 = F_71 () ;
if ( V_156 ) {
F_341 ( V_5 , V_358 , V_31 ) ;
return;
}
if ( F_339 () )
return;
if ( V_358 )
F_325 ( V_5 , V_360 , V_359 ) ;
else if ( ( V_5 != V_31 -> V_14 ) || ( F_336 () != V_361 ) )
F_335 ( V_5 , V_361 , V_360 ,
V_359 ) ;
else
F_338 ( V_360 ) ;
}
void F_345 ( unsigned long V_309 )
{
F_337 ( F_346 ( V_309 ) ) ;
}
void F_347 ( unsigned long V_309 )
{
if ( V_156 ) {
F_343 ( V_309 ) ;
return;
}
F_338 ( F_346 ( V_309 ) ) ;
}
void F_348 ( struct V_4 * V_5 , T_9 * V_362 , T_9 * V_172 )
{
* V_362 = V_5 -> V_340 ;
* V_172 = V_5 -> V_349 ;
}
void F_349 ( struct V_4 * V_5 , T_9 * V_362 , T_9 * V_172 )
{
struct V_363 V_124 ;
F_350 ( V_5 , & V_124 ) ;
* V_362 = V_124 . V_340 ;
* V_172 = V_124 . V_349 ;
}
void F_348 ( struct V_4 * V_5 , T_9 * V_362 , T_9 * V_172 )
{
T_9 V_364 , V_340 = V_5 -> V_340 , V_136 = F_326 ( V_340 , V_5 -> V_349 ) ;
V_364 = F_351 ( V_5 -> V_40 . V_265 ) ;
if ( V_136 ) {
T_2 V_365 = V_364 ;
V_365 *= V_340 ;
F_352 ( V_365 , V_136 ) ;
V_340 = ( T_9 ) V_365 ;
} else
V_340 = V_364 ;
V_5 -> V_366 = F_128 ( V_5 -> V_366 , V_340 ) ;
V_5 -> V_367 = F_128 ( V_5 -> V_367 , F_353 ( V_364 , V_5 -> V_366 ) ) ;
* V_362 = V_5 -> V_366 ;
* V_172 = V_5 -> V_367 ;
}
void F_349 ( struct V_4 * V_5 , T_9 * V_362 , T_9 * V_172 )
{
struct V_368 * V_369 = V_5 -> signal ;
struct V_363 V_124 ;
T_9 V_364 , V_340 , V_136 ;
F_350 ( V_5 , & V_124 ) ;
V_136 = F_326 ( V_124 . V_340 , V_124 . V_349 ) ;
V_364 = F_351 ( V_124 . V_265 ) ;
if ( V_136 ) {
T_2 V_365 = V_364 ;
V_365 *= V_124 . V_340 ;
F_352 ( V_365 , V_136 ) ;
V_340 = ( T_9 ) V_365 ;
} else
V_340 = V_364 ;
V_369 -> V_366 = F_128 ( V_369 -> V_366 , V_340 ) ;
V_369 -> V_367 = F_128 ( V_369 -> V_367 ,
F_353 ( V_364 , V_369 -> V_366 ) ) ;
* V_362 = V_369 -> V_366 ;
* V_172 = V_369 -> V_367 ;
}
void F_354 ( void )
{
int V_32 = F_79 () ;
struct V_31 * V_31 = F_38 ( V_32 ) ;
struct V_4 * V_67 = V_31 -> V_67 ;
F_355 () ;
F_15 ( & V_31 -> V_39 ) ;
F_33 ( V_31 ) ;
F_319 ( V_31 ) ;
V_67 -> V_78 -> V_79 ( V_31 , V_67 , 0 ) ;
F_21 ( & V_31 -> V_39 ) ;
F_356 () ;
#ifdef F_25
V_31 -> V_370 = F_104 ( V_32 ) ;
F_357 ( V_31 , V_32 ) ;
#endif
}
T_14 unsigned long F_358 ( unsigned long V_371 )
{
if ( F_359 ( V_371 ) ) {
V_371 = V_372 ;
if ( F_359 ( V_371 ) )
V_371 = V_373 ;
}
return V_371 ;
}
void T_15 F_360 ( int V_127 )
{
#ifdef F_361
if ( F_362 ( ( V_206 () < 0 ) ) )
return;
#endif
V_206 () += V_127 ;
#ifdef F_361
F_362 ( ( V_206 () & V_374 ) >=
V_374 - 10 ) ;
#endif
if ( V_206 () == V_127 )
F_363 ( V_375 , F_358 ( V_376 ) ) ;
}
void T_15 F_364 ( int V_127 )
{
#ifdef F_361
if ( F_362 ( V_127 > V_206 () ) )
return;
if ( F_362 ( ( V_127 < V_374 ) &&
! ( V_206 () & V_374 ) ) )
return;
#endif
if ( V_206 () == V_127 )
F_365 ( V_375 , F_358 ( V_376 ) ) ;
V_206 () -= V_127 ;
}
static T_16 void F_366 ( struct V_4 * V_70 )
{
struct V_377 * V_378 = F_367 () ;
F_219 ( V_379 L_6 ,
V_70 -> V_227 , V_70 -> V_380 , V_206 () ) ;
F_368 ( V_70 ) ;
F_369 () ;
if ( F_137 () )
F_370 ( V_70 ) ;
if ( V_378 )
F_371 ( V_378 ) ;
else
F_372 () ;
}
static inline void F_373 ( struct V_4 * V_70 )
{
if ( F_112 ( F_374 () && ! V_70 -> V_381 ) )
F_366 ( V_70 ) ;
F_375 ( V_382 , F_376 ( 0 ) ) ;
F_226 ( F_71 () , V_383 ) ;
}
static void F_377 ( struct V_31 * V_31 , struct V_4 * V_70 )
{
if ( V_70 -> V_196 || V_31 -> V_46 < 0 )
F_33 ( V_31 ) ;
V_70 -> V_78 -> F_377 ( V_31 , V_70 ) ;
}
static inline struct V_4 *
F_378 ( struct V_31 * V_31 )
{
const struct V_78 * V_195 ;
struct V_4 * V_5 ;
if ( F_63 ( V_31 -> V_140 == V_31 -> V_384 . V_140 ) ) {
V_5 = V_197 . F_378 ( V_31 ) ;
if ( F_63 ( V_5 ) )
return V_5 ;
}
F_194 (class) {
V_5 = V_195 -> F_378 ( V_31 ) ;
if ( V_5 )
return V_5 ;
}
F_379 () ;
}
static void T_17 F_380 ( void )
{
struct V_4 * V_70 , * V_69 ;
unsigned long * V_385 ;
struct V_31 * V_31 ;
int V_32 ;
V_386:
F_209 () ;
V_32 = F_79 () ;
V_31 = F_38 ( V_32 ) ;
F_381 ( V_32 ) ;
V_70 = V_31 -> V_67 ;
F_373 ( V_70 ) ;
if ( F_73 ( V_76 ) )
F_76 ( V_31 ) ;
F_382 ( & V_31 -> V_39 ) ;
V_385 = & V_70 -> V_387 ;
if ( V_70 -> V_203 && ! ( V_206 () & V_207 ) ) {
if ( F_112 ( F_383 ( V_70 -> V_203 , V_70 ) ) ) {
V_70 -> V_203 = V_204 ;
} else {
F_156 ( V_31 , V_70 , V_388 ) ;
V_70 -> V_196 = 0 ;
if ( V_70 -> V_75 & V_246 ) {
struct V_4 * V_389 ;
V_389 = F_384 ( V_70 , V_32 ) ;
if ( V_389 )
F_246 ( V_389 ) ;
}
}
V_385 = & V_70 -> V_214 ;
}
F_282 ( V_31 , V_70 ) ;
if ( F_112 ( ! V_31 -> V_140 ) )
F_385 ( V_32 , V_31 ) ;
F_377 ( V_31 , V_70 ) ;
V_69 = F_378 ( V_31 ) ;
F_386 ( V_70 ) ;
V_31 -> V_46 = 0 ;
if ( F_63 ( V_70 != V_69 ) ) {
V_31 -> V_297 ++ ;
V_31 -> V_67 = V_69 ;
++ * V_385 ;
F_288 ( V_31 , V_70 , V_69 ) ;
V_32 = F_79 () ;
V_31 = F_38 ( V_32 ) ;
} else
F_58 ( & V_31 -> V_39 ) ;
F_283 ( V_31 ) ;
F_387 () ;
if ( V_386 () )
goto V_386;
}
static inline void F_388 ( struct V_4 * V_123 )
{
if ( ! V_123 -> V_203 )
return;
if ( F_389 ( V_123 ) )
F_390 ( V_123 ) ;
}
T_11 void T_17 F_391 ( void )
{
struct V_4 * V_123 = V_72 ;
F_388 ( V_123 ) ;
F_380 () ;
}
static inline bool F_392 ( struct V_390 * V_39 , struct V_4 * V_71 )
{
if ( V_39 -> V_71 != V_71 )
return false ;
F_295 () ;
return V_71 -> V_68 ;
}
int F_393 ( struct V_390 * V_39 , struct V_4 * V_71 )
{
if ( ! F_73 ( V_391 ) )
return 0 ;
F_101 () ;
while ( F_392 ( V_39 , V_71 ) ) {
if ( V_386 () )
break;
F_394 () ;
}
F_105 () ;
return V_39 -> V_71 == NULL ;
}
T_11 void T_17 T_14 F_395 ( void )
{
struct V_392 * V_393 = F_396 () ;
if ( F_63 ( V_393 -> V_206 || F_137 () ) )
return;
do {
F_397 ( V_207 ) ;
F_380 () ;
F_398 ( V_207 ) ;
F_295 () ;
} while ( V_386 () );
}
T_11 void T_17 F_399 ( void )
{
struct V_392 * V_393 = F_396 () ;
F_138 ( V_393 -> V_206 || ! F_137 () ) ;
do {
F_360 ( V_207 ) ;
F_60 () ;
F_380 () ;
F_70 () ;
F_364 ( V_207 ) ;
F_295 () ;
} while ( V_386 () );
}
int F_400 ( T_18 * V_67 , unsigned V_394 , int V_229 ,
void * V_395 )
{
return F_244 ( V_67 -> V_396 , V_394 , V_229 ) ;
}
static void F_401 ( T_19 * V_397 , unsigned int V_394 ,
int V_398 , int V_229 , void * V_395 )
{
T_18 * V_67 , * V_69 ;
F_402 (curr, next, &q->task_list, task_list) {
unsigned V_75 = V_67 -> V_75 ;
if ( V_67 -> V_99 ( V_67 , V_394 , V_229 , V_395 ) &&
( V_75 & V_399 ) && ! -- V_398 )
break;
}
}
void F_403 ( T_19 * V_397 , unsigned int V_394 ,
int V_398 , void * V_395 )
{
unsigned long V_75 ;
F_404 ( & V_397 -> V_39 , V_75 ) ;
F_401 ( V_397 , V_394 , V_398 , 0 , V_395 ) ;
F_405 ( & V_397 -> V_39 , V_75 ) ;
}
void F_406 ( T_19 * V_397 , unsigned int V_394 )
{
F_401 ( V_397 , V_394 , 1 , 0 , NULL ) ;
}
void F_407 ( T_19 * V_397 , unsigned int V_394 , void * V_395 )
{
F_401 ( V_397 , V_394 , 1 , 0 , V_395 ) ;
}
void F_408 ( T_19 * V_397 , unsigned int V_394 ,
int V_398 , void * V_395 )
{
unsigned long V_75 ;
int V_229 = V_243 ;
if ( F_112 ( ! V_397 ) )
return;
if ( F_112 ( ! V_398 ) )
V_229 = 0 ;
F_404 ( & V_397 -> V_39 , V_75 ) ;
F_401 ( V_397 , V_394 , V_398 , V_229 , V_395 ) ;
F_405 ( & V_397 -> V_39 , V_75 ) ;
}
void F_409 ( T_19 * V_397 , unsigned int V_394 , int V_398 )
{
F_408 ( V_397 , V_394 , V_398 , NULL ) ;
}
void F_410 ( struct V_400 * V_305 )
{
unsigned long V_75 ;
F_404 ( & V_305 -> V_401 . V_39 , V_75 ) ;
V_305 -> V_402 ++ ;
F_401 ( & V_305 -> V_401 , V_263 , 1 , 0 , NULL ) ;
F_405 ( & V_305 -> V_401 . V_39 , V_75 ) ;
}
void F_411 ( struct V_400 * V_305 )
{
unsigned long V_75 ;
F_404 ( & V_305 -> V_401 . V_39 , V_75 ) ;
V_305 -> V_402 += V_403 / 2 ;
F_401 ( & V_305 -> V_401 , V_263 , 0 , 0 , NULL ) ;
F_405 ( & V_305 -> V_401 . V_39 , V_75 ) ;
}
static inline long T_17
F_412 ( struct V_400 * V_305 , long V_404 , int V_203 )
{
if ( ! V_305 -> V_402 ) {
F_413 ( V_401 , V_72 ) ;
F_414 ( & V_305 -> V_401 , & V_401 ) ;
do {
if ( F_383 ( V_203 , V_72 ) ) {
V_404 = - V_405 ;
break;
}
F_415 ( V_203 ) ;
F_416 ( & V_305 -> V_401 . V_39 ) ;
V_404 = F_417 ( V_404 ) ;
F_418 ( & V_305 -> V_401 . V_39 ) ;
} while ( ! V_305 -> V_402 && V_404 );
F_419 ( & V_305 -> V_401 , & V_401 ) ;
if ( ! V_305 -> V_402 )
return V_404 ;
}
V_305 -> V_402 -- ;
return V_404 ? : 1 ;
}
static long T_17
F_420 ( struct V_400 * V_305 , long V_404 , int V_203 )
{
F_421 () ;
F_418 ( & V_305 -> V_401 . V_39 ) ;
V_404 = F_412 ( V_305 , V_404 , V_203 ) ;
F_416 ( & V_305 -> V_401 . V_39 ) ;
return V_404 ;
}
void T_17 F_422 ( struct V_400 * V_305 )
{
F_420 ( V_305 , V_406 , V_218 ) ;
}
unsigned long T_17
F_423 ( struct V_400 * V_305 , unsigned long V_404 )
{
return F_420 ( V_305 , V_404 , V_218 ) ;
}
int T_17 F_424 ( struct V_400 * V_305 )
{
long V_407 = F_420 ( V_305 , V_406 , V_408 ) ;
if ( V_407 == - V_405 )
return V_407 ;
return 0 ;
}
long T_17
F_425 ( struct V_400 * V_305 ,
unsigned long V_404 )
{
return F_420 ( V_305 , V_404 , V_408 ) ;
}
int T_17 F_426 ( struct V_400 * V_305 )
{
long V_407 = F_420 ( V_305 , V_406 , V_409 ) ;
if ( V_407 == - V_405 )
return V_407 ;
return 0 ;
}
long T_17
F_427 ( struct V_400 * V_305 ,
unsigned long V_404 )
{
return F_420 ( V_305 , V_404 , V_409 ) ;
}
bool F_428 ( struct V_400 * V_305 )
{
unsigned long V_75 ;
int V_133 = 1 ;
F_404 ( & V_305 -> V_401 . V_39 , V_75 ) ;
if ( ! V_305 -> V_402 )
V_133 = 0 ;
else
V_305 -> V_402 -- ;
F_405 ( & V_305 -> V_401 . V_39 , V_75 ) ;
return V_133 ;
}
bool F_429 ( struct V_400 * V_305 )
{
unsigned long V_75 ;
int V_133 = 1 ;
F_404 ( & V_305 -> V_401 . V_39 , V_75 ) ;
if ( ! V_305 -> V_402 )
V_133 = 0 ;
F_405 ( & V_305 -> V_401 . V_39 , V_75 ) ;
return V_133 ;
}
static long T_17
F_430 ( T_19 * V_397 , int V_203 , long V_404 )
{
unsigned long V_75 ;
T_18 V_401 ;
F_431 ( & V_401 , V_72 ) ;
F_415 ( V_203 ) ;
F_404 ( & V_397 -> V_39 , V_75 ) ;
F_432 ( V_397 , & V_401 ) ;
F_433 ( & V_397 -> V_39 ) ;
V_404 = F_417 ( V_404 ) ;
F_418 ( & V_397 -> V_39 ) ;
F_419 ( V_397 , & V_401 ) ;
F_405 ( & V_397 -> V_39 , V_75 ) ;
return V_404 ;
}
void T_17 F_434 ( T_19 * V_397 )
{
F_430 ( V_397 , V_408 , V_406 ) ;
}
long T_17
F_435 ( T_19 * V_397 , long V_404 )
{
return F_430 ( V_397 , V_408 , V_404 ) ;
}
void T_17 F_436 ( T_19 * V_397 )
{
F_430 ( V_397 , V_218 , V_406 ) ;
}
long T_17 F_437 ( T_19 * V_397 , long V_404 )
{
return F_430 ( V_397 , V_218 , V_404 ) ;
}
void F_438 ( struct V_4 * V_5 , int V_147 )
{
int V_191 , V_196 , V_212 ;
struct V_31 * V_31 ;
const struct V_78 * V_190 ;
F_138 ( V_147 < 0 || V_147 > V_277 ) ;
V_31 = F_61 ( V_5 ) ;
F_439 ( V_5 , V_147 ) ;
V_191 = V_5 -> V_147 ;
V_190 = V_5 -> V_78 ;
V_196 = V_5 -> V_196 ;
V_212 = F_51 ( V_31 , V_5 ) ;
if ( V_196 )
F_152 ( V_31 , V_5 , 0 ) ;
if ( V_212 )
V_5 -> V_78 -> F_377 ( V_31 , V_5 ) ;
if ( F_190 ( V_147 ) )
V_5 -> V_78 = & V_188 ;
else
V_5 -> V_78 = & V_197 ;
V_5 -> V_147 = V_147 ;
if ( V_212 )
V_5 -> V_78 -> V_410 ( V_31 ) ;
if ( V_196 )
F_150 ( V_31 , V_5 , V_191 < V_147 ? V_411 : 0 ) ;
F_192 ( V_31 , V_5 , V_190 , V_191 ) ;
F_67 ( V_31 ) ;
}
void F_440 ( struct V_4 * V_5 , long V_342 )
{
int V_412 , V_27 , V_196 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
if ( F_329 ( V_5 ) == V_342 || V_342 < - 20 || V_342 > 19 )
return;
V_31 = F_64 ( V_5 , & V_75 ) ;
if ( F_2 ( V_5 ) ) {
V_5 -> V_148 = F_256 ( V_342 ) ;
goto V_135;
}
V_196 = V_5 -> V_196 ;
if ( V_196 )
F_152 ( V_31 , V_5 , 0 ) ;
V_5 -> V_148 = F_256 ( V_342 ) ;
F_148 ( V_5 ) ;
V_412 = V_5 -> V_147 ;
V_5 -> V_147 = F_189 ( V_5 ) ;
V_27 = V_5 -> V_147 - V_412 ;
if ( V_196 ) {
F_150 ( V_31 , V_5 , 0 ) ;
if ( V_27 < 0 || ( V_27 > 0 && F_52 ( V_31 , V_5 ) ) )
F_89 ( V_31 -> V_67 ) ;
}
V_135:
F_68 ( V_31 , V_5 , & V_75 ) ;
}
int F_441 ( const struct V_4 * V_5 , const int V_342 )
{
int V_413 = 20 - V_342 ;
return ( V_413 <= F_442 ( V_5 , V_414 ) ||
F_443 ( V_415 ) ) ;
}
int F_444 ( const struct V_4 * V_5 )
{
return V_5 -> V_147 - V_149 ;
}
int F_445 ( const struct V_4 * V_5 )
{
return F_329 ( V_5 ) ;
}
int F_104 ( int V_32 )
{
return F_99 ( V_32 ) == F_38 ( V_32 ) -> V_14 ;
}
struct V_4 * F_446 ( int V_32 )
{
return F_38 ( V_32 ) -> V_14 ;
}
static struct V_4 * F_447 ( T_20 V_380 )
{
return V_380 ? F_448 ( V_380 ) : V_72 ;
}
static void
F_449 ( struct V_31 * V_31 , struct V_4 * V_5 , int V_1 , int V_147 )
{
V_5 -> V_1 = V_1 ;
V_5 -> V_189 = V_147 ;
V_5 -> F_188 = F_188 ( V_5 ) ;
V_5 -> V_147 = F_450 ( V_5 ) ;
if ( F_190 ( V_5 -> V_147 ) )
V_5 -> V_78 = & V_188 ;
else
V_5 -> V_78 = & V_197 ;
F_148 ( V_5 ) ;
}
static bool F_451 ( struct V_4 * V_5 )
{
const struct V_416 * V_416 = F_452 () , * V_417 ;
bool V_418 ;
F_101 () ;
V_417 = F_453 ( V_5 ) ;
if ( V_416 -> V_343 -> V_419 == V_417 -> V_343 -> V_419 )
V_418 = ( V_416 -> V_420 == V_417 -> V_420 ||
V_416 -> V_420 == V_417 -> V_421 ) ;
else
V_418 = false ;
F_105 () ;
return V_418 ;
}
static int F_454 ( struct V_4 * V_5 , int V_1 ,
const struct V_183 * V_184 , bool V_343 )
{
int V_422 , V_191 , V_423 = - 1 , V_196 , V_212 ;
unsigned long V_75 ;
const struct V_78 * V_190 ;
struct V_31 * V_31 ;
int V_424 ;
F_138 ( F_455 () ) ;
V_425:
if ( V_1 < 0 ) {
V_424 = V_5 -> V_271 ;
V_1 = V_423 = V_5 -> V_1 ;
} else {
V_424 = ! ! ( V_1 & V_426 ) ;
V_1 &= ~ V_426 ;
if ( V_1 != V_2 && V_1 != V_3 &&
V_1 != V_272 && V_1 != V_427 &&
V_1 != V_150 )
return - V_62 ;
}
if ( V_184 -> V_185 < 0 ||
( V_5 -> V_225 && V_184 -> V_185 > V_428 - 1 ) ||
( ! V_5 -> V_225 && V_184 -> V_185 > V_149 - 1 ) )
return - V_62 ;
if ( F_1 ( V_1 ) != ( V_184 -> V_185 != 0 ) )
return - V_62 ;
if ( V_343 && ! F_443 ( V_415 ) ) {
if ( F_1 ( V_1 ) ) {
unsigned long V_429 =
F_442 ( V_5 , V_430 ) ;
if ( V_1 != V_5 -> V_1 && ! V_429 )
return - V_431 ;
if ( V_184 -> V_185 > V_5 -> V_189 &&
V_184 -> V_185 > V_429 )
return - V_431 ;
}
if ( V_5 -> V_1 == V_150 && V_1 != V_150 ) {
if ( ! F_441 ( V_5 , F_329 ( V_5 ) ) )
return - V_431 ;
}
if ( ! F_451 ( V_5 ) )
return - V_431 ;
if ( V_5 -> V_271 && ! V_424 )
return - V_431 ;
}
if ( V_343 ) {
V_422 = F_456 ( V_5 ) ;
if ( V_422 )
return V_422 ;
}
V_31 = F_64 ( V_5 , & V_75 ) ;
if ( V_5 == V_31 -> V_182 ) {
F_68 ( V_31 , V_5 , & V_75 ) ;
return - V_62 ;
}
if ( F_112 ( V_1 == V_5 -> V_1 && ( ! F_1 ( V_1 ) ||
V_184 -> V_185 == V_5 -> V_189 ) ) ) {
F_67 ( V_31 ) ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
return 0 ;
}
#ifdef F_32
if ( V_343 ) {
if ( F_12 () && F_1 ( V_1 ) &&
V_33 ( V_5 ) -> V_9 . V_20 == 0 &&
! F_457 ( V_33 ( V_5 ) ) ) {
F_68 ( V_31 , V_5 , & V_75 ) ;
return - V_431 ;
}
}
#endif
if ( F_112 ( V_423 != - 1 && V_423 != V_5 -> V_1 ) ) {
V_1 = V_423 = - 1 ;
F_68 ( V_31 , V_5 , & V_75 ) ;
goto V_425;
}
V_196 = V_5 -> V_196 ;
V_212 = F_51 ( V_31 , V_5 ) ;
if ( V_196 )
F_156 ( V_31 , V_5 , 0 ) ;
if ( V_212 )
V_5 -> V_78 -> F_377 ( V_31 , V_5 ) ;
V_5 -> V_271 = V_424 ;
V_191 = V_5 -> V_147 ;
V_190 = V_5 -> V_78 ;
F_449 ( V_31 , V_5 , V_1 , V_184 -> V_185 ) ;
if ( V_212 )
V_5 -> V_78 -> V_410 ( V_31 ) ;
if ( V_196 )
F_154 ( V_31 , V_5 , 0 ) ;
F_192 ( V_31 , V_5 , V_190 , V_191 ) ;
F_68 ( V_31 , V_5 , & V_75 ) ;
F_458 ( V_5 ) ;
return 0 ;
}
int F_459 ( struct V_4 * V_5 , int V_1 ,
const struct V_183 * V_184 )
{
return F_454 ( V_5 , V_1 , V_184 , true ) ;
}
int F_186 ( struct V_4 * V_5 , int V_1 ,
const struct V_183 * V_184 )
{
return F_454 ( V_5 , V_1 , V_184 , false ) ;
}
static int
F_460 ( T_20 V_380 , int V_1 , struct V_183 T_5 * V_184 )
{
struct V_183 V_432 ;
struct V_4 * V_5 ;
int V_422 ;
if ( ! V_184 || V_380 < 0 )
return - V_62 ;
if ( F_43 ( & V_432 , V_184 , sizeof( struct V_183 ) ) )
return - V_61 ;
F_101 () ;
V_422 = - V_433 ;
V_5 = F_447 ( V_380 ) ;
if ( V_5 != NULL )
V_422 = F_459 ( V_5 , V_1 , & V_432 ) ;
F_105 () ;
return V_422 ;
}
long F_461 ( T_20 V_380 , const struct V_220 * V_434 )
{
T_21 V_222 , V_435 ;
struct V_4 * V_5 ;
int V_422 ;
F_462 () ;
F_101 () ;
V_5 = F_447 ( V_380 ) ;
if ( ! V_5 ) {
F_105 () ;
F_463 () ;
return - V_433 ;
}
F_464 ( V_5 ) ;
F_105 () ;
if ( ! F_465 ( & V_222 , V_436 ) ) {
V_422 = - V_437 ;
goto V_438;
}
if ( ! F_465 ( & V_435 , V_436 ) ) {
V_422 = - V_437 ;
goto V_439;
}
V_422 = - V_431 ;
if ( ! F_451 ( V_5 ) && ! F_466 ( V_5 , V_415 ) )
goto V_135;
V_422 = F_456 ( V_5 ) ;
if ( V_422 )
goto V_135;
F_467 ( V_5 , V_222 ) ;
F_468 ( V_435 , V_434 , V_222 ) ;
V_440:
V_422 = F_469 ( V_5 , V_435 ) ;
if ( ! V_422 ) {
F_467 ( V_5 , V_222 ) ;
if ( ! F_470 ( V_435 , V_222 ) ) {
F_471 ( V_435 , V_222 ) ;
goto V_440;
}
}
V_135:
F_472 ( V_435 ) ;
V_439:
F_472 ( V_222 ) ;
V_438:
F_281 ( V_5 ) ;
F_463 () ;
return V_422 ;
}
static int F_473 ( unsigned long T_5 * V_441 , unsigned V_442 ,
struct V_220 * V_435 )
{
if ( V_442 < F_474 () )
F_475 ( V_435 ) ;
else if ( V_442 > F_474 () )
V_442 = F_474 () ;
return F_43 ( V_435 , V_441 , V_442 ) ? - V_61 : 0 ;
}
long F_476 ( T_20 V_380 , struct V_220 * V_443 )
{
struct V_4 * V_5 ;
unsigned long V_75 ;
int V_422 ;
F_462 () ;
F_101 () ;
V_422 = - V_433 ;
V_5 = F_447 ( V_380 ) ;
if ( ! V_5 )
goto V_135;
V_422 = F_477 ( V_5 ) ;
if ( V_422 )
goto V_135;
F_65 ( & V_5 -> V_38 , V_75 ) ;
F_468 ( V_443 , & V_5 -> V_222 , V_444 ) ;
F_66 ( & V_5 -> V_38 , V_75 ) ;
V_135:
F_105 () ;
F_463 () ;
return V_422 ;
}
static inline int F_478 ( void )
{
return V_386 () && ! ( V_206 () & V_207 ) ;
}
static void F_479 ( void )
{
F_360 ( V_207 ) ;
F_380 () ;
F_364 ( V_207 ) ;
}
int T_17 F_480 ( void )
{
if ( F_478 () ) {
F_479 () ;
return 1 ;
}
return 0 ;
}
int F_481 ( T_22 * V_39 )
{
int V_445 = F_478 () ;
int V_133 = 0 ;
F_62 ( V_39 ) ;
if ( F_482 ( V_39 ) || V_445 ) {
F_433 ( V_39 ) ;
if ( V_445 )
F_479 () ;
else
F_203 () ;
V_133 = 1 ;
F_483 ( V_39 ) ;
}
return V_133 ;
}
int T_17 F_484 ( void )
{
F_138 ( ! F_485 () ) ;
if ( F_478 () ) {
F_486 () ;
F_479 () ;
F_487 () ;
return 1 ;
}
return 0 ;
}
void T_17 F_488 ( void )
{
F_206 ( V_204 ) ;
F_489 () ;
}
bool T_17 F_490 ( struct V_4 * V_5 , bool V_446 )
{
struct V_4 * V_67 = V_72 ;
struct V_31 * V_31 , * V_447 ;
unsigned long V_75 ;
bool V_448 = 0 ;
F_167 ( V_75 ) ;
V_31 = F_71 () ;
V_440:
V_447 = F_28 ( V_5 ) ;
F_133 ( V_31 , V_447 ) ;
while ( F_28 ( V_5 ) != V_447 ) {
F_142 ( V_31 , V_447 ) ;
goto V_440;
}
if ( ! V_67 -> V_78 -> V_449 )
goto V_259;
if ( V_67 -> V_78 != V_5 -> V_78 )
goto V_259;
if ( F_52 ( V_447 , V_5 ) || V_5 -> V_203 )
goto V_259;
V_448 = V_67 -> V_78 -> V_449 ( V_31 , V_5 , V_446 ) ;
if ( V_448 ) {
F_226 ( V_31 , V_450 ) ;
if ( V_446 && V_31 != V_447 )
F_89 ( V_447 -> V_67 ) ;
}
V_259:
F_142 ( V_31 , V_447 ) ;
F_173 ( V_75 ) ;
if ( V_448 )
F_391 () ;
return V_448 ;
}
void T_17 F_491 ( void )
{
struct V_31 * V_31 = F_492 () ;
F_493 () ;
F_290 ( & V_31 -> F_299 ) ;
F_494 ( V_72 ) ;
V_72 -> V_451 = 1 ;
F_391 () ;
V_72 -> V_451 = 0 ;
F_495 ( & V_31 -> F_299 ) ;
F_496 () ;
}
long T_17 F_497 ( long V_404 )
{
struct V_31 * V_31 = F_492 () ;
long V_133 ;
F_493 () ;
F_290 ( & V_31 -> F_299 ) ;
F_494 ( V_72 ) ;
V_72 -> V_451 = 1 ;
V_133 = F_417 ( V_404 ) ;
V_72 -> V_451 = 0 ;
F_495 ( & V_31 -> F_299 ) ;
F_496 () ;
return V_133 ;
}
void F_498 ( struct V_4 * V_5 )
{
unsigned long free = 0 ;
unsigned V_203 ;
V_203 = V_5 -> V_203 ? F_499 ( V_5 -> V_203 ) + 1 : 0 ;
F_219 ( V_226 L_7 , V_5 -> V_227 ,
V_203 < sizeof( V_452 ) - 1 ? V_452 [ V_203 ] : '?' ) ;
#if V_117 == 32
if ( V_203 == V_204 )
F_219 ( V_453 L_8 ) ;
else
F_219 ( V_453 L_9 , F_500 ( V_5 ) ) ;
#else
if ( V_203 == V_204 )
F_219 ( V_453 L_10 ) ;
else
F_219 ( V_453 L_11 , F_500 ( V_5 ) ) ;
#endif
#ifdef F_501
free = F_502 ( V_5 ) ;
#endif
F_219 ( V_453 L_12 , free ,
F_220 ( V_5 ) , F_220 ( V_5 -> V_454 ) ,
( unsigned long ) F_145 ( V_5 ) -> V_75 ) ;
F_503 ( V_5 , NULL ) ;
}
void F_504 ( unsigned long V_455 )
{
struct V_4 * V_456 , * V_5 ;
#if V_117 == 32
F_219 ( V_226
L_13 ) ;
#else
F_219 ( V_226
L_14 ) ;
#endif
F_505 ( & V_457 ) ;
F_506 (g, p) {
F_507 () ;
if ( ! V_455 || ( V_5 -> V_203 & V_455 ) )
F_498 ( V_5 ) ;
} F_508 ( V_456 , V_5 ) ;
F_509 () ;
#ifdef F_198
F_510 () ;
#endif
F_511 ( & V_457 ) ;
if ( ! V_455 )
F_512 () ;
}
void T_23 F_513 ( struct V_4 * V_14 )
{
V_14 -> V_78 = & V_458 ;
}
void T_23 F_514 ( struct V_4 * V_14 , int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_75 ;
F_65 ( & V_31 -> V_39 , V_75 ) ;
F_249 ( V_14 ) ;
V_14 -> V_203 = V_204 ;
V_14 -> V_40 . V_201 = F_515 () ;
F_516 ( V_14 , F_517 ( V_32 ) ) ;
F_101 () ;
F_144 ( V_14 , V_32 ) ;
F_105 () ;
V_31 -> V_67 = V_31 -> V_14 = V_14 ;
#if F_177 ( F_25 )
V_14 -> V_68 = 1 ;
#endif
F_66 ( & V_31 -> V_39 , V_75 ) ;
F_145 ( V_14 ) -> V_206 = 0 ;
V_14 -> V_78 = & V_458 ;
F_518 ( V_14 , V_32 ) ;
}
static int F_519 ( void )
{
unsigned int V_459 = F_520 ( int , F_521 () , 8 ) ;
unsigned int V_460 ;
switch ( V_461 ) {
case V_462 :
V_460 = 1 ;
break;
case V_463 :
V_460 = V_459 ;
break;
case V_464 :
default:
V_460 = 1 + F_522 ( V_459 ) ;
break;
}
return V_460 ;
}
static void F_523 ( void )
{
unsigned int V_460 = F_519 () ;
#define F_524 ( T_24 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_524 ( V_465 ) ;
F_524 ( V_466 ) ;
F_524 ( V_467 ) ;
#undef F_524
}
static inline void F_525 ( void )
{
F_523 () ;
}
void F_516 ( struct V_4 * V_5 , const struct V_220 * V_435 )
{
if ( V_5 -> V_78 && V_5 -> V_78 -> V_468 )
V_5 -> V_78 -> V_468 ( V_5 , V_435 ) ;
else {
F_471 ( & V_5 -> V_222 , V_435 ) ;
V_5 -> V_43 . V_469 = F_526 ( V_435 ) ;
}
}
int F_469 ( struct V_4 * V_5 , const struct V_220 * V_435 )
{
unsigned long V_75 ;
struct V_31 * V_31 ;
unsigned int V_219 ;
int V_133 = 0 ;
V_31 = F_64 ( V_5 , & V_75 ) ;
if ( F_527 ( & V_5 -> V_222 , V_435 ) )
goto V_259;
if ( ! F_528 ( V_435 , V_223 ) ) {
V_133 = - V_62 ;
goto V_259;
}
if ( F_112 ( ( V_5 -> V_75 & V_470 ) && V_5 != V_72 ) ) {
V_133 = - V_62 ;
goto V_259;
}
F_516 ( V_5 , V_435 ) ;
if ( F_215 ( F_93 ( V_5 ) , V_435 ) )
goto V_259;
V_219 = F_216 ( V_223 , V_435 ) ;
if ( V_5 -> V_196 ) {
struct V_336 V_80 = { V_5 , V_219 } ;
F_68 ( V_31 , V_5 , & V_75 ) ;
F_321 ( F_24 ( V_31 ) , V_337 , & V_80 ) ;
F_529 ( V_5 -> V_225 ) ;
return 0 ;
}
V_259:
F_68 ( V_31 , V_5 , & V_75 ) ;
return V_133 ;
}
static int F_530 ( struct V_4 * V_5 , int V_471 , int V_219 )
{
struct V_31 * V_472 , * V_473 ;
int V_133 = 0 ;
if ( F_112 ( ! F_74 ( V_219 ) ) )
return V_133 ;
V_473 = F_38 ( V_471 ) ;
V_472 = F_38 ( V_219 ) ;
F_15 ( & V_5 -> V_38 ) ;
F_133 ( V_473 , V_472 ) ;
if ( F_93 ( V_5 ) != V_471 )
goto V_402;
if ( ! F_215 ( V_219 , & V_5 -> V_222 ) )
goto V_474;
if ( V_5 -> V_196 ) {
F_156 ( V_473 , V_5 , 0 ) ;
F_197 ( V_5 , V_219 ) ;
F_154 ( V_472 , V_5 , 0 ) ;
F_193 ( V_472 , V_5 , 0 ) ;
}
V_402:
V_133 = 1 ;
V_474:
F_142 ( V_473 , V_472 ) ;
F_21 ( & V_5 -> V_38 ) ;
return V_133 ;
}
static int V_337 ( void * V_131 )
{
struct V_336 * V_80 = V_131 ;
F_70 () ;
F_530 ( V_80 -> V_475 , F_269 () , V_80 -> V_219 ) ;
F_60 () ;
return 0 ;
}
void F_531 ( void )
{
struct V_288 * V_225 = V_72 -> V_294 ;
F_138 ( F_222 ( F_79 () ) ) ;
if ( V_225 != & V_476 )
F_292 ( V_225 , & V_476 , V_72 ) ;
F_279 ( V_225 ) ;
}
static void F_532 ( struct V_31 * V_473 )
{
struct V_31 * V_472 = F_38 ( F_533 ( V_223 ) ) ;
V_472 -> V_155 += V_473 -> V_155 ;
V_473 -> V_155 = 0 ;
}
static void F_534 ( struct V_31 * V_31 )
{
F_535 ( V_31 -> V_300 , & V_312 ) ;
V_31 -> V_300 = 0 ;
}
static void F_536 ( unsigned int V_477 )
{
struct V_31 * V_31 = F_38 ( V_477 ) ;
struct V_4 * V_69 , * V_182 = V_31 -> V_182 ;
int V_219 ;
V_31 -> V_182 = NULL ;
for ( ; ; ) {
if ( V_31 -> V_140 == 1 )
break;
V_69 = F_378 ( V_31 ) ;
F_138 ( ! V_69 ) ;
V_69 -> V_78 -> F_377 ( V_31 , V_69 ) ;
V_219 = F_211 ( V_477 , V_69 ) ;
F_21 ( & V_31 -> V_39 ) ;
F_530 ( V_69 , V_477 , V_219 ) ;
F_15 ( & V_31 -> V_39 ) ;
}
V_31 -> V_182 = V_182 ;
}
static struct V_478 * F_537 ( int V_307 )
{
struct V_478 * V_479 =
F_538 ( V_307 , sizeof( struct V_478 ) , V_436 ) ;
return V_479 ;
}
static void F_539 ( struct V_478 * * V_480 )
{
struct V_478 * V_479 ;
for ( V_479 = * V_480 ; V_479 -> V_394 ; V_479 ++ ) {
if ( V_479 -> V_132 )
F_539 ( & V_479 -> V_132 ) ;
if ( V_479 -> V_481 == NULL )
F_540 ( V_479 -> V_482 ) ;
}
F_540 ( * V_480 ) ;
* V_480 = NULL ;
}
static void
F_541 ( struct V_478 * V_479 ,
const char * V_482 , void * V_131 , int V_483 ,
T_25 V_394 , V_481 * V_481 )
{
V_479 -> V_482 = V_482 ;
V_479 -> V_131 = V_131 ;
V_479 -> V_483 = V_483 ;
V_479 -> V_394 = V_394 ;
V_479 -> V_481 = V_481 ;
}
static struct V_478 *
F_542 ( struct V_101 * V_102 )
{
struct V_478 * V_484 = F_537 ( 13 ) ;
if ( V_484 == NULL )
return NULL ;
F_541 ( & V_484 [ 0 ] , L_15 , & V_102 -> V_485 ,
sizeof( long ) , 0644 , V_486 ) ;
F_541 ( & V_484 [ 1 ] , L_16 , & V_102 -> V_487 ,
sizeof( long ) , 0644 , V_486 ) ;
F_541 ( & V_484 [ 2 ] , L_17 , & V_102 -> V_488 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 3 ] , L_18 , & V_102 -> V_490 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 4 ] , L_19 , & V_102 -> V_491 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 5 ] , L_20 , & V_102 -> V_492 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 6 ] , L_21 , & V_102 -> V_493 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 7 ] , L_22 , & V_102 -> V_494 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 8 ] , L_23 , & V_102 -> V_495 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 9 ] , L_24 ,
& V_102 -> V_496 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 10 ] , L_25 , & V_102 -> V_75 ,
sizeof( int ) , 0644 , V_489 ) ;
F_541 ( & V_484 [ 11 ] , L_26 , V_102 -> T_24 ,
V_497 , 0444 , V_498 ) ;
return V_484 ;
}
static V_478 * F_543 ( int V_32 )
{
struct V_478 * V_479 , * V_484 ;
struct V_101 * V_102 ;
int V_499 = 0 , V_50 ;
char V_58 [ 32 ] ;
F_102 (cpu, sd)
V_499 ++ ;
V_479 = V_484 = F_537 ( V_499 + 1 ) ;
if ( V_484 == NULL )
return NULL ;
V_50 = 0 ;
F_102 (cpu, sd) {
snprintf ( V_58 , 32 , L_27 , V_50 ) ;
V_479 -> V_482 = F_544 ( V_58 , V_436 ) ;
V_479 -> V_394 = 0555 ;
V_479 -> V_132 = F_542 ( V_102 ) ;
V_479 ++ ;
V_50 ++ ;
}
return V_484 ;
}
static void F_545 ( void )
{
int V_50 , V_500 = F_546 () ;
struct V_478 * V_479 = F_537 ( V_500 + 1 ) ;
char V_58 [ 32 ] ;
F_547 ( V_501 [ 0 ] . V_132 ) ;
V_501 [ 0 ] . V_132 = V_479 ;
if ( V_479 == NULL )
return;
F_297 (i) {
snprintf ( V_58 , 32 , L_28 , V_50 ) ;
V_479 -> V_482 = F_544 ( V_58 , V_436 ) ;
V_479 -> V_394 = 0555 ;
V_479 -> V_132 = F_543 ( V_50 ) ;
V_479 ++ ;
}
F_547 ( V_502 ) ;
V_502 = F_548 ( V_503 ) ;
}
static void F_549 ( void )
{
if ( V_502 )
F_550 ( V_502 ) ;
V_502 = NULL ;
if ( V_501 [ 0 ] . V_132 )
F_539 ( & V_501 [ 0 ] . V_132 ) ;
}
static void F_545 ( void )
{
}
static void F_549 ( void )
{
}
static void F_551 ( struct V_31 * V_31 )
{
if ( ! V_31 -> V_504 ) {
const struct V_78 * V_195 ;
F_552 ( V_31 -> V_32 , V_31 -> V_505 -> V_504 ) ;
V_31 -> V_504 = 1 ;
F_194 (class) {
if ( V_195 -> V_506 )
V_195 -> V_506 ( V_31 ) ;
}
}
}
static void F_553 ( struct V_31 * V_31 )
{
if ( V_31 -> V_504 ) {
const struct V_78 * V_195 ;
F_194 (class) {
if ( V_195 -> V_507 )
V_195 -> V_507 ( V_31 ) ;
}
F_554 ( V_31 -> V_32 , V_31 -> V_505 -> V_504 ) ;
V_31 -> V_504 = 0 ;
}
}
static int T_23
F_555 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
int V_32 = ( long ) V_89 ;
unsigned long V_75 ;
struct V_31 * V_31 = F_38 ( V_32 ) ;
switch ( V_88 & ~ V_508 ) {
case V_509 :
V_31 -> V_311 = V_311 ;
break;
case V_510 :
F_65 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_505 ) {
F_138 ( ! F_215 ( V_32 , V_31 -> V_505 -> V_511 ) ) ;
F_551 ( V_31 ) ;
}
F_66 ( & V_31 -> V_39 , V_75 ) ;
break;
#ifdef F_556
case V_512 :
F_235 () ;
F_65 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_505 ) {
F_138 ( ! F_215 ( V_32 , V_31 -> V_505 -> V_511 ) ) ;
F_553 ( V_31 ) ;
}
F_536 ( V_32 ) ;
F_138 ( V_31 -> V_140 != 1 ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
F_532 ( V_31 ) ;
F_534 ( V_31 ) ;
break;
#endif
}
F_557 () ;
return V_96 ;
}
static int T_23 F_558 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
switch ( V_88 & ~ V_508 ) {
case V_510 :
case V_513 :
F_559 ( ( long ) V_89 , true ) ;
return V_96 ;
default:
return V_97 ;
}
}
static int T_23 F_560 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
switch ( V_88 & ~ V_508 ) {
case V_92 :
F_559 ( ( long ) V_89 , false ) ;
return V_96 ;
default:
return V_97 ;
}
}
static int T_8 F_561 ( void )
{
void * V_32 = ( void * ) ( long ) F_79 () ;
int V_514 ;
V_514 = F_555 ( & V_515 , V_509 , V_32 ) ;
F_138 ( V_514 == V_516 ) ;
F_555 ( & V_515 , V_510 , V_32 ) ;
F_562 ( & V_515 ) ;
F_563 ( F_558 , V_517 ) ;
F_563 ( F_560 , V_518 ) ;
return 0 ;
}
static int T_8 F_564 ( char * V_519 )
{
V_520 = 1 ;
return 0 ;
}
static int F_565 ( struct V_101 * V_102 , int V_32 , int V_521 ,
struct V_220 * V_522 )
{
struct V_523 * V_524 = V_102 -> V_525 ;
char V_519 [ 256 ] ;
F_566 ( V_519 , sizeof( V_519 ) , F_227 ( V_102 ) ) ;
F_475 ( V_522 ) ;
F_219 ( V_526 L_29 , V_521 , L_30 , V_521 ) ;
if ( ! ( V_102 -> V_75 & V_527 ) ) {
F_219 ( L_31 ) ;
if ( V_102 -> V_42 )
F_219 ( V_379 L_32
L_33 ) ;
return - 1 ;
}
F_219 ( V_453 L_34 , V_519 , V_102 -> T_24 ) ;
if ( ! F_215 ( V_32 , F_227 ( V_102 ) ) ) {
F_219 ( V_379 L_35
L_36 , V_32 ) ;
}
if ( ! F_215 ( V_32 , F_567 ( V_524 ) ) ) {
F_219 ( V_379 L_37
L_38 , V_32 ) ;
}
F_219 ( V_526 L_39 , V_521 + 1 , L_30 ) ;
do {
if ( ! V_524 ) {
F_219 ( L_3 ) ;
F_219 ( V_379 L_40 ) ;
break;
}
if ( ! V_524 -> V_528 -> V_529 ) {
F_219 ( V_453 L_3 ) ;
F_219 ( V_379 L_41
L_42 ) ;
break;
}
if ( ! F_526 ( F_567 ( V_524 ) ) ) {
F_219 ( V_453 L_3 ) ;
F_219 ( V_379 L_43 ) ;
break;
}
if ( F_528 ( V_522 , F_567 ( V_524 ) ) ) {
F_219 ( V_453 L_3 ) ;
F_219 ( V_379 L_44 ) ;
break;
}
F_568 ( V_522 , V_522 , F_567 ( V_524 ) ) ;
F_566 ( V_519 , sizeof( V_519 ) , F_567 ( V_524 ) ) ;
F_219 ( V_453 L_45 , V_519 ) ;
if ( V_524 -> V_528 -> V_529 != V_530 ) {
F_219 ( V_453 L_46 ,
V_524 -> V_528 -> V_529 ) ;
}
V_524 = V_524 -> V_69 ;
} while ( V_524 != V_102 -> V_525 );
F_219 ( V_453 L_3 ) ;
if ( ! F_527 ( F_227 ( V_102 ) , V_522 ) )
F_219 ( V_379 L_47 ) ;
if ( V_102 -> V_42 &&
! F_470 ( V_522 , F_227 ( V_102 -> V_42 ) ) )
F_219 ( V_379 L_48
L_49 ) ;
return 0 ;
}
static void F_569 ( struct V_101 * V_102 , int V_32 )
{
int V_521 = 0 ;
if ( ! V_520 )
return;
if ( ! V_102 ) {
F_219 ( V_526 L_50 , V_32 ) ;
return;
}
F_219 ( V_526 L_51 , V_32 ) ;
for (; ; ) {
if ( F_565 ( V_102 , V_32 , V_521 , V_531 ) )
break;
V_521 ++ ;
V_102 = V_102 -> V_42 ;
if ( ! V_102 )
break;
}
}
static int F_570 ( struct V_101 * V_102 )
{
if ( F_526 ( F_227 ( V_102 ) ) == 1 )
return 1 ;
if ( V_102 -> V_75 & ( V_527 |
V_532 |
V_278 |
V_335 |
V_533 |
V_534 ) ) {
if ( V_102 -> V_525 != V_102 -> V_525 -> V_69 )
return 0 ;
}
if ( V_102 -> V_75 & ( V_535 ) )
return 0 ;
return 1 ;
}
static int
F_571 ( struct V_101 * V_102 , struct V_101 * V_42 )
{
unsigned long V_536 = V_102 -> V_75 , V_537 = V_42 -> V_75 ;
if ( F_570 ( V_42 ) )
return 1 ;
if ( ! F_527 ( F_227 ( V_102 ) , F_227 ( V_42 ) ) )
return 0 ;
if ( V_42 -> V_525 == V_42 -> V_525 -> V_69 ) {
V_537 &= ~ ( V_527 |
V_532 |
V_278 |
V_335 |
V_533 |
V_534 ) ;
if ( V_538 == 1 )
V_537 &= ~ V_539 ;
}
if ( ~ V_536 & V_537 )
return 0 ;
return 1 ;
}
static void F_572 ( struct V_540 * V_541 )
{
struct V_542 * V_505 = F_4 ( V_541 , struct V_542 , V_541 ) ;
F_573 ( & V_505 -> V_543 ) ;
F_472 ( V_505 -> V_544 ) ;
F_472 ( V_505 -> V_504 ) ;
F_472 ( V_505 -> V_511 ) ;
F_540 ( V_505 ) ;
}
static void F_574 ( struct V_31 * V_31 , struct V_542 * V_505 )
{
struct V_542 * V_545 = NULL ;
unsigned long V_75 ;
F_65 ( & V_31 -> V_39 , V_75 ) ;
if ( V_31 -> V_505 ) {
V_545 = V_31 -> V_505 ;
if ( F_215 ( V_31 -> V_32 , V_545 -> V_504 ) )
F_553 ( V_31 ) ;
F_554 ( V_31 -> V_32 , V_545 -> V_511 ) ;
if ( ! F_575 ( & V_545 -> V_546 ) )
V_545 = NULL ;
}
F_290 ( & V_505 -> V_546 ) ;
V_31 -> V_505 = V_505 ;
F_552 ( V_31 -> V_32 , V_505 -> V_511 ) ;
if ( F_215 ( V_31 -> V_32 , V_223 ) )
F_551 ( V_31 ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
if ( V_545 )
F_576 ( & V_545 -> V_541 , F_572 ) ;
}
static int F_577 ( struct V_542 * V_505 )
{
memset ( V_505 , 0 , sizeof( * V_505 ) ) ;
if ( ! F_465 ( & V_505 -> V_511 , V_436 ) )
goto V_259;
if ( ! F_465 ( & V_505 -> V_504 , V_436 ) )
goto V_547;
if ( ! F_465 ( & V_505 -> V_544 , V_436 ) )
goto V_548;
if ( F_578 ( & V_505 -> V_543 ) != 0 )
goto V_549;
return 0 ;
V_549:
F_472 ( V_505 -> V_544 ) ;
V_548:
F_472 ( V_505 -> V_504 ) ;
V_547:
F_472 ( V_505 -> V_511 ) ;
V_259:
return - V_437 ;
}
static void F_579 ( void )
{
F_577 ( & V_550 ) ;
F_580 ( & V_550 . V_546 , 1 ) ;
}
static struct V_542 * F_581 ( void )
{
struct V_542 * V_505 ;
V_505 = F_582 ( sizeof( * V_505 ) , V_436 ) ;
if ( ! V_505 )
return NULL ;
if ( F_577 ( V_505 ) != 0 ) {
F_540 ( V_505 ) ;
return NULL ;
}
return V_505 ;
}
static void F_583 ( struct V_523 * V_551 , int V_552 )
{
struct V_523 * V_113 , * V_553 ;
if ( ! V_551 )
return;
V_553 = V_551 ;
do {
V_113 = V_551 -> V_69 ;
if ( V_552 && F_575 ( & V_551 -> V_528 -> V_554 ) )
F_540 ( V_551 -> V_528 ) ;
F_540 ( V_551 ) ;
V_551 = V_113 ;
} while ( V_551 != V_553 );
}
static void F_584 ( struct V_540 * V_541 )
{
struct V_101 * V_102 = F_4 ( V_541 , struct V_101 , V_541 ) ;
if ( V_102 -> V_75 & V_555 ) {
F_583 ( V_102 -> V_525 , 1 ) ;
} else if ( F_575 ( & V_102 -> V_525 -> V_554 ) ) {
F_540 ( V_102 -> V_525 -> V_528 ) ;
F_540 ( V_102 -> V_525 ) ;
}
F_540 ( V_102 ) ;
}
static void F_585 ( struct V_101 * V_102 , int V_32 )
{
F_586 ( & V_102 -> V_541 , F_584 ) ;
}
static void F_587 ( struct V_101 * V_102 , int V_32 )
{
for (; V_102 ; V_102 = V_102 -> V_42 )
F_585 ( V_102 , V_32 ) ;
}
static void
F_588 ( struct V_101 * V_102 , struct V_542 * V_505 , int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
struct V_101 * V_113 ;
for ( V_113 = V_102 ; V_113 ; ) {
struct V_101 * V_42 = V_113 -> V_42 ;
if ( ! V_42 )
break;
if ( F_571 ( V_113 , V_42 ) ) {
V_113 -> V_42 = V_42 -> V_42 ;
if ( V_42 -> V_42 )
V_42 -> V_42 -> V_132 = V_113 ;
F_585 ( V_42 , V_32 ) ;
} else
V_113 = V_113 -> V_42 ;
}
if ( V_102 && F_570 ( V_102 ) ) {
V_113 = V_102 ;
V_102 = V_102 -> V_42 ;
F_585 ( V_113 , V_32 ) ;
if ( V_102 )
V_102 -> V_132 = NULL ;
}
F_569 ( V_102 , V_32 ) ;
F_574 ( V_31 , V_505 ) ;
V_113 = V_31 -> V_102 ;
F_589 ( V_31 -> V_102 , V_102 ) ;
F_587 ( V_113 , V_32 ) ;
}
static int T_8 F_590 ( char * V_519 )
{
F_591 ( & V_556 ) ;
F_592 ( V_519 , V_556 ) ;
return 1 ;
}
static int F_593 ( int V_284 , T_26 * V_557 )
{
int V_50 , V_307 , V_127 , V_558 , V_559 = - 1 ;
V_558 = V_560 ;
for ( V_50 = 0 ; V_50 < V_538 ; V_50 ++ ) {
V_307 = ( V_284 + V_50 ) % V_538 ;
if ( ! F_594 ( V_307 ) )
continue;
if ( F_595 ( V_307 , * V_557 ) )
continue;
V_127 = F_596 ( V_284 , V_307 ) ;
if ( V_127 < V_558 ) {
V_558 = V_127 ;
V_559 = V_307 ;
}
}
if ( V_559 != - 1 )
F_597 ( V_559 , * V_557 ) ;
return V_559 ;
}
static void F_598 ( int V_284 , struct V_220 * V_511 )
{
T_26 V_557 ;
int V_50 ;
F_475 ( V_511 ) ;
F_599 ( V_557 ) ;
F_568 ( V_511 , V_511 , F_212 ( V_284 ) ) ;
F_597 ( V_284 , V_557 ) ;
for ( V_50 = 1 ; V_50 < V_561 ; V_50 ++ ) {
int V_562 = F_593 ( V_284 , & V_557 ) ;
if ( V_562 < 0 )
break;
F_568 ( V_511 , V_511 , F_212 ( V_562 ) ) ;
}
}
static const struct V_220 * F_600 ( int V_32 )
{
F_62 ( & V_563 ) ;
F_598 ( F_213 ( V_32 ) , V_531 ) ;
return V_531 ;
}
static const struct V_220 * F_601 ( int V_32 )
{
return V_564 ;
}
static const struct V_220 * F_602 ( int V_32 )
{
return F_212 ( F_213 ( V_32 ) ) ;
}
static int
F_603 ( struct V_101 * V_102 , int V_32 )
{
struct V_523 * V_553 = NULL , * V_199 = NULL , * V_525 = NULL , * V_551 ;
const struct V_220 * V_511 = F_227 ( V_102 ) ;
struct V_220 * V_565 = V_531 ;
struct V_566 * V_567 = V_102 -> V_396 ;
struct V_101 * V_132 ;
int V_50 ;
F_475 ( V_565 ) ;
F_103 (i, span) {
struct V_220 * V_568 ;
if ( F_215 ( V_50 , V_565 ) )
continue;
V_551 = F_604 ( sizeof( struct V_523 ) + F_474 () ,
V_436 , F_213 ( V_50 ) ) ;
if ( ! V_551 )
goto V_474;
V_568 = F_567 ( V_551 ) ;
V_132 = * F_605 ( V_567 -> V_102 , V_50 ) ;
if ( V_132 -> V_132 ) {
V_132 = V_132 -> V_132 ;
F_471 ( V_568 , F_227 ( V_132 ) ) ;
} else
F_552 ( V_50 , V_568 ) ;
F_568 ( V_565 , V_565 , V_568 ) ;
V_551 -> V_528 = * F_605 ( V_567 -> V_528 , F_606 ( V_568 ) ) ;
F_290 ( & V_551 -> V_528 -> V_554 ) ;
if ( F_215 ( V_32 , V_568 ) )
V_525 = V_551 ;
if ( ! V_553 )
V_553 = V_551 ;
if ( V_199 )
V_199 -> V_69 = V_551 ;
V_199 = V_551 ;
V_199 -> V_69 = V_553 ;
}
V_102 -> V_525 = V_525 ;
return 0 ;
V_474:
F_583 ( V_553 , 0 ) ;
return - V_437 ;
}
static int F_607 ( int V_32 , struct V_566 * V_567 , struct V_523 * * V_551 )
{
struct V_101 * V_102 = * F_605 ( V_567 -> V_102 , V_32 ) ;
struct V_101 * V_132 = V_102 -> V_132 ;
if ( V_132 )
V_32 = F_606 ( F_227 ( V_132 ) ) ;
if ( V_551 ) {
* V_551 = * F_605 ( V_567 -> V_551 , V_32 ) ;
( * V_551 ) -> V_528 = * F_605 ( V_567 -> V_528 , V_32 ) ;
F_580 ( & ( * V_551 ) -> V_528 -> V_554 , 1 ) ;
}
return V_32 ;
}
static int
F_608 ( struct V_101 * V_102 , int V_32 )
{
struct V_523 * V_553 = NULL , * V_199 = NULL ;
struct V_566 * V_567 = V_102 -> V_396 ;
const struct V_220 * V_511 = F_227 ( V_102 ) ;
struct V_220 * V_565 ;
int V_50 ;
F_607 ( V_32 , V_567 , & V_102 -> V_525 ) ;
F_290 ( & V_102 -> V_525 -> V_554 ) ;
if ( V_32 != F_606 ( F_227 ( V_102 ) ) )
return 0 ;
F_62 ( & V_563 ) ;
V_565 = V_531 ;
F_475 ( V_565 ) ;
F_103 (i, span) {
struct V_523 * V_551 ;
int V_524 = F_607 ( V_50 , V_567 , & V_551 ) ;
int V_322 ;
if ( F_215 ( V_50 , V_565 ) )
continue;
F_475 ( F_567 ( V_551 ) ) ;
V_551 -> V_528 -> V_529 = 0 ;
F_103 (j, span) {
if ( F_607 ( V_322 , V_567 , NULL ) != V_524 )
continue;
F_552 ( V_322 , V_565 ) ;
F_552 ( V_322 , F_567 ( V_551 ) ) ;
}
if ( ! V_553 )
V_553 = V_551 ;
if ( V_199 )
V_199 -> V_69 = V_551 ;
V_199 = V_551 ;
}
V_199 -> V_69 = V_553 ;
return 0 ;
}
static void F_609 ( int V_32 , struct V_101 * V_102 )
{
struct V_523 * V_551 = V_102 -> V_525 ;
F_547 ( ! V_102 || ! V_551 ) ;
do {
V_551 -> V_569 = F_526 ( F_567 ( V_551 ) ) ;
V_551 = V_551 -> V_69 ;
} while ( V_551 != V_102 -> V_525 );
if ( V_32 != F_610 ( V_551 ) )
return;
F_611 ( V_102 , V_32 ) ;
}
static int T_8 F_612 ( char * V_519 )
{
unsigned long V_127 ;
V_127 = F_613 ( V_519 , NULL , 0 ) ;
if ( V_127 < V_570 )
V_571 = V_127 ;
return 1 ;
}
static void F_614 ( struct V_101 * V_102 ,
struct V_572 * V_573 )
{
int V_574 ;
if ( ! V_573 || V_573 -> V_575 < 0 ) {
if ( V_571 < 0 )
return;
else
V_574 = V_571 ;
} else
V_574 = V_573 -> V_575 ;
if ( V_574 < V_102 -> V_521 ) {
V_102 -> V_75 &= ~ ( V_262 | V_532 ) ;
} else {
V_102 -> V_75 |= ( V_262 | V_532 ) ;
}
}
static void F_615 ( struct V_576 * V_577 , enum V_578 V_579 ,
const struct V_220 * V_580 )
{
switch ( V_579 ) {
case V_581 :
if ( ! F_300 ( & V_577 -> V_505 -> V_546 ) )
F_572 ( & V_577 -> V_505 -> V_541 ) ;
case V_582 :
F_616 ( V_577 -> V_102 ) ;
case V_583 :
F_617 ( V_580 ) ;
case V_584 :
break;
}
}
static enum V_578 F_618 ( struct V_576 * V_577 ,
const struct V_220 * V_580 )
{
memset ( V_577 , 0 , sizeof( * V_577 ) ) ;
if ( F_619 ( V_580 ) )
return V_583 ;
V_577 -> V_102 = F_620 ( struct V_101 * ) ;
if ( ! V_577 -> V_102 )
return V_583 ;
V_577 -> V_505 = F_581 () ;
if ( ! V_577 -> V_505 )
return V_582 ;
return V_581 ;
}
static void F_621 ( int V_32 , struct V_101 * V_102 )
{
struct V_566 * V_567 = V_102 -> V_396 ;
F_78 ( * F_605 ( V_567 -> V_102 , V_32 ) != V_102 ) ;
* F_605 ( V_567 -> V_102 , V_32 ) = NULL ;
if ( F_300 ( & ( * F_605 ( V_567 -> V_551 , V_32 ) ) -> V_554 ) )
* F_605 ( V_567 -> V_551 , V_32 ) = NULL ;
if ( F_300 ( & ( * F_605 ( V_567 -> V_528 , V_32 ) ) -> V_554 ) )
* F_605 ( V_567 -> V_528 , V_32 ) = NULL ;
}
static const struct V_220 * F_622 ( int V_32 )
{
return F_623 ( V_32 ) ;
}
static int F_619 ( const struct V_220 * V_580 )
{
struct V_585 * V_586 ;
int V_322 ;
for ( V_586 = V_587 ; V_586 -> V_588 ; V_586 ++ ) {
struct V_566 * V_567 = & V_586 -> V_131 ;
V_567 -> V_102 = F_620 ( struct V_101 * ) ;
if ( ! V_567 -> V_102 )
return - V_437 ;
V_567 -> V_551 = F_620 ( struct V_523 * ) ;
if ( ! V_567 -> V_551 )
return - V_437 ;
V_567 -> V_528 = F_620 ( struct V_589 * ) ;
if ( ! V_567 -> V_528 )
return - V_437 ;
F_103 (j, cpu_map) {
struct V_101 * V_102 ;
struct V_523 * V_551 ;
struct V_589 * V_528 ;
V_102 = F_604 ( sizeof( struct V_101 ) + F_474 () ,
V_436 , F_213 ( V_322 ) ) ;
if ( ! V_102 )
return - V_437 ;
* F_605 ( V_567 -> V_102 , V_322 ) = V_102 ;
V_551 = F_604 ( sizeof( struct V_523 ) + F_474 () ,
V_436 , F_213 ( V_322 ) ) ;
if ( ! V_551 )
return - V_437 ;
* F_605 ( V_567 -> V_551 , V_322 ) = V_551 ;
V_528 = F_604 ( sizeof( struct V_589 ) ,
V_436 , F_213 ( V_322 ) ) ;
if ( ! V_528 )
return - V_437 ;
* F_605 ( V_567 -> V_528 , V_322 ) = V_528 ;
}
}
return 0 ;
}
static void F_617 ( const struct V_220 * V_580 )
{
struct V_585 * V_586 ;
int V_322 ;
for ( V_586 = V_587 ; V_586 -> V_588 ; V_586 ++ ) {
struct V_566 * V_567 = & V_586 -> V_131 ;
F_103 (j, cpu_map) {
struct V_101 * V_102 = * F_605 ( V_567 -> V_102 , V_322 ) ;
if ( V_102 && ( V_102 -> V_75 & V_555 ) )
F_583 ( V_102 -> V_525 , 0 ) ;
F_540 ( * F_605 ( V_567 -> V_102 , V_322 ) ) ;
F_540 ( * F_605 ( V_567 -> V_551 , V_322 ) ) ;
F_540 ( * F_605 ( V_567 -> V_528 , V_322 ) ) ;
}
F_616 ( V_567 -> V_102 ) ;
F_616 ( V_567 -> V_551 ) ;
F_616 ( V_567 -> V_528 ) ;
}
}
struct V_101 * F_624 ( struct V_585 * V_586 ,
struct V_576 * V_577 , const struct V_220 * V_580 ,
struct V_572 * V_573 , struct V_101 * V_132 ,
int V_32 )
{
struct V_101 * V_102 = V_586 -> V_588 ( V_586 , V_32 ) ;
if ( ! V_102 )
return V_132 ;
F_614 ( V_102 , V_573 ) ;
F_468 ( F_227 ( V_102 ) , V_580 , V_586 -> V_443 ( V_32 ) ) ;
if ( V_132 ) {
V_102 -> V_521 = V_132 -> V_521 + 1 ;
V_570 = F_128 ( V_570 , V_102 -> V_521 ) ;
V_132 -> V_42 = V_102 ;
}
V_102 -> V_132 = V_132 ;
return V_102 ;
}
static int F_625 ( const struct V_220 * V_580 ,
struct V_572 * V_573 )
{
enum V_578 V_590 = V_584 ;
struct V_101 * V_102 ;
struct V_576 V_577 ;
int V_50 , V_133 = - V_437 ;
V_590 = F_618 ( & V_577 , V_580 ) ;
if ( V_590 != V_581 )
goto error;
F_103 (i, cpu_map) {
struct V_585 * V_586 ;
V_102 = NULL ;
for ( V_586 = V_587 ; V_586 -> V_588 ; V_586 ++ ) {
V_102 = F_624 ( V_586 , & V_577 , V_580 , V_573 , V_102 , V_50 ) ;
if ( V_586 -> V_75 & V_591 || F_73 ( V_592 ) )
V_102 -> V_75 |= V_555 ;
if ( F_527 ( V_580 , F_227 ( V_102 ) ) )
break;
}
while ( V_102 -> V_132 )
V_102 = V_102 -> V_132 ;
* F_605 ( V_577 . V_102 , V_50 ) = V_102 ;
}
F_103 (i, cpu_map) {
for ( V_102 = * F_605 ( V_577 . V_102 , V_50 ) ; V_102 ; V_102 = V_102 -> V_42 ) {
V_102 -> V_593 = F_526 ( F_227 ( V_102 ) ) ;
if ( V_102 -> V_75 & V_555 ) {
if ( F_603 ( V_102 , V_50 ) )
goto error;
} else {
if ( F_608 ( V_102 , V_50 ) )
goto error;
}
}
}
for ( V_50 = V_594 - 1 ; V_50 >= 0 ; V_50 -- ) {
if ( ! F_215 ( V_50 , V_580 ) )
continue;
for ( V_102 = * F_605 ( V_577 . V_102 , V_50 ) ; V_102 ; V_102 = V_102 -> V_42 ) {
F_621 ( V_50 , V_102 ) ;
F_609 ( V_50 , V_102 ) ;
}
}
F_101 () ;
F_103 (i, cpu_map) {
V_102 = * F_605 ( V_577 . V_102 , V_50 ) ;
F_588 ( V_102 , V_577 . V_505 , V_50 ) ;
}
F_105 () ;
V_133 = 0 ;
error:
F_615 ( & V_577 , V_590 , V_580 ) ;
return V_133 ;
}
T_21 * F_626 ( unsigned int V_595 )
{
int V_50 ;
T_21 * V_596 ;
V_596 = F_582 ( sizeof( * V_596 ) * V_595 , V_436 ) ;
if ( ! V_596 )
return NULL ;
for ( V_50 = 0 ; V_50 < V_595 ; V_50 ++ ) {
if ( ! F_465 ( & V_596 [ V_50 ] , V_436 ) ) {
F_627 ( V_596 , V_50 ) ;
return NULL ;
}
}
return V_596 ;
}
void F_627 ( T_21 V_596 [] , unsigned int V_595 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_595 ; V_50 ++ )
F_472 ( V_596 [ V_50 ] ) ;
F_540 ( V_596 ) ;
}
static int F_628 ( const struct V_220 * V_580 )
{
int V_514 ;
F_629 () ;
V_597 = 1 ;
V_598 = F_626 ( V_597 ) ;
if ( ! V_598 )
V_598 = & V_599 ;
F_630 ( V_598 [ 0 ] , V_580 , V_556 ) ;
V_600 = NULL ;
V_514 = F_625 ( V_598 [ 0 ] , NULL ) ;
F_545 () ;
return V_514 ;
}
static void F_631 ( const struct V_220 * V_580 )
{
int V_50 ;
F_101 () ;
F_103 (i, cpu_map)
F_588 ( NULL , & V_550 , V_50 ) ;
F_105 () ;
}
static int F_632 ( struct V_572 * V_601 , int V_602 ,
struct V_572 * V_603 , int V_604 )
{
struct V_572 V_113 ;
if ( ! V_603 && ! V_601 )
return 1 ;
V_113 = V_605 ;
return ! memcmp ( V_601 ? ( V_601 + V_602 ) : & V_113 ,
V_603 ? ( V_603 + V_604 ) : & V_113 ,
sizeof( struct V_572 ) ) ;
}
void F_633 ( int V_606 , T_21 V_607 [] ,
struct V_572 * V_608 )
{
int V_50 , V_322 , V_307 ;
int V_609 ;
F_634 ( & V_563 ) ;
F_549 () ;
V_609 = F_629 () ;
V_307 = V_607 ? V_606 : 0 ;
for ( V_50 = 0 ; V_50 < V_597 ; V_50 ++ ) {
for ( V_322 = 0 ; V_322 < V_307 && ! V_609 ; V_322 ++ ) {
if ( F_527 ( V_598 [ V_50 ] , V_607 [ V_322 ] )
&& F_632 ( V_600 , V_50 , V_608 , V_322 ) )
goto V_610;
}
F_631 ( V_598 [ V_50 ] ) ;
V_610:
;
}
if ( V_607 == NULL ) {
V_597 = 0 ;
V_607 = & V_599 ;
F_630 ( V_607 [ 0 ] , V_223 , V_556 ) ;
F_78 ( V_608 ) ;
}
for ( V_50 = 0 ; V_50 < V_606 ; V_50 ++ ) {
for ( V_322 = 0 ; V_322 < V_597 && ! V_609 ; V_322 ++ ) {
if ( F_527 ( V_607 [ V_50 ] , V_598 [ V_322 ] )
&& F_632 ( V_608 , V_50 , V_600 , V_322 ) )
goto V_611;
}
F_625 ( V_607 [ V_50 ] , V_608 ? V_608 + V_50 : NULL ) ;
V_611:
;
}
if ( V_598 != & V_599 )
F_627 ( V_598 , V_597 ) ;
F_540 ( V_600 ) ;
V_598 = V_607 ;
V_600 = V_608 ;
V_597 = V_606 ;
F_545 () ;
F_635 ( & V_563 ) ;
}
static void F_636 ( void )
{
F_462 () ;
F_633 ( 0 , NULL , NULL ) ;
F_637 () ;
F_463 () ;
}
static T_4 F_638 ( const char * V_58 , T_6 V_612 , int V_613 )
{
unsigned int V_521 = 0 ;
if ( sscanf ( V_58 , L_52 , & V_521 ) != 1 )
return - V_62 ;
if ( V_521 >= V_614 )
return - V_62 ;
if ( V_613 )
V_615 = V_521 ;
else
V_616 = V_521 ;
F_636 () ;
return V_612 ;
}
static T_4 F_639 ( struct V_617 * V_195 ,
struct V_618 * V_573 ,
char * V_619 )
{
return sprintf ( V_619 , L_53 , V_616 ) ;
}
static T_4 F_640 ( struct V_617 * V_195 ,
struct V_618 * V_573 ,
const char * V_58 , T_6 V_612 )
{
return F_638 ( V_58 , V_612 , 0 ) ;
}
static T_4 F_641 ( struct V_617 * V_620 ,
struct V_618 * V_573 ,
char * V_619 )
{
return sprintf ( V_619 , L_53 , V_615 ) ;
}
static T_4 F_642 ( struct V_617 * V_620 ,
struct V_618 * V_573 ,
const char * V_58 , T_6 V_612 )
{
return F_638 ( V_58 , V_612 , 1 ) ;
}
int T_8 F_643 ( struct V_617 * V_621 )
{
int V_514 = 0 ;
#ifdef F_644
if ( F_645 () )
V_514 = F_646 ( & V_621 -> V_622 . V_623 ,
& V_624 . V_573 ) ;
#endif
#ifdef F_647
if ( ! V_514 && F_648 () )
V_514 = F_646 ( & V_621 -> V_622 . V_623 ,
& V_625 . V_573 ) ;
#endif
return V_514 ;
}
static int F_649 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
switch ( V_88 & ~ V_508 ) {
case V_510 :
case V_513 :
F_650 () ;
return V_96 ;
default:
return V_97 ;
}
}
static int F_651 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
switch ( V_88 & ~ V_508 ) {
case V_92 :
F_650 () ;
return V_96 ;
default:
return V_97 ;
}
}
static int F_652 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
int V_32 = ( int ) ( long ) V_89 ;
switch ( V_88 ) {
case V_92 :
case V_93 :
F_653 ( F_38 ( V_32 ) ) ;
return V_96 ;
case V_513 :
case V_626 :
case V_510 :
case V_627 :
F_654 ( F_38 ( V_32 ) ) ;
return V_96 ;
default:
return V_97 ;
}
}
void T_8 F_655 ( void )
{
T_21 V_628 ;
F_465 ( & V_628 , V_436 ) ;
F_465 ( & V_599 , V_436 ) ;
F_462 () ;
F_634 ( & V_563 ) ;
F_628 ( V_223 ) ;
F_630 ( V_628 , V_564 , V_556 ) ;
if ( F_656 ( V_628 ) )
F_552 ( F_79 () , V_628 ) ;
F_635 ( & V_563 ) ;
F_463 () ;
F_87 ( F_649 , V_629 ) ;
F_87 ( F_651 , V_630 ) ;
F_87 ( F_652 , 0 ) ;
F_86 () ;
if ( F_469 ( V_72 , V_628 ) < 0 )
F_379 () ;
F_525 () ;
F_472 ( V_628 ) ;
F_657 () ;
}
void T_8 F_655 ( void )
{
F_525 () ;
}
int F_658 ( unsigned long V_371 )
{
return F_359 ( V_371 ) ||
( V_371 >= ( unsigned long ) V_631
&& V_371 < ( unsigned long ) V_632 ) ;
}
static void F_659 ( struct V_41 * V_41 )
{
V_41 -> V_633 = V_634 ;
F_250 ( & V_41 -> V_635 ) ;
V_41 -> V_636 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_660
V_41 -> V_637 = V_41 -> V_636 ;
#endif
}
static void F_661 ( struct V_44 * V_44 , struct V_31 * V_31 )
{
struct V_638 * V_639 ;
int V_50 ;
V_639 = & V_44 -> V_301 ;
for ( V_50 = 0 ; V_50 < V_149 ; V_50 ++ ) {
F_250 ( V_639 -> V_640 + V_50 ) ;
F_662 ( V_50 , V_639 -> V_641 ) ;
}
F_663 ( V_149 , V_639 -> V_641 ) ;
#if F_177 F_25
V_44 -> V_642 . V_67 = V_149 ;
V_44 -> V_642 . V_69 = V_149 ;
V_44 -> V_643 = 0 ;
V_44 -> V_644 = 0 ;
F_664 ( & V_44 -> V_276 ) ;
#endif
V_44 -> V_645 = 0 ;
V_44 -> V_646 = 0 ;
V_44 -> V_20 = 0 ;
F_10 ( & V_44 -> V_21 ) ;
}
static void F_665 ( struct V_33 * V_34 , struct V_41 * V_41 ,
struct V_647 * V_40 , int V_32 ,
struct V_647 * V_42 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
V_41 -> V_34 = V_34 ;
V_41 -> V_31 = V_31 ;
#ifdef F_25
V_41 -> V_648 = 1 ;
#endif
V_34 -> V_41 [ V_32 ] = V_41 ;
V_34 -> V_40 [ V_32 ] = V_40 ;
if ( ! V_40 )
return;
if ( ! V_42 )
V_40 -> V_41 = & V_31 -> V_384 ;
else
V_40 -> V_41 = V_42 -> V_649 ;
V_40 -> V_649 = V_41 ;
F_117 ( & V_40 -> V_128 , 0 ) ;
V_40 -> V_42 = V_42 ;
}
static void F_666 ( struct V_33 * V_34 , struct V_44 * V_44 ,
struct V_650 * V_45 , int V_32 ,
struct V_650 * V_42 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
V_44 -> V_642 . V_67 = V_149 ;
V_44 -> V_651 = 0 ;
V_44 -> V_31 = V_31 ;
V_44 -> V_34 = V_34 ;
V_34 -> V_44 [ V_32 ] = V_44 ;
V_34 -> V_45 [ V_32 ] = V_45 ;
if ( ! V_45 )
return;
if ( ! V_42 )
V_45 -> V_44 = & V_31 -> V_43 ;
else
V_45 -> V_44 = V_42 -> V_649 ;
V_45 -> V_649 = V_44 ;
V_45 -> V_42 = V_42 ;
F_250 ( & V_45 -> V_269 ) ;
}
void T_8 F_667 ( void )
{
int V_50 , V_322 ;
unsigned long V_652 = 0 , V_653 ;
#ifdef F_31
V_652 += 2 * V_224 * sizeof( void * * ) ;
#endif
#ifdef F_32
V_652 += 2 * V_224 * sizeof( void * * ) ;
#endif
#ifdef F_668
V_652 += F_546 () * F_474 () ;
#endif
if ( V_652 ) {
V_653 = ( unsigned long ) F_669 ( V_652 , V_654 ) ;
#ifdef F_31
V_134 . V_40 = (struct V_647 * * ) V_653 ;
V_653 += V_224 * sizeof( void * * ) ;
V_134 . V_41 = (struct V_41 * * ) V_653 ;
V_653 += V_224 * sizeof( void * * ) ;
#endif
#ifdef F_32
V_134 . V_45 = (struct V_650 * * ) V_653 ;
V_653 += V_224 * sizeof( void * * ) ;
V_134 . V_44 = (struct V_44 * * ) V_653 ;
V_653 += V_224 * sizeof( void * * ) ;
#endif
#ifdef F_668
F_297 (i) {
F_164 ( V_655 , V_50 ) = ( void * ) V_653 ;
V_653 += F_474 () ;
}
#endif
}
#ifdef F_25
F_579 () ;
#endif
F_8 ( & V_656 ,
F_49 () , F_50 () ) ;
#ifdef F_32
F_8 ( & V_134 . V_9 ,
F_49 () , F_50 () ) ;
#endif
#ifdef F_670
F_671 ( & V_134 . V_253 , & V_657 ) ;
F_250 ( & V_134 . V_658 ) ;
F_672 ( & V_659 ) ;
#endif
F_297 (i) {
struct V_31 * V_31 ;
V_31 = F_38 ( V_50 ) ;
F_10 ( & V_31 -> V_39 ) ;
V_31 -> V_140 = 0 ;
V_31 -> V_300 = 0 ;
V_31 -> V_311 = V_310 + V_313 ;
F_659 ( & V_31 -> V_384 ) ;
F_661 ( & V_31 -> V_43 , V_31 ) ;
#ifdef F_31
V_134 . V_660 = V_661 ;
F_250 ( & V_31 -> V_662 ) ;
F_665 ( & V_134 , & V_31 -> V_384 , NULL , V_50 , NULL ) ;
#endif
V_31 -> V_43 . V_20 = V_656 . V_20 ;
#ifdef F_32
F_250 ( & V_31 -> V_663 ) ;
F_666 ( & V_134 , & V_31 -> V_43 , NULL , V_50 , NULL ) ;
#endif
for ( V_322 = 0 ; V_322 < V_332 ; V_322 ++ )
V_31 -> V_138 [ V_322 ] = 0 ;
V_31 -> V_331 = V_310 ;
#ifdef F_25
V_31 -> V_102 = NULL ;
V_31 -> V_505 = NULL ;
V_31 -> V_139 = V_530 ;
V_31 -> F_283 = 0 ;
V_31 -> V_664 = 0 ;
V_31 -> V_665 = V_310 ;
V_31 -> V_666 = 0 ;
V_31 -> V_32 = V_50 ;
V_31 -> V_504 = 0 ;
V_31 -> V_248 = 0 ;
V_31 -> V_249 = 2 * V_200 ;
F_574 ( V_31 , & V_550 ) ;
#ifdef F_673
V_31 -> V_667 = 0 ;
F_674 ( & F_164 ( V_668 , V_50 ) ) ;
#endif
#endif
F_88 ( V_31 ) ;
F_580 ( & V_31 -> F_299 , 0 ) ;
}
F_148 ( & V_659 ) ;
#ifdef F_251
F_252 ( & V_659 . V_270 ) ;
#endif
#ifdef F_25
F_675 ( V_669 , V_670 ) ;
#endif
#ifdef F_676
F_664 ( & V_659 . V_671 ) ;
#endif
F_290 ( & V_476 . V_295 ) ;
F_291 ( & V_476 , V_72 ) ;
F_514 ( V_72 , F_79 () ) ;
V_311 = V_310 + V_313 ;
V_72 -> V_78 = & V_197 ;
F_677 ( & V_672 , V_654 ) ;
#ifdef F_25
F_677 ( & V_531 , V_654 ) ;
#ifdef F_673
F_677 ( & V_673 . V_674 , V_654 ) ;
F_465 ( & V_673 . V_675 , V_654 ) ;
F_580 ( & V_673 . V_676 , V_224 ) ;
F_580 ( & V_673 . V_677 , V_224 ) ;
F_580 ( & V_673 . V_678 , V_224 ) ;
#endif
if ( V_556 == NULL )
F_677 ( & V_556 , V_654 ) ;
#endif
V_679 = 1 ;
}
static inline int F_678 ( int V_680 )
{
int V_681 = ( V_206 () & ~ V_207 ) + F_679 () ;
return ( V_681 == V_680 ) ;
}
void F_680 ( const char * V_53 , int line , int V_680 )
{
static unsigned long V_682 ;
if ( ( F_678 ( V_680 ) && ! F_137 () ) ||
V_683 != V_684 || V_685 )
return;
if ( F_313 ( V_310 , V_682 + V_217 ) && V_682 )
return;
V_682 = V_310 ;
F_219 ( V_379
L_54 ,
V_53 , line ) ;
F_219 ( V_379
L_55 ,
F_681 () , F_137 () ,
V_72 -> V_380 , V_72 -> V_227 ) ;
F_368 ( V_72 ) ;
if ( F_137 () )
F_370 ( V_72 ) ;
F_372 () ;
}
static void F_682 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
const struct V_78 * V_190 = V_5 -> V_78 ;
int V_412 = V_5 -> V_147 ;
int V_196 ;
V_196 = V_5 -> V_196 ;
if ( V_196 )
F_156 ( V_31 , V_5 , 0 ) ;
F_449 ( V_31 , V_5 , V_272 , 0 ) ;
if ( V_196 ) {
F_154 ( V_31 , V_5 , 0 ) ;
F_89 ( V_31 -> V_67 ) ;
}
F_192 ( V_31 , V_5 , V_190 , V_412 ) ;
}
void F_683 ( void )
{
struct V_4 * V_456 , * V_5 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
F_684 ( & V_457 , V_75 ) ;
F_506 (g, p) {
if ( ! V_5 -> V_225 )
continue;
V_5 -> V_40 . V_201 = 0 ;
#ifdef F_225
V_5 -> V_40 . V_235 . V_686 = 0 ;
V_5 -> V_40 . V_235 . V_687 = 0 ;
V_5 -> V_40 . V_235 . V_688 = 0 ;
#endif
if ( ! F_685 ( V_5 ) ) {
if ( F_329 ( V_5 ) < 0 && V_5 -> V_225 )
F_440 ( V_5 , 0 ) ;
continue;
}
F_15 ( & V_5 -> V_38 ) ;
V_31 = F_61 ( V_5 ) ;
F_682 ( V_31 , V_5 ) ;
F_67 ( V_31 ) ;
F_21 ( & V_5 -> V_38 ) ;
} F_508 ( V_456 , V_5 ) ;
F_686 ( & V_457 , V_75 ) ;
}
struct V_4 * F_687 ( int V_32 )
{
return F_99 ( V_32 ) ;
}
void V_410 ( int V_32 , struct V_4 * V_5 )
{
F_99 ( V_32 ) = V_5 ;
}
static void F_688 ( struct V_33 * V_34 )
{
int V_50 ;
F_297 (i) {
if ( V_34 -> V_41 )
F_540 ( V_34 -> V_41 [ V_50 ] ) ;
if ( V_34 -> V_40 )
F_540 ( V_34 -> V_40 [ V_50 ] ) ;
}
F_540 ( V_34 -> V_41 ) ;
F_540 ( V_34 -> V_40 ) ;
}
static
int F_689 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
struct V_41 * V_41 ;
struct V_647 * V_40 ;
int V_50 ;
V_34 -> V_41 = F_669 ( sizeof( V_41 ) * V_224 , V_436 ) ;
if ( ! V_34 -> V_41 )
goto V_514;
V_34 -> V_40 = F_669 ( sizeof( V_40 ) * V_224 , V_436 ) ;
if ( ! V_34 -> V_40 )
goto V_514;
V_34 -> V_660 = V_689 ;
F_297 (i) {
V_41 = F_604 ( sizeof( struct V_41 ) ,
V_436 , F_213 ( V_50 ) ) ;
if ( ! V_41 )
goto V_514;
V_40 = F_604 ( sizeof( struct V_647 ) ,
V_436 , F_213 ( V_50 ) ) ;
if ( ! V_40 )
goto V_690;
F_659 ( V_41 ) ;
F_665 ( V_34 , V_41 , V_40 , V_50 , V_42 -> V_40 [ V_50 ] ) ;
}
return 1 ;
V_690:
F_540 ( V_41 ) ;
V_514:
return 0 ;
}
static inline void F_690 ( struct V_33 * V_34 , int V_32 )
{
struct V_31 * V_31 = F_38 ( V_32 ) ;
unsigned long V_75 ;
if ( ! V_34 -> V_41 [ V_32 ] -> V_691 )
return;
F_65 ( & V_31 -> V_39 , V_75 ) ;
F_691 ( V_34 -> V_41 [ V_32 ] ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
}
static inline void F_688 ( struct V_33 * V_34 )
{
}
static inline
int F_689 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
return 1 ;
}
static inline void F_690 ( struct V_33 * V_34 , int V_32 )
{
}
static void F_692 ( struct V_33 * V_34 )
{
int V_50 ;
if ( V_34 -> V_45 )
F_22 ( & V_34 -> V_9 ) ;
F_297 (i) {
if ( V_34 -> V_44 )
F_540 ( V_34 -> V_44 [ V_50 ] ) ;
if ( V_34 -> V_45 )
F_540 ( V_34 -> V_45 [ V_50 ] ) ;
}
F_540 ( V_34 -> V_44 ) ;
F_540 ( V_34 -> V_45 ) ;
}
static
int F_693 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
struct V_44 * V_44 ;
struct V_650 * V_45 ;
int V_50 ;
V_34 -> V_44 = F_669 ( sizeof( V_44 ) * V_224 , V_436 ) ;
if ( ! V_34 -> V_44 )
goto V_514;
V_34 -> V_45 = F_669 ( sizeof( V_45 ) * V_224 , V_436 ) ;
if ( ! V_34 -> V_45 )
goto V_514;
F_8 ( & V_34 -> V_9 ,
F_18 ( V_656 . V_15 ) , 0 ) ;
F_297 (i) {
V_44 = F_604 ( sizeof( struct V_44 ) ,
V_436 , F_213 ( V_50 ) ) ;
if ( ! V_44 )
goto V_514;
V_45 = F_604 ( sizeof( struct V_650 ) ,
V_436 , F_213 ( V_50 ) ) ;
if ( ! V_45 )
goto V_690;
F_661 ( V_44 , F_38 ( V_50 ) ) ;
V_44 -> V_20 = V_34 -> V_9 . V_20 ;
F_666 ( V_34 , V_44 , V_45 , V_50 , V_42 -> V_45 [ V_50 ] ) ;
}
return 1 ;
V_690:
F_540 ( V_44 ) ;
V_514:
return 0 ;
}
static inline void F_692 ( struct V_33 * V_34 )
{
}
static inline
int F_693 ( struct V_33 * V_34 , struct V_33 * V_42 )
{
return 1 ;
}
static void F_694 ( struct V_33 * V_34 )
{
F_688 ( V_34 ) ;
F_692 ( V_34 ) ;
F_695 ( V_34 ) ;
F_540 ( V_34 ) ;
}
struct V_33 * F_696 ( struct V_33 * V_42 )
{
struct V_33 * V_34 ;
unsigned long V_75 ;
V_34 = F_669 ( sizeof( * V_34 ) , V_436 ) ;
if ( ! V_34 )
return F_697 ( - V_437 ) ;
if ( ! F_689 ( V_34 , V_42 ) )
goto V_514;
if ( ! F_693 ( V_34 , V_42 ) )
goto V_514;
F_404 ( & V_692 , V_75 ) ;
F_698 ( & V_34 -> V_253 , & V_657 ) ;
F_547 ( ! V_42 ) ;
V_34 -> V_42 = V_42 ;
F_250 ( & V_34 -> V_658 ) ;
F_698 ( & V_34 -> V_693 , & V_42 -> V_658 ) ;
F_405 ( & V_692 , V_75 ) ;
return V_34 ;
V_514:
F_694 ( V_34 ) ;
return F_697 ( - V_437 ) ;
}
static void F_699 ( struct V_540 * V_694 )
{
F_694 ( F_4 ( V_694 , struct V_33 , V_541 ) ) ;
}
void F_700 ( struct V_33 * V_34 )
{
unsigned long V_75 ;
int V_50 ;
F_297 (i)
F_690 ( V_34 , V_50 ) ;
F_404 ( & V_692 , V_75 ) ;
F_701 ( & V_34 -> V_253 ) ;
F_701 ( & V_34 -> V_693 ) ;
F_405 ( & V_692 , V_75 ) ;
F_586 ( & V_34 -> V_541 , F_699 ) ;
}
void F_702 ( struct V_4 * V_123 )
{
int V_196 , V_212 ;
unsigned long V_75 ;
struct V_31 * V_31 ;
V_31 = F_64 ( V_123 , & V_75 ) ;
V_212 = F_51 ( V_31 , V_123 ) ;
V_196 = V_123 -> V_196 ;
if ( V_196 )
F_152 ( V_31 , V_123 , 0 ) ;
if ( F_112 ( V_212 ) )
V_123 -> V_78 -> F_377 ( V_31 , V_123 ) ;
#ifdef F_31
if ( V_123 -> V_78 -> V_695 )
V_123 -> V_78 -> V_695 ( V_123 , V_196 ) ;
else
#endif
F_30 ( V_123 , F_93 ( V_123 ) ) ;
if ( F_112 ( V_212 ) )
V_123 -> V_78 -> V_410 ( V_31 ) ;
if ( V_196 )
F_150 ( V_31 , V_123 , 0 ) ;
F_68 ( V_31 , V_123 , & V_75 ) ;
}
int F_703 ( struct V_33 * V_34 , unsigned long V_660 )
{
int V_50 ;
unsigned long V_75 ;
if ( ! V_34 -> V_40 [ 0 ] )
return - V_62 ;
V_660 = F_704 ( V_660 , F_149 ( V_696 ) , F_149 ( V_697 ) ) ;
F_634 ( & V_698 ) ;
if ( V_34 -> V_660 == V_660 )
goto V_402;
V_34 -> V_660 = V_660 ;
F_297 (i) {
struct V_31 * V_31 = F_38 ( V_50 ) ;
struct V_647 * V_40 ;
V_40 = V_34 -> V_40 [ V_50 ] ;
F_65 ( & V_31 -> V_39 , V_75 ) ;
F_705 (se)
F_706 ( F_707 ( V_40 ) ) ;
F_66 ( & V_31 -> V_39 , V_75 ) ;
}
V_402:
F_635 ( & V_698 ) ;
return 0 ;
}
unsigned long F_708 ( struct V_33 * V_34 )
{
return V_34 -> V_660 ;
}
static unsigned long F_709 ( T_2 V_18 , T_2 V_19 )
{
if ( V_19 == V_26 )
return 1ULL << 20 ;
return F_710 ( V_19 << 20 , V_18 ) ;
}
static inline int F_711 ( struct V_33 * V_34 )
{
struct V_4 * V_456 , * V_5 ;
F_506 (g, p) {
if ( F_685 ( V_5 ) && F_712 ( & V_5 -> V_43 ) -> V_34 == V_34 )
return 1 ;
} F_508 ( V_456 , V_5 ) ;
return 0 ;
}
static int F_713 ( struct V_33 * V_34 , void * V_131 )
{
struct V_699 * V_577 = V_131 ;
struct V_33 * V_132 ;
unsigned long V_136 , V_296 = 0 ;
T_2 V_18 , V_19 ;
V_18 = F_18 ( V_34 -> V_9 . V_15 ) ;
V_19 = V_34 -> V_9 . V_20 ;
if ( V_34 == V_577 -> V_34 ) {
V_18 = V_577 -> V_15 ;
V_19 = V_577 -> V_20 ;
}
if ( V_19 > V_18 && V_19 != V_26 )
return - V_62 ;
if ( F_12 () && ! V_19 && F_711 ( V_34 ) )
return - V_700 ;
V_136 = F_709 ( V_18 , V_19 ) ;
if ( V_136 > F_709 ( F_49 () , F_50 () ) )
return - V_62 ;
F_123 (child, &tg->children, siblings) {
V_18 = F_18 ( V_132 -> V_9 . V_15 ) ;
V_19 = V_132 -> V_9 . V_20 ;
if ( V_132 == V_577 -> V_34 ) {
V_18 = V_577 -> V_15 ;
V_19 = V_577 -> V_20 ;
}
V_296 += F_709 ( V_18 , V_19 ) ;
}
if ( V_296 > V_136 )
return - V_62 ;
return 0 ;
}
static int F_714 ( struct V_33 * V_34 , T_2 V_18 , T_2 V_19 )
{
struct V_699 V_131 = {
. V_34 = V_34 ,
. V_15 = V_18 ,
. V_20 = V_19 ,
} ;
return F_122 ( F_713 , F_124 , & V_131 ) ;
}
static int F_715 ( struct V_33 * V_34 ,
T_2 V_15 , T_2 V_20 )
{
int V_50 , V_514 = 0 ;
F_634 ( & V_701 ) ;
F_505 ( & V_457 ) ;
V_514 = F_714 ( V_34 , V_15 , V_20 ) ;
if ( V_514 )
goto V_103;
F_382 ( & V_34 -> V_9 . V_21 ) ;
V_34 -> V_9 . V_15 = F_9 ( V_15 ) ;
V_34 -> V_9 . V_20 = V_20 ;
F_297 (i) {
struct V_44 * V_44 = V_34 -> V_44 [ V_50 ] ;
F_15 ( & V_44 -> V_21 ) ;
V_44 -> V_20 = V_20 ;
F_21 ( & V_44 -> V_21 ) ;
}
F_58 ( & V_34 -> V_9 . V_21 ) ;
V_103:
F_511 ( & V_457 ) ;
F_635 ( & V_701 ) ;
return V_514 ;
}
int F_716 ( struct V_33 * V_34 , long V_702 )
{
T_2 V_20 , V_15 ;
V_15 = F_18 ( V_34 -> V_9 . V_15 ) ;
V_20 = ( T_2 ) V_702 * V_66 ;
if ( V_702 < 0 )
V_20 = V_26 ;
return F_715 ( V_34 , V_15 , V_20 ) ;
}
long F_717 ( struct V_33 * V_34 )
{
T_2 V_702 ;
if ( V_34 -> V_9 . V_20 == V_26 )
return - 1 ;
V_702 = V_34 -> V_9 . V_20 ;
F_352 ( V_702 , V_66 ) ;
return V_702 ;
}
int F_718 ( struct V_33 * V_34 , long V_703 )
{
T_2 V_20 , V_15 ;
V_15 = ( T_2 ) V_703 * V_66 ;
V_20 = V_34 -> V_9 . V_20 ;
if ( V_15 == 0 )
return - V_62 ;
return F_715 ( V_34 , V_15 , V_20 ) ;
}
long F_719 ( struct V_33 * V_34 )
{
T_2 V_703 ;
V_703 = F_18 ( V_34 -> V_9 . V_15 ) ;
F_352 ( V_703 , V_66 ) ;
return V_703 ;
}
static int F_720 ( void )
{
T_2 V_19 , V_18 ;
int V_133 = 0 ;
if ( V_65 <= 0 )
return - V_62 ;
V_19 = F_50 () ;
V_18 = F_49 () ;
if ( V_19 > V_18 && V_19 != V_26 )
return - V_62 ;
F_634 ( & V_701 ) ;
F_505 ( & V_457 ) ;
V_133 = F_714 ( NULL , 0 , 0 ) ;
F_511 ( & V_457 ) ;
F_635 ( & V_701 ) ;
return V_133 ;
}
int F_721 ( struct V_33 * V_34 , struct V_4 * V_123 )
{
if ( F_685 ( V_123 ) && V_34 -> V_9 . V_20 == 0 )
return 0 ;
return 1 ;
}
static int F_720 ( void )
{
unsigned long V_75 ;
int V_50 ;
if ( V_65 <= 0 )
return - V_62 ;
if ( V_25 == 0 )
return - V_700 ;
F_65 ( & V_656 . V_21 , V_75 ) ;
F_297 (i) {
struct V_44 * V_44 = & F_38 ( V_50 ) -> V_43 ;
F_15 ( & V_44 -> V_21 ) ;
V_44 -> V_20 = F_50 () ;
F_21 ( & V_44 -> V_21 ) ;
}
F_66 ( & V_656 . V_21 , V_75 ) ;
return 0 ;
}
int F_722 ( struct V_478 * V_484 , int V_704 ,
void T_5 * V_705 , T_6 * V_706 ,
T_7 * V_57 )
{
int V_133 ;
int V_707 , V_708 ;
static F_723 ( V_390 ) ;
F_634 ( & V_390 ) ;
V_707 = V_65 ;
V_708 = V_25 ;
V_133 = F_724 ( V_484 , V_704 , V_705 , V_706 , V_57 ) ;
if ( ! V_133 && V_704 ) {
V_133 = F_720 () ;
if ( V_133 ) {
V_65 = V_707 ;
V_25 = V_708 ;
} else {
V_656 . V_20 = F_50 () ;
V_656 . V_15 =
F_9 ( F_49 () ) ;
}
}
F_635 ( & V_390 ) ;
return V_133 ;
}
static inline struct V_33 * F_725 ( struct V_709 * V_710 )
{
return F_4 ( V_35 ( V_710 , V_37 ) ,
struct V_33 , V_36 ) ;
}
static struct V_35 *
F_726 ( struct V_711 * V_712 , struct V_709 * V_710 )
{
struct V_33 * V_34 , * V_42 ;
if ( ! V_710 -> V_42 ) {
return & V_134 . V_36 ;
}
V_42 = F_725 ( V_710 -> V_42 ) ;
V_34 = F_696 ( V_42 ) ;
if ( F_727 ( V_34 ) )
return F_697 ( - V_437 ) ;
return & V_34 -> V_36 ;
}
static void
F_728 ( struct V_711 * V_712 , struct V_709 * V_710 )
{
struct V_33 * V_34 = F_725 ( V_710 ) ;
F_700 ( V_34 ) ;
}
static int
F_729 ( struct V_709 * V_710 , struct V_4 * V_123 )
{
#ifdef F_32
if ( ! F_721 ( F_725 ( V_710 ) , V_123 ) )
return - V_62 ;
#else
if ( V_123 -> V_78 != & V_197 )
return - V_62 ;
#endif
return 0 ;
}
static void
F_730 ( struct V_709 * V_710 , struct V_4 * V_123 )
{
F_702 ( V_123 ) ;
}
static void
F_731 ( struct V_711 * V_712 , struct V_709 * V_710 ,
struct V_709 * V_713 , struct V_4 * V_475 )
{
if ( ! ( V_475 -> V_75 & V_714 ) )
return;
F_702 ( V_475 ) ;
}
static int F_732 ( struct V_709 * V_710 , struct V_715 * V_715 ,
T_2 V_716 )
{
return F_703 ( F_725 ( V_710 ) , F_149 ( V_716 ) ) ;
}
static T_2 F_733 ( struct V_709 * V_710 , struct V_715 * V_717 )
{
struct V_33 * V_34 = F_725 ( V_710 ) ;
return ( T_2 ) F_111 ( V_34 -> V_660 ) ;
}
static int F_734 ( struct V_709 * V_710 , struct V_715 * V_717 ,
T_3 V_127 )
{
return F_716 ( F_725 ( V_710 ) , V_127 ) ;
}
static T_3 F_735 ( struct V_709 * V_710 , struct V_715 * V_717 )
{
return F_717 ( F_725 ( V_710 ) ) ;
}
static int F_736 ( struct V_709 * V_710 , struct V_715 * V_715 ,
T_2 V_703 )
{
return F_718 ( F_725 ( V_710 ) , V_703 ) ;
}
static T_2 F_737 ( struct V_709 * V_710 , struct V_715 * V_717 )
{
return F_719 ( F_725 ( V_710 ) ) ;
}
static int F_738 ( struct V_711 * V_712 , struct V_709 * V_718 )
{
return F_739 ( V_718 , V_712 , V_719 , F_740 ( V_719 ) ) ;
}
static inline struct V_720 * F_741 ( struct V_709 * V_710 )
{
return F_4 ( V_35 ( V_710 , V_721 ) ,
struct V_720 , V_36 ) ;
}
static inline struct V_720 * F_742 ( struct V_4 * V_123 )
{
return F_4 ( F_743 ( V_123 , V_721 ) ,
struct V_720 , V_36 ) ;
}
static struct V_35 * F_744 (
struct V_711 * V_712 , struct V_709 * V_710 )
{
struct V_720 * V_722 = F_669 ( sizeof( * V_722 ) , V_436 ) ;
int V_50 ;
if ( ! V_722 )
goto V_259;
V_722 -> V_723 = F_620 ( T_2 ) ;
if ( ! V_722 -> V_723 )
goto V_724;
for ( V_50 = 0 ; V_50 < V_725 ; V_50 ++ )
if ( F_745 ( & V_722 -> V_177 [ V_50 ] , 0 ) )
goto V_726;
if ( V_710 -> V_42 )
V_722 -> V_42 = F_741 ( V_710 -> V_42 ) ;
return & V_722 -> V_36 ;
V_726:
while ( -- V_50 >= 0 )
F_746 ( & V_722 -> V_177 [ V_50 ] ) ;
F_616 ( V_722 -> V_723 ) ;
V_724:
F_540 ( V_722 ) ;
V_259:
return F_697 ( - V_437 ) ;
}
static void
F_747 ( struct V_711 * V_712 , struct V_709 * V_710 )
{
struct V_720 * V_722 = F_741 ( V_710 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_725 ; V_50 ++ )
F_746 ( & V_722 -> V_177 [ V_50 ] ) ;
F_616 ( V_722 -> V_723 ) ;
F_540 ( V_722 ) ;
}
static T_2 F_748 ( struct V_720 * V_722 , int V_32 )
{
T_2 * V_723 = F_605 ( V_722 -> V_723 , V_32 ) ;
T_2 V_131 ;
#ifndef F_660
F_382 ( & F_38 ( V_32 ) -> V_39 ) ;
V_131 = * V_723 ;
F_58 ( & F_38 ( V_32 ) -> V_39 ) ;
#else
V_131 = * V_723 ;
#endif
return V_131 ;
}
static void F_749 ( struct V_720 * V_722 , int V_32 , T_2 V_127 )
{
T_2 * V_723 = F_605 ( V_722 -> V_723 , V_32 ) ;
#ifndef F_660
F_382 ( & F_38 ( V_32 ) -> V_39 ) ;
* V_723 = V_127 ;
F_58 ( & F_38 ( V_32 ) -> V_39 ) ;
#else
* V_723 = V_127 ;
#endif
}
static T_2 F_750 ( struct V_709 * V_710 , struct V_715 * V_717 )
{
struct V_720 * V_722 = F_741 ( V_710 ) ;
T_2 V_727 = 0 ;
int V_50 ;
F_751 (i)
V_727 += F_748 ( V_722 , V_50 ) ;
return V_727 ;
}
static int F_752 ( struct V_709 * V_710 , struct V_715 * V_715 ,
T_2 V_728 )
{
struct V_720 * V_722 = F_741 ( V_710 ) ;
int V_514 = 0 ;
int V_50 ;
if ( V_728 ) {
V_514 = - V_62 ;
goto V_259;
}
F_751 (i)
F_749 ( V_722 , V_50 , 0 ) ;
V_259:
return V_514 ;
}
static int F_753 ( struct V_709 * V_709 , struct V_715 * V_717 ,
struct V_47 * V_48 )
{
struct V_720 * V_722 = F_741 ( V_709 ) ;
T_2 V_729 ;
int V_50 ;
F_751 (i) {
V_729 = F_748 ( V_722 , V_50 ) ;
F_41 ( V_48 , L_56 , ( unsigned long long ) V_729 ) ;
}
F_41 ( V_48 , L_3 ) ;
return 0 ;
}
static int F_754 ( struct V_709 * V_710 , struct V_715 * V_717 ,
struct V_730 * V_731 )
{
struct V_720 * V_722 = F_741 ( V_710 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_725 ; V_50 ++ ) {
T_3 V_127 = F_755 ( & V_722 -> V_177 [ V_50 ] ) ;
V_127 = F_756 ( V_127 ) ;
V_731 -> V_732 ( V_731 , V_733 [ V_50 ] , V_127 ) ;
}
return 0 ;
}
static int F_757 ( struct V_711 * V_712 , struct V_709 * V_710 )
{
return F_739 ( V_710 , V_712 , V_734 , F_740 ( V_734 ) ) ;
}
static void F_118 ( struct V_4 * V_123 , T_2 V_124 )
{
struct V_720 * V_722 ;
int V_32 ;
if ( F_112 ( ! V_735 . V_301 ) )
return;
V_32 = F_93 ( V_123 ) ;
F_101 () ;
V_722 = F_742 ( V_123 ) ;
for (; V_722 ; V_722 = V_722 -> V_42 ) {
T_2 * V_723 = F_605 ( V_722 -> V_723 , V_32 ) ;
* V_723 += V_124 ;
}
F_105 () ;
}
static void F_119 ( struct V_4 * V_123 ,
enum V_125 V_126 , T_9 V_127 )
{
struct V_720 * V_722 ;
int V_736 = V_737 ;
if ( F_112 ( ! V_735 . V_301 ) )
return;
F_101 () ;
V_722 = F_742 ( V_123 ) ;
do {
F_758 ( & V_722 -> V_177 [ V_126 ] , V_127 , V_736 ) ;
V_722 = V_722 -> V_42 ;
} while ( V_722 );
F_105 () ;
}
