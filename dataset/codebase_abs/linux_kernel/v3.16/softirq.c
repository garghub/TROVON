static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 ) ;
if ( V_2 && V_2 -> V_4 != V_5 )
F_3 ( V_2 ) ;
}
void F_4 ( unsigned long V_6 , unsigned int V_7 )
{
unsigned long V_8 ;
F_5 ( F_6 () ) ;
F_7 ( V_8 ) ;
F_8 ( V_7 ) ;
if ( F_9 () == ( V_7 & V_9 ) )
F_10 ( V_6 ) ;
F_11 ( V_8 ) ;
if ( F_12 () == V_7 )
F_13 ( V_10 , F_14 ( V_11 ) ) ;
}
static void F_15 ( unsigned int V_7 )
{
F_5 ( ! F_16 () ) ;
if ( F_9 () == ( V_7 & V_9 ) )
F_17 ( V_12 ) ;
F_18 ( V_7 ) ;
}
void F_19 ( void )
{
F_5 ( F_6 () ) ;
F_15 ( V_13 ) ;
}
void F_20 ( unsigned long V_6 , unsigned int V_7 )
{
F_5 ( F_6 () || F_16 () ) ;
#ifdef F_21
F_22 () ;
#endif
if ( F_9 () == V_13 )
F_17 ( V_6 ) ;
F_18 ( V_7 - 1 ) ;
if ( F_23 ( ! F_24 () && F_25 () ) ) {
F_26 () ;
}
F_27 () ;
#ifdef F_21
F_28 () ;
#endif
F_29 () ;
}
static inline bool F_30 ( void )
{
bool V_14 = false ;
if ( F_31 ( V_15 ) ) {
V_14 = true ;
F_32 () ;
}
F_33 () ;
return V_14 ;
}
static inline void F_34 ( bool V_14 )
{
F_35 () ;
if ( V_14 )
F_36 () ;
}
static inline bool F_30 ( void ) { return false ; }
static inline void F_34 ( bool V_14 ) { }
T_1 T_2 void F_37 ( void )
{
unsigned long V_16 = V_17 + V_18 ;
unsigned long V_19 = V_15 -> V_8 ;
int V_20 = V_21 ;
struct V_22 * V_23 ;
bool V_14 ;
T_3 V_24 ;
int V_25 ;
V_15 -> V_8 &= ~ V_26 ;
V_24 = F_25 () ;
F_38 ( V_15 ) ;
F_4 ( V_12 , V_27 ) ;
V_14 = F_30 () ;
V_28:
F_39 ( 0 ) ;
F_28 () ;
V_23 = V_29 ;
while ( ( V_25 = F_40 ( V_24 ) ) ) {
unsigned int V_30 ;
int V_31 ;
V_23 += V_25 - 1 ;
V_30 = V_23 - V_29 ;
V_31 = F_12 () ;
F_41 ( V_30 ) ;
F_42 ( V_30 ) ;
V_23 -> V_32 ( V_23 ) ;
F_43 ( V_30 ) ;
if ( F_23 ( V_31 != F_12 () ) ) {
F_44 ( L_1 ,
V_30 , V_33 [ V_30 ] , V_23 -> V_32 ,
V_31 , F_12 () ) ;
F_45 ( V_31 ) ;
}
V_23 ++ ;
V_24 >>= V_25 ;
}
F_46 ( F_47 () ) ;
F_22 () ;
V_24 = F_25 () ;
if ( V_24 ) {
if ( F_48 ( V_17 , V_16 ) && ! F_49 () &&
-- V_20 )
goto V_28;
F_1 () ;
}
F_34 ( V_14 ) ;
F_50 ( V_15 ) ;
F_15 ( V_27 ) ;
F_5 ( F_24 () ) ;
F_51 ( V_15 , V_19 , V_26 ) ;
}
T_1 T_2 void F_26 ( void )
{
T_3 V_24 ;
unsigned long V_8 ;
if ( F_24 () )
return;
F_52 ( V_8 ) ;
V_24 = F_25 () ;
if ( V_24 )
F_53 () ;
F_54 ( V_8 ) ;
}
void F_55 ( void )
{
F_56 () ;
if ( F_57 ( V_15 ) && ! F_24 () ) {
F_58 () ;
F_59 () ;
F_19 () ;
}
F_60 () ;
}
static inline void F_61 ( void )
{
if ( ! V_34 ) {
#ifdef F_62
F_37 () ;
#else
F_53 () ;
#endif
} else {
F_1 () ;
}
}
static inline void F_63 ( void )
{
#ifdef F_64
int V_35 = F_47 () ;
if ( ( F_65 ( V_35 ) && ! F_49 () ) || F_66 ( V_35 ) ) {
if ( ! F_24 () )
F_67 () ;
}
#endif
}
void F_68 ( void )
{
#ifndef F_69
F_22 () ;
#else
F_5 ( ! F_16 () ) ;
#endif
F_50 ( V_15 ) ;
F_18 ( V_36 ) ;
if ( ! F_24 () && F_25 () )
F_61 () ;
F_63 () ;
F_70 () ;
F_32 () ;
}
inline void F_71 ( unsigned int V_37 )
{
F_72 ( V_37 ) ;
if ( ! F_24 () )
F_1 () ;
}
void F_73 ( unsigned int V_37 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
F_71 ( V_37 ) ;
F_54 ( V_8 ) ;
}
void F_72 ( unsigned int V_37 )
{
F_74 ( V_37 ) ;
F_75 ( 1UL << V_37 ) ;
}
void F_76 ( int V_37 , void (* V_32)( struct V_22 * ) )
{
V_29 [ V_37 ] . V_32 = V_32 ;
}
void F_77 ( struct V_38 * V_39 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
V_39 -> V_40 = NULL ;
* F_2 ( V_41 . V_42 ) = V_39 ;
F_78 ( V_41 . V_42 , & ( V_39 -> V_40 ) ) ;
F_71 ( V_43 ) ;
F_54 ( V_8 ) ;
}
void F_79 ( struct V_38 * V_39 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
V_39 -> V_40 = NULL ;
* F_2 ( V_44 . V_42 ) = V_39 ;
F_78 ( V_44 . V_42 , & ( V_39 -> V_40 ) ) ;
F_71 ( V_45 ) ;
F_54 ( V_8 ) ;
}
void F_80 ( struct V_38 * V_39 )
{
F_81 ( ! F_16 () ) ;
V_39 -> V_40 = F_2 ( V_44 . V_46 ) ;
F_78 ( V_44 . V_46 , V_39 ) ;
F_72 ( V_45 ) ;
}
static void F_82 ( struct V_22 * V_47 )
{
struct V_38 * V_48 ;
F_22 () ;
V_48 = F_2 ( V_41 . V_46 ) ;
F_78 ( V_41 . V_46 , NULL ) ;
F_78 ( V_41 . V_42 , & F_83 ( V_41 ) . V_46 ) ;
F_28 () ;
while ( V_48 ) {
struct V_38 * V_39 = V_48 ;
V_48 = V_48 -> V_40 ;
if ( F_84 ( V_39 ) ) {
if ( ! F_85 ( & V_39 -> V_49 ) ) {
if ( ! F_86 ( V_50 ,
& V_39 -> V_4 ) )
F_87 () ;
V_39 -> V_51 ( V_39 -> V_52 ) ;
F_88 ( V_39 ) ;
continue;
}
F_88 ( V_39 ) ;
}
F_22 () ;
V_39 -> V_40 = NULL ;
* F_2 ( V_41 . V_42 ) = V_39 ;
F_78 ( V_41 . V_42 , & ( V_39 -> V_40 ) ) ;
F_72 ( V_43 ) ;
F_28 () ;
}
}
static void F_89 ( struct V_22 * V_47 )
{
struct V_38 * V_48 ;
F_22 () ;
V_48 = F_2 ( V_44 . V_46 ) ;
F_78 ( V_44 . V_46 , NULL ) ;
F_78 ( V_44 . V_42 , & F_83 ( V_44 ) . V_46 ) ;
F_28 () ;
while ( V_48 ) {
struct V_38 * V_39 = V_48 ;
V_48 = V_48 -> V_40 ;
if ( F_84 ( V_39 ) ) {
if ( ! F_85 ( & V_39 -> V_49 ) ) {
if ( ! F_86 ( V_50 ,
& V_39 -> V_4 ) )
F_87 () ;
V_39 -> V_51 ( V_39 -> V_52 ) ;
F_88 ( V_39 ) ;
continue;
}
F_88 ( V_39 ) ;
}
F_22 () ;
V_39 -> V_40 = NULL ;
* F_2 ( V_44 . V_42 ) = V_39 ;
F_78 ( V_44 . V_42 , & ( V_39 -> V_40 ) ) ;
F_72 ( V_45 ) ;
F_28 () ;
}
}
void F_90 ( struct V_38 * V_39 ,
void (* V_51)( unsigned long ) , unsigned long V_52 )
{
V_39 -> V_40 = NULL ;
V_39 -> V_4 = 0 ;
F_91 ( & V_39 -> V_49 , 0 ) ;
V_39 -> V_51 = V_51 ;
V_39 -> V_52 = V_52 ;
}
void F_92 ( struct V_38 * V_39 )
{
if ( F_24 () )
F_93 ( L_2 ) ;
while ( F_94 ( V_50 , & V_39 -> V_4 ) ) {
do {
F_95 () ;
} while ( F_96 ( V_50 , & V_39 -> V_4 ) );
}
F_97 ( V_39 ) ;
F_98 ( V_50 , & V_39 -> V_4 ) ;
}
static enum V_53 F_99 ( struct V_54 * V_55 )
{
struct V_56 * V_57 =
F_100 ( V_55 , struct V_56 , V_55 ) ;
F_101 ( & V_57 -> V_58 ) ;
return V_59 ;
}
static void F_102 ( unsigned long V_52 )
{
struct V_56 * V_57 = ( void * ) V_52 ;
enum V_53 V_28 ;
V_28 = V_57 -> V_60 ( & V_57 -> V_55 ) ;
if ( V_28 != V_59 )
V_53 ( & V_57 -> V_55 ) ;
}
void T_4 F_103 ( void )
{
int V_35 ;
F_104 (cpu) {
F_105 ( V_41 , V_35 ) . V_42 =
& F_105 ( V_41 , V_35 ) . V_46 ;
F_105 ( V_44 , V_35 ) . V_42 =
& F_105 ( V_44 , V_35 ) . V_46 ;
}
F_76 ( V_43 , F_82 ) ;
F_76 ( V_45 , F_89 ) ;
}
static int F_106 ( unsigned int V_35 )
{
return F_25 () ;
}
static void F_107 ( unsigned int V_35 )
{
F_22 () ;
if ( F_25 () ) {
F_37 () ;
F_108 ( V_35 ) ;
F_28 () ;
F_109 () ;
return;
}
F_28 () ;
}
void F_110 ( struct V_38 * V_39 , unsigned int V_35 )
{
struct V_38 * * V_61 ;
F_81 ( F_111 ( V_35 ) ) ;
F_81 ( F_96 ( V_62 , & V_39 -> V_4 ) ) ;
if ( ! F_96 ( V_50 , & V_39 -> V_4 ) )
return;
for ( V_61 = & F_105 ( V_41 , V_35 ) . V_46 ; * V_61 ; V_61 = & ( * V_61 ) -> V_40 ) {
if ( * V_61 == V_39 ) {
* V_61 = V_39 -> V_40 ;
if ( * V_61 == NULL )
F_105 ( V_41 , V_35 ) . V_42 = V_61 ;
return;
}
}
F_87 () ;
}
static void F_112 ( unsigned int V_35 )
{
F_22 () ;
if ( & F_105 ( V_41 , V_35 ) . V_46 != F_105 ( V_41 , V_35 ) . V_42 ) {
* F_2 ( V_41 . V_42 ) = F_105 ( V_41 , V_35 ) . V_46 ;
F_113 ( V_41 . V_42 , F_105 ( V_41 , V_35 ) . V_42 ) ;
F_105 ( V_41 , V_35 ) . V_46 = NULL ;
F_105 ( V_41 , V_35 ) . V_42 = & F_105 ( V_41 , V_35 ) . V_46 ;
}
F_71 ( V_43 ) ;
if ( & F_105 ( V_44 , V_35 ) . V_46 != F_105 ( V_44 , V_35 ) . V_42 ) {
* F_2 ( V_44 . V_42 ) = F_105 ( V_44 , V_35 ) . V_46 ;
F_78 ( V_44 . V_42 , F_105 ( V_44 , V_35 ) . V_42 ) ;
F_105 ( V_44 , V_35 ) . V_46 = NULL ;
F_105 ( V_44 , V_35 ) . V_42 = & F_105 ( V_44 , V_35 ) . V_46 ;
}
F_71 ( V_45 ) ;
F_28 () ;
}
static int F_114 ( struct V_63 * V_64 , unsigned long V_32 ,
void * V_65 )
{
switch ( V_32 ) {
#ifdef F_115
case V_66 :
case V_67 :
F_112 ( ( unsigned long ) V_65 ) ;
break;
#endif
}
return V_68 ;
}
static T_4 int F_116 ( void )
{
F_117 ( & V_69 ) ;
F_81 ( F_118 ( & V_70 ) ) ;
return 0 ;
}
int T_4 __weak F_119 ( void )
{
return 0 ;
}
int T_4 __weak F_120 ( void )
{
return V_71 ;
}
int T_4 __weak F_121 ( void )
{
return 0 ;
}
unsigned int __weak F_122 ( unsigned int V_72 )
{
return V_72 ;
}
