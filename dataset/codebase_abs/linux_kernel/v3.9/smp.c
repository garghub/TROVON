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
V_26 -> V_31 = V_8 -> V_31 + V_36 ;
V_26 -> V_33 = V_8 -> V_33 + V_37 ;
V_26 -> V_38 = V_19 ;
#ifndef F_15
if ( V_39 ) {
V_26 -> V_40 = F_16 ( V_28 ) ;
if ( ! V_26 -> V_40 )
goto V_34;
}
#else
if ( F_17 ( V_26 ) )
goto V_34;
#endif
V_41 [ V_19 ] = V_26 ;
F_4 ( V_8 , V_42 , ( T_3 ) ( unsigned long ) V_26 ) ;
return 0 ;
V_34:
if ( V_8 != & V_20 [ 0 ] ) {
F_18 ( V_8 -> V_33 ) ;
F_19 ( V_8 -> V_31 , V_32 ) ;
F_19 ( ( unsigned long ) V_8 -> V_27 , V_30 ) ;
}
return - V_43 ;
}
static void F_20 ( struct V_8 * V_8 )
{
F_4 ( V_8 , V_42 , 0 ) ;
V_41 [ V_8 - V_20 ] = NULL ;
#ifndef F_15
if ( V_39 ) {
struct V_25 * V_26 = V_8 -> V_27 ;
F_18 ( ( unsigned long ) V_26 -> V_40 ) ;
V_26 -> V_40 = 0 ;
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
F_23 ( & V_44 . V_45 . V_46 ) ;
V_26 -> V_38 = V_19 ;
V_26 -> V_47 = V_48 [ V_19 ] ;
V_26 -> V_49 = V_35 . V_49 ;
V_26 -> V_50 = V_35 . V_50 ;
V_26 -> V_51 = V_35 . V_51 ;
V_26 -> V_52 = V_26 -> V_53 = V_26 -> V_54 = 0 ;
F_24 ( V_26 -> V_55 , 0 , 15 ) ;
F_25 ( ( unsigned int * ) V_26 -> V_56 ) ;
memcpy ( V_26 -> V_57 , V_35 . V_57 ,
V_58 / 8 ) ;
}
static void F_26 ( struct V_8 * V_8 , struct V_59 * V_60 )
{
struct V_25 * V_26 = V_8 -> V_27 ;
struct V_61 * V_62 = F_27 ( V_60 ) ;
V_26 -> V_63 = ( unsigned long ) F_28 ( V_60 ) + V_64 ;
V_26 -> V_61 = ( unsigned long ) F_27 ( V_60 ) ;
V_26 -> V_65 = ( unsigned long ) V_60 ;
V_26 -> V_52 = V_62 -> V_52 ;
V_26 -> V_53 = V_62 -> V_53 ;
V_26 -> V_54 = 0 ;
}
static void F_29 ( struct V_8 * V_8 , void (* F_30)( void * ) , void * V_66 )
{
struct V_25 * V_26 = V_8 -> V_27 ;
V_26 -> V_67 = V_26 -> V_63 ;
V_26 -> V_68 = ( unsigned long ) F_30 ;
V_26 -> V_69 = ( unsigned long ) V_66 ;
V_26 -> V_70 = - 1UL ;
F_4 ( V_8 , V_71 , 0 ) ;
}
static void F_31 ( struct V_8 * V_8 , void (* F_30)( void * ) ,
void * V_66 , unsigned long V_72 )
{
struct V_25 * V_26 = V_41 [ V_8 - V_20 ] ;
unsigned long V_73 = F_32 () ;
F_33 ( V_74 ) ;
if ( V_8 -> V_10 == V_73 )
F_30 ( V_66 ) ;
F_4 ( V_8 , V_75 , 0 ) ;
F_34 ( V_26 -> V_67 , V_72 ) ;
F_34 ( V_26 -> V_68 , ( unsigned long ) F_30 ) ;
F_34 ( V_26 -> V_69 , ( unsigned long ) V_66 ) ;
F_34 ( V_26 -> V_70 , V_73 ) ;
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
void F_35 ( void (* F_30)( void * ) , void * V_66 )
{
struct V_8 * V_8 ;
V_8 = F_8 ( V_76 , F_32 () ) ;
if ( ! V_8 )
V_8 = V_20 + F_36 ( V_76 ) ;
F_31 ( V_8 , F_30 , V_66 , ( unsigned long ) V_67 ) ;
}
void F_37 ( void (* F_30)( void * ) , void * V_66 )
{
F_31 ( & V_20 [ 0 ] , F_30 , V_66 ,
V_20 -> V_33 + V_37 ) ;
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
if ( V_77 )
asm volatile("diag 0,0,0x44");
}
void F_42 ( int V_19 )
{
if ( V_78 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_77 )
asm volatile("diag 0,0,0x44");
}
void F_43 ( T_6 * V_17 )
{
T_7 V_79 ;
int V_19 ;
V_79 = F_44 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_8 * V_8 = V_20 + V_19 ;
F_11 ( V_80 , & V_8 -> V_22 ) ;
while ( F_1 ( V_8 -> V_10 , V_24 ,
0 , NULL ) == V_7 &&
F_44 () < V_79 )
F_3 () ;
}
while ( F_44 () < V_79 ) {
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
F_33 ( V_74 | V_81 ) ;
F_48 () ;
F_49 () ;
F_50 ( & V_17 , V_76 ) ;
F_45 ( F_51 () , & V_17 ) ;
if ( V_82 )
F_43 ( & V_17 ) ;
F_9 (cpu, &cpumask) {
struct V_8 * V_8 = V_20 + V_19 ;
F_4 ( V_8 , V_75 , 0 ) ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
}
}
void F_52 ( void )
{
F_4 ( V_20 + F_51 () , V_75 , 0 ) ;
for (; ; ) ;
}
static void F_53 ( struct V_83 V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
unsigned long V_86 ;
int V_19 ;
V_19 = F_51 () ;
if ( V_83 . V_87 == 0x1202 )
F_54 ( V_88 ) ;
else
F_54 ( V_89 ) ;
V_86 = F_55 ( & V_20 [ V_19 ] . V_22 , 0 ) ;
if ( F_56 ( V_80 , & V_86 ) )
F_52 () ;
if ( F_56 ( V_90 , & V_86 ) )
F_57 () ;
if ( F_56 ( V_91 , & V_86 ) )
F_58 () ;
if ( F_56 ( V_92 , & V_86 ) )
F_59 () ;
}
void F_60 ( const struct V_17 * V_18 )
{
int V_19 ;
F_9 (cpu, mask)
F_10 ( V_20 + V_19 , V_91 ) ;
}
void F_61 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_92 ) ;
}
static void F_62 ( void * V_93 )
{
F_63 () ;
}
void F_64 ( void )
{
F_65 ( F_62 , NULL , 1 ) ;
}
void F_66 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_90 ) ;
}
static void F_67 ( void * V_93 )
{
struct V_94 * V_95 = V_93 ;
unsigned long V_96 [ 16 ] ;
F_24 ( V_96 , 0 , 15 ) ;
V_96 [ V_95 -> V_97 ] = ( V_96 [ V_95 -> V_97 ] & V_95 -> V_98 ) | V_95 -> V_99 ;
F_68 ( V_96 , 0 , 15 ) ;
}
void F_69 ( int V_97 , int V_100 )
{
struct V_94 V_101 = { 1UL << V_100 , - 1UL , V_97 } ;
F_65 ( F_67 , & V_101 , 1 ) ;
}
void F_70 ( int V_97 , int V_100 )
{
struct V_94 V_101 = { 0 , ~ ( 1UL << V_100 ) , V_97 } ;
F_65 ( F_67 , & V_101 , 1 ) ;
}
static void T_8 F_71 ( int V_19 , T_1 V_10 )
{
void * V_26 = V_20 [ 0 ] . V_27 ;
struct V_102 * V_102 ;
if ( F_72 () )
return;
if ( ! V_103 && ( V_10 == V_104 ||
V_105 . type != V_106 ) )
return;
if ( V_19 >= V_107 ) {
F_73 ( L_2
L_3 , V_19 , V_107 - 1 ) ;
return;
}
V_102 = F_74 ( sizeof( struct V_102 ) , V_28 ) ;
if ( ! V_102 )
F_75 ( L_4 ) ;
V_108 [ V_19 ] = V_102 ;
#ifdef F_76
if ( V_10 == V_104 ) {
F_77 ( 1 , ( void * ) V_102 , sizeof( * V_102 ) ,
V_109 - V_37 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_110 , 0 , NULL ) ;
F_78 ( V_102 , V_26 + V_109 , sizeof( * V_102 ) ) ;
}
int F_79 ( int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
if ( F_2 ( V_8 -> V_10 , V_110 ,
0 , NULL ) != V_111 )
return - V_112 ;
return 0 ;
}
static inline void F_71 ( int V_19 , T_1 V_10 ) { }
void F_80 ( int V_19 , int V_113 )
{
V_20 [ V_19 ] . V_114 = V_113 ;
}
int F_81 ( int V_19 )
{
return V_20 [ V_19 ] . V_114 ;
}
static struct V_115 * F_82 ( void )
{
static int V_116 ;
struct V_115 * V_93 ;
int V_10 ;
V_93 = F_83 ( sizeof( * V_93 ) , V_28 ) ;
if ( V_93 && ( V_116 || F_84 ( V_93 ) ) ) {
V_116 = 1 ;
for ( V_10 = 0 ; V_10 <= V_117 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_12 , 0 , NULL ) ==
V_118 )
continue;
V_93 -> V_19 [ V_93 -> V_119 ] . V_10 = V_10 ;
V_93 -> V_119 ++ ;
}
V_93 -> V_120 = V_93 -> V_119 ;
}
return V_93 ;
}
static int T_5 F_85 ( struct V_115 * V_93 ,
int V_121 )
{
struct V_8 * V_8 ;
T_6 V_122 ;
int V_19 , V_123 , V_124 ;
V_123 = 0 ;
F_86 ( & V_122 , V_125 , V_126 ) ;
V_19 = F_36 ( & V_122 ) ;
for ( V_124 = 0 ; ( V_124 < V_93 -> V_120 ) && ( V_19 < V_127 ) ; V_124 ++ ) {
if ( V_93 -> V_128 && V_93 -> V_19 [ V_124 ] . type != V_129 )
continue;
if ( F_8 ( V_126 , V_93 -> V_19 [ V_124 ] . V_10 ) )
continue;
V_8 = V_20 + V_19 ;
V_8 -> V_10 = V_93 -> V_19 [ V_124 ] . V_10 ;
V_8 -> V_130 = ( V_19 >= V_93 -> V_119 ) ?
V_131 : V_132 ;
F_80 ( V_19 , V_133 ) ;
F_87 ( V_19 , true ) ;
if ( V_121 && F_88 ( V_19 ) != 0 )
F_87 ( V_19 , false ) ;
else
V_123 ++ ;
V_19 = F_89 ( V_19 , & V_122 ) ;
}
return V_123 ;
}
static void T_8 F_90 ( void )
{
unsigned int V_19 , V_134 , V_135 ;
struct V_115 * V_93 ;
V_93 = F_82 () ;
if ( ! V_93 )
F_75 ( L_5 ) ;
if ( V_93 -> V_128 ) {
for ( V_19 = 0 ; V_19 < V_93 -> V_120 ; V_19 ++ ) {
if ( V_93 -> V_19 [ V_19 ] . V_10 != V_104 )
continue;
V_129 = V_93 -> V_19 [ V_19 ] . type ;
break;
}
}
V_134 = V_135 = 0 ;
for ( V_19 = 0 ; V_19 < V_93 -> V_120 ; V_19 ++ ) {
if ( V_93 -> V_128 && V_93 -> V_19 [ V_19 ] . type != V_129 )
continue;
if ( V_19 < V_93 -> V_119 ) {
F_71 ( V_134 , V_93 -> V_19 [ V_19 ] . V_10 ) ;
V_134 ++ ;
} else
V_135 ++ ;
}
F_91 ( L_6 , V_134 , V_135 ) ;
F_92 () ;
F_85 ( V_93 , 0 ) ;
F_93 () ;
F_94 ( V_93 ) ;
}
static void T_5 F_95 ( void * V_136 )
{
V_35 . V_137 = F_44 () ;
V_35 . V_67 = ( unsigned long ) V_67 ;
V_35 . V_68 = ( unsigned long ) V_138 ;
V_35 . V_69 = 0 ;
V_35 . V_70 = - 1UL ;
F_96 ( V_35 . V_56 ) ;
F_68 ( V_35 . V_55 , 0 , 15 ) ;
F_33 ( V_74 | V_81 ) ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 () ;
F_102 ( F_51 () ) ;
F_103 ( F_51 () , true ) ;
F_54 ( V_139 ) ;
F_104 () ;
F_105 () ;
}
int T_5 F_106 ( unsigned int V_19 , struct V_59 * V_140 )
{
struct V_8 * V_8 ;
int V_141 ;
V_8 = V_20 + V_19 ;
if ( V_8 -> V_130 != V_132 )
return - V_112 ;
if ( F_4 ( V_8 , V_142 , 0 ) !=
V_111 )
return - V_112 ;
V_141 = F_12 ( V_8 , V_19 ) ;
if ( V_141 )
return V_141 ;
F_22 ( V_8 , V_19 ) ;
F_26 ( V_8 , V_140 ) ;
F_29 ( V_8 , F_95 , NULL ) ;
while ( ! F_107 ( V_19 ) )
F_3 () ;
return 0 ;
}
static int T_8 F_108 ( char * V_143 )
{
int V_144 , V_19 ;
if ( F_109 ( V_143 , 0 , & V_144 ) < 0 )
return 0 ;
F_110 ( F_111 ( 0 ) ) ;
for ( V_19 = 1 ; V_19 < V_144 && V_19 < V_127 ; V_19 ++ )
F_112 ( V_19 , true ) ;
return 0 ;
}
int F_113 ( void )
{
unsigned long V_96 [ 16 ] ;
F_103 ( F_51 () , false ) ;
F_114 () ;
F_24 ( V_96 , 0 , 15 ) ;
V_96 [ 0 ] &= ~ 0x0000ee70UL ;
V_96 [ 6 ] &= ~ 0xff000000UL ;
V_96 [ 14 ] &= ~ 0x1f000000UL ;
F_68 ( V_96 , 0 , 15 ) ;
return 0 ;
}
void F_115 ( unsigned int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_116 ( & V_44 . V_45 . V_46 ) ;
}
void T_9 F_117 ( void )
{
F_118 () ;
F_4 ( V_20 + F_51 () , V_75 , 0 ) ;
for (; ; ) ;
}
void T_8 F_119 ( unsigned int V_145 )
{
if ( F_120 ( 0x1201 , F_53 ) != 0 )
F_75 ( L_7 ) ;
if ( F_120 ( 0x1202 , F_53 ) != 0 )
F_75 ( L_8 ) ;
F_90 () ;
}
void T_8 F_121 ( void )
{
struct V_8 * V_8 = V_20 ;
V_104 = F_32 () ;
V_8 -> V_130 = V_132 ;
V_8 -> V_10 = V_104 ;
V_8 -> V_27 = (struct V_25 * ) ( unsigned long ) F_122 () ;
V_8 -> V_31 = V_35 . V_31 - V_36 ;
V_8 -> V_33 = V_35 . V_33 - V_37 ;
V_35 . V_47 = V_48 [ 0 ] ;
F_80 ( 0 , V_133 ) ;
F_87 ( 0 , true ) ;
F_103 ( 0 , true ) ;
}
void T_8 F_123 ( unsigned int V_145 )
{
}
void T_8 F_124 ( void )
{
V_35 . V_38 = 0 ;
}
int F_125 ( unsigned int V_146 )
{
return 0 ;
}
static T_10 F_126 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
T_10 V_152 ;
F_127 ( & V_153 ) ;
V_152 = sprintf ( V_151 , L_9 , V_20 [ V_148 -> V_154 ] . V_130 ) ;
F_128 ( & V_153 ) ;
return V_152 ;
}
static T_10 F_129 ( struct V_147 * V_148 ,
struct V_149 * V_150 ,
const char * V_151 , T_11 V_152 )
{
struct V_8 * V_8 ;
int V_19 , V_113 , V_141 ;
char V_155 ;
if ( sscanf ( V_151 , L_10 , & V_113 , & V_155 ) != 1 )
return - V_156 ;
if ( V_113 != 0 && V_113 != 1 )
return - V_156 ;
F_92 () ;
F_127 ( & V_153 ) ;
V_141 = - V_157 ;
V_19 = V_148 -> V_154 ;
if ( F_107 ( V_19 ) || V_19 == 0 )
goto V_34;
V_8 = V_20 + V_19 ;
V_141 = 0 ;
switch ( V_113 ) {
case 0 :
if ( V_8 -> V_130 != V_132 )
break;
V_141 = F_130 ( V_8 -> V_10 ) ;
if ( V_141 )
break;
V_8 -> V_130 = V_131 ;
F_80 ( V_19 , V_133 ) ;
F_131 () ;
break;
case 1 :
if ( V_8 -> V_130 != V_131 )
break;
V_141 = F_132 ( V_8 -> V_10 ) ;
if ( V_141 )
break;
V_8 -> V_130 = V_132 ;
F_80 ( V_19 , V_133 ) ;
F_131 () ;
break;
default:
break;
}
V_34:
F_128 ( & V_153 ) ;
F_93 () ;
return V_141 ? V_141 : V_152 ;
}
static T_10 F_133 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
return sprintf ( V_151 , L_9 , V_20 [ V_148 -> V_154 ] . V_10 ) ;
}
static T_10 F_134 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
struct V_158 * V_159 = & F_135 ( V_160 , V_148 -> V_154 ) ;
unsigned long long V_161 ;
unsigned int V_162 ;
do {
V_162 = F_136 ( V_159 -> V_162 ) ;
V_161 = F_136 ( V_159 -> V_161 ) ;
if ( F_136 ( V_159 -> V_163 ) )
V_161 ++ ;
} while ( ( V_162 & 1 ) || ( V_159 -> V_162 != V_162 ) );
return sprintf ( V_151 , L_11 , V_161 ) ;
}
static T_10 F_137 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
struct V_158 * V_159 = & F_135 ( V_160 , V_148 -> V_154 ) ;
unsigned long long V_164 , V_165 , V_166 , V_167 ;
unsigned int V_162 ;
do {
V_164 = F_44 () ;
V_162 = F_136 ( V_159 -> V_162 ) ;
V_165 = F_136 ( V_159 -> V_165 ) ;
V_166 = F_136 ( V_159 -> V_163 ) ;
V_167 = F_136 ( V_159 -> V_168 ) ;
} while ( ( V_162 & 1 ) || ( V_159 -> V_162 != V_162 ) );
V_165 += V_166 ? ( ( V_167 ? : V_164 ) - V_166 ) : 0 ;
return sprintf ( V_151 , L_11 , V_165 >> 12 ) ;
}
static int T_5 F_138 ( struct V_169 * V_170 ,
unsigned long V_171 , void * V_172 )
{
unsigned int V_19 = ( unsigned int ) ( long ) V_172 ;
struct V_19 * V_173 = & V_20 [ V_19 ] . V_19 ;
struct V_147 * V_143 = & V_173 -> V_148 ;
int V_174 = 0 ;
switch ( V_171 & ~ V_175 ) {
case V_176 :
V_174 = F_139 ( & V_143 -> V_177 , & V_178 ) ;
break;
case V_179 :
F_140 ( & V_143 -> V_177 , & V_178 ) ;
break;
}
return F_141 ( V_174 ) ;
}
static int T_5 F_88 ( int V_19 )
{
struct V_19 * V_173 = & V_20 [ V_19 ] . V_19 ;
struct V_147 * V_143 = & V_173 -> V_148 ;
int V_141 ;
V_173 -> V_180 = 1 ;
V_141 = F_142 ( V_173 , V_19 ) ;
if ( V_141 )
goto V_34;
V_141 = F_139 ( & V_143 -> V_177 , & V_181 ) ;
if ( V_141 )
goto V_182;
if ( F_107 ( V_19 ) ) {
V_141 = F_139 ( & V_143 -> V_177 , & V_178 ) ;
if ( V_141 )
goto V_183;
}
V_141 = F_143 ( V_173 ) ;
if ( V_141 )
goto V_184;
return 0 ;
V_184:
if ( F_107 ( V_19 ) )
F_140 ( & V_143 -> V_177 , & V_178 ) ;
V_183:
F_140 ( & V_143 -> V_177 , & V_181 ) ;
V_182:
#ifdef F_144
F_145 ( V_173 ) ;
#endif
V_34:
return V_141 ;
}
int T_12 F_146 ( void )
{
struct V_115 * V_93 ;
int V_123 ;
V_93 = F_82 () ;
if ( ! V_93 )
return - V_43 ;
F_92 () ;
F_127 ( & V_153 ) ;
V_123 = F_85 ( V_93 , 1 ) ;
F_128 ( & V_153 ) ;
F_93 () ;
F_94 ( V_93 ) ;
if ( V_123 )
F_147 () ;
return 0 ;
}
static T_10 T_12 F_148 ( struct V_147 * V_148 ,
struct V_149 * V_150 ,
const char * V_151 ,
T_11 V_152 )
{
int V_141 ;
V_141 = F_146 () ;
return V_141 ? V_141 : V_152 ;
}
static int T_8 F_149 ( void )
{
int V_19 , V_141 ;
F_150 ( F_138 , 0 ) ;
#ifdef F_144
V_141 = F_151 ( V_185 . V_186 , & V_187 ) ;
if ( V_141 )
return V_141 ;
#endif
F_39 (cpu) {
V_141 = F_88 ( V_19 ) ;
if ( V_141 )
return V_141 ;
}
return 0 ;
}
