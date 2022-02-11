static inline int F_1 ( T_1 V_1 , T_2 V_2 , T_3 V_3 , T_3 * V_4 )
{
register unsigned int T_4 V_5 ( L_1 ) = V_3 ;
int V_6 ;
asm volatile(
" sigp %1,%2,0(%3)\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc), "+d" (reg1) : "d" (addr), "a" (order) : "cc");
if ( V_4 && V_6 == 1 )
* V_4 = T_4 ;
return V_6 ;
}
static inline int F_2 ( T_1 V_1 , T_2 V_2 , T_3 V_3 , T_3 * V_4 )
{
int V_6 ;
while ( 1 ) {
V_6 = F_1 ( V_1 , V_2 , V_3 , NULL ) ;
if ( V_6 != V_7 )
return V_6 ;
F_3 () ;
}
}
static int F_4 ( struct V_8 * V_8 , T_2 V_2 , T_3 V_3 )
{
int V_6 , V_9 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
V_6 = F_1 ( V_8 -> V_10 , V_2 , V_3 , NULL ) ;
if ( V_6 != V_7 )
break;
if ( V_9 >= 3 )
F_5 ( 10 ) ;
}
return V_6 ;
}
static inline int F_6 ( struct V_8 * V_8 )
{
T_3 V_11 ( V_4 ) ;
if ( F_1 ( V_8 -> V_10 , V_12 ,
0 , & V_4 ) != V_13 )
return 0 ;
return ! ! ( V_4 & ( V_14 | V_15 ) ) ;
}
static inline int F_7 ( struct V_8 * V_8 )
{
if ( F_1 ( V_8 -> V_10 , V_16 ,
0 , NULL ) != V_13 )
return 1 ;
return 0 ;
}
static struct V_8 * F_8 ( const struct V_17 * V_18 , int V_10 )
{
int V_19 ;
F_9 (cpu, mask)
if ( V_20 [ V_19 ] . V_10 == V_10 )
return V_20 + V_19 ;
return NULL ;
}
static void F_10 ( struct V_8 * V_8 , int V_21 )
{
int V_2 ;
F_11 ( V_21 , & V_8 -> V_22 ) ;
V_2 = F_7 ( V_8 ) ?
V_23 : V_24 ;
F_4 ( V_8 , V_2 , 0 ) ;
}
static int T_5 F_12 ( struct V_8 * V_8 , int V_19 )
{
struct V_25 * V_26 ;
if ( V_8 != & V_20 [ 0 ] ) {
V_8 -> V_27 = (struct V_25 * )
F_13 ( V_28 | V_29 , V_30 ) ;
V_8 -> V_31 = F_13 ( V_28 , V_32 ) ;
V_8 -> V_33 = F_14 ( V_28 ) ;
if ( ! V_8 -> V_27 || ! V_8 -> V_33 || ! V_8 -> V_31 )
goto V_34;
}
V_26 = V_8 -> V_27 ;
memcpy ( V_26 , & V_35 , 512 ) ;
memset ( ( char * ) V_26 + 512 , 0 , sizeof( * V_26 ) - 512 ) ;
V_26 -> V_31 = V_8 -> V_31 + V_36
- V_37 - sizeof( struct V_38 ) ;
V_26 -> V_33 = V_8 -> V_33 + V_39
- V_37 - sizeof( struct V_38 ) ;
V_26 -> V_40 = V_19 ;
#ifndef F_15
if ( V_41 ) {
V_26 -> V_42 = F_16 ( V_28 ) ;
if ( ! V_26 -> V_42 )
goto V_34;
}
#else
if ( F_17 ( V_26 ) )
goto V_34;
#endif
V_43 [ V_19 ] = V_26 ;
F_4 ( V_8 , V_44 , ( T_3 ) ( unsigned long ) V_26 ) ;
return 0 ;
V_34:
if ( V_8 != & V_20 [ 0 ] ) {
F_18 ( V_8 -> V_33 ) ;
F_19 ( V_8 -> V_31 , V_32 ) ;
F_19 ( ( unsigned long ) V_8 -> V_27 , V_30 ) ;
}
return - V_45 ;
}
static void F_20 ( struct V_8 * V_8 )
{
F_4 ( V_8 , V_44 , 0 ) ;
V_43 [ V_8 - V_20 ] = NULL ;
#ifndef F_15
if ( V_41 ) {
struct V_25 * V_26 = V_8 -> V_27 ;
F_18 ( ( unsigned long ) V_26 -> V_42 ) ;
V_26 -> V_42 = 0 ;
}
#else
F_21 ( V_8 -> V_27 ) ;
#endif
if ( V_8 != & V_20 [ 0 ] ) {
F_18 ( V_8 -> V_33 ) ;
F_19 ( V_8 -> V_31 , V_32 ) ;
F_19 ( ( unsigned long ) V_8 -> V_27 , V_30 ) ;
}
}
static void F_22 ( struct V_8 * V_8 , int V_19 )
{
struct V_25 * V_26 = V_8 -> V_27 ;
F_23 ( & V_46 . V_47 . V_48 ) ;
V_26 -> V_40 = V_19 ;
V_26 -> V_49 = V_50 [ V_19 ] ;
V_26 -> V_51 = V_35 . V_51 ;
V_26 -> V_52 = V_35 . V_52 ;
V_26 -> V_53 = V_35 . V_53 ;
V_26 -> V_54 = V_26 -> V_55 = V_26 -> V_56 = 0 ;
F_24 ( V_26 -> V_57 , 0 , 15 ) ;
F_25 ( ( unsigned int * ) V_26 -> V_58 ) ;
memcpy ( V_26 -> V_59 , V_35 . V_59 ,
V_60 / 8 ) ;
}
static void F_26 ( struct V_8 * V_8 , struct V_61 * V_62 )
{
struct V_25 * V_26 = V_8 -> V_27 ;
struct V_63 * V_64 = F_27 ( V_62 ) ;
V_26 -> V_65 = ( unsigned long ) F_28 ( V_62 )
+ V_66 - V_37 - sizeof( struct V_38 ) ;
V_26 -> V_63 = ( unsigned long ) F_27 ( V_62 ) ;
V_26 -> V_67 = ( unsigned long ) V_62 ;
V_26 -> V_54 = V_64 -> V_54 ;
V_26 -> V_55 = V_64 -> V_55 ;
V_26 -> V_56 = 0 ;
}
static void F_29 ( struct V_8 * V_8 , void (* F_30)( void * ) , void * V_68 )
{
struct V_25 * V_26 = V_8 -> V_27 ;
V_26 -> V_69 = V_26 -> V_65 ;
V_26 -> V_70 = ( unsigned long ) F_30 ;
V_26 -> V_71 = ( unsigned long ) V_68 ;
V_26 -> V_72 = - 1UL ;
F_4 ( V_8 , V_73 , 0 ) ;
}
static void F_31 ( struct V_8 * V_8 , void (* F_30)( void * ) ,
void * V_68 , unsigned long V_74 )
{
struct V_25 * V_26 = V_43 [ V_8 - V_20 ] ;
unsigned long V_75 = F_32 () ;
F_33 ( V_76 ) ;
if ( V_8 -> V_10 == V_75 )
F_30 ( V_68 ) ;
F_4 ( V_8 , V_77 , 0 ) ;
F_34 ( V_26 -> V_69 , V_74 ) ;
F_34 ( V_26 -> V_70 , ( unsigned long ) F_30 ) ;
F_34 ( V_26 -> V_71 , ( unsigned long ) V_68 ) ;
F_34 ( V_26 -> V_72 , V_75 ) ;
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
void F_35 ( void (* F_30)( void * ) , void * V_68 )
{
struct V_8 * V_8 ;
V_8 = F_8 ( V_78 , F_32 () ) ;
if ( ! V_8 )
V_8 = V_20 + F_36 ( V_78 ) ;
F_31 ( V_8 , F_30 , V_68 , ( unsigned long ) V_69 ) ;
}
void F_37 ( void (* F_30)( void * ) , void * V_68 )
{
F_31 ( & V_20 [ 0 ] , F_30 , V_68 ,
V_20 -> V_33 + V_39 ) ;
}
int F_38 ( T_1 V_10 )
{
int V_19 ;
F_39 (cpu)
if ( V_20 [ V_19 ] . V_10 == V_10 )
return V_19 ;
return - 1 ;
}
int F_40 ( int V_19 )
{
return F_7 ( V_20 + V_19 ) ;
}
void F_41 ( void )
{
if ( V_79 )
asm volatile("diag 0,0,0x44");
}
void F_42 ( int V_19 )
{
if ( V_80 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_79 )
asm volatile("diag 0,0,0x44");
}
void F_43 ( T_6 * V_17 )
{
T_7 V_81 ;
int V_19 ;
V_81 = F_44 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_8 * V_8 = V_20 + V_19 ;
F_11 ( V_82 , & V_8 -> V_22 ) ;
while ( F_1 ( V_8 -> V_10 , V_24 ,
0 , NULL ) == V_7 &&
F_44 () < V_81 )
F_3 () ;
}
while ( F_44 () < V_81 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_20 + V_19 ) )
F_45 ( V_19 , V_17 ) ;
if ( F_46 ( V_17 ) )
break;
F_3 () ;
}
}
void F_47 ( void )
{
T_6 V_17 ;
int V_19 ;
F_33 ( V_76 | V_83 ) ;
F_48 () ;
F_49 () ;
F_50 ( & V_17 , V_78 ) ;
F_45 ( F_51 () , & V_17 ) ;
if ( V_84 )
F_43 ( & V_17 ) ;
F_9 (cpu, &cpumask) {
struct V_8 * V_8 = V_20 + V_19 ;
F_4 ( V_8 , V_77 , 0 ) ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
}
}
void F_52 ( void )
{
F_4 ( V_20 + F_51 () , V_77 , 0 ) ;
for (; ; ) ;
}
static void F_53 ( void )
{
unsigned long V_85 ;
V_85 = F_54 ( & V_20 [ F_51 () ] . V_22 , 0 ) ;
if ( F_55 ( V_82 , & V_85 ) )
F_52 () ;
if ( F_55 ( V_86 , & V_85 ) )
F_56 () ;
if ( F_55 ( V_87 , & V_85 ) )
F_57 () ;
if ( F_55 ( V_88 , & V_85 ) )
F_58 () ;
}
static void F_59 ( struct V_89 V_89 ,
unsigned int V_90 , unsigned long V_91 )
{
F_60 ( V_89 . V_92 == 0x1202 ? V_93 : V_94 ) ;
F_53 () ;
}
void F_61 ( const struct V_17 * V_18 )
{
int V_19 ;
F_9 (cpu, mask)
F_10 ( V_20 + V_19 , V_87 ) ;
}
void F_62 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_88 ) ;
}
static void F_63 ( void * V_95 )
{
F_64 () ;
}
void F_65 ( void )
{
F_66 ( F_63 , NULL , 1 ) ;
}
void F_67 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_86 ) ;
}
static void F_68 ( void * V_95 )
{
struct V_96 * V_97 = V_95 ;
unsigned long V_98 [ 16 ] ;
F_24 ( V_98 , 0 , 15 ) ;
V_98 [ V_97 -> V_99 ] = ( V_98 [ V_97 -> V_99 ] & V_97 -> V_100 ) | V_97 -> V_101 ;
F_69 ( V_98 , 0 , 15 ) ;
}
void F_70 ( int V_99 , int V_102 )
{
struct V_96 V_103 = { 1UL << V_102 , - 1UL , V_99 } ;
F_66 ( F_68 , & V_103 , 1 ) ;
}
void F_71 ( int V_99 , int V_102 )
{
struct V_96 V_103 = { 0 , ~ ( 1UL << V_102 ) , V_99 } ;
F_66 ( F_68 , & V_103 , 1 ) ;
}
static void T_8 F_72 ( int V_19 , T_1 V_10 )
{
void * V_26 = V_20 [ 0 ] . V_27 ;
struct V_104 * V_104 ;
if ( F_73 () )
return;
if ( ! V_105 && ( V_10 == V_106 ||
V_107 . type != V_108 ) )
return;
if ( V_19 >= V_109 ) {
F_74 ( L_2
L_3 , V_19 , V_109 - 1 ) ;
return;
}
V_104 = F_75 ( sizeof( struct V_104 ) , V_28 ) ;
if ( ! V_104 )
F_76 ( L_4 ) ;
V_110 [ V_19 ] = V_104 ;
#ifdef F_77
if ( V_10 == V_106 ) {
F_78 ( 1 , ( void * ) V_104 , sizeof( * V_104 ) ,
V_111 - V_39 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_112 , 0 , NULL ) ;
F_79 ( V_104 , V_26 + V_111 , sizeof( * V_104 ) ) ;
}
int F_80 ( int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
if ( F_2 ( V_8 -> V_10 , V_112 ,
0 , NULL ) != V_113 )
return - V_114 ;
return 0 ;
}
static inline void F_72 ( int V_19 , T_1 V_10 ) { }
void F_81 ( int V_19 , int V_115 )
{
V_20 [ V_19 ] . V_116 = V_115 ;
}
int F_82 ( int V_19 )
{
return V_20 [ V_19 ] . V_116 ;
}
static struct V_117 * F_83 ( void )
{
static int V_118 ;
struct V_117 * V_95 ;
int V_10 ;
V_95 = F_84 ( sizeof( * V_95 ) , V_28 ) ;
if ( V_95 && ( V_118 || F_85 ( V_95 ) ) ) {
V_118 = 1 ;
for ( V_10 = 0 ; V_10 <= V_119 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_12 , 0 , NULL ) ==
V_120 )
continue;
V_95 -> V_19 [ V_95 -> V_121 ] . V_10 = V_10 ;
V_95 -> V_121 ++ ;
}
V_95 -> V_122 = V_95 -> V_121 ;
}
return V_95 ;
}
static int T_5 F_86 ( struct V_117 * V_95 ,
int V_123 )
{
struct V_8 * V_8 ;
T_6 V_124 ;
int V_19 , V_125 , V_126 ;
V_125 = 0 ;
F_87 ( & V_124 , V_127 , V_128 ) ;
V_19 = F_36 ( & V_124 ) ;
for ( V_126 = 0 ; ( V_126 < V_95 -> V_122 ) && ( V_19 < V_129 ) ; V_126 ++ ) {
if ( V_95 -> V_130 && V_95 -> V_19 [ V_126 ] . type != V_131 )
continue;
if ( F_8 ( V_128 , V_95 -> V_19 [ V_126 ] . V_10 ) )
continue;
V_8 = V_20 + V_19 ;
V_8 -> V_10 = V_95 -> V_19 [ V_126 ] . V_10 ;
V_8 -> V_132 = ( V_126 >= V_95 -> V_121 ) ?
V_133 : V_134 ;
F_81 ( V_19 , V_135 ) ;
F_88 ( V_19 , true ) ;
if ( V_123 && F_89 ( V_19 ) != 0 )
F_88 ( V_19 , false ) ;
else
V_125 ++ ;
V_19 = F_90 ( V_19 , & V_124 ) ;
}
return V_125 ;
}
static void T_8 F_91 ( void )
{
unsigned int V_19 , V_136 , V_137 ;
struct V_117 * V_95 ;
V_95 = F_83 () ;
if ( ! V_95 )
F_76 ( L_5 ) ;
if ( V_95 -> V_130 ) {
for ( V_19 = 0 ; V_19 < V_95 -> V_122 ; V_19 ++ ) {
if ( V_95 -> V_19 [ V_19 ] . V_10 != V_106 )
continue;
V_131 = V_95 -> V_19 [ V_19 ] . type ;
break;
}
}
V_136 = V_137 = 0 ;
for ( V_19 = 0 ; V_19 < V_95 -> V_122 ; V_19 ++ ) {
if ( V_95 -> V_130 && V_95 -> V_19 [ V_19 ] . type != V_131 )
continue;
if ( V_19 < V_95 -> V_121 ) {
F_72 ( V_136 , V_95 -> V_19 [ V_19 ] . V_10 ) ;
V_136 ++ ;
} else
V_137 ++ ;
}
F_92 ( L_6 , V_136 , V_137 ) ;
F_93 () ;
F_86 ( V_95 , 0 ) ;
F_94 () ;
F_95 ( V_95 ) ;
}
static void T_5 F_96 ( void * V_138 )
{
V_35 . V_139 = F_44 () ;
V_35 . V_69 = ( unsigned long ) V_69 ;
V_35 . V_70 = ( unsigned long ) V_140 ;
V_35 . V_71 = 0 ;
V_35 . V_72 = - 1UL ;
F_97 ( V_35 . V_58 ) ;
F_69 ( V_35 . V_57 , 0 , 15 ) ;
F_33 ( V_76 | V_83 ) ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 () ;
F_102 () ;
F_103 ( F_51 () ) ;
F_104 ( F_51 () , true ) ;
F_60 ( V_141 ) ;
F_105 () ;
F_106 ( V_142 ) ;
}
int T_5 F_107 ( unsigned int V_19 , struct V_61 * V_143 )
{
struct V_8 * V_8 ;
int V_144 ;
V_8 = V_20 + V_19 ;
if ( V_8 -> V_132 != V_134 )
return - V_114 ;
if ( F_4 ( V_8 , V_145 , 0 ) !=
V_113 )
return - V_114 ;
V_144 = F_12 ( V_8 , V_19 ) ;
if ( V_144 )
return V_144 ;
F_22 ( V_8 , V_19 ) ;
F_26 ( V_8 , V_143 ) ;
F_29 ( V_8 , F_96 , NULL ) ;
while ( ! F_108 ( V_19 ) )
F_3 () ;
return 0 ;
}
static int T_8 F_109 ( char * V_146 )
{
int V_147 , V_19 ;
if ( F_110 ( V_146 , 0 , & V_147 ) < 0 )
return 0 ;
F_111 ( F_112 ( 0 ) ) ;
for ( V_19 = 1 ; V_19 < V_147 && V_19 < V_129 ; V_19 ++ )
F_113 ( V_19 , true ) ;
return 0 ;
}
int F_114 ( void )
{
unsigned long V_98 [ 16 ] ;
F_53 () ;
F_104 ( F_51 () , false ) ;
F_115 () ;
F_24 ( V_98 , 0 , 15 ) ;
V_98 [ 0 ] &= ~ 0x0000ee70UL ;
V_98 [ 6 ] &= ~ 0xff000000UL ;
V_98 [ 14 ] &= ~ 0x1f000000UL ;
F_69 ( V_98 , 0 , 15 ) ;
return 0 ;
}
void F_116 ( unsigned int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_117 ( & V_46 . V_47 . V_48 ) ;
}
void T_9 F_118 ( void )
{
F_119 () ;
F_4 ( V_20 + F_51 () , V_77 , 0 ) ;
for (; ; ) ;
}
void T_8 F_120 ( unsigned int V_148 )
{
if ( F_121 ( 0x1201 , F_59 ) != 0 )
F_76 ( L_7 ) ;
if ( F_121 ( 0x1202 , F_59 ) != 0 )
F_76 ( L_8 ) ;
F_91 () ;
}
void T_8 F_122 ( void )
{
struct V_8 * V_8 = V_20 ;
V_106 = F_32 () ;
V_8 -> V_132 = V_134 ;
V_8 -> V_10 = V_106 ;
V_8 -> V_27 = (struct V_25 * ) ( unsigned long ) F_123 () ;
V_8 -> V_31 = V_35 . V_31 - V_36
+ V_37 + sizeof( struct V_38 ) ;
V_8 -> V_33 = V_35 . V_33 - V_39
+ V_37 + sizeof( struct V_38 ) ;
V_35 . V_49 = V_50 [ 0 ] ;
F_81 ( 0 , V_135 ) ;
F_88 ( 0 , true ) ;
F_104 ( 0 , true ) ;
}
void T_8 F_124 ( unsigned int V_148 )
{
}
void T_8 F_125 ( void )
{
V_35 . V_40 = 0 ;
}
int F_126 ( unsigned int V_149 )
{
return 0 ;
}
static T_10 F_127 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
T_10 V_155 ;
F_128 ( & V_156 ) ;
V_155 = sprintf ( V_154 , L_9 , V_20 [ V_151 -> V_157 ] . V_132 ) ;
F_129 ( & V_156 ) ;
return V_155 ;
}
static T_10 F_130 ( struct V_150 * V_151 ,
struct V_152 * V_153 ,
const char * V_154 , T_11 V_155 )
{
struct V_8 * V_8 ;
int V_19 , V_115 , V_144 ;
char V_158 ;
if ( sscanf ( V_154 , L_10 , & V_115 , & V_158 ) != 1 )
return - V_159 ;
if ( V_115 != 0 && V_115 != 1 )
return - V_159 ;
F_93 () ;
F_128 ( & V_156 ) ;
V_144 = - V_160 ;
V_19 = V_151 -> V_157 ;
if ( F_108 ( V_19 ) || V_19 == 0 )
goto V_34;
V_8 = V_20 + V_19 ;
V_144 = 0 ;
switch ( V_115 ) {
case 0 :
if ( V_8 -> V_132 != V_134 )
break;
V_144 = F_131 ( V_8 -> V_10 ) ;
if ( V_144 )
break;
V_8 -> V_132 = V_133 ;
F_81 ( V_19 , V_135 ) ;
F_132 () ;
break;
case 1 :
if ( V_8 -> V_132 != V_133 )
break;
V_144 = F_133 ( V_8 -> V_10 ) ;
if ( V_144 )
break;
V_8 -> V_132 = V_134 ;
F_81 ( V_19 , V_135 ) ;
F_132 () ;
break;
default:
break;
}
V_34:
F_129 ( & V_156 ) ;
F_94 () ;
return V_144 ? V_144 : V_155 ;
}
static T_10 F_134 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
return sprintf ( V_154 , L_9 , V_20 [ V_151 -> V_157 ] . V_10 ) ;
}
static T_10 F_135 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_161 * V_162 = & F_136 ( V_163 , V_151 -> V_157 ) ;
unsigned long long V_164 ;
unsigned int V_165 ;
do {
V_165 = F_137 ( V_162 -> V_165 ) ;
V_164 = F_137 ( V_162 -> V_164 ) ;
if ( F_137 ( V_162 -> V_166 ) )
V_164 ++ ;
} while ( ( V_165 & 1 ) || ( V_162 -> V_165 != V_165 ) );
return sprintf ( V_154 , L_11 , V_164 ) ;
}
static T_10 F_138 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_161 * V_162 = & F_136 ( V_163 , V_151 -> V_157 ) ;
unsigned long long V_167 , V_168 , V_169 , V_170 ;
unsigned int V_165 ;
do {
V_167 = F_44 () ;
V_165 = F_137 ( V_162 -> V_165 ) ;
V_168 = F_137 ( V_162 -> V_168 ) ;
V_169 = F_137 ( V_162 -> V_166 ) ;
V_170 = F_137 ( V_162 -> V_171 ) ;
} while ( ( V_165 & 1 ) || ( V_162 -> V_165 != V_165 ) );
V_168 += V_169 ? ( ( V_170 ? : V_167 ) - V_169 ) : 0 ;
return sprintf ( V_154 , L_11 , V_168 >> 12 ) ;
}
static int T_5 F_139 ( struct V_172 * V_173 ,
unsigned long V_174 , void * V_175 )
{
unsigned int V_19 = ( unsigned int ) ( long ) V_175 ;
struct V_19 * V_176 = & V_20 [ V_19 ] . V_19 ;
struct V_150 * V_146 = & V_176 -> V_151 ;
int V_177 = 0 ;
switch ( V_174 & ~ V_178 ) {
case V_179 :
V_177 = F_140 ( & V_146 -> V_180 , & V_181 ) ;
break;
case V_182 :
F_141 ( & V_146 -> V_180 , & V_181 ) ;
break;
}
return F_142 ( V_177 ) ;
}
static int T_5 F_89 ( int V_19 )
{
struct V_19 * V_176 = & V_20 [ V_19 ] . V_19 ;
struct V_150 * V_146 = & V_176 -> V_151 ;
int V_144 ;
V_176 -> V_183 = 1 ;
V_144 = F_143 ( V_176 , V_19 ) ;
if ( V_144 )
goto V_34;
V_144 = F_140 ( & V_146 -> V_180 , & V_184 ) ;
if ( V_144 )
goto V_185;
if ( F_108 ( V_19 ) ) {
V_144 = F_140 ( & V_146 -> V_180 , & V_181 ) ;
if ( V_144 )
goto V_186;
}
V_144 = F_144 ( V_176 ) ;
if ( V_144 )
goto V_187;
return 0 ;
V_187:
if ( F_108 ( V_19 ) )
F_141 ( & V_146 -> V_180 , & V_181 ) ;
V_186:
F_141 ( & V_146 -> V_180 , & V_184 ) ;
V_185:
#ifdef F_145
F_146 ( V_176 ) ;
#endif
V_34:
return V_144 ;
}
int T_12 F_147 ( void )
{
struct V_117 * V_95 ;
int V_125 ;
V_95 = F_83 () ;
if ( ! V_95 )
return - V_45 ;
F_93 () ;
F_128 ( & V_156 ) ;
V_125 = F_86 ( V_95 , 1 ) ;
F_129 ( & V_156 ) ;
F_94 () ;
F_95 ( V_95 ) ;
if ( V_125 )
F_148 () ;
return 0 ;
}
static T_10 T_12 F_149 ( struct V_150 * V_151 ,
struct V_152 * V_153 ,
const char * V_154 ,
T_11 V_155 )
{
int V_144 ;
V_144 = F_147 () ;
return V_144 ? V_144 : V_155 ;
}
static int T_8 F_150 ( void )
{
int V_19 , V_144 ;
F_151 ( F_139 , 0 ) ;
#ifdef F_145
V_144 = F_152 ( V_188 . V_189 , & V_190 ) ;
if ( V_144 )
return V_144 ;
#endif
F_39 (cpu) {
V_144 = F_89 ( V_19 ) ;
if ( V_144 )
return V_144 ;
}
return 0 ;
}
