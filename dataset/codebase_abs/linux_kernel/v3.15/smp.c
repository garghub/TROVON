static inline int F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 , T_3 * V_4 )
{
int V_5 ;
while ( 1 ) {
V_5 = F_2 ( V_1 , V_2 , V_3 , NULL ) ;
if ( V_5 != V_6 )
return V_5 ;
F_3 () ;
}
}
static int F_4 ( struct V_7 * V_7 , T_2 V_2 , T_3 V_3 )
{
int V_5 , V_8 ;
for ( V_8 = 0 ; ; V_8 ++ ) {
V_5 = F_2 ( V_7 -> V_9 , V_2 , V_3 , NULL ) ;
if ( V_5 != V_6 )
break;
if ( V_8 >= 3 )
F_5 ( 10 ) ;
}
return V_5 ;
}
static inline int F_6 ( struct V_7 * V_7 )
{
T_3 V_10 ( V_4 ) ;
if ( F_2 ( V_7 -> V_9 , V_11 ,
0 , & V_4 ) != V_12 )
return 0 ;
return ! ! ( V_4 & ( V_13 | V_14 ) ) ;
}
static inline int F_7 ( struct V_7 * V_7 )
{
if ( F_2 ( V_7 -> V_9 , V_15 ,
0 , NULL ) != V_12 )
return 1 ;
return 0 ;
}
static struct V_7 * F_8 ( const struct V_16 * V_17 , int V_9 )
{
int V_18 ;
F_9 (cpu, mask)
if ( V_19 [ V_18 ] . V_9 == V_9 )
return V_19 + V_18 ;
return NULL ;
}
static void F_10 ( struct V_7 * V_7 , int V_20 )
{
int V_2 ;
if ( F_11 ( V_20 , & V_7 -> V_21 ) )
return;
V_2 = F_7 ( V_7 ) ? V_22 : V_23 ;
F_4 ( V_7 , V_2 , 0 ) ;
}
static int F_12 ( struct V_7 * V_7 , int V_18 )
{
struct V_24 * V_25 ;
if ( V_7 != & V_19 [ 0 ] ) {
V_7 -> V_26 = (struct V_24 * )
F_13 ( V_27 | V_28 , V_29 ) ;
V_7 -> V_30 = F_13 ( V_27 , V_31 ) ;
V_7 -> V_32 = F_14 ( V_27 ) ;
if ( ! V_7 -> V_26 || ! V_7 -> V_32 || ! V_7 -> V_30 )
goto V_33;
}
V_25 = V_7 -> V_26 ;
memcpy ( V_25 , & V_34 , 512 ) ;
memset ( ( char * ) V_25 + 512 , 0 , sizeof( * V_25 ) - 512 ) ;
V_25 -> V_30 = V_7 -> V_30 + V_35
- V_36 - sizeof( struct V_37 ) ;
V_25 -> V_32 = V_7 -> V_32 + V_38
- V_36 - sizeof( struct V_37 ) ;
V_25 -> V_39 = V_18 ;
#ifndef F_15
if ( V_40 ) {
V_25 -> V_41 = F_16 ( V_27 ) ;
if ( ! V_25 -> V_41 )
goto V_33;
}
#else
if ( F_17 ( V_25 ) )
goto V_33;
#endif
V_42 [ V_18 ] = V_25 ;
F_4 ( V_7 , V_43 , ( T_3 ) ( unsigned long ) V_25 ) ;
return 0 ;
V_33:
if ( V_7 != & V_19 [ 0 ] ) {
F_18 ( V_7 -> V_32 ) ;
F_19 ( V_7 -> V_30 , V_31 ) ;
F_19 ( ( unsigned long ) V_7 -> V_26 , V_29 ) ;
}
return - V_44 ;
}
static void F_20 ( struct V_7 * V_7 )
{
F_4 ( V_7 , V_43 , 0 ) ;
V_42 [ V_7 - V_19 ] = NULL ;
#ifndef F_15
if ( V_40 ) {
struct V_24 * V_25 = V_7 -> V_26 ;
F_18 ( ( unsigned long ) V_25 -> V_41 ) ;
V_25 -> V_41 = 0 ;
}
#else
F_21 ( V_7 -> V_26 ) ;
#endif
if ( V_7 != & V_19 [ 0 ] ) {
F_18 ( V_7 -> V_32 ) ;
F_19 ( V_7 -> V_30 , V_31 ) ;
F_19 ( ( unsigned long ) V_7 -> V_26 , V_29 ) ;
}
}
static void F_22 ( struct V_7 * V_7 , int V_18 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
if ( V_45 )
F_23 ( V_18 , & V_46 . V_47 . V_48 ) ;
F_23 ( V_18 , F_24 ( & V_46 ) ) ;
F_25 ( & V_46 . V_47 . V_49 ) ;
V_25 -> V_39 = V_18 ;
V_25 -> V_50 = V_51 [ V_18 ] ;
V_25 -> V_52 = V_34 . V_52 ;
V_25 -> V_53 = V_34 . V_53 ;
V_25 -> V_54 = V_34 . V_54 ;
V_25 -> V_55 = V_25 -> V_56 = V_25 -> V_57 = 0 ;
F_26 ( V_25 -> V_58 , 0 , 15 ) ;
F_27 ( ( unsigned int * ) V_25 -> V_59 ) ;
memcpy ( V_25 -> V_60 , V_34 . V_60 ,
V_61 / 8 ) ;
}
static void F_28 ( struct V_7 * V_7 , struct V_62 * V_63 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_64 * V_65 = F_29 ( V_63 ) ;
V_25 -> V_66 = ( unsigned long ) F_30 ( V_63 )
+ V_67 - V_36 - sizeof( struct V_37 ) ;
V_25 -> V_64 = ( unsigned long ) F_29 ( V_63 ) ;
V_25 -> V_68 = ( unsigned long ) V_63 ;
V_25 -> V_55 = V_65 -> V_55 ;
V_25 -> V_56 = V_65 -> V_56 ;
V_25 -> V_57 = 0 ;
}
static void F_31 ( struct V_7 * V_7 , void (* F_32)( void * ) , void * V_69 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
V_25 -> V_70 = V_25 -> V_66 ;
V_25 -> V_71 = ( unsigned long ) F_32 ;
V_25 -> V_72 = ( unsigned long ) V_69 ;
V_25 -> V_73 = - 1UL ;
F_4 ( V_7 , V_74 , 0 ) ;
}
static void F_33 ( struct V_7 * V_7 , void (* F_32)( void * ) ,
void * V_69 , unsigned long V_75 )
{
struct V_24 * V_25 = V_42 [ V_7 - V_19 ] ;
unsigned long V_76 = F_34 () ;
F_35 ( V_77 ) ;
if ( V_7 -> V_9 == V_76 )
F_32 ( V_69 ) ;
F_4 ( V_7 , V_78 , 0 ) ;
F_36 ( V_25 -> V_70 , V_75 ) ;
F_36 ( V_25 -> V_71 , ( unsigned long ) F_32 ) ;
F_36 ( V_25 -> V_72 , ( unsigned long ) V_69 ) ;
F_36 ( V_25 -> V_73 , V_76 ) ;
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
void F_37 ( void (* F_32)( void * ) , void * V_69 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_79 , F_34 () ) ;
if ( ! V_7 )
V_7 = V_19 + F_38 ( V_79 ) ;
F_33 ( V_7 , F_32 , V_69 , ( unsigned long ) V_70 ) ;
}
void F_39 ( void (* F_32)( void * ) , void * V_69 )
{
F_33 ( & V_19 [ 0 ] , F_32 , V_69 ,
V_19 -> V_32 + V_38 ) ;
}
int F_40 ( T_1 V_9 )
{
int V_18 ;
F_41 (cpu)
if ( V_19 [ V_18 ] . V_9 == V_9 )
return V_18 ;
return - 1 ;
}
int F_42 ( int V_18 )
{
return F_7 ( V_19 + V_18 ) ;
}
void F_43 ( void )
{
if ( V_80 )
asm volatile("diag 0,0,0x44");
}
void F_44 ( int V_18 )
{
if ( V_81 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_80 )
asm volatile("diag 0,0,0x44");
}
static void F_45 ( T_4 * V_16 )
{
T_5 V_82 ;
int V_18 ;
V_82 = F_46 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_47 ( V_83 , & V_7 -> V_21 ) ;
while ( F_2 ( V_7 -> V_9 , V_23 ,
0 , NULL ) == V_6 &&
F_46 () < V_82 )
F_3 () ;
}
while ( F_46 () < V_82 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_19 + V_18 ) )
F_48 ( V_18 , V_16 ) ;
if ( F_49 ( V_16 ) )
break;
F_3 () ;
}
}
void F_50 ( void )
{
T_4 V_16 ;
int V_18 ;
F_35 ( V_77 | V_84 ) ;
F_51 () ;
F_52 () ;
F_53 ( & V_16 , V_79 ) ;
F_48 ( F_54 () , & V_16 ) ;
if ( V_85 )
F_45 ( & V_16 ) ;
F_9 (cpu, &cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_4 ( V_7 , V_78 , 0 ) ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
}
}
void F_55 ( void )
{
F_4 ( V_19 + F_54 () , V_78 , 0 ) ;
for (; ; ) ;
}
static void F_56 ( void )
{
unsigned long V_86 ;
V_86 = F_57 ( & V_19 [ F_54 () ] . V_21 , 0 ) ;
if ( F_58 ( V_83 , & V_86 ) )
F_55 () ;
if ( F_58 ( V_87 , & V_86 ) )
F_59 () ;
if ( F_58 ( V_88 , & V_86 ) )
F_60 () ;
}
static void F_61 ( struct V_89 V_89 ,
unsigned int V_90 , unsigned long V_91 )
{
F_62 ( V_89 . V_92 == 0x1202 ? V_93 : V_94 ) ;
F_56 () ;
}
void F_63 ( const struct V_16 * V_17 )
{
int V_18 ;
F_9 (cpu, mask)
F_10 ( V_19 + V_18 , V_88 ) ;
}
void F_64 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_88 ) ;
}
static void F_65 ( void * V_95 )
{
F_66 () ;
}
void F_67 ( void )
{
F_68 ( F_65 , NULL , 1 ) ;
}
void F_69 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_87 ) ;
}
static void F_70 ( void * V_95 )
{
struct V_96 * V_97 = V_95 ;
unsigned long V_98 [ 16 ] ;
F_26 ( V_98 , 0 , 15 ) ;
V_98 [ V_97 -> V_99 ] = ( V_98 [ V_97 -> V_99 ] & V_97 -> V_100 ) | V_97 -> V_101 ;
F_71 ( V_98 , 0 , 15 ) ;
}
void F_72 ( int V_99 , int V_102 )
{
struct V_96 V_103 = { 1UL << V_102 , - 1UL , V_99 } ;
F_68 ( F_70 , & V_103 , 1 ) ;
}
void F_73 ( int V_99 , int V_102 )
{
struct V_96 V_103 = { 0 , ~ ( 1UL << V_102 ) , V_99 } ;
F_68 ( F_70 , & V_103 , 1 ) ;
}
static void T_6 F_74 ( int V_18 , T_1 V_9 )
{
void * V_25 = V_19 [ 0 ] . V_26 ;
struct V_104 * V_104 ;
if ( F_75 () )
return;
if ( ! V_105 && ( V_9 == V_106 ||
V_107 . type != V_108 ) )
return;
V_104 = F_76 ( V_18 ) ;
if ( ! V_104 )
F_77 ( L_1 ) ;
#ifdef F_78
if ( V_9 == V_106 ) {
F_79 ( 1 , ( void * ) V_104 , sizeof( * V_104 ) ,
V_109 - V_38 , 0 ) ;
return;
}
#endif
F_1 ( V_9 , V_110 , 0 , NULL ) ;
F_80 ( V_104 , V_25 + V_109 , sizeof( * V_104 ) ) ;
}
int F_81 ( int V_18 )
{
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
if ( F_1 ( V_7 -> V_9 , V_110 ,
0 , NULL ) != V_111 )
return - V_112 ;
return 0 ;
}
static inline void F_74 ( int V_18 , T_1 V_9 ) { }
void F_82 ( int V_18 , int V_113 )
{
V_19 [ V_18 ] . V_114 = V_113 ;
}
int F_83 ( int V_18 )
{
return V_19 [ V_18 ] . V_114 ;
}
static struct V_115 * F_84 ( void )
{
static int V_116 ;
struct V_115 * V_95 ;
int V_9 ;
V_95 = F_85 ( sizeof( * V_95 ) , V_27 ) ;
if ( V_95 && ( V_116 || F_86 ( V_95 ) ) ) {
V_116 = 1 ;
for ( V_9 = 0 ; V_9 <= V_117 ; V_9 ++ ) {
if ( F_1 ( V_9 , V_11 , 0 , NULL ) ==
V_118 )
continue;
V_95 -> V_18 [ V_95 -> V_119 ] . V_9 = V_9 ;
V_95 -> V_119 ++ ;
}
V_95 -> V_120 = V_95 -> V_119 ;
}
return V_95 ;
}
static int F_87 ( struct V_115 * V_95 , int V_121 )
{
struct V_7 * V_7 ;
T_4 V_122 ;
int V_18 , V_123 , V_124 ;
V_123 = 0 ;
F_88 ( & V_122 , V_125 , V_126 ) ;
V_18 = F_38 ( & V_122 ) ;
for ( V_124 = 0 ; ( V_124 < V_95 -> V_120 ) && ( V_18 < V_127 ) ; V_124 ++ ) {
if ( V_95 -> V_128 && V_95 -> V_18 [ V_124 ] . type != V_129 )
continue;
if ( F_8 ( V_126 , V_95 -> V_18 [ V_124 ] . V_9 ) )
continue;
V_7 = V_19 + V_18 ;
V_7 -> V_9 = V_95 -> V_18 [ V_124 ] . V_9 ;
V_7 -> V_130 = ( V_124 >= V_95 -> V_119 ) ?
V_131 : V_132 ;
F_82 ( V_18 , V_133 ) ;
F_89 ( V_18 , true ) ;
if ( V_121 && F_90 ( V_18 ) != 0 )
F_89 ( V_18 , false ) ;
else
V_123 ++ ;
V_18 = F_91 ( V_18 , & V_122 ) ;
}
return V_123 ;
}
static void T_6 F_92 ( void )
{
unsigned int V_18 , V_134 , V_135 ;
struct V_115 * V_95 ;
V_95 = F_84 () ;
if ( ! V_95 )
F_77 ( L_2 ) ;
if ( V_95 -> V_128 ) {
for ( V_18 = 0 ; V_18 < V_95 -> V_120 ; V_18 ++ ) {
if ( V_95 -> V_18 [ V_18 ] . V_9 != V_106 )
continue;
V_129 = V_95 -> V_18 [ V_18 ] . type ;
break;
}
}
V_134 = V_135 = 0 ;
for ( V_18 = 0 ; V_18 < V_95 -> V_120 ; V_18 ++ ) {
if ( V_95 -> V_128 && V_95 -> V_18 [ V_18 ] . type != V_129 )
continue;
if ( V_18 < V_95 -> V_119 ) {
F_74 ( V_134 , V_95 -> V_18 [ V_18 ] . V_9 ) ;
V_134 ++ ;
} else
V_135 ++ ;
}
F_93 ( L_3 , V_134 , V_135 ) ;
F_94 () ;
F_87 ( V_95 , 0 ) ;
F_95 () ;
F_96 ( V_95 ) ;
}
static void F_97 ( void * V_136 )
{
V_34 . V_137 = F_46 () ;
V_34 . V_70 = ( unsigned long ) V_70 ;
V_34 . V_71 = ( unsigned long ) V_138 ;
V_34 . V_72 = 0 ;
V_34 . V_73 = - 1UL ;
F_98 ( V_34 . V_59 ) ;
F_71 ( V_34 . V_58 , 0 , 15 ) ;
F_35 ( V_77 | V_84 ) ;
F_99 () ;
F_100 () ;
F_101 () ;
F_102 () ;
F_103 () ;
F_104 ( F_54 () ) ;
F_105 ( F_54 () , true ) ;
F_62 ( V_139 ) ;
F_106 () ;
F_107 ( V_140 ) ;
}
int F_108 ( unsigned int V_18 , struct V_62 * V_141 )
{
struct V_7 * V_7 ;
int V_142 ;
V_7 = V_19 + V_18 ;
if ( V_7 -> V_130 != V_132 )
return - V_112 ;
if ( F_4 ( V_7 , V_143 , 0 ) !=
V_111 )
return - V_112 ;
V_142 = F_12 ( V_7 , V_18 ) ;
if ( V_142 )
return V_142 ;
F_22 ( V_7 , V_18 ) ;
F_28 ( V_7 , V_141 ) ;
F_31 ( V_7 , F_97 , NULL ) ;
while ( ! F_109 ( V_18 ) )
F_3 () ;
return 0 ;
}
static int T_6 F_110 ( char * V_144 )
{
F_111 ( & V_144 , & V_145 ) ;
return 0 ;
}
int F_112 ( void )
{
unsigned long V_98 [ 16 ] ;
F_56 () ;
F_105 ( F_54 () , false ) ;
F_113 () ;
F_26 ( V_98 , 0 , 15 ) ;
V_98 [ 0 ] &= ~ 0x0000ee70UL ;
V_98 [ 6 ] &= ~ 0xff000000UL ;
V_98 [ 14 ] &= ~ 0x1f000000UL ;
F_71 ( V_98 , 0 , 15 ) ;
return 0 ;
}
void F_114 ( unsigned int V_18 )
{
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
F_20 ( V_7 ) ;
F_115 ( & V_46 . V_47 . V_49 ) ;
F_48 ( V_18 , F_24 ( & V_46 ) ) ;
if ( V_45 )
F_48 ( V_18 , & V_46 . V_47 . V_48 ) ;
}
void T_7 F_116 ( void )
{
F_117 () ;
F_4 ( V_19 + F_54 () , V_78 , 0 ) ;
for (; ; ) ;
}
void T_6 F_118 ( void )
{
unsigned int V_146 , V_147 , V_18 ;
V_147 = F_119 () ? : V_127 ;
V_146 = V_145 ? : V_127 ;
V_146 = F_120 ( V_146 , V_147 ) ;
for ( V_18 = 0 ; V_18 < V_146 && V_18 < V_127 ; V_18 ++ )
F_121 ( V_18 , true ) ;
}
void T_6 F_122 ( unsigned int V_148 )
{
if ( F_123 ( V_149 , F_61 ) )
F_77 ( L_4 ) ;
if ( F_123 ( V_150 , F_61 ) )
F_77 ( L_5 ) ;
F_92 () ;
}
void T_6 F_124 ( void )
{
struct V_7 * V_7 = V_19 ;
V_106 = F_34 () ;
V_7 -> V_130 = V_132 ;
V_7 -> V_9 = V_106 ;
V_7 -> V_26 = (struct V_24 * ) ( unsigned long ) F_125 () ;
V_7 -> V_30 = V_34 . V_30 - V_35
+ V_36 + sizeof( struct V_37 ) ;
V_7 -> V_32 = V_34 . V_32 - V_38
+ V_36 + sizeof( struct V_37 ) ;
V_34 . V_50 = V_51 [ 0 ] ;
F_82 ( 0 , V_133 ) ;
F_89 ( 0 , true ) ;
F_105 ( 0 , true ) ;
}
void T_6 F_126 ( unsigned int V_148 )
{
}
void T_6 F_127 ( void )
{
V_34 . V_39 = 0 ;
}
int F_128 ( unsigned int V_151 )
{
return 0 ;
}
static T_8 F_129 ( struct V_152 * V_153 ,
struct V_154 * V_155 , char * V_156 )
{
T_8 V_157 ;
F_130 ( & V_158 ) ;
V_157 = sprintf ( V_156 , L_6 , V_19 [ V_153 -> V_159 ] . V_130 ) ;
F_131 ( & V_158 ) ;
return V_157 ;
}
static T_8 F_132 ( struct V_152 * V_153 ,
struct V_154 * V_155 ,
const char * V_156 , T_9 V_157 )
{
struct V_7 * V_7 ;
int V_18 , V_113 , V_142 ;
char V_160 ;
if ( sscanf ( V_156 , L_7 , & V_113 , & V_160 ) != 1 )
return - V_161 ;
if ( V_113 != 0 && V_113 != 1 )
return - V_161 ;
F_94 () ;
F_130 ( & V_158 ) ;
V_142 = - V_162 ;
V_18 = V_153 -> V_159 ;
if ( F_109 ( V_18 ) || V_18 == 0 )
goto V_33;
V_7 = V_19 + V_18 ;
V_142 = 0 ;
switch ( V_113 ) {
case 0 :
if ( V_7 -> V_130 != V_132 )
break;
V_142 = F_133 ( V_7 -> V_9 ) ;
if ( V_142 )
break;
V_7 -> V_130 = V_131 ;
F_82 ( V_18 , V_133 ) ;
F_134 () ;
break;
case 1 :
if ( V_7 -> V_130 != V_131 )
break;
V_142 = F_135 ( V_7 -> V_9 ) ;
if ( V_142 )
break;
V_7 -> V_130 = V_132 ;
F_82 ( V_18 , V_133 ) ;
F_134 () ;
break;
default:
break;
}
V_33:
F_131 ( & V_158 ) ;
F_95 () ;
return V_142 ? V_142 : V_157 ;
}
static T_8 F_136 ( struct V_152 * V_153 ,
struct V_154 * V_155 , char * V_156 )
{
return sprintf ( V_156 , L_6 , V_19 [ V_153 -> V_159 ] . V_9 ) ;
}
static T_8 F_137 ( struct V_152 * V_153 ,
struct V_154 * V_155 , char * V_156 )
{
struct V_163 * V_164 = & F_138 ( V_165 , V_153 -> V_159 ) ;
unsigned long long V_166 ;
unsigned int V_167 ;
do {
V_167 = F_139 ( V_164 -> V_167 ) ;
V_166 = F_139 ( V_164 -> V_166 ) ;
if ( F_139 ( V_164 -> V_168 ) )
V_166 ++ ;
} while ( ( V_167 & 1 ) || ( F_139 ( V_164 -> V_167 ) != V_167 ) );
return sprintf ( V_156 , L_8 , V_166 ) ;
}
static T_8 F_140 ( struct V_152 * V_153 ,
struct V_154 * V_155 , char * V_156 )
{
struct V_163 * V_164 = & F_138 ( V_165 , V_153 -> V_159 ) ;
unsigned long long V_169 , V_170 , V_171 , V_172 ;
unsigned int V_167 ;
do {
V_169 = F_46 () ;
V_167 = F_139 ( V_164 -> V_167 ) ;
V_170 = F_139 ( V_164 -> V_170 ) ;
V_171 = F_139 ( V_164 -> V_168 ) ;
V_172 = F_139 ( V_164 -> V_173 ) ;
} while ( ( V_167 & 1 ) || ( F_139 ( V_164 -> V_167 ) != V_167 ) );
V_170 += V_171 ? ( ( V_172 ? : V_169 ) - V_171 ) : 0 ;
return sprintf ( V_156 , L_8 , V_170 >> 12 ) ;
}
static int F_141 ( struct V_174 * V_175 , unsigned long V_176 ,
void * V_177 )
{
unsigned int V_18 = ( unsigned int ) ( long ) V_177 ;
struct V_18 * V_178 = V_19 [ V_18 ] . V_18 ;
struct V_152 * V_144 = & V_178 -> V_153 ;
int V_179 = 0 ;
switch ( V_176 & ~ V_180 ) {
case V_181 :
V_179 = F_142 ( & V_144 -> V_182 , & V_183 ) ;
break;
case V_184 :
F_143 ( & V_144 -> V_182 , & V_183 ) ;
break;
}
return F_144 ( V_179 ) ;
}
static int F_90 ( int V_18 )
{
struct V_152 * V_144 ;
struct V_18 * V_178 ;
int V_142 ;
V_178 = F_85 ( sizeof( * V_178 ) , V_27 ) ;
if ( ! V_178 )
return - V_44 ;
V_19 [ V_18 ] . V_18 = V_178 ;
V_144 = & V_178 -> V_153 ;
V_178 -> V_185 = 1 ;
V_142 = F_145 ( V_178 , V_18 ) ;
if ( V_142 )
goto V_33;
V_142 = F_142 ( & V_144 -> V_182 , & V_186 ) ;
if ( V_142 )
goto V_187;
if ( F_109 ( V_18 ) ) {
V_142 = F_142 ( & V_144 -> V_182 , & V_183 ) ;
if ( V_142 )
goto V_188;
}
V_142 = F_146 ( V_178 ) ;
if ( V_142 )
goto V_189;
return 0 ;
V_189:
if ( F_109 ( V_18 ) )
F_143 ( & V_144 -> V_182 , & V_183 ) ;
V_188:
F_143 ( & V_144 -> V_182 , & V_186 ) ;
V_187:
#ifdef F_147
F_148 ( V_178 ) ;
#endif
V_33:
return V_142 ;
}
int T_10 F_149 ( void )
{
struct V_115 * V_95 ;
int V_123 ;
V_95 = F_84 () ;
if ( ! V_95 )
return - V_44 ;
F_94 () ;
F_130 ( & V_158 ) ;
V_123 = F_87 ( V_95 , 1 ) ;
F_131 ( & V_158 ) ;
F_95 () ;
F_96 ( V_95 ) ;
if ( V_123 )
F_150 () ;
return 0 ;
}
static T_8 T_10 F_151 ( struct V_152 * V_153 ,
struct V_154 * V_155 ,
const char * V_156 ,
T_9 V_157 )
{
int V_142 ;
V_142 = F_149 () ;
return V_142 ? V_142 : V_157 ;
}
static int T_6 F_152 ( void )
{
int V_18 , V_142 = 0 ;
#ifdef F_147
V_142 = F_153 ( V_190 . V_191 , & V_192 ) ;
if ( V_142 )
return V_142 ;
#endif
F_154 () ;
F_41 (cpu) {
V_142 = F_90 ( V_18 ) ;
if ( V_142 )
goto V_33;
}
F_155 ( F_141 , 0 ) ;
V_33:
F_156 () ;
return V_142 ;
}
