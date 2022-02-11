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
int V_9 = F_10 ( V_17 ) ;
int V_10 = F_11 ( V_17 ) ;
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
struct V_38 * V_46 = F_28 ( V_39 ) ;
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
F_31 ( & V_25 -> V_47 ) ;
F_32 (rect, &hwt->list, list) {
if ( F_12 ( V_17 , & V_41 -> V_15 ) )
break;
}
F_21 ( & V_41 -> V_48 == & V_25 -> V_48 ) ;
if ( V_41 -> V_49 ) {
F_33 ( L_4 ,
V_17 , V_25 -> V_50 ,
( long ) F_34 ( V_25 , V_35 ) ) ;
goto V_51;
}
V_41 -> V_49 = 1 ;
F_35 () ;
F_33 ( L_5 ,
V_17 , V_25 -> V_50 , ( long ) F_34 ( V_25 , V_35 ) ) ;
V_29 . V_52 = V_53 ;
V_29 . V_54 = 0 ;
V_29 . V_55 = V_56 ;
V_45 = 0 ;
F_32 (p, &rect->task_head,
thread.hardwall[hwt->index].list) {
F_21 ( V_43 -> V_57 . V_58 [ V_25 -> V_59 ] . V_29 != V_41 ) ;
if ( ! ( V_43 -> V_60 & V_61 ) ) {
V_45 = 1 ;
F_33 ( L_6 , V_43 -> V_62 ) ;
F_36 ( V_29 . V_52 , & V_29 , V_43 , false ) ;
}
}
if ( ! V_45 )
F_33 ( L_7 ) ;
V_51:
F_37 ( & V_25 -> V_47 ) ;
F_17 ( V_25 ) ;
F_38 () ;
F_28 ( V_46 ) ;
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
if ( V_78 -> V_57 . V_58 [ V_80 ] . V_29 != NULL ) {
if ( V_79 -> V_57 . V_58 [ V_80 ] . V_29 == NULL )
F_43 ( & V_2 [ V_80 ] ) ;
} else if ( V_79 -> V_57 . V_58 [ V_80 ] . V_29 != NULL ) {
F_39 ( & V_2 [ V_80 ] ) ;
}
}
}
int F_45 ( int V_17 )
{
#ifdef F_46
struct V_7 * V_29 =
V_82 -> V_57 . V_58 [ V_6 ] . V_29 ;
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
unsigned long V_60 ;
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
F_56 ( & V_29 -> V_15 , & V_29 -> V_15 , V_94 ) ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
F_32 (iter, &hwt->list, list) {
if ( F_58 ( & V_84 -> V_15 , & V_29 -> V_15 ) ) {
F_59 ( & V_25 -> V_47 , V_60 ) ;
F_55 ( V_29 ) ;
return F_48 ( - V_95 ) ;
}
}
F_60 ( & V_29 -> V_48 , & V_25 -> V_48 ) ;
F_59 ( & V_25 -> V_47 , V_60 ) ;
if ( V_25 -> V_63 )
F_23 ( V_29 ) ;
F_61 ( V_29 ) ;
return V_29 ;
}
static int F_62 ( struct V_7 * V_29 )
{
int V_17 ;
unsigned long V_60 ;
struct V_42 * V_43 = V_82 ;
struct V_96 * V_97 = & V_43 -> V_57 ;
struct V_24 * V_25 ;
if ( V_29 == NULL )
return - V_98 ;
if ( V_29 -> V_49 )
return - V_21 ;
if ( F_63 ( & V_43 -> V_99 ) != 1 )
return - V_100 ;
V_17 = F_20 () ;
F_21 ( F_64 ( & V_43 -> V_99 ) != V_17 ) ;
if ( ! F_12 ( V_17 , & V_29 -> V_15 ) )
return - V_21 ;
V_25 = V_29 -> type ;
if ( V_97 -> V_58 [ V_25 -> V_59 ] . V_29 ) {
F_21 ( V_97 -> V_58 [ V_25 -> V_59 ] . V_29 != V_29 ) ;
return 0 ;
}
V_97 -> V_58 [ V_25 -> V_59 ] . V_29 = V_29 ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
F_65 ( & V_97 -> V_58 [ V_25 -> V_59 ] . V_48 , & V_29 -> V_92 ) ;
F_59 ( & V_25 -> V_47 , V_60 ) ;
F_39 ( V_25 ) ;
F_66 ( V_101 L_8 ,
V_43 -> V_62 , V_43 -> V_102 , V_25 -> V_50 , V_17 ) ;
return 0 ;
}
static void F_67 ( struct V_24 * V_25 ,
struct V_42 * V_103 )
{
struct V_96 * V_97 = & V_103 -> V_57 ;
if ( F_63 ( & V_103 -> V_99 ) != 1 ) {
F_68 ( L_9 ,
V_103 -> V_62 , V_103 -> V_102 , V_25 -> V_50 ,
F_63 ( & V_103 -> V_99 ) ) ;
F_30 () ;
}
F_21 ( V_97 -> V_58 [ V_25 -> V_59 ] . V_29 == NULL ) ;
V_97 -> V_58 [ V_25 -> V_59 ] . V_29 = NULL ;
F_69 ( & V_97 -> V_58 [ V_25 -> V_59 ] . V_48 ) ;
if ( V_103 == V_82 )
F_43 ( V_25 ) ;
}
static int F_70 ( struct V_24 * V_25 ,
struct V_42 * V_103 )
{
unsigned long V_60 ;
int V_104 ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
V_104 = ( V_103 -> V_57 . V_58 [ V_25 -> V_59 ] . V_29 != NULL ) ;
if ( V_104 )
F_67 ( V_25 , V_103 ) ;
F_59 ( & V_25 -> V_47 , V_60 ) ;
if ( ! V_104 )
return - V_21 ;
F_66 ( V_101 L_10 ,
V_103 -> V_62 , V_103 -> V_102 , V_25 -> V_50 , F_71 () ) ;
return 0 ;
}
void F_72 ( struct V_42 * V_103 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 )
if ( V_103 -> V_57 . V_58 [ V_80 ] . V_29 )
F_70 ( & V_2 [ V_80 ] , V_103 ) ;
}
static void F_73 ( void * V_105 )
{
#if ! F_42 ()
F_40 ( V_106 ,
V_107 |
V_108 |
V_109 ) ;
#else
struct V_24 * V_25 = V_105 ;
unsigned long V_110 = F_34 ( V_25 , V_35 ) ;
F_22 ( V_25 , V_35 , ( V_110 | V_111 ) << 5 ) ;
#endif
}
static void F_74 ( struct V_24 * V_25 )
{
#ifndef F_14
if ( V_25 -> V_26 ) {
while ( F_75 ( V_112 ) & ( 1 << 0 ) )
( void ) F_76 () ;
while ( F_75 ( V_112 ) & ( 1 << 1 ) )
( void ) F_77 () ;
return;
}
#endif
while ( F_75 ( V_113 ) & ( 1 << 0 ) )
( void ) F_78 () ;
while ( F_75 ( V_113 ) & ( 1 << 1 ) )
( void ) F_79 () ;
while ( F_75 ( V_113 ) & ( 1 << 2 ) )
( void ) F_80 () ;
while ( F_75 ( V_113 ) & ( 1 << 3 ) )
( void ) F_81 () ;
}
static void F_82 ( void * V_105 )
{
struct V_7 * V_29 = V_105 ;
struct V_24 * V_25 = V_29 -> type ;
#if F_42 ()
int V_114 = F_34 ( V_25 , V_115 ) ;
while ( V_114 -- ) {
F_74 ( V_25 ) ;
if ( V_25 -> V_26 )
F_83 ( 0 ) ;
else
F_84 ( 0 ) ;
}
F_85 ( & V_29 -> V_116 ) ;
while ( F_86 ( & V_29 -> V_116 ) )
F_74 ( V_25 ) ;
#else
int V_80 ;
int V_117 , V_118 ;
for ( V_80 = 0 ; V_80 < 5 ; V_80 ++ ) {
int V_119 , V_120 ;
F_40 ( V_121 , V_80 ) ;
V_119 = F_75 ( V_122 ) & 0xF ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ )
( void ) F_75 ( V_123 ) ;
F_21 ( ( F_75 ( V_122 ) & 0xF ) != 0 ) ;
}
V_117 = ( F_75 ( V_124 ) >> 10 ) & 0x3 ;
for ( V_80 = 0 ; V_80 < V_117 ; V_80 ++ )
( void ) F_75 ( V_125 ) ;
F_74 ( V_25 ) ;
V_118 = F_75 ( V_126 ) ;
for ( V_80 = 0 ; V_80 < V_118 ; V_80 ++ )
( void ) F_75 ( V_127 ) ;
F_21 ( F_75 ( V_126 ) != 0 ) ;
F_40 ( V_128 , 1 ) ;
for ( V_80 = 0 ; V_80 < 5 ; V_80 ++ ) {
F_40 ( V_121 , V_80 ) ;
F_40 ( V_122 , 0xc3000 ) ;
}
#endif
}
static void F_87 ( struct V_24 * V_25 )
{
if ( V_25 -> V_4 )
return;
F_22 ( V_25 , V_35 , 0 ) ;
F_22 ( V_25 , V_129 , 0 ) ;
F_22 ( V_25 , V_130 , 0 ) ;
#if ! F_42 ()
{
unsigned int V_17 = F_20 () ;
unsigned int V_9 = F_10 ( V_17 ) ;
unsigned int V_10 = F_11 ( V_17 ) ;
F_40 ( V_131 , ( V_9 << 18 ) | ( V_10 << 7 ) ) ;
}
F_40 ( V_132 , 0xf ) ;
F_40 ( V_133 , ( 1 << 0 ) ) ;
F_40 ( V_134 , ( 1 << 1 ) ) ;
F_40 ( V_135 , ( 1 << 2 ) ) ;
F_40 ( V_136 , ( 1 << 3 ) ) ;
F_40 ( V_137 , 0 ) ;
F_40 ( V_138 , 0 ) ;
F_40 ( V_121 , 0 ) ;
F_40 ( V_106 , 0 ) ;
#endif
}
void F_88 ( void )
{
F_87 ( & V_2 [ V_3 ] ) ;
#ifndef F_14
F_87 ( & V_2 [ V_5 ] ) ;
#endif
}
static void F_89 ( void * V_105 )
{
struct V_24 * V_25 = V_105 ;
#if F_42 ()
F_74 ( V_25 ) ;
#endif
F_87 ( V_25 ) ;
F_17 ( V_25 ) ;
}
static void F_90 ( struct V_7 * V_29 )
{
struct V_42 * V_103 ;
struct V_24 * V_25 ;
unsigned long V_60 ;
if ( V_29 == NULL )
return;
V_25 = V_29 -> type ;
V_29 -> V_49 = 1 ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
F_32 (task, &info->task_head,
thread.hardwall[hwt->index].list)
F_67 ( V_25 , V_103 ) ;
F_59 ( & V_25 -> V_47 , V_60 ) ;
if ( V_25 -> V_63 ) {
F_66 ( V_101
L_11 ,
V_25 -> V_50 , V_29 -> V_12 , V_29 -> V_14 ,
V_29 -> V_11 , V_29 -> V_13 ) ;
F_26 ( & V_29 -> V_15 , F_73 , V_25 , 1 ) ;
#if F_42 ()
F_91 ( & V_29 -> V_116 ,
F_63 ( & V_29 -> V_15 ) ) ;
F_26 ( & V_29 -> V_15 , F_82 , V_29 , 0 ) ;
#else
F_26 ( & V_29 -> V_15 , F_82 , V_29 , 1 ) ;
#endif
F_26 ( & V_29 -> V_15 , F_89 , V_25 , 1 ) ;
}
F_92 ( V_29 ) ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
F_21 ( ! F_93 ( & V_29 -> V_92 ) ) ;
F_69 ( & V_29 -> V_48 ) ;
F_59 ( & V_25 -> V_47 , V_60 ) ;
F_55 ( V_29 ) ;
}
static int F_94 ( struct V_139 * V_140 , void * V_141 )
{
struct V_7 * V_29 = V_140 -> V_142 ;
char V_143 [ 256 ] ;
int V_85 = F_95 ( V_143 , sizeof( V_143 ) , & V_29 -> V_15 ) ;
V_143 [ V_85 ++ ] = '\n' ;
F_96 ( V_140 , V_143 , V_85 ) ;
return 0 ;
}
static int F_97 ( struct V_144 * V_144 ,
struct V_145 * V_145 )
{
return F_98 ( V_145 , F_94 , F_99 ( V_144 ) ) ;
}
static void F_61 ( struct V_7 * V_29 )
{
char V_143 [ 64 ] ;
snprintf ( V_143 , sizeof( V_143 ) , L_12 , V_29 -> V_93 ) ;
F_100 ( V_143 , 0444 , V_29 -> type -> V_146 ,
& V_147 , V_29 ) ;
}
static void F_92 ( struct V_7 * V_29 )
{
char V_143 [ 64 ] ;
snprintf ( V_143 , sizeof( V_143 ) , L_12 , V_29 -> V_93 ) ;
F_101 ( V_143 , V_29 -> type -> V_146 ) ;
}
int F_102 ( struct V_139 * V_148 , struct V_149 * V_150 ,
struct V_62 * V_62 , struct V_42 * V_103 )
{
int V_80 ;
int V_151 = 0 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 ) {
struct V_7 * V_29 = V_103 -> V_57 . V_58 [ V_80 ] . V_29 ;
if ( V_29 )
F_103 ( V_148 , L_13 , V_29 -> type -> V_50 , V_29 -> V_93 ) ;
}
return V_151 ;
}
void F_104 ( struct V_152 * V_153 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; ++ V_80 ) {
struct V_24 * V_25 = & V_2 [ V_80 ] ;
if ( V_25 -> V_4 )
continue;
if ( V_154 == NULL )
V_154 = F_105 ( L_14 , V_153 ) ;
V_25 -> V_146 = F_105 ( V_25 -> V_50 , V_154 ) ;
}
}
static long F_106 ( struct V_145 * V_145 , unsigned int V_155 , unsigned long V_156 )
{
struct V_7 * V_29 = V_145 -> V_157 ;
int V_158 = F_107 ( V_145 -> V_159 -> V_160 ) ;
struct V_24 * V_25 ;
if ( F_108 ( V_155 ) != V_161 )
return - V_21 ;
F_109 ( V_81 != V_162 ) ;
F_109 ( V_81 !=
sizeof( V_2 ) / sizeof( V_2 [ 0 ] ) ) ;
if ( V_158 < 0 || V_158 >= V_81 )
return - V_21 ;
V_25 = & V_2 [ V_158 ] ;
F_110 ( V_29 && V_25 != V_29 -> type ) ;
switch ( F_111 ( V_155 ) ) {
case V_163 :
if ( V_25 -> V_4 )
return - V_164 ;
if ( V_29 != NULL )
return - V_165 ;
V_29 = F_47 ( V_25 , F_112 ( V_155 ) ,
( const unsigned char T_4 * ) V_156 ) ;
if ( F_113 ( V_29 ) )
return F_114 ( V_29 ) ;
V_145 -> V_157 = V_29 ;
return 0 ;
case V_166 :
return F_62 ( V_29 ) ;
case V_167 :
if ( V_82 -> V_57 . V_58 [ V_25 -> V_59 ] . V_29 != V_29 )
return - V_21 ;
return F_70 ( V_25 , V_82 ) ;
case V_168 :
return V_29 ? V_29 -> V_93 : - V_21 ;
default:
return - V_21 ;
}
}
static long F_115 ( struct V_145 * V_145 ,
unsigned int V_155 , unsigned long V_156 )
{
return F_106 ( V_145 , V_155 , ( unsigned long ) F_116 ( V_156 ) ) ;
}
static int F_117 ( struct V_145 * V_145 , T_5 V_169 )
{
struct V_7 * V_29 = V_145 -> V_157 ;
struct V_42 * V_103 , * V_170 ;
unsigned long V_60 ;
if ( V_29 ) {
struct V_24 * V_25 = V_29 -> type ;
F_57 ( & V_25 -> V_47 , V_60 ) ;
F_118 (task, tmp, &info->task_head,
thread.hardwall[hwt->index].list) {
if ( V_103 -> V_171 == V_169 || V_103 -> V_171 == NULL )
F_67 ( V_25 , V_103 ) ;
}
F_59 ( & V_25 -> V_47 , V_60 ) ;
}
return 0 ;
}
static int F_119 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
F_90 ( V_145 -> V_157 ) ;
return 0 ;
}
static int T_1 F_120 ( void )
{
int V_85 ;
T_6 V_172 ;
V_85 = F_121 ( & V_172 , 0 , V_81 , L_14 ) ;
if ( V_85 < 0 )
return V_85 ;
F_122 ( & V_173 , & V_174 ) ;
V_85 = F_123 ( & V_173 , V_172 , V_81 ) ;
if ( V_85 < 0 )
return V_85 ;
return 0 ;
}
