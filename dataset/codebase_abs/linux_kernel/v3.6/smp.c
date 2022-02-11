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
V_6 = F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_6 != V_7 )
return V_6 ;
F_3 () ;
}
}
static int F_4 ( struct V_8 * V_8 , T_2 V_2 , T_3 V_3 )
{
int V_6 , V_9 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
V_6 = F_1 ( V_8 -> V_10 , V_2 , V_3 , & V_8 -> V_4 ) ;
if ( V_6 != V_7 )
break;
if ( V_9 >= 3 )
F_5 ( 10 ) ;
}
return V_6 ;
}
static inline int F_6 ( struct V_8 * V_8 )
{
if ( F_1 ( V_8 -> V_10 , V_11 ,
0 , & V_8 -> V_4 ) != V_12 )
return 0 ;
return ! ! ( V_8 -> V_4 & ( V_13 | V_14 ) ) ;
}
static inline int F_7 ( struct V_8 * V_8 )
{
if ( F_1 ( V_8 -> V_10 , V_15 ,
0 , & V_8 -> V_4 ) != V_12 )
return 1 ;
return 0 ;
}
static struct V_8 * F_8 ( const struct V_16 * V_17 , int V_10 )
{
int V_18 ;
F_9 (cpu, mask)
if ( V_19 [ V_18 ] . V_10 == V_10 )
return V_19 + V_18 ;
return NULL ;
}
static void F_10 ( struct V_8 * V_8 , int V_20 )
{
int V_2 ;
F_11 ( V_20 , & V_8 -> V_21 ) ;
V_2 = F_7 ( V_8 ) ?
V_22 : V_23 ;
F_4 ( V_8 , V_2 , 0 ) ;
}
static int T_5 F_12 ( struct V_8 * V_8 , int V_18 )
{
struct V_24 * V_25 ;
if ( V_8 != & V_19 [ 0 ] ) {
V_8 -> V_26 = (struct V_24 * )
F_13 ( V_27 | V_28 , V_29 ) ;
V_8 -> V_30 = F_13 ( V_27 , V_31 ) ;
V_8 -> V_32 = F_14 ( V_27 ) ;
if ( ! V_8 -> V_26 || ! V_8 -> V_32 || ! V_8 -> V_30 )
goto V_33;
}
V_25 = V_8 -> V_26 ;
memcpy ( V_25 , & V_34 , 512 ) ;
memset ( ( char * ) V_25 + 512 , 0 , sizeof( * V_25 ) - 512 ) ;
V_25 -> V_30 = V_8 -> V_30 + V_35 ;
V_25 -> V_32 = V_8 -> V_32 + V_36 ;
V_25 -> V_37 = V_18 ;
#ifndef F_15
if ( V_38 ) {
V_25 -> V_39 = F_16 ( V_27 ) ;
if ( ! V_25 -> V_39 )
goto V_33;
}
#else
if ( F_17 ( V_25 ) )
goto V_33;
#endif
V_40 [ V_18 ] = V_25 ;
F_4 ( V_8 , V_41 , ( T_3 ) ( unsigned long ) V_25 ) ;
return 0 ;
V_33:
if ( V_8 != & V_19 [ 0 ] ) {
F_18 ( V_8 -> V_32 ) ;
F_19 ( V_8 -> V_30 , V_31 ) ;
F_19 ( ( unsigned long ) V_8 -> V_26 , V_29 ) ;
}
return - V_42 ;
}
static void F_20 ( struct V_8 * V_8 )
{
F_4 ( V_8 , V_41 , 0 ) ;
V_40 [ V_8 - V_19 ] = NULL ;
#ifndef F_15
if ( V_38 ) {
struct V_24 * V_25 = V_8 -> V_26 ;
F_18 ( ( unsigned long ) V_25 -> V_39 ) ;
V_25 -> V_39 = 0 ;
}
#else
F_21 ( V_8 -> V_26 ) ;
#endif
if ( V_8 != & V_19 [ 0 ] ) {
F_18 ( V_8 -> V_32 ) ;
F_19 ( V_8 -> V_30 , V_31 ) ;
F_19 ( ( unsigned long ) V_8 -> V_26 , V_29 ) ;
}
}
static void F_22 ( struct V_8 * V_8 , int V_18 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
F_23 ( & V_43 . V_44 . V_45 ) ;
V_25 -> V_37 = V_18 ;
V_25 -> V_46 = V_47 [ V_18 ] ;
V_25 -> V_48 = V_34 . V_48 ;
V_25 -> V_49 = V_34 . V_49 ;
V_25 -> V_50 = V_34 . V_50 ;
V_25 -> V_51 = V_25 -> V_52 = V_25 -> V_53 = 0 ;
F_24 ( V_25 -> V_54 , 0 , 15 ) ;
F_25 ( ( unsigned int * ) V_25 -> V_55 ) ;
memcpy ( V_25 -> V_56 , V_34 . V_56 ,
V_57 / 8 ) ;
}
static void F_26 ( struct V_8 * V_8 , struct V_58 * V_59 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
struct V_60 * V_61 = F_27 ( V_59 ) ;
V_25 -> V_62 = ( unsigned long ) F_28 ( V_59 ) + V_63 ;
V_25 -> V_60 = ( unsigned long ) F_27 ( V_59 ) ;
V_25 -> V_64 = ( unsigned long ) V_59 ;
V_25 -> V_51 = V_61 -> V_51 ;
V_25 -> V_52 = V_61 -> V_52 ;
V_25 -> V_53 = 0 ;
}
static void F_29 ( struct V_8 * V_8 , void (* F_30)( void * ) , void * V_65 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
V_25 -> V_66 = V_25 -> V_62 ;
V_25 -> V_67 = ( unsigned long ) F_30 ;
V_25 -> V_68 = ( unsigned long ) V_65 ;
V_25 -> V_69 = - 1UL ;
F_4 ( V_8 , V_70 , 0 ) ;
}
static void F_31 ( struct V_8 * V_8 , void (* F_30)( void * ) ,
void * V_65 , unsigned long V_71 )
{
struct V_24 * V_25 = V_40 [ V_8 - V_19 ] ;
unsigned long V_72 = F_32 () ;
F_33 ( V_73 ) ;
if ( V_8 -> V_10 == V_72 )
F_30 ( V_65 ) ;
F_4 ( V_8 , V_74 , 0 ) ;
F_34 ( V_25 -> V_66 , V_71 ) ;
F_34 ( V_25 -> V_67 , ( unsigned long ) F_30 ) ;
F_34 ( V_25 -> V_68 , ( unsigned long ) V_65 ) ;
F_34 ( V_25 -> V_69 , V_72 ) ;
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
void F_35 ( void (* F_30)( void * ) , void * V_65 )
{
struct V_8 * V_8 ;
V_8 = F_8 ( V_75 , F_32 () ) ;
if ( ! V_8 )
V_8 = V_19 + F_36 ( V_75 ) ;
F_31 ( V_8 , F_30 , V_65 , ( unsigned long ) V_66 ) ;
}
void F_37 ( void (* F_30)( void * ) , void * V_65 )
{
F_31 ( & V_19 [ 0 ] , F_30 , V_65 ,
V_19 -> V_32 + V_36 ) ;
}
int F_38 ( T_1 V_10 )
{
int V_18 ;
F_39 (cpu)
if ( V_19 [ V_18 ] . V_10 == V_10 )
return V_18 ;
return - 1 ;
}
int F_40 ( int V_18 )
{
return F_7 ( V_19 + V_18 ) ;
}
void F_41 ( void )
{
if ( V_76 )
asm volatile("diag 0,0,0x44");
}
void F_42 ( int V_18 )
{
if ( V_77 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_76 )
asm volatile("diag 0,0,0x44");
}
void F_43 ( T_6 * V_16 )
{
T_7 V_78 ;
int V_18 ;
V_78 = F_44 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_8 * V_8 = V_19 + V_18 ;
F_11 ( V_79 , & V_8 -> V_21 ) ;
while ( F_1 ( V_8 -> V_10 , V_23 ,
0 , NULL ) == V_7 &&
F_44 () < V_78 )
F_3 () ;
}
while ( F_44 () < V_78 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_19 + V_18 ) )
F_45 ( V_18 , V_16 ) ;
if ( F_46 ( V_16 ) )
break;
F_3 () ;
}
}
void F_47 ( void )
{
T_6 V_16 ;
int V_18 ;
F_33 ( V_73 | V_80 ) ;
F_48 () ;
F_49 () ;
F_50 ( & V_16 , V_75 ) ;
F_45 ( F_51 () , & V_16 ) ;
if ( V_81 )
F_43 ( & V_16 ) ;
F_9 (cpu, &cpumask) {
struct V_8 * V_8 = V_19 + V_18 ;
F_4 ( V_8 , V_74 , 0 ) ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
}
}
void F_52 ( void )
{
F_4 ( V_19 + F_51 () , V_74 , 0 ) ;
for (; ; ) ;
}
static void F_53 ( struct V_82 V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
unsigned long V_85 ;
int V_18 ;
V_18 = F_51 () ;
if ( V_82 . V_86 == 0x1202 )
F_54 ( V_18 ) . V_87 [ V_88 ] ++ ;
else
F_54 ( V_18 ) . V_87 [ V_89 ] ++ ;
V_85 = F_55 ( & V_19 [ V_18 ] . V_21 , 0 ) ;
if ( F_56 ( V_79 , & V_85 ) )
F_52 () ;
if ( F_56 ( V_90 , & V_85 ) )
F_57 () ;
if ( F_56 ( V_91 , & V_85 ) )
F_58 () ;
if ( F_56 ( V_92 , & V_85 ) )
F_59 () ;
}
void F_60 ( const struct V_16 * V_17 )
{
int V_18 ;
F_9 (cpu, mask)
F_10 ( V_19 + V_18 , V_91 ) ;
}
void F_61 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_92 ) ;
}
static void F_62 ( void * V_93 )
{
F_63 () ;
}
void F_64 ( void )
{
F_65 ( F_62 , NULL , 1 ) ;
}
void F_66 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_90 ) ;
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
static void T_8 F_71 ( int V_18 , T_1 V_10 )
{
void * V_25 = V_19 [ 0 ] . V_26 ;
struct V_102 * V_102 ;
if ( F_72 () )
return;
if ( ! V_103 && ( V_10 == V_104 ||
V_105 . type != V_106 ) )
return;
if ( V_18 >= V_107 ) {
F_73 ( L_2
L_3 , V_18 , V_107 - 1 ) ;
return;
}
V_102 = F_74 ( sizeof( struct V_102 ) , V_27 ) ;
if ( ! V_102 )
F_75 ( L_4 ) ;
V_108 [ V_18 ] = V_102 ;
#ifdef F_76
if ( V_10 == V_104 ) {
F_77 ( 1 , ( void * ) V_102 , sizeof( * V_102 ) ,
V_109 - V_36 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_110 , 0 , NULL ) ;
F_78 ( V_102 , V_25 + V_109 , sizeof( * V_102 ) ) ;
}
int F_79 ( int V_18 )
{
struct V_8 * V_8 ;
V_8 = V_19 + V_18 ;
if ( F_2 ( V_8 -> V_10 , V_110 ,
0 , NULL ) != V_111 )
return - V_112 ;
return 0 ;
}
static inline void F_71 ( int V_18 , T_1 V_10 ) { }
static struct V_113 * F_80 ( void )
{
static int V_114 ;
struct V_113 * V_93 ;
int V_10 ;
V_93 = F_81 ( sizeof( * V_93 ) , V_27 ) ;
if ( V_93 && ( V_114 || F_82 ( V_93 ) ) ) {
V_114 = 1 ;
for ( V_10 = 0 ; V_10 <= V_115 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_11 , 0 , NULL ) ==
V_116 )
continue;
V_93 -> V_18 [ V_93 -> V_117 ] . V_10 = V_10 ;
V_93 -> V_117 ++ ;
}
V_93 -> V_118 = V_93 -> V_117 ;
}
return V_93 ;
}
static int T_9 F_83 ( struct V_113 * V_93 ,
int V_119 )
{
struct V_8 * V_8 ;
T_6 V_120 ;
int V_18 , V_121 , V_122 ;
V_121 = 0 ;
F_84 ( & V_120 , V_123 , V_124 ) ;
V_18 = F_36 ( & V_120 ) ;
for ( V_122 = 0 ; ( V_122 < V_93 -> V_118 ) && ( V_18 < V_125 ) ; V_122 ++ ) {
if ( V_93 -> V_126 && V_93 -> V_18 [ V_122 ] . type != V_127 )
continue;
if ( F_8 ( V_124 , V_93 -> V_18 [ V_122 ] . V_10 ) )
continue;
V_8 = V_19 + V_18 ;
V_8 -> V_10 = V_93 -> V_18 [ V_122 ] . V_10 ;
V_8 -> V_128 = ( V_18 >= V_93 -> V_117 ) ?
V_129 : V_130 ;
F_85 ( V_18 , V_131 ) ;
F_86 ( V_18 , true ) ;
if ( V_119 && F_87 ( V_18 ) != 0 )
F_86 ( V_18 , false ) ;
else
V_121 ++ ;
V_18 = F_88 ( V_18 , & V_120 ) ;
}
return V_121 ;
}
static void T_8 F_89 ( void )
{
unsigned int V_18 , V_132 , V_133 ;
struct V_113 * V_93 ;
V_93 = F_80 () ;
if ( ! V_93 )
F_75 ( L_5 ) ;
if ( V_93 -> V_126 ) {
for ( V_18 = 0 ; V_18 < V_93 -> V_118 ; V_18 ++ ) {
if ( V_93 -> V_18 [ V_18 ] . V_10 != V_104 )
continue;
V_127 = V_93 -> V_18 [ V_18 ] . type ;
break;
}
}
V_132 = V_133 = 0 ;
for ( V_18 = 0 ; V_18 < V_93 -> V_118 ; V_18 ++ ) {
if ( V_93 -> V_126 && V_93 -> V_18 [ V_18 ] . type != V_127 )
continue;
if ( V_18 < V_93 -> V_117 ) {
F_71 ( V_132 , V_93 -> V_18 [ V_18 ] . V_10 ) ;
V_132 ++ ;
} else
V_133 ++ ;
}
F_90 ( L_6 , V_132 , V_133 ) ;
F_91 () ;
F_83 ( V_93 , 0 ) ;
F_92 () ;
F_93 ( V_93 ) ;
}
static void T_5 F_94 ( void * V_134 )
{
V_34 . V_135 = F_44 () ;
V_34 . V_66 = ( unsigned long ) V_66 ;
V_34 . V_67 = ( unsigned long ) V_136 ;
V_34 . V_68 = 0 ;
V_34 . V_69 = - 1UL ;
F_95 ( V_34 . V_55 ) ;
F_68 ( V_34 . V_54 , 0 , 15 ) ;
F_33 ( V_73 | V_80 ) ;
F_96 () ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 ( F_51 () ) ;
F_102 ( F_51 () , true ) ;
F_103 () ;
F_104 () ;
}
int T_5 F_105 ( unsigned int V_18 , struct V_58 * V_137 )
{
struct V_8 * V_8 ;
int V_138 ;
V_8 = V_19 + V_18 ;
if ( V_8 -> V_128 != V_130 )
return - V_112 ;
if ( F_4 ( V_8 , V_139 , 0 ) !=
V_111 )
return - V_112 ;
V_138 = F_12 ( V_8 , V_18 ) ;
if ( V_138 )
return V_138 ;
F_22 ( V_8 , V_18 ) ;
F_26 ( V_8 , V_137 ) ;
F_29 ( V_8 , F_94 , NULL ) ;
while ( ! F_106 ( V_18 ) )
F_3 () ;
return 0 ;
}
static int T_8 F_107 ( char * V_140 )
{
int V_141 , V_18 ;
if ( F_108 ( V_140 , 0 , & V_141 ) < 0 )
return 0 ;
F_109 ( F_110 ( 0 ) ) ;
for ( V_18 = 1 ; V_18 < V_141 && V_18 < V_125 ; V_18 ++ )
F_111 ( V_18 , true ) ;
return 0 ;
}
int F_112 ( void )
{
unsigned long V_96 [ 16 ] ;
F_102 ( F_51 () , false ) ;
F_113 () ;
F_24 ( V_96 , 0 , 15 ) ;
V_96 [ 0 ] &= ~ 0x0000ee70UL ;
V_96 [ 6 ] &= ~ 0xff000000UL ;
V_96 [ 14 ] &= ~ 0x1f000000UL ;
F_68 ( V_96 , 0 , 15 ) ;
return 0 ;
}
void F_114 ( unsigned int V_18 )
{
struct V_8 * V_8 ;
V_8 = V_19 + V_18 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_115 ( & V_43 . V_44 . V_45 ) ;
}
void T_10 F_116 ( void )
{
F_117 () ;
F_4 ( V_19 + F_51 () , V_74 , 0 ) ;
for (; ; ) ;
}
void T_8 F_118 ( unsigned int V_142 )
{
if ( F_119 ( 0x1201 , F_53 ) != 0 )
F_75 ( L_7 ) ;
if ( F_119 ( 0x1202 , F_53 ) != 0 )
F_75 ( L_8 ) ;
F_89 () ;
}
void T_8 F_120 ( void )
{
struct V_8 * V_8 = V_19 ;
V_104 = F_32 () ;
V_8 -> V_128 = V_130 ;
V_8 -> V_10 = V_104 ;
V_8 -> V_26 = (struct V_24 * ) ( unsigned long ) F_121 () ;
V_8 -> V_30 = V_34 . V_30 - V_35 ;
V_8 -> V_32 = V_34 . V_32 - V_36 ;
V_34 . V_46 = V_47 [ 0 ] ;
F_85 ( 0 , V_131 ) ;
F_86 ( 0 , true ) ;
F_102 ( 0 , true ) ;
}
void T_8 F_122 ( unsigned int V_142 )
{
}
void T_8 F_123 ( void )
{
V_34 . V_37 = 0 ;
}
int F_124 ( unsigned int V_143 )
{
return 0 ;
}
static T_11 F_125 ( struct V_144 * V_145 ,
struct V_146 * V_147 , char * V_148 )
{
T_11 V_149 ;
F_126 ( & V_150 ) ;
V_149 = sprintf ( V_148 , L_9 , V_19 [ V_145 -> V_151 ] . V_128 ) ;
F_127 ( & V_150 ) ;
return V_149 ;
}
static T_11 F_128 ( struct V_144 * V_145 ,
struct V_146 * V_147 ,
const char * V_148 , T_12 V_149 )
{
struct V_8 * V_8 ;
int V_18 , V_152 , V_138 ;
char V_153 ;
if ( sscanf ( V_148 , L_10 , & V_152 , & V_153 ) != 1 )
return - V_154 ;
if ( V_152 != 0 && V_152 != 1 )
return - V_154 ;
F_91 () ;
F_126 ( & V_150 ) ;
V_138 = - V_155 ;
V_18 = V_145 -> V_151 ;
if ( F_106 ( V_18 ) || V_18 == 0 )
goto V_33;
V_8 = V_19 + V_18 ;
V_138 = 0 ;
switch ( V_152 ) {
case 0 :
if ( V_8 -> V_128 != V_130 )
break;
V_138 = F_129 ( V_8 -> V_10 ) ;
if ( V_138 )
break;
V_8 -> V_128 = V_129 ;
F_85 ( V_18 , V_131 ) ;
F_130 () ;
break;
case 1 :
if ( V_8 -> V_128 != V_129 )
break;
V_138 = F_131 ( V_8 -> V_10 ) ;
if ( V_138 )
break;
V_8 -> V_128 = V_130 ;
F_85 ( V_18 , V_131 ) ;
F_130 () ;
break;
default:
break;
}
V_33:
F_127 ( & V_150 ) ;
F_92 () ;
return V_138 ? V_138 : V_149 ;
}
static T_11 F_132 ( struct V_144 * V_145 ,
struct V_146 * V_147 , char * V_148 )
{
return sprintf ( V_148 , L_9 , V_19 [ V_145 -> V_151 ] . V_10 ) ;
}
static T_11 F_133 ( struct V_144 * V_145 ,
struct V_146 * V_147 , char * V_148 )
{
struct V_156 * V_157 = & F_134 ( V_158 , V_145 -> V_151 ) ;
unsigned long long V_159 ;
unsigned int V_160 ;
do {
V_160 = F_135 ( V_157 -> V_160 ) ;
V_159 = F_135 ( V_157 -> V_159 ) ;
if ( F_135 ( V_157 -> V_161 ) )
V_159 ++ ;
} while ( ( V_160 & 1 ) || ( V_157 -> V_160 != V_160 ) );
return sprintf ( V_148 , L_11 , V_159 ) ;
}
static T_11 F_136 ( struct V_144 * V_145 ,
struct V_146 * V_147 , char * V_148 )
{
struct V_156 * V_157 = & F_134 ( V_158 , V_145 -> V_151 ) ;
unsigned long long V_162 , V_163 , V_164 , V_165 ;
unsigned int V_160 ;
do {
V_162 = F_44 () ;
V_160 = F_135 ( V_157 -> V_160 ) ;
V_163 = F_135 ( V_157 -> V_163 ) ;
V_164 = F_135 ( V_157 -> V_161 ) ;
V_165 = F_135 ( V_157 -> V_166 ) ;
} while ( ( V_160 & 1 ) || ( V_157 -> V_160 != V_160 ) );
V_163 += V_164 ? ( ( V_165 ? : V_162 ) - V_164 ) : 0 ;
return sprintf ( V_148 , L_11 , V_163 >> 12 ) ;
}
static int T_5 F_137 ( struct V_167 * V_168 ,
unsigned long V_169 , void * V_170 )
{
unsigned int V_18 = ( unsigned int ) ( long ) V_170 ;
struct V_18 * V_171 = & V_19 [ V_18 ] . V_18 ;
struct V_144 * V_140 = & V_171 -> V_145 ;
int V_172 = 0 ;
switch ( V_169 ) {
case V_173 :
case V_174 :
V_172 = F_138 ( & V_140 -> V_175 , & V_176 ) ;
break;
case V_177 :
case V_178 :
F_139 ( & V_140 -> V_175 , & V_176 ) ;
break;
}
return F_140 ( V_172 ) ;
}
static int T_9 F_87 ( int V_18 )
{
struct V_18 * V_171 = & V_19 [ V_18 ] . V_18 ;
struct V_144 * V_140 = & V_171 -> V_145 ;
int V_138 ;
V_171 -> V_179 = 1 ;
V_138 = F_141 ( V_171 , V_18 ) ;
if ( V_138 )
goto V_33;
V_138 = F_138 ( & V_140 -> V_175 , & V_180 ) ;
if ( V_138 )
goto V_181;
if ( F_106 ( V_18 ) ) {
V_138 = F_138 ( & V_140 -> V_175 , & V_176 ) ;
if ( V_138 )
goto V_182;
}
V_138 = F_142 ( V_171 ) ;
if ( V_138 )
goto V_183;
return 0 ;
V_183:
if ( F_106 ( V_18 ) )
F_139 ( & V_140 -> V_175 , & V_176 ) ;
V_182:
F_139 ( & V_140 -> V_175 , & V_180 ) ;
V_181:
#ifdef F_143
F_144 ( V_171 ) ;
#endif
V_33:
return V_138 ;
}
int T_13 F_145 ( void )
{
struct V_113 * V_93 ;
int V_121 ;
V_93 = F_80 () ;
if ( ! V_93 )
return - V_42 ;
F_91 () ;
F_126 ( & V_150 ) ;
V_121 = F_83 ( V_93 , 1 ) ;
F_127 ( & V_150 ) ;
F_92 () ;
F_93 ( V_93 ) ;
if ( V_121 )
F_146 () ;
return 0 ;
}
static T_11 T_13 F_147 ( struct V_144 * V_145 ,
struct V_146 * V_147 ,
const char * V_148 ,
T_12 V_149 )
{
int V_138 ;
V_138 = F_145 () ;
return V_138 ? V_138 : V_149 ;
}
static int T_8 F_148 ( void )
{
int V_18 , V_138 ;
F_149 ( & V_184 ) ;
#ifdef F_143
V_138 = F_150 ( V_185 . V_186 , & V_187 ) ;
if ( V_138 )
return V_138 ;
#endif
F_39 (cpu) {
V_138 = F_87 ( V_18 ) ;
if ( V_138 )
return V_138 ;
}
return 0 ;
}
