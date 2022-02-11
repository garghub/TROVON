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
unsigned long V_84 , V_85 ;
unsigned int V_18 ;
V_84 = F_11 ( V_3 , V_86 , 0 ) ;
V_85 = F_11 ( V_3 , V_87 ,
V_21 ) ;
if ( ( unsigned long ) V_1 >= V_84 &&
( unsigned long ) V_1 < V_85 ) {
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
return F_75 ( F_76 ( V_1 ) ) +
F_77 ( V_1 ) ;
} else
return F_75 ( F_41 ( V_1 ) ) +
F_77 ( V_1 ) ;
}
struct V_88 * T_5 F_78 ( int V_89 ,
int V_90 )
{
struct V_88 * V_91 ;
T_2 V_92 , V_93 ;
void * V_30 ;
int V_94 ;
V_92 = F_34 ( sizeof( * V_91 ) + V_89 * sizeof( V_91 -> V_95 [ 0 ] ) ,
F_79 ( V_91 -> V_95 [ 0 ] . V_96 [ 0 ] ) ) ;
V_93 = V_92 + V_90 * sizeof( V_91 -> V_95 [ 0 ] . V_96 [ 0 ] ) ;
V_30 = F_80 ( F_81 ( V_93 ) ) ;
if ( ! V_30 )
return NULL ;
V_91 = V_30 ;
V_30 += V_92 ;
V_91 -> V_95 [ 0 ] . V_96 = V_30 ;
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ )
V_91 -> V_95 [ 0 ] . V_96 [ V_94 ] = V_97 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_98 = F_81 ( V_93 ) ;
return V_91 ;
}
void T_5 F_82 ( struct V_88 * V_91 )
{
F_83 ( F_74 ( V_91 ) , V_91 -> V_98 ) ;
}
static void F_84 ( const char * V_99 ,
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
V_107 = F_85 () ;
while ( V_107 /= 10 )
V_101 ++ ;
V_103 [ F_86 ( int , V_101 , sizeof( V_103 ) - 1 ) ] = '\0' ;
V_108 = V_91 -> V_110 / V_91 -> V_111 ;
V_102 = V_108 * ( V_101 + 1 ) + V_100 + 3 ;
V_109 = F_87 ( F_5 ( 60 / V_102 , 1 ) ) ;
F_88 ( L_12 ,
V_99 , V_91 -> V_77 , V_91 -> V_112 , V_91 -> V_113 ,
V_91 -> V_111 , V_91 -> V_110 / V_91 -> V_114 , V_91 -> V_114 ) ;
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
const struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
int V_94 = 0 , V_117 = 0 ;
F_32 ( V_116 -> V_90 % V_108 ) ;
for ( V_105 += V_116 -> V_90 / V_108 ;
V_104 < V_105 ; V_104 ++ ) {
if ( ! ( V_104 % V_109 ) ) {
F_88 ( L_13 ) ;
F_88 ( L_14 , V_99 ) ;
}
F_88 ( L_15 , V_100 , V_106 ) ;
for ( V_117 += V_108 ; V_94 < V_117 ; V_94 ++ )
if ( V_116 -> V_96 [ V_94 ] != V_97 )
F_88 ( L_16 , V_101 ,
V_116 -> V_96 [ V_94 ] ) ;
else
F_88 ( L_17 , V_103 ) ;
}
}
F_88 ( L_13 ) ;
}
int T_5 F_89 ( const struct V_88 * V_91 ,
void * V_4 )
{
static char V_118 [ 4096 ] V_119 ;
static int V_120 [ V_121 ] V_119 ;
static int V_122 [ V_121 ] V_119 ;
T_2 V_113 = V_91 -> V_113 ;
T_2 V_123 = V_91 -> V_77 + V_91 -> V_112 + V_113 ;
struct V_11 * V_124 , * V_125 = NULL ;
unsigned long * V_126 ;
T_2 * V_127 ;
unsigned long * V_128 ;
unsigned int V_18 ;
int * V_129 ;
int V_106 , V_94 , V_49 ;
F_90 ( V_118 , sizeof( V_118 ) , V_130 ) ;
#define F_91 ( T_6 ) do { \
if (unlikely(cond)) { \
pr_emerg("PERCPU: failed to initialize, %s", #cond); \
pr_emerg("PERCPU: cpu_possible_mask=%s\n", cpus_buf); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_91 ( V_91 -> V_89 <= 0 ) ;
#ifdef F_69
F_91 ( ! V_91 -> V_77 ) ;
F_91 ( ( unsigned long ) V_79 & ~ V_131 ) ;
#endif
F_91 ( ! V_4 ) ;
F_91 ( ( unsigned long ) V_4 & ~ V_131 ) ;
F_91 ( V_91 -> V_111 < V_123 ) ;
F_91 ( V_91 -> V_111 & ~ V_131 ) ;
F_91 ( V_91 -> V_111 < V_63 ) ;
F_91 ( V_91 -> V_113 < V_132 ) ;
F_91 ( F_92 ( V_91 ) < 0 ) ;
V_126 = F_93 ( V_91 -> V_89 * sizeof( V_126 [ 0 ] ) ) ;
V_127 = F_93 ( V_91 -> V_89 * sizeof( V_127 [ 0 ] ) ) ;
V_129 = F_93 ( V_133 * sizeof( V_129 [ 0 ] ) ) ;
V_128 = F_93 ( V_133 * sizeof( V_128 [ 0 ] ) ) ;
for ( V_18 = 0 ; V_18 < V_133 ; V_18 ++ )
V_129 [ V_18 ] = V_134 ;
V_86 = V_97 ;
V_87 = V_97 ;
for ( V_106 = 0 , V_94 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ , V_94 += V_49 ) {
const struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
V_126 [ V_106 ] = V_116 -> V_135 ;
V_127 [ V_106 ] = V_116 -> V_90 * V_91 -> V_111 ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 ; V_49 ++ ) {
V_18 = V_116 -> V_96 [ V_49 ] ;
if ( V_18 == V_97 )
continue;
F_91 ( V_18 > V_133 ) ;
F_91 ( ! F_94 ( V_18 ) ) ;
F_91 ( V_129 [ V_18 ] != V_134 ) ;
V_129 [ V_18 ] = V_94 + V_49 ;
V_128 [ V_18 ] = V_116 -> V_135 + V_49 * V_91 -> V_111 ;
if ( V_86 == V_97 ||
V_128 [ V_18 ] < V_128 [ V_86 ] )
V_86 = V_18 ;
if ( V_87 == V_97 ||
V_128 [ V_18 ] > V_128 [ V_87 ] )
V_87 = V_18 ;
}
}
V_136 = V_94 ;
F_70 (cpu)
F_91 ( V_129 [ V_18 ] == V_134 ) ;
#undef F_91
F_84 ( V_137 , V_91 ) ;
V_138 = V_91 -> V_89 ;
V_139 = V_126 ;
V_140 = V_127 ;
V_20 = V_129 ;
V_22 = V_128 ;
V_21 = V_91 -> V_111 >> V_23 ;
V_5 = V_21 << V_23 ;
V_141 = V_91 -> V_114 ;
V_58 = sizeof( struct V_11 ) +
F_95 ( V_21 ) * sizeof( unsigned long ) ;
V_10 = F_3 ( V_5 ) + 2 ;
V_35 = F_93 ( V_10 * sizeof( V_35 [ 0 ] ) ) ;
for ( V_49 = 0 ; V_49 < V_10 ; V_49 ++ )
F_37 ( & V_35 [ V_49 ] ) ;
V_124 = F_93 ( V_58 ) ;
F_37 ( & V_124 -> V_34 ) ;
V_124 -> V_4 = V_4 ;
V_124 -> V_48 = V_120 ;
V_124 -> V_37 = F_96 ( V_120 ) ;
V_124 -> V_74 = true ;
F_97 ( V_124 -> V_27 , V_21 ) ;
if ( V_91 -> V_112 ) {
V_124 -> V_13 = V_91 -> V_112 ;
V_33 = V_124 ;
V_6 = V_91 -> V_77 + V_91 -> V_112 ;
} else {
V_124 -> V_13 = V_113 ;
V_113 = 0 ;
}
V_124 -> V_14 = V_124 -> V_13 ;
V_124 -> V_48 [ V_124 -> V_38 ++ ] = - V_91 -> V_77 ;
if ( V_124 -> V_13 )
V_124 -> V_48 [ V_124 -> V_38 ++ ] = V_124 -> V_13 ;
if ( V_113 ) {
V_125 = F_93 ( V_58 ) ;
F_37 ( & V_125 -> V_34 ) ;
V_125 -> V_4 = V_4 ;
V_125 -> V_48 = V_122 ;
V_125 -> V_37 = F_96 ( V_122 ) ;
V_125 -> V_74 = true ;
F_97 ( V_125 -> V_27 , V_21 ) ;
V_125 -> V_14 = V_125 -> V_13 = V_113 ;
V_125 -> V_48 [ V_125 -> V_38 ++ ] = - V_6 ;
V_125 -> V_48 [ V_125 -> V_38 ++ ] = V_125 -> V_13 ;
}
V_3 = V_125 ? : V_124 ;
F_24 ( V_3 , - 1 ) ;
V_81 = V_4 ;
return 0 ;
}
static int T_5 F_98 ( char * V_142 )
{
if ( 0 )
;
#ifdef F_99
else if ( ! strcmp ( V_142 , L_18 ) )
V_143 = V_144 ;
#endif
#ifdef F_100
else if ( ! strcmp ( V_142 , L_19 ) )
V_143 = V_145 ;
#endif
else
F_51 ( L_20 , V_142 ) ;
return 0 ;
}
static struct V_88 * T_5 F_101 (
T_2 V_112 , T_2 V_113 ,
T_2 V_114 ,
T_7 V_146 )
{
static int V_147 [ V_97 ] V_119 ;
static int V_148 [ V_97 ] V_119 ;
const T_2 V_77 = V_78 - V_79 ;
int V_89 = 1 , V_90 = 0 ;
T_2 V_123 , V_149 , V_110 ;
int V_108 , V_150 , V_151 ( V_152 ) ;
int V_153 , V_106 , V_94 ;
unsigned int V_18 , V_154 ;
struct V_88 * V_91 ;
unsigned int * V_96 ;
memset ( V_147 , 0 , sizeof( V_147 ) ) ;
memset ( V_148 , 0 , sizeof( V_148 ) ) ;
V_123 = F_81 ( V_77 + V_112 +
F_102 ( T_2 , V_113 , V_132 ) ) ;
V_113 = V_123 - V_77 - V_112 ;
V_149 = F_102 ( T_2 , V_123 , V_63 ) ;
V_110 = F_103 ( V_149 , V_114 ) ;
V_108 = V_110 / V_149 ;
while ( V_110 % V_108 || ( ( V_110 / V_108 ) & ~ V_131 ) )
V_108 -- ;
V_150 = V_108 ;
F_70 (cpu) {
V_106 = 0 ;
V_155:
F_70 (tcpu) {
if ( V_18 == V_154 )
break;
if ( V_147 [ V_154 ] == V_106 && V_146 &&
( V_146 ( V_18 , V_154 ) > V_156 ||
V_146 ( V_154 , V_18 ) > V_156 ) ) {
V_106 ++ ;
V_89 = F_5 ( V_89 , V_106 + 1 ) ;
goto V_155;
}
}
V_147 [ V_18 ] = V_106 ;
V_148 [ V_106 ] ++ ;
}
V_153 = V_157 ;
for ( V_108 = V_150 ; V_108 ; V_108 -- ) {
int V_158 = 0 , V_159 = 0 ;
if ( V_110 % V_108 || ( ( V_110 / V_108 ) & ~ V_131 ) )
continue;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ ) {
int V_160 = F_104 ( V_148 [ V_106 ] , V_108 ) ;
V_158 += V_160 ;
V_159 += V_160 * V_108 - V_148 [ V_106 ] ;
}
if ( V_159 > F_85 () / 3 )
continue;
if ( V_158 > V_153 )
break;
V_153 = V_158 ;
V_152 = V_108 ;
}
V_108 = V_152 ;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ )
V_90 += F_103 ( V_148 [ V_106 ] , V_108 ) ;
V_91 = F_78 ( V_89 , V_90 ) ;
if ( ! V_91 )
return F_105 ( - V_45 ) ;
V_96 = V_91 -> V_95 [ 0 ] . V_96 ;
for ( V_106 = 0 ; V_106 < V_89 ; V_106 ++ ) {
V_91 -> V_95 [ V_106 ] . V_96 = V_96 ;
V_96 += F_103 ( V_148 [ V_106 ] , V_108 ) ;
}
V_91 -> V_77 = V_77 ;
V_91 -> V_112 = V_112 ;
V_91 -> V_113 = V_113 ;
V_91 -> V_111 = V_110 / V_108 ;
V_91 -> V_114 = V_114 ;
V_91 -> V_110 = V_110 ;
for ( V_106 = 0 , V_94 = 0 ; V_148 [ V_106 ] ; V_106 ++ ) {
struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
V_116 -> V_135 = V_94 * V_91 -> V_111 ;
F_70 (cpu)
if ( V_147 [ V_18 ] == V_106 )
V_116 -> V_96 [ V_116 -> V_90 ++ ] = V_18 ;
V_116 -> V_90 = F_103 ( V_116 -> V_90 , V_108 ) ;
V_94 += V_116 -> V_90 ;
}
F_32 ( V_94 != V_90 ) ;
return V_91 ;
}
int T_5 F_106 ( T_2 V_112 , T_2 V_113 ,
T_2 V_114 ,
T_7 V_146 ,
T_8 V_161 ,
T_9 V_162 )
{
void * V_80 = ( void * ) V_163 ;
void * * V_164 = NULL ;
struct V_88 * V_91 ;
T_2 V_123 , V_165 , V_166 ;
int V_106 , V_49 , V_167 ;
V_91 = F_101 ( V_112 , V_113 , V_114 ,
V_146 ) ;
if ( F_107 ( V_91 ) )
return F_108 ( V_91 ) ;
V_123 = V_91 -> V_77 + V_91 -> V_112 + V_91 -> V_113 ;
V_165 = F_81 ( V_91 -> V_89 * sizeof( void * ) ) ;
V_164 = F_80 ( V_165 ) ;
if ( ! V_164 ) {
V_167 = - V_45 ;
goto V_168;
}
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
struct V_115 * V_116 = & V_91 -> V_95 [ V_106 ] ;
unsigned int V_18 = V_97 ;
void * V_30 ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 && V_18 == V_97 ; V_49 ++ )
V_18 = V_116 -> V_96 [ V_49 ] ;
F_32 ( V_18 == V_97 ) ;
V_30 = V_161 ( V_18 , V_116 -> V_90 * V_91 -> V_111 , V_114 ) ;
if ( ! V_30 ) {
V_167 = - V_45 ;
goto V_169;
}
V_164 [ V_106 ] = V_30 ;
V_80 = F_109 ( V_30 , V_80 ) ;
for ( V_49 = 0 ; V_49 < V_116 -> V_90 ; V_49 ++ , V_30 += V_91 -> V_111 ) {
if ( V_116 -> V_96 [ V_49 ] == V_97 ) {
V_162 ( V_30 , V_91 -> V_111 ) ;
continue;
}
memcpy ( V_30 , V_170 , V_91 -> V_77 ) ;
V_162 ( V_30 + V_123 , V_91 -> V_111 - V_123 ) ;
}
}
V_166 = 0 ;
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ ) {
V_91 -> V_95 [ V_106 ] . V_135 = V_164 [ V_106 ] - V_80 ;
V_166 = F_102 ( T_2 , V_166 ,
V_91 -> V_95 [ V_106 ] . V_135 ) ;
}
V_166 += V_91 -> V_111 ;
if ( V_166 > ( V_171 - V_172 ) * 3 / 4 ) {
F_51 ( L_21
L_22 , V_166 ,
( unsigned long ) ( V_171 - V_172 ) ) ;
#ifdef F_100
V_167 = - V_173 ;
goto V_168;
#endif
}
F_53 ( L_23 ,
F_110 ( V_123 ) , V_80 , V_91 -> V_77 , V_91 -> V_112 ,
V_91 -> V_113 , V_91 -> V_111 ) ;
V_167 = F_89 ( V_91 , V_80 ) ;
goto V_168;
V_169:
for ( V_106 = 0 ; V_106 < V_91 -> V_89 ; V_106 ++ )
V_162 ( V_164 [ V_106 ] ,
V_91 -> V_95 [ V_106 ] . V_90 * V_91 -> V_111 ) ;
V_168:
F_82 ( V_91 ) ;
if ( V_164 )
F_83 ( F_74 ( V_164 ) , V_165 ) ;
return V_167 ;
}
int T_5 F_111 ( T_2 V_112 ,
T_8 V_161 ,
T_9 V_162 ,
T_10 V_174 )
{
static struct V_175 V_176 ;
struct V_88 * V_91 ;
char V_177 [ 16 ] ;
int V_178 ;
T_2 V_179 ;
struct V_15 * * V_180 ;
int V_94 , V_49 , V_181 , V_167 ;
snprintf ( V_177 , sizeof( V_177 ) , L_24 , V_28 >> 10 ) ;
V_91 = F_101 ( V_112 , 0 , V_28 , NULL ) ;
if ( F_107 ( V_91 ) )
return F_108 ( V_91 ) ;
F_32 ( V_91 -> V_89 != 1 ) ;
F_32 ( V_91 -> V_95 [ 0 ] . V_90 != F_85 () ) ;
V_178 = V_91 -> V_111 >> V_23 ;
V_179 = F_81 ( V_178 * F_85 () *
sizeof( V_180 [ 0 ] ) ) ;
V_180 = F_93 ( V_179 ) ;
V_181 = 0 ;
for ( V_94 = 0 ; V_94 < F_85 () ; V_94 ++ )
for ( V_49 = 0 ; V_49 < V_178 ; V_49 ++ ) {
unsigned int V_18 = V_91 -> V_95 [ 0 ] . V_96 [ V_94 ] ;
void * V_30 ;
V_30 = V_161 ( V_18 , V_28 , V_28 ) ;
if ( ! V_30 ) {
F_51 ( L_25
L_26 , V_177 , V_18 ) ;
goto V_182;
}
V_180 [ V_181 ++ ] = F_112 ( V_30 ) ;
}
V_176 . V_44 = V_183 ;
V_176 . V_7 = F_85 () * V_91 -> V_111 ;
F_113 ( & V_176 , V_28 ) ;
for ( V_94 = 0 ; V_94 < F_85 () ; V_94 ++ ) {
unsigned long V_184 =
( unsigned long ) V_176 . V_1 + V_94 * V_91 -> V_111 ;
for ( V_49 = 0 ; V_49 < V_178 ; V_49 ++ )
V_174 ( V_184 + ( V_49 << V_23 ) ) ;
V_167 = F_114 ( V_184 , & V_180 [ V_94 * V_178 ] ,
V_178 ) ;
if ( V_167 < 0 )
F_115 ( L_27 , V_167 ) ;
memcpy ( ( void * ) V_184 , V_170 , V_91 -> V_77 ) ;
}
F_53 ( L_28 ,
V_178 , V_177 , V_176 . V_1 , V_91 -> V_77 ,
V_91 -> V_112 , V_91 -> V_113 ) ;
V_167 = F_89 ( V_91 , V_176 . V_1 ) ;
goto V_185;
V_182:
while ( -- V_181 >= 0 )
V_162 ( F_116 ( V_180 [ V_181 ] ) , V_28 ) ;
V_167 = - V_45 ;
V_185:
F_83 ( F_74 ( V_180 ) , V_179 ) ;
F_82 ( V_91 ) ;
return V_167 ;
}
static void * T_5 F_117 ( unsigned int V_18 , T_2 V_7 ,
T_2 V_53 )
{
return F_118 ( V_7 , V_53 , F_74 ( V_186 ) ) ;
}
static void T_5 F_119 ( void * V_30 , T_2 V_7 )
{
F_83 ( F_74 ( V_30 ) , V_7 ) ;
}
void T_5 F_120 ( void )
{
unsigned long V_187 ;
unsigned int V_18 ;
int V_167 ;
V_167 = F_106 ( V_188 ,
V_189 , V_28 , NULL ,
F_117 , F_119 ) ;
if ( V_167 < 0 )
F_115 ( L_29 ) ;
V_187 = ( unsigned long ) V_81 - ( unsigned long ) V_79 ;
F_70 (cpu)
V_190 [ V_18 ] = V_187 + V_22 [ V_18 ] ;
}
void T_5 F_120 ( void )
{
const T_2 V_111 =
F_121 ( F_102 ( T_2 , V_63 ,
V_189 ) ) ;
struct V_88 * V_91 ;
void * V_191 ;
V_91 = F_78 ( 1 , 1 ) ;
V_191 = F_122 ( V_111 , V_28 , F_74 ( V_186 ) ) ;
if ( ! V_91 || ! V_191 )
F_115 ( L_30 ) ;
V_91 -> V_113 = V_111 ;
V_91 -> V_111 = V_111 ;
V_91 -> V_114 = V_111 ;
V_91 -> V_110 = V_111 ;
V_91 -> V_95 [ 0 ] . V_90 = 1 ;
V_91 -> V_95 [ 0 ] . V_96 [ 0 ] = 0 ;
if ( F_89 ( V_91 , V_191 ) < 0 )
F_115 ( L_29 ) ;
}
void T_5 F_123 ( void )
{
struct V_11 * V_192 [] =
{ V_3 , V_33 , NULL } ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_49 ;
for ( V_49 = 0 ; ( V_12 = V_192 [ V_49 ] ) ; V_49 ++ ) {
int * V_48 ;
const T_2 V_7 = V_121 * sizeof( V_48 [ 0 ] ) ;
F_124 ( V_7 > V_28 ) ;
V_48 = F_16 ( V_7 ) ;
F_32 ( ! V_48 ) ;
F_29 ( & V_46 , V_44 ) ;
memcpy ( V_48 , V_12 -> V_48 , V_7 ) ;
V_12 -> V_48 = V_48 ;
F_30 ( & V_46 , V_44 ) ;
}
}
