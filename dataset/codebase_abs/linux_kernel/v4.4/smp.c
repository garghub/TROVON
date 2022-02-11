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
V_29 -> V_72 = V_73 ;
V_29 -> V_74 = V_64 -> V_75 ;
V_29 -> V_56 = V_66 -> V_56 ;
V_29 -> V_57 = V_66 -> V_57 ;
V_29 -> V_58 = 0 ;
}
static void F_33 ( struct V_9 * V_9 , void (* F_34)( void * ) , void * V_76 )
{
struct V_28 * V_29 = V_9 -> V_30 ;
V_29 -> V_77 = V_29 -> V_67 ;
V_29 -> V_78 = ( unsigned long ) F_34 ;
V_29 -> V_79 = ( unsigned long ) V_76 ;
V_29 -> V_80 = - 1UL ;
F_7 ( V_9 , V_81 , 0 ) ;
}
static void F_35 ( struct V_9 * V_9 , void (* F_34)( void * ) ,
void * V_76 , unsigned long V_82 )
{
struct V_28 * V_29 = V_44 [ V_9 - V_21 ] ;
unsigned long V_83 = F_36 () ;
F_37 ( V_84 ) ;
if ( V_9 -> V_11 == V_83 )
F_34 ( V_76 ) ;
F_7 ( V_9 , V_85 , 0 ) ;
F_38 ( V_29 -> V_77 , V_82 ) ;
F_38 ( V_29 -> V_78 , ( unsigned long ) F_34 ) ;
F_38 ( V_29 -> V_79 , ( unsigned long ) V_76 ) ;
F_38 ( V_29 -> V_80 , V_83 ) ;
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
static int F_39 ( unsigned int V_86 )
{
register unsigned long T_5 V_87 ( L_1 ) = ( unsigned long ) V_86 ;
int V_7 ;
if ( V_88 == V_86 )
return 0 ;
asm volatile(
" sigp %1,0,%2 # sigp set multi-threading\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc) : "d" (reg1), "K" (SIGP_SET_MULTI_THREADING)
: "cc");
if ( V_7 == 0 ) {
V_88 = V_86 ;
V_89 = 0 ;
while ( V_88 >= ( 1U << V_89 ) )
V_89 ++ ;
V_21 [ 0 ] . V_11 = F_36 () ;
}
return V_7 ;
}
void F_40 ( void (* F_34)( void * ) , void * V_76 )
{
struct V_9 * V_9 ;
V_9 = F_11 ( V_90 , F_36 () ) ;
if ( ! V_9 )
V_9 = V_21 + F_41 ( V_90 ) ;
F_35 ( V_9 , F_34 , V_76 , ( unsigned long ) V_77 ) ;
}
void F_42 ( void (* F_34)( void * ) , void * V_76 )
{
F_35 ( & V_21 [ 0 ] , F_34 , V_76 ,
V_21 -> V_30 -> V_27 -
V_37 + V_91 ) ;
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
if ( V_92 ) {
F_47 ( V_93 ) ;
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
} else if ( V_94 ) {
F_47 ( V_95 ) ;
asm volatile("diag 0,0,0x44");
}
}
static void F_48 ( T_6 * V_18 )
{
T_7 V_96 ;
int V_20 ;
V_96 = F_49 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_50 ( V_97 , & V_9 -> V_23 ) ;
while ( F_5 ( V_9 -> V_11 , V_25 ,
0 , NULL ) == V_8 &&
F_49 () < V_96 )
F_6 () ;
}
while ( F_49 () < V_96 ) {
F_12 (cpu, cpumask)
if ( F_9 ( V_21 + V_20 ) )
F_51 ( V_20 , V_18 ) ;
if ( F_52 ( V_18 ) )
break;
F_6 () ;
}
}
void F_53 ( void )
{
T_6 V_18 ;
int V_20 ;
F_37 ( V_84 | V_98 ) ;
F_54 () ;
F_55 () ;
F_56 ( & V_18 , V_90 ) ;
F_51 ( F_57 () , & V_18 ) ;
if ( V_99 )
F_48 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_9 * V_9 = V_21 + V_20 ;
F_7 ( V_9 , V_85 , 0 ) ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
}
}
static void F_58 ( void )
{
unsigned long V_100 ;
V_100 = F_59 ( & V_21 [ F_57 () ] . V_23 , 0 ) ;
if ( F_60 ( V_97 , & V_100 ) )
F_61 () ;
if ( F_60 ( V_101 , & V_100 ) )
F_62 () ;
if ( F_60 ( V_102 , & V_100 ) )
F_63 () ;
}
static void F_64 ( struct V_103 V_103 ,
unsigned int V_104 , unsigned long V_105 )
{
F_65 ( V_103 . V_106 == 0x1202 ? V_107 : V_108 ) ;
F_58 () ;
}
void F_66 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_102 ) ;
}
void F_67 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_102 ) ;
}
void F_68 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_101 ) ;
}
static void F_69 ( void * V_109 )
{
struct V_110 * V_111 = V_109 ;
unsigned long V_112 [ 16 ] ;
F_28 ( V_112 , 0 , 15 ) ;
V_112 [ V_111 -> V_113 ] = ( V_112 [ V_111 -> V_113 ] & V_111 -> V_114 ) | V_111 -> V_115 ;
F_70 ( V_112 , 0 , 15 ) ;
}
void F_71 ( int V_113 , int V_116 )
{
struct V_110 V_117 = { 1UL << V_116 , - 1UL , V_113 } ;
F_72 ( F_69 , & V_117 , 1 ) ;
}
void F_73 ( int V_113 , int V_116 )
{
struct V_110 V_117 = { 0 , ~ ( 1UL << V_116 ) , V_113 } ;
F_72 ( F_69 , & V_117 , 1 ) ;
}
static void T_1 F_74 ( struct V_118 * V_119 ,
T_2 V_11 , int V_120 )
{
void * V_29 = ( void * ) ( unsigned long ) F_75 () ;
unsigned long V_121 ;
if ( V_120 ) {
F_76 ( 1 , ( void * ) & V_119 -> V_122 , sizeof( V_119 -> V_122 ) ,
V_123 - V_91 , 0 ) ;
if ( V_41 )
F_77 ( V_119 -> V_124 ) ;
return;
}
F_4 ( V_11 , V_125 , 0 , NULL ) ;
F_78 ( & V_119 -> V_122 , V_29 + V_123 , sizeof( V_119 -> V_122 ) ) ;
if ( ! V_41 )
return;
V_121 = F_79 ( V_91 , V_91 ) ;
if ( ! V_121 )
F_80 ( L_2 ) ;
F_4 ( V_11 , V_126 , V_121 , NULL ) ;
memcpy ( V_119 -> V_124 , ( void * ) V_121 , sizeof( V_119 -> V_124 ) ) ;
F_81 ( V_121 , V_91 ) ;
}
int F_82 ( int V_20 )
{
unsigned long V_121 ;
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
if ( F_4 ( V_9 -> V_11 , V_125 ,
0 , NULL ) != V_127 )
return - V_128 ;
if ( ! V_41 )
return 0 ;
V_121 = F_83 ( V_9 -> V_30 -> V_42 ) ;
F_4 ( V_9 -> V_11 , V_126 ,
V_121 , NULL ) ;
return 0 ;
}
void T_1 F_84 ( void )
{
#ifdef F_85
int V_3 , V_20 , V_129 , V_130 ;
struct V_118 * V_119 ;
bool V_120 ;
if ( F_86 () )
return;
if ( ! ( V_131 || V_132 . type == V_133 ) )
return;
F_39 ( V_134 . V_135 ) ;
V_130 = V_136 << V_134 . V_135 ;
for ( V_20 = 0 , V_3 = 0 ; V_3 <= V_130 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 , NULL ) ==
V_137 )
continue;
V_20 += 1 ;
}
V_138 . V_139 = ( void * ) F_79 ( sizeof( void * ) * V_20 , 8 ) ;
V_138 . V_140 = V_20 ;
V_129 = F_36 () ;
for ( V_20 = 0 , V_3 = 0 ; V_3 <= V_130 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 , NULL ) ==
V_137 )
continue;
V_119 = ( void * ) F_79 ( sizeof( * V_119 ) , 8 ) ;
V_138 . V_139 [ V_20 ] = V_119 ;
if ( ! V_119 )
F_80 ( L_3 ) ;
V_120 = ( V_3 == V_129 ) ;
V_20 += 1 ;
if ( V_120 && ! V_131 )
continue;
F_74 ( V_119 , V_3 , V_120 ) ;
}
F_87 () ;
F_39 ( 0 ) ;
#endif
}
void F_88 ( int V_20 , int V_141 )
{
V_21 [ V_20 ] . V_142 = V_141 ;
}
int F_89 ( int V_20 )
{
return V_21 [ V_20 ] . V_142 ;
}
static struct V_143 * F_90 ( void )
{
static int V_144 ;
struct V_143 * V_109 ;
int V_11 ;
V_109 = F_91 ( sizeof( * V_109 ) , V_31 ) ;
if ( V_109 && ( V_144 || F_92 ( V_109 ) ) ) {
V_144 = 1 ;
for ( V_11 = 0 ;
V_11 < ( V_136 << V_89 ) ;
V_11 += ( 1U << V_89 ) ) {
if ( F_4 ( V_11 , V_13 , 0 , NULL ) ==
V_137 )
continue;
V_109 -> V_145 [ V_109 -> V_146 ] . V_147 =
V_11 >> V_89 ;
V_109 -> V_146 ++ ;
}
V_109 -> V_148 = V_109 -> V_146 ;
}
return V_109 ;
}
static int F_93 ( struct V_143 * V_109 , int V_149 )
{
struct V_9 * V_9 ;
T_6 V_150 ;
int V_20 , V_151 , V_152 , V_153 ;
T_2 V_11 ;
V_151 = 0 ;
F_94 ( & V_150 , V_154 , V_155 ) ;
V_20 = F_41 ( & V_150 ) ;
for ( V_152 = 0 ; ( V_152 < V_109 -> V_148 ) && ( V_20 < V_156 ) ; V_152 ++ ) {
if ( V_134 . V_157 && V_109 -> V_145 [ V_152 ] . type != V_158 )
continue;
V_11 = V_109 -> V_145 [ V_152 ] . V_147 << V_89 ;
for ( V_153 = 0 ; V_153 <= V_88 ; V_153 ++ ) {
if ( F_11 ( V_155 , V_11 + V_153 ) )
continue;
V_9 = V_21 + V_20 ;
V_9 -> V_11 = V_11 + V_153 ;
V_9 -> V_159 =
( V_20 >= V_109 -> V_146 * ( V_88 + 1 ) ) ?
V_160 : V_161 ;
F_88 ( V_20 , V_162 ) ;
F_95 ( V_20 , true ) ;
if ( V_149 && F_96 ( V_20 ) != 0 )
F_95 ( V_20 , false ) ;
else
V_151 ++ ;
V_20 = F_97 ( V_20 , & V_150 ) ;
if ( V_20 >= V_156 )
break;
}
}
return V_151 ;
}
static void T_1 F_98 ( void )
{
unsigned int V_20 , V_86 , V_163 , V_164 ;
struct V_143 * V_109 ;
T_2 V_11 ;
V_109 = F_90 () ;
if ( ! V_109 )
F_80 ( L_4 ) ;
if ( V_134 . V_157 ) {
V_11 = F_36 () ;
for ( V_20 = 0 ; V_20 < V_109 -> V_148 ; V_20 ++ )
if ( V_109 -> V_145 [ V_20 ] . V_147 == V_11 ) {
V_158 = V_109 -> V_145 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_109 -> V_148 )
F_80 ( L_5 ) ;
}
V_86 = V_158 ? V_134 . V_86 : V_134 . V_165 ;
V_86 = ( V_86 < V_2 ) ? V_86 : V_2 - 1 ;
F_39 ( V_86 ) ;
V_163 = V_164 = 0 ;
for ( V_20 = 0 ; V_20 < V_109 -> V_148 ; V_20 ++ ) {
if ( V_134 . V_157 &&
V_109 -> V_145 [ V_20 ] . type != V_158 )
continue;
if ( V_20 < V_109 -> V_146 )
V_163 += V_88 + 1 ;
else
V_164 += V_88 + 1 ;
}
F_99 ( L_6 , V_163 , V_164 ) ;
F_100 () ;
F_93 ( V_109 , 0 ) ;
F_101 () ;
F_102 ( V_109 ) ;
}
static void F_103 ( void * V_166 )
{
V_38 . V_167 = F_49 () ;
V_38 . V_77 = ( unsigned long ) V_77 ;
V_38 . V_78 = ( unsigned long ) V_168 ;
V_38 . V_79 = 0 ;
V_38 . V_80 = - 1UL ;
F_104 ( V_38 . V_60 ) ;
F_70 ( V_38 . V_59 , 0 , 15 ) ;
F_37 ( V_84 | V_98 ) ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_110 ( F_57 () ) ;
F_111 ( F_57 () , true ) ;
F_65 ( V_169 ) ;
F_112 () ;
F_113 ( V_170 ) ;
}
int F_114 ( unsigned int V_20 , struct V_63 * V_171 )
{
struct V_9 * V_9 ;
int V_172 , V_152 , V_173 ;
V_9 = V_21 + V_20 ;
if ( V_9 -> V_159 != V_161 )
return - V_128 ;
V_172 = V_20 - ( V_20 % ( V_88 + 1 ) ) ;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_172 + V_152 < V_156 )
if ( F_115 ( V_172 + V_152 ) )
break;
}
if ( V_152 > V_88 &&
F_7 ( V_21 + V_172 , V_174 , 0 ) !=
V_127 )
return - V_128 ;
V_173 = F_15 ( V_9 , V_20 ) ;
if ( V_173 )
return V_173 ;
F_24 ( V_9 , V_20 ) ;
F_30 ( V_9 , V_171 ) ;
F_33 ( V_9 , F_103 , NULL ) ;
while ( ! F_115 ( V_20 ) || ! F_116 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_117 ( char * V_1 )
{
F_3 ( & V_1 , & V_175 ) ;
return 0 ;
}
int F_118 ( void )
{
unsigned long V_112 [ 16 ] ;
F_58 () ;
F_111 ( F_57 () , false ) ;
F_119 () ;
F_28 ( V_112 , 0 , 15 ) ;
V_112 [ 0 ] &= ~ 0x0000ee70UL ;
V_112 [ 6 ] &= ~ 0xff000000UL ;
V_112 [ 14 ] &= ~ 0x1f000000UL ;
F_70 ( V_112 , 0 , 15 ) ;
F_120 ( V_176 ) ;
return 0 ;
}
void F_121 ( unsigned int V_20 )
{
struct V_9 * V_9 ;
V_9 = V_21 + V_20 ;
while ( ! F_9 ( V_9 ) )
F_6 () ;
F_22 ( V_9 ) ;
F_122 ( & V_48 . V_49 . V_51 ) ;
F_51 ( V_20 , F_26 ( & V_48 ) ) ;
if ( V_47 )
F_51 ( V_20 , & V_48 . V_49 . V_50 ) ;
}
void T_8 F_123 ( void )
{
F_124 () ;
F_7 ( V_21 + F_57 () , V_85 , 0 ) ;
for (; ; ) ;
}
void T_1 F_125 ( void )
{
unsigned int V_177 , V_178 , V_20 ;
V_178 = F_126 ( V_134 . V_86 , V_134 . V_165 ) + 1 ;
V_178 = F_127 ( V_2 , V_178 ) ;
V_178 = V_134 . V_179 * V_178 ? : V_156 ;
V_177 = V_175 ? : V_156 ;
V_177 = F_127 ( V_177 , V_178 ) ;
for ( V_20 = 0 ; V_20 < V_177 && V_20 < V_156 ; V_20 ++ )
F_128 ( V_20 , true ) ;
}
void T_1 F_129 ( unsigned int V_180 )
{
if ( F_130 ( V_181 , F_64 ) )
F_80 ( L_7 ) ;
if ( F_130 ( V_182 , F_64 ) )
F_80 ( L_8 ) ;
F_98 () ;
}
void T_1 F_131 ( void )
{
struct V_9 * V_9 = V_21 ;
V_9 -> V_159 = V_161 ;
V_9 -> V_11 = F_36 () ;
V_9 -> V_30 = (struct V_28 * ) ( unsigned long ) F_75 () ;
V_38 . V_52 = V_53 [ 0 ] ;
F_88 ( 0 , V_162 ) ;
F_95 ( 0 , true ) ;
F_111 ( 0 , true ) ;
}
void T_1 F_132 ( unsigned int V_180 )
{
}
void T_1 F_133 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_18 ( 0 ) ;
}
int F_134 ( unsigned int V_183 )
{
return 0 ;
}
static T_9 F_135 ( struct V_184 * V_185 ,
struct V_186 * V_187 , char * V_188 )
{
T_9 V_140 ;
F_136 ( & V_189 ) ;
V_140 = sprintf ( V_188 , L_9 , V_21 [ V_185 -> V_190 ] . V_159 ) ;
F_137 ( & V_189 ) ;
return V_140 ;
}
static T_9 F_138 ( struct V_184 * V_185 ,
struct V_186 * V_187 ,
const char * V_188 , T_10 V_140 )
{
struct V_9 * V_9 ;
int V_20 , V_141 , V_173 , V_152 ;
char V_191 ;
if ( sscanf ( V_188 , L_10 , & V_141 , & V_191 ) != 1 )
return - V_192 ;
if ( V_141 != 0 && V_141 != 1 )
return - V_192 ;
F_100 () ;
F_136 ( & V_189 ) ;
V_173 = - V_193 ;
V_20 = V_185 -> V_190 ;
V_20 -= V_20 % ( V_88 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ )
if ( F_115 ( V_20 + V_152 ) )
goto V_35;
V_9 = V_21 + V_20 ;
V_173 = 0 ;
switch ( V_141 ) {
case 0 :
if ( V_9 -> V_159 != V_161 )
break;
V_173 = F_139 ( V_9 -> V_11 >> V_89 ) ;
if ( V_173 )
break;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_20 + V_152 >= V_156 || ! F_140 ( V_20 + V_152 ) )
continue;
V_9 [ V_152 ] . V_159 = V_160 ;
F_88 ( V_20 + V_152 ,
V_162 ) ;
}
F_141 () ;
break;
case 1 :
if ( V_9 -> V_159 != V_160 )
break;
V_173 = F_142 ( V_9 -> V_11 >> V_89 ) ;
if ( V_173 )
break;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_20 + V_152 >= V_156 || ! F_140 ( V_20 + V_152 ) )
continue;
V_9 [ V_152 ] . V_159 = V_161 ;
F_88 ( V_20 + V_152 ,
V_162 ) ;
}
F_141 () ;
break;
default:
break;
}
V_35:
F_137 ( & V_189 ) ;
F_101 () ;
return V_173 ? V_173 : V_140 ;
}
static T_9 F_143 ( struct V_184 * V_185 ,
struct V_186 * V_187 , char * V_188 )
{
return sprintf ( V_188 , L_9 , V_21 [ V_185 -> V_190 ] . V_11 ) ;
}
static int F_144 ( struct V_194 * V_195 , unsigned long V_196 ,
void * V_197 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_197 ;
struct V_184 * V_1 = & F_145 ( V_198 , V_20 ) -> V_185 ;
int V_199 = 0 ;
switch ( V_196 & ~ V_200 ) {
case V_201 :
V_199 = F_146 ( & V_1 -> V_202 , & V_203 ) ;
break;
case V_204 :
F_147 ( & V_1 -> V_202 , & V_203 ) ;
break;
}
return F_148 ( V_199 ) ;
}
static int F_96 ( int V_20 )
{
struct V_184 * V_1 ;
struct V_20 * V_205 ;
int V_173 ;
V_205 = F_91 ( sizeof( * V_205 ) , V_31 ) ;
if ( ! V_205 )
return - V_46 ;
F_145 ( V_198 , V_20 ) = V_205 ;
V_1 = & V_205 -> V_185 ;
V_205 -> V_206 = 1 ;
V_173 = F_149 ( V_205 , V_20 ) ;
if ( V_173 )
goto V_35;
V_173 = F_146 ( & V_1 -> V_202 , & V_207 ) ;
if ( V_173 )
goto V_208;
if ( F_115 ( V_20 ) ) {
V_173 = F_146 ( & V_1 -> V_202 , & V_203 ) ;
if ( V_173 )
goto V_209;
}
V_173 = F_150 ( V_205 ) ;
if ( V_173 )
goto V_210;
return 0 ;
V_210:
if ( F_115 ( V_20 ) )
F_147 ( & V_1 -> V_202 , & V_203 ) ;
V_209:
F_147 ( & V_1 -> V_202 , & V_207 ) ;
V_208:
#ifdef F_151
F_152 ( V_205 ) ;
#endif
V_35:
return V_173 ;
}
int T_11 F_153 ( void )
{
struct V_143 * V_109 ;
int V_151 ;
V_109 = F_90 () ;
if ( ! V_109 )
return - V_46 ;
F_100 () ;
F_136 ( & V_189 ) ;
V_151 = F_93 ( V_109 , 1 ) ;
F_137 ( & V_189 ) ;
F_101 () ;
F_102 ( V_109 ) ;
if ( V_151 )
F_154 () ;
return 0 ;
}
static T_9 T_11 F_155 ( struct V_184 * V_185 ,
struct V_186 * V_187 ,
const char * V_188 ,
T_10 V_140 )
{
int V_173 ;
V_173 = F_153 () ;
return V_173 ? V_173 : V_140 ;
}
static int T_1 F_156 ( void )
{
int V_20 , V_173 = 0 ;
#ifdef F_151
V_173 = F_157 ( V_211 . V_212 , & V_213 ) ;
if ( V_173 )
return V_173 ;
#endif
F_158 () ;
F_44 (cpu) {
V_173 = F_96 ( V_20 ) ;
if ( V_173 )
goto V_35;
}
F_159 ( F_144 , 0 ) ;
V_35:
F_160 () ;
return V_173 ;
}
