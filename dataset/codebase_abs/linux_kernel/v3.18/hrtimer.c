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
V_8 = F_4 ( V_5 , V_11 ) ;
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
static int T_5 F_52 ( char * V_55 )
{
if ( ! strcmp ( V_55 , L_1 ) )
V_56 = 0 ;
else if ( ! strcmp ( V_55 , L_2 ) )
V_56 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_53 ( void )
{
return V_56 ;
}
static inline int F_54 ( void )
{
return F_55 ( V_37 . V_26 ) ;
}
static void
F_56 ( struct V_3 * V_22 , int V_57 )
{
int V_58 ;
struct V_18 * V_4 = V_22 -> V_12 ;
T_2 V_25 , V_29 ;
V_29 . V_28 = V_59 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ , V_4 ++ ) {
struct V_19 * V_20 ;
struct V_61 * V_62 ;
V_62 = F_57 ( & V_4 -> V_63 ) ;
if ( ! V_62 )
continue;
V_20 = F_58 ( V_62 , struct V_19 , V_64 ) ;
V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
if ( V_25 . V_28 < 0 )
V_25 . V_28 = 0 ;
if ( V_25 . V_28 < V_29 . V_28 )
V_29 = V_25 ;
}
if ( V_57 && V_29 . V_28 == V_22 -> V_29 . V_28 )
return;
V_22 -> V_29 . V_28 = V_29 . V_28 ;
if ( V_22 -> V_65 )
return;
if ( V_22 -> V_29 . V_28 != V_59 )
F_59 ( V_22 -> V_29 , 1 ) ;
}
static int F_60 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
struct V_3 * V_22 = F_61 ( & V_37 ) ;
T_2 V_25 = F_12 ( F_13 ( V_20 ) , V_4 -> V_27 ) ;
int V_43 ;
F_32 ( F_62 ( V_20 ) < 0 ) ;
if ( F_19 ( V_20 ) )
return 0 ;
if ( V_25 . V_28 < 0 )
return - V_66 ;
if ( V_25 . V_28 >= V_22 -> V_29 . V_28 )
return 0 ;
if ( V_22 -> V_65 )
return 0 ;
V_43 = F_59 ( V_25 , 0 ) ;
if ( ! F_63 ( V_43 ) )
V_22 -> V_29 = V_25 ;
return V_43 ;
}
static inline void F_64 ( struct V_3 * V_4 )
{
V_4 -> V_29 . V_28 = V_59 ;
V_4 -> V_26 = 0 ;
}
static inline T_2 F_65 ( struct V_3 * V_4 )
{
T_2 * V_67 = & V_4 -> V_12 [ V_13 ] . V_27 ;
T_2 * V_68 = & V_4 -> V_12 [ V_16 ] . V_27 ;
T_2 * V_69 = & V_4 -> V_12 [ V_17 ] . V_27 ;
return F_66 ( V_67 , V_68 , V_69 ) ;
}
static void F_67 ( void * V_70 )
{
struct V_3 * V_4 = F_61 ( & V_37 ) ;
if ( ! F_54 () )
return;
F_21 ( & V_4 -> V_23 ) ;
F_65 ( V_4 ) ;
F_56 ( V_4 , 0 ) ;
F_20 ( & V_4 -> V_23 ) ;
}
static int F_68 ( void )
{
int V_58 , V_33 = F_15 () ;
struct V_3 * V_4 = & F_17 ( V_37 , V_33 ) ;
unsigned long V_21 ;
if ( V_4 -> V_26 )
return 1 ;
F_69 ( V_21 ) ;
if ( F_70 () ) {
F_71 ( V_21 ) ;
F_72 ( V_71 L_3
L_4 , V_33 ) ;
return 0 ;
}
V_4 -> V_26 = 1 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ )
V_4 -> V_12 [ V_58 ] . V_72 = V_73 ;
F_73 () ;
F_67 ( NULL ) ;
F_71 ( V_21 ) ;
return 1 ;
}
static void F_74 ( struct V_74 * V_75 )
{
F_75 () ;
}
void F_76 ( void )
{
F_77 ( & V_76 ) ;
}
static inline int F_54 ( void ) { return 0 ; }
static inline int F_53 ( void ) { return 0 ; }
static inline int F_68 ( void ) { return 0 ; }
static inline void
F_56 ( struct V_3 * V_4 , int V_57 ) { }
static inline int F_60 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
return 0 ;
}
static inline void F_64 ( struct V_3 * V_4 ) { }
static inline void F_67 ( void * V_70 ) { }
void F_75 ( void )
{
#ifdef F_11
F_78 ( F_67 , NULL , 1 ) ;
#endif
F_79 () ;
}
void F_80 ( void )
{
F_81 ( ! F_82 () ,
V_77 L_5 ) ;
F_67 ( NULL ) ;
F_76 () ;
}
static inline void F_83 ( struct V_19 * V_20 )
{
#ifdef F_84
if ( V_20 -> V_78 )
return;
V_20 -> V_78 = F_85 ( 0 ) ;
memcpy ( V_20 -> V_79 , V_80 -> V_81 , V_82 ) ;
V_20 -> V_83 = V_80 -> V_84 ;
#endif
}
static inline void F_86 ( struct V_19 * V_20 )
{
#ifdef F_84
V_20 -> V_78 = NULL ;
#endif
}
static inline void F_87 ( struct V_19 * V_20 )
{
#ifdef F_84
if ( F_6 ( ! V_85 ) )
return;
F_88 ( V_20 , V_20 -> V_83 , V_20 -> V_78 ,
V_20 -> V_46 , V_20 -> V_79 , 0 ) ;
#endif
}
static inline
void F_89 ( const struct V_19 * V_20 , unsigned long * V_21 )
{
F_8 ( & V_20 -> V_4 -> V_22 -> V_23 , * V_21 ) ;
}
T_3 F_90 ( struct V_19 * V_20 , T_2 V_86 , T_2 V_87 )
{
T_3 V_88 = 1 ;
T_2 V_89 ;
V_89 = F_12 ( V_86 , F_13 ( V_20 ) ) ;
if ( V_89 . V_28 < 0 )
return 0 ;
if ( V_87 . V_28 < V_20 -> V_4 -> V_72 . V_28 )
V_87 . V_28 = V_20 -> V_4 -> V_72 . V_28 ;
if ( F_18 ( V_89 . V_28 >= V_87 . V_28 ) ) {
T_4 V_90 = F_23 ( V_87 ) ;
V_88 = F_22 ( V_89 , V_90 ) ;
F_91 ( V_20 , V_90 * V_88 ) ;
if ( F_62 ( V_20 ) > V_86 . V_28 )
return V_88 ;
V_88 ++ ;
}
F_92 ( V_20 , V_87 ) ;
return V_88 ;
}
static int F_93 ( struct V_19 * V_20 ,
struct V_18 * V_4 )
{
F_48 ( V_20 ) ;
F_94 ( & V_4 -> V_63 , & V_20 -> V_64 ) ;
V_4 -> V_22 -> V_91 |= 1 << V_4 -> V_35 ;
V_20 -> V_48 |= V_92 ;
return ( & V_20 -> V_64 == V_4 -> V_63 . V_62 ) ;
}
static void F_95 ( struct V_19 * V_20 ,
struct V_18 * V_4 ,
unsigned long V_93 , int V_94 )
{
struct V_61 * V_95 ;
if ( ! ( V_20 -> V_48 & V_92 ) )
goto V_96;
V_95 = F_57 ( & V_4 -> V_63 ) ;
F_96 ( & V_4 -> V_63 , & V_20 -> V_64 ) ;
if ( & V_20 -> V_64 == V_95 ) {
#ifdef F_11
if ( V_94 && F_54 () ) {
T_2 V_25 ;
V_25 = F_12 ( F_13 ( V_20 ) ,
V_4 -> V_27 ) ;
if ( V_4 -> V_22 -> V_29 . V_28 == V_25 . V_28 )
F_56 ( V_4 -> V_22 , 1 ) ;
}
#endif
}
if ( ! F_57 ( & V_4 -> V_63 ) )
V_4 -> V_22 -> V_91 &= ~ ( 1 << V_4 -> V_35 ) ;
V_96:
V_20 -> V_48 = V_93 ;
}
static inline int
F_97 ( struct V_19 * V_20 , struct V_18 * V_4 )
{
if ( F_98 ( V_20 ) ) {
unsigned long V_48 ;
int V_94 ;
F_50 ( V_20 ) ;
F_86 ( V_20 ) ;
V_94 = V_4 -> V_22 == F_61 ( & V_37 ) ;
V_48 = V_20 -> V_48 & V_97 ;
F_95 ( V_20 , V_4 , V_48 , V_94 ) ;
return 1 ;
}
return 0 ;
}
int F_99 ( struct V_19 * V_20 , T_2 V_98 ,
unsigned long V_99 , const enum V_52 V_53 ,
int V_100 )
{
struct V_18 * V_4 , * V_24 ;
unsigned long V_21 ;
int V_101 , V_102 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
V_101 = F_97 ( V_20 , V_4 ) ;
if ( V_53 & V_103 ) {
V_98 = F_25 ( V_98 , V_4 -> V_104 () ) ;
#ifdef F_100
V_98 = F_25 ( V_98 , V_4 -> V_72 ) ;
#endif
}
F_101 ( V_20 , V_98 , V_99 ) ;
V_24 = F_14 ( V_20 , V_4 , V_53 & V_105 ) ;
F_83 ( V_20 ) ;
V_102 = F_93 ( V_20 , V_24 ) ;
if ( ! V_102 ) {
F_89 ( V_20 , & V_21 ) ;
return V_101 ;
}
if ( ! F_102 ( V_20 ) ) {
F_103 ( V_24 -> V_22 -> V_33 ) ;
} else if ( V_24 -> V_22 == F_61 ( & V_37 ) &&
F_60 ( V_20 , V_24 ) ) {
if ( V_100 ) {
F_20 ( & V_24 -> V_22 -> V_23 ) ;
F_104 ( V_106 ) ;
F_71 ( V_21 ) ;
return V_101 ;
} else {
F_105 ( V_106 ) ;
}
}
F_89 ( V_20 , & V_21 ) ;
return V_101 ;
}
int F_106 ( struct V_19 * V_20 , T_2 V_98 ,
unsigned long V_99 , const enum V_52 V_53 )
{
return F_99 ( V_20 , V_98 , V_99 , V_53 , 1 ) ;
}
int
F_107 ( struct V_19 * V_20 , T_2 V_98 , const enum V_52 V_53 )
{
return F_99 ( V_20 , V_98 , 0 , V_53 , 1 ) ;
}
int F_108 ( struct V_19 * V_20 )
{
struct V_18 * V_4 ;
unsigned long V_21 ;
int V_101 = - 1 ;
V_4 = F_5 ( V_20 , & V_21 ) ;
if ( ! F_19 ( V_20 ) )
V_101 = F_97 ( V_20 , V_4 ) ;
F_89 ( V_20 , & V_21 ) ;
return V_101 ;
}
int F_29 ( struct V_19 * V_20 )
{
for (; ; ) {
int V_101 = F_108 ( V_20 ) ;
if ( V_101 >= 0 )
return V_101 ;
F_9 () ;
}
}
T_2 F_109 ( const struct V_19 * V_20 )
{
unsigned long V_21 ;
T_2 V_107 ;
F_5 ( V_20 , & V_21 ) ;
V_107 = F_110 ( V_20 ) ;
F_89 ( V_20 , & V_21 ) ;
return V_107 ;
}
T_2 F_111 ( void )
{
struct V_3 * V_22 = F_61 ( & V_37 ) ;
struct V_18 * V_4 = V_22 -> V_12 ;
T_2 V_89 , V_108 = { . V_28 = V_59 } ;
unsigned long V_21 ;
int V_58 ;
F_7 ( & V_22 -> V_23 , V_21 ) ;
if ( ! F_54 () ) {
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ , V_4 ++ ) {
struct V_19 * V_20 ;
struct V_61 * V_62 ;
V_62 = F_57 ( & V_4 -> V_63 ) ;
if ( ! V_62 )
continue;
V_20 = F_58 ( V_62 , struct V_19 , V_64 ) ;
V_89 . V_28 = F_62 ( V_20 ) ;
V_89 = F_12 ( V_89 , V_4 -> V_104 () ) ;
if ( V_89 . V_28 < V_108 . V_28 )
V_108 . V_28 = V_89 . V_28 ;
}
}
F_8 ( & V_22 -> V_23 , V_21 ) ;
if ( V_108 . V_28 < 0 )
V_108 . V_28 = 0 ;
return V_108 ;
}
static void F_44 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_52 V_53 )
{
struct V_3 * V_22 ;
int V_4 ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_22 = F_112 ( & V_37 ) ;
if ( V_1 == V_109 && V_53 != V_110 )
V_1 = V_111 ;
V_4 = F_1 ( V_1 ) ;
V_20 -> V_4 = & V_22 -> V_12 [ V_4 ] ;
F_113 ( & V_20 -> V_64 ) ;
#ifdef F_84
V_20 -> V_78 = NULL ;
V_20 -> V_83 = - 1 ;
memset ( V_20 -> V_79 , 0 , V_82 ) ;
#endif
}
void F_114 ( struct V_19 * V_20 , T_1 V_1 ,
enum V_52 V_53 )
{
F_46 ( V_20 , V_1 , V_53 ) ;
F_44 ( V_20 , V_1 , V_53 ) ;
}
int F_115 ( const T_1 V_112 , struct V_113 * V_114 )
{
struct V_3 * V_22 ;
int V_4 = F_1 ( V_112 ) ;
V_22 = F_112 ( & V_37 ) ;
* V_114 = F_116 ( V_22 -> V_12 [ V_4 ] . V_72 ) ;
return 0 ;
}
static void F_117 ( struct V_19 * V_20 , T_2 * V_86 )
{
struct V_18 * V_4 = V_20 -> V_4 ;
struct V_3 * V_22 = V_4 -> V_22 ;
enum V_115 ( * V_116 ) ( struct V_19 * ) ;
int V_117 ;
F_33 ( ! F_82 () ) ;
F_50 ( V_20 ) ;
F_95 ( V_20 , V_4 , V_97 , 0 ) ;
F_87 ( V_20 ) ;
V_116 = V_20 -> V_46 ;
F_20 ( & V_22 -> V_23 ) ;
F_118 ( V_20 , V_86 ) ;
V_117 = V_116 ( V_20 ) ;
F_119 ( V_20 ) ;
F_21 ( & V_22 -> V_23 ) ;
if ( V_117 != V_118 ) {
F_120 ( V_20 -> V_48 != V_97 ) ;
F_93 ( V_20 , V_4 ) ;
}
F_32 ( ! ( V_20 -> V_48 & V_97 ) ) ;
V_20 -> V_48 &= ~ V_97 ;
}
void F_121 ( struct V_119 * V_120 )
{
struct V_3 * V_22 = F_61 ( & V_37 ) ;
T_2 V_29 , V_86 , V_121 , V_89 ;
int V_58 , V_122 = 0 ;
F_120 ( ! V_22 -> V_26 ) ;
V_22 -> V_123 ++ ;
V_120 -> V_124 . V_28 = V_59 ;
F_21 ( & V_22 -> V_23 ) ;
V_121 = V_86 = F_65 ( V_22 ) ;
V_125:
V_29 . V_28 = V_59 ;
V_22 -> V_29 . V_28 = V_59 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_18 * V_4 ;
struct V_61 * V_64 ;
T_2 V_126 ;
if ( ! ( V_22 -> V_91 & ( 1 << V_58 ) ) )
continue;
V_4 = V_22 -> V_12 + V_58 ;
V_126 = F_4 ( V_86 , V_4 -> V_27 ) ;
while ( ( V_64 = F_57 ( & V_4 -> V_63 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_58 ( V_64 , struct V_19 , V_64 ) ;
if ( V_126 . V_28 < F_122 ( V_20 ) ) {
T_2 V_25 ;
V_25 = F_12 ( F_13 ( V_20 ) ,
V_4 -> V_27 ) ;
if ( V_25 . V_28 < 0 )
V_25 . V_28 = V_59 ;
if ( V_25 . V_28 < V_29 . V_28 )
V_29 = V_25 ;
break;
}
F_117 ( V_20 , & V_126 ) ;
}
}
V_22 -> V_29 = V_29 ;
F_20 ( & V_22 -> V_23 ) ;
if ( V_29 . V_28 == V_59 ||
! F_59 ( V_29 , 0 ) ) {
V_22 -> V_65 = 0 ;
return;
}
F_21 ( & V_22 -> V_23 ) ;
V_86 = F_65 ( V_22 ) ;
V_22 -> V_127 ++ ;
if ( ++ V_122 < 3 )
goto V_125;
V_22 -> V_128 ++ ;
V_22 -> V_65 = 1 ;
F_20 ( & V_22 -> V_23 ) ;
V_89 = F_12 ( V_86 , V_121 ) ;
if ( V_89 . V_28 > V_22 -> V_129 . V_28 )
V_22 -> V_129 = V_89 ;
if ( V_89 . V_28 > 100 * V_130 )
V_29 = F_123 ( V_86 , 100 * V_130 ) ;
else
V_29 = F_4 ( V_86 , V_89 ) ;
F_59 ( V_29 , 1 ) ;
F_124 ( V_71 L_6 ,
F_23 ( V_89 ) ) ;
}
static void F_125 ( void )
{
struct V_131 * V_132 ;
if ( ! F_54 () )
return;
V_132 = F_61 ( & V_133 ) ;
if ( V_132 && V_132 -> V_134 )
F_121 ( V_132 -> V_134 ) ;
}
void F_126 ( void )
{
unsigned long V_21 ;
F_69 ( V_21 ) ;
F_125 () ;
F_71 ( V_21 ) ;
}
static void F_127 ( struct V_135 * V_136 )
{
F_126 () ;
}
static inline void F_125 ( void ) { }
void F_128 ( void )
{
if ( F_54 () )
return;
if ( F_129 ( ! F_53 () ) )
F_68 () ;
}
void F_130 ( void )
{
struct V_61 * V_64 ;
struct V_3 * V_22 = F_61 ( & V_37 ) ;
struct V_18 * V_4 ;
int V_35 , V_137 = 1 ;
if ( F_54 () )
return;
for ( V_35 = 0 ; V_35 < V_60 ; V_35 ++ ) {
V_4 = & V_22 -> V_12 [ V_35 ] ;
if ( ! F_57 ( & V_4 -> V_63 ) )
continue;
if ( V_137 ) {
F_2 ( V_22 ) ;
V_137 = 0 ;
}
F_21 ( & V_22 -> V_23 ) ;
while ( ( V_64 = F_57 ( & V_4 -> V_63 ) ) ) {
struct V_19 * V_20 ;
V_20 = F_58 ( V_64 , struct V_19 , V_64 ) ;
if ( V_4 -> V_14 . V_28 <=
F_62 ( V_20 ) )
break;
F_117 ( V_20 , & V_4 -> V_14 ) ;
}
F_20 ( & V_22 -> V_23 ) ;
}
}
static enum V_115 F_131 ( struct V_19 * V_20 )
{
struct V_138 * V_139 =
F_58 ( V_20 , struct V_138 , V_20 ) ;
struct V_140 * V_141 = V_139 -> V_141 ;
V_139 -> V_141 = NULL ;
if ( V_141 )
F_132 ( V_141 ) ;
return V_118 ;
}
void F_133 ( struct V_138 * V_142 , struct V_140 * V_141 )
{
V_142 -> V_20 . V_46 = F_131 ;
V_142 -> V_141 = V_141 ;
}
static int T_6 F_134 ( struct V_138 * V_139 , enum V_52 V_53 )
{
F_133 ( V_139 , V_80 ) ;
do {
F_135 ( V_143 ) ;
F_136 ( & V_139 -> V_20 , V_53 ) ;
if ( ! F_137 ( & V_139 -> V_20 ) )
V_139 -> V_141 = NULL ;
if ( F_6 ( V_139 -> V_141 ) )
F_138 () ;
F_29 ( & V_139 -> V_20 ) ;
V_53 = V_110 ;
} while ( V_139 -> V_141 && ! F_139 ( V_80 ) );
F_140 ( V_144 ) ;
return V_139 -> V_141 == NULL ;
}
static int F_141 ( struct V_19 * V_20 , struct V_113 T_7 * V_145 )
{
struct V_113 V_146 ;
T_2 V_107 ;
V_107 = F_110 ( V_20 ) ;
if ( V_107 . V_28 <= 0 )
return 0 ;
V_146 = F_116 ( V_107 ) ;
if ( F_142 ( V_145 , & V_146 , sizeof( * V_145 ) ) )
return - V_147 ;
return 1 ;
}
long T_6 F_143 ( struct V_148 * V_117 )
{
struct V_138 V_139 ;
struct V_113 T_7 * V_145 ;
int V_101 = 0 ;
F_42 ( & V_139 . V_20 , V_117 -> V_149 . V_54 ,
V_110 ) ;
F_144 ( & V_139 . V_20 , V_117 -> V_149 . V_25 ) ;
if ( F_134 ( & V_139 , V_110 ) )
goto V_96;
V_145 = V_117 -> V_149 . V_145 ;
if ( V_145 ) {
V_101 = F_141 ( & V_139 . V_20 , V_145 ) ;
if ( V_101 <= 0 )
goto V_96;
}
V_101 = - V_150 ;
V_96:
F_45 ( & V_139 . V_20 ) ;
return V_101 ;
}
long F_145 ( struct V_113 * V_151 , struct V_113 T_7 * V_145 ,
const enum V_52 V_53 , const T_1 V_54 )
{
struct V_148 * V_117 ;
struct V_138 V_139 ;
int V_101 = 0 ;
unsigned long V_152 ;
V_152 = V_80 -> V_153 ;
if ( F_146 ( V_80 ) || F_147 ( V_80 ) )
V_152 = 0 ;
F_42 ( & V_139 . V_20 , V_54 , V_53 ) ;
F_101 ( & V_139 . V_20 , F_148 ( * V_151 ) , V_152 ) ;
if ( F_134 ( & V_139 , V_53 ) )
goto V_96;
if ( V_53 == V_110 ) {
V_101 = - V_154 ;
goto V_96;
}
if ( V_145 ) {
V_101 = F_141 ( & V_139 . V_20 , V_145 ) ;
if ( V_101 <= 0 )
goto V_96;
}
V_117 = & F_149 () -> V_148 ;
V_117 -> V_116 = F_143 ;
V_117 -> V_149 . V_54 = V_139 . V_20 . V_4 -> V_54 ;
V_117 -> V_149 . V_145 = V_145 ;
V_117 -> V_149 . V_25 = F_62 ( & V_139 . V_20 ) ;
V_101 = - V_150 ;
V_96:
F_45 ( & V_139 . V_20 ) ;
return V_101 ;
}
static void F_150 ( int V_33 )
{
struct V_3 * V_22 = & F_17 ( V_37 , V_33 ) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
V_22 -> V_12 [ V_58 ] . V_22 = V_22 ;
F_151 ( & V_22 -> V_12 [ V_58 ] . V_63 ) ;
}
V_22 -> V_33 = V_33 ;
F_64 ( V_22 ) ;
}
static void F_152 ( struct V_18 * V_155 ,
struct V_18 * V_24 )
{
struct V_19 * V_20 ;
struct V_61 * V_64 ;
while ( ( V_64 = F_57 ( & V_155 -> V_63 ) ) ) {
V_20 = F_58 ( V_64 , struct V_19 , V_64 ) ;
F_120 ( F_19 ( V_20 ) ) ;
F_50 ( V_20 ) ;
F_95 ( V_20 , V_155 , V_156 , 0 ) ;
V_20 -> V_4 = V_24 ;
F_93 ( V_20 , V_24 ) ;
V_20 -> V_48 &= ~ V_156 ;
}
}
static void F_153 ( int V_157 )
{
struct V_3 * V_155 , * V_24 ;
int V_58 ;
F_120 ( F_154 ( V_157 ) ) ;
F_155 ( V_157 ) ;
F_156 () ;
V_155 = & F_17 ( V_37 , V_157 ) ;
V_24 = F_61 ( & V_37 ) ;
F_21 ( & V_24 -> V_23 ) ;
F_157 ( & V_155 -> V_23 , V_158 ) ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
F_152 ( & V_155 -> V_12 [ V_58 ] ,
& V_24 -> V_12 [ V_58 ] ) ;
}
F_20 ( & V_155 -> V_23 ) ;
F_20 ( & V_24 -> V_23 ) ;
F_125 () ;
F_158 () ;
}
static int F_159 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
int V_157 = ( long ) V_162 ;
switch ( V_161 ) {
case V_163 :
case V_164 :
F_150 ( V_157 ) ;
break;
#ifdef F_160
case V_165 :
case V_166 :
F_161 ( V_167 , & V_157 ) ;
break;
case V_168 :
case V_169 :
{
F_161 ( V_170 , & V_157 ) ;
F_153 ( V_157 ) ;
break;
}
#endif
default:
break;
}
return V_171 ;
}
void T_5 F_162 ( void )
{
F_159 ( & V_172 , ( unsigned long ) V_163 ,
( void * ) ( long ) F_15 () ) ;
F_163 ( & V_172 ) ;
#ifdef F_11
F_164 ( V_106 , F_127 ) ;
#endif
}
int T_6
F_165 ( T_2 * V_25 , unsigned long V_89 ,
const enum V_52 V_53 , int clock )
{
struct V_138 V_139 ;
if ( V_25 && ! V_25 -> V_28 ) {
F_140 ( V_144 ) ;
return 0 ;
}
if ( ! V_25 ) {
F_166 () ;
return - V_173 ;
}
F_42 ( & V_139 . V_20 , clock , V_53 ) ;
F_101 ( & V_139 . V_20 , * V_25 , V_89 ) ;
F_133 ( & V_139 , V_80 ) ;
F_136 ( & V_139 . V_20 , V_53 ) ;
if ( ! F_137 ( & V_139 . V_20 ) )
V_139 . V_141 = NULL ;
if ( F_6 ( V_139 . V_141 ) )
F_166 () ;
F_29 ( & V_139 . V_20 ) ;
F_45 ( & V_139 . V_20 ) ;
F_140 ( V_144 ) ;
return ! V_139 . V_141 ? 0 : - V_173 ;
}
int T_6 F_167 ( T_2 * V_25 , unsigned long V_89 ,
const enum V_52 V_53 )
{
return F_165 ( V_25 , V_89 , V_53 ,
V_111 ) ;
}
int T_6 F_168 ( T_2 * V_25 ,
const enum V_52 V_53 )
{
return F_167 ( V_25 , 0 , V_53 ) ;
}
