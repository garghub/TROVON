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
if ( V_12 -> V_37 >= V_12 -> V_38 + 3 )
return 0 ;
V_36 = V_39 ;
while ( V_36 < V_12 -> V_38 + 3 )
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
static int F_31 ( struct V_11 * V_12 , int V_7 , int V_49 )
{
int V_31 = F_7 ( V_12 ) ;
int V_50 = 0 ;
int V_51 , V_52 ;
bool V_53 = false ;
int * V_54 ;
for ( V_51 = V_12 -> V_55 , V_54 = V_12 -> V_48 + V_51 ; V_51 < V_12 -> V_38 ; V_51 ++ , V_54 ++ ) {
int V_56 , V_57 ;
int V_58 ;
V_52 = * V_54 ;
if ( V_52 & 1 )
continue;
V_56 = F_32 ( V_52 , V_49 ) - V_52 ;
V_58 = ( V_54 [ 1 ] & ~ 1 ) - V_52 ;
if ( V_58 < V_56 + V_7 ) {
if ( ! V_53 ) {
V_12 -> V_55 = V_51 ;
V_53 = true ;
}
V_50 = F_5 ( V_58 , V_50 ) ;
continue;
}
if ( V_56 && ( V_56 < sizeof( int ) || ! ( V_54 [ - 1 ] & 1 ) ) ) {
* V_54 = V_52 += V_56 ;
if ( V_54 [ - 1 ] & 1 )
V_12 -> V_13 -= V_56 ;
else
V_50 = F_5 ( * V_54 - V_54 [ - 1 ] , V_50 ) ;
V_58 -= V_56 ;
V_56 = 0 ;
}
V_57 = V_58 - V_56 - V_7 ;
if ( V_57 < sizeof( int ) ) {
V_57 = 0 ;
V_7 = V_58 - V_56 ;
}
if ( V_56 || V_57 ) {
int V_59 = ! ! V_56 + ! ! V_57 ;
memmove ( V_54 + V_59 + 1 , V_54 + 1 ,
sizeof( V_12 -> V_48 [ 0 ] ) * ( V_12 -> V_38 - V_51 ) ) ;
V_12 -> V_38 += V_59 ;
if ( V_56 ) {
if ( ! V_53 ) {
V_12 -> V_55 = V_51 ;
V_53 = true ;
}
* ++ V_54 = V_52 += V_56 ;
++ V_51 ;
V_50 = F_5 ( V_56 , V_50 ) ;
}
if ( V_57 ) {
V_54 [ 1 ] = V_52 + V_7 ;
V_50 = F_5 ( V_57 , V_50 ) ;
}
}
if ( ! V_53 )
V_12 -> V_55 = V_51 + 1 ;
if ( V_51 + 1 == V_12 -> V_38 )
V_12 -> V_14 = V_50 ;
else
V_12 -> V_14 = F_5 ( V_12 -> V_14 ,
V_50 ) ;
V_12 -> V_13 -= V_7 ;
* V_54 |= 1 ;
F_24 ( V_12 , V_31 ) ;
return V_52 ;
}
V_12 -> V_14 = V_50 ;
F_24 ( V_12 , V_31 ) ;
return - 1 ;
}
static void F_33 ( struct V_11 * V_12 , int V_60 )
{
int V_31 = F_7 ( V_12 ) ;
int V_52 = 0 ;
unsigned V_51 , V_61 ;
int V_62 = 0 ;
int * V_54 ;
V_60 |= 1 ;
V_51 = 0 ;
V_61 = V_12 -> V_38 ;
while ( V_51 != V_61 ) {
unsigned V_63 = ( V_51 + V_61 ) / 2 ;
V_52 = V_12 -> V_48 [ V_63 ] ;
if ( V_52 < V_60 )
V_51 = V_63 + 1 ;
else if ( V_52 > V_60 )
V_61 = V_63 ;
else
V_51 = V_61 = V_63 ;
}
F_34 ( V_52 != V_60 ) ;
if ( V_51 < V_12 -> V_55 )
V_12 -> V_55 = V_51 ;
V_54 = V_12 -> V_48 + V_51 ;
* V_54 = V_52 &= ~ 1 ;
V_12 -> V_13 += ( V_54 [ 1 ] & ~ 1 ) - V_52 ;
if ( ! ( V_54 [ 1 ] & 1 ) )
V_62 ++ ;
if ( V_51 > 0 && ! ( V_54 [ - 1 ] & 1 ) ) {
V_62 ++ ;
V_51 -- ;
V_54 -- ;
}
if ( V_62 ) {
V_12 -> V_38 -= V_62 ;
memmove ( V_54 + 1 , V_54 + 1 + V_62 ,
( V_12 -> V_38 - V_51 ) * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
}
V_12 -> V_14 = F_5 ( V_12 -> V_48 [ V_51 + 1 ] - V_12 -> V_48 [ V_51 ] - 1 , V_12 -> V_14 ) ;
F_24 ( V_12 , V_31 ) ;
}
static struct V_11 * F_35 ( void )
{
struct V_11 * V_12 ;
V_12 = F_16 ( V_64 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_48 = F_16 ( V_39 *
sizeof( V_12 -> V_48 [ 0 ] ) ) ;
if ( ! V_12 -> V_48 ) {
F_21 ( V_12 , V_64 ) ;
return NULL ;
}
V_12 -> V_37 = V_39 ;
V_12 -> V_48 [ 0 ] = 0 ;
V_12 -> V_48 [ 1 ] = V_5 | 1 ;
V_12 -> V_38 = 1 ;
F_36 ( & V_12 -> V_34 ) ;
V_12 -> V_13 = V_5 ;
V_12 -> V_14 = V_5 ;
return V_12 ;
}
static void F_37 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_21 ( V_12 -> V_48 , V_12 -> V_37 * sizeof( V_12 -> V_48 [ 0 ] ) ) ;
F_21 ( V_12 , V_64 ) ;
}
static struct V_11 * F_38 ( void * V_1 )
{
if ( F_1 ( V_1 ) ) {
if ( F_2 ( V_1 ) )
return V_33 ;
return V_3 ;
}
V_1 += V_22 [ F_39 () ] ;
return F_9 ( F_40 ( V_1 ) ) ;
}
static void T_3 * F_41 ( T_2 V_7 , T_2 V_49 , bool V_65 )
{
static int V_66 = 10 ;
struct V_11 * V_12 ;
const char * V_67 ;
int V_68 , V_52 , V_36 ;
unsigned long V_44 ;
void T_3 * V_30 ;
if ( F_42 ( V_49 < 2 ) )
V_49 = 2 ;
V_7 = F_32 ( V_7 , 2 ) ;
if ( F_42 ( ! V_7 || V_7 > V_69 || V_49 > V_28 ) ) {
F_43 ( true , L_1
L_2 , V_7 , V_49 ) ;
return NULL ;
}
F_44 ( & V_70 ) ;
F_29 ( & V_46 , V_44 ) ;
if ( V_65 && V_33 ) {
V_12 = V_33 ;
if ( V_7 > V_12 -> V_14 ) {
V_67 = L_3 ;
goto V_71;
}
while ( ( V_36 = F_27 ( V_12 ) ) ) {
F_30 ( & V_46 , V_44 ) ;
if ( F_28 ( V_12 , V_36 ) < 0 ) {
V_67 = L_4 ;
goto V_72;
}
F_29 ( & V_46 , V_44 ) ;
}
V_52 = F_31 ( V_12 , V_7 , V_49 ) ;
if ( V_52 >= 0 )
goto V_73;
V_67 = L_3 ;
goto V_71;
}
V_74:
for ( V_68 = F_6 ( V_7 ) ; V_68 < V_10 ; V_68 ++ ) {
F_45 (chunk, &pcpu_slot[slot], list) {
if ( V_7 > V_12 -> V_14 )
continue;
V_36 = F_27 ( V_12 ) ;
if ( V_36 ) {
F_30 ( & V_46 , V_44 ) ;
if ( F_28 ( V_12 ,
V_36 ) < 0 ) {
V_67 = L_5 ;
goto V_72;
}
F_29 ( & V_46 , V_44 ) ;
goto V_74;
}
V_52 = F_31 ( V_12 , V_7 , V_49 ) ;
if ( V_52 >= 0 )
goto V_73;
}
}
F_30 ( & V_46 , V_44 ) ;
V_12 = F_46 () ;
if ( ! V_12 ) {
V_67 = L_6 ;
goto V_72;
}
F_29 ( & V_46 , V_44 ) ;
F_24 ( V_12 , - 1 ) ;
goto V_74;
V_73:
F_30 ( & V_46 , V_44 ) ;
if ( F_47 ( V_12 , V_52 , V_7 ) ) {
F_29 ( & V_46 , V_44 ) ;
F_33 ( V_12 , V_52 ) ;
V_67 = L_7 ;
goto V_71;
}
F_48 ( & V_70 ) ;
V_30 = F_49 ( V_12 -> V_4 + V_52 ) ;
F_50 ( V_30 , V_7 ) ;
return V_30 ;
V_71:
F_30 ( & V_46 , V_44 ) ;
V_72:
F_48 ( & V_70 ) ;
if ( V_66 ) {
F_51 ( L_8
L_9 , V_7 , V_49 , V_67 ) ;
F_52 () ;
if ( ! -- V_66 )
F_53 ( L_10 ) ;
}
return NULL ;
}
void T_3 * F_54 ( T_2 V_7 , T_2 V_49 )
{
return F_41 ( V_7 , V_49 , false ) ;
}
void T_3 * F_55 ( T_2 V_7 , T_2 V_49 )
{
return F_41 ( V_7 , V_49 , true ) ;
}
static void F_56 ( struct V_75 * V_76 )
{
F_57 ( V_77 ) ;
struct V_78 * V_56 = & V_35 [ V_10 - 1 ] ;
struct V_11 * V_12 , * V_79 ;
F_44 ( & V_70 ) ;
F_58 ( & V_46 ) ;
F_59 (chunk, next, head, list) {
F_60 ( V_12 -> V_80 ) ;
if ( V_12 == F_61 ( V_56 , struct V_11 , V_34 ) )
continue;
F_25 ( & V_12 -> V_34 , & V_77 ) ;
}
F_62 ( & V_46 ) ;
F_59 (chunk, next, &todo, list) {
F_63 ( V_12 , 0 , V_5 ) ;
F_64 ( V_12 ) ;
}
F_48 ( & V_70 ) ;
}
void F_65 ( void T_3 * V_30 )
{
void * V_1 ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_52 ;
if ( ! V_30 )
return;
F_66 ( V_30 ) ;
V_1 = F_67 ( V_30 ) ;
F_29 ( & V_46 , V_44 ) ;
V_12 = F_38 ( V_1 ) ;
V_52 = V_1 - V_12 -> V_4 ;
F_33 ( V_12 , V_52 ) ;
if ( V_12 -> V_13 == V_5 ) {
struct V_11 * V_81 ;
F_45 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_81 != V_12 ) {
F_68 ( & V_82 ) ;
break;
}
}
F_30 ( & V_46 , V_44 ) ;
}
bool F_69 ( unsigned long V_1 )
{
#ifdef F_70
const T_2 V_83 = V_84 - V_85 ;
void T_3 * V_86 = F_49 ( V_87 ) ;
unsigned int V_18 ;
F_71 (cpu) {
void * V_88 = F_72 ( V_86 , V_18 ) ;
if ( ( void * ) V_1 >= V_88 && ( void * ) V_1 < V_88 + V_83 )
return true ;
}
#endif
return false ;
}
T_4 F_73 ( void * V_1 )
{
void T_3 * V_86 = F_49 ( V_87 ) ;
bool V_89 = false ;
unsigned long V_90 , V_91 ;
unsigned int V_18 ;
V_90 = F_11 ( V_3 , V_92 , 0 ) ;
V_91 = F_11 ( V_3 , V_93 ,
V_21 ) ;
if ( ( unsigned long ) V_1 >= V_90 &&
( unsigned long ) V_1 < V_91 ) {
F_71 (cpu) {
void * V_88 = F_72 ( V_86 , V_18 ) ;
if ( V_1 >= V_88 && V_1 < V_88 + V_5 ) {
V_89 = true ;
break;
}
}
}
if ( V_89 ) {
if ( ! F_74 ( V_1 ) )
return F_75 ( V_1 ) ;
else
return F_76 ( F_77 ( V_1 ) ) +
F_78 ( V_1 ) ;
} else
return F_76 ( F_40 ( V_1 ) ) +
F_78 ( V_1 ) ;
}
struct V_94 * T_5 F_79 ( int V_95 ,
int V_96 )
{
struct V_94 * V_97 ;
T_2 V_98 , V_99 ;
void * V_30 ;
int V_100 ;
V_98 = F_32 ( sizeof( * V_97 ) + V_95 * sizeof( V_97 -> V_101 [ 0 ] ) ,
F_80 ( V_97 -> V_101 [ 0 ] . V_102 [ 0 ] ) ) ;
V_99 = V_98 + V_96 * sizeof( V_97 -> V_101 [ 0 ] . V_102 [ 0 ] ) ;
V_30 = F_81 ( F_82 ( V_99 ) , 0 ) ;
if ( ! V_30 )
return NULL ;
V_97 = V_30 ;
V_30 += V_98 ;
V_97 -> V_101 [ 0 ] . V_102 = V_30 ;
for ( V_100 = 0 ; V_100 < V_96 ; V_100 ++ )
V_97 -> V_101 [ 0 ] . V_102 [ V_100 ] = V_103 ;
V_97 -> V_95 = V_95 ;
V_97 -> V_104 = F_82 ( V_99 ) ;
return V_97 ;
}
void T_5 F_83 ( struct V_94 * V_97 )
{
F_84 ( F_75 ( V_97 ) , V_97 -> V_104 ) ;
}
static void F_85 ( const char * V_105 ,
const struct V_94 * V_97 )
{
int V_106 = 1 , V_107 = 1 , V_108 ;
char V_109 [] = L_11 ;
int V_110 = 0 , V_111 = 0 ;
int V_112 , V_113 ;
int V_114 , V_115 ;
V_113 = V_97 -> V_95 ;
while ( V_113 /= 10 )
V_106 ++ ;
V_113 = F_86 () ;
while ( V_113 /= 10 )
V_107 ++ ;
V_109 [ F_87 ( int , V_107 , sizeof( V_109 ) - 1 ) ] = '\0' ;
V_114 = V_97 -> V_116 / V_97 -> V_117 ;
V_108 = V_114 * ( V_107 + 1 ) + V_106 + 3 ;
V_115 = F_88 ( F_5 ( 60 / V_108 , 1 ) ) ;
F_89 ( L_12 ,
V_105 , V_97 -> V_83 , V_97 -> V_118 , V_97 -> V_119 ,
V_97 -> V_117 , V_97 -> V_116 / V_97 -> V_120 , V_97 -> V_120 ) ;
for ( V_112 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ ) {
const struct V_121 * V_122 = & V_97 -> V_101 [ V_112 ] ;
int V_100 = 0 , V_123 = 0 ;
F_34 ( V_122 -> V_96 % V_114 ) ;
for ( V_111 += V_122 -> V_96 / V_114 ;
V_110 < V_111 ; V_110 ++ ) {
if ( ! ( V_110 % V_115 ) ) {
F_89 ( V_124 L_13 ) ;
F_89 ( L_14 , V_105 ) ;
}
F_89 ( V_124 L_15 , V_106 , V_112 ) ;
for ( V_123 += V_114 ; V_100 < V_123 ; V_100 ++ )
if ( V_122 -> V_102 [ V_100 ] != V_103 )
F_89 ( V_124 L_16 , V_107 ,
V_122 -> V_102 [ V_100 ] ) ;
else
F_89 ( V_124 L_17 , V_109 ) ;
}
}
F_89 ( V_124 L_13 ) ;
}
int T_5 F_90 ( const struct V_94 * V_97 ,
void * V_4 )
{
static char V_125 [ 4096 ] V_126 ;
static int V_127 [ V_128 ] V_126 ;
static int V_129 [ V_128 ] V_126 ;
T_2 V_119 = V_97 -> V_119 ;
T_2 V_130 = V_97 -> V_83 + V_97 -> V_118 + V_119 ;
struct V_11 * V_131 , * V_132 = NULL ;
unsigned long * V_133 ;
T_2 * V_134 ;
unsigned long * V_135 ;
unsigned int V_18 ;
int * V_136 ;
int V_112 , V_100 , V_51 ;
F_91 ( V_125 , sizeof( V_125 ) , V_137 ) ;
#define F_92 ( T_6 ) do { \
if (unlikely(cond)) { \
pr_emerg("PERCPU: failed to initialize, %s", #cond); \
pr_emerg("PERCPU: cpu_possible_mask=%s\n", cpus_buf); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_92 ( V_97 -> V_95 <= 0 ) ;
#ifdef F_70
F_92 ( ! V_97 -> V_83 ) ;
F_92 ( ( unsigned long ) V_85 & ~ V_138 ) ;
#endif
F_92 ( ! V_4 ) ;
F_92 ( ( unsigned long ) V_4 & ~ V_138 ) ;
F_92 ( V_97 -> V_117 < V_130 ) ;
F_92 ( V_97 -> V_117 & ~ V_138 ) ;
F_92 ( V_97 -> V_117 < V_69 ) ;
F_92 ( V_97 -> V_119 < V_139 ) ;
F_92 ( F_93 ( V_97 ) < 0 ) ;
V_133 = F_94 ( V_97 -> V_95 *
sizeof( V_133 [ 0 ] ) , 0 ) ;
V_134 = F_94 ( V_97 -> V_95 *
sizeof( V_134 [ 0 ] ) , 0 ) ;
V_136 = F_94 ( V_140 * sizeof( V_136 [ 0 ] ) , 0 ) ;
V_135 = F_94 ( V_140 * sizeof( V_135 [ 0 ] ) , 0 ) ;
for ( V_18 = 0 ; V_18 < V_140 ; V_18 ++ )
V_136 [ V_18 ] = V_141 ;
V_92 = V_103 ;
V_93 = V_103 ;
for ( V_112 = 0 , V_100 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ , V_100 += V_51 ) {
const struct V_121 * V_122 = & V_97 -> V_101 [ V_112 ] ;
V_133 [ V_112 ] = V_122 -> V_142 ;
V_134 [ V_112 ] = V_122 -> V_96 * V_97 -> V_117 ;
for ( V_51 = 0 ; V_51 < V_122 -> V_96 ; V_51 ++ ) {
V_18 = V_122 -> V_102 [ V_51 ] ;
if ( V_18 == V_103 )
continue;
F_92 ( V_18 > V_140 ) ;
F_92 ( ! F_95 ( V_18 ) ) ;
F_92 ( V_136 [ V_18 ] != V_141 ) ;
V_136 [ V_18 ] = V_100 + V_51 ;
V_135 [ V_18 ] = V_122 -> V_142 + V_51 * V_97 -> V_117 ;
if ( V_92 == V_103 ||
V_135 [ V_18 ] < V_135 [ V_92 ] )
V_92 = V_18 ;
if ( V_93 == V_103 ||
V_135 [ V_18 ] > V_135 [ V_93 ] )
V_93 = V_18 ;
}
}
V_143 = V_100 ;
F_71 (cpu)
F_92 ( V_136 [ V_18 ] == V_141 ) ;
#undef F_92
F_85 ( V_144 , V_97 ) ;
V_145 = V_97 -> V_95 ;
V_146 = V_133 ;
V_147 = V_134 ;
V_20 = V_136 ;
V_22 = V_135 ;
V_21 = V_97 -> V_117 >> V_23 ;
V_5 = V_21 << V_23 ;
V_148 = V_97 -> V_120 ;
V_64 = sizeof( struct V_11 ) +
F_96 ( V_21 ) * sizeof( unsigned long ) ;
V_10 = F_3 ( V_5 ) + 2 ;
V_35 = F_94 (
V_10 * sizeof( V_35 [ 0 ] ) , 0 ) ;
for ( V_51 = 0 ; V_51 < V_10 ; V_51 ++ )
F_36 ( & V_35 [ V_51 ] ) ;
V_131 = F_94 ( V_64 , 0 ) ;
F_36 ( & V_131 -> V_34 ) ;
V_131 -> V_4 = V_4 ;
V_131 -> V_48 = V_127 ;
V_131 -> V_37 = F_97 ( V_127 ) ;
V_131 -> V_80 = true ;
F_98 ( V_131 -> V_27 , V_21 ) ;
if ( V_97 -> V_118 ) {
V_131 -> V_13 = V_97 -> V_118 ;
V_33 = V_131 ;
V_6 = V_97 -> V_83 + V_97 -> V_118 ;
} else {
V_131 -> V_13 = V_119 ;
V_119 = 0 ;
}
V_131 -> V_14 = V_131 -> V_13 ;
V_131 -> V_48 [ 0 ] = 1 ;
V_131 -> V_48 [ 1 ] = V_97 -> V_83 ;
V_131 -> V_38 = 1 ;
if ( V_131 -> V_13 )
V_131 -> V_48 [ ++ V_131 -> V_38 ] = 1 | ( V_97 -> V_83 + V_131 -> V_13 ) ;
else
V_131 -> V_48 [ 1 ] |= 1 ;
if ( V_119 ) {
V_132 = F_94 ( V_64 , 0 ) ;
F_36 ( & V_132 -> V_34 ) ;
V_132 -> V_4 = V_4 ;
V_132 -> V_48 = V_129 ;
V_132 -> V_37 = F_97 ( V_129 ) ;
V_132 -> V_80 = true ;
F_98 ( V_132 -> V_27 , V_21 ) ;
V_132 -> V_14 = V_132 -> V_13 = V_119 ;
V_132 -> V_48 [ 0 ] = 1 ;
V_132 -> V_48 [ 1 ] = V_6 ;
V_132 -> V_48 [ 2 ] = ( V_6 + V_132 -> V_13 ) | 1 ;
V_132 -> V_38 = 2 ;
}
V_3 = V_132 ? : V_131 ;
F_24 ( V_3 , - 1 ) ;
V_87 = V_4 ;
return 0 ;
}
static int T_5 F_99 ( char * V_149 )
{
if ( ! V_149 )
return - V_150 ;
if ( 0 )
;
#ifdef F_100
else if ( ! strcmp ( V_149 , L_18 ) )
V_151 = V_152 ;
#endif
#ifdef F_101
else if ( ! strcmp ( V_149 , L_19 ) )
V_151 = V_153 ;
#endif
else
F_51 ( L_20 , V_149 ) ;
return 0 ;
}
static struct V_94 * T_5 F_102 (
T_2 V_118 , T_2 V_119 ,
T_2 V_120 ,
T_7 V_154 )
{
static int V_155 [ V_103 ] V_126 ;
static int V_156 [ V_103 ] V_126 ;
const T_2 V_83 = V_84 - V_85 ;
int V_95 = 1 , V_96 = 0 ;
T_2 V_130 , V_157 , V_116 ;
int V_114 , V_158 , V_159 ( V_160 ) ;
int V_161 , V_112 , V_100 ;
unsigned int V_18 , V_162 ;
struct V_94 * V_97 ;
unsigned int * V_102 ;
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
memset ( V_156 , 0 , sizeof( V_156 ) ) ;
V_130 = F_82 ( V_83 + V_118 +
F_103 ( T_2 , V_119 , V_139 ) ) ;
V_119 = V_130 - V_83 - V_118 ;
V_157 = F_103 ( T_2 , V_130 , V_69 ) ;
V_116 = F_104 ( V_157 , V_120 ) ;
V_114 = V_116 / V_157 ;
while ( V_116 % V_114 || ( ( V_116 / V_114 ) & ~ V_138 ) )
V_114 -- ;
V_158 = V_114 ;
F_71 (cpu) {
V_112 = 0 ;
V_163:
F_71 (tcpu) {
if ( V_18 == V_162 )
break;
if ( V_155 [ V_162 ] == V_112 && V_154 &&
( V_154 ( V_18 , V_162 ) > V_164 ||
V_154 ( V_162 , V_18 ) > V_164 ) ) {
V_112 ++ ;
V_95 = F_5 ( V_95 , V_112 + 1 ) ;
goto V_163;
}
}
V_155 [ V_18 ] = V_112 ;
V_156 [ V_112 ] ++ ;
}
V_161 = V_165 ;
for ( V_114 = V_158 ; V_114 ; V_114 -- ) {
int V_166 = 0 , V_167 = 0 ;
if ( V_116 % V_114 || ( ( V_116 / V_114 ) & ~ V_138 ) )
continue;
for ( V_112 = 0 ; V_112 < V_95 ; V_112 ++ ) {
int V_168 = F_105 ( V_156 [ V_112 ] , V_114 ) ;
V_166 += V_168 ;
V_167 += V_168 * V_114 - V_156 [ V_112 ] ;
}
if ( V_167 > F_86 () / 3 )
continue;
if ( V_166 > V_161 )
break;
V_161 = V_166 ;
V_160 = V_114 ;
}
V_114 = V_160 ;
for ( V_112 = 0 ; V_112 < V_95 ; V_112 ++ )
V_96 += F_104 ( V_156 [ V_112 ] , V_114 ) ;
V_97 = F_79 ( V_95 , V_96 ) ;
if ( ! V_97 )
return F_106 ( - V_45 ) ;
V_102 = V_97 -> V_101 [ 0 ] . V_102 ;
for ( V_112 = 0 ; V_112 < V_95 ; V_112 ++ ) {
V_97 -> V_101 [ V_112 ] . V_102 = V_102 ;
V_102 += F_104 ( V_156 [ V_112 ] , V_114 ) ;
}
V_97 -> V_83 = V_83 ;
V_97 -> V_118 = V_118 ;
V_97 -> V_119 = V_119 ;
V_97 -> V_117 = V_116 / V_114 ;
V_97 -> V_120 = V_120 ;
V_97 -> V_116 = V_116 ;
for ( V_112 = 0 , V_100 = 0 ; V_156 [ V_112 ] ; V_112 ++ ) {
struct V_121 * V_122 = & V_97 -> V_101 [ V_112 ] ;
V_122 -> V_142 = V_100 * V_97 -> V_117 ;
F_71 (cpu)
if ( V_155 [ V_18 ] == V_112 )
V_122 -> V_102 [ V_122 -> V_96 ++ ] = V_18 ;
V_122 -> V_96 = F_104 ( V_122 -> V_96 , V_114 ) ;
V_100 += V_122 -> V_96 ;
}
F_34 ( V_100 != V_96 ) ;
return V_97 ;
}
int T_5 F_107 ( T_2 V_118 , T_2 V_119 ,
T_2 V_120 ,
T_7 V_154 ,
T_8 V_169 ,
T_9 V_170 )
{
void * V_86 = ( void * ) V_171 ;
void * * V_172 = NULL ;
struct V_94 * V_97 ;
T_2 V_130 , V_173 , V_174 ;
int V_112 , V_51 , V_175 ;
V_97 = F_102 ( V_118 , V_119 , V_120 ,
V_154 ) ;
if ( F_108 ( V_97 ) )
return F_109 ( V_97 ) ;
V_130 = V_97 -> V_83 + V_97 -> V_118 + V_97 -> V_119 ;
V_173 = F_82 ( V_97 -> V_95 * sizeof( void * ) ) ;
V_172 = F_81 ( V_173 , 0 ) ;
if ( ! V_172 ) {
V_175 = - V_45 ;
goto V_176;
}
for ( V_112 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ ) {
struct V_121 * V_122 = & V_97 -> V_101 [ V_112 ] ;
unsigned int V_18 = V_103 ;
void * V_30 ;
for ( V_51 = 0 ; V_51 < V_122 -> V_96 && V_18 == V_103 ; V_51 ++ )
V_18 = V_122 -> V_102 [ V_51 ] ;
F_34 ( V_18 == V_103 ) ;
V_30 = V_169 ( V_18 , V_122 -> V_96 * V_97 -> V_117 , V_120 ) ;
if ( ! V_30 ) {
V_175 = - V_45 ;
goto V_177;
}
F_110 ( V_30 ) ;
V_172 [ V_112 ] = V_30 ;
V_86 = F_111 ( V_30 , V_86 ) ;
}
for ( V_112 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ ) {
struct V_121 * V_122 = & V_97 -> V_101 [ V_112 ] ;
void * V_30 = V_172 [ V_112 ] ;
for ( V_51 = 0 ; V_51 < V_122 -> V_96 ; V_51 ++ , V_30 += V_97 -> V_117 ) {
if ( V_122 -> V_102 [ V_51 ] == V_103 ) {
V_170 ( V_30 , V_97 -> V_117 ) ;
continue;
}
memcpy ( V_30 , V_178 , V_97 -> V_83 ) ;
V_170 ( V_30 + V_130 , V_97 -> V_117 - V_130 ) ;
}
}
V_174 = 0 ;
for ( V_112 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ ) {
V_97 -> V_101 [ V_112 ] . V_142 = V_172 [ V_112 ] - V_86 ;
V_174 = F_103 ( T_2 , V_174 ,
V_97 -> V_101 [ V_112 ] . V_142 ) ;
}
V_174 += V_97 -> V_117 ;
if ( V_174 > V_179 * 3 / 4 ) {
F_51 ( L_21
L_22 , V_174 ,
V_179 ) ;
#ifdef F_101
V_175 = - V_150 ;
goto V_176;
#endif
}
F_53 ( L_23 ,
F_112 ( V_130 ) , V_86 , V_97 -> V_83 , V_97 -> V_118 ,
V_97 -> V_119 , V_97 -> V_117 ) ;
V_175 = F_90 ( V_97 , V_86 ) ;
goto V_176;
V_177:
for ( V_112 = 0 ; V_112 < V_97 -> V_95 ; V_112 ++ )
if ( V_172 [ V_112 ] )
V_170 ( V_172 [ V_112 ] ,
V_97 -> V_101 [ V_112 ] . V_96 * V_97 -> V_117 ) ;
V_176:
F_83 ( V_97 ) ;
if ( V_172 )
F_84 ( F_75 ( V_172 ) , V_173 ) ;
return V_175 ;
}
int T_5 F_113 ( T_2 V_118 ,
T_8 V_169 ,
T_9 V_170 ,
T_10 V_180 )
{
static struct V_181 V_182 ;
struct V_94 * V_97 ;
char V_183 [ 16 ] ;
int V_184 ;
T_2 V_185 ;
struct V_15 * * V_186 ;
int V_100 , V_51 , V_61 , V_175 ;
snprintf ( V_183 , sizeof( V_183 ) , L_24 , V_28 >> 10 ) ;
V_97 = F_102 ( V_118 , 0 , V_28 , NULL ) ;
if ( F_108 ( V_97 ) )
return F_109 ( V_97 ) ;
F_34 ( V_97 -> V_95 != 1 ) ;
F_34 ( V_97 -> V_101 [ 0 ] . V_96 != F_86 () ) ;
V_184 = V_97 -> V_117 >> V_23 ;
V_185 = F_82 ( V_184 * F_86 () *
sizeof( V_186 [ 0 ] ) ) ;
V_186 = F_94 ( V_185 , 0 ) ;
V_61 = 0 ;
for ( V_100 = 0 ; V_100 < F_86 () ; V_100 ++ )
for ( V_51 = 0 ; V_51 < V_184 ; V_51 ++ ) {
unsigned int V_18 = V_97 -> V_101 [ 0 ] . V_102 [ V_100 ] ;
void * V_30 ;
V_30 = V_169 ( V_18 , V_28 , V_28 ) ;
if ( ! V_30 ) {
F_51 ( L_25
L_26 , V_183 , V_18 ) ;
goto V_187;
}
F_110 ( V_30 ) ;
V_186 [ V_61 ++ ] = F_114 ( V_30 ) ;
}
V_182 . V_44 = V_188 ;
V_182 . V_7 = F_86 () * V_97 -> V_117 ;
F_115 ( & V_182 , V_28 ) ;
for ( V_100 = 0 ; V_100 < F_86 () ; V_100 ++ ) {
unsigned long V_189 =
( unsigned long ) V_182 . V_1 + V_100 * V_97 -> V_117 ;
for ( V_51 = 0 ; V_51 < V_184 ; V_51 ++ )
V_180 ( V_189 + ( V_51 << V_23 ) ) ;
V_175 = F_116 ( V_189 , & V_186 [ V_100 * V_184 ] ,
V_184 ) ;
if ( V_175 < 0 )
F_117 ( L_27 , V_175 ) ;
memcpy ( ( void * ) V_189 , V_178 , V_97 -> V_83 ) ;
}
F_53 ( L_28 ,
V_184 , V_183 , V_182 . V_1 , V_97 -> V_83 ,
V_97 -> V_118 , V_97 -> V_119 ) ;
V_175 = F_90 ( V_97 , V_182 . V_1 ) ;
goto V_190;
V_187:
while ( -- V_61 >= 0 )
V_170 ( F_118 ( V_186 [ V_61 ] ) , V_28 ) ;
V_175 = - V_45 ;
V_190:
F_84 ( F_75 ( V_186 ) , V_185 ) ;
F_83 ( V_97 ) ;
return V_175 ;
}
static void * T_5 F_119 ( unsigned int V_18 , T_2 V_7 ,
T_2 V_49 )
{
return F_120 (
V_7 , V_49 , F_75 ( V_191 ) ) ;
}
static void T_5 F_121 ( void * V_30 , T_2 V_7 )
{
F_84 ( F_75 ( V_30 ) , V_7 ) ;
}
void T_5 F_122 ( void )
{
unsigned long V_192 ;
unsigned int V_18 ;
int V_175 ;
V_175 = F_107 ( V_193 ,
V_194 , V_28 , NULL ,
F_119 , F_121 ) ;
if ( V_175 < 0 )
F_117 ( L_29 ) ;
V_192 = ( unsigned long ) V_87 - ( unsigned long ) V_85 ;
F_71 (cpu)
V_195 [ V_18 ] = V_192 + V_22 [ V_18 ] ;
}
void T_5 F_122 ( void )
{
const T_2 V_117 =
F_123 ( F_103 ( T_2 , V_69 ,
V_194 ) ) ;
struct V_94 * V_97 ;
void * V_196 ;
V_97 = F_79 ( 1 , 1 ) ;
V_196 = F_120 ( V_117 ,
V_28 ,
F_75 ( V_191 ) ) ;
if ( ! V_97 || ! V_196 )
F_117 ( L_30 ) ;
F_110 ( V_196 ) ;
V_97 -> V_119 = V_117 ;
V_97 -> V_117 = V_117 ;
V_97 -> V_120 = V_117 ;
V_97 -> V_116 = V_117 ;
V_97 -> V_101 [ 0 ] . V_96 = 1 ;
V_97 -> V_101 [ 0 ] . V_102 [ 0 ] = 0 ;
if ( F_90 ( V_97 , V_196 ) < 0 )
F_117 ( L_29 ) ;
F_83 ( V_97 ) ;
}
void T_5 F_124 ( void )
{
struct V_11 * V_197 [] =
{ V_3 , V_33 , NULL } ;
struct V_11 * V_12 ;
unsigned long V_44 ;
int V_51 ;
for ( V_51 = 0 ; ( V_12 = V_197 [ V_51 ] ) ; V_51 ++ ) {
int * V_48 ;
const T_2 V_7 = V_128 * sizeof( V_48 [ 0 ] ) ;
F_125 ( V_7 > V_28 ) ;
V_48 = F_16 ( V_7 ) ;
F_34 ( ! V_48 ) ;
F_29 ( & V_46 , V_44 ) ;
memcpy ( V_48 , V_12 -> V_48 , V_7 ) ;
V_12 -> V_48 = V_48 ;
F_30 ( & V_46 , V_44 ) ;
}
}
