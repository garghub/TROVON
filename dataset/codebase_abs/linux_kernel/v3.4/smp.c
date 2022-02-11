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
struct V_22 * V_23 = V_8 -> V_24 ;
unsigned short V_70 ;
F_32 ( V_71 ) ;
V_70 = F_33 () ;
if ( V_8 -> V_10 == V_70 )
F_30 ( V_63 ) ;
F_4 ( V_8 , V_72 , 0 ) ;
V_23 -> V_64 = V_69 ;
V_23 -> V_65 = ( unsigned long ) F_30 ;
V_23 -> V_66 = ( unsigned long ) V_63 ;
V_23 -> V_67 = ( unsigned long ) V_70 ;
asm volatile(
"0: sigp 0,%0,6 # sigp restart to target cpu\n"
" brc 2,0b # busy, try again\n"
"1: sigp 0,%1,5 # sigp stop to current cpu\n"
" brc 2,1b # busy, try again\n"
: : "d" (pcpu->address), "d" (this_cpu) : "0", "1", "cc");
for (; ; ) ;
}
void F_34 ( void (* F_30)( void * ) , void * V_63 )
{
struct V_8 * V_8 ;
V_8 = F_8 ( V_73 , F_33 () ) ;
if ( ! V_8 )
V_8 = V_17 + F_35 ( V_73 ) ;
F_31 ( V_8 , F_30 , V_63 , ( unsigned long ) V_64 ) ;
}
void F_36 ( void (* F_30)( void * ) , void * V_63 )
{
F_31 ( & V_17 [ 0 ] , F_30 , V_63 ,
V_17 -> V_30 + V_34 ) ;
}
int F_37 ( T_1 V_10 )
{
int V_16 ;
F_38 (cpu)
if ( V_17 [ V_16 ] . V_10 == V_10 )
return V_16 ;
return - 1 ;
}
int F_39 ( int V_16 )
{
return F_7 ( V_17 + V_16 ) ;
}
void F_40 ( void )
{
if ( V_74 )
asm volatile("diag 0,0,0x44");
}
void F_41 ( int V_16 )
{
if ( V_75 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_74 )
asm volatile("diag 0,0,0x44");
}
void F_42 ( T_6 * V_14 )
{
T_7 V_76 ;
int V_16 ;
V_76 = F_43 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_8 * V_8 = V_17 + V_16 ;
F_11 ( V_77 , & V_8 -> V_19 ) ;
while ( F_1 ( V_8 -> V_10 , V_21 ,
0 , NULL ) == V_7 &&
F_43 () < V_76 )
F_3 () ;
}
while ( F_43 () < V_76 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_17 + V_16 ) )
F_44 ( V_16 , V_14 ) ;
if ( F_45 ( V_14 ) )
break;
F_3 () ;
}
}
void F_46 ( void )
{
T_6 V_14 ;
int V_16 ;
F_32 ( V_71 | V_78 ) ;
F_47 () ;
F_48 () ;
F_49 ( & V_14 , V_73 ) ;
F_44 ( F_50 () , & V_14 ) ;
if ( V_79 )
F_42 ( & V_14 ) ;
F_9 (cpu, &cpumask) {
struct V_8 * V_8 = V_17 + V_16 ;
F_4 ( V_8 , V_72 , 0 ) ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
}
}
void F_51 ( void )
{
F_4 ( V_17 + F_50 () , V_72 , 0 ) ;
for (; ; ) ;
}
static void F_52 ( struct V_80 V_80 ,
unsigned int V_81 , unsigned long V_82 )
{
unsigned long V_83 ;
int V_16 ;
V_16 = F_50 () ;
if ( V_80 . V_84 == 0x1202 )
F_53 ( V_16 ) . V_85 [ V_86 ] ++ ;
else
F_53 ( V_16 ) . V_85 [ V_87 ] ++ ;
V_83 = F_54 ( & V_17 [ V_16 ] . V_19 , 0 ) ;
if ( F_55 ( V_77 , & V_83 ) )
F_51 () ;
if ( F_55 ( V_88 , & V_83 ) )
F_56 () ;
if ( F_55 ( V_89 , & V_83 ) )
F_57 () ;
if ( F_55 ( V_90 , & V_83 ) )
F_58 () ;
}
void F_59 ( const struct V_14 * V_15 )
{
int V_16 ;
F_9 (cpu, mask)
F_10 ( V_17 + V_16 , V_89 ) ;
}
void F_60 ( int V_16 )
{
F_10 ( V_17 + V_16 , V_90 ) ;
}
static void F_61 ( void * V_91 )
{
F_62 () ;
}
void F_63 ( void )
{
F_64 ( F_61 , NULL , 1 ) ;
}
void F_65 ( int V_16 )
{
F_10 ( V_17 + V_16 , V_88 ) ;
}
static void F_66 ( void * V_91 )
{
struct V_92 * V_93 = V_91 ;
unsigned long V_94 [ 16 ] ;
F_24 ( V_94 , 0 , 15 ) ;
V_94 [ V_93 -> V_95 ] = ( V_94 [ V_93 -> V_95 ] & V_93 -> V_96 ) | V_93 -> V_97 ;
F_67 ( V_94 , 0 , 15 ) ;
}
void F_68 ( int V_95 , int V_98 )
{
struct V_92 V_99 = { 1UL << V_98 , - 1UL , V_95 } ;
F_64 ( F_66 , & V_99 , 1 ) ;
}
void F_69 ( int V_95 , int V_98 )
{
struct V_92 V_99 = { 0 , ~ ( 1UL << V_98 ) , V_95 } ;
F_64 ( F_66 , & V_99 , 1 ) ;
}
static void T_8 F_70 ( int V_16 , T_1 V_10 )
{
void * V_23 = V_17 [ 0 ] . V_24 ;
struct V_100 * V_100 ;
if ( F_71 () )
return;
if ( ! V_101 && ( V_10 == V_102 ||
V_103 . type != V_104 ) )
return;
if ( V_16 >= V_105 ) {
F_72 ( L_2
L_3 , V_16 , V_105 - 1 ) ;
return;
}
V_100 = F_73 ( sizeof( struct V_100 ) , V_25 ) ;
if ( ! V_100 )
F_74 ( L_4 ) ;
V_106 [ V_16 ] = V_100 ;
#ifdef F_75
if ( V_10 == V_102 ) {
F_76 ( 1 , ( void * ) V_100 , sizeof( * V_100 ) ,
V_107 - V_34 , 0 ) ;
return;
}
#endif
F_2 ( V_10 , V_108 , 0 , NULL ) ;
F_77 ( V_100 , V_23 + V_107 , sizeof( * V_100 ) ) ;
}
int F_78 ( int V_16 )
{
struct V_8 * V_8 ;
V_8 = V_17 + V_16 ;
if ( F_2 ( V_8 -> V_10 , V_108 ,
0 , NULL ) != V_109 )
return - V_110 ;
return 0 ;
}
static inline void F_70 ( int V_16 , T_1 V_10 ) { }
static struct V_111 * F_79 ( void )
{
static int V_112 ;
struct V_111 * V_91 ;
int V_10 ;
V_91 = F_80 ( sizeof( * V_91 ) , V_25 ) ;
if ( V_91 && ( V_112 || F_81 ( V_91 ) ) ) {
V_112 = 1 ;
for ( V_10 = 0 ; V_10 <= V_113 ; V_10 ++ ) {
if ( F_2 ( V_10 , V_11 , 0 , NULL ) ==
V_114 )
continue;
V_91 -> V_16 [ V_91 -> V_115 ] . V_10 = V_10 ;
V_91 -> V_115 ++ ;
}
V_91 -> V_116 = V_91 -> V_115 ;
}
return V_91 ;
}
static int T_9 F_82 ( struct V_111 * V_91 ,
int V_117 )
{
struct V_8 * V_8 ;
T_6 V_118 ;
int V_16 , V_119 , V_120 ;
V_119 = 0 ;
F_83 ( & V_118 , V_121 , V_122 ) ;
V_16 = F_35 ( & V_118 ) ;
for ( V_120 = 0 ; ( V_120 < V_91 -> V_116 ) && ( V_16 < V_123 ) ; V_120 ++ ) {
if ( V_91 -> V_124 && V_91 -> V_16 [ V_120 ] . type != V_125 )
continue;
if ( F_8 ( V_122 , V_91 -> V_16 [ V_120 ] . V_10 ) )
continue;
V_8 = V_17 + V_16 ;
V_8 -> V_10 = V_91 -> V_16 [ V_120 ] . V_10 ;
V_8 -> V_126 = ( V_16 >= V_91 -> V_115 ) ?
V_127 : V_128 ;
F_84 ( V_16 , V_129 ) ;
F_85 ( V_16 , true ) ;
if ( V_117 && F_86 ( V_16 ) != 0 )
F_85 ( V_16 , false ) ;
else
V_119 ++ ;
V_16 = F_87 ( V_16 , & V_118 ) ;
}
return V_119 ;
}
static void T_8 F_88 ( void )
{
unsigned int V_16 , V_130 , V_131 ;
struct V_111 * V_91 ;
V_91 = F_79 () ;
if ( ! V_91 )
F_74 ( L_5 ) ;
if ( V_91 -> V_124 ) {
for ( V_16 = 0 ; V_16 < V_91 -> V_116 ; V_16 ++ ) {
if ( V_91 -> V_16 [ V_16 ] . V_10 != V_102 )
continue;
V_125 = V_91 -> V_16 [ V_16 ] . type ;
break;
}
}
V_130 = V_131 = 0 ;
for ( V_16 = 0 ; V_16 < V_91 -> V_116 ; V_16 ++ ) {
if ( V_91 -> V_124 && V_91 -> V_16 [ V_16 ] . type != V_125 )
continue;
if ( V_16 < V_91 -> V_115 ) {
F_70 ( V_130 , V_91 -> V_16 [ V_16 ] . V_10 ) ;
V_130 ++ ;
} else
V_131 ++ ;
}
F_89 ( L_6 , V_130 , V_131 ) ;
F_90 () ;
F_82 ( V_91 , 0 ) ;
F_91 () ;
F_92 ( V_91 ) ;
}
static void T_5 F_93 ( void * V_132 )
{
V_32 . V_133 = F_43 () ;
V_32 . V_64 = ( unsigned long ) V_64 ;
V_32 . V_65 = ( unsigned long ) V_134 ;
V_32 . V_66 = 0 ;
V_32 . V_67 = - 1UL ;
F_94 ( V_32 . V_53 ) ;
F_67 ( V_32 . V_52 , 0 , 15 ) ;
F_32 ( V_71 | V_78 ) ;
F_95 () ;
F_96 () ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 ( F_50 () ) ;
F_101 () ;
F_102 ( F_50 () , true ) ;
F_103 () ;
F_104 () ;
F_105 () ;
}
static void T_5 F_106 ( struct V_135 * V_136 )
{
struct V_137 * V_138 ;
V_138 = F_107 ( V_136 , struct V_137 , V_136 ) ;
V_138 -> V_139 = F_108 ( V_138 -> V_16 ) ;
F_109 ( & V_138 -> V_140 ) ;
}
int T_5 F_110 ( unsigned int V_16 )
{
struct V_137 V_138 ;
struct V_8 * V_8 ;
int V_141 ;
V_8 = V_17 + V_16 ;
if ( V_8 -> V_126 != V_128 )
return - V_110 ;
if ( F_4 ( V_8 , V_142 , 0 ) !=
V_109 )
return - V_110 ;
if ( ! V_8 -> V_139 ) {
V_138 . V_140 = F_111 ( V_138 . V_140 ) ;
F_112 ( & V_138 . V_136 , F_106 ) ;
V_138 . V_16 = V_16 ;
F_113 ( & V_138 . V_136 ) ;
F_114 ( & V_138 . V_140 ) ;
if ( F_115 ( V_138 . V_139 ) )
return F_116 ( V_138 . V_139 ) ;
V_8 -> V_139 = V_138 . V_139 ;
}
F_117 ( V_8 -> V_139 , V_16 ) ;
V_141 = F_12 ( V_8 , V_16 ) ;
if ( V_141 )
return V_141 ;
F_22 ( V_8 , V_16 ) ;
F_26 ( V_8 , V_8 -> V_139 ) ;
F_29 ( V_8 , F_93 , NULL ) ;
while ( ! F_118 ( V_16 ) )
F_3 () ;
return 0 ;
}
static int T_8 F_119 ( char * V_143 )
{
int V_144 , V_16 ;
if ( F_120 ( V_143 , 0 , & V_144 ) < 0 )
return 0 ;
F_121 ( F_122 ( 0 ) ) ;
for ( V_16 = 1 ; V_16 < V_144 && V_16 < V_123 ; V_16 ++ )
F_123 ( V_16 , true ) ;
return 0 ;
}
int F_124 ( void )
{
unsigned long V_94 [ 16 ] ;
F_102 ( F_50 () , false ) ;
F_125 () ;
F_24 ( V_94 , 0 , 15 ) ;
V_94 [ 0 ] &= ~ 0x0000ee70UL ;
V_94 [ 6 ] &= ~ 0xff000000UL ;
V_94 [ 14 ] &= ~ 0x1f000000UL ;
F_67 ( V_94 , 0 , 15 ) ;
return 0 ;
}
void F_126 ( unsigned int V_16 )
{
struct V_8 * V_8 ;
V_8 = V_17 + V_16 ;
while ( ! F_6 ( V_8 ) )
F_3 () ;
F_20 ( V_8 ) ;
F_127 ( & V_41 . V_42 . V_43 ) ;
}
void T_10 F_128 ( void )
{
F_129 () ;
F_4 ( V_17 + F_50 () , V_72 , 0 ) ;
for (; ; ) ;
}
static void F_130 ( void )
{
int (* F_131)( void );
unsigned long V_145 ;
F_131 = F_132 ( V_146 , & V_145 ) ;
if ( ! F_131 )
return;
F_131 () ;
}
void T_8 F_133 ( unsigned int V_147 )
{
if ( F_134 ( 0x1201 , F_52 ) != 0 )
F_74 ( L_7 ) ;
if ( F_134 ( 0x1202 , F_52 ) != 0 )
F_74 ( L_8 ) ;
F_130 () ;
F_88 () ;
}
void T_8 F_135 ( void )
{
struct V_8 * V_8 = V_17 ;
V_102 = F_33 () ;
V_8 -> V_139 = V_148 ;
V_8 -> V_126 = V_128 ;
V_8 -> V_10 = V_102 ;
V_8 -> V_24 = (struct V_22 * ) ( unsigned long ) F_136 () ;
V_8 -> V_28 = V_32 . V_28 - V_33 ;
V_8 -> V_30 = V_32 . V_30 - V_34 ;
V_32 . V_44 = V_45 [ 0 ] ;
F_84 ( 0 , V_129 ) ;
F_85 ( 0 , true ) ;
F_102 ( 0 , true ) ;
}
void T_8 F_137 ( unsigned int V_147 )
{
}
void T_8 F_138 ( void )
{
V_32 . V_35 = 0 ;
}
int F_139 ( unsigned int V_149 )
{
return 0 ;
}
static T_11 F_140 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
T_11 V_155 ;
F_141 ( & V_156 ) ;
V_155 = sprintf ( V_154 , L_9 , V_17 [ V_151 -> V_157 ] . V_126 ) ;
F_142 ( & V_156 ) ;
return V_155 ;
}
static T_11 F_143 ( struct V_150 * V_151 ,
struct V_152 * V_153 ,
const char * V_154 , T_12 V_155 )
{
struct V_8 * V_8 ;
int V_16 , V_158 , V_141 ;
char V_159 ;
if ( sscanf ( V_154 , L_10 , & V_158 , & V_159 ) != 1 )
return - V_160 ;
if ( V_158 != 0 && V_158 != 1 )
return - V_160 ;
F_90 () ;
F_141 ( & V_156 ) ;
V_141 = - V_161 ;
V_16 = V_151 -> V_157 ;
if ( F_118 ( V_16 ) || V_16 == 0 )
goto V_31;
V_8 = V_17 + V_16 ;
V_141 = 0 ;
switch ( V_158 ) {
case 0 :
if ( V_8 -> V_126 != V_128 )
break;
V_141 = F_144 ( V_8 -> V_10 ) ;
if ( V_141 )
break;
V_8 -> V_126 = V_127 ;
F_84 ( V_16 , V_129 ) ;
F_145 () ;
break;
case 1 :
if ( V_8 -> V_126 != V_127 )
break;
V_141 = F_146 ( V_8 -> V_10 ) ;
if ( V_141 )
break;
V_8 -> V_126 = V_128 ;
F_84 ( V_16 , V_129 ) ;
F_145 () ;
break;
default:
break;
}
V_31:
F_142 ( & V_156 ) ;
F_91 () ;
return V_141 ? V_141 : V_155 ;
}
static T_11 F_147 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
return sprintf ( V_154 , L_9 , V_17 [ V_151 -> V_157 ] . V_10 ) ;
}
static T_11 F_148 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
unsigned int V_162 ;
int V_141 ;
V_141 = F_149 ( & V_162 ) ;
if ( V_141 )
return V_141 ;
return sprintf ( V_154 , L_11 , V_162 ) ;
}
static T_11 F_150 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_163 * V_139 = & F_151 ( V_164 , V_151 -> V_157 ) ;
unsigned long long V_165 ;
unsigned int V_166 ;
do {
V_166 = F_152 ( V_139 -> V_166 ) ;
V_165 = F_152 ( V_139 -> V_165 ) ;
if ( F_152 ( V_139 -> V_167 ) )
V_165 ++ ;
} while ( ( V_166 & 1 ) || ( V_139 -> V_166 != V_166 ) );
return sprintf ( V_154 , L_12 , V_165 ) ;
}
static T_11 F_153 ( struct V_150 * V_151 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_163 * V_139 = & F_151 ( V_164 , V_151 -> V_157 ) ;
unsigned long long V_168 , V_169 , V_167 , V_170 ;
unsigned int V_166 ;
do {
V_168 = F_43 () ;
V_166 = F_152 ( V_139 -> V_166 ) ;
V_169 = F_152 ( V_139 -> V_169 ) ;
V_167 = F_152 ( V_139 -> V_167 ) ;
V_170 = F_152 ( V_139 -> V_170 ) ;
} while ( ( V_166 & 1 ) || ( V_139 -> V_166 != V_166 ) );
V_169 += V_167 ? ( ( V_170 ? : V_168 ) - V_167 ) : 0 ;
return sprintf ( V_154 , L_12 , V_169 >> 12 ) ;
}
static int T_5 F_154 ( struct V_171 * V_172 ,
unsigned long V_173 , void * V_174 )
{
unsigned int V_16 = ( unsigned int ) ( long ) V_174 ;
struct V_16 * V_175 = & V_17 [ V_16 ] . V_16 ;
struct V_150 * V_143 = & V_175 -> V_151 ;
struct V_163 * V_139 ;
int V_176 = 0 ;
switch ( V_173 ) {
case V_177 :
case V_178 :
V_139 = & F_151 ( V_164 , V_16 ) ;
memset ( V_139 , 0 , sizeof( struct V_163 ) ) ;
V_176 = F_155 ( & V_143 -> V_179 , & V_180 ) ;
break;
case V_181 :
case V_182 :
F_156 ( & V_143 -> V_179 , & V_180 ) ;
break;
}
return F_157 ( V_176 ) ;
}
static int T_9 F_86 ( int V_16 )
{
struct V_16 * V_175 = & V_17 [ V_16 ] . V_16 ;
struct V_150 * V_143 = & V_175 -> V_151 ;
int V_141 ;
V_175 -> V_183 = 1 ;
V_141 = F_158 ( V_175 , V_16 ) ;
if ( V_141 )
goto V_31;
V_141 = F_155 ( & V_143 -> V_179 , & V_184 ) ;
if ( V_141 )
goto V_185;
if ( F_118 ( V_16 ) ) {
V_141 = F_155 ( & V_143 -> V_179 , & V_180 ) ;
if ( V_141 )
goto V_186;
}
V_141 = F_159 ( V_175 ) ;
if ( V_141 )
goto V_187;
return 0 ;
V_187:
if ( F_118 ( V_16 ) )
F_156 ( & V_143 -> V_179 , & V_180 ) ;
V_186:
F_156 ( & V_143 -> V_179 , & V_184 ) ;
V_185:
#ifdef F_160
F_161 ( V_175 ) ;
#endif
V_31:
return V_141 ;
}
int T_13 F_162 ( void )
{
struct V_111 * V_91 ;
int V_119 ;
V_91 = F_79 () ;
if ( ! V_91 )
return - V_40 ;
F_90 () ;
F_141 ( & V_156 ) ;
V_119 = F_82 ( V_91 , 1 ) ;
F_142 ( & V_156 ) ;
F_91 () ;
F_92 ( V_91 ) ;
if ( V_119 )
F_163 () ;
return 0 ;
}
static T_11 T_13 F_164 ( struct V_150 * V_151 ,
struct V_152 * V_153 ,
const char * V_154 ,
T_12 V_155 )
{
int V_141 ;
V_141 = F_162 () ;
return V_141 ? V_141 : V_155 ;
}
static int T_8 F_165 ( void )
{
int V_16 , V_141 ;
F_166 ( & V_188 ) ;
#ifdef F_160
V_141 = F_167 ( V_189 . V_190 , & V_191 ) ;
if ( V_141 )
return V_141 ;
#endif
F_38 (cpu) {
V_141 = F_86 ( V_16 ) ;
if ( V_141 )
return V_141 ;
}
return 0 ;
}
