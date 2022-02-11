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
V_30 -> V_63 = ( unsigned long ) F_31 ( V_62 )
+ V_64 - V_65 - sizeof( struct V_66 ) ;
V_30 -> V_67 = ( unsigned long ) V_62 ;
V_30 -> V_68 = V_69 ;
V_30 -> V_70 = V_62 -> V_71 ;
V_30 -> V_54 = V_62 -> V_72 . V_54 ;
V_30 -> V_55 = V_62 -> V_72 . V_55 ;
V_30 -> V_56 = 0 ;
}
static void F_32 ( struct V_8 * V_8 , void (* F_33)( void * ) , void * V_73 )
{
struct V_29 * V_30 = V_8 -> V_29 ;
V_30 -> V_74 = V_30 -> V_63 ;
V_30 -> V_75 = ( unsigned long ) F_33 ;
V_30 -> V_76 = ( unsigned long ) V_73 ;
V_30 -> V_77 = - 1UL ;
F_7 ( V_8 , V_78 , 0 ) ;
}
static void F_34 ( struct V_8 * V_8 , void (* F_33)( void * ) ,
void * V_73 , unsigned long V_79 )
{
struct V_29 * V_30 = V_44 [ V_8 - V_21 ] ;
unsigned long V_80 = F_35 () ;
F_36 ( V_81 ) ;
if ( V_8 -> V_10 == V_80 )
F_33 ( V_73 ) ;
F_7 ( V_8 , V_82 , 0 ) ;
F_37 ( V_30 -> V_74 , V_79 ) ;
F_37 ( V_30 -> V_75 , ( unsigned long ) F_33 ) ;
F_37 ( V_30 -> V_76 , ( unsigned long ) V_73 ) ;
F_37 ( V_30 -> V_77 , V_80 ) ;
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
static int F_38 ( unsigned int V_83 )
{
int V_6 ;
if ( V_84 == V_83 )
return 0 ;
V_6 = F_5 ( 0 , V_85 , V_83 , NULL ) ;
if ( V_6 == 0 ) {
V_84 = V_83 ;
V_86 = 0 ;
while ( V_84 >= ( 1U << V_86 ) )
V_86 ++ ;
V_21 [ 0 ] . V_10 = F_35 () ;
}
return V_6 ;
}
void F_39 ( void (* F_33)( void * ) , void * V_73 )
{
struct V_8 * V_8 ;
V_8 = F_11 ( V_87 , F_35 () ) ;
if ( ! V_8 )
V_8 = V_21 + F_40 ( V_87 ) ;
F_34 ( V_8 , F_33 , V_73 , ( unsigned long ) V_74 ) ;
}
void F_41 ( void (* F_33)( void * ) , void * V_73 )
{
F_34 ( & V_21 [ 0 ] , F_33 , V_73 ,
V_21 -> V_29 -> V_28 -
V_37 + V_88 ) ;
}
int F_42 ( T_2 V_10 )
{
int V_20 ;
F_43 (cpu)
if ( V_21 [ V_20 ] . V_10 == V_10 )
return V_20 ;
return - 1 ;
}
bool F_44 ( int V_20 )
{
if ( F_45 ( V_89 , V_20 ) )
return false ;
if ( F_10 ( V_21 + V_20 ) )
return false ;
return true ;
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
F_36 ( V_81 | V_96 ) ;
F_54 () ;
F_55 () ;
F_56 ( & V_18 , V_87 ) ;
F_51 ( F_57 () , & V_18 ) ;
if ( V_97 )
F_48 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_7 ( V_8 , V_82 , 0 ) ;
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
V_125 = F_82 ( V_88 , V_88 , 1UL << 31 ) ;
F_38 ( V_135 . V_136 ) ;
V_130 = F_35 () ;
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
F_85 ( V_125 , V_88 ) ;
F_86 () ;
F_38 ( 0 ) ;
}
void F_87 ( int V_20 , int V_139 )
{
V_21 [ V_20 ] . V_140 = V_139 ;
}
int F_88 ( int V_20 )
{
return V_21 [ V_20 ] . V_140 ;
}
static void T_8 F_89 ( struct V_141 * V_107 , int V_142 )
{
static int V_143 ;
int V_10 ;
if ( V_143 || F_90 ( V_107 , V_142 ) ) {
V_143 = 1 ;
for ( V_10 = 0 ;
V_10 < ( V_137 << V_86 ) ;
V_10 += ( 1U << V_86 ) ) {
if ( F_4 ( V_10 , V_13 , 0 ) ==
V_138 )
continue;
V_107 -> V_144 [ V_107 -> V_145 ] . V_146 =
V_10 >> V_86 ;
V_107 -> V_145 ++ ;
}
V_107 -> V_147 = V_107 -> V_145 ;
}
}
static int F_91 ( struct V_141 * V_107 , int V_148 )
{
struct V_8 * V_8 ;
T_5 V_149 ;
int V_20 , V_150 , V_151 , V_152 ;
T_2 V_10 ;
V_150 = 0 ;
F_92 ( & V_149 , V_153 , V_154 ) ;
V_20 = F_40 ( & V_149 ) ;
for ( V_151 = 0 ; ( V_151 < V_107 -> V_147 ) && ( V_20 < V_155 ) ; V_151 ++ ) {
if ( V_135 . V_156 && V_107 -> V_144 [ V_151 ] . type != V_157 )
continue;
V_10 = V_107 -> V_144 [ V_151 ] . V_146 << V_86 ;
for ( V_152 = 0 ; V_152 <= V_84 ; V_152 ++ ) {
if ( F_11 ( V_154 , V_10 + V_152 ) )
continue;
V_8 = V_21 + V_20 ;
V_8 -> V_10 = V_10 + V_152 ;
V_8 -> V_158 =
( V_20 >= V_107 -> V_145 * ( V_84 + 1 ) ) ?
V_159 : V_160 ;
F_87 ( V_20 , V_161 ) ;
F_93 ( V_20 , true ) ;
if ( V_148 && F_94 ( V_20 ) != 0 )
F_93 ( V_20 , false ) ;
else
V_150 ++ ;
V_20 = F_95 ( V_20 , & V_149 ) ;
if ( V_20 >= V_155 )
break;
}
}
return V_150 ;
}
void T_1 F_96 ( void )
{
unsigned int V_20 , V_83 , V_162 , V_163 ;
struct V_141 * V_107 ;
T_2 V_10 ;
V_107 = F_97 ( sizeof( * V_107 ) , 8 ) ;
F_89 ( V_107 , 1 ) ;
if ( V_135 . V_156 ) {
V_10 = F_35 () ;
for ( V_20 = 0 ; V_20 < V_107 -> V_147 ; V_20 ++ )
if ( V_107 -> V_144 [ V_20 ] . V_146 == V_10 ) {
V_157 = V_107 -> V_144 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_107 -> V_147 )
F_84 ( L_2 ) ;
}
V_83 = V_157 ? V_135 . V_83 : V_135 . V_164 ;
V_83 = ( V_83 < V_2 ) ? V_83 : V_2 - 1 ;
F_38 ( V_83 ) ;
V_162 = V_163 = 0 ;
for ( V_20 = 0 ; V_20 < V_107 -> V_147 ; V_20 ++ ) {
if ( V_135 . V_156 &&
V_107 -> V_144 [ V_20 ] . type != V_157 )
continue;
if ( V_20 < V_107 -> V_145 )
V_162 += V_84 + 1 ;
else
V_163 += V_84 + 1 ;
}
F_98 ( L_3 , V_162 , V_163 ) ;
F_99 () ;
F_91 ( V_107 , 0 ) ;
F_100 () ;
F_101 ( ( unsigned long ) V_107 , sizeof( * V_107 ) ) ;
}
static void F_102 ( void * V_165 )
{
V_38 . V_166 = F_49 () ;
V_38 . V_74 = ( unsigned long ) V_74 ;
V_38 . V_75 = ( unsigned long ) V_167 ;
V_38 . V_76 = 0 ;
V_38 . V_77 = - 1UL ;
F_103 ( V_38 . V_58 ) ;
F_70 ( V_38 . V_57 , 0 , 15 ) ;
F_36 ( V_81 | V_96 ) ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 ( F_57 () ) ;
F_110 ( F_57 () , true ) ;
F_65 ( V_168 ) ;
F_111 () ;
F_112 ( V_169 ) ;
}
int F_113 ( unsigned int V_20 , struct V_61 * V_170 )
{
struct V_8 * V_8 ;
int V_171 , V_151 , V_172 ;
V_8 = V_21 + V_20 ;
if ( V_8 -> V_158 != V_160 )
return - V_120 ;
V_171 = F_114 ( V_20 ) ;
for ( V_151 = 0 ; V_151 <= V_84 ; V_151 ++ ) {
if ( V_171 + V_151 < V_155 )
if ( F_115 ( V_171 + V_151 ) )
break;
}
if ( V_151 > V_84 &&
F_7 ( V_21 + V_171 , V_173 , 0 ) !=
V_119 )
return - V_120 ;
V_172 = F_16 ( V_8 , V_20 ) ;
if ( V_172 )
return V_172 ;
F_25 ( V_8 , V_20 ) ;
F_30 ( V_8 , V_170 ) ;
F_32 ( V_8 , F_102 , NULL ) ;
while ( ! F_115 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_116 ( char * V_1 )
{
F_3 ( & V_1 , & V_174 ) ;
return 0 ;
}
int F_117 ( void )
{
unsigned long V_110 [ 16 ] ;
F_58 () ;
F_110 ( F_57 () , false ) ;
F_118 () ;
F_28 ( V_110 , 0 , 15 ) ;
V_110 [ 0 ] &= ~ 0x0000ee70UL ;
V_110 [ 6 ] &= ~ 0xff000000UL ;
V_110 [ 14 ] &= ~ 0x1f000000UL ;
F_70 ( V_110 , 0 , 15 ) ;
F_119 ( V_175 ) ;
return 0 ;
}
void F_120 ( unsigned int V_20 )
{
struct V_8 * V_8 ;
V_8 = V_21 + V_20 ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
F_23 ( V_8 ) ;
F_51 ( V_20 , F_27 ( & V_47 ) ) ;
F_51 ( V_20 , & V_47 . V_48 . V_49 ) ;
}
void T_9 F_121 ( void )
{
F_122 () ;
F_7 ( V_21 + F_57 () , V_82 , 0 ) ;
for (; ; ) ;
}
void T_1 F_123 ( void )
{
unsigned int V_176 , V_177 , V_20 ;
V_177 = F_124 ( V_135 . V_83 , V_135 . V_164 ) + 1 ;
V_177 = F_125 ( V_2 , V_177 ) ;
V_177 = ( V_135 . V_178 * V_177 ) ? : V_155 ;
V_176 = V_174 ? : V_155 ;
V_176 = F_125 ( V_176 , V_177 ) ;
for ( V_20 = 0 ; V_20 < V_176 && V_20 < V_155 ; V_20 ++ )
F_126 ( V_20 , true ) ;
}
void T_1 F_127 ( unsigned int V_179 )
{
if ( F_128 ( V_180 , F_64 ) )
F_84 ( L_4 ) ;
if ( F_128 ( V_181 , F_64 ) )
F_84 ( L_5 ) ;
}
void T_1 F_129 ( void )
{
struct V_8 * V_8 = V_21 ;
V_8 -> V_158 = V_160 ;
V_8 -> V_10 = F_35 () ;
V_8 -> V_29 = (struct V_29 * ) ( unsigned long ) F_130 () ;
V_38 . V_50 = V_51 [ 0 ] ;
F_87 ( 0 , V_161 ) ;
F_93 ( 0 , true ) ;
F_110 ( 0 , true ) ;
}
void T_1 F_131 ( unsigned int V_179 )
{
}
void T_1 F_132 ( void )
{
V_38 . V_39 = 0 ;
V_38 . V_40 = F_19 ( 0 ) ;
}
int F_133 ( unsigned int V_182 )
{
return 0 ;
}
static T_10 F_134 ( struct V_183 * V_184 ,
struct V_185 * V_186 , char * V_187 )
{
T_10 V_188 ;
F_135 ( & V_189 ) ;
V_188 = sprintf ( V_187 , L_6 , V_21 [ V_184 -> V_190 ] . V_158 ) ;
F_136 ( & V_189 ) ;
return V_188 ;
}
static T_10 F_137 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
const char * V_187 , T_11 V_188 )
{
struct V_8 * V_8 ;
int V_20 , V_139 , V_172 , V_151 ;
char V_191 ;
if ( sscanf ( V_187 , L_7 , & V_139 , & V_191 ) != 1 )
return - V_192 ;
if ( V_139 != 0 && V_139 != 1 )
return - V_192 ;
F_99 () ;
F_135 ( & V_189 ) ;
V_172 = - V_193 ;
V_20 = V_184 -> V_190 ;
V_20 = F_114 ( V_20 ) ;
if ( V_20 == 0 )
goto V_35;
for ( V_151 = 0 ; V_151 <= V_84 ; V_151 ++ )
if ( F_115 ( V_20 + V_151 ) )
goto V_35;
V_8 = V_21 + V_20 ;
V_172 = 0 ;
switch ( V_139 ) {
case 0 :
if ( V_8 -> V_158 != V_160 )
break;
V_172 = F_138 ( V_8 -> V_10 >> V_86 ) ;
if ( V_172 )
break;
for ( V_151 = 0 ; V_151 <= V_84 ; V_151 ++ ) {
if ( V_20 + V_151 >= V_155 || ! F_139 ( V_20 + V_151 ) )
continue;
V_8 [ V_151 ] . V_158 = V_159 ;
F_87 ( V_20 + V_151 ,
V_161 ) ;
}
F_140 () ;
break;
case 1 :
if ( V_8 -> V_158 != V_159 )
break;
V_172 = F_141 ( V_8 -> V_10 >> V_86 ) ;
if ( V_172 )
break;
for ( V_151 = 0 ; V_151 <= V_84 ; V_151 ++ ) {
if ( V_20 + V_151 >= V_155 || ! F_139 ( V_20 + V_151 ) )
continue;
V_8 [ V_151 ] . V_158 = V_160 ;
F_87 ( V_20 + V_151 ,
V_161 ) ;
}
F_140 () ;
break;
default:
break;
}
V_35:
F_136 ( & V_189 ) ;
F_100 () ;
return V_172 ? V_172 : V_188 ;
}
static T_10 F_142 ( struct V_183 * V_184 ,
struct V_185 * V_186 , char * V_187 )
{
return sprintf ( V_187 , L_6 , V_21 [ V_184 -> V_190 ] . V_10 ) ;
}
static int F_143 ( unsigned int V_20 )
{
struct V_183 * V_1 = & F_144 ( V_194 , V_20 ) -> V_184 ;
return F_145 ( & V_1 -> V_195 , & V_196 ) ;
}
static int F_146 ( unsigned int V_20 )
{
struct V_183 * V_1 = & F_144 ( V_194 , V_20 ) -> V_184 ;
F_147 ( & V_1 -> V_195 , & V_196 ) ;
return 0 ;
}
static int F_94 ( int V_20 )
{
struct V_183 * V_1 ;
struct V_20 * V_197 ;
int V_172 ;
V_197 = F_148 ( sizeof( * V_197 ) , V_31 ) ;
if ( ! V_197 )
return - V_46 ;
F_144 ( V_194 , V_20 ) = V_197 ;
V_1 = & V_197 -> V_184 ;
V_197 -> V_198 = 1 ;
V_172 = F_149 ( V_197 , V_20 ) ;
if ( V_172 )
goto V_35;
V_172 = F_145 ( & V_1 -> V_195 , & V_199 ) ;
if ( V_172 )
goto V_200;
V_172 = F_150 ( V_197 ) ;
if ( V_172 )
goto V_201;
return 0 ;
V_201:
F_147 ( & V_1 -> V_195 , & V_199 ) ;
V_200:
#ifdef F_151
F_152 ( V_197 ) ;
#endif
V_35:
return V_172 ;
}
int T_8 F_153 ( void )
{
struct V_141 * V_107 ;
int V_150 ;
V_107 = F_148 ( sizeof( * V_107 ) , V_31 ) ;
if ( ! V_107 )
return - V_46 ;
F_89 ( V_107 , 0 ) ;
F_99 () ;
F_135 ( & V_189 ) ;
V_150 = F_91 ( V_107 , 1 ) ;
F_136 ( & V_189 ) ;
F_100 () ;
F_154 ( V_107 ) ;
if ( V_150 )
F_155 () ;
return 0 ;
}
static T_10 T_8 F_156 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
const char * V_187 ,
T_11 V_188 )
{
int V_172 ;
V_172 = F_153 () ;
return V_172 ? V_172 : V_188 ;
}
static int T_1 F_157 ( void )
{
int V_20 , V_172 = 0 ;
#ifdef F_151
V_172 = F_158 ( V_202 . V_203 , & V_204 ) ;
if ( V_172 )
return V_172 ;
#endif
F_43 (cpu) {
V_172 = F_94 ( V_20 ) ;
if ( V_172 )
goto V_35;
}
V_172 = F_159 ( V_205 , L_8 ,
F_143 , F_146 ) ;
V_35:
return V_172 ;
}
