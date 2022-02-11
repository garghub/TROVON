unsigned long F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 -> V_6 ) != F_2 ( V_5 -> V_7 ) ;
}
void F_4 ( void )
{
if ( ! F_5 ( V_8 . V_9 ) ) {
F_6 ( F_7 ( L_1 ) ,
F_5 ( V_8 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_8 . V_9 , 1 ) ;
}
}
void F_9 ( void )
{
if ( ! F_5 ( V_10 . V_9 ) ) {
F_6 ( F_7 ( L_3 ) ,
F_5 ( V_10 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_10 . V_9 , 1 ) ;
}
}
static void F_10 ( void )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
struct V_4 * V_5 ;
F_11 ( V_11 ) ;
V_16 = F_12 ( V_17 ) ;
F_13 ( V_17 , 0 ) ;
F_14 (rsp) {
V_13 = F_15 ( V_5 -> V_18 ) ;
if ( ! ( V_16 & V_5 -> V_19 ) )
continue;
F_16 () ;
if ( F_2 ( V_13 -> V_20 -> V_6 ) !=
F_2 ( V_13 -> V_21 ) )
continue;
V_15 = F_17 ( & V_14 ) ;
F_18 () ;
F_19 ( 2 , & V_15 -> V_22 ) ;
F_20 () ;
break;
}
F_21 ( V_11 ) ;
}
void F_22 ( void )
{
F_23 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_24 () ;
if ( F_25 ( F_12 ( V_17 ) ) )
F_10 () ;
F_23 ( F_7 ( L_5 ) ) ;
}
void F_26 ( void )
{
if ( F_25 ( F_12 ( V_17 ) ) )
F_10 () ;
F_27 ( V_23 ) ;
}
unsigned long F_28 ( void )
{
return V_24 -> V_7 ;
}
unsigned long F_29 ( void )
{
return V_25 . V_7 ;
}
unsigned long F_30 ( void )
{
return V_26 . V_7 ;
}
unsigned long F_31 ( void )
{
return V_24 -> V_6 ;
}
unsigned long F_32 ( void )
{
return V_25 . V_6 ;
}
unsigned long F_33 ( void )
{
return V_26 . V_6 ;
}
void F_34 ( void )
{
F_35 ( V_24 ) ;
}
void F_36 ( void )
{
F_35 ( & V_26 ) ;
}
void F_37 ( void )
{
F_35 ( & V_25 ) ;
}
void F_38 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp) {
F_39 ( L_6 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_29 -> V_30 ) ;
}
}
void F_40 ( void )
{
V_31 ++ ;
V_32 = 0 ;
}
void F_41 ( enum V_33 V_34 , int * V_11 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_34 ) {
case V_35 :
V_5 = V_24 ;
break;
case V_36 :
V_5 = & V_26 ;
break;
case V_37 :
V_5 = & V_25 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_11 = F_2 ( V_5 -> V_38 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_11 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_42 ( unsigned long V_39 )
{
V_32 ++ ;
}
static int
F_43 ( struct V_12 * V_13 )
{
return & V_13 -> V_40 != V_13 -> V_41 [ V_42 ] &&
V_13 -> V_41 [ V_42 ] != NULL ;
}
static struct V_1 * F_44 ( struct V_4 * V_5 )
{
return & V_5 -> V_43 [ 0 ] ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_44 ( V_5 ) ;
int V_44 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_45 = & V_2 -> V_46 [ V_44 ] ;
return F_2 ( * V_45 ) ;
}
static int
F_46 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
int V_47 ;
if ( F_3 ( V_5 ) )
return 0 ;
if ( F_45 ( V_5 ) )
return 1 ;
if ( ! V_13 -> V_41 [ V_48 ] )
return 0 ;
if ( * V_13 -> V_41 [ V_49 ] )
return 1 ;
for ( V_47 = V_50 ; V_47 < V_48 ; V_47 ++ )
if ( V_13 -> V_41 [ V_47 - 1 ] != V_13 -> V_41 [ V_47 ] &&
F_47 ( F_2 ( V_5 -> V_6 ) ,
V_13 -> V_51 [ V_47 ] ) )
return 1 ;
return 0 ;
}
static void F_48 ( long long V_52 , bool V_53 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_49 ( F_7 ( L_7 ) , V_52 , V_15 -> V_54 ) ;
if ( ! V_53 && ! F_50 ( V_55 ) ) {
struct V_56 * T_1 V_57 =
F_51 ( F_52 () ) ;
F_49 ( F_7 ( L_8 ) , V_52 , 0 ) ;
F_53 ( V_58 ) ;
F_54 ( 1 , L_9 ,
V_55 -> V_59 , V_55 -> V_60 ,
T_1 -> V_59 , T_1 -> V_60 ) ;
}
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
F_55 ( V_13 ) ;
}
F_56 () ;
F_18 () ;
F_57 ( & V_15 -> V_22 ) ;
F_20 () ;
F_58 ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ;
F_60 () ;
F_61 ( ! F_62 ( & V_61 ) ,
L_10 ) ;
F_61 ( ! F_62 ( & V_62 ) ,
L_11 ) ;
F_61 ( ! F_62 ( & V_63 ) ,
L_12 ) ;
}
static void F_63 ( bool V_53 )
{
long long V_52 ;
struct V_14 * V_15 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_58 ( ( V_52 & V_64 ) == 0 ) ;
if ( ( V_52 & V_64 ) == V_65 ) {
V_15 -> V_54 = 0 ;
F_48 ( V_52 , V_53 ) ;
} else {
V_15 -> V_54 -= V_65 ;
}
}
void F_64 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_63 ( false ) ;
F_65 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_66 ( void )
{
F_63 ( 1 ) ;
}
void F_67 ( void )
{
unsigned long V_11 ;
long long V_52 ;
struct V_14 * V_15 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 -- ;
F_58 ( V_15 -> V_54 < 0 ) ;
if ( V_15 -> V_54 )
F_49 ( F_7 ( L_13 ) , V_52 , V_15 -> V_54 ) ;
else
F_48 ( V_52 , true ) ;
F_65 ( 1 ) ;
F_21 ( V_11 ) ;
}
static void F_68 ( long long V_52 , int V_53 )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_69 () ;
F_18 () ;
F_57 ( & V_15 -> V_22 ) ;
F_20 () ;
F_58 ( ! ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ) ;
F_70 () ;
F_49 ( F_7 ( L_14 ) , V_52 , V_15 -> V_54 ) ;
if ( ! V_53 && ! F_50 ( V_55 ) ) {
struct V_56 * T_1 V_57 =
F_51 ( F_52 () ) ;
F_49 ( F_7 ( L_15 ) ,
V_52 , V_15 -> V_54 ) ;
F_53 ( V_58 ) ;
F_54 ( 1 , L_9 ,
V_55 -> V_59 , V_55 -> V_60 ,
T_1 -> V_59 , T_1 -> V_60 ) ;
}
}
static void F_71 ( bool V_53 )
{
struct V_14 * V_15 ;
long long V_52 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_58 ( V_52 < 0 ) ;
if ( V_52 & V_64 ) {
V_15 -> V_54 += V_65 ;
} else {
V_15 -> V_54 = V_66 ;
F_68 ( V_52 , V_53 ) ;
}
}
void F_72 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_71 ( false ) ;
F_73 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_74 ( void )
{
F_71 ( 1 ) ;
}
void F_75 ( void )
{
unsigned long V_11 ;
struct V_14 * V_15 ;
long long V_52 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 ++ ;
F_58 ( V_15 -> V_54 == 0 ) ;
if ( V_52 )
F_49 ( F_7 ( L_16 ) , V_52 , V_15 -> V_54 ) ;
else
F_68 ( V_52 , true ) ;
F_73 ( 1 ) ;
F_21 ( V_11 ) ;
}
void F_76 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
int V_67 = 2 ;
F_58 ( V_15 -> V_68 < 0 ) ;
if ( ! ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ) {
F_18 () ;
F_57 ( & V_15 -> V_22 ) ;
F_20 () ;
F_58 ( ! ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ) ;
V_67 = 1 ;
}
V_15 -> V_68 += V_67 ;
F_77 () ;
}
void F_78 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_58 ( V_15 -> V_68 <= 0 ) ;
F_58 ( ! ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ) ;
if ( V_15 -> V_68 != 1 ) {
V_15 -> V_68 -= 2 ;
return;
}
V_15 -> V_68 = 0 ;
F_18 () ;
F_57 ( & V_15 -> V_22 ) ;
F_20 () ;
F_58 ( F_59 ( & V_15 -> V_22 ) & 0x1 ) ;
}
bool T_2 F_79 ( void )
{
return F_59 ( F_17 ( & V_14 . V_22 ) ) & 0x1 ;
}
bool T_2 F_80 ( void )
{
bool V_69 ;
F_81 () ;
V_69 = F_79 () ;
F_82 () ;
return V_69 ;
}
bool F_83 ( void )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
bool V_69 ;
if ( F_84 () )
return true ;
F_81 () ;
V_13 = F_17 ( & V_8 ) ;
V_2 = V_13 -> V_20 ;
V_69 = ( V_13 -> V_70 & F_1 ( V_2 ) ) ||
! V_71 ;
F_82 () ;
return V_69 ;
}
static int F_85 ( void )
{
return F_5 ( V_14 . V_54 ) <= 1 ;
}
static int F_86 ( struct V_12 * V_13 ,
bool * V_72 , unsigned long * V_73 )
{
V_13 -> V_74 = F_87 ( 0 , & V_13 -> V_22 -> V_22 ) ;
F_88 ( V_13 , V_72 , V_73 ) ;
if ( ( V_13 -> V_74 & 0x1 ) == 0 ) {
F_89 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_75 , F_7 ( L_17 ) ) ;
return 1 ;
} else {
if ( F_47 ( F_2 ( V_13 -> V_7 ) + V_76 / 4 ,
V_13 -> V_20 -> V_7 ) )
F_2 ( V_13 -> V_77 ) = true ;
return 0 ;
}
}
static int F_90 ( struct V_12 * V_13 ,
bool * V_72 , unsigned long * V_73 )
{
unsigned int V_78 ;
int * V_79 ;
unsigned int V_80 ;
V_78 = ( unsigned int ) F_87 ( 0 , & V_13 -> V_22 -> V_22 ) ;
V_80 = ( unsigned int ) V_13 -> V_74 ;
if ( ( V_78 & 0x1 ) == 0 || F_91 ( V_78 , V_80 + 2 ) ) {
F_89 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_75 , F_7 ( L_17 ) ) ;
V_13 -> V_81 ++ ;
return 1 ;
}
if ( F_92 ( V_13 -> V_5 -> V_82 + 2 , V_83 ) )
return 0 ;
F_77 () ;
if ( F_93 ( V_13 -> V_75 ) ) {
F_89 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_75 , F_7 ( L_18 ) ) ;
V_13 -> V_84 ++ ;
return 1 ;
}
V_79 = & F_94 ( V_17 , V_13 -> V_75 ) ;
if ( F_92 ( V_83 ,
V_13 -> V_5 -> V_82 + V_85 ) ||
F_92 ( V_83 , V_13 -> V_5 -> V_86 ) ) {
if ( ! ( F_2 ( * V_79 ) & V_13 -> V_5 -> V_19 ) ) {
F_2 ( V_13 -> V_21 ) =
F_2 ( V_13 -> V_20 -> V_6 ) ;
F_16 () ;
F_2 ( * V_79 ) =
F_2 ( * V_79 ) + V_13 -> V_5 -> V_19 ;
F_95 ( V_13 -> V_75 ) ;
V_13 -> V_5 -> V_86 += 5 ;
} else if ( F_92 ( V_83 , V_13 -> V_5 -> V_86 ) ) {
F_95 ( V_13 -> V_75 ) ;
V_13 -> V_5 -> V_86 += 5 ;
}
}
return 0 ;
}
static void F_96 ( struct V_4 * V_5 )
{
unsigned long V_87 = V_83 ;
unsigned long j1 ;
V_5 -> V_82 = V_87 ;
F_97 () ;
j1 = F_98 () ;
F_2 ( V_5 -> V_88 ) = V_87 + j1 ;
V_5 -> V_86 = V_87 + j1 / 2 ;
V_5 -> V_89 = F_2 ( V_5 -> V_90 ) ;
}
static void F_99 ( struct V_4 * V_5 )
{
unsigned long V_91 ;
unsigned long V_87 ;
V_87 = V_83 ;
V_91 = F_2 ( V_5 -> V_92 ) ;
if ( V_87 - V_91 > 2 * V_93 )
F_100 ( L_19 ,
V_5 -> V_27 , V_87 - V_91 ) ;
}
static void F_101 ( struct V_4 * V_5 )
{
int V_75 ;
unsigned long V_11 ;
struct V_1 * V_2 ;
F_102 (rsp, rnp) {
F_103 ( & V_2 -> V_94 , V_11 ) ;
if ( V_2 -> V_95 != 0 ) {
for ( V_75 = 0 ; V_75 <= V_2 -> V_96 - V_2 -> V_97 ; V_75 ++ )
if ( V_2 -> V_95 & ( 1UL << V_75 ) )
F_104 ( V_2 -> V_97 + V_75 ) ;
}
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
}
static void F_106 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_75 ;
long V_98 ;
unsigned long V_11 ;
unsigned long V_91 ;
unsigned long V_87 ;
int V_99 = 0 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_100 = 0 ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
V_98 = V_83 - F_2 ( V_5 -> V_88 ) ;
if ( V_98 < V_101 || ! F_3 ( V_5 ) ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
F_2 ( V_5 -> V_88 ) = V_83 + 3 * F_98 () + 3 ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
F_100 ( L_20 ,
V_5 -> V_27 ) ;
F_107 () ;
F_102 (rsp, rnp) {
F_103 ( & V_2 -> V_94 , V_11 ) ;
V_99 += F_108 ( V_2 ) ;
if ( V_2 -> V_95 != 0 ) {
for ( V_75 = 0 ; V_75 <= V_2 -> V_96 - V_2 -> V_97 ; V_75 ++ )
if ( V_2 -> V_95 & ( 1UL << V_75 ) ) {
F_109 ( V_5 ,
V_2 -> V_97 + V_75 ) ;
V_99 ++ ;
}
}
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
F_110 () ;
F_111 (cpu)
V_100 += F_112 ( V_5 -> V_18 , V_75 ) -> V_102 ;
F_113 ( L_21 ,
F_52 () , ( long ) ( V_83 - V_5 -> V_82 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_100 ) ;
if ( V_99 ) {
F_101 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_100 ( L_22 ) ;
} else {
V_87 = V_83 ;
V_91 = F_2 ( V_5 -> V_92 ) ;
F_100 ( L_23 ,
V_5 -> V_27 , V_87 - V_91 , V_87 , V_91 ,
V_103 ,
F_44 ( V_5 ) -> V_95 ) ;
F_114 ( V_55 ) ;
}
}
F_115 ( V_5 ) ;
F_99 ( V_5 ) ;
F_35 ( V_5 ) ;
}
static void F_116 ( struct V_4 * V_5 )
{
int V_75 ;
unsigned long V_11 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_100 = 0 ;
F_100 ( L_24 , V_5 -> V_27 ) ;
F_107 () ;
F_109 ( V_5 , F_52 () ) ;
F_110 () ;
F_111 (cpu)
V_100 += F_112 ( V_5 -> V_18 , V_75 ) -> V_102 ;
F_113 ( L_25 ,
V_83 - V_5 -> V_82 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_100 ) ;
F_99 ( V_5 ) ;
F_101 ( V_5 ) ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
if ( F_92 ( V_83 , F_2 ( V_5 -> V_88 ) ) )
F_2 ( V_5 -> V_88 ) = V_83 +
3 * F_98 () + 3 ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
F_95 ( F_52 () ) ;
}
static void F_117 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_104 ;
unsigned long V_87 ;
unsigned long V_105 ;
struct V_1 * V_2 ;
if ( V_106 || ! F_3 ( V_5 ) )
return;
V_87 = V_83 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_118 () ;
V_105 = F_2 ( V_5 -> V_88 ) ;
F_118 () ;
V_104 = F_2 ( V_5 -> V_82 ) ;
F_118 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_92 ( V_6 , V_7 ) ||
F_47 ( V_87 , V_105 ) ||
F_92 ( V_104 , V_105 ) )
return;
V_2 = V_13 -> V_20 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_95 ) & V_13 -> V_70 ) ) {
F_116 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_92 ( V_87 , V_105 + V_101 ) ) {
F_106 ( V_5 , V_7 ) ;
}
}
void F_119 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_2 ( V_5 -> V_88 ) = V_83 + V_76 / 2 ;
}
static void F_120 ( struct V_12 * V_13 )
{
int V_47 ;
V_13 -> V_40 = NULL ;
for ( V_47 = 0 ; V_47 < V_107 ; V_47 ++ )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
}
static void F_121 ( struct V_12 * V_13 )
{
if ( F_122 ( V_13 ) )
return;
F_120 ( V_13 ) ;
}
static unsigned long F_123 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_44 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_124 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long V_108 , const char * V_109 )
{
F_125 ( V_13 -> V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_6 , V_108 , V_2 -> V_110 ,
V_2 -> V_97 , V_2 -> V_96 , V_109 ) ;
}
static bool V_57
F_126 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long * V_111 )
{
unsigned long V_108 ;
int V_47 ;
bool V_69 = false ;
struct V_1 * V_112 = F_44 ( V_13 -> V_5 ) ;
V_108 = F_123 ( V_13 -> V_5 , V_2 ) ;
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_26 ) ) ;
if ( V_2 -> V_46 [ V_108 & 0x1 ] ) {
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_27 ) ) ;
goto V_113;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_112 -> V_7 ) != F_2 ( V_112 -> V_6 ) ) {
V_2 -> V_46 [ V_108 & 0x1 ] ++ ;
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_28 ) ) ;
goto V_113;
}
if ( V_2 != V_112 ) {
F_127 ( & V_112 -> V_94 ) ;
F_128 () ;
}
V_108 = F_123 ( V_13 -> V_5 , V_112 ) ;
for ( V_47 = V_42 ; V_47 < V_48 ; V_47 ++ )
if ( F_47 ( V_108 , V_13 -> V_51 [ V_47 ] ) )
V_13 -> V_51 [ V_47 ] = V_108 ;
if ( V_112 -> V_46 [ V_108 & 0x1 ] ) {
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_29 ) ) ;
goto V_114;
}
V_112 -> V_46 [ V_108 & 0x1 ] ++ ;
if ( V_112 -> V_7 != V_112 -> V_6 ) {
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_30 ) ) ;
} else {
F_124 ( V_2 , V_13 , V_108 , F_7 ( L_31 ) ) ;
V_69 = F_129 ( V_13 -> V_5 , V_112 , V_13 ) ;
}
V_114:
if ( V_2 != V_112 )
F_130 ( & V_112 -> V_94 ) ;
V_113:
if ( V_111 != NULL )
* V_111 = V_108 ;
return V_69 ;
}
static int F_131 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_108 = V_2 -> V_6 ;
int V_115 ;
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
F_132 ( V_5 , V_2 ) ;
V_2 -> V_46 [ V_108 & 0x1 ] = 0 ;
V_115 = V_2 -> V_46 [ ( V_108 + 1 ) & 0x1 ] ;
F_124 ( V_2 , V_13 , V_108 ,
V_115 ? F_7 ( L_32 ) : F_7 ( L_33 ) ) ;
return V_115 ;
}
static void F_133 ( struct V_4 * V_5 )
{
if ( V_55 == V_5 -> V_29 ||
! F_2 ( V_5 -> V_38 ) ||
! V_5 -> V_29 )
return;
F_134 ( & V_5 -> V_116 ) ;
}
static bool F_135 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long V_108 ;
int V_47 ;
bool V_69 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
V_108 = F_123 ( V_5 , V_2 ) ;
for ( V_47 = V_48 - 1 ; V_47 > V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] != V_13 -> V_41 [ V_47 - 1 ] &&
! F_92 ( V_13 -> V_51 [ V_47 ] , V_108 ) )
break;
if ( ++ V_47 >= V_48 )
return false ;
for (; V_47 <= V_48 ; V_47 ++ ) {
V_13 -> V_41 [ V_47 ] = V_13 -> V_41 [ V_48 ] ;
V_13 -> V_51 [ V_47 ] = V_108 ;
}
V_69 = F_126 ( V_2 , V_13 , NULL ) ;
if ( ! * V_13 -> V_41 [ V_50 ] )
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_34 ) ) ;
else
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_35 ) ) ;
return V_69 ;
}
static bool F_136 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_47 , V_87 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
for ( V_47 = V_50 ; V_47 < V_48 ; V_47 ++ ) {
if ( F_47 ( V_2 -> V_6 , V_13 -> V_51 [ V_47 ] ) )
break;
V_13 -> V_41 [ V_42 ] = V_13 -> V_41 [ V_47 ] ;
}
for ( V_87 = V_50 ; V_87 < V_47 ; V_87 ++ )
V_13 -> V_41 [ V_87 ] = V_13 -> V_41 [ V_42 ] ;
for ( V_87 = V_50 ; V_47 < V_48 ; V_47 ++ , V_87 ++ ) {
if ( V_13 -> V_41 [ V_87 ] == V_13 -> V_41 [ V_48 ] )
break;
V_13 -> V_41 [ V_87 ] = V_13 -> V_41 [ V_47 ] ;
V_13 -> V_51 [ V_87 ] = V_13 -> V_51 [ V_47 ] ;
}
return F_135 ( V_5 , V_2 , V_13 ) ;
}
static bool F_137 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
bool V_69 ;
if ( V_13 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_13 -> V_77 ) ) ) {
V_69 = F_135 ( V_5 , V_2 , V_13 ) ;
} else {
V_69 = F_136 ( V_5 , V_2 , V_13 ) ;
V_13 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_36 ) ) ;
}
if ( V_13 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_13 -> V_77 ) ) ) {
V_13 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_37 ) ) ;
V_13 -> V_9 = 0 ;
V_13 -> V_117 = F_5 ( V_23 ) ;
V_13 -> V_118 = ! ! ( V_2 -> V_95 & V_13 -> V_70 ) ;
F_138 ( V_13 ) ;
F_2 ( V_13 -> V_77 ) = false ;
}
return V_69 ;
}
static void F_139 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
bool V_119 ;
struct V_1 * V_2 ;
F_11 ( V_11 ) ;
V_2 = V_13 -> V_20 ;
if ( ( V_13 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_13 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_13 -> V_77 ) ) ) ||
! F_140 ( & V_2 -> V_94 ) ) {
F_21 ( V_11 ) ;
return;
}
F_128 () ;
V_119 = F_137 ( V_5 , V_2 , V_13 ) ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
if ( V_119 )
F_133 ( V_5 ) ;
}
static int F_141 ( struct V_4 * V_5 )
{
unsigned long V_120 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_2 ( V_5 -> V_92 ) = V_83 ;
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
if ( ! F_2 ( V_5 -> V_38 ) ) {
F_143 ( & V_2 -> V_94 ) ;
return 0 ;
}
F_2 ( V_5 -> V_38 ) = 0 ;
if ( F_58 ( F_3 ( V_5 ) ) ) {
F_143 ( & V_2 -> V_94 ) ;
return 0 ;
}
F_96 ( V_5 ) ;
F_144 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_27 , V_5 -> V_7 , F_7 ( L_38 ) ) ;
F_143 ( & V_2 -> V_94 ) ;
F_102 (rsp, rnp) {
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
if ( V_2 -> V_121 == V_2 -> V_3 &&
! V_2 -> V_122 ) {
F_143 ( & V_2 -> V_94 ) ;
continue;
}
V_120 = V_2 -> V_121 ;
V_2 -> V_121 = V_2 -> V_3 ;
if ( ! V_120 != ! V_2 -> V_121 ) {
if ( ! V_120 )
F_145 ( V_2 ) ;
else if ( F_146 ( V_2 ) )
V_2 -> V_122 = true ;
else
F_147 ( V_2 ) ;
}
if ( V_2 -> V_122 &&
( ! F_146 ( V_2 ) ||
V_2 -> V_121 ) ) {
V_2 -> V_122 = false ;
F_147 ( V_2 ) ;
}
F_143 ( & V_2 -> V_94 ) ;
}
F_148 (rsp, rnp) {
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
V_13 = F_17 ( V_5 -> V_18 ) ;
F_149 ( V_2 ) ;
V_2 -> V_95 = V_2 -> V_121 ;
F_2 ( V_2 -> V_7 ) = V_5 -> V_7 ;
if ( F_58 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_2 ( V_2 -> V_6 ) = V_5 -> V_6 ;
if ( V_2 == V_13 -> V_20 )
( void ) F_137 ( V_5 , V_2 , V_13 ) ;
F_150 ( V_2 ) ;
F_151 ( V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_110 , V_2 -> V_97 ,
V_2 -> V_96 , V_2 -> V_95 ) ;
F_143 ( & V_2 -> V_94 ) ;
F_152 () ;
F_2 ( V_5 -> V_92 ) = V_83 ;
if ( V_123 > 0 &&
! ( V_5 -> V_7 % ( V_124 * V_125 ) ) )
F_153 ( V_123 ) ;
}
return 1 ;
}
static int F_154 ( struct V_4 * V_5 , int V_126 )
{
int V_127 = V_126 ;
bool V_72 = false ;
unsigned long V_73 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_2 ( V_5 -> V_92 ) = V_83 ;
V_5 -> V_90 ++ ;
if ( V_127 == V_128 ) {
if ( F_155 ( V_5 ) ) {
V_72 = true ;
V_73 = V_83 - V_76 / 4 ;
}
F_156 ( V_5 , F_86 ,
& V_72 , & V_73 ) ;
F_157 ( V_5 , V_72 , V_73 ) ;
V_127 = V_129 ;
} else {
V_72 = true ;
F_156 ( V_5 , F_90 , & V_72 , & V_73 ) ;
}
if ( F_2 ( V_5 -> V_38 ) & V_130 ) {
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
F_2 ( V_5 -> V_38 ) =
F_2 ( V_5 -> V_38 ) & ~ V_130 ;
F_143 ( & V_2 -> V_94 ) ;
}
return V_127 ;
}
static void F_158 ( struct V_4 * V_5 )
{
unsigned long V_131 ;
bool V_132 = false ;
int V_133 = 0 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_2 ( V_5 -> V_92 ) = V_83 ;
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
V_131 = V_83 - V_5 -> V_82 ;
if ( V_131 > V_5 -> V_134 )
V_5 -> V_134 = V_131 ;
F_143 ( & V_2 -> V_94 ) ;
F_148 (rsp, rnp) {
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
F_58 ( F_159 ( V_2 ) ) ;
F_58 ( V_2 -> V_95 ) ;
F_2 ( V_2 -> V_6 ) = V_5 -> V_7 ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( V_2 == V_13 -> V_20 )
V_132 = F_137 ( V_5 , V_2 , V_13 ) || V_132 ;
V_133 += F_131 ( V_5 , V_2 ) ;
F_143 ( & V_2 -> V_94 ) ;
F_152 () ;
F_2 ( V_5 -> V_92 ) = V_83 ;
}
V_2 = F_44 ( V_5 ) ;
F_142 ( & V_2 -> V_94 ) ;
F_128 () ;
F_160 ( V_2 , V_133 ) ;
F_2 ( V_5 -> V_6 ) = V_5 -> V_7 ;
F_6 ( V_5 -> V_27 , V_5 -> V_6 , F_7 ( L_39 ) ) ;
V_5 -> V_127 = V_135 ;
V_13 = F_17 ( V_5 -> V_18 ) ;
V_132 = F_136 ( V_5 , V_2 , V_13 ) || V_132 ;
if ( V_132 || F_46 ( V_5 , V_13 ) ) {
F_2 ( V_5 -> V_38 ) = V_136 ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
}
F_143 ( & V_2 -> V_94 ) ;
}
static int T_3 F_161 ( void * V_137 )
{
int V_127 ;
int V_138 ;
unsigned long V_87 ;
int V_69 ;
struct V_4 * V_5 = V_137 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_162 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_41 ) ) ;
V_5 -> V_28 = V_139 ;
F_163 ( V_5 -> V_116 ,
F_2 ( V_5 -> V_38 ) &
V_136 ) ;
if ( F_141 ( V_5 ) )
break;
F_152 () ;
F_2 ( V_5 -> V_92 ) = V_83 ;
F_164 ( F_165 ( V_55 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_42 ) ) ;
}
V_127 = V_128 ;
V_87 = V_140 ;
if ( V_87 > V_93 ) {
V_87 = V_93 ;
V_140 = V_93 ;
}
V_69 = 0 ;
for (; ; ) {
if ( ! V_69 )
V_5 -> V_141 = V_83 + V_87 ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
V_5 -> V_28 = V_142 ;
V_69 = F_166 ( V_5 -> V_116 ,
( ( V_138 = F_2 ( V_5 -> V_38 ) ) &
V_130 ) ||
( ! F_2 ( V_2 -> V_95 ) &&
! F_159 ( V_2 ) ) ,
V_87 ) ;
if ( ! F_2 ( V_2 -> V_95 ) &&
! F_159 ( V_2 ) )
break;
if ( F_92 ( V_83 , V_5 -> V_141 ) ||
( V_138 & V_130 ) ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
V_127 = F_154 ( V_5 , V_127 ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
F_152 () ;
F_2 ( V_5 -> V_92 ) = V_83 ;
} else {
F_152 () ;
F_2 ( V_5 -> V_92 ) = V_83 ;
F_164 ( F_165 ( V_55 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
V_87 = V_103 ;
if ( V_87 > V_93 ) {
V_87 = V_93 ;
V_103 = V_93 ;
} else if ( V_87 < 1 ) {
V_87 = 1 ;
V_103 = 1 ;
}
}
F_158 ( V_5 ) ;
}
}
static bool
F_129 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( ! V_5 -> V_29 || ! F_46 ( V_5 , V_13 ) ) {
return false ;
}
F_2 ( V_5 -> V_38 ) = V_136 ;
F_6 ( V_5 -> V_27 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
return true ;
}
static bool F_167 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
bool V_69 = false ;
V_69 = F_136 ( V_5 , V_2 , V_13 ) || V_69 ;
V_69 = F_129 ( V_5 , V_2 , V_13 ) || V_69 ;
return V_69 ;
}
static void F_168 ( struct V_4 * V_5 , unsigned long V_11 )
__releases( rcu_get_root( V_5 )->lock
static void
F_169 ( unsigned long V_143 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_104 , unsigned long V_11 )
__releases( V_2 -> V_94 )
{
unsigned long V_120 = 0 ;
struct V_1 * V_144 ;
for (; ; ) {
if ( ! ( V_2 -> V_95 & V_143 ) || V_2 -> V_7 != V_104 ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
F_58 ( V_120 ) ;
V_2 -> V_95 &= ~ V_143 ;
F_170 ( V_5 -> V_27 , V_2 -> V_7 ,
V_143 , V_2 -> V_95 , V_2 -> V_110 ,
V_2 -> V_97 , V_2 -> V_96 ,
! ! V_2 -> V_145 ) ;
if ( V_2 -> V_95 != 0 || F_159 ( V_2 ) ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
V_143 = V_2 -> V_70 ;
if ( V_2 -> V_146 == NULL ) {
break;
}
F_105 ( & V_2 -> V_94 , V_11 ) ;
V_144 = V_2 ;
V_2 = V_2 -> V_146 ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
F_128 () ;
V_120 = V_144 -> V_95 ;
}
F_168 ( V_5 , V_11 ) ;
}
static void F_171 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_11 )
__releases( V_2 -> V_94 )
{
unsigned long V_104 ;
unsigned long V_143 ;
struct V_1 * V_147 ;
if ( V_24 == & V_25 || V_5 != V_24 ||
V_2 -> V_95 != 0 || F_159 ( V_2 ) ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
V_147 = V_2 -> V_146 ;
if ( V_147 == NULL ) {
F_168 ( V_5 , V_11 ) ;
return;
}
V_104 = V_2 -> V_7 ;
V_143 = V_2 -> V_70 ;
F_130 ( & V_2 -> V_94 ) ;
F_127 ( & V_147 -> V_94 ) ;
F_128 () ;
F_169 ( V_143 , V_5 , V_147 , V_104 , V_11 ) ;
}
static void
F_172 ( int V_75 , struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
unsigned long V_143 ;
bool V_119 ;
struct V_1 * V_2 ;
V_2 = V_13 -> V_20 ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
F_128 () ;
if ( ( V_13 -> V_9 == 0 &&
V_13 -> V_117 == F_5 ( V_23 ) ) ||
V_13 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_13 -> V_77 ) {
V_13 -> V_9 = 0 ;
V_13 -> V_117 = F_5 ( V_23 ) ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
V_143 = V_13 -> V_70 ;
if ( ( V_2 -> V_95 & V_143 ) == 0 ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
} else {
V_13 -> V_118 = 0 ;
V_119 = F_135 ( V_5 , V_2 , V_13 ) ;
F_169 ( V_143 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
if ( V_119 )
F_133 ( V_5 ) ;
}
}
static void
F_173 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
F_139 ( V_5 , V_13 ) ;
if ( ! V_13 -> V_118 )
return;
if ( ! V_13 -> V_9 &&
V_13 -> V_117 == F_5 ( V_23 ) )
return;
F_172 ( V_13 -> V_75 , V_5 , V_13 ) ;
}
static void
F_174 ( int V_75 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( F_175 ( V_13 -> V_75 ) )
return;
if ( V_13 -> V_40 != NULL ) {
V_5 -> V_148 += V_13 -> V_148 ;
V_5 -> V_102 += V_13 -> V_102 ;
V_13 -> V_149 += V_13 -> V_102 ;
V_13 -> V_148 = 0 ;
F_2 ( V_13 -> V_102 ) = 0 ;
}
if ( * V_13 -> V_41 [ V_42 ] != NULL ) {
* V_5 -> V_150 = * V_13 -> V_41 [ V_42 ] ;
V_5 -> V_150 = V_13 -> V_41 [ V_48 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
}
if ( V_13 -> V_40 != NULL ) {
* V_5 -> V_151 = V_13 -> V_40 ;
V_5 -> V_151 = V_13 -> V_41 [ V_42 ] ;
}
F_121 ( V_13 ) ;
V_13 -> V_41 [ V_48 ] = NULL ;
}
static void F_176 ( struct V_4 * V_5 , unsigned long V_11 )
{
int V_47 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
if ( F_177 ( V_5 , V_13 , V_11 ) )
return;
V_13 -> V_148 += V_5 -> V_148 ;
V_13 -> V_102 += V_5 -> V_102 ;
V_13 -> V_152 += V_5 -> V_102 ;
if ( V_5 -> V_148 != V_5 -> V_102 )
F_178 () ;
V_5 -> V_148 = 0 ;
V_5 -> V_102 = 0 ;
if ( V_5 -> V_153 != NULL ) {
* V_5 -> V_151 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = V_5 -> V_153 ;
for ( V_47 = V_107 - 1 ; V_47 >= V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = V_5 -> V_151 ;
V_5 -> V_153 = NULL ;
V_5 -> V_151 = & V_5 -> V_153 ;
}
if ( V_5 -> V_154 != NULL ) {
* V_13 -> V_41 [ V_48 ] = V_5 -> V_154 ;
V_13 -> V_41 [ V_48 ] = V_5 -> V_150 ;
V_5 -> V_154 = NULL ;
V_5 -> V_150 = & V_5 -> V_154 ;
}
}
static void F_179 ( struct V_4 * V_5 )
{
F_180 (unsigned long mask) ;
F_180 ( struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ) ;
F_180 ( struct V_1 * V_2 = V_13 -> V_20 ) ;
F_180 ( V_143 = V_13 -> V_70 ) ;
F_6 ( V_5 -> V_27 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_95 & V_143 ) ,
F_7 ( L_47 ) ) ;
}
static void F_147 ( struct V_1 * V_155 )
{
long V_143 ;
struct V_1 * V_2 = V_155 ;
if ( V_2 -> V_121 || F_146 ( V_2 ) )
return;
for (; ; ) {
V_143 = V_2 -> V_70 ;
V_2 = V_2 -> V_146 ;
if ( ! V_2 )
break;
F_127 ( & V_2 -> V_94 ) ;
F_128 () ;
V_2 -> V_121 &= ~ V_143 ;
V_2 -> V_95 &= ~ V_143 ;
if ( V_2 -> V_121 ) {
F_130 ( & V_2 -> V_94 ) ;
return;
}
F_130 ( & V_2 -> V_94 ) ;
}
}
static void F_181 ( int V_75 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_143 ;
struct V_12 * V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
V_143 = V_13 -> V_70 ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
F_128 () ;
V_2 -> V_3 &= ~ V_143 ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
static void F_182 ( int V_75 , struct V_4 * V_5 )
{
unsigned long V_11 ;
struct V_12 * V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
F_183 ( V_2 , - 1 ) ;
F_103 ( & V_5 -> V_156 , V_11 ) ;
F_174 ( V_75 , V_5 , V_2 , V_13 ) ;
F_176 ( V_5 , V_11 ) ;
F_105 ( & V_5 -> V_156 , V_11 ) ;
F_54 ( V_13 -> V_102 != 0 || V_13 -> V_40 != NULL ,
L_48 ,
V_75 , V_13 -> V_102 , V_13 -> V_40 ) ;
}
static void F_179 ( struct V_4 * V_5 )
{
}
static void V_57 F_147 ( struct V_1 * V_155 )
{
}
static void F_181 ( int V_75 , struct V_4 * V_5 )
{
}
static void F_182 ( int V_75 , struct V_4 * V_5 )
{
}
static void F_184 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
struct V_157 * V_158 , * V_159 , * * V_160 ;
long V_161 , V_162 , V_163 ;
int V_47 ;
if ( ! F_43 ( V_13 ) ) {
F_185 ( V_5 -> V_27 , V_13 -> V_148 , V_13 -> V_102 , 0 ) ;
F_186 ( V_5 -> V_27 , 0 , ! ! F_2 ( V_13 -> V_40 ) ,
F_187 () , F_50 ( V_55 ) ,
F_188 () ) ;
return;
}
F_11 ( V_11 ) ;
F_58 ( F_93 ( F_52 () ) ) ;
V_161 = V_13 -> V_164 ;
F_185 ( V_5 -> V_27 , V_13 -> V_148 , V_13 -> V_102 , V_161 ) ;
V_159 = V_13 -> V_40 ;
V_13 -> V_40 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
V_160 = V_13 -> V_41 [ V_42 ] ;
for ( V_47 = V_107 - 1 ; V_47 >= 0 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
F_21 ( V_11 ) ;
V_162 = V_163 = 0 ;
while ( V_159 ) {
V_158 = V_159 -> V_158 ;
F_189 ( V_158 ) ;
F_190 ( V_159 ) ;
if ( F_191 ( V_5 -> V_27 , V_159 ) )
V_163 ++ ;
V_159 = V_158 ;
if ( ++ V_162 >= V_161 &&
( F_187 () ||
( ! F_50 ( V_55 ) && ! F_188 () ) ) )
break;
}
F_11 ( V_11 ) ;
F_186 ( V_5 -> V_27 , V_162 , ! ! V_159 , F_187 () ,
F_50 ( V_55 ) ,
F_188 () ) ;
if ( V_159 != NULL ) {
* V_160 = V_13 -> V_40 ;
V_13 -> V_40 = V_159 ;
for ( V_47 = 0 ; V_47 < V_107 ; V_47 ++ )
if ( & V_13 -> V_40 == V_13 -> V_41 [ V_47 ] )
V_13 -> V_41 [ V_47 ] = V_160 ;
else
break;
}
F_16 () ;
V_13 -> V_148 -= V_163 ;
F_2 ( V_13 -> V_102 ) = V_13 -> V_102 - V_162 ;
V_13 -> V_165 += V_162 ;
if ( V_13 -> V_164 == V_166 && V_13 -> V_102 <= V_167 )
V_13 -> V_164 = V_164 ;
if ( V_13 -> V_102 == 0 && V_13 -> V_168 != 0 ) {
V_13 -> V_168 = 0 ;
V_13 -> V_169 = V_5 -> V_90 ;
} else if ( V_13 -> V_102 < V_13 -> V_168 - V_170 )
V_13 -> V_168 = V_13 -> V_102 ;
F_58 ( ( V_13 -> V_40 == NULL ) != ( V_13 -> V_102 == 0 ) ) ;
F_21 ( V_11 ) ;
if ( F_43 ( V_13 ) )
F_192 () ;
}
void F_193 ( int V_53 )
{
F_23 ( F_7 ( L_49 ) ) ;
F_194 () ;
if ( V_53 || F_85 () ) {
F_4 () ;
F_9 () ;
} else if ( ! F_195 () ) {
F_9 () ;
}
F_196 () ;
if ( F_197 () )
F_192 () ;
if ( V_53 )
F_198 ( V_55 ) ;
F_23 ( F_7 ( L_50 ) ) ;
}
static void F_156 ( struct V_4 * V_5 ,
int (* F_199)( struct V_12 * V_5 , bool * V_72 ,
unsigned long * V_73 ) ,
bool * V_72 , unsigned long * V_73 )
{
unsigned long V_171 ;
int V_75 ;
unsigned long V_11 ;
unsigned long V_143 ;
struct V_1 * V_2 ;
F_102 (rsp, rnp) {
F_152 () ;
V_143 = 0 ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
F_128 () ;
if ( ! F_3 ( V_5 ) ) {
F_105 ( & V_2 -> V_94 , V_11 ) ;
return;
}
if ( V_2 -> V_95 == 0 ) {
if ( V_24 == & V_25 ||
V_5 != V_24 ||
F_159 ( V_2 ) ) {
F_200 ( V_2 , V_11 ) ;
continue;
}
if ( V_2 -> V_146 &&
( V_2 -> V_146 -> V_95 & V_2 -> V_70 ) ) {
F_171 ( V_5 , V_2 , V_11 ) ;
continue;
}
}
V_75 = V_2 -> V_97 ;
V_171 = 1 ;
for (; V_75 <= V_2 -> V_96 ; V_75 ++ , V_171 <<= 1 ) {
if ( ( V_2 -> V_95 & V_171 ) != 0 ) {
if ( ( V_2 -> V_121 & V_171 ) == 0 )
* V_72 = false ;
if ( F_199 ( F_112 ( V_5 -> V_18 , V_75 ) , V_72 , V_73 ) )
V_143 |= V_171 ;
}
}
if ( V_143 != 0 ) {
F_169 ( V_143 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
} else {
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
}
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_69 ;
struct V_1 * V_2 ;
struct V_1 * V_172 = NULL ;
V_2 = F_5 ( V_5 -> V_18 -> V_20 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_146 ) {
V_69 = ( F_2 ( V_5 -> V_38 ) & V_130 ) ||
! F_140 ( & V_2 -> V_173 ) ;
if ( V_172 != NULL )
F_130 ( & V_172 -> V_173 ) ;
if ( V_69 ) {
V_5 -> V_174 ++ ;
return;
}
V_172 = V_2 ;
}
F_103 ( & V_172 -> V_94 , V_11 ) ;
F_128 () ;
F_130 ( & V_172 -> V_173 ) ;
if ( F_2 ( V_5 -> V_38 ) & V_130 ) {
V_5 -> V_174 ++ ;
F_105 ( & V_172 -> V_94 , V_11 ) ;
return;
}
F_2 ( V_5 -> V_38 ) =
F_2 ( V_5 -> V_38 ) | V_130 ;
F_105 ( & V_172 -> V_94 , V_11 ) ;
F_133 ( V_5 ) ;
}
static void
F_201 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_119 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_58 ( V_13 -> V_175 == 0 ) ;
F_173 ( V_5 , V_13 ) ;
F_11 ( V_11 ) ;
if ( F_46 ( V_5 , V_13 ) ) {
F_127 ( & F_44 ( V_5 ) -> V_94 ) ;
V_119 = F_167 ( V_5 ) ;
F_105 ( & F_44 ( V_5 ) -> V_94 , V_11 ) ;
if ( V_119 )
F_133 ( V_5 ) ;
} else {
F_21 ( V_11 ) ;
}
if ( F_43 ( V_13 ) )
F_202 ( V_5 , V_13 ) ;
F_55 ( V_13 ) ;
}
static void F_203 ( struct V_176 * V_177 )
{
struct V_4 * V_5 ;
if ( F_93 ( F_52 () ) )
return;
F_23 ( F_7 ( L_51 ) ) ;
F_14 (rsp)
F_201 ( V_5 ) ;
F_23 ( F_7 ( L_52 ) ) ;
}
static void F_202 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
if ( F_25 ( ! F_2 ( V_71 ) ) )
return;
if ( F_204 ( ! V_5 -> V_178 ) ) {
F_184 ( V_5 , V_13 ) ;
return;
}
F_205 () ;
}
static void F_192 ( void )
{
if ( F_206 ( F_52 () ) )
F_207 ( V_179 ) ;
}
static void F_208 ( struct V_4 * V_5 , struct V_12 * V_13 ,
struct V_157 * V_180 , unsigned long V_11 )
{
bool V_119 ;
if ( ! F_80 () )
F_192 () ;
if ( F_209 ( V_11 ) || F_93 ( F_52 () ) )
return;
if ( F_25 ( V_13 -> V_102 > V_13 -> V_168 + V_170 ) ) {
F_139 ( V_5 , V_13 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_112 = F_44 ( V_5 ) ;
F_127 ( & V_112 -> V_94 ) ;
F_128 () ;
V_119 = F_167 ( V_5 ) ;
F_130 ( & V_112 -> V_94 ) ;
if ( V_119 )
F_133 ( V_5 ) ;
} else {
V_13 -> V_164 = V_166 ;
if ( V_5 -> V_90 == V_13 -> V_169 &&
* V_13 -> V_41 [ V_42 ] != V_180 )
F_35 ( V_5 ) ;
V_13 -> V_169 = V_5 -> V_90 ;
V_13 -> V_168 = V_13 -> V_102 ;
}
}
}
static void F_210 ( struct V_157 * V_181 )
{
}
static void
F_211 ( struct V_157 * V_180 , void (* F_212)( struct V_157 * V_182 ) ,
struct V_4 * V_5 , int V_75 , bool V_183 )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
F_58 ( ( unsigned long ) V_180 & 0x1 ) ;
if ( F_213 ( V_180 ) ) {
F_2 ( V_180 -> F_212 ) = F_210 ;
F_54 ( 1 , L_53 ) ;
return;
}
V_180 -> F_212 = F_212 ;
V_180 -> V_158 = NULL ;
F_11 ( V_11 ) ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( F_25 ( V_13 -> V_41 [ V_48 ] == NULL ) || V_75 != - 1 ) {
int V_184 ;
if ( V_75 != - 1 )
V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
if ( F_204 ( V_13 -> V_20 ) ) {
V_184 = ! F_214 ( V_13 , V_180 , V_183 , V_11 ) ;
F_58 ( V_184 ) ;
F_21 ( V_11 ) ;
return;
}
F_215 ( V_75 != - 1 ) ;
F_58 ( ! F_80 () ) ;
if ( ! F_204 ( V_13 -> V_40 ) )
F_120 ( V_13 ) ;
}
F_2 ( V_13 -> V_102 ) = V_13 -> V_102 + 1 ;
if ( V_183 )
V_13 -> V_148 ++ ;
else
F_178 () ;
F_16 () ;
* V_13 -> V_41 [ V_48 ] = V_180 ;
V_13 -> V_41 [ V_48 ] = & V_180 -> V_158 ;
if ( F_216 ( ( unsigned long ) F_212 ) )
F_217 ( V_5 -> V_27 , V_180 , ( unsigned long ) F_212 ,
V_13 -> V_148 , V_13 -> V_102 ) ;
else
F_218 ( V_5 -> V_27 , V_180 , V_13 -> V_148 , V_13 -> V_102 ) ;
F_208 ( V_5 , V_13 , V_180 , V_11 ) ;
F_21 ( V_11 ) ;
}
void F_219 ( struct V_157 * V_180 , void (* F_212)( struct V_157 * V_182 ) )
{
F_211 ( V_180 , F_212 , & V_25 , - 1 , 0 ) ;
}
void F_220 ( struct V_157 * V_180 , void (* F_212)( struct V_157 * V_182 ) )
{
F_211 ( V_180 , F_212 , & V_26 , - 1 , 0 ) ;
}
void F_221 ( struct V_157 * V_180 ,
void (* F_212)( struct V_157 * V_182 ) )
{
F_211 ( V_180 , F_212 , V_24 , - 1 , 1 ) ;
}
static inline int F_222 ( void )
{
int V_69 ;
F_223 () ;
F_81 () ;
V_69 = F_224 () <= 1 ;
F_82 () ;
return V_69 ;
}
void F_225 ( void )
{
F_61 ( ! F_62 ( & V_62 ) &&
! F_62 ( & V_61 ) &&
! F_62 ( & V_63 ) ,
L_54 ) ;
if ( F_222 () )
return;
if ( F_226 () )
F_227 () ;
else
F_228 ( F_219 ) ;
}
void F_229 ( void )
{
F_61 ( ! F_62 ( & V_62 ) &&
! F_62 ( & V_61 ) &&
! F_62 ( & V_63 ) ,
L_55 ) ;
if ( F_222 () )
return;
if ( F_226 () )
F_230 () ;
else
F_228 ( F_220 ) ;
}
unsigned long F_231 ( void )
{
F_16 () ;
return F_232 ( & V_24 -> V_7 ) ;
}
void F_233 ( unsigned long V_185 )
{
unsigned long V_186 ;
V_186 = F_232 ( & V_24 -> V_6 ) ;
if ( F_92 ( V_185 , V_186 ) )
F_234 () ;
}
static int F_235 ( void * V_187 )
{
F_16 () ;
return 0 ;
}
void F_227 ( void )
{
T_4 V_188 ;
bool V_189 = false ;
int V_75 ;
long V_190 , V_109 , V_80 ;
int V_191 = 0 ;
struct V_4 * V_5 = & V_25 ;
if ( F_92 ( ( V_192 ) F_236 ( & V_5 -> V_193 ) ,
( V_192 ) F_236 ( & V_5 -> V_194 ) +
V_76 / 8 ) ) {
F_225 () ;
F_237 ( & V_5 -> V_195 ) ;
return;
}
V_80 = F_238 ( & V_5 -> V_193 ) ;
V_190 = V_80 ;
if ( ! F_239 () ) {
F_228 ( F_219 ) ;
F_237 ( & V_5 -> V_196 ) ;
return;
}
F_58 ( F_93 ( F_240 () ) ) ;
V_189 = F_241 ( & V_188 , V_197 ) ;
if ( V_189 ) {
F_242 ( V_188 , V_198 ) ;
F_243 ( F_240 () , V_188 ) ;
F_244 (cpu, cm) {
struct V_14 * V_15 = & F_94 ( V_14 , V_75 ) ;
if ( ! ( F_87 ( 0 , & V_15 -> V_22 ) & 0x1 ) )
F_243 ( V_75 , V_188 ) ;
}
if ( F_245 ( V_188 ) == 0 )
goto V_199;
}
while ( F_246 ( V_189 ? V_188 : V_198 ,
F_235 ,
NULL ) == - V_200 ) {
F_247 () ;
F_237 ( & V_5 -> V_201 ) ;
V_109 = F_236 ( & V_5 -> V_194 ) ;
if ( F_92 ( ( V_192 ) V_109 , ( V_192 ) V_190 ) ) {
F_18 () ;
F_237 ( & V_5 -> V_202 ) ;
F_248 ( V_188 ) ;
return;
}
if ( V_191 ++ < 10 ) {
F_249 ( V_191 * F_224 () ) ;
} else {
F_228 ( F_219 ) ;
F_237 ( & V_5 -> V_196 ) ;
F_248 ( V_188 ) ;
return;
}
V_109 = F_236 ( & V_5 -> V_194 ) ;
if ( F_92 ( ( V_192 ) V_109 , ( V_192 ) V_190 ) ) {
F_18 () ;
F_237 ( & V_5 -> V_203 ) ;
F_248 ( V_188 ) ;
return;
}
if ( ! F_239 () ) {
F_228 ( F_219 ) ;
F_237 ( & V_5 -> V_196 ) ;
F_248 ( V_188 ) ;
return;
}
V_80 = F_236 ( & V_5 -> V_193 ) ;
F_16 () ;
}
F_237 ( & V_5 -> V_204 ) ;
V_199:
F_248 ( V_188 ) ;
do {
F_237 ( & V_5 -> V_205 ) ;
V_109 = F_236 ( & V_5 -> V_194 ) ;
if ( F_92 ( ( V_192 ) V_109 , ( V_192 ) V_80 ) ) {
F_18 () ;
F_237 ( & V_5 -> V_206 ) ;
break;
}
} while ( F_250 ( & V_5 -> V_194 , V_109 , V_80 ) != V_109 );
F_237 ( & V_5 -> V_207 ) ;
F_247 () ;
}
static int F_251 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_20 ;
V_13 -> V_208 ++ ;
F_117 ( V_5 , V_13 ) ;
if ( F_252 ( V_5 ) )
return 0 ;
if ( V_71 &&
V_13 -> V_118 && ! V_13 -> V_9 &&
V_13 -> V_117 == F_5 ( V_23 ) ) {
V_13 -> V_209 ++ ;
} else if ( V_13 -> V_118 &&
( V_13 -> V_9 ||
V_13 -> V_117 != F_5 ( V_23 ) ) ) {
V_13 -> V_210 ++ ;
return 1 ;
}
if ( F_43 ( V_13 ) ) {
V_13 -> V_211 ++ ;
return 1 ;
}
if ( F_46 ( V_5 , V_13 ) ) {
V_13 -> V_212 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_13 -> V_6 ) {
V_13 -> V_213 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_13 -> V_7 ||
F_25 ( F_2 ( V_13 -> V_77 ) ) ) {
V_13 -> V_214 ++ ;
return 1 ;
}
if ( F_253 ( V_13 ) ) {
V_13 -> V_215 ++ ;
return 1 ;
}
V_13 -> V_216 ++ ;
return 0 ;
}
static int F_197 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
if ( F_251 ( V_5 , F_17 ( V_5 -> V_18 ) ) )
return 1 ;
return 0 ;
}
static int V_57 F_254 ( bool * V_217 )
{
bool V_218 = true ;
bool V_219 = false ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( ! V_13 -> V_40 )
continue;
V_219 = true ;
if ( V_13 -> V_102 != V_13 -> V_148 || ! V_217 ) {
V_218 = false ;
break;
}
}
if ( V_217 )
* V_217 = V_218 ;
return V_219 ;
}
static void F_255 ( struct V_4 * V_5 , const char * V_109 ,
int V_75 , unsigned long V_220 )
{
F_256 ( V_5 -> V_27 , V_109 , V_75 ,
F_59 ( & V_5 -> V_221 ) , V_220 ) ;
}
static void F_257 ( struct V_157 * V_181 )
{
struct V_12 * V_13 = F_258 ( V_181 , struct V_12 , V_222 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
if ( F_259 ( & V_5 -> V_221 ) ) {
F_255 ( V_5 , L_56 , - 1 , V_5 -> V_223 ) ;
F_260 ( & V_5 -> V_224 ) ;
} else {
F_255 ( V_5 , L_57 , - 1 , V_5 -> V_223 ) ;
}
}
static void F_261 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_255 ( V_5 , L_58 , - 1 , V_5 -> V_223 ) ;
F_57 ( & V_5 -> V_221 ) ;
V_5 -> V_225 ( & V_13 -> V_222 , F_257 ) ;
}
static void F_262 ( struct V_4 * V_5 )
{
int V_75 ;
struct V_12 * V_13 ;
unsigned long V_80 = F_2 ( V_5 -> V_223 ) ;
unsigned long V_226 ;
F_255 ( V_5 , L_59 , - 1 , V_80 ) ;
F_263 ( & V_5 -> V_227 ) ;
F_16 () ;
V_226 = V_5 -> V_223 ;
F_255 ( V_5 , L_60 , - 1 , V_226 ) ;
if ( F_92 ( V_226 , ( V_80 + 3 ) & ~ 0x1 ) ) {
F_255 ( V_5 , L_61 , - 1 , V_226 ) ;
F_16 () ;
F_264 ( & V_5 -> V_227 ) ;
return;
}
F_2 ( V_5 -> V_223 ) = V_5 -> V_223 + 1 ;
F_58 ( ( V_5 -> V_223 & 0x1 ) != 1 ) ;
F_255 ( V_5 , L_62 , - 1 , V_5 -> V_223 ) ;
F_16 () ;
F_265 ( & V_5 -> V_224 ) ;
F_266 ( & V_5 -> V_221 , 1 ) ;
F_267 () ;
F_111 (cpu) {
if ( ! F_206 ( V_75 ) && ! F_175 ( V_75 ) )
continue;
V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
if ( F_175 ( V_75 ) ) {
if ( ! F_268 ( V_5 , V_75 ) ) {
F_255 ( V_5 , L_63 , V_75 ,
V_5 -> V_223 ) ;
} else {
F_255 ( V_5 , L_64 , V_75 ,
V_5 -> V_223 ) ;
F_18 () ;
F_57 ( & V_5 -> V_221 ) ;
F_211 ( & V_13 -> V_222 ,
F_257 , V_5 , V_75 , 0 ) ;
}
} else if ( F_2 ( V_13 -> V_102 ) ) {
F_255 ( V_5 , L_65 , V_75 ,
V_5 -> V_223 ) ;
F_269 ( V_75 , F_261 , V_5 , 1 ) ;
} else {
F_255 ( V_5 , L_66 , V_75 ,
V_5 -> V_223 ) ;
}
}
F_247 () ;
if ( F_259 ( & V_5 -> V_221 ) )
F_260 ( & V_5 -> V_224 ) ;
F_16 () ;
F_2 ( V_5 -> V_223 ) = V_5 -> V_223 + 1 ;
F_58 ( ( V_5 -> V_223 & 0x1 ) != 0 ) ;
F_255 ( V_5 , L_67 , - 1 , V_5 -> V_223 ) ;
F_16 () ;
F_270 ( & V_5 -> V_224 ) ;
F_264 ( & V_5 -> V_227 ) ;
}
void F_271 ( void )
{
F_262 ( & V_26 ) ;
}
void F_272 ( void )
{
F_262 ( & V_25 ) ;
}
static void F_145 ( struct V_1 * V_155 )
{
long V_143 ;
struct V_1 * V_2 = V_155 ;
for (; ; ) {
V_143 = V_2 -> V_70 ;
V_2 = V_2 -> V_146 ;
if ( V_2 == NULL )
return;
F_127 ( & V_2 -> V_94 ) ;
V_2 -> V_121 |= V_143 ;
F_130 ( & V_2 -> V_94 ) ;
}
}
static void T_5
F_273 ( int V_75 , struct V_4 * V_5 )
{
unsigned long V_11 ;
struct V_12 * V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
V_13 -> V_70 = 1UL << ( V_75 - V_13 -> V_20 -> V_97 ) ;
V_13 -> V_22 = & F_94 ( V_14 , V_75 ) ;
F_58 ( V_13 -> V_22 -> V_54 != V_66 ) ;
F_58 ( F_59 ( & V_13 -> V_22 -> V_22 ) != 1 ) ;
V_13 -> V_75 = V_75 ;
V_13 -> V_5 = V_5 ;
F_274 ( V_13 ) ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
static void
F_275 ( int V_75 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_143 ;
struct V_12 * V_13 = F_112 ( V_5 -> V_18 , V_75 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
V_13 -> V_175 = 1 ;
V_13 -> V_168 = 0 ;
V_13 -> V_169 = V_5 -> V_90 ;
V_13 -> V_164 = V_164 ;
if ( ! V_13 -> V_40 )
F_121 ( V_13 ) ;
V_13 -> V_22 -> V_54 = V_66 ;
F_276 ( V_13 -> V_22 ) ;
F_266 ( & V_13 -> V_22 -> V_22 ,
( F_59 ( & V_13 -> V_22 -> V_22 ) & ~ 0x1 ) + 1 ) ;
F_130 ( & V_2 -> V_94 ) ;
V_2 = V_13 -> V_20 ;
V_143 = V_13 -> V_70 ;
F_127 ( & V_2 -> V_94 ) ;
F_128 () ;
V_2 -> V_3 |= V_143 ;
V_13 -> V_7 = V_2 -> V_6 ;
V_13 -> V_6 = V_2 -> V_6 ;
V_13 -> V_9 = false ;
V_13 -> V_117 = F_5 ( V_23 ) ;
V_13 -> V_118 = false ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_68 ) ) ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
static void F_277 ( int V_75 )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_275 ( V_75 , V_5 ) ;
}
int F_278 ( struct V_228 * V_229 ,
unsigned long V_230 , void * V_231 )
{
long V_75 = ( long ) V_231 ;
struct V_12 * V_13 = F_112 ( V_24 -> V_18 , V_75 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
struct V_4 * V_5 ;
switch ( V_230 ) {
case V_232 :
case V_233 :
F_277 ( V_75 ) ;
F_279 ( V_75 ) ;
F_280 ( V_75 ) ;
break;
case V_234 :
case V_235 :
F_183 ( V_2 , - 1 ) ;
break;
case V_236 :
F_183 ( V_2 , V_75 ) ;
break;
case V_237 :
case V_238 :
F_14 (rsp)
F_179 ( V_5 ) ;
break;
case V_239 :
F_14 (rsp) {
F_181 ( V_75 , V_5 ) ;
}
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
F_14 (rsp) {
F_182 ( V_75 , V_5 ) ;
F_55 ( F_112 ( V_5 -> V_18 , V_75 ) ) ;
}
break;
default:
break;
}
return V_244 ;
}
static int F_281 ( struct V_228 * V_229 ,
unsigned long V_230 , void * V_231 )
{
switch ( V_230 ) {
case V_245 :
case V_246 :
if ( V_247 <= 256 )
F_282 () ;
break;
case V_248 :
case V_249 :
if ( V_247 <= 256 )
F_283 () ;
break;
default:
break;
}
return V_244 ;
}
static int T_5 F_284 ( void )
{
unsigned long V_11 ;
int V_250 = V_251 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_252 V_253 ;
struct V_56 * V_254 ;
if ( F_285 ( V_255 ) && V_251 < 1 )
V_251 = 1 ;
else if ( V_251 < 0 )
V_251 = 0 ;
else if ( V_251 > 99 )
V_251 = 99 ;
if ( V_251 != V_250 )
F_286 ( L_69 ,
V_251 , V_250 ) ;
V_71 = 1 ;
F_14 (rsp) {
V_254 = F_287 ( F_161 , V_5 , L_70 , V_5 -> V_27 ) ;
F_215 ( F_288 ( V_254 ) ) ;
V_2 = F_44 ( V_5 ) ;
F_103 ( & V_2 -> V_94 , V_11 ) ;
V_5 -> V_29 = V_254 ;
if ( V_251 ) {
V_253 . V_256 = V_251 ;
F_289 ( V_254 , V_257 , & V_253 ) ;
}
F_290 ( V_254 ) ;
F_105 ( & V_2 -> V_94 , V_11 ) ;
}
F_291 () ;
F_292 () ;
return 0 ;
}
void F_293 ( void )
{
F_164 ( F_224 () != 1 ) ;
F_164 ( F_294 () > 0 ) ;
V_258 = 1 ;
}
static void T_5 F_295 ( struct V_4 * V_5 )
{
int V_47 ;
if ( F_285 ( V_259 ) ) {
V_5 -> V_260 [ V_261 - 1 ] = V_262 ;
for ( V_47 = V_261 - 2 ; V_47 >= 0 ; V_47 -- )
V_5 -> V_260 [ V_47 ] = V_263 ;
} else {
int V_264 ;
int V_265 ;
V_265 = V_247 ;
for ( V_47 = V_261 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_264 = V_5 -> V_266 [ V_47 ] ;
V_5 -> V_260 [ V_47 ] = ( V_265 + V_264 - 1 ) / V_264 ;
V_265 = V_264 ;
}
}
}
static void T_5 F_296 ( struct V_4 * V_5 ,
struct V_12 T_6 * V_18 )
{
static const char * const V_267 [] = {
L_71 ,
L_72 ,
L_73 ,
L_74 } ;
static const char * const V_268 [] = {
L_75 ,
L_76 ,
L_77 ,
L_78 } ;
static T_7 V_269 = 0x1 ;
int V_270 = 1 ;
int V_47 ;
int V_87 ;
struct V_1 * V_2 ;
F_297 ( V_271 > F_298 ( V_267 ) ) ;
if ( V_261 > V_272 )
F_299 ( L_79 ) ;
for ( V_47 = 0 ; V_47 < V_261 ; V_47 ++ )
V_5 -> V_266 [ V_47 ] = V_273 [ V_47 ] ;
for ( V_47 = 1 ; V_47 < V_261 ; V_47 ++ )
V_5 -> V_110 [ V_47 ] = V_5 -> V_110 [ V_47 - 1 ] + V_5 -> V_266 [ V_47 - 1 ] ;
F_295 ( V_5 ) ;
V_5 -> V_19 = V_269 ;
V_269 <<= 1 ;
for ( V_47 = V_261 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_270 *= V_5 -> V_260 [ V_47 ] ;
V_2 = V_5 -> V_110 [ V_47 ] ;
for ( V_87 = 0 ; V_87 < V_5 -> V_266 [ V_47 ] ; V_87 ++ , V_2 ++ ) {
F_300 ( & V_2 -> V_94 ) ;
F_301 ( & V_2 -> V_94 ,
& V_274 [ V_47 ] , V_267 [ V_47 ] ) ;
F_300 ( & V_2 -> V_173 ) ;
F_301 ( & V_2 -> V_173 ,
& V_275 [ V_47 ] , V_268 [ V_47 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_95 = 0 ;
V_2 -> V_121 = 0 ;
V_2 -> V_97 = V_87 * V_270 ;
V_2 -> V_96 = ( V_87 + 1 ) * V_270 - 1 ;
if ( V_2 -> V_96 >= V_247 )
V_2 -> V_96 = V_247 - 1 ;
if ( V_47 == 0 ) {
V_2 -> V_276 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_146 = NULL ;
} else {
V_2 -> V_276 = V_87 % V_5 -> V_260 [ V_47 - 1 ] ;
V_2 -> V_70 = 1UL << V_2 -> V_276 ;
V_2 -> V_146 = V_5 -> V_110 [ V_47 - 1 ] +
V_87 / V_5 -> V_260 [ V_47 - 1 ] ;
}
V_2 -> V_110 = V_47 ;
F_302 ( & V_2 -> V_277 ) ;
F_303 ( V_2 ) ;
}
}
F_304 ( & V_5 -> V_116 ) ;
V_2 = V_5 -> V_110 [ V_261 - 1 ] ;
F_111 (i) {
while ( V_47 > V_2 -> V_96 )
V_2 ++ ;
F_112 ( V_5 -> V_18 , V_47 ) -> V_20 = V_2 ;
F_273 ( V_47 , V_5 ) ;
}
F_305 ( & V_5 -> V_278 , & V_279 ) ;
}
static void T_5 F_306 ( void )
{
V_192 V_280 ;
int V_47 ;
int V_87 ;
int V_281 = V_247 ;
int V_282 [ V_271 + 1 ] ;
V_280 = V_283 + V_247 / V_284 ;
if ( V_140 == V_76 )
V_140 = V_280 ;
if ( V_103 == V_76 )
V_103 = V_280 ;
if ( V_262 == V_285 &&
V_247 == V_286 )
return;
F_39 ( L_80 ,
V_262 , V_247 ) ;
V_282 [ 0 ] = 1 ;
V_282 [ 1 ] = V_262 ;
for ( V_47 = 2 ; V_47 <= V_271 ; V_47 ++ )
V_282 [ V_47 ] = V_282 [ V_47 - 1 ] * V_263 ;
if ( V_262 < V_285 ||
V_262 > sizeof( unsigned long ) * 8 ||
V_281 > V_282 [ V_271 ] ) {
F_164 ( 1 ) ;
return;
}
for ( V_47 = 1 ; V_47 <= V_271 ; V_47 ++ )
if ( V_281 <= V_282 [ V_47 ] ) {
for ( V_87 = 0 ; V_87 <= V_47 ; V_87 ++ )
V_273 [ V_87 ] =
F_307 ( V_281 , V_282 [ V_47 - V_87 ] ) ;
V_261 = V_47 ;
for ( V_87 = V_47 + 1 ; V_87 <= V_271 ; V_87 ++ )
V_273 [ V_87 ] = 0 ;
break;
}
V_124 = 0 ;
for ( V_47 = 0 ; V_47 <= V_271 ; V_47 ++ )
V_124 += V_273 [ V_47 ] ;
V_124 -= V_281 ;
}
void T_5 F_308 ( void )
{
int V_75 ;
F_309 () ;
F_310 () ;
F_306 () ;
F_296 ( & V_26 , & V_10 ) ;
F_296 ( & V_25 , & V_8 ) ;
F_311 () ;
F_312 ( V_179 , F_203 ) ;
F_313 ( F_278 , 0 ) ;
F_314 ( F_281 , 0 ) ;
F_315 (cpu)
F_278 ( NULL , V_232 , ( void * ) ( long ) V_75 ) ;
}
