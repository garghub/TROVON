void F_1 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
if ( ! V_3 )
return;
F_3 ( V_1 , V_5 ,
( V_6 ) ( ( V_7 ) ( unsigned long ) V_3 ) ,
( V_6 ) ( ( V_7 ) ( unsigned long ) V_3 >> 32 ) ) ;
}
void F_4 ( int V_1 )
{
if ( ! F_2 ( V_4 , V_1 ) . V_3 )
return;
F_3 ( V_1 , V_5 , 0 , 0 ) ;
}
static int F_5 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
int V_8 = F_6 ( V_1 ) ;
int V_9 , V_10 = 1 ;
void * V_11 ;
if ( ! V_12 . V_13 )
return 0 ;
V_11 = F_7 ( V_14 , V_15 | V_16 , V_8 ) ;
if ( F_8 ( ! V_11 ) )
return - V_17 ;
V_9 = V_14 / V_12 . V_18 ;
V_3 -> V_19 = ( V_7 ) ( unsigned long ) V_11 ;
V_3 -> V_20 = V_3 -> V_19 ;
V_3 -> V_21 = V_3 -> V_19 +
V_9 * V_12 . V_18 ;
V_3 -> V_22 = V_3 -> V_19 +
V_10 * V_12 . V_18 ;
return 0 ;
}
static void F_9 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
if ( ! V_3 || ! V_12 . V_13 )
return;
F_10 ( ( void * ) ( unsigned long ) V_3 -> V_19 ) ;
V_3 -> V_19 = 0 ;
}
static int F_11 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
int V_8 = F_6 ( V_1 ) ;
int V_9 , V_10 ;
void * V_11 ;
if ( ! V_12 . V_23 )
return 0 ;
V_11 = F_7 ( V_24 , V_15 | V_16 , V_8 ) ;
if ( F_8 ( ! V_11 ) )
return - V_17 ;
V_9 = V_24 / V_25 ;
V_10 = V_9 / 16 ;
V_3 -> V_26 = ( V_7 ) ( unsigned long ) V_11 ;
V_3 -> V_27 = V_3 -> V_26 ;
V_3 -> V_28 = V_3 -> V_26 +
V_9 * V_25 ;
V_3 -> V_29 = V_3 -> V_28 -
V_10 * V_25 ;
return 0 ;
}
static void F_12 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
if ( ! V_3 || ! V_12 . V_23 )
return;
F_10 ( ( void * ) ( unsigned long ) V_3 -> V_26 ) ;
V_3 -> V_26 = 0 ;
}
static int F_13 ( int V_1 )
{
int V_8 = F_6 ( V_1 ) ;
struct V_2 * V_3 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_15 | V_16 , V_8 ) ;
if ( F_8 ( ! V_3 ) )
return - V_17 ;
F_2 ( V_4 , V_1 ) . V_3 = V_3 ;
return 0 ;
}
static void F_14 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_1 ) . V_3 ;
if ( ! V_3 )
return;
F_2 ( V_4 , V_1 ) . V_3 = NULL ;
F_10 ( V_3 ) ;
}
void F_15 ( void )
{
int V_1 ;
if ( ! V_12 . V_23 && ! V_12 . V_13 )
return;
F_16 () ;
F_17 (cpu)
F_4 ( V_1 ) ;
F_18 (cpu) {
F_9 ( V_1 ) ;
F_12 ( V_1 ) ;
F_14 ( V_1 ) ;
}
F_19 () ;
}
void F_20 ( void )
{
int V_30 = 0 , V_31 = 0 ;
int V_1 ;
V_12 . V_32 = 0 ;
V_12 . V_33 = 0 ;
if ( ! V_12 . V_23 && ! V_12 . V_13 )
return;
if ( ! V_12 . V_23 )
V_30 = 1 ;
if ( ! V_12 . V_13 )
V_31 = 1 ;
F_16 () ;
F_18 (cpu) {
if ( F_13 ( V_1 ) ) {
V_30 = 1 ;
V_31 = 1 ;
}
if ( ! V_30 && F_11 ( V_1 ) )
V_30 = 1 ;
if ( ! V_31 && F_5 ( V_1 ) )
V_31 = 1 ;
if ( V_30 && V_31 )
break;
}
if ( V_30 ) {
F_18 (cpu)
F_12 ( V_1 ) ;
}
if ( V_31 ) {
F_18 (cpu)
F_9 ( V_1 ) ;
}
if ( V_30 && V_31 ) {
F_18 (cpu)
F_14 ( V_1 ) ;
} else {
if ( V_12 . V_23 && ! V_30 )
V_12 . V_32 = 1 ;
if ( V_12 . V_13 && ! V_31 )
V_12 . V_33 = 1 ;
F_17 (cpu)
F_1 ( V_1 ) ;
}
F_19 () ;
}
void F_21 ( V_7 V_34 )
{
unsigned long V_35 ;
V_35 = F_22 () ;
V_35 |= V_36 ;
V_35 |= V_37 ;
V_35 |= V_38 ;
if ( ! ( V_34 & V_39 ) )
V_35 |= V_40 ;
if ( ! ( V_34 & V_41 ) )
V_35 |= V_42 ;
F_23 ( V_35 ) ;
}
void F_24 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
unsigned long V_35 ;
if ( ! V_43 -> V_3 )
return;
V_35 = F_22 () ;
V_35 &=
~ ( V_36 | V_37 | V_38 |
V_40 | V_42 ) ;
F_23 ( V_35 ) ;
}
int F_26 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_44 {
V_7 V_45 ;
V_7 V_46 ;
V_7 V_47 ;
};
struct V_48 * V_49 = V_43 -> V_50 [ V_51 ] ;
struct V_44 * V_52 , * V_53 ;
struct V_54 V_55 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
if ( ! V_49 )
return 0 ;
if ( ! V_12 . V_32 )
return 0 ;
V_52 = (struct V_44 * ) ( unsigned long ) V_3 -> V_26 ;
V_53 = (struct V_44 * ) ( unsigned long ) V_3 -> V_27 ;
if ( V_53 <= V_52 )
return 0 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_3 -> V_27 = V_3 -> V_26 ;
F_27 ( & V_59 , 0 , V_49 -> V_62 . V_63 ) ;
F_28 ( & V_57 , & V_59 , V_49 , & V_61 ) ;
if ( F_29 ( & V_55 , V_49 , V_57 . V_64 * ( V_53 - V_52 ) ) )
return 1 ;
for (; V_52 < V_53 ; V_52 ++ ) {
V_59 . V_65 = V_52 -> V_45 ;
V_59 . V_66 = V_52 -> V_46 ;
F_30 ( & V_55 , & V_57 , & V_59 , V_49 ) ;
}
F_31 ( & V_55 ) ;
V_49 -> V_62 . V_67 ++ ;
V_49 -> V_68 = V_69 ;
return 1 ;
}
struct V_70 * F_32 ( struct V_48 * V_49 )
{
struct V_70 * V_71 ;
if ( ! V_49 -> V_72 . V_73 )
return NULL ;
if ( V_12 . V_74 ) {
F_33 (c, x86_pmu.pebs_constraints) {
if ( ( V_49 -> V_62 . V_34 & V_71 -> V_75 ) == V_71 -> V_76 )
return V_71 ;
}
}
return & V_77 ;
}
void F_34 ( struct V_48 * V_49 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_78 * V_79 = & V_49 -> V_62 ;
V_79 -> V_34 &= ~ V_80 ;
V_43 -> V_81 |= 1ULL << V_79 -> V_82 ;
}
void F_35 ( struct V_48 * V_49 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_78 * V_79 = & V_49 -> V_62 ;
V_43 -> V_81 &= ~ ( 1ULL << V_79 -> V_82 ) ;
if ( V_43 -> V_83 )
F_36 ( V_84 , V_43 -> V_81 ) ;
V_79 -> V_34 |= V_80 ;
}
void F_37 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
if ( V_43 -> V_81 )
F_36 ( V_84 , V_43 -> V_81 ) ;
}
void F_38 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
if ( V_43 -> V_81 )
F_36 ( V_84 , 0 ) ;
}
static int F_39 ( struct V_60 * V_61 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
unsigned long V_45 = V_43 -> V_85 [ 0 ] . V_45 ;
unsigned long V_86 , V_46 = V_43 -> V_85 [ 0 ] . V_46 ;
unsigned long V_65 = V_61 -> V_65 ;
int V_87 = 0 ;
if ( ! V_12 . V_88 . V_89 )
return 1 ;
if ( ! V_43 -> V_90 . V_91 || ! V_45 || ! V_46 )
return 0 ;
if ( F_40 ( V_65 ) != F_40 ( V_46 ) )
return 0 ;
if ( ( V_65 - V_46 ) > V_92 )
return 0 ;
if ( V_65 == V_46 ) {
F_41 ( V_61 , V_45 ) ;
return 1 ;
}
do {
struct V_93 V_93 ;
T_1 V_94 [ V_95 ] ;
void * V_96 ;
V_86 = V_46 ;
if ( ! F_40 ( V_65 ) ) {
int V_97 , V_64 = V_95 ;
V_97 = F_42 ( V_94 , ( void V_98 * ) V_46 , V_64 ) ;
if ( V_97 != V_64 )
return 0 ;
V_96 = V_94 ;
} else
V_96 = ( void * ) V_46 ;
#ifdef F_43
V_87 = F_40 ( V_46 ) || ! F_44 ( V_99 ) ;
#endif
F_45 ( & V_93 , V_96 , V_87 ) ;
F_46 ( & V_93 ) ;
V_46 += V_93 . V_100 ;
} while ( V_46 < V_65 );
if ( V_46 == V_65 ) {
F_41 ( V_61 , V_86 ) ;
return 1 ;
}
return 0 ;
}
static void F_47 ( struct V_48 * V_49 ,
struct V_60 * V_101 , void * V_102 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_103 * V_13 = V_102 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
if ( ! F_48 ( V_49 ) )
return;
F_27 ( & V_59 , 0 , V_49 -> V_62 . V_63 ) ;
V_61 = * V_101 ;
V_61 . V_47 = V_13 -> V_47 ;
F_41 ( & V_61 , V_13 -> V_65 ) ;
V_61 . V_104 = V_13 -> V_104 ;
V_61 . V_105 = V_13 -> V_105 ;
if ( V_49 -> V_72 . V_73 > 1 && F_39 ( & V_61 ) )
V_61 . V_47 |= V_106 ;
else
V_61 . V_47 &= ~ V_106 ;
if ( F_49 ( V_49 ) )
V_59 . V_107 = & V_43 -> V_90 ;
if ( F_50 ( V_49 , & V_59 , & V_61 ) )
F_51 ( V_49 , 0 ) ;
}
static void F_52 ( struct V_60 * V_101 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_48 * V_49 = V_43 -> V_50 [ 0 ] ;
struct V_103 * V_52 , * V_53 ;
int V_108 ;
if ( ! V_12 . V_33 )
return;
V_52 = (struct V_103 * ) ( unsigned long ) V_3 -> V_19 ;
V_53 = (struct V_103 * ) ( unsigned long ) V_3 -> V_20 ;
V_3 -> V_20 = V_3 -> V_19 ;
if ( ! F_53 ( 0 , V_43 -> V_109 ) )
return;
F_54 ( ! V_49 ) ;
if ( ! V_49 -> V_72 . V_73 )
return;
V_108 = V_53 - V_52 ;
if ( V_108 <= 0 )
return;
F_55 ( V_108 > 1 , L_1 , V_108 ) ;
V_52 += V_108 - 1 ;
F_47 ( V_49 , V_101 , V_52 ) ;
}
static void F_56 ( struct V_60 * V_101 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_110 * V_52 , * V_53 ;
struct V_48 * V_49 = NULL ;
V_7 V_111 = 0 ;
int V_112 , V_108 ;
if ( ! V_12 . V_33 )
return;
V_52 = (struct V_110 * ) ( unsigned long ) V_3 -> V_19 ;
V_53 = (struct V_110 * ) ( unsigned long ) V_3 -> V_20 ;
V_3 -> V_20 = V_3 -> V_19 ;
V_108 = V_53 - V_52 ;
if ( V_108 <= 0 )
return;
F_55 ( V_108 > V_12 . V_113 , L_2 , V_108 ) ;
for ( ; V_52 < V_53 ; V_52 ++ ) {
F_57 (bit, (unsigned long *)&at->status, x86_pmu.max_pebs_events) {
V_49 = V_43 -> V_50 [ V_112 ] ;
if ( ! F_53 ( V_112 , V_43 -> V_109 ) )
continue;
F_54 ( ! V_49 ) ;
if ( ! V_49 -> V_72 . V_73 )
continue;
if ( F_58 ( V_112 , ( unsigned long * ) & V_111 ) )
continue;
break;
}
if ( ! V_49 || V_112 >= V_12 . V_113 )
continue;
F_47 ( V_49 , V_101 , V_52 ) ;
}
}
void F_59 ( void )
{
if ( ! F_60 ( V_114 ) )
return;
V_12 . V_23 = F_60 ( V_115 ) ;
V_12 . V_13 = F_60 ( V_116 ) ;
if ( V_12 . V_13 ) {
char V_117 = V_12 . V_88 . V_89 ? '+' : '-' ;
int V_118 = V_12 . V_88 . V_119 ;
switch ( V_118 ) {
case 0 :
F_61 ( V_120 L_3 , V_117 ) ;
V_12 . V_18 = sizeof( struct V_103 ) ;
V_12 . V_121 = F_52 ;
break;
case 1 :
F_61 ( V_120 L_4 , V_117 ) ;
V_12 . V_18 = sizeof( struct V_110 ) ;
V_12 . V_121 = F_56 ;
break;
default:
F_61 ( V_120 L_5 , V_118 , V_117 ) ;
V_12 . V_13 = 0 ;
}
}
}
void F_62 ( void )
{
struct V_2 * V_3 = F_63 ( V_4 . V_3 ) ;
if ( ! V_12 . V_23 && ! V_12 . V_13 )
return;
F_36 ( V_5 , ( unsigned long ) V_3 ) ;
}
