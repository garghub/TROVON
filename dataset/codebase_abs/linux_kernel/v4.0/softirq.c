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
if ( F_12 () == V_7 ) {
#ifdef F_13
V_10 -> V_11 = F_14 ( V_12 ) ;
#endif
F_15 ( V_13 , F_14 ( V_12 ) ) ;
}
}
static void F_16 ( unsigned int V_7 )
{
F_5 ( ! F_17 () ) ;
if ( F_9 () == ( V_7 & V_9 ) )
F_18 ( V_14 ) ;
F_19 ( V_7 ) ;
}
void F_20 ( void )
{
F_5 ( F_6 () ) ;
F_16 ( V_15 ) ;
}
void F_21 ( unsigned long V_6 , unsigned int V_7 )
{
F_5 ( F_6 () || F_17 () ) ;
#ifdef F_22
F_23 () ;
#endif
if ( F_9 () == V_15 )
F_18 ( V_6 ) ;
F_19 ( V_7 - 1 ) ;
if ( F_24 ( ! F_25 () && F_26 () ) ) {
F_27 () ;
}
F_28 () ;
#ifdef F_22
F_29 () ;
#endif
F_30 () ;
}
static inline bool F_31 ( void )
{
bool V_16 = false ;
if ( F_32 ( V_10 ) ) {
V_16 = true ;
F_33 () ;
}
F_34 () ;
return V_16 ;
}
static inline void F_35 ( bool V_16 )
{
F_36 () ;
if ( V_16 )
F_37 () ;
}
static inline bool F_31 ( void ) { return false ; }
static inline void F_35 ( bool V_16 ) { }
T_1 T_2 void F_38 ( void )
{
unsigned long V_17 = V_18 + V_19 ;
unsigned long V_20 = V_10 -> V_8 ;
int V_21 = V_22 ;
struct V_23 * V_24 ;
bool V_16 ;
T_3 V_25 ;
int V_26 ;
V_10 -> V_8 &= ~ V_27 ;
V_25 = F_26 () ;
F_39 ( V_10 ) ;
F_4 ( V_14 , V_28 ) ;
V_16 = F_31 () ;
V_29:
F_40 ( 0 ) ;
F_29 () ;
V_24 = V_30 ;
while ( ( V_26 = F_41 ( V_25 ) ) ) {
unsigned int V_31 ;
int V_32 ;
V_24 += V_26 - 1 ;
V_31 = V_24 - V_30 ;
V_32 = F_12 () ;
F_42 ( V_31 ) ;
F_43 ( V_31 ) ;
V_24 -> V_33 ( V_24 ) ;
F_44 ( V_31 ) ;
if ( F_24 ( V_32 != F_12 () ) ) {
F_45 ( L_1 ,
V_31 , V_34 [ V_31 ] , V_24 -> V_33 ,
V_32 , F_12 () ) ;
F_46 ( V_32 ) ;
}
V_24 ++ ;
V_25 >>= V_26 ;
}
F_47 () ;
F_23 () ;
V_25 = F_26 () ;
if ( V_25 ) {
if ( F_48 ( V_18 , V_17 ) && ! F_49 () &&
-- V_21 )
goto V_29;
F_1 () ;
}
F_35 ( V_16 ) ;
F_50 ( V_10 ) ;
F_16 ( V_28 ) ;
F_5 ( F_25 () ) ;
F_51 ( V_10 , V_20 , V_27 ) ;
}
T_1 T_2 void F_27 ( void )
{
T_3 V_25 ;
unsigned long V_8 ;
if ( F_25 () )
return;
F_52 ( V_8 ) ;
V_25 = F_26 () ;
if ( V_25 )
F_53 () ;
F_54 ( V_8 ) ;
}
void F_55 ( void )
{
F_56 () ;
if ( F_57 ( V_10 ) && ! F_25 () ) {
F_58 () ;
F_59 () ;
F_20 () ;
}
F_60 () ;
}
static inline void F_61 ( void )
{
if ( ! V_35 ) {
#ifdef F_62
F_38 () ;
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
int V_36 = F_65 () ;
if ( ( F_66 ( V_36 ) && ! F_49 () ) || F_67 ( V_36 ) ) {
if ( ! F_25 () )
F_68 () ;
}
#endif
}
void F_69 ( void )
{
#ifndef F_70
F_23 () ;
#else
F_5 ( ! F_17 () ) ;
#endif
F_50 ( V_10 ) ;
F_19 ( V_37 ) ;
if ( ! F_25 () && F_26 () )
F_61 () ;
F_63 () ;
F_71 () ;
F_33 () ;
}
inline void F_72 ( unsigned int V_38 )
{
F_73 ( V_38 ) ;
if ( ! F_25 () )
F_1 () ;
}
void F_74 ( unsigned int V_38 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
F_72 ( V_38 ) ;
F_54 ( V_8 ) ;
}
void F_73 ( unsigned int V_38 )
{
F_75 ( V_38 ) ;
F_76 ( 1UL << V_38 ) ;
}
void F_77 ( int V_38 , void (* V_33)( struct V_23 * ) )
{
V_30 [ V_38 ] . V_33 = V_33 ;
}
void F_78 ( struct V_39 * V_40 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
V_40 -> V_41 = NULL ;
* F_2 ( V_42 . V_43 ) = V_40 ;
F_79 ( V_42 . V_43 , & ( V_40 -> V_41 ) ) ;
F_72 ( V_44 ) ;
F_54 ( V_8 ) ;
}
void F_80 ( struct V_39 * V_40 )
{
unsigned long V_8 ;
F_52 ( V_8 ) ;
V_40 -> V_41 = NULL ;
* F_2 ( V_45 . V_43 ) = V_40 ;
F_79 ( V_45 . V_43 , & ( V_40 -> V_41 ) ) ;
F_72 ( V_46 ) ;
F_54 ( V_8 ) ;
}
void F_81 ( struct V_39 * V_40 )
{
F_82 ( ! F_17 () ) ;
V_40 -> V_41 = F_2 ( V_45 . V_47 ) ;
F_79 ( V_45 . V_47 , V_40 ) ;
F_73 ( V_46 ) ;
}
static void F_83 ( struct V_23 * V_48 )
{
struct V_39 * V_49 ;
F_23 () ;
V_49 = F_2 ( V_42 . V_47 ) ;
F_79 ( V_42 . V_47 , NULL ) ;
F_79 ( V_42 . V_43 , F_84 ( & V_42 . V_47 ) ) ;
F_29 () ;
while ( V_49 ) {
struct V_39 * V_40 = V_49 ;
V_49 = V_49 -> V_41 ;
if ( F_85 ( V_40 ) ) {
if ( ! F_86 ( & V_40 -> V_50 ) ) {
if ( ! F_87 ( V_51 ,
& V_40 -> V_4 ) )
F_88 () ;
V_40 -> V_52 ( V_40 -> V_53 ) ;
F_89 ( V_40 ) ;
continue;
}
F_89 ( V_40 ) ;
}
F_23 () ;
V_40 -> V_41 = NULL ;
* F_2 ( V_42 . V_43 ) = V_40 ;
F_79 ( V_42 . V_43 , & ( V_40 -> V_41 ) ) ;
F_73 ( V_44 ) ;
F_29 () ;
}
}
static void F_90 ( struct V_23 * V_48 )
{
struct V_39 * V_49 ;
F_23 () ;
V_49 = F_2 ( V_45 . V_47 ) ;
F_79 ( V_45 . V_47 , NULL ) ;
F_79 ( V_45 . V_43 , F_84 ( & V_45 . V_47 ) ) ;
F_29 () ;
while ( V_49 ) {
struct V_39 * V_40 = V_49 ;
V_49 = V_49 -> V_41 ;
if ( F_85 ( V_40 ) ) {
if ( ! F_86 ( & V_40 -> V_50 ) ) {
if ( ! F_87 ( V_51 ,
& V_40 -> V_4 ) )
F_88 () ;
V_40 -> V_52 ( V_40 -> V_53 ) ;
F_89 ( V_40 ) ;
continue;
}
F_89 ( V_40 ) ;
}
F_23 () ;
V_40 -> V_41 = NULL ;
* F_2 ( V_45 . V_43 ) = V_40 ;
F_79 ( V_45 . V_43 , & ( V_40 -> V_41 ) ) ;
F_73 ( V_46 ) ;
F_29 () ;
}
}
void F_91 ( struct V_39 * V_40 ,
void (* V_52)( unsigned long ) , unsigned long V_53 )
{
V_40 -> V_41 = NULL ;
V_40 -> V_4 = 0 ;
F_92 ( & V_40 -> V_50 , 0 ) ;
V_40 -> V_52 = V_52 ;
V_40 -> V_53 = V_53 ;
}
void F_93 ( struct V_39 * V_40 )
{
if ( F_25 () )
F_94 ( L_2 ) ;
while ( F_95 ( V_51 , & V_40 -> V_4 ) ) {
do {
F_96 () ;
} while ( F_97 ( V_51 , & V_40 -> V_4 ) );
}
F_98 ( V_40 ) ;
F_99 ( V_51 , & V_40 -> V_4 ) ;
}
static enum V_54 F_100 ( struct V_55 * V_56 )
{
struct V_57 * V_58 =
F_101 ( V_56 , struct V_57 , V_56 ) ;
F_102 ( & V_58 -> V_59 ) ;
return V_60 ;
}
static void F_103 ( unsigned long V_53 )
{
struct V_57 * V_58 = ( void * ) V_53 ;
enum V_54 V_29 ;
V_29 = V_58 -> V_61 ( & V_58 -> V_56 ) ;
if ( V_29 != V_60 )
V_54 ( & V_58 -> V_56 ) ;
}
void T_4 F_104 ( void )
{
int V_36 ;
F_105 (cpu) {
F_106 ( V_42 , V_36 ) . V_43 =
& F_106 ( V_42 , V_36 ) . V_47 ;
F_106 ( V_45 , V_36 ) . V_43 =
& F_106 ( V_45 , V_36 ) . V_47 ;
}
F_77 ( V_44 , F_83 ) ;
F_77 ( V_46 , F_90 ) ;
}
static int F_107 ( unsigned int V_36 )
{
return F_26 () ;
}
static void F_108 ( unsigned int V_36 )
{
F_23 () ;
if ( F_26 () ) {
F_38 () ;
F_29 () ;
F_109 () ;
return;
}
F_29 () ;
}
void F_110 ( struct V_39 * V_40 , unsigned int V_36 )
{
struct V_39 * * V_62 ;
F_82 ( F_111 ( V_36 ) ) ;
F_82 ( F_97 ( V_63 , & V_40 -> V_4 ) ) ;
if ( ! F_97 ( V_51 , & V_40 -> V_4 ) )
return;
for ( V_62 = & F_106 ( V_42 , V_36 ) . V_47 ; * V_62 ; V_62 = & ( * V_62 ) -> V_41 ) {
if ( * V_62 == V_40 ) {
* V_62 = V_40 -> V_41 ;
if ( * V_62 == NULL )
F_106 ( V_42 , V_36 ) . V_43 = V_62 ;
return;
}
}
F_88 () ;
}
static void F_112 ( unsigned int V_36 )
{
F_23 () ;
if ( & F_106 ( V_42 , V_36 ) . V_47 != F_106 ( V_42 , V_36 ) . V_43 ) {
* F_2 ( V_42 . V_43 ) = F_106 ( V_42 , V_36 ) . V_47 ;
F_113 ( V_42 . V_43 , F_106 ( V_42 , V_36 ) . V_43 ) ;
F_106 ( V_42 , V_36 ) . V_47 = NULL ;
F_106 ( V_42 , V_36 ) . V_43 = & F_106 ( V_42 , V_36 ) . V_47 ;
}
F_72 ( V_44 ) ;
if ( & F_106 ( V_45 , V_36 ) . V_47 != F_106 ( V_45 , V_36 ) . V_43 ) {
* F_2 ( V_45 . V_43 ) = F_106 ( V_45 , V_36 ) . V_47 ;
F_79 ( V_45 . V_43 , F_106 ( V_45 , V_36 ) . V_43 ) ;
F_106 ( V_45 , V_36 ) . V_47 = NULL ;
F_106 ( V_45 , V_36 ) . V_43 = & F_106 ( V_45 , V_36 ) . V_47 ;
}
F_72 ( V_46 ) ;
F_29 () ;
}
static int F_114 ( struct V_64 * V_65 , unsigned long V_33 ,
void * V_66 )
{
switch ( V_33 ) {
#ifdef F_115
case V_67 :
case V_68 :
F_112 ( ( unsigned long ) V_66 ) ;
break;
#endif
}
return V_69 ;
}
static T_4 int F_116 ( void )
{
F_117 ( & V_70 ) ;
F_82 ( F_118 ( & V_71 ) ) ;
return 0 ;
}
int T_4 __weak F_119 ( void )
{
return 0 ;
}
int T_4 __weak F_120 ( void )
{
return V_72 ;
}
int T_4 __weak F_121 ( void )
{
return 0 ;
}
unsigned int __weak F_122 ( unsigned int V_73 )
{
return V_73 ;
}
