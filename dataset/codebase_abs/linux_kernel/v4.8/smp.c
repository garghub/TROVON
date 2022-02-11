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
F_26 ( V_20 , & V_47 . V_48 . V_49 ) ;
F_26 ( V_20 , F_27 ( & V_47 ) ) ;
V_30 -> V_39 = V_20 ;
V_30 -> V_40 = F_19 ( V_20 ) ;
V_30 -> V_50 = V_51 [ V_20 ] ;
V_30 -> V_52 = V_38 . V_52 ;
V_30 -> V_53 = V_38 . V_53 ;
V_30 -> V_54 = V_30 -> V_55 = V_30 -> V_56 = 0 ;
F_28 ( V_30 -> V_57 , 0 , 15 ) ;
F_29 ( ( unsigned int * ) V_30 -> V_58 ) ;
memcpy ( V_30 -> V_59 , V_38 . V_59 ,
V_60 / 8 ) ;
}
static void F_30 ( struct V_8 * V_8 , struct V_61 * V_62 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
struct V_63 * V_64 = F_31 ( V_62 ) ;
V_30 -> V_65 = ( unsigned long ) F_32 ( V_62 )
+ V_66 - V_67 - sizeof( struct V_68 ) ;
V_30 -> V_63 = ( unsigned long ) F_31 ( V_62 ) ;
V_30 -> V_69 = ( unsigned long ) V_62 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_72 = V_62 -> V_73 ;
V_30 -> V_54 = V_64 -> V_54 ;
V_30 -> V_55 = V_64 -> V_55 ;
V_30 -> V_56 = 0 ;
}
static void F_33 ( struct V_8 * V_8 , void (* F_34)( void * ) , void * V_74 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
V_30 -> V_75 = V_30 -> V_65 ;
V_30 -> V_76 = ( unsigned long ) F_34 ;
V_30 -> V_77 = ( unsigned long ) V_74 ;
V_30 -> V_78 = - 1UL ;
F_7 ( V_8 , V_79 , 0 ) ;
}
static void F_35 ( struct V_8 * V_8 , void (* F_34)( void * ) ,
void * V_74 , unsigned long V_80 )
{
struct V_29 * V_30 = V_44 [ V_8 - V_21 ] ;
unsigned long V_81 = F_36 () ;
F_37 ( V_82 ) ;
if ( V_8 -> V_10 == V_81 )
F_34 ( V_74 ) ;
F_7 ( V_8 , V_83 , 0 ) ;
F_38 ( V_30 -> V_75 , V_80 ) ;
F_38 ( V_30 -> V_76 , ( unsigned long ) F_34 ) ;
F_38 ( V_30 -> V_77 , ( unsigned long ) V_74 ) ;
F_38 ( V_30 -> V_78 , V_81 ) ;
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
static int F_39 ( unsigned int V_84 )
{
int V_6 ;
if ( V_85 == V_84 )
return 0 ;
V_6 = F_5 ( 0 , V_86 , V_84 , NULL ) ;
if ( V_6 == 0 ) {
V_85 = V_84 ;
V_87 = 0 ;
while ( V_85 >= ( 1U << V_87 ) )
V_87 ++ ;
V_21 [ 0 ] . V_10 = F_36 () ;
}
return V_6 ;
}
void F_40 ( void (* F_34)( void * ) , void * V_74 )
{
struct V_8 * V_8 ;
V_8 = F_11 ( V_88 , F_36 () ) ;
if ( ! V_8 )
V_8 = V_21 + F_41 ( V_88 ) ;
F_35 ( V_8 , F_34 , V_74 , ( unsigned long ) V_75 ) ;
}
void F_42 ( void (* F_34)( void * ) , void * V_74 )
{
F_35 ( & V_21 [ 0 ] , F_34 , V_74 ,
V_21 -> V_29 -> V_28 -
V_37 + V_89 ) ;
}
int F_43 ( T_2 V_10 )
{
int V_20 ;
F_44 (cpu)
if ( V_21 [ V_20 ] . V_10 == V_10 )
return V_20 ;
return - 1 ;
}
int F_45 ( int V_20 )
{
return F_10 ( V_21 + V_20 ) ;
}
void F_46 ( int V_20 )
{
if ( V_90 ) {
F_47 ( V_91 ) ;
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
} else if ( V_92 ) {
F_47 ( V_93 ) ;
asm volatile("diag 0,0,0x44");
}
}
static void F_48 ( T_5 * V_18 )
{
T_6 V_94 ;
int V_20 ;
V_94 = F_49 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_50 ( V_95 , & V_8 -> V_23 ) ;
while ( F_5 ( V_8 -> V_10 , V_25 ,
0 , NULL ) == V_7 &&
F_49 () < V_94 )
F_6 () ;
}
while ( F_49 () < V_94 ) {
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
T_5 V_18 ;
int V_20 ;
F_37 ( V_82 | V_96 ) ;
F_54 () ;
F_55 () ;
F_56 ( & V_18 , V_88 ) ;
F_51 ( F_57 () , & V_18 ) ;
if ( V_97 )
F_48 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_7 ( V_8 , V_83 , 0 ) ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
}
}
static void F_58 ( void )
{
unsigned long V_98 ;
V_98 = F_59 ( & V_21 [ F_57 () ] . V_23 , 0 ) ;
if ( F_60 ( V_95 , & V_98 ) )
F_61 () ;
if ( F_60 ( V_99 , & V_98 ) )
F_62 () ;
if ( F_60 ( V_100 , & V_98 ) )
F_63 () ;
}
static void F_64 ( struct V_101 V_101 ,
unsigned int V_102 , unsigned long V_103 )
{
F_65 ( V_101 . V_104 == 0x1202 ? V_105 : V_106 ) ;
F_58 () ;
}
void F_66 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_100 ) ;
}
void F_67 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_100 ) ;
}
void F_68 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_99 ) ;
}
static void F_69 ( void * V_107 )
{
struct V_108 * V_109 = V_107 ;
unsigned long V_110 [ 16 ] ;
F_28 ( V_110 , 0 , 15 ) ;
V_110 [ V_109 -> V_111 ] = ( V_110 [ V_109 -> V_111 ] & V_109 -> V_112 ) | V_109 -> V_113 ;
F_70 ( V_110 , 0 , 15 ) ;
}
void F_71 ( int V_111 , int V_114 )
{
struct V_108 V_115 = { 1UL << V_114 , - 1UL , V_111 } ;
F_72 ( F_69 , & V_115 , 1 ) ;
}
void F_73 ( int V_111 , int V_114 )
{
struct V_108 V_115 = { 0 , ~ ( 1UL << V_114 ) , V_111 } ;
F_72 ( F_69 , & V_115 , 1 ) ;
}
int F_74 ( int V_20 )
{
struct V_8 * V_8 = V_21 + V_20 ;
unsigned long V_116 ;
V_116 = F_75 ( & V_8 -> V_29 -> V_117 ) ;
if ( F_4 ( V_8 -> V_10 , V_118 ,
V_116 ) != V_119 )
return - V_120 ;
if ( ! V_41 )
return 0 ;
V_116 = F_75 ( V_8 -> V_29 -> V_42 ) ;
if ( F_4 ( V_8 -> V_10 , V_121 ,
V_116 ) != V_119 )
return - V_120 ;
return 0 ;
}
static T_1 void F_76 ( struct V_122 * V_123 , T_2 V_3 ,
bool V_124 , unsigned long V_125 )
{
T_7 * V_126 = ( T_7 * ) V_125 ;
if ( V_124 )
V_126 = V_127 ;
else
F_4 ( V_3 , V_121 , V_125 ) ;
F_77 ( V_123 , V_126 ) ;
}
static T_1 void F_78 ( struct V_122 * V_123 , T_2 V_3 ,
bool V_124 , unsigned long V_125 )
{
void * V_128 = ( void * ) V_125 ;
if ( V_124 )
F_79 ( V_128 , ( void * ) V_129 , 512 ) ;
else
F_4 ( V_3 , V_118 , V_125 ) ;
F_80 ( V_123 , V_128 ) ;
}
void T_1 F_81 ( void )
{
int V_3 , V_130 , V_131 ;
struct V_122 * V_123 ;
unsigned long V_125 ;
bool V_124 ;
if ( ! ( V_132 || V_133 . type == V_134 ) )
return;
V_125 = F_82 ( V_89 , V_89 , 1UL << 31 ) ;
F_39 ( V_135 . V_136 ) ;
V_130 = F_36 () ;
V_131 = V_137 << V_135 . V_136 ;
for ( V_3 = 0 ; V_3 <= V_131 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 ) ==
V_138 )
continue;
V_124 = ( V_3 == V_130 ) ;
V_123 = F_83 ( V_124 ) ;
if ( ! V_123 )
F_84 ( L_1 ) ;
if ( V_41 )
F_76 ( V_123 , V_3 , V_124 , V_125 ) ;
if ( ! V_124 || V_132 )
F_78 ( V_123 , V_3 , V_124 , V_125 ) ;
}
F_85 ( V_125 , V_89 ) ;
F_86 () ;
F_39 ( 0 ) ;
}
void F_87 ( int V_20 , int V_139 )
{
V_21 [ V_20 ] . V_140 = V_139 ;
}
int F_88 ( int V_20 )
{
return V_21 [ V_20 ] . V_140 ;
}
static struct V_141 * F_89 ( void )
{
static int V_142 ;
struct V_141 * V_107 ;
int V_10 ;
V_107 = F_90 ( sizeof( * V_107 ) , V_31 ) ;
if ( V_107 && ( V_142 || F_91 ( V_107 ) ) ) {
V_142 = 1 ;
for ( V_10 = 0 ;
V_10 < ( V_137 << V_87 ) ;
V_10 += ( 1U << V_87 ) ) {
if ( F_4 ( V_10 , V_13 , 0 ) ==
V_138 )
continue;
V_107 -> V_143 [ V_107 -> V_144 ] . V_145 =
V_10 >> V_87 ;
V_107 -> V_144 ++ ;
}
V_107 -> V_146 = V_107 -> V_144 ;
}
return V_107 ;
}
static int F_92 ( struct V_141 * V_107 , int V_147 )
{
struct V_8 * V_8 ;
T_5 V_148 ;
int V_20 , V_149 , V_150 , V_151 ;
T_2 V_10 ;
V_149 = 0 ;
F_93 ( & V_148 , V_152 , V_153 ) ;
V_20 = F_41 ( & V_148 ) ;
for ( V_150 = 0 ; ( V_150 < V_107 -> V_146 ) && ( V_20 < V_154 ) ; V_150 ++ ) {
if ( V_135 . V_155 && V_107 -> V_143 [ V_150 ] . type != V_156 )
continue;
V_10 = V_107 -> V_143 [ V_150 ] . V_145 << V_87 ;
for ( V_151 = 0 ; V_151 <= V_85 ; V_151 ++ ) {
if ( F_11 ( V_153 , V_10 + V_151 ) )
continue;
V_8 = V_21 + V_20 ;
V_8 -> V_10 = V_10 + V_151 ;
V_8 -> V_157 =
( V_20 >= V_107 -> V_144 * ( V_85 + 1 ) ) ?
V_158 : V_159 ;
F_87 ( V_20 , V_160 ) ;
F_94 ( V_20 , true ) ;
if ( V_147 && F_95 ( V_20 ) != 0 )
F_94 ( V_20 , false ) ;
else
V_149 ++ ;
V_20 = F_96 ( V_20 , & V_148 ) ;
if ( V_20 >= V_154 )
break;
}
}
return V_149 ;
}
static void T_1 F_97 ( void )
{
unsigned int V_20 , V_84 , V_161 , V_162 ;
struct V_141 * V_107 ;
T_2 V_10 ;
V_107 = F_89 () ;
if ( ! V_107 )
F_84 ( L_2 ) ;
if ( V_135 . V_155 ) {
V_10 = F_36 () ;
for ( V_20 = 0 ; V_20 < V_107 -> V_146 ; V_20 ++ )
if ( V_107 -> V_143 [ V_20 ] . V_145 == V_10 ) {
V_156 = V_107 -> V_143 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_107 -> V_146 )
F_84 ( L_3 ) ;
}
V_84 = V_156 ? V_135 . V_84 : V_135 . V_163 ;
V_84 = ( V_84 < V_2 ) ? V_84 : V_2 - 1 ;
F_39 ( V_84 ) ;
V_161 = V_162 = 0 ;
for ( V_20 = 0 ; V_20 < V_107 -> V_146 ; V_20 ++ ) {
if ( V_135 . V_155 &&
V_107 -> V_143 [ V_20 ] . type != V_156 )
continue;
if ( V_20 < V_107 -> V_144 )
V_161 += V_85 + 1 ;
else
V_162 += V_85 + 1 ;
}
F_98 ( L_4 , V_161 , V_162 ) ;
F_99 () ;
F_92 ( V_107 , 0 ) ;
F_100 () ;
F_101 ( V_107 ) ;
}
static void F_102 ( void * V_164 )
{
V_38 . V_165 = F_49 () ;
V_38 . V_75 = ( unsigned long ) V_75 ;
V_38 . V_76 = ( unsigned long ) V_166 ;
V_38 . V_77 = 0 ;
V_38 . V_78 = - 1UL ;
F_103 ( V_38 . V_58 ) ;
F_70 ( V_38 . V_57 , 0 , 15 ) ;
F_37 ( V_82 | V_96 ) ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 ( F_57 () ) ;
F_110 ( F_57 () , true ) ;
F_65 ( V_167 ) ;
F_111 () ;
F_112 ( V_168 ) ;
}
int F_113 ( unsigned int V_20 , struct V_61 * V_169 )
{
struct V_8 * V_8 ;
int V_170 , V_150 , V_171 ;
V_8 = V_21 + V_20 ;
if ( V_8 -> V_157 != V_159 )
return - V_120 ;
V_170 = V_20 - ( V_20 % ( V_85 + 1 ) ) ;
for ( V_150 = 0 ; V_150 <= V_85 ; V_150 ++ ) {
if ( V_170 + V_150 < V_154 )
if ( F_114 ( V_170 + V_150 ) )
break;
}
if ( V_150 > V_85 &&
F_7 ( V_21 + V_170 , V_172 , 0 ) !=
V_119 )
return - V_120 ;
V_171 = F_16 ( V_8 , V_20 ) ;
if ( V_171 )
return V_171 ;
F_25 ( V_8 , V_20 ) ;
F_30 ( V_8 , V_169 ) ;
F_33 ( V_8 , F_102 , NULL ) ;
while ( ! F_114 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_115 ( char * V_1 )
{
F_3 ( & V_1 , & V_173 ) ;
return 0 ;
}
int F_116 ( void )
{
unsigned long V_110 [ 16 ] ;
F_58 () ;
F_110 ( F_57 () , false ) ;
F_117 () ;
F_28 ( V_110 , 0 , 15 ) ;
V_110 [ 0 ] &= ~ 0x0000ee70UL ;
V_110 [ 6 ] &= ~ 0xff000000UL ;
V_110 [ 14 ] &= ~ 0x1f000000UL ;
F_70 ( V_110 , 0 , 15 ) ;
F_118 ( V_174 ) ;
return 0 ;
}
void F_119 ( unsigned int V_20 )
{
struct V_8 * V_8 ;
V_8 = V_21 + V_20 ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
F_23 ( V_8 ) ;
F_51 ( V_20 , F_27 ( & V_47 ) ) ;
F_51 ( V_20 , & V_47 . V_48 . V_49 ) ;
}
void T_8 F_120 ( void )
{
F_121 () ;
F_7 ( V_21 + F_57 () , V_83 , 0 ) ;
for (; ; ) ;
}
void T_1 F_122 ( void )
{
unsigned int V_175 , V_176 , V_20 ;
V_176 = F_123 ( V_135 . V_84 , V_135 . V_163 ) + 1 ;
V_176 = F_124 ( V_2 , V_176 ) ;
V_176 = ( V_135 . V_177 * V_176 ) ? : V_154 ;
V_175 = V_173 ? : V_154 ;
V_175 = F_124 ( V_175 , V_176 ) ;
for ( V_20 = 0 ; V_20 < V_175 && V_20 < V_154 ; V_20 ++ )
F_125 ( V_20 , true ) ;
}
void T_1 F_126 ( unsigned int V_178 )
{
if ( F_127 ( V_179 , F_64 ) )
F_84 ( L_5 ) ;
if ( F_127 ( V_180 , F_64 ) )
F_84 ( L_6 ) ;
F_97 () ;
}
void T_1 F_128 ( void )
{
struct V_8 * V_8 = V_21 ;
V_8 -> V_157 = V_159 ;
V_8 -> V_10 = F_36 () ;
V_8 -> V_29 = (struct V_29 * ) ( unsigned long ) F_129 () ;
V_38 . V_50 = V_51 [ 0 ] ;
F_87 ( 0 , V_160 ) ;
F_94 ( 0 , true ) ;
F_110 ( 0 , true ) ;
}
void T_1 F_130 ( unsigned int V_178 )
{
}
void T_1 F_131 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_19 ( 0 ) ;
}
int F_132 ( unsigned int V_181 )
{
return 0 ;
}
static T_9 F_133 ( struct V_182 * V_183 ,
struct V_184 * V_185 , char * V_186 )
{
T_9 V_187 ;
F_134 ( & V_188 ) ;
V_187 = sprintf ( V_186 , L_7 , V_21 [ V_183 -> V_189 ] . V_157 ) ;
F_135 ( & V_188 ) ;
return V_187 ;
}
static T_9 F_136 ( struct V_182 * V_183 ,
struct V_184 * V_185 ,
const char * V_186 , T_10 V_187 )
{
struct V_8 * V_8 ;
int V_20 , V_139 , V_171 , V_150 ;
char V_190 ;
if ( sscanf ( V_186 , L_8 , & V_139 , & V_190 ) != 1 )
return - V_191 ;
if ( V_139 != 0 && V_139 != 1 )
return - V_191 ;
F_99 () ;
F_134 ( & V_188 ) ;
V_171 = - V_192 ;
V_20 = V_183 -> V_189 ;
V_20 -= V_20 % ( V_85 + 1 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_150 = 0 ; V_150 <= V_85 ; V_150 ++ )
if ( F_114 ( V_20 + V_150 ) )
goto V_35;
V_8 = V_21 + V_20 ;
V_171 = 0 ;
switch ( V_139 ) {
case 0 :
if ( V_8 -> V_157 != V_159 )
break;
V_171 = F_137 ( V_8 -> V_10 >> V_87 ) ;
if ( V_171 )
break;
for ( V_150 = 0 ; V_150 <= V_85 ; V_150 ++ ) {
if ( V_20 + V_150 >= V_154 || ! F_138 ( V_20 + V_150 ) )
continue;
V_8 [ V_150 ] . V_157 = V_158 ;
F_87 ( V_20 + V_150 ,
V_160 ) ;
}
F_139 () ;
break;
case 1 :
if ( V_8 -> V_157 != V_158 )
break;
V_171 = F_140 ( V_8 -> V_10 >> V_87 ) ;
if ( V_171 )
break;
for ( V_150 = 0 ; V_150 <= V_85 ; V_150 ++ ) {
if ( V_20 + V_150 >= V_154 || ! F_138 ( V_20 + V_150 ) )
continue;
V_8 [ V_150 ] . V_157 = V_159 ;
F_87 ( V_20 + V_150 ,
V_160 ) ;
}
F_139 () ;
break;
default:
break;
}
V_35:
F_135 ( & V_188 ) ;
F_100 () ;
return V_171 ? V_171 : V_187 ;
}
static T_9 F_141 ( struct V_182 * V_183 ,
struct V_184 * V_185 , char * V_186 )
{
return sprintf ( V_186 , L_7 , V_21 [ V_183 -> V_189 ] . V_10 ) ;
}
static int F_142 ( struct V_193 * V_194 , unsigned long V_195 ,
void * V_196 )
{
unsigned int V_20 = ( unsigned int ) ( long ) V_196 ;
struct V_182 * V_1 = & F_143 ( V_197 , V_20 ) -> V_183 ;
int V_198 = 0 ;
switch ( V_195 & ~ V_199 ) {
case V_200 :
V_198 = F_144 ( & V_1 -> V_201 , & V_202 ) ;
break;
case V_203 :
F_145 ( & V_1 -> V_201 , & V_202 ) ;
break;
}
return F_146 ( V_198 ) ;
}
static int F_95 ( int V_20 )
{
struct V_182 * V_1 ;
struct V_20 * V_204 ;
int V_171 ;
V_204 = F_90 ( sizeof( * V_204 ) , V_31 ) ;
if ( ! V_204 )
return - V_46 ;
F_143 ( V_197 , V_20 ) = V_204 ;
V_1 = & V_204 -> V_183 ;
V_204 -> V_205 = 1 ;
V_171 = F_147 ( V_204 , V_20 ) ;
if ( V_171 )
goto V_35;
V_171 = F_144 ( & V_1 -> V_201 , & V_206 ) ;
if ( V_171 )
goto V_207;
if ( F_114 ( V_20 ) ) {
V_171 = F_144 ( & V_1 -> V_201 , & V_202 ) ;
if ( V_171 )
goto V_208;
}
V_171 = F_148 ( V_204 ) ;
if ( V_171 )
goto V_209;
return 0 ;
V_209:
if ( F_114 ( V_20 ) )
F_145 ( & V_1 -> V_201 , & V_202 ) ;
V_208:
F_145 ( & V_1 -> V_201 , & V_206 ) ;
V_207:
#ifdef F_149
F_150 ( V_204 ) ;
#endif
V_35:
return V_171 ;
}
int T_11 F_151 ( void )
{
struct V_141 * V_107 ;
int V_149 ;
V_107 = F_89 () ;
if ( ! V_107 )
return - V_46 ;
F_99 () ;
F_134 ( & V_188 ) ;
V_149 = F_92 ( V_107 , 1 ) ;
F_135 ( & V_188 ) ;
F_100 () ;
F_101 ( V_107 ) ;
if ( V_149 )
F_152 () ;
return 0 ;
}
static T_9 T_11 F_153 ( struct V_182 * V_183 ,
struct V_184 * V_185 ,
const char * V_186 ,
T_10 V_187 )
{
int V_171 ;
V_171 = F_151 () ;
return V_171 ? V_171 : V_187 ;
}
static int T_1 F_154 ( void )
{
int V_20 , V_171 = 0 ;
#ifdef F_149
V_171 = F_155 ( V_210 . V_211 , & V_212 ) ;
if ( V_171 )
return V_171 ;
#endif
F_156 () ;
F_44 (cpu) {
V_171 = F_95 ( V_20 ) ;
if ( V_171 )
goto V_35;
}
F_157 ( F_142 , 0 ) ;
V_35:
F_158 () ;
return V_171 ;
}
