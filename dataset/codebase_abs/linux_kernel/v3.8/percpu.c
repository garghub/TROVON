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
V_12 -> V_48 = F_16 ( V_39 *
sizeof( V_12 -> V_48 [ 0 ] ) ) ;
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
F_21 ( V_12 , V_58 ) ;
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
void T_3 * V_30 ;
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
V_30 = F_50 ( V_12 -> V_4 + V_55 ) ;
F_51 ( V_30 , V_7 ) ;
return V_30 ;
V_65:
F_30 ( & V_46 , V_44 ) ;
V_66:
F_49 ( & V_64 ) ;
if ( V_60 ) {
F_52 ( L_8
L_9 , V_7 , V_53 , V_61 ) ;
F_53 () ;
if ( ! -- V_60 )
F_54 ( L_10 ) ;
}
return NULL ;
}
void T_3 * F_55 ( T_2 V_7 , T_2 V_53 )
{
return F_42 ( V_7 , V_53 , false ) ;
}
void T_3 * F_56 ( T_2 V_7 , T_2 V_53 )
{
return F_42 ( V_7 , V_53 , true ) ;
}
static void F_57 ( struct V_69 * V_70 )
{
F_58 ( V_71 ) ;
struct V_72 * V_50 = & V_35 [ V_10 - 1 ] ;
struct V_11 * V_12 , * V_73 ;
F_45 ( & V_64 ) ;
F_59 ( & V_46 ) ;
F_60 (chunk, next, head, list) {
F_61 ( V_12 -> V_74 ) ;
if ( V_12 == F_62 ( V_50 , struct V_11 , V_34 ) )
continue;
F_25 ( & V_12 -> V_34 , & V_71 ) ;
}
F_63 ( & V_46 ) ;
F_60 (chunk, next, &todo, list) {
F_64 ( V_12 , 0 , V_5 ) ;
F_65 ( V_12 ) ;
}
F_49 ( & V_64 ) ;
}
void F_66 ( void T_3 * V_30 )
{
void * V_1 ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_55 ;
if ( ! V_30 )
return;
F_67 ( V_30 ) ;
V_1 = F_68 ( V_30 ) ;
F_29 ( & V_46 , V_44 ) ;
V_12 = F_39 ( V_1 ) ;
V_55 = V_1 - V_12 -> V_4 ;
F_35 ( V_12 , V_55 ) ;
if ( V_12 -> V_13 == V_5 ) {
struct V_11 * V_75 ;
F_46 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_75 != V_12 ) {
F_69 ( & V_76 ) ;
break;
}
}
F_30 ( & V_46 , V_44 ) ;
}
bool F_70 ( unsigned long V_1 )
{
#ifdef F_71
const T_2 V_77 = V_78 - V_79 ;
void T_3 * V_80 = F_50 ( V_81 ) ;
unsigned int V_18 ;
F_72 (cpu) {
void * V_82 = F_73 ( V_80 , V_18 ) ;
if ( ( void * ) V_1 >= V_82 && ( void * ) V_1 < V_82 + V_77 )
return true ;
}
#endif
return false ;
}
T_4 F_74 ( void * V_1 )
{
void T_3 * V_80 = F_50 ( V_81 ) ;
bool V_83 = false ;
unsigned long V_84 , V_85 ;
unsigned int V_18 ;
V_84 = F_11 ( V_3 , V_86 , 0 ) ;
V_85 = F_11 ( V_3 , V_87 ,
V_21 ) ;
if ( ( unsigned long ) V_1 >= V_84 &&
( unsigned long ) V_1 < V_85 ) {
F_72 (cpu) {
void * V_82 = F_73 ( V_80 , V_18 ) ;
if ( V_1 >= V_82 && V_1 < V_82 + V_5 ) {
V_83 = true ;
break;
}
}
}
if ( V_83 ) {
if ( ! F_75 ( V_1 ) )
return F_76 ( V_1 ) ;
else
return F_77 ( F_78 ( V_1 ) ) +
F_79 ( V_1 ) ;
} else
return F_77 ( F_41 ( V_1 ) ) +
F_79 ( V_1 ) ;
}
struct V_88 * T_5 F_80 ( int V_89 ,
int V_90 )
{
struct V_88 * V_91 ;
T_2 V_92 , V_93 ;
void * V_30 ;
int V_94 ;
V_92 = F_34 ( sizeof( * V_91 ) + V_89 * sizeof( V_91 -> V_95 [ 0 ] ) ,
F_81 ( V_91 -> V_95 [ 0 ] . V_96 [ 0 ] ) ) ;
V_93 = V_92 + V_90 * sizeof( V_91 -> V_95 [ 0 ] . V_96 [ 0 ] ) ;
V_30 = F_82 ( F_83 ( V_93 ) ) ;
if ( ! V_30 )
return NULL ;
V_91 = V_30 ;
V_30 += V_92 ;
V_91 -> V_95 [ 0 ] . V_96 = V_30 ;
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ )
V_91 -> V_95 [ 0 ] . V_96 [ V_94 ] = V_97 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_98 = F_83 ( V_93 ) ;
return V_91 ;
}
void T_5 F_84 ( struct V_88 * V_91 )
{
F_85 ( F_76 ( V_91 ) , V_91 -> V_98 ) ;
}
static void F_86 ( const char * V_99 ,
const struct V_88 * V_91 )
{
int V_100 = 1 , V_101 = 1 , V_102 ;
char V_103 [] = L_11 ;
int V_104 = 0 , V_105 = 0 ;
int V_106 , V_107 ;
int V_108 , V_109 ;
V_107 = V_91 -> V_89 ;
while ( V_107 /= 10 )
V_100 ++ ;
V_107 = F_87 () ;
while ( V_107 /= 10 )
V_101 ++ ;
V_103 [ F_88 ( int , V_101 , sizeof( V_103 ) - 1 ) ] = '\0' ;
V_108 = V_91 -> V_110 / V_91 -> V_111 ;
V_102 = V_108 * ( V_101 + 1 ) + V_100 + 3 ;
V_109 = F_89 ( F_5 ( 60 / V_102 , 1 ) ) ;
F_90 ( L_12 ,
V_99 , V_91 -> V_77 , V_91 -> V_112 , V_91 -> V_113 ,
V_91 -> V_111 , V_91 -> V_110 / V_91 -> V_114 , V_91 -> V_114 ) ;
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
const struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
int V_94 = 0 , V_117 = 0 ;
F_32 ( V_116 -> V_90 % V_108 ) ;
for ( V_105 += V_116 -> V_90 / V_108 ;
V_104 < V_105 ; V_104 ++ ) {
if ( ! ( V_104 % V_109 ) ) {
F_90 ( V_118 L_13 ) ;
F_90 ( L_14 , V_99 ) ;
}
F_90 ( V_118 L_15 , V_100 , V_106 ) ;
for ( V_117 += V_108 ; V_94 < V_117 ; V_94 ++ )
if ( V_116 -> V_96 [ V_94 ] != V_97 )
F_90 ( V_118 L_16 , V_101 ,
V_116 -> V_96 [ V_94 ] ) ;
else
F_90 ( V_118 L_17 , V_103 ) ;
}
}
F_90 ( V_118 L_13 ) ;
}
int T_5 F_91 ( const struct V_88 * V_91 ,
void * V_4 )
{
static char V_119 [ 4096 ] V_120 ;
static int V_121 [ V_122 ] V_120 ;
static int V_123 [ V_122 ] V_120 ;
T_2 V_113 = V_91 -> V_113 ;
T_2 V_124 = V_91 -> V_77 + V_91 -> V_112 + V_113 ;
struct V_11 * V_125 , * V_126 = NULL ;
unsigned long * V_127 ;
T_2 * V_128 ;
unsigned long * V_129 ;
unsigned int V_18 ;
int * V_130 ;
int V_106 , V_94 , V_49 ;
F_92 ( V_119 , sizeof( V_119 ) , V_131 ) ;
#define F_93 ( T_6 ) do { \
if (unlikely(cond)) { \
pr_emerg("PERCPU: failed to initialize, %s", #cond); \
pr_emerg("PERCPU: cpu_possible_mask=%s\n", cpus_buf); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_93 ( V_91 -> V_89 <= 0 ) ;
#ifdef F_71
F_93 ( ! V_91 -> V_77 ) ;
F_93 ( ( unsigned long ) V_79 & ~ V_132 ) ;
#endif
F_93 ( ! V_4 ) ;
F_93 ( ( unsigned long ) V_4 & ~ V_132 ) ;
F_93 ( V_91 -> V_111 < V_124 ) ;
F_93 ( V_91 -> V_111 & ~ V_132 ) ;
F_93 ( V_91 -> V_111 < V_63 ) ;
F_93 ( V_91 -> V_113 < V_133 ) ;
F_93 ( F_94 ( V_91 ) < 0 ) ;
V_127 = F_95 ( V_91 -> V_89 * sizeof( V_127 [ 0 ] ) ) ;
V_128 = F_95 ( V_91 -> V_89 * sizeof( V_128 [ 0 ] ) ) ;
V_130 = F_95 ( V_134 * sizeof( V_130 [ 0 ] ) ) ;
V_129 = F_95 ( V_134 * sizeof( V_129 [ 0 ] ) ) ;
for ( V_18 = 0 ; V_18 < V_134 ; V_18 ++ )
V_130 [ V_18 ] = V_135 ;
V_86 = V_97 ;
V_87 = V_97 ;
for ( V_106 = 0 , V_94 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ , V_94 += V_49 ) {
const struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
V_127 [ V_106 ] = V_116 -> V_136 ;
V_128 [ V_106 ] = V_116 -> V_90 * V_91 -> V_111 ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 ; V_49 ++ ) {
V_18 = V_116 -> V_96 [ V_49 ] ;
if ( V_18 == V_97 )
continue;
F_93 ( V_18 > V_134 ) ;
F_93 ( ! F_96 ( V_18 ) ) ;
F_93 ( V_130 [ V_18 ] != V_135 ) ;
V_130 [ V_18 ] = V_94 + V_49 ;
V_129 [ V_18 ] = V_116 -> V_136 + V_49 * V_91 -> V_111 ;
if ( V_86 == V_97 ||
V_129 [ V_18 ] < V_129 [ V_86 ] )
V_86 = V_18 ;
if ( V_87 == V_97 ||
V_129 [ V_18 ] > V_129 [ V_87 ] )
V_87 = V_18 ;
}
}
V_137 = V_94 ;
F_72 (cpu)
F_93 ( V_130 [ V_18 ] == V_135 ) ;
#undef F_93
F_86 ( V_138 , V_91 ) ;
V_139 = V_91 -> V_89 ;
V_140 = V_127 ;
V_141 = V_128 ;
V_20 = V_130 ;
V_22 = V_129 ;
V_21 = V_91 -> V_111 >> V_23 ;
V_5 = V_21 << V_23 ;
V_142 = V_91 -> V_114 ;
V_58 = sizeof( struct V_11 ) +
F_97 ( V_21 ) * sizeof( unsigned long ) ;
V_10 = F_3 ( V_5 ) + 2 ;
V_35 = F_95 ( V_10 * sizeof( V_35 [ 0 ] ) ) ;
for ( V_49 = 0 ; V_49 < V_10 ; V_49 ++ )
F_37 ( & V_35 [ V_49 ] ) ;
V_125 = F_95 ( V_58 ) ;
F_37 ( & V_125 -> V_34 ) ;
V_125 -> V_4 = V_4 ;
V_125 -> V_48 = V_121 ;
V_125 -> V_37 = F_98 ( V_121 ) ;
V_125 -> V_74 = true ;
F_99 ( V_125 -> V_27 , V_21 ) ;
if ( V_91 -> V_112 ) {
V_125 -> V_13 = V_91 -> V_112 ;
V_33 = V_125 ;
V_6 = V_91 -> V_77 + V_91 -> V_112 ;
} else {
V_125 -> V_13 = V_113 ;
V_113 = 0 ;
}
V_125 -> V_14 = V_125 -> V_13 ;
V_125 -> V_48 [ V_125 -> V_38 ++ ] = - V_91 -> V_77 ;
if ( V_125 -> V_13 )
V_125 -> V_48 [ V_125 -> V_38 ++ ] = V_125 -> V_13 ;
if ( V_113 ) {
V_126 = F_95 ( V_58 ) ;
F_37 ( & V_126 -> V_34 ) ;
V_126 -> V_4 = V_4 ;
V_126 -> V_48 = V_123 ;
V_126 -> V_37 = F_98 ( V_123 ) ;
V_126 -> V_74 = true ;
F_99 ( V_126 -> V_27 , V_21 ) ;
V_126 -> V_14 = V_126 -> V_13 = V_113 ;
V_126 -> V_48 [ V_126 -> V_38 ++ ] = - V_6 ;
V_126 -> V_48 [ V_126 -> V_38 ++ ] = V_126 -> V_13 ;
}
V_3 = V_126 ? : V_125 ;
F_24 ( V_3 , - 1 ) ;
V_81 = V_4 ;
return 0 ;
}
static int T_5 F_100 ( char * V_143 )
{
if ( ! V_143 )
return - V_144 ;
if ( 0 )
;
#ifdef F_101
else if ( ! strcmp ( V_143 , L_18 ) )
V_145 = V_146 ;
#endif
#ifdef F_102
else if ( ! strcmp ( V_143 , L_19 ) )
V_145 = V_147 ;
#endif
else
F_52 ( L_20 , V_143 ) ;
return 0 ;
}
static struct V_88 * T_5 F_103 (
T_2 V_112 , T_2 V_113 ,
T_2 V_114 ,
T_7 V_148 )
{
static int V_149 [ V_97 ] V_120 ;
static int V_150 [ V_97 ] V_120 ;
const T_2 V_77 = V_78 - V_79 ;
int V_89 = 1 , V_90 = 0 ;
T_2 V_124 , V_151 , V_110 ;
int V_108 , V_152 , V_153 ( V_154 ) ;
int V_155 , V_106 , V_94 ;
unsigned int V_18 , V_156 ;
struct V_88 * V_91 ;
unsigned int * V_96 ;
memset ( V_149 , 0 , sizeof( V_149 ) ) ;
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
V_124 = F_83 ( V_77 + V_112 +
F_104 ( T_2 , V_113 , V_133 ) ) ;
V_113 = V_124 - V_77 - V_112 ;
V_151 = F_104 ( T_2 , V_124 , V_63 ) ;
V_110 = F_105 ( V_151 , V_114 ) ;
V_108 = V_110 / V_151 ;
while ( V_110 % V_108 || ( ( V_110 / V_108 ) & ~ V_132 ) )
V_108 -- ;
V_152 = V_108 ;
F_72 (cpu) {
V_106 = 0 ;
V_157:
F_72 (tcpu) {
if ( V_18 == V_156 )
break;
if ( V_149 [ V_156 ] == V_106 && V_148 &&
( V_148 ( V_18 , V_156 ) > V_158 ||
V_148 ( V_156 , V_18 ) > V_158 ) ) {
V_106 ++ ;
V_89 = F_5 ( V_89 , V_106 + 1 ) ;
goto V_157;
}
}
V_149 [ V_18 ] = V_106 ;
V_150 [ V_106 ] ++ ;
}
V_155 = V_159 ;
for ( V_108 = V_152 ; V_108 ; V_108 -- ) {
int V_160 = 0 , V_161 = 0 ;
if ( V_110 % V_108 || ( ( V_110 / V_108 ) & ~ V_132 ) )
continue;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ ) {
int V_162 = F_106 ( V_150 [ V_106 ] , V_108 ) ;
V_160 += V_162 ;
V_161 += V_162 * V_108 - V_150 [ V_106 ] ;
}
if ( V_161 > F_87 () / 3 )
continue;
if ( V_160 > V_155 )
break;
V_155 = V_160 ;
V_154 = V_108 ;
}
V_108 = V_154 ;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ )
V_90 += F_105 ( V_150 [ V_106 ] , V_108 ) ;
V_91 = F_80 ( V_89 , V_90 ) ;
if ( ! V_91 )
return F_107 ( - V_45 ) ;
V_96 = V_91 -> V_95 [ 0 ] . V_96 ;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ ) {
V_91 -> V_95 [ V_106 ] . V_96 = V_96 ;
V_96 += F_105 ( V_150 [ V_106 ] , V_108 ) ;
}
V_91 -> V_77 = V_77 ;
V_91 -> V_112 = V_112 ;
V_91 -> V_113 = V_113 ;
V_91 -> V_111 = V_110 / V_108 ;
V_91 -> V_114 = V_114 ;
V_91 -> V_110 = V_110 ;
for ( V_106 = 0 , V_94 = 0 ; V_150 [ V_106 ] ; V_106 ++ ) {
struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
V_116 -> V_136 = V_94 * V_91 -> V_111 ;
F_72 (cpu)
if ( V_149 [ V_18 ] == V_106 )
V_116 -> V_96 [ V_116 -> V_90 ++ ] = V_18 ;
V_116 -> V_90 = F_105 ( V_116 -> V_90 , V_108 ) ;
V_94 += V_116 -> V_90 ;
}
F_32 ( V_94 != V_90 ) ;
return V_91 ;
}
int T_5 F_108 ( T_2 V_112 , T_2 V_113 ,
T_2 V_114 ,
T_7 V_148 ,
T_8 V_163 ,
T_9 V_164 )
{
void * V_80 = ( void * ) V_165 ;
void * * V_166 = NULL ;
struct V_88 * V_91 ;
T_2 V_124 , V_167 , V_168 ;
int V_106 , V_49 , V_169 ;
V_91 = F_103 ( V_112 , V_113 , V_114 ,
V_148 ) ;
if ( F_109 ( V_91 ) )
return F_110 ( V_91 ) ;
V_124 = V_91 -> V_77 + V_91 -> V_112 + V_91 -> V_113 ;
V_167 = F_83 ( V_91 -> V_89 * sizeof( void * ) ) ;
V_166 = F_82 ( V_167 ) ;
if ( ! V_166 ) {
V_169 = - V_45 ;
goto V_170;
}
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
unsigned int V_18 = V_97 ;
void * V_30 ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 && V_18 == V_97 ; V_49 ++ )
V_18 = V_116 -> V_96 [ V_49 ] ;
F_32 ( V_18 == V_97 ) ;
V_30 = V_163 ( V_18 , V_116 -> V_90 * V_91 -> V_111 , V_114 ) ;
if ( ! V_30 ) {
V_169 = - V_45 ;
goto V_171;
}
F_111 ( V_30 ) ;
V_166 [ V_106 ] = V_30 ;
V_80 = F_112 ( V_30 , V_80 ) ;
}
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
void * V_30 = V_166 [ V_106 ] ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 ; V_49 ++ , V_30 += V_91 -> V_111 ) {
if ( V_116 -> V_96 [ V_49 ] == V_97 ) {
V_164 ( V_30 , V_91 -> V_111 ) ;
continue;
}
memcpy ( V_30 , V_172 , V_91 -> V_77 ) ;
V_164 ( V_30 + V_124 , V_91 -> V_111 - V_124 ) ;
}
}
V_168 = 0 ;
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
V_91 -> V_95 [ V_106 ] . V_136 = V_166 [ V_106 ] - V_80 ;
V_168 = F_104 ( T_2 , V_168 ,
V_91 -> V_95 [ V_106 ] . V_136 ) ;
}
V_168 += V_91 -> V_111 ;
if ( V_168 > ( V_173 - V_174 ) * 3 / 4 ) {
F_52 ( L_21
L_22 , V_168 ,
( unsigned long ) ( V_173 - V_174 ) ) ;
#ifdef F_102
V_169 = - V_144 ;
goto V_170;
#endif
}
F_54 ( L_23 ,
F_113 ( V_124 ) , V_80 , V_91 -> V_77 , V_91 -> V_112 ,
V_91 -> V_113 , V_91 -> V_111 ) ;
V_169 = F_91 ( V_91 , V_80 ) ;
goto V_170;
V_171:
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ )
V_164 ( V_166 [ V_106 ] ,
V_91 -> V_95 [ V_106 ] . V_90 * V_91 -> V_111 ) ;
V_170:
F_84 ( V_91 ) ;
if ( V_166 )
F_85 ( F_76 ( V_166 ) , V_167 ) ;
return V_169 ;
}
int T_5 F_114 ( T_2 V_112 ,
T_8 V_163 ,
T_9 V_164 ,
T_10 V_175 )
{
static struct V_176 V_177 ;
struct V_88 * V_91 ;
char V_178 [ 16 ] ;
int V_179 ;
T_2 V_180 ;
struct V_15 * * V_181 ;
int V_94 , V_49 , V_182 , V_169 ;
snprintf ( V_178 , sizeof( V_178 ) , L_24 , V_28 >> 10 ) ;
V_91 = F_103 ( V_112 , 0 , V_28 , NULL ) ;
if ( F_109 ( V_91 ) )
return F_110 ( V_91 ) ;
F_32 ( V_91 -> V_89 != 1 ) ;
F_32 ( V_91 -> V_95 [ 0 ] . V_90 != F_87 () ) ;
V_179 = V_91 -> V_111 >> V_23 ;
V_180 = F_83 ( V_179 * F_87 () *
sizeof( V_181 [ 0 ] ) ) ;
V_181 = F_95 ( V_180 ) ;
V_182 = 0 ;
for ( V_94 = 0 ; V_94 < F_87 () ; V_94 ++ )
for ( V_49 = 0 ; V_49 < V_179 ; V_49 ++ ) {
unsigned int V_18 = V_91 -> V_95 [ 0 ] . V_96 [ V_94 ] ;
void * V_30 ;
V_30 = V_163 ( V_18 , V_28 , V_28 ) ;
if ( ! V_30 ) {
F_52 ( L_25
L_26 , V_178 , V_18 ) ;
goto V_183;
}
F_111 ( V_30 ) ;
V_181 [ V_182 ++ ] = F_115 ( V_30 ) ;
}
V_177 . V_44 = V_184 ;
V_177 . V_7 = F_87 () * V_91 -> V_111 ;
F_116 ( & V_177 , V_28 ) ;
for ( V_94 = 0 ; V_94 < F_87 () ; V_94 ++ ) {
unsigned long V_185 =
( unsigned long ) V_177 . V_1 + V_94 * V_91 -> V_111 ;
for ( V_49 = 0 ; V_49 < V_179 ; V_49 ++ )
V_175 ( V_185 + ( V_49 << V_23 ) ) ;
V_169 = F_117 ( V_185 , & V_181 [ V_94 * V_179 ] ,
V_179 ) ;
if ( V_169 < 0 )
F_118 ( L_27 , V_169 ) ;
memcpy ( ( void * ) V_185 , V_172 , V_91 -> V_77 ) ;
}
F_54 ( L_28 ,
V_179 , V_178 , V_177 . V_1 , V_91 -> V_77 ,
V_91 -> V_112 , V_91 -> V_113 ) ;
V_169 = F_91 ( V_91 , V_177 . V_1 ) ;
goto V_186;
V_183:
while ( -- V_182 >= 0 )
V_164 ( F_119 ( V_181 [ V_182 ] ) , V_28 ) ;
V_169 = - V_45 ;
V_186:
F_85 ( F_76 ( V_181 ) , V_180 ) ;
F_84 ( V_91 ) ;
return V_169 ;
}
static void * T_5 F_120 ( unsigned int V_18 , T_2 V_7 ,
T_2 V_53 )
{
return F_121 ( V_7 , V_53 , F_76 ( V_187 ) ) ;
}
static void T_5 F_122 ( void * V_30 , T_2 V_7 )
{
F_85 ( F_76 ( V_30 ) , V_7 ) ;
}
void T_5 F_123 ( void )
{
unsigned long V_188 ;
unsigned int V_18 ;
int V_169 ;
V_169 = F_108 ( V_189 ,
V_190 , V_28 , NULL ,
F_120 , F_122 ) ;
if ( V_169 < 0 )
F_118 ( L_29 ) ;
V_188 = ( unsigned long ) V_81 - ( unsigned long ) V_79 ;
F_72 (cpu)
V_191 [ V_18 ] = V_188 + V_22 [ V_18 ] ;
}
void T_5 F_123 ( void )
{
const T_2 V_111 =
F_124 ( F_104 ( T_2 , V_63 ,
V_190 ) ) ;
struct V_88 * V_91 ;
void * V_192 ;
V_91 = F_80 ( 1 , 1 ) ;
V_192 = F_125 ( V_111 , V_28 , F_76 ( V_187 ) ) ;
if ( ! V_91 || ! V_192 )
F_118 ( L_30 ) ;
F_111 ( V_192 ) ;
V_91 -> V_113 = V_111 ;
V_91 -> V_111 = V_111 ;
V_91 -> V_114 = V_111 ;
V_91 -> V_110 = V_111 ;
V_91 -> V_95 [ 0 ] . V_90 = 1 ;
V_91 -> V_95 [ 0 ] . V_96 [ 0 ] = 0 ;
if ( F_91 ( V_91 , V_192 ) < 0 )
F_118 ( L_29 ) ;
}
void T_5 F_126 ( void )
{
struct V_11 * V_193 [] =
{ V_3 , V_33 , NULL } ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_49 ;
for ( V_49 = 0 ; ( V_12 = V_193 [ V_49 ] ) ; V_49 ++ ) {
int * V_48 ;
const T_2 V_7 = V_122 * sizeof( V_48 [ 0 ] ) ;
F_127 ( V_7 > V_28 ) ;
V_48 = F_16 ( V_7 ) ;
F_32 ( ! V_48 ) ;
F_29 ( & V_46 , V_44 ) ;
memcpy ( V_48 , V_12 -> V_48 , V_7 ) ;
V_12 -> V_48 = V_48 ;
F_30 ( & V_46 , V_44 ) ;
}
}
