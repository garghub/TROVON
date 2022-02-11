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
F_77 ( L_18 ,
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
V_68 += F_83 ( V_2 -> V_70 , V_5 ) -> V_71 ;
F_84 ( L_19 ,
F_26 () , ( long ) ( V_59 - V_2 -> V_58 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_68 ) ;
if ( V_67 == 0 )
F_77 ( L_20 ) ;
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
F_77 ( L_21 , V_2 -> V_56 ) ;
F_78 () ;
F_80 ( V_2 , F_26 () ) ;
F_81 () ;
F_82 (cpu)
V_68 += F_83 ( V_2 -> V_70 , V_5 ) -> V_71 ;
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
unsigned long V_72 ;
unsigned long V_73 ;
struct V_24 * V_48 ;
if ( V_74 )
return;
V_72 = F_2 ( V_59 ) ;
V_73 = F_2 ( V_2 -> V_61 ) ;
V_48 = V_7 -> V_49 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_48 -> V_63 ) & V_7 -> V_50 ) && F_65 ( V_72 , V_73 ) ) {
F_87 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_65 ( V_72 , V_73 + V_69 ) ) {
F_76 ( V_2 ) ;
}
}
void F_91 ( void )
{
struct V_1 * V_2 ;
F_92 (rsp)
V_2 -> V_61 = V_59 + V_75 / 2 ;
}
static void F_93 ( struct V_6 * V_7 )
{
int V_19 ;
if ( F_94 ( V_7 ) )
return;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_76 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
}
static unsigned long F_95 ( struct V_1 * V_2 ,
struct V_24 * V_48 )
{
if ( F_21 ( V_2 ) == V_48 && V_48 -> V_4 == V_48 -> V_3 )
return V_48 -> V_3 + 1 ;
return V_48 -> V_3 + 2 ;
}
static void F_96 ( struct V_24 * V_48 , struct V_6 * V_7 ,
unsigned long V_77 , char * V_78 )
{
F_97 ( V_7 -> V_2 -> V_56 , V_48 -> V_4 ,
V_48 -> V_3 , V_77 , V_48 -> V_79 ,
V_48 -> V_65 , V_48 -> V_64 , V_78 ) ;
}
static unsigned long T_1
F_98 ( struct V_24 * V_48 , struct V_6 * V_7 )
{
unsigned long V_77 ;
int V_19 ;
struct V_24 * V_80 = F_21 ( V_7 -> V_2 ) ;
V_77 = F_95 ( V_7 -> V_2 , V_48 ) ;
F_96 ( V_48 , V_7 , V_77 , L_23 ) ;
if ( V_48 -> V_81 [ V_77 & 0x1 ] ) {
F_96 ( V_48 , V_7 , V_77 , L_24 ) ;
return V_77 ;
}
if ( V_48 -> V_4 != V_48 -> V_3 ||
F_2 ( V_48 -> V_4 ) != F_2 ( V_48 -> V_3 ) ) {
V_48 -> V_81 [ V_77 & 0x1 ] ++ ;
F_96 ( V_48 , V_7 , V_77 , L_25 ) ;
return V_77 ;
}
if ( V_48 != V_80 )
F_99 ( & V_80 -> V_62 ) ;
V_77 = F_95 ( V_7 -> V_2 , V_80 ) ;
for ( V_19 = V_18 ; V_19 < V_20 ; V_19 ++ )
if ( F_20 ( V_77 , V_7 -> V_23 [ V_19 ] ) )
V_7 -> V_23 [ V_19 ] = V_77 ;
if ( V_80 -> V_81 [ V_77 & 0x1 ] ) {
F_96 ( V_48 , V_7 , V_77 , L_26 ) ;
goto V_82;
}
V_80 -> V_81 [ V_77 & 0x1 ] ++ ;
if ( V_80 -> V_4 != V_80 -> V_3 ) {
F_96 ( V_48 , V_7 , V_77 , L_27 ) ;
} else {
F_96 ( V_48 , V_7 , V_77 , L_28 ) ;
F_100 ( V_7 -> V_2 , V_80 , V_7 ) ;
}
V_82:
if ( V_48 != V_80 )
F_101 ( & V_80 -> V_62 ) ;
return V_77 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_24 * V_48 )
{
int V_77 = V_48 -> V_3 ;
int V_83 ;
struct V_6 * V_7 = F_103 ( V_2 -> V_70 ) ;
F_104 ( V_2 , V_48 ) ;
V_48 -> V_81 [ V_77 & 0x1 ] = 0 ;
V_83 = V_48 -> V_81 [ ( V_77 + 1 ) & 0x1 ] ;
F_96 ( V_48 , V_7 , V_77 , V_83 ? L_29 : L_30 ) ;
return V_83 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
unsigned long V_77 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_77 = F_95 ( V_2 , V_48 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_65 ( V_7 -> V_23 [ V_19 ] , V_77 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_77 ;
}
F_98 ( V_48 , V_7 ) ;
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_31 ) ;
else
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_32 ) ;
}
static void F_106 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
int V_19 , V_72 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_20 ( V_48 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
break;
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_19 ] ;
}
for ( V_72 = V_22 ; V_72 < V_19 ; V_72 ++ )
V_7 -> V_17 [ V_72 ] = V_7 -> V_17 [ V_18 ] ;
for ( V_72 = V_22 ; V_19 < V_20 ; V_19 ++ , V_72 ++ ) {
if ( V_7 -> V_17 [ V_72 ] == V_7 -> V_17 [ V_20 ] )
break;
V_7 -> V_17 [ V_72 ] = V_7 -> V_17 [ V_19 ] ;
V_7 -> V_23 [ V_72 ] = V_7 -> V_23 [ V_19 ] ;
}
F_105 ( V_2 , V_48 , V_7 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_48 -> V_3 ) {
F_105 ( V_2 , V_48 , V_7 ) ;
} else {
F_106 ( V_2 , V_48 , V_7 ) ;
V_7 -> V_3 = V_48 -> V_3 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_33 ) ;
}
if ( V_7 -> V_4 != V_48 -> V_4 ) {
V_7 -> V_4 = V_48 -> V_4 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_34 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_84 = ! ! ( V_48 -> V_63 & V_7 -> V_50 ) ;
F_108 ( V_7 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
F_40 ( V_43 ) ;
V_48 = V_7 -> V_49 ;
if ( ( V_7 -> V_4 == F_2 ( V_48 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_48 -> V_3 ) ) ||
! F_110 ( & V_48 -> V_62 ) ) {
F_41 ( V_43 ) ;
return;
}
F_107 ( V_2 , V_48 , V_7 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_112 ( & V_48 -> V_62 ) ;
V_2 -> V_85 = 0 ;
if ( F_1 ( V_2 ) ) {
F_113 ( & V_48 -> V_62 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_56 , V_2 -> V_4 , L_35 ) ;
F_69 ( V_2 ) ;
F_113 ( & V_48 -> V_62 ) ;
F_114 ( & V_2 -> V_86 ) ;
F_115 (rsp, rnp) {
F_112 ( & V_48 -> V_62 ) ;
V_7 = F_103 ( V_2 -> V_70 ) ;
F_116 ( V_48 ) ;
V_48 -> V_63 = V_48 -> V_51 ;
F_2 ( V_48 -> V_4 ) = V_2 -> V_4 ;
F_33 ( V_48 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_3 ;
if ( V_48 == V_7 -> V_49 )
F_107 ( V_2 , V_48 , V_7 ) ;
F_117 ( V_48 ) ;
F_118 ( V_2 -> V_56 , V_48 -> V_4 ,
V_48 -> V_79 , V_48 -> V_65 ,
V_48 -> V_64 , V_48 -> V_63 ) ;
F_113 ( & V_48 -> V_62 ) ;
#ifdef F_119
if ( ( F_120 () % ( V_87 + 1 ) ) == 0 &&
V_88 == V_89 )
F_121 ( 200 ) ;
#endif
F_122 () ;
}
F_123 ( & V_2 -> V_86 ) ;
return 1 ;
}
int F_124 ( struct V_1 * V_2 , int V_90 )
{
int V_91 = V_90 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
V_2 -> V_92 ++ ;
if ( V_91 == V_93 ) {
F_125 ( V_2 , F_60 ) ;
V_91 = V_94 ;
} else {
F_125 ( V_2 , F_62 ) ;
}
if ( F_2 ( V_2 -> V_85 ) & V_95 ) {
F_112 ( & V_48 -> V_62 ) ;
V_2 -> V_85 &= ~ V_95 ;
F_113 ( & V_48 -> V_62 ) ;
}
return V_91 ;
}
static void F_126 ( struct V_1 * V_2 )
{
unsigned long V_96 ;
int V_97 = 0 ;
struct V_6 * V_7 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_112 ( & V_48 -> V_62 ) ;
V_96 = V_59 - V_2 -> V_58 ;
if ( V_96 > V_2 -> V_98 )
V_2 -> V_98 = V_96 ;
F_113 ( & V_48 -> V_62 ) ;
F_115 (rsp, rnp) {
F_112 ( & V_48 -> V_62 ) ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_103 ( V_2 -> V_70 ) ;
if ( V_48 == V_7 -> V_49 )
F_107 ( V_2 , V_48 , V_7 ) ;
V_97 += F_102 ( V_2 , V_48 ) ;
F_113 ( & V_48 -> V_62 ) ;
F_122 () ;
}
V_48 = F_21 ( V_2 ) ;
F_112 ( & V_48 -> V_62 ) ;
F_127 ( V_48 , V_97 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_56 , V_2 -> V_3 , L_36 ) ;
V_2 -> V_91 = V_99 ;
V_7 = F_103 ( V_2 -> V_70 ) ;
F_106 ( V_2 , V_48 , V_7 ) ;
if ( F_18 ( V_2 , V_7 ) )
V_2 -> V_85 = 1 ;
F_113 ( & V_48 -> V_62 ) ;
}
static int T_2 F_128 ( void * V_100 )
{
int V_91 ;
unsigned long V_72 ;
int V_47 ;
struct V_1 * V_2 = V_100 ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_129 ( V_2 -> V_101 ,
V_2 -> V_85 &
V_102 ) ;
if ( ( V_2 -> V_85 & V_102 ) &&
F_111 ( V_2 ) )
break;
F_122 () ;
F_130 ( V_31 ) ;
}
V_91 = V_93 ;
V_72 = V_103 ;
if ( V_72 > V_104 ) {
V_72 = V_104 ;
V_103 = V_104 ;
}
for (; ; ) {
V_2 -> V_105 = V_59 + V_72 ;
V_47 = F_131 ( V_2 -> V_101 ,
( V_2 -> V_85 & V_95 ) ||
( ! F_2 ( V_48 -> V_63 ) &&
! F_132 ( V_48 ) ) ,
V_72 ) ;
if ( ! F_2 ( V_48 -> V_63 ) &&
! F_132 ( V_48 ) )
break;
if ( V_47 == 0 || ( V_2 -> V_85 & V_95 ) ) {
V_91 = F_124 ( V_2 , V_91 ) ;
F_122 () ;
} else {
F_122 () ;
F_130 ( V_31 ) ;
}
V_72 = V_106 ;
if ( V_72 > V_104 ) {
V_72 = V_104 ;
V_106 = V_104 ;
} else if ( V_72 < 1 ) {
V_72 = 1 ;
V_106 = 1 ;
}
}
F_126 ( V_2 ) ;
}
}
static void F_133 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_134 ( V_108 , struct V_1 , V_109 ) ;
F_135 ( & V_2 -> V_101 ) ;
}
static void
F_100 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_110 || ! F_18 ( V_2 , V_7 ) ) {
return;
}
V_2 -> V_85 = V_102 ;
F_136 ( & V_2 -> V_109 ) ;
}
static void
F_137 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_103 ( V_2 -> V_70 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_106 ( V_2 , V_48 , V_7 ) ;
F_100 ( V_2 , V_48 , V_7 ) ;
}
static void F_138 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void
F_139 ( unsigned long V_111 , struct V_1 * V_2 ,
struct V_24 * V_48 , unsigned long V_43 )
__releases( V_48 -> V_62 )
{
struct V_24 * V_112 ;
for (; ; ) {
if ( ! ( V_48 -> V_63 & V_111 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_48 -> V_63 &= ~ V_111 ;
F_140 ( V_2 -> V_56 , V_48 -> V_4 ,
V_111 , V_48 -> V_63 , V_48 -> V_79 ,
V_48 -> V_65 , V_48 -> V_64 ,
! ! V_48 -> V_113 ) ;
if ( V_48 -> V_63 != 0 || F_132 ( V_48 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_111 = V_48 -> V_50 ;
if ( V_48 -> V_114 == NULL ) {
break;
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
V_112 = V_48 ;
V_48 = V_48 -> V_114 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_33 ( V_112 -> V_63 ) ;
}
F_138 ( V_2 , V_43 ) ;
}
static void
F_141 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
unsigned long V_111 ;
struct V_24 * V_48 ;
V_48 = V_7 -> V_49 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_48 -> V_4 ||
V_48 -> V_3 == V_48 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
V_111 = V_7 -> V_50 ;
if ( ( V_48 -> V_63 & V_111 ) == 0 ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
} else {
V_7 -> V_84 = 0 ;
F_105 ( V_2 , V_48 , V_7 ) ;
F_139 ( V_111 , V_2 , V_48 , V_43 ) ;
}
}
static void
F_142 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_109 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_84 )
return;
if ( ! V_7 -> V_9 )
return;
F_141 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_143 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( F_144 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_115 += V_7 -> V_115 ;
V_2 -> V_71 += V_7 -> V_71 ;
V_7 -> V_116 += V_7 -> V_71 ;
V_7 -> V_115 = 0 ;
F_2 ( V_7 -> V_71 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_117 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_117 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_118 = V_7 -> V_16 ;
V_2 -> V_118 = V_7 -> V_17 [ V_18 ] ;
}
F_93 ( V_7 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_6 * V_7 = F_146 ( V_2 -> V_70 ) ;
if ( F_147 ( V_2 , V_7 ) )
return;
V_7 -> V_115 += V_2 -> V_115 ;
V_7 -> V_71 += V_2 -> V_71 ;
V_7 -> V_119 += V_2 -> V_71 ;
if ( V_2 -> V_115 != V_2 -> V_71 )
F_148 () ;
V_2 -> V_115 = 0 ;
V_2 -> V_71 = 0 ;
if ( V_2 -> V_120 != NULL ) {
* V_2 -> V_118 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_120 ;
for ( V_19 = V_76 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_118 ;
V_2 -> V_120 = NULL ;
V_2 -> V_118 = & V_2 -> V_120 ;
}
if ( V_2 -> V_121 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_121 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_117 ;
V_2 -> V_121 = NULL ;
V_2 -> V_117 = & V_2 -> V_121 ;
}
}
static void F_149 ( struct V_1 * V_2 )
{
F_150 (unsigned long mask) ;
F_150 ( struct V_6 * V_7 = F_103 ( V_2 -> V_70 ) ) ;
F_150 ( struct V_24 * V_48 = V_7 -> V_49 ) ;
F_150 ( V_111 = V_7 -> V_50 ) ;
F_5 ( V_2 -> V_56 ,
V_48 -> V_4 + 1 - ! ! ( V_48 -> V_63 & V_111 ) ,
L_37 ) ;
}
static void F_151 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned long V_111 ;
int V_122 = 0 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
F_152 ( V_48 , - 1 ) ;
F_114 ( & V_2 -> V_86 ) ;
F_73 ( & V_2 -> V_123 , V_43 ) ;
F_143 ( V_5 , V_2 , V_48 , V_7 ) ;
F_145 ( V_2 ) ;
V_111 = V_7 -> V_50 ;
do {
F_99 ( & V_48 -> V_62 ) ;
V_48 -> V_51 &= ~ V_111 ;
if ( V_48 -> V_51 != 0 ) {
if ( V_48 != V_7 -> V_49 )
F_101 ( & V_48 -> V_62 ) ;
break;
}
if ( V_48 == V_7 -> V_49 )
V_122 = F_153 ( V_2 , V_48 , V_7 ) ;
else
F_101 ( & V_48 -> V_62 ) ;
V_111 = V_48 -> V_50 ;
V_48 = V_48 -> V_114 ;
} while ( V_48 != NULL );
F_101 ( & V_2 -> V_123 ) ;
V_48 = V_7 -> V_49 ;
if ( V_122 & V_124 )
F_154 ( V_48 , V_43 ) ;
else
F_75 ( & V_48 -> V_62 , V_43 ) ;
if ( V_122 & V_125 )
F_155 ( V_2 , V_48 , true ) ;
F_28 ( V_7 -> V_71 != 0 || V_7 -> V_16 != NULL ,
L_38 ,
V_5 , V_7 -> V_71 , V_7 -> V_16 ) ;
F_93 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_123 ( & V_2 -> V_86 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
}
static void F_151 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_156 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_126 * V_127 , * V_128 , * * V_129 ;
long V_130 , V_131 , V_132 ;
int V_19 ;
if ( ! F_17 ( V_7 ) ) {
F_157 ( V_2 -> V_56 , V_7 -> V_115 , V_7 -> V_71 , 0 ) ;
F_158 ( V_2 -> V_56 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_159 () , F_24 ( V_31 ) ,
F_160 () ) ;
return;
}
F_40 ( V_43 ) ;
F_33 ( F_67 ( F_26 () ) ) ;
V_130 = V_7 -> V_133 ;
F_157 ( V_2 -> V_56 , V_7 -> V_115 , V_7 -> V_71 , V_130 ) ;
V_128 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_129 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_76 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_41 ( V_43 ) ;
V_131 = V_132 = 0 ;
while ( V_128 ) {
V_127 = V_128 -> V_127 ;
F_161 ( V_127 ) ;
F_162 ( V_128 ) ;
if ( F_163 ( V_2 -> V_56 , V_128 ) )
V_132 ++ ;
V_128 = V_127 ;
if ( ++ V_131 >= V_130 &&
( F_159 () ||
( ! F_24 ( V_31 ) && ! F_160 () ) ) )
break;
}
F_40 ( V_43 ) ;
F_158 ( V_2 -> V_56 , V_131 , ! ! V_128 , F_159 () ,
F_24 ( V_31 ) ,
F_160 () ) ;
if ( V_128 != NULL ) {
* V_129 = V_7 -> V_16 ;
V_7 -> V_16 = V_128 ;
for ( V_19 = 0 ; V_19 < V_76 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_129 ;
else
break;
}
F_164 () ;
V_7 -> V_115 -= V_132 ;
F_2 ( V_7 -> V_71 ) -= V_131 ;
V_7 -> V_134 += V_131 ;
if ( V_7 -> V_133 == V_135 && V_7 -> V_71 <= V_136 )
V_7 -> V_133 = V_133 ;
if ( V_7 -> V_71 == 0 && V_7 -> V_137 != 0 ) {
V_7 -> V_137 = 0 ;
V_7 -> V_138 = V_2 -> V_92 ;
} else if ( V_7 -> V_71 < V_7 -> V_137 - V_139 )
V_7 -> V_137 = V_7 -> V_71 ;
F_33 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_71 == 0 ) ) ;
F_41 ( V_43 ) ;
if ( F_17 ( V_7 ) )
F_165 () ;
}
void F_166 ( int V_5 , int V_29 )
{
F_8 ( L_39 ) ;
F_167 () ;
if ( V_29 || F_59 () ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_168 () ) {
F_6 ( V_5 ) ;
}
F_169 ( V_5 ) ;
if ( F_170 ( V_5 ) )
F_165 () ;
F_8 ( L_40 ) ;
}
static void F_125 ( struct V_1 * V_2 , int (* F_171)( struct V_6 * ) )
{
unsigned long V_140 ;
int V_5 ;
unsigned long V_43 ;
unsigned long V_111 ;
struct V_24 * V_48 ;
F_72 (rsp, rnp) {
F_122 () ;
V_111 = 0 ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
if ( ! F_1 ( V_2 ) ) {
F_75 ( & V_48 -> V_62 , V_43 ) ;
return;
}
if ( V_48 -> V_63 == 0 ) {
F_172 ( V_48 , V_43 ) ;
continue;
}
V_5 = V_48 -> V_65 ;
V_140 = 1 ;
for (; V_5 <= V_48 -> V_64 ; V_5 ++ , V_140 <<= 1 ) {
if ( ( V_48 -> V_63 & V_140 ) != 0 &&
F_171 ( F_83 ( V_2 -> V_70 , V_5 ) ) )
V_111 |= V_140 ;
}
if ( V_111 != 0 ) {
F_139 ( V_111 , V_2 , V_48 , V_43 ) ;
continue;
}
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
V_48 = F_21 ( V_2 ) ;
if ( V_48 -> V_63 == 0 ) {
F_73 ( & V_48 -> V_62 , V_43 ) ;
F_172 ( V_48 , V_43 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
bool V_47 ;
struct V_24 * V_48 ;
struct V_24 * V_141 = NULL ;
V_48 = F_83 ( V_2 -> V_70 , F_173 () ) -> V_49 ;
for (; V_48 != NULL ; V_48 = V_48 -> V_114 ) {
V_47 = ( F_2 ( V_2 -> V_85 ) & V_95 ) ||
! F_110 ( & V_48 -> V_142 ) ;
if ( V_141 != NULL )
F_101 ( & V_141 -> V_142 ) ;
if ( V_47 ) {
V_2 -> V_143 ++ ;
return;
}
V_141 = V_48 ;
}
F_73 ( & V_141 -> V_62 , V_43 ) ;
F_101 ( & V_141 -> V_142 ) ;
if ( F_2 ( V_2 -> V_85 ) & V_95 ) {
V_2 -> V_143 ++ ;
F_75 ( & V_141 -> V_62 , V_43 ) ;
return;
}
V_2 -> V_85 |= V_95 ;
F_75 ( & V_141 -> V_62 , V_43 ) ;
F_135 ( & V_2 -> V_101 ) ;
}
static void
F_174 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_146 ( V_2 -> V_70 ) ;
F_33 ( V_7 -> V_144 == 0 ) ;
F_142 ( V_2 , V_7 ) ;
F_40 ( V_43 ) ;
if ( F_18 ( V_2 , V_7 ) ) {
F_99 ( & F_21 ( V_2 ) -> V_62 ) ;
F_137 ( V_2 ) ;
F_75 ( & F_21 ( V_2 ) -> V_62 , V_43 ) ;
} else {
F_41 ( V_43 ) ;
}
if ( F_17 ( V_7 ) )
F_175 ( V_2 , V_7 ) ;
}
static void F_176 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
if ( F_67 ( F_26 () ) )
return;
F_8 ( L_41 ) ;
F_92 (rsp)
F_174 ( V_2 ) ;
F_8 ( L_42 ) ;
}
static void F_175 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_177 ( ! F_2 ( V_52 ) ) )
return;
if ( F_178 ( ! V_2 -> V_147 ) ) {
F_156 ( V_2 , V_7 ) ;
return;
}
F_179 () ;
}
static void F_165 ( void )
{
if ( F_180 ( F_26 () ) )
F_181 ( V_148 ) ;
}
static void F_182 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_126 * V_149 , unsigned long V_43 )
{
if ( F_54 () && F_180 ( F_26 () ) )
F_165 () ;
if ( F_183 ( V_43 ) || F_67 ( F_26 () ) )
return;
if ( F_177 ( V_7 -> V_71 > V_7 -> V_137 + V_139 ) ) {
F_109 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_24 * V_80 = F_21 ( V_2 ) ;
F_99 ( & V_80 -> V_62 ) ;
F_137 ( V_2 ) ;
F_101 ( & V_80 -> V_62 ) ;
} else {
V_7 -> V_133 = V_135 ;
if ( V_2 -> V_92 == V_7 -> V_138 &&
* V_7 -> V_17 [ V_18 ] != V_149 )
F_13 ( V_2 ) ;
V_7 -> V_138 = V_2 -> V_92 ;
V_7 -> V_137 = V_7 -> V_71 ;
}
}
}
static void
F_184 ( struct V_126 * V_149 , void (* F_185)( struct V_126 * V_150 ) ,
struct V_1 * V_2 , int V_5 , bool V_151 )
{
unsigned long V_43 ;
struct V_6 * V_7 ;
F_33 ( ( unsigned long ) V_149 & 0x3 ) ;
F_186 ( V_149 ) ;
V_149 -> F_185 = F_185 ;
V_149 -> V_127 = NULL ;
F_40 ( V_43 ) ;
V_7 = F_103 ( V_2 -> V_70 ) ;
if ( F_177 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_152 ;
if ( V_5 != - 1 )
V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
V_152 = ! F_187 ( V_7 , V_149 , V_151 ) ;
F_33 ( V_152 ) ;
F_41 ( V_43 ) ;
return;
}
F_2 ( V_7 -> V_71 ) ++ ;
if ( V_151 )
V_7 -> V_115 ++ ;
else
F_148 () ;
F_164 () ;
* V_7 -> V_17 [ V_20 ] = V_149 ;
V_7 -> V_17 [ V_20 ] = & V_149 -> V_127 ;
if ( F_188 ( ( unsigned long ) F_185 ) )
F_189 ( V_2 -> V_56 , V_149 , ( unsigned long ) F_185 ,
V_7 -> V_115 , V_7 -> V_71 ) ;
else
F_190 ( V_2 -> V_56 , V_149 , V_7 -> V_115 , V_7 -> V_71 ) ;
F_182 ( V_2 , V_7 , V_149 , V_43 ) ;
F_41 ( V_43 ) ;
}
void F_191 ( struct V_126 * V_149 , void (* F_185)( struct V_126 * V_150 ) )
{
F_184 ( V_149 , F_185 , & V_11 , - 1 , 0 ) ;
}
void F_192 ( struct V_126 * V_149 , void (* F_185)( struct V_126 * V_150 ) )
{
F_184 ( V_149 , F_185 , & V_12 , - 1 , 0 ) ;
}
static inline int F_193 ( void )
{
int V_47 ;
F_194 () ;
F_55 () ;
V_47 = F_195 () <= 1 ;
F_56 () ;
return V_47 ;
}
void F_196 ( void )
{
F_35 ( ! F_36 ( & V_39 ) &&
! F_36 ( & V_38 ) &&
! F_36 ( & V_40 ) ,
L_43 ) ;
if ( F_193 () )
return;
if ( V_153 )
F_197 () ;
else
F_198 ( F_191 ) ;
}
void F_199 ( void )
{
F_35 ( ! F_36 ( & V_39 ) &&
! F_36 ( & V_38 ) &&
! F_36 ( & V_40 ) ,
L_44 ) ;
if ( F_193 () )
return;
if ( V_153 )
F_200 () ;
else
F_198 ( F_192 ) ;
}
static int F_201 ( void * V_154 )
{
F_164 () ;
return 0 ;
}
void F_197 ( void )
{
long V_155 , V_78 , V_55 ;
int V_156 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_65 ( ( V_157 ) F_202 ( & V_2 -> V_158 ) ,
( V_157 ) F_202 ( & V_2 -> V_159 ) +
V_75 / 8 ) ) {
F_196 () ;
F_203 ( & V_2 -> V_160 ) ;
return;
}
V_55 = F_204 ( & V_2 -> V_158 ) ;
V_155 = V_55 ;
F_205 () ;
F_33 ( F_67 ( F_173 () ) ) ;
while ( F_206 ( V_161 ,
F_201 ,
NULL ) == - V_162 ) {
F_207 () ;
F_203 ( & V_2 -> V_163 ) ;
V_78 = F_202 ( & V_2 -> V_159 ) ;
if ( F_65 ( ( V_157 ) V_78 , ( V_157 ) V_155 ) ) {
F_30 () ;
F_203 ( & V_2 -> V_164 ) ;
return;
}
if ( V_156 ++ < 10 ) {
F_121 ( V_156 * F_195 () ) ;
} else {
F_198 ( F_191 ) ;
F_203 ( & V_2 -> V_165 ) ;
return;
}
V_78 = F_202 ( & V_2 -> V_159 ) ;
if ( F_65 ( ( V_157 ) V_78 , ( V_157 ) V_155 ) ) {
F_30 () ;
F_203 ( & V_2 -> V_166 ) ;
return;
}
F_205 () ;
V_55 = F_202 ( & V_2 -> V_158 ) ;
F_164 () ;
}
F_203 ( & V_2 -> V_167 ) ;
do {
F_203 ( & V_2 -> V_168 ) ;
V_78 = F_202 ( & V_2 -> V_159 ) ;
if ( F_65 ( ( V_157 ) V_78 , ( V_157 ) V_55 ) ) {
F_30 () ;
F_203 ( & V_2 -> V_169 ) ;
break;
}
} while ( F_208 ( & V_2 -> V_159 , V_78 , V_55 ) != V_78 );
F_203 ( & V_2 -> V_170 ) ;
F_207 () ;
}
static int F_209 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_48 = V_7 -> V_49 ;
V_7 -> V_171 ++ ;
F_90 ( V_2 , V_7 ) ;
if ( V_52 &&
V_7 -> V_84 && ! V_7 -> V_9 ) {
V_7 -> V_172 ++ ;
} else if ( V_7 -> V_84 && V_7 -> V_9 ) {
V_7 -> V_173 ++ ;
return 1 ;
}
if ( F_17 ( V_7 ) ) {
V_7 -> V_174 ++ ;
return 1 ;
}
if ( F_18 ( V_2 , V_7 ) ) {
V_7 -> V_175 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_176 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_177 ++ ;
return 1 ;
}
V_7 -> V_178 ++ ;
return 0 ;
}
static int F_170 ( int V_5 )
{
struct V_1 * V_2 ;
F_92 (rsp)
if ( F_209 ( V_2 , F_83 ( V_2 -> V_70 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_210 ( int V_5 , bool * V_179 )
{
bool V_180 = true ;
bool V_181 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_92 (rsp) {
V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
if ( V_7 -> V_71 != V_7 -> V_115 )
V_180 = false ;
if ( V_7 -> V_16 )
V_181 = true ;
}
if ( V_179 )
* V_179 = V_180 ;
return V_181 ;
}
static void F_211 ( struct V_1 * V_2 , char * V_78 ,
int V_5 , unsigned long V_182 )
{
F_212 ( V_2 -> V_56 , V_78 , V_5 ,
F_34 ( & V_2 -> V_183 ) , V_182 ) ;
}
static void F_213 ( struct V_126 * V_184 )
{
struct V_6 * V_7 = F_134 ( V_184 , struct V_6 , V_185 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_214 ( & V_2 -> V_183 ) ) {
F_211 ( V_2 , L_45 , - 1 , V_2 -> V_186 ) ;
F_215 ( & V_2 -> V_187 ) ;
} else {
F_211 ( V_2 , L_46 , - 1 , V_2 -> V_186 ) ;
}
}
static void F_216 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_146 ( V_2 -> V_70 ) ;
F_211 ( V_2 , L_47 , - 1 , V_2 -> V_186 ) ;
F_31 ( & V_2 -> V_183 ) ;
V_2 -> V_188 ( & V_7 -> V_185 , F_213 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_55 = F_2 ( V_2 -> V_186 ) ;
unsigned long V_189 ;
F_211 ( V_2 , L_48 , - 1 , V_55 ) ;
F_114 ( & V_2 -> V_190 ) ;
F_164 () ;
V_189 = F_2 ( V_2 -> V_186 ) ;
F_211 ( V_2 , L_49 , - 1 , V_189 ) ;
if ( F_65 ( V_189 , ( ( V_55 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_211 ( V_2 , L_50 , - 1 , V_189 ) ;
F_164 () ;
F_123 ( & V_2 -> V_190 ) ;
return;
}
F_2 ( V_2 -> V_186 ) ++ ;
F_33 ( ( V_2 -> V_186 & 0x1 ) != 1 ) ;
F_211 ( V_2 , L_51 , - 1 , V_2 -> V_186 ) ;
F_164 () ;
F_218 ( & V_2 -> V_187 ) ;
F_219 ( & V_2 -> V_183 , 1 ) ;
F_205 () ;
F_82 (cpu) {
if ( ! F_180 ( V_5 ) && ! F_144 ( V_5 ) )
continue;
V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
if ( F_144 ( V_5 ) ) {
F_211 ( V_2 , L_52 , V_5 ,
V_2 -> V_186 ) ;
F_31 ( & V_2 -> V_183 ) ;
F_184 ( & V_7 -> V_185 , F_213 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_71 ) ) {
F_211 ( V_2 , L_53 , V_5 ,
V_2 -> V_186 ) ;
F_220 ( V_5 , F_216 , V_2 , 1 ) ;
} else {
F_211 ( V_2 , L_54 , V_5 ,
V_2 -> V_186 ) ;
}
}
F_207 () ;
if ( F_214 ( & V_2 -> V_183 ) )
F_215 ( & V_2 -> V_187 ) ;
F_164 () ;
F_2 ( V_2 -> V_186 ) ++ ;
F_33 ( ( V_2 -> V_186 & 0x1 ) != 0 ) ;
F_211 ( V_2 , L_55 , - 1 , V_2 -> V_186 ) ;
F_164 () ;
F_221 ( & V_2 -> V_187 ) ;
F_123 ( & V_2 -> V_190 ) ;
}
void F_222 ( void )
{
F_217 ( & V_12 ) ;
}
void F_223 ( void )
{
F_217 ( & V_11 ) ;
}
static void T_3
F_224 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_50 = 1UL << ( V_5 - V_7 -> V_49 -> V_65 ) ;
F_93 ( V_7 ) ;
V_7 -> V_115 = 0 ;
F_2 ( V_7 -> V_71 ) = 0 ;
V_7 -> V_37 = & F_4 ( V_26 , V_5 ) ;
F_33 ( V_7 -> V_37 -> V_30 != V_45 ) ;
F_33 ( F_34 ( & V_7 -> V_37 -> V_37 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_225 ( V_7 ) ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
}
static void
F_226 ( int V_5 , struct V_1 * V_2 , int V_191 )
{
unsigned long V_43 ;
unsigned long V_111 ;
struct V_6 * V_7 = F_83 ( V_2 -> V_70 , V_5 ) ;
struct V_24 * V_48 = F_21 ( V_2 ) ;
F_114 ( & V_2 -> V_86 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_7 -> V_144 = 1 ;
V_7 -> V_191 = V_191 ;
V_7 -> V_137 = 0 ;
V_7 -> V_138 = V_2 -> V_92 ;
V_7 -> V_133 = V_133 ;
F_93 ( V_7 ) ;
V_7 -> V_37 -> V_30 = V_45 ;
F_219 ( & V_7 -> V_37 -> V_37 ,
( F_34 ( & V_7 -> V_37 -> V_37 ) & ~ 0x1 ) + 1 ) ;
F_101 ( & V_48 -> V_62 ) ;
V_48 = V_7 -> V_49 ;
V_111 = V_7 -> V_50 ;
do {
F_99 ( & V_48 -> V_62 ) ;
V_48 -> V_51 |= V_111 ;
V_111 = V_48 -> V_50 ;
if ( V_48 == V_7 -> V_49 ) {
V_7 -> V_4 = V_48 -> V_3 ;
V_7 -> V_3 = V_48 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_84 = 0 ;
F_5 ( V_2 -> V_56 , V_7 -> V_4 , L_56 ) ;
}
F_101 ( & V_48 -> V_62 ) ;
V_48 = V_48 -> V_114 ;
} while ( V_48 != NULL && ! ( V_48 -> V_51 & V_111 ) );
F_41 ( V_43 ) ;
F_123 ( & V_2 -> V_86 ) ;
}
static void F_227 ( int V_5 )
{
struct V_1 * V_2 ;
F_92 (rsp)
F_226 ( V_5 , V_2 ,
strcmp ( V_2 -> V_56 , L_57 ) == 0 ) ;
}
static int F_228 ( struct V_192 * V_193 ,
unsigned long V_194 , void * V_195 )
{
long V_5 = ( long ) V_195 ;
struct V_6 * V_7 = F_83 ( V_1 -> V_70 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
struct V_1 * V_2 ;
F_8 ( L_58 ) ;
switch ( V_194 ) {
case V_196 :
case V_197 :
F_227 ( V_5 ) ;
F_229 ( V_5 ) ;
break;
case V_198 :
case V_199 :
F_152 ( V_48 , - 1 ) ;
break;
case V_200 :
F_152 ( V_48 , V_5 ) ;
break;
case V_201 :
case V_202 :
F_92 (rsp)
F_149 ( V_2 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
F_92 (rsp)
F_151 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_8 ( L_59 ) ;
return V_207 ;
}
static int T_3 F_230 ( void )
{
unsigned long V_43 ;
struct V_24 * V_48 ;
struct V_1 * V_2 ;
struct V_32 * V_208 ;
F_92 (rsp) {
V_208 = F_231 ( F_128 , V_2 , L_60 , V_2 -> V_56 ) ;
F_232 ( F_233 ( V_208 ) ) ;
V_48 = F_21 ( V_2 ) ;
F_73 ( & V_48 -> V_62 , V_43 ) ;
V_2 -> V_110 = V_208 ;
F_75 ( & V_48 -> V_62 , V_43 ) ;
F_234 ( V_2 ) ;
}
return 0 ;
}
void F_235 ( void )
{
F_236 ( F_195 () != 1 ) ;
F_236 ( F_237 () > 0 ) ;
V_209 = 1 ;
}
static void T_3 F_238 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = V_210 - 1 ; V_19 > 0 ; V_19 -- )
V_2 -> V_211 [ V_19 ] = V_212 ;
V_2 -> V_211 [ 0 ] = V_213 ;
}
static void T_3 F_238 ( struct V_1 * V_2 )
{
int V_214 ;
int V_215 ;
int V_19 ;
V_215 = V_216 ;
for ( V_19 = V_210 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_214 = V_2 -> V_217 [ V_19 ] ;
V_2 -> V_211 [ V_19 ] = ( V_215 + V_214 - 1 ) / V_214 ;
V_215 = V_214 ;
}
}
static void T_3 F_239 ( struct V_1 * V_2 ,
struct V_6 T_4 * V_70 )
{
static char * V_218 [] = { L_61 ,
L_62 ,
L_63 ,
L_64 } ;
static char * V_219 [] = { L_65 ,
L_66 ,
L_67 ,
L_68 } ;
int V_220 = 1 ;
int V_19 ;
int V_72 ;
struct V_24 * V_48 ;
F_240 ( V_221 > F_241 ( V_218 ) ) ;
if ( V_210 > V_222 )
F_242 ( L_69 ) ;
for ( V_19 = 0 ; V_19 < V_210 ; V_19 ++ )
V_2 -> V_217 [ V_19 ] = V_223 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_210 ; V_19 ++ )
V_2 -> V_79 [ V_19 ] = V_2 -> V_79 [ V_19 - 1 ] + V_2 -> V_217 [ V_19 - 1 ] ;
F_238 ( V_2 ) ;
for ( V_19 = V_210 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_220 *= V_2 -> V_211 [ V_19 ] ;
V_48 = V_2 -> V_79 [ V_19 ] ;
for ( V_72 = 0 ; V_72 < V_2 -> V_217 [ V_19 ] ; V_72 ++ , V_48 ++ ) {
F_243 ( & V_48 -> V_62 ) ;
F_244 ( & V_48 -> V_62 ,
& V_224 [ V_19 ] , V_218 [ V_19 ] ) ;
F_243 ( & V_48 -> V_142 ) ;
F_244 ( & V_48 -> V_142 ,
& V_225 [ V_19 ] , V_219 [ V_19 ] ) ;
V_48 -> V_4 = V_2 -> V_4 ;
V_48 -> V_3 = V_2 -> V_3 ;
V_48 -> V_63 = 0 ;
V_48 -> V_51 = 0 ;
V_48 -> V_65 = V_72 * V_220 ;
V_48 -> V_64 = ( V_72 + 1 ) * V_220 - 1 ;
if ( V_48 -> V_64 >= V_226 )
V_48 -> V_64 = V_226 - 1 ;
if ( V_19 == 0 ) {
V_48 -> V_227 = 0 ;
V_48 -> V_50 = 0 ;
V_48 -> V_114 = NULL ;
} else {
V_48 -> V_227 = V_72 % V_2 -> V_211 [ V_19 - 1 ] ;
V_48 -> V_50 = 1UL << V_48 -> V_227 ;
V_48 -> V_114 = V_2 -> V_79 [ V_19 - 1 ] +
V_72 / V_2 -> V_211 [ V_19 - 1 ] ;
}
V_48 -> V_79 = V_19 ;
F_245 ( & V_48 -> V_228 ) ;
F_246 ( V_48 ) ;
}
}
V_2 -> V_70 = V_70 ;
F_247 ( & V_2 -> V_101 ) ;
F_248 ( & V_2 -> V_109 , F_133 ) ;
V_48 = V_2 -> V_79 [ V_210 - 1 ] ;
F_82 (i) {
while ( V_19 > V_48 -> V_64 )
V_48 ++ ;
F_83 ( V_2 -> V_70 , V_19 ) -> V_49 = V_48 ;
F_224 ( V_19 , V_2 ) ;
}
F_249 ( & V_2 -> V_229 , & V_230 ) ;
}
static void T_3 F_250 ( void )
{
V_157 V_231 ;
int V_19 ;
int V_72 ;
int V_232 = V_216 ;
int V_233 [ V_221 + 1 ] ;
V_231 = V_234 + V_216 / V_235 ;
if ( V_103 == V_75 )
V_103 = V_231 ;
if ( V_106 == V_75 )
V_106 = V_231 ;
if ( V_213 == V_236 &&
V_216 == V_226 )
return;
V_233 [ 0 ] = 1 ;
V_233 [ 1 ] = V_213 ;
for ( V_19 = 2 ; V_19 <= V_221 ; V_19 ++ )
V_233 [ V_19 ] = V_233 [ V_19 - 1 ] * V_212 ;
if ( V_213 < V_236 ||
V_213 > sizeof( unsigned long ) * 8 ||
V_232 > V_233 [ V_221 ] ) {
F_236 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_221 ; V_19 ++ )
if ( V_232 <= V_233 [ V_19 ] ) {
for ( V_72 = 0 ; V_72 <= V_19 ; V_72 ++ )
V_223 [ V_72 ] =
F_251 ( V_232 , V_233 [ V_19 - V_72 ] ) ;
V_210 = V_19 ;
for ( V_72 = V_19 + 1 ; V_72 <= V_221 ; V_72 ++ )
V_223 [ V_72 ] = 0 ;
break;
}
V_87 = 0 ;
for ( V_19 = 0 ; V_19 <= V_221 ; V_19 ++ )
V_87 += V_223 [ V_19 ] ;
V_87 -= V_232 ;
}
void T_3 F_252 ( void )
{
int V_5 ;
F_253 () ;
F_250 () ;
F_239 ( & V_11 , & V_8 ) ;
F_239 ( & V_12 , & V_10 ) ;
F_254 () ;
F_255 ( V_148 , F_176 ) ;
F_256 ( F_228 , 0 ) ;
F_257 (cpu)
F_228 ( NULL , V_196 , ( void * ) ( long ) V_5 ) ;
}
