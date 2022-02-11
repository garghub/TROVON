static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_8 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( L_1 , V_7 -> V_4 , L_2 ) ;
V_7 -> V_9 = 1 ;
}
void F_6 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_10 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( L_3 , V_7 -> V_4 , L_2 ) ;
V_7 -> V_9 = 1 ;
}
void F_7 ( int V_5 )
{
F_8 ( L_4 ) ;
F_3 ( V_5 ) ;
F_9 ( V_5 ) ;
F_8 ( L_5 ) ;
}
long F_10 ( void )
{
return V_11 . V_3 ;
}
long F_11 ( void )
{
return V_12 . V_3 ;
}
void F_12 ( void )
{
F_13 ( & V_12 ) ;
}
void F_14 ( void )
{
V_13 ++ ;
V_14 = 0 ;
}
void F_15 ( unsigned long V_15 )
{
V_14 ++ ;
}
void F_16 ( void )
{
F_13 ( & V_11 ) ;
}
static int
F_17 ( struct V_6 * V_7 )
{
return & V_7 -> V_16 != V_7 -> V_17 [ V_18 ] &&
V_7 -> V_17 [ V_18 ] != NULL ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_19 * * V_20 ;
V_20 = V_7 -> V_17 [ V_18 +
( F_2 ( V_2 -> V_3 ) != V_7 -> V_3 ) ] ;
return V_7 -> V_17 [ V_18 ] && V_20 && * V_20 &&
! F_1 ( V_2 ) ;
}
static struct V_21 * F_19 ( struct V_1 * V_2 )
{
return & V_2 -> V_22 [ 0 ] ;
}
static void F_20 ( struct V_23 * V_24 , long long V_25 ,
bool V_26 )
{
F_21 ( L_6 , V_25 , 0 ) ;
if ( ! V_26 && ! F_22 ( V_27 ) ) {
struct V_28 * V_29 = F_23 ( F_24 () ) ;
F_21 ( L_7 , V_25 , 0 ) ;
F_25 ( V_30 ) ;
F_26 ( 1 , L_8 ,
V_27 -> V_31 , V_27 -> V_32 ,
V_29 -> V_31 , V_29 -> V_32 ) ;
}
F_27 ( F_24 () ) ;
F_28 () ;
F_29 ( & V_24 -> V_33 ) ;
F_30 () ;
F_31 ( F_32 ( & V_24 -> V_33 ) & 0x1 ) ;
F_33 ( ! F_34 ( & V_34 ) ,
L_9 ) ;
F_33 ( ! F_34 ( & V_35 ) ,
L_10 ) ;
F_33 ( ! F_34 ( & V_36 ) ,
L_11 ) ;
}
static void F_35 ( bool V_26 )
{
long long V_25 ;
struct V_23 * V_24 ;
V_24 = & F_36 ( V_23 ) ;
V_25 = V_24 -> V_37 ;
F_31 ( ( V_25 & V_38 ) == 0 ) ;
if ( ( V_25 & V_38 ) == V_39 )
V_24 -> V_37 = 0 ;
else
V_24 -> V_37 -= V_39 ;
F_20 ( V_24 , V_25 , V_26 ) ;
}
void F_37 ( void )
{
unsigned long V_40 ;
F_38 ( V_40 ) ;
F_35 ( false ) ;
F_39 ( V_40 ) ;
}
void F_40 ( void )
{
F_35 ( 1 ) ;
}
void F_41 ( void )
{
unsigned long V_40 ;
struct V_23 * V_24 ;
F_38 ( V_40 ) ;
V_24 = & F_36 ( V_23 ) ;
F_31 ( ! ( V_24 -> V_37 & V_41 ) ) ;
V_24 -> V_37 = 1 ;
F_39 ( V_40 ) ;
}
void F_42 ( void )
{
unsigned long V_40 ;
long long V_25 ;
struct V_23 * V_24 ;
F_38 ( V_40 ) ;
V_24 = & F_36 ( V_23 ) ;
V_25 = V_24 -> V_37 ;
V_24 -> V_37 -- ;
F_31 ( V_24 -> V_37 < 0 ) ;
if ( V_24 -> V_37 )
F_21 ( L_12 , V_25 , V_24 -> V_37 ) ;
else
F_20 ( V_24 , V_25 , true ) ;
F_39 ( V_40 ) ;
}
static void F_43 ( struct V_23 * V_24 , long long V_25 ,
int V_26 )
{
F_28 () ;
F_29 ( & V_24 -> V_33 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_24 -> V_33 ) & 0x1 ) ) ;
F_44 ( F_24 () ) ;
F_21 ( L_13 , V_25 , V_24 -> V_37 ) ;
if ( ! V_26 && ! F_22 ( V_27 ) ) {
struct V_28 * V_29 = F_23 ( F_24 () ) ;
F_21 ( L_14 ,
V_25 , V_24 -> V_37 ) ;
F_25 ( V_30 ) ;
F_26 ( 1 , L_8 ,
V_27 -> V_31 , V_27 -> V_32 ,
V_29 -> V_31 , V_29 -> V_32 ) ;
}
}
static void F_45 ( bool V_26 )
{
struct V_23 * V_24 ;
long long V_25 ;
V_24 = & F_36 ( V_23 ) ;
V_25 = V_24 -> V_37 ;
F_31 ( V_25 < 0 ) ;
if ( V_25 & V_38 )
V_24 -> V_37 += V_39 ;
else
V_24 -> V_37 = V_42 ;
F_43 ( V_24 , V_25 , V_26 ) ;
}
void F_46 ( void )
{
unsigned long V_40 ;
F_38 ( V_40 ) ;
F_45 ( false ) ;
F_39 ( V_40 ) ;
}
void F_47 ( void )
{
F_45 ( 1 ) ;
}
void F_48 ( void )
{
unsigned long V_40 ;
struct V_23 * V_24 ;
F_38 ( V_40 ) ;
V_24 = & F_36 ( V_23 ) ;
F_31 ( V_24 -> V_37 & V_38 ) ;
V_24 -> V_37 += V_42 ;
F_39 ( V_40 ) ;
}
void F_49 ( void )
{
unsigned long V_40 ;
struct V_23 * V_24 ;
long long V_25 ;
F_38 ( V_40 ) ;
V_24 = & F_36 ( V_23 ) ;
V_25 = V_24 -> V_37 ;
V_24 -> V_37 ++ ;
F_31 ( V_24 -> V_37 == 0 ) ;
if ( V_25 )
F_21 ( L_15 , V_25 , V_24 -> V_37 ) ;
else
F_43 ( V_24 , V_25 , true ) ;
F_39 ( V_40 ) ;
}
void F_50 ( void )
{
struct V_23 * V_24 = & F_36 ( V_23 ) ;
if ( V_24 -> V_43 == 0 &&
( F_32 ( & V_24 -> V_33 ) & 0x1 ) )
return;
V_24 -> V_43 ++ ;
F_28 () ;
F_29 ( & V_24 -> V_33 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_24 -> V_33 ) & 0x1 ) ) ;
}
void F_51 ( void )
{
struct V_23 * V_24 = & F_36 ( V_23 ) ;
if ( V_24 -> V_43 == 0 ||
-- V_24 -> V_43 != 0 )
return;
F_28 () ;
F_29 ( & V_24 -> V_33 ) ;
F_30 () ;
F_31 ( F_32 ( & V_24 -> V_33 ) & 0x1 ) ;
}
int F_52 ( void )
{
int V_44 ;
F_53 () ;
V_44 = ( F_32 ( & F_36 ( V_23 ) . V_33 ) & 0x1 ) == 0 ;
F_54 () ;
return V_44 ;
}
bool F_55 ( void )
{
struct V_6 * V_7 ;
struct V_21 * V_45 ;
bool V_44 ;
if ( F_56 () )
return 1 ;
F_53 () ;
V_7 = & F_36 ( V_8 ) ;
V_45 = V_7 -> V_46 ;
V_44 = ( V_7 -> V_47 & V_45 -> V_48 ) ||
! V_49 ;
F_54 () ;
return V_44 ;
}
int F_57 ( void )
{
return F_36 ( V_23 ) . V_37 <= 1 ;
}
static int F_58 ( struct V_6 * V_7 )
{
V_7 -> V_50 = F_59 ( 0 , & V_7 -> V_33 -> V_33 ) ;
return ( V_7 -> V_50 & 0x1 ) == 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
unsigned int V_51 ;
unsigned int V_52 ;
V_51 = ( unsigned int ) F_59 ( 0 , & V_7 -> V_33 -> V_33 ) ;
V_52 = ( unsigned int ) V_7 -> V_50 ;
if ( ( V_51 & 0x1 ) == 0 || F_61 ( V_51 , V_52 + 2 ) ) {
F_62 ( V_7 -> V_2 -> V_53 , V_7 -> V_4 , V_7 -> V_5 , L_16 ) ;
V_7 -> V_54 ++ ;
return 1 ;
}
if ( F_63 ( V_7 -> V_2 -> V_55 + 2 , V_56 ) )
return 0 ;
F_64 () ;
if ( F_65 ( V_7 -> V_5 ) ) {
F_62 ( V_7 -> V_2 -> V_53 , V_7 -> V_4 , V_7 -> V_5 , L_17 ) ;
V_7 -> V_57 ++ ;
return 1 ;
}
return 0 ;
}
static int F_66 ( void )
{
int V_58 = F_2 ( V_59 ) ;
if ( V_58 < 3 ) {
F_2 ( V_59 ) = 3 ;
V_58 = 3 ;
} else if ( V_58 > 300 ) {
F_2 ( V_59 ) = 300 ;
V_58 = 300 ;
}
return V_58 * V_60 + V_61 ;
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_56 ;
V_2 -> V_62 = V_56 + F_66 () ;
}
static void F_68 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_40 ;
struct V_21 * V_45 ;
F_69 (rsp, rnp) {
F_70 ( & V_45 -> V_63 , V_40 ) ;
if ( V_45 -> V_64 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_45 -> V_65 - V_45 -> V_66 ; V_5 ++ )
if ( V_45 -> V_64 & ( 1UL << V_5 ) )
F_71 ( V_45 -> V_66 + V_5 ) ;
}
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
int V_5 ;
long V_67 ;
unsigned long V_40 ;
int V_68 = 0 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
long V_69 = 0 ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_67 = V_56 - V_2 -> V_62 ;
if ( V_67 < V_70 || ! F_1 ( V_2 ) ) {
F_72 ( & V_45 -> V_63 , V_40 ) ;
return;
}
V_2 -> V_62 = V_56 + 3 * F_66 () + 3 ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
F_74 ( V_71 L_18 ,
V_2 -> V_53 ) ;
F_75 () ;
F_69 (rsp, rnp) {
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_68 += F_76 ( V_45 ) ;
if ( V_45 -> V_64 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_45 -> V_65 - V_45 -> V_66 ; V_5 ++ )
if ( V_45 -> V_64 & ( 1UL << V_5 ) ) {
F_77 ( V_2 ,
V_45 -> V_66 + V_5 ) ;
V_68 ++ ;
}
}
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
V_45 = F_19 ( V_2 ) ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_68 += F_76 ( V_45 ) ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
F_78 () ;
F_79 (cpu)
V_69 += F_80 ( V_2 -> V_72 , V_5 ) -> V_73 ;
F_81 ( L_19 ,
F_24 () , ( long ) ( V_56 - V_2 -> V_55 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_69 ) ;
if ( V_68 == 0 )
F_74 ( V_71 L_20 ) ;
else if ( ! F_82 () )
F_68 ( V_2 ) ;
F_83 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_40 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
long V_69 = 0 ;
F_74 ( V_71 L_21 , V_2 -> V_53 ) ;
F_75 () ;
F_77 ( V_2 , F_24 () ) ;
F_78 () ;
F_79 (cpu)
V_69 += F_80 ( V_2 -> V_72 , V_5 ) -> V_73 ;
F_81 ( L_22 ,
V_56 - V_2 -> V_55 , V_2 -> V_4 , V_2 -> V_3 , V_69 ) ;
if ( ! F_82 () )
F_85 () ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
if ( F_63 ( V_56 , V_2 -> V_62 ) )
V_2 -> V_62 = V_56 +
3 * F_66 () + 3 ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
F_86 () ;
}
static void F_87 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_74 ;
unsigned long V_75 ;
struct V_21 * V_45 ;
if ( V_76 )
return;
V_74 = F_2 ( V_56 ) ;
V_75 = F_2 ( V_2 -> V_62 ) ;
V_45 = V_7 -> V_46 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_45 -> V_64 ) & V_7 -> V_47 ) && F_63 ( V_74 , V_75 ) ) {
F_84 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_63 ( V_74 , V_75 + V_70 ) ) {
F_73 ( V_2 ) ;
}
}
static int F_88 ( struct V_77 * V_78 , unsigned long V_79 , void * V_80 )
{
V_76 = 1 ;
return V_81 ;
}
void F_89 ( void )
{
struct V_1 * V_2 ;
F_90 (rsp)
V_2 -> V_62 = V_56 + V_82 / 2 ;
}
static void T_1 F_91 ( void )
{
F_92 ( & V_83 , & V_84 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_21 * V_45 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_45 -> V_4 ) {
V_7 -> V_4 = V_45 -> V_4 ;
F_5 ( V_2 -> V_53 , V_7 -> V_4 , L_23 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_85 = ! ! ( V_45 -> V_64 & V_7 -> V_47 ) ;
F_94 ( V_7 ) ;
}
}
static void F_95 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_40 ;
struct V_21 * V_45 ;
F_38 ( V_40 ) ;
V_45 = V_7 -> V_46 ;
if ( V_7 -> V_4 == F_2 ( V_45 -> V_4 ) ||
! F_96 ( & V_45 -> V_63 ) ) {
F_39 ( V_40 ) ;
return;
}
F_93 ( V_2 , V_45 , V_7 ) ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
static int
F_97 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_40 ;
int V_44 = 0 ;
F_38 ( V_40 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_95 ( V_2 , V_7 ) ;
V_44 = 1 ;
}
F_39 ( V_40 ) ;
return V_44 ;
}
static void F_98 ( struct V_6 * V_7 )
{
int V_86 ;
V_7 -> V_16 = NULL ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
V_7 -> V_17 [ V_86 ] = & V_7 -> V_16 ;
F_99 ( V_7 ) ;
}
static void
F_100 ( struct V_1 * V_2 , struct V_21 * V_45 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_45 -> V_3 ) {
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_88 ] ;
V_7 -> V_17 [ V_88 ] = V_7 -> V_17 [ V_89 ] ;
V_7 -> V_17 [ V_89 ] = V_7 -> V_17 [ V_90 ] ;
V_7 -> V_3 = V_45 -> V_3 ;
F_5 ( V_2 -> V_53 , V_7 -> V_4 , L_24 ) ;
if ( F_101 ( V_7 -> V_4 , V_7 -> V_3 ) ) {
V_7 -> V_4 = V_7 -> V_3 ;
V_7 -> V_9 = 0 ;
}
if ( ( V_45 -> V_64 & V_7 -> V_47 ) == 0 )
V_7 -> V_85 = 0 ;
}
}
static void
F_102 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_40 ;
struct V_21 * V_45 ;
F_38 ( V_40 ) ;
V_45 = V_7 -> V_46 ;
if ( V_7 -> V_3 == F_2 ( V_45 -> V_3 ) ||
! F_96 ( & V_45 -> V_63 ) ) {
F_39 ( V_40 ) ;
return;
}
F_100 ( V_2 , V_45 , V_7 ) ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
static void
F_103 ( struct V_1 * V_2 , struct V_21 * V_45 , struct V_6 * V_7 )
{
F_100 ( V_2 , V_45 , V_7 ) ;
F_93 ( V_2 , V_45 , V_7 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
F_105 ( & V_45 -> V_63 ) ;
V_2 -> V_91 = 0 ;
if ( F_1 ( V_2 ) ) {
F_106 ( & V_45 -> V_63 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_53 , V_2 -> V_4 , L_25 ) ;
F_67 ( V_2 ) ;
F_106 ( & V_45 -> V_63 ) ;
F_107 ( & V_2 -> V_92 ) ;
F_108 (rsp, rnp) {
F_105 ( & V_45 -> V_63 ) ;
V_7 = F_109 ( V_2 -> V_72 ) ;
F_110 ( V_45 ) ;
V_45 -> V_64 = V_45 -> V_48 ;
V_45 -> V_4 = V_2 -> V_4 ;
F_31 ( V_45 -> V_3 != V_2 -> V_3 ) ;
V_45 -> V_3 = V_2 -> V_3 ;
if ( V_45 == V_7 -> V_46 )
F_103 ( V_2 , V_45 , V_7 ) ;
F_111 ( V_45 ) ;
F_112 ( V_2 -> V_53 , V_45 -> V_4 ,
V_45 -> V_93 , V_45 -> V_66 ,
V_45 -> V_65 , V_45 -> V_64 ) ;
F_106 ( & V_45 -> V_63 ) ;
#ifdef F_113
if ( ( F_114 () % ( V_94 * 8 ) ) == 0 )
F_115 ( 2 ) ;
#endif
F_116 () ;
}
F_117 ( & V_2 -> V_92 ) ;
return 1 ;
}
int F_118 ( struct V_1 * V_2 , int V_95 )
{
int V_96 = V_95 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
V_2 -> V_97 ++ ;
if ( V_96 == V_98 ) {
F_119 ( V_2 , F_58 ) ;
V_96 = V_99 ;
} else {
F_119 ( V_2 , F_60 ) ;
}
if ( F_2 ( V_2 -> V_91 ) & V_100 ) {
F_105 ( & V_45 -> V_63 ) ;
V_2 -> V_91 &= ~ V_100 ;
F_106 ( & V_45 -> V_63 ) ;
}
return V_96 ;
}
static void F_120 ( struct V_1 * V_2 )
{
unsigned long V_101 ;
struct V_6 * V_7 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
F_105 ( & V_45 -> V_63 ) ;
V_101 = V_56 - V_2 -> V_55 ;
if ( V_101 > V_2 -> V_102 )
V_2 -> V_102 = V_101 ;
F_106 ( & V_45 -> V_63 ) ;
F_108 (rsp, rnp) {
F_105 ( & V_45 -> V_63 ) ;
V_45 -> V_3 = V_2 -> V_4 ;
F_106 ( & V_45 -> V_63 ) ;
F_116 () ;
}
V_45 = F_19 ( V_2 ) ;
F_105 ( & V_45 -> V_63 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_53 , V_2 -> V_3 , L_26 ) ;
V_2 -> V_96 = V_103 ;
V_7 = F_109 ( V_2 -> V_72 ) ;
if ( F_18 ( V_2 , V_7 ) )
V_2 -> V_91 = 1 ;
F_106 ( & V_45 -> V_63 ) ;
}
static int T_2 F_121 ( void * V_104 )
{
int V_96 ;
unsigned long V_74 ;
int V_44 ;
struct V_1 * V_2 = V_104 ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_122 ( V_2 -> V_105 ,
V_2 -> V_91 &
V_106 ) ;
if ( ( V_2 -> V_91 & V_106 ) &&
F_104 ( V_2 ) )
break;
F_116 () ;
F_123 ( V_27 ) ;
}
V_96 = V_98 ;
V_74 = V_107 ;
if ( V_74 > V_60 ) {
V_74 = V_60 ;
V_107 = V_60 ;
}
for (; ; ) {
V_2 -> V_108 = V_56 + V_74 ;
V_44 = F_124 ( V_2 -> V_105 ,
( V_2 -> V_91 & V_100 ) ||
( ! F_2 ( V_45 -> V_64 ) &&
! F_125 ( V_45 ) ) ,
V_74 ) ;
if ( ! F_2 ( V_45 -> V_64 ) &&
! F_125 ( V_45 ) )
break;
if ( V_44 == 0 || ( V_2 -> V_91 & V_100 ) ) {
V_96 = F_118 ( V_2 , V_96 ) ;
F_116 () ;
} else {
F_116 () ;
F_123 ( V_27 ) ;
}
V_74 = V_109 ;
if ( V_74 > V_60 ) {
V_74 = V_60 ;
V_109 = V_60 ;
} else if ( V_74 < 1 ) {
V_74 = 1 ;
V_109 = 1 ;
}
}
F_120 ( V_2 ) ;
}
}
static void
F_126 ( struct V_1 * V_2 , unsigned long V_40 )
__releases( rcu_get_root( V_2 )->lock
static void F_127 ( struct V_1 * V_2 , unsigned long V_40 )
__releases( rcu_get_root( V_2 )->lock
static void
F_128 ( unsigned long V_110 , struct V_1 * V_2 ,
struct V_21 * V_45 , unsigned long V_40 )
__releases( V_45 -> V_63 )
{
struct V_21 * V_111 ;
for (; ; ) {
if ( ! ( V_45 -> V_64 & V_110 ) ) {
F_72 ( & V_45 -> V_63 , V_40 ) ;
return;
}
V_45 -> V_64 &= ~ V_110 ;
F_129 ( V_2 -> V_53 , V_45 -> V_4 ,
V_110 , V_45 -> V_64 , V_45 -> V_93 ,
V_45 -> V_66 , V_45 -> V_65 ,
! ! V_45 -> V_112 ) ;
if ( V_45 -> V_64 != 0 || F_125 ( V_45 ) ) {
F_72 ( & V_45 -> V_63 , V_40 ) ;
return;
}
V_110 = V_45 -> V_47 ;
if ( V_45 -> V_113 == NULL ) {
break;
}
F_72 ( & V_45 -> V_63 , V_40 ) ;
V_111 = V_45 ;
V_45 = V_45 -> V_113 ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
F_31 ( V_111 -> V_64 ) ;
}
F_127 ( V_2 , V_40 ) ;
}
static void
F_130 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_40 ;
unsigned long V_110 ;
struct V_21 * V_45 ;
V_45 = V_7 -> V_46 ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_45 -> V_4 ||
V_45 -> V_3 == V_45 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
return;
}
V_110 = V_7 -> V_47 ;
if ( ( V_45 -> V_64 & V_110 ) == 0 ) {
F_72 ( & V_45 -> V_63 , V_40 ) ;
} else {
V_7 -> V_85 = 0 ;
V_7 -> V_17 [ V_89 ] = V_7 -> V_17 [ V_90 ] ;
F_128 ( V_110 , V_2 , V_45 , V_40 ) ;
}
}
static void
F_131 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_97 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_85 )
return;
if ( ! V_7 -> V_9 )
return;
F_130 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_132 ( int V_5 , struct V_1 * V_2 ,
struct V_21 * V_45 , struct V_6 * V_7 )
{
if ( F_133 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_114 += V_7 -> V_114 ;
V_2 -> V_73 += V_7 -> V_73 ;
V_7 -> V_115 += V_7 -> V_73 ;
V_7 -> V_114 = 0 ;
F_2 ( V_7 -> V_73 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_116 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_116 = V_7 -> V_17 [ V_90 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_117 = V_7 -> V_16 ;
V_2 -> V_117 = V_7 -> V_17 [ V_18 ] ;
}
F_98 ( V_7 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_86 ;
struct V_6 * V_7 = F_135 ( V_2 -> V_72 ) ;
if ( F_136 ( V_2 , V_7 ) )
return;
V_7 -> V_114 += V_2 -> V_114 ;
V_7 -> V_73 += V_2 -> V_73 ;
V_7 -> V_118 += V_2 -> V_73 ;
if ( V_2 -> V_114 != V_2 -> V_73 )
F_137 () ;
V_2 -> V_114 = 0 ;
V_2 -> V_73 = 0 ;
if ( V_2 -> V_119 != NULL ) {
* V_2 -> V_117 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_119 ;
for ( V_86 = V_87 - 1 ; V_86 >= V_18 ; V_86 -- )
if ( V_7 -> V_17 [ V_86 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_86 ] = V_2 -> V_117 ;
V_2 -> V_119 = NULL ;
V_2 -> V_117 = & V_2 -> V_119 ;
}
if ( V_2 -> V_120 != NULL ) {
* V_7 -> V_17 [ V_90 ] = V_2 -> V_120 ;
V_7 -> V_17 [ V_90 ] = V_2 -> V_116 ;
V_2 -> V_120 = NULL ;
V_2 -> V_116 = & V_2 -> V_120 ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
F_139 (unsigned long mask) ;
F_139 ( struct V_6 * V_7 = F_109 ( V_2 -> V_72 ) ) ;
F_139 ( struct V_21 * V_45 = V_7 -> V_46 ) ;
F_139 ( V_110 = V_7 -> V_47 ) ;
F_5 ( V_2 -> V_53 ,
V_45 -> V_4 + 1 - ! ! ( V_45 -> V_64 & V_110 ) ,
L_27 ) ;
}
static void F_140 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_40 ;
unsigned long V_110 ;
int V_121 = 0 ;
struct V_6 * V_7 = F_80 ( V_2 -> V_72 , V_5 ) ;
struct V_21 * V_45 = V_7 -> V_46 ;
F_141 ( V_45 , - 1 ) ;
F_107 ( & V_2 -> V_92 ) ;
F_70 ( & V_2 -> V_122 , V_40 ) ;
F_132 ( V_5 , V_2 , V_45 , V_7 ) ;
F_134 ( V_2 ) ;
V_110 = V_7 -> V_47 ;
do {
F_142 ( & V_45 -> V_63 ) ;
V_45 -> V_48 &= ~ V_110 ;
if ( V_45 -> V_48 != 0 ) {
if ( V_45 != V_7 -> V_46 )
F_143 ( & V_45 -> V_63 ) ;
break;
}
if ( V_45 == V_7 -> V_46 )
V_121 = F_144 ( V_2 , V_45 , V_7 ) ;
else
F_143 ( & V_45 -> V_63 ) ;
V_110 = V_45 -> V_47 ;
V_45 = V_45 -> V_113 ;
} while ( V_45 != NULL );
F_143 ( & V_2 -> V_122 ) ;
V_45 = V_7 -> V_46 ;
if ( V_121 & V_123 )
F_145 ( V_45 , V_40 ) ;
else
F_72 ( & V_45 -> V_63 , V_40 ) ;
if ( V_121 & V_124 )
F_146 ( V_2 , V_45 , true ) ;
F_26 ( V_7 -> V_73 != 0 || V_7 -> V_16 != NULL ,
L_28 ,
V_5 , V_7 -> V_73 , V_7 -> V_16 ) ;
F_98 ( V_7 ) ;
V_7 -> V_17 [ V_90 ] = NULL ;
F_117 ( & V_2 -> V_92 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
}
static void F_140 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_147 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_40 ;
struct V_19 * V_125 , * V_126 , * * V_127 ;
long V_128 , V_129 , V_130 ;
int V_86 ;
if ( ! F_17 ( V_7 ) ) {
F_148 ( V_2 -> V_53 , V_7 -> V_114 , V_7 -> V_73 , 0 ) ;
F_149 ( V_2 -> V_53 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_150 () , F_22 ( V_27 ) ,
F_151 () ) ;
return;
}
F_38 ( V_40 ) ;
F_31 ( F_65 ( F_24 () ) ) ;
V_128 = V_7 -> V_131 ;
F_148 ( V_2 -> V_53 , V_7 -> V_114 , V_7 -> V_73 , V_128 ) ;
V_126 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_127 = V_7 -> V_17 [ V_18 ] ;
for ( V_86 = V_87 - 1 ; V_86 >= 0 ; V_86 -- )
if ( V_7 -> V_17 [ V_86 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_86 ] = & V_7 -> V_16 ;
F_39 ( V_40 ) ;
V_129 = V_130 = 0 ;
while ( V_126 ) {
V_125 = V_126 -> V_125 ;
F_152 ( V_125 ) ;
F_153 ( V_126 ) ;
if ( F_154 ( V_2 -> V_53 , V_126 ) )
V_130 ++ ;
V_126 = V_125 ;
if ( ++ V_129 >= V_128 &&
( F_150 () ||
( ! F_22 ( V_27 ) && ! F_151 () ) ) )
break;
}
F_38 ( V_40 ) ;
F_149 ( V_2 -> V_53 , V_129 , ! ! V_126 , F_150 () ,
F_22 ( V_27 ) ,
F_151 () ) ;
if ( V_126 != NULL ) {
* V_127 = V_7 -> V_16 ;
V_7 -> V_16 = V_126 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_86 ] )
V_7 -> V_17 [ V_86 ] = V_127 ;
else
break;
}
F_155 () ;
V_7 -> V_114 -= V_130 ;
F_2 ( V_7 -> V_73 ) -= V_129 ;
V_7 -> V_132 += V_129 ;
if ( V_7 -> V_131 == V_133 && V_7 -> V_73 <= V_134 )
V_7 -> V_131 = V_131 ;
if ( V_7 -> V_73 == 0 && V_7 -> V_135 != 0 ) {
V_7 -> V_135 = 0 ;
V_7 -> V_136 = V_2 -> V_97 ;
} else if ( V_7 -> V_73 < V_7 -> V_135 - V_137 )
V_7 -> V_135 = V_7 -> V_73 ;
F_31 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_73 == 0 ) ) ;
F_39 ( V_40 ) ;
if ( F_17 ( V_7 ) )
F_156 () ;
}
void F_157 ( int V_5 , int V_26 )
{
F_8 ( L_29 ) ;
F_158 () ;
if ( V_26 || F_57 () ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_159 () ) {
F_6 ( V_5 ) ;
}
F_160 ( V_5 ) ;
if ( F_161 ( V_5 ) )
F_156 () ;
F_8 ( L_30 ) ;
}
static void F_119 ( struct V_1 * V_2 , int (* F_162)( struct V_6 * ) )
{
unsigned long V_138 ;
int V_5 ;
unsigned long V_40 ;
unsigned long V_110 ;
struct V_21 * V_45 ;
F_69 (rsp, rnp) {
F_116 () ;
V_110 = 0 ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
if ( ! F_1 ( V_2 ) ) {
F_72 ( & V_45 -> V_63 , V_40 ) ;
return;
}
if ( V_45 -> V_64 == 0 ) {
F_163 ( V_45 , V_40 ) ;
continue;
}
V_5 = V_45 -> V_66 ;
V_138 = 1 ;
for (; V_5 <= V_45 -> V_65 ; V_5 ++ , V_138 <<= 1 ) {
if ( ( V_45 -> V_64 & V_138 ) != 0 &&
F_162 ( F_80 ( V_2 -> V_72 , V_5 ) ) )
V_110 |= V_138 ;
}
if ( V_110 != 0 ) {
F_128 ( V_110 , V_2 , V_45 , V_40 ) ;
continue;
}
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
V_45 = F_19 ( V_2 ) ;
if ( V_45 -> V_64 == 0 ) {
F_70 ( & V_45 -> V_63 , V_40 ) ;
F_163 ( V_45 , V_40 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
bool V_44 ;
struct V_21 * V_45 ;
struct V_21 * V_139 = NULL ;
V_45 = F_80 ( V_2 -> V_72 , F_164 () ) -> V_46 ;
for (; V_45 != NULL ; V_45 = V_45 -> V_113 ) {
V_44 = ( F_2 ( V_2 -> V_91 ) & V_100 ) ||
! F_96 ( & V_45 -> V_140 ) ;
if ( V_139 != NULL )
F_143 ( & V_139 -> V_140 ) ;
if ( V_44 ) {
V_2 -> V_141 ++ ;
return;
}
V_139 = V_45 ;
}
F_70 ( & V_139 -> V_63 , V_40 ) ;
F_143 ( & V_139 -> V_140 ) ;
if ( F_2 ( V_2 -> V_91 ) & V_100 ) {
V_2 -> V_141 ++ ;
F_72 ( & V_139 -> V_63 , V_40 ) ;
return;
}
V_2 -> V_91 |= V_100 ;
F_72 ( & V_139 -> V_63 , V_40 ) ;
F_165 ( & V_2 -> V_105 ) ;
}
static void
F_166 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
struct V_6 * V_7 = F_135 ( V_2 -> V_72 ) ;
F_31 ( V_7 -> V_142 == 0 ) ;
F_102 ( V_2 , V_7 ) ;
F_131 ( V_2 , V_7 ) ;
if ( F_18 ( V_2 , V_7 ) ) {
F_70 ( & F_19 ( V_2 ) -> V_63 , V_40 ) ;
F_126 ( V_2 , V_40 ) ;
}
if ( F_17 ( V_7 ) )
F_167 ( V_2 , V_7 ) ;
}
static void F_168 ( struct V_143 * V_144 )
{
struct V_1 * V_2 ;
if ( F_65 ( F_24 () ) )
return;
F_8 ( L_31 ) ;
F_90 (rsp)
F_166 ( V_2 ) ;
F_8 ( L_32 ) ;
}
static void F_167 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_169 ( ! F_2 ( V_49 ) ) )
return;
if ( F_170 ( ! V_2 -> V_145 ) ) {
F_147 ( V_2 , V_7 ) ;
return;
}
F_171 () ;
}
static void F_156 ( void )
{
F_172 ( V_146 ) ;
}
static void F_173 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_19 * V_147 , unsigned long V_40 )
{
if ( F_52 () && F_174 ( F_24 () ) )
F_156 () ;
if ( F_175 ( V_40 ) || F_65 ( F_24 () ) )
return;
if ( F_169 ( V_7 -> V_73 > V_7 -> V_135 + V_137 ) ) {
F_102 ( V_2 , V_7 ) ;
F_97 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_148 ;
struct V_21 * V_149 = F_19 ( V_2 ) ;
F_70 ( & V_149 -> V_63 , V_148 ) ;
F_126 ( V_2 , V_148 ) ;
} else {
V_7 -> V_131 = V_133 ;
if ( V_2 -> V_97 == V_7 -> V_136 &&
* V_7 -> V_17 [ V_18 ] != V_147 )
F_13 ( V_2 ) ;
V_7 -> V_136 = V_2 -> V_97 ;
V_7 -> V_135 = V_7 -> V_73 ;
}
}
}
static void
F_176 ( struct V_19 * V_147 , void (* F_177)( struct V_19 * V_150 ) ,
struct V_1 * V_2 , int V_5 , bool V_151 )
{
unsigned long V_40 ;
struct V_6 * V_7 ;
F_31 ( ( unsigned long ) V_147 & 0x3 ) ;
F_178 ( V_147 ) ;
V_147 -> F_177 = F_177 ;
V_147 -> V_125 = NULL ;
F_38 ( V_40 ) ;
V_7 = F_109 ( V_2 -> V_72 ) ;
if ( F_169 ( V_7 -> V_17 [ V_90 ] == NULL ) || V_5 != - 1 ) {
int V_152 ;
if ( V_5 != - 1 )
V_7 = F_80 ( V_2 -> V_72 , V_5 ) ;
V_152 = ! F_179 ( V_7 , V_147 , V_151 ) ;
F_31 ( V_152 ) ;
F_39 ( V_40 ) ;
return;
}
F_2 ( V_7 -> V_73 ) ++ ;
if ( V_151 )
V_7 -> V_114 ++ ;
else
F_137 () ;
F_155 () ;
* V_7 -> V_17 [ V_90 ] = V_147 ;
V_7 -> V_17 [ V_90 ] = & V_147 -> V_125 ;
if ( F_180 ( ( unsigned long ) F_177 ) )
F_181 ( V_2 -> V_53 , V_147 , ( unsigned long ) F_177 ,
V_7 -> V_114 , V_7 -> V_73 ) ;
else
F_182 ( V_2 -> V_53 , V_147 , V_7 -> V_114 , V_7 -> V_73 ) ;
F_173 ( V_2 , V_7 , V_147 , V_40 ) ;
F_39 ( V_40 ) ;
}
void F_183 ( struct V_19 * V_147 , void (* F_177)( struct V_19 * V_150 ) )
{
F_176 ( V_147 , F_177 , & V_11 , - 1 , 0 ) ;
}
void F_184 ( struct V_19 * V_147 , void (* F_177)( struct V_19 * V_150 ) )
{
F_176 ( V_147 , F_177 , & V_12 , - 1 , 0 ) ;
}
static inline int F_185 ( void )
{
int V_44 ;
F_186 () ;
F_53 () ;
V_44 = F_187 () <= 1 ;
F_54 () ;
return V_44 ;
}
void F_188 ( void )
{
F_33 ( ! F_34 ( & V_35 ) &&
! F_34 ( & V_34 ) &&
! F_34 ( & V_36 ) ,
L_33 ) ;
if ( F_185 () )
return;
if ( V_153 )
F_189 () ;
else
F_190 ( F_183 ) ;
}
void F_191 ( void )
{
F_33 ( ! F_34 ( & V_35 ) &&
! F_34 ( & V_34 ) &&
! F_34 ( & V_36 ) ,
L_34 ) ;
if ( F_185 () )
return;
if ( V_153 )
F_192 () ;
else
F_190 ( F_184 ) ;
}
static int F_193 ( void * V_154 )
{
F_155 () ;
return 0 ;
}
void F_189 ( void )
{
long V_155 , V_156 , V_52 ;
int V_157 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_63 ( ( V_158 ) F_194 ( & V_2 -> V_159 ) ,
( V_158 ) F_194 ( & V_2 -> V_160 ) +
V_82 / 8 ) ) {
F_188 () ;
F_195 ( & V_2 -> V_161 ) ;
return;
}
V_52 = F_196 ( & V_2 -> V_159 ) ;
V_155 = V_52 ;
F_197 () ;
F_31 ( F_65 ( F_164 () ) ) ;
while ( F_198 ( V_162 ,
F_193 ,
NULL ) == - V_163 ) {
F_199 () ;
F_195 ( & V_2 -> V_164 ) ;
V_156 = F_194 ( & V_2 -> V_160 ) ;
if ( F_63 ( ( V_158 ) V_156 , ( V_158 ) V_155 ) ) {
F_28 () ;
F_195 ( & V_2 -> V_165 ) ;
return;
}
if ( V_157 ++ < 10 ) {
F_200 ( V_157 * F_187 () ) ;
} else {
F_190 ( F_183 ) ;
F_195 ( & V_2 -> V_166 ) ;
return;
}
V_156 = F_194 ( & V_2 -> V_160 ) ;
if ( F_63 ( ( V_158 ) V_156 , ( V_158 ) V_155 ) ) {
F_28 () ;
F_195 ( & V_2 -> V_167 ) ;
return;
}
F_197 () ;
V_52 = F_194 ( & V_2 -> V_159 ) ;
F_155 () ;
}
F_195 ( & V_2 -> V_168 ) ;
do {
F_195 ( & V_2 -> V_169 ) ;
V_156 = F_194 ( & V_2 -> V_160 ) ;
if ( F_63 ( ( V_158 ) V_156 , ( V_158 ) V_52 ) ) {
F_28 () ;
F_195 ( & V_2 -> V_170 ) ;
break;
}
} while ( F_201 ( & V_2 -> V_160 , V_156 , V_52 ) != V_156 );
F_195 ( & V_2 -> V_171 ) ;
F_199 () ;
}
static int F_202 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_21 * V_45 = V_7 -> V_46 ;
V_7 -> V_172 ++ ;
F_87 ( V_2 , V_7 ) ;
if ( V_49 &&
V_7 -> V_85 && ! V_7 -> V_9 ) {
V_7 -> V_173 ++ ;
} else if ( V_7 -> V_85 && V_7 -> V_9 ) {
V_7 -> V_174 ++ ;
return 1 ;
}
if ( F_17 ( V_7 ) ) {
V_7 -> V_175 ++ ;
return 1 ;
}
if ( F_18 ( V_2 , V_7 ) ) {
V_7 -> V_176 ++ ;
return 1 ;
}
if ( F_2 ( V_45 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_177 ++ ;
return 1 ;
}
if ( F_2 ( V_45 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_178 ++ ;
return 1 ;
}
V_7 -> V_179 ++ ;
return 0 ;
}
static int F_161 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
if ( F_202 ( V_2 , F_80 ( V_2 -> V_72 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_203 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
if ( F_80 ( V_2 -> V_72 , V_5 ) -> V_16 )
return 1 ;
return 0 ;
}
static void F_204 ( struct V_1 * V_2 , char * V_156 ,
int V_5 , unsigned long V_180 )
{
F_205 ( V_2 -> V_53 , V_156 , V_5 ,
F_32 ( & V_2 -> V_181 ) , V_180 ) ;
}
static void F_206 ( struct V_19 * V_182 )
{
struct V_6 * V_7 = F_207 ( V_182 , struct V_6 , V_183 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_208 ( & V_2 -> V_181 ) ) {
F_204 ( V_2 , L_35 , - 1 , V_2 -> V_184 ) ;
F_209 ( & V_2 -> V_185 ) ;
} else {
F_204 ( V_2 , L_36 , - 1 , V_2 -> V_184 ) ;
}
}
static void F_210 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_135 ( V_2 -> V_72 ) ;
F_204 ( V_2 , L_37 , - 1 , V_2 -> V_184 ) ;
F_29 ( & V_2 -> V_181 ) ;
V_2 -> V_186 ( & V_7 -> V_183 , F_206 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_52 = F_2 ( V_2 -> V_184 ) ;
unsigned long V_187 ;
F_204 ( V_2 , L_38 , - 1 , V_52 ) ;
F_107 ( & V_2 -> V_188 ) ;
F_155 () ;
V_187 = F_2 ( V_2 -> V_184 ) ;
F_204 ( V_2 , L_39 , - 1 , V_187 ) ;
if ( F_63 ( V_187 , ( ( V_52 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_204 ( V_2 , L_40 , - 1 , V_187 ) ;
F_155 () ;
F_117 ( & V_2 -> V_188 ) ;
return;
}
F_2 ( V_2 -> V_184 ) ++ ;
F_31 ( ( V_2 -> V_184 & 0x1 ) != 1 ) ;
F_204 ( V_2 , L_41 , - 1 , V_2 -> V_184 ) ;
F_155 () ;
F_212 ( & V_2 -> V_185 ) ;
F_213 ( & V_2 -> V_181 , 1 ) ;
F_197 () ;
F_79 (cpu) {
if ( ! F_174 ( V_5 ) && ! F_133 ( V_5 ) )
continue;
V_7 = F_80 ( V_2 -> V_72 , V_5 ) ;
if ( F_133 ( V_5 ) ) {
F_204 ( V_2 , L_42 , V_5 ,
V_2 -> V_184 ) ;
F_29 ( & V_2 -> V_181 ) ;
F_176 ( & V_7 -> V_183 , F_206 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_73 ) ) {
F_204 ( V_2 , L_43 , V_5 ,
V_2 -> V_184 ) ;
F_214 ( V_5 , F_210 , V_2 , 1 ) ;
} else {
F_204 ( V_2 , L_44 , V_5 ,
V_2 -> V_184 ) ;
}
}
F_199 () ;
if ( F_208 ( & V_2 -> V_181 ) )
F_209 ( & V_2 -> V_185 ) ;
F_155 () ;
F_2 ( V_2 -> V_184 ) ++ ;
F_31 ( ( V_2 -> V_184 & 0x1 ) != 0 ) ;
F_204 ( V_2 , L_45 , - 1 , V_2 -> V_184 ) ;
F_155 () ;
F_215 ( & V_2 -> V_185 ) ;
F_117 ( & V_2 -> V_188 ) ;
}
void F_216 ( void )
{
F_211 ( & V_12 ) ;
}
void F_217 ( void )
{
F_211 ( & V_11 ) ;
}
static void T_1
F_218 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_40 ;
struct V_6 * V_7 = F_80 ( V_2 -> V_72 , V_5 ) ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_7 -> V_47 = 1UL << ( V_5 - V_7 -> V_46 -> V_66 ) ;
F_98 ( V_7 ) ;
V_7 -> V_114 = 0 ;
F_2 ( V_7 -> V_73 ) = 0 ;
V_7 -> V_33 = & F_4 ( V_23 , V_5 ) ;
F_31 ( V_7 -> V_33 -> V_37 != V_42 ) ;
F_31 ( F_32 ( & V_7 -> V_33 -> V_33 ) != 1 ) ;
#ifdef F_219
F_31 ( V_7 -> V_33 -> V_189 ) ;
#endif
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_220 ( V_7 ) ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
}
static void T_3
F_221 ( int V_5 , struct V_1 * V_2 , int V_190 )
{
unsigned long V_40 ;
unsigned long V_110 ;
struct V_6 * V_7 = F_80 ( V_2 -> V_72 , V_5 ) ;
struct V_21 * V_45 = F_19 ( V_2 ) ;
F_107 ( & V_2 -> V_92 ) ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_7 -> V_142 = 1 ;
V_7 -> V_190 = V_190 ;
V_7 -> V_135 = 0 ;
V_7 -> V_136 = V_2 -> V_97 ;
V_7 -> V_131 = V_131 ;
F_98 ( V_7 ) ;
V_7 -> V_33 -> V_37 = V_42 ;
F_213 ( & V_7 -> V_33 -> V_33 ,
( F_32 ( & V_7 -> V_33 -> V_33 ) & ~ 0x1 ) + 1 ) ;
F_222 ( V_5 ) ;
F_143 ( & V_45 -> V_63 ) ;
V_45 = V_7 -> V_46 ;
V_110 = V_7 -> V_47 ;
do {
F_142 ( & V_45 -> V_63 ) ;
V_45 -> V_48 |= V_110 ;
V_110 = V_45 -> V_47 ;
if ( V_45 == V_7 -> V_46 ) {
V_7 -> V_4 = V_45 -> V_3 ;
V_7 -> V_3 = V_45 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_85 = 0 ;
F_5 ( V_2 -> V_53 , V_7 -> V_4 , L_46 ) ;
}
F_143 ( & V_45 -> V_63 ) ;
V_45 = V_45 -> V_113 ;
} while ( V_45 != NULL && ! ( V_45 -> V_48 & V_110 ) );
F_39 ( V_40 ) ;
F_117 ( & V_2 -> V_92 ) ;
}
static void T_3 F_223 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
F_221 ( V_5 , V_2 ,
strcmp ( V_2 -> V_53 , L_47 ) == 0 ) ;
}
static int T_3 F_224 ( struct V_77 * V_191 ,
unsigned long V_192 , void * V_193 )
{
long V_5 = ( long ) V_193 ;
struct V_6 * V_7 = F_80 ( V_1 -> V_72 , V_5 ) ;
struct V_21 * V_45 = V_7 -> V_46 ;
struct V_1 * V_2 ;
int V_44 = V_194 ;
F_8 ( L_48 ) ;
switch ( V_192 ) {
case V_195 :
case V_196 :
F_223 ( V_5 ) ;
F_225 ( V_5 ) ;
break;
case V_197 :
case V_198 :
F_141 ( V_45 , - 1 ) ;
break;
case V_199 :
if ( F_226 ( V_5 ) )
F_141 ( V_45 , V_5 ) ;
else
V_44 = V_200 ;
break;
case V_201 :
case V_202 :
F_90 (rsp)
F_138 ( V_2 ) ;
F_44 ( V_5 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
F_90 (rsp)
F_140 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_8 ( L_49 ) ;
return V_44 ;
}
static int T_1 F_227 ( void )
{
unsigned long V_40 ;
struct V_21 * V_45 ;
struct V_1 * V_2 ;
struct V_28 * V_207 ;
F_90 (rsp) {
V_207 = F_228 ( F_121 , V_2 , V_2 -> V_53 ) ;
F_229 ( F_230 ( V_207 ) ) ;
V_45 = F_19 ( V_2 ) ;
F_70 ( & V_45 -> V_63 , V_40 ) ;
V_2 -> V_208 = V_207 ;
F_72 ( & V_45 -> V_63 , V_40 ) ;
F_231 ( V_2 ) ;
}
return 0 ;
}
void F_232 ( void )
{
F_233 ( F_187 () != 1 ) ;
F_233 ( F_234 () > 0 ) ;
V_209 = 1 ;
}
static void T_1 F_235 ( struct V_1 * V_2 )
{
int V_86 ;
for ( V_86 = V_210 - 1 ; V_86 > 0 ; V_86 -- )
V_2 -> V_211 [ V_86 ] = V_212 ;
V_2 -> V_211 [ 0 ] = V_213 ;
}
static void T_1 F_235 ( struct V_1 * V_2 )
{
int V_214 ;
int V_215 ;
int V_86 ;
V_215 = V_216 ;
for ( V_86 = V_210 - 1 ; V_86 >= 0 ; V_86 -- ) {
V_214 = V_2 -> V_217 [ V_86 ] ;
V_2 -> V_211 [ V_86 ] = ( V_215 + V_214 - 1 ) / V_214 ;
V_215 = V_214 ;
}
}
static void T_1 F_236 ( struct V_1 * V_2 ,
struct V_6 T_4 * V_72 )
{
static char * V_218 [] = { L_50 ,
L_51 ,
L_52 ,
L_53 } ;
static char * V_219 [] = { L_54 ,
L_55 ,
L_56 ,
L_57 } ;
int V_220 = 1 ;
int V_86 ;
int V_74 ;
struct V_21 * V_45 ;
F_237 ( V_221 > F_238 ( V_218 ) ) ;
for ( V_86 = 0 ; V_86 < V_210 ; V_86 ++ )
V_2 -> V_217 [ V_86 ] = V_222 [ V_86 ] ;
for ( V_86 = 1 ; V_86 < V_210 ; V_86 ++ )
V_2 -> V_93 [ V_86 ] = V_2 -> V_93 [ V_86 - 1 ] + V_2 -> V_217 [ V_86 - 1 ] ;
F_235 ( V_2 ) ;
for ( V_86 = V_210 - 1 ; V_86 >= 0 ; V_86 -- ) {
V_220 *= V_2 -> V_211 [ V_86 ] ;
V_45 = V_2 -> V_93 [ V_86 ] ;
for ( V_74 = 0 ; V_74 < V_2 -> V_217 [ V_86 ] ; V_74 ++ , V_45 ++ ) {
F_239 ( & V_45 -> V_63 ) ;
F_240 ( & V_45 -> V_63 ,
& V_223 [ V_86 ] , V_218 [ V_86 ] ) ;
F_239 ( & V_45 -> V_140 ) ;
F_240 ( & V_45 -> V_140 ,
& V_224 [ V_86 ] , V_219 [ V_86 ] ) ;
V_45 -> V_4 = V_2 -> V_4 ;
V_45 -> V_3 = V_2 -> V_3 ;
V_45 -> V_64 = 0 ;
V_45 -> V_48 = 0 ;
V_45 -> V_66 = V_74 * V_220 ;
V_45 -> V_65 = ( V_74 + 1 ) * V_220 - 1 ;
if ( V_45 -> V_65 >= V_225 )
V_45 -> V_65 = V_225 - 1 ;
if ( V_86 == 0 ) {
V_45 -> V_226 = 0 ;
V_45 -> V_47 = 0 ;
V_45 -> V_113 = NULL ;
} else {
V_45 -> V_226 = V_74 % V_2 -> V_211 [ V_86 - 1 ] ;
V_45 -> V_47 = 1UL << V_45 -> V_226 ;
V_45 -> V_113 = V_2 -> V_93 [ V_86 - 1 ] +
V_74 / V_2 -> V_211 [ V_86 - 1 ] ;
}
V_45 -> V_93 = V_86 ;
F_241 ( & V_45 -> V_227 ) ;
}
}
V_2 -> V_72 = V_72 ;
F_242 ( & V_2 -> V_105 ) ;
V_45 = V_2 -> V_93 [ V_210 - 1 ] ;
F_79 (i) {
while ( V_86 > V_45 -> V_65 )
V_45 ++ ;
F_80 ( V_2 -> V_72 , V_86 ) -> V_46 = V_45 ;
F_218 ( V_86 , V_2 ) ;
}
F_243 ( & V_2 -> V_228 , & V_229 ) ;
}
static void T_1 F_244 ( void )
{
int V_86 ;
int V_74 ;
int V_230 = V_216 ;
int V_231 [ V_221 + 1 ] ;
if ( V_213 == V_232 &&
V_216 == V_225 )
return;
V_231 [ 0 ] = 1 ;
V_231 [ 1 ] = V_213 ;
for ( V_86 = 2 ; V_86 <= V_221 ; V_86 ++ )
V_231 [ V_86 ] = V_231 [ V_86 - 1 ] * V_212 ;
if ( V_213 < V_232 ||
V_213 > sizeof( unsigned long ) * 8 ||
V_230 > V_231 [ V_221 ] ) {
F_233 ( 1 ) ;
return;
}
for ( V_86 = 1 ; V_86 <= V_221 ; V_86 ++ )
if ( V_230 <= V_231 [ V_86 ] ) {
for ( V_74 = 0 ; V_74 <= V_86 ; V_74 ++ )
V_222 [ V_74 ] =
F_245 ( V_230 , V_231 [ V_86 - V_74 ] ) ;
V_210 = V_86 ;
for ( V_74 = V_86 + 1 ; V_74 <= V_221 ; V_74 ++ )
V_222 [ V_74 ] = 0 ;
break;
}
V_94 = 0 ;
for ( V_86 = 0 ; V_86 <= V_221 ; V_86 ++ )
V_94 += V_222 [ V_86 ] ;
V_94 -= V_230 ;
}
void T_1 F_246 ( void )
{
int V_5 ;
F_247 () ;
F_244 () ;
F_236 ( & V_11 , & V_8 ) ;
F_236 ( & V_12 , & V_10 ) ;
F_248 () ;
F_249 () ;
F_250 ( V_146 , F_168 ) ;
F_251 ( F_224 , 0 ) ;
F_252 (cpu)
F_224 ( NULL , V_195 , ( void * ) ( long ) V_5 ) ;
F_91 () ;
}
