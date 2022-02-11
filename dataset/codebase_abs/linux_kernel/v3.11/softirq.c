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
F_4 ( V_11 , V_12 ) ;
}
static void F_17 ( unsigned int V_7 )
{
F_5 ( F_6 () ) ;
F_5 ( ! F_18 () ) ;
if ( F_9 () == V_7 )
F_19 ( V_11 ) ;
F_20 ( V_7 ) ;
}
void F_21 ( void )
{
F_17 ( V_12 ) ;
}
static inline void F_22 ( unsigned long V_6 )
{
F_5 ( F_6 () || F_18 () ) ;
#ifdef F_23
F_24 () ;
#endif
if ( F_9 () == V_12 )
F_19 ( V_6 ) ;
F_20 ( V_12 - 1 ) ;
if ( F_25 ( ! F_26 () && F_27 () ) )
F_28 () ;
F_29 () ;
#ifdef F_23
F_30 () ;
#endif
F_31 () ;
}
void F_32 ( void )
{
F_22 ( V_11 ) ;
}
void F_33 ( unsigned long V_6 )
{
F_22 ( V_6 ) ;
}
T_1 void F_34 ( void )
{
struct V_13 * V_14 ;
T_2 V_15 ;
unsigned long V_16 = V_17 + V_18 ;
int V_19 ;
unsigned long V_20 = V_21 -> V_8 ;
int V_22 = V_23 ;
V_21 -> V_8 &= ~ V_24 ;
V_15 = F_27 () ;
F_35 ( V_21 ) ;
F_4 ( V_11 , V_25 ) ;
F_36 () ;
V_19 = F_37 () ;
V_26:
F_38 ( 0 ) ;
F_30 () ;
V_14 = V_27 ;
do {
if ( V_15 & 1 ) {
unsigned int V_28 = V_14 - V_27 ;
int V_29 = F_8 () ;
F_39 ( V_28 ) ;
F_40 ( V_28 ) ;
V_14 -> V_30 ( V_14 ) ;
F_41 ( V_28 ) ;
if ( F_25 ( V_29 != F_8 () ) ) {
F_42 ( V_31 L_1
L_2
L_3 , V_28 ,
V_32 [ V_28 ] , V_14 -> V_30 ,
V_29 , F_8 () ) ;
F_8 () = V_29 ;
}
F_43 ( V_19 ) ;
}
V_14 ++ ;
V_15 >>= 1 ;
} while ( V_15 );
F_24 () ;
V_15 = F_27 () ;
if ( V_15 ) {
if ( F_44 ( V_17 , V_16 ) && ! F_45 () &&
-- V_22 )
goto V_26;
F_1 () ;
}
F_46 () ;
F_47 ( V_21 ) ;
F_17 ( V_25 ) ;
F_48 ( V_21 , V_20 , V_24 ) ;
}
T_1 void F_28 ( void )
{
T_2 V_15 ;
unsigned long V_8 ;
if ( F_26 () )
return;
F_49 ( V_8 ) ;
V_15 = F_27 () ;
if ( V_15 )
F_34 () ;
F_50 ( V_8 ) ;
}
void F_51 ( void )
{
int V_19 = F_37 () ;
F_52 () ;
if ( F_53 ( V_21 ) && ! F_26 () ) {
F_16 () ;
F_54 ( V_19 ) ;
F_21 () ;
}
F_55 () ;
}
static inline void F_56 ( void )
{
if ( ! V_33 )
F_34 () ;
else
F_1 () ;
}
static inline void F_57 ( void )
{
#ifdef F_58
int V_19 = F_37 () ;
if ( ( F_59 ( V_19 ) && ! F_45 () ) || F_60 ( V_19 ) ) {
if ( ! F_26 () )
F_61 () ;
}
#endif
}
void F_62 ( void )
{
#ifndef F_63
F_24 () ;
#else
F_5 ( ! F_18 () ) ;
#endif
F_47 ( V_21 ) ;
F_64 () ;
F_20 ( V_34 ) ;
if ( ! F_26 () && F_27 () )
F_56 () ;
F_57 () ;
F_65 () ;
}
inline void F_66 ( unsigned int V_35 )
{
F_67 ( V_35 ) ;
if ( ! F_26 () )
F_1 () ;
}
void F_68 ( unsigned int V_35 )
{
unsigned long V_8 ;
F_49 ( V_8 ) ;
F_66 ( V_35 ) ;
F_50 ( V_8 ) ;
}
void F_67 ( unsigned int V_35 )
{
F_69 ( V_35 ) ;
F_70 ( 1UL << V_35 ) ;
}
void F_71 ( int V_35 , void (* V_30)( struct V_13 * ) )
{
V_27 [ V_35 ] . V_30 = V_30 ;
}
void F_72 ( struct V_36 * V_37 )
{
unsigned long V_8 ;
F_49 ( V_8 ) ;
V_37 -> V_38 = NULL ;
* F_2 ( V_39 . V_40 ) = V_37 ;
F_73 ( V_39 . V_40 , & ( V_37 -> V_38 ) ) ;
F_66 ( V_41 ) ;
F_50 ( V_8 ) ;
}
void F_74 ( struct V_36 * V_37 )
{
unsigned long V_8 ;
F_49 ( V_8 ) ;
V_37 -> V_38 = NULL ;
* F_2 ( V_42 . V_40 ) = V_37 ;
F_73 ( V_42 . V_40 , & ( V_37 -> V_38 ) ) ;
F_66 ( V_43 ) ;
F_50 ( V_8 ) ;
}
void F_75 ( struct V_36 * V_37 )
{
F_76 ( ! F_18 () ) ;
V_37 -> V_38 = F_2 ( V_42 . V_44 ) ;
F_73 ( V_42 . V_44 , V_37 ) ;
F_67 ( V_43 ) ;
}
static void F_77 ( struct V_13 * V_45 )
{
struct V_36 * V_46 ;
F_24 () ;
V_46 = F_2 ( V_39 . V_44 ) ;
F_73 ( V_39 . V_44 , NULL ) ;
F_73 ( V_39 . V_40 , & F_78 ( V_39 ) . V_44 ) ;
F_30 () ;
while ( V_46 ) {
struct V_36 * V_37 = V_46 ;
V_46 = V_46 -> V_38 ;
if ( F_79 ( V_37 ) ) {
if ( ! F_80 ( & V_37 -> V_47 ) ) {
if ( ! F_81 ( V_48 , & V_37 -> V_4 ) )
F_82 () ;
V_37 -> V_49 ( V_37 -> V_50 ) ;
F_83 ( V_37 ) ;
continue;
}
F_83 ( V_37 ) ;
}
F_24 () ;
V_37 -> V_38 = NULL ;
* F_2 ( V_39 . V_40 ) = V_37 ;
F_73 ( V_39 . V_40 , & ( V_37 -> V_38 ) ) ;
F_67 ( V_41 ) ;
F_30 () ;
}
}
static void F_84 ( struct V_13 * V_45 )
{
struct V_36 * V_46 ;
F_24 () ;
V_46 = F_2 ( V_42 . V_44 ) ;
F_73 ( V_42 . V_44 , NULL ) ;
F_73 ( V_42 . V_40 , & F_78 ( V_42 ) . V_44 ) ;
F_30 () ;
while ( V_46 ) {
struct V_36 * V_37 = V_46 ;
V_46 = V_46 -> V_38 ;
if ( F_79 ( V_37 ) ) {
if ( ! F_80 ( & V_37 -> V_47 ) ) {
if ( ! F_81 ( V_48 , & V_37 -> V_4 ) )
F_82 () ;
V_37 -> V_49 ( V_37 -> V_50 ) ;
F_83 ( V_37 ) ;
continue;
}
F_83 ( V_37 ) ;
}
F_24 () ;
V_37 -> V_38 = NULL ;
* F_2 ( V_42 . V_40 ) = V_37 ;
F_73 ( V_42 . V_40 , & ( V_37 -> V_38 ) ) ;
F_67 ( V_43 ) ;
F_30 () ;
}
}
void F_85 ( struct V_36 * V_37 ,
void (* V_49)( unsigned long ) , unsigned long V_50 )
{
V_37 -> V_38 = NULL ;
V_37 -> V_4 = 0 ;
F_86 ( & V_37 -> V_47 , 0 ) ;
V_37 -> V_49 = V_49 ;
V_37 -> V_50 = V_50 ;
}
void F_87 ( struct V_36 * V_37 )
{
if ( F_26 () )
F_42 ( L_4 ) ;
while ( F_88 ( V_48 , & V_37 -> V_4 ) ) {
do {
F_89 () ;
} while ( F_90 ( V_48 , & V_37 -> V_4 ) );
}
F_91 ( V_37 ) ;
F_92 ( V_48 , & V_37 -> V_4 ) ;
}
static enum V_51 F_93 ( struct V_52 * V_53 )
{
struct V_54 * V_55 =
F_94 ( V_53 , struct V_54 , V_53 ) ;
F_95 ( & V_55 -> V_56 ) ;
return V_57 ;
}
static void F_96 ( unsigned long V_50 )
{
struct V_54 * V_55 = ( void * ) V_50 ;
enum V_51 V_26 ;
V_26 = V_55 -> V_58 ( & V_55 -> V_53 ) ;
if ( V_26 != V_57 )
V_51 ( & V_55 -> V_53 ) ;
}
static void F_97 ( struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_44 = & F_78 ( V_63 [ V_61 ] ) ;
F_98 ( & V_60 -> V_46 , V_44 ) ;
if ( V_44 -> V_38 == & V_60 -> V_46 )
F_66 ( V_61 ) ;
}
static void F_99 ( void * V_50 )
{
struct V_59 * V_60 = V_50 ;
unsigned long V_8 ;
int V_61 ;
V_61 = * ( int * ) V_60 -> V_64 ;
F_49 ( V_8 ) ;
F_97 ( V_60 , V_61 ) ;
F_50 ( V_8 ) ;
}
static int F_100 ( struct V_59 * V_60 , int V_19 , int V_61 )
{
if ( F_101 ( V_19 ) ) {
V_60 -> V_49 = F_99 ;
V_60 -> V_64 = & V_61 ;
V_60 -> V_8 = 0 ;
F_102 ( V_19 , V_60 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_100 ( struct V_59 * V_60 , int V_19 , int V_61 )
{
return 1 ;
}
void F_103 ( struct V_59 * V_60 , int V_19 , int V_65 , int V_61 )
{
if ( V_19 == V_65 || F_100 ( V_60 , V_19 , V_61 ) )
F_97 ( V_60 , V_61 ) ;
}
void F_104 ( struct V_59 * V_60 , int V_19 , int V_61 )
{
unsigned long V_8 ;
int V_65 ;
F_49 ( V_8 ) ;
V_65 = F_37 () ;
F_103 ( V_60 , V_19 , V_65 , V_61 ) ;
F_50 ( V_8 ) ;
}
static int F_105 ( struct V_66 * V_67 ,
unsigned long V_30 , void * V_68 )
{
if ( V_30 == V_69 || V_30 == V_70 ) {
int V_19 = ( unsigned long ) V_68 ;
int V_71 ;
F_24 () ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
struct V_62 * V_44 = & F_106 ( V_63 [ V_71 ] , V_19 ) ;
struct V_62 * V_73 ;
if ( F_107 ( V_44 ) )
continue;
V_73 = & F_78 ( V_63 [ V_71 ] ) ;
F_108 ( V_44 , V_73 ) ;
F_66 ( V_71 ) ;
}
F_30 () ;
}
return V_74 ;
}
void T_3 F_109 ( void )
{
int V_19 ;
F_110 (cpu) {
int V_71 ;
F_106 ( V_39 , V_19 ) . V_40 =
& F_106 ( V_39 , V_19 ) . V_44 ;
F_106 ( V_42 , V_19 ) . V_40 =
& F_106 ( V_42 , V_19 ) . V_44 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
F_111 ( & F_106 ( V_63 [ V_71 ] , V_19 ) ) ;
}
F_112 ( & V_75 ) ;
F_71 ( V_41 , F_77 ) ;
F_71 ( V_43 , F_84 ) ;
}
static int F_113 ( unsigned int V_19 )
{
return F_27 () ;
}
static void F_114 ( unsigned int V_19 )
{
F_24 () ;
if ( F_27 () ) {
F_34 () ;
F_115 ( V_19 ) ;
F_30 () ;
F_116 () ;
return;
}
F_30 () ;
}
void F_117 ( struct V_36 * V_37 , unsigned int V_19 )
{
struct V_36 * * V_71 ;
F_76 ( F_101 ( V_19 ) ) ;
F_76 ( F_90 ( V_76 , & V_37 -> V_4 ) ) ;
if ( ! F_90 ( V_48 , & V_37 -> V_4 ) )
return;
for ( V_71 = & F_106 ( V_39 , V_19 ) . V_44 ; * V_71 ; V_71 = & ( * V_71 ) -> V_38 ) {
if ( * V_71 == V_37 ) {
* V_71 = V_37 -> V_38 ;
if ( * V_71 == NULL )
F_106 ( V_39 , V_19 ) . V_40 = V_71 ;
return;
}
}
F_82 () ;
}
static void F_118 ( unsigned int V_19 )
{
F_24 () ;
if ( & F_106 ( V_39 , V_19 ) . V_44 != F_106 ( V_39 , V_19 ) . V_40 ) {
* F_2 ( V_39 . V_40 ) = F_106 ( V_39 , V_19 ) . V_44 ;
F_119 ( V_39 . V_40 , F_106 ( V_39 , V_19 ) . V_40 ) ;
F_106 ( V_39 , V_19 ) . V_44 = NULL ;
F_106 ( V_39 , V_19 ) . V_40 = & F_106 ( V_39 , V_19 ) . V_44 ;
}
F_66 ( V_41 ) ;
if ( & F_106 ( V_42 , V_19 ) . V_44 != F_106 ( V_42 , V_19 ) . V_40 ) {
* F_2 ( V_42 . V_40 ) = F_106 ( V_42 , V_19 ) . V_44 ;
F_73 ( V_42 . V_40 , F_106 ( V_42 , V_19 ) . V_40 ) ;
F_106 ( V_42 , V_19 ) . V_44 = NULL ;
F_106 ( V_42 , V_19 ) . V_40 = & F_106 ( V_42 , V_19 ) . V_44 ;
}
F_66 ( V_43 ) ;
F_30 () ;
}
static int F_120 ( struct V_66 * V_77 ,
unsigned long V_30 ,
void * V_68 )
{
switch ( V_30 ) {
#ifdef F_121
case V_69 :
case V_70 :
F_118 ( ( unsigned long ) V_68 ) ;
break;
#endif
}
return V_74 ;
}
static T_3 int F_122 ( void )
{
F_123 ( & V_78 ) ;
F_76 ( F_124 ( & V_79 ) ) ;
return 0 ;
}
int T_3 __weak F_125 ( void )
{
return 0 ;
}
int T_3 __weak F_126 ( void )
{
return V_80 ;
}
int T_3 __weak F_127 ( void )
{
return 0 ;
}
