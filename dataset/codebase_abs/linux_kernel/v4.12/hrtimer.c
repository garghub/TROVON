static
struct V_1 * F_1 ( const struct V_2 * V_3 ,
unsigned long * V_4 )
{
struct V_1 * V_5 ;
for (; ; ) {
V_5 = V_3 -> V_5 ;
if ( F_2 ( V_5 != & V_6 ) ) {
F_3 ( & V_5 -> V_7 -> V_8 , * V_4 ) ;
if ( F_2 ( V_5 == V_3 -> V_5 ) )
return V_5 ;
F_4 ( & V_5 -> V_7 -> V_8 , * V_4 ) ;
}
F_5 () ;
}
}
static int
F_6 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
#ifdef F_7
T_1 V_10 ;
if ( ! V_9 -> V_7 -> V_11 )
return 0 ;
V_10 = F_8 ( F_9 ( V_3 ) , V_9 -> V_12 ) ;
return V_10 <= V_9 -> V_7 -> V_13 ;
#else
return 0 ;
#endif
}
static inline
struct V_14 * F_10 ( struct V_14 * V_5 ,
int V_15 )
{
if ( V_15 || ! V_5 -> V_16 )
return V_5 ;
return & F_11 ( V_17 , F_12 () ) ;
}
static inline
struct V_14 * F_10 ( struct V_14 * V_5 ,
int V_15 )
{
return V_5 ;
}
static inline struct V_1 *
F_13 ( struct V_2 * V_3 , struct V_1 * V_5 ,
int V_15 )
{
struct V_14 * V_18 , * V_19 ;
struct V_1 * V_9 ;
int V_20 = V_5 -> V_21 ;
V_19 = F_14 ( & V_17 ) ;
V_18 = F_10 ( V_19 , V_15 ) ;
V_22:
V_9 = & V_18 -> V_23 [ V_20 ] ;
if ( V_5 != V_9 ) {
if ( F_15 ( F_16 ( V_3 ) ) )
return V_5 ;
V_3 -> V_5 = & V_6 ;
F_17 ( & V_5 -> V_7 -> V_8 ) ;
F_18 ( & V_9 -> V_7 -> V_8 ) ;
if ( V_18 != V_19 &&
F_6 ( V_3 , V_9 ) ) {
F_17 ( & V_9 -> V_7 -> V_8 ) ;
F_18 ( & V_5 -> V_7 -> V_8 ) ;
V_18 = V_19 ;
V_3 -> V_5 = V_5 ;
goto V_22;
}
V_3 -> V_5 = V_9 ;
} else {
if ( V_18 != V_19 &&
F_6 ( V_3 , V_9 ) ) {
V_18 = V_19 ;
goto V_22;
}
}
return V_9 ;
}
static inline struct V_1 *
F_1 ( const struct V_2 * V_3 , unsigned long * V_4 )
{
struct V_1 * V_5 = V_3 -> V_5 ;
F_3 ( & V_5 -> V_7 -> V_8 , * V_4 ) ;
return V_5 ;
}
T_2 F_19 ( const T_1 V_24 , T_2 div )
{
int V_25 = 0 ;
T_2 V_26 ;
T_3 V_27 ;
V_26 = F_20 ( V_24 ) ;
V_27 = V_26 < 0 ? - V_26 : V_26 ;
while ( div >> 32 ) {
V_25 ++ ;
div >>= 1 ;
}
V_27 >>= V_25 ;
F_21 ( V_27 , ( unsigned long ) div ) ;
return V_26 < 0 ? - V_27 : V_27 ;
}
T_1 F_22 ( const T_1 V_28 , const T_1 V_29 )
{
T_1 V_30 = F_23 ( V_28 , V_29 ) ;
if ( V_30 < 0 || V_30 < V_28 || V_30 < V_29 )
V_30 = F_24 ( V_31 , 0 ) ;
return V_30 ;
}
static void * F_25 ( void * V_32 )
{
return ( (struct V_2 * ) V_32 ) -> V_33 ;
}
static bool F_26 ( void * V_32 , enum V_34 V_35 )
{
struct V_2 * V_3 = V_32 ;
switch ( V_35 ) {
case V_36 :
F_27 ( V_3 ) ;
F_28 ( V_3 , & V_37 ) ;
return true ;
default:
return false ;
}
}
static bool F_29 ( void * V_32 , enum V_34 V_35 )
{
switch ( V_35 ) {
case V_36 :
F_30 ( 1 ) ;
default:
return false ;
}
}
static bool F_31 ( void * V_32 , enum V_34 V_35 )
{
struct V_2 * V_3 = V_32 ;
switch ( V_35 ) {
case V_36 :
F_27 ( V_3 ) ;
F_32 ( V_3 , & V_37 ) ;
return true ;
default:
return false ;
}
}
static inline void F_33 ( struct V_2 * V_3 )
{
F_28 ( V_3 , & V_37 ) ;
}
static inline void F_34 ( struct V_2 * V_3 )
{
F_35 ( V_3 , & V_37 ) ;
}
static inline void F_36 ( struct V_2 * V_3 )
{
F_37 ( V_3 , & V_37 ) ;
}
static inline void F_38 ( struct V_2 * V_3 )
{
F_32 ( V_3 , & V_37 ) ;
}
void F_39 ( struct V_2 * V_3 , T_4 V_38 ,
enum V_39 V_40 )
{
F_40 ( V_3 , & V_37 ) ;
F_41 ( V_3 , V_38 , V_40 ) ;
}
void F_42 ( struct V_2 * V_3 )
{
F_32 ( V_3 , & V_37 ) ;
}
static inline void F_33 ( struct V_2 * V_3 ) { }
static inline void F_34 ( struct V_2 * V_3 ) { }
static inline void F_36 ( struct V_2 * V_3 ) { }
static inline void
F_43 ( struct V_2 * V_3 , T_4 V_41 ,
enum V_39 V_40 )
{
F_33 ( V_3 ) ;
F_44 ( V_3 , V_41 , V_40 ) ;
}
static inline void F_45 ( struct V_2 * V_3 )
{
F_34 ( V_3 ) ;
F_46 ( V_3 ) ;
}
static inline void F_47 ( struct V_2 * V_3 )
{
F_36 ( V_3 ) ;
F_48 ( V_3 ) ;
}
static inline void F_49 ( struct V_14 * V_7 ,
struct V_2 * V_3 )
{
#ifdef F_7
V_7 -> V_42 = V_3 ;
#endif
}
static T_1 F_50 ( struct V_14 * V_7 )
{
struct V_1 * V_5 = V_7 -> V_23 ;
unsigned int V_43 = V_7 -> V_44 ;
T_1 V_10 , V_13 = V_45 ;
F_49 ( V_7 , NULL ) ;
for (; V_43 ; V_5 ++ , V_43 >>= 1 ) {
struct V_46 * V_47 ;
struct V_2 * V_3 ;
if ( ! ( V_43 & 0x01 ) )
continue;
V_47 = F_51 ( & V_5 -> V_43 ) ;
V_3 = F_52 ( V_47 , struct V_2 , V_48 ) ;
V_10 = F_8 ( F_9 ( V_3 ) , V_5 -> V_12 ) ;
if ( V_10 < V_13 ) {
V_13 = V_10 ;
F_49 ( V_7 , V_3 ) ;
}
}
if ( V_13 < 0 )
V_13 = 0 ;
return V_13 ;
}
static inline T_1 F_53 ( struct V_14 * V_5 )
{
T_1 * V_49 = & V_5 -> V_23 [ V_50 ] . V_12 ;
T_1 * V_51 = & V_5 -> V_23 [ V_52 ] . V_12 ;
T_1 * V_53 = & V_5 -> V_23 [ V_54 ] . V_12 ;
return F_54 ( & V_5 -> V_55 ,
V_49 , V_51 , V_53 ) ;
}
static int T_5 F_55 ( char * V_56 )
{
return ( F_56 ( V_56 , & V_57 ) == 0 ) ;
}
static inline int F_57 ( void )
{
return V_57 ;
}
static inline int F_58 ( struct V_14 * V_7 )
{
return V_7 -> V_11 ;
}
static inline int F_59 ( void )
{
return F_58 ( F_14 ( & V_17 ) ) ;
}
static void
F_60 ( struct V_14 * V_7 , int V_58 )
{
T_1 V_13 ;
if ( ! V_7 -> V_11 )
return;
V_13 = F_50 ( V_7 ) ;
if ( V_58 && V_13 == V_7 -> V_13 )
return;
V_7 -> V_13 = V_13 ;
if ( V_7 -> V_59 )
return;
F_61 ( V_7 -> V_13 , 1 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_14 * V_7 = F_14 ( & V_17 ) ;
T_1 V_10 = F_8 ( F_9 ( V_3 ) , V_5 -> V_12 ) ;
F_63 ( F_64 ( V_3 ) < 0 ) ;
if ( V_5 -> V_7 != V_7 )
return;
if ( V_7 -> V_60 )
return;
if ( V_10 < 0 )
V_10 = 0 ;
if ( V_10 >= V_7 -> V_13 )
return;
V_7 -> V_42 = V_3 ;
if ( V_7 -> V_59 )
return;
V_7 -> V_13 = V_10 ;
F_61 ( V_10 , 1 ) ;
}
static inline void F_65 ( struct V_14 * V_5 )
{
V_5 -> V_13 = V_45 ;
V_5 -> V_11 = 0 ;
}
static void F_66 ( void * V_61 )
{
struct V_14 * V_5 = F_14 ( & V_17 ) ;
if ( ! V_5 -> V_11 )
return;
F_18 ( & V_5 -> V_8 ) ;
F_53 ( V_5 ) ;
F_60 ( V_5 , 0 ) ;
F_17 ( & V_5 -> V_8 ) ;
}
static void F_67 ( void )
{
struct V_14 * V_5 = F_14 ( & V_17 ) ;
if ( F_68 () ) {
F_69 ( V_62 L_1
L_2 , V_5 -> V_63 ) ;
return;
}
V_5 -> V_11 = 1 ;
V_64 = V_65 ;
F_70 () ;
F_66 ( NULL ) ;
}
static void F_71 ( struct V_66 * V_67 )
{
F_72 () ;
}
void F_73 ( void )
{
F_74 ( & V_68 ) ;
}
static inline int F_58 ( struct V_14 * V_69 ) { return 0 ; }
static inline int F_59 ( void ) { return 0 ; }
static inline int F_57 ( void ) { return 0 ; }
static inline void F_67 ( void ) { }
static inline void
F_60 ( struct V_14 * V_5 , int V_58 ) { }
static inline int F_62 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
return 0 ;
}
static inline void F_65 ( struct V_14 * V_5 ) { }
static inline void F_66 ( void * V_61 ) { }
void F_72 ( void )
{
#ifdef F_7
F_75 ( F_66 , NULL , 1 ) ;
#endif
F_76 () ;
}
void F_77 ( void )
{
F_78 ( ! F_79 () ,
V_70 L_3 ) ;
F_66 ( NULL ) ;
F_73 () ;
}
static inline
void F_80 ( const struct V_2 * V_3 , unsigned long * V_4 )
{
F_4 ( & V_3 -> V_5 -> V_7 -> V_8 , * V_4 ) ;
}
T_3 F_81 ( struct V_2 * V_3 , T_1 V_71 , T_1 V_72 )
{
T_3 V_73 = 1 ;
T_1 V_74 ;
V_74 = F_8 ( V_71 , F_9 ( V_3 ) ) ;
if ( V_74 < 0 )
return 0 ;
if ( F_30 ( V_3 -> V_35 & V_75 ) )
return 0 ;
if ( V_72 < V_64 )
V_72 = V_64 ;
if ( F_15 ( V_74 >= V_72 ) ) {
T_2 V_76 = F_20 ( V_72 ) ;
V_73 = F_82 ( V_74 , V_76 ) ;
F_83 ( V_3 , V_76 * V_73 ) ;
if ( F_64 ( V_3 ) > V_71 )
return V_73 ;
V_73 ++ ;
}
F_84 ( V_3 , V_72 ) ;
return V_73 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
F_45 ( V_3 ) ;
V_5 -> V_7 -> V_44 |= 1 << V_5 -> V_21 ;
V_3 -> V_35 = V_75 ;
return F_86 ( & V_5 -> V_43 , & V_3 -> V_48 ) ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
T_6 V_77 , int V_78 )
{
struct V_14 * V_7 = V_5 -> V_7 ;
T_6 V_35 = V_3 -> V_35 ;
V_3 -> V_35 = V_77 ;
if ( ! ( V_35 & V_75 ) )
return;
if ( ! F_88 ( & V_5 -> V_43 , & V_3 -> V_48 ) )
V_7 -> V_44 &= ~ ( 1 << V_5 -> V_21 ) ;
#ifdef F_7
if ( V_78 && V_3 == V_7 -> V_42 )
F_60 ( V_7 , 1 ) ;
#endif
}
static inline int
F_89 ( struct V_2 * V_3 , struct V_1 * V_5 , bool V_79 )
{
if ( F_90 ( V_3 ) ) {
T_6 V_35 = V_3 -> V_35 ;
int V_78 ;
F_47 ( V_3 ) ;
V_78 = V_5 -> V_7 == F_14 ( & V_17 ) ;
if ( ! V_79 )
V_35 = V_80 ;
F_87 ( V_3 , V_5 , V_35 , V_78 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_91 ( struct V_2 * V_3 , T_1 V_81 ,
const enum V_39 V_40 )
{
#ifdef F_92
V_3 -> V_82 = V_40 & V_83 ;
if ( V_3 -> V_82 )
V_81 = F_22 ( V_81 , V_64 ) ;
#endif
return V_81 ;
}
void F_93 ( struct V_2 * V_3 , T_1 V_81 ,
T_3 V_84 , const enum V_39 V_40 )
{
struct V_1 * V_5 , * V_9 ;
unsigned long V_4 ;
int V_85 ;
V_5 = F_1 ( V_3 , & V_4 ) ;
F_89 ( V_3 , V_5 , true ) ;
if ( V_40 & V_83 )
V_81 = F_22 ( V_81 , V_5 -> V_86 () ) ;
V_81 = F_91 ( V_3 , V_81 , V_40 ) ;
F_94 ( V_3 , V_81 , V_84 ) ;
V_9 = F_13 ( V_3 , V_5 , V_40 & V_87 ) ;
V_85 = F_85 ( V_3 , V_9 ) ;
if ( ! V_85 )
goto V_88;
if ( ! F_95 ( V_3 ) ) {
if ( V_9 -> V_7 -> V_89 )
F_96 ( V_9 -> V_7 -> V_63 ) ;
} else {
F_62 ( V_3 , V_9 ) ;
}
V_88:
F_80 ( V_3 , & V_4 ) ;
}
int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
unsigned long V_4 ;
int V_90 = - 1 ;
if ( ! F_98 ( V_3 ) )
return 0 ;
V_5 = F_1 ( V_3 , & V_4 ) ;
if ( ! F_16 ( V_3 ) )
V_90 = F_89 ( V_3 , V_5 , false ) ;
F_80 ( V_3 , & V_4 ) ;
return V_90 ;
}
int F_27 ( struct V_2 * V_3 )
{
for (; ; ) {
int V_90 = F_97 ( V_3 ) ;
if ( V_90 >= 0 )
return V_90 ;
F_5 () ;
}
}
T_1 F_99 ( const struct V_2 * V_3 , bool V_91 )
{
unsigned long V_4 ;
T_1 V_92 ;
F_1 ( V_3 , & V_4 ) ;
if ( F_100 ( F_92 ) && V_91 )
V_92 = F_101 ( V_3 ) ;
else
V_92 = F_102 ( V_3 ) ;
F_80 ( V_3 , & V_4 ) ;
return V_92 ;
}
T_3 F_103 ( void )
{
struct V_14 * V_7 = F_14 ( & V_17 ) ;
T_3 V_10 = V_45 ;
unsigned long V_4 ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
if ( ! F_58 ( V_7 ) )
V_10 = F_50 ( V_7 ) ;
F_4 ( & V_7 -> V_8 , V_4 ) ;
return V_10 ;
}
static inline int F_104 ( T_4 V_38 )
{
if ( F_2 ( V_38 < V_93 ) ) {
int V_5 = V_94 [ V_38 ] ;
if ( F_2 ( V_5 != V_95 ) )
return V_5 ;
}
F_105 ( 1 , L_4 , V_38 ) ;
return V_96 ;
}
static void F_41 ( struct V_2 * V_3 , T_4 V_38 ,
enum V_39 V_40 )
{
struct V_14 * V_7 ;
int V_5 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_7 = F_106 ( & V_17 ) ;
if ( V_38 == V_97 && V_40 != V_98 )
V_38 = V_99 ;
V_5 = F_104 ( V_38 ) ;
V_3 -> V_5 = & V_7 -> V_23 [ V_5 ] ;
F_107 ( & V_3 -> V_48 ) ;
}
void F_108 ( struct V_2 * V_3 , T_4 V_38 ,
enum V_39 V_40 )
{
F_43 ( V_3 , V_38 , V_40 ) ;
F_41 ( V_3 , V_38 , V_40 ) ;
}
bool F_98 ( const struct V_2 * V_3 )
{
struct V_14 * V_7 ;
unsigned int V_100 ;
do {
V_7 = F_109 ( V_3 -> V_5 -> V_7 ) ;
V_100 = F_110 ( & V_7 -> V_100 ) ;
if ( V_3 -> V_35 != V_80 ||
V_7 -> V_101 == V_3 )
return true ;
} while ( F_111 ( & V_7 -> V_100 , V_100 ) ||
V_7 != F_109 ( V_3 -> V_5 -> V_7 ) );
return false ;
}
static void F_112 ( struct V_14 * V_7 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_1 * V_71 )
{
enum V_102 ( * V_103 ) ( struct V_2 * ) ;
int V_79 ;
F_113 ( & V_7 -> V_8 ) ;
F_47 ( V_3 ) ;
V_7 -> V_101 = V_3 ;
F_114 ( & V_7 -> V_100 ) ;
F_87 ( V_3 , V_5 , V_80 , 0 ) ;
V_103 = V_3 -> V_33 ;
if ( F_100 ( F_92 ) )
V_3 -> V_82 = false ;
F_17 ( & V_7 -> V_8 ) ;
F_115 ( V_3 , V_71 ) ;
V_79 = V_103 ( V_3 ) ;
F_116 ( V_3 ) ;
F_18 ( & V_7 -> V_8 ) ;
if ( V_79 != V_104 &&
! ( V_3 -> V_35 & V_75 ) )
F_85 ( V_3 , V_5 ) ;
F_114 ( & V_7 -> V_100 ) ;
F_63 ( V_7 -> V_101 != V_3 ) ;
V_7 -> V_101 = NULL ;
}
static void F_117 ( struct V_14 * V_7 , T_1 V_71 )
{
struct V_1 * V_5 = V_7 -> V_23 ;
unsigned int V_43 = V_7 -> V_44 ;
for (; V_43 ; V_5 ++ , V_43 >>= 1 ) {
struct V_46 * V_48 ;
T_1 V_105 ;
if ( ! ( V_43 & 0x01 ) )
continue;
V_105 = F_118 ( V_71 , V_5 -> V_12 ) ;
while ( ( V_48 = F_51 ( & V_5 -> V_43 ) ) ) {
struct V_2 * V_3 ;
V_3 = F_52 ( V_48 , struct V_2 , V_48 ) ;
if ( V_105 < F_119 ( V_3 ) )
break;
F_112 ( V_7 , V_5 , V_3 , & V_105 ) ;
}
}
}
void F_120 ( struct V_106 * V_107 )
{
struct V_14 * V_7 = F_14 ( & V_17 ) ;
T_1 V_13 , V_71 , V_108 , V_74 ;
int V_109 = 0 ;
F_121 ( ! V_7 -> V_11 ) ;
V_7 -> V_110 ++ ;
V_107 -> V_111 = V_45 ;
F_18 ( & V_7 -> V_8 ) ;
V_108 = V_71 = F_53 ( V_7 ) ;
V_112:
V_7 -> V_60 = 1 ;
V_7 -> V_13 = V_45 ;
F_117 ( V_7 , V_71 ) ;
V_13 = F_50 ( V_7 ) ;
V_7 -> V_13 = V_13 ;
V_7 -> V_60 = 0 ;
F_17 ( & V_7 -> V_8 ) ;
if ( ! F_61 ( V_13 , 0 ) ) {
V_7 -> V_59 = 0 ;
return;
}
F_18 ( & V_7 -> V_8 ) ;
V_71 = F_53 ( V_7 ) ;
V_7 -> V_113 ++ ;
if ( ++ V_109 < 3 )
goto V_112;
V_7 -> V_114 ++ ;
V_7 -> V_59 = 1 ;
F_17 ( & V_7 -> V_8 ) ;
V_74 = F_8 ( V_71 , V_108 ) ;
if ( ( unsigned int ) V_74 > V_7 -> V_115 )
V_7 -> V_115 = ( unsigned int ) V_74 ;
if ( V_74 > 100 * V_116 )
V_13 = F_122 ( V_71 , 100 * V_116 ) ;
else
V_13 = F_118 ( V_71 , V_74 ) ;
F_61 ( V_13 , 1 ) ;
F_123 ( V_62 L_5 ,
F_20 ( V_74 ) ) ;
}
static inline void F_124 ( void )
{
struct V_117 * V_118 ;
if ( ! F_59 () )
return;
V_118 = F_14 ( & V_119 ) ;
if ( V_118 && V_118 -> V_120 )
F_120 ( V_118 -> V_120 ) ;
}
static inline void F_124 ( void ) { }
void F_125 ( void )
{
struct V_14 * V_7 = F_14 ( & V_17 ) ;
T_1 V_71 ;
if ( F_58 ( V_7 ) )
return;
if ( F_126 ( ! F_57 () ) ) {
F_67 () ;
return;
}
F_18 ( & V_7 -> V_8 ) ;
V_71 = F_53 ( V_7 ) ;
F_117 ( V_7 , V_71 ) ;
F_17 ( & V_7 -> V_8 ) ;
}
static enum V_102 F_127 ( struct V_2 * V_3 )
{
struct V_121 * V_122 =
F_52 ( V_3 , struct V_121 , V_3 ) ;
struct V_123 * V_124 = V_122 -> V_124 ;
V_122 -> V_124 = NULL ;
if ( V_124 )
F_128 ( V_124 ) ;
return V_104 ;
}
void F_129 ( struct V_121 * V_125 , struct V_123 * V_124 )
{
V_125 -> V_3 . V_33 = F_127 ;
V_125 -> V_124 = V_124 ;
}
static int T_7 F_130 ( struct V_121 * V_122 , enum V_39 V_40 )
{
F_129 ( V_122 , V_126 ) ;
do {
F_131 ( V_127 ) ;
F_132 ( & V_122 -> V_3 , V_40 ) ;
if ( F_2 ( V_122 -> V_124 ) )
F_133 () ;
F_27 ( & V_122 -> V_3 ) ;
V_40 = V_98 ;
} while ( V_122 -> V_124 && ! F_134 ( V_126 ) );
F_135 ( V_128 ) ;
return V_122 -> V_124 == NULL ;
}
static int F_136 ( struct V_2 * V_3 , struct V_129 T_8 * V_130 )
{
struct V_129 V_131 ;
T_1 V_92 ;
V_92 = F_102 ( V_3 ) ;
if ( V_92 <= 0 )
return 0 ;
V_131 = F_137 ( V_92 ) ;
if ( F_138 ( V_130 , & V_131 , sizeof( * V_130 ) ) )
return - V_132 ;
return 1 ;
}
long T_7 F_139 ( struct V_133 * V_79 )
{
struct V_121 V_122 ;
struct V_129 T_8 * V_130 ;
int V_90 = 0 ;
F_39 ( & V_122 . V_3 , V_79 -> V_134 . V_41 ,
V_98 ) ;
F_140 ( & V_122 . V_3 , V_79 -> V_134 . V_10 ) ;
if ( F_130 ( & V_122 , V_98 ) )
goto V_135;
V_130 = V_79 -> V_134 . V_130 ;
if ( V_130 ) {
V_90 = F_136 ( & V_122 . V_3 , V_130 ) ;
if ( V_90 <= 0 )
goto V_135;
}
V_90 = - V_136 ;
V_135:
F_42 ( & V_122 . V_3 ) ;
return V_90 ;
}
long F_141 ( struct V_137 * V_138 , struct V_129 T_8 * V_130 ,
const enum V_39 V_40 , const T_4 V_41 )
{
struct V_133 * V_79 ;
struct V_121 V_122 ;
int V_90 = 0 ;
T_3 V_139 ;
V_139 = V_126 -> V_140 ;
if ( F_142 ( V_126 ) || F_143 ( V_126 ) )
V_139 = 0 ;
F_39 ( & V_122 . V_3 , V_41 , V_40 ) ;
F_94 ( & V_122 . V_3 , F_144 ( * V_138 ) , V_139 ) ;
if ( F_130 ( & V_122 , V_40 ) )
goto V_135;
if ( V_40 == V_98 ) {
V_90 = - V_141 ;
goto V_135;
}
if ( V_130 ) {
V_90 = F_136 ( & V_122 . V_3 , V_130 ) ;
if ( V_90 <= 0 )
goto V_135;
}
V_79 = & V_126 -> V_133 ;
V_79 -> V_103 = F_139 ;
V_79 -> V_134 . V_41 = V_122 . V_3 . V_5 -> V_41 ;
V_79 -> V_134 . V_130 = V_130 ;
V_79 -> V_134 . V_10 = F_64 ( & V_122 . V_3 ) ;
V_90 = - V_136 ;
V_135:
F_42 ( & V_122 . V_3 ) ;
return V_90 ;
}
int F_145 ( unsigned int V_63 )
{
struct V_14 * V_7 = & F_11 ( V_17 , V_63 ) ;
int V_142 ;
for ( V_142 = 0 ; V_142 < V_95 ; V_142 ++ ) {
V_7 -> V_23 [ V_142 ] . V_7 = V_7 ;
F_146 ( & V_7 -> V_23 [ V_142 ] . V_43 ) ;
}
V_7 -> V_63 = V_63 ;
F_65 ( V_7 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_143 ,
struct V_1 * V_9 )
{
struct V_2 * V_3 ;
struct V_46 * V_48 ;
while ( ( V_48 = F_51 ( & V_143 -> V_43 ) ) ) {
V_3 = F_52 ( V_48 , struct V_2 , V_48 ) ;
F_121 ( F_16 ( V_3 ) ) ;
F_47 ( V_3 ) ;
F_87 ( V_3 , V_143 , V_75 , 0 ) ;
V_3 -> V_5 = V_9 ;
F_85 ( V_3 , V_9 ) ;
}
}
int F_148 ( unsigned int V_144 )
{
struct V_14 * V_143 , * V_9 ;
int V_142 ;
F_121 ( F_149 ( V_144 ) ) ;
F_150 ( V_144 ) ;
F_151 () ;
V_143 = & F_11 ( V_17 , V_144 ) ;
V_9 = F_14 ( & V_17 ) ;
F_18 ( & V_9 -> V_8 ) ;
F_152 ( & V_143 -> V_8 , V_145 ) ;
for ( V_142 = 0 ; V_142 < V_95 ; V_142 ++ ) {
F_147 ( & V_143 -> V_23 [ V_142 ] ,
& V_9 -> V_23 [ V_142 ] ) ;
}
F_17 ( & V_143 -> V_8 ) ;
F_17 ( & V_9 -> V_8 ) ;
F_124 () ;
F_153 () ;
return 0 ;
}
void T_5 F_154 ( void )
{
F_145 ( F_155 () ) ;
}
int T_7
F_156 ( T_1 * V_10 , T_3 V_74 ,
const enum V_39 V_40 , int clock )
{
struct V_121 V_122 ;
if ( V_10 && * V_10 == 0 ) {
F_135 ( V_128 ) ;
return 0 ;
}
if ( ! V_10 ) {
F_157 () ;
return - V_146 ;
}
F_39 ( & V_122 . V_3 , clock , V_40 ) ;
F_94 ( & V_122 . V_3 , * V_10 , V_74 ) ;
F_129 ( & V_122 , V_126 ) ;
F_132 ( & V_122 . V_3 , V_40 ) ;
if ( F_2 ( V_122 . V_124 ) )
F_157 () ;
F_27 ( & V_122 . V_3 ) ;
F_42 ( & V_122 . V_3 ) ;
F_135 ( V_128 ) ;
return ! V_122 . V_124 ? 0 : - V_146 ;
}
int T_7 F_158 ( T_1 * V_10 , T_3 V_74 ,
const enum V_39 V_40 )
{
return F_156 ( V_10 , V_74 , V_40 ,
V_99 ) ;
}
int T_7 F_159 ( T_1 * V_10 ,
const enum V_39 V_40 )
{
return F_158 ( V_10 , 0 , V_40 ) ;
}
