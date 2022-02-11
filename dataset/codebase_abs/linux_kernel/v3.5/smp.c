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
return ! ! ( V_8 -> V_4 & 0x50 ) ;
}
static inline int F_7 ( struct V_8 * V_8 )
{
if ( F_1 ( V_8 -> V_10 , V_13 ,
0 , & V_8 -> V_4 ) != V_12 )
return 1 ;
return ! ( V_8 -> V_4 & 0x400 ) ;
}
static struct V_8 * F_8 ( const struct V_14 * V_15 , int V_10 )
{
int V_16 ;
F_9 (cpu, mask)
if ( V_17 [ V_16 ] . V_10 == V_10 )
return V_17 + V_16 ;
return NULL ;
}
static void F_10 ( struct V_8 * V_8 , int V_18 )
{
int V_2 ;
F_11 ( V_18 , & V_8 -> V_19 ) ;
V_2 = F_7 ( V_8 ) ?
V_20 : V_21 ;
F_4 ( V_8 , V_2 , 0 ) ;
}
static int T_5 F_12 ( struct V_8 * V_8 , int V_16 )
{
struct V_22 * V_23 ;
if ( V_8 != & V_17 [ 0 ] ) {
V_8 -> V_24 = (struct V_22 * )
F_13 ( V_25 | V_26 , V_27 ) ;
V_8 -> V_28 = F_13 ( V_25 , V_29 ) ;
V_8 -> V_30 = F_14 ( V_25 ) ;
if ( ! V_8 -> V_24 || ! V_8 -> V_30 || ! V_8 -> V_28 )
goto V_31;
}
V_23 = V_8 -> V_24 ;
memcpy ( V_23 , & V_32 , 512 ) ;
memset ( ( char * ) V_23 + 512 , 0 , sizeof( * V_23 ) - 512 ) ;
V_23 -> V_28 = V_8 -> V_28 + V_33 ;
V_23 -> V_30 = V_8 -> V_30 + V_34 ;
V_23 -> V_35 = V_16 ;
#ifndef F_15
if ( V_36 ) {
V_23 -> V_37 = F_16 ( V_25 ) ;
if ( ! V_23 -> V_37 )
goto V_31;
}
#else
if ( F_17 ( V_23 ) )
goto V_31;
#endif
V_38 [ V_16 ] = V_23 ;
F_4 ( V_8 , V_39 , ( T_3 ) ( unsigned long ) V_23 ) ;
return 0 ;
V_31:
if ( V_8 != & V_17 [ 0 ] ) {
F_18 ( V_8 -> V_30 ) ;
F_19 ( V_8 -> V_28 , V_29 ) ;
F_19 ( ( unsigned long ) V_8 -> V_24 , V_27 ) ;
}
return - V_40 ;
}
static void F_20 ( struct V_8 * V_8 )
{
F_4 ( V_8 , V_39 , 0 ) ;
V_38 [ V_8 - V_17 ] = NULL ;
#ifndef F_15
if ( V_36 ) {
struct V_22 * V_23 = V_8 -> V_24 ;
F_18 ( ( unsigned long ) V_23 -> V_37 ) ;
V_23 -> V_37 = 0 ;
}
#else
F_21 ( V_8 -> V_24 ) ;
#endif
if ( V_8 != & V_17 [ 0 ] ) {
F_18 ( V_8 -> V_30 ) ;
F_19 ( V_8 -> V_28 , V_29 ) ;
F_19 ( ( unsigned long ) V_8 -> V_24 , V_27 ) ;
}
}
static void F_22 ( struct V_8 * V_8 , int V_16 )
{
struct V_22 * V_23 = V_8 -> V_24 ;
F_23 ( & V_41 . V_42 . V_43 ) ;
V_23 -> V_35 = V_16 ;
V_23 -> V_44 = V_45 [ V_16 ] ;
V_23 -> V_46 = V_32 . V_46 ;
V_23 -> V_47 = V_32 . V_47 ;
V_23 -> V_48 = V_32 . V_48 ;
V_23 -> V_49 = V_23 -> V_50 = V_23 -> V_51 = 0 ;
F_24 ( V_23 -> V_52 , 0 , 15 ) ;
F_25 ( ( unsigned int * ) V_23 -> V_53 ) ;
memcpy ( V_23 -> V_54 , V_32 . V_54 ,
V_55 / 8 ) ;
}
static void F_26 ( struct V_8 * V_8 , struct V_56 * V_57 )
{
struct V_22 * V_23 = V_8 -> V_24 ;
struct V_58 * V_59 = F_27 ( V_57 ) ;
V_23 -> V_60 = ( unsigned long ) F_28 ( V_57 ) + V_61 ;
V_23 -> V_58 = ( unsigned long ) F_27 ( V_57 ) ;
V_23 -> V_62 = ( unsigned long ) V_57 ;
V_23 -> V_49 = V_59 -> V_49 ;
V_23 -> V_50 = V_59 -> V_50 ;
V_23 -> V_51 = 0 ;
}
static void F_29 ( struct V_8 * V_8 , void (* F_30)( void * ) , void * V_63 )
{
struct V_22 * V_23 = V_8 -> V_24 ;
V_23 -> V_64 = V_23 -> V_60 ;
V_23 -> V_65 = ( unsigned long ) F_30 ;
V_23 -> V_66 = ( unsigned long ) V_63 ;
V_23 -> V_67 = - 1UL ;
F_4 ( V_8 , V_68 , 0 ) ;
}
static void F_31 ( struct V_8 * V_8 , void (* F_30)( void * ) ,
void * V_63 , unsigned long V_69 )
{
struct V_22 * V_23 = V_38 [ V_8 - V_17 ] ;
struct {
unsigned long V_69 ;
void * F_30 ;
void * V_63 ;
unsigned long V_70 ;
} V_71 = { V_69 , F_30 , V_63 , F_32 () } ;
F_33 ( V_72 ) ;
if ( V_8 -> V_10 == V_71 . V_70 )
F_30 ( V_63 ) ;
F_4 ( V_8 , V_73 , 0 ) ;
F_34 ( & V_23 -> V_64 , & V_71 , sizeof( V_71 ) ) ;
asm volatile(
"0: sigp 0,%0,6 # sigp restart to target cpu\n"
" brc 2,0b # busy, try again\n"
"1: sigp 0,%1,5 # sigp stop to current cpu\n"
" brc 2,1b # busy, try again\n"
: : "d" (pcpu->address), "d" (restart.source) : "0", "1", "cc");
for (; ; ) ;
}
void F_35 ( void (* F_30)( void * ) , void * V_63 )
{
struct V_8 * V_8 ;
V_8 = F_8 ( V_74 , F_32 () ) ;
if ( ! V_8 )
V_8 = V_17 + F_36 ( V_74 ) ;
F_31 ( V_8 , F_30 , V_63 , ( unsigned long ) V_64 ) ;
}
void F_37 ( void (* F_30)( void * ) , void * V_63 )
{
F_31 ( & V_17 [ 0 ] , F_30 , V_63 ,
V_17 -> V_30 + V_34 ) ;
}
int F_38 ( T_1 V_10 )
{
int V_16 ;
F_39 (cpu)
if ( V_17 [ V_16 ] . V_10 == V_10 )
return V_16 ;
return - 1 ;
}
int F_40 ( int V_16 )
{
return F_7 ( V_17 + V_16 ) ;
}
void F_41 ( void )
{
if ( V_75 )
asm volatile("diag 0,0,0x44");
}
void F_42 ( int V_16 )
{
if ( V_76 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_75 )
asm volatile("diag 0,0,0x44");
}
void F_43 ( T_6 * V_14 )
{
T_7 V_77 ;
int V_16 ;
V_77 = F_44 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_8 * V_8 = V_17 + V_16 ;
F_11 ( V_78 , & V_8 -> V_19 ) ;
while ( F_1 ( V_8 -> V_10 , V_21 ,
0 , NULL ) == V_7 &&
F_44 () < V_77 )
F_3 () ;
}
while ( F_44 () < V_77 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_17 + V_16 ) )
F_45 ( V_16 , V_14 ) ;
if ( F_46 ( V_14 ) )
break;
F_3 () ;
}
}
void F_47 ( void )
{
T_6 V_14 ;
int V_16 ;
F_33 ( V_72 | V_79 ) ;
F_48 () ;
F_49 () ;
F_50 ( & V_14 , V_74 ) ;
F_45 ( F_51 () , & V_14 ) ;
if ( V_80 )
F_43 ( & V_14 ) ;
F_9 (cpu, &cpumask) {
struct V_8 * V_8 = V_17 + V_16 ;
F_4 ( V_8 , V_73 , 0 ) ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
}
}
void F_52 ( void )
{
F_4 ( V_17 + F_51 () , V_73 , 0 ) ;
for (; ; ) ;
}
static void F_53 ( struct V_81 V_81 ,
unsigned int V_82 , unsigned long V_83 )
{
unsigned long V_84 ;
int V_16 ;
V_16 = F_51 () ;
if ( V_81 . V_85 == 0x1202 )
F_54 ( V_16 ) . V_86 [ V_87 ] ++ ;
else
F_54 ( V_16 ) . V_86 [ V_88 ] ++ ;
V_84 = F_55 ( & V_17 [ V_16 ] . V_19 , 0 ) ;
if ( F_56 ( V_78 , & V_84 ) )
F_52 () ;
if ( F_56 ( V_89 , & V_84 ) )
F_57 () ;
if ( F_56 ( V_90 , & V_84 ) )
F_58 () ;
if ( F_56 ( V_91 , & V_84 ) )
F_59 () ;
}
void F_60 ( const struct V_14 * V_15 )
{
int V_16 ;
F_9 (cpu, mask)
F_10 ( V_17 + V_16 , V_90 ) ;
}
void F_61 ( int V_16 )
{
F_10 ( V_17 + V_16 , V_91 ) ;
}
static void F_62 ( void * V_92 )
{
F_63 () ;
}
void F_64 ( void )
{
F_65 ( F_62 , NULL , 1 ) ;
}
void F_66 ( int V_16 )
{
F_10 ( V_17 + V_16 , V_89 ) ;
}
static void F_67 ( void * V_92 )
{
struct V_93 * V_94 = V_92 ;
unsigned long V_95 [ 16 ] ;
F_24 ( V_95 , 0 , 15 ) ;
V_95 [ V_94 -> V_96 ] = ( V_95 [ V_94 -> V_96 ] & V_94 -> V_97 ) | V_94 -> V_98 ;
F_68 ( V_95 , 0 , 15 ) ;
}
void F_69 ( int V_96 , int V_99 )
{
struct V_93 V_100 = { 1UL << V_99 , - 1UL , V_96 } ;
F_65 ( F_67 , & V_100 , 1 ) ;
}
void F_70 ( int V_96 , int V_99 )
{
struct V_93 V_100 = { 0 , ~ ( 1UL << V_99 ) , V_96 } ;
F_65 ( F_67 , & V_100 , 1 ) ;
}
static void T_8 F_71 ( int V_16 , T_1 V_10 )
{
void * V_23 = V_17 [ 0 ] . V_24 ;
struct V_101 * V_101 ;
if ( F_72 () )
return;
if ( ! V_102 && ( V_10 == V_103 ||
V_104 . type != V_105 ) )
return;
if ( V_16 >= V_106 ) {
F_73 ( L_2
L_3 , V_16 , V_106 - 1 ) ;
return;
}
V_101 = F_74 ( sizeof( struct V_101 ) , V_25 ) ;
if ( ! V_101 )
F_75 ( L_4 ) ;
V_107 [ V_16 ] = V_101 ;
#ifdef F_76
if ( V_10 == V_103 ) {
F_77 ( 1 , ( void * ) V_101 , sizeof( * V_101 ) ,
V_108 - V_34 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_109 , 0 , NULL ) ;
F_78 ( V_101 , V_23 + V_108 , sizeof( * V_101 ) ) ;
}
int F_79 ( int V_16 )
{
struct V_8 * V_8 ;
V_8 = V_17 + V_16 ;
if ( F_2 ( V_8 -> V_10 , V_109 ,
0 , NULL ) != V_110 )
return - V_111 ;
return 0 ;
}
static inline void F_71 ( int V_16 , T_1 V_10 ) { }
static struct V_112 * F_80 ( void )
{
static int V_113 ;
struct V_112 * V_92 ;
int V_10 ;
V_92 = F_81 ( sizeof( * V_92 ) , V_25 ) ;
if ( V_92 && ( V_113 || F_82 ( V_92 ) ) ) {
V_113 = 1 ;
for ( V_10 = 0 ; V_10 <= V_114 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_11 , 0 , NULL ) ==
V_115 )
continue;
V_92 -> V_16 [ V_92 -> V_116 ] . V_10 = V_10 ;
V_92 -> V_116 ++ ;
}
V_92 -> V_117 = V_92 -> V_116 ;
}
return V_92 ;
}
static int T_9 F_83 ( struct V_112 * V_92 ,
int V_118 )
{
struct V_8 * V_8 ;
T_6 V_119 ;
int V_16 , V_120 , V_121 ;
V_120 = 0 ;
F_84 ( & V_119 , V_122 , V_123 ) ;
V_16 = F_36 ( & V_119 ) ;
for ( V_121 = 0 ; ( V_121 < V_92 -> V_117 ) && ( V_16 < V_124 ) ; V_121 ++ ) {
if ( V_92 -> V_125 && V_92 -> V_16 [ V_121 ] . type != V_126 )
continue;
if ( F_8 ( V_123 , V_92 -> V_16 [ V_121 ] . V_10 ) )
continue;
V_8 = V_17 + V_16 ;
V_8 -> V_10 = V_92 -> V_16 [ V_121 ] . V_10 ;
V_8 -> V_127 = ( V_16 >= V_92 -> V_116 ) ?
V_128 : V_129 ;
F_85 ( V_16 , V_130 ) ;
F_86 ( V_16 , true ) ;
if ( V_118 && F_87 ( V_16 ) != 0 )
F_86 ( V_16 , false ) ;
else
V_120 ++ ;
V_16 = F_88 ( V_16 , & V_119 ) ;
}
return V_120 ;
}
static void T_8 F_89 ( void )
{
unsigned int V_16 , V_131 , V_132 ;
struct V_112 * V_92 ;
V_92 = F_80 () ;
if ( ! V_92 )
F_75 ( L_5 ) ;
if ( V_92 -> V_125 ) {
for ( V_16 = 0 ; V_16 < V_92 -> V_117 ; V_16 ++ ) {
if ( V_92 -> V_16 [ V_16 ] . V_10 != V_103 )
continue;
V_126 = V_92 -> V_16 [ V_16 ] . type ;
break;
}
}
V_131 = V_132 = 0 ;
for ( V_16 = 0 ; V_16 < V_92 -> V_117 ; V_16 ++ ) {
if ( V_92 -> V_125 && V_92 -> V_16 [ V_16 ] . type != V_126 )
continue;
if ( V_16 < V_92 -> V_116 ) {
F_71 ( V_131 , V_92 -> V_16 [ V_16 ] . V_10 ) ;
V_131 ++ ;
} else
V_132 ++ ;
}
F_90 ( L_6 , V_131 , V_132 ) ;
F_91 () ;
F_83 ( V_92 , 0 ) ;
F_92 () ;
F_93 ( V_92 ) ;
}
static void T_5 F_94 ( void * V_133 )
{
V_32 . V_134 = F_44 () ;
V_32 . V_64 = ( unsigned long ) V_64 ;
V_32 . V_65 = ( unsigned long ) V_135 ;
V_32 . V_66 = 0 ;
V_32 . V_67 = - 1UL ;
F_95 ( V_32 . V_53 ) ;
F_68 ( V_32 . V_52 , 0 , 15 ) ;
F_33 ( V_72 | V_79 ) ;
F_96 () ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 ( F_51 () ) ;
F_102 () ;
F_103 ( F_51 () , true ) ;
F_104 () ;
F_105 () ;
F_106 () ;
}
int T_5 F_107 ( unsigned int V_16 , struct V_56 * V_136 )
{
struct V_8 * V_8 ;
int V_137 ;
V_8 = V_17 + V_16 ;
if ( V_8 -> V_127 != V_129 )
return - V_111 ;
if ( F_4 ( V_8 , V_138 , 0 ) !=
V_110 )
return - V_111 ;
V_137 = F_12 ( V_8 , V_16 ) ;
if ( V_137 )
return V_137 ;
F_22 ( V_8 , V_16 ) ;
F_26 ( V_8 , V_136 ) ;
F_29 ( V_8 , F_94 , NULL ) ;
while ( ! F_108 ( V_16 ) )
F_3 () ;
return 0 ;
}
static int T_8 F_109 ( char * V_139 )
{
int V_140 , V_16 ;
if ( F_110 ( V_139 , 0 , & V_140 ) < 0 )
return 0 ;
F_111 ( F_112 ( 0 ) ) ;
for ( V_16 = 1 ; V_16 < V_140 && V_16 < V_124 ; V_16 ++ )
F_113 ( V_16 , true ) ;
return 0 ;
}
int F_114 ( void )
{
unsigned long V_95 [ 16 ] ;
F_103 ( F_51 () , false ) ;
F_115 () ;
F_24 ( V_95 , 0 , 15 ) ;
V_95 [ 0 ] &= ~ 0x0000ee70UL ;
V_95 [ 6 ] &= ~ 0xff000000UL ;
V_95 [ 14 ] &= ~ 0x1f000000UL ;
F_68 ( V_95 , 0 , 15 ) ;
return 0 ;
}
void F_116 ( unsigned int V_16 )
{
struct V_8 * V_8 ;
V_8 = V_17 + V_16 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_117 ( & V_41 . V_42 . V_43 ) ;
}
void T_10 F_118 ( void )
{
F_119 () ;
F_4 ( V_17 + F_51 () , V_73 , 0 ) ;
for (; ; ) ;
}
void T_8 F_120 ( unsigned int V_141 )
{
if ( F_121 ( 0x1201 , F_53 ) != 0 )
F_75 ( L_7 ) ;
if ( F_121 ( 0x1202 , F_53 ) != 0 )
F_75 ( L_8 ) ;
F_89 () ;
}
void T_8 F_122 ( void )
{
struct V_8 * V_8 = V_17 ;
V_103 = F_32 () ;
V_8 -> V_127 = V_129 ;
V_8 -> V_10 = V_103 ;
V_8 -> V_24 = (struct V_22 * ) ( unsigned long ) F_123 () ;
V_8 -> V_28 = V_32 . V_28 - V_33 ;
V_8 -> V_30 = V_32 . V_30 - V_34 ;
V_32 . V_44 = V_45 [ 0 ] ;
F_85 ( 0 , V_130 ) ;
F_86 ( 0 , true ) ;
F_103 ( 0 , true ) ;
}
void T_8 F_124 ( unsigned int V_141 )
{
}
void T_8 F_125 ( void )
{
V_32 . V_35 = 0 ;
}
int F_126 ( unsigned int V_142 )
{
return 0 ;
}
static T_11 F_127 ( struct V_143 * V_144 ,
struct V_145 * V_146 , char * V_147 )
{
T_11 V_148 ;
F_128 ( & V_149 ) ;
V_148 = sprintf ( V_147 , L_9 , V_17 [ V_144 -> V_150 ] . V_127 ) ;
F_129 ( & V_149 ) ;
return V_148 ;
}
static T_11 F_130 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
const char * V_147 , T_12 V_148 )
{
struct V_8 * V_8 ;
int V_16 , V_151 , V_137 ;
char V_152 ;
if ( sscanf ( V_147 , L_10 , & V_151 , & V_152 ) != 1 )
return - V_153 ;
if ( V_151 != 0 && V_151 != 1 )
return - V_153 ;
F_91 () ;
F_128 ( & V_149 ) ;
V_137 = - V_154 ;
V_16 = V_144 -> V_150 ;
if ( F_108 ( V_16 ) || V_16 == 0 )
goto V_31;
V_8 = V_17 + V_16 ;
V_137 = 0 ;
switch ( V_151 ) {
case 0 :
if ( V_8 -> V_127 != V_129 )
break;
V_137 = F_131 ( V_8 -> V_10 ) ;
if ( V_137 )
break;
V_8 -> V_127 = V_128 ;
F_85 ( V_16 , V_130 ) ;
F_132 () ;
break;
case 1 :
if ( V_8 -> V_127 != V_128 )
break;
V_137 = F_133 ( V_8 -> V_10 ) ;
if ( V_137 )
break;
V_8 -> V_127 = V_129 ;
F_85 ( V_16 , V_130 ) ;
F_132 () ;
break;
default:
break;
}
V_31:
F_129 ( & V_149 ) ;
F_92 () ;
return V_137 ? V_137 : V_148 ;
}
static T_11 F_134 ( struct V_143 * V_144 ,
struct V_145 * V_146 , char * V_147 )
{
return sprintf ( V_147 , L_9 , V_17 [ V_144 -> V_150 ] . V_10 ) ;
}
static T_11 F_135 ( struct V_143 * V_144 ,
struct V_145 * V_146 , char * V_147 )
{
struct V_155 * V_156 = & F_136 ( V_157 , V_144 -> V_150 ) ;
unsigned long long V_158 ;
unsigned int V_159 ;
do {
V_159 = F_137 ( V_156 -> V_159 ) ;
V_158 = F_137 ( V_156 -> V_158 ) ;
if ( F_137 ( V_156 -> V_160 ) )
V_158 ++ ;
} while ( ( V_159 & 1 ) || ( V_156 -> V_159 != V_159 ) );
return sprintf ( V_147 , L_11 , V_158 ) ;
}
static T_11 F_138 ( struct V_143 * V_144 ,
struct V_145 * V_146 , char * V_147 )
{
struct V_155 * V_156 = & F_136 ( V_157 , V_144 -> V_150 ) ;
unsigned long long V_161 , V_162 , V_160 , V_163 ;
unsigned int V_159 ;
do {
V_161 = F_44 () ;
V_159 = F_137 ( V_156 -> V_159 ) ;
V_162 = F_137 ( V_156 -> V_162 ) ;
V_160 = F_137 ( V_156 -> V_160 ) ;
V_163 = F_137 ( V_156 -> V_163 ) ;
} while ( ( V_159 & 1 ) || ( V_156 -> V_159 != V_159 ) );
V_162 += V_160 ? ( ( V_163 ? : V_161 ) - V_160 ) : 0 ;
return sprintf ( V_147 , L_11 , V_162 >> 12 ) ;
}
static int T_5 F_139 ( struct V_164 * V_165 ,
unsigned long V_166 , void * V_167 )
{
unsigned int V_16 = ( unsigned int ) ( long ) V_167 ;
struct V_16 * V_168 = & V_17 [ V_16 ] . V_16 ;
struct V_143 * V_139 = & V_168 -> V_144 ;
struct V_155 * V_156 ;
int V_169 = 0 ;
switch ( V_166 ) {
case V_170 :
case V_171 :
V_156 = & F_136 ( V_157 , V_16 ) ;
memset ( V_156 , 0 , sizeof( struct V_155 ) ) ;
V_169 = F_140 ( & V_139 -> V_172 , & V_173 ) ;
break;
case V_174 :
case V_175 :
F_141 ( & V_139 -> V_172 , & V_173 ) ;
break;
}
return F_142 ( V_169 ) ;
}
static int T_9 F_87 ( int V_16 )
{
struct V_16 * V_168 = & V_17 [ V_16 ] . V_16 ;
struct V_143 * V_139 = & V_168 -> V_144 ;
int V_137 ;
V_168 -> V_176 = 1 ;
V_137 = F_143 ( V_168 , V_16 ) ;
if ( V_137 )
goto V_31;
V_137 = F_140 ( & V_139 -> V_172 , & V_177 ) ;
if ( V_137 )
goto V_178;
if ( F_108 ( V_16 ) ) {
V_137 = F_140 ( & V_139 -> V_172 , & V_173 ) ;
if ( V_137 )
goto V_179;
}
V_137 = F_144 ( V_168 ) ;
if ( V_137 )
goto V_180;
return 0 ;
V_180:
if ( F_108 ( V_16 ) )
F_141 ( & V_139 -> V_172 , & V_173 ) ;
V_179:
F_141 ( & V_139 -> V_172 , & V_177 ) ;
V_178:
#ifdef F_145
F_146 ( V_168 ) ;
#endif
V_31:
return V_137 ;
}
int T_13 F_147 ( void )
{
struct V_112 * V_92 ;
int V_120 ;
V_92 = F_80 () ;
if ( ! V_92 )
return - V_40 ;
F_91 () ;
F_128 ( & V_149 ) ;
V_120 = F_83 ( V_92 , 1 ) ;
F_129 ( & V_149 ) ;
F_92 () ;
F_93 ( V_92 ) ;
if ( V_120 )
F_148 () ;
return 0 ;
}
static T_11 T_13 F_149 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
const char * V_147 ,
T_12 V_148 )
{
int V_137 ;
V_137 = F_147 () ;
return V_137 ? V_137 : V_148 ;
}
static int T_8 F_150 ( void )
{
int V_16 , V_137 ;
F_151 ( & V_181 ) ;
#ifdef F_145
V_137 = F_152 ( V_182 . V_183 , & V_184 ) ;
if ( V_137 )
return V_137 ;
#endif
F_39 (cpu) {
V_137 = F_87 ( V_16 ) ;
if ( V_137 )
return V_137 ;
}
return 0 ;
}
