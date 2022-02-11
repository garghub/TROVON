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
return V_12 . V_15 <= V_11 -> V_9 -> V_16 . V_15 ;
#else
return 0 ;
#endif
}
static inline
struct V_17 * F_11 ( struct V_17 * V_7 ,
int V_18 )
{
if ( V_18 || ! V_7 -> V_19 )
return V_7 ;
return & F_12 ( V_20 , F_13 () ) ;
}
static inline
struct V_17 * F_11 ( struct V_17 * V_7 ,
int V_18 )
{
return V_7 ;
}
static inline struct V_3 *
F_14 ( struct V_4 * V_5 , struct V_3 * V_7 ,
int V_18 )
{
struct V_17 * V_21 , * V_22 ;
struct V_3 * V_11 ;
int V_23 = V_7 -> V_24 ;
V_22 = F_15 ( & V_20 ) ;
V_21 = F_11 ( V_22 , V_18 ) ;
V_25:
V_11 = & V_21 -> V_26 [ V_23 ] ;
if ( V_7 != V_11 ) {
if ( F_16 ( F_17 ( V_5 ) ) )
return V_7 ;
V_5 -> V_7 = & V_8 ;
F_18 ( & V_7 -> V_9 -> V_10 ) ;
F_19 ( & V_11 -> V_9 -> V_10 ) ;
if ( V_21 != V_22 &&
F_7 ( V_5 , V_11 ) ) {
F_18 ( & V_11 -> V_9 -> V_10 ) ;
F_19 ( & V_7 -> V_9 -> V_10 ) ;
V_21 = V_22 ;
V_5 -> V_7 = V_7 ;
goto V_25;
}
V_5 -> V_7 = V_11 ;
} else {
if ( V_21 != V_22 &&
F_7 ( V_5 , V_11 ) ) {
V_21 = V_22 ;
goto V_25;
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
T_3 F_20 ( const T_2 V_27 , T_3 div )
{
int V_28 = 0 ;
T_3 V_29 ;
T_4 V_30 ;
V_29 = F_21 ( V_27 ) ;
V_30 = V_29 < 0 ? - V_29 : V_29 ;
while ( div >> 32 ) {
V_28 ++ ;
div >>= 1 ;
}
V_30 >>= V_28 ;
F_22 ( V_30 , ( unsigned long ) div ) ;
return V_29 < 0 ? - V_30 : V_30 ;
}
T_2 F_23 ( const T_2 V_31 , const T_2 V_32 )
{
T_2 V_33 = F_24 ( V_31 , V_32 ) ;
if ( V_33 . V_15 < 0 || V_33 . V_15 < V_31 . V_15 || V_33 . V_15 < V_32 . V_15 )
V_33 = F_25 ( V_34 , 0 ) ;
return V_33 ;
}
static void * F_26 ( void * V_35 )
{
return ( (struct V_4 * ) V_35 ) -> V_36 ;
}
static bool F_27 ( void * V_35 , enum V_37 V_38 )
{
struct V_4 * V_5 = V_35 ;
switch ( V_38 ) {
case V_39 :
F_28 ( V_5 ) ;
F_29 ( V_5 , & V_40 ) ;
return true ;
default:
return false ;
}
}
static bool F_30 ( void * V_35 , enum V_37 V_38 )
{
switch ( V_38 ) {
case V_39 :
F_31 ( 1 ) ;
default:
return false ;
}
}
static bool F_32 ( void * V_35 , enum V_37 V_38 )
{
struct V_4 * V_5 = V_35 ;
switch ( V_38 ) {
case V_39 :
F_28 ( V_5 ) ;
F_33 ( V_5 , & V_40 ) ;
return true ;
default:
return false ;
}
}
static inline void F_34 ( struct V_4 * V_5 )
{
F_29 ( V_5 , & V_40 ) ;
}
static inline void F_35 ( struct V_4 * V_5 )
{
F_36 ( V_5 , & V_40 ) ;
}
static inline void F_37 ( struct V_4 * V_5 )
{
F_38 ( V_5 , & V_40 ) ;
}
static inline void F_39 ( struct V_4 * V_5 )
{
F_33 ( V_5 , & V_40 ) ;
}
void F_40 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_41 V_42 )
{
F_41 ( V_5 , & V_40 ) ;
F_42 ( V_5 , V_1 , V_42 ) ;
}
void F_43 ( struct V_4 * V_5 )
{
F_33 ( V_5 , & V_40 ) ;
}
static inline void F_34 ( struct V_4 * V_5 ) { }
static inline void F_35 ( struct V_4 * V_5 ) { }
static inline void F_37 ( struct V_4 * V_5 ) { }
static inline void
F_44 ( struct V_4 * V_5 , T_1 V_43 ,
enum V_41 V_42 )
{
F_34 ( V_5 ) ;
F_45 ( V_5 , V_43 , V_42 ) ;
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
static inline void F_50 ( struct V_17 * V_9 ,
struct V_4 * V_5 )
{
#ifdef F_8
V_9 -> V_44 = V_5 ;
#endif
}
static T_2 F_51 ( struct V_17 * V_9 )
{
struct V_3 * V_7 = V_9 -> V_26 ;
T_2 V_12 , V_16 = { . V_15 = V_45 } ;
unsigned int V_46 = V_9 -> V_47 ;
F_50 ( V_9 , NULL ) ;
for (; V_46 ; V_7 ++ , V_46 >>= 1 ) {
struct V_48 * V_49 ;
struct V_4 * V_5 ;
if ( ! ( V_46 & 0x01 ) )
continue;
V_49 = F_52 ( & V_7 -> V_46 ) ;
V_5 = F_53 ( V_49 , struct V_4 , V_50 ) ;
V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
if ( V_12 . V_15 < V_16 . V_15 ) {
V_16 = V_12 ;
F_50 ( V_9 , V_5 ) ;
}
}
if ( V_16 . V_15 < 0 )
V_16 . V_15 = 0 ;
return V_16 ;
}
static inline T_2 F_54 ( struct V_17 * V_7 )
{
T_2 * V_51 = & V_7 -> V_26 [ V_52 ] . V_14 ;
T_2 * V_53 = & V_7 -> V_26 [ V_54 ] . V_14 ;
T_2 * V_55 = & V_7 -> V_26 [ V_56 ] . V_14 ;
return F_55 ( & V_7 -> V_57 ,
V_51 , V_53 , V_55 ) ;
}
static int T_5 F_56 ( char * V_58 )
{
return ( F_57 ( V_58 , & V_59 ) == 0 ) ;
}
static inline int F_58 ( void )
{
return V_59 ;
}
static inline int F_59 ( struct V_17 * V_9 )
{
return V_9 -> V_13 ;
}
static inline int F_60 ( void )
{
return F_59 ( F_15 ( & V_20 ) ) ;
}
static void
F_61 ( struct V_17 * V_9 , int V_60 )
{
T_2 V_16 ;
if ( ! V_9 -> V_13 )
return;
V_16 = F_51 ( V_9 ) ;
if ( V_60 && V_16 . V_15 == V_9 -> V_16 . V_15 )
return;
V_9 -> V_16 . V_15 = V_16 . V_15 ;
if ( V_9 -> V_61 )
return;
F_62 ( V_9 -> V_16 , 1 ) ;
}
static void F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
struct V_17 * V_9 = F_15 ( & V_20 ) ;
T_2 V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
F_64 ( F_65 ( V_5 ) < 0 ) ;
if ( V_7 -> V_9 != V_9 )
return;
if ( V_9 -> V_62 )
return;
if ( V_12 . V_15 < 0 )
V_12 . V_15 = 0 ;
if ( V_12 . V_15 >= V_9 -> V_16 . V_15 )
return;
V_9 -> V_44 = V_5 ;
if ( V_9 -> V_61 )
return;
V_9 -> V_16 = V_12 ;
F_62 ( V_12 , 1 ) ;
}
static inline void F_66 ( struct V_17 * V_7 )
{
V_7 -> V_16 . V_15 = V_45 ;
V_7 -> V_13 = 0 ;
}
static void F_67 ( void * V_63 )
{
struct V_17 * V_7 = F_15 ( & V_20 ) ;
if ( ! V_7 -> V_13 )
return;
F_19 ( & V_7 -> V_10 ) ;
F_54 ( V_7 ) ;
F_61 ( V_7 , 0 ) ;
F_18 ( & V_7 -> V_10 ) ;
}
static void F_68 ( void )
{
struct V_17 * V_7 = F_15 ( & V_20 ) ;
if ( F_69 () ) {
F_70 ( V_64 L_1
L_2 , V_7 -> V_65 ) ;
return;
}
V_7 -> V_13 = 1 ;
V_66 = V_67 ;
F_71 () ;
F_67 ( NULL ) ;
}
static void F_72 ( struct V_68 * V_69 )
{
F_73 () ;
}
void F_74 ( void )
{
F_75 ( & V_70 ) ;
}
static inline int F_59 ( struct V_17 * V_71 ) { return 0 ; }
static inline int F_60 ( void ) { return 0 ; }
static inline int F_58 ( void ) { return 0 ; }
static inline void F_68 ( void ) { }
static inline void
F_61 ( struct V_17 * V_7 , int V_60 ) { }
static inline int F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
return 0 ;
}
static inline void F_66 ( struct V_17 * V_7 ) { }
static inline void F_67 ( void * V_63 ) { }
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
V_72 L_3 ) ;
F_67 ( NULL ) ;
F_74 () ;
}
static inline void F_81 ( struct V_4 * V_5 )
{
#ifdef F_82
if ( V_5 -> V_73 )
return;
V_5 -> V_73 = F_83 ( 0 ) ;
memcpy ( V_5 -> V_74 , V_75 -> V_76 , V_77 ) ;
V_5 -> V_78 = V_75 -> V_79 ;
#endif
}
static inline void F_84 ( struct V_4 * V_5 )
{
#ifdef F_82
V_5 -> V_73 = NULL ;
#endif
}
static inline void F_85 ( struct V_4 * V_5 )
{
#ifdef F_82
if ( F_3 ( ! V_80 ) )
return;
F_86 ( V_5 , V_5 -> V_78 , V_5 -> V_73 ,
V_5 -> V_36 , V_5 -> V_74 , 0 ) ;
#endif
}
static inline
void F_87 ( const struct V_4 * V_5 , unsigned long * V_6 )
{
F_5 ( & V_5 -> V_7 -> V_9 -> V_10 , * V_6 ) ;
}
T_4 F_88 ( struct V_4 * V_5 , T_2 V_81 , T_2 V_82 )
{
T_4 V_83 = 1 ;
T_2 V_84 ;
V_84 = F_9 ( V_81 , F_10 ( V_5 ) ) ;
if ( V_84 . V_15 < 0 )
return 0 ;
if ( F_31 ( V_5 -> V_38 & V_85 ) )
return 0 ;
if ( V_82 . V_15 < V_66 )
V_82 . V_15 = V_66 ;
if ( F_16 ( V_84 . V_15 >= V_82 . V_15 ) ) {
T_3 V_86 = F_21 ( V_82 ) ;
V_83 = F_89 ( V_84 , V_86 ) ;
F_90 ( V_5 , V_86 * V_83 ) ;
if ( F_65 ( V_5 ) > V_81 . V_15 )
return V_83 ;
V_83 ++ ;
}
F_91 ( V_5 , V_82 ) ;
return V_83 ;
}
static int F_92 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
F_46 ( V_5 ) ;
V_7 -> V_9 -> V_47 |= 1 << V_7 -> V_24 ;
V_5 -> V_38 = V_85 ;
return F_93 ( & V_7 -> V_46 , & V_5 -> V_50 ) ;
}
static void F_94 ( struct V_4 * V_5 ,
struct V_3 * V_7 ,
T_6 V_87 , int V_88 )
{
struct V_17 * V_9 = V_7 -> V_9 ;
T_6 V_38 = V_5 -> V_38 ;
V_5 -> V_38 = V_87 ;
if ( ! ( V_38 & V_85 ) )
return;
if ( ! F_95 ( & V_7 -> V_46 , & V_5 -> V_50 ) )
V_9 -> V_47 &= ~ ( 1 << V_7 -> V_24 ) ;
#ifdef F_8
if ( V_88 && V_5 == V_9 -> V_44 )
F_61 ( V_9 , 1 ) ;
#endif
}
static inline int
F_96 ( struct V_4 * V_5 , struct V_3 * V_7 , bool V_89 )
{
if ( F_97 ( V_5 ) ) {
T_6 V_38 = V_5 -> V_38 ;
int V_88 ;
F_48 ( V_5 ) ;
F_84 ( V_5 ) ;
V_88 = V_7 -> V_9 == F_15 ( & V_20 ) ;
if ( ! V_89 )
V_38 = V_90 ;
F_94 ( V_5 , V_7 , V_38 , V_88 ) ;
return 1 ;
}
return 0 ;
}
static inline T_2 F_98 ( struct V_4 * V_5 , T_2 V_91 ,
const enum V_41 V_42 )
{
#ifdef F_99
V_5 -> V_92 = V_42 & V_93 ;
if ( V_5 -> V_92 )
V_91 = F_23 ( V_91 , F_25 ( 0 , V_66 ) ) ;
#endif
return V_91 ;
}
void F_100 ( struct V_4 * V_5 , T_2 V_91 ,
T_4 V_94 , const enum V_41 V_42 )
{
struct V_3 * V_7 , * V_11 ;
unsigned long V_6 ;
int V_95 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
F_96 ( V_5 , V_7 , true ) ;
if ( V_42 & V_93 )
V_91 = F_23 ( V_91 , V_7 -> V_96 () ) ;
V_91 = F_98 ( V_5 , V_91 , V_42 ) ;
F_101 ( V_5 , V_91 , V_94 ) ;
V_11 = F_14 ( V_5 , V_7 , V_42 & V_97 ) ;
F_81 ( V_5 ) ;
V_95 = F_92 ( V_5 , V_11 ) ;
if ( ! V_95 )
goto V_98;
if ( ! F_102 ( V_5 ) ) {
if ( V_11 -> V_9 -> V_99 )
F_103 ( V_11 -> V_9 -> V_65 ) ;
} else {
F_63 ( V_5 , V_11 ) ;
}
V_98:
F_87 ( V_5 , & V_6 ) ;
}
int F_104 ( struct V_4 * V_5 )
{
struct V_3 * V_7 ;
unsigned long V_6 ;
int V_100 = - 1 ;
if ( ! F_105 ( V_5 ) )
return 0 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
if ( ! F_17 ( V_5 ) )
V_100 = F_96 ( V_5 , V_7 , false ) ;
F_87 ( V_5 , & V_6 ) ;
return V_100 ;
}
int F_28 ( struct V_4 * V_5 )
{
for (; ; ) {
int V_100 = F_104 ( V_5 ) ;
if ( V_100 >= 0 )
return V_100 ;
F_6 () ;
}
}
T_2 F_106 ( const struct V_4 * V_5 , bool V_101 )
{
unsigned long V_6 ;
T_2 V_102 ;
F_2 ( V_5 , & V_6 ) ;
if ( F_107 ( F_99 ) && V_101 )
V_102 = F_108 ( V_5 ) ;
else
V_102 = F_109 ( V_5 ) ;
F_87 ( V_5 , & V_6 ) ;
return V_102 ;
}
T_4 F_110 ( void )
{
struct V_17 * V_9 = F_15 ( & V_20 ) ;
T_4 V_12 = V_45 ;
unsigned long V_6 ;
F_4 ( & V_9 -> V_10 , V_6 ) ;
if ( ! F_59 ( V_9 ) )
V_12 = F_51 ( V_9 ) . V_15 ;
F_5 ( & V_9 -> V_10 , V_6 ) ;
return V_12 ;
}
static void F_42 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_41 V_42 )
{
struct V_17 * V_9 ;
int V_7 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_9 = F_111 ( & V_20 ) ;
if ( V_1 == V_103 && V_42 != V_104 )
V_1 = V_105 ;
V_7 = F_1 ( V_1 ) ;
V_5 -> V_7 = & V_9 -> V_26 [ V_7 ] ;
F_112 ( & V_5 -> V_50 ) ;
#ifdef F_82
V_5 -> V_73 = NULL ;
V_5 -> V_78 = - 1 ;
memset ( V_5 -> V_74 , 0 , V_77 ) ;
#endif
}
void F_113 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_41 V_42 )
{
F_44 ( V_5 , V_1 , V_42 ) ;
F_42 ( V_5 , V_1 , V_42 ) ;
}
bool F_105 ( const struct V_4 * V_5 )
{
struct V_17 * V_9 ;
unsigned int V_106 ;
do {
V_9 = F_114 ( V_5 -> V_7 -> V_9 ) ;
V_106 = F_115 ( & V_9 -> V_106 ) ;
if ( V_5 -> V_38 != V_90 ||
V_9 -> V_107 == V_5 )
return true ;
} while ( F_116 ( & V_9 -> V_106 , V_106 ) ||
V_9 != F_114 ( V_5 -> V_7 -> V_9 ) );
return false ;
}
static void F_117 ( struct V_17 * V_9 ,
struct V_3 * V_7 ,
struct V_4 * V_5 , T_2 * V_81 )
{
enum V_108 ( * V_109 ) ( struct V_4 * ) ;
int V_89 ;
F_118 ( & V_9 -> V_10 ) ;
F_48 ( V_5 ) ;
V_9 -> V_107 = V_5 ;
F_119 ( & V_9 -> V_106 ) ;
F_94 ( V_5 , V_7 , V_90 , 0 ) ;
F_85 ( V_5 ) ;
V_109 = V_5 -> V_36 ;
if ( F_107 ( F_99 ) )
V_5 -> V_92 = false ;
F_18 ( & V_9 -> V_10 ) ;
F_120 ( V_5 , V_81 ) ;
V_89 = V_109 ( V_5 ) ;
F_121 ( V_5 ) ;
F_19 ( & V_9 -> V_10 ) ;
if ( V_89 != V_110 &&
! ( V_5 -> V_38 & V_85 ) )
F_92 ( V_5 , V_7 ) ;
F_119 ( & V_9 -> V_106 ) ;
F_64 ( V_9 -> V_107 != V_5 ) ;
V_9 -> V_107 = NULL ;
}
static void F_122 ( struct V_17 * V_9 , T_2 V_81 )
{
struct V_3 * V_7 = V_9 -> V_26 ;
unsigned int V_46 = V_9 -> V_47 ;
for (; V_46 ; V_7 ++ , V_46 >>= 1 ) {
struct V_48 * V_50 ;
T_2 V_111 ;
if ( ! ( V_46 & 0x01 ) )
continue;
V_111 = F_123 ( V_81 , V_7 -> V_14 ) ;
while ( ( V_50 = F_52 ( & V_7 -> V_46 ) ) ) {
struct V_4 * V_5 ;
V_5 = F_53 ( V_50 , struct V_4 , V_50 ) ;
if ( V_111 . V_15 < F_124 ( V_5 ) )
break;
F_117 ( V_9 , V_7 , V_5 , & V_111 ) ;
}
}
}
void F_125 ( struct V_112 * V_113 )
{
struct V_17 * V_9 = F_15 ( & V_20 ) ;
T_2 V_16 , V_81 , V_114 , V_84 ;
int V_115 = 0 ;
F_126 ( ! V_9 -> V_13 ) ;
V_9 -> V_116 ++ ;
V_113 -> V_117 . V_15 = V_45 ;
F_19 ( & V_9 -> V_10 ) ;
V_114 = V_81 = F_54 ( V_9 ) ;
V_118:
V_9 -> V_62 = 1 ;
V_9 -> V_16 . V_15 = V_45 ;
F_122 ( V_9 , V_81 ) ;
V_16 = F_51 ( V_9 ) ;
V_9 -> V_16 = V_16 ;
V_9 -> V_62 = 0 ;
F_18 ( & V_9 -> V_10 ) ;
if ( ! F_62 ( V_16 , 0 ) ) {
V_9 -> V_61 = 0 ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_81 = F_54 ( V_9 ) ;
V_9 -> V_119 ++ ;
if ( ++ V_115 < 3 )
goto V_118;
V_9 -> V_120 ++ ;
V_9 -> V_61 = 1 ;
F_18 ( & V_9 -> V_10 ) ;
V_84 = F_9 ( V_81 , V_114 ) ;
if ( ( unsigned int ) V_84 . V_15 > V_9 -> V_121 )
V_9 -> V_121 = ( unsigned int ) V_84 . V_15 ;
if ( V_84 . V_15 > 100 * V_122 )
V_16 = F_127 ( V_81 , 100 * V_122 ) ;
else
V_16 = F_123 ( V_81 , V_84 ) ;
F_62 ( V_16 , 1 ) ;
F_128 ( V_64 L_4 ,
F_21 ( V_84 ) ) ;
}
static inline void F_129 ( void )
{
struct V_123 * V_124 ;
if ( ! F_60 () )
return;
V_124 = F_15 ( & V_125 ) ;
if ( V_124 && V_124 -> V_126 )
F_125 ( V_124 -> V_126 ) ;
}
static inline void F_129 ( void ) { }
void F_130 ( void )
{
struct V_17 * V_9 = F_15 ( & V_20 ) ;
T_2 V_81 ;
if ( F_59 ( V_9 ) )
return;
if ( F_131 ( ! F_58 () ) ) {
F_68 () ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_81 = F_54 ( V_9 ) ;
F_122 ( V_9 , V_81 ) ;
F_18 ( & V_9 -> V_10 ) ;
}
static enum V_108 F_132 ( struct V_4 * V_5 )
{
struct V_127 * V_128 =
F_53 ( V_5 , struct V_127 , V_5 ) ;
struct V_129 * V_130 = V_128 -> V_130 ;
V_128 -> V_130 = NULL ;
if ( V_130 )
F_133 ( V_130 ) ;
return V_110 ;
}
void F_134 ( struct V_127 * V_131 , struct V_129 * V_130 )
{
V_131 -> V_5 . V_36 = F_132 ;
V_131 -> V_130 = V_130 ;
}
static int T_7 F_135 ( struct V_127 * V_128 , enum V_41 V_42 )
{
F_134 ( V_128 , V_75 ) ;
do {
F_136 ( V_132 ) ;
F_137 ( & V_128 -> V_5 , V_42 ) ;
if ( F_3 ( V_128 -> V_130 ) )
F_138 () ;
F_28 ( & V_128 -> V_5 ) ;
V_42 = V_104 ;
} while ( V_128 -> V_130 && ! F_139 ( V_75 ) );
F_140 ( V_133 ) ;
return V_128 -> V_130 == NULL ;
}
static int F_141 ( struct V_4 * V_5 , struct V_134 T_8 * V_135 )
{
struct V_134 V_136 ;
T_2 V_102 ;
V_102 = F_109 ( V_5 ) ;
if ( V_102 . V_15 <= 0 )
return 0 ;
V_136 = F_142 ( V_102 ) ;
if ( F_143 ( V_135 , & V_136 , sizeof( * V_135 ) ) )
return - V_137 ;
return 1 ;
}
long T_7 F_144 ( struct V_138 * V_89 )
{
struct V_127 V_128 ;
struct V_134 T_8 * V_135 ;
int V_100 = 0 ;
F_40 ( & V_128 . V_5 , V_89 -> V_139 . V_43 ,
V_104 ) ;
F_145 ( & V_128 . V_5 , V_89 -> V_139 . V_12 ) ;
if ( F_135 ( & V_128 , V_104 ) )
goto V_140;
V_135 = V_89 -> V_139 . V_135 ;
if ( V_135 ) {
V_100 = F_141 ( & V_128 . V_5 , V_135 ) ;
if ( V_100 <= 0 )
goto V_140;
}
V_100 = - V_141 ;
V_140:
F_43 ( & V_128 . V_5 ) ;
return V_100 ;
}
long F_146 ( struct V_134 * V_142 , struct V_134 T_8 * V_135 ,
const enum V_41 V_42 , const T_1 V_43 )
{
struct V_138 * V_89 ;
struct V_127 V_128 ;
int V_100 = 0 ;
T_4 V_143 ;
V_143 = V_75 -> V_144 ;
if ( F_147 ( V_75 ) || F_148 ( V_75 ) )
V_143 = 0 ;
F_40 ( & V_128 . V_5 , V_43 , V_42 ) ;
F_101 ( & V_128 . V_5 , F_149 ( * V_142 ) , V_143 ) ;
if ( F_135 ( & V_128 , V_42 ) )
goto V_140;
if ( V_42 == V_104 ) {
V_100 = - V_145 ;
goto V_140;
}
if ( V_135 ) {
V_100 = F_141 ( & V_128 . V_5 , V_135 ) ;
if ( V_100 <= 0 )
goto V_140;
}
V_89 = & V_75 -> V_138 ;
V_89 -> V_109 = F_144 ;
V_89 -> V_139 . V_43 = V_128 . V_5 . V_7 -> V_43 ;
V_89 -> V_139 . V_135 = V_135 ;
V_89 -> V_139 . V_12 = F_65 ( & V_128 . V_5 ) ;
V_100 = - V_141 ;
V_140:
F_43 ( & V_128 . V_5 ) ;
return V_100 ;
}
int F_150 ( unsigned int V_65 )
{
struct V_17 * V_9 = & F_12 ( V_20 , V_65 ) ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
V_9 -> V_26 [ V_146 ] . V_9 = V_9 ;
F_151 ( & V_9 -> V_26 [ V_146 ] . V_46 ) ;
}
V_9 -> V_65 = V_65 ;
F_66 ( V_9 ) ;
return 0 ;
}
static void F_152 ( struct V_3 * V_148 ,
struct V_3 * V_11 )
{
struct V_4 * V_5 ;
struct V_48 * V_50 ;
while ( ( V_50 = F_52 ( & V_148 -> V_46 ) ) ) {
V_5 = F_53 ( V_50 , struct V_4 , V_50 ) ;
F_126 ( F_17 ( V_5 ) ) ;
F_48 ( V_5 ) ;
F_94 ( V_5 , V_148 , V_85 , 0 ) ;
V_5 -> V_7 = V_11 ;
F_92 ( V_5 , V_11 ) ;
}
}
int F_153 ( unsigned int V_149 )
{
struct V_17 * V_148 , * V_11 ;
int V_146 ;
F_126 ( F_154 ( V_149 ) ) ;
F_155 ( V_149 ) ;
F_156 () ;
V_148 = & F_12 ( V_20 , V_149 ) ;
V_11 = F_15 ( & V_20 ) ;
F_19 ( & V_11 -> V_10 ) ;
F_157 ( & V_148 -> V_10 , V_150 ) ;
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
F_152 ( & V_148 -> V_26 [ V_146 ] ,
& V_11 -> V_26 [ V_146 ] ) ;
}
F_18 ( & V_148 -> V_10 ) ;
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
F_161 ( T_2 * V_12 , T_4 V_84 ,
const enum V_41 V_42 , int clock )
{
struct V_127 V_128 ;
if ( V_12 && ! V_12 -> V_15 ) {
F_140 ( V_133 ) ;
return 0 ;
}
if ( ! V_12 ) {
F_162 () ;
return - V_151 ;
}
F_40 ( & V_128 . V_5 , clock , V_42 ) ;
F_101 ( & V_128 . V_5 , * V_12 , V_84 ) ;
F_134 ( & V_128 , V_75 ) ;
F_137 ( & V_128 . V_5 , V_42 ) ;
if ( F_3 ( V_128 . V_130 ) )
F_162 () ;
F_28 ( & V_128 . V_5 ) ;
F_43 ( & V_128 . V_5 ) ;
F_140 ( V_133 ) ;
return ! V_128 . V_130 ? 0 : - V_151 ;
}
int T_7 F_163 ( T_2 * V_12 , T_4 V_84 ,
const enum V_41 V_42 )
{
return F_161 ( V_12 , V_84 , V_42 ,
V_105 ) ;
}
int T_7 F_164 ( T_2 * V_12 ,
const enum V_41 V_42 )
{
return F_163 ( V_12 , 0 , V_42 ) ;
}
