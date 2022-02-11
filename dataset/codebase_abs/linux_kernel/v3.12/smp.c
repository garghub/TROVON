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
static int F_12 ( struct V_8 * V_8 , int V_19 )
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
static void F_43 ( T_5 * V_17 )
{
T_6 V_81 ;
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
T_5 V_17 ;
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
}
static void F_58 ( struct V_88 V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
F_59 ( V_88 . V_91 == 0x1202 ? V_92 : V_93 ) ;
F_53 () ;
}
void F_60 ( const struct V_17 * V_18 )
{
int V_19 ;
F_9 (cpu, mask)
F_10 ( V_20 + V_19 , V_87 ) ;
}
void F_61 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_87 ) ;
}
static void F_62 ( void * V_94 )
{
F_63 () ;
}
void F_64 ( void )
{
F_65 ( F_62 , NULL , 1 ) ;
}
void F_66 ( int V_19 )
{
F_10 ( V_20 + V_19 , V_86 ) ;
}
static void F_67 ( void * V_94 )
{
struct V_95 * V_96 = V_94 ;
unsigned long V_97 [ 16 ] ;
F_24 ( V_97 , 0 , 15 ) ;
V_97 [ V_96 -> V_98 ] = ( V_97 [ V_96 -> V_98 ] & V_96 -> V_99 ) | V_96 -> V_100 ;
F_68 ( V_97 , 0 , 15 ) ;
}
void F_69 ( int V_98 , int V_101 )
{
struct V_95 V_102 = { 1UL << V_101 , - 1UL , V_98 } ;
F_65 ( F_67 , & V_102 , 1 ) ;
}
void F_70 ( int V_98 , int V_101 )
{
struct V_95 V_102 = { 0 , ~ ( 1UL << V_101 ) , V_98 } ;
F_65 ( F_67 , & V_102 , 1 ) ;
}
static void T_7 F_71 ( int V_19 , T_1 V_10 )
{
void * V_26 = V_20 [ 0 ] . V_27 ;
struct V_103 * V_103 ;
if ( F_72 () )
return;
if ( ! V_104 && ( V_10 == V_105 ||
V_106 . type != V_107 ) )
return;
if ( V_19 >= V_108 ) {
F_73 ( L_2
L_3 , V_19 , V_108 - 1 ) ;
return;
}
V_103 = F_74 ( sizeof( struct V_103 ) , V_28 ) ;
if ( ! V_103 )
F_75 ( L_4 ) ;
V_109 [ V_19 ] = V_103 ;
#ifdef F_76
if ( V_10 == V_105 ) {
F_77 ( 1 , ( void * ) V_103 , sizeof( * V_103 ) ,
V_110 - V_39 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_111 , 0 , NULL ) ;
F_78 ( V_103 , V_26 + V_110 , sizeof( * V_103 ) ) ;
}
int F_79 ( int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
if ( F_2 ( V_8 -> V_10 , V_111 ,
0 , NULL ) != V_112 )
return - V_113 ;
return 0 ;
}
static inline void F_71 ( int V_19 , T_1 V_10 ) { }
void F_80 ( int V_19 , int V_114 )
{
V_20 [ V_19 ] . V_115 = V_114 ;
}
int F_81 ( int V_19 )
{
return V_20 [ V_19 ] . V_115 ;
}
static struct V_116 * F_82 ( void )
{
static int V_117 ;
struct V_116 * V_94 ;
int V_10 ;
V_94 = F_83 ( sizeof( * V_94 ) , V_28 ) ;
if ( V_94 && ( V_117 || F_84 ( V_94 ) ) ) {
V_117 = 1 ;
for ( V_10 = 0 ; V_10 <= V_118 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_12 , 0 , NULL ) ==
V_119 )
continue;
V_94 -> V_19 [ V_94 -> V_120 ] . V_10 = V_10 ;
V_94 -> V_120 ++ ;
}
V_94 -> V_121 = V_94 -> V_120 ;
}
return V_94 ;
}
static int F_85 ( struct V_116 * V_94 , int V_122 )
{
struct V_8 * V_8 ;
T_5 V_123 ;
int V_19 , V_124 , V_125 ;
V_124 = 0 ;
F_86 ( & V_123 , V_126 , V_127 ) ;
V_19 = F_36 ( & V_123 ) ;
for ( V_125 = 0 ; ( V_125 < V_94 -> V_121 ) && ( V_19 < V_128 ) ; V_125 ++ ) {
if ( V_94 -> V_129 && V_94 -> V_19 [ V_125 ] . type != V_130 )
continue;
if ( F_8 ( V_127 , V_94 -> V_19 [ V_125 ] . V_10 ) )
continue;
V_8 = V_20 + V_19 ;
V_8 -> V_10 = V_94 -> V_19 [ V_125 ] . V_10 ;
V_8 -> V_131 = ( V_125 >= V_94 -> V_120 ) ?
V_132 : V_133 ;
F_80 ( V_19 , V_134 ) ;
F_87 ( V_19 , true ) ;
if ( V_122 && F_88 ( V_19 ) != 0 )
F_87 ( V_19 , false ) ;
else
V_124 ++ ;
V_19 = F_89 ( V_19 , & V_123 ) ;
}
return V_124 ;
}
static void T_7 F_90 ( void )
{
unsigned int V_19 , V_135 , V_136 ;
struct V_116 * V_94 ;
V_94 = F_82 () ;
if ( ! V_94 )
F_75 ( L_5 ) ;
if ( V_94 -> V_129 ) {
for ( V_19 = 0 ; V_19 < V_94 -> V_121 ; V_19 ++ ) {
if ( V_94 -> V_19 [ V_19 ] . V_10 != V_105 )
continue;
V_130 = V_94 -> V_19 [ V_19 ] . type ;
break;
}
}
V_135 = V_136 = 0 ;
for ( V_19 = 0 ; V_19 < V_94 -> V_121 ; V_19 ++ ) {
if ( V_94 -> V_129 && V_94 -> V_19 [ V_19 ] . type != V_130 )
continue;
if ( V_19 < V_94 -> V_120 ) {
F_71 ( V_135 , V_94 -> V_19 [ V_19 ] . V_10 ) ;
V_135 ++ ;
} else
V_136 ++ ;
}
F_91 ( L_6 , V_135 , V_136 ) ;
F_92 () ;
F_85 ( V_94 , 0 ) ;
F_93 () ;
F_94 ( V_94 ) ;
}
static void F_95 ( void * V_137 )
{
V_35 . V_138 = F_44 () ;
V_35 . V_69 = ( unsigned long ) V_69 ;
V_35 . V_70 = ( unsigned long ) V_139 ;
V_35 . V_71 = 0 ;
V_35 . V_72 = - 1UL ;
F_96 ( V_35 . V_58 ) ;
F_68 ( V_35 . V_57 , 0 , 15 ) ;
F_33 ( V_76 | V_83 ) ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 () ;
F_102 ( F_51 () ) ;
F_103 ( F_51 () , true ) ;
F_59 ( V_140 ) ;
F_104 () ;
F_105 ( V_141 ) ;
}
int F_106 ( unsigned int V_19 , struct V_61 * V_142 )
{
struct V_8 * V_8 ;
int V_143 ;
V_8 = V_20 + V_19 ;
if ( V_8 -> V_131 != V_133 )
return - V_113 ;
if ( F_4 ( V_8 , V_144 , 0 ) !=
V_112 )
return - V_113 ;
V_143 = F_12 ( V_8 , V_19 ) ;
if ( V_143 )
return V_143 ;
F_22 ( V_8 , V_19 ) ;
F_26 ( V_8 , V_142 ) ;
F_29 ( V_8 , F_95 , NULL ) ;
while ( ! F_107 ( V_19 ) )
F_3 () ;
return 0 ;
}
static int T_7 F_108 ( char * V_145 )
{
int V_146 , V_19 ;
if ( F_109 ( V_145 , 0 , & V_146 ) < 0 )
return 0 ;
F_110 ( F_111 ( 0 ) ) ;
for ( V_19 = 1 ; V_19 < V_146 && V_19 < V_128 ; V_19 ++ )
F_112 ( V_19 , true ) ;
return 0 ;
}
int F_113 ( void )
{
unsigned long V_97 [ 16 ] ;
F_53 () ;
F_103 ( F_51 () , false ) ;
F_114 () ;
F_24 ( V_97 , 0 , 15 ) ;
V_97 [ 0 ] &= ~ 0x0000ee70UL ;
V_97 [ 6 ] &= ~ 0xff000000UL ;
V_97 [ 14 ] &= ~ 0x1f000000UL ;
F_68 ( V_97 , 0 , 15 ) ;
return 0 ;
}
void F_115 ( unsigned int V_19 )
{
struct V_8 * V_8 ;
V_8 = V_20 + V_19 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_116 ( & V_46 . V_47 . V_48 ) ;
}
void T_8 F_117 ( void )
{
F_118 () ;
F_4 ( V_20 + F_51 () , V_77 , 0 ) ;
for (; ; ) ;
}
void T_7 F_119 ( unsigned int V_147 )
{
if ( F_120 ( 0x1201 , F_58 ) != 0 )
F_75 ( L_7 ) ;
if ( F_120 ( 0x1202 , F_58 ) != 0 )
F_75 ( L_8 ) ;
F_90 () ;
}
void T_7 F_121 ( void )
{
struct V_8 * V_8 = V_20 ;
V_105 = F_32 () ;
V_8 -> V_131 = V_133 ;
V_8 -> V_10 = V_105 ;
V_8 -> V_27 = (struct V_25 * ) ( unsigned long ) F_122 () ;
V_8 -> V_31 = V_35 . V_31 - V_36
+ V_37 + sizeof( struct V_38 ) ;
V_8 -> V_33 = V_35 . V_33 - V_39
+ V_37 + sizeof( struct V_38 ) ;
V_35 . V_49 = V_50 [ 0 ] ;
F_80 ( 0 , V_134 ) ;
F_87 ( 0 , true ) ;
F_103 ( 0 , true ) ;
}
void T_7 F_123 ( unsigned int V_147 )
{
}
void T_7 F_124 ( void )
{
V_35 . V_40 = 0 ;
}
int F_125 ( unsigned int V_148 )
{
return 0 ;
}
static T_9 F_126 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_153 )
{
T_9 V_154 ;
F_127 ( & V_155 ) ;
V_154 = sprintf ( V_153 , L_9 , V_20 [ V_150 -> V_156 ] . V_131 ) ;
F_128 ( & V_155 ) ;
return V_154 ;
}
static T_9 F_129 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
const char * V_153 , T_10 V_154 )
{
struct V_8 * V_8 ;
int V_19 , V_114 , V_143 ;
char V_157 ;
if ( sscanf ( V_153 , L_10 , & V_114 , & V_157 ) != 1 )
return - V_158 ;
if ( V_114 != 0 && V_114 != 1 )
return - V_158 ;
F_92 () ;
F_127 ( & V_155 ) ;
V_143 = - V_159 ;
V_19 = V_150 -> V_156 ;
if ( F_107 ( V_19 ) || V_19 == 0 )
goto V_34;
V_8 = V_20 + V_19 ;
V_143 = 0 ;
switch ( V_114 ) {
case 0 :
if ( V_8 -> V_131 != V_133 )
break;
V_143 = F_130 ( V_8 -> V_10 ) ;
if ( V_143 )
break;
V_8 -> V_131 = V_132 ;
F_80 ( V_19 , V_134 ) ;
F_131 () ;
break;
case 1 :
if ( V_8 -> V_131 != V_132 )
break;
V_143 = F_132 ( V_8 -> V_10 ) ;
if ( V_143 )
break;
V_8 -> V_131 = V_133 ;
F_80 ( V_19 , V_134 ) ;
F_131 () ;
break;
default:
break;
}
V_34:
F_128 ( & V_155 ) ;
F_93 () ;
return V_143 ? V_143 : V_154 ;
}
static T_9 F_133 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_153 )
{
return sprintf ( V_153 , L_9 , V_20 [ V_150 -> V_156 ] . V_10 ) ;
}
static T_9 F_134 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_160 * V_161 = & F_135 ( V_162 , V_150 -> V_156 ) ;
unsigned long long V_163 ;
unsigned int V_164 ;
do {
V_164 = F_136 ( V_161 -> V_164 ) ;
V_163 = F_136 ( V_161 -> V_163 ) ;
if ( F_136 ( V_161 -> V_165 ) )
V_163 ++ ;
} while ( ( V_164 & 1 ) || ( V_161 -> V_164 != V_164 ) );
return sprintf ( V_153 , L_11 , V_163 ) ;
}
static T_9 F_137 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_160 * V_161 = & F_135 ( V_162 , V_150 -> V_156 ) ;
unsigned long long V_166 , V_167 , V_168 , V_169 ;
unsigned int V_164 ;
do {
V_166 = F_44 () ;
V_164 = F_136 ( V_161 -> V_164 ) ;
V_167 = F_136 ( V_161 -> V_167 ) ;
V_168 = F_136 ( V_161 -> V_165 ) ;
V_169 = F_136 ( V_161 -> V_170 ) ;
} while ( ( V_164 & 1 ) || ( V_161 -> V_164 != V_164 ) );
V_167 += V_168 ? ( ( V_169 ? : V_166 ) - V_168 ) : 0 ;
return sprintf ( V_153 , L_11 , V_167 >> 12 ) ;
}
static int F_138 ( struct V_171 * V_172 , unsigned long V_173 ,
void * V_174 )
{
unsigned int V_19 = ( unsigned int ) ( long ) V_174 ;
struct V_19 * V_175 = & V_20 [ V_19 ] . V_19 ;
struct V_149 * V_145 = & V_175 -> V_150 ;
int V_176 = 0 ;
switch ( V_173 & ~ V_177 ) {
case V_178 :
V_176 = F_139 ( & V_145 -> V_179 , & V_180 ) ;
break;
case V_181 :
F_140 ( & V_145 -> V_179 , & V_180 ) ;
break;
}
return F_141 ( V_176 ) ;
}
static int F_88 ( int V_19 )
{
struct V_19 * V_175 = & V_20 [ V_19 ] . V_19 ;
struct V_149 * V_145 = & V_175 -> V_150 ;
int V_143 ;
V_175 -> V_182 = 1 ;
V_143 = F_142 ( V_175 , V_19 ) ;
if ( V_143 )
goto V_34;
V_143 = F_139 ( & V_145 -> V_179 , & V_183 ) ;
if ( V_143 )
goto V_184;
if ( F_107 ( V_19 ) ) {
V_143 = F_139 ( & V_145 -> V_179 , & V_180 ) ;
if ( V_143 )
goto V_185;
}
V_143 = F_143 ( V_175 ) ;
if ( V_143 )
goto V_186;
return 0 ;
V_186:
if ( F_107 ( V_19 ) )
F_140 ( & V_145 -> V_179 , & V_180 ) ;
V_185:
F_140 ( & V_145 -> V_179 , & V_183 ) ;
V_184:
#ifdef F_144
F_145 ( V_175 ) ;
#endif
V_34:
return V_143 ;
}
int T_11 F_146 ( void )
{
struct V_116 * V_94 ;
int V_124 ;
V_94 = F_82 () ;
if ( ! V_94 )
return - V_45 ;
F_92 () ;
F_127 ( & V_155 ) ;
V_124 = F_85 ( V_94 , 1 ) ;
F_128 ( & V_155 ) ;
F_93 () ;
F_94 ( V_94 ) ;
if ( V_124 )
F_147 () ;
return 0 ;
}
static T_9 T_11 F_148 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
const char * V_153 ,
T_10 V_154 )
{
int V_143 ;
V_143 = F_146 () ;
return V_143 ? V_143 : V_154 ;
}
static int T_7 F_149 ( void )
{
int V_19 , V_143 ;
F_150 ( F_138 , 0 ) ;
#ifdef F_144
V_143 = F_151 ( V_187 . V_188 , & V_189 ) ;
if ( V_143 )
return V_143 ;
#endif
F_39 (cpu) {
V_143 = F_88 ( V_19 ) ;
if ( V_143 )
return V_143 ;
}
return 0 ;
}
