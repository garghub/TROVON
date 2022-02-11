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
void F_5 ( void (* F_6)( void * ) , void * V_5 )
{
struct V_6 * V_7 , * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
if ( F_7 () == 0 )
F_6 ( V_5 ) ;
F_8 ( V_14 | V_15 ) ;
F_9 ( 0 , 28 ) ;
V_8 = V_16 [ F_7 () ] ;
V_7 = V_16 [ 0 ] ;
if ( ! V_7 )
V_7 = V_8 ;
V_7 -> V_17 . V_18 = V_14 | V_15 ;
V_7 -> V_17 . V_19 = V_20 | ( unsigned long ) V_21 ;
if ( ! F_10 ( 0 ) )
F_11 ( F_6 , V_5 , 0 , F_12 () , V_22 [ 0 ] ) ;
while ( F_13 ( 0 , V_23 ) == V_24 )
F_14 () ;
V_13 = V_7 -> V_25 ;
V_13 -= sizeof( struct V_11 ) ;
V_12 = (struct V_11 * ) V_13 ;
memcpy ( & V_12 -> V_26 , & V_8 -> V_27 , sizeof( V_12 -> V_26 ) ) ;
V_12 -> V_28 = V_7 -> V_29 ;
V_13 -= V_30 ;
V_10 = (struct V_9 * ) V_13 ;
V_10 -> V_31 = V_12 -> V_26 [ 15 ] ;
F_11 ( F_6 , V_5 , V_13 , F_12 () , V_22 [ 0 ] ) ;
}
void F_15 ( void )
{
int V_1 , V_32 ;
F_8 ( V_33 & ~ V_34 ) ;
F_16 () ;
F_17 (cpu) {
if ( V_1 == F_7 () )
continue;
do {
V_32 = F_13 ( V_1 , V_35 ) ;
} while ( V_32 == V_24 );
while ( ! F_3 ( V_1 ) )
F_14 () ;
}
}
static void F_18 ( unsigned int V_36 ,
unsigned int V_37 , unsigned long V_38 )
{
unsigned long V_39 ;
F_19 ( F_7 () ) . V_40 [ V_41 ] ++ ;
V_39 = F_20 ( & V_42 . V_43 , 0 ) ;
if ( F_21 ( V_44 , & V_39 ) )
F_22 () ;
if ( F_21 ( V_45 , & V_39 ) )
F_23 () ;
if ( F_21 ( V_46 , & V_39 ) )
F_24 () ;
}
static void F_25 ( int V_1 , int V_47 )
{
F_26 ( V_47 , ( unsigned long * ) & V_16 [ V_1 ] -> V_43 ) ;
while ( F_13 ( V_1 , V_48 ) == V_24 )
F_27 ( 10 ) ;
}
void F_28 ( const struct V_49 * V_18 )
{
int V_1 ;
F_29 (cpu, mask)
F_25 ( V_1 , V_45 ) ;
}
void F_30 ( int V_1 )
{
F_25 ( V_1 , V_46 ) ;
}
static void F_31 ( void * V_50 )
{
F_32 () ;
}
void F_33 ( void )
{
F_34 ( F_31 , NULL , 1 ) ;
}
void F_35 ( int V_1 )
{
F_25 ( V_1 , V_44 ) ;
}
static void F_36 ( void * V_50 )
{
struct V_51 * V_52 = V_50 ;
unsigned long V_53 [ 16 ] ;
int V_54 ;
F_37 ( V_53 , 0 , 15 ) ;
for ( V_54 = 0 ; V_54 <= 15 ; V_54 ++ )
V_53 [ V_54 ] = ( V_53 [ V_54 ] & V_52 -> V_55 [ V_54 ] ) | V_52 -> V_56 [ V_54 ] ;
F_38 ( V_53 , 0 , 15 ) ;
}
void F_39 ( int V_57 , int V_58 )
{
struct V_51 V_59 ;
memset ( & V_59 . V_56 , 0 , sizeof( V_59 . V_56 ) ) ;
memset ( & V_59 . V_55 , 0xff , sizeof( V_59 . V_55 ) ) ;
V_59 . V_56 [ V_57 ] = 1UL << V_58 ;
F_34 ( F_36 , & V_59 , 1 ) ;
}
void F_40 ( int V_57 , int V_58 )
{
struct V_51 V_59 ;
memset ( & V_59 . V_56 , 0 , sizeof( V_59 . V_56 ) ) ;
memset ( & V_59 . V_55 , 0xff , sizeof( V_59 . V_55 ) ) ;
V_59 . V_55 [ V_57 ] = ~ ( 1UL << V_58 ) ;
F_34 ( F_36 , & V_59 , 1 ) ;
}
static void T_2 F_41 ( unsigned int V_1 , unsigned int V_60 )
{
if ( V_61 . type != V_62 )
return;
if ( V_1 >= V_63 ) {
F_42 ( L_1
L_2 , V_1 , V_63 - 1 ) ;
return;
}
V_64 [ V_1 ] = F_43 ( sizeof( struct V_65 ) , V_66 ) ;
while ( F_44 ( V_60 , V_23 ) == V_24 )
F_14 () ;
F_45 ( V_64 [ V_1 ] ,
( void * ) ( unsigned long ) F_46 () + V_67 ,
sizeof( struct V_65 ) ) ;
}
static inline void F_41 ( unsigned int V_1 , unsigned int V_60 ) { }
static int F_47 ( int V_68 )
{
int V_1 ;
F_48 (cpu) {
if ( V_22 [ V_1 ] == V_68 )
return 1 ;
}
return 0 ;
}
static int F_49 ( T_3 V_69 )
{
int V_68 , V_70 ;
V_70 = F_50 ( & V_69 ) ;
if ( V_70 >= V_71 )
return 0 ;
for ( V_68 = 0 ; V_68 <= V_72 ; V_68 ++ ) {
if ( F_47 ( V_68 ) )
continue;
V_22 [ V_70 ] = V_68 ;
V_73 [ V_70 ] = V_74 ;
if ( ! F_3 ( V_70 ) )
continue;
F_51 ( V_70 , true ) ;
V_75 [ V_70 ] = V_76 ;
V_70 = F_52 ( V_70 , & V_69 ) ;
if ( V_70 >= V_71 )
break;
}
return 0 ;
}
static int F_53 ( T_3 V_69 )
{
struct V_77 * V_50 ;
int V_68 , V_70 , V_1 ;
int V_32 ;
V_70 = F_50 ( & V_69 ) ;
if ( V_70 >= V_71 )
return 0 ;
V_50 = F_43 ( sizeof( * V_50 ) , V_66 ) ;
if ( ! V_50 )
return - V_78 ;
V_32 = F_54 ( V_50 ) ;
if ( V_32 )
goto V_79;
for ( V_1 = 0 ; V_1 < V_50 -> V_80 ; V_1 ++ ) {
if ( V_50 -> V_81 && V_50 -> V_1 [ V_1 ] . type != V_82 )
continue;
V_68 = V_50 -> V_1 [ V_1 ] . V_83 ;
if ( F_47 ( V_68 ) )
continue;
V_22 [ V_70 ] = V_68 ;
V_73 [ V_70 ] = V_74 ;
F_51 ( V_70 , true ) ;
if ( V_1 >= V_50 -> V_84 )
V_75 [ V_70 ] = V_85 ;
else
V_75 [ V_70 ] = V_76 ;
V_70 = F_52 ( V_70 , & V_69 ) ;
if ( V_70 >= V_71 )
break;
}
V_79:
F_55 ( V_50 ) ;
return V_32 ;
}
static int F_56 ( void )
{
T_3 V_69 ;
F_57 ( & V_69 , V_86 , V_87 ) ;
if ( V_88 )
return F_49 ( V_69 ) ;
else
return F_53 ( V_69 ) ;
}
static void T_2 F_58 ( void )
{
unsigned int V_1 , V_89 , V_90 ;
struct V_77 * V_50 ;
T_4 V_91 , V_92 ;
V_89 = 1 ;
V_90 = 0 ;
V_91 = V_22 [ 0 ] ;
V_50 = F_43 ( sizeof( * V_50 ) , V_66 ) ;
if ( ! V_50 )
F_59 ( L_3 ) ;
if ( F_54 ( V_50 ) ) {
V_88 = 1 ;
for ( V_1 = 0 ; V_1 <= V_72 ; V_1 ++ ) {
if ( V_1 == V_91 )
continue;
if ( ! F_1 ( V_1 ) )
continue;
F_41 ( V_89 , V_1 ) ;
V_89 ++ ;
}
goto V_79;
}
if ( V_50 -> V_81 ) {
for ( V_1 = 0 ; V_1 < V_50 -> V_80 ; V_1 ++ ) {
if ( V_50 -> V_1 [ V_1 ] . V_83 == V_91 ) {
V_82 = V_50 -> V_1 [ V_1 ] . type ;
break;
}
}
}
for ( V_1 = 0 ; V_1 < V_50 -> V_80 ; V_1 ++ ) {
if ( V_50 -> V_81 && V_50 -> V_1 [ V_1 ] . type != V_82 )
continue;
V_92 = V_50 -> V_1 [ V_1 ] . V_83 ;
if ( V_92 == V_91 )
continue;
if ( ! F_1 ( V_92 ) ) {
V_90 ++ ;
continue;
}
F_41 ( V_89 , V_92 ) ;
V_89 ++ ;
}
V_79:
F_55 ( V_50 ) ;
F_60 ( L_4 , V_89 , V_90 ) ;
F_61 () ;
F_56 () ;
F_62 () ;
}
int T_5 F_63 ( void * V_93 )
{
F_64 () ;
F_65 () ;
F_66 () ;
F_67 () ;
F_68 () ;
F_69 ( F_7 () ) ;
F_70 () ;
F_71 ( F_7 () , true ) ;
F_72 () ;
F_73 () ;
F_74 () ;
return 0 ;
}
static void T_5 F_75 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
V_97 = F_76 ( V_95 , struct V_96 , V_95 ) ;
V_97 -> V_98 = F_77 ( V_97 -> V_1 ) ;
F_78 ( & V_97 -> V_99 ) ;
}
static int T_5 F_79 ( int V_1 )
{
unsigned long V_100 , V_25 ;
struct V_6 * V_101 ;
V_101 = ( void * ) F_80 ( V_66 | V_102 , V_103 ) ;
if ( ! V_101 )
return - V_78 ;
V_100 = F_80 ( V_66 , V_104 ) ;
V_25 = F_81 ( V_66 ) ;
if ( ! V_25 || ! V_100 )
goto V_79;
memcpy ( V_101 , & V_42 , 512 ) ;
memset ( ( char * ) V_101 + 512 , 0 , sizeof( * V_101 ) - 512 ) ;
V_101 -> V_100 = V_100 + V_105 ;
V_101 -> V_25 = V_25 + V_106 ;
#ifndef F_82
if ( V_107 ) {
unsigned long V_65 ;
V_65 = F_83 ( V_66 ) ;
if ( ! V_65 )
goto V_79;
V_101 -> V_108 = ( T_1 ) V_65 ;
}
#else
if ( F_84 ( V_1 , V_101 ) )
goto V_79;
#endif
V_16 [ V_1 ] = V_101 ;
return 0 ;
V_79:
F_85 ( V_25 ) ;
F_86 ( V_100 , V_104 ) ;
F_86 ( ( unsigned long ) V_101 , V_103 ) ;
return - V_78 ;
}
static void F_87 ( int V_1 )
{
struct V_6 * V_101 ;
V_101 = V_16 [ V_1 ] ;
#ifndef F_82
if ( V_107 )
F_85 ( ( unsigned long ) V_101 -> V_108 ) ;
#else
F_88 ( V_1 , V_101 ) ;
#endif
F_85 ( V_101 -> V_25 - V_106 ) ;
F_86 ( V_101 -> V_100 - V_105 , V_104 ) ;
F_86 ( ( unsigned long ) V_101 , V_103 ) ;
V_16 [ V_1 ] = NULL ;
}
int T_5 F_89 ( unsigned int V_1 )
{
struct V_6 * V_109 ;
struct V_96 V_97 ;
struct V_110 * V_98 ;
struct V_9 * V_10 ;
T_1 V_101 ;
int V_111 ;
if ( V_75 [ V_1 ] != V_76 )
return - V_112 ;
V_98 = V_113 [ V_1 ] ;
if ( ! V_98 ) {
V_97 . V_99 = F_90 ( V_97 . V_99 ) ;
F_91 ( & V_97 . V_95 , F_75 ) ;
V_97 . V_1 = V_1 ;
F_92 ( & V_97 . V_95 ) ;
F_93 ( & V_97 . V_99 ) ;
if ( F_94 ( V_97 . V_98 ) )
return F_95 ( V_97 . V_98 ) ;
V_98 = V_97 . V_98 ;
V_113 [ V_1 ] = V_97 . V_98 ;
}
F_96 ( V_98 , V_1 ) ;
if ( F_79 ( V_1 ) )
return - V_78 ;
do {
V_111 = F_13 ( V_1 , V_114 ) ;
if ( V_111 == V_24 )
F_27 ( 10 ) ;
if ( V_111 == V_115 )
goto V_116;
} while ( V_111 == V_24 );
V_101 = ( T_1 ) ( unsigned long ) V_16 [ V_1 ] ;
while ( F_97 ( V_101 , V_1 , V_117 ) == V_24 )
F_27 ( 10 ) ;
V_109 = V_16 [ V_1 ] ;
V_109 -> V_118 = ( unsigned long )
F_98 ( V_98 ) + V_119 ;
V_109 -> V_120 = ( unsigned long ) F_99 ( V_98 ) ;
V_10 = (struct V_9 * ) ( V_109 -> V_118
- sizeof( struct V_11 )
- sizeof( struct V_9 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_26 [ 9 ] = ( unsigned long ) V_10 ;
V_109 -> V_65 [ 15 ] = ( unsigned long ) V_10 ;
F_37 ( V_109 -> V_121 , 0 , 15 ) ;
F_100 ( & V_122 . V_123 . V_124 ) ;
asm volatile(
" stam 0,15,0(%0)"
: : "a" (&cpu_lowcore->access_regs_save_area) : "memory");
V_109 -> V_125 = V_126 [ V_1 ] ;
V_109 -> V_127 = ( unsigned long ) V_98 ;
V_109 -> V_128 = V_1 ;
V_109 -> V_129 = V_42 . V_129 ;
V_109 -> V_130 = V_42 . V_130 ;
V_109 -> V_131 = V_42 . V_131 ;
memcpy ( V_109 -> V_132 , V_42 . V_132 ,
V_133 / 8 ) ;
F_101 () ;
while ( F_13 ( V_1 , V_134 ) == V_24 )
F_27 ( 10 ) ;
while ( ! F_10 ( V_1 ) )
F_14 () ;
return 0 ;
V_116:
F_87 ( V_1 ) ;
return - V_112 ;
}
static int T_2 F_102 ( char * V_135 )
{
int V_136 , V_1 ;
V_136 = F_103 ( V_135 , NULL , 0 ) ;
F_104 ( F_105 ( 0 ) ) ;
for ( V_1 = 1 ; V_1 < V_136 && V_1 < V_71 ; V_1 ++ )
F_106 ( V_1 , true ) ;
return 0 ;
}
int F_107 ( void )
{
struct V_51 V_137 ;
int V_1 = F_7 () ;
F_71 ( V_1 , false ) ;
F_108 () ;
memset ( & V_137 . V_56 , 0 , sizeof( V_137 . V_56 ) ) ;
memset ( & V_137 . V_55 , 0xff , sizeof( V_137 . V_55 ) ) ;
V_137 . V_56 [ 0 ] = 0 ;
V_137 . V_55 [ 0 ] = ~ ( 1 << 15 | 1 << 14 | 1 << 13 | 1 << 11 |
1 << 10 | 1 << 9 | 1 << 6 | 1 << 4 ) ;
V_137 . V_56 [ 6 ] = 0 ;
V_137 . V_55 [ 6 ] = ~ ( 1 << 31 | 1 << 30 | 1 << 29 | 1 << 28 |
1 << 27 | 1 << 26 | 1 << 25 | 1 << 24 ) ;
V_137 . V_56 [ 14 ] = 0 ;
V_137 . V_55 [ 14 ] = ~ ( 1 << 28 | 1 << 27 | 1 << 26 |
1 << 25 | 1 << 24 ) ;
F_36 ( & V_137 ) ;
return 0 ;
}
void F_109 ( unsigned int V_1 )
{
while ( ! F_3 ( V_1 ) )
F_14 () ;
while ( F_97 ( 0 , V_1 , V_117 ) == V_24 )
F_27 ( 10 ) ;
F_87 ( V_1 ) ;
F_110 ( & V_122 . V_123 . V_124 ) ;
}
void T_6 F_111 ( void )
{
F_112 () ;
while ( F_13 ( F_7 () , V_35 ) == V_24 )
F_14 () ;
for (; ; ) ;
}
void T_2 F_113 ( unsigned int V_138 )
{
#ifndef F_82
unsigned long V_65 = 0 ;
#endif
unsigned long V_100 , V_25 ;
struct V_6 * V_101 ;
F_58 () ;
if ( F_114 ( 0x1201 , F_18 ) != 0 )
F_59 ( L_5 ) ;
V_101 = ( void * ) F_80 ( V_66 | V_102 , V_103 ) ;
V_25 = F_81 ( V_66 ) ;
V_100 = F_80 ( V_66 , V_104 ) ;
F_115 ( ! V_101 || ! V_25 || ! V_100 ) ;
#ifndef F_82
if ( V_107 )
V_65 = F_83 ( V_66 ) ;
#endif
F_116 () ;
F_117 () ;
V_16 [ F_7 () ] = V_101 ;
* V_101 = V_42 ;
V_101 -> V_25 = V_25 + V_106 ;
V_101 -> V_100 = V_100 + V_105 ;
#ifndef F_82
if ( V_107 )
V_101 -> V_108 = ( T_1 ) V_65 ;
#endif
F_118 ( ( T_1 ) ( unsigned long ) V_101 ) ;
F_119 () ;
F_73 () ;
#ifdef F_82
if ( F_84 ( F_7 () , & V_42 ) )
F_120 () ;
#endif
}
void T_2 F_121 ( void )
{
F_115 ( F_7 () != 0 ) ;
F_122 () -> V_1 = 0 ;
F_51 ( 0 , true ) ;
F_71 ( 0 , true ) ;
V_42 . V_125 = V_126 [ 0 ] ;
V_113 [ 0 ] = V_139 ;
V_75 [ 0 ] = V_76 ;
V_73 [ 0 ] = V_74 ;
}
void T_2 F_123 ( unsigned int V_138 )
{
}
void T_2 F_124 ( void )
{
V_42 . V_128 = 0 ;
V_22 [ 0 ] = F_12 () ;
}
int F_125 ( unsigned int V_140 )
{
return 0 ;
}
static T_7 F_126 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
T_7 V_146 ;
F_127 ( & V_147 ) ;
V_146 = sprintf ( V_145 , L_6 , V_75 [ V_142 -> V_148 ] ) ;
F_128 ( & V_147 ) ;
return V_146 ;
}
static T_7 F_129 ( struct V_141 * V_142 ,
struct V_143 * V_144 ,
const char * V_145 , T_8 V_146 )
{
int V_1 = V_142 -> V_148 ;
int V_149 , V_32 ;
char V_150 ;
if ( sscanf ( V_145 , L_7 , & V_149 , & V_150 ) != 1 )
return - V_151 ;
if ( V_149 != 0 && V_149 != 1 )
return - V_151 ;
F_61 () ;
F_127 ( & V_147 ) ;
V_32 = - V_152 ;
if ( F_10 ( V_1 ) || V_1 == 0 )
goto V_79;
V_32 = 0 ;
switch ( V_149 ) {
case 0 :
if ( V_75 [ V_1 ] == V_76 ) {
V_32 = F_130 ( V_22 [ V_1 ] ) ;
if ( ! V_32 ) {
V_75 [ V_1 ] = V_85 ;
V_73 [ V_1 ] = V_74 ;
}
}
break;
case 1 :
if ( V_75 [ V_1 ] == V_85 ) {
V_32 = F_131 ( V_22 [ V_1 ] ) ;
if ( ! V_32 ) {
V_75 [ V_1 ] = V_76 ;
V_73 [ V_1 ] = V_74 ;
}
}
break;
default:
break;
}
V_79:
F_128 ( & V_147 ) ;
F_62 () ;
return V_32 ? V_32 : V_146 ;
}
static T_7 F_132 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
int V_1 = V_142 -> V_148 ;
T_7 V_146 ;
F_127 ( & V_147 ) ;
switch ( V_73 [ V_1 ] ) {
case V_153 :
V_146 = sprintf ( V_145 , L_8 ) ;
break;
case V_154 :
V_146 = sprintf ( V_145 , L_9 ) ;
break;
case V_155 :
V_146 = sprintf ( V_145 , L_10 ) ;
break;
case V_156 :
V_146 = sprintf ( V_145 , L_11 ) ;
break;
default:
V_146 = sprintf ( V_145 , L_12 ) ;
break;
}
F_128 ( & V_147 ) ;
return V_146 ;
}
static T_7 F_133 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
return sprintf ( V_145 , L_6 , V_22 [ V_142 -> V_148 ] ) ;
}
static T_7 F_134 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
unsigned int V_157 ;
int V_32 ;
V_32 = F_135 ( & V_157 ) ;
if ( V_32 )
return V_32 ;
return sprintf ( V_145 , L_13 , V_157 ) ;
}
static T_7 F_136 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
struct V_158 * V_98 ;
unsigned long long V_159 ;
unsigned int V_160 ;
V_98 = & F_137 ( V_161 , V_142 -> V_148 ) ;
V_162:
V_160 = V_98 -> V_160 ;
F_138 () ;
if ( V_160 & 1 )
goto V_162;
V_159 = V_98 -> V_159 ;
if ( V_98 -> V_163 )
V_159 ++ ;
F_138 () ;
if ( V_98 -> V_160 != V_160 )
goto V_162;
return sprintf ( V_145 , L_14 , V_159 ) ;
}
static T_7 F_139 ( struct V_141 * V_142 ,
struct V_143 * V_144 , char * V_145 )
{
struct V_158 * V_98 ;
unsigned long long V_164 , V_165 , V_163 ;
unsigned int V_160 ;
V_98 = & F_137 ( V_161 , V_142 -> V_148 ) ;
V_164 = F_140 () ;
V_162:
V_160 = V_98 -> V_160 ;
F_138 () ;
if ( V_160 & 1 )
goto V_162;
V_165 = V_98 -> V_165 ;
V_163 = V_98 -> V_163 ;
if ( V_163 != 0ULL && V_163 < V_164 )
V_165 += V_164 - V_163 ;
F_138 () ;
if ( V_98 -> V_160 != V_160 )
goto V_162;
return sprintf ( V_145 , L_14 , V_165 >> 12 ) ;
}
static int T_5 F_141 ( struct V_166 * V_167 ,
unsigned long V_168 , void * V_169 )
{
unsigned int V_1 = ( unsigned int ) ( long ) V_169 ;
struct V_1 * V_170 = & F_137 ( V_171 , V_1 ) ;
struct V_141 * V_135 = & V_170 -> V_172 ;
struct V_158 * V_98 ;
int V_173 = 0 ;
switch ( V_168 ) {
case V_174 :
case V_175 :
V_98 = & F_137 ( V_161 , V_1 ) ;
memset ( V_98 , 0 , sizeof( struct V_158 ) ) ;
V_173 = F_142 ( & V_135 -> V_176 , & V_177 ) ;
break;
case V_178 :
case V_179 :
F_143 ( & V_135 -> V_176 , & V_177 ) ;
break;
}
return F_144 ( V_173 ) ;
}
static int T_9 F_145 ( int V_1 )
{
struct V_1 * V_170 = & F_137 ( V_171 , V_1 ) ;
struct V_141 * V_135 = & V_170 -> V_172 ;
int V_32 ;
V_170 -> V_180 = 1 ;
V_32 = F_146 ( V_170 , V_1 ) ;
if ( V_32 )
goto V_79;
V_32 = F_142 ( & V_135 -> V_176 , & V_181 ) ;
if ( V_32 )
goto V_182;
if ( ! F_10 ( V_1 ) )
goto V_79;
V_32 = F_142 ( & V_135 -> V_176 , & V_177 ) ;
if ( ! V_32 )
return 0 ;
F_143 ( & V_135 -> V_176 , & V_181 ) ;
V_182:
#ifdef F_147
F_148 ( V_170 ) ;
#endif
V_79:
return V_32 ;
}
int T_10 F_149 ( void )
{
T_3 V_183 ;
int V_1 ;
int V_32 ;
F_61 () ;
F_127 ( & V_147 ) ;
F_150 ( & V_183 , V_87 ) ;
V_32 = F_56 () ;
if ( V_32 )
goto V_79;
F_151 ( & V_183 , V_87 , & V_183 ) ;
F_29 (cpu, &newcpus) {
V_32 = F_145 ( V_1 ) ;
if ( V_32 )
F_51 ( V_1 , false ) ;
}
V_32 = 0 ;
V_79:
F_128 ( & V_147 ) ;
F_62 () ;
if ( ! F_152 ( & V_183 ) )
F_153 () ;
return V_32 ;
}
static T_7 T_10 F_154 ( struct V_184 * V_185 ,
struct V_186 * V_144 ,
const char * V_145 ,
T_8 V_146 )
{
int V_32 ;
V_32 = F_149 () ;
return V_32 ? V_32 : V_146 ;
}
static T_7 F_155 ( struct V_184 * V_185 ,
struct V_186 * V_144 ,
char * V_145 )
{
T_7 V_146 ;
F_127 ( & V_147 ) ;
V_146 = sprintf ( V_145 , L_6 , V_187 ) ;
F_128 ( & V_147 ) ;
return V_146 ;
}
static T_7 F_156 ( struct V_184 * V_142 ,
struct V_186 * V_144 ,
const char * V_145 ,
T_8 V_146 )
{
int V_149 , V_32 ;
char V_150 ;
if ( sscanf ( V_145 , L_7 , & V_149 , & V_150 ) != 1 )
return - V_151 ;
if ( V_149 != 0 && V_149 != 1 )
return - V_151 ;
V_32 = 0 ;
F_61 () ;
F_127 ( & V_147 ) ;
if ( V_187 == V_149 )
goto V_79;
V_32 = F_157 ( V_149 ) ;
if ( ! V_32 )
V_187 = V_149 ;
V_79:
F_128 ( & V_147 ) ;
F_62 () ;
return V_32 ? V_32 : V_146 ;
}
static int T_2 F_158 ( void )
{
int V_1 ;
int V_32 ;
F_159 ( & V_188 ) ;
#ifdef F_147
V_32 = F_160 ( & V_189 , & V_190 ) ;
if ( V_32 )
return V_32 ;
#endif
V_32 = F_160 ( & V_189 , & V_191 ) ;
if ( V_32 )
return V_32 ;
F_48 (cpu) {
V_32 = F_145 ( V_1 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
