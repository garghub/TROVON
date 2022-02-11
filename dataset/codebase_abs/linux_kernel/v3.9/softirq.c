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
unsigned long V_15 = V_16 + V_17 ;
int V_18 ;
unsigned long V_19 = V_20 -> V_8 ;
V_20 -> V_8 &= ~ V_21 ;
V_14 = F_28 () ;
F_36 ( V_20 ) ;
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_22 ) ;
F_37 () ;
V_18 = F_38 () ;
V_23:
F_39 ( 0 ) ;
F_31 () ;
V_13 = V_24 ;
do {
if ( V_14 & 1 ) {
unsigned int V_25 = V_13 - V_24 ;
int V_26 = F_8 () ;
F_40 ( V_25 ) ;
F_41 ( V_25 ) ;
V_13 -> V_27 ( V_13 ) ;
F_42 ( V_25 ) ;
if ( F_26 ( V_26 != F_8 () ) ) {
F_43 ( V_28 L_1
L_2
L_3 , V_25 ,
V_29 [ V_25 ] , V_13 -> V_27 ,
V_26 , F_8 () ) ;
F_8 () = V_26 ;
}
F_44 ( V_18 ) ;
}
V_13 ++ ;
V_14 >>= 1 ;
} while ( V_14 );
F_25 () ;
V_14 = F_28 () ;
if ( V_14 ) {
if ( F_45 ( V_16 , V_15 ) && ! F_46 () )
goto V_23;
F_1 () ;
}
F_47 () ;
F_48 ( V_20 ) ;
F_18 ( V_22 ) ;
F_49 ( V_20 , V_19 , V_21 ) ;
}
T_1 void F_29 ( void )
{
T_2 V_14 ;
unsigned long V_8 ;
if ( F_27 () )
return;
F_50 ( V_8 ) ;
V_14 = F_28 () ;
if ( V_14 )
F_35 () ;
F_51 ( V_8 ) ;
}
void F_52 ( void )
{
int V_18 = F_38 () ;
F_53 () ;
if ( F_54 ( V_20 ) && ! F_27 () ) {
F_16 () ;
F_55 ( V_18 ) ;
F_22 () ;
}
F_56 () ;
}
static inline void F_57 ( void )
{
if ( ! V_30 )
F_35 () ;
else
F_1 () ;
}
void F_58 ( void )
{
#ifndef F_59
F_25 () ;
#else
F_5 ( ! F_19 () ) ;
#endif
F_48 ( V_20 ) ;
F_60 () ;
F_21 ( V_31 ) ;
if ( ! F_27 () && F_28 () )
F_57 () ;
#ifdef F_61
if ( F_62 ( F_38 () ) && ! F_27 () && ! F_46 () )
F_63 () ;
#endif
F_64 () ;
}
inline void F_65 ( unsigned int V_32 )
{
F_66 ( V_32 ) ;
if ( ! F_27 () )
F_1 () ;
}
void F_67 ( unsigned int V_32 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
F_65 ( V_32 ) ;
F_51 ( V_8 ) ;
}
void F_66 ( unsigned int V_32 )
{
F_68 ( V_32 ) ;
F_69 ( 1UL << V_32 ) ;
}
void F_70 ( int V_32 , void (* V_27)( struct V_12 * ) )
{
V_24 [ V_32 ] . V_27 = V_27 ;
}
void F_71 ( struct V_33 * V_34 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
V_34 -> V_35 = NULL ;
* F_2 ( V_36 . V_37 ) = V_34 ;
F_72 ( V_36 . V_37 , & ( V_34 -> V_35 ) ) ;
F_65 ( V_38 ) ;
F_51 ( V_8 ) ;
}
void F_73 ( struct V_33 * V_34 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
V_34 -> V_35 = NULL ;
* F_2 ( V_39 . V_37 ) = V_34 ;
F_72 ( V_39 . V_37 , & ( V_34 -> V_35 ) ) ;
F_65 ( V_40 ) ;
F_51 ( V_8 ) ;
}
void F_74 ( struct V_33 * V_34 )
{
F_75 ( ! F_19 () ) ;
V_34 -> V_35 = F_2 ( V_39 . V_41 ) ;
F_72 ( V_39 . V_41 , V_34 ) ;
F_66 ( V_40 ) ;
}
static void F_76 ( struct V_12 * V_42 )
{
struct V_33 * V_43 ;
F_25 () ;
V_43 = F_2 ( V_36 . V_41 ) ;
F_72 ( V_36 . V_41 , NULL ) ;
F_72 ( V_36 . V_37 , & F_77 ( V_36 ) . V_41 ) ;
F_31 () ;
while ( V_43 ) {
struct V_33 * V_34 = V_43 ;
V_43 = V_43 -> V_35 ;
if ( F_78 ( V_34 ) ) {
if ( ! F_79 ( & V_34 -> V_44 ) ) {
if ( ! F_80 ( V_45 , & V_34 -> V_4 ) )
F_81 () ;
V_34 -> V_46 ( V_34 -> V_47 ) ;
F_82 ( V_34 ) ;
continue;
}
F_82 ( V_34 ) ;
}
F_25 () ;
V_34 -> V_35 = NULL ;
* F_2 ( V_36 . V_37 ) = V_34 ;
F_72 ( V_36 . V_37 , & ( V_34 -> V_35 ) ) ;
F_66 ( V_38 ) ;
F_31 () ;
}
}
static void F_83 ( struct V_12 * V_42 )
{
struct V_33 * V_43 ;
F_25 () ;
V_43 = F_2 ( V_39 . V_41 ) ;
F_72 ( V_39 . V_41 , NULL ) ;
F_72 ( V_39 . V_37 , & F_77 ( V_39 ) . V_41 ) ;
F_31 () ;
while ( V_43 ) {
struct V_33 * V_34 = V_43 ;
V_43 = V_43 -> V_35 ;
if ( F_78 ( V_34 ) ) {
if ( ! F_79 ( & V_34 -> V_44 ) ) {
if ( ! F_80 ( V_45 , & V_34 -> V_4 ) )
F_81 () ;
V_34 -> V_46 ( V_34 -> V_47 ) ;
F_82 ( V_34 ) ;
continue;
}
F_82 ( V_34 ) ;
}
F_25 () ;
V_34 -> V_35 = NULL ;
* F_2 ( V_39 . V_37 ) = V_34 ;
F_72 ( V_39 . V_37 , & ( V_34 -> V_35 ) ) ;
F_66 ( V_40 ) ;
F_31 () ;
}
}
void F_84 ( struct V_33 * V_34 ,
void (* V_46)( unsigned long ) , unsigned long V_47 )
{
V_34 -> V_35 = NULL ;
V_34 -> V_4 = 0 ;
F_85 ( & V_34 -> V_44 , 0 ) ;
V_34 -> V_46 = V_46 ;
V_34 -> V_47 = V_47 ;
}
void F_86 ( struct V_33 * V_34 )
{
if ( F_27 () )
F_43 ( L_4 ) ;
while ( F_87 ( V_45 , & V_34 -> V_4 ) ) {
do {
F_88 () ;
} while ( F_89 ( V_45 , & V_34 -> V_4 ) );
}
F_90 ( V_34 ) ;
F_91 ( V_45 , & V_34 -> V_4 ) ;
}
static enum V_48 F_92 ( struct V_49 * V_50 )
{
struct V_51 * V_52 =
F_93 ( V_50 , struct V_51 , V_50 ) ;
F_94 ( & V_52 -> V_53 ) ;
return V_54 ;
}
static void F_95 ( unsigned long V_47 )
{
struct V_51 * V_52 = ( void * ) V_47 ;
enum V_48 V_23 ;
V_23 = V_52 -> V_55 ( & V_52 -> V_50 ) ;
if ( V_23 != V_54 )
V_48 ( & V_52 -> V_50 ) ;
}
static void F_96 ( struct V_56 * V_57 , int V_58 )
{
struct V_59 * V_41 = & F_77 ( V_60 [ V_58 ] ) ;
F_97 ( & V_57 -> V_43 , V_41 ) ;
if ( V_41 -> V_35 == & V_57 -> V_43 )
F_65 ( V_58 ) ;
}
static void F_98 ( void * V_47 )
{
struct V_56 * V_57 = V_47 ;
unsigned long V_8 ;
int V_58 ;
V_58 = V_57 -> V_61 ;
F_50 ( V_8 ) ;
F_96 ( V_57 , V_58 ) ;
F_51 ( V_8 ) ;
}
static int F_99 ( struct V_56 * V_57 , int V_18 , int V_58 )
{
if ( F_100 ( V_18 ) ) {
V_57 -> V_46 = F_98 ;
V_57 -> V_62 = V_57 ;
V_57 -> V_8 = 0 ;
V_57 -> V_61 = V_58 ;
F_101 ( V_18 , V_57 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_99 ( struct V_56 * V_57 , int V_18 , int V_58 )
{
return 1 ;
}
void F_102 ( struct V_56 * V_57 , int V_18 , int V_63 , int V_58 )
{
if ( V_18 == V_63 || F_99 ( V_57 , V_18 , V_58 ) )
F_96 ( V_57 , V_58 ) ;
}
void F_103 ( struct V_56 * V_57 , int V_18 , int V_58 )
{
unsigned long V_8 ;
int V_63 ;
F_50 ( V_8 ) ;
V_63 = F_38 () ;
F_102 ( V_57 , V_18 , V_63 , V_58 ) ;
F_51 ( V_8 ) ;
}
static int T_3 F_104 ( struct V_64 * V_65 ,
unsigned long V_27 , void * V_66 )
{
if ( V_27 == V_67 || V_27 == V_68 ) {
int V_18 = ( unsigned long ) V_66 ;
int V_69 ;
F_25 () ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_59 * V_41 = & F_105 ( V_60 [ V_69 ] , V_18 ) ;
struct V_59 * V_71 ;
if ( F_106 ( V_41 ) )
continue;
V_71 = & F_77 ( V_60 [ V_69 ] ) ;
F_107 ( V_41 , V_71 ) ;
F_65 ( V_69 ) ;
}
F_31 () ;
}
return V_72 ;
}
void T_4 F_108 ( void )
{
int V_18 ;
F_109 (cpu) {
int V_69 ;
F_105 ( V_36 , V_18 ) . V_37 =
& F_105 ( V_36 , V_18 ) . V_41 ;
F_105 ( V_39 , V_18 ) . V_37 =
& F_105 ( V_39 , V_18 ) . V_41 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_110 ( & F_105 ( V_60 [ V_69 ] , V_18 ) ) ;
}
F_111 ( & V_73 ) ;
F_70 ( V_38 , F_76 ) ;
F_70 ( V_40 , F_83 ) ;
}
static int F_112 ( unsigned int V_18 )
{
return F_28 () ;
}
static void F_113 ( unsigned int V_18 )
{
F_25 () ;
if ( F_28 () ) {
F_35 () ;
F_114 ( V_18 ) ;
F_31 () ;
F_115 () ;
return;
}
F_31 () ;
}
void F_116 ( struct V_33 * V_34 , unsigned int V_18 )
{
struct V_33 * * V_69 ;
F_75 ( F_100 ( V_18 ) ) ;
F_75 ( F_89 ( V_74 , & V_34 -> V_4 ) ) ;
if ( ! F_89 ( V_45 , & V_34 -> V_4 ) )
return;
for ( V_69 = & F_105 ( V_36 , V_18 ) . V_41 ; * V_69 ; V_69 = & ( * V_69 ) -> V_35 ) {
if ( * V_69 == V_34 ) {
* V_69 = V_34 -> V_35 ;
if ( * V_69 == NULL )
F_105 ( V_36 , V_18 ) . V_37 = V_69 ;
return;
}
}
F_81 () ;
}
static void F_117 ( unsigned int V_18 )
{
F_25 () ;
if ( & F_105 ( V_36 , V_18 ) . V_41 != F_105 ( V_36 , V_18 ) . V_37 ) {
* F_2 ( V_36 . V_37 ) = F_105 ( V_36 , V_18 ) . V_41 ;
F_118 ( V_36 . V_37 , F_105 ( V_36 , V_18 ) . V_37 ) ;
F_105 ( V_36 , V_18 ) . V_41 = NULL ;
F_105 ( V_36 , V_18 ) . V_37 = & F_105 ( V_36 , V_18 ) . V_41 ;
}
F_65 ( V_38 ) ;
if ( & F_105 ( V_39 , V_18 ) . V_41 != F_105 ( V_39 , V_18 ) . V_37 ) {
* F_2 ( V_39 . V_37 ) = F_105 ( V_39 , V_18 ) . V_41 ;
F_72 ( V_39 . V_37 , F_105 ( V_39 , V_18 ) . V_37 ) ;
F_105 ( V_39 , V_18 ) . V_41 = NULL ;
F_105 ( V_39 , V_18 ) . V_37 = & F_105 ( V_39 , V_18 ) . V_41 ;
}
F_65 ( V_40 ) ;
F_31 () ;
}
static int T_3 F_119 ( struct V_64 * V_75 ,
unsigned long V_27 ,
void * V_66 )
{
switch ( V_27 ) {
#ifdef F_120
case V_67 :
case V_68 :
F_117 ( ( unsigned long ) V_66 ) ;
break;
#endif
}
return V_72 ;
}
static T_4 int F_121 ( void )
{
F_122 ( & V_76 ) ;
F_75 ( F_123 ( & V_77 ) ) ;
return 0 ;
}
int T_4 __weak F_124 ( void )
{
return 0 ;
}
int T_4 __weak F_125 ( void )
{
return V_78 ;
}
int T_4 __weak F_126 ( void )
{
return 0 ;
}
