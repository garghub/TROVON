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
unsigned long V_29 , V_30 ;
struct V_31 * V_32 ;
V_29 = V_30 = 0 ;
if ( V_8 != & V_21 [ 0 ] ) {
V_8 -> V_31 = (struct V_31 * )
F_17 ( V_33 | V_34 , V_35 ) ;
V_27 = F_17 ( V_33 , V_36 ) ;
V_28 = F_18 ( V_33 ) ;
if ( ! V_8 -> V_31 || ! V_28 || ! V_27 )
goto V_37;
if ( V_38 || V_39 ) {
V_29 = ( unsigned long )
F_19 ( V_40 , V_33 ) ;
if ( ! V_29 )
goto V_37;
V_30 = V_39 ? 11 : 0 ;
}
} else {
V_27 = V_8 -> V_31 -> V_27 - V_41 ;
V_28 = V_8 -> V_31 -> V_28 - V_42 ;
V_29 = V_8 -> V_31 -> V_43 & V_44 ;
V_30 = V_8 -> V_31 -> V_43 & V_45 ;
}
V_32 = V_8 -> V_31 ;
memcpy ( V_32 , & V_46 , 512 ) ;
memset ( ( char * ) V_32 + 512 , 0 , sizeof( * V_32 ) - 512 ) ;
V_32 -> V_27 = V_27 + V_41 ;
V_32 -> V_28 = V_28 + V_42 ;
V_32 -> V_43 = V_29 | V_30 ;
V_32 -> V_47 = V_20 ;
V_32 -> V_48 = F_20 ( V_20 ) ;
if ( F_21 ( V_32 ) )
goto V_37;
V_49 [ V_20 ] = V_32 ;
F_7 ( V_8 , V_50 , ( T_4 ) ( unsigned long ) V_32 ) ;
return 0 ;
V_37:
if ( V_8 != & V_21 [ 0 ] ) {
if ( V_29 )
F_22 ( V_40 ,
( void * ) V_29 ) ;
F_23 ( V_28 ) ;
F_24 ( V_27 , V_36 ) ;
F_24 ( ( unsigned long ) V_8 -> V_31 , V_35 ) ;
}
return - V_51 ;
}
static void F_25 ( struct V_8 * V_8 )
{
unsigned long V_29 ;
F_7 ( V_8 , V_50 , 0 ) ;
V_49 [ V_8 - V_21 ] = NULL ;
F_26 ( V_8 -> V_31 ) ;
if ( V_8 == & V_21 [ 0 ] )
return;
if ( V_38 || V_39 ) {
V_29 = V_8 -> V_31 -> V_43 & V_44 ;
F_22 ( V_40 , ( void * ) V_29 ) ;
}
F_23 ( V_8 -> V_31 -> V_28 - V_42 ) ;
F_24 ( V_8 -> V_31 -> V_27 - V_41 , V_36 ) ;
F_24 ( ( unsigned long ) V_8 -> V_31 , V_35 ) ;
}
static void F_27 ( struct V_8 * V_8 , int V_20 )
{
struct V_31 * V_32 = V_8 -> V_31 ;
F_28 ( V_20 , & V_52 . V_53 . V_54 ) ;
F_28 ( V_20 , F_29 ( & V_52 ) ) ;
V_32 -> V_47 = V_20 ;
V_32 -> V_48 = F_20 ( V_20 ) ;
V_32 -> V_55 = V_56 [ V_20 ] ;
V_32 -> V_57 = V_46 . V_57 ;
V_32 -> V_58 = V_46 . V_58 ;
V_32 -> V_59 = V_32 -> V_60 = V_32 -> V_61 = 0 ;
F_30 ( V_32 -> V_62 , 0 , 15 ) ;
F_31 ( ( unsigned int * ) V_32 -> V_63 ) ;
memcpy ( V_32 -> V_64 , V_46 . V_64 ,
V_65 / 8 ) ;
}
static void F_32 ( struct V_8 * V_8 , struct V_66 * V_67 )
{
struct V_31 * V_32 = V_8 -> V_31 ;
V_32 -> V_68 = ( unsigned long ) F_33 ( V_67 )
+ V_69 - V_70 - sizeof( struct V_71 ) ;
V_32 -> V_72 = ( unsigned long ) V_67 ;
V_32 -> V_73 = V_74 ;
V_32 -> V_75 = V_67 -> V_76 ;
V_32 -> V_59 = V_67 -> V_77 . V_59 ;
V_32 -> V_60 = V_67 -> V_77 . V_60 ;
V_32 -> V_61 = 0 ;
}
static void F_34 ( struct V_8 * V_8 , void (* F_35)( void * ) , void * V_78 )
{
struct V_31 * V_32 = V_8 -> V_31 ;
V_32 -> V_79 = V_32 -> V_68 ;
V_32 -> V_80 = ( unsigned long ) F_35 ;
V_32 -> V_81 = ( unsigned long ) V_78 ;
V_32 -> V_82 = - 1UL ;
F_7 ( V_8 , V_83 , 0 ) ;
}
static void F_36 ( struct V_8 * V_8 , void (* F_35)( void * ) ,
void * V_78 , unsigned long V_84 )
{
struct V_31 * V_32 = V_49 [ V_8 - V_21 ] ;
unsigned long V_85 = F_37 () ;
F_38 ( V_86 ) ;
if ( V_8 -> V_10 == V_85 )
F_35 ( V_78 ) ;
F_7 ( V_8 , V_87 , 0 ) ;
F_39 ( V_32 -> V_79 , V_84 ) ;
F_39 ( V_32 -> V_80 , ( unsigned long ) F_35 ) ;
F_39 ( V_32 -> V_81 , ( unsigned long ) V_78 ) ;
F_39 ( V_32 -> V_82 , V_85 ) ;
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
static int F_40 ( unsigned int V_88 )
{
int V_6 ;
if ( V_89 == V_88 )
return 0 ;
V_6 = F_5 ( 0 , V_90 , V_88 , NULL ) ;
if ( V_6 == 0 ) {
V_89 = V_88 ;
V_91 = 0 ;
while ( V_89 >= ( 1U << V_91 ) )
V_91 ++ ;
V_21 [ 0 ] . V_10 = F_37 () ;
}
return V_6 ;
}
void F_41 ( void (* F_35)( void * ) , void * V_78 )
{
struct V_8 * V_8 ;
V_8 = F_11 ( V_92 , F_37 () ) ;
if ( ! V_8 )
V_8 = V_21 + F_42 ( V_92 ) ;
F_36 ( V_8 , F_35 , V_78 , ( unsigned long ) V_79 ) ;
}
void F_43 ( void (* F_35)( void * ) , void * V_78 )
{
F_36 ( & V_21 [ 0 ] , F_35 , V_78 ,
V_21 -> V_31 -> V_28 -
V_42 + V_93 ) ;
}
int F_44 ( T_2 V_10 )
{
int V_20 ;
F_45 (cpu)
if ( V_21 [ V_20 ] . V_10 == V_10 )
return V_20 ;
return - 1 ;
}
bool F_46 ( int V_20 )
{
if ( F_47 ( V_94 , V_20 ) )
return false ;
if ( F_10 ( V_21 + V_20 ) )
return false ;
return true ;
}
void F_48 ( int V_20 )
{
if ( V_95 ) {
F_49 ( V_96 ) ;
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
} else if ( V_97 ) {
F_49 ( V_98 ) ;
asm volatile("diag 0,0,0x44");
}
}
static void F_50 ( T_5 * V_18 )
{
T_6 V_99 ;
int V_20 ;
V_99 = F_51 () + ( 1000000UL << 12 ) ;
F_12 (cpu, cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_52 ( V_100 , & V_8 -> V_23 ) ;
while ( F_5 ( V_8 -> V_10 , V_25 ,
0 , NULL ) == V_7 &&
F_51 () < V_99 )
F_6 () ;
}
while ( F_51 () < V_99 ) {
F_12 (cpu, cpumask)
if ( F_9 ( V_21 + V_20 ) )
F_53 ( V_20 , V_18 ) ;
if ( F_54 ( V_18 ) )
break;
F_6 () ;
}
}
void F_55 ( void )
{
T_5 V_18 ;
int V_20 ;
F_38 ( V_86 | V_101 ) ;
F_56 () ;
F_57 () ;
F_58 ( & V_18 , V_92 ) ;
F_53 ( F_59 () , & V_18 ) ;
if ( V_102 )
F_50 ( & V_18 ) ;
F_12 (cpu, &cpumask) {
struct V_8 * V_8 = V_21 + V_20 ;
F_7 ( V_8 , V_87 , 0 ) ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
}
}
static void F_60 ( void )
{
unsigned long V_103 ;
V_103 = F_61 ( & V_21 [ F_59 () ] . V_23 , 0 ) ;
if ( F_62 ( V_100 , & V_103 ) )
F_63 () ;
if ( F_62 ( V_104 , & V_103 ) )
F_64 () ;
if ( F_62 ( V_105 , & V_103 ) )
F_65 () ;
}
static void F_66 ( struct V_106 V_106 ,
unsigned int V_107 , unsigned long V_108 )
{
F_67 ( V_106 . V_109 == 0x1202 ? V_110 : V_111 ) ;
F_60 () ;
}
void F_68 ( const struct V_18 * V_19 )
{
int V_20 ;
F_12 (cpu, mask)
F_13 ( V_21 + V_20 , V_105 ) ;
}
void F_69 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_105 ) ;
}
void F_70 ( int V_20 )
{
F_13 ( V_21 + V_20 , V_104 ) ;
}
static void F_71 ( void * V_112 )
{
struct V_113 * V_114 = V_112 ;
unsigned long V_115 [ 16 ] ;
F_30 ( V_115 , 0 , 15 ) ;
V_115 [ V_114 -> V_116 ] = ( V_115 [ V_114 -> V_116 ] & V_114 -> V_117 ) | V_114 -> V_118 ;
F_72 ( V_115 , 0 , 15 ) ;
}
void F_73 ( int V_116 , int V_119 )
{
struct V_113 V_120 = { 1UL << V_119 , - 1UL , V_116 } ;
F_74 ( F_71 , & V_120 , 1 ) ;
}
void F_75 ( int V_116 , int V_119 )
{
struct V_113 V_120 = { 0 , ~ ( 1UL << V_119 ) , V_116 } ;
F_74 ( F_71 , & V_120 , 1 ) ;
}
int F_76 ( int V_20 )
{
struct V_8 * V_8 = V_21 + V_20 ;
unsigned long V_121 ;
V_121 = F_77 ( & V_8 -> V_31 -> V_122 ) ;
if ( F_4 ( V_8 -> V_10 , V_123 ,
V_121 ) != V_124 )
return - V_125 ;
if ( ! V_38 && ! V_39 )
return 0 ;
V_121 = F_77 ( V_8 -> V_31 -> V_43 & V_44 ) ;
if ( V_39 )
V_121 |= V_8 -> V_31 -> V_43 & V_45 ;
if ( F_4 ( V_8 -> V_10 , V_126 ,
V_121 ) != V_124 )
return - V_125 ;
return 0 ;
}
static T_1 void F_78 ( struct V_127 * V_128 , T_2 V_3 ,
bool V_129 , unsigned long V_130 )
{
T_7 * V_131 = ( T_7 * ) V_130 ;
if ( V_129 )
V_131 = V_132 ;
else
F_4 ( V_3 , V_126 , V_130 ) ;
F_79 ( V_128 , V_131 ) ;
}
static T_1 void F_80 ( struct V_127 * V_128 , T_2 V_3 ,
bool V_129 , unsigned long V_130 )
{
void * V_133 = ( void * ) V_130 ;
if ( V_129 )
F_81 ( V_133 , ( void * ) V_134 , 512 ) ;
else
F_4 ( V_3 , V_123 , V_130 ) ;
F_82 ( V_128 , V_133 ) ;
}
void T_1 F_83 ( void )
{
int V_3 , V_135 , V_136 ;
struct V_127 * V_128 ;
unsigned long V_130 ;
bool V_129 ;
if ( ! ( V_137 || V_138 . type == V_139 ) )
return;
V_130 = F_84 ( V_93 , V_93 , 1UL << 31 ) ;
F_40 ( V_140 . V_141 ) ;
V_135 = F_37 () ;
V_136 = V_142 << V_140 . V_141 ;
for ( V_3 = 0 ; V_3 <= V_136 ; V_3 ++ ) {
if ( F_4 ( V_3 , V_13 , 0 ) ==
V_143 )
continue;
V_129 = ( V_3 == V_135 ) ;
V_128 = F_85 ( V_129 ) ;
if ( ! V_128 )
F_86 ( L_1 ) ;
if ( V_38 )
F_78 ( V_128 , V_3 , V_129 , V_130 ) ;
if ( ! V_129 || V_137 )
F_80 ( V_128 , V_3 , V_129 , V_130 ) ;
}
F_87 ( V_130 , V_93 ) ;
F_88 () ;
F_40 ( 0 ) ;
}
void F_89 ( int V_20 , int V_144 )
{
V_21 [ V_20 ] . V_145 = V_144 ;
}
int F_90 ( int V_20 )
{
return V_21 [ V_20 ] . V_145 ;
}
static void T_8 F_91 ( struct V_146 * V_112 , int V_147 )
{
static int V_148 ;
int V_10 ;
if ( V_148 || F_92 ( V_112 , V_147 ) ) {
V_148 = 1 ;
for ( V_10 = 0 ;
V_10 < ( V_142 << V_91 ) ;
V_10 += ( 1U << V_91 ) ) {
if ( F_4 ( V_10 , V_13 , 0 ) ==
V_143 )
continue;
V_112 -> V_149 [ V_112 -> V_150 ] . V_151 =
V_10 >> V_91 ;
V_112 -> V_150 ++ ;
}
V_112 -> V_152 = V_112 -> V_150 ;
}
}
static int F_93 ( struct V_146 * V_112 , int V_153 )
{
struct V_8 * V_8 ;
T_5 V_154 ;
int V_20 , V_155 , V_156 , V_157 ;
T_2 V_10 ;
V_155 = 0 ;
F_94 ( & V_154 , V_158 , V_159 ) ;
V_20 = F_42 ( & V_154 ) ;
for ( V_156 = 0 ; ( V_156 < V_112 -> V_152 ) && ( V_20 < V_160 ) ; V_156 ++ ) {
if ( V_140 . V_161 && V_112 -> V_149 [ V_156 ] . type != V_162 )
continue;
V_10 = V_112 -> V_149 [ V_156 ] . V_151 << V_91 ;
for ( V_157 = 0 ; V_157 <= V_89 ; V_157 ++ ) {
if ( F_11 ( V_159 , V_10 + V_157 ) )
continue;
V_8 = V_21 + V_20 ;
V_8 -> V_10 = V_10 + V_157 ;
V_8 -> V_163 =
( V_20 >= V_112 -> V_150 * ( V_89 + 1 ) ) ?
V_164 : V_165 ;
F_89 ( V_20 , V_166 ) ;
F_95 ( V_20 , true ) ;
if ( V_153 && F_96 ( V_20 ) != 0 )
F_95 ( V_20 , false ) ;
else
V_155 ++ ;
V_20 = F_97 ( V_20 , & V_154 ) ;
if ( V_20 >= V_160 )
break;
}
}
return V_155 ;
}
void T_1 F_98 ( void )
{
unsigned int V_20 , V_88 , V_167 , V_168 ;
struct V_146 * V_112 ;
T_2 V_10 ;
V_112 = F_99 ( sizeof( * V_112 ) , 8 ) ;
F_91 ( V_112 , 1 ) ;
if ( V_140 . V_161 ) {
V_10 = F_37 () ;
for ( V_20 = 0 ; V_20 < V_112 -> V_152 ; V_20 ++ )
if ( V_112 -> V_149 [ V_20 ] . V_151 == V_10 ) {
V_162 = V_112 -> V_149 [ V_20 ] . type ;
break;
}
if ( V_20 >= V_112 -> V_152 )
F_86 ( L_2 ) ;
}
V_88 = V_162 ? V_140 . V_88 : V_140 . V_169 ;
V_88 = ( V_88 < V_2 ) ? V_88 : V_2 - 1 ;
F_40 ( V_88 ) ;
V_167 = V_168 = 0 ;
for ( V_20 = 0 ; V_20 < V_112 -> V_152 ; V_20 ++ ) {
if ( V_140 . V_161 &&
V_112 -> V_149 [ V_20 ] . type != V_162 )
continue;
if ( V_20 < V_112 -> V_150 )
V_167 += V_89 + 1 ;
else
V_168 += V_89 + 1 ;
}
F_100 ( L_3 , V_167 , V_168 ) ;
F_101 () ;
F_93 ( V_112 , 0 ) ;
F_102 () ;
F_103 ( ( unsigned long ) V_112 , sizeof( * V_112 ) ) ;
}
static void F_104 ( void * V_170 )
{
V_46 . V_171 = F_51 () ;
V_46 . V_79 = ( unsigned long ) V_79 ;
V_46 . V_80 = ( unsigned long ) V_172 ;
V_46 . V_81 = 0 ;
V_46 . V_82 = - 1UL ;
F_105 ( V_46 . V_63 ) ;
F_72 ( V_46 . V_62 , 0 , 15 ) ;
F_38 ( V_86 | V_101 ) ;
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_110 () ;
F_111 ( F_59 () ) ;
F_112 ( F_59 () , true ) ;
F_67 ( V_173 ) ;
F_113 () ;
F_114 ( V_174 ) ;
}
int F_115 ( unsigned int V_20 , struct V_66 * V_175 )
{
struct V_8 * V_8 ;
int V_176 , V_156 , V_177 ;
V_8 = V_21 + V_20 ;
if ( V_8 -> V_163 != V_165 )
return - V_125 ;
V_176 = F_116 ( V_20 ) ;
for ( V_156 = 0 ; V_156 <= V_89 ; V_156 ++ ) {
if ( V_176 + V_156 < V_160 )
if ( F_117 ( V_176 + V_156 ) )
break;
}
if ( V_156 > V_89 &&
F_7 ( V_21 + V_176 , V_178 , 0 ) !=
V_124 )
return - V_125 ;
V_177 = F_16 ( V_8 , V_20 ) ;
if ( V_177 )
return V_177 ;
F_27 ( V_8 , V_20 ) ;
F_32 ( V_8 , V_175 ) ;
F_34 ( V_8 , F_104 , NULL ) ;
while ( ! F_117 ( V_20 ) )
F_6 () ;
return 0 ;
}
static int T_1 F_118 ( char * V_1 )
{
F_3 ( & V_1 , & V_179 ) ;
return 0 ;
}
int F_119 ( void )
{
unsigned long V_115 [ 16 ] ;
F_60 () ;
F_112 ( F_59 () , false ) ;
F_120 () ;
F_30 ( V_115 , 0 , 15 ) ;
V_115 [ 0 ] &= ~ 0x0000ee70UL ;
V_115 [ 6 ] &= ~ 0xff000000UL ;
V_115 [ 14 ] &= ~ 0x1f000000UL ;
F_72 ( V_115 , 0 , 15 ) ;
F_121 ( V_180 ) ;
return 0 ;
}
void F_122 ( unsigned int V_20 )
{
struct V_8 * V_8 ;
V_8 = V_21 + V_20 ;
while ( ! F_9 ( V_8 ) )
F_6 () ;
F_25 ( V_8 ) ;
F_53 ( V_20 , F_29 ( & V_52 ) ) ;
F_53 ( V_20 , & V_52 . V_53 . V_54 ) ;
}
void T_9 F_123 ( void )
{
F_124 () ;
F_7 ( V_21 + F_59 () , V_87 , 0 ) ;
for (; ; ) ;
}
void T_1 F_125 ( void )
{
unsigned int V_181 , V_182 , V_20 ;
V_182 = F_126 ( V_140 . V_88 , V_140 . V_169 ) + 1 ;
V_182 = F_127 ( V_2 , V_182 ) ;
V_182 = ( V_140 . V_183 * V_182 ) ? : V_160 ;
V_181 = V_179 ? : V_160 ;
V_181 = F_127 ( V_181 , V_182 ) ;
for ( V_20 = 0 ; V_20 < V_181 && V_20 < V_160 ; V_20 ++ )
F_128 ( V_20 , true ) ;
}
void T_1 F_129 ( unsigned int V_184 )
{
unsigned long V_185 ;
if ( F_130 ( V_186 , F_66 ) )
F_86 ( L_4 ) ;
if ( F_130 ( V_187 , F_66 ) )
F_86 ( L_5 ) ;
if ( V_38 || V_39 ) {
V_185 = 1UL << ( V_39 ? 11 : 10 ) ;
V_40 = F_131 ( L_6 ,
V_185 , V_185 , 0 , NULL ) ;
if ( ! V_40 )
F_86 ( L_7 ) ;
}
}
void T_1 F_132 ( void )
{
struct V_8 * V_8 = V_21 ;
F_133 ( ! F_134 ( 0 ) || ! F_117 ( 0 ) ) ;
V_8 -> V_163 = V_165 ;
V_8 -> V_31 = (struct V_31 * ) ( unsigned long ) F_135 () ;
V_46 . V_55 = V_56 [ 0 ] ;
F_89 ( 0 , V_166 ) ;
}
void T_1 F_136 ( unsigned int V_184 )
{
}
void T_1 F_137 ( void )
{
V_21 [ 0 ] . V_10 = F_37 () ;
V_46 . V_47 = 0 ;
V_46 . V_48 = F_20 ( 0 ) ;
}
int F_138 ( unsigned int V_188 )
{
return 0 ;
}
static T_10 F_139 ( struct V_189 * V_190 ,
struct V_191 * V_192 , char * V_193 )
{
T_10 V_194 ;
F_140 ( & V_195 ) ;
V_194 = sprintf ( V_193 , L_8 , V_21 [ V_190 -> V_196 ] . V_163 ) ;
F_141 ( & V_195 ) ;
return V_194 ;
}
static T_10 F_142 ( struct V_189 * V_190 ,
struct V_191 * V_192 ,
const char * V_193 , T_11 V_194 )
{
struct V_8 * V_8 ;
int V_20 , V_144 , V_177 , V_156 ;
char V_197 ;
if ( sscanf ( V_193 , L_9 , & V_144 , & V_197 ) != 1 )
return - V_198 ;
if ( V_144 != 0 && V_144 != 1 )
return - V_198 ;
F_101 () ;
F_140 ( & V_195 ) ;
V_177 = - V_199 ;
V_20 = V_190 -> V_196 ;
V_20 = F_116 ( V_20 ) ;
if ( V_20 == 0 )
goto V_37;
for ( V_156 = 0 ; V_156 <= V_89 ; V_156 ++ )
if ( F_117 ( V_20 + V_156 ) )
goto V_37;
V_8 = V_21 + V_20 ;
V_177 = 0 ;
switch ( V_144 ) {
case 0 :
if ( V_8 -> V_163 != V_165 )
break;
V_177 = F_143 ( V_8 -> V_10 >> V_91 ) ;
if ( V_177 )
break;
for ( V_156 = 0 ; V_156 <= V_89 ; V_156 ++ ) {
if ( V_20 + V_156 >= V_160 || ! F_134 ( V_20 + V_156 ) )
continue;
V_8 [ V_156 ] . V_163 = V_164 ;
F_89 ( V_20 + V_156 ,
V_166 ) ;
}
F_144 () ;
break;
case 1 :
if ( V_8 -> V_163 != V_164 )
break;
V_177 = F_145 ( V_8 -> V_10 >> V_91 ) ;
if ( V_177 )
break;
for ( V_156 = 0 ; V_156 <= V_89 ; V_156 ++ ) {
if ( V_20 + V_156 >= V_160 || ! F_134 ( V_20 + V_156 ) )
continue;
V_8 [ V_156 ] . V_163 = V_165 ;
F_89 ( V_20 + V_156 ,
V_166 ) ;
}
F_144 () ;
break;
default:
break;
}
V_37:
F_141 ( & V_195 ) ;
F_102 () ;
return V_177 ? V_177 : V_194 ;
}
static T_10 F_146 ( struct V_189 * V_190 ,
struct V_191 * V_192 , char * V_193 )
{
return sprintf ( V_193 , L_8 , V_21 [ V_190 -> V_196 ] . V_10 ) ;
}
static int F_147 ( unsigned int V_20 )
{
struct V_189 * V_1 = & F_148 ( V_200 , V_20 ) -> V_190 ;
return F_149 ( & V_1 -> V_201 , & V_202 ) ;
}
static int F_150 ( unsigned int V_20 )
{
struct V_189 * V_1 = & F_148 ( V_200 , V_20 ) -> V_190 ;
F_151 ( & V_1 -> V_201 , & V_202 ) ;
return 0 ;
}
static int F_96 ( int V_20 )
{
struct V_189 * V_1 ;
struct V_20 * V_203 ;
int V_177 ;
V_203 = F_152 ( sizeof( * V_203 ) , V_33 ) ;
if ( ! V_203 )
return - V_51 ;
F_148 ( V_200 , V_20 ) = V_203 ;
V_1 = & V_203 -> V_190 ;
V_203 -> V_204 = 1 ;
V_177 = F_153 ( V_203 , V_20 ) ;
if ( V_177 )
goto V_37;
V_177 = F_149 ( & V_1 -> V_201 , & V_205 ) ;
if ( V_177 )
goto V_206;
V_177 = F_154 ( V_203 ) ;
if ( V_177 )
goto V_207;
return 0 ;
V_207:
F_151 ( & V_1 -> V_201 , & V_205 ) ;
V_206:
#ifdef F_155
F_156 ( V_203 ) ;
#endif
V_37:
return V_177 ;
}
int T_8 F_157 ( void )
{
struct V_146 * V_112 ;
int V_155 ;
V_112 = F_152 ( sizeof( * V_112 ) , V_33 ) ;
if ( ! V_112 )
return - V_51 ;
F_91 ( V_112 , 0 ) ;
F_101 () ;
F_140 ( & V_195 ) ;
V_155 = F_93 ( V_112 , 1 ) ;
F_141 ( & V_195 ) ;
F_102 () ;
F_158 ( V_112 ) ;
if ( V_155 )
F_159 () ;
return 0 ;
}
static T_10 T_8 F_160 ( struct V_189 * V_190 ,
struct V_191 * V_192 ,
const char * V_193 ,
T_11 V_194 )
{
int V_177 ;
V_177 = F_157 () ;
return V_177 ? V_177 : V_194 ;
}
static int T_1 F_161 ( void )
{
int V_20 , V_177 = 0 ;
#ifdef F_155
V_177 = F_162 ( V_208 . V_209 , & V_210 ) ;
if ( V_177 )
return V_177 ;
#endif
F_45 (cpu) {
V_177 = F_96 ( V_20 ) ;
if ( V_177 )
goto V_37;
}
V_177 = F_163 ( V_211 , L_10 ,
F_147 , F_150 ) ;
V_37:
return V_177 ;
}
