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
V_25 -> V_40 = F_15 ( V_18 ) ;
#ifndef F_16
if ( V_41 ) {
V_25 -> V_42 = F_17 ( V_27 ) ;
if ( ! V_25 -> V_42 )
goto V_33;
}
#else
if ( F_18 ( V_25 ) )
goto V_33;
#endif
V_43 [ V_18 ] = V_25 ;
F_4 ( V_7 , V_44 , ( T_3 ) ( unsigned long ) V_25 ) ;
return 0 ;
V_33:
if ( V_7 != & V_19 [ 0 ] ) {
F_19 ( V_7 -> V_32 ) ;
F_20 ( V_7 -> V_30 , V_31 ) ;
F_20 ( ( unsigned long ) V_7 -> V_26 , V_29 ) ;
}
return - V_45 ;
}
static void F_21 ( struct V_7 * V_7 )
{
F_4 ( V_7 , V_44 , 0 ) ;
V_43 [ V_7 - V_19 ] = NULL ;
#ifndef F_16
if ( V_41 ) {
struct V_24 * V_25 = V_7 -> V_26 ;
F_19 ( ( unsigned long ) V_25 -> V_42 ) ;
V_25 -> V_42 = 0 ;
}
#else
F_22 ( V_7 -> V_26 ) ;
#endif
if ( V_7 != & V_19 [ 0 ] ) {
F_19 ( V_7 -> V_32 ) ;
F_20 ( V_7 -> V_30 , V_31 ) ;
F_20 ( ( unsigned long ) V_7 -> V_26 , V_29 ) ;
}
}
static void F_23 ( struct V_7 * V_7 , int V_18 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
if ( V_46 )
F_24 ( V_18 , & V_47 . V_48 . V_49 ) ;
F_24 ( V_18 , F_25 ( & V_47 ) ) ;
F_26 ( & V_47 . V_48 . V_50 ) ;
V_25 -> V_39 = V_18 ;
V_25 -> V_40 = F_15 ( V_18 ) ;
V_25 -> V_51 = V_52 [ V_18 ] ;
V_25 -> V_53 = V_34 . V_53 ;
V_25 -> V_54 = V_34 . V_54 ;
V_25 -> V_55 = V_34 . V_55 ;
V_25 -> V_56 = V_25 -> V_57 = V_25 -> V_58 = 0 ;
F_27 ( V_25 -> V_59 , 0 , 15 ) ;
F_28 ( ( unsigned int * ) V_25 -> V_60 ) ;
memcpy ( V_25 -> V_61 , V_34 . V_61 ,
V_62 / 8 ) ;
}
static void F_29 ( struct V_7 * V_7 , struct V_63 * V_64 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_65 * V_66 = F_30 ( V_64 ) ;
V_25 -> V_67 = ( unsigned long ) F_31 ( V_64 )
+ V_68 - V_36 - sizeof( struct V_37 ) ;
V_25 -> V_65 = ( unsigned long ) F_30 ( V_64 ) ;
V_25 -> V_69 = ( unsigned long ) V_64 ;
V_25 -> V_56 = V_66 -> V_56 ;
V_25 -> V_57 = V_66 -> V_57 ;
V_25 -> V_58 = 0 ;
}
static void F_32 ( struct V_7 * V_7 , void (* F_33)( void * ) , void * V_70 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
V_25 -> V_71 = V_25 -> V_67 ;
V_25 -> V_72 = ( unsigned long ) F_33 ;
V_25 -> V_73 = ( unsigned long ) V_70 ;
V_25 -> V_74 = - 1UL ;
F_4 ( V_7 , V_75 , 0 ) ;
}
static void F_34 ( struct V_7 * V_7 , void (* F_33)( void * ) ,
void * V_70 , unsigned long V_76 )
{
struct V_24 * V_25 = V_43 [ V_7 - V_19 ] ;
unsigned long V_77 = F_35 () ;
F_36 ( V_78 ) ;
if ( V_7 -> V_9 == V_77 )
F_33 ( V_70 ) ;
F_4 ( V_7 , V_79 , 0 ) ;
F_37 ( V_25 -> V_71 , V_76 ) ;
F_37 ( V_25 -> V_72 , ( unsigned long ) F_33 ) ;
F_37 ( V_25 -> V_73 , ( unsigned long ) V_70 ) ;
F_37 ( V_25 -> V_74 , V_77 ) ;
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
void F_38 ( void (* F_33)( void * ) , void * V_70 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_80 , F_35 () ) ;
if ( ! V_7 )
V_7 = V_19 + F_39 ( V_80 ) ;
F_34 ( V_7 , F_33 , V_70 , ( unsigned long ) V_71 ) ;
}
void F_40 ( void (* F_33)( void * ) , void * V_70 )
{
F_34 ( & V_19 [ 0 ] , F_33 , V_70 ,
V_19 -> V_32 + V_38 ) ;
}
int F_41 ( T_1 V_9 )
{
int V_18 ;
F_42 (cpu)
if ( V_19 [ V_18 ] . V_9 == V_9 )
return V_18 ;
return - 1 ;
}
int F_43 ( int V_18 )
{
return F_7 ( V_19 + V_18 ) ;
}
void F_44 ( void )
{
if ( V_81 )
asm volatile("diag 0,0,0x44");
}
void F_45 ( int V_18 )
{
if ( V_82 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_81 )
asm volatile("diag 0,0,0x44");
}
static void F_46 ( T_4 * V_16 )
{
T_5 V_83 ;
int V_18 ;
V_83 = F_47 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_48 ( V_84 , & V_7 -> V_21 ) ;
while ( F_2 ( V_7 -> V_9 , V_23 ,
0 , NULL ) == V_6 &&
F_47 () < V_83 )
F_3 () ;
}
while ( F_47 () < V_83 ) {
F_9 (cpu, cpumask)
if ( F_6 ( V_19 + V_18 ) )
F_49 ( V_18 , V_16 ) ;
if ( F_50 ( V_16 ) )
break;
F_3 () ;
}
}
void F_51 ( void )
{
T_4 V_16 ;
int V_18 ;
F_36 ( V_78 | V_85 ) ;
F_52 () ;
F_53 () ;
F_54 ( & V_16 , V_80 ) ;
F_49 ( F_55 () , & V_16 ) ;
if ( V_86 )
F_46 ( & V_16 ) ;
F_9 (cpu, &cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_4 ( V_7 , V_79 , 0 ) ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
}
}
static void F_56 ( void )
{
unsigned long V_87 ;
V_87 = F_57 ( & V_19 [ F_55 () ] . V_21 , 0 ) ;
if ( F_58 ( V_84 , & V_87 ) )
F_59 () ;
if ( F_58 ( V_88 , & V_87 ) )
F_60 () ;
if ( F_58 ( V_89 , & V_87 ) )
F_61 () ;
}
static void F_62 ( struct V_90 V_90 ,
unsigned int V_91 , unsigned long V_92 )
{
F_63 ( V_90 . V_93 == 0x1202 ? V_94 : V_95 ) ;
F_56 () ;
}
void F_64 ( const struct V_16 * V_17 )
{
int V_18 ;
F_9 (cpu, mask)
F_10 ( V_19 + V_18 , V_89 ) ;
}
void F_65 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_89 ) ;
}
static void F_66 ( void * V_96 )
{
F_67 () ;
}
void F_68 ( void )
{
F_69 ( F_66 , NULL , 1 ) ;
}
void F_70 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_88 ) ;
}
static void F_71 ( void * V_96 )
{
struct V_97 * V_98 = V_96 ;
unsigned long V_99 [ 16 ] ;
F_27 ( V_99 , 0 , 15 ) ;
V_99 [ V_98 -> V_100 ] = ( V_99 [ V_98 -> V_100 ] & V_98 -> V_101 ) | V_98 -> V_102 ;
F_72 ( V_99 , 0 , 15 ) ;
}
void F_73 ( int V_100 , int V_103 )
{
struct V_97 V_104 = { 1UL << V_103 , - 1UL , V_100 } ;
F_69 ( F_71 , & V_104 , 1 ) ;
}
void F_74 ( int V_100 , int V_103 )
{
struct V_97 V_104 = { 0 , ~ ( 1UL << V_103 ) , V_100 } ;
F_69 ( F_71 , & V_104 , 1 ) ;
}
static void T_6 F_75 ( int V_18 , T_1 V_9 )
{
void * V_25 = V_19 [ 0 ] . V_26 ;
struct V_105 * V_105 ;
if ( F_76 () )
return;
if ( ! V_106 && ( V_9 == V_107 ||
V_108 . type != V_109 ) )
return;
V_105 = F_77 ( V_18 ) ;
if ( ! V_105 )
F_78 ( L_1 ) ;
if ( V_9 == V_107 ) {
F_79 ( 1 , ( void * ) V_105 , sizeof( * V_105 ) ,
V_110 - V_38 , 0 ) ;
return;
}
F_1 ( V_9 , V_111 , 0 , NULL ) ;
F_80 ( V_105 , V_25 + V_110 , sizeof( * V_105 ) ) ;
}
int F_81 ( int V_18 )
{
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
if ( F_1 ( V_7 -> V_9 , V_111 ,
0 , NULL ) != V_112 )
return - V_113 ;
return 0 ;
}
static inline void F_75 ( int V_18 , T_1 V_9 ) { }
void F_82 ( int V_18 , int V_114 )
{
V_19 [ V_18 ] . V_115 = V_114 ;
}
int F_83 ( int V_18 )
{
return V_19 [ V_18 ] . V_115 ;
}
static struct V_116 * F_84 ( void )
{
static int V_117 ;
struct V_116 * V_96 ;
int V_9 ;
V_96 = F_85 ( sizeof( * V_96 ) , V_27 ) ;
if ( V_96 && ( V_117 || F_86 ( V_96 ) ) ) {
V_117 = 1 ;
for ( V_9 = 0 ; V_9 <= V_118 ; V_9 ++ ) {
if ( F_1 ( V_9 , V_11 , 0 , NULL ) ==
V_119 )
continue;
V_96 -> V_18 [ V_96 -> V_120 ] . V_9 = V_9 ;
V_96 -> V_120 ++ ;
}
V_96 -> V_121 = V_96 -> V_120 ;
}
return V_96 ;
}
static int F_87 ( struct V_116 * V_96 , int V_122 )
{
struct V_7 * V_7 ;
T_4 V_123 ;
int V_18 , V_124 , V_125 ;
V_124 = 0 ;
F_88 ( & V_123 , V_126 , V_127 ) ;
V_18 = F_39 ( & V_123 ) ;
for ( V_125 = 0 ; ( V_125 < V_96 -> V_121 ) && ( V_18 < V_128 ) ; V_125 ++ ) {
if ( V_96 -> V_129 && V_96 -> V_18 [ V_125 ] . type != V_130 )
continue;
if ( F_8 ( V_127 , V_96 -> V_18 [ V_125 ] . V_9 ) )
continue;
V_7 = V_19 + V_18 ;
V_7 -> V_9 = V_96 -> V_18 [ V_125 ] . V_9 ;
V_7 -> V_131 = ( V_125 >= V_96 -> V_120 ) ?
V_132 : V_133 ;
F_82 ( V_18 , V_134 ) ;
F_89 ( V_18 , true ) ;
if ( V_122 && F_90 ( V_18 ) != 0 )
F_89 ( V_18 , false ) ;
else
V_124 ++ ;
V_18 = F_91 ( V_18 , & V_123 ) ;
}
return V_124 ;
}
static void T_6 F_92 ( void )
{
unsigned int V_18 , V_135 , V_136 ;
struct V_116 * V_96 ;
V_96 = F_84 () ;
if ( ! V_96 )
F_78 ( L_2 ) ;
if ( V_96 -> V_129 ) {
for ( V_18 = 0 ; V_18 < V_96 -> V_121 ; V_18 ++ ) {
if ( V_96 -> V_18 [ V_18 ] . V_9 != V_107 )
continue;
V_130 = V_96 -> V_18 [ V_18 ] . type ;
break;
}
}
V_135 = V_136 = 0 ;
for ( V_18 = 0 ; V_18 < V_96 -> V_121 ; V_18 ++ ) {
if ( V_96 -> V_129 && V_96 -> V_18 [ V_18 ] . type != V_130 )
continue;
if ( V_18 < V_96 -> V_120 ) {
F_75 ( V_135 , V_96 -> V_18 [ V_18 ] . V_9 ) ;
V_135 ++ ;
} else
V_136 ++ ;
}
F_93 ( L_3 , V_135 , V_136 ) ;
F_94 () ;
F_87 ( V_96 , 0 ) ;
F_95 () ;
F_96 ( V_96 ) ;
}
static void F_97 ( void * V_137 )
{
V_34 . V_138 = F_47 () ;
V_34 . V_71 = ( unsigned long ) V_71 ;
V_34 . V_72 = ( unsigned long ) V_139 ;
V_34 . V_73 = 0 ;
V_34 . V_74 = - 1UL ;
F_98 ( V_34 . V_60 ) ;
F_72 ( V_34 . V_59 , 0 , 15 ) ;
F_36 ( V_78 | V_85 ) ;
F_99 () ;
F_100 () ;
F_101 () ;
F_102 () ;
F_103 () ;
F_104 ( F_55 () ) ;
F_105 ( F_55 () , true ) ;
F_63 ( V_140 ) ;
F_106 () ;
F_107 ( V_141 ) ;
}
int F_108 ( unsigned int V_18 , struct V_63 * V_142 )
{
struct V_7 * V_7 ;
int V_143 ;
V_7 = V_19 + V_18 ;
if ( V_7 -> V_131 != V_133 )
return - V_113 ;
if ( F_4 ( V_7 , V_144 , 0 ) !=
V_112 )
return - V_113 ;
V_143 = F_12 ( V_7 , V_18 ) ;
if ( V_143 )
return V_143 ;
F_23 ( V_7 , V_18 ) ;
F_29 ( V_7 , V_142 ) ;
F_32 ( V_7 , F_97 , NULL ) ;
while ( ! F_109 ( V_18 ) )
F_3 () ;
return 0 ;
}
static int T_6 F_110 ( char * V_145 )
{
F_111 ( & V_145 , & V_146 ) ;
return 0 ;
}
int F_112 ( void )
{
unsigned long V_99 [ 16 ] ;
F_56 () ;
F_105 ( F_55 () , false ) ;
F_113 () ;
F_27 ( V_99 , 0 , 15 ) ;
V_99 [ 0 ] &= ~ 0x0000ee70UL ;
V_99 [ 6 ] &= ~ 0xff000000UL ;
V_99 [ 14 ] &= ~ 0x1f000000UL ;
F_72 ( V_99 , 0 , 15 ) ;
return 0 ;
}
void F_114 ( unsigned int V_18 )
{
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
F_21 ( V_7 ) ;
F_115 ( & V_47 . V_48 . V_50 ) ;
F_49 ( V_18 , F_25 ( & V_47 ) ) ;
if ( V_46 )
F_49 ( V_18 , & V_47 . V_48 . V_49 ) ;
}
void T_7 F_116 ( void )
{
F_117 () ;
F_4 ( V_19 + F_55 () , V_79 , 0 ) ;
for (; ; ) ;
}
void T_6 F_118 ( void )
{
unsigned int V_147 , V_148 , V_18 ;
V_148 = F_119 () ? : V_128 ;
V_147 = V_146 ? : V_128 ;
V_147 = F_120 ( V_147 , V_148 ) ;
for ( V_18 = 0 ; V_18 < V_147 && V_18 < V_128 ; V_18 ++ )
F_121 ( V_18 , true ) ;
}
void T_6 F_122 ( unsigned int V_149 )
{
if ( F_123 ( V_150 , F_62 ) )
F_78 ( L_4 ) ;
if ( F_123 ( V_151 , F_62 ) )
F_78 ( L_5 ) ;
F_92 () ;
}
void T_6 F_124 ( void )
{
struct V_7 * V_7 = V_19 ;
V_107 = F_35 () ;
V_7 -> V_131 = V_133 ;
V_7 -> V_9 = V_107 ;
V_7 -> V_26 = (struct V_24 * ) ( unsigned long ) F_125 () ;
V_7 -> V_30 = V_34 . V_30 - V_35
+ V_36 + sizeof( struct V_37 ) ;
V_7 -> V_32 = V_34 . V_32 - V_38
+ V_36 + sizeof( struct V_37 ) ;
V_34 . V_51 = V_52 [ 0 ] ;
F_82 ( 0 , V_134 ) ;
F_89 ( 0 , true ) ;
F_105 ( 0 , true ) ;
}
void T_6 F_126 ( unsigned int V_149 )
{
}
void T_6 F_127 ( void )
{
V_34 . V_39 = 0 ;
V_34 . V_40 = F_15 ( 0 ) ;
}
int F_128 ( unsigned int V_152 )
{
return 0 ;
}
static T_8 F_129 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
T_8 V_158 ;
F_130 ( & V_159 ) ;
V_158 = sprintf ( V_157 , L_6 , V_19 [ V_154 -> V_160 ] . V_131 ) ;
F_131 ( & V_159 ) ;
return V_158 ;
}
static T_8 F_132 ( struct V_153 * V_154 ,
struct V_155 * V_156 ,
const char * V_157 , T_9 V_158 )
{
struct V_7 * V_7 ;
int V_18 , V_114 , V_143 ;
char V_161 ;
if ( sscanf ( V_157 , L_7 , & V_114 , & V_161 ) != 1 )
return - V_162 ;
if ( V_114 != 0 && V_114 != 1 )
return - V_162 ;
F_94 () ;
F_130 ( & V_159 ) ;
V_143 = - V_163 ;
V_18 = V_154 -> V_160 ;
if ( F_109 ( V_18 ) || V_18 == 0 )
goto V_33;
V_7 = V_19 + V_18 ;
V_143 = 0 ;
switch ( V_114 ) {
case 0 :
if ( V_7 -> V_131 != V_133 )
break;
V_143 = F_133 ( V_7 -> V_9 ) ;
if ( V_143 )
break;
V_7 -> V_131 = V_132 ;
F_82 ( V_18 , V_134 ) ;
F_134 () ;
break;
case 1 :
if ( V_7 -> V_131 != V_132 )
break;
V_143 = F_135 ( V_7 -> V_9 ) ;
if ( V_143 )
break;
V_7 -> V_131 = V_133 ;
F_82 ( V_18 , V_134 ) ;
F_134 () ;
break;
default:
break;
}
V_33:
F_131 ( & V_159 ) ;
F_95 () ;
return V_143 ? V_143 : V_158 ;
}
static T_8 F_136 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
return sprintf ( V_157 , L_6 , V_19 [ V_154 -> V_160 ] . V_9 ) ;
}
static T_8 F_137 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
struct V_164 * V_165 = & F_138 ( V_166 , V_154 -> V_160 ) ;
unsigned long long V_167 ;
unsigned int V_168 ;
do {
V_168 = F_139 ( V_165 -> V_168 ) ;
V_167 = F_139 ( V_165 -> V_167 ) ;
if ( F_139 ( V_165 -> V_169 ) )
V_167 ++ ;
} while ( ( V_168 & 1 ) || ( F_139 ( V_165 -> V_168 ) != V_168 ) );
return sprintf ( V_157 , L_8 , V_167 ) ;
}
static T_8 F_140 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
struct V_164 * V_165 = & F_138 ( V_166 , V_154 -> V_160 ) ;
unsigned long long V_170 , V_171 , V_172 , V_173 ;
unsigned int V_168 ;
do {
V_170 = F_47 () ;
V_168 = F_139 ( V_165 -> V_168 ) ;
V_171 = F_139 ( V_165 -> V_171 ) ;
V_172 = F_139 ( V_165 -> V_169 ) ;
V_173 = F_139 ( V_165 -> V_174 ) ;
} while ( ( V_168 & 1 ) || ( F_139 ( V_165 -> V_168 ) != V_168 ) );
V_171 += V_172 ? ( ( V_173 ? : V_170 ) - V_172 ) : 0 ;
return sprintf ( V_157 , L_8 , V_171 >> 12 ) ;
}
static int F_141 ( struct V_175 * V_176 , unsigned long V_177 ,
void * V_178 )
{
unsigned int V_18 = ( unsigned int ) ( long ) V_178 ;
struct V_18 * V_179 = V_19 [ V_18 ] . V_18 ;
struct V_153 * V_145 = & V_179 -> V_154 ;
int V_180 = 0 ;
switch ( V_177 & ~ V_181 ) {
case V_182 :
V_180 = F_142 ( & V_145 -> V_183 , & V_184 ) ;
break;
case V_185 :
F_143 ( & V_145 -> V_183 , & V_184 ) ;
break;
}
return F_144 ( V_180 ) ;
}
static int F_90 ( int V_18 )
{
struct V_153 * V_145 ;
struct V_18 * V_179 ;
int V_143 ;
V_179 = F_85 ( sizeof( * V_179 ) , V_27 ) ;
if ( ! V_179 )
return - V_45 ;
V_19 [ V_18 ] . V_18 = V_179 ;
V_145 = & V_179 -> V_154 ;
V_179 -> V_186 = 1 ;
V_143 = F_145 ( V_179 , V_18 ) ;
if ( V_143 )
goto V_33;
V_143 = F_142 ( & V_145 -> V_183 , & V_187 ) ;
if ( V_143 )
goto V_188;
if ( F_109 ( V_18 ) ) {
V_143 = F_142 ( & V_145 -> V_183 , & V_184 ) ;
if ( V_143 )
goto V_189;
}
V_143 = F_146 ( V_179 ) ;
if ( V_143 )
goto V_190;
return 0 ;
V_190:
if ( F_109 ( V_18 ) )
F_143 ( & V_145 -> V_183 , & V_184 ) ;
V_189:
F_143 ( & V_145 -> V_183 , & V_187 ) ;
V_188:
#ifdef F_147
F_148 ( V_179 ) ;
#endif
V_33:
return V_143 ;
}
int T_10 F_149 ( void )
{
struct V_116 * V_96 ;
int V_124 ;
V_96 = F_84 () ;
if ( ! V_96 )
return - V_45 ;
F_94 () ;
F_130 ( & V_159 ) ;
V_124 = F_87 ( V_96 , 1 ) ;
F_131 ( & V_159 ) ;
F_95 () ;
F_96 ( V_96 ) ;
if ( V_124 )
F_150 () ;
return 0 ;
}
static T_8 T_10 F_151 ( struct V_153 * V_154 ,
struct V_155 * V_156 ,
const char * V_157 ,
T_9 V_158 )
{
int V_143 ;
V_143 = F_149 () ;
return V_143 ? V_143 : V_158 ;
}
static int T_6 F_152 ( void )
{
int V_18 , V_143 = 0 ;
#ifdef F_147
V_143 = F_153 ( V_191 . V_192 , & V_193 ) ;
if ( V_143 )
return V_143 ;
#endif
F_154 () ;
F_42 (cpu) {
V_143 = F_90 ( V_18 ) ;
if ( V_143 )
goto V_33;
}
F_155 ( F_141 , 0 ) ;
V_33:
F_156 () ;
return V_143 ;
}
