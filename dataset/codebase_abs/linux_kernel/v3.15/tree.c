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
struct V_1 * V_2 ;
struct V_6 * V_7 ;
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
F_30 (rsp) {
V_7 = F_31 ( V_2 -> V_37 ) ;
F_32 ( V_7 ) ;
}
F_33 ( F_27 () ) ;
F_34 () ;
F_35 ( & V_27 -> V_38 ) ;
F_36 () ;
F_37 ( F_38 ( & V_27 -> V_38 ) & 0x1 ) ;
F_39 ( ! F_40 ( & V_39 ) ,
L_9 ) ;
F_39 ( ! F_40 ( & V_40 ) ,
L_10 ) ;
F_39 ( ! F_40 ( & V_41 ) ,
L_11 ) ;
}
static void F_41 ( bool V_29 )
{
long long V_28 ;
struct V_26 * V_27 ;
V_27 = F_31 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
F_37 ( ( V_28 & V_42 ) == 0 ) ;
if ( ( V_28 & V_42 ) == V_43 ) {
V_27 -> V_30 = 0 ;
F_23 ( V_27 , V_28 , V_29 ) ;
} else {
V_27 -> V_30 -= V_43 ;
}
}
void F_42 ( void )
{
unsigned long V_44 ;
F_43 ( V_44 ) ;
F_41 ( false ) ;
F_44 ( F_31 ( & V_26 ) , 0 ) ;
F_45 ( V_44 ) ;
}
void F_46 ( void )
{
F_41 ( 1 ) ;
}
void F_47 ( void )
{
unsigned long V_44 ;
long long V_28 ;
struct V_26 * V_27 ;
F_43 ( V_44 ) ;
V_27 = F_31 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 -- ;
F_37 ( V_27 -> V_30 < 0 ) ;
if ( V_27 -> V_30 )
F_24 ( F_6 ( L_12 ) , V_28 , V_27 -> V_30 ) ;
else
F_23 ( V_27 , V_28 , true ) ;
F_44 ( V_27 , 1 ) ;
F_45 ( V_44 ) ;
}
static void F_48 ( struct V_26 * V_27 , long long V_28 ,
int V_29 )
{
F_34 () ;
F_35 ( & V_27 -> V_38 ) ;
F_36 () ;
F_37 ( ! ( F_38 ( & V_27 -> V_38 ) & 0x1 ) ) ;
F_49 ( F_27 () ) ;
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
static void F_50 ( bool V_29 )
{
struct V_26 * V_27 ;
long long V_28 ;
V_27 = F_31 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
F_37 ( V_28 < 0 ) ;
if ( V_28 & V_42 ) {
V_27 -> V_30 += V_43 ;
} else {
V_27 -> V_30 = V_45 ;
F_48 ( V_27 , V_28 , V_29 ) ;
}
}
void F_51 ( void )
{
unsigned long V_44 ;
F_43 ( V_44 ) ;
F_50 ( false ) ;
F_52 ( F_31 ( & V_26 ) , 0 ) ;
F_45 ( V_44 ) ;
}
void F_53 ( void )
{
F_50 ( 1 ) ;
}
void F_54 ( void )
{
unsigned long V_44 ;
struct V_26 * V_27 ;
long long V_28 ;
F_43 ( V_44 ) ;
V_27 = F_31 ( & V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 ++ ;
F_37 ( V_27 -> V_30 == 0 ) ;
if ( V_28 )
F_24 ( F_6 ( L_15 ) , V_28 , V_27 -> V_30 ) ;
else
F_48 ( V_27 , V_28 , true ) ;
F_52 ( V_27 , 1 ) ;
F_45 ( V_44 ) ;
}
void F_55 ( void )
{
struct V_26 * V_27 = F_31 ( & V_26 ) ;
if ( V_27 -> V_46 == 0 &&
( F_38 ( & V_27 -> V_38 ) & 0x1 ) )
return;
V_27 -> V_46 ++ ;
F_34 () ;
F_35 ( & V_27 -> V_38 ) ;
F_36 () ;
F_37 ( ! ( F_38 ( & V_27 -> V_38 ) & 0x1 ) ) ;
}
void F_56 ( void )
{
struct V_26 * V_27 = F_31 ( & V_26 ) ;
if ( V_27 -> V_46 == 0 ||
-- V_27 -> V_46 != 0 )
return;
F_34 () ;
F_35 ( & V_27 -> V_38 ) ;
F_36 () ;
F_37 ( F_38 ( & V_27 -> V_38 ) & 0x1 ) ;
}
bool T_2 F_57 ( void )
{
return F_38 ( F_31 ( & V_26 . V_38 ) ) & 0x1 ;
}
bool T_2 F_58 ( void )
{
int V_47 ;
F_59 () ;
V_47 = F_57 () ;
F_60 () ;
return V_47 ;
}
bool F_61 ( void )
{
struct V_6 * V_7 ;
struct V_24 * V_48 ;
bool V_47 ;
if ( F_62 () )
return true ;
F_59 () ;
V_7 = F_31 ( & V_8 ) ;
V_48 = V_7 -> V_49 ;
V_47 = ( V_7 -> V_50 & V_48 -> V_51 ) ||
! V_52 ;
F_60 () ;
return V_47 ;
}
static int F_63 ( void )
{
return F_64 ( V_26 . V_30 ) <= 1 ;
}
static int F_65 ( struct V_6 * V_7 ,
bool * V_53 , unsigned long * V_54 )
{
V_7 -> V_55 = F_66 ( 0 , & V_7 -> V_38 -> V_38 ) ;
F_67 ( V_7 , V_53 , V_54 ) ;
return ( V_7 -> V_55 & 0x1 ) == 0 ;
}
static int F_68 ( struct V_6 * V_7 ,
bool * V_53 , unsigned long * V_54 )
{
unsigned int V_56 ;
unsigned int V_57 ;
V_56 = ( unsigned int ) F_66 ( 0 , & V_7 -> V_38 -> V_38 ) ;
V_57 = ( unsigned int ) V_7 -> V_55 ;
if ( ( V_56 & 0x1 ) == 0 || F_69 ( V_56 , V_57 + 2 ) ) {
F_70 ( V_7 -> V_2 -> V_58 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_16 ) ) ;
V_7 -> V_59 ++ ;
return 1 ;
}
if ( F_71 ( V_7 -> V_2 -> V_60 + 2 , V_61 ) )
return 0 ;
F_72 () ;
if ( F_73 ( V_7 -> V_5 ) ) {
F_70 ( V_7 -> V_2 -> V_58 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
V_7 -> V_62 ++ ;
return 1 ;
}
F_74 ( V_7 -> V_5 ) ;
if ( V_7 -> V_2 == V_1 &&
F_71 ( V_61 , V_7 -> V_2 -> V_63 ) ) {
V_7 -> V_2 -> V_63 += 5 ;
F_75 ( V_7 -> V_5 ) ;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_64 = V_61 ;
unsigned long j1 ;
V_2 -> V_60 = V_64 ;
F_77 () ;
j1 = F_78 () ;
V_2 -> V_65 = V_64 + j1 ;
V_2 -> V_63 = V_64 + j1 / 2 ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_44 ;
struct V_24 * V_48 ;
F_80 (rsp, rnp) {
F_81 ( & V_48 -> V_66 , V_44 ) ;
if ( V_48 -> V_67 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_68 - V_48 -> V_69 ; V_5 ++ )
if ( V_48 -> V_67 & ( 1UL << V_5 ) )
F_82 ( V_48 -> V_69 + V_5 ) ;
}
F_83 ( & V_48 -> V_66 , V_44 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
int V_5 ;
long V_70 ;
unsigned long V_44 ;
int V_71 = 0 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
long V_72 = 0 ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_70 = V_61 - V_2 -> V_65 ;
if ( V_70 < V_73 || ! F_1 ( V_2 ) ) {
F_83 ( & V_48 -> V_66 , V_44 ) ;
return;
}
V_2 -> V_65 = V_61 + 3 * F_78 () + 3 ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
F_85 ( L_18 ,
V_2 -> V_58 ) ;
F_86 () ;
F_80 (rsp, rnp) {
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_71 += F_87 ( V_48 ) ;
if ( V_48 -> V_67 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_48 -> V_68 - V_48 -> V_69 ; V_5 ++ )
if ( V_48 -> V_67 & ( 1UL << V_5 ) ) {
F_88 ( V_2 ,
V_48 -> V_69 + V_5 ) ;
V_71 ++ ;
}
}
F_83 ( & V_48 -> V_66 , V_44 ) ;
}
V_48 = F_22 ( V_2 ) ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_71 += F_87 ( V_48 ) ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
F_89 () ;
F_90 (cpu)
V_72 += F_91 ( V_2 -> V_37 , V_5 ) -> V_74 ;
F_92 ( L_19 ,
F_27 () , ( long ) ( V_61 - V_2 -> V_60 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_72 ) ;
if ( V_71 == 0 )
F_85 ( L_20 ) ;
else if ( ! F_93 () )
F_79 ( V_2 ) ;
F_94 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_44 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
long V_72 = 0 ;
F_85 ( L_21 , V_2 -> V_58 ) ;
F_86 () ;
F_88 ( V_2 , F_27 () ) ;
F_89 () ;
F_90 (cpu)
V_72 += F_91 ( V_2 -> V_37 , V_5 ) -> V_74 ;
F_92 ( L_22 ,
V_61 - V_2 -> V_60 , V_2 -> V_4 , V_2 -> V_3 , V_72 ) ;
if ( ! F_93 () )
F_96 () ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
if ( F_71 ( V_61 , V_2 -> V_65 ) )
V_2 -> V_65 = V_61 +
3 * F_78 () + 3 ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
F_75 ( F_27 () ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_75 ;
unsigned long V_64 ;
unsigned long V_76 ;
struct V_24 * V_48 ;
if ( V_77 || ! F_1 ( V_2 ) )
return;
V_64 = V_61 ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_98 () ;
V_76 = F_2 ( V_2 -> V_65 ) ;
F_98 () ;
V_75 = F_2 ( V_2 -> V_60 ) ;
F_98 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_71 ( V_3 , V_4 ) ||
F_21 ( V_64 , V_76 ) ||
F_71 ( V_75 , V_76 ) )
return;
V_48 = V_7 -> V_49 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_48 -> V_67 ) & V_7 -> V_50 ) ) {
F_95 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_71 ( V_64 , V_76 + V_73 ) ) {
F_84 ( V_2 ) ;
}
}
void F_99 ( void )
{
struct V_1 * V_2 ;
F_30 (rsp)
V_2 -> V_65 = V_61 + V_78 / 2 ;
}
static void F_100 ( struct V_6 * V_7 )
{
int V_19 ;
if ( F_101 ( V_7 ) )
return;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_79 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
}
static unsigned long F_102 ( struct V_1 * V_2 ,
struct V_24 * V_48 )
{
if ( F_22 ( V_2 ) == V_48 && V_48 -> V_4 == V_48 -> V_3 )
return V_48 -> V_3 + 1 ;
return V_48 -> V_3 + 2 ;
}
static void F_103 ( struct V_24 * V_48 , struct V_6 * V_7 ,
unsigned long V_80 , const char * V_81 )
{
F_104 ( V_7 -> V_2 -> V_58 , V_48 -> V_4 ,
V_48 -> V_3 , V_80 , V_48 -> V_82 ,
V_48 -> V_69 , V_48 -> V_68 , V_81 ) ;
}
static unsigned long V_33
F_105 ( struct V_24 * V_48 , struct V_6 * V_7 )
{
unsigned long V_80 ;
int V_19 ;
struct V_24 * V_83 = F_22 ( V_7 -> V_2 ) ;
V_80 = F_102 ( V_7 -> V_2 , V_48 ) ;
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_23 ) ) ;
if ( V_48 -> V_84 [ V_80 & 0x1 ] ) {
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_24 ) ) ;
return V_80 ;
}
if ( V_48 -> V_4 != V_48 -> V_3 ||
F_2 ( V_48 -> V_4 ) != F_2 ( V_48 -> V_3 ) ) {
V_48 -> V_84 [ V_80 & 0x1 ] ++ ;
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_25 ) ) ;
return V_80 ;
}
if ( V_48 != V_83 ) {
F_106 ( & V_83 -> V_66 ) ;
F_107 () ;
}
V_80 = F_102 ( V_7 -> V_2 , V_83 ) ;
for ( V_19 = V_18 ; V_19 < V_20 ; V_19 ++ )
if ( F_21 ( V_80 , V_7 -> V_23 [ V_19 ] ) )
V_7 -> V_23 [ V_19 ] = V_80 ;
if ( V_83 -> V_84 [ V_80 & 0x1 ] ) {
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_26 ) ) ;
goto V_85;
}
V_83 -> V_84 [ V_80 & 0x1 ] ++ ;
if ( V_83 -> V_4 != V_83 -> V_3 ) {
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_27 ) ) ;
} else {
F_103 ( V_48 , V_7 , V_80 , F_6 ( L_28 ) ) ;
F_108 ( V_7 -> V_2 , V_83 , V_7 ) ;
}
V_85:
if ( V_48 != V_83 )
F_109 ( & V_83 -> V_66 ) ;
return V_80 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_24 * V_48 )
{
int V_80 = V_48 -> V_3 ;
int V_86 ;
struct V_6 * V_7 = F_31 ( V_2 -> V_37 ) ;
F_111 ( V_2 , V_48 ) ;
V_48 -> V_84 [ V_80 & 0x1 ] = 0 ;
V_86 = V_48 -> V_84 [ ( V_80 + 1 ) & 0x1 ] ;
F_103 ( V_48 , V_7 , V_80 ,
V_86 ? F_6 ( L_29 ) : F_6 ( L_30 ) ) ;
return V_86 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
unsigned long V_80 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_80 = F_102 ( V_2 , V_48 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_71 ( V_7 -> V_23 [ V_19 ] , V_80 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_80 ;
}
F_105 ( V_48 , V_7 ) ;
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_58 , V_7 -> V_4 , F_6 ( L_31 ) ) ;
else
F_5 ( V_2 -> V_58 , V_7 -> V_4 , F_6 ( L_32 ) ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
int V_19 , V_64 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_21 ( V_48 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
break;
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_19 ] ;
}
for ( V_64 = V_22 ; V_64 < V_19 ; V_64 ++ )
V_7 -> V_17 [ V_64 ] = V_7 -> V_17 [ V_18 ] ;
for ( V_64 = V_22 ; V_19 < V_20 ; V_19 ++ , V_64 ++ ) {
if ( V_7 -> V_17 [ V_64 ] == V_7 -> V_17 [ V_20 ] )
break;
V_7 -> V_17 [ V_64 ] = V_7 -> V_17 [ V_19 ] ;
V_7 -> V_23 [ V_64 ] = V_7 -> V_23 [ V_19 ] ;
}
F_112 ( V_2 , V_48 , V_7 ) ;
}
static void F_114 ( struct V_1 * V_2 , struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_48 -> V_3 ) {
F_112 ( V_2 , V_48 , V_7 ) ;
} else {
F_113 ( V_2 , V_48 , V_7 ) ;
V_7 -> V_3 = V_48 -> V_3 ;
F_5 ( V_2 -> V_58 , V_7 -> V_4 , F_6 ( L_33 ) ) ;
}
if ( V_7 -> V_4 != V_48 -> V_4 ) {
V_7 -> V_4 = V_48 -> V_4 ;
F_5 ( V_2 -> V_58 , V_7 -> V_4 , F_6 ( L_34 ) ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_87 = ! ! ( V_48 -> V_67 & V_7 -> V_50 ) ;
F_115 ( V_7 ) ;
}
}
static void F_116 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_44 ;
struct V_24 * V_48 ;
F_43 ( V_44 ) ;
V_48 = V_7 -> V_49 ;
if ( ( V_7 -> V_4 == F_2 ( V_48 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_48 -> V_3 ) ) ||
! F_117 ( & V_48 -> V_66 ) ) {
F_45 ( V_44 ) ;
return;
}
F_107 () ;
F_114 ( V_2 , V_48 , V_7 ) ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
F_119 () ;
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
if ( V_2 -> V_88 == 0 ) {
F_121 ( & V_48 -> V_66 ) ;
return 0 ;
}
V_2 -> V_88 = 0 ;
if ( F_37 ( F_1 ( V_2 ) ) ) {
F_121 ( & V_48 -> V_66 ) ;
return 0 ;
}
F_76 ( V_2 ) ;
F_122 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_58 , V_2 -> V_4 , F_6 ( L_35 ) ) ;
F_121 ( & V_48 -> V_66 ) ;
F_123 ( & V_2 -> V_89 ) ;
F_107 () ;
F_124 (rsp, rnp) {
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
V_7 = F_31 ( V_2 -> V_37 ) ;
F_125 ( V_48 ) ;
V_48 -> V_67 = V_48 -> V_51 ;
F_2 ( V_48 -> V_4 ) = V_2 -> V_4 ;
F_37 ( V_48 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_3 ;
if ( V_48 == V_7 -> V_49 )
F_114 ( V_2 , V_48 , V_7 ) ;
F_126 ( V_48 ) ;
F_127 ( V_2 -> V_58 , V_48 -> V_4 ,
V_48 -> V_82 , V_48 -> V_69 ,
V_48 -> V_68 , V_48 -> V_67 ) ;
F_121 ( & V_48 -> V_66 ) ;
#ifdef F_128
if ( ( F_129 () % ( V_90 + 1 ) ) == 0 &&
V_91 == V_92 )
F_130 ( 200 ) ;
#endif
F_131 () ;
}
F_132 ( & V_2 -> V_89 ) ;
return 1 ;
}
static int F_133 ( struct V_1 * V_2 , int V_93 )
{
int V_94 = V_93 ;
bool V_53 = false ;
unsigned long V_54 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
V_2 -> V_95 ++ ;
if ( V_94 == V_96 ) {
if ( F_134 ( V_2 ) ) {
V_53 = 1 ;
V_54 = V_61 - V_78 / 4 ;
}
F_135 ( V_2 , F_65 ,
& V_53 , & V_54 ) ;
F_136 ( V_2 , V_53 , V_54 ) ;
V_94 = V_97 ;
} else {
V_53 = 0 ;
F_135 ( V_2 , F_68 , & V_53 , & V_54 ) ;
}
if ( F_2 ( V_2 -> V_88 ) & V_98 ) {
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
V_2 -> V_88 &= ~ V_98 ;
F_121 ( & V_48 -> V_66 ) ;
}
return V_94 ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned long V_99 ;
int V_100 = 0 ;
struct V_6 * V_7 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
V_99 = V_61 - V_2 -> V_60 ;
if ( V_99 > V_2 -> V_101 )
V_2 -> V_101 = V_99 ;
F_121 ( & V_48 -> V_66 ) ;
F_124 (rsp, rnp) {
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
F_2 ( V_48 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_31 ( V_2 -> V_37 ) ;
if ( V_48 == V_7 -> V_49 )
F_114 ( V_2 , V_48 , V_7 ) ;
V_100 += F_110 ( V_2 , V_48 ) ;
F_121 ( & V_48 -> V_66 ) ;
F_131 () ;
}
V_48 = F_22 ( V_2 ) ;
F_120 ( & V_48 -> V_66 ) ;
F_107 () ;
F_138 ( V_48 , V_100 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_58 , V_2 -> V_3 , F_6 ( L_36 ) ) ;
V_2 -> V_94 = V_102 ;
V_7 = F_31 ( V_2 -> V_37 ) ;
F_113 ( V_2 , V_48 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
V_2 -> V_88 = V_103 ;
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_37 ) ) ;
}
F_121 ( & V_48 -> V_66 ) ;
}
static int T_3 F_139 ( void * V_104 )
{
int V_94 ;
int V_105 ;
unsigned long V_64 ;
int V_47 ;
struct V_1 * V_2 = V_104 ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
F_140 ( V_2 -> V_106 ,
F_2 ( V_2 -> V_88 ) &
V_103 ) ;
if ( F_118 ( V_2 ) )
break;
F_131 () ;
F_141 ( V_31 ) ;
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
}
V_94 = V_96 ;
V_64 = V_107 ;
if ( V_64 > V_108 ) {
V_64 = V_108 ;
V_107 = V_108 ;
}
V_47 = 0 ;
for (; ; ) {
if ( ! V_47 )
V_2 -> V_109 = V_61 + V_64 ;
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
V_47 = F_142 ( V_2 -> V_106 ,
( ( V_105 = F_2 ( V_2 -> V_88 ) ) &
V_98 ) ||
( ! F_2 ( V_48 -> V_67 ) &&
! F_143 ( V_48 ) ) ,
V_64 ) ;
if ( ! F_2 ( V_48 -> V_67 ) &&
! F_143 ( V_48 ) )
break;
if ( F_71 ( V_61 , V_2 -> V_109 ) ||
( V_105 & V_98 ) ) {
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_94 = F_133 ( V_2 , V_94 ) ;
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
F_131 () ;
} else {
F_131 () ;
F_141 ( V_31 ) ;
F_5 ( V_2 -> V_58 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
}
V_64 = V_110 ;
if ( V_64 > V_108 ) {
V_64 = V_108 ;
V_110 = V_108 ;
} else if ( V_64 < 1 ) {
V_64 = 1 ;
V_110 = 1 ;
}
}
F_137 ( V_2 ) ;
}
}
static void F_144 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_145 ( V_112 , struct V_1 , V_113 ) ;
F_146 ( & V_2 -> V_106 ) ;
}
static void
F_108 ( struct V_1 * V_2 , struct V_24 * V_48 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_114 || ! F_19 ( V_2 , V_7 ) ) {
return;
}
V_2 -> V_88 = V_103 ;
F_5 ( V_2 -> V_58 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_37 ) ) ;
if ( V_31 != V_2 -> V_114 )
F_147 ( & V_2 -> V_113 ) ;
}
static void
F_148 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_31 ( V_2 -> V_37 ) ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
F_113 ( V_2 , V_48 , V_7 ) ;
F_108 ( V_2 , V_48 , V_7 ) ;
}
static void F_149 ( struct V_1 * V_2 , unsigned long V_44 )
__releases( rcu_get_root( V_2 )->lock
static void
F_150 ( unsigned long V_115 , struct V_1 * V_2 ,
struct V_24 * V_48 , unsigned long V_44 )
__releases( V_48 -> V_66 )
{
struct V_24 * V_116 ;
for (; ; ) {
if ( ! ( V_48 -> V_67 & V_115 ) ) {
F_83 ( & V_48 -> V_66 , V_44 ) ;
return;
}
V_48 -> V_67 &= ~ V_115 ;
F_151 ( V_2 -> V_58 , V_48 -> V_4 ,
V_115 , V_48 -> V_67 , V_48 -> V_82 ,
V_48 -> V_69 , V_48 -> V_68 ,
! ! V_48 -> V_117 ) ;
if ( V_48 -> V_67 != 0 || F_143 ( V_48 ) ) {
F_83 ( & V_48 -> V_66 , V_44 ) ;
return;
}
V_115 = V_48 -> V_50 ;
if ( V_48 -> V_118 == NULL ) {
break;
}
F_83 ( & V_48 -> V_66 , V_44 ) ;
V_116 = V_48 ;
V_48 = V_48 -> V_118 ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
F_107 () ;
F_37 ( V_116 -> V_67 ) ;
}
F_149 ( V_2 , V_44 ) ;
}
static void
F_152 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_44 ;
unsigned long V_115 ;
struct V_24 * V_48 ;
V_48 = V_7 -> V_49 ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
F_107 () ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_48 -> V_4 ||
V_48 -> V_3 == V_48 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
return;
}
V_115 = V_7 -> V_50 ;
if ( ( V_48 -> V_67 & V_115 ) == 0 ) {
F_83 ( & V_48 -> V_66 , V_44 ) ;
} else {
V_7 -> V_87 = 0 ;
F_112 ( V_2 , V_48 , V_7 ) ;
F_150 ( V_115 , V_2 , V_48 , V_44 ) ;
}
}
static void
F_153 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_116 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_87 )
return;
if ( ! V_7 -> V_9 )
return;
F_152 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_154 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_48 , struct V_6 * V_7 )
{
if ( F_155 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_119 += V_7 -> V_119 ;
V_2 -> V_74 += V_7 -> V_74 ;
V_7 -> V_120 += V_7 -> V_74 ;
V_7 -> V_119 = 0 ;
F_2 ( V_7 -> V_74 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_121 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_121 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_122 = V_7 -> V_16 ;
V_2 -> V_122 = V_7 -> V_17 [ V_18 ] ;
}
F_100 ( V_7 ) ;
}
static void F_156 ( struct V_1 * V_2 , unsigned long V_44 )
{
int V_19 ;
struct V_6 * V_7 = F_157 ( V_2 -> V_37 ) ;
if ( F_158 ( V_2 , V_7 , V_44 ) )
return;
V_7 -> V_119 += V_2 -> V_119 ;
V_7 -> V_74 += V_2 -> V_74 ;
V_7 -> V_123 += V_2 -> V_74 ;
if ( V_2 -> V_119 != V_2 -> V_74 )
F_159 () ;
V_2 -> V_119 = 0 ;
V_2 -> V_74 = 0 ;
if ( V_2 -> V_124 != NULL ) {
* V_2 -> V_122 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_124 ;
for ( V_19 = V_79 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_122 ;
V_2 -> V_124 = NULL ;
V_2 -> V_122 = & V_2 -> V_124 ;
}
if ( V_2 -> V_125 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_125 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_121 ;
V_2 -> V_125 = NULL ;
V_2 -> V_121 = & V_2 -> V_125 ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
F_161 (unsigned long mask) ;
F_161 ( struct V_6 * V_7 = F_31 ( V_2 -> V_37 ) ) ;
F_161 ( struct V_24 * V_48 = V_7 -> V_49 ) ;
F_161 ( V_115 = V_7 -> V_50 ) ;
F_5 ( V_2 -> V_58 ,
V_48 -> V_4 + 1 - ! ! ( V_48 -> V_67 & V_115 ) ,
F_6 ( L_44 ) ) ;
}
static void F_162 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_44 ;
unsigned long V_115 ;
int V_126 = 0 ;
struct V_6 * V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
F_163 ( V_48 , - 1 ) ;
F_123 ( & V_2 -> V_89 ) ;
F_81 ( & V_2 -> V_127 , V_44 ) ;
F_154 ( V_5 , V_2 , V_48 , V_7 ) ;
F_156 ( V_2 , V_44 ) ;
V_115 = V_7 -> V_50 ;
do {
F_106 ( & V_48 -> V_66 ) ;
F_107 () ;
V_48 -> V_51 &= ~ V_115 ;
if ( V_48 -> V_51 != 0 ) {
if ( V_48 != V_7 -> V_49 )
F_109 ( & V_48 -> V_66 ) ;
break;
}
if ( V_48 == V_7 -> V_49 )
V_126 = F_164 ( V_2 , V_48 , V_7 ) ;
else
F_109 ( & V_48 -> V_66 ) ;
V_115 = V_48 -> V_50 ;
V_48 = V_48 -> V_118 ;
} while ( V_48 != NULL );
F_109 ( & V_2 -> V_127 ) ;
V_48 = V_7 -> V_49 ;
if ( V_126 & V_128 )
F_165 ( V_48 , V_44 ) ;
else
F_83 ( & V_48 -> V_66 , V_44 ) ;
if ( V_126 & V_129 )
F_166 ( V_2 , V_48 , true ) ;
F_29 ( V_7 -> V_74 != 0 || V_7 -> V_16 != NULL ,
L_45 ,
V_5 , V_7 -> V_74 , V_7 -> V_16 ) ;
F_100 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_132 ( & V_2 -> V_89 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
}
static void F_162 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_167 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_44 ;
struct V_130 * V_131 , * V_132 , * * V_133 ;
long V_134 , V_135 , V_136 ;
int V_19 ;
if ( ! F_18 ( V_7 ) ) {
F_168 ( V_2 -> V_58 , V_7 -> V_119 , V_7 -> V_74 , 0 ) ;
F_169 ( V_2 -> V_58 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_170 () , F_25 ( V_31 ) ,
F_171 () ) ;
return;
}
F_43 ( V_44 ) ;
F_37 ( F_73 ( F_27 () ) ) ;
V_134 = V_7 -> V_137 ;
F_168 ( V_2 -> V_58 , V_7 -> V_119 , V_7 -> V_74 , V_134 ) ;
V_132 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_133 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_79 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_45 ( V_44 ) ;
V_135 = V_136 = 0 ;
while ( V_132 ) {
V_131 = V_132 -> V_131 ;
F_172 ( V_131 ) ;
F_173 ( V_132 ) ;
if ( F_174 ( V_2 -> V_58 , V_132 ) )
V_136 ++ ;
V_132 = V_131 ;
if ( ++ V_135 >= V_134 &&
( F_170 () ||
( ! F_25 ( V_31 ) && ! F_171 () ) ) )
break;
}
F_43 ( V_44 ) ;
F_169 ( V_2 -> V_58 , V_135 , ! ! V_132 , F_170 () ,
F_25 ( V_31 ) ,
F_171 () ) ;
if ( V_132 != NULL ) {
* V_133 = V_7 -> V_16 ;
V_7 -> V_16 = V_132 ;
for ( V_19 = 0 ; V_19 < V_79 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_133 ;
else
break;
}
F_175 () ;
V_7 -> V_119 -= V_136 ;
F_2 ( V_7 -> V_74 ) -= V_135 ;
V_7 -> V_138 += V_135 ;
if ( V_7 -> V_137 == V_139 && V_7 -> V_74 <= V_140 )
V_7 -> V_137 = V_137 ;
if ( V_7 -> V_74 == 0 && V_7 -> V_141 != 0 ) {
V_7 -> V_141 = 0 ;
V_7 -> V_142 = V_2 -> V_95 ;
} else if ( V_7 -> V_74 < V_7 -> V_141 - V_143 )
V_7 -> V_141 = V_7 -> V_74 ;
F_37 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_74 == 0 ) ) ;
F_45 ( V_44 ) ;
if ( F_18 ( V_7 ) )
F_176 () ;
}
void F_177 ( int V_5 , int V_29 )
{
F_9 ( F_6 ( L_46 ) ) ;
F_178 () ;
if ( V_29 || F_63 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_179 () ) {
F_7 ( V_5 ) ;
}
F_180 ( V_5 ) ;
if ( F_181 ( V_5 ) )
F_176 () ;
F_9 ( F_6 ( L_47 ) ) ;
}
static void F_135 ( struct V_1 * V_2 ,
int (* F_182)( struct V_6 * V_2 , bool * V_53 ,
unsigned long * V_54 ) ,
bool * V_53 , unsigned long * V_54 )
{
unsigned long V_144 ;
int V_5 ;
unsigned long V_44 ;
unsigned long V_115 ;
struct V_24 * V_48 ;
F_80 (rsp, rnp) {
F_131 () ;
V_115 = 0 ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
F_107 () ;
if ( ! F_1 ( V_2 ) ) {
F_83 ( & V_48 -> V_66 , V_44 ) ;
return;
}
if ( V_48 -> V_67 == 0 ) {
F_183 ( V_48 , V_44 ) ;
continue;
}
V_5 = V_48 -> V_69 ;
V_144 = 1 ;
for (; V_5 <= V_48 -> V_68 ; V_5 ++ , V_144 <<= 1 ) {
if ( ( V_48 -> V_67 & V_144 ) != 0 ) {
if ( ( V_48 -> V_51 & V_144 ) != 0 )
* V_53 = 0 ;
if ( F_182 ( F_91 ( V_2 -> V_37 , V_5 ) , V_53 , V_54 ) )
V_115 |= V_144 ;
}
}
if ( V_115 != 0 ) {
F_150 ( V_115 , V_2 , V_48 , V_44 ) ;
continue;
}
F_83 ( & V_48 -> V_66 , V_44 ) ;
}
V_48 = F_22 ( V_2 ) ;
if ( V_48 -> V_67 == 0 ) {
F_81 ( & V_48 -> V_66 , V_44 ) ;
F_107 () ;
F_183 ( V_48 , V_44 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
bool V_47 ;
struct V_24 * V_48 ;
struct V_24 * V_145 = NULL ;
V_48 = F_91 ( V_2 -> V_37 , F_184 () ) -> V_49 ;
for (; V_48 != NULL ; V_48 = V_48 -> V_118 ) {
V_47 = ( F_2 ( V_2 -> V_88 ) & V_98 ) ||
! F_117 ( & V_48 -> V_146 ) ;
if ( V_145 != NULL )
F_109 ( & V_145 -> V_146 ) ;
if ( V_47 ) {
F_2 ( V_2 -> V_147 ) ++ ;
return;
}
V_145 = V_48 ;
}
F_81 ( & V_145 -> V_66 , V_44 ) ;
F_107 () ;
F_109 ( & V_145 -> V_146 ) ;
if ( F_2 ( V_2 -> V_88 ) & V_98 ) {
F_2 ( V_2 -> V_147 ) ++ ;
F_83 ( & V_145 -> V_66 , V_44 ) ;
return;
}
V_2 -> V_88 |= V_98 ;
F_83 ( & V_145 -> V_66 , V_44 ) ;
F_146 ( & V_2 -> V_106 ) ;
}
static void
F_185 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_6 * V_7 = F_157 ( V_2 -> V_37 ) ;
F_37 ( V_7 -> V_148 == 0 ) ;
F_153 ( V_2 , V_7 ) ;
F_43 ( V_44 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_106 ( & F_22 ( V_2 ) -> V_66 ) ;
F_148 ( V_2 ) ;
F_83 ( & F_22 ( V_2 ) -> V_66 , V_44 ) ;
} else {
F_45 ( V_44 ) ;
}
if ( F_18 ( V_7 ) )
F_186 ( V_2 , V_7 ) ;
F_32 ( V_7 ) ;
}
static void F_187 ( struct V_149 * V_150 )
{
struct V_1 * V_2 ;
if ( F_73 ( F_27 () ) )
return;
F_9 ( F_6 ( L_48 ) ) ;
F_30 (rsp)
F_185 ( V_2 ) ;
F_9 ( F_6 ( L_49 ) ) ;
}
static void F_186 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_188 ( ! F_2 ( V_52 ) ) )
return;
if ( F_189 ( ! V_2 -> V_151 ) ) {
F_167 ( V_2 , V_7 ) ;
return;
}
F_190 () ;
}
static void F_176 ( void )
{
if ( F_191 ( F_27 () ) )
F_192 ( V_152 ) ;
}
static void F_193 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_130 * V_153 , unsigned long V_44 )
{
if ( ! F_58 () && F_191 ( F_27 () ) )
F_176 () ;
if ( F_194 ( V_44 ) || F_73 ( F_27 () ) )
return;
if ( F_188 ( V_7 -> V_74 > V_7 -> V_141 + V_143 ) ) {
F_116 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_24 * V_83 = F_22 ( V_2 ) ;
F_106 ( & V_83 -> V_66 ) ;
F_107 () ;
F_148 ( V_2 ) ;
F_109 ( & V_83 -> V_66 ) ;
} else {
V_7 -> V_137 = V_139 ;
if ( V_2 -> V_95 == V_7 -> V_142 &&
* V_7 -> V_17 [ V_18 ] != V_153 )
F_14 ( V_2 ) ;
V_7 -> V_142 = V_2 -> V_95 ;
V_7 -> V_141 = V_7 -> V_74 ;
}
}
}
static void F_195 ( struct V_130 * V_154 )
{
}
static void
F_196 ( struct V_130 * V_153 , void (* F_197)( struct V_130 * V_155 ) ,
struct V_1 * V_2 , int V_5 , bool V_156 )
{
unsigned long V_44 ;
struct V_6 * V_7 ;
F_37 ( ( unsigned long ) V_153 & 0x3 ) ;
if ( F_198 ( V_153 ) ) {
F_2 ( V_153 -> F_197 ) = F_195 ;
F_29 ( 1 , L_50 ) ;
return;
}
V_153 -> F_197 = F_197 ;
V_153 -> V_131 = NULL ;
F_43 ( V_44 ) ;
V_7 = F_31 ( V_2 -> V_37 ) ;
if ( F_188 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_157 ;
if ( V_5 != - 1 )
V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
V_157 = ! F_199 ( V_7 , V_153 , V_156 , V_44 ) ;
F_37 ( V_157 ) ;
F_45 ( V_44 ) ;
return;
}
F_2 ( V_7 -> V_74 ) ++ ;
if ( V_156 )
V_7 -> V_119 ++ ;
else
F_159 () ;
F_175 () ;
* V_7 -> V_17 [ V_20 ] = V_153 ;
V_7 -> V_17 [ V_20 ] = & V_153 -> V_131 ;
if ( F_200 ( ( unsigned long ) F_197 ) )
F_201 ( V_2 -> V_58 , V_153 , ( unsigned long ) F_197 ,
V_7 -> V_119 , V_7 -> V_74 ) ;
else
F_202 ( V_2 -> V_58 , V_153 , V_7 -> V_119 , V_7 -> V_74 ) ;
F_193 ( V_2 , V_7 , V_153 , V_44 ) ;
F_45 ( V_44 ) ;
}
void F_203 ( struct V_130 * V_153 , void (* F_197)( struct V_130 * V_155 ) )
{
F_196 ( V_153 , F_197 , & V_11 , - 1 , 0 ) ;
}
void F_204 ( struct V_130 * V_153 , void (* F_197)( struct V_130 * V_155 ) )
{
F_196 ( V_153 , F_197 , & V_12 , - 1 , 0 ) ;
}
static inline int F_205 ( void )
{
int V_47 ;
F_206 () ;
F_59 () ;
V_47 = F_207 () <= 1 ;
F_60 () ;
return V_47 ;
}
void F_208 ( void )
{
F_39 ( ! F_40 ( & V_40 ) &&
! F_40 ( & V_39 ) &&
! F_40 ( & V_41 ) ,
L_51 ) ;
if ( F_205 () )
return;
if ( V_158 )
F_209 () ;
else
F_210 ( F_203 ) ;
}
void F_211 ( void )
{
F_39 ( ! F_40 ( & V_40 ) &&
! F_40 ( & V_39 ) &&
! F_40 ( & V_41 ) ,
L_52 ) ;
if ( F_205 () )
return;
if ( V_158 )
F_212 () ;
else
F_210 ( F_204 ) ;
}
unsigned long F_213 ( void )
{
F_175 () ;
return F_214 ( & V_1 -> V_4 ) ;
}
void F_215 ( unsigned long V_159 )
{
unsigned long V_160 ;
V_160 = F_214 ( & V_1 -> V_3 ) ;
if ( F_71 ( V_159 , V_160 ) )
F_216 () ;
}
static int F_217 ( void * V_161 )
{
F_175 () ;
return 0 ;
}
void F_209 ( void )
{
long V_162 , V_81 , V_57 ;
int V_163 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_71 ( ( V_164 ) F_218 ( & V_2 -> V_165 ) ,
( V_164 ) F_218 ( & V_2 -> V_166 ) +
V_78 / 8 ) ) {
F_208 () ;
F_219 ( & V_2 -> V_167 ) ;
return;
}
V_57 = F_220 ( & V_2 -> V_165 ) ;
V_162 = V_57 ;
F_221 () ;
F_37 ( F_73 ( F_184 () ) ) ;
while ( F_222 ( V_168 ,
F_217 ,
NULL ) == - V_169 ) {
F_223 () ;
F_219 ( & V_2 -> V_170 ) ;
V_81 = F_218 ( & V_2 -> V_166 ) ;
if ( F_71 ( ( V_164 ) V_81 , ( V_164 ) V_162 ) ) {
F_34 () ;
F_219 ( & V_2 -> V_171 ) ;
return;
}
if ( V_163 ++ < 10 ) {
F_130 ( V_163 * F_207 () ) ;
} else {
F_210 ( F_203 ) ;
F_219 ( & V_2 -> V_172 ) ;
return;
}
V_81 = F_218 ( & V_2 -> V_166 ) ;
if ( F_71 ( ( V_164 ) V_81 , ( V_164 ) V_162 ) ) {
F_34 () ;
F_219 ( & V_2 -> V_173 ) ;
return;
}
F_221 () ;
V_57 = F_218 ( & V_2 -> V_165 ) ;
F_175 () ;
}
F_219 ( & V_2 -> V_174 ) ;
do {
F_219 ( & V_2 -> V_175 ) ;
V_81 = F_218 ( & V_2 -> V_166 ) ;
if ( F_71 ( ( V_164 ) V_81 , ( V_164 ) V_57 ) ) {
F_34 () ;
F_219 ( & V_2 -> V_176 ) ;
break;
}
} while ( F_224 ( & V_2 -> V_166 , V_81 , V_57 ) != V_81 );
F_219 ( & V_2 -> V_177 ) ;
F_223 () ;
}
static int F_225 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_48 = V_7 -> V_49 ;
V_7 -> V_178 ++ ;
F_97 ( V_2 , V_7 ) ;
if ( F_226 ( V_2 ) )
return 0 ;
if ( V_52 &&
V_7 -> V_87 && ! V_7 -> V_9 ) {
V_7 -> V_179 ++ ;
} else if ( V_7 -> V_87 && V_7 -> V_9 ) {
V_7 -> V_180 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_181 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_182 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_183 ++ ;
return 1 ;
}
if ( F_2 ( V_48 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_184 ++ ;
return 1 ;
}
if ( F_227 ( V_7 ) ) {
V_7 -> V_185 ++ ;
return 1 ;
}
V_7 -> V_186 ++ ;
return 0 ;
}
static int F_181 ( int V_5 )
{
struct V_1 * V_2 ;
F_30 (rsp)
if ( F_225 ( V_2 , F_91 ( V_2 -> V_37 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int V_33 F_228 ( int V_5 , bool * V_187 )
{
bool V_188 = true ;
bool V_189 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_30 (rsp) {
V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
if ( ! V_7 -> V_16 )
continue;
V_189 = true ;
if ( V_7 -> V_74 != V_7 -> V_119 || ! V_187 ) {
V_188 = false ;
break;
}
}
if ( V_187 )
* V_187 = V_188 ;
return V_189 ;
}
static void F_229 ( struct V_1 * V_2 , const char * V_81 ,
int V_5 , unsigned long V_190 )
{
F_230 ( V_2 -> V_58 , V_81 , V_5 ,
F_38 ( & V_2 -> V_191 ) , V_190 ) ;
}
static void F_231 ( struct V_130 * V_154 )
{
struct V_6 * V_7 = F_145 ( V_154 , struct V_6 , V_192 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_232 ( & V_2 -> V_191 ) ) {
F_229 ( V_2 , L_53 , - 1 , V_2 -> V_193 ) ;
F_233 ( & V_2 -> V_194 ) ;
} else {
F_229 ( V_2 , L_54 , - 1 , V_2 -> V_193 ) ;
}
}
static void F_234 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_157 ( V_2 -> V_37 ) ;
F_229 ( V_2 , L_55 , - 1 , V_2 -> V_193 ) ;
F_35 ( & V_2 -> V_191 ) ;
V_2 -> V_195 ( & V_7 -> V_192 , F_231 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_57 = F_2 ( V_2 -> V_193 ) ;
unsigned long V_196 ;
F_229 ( V_2 , L_56 , - 1 , V_57 ) ;
F_123 ( & V_2 -> V_197 ) ;
F_175 () ;
V_196 = V_2 -> V_193 ;
F_229 ( V_2 , L_57 , - 1 , V_196 ) ;
if ( F_71 ( V_196 , ( V_57 + 3 ) & ~ 0x1 ) ) {
F_229 ( V_2 , L_58 , - 1 , V_196 ) ;
F_175 () ;
F_132 ( & V_2 -> V_197 ) ;
return;
}
F_2 ( V_2 -> V_193 ) ++ ;
F_37 ( ( V_2 -> V_193 & 0x1 ) != 1 ) ;
F_229 ( V_2 , L_59 , - 1 , V_2 -> V_193 ) ;
F_175 () ;
F_236 ( & V_2 -> V_194 ) ;
F_237 ( & V_2 -> V_191 , 1 ) ;
F_221 () ;
F_90 (cpu) {
if ( ! F_191 ( V_5 ) && ! F_155 ( V_5 ) )
continue;
V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
if ( F_155 ( V_5 ) ) {
F_229 ( V_2 , L_60 , V_5 ,
V_2 -> V_193 ) ;
F_35 ( & V_2 -> V_191 ) ;
F_196 ( & V_7 -> V_192 , F_231 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_74 ) ) {
F_229 ( V_2 , L_61 , V_5 ,
V_2 -> V_193 ) ;
F_238 ( V_5 , F_234 , V_2 , 1 ) ;
} else {
F_229 ( V_2 , L_62 , V_5 ,
V_2 -> V_193 ) ;
}
}
F_223 () ;
if ( F_232 ( & V_2 -> V_191 ) )
F_233 ( & V_2 -> V_194 ) ;
F_175 () ;
F_2 ( V_2 -> V_193 ) ++ ;
F_37 ( ( V_2 -> V_193 & 0x1 ) != 0 ) ;
F_229 ( V_2 , L_63 , - 1 , V_2 -> V_193 ) ;
F_175 () ;
F_239 ( & V_2 -> V_194 ) ;
F_132 ( & V_2 -> V_197 ) ;
}
void F_240 ( void )
{
F_235 ( & V_12 ) ;
}
void F_241 ( void )
{
F_235 ( & V_11 ) ;
}
static void T_4
F_242 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_6 * V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_7 -> V_50 = 1UL << ( V_5 - V_7 -> V_49 -> V_69 ) ;
F_100 ( V_7 ) ;
V_7 -> V_119 = 0 ;
F_2 ( V_7 -> V_74 ) = 0 ;
V_7 -> V_38 = & F_4 ( V_26 , V_5 ) ;
F_37 ( V_7 -> V_38 -> V_30 != V_45 ) ;
F_37 ( F_38 ( & V_7 -> V_38 -> V_38 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_243 ( V_7 ) ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
}
static void
F_244 ( int V_5 , struct V_1 * V_2 , int V_198 )
{
unsigned long V_44 ;
unsigned long V_115 ;
struct V_6 * V_7 = F_91 ( V_2 -> V_37 , V_5 ) ;
struct V_24 * V_48 = F_22 ( V_2 ) ;
F_123 ( & V_2 -> V_89 ) ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_7 -> V_148 = 1 ;
V_7 -> V_198 = V_198 ;
V_7 -> V_141 = 0 ;
V_7 -> V_142 = V_2 -> V_95 ;
V_7 -> V_137 = V_137 ;
F_100 ( V_7 ) ;
V_7 -> V_38 -> V_30 = V_45 ;
F_245 ( V_7 -> V_38 ) ;
F_237 ( & V_7 -> V_38 -> V_38 ,
( F_38 ( & V_7 -> V_38 -> V_38 ) & ~ 0x1 ) + 1 ) ;
F_109 ( & V_48 -> V_66 ) ;
V_48 = V_7 -> V_49 ;
V_115 = V_7 -> V_50 ;
do {
F_106 ( & V_48 -> V_66 ) ;
V_48 -> V_51 |= V_115 ;
V_115 = V_48 -> V_50 ;
if ( V_48 == V_7 -> V_49 ) {
V_7 -> V_4 = V_48 -> V_3 ;
V_7 -> V_3 = V_48 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_87 = 0 ;
F_5 ( V_2 -> V_58 , V_7 -> V_4 , F_6 ( L_64 ) ) ;
}
F_109 ( & V_48 -> V_66 ) ;
V_48 = V_48 -> V_118 ;
} while ( V_48 != NULL && ! ( V_48 -> V_51 & V_115 ) );
F_45 ( V_44 ) ;
F_132 ( & V_2 -> V_89 ) ;
}
static void F_246 ( int V_5 )
{
struct V_1 * V_2 ;
F_30 (rsp)
F_244 ( V_5 , V_2 ,
strcmp ( V_2 -> V_58 , L_65 ) == 0 ) ;
}
static int F_247 ( struct V_199 * V_200 ,
unsigned long V_201 , void * V_202 )
{
long V_5 = ( long ) V_202 ;
struct V_6 * V_7 = F_91 ( V_1 -> V_37 , V_5 ) ;
struct V_24 * V_48 = V_7 -> V_49 ;
struct V_1 * V_2 ;
F_9 ( F_6 ( L_66 ) ) ;
switch ( V_201 ) {
case V_203 :
case V_204 :
F_246 ( V_5 ) ;
F_248 ( V_5 ) ;
break;
case V_205 :
case V_206 :
F_163 ( V_48 , - 1 ) ;
break;
case V_207 :
F_163 ( V_48 , V_5 ) ;
break;
case V_208 :
case V_209 :
F_30 (rsp)
F_160 ( V_2 ) ;
break;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
F_30 (rsp)
F_162 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_9 ( F_6 ( L_67 ) ) ;
return V_214 ;
}
static int F_249 ( struct V_199 * V_200 ,
unsigned long V_201 , void * V_202 )
{
switch ( V_201 ) {
case V_215 :
case V_216 :
if ( V_217 <= 256 )
V_158 = 1 ;
break;
case V_218 :
case V_219 :
V_158 = 0 ;
break;
default:
break;
}
return V_214 ;
}
static int T_4 F_250 ( void )
{
unsigned long V_44 ;
struct V_24 * V_48 ;
struct V_1 * V_2 ;
struct V_32 * V_220 ;
F_30 (rsp) {
V_220 = F_251 ( F_139 , V_2 , L_68 , V_2 -> V_58 ) ;
F_252 ( F_253 ( V_220 ) ) ;
V_48 = F_22 ( V_2 ) ;
F_81 ( & V_48 -> V_66 , V_44 ) ;
V_2 -> V_114 = V_220 ;
F_83 ( & V_48 -> V_66 , V_44 ) ;
F_254 ( V_2 ) ;
}
return 0 ;
}
void F_255 ( void )
{
F_256 ( F_207 () != 1 ) ;
F_256 ( F_257 () > 0 ) ;
V_221 = 1 ;
}
static void T_4 F_258 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_222 [ V_223 - 1 ] = V_224 ;
for ( V_19 = V_223 - 2 ; V_19 >= 0 ; V_19 -- )
V_2 -> V_222 [ V_19 ] = V_225 ;
}
static void T_4 F_258 ( struct V_1 * V_2 )
{
int V_226 ;
int V_227 ;
int V_19 ;
V_227 = V_217 ;
for ( V_19 = V_223 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_226 = V_2 -> V_228 [ V_19 ] ;
V_2 -> V_222 [ V_19 ] = ( V_227 + V_226 - 1 ) / V_226 ;
V_227 = V_226 ;
}
}
static void T_4 F_259 ( struct V_1 * V_2 ,
struct V_6 T_5 * V_37 )
{
static char * V_229 [] = { L_69 ,
L_70 ,
L_71 ,
L_72 } ;
static char * V_230 [] = { L_73 ,
L_74 ,
L_75 ,
L_76 } ;
int V_231 = 1 ;
int V_19 ;
int V_64 ;
struct V_24 * V_48 ;
F_260 ( V_232 > F_261 ( V_229 ) ) ;
if ( V_223 > V_233 )
F_262 ( L_77 ) ;
for ( V_19 = 0 ; V_19 < V_223 ; V_19 ++ )
V_2 -> V_228 [ V_19 ] = V_234 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_223 ; V_19 ++ )
V_2 -> V_82 [ V_19 ] = V_2 -> V_82 [ V_19 - 1 ] + V_2 -> V_228 [ V_19 - 1 ] ;
F_258 ( V_2 ) ;
for ( V_19 = V_223 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_231 *= V_2 -> V_222 [ V_19 ] ;
V_48 = V_2 -> V_82 [ V_19 ] ;
for ( V_64 = 0 ; V_64 < V_2 -> V_228 [ V_19 ] ; V_64 ++ , V_48 ++ ) {
F_263 ( & V_48 -> V_66 ) ;
F_264 ( & V_48 -> V_66 ,
& V_235 [ V_19 ] , V_229 [ V_19 ] ) ;
F_263 ( & V_48 -> V_146 ) ;
F_264 ( & V_48 -> V_146 ,
& V_236 [ V_19 ] , V_230 [ V_19 ] ) ;
V_48 -> V_4 = V_2 -> V_4 ;
V_48 -> V_3 = V_2 -> V_3 ;
V_48 -> V_67 = 0 ;
V_48 -> V_51 = 0 ;
V_48 -> V_69 = V_64 * V_231 ;
V_48 -> V_68 = ( V_64 + 1 ) * V_231 - 1 ;
if ( V_48 -> V_68 >= V_237 )
V_48 -> V_68 = V_237 - 1 ;
if ( V_19 == 0 ) {
V_48 -> V_238 = 0 ;
V_48 -> V_50 = 0 ;
V_48 -> V_118 = NULL ;
} else {
V_48 -> V_238 = V_64 % V_2 -> V_222 [ V_19 - 1 ] ;
V_48 -> V_50 = 1UL << V_48 -> V_238 ;
V_48 -> V_118 = V_2 -> V_82 [ V_19 - 1 ] +
V_64 / V_2 -> V_222 [ V_19 - 1 ] ;
}
V_48 -> V_82 = V_19 ;
F_265 ( & V_48 -> V_239 ) ;
F_266 ( V_48 ) ;
}
}
V_2 -> V_37 = V_37 ;
F_267 ( & V_2 -> V_106 ) ;
F_268 ( & V_2 -> V_113 , F_144 ) ;
V_48 = V_2 -> V_82 [ V_223 - 1 ] ;
F_90 (i) {
while ( V_19 > V_48 -> V_68 )
V_48 ++ ;
F_91 ( V_2 -> V_37 , V_19 ) -> V_49 = V_48 ;
F_242 ( V_19 , V_2 ) ;
}
F_269 ( & V_2 -> V_240 , & V_241 ) ;
}
static void T_4 F_270 ( void )
{
V_164 V_242 ;
int V_19 ;
int V_64 ;
int V_243 = V_217 ;
int V_244 [ V_232 + 1 ] ;
V_242 = V_245 + V_217 / V_246 ;
if ( V_107 == V_78 )
V_107 = V_242 ;
if ( V_110 == V_78 )
V_110 = V_242 ;
if ( V_224 == V_247 &&
V_217 == V_237 )
return;
F_271 ( L_78 ,
V_224 , V_217 ) ;
V_244 [ 0 ] = 1 ;
V_244 [ 1 ] = V_224 ;
for ( V_19 = 2 ; V_19 <= V_232 ; V_19 ++ )
V_244 [ V_19 ] = V_244 [ V_19 - 1 ] * V_225 ;
if ( V_224 < V_247 ||
V_224 > sizeof( unsigned long ) * 8 ||
V_243 > V_244 [ V_232 ] ) {
F_256 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_232 ; V_19 ++ )
if ( V_243 <= V_244 [ V_19 ] ) {
for ( V_64 = 0 ; V_64 <= V_19 ; V_64 ++ )
V_234 [ V_64 ] =
F_272 ( V_243 , V_244 [ V_19 - V_64 ] ) ;
V_223 = V_19 ;
for ( V_64 = V_19 + 1 ; V_64 <= V_232 ; V_64 ++ )
V_234 [ V_64 ] = 0 ;
break;
}
V_90 = 0 ;
for ( V_19 = 0 ; V_19 <= V_232 ; V_19 ++ )
V_90 += V_234 [ V_19 ] ;
V_90 -= V_243 ;
}
void T_4 F_273 ( void )
{
int V_5 ;
F_274 () ;
F_270 () ;
F_259 ( & V_12 , & V_10 ) ;
F_259 ( & V_11 , & V_8 ) ;
F_275 () ;
F_276 ( V_152 , F_187 ) ;
F_277 ( F_247 , 0 ) ;
F_278 ( F_249 , 0 ) ;
F_279 (cpu)
F_247 ( NULL , V_203 , ( void * ) ( long ) V_5 ) ;
}
