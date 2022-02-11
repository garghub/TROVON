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
F_8 ( V_7 ) ;
if ( F_9 () == V_7 )
F_10 ( V_6 ) ;
F_11 ( V_8 ) ;
if ( F_12 () == V_7 )
F_13 ( V_9 , F_14 ( V_10 ) ) ;
}
static inline void F_4 ( unsigned long V_6 , unsigned int V_7 )
{
F_15 ( V_7 ) ;
F_16 () ;
}
void F_17 ( void )
{
F_4 ( V_11 , V_12 ) ;
}
static void F_18 ( unsigned int V_7 )
{
F_5 ( ! F_19 () ) ;
if ( F_9 () == V_7 )
F_20 ( V_11 ) ;
F_21 ( V_7 ) ;
}
void F_22 ( void )
{
F_5 ( F_6 () ) ;
F_18 ( V_12 ) ;
}
static inline void F_23 ( unsigned long V_6 )
{
F_5 ( F_6 () || F_19 () ) ;
#ifdef F_24
F_25 () ;
#endif
if ( F_9 () == V_12 )
F_20 ( V_6 ) ;
F_21 ( V_12 - 1 ) ;
if ( F_26 ( ! F_27 () && F_28 () ) ) {
F_29 () ;
}
F_30 () ;
#ifdef F_24
F_31 () ;
#endif
F_32 () ;
}
void F_33 ( void )
{
F_23 ( V_11 ) ;
}
void F_34 ( unsigned long V_6 )
{
F_23 ( V_6 ) ;
}
T_1 void F_35 ( void )
{
struct V_13 * V_14 ;
T_2 V_15 ;
unsigned long V_16 = V_17 + V_18 ;
int V_19 ;
unsigned long V_20 = V_21 -> V_8 ;
int V_22 = V_23 ;
V_21 -> V_8 &= ~ V_24 ;
V_15 = F_28 () ;
F_36 ( V_21 ) ;
F_4 ( V_11 , V_25 ) ;
F_37 () ;
V_19 = F_38 () ;
V_26:
F_39 ( 0 ) ;
F_31 () ;
V_14 = V_27 ;
do {
if ( V_15 & 1 ) {
unsigned int V_28 = V_14 - V_27 ;
int V_29 = F_12 () ;
F_40 ( V_28 ) ;
F_41 ( V_28 ) ;
V_14 -> V_30 ( V_14 ) ;
F_42 ( V_28 ) ;
if ( F_26 ( V_29 != F_12 () ) ) {
F_43 ( V_31 L_1
L_2
L_3 , V_28 ,
V_32 [ V_28 ] , V_14 -> V_30 ,
V_29 , F_12 () ) ;
F_44 ( V_29 ) ;
}
F_45 ( V_19 ) ;
}
V_14 ++ ;
V_15 >>= 1 ;
} while ( V_15 );
F_25 () ;
V_15 = F_28 () ;
if ( V_15 ) {
if ( F_46 ( V_17 , V_16 ) && ! F_47 () &&
-- V_22 )
goto V_26;
F_1 () ;
}
F_48 () ;
F_49 ( V_21 ) ;
F_18 ( V_25 ) ;
F_5 ( F_27 () ) ;
F_50 ( V_21 , V_20 , V_24 ) ;
}
T_1 void F_29 ( void )
{
T_2 V_15 ;
unsigned long V_8 ;
if ( F_27 () )
return;
F_51 ( V_8 ) ;
V_15 = F_28 () ;
if ( V_15 )
F_52 () ;
F_53 ( V_8 ) ;
}
void F_54 ( void )
{
int V_19 = F_38 () ;
F_55 () ;
if ( F_56 ( V_21 ) && ! F_27 () ) {
F_17 () ;
F_57 ( V_19 ) ;
F_22 () ;
}
F_58 () ;
}
static inline void F_59 ( void )
{
if ( ! V_33 ) {
#ifdef F_60
F_35 () ;
#else
F_52 () ;
#endif
} else {
F_1 () ;
}
}
static inline void F_61 ( void )
{
#ifdef F_62
int V_19 = F_38 () ;
if ( ( F_63 ( V_19 ) && ! F_47 () ) || F_64 ( V_19 ) ) {
if ( ! F_27 () )
F_65 () ;
}
#endif
}
void F_66 ( void )
{
#ifndef F_67
F_25 () ;
#else
F_5 ( ! F_19 () ) ;
#endif
F_49 ( V_21 ) ;
F_68 () ;
F_21 ( V_34 ) ;
if ( ! F_27 () && F_28 () )
F_59 () ;
F_61 () ;
F_69 () ;
}
inline void F_70 ( unsigned int V_35 )
{
F_71 ( V_35 ) ;
if ( ! F_27 () )
F_1 () ;
}
void F_72 ( unsigned int V_35 )
{
unsigned long V_8 ;
F_51 ( V_8 ) ;
F_70 ( V_35 ) ;
F_53 ( V_8 ) ;
}
void F_71 ( unsigned int V_35 )
{
F_73 ( V_35 ) ;
F_74 ( 1UL << V_35 ) ;
}
void F_75 ( int V_35 , void (* V_30)( struct V_13 * ) )
{
V_27 [ V_35 ] . V_30 = V_30 ;
}
void F_76 ( struct V_36 * V_37 )
{
unsigned long V_8 ;
F_51 ( V_8 ) ;
V_37 -> V_38 = NULL ;
* F_2 ( V_39 . V_40 ) = V_37 ;
F_77 ( V_39 . V_40 , & ( V_37 -> V_38 ) ) ;
F_70 ( V_41 ) ;
F_53 ( V_8 ) ;
}
void F_78 ( struct V_36 * V_37 )
{
unsigned long V_8 ;
F_51 ( V_8 ) ;
V_37 -> V_38 = NULL ;
* F_2 ( V_42 . V_40 ) = V_37 ;
F_77 ( V_42 . V_40 , & ( V_37 -> V_38 ) ) ;
F_70 ( V_43 ) ;
F_53 ( V_8 ) ;
}
void F_79 ( struct V_36 * V_37 )
{
F_80 ( ! F_19 () ) ;
V_37 -> V_38 = F_2 ( V_42 . V_44 ) ;
F_77 ( V_42 . V_44 , V_37 ) ;
F_71 ( V_43 ) ;
}
static void F_81 ( struct V_13 * V_45 )
{
struct V_36 * V_46 ;
F_25 () ;
V_46 = F_2 ( V_39 . V_44 ) ;
F_77 ( V_39 . V_44 , NULL ) ;
F_77 ( V_39 . V_40 , & F_82 ( V_39 ) . V_44 ) ;
F_31 () ;
while ( V_46 ) {
struct V_36 * V_37 = V_46 ;
V_46 = V_46 -> V_38 ;
if ( F_83 ( V_37 ) ) {
if ( ! F_84 ( & V_37 -> V_47 ) ) {
if ( ! F_85 ( V_48 , & V_37 -> V_4 ) )
F_86 () ;
V_37 -> V_49 ( V_37 -> V_50 ) ;
F_87 ( V_37 ) ;
continue;
}
F_87 ( V_37 ) ;
}
F_25 () ;
V_37 -> V_38 = NULL ;
* F_2 ( V_39 . V_40 ) = V_37 ;
F_77 ( V_39 . V_40 , & ( V_37 -> V_38 ) ) ;
F_71 ( V_41 ) ;
F_31 () ;
}
}
static void F_88 ( struct V_13 * V_45 )
{
struct V_36 * V_46 ;
F_25 () ;
V_46 = F_2 ( V_42 . V_44 ) ;
F_77 ( V_42 . V_44 , NULL ) ;
F_77 ( V_42 . V_40 , & F_82 ( V_42 ) . V_44 ) ;
F_31 () ;
while ( V_46 ) {
struct V_36 * V_37 = V_46 ;
V_46 = V_46 -> V_38 ;
if ( F_83 ( V_37 ) ) {
if ( ! F_84 ( & V_37 -> V_47 ) ) {
if ( ! F_85 ( V_48 , & V_37 -> V_4 ) )
F_86 () ;
V_37 -> V_49 ( V_37 -> V_50 ) ;
F_87 ( V_37 ) ;
continue;
}
F_87 ( V_37 ) ;
}
F_25 () ;
V_37 -> V_38 = NULL ;
* F_2 ( V_42 . V_40 ) = V_37 ;
F_77 ( V_42 . V_40 , & ( V_37 -> V_38 ) ) ;
F_71 ( V_43 ) ;
F_31 () ;
}
}
void F_89 ( struct V_36 * V_37 ,
void (* V_49)( unsigned long ) , unsigned long V_50 )
{
V_37 -> V_38 = NULL ;
V_37 -> V_4 = 0 ;
F_90 ( & V_37 -> V_47 , 0 ) ;
V_37 -> V_49 = V_49 ;
V_37 -> V_50 = V_50 ;
}
void F_91 ( struct V_36 * V_37 )
{
if ( F_27 () )
F_43 ( L_4 ) ;
while ( F_92 ( V_48 , & V_37 -> V_4 ) ) {
do {
F_93 () ;
} while ( F_94 ( V_48 , & V_37 -> V_4 ) );
}
F_95 ( V_37 ) ;
F_96 ( V_48 , & V_37 -> V_4 ) ;
}
static enum V_51 F_97 ( struct V_52 * V_53 )
{
struct V_54 * V_55 =
F_98 ( V_53 , struct V_54 , V_53 ) ;
F_99 ( & V_55 -> V_56 ) ;
return V_57 ;
}
static void F_100 ( unsigned long V_50 )
{
struct V_54 * V_55 = ( void * ) V_50 ;
enum V_51 V_26 ;
V_26 = V_55 -> V_58 ( & V_55 -> V_53 ) ;
if ( V_26 != V_57 )
V_51 ( & V_55 -> V_53 ) ;
}
void T_3 F_101 ( void )
{
int V_19 ;
F_102 (cpu) {
F_103 ( V_39 , V_19 ) . V_40 =
& F_103 ( V_39 , V_19 ) . V_44 ;
F_103 ( V_42 , V_19 ) . V_40 =
& F_103 ( V_42 , V_19 ) . V_44 ;
}
F_75 ( V_41 , F_81 ) ;
F_75 ( V_43 , F_88 ) ;
}
static int F_104 ( unsigned int V_19 )
{
return F_28 () ;
}
static void F_105 ( unsigned int V_19 )
{
F_25 () ;
if ( F_28 () ) {
F_35 () ;
F_106 ( V_19 ) ;
F_31 () ;
F_107 () ;
return;
}
F_31 () ;
}
void F_108 ( struct V_36 * V_37 , unsigned int V_19 )
{
struct V_36 * * V_59 ;
F_80 ( F_109 ( V_19 ) ) ;
F_80 ( F_94 ( V_60 , & V_37 -> V_4 ) ) ;
if ( ! F_94 ( V_48 , & V_37 -> V_4 ) )
return;
for ( V_59 = & F_103 ( V_39 , V_19 ) . V_44 ; * V_59 ; V_59 = & ( * V_59 ) -> V_38 ) {
if ( * V_59 == V_37 ) {
* V_59 = V_37 -> V_38 ;
if ( * V_59 == NULL )
F_103 ( V_39 , V_19 ) . V_40 = V_59 ;
return;
}
}
F_86 () ;
}
static void F_110 ( unsigned int V_19 )
{
F_25 () ;
if ( & F_103 ( V_39 , V_19 ) . V_44 != F_103 ( V_39 , V_19 ) . V_40 ) {
* F_2 ( V_39 . V_40 ) = F_103 ( V_39 , V_19 ) . V_44 ;
F_111 ( V_39 . V_40 , F_103 ( V_39 , V_19 ) . V_40 ) ;
F_103 ( V_39 , V_19 ) . V_44 = NULL ;
F_103 ( V_39 , V_19 ) . V_40 = & F_103 ( V_39 , V_19 ) . V_44 ;
}
F_70 ( V_41 ) ;
if ( & F_103 ( V_42 , V_19 ) . V_44 != F_103 ( V_42 , V_19 ) . V_40 ) {
* F_2 ( V_42 . V_40 ) = F_103 ( V_42 , V_19 ) . V_44 ;
F_77 ( V_42 . V_40 , F_103 ( V_42 , V_19 ) . V_40 ) ;
F_103 ( V_42 , V_19 ) . V_44 = NULL ;
F_103 ( V_42 , V_19 ) . V_40 = & F_103 ( V_42 , V_19 ) . V_44 ;
}
F_70 ( V_43 ) ;
F_31 () ;
}
static int F_112 ( struct V_61 * V_62 ,
unsigned long V_30 ,
void * V_63 )
{
switch ( V_30 ) {
#ifdef F_113
case V_64 :
case V_65 :
F_110 ( ( unsigned long ) V_63 ) ;
break;
#endif
}
return V_66 ;
}
static T_3 int F_114 ( void )
{
F_115 ( & V_67 ) ;
F_80 ( F_116 ( & V_68 ) ) ;
return 0 ;
}
int T_3 __weak F_117 ( void )
{
return 0 ;
}
int T_3 __weak F_118 ( void )
{
return V_69 ;
}
int T_3 __weak F_119 ( void )
{
return 0 ;
}
