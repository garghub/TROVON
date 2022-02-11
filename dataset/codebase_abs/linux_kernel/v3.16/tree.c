static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_8 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( F_6 ( L_1 ) , V_7 -> V_4 , F_6 ( L_2 ) ) ;
V_7 -> V_9 = 1 ;
}
void F_7 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_10 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( F_6 ( L_3 ) , V_7 -> V_4 , F_6 ( L_2 ) ) ;
V_7 -> V_9 = 1 ;
}
static void F_8 ( void )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_14 ;
struct V_1 * V_2 ;
F_9 ( V_11 ) ;
V_14 = F_10 ( V_15 ) ;
F_11 ( V_15 , 0 ) ;
F_12 (rsp) {
V_7 = F_13 ( V_2 -> V_16 ) ;
if ( ! ( V_14 & V_2 -> V_17 ) )
continue;
F_14 () ;
if ( F_2 ( V_7 -> V_18 -> V_3 ) !=
F_2 ( V_7 -> V_19 ) )
continue;
V_13 = F_15 ( & V_12 ) ;
F_16 () ;
F_17 ( 2 , & V_13 -> V_20 ) ;
F_18 () ;
break;
}
F_19 ( V_11 ) ;
}
void F_20 ( int V_5 )
{
F_21 ( F_6 ( L_4 ) ) ;
F_3 ( V_5 ) ;
F_22 ( V_5 ) ;
if ( F_23 ( F_10 ( V_15 ) ) )
F_8 () ;
F_21 ( F_6 ( L_5 ) ) ;
}
long F_24 ( void )
{
return V_21 . V_3 ;
}
long F_25 ( void )
{
return V_22 . V_3 ;
}
void F_26 ( void )
{
F_27 ( V_23 ) ;
}
void F_28 ( void )
{
F_27 ( & V_22 ) ;
}
void F_29 ( void )
{
struct V_1 * V_2 ;
F_12 (rsp) {
F_30 ( L_6 ,
V_2 -> V_24 , V_2 -> V_25 , V_2 -> V_26 -> V_27 ) ;
}
}
void F_31 ( void )
{
V_28 ++ ;
V_29 = 0 ;
}
void F_32 ( enum V_30 V_31 , int * V_11 ,
unsigned long * V_4 , unsigned long * V_3 )
{
struct V_1 * V_2 = NULL ;
switch ( V_31 ) {
case V_32 :
V_2 = V_23 ;
break;
case V_33 :
V_2 = & V_22 ;
break;
case V_34 :
V_2 = & V_21 ;
break;
default:
break;
}
if ( V_2 != NULL ) {
* V_11 = F_2 ( V_2 -> V_35 ) ;
* V_4 = F_2 ( V_2 -> V_4 ) ;
* V_3 = F_2 ( V_2 -> V_3 ) ;
return;
}
* V_11 = 0 ;
* V_4 = 0 ;
* V_3 = 0 ;
}
void F_33 ( unsigned long V_36 )
{
V_29 ++ ;
}
void F_34 ( void )
{
F_27 ( & V_21 ) ;
}
static int
F_35 ( struct V_6 * V_7 )
{
return & V_7 -> V_37 != V_7 -> V_38 [ V_39 ] &&
V_7 -> V_38 [ V_39 ] != NULL ;
}
static struct V_40 * F_36 ( struct V_1 * V_2 )
{
return & V_2 -> V_41 [ 0 ] ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_40 * V_42 = F_36 ( V_2 ) ;
int V_43 = ( F_2 ( V_42 -> V_3 ) + 1 ) & 0x1 ;
int * V_44 = & V_42 -> V_45 [ V_43 ] ;
return F_2 ( * V_44 ) ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_46 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_37 ( V_2 ) )
return 1 ;
if ( ! V_7 -> V_38 [ V_47 ] )
return 0 ;
if ( * V_7 -> V_38 [ V_48 ] )
return 1 ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ )
if ( V_7 -> V_38 [ V_46 - 1 ] != V_7 -> V_38 [ V_46 ] &&
F_39 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_50 [ V_46 ] ) )
return 1 ;
return 0 ;
}
static void F_40 ( struct V_12 * V_13 , long long V_51 ,
bool V_52 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_41 ( F_6 ( L_7 ) , V_51 , V_13 -> V_53 ) ;
if ( ! V_52 && ! F_42 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_43 ( F_44 () ) ;
F_41 ( F_6 ( L_8 ) , V_51 , 0 ) ;
F_45 ( V_57 ) ;
F_46 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
F_12 (rsp) {
V_7 = F_15 ( V_2 -> V_16 ) ;
F_47 ( V_7 ) ;
}
F_48 ( F_44 () ) ;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ;
F_52 ( ! F_53 ( & V_60 ) ,
L_10 ) ;
F_52 ( ! F_53 ( & V_61 ) ,
L_11 ) ;
F_52 ( ! F_53 ( & V_62 ) ,
L_12 ) ;
}
static void F_54 ( bool V_52 )
{
long long V_51 ;
struct V_12 * V_13 ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
F_50 ( ( V_51 & V_63 ) == 0 ) ;
if ( ( V_51 & V_63 ) == V_64 ) {
V_13 -> V_53 = 0 ;
F_40 ( V_13 , V_51 , V_52 ) ;
} else {
V_13 -> V_53 -= V_64 ;
}
}
void F_55 ( void )
{
unsigned long V_11 ;
F_9 ( V_11 ) ;
F_54 ( false ) ;
F_56 ( F_15 ( & V_12 ) , 0 ) ;
F_19 ( V_11 ) ;
}
void F_57 ( void )
{
F_54 ( 1 ) ;
}
void F_58 ( void )
{
unsigned long V_11 ;
long long V_51 ;
struct V_12 * V_13 ;
F_9 ( V_11 ) ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
V_13 -> V_53 -- ;
F_50 ( V_13 -> V_53 < 0 ) ;
if ( V_13 -> V_53 )
F_41 ( F_6 ( L_13 ) , V_51 , V_13 -> V_53 ) ;
else
F_40 ( V_13 , V_51 , true ) ;
F_56 ( V_13 , 1 ) ;
F_19 ( V_11 ) ;
}
static void F_59 ( struct V_12 * V_13 , long long V_51 ,
int V_52 )
{
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( ! ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ) ;
F_60 ( F_44 () ) ;
F_41 ( F_6 ( L_14 ) , V_51 , V_13 -> V_53 ) ;
if ( ! V_52 && ! F_42 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_43 ( F_44 () ) ;
F_41 ( F_6 ( L_15 ) ,
V_51 , V_13 -> V_53 ) ;
F_45 ( V_57 ) ;
F_46 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
}
static void F_61 ( bool V_52 )
{
struct V_12 * V_13 ;
long long V_51 ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
F_50 ( V_51 < 0 ) ;
if ( V_51 & V_63 ) {
V_13 -> V_53 += V_64 ;
} else {
V_13 -> V_53 = V_65 ;
F_59 ( V_13 , V_51 , V_52 ) ;
}
}
void F_62 ( void )
{
unsigned long V_11 ;
F_9 ( V_11 ) ;
F_61 ( false ) ;
F_63 ( F_15 ( & V_12 ) , 0 ) ;
F_19 ( V_11 ) ;
}
void F_64 ( void )
{
F_61 ( 1 ) ;
}
void F_65 ( void )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
long long V_51 ;
F_9 ( V_11 ) ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
V_13 -> V_53 ++ ;
F_50 ( V_13 -> V_53 == 0 ) ;
if ( V_51 )
F_41 ( F_6 ( L_16 ) , V_51 , V_13 -> V_53 ) ;
else
F_59 ( V_13 , V_51 , true ) ;
F_63 ( V_13 , 1 ) ;
F_19 ( V_11 ) ;
}
void F_66 ( void )
{
struct V_12 * V_13 = F_15 ( & V_12 ) ;
if ( V_13 -> V_66 == 0 &&
( F_51 ( & V_13 -> V_20 ) & 0x1 ) )
return;
V_13 -> V_66 ++ ;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( ! ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ) ;
}
void F_67 ( void )
{
struct V_12 * V_13 = F_15 ( & V_12 ) ;
if ( V_13 -> V_66 == 0 ||
-- V_13 -> V_66 != 0 )
return;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ;
}
bool T_2 F_68 ( void )
{
return F_51 ( F_15 ( & V_12 . V_20 ) ) & 0x1 ;
}
bool T_2 F_69 ( void )
{
int V_67 ;
F_70 () ;
V_67 = F_68 () ;
F_71 () ;
return V_67 ;
}
bool F_72 ( void )
{
struct V_6 * V_7 ;
struct V_40 * V_42 ;
bool V_67 ;
if ( F_73 () )
return true ;
F_70 () ;
V_7 = F_15 ( & V_8 ) ;
V_42 = V_7 -> V_18 ;
V_67 = ( V_7 -> V_68 & V_42 -> V_69 ) ||
! V_70 ;
F_71 () ;
return V_67 ;
}
static int F_74 ( void )
{
return F_75 ( V_12 . V_53 ) <= 1 ;
}
static int F_76 ( struct V_6 * V_7 ,
bool * V_71 , unsigned long * V_72 )
{
V_7 -> V_73 = F_77 ( 0 , & V_7 -> V_20 -> V_20 ) ;
F_78 ( V_7 , V_71 , V_72 ) ;
if ( ( V_7 -> V_73 & 0x1 ) == 0 ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_80 ( struct V_6 * V_7 ,
bool * V_71 , unsigned long * V_72 )
{
unsigned int V_74 ;
int * V_75 ;
unsigned int V_76 ;
V_74 = ( unsigned int ) F_77 ( 0 , & V_7 -> V_20 -> V_20 ) ;
V_76 = ( unsigned int ) V_7 -> V_73 ;
if ( ( V_74 & 0x1 ) == 0 || F_81 ( V_74 , V_76 + 2 ) ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
V_7 -> V_77 ++ ;
return 1 ;
}
if ( F_82 ( V_7 -> V_2 -> V_78 + 2 , V_79 ) )
return 0 ;
F_83 () ;
if ( F_84 ( V_7 -> V_5 ) ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_18 ) ) ;
V_7 -> V_80 ++ ;
return 1 ;
}
V_75 = & F_4 ( V_15 , V_7 -> V_5 ) ;
if ( F_82 ( V_79 ,
V_7 -> V_2 -> V_78 + V_81 ) ||
F_82 ( V_79 , V_7 -> V_2 -> V_82 ) ) {
if ( ! ( F_2 ( * V_75 ) & V_7 -> V_2 -> V_17 ) ) {
F_2 ( V_7 -> V_19 ) =
F_2 ( V_7 -> V_18 -> V_3 ) ;
F_14 () ;
F_2 ( * V_75 ) =
F_2 ( * V_75 ) + V_7 -> V_2 -> V_17 ;
F_85 ( V_7 -> V_5 ) ;
V_7 -> V_2 -> V_82 += 5 ;
} else if ( F_82 ( V_79 , V_7 -> V_2 -> V_82 ) ) {
F_85 ( V_7 -> V_5 ) ;
V_7 -> V_2 -> V_82 += 5 ;
}
}
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned long V_83 = V_79 ;
unsigned long j1 ;
V_2 -> V_78 = V_83 ;
F_87 () ;
j1 = F_88 () ;
F_2 ( V_2 -> V_84 ) = V_83 + j1 ;
V_2 -> V_82 = V_83 + j1 / 2 ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_11 ;
struct V_40 * V_42 ;
F_90 (rsp, rnp) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_42 -> V_87 - V_42 -> V_88 ; V_5 ++ )
if ( V_42 -> V_86 & ( 1UL << V_5 ) )
F_92 ( V_42 -> V_88 + V_5 ) ;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
int V_5 ;
long V_89 ;
unsigned long V_11 ;
int V_90 = 0 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
long V_91 = 0 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_89 = V_79 - F_2 ( V_2 -> V_84 ) ;
if ( V_89 < V_92 || ! F_1 ( V_2 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
F_2 ( V_2 -> V_84 ) = V_79 + 3 * F_88 () + 3 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_95 ( L_19 ,
V_2 -> V_24 ) ;
F_96 () ;
F_90 (rsp, rnp) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_90 += F_97 ( V_42 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_42 -> V_87 - V_42 -> V_88 ; V_5 ++ )
if ( V_42 -> V_86 & ( 1UL << V_5 ) ) {
F_98 ( V_2 ,
V_42 -> V_88 + V_5 ) ;
V_90 ++ ;
}
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_90 += F_97 ( V_42 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_99 () ;
F_100 (cpu)
V_91 += F_101 ( V_2 -> V_16 , V_5 ) -> V_93 ;
F_102 ( L_20 ,
F_44 () , ( long ) ( V_79 - V_2 -> V_78 ) ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
if ( V_90 == 0 )
F_95 ( L_21 ) ;
else if ( ! F_103 () )
F_89 ( V_2 ) ;
F_104 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_11 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
long V_91 = 0 ;
F_95 ( L_22 , V_2 -> V_24 ) ;
F_96 () ;
F_98 ( V_2 , F_44 () ) ;
F_99 () ;
F_100 (cpu)
V_91 += F_101 ( V_2 -> V_16 , V_5 ) -> V_93 ;
F_102 ( L_23 ,
V_79 - V_2 -> V_78 ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
if ( ! F_103 () )
F_106 () ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
if ( F_82 ( V_79 , F_2 ( V_2 -> V_84 ) ) )
F_2 ( V_2 -> V_84 ) = V_79 +
3 * F_88 () + 3 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_85 ( F_44 () ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_94 ;
unsigned long V_83 ;
unsigned long V_95 ;
struct V_40 * V_42 ;
if ( V_96 || ! F_1 ( V_2 ) )
return;
V_83 = V_79 ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_108 () ;
V_95 = F_2 ( V_2 -> V_84 ) ;
F_108 () ;
V_94 = F_2 ( V_2 -> V_78 ) ;
F_108 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_82 ( V_3 , V_4 ) ||
F_39 ( V_83 , V_95 ) ||
F_82 ( V_94 , V_95 ) )
return;
V_42 = V_7 -> V_18 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_42 -> V_86 ) & V_7 -> V_68 ) ) {
F_105 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_82 ( V_83 , V_95 + V_92 ) ) {
F_94 ( V_2 ) ;
}
}
void F_109 ( void )
{
struct V_1 * V_2 ;
F_12 (rsp)
F_2 ( V_2 -> V_84 ) = V_79 + V_97 / 2 ;
}
static void F_110 ( struct V_6 * V_7 )
{
int V_46 ;
if ( F_111 ( V_7 ) )
return;
V_7 -> V_37 = NULL ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
V_7 -> V_38 [ V_46 ] = & V_7 -> V_37 ;
}
static unsigned long F_112 ( struct V_1 * V_2 ,
struct V_40 * V_42 )
{
if ( F_36 ( V_2 ) == V_42 && V_42 -> V_4 == V_42 -> V_3 )
return V_42 -> V_3 + 1 ;
return V_42 -> V_3 + 2 ;
}
static void F_113 ( struct V_40 * V_42 , struct V_6 * V_7 ,
unsigned long V_99 , const char * V_100 )
{
F_114 ( V_7 -> V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_3 , V_99 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 , V_100 ) ;
}
static bool V_56
F_115 ( struct V_40 * V_42 , struct V_6 * V_7 ,
unsigned long * V_102 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 = false ;
struct V_40 * V_103 = F_36 ( V_7 -> V_2 ) ;
V_99 = F_112 ( V_7 -> V_2 , V_42 ) ;
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_24 ) ) ;
if ( V_42 -> V_45 [ V_99 & 0x1 ] ) {
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_25 ) ) ;
goto V_104;
}
if ( V_42 -> V_4 != V_42 -> V_3 ||
F_2 ( V_42 -> V_4 ) != F_2 ( V_42 -> V_3 ) ) {
V_42 -> V_45 [ V_99 & 0x1 ] ++ ;
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_26 ) ) ;
goto V_104;
}
if ( V_42 != V_103 ) {
F_116 ( & V_103 -> V_85 ) ;
F_117 () ;
}
V_99 = F_112 ( V_7 -> V_2 , V_103 ) ;
for ( V_46 = V_39 ; V_46 < V_47 ; V_46 ++ )
if ( F_39 ( V_99 , V_7 -> V_50 [ V_46 ] ) )
V_7 -> V_50 [ V_46 ] = V_99 ;
if ( V_103 -> V_45 [ V_99 & 0x1 ] ) {
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_27 ) ) ;
goto V_105;
}
V_103 -> V_45 [ V_99 & 0x1 ] ++ ;
if ( V_103 -> V_4 != V_103 -> V_3 ) {
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_28 ) ) ;
} else {
F_113 ( V_42 , V_7 , V_99 , F_6 ( L_29 ) ) ;
V_67 = F_118 ( V_7 -> V_2 , V_103 , V_7 ) ;
}
V_105:
if ( V_42 != V_103 )
F_119 ( & V_103 -> V_85 ) ;
V_104:
if ( V_102 != NULL )
* V_102 = V_99 ;
return V_67 ;
}
static int F_120 ( struct V_1 * V_2 , struct V_40 * V_42 )
{
int V_99 = V_42 -> V_3 ;
int V_106 ;
struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ;
F_121 ( V_2 , V_42 ) ;
V_42 -> V_45 [ V_99 & 0x1 ] = 0 ;
V_106 = V_42 -> V_45 [ ( V_99 + 1 ) & 0x1 ] ;
F_113 ( V_42 , V_7 , V_99 ,
V_106 ? F_6 ( L_30 ) : F_6 ( L_31 ) ) ;
return V_106 ;
}
static void F_122 ( struct V_1 * V_2 )
{
if ( V_54 == V_2 -> V_26 ||
! F_2 ( V_2 -> V_35 ) ||
! V_2 -> V_26 )
return;
F_123 ( & V_2 -> V_107 ) ;
}
static bool F_124 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 ;
if ( ! V_7 -> V_38 [ V_47 ] || ! * V_7 -> V_38 [ V_39 ] )
return false ;
V_99 = F_112 ( V_2 , V_42 ) ;
for ( V_46 = V_47 - 1 ; V_46 > V_39 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] != V_7 -> V_38 [ V_46 - 1 ] &&
! F_82 ( V_7 -> V_50 [ V_46 ] , V_99 ) )
break;
if ( ++ V_46 >= V_47 )
return false ;
for (; V_46 <= V_47 ; V_46 ++ ) {
V_7 -> V_38 [ V_46 ] = V_7 -> V_38 [ V_47 ] ;
V_7 -> V_50 [ V_46 ] = V_99 ;
}
V_67 = F_115 ( V_42 , V_7 , NULL ) ;
if ( ! * V_7 -> V_38 [ V_49 ] )
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_32 ) ) ;
else
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_33 ) ) ;
return V_67 ;
}
static bool F_125 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
int V_46 , V_83 ;
if ( ! V_7 -> V_38 [ V_47 ] || ! * V_7 -> V_38 [ V_39 ] )
return false ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_39 ( V_42 -> V_3 , V_7 -> V_50 [ V_46 ] ) )
break;
V_7 -> V_38 [ V_39 ] = V_7 -> V_38 [ V_46 ] ;
}
for ( V_83 = V_49 ; V_83 < V_46 ; V_83 ++ )
V_7 -> V_38 [ V_83 ] = V_7 -> V_38 [ V_39 ] ;
for ( V_83 = V_49 ; V_46 < V_47 ; V_46 ++ , V_83 ++ ) {
if ( V_7 -> V_38 [ V_83 ] == V_7 -> V_38 [ V_47 ] )
break;
V_7 -> V_38 [ V_83 ] = V_7 -> V_38 [ V_46 ] ;
V_7 -> V_50 [ V_83 ] = V_7 -> V_50 [ V_46 ] ;
}
return F_124 ( V_2 , V_42 , V_7 ) ;
}
static bool F_126 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
bool V_67 ;
if ( V_7 -> V_3 == V_42 -> V_3 ) {
V_67 = F_124 ( V_2 , V_42 , V_7 ) ;
} else {
V_67 = F_125 ( V_2 , V_42 , V_7 ) ;
V_7 -> V_3 = V_42 -> V_3 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_34 ) ) ;
}
if ( V_7 -> V_4 != V_42 -> V_4 ) {
V_7 -> V_4 = V_42 -> V_4 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_35 ) ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_108 = ! ! ( V_42 -> V_86 & V_7 -> V_68 ) ;
F_127 ( V_7 ) ;
}
return V_67 ;
}
static void F_128 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
bool V_109 ;
struct V_40 * V_42 ;
F_9 ( V_11 ) ;
V_42 = V_7 -> V_18 ;
if ( ( V_7 -> V_4 == F_2 ( V_42 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_42 -> V_3 ) ) ||
! F_129 ( & V_42 -> V_85 ) ) {
F_19 ( V_11 ) ;
return;
}
F_117 () ;
V_109 = F_126 ( V_2 , V_42 , V_7 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
if ( V_109 )
F_122 ( V_2 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_131 () ;
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
if ( ! F_2 ( V_2 -> V_35 ) ) {
F_133 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_2 ( V_2 -> V_35 ) = 0 ;
if ( F_50 ( F_1 ( V_2 ) ) ) {
F_133 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_86 ( V_2 ) ;
F_134 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_24 , V_2 -> V_4 , F_6 ( L_36 ) ) ;
F_133 ( & V_42 -> V_85 ) ;
F_135 ( & V_2 -> V_110 ) ;
F_117 () ;
F_136 (rsp, rnp) {
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
V_7 = F_15 ( V_2 -> V_16 ) ;
F_137 ( V_42 ) ;
V_42 -> V_86 = V_42 -> V_69 ;
F_2 ( V_42 -> V_4 ) = V_2 -> V_4 ;
F_50 ( V_42 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_3 ;
if ( V_42 == V_7 -> V_18 )
( void ) F_126 ( V_2 , V_42 , V_7 ) ;
F_138 ( V_42 ) ;
F_139 ( V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_101 , V_42 -> V_88 ,
V_42 -> V_87 , V_42 -> V_86 ) ;
F_133 ( & V_42 -> V_85 ) ;
#ifdef F_140
if ( ( F_141 () % ( V_111 + 1 ) ) == 0 &&
V_112 == V_113 )
F_142 ( 200 ) ;
#endif
F_143 () ;
}
F_144 ( & V_2 -> V_110 ) ;
return 1 ;
}
static int F_145 ( struct V_1 * V_2 , int V_114 )
{
int V_115 = V_114 ;
bool V_71 = false ;
unsigned long V_72 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
V_2 -> V_116 ++ ;
if ( V_115 == V_117 ) {
if ( F_146 ( V_2 ) ) {
V_71 = 1 ;
V_72 = V_79 - V_97 / 4 ;
}
F_147 ( V_2 , F_76 ,
& V_71 , & V_72 ) ;
F_148 ( V_2 , V_71 , V_72 ) ;
V_115 = V_118 ;
} else {
V_71 = 0 ;
F_147 ( V_2 , F_80 , & V_71 , & V_72 ) ;
}
if ( F_2 ( V_2 -> V_35 ) & V_119 ) {
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
F_2 ( V_2 -> V_35 ) &= ~ V_119 ;
F_133 ( & V_42 -> V_85 ) ;
}
return V_115 ;
}
static void F_149 ( struct V_1 * V_2 )
{
unsigned long V_120 ;
bool V_121 = false ;
int V_122 = 0 ;
struct V_6 * V_7 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
V_120 = V_79 - V_2 -> V_78 ;
if ( V_120 > V_2 -> V_123 )
V_2 -> V_123 = V_120 ;
F_133 ( & V_42 -> V_85 ) ;
F_136 (rsp, rnp) {
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_15 ( V_2 -> V_16 ) ;
if ( V_42 == V_7 -> V_18 )
V_121 = F_126 ( V_2 , V_42 , V_7 ) || V_121 ;
V_122 += F_120 ( V_2 , V_42 ) ;
F_133 ( & V_42 -> V_85 ) ;
F_143 () ;
}
V_42 = F_36 ( V_2 ) ;
F_132 ( & V_42 -> V_85 ) ;
F_117 () ;
F_150 ( V_42 , V_122 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_24 , V_2 -> V_3 , F_6 ( L_37 ) ) ;
V_2 -> V_115 = V_124 ;
V_7 = F_15 ( V_2 -> V_16 ) ;
V_121 = F_125 ( V_2 , V_42 , V_7 ) || V_121 ;
if ( V_121 || F_38 ( V_2 , V_7 ) ) {
F_2 ( V_2 -> V_35 ) = V_125 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
}
F_133 ( & V_42 -> V_85 ) ;
}
static int T_3 F_151 ( void * V_126 )
{
int V_115 ;
int V_127 ;
unsigned long V_83 ;
int V_67 ;
struct V_1 * V_2 = V_126 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
V_2 -> V_25 = V_128 ;
F_152 ( V_2 -> V_107 ,
F_2 ( V_2 -> V_35 ) &
V_125 ) ;
if ( F_130 ( V_2 ) )
break;
F_143 () ;
F_153 ( V_54 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
}
V_115 = V_117 ;
V_83 = V_129 ;
if ( V_83 > V_130 ) {
V_83 = V_130 ;
V_129 = V_130 ;
}
V_67 = 0 ;
for (; ; ) {
if ( ! V_67 )
V_2 -> V_131 = V_79 + V_83 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_2 -> V_25 = V_132 ;
V_67 = F_154 ( V_2 -> V_107 ,
( ( V_127 = F_2 ( V_2 -> V_35 ) ) &
V_119 ) ||
( ! F_2 ( V_42 -> V_86 ) &&
! F_155 ( V_42 ) ) ,
V_83 ) ;
if ( ! F_2 ( V_42 -> V_86 ) &&
! F_155 ( V_42 ) )
break;
if ( F_82 ( V_79 , V_2 -> V_131 ) ||
( V_127 & V_119 ) ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
V_115 = F_145 ( V_2 , V_115 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
F_143 () ;
} else {
F_143 () ;
F_153 ( V_54 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_44 ) ) ;
}
V_83 = V_133 ;
if ( V_83 > V_130 ) {
V_83 = V_130 ;
V_133 = V_130 ;
} else if ( V_83 < 1 ) {
V_83 = 1 ;
V_133 = 1 ;
}
}
F_149 ( V_2 ) ;
}
}
static bool
F_118 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_26 || ! F_38 ( V_2 , V_7 ) ) {
return false ;
}
F_2 ( V_2 -> V_35 ) = V_125 ;
F_5 ( V_2 -> V_24 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
return true ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
bool V_67 = false ;
V_67 = F_125 ( V_2 , V_42 , V_7 ) || V_67 ;
V_67 = F_118 ( V_2 , V_42 , V_7 ) || V_67 ;
return V_67 ;
}
static void F_157 ( struct V_1 * V_2 , unsigned long V_11 )
__releases( rcu_get_root( V_2 )->lock
static void
F_158 ( unsigned long V_134 , struct V_1 * V_2 ,
struct V_40 * V_42 , unsigned long V_11 )
__releases( V_42 -> V_85 )
{
struct V_40 * V_135 ;
for (; ; ) {
if ( ! ( V_42 -> V_86 & V_134 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_42 -> V_86 &= ~ V_134 ;
F_159 ( V_2 -> V_24 , V_42 -> V_4 ,
V_134 , V_42 -> V_86 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 ,
! ! V_42 -> V_136 ) ;
if ( V_42 -> V_86 != 0 || F_155 ( V_42 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_134 = V_42 -> V_68 ;
if ( V_42 -> V_137 == NULL ) {
break;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
V_135 = V_42 ;
V_42 = V_42 -> V_137 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_117 () ;
F_50 ( V_135 -> V_86 ) ;
}
F_157 ( V_2 , V_11 ) ;
}
static void
F_160 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
unsigned long V_134 ;
bool V_109 ;
struct V_40 * V_42 ;
V_42 = V_7 -> V_18 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_117 () ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_42 -> V_4 ||
V_42 -> V_3 == V_42 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_134 = V_7 -> V_68 ;
if ( ( V_42 -> V_86 & V_134 ) == 0 ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
} else {
V_7 -> V_108 = 0 ;
V_109 = F_124 ( V_2 , V_42 , V_7 ) ;
F_158 ( V_134 , V_2 , V_42 , V_11 ) ;
if ( V_109 )
F_122 ( V_2 ) ;
}
}
static void
F_161 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_128 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_108 )
return;
if ( ! V_7 -> V_9 )
return;
F_160 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_162 ( int V_5 , struct V_1 * V_2 ,
struct V_40 * V_42 , struct V_6 * V_7 )
{
if ( F_163 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_37 != NULL ) {
V_2 -> V_138 += V_7 -> V_138 ;
V_2 -> V_93 += V_7 -> V_93 ;
V_7 -> V_139 += V_7 -> V_93 ;
V_7 -> V_138 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
}
if ( * V_7 -> V_38 [ V_39 ] != NULL ) {
* V_2 -> V_140 = * V_7 -> V_38 [ V_39 ] ;
V_2 -> V_140 = V_7 -> V_38 [ V_47 ] ;
* V_7 -> V_38 [ V_39 ] = NULL ;
}
if ( V_7 -> V_37 != NULL ) {
* V_2 -> V_141 = V_7 -> V_37 ;
V_2 -> V_141 = V_7 -> V_38 [ V_39 ] ;
}
F_110 ( V_7 ) ;
}
static void F_164 ( struct V_1 * V_2 , unsigned long V_11 )
{
int V_46 ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
if ( F_165 ( V_2 , V_7 , V_11 ) )
return;
V_7 -> V_138 += V_2 -> V_138 ;
V_7 -> V_93 += V_2 -> V_93 ;
V_7 -> V_142 += V_2 -> V_93 ;
if ( V_2 -> V_138 != V_2 -> V_93 )
F_166 () ;
V_2 -> V_138 = 0 ;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_143 != NULL ) {
* V_2 -> V_141 = * V_7 -> V_38 [ V_39 ] ;
* V_7 -> V_38 [ V_39 ] = V_2 -> V_143 ;
for ( V_46 = V_98 - 1 ; V_46 >= V_39 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] == V_7 -> V_38 [ V_39 ] )
V_7 -> V_38 [ V_46 ] = V_2 -> V_141 ;
V_2 -> V_143 = NULL ;
V_2 -> V_141 = & V_2 -> V_143 ;
}
if ( V_2 -> V_144 != NULL ) {
* V_7 -> V_38 [ V_47 ] = V_2 -> V_144 ;
V_7 -> V_38 [ V_47 ] = V_2 -> V_140 ;
V_2 -> V_144 = NULL ;
V_2 -> V_140 = & V_2 -> V_144 ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
F_168 (unsigned long mask) ;
F_168 ( struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ) ;
F_168 ( struct V_40 * V_42 = V_7 -> V_18 ) ;
F_168 ( V_134 = V_7 -> V_68 ) ;
F_5 ( V_2 -> V_24 ,
V_42 -> V_4 + 1 - ! ! ( V_42 -> V_86 & V_134 ) ,
F_6 ( L_45 ) ) ;
}
static void F_169 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned long V_134 ;
int V_145 = 0 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = V_7 -> V_18 ;
F_170 ( V_42 , - 1 ) ;
F_135 ( & V_2 -> V_110 ) ;
F_91 ( & V_2 -> V_146 , V_11 ) ;
F_162 ( V_5 , V_2 , V_42 , V_7 ) ;
F_164 ( V_2 , V_11 ) ;
V_134 = V_7 -> V_68 ;
do {
F_116 ( & V_42 -> V_85 ) ;
F_117 () ;
V_42 -> V_69 &= ~ V_134 ;
if ( V_42 -> V_69 != 0 ) {
if ( V_42 != V_7 -> V_18 )
F_119 ( & V_42 -> V_85 ) ;
break;
}
if ( V_42 == V_7 -> V_18 )
V_145 = F_171 ( V_2 , V_42 , V_7 ) ;
else
F_119 ( & V_42 -> V_85 ) ;
V_134 = V_42 -> V_68 ;
V_42 = V_42 -> V_137 ;
} while ( V_42 != NULL );
F_119 ( & V_2 -> V_146 ) ;
V_42 = V_7 -> V_18 ;
if ( V_145 & V_147 )
F_172 ( V_42 , V_11 ) ;
else
F_93 ( & V_42 -> V_85 , V_11 ) ;
if ( V_145 & V_148 )
F_173 ( V_2 , V_42 , true ) ;
F_46 ( V_7 -> V_93 != 0 || V_7 -> V_37 != NULL ,
L_46 ,
V_5 , V_7 -> V_93 , V_7 -> V_37 ) ;
F_110 ( V_7 ) ;
V_7 -> V_38 [ V_47 ] = NULL ;
F_144 ( & V_2 -> V_110 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
}
static void F_169 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_174 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
struct V_149 * V_150 , * V_151 , * * V_152 ;
long V_153 , V_154 , V_155 ;
int V_46 ;
if ( ! F_35 ( V_7 ) ) {
F_175 ( V_2 -> V_24 , V_7 -> V_138 , V_7 -> V_93 , 0 ) ;
F_176 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_7 -> V_37 ) ,
F_177 () , F_42 ( V_54 ) ,
F_178 () ) ;
return;
}
F_9 ( V_11 ) ;
F_50 ( F_84 ( F_44 () ) ) ;
V_153 = V_7 -> V_156 ;
F_175 ( V_2 -> V_24 , V_7 -> V_138 , V_7 -> V_93 , V_153 ) ;
V_151 = V_7 -> V_37 ;
V_7 -> V_37 = * V_7 -> V_38 [ V_39 ] ;
* V_7 -> V_38 [ V_39 ] = NULL ;
V_152 = V_7 -> V_38 [ V_39 ] ;
for ( V_46 = V_98 - 1 ; V_46 >= 0 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] == V_7 -> V_38 [ V_39 ] )
V_7 -> V_38 [ V_46 ] = & V_7 -> V_37 ;
F_19 ( V_11 ) ;
V_154 = V_155 = 0 ;
while ( V_151 ) {
V_150 = V_151 -> V_150 ;
F_179 ( V_150 ) ;
F_180 ( V_151 ) ;
if ( F_181 ( V_2 -> V_24 , V_151 ) )
V_155 ++ ;
V_151 = V_150 ;
if ( ++ V_154 >= V_153 &&
( F_177 () ||
( ! F_42 ( V_54 ) && ! F_178 () ) ) )
break;
}
F_9 ( V_11 ) ;
F_176 ( V_2 -> V_24 , V_154 , ! ! V_151 , F_177 () ,
F_42 ( V_54 ) ,
F_178 () ) ;
if ( V_151 != NULL ) {
* V_152 = V_7 -> V_37 ;
V_7 -> V_37 = V_151 ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
if ( & V_7 -> V_37 == V_7 -> V_38 [ V_46 ] )
V_7 -> V_38 [ V_46 ] = V_152 ;
else
break;
}
F_14 () ;
V_7 -> V_138 -= V_155 ;
F_2 ( V_7 -> V_93 ) -= V_154 ;
V_7 -> V_157 += V_154 ;
if ( V_7 -> V_156 == V_158 && V_7 -> V_93 <= V_159 )
V_7 -> V_156 = V_156 ;
if ( V_7 -> V_93 == 0 && V_7 -> V_160 != 0 ) {
V_7 -> V_160 = 0 ;
V_7 -> V_161 = V_2 -> V_116 ;
} else if ( V_7 -> V_93 < V_7 -> V_160 - V_162 )
V_7 -> V_160 = V_7 -> V_93 ;
F_50 ( ( V_7 -> V_37 == NULL ) != ( V_7 -> V_93 == 0 ) ) ;
F_19 ( V_11 ) ;
if ( F_35 ( V_7 ) )
F_182 () ;
}
void F_183 ( int V_5 , int V_52 )
{
F_21 ( F_6 ( L_47 ) ) ;
F_184 () ;
if ( V_52 || F_74 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_185 () ) {
F_7 ( V_5 ) ;
}
F_186 ( V_5 ) ;
if ( F_187 ( V_5 ) )
F_182 () ;
F_21 ( F_6 ( L_48 ) ) ;
}
static void F_147 ( struct V_1 * V_2 ,
int (* F_188)( struct V_6 * V_2 , bool * V_71 ,
unsigned long * V_72 ) ,
bool * V_71 , unsigned long * V_72 )
{
unsigned long V_163 ;
int V_5 ;
unsigned long V_11 ;
unsigned long V_134 ;
struct V_40 * V_42 ;
F_90 (rsp, rnp) {
F_143 () ;
V_134 = 0 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_117 () ;
if ( ! F_1 ( V_2 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
if ( V_42 -> V_86 == 0 ) {
F_189 ( V_42 , V_11 ) ;
continue;
}
V_5 = V_42 -> V_88 ;
V_163 = 1 ;
for (; V_5 <= V_42 -> V_87 ; V_5 ++ , V_163 <<= 1 ) {
if ( ( V_42 -> V_86 & V_163 ) != 0 ) {
if ( ( V_42 -> V_69 & V_163 ) != 0 )
* V_71 = 0 ;
if ( F_188 ( F_101 ( V_2 -> V_16 , V_5 ) , V_71 , V_72 ) )
V_134 |= V_163 ;
}
}
if ( V_134 != 0 ) {
F_158 ( V_134 , V_2 , V_42 , V_11 ) ;
continue;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
V_42 = F_36 ( V_2 ) ;
if ( V_42 -> V_86 == 0 ) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_117 () ;
F_189 ( V_42 , V_11 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
bool V_67 ;
struct V_40 * V_42 ;
struct V_40 * V_164 = NULL ;
V_42 = F_101 ( V_2 -> V_16 , F_190 () ) -> V_18 ;
for (; V_42 != NULL ; V_42 = V_42 -> V_137 ) {
V_67 = ( F_2 ( V_2 -> V_35 ) & V_119 ) ||
! F_129 ( & V_42 -> V_165 ) ;
if ( V_164 != NULL )
F_119 ( & V_164 -> V_165 ) ;
if ( V_67 ) {
F_2 ( V_2 -> V_166 ) ++ ;
return;
}
V_164 = V_42 ;
}
F_91 ( & V_164 -> V_85 , V_11 ) ;
F_117 () ;
F_119 ( & V_164 -> V_165 ) ;
if ( F_2 ( V_2 -> V_35 ) & V_119 ) {
F_2 ( V_2 -> V_166 ) ++ ;
F_93 ( & V_164 -> V_85 , V_11 ) ;
return;
}
F_2 ( V_2 -> V_35 ) |= V_119 ;
F_93 ( & V_164 -> V_85 , V_11 ) ;
F_123 ( & V_2 -> V_107 ) ;
}
static void
F_191 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
bool V_109 ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
F_50 ( V_7 -> V_167 == 0 ) ;
F_161 ( V_2 , V_7 ) ;
F_9 ( V_11 ) ;
if ( F_38 ( V_2 , V_7 ) ) {
F_116 ( & F_36 ( V_2 ) -> V_85 ) ;
V_109 = F_156 ( V_2 ) ;
F_93 ( & F_36 ( V_2 ) -> V_85 , V_11 ) ;
if ( V_109 )
F_122 ( V_2 ) ;
} else {
F_19 ( V_11 ) ;
}
if ( F_35 ( V_7 ) )
F_192 ( V_2 , V_7 ) ;
F_47 ( V_7 ) ;
}
static void F_193 ( struct V_168 * V_169 )
{
struct V_1 * V_2 ;
if ( F_84 ( F_44 () ) )
return;
F_21 ( F_6 ( L_49 ) ) ;
F_12 (rsp)
F_191 ( V_2 ) ;
F_21 ( F_6 ( L_50 ) ) ;
}
static void F_192 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_23 ( ! F_2 ( V_70 ) ) )
return;
if ( F_194 ( ! V_2 -> V_170 ) ) {
F_174 ( V_2 , V_7 ) ;
return;
}
F_195 () ;
}
static void F_182 ( void )
{
if ( F_196 ( F_44 () ) )
F_197 ( V_171 ) ;
}
static void F_198 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_149 * V_172 , unsigned long V_11 )
{
bool V_109 ;
if ( ! F_69 () && F_196 ( F_44 () ) )
F_182 () ;
if ( F_199 ( V_11 ) || F_84 ( F_44 () ) )
return;
if ( F_23 ( V_7 -> V_93 > V_7 -> V_160 + V_162 ) ) {
F_128 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_40 * V_103 = F_36 ( V_2 ) ;
F_116 ( & V_103 -> V_85 ) ;
F_117 () ;
V_109 = F_156 ( V_2 ) ;
F_119 ( & V_103 -> V_85 ) ;
if ( V_109 )
F_122 ( V_2 ) ;
} else {
V_7 -> V_156 = V_158 ;
if ( V_2 -> V_116 == V_7 -> V_161 &&
* V_7 -> V_38 [ V_39 ] != V_172 )
F_27 ( V_2 ) ;
V_7 -> V_161 = V_2 -> V_116 ;
V_7 -> V_160 = V_7 -> V_93 ;
}
}
}
static void F_200 ( struct V_149 * V_173 )
{
}
static void
F_201 ( struct V_149 * V_172 , void (* F_202)( struct V_149 * V_174 ) ,
struct V_1 * V_2 , int V_5 , bool V_175 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
F_50 ( ( unsigned long ) V_172 & 0x3 ) ;
if ( F_203 ( V_172 ) ) {
F_2 ( V_172 -> F_202 ) = F_200 ;
F_46 ( 1 , L_51 ) ;
return;
}
V_172 -> F_202 = F_202 ;
V_172 -> V_150 = NULL ;
F_9 ( V_11 ) ;
V_7 = F_15 ( V_2 -> V_16 ) ;
if ( F_23 ( V_7 -> V_38 [ V_47 ] == NULL ) || V_5 != - 1 ) {
int V_176 ;
if ( V_5 != - 1 )
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
V_176 = ! F_204 ( V_7 , V_172 , V_175 , V_11 ) ;
F_50 ( V_176 ) ;
F_19 ( V_11 ) ;
return;
}
F_2 ( V_7 -> V_93 ) ++ ;
if ( V_175 )
V_7 -> V_138 ++ ;
else
F_166 () ;
F_14 () ;
* V_7 -> V_38 [ V_47 ] = V_172 ;
V_7 -> V_38 [ V_47 ] = & V_172 -> V_150 ;
if ( F_205 ( ( unsigned long ) F_202 ) )
F_206 ( V_2 -> V_24 , V_172 , ( unsigned long ) F_202 ,
V_7 -> V_138 , V_7 -> V_93 ) ;
else
F_207 ( V_2 -> V_24 , V_172 , V_7 -> V_138 , V_7 -> V_93 ) ;
F_198 ( V_2 , V_7 , V_172 , V_11 ) ;
F_19 ( V_11 ) ;
}
void F_208 ( struct V_149 * V_172 , void (* F_202)( struct V_149 * V_174 ) )
{
F_201 ( V_172 , F_202 , & V_21 , - 1 , 0 ) ;
}
void F_209 ( struct V_149 * V_172 , void (* F_202)( struct V_149 * V_174 ) )
{
F_201 ( V_172 , F_202 , & V_22 , - 1 , 0 ) ;
}
void F_210 ( struct V_149 * V_172 ,
void (* F_202)( struct V_149 * V_174 ) )
{
F_201 ( V_172 , F_202 , V_23 , - 1 , 1 ) ;
}
static inline int F_211 ( void )
{
int V_67 ;
F_212 () ;
F_70 () ;
V_67 = F_213 () <= 1 ;
F_71 () ;
return V_67 ;
}
void F_214 ( void )
{
F_52 ( ! F_53 ( & V_61 ) &&
! F_53 ( & V_60 ) &&
! F_53 ( & V_62 ) ,
L_52 ) ;
if ( F_211 () )
return;
if ( V_177 )
F_215 () ;
else
F_216 ( F_208 ) ;
}
void F_217 ( void )
{
F_52 ( ! F_53 ( & V_61 ) &&
! F_53 ( & V_60 ) &&
! F_53 ( & V_62 ) ,
L_53 ) ;
if ( F_211 () )
return;
if ( V_177 )
F_218 () ;
else
F_216 ( F_209 ) ;
}
unsigned long F_219 ( void )
{
F_14 () ;
return F_220 ( & V_23 -> V_4 ) ;
}
void F_221 ( unsigned long V_178 )
{
unsigned long V_179 ;
V_179 = F_220 ( & V_23 -> V_3 ) ;
if ( F_82 ( V_178 , V_179 ) )
F_222 () ;
}
static int F_223 ( void * V_180 )
{
F_14 () ;
return 0 ;
}
void F_215 ( void )
{
long V_181 , V_100 , V_76 ;
int V_182 = 0 ;
struct V_1 * V_2 = & V_21 ;
if ( F_82 ( ( V_183 ) F_224 ( & V_2 -> V_184 ) ,
( V_183 ) F_224 ( & V_2 -> V_185 ) +
V_97 / 8 ) ) {
F_214 () ;
F_225 ( & V_2 -> V_186 ) ;
return;
}
V_76 = F_226 ( & V_2 -> V_184 ) ;
V_181 = V_76 ;
F_227 () ;
F_50 ( F_84 ( F_190 () ) ) ;
while ( F_228 ( V_187 ,
F_223 ,
NULL ) == - V_188 ) {
F_229 () ;
F_225 ( & V_2 -> V_189 ) ;
V_100 = F_224 ( & V_2 -> V_185 ) ;
if ( F_82 ( ( V_183 ) V_100 , ( V_183 ) V_181 ) ) {
F_16 () ;
F_225 ( & V_2 -> V_190 ) ;
return;
}
if ( V_182 ++ < 10 ) {
F_142 ( V_182 * F_213 () ) ;
} else {
F_216 ( F_208 ) ;
F_225 ( & V_2 -> V_191 ) ;
return;
}
V_100 = F_224 ( & V_2 -> V_185 ) ;
if ( F_82 ( ( V_183 ) V_100 , ( V_183 ) V_181 ) ) {
F_16 () ;
F_225 ( & V_2 -> V_192 ) ;
return;
}
F_227 () ;
V_76 = F_224 ( & V_2 -> V_184 ) ;
F_14 () ;
}
F_225 ( & V_2 -> V_193 ) ;
do {
F_225 ( & V_2 -> V_194 ) ;
V_100 = F_224 ( & V_2 -> V_185 ) ;
if ( F_82 ( ( V_183 ) V_100 , ( V_183 ) V_76 ) ) {
F_16 () ;
F_225 ( & V_2 -> V_195 ) ;
break;
}
} while ( F_230 ( & V_2 -> V_185 , V_100 , V_76 ) != V_100 );
F_225 ( & V_2 -> V_196 ) ;
F_229 () ;
}
static int F_231 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_40 * V_42 = V_7 -> V_18 ;
V_7 -> V_197 ++ ;
F_107 ( V_2 , V_7 ) ;
if ( F_232 ( V_2 ) )
return 0 ;
if ( V_70 &&
V_7 -> V_108 && ! V_7 -> V_9 ) {
V_7 -> V_198 ++ ;
} else if ( V_7 -> V_108 && V_7 -> V_9 ) {
V_7 -> V_199 ++ ;
return 1 ;
}
if ( F_35 ( V_7 ) ) {
V_7 -> V_200 ++ ;
return 1 ;
}
if ( F_38 ( V_2 , V_7 ) ) {
V_7 -> V_201 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_202 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_203 ++ ;
return 1 ;
}
if ( F_233 ( V_7 ) ) {
V_7 -> V_204 ++ ;
return 1 ;
}
V_7 -> V_205 ++ ;
return 0 ;
}
static int F_187 ( int V_5 )
{
struct V_1 * V_2 ;
F_12 (rsp)
if ( F_231 ( V_2 , F_101 ( V_2 -> V_16 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int V_56 F_234 ( int V_5 , bool * V_206 )
{
bool V_207 = true ;
bool V_208 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_12 (rsp) {
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
if ( ! V_7 -> V_37 )
continue;
V_208 = true ;
if ( V_7 -> V_93 != V_7 -> V_138 || ! V_206 ) {
V_207 = false ;
break;
}
}
if ( V_206 )
* V_206 = V_207 ;
return V_208 ;
}
static void F_235 ( struct V_1 * V_2 , const char * V_100 ,
int V_5 , unsigned long V_209 )
{
F_236 ( V_2 -> V_24 , V_100 , V_5 ,
F_51 ( & V_2 -> V_210 ) , V_209 ) ;
}
static void F_237 ( struct V_149 * V_173 )
{
struct V_6 * V_7 = F_238 ( V_173 , struct V_6 , V_211 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_239 ( & V_2 -> V_210 ) ) {
F_235 ( V_2 , L_54 , - 1 , V_2 -> V_212 ) ;
F_240 ( & V_2 -> V_213 ) ;
} else {
F_235 ( V_2 , L_55 , - 1 , V_2 -> V_212 ) ;
}
}
static void F_241 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
F_235 ( V_2 , L_56 , - 1 , V_2 -> V_212 ) ;
F_49 ( & V_2 -> V_210 ) ;
V_2 -> V_214 ( & V_7 -> V_211 , F_237 ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_76 = F_2 ( V_2 -> V_212 ) ;
unsigned long V_215 ;
F_235 ( V_2 , L_57 , - 1 , V_76 ) ;
F_135 ( & V_2 -> V_216 ) ;
F_14 () ;
V_215 = V_2 -> V_212 ;
F_235 ( V_2 , L_58 , - 1 , V_215 ) ;
if ( F_82 ( V_215 , ( V_76 + 3 ) & ~ 0x1 ) ) {
F_235 ( V_2 , L_59 , - 1 , V_215 ) ;
F_14 () ;
F_144 ( & V_2 -> V_216 ) ;
return;
}
F_2 ( V_2 -> V_212 ) ++ ;
F_50 ( ( V_2 -> V_212 & 0x1 ) != 1 ) ;
F_235 ( V_2 , L_60 , - 1 , V_2 -> V_212 ) ;
F_14 () ;
F_243 ( & V_2 -> V_213 ) ;
F_244 ( & V_2 -> V_210 , 1 ) ;
F_227 () ;
F_100 (cpu) {
if ( ! F_196 ( V_5 ) && ! F_163 ( V_5 ) )
continue;
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
if ( F_163 ( V_5 ) ) {
F_235 ( V_2 , L_61 , V_5 ,
V_2 -> V_212 ) ;
F_49 ( & V_2 -> V_210 ) ;
F_201 ( & V_7 -> V_211 , F_237 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_93 ) ) {
F_235 ( V_2 , L_62 , V_5 ,
V_2 -> V_212 ) ;
F_245 ( V_5 , F_241 , V_2 , 1 ) ;
} else {
F_235 ( V_2 , L_63 , V_5 ,
V_2 -> V_212 ) ;
}
}
F_229 () ;
if ( F_239 ( & V_2 -> V_210 ) )
F_240 ( & V_2 -> V_213 ) ;
F_14 () ;
F_2 ( V_2 -> V_212 ) ++ ;
F_50 ( ( V_2 -> V_212 & 0x1 ) != 0 ) ;
F_235 ( V_2 , L_64 , - 1 , V_2 -> V_212 ) ;
F_14 () ;
F_246 ( & V_2 -> V_213 ) ;
F_144 ( & V_2 -> V_216 ) ;
}
void F_247 ( void )
{
F_242 ( & V_22 ) ;
}
void F_248 ( void )
{
F_242 ( & V_21 ) ;
}
static void T_4
F_249 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_7 -> V_68 = 1UL << ( V_5 - V_7 -> V_18 -> V_88 ) ;
F_110 ( V_7 ) ;
V_7 -> V_138 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
V_7 -> V_20 = & F_4 ( V_12 , V_5 ) ;
F_50 ( V_7 -> V_20 -> V_53 != V_65 ) ;
F_50 ( F_51 ( & V_7 -> V_20 -> V_20 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_250 ( V_7 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
static void
F_251 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned long V_134 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_135 ( & V_2 -> V_110 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_7 -> V_167 = 1 ;
V_7 -> V_160 = 0 ;
V_7 -> V_161 = V_2 -> V_116 ;
V_7 -> V_156 = V_156 ;
F_110 ( V_7 ) ;
V_7 -> V_20 -> V_53 = V_65 ;
F_252 ( V_7 -> V_20 ) ;
F_244 ( & V_7 -> V_20 -> V_20 ,
( F_51 ( & V_7 -> V_20 -> V_20 ) & ~ 0x1 ) + 1 ) ;
F_119 ( & V_42 -> V_85 ) ;
V_42 = V_7 -> V_18 ;
V_134 = V_7 -> V_68 ;
do {
F_116 ( & V_42 -> V_85 ) ;
V_42 -> V_69 |= V_134 ;
V_134 = V_42 -> V_68 ;
if ( V_42 == V_7 -> V_18 ) {
V_7 -> V_4 = V_42 -> V_3 ;
V_7 -> V_3 = V_42 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_108 = 0 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_65 ) ) ;
}
F_119 ( & V_42 -> V_85 ) ;
V_42 = V_42 -> V_137 ;
} while ( V_42 != NULL && ! ( V_42 -> V_69 & V_134 ) );
F_19 ( V_11 ) ;
F_144 ( & V_2 -> V_110 ) ;
}
static void F_253 ( int V_5 )
{
struct V_1 * V_2 ;
F_12 (rsp)
F_251 ( V_5 , V_2 ) ;
}
static int F_254 ( struct V_217 * V_218 ,
unsigned long V_219 , void * V_220 )
{
long V_5 = ( long ) V_220 ;
struct V_6 * V_7 = F_101 ( V_23 -> V_16 , V_5 ) ;
struct V_40 * V_42 = V_7 -> V_18 ;
struct V_1 * V_2 ;
F_21 ( F_6 ( L_66 ) ) ;
switch ( V_219 ) {
case V_221 :
case V_222 :
F_253 ( V_5 ) ;
F_255 ( V_5 ) ;
break;
case V_223 :
case V_224 :
F_170 ( V_42 , - 1 ) ;
break;
case V_225 :
F_170 ( V_42 , V_5 ) ;
break;
case V_226 :
case V_227 :
F_12 (rsp)
F_167 ( V_2 ) ;
break;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
F_12 (rsp)
F_169 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_21 ( F_6 ( L_67 ) ) ;
return V_232 ;
}
static int F_256 ( struct V_217 * V_218 ,
unsigned long V_219 , void * V_220 )
{
switch ( V_219 ) {
case V_233 :
case V_234 :
if ( V_235 <= 256 )
V_177 = 1 ;
break;
case V_236 :
case V_237 :
V_177 = 0 ;
break;
default:
break;
}
return V_232 ;
}
static int T_4 F_257 ( void )
{
unsigned long V_11 ;
struct V_40 * V_42 ;
struct V_1 * V_2 ;
struct V_55 * V_238 ;
F_12 (rsp) {
V_238 = F_258 ( F_151 , V_2 , L_68 , V_2 -> V_24 ) ;
F_259 ( F_260 ( V_238 ) ) ;
V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_2 -> V_26 = V_238 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_261 ( V_2 ) ;
}
return 0 ;
}
void F_262 ( void )
{
F_263 ( F_213 () != 1 ) ;
F_263 ( F_264 () > 0 ) ;
V_239 = 1 ;
}
static void T_4 F_265 ( struct V_1 * V_2 )
{
int V_46 ;
V_2 -> V_240 [ V_241 - 1 ] = V_242 ;
for ( V_46 = V_241 - 2 ; V_46 >= 0 ; V_46 -- )
V_2 -> V_240 [ V_46 ] = V_243 ;
}
static void T_4 F_265 ( struct V_1 * V_2 )
{
int V_244 ;
int V_245 ;
int V_46 ;
V_245 = V_235 ;
for ( V_46 = V_241 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_244 = V_2 -> V_246 [ V_46 ] ;
V_2 -> V_240 [ V_46 ] = ( V_245 + V_244 - 1 ) / V_244 ;
V_245 = V_244 ;
}
}
static void T_4 F_266 ( struct V_1 * V_2 ,
struct V_6 T_5 * V_16 )
{
static char * V_247 [] = { L_69 ,
L_70 ,
L_71 ,
L_72 } ;
static char * V_248 [] = { L_73 ,
L_74 ,
L_75 ,
L_76 } ;
static T_6 V_249 = 0x1 ;
int V_250 = 1 ;
int V_46 ;
int V_83 ;
struct V_40 * V_42 ;
F_267 ( V_251 > F_268 ( V_247 ) ) ;
if ( V_241 > V_252 )
F_269 ( L_77 ) ;
for ( V_46 = 0 ; V_46 < V_241 ; V_46 ++ )
V_2 -> V_246 [ V_46 ] = V_253 [ V_46 ] ;
for ( V_46 = 1 ; V_46 < V_241 ; V_46 ++ )
V_2 -> V_101 [ V_46 ] = V_2 -> V_101 [ V_46 - 1 ] + V_2 -> V_246 [ V_46 - 1 ] ;
F_265 ( V_2 ) ;
V_2 -> V_17 = V_249 ;
V_249 <<= 1 ;
for ( V_46 = V_241 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_250 *= V_2 -> V_240 [ V_46 ] ;
V_42 = V_2 -> V_101 [ V_46 ] ;
for ( V_83 = 0 ; V_83 < V_2 -> V_246 [ V_46 ] ; V_83 ++ , V_42 ++ ) {
F_270 ( & V_42 -> V_85 ) ;
F_271 ( & V_42 -> V_85 ,
& V_254 [ V_46 ] , V_247 [ V_46 ] ) ;
F_270 ( & V_42 -> V_165 ) ;
F_271 ( & V_42 -> V_165 ,
& V_255 [ V_46 ] , V_248 [ V_46 ] ) ;
V_42 -> V_4 = V_2 -> V_4 ;
V_42 -> V_3 = V_2 -> V_3 ;
V_42 -> V_86 = 0 ;
V_42 -> V_69 = 0 ;
V_42 -> V_88 = V_83 * V_250 ;
V_42 -> V_87 = ( V_83 + 1 ) * V_250 - 1 ;
if ( V_42 -> V_87 >= V_235 )
V_42 -> V_87 = V_235 - 1 ;
if ( V_46 == 0 ) {
V_42 -> V_256 = 0 ;
V_42 -> V_68 = 0 ;
V_42 -> V_137 = NULL ;
} else {
V_42 -> V_256 = V_83 % V_2 -> V_240 [ V_46 - 1 ] ;
V_42 -> V_68 = 1UL << V_42 -> V_256 ;
V_42 -> V_137 = V_2 -> V_101 [ V_46 - 1 ] +
V_83 / V_2 -> V_240 [ V_46 - 1 ] ;
}
V_42 -> V_101 = V_46 ;
F_272 ( & V_42 -> V_257 ) ;
F_273 ( V_42 ) ;
}
}
V_2 -> V_16 = V_16 ;
F_274 ( & V_2 -> V_107 ) ;
V_42 = V_2 -> V_101 [ V_241 - 1 ] ;
F_100 (i) {
while ( V_46 > V_42 -> V_87 )
V_42 ++ ;
F_101 ( V_2 -> V_16 , V_46 ) -> V_18 = V_42 ;
F_249 ( V_46 , V_2 ) ;
}
F_275 ( & V_2 -> V_258 , & V_259 ) ;
}
static void T_4 F_276 ( void )
{
V_183 V_260 ;
int V_46 ;
int V_83 ;
int V_261 = V_235 ;
int V_262 [ V_251 + 1 ] ;
V_260 = V_263 + V_235 / V_264 ;
if ( V_129 == V_97 )
V_129 = V_260 ;
if ( V_133 == V_97 )
V_133 = V_260 ;
if ( V_242 == V_265 &&
V_235 == V_266 )
return;
F_30 ( L_78 ,
V_242 , V_235 ) ;
V_262 [ 0 ] = 1 ;
V_262 [ 1 ] = V_242 ;
for ( V_46 = 2 ; V_46 <= V_251 ; V_46 ++ )
V_262 [ V_46 ] = V_262 [ V_46 - 1 ] * V_243 ;
if ( V_242 < V_265 ||
V_242 > sizeof( unsigned long ) * 8 ||
V_261 > V_262 [ V_251 ] ) {
F_263 ( 1 ) ;
return;
}
for ( V_46 = 1 ; V_46 <= V_251 ; V_46 ++ )
if ( V_261 <= V_262 [ V_46 ] ) {
for ( V_83 = 0 ; V_83 <= V_46 ; V_83 ++ )
V_253 [ V_83 ] =
F_277 ( V_261 , V_262 [ V_46 - V_83 ] ) ;
V_241 = V_46 ;
for ( V_83 = V_46 + 1 ; V_83 <= V_251 ; V_83 ++ )
V_253 [ V_83 ] = 0 ;
break;
}
V_111 = 0 ;
for ( V_46 = 0 ; V_46 <= V_251 ; V_46 ++ )
V_111 += V_253 [ V_46 ] ;
V_111 -= V_261 ;
}
void T_4 F_278 ( void )
{
int V_5 ;
F_279 () ;
F_276 () ;
F_266 ( & V_22 , & V_10 ) ;
F_266 ( & V_21 , & V_8 ) ;
F_280 () ;
F_281 ( V_171 , F_193 ) ;
F_282 ( F_254 , 0 ) ;
F_283 ( F_256 , 0 ) ;
F_284 (cpu)
F_254 ( NULL , V_221 , ( void * ) ( long ) V_5 ) ;
}
