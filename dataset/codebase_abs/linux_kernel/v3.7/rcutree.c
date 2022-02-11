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
return & V_7 -> V_16 != V_7 -> V_17 [ V_18 ] ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
return * V_7 -> V_17 [ V_18 +
F_2 ( V_2 -> V_3 ) != V_7 -> V_3 ] &&
! F_1 ( V_2 ) ;
}
static struct V_19 * F_19 ( struct V_1 * V_2 )
{
return & V_2 -> V_20 [ 0 ] ;
}
static void F_20 ( struct V_21 * V_22 , long long V_23 ,
bool V_24 )
{
F_21 ( L_6 , V_23 , 0 ) ;
if ( ! V_24 && ! F_22 ( V_25 ) ) {
struct V_26 * V_27 = F_23 ( F_24 () ) ;
F_21 ( L_7 , V_23 , 0 ) ;
F_25 ( V_28 ) ;
F_26 ( 1 , L_8 ,
V_25 -> V_29 , V_25 -> V_30 ,
V_27 -> V_29 , V_27 -> V_30 ) ;
}
F_27 ( F_24 () ) ;
F_28 () ;
F_29 ( & V_22 -> V_31 ) ;
F_30 () ;
F_31 ( F_32 ( & V_22 -> V_31 ) & 0x1 ) ;
F_33 ( ! F_34 ( & V_32 ) ,
L_9 ) ;
F_33 ( ! F_34 ( & V_33 ) ,
L_10 ) ;
F_33 ( ! F_34 ( & V_34 ) ,
L_11 ) ;
}
static void F_35 ( bool V_24 )
{
long long V_23 ;
struct V_21 * V_22 ;
V_22 = & F_36 ( V_21 ) ;
V_23 = V_22 -> V_35 ;
F_31 ( ( V_23 & V_36 ) == 0 ) ;
if ( ( V_23 & V_36 ) == V_37 )
V_22 -> V_35 = 0 ;
else
V_22 -> V_35 -= V_37 ;
F_20 ( V_22 , V_23 , V_24 ) ;
}
void F_37 ( void )
{
unsigned long V_38 ;
F_38 ( V_38 ) ;
F_35 ( false ) ;
F_39 ( V_38 ) ;
}
void F_40 ( void )
{
unsigned long V_38 ;
struct V_21 * V_22 ;
if ( F_41 () )
return;
F_31 ( ! V_25 -> V_39 ) ;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
if ( ! V_22 -> V_40 && ! V_22 -> V_41 ) {
V_22 -> V_41 = true ;
F_35 ( true ) ;
}
F_39 ( V_38 ) ;
}
void F_42 ( void )
{
unsigned long V_38 ;
struct V_21 * V_22 ;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
F_31 ( ! ( V_22 -> V_35 & V_42 ) ) ;
V_22 -> V_35 = 1 ;
F_39 ( V_38 ) ;
}
void F_43 ( void )
{
unsigned long V_38 ;
long long V_23 ;
struct V_21 * V_22 ;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
V_23 = V_22 -> V_35 ;
V_22 -> V_35 -- ;
F_31 ( V_22 -> V_35 < 0 ) ;
if ( V_22 -> V_35 )
F_21 ( L_12 , V_23 , V_22 -> V_35 ) ;
else
F_20 ( V_22 , V_23 , true ) ;
F_39 ( V_38 ) ;
}
static void F_44 ( struct V_21 * V_22 , long long V_23 ,
int V_24 )
{
F_28 () ;
F_29 ( & V_22 -> V_31 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_22 -> V_31 ) & 0x1 ) ) ;
F_45 ( F_24 () ) ;
F_21 ( L_13 , V_23 , V_22 -> V_35 ) ;
if ( ! V_24 && ! F_22 ( V_25 ) ) {
struct V_26 * V_27 = F_23 ( F_24 () ) ;
F_21 ( L_14 ,
V_23 , V_22 -> V_35 ) ;
F_25 ( V_28 ) ;
F_26 ( 1 , L_8 ,
V_25 -> V_29 , V_25 -> V_30 ,
V_27 -> V_29 , V_27 -> V_30 ) ;
}
}
static void F_46 ( bool V_24 )
{
struct V_21 * V_22 ;
long long V_23 ;
V_22 = & F_36 ( V_21 ) ;
V_23 = V_22 -> V_35 ;
F_31 ( V_23 < 0 ) ;
if ( V_23 & V_36 )
V_22 -> V_35 += V_37 ;
else
V_22 -> V_35 = V_43 ;
F_44 ( V_22 , V_23 , V_24 ) ;
}
void F_47 ( void )
{
unsigned long V_38 ;
F_38 ( V_38 ) ;
F_46 ( false ) ;
F_39 ( V_38 ) ;
}
void F_48 ( void )
{
unsigned long V_38 ;
struct V_21 * V_22 ;
if ( F_41 () )
return;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
if ( V_22 -> V_41 ) {
V_22 -> V_41 = false ;
F_46 ( true ) ;
}
F_39 ( V_38 ) ;
}
void F_49 ( void )
{
unsigned long V_38 ;
struct V_21 * V_22 ;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
F_31 ( V_22 -> V_35 & V_36 ) ;
V_22 -> V_35 += V_43 ;
F_39 ( V_38 ) ;
}
void F_50 ( void )
{
unsigned long V_38 ;
struct V_21 * V_22 ;
long long V_23 ;
F_38 ( V_38 ) ;
V_22 = & F_36 ( V_21 ) ;
V_23 = V_22 -> V_35 ;
V_22 -> V_35 ++ ;
F_31 ( V_22 -> V_35 == 0 ) ;
if ( V_23 )
F_21 ( L_15 , V_23 , V_22 -> V_35 ) ;
else
F_44 ( V_22 , V_23 , true ) ;
F_39 ( V_38 ) ;
}
void F_51 ( void )
{
struct V_21 * V_22 = & F_36 ( V_21 ) ;
if ( V_22 -> V_44 == 0 &&
( F_32 ( & V_22 -> V_31 ) & 0x1 ) )
return;
V_22 -> V_44 ++ ;
F_28 () ;
F_29 ( & V_22 -> V_31 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_22 -> V_31 ) & 0x1 ) ) ;
}
void F_52 ( void )
{
struct V_21 * V_22 = & F_36 ( V_21 ) ;
if ( V_22 -> V_44 == 0 ||
-- V_22 -> V_44 != 0 )
return;
F_28 () ;
F_29 ( & V_22 -> V_31 ) ;
F_30 () ;
F_31 ( F_32 ( & V_22 -> V_31 ) & 0x1 ) ;
}
int F_53 ( void )
{
int V_45 ;
F_54 () ;
V_45 = ( F_32 ( & F_36 ( V_21 ) . V_31 ) & 0x1 ) == 0 ;
F_55 () ;
return V_45 ;
}
void F_56 ( struct V_26 * V_46 ,
struct V_26 * V_47 )
{
struct V_21 * V_22 ;
V_22 = & F_36 ( V_21 ) ;
if ( ! V_22 -> V_40 ) {
F_57 ( V_46 , V_48 ) ;
F_58 ( V_47 , V_48 ) ;
}
}
bool F_59 ( void )
{
struct V_6 * V_7 ;
struct V_19 * V_49 ;
bool V_45 ;
if ( F_60 () )
return 1 ;
F_54 () ;
V_7 = & F_36 ( V_8 ) ;
V_49 = V_7 -> V_50 ;
V_45 = ( V_7 -> V_51 & V_49 -> V_52 ) ||
! V_53 ;
F_55 () ;
return V_45 ;
}
int F_61 ( void )
{
return F_36 ( V_21 ) . V_35 <= 1 ;
}
static int F_62 ( struct V_6 * V_7 )
{
V_7 -> V_54 = F_63 ( 0 , & V_7 -> V_31 -> V_31 ) ;
return ( V_7 -> V_54 & 0x1 ) == 0 ;
}
static int F_64 ( struct V_6 * V_7 )
{
unsigned int V_55 ;
unsigned int V_56 ;
V_55 = ( unsigned int ) F_63 ( 0 , & V_7 -> V_31 -> V_31 ) ;
V_56 = ( unsigned int ) V_7 -> V_54 ;
if ( ( V_55 & 0x1 ) == 0 || F_65 ( V_55 , V_56 + 2 ) ) {
F_66 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , L_16 ) ;
V_7 -> V_58 ++ ;
return 1 ;
}
if ( F_67 ( V_7 -> V_2 -> V_59 + 2 , V_60 ) )
return 0 ;
F_68 () ;
if ( F_69 ( V_7 -> V_5 ) ) {
F_66 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , L_17 ) ;
V_7 -> V_61 ++ ;
return 1 ;
}
return 0 ;
}
static int F_70 ( void )
{
int V_62 = F_2 ( V_63 ) ;
if ( V_62 < 3 ) {
F_2 ( V_63 ) = 3 ;
V_62 = 3 ;
} else if ( V_62 > 300 ) {
F_2 ( V_63 ) = 300 ;
V_62 = 300 ;
}
return V_62 * V_64 + V_65 ;
}
static void F_71 ( struct V_1 * V_2 )
{
V_2 -> V_59 = V_60 ;
V_2 -> V_66 = V_60 + F_70 () ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_5 ;
long V_67 ;
unsigned long V_38 ;
int V_68 = 0 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_67 = V_60 - V_2 -> V_66 ;
if ( V_67 < V_70 || ! F_1 ( V_2 ) ) {
F_74 ( & V_49 -> V_69 , V_38 ) ;
return;
}
V_2 -> V_66 = V_60 + 3 * F_70 () + 3 ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
F_75 ( V_71 L_18 ,
V_2 -> V_57 ) ;
F_76 () ;
F_77 (rsp, rnp) {
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_68 += F_78 ( V_49 ) ;
if ( V_49 -> V_72 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_49 -> V_73 - V_49 -> V_74 ; V_5 ++ )
if ( V_49 -> V_72 & ( 1UL << V_5 ) ) {
F_79 ( V_2 ,
V_49 -> V_74 + V_5 ) ;
V_68 ++ ;
}
}
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
V_49 = F_19 ( V_2 ) ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_68 += F_78 ( V_49 ) ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
F_80 () ;
F_75 ( V_75 L_19 ,
F_24 () , ( long ) ( V_60 - V_2 -> V_59 ) ) ;
if ( V_68 == 0 )
F_75 ( V_71 L_20 ) ;
else if ( ! F_81 () )
F_82 () ;
F_83 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_75 ( V_71 L_21 , V_2 -> V_57 ) ;
F_76 () ;
F_79 ( V_2 , F_24 () ) ;
F_80 () ;
F_75 ( V_75 L_22 , V_60 - V_2 -> V_59 ) ;
if ( ! F_81 () )
F_82 () ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
if ( F_67 ( V_60 , V_2 -> V_66 ) )
V_2 -> V_66 = V_60 +
3 * F_70 () + 3 ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
F_85 () ;
}
static void F_86 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_76 ;
unsigned long V_77 ;
struct V_19 * V_49 ;
if ( V_78 )
return;
V_76 = F_2 ( V_60 ) ;
V_77 = F_2 ( V_2 -> V_66 ) ;
V_49 = V_7 -> V_50 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_49 -> V_72 ) & V_7 -> V_51 ) && F_67 ( V_76 , V_77 ) ) {
F_84 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_67 ( V_76 , V_77 + V_70 ) ) {
F_72 ( V_2 ) ;
}
}
static int F_87 ( struct V_79 * V_80 , unsigned long V_81 , void * V_82 )
{
V_78 = 1 ;
return V_83 ;
}
void F_88 ( void )
{
struct V_1 * V_2 ;
F_89 (rsp)
V_2 -> V_66 = V_60 + V_84 / 2 ;
}
static void T_1 F_90 ( void )
{
F_91 ( & V_85 , & V_86 ) ;
}
static void F_92 ( struct V_1 * V_2 , struct V_19 * V_49 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_49 -> V_4 ) {
V_7 -> V_4 = V_49 -> V_4 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , L_23 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_87 = ! ! ( V_49 -> V_72 & V_7 -> V_51 ) ;
F_93 ( V_7 ) ;
}
}
static void F_94 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_38 ;
struct V_19 * V_49 ;
F_38 ( V_38 ) ;
V_49 = V_7 -> V_50 ;
if ( V_7 -> V_4 == F_2 ( V_49 -> V_4 ) ||
! F_95 ( & V_49 -> V_69 ) ) {
F_39 ( V_38 ) ;
return;
}
F_92 ( V_2 , V_49 , V_7 ) ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
static int
F_96 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_38 ;
int V_45 = 0 ;
F_38 ( V_38 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_94 ( V_2 , V_7 ) ;
V_45 = 1 ;
}
F_39 ( V_38 ) ;
return V_45 ;
}
static void F_97 ( struct V_6 * V_7 )
{
int V_88 ;
V_7 -> V_16 = NULL ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ )
V_7 -> V_17 [ V_88 ] = & V_7 -> V_16 ;
}
static void
F_98 ( struct V_1 * V_2 , struct V_19 * V_49 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_49 -> V_3 ) {
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_90 ] ;
V_7 -> V_17 [ V_90 ] = V_7 -> V_17 [ V_91 ] ;
V_7 -> V_17 [ V_91 ] = V_7 -> V_17 [ V_92 ] ;
V_7 -> V_3 = V_49 -> V_3 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , L_24 ) ;
if ( F_99 ( V_7 -> V_4 , V_7 -> V_3 ) ) {
V_7 -> V_4 = V_7 -> V_3 ;
V_7 -> V_9 = 0 ;
}
if ( ( V_49 -> V_72 & V_7 -> V_51 ) == 0 )
V_7 -> V_87 = 0 ;
}
}
static void
F_100 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_38 ;
struct V_19 * V_49 ;
F_38 ( V_38 ) ;
V_49 = V_7 -> V_50 ;
if ( V_7 -> V_3 == F_2 ( V_49 -> V_3 ) ||
! F_95 ( & V_49 -> V_69 ) ) {
F_39 ( V_38 ) ;
return;
}
F_98 ( V_2 , V_49 , V_7 ) ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_19 * V_49 , struct V_6 * V_7 )
{
F_98 ( V_2 , V_49 , V_7 ) ;
F_92 ( V_2 , V_49 , V_7 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_103 ( & V_49 -> V_69 ) ;
V_2 -> V_93 = 0 ;
if ( F_1 ( V_2 ) ) {
F_104 ( & V_49 -> V_69 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_57 , V_2 -> V_4 , L_25 ) ;
F_71 ( V_2 ) ;
F_104 ( & V_49 -> V_69 ) ;
F_105 ( & V_2 -> V_94 ) ;
F_106 (rsp, rnp) {
F_103 ( & V_49 -> V_69 ) ;
V_7 = F_107 ( V_2 -> V_95 ) ;
F_108 ( V_49 ) ;
V_49 -> V_72 = V_49 -> V_52 ;
V_49 -> V_4 = V_2 -> V_4 ;
F_31 ( V_49 -> V_3 != V_2 -> V_3 ) ;
V_49 -> V_3 = V_2 -> V_3 ;
if ( V_49 == V_7 -> V_50 )
F_101 ( V_2 , V_49 , V_7 ) ;
F_109 ( V_49 ) ;
F_110 ( V_2 -> V_57 , V_49 -> V_4 ,
V_49 -> V_96 , V_49 -> V_74 ,
V_49 -> V_73 , V_49 -> V_72 ) ;
F_104 ( & V_49 -> V_69 ) ;
#ifdef F_111
if ( ( F_112 () % ( V_97 * 8 ) ) == 0 )
F_113 ( 2 ) ;
#endif
F_114 () ;
}
F_115 ( & V_2 -> V_94 ) ;
return 1 ;
}
int F_116 ( struct V_1 * V_2 , int V_98 )
{
int V_99 = V_98 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
V_2 -> V_100 ++ ;
if ( V_99 == V_101 ) {
F_117 ( V_2 , F_62 ) ;
V_99 = V_102 ;
} else {
F_117 ( V_2 , F_64 ) ;
}
if ( F_2 ( V_2 -> V_93 ) & V_103 ) {
F_103 ( & V_49 -> V_69 ) ;
V_2 -> V_93 &= ~ V_103 ;
F_104 ( & V_49 -> V_69 ) ;
}
return V_99 ;
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned long V_104 ;
struct V_6 * V_7 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_103 ( & V_49 -> V_69 ) ;
V_104 = V_60 - V_2 -> V_59 ;
if ( V_104 > V_2 -> V_105 )
V_2 -> V_105 = V_104 ;
F_104 ( & V_49 -> V_69 ) ;
F_106 (rsp, rnp) {
F_103 ( & V_49 -> V_69 ) ;
V_49 -> V_3 = V_2 -> V_4 ;
F_104 ( & V_49 -> V_69 ) ;
F_114 () ;
}
V_49 = F_19 ( V_2 ) ;
F_103 ( & V_49 -> V_69 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_57 , V_2 -> V_3 , L_26 ) ;
V_2 -> V_99 = V_106 ;
V_7 = F_107 ( V_2 -> V_95 ) ;
if ( F_18 ( V_2 , V_7 ) )
V_2 -> V_93 = 1 ;
F_104 ( & V_49 -> V_69 ) ;
}
static int T_2 F_119 ( void * V_107 )
{
int V_99 ;
unsigned long V_76 ;
int V_45 ;
struct V_1 * V_2 = V_107 ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_120 ( V_2 -> V_108 ,
V_2 -> V_93 &
V_109 ) ;
if ( ( V_2 -> V_93 & V_109 ) &&
F_102 ( V_2 ) )
break;
F_114 () ;
F_121 ( V_25 ) ;
}
V_99 = V_101 ;
V_76 = V_110 ;
if ( V_76 > V_64 ) {
V_76 = V_64 ;
V_110 = V_64 ;
}
for (; ; ) {
V_2 -> V_111 = V_60 + V_76 ;
V_45 = F_122 ( V_2 -> V_108 ,
( V_2 -> V_93 & V_103 ) ||
( ! F_2 ( V_49 -> V_72 ) &&
! F_123 ( V_49 ) ) ,
V_76 ) ;
if ( ! F_2 ( V_49 -> V_72 ) &&
! F_123 ( V_49 ) )
break;
if ( V_45 == 0 || ( V_2 -> V_93 & V_103 ) ) {
V_99 = F_116 ( V_2 , V_99 ) ;
F_114 () ;
} else {
F_114 () ;
F_121 ( V_25 ) ;
}
V_76 = V_112 ;
if ( V_76 > V_64 ) {
V_76 = V_64 ;
V_112 = V_64 ;
} else if ( V_76 < 1 ) {
V_76 = 1 ;
V_112 = 1 ;
}
}
F_118 ( V_2 ) ;
}
}
static void
F_124 ( struct V_1 * V_2 , unsigned long V_38 )
__releases( rcu_get_root( V_2 )->lock
static void F_125 ( struct V_1 * V_2 , unsigned long V_38 )
__releases( rcu_get_root( V_2 )->lock
static void
F_126 ( unsigned long V_113 , struct V_1 * V_2 ,
struct V_19 * V_49 , unsigned long V_38 )
__releases( V_49 -> V_69 )
{
struct V_19 * V_114 ;
for (; ; ) {
if ( ! ( V_49 -> V_72 & V_113 ) ) {
F_74 ( & V_49 -> V_69 , V_38 ) ;
return;
}
V_49 -> V_72 &= ~ V_113 ;
F_127 ( V_2 -> V_57 , V_49 -> V_4 ,
V_113 , V_49 -> V_72 , V_49 -> V_96 ,
V_49 -> V_74 , V_49 -> V_73 ,
! ! V_49 -> V_115 ) ;
if ( V_49 -> V_72 != 0 || F_123 ( V_49 ) ) {
F_74 ( & V_49 -> V_69 , V_38 ) ;
return;
}
V_113 = V_49 -> V_51 ;
if ( V_49 -> V_116 == NULL ) {
break;
}
F_74 ( & V_49 -> V_69 , V_38 ) ;
V_114 = V_49 ;
V_49 = V_49 -> V_116 ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
F_31 ( V_114 -> V_72 ) ;
}
F_125 ( V_2 , V_38 ) ;
}
static void
F_128 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_38 ;
unsigned long V_113 ;
struct V_19 * V_49 ;
V_49 = V_7 -> V_50 ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_49 -> V_4 ||
V_49 -> V_3 == V_49 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
return;
}
V_113 = V_7 -> V_51 ;
if ( ( V_49 -> V_72 & V_113 ) == 0 ) {
F_74 ( & V_49 -> V_69 , V_38 ) ;
} else {
V_7 -> V_87 = 0 ;
V_7 -> V_17 [ V_91 ] = V_7 -> V_17 [ V_92 ] ;
F_126 ( V_113 , V_2 , V_49 , V_38 ) ;
}
}
static void
F_129 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_96 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_87 )
return;
if ( ! V_7 -> V_9 )
return;
F_128 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_130 ( int V_5 , struct V_1 * V_2 ,
struct V_19 * V_49 , struct V_6 * V_7 )
{
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_117 += V_7 -> V_117 ;
V_2 -> V_118 += V_7 -> V_118 ;
V_7 -> V_119 += V_7 -> V_118 ;
V_7 -> V_117 = 0 ;
F_2 ( V_7 -> V_118 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_120 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_120 = V_7 -> V_17 [ V_92 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_121 = V_7 -> V_16 ;
V_2 -> V_121 = V_7 -> V_17 [ V_18 ] ;
}
F_97 ( V_7 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
int V_88 ;
struct V_6 * V_7 = F_132 ( V_2 -> V_95 ) ;
V_7 -> V_117 += V_2 -> V_117 ;
V_7 -> V_118 += V_2 -> V_118 ;
V_7 -> V_122 += V_2 -> V_118 ;
if ( V_2 -> V_117 != V_2 -> V_118 )
F_133 () ;
V_2 -> V_117 = 0 ;
V_2 -> V_118 = 0 ;
if ( V_2 -> V_123 != NULL ) {
* V_2 -> V_121 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_123 ;
for ( V_88 = V_89 - 1 ; V_88 >= V_18 ; V_88 -- )
if ( V_7 -> V_17 [ V_88 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_88 ] = V_2 -> V_121 ;
V_2 -> V_123 = NULL ;
V_2 -> V_121 = & V_2 -> V_123 ;
}
if ( V_2 -> V_124 != NULL ) {
* V_7 -> V_17 [ V_92 ] = V_2 -> V_124 ;
V_7 -> V_17 [ V_92 ] = V_2 -> V_120 ;
V_2 -> V_124 = NULL ;
V_2 -> V_120 = & V_2 -> V_124 ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
F_135 (unsigned long mask) ;
F_135 ( struct V_6 * V_7 = F_107 ( V_2 -> V_95 ) ) ;
F_135 ( struct V_19 * V_49 = V_7 -> V_50 ) ;
F_135 ( V_113 = V_7 -> V_51 ) ;
F_5 ( V_2 -> V_57 ,
V_49 -> V_4 + 1 - ! ! ( V_49 -> V_72 & V_113 ) ,
L_27 ) ;
}
static void F_136 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_38 ;
unsigned long V_113 ;
int V_125 = 0 ;
struct V_6 * V_7 = F_137 ( V_2 -> V_95 , V_5 ) ;
struct V_19 * V_49 = V_7 -> V_50 ;
F_138 ( V_49 , - 1 ) ;
F_105 ( & V_2 -> V_94 ) ;
F_73 ( & V_2 -> V_126 , V_38 ) ;
F_130 ( V_5 , V_2 , V_49 , V_7 ) ;
F_131 ( V_2 ) ;
V_113 = V_7 -> V_51 ;
do {
F_139 ( & V_49 -> V_69 ) ;
V_49 -> V_52 &= ~ V_113 ;
if ( V_49 -> V_52 != 0 ) {
if ( V_49 != V_7 -> V_50 )
F_140 ( & V_49 -> V_69 ) ;
break;
}
if ( V_49 == V_7 -> V_50 )
V_125 = F_141 ( V_2 , V_49 , V_7 ) ;
else
F_140 ( & V_49 -> V_69 ) ;
V_113 = V_49 -> V_51 ;
V_49 = V_49 -> V_116 ;
} while ( V_49 != NULL );
F_140 ( & V_2 -> V_126 ) ;
V_49 = V_7 -> V_50 ;
if ( V_125 & V_127 )
F_142 ( V_49 , V_38 ) ;
else
F_74 ( & V_49 -> V_69 , V_38 ) ;
if ( V_125 & V_128 )
F_143 ( V_2 , V_49 , true ) ;
F_26 ( V_7 -> V_118 != 0 || V_7 -> V_16 != NULL ,
L_28 ,
V_5 , V_7 -> V_118 , V_7 -> V_16 ) ;
F_97 ( V_7 ) ;
V_7 -> V_17 [ V_92 ] = NULL ;
F_115 ( & V_2 -> V_94 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
}
static void F_136 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_144 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_38 ;
struct V_129 * V_47 , * V_130 , * * V_131 ;
int V_132 , V_133 , V_134 , V_88 ;
if ( ! F_17 ( V_7 ) ) {
F_145 ( V_2 -> V_57 , V_7 -> V_117 , V_7 -> V_118 , 0 ) ;
F_146 ( V_2 -> V_57 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_147 () , F_22 ( V_25 ) ,
F_148 () ) ;
return;
}
F_38 ( V_38 ) ;
F_31 ( F_69 ( F_24 () ) ) ;
V_132 = V_7 -> V_135 ;
F_145 ( V_2 -> V_57 , V_7 -> V_117 , V_7 -> V_118 , V_132 ) ;
V_130 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_131 = V_7 -> V_17 [ V_18 ] ;
for ( V_88 = V_89 - 1 ; V_88 >= 0 ; V_88 -- )
if ( V_7 -> V_17 [ V_88 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_88 ] = & V_7 -> V_16 ;
F_39 ( V_38 ) ;
V_133 = V_134 = 0 ;
while ( V_130 ) {
V_47 = V_130 -> V_47 ;
F_149 ( V_47 ) ;
F_150 ( V_130 ) ;
if ( F_151 ( V_2 -> V_57 , V_130 ) )
V_134 ++ ;
V_130 = V_47 ;
if ( ++ V_133 >= V_132 &&
( F_147 () ||
( ! F_22 ( V_25 ) && ! F_148 () ) ) )
break;
}
F_38 ( V_38 ) ;
F_146 ( V_2 -> V_57 , V_133 , ! ! V_130 , F_147 () ,
F_22 ( V_25 ) ,
F_148 () ) ;
if ( V_130 != NULL ) {
* V_131 = V_7 -> V_16 ;
V_7 -> V_16 = V_130 ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_88 ] )
V_7 -> V_17 [ V_88 ] = V_131 ;
else
break;
}
F_152 () ;
V_7 -> V_117 -= V_134 ;
F_2 ( V_7 -> V_118 ) -= V_133 ;
V_7 -> V_136 += V_133 ;
if ( V_7 -> V_135 == V_137 && V_7 -> V_118 <= V_138 )
V_7 -> V_135 = V_135 ;
if ( V_7 -> V_118 == 0 && V_7 -> V_139 != 0 ) {
V_7 -> V_139 = 0 ;
V_7 -> V_140 = V_2 -> V_100 ;
} else if ( V_7 -> V_118 < V_7 -> V_139 - V_141 )
V_7 -> V_139 = V_7 -> V_118 ;
F_31 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_118 == 0 ) ) ;
F_39 ( V_38 ) ;
if ( F_17 ( V_7 ) )
F_153 () ;
}
void F_154 ( int V_5 , int V_24 )
{
F_8 ( L_29 ) ;
F_155 () ;
if ( V_24 || F_61 () ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_156 () ) {
F_6 ( V_5 ) ;
}
F_157 ( V_5 ) ;
if ( F_158 ( V_5 ) )
F_153 () ;
F_8 ( L_30 ) ;
}
static void F_117 ( struct V_1 * V_2 , int (* F_159)( struct V_6 * ) )
{
unsigned long V_142 ;
int V_5 ;
unsigned long V_38 ;
unsigned long V_113 ;
struct V_19 * V_49 ;
F_77 (rsp, rnp) {
F_114 () ;
V_113 = 0 ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
if ( ! F_1 ( V_2 ) ) {
F_74 ( & V_49 -> V_69 , V_38 ) ;
return;
}
if ( V_49 -> V_72 == 0 ) {
F_160 ( V_49 , V_38 ) ;
continue;
}
V_5 = V_49 -> V_74 ;
V_142 = 1 ;
for (; V_5 <= V_49 -> V_73 ; V_5 ++ , V_142 <<= 1 ) {
if ( ( V_49 -> V_72 & V_142 ) != 0 &&
F_159 ( F_137 ( V_2 -> V_95 , V_5 ) ) )
V_113 |= V_142 ;
}
if ( V_113 != 0 ) {
F_126 ( V_113 , V_2 , V_49 , V_38 ) ;
continue;
}
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
V_49 = F_19 ( V_2 ) ;
if ( V_49 -> V_72 == 0 ) {
F_73 ( & V_49 -> V_69 , V_38 ) ;
F_160 ( V_49 , V_38 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
bool V_45 ;
struct V_19 * V_49 ;
struct V_19 * V_143 = NULL ;
V_49 = F_137 ( V_2 -> V_95 , F_161 () ) -> V_50 ;
for (; V_49 != NULL ; V_49 = V_49 -> V_116 ) {
V_45 = ( F_2 ( V_2 -> V_93 ) & V_103 ) ||
! F_95 ( & V_49 -> V_144 ) ;
if ( V_143 != NULL )
F_140 ( & V_143 -> V_144 ) ;
if ( V_45 ) {
V_2 -> V_145 ++ ;
return;
}
V_143 = V_49 ;
}
F_73 ( & V_143 -> V_69 , V_38 ) ;
F_140 ( & V_143 -> V_144 ) ;
if ( F_2 ( V_2 -> V_93 ) & V_103 ) {
V_2 -> V_145 ++ ;
F_74 ( & V_143 -> V_69 , V_38 ) ;
return;
}
V_2 -> V_93 |= V_103 ;
F_74 ( & V_143 -> V_69 , V_38 ) ;
F_162 ( & V_2 -> V_108 ) ;
}
static void
F_163 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_6 * V_7 = F_132 ( V_2 -> V_95 ) ;
F_31 ( V_7 -> V_146 == 0 ) ;
F_100 ( V_2 , V_7 ) ;
F_129 ( V_2 , V_7 ) ;
if ( F_18 ( V_2 , V_7 ) ) {
F_73 ( & F_19 ( V_2 ) -> V_69 , V_38 ) ;
F_124 ( V_2 , V_38 ) ;
}
if ( F_17 ( V_7 ) )
F_164 ( V_2 , V_7 ) ;
}
static void F_165 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
if ( F_69 ( F_24 () ) )
return;
F_8 ( L_31 ) ;
F_89 (rsp)
F_163 ( V_2 ) ;
F_8 ( L_32 ) ;
}
static void F_164 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_166 ( ! F_2 ( V_53 ) ) )
return;
if ( F_167 ( ! V_2 -> V_149 ) ) {
F_144 ( V_2 , V_7 ) ;
return;
}
F_168 () ;
}
static void F_153 ( void )
{
F_169 ( V_150 ) ;
}
static void F_170 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_129 * V_151 , unsigned long V_38 )
{
if ( F_53 () && F_171 ( F_24 () ) )
F_153 () ;
if ( F_172 ( V_38 ) || F_69 ( F_24 () ) )
return;
if ( F_166 ( V_7 -> V_118 > V_7 -> V_139 + V_141 ) ) {
F_100 ( V_2 , V_7 ) ;
F_96 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_152 ;
struct V_19 * V_153 = F_19 ( V_2 ) ;
F_73 ( & V_153 -> V_69 , V_152 ) ;
F_124 ( V_2 , V_152 ) ;
} else {
V_7 -> V_135 = V_137 ;
if ( V_2 -> V_100 == V_7 -> V_140 &&
* V_7 -> V_17 [ V_18 ] != V_151 )
F_13 ( V_2 ) ;
V_7 -> V_140 = V_2 -> V_100 ;
V_7 -> V_139 = V_7 -> V_118 ;
}
}
}
static void
F_173 ( struct V_129 * V_151 , void (* F_174)( struct V_129 * V_154 ) ,
struct V_1 * V_2 , bool V_155 )
{
unsigned long V_38 ;
struct V_6 * V_7 ;
F_31 ( ( unsigned long ) V_151 & 0x3 ) ;
F_175 ( V_151 ) ;
V_151 -> F_174 = F_174 ;
V_151 -> V_47 = NULL ;
F_38 ( V_38 ) ;
V_7 = F_107 ( V_2 -> V_95 ) ;
if ( F_166 ( V_7 -> V_17 [ V_92 ] == NULL ) ) {
F_31 ( 1 ) ;
F_39 ( V_38 ) ;
return;
}
F_2 ( V_7 -> V_118 ) ++ ;
if ( V_155 )
V_7 -> V_117 ++ ;
else
F_133 () ;
F_152 () ;
* V_7 -> V_17 [ V_92 ] = V_151 ;
V_7 -> V_17 [ V_92 ] = & V_151 -> V_47 ;
if ( F_176 ( ( unsigned long ) F_174 ) )
F_177 ( V_2 -> V_57 , V_151 , ( unsigned long ) F_174 ,
V_7 -> V_117 , V_7 -> V_118 ) ;
else
F_178 ( V_2 -> V_57 , V_151 , V_7 -> V_117 , V_7 -> V_118 ) ;
F_170 ( V_2 , V_7 , V_151 , V_38 ) ;
F_39 ( V_38 ) ;
}
void F_179 ( struct V_129 * V_151 , void (* F_174)( struct V_129 * V_154 ) )
{
F_173 ( V_151 , F_174 , & V_11 , 0 ) ;
}
void F_180 ( struct V_129 * V_151 , void (* F_174)( struct V_129 * V_154 ) )
{
F_173 ( V_151 , F_174 , & V_12 , 0 ) ;
}
static inline int F_181 ( void )
{
int V_45 ;
F_182 () ;
F_54 () ;
V_45 = F_183 () <= 1 ;
F_55 () ;
return V_45 ;
}
void F_184 ( void )
{
F_33 ( ! F_34 ( & V_33 ) &&
! F_34 ( & V_32 ) &&
! F_34 ( & V_34 ) ,
L_33 ) ;
if ( F_181 () )
return;
F_185 ( F_179 ) ;
}
void F_186 ( void )
{
F_33 ( ! F_34 ( & V_33 ) &&
! F_34 ( & V_32 ) &&
! F_34 ( & V_34 ) ,
L_34 ) ;
if ( F_181 () )
return;
F_185 ( F_180 ) ;
}
static int F_187 ( void * V_156 )
{
F_152 () ;
return 0 ;
}
void F_188 ( void )
{
int V_157 , V_158 , V_56 , V_159 = 0 ;
V_157 = V_56 = F_189 ( & V_160 ) ;
F_190 () ;
F_31 ( F_69 ( F_161 () ) ) ;
while ( F_191 ( V_161 ,
F_187 ,
NULL ) == - V_162 ) {
F_192 () ;
if ( V_159 ++ < 10 ) {
F_193 ( V_159 * F_183 () ) ;
} else {
F_184 () ;
return;
}
V_158 = F_32 ( & V_163 ) ;
if ( F_65 ( ( unsigned ) V_158 , ( unsigned ) V_157 ) ) {
F_152 () ;
return;
}
F_190 () ;
V_56 = F_32 ( & V_160 ) ;
F_152 () ;
}
do {
V_158 = F_32 ( & V_163 ) ;
if ( F_65 ( ( unsigned ) V_158 , ( unsigned ) V_56 ) ) {
F_152 () ;
break;
}
} while ( F_194 ( & V_163 , V_158 , V_56 ) != V_158 );
F_192 () ;
}
static int F_195 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_19 * V_49 = V_7 -> V_50 ;
V_7 -> V_164 ++ ;
F_86 ( V_2 , V_7 ) ;
if ( V_53 &&
V_7 -> V_87 && ! V_7 -> V_9 ) {
V_7 -> V_165 ++ ;
} else if ( V_7 -> V_87 && V_7 -> V_9 ) {
V_7 -> V_166 ++ ;
return 1 ;
}
if ( F_17 ( V_7 ) ) {
V_7 -> V_167 ++ ;
return 1 ;
}
if ( F_18 ( V_2 , V_7 ) ) {
V_7 -> V_168 ++ ;
return 1 ;
}
if ( F_2 ( V_49 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_169 ++ ;
return 1 ;
}
if ( F_2 ( V_49 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_170 ++ ;
return 1 ;
}
V_7 -> V_171 ++ ;
return 0 ;
}
static int F_158 ( int V_5 )
{
struct V_1 * V_2 ;
F_89 (rsp)
if ( F_195 ( V_2 , F_137 ( V_2 -> V_95 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_196 ( int V_5 )
{
struct V_1 * V_2 ;
F_89 (rsp)
if ( F_137 ( V_2 -> V_95 , V_5 ) -> V_16 )
return 1 ;
return 0 ;
}
static void F_197 ( struct V_1 * V_2 , char * V_158 ,
int V_5 , unsigned long V_172 )
{
F_198 ( V_2 -> V_57 , V_158 , V_5 ,
F_32 ( & V_2 -> V_173 ) , V_172 ) ;
}
static void F_199 ( struct V_129 * V_174 )
{
struct V_6 * V_7 = F_200 ( V_174 , struct V_6 , V_175 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_201 ( & V_2 -> V_173 ) ) {
F_197 ( V_2 , L_35 , - 1 , V_2 -> V_176 ) ;
F_202 ( & V_2 -> V_177 ) ;
} else {
F_197 ( V_2 , L_36 , - 1 , V_2 -> V_176 ) ;
}
}
static void F_203 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_132 ( V_2 -> V_95 ) ;
F_197 ( V_2 , L_37 , - 1 , V_2 -> V_176 ) ;
F_29 ( & V_2 -> V_173 ) ;
V_2 -> V_178 ( & V_7 -> V_175 , F_199 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_56 = F_2 ( V_2 -> V_176 ) ;
unsigned long V_179 ;
F_197 ( V_2 , L_38 , - 1 , V_56 ) ;
F_105 ( & V_2 -> V_180 ) ;
F_152 () ;
V_179 = F_2 ( V_2 -> V_176 ) ;
F_197 ( V_2 , L_39 , - 1 , V_179 ) ;
if ( F_67 ( V_179 , ( ( V_56 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_197 ( V_2 , L_40 , - 1 , V_179 ) ;
F_152 () ;
F_115 ( & V_2 -> V_180 ) ;
return;
}
F_2 ( V_2 -> V_176 ) ++ ;
F_31 ( ( V_2 -> V_176 & 0x1 ) != 1 ) ;
F_197 ( V_2 , L_41 , - 1 , V_2 -> V_176 ) ;
F_152 () ;
F_205 ( & V_2 -> V_177 ) ;
F_206 ( & V_2 -> V_173 , 1 ) ;
F_190 () ;
F_207 (cpu) {
V_7 = F_137 ( V_2 -> V_95 , V_5 ) ;
if ( F_2 ( V_7 -> V_118 ) ) {
F_197 ( V_2 , L_42 , V_5 ,
V_2 -> V_176 ) ;
F_208 ( V_5 , F_203 , V_2 , 1 ) ;
} else {
F_197 ( V_2 , L_43 , V_5 ,
V_2 -> V_176 ) ;
}
}
F_192 () ;
if ( F_201 ( & V_2 -> V_173 ) )
F_202 ( & V_2 -> V_177 ) ;
F_152 () ;
F_2 ( V_2 -> V_176 ) ++ ;
F_31 ( ( V_2 -> V_176 & 0x1 ) != 0 ) ;
F_197 ( V_2 , L_44 , - 1 , V_2 -> V_176 ) ;
F_152 () ;
F_209 ( & V_2 -> V_177 ) ;
F_115 ( & V_2 -> V_180 ) ;
}
void F_210 ( void )
{
F_204 ( & V_12 ) ;
}
void F_211 ( void )
{
F_204 ( & V_11 ) ;
}
static void T_1
F_212 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_6 * V_7 = F_137 ( V_2 -> V_95 , V_5 ) ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_7 -> V_51 = 1UL << ( V_5 - V_7 -> V_50 -> V_74 ) ;
F_97 ( V_7 ) ;
V_7 -> V_117 = 0 ;
F_2 ( V_7 -> V_118 ) = 0 ;
V_7 -> V_31 = & F_4 ( V_21 , V_5 ) ;
F_31 ( V_7 -> V_31 -> V_35 != V_43 ) ;
F_31 ( F_32 ( & V_7 -> V_31 -> V_31 ) != 1 ) ;
#ifdef F_213
F_31 ( V_7 -> V_31 -> V_41 ) ;
#endif
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
static void T_3
F_214 ( int V_5 , struct V_1 * V_2 , int V_181 )
{
unsigned long V_38 ;
unsigned long V_113 ;
struct V_6 * V_7 = F_137 ( V_2 -> V_95 , V_5 ) ;
struct V_19 * V_49 = F_19 ( V_2 ) ;
F_105 ( & V_2 -> V_94 ) ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_7 -> V_146 = 1 ;
V_7 -> V_181 = V_181 ;
V_7 -> V_139 = 0 ;
V_7 -> V_140 = V_2 -> V_100 ;
V_7 -> V_135 = V_135 ;
F_97 ( V_7 ) ;
V_7 -> V_31 -> V_35 = V_43 ;
F_206 ( & V_7 -> V_31 -> V_31 ,
( F_32 ( & V_7 -> V_31 -> V_31 ) & ~ 0x1 ) + 1 ) ;
F_215 ( V_5 ) ;
F_140 ( & V_49 -> V_69 ) ;
V_49 = V_7 -> V_50 ;
V_113 = V_7 -> V_51 ;
do {
F_139 ( & V_49 -> V_69 ) ;
V_49 -> V_52 |= V_113 ;
V_113 = V_49 -> V_51 ;
if ( V_49 == V_7 -> V_50 ) {
V_7 -> V_4 = V_49 -> V_3 ;
V_7 -> V_3 = V_49 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_87 = 0 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , L_45 ) ;
}
F_140 ( & V_49 -> V_69 ) ;
V_49 = V_49 -> V_116 ;
} while ( V_49 != NULL && ! ( V_49 -> V_52 & V_113 ) );
F_39 ( V_38 ) ;
F_115 ( & V_2 -> V_94 ) ;
}
static void T_3 F_216 ( int V_5 )
{
struct V_1 * V_2 ;
F_89 (rsp)
F_214 ( V_5 , V_2 ,
strcmp ( V_2 -> V_57 , L_46 ) == 0 ) ;
}
static int T_3 F_217 ( struct V_79 * V_182 ,
unsigned long V_183 , void * V_184 )
{
long V_5 = ( long ) V_184 ;
struct V_6 * V_7 = F_137 ( V_1 -> V_95 , V_5 ) ;
struct V_19 * V_49 = V_7 -> V_50 ;
struct V_1 * V_2 ;
F_8 ( L_47 ) ;
switch ( V_183 ) {
case V_185 :
case V_186 :
F_216 ( V_5 ) ;
F_218 ( V_5 ) ;
break;
case V_187 :
case V_188 :
F_138 ( V_49 , - 1 ) ;
break;
case V_189 :
F_138 ( V_49 , V_5 ) ;
break;
case V_190 :
case V_191 :
F_89 (rsp)
F_134 ( V_2 ) ;
F_45 ( V_5 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
F_89 (rsp)
F_136 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_8 ( L_48 ) ;
return V_196 ;
}
static int T_1 F_219 ( void )
{
unsigned long V_38 ;
struct V_19 * V_49 ;
struct V_1 * V_2 ;
struct V_26 * V_197 ;
F_89 (rsp) {
V_197 = F_220 ( F_119 , V_2 , V_2 -> V_57 ) ;
F_221 ( F_222 ( V_197 ) ) ;
V_49 = F_19 ( V_2 ) ;
F_73 ( & V_49 -> V_69 , V_38 ) ;
V_2 -> V_198 = V_197 ;
F_74 ( & V_49 -> V_69 , V_38 ) ;
}
return 0 ;
}
void F_223 ( void )
{
F_224 ( F_183 () != 1 ) ;
F_224 ( F_225 () > 0 ) ;
V_199 = 1 ;
}
static void T_1 F_226 ( struct V_1 * V_2 )
{
int V_88 ;
for ( V_88 = V_200 - 1 ; V_88 > 0 ; V_88 -- )
V_2 -> V_201 [ V_88 ] = V_202 ;
V_2 -> V_201 [ 0 ] = V_203 ;
}
static void T_1 F_226 ( struct V_1 * V_2 )
{
int V_204 ;
int V_205 ;
int V_88 ;
V_205 = V_206 ;
for ( V_88 = V_200 - 1 ; V_88 >= 0 ; V_88 -- ) {
V_204 = V_2 -> V_207 [ V_88 ] ;
V_2 -> V_201 [ V_88 ] = ( V_205 + V_204 - 1 ) / V_204 ;
V_205 = V_204 ;
}
}
static void T_1 F_227 ( struct V_1 * V_2 ,
struct V_6 T_4 * V_95 )
{
static char * V_208 [] = { L_49 ,
L_50 ,
L_51 ,
L_52 } ;
static char * V_209 [] = { L_53 ,
L_54 ,
L_55 ,
L_56 } ;
int V_210 = 1 ;
int V_88 ;
int V_76 ;
struct V_19 * V_49 ;
F_228 ( V_211 > F_229 ( V_208 ) ) ;
for ( V_88 = 0 ; V_88 < V_200 ; V_88 ++ )
V_2 -> V_207 [ V_88 ] = V_212 [ V_88 ] ;
for ( V_88 = 1 ; V_88 < V_200 ; V_88 ++ )
V_2 -> V_96 [ V_88 ] = V_2 -> V_96 [ V_88 - 1 ] + V_2 -> V_207 [ V_88 - 1 ] ;
F_226 ( V_2 ) ;
for ( V_88 = V_200 - 1 ; V_88 >= 0 ; V_88 -- ) {
V_210 *= V_2 -> V_201 [ V_88 ] ;
V_49 = V_2 -> V_96 [ V_88 ] ;
for ( V_76 = 0 ; V_76 < V_2 -> V_207 [ V_88 ] ; V_76 ++ , V_49 ++ ) {
F_230 ( & V_49 -> V_69 ) ;
F_231 ( & V_49 -> V_69 ,
& V_213 [ V_88 ] , V_208 [ V_88 ] ) ;
F_230 ( & V_49 -> V_144 ) ;
F_231 ( & V_49 -> V_144 ,
& V_214 [ V_88 ] , V_209 [ V_88 ] ) ;
V_49 -> V_4 = V_2 -> V_4 ;
V_49 -> V_3 = V_2 -> V_3 ;
V_49 -> V_72 = 0 ;
V_49 -> V_52 = 0 ;
V_49 -> V_74 = V_76 * V_210 ;
V_49 -> V_73 = ( V_76 + 1 ) * V_210 - 1 ;
if ( V_49 -> V_73 >= V_215 )
V_49 -> V_73 = V_215 - 1 ;
if ( V_88 == 0 ) {
V_49 -> V_216 = 0 ;
V_49 -> V_51 = 0 ;
V_49 -> V_116 = NULL ;
} else {
V_49 -> V_216 = V_76 % V_2 -> V_201 [ V_88 - 1 ] ;
V_49 -> V_51 = 1UL << V_49 -> V_216 ;
V_49 -> V_116 = V_2 -> V_96 [ V_88 - 1 ] +
V_76 / V_2 -> V_201 [ V_88 - 1 ] ;
}
V_49 -> V_96 = V_88 ;
F_232 ( & V_49 -> V_217 ) ;
}
}
V_2 -> V_95 = V_95 ;
F_233 ( & V_2 -> V_108 ) ;
V_49 = V_2 -> V_96 [ V_200 - 1 ] ;
F_234 (i) {
while ( V_88 > V_49 -> V_73 )
V_49 ++ ;
F_137 ( V_2 -> V_95 , V_88 ) -> V_50 = V_49 ;
F_212 ( V_88 , V_2 ) ;
}
F_235 ( & V_2 -> V_218 , & V_219 ) ;
}
static void T_1 F_236 ( void )
{
int V_88 ;
int V_76 ;
int V_220 = V_206 ;
int V_221 [ V_211 + 1 ] ;
if ( V_203 == V_222 &&
V_206 == V_215 )
return;
V_221 [ 0 ] = 1 ;
V_221 [ 1 ] = V_203 ;
for ( V_88 = 2 ; V_88 <= V_211 ; V_88 ++ )
V_221 [ V_88 ] = V_221 [ V_88 - 1 ] * V_202 ;
if ( V_203 < V_222 ||
V_203 > sizeof( unsigned long ) * 8 ||
V_220 > V_221 [ V_211 ] ) {
F_224 ( 1 ) ;
return;
}
for ( V_88 = 1 ; V_88 <= V_211 ; V_88 ++ )
if ( V_220 <= V_221 [ V_88 ] ) {
for ( V_76 = 0 ; V_76 <= V_88 ; V_76 ++ )
V_212 [ V_76 ] =
F_237 ( V_220 , V_221 [ V_88 - V_76 ] ) ;
V_200 = V_88 ;
for ( V_76 = V_88 + 1 ; V_76 <= V_211 ; V_76 ++ )
V_212 [ V_76 ] = 0 ;
break;
}
V_97 = 0 ;
for ( V_88 = 0 ; V_88 <= V_211 ; V_88 ++ )
V_97 += V_212 [ V_88 ] ;
V_97 -= V_220 ;
}
void T_1 F_238 ( void )
{
int V_5 ;
F_239 () ;
F_236 () ;
F_227 ( & V_11 , & V_8 ) ;
F_227 ( & V_12 , & V_10 ) ;
F_240 () ;
F_241 ( V_150 , F_165 ) ;
F_242 ( F_217 , 0 ) ;
F_207 (cpu)
F_217 ( NULL , V_185 , ( void * ) ( long ) V_5 ) ;
F_90 () ;
}
