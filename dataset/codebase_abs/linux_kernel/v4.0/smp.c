static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int T_1 F_2 ( char * V_1 )
{
F_3 ( & V_1 , & V_2 ) ;
return 0 ;
}
static inline int F_4 ( T_2 V_3 , T_3 V_4 , unsigned long V_5 ,
T_4 * V_6 )
{
int V_7 ;
while ( 1 ) {
V_7 = F_5 ( V_3 , V_4 , V_5 , NULL ) ;
if ( V_7 != V_8 )
return V_7 ;
F_6 () ;
}
}
static int F_7 ( struct V_9 * V_9 , T_3 V_4 , T_4 V_5 )
{
int V_7 , V_10 ;
for ( V_10 = 0 ; ; V_10 ++ ) {
V_7 = F_5 ( V_9 -> V_11 , V_4 , V_5 , NULL ) ;
if ( V_7 != V_8 )
break;
if ( V_10 >= 3 )
F_8 ( 10 ) ;
}
return V_7 ;
}
static inline int F_9 ( struct V_9 * V_9 )
{
T_4 V_12 ( V_6 ) ;
if ( F_5 ( V_9 -> V_11 , V_13 ,
0 , & V_6 ) != V_14 )
return 0 ;
return ! ! ( V_6 & ( V_15 | V_16 ) ) ;
}
static inline int F_10 ( struct V_9 * V_9 )
{
if ( F_5 ( V_9 -> V_11 , V_17 ,
0 , NULL ) != V_14 )
return 1 ;
return 0 ;
}
static struct V_9 * F_11 ( const struct V_18 * V_19 , T_2 V_11 )
{
int V_20 ;
F_12 (cpu, mask)
if ( V_21 [ V_20 ] . V_11 == V_11 )
return V_21 + V_20 ;
return NULL ;
}
static void F_13 ( struct V_9 * V_9 , int V_22 )
{
int V_4 ;
if ( F_14 ( V_22 , & V_9 -> V_23 ) )
return;
V_4 = F_10 ( V_9 ) ? V_24 : V_25 ;
F_7 ( V_9 , V_4 , 0 ) ;
}
static int F_15 ( struct V_9 * V_9 , int V_20 )
{
unsigned long V_26 , V_27 ;
struct V_28 * V_29 ;
if ( V_9 != & V_21 [ 0 ] ) {
V_9 -> V_30 = (struct V_28 * )
F_16 ( V_31 | V_32 , V_33 ) ;
V_26 = F_16 ( V_31 , V_34 ) ;
V_27 = F_17 ( V_31 ) ;
if ( ! V_9 -> V_30 || ! V_27 || ! V_26 )
goto V_35;
} else {
V_26 = V_9 -> V_30 -> V_26 - V_36 ;
V_27 = V_9 -> V_30 -> V_27 - V_37 ;
}
V_29 = V_9 -> V_30 ;
memcpy ( V_29 , & V_38 , 512 ) ;
memset ( ( char * ) V_29 + 512 , 0 , sizeof( * V_29 ) - 512 ) ;
V_29 -> V_26 = V_26 + V_36 ;
V_29 -> V_27 = V_27 + V_37 ;
V_29 -> V_39 = V_20 ;
V_29 -> V_40 = F_18 ( V_20 ) ;
#ifndef F_19
if ( V_41 ) {
V_29 -> V_42 = F_20 ( V_31 ) ;
if ( ! V_29 -> V_42 )
goto V_35;
}
#else
if ( V_43 )
V_29 -> V_44 =
( unsigned long ) & V_29 -> V_45 ;
if ( F_21 ( V_29 ) )
goto V_35;
#endif
V_46 [ V_20 ] = V_29 ;
F_7 ( V_9 , V_47 , ( T_4 ) ( unsigned long ) V_29 ) ;
return 0 ;
V_35:
if ( V_9 != & V_21 [ 0 ] ) {
F_22 ( V_27 ) ;
F_23 ( V_26 , V_34 ) ;
F_23 ( ( unsigned long ) V_9 -> V_30 , V_33 ) ;
}
return - V_48 ;
}
static void F_24 ( struct V_9 * V_9 )
{
F_7 ( V_9 , V_47 , 0 ) ;
V_46 [ V_9 - V_21 ] = NULL ;
#ifndef F_19
if ( V_41 ) {
struct V_28 * V_29 = V_9 -> V_30 ;
F_22 ( ( unsigned long ) V_29 -> V_42 ) ;
V_29 -> V_42 = 0 ;
}
#else
F_25 ( V_9 -> V_30 ) ;
#endif
if ( V_9 == & V_21 [ 0 ] )
return;
F_22 ( V_9 -> V_30 -> V_27 - V_37 ) ;
F_23 ( V_9 -> V_30 -> V_26 - V_36 , V_34 ) ;
F_23 ( ( unsigned long ) V_9 -> V_30 , V_33 ) ;
}
static void F_26 ( struct V_9 * V_9 , int V_20 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
if ( V_49 )
F_27 ( V_20 , & V_50 . V_51 . V_52 ) ;
F_27 ( V_20 , F_28 ( & V_50 ) ) ;
F_29 ( & V_50 . V_51 . V_53 ) ;
V_29 -> V_39 = V_20 ;
V_29 -> V_40 = F_18 ( V_20 ) ;
V_29 -> V_54 = V_55 [ V_20 ] ;
V_29 -> V_56 = V_38 . V_56 ;
V_29 -> V_57 = V_38 . V_57 ;
V_29 -> V_58 = V_29 -> V_59 = V_29 -> V_60 = 0 ;
F_30 ( V_29 -> V_61 , 0 , 15 ) ;
F_31 ( ( unsigned int * ) V_29 -> V_62 ) ;
memcpy ( V_29 -> V_63 , V_38 . V_63 ,
V_64 / 8 ) ;
}
static void F_32 ( struct V_9 * V_9 , struct V_65 * V_66 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
struct V_67 * V_68 = F_33 ( V_66 ) ;
V_29 -> V_69 = ( unsigned long ) F_34 ( V_66 )
+ V_70 - V_71 - sizeof( struct V_72 ) ;
V_29 -> V_67 = ( unsigned long ) F_33 ( V_66 ) ;
V_29 -> V_73 = ( unsigned long ) V_66 ;
V_29 -> V_58 = V_68 -> V_58 ;
V_29 -> V_59 = V_68 -> V_59 ;
V_29 -> V_60 = 0 ;
}
static void F_35 ( struct V_9 * V_9 , void (* F_36)( void * ) , void * V_74 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
V_29 -> V_75 = V_29 -> V_69 ;
V_29 -> V_76 = ( unsigned long ) F_36 ;
V_29 -> V_77 = ( unsigned long ) V_74 ;
V_29 -> V_78 = - 1UL ;
F_7 ( V_9 , V_79 , 0 ) ;
}
static void F_37 ( struct V_9 * V_9 , void (* F_36)( void * ) ,
void * V_74 , unsigned long V_80 )
{
struct V_28 * V_29 = V_46 [ V_9 - V_21 ] ;
unsigned long V_81 = F_38 () ;
F_39 ( V_82 ) ;
if ( V_9 -> V_11 == V_81 )
F_36 ( V_74 ) ;
F_7 ( V_9 , V_83 , 0 ) ;
F_40 ( V_29 -> V_75 , V_80 ) ;
F_40 ( V_29 -> V_76 , ( unsigned long ) F_36 ) ;
F_40 ( V_29 -> V_77 , ( unsigned long ) V_74 ) ;
F_40 ( V_29 -> V_78 , V_81 ) ;
asm volatile(
"0: sigp 0,%0,%2 # sigp restart to target cpu\n"
" brc 2,0b # busy, try again\n"
"1: sigp 0,%1,%3 # sigp stop to current cpu\n"
" brc 2,1b # busy, try again\n"
: : "d" (pcpu->address), "d" (source_cpu),
"K" (SIGP_RESTART), "K" (SIGP_STOP)
: "0", "1", "cc");
for (; ; ) ;
}
static int F_41 ( unsigned int V_84 )
{
register unsigned long T_5 V_85 ( L_1 ) = ( unsigned long ) V_84 ;
int V_7 ;
if ( V_86 == V_84 )
return 0 ;
asm volatile(
" sigp %1,0,%2 # sigp set multi-threading\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc) : "d" (reg1), "K" (SIGP_SET_MULTI_THREADING)
: "cc");
if ( V_7 == 0 ) {
V_86 = V_84 ;
V_87 = 0 ;
while ( V_86 >= ( 1U << V_87 ) )
V_87 ++ ;
V_21 [ 0 ] . V_11 = F_38 () ;
}
return V_7 ;
}
void F_42 ( void (* F_36)( void * ) , void * V_74 )
{
struct V_9 * V_9 ;
V_9 = F_11 ( V_88 , F_38 () ) ;
if ( ! V_9 )
V_9 = V_21 + F_43 ( V_88 ) ;
F_37 ( V_9 , F_36 , V_74 , ( unsigned long ) V_75 ) ;
}
void F_44 ( void (* F_36)( void * ) , void * V_74 )
{
F_37 ( & V_21 [ 0 ] , F_36 , V_74 ,
V_21 -> V_30 -> V_27 -
V_37 + V_89 ) ;
}
int F_45 ( T_2 V_11 )
{
int V_20 ;
F_46 (cpu)
if ( V_21 [ V_20 ] . V_11 == V_11 )
return V_20 ;
return - 1 ;
}
int F_47 ( int V_20 )
{
return F_10 ( V_21 + V_20 ) ;
}
void F_48 ( int V_20 )
{
if ( V_90 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_91 )
asm volatile("diag 0,0,0x44");
}
static void F_49 ( T_6 * V_18 )
{
T_7 V_92 ;
int V_20 ;
V_92 = F_50 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_51 ( V_93 , & V_9 -> V_23 ) ;
while ( F_5 ( V_9 -> V_11 , V_25 ,
0 , NULL ) == V_8 &&
F_50 () < V_92 )
F_6 () ;
}
while ( F_50 () < V_92 ) {
F_12 (cpu, cpumask)
if ( F_9 ( V_21 + V_20 ) )
F_52 ( V_20 , V_18 ) ;
if ( F_53 ( V_18 ) )
break;
F_6 () ;
}
}
void F_54 ( void )
{
T_6 V_18 ;
int V_20 ;
F_39 ( V_82 | V_94 ) ;
F_55 () ;
F_56 () ;
F_57 ( & V_18 , V_88 ) ;
F_52 ( F_58 () , & V_18 ) ;
if ( V_95 )
F_49 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_7 ( V_9 , V_83 , 0 ) ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
}
}
static void F_59 ( void )
{
unsigned long V_96 ;
V_96 = F_60 ( & V_21 [ F_58 () ] . V_23 , 0 ) ;
if ( F_61 ( V_93 , & V_96 ) )
F_62 () ;
if ( F_61 ( V_97 , & V_96 ) )
F_63 () ;
if ( F_61 ( V_98 , & V_96 ) )
F_64 () ;
}
static void F_65 ( struct V_99 V_99 ,
unsigned int V_100 , unsigned long V_101 )
{
F_66 ( V_99 . V_102 == 0x1202 ? V_103 : V_104 ) ;
F_59 () ;
}
void F_67 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_98 ) ;
}
void F_68 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_98 ) ;
}
static void F_69 ( void * V_105 )
{
F_70 () ;
}
void F_71 ( void )
{
F_72 ( F_69 , NULL , 1 ) ;
}
void F_73 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_97 ) ;
}
static void F_74 ( void * V_105 )
{
struct V_106 * V_107 = V_105 ;
unsigned long V_108 [ 16 ] ;
F_30 ( V_108 , 0 , 15 ) ;
V_108 [ V_107 -> V_109 ] = ( V_108 [ V_107 -> V_109 ] & V_107 -> V_110 ) | V_107 -> V_111 ;
F_75 ( V_108 , 0 , 15 ) ;
}
void F_76 ( int V_109 , int V_112 )
{
struct V_106 V_113 = { 1UL << V_112 , - 1UL , V_109 } ;
F_72 ( F_74 , & V_113 , 1 ) ;
}
void F_77 ( int V_109 , int V_112 )
{
struct V_106 V_113 = { 0 , ~ ( 1UL << V_112 ) , V_109 } ;
F_72 ( F_74 , & V_113 , 1 ) ;
}
static inline void F_78 ( int V_20 , T_2 V_11 , int V_114 )
{
void * V_29 = V_21 [ 0 ] . V_30 ;
struct V_115 * V_116 ;
unsigned long V_117 ;
V_116 = F_79 ( V_20 ) ;
if ( ! V_116 )
F_80 ( L_2 ) ;
if ( V_114 ) {
F_81 ( 1 , ( void * ) & V_116 -> V_118 , sizeof( V_116 -> V_118 ) ,
V_119 - V_89 , 0 ) ;
if ( V_43 )
F_82 ( V_116 -> V_120 ) ;
return;
}
F_4 ( V_11 , V_121 , 0 , NULL ) ;
F_83 ( & V_116 -> V_118 , V_29 + V_119 , sizeof( V_116 -> V_118 ) ) ;
if ( ! V_43 )
return;
V_117 = F_17 ( V_31 ) ;
if ( ! V_117 )
F_80 ( L_3 ) ;
F_4 ( V_11 , V_122 , V_117 , NULL ) ;
memcpy ( V_116 -> V_120 , ( void * ) V_117 , sizeof( V_116 -> V_120 ) ) ;
F_22 ( V_117 ) ;
}
static void T_1 F_84 ( struct V_123 * V_105 )
{
unsigned int V_20 , V_11 , V_124 , V_125 ;
int V_114 ;
if ( F_85 () )
return;
if ( ! ( V_126 || V_127 . type == V_128 ) )
return;
F_41 ( F_86 () ) ;
V_20 = 0 ;
for ( V_124 = 0 ; V_124 < V_105 -> V_129 ; V_124 ++ ) {
if ( V_105 -> V_130 && V_105 -> V_20 [ V_124 ] . type != V_131 )
continue;
for ( V_125 = 0 ; V_125 <= V_86 ; V_125 ++ , V_20 ++ ) {
V_11 = ( V_105 -> V_20 [ V_124 ] . V_132 << V_87 ) + V_125 ;
V_114 = ( V_11 == V_21 [ 0 ] . V_11 ) ;
if ( V_114 && ! V_126 )
continue;
F_78 ( V_20 , V_11 , V_114 ) ;
}
}
}
int F_87 ( int V_20 )
{
unsigned long V_117 ;
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
if ( F_4 ( V_9 -> V_11 , V_121 ,
0 , NULL ) != V_133 )
return - V_134 ;
if ( ! V_43 )
return 0 ;
V_117 = F_88 ( V_9 -> V_30 -> V_44 ) ;
F_4 ( V_9 -> V_11 , V_122 ,
V_117 , NULL ) ;
return 0 ;
}
void F_89 ( int V_20 , int V_135 )
{
V_21 [ V_20 ] . V_136 = V_135 ;
}
int F_90 ( int V_20 )
{
return V_21 [ V_20 ] . V_136 ;
}
static struct V_123 * F_91 ( void )
{
static int V_137 ;
struct V_123 * V_105 ;
int V_11 ;
V_105 = F_92 ( sizeof( * V_105 ) , V_31 ) ;
if ( V_105 && ( V_137 || F_93 ( V_105 ) ) ) {
V_137 = 1 ;
for ( V_11 = 0 ; V_11 <= V_138 ;
V_11 += ( 1U << V_87 ) ) {
if ( F_4 ( V_11 , V_13 , 0 , NULL ) ==
V_139 )
continue;
V_105 -> V_20 [ V_105 -> V_129 ] . V_132 =
V_11 >> V_87 ;
V_105 -> V_129 ++ ;
}
V_105 -> V_140 = V_105 -> V_129 ;
}
return V_105 ;
}
static int F_94 ( struct V_123 * V_105 , int V_141 )
{
struct V_9 * V_9 ;
T_6 V_142 ;
int V_20 , V_143 , V_124 , V_125 ;
T_2 V_11 ;
V_143 = 0 ;
F_95 ( & V_142 , V_144 , V_145 ) ;
V_20 = F_43 ( & V_142 ) ;
for ( V_124 = 0 ; ( V_124 < V_105 -> V_140 ) && ( V_20 < V_146 ) ; V_124 ++ ) {
if ( V_105 -> V_130 && V_105 -> V_20 [ V_124 ] . type != V_131 )
continue;
V_11 = V_105 -> V_20 [ V_124 ] . V_132 << V_87 ;
for ( V_125 = 0 ; V_125 <= V_86 ; V_125 ++ ) {
if ( F_11 ( V_145 , V_11 + V_125 ) )
continue;
V_9 = V_21 + V_20 ;
V_9 -> V_11 = V_11 + V_125 ;
V_9 -> V_147 =
( V_20 >= V_105 -> V_129 * ( V_86 + 1 ) ) ?
V_148 : V_149 ;
F_89 ( V_20 , V_150 ) ;
F_96 ( V_20 , true ) ;
if ( V_141 && F_97 ( V_20 ) != 0 )
F_96 ( V_20 , false ) ;
else
V_143 ++ ;
V_20 = F_98 ( V_20 , & V_142 ) ;
if ( V_20 >= V_146 )
break;
}
}
return V_143 ;
}
static void T_1 F_99 ( void )
{
unsigned int V_20 , V_84 , V_151 , V_152 ;
struct V_123 * V_105 ;
T_2 V_11 ;
V_105 = F_91 () ;
if ( ! V_105 )
F_80 ( L_4 ) ;
if ( V_105 -> V_130 ) {
V_11 = F_38 () ;
for ( V_20 = 0 ; V_20 < V_105 -> V_140 ; V_20 ++ )
if ( V_105 -> V_20 [ V_20 ] . V_132 == V_11 ) {
V_131 = V_105 -> V_20 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_105 -> V_140 )
F_80 ( L_5 ) ;
}
#ifdef F_100
F_84 ( V_105 ) ;
#endif
V_84 = F_101 ( V_131 ) ;
V_84 = ( V_84 < V_2 ) ? V_84 : V_2 - 1 ;
F_41 ( V_84 ) ;
V_151 = V_152 = 0 ;
for ( V_20 = 0 ; V_20 < V_105 -> V_140 ; V_20 ++ ) {
if ( V_105 -> V_130 && V_105 -> V_20 [ V_20 ] . type != V_131 )
continue;
if ( V_20 < V_105 -> V_129 )
V_151 += V_86 + 1 ;
else
V_152 += V_86 + 1 ;
}
F_102 ( L_6 , V_151 , V_152 ) ;
F_103 () ;
F_94 ( V_105 , 0 ) ;
F_104 () ;
F_105 ( V_105 ) ;
}
static void F_106 ( void * V_153 )
{
V_38 . V_154 = F_50 () ;
V_38 . V_75 = ( unsigned long ) V_75 ;
V_38 . V_76 = ( unsigned long ) V_155 ;
V_38 . V_77 = 0 ;
V_38 . V_78 = - 1UL ;
F_107 ( V_38 . V_62 ) ;
F_75 ( V_38 . V_61 , 0 , 15 ) ;
F_39 ( V_82 | V_94 ) ;
F_108 () ;
F_109 () ;
F_110 () ;
F_111 () ;
F_112 () ;
F_113 ( F_58 () ) ;
F_114 ( F_58 () , true ) ;
F_66 ( V_156 ) ;
F_115 () ;
F_116 ( V_157 ) ;
}
int F_117 ( unsigned int V_20 , struct V_65 * V_158 )
{
struct V_9 * V_9 ;
int V_159 , V_124 , V_160 ;
V_9 = V_21 + V_20 ;
if ( V_9 -> V_147 != V_149 )
return - V_134 ;
V_159 = V_20 - ( V_20 % ( V_86 + 1 ) ) ;
for ( V_124 = 0 ; V_124 <= V_86 ; V_124 ++ ) {
if ( V_159 + V_124 < V_146 )
if ( F_118 ( V_159 + V_124 ) )
break;
}
if ( V_124 > V_86 &&
F_7 ( V_21 + V_159 , V_161 , 0 ) !=
V_133 )
return - V_134 ;
V_160 = F_15 ( V_9 , V_20 ) ;
if ( V_160 )
return V_160 ;
F_26 ( V_9 , V_20 ) ;
F_32 ( V_9 , V_158 ) ;
F_35 ( V_9 , F_106 , NULL ) ;
while ( ! F_118 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_119 ( char * V_1 )
{
F_3 ( & V_1 , & V_162 ) ;
return 0 ;
}
int F_120 ( void )
{
unsigned long V_108 [ 16 ] ;
F_59 () ;
F_114 ( F_58 () , false ) ;
F_121 () ;
F_30 ( V_108 , 0 , 15 ) ;
V_108 [ 0 ] &= ~ 0x0000ee70UL ;
V_108 [ 6 ] &= ~ 0xff000000UL ;
V_108 [ 14 ] &= ~ 0x1f000000UL ;
F_75 ( V_108 , 0 , 15 ) ;
F_122 ( V_163 ) ;
return 0 ;
}
void F_123 ( unsigned int V_20 )
{
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
F_24 ( V_9 ) ;
F_124 ( & V_50 . V_51 . V_53 ) ;
F_52 ( V_20 , F_28 ( & V_50 ) ) ;
if ( V_49 )
F_52 ( V_20 , & V_50 . V_51 . V_52 ) ;
}
void T_8 F_125 ( void )
{
F_126 () ;
F_7 ( V_21 + F_58 () , V_83 , 0 ) ;
for (; ; ) ;
}
void T_1 F_127 ( void )
{
unsigned int V_164 , V_165 , V_20 ;
V_165 = F_128 ( V_2 , F_129 () + 1 ) ;
V_165 = F_130 () * V_165 ? : V_146 ;
V_164 = V_162 ? : V_146 ;
V_164 = F_128 ( V_164 , V_165 ) ;
for ( V_20 = 0 ; V_20 < V_164 && V_20 < V_146 ; V_20 ++ )
F_131 ( V_20 , true ) ;
}
void T_1 F_132 ( unsigned int V_166 )
{
if ( F_133 ( V_167 , F_65 ) )
F_80 ( L_7 ) ;
if ( F_133 ( V_168 , F_65 ) )
F_80 ( L_8 ) ;
F_99 () ;
}
void T_1 F_134 ( void )
{
struct V_9 * V_9 = V_21 ;
V_9 -> V_147 = V_149 ;
V_9 -> V_11 = F_38 () ;
V_9 -> V_30 = (struct V_28 * ) ( unsigned long ) F_135 () ;
V_38 . V_54 = V_55 [ 0 ] ;
F_89 ( 0 , V_150 ) ;
F_96 ( 0 , true ) ;
F_114 ( 0 , true ) ;
}
void T_1 F_136 ( unsigned int V_166 )
{
}
void T_1 F_137 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_18 ( 0 ) ;
}
int F_138 ( unsigned int V_169 )
{
return 0 ;
}
static T_9 F_139 ( struct V_170 * V_171 ,
struct V_172 * V_173 , char * V_174 )
{
T_9 V_175 ;
F_140 ( & V_176 ) ;
V_175 = sprintf ( V_174 , L_9 , V_21 [ V_171 -> V_177 ] . V_147 ) ;
F_141 ( & V_176 ) ;
return V_175 ;
}
static T_9 F_142 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
const char * V_174 , T_10 V_175 )
{
struct V_9 * V_9 ;
int V_20 , V_135 , V_160 , V_124 ;
char V_178 ;
if ( sscanf ( V_174 , L_10 , & V_135 , & V_178 ) != 1 )
return - V_179 ;
if ( V_135 != 0 && V_135 != 1 )
return - V_179 ;
F_103 () ;
F_140 ( & V_176 ) ;
V_160 = - V_180 ;
V_20 = V_171 -> V_177 ;
V_20 -= V_20 % ( V_86 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_124 = 0 ; V_124 <= V_86 ; V_124 ++ )
if ( F_118 ( V_20 + V_124 ) )
goto V_35;
V_9 = V_21 + V_20 ;
V_160 = 0 ;
switch ( V_135 ) {
case 0 :
if ( V_9 -> V_147 != V_149 )
break;
V_160 = F_143 ( V_9 -> V_11 >> V_87 ) ;
if ( V_160 )
break;
for ( V_124 = 0 ; V_124 <= V_86 ; V_124 ++ ) {
if ( V_20 + V_124 >= V_146 || ! F_144 ( V_20 + V_124 ) )
continue;
V_9 [ V_124 ] . V_147 = V_148 ;
F_89 ( V_20 + V_124 ,
V_150 ) ;
}
F_145 () ;
break;
case 1 :
if ( V_9 -> V_147 != V_148 )
break;
V_160 = F_146 ( V_9 -> V_11 >> V_87 ) ;
if ( V_160 )
break;
for ( V_124 = 0 ; V_124 <= V_86 ; V_124 ++ ) {
if ( V_20 + V_124 >= V_146 || ! F_144 ( V_20 + V_124 ) )
continue;
V_9 [ V_124 ] . V_147 = V_149 ;
F_89 ( V_20 + V_124 ,
V_150 ) ;
}
F_145 () ;
break;
default:
break;
}
V_35:
F_141 ( & V_176 ) ;
F_104 () ;
return V_160 ? V_160 : V_175 ;
}
static T_9 F_147 ( struct V_170 * V_171 ,
struct V_172 * V_173 , char * V_174 )
{
return sprintf ( V_174 , L_9 , V_21 [ V_171 -> V_177 ] . V_11 ) ;
}
static int F_148 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_184 ;
struct V_170 * V_1 = & F_149 ( V_185 , V_20 ) -> V_171 ;
int V_186 = 0 ;
switch ( V_183 & ~ V_187 ) {
case V_188 :
V_186 = F_150 ( & V_1 -> V_189 , & V_190 ) ;
break;
case V_191 :
F_151 ( & V_1 -> V_189 , & V_190 ) ;
break;
}
return F_152 ( V_186 ) ;
}
static int F_97 ( int V_20 )
{
struct V_170 * V_1 ;
struct V_20 * V_192 ;
int V_160 ;
V_192 = F_92 ( sizeof( * V_192 ) , V_31 ) ;
if ( ! V_192 )
return - V_48 ;
F_149 ( V_185 , V_20 ) = V_192 ;
V_1 = & V_192 -> V_171 ;
V_192 -> V_193 = 1 ;
V_160 = F_153 ( V_192 , V_20 ) ;
if ( V_160 )
goto V_35;
V_160 = F_150 ( & V_1 -> V_189 , & V_194 ) ;
if ( V_160 )
goto V_195;
if ( F_118 ( V_20 ) ) {
V_160 = F_150 ( & V_1 -> V_189 , & V_190 ) ;
if ( V_160 )
goto V_196;
}
V_160 = F_154 ( V_192 ) ;
if ( V_160 )
goto V_197;
return 0 ;
V_197:
if ( F_118 ( V_20 ) )
F_151 ( & V_1 -> V_189 , & V_190 ) ;
V_196:
F_151 ( & V_1 -> V_189 , & V_194 ) ;
V_195:
#ifdef F_155
F_156 ( V_192 ) ;
#endif
V_35:
return V_160 ;
}
int T_11 F_157 ( void )
{
struct V_123 * V_105 ;
int V_143 ;
V_105 = F_91 () ;
if ( ! V_105 )
return - V_48 ;
F_103 () ;
F_140 ( & V_176 ) ;
V_143 = F_94 ( V_105 , 1 ) ;
F_141 ( & V_176 ) ;
F_104 () ;
F_105 ( V_105 ) ;
if ( V_143 )
F_158 () ;
return 0 ;
}
static T_9 T_11 F_159 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
const char * V_174 ,
T_10 V_175 )
{
int V_160 ;
V_160 = F_157 () ;
return V_160 ? V_160 : V_175 ;
}
static int T_1 F_160 ( void )
{
int V_20 , V_160 = 0 ;
#ifdef F_155
V_160 = F_161 ( V_198 . V_199 , & V_200 ) ;
if ( V_160 )
return V_160 ;
#endif
F_162 () ;
F_46 (cpu) {
V_160 = F_97 ( V_20 ) ;
if ( V_160 )
goto V_35;
}
F_163 ( F_148 , 0 ) ;
V_35:
F_164 () ;
return V_160 ;
}
