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
static int F_13 ( int V_25 , int V_26 )
{
#ifdef F_14
if ( ! V_26 && F_15 () && F_16 ( V_25 ) )
return F_17 () ;
#endif
return V_25 ;
}
static int
F_18 ( struct V_20 * V_21 , struct V_19 * V_27 )
{
#ifdef F_19
T_2 V_28 ;
if ( ! V_27 -> V_23 -> V_29 )
return 0 ;
V_28 = F_20 ( F_21 ( V_21 ) , V_27 -> V_30 ) ;
return V_28 . V_31 <= V_27 -> V_23 -> V_32 . V_31 ;
#else
return 0 ;
#endif
}
static inline struct V_19 *
F_22 ( struct V_20 * V_21 , struct V_19 * V_4 ,
int V_26 )
{
struct V_19 * V_27 ;
struct V_3 * V_33 ;
int V_25 = F_23 () ;
int V_34 = F_13 ( V_25 , V_26 ) ;
int V_35 = V_4 -> V_36 ;
V_37:
V_33 = & F_24 ( V_38 , V_34 ) ;
V_27 = & V_33 -> V_13 [ V_35 ] ;
if ( V_4 != V_27 ) {
if ( F_25 ( F_26 ( V_21 ) ) )
return V_4 ;
V_21 -> V_4 = NULL ;
F_27 ( & V_4 -> V_23 -> V_24 ) ;
F_28 ( & V_27 -> V_23 -> V_24 ) ;
if ( V_34 != V_25 && F_18 ( V_21 , V_27 ) ) {
V_34 = V_25 ;
F_27 ( & V_27 -> V_23 -> V_24 ) ;
F_28 ( & V_4 -> V_23 -> V_24 ) ;
V_21 -> V_4 = V_4 ;
goto V_37;
}
V_21 -> V_4 = V_27 ;
}
return V_27 ;
}
static inline struct V_19 *
F_8 ( const struct V_20 * V_21 , unsigned long * V_22 )
{
struct V_19 * V_4 = V_21 -> V_4 ;
F_10 ( & V_4 -> V_23 -> V_24 , * V_22 ) ;
return V_4 ;
}
T_2 F_29 ( const T_2 V_39 , T_4 V_40 )
{
T_2 V_41 ;
if ( F_9 ( V_40 < V_42 ) ) {
V_41 . V_31 = V_40 ;
} else {
unsigned long V_43 = F_30 ( V_40 , V_42 ) ;
if ( F_25 ( V_40 > V_44 ) )
return ( T_2 ) { . V_31 = V_45 } ;
V_41 = F_7 ( ( long ) V_40 , V_43 ) ;
}
return F_6 ( V_39 , V_41 ) ;
}
T_2 F_31 ( const T_2 V_39 , T_4 V_40 )
{
T_2 V_41 ;
if ( F_9 ( V_40 < V_42 ) ) {
V_41 . V_31 = V_40 ;
} else {
unsigned long V_43 = F_30 ( V_40 , V_42 ) ;
V_41 = F_7 ( ( long ) V_40 , V_43 ) ;
}
return F_20 ( V_39 , V_41 ) ;
}
T_4 F_32 ( const T_2 V_39 , T_5 div )
{
T_4 V_46 ;
int V_47 = 0 ;
V_46 = F_33 ( V_39 ) ;
while ( div >> 32 ) {
V_47 ++ ;
div >>= 1 ;
}
V_46 >>= V_47 ;
F_30 ( V_46 , ( unsigned long ) div ) ;
return V_46 ;
}
T_2 F_34 ( const T_2 V_48 , const T_2 V_49 )
{
T_2 V_50 = F_6 ( V_48 , V_49 ) ;
if ( V_50 . V_31 < 0 || V_50 . V_31 < V_48 . V_31 || V_50 . V_31 < V_49 . V_31 )
V_50 = F_7 ( V_44 , 0 ) ;
return V_50 ;
}
static void * F_35 ( void * V_51 )
{
return ( (struct V_20 * ) V_51 ) -> V_52 ;
}
static int F_36 ( void * V_51 , enum V_53 V_54 )
{
struct V_20 * V_21 = V_51 ;
switch ( V_54 ) {
case V_55 :
F_37 ( V_21 ) ;
F_38 ( V_21 , & V_56 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_39 ( void * V_51 , enum V_53 V_54 )
{
switch ( V_54 ) {
case V_57 :
F_40 ( 1 ) ;
return 0 ;
case V_55 :
F_41 ( 1 ) ;
default:
return 0 ;
}
}
static int F_42 ( void * V_51 , enum V_53 V_54 )
{
struct V_20 * V_21 = V_51 ;
switch ( V_54 ) {
case V_55 :
F_37 ( V_21 ) ;
F_43 ( V_21 , & V_56 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_44 ( struct V_20 * V_21 )
{
F_38 ( V_21 , & V_56 ) ;
}
static inline void F_45 ( struct V_20 * V_21 )
{
F_46 ( V_21 , & V_56 ) ;
}
static inline void F_47 ( struct V_20 * V_21 )
{
F_48 ( V_21 , & V_56 ) ;
}
static inline void F_49 ( struct V_20 * V_21 )
{
F_43 ( V_21 , & V_56 ) ;
}
void F_50 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
F_51 ( V_21 , & V_56 ) ;
F_52 ( V_21 , V_1 , V_59 ) ;
}
void F_53 ( struct V_20 * V_21 )
{
F_43 ( V_21 , & V_56 ) ;
}
static inline void F_44 ( struct V_20 * V_21 ) { }
static inline void F_45 ( struct V_20 * V_21 ) { }
static inline void F_47 ( struct V_20 * V_21 ) { }
static inline void
F_54 ( struct V_20 * V_21 , T_1 V_60 ,
enum V_58 V_59 )
{
F_44 ( V_21 ) ;
F_55 ( V_21 , V_60 , V_59 ) ;
}
static inline void F_56 ( struct V_20 * V_21 )
{
F_45 ( V_21 ) ;
F_57 ( V_21 ) ;
}
static inline void F_58 ( struct V_20 * V_21 )
{
F_47 ( V_21 ) ;
F_59 ( V_21 ) ;
}
static int T_6 F_60 ( char * V_61 )
{
if ( ! strcmp ( V_61 , L_1 ) )
V_62 = 0 ;
else if ( ! strcmp ( V_61 , L_2 ) )
V_62 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_61 ( void )
{
return V_62 ;
}
static inline int F_62 ( void )
{
return F_63 ( V_38 . V_29 ) ;
}
static void
F_64 ( struct V_3 * V_23 , int V_63 )
{
int V_64 ;
struct V_19 * V_4 = V_23 -> V_13 ;
T_2 V_28 , V_32 ;
V_32 . V_31 = V_45 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ , V_4 ++ ) {
struct V_20 * V_21 ;
struct V_66 * V_67 ;
V_67 = F_65 ( & V_4 -> V_68 ) ;
if ( ! V_67 )
continue;
V_21 = F_66 ( V_67 , struct V_20 , V_69 ) ;
V_28 = F_20 ( F_21 ( V_21 ) , V_4 -> V_30 ) ;
if ( V_28 . V_31 < 0 )
V_28 . V_31 = 0 ;
if ( V_28 . V_31 < V_32 . V_31 )
V_32 = V_28 ;
}
if ( V_63 && V_32 . V_31 == V_23 -> V_32 . V_31 )
return;
V_23 -> V_32 . V_31 = V_32 . V_31 ;
if ( V_23 -> V_32 . V_31 != V_45 )
F_67 ( V_23 -> V_32 , 1 ) ;
}
static int F_68 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
struct V_3 * V_23 = & F_69 ( V_38 ) ;
T_2 V_28 = F_20 ( F_21 ( V_21 ) , V_4 -> V_30 ) ;
int V_50 ;
F_40 ( F_70 ( V_21 ) < 0 ) ;
if ( F_26 ( V_21 ) )
return 0 ;
if ( V_28 . V_31 < 0 )
return - V_70 ;
if ( V_28 . V_31 >= V_23 -> V_32 . V_31 )
return 0 ;
if ( V_23 -> V_71 )
return 0 ;
V_50 = F_67 ( V_28 , 0 ) ;
if ( ! F_71 ( V_50 ) )
V_23 -> V_32 = V_28 ;
return V_50 ;
}
static inline void F_72 ( struct V_3 * V_4 )
{
V_4 -> V_32 . V_31 = V_45 ;
V_4 -> V_29 = 0 ;
}
static inline int F_73 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
return V_4 -> V_23 -> V_29 && F_68 ( V_21 , V_4 ) ;
}
static inline T_2 F_74 ( struct V_3 * V_4 )
{
T_2 * V_72 = & V_4 -> V_13 [ V_14 ] . V_30 ;
T_2 * V_73 = & V_4 -> V_13 [ V_17 ] . V_30 ;
T_2 * V_74 = & V_4 -> V_13 [ V_18 ] . V_30 ;
return F_75 ( V_72 , V_73 , V_74 ) ;
}
static void F_76 ( void * V_75 )
{
struct V_3 * V_4 = & F_69 ( V_38 ) ;
if ( ! F_62 () )
return;
F_28 ( & V_4 -> V_24 ) ;
F_74 ( V_4 ) ;
F_64 ( V_4 , 0 ) ;
F_27 ( & V_4 -> V_24 ) ;
}
static int F_77 ( void )
{
int V_64 , V_34 = F_23 () ;
struct V_3 * V_4 = & F_24 ( V_38 , V_34 ) ;
unsigned long V_22 ;
if ( V_4 -> V_29 )
return 1 ;
F_78 ( V_22 ) ;
if ( F_79 () ) {
F_80 ( V_22 ) ;
F_81 ( V_76 L_3
L_4 , V_34 ) ;
return 0 ;
}
V_4 -> V_29 = 1 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
V_4 -> V_13 [ V_64 ] . V_77 = V_78 ;
F_82 () ;
F_76 ( NULL ) ;
F_80 ( V_22 ) ;
return 1 ;
}
static void F_83 ( struct V_79 * V_80 )
{
F_84 () ;
}
void F_85 ( void )
{
F_86 ( & V_81 ) ;
}
static inline int F_62 ( void ) { return 0 ; }
static inline int F_61 ( void ) { return 0 ; }
static inline int F_77 ( void ) { return 0 ; }
static inline void
F_64 ( struct V_3 * V_4 , int V_63 ) { }
static inline int F_73 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
return 0 ;
}
static inline void F_72 ( struct V_3 * V_4 ) { }
static inline void F_76 ( void * V_75 ) { }
void F_84 ( void )
{
#ifdef F_19
F_87 ( F_76 , NULL , 1 ) ;
#endif
F_88 () ;
}
void F_89 ( void )
{
F_90 ( ! F_91 () ,
V_82 L_5 ) ;
F_76 ( NULL ) ;
F_85 () ;
}
static inline void F_92 ( struct V_20 * V_21 )
{
#ifdef F_93
if ( V_21 -> V_83 )
return;
V_21 -> V_83 = F_94 ( 0 ) ;
memcpy ( V_21 -> V_84 , V_85 -> V_86 , V_87 ) ;
V_21 -> V_88 = V_85 -> V_89 ;
#endif
}
static inline void F_95 ( struct V_20 * V_21 )
{
#ifdef F_93
V_21 -> V_83 = NULL ;
#endif
}
static inline void F_96 ( struct V_20 * V_21 )
{
#ifdef F_93
if ( F_9 ( ! V_90 ) )
return;
F_97 ( V_21 , V_21 -> V_88 , V_21 -> V_83 ,
V_21 -> V_52 , V_21 -> V_84 , 0 ) ;
#endif
}
static inline
void F_98 ( const struct V_20 * V_21 , unsigned long * V_22 )
{
F_11 ( & V_21 -> V_4 -> V_23 -> V_24 , * V_22 ) ;
}
T_4 F_99 ( struct V_20 * V_21 , T_2 V_91 , T_2 V_92 )
{
T_4 V_93 = 1 ;
T_2 V_94 ;
V_94 = F_20 ( V_91 , F_21 ( V_21 ) ) ;
if ( V_94 . V_31 < 0 )
return 0 ;
if ( V_92 . V_31 < V_21 -> V_4 -> V_77 . V_31 )
V_92 . V_31 = V_21 -> V_4 -> V_77 . V_31 ;
if ( F_25 ( V_94 . V_31 >= V_92 . V_31 ) ) {
T_5 V_95 = F_33 ( V_92 ) ;
V_93 = F_32 ( V_94 , V_95 ) ;
F_100 ( V_21 , V_95 * V_93 ) ;
if ( F_70 ( V_21 ) > V_91 . V_31 )
return V_93 ;
V_93 ++ ;
}
F_101 ( V_21 , V_92 ) ;
return V_93 ;
}
static int F_102 ( struct V_20 * V_21 ,
struct V_19 * V_4 )
{
F_56 ( V_21 ) ;
F_103 ( & V_4 -> V_68 , & V_21 -> V_69 ) ;
V_4 -> V_23 -> V_96 |= 1 << V_4 -> V_36 ;
V_21 -> V_54 |= V_97 ;
return ( & V_21 -> V_69 == V_4 -> V_68 . V_67 ) ;
}
static void F_104 ( struct V_20 * V_21 ,
struct V_19 * V_4 ,
unsigned long V_98 , int V_99 )
{
struct V_66 * V_100 ;
if ( ! ( V_21 -> V_54 & V_97 ) )
goto V_101;
V_100 = F_65 ( & V_4 -> V_68 ) ;
F_105 ( & V_4 -> V_68 , & V_21 -> V_69 ) ;
if ( & V_21 -> V_69 == V_100 ) {
#ifdef F_19
if ( V_99 && F_62 () ) {
T_2 V_28 ;
V_28 = F_20 ( F_21 ( V_21 ) ,
V_4 -> V_30 ) ;
if ( V_4 -> V_23 -> V_32 . V_31 == V_28 . V_31 )
F_64 ( V_4 -> V_23 , 1 ) ;
}
#endif
}
if ( ! F_65 ( & V_4 -> V_68 ) )
V_4 -> V_23 -> V_96 &= ~ ( 1 << V_4 -> V_36 ) ;
V_101:
V_21 -> V_54 = V_98 ;
}
static inline int
F_106 ( struct V_20 * V_21 , struct V_19 * V_4 )
{
if ( F_107 ( V_21 ) ) {
unsigned long V_54 ;
int V_99 ;
F_58 ( V_21 ) ;
F_95 ( V_21 ) ;
V_99 = V_4 -> V_23 == & F_69 ( V_38 ) ;
V_54 = V_21 -> V_54 & V_102 ;
F_104 ( V_21 , V_4 , V_54 , V_99 ) ;
return 1 ;
}
return 0 ;
}
int F_108 ( struct V_20 * V_21 , T_2 V_103 ,
unsigned long V_104 , const enum V_58 V_59 ,
int V_105 )
{
struct V_19 * V_4 , * V_27 ;
unsigned long V_22 ;
int V_106 , V_107 ;
V_4 = F_8 ( V_21 , & V_22 ) ;
V_106 = F_106 ( V_21 , V_4 ) ;
V_27 = F_22 ( V_21 , V_4 , V_59 & V_108 ) ;
if ( V_59 & V_109 ) {
V_103 = F_34 ( V_103 , V_27 -> V_110 () ) ;
#ifdef F_109
V_103 = F_34 ( V_103 , V_4 -> V_77 ) ;
#endif
}
F_110 ( V_21 , V_103 , V_104 ) ;
F_92 ( V_21 ) ;
V_107 = F_102 ( V_21 , V_27 ) ;
if ( V_107 && V_27 -> V_23 == & F_69 ( V_38 )
&& F_73 ( V_21 , V_27 ) ) {
if ( V_105 ) {
F_27 ( & V_27 -> V_23 -> V_24 ) ;
F_111 ( V_111 ) ;
F_80 ( V_22 ) ;
return V_106 ;
} else {
F_112 ( V_111 ) ;
}
}
F_98 ( V_21 , & V_22 ) ;
return V_106 ;
}
int F_113 ( struct V_20 * V_21 , T_2 V_103 ,
unsigned long V_104 , const enum V_58 V_59 )
{
return F_108 ( V_21 , V_103 , V_104 , V_59 , 1 ) ;
}
int
F_114 ( struct V_20 * V_21 , T_2 V_103 , const enum V_58 V_59 )
{
return F_108 ( V_21 , V_103 , 0 , V_59 , 1 ) ;
}
int F_115 ( struct V_20 * V_21 )
{
struct V_19 * V_4 ;
unsigned long V_22 ;
int V_106 = - 1 ;
V_4 = F_8 ( V_21 , & V_22 ) ;
if ( ! F_26 ( V_21 ) )
V_106 = F_106 ( V_21 , V_4 ) ;
F_98 ( V_21 , & V_22 ) ;
return V_106 ;
}
int F_37 ( struct V_20 * V_21 )
{
for (; ; ) {
int V_106 = F_115 ( V_21 ) ;
if ( V_106 >= 0 )
return V_106 ;
F_12 () ;
}
}
T_2 F_116 ( const struct V_20 * V_21 )
{
unsigned long V_22 ;
T_2 V_43 ;
F_8 ( V_21 , & V_22 ) ;
V_43 = F_117 ( V_21 ) ;
F_98 ( V_21 , & V_22 ) ;
return V_43 ;
}
T_2 F_118 ( void )
{
struct V_3 * V_23 = & F_69 ( V_38 ) ;
struct V_19 * V_4 = V_23 -> V_13 ;
T_2 V_94 , V_112 = { . V_31 = V_45 } ;
unsigned long V_22 ;
int V_64 ;
F_10 ( & V_23 -> V_24 , V_22 ) ;
if ( ! F_62 () ) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ , V_4 ++ ) {
struct V_20 * V_21 ;
struct V_66 * V_67 ;
V_67 = F_65 ( & V_4 -> V_68 ) ;
if ( ! V_67 )
continue;
V_21 = F_66 ( V_67 , struct V_20 , V_69 ) ;
V_94 . V_31 = F_70 ( V_21 ) ;
V_94 = F_20 ( V_94 , V_4 -> V_110 () ) ;
if ( V_94 . V_31 < V_112 . V_31 )
V_112 . V_31 = V_94 . V_31 ;
}
}
F_11 ( & V_23 -> V_24 , V_22 ) ;
if ( V_112 . V_31 < 0 )
V_112 . V_31 = 0 ;
return V_112 ;
}
static void F_52 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
struct V_3 * V_23 ;
int V_4 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_23 = & F_119 ( V_38 ) ;
if ( V_1 == V_113 && V_59 != V_114 )
V_1 = V_115 ;
V_4 = F_1 ( V_1 ) ;
V_21 -> V_4 = & V_23 -> V_13 [ V_4 ] ;
F_120 ( & V_21 -> V_69 ) ;
#ifdef F_93
V_21 -> V_83 = NULL ;
V_21 -> V_88 = - 1 ;
memset ( V_21 -> V_84 , 0 , V_87 ) ;
#endif
}
void F_121 ( struct V_20 * V_21 , T_1 V_1 ,
enum V_58 V_59 )
{
F_54 ( V_21 , V_1 , V_59 ) ;
F_52 ( V_21 , V_1 , V_59 ) ;
}
int F_122 ( const T_1 V_116 , struct V_8 * V_117 )
{
struct V_3 * V_23 ;
int V_4 = F_1 ( V_116 ) ;
V_23 = & F_119 ( V_38 ) ;
* V_117 = F_123 ( V_23 -> V_13 [ V_4 ] . V_77 ) ;
return 0 ;
}
static void F_124 ( struct V_20 * V_21 , T_2 * V_91 )
{
struct V_19 * V_4 = V_21 -> V_4 ;
struct V_3 * V_23 = V_4 -> V_23 ;
enum V_118 ( * V_119 ) ( struct V_20 * ) ;
int V_120 ;
F_41 ( ! F_91 () ) ;
F_58 ( V_21 ) ;
F_104 ( V_21 , V_4 , V_102 , 0 ) ;
F_96 ( V_21 ) ;
V_119 = V_21 -> V_52 ;
F_27 ( & V_23 -> V_24 ) ;
F_125 ( V_21 , V_91 ) ;
V_120 = V_119 ( V_21 ) ;
F_126 ( V_21 ) ;
F_28 ( & V_23 -> V_24 ) ;
if ( V_120 != V_121 ) {
F_127 ( V_21 -> V_54 != V_102 ) ;
F_102 ( V_21 , V_4 ) ;
}
F_40 ( ! ( V_21 -> V_54 & V_102 ) ) ;
V_21 -> V_54 &= ~ V_102 ;
}
void F_128 ( struct V_122 * V_123 )
{
struct V_3 * V_23 = & F_69 ( V_38 ) ;
T_2 V_32 , V_91 , V_124 , V_94 ;
int V_64 , V_125 = 0 ;
F_127 ( ! V_23 -> V_29 ) ;
V_23 -> V_126 ++ ;
V_123 -> V_127 . V_31 = V_45 ;
F_28 ( & V_23 -> V_24 ) ;
V_124 = V_91 = F_74 ( V_23 ) ;
V_128:
V_32 . V_31 = V_45 ;
V_23 -> V_32 . V_31 = V_45 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
struct V_19 * V_4 ;
struct V_66 * V_69 ;
T_2 V_129 ;
if ( ! ( V_23 -> V_96 & ( 1 << V_64 ) ) )
continue;
V_4 = V_23 -> V_13 + V_64 ;
V_129 = F_6 ( V_91 , V_4 -> V_30 ) ;
while ( ( V_69 = F_65 ( & V_4 -> V_68 ) ) ) {
struct V_20 * V_21 ;
V_21 = F_66 ( V_69 , struct V_20 , V_69 ) ;
if ( V_129 . V_31 < F_129 ( V_21 ) ) {
T_2 V_28 ;
V_28 = F_20 ( F_21 ( V_21 ) ,
V_4 -> V_30 ) ;
if ( V_28 . V_31 < 0 )
V_28 . V_31 = V_45 ;
if ( V_28 . V_31 < V_32 . V_31 )
V_32 = V_28 ;
break;
}
F_124 ( V_21 , & V_129 ) ;
}
}
V_23 -> V_32 = V_32 ;
F_27 ( & V_23 -> V_24 ) ;
if ( V_32 . V_31 == V_45 ||
! F_67 ( V_32 , 0 ) ) {
V_23 -> V_71 = 0 ;
return;
}
F_28 ( & V_23 -> V_24 ) ;
V_91 = F_74 ( V_23 ) ;
V_23 -> V_130 ++ ;
if ( ++ V_125 < 3 )
goto V_128;
V_23 -> V_131 ++ ;
V_23 -> V_71 = 1 ;
F_27 ( & V_23 -> V_24 ) ;
V_94 = F_20 ( V_91 , V_124 ) ;
if ( V_94 . V_31 > V_23 -> V_132 . V_31 )
V_23 -> V_132 = V_94 ;
if ( V_94 . V_31 > 100 * V_133 )
V_32 = F_29 ( V_91 , 100 * V_133 ) ;
else
V_32 = F_6 ( V_91 , V_94 ) ;
F_67 ( V_32 , 1 ) ;
F_130 ( V_76 L_6 ,
F_33 ( V_94 ) ) ;
}
static void F_131 ( void )
{
struct V_134 * V_135 ;
if ( ! F_62 () )
return;
V_135 = & F_69 ( V_136 ) ;
if ( V_135 && V_135 -> V_137 )
F_128 ( V_135 -> V_137 ) ;
}
void F_132 ( void )
{
unsigned long V_22 ;
F_78 ( V_22 ) ;
F_131 () ;
F_80 ( V_22 ) ;
}
static void F_133 ( struct V_138 * V_139 )
{
F_132 () ;
}
static inline void F_131 ( void ) { }
void F_134 ( void )
{
if ( F_62 () )
return;
if ( F_135 ( ! F_61 () ) )
F_77 () ;
}
void F_136 ( void )
{
struct V_66 * V_69 ;
struct V_3 * V_23 = & F_69 ( V_38 ) ;
struct V_19 * V_4 ;
int V_36 , V_140 = 1 ;
if ( F_62 () )
return;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ ) {
V_4 = & V_23 -> V_13 [ V_36 ] ;
if ( ! F_65 ( & V_4 -> V_68 ) )
continue;
if ( V_140 ) {
F_2 ( V_23 ) ;
V_140 = 0 ;
}
F_28 ( & V_23 -> V_24 ) ;
while ( ( V_69 = F_65 ( & V_4 -> V_68 ) ) ) {
struct V_20 * V_21 ;
V_21 = F_66 ( V_69 , struct V_20 , V_69 ) ;
if ( V_4 -> V_15 . V_31 <=
F_70 ( V_21 ) )
break;
F_124 ( V_21 , & V_4 -> V_15 ) ;
}
F_27 ( & V_23 -> V_24 ) ;
}
}
static enum V_118 F_137 ( struct V_20 * V_21 )
{
struct V_141 * V_142 =
F_66 ( V_21 , struct V_141 , V_21 ) ;
struct V_143 * V_144 = V_142 -> V_144 ;
V_142 -> V_144 = NULL ;
if ( V_144 )
F_138 ( V_144 ) ;
return V_121 ;
}
void F_139 ( struct V_141 * V_145 , struct V_143 * V_144 )
{
V_145 -> V_21 . V_52 = F_137 ;
V_145 -> V_144 = V_144 ;
}
static int T_7 F_140 ( struct V_141 * V_142 , enum V_58 V_59 )
{
F_139 ( V_142 , V_85 ) ;
do {
F_141 ( V_146 ) ;
F_142 ( & V_142 -> V_21 , V_59 ) ;
if ( ! F_143 ( & V_142 -> V_21 ) )
V_142 -> V_144 = NULL ;
if ( F_9 ( V_142 -> V_144 ) )
F_144 () ;
F_37 ( & V_142 -> V_21 ) ;
V_59 = V_114 ;
} while ( V_142 -> V_144 && ! F_145 ( V_85 ) );
F_146 ( V_147 ) ;
return V_142 -> V_144 == NULL ;
}
static int F_147 ( struct V_20 * V_21 , struct V_8 T_8 * V_148 )
{
struct V_8 V_149 ;
T_2 V_43 ;
V_43 = F_117 ( V_21 ) ;
if ( V_43 . V_31 <= 0 )
return 0 ;
V_149 = F_123 ( V_43 ) ;
if ( F_148 ( V_148 , & V_149 , sizeof( * V_148 ) ) )
return - V_150 ;
return 1 ;
}
long T_7 F_149 ( struct V_151 * V_120 )
{
struct V_141 V_142 ;
struct V_8 T_8 * V_148 ;
int V_106 = 0 ;
F_50 ( & V_142 . V_21 , V_120 -> V_152 . V_60 ,
V_114 ) ;
F_150 ( & V_142 . V_21 , V_120 -> V_152 . V_28 ) ;
if ( F_140 ( & V_142 , V_114 ) )
goto V_101;
V_148 = V_120 -> V_152 . V_148 ;
if ( V_148 ) {
V_106 = F_147 ( & V_142 . V_21 , V_148 ) ;
if ( V_106 <= 0 )
goto V_101;
}
V_106 = - V_153 ;
V_101:
F_53 ( & V_142 . V_21 ) ;
return V_106 ;
}
long F_151 ( struct V_8 * V_154 , struct V_8 T_8 * V_148 ,
const enum V_58 V_59 , const T_1 V_60 )
{
struct V_151 * V_120 ;
struct V_141 V_142 ;
int V_106 = 0 ;
unsigned long V_155 ;
V_155 = V_85 -> V_156 ;
if ( F_152 ( V_85 ) || F_153 ( V_85 ) )
V_155 = 0 ;
F_50 ( & V_142 . V_21 , V_60 , V_59 ) ;
F_110 ( & V_142 . V_21 , F_5 ( * V_154 ) , V_155 ) ;
if ( F_140 ( & V_142 , V_59 ) )
goto V_101;
if ( V_59 == V_114 ) {
V_106 = - V_157 ;
goto V_101;
}
if ( V_148 ) {
V_106 = F_147 ( & V_142 . V_21 , V_148 ) ;
if ( V_106 <= 0 )
goto V_101;
}
V_120 = & F_154 () -> V_151 ;
V_120 -> V_119 = F_149 ;
V_120 -> V_152 . V_60 = V_142 . V_21 . V_4 -> V_60 ;
V_120 -> V_152 . V_148 = V_148 ;
V_120 -> V_152 . V_28 = F_70 ( & V_142 . V_21 ) ;
V_106 = - V_153 ;
V_101:
F_53 ( & V_142 . V_21 ) ;
return V_106 ;
}
static void F_155 ( int V_34 )
{
struct V_3 * V_23 = & F_24 ( V_38 , V_34 ) ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_23 -> V_13 [ V_64 ] . V_23 = V_23 ;
F_156 ( & V_23 -> V_13 [ V_64 ] . V_68 ) ;
}
F_72 ( V_23 ) ;
}
static void F_157 ( struct V_19 * V_158 ,
struct V_19 * V_27 )
{
struct V_20 * V_21 ;
struct V_66 * V_69 ;
while ( ( V_69 = F_65 ( & V_158 -> V_68 ) ) ) {
V_21 = F_66 ( V_69 , struct V_20 , V_69 ) ;
F_127 ( F_26 ( V_21 ) ) ;
F_58 ( V_21 ) ;
F_104 ( V_21 , V_158 , V_159 , 0 ) ;
V_21 -> V_4 = V_27 ;
F_102 ( V_21 , V_27 ) ;
V_21 -> V_54 &= ~ V_159 ;
}
}
static void F_158 ( int V_160 )
{
struct V_3 * V_158 , * V_27 ;
int V_64 ;
F_127 ( F_159 ( V_160 ) ) ;
F_160 ( V_160 ) ;
F_161 () ;
V_158 = & F_24 ( V_38 , V_160 ) ;
V_27 = & F_69 ( V_38 ) ;
F_28 ( & V_27 -> V_24 ) ;
F_162 ( & V_158 -> V_24 , V_161 ) ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
F_157 ( & V_158 -> V_13 [ V_64 ] ,
& V_27 -> V_13 [ V_64 ] ) ;
}
F_27 ( & V_158 -> V_24 ) ;
F_27 ( & V_27 -> V_24 ) ;
F_131 () ;
F_163 () ;
}
static int F_164 ( struct V_162 * V_163 ,
unsigned long V_164 , void * V_165 )
{
int V_160 = ( long ) V_165 ;
switch ( V_164 ) {
case V_166 :
case V_167 :
F_155 ( V_160 ) ;
break;
#ifdef F_165
case V_168 :
case V_169 :
F_166 ( V_170 , & V_160 ) ;
break;
case V_171 :
case V_172 :
{
F_166 ( V_173 , & V_160 ) ;
F_158 ( V_160 ) ;
break;
}
#endif
default:
break;
}
return V_174 ;
}
void T_6 F_167 ( void )
{
F_164 ( & V_175 , ( unsigned long ) V_166 ,
( void * ) ( long ) F_23 () ) ;
F_168 ( & V_175 ) ;
#ifdef F_19
F_169 ( V_111 , F_133 ) ;
#endif
}
int T_7
F_170 ( T_2 * V_28 , unsigned long V_94 ,
const enum V_58 V_59 , int clock )
{
struct V_141 V_142 ;
if ( V_28 && ! V_28 -> V_31 ) {
F_146 ( V_147 ) ;
return 0 ;
}
if ( ! V_28 ) {
F_171 () ;
F_146 ( V_147 ) ;
return - V_176 ;
}
F_50 ( & V_142 . V_21 , clock , V_59 ) ;
F_110 ( & V_142 . V_21 , * V_28 , V_94 ) ;
F_139 ( & V_142 , V_85 ) ;
F_142 ( & V_142 . V_21 , V_59 ) ;
if ( ! F_143 ( & V_142 . V_21 ) )
V_142 . V_144 = NULL ;
if ( F_9 ( V_142 . V_144 ) )
F_171 () ;
F_37 ( & V_142 . V_21 ) ;
F_53 ( & V_142 . V_21 ) ;
F_146 ( V_147 ) ;
return ! V_142 . V_144 ? 0 : - V_176 ;
}
int T_7 F_172 ( T_2 * V_28 , unsigned long V_94 ,
const enum V_58 V_59 )
{
return F_170 ( V_28 , V_94 , V_59 ,
V_115 ) ;
}
int T_7 F_173 ( T_2 * V_28 ,
const enum V_58 V_59 )
{
return F_172 ( V_28 , 0 , V_59 ) ;
}
