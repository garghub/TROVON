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
V_18 -> V_34 = V_13 -> V_35 ;
V_19 -= V_36 ;
V_16 = (struct V_15 * ) V_19 ;
V_16 -> V_37 = V_18 -> V_32 [ 15 ] ;
F_17 ( F_13 , V_11 , V_19 , F_7 () , V_5 [ 0 ] ) ;
}
void F_18 ( void )
{
int V_1 , V_38 ;
F_8 ( V_6 | V_7 ) ;
F_19 () ;
F_6 (cpu) {
if ( V_1 == F_14 () )
continue;
do {
V_38 = F_9 ( V_1 , V_10 ) ;
} while ( V_38 == V_9 );
while ( ! F_3 ( V_1 ) )
F_10 () ;
}
}
static void F_20 ( unsigned int V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
unsigned long V_42 ;
if ( V_39 == 0x1202 )
F_21 ( F_14 () ) . V_43 [ V_44 ] ++ ;
else
F_21 ( F_14 () ) . V_43 [ V_45 ] ++ ;
V_42 = F_22 ( & V_46 . V_47 , 0 ) ;
if ( F_23 ( V_48 , & V_42 ) )
F_24 () ;
if ( F_23 ( V_49 , & V_42 ) )
F_25 () ;
if ( F_23 ( V_50 , & V_42 ) )
F_26 () ;
}
static void F_27 ( int V_1 , int V_51 )
{
int V_52 ;
F_28 ( V_51 , ( unsigned long * ) & V_24 [ V_1 ] -> V_47 ) ;
while ( 1 ) {
V_52 = F_29 ( V_1 ) ?
V_53 : V_54 ;
if ( F_9 ( V_1 , V_52 ) != V_9 )
break;
F_30 ( 10 ) ;
}
}
void F_31 ( const struct V_55 * V_26 )
{
int V_1 ;
F_32 (cpu, mask)
F_27 ( V_1 , V_49 ) ;
}
void F_33 ( int V_1 )
{
F_27 ( V_1 , V_50 ) ;
}
static void F_34 ( void * V_56 )
{
F_35 () ;
}
void F_36 ( void )
{
F_37 ( F_34 , NULL , 1 ) ;
}
void F_38 ( int V_1 )
{
F_27 ( V_1 , V_48 ) ;
}
static void F_39 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
unsigned long V_59 [ 16 ] ;
int V_60 ;
F_40 ( V_59 , 0 , 15 ) ;
for ( V_60 = 0 ; V_60 <= 15 ; V_60 ++ )
V_59 [ V_60 ] = ( V_59 [ V_60 ] & V_58 -> V_61 [ V_60 ] ) | V_58 -> V_62 [ V_60 ] ;
F_41 ( V_59 , 0 , 15 ) ;
}
void F_42 ( int V_63 , int V_64 )
{
struct V_57 V_65 ;
memset ( & V_65 . V_62 , 0 , sizeof( V_65 . V_62 ) ) ;
memset ( & V_65 . V_61 , 0xff , sizeof( V_65 . V_61 ) ) ;
V_65 . V_62 [ V_63 ] = 1UL << V_64 ;
F_37 ( F_39 , & V_65 , 1 ) ;
}
void F_43 ( int V_63 , int V_64 )
{
struct V_57 V_65 ;
memset ( & V_65 . V_62 , 0 , sizeof( V_65 . V_62 ) ) ;
memset ( & V_65 . V_61 , 0xff , sizeof( V_65 . V_61 ) ) ;
V_65 . V_61 [ V_63 ] = ~ ( 1UL << V_64 ) ;
F_37 ( F_39 , & V_65 , 1 ) ;
}
static void T_2 F_44 ( unsigned int V_1 , unsigned int V_66 )
{
if ( V_67 . type != V_68 && ! V_69 )
return;
if ( F_45 () )
return;
if ( V_1 >= V_70 ) {
F_46 ( L_1
L_2 , V_1 , V_70 - 1 ) ;
return;
}
V_71 [ V_1 ] = F_47 ( sizeof( struct V_72 ) , V_73 ) ;
while ( F_11 ( V_66 , V_30 ) == V_9 )
F_10 () ;
F_48 ( V_71 [ V_1 ] ,
( void * ) ( unsigned long ) F_49 () + V_74 ,
sizeof( struct V_72 ) ) ;
}
static inline void F_44 ( unsigned int V_1 , unsigned int V_66 ) { }
static int F_50 ( int V_75 )
{
int V_1 ;
F_51 (cpu) {
if ( V_5 [ V_1 ] == V_75 )
return 1 ;
}
return 0 ;
}
static int F_52 ( T_3 V_76 )
{
int V_75 , V_77 ;
V_77 = F_53 ( & V_76 ) ;
if ( V_77 >= V_78 )
return 0 ;
for ( V_75 = 0 ; V_75 <= V_79 ; V_75 ++ ) {
if ( F_50 ( V_75 ) )
continue;
V_5 [ V_77 ] = V_75 ;
V_80 [ V_77 ] = V_81 ;
if ( ! F_3 ( V_77 ) )
continue;
F_54 ( V_77 , true ) ;
V_82 [ V_77 ] = V_83 ;
V_77 = F_55 ( V_77 , & V_76 ) ;
if ( V_77 >= V_78 )
break;
}
return 0 ;
}
static int F_56 ( T_3 V_76 )
{
struct V_84 * V_56 ;
int V_75 , V_77 , V_1 ;
int V_38 ;
V_77 = F_53 ( & V_76 ) ;
if ( V_77 >= V_78 )
return 0 ;
V_56 = F_47 ( sizeof( * V_56 ) , V_73 ) ;
if ( ! V_56 )
return - V_85 ;
V_38 = F_57 ( V_56 ) ;
if ( V_38 )
goto V_86;
for ( V_1 = 0 ; V_1 < V_56 -> V_87 ; V_1 ++ ) {
if ( V_56 -> V_88 && V_56 -> V_1 [ V_1 ] . type != V_89 )
continue;
V_75 = V_56 -> V_1 [ V_1 ] . V_90 ;
if ( F_50 ( V_75 ) )
continue;
V_5 [ V_77 ] = V_75 ;
V_80 [ V_77 ] = V_81 ;
F_54 ( V_77 , true ) ;
if ( V_1 >= V_56 -> V_91 )
V_82 [ V_77 ] = V_92 ;
else
V_82 [ V_77 ] = V_83 ;
V_77 = F_55 ( V_77 , & V_76 ) ;
if ( V_77 >= V_78 )
break;
}
V_86:
F_58 ( V_56 ) ;
return V_38 ;
}
static int F_59 ( void )
{
T_3 V_76 ;
F_60 ( & V_76 , V_93 , V_94 ) ;
if ( V_95 )
return F_52 ( V_76 ) ;
else
return F_56 ( V_76 ) ;
}
static void T_2 F_61 ( void )
{
unsigned int V_1 , V_96 , V_97 ;
struct V_84 * V_56 ;
T_4 V_98 , V_99 ;
V_96 = 1 ;
V_97 = 0 ;
V_98 = V_5 [ 0 ] ;
V_56 = F_47 ( sizeof( * V_56 ) , V_73 ) ;
if ( ! V_56 )
F_62 ( L_3 ) ;
#ifdef F_63
if ( V_69 && ! F_45 () ) {
struct V_72 * V_72 ;
V_72 = F_47 ( sizeof( * V_72 ) , V_73 ) ;
if ( ! V_72 )
F_62 ( L_4 ) ;
F_64 ( 1 , ( void * ) V_72 , sizeof( * V_72 ) ,
0x200 , 0 ) ;
V_71 [ 0 ] = V_72 ;
}
#endif
if ( F_57 ( V_56 ) ) {
V_95 = 1 ;
for ( V_1 = 0 ; V_1 <= V_79 ; V_1 ++ ) {
if ( V_1 == V_98 )
continue;
if ( ! F_1 ( V_1 ) )
continue;
F_44 ( V_96 , V_1 ) ;
V_96 ++ ;
}
goto V_86;
}
if ( V_56 -> V_88 ) {
for ( V_1 = 0 ; V_1 < V_56 -> V_87 ; V_1 ++ ) {
if ( V_56 -> V_1 [ V_1 ] . V_90 == V_98 ) {
V_89 = V_56 -> V_1 [ V_1 ] . type ;
break;
}
}
}
for ( V_1 = 0 ; V_1 < V_56 -> V_87 ; V_1 ++ ) {
if ( V_56 -> V_88 && V_56 -> V_1 [ V_1 ] . type != V_89 )
continue;
V_99 = V_56 -> V_1 [ V_1 ] . V_90 ;
if ( V_99 == V_98 )
continue;
if ( ! F_1 ( V_99 ) ) {
V_97 ++ ;
continue;
}
F_44 ( V_96 , V_99 ) ;
V_96 ++ ;
}
V_86:
F_58 ( V_56 ) ;
F_65 ( L_5 , V_96 , V_97 ) ;
F_66 () ;
F_59 () ;
F_67 () ;
}
int T_5 F_68 ( void * V_100 )
{
F_69 () ;
F_70 () ;
F_71 () ;
F_72 () ;
F_73 () ;
F_74 ( F_14 () ) ;
F_75 () ;
F_76 ( F_14 () , true ) ;
F_77 () ;
F_15 ( 0 , 28 ) ;
V_46 . V_25 . V_26 =
V_20 | V_21 | V_22 | V_23 ;
V_46 . V_25 . V_27 =
V_28 | ( unsigned long ) V_101 ;
F_78 ( 0 , 28 ) ;
while ( ! F_79 ( F_14 () , V_102 ) )
F_10 () ;
F_80 () ;
F_81 () ;
return 0 ;
}
static void T_5 F_82 ( struct V_103 * V_104 )
{
struct V_105 * V_106 ;
V_106 = F_83 ( V_104 , struct V_105 , V_104 ) ;
V_106 -> V_107 = F_84 ( V_106 -> V_1 ) ;
F_85 ( & V_106 -> V_108 ) ;
}
static int T_5 F_86 ( int V_1 )
{
unsigned long V_109 , V_31 ;
struct V_12 * V_110 ;
V_110 = ( void * ) F_87 ( V_73 | V_111 , V_112 ) ;
if ( ! V_110 )
return - V_85 ;
V_109 = F_87 ( V_73 , V_113 ) ;
V_31 = F_88 ( V_73 ) ;
if ( ! V_31 || ! V_109 )
goto V_86;
memcpy ( V_110 , & V_46 , 512 ) ;
memset ( ( char * ) V_110 + 512 , 0 , sizeof( * V_110 ) - 512 ) ;
V_110 -> V_109 = V_109 + V_114 ;
V_110 -> V_31 = V_31 + V_115 ;
V_110 -> V_25 . V_26 =
V_20 | V_21 | V_22 | V_23 ;
V_110 -> V_25 . V_27 =
V_28 | ( unsigned long ) V_116 ;
if ( V_117 != V_118 )
V_110 -> V_25 . V_26 |= V_119 ;
#ifndef F_89
if ( V_120 ) {
unsigned long V_72 ;
V_72 = F_90 ( V_73 ) ;
if ( ! V_72 )
goto V_86;
V_110 -> V_121 = ( T_1 ) V_72 ;
}
#else
if ( F_91 ( V_1 , V_110 ) )
goto V_86;
#endif
V_24 [ V_1 ] = V_110 ;
return 0 ;
V_86:
F_92 ( V_31 ) ;
F_93 ( V_109 , V_113 ) ;
F_93 ( ( unsigned long ) V_110 , V_112 ) ;
return - V_85 ;
}
static void F_94 ( int V_1 )
{
struct V_12 * V_110 ;
V_110 = V_24 [ V_1 ] ;
#ifndef F_89
if ( V_120 )
F_92 ( ( unsigned long ) V_110 -> V_121 ) ;
#else
F_95 ( V_1 , V_110 ) ;
#endif
F_92 ( V_110 -> V_31 - V_115 ) ;
F_93 ( V_110 -> V_109 - V_114 , V_113 ) ;
F_93 ( ( unsigned long ) V_110 , V_112 ) ;
V_24 [ V_1 ] = NULL ;
}
int T_5 F_96 ( unsigned int V_1 )
{
struct V_12 * V_122 ;
struct V_105 V_106 ;
struct V_123 * V_107 ;
struct V_15 * V_16 ;
T_1 V_110 ;
int V_124 ;
if ( V_82 [ V_1 ] != V_83 )
return - V_125 ;
V_107 = V_126 [ V_1 ] ;
if ( ! V_107 ) {
V_106 . V_108 = F_97 ( V_106 . V_108 ) ;
F_98 ( & V_106 . V_104 , F_82 ) ;
V_106 . V_1 = V_1 ;
F_99 ( & V_106 . V_104 ) ;
F_100 ( & V_106 . V_108 ) ;
if ( F_101 ( V_106 . V_107 ) )
return F_102 ( V_106 . V_107 ) ;
V_107 = V_106 . V_107 ;
V_126 [ V_1 ] = V_106 . V_107 ;
}
F_103 ( V_107 , V_1 ) ;
if ( F_86 ( V_1 ) )
return - V_85 ;
do {
V_124 = F_9 ( V_1 , V_127 ) ;
if ( V_124 == V_9 )
F_30 ( 10 ) ;
if ( V_124 == V_128 )
goto V_129;
} while ( V_124 == V_9 );
V_110 = ( T_1 ) ( unsigned long ) V_24 [ V_1 ] ;
while ( F_104 ( V_110 , V_1 , V_130 ) == V_9 )
F_30 ( 10 ) ;
V_122 = V_24 [ V_1 ] ;
V_122 -> V_131 = ( unsigned long )
F_105 ( V_107 ) + V_132 ;
V_122 -> V_133 = ( unsigned long ) F_106 ( V_107 ) ;
V_16 = (struct V_15 * ) ( V_122 -> V_131
- sizeof( struct V_17 )
- sizeof( struct V_15 ) ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_32 [ 9 ] = ( unsigned long ) V_16 ;
V_122 -> V_72 [ 15 ] = ( unsigned long ) V_16 ;
F_40 ( V_122 -> V_134 , 0 , 15 ) ;
F_107 ( & V_135 . V_136 . V_137 ) ;
asm volatile(
" stam 0,15,0(%0)"
: : "a" (&cpu_lowcore->access_regs_save_area) : "memory");
V_122 -> V_138 = V_139 [ V_1 ] ;
V_122 -> V_140 = ( unsigned long ) V_107 ;
V_122 -> V_141 = V_1 ;
V_122 -> V_142 = V_46 . V_142 ;
V_122 -> V_143 = V_46 . V_143 ;
V_122 -> V_144 = V_46 . V_144 ;
memcpy ( V_122 -> V_145 , V_46 . V_145 ,
V_146 / 8 ) ;
F_108 () ;
while ( F_9 ( V_1 , V_8 ) == V_9 )
F_30 ( 10 ) ;
while ( ! F_16 ( V_1 ) )
F_10 () ;
return 0 ;
V_129:
F_94 ( V_1 ) ;
return - V_125 ;
}
static int T_2 F_109 ( char * V_147 )
{
int V_148 , V_1 ;
V_148 = F_110 ( V_147 , NULL , 0 ) ;
F_111 ( F_112 ( 0 ) ) ;
for ( V_1 = 1 ; V_1 < V_148 && V_1 < V_78 ; V_1 ++ )
F_113 ( V_1 , true ) ;
return 0 ;
}
int F_114 ( void )
{
struct V_57 V_149 ;
int V_1 = F_14 () ;
F_76 ( V_1 , false ) ;
F_115 () ;
memset ( & V_149 . V_62 , 0 , sizeof( V_149 . V_62 ) ) ;
memset ( & V_149 . V_61 , 0xff , sizeof( V_149 . V_61 ) ) ;
V_149 . V_62 [ 0 ] = 0 ;
V_149 . V_61 [ 0 ] = ~ ( 1 << 15 | 1 << 14 | 1 << 13 | 1 << 11 |
1 << 10 | 1 << 9 | 1 << 6 | 1 << 5 |
1 << 4 ) ;
V_149 . V_62 [ 6 ] = 0 ;
V_149 . V_61 [ 6 ] = ~ ( 1 << 31 | 1 << 30 | 1 << 29 | 1 << 28 |
1 << 27 | 1 << 26 | 1 << 25 | 1 << 24 ) ;
V_149 . V_62 [ 14 ] = 0 ;
V_149 . V_61 [ 14 ] = ~ ( 1 << 28 | 1 << 27 | 1 << 26 |
1 << 25 | 1 << 24 ) ;
F_39 ( & V_149 ) ;
return 0 ;
}
void F_116 ( unsigned int V_1 )
{
while ( ! F_3 ( V_1 ) )
F_10 () ;
while ( F_104 ( 0 , V_1 , V_130 ) == V_9 )
F_30 ( 10 ) ;
F_94 ( V_1 ) ;
F_117 ( & V_135 . V_136 . V_137 ) ;
}
void T_6 F_118 ( void )
{
F_119 () ;
while ( F_9 ( F_14 () , V_10 ) == V_9 )
F_10 () ;
for (; ; ) ;
}
void T_2 F_120 ( unsigned int V_150 )
{
#ifndef F_89
unsigned long V_72 = 0 ;
#endif
unsigned long V_109 , V_31 ;
struct V_12 * V_110 ;
F_61 () ;
if ( F_121 ( 0x1201 , F_20 ) != 0 )
F_62 ( L_6 ) ;
if ( F_121 ( 0x1202 , F_20 ) != 0 )
F_62 ( L_7 ) ;
V_110 = ( void * ) F_87 ( V_73 | V_111 , V_112 ) ;
V_31 = F_88 ( V_73 ) ;
V_109 = F_87 ( V_73 , V_113 ) ;
F_122 ( ! V_110 || ! V_31 || ! V_109 ) ;
#ifndef F_89
if ( V_120 )
V_72 = F_90 ( V_73 ) ;
#endif
F_123 () ;
F_124 () ;
V_24 [ F_14 () ] = V_110 ;
* V_110 = V_46 ;
V_110 -> V_31 = V_31 + V_115 ;
V_110 -> V_109 = V_109 + V_114 ;
#ifndef F_89
if ( V_120 )
V_110 -> V_121 = ( T_1 ) V_72 ;
#endif
F_125 ( ( T_1 ) ( unsigned long ) V_110 ) ;
F_126 () ;
F_80 () ;
#ifdef F_89
if ( F_91 ( F_14 () , & V_46 ) )
F_127 () ;
#endif
}
void T_2 F_128 ( void )
{
F_122 ( F_14 () != 0 ) ;
F_129 () -> V_1 = 0 ;
F_54 ( 0 , true ) ;
F_76 ( 0 , true ) ;
V_46 . V_138 = V_139 [ 0 ] ;
V_126 [ 0 ] = V_151 ;
V_82 [ 0 ] = V_83 ;
V_80 [ 0 ] = V_81 ;
}
void T_2 F_130 ( unsigned int V_150 )
{
}
void T_2 F_131 ( void )
{
V_46 . V_141 = 0 ;
V_5 [ 0 ] = F_7 () ;
}
int F_132 ( unsigned int V_152 )
{
return 0 ;
}
static T_7 F_133 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
T_7 V_158 ;
F_134 ( & V_159 ) ;
V_158 = sprintf ( V_157 , L_8 , V_82 [ V_154 -> V_160 ] ) ;
F_135 ( & V_159 ) ;
return V_158 ;
}
static T_7 F_136 ( struct V_153 * V_154 ,
struct V_155 * V_156 ,
const char * V_157 , T_8 V_158 )
{
int V_1 = V_154 -> V_160 ;
int V_161 , V_38 ;
char V_162 ;
if ( sscanf ( V_157 , L_9 , & V_161 , & V_162 ) != 1 )
return - V_163 ;
if ( V_161 != 0 && V_161 != 1 )
return - V_163 ;
F_66 () ;
F_134 ( & V_159 ) ;
V_38 = - V_164 ;
if ( F_16 ( V_1 ) || V_1 == 0 )
goto V_86;
V_38 = 0 ;
switch ( V_161 ) {
case 0 :
if ( V_82 [ V_1 ] == V_83 ) {
V_38 = F_137 ( V_5 [ V_1 ] ) ;
if ( ! V_38 ) {
V_82 [ V_1 ] = V_92 ;
V_80 [ V_1 ] = V_81 ;
}
}
break;
case 1 :
if ( V_82 [ V_1 ] == V_92 ) {
V_38 = F_138 ( V_5 [ V_1 ] ) ;
if ( ! V_38 ) {
V_82 [ V_1 ] = V_83 ;
V_80 [ V_1 ] = V_81 ;
}
}
break;
default:
break;
}
V_86:
F_135 ( & V_159 ) ;
F_67 () ;
return V_38 ? V_38 : V_158 ;
}
static T_7 F_139 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
int V_1 = V_154 -> V_160 ;
T_7 V_158 ;
F_134 ( & V_159 ) ;
switch ( V_80 [ V_1 ] ) {
case V_165 :
V_158 = sprintf ( V_157 , L_10 ) ;
break;
case V_166 :
V_158 = sprintf ( V_157 , L_11 ) ;
break;
case V_167 :
V_158 = sprintf ( V_157 , L_12 ) ;
break;
case V_168 :
V_158 = sprintf ( V_157 , L_13 ) ;
break;
default:
V_158 = sprintf ( V_157 , L_14 ) ;
break;
}
F_135 ( & V_159 ) ;
return V_158 ;
}
static T_7 F_140 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
return sprintf ( V_157 , L_8 , V_5 [ V_154 -> V_160 ] ) ;
}
static T_7 F_141 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
unsigned int V_169 ;
int V_38 ;
V_38 = F_142 ( & V_169 ) ;
if ( V_38 )
return V_38 ;
return sprintf ( V_157 , L_15 , V_169 ) ;
}
static T_7 F_143 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
struct V_170 * V_107 ;
unsigned long long V_171 ;
unsigned int V_172 ;
V_107 = & F_144 ( V_173 , V_154 -> V_160 ) ;
V_174:
V_172 = V_107 -> V_172 ;
F_145 () ;
if ( V_172 & 1 )
goto V_174;
V_171 = V_107 -> V_171 ;
if ( V_107 -> V_175 )
V_171 ++ ;
F_145 () ;
if ( V_107 -> V_172 != V_172 )
goto V_174;
return sprintf ( V_157 , L_16 , V_171 ) ;
}
static T_7 F_146 ( struct V_153 * V_154 ,
struct V_155 * V_156 , char * V_157 )
{
struct V_170 * V_107 ;
unsigned long long V_176 , V_177 , V_175 ;
unsigned int V_172 ;
V_107 = & F_144 ( V_173 , V_154 -> V_160 ) ;
V_176 = F_147 () ;
V_174:
V_172 = V_107 -> V_172 ;
F_145 () ;
if ( V_172 & 1 )
goto V_174;
V_177 = V_107 -> V_177 ;
V_175 = V_107 -> V_175 ;
if ( V_175 != 0ULL && V_175 < V_176 )
V_177 += V_176 - V_175 ;
F_145 () ;
if ( V_107 -> V_172 != V_172 )
goto V_174;
return sprintf ( V_157 , L_16 , V_177 >> 12 ) ;
}
static int T_5 F_148 ( struct V_178 * V_179 ,
unsigned long V_180 , void * V_181 )
{
unsigned int V_1 = ( unsigned int ) ( long ) V_181 ;
struct V_1 * V_182 = & F_144 ( V_183 , V_1 ) ;
struct V_153 * V_147 = & V_182 -> V_184 ;
struct V_170 * V_107 ;
int V_185 = 0 ;
switch ( V_180 ) {
case V_186 :
case V_187 :
V_107 = & F_144 ( V_173 , V_1 ) ;
memset ( V_107 , 0 , sizeof( struct V_170 ) ) ;
V_185 = F_149 ( & V_147 -> V_188 , & V_189 ) ;
break;
case V_190 :
case V_191 :
F_150 ( & V_147 -> V_188 , & V_189 ) ;
break;
}
return F_151 ( V_185 ) ;
}
static int T_9 F_152 ( int V_1 )
{
struct V_1 * V_182 = & F_144 ( V_183 , V_1 ) ;
struct V_153 * V_147 = & V_182 -> V_184 ;
int V_38 ;
V_182 -> V_192 = 1 ;
V_38 = F_153 ( V_182 , V_1 ) ;
if ( V_38 )
goto V_86;
V_38 = F_149 ( & V_147 -> V_188 , & V_193 ) ;
if ( V_38 )
goto V_194;
if ( ! F_16 ( V_1 ) )
goto V_86;
V_38 = F_149 ( & V_147 -> V_188 , & V_189 ) ;
if ( ! V_38 )
return 0 ;
F_150 ( & V_147 -> V_188 , & V_193 ) ;
V_194:
#ifdef F_154
F_155 ( V_182 ) ;
#endif
V_86:
return V_38 ;
}
int T_10 F_156 ( void )
{
T_3 V_195 ;
int V_1 ;
int V_38 ;
F_66 () ;
F_134 ( & V_159 ) ;
F_157 ( & V_195 , V_94 ) ;
V_38 = F_59 () ;
if ( V_38 )
goto V_86;
F_158 ( & V_195 , V_94 , & V_195 ) ;
F_32 (cpu, &newcpus) {
V_38 = F_152 ( V_1 ) ;
if ( V_38 )
F_54 ( V_1 , false ) ;
}
V_38 = 0 ;
V_86:
F_135 ( & V_159 ) ;
F_67 () ;
if ( ! F_159 ( & V_195 ) )
F_160 () ;
return V_38 ;
}
static T_7 T_10 F_161 ( struct V_196 * V_197 ,
struct V_198 * V_156 ,
const char * V_157 ,
T_8 V_158 )
{
int V_38 ;
V_38 = F_156 () ;
return V_38 ? V_38 : V_158 ;
}
static T_7 F_162 ( struct V_196 * V_197 ,
struct V_198 * V_156 ,
char * V_157 )
{
T_7 V_158 ;
F_134 ( & V_159 ) ;
V_158 = sprintf ( V_157 , L_8 , V_199 ) ;
F_135 ( & V_159 ) ;
return V_158 ;
}
static T_7 F_163 ( struct V_196 * V_154 ,
struct V_198 * V_156 ,
const char * V_157 ,
T_8 V_158 )
{
int V_161 , V_38 ;
char V_162 ;
if ( sscanf ( V_157 , L_9 , & V_161 , & V_162 ) != 1 )
return - V_163 ;
if ( V_161 != 0 && V_161 != 1 )
return - V_163 ;
V_38 = 0 ;
F_66 () ;
F_134 ( & V_159 ) ;
if ( V_199 == V_161 )
goto V_86;
V_38 = F_164 ( V_161 ) ;
if ( ! V_38 )
V_199 = V_161 ;
V_86:
F_135 ( & V_159 ) ;
F_67 () ;
return V_38 ? V_38 : V_158 ;
}
static int T_2 F_165 ( void )
{
int V_1 ;
int V_38 ;
F_166 ( & V_200 ) ;
#ifdef F_154
V_38 = F_167 ( & V_201 , & V_202 ) ;
if ( V_38 )
return V_38 ;
#endif
V_38 = F_167 ( & V_201 , & V_203 ) ;
if ( V_38 )
return V_38 ;
F_51 (cpu) {
V_38 = F_152 ( V_1 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
