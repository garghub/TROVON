void F_1 ( bool V_1 )
{
bool V_2 = V_3 && V_4 ;
unsigned int V_5 ;
if ( F_2 ( V_6 [ V_7 ] . V_8 ) == V_2 )
return;
F_3 (cpu) {
F_4 ( V_6 [ V_7 ] . V_8 , V_5 ) = V_2 ;
F_4 ( V_6 [ V_9 ] . V_8 , V_5 ) = V_2 ;
F_4 ( V_10 . V_8 , V_5 ) = V_2 ;
if ( ! V_1 )
continue;
F_4 ( V_6 [ V_7 ] . V_11 , V_5 ) = true ;
F_4 ( V_6 [ V_9 ] . V_11 , V_5 ) = true ;
F_4 ( V_10 . V_11 , V_5 ) = true ;
}
}
int F_5 ( struct V_12 * V_13 , int V_14 ,
void T_1 * V_15 , T_2 * V_16 ,
T_3 * V_17 )
{
static F_6 ( V_18 ) ;
int V_19 ;
F_7 ( & V_18 ) ;
V_19 = F_8 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
if ( ! V_19 && V_14 )
F_1 ( false ) ;
F_9 ( & V_18 ) ;
return V_19 ;
}
static unsigned long F_10 ( unsigned long V_20 , int V_5 ,
bool V_21 )
{
int V_22 ;
unsigned long V_23 = V_20 ;
V_20 += V_5 * 3 ;
V_22 = V_20 % V_24 ;
if ( V_22 < V_24 / 4 && ! V_21 )
V_20 = V_20 - V_22 ;
else
V_20 = V_20 - V_22 + V_24 ;
V_20 -= V_5 * 3 ;
return F_11 ( V_20 ) ? V_20 : V_23 ;
}
unsigned long F_12 ( unsigned long V_20 , int V_5 )
{
return F_10 ( V_20 , V_5 , false ) ;
}
unsigned long F_13 ( unsigned long V_20 , int V_5 )
{
unsigned long j0 = V_25 ;
return F_10 ( V_20 + j0 , V_5 , false ) - j0 ;
}
unsigned long F_14 ( unsigned long V_20 )
{
return F_10 ( V_20 , F_15 () , false ) ;
}
unsigned long F_16 ( unsigned long V_20 )
{
return F_13 ( V_20 , F_15 () ) ;
}
unsigned long F_17 ( unsigned long V_20 , int V_5 )
{
return F_10 ( V_20 , V_5 , true ) ;
}
unsigned long F_18 ( unsigned long V_20 , int V_5 )
{
unsigned long j0 = V_25 ;
return F_10 ( V_20 + j0 , V_5 , true ) - j0 ;
}
unsigned long F_19 ( unsigned long V_20 )
{
return F_10 ( V_20 , F_15 () , true ) ;
}
unsigned long F_20 ( unsigned long V_20 )
{
return F_18 ( V_20 , F_15 () ) ;
}
static inline unsigned int F_21 ( struct V_26 * V_27 )
{
return ( V_27 -> V_28 & V_29 ) >> V_30 ;
}
static inline void F_22 ( struct V_26 * V_27 , unsigned int V_31 )
{
V_27 -> V_28 = ( V_27 -> V_28 & ~ V_29 ) |
V_31 << V_30 ;
}
static inline unsigned F_23 ( unsigned V_32 , unsigned V_33 )
{
V_32 = ( V_32 + F_24 ( V_33 ) ) >> F_25 ( V_33 ) ;
return F_26 ( V_33 ) + ( V_32 & V_34 ) ;
}
static int F_27 ( unsigned long V_32 , unsigned long V_35 )
{
unsigned long V_36 = V_32 - V_35 ;
unsigned int V_31 ;
if ( V_36 < F_28 ( 1 ) ) {
V_31 = F_23 ( V_32 , 0 ) ;
} else if ( V_36 < F_28 ( 2 ) ) {
V_31 = F_23 ( V_32 , 1 ) ;
} else if ( V_36 < F_28 ( 3 ) ) {
V_31 = F_23 ( V_32 , 2 ) ;
} else if ( V_36 < F_28 ( 4 ) ) {
V_31 = F_23 ( V_32 , 3 ) ;
} else if ( V_36 < F_28 ( 5 ) ) {
V_31 = F_23 ( V_32 , 4 ) ;
} else if ( V_36 < F_28 ( 6 ) ) {
V_31 = F_23 ( V_32 , 5 ) ;
} else if ( V_36 < F_28 ( 7 ) ) {
V_31 = F_23 ( V_32 , 6 ) ;
} else if ( V_37 > 8 && V_36 < F_28 ( 8 ) ) {
V_31 = F_23 ( V_32 , 7 ) ;
} else if ( ( long ) V_36 < 0 ) {
V_31 = V_35 & V_34 ;
} else {
if ( V_32 >= V_38 )
V_32 = V_39 ;
V_31 = F_23 ( V_32 , V_37 - 1 ) ;
}
return V_31 ;
}
static void F_29 ( struct V_40 * V_41 , struct V_26 * V_27 ,
unsigned int V_31 )
{
F_30 ( & V_27 -> V_42 , V_41 -> V_43 + V_31 ) ;
F_31 ( V_31 , V_41 -> V_44 ) ;
F_22 ( V_27 , V_31 ) ;
}
static void
F_32 ( struct V_40 * V_41 , struct V_26 * V_27 )
{
unsigned int V_31 ;
V_31 = F_27 ( V_27 -> V_32 , V_41 -> V_35 ) ;
F_29 ( V_41 , V_27 , V_31 ) ;
}
static void
F_33 ( struct V_40 * V_41 , struct V_26 * V_27 )
{
if ( ! F_34 ( V_45 ) || ! V_41 -> V_11 )
return;
if ( V_27 -> V_28 & V_46 ) {
if ( F_35 ( V_41 -> V_5 ) )
F_36 ( V_41 -> V_5 ) ;
return;
}
if ( ! V_41 -> V_47 )
return;
if ( F_37 ( V_27 -> V_32 , V_41 -> V_48 ) )
return;
V_41 -> V_48 = V_27 -> V_32 ;
F_36 ( V_41 -> V_5 ) ;
}
static void
F_38 ( struct V_40 * V_41 , struct V_26 * V_27 )
{
F_32 ( V_41 , V_27 ) ;
F_33 ( V_41 , V_27 ) ;
}
void F_39 ( struct V_26 * V_27 , void * V_49 )
{
if ( V_27 -> V_50 )
return;
V_27 -> V_50 = V_49 ;
memcpy ( V_27 -> V_51 , V_52 -> V_53 , V_54 ) ;
V_27 -> V_55 = V_52 -> V_56 ;
}
static void F_40 ( struct V_26 * V_27 )
{
void * V_57 ;
V_57 = F_41 ( V_27 -> V_50 ) ;
if ( F_42 ( ! V_57 ) )
return;
F_43 ( V_27 , V_27 -> V_55 , V_57 ,
V_27 -> V_58 , V_27 -> V_51 ,
V_27 -> V_28 ) ;
}
static void F_40 ( struct V_26 * V_27 ) {}
static void * F_44 ( void * V_49 )
{
return ( (struct V_26 * ) V_49 ) -> V_58 ;
}
static bool F_45 ( void * V_49 )
{
struct V_26 * V_27 = V_49 ;
return ( V_27 -> V_42 . V_59 == NULL &&
V_27 -> V_42 . V_60 == V_61 ) ;
}
static bool F_46 ( void * V_49 , enum V_62 V_63 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_63 ) {
case V_64 :
F_47 ( V_27 ) ;
F_48 ( V_27 , & V_65 ) ;
return true ;
default:
return false ;
}
}
static void F_49 ( unsigned long V_66 )
{
F_50 ( 1 ) ;
}
static bool F_51 ( void * V_49 , enum V_62 V_63 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_63 ) {
case V_67 :
F_52 ( V_27 , F_49 , 0 ) ;
return true ;
case V_64 :
F_50 ( 1 ) ;
default:
return false ;
}
}
static bool F_53 ( void * V_49 , enum V_62 V_63 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_63 ) {
case V_64 :
F_47 ( V_27 ) ;
F_54 ( V_27 , & V_65 ) ;
return true ;
default:
return false ;
}
}
static bool F_55 ( void * V_49 , enum V_62 V_63 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_63 ) {
case V_67 :
F_52 ( V_27 , F_49 , 0 ) ;
return true ;
default:
return false ;
}
}
static inline void F_56 ( struct V_26 * V_27 )
{
F_48 ( V_27 , & V_65 ) ;
}
static inline void F_57 ( struct V_26 * V_27 )
{
F_58 ( V_27 , & V_65 ) ;
}
static inline void F_59 ( struct V_26 * V_27 )
{
F_60 ( V_27 , & V_65 ) ;
}
static inline void F_61 ( struct V_26 * V_27 )
{
F_54 ( V_27 , & V_65 ) ;
}
static inline void F_62 ( struct V_26 * V_27 )
{
F_63 ( V_27 , & V_65 ) ;
}
void F_64 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_68 , struct V_69 * V_70 )
{
F_65 ( V_27 , & V_65 ) ;
F_66 ( V_27 , V_28 , V_68 , V_70 ) ;
}
void F_67 ( struct V_26 * V_27 )
{
F_54 ( V_27 , & V_65 ) ;
}
static inline void F_56 ( struct V_26 * V_27 ) { }
static inline void F_57 ( struct V_26 * V_27 ) { }
static inline void F_59 ( struct V_26 * V_27 ) { }
static inline void F_62 ( struct V_26 * V_27 ) { }
static inline void F_68 ( struct V_26 * V_27 )
{
F_56 ( V_27 ) ;
F_69 ( V_27 ) ;
}
static inline void
F_70 ( struct V_26 * V_27 , unsigned long V_32 )
{
F_57 ( V_27 ) ;
F_71 ( V_27 , V_32 , V_27 -> V_28 ) ;
}
static inline void F_72 ( struct V_26 * V_27 )
{
F_59 ( V_27 ) ;
F_73 ( V_27 ) ;
}
static inline void F_74 ( struct V_26 * V_27 )
{
F_62 ( V_27 ) ;
}
static void F_66 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_68 , struct V_69 * V_70 )
{
V_27 -> V_42 . V_59 = NULL ;
V_27 -> V_28 = V_28 | F_15 () ;
#ifdef F_75
V_27 -> V_50 = NULL ;
V_27 -> V_55 = - 1 ;
memset ( V_27 -> V_51 , 0 , V_54 ) ;
#endif
F_76 ( & V_27 -> V_71 , V_68 , V_70 , 0 ) ;
}
void F_77 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_68 , struct V_69 * V_70 )
{
F_68 ( V_27 ) ;
F_66 ( V_27 , V_28 , V_68 , V_70 ) ;
}
static inline void F_78 ( struct V_26 * V_27 , bool V_72 )
{
struct V_73 * V_42 = & V_27 -> V_42 ;
F_72 ( V_27 ) ;
F_79 ( V_42 ) ;
if ( V_72 )
V_42 -> V_59 = NULL ;
V_42 -> V_60 = V_74 ;
}
static int F_80 ( struct V_26 * V_27 , struct V_40 * V_41 ,
bool V_72 )
{
unsigned V_31 = F_21 ( V_27 ) ;
if ( ! F_81 ( V_27 ) )
return 0 ;
if ( F_82 ( & V_27 -> V_42 , V_41 -> V_43 + V_31 ) )
F_83 ( V_31 , V_41 -> V_44 ) ;
F_78 ( V_27 , V_72 ) ;
return 1 ;
}
static inline struct V_40 * F_84 ( T_4 V_75 , T_4 V_5 )
{
struct V_40 * V_41 = F_85 ( & V_6 [ V_7 ] , V_5 ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 &&
( V_75 & V_46 ) )
V_41 = F_85 ( & V_6 [ V_9 ] , V_5 ) ;
return V_41 ;
}
static inline struct V_40 * F_86 ( T_4 V_75 )
{
struct V_40 * V_41 = F_87 ( & V_6 [ V_7 ] ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 &&
( V_75 & V_46 ) )
V_41 = F_87 ( & V_6 [ V_9 ] ) ;
return V_41 ;
}
static inline struct V_40 * F_88 ( T_4 V_75 )
{
return F_84 ( V_75 , V_75 & V_76 ) ;
}
static inline struct V_40 *
F_89 ( struct V_40 * V_41 , unsigned V_75 )
{
#ifdef F_90
if ( ( V_75 & V_77 ) || ! V_41 -> V_8 )
return F_86 ( V_75 ) ;
return F_84 ( V_75 , F_91 () ) ;
#else
return F_86 ( V_75 ) ;
#endif
}
static inline void F_92 ( struct V_40 * V_41 )
{
unsigned long V_78 = F_41 ( V_25 ) ;
if ( ! V_41 -> V_47 || ( long ) ( V_78 - V_41 -> V_35 ) < 2 )
return;
if ( F_93 ( V_41 -> V_48 , V_78 ) )
V_41 -> V_35 = V_78 ;
else
V_41 -> V_35 = V_41 -> V_48 ;
}
static inline struct V_40 *
F_89 ( struct V_40 * V_41 , unsigned V_75 )
{
return F_86 ( V_75 ) ;
}
static inline void F_92 ( struct V_40 * V_41 ) { }
static struct V_40 * F_94 ( struct V_26 * V_27 ,
unsigned long * V_28 )
__acquires( V_27 -> V_41 -> V_79 )
{
for (; ; ) {
struct V_40 * V_41 ;
T_4 V_80 ;
V_80 = F_41 ( V_27 -> V_28 ) ;
if ( ! ( V_80 & V_81 ) ) {
V_41 = F_88 ( V_80 ) ;
F_95 ( & V_41 -> V_79 , * V_28 ) ;
if ( V_27 -> V_28 == V_80 )
return V_41 ;
F_96 ( & V_41 -> V_79 , * V_28 ) ;
}
F_97 () ;
}
}
static inline int
F_98 ( struct V_26 * V_27 , unsigned long V_32 , bool V_82 )
{
struct V_40 * V_41 , * V_83 ;
unsigned int V_31 = V_84 ;
unsigned long V_35 = 0 , V_28 ;
int V_19 = 0 ;
F_99 ( ! V_27 -> V_58 ) ;
if ( F_81 ( V_27 ) ) {
if ( V_27 -> V_32 == V_32 )
return 1 ;
V_41 = F_94 ( V_27 , & V_28 ) ;
V_35 = V_41 -> V_35 ;
V_31 = F_27 ( V_32 , V_35 ) ;
if ( V_31 == F_21 ( V_27 ) ) {
V_27 -> V_32 = V_32 ;
V_19 = 1 ;
goto V_85;
}
} else {
V_41 = F_94 ( V_27 , & V_28 ) ;
}
F_100 ( V_27 ) ;
V_19 = F_80 ( V_27 , V_41 , false ) ;
if ( ! V_19 && V_82 )
goto V_85;
F_70 ( V_27 , V_32 ) ;
V_83 = F_89 ( V_41 , V_27 -> V_28 ) ;
if ( V_41 != V_83 ) {
if ( F_42 ( V_41 -> V_86 != V_27 ) ) {
V_27 -> V_28 |= V_81 ;
F_101 ( & V_41 -> V_79 ) ;
V_41 = V_83 ;
F_102 ( & V_41 -> V_79 ) ;
F_103 ( V_27 -> V_28 ,
( V_27 -> V_28 & ~ V_87 ) | V_41 -> V_5 ) ;
}
}
F_92 ( V_41 ) ;
V_27 -> V_32 = V_32 ;
if ( V_31 != V_84 && V_35 == V_41 -> V_35 ) {
F_29 ( V_41 , V_27 , V_31 ) ;
F_33 ( V_41 , V_27 ) ;
} else {
F_38 ( V_41 , V_27 ) ;
}
V_85:
F_96 ( & V_41 -> V_79 , V_28 ) ;
return V_19 ;
}
int F_104 ( struct V_26 * V_27 , unsigned long V_32 )
{
return F_98 ( V_27 , V_32 , true ) ;
}
int F_105 ( struct V_26 * V_27 , unsigned long V_32 )
{
return F_98 ( V_27 , V_32 , false ) ;
}
void F_106 ( struct V_26 * V_27 )
{
F_99 ( F_81 ( V_27 ) ) ;
F_105 ( V_27 , V_27 -> V_32 ) ;
}
void F_107 ( struct V_26 * V_27 , int V_5 )
{
struct V_40 * V_83 , * V_41 ;
unsigned long V_28 ;
F_100 ( V_27 ) ;
F_99 ( F_81 ( V_27 ) || ! V_27 -> V_58 ) ;
V_83 = F_84 ( V_27 -> V_28 , V_5 ) ;
V_41 = F_94 ( V_27 , & V_28 ) ;
if ( V_41 != V_83 ) {
V_27 -> V_28 |= V_81 ;
F_101 ( & V_41 -> V_79 ) ;
V_41 = V_83 ;
F_102 ( & V_41 -> V_79 ) ;
F_103 ( V_27 -> V_28 ,
( V_27 -> V_28 & ~ V_87 ) | V_5 ) ;
}
F_70 ( V_27 , V_27 -> V_32 ) ;
F_38 ( V_41 , V_27 ) ;
F_96 ( & V_41 -> V_79 , V_28 ) ;
}
int F_108 ( struct V_26 * V_27 )
{
struct V_40 * V_41 ;
unsigned long V_28 ;
int V_19 = 0 ;
F_74 ( V_27 ) ;
F_109 ( V_27 ) ;
if ( F_81 ( V_27 ) ) {
V_41 = F_94 ( V_27 , & V_28 ) ;
V_19 = F_80 ( V_27 , V_41 , true ) ;
F_96 ( & V_41 -> V_79 , V_28 ) ;
}
return V_19 ;
}
int F_110 ( struct V_26 * V_27 )
{
struct V_40 * V_41 ;
unsigned long V_28 ;
int V_19 = - 1 ;
F_74 ( V_27 ) ;
V_41 = F_94 ( V_27 , & V_28 ) ;
if ( V_41 -> V_86 != V_27 ) {
F_109 ( V_27 ) ;
V_19 = F_80 ( V_27 , V_41 , true ) ;
}
F_96 ( & V_41 -> V_79 , V_28 ) ;
return V_19 ;
}
int F_47 ( struct V_26 * V_27 )
{
#ifdef F_111
unsigned long V_28 ;
F_112 ( V_28 ) ;
F_113 ( & V_27 -> V_71 ) ;
F_114 ( & V_27 -> V_71 ) ;
F_115 ( V_28 ) ;
#endif
F_50 ( F_116 () && ! ( V_27 -> V_28 & V_88 ) ) ;
for (; ; ) {
int V_19 = F_110 ( V_27 ) ;
if ( V_19 >= 0 )
return V_19 ;
F_97 () ;
}
}
static void F_117 ( struct V_26 * V_27 , void (* F_118)( unsigned long ) ,
unsigned long V_66 )
{
int V_89 = F_119 () ;
#ifdef F_111
struct V_71 V_71 ;
F_120 ( & V_71 , & V_27 -> V_71 ) ;
#endif
F_113 ( & V_71 ) ;
F_121 ( V_27 ) ;
F_118 ( V_66 ) ;
F_122 ( V_27 ) ;
F_114 ( & V_71 ) ;
if ( V_89 != F_119 () ) {
F_123 ( 1 , L_1 ,
F_118 , V_89 , F_119 () ) ;
F_124 ( V_89 ) ;
}
}
static void F_125 ( struct V_40 * V_41 , struct V_90 * V_91 )
{
while ( ! F_126 ( V_91 ) ) {
struct V_26 * V_27 ;
void (* F_118)( unsigned long );
unsigned long V_66 ;
V_27 = F_127 ( V_91 -> V_92 , struct V_26 , V_42 ) ;
F_40 ( V_27 ) ;
V_41 -> V_86 = V_27 ;
F_78 ( V_27 , true ) ;
F_118 = V_27 -> V_58 ;
V_66 = V_27 -> V_66 ;
if ( V_27 -> V_28 & V_88 ) {
F_101 ( & V_41 -> V_79 ) ;
F_117 ( V_27 , F_118 , V_66 ) ;
F_102 ( & V_41 -> V_79 ) ;
} else {
F_128 ( & V_41 -> V_79 ) ;
F_117 ( V_27 , F_118 , V_66 ) ;
F_129 ( & V_41 -> V_79 ) ;
}
}
}
static int F_130 ( struct V_40 * V_41 ,
struct V_90 * V_93 )
{
unsigned long V_35 = V_41 -> V_35 ;
struct V_90 * V_94 ;
int V_95 , V_96 = 0 ;
unsigned int V_31 ;
for ( V_95 = 0 ; V_95 < V_37 ; V_95 ++ ) {
V_31 = ( V_35 & V_34 ) + V_95 * V_97 ;
if ( F_131 ( V_31 , V_41 -> V_44 ) ) {
V_94 = V_41 -> V_43 + V_31 ;
F_132 ( V_94 , V_93 ++ ) ;
V_96 ++ ;
}
if ( V_35 & V_98 )
break;
V_35 >>= V_99 ;
}
return V_96 ;
}
static int F_133 ( struct V_40 * V_41 , unsigned V_100 ,
unsigned V_35 )
{
unsigned V_101 , V_102 = V_100 + V_35 ;
unsigned V_103 = V_100 + V_97 ;
V_101 = F_134 ( V_41 -> V_44 , V_103 , V_102 ) ;
if ( V_101 < V_103 )
return V_101 - V_102 ;
V_101 = F_134 ( V_41 -> V_44 , V_102 , V_100 ) ;
return V_101 < V_102 ? V_101 + V_97 - V_102 : - 1 ;
}
static unsigned long F_135 ( struct V_40 * V_41 )
{
unsigned long V_35 , V_60 , V_104 ;
unsigned V_33 , V_100 = 0 ;
V_60 = V_41 -> V_35 + V_105 ;
V_35 = V_41 -> V_35 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ , V_100 += V_97 ) {
int V_101 = F_133 ( V_41 , V_100 , V_35 & V_34 ) ;
if ( V_101 >= 0 ) {
unsigned long V_106 = V_35 + ( unsigned long ) V_101 ;
V_106 <<= F_25 ( V_33 ) ;
if ( F_136 ( V_106 , V_60 ) )
V_60 = V_106 ;
}
V_104 = V_35 & V_98 ? 1 : 0 ;
V_35 >>= V_99 ;
V_35 += V_104 ;
}
return V_60 ;
}
static T_5 F_137 ( T_5 V_107 , T_5 V_32 )
{
T_5 V_108 = F_138 () ;
if ( V_32 <= V_108 )
return V_32 ;
if ( V_108 <= V_107 )
return V_107 ;
return F_139 ( V_108 , V_109 ) * V_109 ;
}
T_5 F_140 ( unsigned long V_110 , T_5 V_107 )
{
struct V_40 * V_41 = F_87 ( & V_6 [ V_7 ] ) ;
T_5 V_32 = V_111 ;
unsigned long V_108 ;
bool V_112 ;
if ( F_141 ( F_142 () ) )
return V_32 ;
F_102 ( & V_41 -> V_79 ) ;
V_108 = F_135 ( V_41 ) ;
V_112 = ( V_108 == V_41 -> V_35 + V_105 ) ;
V_41 -> V_48 = V_108 ;
if ( F_93 ( V_110 , V_41 -> V_35 ) ) {
if ( F_93 ( V_108 , V_110 ) )
V_41 -> V_35 = V_110 ;
else if ( F_93 ( V_108 , V_41 -> V_35 ) )
V_41 -> V_35 = V_108 ;
}
if ( F_143 ( V_108 , V_110 ) ) {
V_32 = V_107 ;
V_41 -> V_47 = false ;
} else {
if ( ! V_112 )
V_32 = V_107 + ( V_108 - V_110 ) * V_109 ;
if ( ( V_32 - V_107 ) > V_109 )
V_41 -> V_47 = true ;
}
F_101 ( & V_41 -> V_79 ) ;
return F_137 ( V_107 , V_32 ) ;
}
void F_144 ( void )
{
struct V_40 * V_41 = F_87 ( & V_6 [ V_7 ] ) ;
V_41 -> V_47 = false ;
}
static int F_145 ( struct V_40 * V_41 ,
struct V_90 * V_93 )
{
if ( ( long ) ( V_25 - V_41 -> V_35 ) > 2 ) {
unsigned long V_60 = F_135 ( V_41 ) ;
if ( F_93 ( V_60 , V_25 ) ) {
V_41 -> V_35 = V_25 - 1 ;
return 0 ;
}
V_41 -> V_35 = V_60 ;
}
return F_130 ( V_41 , V_93 ) ;
}
static inline int F_145 ( struct V_40 * V_41 ,
struct V_90 * V_93 )
{
return F_130 ( V_41 , V_93 ) ;
}
void F_146 ( int V_113 )
{
struct V_114 * V_115 = V_52 ;
F_147 ( V_115 , V_113 ) ;
F_148 () ;
F_149 ( V_113 ) ;
#ifdef F_150
if ( F_116 () )
F_151 () ;
#endif
F_152 () ;
F_153 ( V_115 ) ;
}
static inline void F_154 ( struct V_40 * V_41 )
{
struct V_90 V_93 [ V_37 ] ;
int V_96 ;
if ( ! F_37 ( V_25 , V_41 -> V_35 ) )
return;
F_129 ( & V_41 -> V_79 ) ;
while ( F_37 ( V_25 , V_41 -> V_35 ) ) {
V_96 = F_145 ( V_41 , V_93 ) ;
V_41 -> V_35 ++ ;
while ( V_96 -- )
F_125 ( V_41 , V_93 + V_96 ) ;
}
V_41 -> V_86 = NULL ;
F_128 ( & V_41 -> V_79 ) ;
}
static T_6 void F_155 ( struct V_116 * V_117 )
{
struct V_40 * V_41 = F_87 ( & V_6 [ V_7 ] ) ;
F_154 ( V_41 ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 )
F_154 ( F_87 ( & V_6 [ V_9 ] ) ) ;
}
void F_148 ( void )
{
struct V_40 * V_41 = F_87 ( & V_6 [ V_7 ] ) ;
F_156 () ;
if ( F_136 ( V_25 , V_41 -> V_35 ) ) {
if ( ! F_34 ( V_45 ) || ! V_41 -> V_11 )
return;
V_41 ++ ;
if ( F_136 ( V_25 , V_41 -> V_35 ) )
return;
}
F_157 ( V_118 ) ;
}
static void F_158 ( unsigned long V_119 )
{
F_159 ( (struct V_114 * ) V_119 ) ;
}
signed long T_7 F_160 ( signed long V_120 )
{
struct V_26 V_27 ;
unsigned long V_121 ;
switch ( V_120 )
{
case V_122 :
F_161 () ;
goto V_123;
default:
if ( V_120 < 0 ) {
F_162 ( V_124 L_2
L_3 , V_120 ) ;
F_163 () ;
V_52 -> V_63 = V_125 ;
goto V_123;
}
}
V_121 = V_120 + V_25 ;
F_164 ( & V_27 , F_158 , ( unsigned long ) V_52 ) ;
F_98 ( & V_27 , V_121 , false ) ;
F_161 () ;
F_165 ( & V_27 ) ;
F_67 ( & V_27 ) ;
V_120 = V_121 - V_25 ;
V_123:
return V_120 < 0 ? 0 : V_120 ;
}
signed long T_7 F_166 ( signed long V_120 )
{
F_167 ( V_126 ) ;
return F_160 ( V_120 ) ;
}
signed long T_7 F_168 ( signed long V_120 )
{
F_167 ( V_127 ) ;
return F_160 ( V_120 ) ;
}
signed long T_7 F_169 ( signed long V_120 )
{
F_167 ( V_128 ) ;
return F_160 ( V_120 ) ;
}
signed long T_7 F_170 ( signed long V_120 )
{
F_167 ( V_129 ) ;
return F_160 ( V_120 ) ;
}
static void F_171 ( struct V_40 * V_83 , struct V_90 * V_91 )
{
struct V_26 * V_27 ;
int V_5 = V_83 -> V_5 ;
while ( ! F_126 ( V_91 ) ) {
V_27 = F_127 ( V_91 -> V_92 , struct V_26 , V_42 ) ;
F_78 ( V_27 , false ) ;
V_27 -> V_28 = ( V_27 -> V_28 & ~ V_87 ) | V_5 ;
F_38 ( V_83 , V_27 ) ;
}
}
int F_172 ( unsigned int V_5 )
{
struct V_40 * V_130 ;
struct V_40 * V_83 ;
int V_131 , V_95 ;
F_99 ( F_173 ( V_5 ) ) ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
V_130 = F_85 ( & V_6 [ V_131 ] , V_5 ) ;
V_83 = F_174 ( & V_6 [ V_131 ] ) ;
F_129 ( & V_83 -> V_79 ) ;
F_175 ( & V_130 -> V_79 , V_133 ) ;
F_99 ( V_130 -> V_86 ) ;
for ( V_95 = 0 ; V_95 < V_134 ; V_95 ++ )
F_171 ( V_83 , V_130 -> V_43 + V_95 ) ;
F_101 ( & V_130 -> V_79 ) ;
F_128 ( & V_83 -> V_79 ) ;
F_176 ( & V_6 ) ;
}
return 0 ;
}
static void T_8 F_177 ( int V_5 )
{
struct V_40 * V_41 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_132 ; V_95 ++ ) {
V_41 = F_85 ( & V_6 [ V_95 ] , V_5 ) ;
V_41 -> V_5 = V_5 ;
F_178 ( & V_41 -> V_79 ) ;
V_41 -> V_35 = V_25 ;
}
}
static void T_8 F_179 ( void )
{
int V_5 ;
F_3 (cpu)
F_177 ( V_5 ) ;
}
void T_8 F_180 ( void )
{
F_179 () ;
F_181 () ;
F_182 ( V_118 , F_155 ) ;
}
void F_183 ( unsigned int V_135 )
{
unsigned long V_120 = F_184 ( V_135 ) + 1 ;
while ( V_120 )
V_120 = F_169 ( V_120 ) ;
}
unsigned long F_185 ( unsigned int V_135 )
{
unsigned long V_120 = F_184 ( V_135 ) + 1 ;
while ( V_120 && ! F_186 ( V_52 ) )
V_120 = F_166 ( V_120 ) ;
return F_187 ( V_120 ) ;
}
static void T_7 F_188 ( unsigned long V_136 , unsigned long V_137 )
{
T_9 V_138 ;
T_5 V_36 ;
V_138 = F_189 ( 0 , V_136 * V_139 ) ;
V_36 = ( T_5 ) ( V_137 - V_136 ) * V_139 ;
F_190 ( & V_138 , V_36 , V_140 ) ;
}
void T_7 F_191 ( unsigned long V_136 , unsigned long V_137 )
{
F_167 ( V_128 ) ;
F_188 ( V_136 , V_137 ) ;
}
