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
V_3 -> V_27 = V_3 -> V_26 ;
F_27 ( & V_59 , 0 ) ;
V_59 . V_62 = V_49 -> V_63 . V_64 ;
V_61 . V_65 = 0 ;
F_28 ( & V_57 , & V_59 , V_49 , & V_61 ) ;
if ( F_29 ( & V_55 , V_49 , V_57 . V_66 * ( V_53 - V_52 ) ) )
return 1 ;
for (; V_52 < V_53 ; V_52 ++ ) {
V_59 . V_65 = V_52 -> V_45 ;
V_59 . V_67 = V_52 -> V_46 ;
F_30 ( & V_55 , & V_57 , & V_59 , V_49 ) ;
}
F_31 ( & V_55 ) ;
V_49 -> V_63 . V_68 ++ ;
V_49 -> V_69 = V_70 ;
return 1 ;
}
struct V_71 * F_32 ( struct V_48 * V_49 )
{
struct V_71 * V_72 ;
if ( ! V_49 -> V_73 . V_74 )
return NULL ;
if ( V_12 . V_75 ) {
F_33 (c, x86_pmu.pebs_constraints) {
if ( ( V_49 -> V_63 . V_34 & V_72 -> V_76 ) == V_72 -> V_77 )
return V_72 ;
}
}
return & V_78 ;
}
void F_34 ( struct V_48 * V_49 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_79 * V_80 = & V_49 -> V_63 ;
V_80 -> V_34 &= ~ V_81 ;
V_43 -> V_82 |= 1ULL << V_80 -> V_83 ;
F_35 ( V_43 -> V_84 ) ;
if ( V_12 . V_85 . V_86 && V_49 -> V_73 . V_74 > 1 )
F_36 ( V_49 ) ;
}
void F_37 ( struct V_48 * V_49 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_79 * V_80 = & V_49 -> V_63 ;
V_43 -> V_82 &= ~ ( 1ULL << V_80 -> V_83 ) ;
if ( V_43 -> V_84 )
F_38 ( V_87 , V_43 -> V_82 ) ;
V_80 -> V_34 |= V_81 ;
if ( V_12 . V_85 . V_86 && V_49 -> V_73 . V_74 > 1 )
F_39 ( V_49 ) ;
}
void F_40 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
if ( V_43 -> V_82 )
F_38 ( V_87 , V_43 -> V_82 ) ;
}
void F_41 ( void )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
if ( V_43 -> V_82 )
F_38 ( V_87 , 0 ) ;
}
static inline bool F_42 ( unsigned long V_65 )
{
#ifdef F_43
return V_65 > V_88 ;
#else
return ( long ) V_65 < 0 ;
#endif
}
static int F_44 ( struct V_60 * V_61 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
unsigned long V_45 = V_43 -> V_89 [ 0 ] . V_45 ;
unsigned long V_90 , V_46 = V_43 -> V_89 [ 0 ] . V_46 ;
unsigned long V_65 = V_61 -> V_65 ;
int V_91 = 0 ;
if ( ! V_12 . V_85 . V_86 )
return 1 ;
if ( ! V_43 -> V_92 . V_93 || ! V_45 || ! V_46 )
return 0 ;
if ( F_42 ( V_65 ) != F_42 ( V_46 ) )
return 0 ;
if ( ( V_65 - V_46 ) > V_94 )
return 0 ;
if ( V_65 == V_46 ) {
V_61 -> V_65 = V_45 ;
return 1 ;
}
do {
struct V_95 V_95 ;
T_1 V_96 [ V_97 ] ;
void * V_98 ;
V_90 = V_46 ;
if ( ! F_42 ( V_65 ) ) {
int V_99 , V_66 = V_97 ;
V_99 = F_45 ( V_96 , ( void V_100 * ) V_46 , V_66 ) ;
if ( V_99 != V_66 )
return 0 ;
V_98 = V_96 ;
} else
V_98 = ( void * ) V_46 ;
#ifdef F_46
V_91 = F_42 ( V_46 ) || ! F_47 ( V_101 ) ;
#endif
F_48 ( & V_95 , V_98 , V_91 ) ;
F_49 ( & V_95 ) ;
V_46 += V_95 . V_102 ;
} while ( V_46 < V_65 );
if ( V_46 == V_65 ) {
V_61 -> V_65 = V_90 ;
return 1 ;
}
return 0 ;
}
static void F_50 ( struct V_48 * V_49 ,
struct V_60 * V_103 , void * V_104 )
{
struct V_105 * V_13 = V_104 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
if ( ! F_51 ( V_49 ) )
return;
F_27 ( & V_59 , 0 ) ;
V_59 . V_62 = V_49 -> V_63 . V_64 ;
V_61 = * V_103 ;
V_61 . V_65 = V_13 -> V_65 ;
V_61 . V_106 = V_13 -> V_106 ;
V_61 . V_107 = V_13 -> V_107 ;
if ( V_49 -> V_73 . V_74 > 1 && F_44 ( & V_61 ) )
V_61 . V_47 |= V_108 ;
else
V_61 . V_47 &= ~ V_108 ;
if ( F_52 ( V_49 , & V_59 , & V_61 ) )
F_53 ( V_49 , 0 ) ;
}
static void F_54 ( struct V_60 * V_103 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_48 * V_49 = V_43 -> V_50 [ 0 ] ;
struct V_105 * V_52 , * V_53 ;
int V_109 ;
if ( ! V_12 . V_33 )
return;
V_52 = (struct V_105 * ) ( unsigned long ) V_3 -> V_19 ;
V_53 = (struct V_105 * ) ( unsigned long ) V_3 -> V_20 ;
V_3 -> V_20 = V_3 -> V_19 ;
if ( ! F_55 ( 0 , V_43 -> V_110 ) )
return;
F_35 ( ! V_49 ) ;
if ( ! V_49 -> V_73 . V_74 )
return;
V_109 = V_53 - V_52 ;
if ( V_109 <= 0 )
return;
F_35 ( V_109 > 1 ) ;
V_52 += V_109 - 1 ;
F_50 ( V_49 , V_103 , V_52 ) ;
}
static void F_56 ( struct V_60 * V_103 )
{
struct V_4 * V_43 = & F_25 ( V_4 ) ;
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_111 * V_52 , * V_53 ;
struct V_48 * V_49 = NULL ;
V_7 V_112 = 0 ;
int V_113 , V_109 ;
if ( ! V_12 . V_33 )
return;
V_52 = (struct V_111 * ) ( unsigned long ) V_3 -> V_19 ;
V_53 = (struct V_111 * ) ( unsigned long ) V_3 -> V_20 ;
V_3 -> V_20 = V_3 -> V_19 ;
V_109 = V_53 - V_52 ;
if ( V_109 <= 0 )
return;
F_35 ( V_109 > V_114 ) ;
for ( ; V_52 < V_53 ; V_52 ++ ) {
F_57 (bit, (unsigned long *)&at->status, MAX_PEBS_EVENTS) {
V_49 = V_43 -> V_50 [ V_113 ] ;
if ( ! F_55 ( V_113 , V_43 -> V_110 ) )
continue;
F_35 ( ! V_49 ) ;
if ( ! V_49 -> V_73 . V_74 )
continue;
if ( F_58 ( V_113 , ( unsigned long * ) & V_112 ) )
continue;
break;
}
if ( ! V_49 || V_113 >= V_114 )
continue;
F_50 ( V_49 , V_103 , V_52 ) ;
}
}
void F_59 ( void )
{
if ( ! F_60 ( V_115 ) )
return;
V_12 . V_23 = F_60 ( V_116 ) ;
V_12 . V_13 = F_60 ( V_117 ) ;
if ( V_12 . V_13 ) {
char V_118 = V_12 . V_85 . V_86 ? '+' : '-' ;
int V_119 = V_12 . V_85 . V_120 ;
switch ( V_119 ) {
case 0 :
F_61 ( V_121 L_1 , V_118 ) ;
V_12 . V_18 = sizeof( struct V_105 ) ;
V_12 . V_122 = F_54 ;
break;
case 1 :
F_61 ( V_121 L_2 , V_118 ) ;
V_12 . V_18 = sizeof( struct V_111 ) ;
V_12 . V_122 = F_56 ;
break;
default:
F_61 ( V_121 L_3 , V_119 , V_118 ) ;
V_12 . V_13 = 0 ;
}
}
}
