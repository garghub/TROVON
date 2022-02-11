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
int V_19 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( ! V_7 -> V_17 [ V_20 ] )
return 0 ;
if ( * V_7 -> V_17 [ V_21 ] )
return 1 ;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ )
if ( V_7 -> V_17 [ V_19 - 1 ] != V_7 -> V_17 [ V_19 ] &&
F_19 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_23 [ V_19 ] ) )
return 1 ;
return 0 ;
}
static struct V_24 * F_20 ( struct V_1 * V_2 )
{
return & V_2 -> V_25 [ 0 ] ;
}
static void F_21 ( struct V_26 * V_27 , long long V_28 ,
bool V_29 )
{
F_22 ( L_6 , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_23 ( V_31 ) ) {
struct V_32 * V_33 = F_24 ( F_25 () ) ;
F_22 ( L_7 , V_28 , 0 ) ;
F_26 ( V_34 ) ;
F_27 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
F_28 ( F_25 () ) ;
F_29 () ;
F_30 ( & V_27 -> V_37 ) ;
F_31 () ;
F_32 ( F_33 ( & V_27 -> V_37 ) & 0x1 ) ;
F_34 ( ! F_35 ( & V_38 ) ,
L_9 ) ;
F_34 ( ! F_35 ( & V_39 ) ,
L_10 ) ;
F_34 ( ! F_35 ( & V_40 ) ,
L_11 ) ;
}
static void F_36 ( bool V_29 )
{
long long V_28 ;
struct V_26 * V_27 ;
V_27 = & F_37 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_32 ( ( V_28 & V_41 ) == 0 ) ;
if ( ( V_28 & V_41 ) == V_42 )
V_27 -> V_30 = 0 ;
else
V_27 -> V_30 -= V_42 ;
F_21 ( V_27 , V_28 , V_29 ) ;
}
void F_38 ( void )
{
unsigned long V_43 ;
F_39 ( V_43 ) ;
F_36 ( false ) ;
F_40 ( V_43 ) ;
}
void F_41 ( void )
{
F_36 ( 1 ) ;
}
void F_42 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
F_39 ( V_43 ) ;
V_27 = & F_37 ( V_26 ) ;
F_32 ( ! ( V_27 -> V_30 & V_44 ) ) ;
V_27 -> V_30 = 1 ;
F_40 ( V_43 ) ;
}
void F_43 ( void )
{
unsigned long V_43 ;
long long V_28 ;
struct V_26 * V_27 ;
F_39 ( V_43 ) ;
V_27 = & F_37 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 -- ;
F_32 ( V_27 -> V_30 < 0 ) ;
if ( V_27 -> V_30 )
F_22 ( L_12 , V_28 , V_27 -> V_30 ) ;
else
F_21 ( V_27 , V_28 , true ) ;
F_40 ( V_43 ) ;
}
static void F_44 ( struct V_26 * V_27 , long long V_28 ,
int V_29 )
{
F_29 () ;
F_30 ( & V_27 -> V_37 ) ;
F_31 () ;
F_32 ( ! ( F_33 ( & V_27 -> V_37 ) & 0x1 ) ) ;
F_45 ( F_25 () ) ;
F_22 ( L_13 , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_23 ( V_31 ) ) {
struct V_32 * V_33 = F_24 ( F_25 () ) ;
F_22 ( L_14 ,
V_28 , V_27 -> V_30 ) ;
F_26 ( V_34 ) ;
F_27 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
}
static void F_46 ( bool V_29 )
{
struct V_26 * V_27 ;
long long V_28 ;
V_27 = & F_37 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_32 ( V_28 < 0 ) ;
if ( V_28 & V_41 )
V_27 -> V_30 += V_42 ;
else
V_27 -> V_30 = V_45 ;
F_44 ( V_27 , V_28 , V_29 ) ;
}
void F_47 ( void )
{
unsigned long V_43 ;
F_39 ( V_43 ) ;
F_46 ( false ) ;
F_40 ( V_43 ) ;
}
void F_48 ( void )
{
F_46 ( 1 ) ;
}
void F_49 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
F_39 ( V_43 ) ;
V_27 = & F_37 ( V_26 ) ;
F_32 ( V_27 -> V_30 & V_41 ) ;
V_27 -> V_30 += V_45 ;
F_40 ( V_43 ) ;
}
void F_50 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
long long V_28 ;
F_39 ( V_43 ) ;
V_27 = & F_37 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 ++ ;
F_32 ( V_27 -> V_30 == 0 ) ;
if ( V_28 )
F_22 ( L_15 , V_28 , V_27 -> V_30 ) ;
else
F_44 ( V_27 , V_28 , true ) ;
F_40 ( V_43 ) ;
}
void F_51 ( void )
{
struct V_26 * V_27 = & F_37 ( V_26 ) ;
if ( V_27 -> V_46 == 0 &&
( F_33 ( & V_27 -> V_37 ) & 0x1 ) )
return;
V_27 -> V_46 ++ ;
F_29 () ;
F_30 ( & V_27 -> V_37 ) ;
F_31 () ;
F_32 ( ! ( F_33 ( & V_27 -> V_37 ) & 0x1 ) ) ;
}
void F_52 ( void )
{
struct V_26 * V_27 = & F_37 ( V_26 ) ;
if ( V_27 -> V_46 == 0 ||
-- V_27 -> V_46 != 0 )
return;
F_29 () ;
F_30 ( & V_27 -> V_37 ) ;
F_31 () ;
F_32 ( F_33 ( & V_27 -> V_37 ) & 0x1 ) ;
}
int F_53 ( void )
{
int V_47 ;
F_54 () ;
V_47 = ( F_33 ( & F_37 ( V_26 ) . V_37 ) & 0x1 ) == 0 ;
F_55 () ;
return V_47 ;
}
bool F_56 ( void )
{
struct V_6 * V_7 ;
struct V_24 * V_48 ;
bool V_47 ;
if ( F_57 () )
return 1 ;
F_54 () ;
V_7 = & F_37 ( V_8 ) ;
V_48 = V_7 -> V_49 ;
V_47 = ( V_7 -> V_50 & V_48 -> V_51 ) ||
! V_52 ;
F_55 () ;
return V_47 ;
}
static int F_58 ( void )
{
return F_37 ( V_26 ) . V_30 <= 1 ;
}
static int F_59 ( struct V_6 * V_7 )
{
V_7 -> V_53 = F_60 ( 0 , & V_7 -> V_37 -> V_37 ) ;
return ( V_7 -> V_53 & 0x1 ) == 0 ;
}
static int F_61 ( struct V_6 * V_7 )
{
unsigned int V_54 ;
unsigned int V_55 ;
V_54 = ( unsigned int ) F_60 ( 0 , & V_7 -> V_37 -> V_37 ) ;
V_55 = ( unsigned int ) V_7 -> V_53 ;
if ( ( V_54 & 0x1 ) == 0 || F_62 ( V_54 , V_55 + 2 ) ) {
F_63 ( V_7 -> V_2 -> V_56 , V_7 -> V_4 , V_7 -> V_5 , L_16 ) ;
V_7 -> V_57 ++ ;
return 1 ;
}
if ( F_64 ( V_7 -> V_2 -> V_58 + 2 , V_59 ) )
return 0 ;
F_65 () ;
if ( F_66 ( V_7 -> V_5 ) ) {
F_63 ( V_7 -> V_2 -> V_56 , V_7 -> V_4 , V_7 -> V_5 , L_17 ) ;
V_7 -> V_60 ++ ;
return 1 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_58 = V_59 ;
V_2 -> V_61 = V_59 + F_68 () ;
}
static void F_69 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_48 ;
F_70 (rsp, rnp) {
F_71 ( & V_48 -> V_62 , V_43 ) ;
if ( V_48 -> V_63 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_64 - V_48 -> V_65 ; V_5 ++ )
if ( V_48 -> V_63 & ( 1UL << V_5 ) )
F_72 ( V_48 -> V_65 + V_5 ) ;
}
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
int V_5 ;
long V_66 ;
unsigned long V_43 ;
int V_67 = 0 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
long V_68 = 0 ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_66 = V_59 - V_2 -> V_61 ;
if ( V_66 < V_69 || ! F_1 ( V_2 ) ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_2 -> V_61 = V_59 + 3 * F_68 () + 3 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_75 ( V_70 L_18 ,
V_2 -> V_56 ) ;
F_76 () ;
F_70 (rsp, rnp) {
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_67 += F_77 ( V_48 ) ;
if ( V_48 -> V_63 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_64 - V_48 -> V_65 ; V_5 ++ )
if ( V_48 -> V_63 & ( 1UL << V_5 ) ) {
F_78 ( V_2 ,
V_48 -> V_65 + V_5 ) ;
V_67 ++ ;
}
}
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
V_48 = F_20 ( V_2 ) ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_67 += F_77 ( V_48 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_79 () ;
F_80 (cpu)
V_68 += F_81 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_82 ( L_19 ,
F_25 () , ( long ) ( V_59 - V_2 -> V_58 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_68 ) ;
if ( V_67 == 0 )
F_75 ( V_70 L_20 ) ;
else if ( ! F_83 () )
F_69 ( V_2 ) ;
F_84 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
long V_68 = 0 ;
F_75 ( V_70 L_21 , V_2 -> V_56 ) ;
F_76 () ;
F_78 ( V_2 , F_25 () ) ;
F_79 () ;
F_80 (cpu)
V_68 += F_81 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_82 ( L_22 ,
V_59 - V_2 -> V_58 , V_2 -> V_4 , V_2 -> V_3 , V_68 ) ;
if ( ! F_83 () )
F_86 () ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
if ( F_64 ( V_59 , V_2 -> V_61 ) )
V_2 -> V_61 = V_59 +
3 * F_68 () + 3 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_87 () ;
}
static void F_88 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_73 ;
unsigned long V_74 ;
struct V_24 * V_48 ;
if ( V_75 )
return;
V_73 = F_2 ( V_59 ) ;
V_74 = F_2 ( V_2 -> V_61 ) ;
V_48 = V_7 -> V_49 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_48 -> V_63 ) & V_7 -> V_50 ) && F_64 ( V_73 , V_74 ) ) {
F_85 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_64 ( V_73 , V_74 + V_69 ) ) {
F_74 ( V_2 ) ;
}
}
void F_89 ( void )
{
struct V_1 * V_2 ;
F_90 (rsp)
V_2 -> V_61 = V_59 + V_76 / 2 ;
}
static void F_91 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_48 -> V_4 ) {
V_7 -> V_4 = V_48 -> V_4 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_23 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_77 = ! ! ( V_48 -> V_63 & V_7 -> V_50 ) ;
F_92 ( V_7 ) ;
}
}
static void F_93 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
F_39 ( V_43 ) ;
V_48 = V_7 -> V_49 ;
if ( V_7 -> V_4 == F_2 ( V_48 -> V_4 ) ||
! F_94 ( & V_48 -> V_62 ) ) {
F_40 ( V_43 ) ;
return;
}
F_91 ( V_2 , V_48 , V_7 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
static int
F_95 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
int V_47 = 0 ;
F_39 ( V_43 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_93 ( V_2 , V_7 ) ;
V_47 = 1 ;
}
F_40 ( V_43 ) ;
return V_47 ;
}
static void F_96 ( struct V_6 * V_7 )
{
int V_19 ;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_97 ( V_7 ) ;
}
static unsigned long F_98 ( struct V_1 * V_2 ,
struct V_24 * V_48 )
{
if ( F_20 ( V_2 ) == V_48 && V_48 -> V_4 == V_48 -> V_3 )
return V_48 -> V_3 + 1 ;
return V_48 -> V_3 + 2 ;
}
static void F_99 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
unsigned long V_79 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_79 = F_98 ( V_2 , V_48 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_64 ( V_7 -> V_23 [ V_19 ] , V_79 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_79 ;
}
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_24 ) ;
else
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_25 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
int V_19 , V_73 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_19 ( V_48 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
break;
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_19 ] ;
}
for ( V_73 = V_22 ; V_73 < V_19 ; V_73 ++ )
V_7 -> V_17 [ V_73 ] = V_7 -> V_17 [ V_18 ] ;
for ( V_73 = V_22 ; V_19 < V_20 ; V_19 ++ , V_73 ++ ) {
if ( V_7 -> V_17 [ V_73 ] == V_7 -> V_17 [ V_20 ] )
break;
V_7 -> V_17 [ V_73 ] = V_7 -> V_17 [ V_19 ] ;
V_7 -> V_23 [ V_73 ] = V_7 -> V_23 [ V_19 ] ;
}
F_99 ( V_2 , V_48 , V_7 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_48 -> V_3 ) {
F_99 ( V_2 , V_48 , V_7 ) ;
} else {
F_100 ( V_2 , V_48 , V_7 ) ;
V_7 -> V_3 = V_48 -> V_3 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_26 ) ;
if ( F_19 ( V_7 -> V_4 , V_7 -> V_3 ) ) {
V_7 -> V_4 = V_7 -> V_3 ;
V_7 -> V_9 = 0 ;
}
if ( ( V_48 -> V_63 & V_7 -> V_50 ) == 0 )
V_7 -> V_77 = 0 ;
}
}
static void
F_102 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
F_39 ( V_43 ) ;
V_48 = V_7 -> V_49 ;
if ( V_7 -> V_3 == F_2 ( V_48 -> V_3 ) ||
! F_94 ( & V_48 -> V_62 ) ) {
F_40 ( V_43 ) ;
return;
}
F_101 ( V_2 , V_48 , V_7 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
static void
F_103 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
F_101 ( V_2 , V_48 , V_7 ) ;
F_91 ( V_2 , V_48 , V_7 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
F_105 ( & V_48 -> V_62 ) ;
V_2 -> V_80 = 0 ;
if ( F_1 ( V_2 ) ) {
F_106 ( & V_48 -> V_62 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_56 , V_2 -> V_4 , L_27 ) ;
F_67 ( V_2 ) ;
F_106 ( & V_48 -> V_62 ) ;
F_107 ( & V_2 -> V_81 ) ;
F_108 (rsp, rnp) {
F_105 ( & V_48 -> V_62 ) ;
V_7 = F_109 ( V_2 -> V_71 ) ;
F_110 ( V_48 ) ;
V_48 -> V_63 = V_48 -> V_51 ;
V_48 -> V_4 = V_2 -> V_4 ;
F_32 ( V_48 -> V_3 != V_2 -> V_3 ) ;
V_48 -> V_3 = V_2 -> V_3 ;
if ( V_48 == V_7 -> V_49 )
F_103 ( V_2 , V_48 , V_7 ) ;
F_111 ( V_48 ) ;
F_112 ( V_2 -> V_56 , V_48 -> V_4 ,
V_48 -> V_82 , V_48 -> V_65 ,
V_48 -> V_64 , V_48 -> V_63 ) ;
F_106 ( & V_48 -> V_62 ) ;
#ifdef F_113
if ( ( F_114 () % ( V_83 * 8 ) ) == 0 )
F_115 ( 2 ) ;
#endif
F_116 () ;
}
F_117 ( & V_2 -> V_81 ) ;
return 1 ;
}
int F_118 ( struct V_1 * V_2 , int V_84 )
{
int V_85 = V_84 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
V_2 -> V_86 ++ ;
if ( V_85 == V_87 ) {
F_119 ( V_2 , F_59 ) ;
V_85 = V_88 ;
} else {
F_119 ( V_2 , F_61 ) ;
}
if ( F_2 ( V_2 -> V_80 ) & V_89 ) {
F_105 ( & V_48 -> V_62 ) ;
V_2 -> V_80 &= ~ V_89 ;
F_106 ( & V_48 -> V_62 ) ;
}
return V_85 ;
}
static void F_120 ( struct V_1 * V_2 )
{
unsigned long V_90 ;
struct V_6 * V_7 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
F_105 ( & V_48 -> V_62 ) ;
V_90 = V_59 - V_2 -> V_58 ;
if ( V_90 > V_2 -> V_91 )
V_2 -> V_91 = V_90 ;
F_106 ( & V_48 -> V_62 ) ;
F_108 (rsp, rnp) {
F_105 ( & V_48 -> V_62 ) ;
V_48 -> V_3 = V_2 -> V_4 ;
F_106 ( & V_48 -> V_62 ) ;
F_116 () ;
}
V_48 = F_20 ( V_2 ) ;
F_105 ( & V_48 -> V_62 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_56 , V_2 -> V_3 , L_28 ) ;
V_2 -> V_85 = V_92 ;
V_7 = F_109 ( V_2 -> V_71 ) ;
if ( F_18 ( V_2 , V_7 ) )
V_2 -> V_80 = 1 ;
F_106 ( & V_48 -> V_62 ) ;
}
static int T_1 F_121 ( void * V_93 )
{
int V_85 ;
unsigned long V_73 ;
int V_47 ;
struct V_1 * V_2 = V_93 ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_122 ( V_2 -> V_94 ,
V_2 -> V_80 &
V_95 ) ;
if ( ( V_2 -> V_80 & V_95 ) &&
F_104 ( V_2 ) )
break;
F_116 () ;
F_123 ( V_31 ) ;
}
V_85 = V_87 ;
V_73 = V_96 ;
if ( V_73 > V_97 ) {
V_73 = V_97 ;
V_96 = V_97 ;
}
for (; ; ) {
V_2 -> V_98 = V_59 + V_73 ;
V_47 = F_124 ( V_2 -> V_94 ,
( V_2 -> V_80 & V_89 ) ||
( ! F_2 ( V_48 -> V_63 ) &&
! F_125 ( V_48 ) ) ,
V_73 ) ;
if ( ! F_2 ( V_48 -> V_63 ) &&
! F_125 ( V_48 ) )
break;
if ( V_47 == 0 || ( V_2 -> V_80 & V_89 ) ) {
V_85 = F_118 ( V_2 , V_85 ) ;
F_116 () ;
} else {
F_116 () ;
F_123 ( V_31 ) ;
}
V_73 = V_99 ;
if ( V_73 > V_97 ) {
V_73 = V_97 ;
V_99 = V_97 ;
} else if ( V_73 < 1 ) {
V_73 = 1 ;
V_99 = 1 ;
}
}
F_120 ( V_2 ) ;
}
}
static void
F_126 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void F_127 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void
F_128 ( unsigned long V_100 , struct V_1 * V_2 ,
struct V_24 * V_48 , unsigned long V_43 )
__releases( V_48 -> V_62 )
{
struct V_24 * V_101 ;
for (; ; ) {
if ( ! ( V_48 -> V_63 & V_100 ) ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_48 -> V_63 &= ~ V_100 ;
F_129 ( V_2 -> V_56 , V_48 -> V_4 ,
V_100 , V_48 -> V_63 , V_48 -> V_82 ,
V_48 -> V_65 , V_48 -> V_64 ,
! ! V_48 -> V_102 ) ;
if ( V_48 -> V_63 != 0 || F_125 ( V_48 ) ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_100 = V_48 -> V_50 ;
if ( V_48 -> V_103 == NULL ) {
break;
}
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_101 = V_48 ;
V_48 = V_48 -> V_103 ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
F_32 ( V_101 -> V_63 ) ;
}
F_127 ( V_2 , V_43 ) ;
}
static void
F_130 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
unsigned long V_100 ;
struct V_24 * V_48 ;
V_48 = V_7 -> V_49 ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_48 -> V_4 ||
V_48 -> V_3 == V_48 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_100 = V_7 -> V_50 ;
if ( ( V_48 -> V_63 & V_100 ) == 0 ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
} else {
V_7 -> V_77 = 0 ;
F_99 ( V_2 , V_48 , V_7 ) ;
F_128 ( V_100 , V_2 , V_48 , V_43 ) ;
}
}
static void
F_131 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_95 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_77 )
return;
if ( ! V_7 -> V_9 )
return;
F_130 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_132 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( F_133 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_104 += V_7 -> V_104 ;
V_2 -> V_72 += V_7 -> V_72 ;
V_7 -> V_105 += V_7 -> V_72 ;
V_7 -> V_104 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_106 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_106 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_107 = V_7 -> V_16 ;
V_2 -> V_107 = V_7 -> V_17 [ V_18 ] ;
}
F_96 ( V_7 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_6 * V_7 = F_135 ( V_2 -> V_71 ) ;
if ( F_136 ( V_2 , V_7 ) )
return;
V_7 -> V_104 += V_2 -> V_104 ;
V_7 -> V_72 += V_2 -> V_72 ;
V_7 -> V_108 += V_2 -> V_72 ;
if ( V_2 -> V_104 != V_2 -> V_72 )
F_137 () ;
V_2 -> V_104 = 0 ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_109 != NULL ) {
* V_2 -> V_107 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_109 ;
for ( V_19 = V_78 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_107 ;
V_2 -> V_109 = NULL ;
V_2 -> V_107 = & V_2 -> V_109 ;
}
if ( V_2 -> V_110 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_110 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_106 ;
V_2 -> V_110 = NULL ;
V_2 -> V_106 = & V_2 -> V_110 ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
F_139 (unsigned long mask) ;
F_139 ( struct V_6 * V_7 = F_109 ( V_2 -> V_71 ) ) ;
F_139 ( struct V_24 * V_48 = V_7 -> V_49 ) ;
F_139 ( V_100 = V_7 -> V_50 ) ;
F_5 ( V_2 -> V_56 ,
V_48 -> V_4 + 1 - ! ! ( V_48 -> V_63 & V_100 ) ,
L_29 ) ;
}
static void F_140 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned long V_100 ;
int V_111 = 0 ;
struct V_6 * V_7 = F_81 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
F_141 ( V_48 , - 1 ) ;
F_107 ( & V_2 -> V_81 ) ;
F_71 ( & V_2 -> V_112 , V_43 ) ;
F_132 ( V_5 , V_2 , V_48 , V_7 ) ;
F_134 ( V_2 ) ;
V_100 = V_7 -> V_50 ;
do {
F_142 ( & V_48 -> V_62 ) ;
V_48 -> V_51 &= ~ V_100 ;
if ( V_48 -> V_51 != 0 ) {
if ( V_48 != V_7 -> V_49 )
F_143 ( & V_48 -> V_62 ) ;
break;
}
if ( V_48 == V_7 -> V_49 )
V_111 = F_144 ( V_2 , V_48 , V_7 ) ;
else
F_143 ( & V_48 -> V_62 ) ;
V_100 = V_48 -> V_50 ;
V_48 = V_48 -> V_103 ;
} while ( V_48 != NULL );
F_143 ( & V_2 -> V_112 ) ;
V_48 = V_7 -> V_49 ;
if ( V_111 & V_113 )
F_145 ( V_48 , V_43 ) ;
else
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( V_111 & V_114 )
F_146 ( V_2 , V_48 , true ) ;
F_27 ( V_7 -> V_72 != 0 || V_7 -> V_16 != NULL ,
L_30 ,
V_5 , V_7 -> V_72 , V_7 -> V_16 ) ;
F_96 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_117 ( & V_2 -> V_81 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
}
static void F_140 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_147 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_115 * V_116 , * V_117 , * * V_118 ;
long V_119 , V_120 , V_121 ;
int V_19 ;
if ( ! F_17 ( V_7 ) ) {
F_148 ( V_2 -> V_56 , V_7 -> V_104 , V_7 -> V_72 , 0 ) ;
F_149 ( V_2 -> V_56 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_150 () , F_23 ( V_31 ) ,
F_151 () ) ;
return;
}
F_39 ( V_43 ) ;
F_32 ( F_66 ( F_25 () ) ) ;
V_119 = V_7 -> V_122 ;
F_148 ( V_2 -> V_56 , V_7 -> V_104 , V_7 -> V_72 , V_119 ) ;
V_117 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_118 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_78 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_40 ( V_43 ) ;
V_120 = V_121 = 0 ;
while ( V_117 ) {
V_116 = V_117 -> V_116 ;
F_152 ( V_116 ) ;
F_153 ( V_117 ) ;
if ( F_154 ( V_2 -> V_56 , V_117 ) )
V_121 ++ ;
V_117 = V_116 ;
if ( ++ V_120 >= V_119 &&
( F_150 () ||
( ! F_23 ( V_31 ) && ! F_151 () ) ) )
break;
}
F_39 ( V_43 ) ;
F_149 ( V_2 -> V_56 , V_120 , ! ! V_117 , F_150 () ,
F_23 ( V_31 ) ,
F_151 () ) ;
if ( V_117 != NULL ) {
* V_118 = V_7 -> V_16 ;
V_7 -> V_16 = V_117 ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_118 ;
else
break;
}
F_155 () ;
V_7 -> V_104 -= V_121 ;
F_2 ( V_7 -> V_72 ) -= V_120 ;
V_7 -> V_123 += V_120 ;
if ( V_7 -> V_122 == V_124 && V_7 -> V_72 <= V_125 )
V_7 -> V_122 = V_122 ;
if ( V_7 -> V_72 == 0 && V_7 -> V_126 != 0 ) {
V_7 -> V_126 = 0 ;
V_7 -> V_127 = V_2 -> V_86 ;
} else if ( V_7 -> V_72 < V_7 -> V_126 - V_128 )
V_7 -> V_126 = V_7 -> V_72 ;
F_32 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_72 == 0 ) ) ;
F_40 ( V_43 ) ;
if ( F_17 ( V_7 ) )
F_156 () ;
}
void F_157 ( int V_5 , int V_29 )
{
F_8 ( L_31 ) ;
F_158 () ;
if ( V_29 || F_58 () ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_159 () ) {
F_6 ( V_5 ) ;
}
F_160 ( V_5 ) ;
if ( F_161 ( V_5 ) )
F_156 () ;
F_8 ( L_32 ) ;
}
static void F_119 ( struct V_1 * V_2 , int (* F_162)( struct V_6 * ) )
{
unsigned long V_129 ;
int V_5 ;
unsigned long V_43 ;
unsigned long V_100 ;
struct V_24 * V_48 ;
F_70 (rsp, rnp) {
F_116 () ;
V_100 = 0 ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
if ( ! F_1 ( V_2 ) ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
return;
}
if ( V_48 -> V_63 == 0 ) {
F_163 ( V_48 , V_43 ) ;
continue;
}
V_5 = V_48 -> V_65 ;
V_129 = 1 ;
for (; V_5 <= V_48 -> V_64 ; V_5 ++ , V_129 <<= 1 ) {
if ( ( V_48 -> V_63 & V_129 ) != 0 &&
F_162 ( F_81 ( V_2 -> V_71 , V_5 ) ) )
V_100 |= V_129 ;
}
if ( V_100 != 0 ) {
F_128 ( V_100 , V_2 , V_48 , V_43 ) ;
continue;
}
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
V_48 = F_20 ( V_2 ) ;
if ( V_48 -> V_63 == 0 ) {
F_71 ( & V_48 -> V_62 , V_43 ) ;
F_163 ( V_48 , V_43 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
bool V_47 ;
struct V_24 * V_48 ;
struct V_24 * V_130 = NULL ;
V_48 = F_81 ( V_2 -> V_71 , F_164 () ) -> V_49 ;
for (; V_48 != NULL ; V_48 = V_48 -> V_103 ) {
V_47 = ( F_2 ( V_2 -> V_80 ) & V_89 ) ||
! F_94 ( & V_48 -> V_131 ) ;
if ( V_130 != NULL )
F_143 ( & V_130 -> V_131 ) ;
if ( V_47 ) {
V_2 -> V_132 ++ ;
return;
}
V_130 = V_48 ;
}
F_71 ( & V_130 -> V_62 , V_43 ) ;
F_143 ( & V_130 -> V_131 ) ;
if ( F_2 ( V_2 -> V_80 ) & V_89 ) {
V_2 -> V_132 ++ ;
F_73 ( & V_130 -> V_62 , V_43 ) ;
return;
}
V_2 -> V_80 |= V_89 ;
F_73 ( & V_130 -> V_62 , V_43 ) ;
F_165 ( & V_2 -> V_94 ) ;
}
static void
F_166 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_135 ( V_2 -> V_71 ) ;
F_32 ( V_7 -> V_133 == 0 ) ;
F_102 ( V_2 , V_7 ) ;
F_131 ( V_2 , V_7 ) ;
F_39 ( V_43 ) ;
if ( F_18 ( V_2 , V_7 ) ) {
F_142 ( & F_20 ( V_2 ) -> V_62 ) ;
F_126 ( V_2 , V_43 ) ;
} else {
F_40 ( V_43 ) ;
}
if ( F_17 ( V_7 ) )
F_167 ( V_2 , V_7 ) ;
}
static void F_168 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
if ( F_66 ( F_25 () ) )
return;
F_8 ( L_33 ) ;
F_90 (rsp)
F_166 ( V_2 ) ;
F_8 ( L_34 ) ;
}
static void F_167 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_169 ( ! F_2 ( V_52 ) ) )
return;
if ( F_170 ( ! V_2 -> V_136 ) ) {
F_147 ( V_2 , V_7 ) ;
return;
}
F_171 () ;
}
static void F_156 ( void )
{
F_172 ( V_137 ) ;
}
static void F_173 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_115 * V_138 , unsigned long V_43 )
{
if ( F_53 () && F_174 ( F_25 () ) )
F_156 () ;
if ( F_175 ( V_43 ) || F_66 ( F_25 () ) )
return;
if ( F_169 ( V_7 -> V_72 > V_7 -> V_126 + V_128 ) ) {
F_102 ( V_2 , V_7 ) ;
F_95 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_139 ;
struct V_24 * V_140 = F_20 ( V_2 ) ;
F_71 ( & V_140 -> V_62 , V_139 ) ;
F_126 ( V_2 , V_139 ) ;
} else {
V_7 -> V_122 = V_124 ;
if ( V_2 -> V_86 == V_7 -> V_127 &&
* V_7 -> V_17 [ V_18 ] != V_138 )
F_13 ( V_2 ) ;
V_7 -> V_127 = V_2 -> V_86 ;
V_7 -> V_126 = V_7 -> V_72 ;
}
}
}
static void
F_176 ( struct V_115 * V_138 , void (* F_177)( struct V_115 * V_141 ) ,
struct V_1 * V_2 , int V_5 , bool V_142 )
{
unsigned long V_43 ;
struct V_6 * V_7 ;
F_32 ( ( unsigned long ) V_138 & 0x3 ) ;
F_178 ( V_138 ) ;
V_138 -> F_177 = F_177 ;
V_138 -> V_116 = NULL ;
F_39 ( V_43 ) ;
V_7 = F_109 ( V_2 -> V_71 ) ;
if ( F_169 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_143 ;
if ( V_5 != - 1 )
V_7 = F_81 ( V_2 -> V_71 , V_5 ) ;
V_143 = ! F_179 ( V_7 , V_138 , V_142 ) ;
F_32 ( V_143 ) ;
F_40 ( V_43 ) ;
return;
}
F_2 ( V_7 -> V_72 ) ++ ;
if ( V_142 )
V_7 -> V_104 ++ ;
else
F_137 () ;
F_155 () ;
* V_7 -> V_17 [ V_20 ] = V_138 ;
V_7 -> V_17 [ V_20 ] = & V_138 -> V_116 ;
if ( F_180 ( ( unsigned long ) F_177 ) )
F_181 ( V_2 -> V_56 , V_138 , ( unsigned long ) F_177 ,
V_7 -> V_104 , V_7 -> V_72 ) ;
else
F_182 ( V_2 -> V_56 , V_138 , V_7 -> V_104 , V_7 -> V_72 ) ;
F_173 ( V_2 , V_7 , V_138 , V_43 ) ;
F_40 ( V_43 ) ;
}
void F_183 ( struct V_115 * V_138 , void (* F_177)( struct V_115 * V_141 ) )
{
F_176 ( V_138 , F_177 , & V_11 , - 1 , 0 ) ;
}
void F_184 ( struct V_115 * V_138 , void (* F_177)( struct V_115 * V_141 ) )
{
F_176 ( V_138 , F_177 , & V_12 , - 1 , 0 ) ;
}
static inline int F_185 ( void )
{
int V_47 ;
F_186 () ;
F_54 () ;
V_47 = F_187 () <= 1 ;
F_55 () ;
return V_47 ;
}
void F_188 ( void )
{
F_34 ( ! F_35 ( & V_39 ) &&
! F_35 ( & V_38 ) &&
! F_35 ( & V_40 ) ,
L_35 ) ;
if ( F_185 () )
return;
if ( V_144 )
F_189 () ;
else
F_190 ( F_183 ) ;
}
void F_191 ( void )
{
F_34 ( ! F_35 ( & V_39 ) &&
! F_35 ( & V_38 ) &&
! F_35 ( & V_40 ) ,
L_36 ) ;
if ( F_185 () )
return;
if ( V_144 )
F_192 () ;
else
F_190 ( F_184 ) ;
}
static int F_193 ( void * V_145 )
{
F_155 () ;
return 0 ;
}
void F_189 ( void )
{
long V_146 , V_147 , V_55 ;
int V_148 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_64 ( ( V_149 ) F_194 ( & V_2 -> V_150 ) ,
( V_149 ) F_194 ( & V_2 -> V_151 ) +
V_76 / 8 ) ) {
F_188 () ;
F_195 ( & V_2 -> V_152 ) ;
return;
}
V_55 = F_196 ( & V_2 -> V_150 ) ;
V_146 = V_55 ;
F_197 () ;
F_32 ( F_66 ( F_164 () ) ) ;
while ( F_198 ( V_153 ,
F_193 ,
NULL ) == - V_154 ) {
F_199 () ;
F_195 ( & V_2 -> V_155 ) ;
V_147 = F_194 ( & V_2 -> V_151 ) ;
if ( F_64 ( ( V_149 ) V_147 , ( V_149 ) V_146 ) ) {
F_29 () ;
F_195 ( & V_2 -> V_156 ) ;
return;
}
if ( V_148 ++ < 10 ) {
F_200 ( V_148 * F_187 () ) ;
} else {
F_190 ( F_183 ) ;
F_195 ( & V_2 -> V_157 ) ;
return;
}
V_147 = F_194 ( & V_2 -> V_151 ) ;
if ( F_64 ( ( V_149 ) V_147 , ( V_149 ) V_146 ) ) {
F_29 () ;
F_195 ( & V_2 -> V_158 ) ;
return;
}
F_197 () ;
V_55 = F_194 ( & V_2 -> V_150 ) ;
F_155 () ;
}
F_195 ( & V_2 -> V_159 ) ;
do {
F_195 ( & V_2 -> V_160 ) ;
V_147 = F_194 ( & V_2 -> V_151 ) ;
if ( F_64 ( ( V_149 ) V_147 , ( V_149 ) V_55 ) ) {
F_29 () ;
F_195 ( & V_2 -> V_161 ) ;
break;
}
} while ( F_201 ( & V_2 -> V_151 , V_147 , V_55 ) != V_147 );
F_195 ( & V_2 -> V_162 ) ;
F_199 () ;
}
static int F_202 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_48 = V_7 -> V_49 ;
V_7 -> V_163 ++ ;
F_88 ( V_2 , V_7 ) ;
if ( V_52 &&
V_7 -> V_77 && ! V_7 -> V_9 ) {
V_7 -> V_164 ++ ;
} else if ( V_7 -> V_77 && V_7 -> V_9 ) {
V_7 -> V_165 ++ ;
return 1 ;
}
if ( F_17 ( V_7 ) ) {
V_7 -> V_166 ++ ;
return 1 ;
}
if ( F_18 ( V_2 , V_7 ) ) {
V_7 -> V_167 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_168 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_169 ++ ;
return 1 ;
}
V_7 -> V_170 ++ ;
return 0 ;
}
static int F_161 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
if ( F_202 ( V_2 , F_81 ( V_2 -> V_71 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_203 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
if ( F_81 ( V_2 -> V_71 , V_5 ) -> V_16 )
return 1 ;
return 0 ;
}
static void F_204 ( struct V_1 * V_2 , char * V_147 ,
int V_5 , unsigned long V_171 )
{
F_205 ( V_2 -> V_56 , V_147 , V_5 ,
F_33 ( & V_2 -> V_172 ) , V_171 ) ;
}
static void F_206 ( struct V_115 * V_173 )
{
struct V_6 * V_7 = F_207 ( V_173 , struct V_6 , V_174 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_208 ( & V_2 -> V_172 ) ) {
F_204 ( V_2 , L_37 , - 1 , V_2 -> V_175 ) ;
F_209 ( & V_2 -> V_176 ) ;
} else {
F_204 ( V_2 , L_38 , - 1 , V_2 -> V_175 ) ;
}
}
static void F_210 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_135 ( V_2 -> V_71 ) ;
F_204 ( V_2 , L_39 , - 1 , V_2 -> V_175 ) ;
F_30 ( & V_2 -> V_172 ) ;
V_2 -> V_177 ( & V_7 -> V_174 , F_206 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_55 = F_2 ( V_2 -> V_175 ) ;
unsigned long V_178 ;
F_204 ( V_2 , L_40 , - 1 , V_55 ) ;
F_107 ( & V_2 -> V_179 ) ;
F_155 () ;
V_178 = F_2 ( V_2 -> V_175 ) ;
F_204 ( V_2 , L_41 , - 1 , V_178 ) ;
if ( F_64 ( V_178 , ( ( V_55 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_204 ( V_2 , L_42 , - 1 , V_178 ) ;
F_155 () ;
F_117 ( & V_2 -> V_179 ) ;
return;
}
F_2 ( V_2 -> V_175 ) ++ ;
F_32 ( ( V_2 -> V_175 & 0x1 ) != 1 ) ;
F_204 ( V_2 , L_43 , - 1 , V_2 -> V_175 ) ;
F_155 () ;
F_212 ( & V_2 -> V_176 ) ;
F_213 ( & V_2 -> V_172 , 1 ) ;
F_197 () ;
F_80 (cpu) {
if ( ! F_174 ( V_5 ) && ! F_133 ( V_5 ) )
continue;
V_7 = F_81 ( V_2 -> V_71 , V_5 ) ;
if ( F_133 ( V_5 ) ) {
F_204 ( V_2 , L_44 , V_5 ,
V_2 -> V_175 ) ;
F_30 ( & V_2 -> V_172 ) ;
F_176 ( & V_7 -> V_174 , F_206 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_72 ) ) {
F_204 ( V_2 , L_45 , V_5 ,
V_2 -> V_175 ) ;
F_214 ( V_5 , F_210 , V_2 , 1 ) ;
} else {
F_204 ( V_2 , L_46 , V_5 ,
V_2 -> V_175 ) ;
}
}
F_199 () ;
if ( F_208 ( & V_2 -> V_172 ) )
F_209 ( & V_2 -> V_176 ) ;
F_155 () ;
F_2 ( V_2 -> V_175 ) ++ ;
F_32 ( ( V_2 -> V_175 & 0x1 ) != 0 ) ;
F_204 ( V_2 , L_47 , - 1 , V_2 -> V_175 ) ;
F_155 () ;
F_215 ( & V_2 -> V_176 ) ;
F_117 ( & V_2 -> V_179 ) ;
}
void F_216 ( void )
{
F_211 ( & V_12 ) ;
}
void F_217 ( void )
{
F_211 ( & V_11 ) ;
}
static void T_2
F_218 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_81 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_50 = 1UL << ( V_5 - V_7 -> V_49 -> V_65 ) ;
F_96 ( V_7 ) ;
V_7 -> V_104 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
V_7 -> V_37 = & F_4 ( V_26 , V_5 ) ;
F_32 ( V_7 -> V_37 -> V_30 != V_45 ) ;
F_32 ( F_33 ( & V_7 -> V_37 -> V_37 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_219 ( V_7 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
}
static void T_3
F_220 ( int V_5 , struct V_1 * V_2 , int V_180 )
{
unsigned long V_43 ;
unsigned long V_100 ;
struct V_6 * V_7 = F_81 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = F_20 ( V_2 ) ;
F_107 ( & V_2 -> V_81 ) ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_133 = 1 ;
V_7 -> V_180 = V_180 ;
V_7 -> V_126 = 0 ;
V_7 -> V_127 = V_2 -> V_86 ;
V_7 -> V_122 = V_122 ;
F_96 ( V_7 ) ;
V_7 -> V_37 -> V_30 = V_45 ;
F_213 ( & V_7 -> V_37 -> V_37 ,
( F_33 ( & V_7 -> V_37 -> V_37 ) & ~ 0x1 ) + 1 ) ;
F_221 ( V_5 ) ;
F_143 ( & V_48 -> V_62 ) ;
V_48 = V_7 -> V_49 ;
V_100 = V_7 -> V_50 ;
do {
F_142 ( & V_48 -> V_62 ) ;
V_48 -> V_51 |= V_100 ;
V_100 = V_48 -> V_50 ;
if ( V_48 == V_7 -> V_49 ) {
V_7 -> V_4 = V_48 -> V_3 ;
V_7 -> V_3 = V_48 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_77 = 0 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_48 ) ;
}
F_143 ( & V_48 -> V_62 ) ;
V_48 = V_48 -> V_103 ;
} while ( V_48 != NULL && ! ( V_48 -> V_51 & V_100 ) );
F_40 ( V_43 ) ;
F_117 ( & V_2 -> V_81 ) ;
}
static void T_3 F_222 ( int V_5 )
{
struct V_1 * V_2 ;
F_90 (rsp)
F_220 ( V_5 , V_2 ,
strcmp ( V_2 -> V_56 , L_49 ) == 0 ) ;
}
static int T_3 F_223 ( struct V_181 * V_182 ,
unsigned long V_183 , void * V_184 )
{
long V_5 = ( long ) V_184 ;
struct V_6 * V_7 = F_81 ( V_1 -> V_71 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
struct V_1 * V_2 ;
int V_47 = V_185 ;
F_8 ( L_50 ) ;
switch ( V_183 ) {
case V_186 :
case V_187 :
F_222 ( V_5 ) ;
F_224 ( V_5 ) ;
break;
case V_188 :
case V_189 :
F_141 ( V_48 , - 1 ) ;
break;
case V_190 :
if ( F_225 ( V_5 ) )
F_141 ( V_48 , V_5 ) ;
else
V_47 = V_191 ;
break;
case V_192 :
case V_193 :
F_90 (rsp)
F_138 ( V_2 ) ;
F_45 ( V_5 ) ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
F_90 (rsp)
F_140 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_8 ( L_51 ) ;
return V_47 ;
}
static int T_2 F_226 ( void )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
struct V_1 * V_2 ;
struct V_32 * V_198 ;
F_90 (rsp) {
V_198 = F_227 ( F_121 , V_2 , V_2 -> V_56 ) ;
F_228 ( F_229 ( V_198 ) ) ;
V_48 = F_20 ( V_2 ) ;
F_71 ( & V_48 -> V_62 , V_43 ) ;
V_2 -> V_199 = V_198 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_230 ( V_2 ) ;
}
return 0 ;
}
void F_231 ( void )
{
F_232 ( F_187 () != 1 ) ;
F_232 ( F_233 () > 0 ) ;
V_200 = 1 ;
}
static void T_2 F_234 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = V_201 - 1 ; V_19 > 0 ; V_19 -- )
V_2 -> V_202 [ V_19 ] = V_203 ;
V_2 -> V_202 [ 0 ] = V_204 ;
}
static void T_2 F_234 ( struct V_1 * V_2 )
{
int V_205 ;
int V_206 ;
int V_19 ;
V_206 = V_207 ;
for ( V_19 = V_201 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_205 = V_2 -> V_208 [ V_19 ] ;
V_2 -> V_202 [ V_19 ] = ( V_206 + V_205 - 1 ) / V_205 ;
V_206 = V_205 ;
}
}
static void T_2 F_235 ( struct V_1 * V_2 ,
struct V_6 T_4 * V_71 )
{
static char * V_209 [] = { L_52 ,
L_53 ,
L_54 ,
L_55 } ;
static char * V_210 [] = { L_56 ,
L_57 ,
L_58 ,
L_59 } ;
int V_211 = 1 ;
int V_19 ;
int V_73 ;
struct V_24 * V_48 ;
F_236 ( V_212 > F_237 ( V_209 ) ) ;
if ( V_201 > V_213 )
F_238 ( L_60 ) ;
for ( V_19 = 0 ; V_19 < V_201 ; V_19 ++ )
V_2 -> V_208 [ V_19 ] = V_214 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_201 ; V_19 ++ )
V_2 -> V_82 [ V_19 ] = V_2 -> V_82 [ V_19 - 1 ] + V_2 -> V_208 [ V_19 - 1 ] ;
F_234 ( V_2 ) ;
for ( V_19 = V_201 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_211 *= V_2 -> V_202 [ V_19 ] ;
V_48 = V_2 -> V_82 [ V_19 ] ;
for ( V_73 = 0 ; V_73 < V_2 -> V_208 [ V_19 ] ; V_73 ++ , V_48 ++ ) {
F_239 ( & V_48 -> V_62 ) ;
F_240 ( & V_48 -> V_62 ,
& V_215 [ V_19 ] , V_209 [ V_19 ] ) ;
F_239 ( & V_48 -> V_131 ) ;
F_240 ( & V_48 -> V_131 ,
& V_216 [ V_19 ] , V_210 [ V_19 ] ) ;
V_48 -> V_4 = V_2 -> V_4 ;
V_48 -> V_3 = V_2 -> V_3 ;
V_48 -> V_63 = 0 ;
V_48 -> V_51 = 0 ;
V_48 -> V_65 = V_73 * V_211 ;
V_48 -> V_64 = ( V_73 + 1 ) * V_211 - 1 ;
if ( V_48 -> V_64 >= V_217 )
V_48 -> V_64 = V_217 - 1 ;
if ( V_19 == 0 ) {
V_48 -> V_218 = 0 ;
V_48 -> V_50 = 0 ;
V_48 -> V_103 = NULL ;
} else {
V_48 -> V_218 = V_73 % V_2 -> V_202 [ V_19 - 1 ] ;
V_48 -> V_50 = 1UL << V_48 -> V_218 ;
V_48 -> V_103 = V_2 -> V_82 [ V_19 - 1 ] +
V_73 / V_2 -> V_202 [ V_19 - 1 ] ;
}
V_48 -> V_82 = V_19 ;
F_241 ( & V_48 -> V_219 ) ;
}
}
V_2 -> V_71 = V_71 ;
F_242 ( & V_2 -> V_94 ) ;
V_48 = V_2 -> V_82 [ V_201 - 1 ] ;
F_80 (i) {
while ( V_19 > V_48 -> V_64 )
V_48 ++ ;
F_81 ( V_2 -> V_71 , V_19 ) -> V_49 = V_48 ;
F_218 ( V_19 , V_2 ) ;
}
F_243 ( & V_2 -> V_220 , & V_221 ) ;
}
static void T_2 F_244 ( void )
{
int V_19 ;
int V_73 ;
int V_222 = V_207 ;
int V_223 [ V_212 + 1 ] ;
if ( V_204 == V_224 &&
V_207 == V_217 )
return;
V_223 [ 0 ] = 1 ;
V_223 [ 1 ] = V_204 ;
for ( V_19 = 2 ; V_19 <= V_212 ; V_19 ++ )
V_223 [ V_19 ] = V_223 [ V_19 - 1 ] * V_203 ;
if ( V_204 < V_224 ||
V_204 > sizeof( unsigned long ) * 8 ||
V_222 > V_223 [ V_212 ] ) {
F_232 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_212 ; V_19 ++ )
if ( V_222 <= V_223 [ V_19 ] ) {
for ( V_73 = 0 ; V_73 <= V_19 ; V_73 ++ )
V_214 [ V_73 ] =
F_245 ( V_222 , V_223 [ V_19 - V_73 ] ) ;
V_201 = V_19 ;
for ( V_73 = V_19 + 1 ; V_73 <= V_212 ; V_73 ++ )
V_214 [ V_73 ] = 0 ;
break;
}
V_83 = 0 ;
for ( V_19 = 0 ; V_19 <= V_212 ; V_19 ++ )
V_83 += V_214 [ V_19 ] ;
V_83 -= V_222 ;
}
void T_2 F_246 ( void )
{
int V_5 ;
F_247 () ;
F_244 () ;
F_235 ( & V_11 , & V_8 ) ;
F_235 ( & V_12 , & V_10 ) ;
F_248 () ;
F_249 () ;
F_250 ( V_137 , F_168 ) ;
F_251 ( F_223 , 0 ) ;
F_252 (cpu)
F_223 ( NULL , V_186 , ( void * ) ( long ) V_5 ) ;
}
