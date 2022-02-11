static inline int F_1 ( T_1 V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( struct V_3 * V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
T_2 V_9 , V_10 , V_11 ;
V_6 = F_3 ( & V_9 , & V_10 , & V_11 ) ;
V_7 = F_4 ( V_6 , V_10 ) ;
V_5 = F_4 ( V_6 , V_9 ) ;
V_8 = F_4 ( V_6 , V_11 ) ;
V_4 -> V_12 [ V_13 ] . V_14 = V_5 ;
V_4 -> V_12 [ V_15 ] . V_14 = V_6 ;
V_4 -> V_12 [ V_16 ] . V_14 = V_7 ;
V_4 -> V_12 [ V_17 ] . V_14 = V_8 ;
}
static
struct V_18 * F_5 ( const struct V_19 * V_20 ,
unsigned long * V_21 )
{
struct V_18 * V_4 ;
for (; ; ) {
V_4 = V_20 -> V_4 ;
if ( F_6 ( V_4 != NULL ) ) {
F_7 ( & V_4 -> V_22 -> V_23 , * V_21 ) ;
if ( F_6 ( V_4 == V_20 -> V_4 ) )
return V_4 ;
F_8 ( & V_4 -> V_22 -> V_23 , * V_21 ) ;
}
F_9 () ;
}
}
static int
F_10 ( struct V_19 * V_20 , struct V_18 * V_24 )
{
#ifdef F_11
T_2 V_25 ;
if ( ! V_24 -> V_22 -> V_26 )
return 0 ;
V_25 = F_12 ( F_13 ( V_20 ) , V_24 -> V_27 ) ;
return V_25 . V_28 <= V_24 -> V_22 -> V_29 . V_28 ;
#else
return 0 ;
#endif
}
static inline struct V_18 *
F_14 ( struct V_19 * V_20 , struct V_18 * V_4 ,
int V_30 )
{
struct V_18 * V_24 ;
struct V_3 * V_31 ;
int V_32 = F_15 () ;
int V_33 = F_16 ( V_30 ) ;
int V_34 = V_4 -> V_35 ;
V_36:
V_31 = & F_17 ( V_37 , V_33 ) ;
V_24 = & V_31 -> V_12 [ V_34 ] ;
if ( V_4 != V_24 ) {
if ( F_18 ( F_19 ( V_20 ) ) )
return V_4 ;
V_20 -> V_4 = NULL ;
F_20 ( & V_4 -> V_22 -> V_23 ) ;
F_21 ( & V_24 -> V_22 -> V_23 ) ;
if ( V_33 != V_32 && F_10 ( V_20 , V_24 ) ) {
V_33 = V_32 ;
F_20 ( & V_24 -> V_22 -> V_23 ) ;
F_21 ( & V_4 -> V_22 -> V_23 ) ;
V_20 -> V_4 = V_4 ;
goto V_36;
}
V_20 -> V_4 = V_24 ;
} else {
if ( V_33 != V_32 && F_10 ( V_20 , V_24 ) ) {
V_33 = V_32 ;
goto V_36;
}
}
return V_24 ;
}
static inline struct V_18 *
F_5 ( const struct V_19 * V_20 , unsigned long * V_21 )
{
struct V_18 * V_4 = V_20 -> V_4 ;
F_7 ( & V_4 -> V_22 -> V_23 , * V_21 ) ;
return V_4 ;
}
T_3 F_22 ( const T_2 V_38 , T_3 div )
{
int V_39 = 0 ;
T_3 V_40 ;
T_4 V_41 ;
V_40 = F_23 ( V_38 ) ;
V_41 = V_40 < 0 ? - V_40 : V_40 ;
while ( div >> 32 ) {
V_39 ++ ;
div >>= 1 ;
}
V_41 >>= V_39 ;
F_24 ( V_41 , ( unsigned long ) div ) ;
return V_40 < 0 ? - V_41 : V_41 ;
}
T_2 F_25 ( const T_2 V_42 , const T_2 V_43 )
{
T_2 V_44 = F_4 ( V_42 , V_43 ) ;
if ( V_44 . V_28 < 0 || V_44 . V_28 < V_42 . V_28 || V_44 . V_28 < V_43 . V_28 )
V_44 = F_26 ( V_45 , 0 ) ;
return V_44 ;
}
static void * F_27 ( void * V_46 )
{
return ( (struct V_19 * ) V_46 ) -> V_47 ;
}
static int F_28 ( void * V_46 , enum V_48 V_49 )
{
struct V_19 * V_20 = V_46 ;
switch ( V_49 ) {
case V_50 :
F_29 ( V_20 ) ;
F_30 ( V_20 , & V_51 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_31 ( void * V_46 , enum V_48 V_49 )
{
switch ( V_49 ) {
case V_52 :
F_32 ( 1 ) ;
return 0 ;
case V_50 :
F_33 ( 1 ) ;
default:
return 0 ;
}
}
static int F_34 ( void * V_46 , enum V_48 V_49 )
{
struct V_19 * V_20 = V_46 ;
switch ( V_49 ) {
case V_50 :
F_29 ( V_20 ) ;
F_35 ( V_20 , & V_51 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_36 ( struct V_19 * V_20 )
{
F_30 ( V_20 , & V_51 ) ;
}
static inline void F_37 ( struct V_19 * V_20 )
{
F_38 ( V_20 , & V_51 ) ;
}
static inline void F_39 ( struct V_19 * V_20 )
{
F_40 ( V_20 , & V_51 ) ;
}
static inline void F_41 ( struct V_19 * V_20 )
{
F_35 ( V_20 , & V_51 ) ;
}
void F_42 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_53 V_54 )
{
F_43 ( V_20 , & V_51 ) ;
F_44 ( V_20 , V_1 , V_54 ) ;
}
void F_45 ( struct V_19 * V_20 )
{
F_35 ( V_20 , & V_51 ) ;
}
static inline void F_36 ( struct V_19 * V_20 ) { }
static inline void F_37 ( struct V_19 * V_20 ) { }
static inline void F_39 ( struct V_19 * V_20 ) { }
static inline void
F_46 ( struct V_19 * V_20 , T_1 V_55 ,
enum V_53 V_54 )
{
F_36 ( V_20 ) ;
F_47 ( V_20 , V_55 , V_54 ) ;
}
static inline void F_48 ( struct V_19 * V_20 )
{
F_37 ( V_20 ) ;
F_49 ( V_20 ) ;
}
static inline void F_50 ( struct V_19 * V_20 )
{
F_39 ( V_20 ) ;
F_51 ( V_20 ) ;
}
static T_2 F_52 ( struct V_3 * V_22 )
{
struct V_18 * V_4 = V_22 -> V_12 ;
T_2 V_25 , V_29 = { . V_28 = V_56 } ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ , V_4 ++ ) {
struct V_59 * V_60 ;
struct V_19 * V_20 ;
V_60 = F_53 ( & V_4 -> V_61 ) ;
if ( ! V_60 )
continue;
V_20 = F_54 ( V_60 , struct V_19 , V_62 ) ;
V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
if ( V_25 . V_28 < V_29 . V_28 )
V_29 = V_25 ;
}
if ( V_29 . V_28 < 0 )
V_29 . V_28 = 0 ;
return V_29 ;
}
static int T_5 F_55 ( char * V_63 )
{
if ( ! strcmp ( V_63 , L_1 ) )
V_64 = 0 ;
else if ( ! strcmp ( V_63 , L_2 ) )
V_64 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_56 ( void )
{
return V_64 ;
}
static inline int F_57 ( void )
{
return F_58 ( V_37 . V_26 ) ;
}
static void
F_59 ( struct V_3 * V_22 , int V_65 )
{
T_2 V_29 = F_52 ( V_22 ) ;
if ( V_65 && V_29 . V_28 == V_22 -> V_29 . V_28 )
return;
V_22 -> V_29 . V_28 = V_29 . V_28 ;
if ( V_22 -> V_66 )
return;
if ( V_22 -> V_29 . V_28 != V_56 )
F_60 ( V_22 -> V_29 , 1 ) ;
}
static int F_61 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
int V_44 ;
F_32 ( F_63 ( V_20 ) < 0 ) ;
if ( F_19 ( V_20 ) )
return 0 ;
if ( V_25 . V_28 < 0 )
return - V_67 ;
if ( V_25 . V_28 >= V_22 -> V_29 . V_28 )
return 0 ;
if ( V_22 -> V_68 )
return 0 ;
if ( V_22 -> V_66 )
return 0 ;
V_44 = F_60 ( V_25 , 0 ) ;
if ( ! F_64 ( V_44 ) )
V_22 -> V_29 = V_25 ;
return V_44 ;
}
static inline void F_65 ( struct V_3 * V_4 )
{
V_4 -> V_29 . V_28 = V_56 ;
V_4 -> V_26 = 0 ;
}
static inline T_2 F_66 ( struct V_3 * V_4 )
{
T_2 * V_69 = & V_4 -> V_12 [ V_13 ] . V_27 ;
T_2 * V_70 = & V_4 -> V_12 [ V_16 ] . V_27 ;
T_2 * V_71 = & V_4 -> V_12 [ V_17 ] . V_27 ;
return F_67 ( V_69 , V_70 , V_71 ) ;
}
static void F_68 ( void * V_72 )
{
struct V_3 * V_4 = F_62 ( & V_37 ) ;
if ( ! F_57 () )
return;
F_21 ( & V_4 -> V_23 ) ;
F_66 ( V_4 ) ;
F_59 ( V_4 , 0 ) ;
F_20 ( & V_4 -> V_23 ) ;
}
static int F_69 ( void )
{
int V_57 , V_33 = F_15 () ;
struct V_3 * V_4 = & F_17 ( V_37 , V_33 ) ;
unsigned long V_21 ;
if ( V_4 -> V_26 )
return 1 ;
F_70 ( V_21 ) ;
if ( F_71 () ) {
F_72 ( V_21 ) ;
F_73 ( V_73 L_3
L_4 , V_33 ) ;
return 0 ;
}
V_4 -> V_26 = 1 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
V_4 -> V_12 [ V_57 ] . V_74 = V_75 ;
F_74 () ;
F_68 ( NULL ) ;
F_72 ( V_21 ) ;
return 1 ;
}
static void F_75 ( struct V_76 * V_77 )
{
F_76 () ;
}
void F_77 ( void )
{
F_78 ( & V_78 ) ;
}
static inline int F_57 ( void ) { return 0 ; }
static inline int F_56 ( void ) { return 0 ; }
static inline int F_69 ( void ) { return 0 ; }
static inline void
F_59 ( struct V_3 * V_4 , int V_65 ) { }
static inline int F_61 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
return 0 ;
}
static inline void F_65 ( struct V_3 * V_4 ) { }
static inline void F_68 ( void * V_72 ) { }
void F_76 ( void )
{
#ifdef F_11
F_79 ( F_68 , NULL , 1 ) ;
#endif
F_80 () ;
}
void F_81 ( void )
{
F_82 ( ! F_83 () ,
V_79 L_5 ) ;
F_68 ( NULL ) ;
F_77 () ;
}
static inline void F_84 ( struct V_19 * V_20 )
{
#ifdef F_85
if ( V_20 -> V_80 )
return;
V_20 -> V_80 = F_86 ( 0 ) ;
memcpy ( V_20 -> V_81 , V_82 -> V_83 , V_84 ) ;
V_20 -> V_85 = V_82 -> V_86 ;
#endif
}
static inline void F_87 ( struct V_19 * V_20 )
{
#ifdef F_85
V_20 -> V_80 = NULL ;
#endif
}
static inline void F_88 ( struct V_19 * V_20 )
{
#ifdef F_85
if ( F_6 ( ! V_87 ) )
return;
F_89 ( V_20 , V_20 -> V_85 , V_20 -> V_80 ,
V_20 -> V_47 , V_20 -> V_81 , 0 ) ;
#endif
}
static inline
void F_90 ( const struct V_19 * V_20 , unsigned long * V_21 )
{
F_8 ( & V_20 -> V_4 -> V_22 -> V_23 , * V_21 ) ;
}
T_4 F_91 ( struct V_19 * V_20 , T_2 V_88 , T_2 V_89 )
{
T_4 V_90 = 1 ;
T_2 V_91 ;
V_91 = F_12 ( V_88 , F_13 ( V_20 ) ) ;
if ( V_91 . V_28 < 0 )
return 0 ;
if ( V_89 . V_28 < V_20 -> V_4 -> V_74 . V_28 )
V_89 . V_28 = V_20 -> V_4 -> V_74 . V_28 ;
if ( F_18 ( V_91 . V_28 >= V_89 . V_28 ) ) {
T_3 V_92 = F_23 ( V_89 ) ;
V_90 = F_92 ( V_91 , V_92 ) ;
F_93 ( V_20 , V_92 * V_90 ) ;
if ( F_63 ( V_20 ) > V_88 . V_28 )
return V_90 ;
V_90 ++ ;
}
F_94 ( V_20 , V_89 ) ;
return V_90 ;
}
static int F_95 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
F_48 ( V_20 ) ;
F_96 ( & V_4 -> V_61 , & V_20 -> V_62 ) ;
V_4 -> V_22 -> V_93 |= 1 << V_4 -> V_35 ;
V_20 -> V_49 |= V_94 ;
return ( & V_20 -> V_62 == V_4 -> V_61 . V_60 ) ;
}
static void F_97 ( struct V_19 * V_20 ,
struct V_18 * V_4 ,
unsigned long V_95 , int V_96 )
{
struct V_59 * V_97 ;
if ( ! ( V_20 -> V_49 & V_94 ) )
goto V_98;
V_97 = F_53 ( & V_4 -> V_61 ) ;
F_98 ( & V_4 -> V_61 , & V_20 -> V_62 ) ;
if ( & V_20 -> V_62 == V_97 ) {
#ifdef F_11
if ( V_96 && F_57 () ) {
T_2 V_25 ;
V_25 = F_12 ( F_13 ( V_20 ) ,
V_4 -> V_27 ) ;
if ( V_4 -> V_22 -> V_29 . V_28 == V_25 . V_28 )
F_59 ( V_4 -> V_22 , 1 ) ;
}
#endif
}
if ( ! F_53 ( & V_4 -> V_61 ) )
V_4 -> V_22 -> V_93 &= ~ ( 1 << V_4 -> V_35 ) ;
V_98:
V_20 -> V_49 = V_95 ;
}
static inline int
F_99 ( struct V_19 * V_20 , struct V_18 * V_4 )
{
if ( F_100 ( V_20 ) ) {
unsigned long V_49 ;
int V_96 ;
F_50 ( V_20 ) ;
F_87 ( V_20 ) ;
V_96 = V_4 -> V_22 == F_62 ( & V_37 ) ;
V_49 = V_20 -> V_49 & V_99 ;
F_97 ( V_20 , V_4 , V_49 , V_96 ) ;
return 1 ;
}
return 0 ;
}
int F_101 ( struct V_19 * V_20 , T_2 V_100 ,
unsigned long V_101 , const enum V_53 V_54 ,
int V_102 )
{
struct V_18 * V_4 , * V_24 ;
unsigned long V_21 ;
int V_103 , V_104 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
V_103 = F_99 ( V_20 , V_4 ) ;
if ( V_54 & V_105 ) {
V_100 = F_25 ( V_100 , V_4 -> V_106 () ) ;
#ifdef F_102
V_100 = F_25 ( V_100 , V_4 -> V_74 ) ;
#endif
}
F_103 ( V_20 , V_100 , V_101 ) ;
V_24 = F_14 ( V_20 , V_4 , V_54 & V_107 ) ;
F_84 ( V_20 ) ;
V_104 = F_95 ( V_20 , V_24 ) ;
if ( ! V_104 ) {
F_90 ( V_20 , & V_21 ) ;
return V_103 ;
}
if ( ! F_104 ( V_20 ) ) {
F_105 ( V_24 -> V_22 -> V_33 ) ;
} else if ( V_24 -> V_22 == F_62 ( & V_37 ) &&
F_61 ( V_20 , V_24 ) ) {
if ( V_102 ) {
F_20 ( & V_24 -> V_22 -> V_23 ) ;
F_106 ( V_108 ) ;
F_72 ( V_21 ) ;
return V_103 ;
} else {
F_107 ( V_108 ) ;
}
}
F_90 ( V_20 , & V_21 ) ;
return V_103 ;
}
int F_108 ( struct V_19 * V_20 , T_2 V_100 ,
unsigned long V_101 , const enum V_53 V_54 )
{
return F_101 ( V_20 , V_100 , V_101 , V_54 , 1 ) ;
}
int
F_109 ( struct V_19 * V_20 , T_2 V_100 , const enum V_53 V_54 )
{
return F_101 ( V_20 , V_100 , 0 , V_54 , 1 ) ;
}
int F_110 ( struct V_19 * V_20 )
{
struct V_18 * V_4 ;
unsigned long V_21 ;
int V_103 = - 1 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
if ( ! F_19 ( V_20 ) )
V_103 = F_99 ( V_20 , V_4 ) ;
F_90 ( V_20 , & V_21 ) ;
return V_103 ;
}
int F_29 ( struct V_19 * V_20 )
{
for (; ; ) {
int V_103 = F_110 ( V_20 ) ;
if ( V_103 >= 0 )
return V_103 ;
F_9 () ;
}
}
T_2 F_111 ( const struct V_19 * V_20 )
{
unsigned long V_21 ;
T_2 V_109 ;
F_5 ( V_20 , & V_21 ) ;
V_109 = F_112 ( V_20 ) ;
F_90 ( V_20 , & V_21 ) ;
return V_109 ;
}
T_2 F_113 ( void )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_110 = { . V_28 = V_56 } ;
unsigned long V_21 ;
F_7 ( & V_22 -> V_23 , V_21 ) ;
if ( ! F_57 () )
V_110 = F_12 ( F_52 ( V_22 ) ,
F_114 () ) ;
F_8 ( & V_22 -> V_23 , V_21 ) ;
if ( V_110 . V_28 < 0 )
V_110 . V_28 = 0 ;
return V_110 ;
}
static void F_44 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_53 V_54 )
{
struct V_3 * V_22 ;
int V_4 ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_22 = F_115 ( & V_37 ) ;
if ( V_1 == V_111 && V_54 != V_112 )
V_1 = V_113 ;
V_4 = F_1 ( V_1 ) ;
V_20 -> V_4 = & V_22 -> V_12 [ V_4 ] ;
F_116 ( & V_20 -> V_62 ) ;
#ifdef F_85
V_20 -> V_80 = NULL ;
V_20 -> V_85 = - 1 ;
memset ( V_20 -> V_81 , 0 , V_84 ) ;
#endif
}
void F_117 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_53 V_54 )
{
F_46 ( V_20 , V_1 , V_54 ) ;
F_44 ( V_20 , V_1 , V_54 ) ;
}
int F_118 ( const T_1 V_114 , struct V_115 * V_116 )
{
struct V_3 * V_22 ;
int V_4 = F_1 ( V_114 ) ;
V_22 = F_115 ( & V_37 ) ;
* V_116 = F_119 ( V_22 -> V_12 [ V_4 ] . V_74 ) ;
return 0 ;
}
static void F_120 ( struct V_19 * V_20 , T_2 * V_88 )
{
struct V_18 * V_4 = V_20 -> V_4 ;
struct V_3 * V_22 = V_4 -> V_22 ;
enum V_117 ( * V_118 ) ( struct V_19 * ) ;
int V_119 ;
F_33 ( ! F_83 () ) ;
F_50 ( V_20 ) ;
F_97 ( V_20 , V_4 , V_99 , 0 ) ;
F_88 ( V_20 ) ;
V_118 = V_20 -> V_47 ;
F_20 ( & V_22 -> V_23 ) ;
F_121 ( V_20 , V_88 ) ;
V_119 = V_118 ( V_20 ) ;
F_122 ( V_20 ) ;
F_21 ( & V_22 -> V_23 ) ;
if ( V_119 != V_120 ) {
F_123 ( V_20 -> V_49 != V_99 ) ;
F_95 ( V_20 , V_4 ) ;
}
F_32 ( ! ( V_20 -> V_49 & V_99 ) ) ;
V_20 -> V_49 &= ~ V_99 ;
}
void F_124 ( struct V_121 * V_122 )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_29 , V_88 , V_123 , V_91 ;
int V_57 , V_124 = 0 ;
F_123 ( ! V_22 -> V_26 ) ;
V_22 -> V_125 ++ ;
V_122 -> V_126 . V_28 = V_56 ;
F_21 ( & V_22 -> V_23 ) ;
V_123 = V_88 = F_66 ( V_22 ) ;
V_127:
V_22 -> V_68 = 1 ;
V_22 -> V_29 . V_28 = V_56 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
struct V_18 * V_4 ;
struct V_59 * V_62 ;
T_2 V_128 ;
if ( ! ( V_22 -> V_93 & ( 1 << V_57 ) ) )
continue;
V_4 = V_22 -> V_12 + V_57 ;
V_128 = F_4 ( V_88 , V_4 -> V_27 ) ;
while ( ( V_62 = F_53 ( & V_4 -> V_61 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_54 ( V_62 , struct V_19 , V_62 ) ;
if ( V_128 . V_28 < F_125 ( V_20 ) )
break;
F_120 ( V_20 , & V_128 ) ;
}
}
V_29 = F_52 ( V_22 ) ;
V_22 -> V_29 = V_29 ;
V_22 -> V_68 = 0 ;
F_20 ( & V_22 -> V_23 ) ;
if ( V_29 . V_28 == V_56 ||
! F_60 ( V_29 , 0 ) ) {
V_22 -> V_66 = 0 ;
return;
}
F_21 ( & V_22 -> V_23 ) ;
V_88 = F_66 ( V_22 ) ;
V_22 -> V_129 ++ ;
if ( ++ V_124 < 3 )
goto V_127;
V_22 -> V_130 ++ ;
V_22 -> V_66 = 1 ;
F_20 ( & V_22 -> V_23 ) ;
V_91 = F_12 ( V_88 , V_123 ) ;
if ( V_91 . V_28 > V_22 -> V_131 . V_28 )
V_22 -> V_131 = V_91 ;
if ( V_91 . V_28 > 100 * V_132 )
V_29 = F_126 ( V_88 , 100 * V_132 ) ;
else
V_29 = F_4 ( V_88 , V_91 ) ;
F_60 ( V_29 , 1 ) ;
F_127 ( V_73 L_6 ,
F_23 ( V_91 ) ) ;
}
static void F_128 ( void )
{
struct V_133 * V_134 ;
if ( ! F_57 () )
return;
V_134 = F_62 ( & V_135 ) ;
if ( V_134 && V_134 -> V_136 )
F_124 ( V_134 -> V_136 ) ;
}
void F_129 ( void )
{
unsigned long V_21 ;
F_70 ( V_21 ) ;
F_128 () ;
F_72 ( V_21 ) ;
}
static void F_130 ( struct V_137 * V_138 )
{
F_129 () ;
}
static inline void F_128 ( void ) { }
void F_131 ( void )
{
if ( F_57 () )
return;
if ( F_132 ( ! F_56 () ) )
F_69 () ;
}
void F_133 ( void )
{
struct V_59 * V_62 ;
struct V_3 * V_22 = F_62 ( & V_37 ) ;
struct V_18 * V_4 ;
int V_35 , V_139 = 1 ;
if ( F_57 () )
return;
for ( V_35 = 0 ; V_35 < V_58 ; V_35 ++ ) {
V_4 = & V_22 -> V_12 [ V_35 ] ;
if ( ! F_53 ( & V_4 -> V_61 ) )
continue;
if ( V_139 ) {
F_2 ( V_22 ) ;
V_139 = 0 ;
}
F_21 ( & V_22 -> V_23 ) ;
while ( ( V_62 = F_53 ( & V_4 -> V_61 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_54 ( V_62 , struct V_19 , V_62 ) ;
if ( V_4 -> V_14 . V_28 <=
F_63 ( V_20 ) )
break;
F_120 ( V_20 , & V_4 -> V_14 ) ;
}
F_20 ( & V_22 -> V_23 ) ;
}
}
static enum V_117 F_134 ( struct V_19 * V_20 )
{
struct V_140 * V_141 =
F_54 ( V_20 , struct V_140 , V_20 ) ;
struct V_142 * V_143 = V_141 -> V_143 ;
V_141 -> V_143 = NULL ;
if ( V_143 )
F_135 ( V_143 ) ;
return V_120 ;
}
void F_136 ( struct V_140 * V_144 , struct V_142 * V_143 )
{
V_144 -> V_20 . V_47 = F_134 ;
V_144 -> V_143 = V_143 ;
}
static int T_6 F_137 ( struct V_140 * V_141 , enum V_53 V_54 )
{
F_136 ( V_141 , V_82 ) ;
do {
F_138 ( V_145 ) ;
F_139 ( & V_141 -> V_20 , V_54 ) ;
if ( ! F_140 ( & V_141 -> V_20 ) )
V_141 -> V_143 = NULL ;
if ( F_6 ( V_141 -> V_143 ) )
F_141 () ;
F_29 ( & V_141 -> V_20 ) ;
V_54 = V_112 ;
} while ( V_141 -> V_143 && ! F_142 ( V_82 ) );
F_143 ( V_146 ) ;
return V_141 -> V_143 == NULL ;
}
static int F_144 ( struct V_19 * V_20 , struct V_115 T_7 * V_147 )
{
struct V_115 V_148 ;
T_2 V_109 ;
V_109 = F_112 ( V_20 ) ;
if ( V_109 . V_28 <= 0 )
return 0 ;
V_148 = F_119 ( V_109 ) ;
if ( F_145 ( V_147 , & V_148 , sizeof( * V_147 ) ) )
return - V_149 ;
return 1 ;
}
long T_6 F_146 ( struct V_150 * V_119 )
{
struct V_140 V_141 ;
struct V_115 T_7 * V_147 ;
int V_103 = 0 ;
F_42 ( & V_141 . V_20 , V_119 -> V_151 . V_55 ,
V_112 ) ;
F_147 ( & V_141 . V_20 , V_119 -> V_151 . V_25 ) ;
if ( F_137 ( & V_141 , V_112 ) )
goto V_98;
V_147 = V_119 -> V_151 . V_147 ;
if ( V_147 ) {
V_103 = F_144 ( & V_141 . V_20 , V_147 ) ;
if ( V_103 <= 0 )
goto V_98;
}
V_103 = - V_152 ;
V_98:
F_45 ( & V_141 . V_20 ) ;
return V_103 ;
}
long F_148 ( struct V_115 * V_153 , struct V_115 T_7 * V_147 ,
const enum V_53 V_54 , const T_1 V_55 )
{
struct V_150 * V_119 ;
struct V_140 V_141 ;
int V_103 = 0 ;
unsigned long V_154 ;
V_154 = V_82 -> V_155 ;
if ( F_149 ( V_82 ) || F_150 ( V_82 ) )
V_154 = 0 ;
F_42 ( & V_141 . V_20 , V_55 , V_54 ) ;
F_103 ( & V_141 . V_20 , F_151 ( * V_153 ) , V_154 ) ;
if ( F_137 ( & V_141 , V_54 ) )
goto V_98;
if ( V_54 == V_112 ) {
V_103 = - V_156 ;
goto V_98;
}
if ( V_147 ) {
V_103 = F_144 ( & V_141 . V_20 , V_147 ) ;
if ( V_103 <= 0 )
goto V_98;
}
V_119 = & V_82 -> V_150 ;
V_119 -> V_118 = F_146 ;
V_119 -> V_151 . V_55 = V_141 . V_20 . V_4 -> V_55 ;
V_119 -> V_151 . V_147 = V_147 ;
V_119 -> V_151 . V_25 = F_63 ( & V_141 . V_20 ) ;
V_103 = - V_152 ;
V_98:
F_45 ( & V_141 . V_20 ) ;
return V_103 ;
}
static void F_152 ( int V_33 )
{
struct V_3 * V_22 = & F_17 ( V_37 , V_33 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_22 -> V_12 [ V_57 ] . V_22 = V_22 ;
F_153 ( & V_22 -> V_12 [ V_57 ] . V_61 ) ;
}
V_22 -> V_33 = V_33 ;
F_65 ( V_22 ) ;
}
static void F_154 ( struct V_18 * V_157 ,
struct V_18 * V_24 )
{
struct V_19 * V_20 ;
struct V_59 * V_62 ;
while ( ( V_62 = F_53 ( & V_157 -> V_61 ) ) ) {
V_20 = F_54 ( V_62 , struct V_19 , V_62 ) ;
F_123 ( F_19 ( V_20 ) ) ;
F_50 ( V_20 ) ;
F_97 ( V_20 , V_157 , V_158 , 0 ) ;
V_20 -> V_4 = V_24 ;
F_95 ( V_20 , V_24 ) ;
V_20 -> V_49 &= ~ V_158 ;
}
}
static void F_155 ( int V_159 )
{
struct V_3 * V_157 , * V_24 ;
int V_57 ;
F_123 ( F_156 ( V_159 ) ) ;
F_157 ( V_159 ) ;
F_158 () ;
V_157 = & F_17 ( V_37 , V_159 ) ;
V_24 = F_62 ( & V_37 ) ;
F_21 ( & V_24 -> V_23 ) ;
F_159 ( & V_157 -> V_23 , V_160 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
F_154 ( & V_157 -> V_12 [ V_57 ] ,
& V_24 -> V_12 [ V_57 ] ) ;
}
F_20 ( & V_157 -> V_23 ) ;
F_20 ( & V_24 -> V_23 ) ;
F_128 () ;
F_160 () ;
}
static int F_161 ( struct V_161 * V_162 ,
unsigned long V_163 , void * V_164 )
{
int V_159 = ( long ) V_164 ;
switch ( V_163 ) {
case V_165 :
case V_166 :
F_152 ( V_159 ) ;
break;
#ifdef F_162
case V_167 :
case V_168 :
F_155 ( V_159 ) ;
break;
#endif
default:
break;
}
return V_169 ;
}
void T_5 F_163 ( void )
{
F_161 ( & V_170 , ( unsigned long ) V_165 ,
( void * ) ( long ) F_15 () ) ;
F_164 ( & V_170 ) ;
#ifdef F_11
F_165 ( V_108 , F_130 ) ;
#endif
}
int T_6
F_166 ( T_2 * V_25 , unsigned long V_91 ,
const enum V_53 V_54 , int clock )
{
struct V_140 V_141 ;
if ( V_25 && ! V_25 -> V_28 ) {
F_143 ( V_146 ) ;
return 0 ;
}
if ( ! V_25 ) {
F_167 () ;
return - V_171 ;
}
F_42 ( & V_141 . V_20 , clock , V_54 ) ;
F_103 ( & V_141 . V_20 , * V_25 , V_91 ) ;
F_136 ( & V_141 , V_82 ) ;
F_139 ( & V_141 . V_20 , V_54 ) ;
if ( ! F_140 ( & V_141 . V_20 ) )
V_141 . V_143 = NULL ;
if ( F_6 ( V_141 . V_143 ) )
F_167 () ;
F_29 ( & V_141 . V_20 ) ;
F_45 ( & V_141 . V_20 ) ;
F_143 ( V_146 ) ;
return ! V_141 . V_143 ? 0 : - V_171 ;
}
int T_6 F_168 ( T_2 * V_25 , unsigned long V_91 ,
const enum V_53 V_54 )
{
return F_166 ( V_25 , V_91 , V_54 ,
V_113 ) ;
}
int T_6 F_169 ( T_2 * V_25 ,
const enum V_53 V_54 )
{
return F_168 ( V_25 , 0 , V_54 ) ;
}
