static inline int F_1 ( T_1 V_1 , T_2 V_2 , unsigned long V_3 ,
T_3 * V_4 )
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
if ( V_43 )
V_25 -> V_44 =
( unsigned long ) & V_25 -> V_45 ;
if ( F_18 ( V_25 ) )
goto V_33;
#endif
V_46 [ V_18 ] = V_25 ;
F_4 ( V_7 , V_47 , ( T_3 ) ( unsigned long ) V_25 ) ;
return 0 ;
V_33:
if ( V_7 != & V_19 [ 0 ] ) {
F_19 ( V_7 -> V_32 ) ;
F_20 ( V_7 -> V_30 , V_31 ) ;
F_20 ( ( unsigned long ) V_7 -> V_26 , V_29 ) ;
}
return - V_48 ;
}
static void F_21 ( struct V_7 * V_7 )
{
F_4 ( V_7 , V_47 , 0 ) ;
V_46 [ V_7 - V_19 ] = NULL ;
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
if ( V_49 )
F_24 ( V_18 , & V_50 . V_51 . V_52 ) ;
F_24 ( V_18 , F_25 ( & V_50 ) ) ;
F_26 ( & V_50 . V_51 . V_53 ) ;
V_25 -> V_39 = V_18 ;
V_25 -> V_40 = F_15 ( V_18 ) ;
V_25 -> V_54 = V_55 [ V_18 ] ;
V_25 -> V_56 = V_34 . V_56 ;
V_25 -> V_57 = V_34 . V_57 ;
V_25 -> V_58 = V_25 -> V_59 = V_25 -> V_60 = 0 ;
F_27 ( V_25 -> V_61 , 0 , 15 ) ;
F_28 ( ( unsigned int * ) V_25 -> V_62 ) ;
memcpy ( V_25 -> V_63 , V_34 . V_63 ,
V_64 / 8 ) ;
}
static void F_29 ( struct V_7 * V_7 , struct V_65 * V_66 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_67 * V_68 = F_30 ( V_66 ) ;
V_25 -> V_69 = ( unsigned long ) F_31 ( V_66 )
+ V_70 - V_36 - sizeof( struct V_37 ) ;
V_25 -> V_67 = ( unsigned long ) F_30 ( V_66 ) ;
V_25 -> V_71 = ( unsigned long ) V_66 ;
V_25 -> V_58 = V_68 -> V_58 ;
V_25 -> V_59 = V_68 -> V_59 ;
V_25 -> V_60 = 0 ;
}
static void F_32 ( struct V_7 * V_7 , void (* F_33)( void * ) , void * V_72 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
V_25 -> V_73 = V_25 -> V_69 ;
V_25 -> V_74 = ( unsigned long ) F_33 ;
V_25 -> V_75 = ( unsigned long ) V_72 ;
V_25 -> V_76 = - 1UL ;
F_4 ( V_7 , V_77 , 0 ) ;
}
static void F_34 ( struct V_7 * V_7 , void (* F_33)( void * ) ,
void * V_72 , unsigned long V_78 )
{
struct V_24 * V_25 = V_46 [ V_7 - V_19 ] ;
unsigned long V_79 = F_35 () ;
F_36 ( V_80 ) ;
if ( V_7 -> V_9 == V_79 )
F_33 ( V_72 ) ;
F_4 ( V_7 , V_81 , 0 ) ;
F_37 ( V_25 -> V_73 , V_78 ) ;
F_37 ( V_25 -> V_74 , ( unsigned long ) F_33 ) ;
F_37 ( V_25 -> V_75 , ( unsigned long ) V_72 ) ;
F_37 ( V_25 -> V_76 , V_79 ) ;
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
void F_38 ( void (* F_33)( void * ) , void * V_72 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_82 , F_35 () ) ;
if ( ! V_7 )
V_7 = V_19 + F_39 ( V_82 ) ;
F_34 ( V_7 , F_33 , V_72 , ( unsigned long ) V_73 ) ;
}
void F_40 ( void (* F_33)( void * ) , void * V_72 )
{
F_34 ( & V_19 [ 0 ] , F_33 , V_72 ,
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
void F_44 ( int V_18 )
{
if ( V_83 )
asm volatile("diag %0,0,0x9c"
: : "d" (pcpu_devices[cpu].address));
else if ( V_84 )
asm volatile("diag 0,0,0x44");
}
static void F_45 ( T_4 * V_16 )
{
T_5 V_85 ;
int V_18 ;
V_85 = F_46 () + ( 1000000UL << 12 ) ;
F_9 (cpu, cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_47 ( V_86 , & V_7 -> V_21 ) ;
while ( F_2 ( V_7 -> V_9 , V_23 ,
0 , NULL ) == V_6 &&
F_46 () < V_85 )
F_3 () ;
}
while ( F_46 () < V_85 ) {
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
F_36 ( V_80 | V_87 ) ;
F_51 () ;
F_52 () ;
F_53 ( & V_16 , V_82 ) ;
F_48 ( F_54 () , & V_16 ) ;
if ( V_88 )
F_45 ( & V_16 ) ;
F_9 (cpu, &cpumask) {
struct V_7 * V_7 = V_19 + V_18 ;
F_4 ( V_7 , V_81 , 0 ) ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
}
}
static void F_55 ( void )
{
unsigned long V_89 ;
V_89 = F_56 ( & V_19 [ F_54 () ] . V_21 , 0 ) ;
if ( F_57 ( V_86 , & V_89 ) )
F_58 () ;
if ( F_57 ( V_90 , & V_89 ) )
F_59 () ;
if ( F_57 ( V_91 , & V_89 ) )
F_60 () ;
}
static void F_61 ( struct V_92 V_92 ,
unsigned int V_93 , unsigned long V_94 )
{
F_62 ( V_92 . V_95 == 0x1202 ? V_96 : V_97 ) ;
F_55 () ;
}
void F_63 ( const struct V_16 * V_17 )
{
int V_18 ;
F_9 (cpu, mask)
F_10 ( V_19 + V_18 , V_91 ) ;
}
void F_64 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_91 ) ;
}
static void F_65 ( void * V_98 )
{
F_66 () ;
}
void F_67 ( void )
{
F_68 ( F_65 , NULL , 1 ) ;
}
void F_69 ( int V_18 )
{
F_10 ( V_19 + V_18 , V_90 ) ;
}
static void F_70 ( void * V_98 )
{
struct V_99 * V_100 = V_98 ;
unsigned long V_101 [ 16 ] ;
F_27 ( V_101 , 0 , 15 ) ;
V_101 [ V_100 -> V_102 ] = ( V_101 [ V_100 -> V_102 ] & V_100 -> V_103 ) | V_100 -> V_104 ;
F_71 ( V_101 , 0 , 15 ) ;
}
void F_72 ( int V_102 , int V_105 )
{
struct V_99 V_106 = { 1UL << V_105 , - 1UL , V_102 } ;
F_68 ( F_70 , & V_106 , 1 ) ;
}
void F_73 ( int V_102 , int V_105 )
{
struct V_99 V_106 = { 0 , ~ ( 1UL << V_105 ) , V_102 } ;
F_68 ( F_70 , & V_106 , 1 ) ;
}
static void T_6 F_74 ( int V_18 , T_1 V_9 )
{
void * V_25 = V_19 [ 0 ] . V_26 ;
struct V_107 * V_108 ;
unsigned long V_109 ;
if ( F_75 () )
return;
if ( ! V_110 && ( V_9 == V_111 ||
V_112 . type != V_113 ) )
return;
V_108 = F_76 ( V_18 ) ;
if ( ! V_108 )
F_77 ( L_1 ) ;
if ( V_9 == V_111 ) {
F_78 ( 1 , ( void * ) & V_108 -> V_114 , sizeof( V_108 -> V_114 ) ,
V_115 - V_38 , 0 ) ;
if ( V_43 )
F_79 ( V_108 -> V_116 ) ;
return;
}
F_1 ( V_9 , V_117 , 0 , NULL ) ;
F_80 ( & V_108 -> V_114 , V_25 + V_115 , sizeof( V_108 -> V_114 ) ) ;
if ( ! V_43 )
return;
V_109 = F_14 ( V_27 ) ;
if ( ! V_109 )
F_77 ( L_2 ) ;
F_1 ( V_9 , V_118 , V_109 , NULL ) ;
memcpy ( V_108 -> V_116 , ( void * ) V_109 , sizeof( V_108 -> V_116 ) ) ;
F_19 ( V_109 ) ;
}
int F_81 ( int V_18 )
{
unsigned long V_109 ;
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
if ( F_1 ( V_7 -> V_9 , V_117 ,
0 , NULL ) != V_119 )
return - V_120 ;
if ( ! V_43 )
return 0 ;
V_109 = F_82 ( V_7 -> V_26 -> V_44 ) ;
F_1 ( V_7 -> V_9 , V_118 ,
V_109 , NULL ) ;
return 0 ;
}
static inline void F_74 ( int V_18 , T_1 V_9 ) { }
void F_83 ( int V_18 , int V_121 )
{
V_19 [ V_18 ] . V_122 = V_121 ;
}
int F_84 ( int V_18 )
{
return V_19 [ V_18 ] . V_122 ;
}
static struct V_123 * F_85 ( void )
{
static int V_124 ;
struct V_123 * V_98 ;
int V_9 ;
V_98 = F_86 ( sizeof( * V_98 ) , V_27 ) ;
if ( V_98 && ( V_124 || F_87 ( V_98 ) ) ) {
V_124 = 1 ;
for ( V_9 = 0 ; V_9 <= V_125 ; V_9 ++ ) {
if ( F_1 ( V_9 , V_11 , 0 , NULL ) ==
V_126 )
continue;
V_98 -> V_18 [ V_98 -> V_127 ] . V_9 = V_9 ;
V_98 -> V_127 ++ ;
}
V_98 -> V_128 = V_98 -> V_127 ;
}
return V_98 ;
}
static int F_88 ( struct V_123 * V_98 , int V_129 )
{
struct V_7 * V_7 ;
T_4 V_130 ;
int V_18 , V_131 , V_132 ;
V_131 = 0 ;
F_89 ( & V_130 , V_133 , V_134 ) ;
V_18 = F_39 ( & V_130 ) ;
for ( V_132 = 0 ; ( V_132 < V_98 -> V_128 ) && ( V_18 < V_135 ) ; V_132 ++ ) {
if ( V_98 -> V_136 && V_98 -> V_18 [ V_132 ] . type != V_137 )
continue;
if ( F_8 ( V_134 , V_98 -> V_18 [ V_132 ] . V_9 ) )
continue;
V_7 = V_19 + V_18 ;
V_7 -> V_9 = V_98 -> V_18 [ V_132 ] . V_9 ;
V_7 -> V_138 = ( V_132 >= V_98 -> V_127 ) ?
V_139 : V_140 ;
F_83 ( V_18 , V_141 ) ;
F_90 ( V_18 , true ) ;
if ( V_129 && F_91 ( V_18 ) != 0 )
F_90 ( V_18 , false ) ;
else
V_131 ++ ;
V_18 = F_92 ( V_18 , & V_130 ) ;
}
return V_131 ;
}
static void T_6 F_93 ( void )
{
unsigned int V_18 , V_142 , V_143 ;
struct V_123 * V_98 ;
V_98 = F_85 () ;
if ( ! V_98 )
F_77 ( L_3 ) ;
if ( V_98 -> V_136 ) {
for ( V_18 = 0 ; V_18 < V_98 -> V_128 ; V_18 ++ ) {
if ( V_98 -> V_18 [ V_18 ] . V_9 != V_111 )
continue;
V_137 = V_98 -> V_18 [ V_18 ] . type ;
break;
}
}
V_142 = V_143 = 0 ;
for ( V_18 = 0 ; V_18 < V_98 -> V_128 ; V_18 ++ ) {
if ( V_98 -> V_136 && V_98 -> V_18 [ V_18 ] . type != V_137 )
continue;
if ( V_18 < V_98 -> V_127 ) {
F_74 ( V_142 , V_98 -> V_18 [ V_18 ] . V_9 ) ;
V_142 ++ ;
} else
V_143 ++ ;
}
F_94 ( L_4 , V_142 , V_143 ) ;
F_95 () ;
F_88 ( V_98 , 0 ) ;
F_96 () ;
F_97 ( V_98 ) ;
}
static void F_98 ( void * V_144 )
{
V_34 . V_145 = F_46 () ;
V_34 . V_73 = ( unsigned long ) V_73 ;
V_34 . V_74 = ( unsigned long ) V_146 ;
V_34 . V_75 = 0 ;
V_34 . V_76 = - 1UL ;
F_99 ( V_34 . V_62 ) ;
F_71 ( V_34 . V_61 , 0 , 15 ) ;
F_36 ( V_80 | V_87 ) ;
F_100 () ;
F_101 () ;
F_102 () ;
F_103 () ;
F_104 () ;
F_105 ( F_54 () ) ;
F_106 ( F_54 () , true ) ;
F_62 ( V_147 ) ;
F_107 () ;
F_108 ( V_148 ) ;
}
int F_109 ( unsigned int V_18 , struct V_65 * V_149 )
{
struct V_7 * V_7 ;
int V_150 ;
V_7 = V_19 + V_18 ;
if ( V_7 -> V_138 != V_140 )
return - V_120 ;
if ( F_4 ( V_7 , V_151 , 0 ) !=
V_119 )
return - V_120 ;
V_150 = F_12 ( V_7 , V_18 ) ;
if ( V_150 )
return V_150 ;
F_23 ( V_7 , V_18 ) ;
F_29 ( V_7 , V_149 ) ;
F_32 ( V_7 , F_98 , NULL ) ;
while ( ! F_110 ( V_18 ) )
F_3 () ;
return 0 ;
}
static int T_6 F_111 ( char * V_152 )
{
F_112 ( & V_152 , & V_153 ) ;
return 0 ;
}
int F_113 ( void )
{
unsigned long V_101 [ 16 ] ;
F_55 () ;
F_106 ( F_54 () , false ) ;
F_114 () ;
F_27 ( V_101 , 0 , 15 ) ;
V_101 [ 0 ] &= ~ 0x0000ee70UL ;
V_101 [ 6 ] &= ~ 0xff000000UL ;
V_101 [ 14 ] &= ~ 0x1f000000UL ;
F_71 ( V_101 , 0 , 15 ) ;
F_115 ( V_154 ) ;
return 0 ;
}
void F_116 ( unsigned int V_18 )
{
struct V_7 * V_7 ;
V_7 = V_19 + V_18 ;
while ( ! F_6 ( V_7 ) )
F_3 () ;
F_21 ( V_7 ) ;
F_117 ( & V_50 . V_51 . V_53 ) ;
F_48 ( V_18 , F_25 ( & V_50 ) ) ;
if ( V_49 )
F_48 ( V_18 , & V_50 . V_51 . V_52 ) ;
}
void T_7 F_118 ( void )
{
F_119 () ;
F_4 ( V_19 + F_54 () , V_81 , 0 ) ;
for (; ; ) ;
}
void T_6 F_120 ( void )
{
unsigned int V_155 , V_156 , V_18 ;
V_156 = F_121 () ? : V_135 ;
V_155 = V_153 ? : V_135 ;
V_155 = F_122 ( V_155 , V_156 ) ;
for ( V_18 = 0 ; V_18 < V_155 && V_18 < V_135 ; V_18 ++ )
F_123 ( V_18 , true ) ;
}
void T_6 F_124 ( unsigned int V_157 )
{
if ( F_125 ( V_158 , F_61 ) )
F_77 ( L_5 ) ;
if ( F_125 ( V_159 , F_61 ) )
F_77 ( L_6 ) ;
F_93 () ;
}
void T_6 F_126 ( void )
{
struct V_7 * V_7 = V_19 ;
V_111 = F_35 () ;
V_7 -> V_138 = V_140 ;
V_7 -> V_9 = V_111 ;
V_7 -> V_26 = (struct V_24 * ) ( unsigned long ) F_127 () ;
V_7 -> V_30 = V_34 . V_30 - V_35
+ V_36 + sizeof( struct V_37 ) ;
V_7 -> V_32 = V_34 . V_32 - V_38
+ V_36 + sizeof( struct V_37 ) ;
V_34 . V_54 = V_55 [ 0 ] ;
F_83 ( 0 , V_141 ) ;
F_90 ( 0 , true ) ;
F_106 ( 0 , true ) ;
}
void T_6 F_128 ( unsigned int V_157 )
{
}
void T_6 F_129 ( void )
{
V_34 . V_39 = 0 ;
V_34 . V_40 = F_15 ( 0 ) ;
}
int F_130 ( unsigned int V_160 )
{
return 0 ;
}
static T_8 F_131 ( struct V_161 * V_162 ,
struct V_163 * V_164 , char * V_165 )
{
T_8 V_166 ;
F_132 ( & V_167 ) ;
V_166 = sprintf ( V_165 , L_7 , V_19 [ V_162 -> V_168 ] . V_138 ) ;
F_133 ( & V_167 ) ;
return V_166 ;
}
static T_8 F_134 ( struct V_161 * V_162 ,
struct V_163 * V_164 ,
const char * V_165 , T_9 V_166 )
{
struct V_7 * V_7 ;
int V_18 , V_121 , V_150 ;
char V_169 ;
if ( sscanf ( V_165 , L_8 , & V_121 , & V_169 ) != 1 )
return - V_170 ;
if ( V_121 != 0 && V_121 != 1 )
return - V_170 ;
F_95 () ;
F_132 ( & V_167 ) ;
V_150 = - V_171 ;
V_18 = V_162 -> V_168 ;
if ( F_110 ( V_18 ) || V_18 == 0 )
goto V_33;
V_7 = V_19 + V_18 ;
V_150 = 0 ;
switch ( V_121 ) {
case 0 :
if ( V_7 -> V_138 != V_140 )
break;
V_150 = F_135 ( V_7 -> V_9 ) ;
if ( V_150 )
break;
V_7 -> V_138 = V_139 ;
F_83 ( V_18 , V_141 ) ;
F_136 () ;
break;
case 1 :
if ( V_7 -> V_138 != V_139 )
break;
V_150 = F_137 ( V_7 -> V_9 ) ;
if ( V_150 )
break;
V_7 -> V_138 = V_140 ;
F_83 ( V_18 , V_141 ) ;
F_136 () ;
break;
default:
break;
}
V_33:
F_133 ( & V_167 ) ;
F_96 () ;
return V_150 ? V_150 : V_166 ;
}
static T_8 F_138 ( struct V_161 * V_162 ,
struct V_163 * V_164 , char * V_165 )
{
return sprintf ( V_165 , L_7 , V_19 [ V_162 -> V_168 ] . V_9 ) ;
}
static int F_139 ( struct V_172 * V_173 , unsigned long V_174 ,
void * V_175 )
{
unsigned int V_18 = ( unsigned int ) ( long ) V_175 ;
struct V_18 * V_176 = V_19 [ V_18 ] . V_18 ;
struct V_161 * V_152 = & V_176 -> V_162 ;
int V_177 = 0 ;
switch ( V_174 & ~ V_178 ) {
case V_179 :
V_177 = F_140 ( & V_152 -> V_180 , & V_181 ) ;
break;
case V_182 :
F_141 ( & V_152 -> V_180 , & V_181 ) ;
break;
}
return F_142 ( V_177 ) ;
}
static int F_91 ( int V_18 )
{
struct V_161 * V_152 ;
struct V_18 * V_176 ;
int V_150 ;
V_176 = F_86 ( sizeof( * V_176 ) , V_27 ) ;
if ( ! V_176 )
return - V_48 ;
V_19 [ V_18 ] . V_18 = V_176 ;
V_152 = & V_176 -> V_162 ;
V_176 -> V_183 = 1 ;
V_150 = F_143 ( V_176 , V_18 ) ;
if ( V_150 )
goto V_33;
V_150 = F_140 ( & V_152 -> V_180 , & V_184 ) ;
if ( V_150 )
goto V_185;
if ( F_110 ( V_18 ) ) {
V_150 = F_140 ( & V_152 -> V_180 , & V_181 ) ;
if ( V_150 )
goto V_186;
}
V_150 = F_144 ( V_176 ) ;
if ( V_150 )
goto V_187;
return 0 ;
V_187:
if ( F_110 ( V_18 ) )
F_141 ( & V_152 -> V_180 , & V_181 ) ;
V_186:
F_141 ( & V_152 -> V_180 , & V_184 ) ;
V_185:
#ifdef F_145
F_146 ( V_176 ) ;
#endif
V_33:
return V_150 ;
}
int T_10 F_147 ( void )
{
struct V_123 * V_98 ;
int V_131 ;
V_98 = F_85 () ;
if ( ! V_98 )
return - V_48 ;
F_95 () ;
F_132 ( & V_167 ) ;
V_131 = F_88 ( V_98 , 1 ) ;
F_133 ( & V_167 ) ;
F_96 () ;
F_97 ( V_98 ) ;
if ( V_131 )
F_148 () ;
return 0 ;
}
static T_8 T_10 F_149 ( struct V_161 * V_162 ,
struct V_163 * V_164 ,
const char * V_165 ,
T_9 V_166 )
{
int V_150 ;
V_150 = F_147 () ;
return V_150 ? V_150 : V_166 ;
}
static int T_6 F_150 ( void )
{
int V_18 , V_150 = 0 ;
#ifdef F_145
V_150 = F_151 ( V_188 . V_189 , & V_190 ) ;
if ( V_150 )
return V_150 ;
#endif
F_152 () ;
F_42 (cpu) {
V_150 = F_91 ( V_18 ) ;
if ( V_150 )
goto V_33;
}
F_153 ( F_139 , 0 ) ;
V_33:
F_154 () ;
return V_150 ;
}
