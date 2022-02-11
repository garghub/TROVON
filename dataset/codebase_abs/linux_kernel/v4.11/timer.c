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
static void * F_39 ( void * V_49 )
{
return ( (struct V_26 * ) V_49 ) -> V_50 ;
}
static bool F_40 ( void * V_49 )
{
struct V_26 * V_27 = V_49 ;
return ( V_27 -> V_42 . V_51 == NULL &&
V_27 -> V_42 . V_52 == V_53 ) ;
}
static bool F_41 ( void * V_49 , enum V_54 V_55 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_55 ) {
case V_56 :
F_42 ( V_27 ) ;
F_43 ( V_27 , & V_57 ) ;
return true ;
default:
return false ;
}
}
static void F_44 ( unsigned long V_58 )
{
F_45 ( 1 ) ;
}
static bool F_46 ( void * V_49 , enum V_54 V_55 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_55 ) {
case V_59 :
F_47 ( V_27 , F_44 , 0 ) ;
return true ;
case V_56 :
F_45 ( 1 ) ;
default:
return false ;
}
}
static bool F_48 ( void * V_49 , enum V_54 V_55 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_55 ) {
case V_56 :
F_42 ( V_27 ) ;
F_49 ( V_27 , & V_57 ) ;
return true ;
default:
return false ;
}
}
static bool F_50 ( void * V_49 , enum V_54 V_55 )
{
struct V_26 * V_27 = V_49 ;
switch ( V_55 ) {
case V_59 :
F_47 ( V_27 , F_44 , 0 ) ;
return true ;
default:
return false ;
}
}
static inline void F_51 ( struct V_26 * V_27 )
{
F_43 ( V_27 , & V_57 ) ;
}
static inline void F_52 ( struct V_26 * V_27 )
{
F_53 ( V_27 , & V_57 ) ;
}
static inline void F_54 ( struct V_26 * V_27 )
{
F_55 ( V_27 , & V_57 ) ;
}
static inline void F_56 ( struct V_26 * V_27 )
{
F_49 ( V_27 , & V_57 ) ;
}
static inline void F_57 ( struct V_26 * V_27 )
{
F_58 ( V_27 , & V_57 ) ;
}
void F_59 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_60 , struct V_61 * V_62 )
{
F_60 ( V_27 , & V_57 ) ;
F_61 ( V_27 , V_28 , V_60 , V_62 ) ;
}
void F_62 ( struct V_26 * V_27 )
{
F_49 ( V_27 , & V_57 ) ;
}
static inline void F_51 ( struct V_26 * V_27 ) { }
static inline void F_52 ( struct V_26 * V_27 ) { }
static inline void F_54 ( struct V_26 * V_27 ) { }
static inline void F_57 ( struct V_26 * V_27 ) { }
static inline void F_63 ( struct V_26 * V_27 )
{
F_51 ( V_27 ) ;
F_64 ( V_27 ) ;
}
static inline void
F_65 ( struct V_26 * V_27 , unsigned long V_32 )
{
F_52 ( V_27 ) ;
F_66 ( V_27 , V_32 , V_27 -> V_28 ) ;
}
static inline void F_67 ( struct V_26 * V_27 )
{
F_54 ( V_27 ) ;
F_68 ( V_27 ) ;
}
static inline void F_69 ( struct V_26 * V_27 )
{
F_57 ( V_27 ) ;
}
static void F_61 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_60 , struct V_61 * V_62 )
{
V_27 -> V_42 . V_51 = NULL ;
V_27 -> V_28 = V_28 | F_15 () ;
F_70 ( & V_27 -> V_63 , V_60 , V_62 , 0 ) ;
}
void F_71 ( struct V_26 * V_27 , unsigned int V_28 ,
const char * V_60 , struct V_61 * V_62 )
{
F_63 ( V_27 ) ;
F_61 ( V_27 , V_28 , V_60 , V_62 ) ;
}
static inline void F_72 ( struct V_26 * V_27 , bool V_64 )
{
struct V_65 * V_42 = & V_27 -> V_42 ;
F_67 ( V_27 ) ;
F_73 ( V_42 ) ;
if ( V_64 )
V_42 -> V_51 = NULL ;
V_42 -> V_52 = V_66 ;
}
static int F_74 ( struct V_26 * V_27 , struct V_40 * V_41 ,
bool V_64 )
{
unsigned V_31 = F_21 ( V_27 ) ;
if ( ! F_75 ( V_27 ) )
return 0 ;
if ( F_76 ( & V_27 -> V_42 , V_41 -> V_43 + V_31 ) )
F_77 ( V_31 , V_41 -> V_44 ) ;
F_72 ( V_27 , V_64 ) ;
return 1 ;
}
static inline struct V_40 * F_78 ( T_4 V_67 , T_4 V_5 )
{
struct V_40 * V_41 = F_79 ( & V_6 [ V_7 ] , V_5 ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 &&
( V_67 & V_46 ) )
V_41 = F_79 ( & V_6 [ V_9 ] , V_5 ) ;
return V_41 ;
}
static inline struct V_40 * F_80 ( T_4 V_67 )
{
struct V_40 * V_41 = F_81 ( & V_6 [ V_7 ] ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 &&
( V_67 & V_46 ) )
V_41 = F_81 ( & V_6 [ V_9 ] ) ;
return V_41 ;
}
static inline struct V_40 * F_82 ( T_4 V_67 )
{
return F_78 ( V_67 , V_67 & V_68 ) ;
}
static inline struct V_40 *
F_83 ( struct V_40 * V_41 , unsigned V_67 )
{
#ifdef F_84
if ( ( V_67 & V_69 ) || ! V_41 -> V_8 )
return F_80 ( V_67 ) ;
return F_78 ( V_67 , F_85 () ) ;
#else
return F_80 ( V_67 ) ;
#endif
}
static inline void F_86 ( struct V_40 * V_41 )
{
unsigned long V_70 = F_87 ( V_25 ) ;
if ( ! V_41 -> V_47 || ( long ) ( V_70 - V_41 -> V_35 ) < 2 )
return;
if ( F_88 ( V_41 -> V_48 , V_70 ) )
V_41 -> V_35 = V_70 ;
else
V_41 -> V_35 = V_41 -> V_48 ;
}
static inline struct V_40 *
F_83 ( struct V_40 * V_41 , unsigned V_67 )
{
return F_80 ( V_67 ) ;
}
static inline void F_86 ( struct V_40 * V_41 ) { }
static struct V_40 * F_89 ( struct V_26 * V_27 ,
unsigned long * V_28 )
__acquires( V_27 -> V_41 -> V_71 )
{
for (; ; ) {
struct V_40 * V_41 ;
T_4 V_72 ;
V_72 = F_87 ( V_27 -> V_28 ) ;
if ( ! ( V_72 & V_73 ) ) {
V_41 = F_82 ( V_72 ) ;
F_90 ( & V_41 -> V_71 , * V_28 ) ;
if ( V_27 -> V_28 == V_72 )
return V_41 ;
F_91 ( & V_41 -> V_71 , * V_28 ) ;
}
F_92 () ;
}
}
static inline int
F_93 ( struct V_26 * V_27 , unsigned long V_32 , bool V_74 )
{
struct V_40 * V_41 , * V_75 ;
unsigned int V_31 = V_76 ;
unsigned long V_35 = 0 , V_28 ;
int V_19 = 0 ;
F_94 ( ! V_27 -> V_50 ) ;
if ( F_75 ( V_27 ) ) {
if ( V_27 -> V_32 == V_32 )
return 1 ;
V_41 = F_89 ( V_27 , & V_28 ) ;
V_35 = V_41 -> V_35 ;
V_31 = F_27 ( V_32 , V_35 ) ;
if ( V_31 == F_21 ( V_27 ) ) {
V_27 -> V_32 = V_32 ;
V_19 = 1 ;
goto V_77;
}
} else {
V_41 = F_89 ( V_27 , & V_28 ) ;
}
V_19 = F_74 ( V_27 , V_41 , false ) ;
if ( ! V_19 && V_74 )
goto V_77;
F_65 ( V_27 , V_32 ) ;
V_75 = F_83 ( V_41 , V_27 -> V_28 ) ;
if ( V_41 != V_75 ) {
if ( F_95 ( V_41 -> V_78 != V_27 ) ) {
V_27 -> V_28 |= V_73 ;
F_96 ( & V_41 -> V_71 ) ;
V_41 = V_75 ;
F_97 ( & V_41 -> V_71 ) ;
F_98 ( V_27 -> V_28 ,
( V_27 -> V_28 & ~ V_79 ) | V_41 -> V_5 ) ;
}
}
F_86 ( V_41 ) ;
V_27 -> V_32 = V_32 ;
if ( V_31 != V_76 && V_35 == V_41 -> V_35 ) {
F_29 ( V_41 , V_27 , V_31 ) ;
F_33 ( V_41 , V_27 ) ;
} else {
F_38 ( V_41 , V_27 ) ;
}
V_77:
F_91 ( & V_41 -> V_71 , V_28 ) ;
return V_19 ;
}
int F_99 ( struct V_26 * V_27 , unsigned long V_32 )
{
return F_93 ( V_27 , V_32 , true ) ;
}
int F_100 ( struct V_26 * V_27 , unsigned long V_32 )
{
return F_93 ( V_27 , V_32 , false ) ;
}
void F_101 ( struct V_26 * V_27 )
{
F_94 ( F_75 ( V_27 ) ) ;
F_100 ( V_27 , V_27 -> V_32 ) ;
}
void F_102 ( struct V_26 * V_27 , int V_5 )
{
struct V_40 * V_75 , * V_41 ;
unsigned long V_28 ;
F_94 ( F_75 ( V_27 ) || ! V_27 -> V_50 ) ;
V_75 = F_78 ( V_27 -> V_28 , V_5 ) ;
V_41 = F_89 ( V_27 , & V_28 ) ;
if ( V_41 != V_75 ) {
V_27 -> V_28 |= V_73 ;
F_96 ( & V_41 -> V_71 ) ;
V_41 = V_75 ;
F_97 ( & V_41 -> V_71 ) ;
F_98 ( V_27 -> V_28 ,
( V_27 -> V_28 & ~ V_79 ) | V_5 ) ;
}
F_65 ( V_27 , V_27 -> V_32 ) ;
F_38 ( V_41 , V_27 ) ;
F_91 ( & V_41 -> V_71 , V_28 ) ;
}
int F_103 ( struct V_26 * V_27 )
{
struct V_40 * V_41 ;
unsigned long V_28 ;
int V_19 = 0 ;
F_69 ( V_27 ) ;
if ( F_75 ( V_27 ) ) {
V_41 = F_89 ( V_27 , & V_28 ) ;
V_19 = F_74 ( V_27 , V_41 , true ) ;
F_91 ( & V_41 -> V_71 , V_28 ) ;
}
return V_19 ;
}
int F_104 ( struct V_26 * V_27 )
{
struct V_40 * V_41 ;
unsigned long V_28 ;
int V_19 = - 1 ;
F_69 ( V_27 ) ;
V_41 = F_89 ( V_27 , & V_28 ) ;
if ( V_41 -> V_78 != V_27 )
V_19 = F_74 ( V_27 , V_41 , true ) ;
F_91 ( & V_41 -> V_71 , V_28 ) ;
return V_19 ;
}
int F_42 ( struct V_26 * V_27 )
{
#ifdef F_105
unsigned long V_28 ;
F_106 ( V_28 ) ;
F_107 ( & V_27 -> V_63 ) ;
F_108 ( & V_27 -> V_63 ) ;
F_109 ( V_28 ) ;
#endif
F_45 ( F_110 () && ! ( V_27 -> V_28 & V_80 ) ) ;
for (; ; ) {
int V_19 = F_104 ( V_27 ) ;
if ( V_19 >= 0 )
return V_19 ;
F_92 () ;
}
}
static void F_111 ( struct V_26 * V_27 , void (* F_112)( unsigned long ) ,
unsigned long V_58 )
{
int V_81 = F_113 () ;
#ifdef F_105
struct V_63 V_63 ;
F_114 ( & V_63 , & V_27 -> V_63 ) ;
#endif
F_107 ( & V_63 ) ;
F_115 ( V_27 ) ;
F_112 ( V_58 ) ;
F_116 ( V_27 ) ;
F_108 ( & V_63 ) ;
if ( V_81 != F_113 () ) {
F_117 ( 1 , L_1 ,
F_112 , V_81 , F_113 () ) ;
F_118 ( V_81 ) ;
}
}
static void F_119 ( struct V_40 * V_41 , struct V_82 * V_83 )
{
while ( ! F_120 ( V_83 ) ) {
struct V_26 * V_27 ;
void (* F_112)( unsigned long );
unsigned long V_58 ;
V_27 = F_121 ( V_83 -> V_84 , struct V_26 , V_42 ) ;
V_41 -> V_78 = V_27 ;
F_72 ( V_27 , true ) ;
F_112 = V_27 -> V_50 ;
V_58 = V_27 -> V_58 ;
if ( V_27 -> V_28 & V_80 ) {
F_96 ( & V_41 -> V_71 ) ;
F_111 ( V_27 , F_112 , V_58 ) ;
F_97 ( & V_41 -> V_71 ) ;
} else {
F_122 ( & V_41 -> V_71 ) ;
F_111 ( V_27 , F_112 , V_58 ) ;
F_123 ( & V_41 -> V_71 ) ;
}
}
}
static int F_124 ( struct V_40 * V_41 ,
struct V_82 * V_85 )
{
unsigned long V_35 = V_41 -> V_35 ;
struct V_82 * V_86 ;
int V_87 , V_88 = 0 ;
unsigned int V_31 ;
for ( V_87 = 0 ; V_87 < V_37 ; V_87 ++ ) {
V_31 = ( V_35 & V_34 ) + V_87 * V_89 ;
if ( F_125 ( V_31 , V_41 -> V_44 ) ) {
V_86 = V_41 -> V_43 + V_31 ;
F_126 ( V_86 , V_85 ++ ) ;
V_88 ++ ;
}
if ( V_35 & V_90 )
break;
V_35 >>= V_91 ;
}
return V_88 ;
}
static int F_127 ( struct V_40 * V_41 , unsigned V_92 ,
unsigned V_35 )
{
unsigned V_93 , V_94 = V_92 + V_35 ;
unsigned V_95 = V_92 + V_89 ;
V_93 = F_128 ( V_41 -> V_44 , V_95 , V_94 ) ;
if ( V_93 < V_95 )
return V_93 - V_94 ;
V_93 = F_128 ( V_41 -> V_44 , V_94 , V_92 ) ;
return V_93 < V_94 ? V_93 + V_89 - V_94 : - 1 ;
}
static unsigned long F_129 ( struct V_40 * V_41 )
{
unsigned long V_35 , V_52 , V_96 ;
unsigned V_33 , V_92 = 0 ;
V_52 = V_41 -> V_35 + V_97 ;
V_35 = V_41 -> V_35 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ , V_92 += V_89 ) {
int V_93 = F_127 ( V_41 , V_92 , V_35 & V_34 ) ;
if ( V_93 >= 0 ) {
unsigned long V_98 = V_35 + ( unsigned long ) V_93 ;
V_98 <<= F_25 ( V_33 ) ;
if ( F_130 ( V_98 , V_52 ) )
V_52 = V_98 ;
}
V_96 = V_35 & V_90 ? 1 : 0 ;
V_35 >>= V_91 ;
V_35 += V_96 ;
}
return V_52 ;
}
static T_5 F_131 ( T_5 V_99 , T_5 V_32 )
{
T_5 V_100 = F_132 () ;
if ( V_32 <= V_100 )
return V_32 ;
if ( V_100 <= V_99 )
return V_99 ;
return F_133 ( V_100 , V_101 ) * V_101 ;
}
T_5 F_134 ( unsigned long V_102 , T_5 V_99 )
{
struct V_40 * V_41 = F_81 ( & V_6 [ V_7 ] ) ;
T_5 V_32 = V_103 ;
unsigned long V_100 ;
bool V_104 ;
if ( F_135 ( F_136 () ) )
return V_32 ;
F_97 ( & V_41 -> V_71 ) ;
V_100 = F_129 ( V_41 ) ;
V_104 = ( V_100 == V_41 -> V_35 + V_97 ) ;
V_41 -> V_48 = V_100 ;
if ( F_88 ( V_102 , V_41 -> V_35 ) ) {
if ( F_88 ( V_100 , V_102 ) )
V_41 -> V_35 = V_102 ;
else if ( F_88 ( V_100 , V_41 -> V_35 ) )
V_41 -> V_35 = V_100 ;
}
if ( F_137 ( V_100 , V_102 ) ) {
V_32 = V_99 ;
V_41 -> V_47 = false ;
} else {
if ( ! V_104 )
V_32 = V_99 + ( V_100 - V_102 ) * V_101 ;
if ( ( V_32 - V_99 ) > V_101 )
V_41 -> V_47 = true ;
}
F_96 ( & V_41 -> V_71 ) ;
return F_131 ( V_99 , V_32 ) ;
}
void F_138 ( void )
{
struct V_40 * V_41 = F_81 ( & V_6 [ V_7 ] ) ;
V_41 -> V_47 = false ;
}
static int F_139 ( struct V_40 * V_41 ,
struct V_82 * V_85 )
{
if ( ( long ) ( V_25 - V_41 -> V_35 ) > 2 ) {
unsigned long V_52 = F_129 ( V_41 ) ;
if ( F_88 ( V_52 , V_25 ) ) {
V_41 -> V_35 = V_25 - 1 ;
return 0 ;
}
V_41 -> V_35 = V_52 ;
}
return F_124 ( V_41 , V_85 ) ;
}
static inline int F_139 ( struct V_40 * V_41 ,
struct V_82 * V_85 )
{
return F_124 ( V_41 , V_85 ) ;
}
void F_140 ( int V_105 )
{
struct V_106 * V_107 = V_108 ;
F_141 ( V_107 , V_105 ) ;
F_142 () ;
F_143 ( V_105 ) ;
#ifdef F_144
if ( F_110 () )
F_145 () ;
#endif
F_146 () ;
if ( F_34 ( V_109 ) )
F_147 ( V_107 ) ;
}
static inline void F_148 ( struct V_40 * V_41 )
{
struct V_82 V_85 [ V_37 ] ;
int V_88 ;
if ( ! F_37 ( V_25 , V_41 -> V_35 ) )
return;
F_123 ( & V_41 -> V_71 ) ;
while ( F_37 ( V_25 , V_41 -> V_35 ) ) {
V_88 = F_139 ( V_41 , V_85 ) ;
V_41 -> V_35 ++ ;
while ( V_88 -- )
F_119 ( V_41 , V_85 + V_88 ) ;
}
V_41 -> V_78 = NULL ;
F_122 ( & V_41 -> V_71 ) ;
}
static T_6 void F_149 ( struct V_110 * V_111 )
{
struct V_40 * V_41 = F_81 ( & V_6 [ V_7 ] ) ;
F_148 ( V_41 ) ;
if ( F_34 ( V_45 ) && V_41 -> V_11 )
F_148 ( F_81 ( & V_6 [ V_9 ] ) ) ;
}
void F_142 ( void )
{
struct V_40 * V_41 = F_81 ( & V_6 [ V_7 ] ) ;
F_150 () ;
if ( F_130 ( V_25 , V_41 -> V_35 ) ) {
if ( ! F_34 ( V_45 ) || ! V_41 -> V_11 )
return;
V_41 ++ ;
if ( F_130 ( V_25 , V_41 -> V_35 ) )
return;
}
F_151 ( V_112 ) ;
}
static void F_152 ( unsigned long V_113 )
{
F_153 ( (struct V_106 * ) V_113 ) ;
}
signed long T_7 F_154 ( signed long V_114 )
{
struct V_26 V_27 ;
unsigned long V_115 ;
switch ( V_114 )
{
case V_116 :
F_155 () ;
goto V_117;
default:
if ( V_114 < 0 ) {
F_156 ( V_118 L_2
L_3 , V_114 ) ;
F_157 () ;
V_108 -> V_55 = V_119 ;
goto V_117;
}
}
V_115 = V_114 + V_25 ;
F_158 ( & V_27 , F_152 , ( unsigned long ) V_108 ) ;
F_93 ( & V_27 , V_115 , false ) ;
F_155 () ;
F_159 ( & V_27 ) ;
F_62 ( & V_27 ) ;
V_114 = V_115 - V_25 ;
V_117:
return V_114 < 0 ? 0 : V_114 ;
}
signed long T_7 F_160 ( signed long V_114 )
{
F_161 ( V_120 ) ;
return F_154 ( V_114 ) ;
}
signed long T_7 F_162 ( signed long V_114 )
{
F_161 ( V_121 ) ;
return F_154 ( V_114 ) ;
}
signed long T_7 F_163 ( signed long V_114 )
{
F_161 ( V_122 ) ;
return F_154 ( V_114 ) ;
}
signed long T_7 F_164 ( signed long V_114 )
{
F_161 ( V_123 ) ;
return F_154 ( V_114 ) ;
}
static void F_165 ( struct V_40 * V_75 , struct V_82 * V_83 )
{
struct V_26 * V_27 ;
int V_5 = V_75 -> V_5 ;
while ( ! F_120 ( V_83 ) ) {
V_27 = F_121 ( V_83 -> V_84 , struct V_26 , V_42 ) ;
F_72 ( V_27 , false ) ;
V_27 -> V_28 = ( V_27 -> V_28 & ~ V_79 ) | V_5 ;
F_38 ( V_75 , V_27 ) ;
}
}
int F_166 ( unsigned int V_5 )
{
struct V_40 * V_124 ;
struct V_40 * V_75 ;
int V_125 , V_87 ;
F_94 ( F_167 ( V_5 ) ) ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
V_124 = F_79 ( & V_6 [ V_125 ] , V_5 ) ;
V_75 = F_168 ( & V_6 [ V_125 ] ) ;
F_123 ( & V_75 -> V_71 ) ;
F_169 ( & V_124 -> V_71 , V_127 ) ;
F_94 ( V_124 -> V_78 ) ;
for ( V_87 = 0 ; V_87 < V_128 ; V_87 ++ )
F_165 ( V_75 , V_124 -> V_43 + V_87 ) ;
F_96 ( & V_124 -> V_71 ) ;
F_122 ( & V_75 -> V_71 ) ;
F_170 ( & V_6 ) ;
}
return 0 ;
}
static void T_8 F_171 ( int V_5 )
{
struct V_40 * V_41 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_126 ; V_87 ++ ) {
V_41 = F_79 ( & V_6 [ V_87 ] , V_5 ) ;
V_41 -> V_5 = V_5 ;
F_172 ( & V_41 -> V_71 ) ;
V_41 -> V_35 = V_25 ;
}
}
static void T_8 F_173 ( void )
{
int V_5 ;
F_3 (cpu)
F_171 ( V_5 ) ;
}
void T_8 F_174 ( void )
{
F_173 () ;
F_175 ( V_112 , F_149 ) ;
}
void F_176 ( unsigned int V_129 )
{
unsigned long V_114 = F_177 ( V_129 ) + 1 ;
while ( V_114 )
V_114 = F_163 ( V_114 ) ;
}
unsigned long F_178 ( unsigned int V_129 )
{
unsigned long V_114 = F_177 ( V_129 ) + 1 ;
while ( V_114 && ! F_179 ( V_108 ) )
V_114 = F_160 ( V_114 ) ;
return F_180 ( V_114 ) ;
}
void T_7 F_181 ( unsigned long V_130 , unsigned long V_131 )
{
T_9 exp = F_182 ( F_183 () , V_130 ) ;
T_5 V_36 = ( T_5 ) ( V_131 - V_130 ) * V_132 ;
for (; ; ) {
F_161 ( V_122 ) ;
if ( ! F_184 ( & exp , V_36 , V_133 ) )
break;
}
}
