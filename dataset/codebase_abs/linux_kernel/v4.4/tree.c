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
unsigned long V_8 ;
if ( F_5 ( V_9 . V_10 . V_11 ) ) {
F_6 ( F_7 ( L_1 ) ,
F_5 ( V_9 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_9 . V_10 . V_12 . V_13 , false ) ;
if ( ! F_5 ( V_9 . V_10 . V_12 . exp ) )
return;
F_9 ( V_8 ) ;
if ( F_5 ( V_9 . V_10 . V_12 . exp ) ) {
F_8 ( V_9 . V_10 . V_12 . exp , false ) ;
F_10 ( & V_14 ,
F_11 ( & V_9 ) ,
true ) ;
}
F_12 ( V_8 ) ;
}
}
void F_13 ( void )
{
if ( F_5 ( V_15 . V_10 . V_11 ) ) {
F_6 ( F_7 ( L_3 ) ,
F_5 ( V_15 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_15 . V_10 . V_12 . V_13 , false ) ;
}
}
static void F_14 ( void )
{
unsigned long V_8 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
struct V_4 * V_5 ;
F_9 ( V_8 ) ;
V_20 = F_15 ( V_21 ) ;
F_16 ( V_21 , 0 ) ;
F_17 (rsp) {
V_17 = F_18 ( V_5 -> V_22 ) ;
if ( ! ( V_20 & V_5 -> V_23 ) )
continue;
F_19 () ;
if ( F_2 ( V_17 -> V_24 -> V_6 ) !=
F_2 ( V_17 -> V_25 ) )
continue;
V_19 = F_11 ( & V_18 ) ;
F_20 () ;
F_21 ( 2 , & V_19 -> V_26 ) ;
F_22 () ;
break;
}
F_12 ( V_8 ) ;
}
void F_23 ( void )
{
F_24 () ;
F_25 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_26 () ;
if ( F_27 ( F_15 ( V_21 ) ) )
F_14 () ;
F_25 ( F_7 ( L_5 ) ) ;
F_24 () ;
}
void F_28 ( void )
{
F_24 () ;
if ( F_27 ( F_15 ( V_21 ) ) )
F_14 () ;
F_29 ( V_27 ) ;
F_24 () ;
}
unsigned long F_30 ( void )
{
return V_28 -> V_7 ;
}
unsigned long F_31 ( void )
{
return V_14 . V_7 ;
}
unsigned long F_32 ( void )
{
return V_29 . V_7 ;
}
unsigned long F_33 ( void )
{
return V_28 -> V_6 ;
}
unsigned long F_34 ( void )
{
return V_14 . V_6 ;
}
unsigned long F_35 ( void )
{
return V_29 . V_6 ;
}
void F_36 ( void )
{
F_37 ( V_28 ) ;
}
void F_38 ( void )
{
F_37 ( & V_29 ) ;
}
void F_39 ( void )
{
F_37 ( & V_14 ) ;
}
void F_40 ( void )
{
struct V_4 * V_5 ;
F_17 (rsp) {
F_41 ( L_6 ,
V_5 -> V_30 , V_5 -> V_31 , V_5 -> V_32 -> V_33 ) ;
}
}
void F_42 ( void )
{
V_34 ++ ;
V_35 = 0 ;
}
void F_43 ( enum V_36 V_37 , int * V_8 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_37 ) {
case V_38 :
V_5 = V_28 ;
break;
case V_39 :
V_5 = & V_29 ;
break;
case V_40 :
V_5 = & V_14 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_8 = F_2 ( V_5 -> V_41 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_8 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_44 ( unsigned long V_42 )
{
V_35 ++ ;
}
static int
F_45 ( struct V_16 * V_17 )
{
return & V_17 -> V_43 != V_17 -> V_44 [ V_45 ] &&
V_17 -> V_44 [ V_45 ] != NULL ;
}
static struct V_1 * F_46 ( struct V_4 * V_5 )
{
return & V_5 -> V_46 [ 0 ] ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_46 ( V_5 ) ;
int V_47 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_48 = & V_2 -> V_49 [ V_47 ] ;
return F_2 ( * V_48 ) ;
}
static int
F_48 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
int V_50 ;
if ( F_3 ( V_5 ) )
return 0 ;
if ( F_47 ( V_5 ) )
return 1 ;
if ( ! V_17 -> V_44 [ V_51 ] )
return 0 ;
if ( * V_17 -> V_44 [ V_52 ] )
return 1 ;
for ( V_50 = V_53 ; V_50 < V_51 ; V_50 ++ )
if ( V_17 -> V_44 [ V_50 - 1 ] != V_17 -> V_44 [ V_50 ] &&
F_49 ( F_2 ( V_5 -> V_6 ) ,
V_17 -> V_54 [ V_50 ] ) )
return 1 ;
return 0 ;
}
static void F_50 ( long long V_55 , bool V_56 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = F_11 ( & V_18 ) ;
F_51 ( F_7 ( L_7 ) , V_55 , V_19 -> V_57 ) ;
if ( F_52 ( V_58 ) &&
! V_56 && ! F_53 ( V_59 ) ) {
struct V_60 * T_1 V_61 =
F_54 ( F_55 () ) ;
F_51 ( F_7 ( L_8 ) , V_55 , 0 ) ;
F_56 ( V_62 ) ;
F_57 ( 1 , L_9 ,
V_59 -> V_63 , V_59 -> V_64 ,
T_1 -> V_63 , T_1 -> V_64 ) ;
}
F_17 (rsp) {
V_17 = F_11 ( V_5 -> V_22 ) ;
F_58 ( V_17 ) ;
}
F_59 () ;
F_20 () ;
F_60 ( & V_19 -> V_26 ) ;
F_22 () ;
F_61 ( F_52 ( V_58 ) &&
F_62 ( & V_19 -> V_26 ) & 0x1 ) ;
F_63 () ;
F_64 ( F_65 ( & V_65 ) ,
L_10 ) ;
F_64 ( F_65 ( & V_66 ) ,
L_11 ) ;
F_64 ( F_65 ( & V_67 ) ,
L_12 ) ;
}
static void F_66 ( bool V_56 )
{
long long V_55 ;
struct V_18 * V_19 ;
V_19 = F_11 ( & V_18 ) ;
V_55 = V_19 -> V_57 ;
F_61 ( F_52 ( V_58 ) &&
( V_55 & V_68 ) == 0 ) ;
if ( ( V_55 & V_68 ) == V_69 ) {
V_19 -> V_57 = 0 ;
F_50 ( V_55 , V_56 ) ;
} else {
V_19 -> V_57 -= V_69 ;
}
}
void F_67 ( void )
{
unsigned long V_8 ;
F_9 ( V_8 ) ;
F_66 ( false ) ;
F_68 ( 0 ) ;
F_12 ( V_8 ) ;
}
void F_69 ( void )
{
F_66 ( 1 ) ;
}
void F_70 ( void )
{
unsigned long V_8 ;
long long V_55 ;
struct V_18 * V_19 ;
F_9 ( V_8 ) ;
V_19 = F_11 ( & V_18 ) ;
V_55 = V_19 -> V_57 ;
V_19 -> V_57 -- ;
F_61 ( F_52 ( V_58 ) &&
V_19 -> V_57 < 0 ) ;
if ( V_19 -> V_57 )
F_51 ( F_7 ( L_13 ) , V_55 , V_19 -> V_57 ) ;
else
F_50 ( V_55 , true ) ;
F_68 ( 1 ) ;
F_12 ( V_8 ) ;
}
static void F_71 ( long long V_55 , int V_56 )
{
struct V_18 * V_19 = F_11 ( & V_18 ) ;
F_72 () ;
F_20 () ;
F_60 ( & V_19 -> V_26 ) ;
F_22 () ;
F_61 ( F_52 ( V_58 ) &&
! ( F_62 ( & V_19 -> V_26 ) & 0x1 ) ) ;
F_73 () ;
F_51 ( F_7 ( L_14 ) , V_55 , V_19 -> V_57 ) ;
if ( F_52 ( V_58 ) &&
! V_56 && ! F_53 ( V_59 ) ) {
struct V_60 * T_1 V_61 =
F_54 ( F_55 () ) ;
F_51 ( F_7 ( L_15 ) ,
V_55 , V_19 -> V_57 ) ;
F_56 ( V_62 ) ;
F_57 ( 1 , L_9 ,
V_59 -> V_63 , V_59 -> V_64 ,
T_1 -> V_63 , T_1 -> V_64 ) ;
}
}
static void F_74 ( bool V_56 )
{
struct V_18 * V_19 ;
long long V_55 ;
V_19 = F_11 ( & V_18 ) ;
V_55 = V_19 -> V_57 ;
F_61 ( F_52 ( V_58 ) && V_55 < 0 ) ;
if ( V_55 & V_68 ) {
V_19 -> V_57 += V_69 ;
} else {
V_19 -> V_57 = V_70 ;
F_71 ( V_55 , V_56 ) ;
}
}
void F_75 ( void )
{
unsigned long V_8 ;
F_9 ( V_8 ) ;
F_74 ( false ) ;
F_76 ( 0 ) ;
F_12 ( V_8 ) ;
}
void F_77 ( void )
{
F_74 ( 1 ) ;
}
void F_78 ( void )
{
unsigned long V_8 ;
struct V_18 * V_19 ;
long long V_55 ;
F_9 ( V_8 ) ;
V_19 = F_11 ( & V_18 ) ;
V_55 = V_19 -> V_57 ;
V_19 -> V_57 ++ ;
F_61 ( F_52 ( V_58 ) &&
V_19 -> V_57 == 0 ) ;
if ( V_55 )
F_51 ( F_7 ( L_16 ) , V_55 , V_19 -> V_57 ) ;
else
F_71 ( V_55 , true ) ;
F_76 ( 1 ) ;
F_12 ( V_8 ) ;
}
void F_79 ( void )
{
struct V_18 * V_19 = F_11 ( & V_18 ) ;
int V_71 = 2 ;
F_61 ( V_19 -> V_72 < 0 ) ;
if ( ! ( F_62 ( & V_19 -> V_26 ) & 0x1 ) ) {
F_20 () ;
F_60 ( & V_19 -> V_26 ) ;
F_22 () ;
F_61 ( ! ( F_62 ( & V_19 -> V_26 ) & 0x1 ) ) ;
V_71 = 1 ;
}
V_19 -> V_72 += V_71 ;
F_24 () ;
}
void F_80 ( void )
{
struct V_18 * V_19 = F_11 ( & V_18 ) ;
F_61 ( V_19 -> V_72 <= 0 ) ;
F_61 ( ! ( F_62 ( & V_19 -> V_26 ) & 0x1 ) ) ;
if ( V_19 -> V_72 != 1 ) {
V_19 -> V_72 -= 2 ;
return;
}
V_19 -> V_72 = 0 ;
F_20 () ;
F_60 ( & V_19 -> V_26 ) ;
F_22 () ;
F_61 ( F_62 ( & V_19 -> V_26 ) & 0x1 ) ;
}
bool T_2 F_81 ( void )
{
return F_62 ( F_11 ( & V_18 . V_26 ) ) & 0x1 ;
}
bool T_2 F_82 ( void )
{
bool V_73 ;
F_83 () ;
V_73 = F_81 () ;
F_84 () ;
return V_73 ;
}
bool F_85 ( void )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
bool V_73 ;
if ( F_86 () )
return true ;
F_87 () ;
V_17 = F_11 ( & V_9 ) ;
V_2 = V_17 -> V_24 ;
V_73 = ( V_17 -> V_74 & F_1 ( V_2 ) ) ||
! V_75 ;
F_88 () ;
return V_73 ;
}
static int F_89 ( void )
{
return F_5 ( V_18 . V_57 ) <= 1 ;
}
static int F_90 ( struct V_16 * V_17 ,
bool * V_76 , unsigned long * V_77 )
{
V_17 -> V_78 = F_91 ( 0 , & V_17 -> V_26 -> V_26 ) ;
F_92 ( V_17 , V_76 , V_77 ) ;
if ( ( V_17 -> V_78 & 0x1 ) == 0 ) {
F_93 ( V_17 -> V_5 -> V_30 , V_17 -> V_7 , V_17 -> V_79 , F_7 ( L_17 ) ) ;
return 1 ;
} else {
if ( F_49 ( F_2 ( V_17 -> V_7 ) + V_80 / 4 ,
V_17 -> V_24 -> V_7 ) )
F_94 ( V_17 -> V_81 , true ) ;
return 0 ;
}
}
static int F_95 ( struct V_16 * V_17 ,
bool * V_76 , unsigned long * V_77 )
{
unsigned int V_82 ;
int * V_83 ;
unsigned int V_84 ;
V_82 = ( unsigned int ) F_91 ( 0 , & V_17 -> V_26 -> V_26 ) ;
V_84 = ( unsigned int ) V_17 -> V_78 ;
if ( ( V_82 & 0x1 ) == 0 || F_96 ( V_82 , V_84 + 2 ) ) {
F_93 ( V_17 -> V_5 -> V_30 , V_17 -> V_7 , V_17 -> V_79 , F_7 ( L_17 ) ) ;
V_17 -> V_85 ++ ;
return 1 ;
}
if ( F_97 ( V_17 -> V_5 -> V_86 + 2 , V_87 ) )
return 0 ;
F_24 () ;
if ( F_98 ( V_17 -> V_79 ) ) {
F_93 ( V_17 -> V_5 -> V_30 , V_17 -> V_7 , V_17 -> V_79 , F_7 ( L_18 ) ) ;
V_17 -> V_88 ++ ;
return 1 ;
}
V_83 = & F_99 ( V_21 , V_17 -> V_79 ) ;
if ( F_97 ( V_87 ,
V_17 -> V_5 -> V_86 + V_89 ) ||
F_97 ( V_87 , V_17 -> V_5 -> V_90 ) ) {
if ( ! ( F_2 ( * V_83 ) & V_17 -> V_5 -> V_23 ) ) {
F_94 ( V_17 -> V_25 ,
F_2 ( V_17 -> V_24 -> V_6 ) ) ;
F_19 () ;
F_94 ( * V_83 ,
F_2 ( * V_83 ) + V_17 -> V_5 -> V_23 ) ;
F_100 ( V_17 -> V_79 ) ;
V_17 -> V_5 -> V_90 += 5 ;
} else if ( F_97 ( V_87 , V_17 -> V_5 -> V_90 ) ) {
F_100 ( V_17 -> V_79 ) ;
V_17 -> V_5 -> V_90 += 5 ;
}
}
return 0 ;
}
static void F_101 ( struct V_4 * V_5 )
{
unsigned long V_91 = V_87 ;
unsigned long j1 ;
V_5 -> V_86 = V_91 ;
F_102 () ;
j1 = F_103 () ;
F_94 ( V_5 -> V_92 , V_91 + j1 ) ;
V_5 -> V_90 = V_91 + j1 / 2 ;
V_5 -> V_93 = F_2 ( V_5 -> V_94 ) ;
}
static void F_104 ( struct V_4 * V_5 )
{
unsigned long V_95 ;
unsigned long V_91 ;
V_91 = V_87 ;
V_95 = F_2 ( V_5 -> V_96 ) ;
if ( V_91 - V_95 > 2 * V_97 )
F_105 ( L_19 ,
V_5 -> V_30 , V_91 - V_95 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_41 , V_5 -> V_31 ,
V_5 -> V_32 ? V_5 -> V_32 -> V_33 : 0 ) ;
}
static void F_106 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_8 ;
struct V_1 * V_2 ;
F_107 (rsp, rnp) {
F_108 ( & V_2 -> V_98 , V_8 ) ;
if ( V_2 -> V_99 != 0 ) {
for ( V_79 = 0 ; V_79 <= V_2 -> V_100 - V_2 -> V_101 ; V_79 ++ )
if ( V_2 -> V_99 & ( 1UL << V_79 ) )
F_109 ( V_2 -> V_101 + V_79 ) ;
}
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
}
static void F_111 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_79 ;
long V_102 ;
unsigned long V_8 ;
unsigned long V_95 ;
unsigned long V_91 ;
int V_103 = 0 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
long V_104 = 0 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
V_102 = V_87 - F_2 ( V_5 -> V_92 ) ;
if ( V_102 < V_105 || ! F_3 ( V_5 ) ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
F_94 ( V_5 -> V_92 ,
V_87 + 3 * F_103 () + 3 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
F_105 ( L_20 ,
V_5 -> V_30 ) ;
F_112 () ;
F_107 (rsp, rnp) {
F_108 ( & V_2 -> V_98 , V_8 ) ;
V_103 += F_113 ( V_2 ) ;
if ( V_2 -> V_99 != 0 ) {
for ( V_79 = 0 ; V_79 <= V_2 -> V_100 - V_2 -> V_101 ; V_79 ++ )
if ( V_2 -> V_99 & ( 1UL << V_79 ) ) {
F_114 ( V_5 ,
V_2 -> V_101 + V_79 ) ;
V_103 ++ ;
}
}
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
F_115 () ;
F_116 (cpu)
V_104 += F_117 ( V_5 -> V_22 , V_79 ) -> V_106 ;
F_118 ( L_21 ,
F_55 () , ( long ) ( V_87 - V_5 -> V_86 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_104 ) ;
if ( V_103 ) {
F_106 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_105 ( L_22 ) ;
} else {
V_91 = V_87 ;
V_95 = F_2 ( V_5 -> V_96 ) ;
F_105 ( L_23 ,
V_5 -> V_30 , V_91 - V_95 , V_91 , V_95 ,
V_107 ,
F_46 ( V_5 ) -> V_99 ) ;
F_119 ( V_59 ) ;
}
}
F_120 ( V_5 ) ;
F_104 ( V_5 ) ;
F_37 ( V_5 ) ;
}
static void F_121 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_8 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
long V_104 = 0 ;
F_105 ( L_24 , V_5 -> V_30 ) ;
F_112 () ;
F_114 ( V_5 , F_55 () ) ;
F_115 () ;
F_116 (cpu)
V_104 += F_117 ( V_5 -> V_22 , V_79 ) -> V_106 ;
F_118 ( L_25 ,
V_87 - V_5 -> V_86 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_104 ) ;
F_104 ( V_5 ) ;
F_106 ( V_5 ) ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
if ( F_97 ( V_87 , F_2 ( V_5 -> V_92 ) ) )
F_94 ( V_5 -> V_92 ,
V_87 + 3 * F_103 () + 3 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
F_100 ( F_55 () ) ;
}
static void F_122 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_108 ;
unsigned long V_91 ;
unsigned long V_109 ;
struct V_1 * V_2 ;
if ( V_110 || ! F_3 ( V_5 ) )
return;
V_91 = V_87 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_123 () ;
V_109 = F_2 ( V_5 -> V_92 ) ;
F_123 () ;
V_108 = F_2 ( V_5 -> V_86 ) ;
F_123 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_97 ( V_6 , V_7 ) ||
F_49 ( V_91 , V_109 ) ||
F_97 ( V_108 , V_109 ) )
return;
V_2 = V_17 -> V_24 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_99 ) & V_17 -> V_74 ) ) {
F_121 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_97 ( V_91 , V_109 + V_105 ) ) {
F_111 ( V_5 , V_7 ) ;
}
}
void F_124 ( void )
{
struct V_4 * V_5 ;
F_17 (rsp)
F_94 ( V_5 -> V_92 , V_87 + V_80 / 2 ) ;
}
static void F_125 ( struct V_16 * V_17 )
{
int V_50 ;
V_17 -> V_43 = NULL ;
for ( V_50 = 0 ; V_50 < V_111 ; V_50 ++ )
V_17 -> V_44 [ V_50 ] = & V_17 -> V_43 ;
}
static void F_126 ( struct V_16 * V_17 )
{
if ( F_127 ( V_17 ) )
return;
F_125 ( V_17 ) ;
}
static unsigned long F_128 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_46 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_129 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned long V_112 , const char * V_11 )
{
F_130 ( V_17 -> V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_6 , V_112 , V_2 -> V_113 ,
V_2 -> V_101 , V_2 -> V_100 , V_11 ) ;
}
static bool V_61
F_131 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned long * V_114 )
{
unsigned long V_112 ;
int V_50 ;
bool V_73 = false ;
struct V_1 * V_115 = F_46 ( V_17 -> V_5 ) ;
V_112 = F_128 ( V_17 -> V_5 , V_2 ) ;
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_26 ) ) ;
if ( V_2 -> V_49 [ V_112 & 0x1 ] ) {
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_27 ) ) ;
goto V_116;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_115 -> V_7 ) != F_2 ( V_115 -> V_6 ) ) {
V_2 -> V_49 [ V_112 & 0x1 ] ++ ;
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_28 ) ) ;
goto V_116;
}
if ( V_2 != V_115 ) {
F_132 ( & V_115 -> V_98 ) ;
F_133 () ;
}
V_112 = F_128 ( V_17 -> V_5 , V_115 ) ;
for ( V_50 = V_45 ; V_50 < V_51 ; V_50 ++ )
if ( F_49 ( V_112 , V_17 -> V_54 [ V_50 ] ) )
V_17 -> V_54 [ V_50 ] = V_112 ;
if ( V_115 -> V_49 [ V_112 & 0x1 ] ) {
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_29 ) ) ;
goto V_117;
}
V_115 -> V_49 [ V_112 & 0x1 ] ++ ;
if ( V_115 -> V_7 != V_115 -> V_6 ) {
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_30 ) ) ;
} else {
F_129 ( V_2 , V_17 , V_112 , F_7 ( L_31 ) ) ;
V_73 = F_134 ( V_17 -> V_5 , V_115 , V_17 ) ;
}
V_117:
if ( V_2 != V_115 )
F_135 ( & V_115 -> V_98 ) ;
V_116:
if ( V_114 != NULL )
* V_114 = V_112 ;
return V_73 ;
}
static int F_136 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_112 = V_2 -> V_6 ;
int V_118 ;
struct V_16 * V_17 = F_11 ( V_5 -> V_22 ) ;
F_137 ( V_5 , V_2 ) ;
V_2 -> V_49 [ V_112 & 0x1 ] = 0 ;
V_118 = V_2 -> V_49 [ ( V_112 + 1 ) & 0x1 ] ;
F_129 ( V_2 , V_17 , V_112 ,
V_118 ? F_7 ( L_32 ) : F_7 ( L_33 ) ) ;
return V_118 ;
}
static void F_138 ( struct V_4 * V_5 )
{
if ( V_59 == V_5 -> V_32 ||
! F_2 ( V_5 -> V_41 ) ||
! V_5 -> V_32 )
return;
F_139 ( & V_5 -> V_119 ) ;
}
static bool F_140 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_16 * V_17 )
{
unsigned long V_112 ;
int V_50 ;
bool V_73 ;
if ( ! V_17 -> V_44 [ V_51 ] || ! * V_17 -> V_44 [ V_45 ] )
return false ;
V_112 = F_128 ( V_5 , V_2 ) ;
for ( V_50 = V_51 - 1 ; V_50 > V_45 ; V_50 -- )
if ( V_17 -> V_44 [ V_50 ] != V_17 -> V_44 [ V_50 - 1 ] &&
! F_97 ( V_17 -> V_54 [ V_50 ] , V_112 ) )
break;
if ( ++ V_50 >= V_51 )
return false ;
for (; V_50 <= V_51 ; V_50 ++ ) {
V_17 -> V_44 [ V_50 ] = V_17 -> V_44 [ V_51 ] ;
V_17 -> V_54 [ V_50 ] = V_112 ;
}
V_73 = F_131 ( V_2 , V_17 , NULL ) ;
if ( ! * V_17 -> V_44 [ V_53 ] )
F_6 ( V_5 -> V_30 , V_17 -> V_7 , F_7 ( L_34 ) ) ;
else
F_6 ( V_5 -> V_30 , V_17 -> V_7 , F_7 ( L_35 ) ) ;
return V_73 ;
}
static bool F_141 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_50 , V_91 ;
if ( ! V_17 -> V_44 [ V_51 ] || ! * V_17 -> V_44 [ V_45 ] )
return false ;
for ( V_50 = V_53 ; V_50 < V_51 ; V_50 ++ ) {
if ( F_49 ( V_2 -> V_6 , V_17 -> V_54 [ V_50 ] ) )
break;
V_17 -> V_44 [ V_45 ] = V_17 -> V_44 [ V_50 ] ;
}
for ( V_91 = V_53 ; V_91 < V_50 ; V_91 ++ )
V_17 -> V_44 [ V_91 ] = V_17 -> V_44 [ V_45 ] ;
for ( V_91 = V_53 ; V_50 < V_51 ; V_50 ++ , V_91 ++ ) {
if ( V_17 -> V_44 [ V_91 ] == V_17 -> V_44 [ V_51 ] )
break;
V_17 -> V_44 [ V_91 ] = V_17 -> V_44 [ V_50 ] ;
V_17 -> V_54 [ V_91 ] = V_17 -> V_54 [ V_50 ] ;
}
return F_140 ( V_5 , V_2 , V_17 ) ;
}
static bool F_142 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_16 * V_17 )
{
bool V_73 ;
if ( V_17 -> V_6 == V_2 -> V_6 &&
! F_27 ( F_2 ( V_17 -> V_81 ) ) ) {
V_73 = F_140 ( V_5 , V_2 , V_17 ) ;
} else {
V_73 = F_141 ( V_5 , V_2 , V_17 ) ;
V_17 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_30 , V_17 -> V_7 , F_7 ( L_36 ) ) ;
}
if ( V_17 -> V_7 != V_2 -> V_7 || F_27 ( F_2 ( V_17 -> V_81 ) ) ) {
V_17 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_30 , V_17 -> V_7 , F_7 ( L_37 ) ) ;
V_17 -> V_10 . V_12 . V_13 = true ;
V_17 -> V_120 = F_5 ( V_27 ) ;
V_17 -> V_121 = ! ! ( V_2 -> V_99 & V_17 -> V_74 ) ;
F_143 ( V_17 ) ;
F_94 ( V_17 -> V_81 , false ) ;
}
return V_73 ;
}
static void F_144 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
unsigned long V_8 ;
bool V_122 ;
struct V_1 * V_2 ;
F_9 ( V_8 ) ;
V_2 = V_17 -> V_24 ;
if ( ( V_17 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_17 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_27 ( F_2 ( V_17 -> V_81 ) ) ) ||
! F_145 ( & V_2 -> V_98 ) ) {
F_12 ( V_8 ) ;
return;
}
F_133 () ;
V_122 = F_142 ( V_5 , V_2 , V_17 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
if ( V_122 )
F_138 ( V_5 ) ;
}
static void F_146 ( struct V_4 * V_5 , int V_123 )
{
if ( V_123 > 0 &&
! ( V_5 -> V_7 % ( V_124 * V_125 * V_123 ) ) )
F_147 ( V_123 ) ;
}
static int F_148 ( struct V_4 * V_5 )
{
unsigned long V_126 ;
struct V_16 * V_17 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_94 ( V_5 -> V_96 , V_87 ) ;
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
if ( ! F_2 ( V_5 -> V_41 ) ) {
F_150 ( & V_2 -> V_98 ) ;
return 0 ;
}
F_94 ( V_5 -> V_41 , 0 ) ;
if ( F_61 ( F_3 ( V_5 ) ) ) {
F_150 ( & V_2 -> V_98 ) ;
return 0 ;
}
F_101 ( V_5 ) ;
F_151 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_7 , F_7 ( L_38 ) ) ;
F_150 ( & V_2 -> V_98 ) ;
F_107 (rsp, rnp) {
F_146 ( V_5 , V_127 ) ;
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
if ( V_2 -> V_128 == V_2 -> V_3 &&
! V_2 -> V_129 ) {
F_150 ( & V_2 -> V_98 ) ;
continue;
}
V_126 = V_2 -> V_128 ;
V_2 -> V_128 = V_2 -> V_3 ;
if ( ! V_126 != ! V_2 -> V_128 ) {
if ( ! V_126 )
F_152 ( V_2 ) ;
else if ( F_153 ( V_2 ) )
V_2 -> V_129 = true ;
else
F_154 ( V_2 ) ;
}
if ( V_2 -> V_129 &&
( ! F_153 ( V_2 ) ||
V_2 -> V_128 ) ) {
V_2 -> V_129 = false ;
F_154 ( V_2 ) ;
}
F_150 ( & V_2 -> V_98 ) ;
}
F_155 (rsp, rnp) {
F_146 ( V_5 , V_130 ) ;
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
V_17 = F_11 ( V_5 -> V_22 ) ;
F_156 ( V_2 ) ;
V_2 -> V_99 = V_2 -> V_128 ;
F_94 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_61 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_94 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_17 -> V_24 )
( void ) F_142 ( V_5 , V_2 , V_17 ) ;
F_157 ( V_2 ) ;
F_158 ( V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_113 , V_2 -> V_101 ,
V_2 -> V_100 , V_2 -> V_99 ) ;
F_150 ( & V_2 -> V_98 ) ;
F_159 () ;
F_94 ( V_5 -> V_96 , V_87 ) ;
}
return 1 ;
}
static bool F_160 ( struct V_4 * V_5 , int * V_131 )
{
struct V_1 * V_2 = F_46 ( V_5 ) ;
* V_131 = F_2 ( V_5 -> V_41 ) ;
if ( * V_131 & V_132 )
return true ;
if ( ! F_2 ( V_2 -> V_99 ) && ! F_161 ( V_2 ) )
return true ;
return false ;
}
static void F_162 ( struct V_4 * V_5 , bool V_133 )
{
bool V_76 = false ;
unsigned long V_77 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_94 ( V_5 -> V_96 , V_87 ) ;
V_5 -> V_94 ++ ;
if ( V_133 ) {
if ( F_163 ( V_5 ) ) {
V_76 = true ;
V_77 = V_87 - V_80 / 4 ;
}
F_164 ( V_5 , F_90 ,
& V_76 , & V_77 ) ;
F_165 ( V_5 , V_76 , V_77 ) ;
} else {
V_76 = true ;
F_164 ( V_5 , F_95 , & V_76 , & V_77 ) ;
}
if ( F_2 ( V_5 -> V_41 ) & V_132 ) {
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
F_94 ( V_5 -> V_41 ,
F_2 ( V_5 -> V_41 ) & ~ V_132 ) ;
F_150 ( & V_2 -> V_98 ) ;
}
}
static void F_166 ( struct V_4 * V_5 )
{
unsigned long V_134 ;
bool V_135 = false ;
int V_136 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_94 ( V_5 -> V_96 , V_87 ) ;
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
V_134 = V_87 - V_5 -> V_86 ;
if ( V_134 > V_5 -> V_137 )
V_5 -> V_137 = V_134 ;
F_150 ( & V_2 -> V_98 ) ;
F_155 (rsp, rnp) {
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
F_61 ( F_161 ( V_2 ) ) ;
F_61 ( V_2 -> V_99 ) ;
F_94 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_17 = F_11 ( V_5 -> V_22 ) ;
if ( V_2 == V_17 -> V_24 )
V_135 = F_142 ( V_5 , V_2 , V_17 ) || V_135 ;
V_136 += F_136 ( V_5 , V_2 ) ;
F_150 ( & V_2 -> V_98 ) ;
F_159 () ;
F_94 ( V_5 -> V_96 , V_87 ) ;
F_146 ( V_5 , V_138 ) ;
}
V_2 = F_46 ( V_5 ) ;
F_149 ( & V_2 -> V_98 ) ;
F_133 () ;
F_167 ( V_2 , V_136 ) ;
F_94 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_6 , F_7 ( L_39 ) ) ;
V_5 -> V_31 = V_139 ;
V_17 = F_11 ( V_5 -> V_22 ) ;
V_135 = F_141 ( V_5 , V_2 , V_17 ) || V_135 ;
if ( V_135 || F_48 ( V_5 , V_17 ) ) {
F_94 ( V_5 -> V_41 , V_140 ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
}
F_150 ( & V_2 -> V_98 ) ;
}
static int T_3 F_168 ( void * V_141 )
{
bool V_142 ;
int V_143 ;
unsigned long V_91 ;
int V_73 ;
struct V_4 * V_5 = V_141 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_169 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_41 ) ) ;
V_5 -> V_31 = V_144 ;
F_170 ( V_5 -> V_119 ,
F_2 ( V_5 -> V_41 ) &
V_140 ) ;
V_5 -> V_31 = V_145 ;
if ( F_148 ( V_5 ) )
break;
F_159 () ;
F_94 ( V_5 -> V_96 , V_87 ) ;
F_171 ( F_172 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_42 ) ) ;
}
V_142 = true ;
V_91 = V_146 ;
if ( V_91 > V_97 ) {
V_91 = V_97 ;
V_146 = V_97 ;
}
V_73 = 0 ;
for (; ; ) {
if ( ! V_73 )
V_5 -> V_147 = V_87 + V_91 ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
V_5 -> V_31 = V_148 ;
V_73 = F_173 ( V_5 -> V_119 ,
F_160 ( V_5 , & V_143 ) , V_91 ) ;
V_5 -> V_31 = V_149 ;
if ( ! F_2 ( V_2 -> V_99 ) &&
! F_161 ( V_2 ) )
break;
if ( F_97 ( V_87 , V_5 -> V_147 ) ||
( V_143 & V_132 ) ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
F_162 ( V_5 , V_142 ) ;
V_142 = false ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
F_159 () ;
F_94 ( V_5 -> V_96 , V_87 ) ;
} else {
F_159 () ;
F_94 ( V_5 -> V_96 , V_87 ) ;
F_171 ( F_172 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
V_91 = V_107 ;
if ( V_91 > V_97 ) {
V_91 = V_97 ;
V_107 = V_97 ;
} else if ( V_91 < 1 ) {
V_91 = 1 ;
V_107 = 1 ;
}
}
V_5 -> V_31 = V_150 ;
F_166 ( V_5 ) ;
V_5 -> V_31 = V_151 ;
}
}
static bool
F_134 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_16 * V_17 )
{
if ( ! V_5 -> V_32 || ! F_48 ( V_5 , V_17 ) ) {
return false ;
}
F_94 ( V_5 -> V_41 , V_140 ) ;
F_6 ( V_5 -> V_30 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
return true ;
}
static bool F_174 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = F_11 ( V_5 -> V_22 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
bool V_73 = false ;
V_73 = F_141 ( V_5 , V_2 , V_17 ) || V_73 ;
V_73 = F_134 ( V_5 , V_2 , V_17 ) || V_73 ;
return V_73 ;
}
static void F_175 ( struct V_4 * V_5 , unsigned long V_8 )
__releases( rcu_get_root( V_5 )->lock
static void
F_176 ( unsigned long V_152 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_108 , unsigned long V_8 )
__releases( V_2 -> V_98 )
{
unsigned long V_126 = 0 ;
struct V_1 * V_153 ;
for (; ; ) {
if ( ! ( V_2 -> V_99 & V_152 ) || V_2 -> V_7 != V_108 ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
F_61 ( V_126 ) ;
V_2 -> V_99 &= ~ V_152 ;
F_177 ( V_5 -> V_30 , V_2 -> V_7 ,
V_152 , V_2 -> V_99 , V_2 -> V_113 ,
V_2 -> V_101 , V_2 -> V_100 ,
! ! V_2 -> V_154 ) ;
if ( V_2 -> V_99 != 0 || F_161 ( V_2 ) ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
V_152 = V_2 -> V_74 ;
if ( V_2 -> V_155 == NULL ) {
break;
}
F_110 ( & V_2 -> V_98 , V_8 ) ;
V_153 = V_2 ;
V_2 = V_2 -> V_155 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
V_126 = V_153 -> V_99 ;
}
F_175 ( V_5 , V_8 ) ;
}
static void F_178 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_8 )
__releases( V_2 -> V_98 )
{
unsigned long V_108 ;
unsigned long V_152 ;
struct V_1 * V_156 ;
if ( V_28 == & V_14 || V_5 != V_28 ||
V_2 -> V_99 != 0 || F_161 ( V_2 ) ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
V_156 = V_2 -> V_155 ;
if ( V_156 == NULL ) {
F_175 ( V_5 , V_8 ) ;
return;
}
V_108 = V_2 -> V_7 ;
V_152 = V_2 -> V_74 ;
F_135 ( & V_2 -> V_98 ) ;
F_132 ( & V_156 -> V_98 ) ;
F_133 () ;
F_176 ( V_152 , V_5 , V_156 , V_108 , V_8 ) ;
}
static void
F_179 ( int V_79 , struct V_4 * V_5 , struct V_16 * V_17 )
{
unsigned long V_8 ;
unsigned long V_152 ;
bool V_122 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_24 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
if ( ( V_17 -> V_10 . V_12 . V_13 &&
V_17 -> V_120 == F_5 ( V_27 ) ) ||
V_17 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_17 -> V_81 ) {
V_17 -> V_10 . V_12 . V_13 = true ;
V_17 -> V_120 = F_5 ( V_27 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
V_152 = V_17 -> V_74 ;
if ( ( V_2 -> V_99 & V_152 ) == 0 ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
} else {
V_17 -> V_121 = 0 ;
V_122 = F_140 ( V_5 , V_2 , V_17 ) ;
F_176 ( V_152 , V_5 , V_2 , V_2 -> V_7 , V_8 ) ;
if ( V_122 )
F_138 ( V_5 ) ;
}
}
static void
F_180 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
F_144 ( V_5 , V_17 ) ;
if ( ! V_17 -> V_121 )
return;
if ( V_17 -> V_10 . V_12 . V_13 &&
V_17 -> V_120 == F_5 ( V_27 ) )
return;
F_179 ( V_17 -> V_79 , V_5 , V_17 ) ;
}
static void
F_181 ( int V_79 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( ! F_52 ( V_157 ) || F_182 ( V_17 -> V_79 ) )
return;
if ( V_17 -> V_43 != NULL ) {
V_5 -> V_158 += V_17 -> V_158 ;
V_5 -> V_106 += V_17 -> V_106 ;
V_17 -> V_159 += V_17 -> V_106 ;
V_17 -> V_158 = 0 ;
F_94 ( V_17 -> V_106 , 0 ) ;
}
if ( * V_17 -> V_44 [ V_45 ] != NULL ) {
* V_5 -> V_160 = * V_17 -> V_44 [ V_45 ] ;
V_5 -> V_160 = V_17 -> V_44 [ V_51 ] ;
* V_17 -> V_44 [ V_45 ] = NULL ;
}
if ( V_17 -> V_43 != NULL ) {
* V_5 -> V_161 = V_17 -> V_43 ;
V_5 -> V_161 = V_17 -> V_44 [ V_45 ] ;
}
F_126 ( V_17 ) ;
V_17 -> V_44 [ V_51 ] = NULL ;
}
static void F_183 ( struct V_4 * V_5 , unsigned long V_8 )
{
int V_50 ;
struct V_16 * V_17 = F_18 ( V_5 -> V_22 ) ;
if ( ! F_52 ( V_157 ) ||
F_184 ( V_5 , V_17 , V_8 ) )
return;
V_17 -> V_158 += V_5 -> V_158 ;
V_17 -> V_106 += V_5 -> V_106 ;
V_17 -> V_162 += V_5 -> V_106 ;
if ( V_5 -> V_158 != V_5 -> V_106 )
F_185 () ;
V_5 -> V_158 = 0 ;
V_5 -> V_106 = 0 ;
if ( V_5 -> V_163 != NULL ) {
* V_5 -> V_161 = * V_17 -> V_44 [ V_45 ] ;
* V_17 -> V_44 [ V_45 ] = V_5 -> V_163 ;
for ( V_50 = V_111 - 1 ; V_50 >= V_45 ; V_50 -- )
if ( V_17 -> V_44 [ V_50 ] == V_17 -> V_44 [ V_45 ] )
V_17 -> V_44 [ V_50 ] = V_5 -> V_161 ;
V_5 -> V_163 = NULL ;
V_5 -> V_161 = & V_5 -> V_163 ;
}
if ( V_5 -> V_164 != NULL ) {
* V_17 -> V_44 [ V_51 ] = V_5 -> V_164 ;
V_17 -> V_44 [ V_51 ] = V_5 -> V_160 ;
V_5 -> V_164 = NULL ;
V_5 -> V_160 = & V_5 -> V_164 ;
}
}
static void F_186 ( struct V_4 * V_5 )
{
F_187 (unsigned long mask) ;
F_187 ( struct V_16 * V_17 = F_11 ( V_5 -> V_22 ) ) ;
F_187 ( struct V_1 * V_2 = V_17 -> V_24 ) ;
if ( ! F_52 ( V_157 ) )
return;
F_187 ( V_152 = V_17 -> V_74 ) ;
F_6 ( V_5 -> V_30 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_99 & V_152 ) ,
F_7 ( L_47 ) ) ;
}
static void F_154 ( struct V_1 * V_165 )
{
long V_152 ;
struct V_1 * V_2 = V_165 ;
if ( ! F_52 ( V_157 ) ||
V_2 -> V_128 || F_153 ( V_2 ) )
return;
for (; ; ) {
V_152 = V_2 -> V_74 ;
V_2 = V_2 -> V_155 ;
if ( ! V_2 )
break;
F_132 ( & V_2 -> V_98 ) ;
F_133 () ;
V_2 -> V_128 &= ~ V_152 ;
V_2 -> V_99 &= ~ V_152 ;
if ( V_2 -> V_128 ) {
F_135 ( & V_2 -> V_98 ) ;
return;
}
F_135 ( & V_2 -> V_98 ) ;
}
}
static void F_188 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_8 ;
unsigned long V_152 ;
struct V_16 * V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
struct V_1 * V_2 = V_17 -> V_24 ;
if ( ! F_52 ( V_157 ) )
return;
V_152 = V_17 -> V_74 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
V_2 -> V_3 &= ~ V_152 ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
static void F_189 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_8 ;
struct V_16 * V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
struct V_1 * V_2 = V_17 -> V_24 ;
if ( ! F_52 ( V_157 ) )
return;
F_190 ( V_2 , - 1 ) ;
F_108 ( & V_5 -> V_166 , V_8 ) ;
F_181 ( V_79 , V_5 , V_2 , V_17 ) ;
F_183 ( V_5 , V_8 ) ;
F_110 ( & V_5 -> V_166 , V_8 ) ;
F_57 ( V_17 -> V_106 != 0 || V_17 -> V_43 != NULL ,
L_48 ,
V_79 , V_17 -> V_106 , V_17 -> V_43 ) ;
}
static void F_191 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
unsigned long V_8 ;
struct V_167 * V_168 , * V_169 , * * V_170 ;
long V_171 , V_172 , V_173 ;
int V_50 ;
if ( ! F_45 ( V_17 ) ) {
F_192 ( V_5 -> V_30 , V_17 -> V_158 , V_17 -> V_106 , 0 ) ;
F_193 ( V_5 -> V_30 , 0 , ! ! F_2 ( V_17 -> V_43 ) ,
F_194 () , F_53 ( V_59 ) ,
F_195 () ) ;
return;
}
F_9 ( V_8 ) ;
F_61 ( F_98 ( F_55 () ) ) ;
V_171 = V_17 -> V_174 ;
F_192 ( V_5 -> V_30 , V_17 -> V_158 , V_17 -> V_106 , V_171 ) ;
V_169 = V_17 -> V_43 ;
V_17 -> V_43 = * V_17 -> V_44 [ V_45 ] ;
* V_17 -> V_44 [ V_45 ] = NULL ;
V_170 = V_17 -> V_44 [ V_45 ] ;
for ( V_50 = V_111 - 1 ; V_50 >= 0 ; V_50 -- )
if ( V_17 -> V_44 [ V_50 ] == V_17 -> V_44 [ V_45 ] )
V_17 -> V_44 [ V_50 ] = & V_17 -> V_43 ;
F_12 ( V_8 ) ;
V_172 = V_173 = 0 ;
while ( V_169 ) {
V_168 = V_169 -> V_168 ;
F_196 ( V_168 ) ;
F_197 ( V_169 ) ;
if ( F_198 ( V_5 -> V_30 , V_169 ) )
V_173 ++ ;
V_169 = V_168 ;
if ( ++ V_172 >= V_171 &&
( F_194 () ||
( ! F_53 ( V_59 ) && ! F_195 () ) ) )
break;
}
F_9 ( V_8 ) ;
F_193 ( V_5 -> V_30 , V_172 , ! ! V_169 , F_194 () ,
F_53 ( V_59 ) ,
F_195 () ) ;
if ( V_169 != NULL ) {
* V_170 = V_17 -> V_43 ;
V_17 -> V_43 = V_169 ;
for ( V_50 = 0 ; V_50 < V_111 ; V_50 ++ )
if ( & V_17 -> V_43 == V_17 -> V_44 [ V_50 ] )
V_17 -> V_44 [ V_50 ] = V_170 ;
else
break;
}
F_19 () ;
V_17 -> V_158 -= V_173 ;
F_94 ( V_17 -> V_106 , V_17 -> V_106 - V_172 ) ;
V_17 -> V_175 += V_172 ;
if ( V_17 -> V_174 == V_176 && V_17 -> V_106 <= V_177 )
V_17 -> V_174 = V_174 ;
if ( V_17 -> V_106 == 0 && V_17 -> V_178 != 0 ) {
V_17 -> V_178 = 0 ;
V_17 -> V_179 = V_5 -> V_94 ;
} else if ( V_17 -> V_106 < V_17 -> V_178 - V_180 )
V_17 -> V_178 = V_17 -> V_106 ;
F_61 ( ( V_17 -> V_43 == NULL ) != ( V_17 -> V_106 == 0 ) ) ;
F_12 ( V_8 ) ;
if ( F_45 ( V_17 ) )
F_199 () ;
}
void F_200 ( int V_56 )
{
F_25 ( F_7 ( L_49 ) ) ;
F_201 () ;
if ( V_56 || F_89 () ) {
F_4 () ;
F_13 () ;
} else if ( ! F_202 () ) {
F_13 () ;
}
F_203 () ;
if ( F_204 () )
F_199 () ;
if ( V_56 )
F_205 ( V_59 ) ;
F_25 ( F_7 ( L_50 ) ) ;
}
static void F_164 ( struct V_4 * V_5 ,
int (* F_206)( struct V_16 * V_5 , bool * V_76 ,
unsigned long * V_77 ) ,
bool * V_76 , unsigned long * V_77 )
{
unsigned long V_181 ;
int V_79 ;
unsigned long V_8 ;
unsigned long V_152 ;
struct V_1 * V_2 ;
F_107 (rsp, rnp) {
F_159 () ;
V_152 = 0 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
if ( V_2 -> V_99 == 0 ) {
if ( V_28 == & V_14 ||
V_5 != V_28 ||
F_161 ( V_2 ) ) {
F_207 ( V_2 , V_8 ) ;
continue;
}
if ( V_2 -> V_155 &&
( V_2 -> V_155 -> V_99 & V_2 -> V_74 ) ) {
F_178 ( V_5 , V_2 , V_8 ) ;
continue;
}
}
V_79 = V_2 -> V_101 ;
V_181 = 1 ;
for (; V_79 <= V_2 -> V_100 ; V_79 ++ , V_181 <<= 1 ) {
if ( ( V_2 -> V_99 & V_181 ) != 0 ) {
if ( F_206 ( F_117 ( V_5 -> V_22 , V_79 ) , V_76 , V_77 ) )
V_152 |= V_181 ;
}
}
if ( V_152 != 0 ) {
F_176 ( V_152 , V_5 , V_2 , V_2 -> V_7 , V_8 ) ;
} else {
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
}
}
static void F_37 ( struct V_4 * V_5 )
{
unsigned long V_8 ;
bool V_73 ;
struct V_1 * V_2 ;
struct V_1 * V_182 = NULL ;
V_2 = F_5 ( V_5 -> V_22 -> V_24 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_155 ) {
V_73 = ( F_2 ( V_5 -> V_41 ) & V_132 ) ||
! F_145 ( & V_2 -> V_183 ) ;
if ( V_182 != NULL )
F_135 ( & V_182 -> V_183 ) ;
if ( V_73 ) {
V_5 -> V_184 ++ ;
return;
}
V_182 = V_2 ;
}
F_108 ( & V_182 -> V_98 , V_8 ) ;
F_133 () ;
F_135 ( & V_182 -> V_183 ) ;
if ( F_2 ( V_5 -> V_41 ) & V_132 ) {
V_5 -> V_184 ++ ;
F_110 ( & V_182 -> V_98 , V_8 ) ;
return;
}
F_94 ( V_5 -> V_41 , F_2 ( V_5 -> V_41 ) | V_132 ) ;
F_110 ( & V_182 -> V_98 , V_8 ) ;
F_138 ( V_5 ) ;
}
static void
F_208 ( struct V_4 * V_5 )
{
unsigned long V_8 ;
bool V_122 ;
struct V_16 * V_17 = F_18 ( V_5 -> V_22 ) ;
F_61 ( V_17 -> V_185 == 0 ) ;
F_180 ( V_5 , V_17 ) ;
F_9 ( V_8 ) ;
if ( F_48 ( V_5 , V_17 ) ) {
F_132 ( & F_46 ( V_5 ) -> V_98 ) ;
V_122 = F_174 ( V_5 ) ;
F_110 ( & F_46 ( V_5 ) -> V_98 , V_8 ) ;
if ( V_122 )
F_138 ( V_5 ) ;
} else {
F_12 ( V_8 ) ;
}
if ( F_45 ( V_17 ) )
F_209 ( V_5 , V_17 ) ;
F_58 ( V_17 ) ;
}
static void F_210 ( struct V_186 * V_187 )
{
struct V_4 * V_5 ;
if ( F_98 ( F_55 () ) )
return;
F_25 ( F_7 ( L_51 ) ) ;
F_17 (rsp)
F_208 ( V_5 ) ;
F_25 ( F_7 ( L_52 ) ) ;
}
static void F_209 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( F_27 ( ! F_2 ( V_75 ) ) )
return;
if ( F_211 ( ! V_5 -> V_188 ) ) {
F_191 ( V_5 , V_17 ) ;
return;
}
F_212 () ;
}
static void F_199 ( void )
{
if ( F_213 ( F_55 () ) )
F_214 ( V_189 ) ;
}
static void F_215 ( struct V_4 * V_5 , struct V_16 * V_17 ,
struct V_167 * V_190 , unsigned long V_8 )
{
bool V_122 ;
if ( ! F_82 () )
F_199 () ;
if ( F_216 ( V_8 ) || F_98 ( F_55 () ) )
return;
if ( F_27 ( V_17 -> V_106 > V_17 -> V_178 + V_180 ) ) {
F_144 ( V_5 , V_17 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_115 = F_46 ( V_5 ) ;
F_132 ( & V_115 -> V_98 ) ;
F_133 () ;
V_122 = F_174 ( V_5 ) ;
F_135 ( & V_115 -> V_98 ) ;
if ( V_122 )
F_138 ( V_5 ) ;
} else {
V_17 -> V_174 = V_176 ;
if ( V_5 -> V_94 == V_17 -> V_179 &&
* V_17 -> V_44 [ V_45 ] != V_190 )
F_37 ( V_5 ) ;
V_17 -> V_179 = V_5 -> V_94 ;
V_17 -> V_178 = V_17 -> V_106 ;
}
}
}
static void F_217 ( struct V_167 * V_191 )
{
}
static void
F_218 ( struct V_167 * V_190 , T_4 V_192 ,
struct V_4 * V_5 , int V_79 , bool V_193 )
{
unsigned long V_8 ;
struct V_16 * V_17 ;
F_61 ( ( unsigned long ) V_190 & 0x1 ) ;
if ( F_219 ( V_190 ) ) {
F_94 ( V_190 -> V_192 , F_217 ) ;
F_57 ( 1 , L_53 ) ;
return;
}
V_190 -> V_192 = V_192 ;
V_190 -> V_168 = NULL ;
F_9 ( V_8 ) ;
V_17 = F_11 ( V_5 -> V_22 ) ;
if ( F_27 ( V_17 -> V_44 [ V_51 ] == NULL ) || V_79 != - 1 ) {
int V_194 ;
if ( V_79 != - 1 )
V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
if ( F_211 ( V_17 -> V_24 ) ) {
V_194 = ! F_220 ( V_17 , V_190 , V_193 , V_8 ) ;
F_61 ( V_194 ) ;
F_12 ( V_8 ) ;
return;
}
F_221 ( V_79 != - 1 ) ;
F_61 ( ! F_82 () ) ;
if ( ! F_211 ( V_17 -> V_43 ) )
F_125 ( V_17 ) ;
}
F_94 ( V_17 -> V_106 , V_17 -> V_106 + 1 ) ;
if ( V_193 )
V_17 -> V_158 ++ ;
else
F_185 () ;
F_19 () ;
* V_17 -> V_44 [ V_51 ] = V_190 ;
V_17 -> V_44 [ V_51 ] = & V_190 -> V_168 ;
if ( F_222 ( ( unsigned long ) V_192 ) )
F_223 ( V_5 -> V_30 , V_190 , ( unsigned long ) V_192 ,
V_17 -> V_158 , V_17 -> V_106 ) ;
else
F_224 ( V_5 -> V_30 , V_190 , V_17 -> V_158 , V_17 -> V_106 ) ;
F_215 ( V_5 , V_17 , V_190 , V_8 ) ;
F_12 ( V_8 ) ;
}
void F_225 ( struct V_167 * V_190 , T_4 V_192 )
{
F_218 ( V_190 , V_192 , & V_14 , - 1 , 0 ) ;
}
void F_226 ( struct V_167 * V_190 , T_4 V_192 )
{
F_218 ( V_190 , V_192 , & V_29 , - 1 , 0 ) ;
}
void F_227 ( struct V_167 * V_190 ,
T_4 V_192 )
{
F_218 ( V_190 , V_192 , V_28 , - 1 , 1 ) ;
}
static inline int F_228 ( void )
{
int V_73 ;
F_229 () ;
F_87 () ;
V_73 = F_230 () <= 1 ;
F_88 () ;
return V_73 ;
}
void F_231 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_54 ) ;
if ( F_228 () )
return;
if ( F_232 () )
F_233 () ;
else
F_234 ( F_225 ) ;
}
void F_235 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_55 ) ;
if ( F_228 () )
return;
if ( F_232 () )
F_236 () ;
else
F_234 ( F_226 ) ;
}
unsigned long F_237 ( void )
{
F_19 () ;
return F_238 ( & V_28 -> V_7 ) ;
}
void F_239 ( unsigned long V_195 )
{
unsigned long V_196 ;
V_196 = F_238 ( & V_28 -> V_6 ) ;
if ( F_97 ( V_195 , V_196 ) )
F_240 () ;
}
unsigned long F_241 ( void )
{
F_19 () ;
return F_238 ( & V_14 . V_7 ) ;
}
void F_242 ( unsigned long V_195 )
{
unsigned long V_196 ;
V_196 = F_238 ( & V_14 . V_6 ) ;
if ( F_97 ( V_195 , V_196 ) )
F_231 () ;
}
static void F_243 ( unsigned long * V_197 )
{
F_94 ( * V_197 , * V_197 + 1 ) ;
F_19 () ;
F_61 ( ! ( * V_197 & 0x1 ) ) ;
}
static void F_244 ( unsigned long * V_197 )
{
F_19 () ;
F_94 ( * V_197 , * V_197 + 1 ) ;
F_61 ( * V_197 & 0x1 ) ;
}
static unsigned long F_245 ( unsigned long * V_197 )
{
unsigned long V_11 ;
F_19 () ;
V_11 = ( F_2 ( * V_197 ) + 3 ) & ~ 0x1 ;
F_19 () ;
return V_11 ;
}
static bool F_246 ( unsigned long * V_197 , unsigned long V_11 )
{
return F_97 ( F_2 ( * V_197 ) , V_11 ) ;
}
static void F_247 ( struct V_4 * V_5 )
{
F_243 ( & V_5 -> V_198 ) ;
}
static void F_248 ( struct V_4 * V_5 )
{
F_244 ( & V_5 -> V_198 ) ;
F_19 () ;
}
static unsigned long F_249 ( struct V_4 * V_5 )
{
return F_245 ( & V_5 -> V_198 ) ;
}
static bool F_250 ( struct V_4 * V_5 , unsigned long V_11 )
{
return F_246 ( & V_5 -> V_198 , V_11 ) ;
}
static void F_251 ( struct V_4 * V_5 )
{
bool V_199 ;
unsigned long V_8 ;
unsigned long V_152 ;
unsigned long V_126 ;
int V_200 = F_2 ( V_5 -> V_200 ) ;
struct V_1 * V_2 ;
struct V_1 * V_201 ;
if ( F_211 ( V_200 == V_5 -> V_202 ) )
return;
V_5 -> V_202 = V_200 ;
F_107 (rsp, rnp) {
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
if ( V_2 -> V_203 == V_2 -> V_204 ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
continue;
}
V_126 = V_2 -> V_203 ;
V_2 -> V_203 = V_2 -> V_204 ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
if ( V_126 )
continue;
V_152 = V_2 -> V_74 ;
V_201 = V_2 -> V_155 ;
V_199 = false ;
while ( V_201 ) {
F_108 ( & V_201 -> V_98 , V_8 ) ;
F_133 () ;
if ( V_201 -> V_203 )
V_199 = true ;
V_201 -> V_203 |= V_152 ;
F_110 ( & V_201 -> V_98 , V_8 ) ;
if ( V_199 )
break;
V_152 = V_201 -> V_74 ;
V_201 = V_201 -> V_155 ;
}
}
}
static void V_61 F_252 ( struct V_4 * V_5 )
{
unsigned long V_8 ;
struct V_1 * V_2 ;
F_251 ( V_5 ) ;
F_155 (rsp, rnp) {
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
F_61 ( V_2 -> V_205 ) ;
V_2 -> V_205 = V_2 -> V_203 ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
}
static int F_253 ( struct V_1 * V_2 )
{
return V_2 -> V_206 == NULL &&
F_2 ( V_2 -> V_205 ) == 0 ;
}
static void F_254 ( struct V_4 * V_5 , struct V_1 * V_2 ,
bool V_207 , unsigned long V_8 )
__releases( V_2 -> V_98 )
{
unsigned long V_152 ;
for (; ; ) {
if ( ! F_253 ( V_2 ) ) {
if ( ! V_2 -> V_205 )
F_207 ( V_2 , V_8 ) ;
else
F_110 ( & V_2 -> V_98 , V_8 ) ;
break;
}
if ( V_2 -> V_155 == NULL ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
if ( V_207 ) {
F_19 () ;
F_139 ( & V_5 -> V_208 ) ;
}
break;
}
V_152 = V_2 -> V_74 ;
F_135 ( & V_2 -> V_98 ) ;
V_2 = V_2 -> V_155 ;
F_132 ( & V_2 -> V_98 ) ;
F_133 () ;
F_61 ( ! ( V_2 -> V_205 & V_152 ) ) ;
V_2 -> V_205 &= ~ V_152 ;
}
}
static void V_61 F_255 ( struct V_4 * V_5 ,
struct V_1 * V_2 , bool V_207 )
{
unsigned long V_8 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
F_254 ( V_5 , V_2 , V_207 , V_8 ) ;
}
static void F_256 ( struct V_4 * V_5 , struct V_1 * V_2 ,
unsigned long V_152 , bool V_207 )
{
unsigned long V_8 ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
if ( ! ( V_2 -> V_205 & V_152 ) ) {
F_110 ( & V_2 -> V_98 , V_8 ) ;
return;
}
V_2 -> V_205 &= ~ V_152 ;
F_254 ( V_5 , V_2 , V_207 , V_8 ) ;
}
static void F_10 ( struct V_4 * V_5 , struct V_16 * V_17 ,
bool V_207 )
{
F_256 ( V_5 , V_17 -> V_24 , V_17 -> V_74 , V_207 ) ;
}
static bool F_257 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_5 * V_209 , unsigned long V_11 )
{
if ( F_250 ( V_5 , V_11 ) ) {
if ( V_2 )
F_258 ( & V_2 -> V_210 ) ;
else if ( V_17 )
F_258 ( & V_17 -> V_210 ) ;
F_20 () ;
F_259 ( V_209 ) ;
return true ;
}
return false ;
}
static struct V_1 * F_260 ( struct V_4 * V_5 , unsigned long V_11 )
{
struct V_16 * V_17 ;
struct V_1 * V_211 ;
struct V_1 * V_212 = NULL ;
V_211 = F_46 ( V_5 ) ;
if ( ! F_261 ( & V_211 -> V_210 ) ) {
if ( F_262 ( & V_211 -> V_210 ) ) {
if ( F_257 ( V_5 , V_211 , NULL ,
& V_5 -> V_213 , V_11 ) )
return NULL ;
return V_211 ;
}
}
V_17 = F_117 ( V_5 -> V_22 , F_263 () ) ;
if ( F_257 ( V_5 , NULL , NULL , & V_5 -> V_214 , V_11 ) )
return NULL ;
F_264 ( & V_17 -> V_210 ) ;
V_211 = V_17 -> V_24 ;
for (; V_211 != NULL ; V_211 = V_211 -> V_155 ) {
if ( F_257 ( V_5 , V_212 , V_17 ,
& V_5 -> V_215 , V_11 ) )
return NULL ;
F_264 ( & V_211 -> V_210 ) ;
if ( V_212 )
F_258 ( & V_212 -> V_210 ) ;
else
F_258 ( & V_17 -> V_210 ) ;
V_212 = V_211 ;
}
if ( F_257 ( V_5 , V_212 , V_17 ,
& V_5 -> V_216 , V_11 ) )
return NULL ;
return V_212 ;
}
static void F_265 ( void * V_217 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = V_217 ;
V_17 = F_11 ( V_5 -> V_22 ) ;
V_2 = V_17 -> V_24 ;
if ( ! ( F_2 ( V_2 -> V_205 ) & V_17 -> V_74 ) ||
F_5 ( V_9 . V_10 . V_12 . exp ) )
return;
F_8 ( V_9 . V_10 . V_12 . exp , true ) ;
F_100 ( F_55 () ) ;
}
static void F_266 ( int V_79 )
{
struct V_16 * V_17 ;
int V_73 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_14 ;
V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
V_2 = V_17 -> V_24 ;
if ( ! ( F_2 ( V_2 -> V_205 ) & V_17 -> V_74 ) )
return;
V_73 = F_267 ( V_79 , F_265 , V_5 , 0 ) ;
F_61 ( V_73 ) ;
}
static void F_268 ( struct V_4 * V_5 ,
T_6 V_192 )
{
int V_79 ;
unsigned long V_8 ;
unsigned long V_152 ;
unsigned long V_218 ;
unsigned long V_219 ;
int V_73 ;
struct V_1 * V_2 ;
F_252 ( V_5 ) ;
F_107 (rsp, rnp) {
F_108 ( & V_2 -> V_98 , V_8 ) ;
F_133 () ;
V_218 = 0 ;
for ( V_79 = V_2 -> V_101 ; V_79 <= V_2 -> V_100 ; V_79 ++ ) {
struct V_16 * V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
struct V_18 * V_19 = & F_99 ( V_18 , V_79 ) ;
if ( F_263 () == V_79 ||
! ( F_91 ( 0 , & V_19 -> V_26 ) & 0x1 ) )
V_218 |= V_17 -> V_74 ;
}
V_219 = V_2 -> V_205 & ~ V_218 ;
if ( F_153 ( V_2 ) )
V_2 -> V_206 = V_2 -> V_220 . V_168 ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
V_152 = 1 ;
for ( V_79 = V_2 -> V_101 ; V_79 <= V_2 -> V_100 ; V_79 ++ , V_152 <<= 1 ) {
if ( ! ( V_219 & V_152 ) )
continue;
V_221:
V_73 = F_267 ( V_79 , V_192 , V_5 , 0 ) ;
if ( ! V_73 ) {
V_219 &= ~ V_152 ;
} else {
F_108 ( & V_2 -> V_98 , V_8 ) ;
if ( F_213 ( V_79 ) &&
( V_2 -> V_205 & V_152 ) ) {
F_110 ( & V_2 -> V_98 ,
V_8 ) ;
F_147 ( 1 ) ;
if ( F_213 ( V_79 ) &&
( V_2 -> V_205 & V_152 ) )
goto V_221;
F_108 ( & V_2 -> V_98 ,
V_8 ) ;
}
if ( ! ( V_2 -> V_205 & V_152 ) )
V_219 &= ~ V_152 ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
}
V_218 |= V_219 ;
if ( V_218 )
F_256 ( V_5 , V_2 , V_218 , false ) ;
}
}
static void F_269 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_92 ;
unsigned long V_222 ;
unsigned long V_152 ;
struct V_1 * V_2 ;
struct V_1 * V_115 = F_46 ( V_5 ) ;
int V_73 ;
V_92 = F_103 () ;
V_222 = V_87 ;
for (; ; ) {
V_73 = F_173 (
V_5 -> V_208 ,
F_253 ( V_115 ) ,
V_92 ) ;
if ( V_73 > 0 )
return;
if ( V_73 < 0 ) {
F_270 ( V_5 -> V_208 ,
F_253 ( V_115 ) ) ;
return;
}
F_105 ( L_56 ,
V_5 -> V_30 ) ;
F_107 (rsp, rnp) {
( void ) F_271 ( V_2 ) ;
V_152 = 1 ;
for ( V_79 = V_2 -> V_101 ; V_79 <= V_2 -> V_100 ; V_79 ++ , V_152 <<= 1 ) {
struct V_16 * V_17 ;
if ( ! ( V_2 -> V_205 & V_152 ) )
continue;
V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
F_118 ( L_57 , V_79 ,
L_58 [ F_213 ( V_79 ) ] ,
L_59 [ ! ! ( V_17 -> V_74 & V_2 -> V_203 ) ] ,
L_60 [ ! ! ( V_17 -> V_74 & V_2 -> V_204 ) ] ) ;
}
V_152 <<= 1 ;
}
F_118 ( L_61 ,
V_87 - V_222 , V_5 -> V_198 ) ;
F_107 (rsp, rnp) {
V_152 = 1 ;
for ( V_79 = V_2 -> V_101 ; V_79 <= V_2 -> V_100 ; V_79 ++ , V_152 <<= 1 ) {
if ( ! ( V_2 -> V_205 & V_152 ) )
continue;
F_109 ( V_79 ) ;
}
}
V_92 = 3 * F_103 () + 3 ;
}
}
void F_233 ( void )
{
unsigned long V_11 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_14 ;
V_11 = F_249 ( V_5 ) ;
V_2 = F_260 ( V_5 , V_11 ) ;
if ( V_2 == NULL )
return;
F_247 ( V_5 ) ;
F_268 ( V_5 , F_265 ) ;
F_269 ( V_5 ) ;
F_248 ( V_5 ) ;
F_258 ( & V_2 -> V_210 ) ;
}
static int F_272 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_24 ;
V_17 -> V_223 ++ ;
F_122 ( V_5 , V_17 ) ;
if ( F_273 ( V_5 ) )
return 0 ;
if ( V_75 &&
V_17 -> V_121 && V_17 -> V_10 . V_12 . V_13 &&
V_17 -> V_120 == F_5 ( V_27 ) ) {
V_17 -> V_224 ++ ;
} else if ( V_17 -> V_121 &&
( ! V_17 -> V_10 . V_12 . V_13 ||
V_17 -> V_120 != F_5 ( V_27 ) ) ) {
V_17 -> V_225 ++ ;
return 1 ;
}
if ( F_45 ( V_17 ) ) {
V_17 -> V_226 ++ ;
return 1 ;
}
if ( F_48 ( V_5 , V_17 ) ) {
V_17 -> V_227 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_17 -> V_6 ) {
V_17 -> V_228 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_17 -> V_7 ||
F_27 ( F_2 ( V_17 -> V_81 ) ) ) {
V_17 -> V_229 ++ ;
return 1 ;
}
if ( F_274 ( V_17 ) ) {
V_17 -> V_230 ++ ;
return 1 ;
}
V_17 -> V_231 ++ ;
return 0 ;
}
static int F_204 ( void )
{
struct V_4 * V_5 ;
F_17 (rsp)
if ( F_272 ( V_5 , F_11 ( V_5 -> V_22 ) ) )
return 1 ;
return 0 ;
}
static bool V_61 F_275 ( bool * V_232 )
{
bool V_233 = true ;
bool V_234 = false ;
struct V_16 * V_17 ;
struct V_4 * V_5 ;
F_17 (rsp) {
V_17 = F_11 ( V_5 -> V_22 ) ;
if ( ! V_17 -> V_43 )
continue;
V_234 = true ;
if ( V_17 -> V_106 != V_17 -> V_158 || ! V_232 ) {
V_233 = false ;
break;
}
}
if ( V_232 )
* V_232 = V_233 ;
return V_234 ;
}
static void F_276 ( struct V_4 * V_5 , const char * V_11 ,
int V_79 , unsigned long V_199 )
{
F_277 ( V_5 -> V_30 , V_11 , V_79 ,
F_62 ( & V_5 -> V_235 ) , V_199 ) ;
}
static void F_278 ( struct V_167 * V_191 )
{
struct V_16 * V_17 = F_279 ( V_191 , struct V_16 , V_236 ) ;
struct V_4 * V_5 = V_17 -> V_5 ;
if ( F_280 ( & V_5 -> V_235 ) ) {
F_276 ( V_5 , L_62 , - 1 , V_5 -> V_237 ) ;
F_281 ( & V_5 -> V_238 ) ;
} else {
F_276 ( V_5 , L_63 , - 1 , V_5 -> V_237 ) ;
}
}
static void F_282 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_16 * V_17 = F_18 ( V_5 -> V_22 ) ;
F_276 ( V_5 , L_64 , - 1 , V_5 -> V_237 ) ;
F_60 ( & V_5 -> V_235 ) ;
V_5 -> V_239 ( & V_17 -> V_236 , F_278 ) ;
}
static void F_283 ( struct V_4 * V_5 )
{
int V_79 ;
struct V_16 * V_17 ;
unsigned long V_11 = F_245 ( & V_5 -> V_237 ) ;
F_276 ( V_5 , L_65 , - 1 , V_11 ) ;
F_264 ( & V_5 -> V_240 ) ;
if ( F_246 ( & V_5 -> V_237 , V_11 ) ) {
F_276 ( V_5 , L_66 , - 1 , V_5 -> V_237 ) ;
F_19 () ;
F_258 ( & V_5 -> V_240 ) ;
return;
}
F_243 ( & V_5 -> V_237 ) ;
F_276 ( V_5 , L_67 , - 1 , V_5 -> V_237 ) ;
F_284 ( & V_5 -> V_238 ) ;
F_285 ( & V_5 -> V_235 , 1 ) ;
F_286 () ;
F_116 (cpu) {
if ( ! F_213 ( V_79 ) && ! F_182 ( V_79 ) )
continue;
V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
if ( F_182 ( V_79 ) ) {
if ( ! F_287 ( V_5 , V_79 ) ) {
F_276 ( V_5 , L_68 , V_79 ,
V_5 -> V_237 ) ;
} else {
F_276 ( V_5 , L_69 , V_79 ,
V_5 -> V_237 ) ;
F_20 () ;
F_60 ( & V_5 -> V_235 ) ;
F_218 ( & V_17 -> V_236 ,
F_278 , V_5 , V_79 , 0 ) ;
}
} else if ( F_2 ( V_17 -> V_106 ) ) {
F_276 ( V_5 , L_70 , V_79 ,
V_5 -> V_237 ) ;
F_267 ( V_79 , F_282 , V_5 , 1 ) ;
} else {
F_276 ( V_5 , L_71 , V_79 ,
V_5 -> V_237 ) ;
}
}
F_288 () ;
if ( F_280 ( & V_5 -> V_235 ) )
F_281 ( & V_5 -> V_238 ) ;
F_289 ( & V_5 -> V_238 ) ;
F_276 ( V_5 , L_72 , - 1 , V_5 -> V_237 ) ;
F_244 ( & V_5 -> V_237 ) ;
F_258 ( & V_5 -> V_240 ) ;
}
void F_290 ( void )
{
F_283 ( & V_29 ) ;
}
void F_291 ( void )
{
F_283 ( & V_14 ) ;
}
static void F_152 ( struct V_1 * V_165 )
{
long V_152 ;
struct V_1 * V_2 = V_165 ;
for (; ; ) {
V_152 = V_2 -> V_74 ;
V_2 = V_2 -> V_155 ;
if ( V_2 == NULL )
return;
F_132 ( & V_2 -> V_98 ) ;
V_2 -> V_128 |= V_152 ;
F_135 ( & V_2 -> V_98 ) ;
}
}
static void T_7
F_292 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_8 ;
struct V_16 * V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
V_17 -> V_74 = 1UL << ( V_79 - V_17 -> V_24 -> V_101 ) ;
V_17 -> V_26 = & F_99 ( V_18 , V_79 ) ;
F_61 ( V_17 -> V_26 -> V_57 != V_70 ) ;
F_61 ( F_62 ( & V_17 -> V_26 -> V_26 ) != 1 ) ;
V_17 -> V_79 = V_79 ;
V_17 -> V_5 = V_5 ;
F_293 ( & V_17 -> V_210 ) ;
F_294 ( V_17 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
static void
F_295 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_8 ;
unsigned long V_152 ;
struct V_16 * V_17 = F_117 ( V_5 -> V_22 , V_79 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
V_17 -> V_178 = 0 ;
V_17 -> V_179 = V_5 -> V_94 ;
V_17 -> V_174 = V_174 ;
if ( ! V_17 -> V_43 )
F_126 ( V_17 ) ;
V_17 -> V_26 -> V_57 = V_70 ;
F_296 ( V_17 -> V_26 ) ;
F_285 ( & V_17 -> V_26 -> V_26 ,
( F_62 ( & V_17 -> V_26 -> V_26 ) & ~ 0x1 ) + 1 ) ;
F_135 ( & V_2 -> V_98 ) ;
V_2 = V_17 -> V_24 ;
V_152 = V_17 -> V_74 ;
F_132 ( & V_2 -> V_98 ) ;
F_133 () ;
V_2 -> V_3 |= V_152 ;
V_2 -> V_204 |= V_152 ;
if ( ! V_17 -> V_185 )
F_94 ( V_5 -> V_200 , F_2 ( V_5 -> V_200 ) + 1 ) ;
V_17 -> V_185 = true ;
V_17 -> V_7 = V_2 -> V_6 ;
V_17 -> V_6 = V_2 -> V_6 ;
V_17 -> V_10 . V_12 . V_13 = true ;
V_17 -> V_120 = F_99 ( V_27 , V_79 ) ;
V_17 -> V_121 = false ;
F_6 ( V_5 -> V_30 , V_17 -> V_7 , F_7 ( L_73 ) ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
static void F_297 ( int V_79 )
{
struct V_4 * V_5 ;
F_17 (rsp)
F_295 ( V_79 , V_5 ) ;
}
int F_298 ( struct V_241 * V_242 ,
unsigned long V_243 , void * V_244 )
{
long V_79 = ( long ) V_244 ;
struct V_16 * V_17 = F_117 ( V_28 -> V_22 , V_79 ) ;
struct V_1 * V_2 = V_17 -> V_24 ;
struct V_4 * V_5 ;
switch ( V_243 ) {
case V_245 :
case V_246 :
F_297 ( V_79 ) ;
F_299 ( V_79 ) ;
F_300 ( V_79 ) ;
break;
case V_247 :
case V_248 :
F_266 ( V_79 ) ;
F_190 ( V_2 , - 1 ) ;
break;
case V_249 :
F_190 ( V_2 , V_79 ) ;
break;
case V_250 :
case V_251 :
F_17 (rsp)
F_186 ( V_5 ) ;
break;
case V_252 :
F_87 () ;
F_10 ( & V_14 ,
F_11 ( V_14 . V_22 ) , true ) ;
F_88 () ;
F_17 (rsp) {
F_188 ( V_79 , V_5 ) ;
}
break;
case V_253 :
case V_254 :
case V_255 :
case V_256 :
F_17 (rsp) {
F_189 ( V_79 , V_5 ) ;
F_58 ( F_117 ( V_5 -> V_22 , V_79 ) ) ;
}
break;
default:
break;
}
return V_257 ;
}
static int F_301 ( struct V_241 * V_242 ,
unsigned long V_243 , void * V_244 )
{
switch ( V_243 ) {
case V_258 :
case V_259 :
if ( V_260 <= 256 )
F_302 () ;
break;
case V_261 :
case V_262 :
if ( V_260 <= 256 )
F_303 () ;
break;
default:
break;
}
return V_257 ;
}
static int T_7 F_304 ( void )
{
unsigned long V_8 ;
int V_263 = V_264 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_265 V_197 ;
struct V_60 * V_266 ;
if ( F_52 ( V_267 ) && V_264 < 1 )
V_264 = 1 ;
else if ( V_264 < 0 )
V_264 = 0 ;
else if ( V_264 > 99 )
V_264 = 99 ;
if ( V_264 != V_263 )
F_305 ( L_74 ,
V_264 , V_263 ) ;
V_75 = 1 ;
F_17 (rsp) {
V_266 = F_306 ( F_168 , V_5 , L_75 , V_5 -> V_30 ) ;
F_221 ( F_307 ( V_266 ) ) ;
V_2 = F_46 ( V_5 ) ;
F_108 ( & V_2 -> V_98 , V_8 ) ;
V_5 -> V_32 = V_266 ;
if ( V_264 ) {
V_197 . V_268 = V_264 ;
F_308 ( V_266 , V_269 , & V_197 ) ;
}
F_309 ( V_266 ) ;
F_110 ( & V_2 -> V_98 , V_8 ) ;
}
F_310 () ;
F_311 () ;
return 0 ;
}
void F_312 ( void )
{
F_171 ( F_230 () != 1 ) ;
F_171 ( F_313 () > 0 ) ;
V_270 = 1 ;
}
static void T_7 F_314 ( int * V_271 , const int * V_272 )
{
int V_50 ;
if ( V_273 ) {
V_271 [ V_274 - 1 ] = V_275 ;
for ( V_50 = V_274 - 2 ; V_50 >= 0 ; V_50 -- )
V_271 [ V_50 ] = V_276 ;
} else {
int V_277 ;
int V_278 ;
V_278 = V_260 ;
for ( V_50 = V_274 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_277 = V_272 [ V_50 ] ;
V_271 [ V_50 ] = ( V_278 + V_277 - 1 ) / V_277 ;
V_278 = V_277 ;
}
}
}
static void T_7 F_315 ( struct V_4 * V_5 ,
struct V_16 T_8 * V_22 )
{
static const char * const V_279 [] = V_280 ;
static const char * const V_281 [] = V_282 ;
static const char * const exp [] = V_283 ;
static T_9 V_284 = 0x1 ;
int V_272 [ V_285 ] ;
int V_271 [ V_285 ] ;
int V_286 = 1 ;
int V_50 ;
int V_91 ;
struct V_1 * V_2 ;
F_316 ( V_285 > F_317 ( V_279 ) ) ;
if ( V_274 <= 0 || V_274 > V_285 )
F_318 ( L_76 ) ;
for ( V_50 = 0 ; V_50 < V_274 ; V_50 ++ )
V_272 [ V_50 ] = V_287 [ V_50 ] ;
for ( V_50 = 1 ; V_50 < V_274 ; V_50 ++ )
V_5 -> V_113 [ V_50 ] = V_5 -> V_113 [ V_50 - 1 ] + V_272 [ V_50 - 1 ] ;
F_314 ( V_271 , V_272 ) ;
V_5 -> V_23 = V_284 ;
V_284 <<= 1 ;
for ( V_50 = V_274 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_286 *= V_271 [ V_50 ] ;
V_2 = V_5 -> V_113 [ V_50 ] ;
for ( V_91 = 0 ; V_91 < V_272 [ V_50 ] ; V_91 ++ , V_2 ++ ) {
F_319 ( & V_2 -> V_98 ) ;
F_320 ( & V_2 -> V_98 ,
& V_288 [ V_50 ] , V_279 [ V_50 ] ) ;
F_319 ( & V_2 -> V_183 ) ;
F_320 ( & V_2 -> V_183 ,
& V_289 [ V_50 ] , V_281 [ V_50 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_99 = 0 ;
V_2 -> V_128 = 0 ;
V_2 -> V_101 = V_91 * V_286 ;
V_2 -> V_100 = ( V_91 + 1 ) * V_286 - 1 ;
if ( V_2 -> V_100 >= V_260 )
V_2 -> V_100 = V_260 - 1 ;
if ( V_50 == 0 ) {
V_2 -> V_290 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_155 = NULL ;
} else {
V_2 -> V_290 = V_91 % V_271 [ V_50 - 1 ] ;
V_2 -> V_74 = 1UL << V_2 -> V_290 ;
V_2 -> V_155 = V_5 -> V_113 [ V_50 - 1 ] +
V_91 / V_271 [ V_50 - 1 ] ;
}
V_2 -> V_113 = V_50 ;
F_321 ( & V_2 -> V_220 ) ;
F_322 ( V_2 ) ;
F_293 ( & V_2 -> V_210 ) ;
F_320 ( & V_2 -> V_210 ,
& V_291 [ V_50 ] , exp [ V_50 ] ) ;
}
}
F_323 ( & V_5 -> V_119 ) ;
F_323 ( & V_5 -> V_208 ) ;
V_2 = V_5 -> V_113 [ V_274 - 1 ] ;
F_116 (i) {
while ( V_50 > V_2 -> V_100 )
V_2 ++ ;
F_117 ( V_5 -> V_22 , V_50 ) -> V_24 = V_2 ;
F_292 ( V_50 , V_5 ) ;
}
F_324 ( & V_5 -> V_292 , & V_293 ) ;
}
static void T_7 F_325 ( void )
{
T_10 V_294 ;
int V_50 ;
int V_295 [ V_285 ] ;
V_294 = V_296 + V_260 / V_297 ;
if ( V_146 == V_80 )
V_146 = V_294 ;
if ( V_107 == V_80 )
V_107 = V_294 ;
if ( V_275 == V_298 &&
V_260 == V_299 )
return;
F_41 ( L_77 ,
V_275 , V_260 ) ;
if ( V_275 < 2 ||
V_275 > sizeof( unsigned long ) * 8 ) {
V_275 = V_298 ;
F_171 ( 1 ) ;
return;
}
V_295 [ 0 ] = V_275 ;
for ( V_50 = 1 ; V_50 < V_285 ; V_50 ++ )
V_295 [ V_50 ] = V_295 [ V_50 - 1 ] * V_276 ;
if ( V_260 > V_295 [ V_285 - 1 ] ) {
V_275 = V_298 ;
F_171 ( 1 ) ;
return;
}
for ( V_50 = 0 ; V_260 > V_295 [ V_50 ] ; V_50 ++ ) {
}
V_274 = V_50 + 1 ;
for ( V_50 = 0 ; V_50 < V_274 ; V_50 ++ ) {
int V_300 = V_295 [ ( V_274 - 1 ) - V_50 ] ;
V_287 [ V_50 ] = F_326 ( V_260 , V_300 ) ;
}
V_124 = 0 ;
for ( V_50 = 0 ; V_50 < V_274 ; V_50 ++ )
V_124 += V_287 [ V_50 ] ;
}
static void T_7 F_327 ( struct V_4 * V_5 )
{
int V_113 = 0 ;
struct V_1 * V_2 ;
F_41 ( L_78 ) ;
F_41 ( L_79 ) ;
F_155 (rsp, rnp) {
if ( V_2 -> V_113 != V_113 ) {
F_118 ( L_80 ) ;
F_41 ( L_79 ) ;
V_113 = V_2 -> V_113 ;
}
F_118 ( L_81 , V_2 -> V_101 , V_2 -> V_100 , V_2 -> V_290 ) ;
}
F_118 ( L_80 ) ;
}
void T_7 F_328 ( void )
{
int V_79 ;
F_329 () ;
F_330 () ;
F_325 () ;
F_315 ( & V_29 , & V_15 ) ;
F_315 ( & V_14 , & V_9 ) ;
if ( V_301 )
F_327 ( & V_14 ) ;
F_331 () ;
F_332 ( V_189 , F_210 ) ;
F_333 ( F_298 , 0 ) ;
F_334 ( F_301 , 0 ) ;
F_335 (cpu)
F_298 ( NULL , V_245 , ( void * ) ( long ) V_79 ) ;
}
