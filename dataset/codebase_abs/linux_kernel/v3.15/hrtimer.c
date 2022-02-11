static inline int F_1 ( T_1 V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( struct V_3 * V_4 )
{
T_2 V_5 , V_6 , V_7 ;
struct V_8 V_9 , V_10 , V_11 ;
T_3 V_12 ;
F_3 ( & V_9 , & V_10 , & V_11 ) ;
V_12 = F_4 () ;
V_5 = F_5 ( V_9 ) ;
V_6 = F_6 ( V_5 , F_5 ( V_10 ) ) ;
V_7 = F_6 ( V_6 , F_5 ( V_11 ) ) ;
V_4 -> V_13 [ V_14 ] . V_15 = V_5 ;
V_4 -> V_13 [ V_16 ] . V_15 = V_6 ;
V_4 -> V_13 [ V_17 ] . V_15 = V_7 ;
V_4 -> V_13 [ V_18 ] . V_15 =
F_6 ( V_5 , F_7 ( V_12 , 0 ) ) ;
}
static
struct V_19 * F_8 ( const struct V_20 * V_21 ,
unsigned long * V_22 )
{
struct V_19 * V_4 ;
for (; ; ) {
V_4 = V_21 -> V_4 ;
if ( F_9 ( V_4 != NULL ) ) {
F_10 ( & V_4 -> V_23 -> V_24 , * V_22 ) ;
if ( F_9 ( V_4 == V_21 -> V_4 ) )
return V_4 ;
F_11 ( & V_4 -> V_23 -> V_24 , * V_22 ) ;
}
F_12 () ;
}
}
static int
F_13 ( struct V_20 * V_21 , struct V_19 * V_25 )
{
#ifdef F_14
T_2 V_26 ;
if ( ! V_25 -> V_23 -> V_27 )
return 0 ;
V_26 = F_15 ( F_16 ( V_21 ) , V_25 -> V_28 ) ;
return V_26 . V_29 <= V_25 -> V_23 -> V_30 . V_29 ;
#else
return 0 ;
#endif
}
static inline struct V_19 *
F_17 ( struct V_20 * V_21 , struct V_19 * V_4 ,
int V_31 )
{
struct V_19 * V_25 ;
struct V_3 * V_32 ;
int V_33 = F_18 () ;
int V_34 = F_19 ( V_31 ) ;
int V_35 = V_4 -> V_36 ;
V_37:
V_32 = & F_20 ( V_38 , V_34 ) ;
V_25 = & V_32 -> V_13 [ V_35 ] ;
if ( V_4 != V_25 ) {
if ( F_21 ( F_22 ( V_21 ) ) )
return V_4 ;
V_21 -> V_4 = NULL ;
F_23 ( & V_4 -> V_23 -> V_24 ) ;
F_24 ( & V_25 -> V_23 -> V_24 ) ;
if ( V_34 != V_33 && F_13 ( V_21 , V_25 ) ) {
V_34 = V_33 ;
F_23 ( & V_25 -> V_23 -> V_24 ) ;
F_24 ( & V_4 -> V_23 -> V_24 ) ;
V_21 -> V_4 = V_4 ;
goto V_37;
}
V_21 -> V_4 = V_25 ;
} else {
if ( V_34 != V_33 && F_13 ( V_21 , V_25 ) ) {
V_34 = V_33 ;
goto V_37;
}
}
return V_25 ;
}
static inline struct V_19 *
F_8 ( const struct V_20 * V_21 , unsigned long * V_22 )
{
struct V_19 * V_4 = V_21 -> V_4 ;
F_10 ( & V_4 -> V_23 -> V_24 , * V_22 ) ;
return V_4 ;
}
T_2 F_25 ( const T_2 V_39 , T_4 V_40 )
{
T_2 V_41 ;
if ( F_9 ( V_40 < V_42 ) ) {
V_41 . V_29 = V_40 ;
} else {
unsigned long V_43 = F_26 ( V_40 , V_42 ) ;
if ( F_21 ( V_40 > V_44 ) )
return ( T_2 ) { . V_29 = V_45 } ;
V_41 = F_7 ( ( long ) V_40 , V_43 ) ;
}
return F_6 ( V_39 , V_41 ) ;
}
T_2 F_27 ( const T_2 V_39 , T_4 V_40 )
{
T_2 V_41 ;
if ( F_9 ( V_40 < V_42 ) ) {
V_41 . V_29 = V_40 ;
} else {
unsigned long V_43 = F_26 ( V_40 , V_42 ) ;
V_41 = F_7 ( ( long ) V_40 , V_43 ) ;
}
return F_15 ( V_39 , V_41 ) ;
}
T_4 F_28 ( const T_2 V_39 , T_5 div )
{
T_4 V_46 ;
int V_47 = 0 ;
V_46 = F_29 ( V_39 ) ;
while ( div >> 32 ) {
V_47 ++ ;
div >>= 1 ;
}
V_46 >>= V_47 ;
F_26 ( V_46 , ( unsigned long ) div ) ;
return V_46 ;
}
T_2 F_30 ( const T_2 V_48 , const T_2 V_49 )
{
T_2 V_50 = F_6 ( V_48 , V_49 ) ;
if ( V_50 . V_29 < 0 || V_50 . V_29 < V_48 . V_29 || V_50 . V_29 < V_49 . V_29 )
V_50 = F_7 ( V_44 , 0 ) ;
return V_50 ;
}
static void * F_31 ( void * V_51 )
{
return ( (struct V_20 * ) V_51 ) -> V_52 ;
}
static int F_32 ( void * V_51 , enum V_53 V_54 )
{
struct V_20 * V_21 = V_51 ;
switch ( V_54 ) {
case V_55 :
F_33 ( V_21 ) ;
F_34 ( V_21 , & V_56 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_35 ( void * V_51 , enum V_53 V_54 )
{
switch ( V_54 ) {
case V_57 :
F_36 ( 1 ) ;
return 0 ;
case V_55 :
F_37 ( 1 ) ;
default:
return 0 ;
}
}
static int F_38 ( void * V_51 , enum V_53 V_54 )
{
struct V_20 * V_21 = V_51 ;
switch ( V_54 ) {
case V_55 :
F_33 ( V_21 ) ;
F_39 ( V_21 , & V_56 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_40 ( struct V_20 * V_21 )
{
F_34 ( V_21 , & V_56 ) ;
}
static inline void F_41 ( struct V_20 * V_21 )
{
F_42 ( V_21 , & V_56 ) ;
}
static inline void F_43 ( struct V_20 * V_21 )
{
F_44 ( V_21 , & V_56 ) ;
}
static inline void F_45 ( struct V_20 * V_21 )
{
F_39 ( V_21 , & V_56 ) ;
}
void F_46 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
F_47 ( V_21 , & V_56 ) ;
F_48 ( V_21 , V_1 , V_59 ) ;
}
void F_49 ( struct V_20 * V_21 )
{
F_39 ( V_21 , & V_56 ) ;
}
static inline void F_40 ( struct V_20 * V_21 ) { }
static inline void F_41 ( struct V_20 * V_21 ) { }
static inline void F_43 ( struct V_20 * V_21 ) { }
static inline void
F_50 ( struct V_20 * V_21 , T_1 V_60 ,
enum V_58 V_59 )
{
F_40 ( V_21 ) ;
F_51 ( V_21 , V_60 , V_59 ) ;
}
static inline void F_52 ( struct V_20 * V_21 )
{
F_41 ( V_21 ) ;
F_53 ( V_21 ) ;
}
static inline void F_54 ( struct V_20 * V_21 )
{
F_43 ( V_21 ) ;
F_55 ( V_21 ) ;
}
static int T_6 F_56 ( char * V_61 )
{
if ( ! strcmp ( V_61 , L_1 ) )
V_62 = 0 ;
else if ( ! strcmp ( V_61 , L_2 ) )
V_62 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_57 ( void )
{
return V_62 ;
}
static inline int F_58 ( void )
{
return F_59 ( V_38 . V_27 ) ;
}
static void
F_60 ( struct V_3 * V_23 , int V_63 )
{
int V_64 ;
struct V_19 * V_4 = V_23 -> V_13 ;
T_2 V_26 , V_30 ;
V_30 . V_29 = V_45 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ , V_4 ++ ) {
struct V_20 * V_21 ;
struct V_66 * V_67 ;
V_67 = F_61 ( & V_4 -> V_68 ) ;
if ( ! V_67 )
continue;
V_21 = F_62 ( V_67 , struct V_20 , V_69 ) ;
V_26 = F_15 ( F_16 ( V_21 ) , V_4 -> V_28 ) ;
if ( V_26 . V_29 < 0 )
V_26 . V_29 = 0 ;
if ( V_26 . V_29 < V_30 . V_29 )
V_30 = V_26 ;
}
if ( V_63 && V_30 . V_29 == V_23 -> V_30 . V_29 )
return;
V_23 -> V_30 . V_29 = V_30 . V_29 ;
if ( V_23 -> V_70 )
return;
if ( V_23 -> V_30 . V_29 != V_45 )
F_63 ( V_23 -> V_30 , 1 ) ;
}
static int F_64 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
struct V_3 * V_23 = & F_65 ( V_38 ) ;
T_2 V_26 = F_15 ( F_16 ( V_21 ) , V_4 -> V_28 ) ;
int V_50 ;
F_36 ( F_66 ( V_21 ) < 0 ) ;
if ( F_22 ( V_21 ) )
return 0 ;
if ( V_26 . V_29 < 0 )
return - V_71 ;
if ( V_26 . V_29 >= V_23 -> V_30 . V_29 )
return 0 ;
if ( V_23 -> V_70 )
return 0 ;
V_50 = F_63 ( V_26 , 0 ) ;
if ( ! F_67 ( V_50 ) )
V_23 -> V_30 = V_26 ;
return V_50 ;
}
static inline void F_68 ( struct V_3 * V_4 )
{
V_4 -> V_30 . V_29 = V_45 ;
V_4 -> V_27 = 0 ;
}
static inline int F_69 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
return V_4 -> V_23 -> V_27 && F_64 ( V_21 , V_4 ) ;
}
static inline T_2 F_70 ( struct V_3 * V_4 )
{
T_2 * V_72 = & V_4 -> V_13 [ V_14 ] . V_28 ;
T_2 * V_73 = & V_4 -> V_13 [ V_17 ] . V_28 ;
T_2 * V_74 = & V_4 -> V_13 [ V_18 ] . V_28 ;
return F_71 ( V_72 , V_73 , V_74 ) ;
}
static void F_72 ( void * V_75 )
{
struct V_3 * V_4 = & F_65 ( V_38 ) ;
if ( ! F_58 () )
return;
F_24 ( & V_4 -> V_24 ) ;
F_70 ( V_4 ) ;
F_60 ( V_4 , 0 ) ;
F_23 ( & V_4 -> V_24 ) ;
}
static int F_73 ( void )
{
int V_64 , V_34 = F_18 () ;
struct V_3 * V_4 = & F_20 ( V_38 , V_34 ) ;
unsigned long V_22 ;
if ( V_4 -> V_27 )
return 1 ;
F_74 ( V_22 ) ;
if ( F_75 () ) {
F_76 ( V_22 ) ;
F_77 ( V_76 L_3
L_4 , V_34 ) ;
return 0 ;
}
V_4 -> V_27 = 1 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
V_4 -> V_13 [ V_64 ] . V_77 = V_78 ;
F_78 () ;
F_72 ( NULL ) ;
F_76 ( V_22 ) ;
return 1 ;
}
static void F_79 ( struct V_79 * V_80 )
{
F_80 () ;
}
void F_81 ( void )
{
F_82 ( & V_81 ) ;
}
static inline int F_58 ( void ) { return 0 ; }
static inline int F_57 ( void ) { return 0 ; }
static inline int F_73 ( void ) { return 0 ; }
static inline void
F_60 ( struct V_3 * V_4 , int V_63 ) { }
static inline int F_69 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
return 0 ;
}
static inline void F_68 ( struct V_3 * V_4 ) { }
static inline void F_72 ( void * V_75 ) { }
void F_80 ( void )
{
#ifdef F_14
F_83 ( F_72 , NULL , 1 ) ;
#endif
F_84 () ;
}
void F_85 ( void )
{
F_86 ( ! F_87 () ,
V_82 L_5 ) ;
F_72 ( NULL ) ;
F_81 () ;
}
static inline void F_88 ( struct V_20 * V_21 )
{
#ifdef F_89
if ( V_21 -> V_83 )
return;
V_21 -> V_83 = F_90 ( 0 ) ;
memcpy ( V_21 -> V_84 , V_85 -> V_86 , V_87 ) ;
V_21 -> V_88 = V_85 -> V_89 ;
#endif
}
static inline void F_91 ( struct V_20 * V_21 )
{
#ifdef F_89
V_21 -> V_83 = NULL ;
#endif
}
static inline void F_92 ( struct V_20 * V_21 )
{
#ifdef F_89
if ( F_9 ( ! V_90 ) )
return;
F_93 ( V_21 , V_21 -> V_88 , V_21 -> V_83 ,
V_21 -> V_52 , V_21 -> V_84 , 0 ) ;
#endif
}
static inline
void F_94 ( const struct V_20 * V_21 , unsigned long * V_22 )
{
F_11 ( & V_21 -> V_4 -> V_23 -> V_24 , * V_22 ) ;
}
T_4 F_95 ( struct V_20 * V_21 , T_2 V_91 , T_2 V_92 )
{
T_4 V_93 = 1 ;
T_2 V_94 ;
V_94 = F_15 ( V_91 , F_16 ( V_21 ) ) ;
if ( V_94 . V_29 < 0 )
return 0 ;
if ( V_92 . V_29 < V_21 -> V_4 -> V_77 . V_29 )
V_92 . V_29 = V_21 -> V_4 -> V_77 . V_29 ;
if ( F_21 ( V_94 . V_29 >= V_92 . V_29 ) ) {
T_5 V_95 = F_29 ( V_92 ) ;
V_93 = F_28 ( V_94 , V_95 ) ;
F_96 ( V_21 , V_95 * V_93 ) ;
if ( F_66 ( V_21 ) > V_91 . V_29 )
return V_93 ;
V_93 ++ ;
}
F_97 ( V_21 , V_92 ) ;
return V_93 ;
}
static int F_98 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
F_52 ( V_21 ) ;
F_99 ( & V_4 -> V_68 , & V_21 -> V_69 ) ;
V_4 -> V_23 -> V_96 |= 1 << V_4 -> V_36 ;
V_21 -> V_54 |= V_97 ;
return ( & V_21 -> V_69 == V_4 -> V_68 . V_67 ) ;
}
static void F_100 ( struct V_20 * V_21 ,
struct V_19 * V_4 ,
unsigned long V_98 , int V_99 )
{
struct V_66 * V_100 ;
if ( ! ( V_21 -> V_54 & V_97 ) )
goto V_101;
V_100 = F_61 ( & V_4 -> V_68 ) ;
F_101 ( & V_4 -> V_68 , & V_21 -> V_69 ) ;
if ( & V_21 -> V_69 == V_100 ) {
#ifdef F_14
if ( V_99 && F_58 () ) {
T_2 V_26 ;
V_26 = F_15 ( F_16 ( V_21 ) ,
V_4 -> V_28 ) ;
if ( V_4 -> V_23 -> V_30 . V_29 == V_26 . V_29 )
F_60 ( V_4 -> V_23 , 1 ) ;
}
#endif
}
if ( ! F_61 ( & V_4 -> V_68 ) )
V_4 -> V_23 -> V_96 &= ~ ( 1 << V_4 -> V_36 ) ;
V_101:
V_21 -> V_54 = V_98 ;
}
static inline int
F_102 ( struct V_20 * V_21 , struct V_19 * V_4 )
{
if ( F_103 ( V_21 ) ) {
unsigned long V_54 ;
int V_99 ;
F_54 ( V_21 ) ;
F_91 ( V_21 ) ;
V_99 = V_4 -> V_23 == & F_65 ( V_38 ) ;
V_54 = V_21 -> V_54 & V_102 ;
F_100 ( V_21 , V_4 , V_54 , V_99 ) ;
return 1 ;
}
return 0 ;
}
int F_104 ( struct V_20 * V_21 , T_2 V_103 ,
unsigned long V_104 , const enum V_58 V_59 ,
int V_105 )
{
struct V_19 * V_4 , * V_25 ;
unsigned long V_22 ;
int V_106 , V_107 ;
V_4 = F_8 ( V_21 , & V_22 ) ;
V_106 = F_102 ( V_21 , V_4 ) ;
if ( V_59 & V_108 ) {
V_103 = F_30 ( V_103 , V_4 -> V_109 () ) ;
#ifdef F_105
V_103 = F_30 ( V_103 , V_4 -> V_77 ) ;
#endif
}
F_106 ( V_21 , V_103 , V_104 ) ;
V_25 = F_17 ( V_21 , V_4 , V_59 & V_110 ) ;
F_88 ( V_21 ) ;
V_107 = F_98 ( V_21 , V_25 ) ;
if ( V_107 && V_25 -> V_23 == & F_65 ( V_38 )
&& F_69 ( V_21 , V_25 ) ) {
if ( V_105 ) {
F_23 ( & V_25 -> V_23 -> V_24 ) ;
F_107 ( V_111 ) ;
F_76 ( V_22 ) ;
return V_106 ;
} else {
F_108 ( V_111 ) ;
}
}
F_94 ( V_21 , & V_22 ) ;
return V_106 ;
}
int F_109 ( struct V_20 * V_21 , T_2 V_103 ,
unsigned long V_104 , const enum V_58 V_59 )
{
return F_104 ( V_21 , V_103 , V_104 , V_59 , 1 ) ;
}
int
F_110 ( struct V_20 * V_21 , T_2 V_103 , const enum V_58 V_59 )
{
return F_104 ( V_21 , V_103 , 0 , V_59 , 1 ) ;
}
int F_111 ( struct V_20 * V_21 )
{
struct V_19 * V_4 ;
unsigned long V_22 ;
int V_106 = - 1 ;
V_4 = F_8 ( V_21 , & V_22 ) ;
if ( ! F_22 ( V_21 ) )
V_106 = F_102 ( V_21 , V_4 ) ;
F_94 ( V_21 , & V_22 ) ;
return V_106 ;
}
int F_33 ( struct V_20 * V_21 )
{
for (; ; ) {
int V_106 = F_111 ( V_21 ) ;
if ( V_106 >= 0 )
return V_106 ;
F_12 () ;
}
}
T_2 F_112 ( const struct V_20 * V_21 )
{
unsigned long V_22 ;
T_2 V_43 ;
F_8 ( V_21 , & V_22 ) ;
V_43 = F_113 ( V_21 ) ;
F_94 ( V_21 , & V_22 ) ;
return V_43 ;
}
T_2 F_114 ( void )
{
struct V_3 * V_23 = & F_65 ( V_38 ) ;
struct V_19 * V_4 = V_23 -> V_13 ;
T_2 V_94 , V_112 = { . V_29 = V_45 } ;
unsigned long V_22 ;
int V_64 ;
F_10 ( & V_23 -> V_24 , V_22 ) ;
if ( ! F_58 () ) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ , V_4 ++ ) {
struct V_20 * V_21 ;
struct V_66 * V_67 ;
V_67 = F_61 ( & V_4 -> V_68 ) ;
if ( ! V_67 )
continue;
V_21 = F_62 ( V_67 , struct V_20 , V_69 ) ;
V_94 . V_29 = F_66 ( V_21 ) ;
V_94 = F_15 ( V_94 , V_4 -> V_109 () ) ;
if ( V_94 . V_29 < V_112 . V_29 )
V_112 . V_29 = V_94 . V_29 ;
}
}
F_11 ( & V_23 -> V_24 , V_22 ) ;
if ( V_112 . V_29 < 0 )
V_112 . V_29 = 0 ;
return V_112 ;
}
static void F_48 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
struct V_3 * V_23 ;
int V_4 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_23 = & F_115 ( V_38 ) ;
if ( V_1 == V_113 && V_59 != V_114 )
V_1 = V_115 ;
V_4 = F_1 ( V_1 ) ;
V_21 -> V_4 = & V_23 -> V_13 [ V_4 ] ;
F_116 ( & V_21 -> V_69 ) ;
#ifdef F_89
V_21 -> V_83 = NULL ;
V_21 -> V_88 = - 1 ;
memset ( V_21 -> V_84 , 0 , V_87 ) ;
#endif
}
void F_117 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
F_50 ( V_21 , V_1 , V_59 ) ;
F_48 ( V_21 , V_1 , V_59 ) ;
}
int F_118 ( const T_1 V_116 , struct V_8 * V_117 )
{
struct V_3 * V_23 ;
int V_4 = F_1 ( V_116 ) ;
V_23 = & F_115 ( V_38 ) ;
* V_117 = F_119 ( V_23 -> V_13 [ V_4 ] . V_77 ) ;
return 0 ;
}
static void F_120 ( struct V_20 * V_21 , T_2 * V_91 )
{
struct V_19 * V_4 = V_21 -> V_4 ;
struct V_3 * V_23 = V_4 -> V_23 ;
enum V_118 ( * V_119 ) ( struct V_20 * ) ;
int V_120 ;
F_37 ( ! F_87 () ) ;
F_54 ( V_21 ) ;
F_100 ( V_21 , V_4 , V_102 , 0 ) ;
F_92 ( V_21 ) ;
V_119 = V_21 -> V_52 ;
F_23 ( & V_23 -> V_24 ) ;
F_121 ( V_21 , V_91 ) ;
V_120 = V_119 ( V_21 ) ;
F_122 ( V_21 ) ;
F_24 ( & V_23 -> V_24 ) ;
if ( V_120 != V_121 ) {
F_123 ( V_21 -> V_54 != V_102 ) ;
F_98 ( V_21 , V_4 ) ;
}
F_36 ( ! ( V_21 -> V_54 & V_102 ) ) ;
V_21 -> V_54 &= ~ V_102 ;
}
void F_124 ( struct V_122 * V_123 )
{
struct V_3 * V_23 = & F_65 ( V_38 ) ;
T_2 V_30 , V_91 , V_124 , V_94 ;
int V_64 , V_125 = 0 ;
F_123 ( ! V_23 -> V_27 ) ;
V_23 -> V_126 ++ ;
V_123 -> V_127 . V_29 = V_45 ;
F_24 ( & V_23 -> V_24 ) ;
V_124 = V_91 = F_70 ( V_23 ) ;
V_128:
V_30 . V_29 = V_45 ;
V_23 -> V_30 . V_29 = V_45 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
struct V_19 * V_4 ;
struct V_66 * V_69 ;
T_2 V_129 ;
if ( ! ( V_23 -> V_96 & ( 1 << V_64 ) ) )
continue;
V_4 = V_23 -> V_13 + V_64 ;
V_129 = F_6 ( V_91 , V_4 -> V_28 ) ;
while ( ( V_69 = F_61 ( & V_4 -> V_68 ) ) ) {
struct V_20 * V_21 ;
V_21 = F_62 ( V_69 , struct V_20 , V_69 ) ;
if ( V_129 . V_29 < F_125 ( V_21 ) ) {
T_2 V_26 ;
V_26 = F_15 ( F_16 ( V_21 ) ,
V_4 -> V_28 ) ;
if ( V_26 . V_29 < 0 )
V_26 . V_29 = V_45 ;
if ( V_26 . V_29 < V_30 . V_29 )
V_30 = V_26 ;
break;
}
F_120 ( V_21 , & V_129 ) ;
}
}
V_23 -> V_30 = V_30 ;
F_23 ( & V_23 -> V_24 ) ;
if ( V_30 . V_29 == V_45 ||
! F_63 ( V_30 , 0 ) ) {
V_23 -> V_70 = 0 ;
return;
}
F_24 ( & V_23 -> V_24 ) ;
V_91 = F_70 ( V_23 ) ;
V_23 -> V_130 ++ ;
if ( ++ V_125 < 3 )
goto V_128;
V_23 -> V_131 ++ ;
V_23 -> V_70 = 1 ;
F_23 ( & V_23 -> V_24 ) ;
V_94 = F_15 ( V_91 , V_124 ) ;
if ( V_94 . V_29 > V_23 -> V_132 . V_29 )
V_23 -> V_132 = V_94 ;
if ( V_94 . V_29 > 100 * V_133 )
V_30 = F_25 ( V_91 , 100 * V_133 ) ;
else
V_30 = F_6 ( V_91 , V_94 ) ;
F_63 ( V_30 , 1 ) ;
F_126 ( V_76 L_6 ,
F_29 ( V_94 ) ) ;
}
static void F_127 ( void )
{
struct V_134 * V_135 ;
if ( ! F_58 () )
return;
V_135 = & F_65 ( V_136 ) ;
if ( V_135 && V_135 -> V_137 )
F_124 ( V_135 -> V_137 ) ;
}
void F_128 ( void )
{
unsigned long V_22 ;
F_74 ( V_22 ) ;
F_127 () ;
F_76 ( V_22 ) ;
}
static void F_129 ( struct V_138 * V_139 )
{
F_128 () ;
}
static inline void F_127 ( void ) { }
void F_130 ( void )
{
if ( F_58 () )
return;
if ( F_131 ( ! F_57 () ) )
F_73 () ;
}
void F_132 ( void )
{
struct V_66 * V_69 ;
struct V_3 * V_23 = & F_65 ( V_38 ) ;
struct V_19 * V_4 ;
int V_36 , V_140 = 1 ;
if ( F_58 () )
return;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ ) {
V_4 = & V_23 -> V_13 [ V_36 ] ;
if ( ! F_61 ( & V_4 -> V_68 ) )
continue;
if ( V_140 ) {
F_2 ( V_23 ) ;
V_140 = 0 ;
}
F_24 ( & V_23 -> V_24 ) ;
while ( ( V_69 = F_61 ( & V_4 -> V_68 ) ) ) {
struct V_20 * V_21 ;
V_21 = F_62 ( V_69 , struct V_20 , V_69 ) ;
if ( V_4 -> V_15 . V_29 <=
F_66 ( V_21 ) )
break;
F_120 ( V_21 , & V_4 -> V_15 ) ;
}
F_23 ( & V_23 -> V_24 ) ;
}
}
static enum V_118 F_133 ( struct V_20 * V_21 )
{
struct V_141 * V_142 =
F_62 ( V_21 , struct V_141 , V_21 ) ;
struct V_143 * V_144 = V_142 -> V_144 ;
V_142 -> V_144 = NULL ;
if ( V_144 )
F_134 ( V_144 ) ;
return V_121 ;
}
void F_135 ( struct V_141 * V_145 , struct V_143 * V_144 )
{
V_145 -> V_21 . V_52 = F_133 ;
V_145 -> V_144 = V_144 ;
}
static int T_7 F_136 ( struct V_141 * V_142 , enum V_58 V_59 )
{
F_135 ( V_142 , V_85 ) ;
do {
F_137 ( V_146 ) ;
F_138 ( & V_142 -> V_21 , V_59 ) ;
if ( ! F_139 ( & V_142 -> V_21 ) )
V_142 -> V_144 = NULL ;
if ( F_9 ( V_142 -> V_144 ) )
F_140 () ;
F_33 ( & V_142 -> V_21 ) ;
V_59 = V_114 ;
} while ( V_142 -> V_144 && ! F_141 ( V_85 ) );
F_142 ( V_147 ) ;
return V_142 -> V_144 == NULL ;
}
static int F_143 ( struct V_20 * V_21 , struct V_8 T_8 * V_148 )
{
struct V_8 V_149 ;
T_2 V_43 ;
V_43 = F_113 ( V_21 ) ;
if ( V_43 . V_29 <= 0 )
return 0 ;
V_149 = F_119 ( V_43 ) ;
if ( F_144 ( V_148 , & V_149 , sizeof( * V_148 ) ) )
return - V_150 ;
return 1 ;
}
long T_7 F_145 ( struct V_151 * V_120 )
{
struct V_141 V_142 ;
struct V_8 T_8 * V_148 ;
int V_106 = 0 ;
F_46 ( & V_142 . V_21 , V_120 -> V_152 . V_60 ,
V_114 ) ;
F_146 ( & V_142 . V_21 , V_120 -> V_152 . V_26 ) ;
if ( F_136 ( & V_142 , V_114 ) )
goto V_101;
V_148 = V_120 -> V_152 . V_148 ;
if ( V_148 ) {
V_106 = F_143 ( & V_142 . V_21 , V_148 ) ;
if ( V_106 <= 0 )
goto V_101;
}
V_106 = - V_153 ;
V_101:
F_49 ( & V_142 . V_21 ) ;
return V_106 ;
}
long F_147 ( struct V_8 * V_154 , struct V_8 T_8 * V_148 ,
const enum V_58 V_59 , const T_1 V_60 )
{
struct V_151 * V_120 ;
struct V_141 V_142 ;
int V_106 = 0 ;
unsigned long V_155 ;
V_155 = V_85 -> V_156 ;
if ( F_148 ( V_85 ) || F_149 ( V_85 ) )
V_155 = 0 ;
F_46 ( & V_142 . V_21 , V_60 , V_59 ) ;
F_106 ( & V_142 . V_21 , F_5 ( * V_154 ) , V_155 ) ;
if ( F_136 ( & V_142 , V_59 ) )
goto V_101;
if ( V_59 == V_114 ) {
V_106 = - V_157 ;
goto V_101;
}
if ( V_148 ) {
V_106 = F_143 ( & V_142 . V_21 , V_148 ) ;
if ( V_106 <= 0 )
goto V_101;
}
V_120 = & F_150 () -> V_151 ;
V_120 -> V_119 = F_145 ;
V_120 -> V_152 . V_60 = V_142 . V_21 . V_4 -> V_60 ;
V_120 -> V_152 . V_148 = V_148 ;
V_120 -> V_152 . V_26 = F_66 ( & V_142 . V_21 ) ;
V_106 = - V_153 ;
V_101:
F_49 ( & V_142 . V_21 ) ;
return V_106 ;
}
static void F_151 ( int V_34 )
{
struct V_3 * V_23 = & F_20 ( V_38 , V_34 ) ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_23 -> V_13 [ V_64 ] . V_23 = V_23 ;
F_152 ( & V_23 -> V_13 [ V_64 ] . V_68 ) ;
}
F_68 ( V_23 ) ;
}
static void F_153 ( struct V_19 * V_158 ,
struct V_19 * V_25 )
{
struct V_20 * V_21 ;
struct V_66 * V_69 ;
while ( ( V_69 = F_61 ( & V_158 -> V_68 ) ) ) {
V_21 = F_62 ( V_69 , struct V_20 , V_69 ) ;
F_123 ( F_22 ( V_21 ) ) ;
F_54 ( V_21 ) ;
F_100 ( V_21 , V_158 , V_159 , 0 ) ;
V_21 -> V_4 = V_25 ;
F_98 ( V_21 , V_25 ) ;
V_21 -> V_54 &= ~ V_159 ;
}
}
static void F_154 ( int V_160 )
{
struct V_3 * V_158 , * V_25 ;
int V_64 ;
F_123 ( F_155 ( V_160 ) ) ;
F_156 ( V_160 ) ;
F_157 () ;
V_158 = & F_20 ( V_38 , V_160 ) ;
V_25 = & F_65 ( V_38 ) ;
F_24 ( & V_25 -> V_24 ) ;
F_158 ( & V_158 -> V_24 , V_161 ) ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
F_153 ( & V_158 -> V_13 [ V_64 ] ,
& V_25 -> V_13 [ V_64 ] ) ;
}
F_23 ( & V_158 -> V_24 ) ;
F_23 ( & V_25 -> V_24 ) ;
F_127 () ;
F_159 () ;
}
static int F_160 ( struct V_162 * V_163 ,
unsigned long V_164 , void * V_165 )
{
int V_160 = ( long ) V_165 ;
switch ( V_164 ) {
case V_166 :
case V_167 :
F_151 ( V_160 ) ;
break;
#ifdef F_161
case V_168 :
case V_169 :
F_162 ( V_170 , & V_160 ) ;
break;
case V_171 :
case V_172 :
{
F_162 ( V_173 , & V_160 ) ;
F_154 ( V_160 ) ;
break;
}
#endif
default:
break;
}
return V_174 ;
}
void T_6 F_163 ( void )
{
F_160 ( & V_175 , ( unsigned long ) V_166 ,
( void * ) ( long ) F_18 () ) ;
F_164 ( & V_175 ) ;
#ifdef F_14
F_165 ( V_111 , F_129 ) ;
#endif
}
int T_7
F_166 ( T_2 * V_26 , unsigned long V_94 ,
const enum V_58 V_59 , int clock )
{
struct V_141 V_142 ;
if ( V_26 && ! V_26 -> V_29 ) {
F_142 ( V_147 ) ;
return 0 ;
}
if ( ! V_26 ) {
F_167 () ;
F_142 ( V_147 ) ;
return - V_176 ;
}
F_46 ( & V_142 . V_21 , clock , V_59 ) ;
F_106 ( & V_142 . V_21 , * V_26 , V_94 ) ;
F_135 ( & V_142 , V_85 ) ;
F_138 ( & V_142 . V_21 , V_59 ) ;
if ( ! F_139 ( & V_142 . V_21 ) )
V_142 . V_144 = NULL ;
if ( F_9 ( V_142 . V_144 ) )
F_167 () ;
F_33 ( & V_142 . V_21 ) ;
F_49 ( & V_142 . V_21 ) ;
F_142 ( V_147 ) ;
return ! V_142 . V_144 ? 0 : - V_176 ;
}
int T_7 F_168 ( T_2 * V_26 , unsigned long V_94 ,
const enum V_58 V_59 )
{
return F_166 ( V_26 , V_94 , V_59 ,
V_115 ) ;
}
int T_7 F_169 ( T_2 * V_26 ,
const enum V_58 V_59 )
{
return F_168 ( V_26 , 0 , V_59 ) ;
}
