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
if ( F_19 ( V_2 ) )
return 1 ;
if ( ! V_7 -> V_17 [ V_20 ] )
return 0 ;
if ( * V_7 -> V_17 [ V_21 ] )
return 1 ;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ )
if ( V_7 -> V_17 [ V_19 - 1 ] != V_7 -> V_17 [ V_19 ] &&
F_20 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_23 [ V_19 ] ) )
return 1 ;
return 0 ;
}
static struct V_24 * F_21 ( struct V_1 * V_2 )
{
return & V_2 -> V_25 [ 0 ] ;
}
static void F_22 ( struct V_26 * V_27 , long long V_28 ,
bool V_29 )
{
F_23 ( L_6 , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_24 ( V_31 ) ) {
struct V_32 * V_33 = F_25 ( F_26 () ) ;
F_23 ( L_7 , V_28 , 0 ) ;
F_27 ( V_34 ) ;
F_28 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
F_29 ( F_26 () ) ;
F_30 () ;
F_31 ( & V_27 -> V_37 ) ;
F_32 () ;
F_33 ( F_34 ( & V_27 -> V_37 ) & 0x1 ) ;
F_35 ( ! F_36 ( & V_38 ) ,
L_9 ) ;
F_35 ( ! F_36 ( & V_39 ) ,
L_10 ) ;
F_35 ( ! F_36 ( & V_40 ) ,
L_11 ) ;
}
static void F_37 ( bool V_29 )
{
long long V_28 ;
struct V_26 * V_27 ;
V_27 = & F_38 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_33 ( ( V_28 & V_41 ) == 0 ) ;
if ( ( V_28 & V_41 ) == V_42 )
V_27 -> V_30 = 0 ;
else
V_27 -> V_30 -= V_42 ;
F_22 ( V_27 , V_28 , V_29 ) ;
}
void F_39 ( void )
{
unsigned long V_43 ;
F_40 ( V_43 ) ;
F_37 ( false ) ;
F_41 ( V_43 ) ;
}
void F_42 ( void )
{
F_37 ( 1 ) ;
}
void F_43 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
F_40 ( V_43 ) ;
V_27 = & F_38 ( V_26 ) ;
F_33 ( ! ( V_27 -> V_30 & V_44 ) ) ;
V_27 -> V_30 = 1 ;
F_41 ( V_43 ) ;
}
void F_44 ( void )
{
unsigned long V_43 ;
long long V_28 ;
struct V_26 * V_27 ;
F_40 ( V_43 ) ;
V_27 = & F_38 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 -- ;
F_33 ( V_27 -> V_30 < 0 ) ;
if ( V_27 -> V_30 )
F_23 ( L_12 , V_28 , V_27 -> V_30 ) ;
else
F_22 ( V_27 , V_28 , true ) ;
F_41 ( V_43 ) ;
}
static void F_45 ( struct V_26 * V_27 , long long V_28 ,
int V_29 )
{
F_30 () ;
F_31 ( & V_27 -> V_37 ) ;
F_32 () ;
F_33 ( ! ( F_34 ( & V_27 -> V_37 ) & 0x1 ) ) ;
F_46 ( F_26 () ) ;
F_23 ( L_13 , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_24 ( V_31 ) ) {
struct V_32 * V_33 = F_25 ( F_26 () ) ;
F_23 ( L_14 ,
V_28 , V_27 -> V_30 ) ;
F_27 ( V_34 ) ;
F_28 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
}
static void F_47 ( bool V_29 )
{
struct V_26 * V_27 ;
long long V_28 ;
V_27 = & F_38 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_33 ( V_28 < 0 ) ;
if ( V_28 & V_41 )
V_27 -> V_30 += V_42 ;
else
V_27 -> V_30 = V_45 ;
F_45 ( V_27 , V_28 , V_29 ) ;
}
void F_48 ( void )
{
unsigned long V_43 ;
F_40 ( V_43 ) ;
F_47 ( false ) ;
F_41 ( V_43 ) ;
}
void F_49 ( void )
{
F_47 ( 1 ) ;
}
void F_50 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
F_40 ( V_43 ) ;
V_27 = & F_38 ( V_26 ) ;
F_33 ( V_27 -> V_30 & V_41 ) ;
V_27 -> V_30 += V_45 ;
F_41 ( V_43 ) ;
}
void F_51 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
long long V_28 ;
F_40 ( V_43 ) ;
V_27 = & F_38 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 ++ ;
F_33 ( V_27 -> V_30 == 0 ) ;
if ( V_28 )
F_23 ( L_15 , V_28 , V_27 -> V_30 ) ;
else
F_45 ( V_27 , V_28 , true ) ;
F_41 ( V_43 ) ;
}
void F_52 ( void )
{
struct V_26 * V_27 = & F_38 ( V_26 ) ;
if ( V_27 -> V_46 == 0 &&
( F_34 ( & V_27 -> V_37 ) & 0x1 ) )
return;
V_27 -> V_46 ++ ;
F_30 () ;
F_31 ( & V_27 -> V_37 ) ;
F_32 () ;
F_33 ( ! ( F_34 ( & V_27 -> V_37 ) & 0x1 ) ) ;
}
void F_53 ( void )
{
struct V_26 * V_27 = & F_38 ( V_26 ) ;
if ( V_27 -> V_46 == 0 ||
-- V_27 -> V_46 != 0 )
return;
F_30 () ;
F_31 ( & V_27 -> V_37 ) ;
F_32 () ;
F_33 ( F_34 ( & V_27 -> V_37 ) & 0x1 ) ;
}
int F_54 ( void )
{
int V_47 ;
F_55 () ;
V_47 = ( F_34 ( & F_38 ( V_26 ) . V_37 ) & 0x1 ) == 0 ;
F_56 () ;
return V_47 ;
}
bool F_57 ( void )
{
struct V_6 * V_7 ;
struct V_24 * V_48 ;
bool V_47 ;
if ( F_58 () )
return 1 ;
F_55 () ;
V_7 = & F_38 ( V_8 ) ;
V_48 = V_7 -> V_49 ;
V_47 = ( V_7 -> V_50 & V_48 -> V_51 ) ||
! V_52 ;
F_56 () ;
return V_47 ;
}
static int F_59 ( void )
{
return F_38 ( V_26 ) . V_30 <= 1 ;
}
static int F_60 ( struct V_6 * V_7 )
{
V_7 -> V_53 = F_61 ( 0 , & V_7 -> V_37 -> V_37 ) ;
return ( V_7 -> V_53 & 0x1 ) == 0 ;
}
static int F_62 ( struct V_6 * V_7 )
{
unsigned int V_54 ;
unsigned int V_55 ;
V_54 = ( unsigned int ) F_61 ( 0 , & V_7 -> V_37 -> V_37 ) ;
V_55 = ( unsigned int ) V_7 -> V_53 ;
if ( ( V_54 & 0x1 ) == 0 || F_63 ( V_54 , V_55 + 2 ) ) {
F_64 ( V_7 -> V_2 -> V_56 , V_7 -> V_4 , V_7 -> V_5 , L_16 ) ;
V_7 -> V_57 ++ ;
return 1 ;
}
if ( F_65 ( V_7 -> V_2 -> V_58 + 2 , V_59 ) )
return 0 ;
F_66 () ;
if ( F_67 ( V_7 -> V_5 ) ) {
F_64 ( V_7 -> V_2 -> V_56 , V_7 -> V_4 , V_7 -> V_5 , L_17 ) ;
V_7 -> V_60 ++ ;
return 1 ;
}
F_68 ( V_7 -> V_5 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
V_2 -> V_58 = V_59 ;
V_2 -> V_61 = V_59 + F_70 () ;
}
static void F_71 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_48 ;
F_72 (rsp, rnp) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( V_48 -> V_63 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_64 - V_48 -> V_65 ; V_5 ++ )
if ( V_48 -> V_63 & ( 1UL << V_5 ) )
F_74 ( V_48 -> V_65 + V_5 ) ;
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
int V_5 ;
long V_66 ;
unsigned long V_43 ;
int V_67 = 0 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
long V_68 = 0 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_66 = V_59 - V_2 -> V_61 ;
if ( V_66 < V_69 || ! F_1 ( V_2 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_2 -> V_61 = V_59 + 3 * F_70 () + 3 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
F_77 ( V_70 L_18 ,
V_2 -> V_56 ) ;
F_78 () ;
F_72 (rsp, rnp) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_67 += F_79 ( V_48 ) ;
if ( V_48 -> V_63 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_64 - V_48 -> V_65 ; V_5 ++ )
if ( V_48 -> V_63 & ( 1UL << V_5 ) ) {
F_80 ( V_2 ,
V_48 -> V_65 + V_5 ) ;
V_67 ++ ;
}
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
V_48 = F_21 ( V_2 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_67 += F_79 ( V_48 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
F_81 () ;
F_82 (cpu)
V_68 += F_83 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_84 ( L_19 ,
F_26 () , ( long ) ( V_59 - V_2 -> V_58 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_68 ) ;
if ( V_67 == 0 )
F_77 ( V_70 L_20 ) ;
else if ( ! F_85 () )
F_71 ( V_2 ) ;
F_86 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
long V_68 = 0 ;
F_77 ( V_70 L_21 , V_2 -> V_56 ) ;
F_78 () ;
F_80 ( V_2 , F_26 () ) ;
F_81 () ;
F_82 (cpu)
V_68 += F_83 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_84 ( L_22 ,
V_59 - V_2 -> V_58 , V_2 -> V_4 , V_2 -> V_3 , V_68 ) ;
if ( ! F_85 () )
F_88 () ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( F_65 ( V_59 , V_2 -> V_61 ) )
V_2 -> V_61 = V_59 +
3 * F_70 () + 3 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
F_89 () ;
}
static void F_90 ( struct V_1 * V_2 , struct V_6 * V_7 )
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
( F_2 ( V_48 -> V_63 ) & V_7 -> V_50 ) && F_65 ( V_73 , V_74 ) ) {
F_87 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_65 ( V_73 , V_74 + V_69 ) ) {
F_76 ( V_2 ) ;
}
}
void F_91 ( void )
{
struct V_1 * V_2 ;
F_92 (rsp)
V_2 -> V_61 = V_59 + V_76 / 2 ;
}
static void F_93 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_48 -> V_4 ) {
V_7 -> V_4 = V_48 -> V_4 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_23 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_77 = ! ! ( V_48 -> V_63 & V_7 -> V_50 ) ;
F_94 ( V_7 ) ;
}
}
static void F_95 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
F_40 ( V_43 ) ;
V_48 = V_7 -> V_49 ;
if ( V_7 -> V_4 == F_2 ( V_48 -> V_4 ) ||
! F_96 ( & V_48 -> V_62 ) ) {
F_41 ( V_43 ) ;
return;
}
F_93 ( V_2 , V_48 , V_7 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
static int
F_97 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
int V_47 = 0 ;
F_40 ( V_43 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_95 ( V_2 , V_7 ) ;
V_47 = 1 ;
}
F_41 ( V_43 ) ;
return V_47 ;
}
static void F_98 ( struct V_6 * V_7 )
{
int V_19 ;
if ( F_99 ( V_7 ) )
return;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
}
static unsigned long F_100 ( struct V_1 * V_2 ,
struct V_24 * V_48 )
{
if ( F_21 ( V_2 ) == V_48 && V_48 -> V_4 == V_48 -> V_3 )
return V_48 -> V_3 + 1 ;
return V_48 -> V_3 + 2 ;
}
static void F_101 ( struct V_24 * V_48 , struct V_6 * V_7 ,
unsigned long V_79 , char * V_80 )
{
F_102 ( V_7 -> V_2 -> V_56 , V_48 -> V_4 ,
V_48 -> V_3 , V_79 , V_48 -> V_81 ,
V_48 -> V_65 , V_48 -> V_64 , V_80 ) ;
}
static unsigned long T_1
F_103 ( struct V_24 * V_48 , struct V_6 * V_7 )
{
unsigned long V_79 ;
int V_19 ;
struct V_24 * V_82 = F_21 ( V_7 -> V_2 ) ;
V_79 = F_100 ( V_7 -> V_2 , V_48 ) ;
F_101 ( V_48 , V_7 , V_79 , L_24 ) ;
if ( V_48 -> V_83 [ V_79 & 0x1 ] ) {
F_101 ( V_48 , V_7 , V_79 , L_25 ) ;
return V_79 ;
}
if ( V_48 -> V_4 != V_48 -> V_3 ||
F_2 ( V_48 -> V_4 ) != F_2 ( V_48 -> V_3 ) ) {
V_48 -> V_83 [ V_79 & 0x1 ] ++ ;
F_101 ( V_48 , V_7 , V_79 , L_26 ) ;
return V_79 ;
}
if ( V_48 != V_82 )
F_104 ( & V_82 -> V_62 ) ;
V_79 = F_100 ( V_7 -> V_2 , V_82 ) ;
for ( V_19 = V_18 ; V_19 < V_20 ; V_19 ++ )
if ( F_20 ( V_79 , V_7 -> V_23 [ V_19 ] ) )
V_7 -> V_23 [ V_19 ] = V_79 ;
if ( V_82 -> V_83 [ V_79 & 0x1 ] ) {
F_101 ( V_48 , V_7 , V_79 , L_27 ) ;
goto V_84;
}
V_82 -> V_83 [ V_79 & 0x1 ] ++ ;
if ( V_82 -> V_4 != V_82 -> V_3 ) {
F_101 ( V_48 , V_7 , V_79 , L_28 ) ;
} else {
F_101 ( V_48 , V_7 , V_79 , L_29 ) ;
F_105 ( V_7 -> V_2 , V_82 , V_7 ) ;
}
V_84:
if ( V_48 != V_82 )
F_106 ( & V_82 -> V_62 ) ;
return V_79 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_24 * V_48 )
{
int V_79 = V_48 -> V_3 ;
int V_85 ;
struct V_6 * V_7 = F_108 ( V_2 -> V_71 ) ;
F_109 ( V_2 , V_48 ) ;
V_48 -> V_83 [ V_79 & 0x1 ] = 0 ;
V_85 = V_48 -> V_83 [ ( V_79 + 1 ) & 0x1 ] ;
F_101 ( V_48 , V_7 , V_79 , V_85 ? L_30 : L_31 ) ;
return V_85 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
unsigned long V_79 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_79 = F_100 ( V_2 , V_48 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_65 ( V_7 -> V_23 [ V_19 ] , V_79 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_79 ;
}
F_103 ( V_48 , V_7 ) ;
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_32 ) ;
else
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_33 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
int V_19 , V_73 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_20 ( V_48 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
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
F_110 ( V_2 , V_48 , V_7 ) ;
}
static void
F_112 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_48 -> V_3 ) {
F_110 ( V_2 , V_48 , V_7 ) ;
} else {
F_111 ( V_2 , V_48 , V_7 ) ;
V_7 -> V_3 = V_48 -> V_3 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_34 ) ;
if ( F_20 ( V_7 -> V_4 , V_7 -> V_3 ) ) {
V_7 -> V_4 = V_7 -> V_3 ;
V_7 -> V_9 = 0 ;
}
if ( ( V_48 -> V_63 & V_7 -> V_50 ) == 0 )
V_7 -> V_77 = 0 ;
}
}
static void
F_113 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
F_40 ( V_43 ) ;
V_48 = V_7 -> V_49 ;
if ( V_7 -> V_3 == F_2 ( V_48 -> V_3 ) ||
! F_96 ( & V_48 -> V_62 ) ) {
F_41 ( V_43 ) ;
return;
}
F_112 ( V_2 , V_48 , V_7 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
static void
F_114 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
F_112 ( V_2 , V_48 , V_7 ) ;
F_93 ( V_2 , V_48 , V_7 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_116 ( & V_48 -> V_62 ) ;
V_2 -> V_86 = 0 ;
if ( F_1 ( V_2 ) ) {
F_117 ( & V_48 -> V_62 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_56 , V_2 -> V_4 , L_35 ) ;
F_69 ( V_2 ) ;
F_117 ( & V_48 -> V_62 ) ;
F_118 ( & V_2 -> V_87 ) ;
F_119 (rsp, rnp) {
F_116 ( & V_48 -> V_62 ) ;
V_7 = F_108 ( V_2 -> V_71 ) ;
F_120 ( V_48 ) ;
V_48 -> V_63 = V_48 -> V_51 ;
F_2 ( V_48 -> V_4 ) = V_2 -> V_4 ;
F_33 ( V_48 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_3 ;
if ( V_48 == V_7 -> V_49 )
F_114 ( V_2 , V_48 , V_7 ) ;
F_121 ( V_48 ) ;
F_122 ( V_2 -> V_56 , V_48 -> V_4 ,
V_48 -> V_81 , V_48 -> V_65 ,
V_48 -> V_64 , V_48 -> V_63 ) ;
F_117 ( & V_48 -> V_62 ) ;
#ifdef F_123
if ( ( F_124 () % ( V_88 + 1 ) ) == 0 &&
V_89 == V_90 )
F_125 ( 200 ) ;
#endif
F_126 () ;
}
F_127 ( & V_2 -> V_87 ) ;
return 1 ;
}
int F_128 ( struct V_1 * V_2 , int V_91 )
{
int V_92 = V_91 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
V_2 -> V_93 ++ ;
if ( V_92 == V_94 ) {
F_129 ( V_2 , F_60 ) ;
V_92 = V_95 ;
} else {
F_129 ( V_2 , F_62 ) ;
}
if ( F_2 ( V_2 -> V_86 ) & V_96 ) {
F_116 ( & V_48 -> V_62 ) ;
V_2 -> V_86 &= ~ V_96 ;
F_117 ( & V_48 -> V_62 ) ;
}
return V_92 ;
}
static void F_130 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
int V_98 = 0 ;
struct V_6 * V_7 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_116 ( & V_48 -> V_62 ) ;
V_97 = V_59 - V_2 -> V_58 ;
if ( V_97 > V_2 -> V_99 )
V_2 -> V_99 = V_97 ;
F_117 ( & V_48 -> V_62 ) ;
F_119 (rsp, rnp) {
F_116 ( & V_48 -> V_62 ) ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_108 ( V_2 -> V_71 ) ;
if ( V_48 == V_7 -> V_49 )
F_112 ( V_2 , V_48 , V_7 ) ;
V_98 += F_107 ( V_2 , V_48 ) ;
F_117 ( & V_48 -> V_62 ) ;
F_126 () ;
}
V_48 = F_21 ( V_2 ) ;
F_116 ( & V_48 -> V_62 ) ;
F_131 ( V_48 , V_98 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_56 , V_2 -> V_3 , L_36 ) ;
V_2 -> V_92 = V_100 ;
V_7 = F_108 ( V_2 -> V_71 ) ;
F_111 ( V_2 , V_48 , V_7 ) ;
if ( F_18 ( V_2 , V_7 ) )
V_2 -> V_86 = 1 ;
F_117 ( & V_48 -> V_62 ) ;
}
static int T_2 F_132 ( void * V_101 )
{
int V_92 ;
unsigned long V_73 ;
int V_47 ;
struct V_1 * V_2 = V_101 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_133 ( V_2 -> V_102 ,
V_2 -> V_86 &
V_103 ) ;
if ( ( V_2 -> V_86 & V_103 ) &&
F_115 ( V_2 ) )
break;
F_126 () ;
F_134 ( V_31 ) ;
}
V_92 = V_94 ;
V_73 = V_104 ;
if ( V_73 > V_105 ) {
V_73 = V_105 ;
V_104 = V_105 ;
}
for (; ; ) {
V_2 -> V_106 = V_59 + V_73 ;
V_47 = F_135 ( V_2 -> V_102 ,
( V_2 -> V_86 & V_96 ) ||
( ! F_2 ( V_48 -> V_63 ) &&
! F_136 ( V_48 ) ) ,
V_73 ) ;
if ( ! F_2 ( V_48 -> V_63 ) &&
! F_136 ( V_48 ) )
break;
if ( V_47 == 0 || ( V_2 -> V_86 & V_96 ) ) {
V_92 = F_128 ( V_2 , V_92 ) ;
F_126 () ;
} else {
F_126 () ;
F_134 ( V_31 ) ;
}
V_73 = V_107 ;
if ( V_73 > V_105 ) {
V_73 = V_105 ;
V_107 = V_105 ;
} else if ( V_73 < 1 ) {
V_73 = 1 ;
V_107 = 1 ;
}
}
F_130 ( V_2 ) ;
}
}
static void F_137 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_138 ( V_109 , struct V_1 , V_110 ) ;
F_139 ( & V_2 -> V_102 ) ;
}
static void
F_105 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_111 || ! F_18 ( V_2 , V_7 ) ) {
return;
}
V_2 -> V_86 = V_103 ;
F_140 ( & V_2 -> V_110 ) ;
}
static void
F_141 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_108 ( V_2 -> V_71 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_111 ( V_2 , V_48 , V_7 ) ;
F_105 ( V_2 , V_48 , V_7 ) ;
}
static void F_142 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void
F_143 ( unsigned long V_112 , struct V_1 * V_2 ,
struct V_24 * V_48 , unsigned long V_43 )
__releases( V_48 -> V_62 )
{
struct V_24 * V_113 ;
for (; ; ) {
if ( ! ( V_48 -> V_63 & V_112 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_48 -> V_63 &= ~ V_112 ;
F_144 ( V_2 -> V_56 , V_48 -> V_4 ,
V_112 , V_48 -> V_63 , V_48 -> V_81 ,
V_48 -> V_65 , V_48 -> V_64 ,
! ! V_48 -> V_114 ) ;
if ( V_48 -> V_63 != 0 || F_136 ( V_48 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_112 = V_48 -> V_50 ;
if ( V_48 -> V_115 == NULL ) {
break;
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
V_113 = V_48 ;
V_48 = V_48 -> V_115 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_33 ( V_113 -> V_63 ) ;
}
F_142 ( V_2 , V_43 ) ;
}
static void
F_145 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
unsigned long V_112 ;
struct V_24 * V_48 ;
V_48 = V_7 -> V_49 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_48 -> V_4 ||
V_48 -> V_3 == V_48 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_112 = V_7 -> V_50 ;
if ( ( V_48 -> V_63 & V_112 ) == 0 ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
} else {
V_7 -> V_77 = 0 ;
F_110 ( V_2 , V_48 , V_7 ) ;
F_143 ( V_112 , V_2 , V_48 , V_43 ) ;
}
}
static void
F_146 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_97 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_77 )
return;
if ( ! V_7 -> V_9 )
return;
F_145 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_147 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( F_148 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_116 += V_7 -> V_116 ;
V_2 -> V_72 += V_7 -> V_72 ;
V_7 -> V_117 += V_7 -> V_72 ;
V_7 -> V_116 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_118 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_118 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_119 = V_7 -> V_16 ;
V_2 -> V_119 = V_7 -> V_17 [ V_18 ] ;
}
F_98 ( V_7 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_6 * V_7 = F_150 ( V_2 -> V_71 ) ;
if ( F_151 ( V_2 , V_7 ) )
return;
V_7 -> V_116 += V_2 -> V_116 ;
V_7 -> V_72 += V_2 -> V_72 ;
V_7 -> V_120 += V_2 -> V_72 ;
if ( V_2 -> V_116 != V_2 -> V_72 )
F_152 () ;
V_2 -> V_116 = 0 ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_121 != NULL ) {
* V_2 -> V_119 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_121 ;
for ( V_19 = V_78 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_119 ;
V_2 -> V_121 = NULL ;
V_2 -> V_119 = & V_2 -> V_121 ;
}
if ( V_2 -> V_122 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_122 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_118 ;
V_2 -> V_122 = NULL ;
V_2 -> V_118 = & V_2 -> V_122 ;
}
}
static void F_153 ( struct V_1 * V_2 )
{
F_154 (unsigned long mask) ;
F_154 ( struct V_6 * V_7 = F_108 ( V_2 -> V_71 ) ) ;
F_154 ( struct V_24 * V_48 = V_7 -> V_49 ) ;
F_154 ( V_112 = V_7 -> V_50 ) ;
F_5 ( V_2 -> V_56 ,
V_48 -> V_4 + 1 - ! ! ( V_48 -> V_63 & V_112 ) ,
L_37 ) ;
}
static void F_155 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned long V_112 ;
int V_123 = 0 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
F_156 ( V_48 , - 1 ) ;
F_118 ( & V_2 -> V_87 ) ;
F_73 ( & V_2 -> V_124 , V_43 ) ;
F_147 ( V_5 , V_2 , V_48 , V_7 ) ;
F_149 ( V_2 ) ;
V_112 = V_7 -> V_50 ;
do {
F_104 ( & V_48 -> V_62 ) ;
V_48 -> V_51 &= ~ V_112 ;
if ( V_48 -> V_51 != 0 ) {
if ( V_48 != V_7 -> V_49 )
F_106 ( & V_48 -> V_62 ) ;
break;
}
if ( V_48 == V_7 -> V_49 )
V_123 = F_157 ( V_2 , V_48 , V_7 ) ;
else
F_106 ( & V_48 -> V_62 ) ;
V_112 = V_48 -> V_50 ;
V_48 = V_48 -> V_115 ;
} while ( V_48 != NULL );
F_106 ( & V_2 -> V_124 ) ;
V_48 = V_7 -> V_49 ;
if ( V_123 & V_125 )
F_158 ( V_48 , V_43 ) ;
else
F_75 ( & V_48 -> V_62 , V_43 ) ;
if ( V_123 & V_126 )
F_159 ( V_2 , V_48 , true ) ;
F_28 ( V_7 -> V_72 != 0 || V_7 -> V_16 != NULL ,
L_38 ,
V_5 , V_7 -> V_72 , V_7 -> V_16 ) ;
F_98 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_127 ( & V_2 -> V_87 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
}
static void F_155 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_160 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_127 * V_128 , * V_129 , * * V_130 ;
long V_131 , V_132 , V_133 ;
int V_19 ;
if ( ! F_17 ( V_7 ) ) {
F_161 ( V_2 -> V_56 , V_7 -> V_116 , V_7 -> V_72 , 0 ) ;
F_162 ( V_2 -> V_56 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_163 () , F_24 ( V_31 ) ,
F_164 () ) ;
return;
}
F_40 ( V_43 ) ;
F_33 ( F_67 ( F_26 () ) ) ;
V_131 = V_7 -> V_134 ;
F_161 ( V_2 -> V_56 , V_7 -> V_116 , V_7 -> V_72 , V_131 ) ;
V_129 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_130 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_78 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_41 ( V_43 ) ;
V_132 = V_133 = 0 ;
while ( V_129 ) {
V_128 = V_129 -> V_128 ;
F_165 ( V_128 ) ;
F_166 ( V_129 ) ;
if ( F_167 ( V_2 -> V_56 , V_129 ) )
V_133 ++ ;
V_129 = V_128 ;
if ( ++ V_132 >= V_131 &&
( F_163 () ||
( ! F_24 ( V_31 ) && ! F_164 () ) ) )
break;
}
F_40 ( V_43 ) ;
F_162 ( V_2 -> V_56 , V_132 , ! ! V_129 , F_163 () ,
F_24 ( V_31 ) ,
F_164 () ) ;
if ( V_129 != NULL ) {
* V_130 = V_7 -> V_16 ;
V_7 -> V_16 = V_129 ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_130 ;
else
break;
}
F_168 () ;
V_7 -> V_116 -= V_133 ;
F_2 ( V_7 -> V_72 ) -= V_132 ;
V_7 -> V_135 += V_132 ;
if ( V_7 -> V_134 == V_136 && V_7 -> V_72 <= V_137 )
V_7 -> V_134 = V_134 ;
if ( V_7 -> V_72 == 0 && V_7 -> V_138 != 0 ) {
V_7 -> V_138 = 0 ;
V_7 -> V_139 = V_2 -> V_93 ;
} else if ( V_7 -> V_72 < V_7 -> V_138 - V_140 )
V_7 -> V_138 = V_7 -> V_72 ;
F_33 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_72 == 0 ) ) ;
F_41 ( V_43 ) ;
if ( F_17 ( V_7 ) )
F_169 () ;
}
void F_170 ( int V_5 , int V_29 )
{
F_8 ( L_39 ) ;
F_171 () ;
if ( V_29 || F_59 () ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_172 () ) {
F_6 ( V_5 ) ;
}
F_173 ( V_5 ) ;
if ( F_174 ( V_5 ) )
F_169 () ;
F_8 ( L_40 ) ;
}
static void F_129 ( struct V_1 * V_2 , int (* F_175)( struct V_6 * ) )
{
unsigned long V_141 ;
int V_5 ;
unsigned long V_43 ;
unsigned long V_112 ;
struct V_24 * V_48 ;
F_72 (rsp, rnp) {
F_126 () ;
V_112 = 0 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( ! F_1 ( V_2 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
if ( V_48 -> V_63 == 0 ) {
F_176 ( V_48 , V_43 ) ;
continue;
}
V_5 = V_48 -> V_65 ;
V_141 = 1 ;
for (; V_5 <= V_48 -> V_64 ; V_5 ++ , V_141 <<= 1 ) {
if ( ( V_48 -> V_63 & V_141 ) != 0 &&
F_175 ( F_83 ( V_2 -> V_71 , V_5 ) ) )
V_112 |= V_141 ;
}
if ( V_112 != 0 ) {
F_143 ( V_112 , V_2 , V_48 , V_43 ) ;
continue;
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
V_48 = F_21 ( V_2 ) ;
if ( V_48 -> V_63 == 0 ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_176 ( V_48 , V_43 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
bool V_47 ;
struct V_24 * V_48 ;
struct V_24 * V_142 = NULL ;
V_48 = F_83 ( V_2 -> V_71 , F_177 () ) -> V_49 ;
for (; V_48 != NULL ; V_48 = V_48 -> V_115 ) {
V_47 = ( F_2 ( V_2 -> V_86 ) & V_96 ) ||
! F_96 ( & V_48 -> V_143 ) ;
if ( V_142 != NULL )
F_106 ( & V_142 -> V_143 ) ;
if ( V_47 ) {
V_2 -> V_144 ++ ;
return;
}
V_142 = V_48 ;
}
F_73 ( & V_142 -> V_62 , V_43 ) ;
F_106 ( & V_142 -> V_143 ) ;
if ( F_2 ( V_2 -> V_86 ) & V_96 ) {
V_2 -> V_144 ++ ;
F_75 ( & V_142 -> V_62 , V_43 ) ;
return;
}
V_2 -> V_86 |= V_96 ;
F_75 ( & V_142 -> V_62 , V_43 ) ;
F_139 ( & V_2 -> V_102 ) ;
}
static void
F_178 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_150 ( V_2 -> V_71 ) ;
F_33 ( V_7 -> V_145 == 0 ) ;
F_113 ( V_2 , V_7 ) ;
F_146 ( V_2 , V_7 ) ;
F_40 ( V_43 ) ;
if ( F_18 ( V_2 , V_7 ) ) {
F_104 ( & F_21 ( V_2 ) -> V_62 ) ;
F_141 ( V_2 ) ;
F_75 ( & F_21 ( V_2 ) -> V_62 , V_43 ) ;
} else {
F_41 ( V_43 ) ;
}
if ( F_17 ( V_7 ) )
F_179 ( V_2 , V_7 ) ;
}
static void F_180 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
if ( F_67 ( F_26 () ) )
return;
F_8 ( L_41 ) ;
F_92 (rsp)
F_178 ( V_2 ) ;
F_8 ( L_42 ) ;
}
static void F_179 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_181 ( ! F_2 ( V_52 ) ) )
return;
if ( F_182 ( ! V_2 -> V_148 ) ) {
F_160 ( V_2 , V_7 ) ;
return;
}
F_183 () ;
}
static void F_169 ( void )
{
if ( F_184 ( F_26 () ) )
F_185 ( V_149 ) ;
}
static void F_186 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_127 * V_150 , unsigned long V_43 )
{
if ( F_54 () && F_184 ( F_26 () ) )
F_169 () ;
if ( F_187 ( V_43 ) || F_67 ( F_26 () ) )
return;
if ( F_181 ( V_7 -> V_72 > V_7 -> V_138 + V_140 ) ) {
F_113 ( V_2 , V_7 ) ;
F_97 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_24 * V_82 = F_21 ( V_2 ) ;
F_104 ( & V_82 -> V_62 ) ;
F_141 ( V_2 ) ;
F_106 ( & V_82 -> V_62 ) ;
} else {
V_7 -> V_134 = V_136 ;
if ( V_2 -> V_93 == V_7 -> V_139 &&
* V_7 -> V_17 [ V_18 ] != V_150 )
F_13 ( V_2 ) ;
V_7 -> V_139 = V_2 -> V_93 ;
V_7 -> V_138 = V_7 -> V_72 ;
}
}
}
static void
F_188 ( struct V_127 * V_150 , void (* F_189)( struct V_127 * V_151 ) ,
struct V_1 * V_2 , int V_5 , bool V_152 )
{
unsigned long V_43 ;
struct V_6 * V_7 ;
F_33 ( ( unsigned long ) V_150 & 0x3 ) ;
F_190 ( V_150 ) ;
V_150 -> F_189 = F_189 ;
V_150 -> V_128 = NULL ;
F_40 ( V_43 ) ;
V_7 = F_108 ( V_2 -> V_71 ) ;
if ( F_181 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_153 ;
if ( V_5 != - 1 )
V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
V_153 = ! F_191 ( V_7 , V_150 , V_152 ) ;
F_33 ( V_153 ) ;
F_41 ( V_43 ) ;
return;
}
F_2 ( V_7 -> V_72 ) ++ ;
if ( V_152 )
V_7 -> V_116 ++ ;
else
F_152 () ;
F_168 () ;
* V_7 -> V_17 [ V_20 ] = V_150 ;
V_7 -> V_17 [ V_20 ] = & V_150 -> V_128 ;
if ( F_192 ( ( unsigned long ) F_189 ) )
F_193 ( V_2 -> V_56 , V_150 , ( unsigned long ) F_189 ,
V_7 -> V_116 , V_7 -> V_72 ) ;
else
F_194 ( V_2 -> V_56 , V_150 , V_7 -> V_116 , V_7 -> V_72 ) ;
F_186 ( V_2 , V_7 , V_150 , V_43 ) ;
F_41 ( V_43 ) ;
}
void F_195 ( struct V_127 * V_150 , void (* F_189)( struct V_127 * V_151 ) )
{
F_188 ( V_150 , F_189 , & V_11 , - 1 , 0 ) ;
}
void F_196 ( struct V_127 * V_150 , void (* F_189)( struct V_127 * V_151 ) )
{
F_188 ( V_150 , F_189 , & V_12 , - 1 , 0 ) ;
}
static inline int F_197 ( void )
{
int V_47 ;
F_198 () ;
F_55 () ;
V_47 = F_199 () <= 1 ;
F_56 () ;
return V_47 ;
}
void F_200 ( void )
{
F_35 ( ! F_36 ( & V_39 ) &&
! F_36 ( & V_38 ) &&
! F_36 ( & V_40 ) ,
L_43 ) ;
if ( F_197 () )
return;
if ( V_154 )
F_201 () ;
else
F_202 ( F_195 ) ;
}
void F_203 ( void )
{
F_35 ( ! F_36 ( & V_39 ) &&
! F_36 ( & V_38 ) &&
! F_36 ( & V_40 ) ,
L_44 ) ;
if ( F_197 () )
return;
if ( V_154 )
F_204 () ;
else
F_202 ( F_196 ) ;
}
static int F_205 ( void * V_155 )
{
F_168 () ;
return 0 ;
}
void F_201 ( void )
{
long V_156 , V_80 , V_55 ;
int V_157 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_65 ( ( V_158 ) F_206 ( & V_2 -> V_159 ) ,
( V_158 ) F_206 ( & V_2 -> V_160 ) +
V_76 / 8 ) ) {
F_200 () ;
F_207 ( & V_2 -> V_161 ) ;
return;
}
V_55 = F_208 ( & V_2 -> V_159 ) ;
V_156 = V_55 ;
F_209 () ;
F_33 ( F_67 ( F_177 () ) ) ;
while ( F_210 ( V_162 ,
F_205 ,
NULL ) == - V_163 ) {
F_211 () ;
F_207 ( & V_2 -> V_164 ) ;
V_80 = F_206 ( & V_2 -> V_160 ) ;
if ( F_65 ( ( V_158 ) V_80 , ( V_158 ) V_156 ) ) {
F_30 () ;
F_207 ( & V_2 -> V_165 ) ;
return;
}
if ( V_157 ++ < 10 ) {
F_125 ( V_157 * F_199 () ) ;
} else {
F_202 ( F_195 ) ;
F_207 ( & V_2 -> V_166 ) ;
return;
}
V_80 = F_206 ( & V_2 -> V_160 ) ;
if ( F_65 ( ( V_158 ) V_80 , ( V_158 ) V_156 ) ) {
F_30 () ;
F_207 ( & V_2 -> V_167 ) ;
return;
}
F_209 () ;
V_55 = F_206 ( & V_2 -> V_159 ) ;
F_168 () ;
}
F_207 ( & V_2 -> V_168 ) ;
do {
F_207 ( & V_2 -> V_169 ) ;
V_80 = F_206 ( & V_2 -> V_160 ) ;
if ( F_65 ( ( V_158 ) V_80 , ( V_158 ) V_55 ) ) {
F_30 () ;
F_207 ( & V_2 -> V_170 ) ;
break;
}
} while ( F_212 ( & V_2 -> V_160 , V_80 , V_55 ) != V_80 );
F_207 ( & V_2 -> V_171 ) ;
F_211 () ;
}
static int F_213 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_48 = V_7 -> V_49 ;
V_7 -> V_172 ++ ;
F_90 ( V_2 , V_7 ) ;
if ( V_52 &&
V_7 -> V_77 && ! V_7 -> V_9 ) {
V_7 -> V_173 ++ ;
} else if ( V_7 -> V_77 && V_7 -> V_9 ) {
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
if ( F_2 ( V_48 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_177 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_178 ++ ;
return 1 ;
}
V_7 -> V_179 ++ ;
return 0 ;
}
static int F_174 ( int V_5 )
{
struct V_1 * V_2 ;
F_92 (rsp)
if ( F_213 ( V_2 , F_83 ( V_2 -> V_71 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_214 ( int V_5 , bool * V_180 )
{
bool V_181 = true ;
bool V_182 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_92 (rsp) {
V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
if ( V_7 -> V_72 != V_7 -> V_116 )
V_181 = false ;
if ( V_7 -> V_16 )
V_182 = true ;
}
if ( V_180 )
* V_180 = V_181 ;
return V_182 ;
}
static void F_215 ( struct V_1 * V_2 , char * V_80 ,
int V_5 , unsigned long V_183 )
{
F_216 ( V_2 -> V_56 , V_80 , V_5 ,
F_34 ( & V_2 -> V_184 ) , V_183 ) ;
}
static void F_217 ( struct V_127 * V_185 )
{
struct V_6 * V_7 = F_138 ( V_185 , struct V_6 , V_186 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_218 ( & V_2 -> V_184 ) ) {
F_215 ( V_2 , L_45 , - 1 , V_2 -> V_187 ) ;
F_219 ( & V_2 -> V_188 ) ;
} else {
F_215 ( V_2 , L_46 , - 1 , V_2 -> V_187 ) ;
}
}
static void F_220 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_150 ( V_2 -> V_71 ) ;
F_215 ( V_2 , L_47 , - 1 , V_2 -> V_187 ) ;
F_31 ( & V_2 -> V_184 ) ;
V_2 -> V_189 ( & V_7 -> V_186 , F_217 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_55 = F_2 ( V_2 -> V_187 ) ;
unsigned long V_190 ;
F_215 ( V_2 , L_48 , - 1 , V_55 ) ;
F_118 ( & V_2 -> V_191 ) ;
F_168 () ;
V_190 = F_2 ( V_2 -> V_187 ) ;
F_215 ( V_2 , L_49 , - 1 , V_190 ) ;
if ( F_65 ( V_190 , ( ( V_55 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_215 ( V_2 , L_50 , - 1 , V_190 ) ;
F_168 () ;
F_127 ( & V_2 -> V_191 ) ;
return;
}
F_2 ( V_2 -> V_187 ) ++ ;
F_33 ( ( V_2 -> V_187 & 0x1 ) != 1 ) ;
F_215 ( V_2 , L_51 , - 1 , V_2 -> V_187 ) ;
F_168 () ;
F_222 ( & V_2 -> V_188 ) ;
F_223 ( & V_2 -> V_184 , 1 ) ;
F_209 () ;
F_82 (cpu) {
if ( ! F_184 ( V_5 ) && ! F_148 ( V_5 ) )
continue;
V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
if ( F_148 ( V_5 ) ) {
F_215 ( V_2 , L_52 , V_5 ,
V_2 -> V_187 ) ;
F_31 ( & V_2 -> V_184 ) ;
F_188 ( & V_7 -> V_186 , F_217 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_72 ) ) {
F_215 ( V_2 , L_53 , V_5 ,
V_2 -> V_187 ) ;
F_224 ( V_5 , F_220 , V_2 , 1 ) ;
} else {
F_215 ( V_2 , L_54 , V_5 ,
V_2 -> V_187 ) ;
}
}
F_211 () ;
if ( F_218 ( & V_2 -> V_184 ) )
F_219 ( & V_2 -> V_188 ) ;
F_168 () ;
F_2 ( V_2 -> V_187 ) ++ ;
F_33 ( ( V_2 -> V_187 & 0x1 ) != 0 ) ;
F_215 ( V_2 , L_55 , - 1 , V_2 -> V_187 ) ;
F_168 () ;
F_225 ( & V_2 -> V_188 ) ;
F_127 ( & V_2 -> V_191 ) ;
}
void F_226 ( void )
{
F_221 ( & V_12 ) ;
}
void F_227 ( void )
{
F_221 ( & V_11 ) ;
}
static void T_3
F_228 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_50 = 1UL << ( V_5 - V_7 -> V_49 -> V_65 ) ;
F_98 ( V_7 ) ;
V_7 -> V_116 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
V_7 -> V_37 = & F_4 ( V_26 , V_5 ) ;
F_33 ( V_7 -> V_37 -> V_30 != V_45 ) ;
F_33 ( F_34 ( & V_7 -> V_37 -> V_37 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_229 ( V_7 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
static void T_4
F_230 ( int V_5 , struct V_1 * V_2 , int V_192 )
{
unsigned long V_43 ;
unsigned long V_112 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_118 ( & V_2 -> V_87 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_145 = 1 ;
V_7 -> V_192 = V_192 ;
V_7 -> V_138 = 0 ;
V_7 -> V_139 = V_2 -> V_93 ;
V_7 -> V_134 = V_134 ;
F_98 ( V_7 ) ;
V_7 -> V_37 -> V_30 = V_45 ;
F_223 ( & V_7 -> V_37 -> V_37 ,
( F_34 ( & V_7 -> V_37 -> V_37 ) & ~ 0x1 ) + 1 ) ;
F_106 ( & V_48 -> V_62 ) ;
V_48 = V_7 -> V_49 ;
V_112 = V_7 -> V_50 ;
do {
F_104 ( & V_48 -> V_62 ) ;
V_48 -> V_51 |= V_112 ;
V_112 = V_48 -> V_50 ;
if ( V_48 == V_7 -> V_49 ) {
V_7 -> V_4 = V_48 -> V_3 ;
V_7 -> V_3 = V_48 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_77 = 0 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_56 ) ;
}
F_106 ( & V_48 -> V_62 ) ;
V_48 = V_48 -> V_115 ;
} while ( V_48 != NULL && ! ( V_48 -> V_51 & V_112 ) );
F_41 ( V_43 ) ;
F_127 ( & V_2 -> V_87 ) ;
}
static void T_4 F_231 ( int V_5 )
{
struct V_1 * V_2 ;
F_92 (rsp)
F_230 ( V_5 , V_2 ,
strcmp ( V_2 -> V_56 , L_57 ) == 0 ) ;
}
static int T_4 F_232 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_196 )
{
long V_5 = ( long ) V_196 ;
struct V_6 * V_7 = F_83 ( V_1 -> V_71 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
struct V_1 * V_2 ;
F_8 ( L_58 ) ;
switch ( V_195 ) {
case V_197 :
case V_198 :
F_231 ( V_5 ) ;
F_233 ( V_5 ) ;
break;
case V_199 :
case V_200 :
F_156 ( V_48 , - 1 ) ;
break;
case V_201 :
F_156 ( V_48 , V_5 ) ;
break;
case V_202 :
case V_203 :
F_92 (rsp)
F_153 ( V_2 ) ;
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
F_92 (rsp)
F_155 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_8 ( L_59 ) ;
return V_208 ;
}
static int T_3 F_234 ( void )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
struct V_1 * V_2 ;
struct V_32 * V_209 ;
F_92 (rsp) {
V_209 = F_235 ( F_132 , V_2 , V_2 -> V_56 ) ;
F_236 ( F_237 ( V_209 ) ) ;
V_48 = F_21 ( V_2 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_2 -> V_111 = V_209 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
F_238 ( V_2 ) ;
}
return 0 ;
}
void F_239 ( void )
{
F_240 ( F_199 () != 1 ) ;
F_240 ( F_241 () > 0 ) ;
V_210 = 1 ;
}
static void T_3 F_242 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = V_211 - 1 ; V_19 > 0 ; V_19 -- )
V_2 -> V_212 [ V_19 ] = V_213 ;
V_2 -> V_212 [ 0 ] = V_214 ;
}
static void T_3 F_242 ( struct V_1 * V_2 )
{
int V_215 ;
int V_216 ;
int V_19 ;
V_216 = V_217 ;
for ( V_19 = V_211 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_215 = V_2 -> V_218 [ V_19 ] ;
V_2 -> V_212 [ V_19 ] = ( V_216 + V_215 - 1 ) / V_215 ;
V_216 = V_215 ;
}
}
static void T_3 F_243 ( struct V_1 * V_2 ,
struct V_6 T_5 * V_71 )
{
static char * V_219 [] = { L_60 ,
L_61 ,
L_62 ,
L_63 } ;
static char * V_220 [] = { L_64 ,
L_65 ,
L_66 ,
L_67 } ;
int V_221 = 1 ;
int V_19 ;
int V_73 ;
struct V_24 * V_48 ;
F_244 ( V_222 > F_245 ( V_219 ) ) ;
if ( V_211 > V_223 )
F_246 ( L_68 ) ;
for ( V_19 = 0 ; V_19 < V_211 ; V_19 ++ )
V_2 -> V_218 [ V_19 ] = V_224 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_211 ; V_19 ++ )
V_2 -> V_81 [ V_19 ] = V_2 -> V_81 [ V_19 - 1 ] + V_2 -> V_218 [ V_19 - 1 ] ;
F_242 ( V_2 ) ;
for ( V_19 = V_211 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_221 *= V_2 -> V_212 [ V_19 ] ;
V_48 = V_2 -> V_81 [ V_19 ] ;
for ( V_73 = 0 ; V_73 < V_2 -> V_218 [ V_19 ] ; V_73 ++ , V_48 ++ ) {
F_247 ( & V_48 -> V_62 ) ;
F_248 ( & V_48 -> V_62 ,
& V_225 [ V_19 ] , V_219 [ V_19 ] ) ;
F_247 ( & V_48 -> V_143 ) ;
F_248 ( & V_48 -> V_143 ,
& V_226 [ V_19 ] , V_220 [ V_19 ] ) ;
V_48 -> V_4 = V_2 -> V_4 ;
V_48 -> V_3 = V_2 -> V_3 ;
V_48 -> V_63 = 0 ;
V_48 -> V_51 = 0 ;
V_48 -> V_65 = V_73 * V_221 ;
V_48 -> V_64 = ( V_73 + 1 ) * V_221 - 1 ;
if ( V_48 -> V_64 >= V_227 )
V_48 -> V_64 = V_227 - 1 ;
if ( V_19 == 0 ) {
V_48 -> V_228 = 0 ;
V_48 -> V_50 = 0 ;
V_48 -> V_115 = NULL ;
} else {
V_48 -> V_228 = V_73 % V_2 -> V_212 [ V_19 - 1 ] ;
V_48 -> V_50 = 1UL << V_48 -> V_228 ;
V_48 -> V_115 = V_2 -> V_81 [ V_19 - 1 ] +
V_73 / V_2 -> V_212 [ V_19 - 1 ] ;
}
V_48 -> V_81 = V_19 ;
F_249 ( & V_48 -> V_229 ) ;
F_250 ( V_48 ) ;
}
}
V_2 -> V_71 = V_71 ;
F_251 ( & V_2 -> V_102 ) ;
F_252 ( & V_2 -> V_110 , F_137 ) ;
V_48 = V_2 -> V_81 [ V_211 - 1 ] ;
F_82 (i) {
while ( V_19 > V_48 -> V_64 )
V_48 ++ ;
F_83 ( V_2 -> V_71 , V_19 ) -> V_49 = V_48 ;
F_228 ( V_19 , V_2 ) ;
}
F_253 ( & V_2 -> V_230 , & V_231 ) ;
}
static void T_3 F_254 ( void )
{
int V_19 ;
int V_73 ;
int V_232 = V_217 ;
int V_233 [ V_222 + 1 ] ;
if ( V_214 == V_234 &&
V_217 == V_227 )
return;
V_233 [ 0 ] = 1 ;
V_233 [ 1 ] = V_214 ;
for ( V_19 = 2 ; V_19 <= V_222 ; V_19 ++ )
V_233 [ V_19 ] = V_233 [ V_19 - 1 ] * V_213 ;
if ( V_214 < V_234 ||
V_214 > sizeof( unsigned long ) * 8 ||
V_232 > V_233 [ V_222 ] ) {
F_240 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_222 ; V_19 ++ )
if ( V_232 <= V_233 [ V_19 ] ) {
for ( V_73 = 0 ; V_73 <= V_19 ; V_73 ++ )
V_224 [ V_73 ] =
F_255 ( V_232 , V_233 [ V_19 - V_73 ] ) ;
V_211 = V_19 ;
for ( V_73 = V_19 + 1 ; V_73 <= V_222 ; V_73 ++ )
V_224 [ V_73 ] = 0 ;
break;
}
V_88 = 0 ;
for ( V_19 = 0 ; V_19 <= V_222 ; V_19 ++ )
V_88 += V_224 [ V_19 ] ;
V_88 -= V_232 ;
}
void T_3 F_256 ( void )
{
int V_5 ;
F_257 () ;
F_254 () ;
F_243 ( & V_11 , & V_8 ) ;
F_243 ( & V_12 , & V_10 ) ;
F_258 () ;
F_259 ( V_149 , F_180 ) ;
F_260 ( F_232 , 0 ) ;
F_261 (cpu)
F_232 ( NULL , V_197 , ( void * ) ( long ) V_5 ) ;
}
