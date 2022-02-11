static int F_1 ( int V_1 )
{
T_1 V_2 ;
switch ( F_2 ( & V_2 , 0 , V_1 , V_3 ) ) {
case V_4 :
if ( V_2 & 0x50 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
static inline int F_3 ( int V_1 )
{
return F_1 ( F_4 ( V_1 ) ) ;
}
void F_5 ( void )
{
int V_1 ;
F_6 (cpu) {
if ( F_7 () == V_5 [ V_1 ] ) {
F_8 ( V_6 | V_7 ) ;
return;
}
}
while ( F_9 ( V_1 , V_8 ) == V_9 )
F_10 () ;
while ( F_11 ( F_7 () , V_10 ) == V_9 )
F_10 () ;
for (; ; ) ;
}
void F_12 ( void (* F_13)( void * ) , void * V_11 )
{
struct V_12 * V_13 , * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
if ( F_14 () == 0 )
F_13 ( V_11 ) ;
F_8 ( V_20 | V_21 |
V_22 | V_23 ) ;
F_15 ( 0 , 28 ) ;
V_14 = V_24 [ F_14 () ] ;
V_13 = V_24 [ 0 ] ;
if ( ! V_13 )
V_13 = V_14 ;
V_13 -> V_25 . V_26 =
V_20 | V_21 | V_22 | V_23 ;
V_13 -> V_25 . V_27 = V_28 | ( unsigned long ) V_29 ;
if ( ! F_16 ( 0 ) )
F_17 ( F_13 , V_11 , 0 , F_7 () , V_5 [ 0 ] ) ;
while ( F_9 ( 0 , V_30 ) == V_9 )
F_10 () ;
V_19 = V_13 -> V_31 ;
V_19 -= sizeof( struct V_17 ) ;
V_18 = (struct V_17 * ) V_19 ;
memcpy ( & V_18 -> V_32 , & V_14 -> V_33 , sizeof( V_18 -> V_32 ) ) ;
V_18 -> V_34 = V_14 -> V_35 ;
V_19 -= V_36 ;
V_16 = (struct V_15 * ) V_19 ;
V_16 -> V_37 = 0 ;
F_17 ( F_13 , V_11 , V_19 , F_7 () , V_5 [ 0 ] ) ;
}
static void F_18 ( void )
{
while ( F_9 ( F_14 () , V_10 ) == V_9 )
F_10 () ;
}
void F_19 ( void )
{
T_2 V_38 ;
int V_1 ;
T_3 V_39 ;
F_8 ( V_6 | V_7 ) ;
F_20 () ;
F_21 ( & V_38 , V_40 ) ;
F_22 ( F_14 () , & V_38 ) ;
if ( V_41 ) {
V_39 = F_23 () + ( 1000000UL << 12 ) ;
F_24 (cpu, &cpumask) {
F_25 ( V_42 , ( unsigned long * )
& V_24 [ V_1 ] -> V_43 ) ;
while ( F_9 ( V_1 , V_44 ) == V_9 &&
F_23 () < V_39 )
F_10 () ;
}
while ( F_23 () < V_39 ) {
F_24 (cpu, &cpumask)
if ( F_3 ( V_1 ) )
F_22 ( V_1 , & V_38 ) ;
if ( F_26 ( & V_38 ) )
break;
F_10 () ;
}
}
F_24 (cpu, &cpumask) {
while ( F_9 ( V_1 , V_10 ) == V_9 )
F_10 () ;
while ( ! F_3 ( V_1 ) )
F_10 () ;
}
}
static void F_27 ( unsigned int V_45 ,
unsigned int V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
if ( ( V_45 & 0xffff ) == 0x1202 )
F_28 ( F_14 () ) . V_49 [ V_50 ] ++ ;
else
F_28 ( F_14 () ) . V_49 [ V_51 ] ++ ;
V_48 = F_29 ( & V_52 . V_43 , 0 ) ;
if ( F_30 ( V_42 , & V_48 ) )
F_18 () ;
if ( F_30 ( V_53 , & V_48 ) )
F_31 () ;
if ( F_30 ( V_54 , & V_48 ) )
F_32 () ;
if ( F_30 ( V_55 , & V_48 ) )
F_33 () ;
}
static void F_34 ( int V_1 , int V_56 )
{
int V_57 ;
F_25 ( V_56 , ( unsigned long * ) & V_24 [ V_1 ] -> V_43 ) ;
while ( 1 ) {
V_57 = F_35 ( V_1 ) ?
V_58 : V_44 ;
if ( F_9 ( V_1 , V_57 ) != V_9 )
break;
F_36 ( 10 ) ;
}
}
void F_37 ( const struct V_38 * V_26 )
{
int V_1 ;
F_24 (cpu, mask)
F_34 ( V_1 , V_54 ) ;
}
void F_38 ( int V_1 )
{
F_34 ( V_1 , V_55 ) ;
}
static void F_39 ( void * V_59 )
{
F_40 () ;
}
void F_41 ( void )
{
F_42 ( F_39 , NULL , 1 ) ;
}
void F_43 ( int V_1 )
{
F_34 ( V_1 , V_53 ) ;
}
static void F_44 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
unsigned long V_62 [ 16 ] ;
int V_63 ;
F_45 ( V_62 , 0 , 15 ) ;
for ( V_63 = 0 ; V_63 <= 15 ; V_63 ++ )
V_62 [ V_63 ] = ( V_62 [ V_63 ] & V_61 -> V_64 [ V_63 ] ) | V_61 -> V_65 [ V_63 ] ;
F_46 ( V_62 , 0 , 15 ) ;
}
void F_47 ( int V_66 , int V_67 )
{
struct V_60 V_68 ;
memset ( & V_68 . V_65 , 0 , sizeof( V_68 . V_65 ) ) ;
memset ( & V_68 . V_64 , 0xff , sizeof( V_68 . V_64 ) ) ;
V_68 . V_65 [ V_66 ] = 1UL << V_67 ;
F_42 ( F_44 , & V_68 , 1 ) ;
}
void F_48 ( int V_66 , int V_67 )
{
struct V_60 V_68 ;
memset ( & V_68 . V_65 , 0 , sizeof( V_68 . V_65 ) ) ;
memset ( & V_68 . V_64 , 0xff , sizeof( V_68 . V_64 ) ) ;
V_68 . V_64 [ V_66 ] = ~ ( 1UL << V_67 ) ;
F_42 ( F_44 , & V_68 , 1 ) ;
}
static void T_4 F_49 ( unsigned int V_1 , unsigned int V_69 )
{
if ( V_70 . type != V_71 && ! V_72 )
return;
if ( F_50 () )
return;
if ( V_1 >= V_73 ) {
F_51 ( L_1
L_2 , V_1 , V_73 - 1 ) ;
return;
}
V_74 [ V_1 ] = F_52 ( sizeof( struct V_75 ) , V_76 ) ;
while ( F_11 ( V_69 , V_30 ) == V_9 )
F_10 () ;
F_53 ( V_74 [ V_1 ] ,
( void * ) ( unsigned long ) F_54 () + V_77 ,
sizeof( struct V_75 ) ) ;
}
static inline void F_49 ( unsigned int V_1 , unsigned int V_69 ) { }
static int F_55 ( int V_78 )
{
int V_1 ;
F_56 (cpu) {
if ( V_5 [ V_1 ] == V_78 )
return 1 ;
}
return 0 ;
}
static int F_57 ( T_2 V_79 )
{
int V_78 , V_80 ;
V_80 = F_58 ( & V_79 ) ;
if ( V_80 >= V_81 )
return 0 ;
for ( V_78 = 0 ; V_78 <= V_82 ; V_78 ++ ) {
if ( F_55 ( V_78 ) )
continue;
V_5 [ V_80 ] = V_78 ;
F_59 ( V_80 , V_83 ) ;
if ( ! F_3 ( V_80 ) )
continue;
F_60 ( V_80 , true ) ;
V_84 [ V_80 ] = V_85 ;
V_80 = F_61 ( V_80 , & V_79 ) ;
if ( V_80 >= V_81 )
break;
}
return 0 ;
}
static int F_62 ( T_2 V_79 )
{
struct V_86 * V_59 ;
int V_78 , V_80 , V_1 ;
int V_87 ;
V_80 = F_58 ( & V_79 ) ;
if ( V_80 >= V_81 )
return 0 ;
V_59 = F_52 ( sizeof( * V_59 ) , V_76 ) ;
if ( ! V_59 )
return - V_88 ;
V_87 = F_63 ( V_59 ) ;
if ( V_87 )
goto V_89;
for ( V_1 = 0 ; V_1 < V_59 -> V_90 ; V_1 ++ ) {
if ( V_59 -> V_91 && V_59 -> V_1 [ V_1 ] . type != V_92 )
continue;
V_78 = V_59 -> V_1 [ V_1 ] . V_93 ;
if ( F_55 ( V_78 ) )
continue;
V_5 [ V_80 ] = V_78 ;
F_59 ( V_80 , V_83 ) ;
F_60 ( V_80 , true ) ;
if ( V_1 >= V_59 -> V_94 )
V_84 [ V_80 ] = V_95 ;
else
V_84 [ V_80 ] = V_85 ;
V_80 = F_61 ( V_80 , & V_79 ) ;
if ( V_80 >= V_81 )
break;
}
V_89:
F_64 ( V_59 ) ;
return V_87 ;
}
static int F_65 ( void )
{
T_2 V_79 ;
F_66 ( & V_79 , V_96 , V_97 ) ;
if ( V_98 )
return F_57 ( V_79 ) ;
else
return F_62 ( V_79 ) ;
}
static void T_4 F_67 ( void )
{
unsigned int V_1 , V_99 , V_100 ;
struct V_86 * V_59 ;
T_5 V_101 , V_102 ;
V_99 = 1 ;
V_100 = 0 ;
V_101 = V_5 [ 0 ] ;
V_59 = F_52 ( sizeof( * V_59 ) , V_76 ) ;
if ( ! V_59 )
F_68 ( L_3 ) ;
#ifdef F_69
if ( V_72 && ! F_50 () ) {
struct V_75 * V_75 ;
V_75 = F_52 ( sizeof( * V_75 ) , V_76 ) ;
if ( ! V_75 )
F_68 ( L_4 ) ;
F_70 ( 1 , ( void * ) V_75 , sizeof( * V_75 ) ,
0x200 , 0 ) ;
V_74 [ 0 ] = V_75 ;
}
#endif
if ( F_63 ( V_59 ) ) {
V_98 = 1 ;
for ( V_1 = 0 ; V_1 <= V_82 ; V_1 ++ ) {
if ( V_1 == V_101 )
continue;
if ( ! F_1 ( V_1 ) )
continue;
F_49 ( V_99 , V_1 ) ;
V_99 ++ ;
}
goto V_89;
}
if ( V_59 -> V_91 ) {
for ( V_1 = 0 ; V_1 < V_59 -> V_90 ; V_1 ++ ) {
if ( V_59 -> V_1 [ V_1 ] . V_93 == V_101 ) {
V_92 = V_59 -> V_1 [ V_1 ] . type ;
break;
}
}
}
for ( V_1 = 0 ; V_1 < V_59 -> V_90 ; V_1 ++ ) {
if ( V_59 -> V_91 && V_59 -> V_1 [ V_1 ] . type != V_92 )
continue;
V_102 = V_59 -> V_1 [ V_1 ] . V_93 ;
if ( V_102 == V_101 )
continue;
if ( ! F_1 ( V_102 ) ) {
V_100 ++ ;
continue;
}
F_49 ( V_99 , V_102 ) ;
V_99 ++ ;
}
V_89:
F_64 ( V_59 ) ;
F_71 ( L_5 , V_99 , V_100 ) ;
F_72 () ;
F_65 () ;
F_73 () ;
}
int T_6 F_74 ( void * V_103 )
{
F_75 () ;
F_76 () ;
F_77 () ;
F_78 () ;
F_79 () ;
F_80 ( F_14 () ) ;
F_81 () ;
F_82 ( F_14 () , true ) ;
F_83 () ;
F_15 ( 0 , 28 ) ;
V_52 . V_25 . V_26 =
V_20 | V_21 | V_22 | V_23 ;
V_52 . V_25 . V_27 =
V_28 | ( unsigned long ) V_104 ;
F_84 ( 0 , 28 ) ;
while ( ! F_85 ( F_14 () , V_105 ) )
F_10 () ;
F_86 () ;
F_87 () ;
return 0 ;
}
static void T_6 F_88 ( struct V_106 * V_107 )
{
struct V_108 * V_109 ;
V_109 = F_89 ( V_107 , struct V_108 , V_107 ) ;
V_109 -> V_110 = F_90 ( V_109 -> V_1 ) ;
F_91 ( & V_109 -> V_111 ) ;
}
static int T_6 F_92 ( int V_1 )
{
unsigned long V_112 , V_31 ;
struct V_12 * V_113 ;
V_113 = ( void * ) F_93 ( V_76 | V_114 , V_115 ) ;
if ( ! V_113 )
return - V_88 ;
V_112 = F_93 ( V_76 , V_116 ) ;
V_31 = F_94 ( V_76 ) ;
if ( ! V_31 || ! V_112 )
goto V_89;
memcpy ( V_113 , & V_52 , 512 ) ;
memset ( ( char * ) V_113 + 512 , 0 , sizeof( * V_113 ) - 512 ) ;
V_113 -> V_112 = V_112 + V_117 ;
V_113 -> V_31 = V_31 + V_118 ;
V_113 -> V_25 . V_26 =
V_20 | V_21 | V_22 | V_23 ;
V_113 -> V_25 . V_27 =
V_28 | ( unsigned long ) V_119 ;
if ( V_120 != V_121 )
V_113 -> V_25 . V_26 |= V_122 ;
#ifndef F_95
if ( V_123 ) {
unsigned long V_75 ;
V_75 = F_96 ( V_76 ) ;
if ( ! V_75 )
goto V_89;
V_113 -> V_124 = ( T_1 ) V_75 ;
}
#else
if ( F_97 ( V_1 , V_113 ) )
goto V_89;
#endif
V_24 [ V_1 ] = V_113 ;
return 0 ;
V_89:
F_98 ( V_31 ) ;
F_99 ( V_112 , V_116 ) ;
F_99 ( ( unsigned long ) V_113 , V_115 ) ;
return - V_88 ;
}
static void F_100 ( int V_1 )
{
struct V_12 * V_113 ;
V_113 = V_24 [ V_1 ] ;
#ifndef F_95
if ( V_123 )
F_98 ( ( unsigned long ) V_113 -> V_124 ) ;
#else
F_101 ( V_1 , V_113 ) ;
#endif
F_98 ( V_113 -> V_31 - V_118 ) ;
F_99 ( V_113 -> V_112 - V_117 , V_116 ) ;
F_99 ( ( unsigned long ) V_113 , V_115 ) ;
V_24 [ V_1 ] = NULL ;
}
int T_6 F_102 ( unsigned int V_1 )
{
struct V_12 * V_125 ;
struct V_108 V_109 ;
struct V_126 * V_110 ;
struct V_15 * V_16 ;
T_1 V_113 ;
int V_127 ;
if ( V_84 [ V_1 ] != V_85 )
return - V_128 ;
V_110 = V_129 [ V_1 ] ;
if ( ! V_110 ) {
V_109 . V_111 = F_103 ( V_109 . V_111 ) ;
F_104 ( & V_109 . V_107 , F_88 ) ;
V_109 . V_1 = V_1 ;
F_105 ( & V_109 . V_107 ) ;
F_106 ( & V_109 . V_111 ) ;
if ( F_107 ( V_109 . V_110 ) )
return F_108 ( V_109 . V_110 ) ;
V_110 = V_109 . V_110 ;
V_129 [ V_1 ] = V_109 . V_110 ;
}
F_109 ( V_110 , V_1 ) ;
if ( F_92 ( V_1 ) )
return - V_88 ;
do {
V_127 = F_9 ( V_1 , V_130 ) ;
if ( V_127 == V_9 )
F_36 ( 10 ) ;
if ( V_127 == V_131 )
goto V_132;
} while ( V_127 == V_9 );
V_113 = ( T_1 ) ( unsigned long ) V_24 [ V_1 ] ;
while ( F_110 ( V_113 , V_1 , V_133 ) == V_9 )
F_36 ( 10 ) ;
V_125 = V_24 [ V_1 ] ;
V_125 -> V_134 = ( unsigned long )
F_111 ( V_110 ) + V_135 ;
V_125 -> V_136 = ( unsigned long ) F_112 ( V_110 ) ;
V_16 = (struct V_15 * ) ( V_125 -> V_134
- sizeof( struct V_17 )
- sizeof( struct V_15 ) ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_32 [ 9 ] = ( unsigned long ) V_16 ;
V_125 -> V_33 [ 15 ] = ( unsigned long ) V_16 ;
F_45 ( V_125 -> V_137 , 0 , 15 ) ;
F_113 ( & V_138 . V_139 . V_140 ) ;
asm volatile(
" stam 0,15,0(%0)"
: : "a" (&cpu_lowcore->access_regs_save_area) : "memory");
V_125 -> V_141 = V_142 [ V_1 ] ;
V_125 -> V_143 = ( unsigned long ) V_110 ;
V_125 -> V_144 = V_1 ;
V_125 -> V_145 = V_52 . V_145 ;
V_125 -> V_146 = V_52 . V_146 ;
V_125 -> V_147 = V_52 . V_147 ;
memcpy ( V_125 -> V_148 , V_52 . V_148 ,
V_149 / 8 ) ;
F_114 () ;
while ( F_9 ( V_1 , V_8 ) == V_9 )
F_36 ( 10 ) ;
while ( ! F_16 ( V_1 ) )
F_10 () ;
return 0 ;
V_132:
F_100 ( V_1 ) ;
return - V_128 ;
}
static int T_4 F_115 ( char * V_150 )
{
int V_151 , V_1 ;
V_151 = F_116 ( V_150 , NULL , 0 ) ;
F_117 ( F_118 ( 0 ) ) ;
for ( V_1 = 1 ; V_1 < V_151 && V_1 < V_81 ; V_1 ++ )
F_119 ( V_1 , true ) ;
return 0 ;
}
int F_120 ( void )
{
struct V_60 V_152 ;
int V_1 = F_14 () ;
F_82 ( V_1 , false ) ;
F_121 () ;
memset ( & V_152 . V_65 , 0 , sizeof( V_152 . V_65 ) ) ;
memset ( & V_152 . V_64 , 0xff , sizeof( V_152 . V_64 ) ) ;
V_152 . V_65 [ 0 ] = 0 ;
V_152 . V_64 [ 0 ] = ~ ( 1 << 15 | 1 << 14 | 1 << 13 | 1 << 11 |
1 << 10 | 1 << 9 | 1 << 6 | 1 << 5 |
1 << 4 ) ;
V_152 . V_65 [ 6 ] = 0 ;
V_152 . V_64 [ 6 ] = ~ ( 1 << 31 | 1 << 30 | 1 << 29 | 1 << 28 |
1 << 27 | 1 << 26 | 1 << 25 | 1 << 24 ) ;
V_152 . V_65 [ 14 ] = 0 ;
V_152 . V_64 [ 14 ] = ~ ( 1 << 28 | 1 << 27 | 1 << 26 |
1 << 25 | 1 << 24 ) ;
F_44 ( & V_152 ) ;
return 0 ;
}
void F_122 ( unsigned int V_1 )
{
while ( ! F_3 ( V_1 ) )
F_10 () ;
while ( F_110 ( 0 , V_1 , V_133 ) == V_9 )
F_36 ( 10 ) ;
F_100 ( V_1 ) ;
F_123 ( & V_138 . V_139 . V_140 ) ;
}
void T_7 F_124 ( void )
{
F_125 () ;
while ( F_9 ( F_14 () , V_10 ) == V_9 )
F_10 () ;
for (; ; ) ;
}
void T_4 F_126 ( unsigned int V_153 )
{
#ifndef F_95
unsigned long V_75 = 0 ;
#endif
unsigned long V_112 , V_31 ;
struct V_12 * V_113 ;
F_67 () ;
if ( F_127 ( 0x1201 , F_27 ) != 0 )
F_68 ( L_6 ) ;
if ( F_127 ( 0x1202 , F_27 ) != 0 )
F_68 ( L_7 ) ;
V_113 = ( void * ) F_93 ( V_76 | V_114 , V_115 ) ;
V_31 = F_94 ( V_76 ) ;
V_112 = F_93 ( V_76 , V_116 ) ;
F_128 ( ! V_113 || ! V_31 || ! V_112 ) ;
#ifndef F_95
if ( V_123 )
V_75 = F_96 ( V_76 ) ;
#endif
F_129 () ;
F_130 () ;
V_24 [ F_14 () ] = V_113 ;
* V_113 = V_52 ;
V_113 -> V_31 = V_31 + V_118 ;
V_113 -> V_112 = V_112 + V_117 ;
#ifndef F_95
if ( V_123 )
V_113 -> V_124 = ( T_1 ) V_75 ;
#endif
F_131 ( ( T_1 ) ( unsigned long ) V_113 ) ;
F_132 () ;
F_86 () ;
#ifdef F_95
if ( F_97 ( F_14 () , & V_52 ) )
F_133 () ;
#endif
}
void T_4 F_134 ( void )
{
F_128 ( F_14 () != 0 ) ;
F_135 () -> V_1 = 0 ;
F_60 ( 0 , true ) ;
F_82 ( 0 , true ) ;
V_52 . V_141 = V_142 [ 0 ] ;
V_129 [ 0 ] = V_154 ;
V_84 [ 0 ] = V_85 ;
F_59 ( 0 , V_83 ) ;
}
void T_4 F_136 ( unsigned int V_153 )
{
}
void T_4 F_137 ( void )
{
V_52 . V_144 = 0 ;
V_5 [ 0 ] = F_7 () ;
}
int F_138 ( unsigned int V_155 )
{
return 0 ;
}
static T_8 F_139 ( struct V_156 * V_157 ,
struct V_158 * V_159 , char * V_160 )
{
T_8 V_161 ;
F_140 ( & V_162 ) ;
V_161 = sprintf ( V_160 , L_8 , V_84 [ V_157 -> V_163 ] ) ;
F_141 ( & V_162 ) ;
return V_161 ;
}
static T_8 F_142 ( struct V_156 * V_157 ,
struct V_158 * V_159 ,
const char * V_160 , T_9 V_161 )
{
int V_1 = V_157 -> V_163 ;
int V_164 , V_87 ;
char V_165 ;
if ( sscanf ( V_160 , L_9 , & V_164 , & V_165 ) != 1 )
return - V_166 ;
if ( V_164 != 0 && V_164 != 1 )
return - V_166 ;
F_72 () ;
F_140 ( & V_162 ) ;
V_87 = - V_167 ;
if ( F_16 ( V_1 ) || V_1 == 0 )
goto V_89;
V_87 = 0 ;
switch ( V_164 ) {
case 0 :
if ( V_84 [ V_1 ] == V_85 ) {
V_87 = F_143 ( V_5 [ V_1 ] ) ;
if ( ! V_87 ) {
V_84 [ V_1 ] = V_95 ;
F_59 ( V_1 , V_83 ) ;
F_144 () ;
}
}
break;
case 1 :
if ( V_84 [ V_1 ] == V_95 ) {
V_87 = F_145 ( V_5 [ V_1 ] ) ;
if ( ! V_87 ) {
V_84 [ V_1 ] = V_85 ;
F_59 ( V_1 , V_83 ) ;
F_144 () ;
}
}
break;
default:
break;
}
V_89:
F_141 ( & V_162 ) ;
F_73 () ;
return V_87 ? V_87 : V_161 ;
}
static T_8 F_146 ( struct V_156 * V_157 ,
struct V_158 * V_159 , char * V_160 )
{
return sprintf ( V_160 , L_8 , V_5 [ V_157 -> V_163 ] ) ;
}
static T_8 F_147 ( struct V_156 * V_157 ,
struct V_158 * V_159 , char * V_160 )
{
unsigned int V_168 ;
int V_87 ;
V_87 = F_148 ( & V_168 ) ;
if ( V_87 )
return V_87 ;
return sprintf ( V_160 , L_10 , V_168 ) ;
}
static T_8 F_149 ( struct V_156 * V_157 ,
struct V_158 * V_159 , char * V_160 )
{
struct V_169 * V_110 ;
unsigned long long V_170 ;
unsigned int V_171 ;
V_110 = & F_150 ( V_172 , V_157 -> V_163 ) ;
V_173:
V_171 = V_110 -> V_171 ;
F_151 () ;
if ( V_171 & 1 )
goto V_173;
V_170 = V_110 -> V_170 ;
if ( V_110 -> V_174 )
V_170 ++ ;
F_151 () ;
if ( V_110 -> V_171 != V_171 )
goto V_173;
return sprintf ( V_160 , L_11 , V_170 ) ;
}
static T_8 F_152 ( struct V_156 * V_157 ,
struct V_158 * V_159 , char * V_160 )
{
struct V_169 * V_110 ;
unsigned long long V_175 , V_176 , V_174 ;
unsigned int V_171 ;
V_110 = & F_150 ( V_172 , V_157 -> V_163 ) ;
V_175 = F_23 () ;
V_173:
V_171 = V_110 -> V_171 ;
F_151 () ;
if ( V_171 & 1 )
goto V_173;
V_176 = V_110 -> V_176 ;
V_174 = V_110 -> V_174 ;
if ( V_174 != 0ULL && V_174 < V_175 )
V_176 += V_175 - V_174 ;
F_151 () ;
if ( V_110 -> V_171 != V_171 )
goto V_173;
return sprintf ( V_160 , L_11 , V_176 >> 12 ) ;
}
static int T_6 F_153 ( struct V_177 * V_178 ,
unsigned long V_179 , void * V_180 )
{
unsigned int V_1 = ( unsigned int ) ( long ) V_180 ;
struct V_1 * V_181 = & F_150 ( V_182 , V_1 ) ;
struct V_156 * V_150 = & V_181 -> V_157 ;
struct V_169 * V_110 ;
int V_183 = 0 ;
switch ( V_179 ) {
case V_184 :
case V_185 :
V_110 = & F_150 ( V_172 , V_1 ) ;
memset ( V_110 , 0 , sizeof( struct V_169 ) ) ;
V_183 = F_154 ( & V_150 -> V_186 , & V_187 ) ;
break;
case V_188 :
case V_189 :
F_155 ( & V_150 -> V_186 , & V_187 ) ;
break;
}
return F_156 ( V_183 ) ;
}
static int T_10 F_157 ( int V_1 )
{
struct V_1 * V_181 = & F_150 ( V_182 , V_1 ) ;
struct V_156 * V_150 = & V_181 -> V_157 ;
int V_87 ;
V_181 -> V_190 = 1 ;
V_87 = F_158 ( V_181 , V_1 ) ;
if ( V_87 )
goto V_89;
V_87 = F_154 ( & V_150 -> V_186 , & V_191 ) ;
if ( V_87 )
goto V_192;
if ( F_16 ( V_1 ) ) {
V_87 = F_154 ( & V_150 -> V_186 , & V_187 ) ;
if ( V_87 )
goto V_193;
}
V_87 = F_159 ( V_181 ) ;
if ( V_87 )
goto V_194;
return 0 ;
V_194:
if ( F_16 ( V_1 ) )
F_155 ( & V_150 -> V_186 , & V_187 ) ;
V_193:
F_155 ( & V_150 -> V_186 , & V_191 ) ;
V_192:
#ifdef F_160
F_161 ( V_181 ) ;
#endif
V_89:
return V_87 ;
}
int T_11 F_162 ( void )
{
T_2 V_195 ;
int V_1 ;
int V_87 ;
F_72 () ;
F_140 ( & V_162 ) ;
F_21 ( & V_195 , V_97 ) ;
V_87 = F_65 () ;
if ( V_87 )
goto V_89;
F_163 ( & V_195 , V_97 , & V_195 ) ;
F_24 (cpu, &newcpus) {
V_87 = F_157 ( V_1 ) ;
if ( V_87 )
F_60 ( V_1 , false ) ;
}
V_87 = 0 ;
V_89:
F_141 ( & V_162 ) ;
F_73 () ;
if ( ! F_26 ( & V_195 ) )
F_164 () ;
return V_87 ;
}
static T_8 T_11 F_165 ( struct V_156 * V_157 ,
struct V_158 * V_159 ,
const char * V_160 ,
T_9 V_161 )
{
int V_87 ;
V_87 = F_162 () ;
return V_87 ? V_87 : V_161 ;
}
static int T_4 F_166 ( void )
{
int V_1 , V_87 ;
F_167 ( & V_196 ) ;
#ifdef F_160
V_87 = F_168 ( V_197 . V_198 , & V_199 ) ;
if ( V_87 )
return V_87 ;
#endif
F_56 (cpu) {
V_87 = F_157 ( V_1 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
