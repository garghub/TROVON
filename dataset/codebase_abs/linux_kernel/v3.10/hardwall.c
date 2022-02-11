static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 ) ;
V_2 [ V_3 ] . V_4 = 1 ;
return 0 ;
}
static int T_1 F_3 ( char * V_1 )
{
F_2 ( L_2 ) ;
V_2 [ V_5 ] . V_4 = 1 ;
return 0 ;
}
static int T_1 F_4 ( char * V_1 )
{
F_2 ( L_3 ) ;
V_2 [ V_6 ] . V_4 = 1 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , int V_9 , int V_10 )
{
return ( V_9 >= V_8 -> V_11 && V_9 < V_8 -> V_11 + V_8 -> V_12 ) &&
( V_10 >= V_8 -> V_13 && V_10 < V_8 -> V_13 + V_8 -> V_14 ) ;
}
static int F_6 ( struct V_7 * V_8 , struct V_15 * V_16 )
{
int V_9 , V_10 , V_17 , V_18 , V_19 ;
V_18 = F_7 ( F_8 ( V_16 ) , V_20 ) ;
V_19 = F_9 ( F_8 ( V_16 ) , V_20 ) ;
V_8 -> V_11 = F_10 ( V_18 ) ;
V_8 -> V_13 = F_11 ( V_18 ) ;
V_8 -> V_12 = F_10 ( V_19 ) - V_8 -> V_11 + 1 ;
V_8 -> V_14 = F_11 ( V_19 ) - V_8 -> V_13 + 1 ;
if ( V_8 -> V_12 <= 0 || V_8 -> V_14 <= 0 )
return - V_21 ;
for ( V_10 = 0 , V_17 = 0 ; V_10 < V_22 ; ++ V_10 )
for ( V_9 = 0 ; V_9 < V_23 ; ++ V_9 , ++ V_17 )
if ( F_12 ( V_17 , V_16 ) != F_5 ( V_8 , V_9 , V_10 ) )
return - V_21 ;
return 0 ;
}
static inline int F_13 ( struct V_24 * V_25 )
{
#ifndef F_14
if ( V_25 -> V_26 )
return V_27 ;
#endif
return V_28 ;
}
static void F_15 ( struct V_24 * V_25 )
{
F_16 ( F_13 ( V_25 ) ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
F_18 ( F_13 ( V_25 ) ) ;
}
static void F_19 ( void * V_29 )
{
struct V_7 * V_8 = V_29 ;
struct V_24 * V_25 = V_8 -> type ;
int V_17 = F_20 () ;
int V_9 = V_17 % V_23 ;
int V_10 = V_17 / V_23 ;
int V_30 = 0 ;
if ( V_9 == V_8 -> V_11 )
V_30 |= V_31 ;
if ( V_9 == V_8 -> V_11 + V_8 -> V_12 - 1 )
V_30 |= V_32 ;
if ( V_10 == V_8 -> V_13 )
V_30 |= V_33 ;
if ( V_10 == V_8 -> V_13 + V_8 -> V_14 - 1 )
V_30 |= V_34 ;
F_21 ( V_30 == 0 ) ;
F_22 ( V_25 , V_35 , V_30 ) ;
F_15 ( V_25 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
int V_9 , V_10 , V_17 , V_36 ;
struct V_15 V_37 ;
F_24 ( & V_37 ) ;
V_17 = V_8 -> V_13 * V_23 + V_8 -> V_11 ;
V_36 = ( V_8 -> V_14 - 1 ) * V_23 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_12 ; ++ V_9 , ++ V_17 ) {
F_25 ( V_17 , & V_37 ) ;
F_25 ( V_17 + V_36 , & V_37 ) ;
}
V_17 -= V_8 -> V_12 ;
V_36 = V_8 -> V_12 - 1 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; ++ V_10 , V_17 += V_23 ) {
F_25 ( V_17 , & V_37 ) ;
F_25 ( V_17 + V_36 , & V_37 ) ;
}
F_26 ( & V_37 , F_19 , V_8 , 1 ) ;
}
void T_2 F_27 ( struct V_38 * V_39 , int V_40 )
{
struct V_7 * V_41 ;
struct V_24 * V_25 ;
struct V_42 * V_43 ;
struct V_44 V_29 ;
int V_17 = F_20 () ;
int V_45 ;
unsigned long V_46 ;
struct V_38 * V_47 = F_28 ( V_39 ) ;
F_29 () ;
switch ( V_40 ) {
#ifndef F_14
case V_27 :
V_25 = & V_2 [ V_5 ] ;
break;
#endif
case V_28 :
V_25 = & V_2 [ V_3 ] ;
break;
default:
F_30 () ;
}
F_21 ( V_25 -> V_4 ) ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_32 (rect, &hwt->list, list) {
if ( F_12 ( V_17 , & V_41 -> V_15 ) )
break;
}
F_21 ( & V_41 -> V_49 == & V_25 -> V_49 ) ;
if ( V_41 -> V_50 ) {
F_33 ( L_4
L_5 ,
V_17 , V_25 -> V_51 ,
( long ) F_34 ( V_25 , V_35 ) ) ;
goto V_52;
}
V_41 -> V_50 = 1 ;
F_35 () ;
F_33 ( L_6 ,
V_17 , V_25 -> V_51 , ( long ) F_34 ( V_25 , V_35 ) ) ;
V_29 . V_53 = V_54 ;
V_29 . V_55 = 0 ;
V_29 . V_56 = V_57 ;
V_45 = 0 ;
F_32 (p, &rect->task_head,
thread.hardwall[hwt->index].list) {
F_21 ( V_43 -> V_58 . V_59 [ V_25 -> V_60 ] . V_29 != V_41 ) ;
if ( ! ( V_43 -> V_46 & V_61 ) ) {
V_45 = 1 ;
F_33 ( L_7 , V_43 -> V_62 ) ;
F_36 ( V_29 . V_53 , & V_29 , V_43 , false ) ;
}
}
if ( ! V_45 )
F_33 ( L_8 ) ;
V_52:
F_37 ( & V_25 -> V_48 , V_46 ) ;
F_17 ( V_25 ) ;
F_38 () ;
F_28 ( V_47 ) ;
}
void F_39 ( struct V_24 * V_25 )
{
#ifndef F_14
if ( ! V_25 -> V_63 ) {
F_40 ( V_64 , 1 ) ;
return;
}
#endif
F_41 ( V_25 , V_65 , 1 ) ;
F_41 ( V_25 , V_66 , 1 ) ;
F_41 ( V_25 , V_67 , 1 ) ;
F_41 ( V_25 , V_68 , 1 ) ;
#if ! F_42 ()
F_41 ( V_25 , V_69 , 1 ) ;
F_41 ( V_25 , V_70 , 1 ) ;
#endif
}
void F_43 ( struct V_24 * V_25 )
{
#ifndef F_14
if ( ! V_25 -> V_63 ) {
F_40 ( V_71 , 1 ) ;
return;
}
#endif
F_41 ( V_25 , V_72 , 1 ) ;
F_41 ( V_25 , V_73 , 1 ) ;
F_41 ( V_25 , V_74 , 1 ) ;
F_41 ( V_25 , V_75 , 1 ) ;
#if ! F_42 ()
F_41 ( V_25 , V_76 , 1 ) ;
F_41 ( V_25 , V_77 , 1 ) ;
#endif
}
void F_44 ( struct V_42 * V_78 ,
struct V_42 * V_79 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 ) {
if ( V_78 -> V_58 . V_59 [ V_80 ] . V_29 != NULL ) {
if ( V_79 -> V_58 . V_59 [ V_80 ] . V_29 == NULL )
F_43 ( & V_2 [ V_80 ] ) ;
} else if ( V_79 -> V_58 . V_59 [ V_80 ] . V_29 != NULL ) {
F_39 ( & V_2 [ V_80 ] ) ;
}
}
}
int F_45 ( int V_17 )
{
#ifdef F_46
struct V_7 * V_29 =
V_82 -> V_58 . V_59 [ V_6 ] . V_29 ;
return V_29 && F_12 ( V_17 , & V_29 -> V_15 ) ;
#else
return 0 ;
#endif
}
static struct V_7 * F_47 ( struct V_24 * V_25 ,
T_3 V_83 ,
const unsigned char T_4 * V_30 )
{
struct V_7 * V_84 , * V_29 ;
struct V_15 V_16 ;
unsigned long V_46 ;
int V_85 ;
if ( V_83 > V_86 )
return F_48 ( - V_21 ) ;
if ( F_49 ( & V_16 , V_30 , F_50 ( sizeof( struct V_15 ) , V_83 ) ) )
return F_48 ( - V_87 ) ;
if ( V_83 < sizeof( struct V_15 ) ) {
memset ( ( char * ) & V_16 + V_83 , 0 , sizeof( struct V_15 ) - V_83 ) ;
} else if ( V_83 > sizeof( struct V_15 ) ) {
T_3 V_80 ;
for ( V_80 = sizeof( struct V_15 ) ; V_80 < V_83 ; ++ V_80 ) {
char V_88 ;
if ( F_51 ( V_88 , & V_30 [ V_80 ] ) )
return F_48 ( - V_87 ) ;
if ( V_88 )
return F_48 ( - V_21 ) ;
}
}
V_29 = F_52 ( sizeof( struct V_7 ) ,
V_89 | V_90 ) ;
if ( V_29 == NULL )
return F_48 ( - V_91 ) ;
F_53 ( & V_29 -> V_92 ) ;
V_29 -> type = V_25 ;
F_54 ( & V_29 -> V_15 , & V_16 ) ;
V_29 -> V_93 = F_7 ( F_8 ( & V_16 ) , V_20 ) ;
if ( V_25 -> V_63 ) {
V_85 = F_6 ( V_29 , & V_16 ) ;
if ( V_85 != 0 ) {
F_55 ( V_29 ) ;
return F_48 ( V_85 ) ;
}
}
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_32 (iter, &hwt->list, list) {
if ( F_56 ( & V_84 -> V_15 , & V_29 -> V_15 ) ) {
F_37 ( & V_25 -> V_48 , V_46 ) ;
F_55 ( V_29 ) ;
return F_48 ( - V_94 ) ;
}
}
F_57 ( & V_29 -> V_49 , & V_25 -> V_49 ) ;
F_37 ( & V_25 -> V_48 , V_46 ) ;
if ( V_25 -> V_63 )
F_23 ( V_29 ) ;
F_58 ( V_29 ) ;
return V_29 ;
}
static int F_59 ( struct V_7 * V_29 )
{
int V_17 ;
unsigned long V_46 ;
struct V_42 * V_43 = V_82 ;
struct V_95 * V_96 = & V_43 -> V_58 ;
struct V_24 * V_25 ;
if ( V_29 == NULL )
return - V_97 ;
if ( V_29 -> V_50 )
return - V_21 ;
if ( F_60 ( & V_43 -> V_98 ) != 1 )
return - V_99 ;
V_17 = F_20 () ;
F_21 ( F_61 ( & V_43 -> V_98 ) != V_17 ) ;
if ( ! F_12 ( V_17 , & V_29 -> V_15 ) )
return - V_21 ;
V_25 = V_29 -> type ;
if ( V_96 -> V_59 [ V_25 -> V_60 ] . V_29 ) {
F_21 ( V_96 -> V_59 [ V_25 -> V_60 ] . V_29 != V_29 ) ;
return 0 ;
}
V_96 -> V_59 [ V_25 -> V_60 ] . V_29 = V_29 ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_62 ( & V_96 -> V_59 [ V_25 -> V_60 ] . V_49 , & V_29 -> V_92 ) ;
F_37 ( & V_25 -> V_48 , V_46 ) ;
F_39 ( V_25 ) ;
F_63 ( V_100 L_9 ,
V_43 -> V_62 , V_43 -> V_101 , V_25 -> V_51 , V_17 ) ;
return 0 ;
}
static void F_64 ( struct V_24 * V_25 ,
struct V_42 * V_102 )
{
struct V_95 * V_96 = & V_102 -> V_58 ;
if ( F_60 ( & V_102 -> V_98 ) != 1 ) {
F_65 ( L_10
L_11 ,
V_102 -> V_62 , V_102 -> V_101 , V_25 -> V_51 ,
F_60 ( & V_102 -> V_98 ) ) ;
F_30 () ;
}
F_21 ( V_96 -> V_59 [ V_25 -> V_60 ] . V_29 == NULL ) ;
V_96 -> V_59 [ V_25 -> V_60 ] . V_29 = NULL ;
F_66 ( & V_96 -> V_59 [ V_25 -> V_60 ] . V_49 ) ;
if ( V_102 == V_82 )
F_43 ( V_25 ) ;
}
static int F_67 ( struct V_24 * V_25 ,
struct V_42 * V_102 )
{
unsigned long V_46 ;
int V_103 ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
V_103 = ( V_102 -> V_58 . V_59 [ V_25 -> V_60 ] . V_29 != NULL ) ;
if ( V_103 )
F_64 ( V_25 , V_102 ) ;
F_37 ( & V_25 -> V_48 , V_46 ) ;
if ( ! V_103 )
return - V_21 ;
F_63 ( V_100 L_12 ,
V_102 -> V_62 , V_102 -> V_101 , V_25 -> V_51 , F_20 () ) ;
return 0 ;
}
void F_68 ( struct V_42 * V_102 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 )
if ( V_102 -> V_58 . V_59 [ V_80 ] . V_29 )
F_67 ( & V_2 [ V_80 ] , V_102 ) ;
}
static void F_69 ( void * V_104 )
{
#if ! F_42 ()
F_40 ( V_105 ,
V_106 |
V_107 |
V_108 ) ;
#else
struct V_24 * V_25 = V_104 ;
unsigned long V_109 = F_34 ( V_25 , V_35 ) ;
F_22 ( V_25 , V_35 , ( V_109 | V_110 ) << 5 ) ;
#endif
}
static void F_70 ( struct V_24 * V_25 )
{
#ifndef F_14
if ( V_25 -> V_26 ) {
while ( F_71 ( V_111 ) & ( 1 << 0 ) )
( void ) F_72 () ;
while ( F_71 ( V_111 ) & ( 1 << 1 ) )
( void ) F_73 () ;
return;
}
#endif
while ( F_71 ( V_112 ) & ( 1 << 0 ) )
( void ) F_74 () ;
while ( F_71 ( V_112 ) & ( 1 << 1 ) )
( void ) F_75 () ;
while ( F_71 ( V_112 ) & ( 1 << 2 ) )
( void ) F_76 () ;
while ( F_71 ( V_112 ) & ( 1 << 3 ) )
( void ) F_77 () ;
}
static void F_78 ( void * V_104 )
{
struct V_7 * V_29 = V_104 ;
struct V_24 * V_25 = V_29 -> type ;
#if F_42 ()
int V_113 = F_34 ( V_25 , V_114 ) ;
while ( V_113 -- ) {
F_70 ( V_25 ) ;
if ( V_25 -> V_26 )
F_79 ( 0 ) ;
else
F_80 ( 0 ) ;
}
F_81 ( & V_29 -> V_115 ) ;
while ( F_82 ( & V_29 -> V_115 ) )
F_70 ( V_25 ) ;
#else
int V_80 ;
int V_116 , V_117 ;
for ( V_80 = 0 ; V_80 < 5 ; V_80 ++ ) {
int V_118 , V_119 ;
F_40 ( V_120 , V_80 ) ;
V_118 = F_71 ( V_121 ) & 0xF ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ )
( void ) F_71 ( V_122 ) ;
F_21 ( ( F_71 ( V_121 ) & 0xF ) != 0 ) ;
}
V_116 = ( F_71 ( V_123 ) >> 10 ) & 0x3 ;
for ( V_80 = 0 ; V_80 < V_116 ; V_80 ++ )
( void ) F_71 ( V_124 ) ;
F_70 ( V_25 ) ;
V_117 = F_71 ( V_125 ) ;
for ( V_80 = 0 ; V_80 < V_117 ; V_80 ++ )
( void ) F_71 ( V_126 ) ;
F_21 ( F_71 ( V_125 ) != 0 ) ;
F_40 ( V_127 , 1 ) ;
for ( V_80 = 0 ; V_80 < 5 ; V_80 ++ ) {
F_40 ( V_120 , V_80 ) ;
F_40 ( V_121 , 0xc3000 ) ;
}
#endif
}
static void F_83 ( struct V_24 * V_25 )
{
if ( V_25 -> V_4 )
return;
F_22 ( V_25 , V_35 , 0 ) ;
F_22 ( V_25 , V_128 , 0 ) ;
F_22 ( V_25 , V_129 , 0 ) ;
#if ! F_42 ()
{
unsigned int V_17 = F_20 () ;
unsigned int V_9 = V_17 % V_23 ;
unsigned int V_10 = V_17 / V_23 ;
F_40 ( V_130 , ( V_9 << 18 ) | ( V_10 << 7 ) ) ;
}
F_40 ( V_131 , 0xf ) ;
F_40 ( V_132 , ( 1 << 0 ) ) ;
F_40 ( V_133 , ( 1 << 1 ) ) ;
F_40 ( V_134 , ( 1 << 2 ) ) ;
F_40 ( V_135 , ( 1 << 3 ) ) ;
F_40 ( V_136 , 0 ) ;
F_40 ( V_137 , 0 ) ;
F_40 ( V_120 , 0 ) ;
F_40 ( V_105 , 0 ) ;
#endif
}
void F_84 ( void )
{
F_83 ( & V_2 [ V_3 ] ) ;
#ifndef F_14
F_83 ( & V_2 [ V_5 ] ) ;
#endif
}
static void F_85 ( void * V_104 )
{
struct V_24 * V_25 = V_104 ;
#if F_42 ()
F_70 ( V_25 ) ;
#endif
F_83 ( V_25 ) ;
F_17 ( V_25 ) ;
}
static void F_86 ( struct V_7 * V_29 )
{
struct V_42 * V_102 ;
struct V_24 * V_25 ;
unsigned long V_46 ;
if ( V_29 == NULL )
return;
V_25 = V_29 -> type ;
V_29 -> V_50 = 1 ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_32 (task, &info->task_head,
thread.hardwall[hwt->index].list)
F_64 ( V_25 , V_102 ) ;
F_37 ( & V_25 -> V_48 , V_46 ) ;
if ( V_25 -> V_63 ) {
F_63 ( V_100
L_13 ,
V_25 -> V_51 , V_29 -> V_12 , V_29 -> V_14 ,
V_29 -> V_11 , V_29 -> V_13 ) ;
F_26 ( & V_29 -> V_15 , F_69 , V_25 , 1 ) ;
#if F_42 ()
F_87 ( & V_29 -> V_115 ,
F_60 ( & V_29 -> V_15 ) ) ;
F_26 ( & V_29 -> V_15 , F_78 , V_29 , 0 ) ;
#else
F_26 ( & V_29 -> V_15 , F_78 , V_29 , 1 ) ;
#endif
F_26 ( & V_29 -> V_15 , F_85 , V_25 , 1 ) ;
}
F_88 ( V_29 ) ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_21 ( ! F_89 ( & V_29 -> V_92 ) ) ;
F_66 ( & V_29 -> V_49 ) ;
F_37 ( & V_25 -> V_48 , V_46 ) ;
F_55 ( V_29 ) ;
}
static int F_90 ( struct V_138 * V_139 , void * V_140 )
{
struct V_7 * V_29 = V_139 -> V_141 ;
char V_142 [ 256 ] ;
int V_85 = F_91 ( V_142 , sizeof( V_142 ) , & V_29 -> V_15 ) ;
V_142 [ V_85 ++ ] = '\n' ;
F_92 ( V_139 , V_142 , V_85 ) ;
return 0 ;
}
static int F_93 ( struct V_143 * V_143 ,
struct V_144 * V_144 )
{
return F_94 ( V_144 , F_90 , F_95 ( V_143 ) ) ;
}
static void F_58 ( struct V_7 * V_29 )
{
char V_142 [ 64 ] ;
snprintf ( V_142 , sizeof( V_142 ) , L_14 , V_29 -> V_93 ) ;
F_96 ( V_142 , 0444 , V_29 -> type -> V_145 ,
& V_146 , V_29 ) ;
}
static void F_88 ( struct V_7 * V_29 )
{
char V_142 [ 64 ] ;
snprintf ( V_142 , sizeof( V_142 ) , L_14 , V_29 -> V_93 ) ;
F_97 ( V_142 , V_29 -> type -> V_145 ) ;
}
int F_98 ( struct V_42 * V_102 , char * V_147 )
{
int V_80 ;
int V_148 = 0 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 ) {
struct V_7 * V_29 = V_102 -> V_58 . V_59 [ V_80 ] . V_29 ;
if ( V_29 )
V_148 += sprintf ( & V_147 [ V_148 ] , L_15 ,
V_29 -> type -> V_51 , V_29 -> V_93 ) ;
}
return V_148 ;
}
void F_99 ( struct V_149 * V_150 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 ) {
struct V_24 * V_25 = & V_2 [ V_80 ] ;
if ( V_25 -> V_4 )
continue;
if ( V_151 == NULL )
V_151 = F_100 ( L_16 , V_150 ) ;
V_25 -> V_145 = F_100 ( V_25 -> V_51 , V_151 ) ;
}
}
static long F_101 ( struct V_144 * V_144 , unsigned int V_152 , unsigned long V_153 )
{
struct V_7 * V_29 = V_144 -> V_154 ;
int V_155 = F_102 ( V_144 -> V_156 -> V_157 ) ;
struct V_24 * V_25 ;
if ( F_103 ( V_152 ) != V_158 )
return - V_21 ;
F_104 ( V_81 != V_159 ) ;
F_104 ( V_81 !=
sizeof( V_2 ) / sizeof( V_2 [ 0 ] ) ) ;
if ( V_155 < 0 || V_155 >= V_81 )
return - V_21 ;
V_25 = & V_2 [ V_155 ] ;
F_105 ( V_29 && V_25 != V_29 -> type ) ;
switch ( F_106 ( V_152 ) ) {
case V_160 :
if ( V_25 -> V_4 )
return - V_161 ;
if ( V_29 != NULL )
return - V_162 ;
V_29 = F_47 ( V_25 , F_107 ( V_152 ) ,
( const unsigned char T_4 * ) V_153 ) ;
if ( F_108 ( V_29 ) )
return F_109 ( V_29 ) ;
V_144 -> V_154 = V_29 ;
return 0 ;
case V_163 :
return F_59 ( V_29 ) ;
case V_164 :
if ( V_82 -> V_58 . V_59 [ V_25 -> V_60 ] . V_29 != V_29 )
return - V_21 ;
return F_67 ( V_25 , V_82 ) ;
case V_165 :
return V_29 ? V_29 -> V_93 : - V_21 ;
default:
return - V_21 ;
}
}
static long F_110 ( struct V_144 * V_144 ,
unsigned int V_152 , unsigned long V_153 )
{
return F_101 ( V_144 , V_152 , ( unsigned long ) F_111 ( V_153 ) ) ;
}
static int F_112 ( struct V_144 * V_144 , T_5 V_166 )
{
struct V_7 * V_29 = V_144 -> V_154 ;
struct V_42 * V_102 , * V_167 ;
unsigned long V_46 ;
if ( V_29 ) {
struct V_24 * V_25 = V_29 -> type ;
F_31 ( & V_25 -> V_48 , V_46 ) ;
F_113 (task, tmp, &info->task_head,
thread.hardwall[hwt->index].list) {
if ( V_102 -> V_168 == V_166 || V_102 -> V_168 == NULL )
F_64 ( V_25 , V_102 ) ;
}
F_37 ( & V_25 -> V_48 , V_46 ) ;
}
return 0 ;
}
static int F_114 ( struct V_143 * V_143 , struct V_144 * V_144 )
{
F_86 ( V_144 -> V_154 ) ;
return 0 ;
}
static int T_1 F_115 ( void )
{
int V_85 ;
T_6 V_169 ;
V_85 = F_116 ( & V_169 , 0 , V_81 , L_16 ) ;
if ( V_85 < 0 )
return V_85 ;
F_117 ( & V_170 , & V_171 ) ;
V_85 = F_118 ( & V_170 , V_169 , V_81 ) ;
if ( V_85 < 0 )
return V_85 ;
return 0 ;
}
