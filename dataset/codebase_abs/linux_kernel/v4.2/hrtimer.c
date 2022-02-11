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
return F_12 ( & V_20 ) ;
return & F_13 ( V_20 , F_14 () ) ;
}
static inline
struct V_17 * F_11 ( struct V_17 * V_7 ,
int V_18 )
{
return F_12 ( & V_20 ) ;
}
static inline struct V_3 *
F_15 ( struct V_4 * V_5 , struct V_3 * V_7 ,
int V_18 )
{
struct V_17 * V_21 , * V_22 ;
struct V_3 * V_11 ;
int V_23 = V_7 -> V_24 ;
V_22 = F_12 ( & V_20 ) ;
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
static int F_27 ( void * V_35 , enum V_37 V_38 )
{
struct V_4 * V_5 = V_35 ;
switch ( V_38 ) {
case V_39 :
F_28 ( V_5 ) ;
F_29 ( V_5 , & V_40 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( void * V_35 , enum V_37 V_38 )
{
switch ( V_38 ) {
case V_41 :
F_31 ( 1 ) ;
return 0 ;
case V_39 :
F_32 ( 1 ) ;
default:
return 0 ;
}
}
static int F_33 ( void * V_35 , enum V_37 V_38 )
{
struct V_4 * V_5 = V_35 ;
switch ( V_38 ) {
case V_39 :
F_28 ( V_5 ) ;
F_34 ( V_5 , & V_40 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_35 ( struct V_4 * V_5 )
{
F_29 ( V_5 , & V_40 ) ;
}
static inline void F_36 ( struct V_4 * V_5 )
{
F_37 ( V_5 , & V_40 ) ;
}
static inline void F_38 ( struct V_4 * V_5 )
{
F_39 ( V_5 , & V_40 ) ;
}
static inline void F_40 ( struct V_4 * V_5 )
{
F_34 ( V_5 , & V_40 ) ;
}
void F_41 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_42 V_43 )
{
F_42 ( V_5 , & V_40 ) ;
F_43 ( V_5 , V_1 , V_43 ) ;
}
void F_44 ( struct V_4 * V_5 )
{
F_34 ( V_5 , & V_40 ) ;
}
static inline void F_35 ( struct V_4 * V_5 ) { }
static inline void F_36 ( struct V_4 * V_5 ) { }
static inline void F_38 ( struct V_4 * V_5 ) { }
static inline void
F_45 ( struct V_4 * V_5 , T_1 V_44 ,
enum V_42 V_43 )
{
F_35 ( V_5 ) ;
F_46 ( V_5 , V_44 , V_43 ) ;
}
static inline void F_47 ( struct V_4 * V_5 )
{
F_36 ( V_5 ) ;
F_48 ( V_5 ) ;
}
static inline void F_49 ( struct V_4 * V_5 )
{
F_38 ( V_5 ) ;
F_50 ( V_5 ) ;
}
static inline void F_51 ( struct V_17 * V_9 ,
struct V_4 * V_5 )
{
#ifdef F_8
V_9 -> V_45 = V_5 ;
#endif
}
static T_2 F_52 ( struct V_17 * V_9 )
{
struct V_3 * V_7 = V_9 -> V_26 ;
T_2 V_12 , V_16 = { . V_15 = V_46 } ;
unsigned int V_47 = V_9 -> V_48 ;
F_51 ( V_9 , NULL ) ;
for (; V_47 ; V_7 ++ , V_47 >>= 1 ) {
struct V_49 * V_50 ;
struct V_4 * V_5 ;
if ( ! ( V_47 & 0x01 ) )
continue;
V_50 = F_53 ( & V_7 -> V_47 ) ;
V_5 = F_54 ( V_50 , struct V_4 , V_51 ) ;
V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
if ( V_12 . V_15 < V_16 . V_15 ) {
V_16 = V_12 ;
F_51 ( V_9 , V_5 ) ;
}
}
if ( V_16 . V_15 < 0 )
V_16 . V_15 = 0 ;
return V_16 ;
}
static inline T_2 F_55 ( struct V_17 * V_7 )
{
T_2 * V_52 = & V_7 -> V_26 [ V_53 ] . V_14 ;
T_2 * V_54 = & V_7 -> V_26 [ V_55 ] . V_14 ;
T_2 * V_56 = & V_7 -> V_26 [ V_57 ] . V_14 ;
return F_56 ( & V_7 -> V_58 ,
V_52 , V_54 , V_56 ) ;
}
static int T_5 F_57 ( char * V_59 )
{
if ( ! strcmp ( V_59 , L_1 ) )
V_60 = 0 ;
else if ( ! strcmp ( V_59 , L_2 ) )
V_60 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_58 ( void )
{
return V_60 ;
}
static inline int F_59 ( struct V_17 * V_9 )
{
return V_9 -> V_13 ;
}
static inline int F_60 ( void )
{
return F_59 ( F_12 ( & V_20 ) ) ;
}
static void
F_61 ( struct V_17 * V_9 , int V_61 )
{
T_2 V_16 ;
if ( ! V_9 -> V_13 )
return;
V_16 = F_52 ( V_9 ) ;
if ( V_61 && V_16 . V_15 == V_9 -> V_16 . V_15 )
return;
V_9 -> V_16 . V_15 = V_16 . V_15 ;
if ( V_9 -> V_62 )
return;
F_62 ( V_9 -> V_16 , 1 ) ;
}
static void F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
struct V_17 * V_9 = F_12 ( & V_20 ) ;
T_2 V_12 = F_9 ( F_10 ( V_5 ) , V_7 -> V_14 ) ;
F_31 ( F_64 ( V_5 ) < 0 ) ;
if ( V_7 -> V_9 != V_9 )
return;
if ( V_9 -> V_63 )
return;
if ( V_12 . V_15 < 0 )
V_12 . V_15 = 0 ;
if ( V_12 . V_15 >= V_9 -> V_16 . V_15 )
return;
V_9 -> V_45 = V_5 ;
if ( V_9 -> V_62 )
return;
V_9 -> V_16 = V_12 ;
F_62 ( V_12 , 1 ) ;
}
static inline void F_65 ( struct V_17 * V_7 )
{
V_7 -> V_16 . V_15 = V_46 ;
V_7 -> V_13 = 0 ;
}
static void F_66 ( void * V_64 )
{
struct V_17 * V_7 = F_12 ( & V_20 ) ;
if ( ! V_7 -> V_13 )
return;
F_19 ( & V_7 -> V_10 ) ;
F_55 ( V_7 ) ;
F_61 ( V_7 , 0 ) ;
F_18 ( & V_7 -> V_10 ) ;
}
static int F_67 ( void )
{
struct V_17 * V_7 = F_12 ( & V_20 ) ;
if ( F_68 () ) {
F_69 ( V_65 L_3
L_4 , V_7 -> V_66 ) ;
return 0 ;
}
V_7 -> V_13 = 1 ;
V_67 = V_68 ;
F_70 () ;
F_66 ( NULL ) ;
return 1 ;
}
static void F_71 ( struct V_69 * V_70 )
{
F_72 () ;
}
void F_73 ( void )
{
F_74 ( & V_71 ) ;
}
static inline int F_59 ( struct V_17 * V_72 ) { return 0 ; }
static inline int F_60 ( void ) { return 0 ; }
static inline int F_58 ( void ) { return 0 ; }
static inline int F_67 ( void ) { return 0 ; }
static inline void
F_61 ( struct V_17 * V_7 , int V_61 ) { }
static inline int F_63 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
return 0 ;
}
static inline void F_65 ( struct V_17 * V_7 ) { }
static inline void F_66 ( void * V_64 ) { }
void F_72 ( void )
{
#ifdef F_8
F_75 ( F_66 , NULL , 1 ) ;
#endif
F_76 () ;
}
void F_77 ( void )
{
F_78 ( ! F_79 () ,
V_73 L_5 ) ;
F_66 ( NULL ) ;
F_73 () ;
}
static inline void F_80 ( struct V_4 * V_5 )
{
#ifdef F_81
if ( V_5 -> V_74 )
return;
V_5 -> V_74 = F_82 ( 0 ) ;
memcpy ( V_5 -> V_75 , V_76 -> V_77 , V_78 ) ;
V_5 -> V_79 = V_76 -> V_80 ;
#endif
}
static inline void F_83 ( struct V_4 * V_5 )
{
#ifdef F_81
V_5 -> V_74 = NULL ;
#endif
}
static inline void F_84 ( struct V_4 * V_5 )
{
#ifdef F_81
if ( F_3 ( ! V_81 ) )
return;
F_85 ( V_5 , V_5 -> V_79 , V_5 -> V_74 ,
V_5 -> V_36 , V_5 -> V_75 , 0 ) ;
#endif
}
static inline
void F_86 ( const struct V_4 * V_5 , unsigned long * V_6 )
{
F_5 ( & V_5 -> V_7 -> V_9 -> V_10 , * V_6 ) ;
}
T_4 F_87 ( struct V_4 * V_5 , T_2 V_82 , T_2 V_83 )
{
T_4 V_84 = 1 ;
T_2 V_85 ;
V_85 = F_9 ( V_82 , F_10 ( V_5 ) ) ;
if ( V_85 . V_15 < 0 )
return 0 ;
if ( F_32 ( V_5 -> V_38 & V_86 ) )
return 0 ;
if ( V_83 . V_15 < V_67 )
V_83 . V_15 = V_67 ;
if ( F_16 ( V_85 . V_15 >= V_83 . V_15 ) ) {
T_3 V_87 = F_21 ( V_83 ) ;
V_84 = F_88 ( V_85 , V_87 ) ;
F_89 ( V_5 , V_87 * V_84 ) ;
if ( F_64 ( V_5 ) > V_82 . V_15 )
return V_84 ;
V_84 ++ ;
}
F_90 ( V_5 , V_83 ) ;
return V_84 ;
}
static int F_91 ( struct V_4 * V_5 ,
struct V_3 * V_7 )
{
F_47 ( V_5 ) ;
V_7 -> V_9 -> V_48 |= 1 << V_7 -> V_24 ;
V_5 -> V_38 = V_86 ;
return F_92 ( & V_7 -> V_47 , & V_5 -> V_51 ) ;
}
static void F_93 ( struct V_4 * V_5 ,
struct V_3 * V_7 ,
unsigned long V_88 , int V_89 )
{
struct V_17 * V_9 = V_7 -> V_9 ;
unsigned int V_38 = V_5 -> V_38 ;
V_5 -> V_38 = V_88 ;
if ( ! ( V_38 & V_86 ) )
return;
if ( ! F_94 ( & V_7 -> V_47 , & V_5 -> V_51 ) )
V_9 -> V_48 &= ~ ( 1 << V_7 -> V_24 ) ;
#ifdef F_8
if ( V_89 && V_5 == V_9 -> V_45 )
F_61 ( V_9 , 1 ) ;
#endif
}
static inline int
F_95 ( struct V_4 * V_5 , struct V_3 * V_7 , bool V_90 )
{
if ( F_96 ( V_5 ) ) {
unsigned long V_38 = V_5 -> V_38 ;
int V_89 ;
F_49 ( V_5 ) ;
F_83 ( V_5 ) ;
V_89 = V_7 -> V_9 == F_12 ( & V_20 ) ;
if ( ! V_90 )
V_38 = V_91 ;
F_93 ( V_5 , V_7 , V_38 , V_89 ) ;
return 1 ;
}
return 0 ;
}
void F_97 ( struct V_4 * V_5 , T_2 V_92 ,
unsigned long V_93 , const enum V_42 V_43 )
{
struct V_3 * V_7 , * V_11 ;
unsigned long V_6 ;
int V_94 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
F_95 ( V_5 , V_7 , true ) ;
if ( V_43 & V_95 ) {
V_92 = F_23 ( V_92 , V_7 -> V_96 () ) ;
#ifdef F_98
V_92 = F_23 ( V_92 , F_25 ( 0 , V_67 ) ) ;
#endif
}
F_99 ( V_5 , V_92 , V_93 ) ;
V_11 = F_15 ( V_5 , V_7 , V_43 & V_97 ) ;
F_80 ( V_5 ) ;
V_94 = F_91 ( V_5 , V_11 ) ;
if ( ! V_94 )
goto V_98;
if ( ! F_100 ( V_5 ) ) {
if ( V_11 -> V_9 -> V_99 )
F_101 ( V_11 -> V_9 -> V_66 ) ;
} else {
F_63 ( V_5 , V_11 ) ;
}
V_98:
F_86 ( V_5 , & V_6 ) ;
}
int F_102 ( struct V_4 * V_5 )
{
struct V_3 * V_7 ;
unsigned long V_6 ;
int V_100 = - 1 ;
if ( ! F_103 ( V_5 ) )
return 0 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
if ( ! F_17 ( V_5 ) )
V_100 = F_95 ( V_5 , V_7 , false ) ;
F_86 ( V_5 , & V_6 ) ;
return V_100 ;
}
int F_28 ( struct V_4 * V_5 )
{
for (; ; ) {
int V_100 = F_102 ( V_5 ) ;
if ( V_100 >= 0 )
return V_100 ;
F_6 () ;
}
}
T_2 F_104 ( const struct V_4 * V_5 )
{
unsigned long V_6 ;
T_2 V_101 ;
F_2 ( V_5 , & V_6 ) ;
V_101 = F_105 ( V_5 ) ;
F_86 ( V_5 , & V_6 ) ;
return V_101 ;
}
T_4 F_106 ( void )
{
struct V_17 * V_9 = F_12 ( & V_20 ) ;
T_4 V_12 = V_46 ;
unsigned long V_6 ;
F_4 ( & V_9 -> V_10 , V_6 ) ;
if ( ! F_59 ( V_9 ) )
V_12 = F_52 ( V_9 ) . V_15 ;
F_5 ( & V_9 -> V_10 , V_6 ) ;
return V_12 ;
}
static void F_43 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_42 V_43 )
{
struct V_17 * V_9 ;
int V_7 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_9 = F_107 ( & V_20 ) ;
if ( V_1 == V_102 && V_43 != V_103 )
V_1 = V_104 ;
V_7 = F_1 ( V_1 ) ;
V_5 -> V_7 = & V_9 -> V_26 [ V_7 ] ;
F_108 ( & V_5 -> V_51 ) ;
#ifdef F_81
V_5 -> V_74 = NULL ;
V_5 -> V_79 = - 1 ;
memset ( V_5 -> V_75 , 0 , V_78 ) ;
#endif
}
void F_109 ( struct V_4 * V_5 , T_1 V_1 ,
enum V_42 V_43 )
{
F_45 ( V_5 , V_1 , V_43 ) ;
F_43 ( V_5 , V_1 , V_43 ) ;
}
bool F_103 ( const struct V_4 * V_5 )
{
struct V_17 * V_9 ;
unsigned int V_105 ;
do {
V_9 = F_110 ( V_5 -> V_7 -> V_9 ) ;
V_105 = F_111 ( & V_9 -> V_105 ) ;
if ( V_5 -> V_38 != V_91 ||
V_9 -> V_106 == V_5 )
return true ;
} while ( F_112 ( & V_9 -> V_105 , V_105 ) ||
V_9 != F_110 ( V_5 -> V_7 -> V_9 ) );
return false ;
}
static void F_113 ( struct V_17 * V_9 ,
struct V_3 * V_7 ,
struct V_4 * V_5 , T_2 * V_82 )
{
enum V_107 ( * V_108 ) ( struct V_4 * ) ;
int V_90 ;
F_114 ( & V_9 -> V_10 ) ;
F_49 ( V_5 ) ;
V_9 -> V_106 = V_5 ;
F_115 ( & V_9 -> V_105 ) ;
F_93 ( V_5 , V_7 , V_91 , 0 ) ;
F_84 ( V_5 ) ;
V_108 = V_5 -> V_36 ;
F_18 ( & V_9 -> V_10 ) ;
F_116 ( V_5 , V_82 ) ;
V_90 = V_108 ( V_5 ) ;
F_117 ( V_5 ) ;
F_19 ( & V_9 -> V_10 ) ;
if ( V_90 != V_109 &&
! ( V_5 -> V_38 & V_86 ) )
F_91 ( V_5 , V_7 ) ;
F_115 ( & V_9 -> V_105 ) ;
F_31 ( V_9 -> V_106 != V_5 ) ;
V_9 -> V_106 = NULL ;
}
static void F_118 ( struct V_17 * V_9 , T_2 V_82 )
{
struct V_3 * V_7 = V_9 -> V_26 ;
unsigned int V_47 = V_9 -> V_48 ;
for (; V_47 ; V_7 ++ , V_47 >>= 1 ) {
struct V_49 * V_51 ;
T_2 V_110 ;
if ( ! ( V_47 & 0x01 ) )
continue;
V_110 = F_24 ( V_82 , V_7 -> V_14 ) ;
while ( ( V_51 = F_53 ( & V_7 -> V_47 ) ) ) {
struct V_4 * V_5 ;
V_5 = F_54 ( V_51 , struct V_4 , V_51 ) ;
if ( V_110 . V_15 < F_119 ( V_5 ) )
break;
F_113 ( V_9 , V_7 , V_5 , & V_110 ) ;
}
}
}
void F_120 ( struct V_111 * V_112 )
{
struct V_17 * V_9 = F_12 ( & V_20 ) ;
T_2 V_16 , V_82 , V_113 , V_85 ;
int V_114 = 0 ;
F_121 ( ! V_9 -> V_13 ) ;
V_9 -> V_115 ++ ;
V_112 -> V_116 . V_15 = V_46 ;
F_19 ( & V_9 -> V_10 ) ;
V_113 = V_82 = F_55 ( V_9 ) ;
V_117:
V_9 -> V_63 = 1 ;
V_9 -> V_16 . V_15 = V_46 ;
F_118 ( V_9 , V_82 ) ;
V_16 = F_52 ( V_9 ) ;
V_9 -> V_16 = V_16 ;
V_9 -> V_63 = 0 ;
F_18 ( & V_9 -> V_10 ) ;
if ( ! F_62 ( V_16 , 0 ) ) {
V_9 -> V_62 = 0 ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_82 = F_55 ( V_9 ) ;
V_9 -> V_118 ++ ;
if ( ++ V_114 < 3 )
goto V_117;
V_9 -> V_119 ++ ;
V_9 -> V_62 = 1 ;
F_18 ( & V_9 -> V_10 ) ;
V_85 = F_9 ( V_82 , V_113 ) ;
if ( ( unsigned int ) V_85 . V_15 > V_9 -> V_120 )
V_9 -> V_120 = ( unsigned int ) V_85 . V_15 ;
if ( V_85 . V_15 > 100 * V_121 )
V_16 = F_122 ( V_82 , 100 * V_121 ) ;
else
V_16 = F_24 ( V_82 , V_85 ) ;
F_62 ( V_16 , 1 ) ;
F_123 ( V_65 L_6 ,
F_21 ( V_85 ) ) ;
}
static inline void F_124 ( void )
{
struct V_122 * V_123 ;
if ( ! F_60 () )
return;
V_123 = F_12 ( & V_124 ) ;
if ( V_123 && V_123 -> V_125 )
F_120 ( V_123 -> V_125 ) ;
}
static inline void F_124 ( void ) { }
void F_125 ( void )
{
struct V_17 * V_9 = F_12 ( & V_20 ) ;
T_2 V_82 ;
if ( F_59 ( V_9 ) )
return;
if ( F_126 ( ! F_58 () ) ) {
F_67 () ;
return;
}
F_19 ( & V_9 -> V_10 ) ;
V_82 = F_55 ( V_9 ) ;
F_118 ( V_9 , V_82 ) ;
F_18 ( & V_9 -> V_10 ) ;
}
static enum V_107 F_127 ( struct V_4 * V_5 )
{
struct V_126 * V_127 =
F_54 ( V_5 , struct V_126 , V_5 ) ;
struct V_128 * V_129 = V_127 -> V_129 ;
V_127 -> V_129 = NULL ;
if ( V_129 )
F_128 ( V_129 ) ;
return V_109 ;
}
void F_129 ( struct V_126 * V_130 , struct V_128 * V_129 )
{
V_130 -> V_5 . V_36 = F_127 ;
V_130 -> V_129 = V_129 ;
}
static int T_6 F_130 ( struct V_126 * V_127 , enum V_42 V_43 )
{
F_129 ( V_127 , V_76 ) ;
do {
F_131 ( V_131 ) ;
F_132 ( & V_127 -> V_5 , V_43 ) ;
if ( F_3 ( V_127 -> V_129 ) )
F_133 () ;
F_28 ( & V_127 -> V_5 ) ;
V_43 = V_103 ;
} while ( V_127 -> V_129 && ! F_134 ( V_76 ) );
F_135 ( V_132 ) ;
return V_127 -> V_129 == NULL ;
}
static int F_136 ( struct V_4 * V_5 , struct V_133 T_7 * V_134 )
{
struct V_133 V_135 ;
T_2 V_101 ;
V_101 = F_105 ( V_5 ) ;
if ( V_101 . V_15 <= 0 )
return 0 ;
V_135 = F_137 ( V_101 ) ;
if ( F_138 ( V_134 , & V_135 , sizeof( * V_134 ) ) )
return - V_136 ;
return 1 ;
}
long T_6 F_139 ( struct V_137 * V_90 )
{
struct V_126 V_127 ;
struct V_133 T_7 * V_134 ;
int V_100 = 0 ;
F_41 ( & V_127 . V_5 , V_90 -> V_138 . V_44 ,
V_103 ) ;
F_140 ( & V_127 . V_5 , V_90 -> V_138 . V_12 ) ;
if ( F_130 ( & V_127 , V_103 ) )
goto V_139;
V_134 = V_90 -> V_138 . V_134 ;
if ( V_134 ) {
V_100 = F_136 ( & V_127 . V_5 , V_134 ) ;
if ( V_100 <= 0 )
goto V_139;
}
V_100 = - V_140 ;
V_139:
F_44 ( & V_127 . V_5 ) ;
return V_100 ;
}
long F_141 ( struct V_133 * V_141 , struct V_133 T_7 * V_134 ,
const enum V_42 V_43 , const T_1 V_44 )
{
struct V_137 * V_90 ;
struct V_126 V_127 ;
int V_100 = 0 ;
unsigned long V_142 ;
V_142 = V_76 -> V_143 ;
if ( F_142 ( V_76 ) || F_143 ( V_76 ) )
V_142 = 0 ;
F_41 ( & V_127 . V_5 , V_44 , V_43 ) ;
F_99 ( & V_127 . V_5 , F_144 ( * V_141 ) , V_142 ) ;
if ( F_130 ( & V_127 , V_43 ) )
goto V_139;
if ( V_43 == V_103 ) {
V_100 = - V_144 ;
goto V_139;
}
if ( V_134 ) {
V_100 = F_136 ( & V_127 . V_5 , V_134 ) ;
if ( V_100 <= 0 )
goto V_139;
}
V_90 = & V_76 -> V_137 ;
V_90 -> V_108 = F_139 ;
V_90 -> V_138 . V_44 = V_127 . V_5 . V_7 -> V_44 ;
V_90 -> V_138 . V_134 = V_134 ;
V_90 -> V_138 . V_12 = F_64 ( & V_127 . V_5 ) ;
V_100 = - V_140 ;
V_139:
F_44 ( & V_127 . V_5 ) ;
return V_100 ;
}
static void F_145 ( int V_66 )
{
struct V_17 * V_9 = & F_13 ( V_20 , V_66 ) ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
V_9 -> V_26 [ V_145 ] . V_9 = V_9 ;
F_146 ( & V_9 -> V_26 [ V_145 ] . V_47 ) ;
}
V_9 -> V_66 = V_66 ;
F_65 ( V_9 ) ;
}
static void F_147 ( struct V_3 * V_147 ,
struct V_3 * V_11 )
{
struct V_4 * V_5 ;
struct V_49 * V_51 ;
while ( ( V_51 = F_53 ( & V_147 -> V_47 ) ) ) {
V_5 = F_54 ( V_51 , struct V_4 , V_51 ) ;
F_121 ( F_17 ( V_5 ) ) ;
F_49 ( V_5 ) ;
F_93 ( V_5 , V_147 , V_86 , 0 ) ;
V_5 -> V_7 = V_11 ;
F_91 ( V_5 , V_11 ) ;
}
}
static void F_148 ( int V_148 )
{
struct V_17 * V_147 , * V_11 ;
int V_145 ;
F_121 ( F_149 ( V_148 ) ) ;
F_150 ( V_148 ) ;
F_151 () ;
V_147 = & F_13 ( V_20 , V_148 ) ;
V_11 = F_12 ( & V_20 ) ;
F_19 ( & V_11 -> V_10 ) ;
F_152 ( & V_147 -> V_10 , V_149 ) ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
F_147 ( & V_147 -> V_26 [ V_145 ] ,
& V_11 -> V_26 [ V_145 ] ) ;
}
F_18 ( & V_147 -> V_10 ) ;
F_18 ( & V_11 -> V_10 ) ;
F_124 () ;
F_153 () ;
}
static int F_154 ( struct V_150 * V_151 ,
unsigned long V_152 , void * V_153 )
{
int V_148 = ( long ) V_153 ;
switch ( V_152 ) {
case V_154 :
case V_155 :
F_145 ( V_148 ) ;
break;
#ifdef F_155
case V_156 :
case V_157 :
F_148 ( V_148 ) ;
break;
#endif
default:
break;
}
return V_158 ;
}
void T_5 F_156 ( void )
{
F_154 ( & V_159 , ( unsigned long ) V_154 ,
( void * ) ( long ) F_157 () ) ;
F_158 ( & V_159 ) ;
}
int T_6
F_159 ( T_2 * V_12 , unsigned long V_85 ,
const enum V_42 V_43 , int clock )
{
struct V_126 V_127 ;
if ( V_12 && ! V_12 -> V_15 ) {
F_135 ( V_132 ) ;
return 0 ;
}
if ( ! V_12 ) {
F_160 () ;
return - V_160 ;
}
F_41 ( & V_127 . V_5 , clock , V_43 ) ;
F_99 ( & V_127 . V_5 , * V_12 , V_85 ) ;
F_129 ( & V_127 , V_76 ) ;
F_132 ( & V_127 . V_5 , V_43 ) ;
if ( F_3 ( V_127 . V_129 ) )
F_160 () ;
F_28 ( & V_127 . V_5 ) ;
F_44 ( & V_127 . V_5 ) ;
F_135 ( V_132 ) ;
return ! V_127 . V_129 ? 0 : - V_160 ;
}
int T_6 F_161 ( T_2 * V_12 , unsigned long V_85 ,
const enum V_42 V_43 )
{
return F_159 ( V_12 , V_85 , V_43 ,
V_104 ) ;
}
int T_6 F_162 ( T_2 * V_12 ,
const enum V_42 V_43 )
{
return F_161 ( V_12 , 0 , V_43 ) ;
}
