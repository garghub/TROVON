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
if ( V_41 )
V_29 -> V_42 =
( unsigned long ) & V_29 -> V_43 ;
if ( F_19 ( V_29 ) )
goto V_35;
V_44 [ V_20 ] = V_29 ;
F_7 ( V_9 , V_45 , ( T_4 ) ( unsigned long ) V_29 ) ;
return 0 ;
V_35:
if ( V_9 != & V_21 [ 0 ] ) {
F_20 ( V_27 ) ;
F_21 ( V_26 , V_34 ) ;
F_21 ( ( unsigned long ) V_9 -> V_30 , V_33 ) ;
}
return - V_46 ;
}
static void F_22 ( struct V_9 * V_9 )
{
F_7 ( V_9 , V_45 , 0 ) ;
V_44 [ V_9 - V_21 ] = NULL ;
F_23 ( V_9 -> V_30 ) ;
if ( V_9 == & V_21 [ 0 ] )
return;
F_20 ( V_9 -> V_30 -> V_27 - V_37 ) ;
F_21 ( V_9 -> V_30 -> V_26 - V_36 , V_34 ) ;
F_21 ( ( unsigned long ) V_9 -> V_30 , V_33 ) ;
}
static void F_24 ( struct V_9 * V_9 , int V_20 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
if ( V_47 )
F_25 ( V_20 , & V_48 . V_49 . V_50 ) ;
F_25 ( V_20 , F_26 ( & V_48 ) ) ;
F_27 ( & V_48 . V_49 . V_51 ) ;
V_29 -> V_39 = V_20 ;
V_29 -> V_40 = F_18 ( V_20 ) ;
V_29 -> V_52 = V_53 [ V_20 ] ;
V_29 -> V_54 = V_38 . V_54 ;
V_29 -> V_55 = V_38 . V_55 ;
V_29 -> V_56 = V_29 -> V_57 = V_29 -> V_58 = 0 ;
F_28 ( V_29 -> V_59 , 0 , 15 ) ;
F_29 ( ( unsigned int * ) V_29 -> V_60 ) ;
memcpy ( V_29 -> V_61 , V_38 . V_61 ,
V_62 / 8 ) ;
}
static void F_30 ( struct V_9 * V_9 , struct V_63 * V_64 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
struct V_65 * V_66 = F_31 ( V_64 ) ;
V_29 -> V_67 = ( unsigned long ) F_32 ( V_64 )
+ V_68 - V_69 - sizeof( struct V_70 ) ;
V_29 -> V_65 = ( unsigned long ) F_31 ( V_64 ) ;
V_29 -> V_71 = ( unsigned long ) V_64 ;
V_29 -> V_56 = V_66 -> V_56 ;
V_29 -> V_57 = V_66 -> V_57 ;
V_29 -> V_58 = 0 ;
}
static void F_33 ( struct V_9 * V_9 , void (* F_34)( void * ) , void * V_72 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
V_29 -> V_73 = V_29 -> V_67 ;
V_29 -> V_74 = ( unsigned long ) F_34 ;
V_29 -> V_75 = ( unsigned long ) V_72 ;
V_29 -> V_76 = - 1UL ;
F_7 ( V_9 , V_77 , 0 ) ;
}
static void F_35 ( struct V_9 * V_9 , void (* F_34)( void * ) ,
void * V_72 , unsigned long V_78 )
{
struct V_28 * V_29 = V_44 [ V_9 - V_21 ] ;
unsigned long V_79 = F_36 () ;
F_37 ( V_80 ) ;
if ( V_9 -> V_11 == V_79 )
F_34 ( V_72 ) ;
F_7 ( V_9 , V_81 , 0 ) ;
F_38 ( V_29 -> V_73 , V_78 ) ;
F_38 ( V_29 -> V_74 , ( unsigned long ) F_34 ) ;
F_38 ( V_29 -> V_75 , ( unsigned long ) V_72 ) ;
F_38 ( V_29 -> V_76 , V_79 ) ;
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
static int F_39 ( unsigned int V_82 )
{
register unsigned long T_5 V_83 ( L_1 ) = ( unsigned long ) V_82 ;
int V_7 ;
if ( V_84 == V_82 )
return 0 ;
asm volatile(
" sigp %1,0,%2 # sigp set multi-threading\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc) : "d" (reg1), "K" (SIGP_SET_MULTI_THREADING)
: "cc");
if ( V_7 == 0 ) {
V_84 = V_82 ;
V_85 = 0 ;
while ( V_84 >= ( 1U << V_85 ) )
V_85 ++ ;
V_21 [ 0 ] . V_11 = F_36 () ;
}
return V_7 ;
}
void F_40 ( void (* F_34)( void * ) , void * V_72 )
{
struct V_9 * V_9 ;
V_9 = F_11 ( V_86 , F_36 () ) ;
if ( ! V_9 )
V_9 = V_21 + F_41 ( V_86 ) ;
F_35 ( V_9 , F_34 , V_72 , ( unsigned long ) V_73 ) ;
}
void F_42 ( void (* F_34)( void * ) , void * V_72 )
{
F_35 ( & V_21 [ 0 ] , F_34 , V_72 ,
V_21 -> V_30 -> V_27 -
V_37 + V_87 ) ;
}
int F_43 ( T_2 V_11 )
{
int V_20 ;
F_44 (cpu)
if ( V_21 [ V_20 ] . V_11 == V_11 )
return V_20 ;
return - 1 ;
}
int F_45 ( int V_20 )
{
return F_10 ( V_21 + V_20 ) ;
}
void F_46 ( int V_20 )
{
if ( V_88 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_89 )
asm volatile("diag 0,0,0x44");
}
static void F_47 ( T_6 * V_18 )
{
T_7 V_90 ;
int V_20 ;
V_90 = F_48 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_49 ( V_91 , & V_9 -> V_23 ) ;
while ( F_5 ( V_9 -> V_11 , V_25 ,
0 , NULL ) == V_8 &&
F_48 () < V_90 )
F_6 () ;
}
while ( F_48 () < V_90 ) {
F_12 (cpu, cpumask)
if ( F_9 ( V_21 + V_20 ) )
F_50 ( V_20 , V_18 ) ;
if ( F_51 ( V_18 ) )
break;
F_6 () ;
}
}
void F_52 ( void )
{
T_6 V_18 ;
int V_20 ;
F_37 ( V_80 | V_92 ) ;
F_53 () ;
F_54 () ;
F_55 ( & V_18 , V_86 ) ;
F_50 ( F_56 () , & V_18 ) ;
if ( V_93 )
F_47 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_7 ( V_9 , V_81 , 0 ) ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
}
}
static void F_57 ( void )
{
unsigned long V_94 ;
V_94 = F_58 ( & V_21 [ F_56 () ] . V_23 , 0 ) ;
if ( F_59 ( V_91 , & V_94 ) )
F_60 () ;
if ( F_59 ( V_95 , & V_94 ) )
F_61 () ;
if ( F_59 ( V_96 , & V_94 ) )
F_62 () ;
}
static void F_63 ( struct V_97 V_97 ,
unsigned int V_98 , unsigned long V_99 )
{
F_64 ( V_97 . V_100 == 0x1202 ? V_101 : V_102 ) ;
F_57 () ;
}
void F_65 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_96 ) ;
}
void F_66 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_96 ) ;
}
void F_67 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_95 ) ;
}
static void F_68 ( void * V_103 )
{
struct V_104 * V_105 = V_103 ;
unsigned long V_106 [ 16 ] ;
F_28 ( V_106 , 0 , 15 ) ;
V_106 [ V_105 -> V_107 ] = ( V_106 [ V_105 -> V_107 ] & V_105 -> V_108 ) | V_105 -> V_109 ;
F_69 ( V_106 , 0 , 15 ) ;
}
void F_70 ( int V_107 , int V_110 )
{
struct V_104 V_111 = { 1UL << V_110 , - 1UL , V_107 } ;
F_71 ( F_68 , & V_111 , 1 ) ;
}
void F_72 ( int V_107 , int V_110 )
{
struct V_104 V_111 = { 0 , ~ ( 1UL << V_110 ) , V_107 } ;
F_71 ( F_68 , & V_111 , 1 ) ;
}
static inline void F_73 ( int V_20 , T_2 V_11 , int V_112 )
{
void * V_29 = V_21 [ 0 ] . V_30 ;
struct V_113 * V_114 ;
unsigned long V_115 ;
V_114 = F_74 ( V_20 ) ;
if ( ! V_114 )
F_75 ( L_2 ) ;
if ( V_112 ) {
F_76 ( 1 , ( void * ) & V_114 -> V_116 , sizeof( V_114 -> V_116 ) ,
V_117 - V_87 , 0 ) ;
if ( V_41 )
F_77 ( V_114 -> V_118 ) ;
return;
}
F_4 ( V_11 , V_119 , 0 , NULL ) ;
F_78 ( & V_114 -> V_116 , V_29 + V_117 , sizeof( V_114 -> V_116 ) ) ;
if ( ! V_41 )
return;
V_115 = F_17 ( V_31 ) ;
if ( ! V_115 )
F_75 ( L_3 ) ;
F_4 ( V_11 , V_120 , V_115 , NULL ) ;
memcpy ( V_114 -> V_118 , ( void * ) V_115 , sizeof( V_114 -> V_118 ) ) ;
F_20 ( V_115 ) ;
}
static void T_1 F_79 ( struct V_121 * V_103 )
{
unsigned int V_20 , V_11 , V_122 , V_123 ;
int V_112 ;
if ( F_80 () )
return;
if ( ! ( V_124 || V_125 . type == V_126 ) )
return;
F_39 ( F_81 () ) ;
V_20 = 0 ;
for ( V_122 = 0 ; V_122 < V_103 -> V_127 ; V_122 ++ ) {
if ( V_103 -> V_128 && V_103 -> V_20 [ V_122 ] . type != V_129 )
continue;
for ( V_123 = 0 ; V_123 <= V_84 ; V_123 ++ , V_20 ++ ) {
V_11 = ( V_103 -> V_20 [ V_122 ] . V_130 << V_85 ) + V_123 ;
V_112 = ( V_11 == V_21 [ 0 ] . V_11 ) ;
if ( V_112 && ! V_124 )
continue;
F_73 ( V_20 , V_11 , V_112 ) ;
}
}
}
int F_82 ( int V_20 )
{
unsigned long V_115 ;
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
if ( F_4 ( V_9 -> V_11 , V_119 ,
0 , NULL ) != V_131 )
return - V_132 ;
if ( ! V_41 )
return 0 ;
V_115 = F_83 ( V_9 -> V_30 -> V_42 ) ;
F_4 ( V_9 -> V_11 , V_120 ,
V_115 , NULL ) ;
return 0 ;
}
void F_84 ( int V_20 , int V_133 )
{
V_21 [ V_20 ] . V_134 = V_133 ;
}
int F_85 ( int V_20 )
{
return V_21 [ V_20 ] . V_134 ;
}
static struct V_121 * F_86 ( void )
{
static int V_135 ;
struct V_121 * V_103 ;
int V_11 ;
V_103 = F_87 ( sizeof( * V_103 ) , V_31 ) ;
if ( V_103 && ( V_135 || F_88 ( V_103 ) ) ) {
V_135 = 1 ;
for ( V_11 = 0 ; V_11 <= V_136 ;
V_11 += ( 1U << V_85 ) ) {
if ( F_4 ( V_11 , V_13 , 0 , NULL ) ==
V_137 )
continue;
V_103 -> V_20 [ V_103 -> V_127 ] . V_130 =
V_11 >> V_85 ;
V_103 -> V_127 ++ ;
}
V_103 -> V_138 = V_103 -> V_127 ;
}
return V_103 ;
}
static int F_89 ( struct V_121 * V_103 , int V_139 )
{
struct V_9 * V_9 ;
T_6 V_140 ;
int V_20 , V_141 , V_122 , V_123 ;
T_2 V_11 ;
V_141 = 0 ;
F_90 ( & V_140 , V_142 , V_143 ) ;
V_20 = F_41 ( & V_140 ) ;
for ( V_122 = 0 ; ( V_122 < V_103 -> V_138 ) && ( V_20 < V_144 ) ; V_122 ++ ) {
if ( V_103 -> V_128 && V_103 -> V_20 [ V_122 ] . type != V_129 )
continue;
V_11 = V_103 -> V_20 [ V_122 ] . V_130 << V_85 ;
for ( V_123 = 0 ; V_123 <= V_84 ; V_123 ++ ) {
if ( F_11 ( V_143 , V_11 + V_123 ) )
continue;
V_9 = V_21 + V_20 ;
V_9 -> V_11 = V_11 + V_123 ;
V_9 -> V_145 =
( V_20 >= V_103 -> V_127 * ( V_84 + 1 ) ) ?
V_146 : V_147 ;
F_84 ( V_20 , V_148 ) ;
F_91 ( V_20 , true ) ;
if ( V_139 && F_92 ( V_20 ) != 0 )
F_91 ( V_20 , false ) ;
else
V_141 ++ ;
V_20 = F_93 ( V_20 , & V_140 ) ;
if ( V_20 >= V_144 )
break;
}
}
return V_141 ;
}
static void T_1 F_94 ( void )
{
unsigned int V_20 , V_82 , V_149 , V_150 ;
struct V_121 * V_103 ;
T_2 V_11 ;
V_103 = F_86 () ;
if ( ! V_103 )
F_75 ( L_4 ) ;
if ( V_103 -> V_128 ) {
V_11 = F_36 () ;
for ( V_20 = 0 ; V_20 < V_103 -> V_138 ; V_20 ++ )
if ( V_103 -> V_20 [ V_20 ] . V_130 == V_11 ) {
V_129 = V_103 -> V_20 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_103 -> V_138 )
F_75 ( L_5 ) ;
}
#ifdef F_95
F_79 ( V_103 ) ;
#endif
V_82 = F_96 ( V_129 ) ;
V_82 = ( V_82 < V_2 ) ? V_82 : V_2 - 1 ;
F_39 ( V_82 ) ;
V_149 = V_150 = 0 ;
for ( V_20 = 0 ; V_20 < V_103 -> V_138 ; V_20 ++ ) {
if ( V_103 -> V_128 && V_103 -> V_20 [ V_20 ] . type != V_129 )
continue;
if ( V_20 < V_103 -> V_127 )
V_149 += V_84 + 1 ;
else
V_150 += V_84 + 1 ;
}
F_97 ( L_6 , V_149 , V_150 ) ;
F_98 () ;
F_89 ( V_103 , 0 ) ;
F_99 () ;
F_100 ( V_103 ) ;
}
static void F_101 ( void * V_151 )
{
V_38 . V_152 = F_48 () ;
V_38 . V_73 = ( unsigned long ) V_73 ;
V_38 . V_74 = ( unsigned long ) V_153 ;
V_38 . V_75 = 0 ;
V_38 . V_76 = - 1UL ;
F_102 ( V_38 . V_60 ) ;
F_69 ( V_38 . V_59 , 0 , 15 ) ;
F_37 ( V_80 | V_92 ) ;
F_103 () ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 ( F_56 () ) ;
F_109 ( F_56 () , true ) ;
F_64 ( V_154 ) ;
F_110 () ;
F_111 ( V_155 ) ;
}
int F_112 ( unsigned int V_20 , struct V_63 * V_156 )
{
struct V_9 * V_9 ;
int V_157 , V_122 , V_158 ;
V_9 = V_21 + V_20 ;
if ( V_9 -> V_145 != V_147 )
return - V_132 ;
V_157 = V_20 - ( V_20 % ( V_84 + 1 ) ) ;
for ( V_122 = 0 ; V_122 <= V_84 ; V_122 ++ ) {
if ( V_157 + V_122 < V_144 )
if ( F_113 ( V_157 + V_122 ) )
break;
}
if ( V_122 > V_84 &&
F_7 ( V_21 + V_157 , V_159 , 0 ) !=
V_131 )
return - V_132 ;
V_158 = F_15 ( V_9 , V_20 ) ;
if ( V_158 )
return V_158 ;
F_24 ( V_9 , V_20 ) ;
F_30 ( V_9 , V_156 ) ;
F_33 ( V_9 , F_101 , NULL ) ;
while ( ! F_113 ( V_20 ) || ! F_114 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_115 ( char * V_1 )
{
F_3 ( & V_1 , & V_160 ) ;
return 0 ;
}
int F_116 ( void )
{
unsigned long V_106 [ 16 ] ;
F_57 () ;
F_109 ( F_56 () , false ) ;
F_117 () ;
F_28 ( V_106 , 0 , 15 ) ;
V_106 [ 0 ] &= ~ 0x0000ee70UL ;
V_106 [ 6 ] &= ~ 0xff000000UL ;
V_106 [ 14 ] &= ~ 0x1f000000UL ;
F_69 ( V_106 , 0 , 15 ) ;
F_118 ( V_161 ) ;
return 0 ;
}
void F_119 ( unsigned int V_20 )
{
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
F_22 ( V_9 ) ;
F_120 ( & V_48 . V_49 . V_51 ) ;
F_50 ( V_20 , F_26 ( & V_48 ) ) ;
if ( V_47 )
F_50 ( V_20 , & V_48 . V_49 . V_50 ) ;
}
void T_8 F_121 ( void )
{
F_122 () ;
F_7 ( V_21 + F_56 () , V_81 , 0 ) ;
for (; ; ) ;
}
void T_1 F_123 ( void )
{
unsigned int V_162 , V_163 , V_20 ;
V_163 = F_124 ( V_2 , F_125 () + 1 ) ;
V_163 = F_126 () * V_163 ? : V_144 ;
V_162 = V_160 ? : V_144 ;
V_162 = F_124 ( V_162 , V_163 ) ;
for ( V_20 = 0 ; V_20 < V_162 && V_20 < V_144 ; V_20 ++ )
F_127 ( V_20 , true ) ;
}
void T_1 F_128 ( unsigned int V_164 )
{
if ( F_129 ( V_165 , F_63 ) )
F_75 ( L_7 ) ;
if ( F_129 ( V_166 , F_63 ) )
F_75 ( L_8 ) ;
F_94 () ;
}
void T_1 F_130 ( void )
{
struct V_9 * V_9 = V_21 ;
V_9 -> V_145 = V_147 ;
V_9 -> V_11 = F_36 () ;
V_9 -> V_30 = (struct V_28 * ) ( unsigned long ) F_131 () ;
V_38 . V_52 = V_53 [ 0 ] ;
F_84 ( 0 , V_148 ) ;
F_91 ( 0 , true ) ;
F_109 ( 0 , true ) ;
}
void T_1 F_132 ( unsigned int V_164 )
{
}
void T_1 F_133 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_18 ( 0 ) ;
}
int F_134 ( unsigned int V_167 )
{
return 0 ;
}
static T_9 F_135 ( struct V_168 * V_169 ,
struct V_170 * V_171 , char * V_172 )
{
T_9 V_173 ;
F_136 ( & V_174 ) ;
V_173 = sprintf ( V_172 , L_9 , V_21 [ V_169 -> V_175 ] . V_145 ) ;
F_137 ( & V_174 ) ;
return V_173 ;
}
static T_9 F_138 ( struct V_168 * V_169 ,
struct V_170 * V_171 ,
const char * V_172 , T_10 V_173 )
{
struct V_9 * V_9 ;
int V_20 , V_133 , V_158 , V_122 ;
char V_176 ;
if ( sscanf ( V_172 , L_10 , & V_133 , & V_176 ) != 1 )
return - V_177 ;
if ( V_133 != 0 && V_133 != 1 )
return - V_177 ;
F_98 () ;
F_136 ( & V_174 ) ;
V_158 = - V_178 ;
V_20 = V_169 -> V_175 ;
V_20 -= V_20 % ( V_84 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_122 = 0 ; V_122 <= V_84 ; V_122 ++ )
if ( F_113 ( V_20 + V_122 ) )
goto V_35;
V_9 = V_21 + V_20 ;
V_158 = 0 ;
switch ( V_133 ) {
case 0 :
if ( V_9 -> V_145 != V_147 )
break;
V_158 = F_139 ( V_9 -> V_11 >> V_85 ) ;
if ( V_158 )
break;
for ( V_122 = 0 ; V_122 <= V_84 ; V_122 ++ ) {
if ( V_20 + V_122 >= V_144 || ! F_140 ( V_20 + V_122 ) )
continue;
V_9 [ V_122 ] . V_145 = V_146 ;
F_84 ( V_20 + V_122 ,
V_148 ) ;
}
F_141 () ;
break;
case 1 :
if ( V_9 -> V_145 != V_146 )
break;
V_158 = F_142 ( V_9 -> V_11 >> V_85 ) ;
if ( V_158 )
break;
for ( V_122 = 0 ; V_122 <= V_84 ; V_122 ++ ) {
if ( V_20 + V_122 >= V_144 || ! F_140 ( V_20 + V_122 ) )
continue;
V_9 [ V_122 ] . V_145 = V_147 ;
F_84 ( V_20 + V_122 ,
V_148 ) ;
}
F_141 () ;
break;
default:
break;
}
V_35:
F_137 ( & V_174 ) ;
F_99 () ;
return V_158 ? V_158 : V_173 ;
}
static T_9 F_143 ( struct V_168 * V_169 ,
struct V_170 * V_171 , char * V_172 )
{
return sprintf ( V_172 , L_9 , V_21 [ V_169 -> V_175 ] . V_11 ) ;
}
static int F_144 ( struct V_179 * V_180 , unsigned long V_181 ,
void * V_182 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_182 ;
struct V_168 * V_1 = & F_145 ( V_183 , V_20 ) -> V_169 ;
int V_184 = 0 ;
switch ( V_181 & ~ V_185 ) {
case V_186 :
V_184 = F_146 ( & V_1 -> V_187 , & V_188 ) ;
break;
case V_189 :
F_147 ( & V_1 -> V_187 , & V_188 ) ;
break;
}
return F_148 ( V_184 ) ;
}
static int F_92 ( int V_20 )
{
struct V_168 * V_1 ;
struct V_20 * V_190 ;
int V_158 ;
V_190 = F_87 ( sizeof( * V_190 ) , V_31 ) ;
if ( ! V_190 )
return - V_46 ;
F_145 ( V_183 , V_20 ) = V_190 ;
V_1 = & V_190 -> V_169 ;
V_190 -> V_191 = 1 ;
V_158 = F_149 ( V_190 , V_20 ) ;
if ( V_158 )
goto V_35;
V_158 = F_146 ( & V_1 -> V_187 , & V_192 ) ;
if ( V_158 )
goto V_193;
if ( F_113 ( V_20 ) ) {
V_158 = F_146 ( & V_1 -> V_187 , & V_188 ) ;
if ( V_158 )
goto V_194;
}
V_158 = F_150 ( V_190 ) ;
if ( V_158 )
goto V_195;
return 0 ;
V_195:
if ( F_113 ( V_20 ) )
F_147 ( & V_1 -> V_187 , & V_188 ) ;
V_194:
F_147 ( & V_1 -> V_187 , & V_192 ) ;
V_193:
#ifdef F_151
F_152 ( V_190 ) ;
#endif
V_35:
return V_158 ;
}
int T_11 F_153 ( void )
{
struct V_121 * V_103 ;
int V_141 ;
V_103 = F_86 () ;
if ( ! V_103 )
return - V_46 ;
F_98 () ;
F_136 ( & V_174 ) ;
V_141 = F_89 ( V_103 , 1 ) ;
F_137 ( & V_174 ) ;
F_99 () ;
F_100 ( V_103 ) ;
if ( V_141 )
F_154 () ;
return 0 ;
}
static T_9 T_11 F_155 ( struct V_168 * V_169 ,
struct V_170 * V_171 ,
const char * V_172 ,
T_10 V_173 )
{
int V_158 ;
V_158 = F_153 () ;
return V_158 ? V_158 : V_173 ;
}
static int T_1 F_156 ( void )
{
int V_20 , V_158 = 0 ;
#ifdef F_151
V_158 = F_157 ( V_196 . V_197 , & V_198 ) ;
if ( V_158 )
return V_158 ;
#endif
F_158 () ;
F_44 (cpu) {
V_158 = F_92 ( V_20 ) ;
if ( V_158 )
goto V_35;
}
F_159 ( F_144 , 0 ) ;
V_35:
F_160 () ;
return V_158 ;
}
