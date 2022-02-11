static inline int F_1 ( T_1 V_1 )
{
return V_2 [ V_1 ] ;
}
static
struct V_3 * F_2 ( const struct V_4 * V_5 ,
unsigned long * V_6 )
{
struct V_3 * V_7 ;
for (; ; ) {
V_7 = V_5 -> V_7 ;
if ( F_3 ( V_7 != & V_8 ) ) {
F_4 ( & V_7 -> V_9 -> V_10 , * V_6 ) ;
if ( F_3 ( V_7 == V_5 -> V_7 ) )
return V_7 ;
F_5 ( & V_7 -> V_9 -> V_10 , * V_6 ) ;
}
F_6 () ;
}
}
static int
F_7 ( struct V_4 * V_5 , struct V_3 * V_11 )
{
#ifdef F_8
T_2 V_12 ;
if ( ! V_11 -> V_9 -> V_13 )
return 0 ;
V_12 = F_9 ( F_10 ( V_5 ) , V_11 -> V_14 ) ;
return V_12 <= V_11 -> V_9 -> V_15 ;
#else
return 0 ;
#endif
}
static inline
struct V_16 * F_11 ( struct V_16 * V_7 ,
int V_17 )
{
if ( V_17 || ! V_7 -> V_18 )
return V_7 ;
return & F_12 ( V_19 , F_13 () ) ;
}
static inline
struct V_16 * F_11 ( struct V_16 * V_7 ,
int V_17 )
{
return V_7 ;
}
static inline struct V_3 *
F_14 ( struct V_4 * V_5 , struct V_3 * V_7 ,
int V_17 )
{
struct V_16 * V_20 , * V_21 ;
struct V_3 * V_11 ;
int V_22 = V_7 -> V_23 ;
V_21 = F_15 ( & V_19 ) ;
V_20 = F_11 ( V_21 , V_17 ) ;
V_24:
V_11 = & V_20 -> V_25 [ V_22 ] ;
if ( V_7 != V_11 ) {
if ( F_16 ( F_17 ( V_5 ) ) )
return V_7 ;
V_5 -> V_7 = & V_8 ;
F_18 ( & V_7 -> V_9 -> V_10 ) ;
F_19 ( & V_11 -> V_9 -> V_10 ) ;
if ( V_20 != V_21 &&
F_7 ( V_5 , V_11 ) ) {
F_18 ( & V_11 -> V_9 -> V_10 ) ;
F_19 ( & V_7 -> V_9 -> V_10 ) ;
V_20 = V_21 ;
V_5 -> V_7 = V_7 ;
goto V_24;
}
V_5 -> V_7 = V_11 ;
} else {
if ( V_20 != V_21 &&
F_7 ( V_5 , V_11 ) ) {
V_20 = V_21 ;
goto V_24;
}
}
return V_11 ;
}
static inline struct V_3 *
F_2 ( const struct V_4 * V_5 , unsigned long * V_6 )
{
struct V_3 * V_7 = V_5 -> V_7 ;
F_4 ( & V_7 -> V_9 -> V_10 , * V_6 ) ;
return V_7 ;
}
T_3 F_20 ( const T_2 V_26 , T_3 div )
{
int V_27 = 0 ;
T_3 V_28 ;
T_4 V_29 ;
V_28 = F_21 ( V_26 ) ;
V_29 = V_28 < 0 ? - V_28 : V_28 ;
while ( div >> 32 ) {
V_27 ++ ;
div >>= 1 ;
}
V_29 >>= V_27 ;
F_22 ( V_29 , ( unsigned long ) div ) ;
return V_28 < 0 ? - V_29 : V_29 ;
}
T_2 F_23 ( const T_2 V_30 , const T_2 V_31 )
{
T_2 V_32 = F_24 ( V_30 , V_31 ) ;
if ( V_32 < 0 || V_32 < V_30 || V_32 < V_31 )
V_32 = F_25 ( V_33 , 0 ) ;
return V_32 ;
}
static void * F_26 ( void * V_34 )
{
return ( (struct V_4 * ) V_34 ) -> V_35 ;
}
static bool F_27 ( void * V_34 , enum V_36 V_37 )
{
struct V_4 * V_5 = V_34 ;
switch ( V_37 ) {
case V_38 :
F_28 ( V_5 ) ;
F_29 ( V_5 , & V_39 ) ;
return true ;
default:
return false ;
}
}
static bool F_30 ( void * V_34 , enum V_36 V_37 )
{
switch ( V_37 ) {
case V_38 :
F_31 ( 1 ) ;
default:
return false ;
}
}
static bool F_32 ( void * V_34 , enum V_36 V_37 )
{
struct V_4 * V_5 = V_34 ;
switch ( V_37 ) {
case V_38 :
F_28 ( V_5 ) ;
F_33 ( V_5 , & V_39 ) ;
return true ;
default:
return false ;
}
}
static inline void F_34 ( struct V_4 * V_5 )
{
F_29 ( V_5 , & V_39 ) ;
}
static inline void F_35 ( struct V_4 * V_5 )
{
F_36 ( V_5 , & V_39 ) ;
}
static inline void F_37 ( struct V_4 * V_5 )
{
F_38 ( V_5 , & V_39 ) ;
}
static inline void F_39 ( struct V_4 * V_5 )
{
F_33 ( V_5 , & V_39 ) ;
}
void F_40 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_40 V_41 )
{
F_41 ( V_5 , & V_39 ) ;
F_42 ( V_5 , V_1 , V_41 ) ;
}
void F_43 ( struct V_4 * V_5 )
{
F_33 ( V_5 , & V_39 ) ;
}
static inline void F_34 ( struct V_4 * V_5 ) { }
static inline void F_35 ( struct V_4 * V_5 ) { }
static inline void F_37 ( struct V_4 * V_5 ) { }
static inline void
F_44 ( struct V_4 * V_5 , T_1 V_42 ,
enum V_40 V_41 )
{
F_34 ( V_5 ) ;
F_45 ( V_5 , V_42 , V_41 ) ;
}
static inline void F_46 ( struct V_4 * V_5 )
{
F_35 ( V_5 ) ;
F_47 ( V_5 ) ;
}
static inline void F_48 ( struct V_4 * V_5 )
{
F_37 ( V_5 ) ;
F_49 ( V_5 ) ;
}
static inline void F_50 ( struct V_16 * V_9 ,
struct V_4 * V_5 )
{
#ifdef F_8
V_9 -> V_43 = V_5 ;
#endif
}
static T_2 F_51 ( struct V_16 * V_9 )
{
struct V_3 * V_7 = V_9 -> V_25 ;
unsigned int V_44 = V_9 -> V_45 ;
T_2 V_12 , V_15 = V_46 ;
F_50 ( V_9 , NULL ) ;
for (; V_44 ; V_7 ++ , V_44 >>= 1 ) {
struct V_47 * V_48 ;
struct V_4 * V_5 ;
if ( ! ( V_44 & 0x01 ) )
continue;
V_48 = F_52 ( & V_7 -> V_44 ) ;
V_5 = F_53 ( V_48 , struct V_4 , V_49 ) ;
V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
if ( V_12 < V_15 ) {
V_15 = V_12 ;
F_50 ( V_9 , V_5 ) ;
}
}
if ( V_15 < 0 )
V_15 = 0 ;
return V_15 ;
}
static inline T_2 F_54 ( struct V_16 * V_7 )
{
T_2 * V_50 = & V_7 -> V_25 [ V_51 ] . V_14 ;
T_2 * V_52 = & V_7 -> V_25 [ V_53 ] . V_14 ;
T_2 * V_54 = & V_7 -> V_25 [ V_55 ] . V_14 ;
return F_55 ( & V_7 -> V_56 ,
V_50 , V_52 , V_54 ) ;
}
static int T_5 F_56 ( char * V_57 )
{
return ( F_57 ( V_57 , & V_58 ) == 0 ) ;
}
static inline int F_58 ( void )
{
return V_58 ;
}
static inline int F_59 ( struct V_16 * V_9 )
{
return V_9 -> V_13 ;
}
static inline int F_60 ( void )
{
return F_59 ( F_15 ( & V_19 ) ) ;
}
static void
F_61 ( struct V_16 * V_9 , int V_59 )
{
T_2 V_15 ;
if ( ! V_9 -> V_13 )
return;
V_15 = F_51 ( V_9 ) ;
if ( V_59 && V_15 == V_9 -> V_15 )
return;
V_9 -> V_15 = V_15 ;
if ( V_9 -> V_60 )
return;
F_62 ( V_9 -> V_15 , 1 ) ;
}
static void F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
struct V_16 * V_9 = F_15 ( & V_19 ) ;
T_2 V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
F_64 ( F_65 ( V_5 ) < 0 ) ;
if ( V_7 -> V_9 != V_9 )
return;
if ( V_9 -> V_61 )
return;
if ( V_12 < 0 )
V_12 = 0 ;
if ( V_12 >= V_9 -> V_15 )
return;
V_9 -> V_43 = V_5 ;
if ( V_9 -> V_60 )
return;
V_9 -> V_15 = V_12 ;
F_62 ( V_12 , 1 ) ;
}
static inline void F_66 ( struct V_16 * V_7 )
{
V_7 -> V_15 = V_46 ;
V_7 -> V_13 = 0 ;
}
static void F_67 ( void * V_62 )
{
struct V_16 * V_7 = F_15 ( & V_19 ) ;
if ( ! V_7 -> V_13 )
return;
F_19 ( & V_7 -> V_10 ) ;
F_54 ( V_7 ) ;
F_61 ( V_7 , 0 ) ;
F_18 ( & V_7 -> V_10 ) ;
}
static void F_68 ( void )
{
struct V_16 * V_7 = F_15 ( & V_19 ) ;
if ( F_69 () ) {
F_70 ( V_63 L_1
L_2 , V_7 -> V_64 ) ;
return;
}
V_7 -> V_13 = 1 ;
V_65 = V_66 ;
F_71 () ;
F_67 ( NULL ) ;
}
static void F_72 ( struct V_67 * V_68 )
{
F_73 () ;
}
void F_74 ( void )
{
F_75 ( & V_69 ) ;
}
static inline int F_59 ( struct V_16 * V_70 ) { return 0 ; }
static inline int F_60 ( void ) { return 0 ; }
static inline int F_58 ( void ) { return 0 ; }
static inline void F_68 ( void ) { }
static inline void
F_61 ( struct V_16 * V_7 , int V_59 ) { }
static inline int F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
return 0 ;
}
static inline void F_66 ( struct V_16 * V_7 ) { }
static inline void F_67 ( void * V_62 ) { }
void F_73 ( void )
{
#ifdef F_8
F_76 ( F_67 , NULL , 1 ) ;
#endif
F_77 () ;
}
void F_78 ( void )
{
F_79 ( ! F_80 () ,
V_71 L_3 ) ;
F_67 ( NULL ) ;
F_74 () ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
#ifdef F_82
if ( V_5 -> V_72 )
return;
V_5 -> V_72 = F_83 ( 0 ) ;
memcpy ( V_5 -> V_73 , V_74 -> V_75 , V_76 ) ;
V_5 -> V_77 = V_74 -> V_78 ;
#endif
}
static inline void F_84 ( struct V_4 * V_5 )
{
#ifdef F_82
V_5 -> V_72 = NULL ;
#endif
}
static inline void F_85 ( struct V_4 * V_5 )
{
#ifdef F_82
if ( F_3 ( ! V_79 ) )
return;
F_86 ( V_5 , V_5 -> V_77 , V_5 -> V_72 ,
V_5 -> V_35 , V_5 -> V_73 , 0 ) ;
#endif
}
static inline
void F_87 ( const struct V_4 * V_5 , unsigned long * V_6 )
{
F_5 ( & V_5 -> V_7 -> V_9 -> V_10 , * V_6 ) ;
}
T_4 F_88 ( struct V_4 * V_5 , T_2 V_80 , T_2 V_81 )
{
T_4 V_82 = 1 ;
T_2 V_83 ;
V_83 = F_9 ( V_80 , F_10 ( V_5 ) ) ;
if ( V_83 < 0 )
return 0 ;
if ( F_31 ( V_5 -> V_37 & V_84 ) )
return 0 ;
if ( V_81 < V_65 )
V_81 = V_65 ;
if ( F_16 ( V_83 >= V_81 ) ) {
T_3 V_85 = F_21 ( V_81 ) ;
V_82 = F_89 ( V_83 , V_85 ) ;
F_90 ( V_5 , V_85 * V_82 ) ;
if ( F_65 ( V_5 ) > V_80 )
return V_82 ;
V_82 ++ ;
}
F_91 ( V_5 , V_81 ) ;
return V_82 ;
}
static int F_92 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
F_46 ( V_5 ) ;
V_7 -> V_9 -> V_45 |= 1 << V_7 -> V_23 ;
V_5 -> V_37 = V_84 ;
return F_93 ( & V_7 -> V_44 , & V_5 -> V_49 ) ;
}
static void F_94 ( struct V_4 * V_5 ,
struct V_3 * V_7 ,
T_6 V_86 , int V_87 )
{
struct V_16 * V_9 = V_7 -> V_9 ;
T_6 V_37 = V_5 -> V_37 ;
V_5 -> V_37 = V_86 ;
if ( ! ( V_37 & V_84 ) )
return;
if ( ! F_95 ( & V_7 -> V_44 , & V_5 -> V_49 ) )
V_9 -> V_45 &= ~ ( 1 << V_7 -> V_23 ) ;
#ifdef F_8
if ( V_87 && V_5 == V_9 -> V_43 )
F_61 ( V_9 , 1 ) ;
#endif
}
static inline int
F_96 ( struct V_4 * V_5 , struct V_3 * V_7 , bool V_88 )
{
if ( F_97 ( V_5 ) ) {
T_6 V_37 = V_5 -> V_37 ;
int V_87 ;
F_48 ( V_5 ) ;
F_84 ( V_5 ) ;
V_87 = V_7 -> V_9 == F_15 ( & V_19 ) ;
if ( ! V_88 )
V_37 = V_89 ;
F_94 ( V_5 , V_7 , V_37 , V_87 ) ;
return 1 ;
}
return 0 ;
}
static inline T_2 F_98 ( struct V_4 * V_5 , T_2 V_90 ,
const enum V_40 V_41 )
{
#ifdef F_99
V_5 -> V_91 = V_41 & V_92 ;
if ( V_5 -> V_91 )
V_90 = F_23 ( V_90 , V_65 ) ;
#endif
return V_90 ;
}
void F_100 ( struct V_4 * V_5 , T_2 V_90 ,
T_4 V_93 , const enum V_40 V_41 )
{
struct V_3 * V_7 , * V_11 ;
unsigned long V_6 ;
int V_94 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
F_96 ( V_5 , V_7 , true ) ;
if ( V_41 & V_92 )
V_90 = F_23 ( V_90 , V_7 -> V_95 () ) ;
V_90 = F_98 ( V_5 , V_90 , V_41 ) ;
F_101 ( V_5 , V_90 , V_93 ) ;
V_11 = F_14 ( V_5 , V_7 , V_41 & V_96 ) ;
F_81 ( V_5 ) ;
V_94 = F_92 ( V_5 , V_11 ) ;
if ( ! V_94 )
goto V_97;
if ( ! F_102 ( V_5 ) ) {
if ( V_11 -> V_9 -> V_98 )
F_103 ( V_11 -> V_9 -> V_64 ) ;
} else {
F_63 ( V_5 , V_11 ) ;
}
V_97:
F_87 ( V_5 , & V_6 ) ;
}
int F_104 ( struct V_4 * V_5 )
{
struct V_3 * V_7 ;
unsigned long V_6 ;
int V_99 = - 1 ;
if ( ! F_105 ( V_5 ) )
return 0 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
if ( ! F_17 ( V_5 ) )
V_99 = F_96 ( V_5 , V_7 , false ) ;
F_87 ( V_5 , & V_6 ) ;
return V_99 ;
}
int F_28 ( struct V_4 * V_5 )
{
for (; ; ) {
int V_99 = F_104 ( V_5 ) ;
if ( V_99 >= 0 )
return V_99 ;
F_6 () ;
}
}
T_2 F_106 ( const struct V_4 * V_5 , bool V_100 )
{
unsigned long V_6 ;
T_2 V_101 ;
F_2 ( V_5 , & V_6 ) ;
if ( F_107 ( F_99 ) && V_100 )
V_101 = F_108 ( V_5 ) ;
else
V_101 = F_109 ( V_5 ) ;
F_87 ( V_5 , & V_6 ) ;
return V_101 ;
}
T_4 F_110 ( void )
{
struct V_16 * V_9 = F_15 ( & V_19 ) ;
T_4 V_12 = V_46 ;
unsigned long V_6 ;
F_4 ( & V_9 -> V_10 , V_6 ) ;
if ( ! F_59 ( V_9 ) )
V_12 = F_51 ( V_9 ) ;
F_5 ( & V_9 -> V_10 , V_6 ) ;
return V_12 ;
}
static void F_42 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_40 V_41 )
{
struct V_16 * V_9 ;
int V_7 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_9 = F_111 ( & V_19 ) ;
if ( V_1 == V_102 && V_41 != V_103 )
V_1 = V_104 ;
V_7 = F_1 ( V_1 ) ;
V_5 -> V_7 = & V_9 -> V_25 [ V_7 ] ;
F_112 ( & V_5 -> V_49 ) ;
#ifdef F_82
V_5 -> V_72 = NULL ;
V_5 -> V_77 = - 1 ;
memset ( V_5 -> V_73 , 0 , V_76 ) ;
#endif
}
void F_113 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_40 V_41 )
{
F_44 ( V_5 , V_1 , V_41 ) ;
F_42 ( V_5 , V_1 , V_41 ) ;
}
bool F_105 ( const struct V_4 * V_5 )
{
struct V_16 * V_9 ;
unsigned int V_105 ;
do {
V_9 = F_114 ( V_5 -> V_7 -> V_9 ) ;
V_105 = F_115 ( & V_9 -> V_105 ) ;
if ( V_5 -> V_37 != V_89 ||
V_9 -> V_106 == V_5 )
return true ;
} while ( F_116 ( & V_9 -> V_105 , V_105 ) ||
V_9 != F_114 ( V_5 -> V_7 -> V_9 ) );
return false ;
}
static void F_117 ( struct V_16 * V_9 ,
struct V_3 * V_7 ,
struct V_4 * V_5 , T_2 * V_80 )
{
enum V_107 ( * V_108 ) ( struct V_4 * ) ;
int V_88 ;
F_118 ( & V_9 -> V_10 ) ;
F_48 ( V_5 ) ;
V_9 -> V_106 = V_5 ;
F_119 ( & V_9 -> V_105 ) ;
F_94 ( V_5 , V_7 , V_89 , 0 ) ;
F_85 ( V_5 ) ;
V_108 = V_5 -> V_35 ;
if ( F_107 ( F_99 ) )
V_5 -> V_91 = false ;
F_18 ( & V_9 -> V_10 ) ;
F_120 ( V_5 , V_80 ) ;
V_88 = V_108 ( V_5 ) ;
F_121 ( V_5 ) ;
F_19 ( & V_9 -> V_10 ) ;
if ( V_88 != V_109 &&
! ( V_5 -> V_37 & V_84 ) )
F_92 ( V_5 , V_7 ) ;
F_119 ( & V_9 -> V_105 ) ;
F_64 ( V_9 -> V_106 != V_5 ) ;
V_9 -> V_106 = NULL ;
}
static void F_122 ( struct V_16 * V_9 , T_2 V_80 )
{
struct V_3 * V_7 = V_9 -> V_25 ;
unsigned int V_44 = V_9 -> V_45 ;
for (; V_44 ; V_7 ++ , V_44 >>= 1 ) {
struct V_47 * V_49 ;
T_2 V_110 ;
if ( ! ( V_44 & 0x01 ) )
continue;
V_110 = F_123 ( V_80 , V_7 -> V_14 ) ;
while ( ( V_49 = F_52 ( & V_7 -> V_44 ) ) ) {
struct V_4 * V_5 ;
V_5 = F_53 ( V_49 , struct V_4 , V_49 ) ;
if ( V_110 < F_124 ( V_5 ) )
break;
F_117 ( V_9 , V_7 , V_5 , & V_110 ) ;
}
}
}
void F_125 ( struct V_111 * V_112 )
{
struct V_16 * V_9 = F_15 ( & V_19 ) ;
T_2 V_15 , V_80 , V_113 , V_83 ;
int V_114 = 0 ;
F_126 ( ! V_9 -> V_13 ) ;
V_9 -> V_115 ++ ;
V_112 -> V_116 = V_46 ;
F_19 ( & V_9 -> V_10 ) ;
V_113 = V_80 = F_54 ( V_9 ) ;
V_117:
V_9 -> V_61 = 1 ;
V_9 -> V_15 = V_46 ;
F_122 ( V_9 , V_80 ) ;
V_15 = F_51 ( V_9 ) ;
V_9 -> V_15 = V_15 ;
V_9 -> V_61 = 0 ;
F_18 ( & V_9 -> V_10 ) ;
if ( ! F_62 ( V_15 , 0 ) ) {
V_9 -> V_60 = 0 ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_80 = F_54 ( V_9 ) ;
V_9 -> V_118 ++ ;
if ( ++ V_114 < 3 )
goto V_117;
V_9 -> V_119 ++ ;
V_9 -> V_60 = 1 ;
F_18 ( & V_9 -> V_10 ) ;
V_83 = F_9 ( V_80 , V_113 ) ;
if ( ( unsigned int ) V_83 > V_9 -> V_120 )
V_9 -> V_120 = ( unsigned int ) V_83 ;
if ( V_83 > 100 * V_121 )
V_15 = F_127 ( V_80 , 100 * V_121 ) ;
else
V_15 = F_123 ( V_80 , V_83 ) ;
F_62 ( V_15 , 1 ) ;
F_128 ( V_63 L_4 ,
F_21 ( V_83 ) ) ;
}
static inline void F_129 ( void )
{
struct V_122 * V_123 ;
if ( ! F_60 () )
return;
V_123 = F_15 ( & V_124 ) ;
if ( V_123 && V_123 -> V_125 )
F_125 ( V_123 -> V_125 ) ;
}
static inline void F_129 ( void ) { }
void F_130 ( void )
{
struct V_16 * V_9 = F_15 ( & V_19 ) ;
T_2 V_80 ;
if ( F_59 ( V_9 ) )
return;
if ( F_131 ( ! F_58 () ) ) {
F_68 () ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_80 = F_54 ( V_9 ) ;
F_122 ( V_9 , V_80 ) ;
F_18 ( & V_9 -> V_10 ) ;
}
static enum V_107 F_132 ( struct V_4 * V_5 )
{
struct V_126 * V_127 =
F_53 ( V_5 , struct V_126 , V_5 ) ;
struct V_128 * V_129 = V_127 -> V_129 ;
V_127 -> V_129 = NULL ;
if ( V_129 )
F_133 ( V_129 ) ;
return V_109 ;
}
void F_134 ( struct V_126 * V_130 , struct V_128 * V_129 )
{
V_130 -> V_5 . V_35 = F_132 ;
V_130 -> V_129 = V_129 ;
}
static int T_7 F_135 ( struct V_126 * V_127 , enum V_40 V_41 )
{
F_134 ( V_127 , V_74 ) ;
do {
F_136 ( V_131 ) ;
F_137 ( & V_127 -> V_5 , V_41 ) ;
if ( F_3 ( V_127 -> V_129 ) )
F_138 () ;
F_28 ( & V_127 -> V_5 ) ;
V_41 = V_103 ;
} while ( V_127 -> V_129 && ! F_139 ( V_74 ) );
F_140 ( V_132 ) ;
return V_127 -> V_129 == NULL ;
}
static int F_141 ( struct V_4 * V_5 , struct V_133 T_8 * V_134 )
{
struct V_133 V_135 ;
T_2 V_101 ;
V_101 = F_109 ( V_5 ) ;
if ( V_101 <= 0 )
return 0 ;
V_135 = F_142 ( V_101 ) ;
if ( F_143 ( V_134 , & V_135 , sizeof( * V_134 ) ) )
return - V_136 ;
return 1 ;
}
long T_7 F_144 ( struct V_137 * V_88 )
{
struct V_126 V_127 ;
struct V_133 T_8 * V_134 ;
int V_99 = 0 ;
F_40 ( & V_127 . V_5 , V_88 -> V_138 . V_42 ,
V_103 ) ;
F_145 ( & V_127 . V_5 , V_88 -> V_138 . V_12 ) ;
if ( F_135 ( & V_127 , V_103 ) )
goto V_139;
V_134 = V_88 -> V_138 . V_134 ;
if ( V_134 ) {
V_99 = F_141 ( & V_127 . V_5 , V_134 ) ;
if ( V_99 <= 0 )
goto V_139;
}
V_99 = - V_140 ;
V_139:
F_43 ( & V_127 . V_5 ) ;
return V_99 ;
}
long F_146 ( struct V_133 * V_141 , struct V_133 T_8 * V_134 ,
const enum V_40 V_41 , const T_1 V_42 )
{
struct V_137 * V_88 ;
struct V_126 V_127 ;
int V_99 = 0 ;
T_4 V_142 ;
V_142 = V_74 -> V_143 ;
if ( F_147 ( V_74 ) || F_148 ( V_74 ) )
V_142 = 0 ;
F_40 ( & V_127 . V_5 , V_42 , V_41 ) ;
F_101 ( & V_127 . V_5 , F_149 ( * V_141 ) , V_142 ) ;
if ( F_135 ( & V_127 , V_41 ) )
goto V_139;
if ( V_41 == V_103 ) {
V_99 = - V_144 ;
goto V_139;
}
if ( V_134 ) {
V_99 = F_141 ( & V_127 . V_5 , V_134 ) ;
if ( V_99 <= 0 )
goto V_139;
}
V_88 = & V_74 -> V_137 ;
V_88 -> V_108 = F_144 ;
V_88 -> V_138 . V_42 = V_127 . V_5 . V_7 -> V_42 ;
V_88 -> V_138 . V_134 = V_134 ;
V_88 -> V_138 . V_12 = F_65 ( & V_127 . V_5 ) ;
V_99 = - V_140 ;
V_139:
F_43 ( & V_127 . V_5 ) ;
return V_99 ;
}
int F_150 ( unsigned int V_64 )
{
struct V_16 * V_9 = & F_12 ( V_19 , V_64 ) ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
V_9 -> V_25 [ V_145 ] . V_9 = V_9 ;
F_151 ( & V_9 -> V_25 [ V_145 ] . V_44 ) ;
}
V_9 -> V_64 = V_64 ;
F_66 ( V_9 ) ;
return 0 ;
}
static void F_152 ( struct V_3 * V_147 ,
struct V_3 * V_11 )
{
struct V_4 * V_5 ;
struct V_47 * V_49 ;
while ( ( V_49 = F_52 ( & V_147 -> V_44 ) ) ) {
V_5 = F_53 ( V_49 , struct V_4 , V_49 ) ;
F_126 ( F_17 ( V_5 ) ) ;
F_48 ( V_5 ) ;
F_94 ( V_5 , V_147 , V_84 , 0 ) ;
V_5 -> V_7 = V_11 ;
F_92 ( V_5 , V_11 ) ;
}
}
int F_153 ( unsigned int V_148 )
{
struct V_16 * V_147 , * V_11 ;
int V_145 ;
F_126 ( F_154 ( V_148 ) ) ;
F_155 ( V_148 ) ;
F_156 () ;
V_147 = & F_12 ( V_19 , V_148 ) ;
V_11 = F_15 ( & V_19 ) ;
F_19 ( & V_11 -> V_10 ) ;
F_157 ( & V_147 -> V_10 , V_149 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
F_152 ( & V_147 -> V_25 [ V_145 ] ,
& V_11 -> V_25 [ V_145 ] ) ;
}
F_18 ( & V_147 -> V_10 ) ;
F_18 ( & V_11 -> V_10 ) ;
F_129 () ;
F_158 () ;
return 0 ;
}
void T_5 F_159 ( void )
{
F_150 ( F_160 () ) ;
}
int T_7
F_161 ( T_2 * V_12 , T_4 V_83 ,
const enum V_40 V_41 , int clock )
{
struct V_126 V_127 ;
if ( V_12 && * V_12 == 0 ) {
F_140 ( V_132 ) ;
return 0 ;
}
if ( ! V_12 ) {
F_162 () ;
return - V_150 ;
}
F_40 ( & V_127 . V_5 , clock , V_41 ) ;
F_101 ( & V_127 . V_5 , * V_12 , V_83 ) ;
F_134 ( & V_127 , V_74 ) ;
F_137 ( & V_127 . V_5 , V_41 ) ;
if ( F_3 ( V_127 . V_129 ) )
F_162 () ;
F_28 ( & V_127 . V_5 ) ;
F_43 ( & V_127 . V_5 ) ;
F_140 ( V_132 ) ;
return ! V_127 . V_129 ? 0 : - V_150 ;
}
int T_7 F_163 ( T_2 * V_12 , T_4 V_83 ,
const enum V_40 V_41 )
{
return F_161 ( V_12 , V_83 , V_41 ,
V_104 ) ;
}
int T_7 F_164 ( T_2 * V_12 ,
const enum V_40 V_41 )
{
return F_163 ( V_12 , 0 , V_41 ) ;
}
