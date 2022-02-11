static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 ) ;
if ( V_2 && V_2 -> V_4 != V_5 )
F_3 ( V_2 ) ;
}
static void F_4 ( unsigned long V_6 , unsigned int V_7 )
{
unsigned long V_8 ;
F_5 ( F_6 () ) ;
F_7 ( V_8 ) ;
F_8 () += V_7 ;
if ( F_9 () == V_7 )
F_10 ( V_6 ) ;
F_11 ( V_8 ) ;
if ( F_8 () == V_7 )
F_12 ( V_9 , F_13 ( V_10 ) ) ;
}
static inline void F_4 ( unsigned long V_6 , unsigned int V_7 )
{
F_14 ( V_7 ) ;
F_15 () ;
}
void F_16 ( void )
{
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_11 ) ;
}
static void F_18 ( unsigned int V_7 )
{
F_5 ( F_6 () ) ;
F_5 ( ! F_19 () ) ;
if ( F_9 () == V_7 )
F_20 ( ( unsigned long ) F_17 ( 0 ) ) ;
F_21 ( V_7 ) ;
}
void F_22 ( void )
{
F_18 ( V_11 ) ;
}
static inline void F_23 ( unsigned long V_6 )
{
F_5 ( F_6 () || F_19 () ) ;
#ifdef F_24
F_25 () ;
#endif
if ( F_9 () == V_11 )
F_20 ( V_6 ) ;
F_21 ( V_11 - 1 ) ;
if ( F_26 ( ! F_27 () && F_28 () ) )
F_29 () ;
F_30 () ;
#ifdef F_24
F_31 () ;
#endif
F_32 () ;
}
void F_33 ( void )
{
F_23 ( ( unsigned long ) F_17 ( 0 ) ) ;
}
void F_34 ( unsigned long V_6 )
{
F_23 ( V_6 ) ;
}
T_1 void F_35 ( void )
{
struct V_12 * V_13 ;
T_2 V_14 ;
int V_15 = V_16 ;
int V_17 ;
unsigned long V_18 = V_19 -> V_8 ;
V_19 -> V_8 &= ~ V_20 ;
V_14 = F_28 () ;
F_36 ( V_19 ) ;
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_21 ) ;
F_37 () ;
V_17 = F_38 () ;
V_22:
F_39 ( 0 ) ;
F_31 () ;
V_13 = V_23 ;
do {
if ( V_14 & 1 ) {
unsigned int V_24 = V_13 - V_23 ;
int V_25 = F_8 () ;
F_40 ( V_24 ) ;
F_41 ( V_24 ) ;
V_13 -> V_26 ( V_13 ) ;
F_42 ( V_24 ) ;
if ( F_26 ( V_25 != F_8 () ) ) {
F_43 ( V_27 L_1
L_2
L_3 , V_24 ,
V_28 [ V_24 ] , V_13 -> V_26 ,
V_25 , F_8 () ) ;
F_8 () = V_25 ;
}
F_44 ( V_17 ) ;
}
V_13 ++ ;
V_14 >>= 1 ;
} while ( V_14 );
F_25 () ;
V_14 = F_28 () ;
if ( V_14 && -- V_15 )
goto V_22;
if ( V_14 )
F_1 () ;
F_45 () ;
F_36 ( V_19 ) ;
F_18 ( V_21 ) ;
F_46 ( V_19 , V_18 , V_20 ) ;
}
T_1 void F_29 ( void )
{
T_2 V_14 ;
unsigned long V_8 ;
if ( F_27 () )
return;
F_47 ( V_8 ) ;
V_14 = F_28 () ;
if ( V_14 )
F_35 () ;
F_48 ( V_8 ) ;
}
void F_49 ( void )
{
int V_17 = F_38 () ;
F_50 () ;
if ( F_51 ( V_19 ) && ! F_27 () ) {
F_16 () ;
F_52 ( V_17 ) ;
F_22 () ;
}
F_53 () ;
}
static inline void F_54 ( void )
{
if ( ! V_29 ) {
#ifdef F_55
F_35 () ;
#else
F_29 () ;
#endif
} else {
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_21 ) ;
F_1 () ;
F_18 ( V_21 ) ;
}
}
void F_56 ( void )
{
F_36 ( V_19 ) ;
F_57 () ;
F_21 ( V_30 ) ;
if ( ! F_27 () && F_28 () )
F_54 () ;
#ifdef F_58
if ( F_59 ( F_38 () ) && ! F_27 () && ! F_60 () )
F_61 () ;
#endif
F_62 () ;
F_63 () ;
}
inline void F_64 ( unsigned int V_31 )
{
F_65 ( V_31 ) ;
if ( ! F_27 () )
F_1 () ;
}
void F_66 ( unsigned int V_31 )
{
unsigned long V_8 ;
F_47 ( V_8 ) ;
F_64 ( V_31 ) ;
F_48 ( V_8 ) ;
}
void F_65 ( unsigned int V_31 )
{
F_67 ( V_31 ) ;
F_68 ( 1UL << V_31 ) ;
}
void F_69 ( int V_31 , void (* V_26)( struct V_12 * ) )
{
V_23 [ V_31 ] . V_26 = V_26 ;
}
void F_70 ( struct V_32 * V_33 )
{
unsigned long V_8 ;
F_47 ( V_8 ) ;
V_33 -> V_34 = NULL ;
* F_2 ( V_35 . V_36 ) = V_33 ;
F_71 ( V_35 . V_36 , & ( V_33 -> V_34 ) ) ;
F_64 ( V_37 ) ;
F_48 ( V_8 ) ;
}
void F_72 ( struct V_32 * V_33 )
{
unsigned long V_8 ;
F_47 ( V_8 ) ;
V_33 -> V_34 = NULL ;
* F_2 ( V_38 . V_36 ) = V_33 ;
F_71 ( V_38 . V_36 , & ( V_33 -> V_34 ) ) ;
F_64 ( V_39 ) ;
F_48 ( V_8 ) ;
}
void F_73 ( struct V_32 * V_33 )
{
F_74 ( ! F_19 () ) ;
V_33 -> V_34 = F_2 ( V_38 . V_40 ) ;
F_71 ( V_38 . V_40 , V_33 ) ;
F_65 ( V_39 ) ;
}
static void F_75 ( struct V_12 * V_41 )
{
struct V_32 * V_42 ;
F_25 () ;
V_42 = F_2 ( V_35 . V_40 ) ;
F_71 ( V_35 . V_40 , NULL ) ;
F_71 ( V_35 . V_36 , & F_76 ( V_35 ) . V_40 ) ;
F_31 () ;
while ( V_42 ) {
struct V_32 * V_33 = V_42 ;
V_42 = V_42 -> V_34 ;
if ( F_77 ( V_33 ) ) {
if ( ! F_78 ( & V_33 -> V_43 ) ) {
if ( ! F_79 ( V_44 , & V_33 -> V_4 ) )
F_80 () ;
V_33 -> V_45 ( V_33 -> V_46 ) ;
F_81 ( V_33 ) ;
continue;
}
F_81 ( V_33 ) ;
}
F_25 () ;
V_33 -> V_34 = NULL ;
* F_2 ( V_35 . V_36 ) = V_33 ;
F_71 ( V_35 . V_36 , & ( V_33 -> V_34 ) ) ;
F_65 ( V_37 ) ;
F_31 () ;
}
}
static void F_82 ( struct V_12 * V_41 )
{
struct V_32 * V_42 ;
F_25 () ;
V_42 = F_2 ( V_38 . V_40 ) ;
F_71 ( V_38 . V_40 , NULL ) ;
F_71 ( V_38 . V_36 , & F_76 ( V_38 ) . V_40 ) ;
F_31 () ;
while ( V_42 ) {
struct V_32 * V_33 = V_42 ;
V_42 = V_42 -> V_34 ;
if ( F_77 ( V_33 ) ) {
if ( ! F_78 ( & V_33 -> V_43 ) ) {
if ( ! F_79 ( V_44 , & V_33 -> V_4 ) )
F_80 () ;
V_33 -> V_45 ( V_33 -> V_46 ) ;
F_81 ( V_33 ) ;
continue;
}
F_81 ( V_33 ) ;
}
F_25 () ;
V_33 -> V_34 = NULL ;
* F_2 ( V_38 . V_36 ) = V_33 ;
F_71 ( V_38 . V_36 , & ( V_33 -> V_34 ) ) ;
F_65 ( V_39 ) ;
F_31 () ;
}
}
void F_83 ( struct V_32 * V_33 ,
void (* V_45)( unsigned long ) , unsigned long V_46 )
{
V_33 -> V_34 = NULL ;
V_33 -> V_4 = 0 ;
F_84 ( & V_33 -> V_43 , 0 ) ;
V_33 -> V_45 = V_45 ;
V_33 -> V_46 = V_46 ;
}
void F_85 ( struct V_32 * V_33 )
{
if ( F_27 () )
F_43 ( L_4 ) ;
while ( F_86 ( V_44 , & V_33 -> V_4 ) ) {
do {
F_87 () ;
} while ( F_88 ( V_44 , & V_33 -> V_4 ) );
}
F_89 ( V_33 ) ;
F_90 ( V_44 , & V_33 -> V_4 ) ;
}
static enum V_47 F_91 ( struct V_48 * V_49 )
{
struct V_50 * V_51 =
F_92 ( V_49 , struct V_50 , V_49 ) ;
F_93 ( & V_51 -> V_52 ) ;
return V_53 ;
}
static void F_94 ( unsigned long V_46 )
{
struct V_50 * V_51 = ( void * ) V_46 ;
enum V_47 V_22 ;
V_22 = V_51 -> V_54 ( & V_51 -> V_49 ) ;
if ( V_22 != V_53 )
V_47 ( & V_51 -> V_49 ) ;
}
static void F_95 ( struct V_55 * V_56 , int V_57 )
{
struct V_58 * V_40 = & F_76 ( V_59 [ V_57 ] ) ;
F_96 ( & V_56 -> V_42 , V_40 ) ;
if ( V_40 -> V_34 == & V_56 -> V_42 )
F_64 ( V_57 ) ;
}
static void F_97 ( void * V_46 )
{
struct V_55 * V_56 = V_46 ;
unsigned long V_8 ;
int V_57 ;
V_57 = V_56 -> V_60 ;
F_47 ( V_8 ) ;
F_95 ( V_56 , V_57 ) ;
F_48 ( V_8 ) ;
}
static int F_98 ( struct V_55 * V_56 , int V_17 , int V_57 )
{
if ( F_99 ( V_17 ) ) {
V_56 -> V_45 = F_97 ;
V_56 -> V_61 = V_56 ;
V_56 -> V_8 = 0 ;
V_56 -> V_60 = V_57 ;
F_100 ( V_17 , V_56 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_98 ( struct V_55 * V_56 , int V_17 , int V_57 )
{
return 1 ;
}
void F_101 ( struct V_55 * V_56 , int V_17 , int V_62 , int V_57 )
{
if ( V_17 == V_62 || F_98 ( V_56 , V_17 , V_57 ) )
F_95 ( V_56 , V_57 ) ;
}
void F_102 ( struct V_55 * V_56 , int V_17 , int V_57 )
{
unsigned long V_8 ;
int V_62 ;
F_47 ( V_8 ) ;
V_62 = F_38 () ;
F_101 ( V_56 , V_17 , V_62 , V_57 ) ;
F_48 ( V_8 ) ;
}
static int T_3 F_103 ( struct V_63 * V_64 ,
unsigned long V_26 , void * V_65 )
{
if ( V_26 == V_66 || V_26 == V_67 ) {
int V_17 = ( unsigned long ) V_65 ;
int V_68 ;
F_25 () ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
struct V_58 * V_40 = & F_104 ( V_59 [ V_68 ] , V_17 ) ;
struct V_58 * V_70 ;
if ( F_105 ( V_40 ) )
continue;
V_70 = & F_76 ( V_59 [ V_68 ] ) ;
F_106 ( V_40 , V_70 ) ;
F_64 ( V_68 ) ;
}
F_31 () ;
}
return V_71 ;
}
void T_4 F_107 ( void )
{
int V_17 ;
F_108 (cpu) {
int V_68 ;
F_104 ( V_35 , V_17 ) . V_36 =
& F_104 ( V_35 , V_17 ) . V_40 ;
F_104 ( V_38 , V_17 ) . V_36 =
& F_104 ( V_38 , V_17 ) . V_40 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ )
F_109 ( & F_104 ( V_59 [ V_68 ] , V_17 ) ) ;
}
F_110 ( & V_72 ) ;
F_69 ( V_37 , F_75 ) ;
F_69 ( V_39 , F_82 ) ;
}
static int F_111 ( unsigned int V_17 )
{
return F_28 () ;
}
static void F_112 ( unsigned int V_17 )
{
F_25 () ;
if ( F_28 () ) {
F_35 () ;
F_113 ( V_17 ) ;
F_31 () ;
F_114 () ;
return;
}
F_31 () ;
}
void F_115 ( struct V_32 * V_33 , unsigned int V_17 )
{
struct V_32 * * V_68 ;
F_74 ( F_99 ( V_17 ) ) ;
F_74 ( F_88 ( V_73 , & V_33 -> V_4 ) ) ;
if ( ! F_88 ( V_44 , & V_33 -> V_4 ) )
return;
for ( V_68 = & F_104 ( V_35 , V_17 ) . V_40 ; * V_68 ; V_68 = & ( * V_68 ) -> V_34 ) {
if ( * V_68 == V_33 ) {
* V_68 = V_33 -> V_34 ;
if ( * V_68 == NULL )
F_104 ( V_35 , V_17 ) . V_36 = V_68 ;
return;
}
}
F_80 () ;
}
static void F_116 ( unsigned int V_17 )
{
F_25 () ;
if ( & F_104 ( V_35 , V_17 ) . V_40 != F_104 ( V_35 , V_17 ) . V_36 ) {
* F_2 ( V_35 . V_36 ) = F_104 ( V_35 , V_17 ) . V_40 ;
F_117 ( V_35 . V_36 , F_104 ( V_35 , V_17 ) . V_36 ) ;
F_104 ( V_35 , V_17 ) . V_40 = NULL ;
F_104 ( V_35 , V_17 ) . V_36 = & F_104 ( V_35 , V_17 ) . V_40 ;
}
F_64 ( V_37 ) ;
if ( & F_104 ( V_38 , V_17 ) . V_40 != F_104 ( V_38 , V_17 ) . V_36 ) {
* F_2 ( V_38 . V_36 ) = F_104 ( V_38 , V_17 ) . V_40 ;
F_71 ( V_38 . V_36 , F_104 ( V_38 , V_17 ) . V_36 ) ;
F_104 ( V_38 , V_17 ) . V_40 = NULL ;
F_104 ( V_38 , V_17 ) . V_36 = & F_104 ( V_38 , V_17 ) . V_40 ;
}
F_64 ( V_39 ) ;
F_31 () ;
}
static int T_3 F_118 ( struct V_63 * V_74 ,
unsigned long V_26 ,
void * V_65 )
{
switch ( V_26 ) {
#ifdef F_119
case V_66 :
case V_67 :
F_116 ( ( unsigned long ) V_65 ) ;
break;
#endif
}
return V_71 ;
}
static T_4 int F_120 ( void )
{
F_121 ( & V_75 ) ;
F_74 ( F_122 ( & V_76 ) ) ;
return 0 ;
}
int T_4 __weak F_123 ( void )
{
return 0 ;
}
int T_4 __weak F_124 ( void )
{
return V_77 ;
}
int T_4 __weak F_125 ( void )
{
return 0 ;
}
