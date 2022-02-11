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
void F_8 ( int V_5 )
{
F_9 ( F_6 ( L_4 ) ) ;
F_3 ( V_5 ) ;
F_10 ( V_5 ) ;
F_9 ( F_6 ( L_5 ) ) ;
}
long F_11 ( void )
{
return V_11 . V_3 ;
}
long F_12 ( void )
{
return V_12 . V_3 ;
}
void F_13 ( void )
{
F_14 ( & V_12 ) ;
}
void F_15 ( void )
{
V_13 ++ ;
V_14 = 0 ;
}
void F_16 ( unsigned long V_15 )
{
V_14 ++ ;
}
void F_17 ( void )
{
F_14 ( & V_11 ) ;
}
static int
F_18 ( struct V_6 * V_7 )
{
return & V_7 -> V_16 != V_7 -> V_17 [ V_18 ] &&
V_7 -> V_17 [ V_18 ] != NULL ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_19 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_20 ( V_2 ) )
return 1 ;
if ( ! V_7 -> V_17 [ V_20 ] )
return 0 ;
if ( * V_7 -> V_17 [ V_21 ] )
return 1 ;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ )
if ( V_7 -> V_17 [ V_19 - 1 ] != V_7 -> V_17 [ V_19 ] &&
F_21 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_23 [ V_19 ] ) )
return 1 ;
return 0 ;
}
static struct V_24 * F_22 ( struct V_1 * V_2 )
{
return & V_2 -> V_25 [ 0 ] ;
}
static void F_23 ( struct V_26 * V_27 , long long V_28 ,
bool V_29 )
{
F_24 ( F_6 ( L_6 ) , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_25 ( V_31 ) ) {
struct V_32 * T_1 V_33 =
F_26 ( F_27 () ) ;
F_24 ( F_6 ( L_7 ) , V_28 , 0 ) ;
F_28 ( V_34 ) ;
F_29 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
T_1 -> V_35 , T_1 -> V_36 ) ;
}
F_30 ( F_27 () ) ;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ;
F_36 ( ! F_37 ( & V_38 ) ,
L_9 ) ;
F_36 ( ! F_37 ( & V_39 ) ,
L_10 ) ;
F_36 ( ! F_37 ( & V_40 ) ,
L_11 ) ;
}
static void F_38 ( bool V_29 )
{
long long V_28 ;
struct V_26 * V_27 ;
V_27 = F_39 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
F_34 ( ( V_28 & V_41 ) == 0 ) ;
if ( ( V_28 & V_41 ) == V_42 )
V_27 -> V_30 = 0 ;
else
V_27 -> V_30 -= V_42 ;
F_23 ( V_27 , V_28 , V_29 ) ;
}
void F_40 ( void )
{
unsigned long V_43 ;
F_41 ( V_43 ) ;
F_38 ( false ) ;
F_42 ( F_39 ( & V_26 ) , 0 ) ;
F_43 ( V_43 ) ;
}
void F_44 ( void )
{
F_38 ( 1 ) ;
}
void F_45 ( void )
{
unsigned long V_43 ;
long long V_28 ;
struct V_26 * V_27 ;
F_41 ( V_43 ) ;
V_27 = F_39 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 -- ;
F_34 ( V_27 -> V_30 < 0 ) ;
if ( V_27 -> V_30 )
F_24 ( F_6 ( L_12 ) , V_28 , V_27 -> V_30 ) ;
else
F_23 ( V_27 , V_28 , true ) ;
F_42 ( V_27 , 1 ) ;
F_43 ( V_43 ) ;
}
static void F_46 ( struct V_26 * V_27 , long long V_28 ,
int V_29 )
{
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( ! ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ) ;
F_47 ( F_27 () ) ;
F_24 ( F_6 ( L_13 ) , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_25 ( V_31 ) ) {
struct V_32 * T_1 V_33 =
F_26 ( F_27 () ) ;
F_24 ( F_6 ( L_14 ) ,
V_28 , V_27 -> V_30 ) ;
F_28 ( V_34 ) ;
F_29 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
T_1 -> V_35 , T_1 -> V_36 ) ;
}
}
static void F_48 ( bool V_29 )
{
struct V_26 * V_27 ;
long long V_28 ;
V_27 = F_39 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
F_34 ( V_28 < 0 ) ;
if ( V_28 & V_41 )
V_27 -> V_30 += V_42 ;
else
V_27 -> V_30 = V_44 ;
F_46 ( V_27 , V_28 , V_29 ) ;
}
void F_49 ( void )
{
unsigned long V_43 ;
F_41 ( V_43 ) ;
F_48 ( false ) ;
F_50 ( F_39 ( & V_26 ) , 0 ) ;
F_43 ( V_43 ) ;
}
void F_51 ( void )
{
F_48 ( 1 ) ;
}
void F_52 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
long long V_28 ;
F_41 ( V_43 ) ;
V_27 = F_39 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 ++ ;
F_34 ( V_27 -> V_30 == 0 ) ;
if ( V_28 )
F_24 ( F_6 ( L_15 ) , V_28 , V_27 -> V_30 ) ;
else
F_46 ( V_27 , V_28 , true ) ;
F_50 ( V_27 , 1 ) ;
F_43 ( V_43 ) ;
}
void F_53 ( void )
{
struct V_26 * V_27 = F_39 ( & V_26 ) ;
if ( V_27 -> V_45 == 0 &&
( F_35 ( & V_27 -> V_37 ) & 0x1 ) )
return;
V_27 -> V_45 ++ ;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( ! ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ) ;
}
void F_54 ( void )
{
struct V_26 * V_27 = F_39 ( & V_26 ) ;
if ( V_27 -> V_45 == 0 ||
-- V_27 -> V_45 != 0 )
return;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ;
}
bool T_2 F_55 ( void )
{
return F_35 ( F_39 ( & V_26 . V_37 ) ) & 0x1 ;
}
bool T_2 F_56 ( void )
{
int V_46 ;
F_57 () ;
V_46 = F_55 () ;
F_58 () ;
return V_46 ;
}
bool F_59 ( void )
{
struct V_6 * V_7 ;
struct V_24 * V_47 ;
bool V_46 ;
if ( F_60 () )
return 1 ;
F_57 () ;
V_7 = F_39 ( & V_8 ) ;
V_47 = V_7 -> V_48 ;
V_46 = ( V_7 -> V_49 & V_47 -> V_50 ) ||
! V_51 ;
F_58 () ;
return V_46 ;
}
static int F_61 ( void )
{
return F_62 ( V_26 . V_30 ) <= 1 ;
}
static int F_63 ( struct V_6 * V_7 ,
bool * V_52 , unsigned long * V_53 )
{
V_7 -> V_54 = F_64 ( 0 , & V_7 -> V_37 -> V_37 ) ;
F_65 ( V_7 , V_52 , V_53 ) ;
return ( V_7 -> V_54 & 0x1 ) == 0 ;
}
static int F_66 ( struct V_6 * V_7 ,
bool * V_52 , unsigned long * V_53 )
{
unsigned int V_55 ;
unsigned int V_56 ;
V_55 = ( unsigned int ) F_64 ( 0 , & V_7 -> V_37 -> V_37 ) ;
V_56 = ( unsigned int ) V_7 -> V_54 ;
if ( ( V_55 & 0x1 ) == 0 || F_67 ( V_55 , V_56 + 2 ) ) {
F_68 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_16 ) ) ;
V_7 -> V_58 ++ ;
return 1 ;
}
if ( F_69 ( V_7 -> V_2 -> V_59 + 2 , V_60 ) )
return 0 ;
F_70 () ;
if ( F_71 ( V_7 -> V_5 ) ) {
F_68 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
V_7 -> V_61 ++ ;
return 1 ;
}
F_72 ( V_7 -> V_5 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
unsigned long V_62 = F_2 ( V_60 ) ;
V_2 -> V_59 = V_62 ;
F_74 () ;
V_2 -> V_63 = V_62 + F_75 () ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_47 ;
F_77 (rsp, rnp) {
F_78 ( & V_47 -> V_64 , V_43 ) ;
if ( V_47 -> V_65 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_47 -> V_66 - V_47 -> V_67 ; V_5 ++ )
if ( V_47 -> V_65 & ( 1UL << V_5 ) )
F_79 ( V_47 -> V_67 + V_5 ) ;
}
F_80 ( & V_47 -> V_64 , V_43 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
int V_5 ;
long V_68 ;
unsigned long V_43 ;
int V_69 = 0 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
long V_70 = 0 ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_68 = V_60 - V_2 -> V_63 ;
if ( V_68 < V_71 || ! F_1 ( V_2 ) ) {
F_80 ( & V_47 -> V_64 , V_43 ) ;
return;
}
V_2 -> V_63 = V_60 + 3 * F_75 () + 3 ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
F_82 ( L_18 ,
V_2 -> V_57 ) ;
F_83 () ;
F_77 (rsp, rnp) {
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_69 += F_84 ( V_47 ) ;
if ( V_47 -> V_65 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_47 -> V_66 - V_47 -> V_67 ; V_5 ++ )
if ( V_47 -> V_65 & ( 1UL << V_5 ) ) {
F_85 ( V_2 ,
V_47 -> V_67 + V_5 ) ;
V_69 ++ ;
}
}
F_80 ( & V_47 -> V_64 , V_43 ) ;
}
V_47 = F_22 ( V_2 ) ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_69 += F_84 ( V_47 ) ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
F_86 () ;
F_87 (cpu)
V_70 += F_88 ( V_2 -> V_72 , V_5 ) -> V_73 ;
F_89 ( L_19 ,
F_27 () , ( long ) ( V_60 - V_2 -> V_59 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_70 ) ;
if ( V_69 == 0 )
F_82 ( L_20 ) ;
else if ( ! F_90 () )
F_76 ( V_2 ) ;
F_91 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
long V_70 = 0 ;
F_82 ( L_21 , V_2 -> V_57 ) ;
F_83 () ;
F_85 ( V_2 , F_27 () ) ;
F_86 () ;
F_87 (cpu)
V_70 += F_88 ( V_2 -> V_72 , V_5 ) -> V_73 ;
F_89 ( L_22 ,
V_60 - V_2 -> V_59 , V_2 -> V_4 , V_2 -> V_3 , V_70 ) ;
if ( ! F_90 () )
F_93 () ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
if ( F_69 ( V_60 , V_2 -> V_63 ) )
V_2 -> V_63 = V_60 +
3 * F_75 () + 3 ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
F_94 ( F_27 () ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_74 ;
unsigned long V_62 ;
unsigned long V_75 ;
struct V_24 * V_47 ;
if ( V_76 || ! F_1 ( V_2 ) )
return;
V_62 = F_2 ( V_60 ) ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_96 () ;
V_75 = F_2 ( V_2 -> V_63 ) ;
F_96 () ;
V_74 = F_2 ( V_2 -> V_59 ) ;
F_96 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_69 ( V_3 , V_4 ) ||
F_21 ( V_62 , V_75 ) ||
F_69 ( V_74 , V_75 ) )
return;
V_47 = V_7 -> V_48 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_47 -> V_65 ) & V_7 -> V_49 ) ) {
F_92 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_69 ( V_62 , V_75 + V_71 ) ) {
F_81 ( V_2 ) ;
}
}
void F_97 ( void )
{
struct V_1 * V_2 ;
F_98 (rsp)
V_2 -> V_63 = V_60 + V_77 / 2 ;
}
static void F_99 ( struct V_6 * V_7 )
{
int V_19 ;
if ( F_100 ( V_7 ) )
return;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
}
static unsigned long F_101 ( struct V_1 * V_2 ,
struct V_24 * V_47 )
{
if ( F_22 ( V_2 ) == V_47 && V_47 -> V_4 == V_47 -> V_3 )
return V_47 -> V_3 + 1 ;
return V_47 -> V_3 + 2 ;
}
static void F_102 ( struct V_24 * V_47 , struct V_6 * V_7 ,
unsigned long V_79 , const char * V_80 )
{
F_103 ( V_7 -> V_2 -> V_57 , V_47 -> V_4 ,
V_47 -> V_3 , V_79 , V_47 -> V_81 ,
V_47 -> V_67 , V_47 -> V_66 , V_80 ) ;
}
static unsigned long V_33
F_104 ( struct V_24 * V_47 , struct V_6 * V_7 )
{
unsigned long V_79 ;
int V_19 ;
struct V_24 * V_82 = F_22 ( V_7 -> V_2 ) ;
V_79 = F_101 ( V_7 -> V_2 , V_47 ) ;
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_23 ) ) ;
if ( V_47 -> V_83 [ V_79 & 0x1 ] ) {
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_24 ) ) ;
return V_79 ;
}
if ( V_47 -> V_4 != V_47 -> V_3 ||
F_2 ( V_47 -> V_4 ) != F_2 ( V_47 -> V_3 ) ) {
V_47 -> V_83 [ V_79 & 0x1 ] ++ ;
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_25 ) ) ;
return V_79 ;
}
if ( V_47 != V_82 )
F_105 ( & V_82 -> V_64 ) ;
V_79 = F_101 ( V_7 -> V_2 , V_82 ) ;
for ( V_19 = V_18 ; V_19 < V_20 ; V_19 ++ )
if ( F_21 ( V_79 , V_7 -> V_23 [ V_19 ] ) )
V_7 -> V_23 [ V_19 ] = V_79 ;
if ( V_82 -> V_83 [ V_79 & 0x1 ] ) {
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_26 ) ) ;
goto V_84;
}
V_82 -> V_83 [ V_79 & 0x1 ] ++ ;
if ( V_82 -> V_4 != V_82 -> V_3 ) {
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_27 ) ) ;
} else {
F_102 ( V_47 , V_7 , V_79 , F_6 ( L_28 ) ) ;
F_106 ( V_7 -> V_2 , V_82 , V_7 ) ;
}
V_84:
if ( V_47 != V_82 )
F_107 ( & V_82 -> V_64 ) ;
return V_79 ;
}
static int F_108 ( struct V_1 * V_2 , struct V_24 * V_47 )
{
int V_79 = V_47 -> V_3 ;
int V_85 ;
struct V_6 * V_7 = F_39 ( V_2 -> V_72 ) ;
F_109 ( V_2 , V_47 ) ;
V_47 -> V_83 [ V_79 & 0x1 ] = 0 ;
V_85 = V_47 -> V_83 [ ( V_79 + 1 ) & 0x1 ] ;
F_102 ( V_47 , V_7 , V_79 ,
V_85 ? F_6 ( L_29 ) : F_6 ( L_30 ) ) ;
return V_85 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
unsigned long V_79 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_79 = F_101 ( V_2 , V_47 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_69 ( V_7 -> V_23 [ V_19 ] , V_79 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_79 ;
}
F_104 ( V_47 , V_7 ) ;
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_31 ) ) ;
else
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_32 ) ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
int V_19 , V_62 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_21 ( V_47 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
break;
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_19 ] ;
}
for ( V_62 = V_22 ; V_62 < V_19 ; V_62 ++ )
V_7 -> V_17 [ V_62 ] = V_7 -> V_17 [ V_18 ] ;
for ( V_62 = V_22 ; V_19 < V_20 ; V_19 ++ , V_62 ++ ) {
if ( V_7 -> V_17 [ V_62 ] == V_7 -> V_17 [ V_20 ] )
break;
V_7 -> V_17 [ V_62 ] = V_7 -> V_17 [ V_19 ] ;
V_7 -> V_23 [ V_62 ] = V_7 -> V_23 [ V_19 ] ;
}
F_110 ( V_2 , V_47 , V_7 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_24 * V_47 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_47 -> V_3 ) {
F_110 ( V_2 , V_47 , V_7 ) ;
} else {
F_111 ( V_2 , V_47 , V_7 ) ;
V_7 -> V_3 = V_47 -> V_3 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_33 ) ) ;
}
if ( V_7 -> V_4 != V_47 -> V_4 ) {
V_7 -> V_4 = V_47 -> V_4 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_34 ) ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_86 = ! ! ( V_47 -> V_65 & V_7 -> V_49 ) ;
F_113 ( V_7 ) ;
}
}
static void F_114 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_47 ;
F_41 ( V_43 ) ;
V_47 = V_7 -> V_48 ;
if ( ( V_7 -> V_4 == F_2 ( V_47 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_47 -> V_3 ) ) ||
! F_115 ( & V_47 -> V_64 ) ) {
F_43 ( V_43 ) ;
return;
}
F_112 ( V_2 , V_47 , V_7 ) ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_117 () ;
F_118 ( & V_47 -> V_64 ) ;
if ( V_2 -> V_87 == 0 ) {
F_119 ( & V_47 -> V_64 ) ;
return 0 ;
}
V_2 -> V_87 = 0 ;
if ( F_34 ( F_1 ( V_2 ) ) ) {
F_119 ( & V_47 -> V_64 ) ;
return 0 ;
}
F_73 ( V_2 ) ;
F_74 () ;
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_57 , V_2 -> V_4 , F_6 ( L_35 ) ) ;
F_119 ( & V_47 -> V_64 ) ;
F_120 ( & V_2 -> V_88 ) ;
F_121 (rsp, rnp) {
F_118 ( & V_47 -> V_64 ) ;
V_7 = F_39 ( V_2 -> V_72 ) ;
F_122 ( V_47 ) ;
V_47 -> V_65 = V_47 -> V_50 ;
F_2 ( V_47 -> V_4 ) = V_2 -> V_4 ;
F_34 ( V_47 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_47 -> V_3 ) = V_2 -> V_3 ;
if ( V_47 == V_7 -> V_48 )
F_112 ( V_2 , V_47 , V_7 ) ;
F_123 ( V_47 ) ;
F_124 ( V_2 -> V_57 , V_47 -> V_4 ,
V_47 -> V_81 , V_47 -> V_67 ,
V_47 -> V_66 , V_47 -> V_65 ) ;
F_119 ( & V_47 -> V_64 ) ;
#ifdef F_125
if ( ( F_126 () % ( V_89 + 1 ) ) == 0 &&
V_90 == V_91 )
F_127 ( 200 ) ;
#endif
F_128 () ;
}
F_129 ( & V_2 -> V_88 ) ;
return 1 ;
}
static int F_130 ( struct V_1 * V_2 , int V_92 )
{
int V_93 = V_92 ;
bool V_52 = false ;
unsigned long V_53 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
V_2 -> V_94 ++ ;
if ( V_93 == V_95 ) {
if ( F_131 ( V_2 ) ) {
V_52 = 1 ;
V_53 = V_60 - V_77 / 4 ;
}
F_132 ( V_2 , F_63 ,
& V_52 , & V_53 ) ;
F_133 ( V_2 , V_52 , V_53 ) ;
V_93 = V_96 ;
} else {
V_52 = 0 ;
F_132 ( V_2 , F_66 , & V_52 , & V_53 ) ;
}
if ( F_2 ( V_2 -> V_87 ) & V_97 ) {
F_118 ( & V_47 -> V_64 ) ;
V_2 -> V_87 &= ~ V_97 ;
F_119 ( & V_47 -> V_64 ) ;
}
return V_93 ;
}
static void F_134 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
int V_99 = 0 ;
struct V_6 * V_7 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_118 ( & V_47 -> V_64 ) ;
V_98 = V_60 - V_2 -> V_59 ;
if ( V_98 > V_2 -> V_100 )
V_2 -> V_100 = V_98 ;
F_119 ( & V_47 -> V_64 ) ;
F_121 (rsp, rnp) {
F_118 ( & V_47 -> V_64 ) ;
F_2 ( V_47 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_39 ( V_2 -> V_72 ) ;
if ( V_47 == V_7 -> V_48 )
F_112 ( V_2 , V_47 , V_7 ) ;
V_99 += F_108 ( V_2 , V_47 ) ;
F_119 ( & V_47 -> V_64 ) ;
F_128 () ;
}
V_47 = F_22 ( V_2 ) ;
F_118 ( & V_47 -> V_64 ) ;
F_135 ( V_47 , V_99 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_57 , V_2 -> V_3 , F_6 ( L_36 ) ) ;
V_2 -> V_93 = V_101 ;
V_7 = F_39 ( V_2 -> V_72 ) ;
F_111 ( V_2 , V_47 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
V_2 -> V_87 = V_102 ;
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_37 ) ) ;
}
F_119 ( & V_47 -> V_64 ) ;
}
static int T_3 F_136 ( void * V_103 )
{
int V_93 ;
int V_104 ;
unsigned long V_62 ;
int V_46 ;
struct V_1 * V_2 = V_103 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
F_137 ( V_2 -> V_105 ,
F_2 ( V_2 -> V_87 ) &
V_102 ) ;
if ( F_116 ( V_2 ) )
break;
F_128 () ;
F_138 ( V_31 ) ;
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
}
V_93 = V_95 ;
V_62 = V_106 ;
if ( V_62 > V_107 ) {
V_62 = V_107 ;
V_106 = V_107 ;
}
V_46 = 0 ;
for (; ; ) {
if ( ! V_46 )
V_2 -> V_108 = V_60 + V_62 ;
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
V_46 = F_139 ( V_2 -> V_105 ,
( ( V_104 = F_2 ( V_2 -> V_87 ) ) &
V_97 ) ||
( ! F_2 ( V_47 -> V_65 ) &&
! F_140 ( V_47 ) ) ,
V_62 ) ;
if ( ! F_2 ( V_47 -> V_65 ) &&
! F_140 ( V_47 ) )
break;
if ( F_69 ( V_60 , V_2 -> V_108 ) ||
( V_104 & V_97 ) ) {
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_93 = F_130 ( V_2 , V_93 ) ;
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
F_128 () ;
} else {
F_128 () ;
F_138 ( V_31 ) ;
F_5 ( V_2 -> V_57 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
}
V_62 = V_109 ;
if ( V_62 > V_107 ) {
V_62 = V_107 ;
V_109 = V_107 ;
} else if ( V_62 < 1 ) {
V_62 = 1 ;
V_109 = 1 ;
}
}
F_134 ( V_2 ) ;
}
}
static void F_141 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_142 ( V_111 , struct V_1 , V_112 ) ;
F_143 ( & V_2 -> V_105 ) ;
}
static void
F_106 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_113 || ! F_19 ( V_2 , V_7 ) ) {
return;
}
V_2 -> V_87 = V_102 ;
F_5 ( V_2 -> V_57 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_37 ) ) ;
if ( V_31 != V_2 -> V_113 )
F_144 ( & V_2 -> V_112 ) ;
}
static void
F_145 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_39 ( V_2 -> V_72 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_111 ( V_2 , V_47 , V_7 ) ;
F_106 ( V_2 , V_47 , V_7 ) ;
}
static void F_146 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void
F_147 ( unsigned long V_114 , struct V_1 * V_2 ,
struct V_24 * V_47 , unsigned long V_43 )
__releases( V_47 -> V_64 )
{
struct V_24 * V_115 ;
for (; ; ) {
if ( ! ( V_47 -> V_65 & V_114 ) ) {
F_80 ( & V_47 -> V_64 , V_43 ) ;
return;
}
V_47 -> V_65 &= ~ V_114 ;
F_148 ( V_2 -> V_57 , V_47 -> V_4 ,
V_114 , V_47 -> V_65 , V_47 -> V_81 ,
V_47 -> V_67 , V_47 -> V_66 ,
! ! V_47 -> V_116 ) ;
if ( V_47 -> V_65 != 0 || F_140 ( V_47 ) ) {
F_80 ( & V_47 -> V_64 , V_43 ) ;
return;
}
V_114 = V_47 -> V_49 ;
if ( V_47 -> V_117 == NULL ) {
break;
}
F_80 ( & V_47 -> V_64 , V_43 ) ;
V_115 = V_47 ;
V_47 = V_47 -> V_117 ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
F_34 ( V_115 -> V_65 ) ;
}
F_146 ( V_2 , V_43 ) ;
}
static void
F_149 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
unsigned long V_114 ;
struct V_24 * V_47 ;
V_47 = V_7 -> V_48 ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_47 -> V_4 ||
V_47 -> V_3 == V_47 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
return;
}
V_114 = V_7 -> V_49 ;
if ( ( V_47 -> V_65 & V_114 ) == 0 ) {
F_80 ( & V_47 -> V_64 , V_43 ) ;
} else {
V_7 -> V_86 = 0 ;
F_110 ( V_2 , V_47 , V_7 ) ;
F_147 ( V_114 , V_2 , V_47 , V_43 ) ;
}
}
static void
F_150 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_114 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_86 )
return;
if ( ! V_7 -> V_9 )
return;
F_149 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_151 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_47 , struct V_6 * V_7 )
{
if ( F_152 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_118 += V_7 -> V_118 ;
V_2 -> V_73 += V_7 -> V_73 ;
V_7 -> V_119 += V_7 -> V_73 ;
V_7 -> V_118 = 0 ;
F_2 ( V_7 -> V_73 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_120 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_120 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_121 = V_7 -> V_16 ;
V_2 -> V_121 = V_7 -> V_17 [ V_18 ] ;
}
F_99 ( V_7 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_6 * V_7 = F_154 ( V_2 -> V_72 ) ;
if ( F_155 ( V_2 , V_7 ) )
return;
V_7 -> V_118 += V_2 -> V_118 ;
V_7 -> V_73 += V_2 -> V_73 ;
V_7 -> V_122 += V_2 -> V_73 ;
if ( V_2 -> V_118 != V_2 -> V_73 )
F_156 () ;
V_2 -> V_118 = 0 ;
V_2 -> V_73 = 0 ;
if ( V_2 -> V_123 != NULL ) {
* V_2 -> V_121 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_123 ;
for ( V_19 = V_78 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_121 ;
V_2 -> V_123 = NULL ;
V_2 -> V_121 = & V_2 -> V_123 ;
}
if ( V_2 -> V_124 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_124 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_120 ;
V_2 -> V_124 = NULL ;
V_2 -> V_120 = & V_2 -> V_124 ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
F_158 (unsigned long mask) ;
F_158 ( struct V_6 * V_7 = F_39 ( V_2 -> V_72 ) ) ;
F_158 ( struct V_24 * V_47 = V_7 -> V_48 ) ;
F_158 ( V_114 = V_7 -> V_49 ) ;
F_5 ( V_2 -> V_57 ,
V_47 -> V_4 + 1 - ! ! ( V_47 -> V_65 & V_114 ) ,
F_6 ( L_44 ) ) ;
}
static void F_159 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned long V_114 ;
int V_125 = 0 ;
struct V_6 * V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
struct V_24 * V_47 = V_7 -> V_48 ;
F_160 ( V_47 , - 1 ) ;
F_120 ( & V_2 -> V_88 ) ;
F_78 ( & V_2 -> V_126 , V_43 ) ;
F_151 ( V_5 , V_2 , V_47 , V_7 ) ;
F_153 ( V_2 ) ;
V_114 = V_7 -> V_49 ;
do {
F_105 ( & V_47 -> V_64 ) ;
V_47 -> V_50 &= ~ V_114 ;
if ( V_47 -> V_50 != 0 ) {
if ( V_47 != V_7 -> V_48 )
F_107 ( & V_47 -> V_64 ) ;
break;
}
if ( V_47 == V_7 -> V_48 )
V_125 = F_161 ( V_2 , V_47 , V_7 ) ;
else
F_107 ( & V_47 -> V_64 ) ;
V_114 = V_47 -> V_49 ;
V_47 = V_47 -> V_117 ;
} while ( V_47 != NULL );
F_107 ( & V_2 -> V_126 ) ;
V_47 = V_7 -> V_48 ;
if ( V_125 & V_127 )
F_162 ( V_47 , V_43 ) ;
else
F_80 ( & V_47 -> V_64 , V_43 ) ;
if ( V_125 & V_128 )
F_163 ( V_2 , V_47 , true ) ;
F_29 ( V_7 -> V_73 != 0 || V_7 -> V_16 != NULL ,
L_45 ,
V_5 , V_7 -> V_73 , V_7 -> V_16 ) ;
F_99 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_129 ( & V_2 -> V_88 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
}
static void F_159 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_164 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_129 * V_130 , * V_131 , * * V_132 ;
long V_133 , V_134 , V_135 ;
int V_19 ;
if ( ! F_18 ( V_7 ) ) {
F_165 ( V_2 -> V_57 , V_7 -> V_118 , V_7 -> V_73 , 0 ) ;
F_166 ( V_2 -> V_57 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_167 () , F_25 ( V_31 ) ,
F_168 () ) ;
return;
}
F_41 ( V_43 ) ;
F_34 ( F_71 ( F_27 () ) ) ;
V_133 = V_7 -> V_136 ;
F_165 ( V_2 -> V_57 , V_7 -> V_118 , V_7 -> V_73 , V_133 ) ;
V_131 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_132 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_78 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_43 ( V_43 ) ;
V_134 = V_135 = 0 ;
while ( V_131 ) {
V_130 = V_131 -> V_130 ;
F_169 ( V_130 ) ;
F_170 ( V_131 ) ;
if ( F_171 ( V_2 -> V_57 , V_131 ) )
V_135 ++ ;
V_131 = V_130 ;
if ( ++ V_134 >= V_133 &&
( F_167 () ||
( ! F_25 ( V_31 ) && ! F_168 () ) ) )
break;
}
F_41 ( V_43 ) ;
F_166 ( V_2 -> V_57 , V_134 , ! ! V_131 , F_167 () ,
F_25 ( V_31 ) ,
F_168 () ) ;
if ( V_131 != NULL ) {
* V_132 = V_7 -> V_16 ;
V_7 -> V_16 = V_131 ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_132 ;
else
break;
}
F_172 () ;
V_7 -> V_118 -= V_135 ;
F_2 ( V_7 -> V_73 ) -= V_134 ;
V_7 -> V_137 += V_134 ;
if ( V_7 -> V_136 == V_138 && V_7 -> V_73 <= V_139 )
V_7 -> V_136 = V_136 ;
if ( V_7 -> V_73 == 0 && V_7 -> V_140 != 0 ) {
V_7 -> V_140 = 0 ;
V_7 -> V_141 = V_2 -> V_94 ;
} else if ( V_7 -> V_73 < V_7 -> V_140 - V_142 )
V_7 -> V_140 = V_7 -> V_73 ;
F_34 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_73 == 0 ) ) ;
F_43 ( V_43 ) ;
if ( F_18 ( V_7 ) )
F_173 () ;
}
void F_174 ( int V_5 , int V_29 )
{
F_9 ( F_6 ( L_46 ) ) ;
F_175 () ;
if ( V_29 || F_61 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_176 () ) {
F_7 ( V_5 ) ;
}
F_177 ( V_5 ) ;
if ( F_178 ( V_5 ) )
F_173 () ;
F_9 ( F_6 ( L_47 ) ) ;
}
static void F_132 ( struct V_1 * V_2 ,
int (* F_179)( struct V_6 * V_2 , bool * V_52 ,
unsigned long * V_53 ) ,
bool * V_52 , unsigned long * V_53 )
{
unsigned long V_143 ;
int V_5 ;
unsigned long V_43 ;
unsigned long V_114 ;
struct V_24 * V_47 ;
F_77 (rsp, rnp) {
F_128 () ;
V_114 = 0 ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
if ( ! F_1 ( V_2 ) ) {
F_80 ( & V_47 -> V_64 , V_43 ) ;
return;
}
if ( V_47 -> V_65 == 0 ) {
F_180 ( V_47 , V_43 ) ;
continue;
}
V_5 = V_47 -> V_67 ;
V_143 = 1 ;
for (; V_5 <= V_47 -> V_66 ; V_5 ++ , V_143 <<= 1 ) {
if ( ( V_47 -> V_65 & V_143 ) != 0 ) {
if ( ( V_47 -> V_50 & V_143 ) != 0 )
* V_52 = 0 ;
if ( F_179 ( F_88 ( V_2 -> V_72 , V_5 ) , V_52 , V_53 ) )
V_114 |= V_143 ;
}
}
if ( V_114 != 0 ) {
F_147 ( V_114 , V_2 , V_47 , V_43 ) ;
continue;
}
F_80 ( & V_47 -> V_64 , V_43 ) ;
}
V_47 = F_22 ( V_2 ) ;
if ( V_47 -> V_65 == 0 ) {
F_78 ( & V_47 -> V_64 , V_43 ) ;
F_180 ( V_47 , V_43 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
bool V_46 ;
struct V_24 * V_47 ;
struct V_24 * V_144 = NULL ;
V_47 = F_88 ( V_2 -> V_72 , F_181 () ) -> V_48 ;
for (; V_47 != NULL ; V_47 = V_47 -> V_117 ) {
V_46 = ( F_2 ( V_2 -> V_87 ) & V_97 ) ||
! F_115 ( & V_47 -> V_145 ) ;
if ( V_144 != NULL )
F_107 ( & V_144 -> V_145 ) ;
if ( V_46 ) {
V_2 -> V_146 ++ ;
return;
}
V_144 = V_47 ;
}
F_78 ( & V_144 -> V_64 , V_43 ) ;
F_107 ( & V_144 -> V_145 ) ;
if ( F_2 ( V_2 -> V_87 ) & V_97 ) {
V_2 -> V_146 ++ ;
F_80 ( & V_144 -> V_64 , V_43 ) ;
return;
}
V_2 -> V_87 |= V_97 ;
F_80 ( & V_144 -> V_64 , V_43 ) ;
F_143 ( & V_2 -> V_105 ) ;
}
static void
F_182 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_154 ( V_2 -> V_72 ) ;
F_34 ( V_7 -> V_147 == 0 ) ;
F_150 ( V_2 , V_7 ) ;
F_41 ( V_43 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_105 ( & F_22 ( V_2 ) -> V_64 ) ;
F_145 ( V_2 ) ;
F_80 ( & F_22 ( V_2 ) -> V_64 , V_43 ) ;
} else {
F_43 ( V_43 ) ;
}
if ( F_18 ( V_7 ) )
F_183 ( V_2 , V_7 ) ;
}
static void F_184 ( struct V_148 * V_149 )
{
struct V_1 * V_2 ;
if ( F_71 ( F_27 () ) )
return;
F_9 ( F_6 ( L_48 ) ) ;
F_98 (rsp)
F_182 ( V_2 ) ;
F_9 ( F_6 ( L_49 ) ) ;
}
static void F_183 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_185 ( ! F_2 ( V_51 ) ) )
return;
if ( F_186 ( ! V_2 -> V_150 ) ) {
F_164 ( V_2 , V_7 ) ;
return;
}
F_187 () ;
}
static void F_173 ( void )
{
if ( F_188 ( F_27 () ) )
F_189 ( V_151 ) ;
}
static void F_190 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_129 * V_152 , unsigned long V_43 )
{
if ( ! F_56 () && F_188 ( F_27 () ) )
F_173 () ;
if ( F_191 ( V_43 ) || F_71 ( F_27 () ) )
return;
if ( F_185 ( V_7 -> V_73 > V_7 -> V_140 + V_142 ) ) {
F_114 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_24 * V_82 = F_22 ( V_2 ) ;
F_105 ( & V_82 -> V_64 ) ;
F_145 ( V_2 ) ;
F_107 ( & V_82 -> V_64 ) ;
} else {
V_7 -> V_136 = V_138 ;
if ( V_2 -> V_94 == V_7 -> V_141 &&
* V_7 -> V_17 [ V_18 ] != V_152 )
F_14 ( V_2 ) ;
V_7 -> V_141 = V_2 -> V_94 ;
V_7 -> V_140 = V_7 -> V_73 ;
}
}
}
static void F_192 ( struct V_129 * V_153 )
{
}
static void
F_193 ( struct V_129 * V_152 , void (* F_194)( struct V_129 * V_154 ) ,
struct V_1 * V_2 , int V_5 , bool V_155 )
{
unsigned long V_43 ;
struct V_6 * V_7 ;
F_34 ( ( unsigned long ) V_152 & 0x3 ) ;
if ( F_195 ( V_152 ) ) {
F_2 ( V_152 -> F_194 ) = F_192 ;
F_29 ( 1 , L_50 ) ;
return;
}
V_152 -> F_194 = F_194 ;
V_152 -> V_130 = NULL ;
F_41 ( V_43 ) ;
V_7 = F_39 ( V_2 -> V_72 ) ;
if ( F_185 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_156 ;
if ( V_5 != - 1 )
V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
V_156 = ! F_196 ( V_7 , V_152 , V_155 ) ;
F_34 ( V_156 ) ;
F_43 ( V_43 ) ;
return;
}
F_2 ( V_7 -> V_73 ) ++ ;
if ( V_155 )
V_7 -> V_118 ++ ;
else
F_156 () ;
F_172 () ;
* V_7 -> V_17 [ V_20 ] = V_152 ;
V_7 -> V_17 [ V_20 ] = & V_152 -> V_130 ;
if ( F_197 ( ( unsigned long ) F_194 ) )
F_198 ( V_2 -> V_57 , V_152 , ( unsigned long ) F_194 ,
V_7 -> V_118 , V_7 -> V_73 ) ;
else
F_199 ( V_2 -> V_57 , V_152 , V_7 -> V_118 , V_7 -> V_73 ) ;
F_190 ( V_2 , V_7 , V_152 , V_43 ) ;
F_43 ( V_43 ) ;
}
void F_200 ( struct V_129 * V_152 , void (* F_194)( struct V_129 * V_154 ) )
{
F_193 ( V_152 , F_194 , & V_11 , - 1 , 0 ) ;
}
void F_201 ( struct V_129 * V_152 , void (* F_194)( struct V_129 * V_154 ) )
{
F_193 ( V_152 , F_194 , & V_12 , - 1 , 0 ) ;
}
static inline int F_202 ( void )
{
int V_46 ;
F_203 () ;
F_57 () ;
V_46 = F_204 () <= 1 ;
F_58 () ;
return V_46 ;
}
void F_205 ( void )
{
F_36 ( ! F_37 ( & V_39 ) &&
! F_37 ( & V_38 ) &&
! F_37 ( & V_40 ) ,
L_51 ) ;
if ( F_202 () )
return;
if ( V_157 )
F_206 () ;
else
F_207 ( F_200 ) ;
}
void F_208 ( void )
{
F_36 ( ! F_37 ( & V_39 ) &&
! F_37 ( & V_38 ) &&
! F_37 ( & V_40 ) ,
L_52 ) ;
if ( F_202 () )
return;
if ( V_157 )
F_209 () ;
else
F_207 ( F_201 ) ;
}
static int F_210 ( void * V_158 )
{
F_172 () ;
return 0 ;
}
void F_206 ( void )
{
long V_159 , V_80 , V_56 ;
int V_160 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_69 ( ( V_161 ) F_211 ( & V_2 -> V_162 ) ,
( V_161 ) F_211 ( & V_2 -> V_163 ) +
V_77 / 8 ) ) {
F_205 () ;
F_212 ( & V_2 -> V_164 ) ;
return;
}
V_56 = F_213 ( & V_2 -> V_162 ) ;
V_159 = V_56 ;
F_214 () ;
F_34 ( F_71 ( F_181 () ) ) ;
while ( F_215 ( V_165 ,
F_210 ,
NULL ) == - V_166 ) {
F_216 () ;
F_212 ( & V_2 -> V_167 ) ;
V_80 = F_211 ( & V_2 -> V_163 ) ;
if ( F_69 ( ( V_161 ) V_80 , ( V_161 ) V_159 ) ) {
F_31 () ;
F_212 ( & V_2 -> V_168 ) ;
return;
}
if ( V_160 ++ < 10 ) {
F_127 ( V_160 * F_204 () ) ;
} else {
F_207 ( F_200 ) ;
F_212 ( & V_2 -> V_169 ) ;
return;
}
V_80 = F_211 ( & V_2 -> V_163 ) ;
if ( F_69 ( ( V_161 ) V_80 , ( V_161 ) V_159 ) ) {
F_31 () ;
F_212 ( & V_2 -> V_170 ) ;
return;
}
F_214 () ;
V_56 = F_211 ( & V_2 -> V_162 ) ;
F_172 () ;
}
F_212 ( & V_2 -> V_171 ) ;
do {
F_212 ( & V_2 -> V_172 ) ;
V_80 = F_211 ( & V_2 -> V_163 ) ;
if ( F_69 ( ( V_161 ) V_80 , ( V_161 ) V_56 ) ) {
F_31 () ;
F_212 ( & V_2 -> V_173 ) ;
break;
}
} while ( F_217 ( & V_2 -> V_163 , V_80 , V_56 ) != V_80 );
F_212 ( & V_2 -> V_174 ) ;
F_216 () ;
}
static int F_218 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_47 = V_7 -> V_48 ;
V_7 -> V_175 ++ ;
F_95 ( V_2 , V_7 ) ;
if ( V_51 &&
V_7 -> V_86 && ! V_7 -> V_9 ) {
V_7 -> V_176 ++ ;
} else if ( V_7 -> V_86 && V_7 -> V_9 ) {
V_7 -> V_177 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_178 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_179 ++ ;
return 1 ;
}
if ( F_2 ( V_47 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_180 ++ ;
return 1 ;
}
if ( F_2 ( V_47 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_181 ++ ;
return 1 ;
}
V_7 -> V_182 ++ ;
return 0 ;
}
static int F_178 ( int V_5 )
{
struct V_1 * V_2 ;
F_98 (rsp)
if ( F_218 ( V_2 , F_88 ( V_2 -> V_72 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_219 ( int V_5 , bool * V_183 )
{
bool V_184 = true ;
bool V_185 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_98 (rsp) {
V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
if ( ! V_7 -> V_16 )
continue;
V_185 = true ;
if ( V_7 -> V_73 != V_7 -> V_118 || ! V_183 ) {
V_184 = false ;
break;
}
}
if ( V_183 )
* V_183 = V_184 ;
return V_185 ;
}
static void F_220 ( struct V_1 * V_2 , const char * V_80 ,
int V_5 , unsigned long V_186 )
{
F_221 ( V_2 -> V_57 , V_80 , V_5 ,
F_35 ( & V_2 -> V_187 ) , V_186 ) ;
}
static void F_222 ( struct V_129 * V_153 )
{
struct V_6 * V_7 = F_142 ( V_153 , struct V_6 , V_188 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_223 ( & V_2 -> V_187 ) ) {
F_220 ( V_2 , L_53 , - 1 , V_2 -> V_189 ) ;
F_224 ( & V_2 -> V_190 ) ;
} else {
F_220 ( V_2 , L_54 , - 1 , V_2 -> V_189 ) ;
}
}
static void F_225 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_154 ( V_2 -> V_72 ) ;
F_220 ( V_2 , L_55 , - 1 , V_2 -> V_189 ) ;
F_32 ( & V_2 -> V_187 ) ;
V_2 -> V_191 ( & V_7 -> V_188 , F_222 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_56 = F_2 ( V_2 -> V_189 ) ;
unsigned long V_192 ;
F_220 ( V_2 , L_56 , - 1 , V_56 ) ;
F_120 ( & V_2 -> V_193 ) ;
F_172 () ;
V_192 = V_2 -> V_189 ;
F_220 ( V_2 , L_57 , - 1 , V_192 ) ;
if ( F_69 ( V_192 , ( V_56 + 3 ) & ~ 0x1 ) ) {
F_220 ( V_2 , L_58 , - 1 , V_192 ) ;
F_172 () ;
F_129 ( & V_2 -> V_193 ) ;
return;
}
F_2 ( V_2 -> V_189 ) ++ ;
F_34 ( ( V_2 -> V_189 & 0x1 ) != 1 ) ;
F_220 ( V_2 , L_59 , - 1 , V_2 -> V_189 ) ;
F_172 () ;
F_227 ( & V_2 -> V_190 ) ;
F_228 ( & V_2 -> V_187 , 1 ) ;
F_214 () ;
F_87 (cpu) {
if ( ! F_188 ( V_5 ) && ! F_152 ( V_5 ) )
continue;
V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
if ( F_152 ( V_5 ) ) {
F_220 ( V_2 , L_60 , V_5 ,
V_2 -> V_189 ) ;
F_32 ( & V_2 -> V_187 ) ;
F_193 ( & V_7 -> V_188 , F_222 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_73 ) ) {
F_220 ( V_2 , L_61 , V_5 ,
V_2 -> V_189 ) ;
F_229 ( V_5 , F_225 , V_2 , 1 ) ;
} else {
F_220 ( V_2 , L_62 , V_5 ,
V_2 -> V_189 ) ;
}
}
F_216 () ;
if ( F_223 ( & V_2 -> V_187 ) )
F_224 ( & V_2 -> V_190 ) ;
F_172 () ;
F_2 ( V_2 -> V_189 ) ++ ;
F_34 ( ( V_2 -> V_189 & 0x1 ) != 0 ) ;
F_220 ( V_2 , L_63 , - 1 , V_2 -> V_189 ) ;
F_172 () ;
F_230 ( & V_2 -> V_190 ) ;
F_129 ( & V_2 -> V_193 ) ;
}
void F_231 ( void )
{
F_226 ( & V_12 ) ;
}
void F_232 ( void )
{
F_226 ( & V_11 ) ;
}
static void T_4
F_233 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_7 -> V_49 = 1UL << ( V_5 - V_7 -> V_48 -> V_67 ) ;
F_99 ( V_7 ) ;
V_7 -> V_118 = 0 ;
F_2 ( V_7 -> V_73 ) = 0 ;
V_7 -> V_37 = & F_4 ( V_26 , V_5 ) ;
F_34 ( V_7 -> V_37 -> V_30 != V_44 ) ;
F_34 ( F_35 ( & V_7 -> V_37 -> V_37 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_234 ( V_7 ) ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
}
static void
F_235 ( int V_5 , struct V_1 * V_2 , int V_194 )
{
unsigned long V_43 ;
unsigned long V_114 ;
struct V_6 * V_7 = F_88 ( V_2 -> V_72 , V_5 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_120 ( & V_2 -> V_88 ) ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_7 -> V_147 = 1 ;
V_7 -> V_194 = V_194 ;
V_7 -> V_140 = 0 ;
V_7 -> V_141 = V_2 -> V_94 ;
V_7 -> V_136 = V_136 ;
F_99 ( V_7 ) ;
V_7 -> V_37 -> V_30 = V_44 ;
F_236 ( V_7 -> V_37 ) ;
F_228 ( & V_7 -> V_37 -> V_37 ,
( F_35 ( & V_7 -> V_37 -> V_37 ) & ~ 0x1 ) + 1 ) ;
F_107 ( & V_47 -> V_64 ) ;
V_47 = V_7 -> V_48 ;
V_114 = V_7 -> V_49 ;
do {
F_105 ( & V_47 -> V_64 ) ;
V_47 -> V_50 |= V_114 ;
V_114 = V_47 -> V_49 ;
if ( V_47 == V_7 -> V_48 ) {
V_7 -> V_4 = V_47 -> V_3 ;
V_7 -> V_3 = V_47 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_86 = 0 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_64 ) ) ;
}
F_107 ( & V_47 -> V_64 ) ;
V_47 = V_47 -> V_117 ;
} while ( V_47 != NULL && ! ( V_47 -> V_50 & V_114 ) );
F_43 ( V_43 ) ;
F_129 ( & V_2 -> V_88 ) ;
}
static void F_237 ( int V_5 )
{
struct V_1 * V_2 ;
F_98 (rsp)
F_235 ( V_5 , V_2 ,
strcmp ( V_2 -> V_57 , L_65 ) == 0 ) ;
}
static int F_238 ( struct V_195 * V_196 ,
unsigned long V_197 , void * V_198 )
{
long V_5 = ( long ) V_198 ;
struct V_6 * V_7 = F_88 ( V_1 -> V_72 , V_5 ) ;
struct V_24 * V_47 = V_7 -> V_48 ;
struct V_1 * V_2 ;
F_9 ( F_6 ( L_66 ) ) ;
switch ( V_197 ) {
case V_199 :
case V_200 :
F_237 ( V_5 ) ;
F_239 ( V_5 ) ;
break;
case V_201 :
case V_202 :
F_160 ( V_47 , - 1 ) ;
break;
case V_203 :
F_160 ( V_47 , V_5 ) ;
break;
case V_204 :
case V_205 :
F_98 (rsp)
F_157 ( V_2 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
case V_209 :
F_98 (rsp)
F_159 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_9 ( F_6 ( L_67 ) ) ;
return V_210 ;
}
static int F_240 ( struct V_195 * V_196 ,
unsigned long V_197 , void * V_198 )
{
switch ( V_197 ) {
case V_211 :
case V_212 :
if ( V_213 <= 256 )
V_157 = 1 ;
break;
case V_214 :
case V_215 :
V_157 = 0 ;
break;
default:
break;
}
return V_210 ;
}
static int T_4 F_241 ( void )
{
unsigned long V_43 ;
struct V_24 * V_47 ;
struct V_1 * V_2 ;
struct V_32 * V_216 ;
F_98 (rsp) {
V_216 = F_242 ( F_136 , V_2 , L_68 , V_2 -> V_57 ) ;
F_243 ( F_244 ( V_216 ) ) ;
V_47 = F_22 ( V_2 ) ;
F_78 ( & V_47 -> V_64 , V_43 ) ;
V_2 -> V_113 = V_216 ;
F_80 ( & V_47 -> V_64 , V_43 ) ;
F_245 ( V_2 ) ;
}
return 0 ;
}
void F_246 ( void )
{
F_247 ( F_204 () != 1 ) ;
F_247 ( F_248 () > 0 ) ;
V_217 = 1 ;
}
static void T_4 F_249 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = V_218 - 1 ; V_19 > 0 ; V_19 -- )
V_2 -> V_219 [ V_19 ] = V_220 ;
V_2 -> V_219 [ 0 ] = V_221 ;
}
static void T_4 F_249 ( struct V_1 * V_2 )
{
int V_222 ;
int V_223 ;
int V_19 ;
V_223 = V_213 ;
for ( V_19 = V_218 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_222 = V_2 -> V_224 [ V_19 ] ;
V_2 -> V_219 [ V_19 ] = ( V_223 + V_222 - 1 ) / V_222 ;
V_223 = V_222 ;
}
}
static void T_4 F_250 ( struct V_1 * V_2 ,
struct V_6 T_5 * V_72 )
{
static char * V_225 [] = { L_69 ,
L_70 ,
L_71 ,
L_72 } ;
static char * V_226 [] = { L_73 ,
L_74 ,
L_75 ,
L_76 } ;
int V_227 = 1 ;
int V_19 ;
int V_62 ;
struct V_24 * V_47 ;
F_251 ( V_228 > F_252 ( V_225 ) ) ;
if ( V_218 > V_229 )
F_253 ( L_77 ) ;
for ( V_19 = 0 ; V_19 < V_218 ; V_19 ++ )
V_2 -> V_224 [ V_19 ] = V_230 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_218 ; V_19 ++ )
V_2 -> V_81 [ V_19 ] = V_2 -> V_81 [ V_19 - 1 ] + V_2 -> V_224 [ V_19 - 1 ] ;
F_249 ( V_2 ) ;
for ( V_19 = V_218 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_227 *= V_2 -> V_219 [ V_19 ] ;
V_47 = V_2 -> V_81 [ V_19 ] ;
for ( V_62 = 0 ; V_62 < V_2 -> V_224 [ V_19 ] ; V_62 ++ , V_47 ++ ) {
F_254 ( & V_47 -> V_64 ) ;
F_255 ( & V_47 -> V_64 ,
& V_231 [ V_19 ] , V_225 [ V_19 ] ) ;
F_254 ( & V_47 -> V_145 ) ;
F_255 ( & V_47 -> V_145 ,
& V_232 [ V_19 ] , V_226 [ V_19 ] ) ;
V_47 -> V_4 = V_2 -> V_4 ;
V_47 -> V_3 = V_2 -> V_3 ;
V_47 -> V_65 = 0 ;
V_47 -> V_50 = 0 ;
V_47 -> V_67 = V_62 * V_227 ;
V_47 -> V_66 = ( V_62 + 1 ) * V_227 - 1 ;
if ( V_47 -> V_66 >= V_233 )
V_47 -> V_66 = V_233 - 1 ;
if ( V_19 == 0 ) {
V_47 -> V_234 = 0 ;
V_47 -> V_49 = 0 ;
V_47 -> V_117 = NULL ;
} else {
V_47 -> V_234 = V_62 % V_2 -> V_219 [ V_19 - 1 ] ;
V_47 -> V_49 = 1UL << V_47 -> V_234 ;
V_47 -> V_117 = V_2 -> V_81 [ V_19 - 1 ] +
V_62 / V_2 -> V_219 [ V_19 - 1 ] ;
}
V_47 -> V_81 = V_19 ;
F_256 ( & V_47 -> V_235 ) ;
F_257 ( V_47 ) ;
}
}
V_2 -> V_72 = V_72 ;
F_258 ( & V_2 -> V_105 ) ;
F_259 ( & V_2 -> V_112 , F_141 ) ;
V_47 = V_2 -> V_81 [ V_218 - 1 ] ;
F_87 (i) {
while ( V_19 > V_47 -> V_66 )
V_47 ++ ;
F_88 ( V_2 -> V_72 , V_19 ) -> V_48 = V_47 ;
F_233 ( V_19 , V_2 ) ;
}
F_260 ( & V_2 -> V_236 , & V_237 ) ;
}
static void T_4 F_261 ( void )
{
V_161 V_238 ;
int V_19 ;
int V_62 ;
int V_239 = V_213 ;
int V_240 [ V_228 + 1 ] ;
V_238 = V_241 + V_213 / V_242 ;
if ( V_106 == V_77 )
V_106 = V_238 ;
if ( V_109 == V_77 )
V_109 = V_238 ;
if ( V_221 == V_243 &&
V_213 == V_233 )
return;
V_240 [ 0 ] = 1 ;
V_240 [ 1 ] = V_221 ;
for ( V_19 = 2 ; V_19 <= V_228 ; V_19 ++ )
V_240 [ V_19 ] = V_240 [ V_19 - 1 ] * V_220 ;
if ( V_221 < V_243 ||
V_221 > sizeof( unsigned long ) * 8 ||
V_239 > V_240 [ V_228 ] ) {
F_247 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_228 ; V_19 ++ )
if ( V_239 <= V_240 [ V_19 ] ) {
for ( V_62 = 0 ; V_62 <= V_19 ; V_62 ++ )
V_230 [ V_62 ] =
F_262 ( V_239 , V_240 [ V_19 - V_62 ] ) ;
V_218 = V_19 ;
for ( V_62 = V_19 + 1 ; V_62 <= V_228 ; V_62 ++ )
V_230 [ V_62 ] = 0 ;
break;
}
V_89 = 0 ;
for ( V_19 = 0 ; V_19 <= V_228 ; V_19 ++ )
V_89 += V_230 [ V_19 ] ;
V_89 -= V_239 ;
}
void T_4 F_263 ( void )
{
int V_5 ;
F_264 () ;
F_261 () ;
F_250 ( & V_12 , & V_10 ) ;
F_250 ( & V_11 , & V_8 ) ;
F_265 () ;
F_266 ( V_151 , F_184 ) ;
F_267 ( F_238 , 0 ) ;
F_268 ( F_240 , 0 ) ;
F_269 (cpu)
F_238 ( NULL , V_199 , ( void * ) ( long ) V_5 ) ;
}
