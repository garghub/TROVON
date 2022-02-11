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
T_3 F_22 ( const T_2 V_38 , T_4 div )
{
T_3 V_39 ;
int V_40 = 0 ;
V_39 = F_23 ( V_38 ) ;
while ( div >> 32 ) {
V_40 ++ ;
div >>= 1 ;
}
V_39 >>= V_40 ;
F_24 ( V_39 , ( unsigned long ) div ) ;
return V_39 ;
}
T_2 F_25 ( const T_2 V_41 , const T_2 V_42 )
{
T_2 V_43 = F_4 ( V_41 , V_42 ) ;
if ( V_43 . V_28 < 0 || V_43 . V_28 < V_41 . V_28 || V_43 . V_28 < V_42 . V_28 )
V_43 = F_26 ( V_44 , 0 ) ;
return V_43 ;
}
static void * F_27 ( void * V_45 )
{
return ( (struct V_19 * ) V_45 ) -> V_46 ;
}
static int F_28 ( void * V_45 , enum V_47 V_48 )
{
struct V_19 * V_20 = V_45 ;
switch ( V_48 ) {
case V_49 :
F_29 ( V_20 ) ;
F_30 ( V_20 , & V_50 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_31 ( void * V_45 , enum V_47 V_48 )
{
switch ( V_48 ) {
case V_51 :
F_32 ( 1 ) ;
return 0 ;
case V_49 :
F_33 ( 1 ) ;
default:
return 0 ;
}
}
static int F_34 ( void * V_45 , enum V_47 V_48 )
{
struct V_19 * V_20 = V_45 ;
switch ( V_48 ) {
case V_49 :
F_29 ( V_20 ) ;
F_35 ( V_20 , & V_50 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_36 ( struct V_19 * V_20 )
{
F_30 ( V_20 , & V_50 ) ;
}
static inline void F_37 ( struct V_19 * V_20 )
{
F_38 ( V_20 , & V_50 ) ;
}
static inline void F_39 ( struct V_19 * V_20 )
{
F_40 ( V_20 , & V_50 ) ;
}
static inline void F_41 ( struct V_19 * V_20 )
{
F_35 ( V_20 , & V_50 ) ;
}
void F_42 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_52 V_53 )
{
F_43 ( V_20 , & V_50 ) ;
F_44 ( V_20 , V_1 , V_53 ) ;
}
void F_45 ( struct V_19 * V_20 )
{
F_35 ( V_20 , & V_50 ) ;
}
static inline void F_36 ( struct V_19 * V_20 ) { }
static inline void F_37 ( struct V_19 * V_20 ) { }
static inline void F_39 ( struct V_19 * V_20 ) { }
static inline void
F_46 ( struct V_19 * V_20 , T_1 V_54 ,
enum V_52 V_53 )
{
F_36 ( V_20 ) ;
F_47 ( V_20 , V_54 , V_53 ) ;
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
T_2 V_25 , V_29 = { . V_28 = V_55 } ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ , V_4 ++ ) {
struct V_58 * V_59 ;
struct V_19 * V_20 ;
V_59 = F_53 ( & V_4 -> V_60 ) ;
if ( ! V_59 )
continue;
V_20 = F_54 ( V_59 , struct V_19 , V_61 ) ;
V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
if ( V_25 . V_28 < V_29 . V_28 )
V_29 = V_25 ;
}
if ( V_29 . V_28 < 0 )
V_29 . V_28 = 0 ;
return V_29 ;
}
static int T_5 F_55 ( char * V_62 )
{
if ( ! strcmp ( V_62 , L_1 ) )
V_63 = 0 ;
else if ( ! strcmp ( V_62 , L_2 ) )
V_63 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_56 ( void )
{
return V_63 ;
}
static inline int F_57 ( void )
{
return F_58 ( V_37 . V_26 ) ;
}
static void
F_59 ( struct V_3 * V_22 , int V_64 )
{
T_2 V_29 = F_52 ( V_22 ) ;
if ( V_64 && V_29 . V_28 == V_22 -> V_29 . V_28 )
return;
V_22 -> V_29 . V_28 = V_29 . V_28 ;
if ( V_22 -> V_65 )
return;
if ( V_22 -> V_29 . V_28 != V_55 )
F_60 ( V_22 -> V_29 , 1 ) ;
}
static int F_61 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
int V_43 ;
F_32 ( F_63 ( V_20 ) < 0 ) ;
if ( F_19 ( V_20 ) )
return 0 ;
if ( V_25 . V_28 < 0 )
return - V_66 ;
if ( V_25 . V_28 >= V_22 -> V_29 . V_28 )
return 0 ;
if ( V_22 -> V_67 )
return 0 ;
if ( V_22 -> V_65 )
return 0 ;
V_43 = F_60 ( V_25 , 0 ) ;
if ( ! F_64 ( V_43 ) )
V_22 -> V_29 = V_25 ;
return V_43 ;
}
static inline void F_65 ( struct V_3 * V_4 )
{
V_4 -> V_29 . V_28 = V_55 ;
V_4 -> V_26 = 0 ;
}
static inline T_2 F_66 ( struct V_3 * V_4 )
{
T_2 * V_68 = & V_4 -> V_12 [ V_13 ] . V_27 ;
T_2 * V_69 = & V_4 -> V_12 [ V_16 ] . V_27 ;
T_2 * V_70 = & V_4 -> V_12 [ V_17 ] . V_27 ;
return F_67 ( V_68 , V_69 , V_70 ) ;
}
static void F_68 ( void * V_71 )
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
int V_56 , V_33 = F_15 () ;
struct V_3 * V_4 = & F_17 ( V_37 , V_33 ) ;
unsigned long V_21 ;
if ( V_4 -> V_26 )
return 1 ;
F_70 ( V_21 ) ;
if ( F_71 () ) {
F_72 ( V_21 ) ;
F_73 ( V_72 L_3
L_4 , V_33 ) ;
return 0 ;
}
V_4 -> V_26 = 1 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ )
V_4 -> V_12 [ V_56 ] . V_73 = V_74 ;
F_74 () ;
F_68 ( NULL ) ;
F_72 ( V_21 ) ;
return 1 ;
}
static void F_75 ( struct V_75 * V_76 )
{
F_76 () ;
}
void F_77 ( void )
{
F_78 ( & V_77 ) ;
}
static inline int F_57 ( void ) { return 0 ; }
static inline int F_56 ( void ) { return 0 ; }
static inline int F_69 ( void ) { return 0 ; }
static inline void
F_59 ( struct V_3 * V_4 , int V_64 ) { }
static inline int F_61 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
return 0 ;
}
static inline void F_65 ( struct V_3 * V_4 ) { }
static inline void F_68 ( void * V_71 ) { }
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
V_78 L_5 ) ;
F_68 ( NULL ) ;
F_77 () ;
}
static inline void F_84 ( struct V_19 * V_20 )
{
#ifdef F_85
if ( V_20 -> V_79 )
return;
V_20 -> V_79 = F_86 ( 0 ) ;
memcpy ( V_20 -> V_80 , V_81 -> V_82 , V_83 ) ;
V_20 -> V_84 = V_81 -> V_85 ;
#endif
}
static inline void F_87 ( struct V_19 * V_20 )
{
#ifdef F_85
V_20 -> V_79 = NULL ;
#endif
}
static inline void F_88 ( struct V_19 * V_20 )
{
#ifdef F_85
if ( F_6 ( ! V_86 ) )
return;
F_89 ( V_20 , V_20 -> V_84 , V_20 -> V_79 ,
V_20 -> V_46 , V_20 -> V_80 , 0 ) ;
#endif
}
static inline
void F_90 ( const struct V_19 * V_20 , unsigned long * V_21 )
{
F_8 ( & V_20 -> V_4 -> V_22 -> V_23 , * V_21 ) ;
}
T_3 F_91 ( struct V_19 * V_20 , T_2 V_87 , T_2 V_88 )
{
T_3 V_89 = 1 ;
T_2 V_90 ;
V_90 = F_12 ( V_87 , F_13 ( V_20 ) ) ;
if ( V_90 . V_28 < 0 )
return 0 ;
if ( V_88 . V_28 < V_20 -> V_4 -> V_73 . V_28 )
V_88 . V_28 = V_20 -> V_4 -> V_73 . V_28 ;
if ( F_18 ( V_90 . V_28 >= V_88 . V_28 ) ) {
T_4 V_91 = F_23 ( V_88 ) ;
V_89 = F_92 ( V_90 , V_91 ) ;
F_93 ( V_20 , V_91 * V_89 ) ;
if ( F_63 ( V_20 ) > V_87 . V_28 )
return V_89 ;
V_89 ++ ;
}
F_94 ( V_20 , V_88 ) ;
return V_89 ;
}
static int F_95 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
F_48 ( V_20 ) ;
F_96 ( & V_4 -> V_60 , & V_20 -> V_61 ) ;
V_4 -> V_22 -> V_92 |= 1 << V_4 -> V_35 ;
V_20 -> V_48 |= V_93 ;
return ( & V_20 -> V_61 == V_4 -> V_60 . V_59 ) ;
}
static void F_97 ( struct V_19 * V_20 ,
struct V_18 * V_4 ,
unsigned long V_94 , int V_95 )
{
struct V_58 * V_96 ;
if ( ! ( V_20 -> V_48 & V_93 ) )
goto V_97;
V_96 = F_53 ( & V_4 -> V_60 ) ;
F_98 ( & V_4 -> V_60 , & V_20 -> V_61 ) ;
if ( & V_20 -> V_61 == V_96 ) {
#ifdef F_11
if ( V_95 && F_57 () ) {
T_2 V_25 ;
V_25 = F_12 ( F_13 ( V_20 ) ,
V_4 -> V_27 ) ;
if ( V_4 -> V_22 -> V_29 . V_28 == V_25 . V_28 )
F_59 ( V_4 -> V_22 , 1 ) ;
}
#endif
}
if ( ! F_53 ( & V_4 -> V_60 ) )
V_4 -> V_22 -> V_92 &= ~ ( 1 << V_4 -> V_35 ) ;
V_97:
V_20 -> V_48 = V_94 ;
}
static inline int
F_99 ( struct V_19 * V_20 , struct V_18 * V_4 )
{
if ( F_100 ( V_20 ) ) {
unsigned long V_48 ;
int V_95 ;
F_50 ( V_20 ) ;
F_87 ( V_20 ) ;
V_95 = V_4 -> V_22 == F_62 ( & V_37 ) ;
V_48 = V_20 -> V_48 & V_98 ;
F_97 ( V_20 , V_4 , V_48 , V_95 ) ;
return 1 ;
}
return 0 ;
}
int F_101 ( struct V_19 * V_20 , T_2 V_99 ,
unsigned long V_100 , const enum V_52 V_53 ,
int V_101 )
{
struct V_18 * V_4 , * V_24 ;
unsigned long V_21 ;
int V_102 , V_103 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
V_102 = F_99 ( V_20 , V_4 ) ;
if ( V_53 & V_104 ) {
V_99 = F_25 ( V_99 , V_4 -> V_105 () ) ;
#ifdef F_102
V_99 = F_25 ( V_99 , V_4 -> V_73 ) ;
#endif
}
F_103 ( V_20 , V_99 , V_100 ) ;
V_24 = F_14 ( V_20 , V_4 , V_53 & V_106 ) ;
F_84 ( V_20 ) ;
V_103 = F_95 ( V_20 , V_24 ) ;
if ( ! V_103 ) {
F_90 ( V_20 , & V_21 ) ;
return V_102 ;
}
if ( ! F_104 ( V_20 ) ) {
F_105 ( V_24 -> V_22 -> V_33 ) ;
} else if ( V_24 -> V_22 == F_62 ( & V_37 ) &&
F_61 ( V_20 , V_24 ) ) {
if ( V_101 ) {
F_20 ( & V_24 -> V_22 -> V_23 ) ;
F_106 ( V_107 ) ;
F_72 ( V_21 ) ;
return V_102 ;
} else {
F_107 ( V_107 ) ;
}
}
F_90 ( V_20 , & V_21 ) ;
return V_102 ;
}
int F_108 ( struct V_19 * V_20 , T_2 V_99 ,
unsigned long V_100 , const enum V_52 V_53 )
{
return F_101 ( V_20 , V_99 , V_100 , V_53 , 1 ) ;
}
int
F_109 ( struct V_19 * V_20 , T_2 V_99 , const enum V_52 V_53 )
{
return F_101 ( V_20 , V_99 , 0 , V_53 , 1 ) ;
}
int F_110 ( struct V_19 * V_20 )
{
struct V_18 * V_4 ;
unsigned long V_21 ;
int V_102 = - 1 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
if ( ! F_19 ( V_20 ) )
V_102 = F_99 ( V_20 , V_4 ) ;
F_90 ( V_20 , & V_21 ) ;
return V_102 ;
}
int F_29 ( struct V_19 * V_20 )
{
for (; ; ) {
int V_102 = F_110 ( V_20 ) ;
if ( V_102 >= 0 )
return V_102 ;
F_9 () ;
}
}
T_2 F_111 ( const struct V_19 * V_20 )
{
unsigned long V_21 ;
T_2 V_108 ;
F_5 ( V_20 , & V_21 ) ;
V_108 = F_112 ( V_20 ) ;
F_90 ( V_20 , & V_21 ) ;
return V_108 ;
}
T_2 F_113 ( void )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_109 = { . V_28 = V_55 } ;
unsigned long V_21 ;
F_7 ( & V_22 -> V_23 , V_21 ) ;
if ( ! F_57 () )
V_109 = F_12 ( F_52 ( V_22 ) ,
F_114 () ) ;
F_8 ( & V_22 -> V_23 , V_21 ) ;
if ( V_109 . V_28 < 0 )
V_109 . V_28 = 0 ;
return V_109 ;
}
static void F_44 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_52 V_53 )
{
struct V_3 * V_22 ;
int V_4 ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_22 = F_115 ( & V_37 ) ;
if ( V_1 == V_110 && V_53 != V_111 )
V_1 = V_112 ;
V_4 = F_1 ( V_1 ) ;
V_20 -> V_4 = & V_22 -> V_12 [ V_4 ] ;
F_116 ( & V_20 -> V_61 ) ;
#ifdef F_85
V_20 -> V_79 = NULL ;
V_20 -> V_84 = - 1 ;
memset ( V_20 -> V_80 , 0 , V_83 ) ;
#endif
}
void F_117 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_52 V_53 )
{
F_46 ( V_20 , V_1 , V_53 ) ;
F_44 ( V_20 , V_1 , V_53 ) ;
}
int F_118 ( const T_1 V_113 , struct V_114 * V_115 )
{
struct V_3 * V_22 ;
int V_4 = F_1 ( V_113 ) ;
V_22 = F_115 ( & V_37 ) ;
* V_115 = F_119 ( V_22 -> V_12 [ V_4 ] . V_73 ) ;
return 0 ;
}
static void F_120 ( struct V_19 * V_20 , T_2 * V_87 )
{
struct V_18 * V_4 = V_20 -> V_4 ;
struct V_3 * V_22 = V_4 -> V_22 ;
enum V_116 ( * V_117 ) ( struct V_19 * ) ;
int V_118 ;
F_33 ( ! F_83 () ) ;
F_50 ( V_20 ) ;
F_97 ( V_20 , V_4 , V_98 , 0 ) ;
F_88 ( V_20 ) ;
V_117 = V_20 -> V_46 ;
F_20 ( & V_22 -> V_23 ) ;
F_121 ( V_20 , V_87 ) ;
V_118 = V_117 ( V_20 ) ;
F_122 ( V_20 ) ;
F_21 ( & V_22 -> V_23 ) ;
if ( V_118 != V_119 ) {
F_123 ( V_20 -> V_48 != V_98 ) ;
F_95 ( V_20 , V_4 ) ;
}
F_32 ( ! ( V_20 -> V_48 & V_98 ) ) ;
V_20 -> V_48 &= ~ V_98 ;
}
void F_124 ( struct V_120 * V_121 )
{
struct V_3 * V_22 = F_62 ( & V_37 ) ;
T_2 V_29 , V_87 , V_122 , V_90 ;
int V_56 , V_123 = 0 ;
F_123 ( ! V_22 -> V_26 ) ;
V_22 -> V_124 ++ ;
V_121 -> V_125 . V_28 = V_55 ;
F_21 ( & V_22 -> V_23 ) ;
V_122 = V_87 = F_66 ( V_22 ) ;
V_126:
V_22 -> V_67 = 1 ;
V_22 -> V_29 . V_28 = V_55 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
struct V_18 * V_4 ;
struct V_58 * V_61 ;
T_2 V_127 ;
if ( ! ( V_22 -> V_92 & ( 1 << V_56 ) ) )
continue;
V_4 = V_22 -> V_12 + V_56 ;
V_127 = F_4 ( V_87 , V_4 -> V_27 ) ;
while ( ( V_61 = F_53 ( & V_4 -> V_60 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_54 ( V_61 , struct V_19 , V_61 ) ;
if ( V_127 . V_28 < F_125 ( V_20 ) )
break;
F_120 ( V_20 , & V_127 ) ;
}
}
V_29 = F_52 ( V_22 ) ;
V_22 -> V_29 = V_29 ;
V_22 -> V_67 = 0 ;
F_20 ( & V_22 -> V_23 ) ;
if ( V_29 . V_28 == V_55 ||
! F_60 ( V_29 , 0 ) ) {
V_22 -> V_65 = 0 ;
return;
}
F_21 ( & V_22 -> V_23 ) ;
V_87 = F_66 ( V_22 ) ;
V_22 -> V_128 ++ ;
if ( ++ V_123 < 3 )
goto V_126;
V_22 -> V_129 ++ ;
V_22 -> V_65 = 1 ;
F_20 ( & V_22 -> V_23 ) ;
V_90 = F_12 ( V_87 , V_122 ) ;
if ( V_90 . V_28 > V_22 -> V_130 . V_28 )
V_22 -> V_130 = V_90 ;
if ( V_90 . V_28 > 100 * V_131 )
V_29 = F_126 ( V_87 , 100 * V_131 ) ;
else
V_29 = F_4 ( V_87 , V_90 ) ;
F_60 ( V_29 , 1 ) ;
F_127 ( V_72 L_6 ,
F_23 ( V_90 ) ) ;
}
static void F_128 ( void )
{
struct V_132 * V_133 ;
if ( ! F_57 () )
return;
V_133 = F_62 ( & V_134 ) ;
if ( V_133 && V_133 -> V_135 )
F_124 ( V_133 -> V_135 ) ;
}
void F_129 ( void )
{
unsigned long V_21 ;
F_70 ( V_21 ) ;
F_128 () ;
F_72 ( V_21 ) ;
}
static void F_130 ( struct V_136 * V_137 )
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
struct V_58 * V_61 ;
struct V_3 * V_22 = F_62 ( & V_37 ) ;
struct V_18 * V_4 ;
int V_35 , V_138 = 1 ;
if ( F_57 () )
return;
for ( V_35 = 0 ; V_35 < V_57 ; V_35 ++ ) {
V_4 = & V_22 -> V_12 [ V_35 ] ;
if ( ! F_53 ( & V_4 -> V_60 ) )
continue;
if ( V_138 ) {
F_2 ( V_22 ) ;
V_138 = 0 ;
}
F_21 ( & V_22 -> V_23 ) ;
while ( ( V_61 = F_53 ( & V_4 -> V_60 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_54 ( V_61 , struct V_19 , V_61 ) ;
if ( V_4 -> V_14 . V_28 <=
F_63 ( V_20 ) )
break;
F_120 ( V_20 , & V_4 -> V_14 ) ;
}
F_20 ( & V_22 -> V_23 ) ;
}
}
static enum V_116 F_134 ( struct V_19 * V_20 )
{
struct V_139 * V_140 =
F_54 ( V_20 , struct V_139 , V_20 ) ;
struct V_141 * V_142 = V_140 -> V_142 ;
V_140 -> V_142 = NULL ;
if ( V_142 )
F_135 ( V_142 ) ;
return V_119 ;
}
void F_136 ( struct V_139 * V_143 , struct V_141 * V_142 )
{
V_143 -> V_20 . V_46 = F_134 ;
V_143 -> V_142 = V_142 ;
}
static int T_6 F_137 ( struct V_139 * V_140 , enum V_52 V_53 )
{
F_136 ( V_140 , V_81 ) ;
do {
F_138 ( V_144 ) ;
F_139 ( & V_140 -> V_20 , V_53 ) ;
if ( ! F_140 ( & V_140 -> V_20 ) )
V_140 -> V_142 = NULL ;
if ( F_6 ( V_140 -> V_142 ) )
F_141 () ;
F_29 ( & V_140 -> V_20 ) ;
V_53 = V_111 ;
} while ( V_140 -> V_142 && ! F_142 ( V_81 ) );
F_143 ( V_145 ) ;
return V_140 -> V_142 == NULL ;
}
static int F_144 ( struct V_19 * V_20 , struct V_114 T_7 * V_146 )
{
struct V_114 V_147 ;
T_2 V_108 ;
V_108 = F_112 ( V_20 ) ;
if ( V_108 . V_28 <= 0 )
return 0 ;
V_147 = F_119 ( V_108 ) ;
if ( F_145 ( V_146 , & V_147 , sizeof( * V_146 ) ) )
return - V_148 ;
return 1 ;
}
long T_6 F_146 ( struct V_149 * V_118 )
{
struct V_139 V_140 ;
struct V_114 T_7 * V_146 ;
int V_102 = 0 ;
F_42 ( & V_140 . V_20 , V_118 -> V_150 . V_54 ,
V_111 ) ;
F_147 ( & V_140 . V_20 , V_118 -> V_150 . V_25 ) ;
if ( F_137 ( & V_140 , V_111 ) )
goto V_97;
V_146 = V_118 -> V_150 . V_146 ;
if ( V_146 ) {
V_102 = F_144 ( & V_140 . V_20 , V_146 ) ;
if ( V_102 <= 0 )
goto V_97;
}
V_102 = - V_151 ;
V_97:
F_45 ( & V_140 . V_20 ) ;
return V_102 ;
}
long F_148 ( struct V_114 * V_152 , struct V_114 T_7 * V_146 ,
const enum V_52 V_53 , const T_1 V_54 )
{
struct V_149 * V_118 ;
struct V_139 V_140 ;
int V_102 = 0 ;
unsigned long V_153 ;
V_153 = V_81 -> V_154 ;
if ( F_149 ( V_81 ) || F_150 ( V_81 ) )
V_153 = 0 ;
F_42 ( & V_140 . V_20 , V_54 , V_53 ) ;
F_103 ( & V_140 . V_20 , F_151 ( * V_152 ) , V_153 ) ;
if ( F_137 ( & V_140 , V_53 ) )
goto V_97;
if ( V_53 == V_111 ) {
V_102 = - V_155 ;
goto V_97;
}
if ( V_146 ) {
V_102 = F_144 ( & V_140 . V_20 , V_146 ) ;
if ( V_102 <= 0 )
goto V_97;
}
V_118 = & V_81 -> V_149 ;
V_118 -> V_117 = F_146 ;
V_118 -> V_150 . V_54 = V_140 . V_20 . V_4 -> V_54 ;
V_118 -> V_150 . V_146 = V_146 ;
V_118 -> V_150 . V_25 = F_63 ( & V_140 . V_20 ) ;
V_102 = - V_151 ;
V_97:
F_45 ( & V_140 . V_20 ) ;
return V_102 ;
}
static void F_152 ( int V_33 )
{
struct V_3 * V_22 = & F_17 ( V_37 , V_33 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_22 -> V_12 [ V_56 ] . V_22 = V_22 ;
F_153 ( & V_22 -> V_12 [ V_56 ] . V_60 ) ;
}
V_22 -> V_33 = V_33 ;
F_65 ( V_22 ) ;
}
static void F_154 ( struct V_18 * V_156 ,
struct V_18 * V_24 )
{
struct V_19 * V_20 ;
struct V_58 * V_61 ;
while ( ( V_61 = F_53 ( & V_156 -> V_60 ) ) ) {
V_20 = F_54 ( V_61 , struct V_19 , V_61 ) ;
F_123 ( F_19 ( V_20 ) ) ;
F_50 ( V_20 ) ;
F_97 ( V_20 , V_156 , V_157 , 0 ) ;
V_20 -> V_4 = V_24 ;
F_95 ( V_20 , V_24 ) ;
V_20 -> V_48 &= ~ V_157 ;
}
}
static void F_155 ( int V_158 )
{
struct V_3 * V_156 , * V_24 ;
int V_56 ;
F_123 ( F_156 ( V_158 ) ) ;
F_157 ( V_158 ) ;
F_158 () ;
V_156 = & F_17 ( V_37 , V_158 ) ;
V_24 = F_62 ( & V_37 ) ;
F_21 ( & V_24 -> V_23 ) ;
F_159 ( & V_156 -> V_23 , V_159 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
F_154 ( & V_156 -> V_12 [ V_56 ] ,
& V_24 -> V_12 [ V_56 ] ) ;
}
F_20 ( & V_156 -> V_23 ) ;
F_20 ( & V_24 -> V_23 ) ;
F_128 () ;
F_160 () ;
}
static int F_161 ( struct V_160 * V_161 ,
unsigned long V_162 , void * V_163 )
{
int V_158 = ( long ) V_163 ;
switch ( V_162 ) {
case V_164 :
case V_165 :
F_152 ( V_158 ) ;
break;
#ifdef F_162
case V_166 :
case V_167 :
F_163 ( V_168 , & V_158 ) ;
break;
case V_169 :
case V_170 :
{
F_163 ( V_171 , & V_158 ) ;
F_155 ( V_158 ) ;
break;
}
#endif
default:
break;
}
return V_172 ;
}
void T_5 F_164 ( void )
{
F_161 ( & V_173 , ( unsigned long ) V_164 ,
( void * ) ( long ) F_15 () ) ;
F_165 ( & V_173 ) ;
#ifdef F_11
F_166 ( V_107 , F_130 ) ;
#endif
}
int T_6
F_167 ( T_2 * V_25 , unsigned long V_90 ,
const enum V_52 V_53 , int clock )
{
struct V_139 V_140 ;
if ( V_25 && ! V_25 -> V_28 ) {
F_143 ( V_145 ) ;
return 0 ;
}
if ( ! V_25 ) {
F_168 () ;
return - V_174 ;
}
F_42 ( & V_140 . V_20 , clock , V_53 ) ;
F_103 ( & V_140 . V_20 , * V_25 , V_90 ) ;
F_136 ( & V_140 , V_81 ) ;
F_139 ( & V_140 . V_20 , V_53 ) ;
if ( ! F_140 ( & V_140 . V_20 ) )
V_140 . V_142 = NULL ;
if ( F_6 ( V_140 . V_142 ) )
F_168 () ;
F_29 ( & V_140 . V_20 ) ;
F_45 ( & V_140 . V_20 ) ;
F_143 ( V_145 ) ;
return ! V_140 . V_142 ? 0 : - V_174 ;
}
int T_6 F_169 ( T_2 * V_25 , unsigned long V_90 ,
const enum V_52 V_53 )
{
return F_167 ( V_25 , V_90 , V_53 ,
V_112 ) ;
}
int T_6 F_170 ( T_2 * V_25 ,
const enum V_52 V_53 )
{
return F_169 ( V_25 , 0 , V_53 ) ;
}
