static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( void )
{
if ( ! F_4 ( V_5 . V_6 ) ) {
F_5 ( F_6 ( L_1 ) ,
F_4 ( V_5 . V_4 ) ,
F_6 ( L_2 ) ) ;
F_7 ( V_5 . V_6 , 1 ) ;
}
}
void F_8 ( void )
{
if ( ! F_4 ( V_7 . V_6 ) ) {
F_5 ( F_6 ( L_3 ) ,
F_4 ( V_7 . V_4 ) ,
F_6 ( L_2 ) ) ;
F_7 ( V_7 . V_6 , 1 ) ;
}
}
static void F_9 ( void )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
struct V_1 * V_2 ;
F_10 ( V_8 ) ;
V_13 = F_11 ( V_14 ) ;
F_12 ( V_14 , 0 ) ;
F_13 (rsp) {
V_10 = F_14 ( V_2 -> V_15 ) ;
if ( ! ( V_13 & V_2 -> V_16 ) )
continue;
F_15 () ;
if ( F_2 ( V_10 -> V_17 -> V_3 ) !=
F_2 ( V_10 -> V_18 ) )
continue;
V_12 = F_16 ( & V_11 ) ;
F_17 () ;
F_18 ( 2 , & V_12 -> V_19 ) ;
F_19 () ;
break;
}
F_20 ( V_8 ) ;
}
void F_21 ( void )
{
F_22 ( F_6 ( L_4 ) ) ;
F_3 () ;
F_23 () ;
if ( F_24 ( F_11 ( V_14 ) ) )
F_9 () ;
F_22 ( F_6 ( L_5 ) ) ;
}
void F_25 ( void )
{
if ( F_24 ( F_11 ( V_14 ) ) )
F_9 () ;
F_26 ( V_20 ) ;
}
unsigned long F_27 ( void )
{
return V_21 -> V_4 ;
}
unsigned long F_28 ( void )
{
return V_22 . V_4 ;
}
unsigned long F_29 ( void )
{
return V_23 . V_4 ;
}
unsigned long F_30 ( void )
{
return V_21 -> V_3 ;
}
unsigned long F_31 ( void )
{
return V_22 . V_3 ;
}
unsigned long F_32 ( void )
{
return V_23 . V_3 ;
}
void F_33 ( void )
{
F_34 ( V_21 ) ;
}
void F_35 ( void )
{
F_34 ( & V_23 ) ;
}
void F_36 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp) {
F_37 ( L_6 ,
V_2 -> V_24 , V_2 -> V_25 , V_2 -> V_26 -> V_27 ) ;
}
}
void F_38 ( void )
{
V_28 ++ ;
V_29 = 0 ;
}
void F_39 ( enum V_30 V_31 , int * V_8 ,
unsigned long * V_4 , unsigned long * V_3 )
{
struct V_1 * V_2 = NULL ;
switch ( V_31 ) {
case V_32 :
V_2 = V_21 ;
break;
case V_33 :
V_2 = & V_23 ;
break;
case V_34 :
V_2 = & V_22 ;
break;
default:
break;
}
if ( V_2 != NULL ) {
* V_8 = F_2 ( V_2 -> V_35 ) ;
* V_4 = F_2 ( V_2 -> V_4 ) ;
* V_3 = F_2 ( V_2 -> V_3 ) ;
return;
}
* V_8 = 0 ;
* V_4 = 0 ;
* V_3 = 0 ;
}
void F_40 ( unsigned long V_36 )
{
V_29 ++ ;
}
void F_41 ( void )
{
F_34 ( & V_22 ) ;
}
static int
F_42 ( struct V_9 * V_10 )
{
return & V_10 -> V_37 != V_10 -> V_38 [ V_39 ] &&
V_10 -> V_38 [ V_39 ] != NULL ;
}
static struct V_40 * F_43 ( struct V_1 * V_2 )
{
return & V_2 -> V_41 [ 0 ] ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_40 * V_42 = F_43 ( V_2 ) ;
int V_43 = ( F_2 ( V_42 -> V_3 ) + 1 ) & 0x1 ;
int * V_44 = & V_42 -> V_45 [ V_43 ] ;
return F_2 ( * V_44 ) ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_46 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_44 ( V_2 ) )
return 1 ;
if ( ! V_10 -> V_38 [ V_47 ] )
return 0 ;
if ( * V_10 -> V_38 [ V_48 ] )
return 1 ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ )
if ( V_10 -> V_38 [ V_46 - 1 ] != V_10 -> V_38 [ V_46 ] &&
F_46 ( F_2 ( V_2 -> V_3 ) ,
V_10 -> V_50 [ V_46 ] ) )
return 1 ;
return 0 ;
}
static void F_47 ( long long V_51 , bool V_52 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_16 ( & V_11 ) ;
F_48 ( F_6 ( L_7 ) , V_51 , V_12 -> V_53 ) ;
if ( ! V_52 && ! F_49 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_50 ( F_51 () ) ;
F_48 ( F_6 ( L_8 ) , V_51 , 0 ) ;
F_52 ( V_57 ) ;
F_53 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
F_13 (rsp) {
V_10 = F_16 ( V_2 -> V_15 ) ;
F_54 ( V_10 ) ;
}
F_55 () ;
F_17 () ;
F_56 ( & V_12 -> V_19 ) ;
F_19 () ;
F_57 ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ;
F_59 () ;
F_60 ( ! F_61 ( & V_60 ) ,
L_10 ) ;
F_60 ( ! F_61 ( & V_61 ) ,
L_11 ) ;
F_60 ( ! F_61 ( & V_62 ) ,
L_12 ) ;
}
static void F_62 ( bool V_52 )
{
long long V_51 ;
struct V_11 * V_12 ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
F_57 ( ( V_51 & V_63 ) == 0 ) ;
if ( ( V_51 & V_63 ) == V_64 ) {
V_12 -> V_53 = 0 ;
F_47 ( V_51 , V_52 ) ;
} else {
V_12 -> V_53 -= V_64 ;
}
}
void F_63 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_62 ( false ) ;
F_64 ( 0 ) ;
F_20 ( V_8 ) ;
}
void F_65 ( void )
{
F_62 ( 1 ) ;
}
void F_66 ( void )
{
unsigned long V_8 ;
long long V_51 ;
struct V_11 * V_12 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
V_12 -> V_53 -- ;
F_57 ( V_12 -> V_53 < 0 ) ;
if ( V_12 -> V_53 )
F_48 ( F_6 ( L_13 ) , V_51 , V_12 -> V_53 ) ;
else
F_47 ( V_51 , true ) ;
F_64 ( 1 ) ;
F_20 ( V_8 ) ;
}
static void F_67 ( long long V_51 , int V_52 )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
F_68 () ;
F_17 () ;
F_56 ( & V_12 -> V_19 ) ;
F_19 () ;
F_57 ( ! ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ) ;
F_69 () ;
F_48 ( F_6 ( L_14 ) , V_51 , V_12 -> V_53 ) ;
if ( ! V_52 && ! F_49 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_50 ( F_51 () ) ;
F_48 ( F_6 ( L_15 ) ,
V_51 , V_12 -> V_53 ) ;
F_52 ( V_57 ) ;
F_53 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
}
static void F_70 ( bool V_52 )
{
struct V_11 * V_12 ;
long long V_51 ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
F_57 ( V_51 < 0 ) ;
if ( V_51 & V_63 ) {
V_12 -> V_53 += V_64 ;
} else {
V_12 -> V_53 = V_65 ;
F_67 ( V_51 , V_52 ) ;
}
}
void F_71 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_70 ( false ) ;
F_72 ( 0 ) ;
F_20 ( V_8 ) ;
}
void F_73 ( void )
{
F_70 ( 1 ) ;
}
void F_74 ( void )
{
unsigned long V_8 ;
struct V_11 * V_12 ;
long long V_51 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
V_12 -> V_53 ++ ;
F_57 ( V_12 -> V_53 == 0 ) ;
if ( V_51 )
F_48 ( F_6 ( L_16 ) , V_51 , V_12 -> V_53 ) ;
else
F_67 ( V_51 , true ) ;
F_72 ( 1 ) ;
F_20 ( V_8 ) ;
}
void F_75 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
int V_66 = 2 ;
F_57 ( V_12 -> V_67 < 0 ) ;
if ( ! ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ) {
F_17 () ;
F_56 ( & V_12 -> V_19 ) ;
F_19 () ;
F_57 ( ! ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ) ;
V_66 = 1 ;
}
V_12 -> V_67 += V_66 ;
F_76 () ;
}
void F_77 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
F_57 ( V_12 -> V_67 <= 0 ) ;
F_57 ( ! ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ) ;
if ( V_12 -> V_67 != 1 ) {
V_12 -> V_67 -= 2 ;
return;
}
V_12 -> V_67 = 0 ;
F_17 () ;
F_56 ( & V_12 -> V_19 ) ;
F_19 () ;
F_57 ( F_58 ( & V_12 -> V_19 ) & 0x1 ) ;
}
bool T_2 F_78 ( void )
{
return F_58 ( F_16 ( & V_11 . V_19 ) ) & 0x1 ;
}
bool T_2 F_79 ( void )
{
bool V_68 ;
F_80 () ;
V_68 = F_78 () ;
F_81 () ;
return V_68 ;
}
bool F_82 ( void )
{
struct V_9 * V_10 ;
struct V_40 * V_42 ;
bool V_68 ;
if ( F_83 () )
return true ;
F_80 () ;
V_10 = F_16 ( & V_5 ) ;
V_42 = V_10 -> V_17 ;
V_68 = ( V_10 -> V_69 & V_42 -> V_70 ) ||
! V_71 ;
F_81 () ;
return V_68 ;
}
static int F_84 ( void )
{
return F_4 ( V_11 . V_53 ) <= 1 ;
}
static int F_85 ( struct V_9 * V_10 ,
bool * V_72 , unsigned long * V_73 )
{
V_10 -> V_74 = F_86 ( 0 , & V_10 -> V_19 -> V_19 ) ;
F_87 ( V_10 , V_72 , V_73 ) ;
if ( ( V_10 -> V_74 & 0x1 ) == 0 ) {
F_88 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_75 , F_6 ( L_17 ) ) ;
return 1 ;
} else {
if ( F_46 ( F_2 ( V_10 -> V_4 ) + V_76 / 4 ,
V_10 -> V_17 -> V_4 ) )
F_2 ( V_10 -> V_77 ) = true ;
return 0 ;
}
}
static int F_89 ( struct V_9 * V_10 ,
bool * V_72 , unsigned long * V_73 )
{
unsigned int V_78 ;
int * V_79 ;
unsigned int V_80 ;
V_78 = ( unsigned int ) F_86 ( 0 , & V_10 -> V_19 -> V_19 ) ;
V_80 = ( unsigned int ) V_10 -> V_74 ;
if ( ( V_78 & 0x1 ) == 0 || F_90 ( V_78 , V_80 + 2 ) ) {
F_88 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_75 , F_6 ( L_17 ) ) ;
V_10 -> V_81 ++ ;
return 1 ;
}
if ( F_91 ( V_10 -> V_2 -> V_82 + 2 , V_83 ) )
return 0 ;
F_76 () ;
if ( F_92 ( V_10 -> V_75 ) ) {
F_88 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_75 , F_6 ( L_18 ) ) ;
V_10 -> V_84 ++ ;
return 1 ;
}
V_79 = & F_93 ( V_14 , V_10 -> V_75 ) ;
if ( F_91 ( V_83 ,
V_10 -> V_2 -> V_82 + V_85 ) ||
F_91 ( V_83 , V_10 -> V_2 -> V_86 ) ) {
if ( ! ( F_2 ( * V_79 ) & V_10 -> V_2 -> V_16 ) ) {
F_2 ( V_10 -> V_18 ) =
F_2 ( V_10 -> V_17 -> V_3 ) ;
F_15 () ;
F_2 ( * V_79 ) =
F_2 ( * V_79 ) + V_10 -> V_2 -> V_16 ;
F_94 ( V_10 -> V_75 ) ;
V_10 -> V_2 -> V_86 += 5 ;
} else if ( F_91 ( V_83 , V_10 -> V_2 -> V_86 ) ) {
F_94 ( V_10 -> V_75 ) ;
V_10 -> V_2 -> V_86 += 5 ;
}
}
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
unsigned long V_87 = V_83 ;
unsigned long j1 ;
V_2 -> V_82 = V_87 ;
F_96 () ;
j1 = F_97 () ;
F_2 ( V_2 -> V_88 ) = V_87 + j1 ;
V_2 -> V_86 = V_87 + j1 / 2 ;
V_2 -> V_89 = F_2 ( V_2 -> V_90 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_91 ;
unsigned long V_87 ;
V_87 = V_83 ;
V_91 = F_2 ( V_2 -> V_92 ) ;
if ( V_87 - V_91 > 2 * V_93 )
F_99 ( L_19 ,
V_2 -> V_24 , V_87 - V_91 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_75 ;
unsigned long V_8 ;
struct V_40 * V_42 ;
F_101 (rsp, rnp) {
F_102 ( & V_42 -> V_94 , V_8 ) ;
if ( V_42 -> V_95 != 0 ) {
for ( V_75 = 0 ; V_75 <= V_42 -> V_96 - V_42 -> V_97 ; V_75 ++ )
if ( V_42 -> V_95 & ( 1UL << V_75 ) )
F_103 ( V_42 -> V_97 + V_75 ) ;
}
F_104 ( & V_42 -> V_94 , V_8 ) ;
}
}
static void F_105 ( struct V_1 * V_2 , unsigned long V_4 )
{
int V_75 ;
long V_98 ;
unsigned long V_8 ;
unsigned long V_91 ;
unsigned long V_87 ;
int V_99 = 0 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
long V_100 = 0 ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
V_98 = V_83 - F_2 ( V_2 -> V_88 ) ;
if ( V_98 < V_101 || ! F_1 ( V_2 ) ) {
F_104 ( & V_42 -> V_94 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_88 ) = V_83 + 3 * F_97 () + 3 ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
F_99 ( L_20 ,
V_2 -> V_24 ) ;
F_106 () ;
F_101 (rsp, rnp) {
F_102 ( & V_42 -> V_94 , V_8 ) ;
V_99 += F_107 ( V_42 ) ;
if ( V_42 -> V_95 != 0 ) {
for ( V_75 = 0 ; V_75 <= V_42 -> V_96 - V_42 -> V_97 ; V_75 ++ )
if ( V_42 -> V_95 & ( 1UL << V_75 ) ) {
F_108 ( V_2 ,
V_42 -> V_97 + V_75 ) ;
V_99 ++ ;
}
}
F_104 ( & V_42 -> V_94 , V_8 ) ;
}
F_109 () ;
F_110 (cpu)
V_100 += F_111 ( V_2 -> V_15 , V_75 ) -> V_102 ;
F_112 ( L_21 ,
F_51 () , ( long ) ( V_83 - V_2 -> V_82 ) ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_100 ) ;
if ( V_99 ) {
F_100 ( V_2 ) ;
} else {
if ( F_2 ( V_2 -> V_4 ) != V_4 ||
F_2 ( V_2 -> V_3 ) == V_4 ) {
F_99 ( L_22 ) ;
} else {
V_87 = V_83 ;
V_91 = F_2 ( V_2 -> V_92 ) ;
F_99 ( L_23 ,
V_2 -> V_24 , V_87 - V_91 , V_87 , V_91 ,
V_103 ) ;
F_113 ( V_54 ) ;
}
}
F_114 ( V_2 ) ;
F_98 ( V_2 ) ;
F_34 ( V_2 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
int V_75 ;
unsigned long V_8 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
long V_100 = 0 ;
F_99 ( L_24 , V_2 -> V_24 ) ;
F_106 () ;
F_108 ( V_2 , F_51 () ) ;
F_109 () ;
F_110 (cpu)
V_100 += F_111 ( V_2 -> V_15 , V_75 ) -> V_102 ;
F_112 ( L_25 ,
V_83 - V_2 -> V_82 ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_100 ) ;
F_98 ( V_2 ) ;
F_100 ( V_2 ) ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
if ( F_91 ( V_83 , F_2 ( V_2 -> V_88 ) ) )
F_2 ( V_2 -> V_88 ) = V_83 +
3 * F_97 () + 3 ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
F_94 ( F_51 () ) ;
}
static void F_116 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_104 ;
unsigned long V_87 ;
unsigned long V_105 ;
struct V_40 * V_42 ;
if ( V_106 || ! F_1 ( V_2 ) )
return;
V_87 = V_83 ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_117 () ;
V_105 = F_2 ( V_2 -> V_88 ) ;
F_117 () ;
V_104 = F_2 ( V_2 -> V_82 ) ;
F_117 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_91 ( V_3 , V_4 ) ||
F_46 ( V_87 , V_105 ) ||
F_91 ( V_104 , V_105 ) )
return;
V_42 = V_10 -> V_17 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_42 -> V_95 ) & V_10 -> V_69 ) ) {
F_115 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_91 ( V_87 , V_105 + V_101 ) ) {
F_105 ( V_2 , V_4 ) ;
}
}
void F_118 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_2 ( V_2 -> V_88 ) = V_83 + V_76 / 2 ;
}
static void F_119 ( struct V_9 * V_10 )
{
int V_46 ;
if ( F_120 ( V_10 ) )
return;
V_10 -> V_37 = NULL ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
V_10 -> V_38 [ V_46 ] = & V_10 -> V_37 ;
}
static unsigned long F_121 ( struct V_1 * V_2 ,
struct V_40 * V_42 )
{
if ( F_43 ( V_2 ) == V_42 && V_42 -> V_4 == V_42 -> V_3 )
return V_42 -> V_3 + 1 ;
return V_42 -> V_3 + 2 ;
}
static void F_122 ( struct V_40 * V_42 , struct V_9 * V_10 ,
unsigned long V_108 , const char * V_109 )
{
F_123 ( V_10 -> V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_3 , V_108 , V_42 -> V_110 ,
V_42 -> V_97 , V_42 -> V_96 , V_109 ) ;
}
static bool V_56
F_124 ( struct V_40 * V_42 , struct V_9 * V_10 ,
unsigned long * V_111 )
{
unsigned long V_108 ;
int V_46 ;
bool V_68 = false ;
struct V_40 * V_112 = F_43 ( V_10 -> V_2 ) ;
V_108 = F_121 ( V_10 -> V_2 , V_42 ) ;
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_26 ) ) ;
if ( V_42 -> V_45 [ V_108 & 0x1 ] ) {
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_27 ) ) ;
goto V_113;
}
if ( V_42 -> V_4 != V_42 -> V_3 ||
F_2 ( V_112 -> V_4 ) != F_2 ( V_112 -> V_3 ) ) {
V_42 -> V_45 [ V_108 & 0x1 ] ++ ;
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_28 ) ) ;
goto V_113;
}
if ( V_42 != V_112 ) {
F_125 ( & V_112 -> V_94 ) ;
F_126 () ;
}
V_108 = F_121 ( V_10 -> V_2 , V_112 ) ;
for ( V_46 = V_39 ; V_46 < V_47 ; V_46 ++ )
if ( F_46 ( V_108 , V_10 -> V_50 [ V_46 ] ) )
V_10 -> V_50 [ V_46 ] = V_108 ;
if ( V_112 -> V_45 [ V_108 & 0x1 ] ) {
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_29 ) ) ;
goto V_114;
}
V_112 -> V_45 [ V_108 & 0x1 ] ++ ;
if ( V_112 -> V_4 != V_112 -> V_3 ) {
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_30 ) ) ;
} else {
F_122 ( V_42 , V_10 , V_108 , F_6 ( L_31 ) ) ;
V_68 = F_127 ( V_10 -> V_2 , V_112 , V_10 ) ;
}
V_114:
if ( V_42 != V_112 )
F_128 ( & V_112 -> V_94 ) ;
V_113:
if ( V_111 != NULL )
* V_111 = V_108 ;
return V_68 ;
}
static int F_129 ( struct V_1 * V_2 , struct V_40 * V_42 )
{
int V_108 = V_42 -> V_3 ;
int V_115 ;
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
F_130 ( V_2 , V_42 ) ;
V_42 -> V_45 [ V_108 & 0x1 ] = 0 ;
V_115 = V_42 -> V_45 [ ( V_108 + 1 ) & 0x1 ] ;
F_122 ( V_42 , V_10 , V_108 ,
V_115 ? F_6 ( L_32 ) : F_6 ( L_33 ) ) ;
return V_115 ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_54 == V_2 -> V_26 ||
! F_2 ( V_2 -> V_35 ) ||
! V_2 -> V_26 )
return;
F_132 ( & V_2 -> V_116 ) ;
}
static bool F_133 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
unsigned long V_108 ;
int V_46 ;
bool V_68 ;
if ( ! V_10 -> V_38 [ V_47 ] || ! * V_10 -> V_38 [ V_39 ] )
return false ;
V_108 = F_121 ( V_2 , V_42 ) ;
for ( V_46 = V_47 - 1 ; V_46 > V_39 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] != V_10 -> V_38 [ V_46 - 1 ] &&
! F_91 ( V_10 -> V_50 [ V_46 ] , V_108 ) )
break;
if ( ++ V_46 >= V_47 )
return false ;
for (; V_46 <= V_47 ; V_46 ++ ) {
V_10 -> V_38 [ V_46 ] = V_10 -> V_38 [ V_47 ] ;
V_10 -> V_50 [ V_46 ] = V_108 ;
}
V_68 = F_124 ( V_42 , V_10 , NULL ) ;
if ( ! * V_10 -> V_38 [ V_49 ] )
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_34 ) ) ;
else
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_35 ) ) ;
return V_68 ;
}
static bool F_134 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
int V_46 , V_87 ;
if ( ! V_10 -> V_38 [ V_47 ] || ! * V_10 -> V_38 [ V_39 ] )
return false ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_46 ( V_42 -> V_3 , V_10 -> V_50 [ V_46 ] ) )
break;
V_10 -> V_38 [ V_39 ] = V_10 -> V_38 [ V_46 ] ;
}
for ( V_87 = V_49 ; V_87 < V_46 ; V_87 ++ )
V_10 -> V_38 [ V_87 ] = V_10 -> V_38 [ V_39 ] ;
for ( V_87 = V_49 ; V_46 < V_47 ; V_46 ++ , V_87 ++ ) {
if ( V_10 -> V_38 [ V_87 ] == V_10 -> V_38 [ V_47 ] )
break;
V_10 -> V_38 [ V_87 ] = V_10 -> V_38 [ V_46 ] ;
V_10 -> V_50 [ V_87 ] = V_10 -> V_50 [ V_46 ] ;
}
return F_133 ( V_2 , V_42 , V_10 ) ;
}
static bool F_135 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
bool V_68 ;
if ( V_10 -> V_3 == V_42 -> V_3 &&
! F_24 ( F_2 ( V_10 -> V_77 ) ) ) {
V_68 = F_133 ( V_2 , V_42 , V_10 ) ;
} else {
V_68 = F_134 ( V_2 , V_42 , V_10 ) ;
V_10 -> V_3 = V_42 -> V_3 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_36 ) ) ;
}
if ( V_10 -> V_4 != V_42 -> V_4 || F_24 ( F_2 ( V_10 -> V_77 ) ) ) {
V_10 -> V_4 = V_42 -> V_4 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_37 ) ) ;
V_10 -> V_6 = 0 ;
V_10 -> V_117 = F_4 ( V_20 ) ;
V_10 -> V_118 = ! ! ( V_42 -> V_95 & V_10 -> V_69 ) ;
F_136 ( V_10 ) ;
F_2 ( V_10 -> V_77 ) = false ;
}
return V_68 ;
}
static void F_137 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
bool V_119 ;
struct V_40 * V_42 ;
F_10 ( V_8 ) ;
V_42 = V_10 -> V_17 ;
if ( ( V_10 -> V_4 == F_2 ( V_42 -> V_4 ) &&
V_10 -> V_3 == F_2 ( V_42 -> V_3 ) &&
! F_24 ( F_2 ( V_10 -> V_77 ) ) ) ||
! F_138 ( & V_42 -> V_94 ) ) {
F_20 ( V_8 ) ;
return;
}
F_126 () ;
V_119 = F_135 ( V_2 , V_42 , V_10 ) ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
if ( V_119 )
F_131 ( V_2 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
F_2 ( V_2 -> V_92 ) = V_83 ;
F_140 () ;
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
if ( ! F_2 ( V_2 -> V_35 ) ) {
F_142 ( & V_42 -> V_94 ) ;
return 0 ;
}
F_2 ( V_2 -> V_35 ) = 0 ;
if ( F_57 ( F_1 ( V_2 ) ) ) {
F_142 ( & V_42 -> V_94 ) ;
return 0 ;
}
F_95 ( V_2 ) ;
F_143 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_24 , V_2 -> V_4 , F_6 ( L_38 ) ) ;
F_142 ( & V_42 -> V_94 ) ;
F_144 ( & V_2 -> V_120 ) ;
F_126 () ;
F_145 (rsp, rnp) {
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
V_10 = F_16 ( V_2 -> V_15 ) ;
F_146 ( V_42 ) ;
V_42 -> V_95 = V_42 -> V_70 ;
F_2 ( V_42 -> V_4 ) = V_2 -> V_4 ;
F_57 ( V_42 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_3 ;
if ( V_42 == V_10 -> V_17 )
( void ) F_135 ( V_2 , V_42 , V_10 ) ;
F_147 ( V_42 ) ;
F_148 ( V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_110 , V_42 -> V_97 ,
V_42 -> V_96 , V_42 -> V_95 ) ;
F_142 ( & V_42 -> V_94 ) ;
F_149 () ;
F_2 ( V_2 -> V_92 ) = V_83 ;
}
F_150 ( & V_2 -> V_120 ) ;
return 1 ;
}
static int F_151 ( struct V_1 * V_2 , int V_121 )
{
int V_122 = V_121 ;
bool V_72 = false ;
unsigned long V_73 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
F_2 ( V_2 -> V_92 ) = V_83 ;
V_2 -> V_90 ++ ;
if ( V_122 == V_123 ) {
if ( F_152 ( V_2 ) ) {
V_72 = true ;
V_73 = V_83 - V_76 / 4 ;
}
F_153 ( V_2 , F_85 ,
& V_72 , & V_73 ) ;
F_154 ( V_2 , V_72 , V_73 ) ;
V_122 = V_124 ;
} else {
V_72 = false ;
F_153 ( V_2 , F_89 , & V_72 , & V_73 ) ;
}
if ( F_2 ( V_2 -> V_35 ) & V_125 ) {
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
F_2 ( V_2 -> V_35 ) =
F_2 ( V_2 -> V_35 ) & ~ V_125 ;
F_142 ( & V_42 -> V_94 ) ;
}
return V_122 ;
}
static void F_155 ( struct V_1 * V_2 )
{
unsigned long V_126 ;
bool V_127 = false ;
int V_128 = 0 ;
struct V_9 * V_10 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
F_2 ( V_2 -> V_92 ) = V_83 ;
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
V_126 = V_83 - V_2 -> V_82 ;
if ( V_126 > V_2 -> V_129 )
V_2 -> V_129 = V_126 ;
F_142 ( & V_42 -> V_94 ) ;
F_145 (rsp, rnp) {
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_4 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( V_42 == V_10 -> V_17 )
V_127 = F_135 ( V_2 , V_42 , V_10 ) || V_127 ;
V_128 += F_129 ( V_2 , V_42 ) ;
F_142 ( & V_42 -> V_94 ) ;
F_149 () ;
F_2 ( V_2 -> V_92 ) = V_83 ;
}
V_42 = F_43 ( V_2 ) ;
F_141 ( & V_42 -> V_94 ) ;
F_126 () ;
F_156 ( V_42 , V_128 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_24 , V_2 -> V_3 , F_6 ( L_39 ) ) ;
V_2 -> V_122 = V_130 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
V_127 = F_134 ( V_2 , V_42 , V_10 ) || V_127 ;
if ( V_127 || F_45 ( V_2 , V_10 ) ) {
F_2 ( V_2 -> V_35 ) = V_131 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
}
F_142 ( & V_42 -> V_94 ) ;
}
static int T_3 F_157 ( void * V_132 )
{
int V_122 ;
int V_133 ;
unsigned long V_87 ;
int V_68 ;
struct V_1 * V_2 = V_132 ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_2 -> V_25 = V_134 ;
F_158 ( V_2 -> V_116 ,
F_2 ( V_2 -> V_35 ) &
V_131 ) ;
if ( F_139 ( V_2 ) )
break;
F_149 () ;
F_2 ( V_2 -> V_92 ) = V_83 ;
F_159 ( F_160 ( V_54 ) ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
}
V_122 = V_123 ;
V_87 = V_135 ;
if ( V_87 > V_93 ) {
V_87 = V_93 ;
V_135 = V_93 ;
}
V_68 = 0 ;
for (; ; ) {
if ( ! V_68 )
V_2 -> V_136 = V_83 + V_87 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
V_2 -> V_25 = V_137 ;
V_68 = F_161 ( V_2 -> V_116 ,
( ( V_133 = F_2 ( V_2 -> V_35 ) ) &
V_125 ) ||
( ! F_2 ( V_42 -> V_95 ) &&
! F_162 ( V_42 ) ) ,
V_87 ) ;
if ( ! F_2 ( V_42 -> V_95 ) &&
! F_162 ( V_42 ) )
break;
if ( F_91 ( V_83 , V_2 -> V_136 ) ||
( V_133 & V_125 ) ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_44 ) ) ;
V_122 = F_151 ( V_2 , V_122 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_45 ) ) ;
F_149 () ;
F_2 ( V_2 -> V_92 ) = V_83 ;
} else {
F_149 () ;
F_2 ( V_2 -> V_92 ) = V_83 ;
F_159 ( F_160 ( V_54 ) ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_46 ) ) ;
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
F_155 ( V_2 ) ;
}
}
static bool
F_127 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_26 || ! F_45 ( V_2 , V_10 ) ) {
return false ;
}
F_2 ( V_2 -> V_35 ) = V_131 ;
F_5 ( V_2 -> V_24 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
return true ;
}
static bool F_163 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
bool V_68 = false ;
V_68 = F_134 ( V_2 , V_42 , V_10 ) || V_68 ;
V_68 = F_127 ( V_2 , V_42 , V_10 ) || V_68 ;
return V_68 ;
}
static void F_164 ( struct V_1 * V_2 , unsigned long V_8 )
__releases( rcu_get_root( V_2 )->lock
static void
F_165 ( unsigned long V_138 , struct V_1 * V_2 ,
struct V_40 * V_42 , unsigned long V_8 )
__releases( V_42 -> V_94 )
{
struct V_40 * V_139 ;
for (; ; ) {
if ( ! ( V_42 -> V_95 & V_138 ) ) {
F_104 ( & V_42 -> V_94 , V_8 ) ;
return;
}
V_42 -> V_95 &= ~ V_138 ;
F_166 ( V_2 -> V_24 , V_42 -> V_4 ,
V_138 , V_42 -> V_95 , V_42 -> V_110 ,
V_42 -> V_97 , V_42 -> V_96 ,
! ! V_42 -> V_140 ) ;
if ( V_42 -> V_95 != 0 || F_162 ( V_42 ) ) {
F_104 ( & V_42 -> V_94 , V_8 ) ;
return;
}
V_138 = V_42 -> V_69 ;
if ( V_42 -> V_141 == NULL ) {
break;
}
F_104 ( & V_42 -> V_94 , V_8 ) ;
V_139 = V_42 ;
V_42 = V_42 -> V_141 ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
F_126 () ;
F_57 ( V_139 -> V_95 ) ;
}
F_164 ( V_2 , V_8 ) ;
}
static void
F_167 ( int V_75 , struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
unsigned long V_138 ;
bool V_119 ;
struct V_40 * V_42 ;
V_42 = V_10 -> V_17 ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
F_126 () ;
if ( ( V_10 -> V_6 == 0 &&
V_10 -> V_117 == F_4 ( V_20 ) ) ||
V_10 -> V_4 != V_42 -> V_4 || V_42 -> V_3 == V_42 -> V_4 ||
V_10 -> V_77 ) {
V_10 -> V_6 = 0 ;
V_10 -> V_117 = F_4 ( V_20 ) ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
return;
}
V_138 = V_10 -> V_69 ;
if ( ( V_42 -> V_95 & V_138 ) == 0 ) {
F_104 ( & V_42 -> V_94 , V_8 ) ;
} else {
V_10 -> V_118 = 0 ;
V_119 = F_133 ( V_2 , V_42 , V_10 ) ;
F_165 ( V_138 , V_2 , V_42 , V_8 ) ;
if ( V_119 )
F_131 ( V_2 ) ;
}
}
static void
F_168 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_137 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_118 )
return;
if ( ! V_10 -> V_6 &&
V_10 -> V_117 == F_4 ( V_20 ) )
return;
F_167 ( V_10 -> V_75 , V_2 , V_10 ) ;
}
static void
F_169 ( int V_75 , struct V_1 * V_2 ,
struct V_40 * V_42 , struct V_9 * V_10 )
{
if ( F_170 ( V_10 -> V_75 ) )
return;
if ( V_10 -> V_37 != NULL ) {
V_2 -> V_142 += V_10 -> V_142 ;
V_2 -> V_102 += V_10 -> V_102 ;
V_10 -> V_143 += V_10 -> V_102 ;
V_10 -> V_142 = 0 ;
F_2 ( V_10 -> V_102 ) = 0 ;
}
if ( * V_10 -> V_38 [ V_39 ] != NULL ) {
* V_2 -> V_144 = * V_10 -> V_38 [ V_39 ] ;
V_2 -> V_144 = V_10 -> V_38 [ V_47 ] ;
* V_10 -> V_38 [ V_39 ] = NULL ;
}
if ( V_10 -> V_37 != NULL ) {
* V_2 -> V_145 = V_10 -> V_37 ;
V_2 -> V_145 = V_10 -> V_38 [ V_39 ] ;
}
F_119 ( V_10 ) ;
}
static void F_171 ( struct V_1 * V_2 , unsigned long V_8 )
{
int V_46 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
if ( F_172 ( V_2 , V_10 , V_8 ) )
return;
V_10 -> V_142 += V_2 -> V_142 ;
V_10 -> V_102 += V_2 -> V_102 ;
V_10 -> V_146 += V_2 -> V_102 ;
if ( V_2 -> V_142 != V_2 -> V_102 )
F_173 () ;
V_2 -> V_142 = 0 ;
V_2 -> V_102 = 0 ;
if ( V_2 -> V_147 != NULL ) {
* V_2 -> V_145 = * V_10 -> V_38 [ V_39 ] ;
* V_10 -> V_38 [ V_39 ] = V_2 -> V_147 ;
for ( V_46 = V_107 - 1 ; V_46 >= V_39 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] == V_10 -> V_38 [ V_39 ] )
V_10 -> V_38 [ V_46 ] = V_2 -> V_145 ;
V_2 -> V_147 = NULL ;
V_2 -> V_145 = & V_2 -> V_147 ;
}
if ( V_2 -> V_148 != NULL ) {
* V_10 -> V_38 [ V_47 ] = V_2 -> V_148 ;
V_10 -> V_38 [ V_47 ] = V_2 -> V_144 ;
V_2 -> V_148 = NULL ;
V_2 -> V_144 = & V_2 -> V_148 ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
F_175 (unsigned long mask) ;
F_175 ( struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ) ;
F_175 ( struct V_40 * V_42 = V_10 -> V_17 ) ;
F_175 ( V_138 = V_10 -> V_69 ) ;
F_5 ( V_2 -> V_24 ,
V_42 -> V_4 + 1 - ! ! ( V_42 -> V_95 & V_138 ) ,
F_6 ( L_47 ) ) ;
}
static void F_176 ( struct V_40 * V_149 )
{
long V_138 ;
struct V_40 * V_42 = V_149 ;
if ( V_42 -> V_70 || F_177 ( V_42 ) )
return;
for (; ; ) {
V_138 = V_42 -> V_69 ;
V_42 = V_42 -> V_141 ;
if ( ! V_42 )
break;
F_125 ( & V_42 -> V_94 ) ;
F_126 () ;
V_42 -> V_70 &= ~ V_138 ;
if ( V_42 -> V_70 ) {
F_128 ( & V_42 -> V_94 ) ;
return;
}
F_128 ( & V_42 -> V_94 ) ;
}
}
static void F_178 ( int V_75 , struct V_1 * V_2 )
{
unsigned long V_8 ;
struct V_9 * V_10 = F_111 ( V_2 -> V_15 , V_75 ) ;
struct V_40 * V_42 = V_10 -> V_17 ;
F_179 ( V_42 , - 1 ) ;
F_144 ( & V_2 -> V_120 ) ;
F_102 ( & V_2 -> V_150 , V_8 ) ;
F_169 ( V_75 , V_2 , V_42 , V_10 ) ;
F_171 ( V_2 , V_8 ) ;
F_104 ( & V_2 -> V_150 , V_8 ) ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
F_126 () ;
V_42 -> V_70 &= ~ V_10 -> V_69 ;
if ( V_42 -> V_70 == 0 && ! F_177 ( V_42 ) )
F_176 ( V_42 ) ;
F_165 ( V_10 -> V_69 , V_2 , V_42 , V_8 ) ;
F_53 ( V_10 -> V_102 != 0 || V_10 -> V_37 != NULL ,
L_48 ,
V_75 , V_10 -> V_102 , V_10 -> V_37 ) ;
F_119 ( V_10 ) ;
V_10 -> V_38 [ V_47 ] = NULL ;
F_150 ( & V_2 -> V_120 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
}
static void V_56 F_176 ( struct V_40 * V_149 )
{
}
static void F_178 ( int V_75 , struct V_1 * V_2 )
{
}
static void F_180 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
struct V_151 * V_152 , * V_153 , * * V_154 ;
long V_155 , V_156 , V_157 ;
int V_46 ;
if ( ! F_42 ( V_10 ) ) {
F_181 ( V_2 -> V_24 , V_10 -> V_142 , V_10 -> V_102 , 0 ) ;
F_182 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_10 -> V_37 ) ,
F_183 () , F_49 ( V_54 ) ,
F_184 () ) ;
return;
}
F_10 ( V_8 ) ;
F_57 ( F_92 ( F_51 () ) ) ;
V_155 = V_10 -> V_158 ;
F_181 ( V_2 -> V_24 , V_10 -> V_142 , V_10 -> V_102 , V_155 ) ;
V_153 = V_10 -> V_37 ;
V_10 -> V_37 = * V_10 -> V_38 [ V_39 ] ;
* V_10 -> V_38 [ V_39 ] = NULL ;
V_154 = V_10 -> V_38 [ V_39 ] ;
for ( V_46 = V_107 - 1 ; V_46 >= 0 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] == V_10 -> V_38 [ V_39 ] )
V_10 -> V_38 [ V_46 ] = & V_10 -> V_37 ;
F_20 ( V_8 ) ;
V_156 = V_157 = 0 ;
while ( V_153 ) {
V_152 = V_153 -> V_152 ;
F_185 ( V_152 ) ;
F_186 ( V_153 ) ;
if ( F_187 ( V_2 -> V_24 , V_153 ) )
V_157 ++ ;
V_153 = V_152 ;
if ( ++ V_156 >= V_155 &&
( F_183 () ||
( ! F_49 ( V_54 ) && ! F_184 () ) ) )
break;
}
F_10 ( V_8 ) ;
F_182 ( V_2 -> V_24 , V_156 , ! ! V_153 , F_183 () ,
F_49 ( V_54 ) ,
F_184 () ) ;
if ( V_153 != NULL ) {
* V_154 = V_10 -> V_37 ;
V_10 -> V_37 = V_153 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
if ( & V_10 -> V_37 == V_10 -> V_38 [ V_46 ] )
V_10 -> V_38 [ V_46 ] = V_154 ;
else
break;
}
F_15 () ;
V_10 -> V_142 -= V_157 ;
F_2 ( V_10 -> V_102 ) = V_10 -> V_102 - V_156 ;
V_10 -> V_159 += V_156 ;
if ( V_10 -> V_158 == V_160 && V_10 -> V_102 <= V_161 )
V_10 -> V_158 = V_158 ;
if ( V_10 -> V_102 == 0 && V_10 -> V_162 != 0 ) {
V_10 -> V_162 = 0 ;
V_10 -> V_163 = V_2 -> V_90 ;
} else if ( V_10 -> V_102 < V_10 -> V_162 - V_164 )
V_10 -> V_162 = V_10 -> V_102 ;
F_57 ( ( V_10 -> V_37 == NULL ) != ( V_10 -> V_102 == 0 ) ) ;
F_20 ( V_8 ) ;
if ( F_42 ( V_10 ) )
F_188 () ;
}
void F_189 ( int V_52 )
{
F_22 ( F_6 ( L_49 ) ) ;
F_190 () ;
if ( V_52 || F_84 () ) {
F_3 () ;
F_8 () ;
} else if ( ! F_191 () ) {
F_8 () ;
}
F_192 () ;
if ( F_193 () )
F_188 () ;
if ( V_52 )
F_194 ( V_54 ) ;
F_22 ( F_6 ( L_50 ) ) ;
}
static void F_153 ( struct V_1 * V_2 ,
int (* F_195)( struct V_9 * V_2 , bool * V_72 ,
unsigned long * V_73 ) ,
bool * V_72 , unsigned long * V_73 )
{
unsigned long V_165 ;
int V_75 ;
unsigned long V_8 ;
unsigned long V_138 ;
struct V_40 * V_42 ;
F_101 (rsp, rnp) {
F_149 () ;
V_138 = 0 ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
F_126 () ;
if ( ! F_1 ( V_2 ) ) {
F_104 ( & V_42 -> V_94 , V_8 ) ;
return;
}
if ( V_42 -> V_95 == 0 ) {
F_196 ( V_42 , V_8 ) ;
continue;
}
V_75 = V_42 -> V_97 ;
V_165 = 1 ;
for (; V_75 <= V_42 -> V_96 ; V_75 ++ , V_165 <<= 1 ) {
if ( ( V_42 -> V_95 & V_165 ) != 0 ) {
if ( ( V_42 -> V_70 & V_165 ) != 0 )
* V_72 = false ;
if ( F_195 ( F_111 ( V_2 -> V_15 , V_75 ) , V_72 , V_73 ) )
V_138 |= V_165 ;
}
}
if ( V_138 != 0 ) {
F_165 ( V_138 , V_2 , V_42 , V_8 ) ;
continue;
}
F_104 ( & V_42 -> V_94 , V_8 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_68 ;
struct V_40 * V_42 ;
struct V_40 * V_166 = NULL ;
V_42 = F_4 ( V_2 -> V_15 -> V_17 ) ;
for (; V_42 != NULL ; V_42 = V_42 -> V_141 ) {
V_68 = ( F_2 ( V_2 -> V_35 ) & V_125 ) ||
! F_138 ( & V_42 -> V_167 ) ;
if ( V_166 != NULL )
F_128 ( & V_166 -> V_167 ) ;
if ( V_68 ) {
V_2 -> V_168 ++ ;
return;
}
V_166 = V_42 ;
}
F_102 ( & V_166 -> V_94 , V_8 ) ;
F_126 () ;
F_128 ( & V_166 -> V_167 ) ;
if ( F_2 ( V_2 -> V_35 ) & V_125 ) {
V_2 -> V_168 ++ ;
F_104 ( & V_166 -> V_94 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_35 ) =
F_2 ( V_2 -> V_35 ) | V_125 ;
F_104 ( & V_166 -> V_94 , V_8 ) ;
F_131 ( V_2 ) ;
}
static void
F_197 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_119 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_57 ( V_10 -> V_169 == 0 ) ;
F_168 ( V_2 , V_10 ) ;
F_10 ( V_8 ) ;
if ( F_45 ( V_2 , V_10 ) ) {
F_125 ( & F_43 ( V_2 ) -> V_94 ) ;
V_119 = F_163 ( V_2 ) ;
F_104 ( & F_43 ( V_2 ) -> V_94 , V_8 ) ;
if ( V_119 )
F_131 ( V_2 ) ;
} else {
F_20 ( V_8 ) ;
}
if ( F_42 ( V_10 ) )
F_198 ( V_2 , V_10 ) ;
F_54 ( V_10 ) ;
}
static void F_199 ( struct V_170 * V_171 )
{
struct V_1 * V_2 ;
if ( F_92 ( F_51 () ) )
return;
F_22 ( F_6 ( L_51 ) ) ;
F_13 (rsp)
F_197 ( V_2 ) ;
F_22 ( F_6 ( L_52 ) ) ;
}
static void F_198 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
if ( F_24 ( ! F_2 ( V_71 ) ) )
return;
if ( F_200 ( ! V_2 -> V_172 ) ) {
F_180 ( V_2 , V_10 ) ;
return;
}
F_201 () ;
}
static void F_188 ( void )
{
if ( F_202 ( F_51 () ) )
F_203 ( V_173 ) ;
}
static void F_204 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_151 * V_174 , unsigned long V_8 )
{
bool V_119 ;
if ( ! F_79 () && F_202 ( F_51 () ) )
F_188 () ;
if ( F_205 ( V_8 ) || F_92 ( F_51 () ) )
return;
if ( F_24 ( V_10 -> V_102 > V_10 -> V_162 + V_164 ) ) {
F_137 ( V_2 , V_10 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_40 * V_112 = F_43 ( V_2 ) ;
F_125 ( & V_112 -> V_94 ) ;
F_126 () ;
V_119 = F_163 ( V_2 ) ;
F_128 ( & V_112 -> V_94 ) ;
if ( V_119 )
F_131 ( V_2 ) ;
} else {
V_10 -> V_158 = V_160 ;
if ( V_2 -> V_90 == V_10 -> V_163 &&
* V_10 -> V_38 [ V_39 ] != V_174 )
F_34 ( V_2 ) ;
V_10 -> V_163 = V_2 -> V_90 ;
V_10 -> V_162 = V_10 -> V_102 ;
}
}
}
static void F_206 ( struct V_151 * V_175 )
{
}
static void
F_207 ( struct V_151 * V_174 , void (* F_208)( struct V_151 * V_176 ) ,
struct V_1 * V_2 , int V_75 , bool V_177 )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
F_57 ( ( unsigned long ) V_174 & 0x1 ) ;
if ( F_209 ( V_174 ) ) {
F_2 ( V_174 -> F_208 ) = F_206 ;
F_53 ( 1 , L_53 ) ;
return;
}
V_174 -> F_208 = F_208 ;
V_174 -> V_152 = NULL ;
F_10 ( V_8 ) ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( F_24 ( V_10 -> V_38 [ V_47 ] == NULL ) || V_75 != - 1 ) {
int V_178 ;
if ( V_75 != - 1 )
V_10 = F_111 ( V_2 -> V_15 , V_75 ) ;
V_178 = ! F_210 ( V_10 , V_174 , V_177 , V_8 ) ;
F_57 ( V_178 ) ;
F_20 ( V_8 ) ;
return;
}
F_2 ( V_10 -> V_102 ) = V_10 -> V_102 + 1 ;
if ( V_177 )
V_10 -> V_142 ++ ;
else
F_173 () ;
F_15 () ;
* V_10 -> V_38 [ V_47 ] = V_174 ;
V_10 -> V_38 [ V_47 ] = & V_174 -> V_152 ;
if ( F_211 ( ( unsigned long ) F_208 ) )
F_212 ( V_2 -> V_24 , V_174 , ( unsigned long ) F_208 ,
V_10 -> V_142 , V_10 -> V_102 ) ;
else
F_213 ( V_2 -> V_24 , V_174 , V_10 -> V_142 , V_10 -> V_102 ) ;
F_204 ( V_2 , V_10 , V_174 , V_8 ) ;
F_20 ( V_8 ) ;
}
void F_214 ( struct V_151 * V_174 , void (* F_208)( struct V_151 * V_176 ) )
{
F_207 ( V_174 , F_208 , & V_22 , - 1 , 0 ) ;
}
void F_215 ( struct V_151 * V_174 , void (* F_208)( struct V_151 * V_176 ) )
{
F_207 ( V_174 , F_208 , & V_23 , - 1 , 0 ) ;
}
void F_216 ( struct V_151 * V_174 ,
void (* F_208)( struct V_151 * V_176 ) )
{
F_207 ( V_174 , F_208 , V_21 , - 1 , 1 ) ;
}
static inline int F_217 ( void )
{
int V_68 ;
F_218 () ;
F_80 () ;
V_68 = F_219 () <= 1 ;
F_81 () ;
return V_68 ;
}
void F_220 ( void )
{
F_60 ( ! F_61 ( & V_61 ) &&
! F_61 ( & V_60 ) &&
! F_61 ( & V_62 ) ,
L_54 ) ;
if ( F_217 () )
return;
if ( V_179 )
F_221 () ;
else
F_222 ( F_214 ) ;
}
void F_223 ( void )
{
F_60 ( ! F_61 ( & V_61 ) &&
! F_61 ( & V_60 ) &&
! F_61 ( & V_62 ) ,
L_55 ) ;
if ( F_217 () )
return;
if ( V_179 )
F_224 () ;
else
F_222 ( F_215 ) ;
}
unsigned long F_225 ( void )
{
F_15 () ;
return F_226 ( & V_21 -> V_4 ) ;
}
void F_227 ( unsigned long V_180 )
{
unsigned long V_181 ;
V_181 = F_226 ( & V_21 -> V_3 ) ;
if ( F_91 ( V_180 , V_181 ) )
F_228 () ;
}
static int F_229 ( void * V_182 )
{
F_15 () ;
return 0 ;
}
void F_221 ( void )
{
T_4 V_183 ;
bool V_184 = false ;
int V_75 ;
long V_185 , V_109 , V_80 ;
int V_186 = 0 ;
struct V_1 * V_2 = & V_22 ;
if ( F_91 ( ( V_187 ) F_230 ( & V_2 -> V_188 ) ,
( V_187 ) F_230 ( & V_2 -> V_189 ) +
V_76 / 8 ) ) {
F_220 () ;
F_231 ( & V_2 -> V_190 ) ;
return;
}
V_80 = F_232 ( & V_2 -> V_188 ) ;
V_185 = V_80 ;
if ( ! F_233 () ) {
F_222 ( F_214 ) ;
F_231 ( & V_2 -> V_191 ) ;
return;
}
F_57 ( F_92 ( F_234 () ) ) ;
V_184 = F_235 ( & V_183 , V_192 ) ;
if ( V_184 ) {
F_236 ( V_183 , V_193 ) ;
F_237 ( F_234 () , V_183 ) ;
F_238 (cpu, cm) {
struct V_11 * V_12 = & F_93 ( V_11 , V_75 ) ;
if ( ! ( F_86 ( 0 , & V_12 -> V_19 ) & 0x1 ) )
F_237 ( V_75 , V_183 ) ;
}
if ( F_239 ( V_183 ) == 0 )
goto V_194;
}
while ( F_240 ( V_184 ? V_183 : V_193 ,
F_229 ,
NULL ) == - V_195 ) {
F_241 () ;
F_231 ( & V_2 -> V_196 ) ;
V_109 = F_230 ( & V_2 -> V_189 ) ;
if ( F_91 ( ( V_187 ) V_109 , ( V_187 ) V_185 ) ) {
F_17 () ;
F_231 ( & V_2 -> V_197 ) ;
F_242 ( V_183 ) ;
return;
}
if ( V_186 ++ < 10 ) {
F_243 ( V_186 * F_219 () ) ;
} else {
F_222 ( F_214 ) ;
F_231 ( & V_2 -> V_191 ) ;
F_242 ( V_183 ) ;
return;
}
V_109 = F_230 ( & V_2 -> V_189 ) ;
if ( F_91 ( ( V_187 ) V_109 , ( V_187 ) V_185 ) ) {
F_17 () ;
F_231 ( & V_2 -> V_198 ) ;
F_242 ( V_183 ) ;
return;
}
if ( ! F_233 () ) {
F_222 ( F_214 ) ;
F_231 ( & V_2 -> V_191 ) ;
F_242 ( V_183 ) ;
return;
}
V_80 = F_230 ( & V_2 -> V_188 ) ;
F_15 () ;
}
F_231 ( & V_2 -> V_199 ) ;
V_194:
F_242 ( V_183 ) ;
do {
F_231 ( & V_2 -> V_200 ) ;
V_109 = F_230 ( & V_2 -> V_189 ) ;
if ( F_91 ( ( V_187 ) V_109 , ( V_187 ) V_80 ) ) {
F_17 () ;
F_231 ( & V_2 -> V_201 ) ;
break;
}
} while ( F_244 ( & V_2 -> V_189 , V_109 , V_80 ) != V_109 );
F_231 ( & V_2 -> V_202 ) ;
F_241 () ;
}
static int F_245 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_40 * V_42 = V_10 -> V_17 ;
V_10 -> V_203 ++ ;
F_116 ( V_2 , V_10 ) ;
if ( F_246 ( V_2 ) )
return 0 ;
if ( V_71 &&
V_10 -> V_118 && ! V_10 -> V_6 &&
V_10 -> V_117 == F_4 ( V_20 ) ) {
V_10 -> V_204 ++ ;
} else if ( V_10 -> V_118 &&
( V_10 -> V_6 ||
V_10 -> V_117 != F_4 ( V_20 ) ) ) {
V_10 -> V_205 ++ ;
return 1 ;
}
if ( F_42 ( V_10 ) ) {
V_10 -> V_206 ++ ;
return 1 ;
}
if ( F_45 ( V_2 , V_10 ) ) {
V_10 -> V_207 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_3 ) != V_10 -> V_3 ) {
V_10 -> V_208 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_4 ) != V_10 -> V_4 ||
F_24 ( F_2 ( V_10 -> V_77 ) ) ) {
V_10 -> V_209 ++ ;
return 1 ;
}
if ( F_247 ( V_10 ) ) {
V_10 -> V_210 ++ ;
return 1 ;
}
V_10 -> V_211 ++ ;
return 0 ;
}
static int F_193 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp)
if ( F_245 ( V_2 , F_16 ( V_2 -> V_15 ) ) )
return 1 ;
return 0 ;
}
static int V_56 F_248 ( bool * V_212 )
{
bool V_213 = true ;
bool V_214 = false ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_13 (rsp) {
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( ! V_10 -> V_37 )
continue;
V_214 = true ;
if ( V_10 -> V_102 != V_10 -> V_142 || ! V_212 ) {
V_213 = false ;
break;
}
}
if ( V_212 )
* V_212 = V_213 ;
return V_214 ;
}
static void F_249 ( struct V_1 * V_2 , const char * V_109 ,
int V_75 , unsigned long V_215 )
{
F_250 ( V_2 -> V_24 , V_109 , V_75 ,
F_58 ( & V_2 -> V_216 ) , V_215 ) ;
}
static void F_251 ( struct V_151 * V_175 )
{
struct V_9 * V_10 = F_252 ( V_175 , struct V_9 , V_217 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( F_253 ( & V_2 -> V_216 ) ) {
F_249 ( V_2 , L_56 , - 1 , V_2 -> V_218 ) ;
F_254 ( & V_2 -> V_219 ) ;
} else {
F_249 ( V_2 , L_57 , - 1 , V_2 -> V_218 ) ;
}
}
static void F_255 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_249 ( V_2 , L_58 , - 1 , V_2 -> V_218 ) ;
F_56 ( & V_2 -> V_216 ) ;
V_2 -> V_220 ( & V_10 -> V_217 , F_251 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
int V_75 ;
struct V_9 * V_10 ;
unsigned long V_80 = F_2 ( V_2 -> V_218 ) ;
unsigned long V_221 ;
F_249 ( V_2 , L_59 , - 1 , V_80 ) ;
F_144 ( & V_2 -> V_222 ) ;
F_15 () ;
V_221 = V_2 -> V_218 ;
F_249 ( V_2 , L_60 , - 1 , V_221 ) ;
if ( F_91 ( V_221 , ( V_80 + 3 ) & ~ 0x1 ) ) {
F_249 ( V_2 , L_61 , - 1 , V_221 ) ;
F_15 () ;
F_150 ( & V_2 -> V_222 ) ;
return;
}
F_2 ( V_2 -> V_218 ) = V_2 -> V_218 + 1 ;
F_57 ( ( V_2 -> V_218 & 0x1 ) != 1 ) ;
F_249 ( V_2 , L_62 , - 1 , V_2 -> V_218 ) ;
F_15 () ;
F_257 ( & V_2 -> V_219 ) ;
F_258 ( & V_2 -> V_216 , 1 ) ;
F_259 () ;
F_110 (cpu) {
if ( ! F_202 ( V_75 ) && ! F_170 ( V_75 ) )
continue;
V_10 = F_111 ( V_2 -> V_15 , V_75 ) ;
if ( F_170 ( V_75 ) ) {
if ( ! F_260 ( V_2 , V_75 ) ) {
F_249 ( V_2 , L_63 , V_75 ,
V_2 -> V_218 ) ;
} else {
F_249 ( V_2 , L_64 , V_75 ,
V_2 -> V_218 ) ;
F_17 () ;
F_56 ( & V_2 -> V_216 ) ;
F_207 ( & V_10 -> V_217 ,
F_251 , V_2 , V_75 , 0 ) ;
}
} else if ( F_2 ( V_10 -> V_102 ) ) {
F_249 ( V_2 , L_65 , V_75 ,
V_2 -> V_218 ) ;
F_261 ( V_75 , F_255 , V_2 , 1 ) ;
} else {
F_249 ( V_2 , L_66 , V_75 ,
V_2 -> V_218 ) ;
}
}
F_241 () ;
if ( F_253 ( & V_2 -> V_216 ) )
F_254 ( & V_2 -> V_219 ) ;
F_15 () ;
F_2 ( V_2 -> V_218 ) = V_2 -> V_218 + 1 ;
F_57 ( ( V_2 -> V_218 & 0x1 ) != 0 ) ;
F_249 ( V_2 , L_67 , - 1 , V_2 -> V_218 ) ;
F_15 () ;
F_262 ( & V_2 -> V_219 ) ;
F_150 ( & V_2 -> V_222 ) ;
}
void F_263 ( void )
{
F_256 ( & V_23 ) ;
}
void F_264 ( void )
{
F_256 ( & V_22 ) ;
}
static void T_5
F_265 ( int V_75 , struct V_1 * V_2 )
{
unsigned long V_8 ;
struct V_9 * V_10 = F_111 ( V_2 -> V_15 , V_75 ) ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
V_10 -> V_69 = 1UL << ( V_75 - V_10 -> V_17 -> V_97 ) ;
V_10 -> V_19 = & F_93 ( V_11 , V_75 ) ;
F_57 ( V_10 -> V_19 -> V_53 != V_65 ) ;
F_57 ( F_58 ( & V_10 -> V_19 -> V_19 ) != 1 ) ;
V_10 -> V_75 = V_75 ;
V_10 -> V_2 = V_2 ;
F_266 ( V_10 ) ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
}
static void
F_267 ( int V_75 , struct V_1 * V_2 )
{
unsigned long V_8 ;
unsigned long V_138 ;
struct V_9 * V_10 = F_111 ( V_2 -> V_15 , V_75 ) ;
struct V_40 * V_42 = F_43 ( V_2 ) ;
F_144 ( & V_2 -> V_120 ) ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
V_10 -> V_169 = 1 ;
V_10 -> V_162 = 0 ;
V_10 -> V_163 = V_2 -> V_90 ;
V_10 -> V_158 = V_158 ;
F_119 ( V_10 ) ;
V_10 -> V_19 -> V_53 = V_65 ;
F_268 ( V_10 -> V_19 ) ;
F_258 ( & V_10 -> V_19 -> V_19 ,
( F_58 ( & V_10 -> V_19 -> V_19 ) & ~ 0x1 ) + 1 ) ;
F_128 ( & V_42 -> V_94 ) ;
V_42 = V_10 -> V_17 ;
V_138 = V_10 -> V_69 ;
do {
F_125 ( & V_42 -> V_94 ) ;
V_42 -> V_70 |= V_138 ;
V_138 = V_42 -> V_69 ;
if ( V_42 == V_10 -> V_17 ) {
V_10 -> V_4 = V_42 -> V_3 ;
V_10 -> V_3 = V_42 -> V_3 ;
V_10 -> V_6 = 0 ;
V_10 -> V_117 = F_4 ( V_20 ) ;
V_10 -> V_118 = 0 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_68 ) ) ;
}
F_128 ( & V_42 -> V_94 ) ;
V_42 = V_42 -> V_141 ;
} while ( V_42 != NULL && ! ( V_42 -> V_70 & V_138 ) );
F_20 ( V_8 ) ;
F_150 ( & V_2 -> V_120 ) ;
}
static void F_269 ( int V_75 )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_267 ( V_75 , V_2 ) ;
}
static int F_270 ( struct V_223 * V_224 ,
unsigned long V_225 , void * V_226 )
{
long V_75 = ( long ) V_226 ;
struct V_9 * V_10 = F_111 ( V_21 -> V_15 , V_75 ) ;
struct V_40 * V_42 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_22 ( F_6 ( L_69 ) ) ;
switch ( V_225 ) {
case V_227 :
case V_228 :
F_269 ( V_75 ) ;
F_271 ( V_75 ) ;
F_272 ( V_75 ) ;
break;
case V_229 :
case V_230 :
F_179 ( V_42 , - 1 ) ;
break;
case V_231 :
F_179 ( V_42 , V_75 ) ;
break;
case V_232 :
case V_233 :
F_13 (rsp)
F_174 ( V_2 ) ;
break;
case V_234 :
case V_235 :
case V_236 :
case V_237 :
F_13 (rsp) {
F_178 ( V_75 , V_2 ) ;
F_54 ( F_111 ( V_2 -> V_15 , V_75 ) ) ;
}
break;
default:
break;
}
F_22 ( F_6 ( L_70 ) ) ;
return V_238 ;
}
static int F_273 ( struct V_223 * V_224 ,
unsigned long V_225 , void * V_226 )
{
switch ( V_225 ) {
case V_239 :
case V_240 :
if ( V_241 <= 256 )
V_179 = 1 ;
break;
case V_242 :
case V_243 :
V_179 = 0 ;
break;
default:
break;
}
return V_238 ;
}
static int T_5 F_274 ( void )
{
unsigned long V_8 ;
int V_244 = V_245 ;
struct V_40 * V_42 ;
struct V_1 * V_2 ;
struct V_246 V_247 ;
struct V_55 * V_248 ;
if ( F_275 ( V_249 ) && V_245 < 1 )
V_245 = 1 ;
else if ( V_245 < 0 )
V_245 = 0 ;
else if ( V_245 > 99 )
V_245 = 99 ;
if ( V_245 != V_244 )
F_276 ( L_71 ,
V_245 , V_244 ) ;
V_71 = 1 ;
F_13 (rsp) {
V_248 = F_277 ( F_157 , V_2 , L_72 , V_2 -> V_24 ) ;
F_278 ( F_279 ( V_248 ) ) ;
V_42 = F_43 ( V_2 ) ;
F_102 ( & V_42 -> V_94 , V_8 ) ;
V_2 -> V_26 = V_248 ;
if ( V_245 ) {
V_247 . V_250 = V_245 ;
F_280 ( V_248 , V_251 , & V_247 ) ;
}
F_281 ( V_248 ) ;
F_104 ( & V_42 -> V_94 , V_8 ) ;
}
F_282 () ;
F_283 () ;
return 0 ;
}
void F_284 ( void )
{
F_159 ( F_219 () != 1 ) ;
F_159 ( F_285 () > 0 ) ;
V_252 = 1 ;
}
static void T_5 F_286 ( struct V_1 * V_2 )
{
int V_46 ;
V_2 -> V_253 [ V_254 - 1 ] = V_255 ;
for ( V_46 = V_254 - 2 ; V_46 >= 0 ; V_46 -- )
V_2 -> V_253 [ V_46 ] = V_256 ;
}
static void T_5 F_286 ( struct V_1 * V_2 )
{
int V_257 ;
int V_258 ;
int V_46 ;
V_258 = V_241 ;
for ( V_46 = V_254 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_257 = V_2 -> V_259 [ V_46 ] ;
V_2 -> V_253 [ V_46 ] = ( V_258 + V_257 - 1 ) / V_257 ;
V_258 = V_257 ;
}
}
static void T_5 F_287 ( struct V_1 * V_2 ,
struct V_9 T_6 * V_15 )
{
static const char * const V_260 [] = {
L_73 ,
L_74 ,
L_75 ,
L_76 } ;
static const char * const V_261 [] = {
L_77 ,
L_78 ,
L_79 ,
L_80 } ;
static T_7 V_262 = 0x1 ;
int V_263 = 1 ;
int V_46 ;
int V_87 ;
struct V_40 * V_42 ;
F_288 ( V_264 > F_289 ( V_260 ) ) ;
if ( V_254 > V_265 )
F_290 ( L_81 ) ;
for ( V_46 = 0 ; V_46 < V_254 ; V_46 ++ )
V_2 -> V_259 [ V_46 ] = V_266 [ V_46 ] ;
for ( V_46 = 1 ; V_46 < V_254 ; V_46 ++ )
V_2 -> V_110 [ V_46 ] = V_2 -> V_110 [ V_46 - 1 ] + V_2 -> V_259 [ V_46 - 1 ] ;
F_286 ( V_2 ) ;
V_2 -> V_16 = V_262 ;
V_262 <<= 1 ;
for ( V_46 = V_254 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_263 *= V_2 -> V_253 [ V_46 ] ;
V_42 = V_2 -> V_110 [ V_46 ] ;
for ( V_87 = 0 ; V_87 < V_2 -> V_259 [ V_46 ] ; V_87 ++ , V_42 ++ ) {
F_291 ( & V_42 -> V_94 ) ;
F_292 ( & V_42 -> V_94 ,
& V_267 [ V_46 ] , V_260 [ V_46 ] ) ;
F_291 ( & V_42 -> V_167 ) ;
F_292 ( & V_42 -> V_167 ,
& V_268 [ V_46 ] , V_261 [ V_46 ] ) ;
V_42 -> V_4 = V_2 -> V_4 ;
V_42 -> V_3 = V_2 -> V_3 ;
V_42 -> V_95 = 0 ;
V_42 -> V_70 = 0 ;
V_42 -> V_97 = V_87 * V_263 ;
V_42 -> V_96 = ( V_87 + 1 ) * V_263 - 1 ;
if ( V_42 -> V_96 >= V_241 )
V_42 -> V_96 = V_241 - 1 ;
if ( V_46 == 0 ) {
V_42 -> V_269 = 0 ;
V_42 -> V_69 = 0 ;
V_42 -> V_141 = NULL ;
} else {
V_42 -> V_269 = V_87 % V_2 -> V_253 [ V_46 - 1 ] ;
V_42 -> V_69 = 1UL << V_42 -> V_269 ;
V_42 -> V_141 = V_2 -> V_110 [ V_46 - 1 ] +
V_87 / V_2 -> V_253 [ V_46 - 1 ] ;
}
V_42 -> V_110 = V_46 ;
F_293 ( & V_42 -> V_270 ) ;
F_294 ( V_42 ) ;
}
}
V_2 -> V_15 = V_15 ;
F_295 ( & V_2 -> V_116 ) ;
V_42 = V_2 -> V_110 [ V_254 - 1 ] ;
F_110 (i) {
while ( V_46 > V_42 -> V_96 )
V_42 ++ ;
F_111 ( V_2 -> V_15 , V_46 ) -> V_17 = V_42 ;
F_265 ( V_46 , V_2 ) ;
}
F_296 ( & V_2 -> V_271 , & V_272 ) ;
}
static void T_5 F_297 ( void )
{
V_187 V_273 ;
int V_46 ;
int V_87 ;
int V_274 = V_241 ;
int V_275 [ V_264 + 1 ] ;
V_273 = V_276 + V_241 / V_277 ;
if ( V_135 == V_76 )
V_135 = V_273 ;
if ( V_103 == V_76 )
V_103 = V_273 ;
if ( V_255 == V_278 &&
V_241 == V_279 )
return;
F_37 ( L_82 ,
V_255 , V_241 ) ;
V_275 [ 0 ] = 1 ;
V_275 [ 1 ] = V_255 ;
for ( V_46 = 2 ; V_46 <= V_264 ; V_46 ++ )
V_275 [ V_46 ] = V_275 [ V_46 - 1 ] * V_256 ;
if ( V_255 < V_278 ||
V_255 > sizeof( unsigned long ) * 8 ||
V_274 > V_275 [ V_264 ] ) {
F_159 ( 1 ) ;
return;
}
for ( V_46 = 1 ; V_46 <= V_264 ; V_46 ++ )
if ( V_274 <= V_275 [ V_46 ] ) {
for ( V_87 = 0 ; V_87 <= V_46 ; V_87 ++ )
V_266 [ V_87 ] =
F_298 ( V_274 , V_275 [ V_46 - V_87 ] ) ;
V_254 = V_46 ;
for ( V_87 = V_46 + 1 ; V_87 <= V_264 ; V_87 ++ )
V_266 [ V_87 ] = 0 ;
break;
}
V_280 = 0 ;
for ( V_46 = 0 ; V_46 <= V_264 ; V_46 ++ )
V_280 += V_266 [ V_46 ] ;
V_280 -= V_274 ;
}
void T_5 F_299 ( void )
{
int V_75 ;
F_300 () ;
F_297 () ;
F_287 ( & V_23 , & V_7 ) ;
F_287 ( & V_22 , & V_5 ) ;
F_301 () ;
F_302 ( V_173 , F_199 ) ;
F_303 ( F_270 , 0 ) ;
F_304 ( F_273 , 0 ) ;
F_305 (cpu)
F_270 ( NULL , V_227 , ( void * ) ( long ) V_75 ) ;
F_306 () ;
}
