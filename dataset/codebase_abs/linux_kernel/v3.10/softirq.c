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
int V_21 = V_22 ;
V_20 -> V_8 &= ~ V_23 ;
V_14 = F_28 () ;
F_36 ( V_20 ) ;
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_24 ) ;
F_37 () ;
V_18 = F_38 () ;
V_25:
F_39 ( 0 ) ;
F_31 () ;
V_13 = V_26 ;
do {
if ( V_14 & 1 ) {
unsigned int V_27 = V_13 - V_26 ;
int V_28 = F_8 () ;
F_40 ( V_27 ) ;
F_41 ( V_27 ) ;
V_13 -> V_29 ( V_13 ) ;
F_42 ( V_27 ) ;
if ( F_26 ( V_28 != F_8 () ) ) {
F_43 ( V_30 L_1
L_2
L_3 , V_27 ,
V_31 [ V_27 ] , V_13 -> V_29 ,
V_28 , F_8 () ) ;
F_8 () = V_28 ;
}
F_44 ( V_18 ) ;
}
V_13 ++ ;
V_14 >>= 1 ;
} while ( V_14 );
F_25 () ;
V_14 = F_28 () ;
if ( V_14 ) {
if ( F_45 ( V_16 , V_15 ) && ! F_46 () &&
-- V_21 )
goto V_25;
F_1 () ;
}
F_47 () ;
F_48 ( V_20 ) ;
F_18 ( V_24 ) ;
F_49 ( V_20 , V_19 , V_23 ) ;
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
if ( ! V_32 )
F_35 () ;
else
F_1 () ;
}
static inline void F_58 ( void )
{
#ifdef F_59
int V_18 = F_38 () ;
if ( ( F_60 ( V_18 ) && ! F_46 () ) || F_61 ( V_18 ) ) {
if ( ! F_27 () )
F_62 () ;
}
#endif
}
void F_63 ( void )
{
#ifndef F_64
F_25 () ;
#else
F_5 ( ! F_19 () ) ;
#endif
F_48 ( V_20 ) ;
F_65 () ;
F_21 ( V_33 ) ;
if ( ! F_27 () && F_28 () )
F_57 () ;
F_58 () ;
F_66 () ;
}
inline void F_67 ( unsigned int V_34 )
{
F_68 ( V_34 ) ;
if ( ! F_27 () )
F_1 () ;
}
void F_69 ( unsigned int V_34 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
F_67 ( V_34 ) ;
F_51 ( V_8 ) ;
}
void F_68 ( unsigned int V_34 )
{
F_70 ( V_34 ) ;
F_71 ( 1UL << V_34 ) ;
}
void F_72 ( int V_34 , void (* V_29)( struct V_12 * ) )
{
V_26 [ V_34 ] . V_29 = V_29 ;
}
void F_73 ( struct V_35 * V_36 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
V_36 -> V_37 = NULL ;
* F_2 ( V_38 . V_39 ) = V_36 ;
F_74 ( V_38 . V_39 , & ( V_36 -> V_37 ) ) ;
F_67 ( V_40 ) ;
F_51 ( V_8 ) ;
}
void F_75 ( struct V_35 * V_36 )
{
unsigned long V_8 ;
F_50 ( V_8 ) ;
V_36 -> V_37 = NULL ;
* F_2 ( V_41 . V_39 ) = V_36 ;
F_74 ( V_41 . V_39 , & ( V_36 -> V_37 ) ) ;
F_67 ( V_42 ) ;
F_51 ( V_8 ) ;
}
void F_76 ( struct V_35 * V_36 )
{
F_77 ( ! F_19 () ) ;
V_36 -> V_37 = F_2 ( V_41 . V_43 ) ;
F_74 ( V_41 . V_43 , V_36 ) ;
F_68 ( V_42 ) ;
}
static void F_78 ( struct V_12 * V_44 )
{
struct V_35 * V_45 ;
F_25 () ;
V_45 = F_2 ( V_38 . V_43 ) ;
F_74 ( V_38 . V_43 , NULL ) ;
F_74 ( V_38 . V_39 , & F_79 ( V_38 ) . V_43 ) ;
F_31 () ;
while ( V_45 ) {
struct V_35 * V_36 = V_45 ;
V_45 = V_45 -> V_37 ;
if ( F_80 ( V_36 ) ) {
if ( ! F_81 ( & V_36 -> V_46 ) ) {
if ( ! F_82 ( V_47 , & V_36 -> V_4 ) )
F_83 () ;
V_36 -> V_48 ( V_36 -> V_49 ) ;
F_84 ( V_36 ) ;
continue;
}
F_84 ( V_36 ) ;
}
F_25 () ;
V_36 -> V_37 = NULL ;
* F_2 ( V_38 . V_39 ) = V_36 ;
F_74 ( V_38 . V_39 , & ( V_36 -> V_37 ) ) ;
F_68 ( V_40 ) ;
F_31 () ;
}
}
static void F_85 ( struct V_12 * V_44 )
{
struct V_35 * V_45 ;
F_25 () ;
V_45 = F_2 ( V_41 . V_43 ) ;
F_74 ( V_41 . V_43 , NULL ) ;
F_74 ( V_41 . V_39 , & F_79 ( V_41 ) . V_43 ) ;
F_31 () ;
while ( V_45 ) {
struct V_35 * V_36 = V_45 ;
V_45 = V_45 -> V_37 ;
if ( F_80 ( V_36 ) ) {
if ( ! F_81 ( & V_36 -> V_46 ) ) {
if ( ! F_82 ( V_47 , & V_36 -> V_4 ) )
F_83 () ;
V_36 -> V_48 ( V_36 -> V_49 ) ;
F_84 ( V_36 ) ;
continue;
}
F_84 ( V_36 ) ;
}
F_25 () ;
V_36 -> V_37 = NULL ;
* F_2 ( V_41 . V_39 ) = V_36 ;
F_74 ( V_41 . V_39 , & ( V_36 -> V_37 ) ) ;
F_68 ( V_42 ) ;
F_31 () ;
}
}
void F_86 ( struct V_35 * V_36 ,
void (* V_48)( unsigned long ) , unsigned long V_49 )
{
V_36 -> V_37 = NULL ;
V_36 -> V_4 = 0 ;
F_87 ( & V_36 -> V_46 , 0 ) ;
V_36 -> V_48 = V_48 ;
V_36 -> V_49 = V_49 ;
}
void F_88 ( struct V_35 * V_36 )
{
if ( F_27 () )
F_43 ( L_4 ) ;
while ( F_89 ( V_47 , & V_36 -> V_4 ) ) {
do {
F_90 () ;
} while ( F_91 ( V_47 , & V_36 -> V_4 ) );
}
F_92 ( V_36 ) ;
F_93 ( V_47 , & V_36 -> V_4 ) ;
}
static enum V_50 F_94 ( struct V_51 * V_52 )
{
struct V_53 * V_54 =
F_95 ( V_52 , struct V_53 , V_52 ) ;
F_96 ( & V_54 -> V_55 ) ;
return V_56 ;
}
static void F_97 ( unsigned long V_49 )
{
struct V_53 * V_54 = ( void * ) V_49 ;
enum V_50 V_25 ;
V_25 = V_54 -> V_57 ( & V_54 -> V_52 ) ;
if ( V_25 != V_56 )
V_50 ( & V_54 -> V_52 ) ;
}
static void F_98 ( struct V_58 * V_59 , int V_60 )
{
struct V_61 * V_43 = & F_79 ( V_62 [ V_60 ] ) ;
F_99 ( & V_59 -> V_45 , V_43 ) ;
if ( V_43 -> V_37 == & V_59 -> V_45 )
F_67 ( V_60 ) ;
}
static void F_100 ( void * V_49 )
{
struct V_58 * V_59 = V_49 ;
unsigned long V_8 ;
int V_60 ;
V_60 = * ( int * ) V_59 -> V_63 ;
F_50 ( V_8 ) ;
F_98 ( V_59 , V_60 ) ;
F_51 ( V_8 ) ;
}
static int F_101 ( struct V_58 * V_59 , int V_18 , int V_60 )
{
if ( F_102 ( V_18 ) ) {
V_59 -> V_48 = F_100 ;
V_59 -> V_63 = & V_60 ;
V_59 -> V_8 = 0 ;
F_103 ( V_18 , V_59 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_101 ( struct V_58 * V_59 , int V_18 , int V_60 )
{
return 1 ;
}
void F_104 ( struct V_58 * V_59 , int V_18 , int V_64 , int V_60 )
{
if ( V_18 == V_64 || F_101 ( V_59 , V_18 , V_60 ) )
F_98 ( V_59 , V_60 ) ;
}
void F_105 ( struct V_58 * V_59 , int V_18 , int V_60 )
{
unsigned long V_8 ;
int V_64 ;
F_50 ( V_8 ) ;
V_64 = F_38 () ;
F_104 ( V_59 , V_18 , V_64 , V_60 ) ;
F_51 ( V_8 ) ;
}
static int T_3 F_106 ( struct V_65 * V_66 ,
unsigned long V_29 , void * V_67 )
{
if ( V_29 == V_68 || V_29 == V_69 ) {
int V_18 = ( unsigned long ) V_67 ;
int V_70 ;
F_25 () ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
struct V_61 * V_43 = & F_107 ( V_62 [ V_70 ] , V_18 ) ;
struct V_61 * V_72 ;
if ( F_108 ( V_43 ) )
continue;
V_72 = & F_79 ( V_62 [ V_70 ] ) ;
F_109 ( V_43 , V_72 ) ;
F_67 ( V_70 ) ;
}
F_31 () ;
}
return V_73 ;
}
void T_4 F_110 ( void )
{
int V_18 ;
F_111 (cpu) {
int V_70 ;
F_107 ( V_38 , V_18 ) . V_39 =
& F_107 ( V_38 , V_18 ) . V_43 ;
F_107 ( V_41 , V_18 ) . V_39 =
& F_107 ( V_41 , V_18 ) . V_43 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_112 ( & F_107 ( V_62 [ V_70 ] , V_18 ) ) ;
}
F_113 ( & V_74 ) ;
F_72 ( V_40 , F_78 ) ;
F_72 ( V_42 , F_85 ) ;
}
static int F_114 ( unsigned int V_18 )
{
return F_28 () ;
}
static void F_115 ( unsigned int V_18 )
{
F_25 () ;
if ( F_28 () ) {
F_35 () ;
F_116 ( V_18 ) ;
F_31 () ;
F_117 () ;
return;
}
F_31 () ;
}
void F_118 ( struct V_35 * V_36 , unsigned int V_18 )
{
struct V_35 * * V_70 ;
F_77 ( F_102 ( V_18 ) ) ;
F_77 ( F_91 ( V_75 , & V_36 -> V_4 ) ) ;
if ( ! F_91 ( V_47 , & V_36 -> V_4 ) )
return;
for ( V_70 = & F_107 ( V_38 , V_18 ) . V_43 ; * V_70 ; V_70 = & ( * V_70 ) -> V_37 ) {
if ( * V_70 == V_36 ) {
* V_70 = V_36 -> V_37 ;
if ( * V_70 == NULL )
F_107 ( V_38 , V_18 ) . V_39 = V_70 ;
return;
}
}
F_83 () ;
}
static void F_119 ( unsigned int V_18 )
{
F_25 () ;
if ( & F_107 ( V_38 , V_18 ) . V_43 != F_107 ( V_38 , V_18 ) . V_39 ) {
* F_2 ( V_38 . V_39 ) = F_107 ( V_38 , V_18 ) . V_43 ;
F_120 ( V_38 . V_39 , F_107 ( V_38 , V_18 ) . V_39 ) ;
F_107 ( V_38 , V_18 ) . V_43 = NULL ;
F_107 ( V_38 , V_18 ) . V_39 = & F_107 ( V_38 , V_18 ) . V_43 ;
}
F_67 ( V_40 ) ;
if ( & F_107 ( V_41 , V_18 ) . V_43 != F_107 ( V_41 , V_18 ) . V_39 ) {
* F_2 ( V_41 . V_39 ) = F_107 ( V_41 , V_18 ) . V_43 ;
F_74 ( V_41 . V_39 , F_107 ( V_41 , V_18 ) . V_39 ) ;
F_107 ( V_41 , V_18 ) . V_43 = NULL ;
F_107 ( V_41 , V_18 ) . V_39 = & F_107 ( V_41 , V_18 ) . V_43 ;
}
F_67 ( V_42 ) ;
F_31 () ;
}
static int T_3 F_121 ( struct V_65 * V_76 ,
unsigned long V_29 ,
void * V_67 )
{
switch ( V_29 ) {
#ifdef F_122
case V_68 :
case V_69 :
F_119 ( ( unsigned long ) V_67 ) ;
break;
#endif
}
return V_73 ;
}
static T_4 int F_123 ( void )
{
F_124 ( & V_77 ) ;
F_77 ( F_125 ( & V_78 ) ) ;
return 0 ;
}
int T_4 __weak F_126 ( void )
{
return 0 ;
}
int T_4 __weak F_127 ( void )
{
return V_79 ;
}
int T_4 __weak F_128 ( void )
{
return 0 ;
}
