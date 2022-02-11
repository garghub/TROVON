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
if ( F_50 ( V_55 ) &&
! V_53 && ! F_51 ( V_56 ) ) {
struct V_57 * T_1 V_58 =
F_52 ( F_53 () ) ;
F_49 ( F_7 ( L_8 ) , V_52 , 0 ) ;
F_54 ( V_59 ) ;
F_55 ( 1 , L_9 ,
V_56 -> V_60 , V_56 -> V_61 ,
T_1 -> V_60 , T_1 -> V_61 ) ;
}
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
F_56 ( V_13 ) ;
}
F_57 () ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_50 ( V_55 ) &&
F_60 ( & V_15 -> V_22 ) & 0x1 ) ;
F_61 () ;
F_62 ( ! F_63 ( & V_62 ) ,
L_10 ) ;
F_62 ( ! F_63 ( & V_63 ) ,
L_11 ) ;
F_62 ( ! F_63 ( & V_64 ) ,
L_12 ) ;
}
static void F_64 ( bool V_53 )
{
long long V_52 ;
struct V_14 * V_15 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_59 ( F_50 ( V_55 ) &&
( V_52 & V_65 ) == 0 ) ;
if ( ( V_52 & V_65 ) == V_66 ) {
V_15 -> V_54 = 0 ;
F_48 ( V_52 , V_53 ) ;
} else {
V_15 -> V_54 -= V_66 ;
}
}
void F_65 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_64 ( false ) ;
F_66 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_67 ( void )
{
F_64 ( 1 ) ;
}
void F_68 ( void )
{
unsigned long V_11 ;
long long V_52 ;
struct V_14 * V_15 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 -- ;
F_59 ( F_50 ( V_55 ) &&
V_15 -> V_54 < 0 ) ;
if ( V_15 -> V_54 )
F_49 ( F_7 ( L_13 ) , V_52 , V_15 -> V_54 ) ;
else
F_48 ( V_52 , true ) ;
F_66 ( 1 ) ;
F_21 ( V_11 ) ;
}
static void F_69 ( long long V_52 , int V_53 )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_70 () ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_50 ( V_55 ) &&
! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
F_71 () ;
F_49 ( F_7 ( L_14 ) , V_52 , V_15 -> V_54 ) ;
if ( F_50 ( V_55 ) &&
! V_53 && ! F_51 ( V_56 ) ) {
struct V_57 * T_1 V_58 =
F_52 ( F_53 () ) ;
F_49 ( F_7 ( L_15 ) ,
V_52 , V_15 -> V_54 ) ;
F_54 ( V_59 ) ;
F_55 ( 1 , L_9 ,
V_56 -> V_60 , V_56 -> V_61 ,
T_1 -> V_60 , T_1 -> V_61 ) ;
}
}
static void F_72 ( bool V_53 )
{
struct V_14 * V_15 ;
long long V_52 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_59 ( F_50 ( V_55 ) && V_52 < 0 ) ;
if ( V_52 & V_65 ) {
V_15 -> V_54 += V_66 ;
} else {
V_15 -> V_54 = V_67 ;
F_69 ( V_52 , V_53 ) ;
}
}
void F_73 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_72 ( false ) ;
F_74 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_75 ( void )
{
F_72 ( 1 ) ;
}
void F_76 ( void )
{
unsigned long V_11 ;
struct V_14 * V_15 ;
long long V_52 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 ++ ;
F_59 ( F_50 ( V_55 ) &&
V_15 -> V_54 == 0 ) ;
if ( V_52 )
F_49 ( F_7 ( L_16 ) , V_52 , V_15 -> V_54 ) ;
else
F_69 ( V_52 , true ) ;
F_74 ( 1 ) ;
F_21 ( V_11 ) ;
}
void F_77 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
int V_68 = 2 ;
F_59 ( V_15 -> V_69 < 0 ) ;
if ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) {
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
V_68 = 1 ;
}
V_15 -> V_69 += V_68 ;
F_78 () ;
}
void F_79 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_59 ( V_15 -> V_69 <= 0 ) ;
F_59 ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
if ( V_15 -> V_69 != 1 ) {
V_15 -> V_69 -= 2 ;
return;
}
V_15 -> V_69 = 0 ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ;
}
bool T_2 F_80 ( void )
{
return F_60 ( F_17 ( & V_14 . V_22 ) ) & 0x1 ;
}
bool T_2 F_81 ( void )
{
bool V_70 ;
F_82 () ;
V_70 = F_80 () ;
F_83 () ;
return V_70 ;
}
bool F_84 ( void )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
bool V_70 ;
if ( F_85 () )
return true ;
F_82 () ;
V_13 = F_17 ( & V_8 ) ;
V_2 = V_13 -> V_20 ;
V_70 = ( V_13 -> V_71 & F_1 ( V_2 ) ) ||
! V_72 ;
F_83 () ;
return V_70 ;
}
static int F_86 ( void )
{
return F_5 ( V_14 . V_54 ) <= 1 ;
}
static int F_87 ( struct V_12 * V_13 ,
bool * V_73 , unsigned long * V_74 )
{
V_13 -> V_75 = F_88 ( 0 , & V_13 -> V_22 -> V_22 ) ;
F_89 ( V_13 , V_73 , V_74 ) ;
if ( ( V_13 -> V_75 & 0x1 ) == 0 ) {
F_90 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_17 ) ) ;
return 1 ;
} else {
if ( F_47 ( F_2 ( V_13 -> V_7 ) + V_77 / 4 ,
V_13 -> V_20 -> V_7 ) )
F_91 ( V_13 -> V_78 , true ) ;
return 0 ;
}
}
static int F_92 ( struct V_12 * V_13 ,
bool * V_73 , unsigned long * V_74 )
{
unsigned int V_79 ;
int * V_80 ;
unsigned int V_81 ;
V_79 = ( unsigned int ) F_88 ( 0 , & V_13 -> V_22 -> V_22 ) ;
V_81 = ( unsigned int ) V_13 -> V_75 ;
if ( ( V_79 & 0x1 ) == 0 || F_93 ( V_79 , V_81 + 2 ) ) {
F_90 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_17 ) ) ;
V_13 -> V_82 ++ ;
return 1 ;
}
if ( F_94 ( V_13 -> V_5 -> V_83 + 2 , V_84 ) )
return 0 ;
F_78 () ;
if ( F_95 ( V_13 -> V_76 ) ) {
F_90 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_18 ) ) ;
V_13 -> V_85 ++ ;
return 1 ;
}
V_80 = & F_96 ( V_17 , V_13 -> V_76 ) ;
if ( F_94 ( V_84 ,
V_13 -> V_5 -> V_83 + V_86 ) ||
F_94 ( V_84 , V_13 -> V_5 -> V_87 ) ) {
if ( ! ( F_2 ( * V_80 ) & V_13 -> V_5 -> V_19 ) ) {
F_91 ( V_13 -> V_21 ,
F_2 ( V_13 -> V_20 -> V_6 ) ) ;
F_16 () ;
F_91 ( * V_80 ,
F_2 ( * V_80 ) + V_13 -> V_5 -> V_19 ) ;
F_97 ( V_13 -> V_76 ) ;
V_13 -> V_5 -> V_87 += 5 ;
} else if ( F_94 ( V_84 , V_13 -> V_5 -> V_87 ) ) {
F_97 ( V_13 -> V_76 ) ;
V_13 -> V_5 -> V_87 += 5 ;
}
}
return 0 ;
}
static void F_98 ( struct V_4 * V_5 )
{
unsigned long V_88 = V_84 ;
unsigned long j1 ;
V_5 -> V_83 = V_88 ;
F_99 () ;
j1 = F_100 () ;
F_91 ( V_5 -> V_89 , V_88 + j1 ) ;
V_5 -> V_87 = V_88 + j1 / 2 ;
V_5 -> V_90 = F_2 ( V_5 -> V_91 ) ;
}
static void F_101 ( struct V_4 * V_5 )
{
unsigned long V_92 ;
unsigned long V_88 ;
V_88 = V_84 ;
V_92 = F_2 ( V_5 -> V_93 ) ;
if ( V_88 - V_92 > 2 * V_94 )
F_102 ( L_19 ,
V_5 -> V_27 , V_88 - V_92 ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_38 ) ;
}
static void F_103 ( struct V_4 * V_5 )
{
int V_76 ;
unsigned long V_11 ;
struct V_1 * V_2 ;
F_104 (rsp, rnp) {
F_105 ( & V_2 -> V_95 , V_11 ) ;
if ( V_2 -> V_96 != 0 ) {
for ( V_76 = 0 ; V_76 <= V_2 -> V_97 - V_2 -> V_98 ; V_76 ++ )
if ( V_2 -> V_96 & ( 1UL << V_76 ) )
F_106 ( V_2 -> V_98 + V_76 ) ;
}
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
}
static void F_108 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_76 ;
long V_99 ;
unsigned long V_11 ;
unsigned long V_92 ;
unsigned long V_88 ;
int V_100 = 0 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_101 = 0 ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
V_99 = V_84 - F_2 ( V_5 -> V_89 ) ;
if ( V_99 < V_102 || ! F_3 ( V_5 ) ) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
return;
}
F_91 ( V_5 -> V_89 ,
V_84 + 3 * F_100 () + 3 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_102 ( L_20 ,
V_5 -> V_27 ) ;
F_109 () ;
F_104 (rsp, rnp) {
F_105 ( & V_2 -> V_95 , V_11 ) ;
V_100 += F_110 ( V_2 ) ;
if ( V_2 -> V_96 != 0 ) {
for ( V_76 = 0 ; V_76 <= V_2 -> V_97 - V_2 -> V_98 ; V_76 ++ )
if ( V_2 -> V_96 & ( 1UL << V_76 ) ) {
F_111 ( V_5 ,
V_2 -> V_98 + V_76 ) ;
V_100 ++ ;
}
}
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
F_112 () ;
F_113 (cpu)
V_101 += F_114 ( V_5 -> V_18 , V_76 ) -> V_103 ;
F_115 ( L_21 ,
F_53 () , ( long ) ( V_84 - V_5 -> V_83 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_101 ) ;
if ( V_100 ) {
F_103 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_102 ( L_22 ) ;
} else {
V_88 = V_84 ;
V_92 = F_2 ( V_5 -> V_93 ) ;
F_102 ( L_23 ,
V_5 -> V_27 , V_88 - V_92 , V_88 , V_92 ,
V_104 ,
F_44 ( V_5 ) -> V_96 ) ;
F_116 ( V_56 ) ;
}
}
F_117 ( V_5 ) ;
F_101 ( V_5 ) ;
F_35 ( V_5 ) ;
}
static void F_118 ( struct V_4 * V_5 )
{
int V_76 ;
unsigned long V_11 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_101 = 0 ;
F_102 ( L_24 , V_5 -> V_27 ) ;
F_109 () ;
F_111 ( V_5 , F_53 () ) ;
F_112 () ;
F_113 (cpu)
V_101 += F_114 ( V_5 -> V_18 , V_76 ) -> V_103 ;
F_115 ( L_25 ,
V_84 - V_5 -> V_83 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_101 ) ;
F_101 ( V_5 ) ;
F_103 ( V_5 ) ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
if ( F_94 ( V_84 , F_2 ( V_5 -> V_89 ) ) )
F_91 ( V_5 -> V_89 ,
V_84 + 3 * F_100 () + 3 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_97 ( F_53 () ) ;
}
static void F_119 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_105 ;
unsigned long V_88 ;
unsigned long V_106 ;
struct V_1 * V_2 ;
if ( V_107 || ! F_3 ( V_5 ) )
return;
V_88 = V_84 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_120 () ;
V_106 = F_2 ( V_5 -> V_89 ) ;
F_120 () ;
V_105 = F_2 ( V_5 -> V_83 ) ;
F_120 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_94 ( V_6 , V_7 ) ||
F_47 ( V_88 , V_106 ) ||
F_94 ( V_105 , V_106 ) )
return;
V_2 = V_13 -> V_20 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_96 ) & V_13 -> V_71 ) ) {
F_118 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_94 ( V_88 , V_106 + V_102 ) ) {
F_108 ( V_5 , V_7 ) ;
}
}
void F_121 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_91 ( V_5 -> V_89 , V_84 + V_77 / 2 ) ;
}
static void F_122 ( struct V_12 * V_13 )
{
int V_47 ;
V_13 -> V_40 = NULL ;
for ( V_47 = 0 ; V_47 < V_108 ; V_47 ++ )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
}
static void F_123 ( struct V_12 * V_13 )
{
if ( F_124 ( V_13 ) )
return;
F_122 ( V_13 ) ;
}
static unsigned long F_125 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_44 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_126 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long V_109 , const char * V_110 )
{
F_127 ( V_13 -> V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_6 , V_109 , V_2 -> V_111 ,
V_2 -> V_98 , V_2 -> V_97 , V_110 ) ;
}
static bool V_58
F_128 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long * V_112 )
{
unsigned long V_109 ;
int V_47 ;
bool V_70 = false ;
struct V_1 * V_113 = F_44 ( V_13 -> V_5 ) ;
V_109 = F_125 ( V_13 -> V_5 , V_2 ) ;
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_26 ) ) ;
if ( V_2 -> V_46 [ V_109 & 0x1 ] ) {
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_27 ) ) ;
goto V_114;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_113 -> V_7 ) != F_2 ( V_113 -> V_6 ) ) {
V_2 -> V_46 [ V_109 & 0x1 ] ++ ;
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_28 ) ) ;
goto V_114;
}
if ( V_2 != V_113 ) {
F_129 ( & V_113 -> V_95 ) ;
F_130 () ;
}
V_109 = F_125 ( V_13 -> V_5 , V_113 ) ;
for ( V_47 = V_42 ; V_47 < V_48 ; V_47 ++ )
if ( F_47 ( V_109 , V_13 -> V_51 [ V_47 ] ) )
V_13 -> V_51 [ V_47 ] = V_109 ;
if ( V_113 -> V_46 [ V_109 & 0x1 ] ) {
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_29 ) ) ;
goto V_115;
}
V_113 -> V_46 [ V_109 & 0x1 ] ++ ;
if ( V_113 -> V_7 != V_113 -> V_6 ) {
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_30 ) ) ;
} else {
F_126 ( V_2 , V_13 , V_109 , F_7 ( L_31 ) ) ;
V_70 = F_131 ( V_13 -> V_5 , V_113 , V_13 ) ;
}
V_115:
if ( V_2 != V_113 )
F_132 ( & V_113 -> V_95 ) ;
V_114:
if ( V_112 != NULL )
* V_112 = V_109 ;
return V_70 ;
}
static int F_133 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_109 = V_2 -> V_6 ;
int V_116 ;
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
F_134 ( V_5 , V_2 ) ;
V_2 -> V_46 [ V_109 & 0x1 ] = 0 ;
V_116 = V_2 -> V_46 [ ( V_109 + 1 ) & 0x1 ] ;
F_126 ( V_2 , V_13 , V_109 ,
V_116 ? F_7 ( L_32 ) : F_7 ( L_33 ) ) ;
return V_116 ;
}
static void F_135 ( struct V_4 * V_5 )
{
if ( V_56 == V_5 -> V_29 ||
! F_2 ( V_5 -> V_38 ) ||
! V_5 -> V_29 )
return;
F_136 ( & V_5 -> V_117 ) ;
}
static bool F_137 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long V_109 ;
int V_47 ;
bool V_70 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
V_109 = F_125 ( V_5 , V_2 ) ;
for ( V_47 = V_48 - 1 ; V_47 > V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] != V_13 -> V_41 [ V_47 - 1 ] &&
! F_94 ( V_13 -> V_51 [ V_47 ] , V_109 ) )
break;
if ( ++ V_47 >= V_48 )
return false ;
for (; V_47 <= V_48 ; V_47 ++ ) {
V_13 -> V_41 [ V_47 ] = V_13 -> V_41 [ V_48 ] ;
V_13 -> V_51 [ V_47 ] = V_109 ;
}
V_70 = F_128 ( V_2 , V_13 , NULL ) ;
if ( ! * V_13 -> V_41 [ V_50 ] )
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_34 ) ) ;
else
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_35 ) ) ;
return V_70 ;
}
static bool F_138 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_47 , V_88 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
for ( V_47 = V_50 ; V_47 < V_48 ; V_47 ++ ) {
if ( F_47 ( V_2 -> V_6 , V_13 -> V_51 [ V_47 ] ) )
break;
V_13 -> V_41 [ V_42 ] = V_13 -> V_41 [ V_47 ] ;
}
for ( V_88 = V_50 ; V_88 < V_47 ; V_88 ++ )
V_13 -> V_41 [ V_88 ] = V_13 -> V_41 [ V_42 ] ;
for ( V_88 = V_50 ; V_47 < V_48 ; V_47 ++ , V_88 ++ ) {
if ( V_13 -> V_41 [ V_88 ] == V_13 -> V_41 [ V_48 ] )
break;
V_13 -> V_41 [ V_88 ] = V_13 -> V_41 [ V_47 ] ;
V_13 -> V_51 [ V_88 ] = V_13 -> V_51 [ V_47 ] ;
}
return F_137 ( V_5 , V_2 , V_13 ) ;
}
static bool F_139 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
bool V_70 ;
if ( V_13 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_70 = F_137 ( V_5 , V_2 , V_13 ) ;
} else {
V_70 = F_138 ( V_5 , V_2 , V_13 ) ;
V_13 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_36 ) ) ;
}
if ( V_13 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_13 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_37 ) ) ;
V_13 -> V_9 = 0 ;
V_13 -> V_118 = F_5 ( V_23 ) ;
V_13 -> V_119 = ! ! ( V_2 -> V_96 & V_13 -> V_71 ) ;
F_140 ( V_13 ) ;
F_91 ( V_13 -> V_78 , false ) ;
}
return V_70 ;
}
static void F_141 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
bool V_120 ;
struct V_1 * V_2 ;
F_11 ( V_11 ) ;
V_2 = V_13 -> V_20 ;
if ( ( V_13 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_13 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_13 -> V_78 ) ) ) ||
! F_142 ( & V_2 -> V_95 ) ) {
F_21 ( V_11 ) ;
return;
}
F_130 () ;
V_120 = F_139 ( V_5 , V_2 , V_13 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
if ( V_120 )
F_135 ( V_5 ) ;
}
static void F_143 ( struct V_4 * V_5 , int V_121 )
{
if ( V_121 > 0 &&
! ( V_5 -> V_7 % ( V_122 * V_123 * V_121 ) ) )
F_144 ( V_121 ) ;
}
static int F_145 ( struct V_4 * V_5 )
{
unsigned long V_124 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_91 ( V_5 -> V_93 , V_84 ) ;
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
if ( ! F_2 ( V_5 -> V_38 ) ) {
F_147 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_91 ( V_5 -> V_38 , 0 ) ;
if ( F_59 ( F_3 ( V_5 ) ) ) {
F_147 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_98 ( V_5 ) ;
F_148 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_27 , V_5 -> V_7 , F_7 ( L_38 ) ) ;
F_147 ( & V_2 -> V_95 ) ;
F_104 (rsp, rnp) {
F_143 ( V_5 , V_125 ) ;
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
if ( V_2 -> V_126 == V_2 -> V_3 &&
! V_2 -> V_127 ) {
F_147 ( & V_2 -> V_95 ) ;
continue;
}
V_124 = V_2 -> V_126 ;
V_2 -> V_126 = V_2 -> V_3 ;
if ( ! V_124 != ! V_2 -> V_126 ) {
if ( ! V_124 )
F_149 ( V_2 ) ;
else if ( F_150 ( V_2 ) )
V_2 -> V_127 = true ;
else
F_151 ( V_2 ) ;
}
if ( V_2 -> V_127 &&
( ! F_150 ( V_2 ) ||
V_2 -> V_126 ) ) {
V_2 -> V_127 = false ;
F_151 ( V_2 ) ;
}
F_147 ( & V_2 -> V_95 ) ;
}
F_152 (rsp, rnp) {
F_143 ( V_5 , V_128 ) ;
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
V_13 = F_17 ( V_5 -> V_18 ) ;
F_153 ( V_2 ) ;
V_2 -> V_96 = V_2 -> V_126 ;
F_91 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_59 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_91 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_13 -> V_20 )
( void ) F_139 ( V_5 , V_2 , V_13 ) ;
F_154 ( V_2 ) ;
F_155 ( V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_111 , V_2 -> V_98 ,
V_2 -> V_97 , V_2 -> V_96 ) ;
F_147 ( & V_2 -> V_95 ) ;
F_156 () ;
F_91 ( V_5 -> V_93 , V_84 ) ;
}
return 1 ;
}
static int F_157 ( struct V_4 * V_5 , int V_129 )
{
int V_130 = V_129 ;
bool V_73 = false ;
unsigned long V_74 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_91 ( V_5 -> V_93 , V_84 ) ;
V_5 -> V_91 ++ ;
if ( V_130 == V_131 ) {
if ( F_158 ( V_5 ) ) {
V_73 = true ;
V_74 = V_84 - V_77 / 4 ;
}
F_159 ( V_5 , F_87 ,
& V_73 , & V_74 ) ;
F_160 ( V_5 , V_73 , V_74 ) ;
V_130 = V_132 ;
} else {
V_73 = true ;
F_159 ( V_5 , F_92 , & V_73 , & V_74 ) ;
}
if ( F_2 ( V_5 -> V_38 ) & V_133 ) {
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
F_91 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_38 ) & ~ V_133 ) ;
F_147 ( & V_2 -> V_95 ) ;
}
return V_130 ;
}
static void F_161 ( struct V_4 * V_5 )
{
unsigned long V_134 ;
bool V_135 = false ;
int V_136 = 0 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_91 ( V_5 -> V_93 , V_84 ) ;
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
V_134 = V_84 - V_5 -> V_83 ;
if ( V_134 > V_5 -> V_137 )
V_5 -> V_137 = V_134 ;
F_147 ( & V_2 -> V_95 ) ;
F_152 (rsp, rnp) {
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
F_59 ( F_162 ( V_2 ) ) ;
F_59 ( V_2 -> V_96 ) ;
F_91 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( V_2 == V_13 -> V_20 )
V_135 = F_139 ( V_5 , V_2 , V_13 ) || V_135 ;
V_136 += F_133 ( V_5 , V_2 ) ;
F_147 ( & V_2 -> V_95 ) ;
F_156 () ;
F_91 ( V_5 -> V_93 , V_84 ) ;
F_143 ( V_5 , V_138 ) ;
}
V_2 = F_44 ( V_5 ) ;
F_146 ( & V_2 -> V_95 ) ;
F_130 () ;
F_163 ( V_2 , V_136 ) ;
F_91 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_27 , V_5 -> V_6 , F_7 ( L_39 ) ) ;
V_5 -> V_130 = V_139 ;
V_13 = F_17 ( V_5 -> V_18 ) ;
V_135 = F_138 ( V_5 , V_2 , V_13 ) || V_135 ;
if ( V_135 || F_46 ( V_5 , V_13 ) ) {
F_91 ( V_5 -> V_38 , V_140 ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
}
F_147 ( & V_2 -> V_95 ) ;
}
static int T_3 F_164 ( void * V_141 )
{
int V_130 ;
int V_142 ;
unsigned long V_88 ;
int V_70 ;
struct V_4 * V_5 = V_141 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_165 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_41 ) ) ;
V_5 -> V_28 = V_143 ;
F_166 ( V_5 -> V_117 ,
F_2 ( V_5 -> V_38 ) &
V_140 ) ;
if ( F_145 ( V_5 ) )
break;
F_156 () ;
F_91 ( V_5 -> V_93 , V_84 ) ;
F_167 ( F_168 ( V_56 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_42 ) ) ;
}
V_130 = V_131 ;
V_88 = V_144 ;
if ( V_88 > V_94 ) {
V_88 = V_94 ;
V_144 = V_94 ;
}
V_70 = 0 ;
for (; ; ) {
if ( ! V_70 )
V_5 -> V_145 = V_84 + V_88 ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
V_5 -> V_28 = V_146 ;
V_70 = F_169 ( V_5 -> V_117 ,
( ( V_142 = F_2 ( V_5 -> V_38 ) ) &
V_133 ) ||
( ! F_2 ( V_2 -> V_96 ) &&
! F_162 ( V_2 ) ) ,
V_88 ) ;
if ( ! F_2 ( V_2 -> V_96 ) &&
! F_162 ( V_2 ) )
break;
if ( F_94 ( V_84 , V_5 -> V_145 ) ||
( V_142 & V_133 ) ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
V_130 = F_157 ( V_5 , V_130 ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
F_156 () ;
F_91 ( V_5 -> V_93 , V_84 ) ;
} else {
F_156 () ;
F_91 ( V_5 -> V_93 , V_84 ) ;
F_167 ( F_168 ( V_56 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
V_88 = V_104 ;
if ( V_88 > V_94 ) {
V_88 = V_94 ;
V_104 = V_94 ;
} else if ( V_88 < 1 ) {
V_88 = 1 ;
V_104 = 1 ;
}
}
F_161 ( V_5 ) ;
}
}
static bool
F_131 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( ! V_5 -> V_29 || ! F_46 ( V_5 , V_13 ) ) {
return false ;
}
F_91 ( V_5 -> V_38 , V_140 ) ;
F_6 ( V_5 -> V_27 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
return true ;
}
static bool F_170 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
bool V_70 = false ;
V_70 = F_138 ( V_5 , V_2 , V_13 ) || V_70 ;
V_70 = F_131 ( V_5 , V_2 , V_13 ) || V_70 ;
return V_70 ;
}
static void F_171 ( struct V_4 * V_5 , unsigned long V_11 )
__releases( rcu_get_root( V_5 )->lock
static void
F_172 ( unsigned long V_147 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_105 , unsigned long V_11 )
__releases( V_2 -> V_95 )
{
unsigned long V_124 = 0 ;
struct V_1 * V_148 ;
for (; ; ) {
if ( ! ( V_2 -> V_96 & V_147 ) || V_2 -> V_7 != V_105 ) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
return;
}
F_59 ( V_124 ) ;
V_2 -> V_96 &= ~ V_147 ;
F_173 ( V_5 -> V_27 , V_2 -> V_7 ,
V_147 , V_2 -> V_96 , V_2 -> V_111 ,
V_2 -> V_98 , V_2 -> V_97 ,
! ! V_2 -> V_149 ) ;
if ( V_2 -> V_96 != 0 || F_162 ( V_2 ) ) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_147 = V_2 -> V_71 ;
if ( V_2 -> V_150 == NULL ) {
break;
}
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_148 = V_2 ;
V_2 = V_2 -> V_150 ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
F_130 () ;
V_124 = V_148 -> V_96 ;
}
F_171 ( V_5 , V_11 ) ;
}
static void F_174 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_11 )
__releases( V_2 -> V_95 )
{
unsigned long V_105 ;
unsigned long V_147 ;
struct V_1 * V_151 ;
if ( V_24 == & V_25 || V_5 != V_24 ||
V_2 -> V_96 != 0 || F_162 ( V_2 ) ) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_151 = V_2 -> V_150 ;
if ( V_151 == NULL ) {
F_171 ( V_5 , V_11 ) ;
return;
}
V_105 = V_2 -> V_7 ;
V_147 = V_2 -> V_71 ;
F_132 ( & V_2 -> V_95 ) ;
F_129 ( & V_151 -> V_95 ) ;
F_130 () ;
F_172 ( V_147 , V_5 , V_151 , V_105 , V_11 ) ;
}
static void
F_175 ( int V_76 , struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
unsigned long V_147 ;
bool V_120 ;
struct V_1 * V_2 ;
V_2 = V_13 -> V_20 ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
F_130 () ;
if ( ( V_13 -> V_9 == 0 &&
V_13 -> V_118 == F_5 ( V_23 ) ) ||
V_13 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_13 -> V_78 ) {
V_13 -> V_9 = 0 ;
V_13 -> V_118 = F_5 ( V_23 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_147 = V_13 -> V_71 ;
if ( ( V_2 -> V_96 & V_147 ) == 0 ) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
} else {
V_13 -> V_119 = 0 ;
V_120 = F_137 ( V_5 , V_2 , V_13 ) ;
F_172 ( V_147 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
if ( V_120 )
F_135 ( V_5 ) ;
}
}
static void
F_176 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
F_141 ( V_5 , V_13 ) ;
if ( ! V_13 -> V_119 )
return;
if ( ! V_13 -> V_9 &&
V_13 -> V_118 == F_5 ( V_23 ) )
return;
F_175 ( V_13 -> V_76 , V_5 , V_13 ) ;
}
static void
F_177 ( int V_76 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! F_50 ( V_152 ) || F_178 ( V_13 -> V_76 ) )
return;
if ( V_13 -> V_40 != NULL ) {
V_5 -> V_153 += V_13 -> V_153 ;
V_5 -> V_103 += V_13 -> V_103 ;
V_13 -> V_154 += V_13 -> V_103 ;
V_13 -> V_153 = 0 ;
F_91 ( V_13 -> V_103 , 0 ) ;
}
if ( * V_13 -> V_41 [ V_42 ] != NULL ) {
* V_5 -> V_155 = * V_13 -> V_41 [ V_42 ] ;
V_5 -> V_155 = V_13 -> V_41 [ V_48 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
}
if ( V_13 -> V_40 != NULL ) {
* V_5 -> V_156 = V_13 -> V_40 ;
V_5 -> V_156 = V_13 -> V_41 [ V_42 ] ;
}
F_123 ( V_13 ) ;
V_13 -> V_41 [ V_48 ] = NULL ;
}
static void F_179 ( struct V_4 * V_5 , unsigned long V_11 )
{
int V_47 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
if ( ! F_50 ( V_152 ) ||
F_180 ( V_5 , V_13 , V_11 ) )
return;
V_13 -> V_153 += V_5 -> V_153 ;
V_13 -> V_103 += V_5 -> V_103 ;
V_13 -> V_157 += V_5 -> V_103 ;
if ( V_5 -> V_153 != V_5 -> V_103 )
F_181 () ;
V_5 -> V_153 = 0 ;
V_5 -> V_103 = 0 ;
if ( V_5 -> V_158 != NULL ) {
* V_5 -> V_156 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = V_5 -> V_158 ;
for ( V_47 = V_108 - 1 ; V_47 >= V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = V_5 -> V_156 ;
V_5 -> V_158 = NULL ;
V_5 -> V_156 = & V_5 -> V_158 ;
}
if ( V_5 -> V_159 != NULL ) {
* V_13 -> V_41 [ V_48 ] = V_5 -> V_159 ;
V_13 -> V_41 [ V_48 ] = V_5 -> V_155 ;
V_5 -> V_159 = NULL ;
V_5 -> V_155 = & V_5 -> V_159 ;
}
}
static void F_182 ( struct V_4 * V_5 )
{
F_183 (unsigned long mask) ;
F_183 ( struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ) ;
F_183 ( struct V_1 * V_2 = V_13 -> V_20 ) ;
if ( ! F_50 ( V_152 ) )
return;
F_183 ( V_147 = V_13 -> V_71 ) ;
F_6 ( V_5 -> V_27 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_96 & V_147 ) ,
F_7 ( L_47 ) ) ;
}
static void F_151 ( struct V_1 * V_160 )
{
long V_147 ;
struct V_1 * V_2 = V_160 ;
if ( ! F_50 ( V_152 ) ||
V_2 -> V_126 || F_150 ( V_2 ) )
return;
for (; ; ) {
V_147 = V_2 -> V_71 ;
V_2 = V_2 -> V_150 ;
if ( ! V_2 )
break;
F_129 ( & V_2 -> V_95 ) ;
F_130 () ;
V_2 -> V_126 &= ~ V_147 ;
V_2 -> V_96 &= ~ V_147 ;
if ( V_2 -> V_126 ) {
F_132 ( & V_2 -> V_95 ) ;
return;
}
F_132 ( & V_2 -> V_95 ) ;
}
}
static void F_184 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_147 ;
struct V_12 * V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
if ( ! F_50 ( V_152 ) )
return;
V_147 = V_13 -> V_71 ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
F_130 () ;
V_2 -> V_3 &= ~ V_147 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
static void F_185 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
struct V_12 * V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
if ( ! F_50 ( V_152 ) )
return;
F_186 ( V_2 , - 1 ) ;
F_105 ( & V_5 -> V_161 , V_11 ) ;
F_177 ( V_76 , V_5 , V_2 , V_13 ) ;
F_179 ( V_5 , V_11 ) ;
F_107 ( & V_5 -> V_161 , V_11 ) ;
F_55 ( V_13 -> V_103 != 0 || V_13 -> V_40 != NULL ,
L_48 ,
V_76 , V_13 -> V_103 , V_13 -> V_40 ) ;
}
static void F_187 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
struct V_162 * V_163 , * V_164 , * * V_165 ;
long V_166 , V_167 , V_168 ;
int V_47 ;
if ( ! F_43 ( V_13 ) ) {
F_188 ( V_5 -> V_27 , V_13 -> V_153 , V_13 -> V_103 , 0 ) ;
F_189 ( V_5 -> V_27 , 0 , ! ! F_2 ( V_13 -> V_40 ) ,
F_190 () , F_51 ( V_56 ) ,
F_191 () ) ;
return;
}
F_11 ( V_11 ) ;
F_59 ( F_95 ( F_53 () ) ) ;
V_166 = V_13 -> V_169 ;
F_188 ( V_5 -> V_27 , V_13 -> V_153 , V_13 -> V_103 , V_166 ) ;
V_164 = V_13 -> V_40 ;
V_13 -> V_40 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
V_165 = V_13 -> V_41 [ V_42 ] ;
for ( V_47 = V_108 - 1 ; V_47 >= 0 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
F_21 ( V_11 ) ;
V_167 = V_168 = 0 ;
while ( V_164 ) {
V_163 = V_164 -> V_163 ;
F_192 ( V_163 ) ;
F_193 ( V_164 ) ;
if ( F_194 ( V_5 -> V_27 , V_164 ) )
V_168 ++ ;
V_164 = V_163 ;
if ( ++ V_167 >= V_166 &&
( F_190 () ||
( ! F_51 ( V_56 ) && ! F_191 () ) ) )
break;
}
F_11 ( V_11 ) ;
F_189 ( V_5 -> V_27 , V_167 , ! ! V_164 , F_190 () ,
F_51 ( V_56 ) ,
F_191 () ) ;
if ( V_164 != NULL ) {
* V_165 = V_13 -> V_40 ;
V_13 -> V_40 = V_164 ;
for ( V_47 = 0 ; V_47 < V_108 ; V_47 ++ )
if ( & V_13 -> V_40 == V_13 -> V_41 [ V_47 ] )
V_13 -> V_41 [ V_47 ] = V_165 ;
else
break;
}
F_16 () ;
V_13 -> V_153 -= V_168 ;
F_91 ( V_13 -> V_103 , V_13 -> V_103 - V_167 ) ;
V_13 -> V_170 += V_167 ;
if ( V_13 -> V_169 == V_171 && V_13 -> V_103 <= V_172 )
V_13 -> V_169 = V_169 ;
if ( V_13 -> V_103 == 0 && V_13 -> V_173 != 0 ) {
V_13 -> V_173 = 0 ;
V_13 -> V_174 = V_5 -> V_91 ;
} else if ( V_13 -> V_103 < V_13 -> V_173 - V_175 )
V_13 -> V_173 = V_13 -> V_103 ;
F_59 ( ( V_13 -> V_40 == NULL ) != ( V_13 -> V_103 == 0 ) ) ;
F_21 ( V_11 ) ;
if ( F_43 ( V_13 ) )
F_195 () ;
}
void F_196 ( int V_53 )
{
F_23 ( F_7 ( L_49 ) ) ;
F_197 () ;
if ( V_53 || F_86 () ) {
F_4 () ;
F_9 () ;
} else if ( ! F_198 () ) {
F_9 () ;
}
F_199 () ;
if ( F_200 () )
F_195 () ;
if ( V_53 )
F_201 ( V_56 ) ;
F_23 ( F_7 ( L_50 ) ) ;
}
static void F_159 ( struct V_4 * V_5 ,
int (* F_202)( struct V_12 * V_5 , bool * V_73 ,
unsigned long * V_74 ) ,
bool * V_73 , unsigned long * V_74 )
{
unsigned long V_176 ;
int V_76 ;
unsigned long V_11 ;
unsigned long V_147 ;
struct V_1 * V_2 ;
F_104 (rsp, rnp) {
F_156 () ;
V_147 = 0 ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
F_130 () ;
if ( V_2 -> V_96 == 0 ) {
if ( V_24 == & V_25 ||
V_5 != V_24 ||
F_162 ( V_2 ) ) {
F_203 ( V_2 , V_11 ) ;
continue;
}
if ( V_2 -> V_150 &&
( V_2 -> V_150 -> V_96 & V_2 -> V_71 ) ) {
F_174 ( V_5 , V_2 , V_11 ) ;
continue;
}
}
V_76 = V_2 -> V_98 ;
V_176 = 1 ;
for (; V_76 <= V_2 -> V_97 ; V_76 ++ , V_176 <<= 1 ) {
if ( ( V_2 -> V_96 & V_176 ) != 0 ) {
if ( F_202 ( F_114 ( V_5 -> V_18 , V_76 ) , V_73 , V_74 ) )
V_147 |= V_176 ;
}
}
if ( V_147 != 0 ) {
F_172 ( V_147 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
} else {
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
}
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_70 ;
struct V_1 * V_2 ;
struct V_1 * V_177 = NULL ;
V_2 = F_5 ( V_5 -> V_18 -> V_20 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_150 ) {
V_70 = ( F_2 ( V_5 -> V_38 ) & V_133 ) ||
! F_142 ( & V_2 -> V_178 ) ;
if ( V_177 != NULL )
F_132 ( & V_177 -> V_178 ) ;
if ( V_70 ) {
V_5 -> V_179 ++ ;
return;
}
V_177 = V_2 ;
}
F_105 ( & V_177 -> V_95 , V_11 ) ;
F_130 () ;
F_132 ( & V_177 -> V_178 ) ;
if ( F_2 ( V_5 -> V_38 ) & V_133 ) {
V_5 -> V_179 ++ ;
F_107 ( & V_177 -> V_95 , V_11 ) ;
return;
}
F_91 ( V_5 -> V_38 , F_2 ( V_5 -> V_38 ) | V_133 ) ;
F_107 ( & V_177 -> V_95 , V_11 ) ;
F_135 ( V_5 ) ;
}
static void
F_204 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_120 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_59 ( V_13 -> V_180 == 0 ) ;
F_176 ( V_5 , V_13 ) ;
F_11 ( V_11 ) ;
if ( F_46 ( V_5 , V_13 ) ) {
F_129 ( & F_44 ( V_5 ) -> V_95 ) ;
V_120 = F_170 ( V_5 ) ;
F_107 ( & F_44 ( V_5 ) -> V_95 , V_11 ) ;
if ( V_120 )
F_135 ( V_5 ) ;
} else {
F_21 ( V_11 ) ;
}
if ( F_43 ( V_13 ) )
F_205 ( V_5 , V_13 ) ;
F_56 ( V_13 ) ;
}
static void F_206 ( struct V_181 * V_182 )
{
struct V_4 * V_5 ;
if ( F_95 ( F_53 () ) )
return;
F_23 ( F_7 ( L_51 ) ) ;
F_14 (rsp)
F_204 ( V_5 ) ;
F_23 ( F_7 ( L_52 ) ) ;
}
static void F_205 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
if ( F_25 ( ! F_2 ( V_72 ) ) )
return;
if ( F_207 ( ! V_5 -> V_183 ) ) {
F_187 ( V_5 , V_13 ) ;
return;
}
F_208 () ;
}
static void F_195 ( void )
{
if ( F_209 ( F_53 () ) )
F_210 ( V_184 ) ;
}
static void F_211 ( struct V_4 * V_5 , struct V_12 * V_13 ,
struct V_162 * V_185 , unsigned long V_11 )
{
bool V_120 ;
if ( ! F_81 () )
F_195 () ;
if ( F_212 ( V_11 ) || F_95 ( F_53 () ) )
return;
if ( F_25 ( V_13 -> V_103 > V_13 -> V_173 + V_175 ) ) {
F_141 ( V_5 , V_13 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_113 = F_44 ( V_5 ) ;
F_129 ( & V_113 -> V_95 ) ;
F_130 () ;
V_120 = F_170 ( V_5 ) ;
F_132 ( & V_113 -> V_95 ) ;
if ( V_120 )
F_135 ( V_5 ) ;
} else {
V_13 -> V_169 = V_171 ;
if ( V_5 -> V_91 == V_13 -> V_174 &&
* V_13 -> V_41 [ V_42 ] != V_185 )
F_35 ( V_5 ) ;
V_13 -> V_174 = V_5 -> V_91 ;
V_13 -> V_173 = V_13 -> V_103 ;
}
}
}
static void F_213 ( struct V_162 * V_186 )
{
}
static void
F_214 ( struct V_162 * V_185 , void (* F_215)( struct V_162 * V_187 ) ,
struct V_4 * V_5 , int V_76 , bool V_188 )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
F_59 ( ( unsigned long ) V_185 & 0x1 ) ;
if ( F_216 ( V_185 ) ) {
F_91 ( V_185 -> F_215 , F_213 ) ;
F_55 ( 1 , L_53 ) ;
return;
}
V_185 -> F_215 = F_215 ;
V_185 -> V_163 = NULL ;
F_11 ( V_11 ) ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( F_25 ( V_13 -> V_41 [ V_48 ] == NULL ) || V_76 != - 1 ) {
int V_189 ;
if ( V_76 != - 1 )
V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
if ( F_207 ( V_13 -> V_20 ) ) {
V_189 = ! F_217 ( V_13 , V_185 , V_188 , V_11 ) ;
F_59 ( V_189 ) ;
F_21 ( V_11 ) ;
return;
}
F_218 ( V_76 != - 1 ) ;
F_59 ( ! F_81 () ) ;
if ( ! F_207 ( V_13 -> V_40 ) )
F_122 ( V_13 ) ;
}
F_91 ( V_13 -> V_103 , V_13 -> V_103 + 1 ) ;
if ( V_188 )
V_13 -> V_153 ++ ;
else
F_181 () ;
F_16 () ;
* V_13 -> V_41 [ V_48 ] = V_185 ;
V_13 -> V_41 [ V_48 ] = & V_185 -> V_163 ;
if ( F_219 ( ( unsigned long ) F_215 ) )
F_220 ( V_5 -> V_27 , V_185 , ( unsigned long ) F_215 ,
V_13 -> V_153 , V_13 -> V_103 ) ;
else
F_221 ( V_5 -> V_27 , V_185 , V_13 -> V_153 , V_13 -> V_103 ) ;
F_211 ( V_5 , V_13 , V_185 , V_11 ) ;
F_21 ( V_11 ) ;
}
void F_222 ( struct V_162 * V_185 , void (* F_215)( struct V_162 * V_187 ) )
{
F_214 ( V_185 , F_215 , & V_25 , - 1 , 0 ) ;
}
void F_223 ( struct V_162 * V_185 , void (* F_215)( struct V_162 * V_187 ) )
{
F_214 ( V_185 , F_215 , & V_26 , - 1 , 0 ) ;
}
void F_224 ( struct V_162 * V_185 ,
void (* F_215)( struct V_162 * V_187 ) )
{
F_214 ( V_185 , F_215 , V_24 , - 1 , 1 ) ;
}
static inline int F_225 ( void )
{
int V_70 ;
F_226 () ;
F_82 () ;
V_70 = F_227 () <= 1 ;
F_83 () ;
return V_70 ;
}
void F_228 ( void )
{
F_62 ( ! F_63 ( & V_63 ) &&
! F_63 ( & V_62 ) &&
! F_63 ( & V_64 ) ,
L_54 ) ;
if ( F_225 () )
return;
if ( F_229 () )
F_230 () ;
else
F_231 ( F_222 ) ;
}
void F_232 ( void )
{
F_62 ( ! F_63 ( & V_63 ) &&
! F_63 ( & V_62 ) &&
! F_63 ( & V_64 ) ,
L_55 ) ;
if ( F_225 () )
return;
if ( F_229 () )
F_233 () ;
else
F_231 ( F_223 ) ;
}
unsigned long F_234 ( void )
{
F_16 () ;
return F_235 ( & V_24 -> V_7 ) ;
}
void F_236 ( unsigned long V_190 )
{
unsigned long V_191 ;
V_191 = F_235 ( & V_24 -> V_6 ) ;
if ( F_94 ( V_190 , V_191 ) )
F_237 () ;
}
static int F_238 ( void * V_192 )
{
F_16 () ;
return 0 ;
}
void F_230 ( void )
{
T_4 V_193 ;
bool V_194 = false ;
int V_76 ;
long V_195 , V_110 , V_81 ;
int V_196 = 0 ;
struct V_4 * V_5 = & V_25 ;
if ( F_94 ( ( V_197 ) F_239 ( & V_5 -> V_198 ) ,
( V_197 ) F_239 ( & V_5 -> V_199 ) +
V_77 / 8 ) ) {
F_231 ( F_222 ) ;
F_240 ( & V_5 -> V_200 ) ;
return;
}
V_81 = F_241 ( & V_5 -> V_198 ) ;
V_195 = V_81 ;
if ( ! F_242 () ) {
F_231 ( F_222 ) ;
F_240 ( & V_5 -> V_201 ) ;
return;
}
F_59 ( F_95 ( F_243 () ) ) ;
V_194 = F_244 ( & V_193 , V_202 ) ;
if ( V_194 ) {
F_245 ( V_193 , V_203 ) ;
F_246 ( F_243 () , V_193 ) ;
F_247 (cpu, cm) {
struct V_14 * V_15 = & F_96 ( V_14 , V_76 ) ;
if ( ! ( F_88 ( 0 , & V_15 -> V_22 ) & 0x1 ) )
F_246 ( V_76 , V_193 ) ;
}
if ( F_248 ( V_193 ) == 0 )
goto V_204;
}
while ( F_249 ( V_194 ? V_193 : V_203 ,
F_238 ,
NULL ) == - V_205 ) {
F_250 () ;
F_240 ( & V_5 -> V_206 ) ;
V_110 = F_239 ( & V_5 -> V_199 ) ;
if ( F_94 ( ( V_197 ) V_110 , ( V_197 ) V_195 ) ) {
F_18 () ;
F_240 ( & V_5 -> V_207 ) ;
F_251 ( V_193 ) ;
return;
}
if ( V_196 ++ < 10 ) {
F_252 ( V_196 * F_227 () ) ;
} else {
F_231 ( F_222 ) ;
F_240 ( & V_5 -> V_201 ) ;
F_251 ( V_193 ) ;
return;
}
V_110 = F_239 ( & V_5 -> V_199 ) ;
if ( F_94 ( ( V_197 ) V_110 , ( V_197 ) V_195 ) ) {
F_18 () ;
F_240 ( & V_5 -> V_208 ) ;
F_251 ( V_193 ) ;
return;
}
if ( ! F_242 () ) {
F_231 ( F_222 ) ;
F_240 ( & V_5 -> V_201 ) ;
F_251 ( V_193 ) ;
return;
}
V_81 = F_239 ( & V_5 -> V_198 ) ;
F_16 () ;
}
F_240 ( & V_5 -> V_209 ) ;
V_204:
F_251 ( V_193 ) ;
do {
F_240 ( & V_5 -> V_210 ) ;
V_110 = F_239 ( & V_5 -> V_199 ) ;
if ( F_94 ( ( V_197 ) V_110 , ( V_197 ) V_81 ) ) {
F_18 () ;
F_240 ( & V_5 -> V_211 ) ;
break;
}
} while ( F_253 ( & V_5 -> V_199 , V_110 , V_81 ) != V_110 );
F_240 ( & V_5 -> V_212 ) ;
F_250 () ;
}
static int F_254 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_20 ;
V_13 -> V_213 ++ ;
F_119 ( V_5 , V_13 ) ;
if ( F_255 ( V_5 ) )
return 0 ;
if ( V_72 &&
V_13 -> V_119 && ! V_13 -> V_9 &&
V_13 -> V_118 == F_5 ( V_23 ) ) {
V_13 -> V_214 ++ ;
} else if ( V_13 -> V_119 &&
( V_13 -> V_9 ||
V_13 -> V_118 != F_5 ( V_23 ) ) ) {
V_13 -> V_215 ++ ;
return 1 ;
}
if ( F_43 ( V_13 ) ) {
V_13 -> V_216 ++ ;
return 1 ;
}
if ( F_46 ( V_5 , V_13 ) ) {
V_13 -> V_217 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_13 -> V_6 ) {
V_13 -> V_218 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_13 -> V_7 ||
F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_13 -> V_219 ++ ;
return 1 ;
}
if ( F_256 ( V_13 ) ) {
V_13 -> V_220 ++ ;
return 1 ;
}
V_13 -> V_221 ++ ;
return 0 ;
}
static int F_200 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
if ( F_254 ( V_5 , F_17 ( V_5 -> V_18 ) ) )
return 1 ;
return 0 ;
}
static bool V_58 F_257 ( bool * V_222 )
{
bool V_223 = true ;
bool V_224 = false ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( ! V_13 -> V_40 )
continue;
V_224 = true ;
if ( V_13 -> V_103 != V_13 -> V_153 || ! V_222 ) {
V_223 = false ;
break;
}
}
if ( V_222 )
* V_222 = V_223 ;
return V_224 ;
}
static void F_258 ( struct V_4 * V_5 , const char * V_110 ,
int V_76 , unsigned long V_225 )
{
F_259 ( V_5 -> V_27 , V_110 , V_76 ,
F_60 ( & V_5 -> V_226 ) , V_225 ) ;
}
static void F_260 ( struct V_162 * V_186 )
{
struct V_12 * V_13 = F_261 ( V_186 , struct V_12 , V_227 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
if ( F_262 ( & V_5 -> V_226 ) ) {
F_258 ( V_5 , L_56 , - 1 , V_5 -> V_228 ) ;
F_263 ( & V_5 -> V_229 ) ;
} else {
F_258 ( V_5 , L_57 , - 1 , V_5 -> V_228 ) ;
}
}
static void F_264 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_258 ( V_5 , L_58 , - 1 , V_5 -> V_228 ) ;
F_58 ( & V_5 -> V_226 ) ;
V_5 -> V_230 ( & V_13 -> V_227 , F_260 ) ;
}
static void F_265 ( struct V_4 * V_5 )
{
int V_76 ;
struct V_12 * V_13 ;
unsigned long V_81 = F_2 ( V_5 -> V_228 ) ;
unsigned long V_231 ;
F_258 ( V_5 , L_59 , - 1 , V_81 ) ;
F_266 ( & V_5 -> V_232 ) ;
F_16 () ;
V_231 = V_5 -> V_228 ;
F_258 ( V_5 , L_60 , - 1 , V_231 ) ;
if ( F_94 ( V_231 , ( V_81 + 3 ) & ~ 0x1 ) ) {
F_258 ( V_5 , L_61 , - 1 , V_231 ) ;
F_16 () ;
F_267 ( & V_5 -> V_232 ) ;
return;
}
F_91 ( V_5 -> V_228 , V_5 -> V_228 + 1 ) ;
F_59 ( ( V_5 -> V_228 & 0x1 ) != 1 ) ;
F_258 ( V_5 , L_62 , - 1 , V_5 -> V_228 ) ;
F_16 () ;
F_268 ( & V_5 -> V_229 ) ;
F_269 ( & V_5 -> V_226 , 1 ) ;
F_270 () ;
F_113 (cpu) {
if ( ! F_209 ( V_76 ) && ! F_178 ( V_76 ) )
continue;
V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
if ( F_178 ( V_76 ) ) {
if ( ! F_271 ( V_5 , V_76 ) ) {
F_258 ( V_5 , L_63 , V_76 ,
V_5 -> V_228 ) ;
} else {
F_258 ( V_5 , L_64 , V_76 ,
V_5 -> V_228 ) ;
F_18 () ;
F_58 ( & V_5 -> V_226 ) ;
F_214 ( & V_13 -> V_227 ,
F_260 , V_5 , V_76 , 0 ) ;
}
} else if ( F_2 ( V_13 -> V_103 ) ) {
F_258 ( V_5 , L_65 , V_76 ,
V_5 -> V_228 ) ;
F_272 ( V_76 , F_264 , V_5 , 1 ) ;
} else {
F_258 ( V_5 , L_66 , V_76 ,
V_5 -> V_228 ) ;
}
}
F_250 () ;
if ( F_262 ( & V_5 -> V_226 ) )
F_263 ( & V_5 -> V_229 ) ;
F_16 () ;
F_91 ( V_5 -> V_228 , V_5 -> V_228 + 1 ) ;
F_59 ( ( V_5 -> V_228 & 0x1 ) != 0 ) ;
F_258 ( V_5 , L_67 , - 1 , V_5 -> V_228 ) ;
F_16 () ;
F_273 ( & V_5 -> V_229 ) ;
F_267 ( & V_5 -> V_232 ) ;
}
void F_274 ( void )
{
F_265 ( & V_26 ) ;
}
void F_275 ( void )
{
F_265 ( & V_25 ) ;
}
static void F_149 ( struct V_1 * V_160 )
{
long V_147 ;
struct V_1 * V_2 = V_160 ;
for (; ; ) {
V_147 = V_2 -> V_71 ;
V_2 = V_2 -> V_150 ;
if ( V_2 == NULL )
return;
F_129 ( & V_2 -> V_95 ) ;
V_2 -> V_126 |= V_147 ;
F_132 ( & V_2 -> V_95 ) ;
}
}
static void T_5
F_276 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
struct V_12 * V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
V_13 -> V_71 = 1UL << ( V_76 - V_13 -> V_20 -> V_98 ) ;
V_13 -> V_22 = & F_96 ( V_14 , V_76 ) ;
F_59 ( V_13 -> V_22 -> V_54 != V_67 ) ;
F_59 ( F_60 ( & V_13 -> V_22 -> V_22 ) != 1 ) ;
V_13 -> V_76 = V_76 ;
V_13 -> V_5 = V_5 ;
F_277 ( V_13 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
static void
F_278 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_147 ;
struct V_12 * V_13 = F_114 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
V_13 -> V_180 = 1 ;
V_13 -> V_173 = 0 ;
V_13 -> V_174 = V_5 -> V_91 ;
V_13 -> V_169 = V_169 ;
if ( ! V_13 -> V_40 )
F_123 ( V_13 ) ;
V_13 -> V_22 -> V_54 = V_67 ;
F_279 ( V_13 -> V_22 ) ;
F_269 ( & V_13 -> V_22 -> V_22 ,
( F_60 ( & V_13 -> V_22 -> V_22 ) & ~ 0x1 ) + 1 ) ;
F_132 ( & V_2 -> V_95 ) ;
V_2 = V_13 -> V_20 ;
V_147 = V_13 -> V_71 ;
F_129 ( & V_2 -> V_95 ) ;
F_130 () ;
V_2 -> V_3 |= V_147 ;
V_13 -> V_7 = V_2 -> V_6 ;
V_13 -> V_6 = V_2 -> V_6 ;
V_13 -> V_9 = false ;
V_13 -> V_118 = F_96 ( V_23 , V_76 ) ;
V_13 -> V_119 = false ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_68 ) ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
static void F_280 ( int V_76 )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_278 ( V_76 , V_5 ) ;
}
int F_281 ( struct V_233 * V_234 ,
unsigned long V_235 , void * V_236 )
{
long V_76 = ( long ) V_236 ;
struct V_12 * V_13 = F_114 ( V_24 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
struct V_4 * V_5 ;
switch ( V_235 ) {
case V_237 :
case V_238 :
F_280 ( V_76 ) ;
F_282 ( V_76 ) ;
F_283 ( V_76 ) ;
break;
case V_239 :
case V_240 :
F_186 ( V_2 , - 1 ) ;
break;
case V_241 :
F_186 ( V_2 , V_76 ) ;
break;
case V_242 :
case V_243 :
F_14 (rsp)
F_182 ( V_5 ) ;
break;
case V_244 :
F_14 (rsp) {
F_184 ( V_76 , V_5 ) ;
}
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
F_14 (rsp) {
F_185 ( V_76 , V_5 ) ;
F_56 ( F_114 ( V_5 -> V_18 , V_76 ) ) ;
}
break;
default:
break;
}
return V_249 ;
}
static int F_284 ( struct V_233 * V_234 ,
unsigned long V_235 , void * V_236 )
{
switch ( V_235 ) {
case V_250 :
case V_251 :
if ( V_252 <= 256 )
F_285 () ;
break;
case V_253 :
case V_254 :
if ( V_252 <= 256 )
F_286 () ;
break;
default:
break;
}
return V_249 ;
}
static int T_5 F_287 ( void )
{
unsigned long V_11 ;
int V_255 = V_256 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_257 V_258 ;
struct V_57 * V_259 ;
if ( F_50 ( V_260 ) && V_256 < 1 )
V_256 = 1 ;
else if ( V_256 < 0 )
V_256 = 0 ;
else if ( V_256 > 99 )
V_256 = 99 ;
if ( V_256 != V_255 )
F_288 ( L_69 ,
V_256 , V_255 ) ;
V_72 = 1 ;
F_14 (rsp) {
V_259 = F_289 ( F_164 , V_5 , L_70 , V_5 -> V_27 ) ;
F_218 ( F_290 ( V_259 ) ) ;
V_2 = F_44 ( V_5 ) ;
F_105 ( & V_2 -> V_95 , V_11 ) ;
V_5 -> V_29 = V_259 ;
if ( V_256 ) {
V_258 . V_261 = V_256 ;
F_291 ( V_259 , V_262 , & V_258 ) ;
}
F_292 ( V_259 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
}
F_293 () ;
F_294 () ;
return 0 ;
}
void F_295 ( void )
{
F_167 ( F_227 () != 1 ) ;
F_167 ( F_296 () > 0 ) ;
V_263 = 1 ;
}
static void T_5 F_297 ( struct V_4 * V_5 )
{
int V_47 ;
if ( V_264 ) {
V_5 -> V_265 [ V_266 - 1 ] = V_267 ;
for ( V_47 = V_266 - 2 ; V_47 >= 0 ; V_47 -- )
V_5 -> V_265 [ V_47 ] = V_268 ;
} else {
int V_269 ;
int V_270 ;
V_270 = V_252 ;
for ( V_47 = V_266 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_269 = V_5 -> V_271 [ V_47 ] ;
V_5 -> V_265 [ V_47 ] = ( V_270 + V_269 - 1 ) / V_269 ;
V_270 = V_269 ;
}
}
}
static void T_5 F_298 ( struct V_4 * V_5 ,
struct V_12 T_6 * V_18 )
{
static const char * const V_272 [] = {
L_71 ,
L_72 ,
L_73 ,
L_74 } ;
static const char * const V_273 [] = {
L_75 ,
L_76 ,
L_77 ,
L_78 } ;
static T_7 V_274 = 0x1 ;
int V_275 = 1 ;
int V_47 ;
int V_88 ;
struct V_1 * V_2 ;
F_299 ( V_276 > F_300 ( V_272 ) ) ;
if ( V_266 <= 0 || V_266 > V_277 )
F_301 ( L_79 ) ;
for ( V_47 = 0 ; V_47 < V_266 ; V_47 ++ )
V_5 -> V_271 [ V_47 ] = V_278 [ V_47 ] ;
for ( V_47 = 1 ; V_47 < V_266 ; V_47 ++ )
V_5 -> V_111 [ V_47 ] = V_5 -> V_111 [ V_47 - 1 ] + V_5 -> V_271 [ V_47 - 1 ] ;
F_297 ( V_5 ) ;
V_5 -> V_19 = V_274 ;
V_274 <<= 1 ;
for ( V_47 = V_266 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_275 *= V_5 -> V_265 [ V_47 ] ;
V_2 = V_5 -> V_111 [ V_47 ] ;
for ( V_88 = 0 ; V_88 < V_5 -> V_271 [ V_47 ] ; V_88 ++ , V_2 ++ ) {
F_302 ( & V_2 -> V_95 ) ;
F_303 ( & V_2 -> V_95 ,
& V_279 [ V_47 ] , V_272 [ V_47 ] ) ;
F_302 ( & V_2 -> V_178 ) ;
F_303 ( & V_2 -> V_178 ,
& V_280 [ V_47 ] , V_273 [ V_47 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_96 = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_98 = V_88 * V_275 ;
V_2 -> V_97 = ( V_88 + 1 ) * V_275 - 1 ;
if ( V_2 -> V_97 >= V_252 )
V_2 -> V_97 = V_252 - 1 ;
if ( V_47 == 0 ) {
V_2 -> V_281 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_150 = NULL ;
} else {
V_2 -> V_281 = V_88 % V_5 -> V_265 [ V_47 - 1 ] ;
V_2 -> V_71 = 1UL << V_2 -> V_281 ;
V_2 -> V_150 = V_5 -> V_111 [ V_47 - 1 ] +
V_88 / V_5 -> V_265 [ V_47 - 1 ] ;
}
V_2 -> V_111 = V_47 ;
F_304 ( & V_2 -> V_282 ) ;
F_305 ( V_2 ) ;
}
}
F_306 ( & V_5 -> V_117 ) ;
V_2 = V_5 -> V_111 [ V_266 - 1 ] ;
F_113 (i) {
while ( V_47 > V_2 -> V_97 )
V_2 ++ ;
F_114 ( V_5 -> V_18 , V_47 ) -> V_20 = V_2 ;
F_276 ( V_47 , V_5 ) ;
}
F_307 ( & V_5 -> V_283 , & V_284 ) ;
}
static void T_5 F_308 ( void )
{
V_197 V_285 ;
int V_47 ;
int V_88 ;
int V_286 = V_252 ;
int V_287 [ V_276 + 1 ] ;
V_285 = V_288 + V_252 / V_289 ;
if ( V_144 == V_77 )
V_144 = V_285 ;
if ( V_104 == V_77 )
V_104 = V_285 ;
if ( V_267 == V_290 &&
V_252 == V_291 )
return;
F_39 ( L_80 ,
V_267 , V_252 ) ;
V_287 [ 0 ] = 1 ;
V_287 [ 1 ] = V_267 ;
for ( V_47 = 2 ; V_47 <= V_276 ; V_47 ++ )
V_287 [ V_47 ] = V_287 [ V_47 - 1 ] * V_268 ;
if ( V_267 < V_290 ||
V_267 > sizeof( unsigned long ) * 8 ||
V_286 > V_287 [ V_276 ] ) {
F_167 ( 1 ) ;
return;
}
for ( V_47 = 1 ; V_47 <= V_276 ; V_47 ++ )
if ( V_286 <= V_287 [ V_47 ] ) {
for ( V_88 = 0 ; V_88 <= V_47 ; V_88 ++ )
V_278 [ V_88 ] =
F_309 ( V_286 , V_287 [ V_47 - V_88 ] ) ;
V_266 = V_47 ;
for ( V_88 = V_47 + 1 ; V_88 <= V_276 ; V_88 ++ )
V_278 [ V_88 ] = 0 ;
break;
}
V_122 = 0 ;
for ( V_47 = 0 ; V_47 <= V_276 ; V_47 ++ )
V_122 += V_278 [ V_47 ] ;
V_122 -= V_286 ;
}
static void T_5 F_310 ( struct V_4 * V_5 )
{
int V_111 = 0 ;
struct V_1 * V_2 ;
F_39 ( L_81 ) ;
F_39 ( L_82 ) ;
F_152 (rsp, rnp) {
if ( V_2 -> V_111 != V_111 ) {
F_115 ( L_83 ) ;
F_39 ( L_82 ) ;
V_111 = V_2 -> V_111 ;
}
F_115 ( L_84 , V_2 -> V_98 , V_2 -> V_97 , V_2 -> V_281 ) ;
}
F_115 ( L_83 ) ;
}
void T_5 F_311 ( void )
{
int V_76 ;
F_312 () ;
F_313 () ;
F_308 () ;
F_298 ( & V_26 , & V_10 ) ;
F_298 ( & V_25 , & V_8 ) ;
if ( V_292 )
F_310 ( & V_25 ) ;
F_314 () ;
F_315 ( V_184 , F_206 ) ;
F_316 ( F_281 , 0 ) ;
F_317 ( F_284 , 0 ) ;
F_318 (cpu)
F_281 ( NULL , V_237 , ( void * ) ( long ) V_76 ) ;
}
