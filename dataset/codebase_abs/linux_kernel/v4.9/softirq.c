static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 ) ;
if ( V_2 && V_2 -> V_4 != V_5 )
F_3 ( V_2 ) ;
}
static bool F_4 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 ) ;
return V_2 && ( V_2 -> V_4 == V_5 ) ;
}
void F_5 ( unsigned long V_6 , unsigned int V_7 )
{
unsigned long V_8 ;
F_6 ( F_7 () ) ;
F_8 ( V_8 ) ;
F_9 ( V_7 ) ;
if ( F_10 () == ( V_7 & V_9 ) )
F_11 ( V_6 ) ;
F_12 ( V_8 ) ;
if ( F_13 () == V_7 ) {
#ifdef F_14
V_10 -> V_11 = F_15 () ;
#endif
F_16 ( V_12 , F_15 () ) ;
}
}
static void F_17 ( unsigned int V_7 )
{
F_6 ( ! F_18 () ) ;
if ( F_10 () == ( V_7 & V_9 ) )
F_19 ( V_13 ) ;
F_20 ( V_7 ) ;
}
void F_21 ( void )
{
F_6 ( F_7 () ) ;
F_17 ( V_14 ) ;
}
void F_22 ( unsigned long V_6 , unsigned int V_7 )
{
F_6 ( F_7 () || F_18 () ) ;
#ifdef F_23
F_24 () ;
#endif
if ( F_10 () == V_14 )
F_19 ( V_6 ) ;
F_20 ( V_7 - 1 ) ;
if ( F_25 ( ! F_26 () && F_27 () ) ) {
F_28 () ;
}
F_29 () ;
#ifdef F_23
F_30 () ;
#endif
F_31 () ;
}
static inline bool F_32 ( void )
{
bool V_15 = false ;
if ( F_33 ( V_10 ) ) {
V_15 = true ;
F_34 () ;
}
F_35 () ;
return V_15 ;
}
static inline void F_36 ( bool V_15 )
{
F_37 () ;
if ( V_15 )
F_38 () ;
}
static inline bool F_32 ( void ) { return false ; }
static inline void F_36 ( bool V_15 ) { }
T_1 T_2 void T_3 F_39 ( void )
{
unsigned long V_16 = V_17 + V_18 ;
unsigned long V_19 = V_10 -> V_8 ;
int V_20 = V_21 ;
struct V_22 * V_23 ;
bool V_15 ;
T_4 V_24 ;
int V_25 ;
V_10 -> V_8 &= ~ V_26 ;
V_24 = F_27 () ;
F_40 ( V_10 ) ;
F_5 ( V_13 , V_27 ) ;
V_15 = F_32 () ;
V_28:
F_41 ( 0 ) ;
F_30 () ;
V_23 = V_29 ;
while ( ( V_25 = F_42 ( V_24 ) ) ) {
unsigned int V_30 ;
int V_31 ;
V_23 += V_25 - 1 ;
V_30 = V_23 - V_29 ;
V_31 = F_13 () ;
F_43 ( V_30 ) ;
F_44 ( V_30 ) ;
V_23 -> V_32 ( V_23 ) ;
F_45 ( V_30 ) ;
if ( F_25 ( V_31 != F_13 () ) ) {
F_46 ( L_1 ,
V_30 , V_33 [ V_30 ] , V_23 -> V_32 ,
V_31 , F_13 () ) ;
F_47 ( V_31 ) ;
}
V_23 ++ ;
V_24 >>= V_25 ;
}
F_48 () ;
F_24 () ;
V_24 = F_27 () ;
if ( V_24 ) {
if ( F_49 ( V_17 , V_16 ) && ! F_50 () &&
-- V_20 )
goto V_28;
F_1 () ;
}
F_36 ( V_15 ) ;
F_51 ( V_10 ) ;
F_17 ( V_27 ) ;
F_6 ( F_26 () ) ;
F_52 ( V_10 , V_19 , V_26 ) ;
}
T_1 T_2 void F_28 ( void )
{
T_4 V_24 ;
unsigned long V_8 ;
if ( F_26 () )
return;
F_53 ( V_8 ) ;
V_24 = F_27 () ;
if ( V_24 && ! F_4 () )
F_54 () ;
F_55 ( V_8 ) ;
}
void F_56 ( void )
{
F_57 () ;
if ( F_58 ( V_10 ) && ! F_26 () ) {
F_59 () ;
F_60 () ;
F_21 () ;
}
F_61 () ;
}
static inline void F_62 ( void )
{
if ( F_4 () )
return;
if ( ! V_34 ) {
#ifdef F_63
F_39 () ;
#else
F_54 () ;
#endif
} else {
F_1 () ;
}
}
static inline void F_64 ( void )
{
#ifdef F_65
int V_35 = F_66 () ;
if ( ( F_67 ( V_35 ) && ! F_50 () ) || F_68 ( V_35 ) ) {
if ( ! F_26 () )
F_69 () ;
}
#endif
}
void F_70 ( void )
{
#ifndef F_71
F_24 () ;
#else
F_6 ( ! F_18 () ) ;
#endif
F_51 ( V_10 ) ;
F_20 ( V_36 ) ;
if ( ! F_26 () && F_27 () )
F_62 () ;
F_64 () ;
F_72 () ;
F_34 () ;
}
inline void F_73 ( unsigned int V_37 )
{
F_74 ( V_37 ) ;
if ( ! F_26 () )
F_1 () ;
}
void F_75 ( unsigned int V_37 )
{
unsigned long V_8 ;
F_53 ( V_8 ) ;
F_73 ( V_37 ) ;
F_55 ( V_8 ) ;
}
void F_74 ( unsigned int V_37 )
{
F_76 ( V_37 ) ;
F_77 ( 1UL << V_37 ) ;
}
void F_78 ( int V_37 , void (* V_32)( struct V_22 * ) )
{
V_29 [ V_37 ] . V_32 = V_32 ;
}
void F_79 ( struct V_38 * V_39 )
{
unsigned long V_8 ;
F_53 ( V_8 ) ;
V_39 -> V_40 = NULL ;
* F_2 ( V_41 . V_42 ) = V_39 ;
F_80 ( V_41 . V_42 , & ( V_39 -> V_40 ) ) ;
F_73 ( V_43 ) ;
F_55 ( V_8 ) ;
}
void F_81 ( struct V_38 * V_39 )
{
unsigned long V_8 ;
F_53 ( V_8 ) ;
V_39 -> V_40 = NULL ;
* F_2 ( V_44 . V_42 ) = V_39 ;
F_80 ( V_44 . V_42 , & ( V_39 -> V_40 ) ) ;
F_73 ( V_45 ) ;
F_55 ( V_8 ) ;
}
void F_82 ( struct V_38 * V_39 )
{
F_83 ( ! F_18 () ) ;
V_39 -> V_40 = F_2 ( V_44 . V_46 ) ;
F_80 ( V_44 . V_46 , V_39 ) ;
F_74 ( V_45 ) ;
}
static T_5 void F_84 ( struct V_22 * V_47 )
{
struct V_38 * V_48 ;
F_24 () ;
V_48 = F_2 ( V_41 . V_46 ) ;
F_80 ( V_41 . V_46 , NULL ) ;
F_80 ( V_41 . V_42 , F_85 ( & V_41 . V_46 ) ) ;
F_30 () ;
while ( V_48 ) {
struct V_38 * V_39 = V_48 ;
V_48 = V_48 -> V_40 ;
if ( F_86 ( V_39 ) ) {
if ( ! F_87 ( & V_39 -> V_49 ) ) {
if ( ! F_88 ( V_50 ,
& V_39 -> V_4 ) )
F_89 () ;
V_39 -> V_51 ( V_39 -> V_52 ) ;
F_90 ( V_39 ) ;
continue;
}
F_90 ( V_39 ) ;
}
F_24 () ;
V_39 -> V_40 = NULL ;
* F_2 ( V_41 . V_42 ) = V_39 ;
F_80 ( V_41 . V_42 , & ( V_39 -> V_40 ) ) ;
F_74 ( V_43 ) ;
F_30 () ;
}
}
static T_5 void F_91 ( struct V_22 * V_47 )
{
struct V_38 * V_48 ;
F_24 () ;
V_48 = F_2 ( V_44 . V_46 ) ;
F_80 ( V_44 . V_46 , NULL ) ;
F_80 ( V_44 . V_42 , F_85 ( & V_44 . V_46 ) ) ;
F_30 () ;
while ( V_48 ) {
struct V_38 * V_39 = V_48 ;
V_48 = V_48 -> V_40 ;
if ( F_86 ( V_39 ) ) {
if ( ! F_87 ( & V_39 -> V_49 ) ) {
if ( ! F_88 ( V_50 ,
& V_39 -> V_4 ) )
F_89 () ;
V_39 -> V_51 ( V_39 -> V_52 ) ;
F_90 ( V_39 ) ;
continue;
}
F_90 ( V_39 ) ;
}
F_24 () ;
V_39 -> V_40 = NULL ;
* F_2 ( V_44 . V_42 ) = V_39 ;
F_80 ( V_44 . V_42 , & ( V_39 -> V_40 ) ) ;
F_74 ( V_45 ) ;
F_30 () ;
}
}
void F_92 ( struct V_38 * V_39 ,
void (* V_51)( unsigned long ) , unsigned long V_52 )
{
V_39 -> V_40 = NULL ;
V_39 -> V_4 = 0 ;
F_93 ( & V_39 -> V_49 , 0 ) ;
V_39 -> V_51 = V_51 ;
V_39 -> V_52 = V_52 ;
}
void F_94 ( struct V_38 * V_39 )
{
if ( F_26 () )
F_95 ( L_2 ) ;
while ( F_96 ( V_50 , & V_39 -> V_4 ) ) {
do {
F_97 () ;
} while ( F_98 ( V_50 , & V_39 -> V_4 ) );
}
F_99 ( V_39 ) ;
F_100 ( V_50 , & V_39 -> V_4 ) ;
}
static enum V_53 F_101 ( struct V_54 * V_55 )
{
struct V_56 * V_57 =
F_102 ( V_55 , struct V_56 , V_55 ) ;
F_103 ( & V_57 -> V_58 ) ;
return V_59 ;
}
static void F_104 ( unsigned long V_52 )
{
struct V_56 * V_57 = ( void * ) V_52 ;
enum V_53 V_28 ;
V_28 = V_57 -> V_60 ( & V_57 -> V_55 ) ;
if ( V_28 != V_59 )
V_53 ( & V_57 -> V_55 ) ;
}
void T_6 F_105 ( void )
{
int V_35 ;
F_106 (cpu) {
F_107 ( V_41 , V_35 ) . V_42 =
& F_107 ( V_41 , V_35 ) . V_46 ;
F_107 ( V_44 , V_35 ) . V_42 =
& F_107 ( V_44 , V_35 ) . V_46 ;
}
F_78 ( V_43 , F_84 ) ;
F_78 ( V_45 , F_91 ) ;
}
static int F_108 ( unsigned int V_35 )
{
return F_27 () ;
}
static void F_109 ( unsigned int V_35 )
{
F_24 () ;
if ( F_27 () ) {
F_39 () ;
F_30 () ;
F_110 () ;
return;
}
F_30 () ;
}
void F_111 ( struct V_38 * V_39 , unsigned int V_35 )
{
struct V_38 * * V_61 ;
F_83 ( F_112 ( V_35 ) ) ;
F_83 ( F_98 ( V_62 , & V_39 -> V_4 ) ) ;
if ( ! F_98 ( V_50 , & V_39 -> V_4 ) )
return;
for ( V_61 = & F_107 ( V_41 , V_35 ) . V_46 ; * V_61 ; V_61 = & ( * V_61 ) -> V_40 ) {
if ( * V_61 == V_39 ) {
* V_61 = V_39 -> V_40 ;
if ( * V_61 == NULL )
F_107 ( V_41 , V_35 ) . V_42 = V_61 ;
return;
}
}
F_89 () ;
}
static int F_113 ( unsigned int V_35 )
{
F_24 () ;
if ( & F_107 ( V_41 , V_35 ) . V_46 != F_107 ( V_41 , V_35 ) . V_42 ) {
* F_2 ( V_41 . V_42 ) = F_107 ( V_41 , V_35 ) . V_46 ;
F_114 ( V_41 . V_42 , F_107 ( V_41 , V_35 ) . V_42 ) ;
F_107 ( V_41 , V_35 ) . V_46 = NULL ;
F_107 ( V_41 , V_35 ) . V_42 = & F_107 ( V_41 , V_35 ) . V_46 ;
}
F_73 ( V_43 ) ;
if ( & F_107 ( V_44 , V_35 ) . V_46 != F_107 ( V_44 , V_35 ) . V_42 ) {
* F_2 ( V_44 . V_42 ) = F_107 ( V_44 , V_35 ) . V_46 ;
F_80 ( V_44 . V_42 , F_107 ( V_44 , V_35 ) . V_42 ) ;
F_107 ( V_44 , V_35 ) . V_46 = NULL ;
F_107 ( V_44 , V_35 ) . V_42 = & F_107 ( V_44 , V_35 ) . V_46 ;
}
F_73 ( V_45 ) ;
F_30 () ;
return 0 ;
}
static T_6 int F_115 ( void )
{
F_116 ( V_63 , L_3 , NULL ,
F_113 ) ;
F_83 ( F_117 ( & V_64 ) ) ;
return 0 ;
}
int T_6 __weak F_118 ( void )
{
return 0 ;
}
int T_6 __weak F_119 ( void )
{
return V_65 ;
}
int T_6 __weak F_120 ( void )
{
return 0 ;
}
unsigned int __weak F_121 ( unsigned int V_66 )
{
return V_66 ;
}
