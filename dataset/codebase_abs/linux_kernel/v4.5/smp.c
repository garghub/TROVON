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
static inline int F_4 ( T_2 V_3 , T_3 V_4 , unsigned long V_5 )
{
int V_6 ;
while ( 1 ) {
V_6 = F_5 ( V_3 , V_4 , V_5 , NULL ) ;
if ( V_6 != V_7 )
return V_6 ;
F_6 () ;
}
}
static int F_7 ( struct V_8 * V_8 , T_3 V_4 , T_4 V_5 )
{
int V_6 , V_9 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
V_6 = F_5 ( V_8 -> V_10 , V_4 , V_5 , NULL ) ;
if ( V_6 != V_7 )
break;
if ( V_9 >= 3 )
F_8 ( 10 ) ;
}
return V_6 ;
}
static inline int F_9 ( struct V_8 * V_8 )
{
T_4 V_11 ( V_12 ) ;
if ( F_5 ( V_8 -> V_10 , V_13 ,
0 , & V_12 ) != V_14 )
return 0 ;
return ! ! ( V_12 & ( V_15 | V_16 ) ) ;
}
static inline int F_10 ( struct V_8 * V_8 )
{
if ( F_5 ( V_8 -> V_10 , V_17 ,
0 , NULL ) != V_14 )
return 1 ;
return 0 ;
}
static struct V_8 * F_11 ( const struct V_18 * V_19 , T_2 V_10 )
{
int V_20 ;
F_12 (cpu, mask)
if ( V_21 [ V_20 ] . V_10 == V_10 )
return V_21 + V_20 ;
return NULL ;
}
static void F_13 ( struct V_8 * V_8 , int V_22 )
{
int V_4 ;
if ( F_14 ( V_22 , & V_8 -> V_23 ) )
return;
V_4 = F_10 ( V_8 ) ? V_24 : V_25 ;
V_8 -> V_26 = F_15 () ;
F_7 ( V_8 , V_4 , 0 ) ;
}
static int F_16 ( struct V_8 * V_8 , int V_20 )
{
unsigned long V_27 , V_28 ;
struct V_29 * V_30 ;
if ( V_8 != & V_21 [ 0 ] ) {
V_8 -> V_29 = (struct V_29 * )
F_17 ( V_31 | V_32 , V_33 ) ;
V_27 = F_17 ( V_31 , V_34 ) ;
V_28 = F_18 ( V_31 ) ;
if ( ! V_8 -> V_29 || ! V_28 || ! V_27 )
goto V_35;
} else {
V_27 = V_8 -> V_29 -> V_27 - V_36 ;
V_28 = V_8 -> V_29 -> V_28 - V_37 ;
}
V_30 = V_8 -> V_29 ;
memcpy ( V_30 , & V_38 , 512 ) ;
memset ( ( char * ) V_30 + 512 , 0 , sizeof( * V_30 ) - 512 ) ;
V_30 -> V_27 = V_27 + V_36 ;
V_30 -> V_28 = V_28 + V_37 ;
V_30 -> V_39 = V_20 ;
V_30 -> V_40 = F_19 ( V_20 ) ;
if ( V_41 )
V_30 -> V_42 =
( unsigned long ) & V_30 -> V_43 ;
if ( F_20 ( V_30 ) )
goto V_35;
V_44 [ V_20 ] = V_30 ;
F_7 ( V_8 , V_45 , ( T_4 ) ( unsigned long ) V_30 ) ;
return 0 ;
V_35:
if ( V_8 != & V_21 [ 0 ] ) {
F_21 ( V_28 ) ;
F_22 ( V_27 , V_34 ) ;
F_22 ( ( unsigned long ) V_8 -> V_29 , V_33 ) ;
}
return - V_46 ;
}
static void F_23 ( struct V_8 * V_8 )
{
F_7 ( V_8 , V_45 , 0 ) ;
V_44 [ V_8 - V_21 ] = NULL ;
F_24 ( V_8 -> V_29 ) ;
if ( V_8 == & V_21 [ 0 ] )
return;
F_21 ( V_8 -> V_29 -> V_28 - V_37 ) ;
F_22 ( V_8 -> V_29 -> V_27 - V_36 , V_34 ) ;
F_22 ( ( unsigned long ) V_8 -> V_29 , V_33 ) ;
}
static void F_25 ( struct V_8 * V_8 , int V_20 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
if ( V_47 )
F_26 ( V_20 , & V_48 . V_49 . V_50 ) ;
F_26 ( V_20 , F_27 ( & V_48 ) ) ;
F_28 ( & V_48 . V_49 . V_51 ) ;
V_30 -> V_39 = V_20 ;
V_30 -> V_40 = F_19 ( V_20 ) ;
V_30 -> V_52 = V_53 [ V_20 ] ;
V_30 -> V_54 = V_38 . V_54 ;
V_30 -> V_55 = V_38 . V_55 ;
V_30 -> V_56 = V_30 -> V_57 = V_30 -> V_58 = 0 ;
F_29 ( V_30 -> V_59 , 0 , 15 ) ;
F_30 ( ( unsigned int * ) V_30 -> V_60 ) ;
memcpy ( V_30 -> V_61 , V_38 . V_61 ,
V_62 / 8 ) ;
}
static void F_31 ( struct V_8 * V_8 , struct V_63 * V_64 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
struct V_65 * V_66 = F_32 ( V_64 ) ;
V_30 -> V_67 = ( unsigned long ) F_33 ( V_64 )
+ V_68 - V_69 - sizeof( struct V_70 ) ;
V_30 -> V_65 = ( unsigned long ) F_32 ( V_64 ) ;
V_30 -> V_71 = ( unsigned long ) V_64 ;
V_30 -> V_72 = V_73 ;
V_30 -> V_74 = V_64 -> V_75 ;
V_30 -> V_56 = V_66 -> V_56 ;
V_30 -> V_57 = V_66 -> V_57 ;
V_30 -> V_58 = 0 ;
}
static void F_34 ( struct V_8 * V_8 , void (* F_35)( void * ) , void * V_76 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
V_30 -> V_77 = V_30 -> V_67 ;
V_30 -> V_78 = ( unsigned long ) F_35 ;
V_30 -> V_79 = ( unsigned long ) V_76 ;
V_30 -> V_80 = - 1UL ;
F_7 ( V_8 , V_81 , 0 ) ;
}
static void F_36 ( struct V_8 * V_8 , void (* F_35)( void * ) ,
void * V_76 , unsigned long V_82 )
{
struct V_29 * V_30 = V_44 [ V_8 - V_21 ] ;
unsigned long V_83 = F_37 () ;
F_38 ( V_84 ) ;
if ( V_8 -> V_10 == V_83 )
F_35 ( V_76 ) ;
F_7 ( V_8 , V_85 , 0 ) ;
F_39 ( V_30 -> V_77 , V_82 ) ;
F_39 ( V_30 -> V_78 , ( unsigned long ) F_35 ) ;
F_39 ( V_30 -> V_79 , ( unsigned long ) V_76 ) ;
F_39 ( V_30 -> V_80 , V_83 ) ;
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
static int F_40 ( unsigned int V_86 )
{
register unsigned long T_5 V_87 ( L_1 ) = ( unsigned long ) V_86 ;
int V_6 ;
if ( V_88 == V_86 )
return 0 ;
asm volatile(
" sigp %1,0,%2 # sigp set multi-threading\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc) : "d" (reg1), "K" (SIGP_SET_MULTI_THREADING)
: "cc");
if ( V_6 == 0 ) {
V_88 = V_86 ;
V_89 = 0 ;
while ( V_88 >= ( 1U << V_89 ) )
V_89 ++ ;
V_21 [ 0 ] . V_10 = F_37 () ;
}
return V_6 ;
}
void F_41 ( void (* F_35)( void * ) , void * V_76 )
{
struct V_8 * V_8 ;
V_8 = F_11 ( V_90 , F_37 () ) ;
if ( ! V_8 )
V_8 = V_21 + F_42 ( V_90 ) ;
F_36 ( V_8 , F_35 , V_76 , ( unsigned long ) V_77 ) ;
}
void F_43 ( void (* F_35)( void * ) , void * V_76 )
{
F_36 ( & V_21 [ 0 ] , F_35 , V_76 ,
V_21 -> V_29 -> V_28 -
V_37 + V_91 ) ;
}
int F_44 ( T_2 V_10 )
{
int V_20 ;
F_45 (cpu)
if ( V_21 [ V_20 ] . V_10 == V_10 )
return V_20 ;
return - 1 ;
}
int F_46 ( int V_20 )
{
return F_10 ( V_21 + V_20 ) ;
}
void F_47 ( int V_20 )
{
if ( V_92 ) {
F_48 ( V_93 ) ;
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
} else if ( V_94 ) {
F_48 ( V_95 ) ;
asm volatile("diag 0,0,0x44");
}
}
static void F_49 ( T_6 * V_18 )
{
T_7 V_96 ;
int V_20 ;
V_96 = F_50 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_51 ( V_97 , & V_8 -> V_23 ) ;
while ( F_5 ( V_8 -> V_10 , V_25 ,
0 , NULL ) == V_7 &&
F_50 () < V_96 )
F_6 () ;
}
while ( F_50 () < V_96 ) {
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
F_38 ( V_84 | V_98 ) ;
F_55 () ;
F_56 () ;
F_57 ( & V_18 , V_90 ) ;
F_52 ( F_58 () , & V_18 ) ;
if ( V_99 )
F_49 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_7 ( V_8 , V_85 , 0 ) ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
}
}
static void F_59 ( void )
{
unsigned long V_100 ;
V_100 = F_60 ( & V_21 [ F_58 () ] . V_23 , 0 ) ;
if ( F_61 ( V_97 , & V_100 ) )
F_62 () ;
if ( F_61 ( V_101 , & V_100 ) )
F_63 () ;
if ( F_61 ( V_102 , & V_100 ) )
F_64 () ;
}
static void F_65 ( struct V_103 V_103 ,
unsigned int V_104 , unsigned long V_105 )
{
F_66 ( V_103 . V_106 == 0x1202 ? V_107 : V_108 ) ;
F_59 () ;
}
void F_67 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_102 ) ;
}
void F_68 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_102 ) ;
}
void F_69 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_101 ) ;
}
static void F_70 ( void * V_109 )
{
struct V_110 * V_111 = V_109 ;
unsigned long V_112 [ 16 ] ;
F_29 ( V_112 , 0 , 15 ) ;
V_112 [ V_111 -> V_113 ] = ( V_112 [ V_111 -> V_113 ] & V_111 -> V_114 ) | V_111 -> V_115 ;
F_71 ( V_112 , 0 , 15 ) ;
}
void F_72 ( int V_113 , int V_116 )
{
struct V_110 V_117 = { 1UL << V_116 , - 1UL , V_113 } ;
F_73 ( F_70 , & V_117 , 1 ) ;
}
void F_74 ( int V_113 , int V_116 )
{
struct V_110 V_117 = { 0 , ~ ( 1UL << V_116 ) , V_113 } ;
F_73 ( F_70 , & V_117 , 1 ) ;
}
int F_75 ( int V_20 )
{
struct V_8 * V_8 = V_21 + V_20 ;
unsigned long V_118 ;
V_118 = F_76 ( & V_8 -> V_29 -> V_119 ) ;
if ( F_4 ( V_8 -> V_10 , V_120 ,
V_118 ) != V_121 )
return - V_122 ;
if ( ! V_41 )
return 0 ;
V_118 = F_76 ( V_8 -> V_29 -> V_42 ) ;
if ( F_4 ( V_8 -> V_10 , V_123 ,
V_118 ) != V_121 )
return - V_122 ;
return 0 ;
}
static T_1 void F_77 ( struct V_124 * V_125 , T_2 V_3 ,
bool V_126 , unsigned long V_127 )
{
T_8 * V_128 = ( T_8 * ) V_127 ;
if ( V_126 )
V_128 = V_129 ;
else
F_4 ( V_3 , V_123 , V_127 ) ;
F_78 ( V_125 , V_128 ) ;
}
static T_1 void F_79 ( struct V_124 * V_125 , T_2 V_3 ,
bool V_126 , unsigned long V_127 )
{
void * V_130 = ( void * ) V_127 ;
if ( V_126 )
F_80 ( V_130 , ( void * ) V_131 , 512 ) ;
else
F_4 ( V_3 , V_120 , V_127 ) ;
F_81 ( V_125 , V_130 ) ;
}
void T_1 F_82 ( void )
{
int V_3 , V_132 , V_133 ;
struct V_124 * V_125 ;
unsigned long V_127 ;
bool V_126 ;
if ( ! ( V_134 || V_135 . type == V_136 ) )
return;
V_127 = F_83 ( V_91 , V_91 , 1UL << 31 ) ;
F_40 ( V_137 . V_138 ) ;
V_132 = F_37 () ;
V_133 = V_139 << V_137 . V_138 ;
for ( V_3 = 0 ; V_3 <= V_133 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 ) ==
V_140 )
continue;
V_126 = ( V_3 == V_132 ) ;
V_125 = F_84 ( V_126 ) ;
if ( ! V_125 )
F_85 ( L_2 ) ;
if ( V_41 )
F_77 ( V_125 , V_3 , V_126 , V_127 ) ;
if ( ! V_126 || V_134 )
F_79 ( V_125 , V_3 , V_126 , V_127 ) ;
}
F_86 ( V_127 , V_91 ) ;
F_87 () ;
F_40 ( 0 ) ;
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
int V_10 ;
V_109 = F_91 ( sizeof( * V_109 ) , V_31 ) ;
if ( V_109 && ( V_144 || F_92 ( V_109 ) ) ) {
V_144 = 1 ;
for ( V_10 = 0 ;
V_10 < ( V_139 << V_89 ) ;
V_10 += ( 1U << V_89 ) ) {
if ( F_4 ( V_10 , V_13 , 0 ) ==
V_140 )
continue;
V_109 -> V_145 [ V_109 -> V_146 ] . V_147 =
V_10 >> V_89 ;
V_109 -> V_146 ++ ;
}
V_109 -> V_148 = V_109 -> V_146 ;
}
return V_109 ;
}
static int F_93 ( struct V_143 * V_109 , int V_149 )
{
struct V_8 * V_8 ;
T_6 V_150 ;
int V_20 , V_151 , V_152 , V_153 ;
T_2 V_10 ;
V_151 = 0 ;
F_94 ( & V_150 , V_154 , V_155 ) ;
V_20 = F_42 ( & V_150 ) ;
for ( V_152 = 0 ; ( V_152 < V_109 -> V_148 ) && ( V_20 < V_156 ) ; V_152 ++ ) {
if ( V_137 . V_157 && V_109 -> V_145 [ V_152 ] . type != V_158 )
continue;
V_10 = V_109 -> V_145 [ V_152 ] . V_147 << V_89 ;
for ( V_153 = 0 ; V_153 <= V_88 ; V_153 ++ ) {
if ( F_11 ( V_155 , V_10 + V_153 ) )
continue;
V_8 = V_21 + V_20 ;
V_8 -> V_10 = V_10 + V_153 ;
V_8 -> V_159 =
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
T_2 V_10 ;
V_109 = F_90 () ;
if ( ! V_109 )
F_85 ( L_3 ) ;
if ( V_137 . V_157 ) {
V_10 = F_37 () ;
for ( V_20 = 0 ; V_20 < V_109 -> V_148 ; V_20 ++ )
if ( V_109 -> V_145 [ V_20 ] . V_147 == V_10 ) {
V_158 = V_109 -> V_145 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_109 -> V_148 )
F_85 ( L_4 ) ;
}
V_86 = V_158 ? V_137 . V_86 : V_137 . V_165 ;
V_86 = ( V_86 < V_2 ) ? V_86 : V_2 - 1 ;
F_40 ( V_86 ) ;
V_163 = V_164 = 0 ;
for ( V_20 = 0 ; V_20 < V_109 -> V_148 ; V_20 ++ ) {
if ( V_137 . V_157 &&
V_109 -> V_145 [ V_20 ] . type != V_158 )
continue;
if ( V_20 < V_109 -> V_146 )
V_163 += V_88 + 1 ;
else
V_164 += V_88 + 1 ;
}
F_99 ( L_5 , V_163 , V_164 ) ;
F_100 () ;
F_93 ( V_109 , 0 ) ;
F_101 () ;
F_102 ( V_109 ) ;
}
static void F_103 ( void * V_166 )
{
V_38 . V_167 = F_50 () ;
V_38 . V_77 = ( unsigned long ) V_77 ;
V_38 . V_78 = ( unsigned long ) V_168 ;
V_38 . V_79 = 0 ;
V_38 . V_80 = - 1UL ;
F_104 ( V_38 . V_60 ) ;
F_71 ( V_38 . V_59 , 0 , 15 ) ;
F_38 ( V_84 | V_98 ) ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_110 ( F_58 () ) ;
F_111 ( F_58 () , true ) ;
F_66 ( V_169 ) ;
F_112 () ;
F_113 ( V_170 ) ;
}
int F_114 ( unsigned int V_20 , struct V_63 * V_171 )
{
struct V_8 * V_8 ;
int V_172 , V_152 , V_173 ;
V_8 = V_21 + V_20 ;
if ( V_8 -> V_159 != V_161 )
return - V_122 ;
V_172 = V_20 - ( V_20 % ( V_88 + 1 ) ) ;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_172 + V_152 < V_156 )
if ( F_115 ( V_172 + V_152 ) )
break;
}
if ( V_152 > V_88 &&
F_7 ( V_21 + V_172 , V_174 , 0 ) !=
V_121 )
return - V_122 ;
V_173 = F_16 ( V_8 , V_20 ) ;
if ( V_173 )
return V_173 ;
F_25 ( V_8 , V_20 ) ;
F_31 ( V_8 , V_171 ) ;
F_34 ( V_8 , F_103 , NULL ) ;
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
F_59 () ;
F_111 ( F_58 () , false ) ;
F_119 () ;
F_29 ( V_112 , 0 , 15 ) ;
V_112 [ 0 ] &= ~ 0x0000ee70UL ;
V_112 [ 6 ] &= ~ 0xff000000UL ;
V_112 [ 14 ] &= ~ 0x1f000000UL ;
F_71 ( V_112 , 0 , 15 ) ;
F_120 ( V_176 ) ;
return 0 ;
}
void F_121 ( unsigned int V_20 )
{
struct V_8 * V_8 ;
V_8 = V_21 + V_20 ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
F_23 ( V_8 ) ;
F_122 ( & V_48 . V_49 . V_51 ) ;
F_52 ( V_20 , F_27 ( & V_48 ) ) ;
if ( V_47 )
F_52 ( V_20 , & V_48 . V_49 . V_50 ) ;
}
void T_9 F_123 ( void )
{
F_124 () ;
F_7 ( V_21 + F_58 () , V_85 , 0 ) ;
for (; ; ) ;
}
void T_1 F_125 ( void )
{
unsigned int V_177 , V_178 , V_20 ;
V_178 = F_126 ( V_137 . V_86 , V_137 . V_165 ) + 1 ;
V_178 = F_127 ( V_2 , V_178 ) ;
V_178 = V_137 . V_179 * V_178 ? : V_156 ;
V_177 = V_175 ? : V_156 ;
V_177 = F_127 ( V_177 , V_178 ) ;
for ( V_20 = 0 ; V_20 < V_177 && V_20 < V_156 ; V_20 ++ )
F_128 ( V_20 , true ) ;
}
void T_1 F_129 ( unsigned int V_180 )
{
if ( F_130 ( V_181 , F_65 ) )
F_85 ( L_6 ) ;
if ( F_130 ( V_182 , F_65 ) )
F_85 ( L_7 ) ;
F_98 () ;
}
void T_1 F_131 ( void )
{
struct V_8 * V_8 = V_21 ;
V_8 -> V_159 = V_161 ;
V_8 -> V_10 = F_37 () ;
V_8 -> V_29 = (struct V_29 * ) ( unsigned long ) F_132 () ;
V_38 . V_52 = V_53 [ 0 ] ;
F_88 ( 0 , V_162 ) ;
F_95 ( 0 , true ) ;
F_111 ( 0 , true ) ;
}
void T_1 F_133 ( unsigned int V_180 )
{
}
void T_1 F_134 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_19 ( 0 ) ;
}
int F_135 ( unsigned int V_183 )
{
return 0 ;
}
static T_10 F_136 ( struct V_184 * V_185 ,
struct V_186 * V_187 , char * V_188 )
{
T_10 V_189 ;
F_137 ( & V_190 ) ;
V_189 = sprintf ( V_188 , L_8 , V_21 [ V_185 -> V_191 ] . V_159 ) ;
F_138 ( & V_190 ) ;
return V_189 ;
}
static T_10 F_139 ( struct V_184 * V_185 ,
struct V_186 * V_187 ,
const char * V_188 , T_11 V_189 )
{
struct V_8 * V_8 ;
int V_20 , V_141 , V_173 , V_152 ;
char V_192 ;
if ( sscanf ( V_188 , L_9 , & V_141 , & V_192 ) != 1 )
return - V_193 ;
if ( V_141 != 0 && V_141 != 1 )
return - V_193 ;
F_100 () ;
F_137 ( & V_190 ) ;
V_173 = - V_194 ;
V_20 = V_185 -> V_191 ;
V_20 -= V_20 % ( V_88 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ )
if ( F_115 ( V_20 + V_152 ) )
goto V_35;
V_8 = V_21 + V_20 ;
V_173 = 0 ;
switch ( V_141 ) {
case 0 :
if ( V_8 -> V_159 != V_161 )
break;
V_173 = F_140 ( V_8 -> V_10 >> V_89 ) ;
if ( V_173 )
break;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_20 + V_152 >= V_156 || ! F_141 ( V_20 + V_152 ) )
continue;
V_8 [ V_152 ] . V_159 = V_160 ;
F_88 ( V_20 + V_152 ,
V_162 ) ;
}
F_142 () ;
break;
case 1 :
if ( V_8 -> V_159 != V_160 )
break;
V_173 = F_143 ( V_8 -> V_10 >> V_89 ) ;
if ( V_173 )
break;
for ( V_152 = 0 ; V_152 <= V_88 ; V_152 ++ ) {
if ( V_20 + V_152 >= V_156 || ! F_141 ( V_20 + V_152 ) )
continue;
V_8 [ V_152 ] . V_159 = V_161 ;
F_88 ( V_20 + V_152 ,
V_162 ) ;
}
F_142 () ;
break;
default:
break;
}
V_35:
F_138 ( & V_190 ) ;
F_101 () ;
return V_173 ? V_173 : V_189 ;
}
static T_10 F_144 ( struct V_184 * V_185 ,
struct V_186 * V_187 , char * V_188 )
{
return sprintf ( V_188 , L_8 , V_21 [ V_185 -> V_191 ] . V_10 ) ;
}
static int F_145 ( struct V_195 * V_196 , unsigned long V_197 ,
void * V_198 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_198 ;
struct V_184 * V_1 = & F_146 ( V_199 , V_20 ) -> V_185 ;
int V_200 = 0 ;
switch ( V_197 & ~ V_201 ) {
case V_202 :
V_200 = F_147 ( & V_1 -> V_203 , & V_204 ) ;
break;
case V_205 :
F_148 ( & V_1 -> V_203 , & V_204 ) ;
break;
}
return F_149 ( V_200 ) ;
}
static int F_96 ( int V_20 )
{
struct V_184 * V_1 ;
struct V_20 * V_206 ;
int V_173 ;
V_206 = F_91 ( sizeof( * V_206 ) , V_31 ) ;
if ( ! V_206 )
return - V_46 ;
F_146 ( V_199 , V_20 ) = V_206 ;
V_1 = & V_206 -> V_185 ;
V_206 -> V_207 = 1 ;
V_173 = F_150 ( V_206 , V_20 ) ;
if ( V_173 )
goto V_35;
V_173 = F_147 ( & V_1 -> V_203 , & V_208 ) ;
if ( V_173 )
goto V_209;
if ( F_115 ( V_20 ) ) {
V_173 = F_147 ( & V_1 -> V_203 , & V_204 ) ;
if ( V_173 )
goto V_210;
}
V_173 = F_151 ( V_206 ) ;
if ( V_173 )
goto V_211;
return 0 ;
V_211:
if ( F_115 ( V_20 ) )
F_148 ( & V_1 -> V_203 , & V_204 ) ;
V_210:
F_148 ( & V_1 -> V_203 , & V_208 ) ;
V_209:
#ifdef F_152
F_153 ( V_206 ) ;
#endif
V_35:
return V_173 ;
}
int T_12 F_154 ( void )
{
struct V_143 * V_109 ;
int V_151 ;
V_109 = F_90 () ;
if ( ! V_109 )
return - V_46 ;
F_100 () ;
F_137 ( & V_190 ) ;
V_151 = F_93 ( V_109 , 1 ) ;
F_138 ( & V_190 ) ;
F_101 () ;
F_102 ( V_109 ) ;
if ( V_151 )
F_155 () ;
return 0 ;
}
static T_10 T_12 F_156 ( struct V_184 * V_185 ,
struct V_186 * V_187 ,
const char * V_188 ,
T_11 V_189 )
{
int V_173 ;
V_173 = F_154 () ;
return V_173 ? V_173 : V_189 ;
}
static int T_1 F_157 ( void )
{
int V_20 , V_173 = 0 ;
#ifdef F_152
V_173 = F_158 ( V_212 . V_213 , & V_214 ) ;
if ( V_173 )
return V_173 ;
#endif
F_159 () ;
F_45 (cpu) {
V_173 = F_96 ( V_20 ) ;
if ( V_173 )
goto V_35;
}
F_160 ( F_145 , 0 ) ;
V_35:
F_161 () ;
return V_173 ;
}
