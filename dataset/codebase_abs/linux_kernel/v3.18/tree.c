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
void F_21 ( int V_20 )
{
F_22 ( F_6 ( L_4 ) ) ;
F_3 () ;
F_23 ( V_20 ) ;
if ( F_24 ( F_11 ( V_14 ) ) )
F_9 () ;
F_22 ( F_6 ( L_5 ) ) ;
}
long F_25 ( void )
{
return V_21 . V_3 ;
}
long F_26 ( void )
{
return V_22 . V_3 ;
}
void F_27 ( void )
{
F_28 ( V_23 ) ;
}
void F_29 ( void )
{
F_28 ( & V_22 ) ;
}
void F_30 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp) {
F_31 ( L_6 ,
V_2 -> V_24 , V_2 -> V_25 , V_2 -> V_26 -> V_27 ) ;
}
}
void F_32 ( void )
{
V_28 ++ ;
V_29 = 0 ;
}
void F_33 ( enum V_30 V_31 , int * V_8 ,
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
* V_8 = F_2 ( V_2 -> V_35 ) ;
* V_4 = F_2 ( V_2 -> V_4 ) ;
* V_3 = F_2 ( V_2 -> V_3 ) ;
return;
}
* V_8 = 0 ;
* V_4 = 0 ;
* V_3 = 0 ;
}
void F_34 ( unsigned long V_36 )
{
V_29 ++ ;
}
void F_35 ( void )
{
F_28 ( & V_21 ) ;
}
static int
F_36 ( struct V_9 * V_10 )
{
return & V_10 -> V_37 != V_10 -> V_38 [ V_39 ] &&
V_10 -> V_38 [ V_39 ] != NULL ;
}
static struct V_40 * F_37 ( struct V_1 * V_2 )
{
return & V_2 -> V_41 [ 0 ] ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_40 * V_42 = F_37 ( V_2 ) ;
int V_43 = ( F_2 ( V_42 -> V_3 ) + 1 ) & 0x1 ;
int * V_44 = & V_42 -> V_45 [ V_43 ] ;
return F_2 ( * V_44 ) ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_46 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_38 ( V_2 ) )
return 1 ;
if ( ! V_10 -> V_38 [ V_47 ] )
return 0 ;
if ( * V_10 -> V_38 [ V_48 ] )
return 1 ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ )
if ( V_10 -> V_38 [ V_46 - 1 ] != V_10 -> V_38 [ V_46 ] &&
F_40 ( F_2 ( V_2 -> V_3 ) ,
V_10 -> V_50 [ V_46 ] ) )
return 1 ;
return 0 ;
}
static void F_41 ( struct V_11 * V_12 , long long V_51 ,
bool V_52 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_42 ( F_6 ( L_7 ) , V_51 , V_12 -> V_53 ) ;
if ( ! V_52 && ! F_43 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_44 ( F_45 () ) ;
F_42 ( F_6 ( L_8 ) , V_51 , 0 ) ;
F_46 ( V_57 ) ;
F_47 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
F_13 (rsp) {
V_10 = F_16 ( V_2 -> V_15 ) ;
F_48 ( V_10 ) ;
}
F_49 ( F_45 () ) ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ;
F_53 () ;
F_54 ( ! F_55 ( & V_60 ) ,
L_10 ) ;
F_54 ( ! F_55 ( & V_61 ) ,
L_11 ) ;
F_54 ( ! F_55 ( & V_62 ) ,
L_12 ) ;
}
static void F_56 ( bool V_52 )
{
long long V_51 ;
struct V_11 * V_12 ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
F_51 ( ( V_51 & V_63 ) == 0 ) ;
if ( ( V_51 & V_63 ) == V_64 ) {
V_12 -> V_53 = 0 ;
F_41 ( V_12 , V_51 , V_52 ) ;
} else {
V_12 -> V_53 -= V_64 ;
}
}
void F_57 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_56 ( false ) ;
F_58 ( F_16 ( & V_11 ) , 0 ) ;
F_20 ( V_8 ) ;
}
void F_59 ( void )
{
F_56 ( 1 ) ;
}
void F_60 ( void )
{
unsigned long V_8 ;
long long V_51 ;
struct V_11 * V_12 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
V_12 -> V_53 -- ;
F_51 ( V_12 -> V_53 < 0 ) ;
if ( V_12 -> V_53 )
F_42 ( F_6 ( L_13 ) , V_51 , V_12 -> V_53 ) ;
else
F_41 ( V_12 , V_51 , true ) ;
F_58 ( V_12 , 1 ) ;
F_20 ( V_8 ) ;
}
static void F_61 ( struct V_11 * V_12 , long long V_51 ,
int V_52 )
{
F_62 () ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( ! ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ) ;
F_63 ( F_45 () ) ;
F_42 ( F_6 ( L_14 ) , V_51 , V_12 -> V_53 ) ;
if ( ! V_52 && ! F_43 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_44 ( F_45 () ) ;
F_42 ( F_6 ( L_15 ) ,
V_51 , V_12 -> V_53 ) ;
F_46 ( V_57 ) ;
F_47 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
}
static void F_64 ( bool V_52 )
{
struct V_11 * V_12 ;
long long V_51 ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
F_51 ( V_51 < 0 ) ;
if ( V_51 & V_63 ) {
V_12 -> V_53 += V_64 ;
} else {
V_12 -> V_53 = V_65 ;
F_61 ( V_12 , V_51 , V_52 ) ;
}
}
void F_65 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_64 ( false ) ;
F_66 ( F_16 ( & V_11 ) , 0 ) ;
F_20 ( V_8 ) ;
}
void F_67 ( void )
{
F_64 ( 1 ) ;
}
void F_68 ( void )
{
unsigned long V_8 ;
struct V_11 * V_12 ;
long long V_51 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_51 = V_12 -> V_53 ;
V_12 -> V_53 ++ ;
F_51 ( V_12 -> V_53 == 0 ) ;
if ( V_51 )
F_42 ( F_6 ( L_16 ) , V_51 , V_12 -> V_53 ) ;
else
F_61 ( V_12 , V_51 , true ) ;
F_66 ( V_12 , 1 ) ;
F_20 ( V_8 ) ;
}
void F_69 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
if ( V_12 -> V_66 == 0 &&
( F_52 ( & V_12 -> V_19 ) & 0x1 ) )
return;
V_12 -> V_66 ++ ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( ! ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ) ;
}
void F_70 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
if ( V_12 -> V_66 == 0 ||
-- V_12 -> V_66 != 0 )
return;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ;
}
bool T_2 F_71 ( void )
{
return F_52 ( F_16 ( & V_11 . V_19 ) ) & 0x1 ;
}
bool T_2 F_72 ( void )
{
bool V_67 ;
F_73 () ;
V_67 = F_71 () ;
F_74 () ;
return V_67 ;
}
bool F_75 ( void )
{
struct V_9 * V_10 ;
struct V_40 * V_42 ;
bool V_67 ;
if ( F_76 () )
return true ;
F_73 () ;
V_10 = F_16 ( & V_5 ) ;
V_42 = V_10 -> V_17 ;
V_67 = ( V_10 -> V_68 & V_42 -> V_69 ) ||
! V_70 ;
F_74 () ;
return V_67 ;
}
static int F_77 ( void )
{
return F_4 ( V_11 . V_53 ) <= 1 ;
}
static int F_78 ( struct V_9 * V_10 ,
bool * V_71 , unsigned long * V_72 )
{
V_10 -> V_73 = F_79 ( 0 , & V_10 -> V_19 -> V_19 ) ;
F_80 ( V_10 , V_71 , V_72 ) ;
if ( ( V_10 -> V_73 & 0x1 ) == 0 ) {
F_81 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_20 , F_6 ( L_17 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_82 ( struct V_9 * V_10 ,
bool * V_71 , unsigned long * V_72 )
{
unsigned int V_74 ;
int * V_75 ;
unsigned int V_76 ;
V_74 = ( unsigned int ) F_79 ( 0 , & V_10 -> V_19 -> V_19 ) ;
V_76 = ( unsigned int ) V_10 -> V_73 ;
if ( ( V_74 & 0x1 ) == 0 || F_83 ( V_74 , V_76 + 2 ) ) {
F_81 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_20 , F_6 ( L_17 ) ) ;
V_10 -> V_77 ++ ;
return 1 ;
}
if ( F_84 ( V_10 -> V_2 -> V_78 + 2 , V_79 ) )
return 0 ;
F_85 () ;
if ( F_86 ( V_10 -> V_20 ) ) {
F_81 ( V_10 -> V_2 -> V_24 , V_10 -> V_4 , V_10 -> V_20 , F_6 ( L_18 ) ) ;
V_10 -> V_80 ++ ;
return 1 ;
}
V_75 = & F_87 ( V_14 , V_10 -> V_20 ) ;
if ( F_84 ( V_79 ,
V_10 -> V_2 -> V_78 + V_81 ) ||
F_84 ( V_79 , V_10 -> V_2 -> V_82 ) ) {
if ( ! ( F_2 ( * V_75 ) & V_10 -> V_2 -> V_16 ) ) {
F_2 ( V_10 -> V_18 ) =
F_2 ( V_10 -> V_17 -> V_3 ) ;
F_15 () ;
F_2 ( * V_75 ) =
F_2 ( * V_75 ) + V_10 -> V_2 -> V_16 ;
F_88 ( V_10 -> V_20 ) ;
V_10 -> V_2 -> V_82 += 5 ;
} else if ( F_84 ( V_79 , V_10 -> V_2 -> V_82 ) ) {
F_88 ( V_10 -> V_20 ) ;
V_10 -> V_2 -> V_82 += 5 ;
}
}
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
unsigned long V_83 = V_79 ;
unsigned long j1 ;
V_2 -> V_78 = V_83 ;
F_90 () ;
j1 = F_91 () ;
F_2 ( V_2 -> V_84 ) = V_83 + j1 ;
V_2 -> V_82 = V_83 + j1 / 2 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_20 ;
unsigned long V_8 ;
struct V_40 * V_42 ;
F_93 (rsp, rnp) {
F_94 ( & V_42 -> V_85 , V_8 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_20 = 0 ; V_20 <= V_42 -> V_87 - V_42 -> V_88 ; V_20 ++ )
if ( V_42 -> V_86 & ( 1UL << V_20 ) )
F_95 ( V_42 -> V_88 + V_20 ) ;
}
F_96 ( & V_42 -> V_85 , V_8 ) ;
}
}
static void F_97 ( struct V_1 * V_2 )
{
int V_20 ;
long V_89 ;
unsigned long V_8 ;
int V_90 = 0 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
long V_91 = 0 ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_89 = V_79 - F_2 ( V_2 -> V_84 ) ;
if ( V_89 < V_92 || ! F_1 ( V_2 ) ) {
F_96 ( & V_42 -> V_85 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_84 ) = V_79 + 3 * F_91 () + 3 ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
F_98 ( L_19 ,
V_2 -> V_24 ) ;
F_99 () ;
F_93 (rsp, rnp) {
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_90 += F_100 ( V_42 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_20 = 0 ; V_20 <= V_42 -> V_87 - V_42 -> V_88 ; V_20 ++ )
if ( V_42 -> V_86 & ( 1UL << V_20 ) ) {
F_101 ( V_2 ,
V_42 -> V_88 + V_20 ) ;
V_90 ++ ;
}
}
F_96 ( & V_42 -> V_85 , V_8 ) ;
}
V_42 = F_37 ( V_2 ) ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_90 += F_100 ( V_42 ) ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
F_102 () ;
F_103 (cpu)
V_91 += F_104 ( V_2 -> V_15 , V_20 ) -> V_93 ;
F_105 ( L_20 ,
F_45 () , ( long ) ( V_79 - V_2 -> V_78 ) ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
if ( V_90 == 0 )
F_98 ( L_21 ) ;
else
F_92 ( V_2 ) ;
F_106 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_20 ;
unsigned long V_8 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
long V_91 = 0 ;
F_98 ( L_22 , V_2 -> V_24 ) ;
F_99 () ;
F_101 ( V_2 , F_45 () ) ;
F_102 () ;
F_103 (cpu)
V_91 += F_104 ( V_2 -> V_15 , V_20 ) -> V_93 ;
F_105 ( L_23 ,
V_79 - V_2 -> V_78 ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
F_92 ( V_2 ) ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
if ( F_84 ( V_79 , F_2 ( V_2 -> V_84 ) ) )
F_2 ( V_2 -> V_84 ) = V_79 +
3 * F_91 () + 3 ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
F_88 ( F_45 () ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_9 * V_10 )
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
F_109 () ;
V_95 = F_2 ( V_2 -> V_84 ) ;
F_109 () ;
V_94 = F_2 ( V_2 -> V_78 ) ;
F_109 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_84 ( V_3 , V_4 ) ||
F_40 ( V_83 , V_95 ) ||
F_84 ( V_94 , V_95 ) )
return;
V_42 = V_10 -> V_17 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_42 -> V_86 ) & V_10 -> V_68 ) ) {
F_107 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_84 ( V_83 , V_95 + V_92 ) ) {
F_97 ( V_2 ) ;
}
}
void F_110 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_2 ( V_2 -> V_84 ) = V_79 + V_97 / 2 ;
}
static void F_111 ( struct V_9 * V_10 )
{
int V_46 ;
if ( F_112 ( V_10 ) )
return;
V_10 -> V_37 = NULL ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
V_10 -> V_38 [ V_46 ] = & V_10 -> V_37 ;
}
static unsigned long F_113 ( struct V_1 * V_2 ,
struct V_40 * V_42 )
{
if ( F_37 ( V_2 ) == V_42 && V_42 -> V_4 == V_42 -> V_3 )
return V_42 -> V_3 + 1 ;
return V_42 -> V_3 + 2 ;
}
static void F_114 ( struct V_40 * V_42 , struct V_9 * V_10 ,
unsigned long V_99 , const char * V_100 )
{
F_115 ( V_10 -> V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_3 , V_99 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 , V_100 ) ;
}
static bool V_56
F_116 ( struct V_40 * V_42 , struct V_9 * V_10 ,
unsigned long * V_102 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 = false ;
struct V_40 * V_103 = F_37 ( V_10 -> V_2 ) ;
V_99 = F_113 ( V_10 -> V_2 , V_42 ) ;
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_24 ) ) ;
if ( V_42 -> V_45 [ V_99 & 0x1 ] ) {
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_25 ) ) ;
goto V_104;
}
if ( V_42 -> V_4 != V_42 -> V_3 ||
F_2 ( V_103 -> V_4 ) != F_2 ( V_103 -> V_3 ) ) {
V_42 -> V_45 [ V_99 & 0x1 ] ++ ;
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_26 ) ) ;
goto V_104;
}
if ( V_42 != V_103 ) {
F_117 ( & V_103 -> V_85 ) ;
F_118 () ;
}
V_99 = F_113 ( V_10 -> V_2 , V_103 ) ;
for ( V_46 = V_39 ; V_46 < V_47 ; V_46 ++ )
if ( F_40 ( V_99 , V_10 -> V_50 [ V_46 ] ) )
V_10 -> V_50 [ V_46 ] = V_99 ;
if ( V_103 -> V_45 [ V_99 & 0x1 ] ) {
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_27 ) ) ;
goto V_105;
}
V_103 -> V_45 [ V_99 & 0x1 ] ++ ;
if ( V_103 -> V_4 != V_103 -> V_3 ) {
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_28 ) ) ;
} else {
F_114 ( V_42 , V_10 , V_99 , F_6 ( L_29 ) ) ;
V_67 = F_119 ( V_10 -> V_2 , V_103 , V_10 ) ;
}
V_105:
if ( V_42 != V_103 )
F_120 ( & V_103 -> V_85 ) ;
V_104:
if ( V_102 != NULL )
* V_102 = V_99 ;
return V_67 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_40 * V_42 )
{
int V_99 = V_42 -> V_3 ;
int V_106 ;
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
F_122 ( V_2 , V_42 ) ;
V_42 -> V_45 [ V_99 & 0x1 ] = 0 ;
V_106 = V_42 -> V_45 [ ( V_99 + 1 ) & 0x1 ] ;
F_114 ( V_42 , V_10 , V_99 ,
V_106 ? F_6 ( L_30 ) : F_6 ( L_31 ) ) ;
return V_106 ;
}
static void F_123 ( struct V_1 * V_2 )
{
if ( V_54 == V_2 -> V_26 ||
! F_2 ( V_2 -> V_35 ) ||
! V_2 -> V_26 )
return;
F_124 ( & V_2 -> V_107 ) ;
}
static bool F_125 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 ;
if ( ! V_10 -> V_38 [ V_47 ] || ! * V_10 -> V_38 [ V_39 ] )
return false ;
V_99 = F_113 ( V_2 , V_42 ) ;
for ( V_46 = V_47 - 1 ; V_46 > V_39 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] != V_10 -> V_38 [ V_46 - 1 ] &&
! F_84 ( V_10 -> V_50 [ V_46 ] , V_99 ) )
break;
if ( ++ V_46 >= V_47 )
return false ;
for (; V_46 <= V_47 ; V_46 ++ ) {
V_10 -> V_38 [ V_46 ] = V_10 -> V_38 [ V_47 ] ;
V_10 -> V_50 [ V_46 ] = V_99 ;
}
V_67 = F_116 ( V_42 , V_10 , NULL ) ;
if ( ! * V_10 -> V_38 [ V_49 ] )
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_32 ) ) ;
else
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_33 ) ) ;
return V_67 ;
}
static bool F_126 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
int V_46 , V_83 ;
if ( ! V_10 -> V_38 [ V_47 ] || ! * V_10 -> V_38 [ V_39 ] )
return false ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_40 ( V_42 -> V_3 , V_10 -> V_50 [ V_46 ] ) )
break;
V_10 -> V_38 [ V_39 ] = V_10 -> V_38 [ V_46 ] ;
}
for ( V_83 = V_49 ; V_83 < V_46 ; V_83 ++ )
V_10 -> V_38 [ V_83 ] = V_10 -> V_38 [ V_39 ] ;
for ( V_83 = V_49 ; V_46 < V_47 ; V_46 ++ , V_83 ++ ) {
if ( V_10 -> V_38 [ V_83 ] == V_10 -> V_38 [ V_47 ] )
break;
V_10 -> V_38 [ V_83 ] = V_10 -> V_38 [ V_46 ] ;
V_10 -> V_50 [ V_83 ] = V_10 -> V_50 [ V_46 ] ;
}
return F_125 ( V_2 , V_42 , V_10 ) ;
}
static bool F_127 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
bool V_67 ;
if ( V_10 -> V_3 == V_42 -> V_3 ) {
V_67 = F_125 ( V_2 , V_42 , V_10 ) ;
} else {
V_67 = F_126 ( V_2 , V_42 , V_10 ) ;
V_10 -> V_3 = V_42 -> V_3 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_34 ) ) ;
}
if ( V_10 -> V_4 != V_42 -> V_4 ) {
V_10 -> V_4 = V_42 -> V_4 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_35 ) ) ;
V_10 -> V_6 = 0 ;
V_10 -> V_108 = ! ! ( V_42 -> V_86 & V_10 -> V_68 ) ;
F_128 ( V_10 ) ;
}
return V_67 ;
}
static void F_129 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
bool V_109 ;
struct V_40 * V_42 ;
F_10 ( V_8 ) ;
V_42 = V_10 -> V_17 ;
if ( ( V_10 -> V_4 == F_2 ( V_42 -> V_4 ) &&
V_10 -> V_3 == F_2 ( V_42 -> V_3 ) ) ||
! F_130 ( & V_42 -> V_85 ) ) {
F_20 ( V_8 ) ;
return;
}
F_118 () ;
V_109 = F_127 ( V_2 , V_42 , V_10 ) ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
F_132 () ;
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
if ( ! F_2 ( V_2 -> V_35 ) ) {
F_134 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_2 ( V_2 -> V_35 ) = 0 ;
if ( F_51 ( F_1 ( V_2 ) ) ) {
F_134 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_89 ( V_2 ) ;
F_135 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_24 , V_2 -> V_4 , F_6 ( L_36 ) ) ;
F_134 ( & V_42 -> V_85 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_118 () ;
F_137 (rsp, rnp) {
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
V_10 = F_16 ( V_2 -> V_15 ) ;
F_138 ( V_42 ) ;
V_42 -> V_86 = V_42 -> V_69 ;
F_2 ( V_42 -> V_4 ) = V_2 -> V_4 ;
F_51 ( V_42 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_3 ;
if ( V_42 == V_10 -> V_17 )
( void ) F_127 ( V_2 , V_42 , V_10 ) ;
F_139 ( V_42 ) ;
F_140 ( V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_101 , V_42 -> V_88 ,
V_42 -> V_87 , V_42 -> V_86 ) ;
F_134 ( & V_42 -> V_85 ) ;
F_141 () ;
}
F_142 ( & V_2 -> V_110 ) ;
return 1 ;
}
static int F_143 ( struct V_1 * V_2 , int V_111 )
{
int V_112 = V_111 ;
bool V_71 = false ;
unsigned long V_72 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
V_2 -> V_113 ++ ;
if ( V_112 == V_114 ) {
if ( F_144 ( V_2 ) ) {
V_71 = true ;
V_72 = V_79 - V_97 / 4 ;
}
F_145 ( V_2 , F_78 ,
& V_71 , & V_72 ) ;
F_146 ( V_2 , V_71 , V_72 ) ;
V_112 = V_115 ;
} else {
V_71 = false ;
F_145 ( V_2 , F_82 , & V_71 , & V_72 ) ;
}
if ( F_2 ( V_2 -> V_35 ) & V_116 ) {
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
F_2 ( V_2 -> V_35 ) =
F_2 ( V_2 -> V_35 ) & ~ V_116 ;
F_134 ( & V_42 -> V_85 ) ;
}
return V_112 ;
}
static void F_147 ( struct V_1 * V_2 )
{
unsigned long V_117 ;
bool V_118 = false ;
int V_119 = 0 ;
struct V_9 * V_10 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
V_117 = V_79 - V_2 -> V_78 ;
if ( V_117 > V_2 -> V_120 )
V_2 -> V_120 = V_117 ;
F_134 ( & V_42 -> V_85 ) ;
F_137 (rsp, rnp) {
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_4 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( V_42 == V_10 -> V_17 )
V_118 = F_127 ( V_2 , V_42 , V_10 ) || V_118 ;
V_119 += F_121 ( V_2 , V_42 ) ;
F_134 ( & V_42 -> V_85 ) ;
F_141 () ;
}
V_42 = F_37 ( V_2 ) ;
F_133 ( & V_42 -> V_85 ) ;
F_118 () ;
F_148 ( V_42 , V_119 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_24 , V_2 -> V_3 , F_6 ( L_37 ) ) ;
V_2 -> V_112 = V_121 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
V_118 = F_126 ( V_2 , V_42 , V_10 ) || V_118 ;
if ( V_118 || F_39 ( V_2 , V_10 ) ) {
F_2 ( V_2 -> V_35 ) = V_122 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
}
F_134 ( & V_42 -> V_85 ) ;
}
static int T_3 F_149 ( void * V_123 )
{
int V_112 ;
int V_124 ;
unsigned long V_83 ;
int V_67 ;
struct V_1 * V_2 = V_123 ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
V_2 -> V_25 = V_125 ;
F_150 ( V_2 -> V_107 ,
F_2 ( V_2 -> V_35 ) &
V_122 ) ;
if ( F_131 ( V_2 ) )
break;
F_141 () ;
F_151 ( F_152 ( V_54 ) ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
}
V_112 = V_114 ;
V_83 = V_126 ;
if ( V_83 > V_127 ) {
V_83 = V_127 ;
V_126 = V_127 ;
}
V_67 = 0 ;
for (; ; ) {
if ( ! V_67 )
V_2 -> V_128 = V_79 + V_83 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_2 -> V_25 = V_129 ;
V_67 = F_153 ( V_2 -> V_107 ,
( ( V_124 = F_2 ( V_2 -> V_35 ) ) &
V_116 ) ||
( ! F_2 ( V_42 -> V_86 ) &&
! F_154 ( V_42 ) ) ,
V_83 ) ;
if ( ! F_2 ( V_42 -> V_86 ) &&
! F_154 ( V_42 ) )
break;
if ( F_84 ( V_79 , V_2 -> V_128 ) ||
( V_124 & V_116 ) ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
V_112 = F_143 ( V_2 , V_112 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
F_141 () ;
} else {
F_141 () ;
F_151 ( F_152 ( V_54 ) ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_44 ) ) ;
}
V_83 = V_130 ;
if ( V_83 > V_127 ) {
V_83 = V_127 ;
V_130 = V_127 ;
} else if ( V_83 < 1 ) {
V_83 = 1 ;
V_130 = 1 ;
}
}
F_147 ( V_2 ) ;
}
}
static bool
F_119 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_26 || ! F_39 ( V_2 , V_10 ) ) {
return false ;
}
F_2 ( V_2 -> V_35 ) = V_122 ;
F_5 ( V_2 -> V_24 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
return true ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
bool V_67 = false ;
V_67 = F_126 ( V_2 , V_42 , V_10 ) || V_67 ;
V_67 = F_119 ( V_2 , V_42 , V_10 ) || V_67 ;
return V_67 ;
}
static void F_156 ( struct V_1 * V_2 , unsigned long V_8 )
__releases( rcu_get_root( V_2 )->lock
static void
F_157 ( unsigned long V_131 , struct V_1 * V_2 ,
struct V_40 * V_42 , unsigned long V_8 )
__releases( V_42 -> V_85 )
{
struct V_40 * V_132 ;
for (; ; ) {
if ( ! ( V_42 -> V_86 & V_131 ) ) {
F_96 ( & V_42 -> V_85 , V_8 ) ;
return;
}
V_42 -> V_86 &= ~ V_131 ;
F_158 ( V_2 -> V_24 , V_42 -> V_4 ,
V_131 , V_42 -> V_86 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 ,
! ! V_42 -> V_133 ) ;
if ( V_42 -> V_86 != 0 || F_154 ( V_42 ) ) {
F_96 ( & V_42 -> V_85 , V_8 ) ;
return;
}
V_131 = V_42 -> V_68 ;
if ( V_42 -> V_134 == NULL ) {
break;
}
F_96 ( & V_42 -> V_85 , V_8 ) ;
V_132 = V_42 ;
V_42 = V_42 -> V_134 ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
F_118 () ;
F_51 ( V_132 -> V_86 ) ;
}
F_156 ( V_2 , V_8 ) ;
}
static void
F_159 ( int V_20 , struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
unsigned long V_131 ;
bool V_109 ;
struct V_40 * V_42 ;
V_42 = V_10 -> V_17 ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
F_118 () ;
if ( V_10 -> V_6 == 0 || V_10 -> V_4 != V_42 -> V_4 ||
V_42 -> V_3 == V_42 -> V_4 ) {
V_10 -> V_6 = 0 ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
return;
}
V_131 = V_10 -> V_68 ;
if ( ( V_42 -> V_86 & V_131 ) == 0 ) {
F_96 ( & V_42 -> V_85 , V_8 ) ;
} else {
V_10 -> V_108 = 0 ;
V_109 = F_125 ( V_2 , V_42 , V_10 ) ;
F_157 ( V_131 , V_2 , V_42 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
}
}
static void
F_160 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_129 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_108 )
return;
if ( ! V_10 -> V_6 )
return;
F_159 ( V_10 -> V_20 , V_2 , V_10 ) ;
}
static void
F_161 ( int V_20 , struct V_1 * V_2 ,
struct V_40 * V_42 , struct V_9 * V_10 )
{
if ( F_162 ( V_10 -> V_20 ) )
return;
if ( V_10 -> V_37 != NULL ) {
V_2 -> V_135 += V_10 -> V_135 ;
V_2 -> V_93 += V_10 -> V_93 ;
V_10 -> V_136 += V_10 -> V_93 ;
V_10 -> V_135 = 0 ;
F_2 ( V_10 -> V_93 ) = 0 ;
}
if ( * V_10 -> V_38 [ V_39 ] != NULL ) {
* V_2 -> V_137 = * V_10 -> V_38 [ V_39 ] ;
V_2 -> V_137 = V_10 -> V_38 [ V_47 ] ;
* V_10 -> V_38 [ V_39 ] = NULL ;
}
if ( V_10 -> V_37 != NULL ) {
* V_2 -> V_138 = V_10 -> V_37 ;
V_2 -> V_138 = V_10 -> V_38 [ V_39 ] ;
}
F_111 ( V_10 ) ;
}
static void F_163 ( struct V_1 * V_2 , unsigned long V_8 )
{
int V_46 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
if ( F_164 ( V_2 , V_10 , V_8 ) )
return;
V_10 -> V_135 += V_2 -> V_135 ;
V_10 -> V_93 += V_2 -> V_93 ;
V_10 -> V_139 += V_2 -> V_93 ;
if ( V_2 -> V_135 != V_2 -> V_93 )
F_165 () ;
V_2 -> V_135 = 0 ;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_140 != NULL ) {
* V_2 -> V_138 = * V_10 -> V_38 [ V_39 ] ;
* V_10 -> V_38 [ V_39 ] = V_2 -> V_140 ;
for ( V_46 = V_98 - 1 ; V_46 >= V_39 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] == V_10 -> V_38 [ V_39 ] )
V_10 -> V_38 [ V_46 ] = V_2 -> V_138 ;
V_2 -> V_140 = NULL ;
V_2 -> V_138 = & V_2 -> V_140 ;
}
if ( V_2 -> V_141 != NULL ) {
* V_10 -> V_38 [ V_47 ] = V_2 -> V_141 ;
V_10 -> V_38 [ V_47 ] = V_2 -> V_137 ;
V_2 -> V_141 = NULL ;
V_2 -> V_137 = & V_2 -> V_141 ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
F_167 (unsigned long mask) ;
F_167 ( struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ) ;
F_167 ( struct V_40 * V_42 = V_10 -> V_17 ) ;
F_167 ( V_131 = V_10 -> V_68 ) ;
F_5 ( V_2 -> V_24 ,
V_42 -> V_4 + 1 - ! ! ( V_42 -> V_86 & V_131 ) ,
F_6 ( L_45 ) ) ;
}
static void F_168 ( int V_20 , struct V_1 * V_2 )
{
unsigned long V_8 ;
unsigned long V_131 ;
int V_142 = 0 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
struct V_40 * V_42 = V_10 -> V_17 ;
F_169 ( V_42 , - 1 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_94 ( & V_2 -> V_143 , V_8 ) ;
F_161 ( V_20 , V_2 , V_42 , V_10 ) ;
F_163 ( V_2 , V_8 ) ;
V_131 = V_10 -> V_68 ;
do {
F_117 ( & V_42 -> V_85 ) ;
F_118 () ;
V_42 -> V_69 &= ~ V_131 ;
if ( V_42 -> V_69 != 0 ) {
if ( V_42 != V_10 -> V_17 )
F_120 ( & V_42 -> V_85 ) ;
break;
}
if ( V_42 == V_10 -> V_17 )
V_142 = F_170 ( V_2 , V_42 , V_10 ) ;
else
F_120 ( & V_42 -> V_85 ) ;
V_131 = V_42 -> V_68 ;
V_42 = V_42 -> V_134 ;
} while ( V_42 != NULL );
F_120 ( & V_2 -> V_143 ) ;
V_42 = V_10 -> V_17 ;
if ( V_142 & V_144 )
F_171 ( V_42 , V_8 ) ;
else
F_96 ( & V_42 -> V_85 , V_8 ) ;
if ( V_142 & V_145 )
F_172 ( V_2 , V_42 , true ) ;
F_47 ( V_10 -> V_93 != 0 || V_10 -> V_37 != NULL ,
L_46 ,
V_20 , V_10 -> V_93 , V_10 -> V_37 ) ;
F_111 ( V_10 ) ;
V_10 -> V_38 [ V_47 ] = NULL ;
F_142 ( & V_2 -> V_110 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
}
static void F_168 ( int V_20 , struct V_1 * V_2 )
{
}
static void F_173 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
struct V_146 * V_147 , * V_148 , * * V_149 ;
long V_150 , V_151 , V_152 ;
int V_46 ;
if ( ! F_36 ( V_10 ) ) {
F_174 ( V_2 -> V_24 , V_10 -> V_135 , V_10 -> V_93 , 0 ) ;
F_175 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_10 -> V_37 ) ,
F_176 () , F_43 ( V_54 ) ,
F_177 () ) ;
return;
}
F_10 ( V_8 ) ;
F_51 ( F_86 ( F_45 () ) ) ;
V_150 = V_10 -> V_153 ;
F_174 ( V_2 -> V_24 , V_10 -> V_135 , V_10 -> V_93 , V_150 ) ;
V_148 = V_10 -> V_37 ;
V_10 -> V_37 = * V_10 -> V_38 [ V_39 ] ;
* V_10 -> V_38 [ V_39 ] = NULL ;
V_149 = V_10 -> V_38 [ V_39 ] ;
for ( V_46 = V_98 - 1 ; V_46 >= 0 ; V_46 -- )
if ( V_10 -> V_38 [ V_46 ] == V_10 -> V_38 [ V_39 ] )
V_10 -> V_38 [ V_46 ] = & V_10 -> V_37 ;
F_20 ( V_8 ) ;
V_151 = V_152 = 0 ;
while ( V_148 ) {
V_147 = V_148 -> V_147 ;
F_178 ( V_147 ) ;
F_179 ( V_148 ) ;
if ( F_180 ( V_2 -> V_24 , V_148 ) )
V_152 ++ ;
V_148 = V_147 ;
if ( ++ V_151 >= V_150 &&
( F_176 () ||
( ! F_43 ( V_54 ) && ! F_177 () ) ) )
break;
}
F_10 ( V_8 ) ;
F_175 ( V_2 -> V_24 , V_151 , ! ! V_148 , F_176 () ,
F_43 ( V_54 ) ,
F_177 () ) ;
if ( V_148 != NULL ) {
* V_149 = V_10 -> V_37 ;
V_10 -> V_37 = V_148 ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
if ( & V_10 -> V_37 == V_10 -> V_38 [ V_46 ] )
V_10 -> V_38 [ V_46 ] = V_149 ;
else
break;
}
F_15 () ;
V_10 -> V_135 -= V_152 ;
F_2 ( V_10 -> V_93 ) = V_10 -> V_93 - V_151 ;
V_10 -> V_154 += V_151 ;
if ( V_10 -> V_153 == V_155 && V_10 -> V_93 <= V_156 )
V_10 -> V_153 = V_153 ;
if ( V_10 -> V_93 == 0 && V_10 -> V_157 != 0 ) {
V_10 -> V_157 = 0 ;
V_10 -> V_158 = V_2 -> V_113 ;
} else if ( V_10 -> V_93 < V_10 -> V_157 - V_159 )
V_10 -> V_157 = V_10 -> V_93 ;
F_51 ( ( V_10 -> V_37 == NULL ) != ( V_10 -> V_93 == 0 ) ) ;
F_20 ( V_8 ) ;
if ( F_36 ( V_10 ) )
F_181 () ;
}
void F_182 ( int V_20 , int V_52 )
{
F_22 ( F_6 ( L_47 ) ) ;
F_183 () ;
if ( V_52 || F_77 () ) {
F_3 () ;
F_8 () ;
} else if ( ! F_184 () ) {
F_8 () ;
}
F_185 ( V_20 ) ;
if ( F_186 ( V_20 ) )
F_181 () ;
if ( V_52 )
F_187 ( V_54 ) ;
F_22 ( F_6 ( L_48 ) ) ;
}
static void F_145 ( struct V_1 * V_2 ,
int (* F_188)( struct V_9 * V_2 , bool * V_71 ,
unsigned long * V_72 ) ,
bool * V_71 , unsigned long * V_72 )
{
unsigned long V_160 ;
int V_20 ;
unsigned long V_8 ;
unsigned long V_131 ;
struct V_40 * V_42 ;
F_93 (rsp, rnp) {
F_141 () ;
V_131 = 0 ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
F_118 () ;
if ( ! F_1 ( V_2 ) ) {
F_96 ( & V_42 -> V_85 , V_8 ) ;
return;
}
if ( V_42 -> V_86 == 0 ) {
F_189 ( V_42 , V_8 ) ;
continue;
}
V_20 = V_42 -> V_88 ;
V_160 = 1 ;
for (; V_20 <= V_42 -> V_87 ; V_20 ++ , V_160 <<= 1 ) {
if ( ( V_42 -> V_86 & V_160 ) != 0 ) {
if ( ( V_42 -> V_69 & V_160 ) != 0 )
* V_71 = false ;
if ( F_188 ( F_104 ( V_2 -> V_15 , V_20 ) , V_71 , V_72 ) )
V_131 |= V_160 ;
}
}
if ( V_131 != 0 ) {
F_157 ( V_131 , V_2 , V_42 , V_8 ) ;
continue;
}
F_96 ( & V_42 -> V_85 , V_8 ) ;
}
V_42 = F_37 ( V_2 ) ;
if ( V_42 -> V_86 == 0 ) {
F_94 ( & V_42 -> V_85 , V_8 ) ;
F_118 () ;
F_189 ( V_42 , V_8 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_67 ;
struct V_40 * V_42 ;
struct V_40 * V_161 = NULL ;
V_42 = F_4 ( V_2 -> V_15 -> V_17 ) ;
for (; V_42 != NULL ; V_42 = V_42 -> V_134 ) {
V_67 = ( F_2 ( V_2 -> V_35 ) & V_116 ) ||
! F_130 ( & V_42 -> V_162 ) ;
if ( V_161 != NULL )
F_120 ( & V_161 -> V_162 ) ;
if ( V_67 ) {
V_2 -> V_163 ++ ;
return;
}
V_161 = V_42 ;
}
F_94 ( & V_161 -> V_85 , V_8 ) ;
F_118 () ;
F_120 ( & V_161 -> V_162 ) ;
if ( F_2 ( V_2 -> V_35 ) & V_116 ) {
V_2 -> V_163 ++ ;
F_96 ( & V_161 -> V_85 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_35 ) =
F_2 ( V_2 -> V_35 ) | V_116 ;
F_96 ( & V_161 -> V_85 , V_8 ) ;
F_123 ( V_2 ) ;
}
static void
F_190 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_109 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_51 ( V_10 -> V_164 == 0 ) ;
F_160 ( V_2 , V_10 ) ;
F_10 ( V_8 ) ;
if ( F_39 ( V_2 , V_10 ) ) {
F_117 ( & F_37 ( V_2 ) -> V_85 ) ;
V_109 = F_155 ( V_2 ) ;
F_96 ( & F_37 ( V_2 ) -> V_85 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
} else {
F_20 ( V_8 ) ;
}
if ( F_36 ( V_10 ) )
F_191 ( V_2 , V_10 ) ;
F_48 ( V_10 ) ;
}
static void F_192 ( struct V_165 * V_166 )
{
struct V_1 * V_2 ;
if ( F_86 ( F_45 () ) )
return;
F_22 ( F_6 ( L_49 ) ) ;
F_13 (rsp)
F_190 ( V_2 ) ;
F_22 ( F_6 ( L_50 ) ) ;
}
static void F_191 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
if ( F_24 ( ! F_2 ( V_70 ) ) )
return;
if ( F_193 ( ! V_2 -> V_167 ) ) {
F_173 ( V_2 , V_10 ) ;
return;
}
F_194 () ;
}
static void F_181 ( void )
{
if ( F_195 ( F_45 () ) )
F_196 ( V_168 ) ;
}
static void F_197 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_146 * V_169 , unsigned long V_8 )
{
bool V_109 ;
if ( ! F_72 () && F_195 ( F_45 () ) )
F_181 () ;
if ( F_198 ( V_8 ) || F_86 ( F_45 () ) )
return;
if ( F_24 ( V_10 -> V_93 > V_10 -> V_157 + V_159 ) ) {
F_129 ( V_2 , V_10 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_40 * V_103 = F_37 ( V_2 ) ;
F_117 ( & V_103 -> V_85 ) ;
F_118 () ;
V_109 = F_155 ( V_2 ) ;
F_120 ( & V_103 -> V_85 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
} else {
V_10 -> V_153 = V_155 ;
if ( V_2 -> V_113 == V_10 -> V_158 &&
* V_10 -> V_38 [ V_39 ] != V_169 )
F_28 ( V_2 ) ;
V_10 -> V_158 = V_2 -> V_113 ;
V_10 -> V_157 = V_10 -> V_93 ;
}
}
}
static void F_199 ( struct V_146 * V_170 )
{
}
static void
F_200 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) ,
struct V_1 * V_2 , int V_20 , bool V_172 )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
F_51 ( ( unsigned long ) V_169 & 0x1 ) ;
if ( F_202 ( V_169 ) ) {
F_2 ( V_169 -> F_201 ) = F_199 ;
F_47 ( 1 , L_51 ) ;
return;
}
V_169 -> F_201 = F_201 ;
V_169 -> V_147 = NULL ;
F_10 ( V_8 ) ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( F_24 ( V_10 -> V_38 [ V_47 ] == NULL ) || V_20 != - 1 ) {
int V_173 ;
if ( V_20 != - 1 )
V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
V_173 = ! F_203 ( V_10 , V_169 , V_172 , V_8 ) ;
F_51 ( V_173 ) ;
F_20 ( V_8 ) ;
return;
}
F_2 ( V_10 -> V_93 ) = V_10 -> V_93 + 1 ;
if ( V_172 )
V_10 -> V_135 ++ ;
else
F_165 () ;
F_15 () ;
* V_10 -> V_38 [ V_47 ] = V_169 ;
V_10 -> V_38 [ V_47 ] = & V_169 -> V_147 ;
if ( F_204 ( ( unsigned long ) F_201 ) )
F_205 ( V_2 -> V_24 , V_169 , ( unsigned long ) F_201 ,
V_10 -> V_135 , V_10 -> V_93 ) ;
else
F_206 ( V_2 -> V_24 , V_169 , V_10 -> V_135 , V_10 -> V_93 ) ;
F_197 ( V_2 , V_10 , V_169 , V_8 ) ;
F_20 ( V_8 ) ;
}
void F_207 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , & V_21 , - 1 , 0 ) ;
}
void F_208 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , & V_22 , - 1 , 0 ) ;
}
void F_209 ( struct V_146 * V_169 ,
void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , V_23 , - 1 , 1 ) ;
}
static inline int F_210 ( void )
{
int V_67 ;
F_211 () ;
F_73 () ;
V_67 = F_212 () <= 1 ;
F_74 () ;
return V_67 ;
}
void F_213 ( void )
{
F_54 ( ! F_55 ( & V_61 ) &&
! F_55 ( & V_60 ) &&
! F_55 ( & V_62 ) ,
L_52 ) ;
if ( F_210 () )
return;
if ( V_174 )
F_214 () ;
else
F_215 ( F_207 ) ;
}
void F_216 ( void )
{
F_54 ( ! F_55 ( & V_61 ) &&
! F_55 ( & V_60 ) &&
! F_55 ( & V_62 ) ,
L_53 ) ;
if ( F_210 () )
return;
if ( V_174 )
F_217 () ;
else
F_215 ( F_208 ) ;
}
unsigned long F_218 ( void )
{
F_15 () ;
return F_219 ( & V_23 -> V_4 ) ;
}
void F_220 ( unsigned long V_175 )
{
unsigned long V_176 ;
V_176 = F_219 ( & V_23 -> V_3 ) ;
if ( F_84 ( V_175 , V_176 ) )
F_221 () ;
}
static int F_222 ( void * V_177 )
{
F_15 () ;
return 0 ;
}
void F_214 ( void )
{
long V_178 , V_100 , V_76 ;
int V_179 = 0 ;
struct V_1 * V_2 = & V_21 ;
if ( F_84 ( ( V_180 ) F_223 ( & V_2 -> V_181 ) ,
( V_180 ) F_223 ( & V_2 -> V_182 ) +
V_97 / 8 ) ) {
F_213 () ;
F_224 ( & V_2 -> V_183 ) ;
return;
}
V_76 = F_225 ( & V_2 -> V_181 ) ;
V_178 = V_76 ;
if ( ! F_226 () ) {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_184 ) ;
return;
}
F_51 ( F_86 ( F_227 () ) ) ;
while ( F_228 ( V_185 ,
F_222 ,
NULL ) == - V_186 ) {
F_229 () ;
F_224 ( & V_2 -> V_187 ) ;
V_100 = F_223 ( & V_2 -> V_182 ) ;
if ( F_84 ( ( V_180 ) V_100 , ( V_180 ) V_178 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_188 ) ;
return;
}
if ( V_179 ++ < 10 ) {
F_230 ( V_179 * F_212 () ) ;
} else {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_184 ) ;
return;
}
V_100 = F_223 ( & V_2 -> V_182 ) ;
if ( F_84 ( ( V_180 ) V_100 , ( V_180 ) V_178 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_189 ) ;
return;
}
if ( ! F_226 () ) {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_184 ) ;
return;
}
V_76 = F_223 ( & V_2 -> V_181 ) ;
F_15 () ;
}
F_224 ( & V_2 -> V_190 ) ;
do {
F_224 ( & V_2 -> V_191 ) ;
V_100 = F_223 ( & V_2 -> V_182 ) ;
if ( F_84 ( ( V_180 ) V_100 , ( V_180 ) V_76 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_192 ) ;
break;
}
} while ( F_231 ( & V_2 -> V_182 , V_100 , V_76 ) != V_100 );
F_224 ( & V_2 -> V_193 ) ;
F_229 () ;
}
static int F_232 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_40 * V_42 = V_10 -> V_17 ;
V_10 -> V_194 ++ ;
F_108 ( V_2 , V_10 ) ;
if ( F_233 ( V_2 ) )
return 0 ;
if ( V_70 &&
V_10 -> V_108 && ! V_10 -> V_6 ) {
V_10 -> V_195 ++ ;
} else if ( V_10 -> V_108 && V_10 -> V_6 ) {
V_10 -> V_196 ++ ;
return 1 ;
}
if ( F_36 ( V_10 ) ) {
V_10 -> V_197 ++ ;
return 1 ;
}
if ( F_39 ( V_2 , V_10 ) ) {
V_10 -> V_198 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_3 ) != V_10 -> V_3 ) {
V_10 -> V_199 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_4 ) != V_10 -> V_4 ) {
V_10 -> V_200 ++ ;
return 1 ;
}
if ( F_234 ( V_10 ) ) {
V_10 -> V_201 ++ ;
return 1 ;
}
V_10 -> V_202 ++ ;
return 0 ;
}
static int F_186 ( int V_20 )
{
struct V_1 * V_2 ;
F_13 (rsp)
if ( F_232 ( V_2 , F_104 ( V_2 -> V_15 , V_20 ) ) )
return 1 ;
return 0 ;
}
static int V_56 F_235 ( int V_20 , bool * V_203 )
{
bool V_204 = true ;
bool V_205 = false ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_13 (rsp) {
V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
if ( ! V_10 -> V_37 )
continue;
V_205 = true ;
if ( V_10 -> V_93 != V_10 -> V_135 || ! V_203 ) {
V_204 = false ;
break;
}
}
if ( V_203 )
* V_203 = V_204 ;
return V_205 ;
}
static void F_236 ( struct V_1 * V_2 , const char * V_100 ,
int V_20 , unsigned long V_206 )
{
F_237 ( V_2 -> V_24 , V_100 , V_20 ,
F_52 ( & V_2 -> V_207 ) , V_206 ) ;
}
static void F_238 ( struct V_146 * V_170 )
{
struct V_9 * V_10 = F_239 ( V_170 , struct V_9 , V_208 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( F_240 ( & V_2 -> V_207 ) ) {
F_236 ( V_2 , L_54 , - 1 , V_2 -> V_209 ) ;
F_241 ( & V_2 -> V_210 ) ;
} else {
F_236 ( V_2 , L_55 , - 1 , V_2 -> V_209 ) ;
}
}
static void F_242 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_236 ( V_2 , L_56 , - 1 , V_2 -> V_209 ) ;
F_50 ( & V_2 -> V_207 ) ;
V_2 -> V_211 ( & V_10 -> V_208 , F_238 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_9 * V_10 ;
unsigned long V_76 = F_2 ( V_2 -> V_209 ) ;
unsigned long V_212 ;
F_236 ( V_2 , L_57 , - 1 , V_76 ) ;
F_136 ( & V_2 -> V_213 ) ;
F_15 () ;
V_212 = V_2 -> V_209 ;
F_236 ( V_2 , L_58 , - 1 , V_212 ) ;
if ( F_84 ( V_212 , ( V_76 + 3 ) & ~ 0x1 ) ) {
F_236 ( V_2 , L_59 , - 1 , V_212 ) ;
F_15 () ;
F_142 ( & V_2 -> V_213 ) ;
return;
}
F_2 ( V_2 -> V_209 ) = V_2 -> V_209 + 1 ;
F_51 ( ( V_2 -> V_209 & 0x1 ) != 1 ) ;
F_236 ( V_2 , L_60 , - 1 , V_2 -> V_209 ) ;
F_15 () ;
F_244 ( & V_2 -> V_210 ) ;
F_245 ( & V_2 -> V_207 , 1 ) ;
F_246 () ;
F_103 (cpu) {
if ( ! F_195 ( V_20 ) && ! F_162 ( V_20 ) )
continue;
V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
if ( F_162 ( V_20 ) ) {
if ( ! F_247 ( V_2 , V_20 ) ) {
F_236 ( V_2 , L_61 , V_20 ,
V_2 -> V_209 ) ;
} else {
F_236 ( V_2 , L_62 , V_20 ,
V_2 -> V_209 ) ;
F_50 ( & V_2 -> V_207 ) ;
F_200 ( & V_10 -> V_208 ,
F_238 , V_2 , V_20 , 0 ) ;
}
} else if ( F_2 ( V_10 -> V_93 ) ) {
F_236 ( V_2 , L_63 , V_20 ,
V_2 -> V_209 ) ;
F_248 ( V_20 , F_242 , V_2 , 1 ) ;
} else {
F_236 ( V_2 , L_64 , V_20 ,
V_2 -> V_209 ) ;
}
}
F_229 () ;
if ( F_240 ( & V_2 -> V_207 ) )
F_241 ( & V_2 -> V_210 ) ;
F_15 () ;
F_2 ( V_2 -> V_209 ) = V_2 -> V_209 + 1 ;
F_51 ( ( V_2 -> V_209 & 0x1 ) != 0 ) ;
F_236 ( V_2 , L_65 , - 1 , V_2 -> V_209 ) ;
F_15 () ;
F_249 ( & V_2 -> V_210 ) ;
F_142 ( & V_2 -> V_213 ) ;
}
void F_250 ( void )
{
F_243 ( & V_22 ) ;
}
void F_251 ( void )
{
F_243 ( & V_21 ) ;
}
static void T_4
F_252 ( int V_20 , struct V_1 * V_2 )
{
unsigned long V_8 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_10 -> V_68 = 1UL << ( V_20 - V_10 -> V_17 -> V_88 ) ;
F_111 ( V_10 ) ;
V_10 -> V_135 = 0 ;
F_2 ( V_10 -> V_93 ) = 0 ;
V_10 -> V_19 = & F_87 ( V_11 , V_20 ) ;
F_51 ( V_10 -> V_19 -> V_53 != V_65 ) ;
F_51 ( F_52 ( & V_10 -> V_19 -> V_19 ) != 1 ) ;
V_10 -> V_20 = V_20 ;
V_10 -> V_2 = V_2 ;
F_253 ( V_10 ) ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
}
static void
F_254 ( int V_20 , struct V_1 * V_2 )
{
unsigned long V_8 ;
unsigned long V_131 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_20 ) ;
struct V_40 * V_42 = F_37 ( V_2 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_10 -> V_164 = 1 ;
V_10 -> V_157 = 0 ;
V_10 -> V_158 = V_2 -> V_113 ;
V_10 -> V_153 = V_153 ;
F_111 ( V_10 ) ;
V_10 -> V_19 -> V_53 = V_65 ;
F_255 ( V_10 -> V_19 ) ;
F_245 ( & V_10 -> V_19 -> V_19 ,
( F_52 ( & V_10 -> V_19 -> V_19 ) & ~ 0x1 ) + 1 ) ;
F_120 ( & V_42 -> V_85 ) ;
V_42 = V_10 -> V_17 ;
V_131 = V_10 -> V_68 ;
do {
F_117 ( & V_42 -> V_85 ) ;
V_42 -> V_69 |= V_131 ;
V_131 = V_42 -> V_68 ;
if ( V_42 == V_10 -> V_17 ) {
V_10 -> V_4 = V_42 -> V_3 ;
V_10 -> V_3 = V_42 -> V_3 ;
V_10 -> V_6 = 0 ;
V_10 -> V_108 = 0 ;
F_5 ( V_2 -> V_24 , V_10 -> V_4 , F_6 ( L_66 ) ) ;
}
F_120 ( & V_42 -> V_85 ) ;
V_42 = V_42 -> V_134 ;
} while ( V_42 != NULL && ! ( V_42 -> V_69 & V_131 ) );
F_20 ( V_8 ) ;
F_142 ( & V_2 -> V_110 ) ;
}
static void F_256 ( int V_20 )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_254 ( V_20 , V_2 ) ;
}
static int F_257 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
long V_20 = ( long ) V_217 ;
struct V_9 * V_10 = F_104 ( V_23 -> V_15 , V_20 ) ;
struct V_40 * V_42 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_22 ( F_6 ( L_67 ) ) ;
switch ( V_216 ) {
case V_218 :
case V_219 :
F_256 ( V_20 ) ;
F_258 ( V_20 ) ;
F_259 ( V_20 ) ;
break;
case V_220 :
case V_221 :
F_169 ( V_42 , - 1 ) ;
break;
case V_222 :
F_169 ( V_42 , V_20 ) ;
break;
case V_223 :
case V_224 :
F_13 (rsp)
F_166 ( V_2 ) ;
break;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
F_13 (rsp)
F_168 ( V_20 , V_2 ) ;
break;
default:
break;
}
F_22 ( F_6 ( L_68 ) ) ;
return V_229 ;
}
static int F_260 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
switch ( V_216 ) {
case V_230 :
case V_231 :
if ( V_232 <= 256 )
V_174 = 1 ;
break;
case V_233 :
case V_234 :
V_174 = 0 ;
break;
default:
break;
}
return V_229 ;
}
static int T_4 F_261 ( void )
{
unsigned long V_8 ;
struct V_40 * V_42 ;
struct V_1 * V_2 ;
struct V_55 * V_235 ;
V_70 = 1 ;
F_13 (rsp) {
V_235 = F_262 ( F_149 , V_2 , L_69 , V_2 -> V_24 ) ;
F_263 ( F_264 ( V_235 ) ) ;
V_42 = F_37 ( V_2 ) ;
F_94 ( & V_42 -> V_85 , V_8 ) ;
V_2 -> V_26 = V_235 ;
F_96 ( & V_42 -> V_85 , V_8 ) ;
}
F_265 () ;
F_266 () ;
return 0 ;
}
void F_267 ( void )
{
F_151 ( F_212 () != 1 ) ;
F_151 ( F_268 () > 0 ) ;
V_236 = 1 ;
}
static void T_4 F_269 ( struct V_1 * V_2 )
{
int V_46 ;
V_2 -> V_237 [ V_238 - 1 ] = V_239 ;
for ( V_46 = V_238 - 2 ; V_46 >= 0 ; V_46 -- )
V_2 -> V_237 [ V_46 ] = V_240 ;
}
static void T_4 F_269 ( struct V_1 * V_2 )
{
int V_241 ;
int V_242 ;
int V_46 ;
V_242 = V_232 ;
for ( V_46 = V_238 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_241 = V_2 -> V_243 [ V_46 ] ;
V_2 -> V_237 [ V_46 ] = ( V_242 + V_241 - 1 ) / V_241 ;
V_242 = V_241 ;
}
}
static void T_4 F_270 ( struct V_1 * V_2 ,
struct V_9 T_5 * V_15 )
{
static const char * const V_244 [] = {
L_70 ,
L_71 ,
L_72 ,
L_73 } ;
static const char * const V_245 [] = {
L_74 ,
L_75 ,
L_76 ,
L_77 } ;
static T_6 V_246 = 0x1 ;
int V_247 = 1 ;
int V_46 ;
int V_83 ;
struct V_40 * V_42 ;
F_271 ( V_248 > F_272 ( V_244 ) ) ;
if ( V_238 > V_249 )
F_273 ( L_78 ) ;
for ( V_46 = 0 ; V_46 < V_238 ; V_46 ++ )
V_2 -> V_243 [ V_46 ] = V_250 [ V_46 ] ;
for ( V_46 = 1 ; V_46 < V_238 ; V_46 ++ )
V_2 -> V_101 [ V_46 ] = V_2 -> V_101 [ V_46 - 1 ] + V_2 -> V_243 [ V_46 - 1 ] ;
F_269 ( V_2 ) ;
V_2 -> V_16 = V_246 ;
V_246 <<= 1 ;
for ( V_46 = V_238 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_247 *= V_2 -> V_237 [ V_46 ] ;
V_42 = V_2 -> V_101 [ V_46 ] ;
for ( V_83 = 0 ; V_83 < V_2 -> V_243 [ V_46 ] ; V_83 ++ , V_42 ++ ) {
F_274 ( & V_42 -> V_85 ) ;
F_275 ( & V_42 -> V_85 ,
& V_251 [ V_46 ] , V_244 [ V_46 ] ) ;
F_274 ( & V_42 -> V_162 ) ;
F_275 ( & V_42 -> V_162 ,
& V_252 [ V_46 ] , V_245 [ V_46 ] ) ;
V_42 -> V_4 = V_2 -> V_4 ;
V_42 -> V_3 = V_2 -> V_3 ;
V_42 -> V_86 = 0 ;
V_42 -> V_69 = 0 ;
V_42 -> V_88 = V_83 * V_247 ;
V_42 -> V_87 = ( V_83 + 1 ) * V_247 - 1 ;
if ( V_42 -> V_87 >= V_232 )
V_42 -> V_87 = V_232 - 1 ;
if ( V_46 == 0 ) {
V_42 -> V_253 = 0 ;
V_42 -> V_68 = 0 ;
V_42 -> V_134 = NULL ;
} else {
V_42 -> V_253 = V_83 % V_2 -> V_237 [ V_46 - 1 ] ;
V_42 -> V_68 = 1UL << V_42 -> V_253 ;
V_42 -> V_134 = V_2 -> V_101 [ V_46 - 1 ] +
V_83 / V_2 -> V_237 [ V_46 - 1 ] ;
}
V_42 -> V_101 = V_46 ;
F_276 ( & V_42 -> V_254 ) ;
F_277 ( V_42 ) ;
}
}
V_2 -> V_15 = V_15 ;
F_278 ( & V_2 -> V_107 ) ;
V_42 = V_2 -> V_101 [ V_238 - 1 ] ;
F_103 (i) {
while ( V_46 > V_42 -> V_87 )
V_42 ++ ;
F_104 ( V_2 -> V_15 , V_46 ) -> V_17 = V_42 ;
F_252 ( V_46 , V_2 ) ;
}
F_279 ( & V_2 -> V_255 , & V_256 ) ;
}
static void T_4 F_280 ( void )
{
V_180 V_257 ;
int V_46 ;
int V_83 ;
int V_258 = V_232 ;
int V_259 [ V_248 + 1 ] ;
V_257 = V_260 + V_232 / V_261 ;
if ( V_126 == V_97 )
V_126 = V_257 ;
if ( V_130 == V_97 )
V_130 = V_257 ;
if ( V_239 == V_262 &&
V_232 == V_263 )
return;
F_31 ( L_79 ,
V_239 , V_232 ) ;
V_259 [ 0 ] = 1 ;
V_259 [ 1 ] = V_239 ;
for ( V_46 = 2 ; V_46 <= V_248 ; V_46 ++ )
V_259 [ V_46 ] = V_259 [ V_46 - 1 ] * V_240 ;
if ( V_239 < V_262 ||
V_239 > sizeof( unsigned long ) * 8 ||
V_258 > V_259 [ V_248 ] ) {
F_151 ( 1 ) ;
return;
}
for ( V_46 = 1 ; V_46 <= V_248 ; V_46 ++ )
if ( V_258 <= V_259 [ V_46 ] ) {
for ( V_83 = 0 ; V_83 <= V_46 ; V_83 ++ )
V_250 [ V_83 ] =
F_281 ( V_258 , V_259 [ V_46 - V_83 ] ) ;
V_238 = V_46 ;
for ( V_83 = V_46 + 1 ; V_83 <= V_248 ; V_83 ++ )
V_250 [ V_83 ] = 0 ;
break;
}
V_264 = 0 ;
for ( V_46 = 0 ; V_46 <= V_248 ; V_46 ++ )
V_264 += V_250 [ V_46 ] ;
V_264 -= V_258 ;
}
void T_4 F_282 ( void )
{
int V_20 ;
F_283 () ;
F_280 () ;
F_270 ( & V_22 , & V_7 ) ;
F_270 ( & V_21 , & V_5 ) ;
F_284 () ;
F_285 ( V_168 , F_192 ) ;
F_286 ( F_257 , 0 ) ;
F_287 ( F_260 , 0 ) ;
F_288 (cpu)
F_257 ( NULL , V_218 , ( void * ) ( long ) V_20 ) ;
}
