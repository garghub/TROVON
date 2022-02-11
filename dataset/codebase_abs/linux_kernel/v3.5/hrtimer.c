static inline int F_1 ( T_1 V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( struct V_3 * V_4 )
{
T_2 V_5 , V_6 , V_7 ;
struct V_8 V_9 , V_10 , V_11 ;
F_3 ( & V_9 , & V_10 , & V_11 ) ;
V_5 = F_4 ( V_9 ) ;
V_6 = F_5 ( V_5 , F_4 ( V_10 ) ) ;
V_7 = F_5 ( V_6 , F_4 ( V_11 ) ) ;
V_4 -> V_12 [ V_13 ] . V_14 = V_5 ;
V_4 -> V_12 [ V_15 ] . V_14 = V_6 ;
V_4 -> V_12 [ V_16 ] . V_14 = V_7 ;
}
static
struct V_17 * F_6 ( const struct V_18 * V_19 ,
unsigned long * V_20 )
{
struct V_17 * V_4 ;
for (; ; ) {
V_4 = V_19 -> V_4 ;
if ( F_7 ( V_4 != NULL ) ) {
F_8 ( & V_4 -> V_21 -> V_22 , * V_20 ) ;
if ( F_7 ( V_4 == V_19 -> V_4 ) )
return V_4 ;
F_9 ( & V_4 -> V_21 -> V_22 , * V_20 ) ;
}
F_10 () ;
}
}
static int F_11 ( int V_23 , int V_24 )
{
#ifdef F_12
if ( ! V_24 && F_13 () && F_14 ( V_23 ) )
return F_15 () ;
#endif
return V_23 ;
}
static int
F_16 ( struct V_18 * V_19 , struct V_17 * V_25 )
{
#ifdef F_17
T_2 V_26 ;
if ( ! V_25 -> V_21 -> V_27 )
return 0 ;
V_26 = F_18 ( F_19 ( V_19 ) , V_25 -> V_28 ) ;
return V_26 . V_29 <= V_25 -> V_21 -> V_30 . V_29 ;
#else
return 0 ;
#endif
}
static inline struct V_17 *
F_20 ( struct V_18 * V_19 , struct V_17 * V_4 ,
int V_24 )
{
struct V_17 * V_25 ;
struct V_3 * V_31 ;
int V_23 = F_21 () ;
int V_32 = F_11 ( V_23 , V_24 ) ;
int V_33 = V_4 -> V_34 ;
V_35:
V_31 = & F_22 ( V_36 , V_32 ) ;
V_25 = & V_31 -> V_12 [ V_33 ] ;
if ( V_4 != V_25 ) {
if ( F_23 ( F_24 ( V_19 ) ) )
return V_4 ;
V_19 -> V_4 = NULL ;
F_25 ( & V_4 -> V_21 -> V_22 ) ;
F_26 ( & V_25 -> V_21 -> V_22 ) ;
if ( V_32 != V_23 && F_16 ( V_19 , V_25 ) ) {
V_32 = V_23 ;
F_25 ( & V_25 -> V_21 -> V_22 ) ;
F_26 ( & V_4 -> V_21 -> V_22 ) ;
V_19 -> V_4 = V_4 ;
goto V_35;
}
V_19 -> V_4 = V_25 ;
}
return V_25 ;
}
static inline struct V_17 *
F_6 ( const struct V_18 * V_19 , unsigned long * V_20 )
{
struct V_17 * V_4 = V_19 -> V_4 ;
F_8 ( & V_4 -> V_21 -> V_22 , * V_20 ) ;
return V_4 ;
}
T_2 F_27 ( const T_2 V_37 , T_3 V_38 )
{
T_2 V_39 ;
if ( F_7 ( V_38 < V_40 ) ) {
V_39 . V_29 = V_38 ;
} else {
unsigned long V_41 = F_28 ( V_38 , V_40 ) ;
V_39 = F_29 ( ( long ) V_38 , V_41 ) ;
}
return F_5 ( V_37 , V_39 ) ;
}
T_2 F_30 ( const T_2 V_37 , T_3 V_38 )
{
T_2 V_39 ;
if ( F_7 ( V_38 < V_40 ) ) {
V_39 . V_29 = V_38 ;
} else {
unsigned long V_41 = F_28 ( V_38 , V_40 ) ;
V_39 = F_29 ( ( long ) V_38 , V_41 ) ;
}
return F_18 ( V_37 , V_39 ) ;
}
T_3 F_31 ( const T_2 V_37 , T_4 div )
{
T_3 V_42 ;
int V_43 = 0 ;
V_42 = F_32 ( V_37 ) ;
while ( div >> 32 ) {
V_43 ++ ;
div >>= 1 ;
}
V_42 >>= V_43 ;
F_28 ( V_42 , ( unsigned long ) div ) ;
return V_42 ;
}
T_2 F_33 ( const T_2 V_44 , const T_2 V_45 )
{
T_2 V_46 = F_5 ( V_44 , V_45 ) ;
if ( V_46 . V_29 < 0 || V_46 . V_29 < V_44 . V_29 || V_46 . V_29 < V_45 . V_29 )
V_46 = F_29 ( V_47 , 0 ) ;
return V_46 ;
}
static void * F_34 ( void * V_48 )
{
return ( (struct V_18 * ) V_48 ) -> V_49 ;
}
static int F_35 ( void * V_48 , enum V_50 V_51 )
{
struct V_18 * V_19 = V_48 ;
switch ( V_51 ) {
case V_52 :
F_36 ( V_19 ) ;
F_37 ( V_19 , & V_53 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_38 ( void * V_48 , enum V_50 V_51 )
{
switch ( V_51 ) {
case V_54 :
F_39 ( 1 ) ;
return 0 ;
case V_52 :
F_40 ( 1 ) ;
default:
return 0 ;
}
}
static int F_41 ( void * V_48 , enum V_50 V_51 )
{
struct V_18 * V_19 = V_48 ;
switch ( V_51 ) {
case V_52 :
F_36 ( V_19 ) ;
F_42 ( V_19 , & V_53 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_43 ( struct V_18 * V_19 )
{
F_37 ( V_19 , & V_53 ) ;
}
static inline void F_44 ( struct V_18 * V_19 )
{
F_45 ( V_19 , & V_53 ) ;
}
static inline void F_46 ( struct V_18 * V_19 )
{
F_47 ( V_19 , & V_53 ) ;
}
static inline void F_48 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_53 ) ;
}
void F_49 ( struct V_18 * V_19 , T_1 V_1 ,
enum V_55 V_56 )
{
F_50 ( V_19 , & V_53 ) ;
F_51 ( V_19 , V_1 , V_56 ) ;
}
void F_52 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_53 ) ;
}
static inline void F_43 ( struct V_18 * V_19 ) { }
static inline void F_44 ( struct V_18 * V_19 ) { }
static inline void F_46 ( struct V_18 * V_19 ) { }
static inline void
F_53 ( struct V_18 * V_19 , T_1 V_57 ,
enum V_55 V_56 )
{
F_43 ( V_19 ) ;
F_54 ( V_19 , V_57 , V_56 ) ;
}
static inline void F_55 ( struct V_18 * V_19 )
{
F_44 ( V_19 ) ;
F_56 ( V_19 ) ;
}
static inline void F_57 ( struct V_18 * V_19 )
{
F_46 ( V_19 ) ;
F_58 ( V_19 ) ;
}
static int T_5 F_59 ( char * V_58 )
{
if ( ! strcmp ( V_58 , L_1 ) )
V_59 = 0 ;
else if ( ! strcmp ( V_58 , L_2 ) )
V_59 = 1 ;
else
return 0 ;
return 1 ;
}
static inline int F_60 ( void )
{
return V_59 ;
}
static inline int F_61 ( void )
{
return F_62 ( V_36 . V_27 ) ;
}
static void
F_63 ( struct V_3 * V_21 , int V_60 )
{
int V_61 ;
struct V_17 * V_4 = V_21 -> V_12 ;
T_2 V_26 , V_30 ;
V_30 . V_29 = V_62 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ , V_4 ++ ) {
struct V_18 * V_19 ;
struct V_64 * V_65 ;
V_65 = F_64 ( & V_4 -> V_66 ) ;
if ( ! V_65 )
continue;
V_19 = F_65 ( V_65 , struct V_18 , V_67 ) ;
V_26 = F_18 ( F_19 ( V_19 ) , V_4 -> V_28 ) ;
if ( V_26 . V_29 < 0 )
V_26 . V_29 = 0 ;
if ( V_26 . V_29 < V_30 . V_29 )
V_30 = V_26 ;
}
if ( V_60 && V_30 . V_29 == V_21 -> V_30 . V_29 )
return;
V_21 -> V_30 . V_29 = V_30 . V_29 ;
if ( V_21 -> V_30 . V_29 != V_62 )
F_66 ( V_21 -> V_30 , 1 ) ;
}
static int F_67 ( struct V_18 * V_19 ,
struct V_17 * V_4 )
{
struct V_3 * V_21 = & F_68 ( V_36 ) ;
T_2 V_26 = F_18 ( F_19 ( V_19 ) , V_4 -> V_28 ) ;
int V_46 ;
F_39 ( F_69 ( V_19 ) < 0 ) ;
if ( F_24 ( V_19 ) )
return 0 ;
if ( V_26 . V_29 < 0 )
return - V_68 ;
if ( V_26 . V_29 >= V_21 -> V_30 . V_29 )
return 0 ;
if ( V_21 -> V_69 )
return 0 ;
V_46 = F_66 ( V_26 , 0 ) ;
if ( ! F_70 ( V_46 ) )
V_21 -> V_30 = V_26 ;
return V_46 ;
}
static inline void F_71 ( struct V_3 * V_4 )
{
V_4 -> V_30 . V_29 = V_62 ;
V_4 -> V_27 = 0 ;
}
static inline int F_72 ( struct V_18 * V_19 ,
struct V_17 * V_4 ,
int V_70 )
{
if ( V_4 -> V_21 -> V_27 && F_67 ( V_19 , V_4 ) ) {
if ( V_70 ) {
F_25 ( & V_4 -> V_21 -> V_22 ) ;
F_73 ( V_71 ) ;
F_26 ( & V_4 -> V_21 -> V_22 ) ;
} else
F_74 ( V_71 ) ;
return 1 ;
}
return 0 ;
}
static inline T_2 F_75 ( struct V_3 * V_4 )
{
T_2 * V_72 = & V_4 -> V_12 [ V_13 ] . V_28 ;
T_2 * V_73 = & V_4 -> V_12 [ V_16 ] . V_28 ;
return F_76 ( V_72 , V_73 ) ;
}
static void F_77 ( void * V_74 )
{
struct V_3 * V_4 = & F_68 ( V_36 ) ;
if ( ! F_61 () )
return;
F_26 ( & V_4 -> V_22 ) ;
F_75 ( V_4 ) ;
F_63 ( V_4 , 0 ) ;
F_25 ( & V_4 -> V_22 ) ;
}
static int F_78 ( void )
{
int V_61 , V_32 = F_21 () ;
struct V_3 * V_4 = & F_22 ( V_36 , V_32 ) ;
unsigned long V_20 ;
if ( V_4 -> V_27 )
return 1 ;
F_79 ( V_20 ) ;
if ( F_80 () ) {
F_81 ( V_20 ) ;
F_82 ( V_75 L_3
L_4 , V_32 ) ;
return 0 ;
}
V_4 -> V_27 = 1 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
V_4 -> V_12 [ V_61 ] . V_76 = V_77 ;
F_83 () ;
F_77 ( NULL ) ;
F_81 ( V_20 ) ;
return 1 ;
}
void F_84 ( void )
{
struct V_3 * V_21 = & F_68 ( V_36 ) ;
V_21 -> V_78 = 1 ;
F_74 ( V_71 ) ;
}
static inline int F_61 ( void ) { return 0 ; }
static inline int F_60 ( void ) { return 0 ; }
static inline int F_78 ( void ) { return 0 ; }
static inline void
F_63 ( struct V_3 * V_4 , int V_60 ) { }
static inline int F_72 ( struct V_18 * V_19 ,
struct V_17 * V_4 ,
int V_70 )
{
return 0 ;
}
static inline void F_71 ( struct V_3 * V_4 ) { }
static inline void F_77 ( void * V_74 ) { }
void V_78 ( void )
{
#ifdef F_17
F_85 ( F_77 , NULL , 1 ) ;
#endif
F_86 () ;
}
void F_87 ( void )
{
F_88 ( ! F_89 () ,
V_79 L_5 ) ;
F_77 ( NULL ) ;
F_86 () ;
}
static inline void F_90 ( struct V_18 * V_19 )
{
#ifdef F_91
if ( V_19 -> V_80 )
return;
V_19 -> V_80 = F_92 ( 0 ) ;
memcpy ( V_19 -> V_81 , V_82 -> V_83 , V_84 ) ;
V_19 -> V_85 = V_82 -> V_86 ;
#endif
}
static inline void F_93 ( struct V_18 * V_19 )
{
#ifdef F_91
V_19 -> V_80 = NULL ;
#endif
}
static inline void F_94 ( struct V_18 * V_19 )
{
#ifdef F_91
if ( F_7 ( ! V_87 ) )
return;
F_95 ( V_19 , V_19 -> V_85 , V_19 -> V_80 ,
V_19 -> V_49 , V_19 -> V_81 , 0 ) ;
#endif
}
static inline
void F_96 ( const struct V_18 * V_19 , unsigned long * V_20 )
{
F_9 ( & V_19 -> V_4 -> V_21 -> V_22 , * V_20 ) ;
}
T_3 F_97 ( struct V_18 * V_19 , T_2 V_88 , T_2 V_89 )
{
T_3 V_90 = 1 ;
T_2 V_91 ;
V_91 = F_18 ( V_88 , F_19 ( V_19 ) ) ;
if ( V_91 . V_29 < 0 )
return 0 ;
if ( V_89 . V_29 < V_19 -> V_4 -> V_76 . V_29 )
V_89 . V_29 = V_19 -> V_4 -> V_76 . V_29 ;
if ( F_23 ( V_91 . V_29 >= V_89 . V_29 ) ) {
T_4 V_92 = F_32 ( V_89 ) ;
V_90 = F_31 ( V_91 , V_92 ) ;
F_98 ( V_19 , V_92 * V_90 ) ;
if ( F_69 ( V_19 ) > V_88 . V_29 )
return V_90 ;
V_90 ++ ;
}
F_99 ( V_19 , V_89 ) ;
return V_90 ;
}
static int F_100 ( struct V_18 * V_19 ,
struct V_17 * V_4 )
{
F_55 ( V_19 ) ;
F_101 ( & V_4 -> V_66 , & V_19 -> V_67 ) ;
V_4 -> V_21 -> V_93 |= 1 << V_4 -> V_34 ;
V_19 -> V_51 |= V_94 ;
return ( & V_19 -> V_67 == V_4 -> V_66 . V_65 ) ;
}
static void F_102 ( struct V_18 * V_19 ,
struct V_17 * V_4 ,
unsigned long V_95 , int V_96 )
{
struct V_64 * V_97 ;
if ( ! ( V_19 -> V_51 & V_94 ) )
goto V_98;
V_97 = F_64 ( & V_4 -> V_66 ) ;
F_103 ( & V_4 -> V_66 , & V_19 -> V_67 ) ;
if ( & V_19 -> V_67 == V_97 ) {
#ifdef F_17
if ( V_96 && F_61 () ) {
T_2 V_26 ;
V_26 = F_18 ( F_19 ( V_19 ) ,
V_4 -> V_28 ) ;
if ( V_4 -> V_21 -> V_30 . V_29 == V_26 . V_29 )
F_63 ( V_4 -> V_21 , 1 ) ;
}
#endif
}
if ( ! F_64 ( & V_4 -> V_66 ) )
V_4 -> V_21 -> V_93 &= ~ ( 1 << V_4 -> V_34 ) ;
V_98:
V_19 -> V_51 = V_95 ;
}
static inline int
F_104 ( struct V_18 * V_19 , struct V_17 * V_4 )
{
if ( F_105 ( V_19 ) ) {
unsigned long V_51 ;
int V_96 ;
F_57 ( V_19 ) ;
F_93 ( V_19 ) ;
V_96 = V_4 -> V_21 == & F_68 ( V_36 ) ;
V_51 = V_19 -> V_51 & V_99 ;
F_102 ( V_19 , V_4 , V_51 , V_96 ) ;
return 1 ;
}
return 0 ;
}
int F_106 ( struct V_18 * V_19 , T_2 V_100 ,
unsigned long V_101 , const enum V_55 V_56 ,
int V_70 )
{
struct V_17 * V_4 , * V_25 ;
unsigned long V_20 ;
int V_102 , V_103 ;
V_4 = F_6 ( V_19 , & V_20 ) ;
V_102 = F_104 ( V_19 , V_4 ) ;
V_25 = F_20 ( V_19 , V_4 , V_56 & V_104 ) ;
if ( V_56 & V_105 ) {
V_100 = F_33 ( V_100 , V_25 -> V_106 () ) ;
#ifdef F_107
V_100 = F_33 ( V_100 , V_4 -> V_76 ) ;
#endif
}
F_108 ( V_19 , V_100 , V_101 ) ;
F_90 ( V_19 ) ;
V_103 = F_100 ( V_19 , V_25 ) ;
if ( V_103 && V_25 -> V_21 == & F_68 ( V_36 ) )
F_72 ( V_19 , V_25 , V_70 ) ;
F_96 ( V_19 , & V_20 ) ;
return V_102 ;
}
int F_109 ( struct V_18 * V_19 , T_2 V_100 ,
unsigned long V_101 , const enum V_55 V_56 )
{
return F_106 ( V_19 , V_100 , V_101 , V_56 , 1 ) ;
}
int
F_110 ( struct V_18 * V_19 , T_2 V_100 , const enum V_55 V_56 )
{
return F_106 ( V_19 , V_100 , 0 , V_56 , 1 ) ;
}
int F_111 ( struct V_18 * V_19 )
{
struct V_17 * V_4 ;
unsigned long V_20 ;
int V_102 = - 1 ;
V_4 = F_6 ( V_19 , & V_20 ) ;
if ( ! F_24 ( V_19 ) )
V_102 = F_104 ( V_19 , V_4 ) ;
F_96 ( V_19 , & V_20 ) ;
return V_102 ;
}
int F_36 ( struct V_18 * V_19 )
{
for (; ; ) {
int V_102 = F_111 ( V_19 ) ;
if ( V_102 >= 0 )
return V_102 ;
F_10 () ;
}
}
T_2 F_112 ( const struct V_18 * V_19 )
{
unsigned long V_20 ;
T_2 V_41 ;
F_6 ( V_19 , & V_20 ) ;
V_41 = F_113 ( V_19 ) ;
F_96 ( V_19 , & V_20 ) ;
return V_41 ;
}
T_2 F_114 ( void )
{
struct V_3 * V_21 = & F_68 ( V_36 ) ;
struct V_17 * V_4 = V_21 -> V_12 ;
T_2 V_91 , V_107 = { . V_29 = V_62 } ;
unsigned long V_20 ;
int V_61 ;
F_8 ( & V_21 -> V_22 , V_20 ) ;
if ( ! F_61 () ) {
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ , V_4 ++ ) {
struct V_18 * V_19 ;
struct V_64 * V_65 ;
V_65 = F_64 ( & V_4 -> V_66 ) ;
if ( ! V_65 )
continue;
V_19 = F_65 ( V_65 , struct V_18 , V_67 ) ;
V_91 . V_29 = F_69 ( V_19 ) ;
V_91 = F_18 ( V_91 , V_4 -> V_106 () ) ;
if ( V_91 . V_29 < V_107 . V_29 )
V_107 . V_29 = V_91 . V_29 ;
}
}
F_9 ( & V_21 -> V_22 , V_20 ) ;
if ( V_107 . V_29 < 0 )
V_107 . V_29 = 0 ;
return V_107 ;
}
static void F_51 ( struct V_18 * V_19 , T_1 V_1 ,
enum V_55 V_56 )
{
struct V_3 * V_21 ;
int V_4 ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_21 = & F_115 ( V_36 ) ;
if ( V_1 == V_108 && V_56 != V_109 )
V_1 = V_110 ;
V_4 = F_1 ( V_1 ) ;
V_19 -> V_4 = & V_21 -> V_12 [ V_4 ] ;
F_116 ( & V_19 -> V_67 ) ;
#ifdef F_91
V_19 -> V_80 = NULL ;
V_19 -> V_85 = - 1 ;
memset ( V_19 -> V_81 , 0 , V_84 ) ;
#endif
}
void F_117 ( struct V_18 * V_19 , T_1 V_1 ,
enum V_55 V_56 )
{
F_53 ( V_19 , V_1 , V_56 ) ;
F_51 ( V_19 , V_1 , V_56 ) ;
}
int F_118 ( const T_1 V_111 , struct V_8 * V_112 )
{
struct V_3 * V_21 ;
int V_4 = F_1 ( V_111 ) ;
V_21 = & F_115 ( V_36 ) ;
* V_112 = F_119 ( V_21 -> V_12 [ V_4 ] . V_76 ) ;
return 0 ;
}
static void F_120 ( struct V_18 * V_19 , T_2 * V_88 )
{
struct V_17 * V_4 = V_19 -> V_4 ;
struct V_3 * V_21 = V_4 -> V_21 ;
enum V_113 ( * V_114 ) ( struct V_18 * ) ;
int V_115 ;
F_40 ( ! F_89 () ) ;
F_57 ( V_19 ) ;
F_102 ( V_19 , V_4 , V_99 , 0 ) ;
F_94 ( V_19 ) ;
V_114 = V_19 -> V_49 ;
F_25 ( & V_21 -> V_22 ) ;
F_121 ( V_19 , V_88 ) ;
V_115 = V_114 ( V_19 ) ;
F_122 ( V_19 ) ;
F_26 ( & V_21 -> V_22 ) ;
if ( V_115 != V_116 ) {
F_123 ( V_19 -> V_51 != V_99 ) ;
F_100 ( V_19 , V_4 ) ;
}
F_39 ( ! ( V_19 -> V_51 & V_99 ) ) ;
V_19 -> V_51 &= ~ V_99 ;
}
void F_124 ( struct V_117 * V_118 )
{
struct V_3 * V_21 = & F_68 ( V_36 ) ;
T_2 V_30 , V_88 , V_119 , V_91 ;
int V_61 , V_120 = 0 ;
F_123 ( ! V_21 -> V_27 ) ;
V_21 -> V_121 ++ ;
V_118 -> V_122 . V_29 = V_62 ;
F_26 ( & V_21 -> V_22 ) ;
V_119 = V_88 = F_75 ( V_21 ) ;
V_123:
V_30 . V_29 = V_62 ;
V_21 -> V_30 . V_29 = V_62 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_17 * V_4 ;
struct V_64 * V_67 ;
T_2 V_124 ;
if ( ! ( V_21 -> V_93 & ( 1 << V_61 ) ) )
continue;
V_4 = V_21 -> V_12 + V_61 ;
V_124 = F_5 ( V_88 , V_4 -> V_28 ) ;
while ( ( V_67 = F_64 ( & V_4 -> V_66 ) ) ) {
struct V_18 * V_19 ;
V_19 = F_65 ( V_67 , struct V_18 , V_67 ) ;
if ( V_124 . V_29 < F_125 ( V_19 ) ) {
T_2 V_26 ;
V_26 = F_18 ( F_19 ( V_19 ) ,
V_4 -> V_28 ) ;
if ( V_26 . V_29 < V_30 . V_29 )
V_30 = V_26 ;
break;
}
F_120 ( V_19 , & V_124 ) ;
}
}
V_21 -> V_30 = V_30 ;
F_25 ( & V_21 -> V_22 ) ;
if ( V_30 . V_29 == V_62 ||
! F_66 ( V_30 , 0 ) ) {
V_21 -> V_69 = 0 ;
return;
}
F_26 ( & V_21 -> V_22 ) ;
V_88 = F_75 ( V_21 ) ;
V_21 -> V_125 ++ ;
if ( ++ V_120 < 3 )
goto V_123;
V_21 -> V_126 ++ ;
V_21 -> V_69 = 1 ;
F_25 ( & V_21 -> V_22 ) ;
V_91 = F_18 ( V_88 , V_119 ) ;
if ( V_91 . V_29 > V_21 -> V_127 . V_29 )
V_21 -> V_127 = V_91 ;
if ( V_91 . V_29 > 100 * V_128 )
V_30 = F_27 ( V_88 , 100 * V_128 ) ;
else
V_30 = F_5 ( V_88 , V_91 ) ;
F_66 ( V_30 , 1 ) ;
F_126 ( V_75 L_6 ,
F_32 ( V_91 ) ) ;
}
static void F_127 ( void )
{
struct V_129 * V_130 ;
if ( ! F_61 () )
return;
V_130 = & F_68 ( V_131 ) ;
if ( V_130 && V_130 -> V_132 )
F_124 ( V_130 -> V_132 ) ;
}
void F_128 ( void )
{
unsigned long V_20 ;
F_79 ( V_20 ) ;
F_127 () ;
F_81 ( V_20 ) ;
}
static void F_129 ( struct V_133 * V_134 )
{
struct V_3 * V_21 = & F_68 ( V_36 ) ;
if ( V_21 -> V_78 ) {
V_21 -> V_78 = 0 ;
V_78 () ;
}
F_128 () ;
}
static inline void F_127 ( void ) { }
void F_130 ( void )
{
if ( F_61 () )
return;
if ( F_131 ( ! F_60 () ) )
F_78 () ;
}
void F_132 ( void )
{
struct V_64 * V_67 ;
struct V_3 * V_21 = & F_68 ( V_36 ) ;
struct V_17 * V_4 ;
int V_34 , V_135 = 1 ;
if ( F_61 () )
return;
for ( V_34 = 0 ; V_34 < V_63 ; V_34 ++ ) {
V_4 = & V_21 -> V_12 [ V_34 ] ;
if ( ! F_64 ( & V_4 -> V_66 ) )
continue;
if ( V_135 ) {
F_2 ( V_21 ) ;
V_135 = 0 ;
}
F_26 ( & V_21 -> V_22 ) ;
while ( ( V_67 = F_64 ( & V_4 -> V_66 ) ) ) {
struct V_18 * V_19 ;
V_19 = F_65 ( V_67 , struct V_18 , V_67 ) ;
if ( V_4 -> V_14 . V_29 <=
F_69 ( V_19 ) )
break;
F_120 ( V_19 , & V_4 -> V_14 ) ;
}
F_25 ( & V_21 -> V_22 ) ;
}
}
static enum V_113 F_133 ( struct V_18 * V_19 )
{
struct V_136 * V_137 =
F_65 ( V_19 , struct V_136 , V_19 ) ;
struct V_138 * V_139 = V_137 -> V_139 ;
V_137 -> V_139 = NULL ;
if ( V_139 )
F_134 ( V_139 ) ;
return V_116 ;
}
void F_135 ( struct V_136 * V_140 , struct V_138 * V_139 )
{
V_140 -> V_19 . V_49 = F_133 ;
V_140 -> V_139 = V_139 ;
}
static int T_6 F_136 ( struct V_136 * V_137 , enum V_55 V_56 )
{
F_135 ( V_137 , V_82 ) ;
do {
F_137 ( V_141 ) ;
F_138 ( & V_137 -> V_19 , V_56 ) ;
if ( ! F_139 ( & V_137 -> V_19 ) )
V_137 -> V_139 = NULL ;
if ( F_7 ( V_137 -> V_139 ) )
F_140 () ;
F_36 ( & V_137 -> V_19 ) ;
V_56 = V_109 ;
} while ( V_137 -> V_139 && ! F_141 ( V_82 ) );
F_142 ( V_142 ) ;
return V_137 -> V_139 == NULL ;
}
static int F_143 ( struct V_18 * V_19 , struct V_8 T_7 * V_143 )
{
struct V_8 V_144 ;
T_2 V_41 ;
V_41 = F_113 ( V_19 ) ;
if ( V_41 . V_29 <= 0 )
return 0 ;
V_144 = F_119 ( V_41 ) ;
if ( F_144 ( V_143 , & V_144 , sizeof( * V_143 ) ) )
return - V_145 ;
return 1 ;
}
long T_6 F_145 ( struct V_146 * V_115 )
{
struct V_136 V_137 ;
struct V_8 T_7 * V_143 ;
int V_102 = 0 ;
F_49 ( & V_137 . V_19 , V_115 -> V_147 . V_57 ,
V_109 ) ;
F_146 ( & V_137 . V_19 , V_115 -> V_147 . V_26 ) ;
if ( F_136 ( & V_137 , V_109 ) )
goto V_98;
V_143 = V_115 -> V_147 . V_143 ;
if ( V_143 ) {
V_102 = F_143 ( & V_137 . V_19 , V_143 ) ;
if ( V_102 <= 0 )
goto V_98;
}
V_102 = - V_148 ;
V_98:
F_52 ( & V_137 . V_19 ) ;
return V_102 ;
}
long F_147 ( struct V_8 * V_149 , struct V_8 T_7 * V_143 ,
const enum V_55 V_56 , const T_1 V_57 )
{
struct V_146 * V_115 ;
struct V_136 V_137 ;
int V_102 = 0 ;
unsigned long V_150 ;
V_150 = V_82 -> V_151 ;
if ( F_148 ( V_82 ) )
V_150 = 0 ;
F_49 ( & V_137 . V_19 , V_57 , V_56 ) ;
F_108 ( & V_137 . V_19 , F_4 ( * V_149 ) , V_150 ) ;
if ( F_136 ( & V_137 , V_56 ) )
goto V_98;
if ( V_56 == V_109 ) {
V_102 = - V_152 ;
goto V_98;
}
if ( V_143 ) {
V_102 = F_143 ( & V_137 . V_19 , V_143 ) ;
if ( V_102 <= 0 )
goto V_98;
}
V_115 = & F_149 () -> V_146 ;
V_115 -> V_114 = F_145 ;
V_115 -> V_147 . V_57 = V_137 . V_19 . V_4 -> V_57 ;
V_115 -> V_147 . V_143 = V_143 ;
V_115 -> V_147 . V_26 = F_69 ( & V_137 . V_19 ) ;
V_102 = - V_148 ;
V_98:
F_52 ( & V_137 . V_19 ) ;
return V_102 ;
}
static void T_8 F_150 ( int V_32 )
{
struct V_3 * V_21 = & F_22 ( V_36 , V_32 ) ;
int V_61 ;
F_151 ( & V_21 -> V_22 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_21 -> V_12 [ V_61 ] . V_21 = V_21 ;
F_152 ( & V_21 -> V_12 [ V_61 ] . V_66 ) ;
}
F_71 ( V_21 ) ;
}
static void F_153 ( struct V_17 * V_153 ,
struct V_17 * V_25 )
{
struct V_18 * V_19 ;
struct V_64 * V_67 ;
while ( ( V_67 = F_64 ( & V_153 -> V_66 ) ) ) {
V_19 = F_65 ( V_67 , struct V_18 , V_67 ) ;
F_123 ( F_24 ( V_19 ) ) ;
F_57 ( V_19 ) ;
F_102 ( V_19 , V_153 , V_154 , 0 ) ;
V_19 -> V_4 = V_25 ;
F_100 ( V_19 , V_25 ) ;
V_19 -> V_51 &= ~ V_154 ;
}
}
static void F_154 ( int V_155 )
{
struct V_3 * V_153 , * V_25 ;
int V_61 ;
F_123 ( F_155 ( V_155 ) ) ;
F_156 ( V_155 ) ;
F_157 () ;
V_153 = & F_22 ( V_36 , V_155 ) ;
V_25 = & F_68 ( V_36 ) ;
F_26 ( & V_25 -> V_22 ) ;
F_158 ( & V_153 -> V_22 , V_156 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
F_153 ( & V_153 -> V_12 [ V_61 ] ,
& V_25 -> V_12 [ V_61 ] ) ;
}
F_25 ( & V_153 -> V_22 ) ;
F_25 ( & V_25 -> V_22 ) ;
F_127 () ;
F_159 () ;
}
static int T_8 F_160 ( struct V_157 * V_158 ,
unsigned long V_159 , void * V_160 )
{
int V_155 = ( long ) V_160 ;
switch ( V_159 ) {
case V_161 :
case V_162 :
F_150 ( V_155 ) ;
break;
#ifdef F_161
case V_163 :
case V_164 :
F_162 ( V_165 , & V_155 ) ;
break;
case V_166 :
case V_167 :
{
F_162 ( V_168 , & V_155 ) ;
F_154 ( V_155 ) ;
break;
}
#endif
default:
break;
}
return V_169 ;
}
void T_5 F_163 ( void )
{
F_160 ( & V_170 , ( unsigned long ) V_161 ,
( void * ) ( long ) F_21 () ) ;
F_164 ( & V_170 ) ;
#ifdef F_17
F_165 ( V_71 , F_129 ) ;
#endif
}
int T_6
F_166 ( T_2 * V_26 , unsigned long V_91 ,
const enum V_55 V_56 , int clock )
{
struct V_136 V_137 ;
if ( V_26 && ! V_26 -> V_29 ) {
F_142 ( V_142 ) ;
return 0 ;
}
if ( ! V_26 ) {
F_140 () ;
F_142 ( V_142 ) ;
return - V_171 ;
}
F_49 ( & V_137 . V_19 , clock , V_56 ) ;
F_108 ( & V_137 . V_19 , * V_26 , V_91 ) ;
F_135 ( & V_137 , V_82 ) ;
F_138 ( & V_137 . V_19 , V_56 ) ;
if ( ! F_139 ( & V_137 . V_19 ) )
V_137 . V_139 = NULL ;
if ( F_7 ( V_137 . V_139 ) )
F_140 () ;
F_36 ( & V_137 . V_19 ) ;
F_52 ( & V_137 . V_19 ) ;
F_142 ( V_142 ) ;
return ! V_137 . V_139 ? 0 : - V_171 ;
}
int T_6 F_167 ( T_2 * V_26 , unsigned long V_91 ,
const enum V_55 V_56 )
{
return F_166 ( V_26 , V_91 , V_56 ,
V_110 ) ;
}
int T_6 F_168 ( T_2 * V_26 ,
const enum V_55 V_56 )
{
return F_167 ( V_26 , 0 , V_56 ) ;
}
