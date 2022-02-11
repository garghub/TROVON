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
F_9 ( 0 , 28 ) ;
V_42 . V_17 . V_18 = V_14 | V_15 ;
V_42 . V_17 . V_19 =
V_20 | ( unsigned long ) V_94 ;
F_73 ( 0 , 28 ) ;
while ( ! F_74 ( F_7 () , V_95 ) )
F_14 () ;
F_75 () ;
F_76 () ;
return 0 ;
}
static void T_5 F_77 ( struct V_96 * V_97 )
{
struct V_98 * V_99 ;
V_99 = F_78 ( V_97 , struct V_98 , V_97 ) ;
V_99 -> V_100 = F_79 ( V_99 -> V_1 ) ;
F_80 ( & V_99 -> V_101 ) ;
}
static int T_5 F_81 ( int V_1 )
{
unsigned long V_102 , V_25 ;
struct V_6 * V_103 ;
V_103 = ( void * ) F_82 ( V_66 | V_104 , V_105 ) ;
if ( ! V_103 )
return - V_78 ;
V_102 = F_82 ( V_66 , V_106 ) ;
V_25 = F_83 ( V_66 ) ;
if ( ! V_25 || ! V_102 )
goto V_79;
memcpy ( V_103 , & V_42 , 512 ) ;
memset ( ( char * ) V_103 + 512 , 0 , sizeof( * V_103 ) - 512 ) ;
V_103 -> V_102 = V_102 + V_107 ;
V_103 -> V_25 = V_25 + V_108 ;
V_103 -> V_17 . V_18 = V_14 | V_15 ;
V_103 -> V_17 . V_19 =
V_20 | ( unsigned long ) V_109 ;
if ( V_110 != V_111 )
V_103 -> V_17 . V_18 |= V_112 ;
#ifndef F_84
if ( V_113 ) {
unsigned long V_65 ;
V_65 = F_85 ( V_66 ) ;
if ( ! V_65 )
goto V_79;
V_103 -> V_114 = ( T_1 ) V_65 ;
}
#else
if ( F_86 ( V_1 , V_103 ) )
goto V_79;
#endif
V_16 [ V_1 ] = V_103 ;
return 0 ;
V_79:
F_87 ( V_25 ) ;
F_88 ( V_102 , V_106 ) ;
F_88 ( ( unsigned long ) V_103 , V_105 ) ;
return - V_78 ;
}
static void F_89 ( int V_1 )
{
struct V_6 * V_103 ;
V_103 = V_16 [ V_1 ] ;
#ifndef F_84
if ( V_113 )
F_87 ( ( unsigned long ) V_103 -> V_114 ) ;
#else
F_90 ( V_1 , V_103 ) ;
#endif
F_87 ( V_103 -> V_25 - V_108 ) ;
F_88 ( V_103 -> V_102 - V_107 , V_106 ) ;
F_88 ( ( unsigned long ) V_103 , V_105 ) ;
V_16 [ V_1 ] = NULL ;
}
int T_5 F_91 ( unsigned int V_1 )
{
struct V_6 * V_115 ;
struct V_98 V_99 ;
struct V_116 * V_100 ;
struct V_9 * V_10 ;
T_1 V_103 ;
int V_117 ;
if ( V_75 [ V_1 ] != V_76 )
return - V_118 ;
V_100 = V_119 [ V_1 ] ;
if ( ! V_100 ) {
V_99 . V_101 = F_92 ( V_99 . V_101 ) ;
F_93 ( & V_99 . V_97 , F_77 ) ;
V_99 . V_1 = V_1 ;
F_94 ( & V_99 . V_97 ) ;
F_95 ( & V_99 . V_101 ) ;
if ( F_96 ( V_99 . V_100 ) )
return F_97 ( V_99 . V_100 ) ;
V_100 = V_99 . V_100 ;
V_119 [ V_1 ] = V_99 . V_100 ;
}
F_98 ( V_100 , V_1 ) ;
if ( F_81 ( V_1 ) )
return - V_78 ;
do {
V_117 = F_13 ( V_1 , V_120 ) ;
if ( V_117 == V_24 )
F_27 ( 10 ) ;
if ( V_117 == V_121 )
goto V_122;
} while ( V_117 == V_24 );
V_103 = ( T_1 ) ( unsigned long ) V_16 [ V_1 ] ;
while ( F_99 ( V_103 , V_1 , V_123 ) == V_24 )
F_27 ( 10 ) ;
V_115 = V_16 [ V_1 ] ;
V_115 -> V_124 = ( unsigned long )
F_100 ( V_100 ) + V_125 ;
V_115 -> V_126 = ( unsigned long ) F_101 ( V_100 ) ;
V_10 = (struct V_9 * ) ( V_115 -> V_124
- sizeof( struct V_11 )
- sizeof( struct V_9 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_26 [ 9 ] = ( unsigned long ) V_10 ;
V_115 -> V_65 [ 15 ] = ( unsigned long ) V_10 ;
F_37 ( V_115 -> V_127 , 0 , 15 ) ;
F_102 ( & V_128 . V_129 . V_130 ) ;
asm volatile(
" stam 0,15,0(%0)"
: : "a" (&cpu_lowcore->access_regs_save_area) : "memory");
V_115 -> V_131 = V_132 [ V_1 ] ;
V_115 -> V_133 = ( unsigned long ) V_100 ;
V_115 -> V_134 = V_1 ;
V_115 -> V_135 = V_42 . V_135 ;
V_115 -> V_136 = V_42 . V_136 ;
V_115 -> V_137 = V_42 . V_137 ;
memcpy ( V_115 -> V_138 , V_42 . V_138 ,
V_139 / 8 ) ;
F_103 () ;
while ( F_13 ( V_1 , V_140 ) == V_24 )
F_27 ( 10 ) ;
while ( ! F_10 ( V_1 ) )
F_14 () ;
return 0 ;
V_122:
F_89 ( V_1 ) ;
return - V_118 ;
}
static int T_2 F_104 ( char * V_141 )
{
int V_142 , V_1 ;
V_142 = F_105 ( V_141 , NULL , 0 ) ;
F_106 ( F_107 ( 0 ) ) ;
for ( V_1 = 1 ; V_1 < V_142 && V_1 < V_71 ; V_1 ++ )
F_108 ( V_1 , true ) ;
return 0 ;
}
int F_109 ( void )
{
struct V_51 V_143 ;
int V_1 = F_7 () ;
F_71 ( V_1 , false ) ;
F_110 () ;
memset ( & V_143 . V_56 , 0 , sizeof( V_143 . V_56 ) ) ;
memset ( & V_143 . V_55 , 0xff , sizeof( V_143 . V_55 ) ) ;
V_143 . V_56 [ 0 ] = 0 ;
V_143 . V_55 [ 0 ] = ~ ( 1 << 15 | 1 << 14 | 1 << 13 | 1 << 11 |
1 << 10 | 1 << 9 | 1 << 6 | 1 << 5 |
1 << 4 ) ;
V_143 . V_56 [ 6 ] = 0 ;
V_143 . V_55 [ 6 ] = ~ ( 1 << 31 | 1 << 30 | 1 << 29 | 1 << 28 |
1 << 27 | 1 << 26 | 1 << 25 | 1 << 24 ) ;
V_143 . V_56 [ 14 ] = 0 ;
V_143 . V_55 [ 14 ] = ~ ( 1 << 28 | 1 << 27 | 1 << 26 |
1 << 25 | 1 << 24 ) ;
F_36 ( & V_143 ) ;
return 0 ;
}
void F_111 ( unsigned int V_1 )
{
while ( ! F_3 ( V_1 ) )
F_14 () ;
while ( F_99 ( 0 , V_1 , V_123 ) == V_24 )
F_27 ( 10 ) ;
F_89 ( V_1 ) ;
F_112 ( & V_128 . V_129 . V_130 ) ;
}
void T_6 F_113 ( void )
{
F_114 () ;
while ( F_13 ( F_7 () , V_35 ) == V_24 )
F_14 () ;
for (; ; ) ;
}
void T_2 F_115 ( unsigned int V_144 )
{
#ifndef F_84
unsigned long V_65 = 0 ;
#endif
unsigned long V_102 , V_25 ;
struct V_6 * V_103 ;
F_58 () ;
if ( F_116 ( 0x1201 , F_18 ) != 0 )
F_59 ( L_5 ) ;
V_103 = ( void * ) F_82 ( V_66 | V_104 , V_105 ) ;
V_25 = F_83 ( V_66 ) ;
V_102 = F_82 ( V_66 , V_106 ) ;
F_117 ( ! V_103 || ! V_25 || ! V_102 ) ;
#ifndef F_84
if ( V_113 )
V_65 = F_85 ( V_66 ) ;
#endif
F_118 () ;
F_119 () ;
V_16 [ F_7 () ] = V_103 ;
* V_103 = V_42 ;
V_103 -> V_25 = V_25 + V_108 ;
V_103 -> V_102 = V_102 + V_107 ;
#ifndef F_84
if ( V_113 )
V_103 -> V_114 = ( T_1 ) V_65 ;
#endif
F_120 ( ( T_1 ) ( unsigned long ) V_103 ) ;
F_121 () ;
F_75 () ;
#ifdef F_84
if ( F_86 ( F_7 () , & V_42 ) )
F_122 () ;
#endif
}
void T_2 F_123 ( void )
{
F_117 ( F_7 () != 0 ) ;
F_124 () -> V_1 = 0 ;
F_51 ( 0 , true ) ;
F_71 ( 0 , true ) ;
V_42 . V_131 = V_132 [ 0 ] ;
V_119 [ 0 ] = V_145 ;
V_75 [ 0 ] = V_76 ;
V_73 [ 0 ] = V_74 ;
}
void T_2 F_125 ( unsigned int V_144 )
{
}
void T_2 F_126 ( void )
{
V_42 . V_134 = 0 ;
V_22 [ 0 ] = F_12 () ;
}
int F_127 ( unsigned int V_146 )
{
return 0 ;
}
static T_7 F_128 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
T_7 V_152 ;
F_129 ( & V_153 ) ;
V_152 = sprintf ( V_151 , L_6 , V_75 [ V_148 -> V_154 ] ) ;
F_130 ( & V_153 ) ;
return V_152 ;
}
static T_7 F_131 ( struct V_147 * V_148 ,
struct V_149 * V_150 ,
const char * V_151 , T_8 V_152 )
{
int V_1 = V_148 -> V_154 ;
int V_155 , V_32 ;
char V_156 ;
if ( sscanf ( V_151 , L_7 , & V_155 , & V_156 ) != 1 )
return - V_157 ;
if ( V_155 != 0 && V_155 != 1 )
return - V_157 ;
F_61 () ;
F_129 ( & V_153 ) ;
V_32 = - V_158 ;
if ( F_10 ( V_1 ) || V_1 == 0 )
goto V_79;
V_32 = 0 ;
switch ( V_155 ) {
case 0 :
if ( V_75 [ V_1 ] == V_76 ) {
V_32 = F_132 ( V_22 [ V_1 ] ) ;
if ( ! V_32 ) {
V_75 [ V_1 ] = V_85 ;
V_73 [ V_1 ] = V_74 ;
}
}
break;
case 1 :
if ( V_75 [ V_1 ] == V_85 ) {
V_32 = F_133 ( V_22 [ V_1 ] ) ;
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
F_130 ( & V_153 ) ;
F_62 () ;
return V_32 ? V_32 : V_152 ;
}
static T_7 F_134 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
int V_1 = V_148 -> V_154 ;
T_7 V_152 ;
F_129 ( & V_153 ) ;
switch ( V_73 [ V_1 ] ) {
case V_159 :
V_152 = sprintf ( V_151 , L_8 ) ;
break;
case V_160 :
V_152 = sprintf ( V_151 , L_9 ) ;
break;
case V_161 :
V_152 = sprintf ( V_151 , L_10 ) ;
break;
case V_162 :
V_152 = sprintf ( V_151 , L_11 ) ;
break;
default:
V_152 = sprintf ( V_151 , L_12 ) ;
break;
}
F_130 ( & V_153 ) ;
return V_152 ;
}
static T_7 F_135 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
return sprintf ( V_151 , L_6 , V_22 [ V_148 -> V_154 ] ) ;
}
static T_7 F_136 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
unsigned int V_163 ;
int V_32 ;
V_32 = F_137 ( & V_163 ) ;
if ( V_32 )
return V_32 ;
return sprintf ( V_151 , L_13 , V_163 ) ;
}
static T_7 F_138 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
struct V_164 * V_100 ;
unsigned long long V_165 ;
unsigned int V_166 ;
V_100 = & F_139 ( V_167 , V_148 -> V_154 ) ;
V_168:
V_166 = V_100 -> V_166 ;
F_140 () ;
if ( V_166 & 1 )
goto V_168;
V_165 = V_100 -> V_165 ;
if ( V_100 -> V_169 )
V_165 ++ ;
F_140 () ;
if ( V_100 -> V_166 != V_166 )
goto V_168;
return sprintf ( V_151 , L_14 , V_165 ) ;
}
static T_7 F_141 ( struct V_147 * V_148 ,
struct V_149 * V_150 , char * V_151 )
{
struct V_164 * V_100 ;
unsigned long long V_170 , V_171 , V_169 ;
unsigned int V_166 ;
V_100 = & F_139 ( V_167 , V_148 -> V_154 ) ;
V_170 = F_142 () ;
V_168:
V_166 = V_100 -> V_166 ;
F_140 () ;
if ( V_166 & 1 )
goto V_168;
V_171 = V_100 -> V_171 ;
V_169 = V_100 -> V_169 ;
if ( V_169 != 0ULL && V_169 < V_170 )
V_171 += V_170 - V_169 ;
F_140 () ;
if ( V_100 -> V_166 != V_166 )
goto V_168;
return sprintf ( V_151 , L_14 , V_171 >> 12 ) ;
}
static int T_5 F_143 ( struct V_172 * V_173 ,
unsigned long V_174 , void * V_175 )
{
unsigned int V_1 = ( unsigned int ) ( long ) V_175 ;
struct V_1 * V_176 = & F_139 ( V_177 , V_1 ) ;
struct V_147 * V_141 = & V_176 -> V_178 ;
struct V_164 * V_100 ;
int V_179 = 0 ;
switch ( V_174 ) {
case V_180 :
case V_181 :
V_100 = & F_139 ( V_167 , V_1 ) ;
memset ( V_100 , 0 , sizeof( struct V_164 ) ) ;
V_179 = F_144 ( & V_141 -> V_182 , & V_183 ) ;
break;
case V_184 :
case V_185 :
F_145 ( & V_141 -> V_182 , & V_183 ) ;
break;
}
return F_146 ( V_179 ) ;
}
static int T_9 F_147 ( int V_1 )
{
struct V_1 * V_176 = & F_139 ( V_177 , V_1 ) ;
struct V_147 * V_141 = & V_176 -> V_178 ;
int V_32 ;
V_176 -> V_186 = 1 ;
V_32 = F_148 ( V_176 , V_1 ) ;
if ( V_32 )
goto V_79;
V_32 = F_144 ( & V_141 -> V_182 , & V_187 ) ;
if ( V_32 )
goto V_188;
if ( ! F_10 ( V_1 ) )
goto V_79;
V_32 = F_144 ( & V_141 -> V_182 , & V_183 ) ;
if ( ! V_32 )
return 0 ;
F_145 ( & V_141 -> V_182 , & V_187 ) ;
V_188:
#ifdef F_149
F_150 ( V_176 ) ;
#endif
V_79:
return V_32 ;
}
int T_10 F_151 ( void )
{
T_3 V_189 ;
int V_1 ;
int V_32 ;
F_61 () ;
F_129 ( & V_153 ) ;
F_152 ( & V_189 , V_87 ) ;
V_32 = F_56 () ;
if ( V_32 )
goto V_79;
F_153 ( & V_189 , V_87 , & V_189 ) ;
F_29 (cpu, &newcpus) {
V_32 = F_147 ( V_1 ) ;
if ( V_32 )
F_51 ( V_1 , false ) ;
}
V_32 = 0 ;
V_79:
F_130 ( & V_153 ) ;
F_62 () ;
if ( ! F_154 ( & V_189 ) )
F_155 () ;
return V_32 ;
}
static T_7 T_10 F_156 ( struct V_190 * V_191 ,
struct V_192 * V_150 ,
const char * V_151 ,
T_8 V_152 )
{
int V_32 ;
V_32 = F_151 () ;
return V_32 ? V_32 : V_152 ;
}
static T_7 F_157 ( struct V_190 * V_191 ,
struct V_192 * V_150 ,
char * V_151 )
{
T_7 V_152 ;
F_129 ( & V_153 ) ;
V_152 = sprintf ( V_151 , L_6 , V_193 ) ;
F_130 ( & V_153 ) ;
return V_152 ;
}
static T_7 F_158 ( struct V_190 * V_148 ,
struct V_192 * V_150 ,
const char * V_151 ,
T_8 V_152 )
{
int V_155 , V_32 ;
char V_156 ;
if ( sscanf ( V_151 , L_7 , & V_155 , & V_156 ) != 1 )
return - V_157 ;
if ( V_155 != 0 && V_155 != 1 )
return - V_157 ;
V_32 = 0 ;
F_61 () ;
F_129 ( & V_153 ) ;
if ( V_193 == V_155 )
goto V_79;
V_32 = F_159 ( V_155 ) ;
if ( ! V_32 )
V_193 = V_155 ;
V_79:
F_130 ( & V_153 ) ;
F_62 () ;
return V_32 ? V_32 : V_152 ;
}
static int T_2 F_160 ( void )
{
int V_1 ;
int V_32 ;
F_161 ( & V_194 ) ;
#ifdef F_149
V_32 = F_162 ( & V_195 , & V_196 ) ;
if ( V_32 )
return V_32 ;
#endif
V_32 = F_162 ( & V_195 , & V_197 ) ;
if ( V_32 )
return V_32 ;
F_48 (cpu) {
V_32 = F_147 ( V_1 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
