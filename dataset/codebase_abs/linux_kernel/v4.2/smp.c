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
static void F_73 ( struct V_112 * V_113 , T_2 V_11 ,
int V_114 )
{
void * V_29 = ( void * ) ( unsigned long ) F_74 () ;
unsigned long V_115 ;
if ( V_114 ) {
F_75 ( 1 , ( void * ) & V_113 -> V_116 , sizeof( V_113 -> V_116 ) ,
V_117 - V_87 , 0 ) ;
if ( V_41 )
F_76 ( V_113 -> V_118 ) ;
return;
}
F_4 ( V_11 , V_119 , 0 , NULL ) ;
F_77 ( & V_113 -> V_116 , V_29 + V_117 , sizeof( V_113 -> V_116 ) ) ;
if ( ! V_41 )
return;
V_115 = F_78 ( V_87 , V_87 ) ;
if ( ! V_115 )
F_79 ( L_2 ) ;
F_4 ( V_11 , V_120 , V_115 , NULL ) ;
memcpy ( V_113 -> V_118 , ( void * ) V_115 , sizeof( V_113 -> V_118 ) ) ;
F_80 ( V_115 , V_87 ) ;
}
int F_81 ( int V_20 )
{
unsigned long V_115 ;
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
if ( F_4 ( V_9 -> V_11 , V_119 ,
0 , NULL ) != V_121 )
return - V_122 ;
if ( ! V_41 )
return 0 ;
V_115 = F_82 ( V_9 -> V_30 -> V_42 ) ;
F_4 ( V_9 -> V_11 , V_120 ,
V_115 , NULL ) ;
return 0 ;
}
void T_1 F_83 ( void )
{
#ifdef F_84
int V_3 , V_20 , V_123 , V_124 ;
struct V_112 * V_113 ;
bool V_114 ;
if ( F_85 () )
return;
if ( ! ( V_125 || V_126 . type == V_127 ) )
return;
F_39 ( V_128 . V_129 ) ;
V_124 = V_130 << V_128 . V_129 ;
for ( V_20 = 0 , V_3 = 0 ; V_3 <= V_124 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 , NULL ) ==
V_131 )
continue;
V_20 += 1 ;
}
V_132 . V_133 = ( void * ) F_78 ( sizeof( void * ) * V_20 , 8 ) ;
V_132 . V_134 = V_20 ;
V_123 = F_36 () ;
for ( V_20 = 0 , V_3 = 0 ; V_3 <= V_124 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 , NULL ) ==
V_131 )
continue;
V_113 = ( void * ) F_78 ( sizeof( * V_113 ) , 8 ) ;
V_132 . V_133 [ V_20 ] = V_113 ;
if ( ! V_113 )
F_79 ( L_3 ) ;
V_114 = ( V_3 == V_123 ) ;
V_20 += 1 ;
if ( V_114 && ! V_125 )
continue;
F_73 ( V_113 , V_3 , V_114 ) ;
}
F_86 () ;
F_39 ( 0 ) ;
#endif
}
void F_87 ( int V_20 , int V_135 )
{
V_21 [ V_20 ] . V_136 = V_135 ;
}
int F_88 ( int V_20 )
{
return V_21 [ V_20 ] . V_136 ;
}
static struct V_137 * F_89 ( void )
{
static int V_138 ;
struct V_137 * V_103 ;
int V_11 ;
V_103 = F_90 ( sizeof( * V_103 ) , V_31 ) ;
if ( V_103 && ( V_138 || F_91 ( V_103 ) ) ) {
V_138 = 1 ;
for ( V_11 = 0 ;
V_11 < ( V_130 << V_85 ) ;
V_11 += ( 1U << V_85 ) ) {
if ( F_4 ( V_11 , V_13 , 0 , NULL ) ==
V_131 )
continue;
V_103 -> V_139 [ V_103 -> V_140 ] . V_141 =
V_11 >> V_85 ;
V_103 -> V_140 ++ ;
}
V_103 -> V_142 = V_103 -> V_140 ;
}
return V_103 ;
}
static int F_92 ( struct V_137 * V_103 , int V_143 )
{
struct V_9 * V_9 ;
T_6 V_144 ;
int V_20 , V_145 , V_146 , V_147 ;
T_2 V_11 ;
V_145 = 0 ;
F_93 ( & V_144 , V_148 , V_149 ) ;
V_20 = F_41 ( & V_144 ) ;
for ( V_146 = 0 ; ( V_146 < V_103 -> V_142 ) && ( V_20 < V_150 ) ; V_146 ++ ) {
if ( V_128 . V_151 && V_103 -> V_139 [ V_146 ] . type != V_152 )
continue;
V_11 = V_103 -> V_139 [ V_146 ] . V_141 << V_85 ;
for ( V_147 = 0 ; V_147 <= V_84 ; V_147 ++ ) {
if ( F_11 ( V_149 , V_11 + V_147 ) )
continue;
V_9 = V_21 + V_20 ;
V_9 -> V_11 = V_11 + V_147 ;
V_9 -> V_153 =
( V_20 >= V_103 -> V_140 * ( V_84 + 1 ) ) ?
V_154 : V_155 ;
F_87 ( V_20 , V_156 ) ;
F_94 ( V_20 , true ) ;
if ( V_143 && F_95 ( V_20 ) != 0 )
F_94 ( V_20 , false ) ;
else
V_145 ++ ;
V_20 = F_96 ( V_20 , & V_144 ) ;
if ( V_20 >= V_150 )
break;
}
}
return V_145 ;
}
static void T_1 F_97 ( void )
{
unsigned int V_20 , V_82 , V_157 , V_158 ;
struct V_137 * V_103 ;
T_2 V_11 ;
V_103 = F_89 () ;
if ( ! V_103 )
F_79 ( L_4 ) ;
if ( V_128 . V_151 ) {
V_11 = F_36 () ;
for ( V_20 = 0 ; V_20 < V_103 -> V_142 ; V_20 ++ )
if ( V_103 -> V_139 [ V_20 ] . V_141 == V_11 ) {
V_152 = V_103 -> V_139 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_103 -> V_142 )
F_79 ( L_5 ) ;
}
V_82 = V_152 ? V_128 . V_82 : V_128 . V_159 ;
V_82 = ( V_82 < V_2 ) ? V_82 : V_2 - 1 ;
F_39 ( V_82 ) ;
V_157 = V_158 = 0 ;
for ( V_20 = 0 ; V_20 < V_103 -> V_142 ; V_20 ++ ) {
if ( V_128 . V_151 &&
V_103 -> V_139 [ V_20 ] . type != V_152 )
continue;
if ( V_20 < V_103 -> V_140 )
V_157 += V_84 + 1 ;
else
V_158 += V_84 + 1 ;
}
F_98 ( L_6 , V_157 , V_158 ) ;
F_99 () ;
F_92 ( V_103 , 0 ) ;
F_100 () ;
F_101 ( V_103 ) ;
}
static void F_102 ( void * V_160 )
{
V_38 . V_161 = F_48 () ;
V_38 . V_73 = ( unsigned long ) V_73 ;
V_38 . V_74 = ( unsigned long ) V_162 ;
V_38 . V_75 = 0 ;
V_38 . V_76 = - 1UL ;
F_103 ( V_38 . V_60 ) ;
F_69 ( V_38 . V_59 , 0 , 15 ) ;
F_37 ( V_80 | V_92 ) ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 ( F_56 () ) ;
F_110 ( F_56 () , true ) ;
F_64 ( V_163 ) ;
F_111 () ;
F_112 ( V_164 ) ;
}
int F_113 ( unsigned int V_20 , struct V_63 * V_165 )
{
struct V_9 * V_9 ;
int V_166 , V_146 , V_167 ;
V_9 = V_21 + V_20 ;
if ( V_9 -> V_153 != V_155 )
return - V_122 ;
V_166 = V_20 - ( V_20 % ( V_84 + 1 ) ) ;
for ( V_146 = 0 ; V_146 <= V_84 ; V_146 ++ ) {
if ( V_166 + V_146 < V_150 )
if ( F_114 ( V_166 + V_146 ) )
break;
}
if ( V_146 > V_84 &&
F_7 ( V_21 + V_166 , V_168 , 0 ) !=
V_121 )
return - V_122 ;
V_167 = F_15 ( V_9 , V_20 ) ;
if ( V_167 )
return V_167 ;
F_24 ( V_9 , V_20 ) ;
F_30 ( V_9 , V_165 ) ;
F_33 ( V_9 , F_102 , NULL ) ;
while ( ! F_114 ( V_20 ) || ! F_115 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_116 ( char * V_1 )
{
F_3 ( & V_1 , & V_169 ) ;
return 0 ;
}
int F_117 ( void )
{
unsigned long V_106 [ 16 ] ;
F_57 () ;
F_110 ( F_56 () , false ) ;
F_118 () ;
F_28 ( V_106 , 0 , 15 ) ;
V_106 [ 0 ] &= ~ 0x0000ee70UL ;
V_106 [ 6 ] &= ~ 0xff000000UL ;
V_106 [ 14 ] &= ~ 0x1f000000UL ;
F_69 ( V_106 , 0 , 15 ) ;
F_119 ( V_170 ) ;
return 0 ;
}
void F_120 ( unsigned int V_20 )
{
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
F_22 ( V_9 ) ;
F_121 ( & V_48 . V_49 . V_51 ) ;
F_50 ( V_20 , F_26 ( & V_48 ) ) ;
if ( V_47 )
F_50 ( V_20 , & V_48 . V_49 . V_50 ) ;
}
void T_8 F_122 ( void )
{
F_123 () ;
F_7 ( V_21 + F_56 () , V_81 , 0 ) ;
for (; ; ) ;
}
void T_1 F_124 ( void )
{
unsigned int V_171 , V_172 , V_20 ;
V_172 = F_125 ( V_128 . V_82 , V_128 . V_159 ) + 1 ;
V_172 = F_126 ( V_2 , V_172 ) ;
V_172 = V_128 . V_173 * V_172 ? : V_150 ;
V_171 = V_169 ? : V_150 ;
V_171 = F_126 ( V_171 , V_172 ) ;
for ( V_20 = 0 ; V_20 < V_171 && V_20 < V_150 ; V_20 ++ )
F_127 ( V_20 , true ) ;
}
void T_1 F_128 ( unsigned int V_174 )
{
if ( F_129 ( V_175 , F_63 ) )
F_79 ( L_7 ) ;
if ( F_129 ( V_176 , F_63 ) )
F_79 ( L_8 ) ;
F_97 () ;
}
void T_1 F_130 ( void )
{
struct V_9 * V_9 = V_21 ;
V_9 -> V_153 = V_155 ;
V_9 -> V_11 = F_36 () ;
V_9 -> V_30 = (struct V_28 * ) ( unsigned long ) F_74 () ;
V_38 . V_52 = V_53 [ 0 ] ;
F_87 ( 0 , V_156 ) ;
F_94 ( 0 , true ) ;
F_110 ( 0 , true ) ;
}
void T_1 F_131 ( unsigned int V_174 )
{
}
void T_1 F_132 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_18 ( 0 ) ;
}
int F_133 ( unsigned int V_177 )
{
return 0 ;
}
static T_9 F_134 ( struct V_178 * V_179 ,
struct V_180 * V_181 , char * V_182 )
{
T_9 V_134 ;
F_135 ( & V_183 ) ;
V_134 = sprintf ( V_182 , L_9 , V_21 [ V_179 -> V_184 ] . V_153 ) ;
F_136 ( & V_183 ) ;
return V_134 ;
}
static T_9 F_137 ( struct V_178 * V_179 ,
struct V_180 * V_181 ,
const char * V_182 , T_10 V_134 )
{
struct V_9 * V_9 ;
int V_20 , V_135 , V_167 , V_146 ;
char V_185 ;
if ( sscanf ( V_182 , L_10 , & V_135 , & V_185 ) != 1 )
return - V_186 ;
if ( V_135 != 0 && V_135 != 1 )
return - V_186 ;
F_99 () ;
F_135 ( & V_183 ) ;
V_167 = - V_187 ;
V_20 = V_179 -> V_184 ;
V_20 -= V_20 % ( V_84 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_146 = 0 ; V_146 <= V_84 ; V_146 ++ )
if ( F_114 ( V_20 + V_146 ) )
goto V_35;
V_9 = V_21 + V_20 ;
V_167 = 0 ;
switch ( V_135 ) {
case 0 :
if ( V_9 -> V_153 != V_155 )
break;
V_167 = F_138 ( V_9 -> V_11 >> V_85 ) ;
if ( V_167 )
break;
for ( V_146 = 0 ; V_146 <= V_84 ; V_146 ++ ) {
if ( V_20 + V_146 >= V_150 || ! F_139 ( V_20 + V_146 ) )
continue;
V_9 [ V_146 ] . V_153 = V_154 ;
F_87 ( V_20 + V_146 ,
V_156 ) ;
}
F_140 () ;
break;
case 1 :
if ( V_9 -> V_153 != V_154 )
break;
V_167 = F_141 ( V_9 -> V_11 >> V_85 ) ;
if ( V_167 )
break;
for ( V_146 = 0 ; V_146 <= V_84 ; V_146 ++ ) {
if ( V_20 + V_146 >= V_150 || ! F_139 ( V_20 + V_146 ) )
continue;
V_9 [ V_146 ] . V_153 = V_155 ;
F_87 ( V_20 + V_146 ,
V_156 ) ;
}
F_140 () ;
break;
default:
break;
}
V_35:
F_136 ( & V_183 ) ;
F_100 () ;
return V_167 ? V_167 : V_134 ;
}
static T_9 F_142 ( struct V_178 * V_179 ,
struct V_180 * V_181 , char * V_182 )
{
return sprintf ( V_182 , L_9 , V_21 [ V_179 -> V_184 ] . V_11 ) ;
}
static int F_143 ( struct V_188 * V_189 , unsigned long V_190 ,
void * V_191 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_191 ;
struct V_178 * V_1 = & F_144 ( V_192 , V_20 ) -> V_179 ;
int V_193 = 0 ;
switch ( V_190 & ~ V_194 ) {
case V_195 :
V_193 = F_145 ( & V_1 -> V_196 , & V_197 ) ;
break;
case V_198 :
F_146 ( & V_1 -> V_196 , & V_197 ) ;
break;
}
return F_147 ( V_193 ) ;
}
static int F_95 ( int V_20 )
{
struct V_178 * V_1 ;
struct V_20 * V_199 ;
int V_167 ;
V_199 = F_90 ( sizeof( * V_199 ) , V_31 ) ;
if ( ! V_199 )
return - V_46 ;
F_144 ( V_192 , V_20 ) = V_199 ;
V_1 = & V_199 -> V_179 ;
V_199 -> V_200 = 1 ;
V_167 = F_148 ( V_199 , V_20 ) ;
if ( V_167 )
goto V_35;
V_167 = F_145 ( & V_1 -> V_196 , & V_201 ) ;
if ( V_167 )
goto V_202;
if ( F_114 ( V_20 ) ) {
V_167 = F_145 ( & V_1 -> V_196 , & V_197 ) ;
if ( V_167 )
goto V_203;
}
V_167 = F_149 ( V_199 ) ;
if ( V_167 )
goto V_204;
return 0 ;
V_204:
if ( F_114 ( V_20 ) )
F_146 ( & V_1 -> V_196 , & V_197 ) ;
V_203:
F_146 ( & V_1 -> V_196 , & V_201 ) ;
V_202:
#ifdef F_150
F_151 ( V_199 ) ;
#endif
V_35:
return V_167 ;
}
int T_11 F_152 ( void )
{
struct V_137 * V_103 ;
int V_145 ;
V_103 = F_89 () ;
if ( ! V_103 )
return - V_46 ;
F_99 () ;
F_135 ( & V_183 ) ;
V_145 = F_92 ( V_103 , 1 ) ;
F_136 ( & V_183 ) ;
F_100 () ;
F_101 ( V_103 ) ;
if ( V_145 )
F_153 () ;
return 0 ;
}
static T_9 T_11 F_154 ( struct V_178 * V_179 ,
struct V_180 * V_181 ,
const char * V_182 ,
T_10 V_134 )
{
int V_167 ;
V_167 = F_152 () ;
return V_167 ? V_167 : V_134 ;
}
static int T_1 F_155 ( void )
{
int V_20 , V_167 = 0 ;
#ifdef F_150
V_167 = F_156 ( V_205 . V_206 , & V_207 ) ;
if ( V_167 )
return V_167 ;
#endif
F_157 () ;
F_44 (cpu) {
V_167 = F_95 ( V_20 ) ;
if ( V_167 )
goto V_35;
}
F_158 ( F_143 , 0 ) ;
V_35:
F_159 () ;
return V_167 ;
}
