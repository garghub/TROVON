static bool F_1 ( void * V_1 )
{
void * V_2 = V_3 -> V_4 ;
return V_1 >= V_2 && V_1 < V_2 + V_5 ;
}
static bool F_2 ( void * V_1 )
{
void * V_2 = V_3 -> V_4 ;
return V_1 >= V_2 &&
V_1 < V_2 + V_6 ;
}
static int F_3 ( int V_7 )
{
int V_8 = F_4 ( V_7 ) ;
return F_5 ( V_8 - V_9 + 2 , 1 ) ;
}
static int F_6 ( int V_7 )
{
if ( V_7 == V_5 )
return V_10 - 1 ;
return F_3 ( V_7 ) ;
}
static int F_7 ( const struct V_11 * V_12 )
{
if ( V_12 -> V_13 < sizeof( int ) || V_12 -> V_14 < sizeof( int ) )
return 0 ;
return F_6 ( V_12 -> V_13 ) ;
}
static void F_8 ( struct V_15 * V_15 , struct V_11 * V_16 )
{
V_15 -> V_17 = ( unsigned long ) V_16 ;
}
static struct V_11 * F_9 ( struct V_15 * V_15 )
{
return (struct V_11 * ) V_15 -> V_17 ;
}
static int T_1 F_10 ( unsigned int V_18 , int V_19 )
{
return V_20 [ V_18 ] * V_21 + V_19 ;
}
static unsigned long F_11 ( struct V_11 * V_12 ,
unsigned int V_18 , int V_19 )
{
return ( unsigned long ) V_12 -> V_4 + V_22 [ V_18 ] +
( V_19 << V_23 ) ;
}
static void T_1 F_12 ( struct V_11 * V_12 ,
int * V_24 , int * V_25 , int V_26 )
{
* V_24 = F_13 ( V_12 -> V_27 , V_26 , * V_24 ) ;
* V_25 = F_14 ( V_12 -> V_27 , V_26 , * V_24 + 1 ) ;
}
static void T_1 F_15 ( struct V_11 * V_12 ,
int * V_24 , int * V_25 , int V_26 )
{
* V_24 = F_14 ( V_12 -> V_27 , V_26 , * V_24 ) ;
* V_25 = F_13 ( V_12 -> V_27 , V_26 , * V_24 + 1 ) ;
}
static void * F_16 ( T_2 V_7 )
{
if ( F_17 ( ! F_18 () ) )
return NULL ;
if ( V_7 <= V_28 )
return F_19 ( V_7 , V_29 ) ;
else
return F_20 ( V_7 ) ;
}
static void F_21 ( void * V_30 , T_2 V_7 )
{
if ( V_7 <= V_28 )
F_22 ( V_30 ) ;
else
F_23 ( V_30 ) ;
}
static void F_24 ( struct V_11 * V_12 , int V_31 )
{
int V_32 = F_7 ( V_12 ) ;
if ( V_12 != V_33 && V_31 != V_32 ) {
if ( V_31 < V_32 )
F_25 ( & V_12 -> V_34 , & V_35 [ V_32 ] ) ;
else
F_26 ( & V_12 -> V_34 , & V_35 [ V_32 ] ) ;
}
}
static int F_27 ( struct V_11 * V_12 )
{
int V_36 ;
if ( V_12 -> V_37 >= V_12 -> V_38 + 2 )
return 0 ;
V_36 = V_39 ;
while ( V_36 < V_12 -> V_38 + 2 )
V_36 *= 2 ;
return V_36 ;
}
static int F_28 ( struct V_11 * V_12 , int V_36 )
{
int * V_40 = NULL , * V_41 = NULL ;
T_2 V_42 = 0 , V_43 = V_36 * sizeof( V_41 [ 0 ] ) ;
unsigned long V_44 ;
V_41 = F_16 ( V_43 ) ;
if ( ! V_41 )
return - V_45 ;
F_29 ( & V_46 , V_44 ) ;
if ( V_36 <= V_12 -> V_37 )
goto V_47;
V_42 = V_12 -> V_37 * sizeof( V_12 -> V_48 [ 0 ] ) ;
V_40 = V_12 -> V_48 ;
memcpy ( V_41 , V_40 , V_42 ) ;
V_12 -> V_37 = V_36 ;
V_12 -> V_48 = V_41 ;
V_41 = NULL ;
V_47:
F_30 ( & V_46 , V_44 ) ;
F_21 ( V_40 , V_42 ) ;
F_21 ( V_41 , V_43 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 , int V_49 ,
int V_50 , int V_51 )
{
int V_52 = ! ! V_50 + ! ! V_51 ;
F_32 ( V_12 -> V_37 < V_12 -> V_38 + V_52 ) ;
memmove ( & V_12 -> V_48 [ V_49 + V_52 ] , & V_12 -> V_48 [ V_49 ] ,
sizeof( V_12 -> V_48 [ 0 ] ) * ( V_12 -> V_38 - V_49 ) ) ;
V_12 -> V_38 += V_52 ;
if ( V_50 ) {
V_12 -> V_48 [ V_49 + 1 ] = V_12 -> V_48 [ V_49 ] - V_50 ;
V_12 -> V_48 [ V_49 ++ ] = V_50 ;
}
if ( V_51 ) {
V_12 -> V_48 [ V_49 ++ ] -= V_51 ;
V_12 -> V_48 [ V_49 ] = V_51 ;
}
}
static int F_33 ( struct V_11 * V_12 , int V_7 , int V_53 )
{
int V_31 = F_7 ( V_12 ) ;
int V_54 = 0 ;
int V_49 , V_55 ;
for ( V_49 = 0 , V_55 = 0 ; V_49 < V_12 -> V_38 ; V_55 += abs ( V_12 -> V_48 [ V_49 ++ ] ) ) {
bool V_56 = V_49 + 1 == V_12 -> V_38 ;
int V_50 , V_51 ;
V_50 = F_34 ( V_55 , V_53 ) - V_55 ;
F_32 ( V_49 == 0 && V_50 != 0 ) ;
if ( V_12 -> V_48 [ V_49 ] < 0 )
continue;
if ( V_12 -> V_48 [ V_49 ] < V_50 + V_7 ) {
V_54 = F_5 ( V_12 -> V_48 [ V_49 ] , V_54 ) ;
continue;
}
if ( V_50 && ( V_50 < sizeof( int ) || V_12 -> V_48 [ V_49 - 1 ] > 0 ) ) {
if ( V_12 -> V_48 [ V_49 - 1 ] > 0 )
V_12 -> V_48 [ V_49 - 1 ] += V_50 ;
else {
V_12 -> V_48 [ V_49 - 1 ] -= V_50 ;
V_12 -> V_13 -= V_50 ;
}
V_12 -> V_48 [ V_49 ] -= V_50 ;
V_55 += V_50 ;
V_50 = 0 ;
}
V_51 = V_12 -> V_48 [ V_49 ] - V_50 - V_7 ;
if ( V_51 < sizeof( int ) )
V_51 = 0 ;
if ( V_50 || V_51 ) {
F_31 ( V_12 , V_49 , V_50 , V_51 ) ;
if ( V_50 ) {
V_49 ++ ;
V_55 += V_50 ;
V_54 = F_5 ( V_12 -> V_48 [ V_49 - 1 ] , V_54 ) ;
}
if ( V_51 )
V_54 = F_5 ( V_12 -> V_48 [ V_49 + 1 ] , V_54 ) ;
}
if ( V_56 )
V_12 -> V_14 = V_54 ;
else
V_12 -> V_14 = F_5 ( V_12 -> V_14 ,
V_54 ) ;
V_12 -> V_13 -= V_12 -> V_48 [ V_49 ] ;
V_12 -> V_48 [ V_49 ] = - V_12 -> V_48 [ V_49 ] ;
F_24 ( V_12 , V_31 ) ;
return V_55 ;
}
V_12 -> V_14 = V_54 ;
F_24 ( V_12 , V_31 ) ;
return - 1 ;
}
static void F_35 ( struct V_11 * V_12 , int V_57 )
{
int V_31 = F_7 ( V_12 ) ;
int V_49 , V_55 ;
for ( V_49 = 0 , V_55 = 0 ; V_49 < V_12 -> V_38 ; V_55 += abs ( V_12 -> V_48 [ V_49 ++ ] ) )
if ( V_55 == V_57 )
break;
F_32 ( V_55 != V_57 ) ;
F_32 ( V_12 -> V_48 [ V_49 ] > 0 ) ;
V_12 -> V_48 [ V_49 ] = - V_12 -> V_48 [ V_49 ] ;
V_12 -> V_13 += V_12 -> V_48 [ V_49 ] ;
if ( V_49 > 0 && V_12 -> V_48 [ V_49 - 1 ] >= 0 ) {
V_12 -> V_48 [ V_49 - 1 ] += V_12 -> V_48 [ V_49 ] ;
V_12 -> V_38 -- ;
memmove ( & V_12 -> V_48 [ V_49 ] , & V_12 -> V_48 [ V_49 + 1 ] ,
( V_12 -> V_38 - V_49 ) * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
V_49 -- ;
}
if ( V_49 + 1 < V_12 -> V_38 && V_12 -> V_48 [ V_49 + 1 ] >= 0 ) {
V_12 -> V_48 [ V_49 ] += V_12 -> V_48 [ V_49 + 1 ] ;
V_12 -> V_38 -- ;
memmove ( & V_12 -> V_48 [ V_49 + 1 ] , & V_12 -> V_48 [ V_49 + 2 ] ,
( V_12 -> V_38 - ( V_49 + 1 ) ) * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
}
V_12 -> V_14 = F_5 ( V_12 -> V_48 [ V_49 ] , V_12 -> V_14 ) ;
F_24 ( V_12 , V_31 ) ;
}
static struct V_11 * F_36 ( void )
{
struct V_11 * V_12 ;
V_12 = F_16 ( V_58 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_48 = F_16 ( V_39 * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
if ( ! V_12 -> V_48 ) {
F_22 ( V_12 ) ;
return NULL ;
}
V_12 -> V_37 = V_39 ;
V_12 -> V_48 [ V_12 -> V_38 ++ ] = V_5 ;
F_37 ( & V_12 -> V_34 ) ;
V_12 -> V_13 = V_5 ;
V_12 -> V_14 = V_5 ;
return V_12 ;
}
static void F_38 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_21 ( V_12 -> V_48 , V_12 -> V_37 * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
F_22 ( V_12 ) ;
}
static struct V_11 * F_39 ( void * V_1 )
{
if ( F_1 ( V_1 ) ) {
if ( F_2 ( V_1 ) )
return V_33 ;
return V_3 ;
}
V_1 += V_22 [ F_40 () ] ;
return F_9 ( F_41 ( V_1 ) ) ;
}
static void T_3 * F_42 ( T_2 V_7 , T_2 V_53 , bool V_59 )
{
static int V_60 = 10 ;
struct V_11 * V_12 ;
const char * V_61 ;
int V_62 , V_55 , V_36 ;
unsigned long V_44 ;
if ( F_43 ( ! V_7 || V_7 > V_63 || V_53 > V_28 ) ) {
F_44 ( true , L_1
L_2 , V_7 , V_53 ) ;
return NULL ;
}
F_45 ( & V_64 ) ;
F_29 ( & V_46 , V_44 ) ;
if ( V_59 && V_33 ) {
V_12 = V_33 ;
if ( V_7 > V_12 -> V_14 ) {
V_61 = L_3 ;
goto V_65;
}
while ( ( V_36 = F_27 ( V_12 ) ) ) {
F_30 ( & V_46 , V_44 ) ;
if ( F_28 ( V_12 , V_36 ) < 0 ) {
V_61 = L_4 ;
goto V_66;
}
F_29 ( & V_46 , V_44 ) ;
}
V_55 = F_33 ( V_12 , V_7 , V_53 ) ;
if ( V_55 >= 0 )
goto V_67;
V_61 = L_3 ;
goto V_65;
}
V_68:
for ( V_62 = F_6 ( V_7 ) ; V_62 < V_10 ; V_62 ++ ) {
F_46 (chunk, &pcpu_slot[slot], list) {
if ( V_7 > V_12 -> V_14 )
continue;
V_36 = F_27 ( V_12 ) ;
if ( V_36 ) {
F_30 ( & V_46 , V_44 ) ;
if ( F_28 ( V_12 ,
V_36 ) < 0 ) {
V_61 = L_5 ;
goto V_66;
}
F_29 ( & V_46 , V_44 ) ;
goto V_68;
}
V_55 = F_33 ( V_12 , V_7 , V_53 ) ;
if ( V_55 >= 0 )
goto V_67;
}
}
F_30 ( & V_46 , V_44 ) ;
V_12 = F_47 () ;
if ( ! V_12 ) {
V_61 = L_6 ;
goto V_66;
}
F_29 ( & V_46 , V_44 ) ;
F_24 ( V_12 , - 1 ) ;
goto V_68;
V_67:
F_30 ( & V_46 , V_44 ) ;
if ( F_48 ( V_12 , V_55 , V_7 ) ) {
F_29 ( & V_46 , V_44 ) ;
F_35 ( V_12 , V_55 ) ;
V_61 = L_7 ;
goto V_65;
}
F_49 ( & V_64 ) ;
return F_50 ( V_12 -> V_4 + V_55 ) ;
V_65:
F_30 ( & V_46 , V_44 ) ;
V_66:
F_49 ( & V_64 ) ;
if ( V_60 ) {
F_51 ( L_8
L_9 , V_7 , V_53 , V_61 ) ;
F_52 () ;
if ( ! -- V_60 )
F_53 ( L_10 ) ;
}
return NULL ;
}
void T_3 * F_54 ( T_2 V_7 , T_2 V_53 )
{
return F_42 ( V_7 , V_53 , false ) ;
}
void T_3 * F_55 ( T_2 V_7 , T_2 V_53 )
{
return F_42 ( V_7 , V_53 , true ) ;
}
static void F_56 ( struct V_69 * V_70 )
{
F_57 ( V_71 ) ;
struct V_72 * V_50 = & V_35 [ V_10 - 1 ] ;
struct V_11 * V_12 , * V_73 ;
F_45 ( & V_64 ) ;
F_58 ( & V_46 ) ;
F_59 (chunk, next, head, list) {
F_60 ( V_12 -> V_74 ) ;
if ( V_12 == F_61 ( V_50 , struct V_11 , V_34 ) )
continue;
F_25 ( & V_12 -> V_34 , & V_71 ) ;
}
F_62 ( & V_46 ) ;
F_59 (chunk, next, &todo, list) {
F_63 ( V_12 , 0 , V_5 ) ;
F_64 ( V_12 ) ;
}
F_49 ( & V_64 ) ;
}
void F_65 ( void T_3 * V_30 )
{
void * V_1 ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_55 ;
if ( ! V_30 )
return;
V_1 = F_66 ( V_30 ) ;
F_29 ( & V_46 , V_44 ) ;
V_12 = F_39 ( V_1 ) ;
V_55 = V_1 - V_12 -> V_4 ;
F_35 ( V_12 , V_55 ) ;
if ( V_12 -> V_13 == V_5 ) {
struct V_11 * V_75 ;
F_46 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_75 != V_12 ) {
F_67 ( & V_76 ) ;
break;
}
}
F_30 ( & V_46 , V_44 ) ;
}
bool F_68 ( unsigned long V_1 )
{
#ifdef F_69
const T_2 V_77 = V_78 - V_79 ;
void T_3 * V_80 = F_50 ( V_81 ) ;
unsigned int V_18 ;
F_70 (cpu) {
void * V_82 = F_71 ( V_80 , V_18 ) ;
if ( ( void * ) V_1 >= V_82 && ( void * ) V_1 < V_82 + V_77 )
return true ;
}
#endif
return false ;
}
T_4 F_72 ( void * V_1 )
{
void T_3 * V_80 = F_50 ( V_81 ) ;
bool V_83 = false ;
unsigned long V_2 , V_84 ;
unsigned int V_18 ;
V_2 = F_11 ( V_3 , V_85 , 0 ) ;
V_84 = F_11 ( V_3 , V_86 ,
V_21 ) ;
if ( ( unsigned long ) V_1 >= V_2 &&
( unsigned long ) V_1 < V_84 ) {
F_70 (cpu) {
void * V_82 = F_71 ( V_80 , V_18 ) ;
if ( V_1 >= V_82 && V_1 < V_82 + V_5 ) {
V_83 = true ;
break;
}
}
}
if ( V_83 ) {
if ( ! F_73 ( V_1 ) )
return F_74 ( V_1 ) ;
else
return F_75 ( F_76 ( V_1 ) ) ;
} else
return F_75 ( F_41 ( V_1 ) ) ;
}
struct V_87 * T_5 F_77 ( int V_88 ,
int V_89 )
{
struct V_87 * V_90 ;
T_2 V_91 , V_92 ;
void * V_30 ;
int V_93 ;
V_91 = F_34 ( sizeof( * V_90 ) + V_88 * sizeof( V_90 -> V_94 [ 0 ] ) ,
F_78 ( V_90 -> V_94 [ 0 ] . V_95 [ 0 ] ) ) ;
V_92 = V_91 + V_89 * sizeof( V_90 -> V_94 [ 0 ] . V_95 [ 0 ] ) ;
V_30 = F_79 ( F_80 ( V_92 ) ) ;
if ( ! V_30 )
return NULL ;
V_90 = V_30 ;
V_30 += V_91 ;
V_90 -> V_94 [ 0 ] . V_95 = V_30 ;
for ( V_93 = 0 ; V_93 < V_89 ; V_93 ++ )
V_90 -> V_94 [ 0 ] . V_95 [ V_93 ] = V_96 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_97 = F_80 ( V_92 ) ;
return V_90 ;
}
void T_5 F_81 ( struct V_87 * V_90 )
{
F_82 ( F_74 ( V_90 ) , V_90 -> V_97 ) ;
}
static void F_83 ( const char * V_98 ,
const struct V_87 * V_90 )
{
int V_99 = 1 , V_100 = 1 , V_101 ;
char V_102 [] = L_11 ;
int V_103 = 0 , V_104 = 0 ;
int V_105 , V_106 ;
int V_107 , V_108 ;
V_106 = V_90 -> V_88 ;
while ( V_106 /= 10 )
V_99 ++ ;
V_106 = F_84 () ;
while ( V_106 /= 10 )
V_100 ++ ;
V_102 [ F_85 ( int , V_100 , sizeof( V_102 ) - 1 ) ] = '\0' ;
V_107 = V_90 -> V_109 / V_90 -> V_110 ;
V_101 = V_107 * ( V_100 + 1 ) + V_99 + 3 ;
V_108 = F_86 ( F_5 ( 60 / V_101 , 1 ) ) ;
F_87 ( L_12 ,
V_98 , V_90 -> V_77 , V_90 -> V_111 , V_90 -> V_112 ,
V_90 -> V_110 , V_90 -> V_109 / V_90 -> V_113 , V_90 -> V_113 ) ;
for ( V_105 = 0 ; V_105 < V_90 -> V_88 ; V_105 ++ ) {
const struct V_114 * V_115 = & V_90 -> V_94 [ V_105 ] ;
int V_93 = 0 , V_116 = 0 ;
F_32 ( V_115 -> V_89 % V_107 ) ;
for ( V_104 += V_115 -> V_89 / V_107 ;
V_103 < V_104 ; V_103 ++ ) {
if ( ! ( V_103 % V_108 ) ) {
F_87 ( L_13 ) ;
F_87 ( L_14 , V_98 ) ;
}
F_87 ( L_15 , V_99 , V_105 ) ;
for ( V_116 += V_107 ; V_93 < V_116 ; V_93 ++ )
if ( V_115 -> V_95 [ V_93 ] != V_96 )
F_87 ( L_16 , V_100 ,
V_115 -> V_95 [ V_93 ] ) ;
else
F_87 ( L_17 , V_102 ) ;
}
}
F_87 ( L_13 ) ;
}
int T_5 F_88 ( const struct V_87 * V_90 ,
void * V_4 )
{
static char V_117 [ 4096 ] V_118 ;
static int V_119 [ V_120 ] V_118 ;
static int V_121 [ V_120 ] V_118 ;
T_2 V_112 = V_90 -> V_112 ;
T_2 V_122 = V_90 -> V_77 + V_90 -> V_111 + V_112 ;
struct V_11 * V_123 , * V_124 = NULL ;
unsigned long * V_125 ;
T_2 * V_126 ;
unsigned long * V_127 ;
unsigned int V_18 ;
int * V_128 ;
int V_105 , V_93 , V_49 ;
F_89 ( V_117 , sizeof( V_117 ) , V_129 ) ;
#define F_90 ( T_6 ) do { \
if (unlikely(cond)) { \
pr_emerg("PERCPU: failed to initialize, %s", #cond); \
pr_emerg("PERCPU: cpu_possible_mask=%s\n", cpus_buf); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_90 ( V_90 -> V_88 <= 0 ) ;
#ifdef F_69
F_90 ( ! V_90 -> V_77 ) ;
F_90 ( ( unsigned long ) V_79 & ~ V_130 ) ;
#endif
F_90 ( ! V_4 ) ;
F_90 ( ( unsigned long ) V_4 & ~ V_130 ) ;
F_90 ( V_90 -> V_110 < V_122 ) ;
F_90 ( V_90 -> V_110 & ~ V_130 ) ;
F_90 ( V_90 -> V_110 < V_63 ) ;
F_90 ( V_90 -> V_112 < V_131 ) ;
F_90 ( F_91 ( V_90 ) < 0 ) ;
V_125 = F_92 ( V_90 -> V_88 * sizeof( V_125 [ 0 ] ) ) ;
V_126 = F_92 ( V_90 -> V_88 * sizeof( V_126 [ 0 ] ) ) ;
V_128 = F_92 ( V_132 * sizeof( V_128 [ 0 ] ) ) ;
V_127 = F_92 ( V_132 * sizeof( V_127 [ 0 ] ) ) ;
for ( V_18 = 0 ; V_18 < V_132 ; V_18 ++ )
V_128 [ V_18 ] = V_133 ;
V_85 = V_96 ;
for ( V_105 = 0 , V_93 = 0 ; V_105 < V_90 -> V_88 ; V_105 ++ , V_93 += V_49 ) {
const struct V_114 * V_115 = & V_90 -> V_94 [ V_105 ] ;
V_125 [ V_105 ] = V_115 -> V_134 ;
V_126 [ V_105 ] = V_115 -> V_89 * V_90 -> V_110 ;
for ( V_49 = 0 ; V_49 < V_115 -> V_89 ; V_49 ++ ) {
V_18 = V_115 -> V_95 [ V_49 ] ;
if ( V_18 == V_96 )
continue;
F_90 ( V_18 > V_132 ) ;
F_90 ( ! F_93 ( V_18 ) ) ;
F_90 ( V_128 [ V_18 ] != V_133 ) ;
V_128 [ V_18 ] = V_93 + V_49 ;
V_127 [ V_18 ] = V_115 -> V_134 + V_49 * V_90 -> V_110 ;
if ( V_85 == V_96 )
V_85 = V_18 ;
V_86 = V_18 ;
}
}
V_135 = V_93 ;
F_70 (cpu)
F_90 ( V_128 [ V_18 ] == V_133 ) ;
#undef F_90
F_83 ( V_136 , V_90 ) ;
V_137 = V_90 -> V_88 ;
V_138 = V_125 ;
V_139 = V_126 ;
V_20 = V_128 ;
V_22 = V_127 ;
V_21 = V_90 -> V_110 >> V_23 ;
V_5 = V_21 << V_23 ;
V_140 = V_90 -> V_113 ;
V_58 = sizeof( struct V_11 ) +
F_94 ( V_21 ) * sizeof( unsigned long ) ;
V_10 = F_3 ( V_5 ) + 2 ;
V_35 = F_92 ( V_10 * sizeof( V_35 [ 0 ] ) ) ;
for ( V_49 = 0 ; V_49 < V_10 ; V_49 ++ )
F_37 ( & V_35 [ V_49 ] ) ;
V_123 = F_92 ( V_58 ) ;
F_37 ( & V_123 -> V_34 ) ;
V_123 -> V_4 = V_4 ;
V_123 -> V_48 = V_119 ;
V_123 -> V_37 = F_95 ( V_119 ) ;
V_123 -> V_74 = true ;
F_96 ( V_123 -> V_27 , V_21 ) ;
if ( V_90 -> V_111 ) {
V_123 -> V_13 = V_90 -> V_111 ;
V_33 = V_123 ;
V_6 = V_90 -> V_77 + V_90 -> V_111 ;
} else {
V_123 -> V_13 = V_112 ;
V_112 = 0 ;
}
V_123 -> V_14 = V_123 -> V_13 ;
V_123 -> V_48 [ V_123 -> V_38 ++ ] = - V_90 -> V_77 ;
if ( V_123 -> V_13 )
V_123 -> V_48 [ V_123 -> V_38 ++ ] = V_123 -> V_13 ;
if ( V_112 ) {
V_124 = F_92 ( V_58 ) ;
F_37 ( & V_124 -> V_34 ) ;
V_124 -> V_4 = V_4 ;
V_124 -> V_48 = V_121 ;
V_124 -> V_37 = F_95 ( V_121 ) ;
V_124 -> V_74 = true ;
F_96 ( V_124 -> V_27 , V_21 ) ;
V_124 -> V_14 = V_124 -> V_13 = V_112 ;
V_124 -> V_48 [ V_124 -> V_38 ++ ] = - V_6 ;
V_124 -> V_48 [ V_124 -> V_38 ++ ] = V_124 -> V_13 ;
}
V_3 = V_124 ? : V_123 ;
F_24 ( V_3 , - 1 ) ;
V_81 = V_4 ;
return 0 ;
}
static int T_5 F_97 ( char * V_141 )
{
if ( 0 )
;
#ifdef F_98
else if ( ! strcmp ( V_141 , L_18 ) )
V_142 = V_143 ;
#endif
#ifdef F_99
else if ( ! strcmp ( V_141 , L_19 ) )
V_142 = V_144 ;
#endif
else
F_51 ( L_20 , V_141 ) ;
return 0 ;
}
static struct V_87 * T_5 F_100 (
T_2 V_111 , T_2 V_112 ,
T_2 V_113 ,
T_7 V_145 )
{
static int V_146 [ V_96 ] V_118 ;
static int V_147 [ V_96 ] V_118 ;
const T_2 V_77 = V_78 - V_79 ;
int V_88 = 1 , V_89 = 0 ;
T_2 V_122 , V_148 , V_109 ;
int V_107 , V_149 , V_150 ( V_151 ) ;
int V_152 , V_105 , V_93 ;
unsigned int V_18 , V_153 ;
struct V_87 * V_90 ;
unsigned int * V_95 ;
memset ( V_146 , 0 , sizeof( V_146 ) ) ;
memset ( V_147 , 0 , sizeof( V_147 ) ) ;
V_122 = F_80 ( V_77 + V_111 +
F_101 ( T_2 , V_112 , V_131 ) ) ;
V_112 = V_122 - V_77 - V_111 ;
V_148 = F_101 ( T_2 , V_122 , V_63 ) ;
V_109 = F_102 ( V_148 , V_113 ) ;
V_107 = V_109 / V_148 ;
while ( V_109 % V_107 || ( ( V_109 / V_107 ) & ~ V_130 ) )
V_107 -- ;
V_149 = V_107 ;
F_70 (cpu) {
V_105 = 0 ;
V_154:
F_70 (tcpu) {
if ( V_18 == V_153 )
break;
if ( V_146 [ V_153 ] == V_105 && V_145 &&
( V_145 ( V_18 , V_153 ) > V_155 ||
V_145 ( V_153 , V_18 ) > V_155 ) ) {
V_105 ++ ;
V_88 = F_5 ( V_88 , V_105 + 1 ) ;
goto V_154;
}
}
V_146 [ V_18 ] = V_105 ;
V_147 [ V_105 ] ++ ;
}
V_152 = V_156 ;
for ( V_107 = V_149 ; V_107 ; V_107 -- ) {
int V_157 = 0 , V_158 = 0 ;
if ( V_109 % V_107 || ( ( V_109 / V_107 ) & ~ V_130 ) )
continue;
for ( V_105 = 0 ; V_105 < V_88 ; V_105 ++ ) {
int V_159 = F_103 ( V_147 [ V_105 ] , V_107 ) ;
V_157 += V_159 ;
V_158 += V_159 * V_107 - V_147 [ V_105 ] ;
}
if ( V_158 > F_84 () / 3 )
continue;
if ( V_157 > V_152 )
break;
V_152 = V_157 ;
V_151 = V_107 ;
}
V_107 = V_151 ;
for ( V_105 = 0 ; V_105 < V_88 ; V_105 ++ )
V_89 += F_102 ( V_147 [ V_105 ] , V_107 ) ;
V_90 = F_77 ( V_88 , V_89 ) ;
if ( ! V_90 )
return F_104 ( - V_45 ) ;
V_95 = V_90 -> V_94 [ 0 ] . V_95 ;
for ( V_105 = 0 ; V_105 < V_88 ; V_105 ++ ) {
V_90 -> V_94 [ V_105 ] . V_95 = V_95 ;
V_95 += F_102 ( V_147 [ V_105 ] , V_107 ) ;
}
V_90 -> V_77 = V_77 ;
V_90 -> V_111 = V_111 ;
V_90 -> V_112 = V_112 ;
V_90 -> V_110 = V_109 / V_107 ;
V_90 -> V_113 = V_113 ;
V_90 -> V_109 = V_109 ;
for ( V_105 = 0 , V_93 = 0 ; V_147 [ V_105 ] ; V_105 ++ ) {
struct V_114 * V_115 = & V_90 -> V_94 [ V_105 ] ;
V_115 -> V_134 = V_93 * V_90 -> V_110 ;
F_70 (cpu)
if ( V_146 [ V_18 ] == V_105 )
V_115 -> V_95 [ V_115 -> V_89 ++ ] = V_18 ;
V_115 -> V_89 = F_102 ( V_115 -> V_89 , V_107 ) ;
V_93 += V_115 -> V_89 ;
}
F_32 ( V_93 != V_89 ) ;
return V_90 ;
}
int T_5 F_105 ( T_2 V_111 , T_2 V_112 ,
T_2 V_113 ,
T_7 V_145 ,
T_8 V_160 ,
T_9 V_161 )
{
void * V_80 = ( void * ) V_162 ;
void * * V_163 = NULL ;
struct V_87 * V_90 ;
T_2 V_122 , V_164 , V_165 ;
int V_105 , V_49 , V_166 ;
V_90 = F_100 ( V_111 , V_112 , V_113 ,
V_145 ) ;
if ( F_106 ( V_90 ) )
return F_107 ( V_90 ) ;
V_122 = V_90 -> V_77 + V_90 -> V_111 + V_90 -> V_112 ;
V_164 = F_80 ( V_90 -> V_88 * sizeof( void * ) ) ;
V_163 = F_79 ( V_164 ) ;
if ( ! V_163 ) {
V_166 = - V_45 ;
goto V_167;
}
for ( V_105 = 0 ; V_105 < V_90 -> V_88 ; V_105 ++ ) {
struct V_114 * V_115 = & V_90 -> V_94 [ V_105 ] ;
unsigned int V_18 = V_96 ;
void * V_30 ;
for ( V_49 = 0 ; V_49 < V_115 -> V_89 && V_18 == V_96 ; V_49 ++ )
V_18 = V_115 -> V_95 [ V_49 ] ;
F_32 ( V_18 == V_96 ) ;
V_30 = V_160 ( V_18 , V_115 -> V_89 * V_90 -> V_110 , V_113 ) ;
if ( ! V_30 ) {
V_166 = - V_45 ;
goto V_168;
}
V_163 [ V_105 ] = V_30 ;
V_80 = F_108 ( V_30 , V_80 ) ;
for ( V_49 = 0 ; V_49 < V_115 -> V_89 ; V_49 ++ , V_30 += V_90 -> V_110 ) {
if ( V_115 -> V_95 [ V_49 ] == V_96 ) {
V_161 ( V_30 , V_90 -> V_110 ) ;
continue;
}
memcpy ( V_30 , V_169 , V_90 -> V_77 ) ;
V_161 ( V_30 + V_122 , V_90 -> V_110 - V_122 ) ;
}
}
V_165 = 0 ;
for ( V_105 = 0 ; V_105 < V_90 -> V_88 ; V_105 ++ ) {
V_90 -> V_94 [ V_105 ] . V_134 = V_163 [ V_105 ] - V_80 ;
V_165 = F_101 ( T_2 , V_165 ,
V_90 -> V_94 [ V_105 ] . V_134 ) ;
}
V_165 += V_90 -> V_110 ;
if ( V_165 > ( V_170 - V_171 ) * 3 / 4 ) {
F_51 ( L_21
L_22 , V_165 ,
( unsigned long ) ( V_170 - V_171 ) ) ;
#ifdef F_99
V_166 = - V_172 ;
goto V_167;
#endif
}
F_53 ( L_23 ,
F_109 ( V_122 ) , V_80 , V_90 -> V_77 , V_90 -> V_111 ,
V_90 -> V_112 , V_90 -> V_110 ) ;
V_166 = F_88 ( V_90 , V_80 ) ;
goto V_167;
V_168:
for ( V_105 = 0 ; V_105 < V_90 -> V_88 ; V_105 ++ )
V_161 ( V_163 [ V_105 ] ,
V_90 -> V_94 [ V_105 ] . V_89 * V_90 -> V_110 ) ;
V_167:
F_81 ( V_90 ) ;
if ( V_163 )
F_82 ( F_74 ( V_163 ) , V_164 ) ;
return V_166 ;
}
int T_5 F_110 ( T_2 V_111 ,
T_8 V_160 ,
T_9 V_161 ,
T_10 V_173 )
{
static struct V_174 V_175 ;
struct V_87 * V_90 ;
char V_176 [ 16 ] ;
int V_177 ;
T_2 V_178 ;
struct V_15 * * V_179 ;
int V_93 , V_49 , V_180 , V_166 ;
snprintf ( V_176 , sizeof( V_176 ) , L_24 , V_28 >> 10 ) ;
V_90 = F_100 ( V_111 , 0 , V_28 , NULL ) ;
if ( F_106 ( V_90 ) )
return F_107 ( V_90 ) ;
F_32 ( V_90 -> V_88 != 1 ) ;
F_32 ( V_90 -> V_94 [ 0 ] . V_89 != F_84 () ) ;
V_177 = V_90 -> V_110 >> V_23 ;
V_178 = F_80 ( V_177 * F_84 () *
sizeof( V_179 [ 0 ] ) ) ;
V_179 = F_92 ( V_178 ) ;
V_180 = 0 ;
for ( V_93 = 0 ; V_93 < F_84 () ; V_93 ++ )
for ( V_49 = 0 ; V_49 < V_177 ; V_49 ++ ) {
unsigned int V_18 = V_90 -> V_94 [ 0 ] . V_95 [ V_93 ] ;
void * V_30 ;
V_30 = V_160 ( V_18 , V_28 , V_28 ) ;
if ( ! V_30 ) {
F_51 ( L_25
L_26 , V_176 , V_18 ) ;
goto V_181;
}
V_179 [ V_180 ++ ] = F_111 ( V_30 ) ;
}
V_175 . V_44 = V_182 ;
V_175 . V_7 = F_84 () * V_90 -> V_110 ;
F_112 ( & V_175 , V_28 ) ;
for ( V_93 = 0 ; V_93 < F_84 () ; V_93 ++ ) {
unsigned long V_183 =
( unsigned long ) V_175 . V_1 + V_93 * V_90 -> V_110 ;
for ( V_49 = 0 ; V_49 < V_177 ; V_49 ++ )
V_173 ( V_183 + ( V_49 << V_23 ) ) ;
V_166 = F_113 ( V_183 , & V_179 [ V_93 * V_177 ] ,
V_177 ) ;
if ( V_166 < 0 )
F_114 ( L_27 , V_166 ) ;
memcpy ( ( void * ) V_183 , V_169 , V_90 -> V_77 ) ;
}
F_53 ( L_28 ,
V_177 , V_176 , V_175 . V_1 , V_90 -> V_77 ,
V_90 -> V_111 , V_90 -> V_112 ) ;
V_166 = F_88 ( V_90 , V_175 . V_1 ) ;
goto V_184;
V_181:
while ( -- V_180 >= 0 )
V_161 ( F_115 ( V_179 [ V_180 ] ) , V_28 ) ;
V_166 = - V_45 ;
V_184:
F_82 ( F_74 ( V_179 ) , V_178 ) ;
F_81 ( V_90 ) ;
return V_166 ;
}
static void * T_5 F_116 ( unsigned int V_18 , T_2 V_7 ,
T_2 V_53 )
{
return F_117 ( V_7 , V_53 , F_74 ( V_185 ) ) ;
}
static void T_5 F_118 ( void * V_30 , T_2 V_7 )
{
F_82 ( F_74 ( V_30 ) , V_7 ) ;
}
void T_5 F_119 ( void )
{
unsigned long V_186 ;
unsigned int V_18 ;
int V_166 ;
V_166 = F_105 ( V_187 ,
V_188 , V_28 , NULL ,
F_116 , F_118 ) ;
if ( V_166 < 0 )
F_114 ( L_29 ) ;
V_186 = ( unsigned long ) V_81 - ( unsigned long ) V_79 ;
F_70 (cpu)
V_189 [ V_18 ] = V_186 + V_22 [ V_18 ] ;
}
void T_5 F_119 ( void )
{
const T_2 V_110 =
F_120 ( F_101 ( T_2 , V_63 ,
V_188 ) ) ;
struct V_87 * V_90 ;
void * V_190 ;
V_90 = F_77 ( 1 , 1 ) ;
V_190 = F_121 ( V_110 , V_28 , F_74 ( V_185 ) ) ;
if ( ! V_90 || ! V_190 )
F_114 ( L_30 ) ;
V_90 -> V_112 = V_110 ;
V_90 -> V_110 = V_110 ;
V_90 -> V_113 = V_110 ;
V_90 -> V_109 = V_110 ;
V_90 -> V_94 [ 0 ] . V_89 = 1 ;
V_90 -> V_94 [ 0 ] . V_95 [ 0 ] = 0 ;
if ( F_88 ( V_90 , V_190 ) < 0 )
F_114 ( L_29 ) ;
}
void T_5 F_122 ( void )
{
struct V_11 * V_191 [] =
{ V_3 , V_33 , NULL } ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_49 ;
for ( V_49 = 0 ; ( V_12 = V_191 [ V_49 ] ) ; V_49 ++ ) {
int * V_48 ;
const T_2 V_7 = V_120 * sizeof( V_48 [ 0 ] ) ;
F_123 ( V_7 > V_28 ) ;
V_48 = F_16 ( V_7 ) ;
F_32 ( ! V_48 ) ;
F_29 ( & V_46 , V_44 ) ;
memcpy ( V_48 , V_12 -> V_48 , V_7 ) ;
V_12 -> V_48 = V_48 ;
F_30 ( & V_46 , V_44 ) ;
}
}
