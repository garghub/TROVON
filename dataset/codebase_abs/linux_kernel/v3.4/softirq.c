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
V_14 = F_28 () ;
F_36 ( V_18 ) ;
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_19 ) ;
F_37 () ;
V_17 = F_38 () ;
V_20:
F_39 ( 0 ) ;
F_31 () ;
V_13 = V_21 ;
do {
if ( V_14 & 1 ) {
unsigned int V_22 = V_13 - V_21 ;
int V_23 = F_8 () ;
F_40 ( V_22 ) ;
F_41 ( V_22 ) ;
V_13 -> V_24 ( V_13 ) ;
F_42 ( V_22 ) ;
if ( F_26 ( V_23 != F_8 () ) ) {
F_43 ( V_25 L_1
L_2
L_3 , V_22 ,
V_26 [ V_22 ] , V_13 -> V_24 ,
V_23 , F_8 () ) ;
F_8 () = V_23 ;
}
F_44 ( V_17 ) ;
}
V_13 ++ ;
V_14 >>= 1 ;
} while ( V_14 );
F_25 () ;
V_14 = F_28 () ;
if ( V_14 && -- V_15 )
goto V_20;
if ( V_14 )
F_1 () ;
F_45 () ;
F_36 ( V_18 ) ;
F_18 ( V_19 ) ;
}
T_1 void F_29 ( void )
{
T_2 V_14 ;
unsigned long V_8 ;
if ( F_27 () )
return;
F_46 ( V_8 ) ;
V_14 = F_28 () ;
if ( V_14 )
F_35 () ;
F_47 ( V_8 ) ;
}
void F_48 ( void )
{
int V_17 = F_38 () ;
F_49 () ;
if ( F_50 ( V_18 ) && ! F_27 () ) {
F_16 () ;
F_51 ( V_17 ) ;
F_22 () ;
}
F_52 () ;
}
static inline void F_53 ( void )
{
if ( ! V_27 ) {
#ifdef F_54
F_35 () ;
#else
F_29 () ;
#endif
} else {
F_4 ( ( unsigned long ) F_17 ( 0 ) ,
V_19 ) ;
F_1 () ;
F_18 ( V_19 ) ;
}
}
void F_55 ( void )
{
F_36 ( V_18 ) ;
F_56 () ;
F_21 ( V_28 ) ;
if ( ! F_27 () && F_28 () )
F_53 () ;
#ifdef F_57
if ( F_58 ( F_38 () ) && ! F_27 () && ! F_59 () )
F_60 () ;
#endif
F_61 () ;
F_62 () ;
}
inline void F_63 ( unsigned int V_29 )
{
F_64 ( V_29 ) ;
if ( ! F_27 () )
F_1 () ;
}
void F_65 ( unsigned int V_29 )
{
unsigned long V_8 ;
F_46 ( V_8 ) ;
F_63 ( V_29 ) ;
F_47 ( V_8 ) ;
}
void F_64 ( unsigned int V_29 )
{
F_66 ( V_29 ) ;
F_67 ( 1UL << V_29 ) ;
}
void F_68 ( int V_29 , void (* V_24)( struct V_12 * ) )
{
V_21 [ V_29 ] . V_24 = V_24 ;
}
void F_69 ( struct V_30 * V_31 )
{
unsigned long V_8 ;
F_46 ( V_8 ) ;
V_31 -> V_32 = NULL ;
* F_2 ( V_33 . V_34 ) = V_31 ;
F_70 ( V_33 . V_34 , & ( V_31 -> V_32 ) ) ;
F_63 ( V_35 ) ;
F_47 ( V_8 ) ;
}
void F_71 ( struct V_30 * V_31 )
{
unsigned long V_8 ;
F_46 ( V_8 ) ;
V_31 -> V_32 = NULL ;
* F_2 ( V_36 . V_34 ) = V_31 ;
F_70 ( V_36 . V_34 , & ( V_31 -> V_32 ) ) ;
F_63 ( V_37 ) ;
F_47 ( V_8 ) ;
}
void F_72 ( struct V_30 * V_31 )
{
F_73 ( ! F_19 () ) ;
V_31 -> V_32 = F_2 ( V_36 . V_38 ) ;
F_70 ( V_36 . V_38 , V_31 ) ;
F_64 ( V_37 ) ;
}
static void F_74 ( struct V_12 * V_39 )
{
struct V_30 * V_40 ;
F_25 () ;
V_40 = F_2 ( V_33 . V_38 ) ;
F_70 ( V_33 . V_38 , NULL ) ;
F_70 ( V_33 . V_34 , & F_75 ( V_33 ) . V_38 ) ;
F_31 () ;
while ( V_40 ) {
struct V_30 * V_31 = V_40 ;
V_40 = V_40 -> V_32 ;
if ( F_76 ( V_31 ) ) {
if ( ! F_77 ( & V_31 -> V_41 ) ) {
if ( ! F_78 ( V_42 , & V_31 -> V_4 ) )
F_79 () ;
V_31 -> V_43 ( V_31 -> V_44 ) ;
F_80 ( V_31 ) ;
continue;
}
F_80 ( V_31 ) ;
}
F_25 () ;
V_31 -> V_32 = NULL ;
* F_2 ( V_33 . V_34 ) = V_31 ;
F_70 ( V_33 . V_34 , & ( V_31 -> V_32 ) ) ;
F_64 ( V_35 ) ;
F_31 () ;
}
}
static void F_81 ( struct V_12 * V_39 )
{
struct V_30 * V_40 ;
F_25 () ;
V_40 = F_2 ( V_36 . V_38 ) ;
F_70 ( V_36 . V_38 , NULL ) ;
F_70 ( V_36 . V_34 , & F_75 ( V_36 ) . V_38 ) ;
F_31 () ;
while ( V_40 ) {
struct V_30 * V_31 = V_40 ;
V_40 = V_40 -> V_32 ;
if ( F_76 ( V_31 ) ) {
if ( ! F_77 ( & V_31 -> V_41 ) ) {
if ( ! F_78 ( V_42 , & V_31 -> V_4 ) )
F_79 () ;
V_31 -> V_43 ( V_31 -> V_44 ) ;
F_80 ( V_31 ) ;
continue;
}
F_80 ( V_31 ) ;
}
F_25 () ;
V_31 -> V_32 = NULL ;
* F_2 ( V_36 . V_34 ) = V_31 ;
F_70 ( V_36 . V_34 , & ( V_31 -> V_32 ) ) ;
F_64 ( V_37 ) ;
F_31 () ;
}
}
void F_82 ( struct V_30 * V_31 ,
void (* V_43)( unsigned long ) , unsigned long V_44 )
{
V_31 -> V_32 = NULL ;
V_31 -> V_4 = 0 ;
F_83 ( & V_31 -> V_41 , 0 ) ;
V_31 -> V_43 = V_43 ;
V_31 -> V_44 = V_44 ;
}
void F_84 ( struct V_30 * V_31 )
{
if ( F_27 () )
F_43 ( L_4 ) ;
while ( F_85 ( V_42 , & V_31 -> V_4 ) ) {
do {
F_86 () ;
} while ( F_87 ( V_42 , & V_31 -> V_4 ) );
}
F_88 ( V_31 ) ;
F_89 ( V_42 , & V_31 -> V_4 ) ;
}
static enum V_45 F_90 ( struct V_46 * V_47 )
{
struct V_48 * V_49 =
F_91 ( V_47 , struct V_48 , V_47 ) ;
F_92 ( & V_49 -> V_50 ) ;
return V_51 ;
}
static void F_93 ( unsigned long V_44 )
{
struct V_48 * V_49 = ( void * ) V_44 ;
enum V_45 V_20 ;
V_20 = V_49 -> V_52 ( & V_49 -> V_47 ) ;
if ( V_20 != V_51 )
V_45 ( & V_49 -> V_47 ) ;
}
static void F_94 ( struct V_53 * V_54 , int V_55 )
{
struct V_56 * V_38 = & F_75 ( V_57 [ V_55 ] ) ;
F_95 ( & V_54 -> V_40 , V_38 ) ;
if ( V_38 -> V_32 == & V_54 -> V_40 )
F_63 ( V_55 ) ;
}
static void F_96 ( void * V_44 )
{
struct V_53 * V_54 = V_44 ;
unsigned long V_8 ;
int V_55 ;
V_55 = V_54 -> V_58 ;
F_46 ( V_8 ) ;
F_94 ( V_54 , V_55 ) ;
F_47 ( V_8 ) ;
}
static int F_97 ( struct V_53 * V_54 , int V_17 , int V_55 )
{
if ( F_98 ( V_17 ) ) {
V_54 -> V_43 = F_96 ;
V_54 -> V_59 = V_54 ;
V_54 -> V_8 = 0 ;
V_54 -> V_58 = V_55 ;
F_99 ( V_17 , V_54 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_97 ( struct V_53 * V_54 , int V_17 , int V_55 )
{
return 1 ;
}
void F_100 ( struct V_53 * V_54 , int V_17 , int V_60 , int V_55 )
{
if ( V_17 == V_60 || F_97 ( V_54 , V_17 , V_55 ) )
F_94 ( V_54 , V_55 ) ;
}
void F_101 ( struct V_53 * V_54 , int V_17 , int V_55 )
{
unsigned long V_8 ;
int V_60 ;
F_46 ( V_8 ) ;
V_60 = F_38 () ;
F_100 ( V_54 , V_17 , V_60 , V_55 ) ;
F_47 ( V_8 ) ;
}
static int T_3 F_102 ( struct V_61 * V_62 ,
unsigned long V_24 , void * V_63 )
{
if ( V_24 == V_64 || V_24 == V_65 ) {
int V_17 = ( unsigned long ) V_63 ;
int V_66 ;
F_25 () ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
struct V_56 * V_38 = & F_103 ( V_57 [ V_66 ] , V_17 ) ;
struct V_56 * V_68 ;
if ( F_104 ( V_38 ) )
continue;
V_68 = & F_75 ( V_57 [ V_66 ] ) ;
F_105 ( V_38 , V_68 ) ;
F_63 ( V_66 ) ;
}
F_31 () ;
}
return V_69 ;
}
void T_4 F_106 ( void )
{
int V_17 ;
F_107 (cpu) {
int V_66 ;
F_103 ( V_33 , V_17 ) . V_34 =
& F_103 ( V_33 , V_17 ) . V_38 ;
F_103 ( V_36 , V_17 ) . V_34 =
& F_103 ( V_36 , V_17 ) . V_38 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ )
F_108 ( & F_103 ( V_57 [ V_66 ] , V_17 ) ) ;
}
F_109 ( & V_70 ) ;
F_68 ( V_35 , F_74 ) ;
F_68 ( V_37 , F_81 ) ;
}
static int F_110 ( void * V_71 )
{
F_111 ( V_72 ) ;
while ( ! F_112 () ) {
F_113 () ;
if ( ! F_28 () ) {
F_114 () ;
}
F_115 ( V_5 ) ;
while ( F_28 () ) {
if ( F_116 ( ( long ) V_71 ) )
goto V_73;
F_25 () ;
if ( F_28 () )
F_35 () ;
F_31 () ;
F_62 () ;
F_117 () ;
F_113 () ;
F_118 ( ( long ) V_71 ) ;
}
F_119 () ;
F_111 ( V_72 ) ;
}
F_115 ( V_5 ) ;
return 0 ;
V_73:
F_119 () ;
F_111 ( V_72 ) ;
while ( ! F_112 () ) {
F_120 () ;
F_111 ( V_72 ) ;
}
F_115 ( V_5 ) ;
return 0 ;
}
void F_121 ( struct V_30 * V_31 , unsigned int V_17 )
{
struct V_30 * * V_66 ;
F_73 ( F_98 ( V_17 ) ) ;
F_73 ( F_87 ( V_74 , & V_31 -> V_4 ) ) ;
if ( ! F_87 ( V_42 , & V_31 -> V_4 ) )
return;
for ( V_66 = & F_103 ( V_33 , V_17 ) . V_38 ; * V_66 ; V_66 = & ( * V_66 ) -> V_32 ) {
if ( * V_66 == V_31 ) {
* V_66 = V_31 -> V_32 ;
if ( * V_66 == NULL )
F_103 ( V_33 , V_17 ) . V_34 = V_66 ;
return;
}
}
F_79 () ;
}
static void F_122 ( unsigned int V_17 )
{
F_25 () ;
if ( & F_103 ( V_33 , V_17 ) . V_38 != F_103 ( V_33 , V_17 ) . V_34 ) {
* F_2 ( V_33 . V_34 ) = F_103 ( V_33 , V_17 ) . V_38 ;
F_123 ( V_33 . V_34 , F_103 ( V_33 , V_17 ) . V_34 ) ;
F_103 ( V_33 , V_17 ) . V_38 = NULL ;
F_103 ( V_33 , V_17 ) . V_34 = & F_103 ( V_33 , V_17 ) . V_38 ;
}
F_63 ( V_35 ) ;
if ( & F_103 ( V_36 , V_17 ) . V_38 != F_103 ( V_36 , V_17 ) . V_34 ) {
* F_2 ( V_36 . V_34 ) = F_103 ( V_36 , V_17 ) . V_38 ;
F_70 ( V_36 . V_34 , F_103 ( V_36 , V_17 ) . V_34 ) ;
F_103 ( V_36 , V_17 ) . V_38 = NULL ;
F_103 ( V_36 , V_17 ) . V_34 = & F_103 ( V_36 , V_17 ) . V_38 ;
}
F_63 ( V_37 ) ;
F_31 () ;
}
static int T_3 F_124 ( struct V_61 * V_75 ,
unsigned long V_24 ,
void * V_63 )
{
int V_76 = ( unsigned long ) V_63 ;
struct V_1 * V_77 ;
switch ( V_24 ) {
case V_78 :
case V_79 :
V_77 = F_125 ( F_110 ,
V_63 ,
F_126 ( V_76 ) ,
L_5 , V_76 ) ;
if ( F_127 ( V_77 ) ) {
F_43 ( L_6 , V_76 ) ;
return F_128 ( F_129 ( V_77 ) ) ;
}
F_130 ( V_77 , V_76 ) ;
F_103 ( V_3 , V_76 ) = V_77 ;
break;
case V_80 :
case V_81 :
F_3 ( F_103 ( V_3 , V_76 ) ) ;
break;
#ifdef F_131
case V_82 :
case V_83 :
if ( ! F_103 ( V_3 , V_76 ) )
break;
F_130 ( F_103 ( V_3 , V_76 ) ,
F_132 ( V_84 ) ) ;
case V_64 :
case V_65 : {
static const struct V_85 V_86 = {
. V_87 = V_88 - 1
} ;
V_77 = F_103 ( V_3 , V_76 ) ;
F_103 ( V_3 , V_76 ) = NULL ;
F_133 ( V_77 , V_89 , & V_86 ) ;
F_134 ( V_77 ) ;
F_122 ( V_76 ) ;
break;
}
#endif
}
return V_69 ;
}
static T_4 int F_135 ( void )
{
void * V_17 = ( void * ) ( long ) F_38 () ;
int V_90 = F_124 ( & V_91 , V_78 , V_17 ) ;
F_73 ( V_90 != V_69 ) ;
F_124 ( & V_91 , V_80 , V_17 ) ;
F_136 ( & V_91 ) ;
return 0 ;
}
int T_4 __weak F_137 ( void )
{
return 0 ;
}
int T_4 __weak F_138 ( void )
{
return V_92 ;
}
int T_4 __weak F_139 ( void )
{
return 0 ;
}
