static bool F_1 ( void )
{
char V_1 [ 1024 ] ;
int V_2 ;
if ( V_3 == NULL )
return false ;
V_2 = F_2 ( V_3 , & V_4 ) ;
if ( V_2 != 0 ) {
F_3 ( L_1 ,
V_3 ) ;
return false ;
}
F_4 ( & V_4 , & V_4 , V_5 ) ;
if ( F_5 ( & V_4 ) ) {
F_3 ( L_2 ,
V_3 ) ;
return false ;
}
F_6 ( V_1 , sizeof( V_1 ) , & V_4 ) ;
F_7 ( L_3 , V_1 ) ;
return true ;
}
static void F_8 ( unsigned long V_6 , unsigned long * V_7 )
{
F_9 ( sizeof( V_8 ) != sizeof( unsigned long ) ) ;
F_10 ( V_6 , ( V_8 * ) V_7 ) ;
}
static bool F_11 ( bool V_9 )
{
int V_10 = V_9 ? V_11 : V_12 ;
const unsigned long V_13 = 128 ;
struct V_14 * V_15 ;
int V_16 ;
V_16 = sizeof( struct V_14 * * ) + V_13 ;
V_16 += ( V_9 ? V_17 : V_18 ) ;
V_15 = F_12 ( V_16 ) ;
if ( V_15 == NULL )
return false ;
F_13 ( V_15 , sizeof( struct V_14 * * ) ) ;
F_13 ( V_15 , - ( long ) V_15 -> V_19 & ( V_13 - 1 ) ) ;
* (struct V_14 * * ) ( V_15 -> V_19 - sizeof( struct V_14 * * ) ) = V_15 ;
F_14 () ;
F_15 ( & V_20 , V_10 ,
( void * ) F_16 ( V_15 -> V_19 ) ) ;
return true ;
}
static struct V_14 * F_17 ( void * V_21 )
{
struct V_14 * * V_22 = V_21 - sizeof( * V_22 ) ;
struct V_14 * V_15 = * V_22 ;
if ( V_15 -> V_19 != V_21 ) {
F_18 ( L_4 ,
V_21 , V_15 , V_15 -> V_19 ) ;
}
return V_15 ;
}
static void F_19 ( int V_10 )
{
for (; ; ) {
T_1 V_23 =
( T_1 ) F_20 ( & V_20 , V_10 ) ;
if ( V_23 == 0 )
break;
F_21 ( F_17 ( F_22 ( V_23 ) ) ) ;
}
}
static void F_23 ( void )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
while ( V_25 -> V_27 != 0 ) {
if ( ! F_11 ( true ) )
goto V_28;
V_25 -> V_27 -- ;
}
while ( V_25 -> V_29 != 0 ) {
if ( ! F_11 ( false ) )
goto V_28;
V_25 -> V_29 -- ;
}
return;
V_28:
F_25 ( L_5 , V_25 -> V_30 ) ;
}
static inline bool F_26 ( struct V_31 * V_32 , void * V_1 )
{
if ( V_32 == NULL || ! ( V_32 -> V_33 & V_34 ) )
return true ;
if ( ! ( V_32 -> V_33 & V_35 ) &&
! F_27 ( V_1 ) &&
F_28 ( V_32 -> V_36 , V_1 ) != 0 )
return true ;
return false ;
}
static void F_29 ( struct V_31 * V_32 , struct V_14 * V_15 ,
T_2 * V_37 , unsigned long V_16 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
F_31 ( V_15 , V_16 ) ;
V_15 -> V_40 = F_32 ( V_15 , V_32 ) ;
if ( V_37 -> V_41 && V_37 -> V_42 == 0xFFFF )
V_15 -> V_43 = V_44 ;
F_33 ( V_15 ) ;
F_8 ( 1 , & V_39 -> V_45 . V_46 ) ;
F_8 ( V_16 , & V_39 -> V_45 . V_47 ) ;
if ( V_37 -> V_48 == V_49 )
V_25 -> V_27 ++ ;
else
V_25 -> V_29 ++ ;
}
static bool F_34 ( T_2 * V_37 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_31 * V_32 = V_50 [ V_37 -> V_51 ] ;
T_3 V_52 ;
void * V_21 ;
void * V_1 ;
unsigned long V_16 ;
bool V_53 ;
if ( V_37 -> V_54 ) {
struct V_38 * V_39 = F_30 ( V_32 ) ;
F_8 ( 1 , & V_39 -> V_45 . V_55 ) ;
F_35 ( & V_25 -> V_56 , V_37 ) ;
if ( F_36 () )
F_7 ( L_6 ) ;
return false ;
}
V_52 = V_57 ? 0 : F_37 ( V_37 ) ;
V_21 = F_22 ( ( unsigned long ) ( long ) V_37 -> V_21 ) ;
V_1 = V_21 + V_52 ;
V_16 = V_37 -> V_58 - V_52 ;
V_21 -= V_59 ;
V_53 = F_26 ( V_32 , V_1 ) ;
if ( V_53 ) {
F_38 ( & V_25 -> V_56 , V_37 ) ;
} else {
struct V_14 * V_15 = F_17 ( V_21 ) ;
F_13 ( V_15 , V_59 + V_52 ) ;
F_29 ( V_32 , V_15 , V_37 , V_16 ) ;
}
F_35 ( & V_25 -> V_56 , V_37 ) ;
return ! V_53 ;
}
static int F_39 ( struct V_60 * V_61 , int V_62 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
unsigned int V_63 = 0 ;
T_2 * V_37 ;
int V_64 , V_65 ;
while ( ( V_65 = F_40 ( & V_25 -> V_56 , & V_37 ) ) > 0 ) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
if ( V_64 == V_66 )
goto V_67;
if ( F_34 ( V_37 + V_64 ) ) {
if ( ++ V_63 >= V_62 )
goto V_67;
}
}
}
F_41 ( & V_25 -> V_61 ) ;
F_42 ( & V_20 , V_25 -> V_56 . V_68 ) ;
if ( F_40 ( & V_25 -> V_56 , & V_37 ) > 0 )
F_43 ( & V_25 -> V_61 ) ;
V_67:
F_23 () ;
return V_63 ;
}
static T_4 F_44 ( int V_69 , void * V_70 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
F_43 ( & V_25 -> V_61 ) ;
return V_71 ;
}
static int F_45 ( T_5 * V_72 ,
struct V_73 * V_74 ,
int V_75 , bool V_76 )
{
int V_65 = 0 ;
while ( V_74 -> V_77 < V_74 -> V_78 ) {
unsigned int V_79 = V_74 -> V_77 % V_80 ;
struct V_81 * V_82 = & V_74 -> V_83 [ V_79 ] ;
if ( ! F_46 ( V_72 , V_82 -> V_84 ,
V_76 || V_65 == 0 ) )
break;
F_21 ( V_82 -> V_15 ) ;
V_74 -> V_77 ++ ;
if ( ++ V_65 == V_75 )
break;
}
return V_65 ;
}
static void F_47 ( T_5 * V_72 ,
struct V_73 * V_74 ,
T_6 V_84 , struct V_14 * V_15 )
{
int V_79 = V_74 -> V_78 % V_80 ;
V_74 -> V_83 [ V_79 ] . V_84 = V_84 ;
V_74 -> V_83 [ V_79 ] . V_15 = V_15 ;
V_74 -> V_78 ++ ;
}
static void F_48 ( struct V_31 * V_32 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
F_49 ( & V_25 -> V_85 [ V_39 -> V_86 ] . V_87 ,
F_50 ( 0 , V_88 * 1000UL ) ,
V_89 ) ;
}
static enum V_90 F_51 ( struct V_91 * V_92 )
{
struct V_93 * V_85 =
F_52 ( V_92 , struct V_93 , V_87 ) ;
F_53 ( V_85 -> V_32 , F_54 () ) ;
return V_94 ;
}
static void F_55 ( void )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
if ( ! V_25 -> V_95 ) {
F_49 ( & V_25 -> V_96 ,
F_50 ( 0 , V_97 * 1000UL ) ,
V_89 ) ;
V_25 -> V_95 = true ;
}
}
static enum V_90 F_56 ( struct V_91 * V_92 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
unsigned long V_98 ;
bool V_99 = false ;
int V_64 ;
F_57 ( V_98 ) ;
V_25 -> V_95 = false ;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ ) {
struct V_101 * V_102 = & V_103 [ V_64 ] ;
struct V_73 * V_74 = V_25 -> V_104 [ V_64 ] ;
if ( V_74 -> V_77 >= V_74 -> V_78 )
continue;
F_45 ( V_102 -> V_72 , V_74 , - 1 , true ) ;
V_99 = V_99 || ( V_74 -> V_77 < V_74 -> V_78 ) ;
}
if ( V_99 )
F_55 () ;
F_58 ( V_98 ) ;
return V_94 ;
}
static void F_59 ( void * V_105 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_31 * V_32 = V_105 ;
if ( ! V_25 -> V_106 )
return;
if ( V_32 != NULL ) {
if ( ! V_25 -> V_107 ) {
F_60 ( V_32 , & V_25 -> V_61 ,
F_39 , V_108 ) ;
V_25 -> V_107 = true ;
}
if ( ! V_25 -> V_109 ) {
F_61 ( & V_25 -> V_61 ) ;
V_25 -> V_109 = true ;
}
F_62 ( V_110 , 0 ) ;
} else {
F_63 ( V_110 ) ;
if ( V_25 -> V_109 ) {
F_64 ( & V_25 -> V_61 ) ;
V_25 -> V_109 = false ;
}
}
}
static int F_65 ( struct V_31 * V_32 )
{
static T_7 V_111 ;
bool V_112 = false ;
int V_51 ;
int V_2 ;
int V_113 ;
F_66 ( & V_111 , & V_20 ) ;
for ( V_51 = 0 ; V_51 < V_100 ; V_51 ++ ) {
if ( V_50 [ V_51 ] == NULL )
continue;
if ( ! V_112 ) {
V_112 = true ;
F_67 ( & V_111 , V_114 ,
V_115 , NULL ) ;
F_68 ( & V_111 , V_59 ) ;
}
F_69 ( & V_111 , V_51 ) ;
}
V_2 = F_70 ( & V_111 ) ;
if ( V_2 != 0 ) {
F_71 ( V_32 , L_7 , V_2 ) ;
return - V_116 ;
}
F_72 (cpu)
F_73 ( V_113 , F_59 ,
( V_112 ? V_32 : NULL ) , 1 ) ;
if ( V_112 )
F_74 ( 0 , - 1 ) ;
return 0 ;
}
static int F_75 ( struct V_31 * V_32 , int V_117 )
{
T_8 V_118 = F_76 ((pte_t) { 0 }, PAGE_HOME_HASH) ;
int V_2 ;
V_119 =
F_77 ( F_78 ( V_117 ) ,
64 * 1024 ) ;
V_2 = F_79 ( & V_20 , 2 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_8 ,
V_2 ) ;
return V_2 ;
}
V_11 = V_2 ;
V_12 = V_2 + 1 ;
V_120 =
F_81 ( V_119 , V_121 ) ;
if ( V_120 == NULL ) {
F_80 ( V_32 ,
L_9 ,
V_119 ) ;
return - V_122 ;
}
V_2 = F_82 ( & V_20 , V_11 ,
V_49 ,
V_120 ,
V_119 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_10 , V_2 ) ;
return V_2 ;
}
V_2 = F_83 ( & V_20 , V_11 ,
V_118 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 ,
L_11 ,
V_2 ) ;
return V_2 ;
}
V_123 =
F_81 ( V_119 , V_121 ) ;
if ( V_123 == NULL ) {
F_80 ( V_32 ,
L_9 ,
V_119 ) ;
return - V_122 ;
}
V_2 = F_82 ( & V_20 , V_12 ,
V_124 ,
V_123 ,
V_119 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_12 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_83 ( & V_20 , V_12 ,
V_118 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 ,
L_11 ,
V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_84 ( struct V_31 * V_32 ,
int V_113 , int V_68 )
{
struct V_24 * V_25 = & F_85 ( V_26 , V_113 ) ;
int V_125 , V_64 , V_2 ;
struct V_126 * V_126 ;
void * V_23 ;
V_125 = F_86 ( V_127 ) ;
V_126 = F_87 ( V_121 , V_125 , V_113 ) ;
if ( V_126 == NULL ) {
F_80 ( V_32 , L_13 ,
V_127 ) ;
return - V_122 ;
}
V_23 = F_88 ( F_89 ( V_126 ) ) ;
memset ( V_23 , 0 , V_127 ) ;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ )
V_25 -> V_104 [ V_64 ] =
V_23 + V_64 * sizeof( struct V_73 ) ;
if ( F_90 ( V_113 , V_4 ) ) {
V_125 = F_86 ( V_128 ) ;
V_126 = F_87 ( V_121 , V_125 , V_113 ) ;
if ( V_126 == NULL ) {
F_80 ( V_32 ,
L_14 ,
V_128 ) ;
return - V_122 ;
}
V_23 = F_88 ( F_89 ( V_126 ) ) ;
V_2 = F_91 ( & V_25 -> V_56 , & V_20 , V_68 ++ ,
V_23 , V_128 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 ,
L_15 , V_2 ) ;
return V_2 ;
}
V_25 -> V_106 = true ;
}
return V_68 ;
}
static int F_92 ( struct V_31 * V_32 ,
int V_68 , int V_129 )
{
int V_130 , V_2 ;
V_2 = F_93 ( & V_20 , 1 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_16 ,
V_2 ) ;
return V_2 ;
}
V_130 = V_2 ;
if ( V_129 > 4 )
V_115 = 256 ;
else if ( V_129 > 1 )
V_115 = 16 ;
V_2 = F_94 ( & V_20 , V_115 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_17 , V_2 ) ;
return V_2 ;
}
V_114 = V_2 ;
V_2 = F_95 (
& V_20 , V_130 , V_68 , V_129 ,
V_114 , V_115 ,
V_131 ) ;
if ( V_2 != 0 ) {
F_80 (
V_32 ,
L_18 ,
V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_96 ( struct V_31 * V_32 )
{
int V_113 , V_2 ;
V_2 = F_97 () ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_19 , V_2 ) ;
return V_2 ;
}
V_110 = V_2 ;
F_98 ( V_110 , V_132 ) ;
V_2 = F_99 ( V_110 , F_44 ,
0 , NULL , NULL ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_20 , V_2 ) ;
F_100 ( V_110 ) ;
V_110 = - 1 ;
return V_2 ;
}
F_72 (cpu) {
struct V_24 * V_25 = & F_85 ( V_26 , V_113 ) ;
if ( V_25 -> V_106 ) {
F_101 (
& V_20 , F_102 ( V_113 ) , F_103 ( V_113 ) ,
1 , V_110 , V_25 -> V_56 . V_68 ) ;
}
}
return 0 ;
}
static void F_104 ( void )
{
int V_113 ;
if ( V_11 >= 0 )
F_19 ( V_11 ) ;
if ( V_12 >= 0 )
F_19 ( V_12 ) ;
F_105 ( & V_20 ) ;
F_72 (cpu) {
struct V_24 * V_25 = & F_85 ( V_26 , V_113 ) ;
F_106 ( ( unsigned long ) ( V_25 -> V_104 [ 0 ] ) ,
F_86 ( V_127 ) ) ;
V_25 -> V_104 [ 0 ] = NULL ;
F_106 ( ( unsigned long ) ( V_25 -> V_56 . V_133 ) ,
F_86 ( V_128 ) ) ;
V_25 -> V_56 . V_133 = NULL ;
}
if ( V_120 )
F_107 ( V_120 , V_119 ) ;
if ( V_123 )
F_107 ( V_123 , V_119 ) ;
V_120 = NULL ;
V_123 = NULL ;
V_12 = - 1 ;
V_11 = - 1 ;
V_114 = - 1 ;
}
static int F_108 ( struct V_31 * V_32 )
{
int V_64 , V_117 , V_2 ;
int V_113 ;
int V_134 , V_68 ;
int V_129 = F_109 ( V_4 ) ;
if ( ! V_135 ) {
F_80 ( V_32 , L_21 ) ;
return - V_116 ;
}
V_2 = F_110 ( & V_20 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_22 , V_2 ) ;
return - V_116 ;
}
V_117 =
V_129 * ( V_136 + V_66 ) ;
V_2 = F_75 ( V_32 , V_117 ) ;
if ( V_2 != 0 )
goto V_137;
V_2 = - V_122 ;
for ( V_64 = 0 ; V_64 < V_117 ; V_64 ++ ) {
if ( ! F_11 ( true ) ) {
F_80 ( V_32 , L_23 ) ;
goto V_137;
}
}
for ( V_64 = 0 ; V_64 < V_117 ; V_64 ++ ) {
if ( ! F_11 ( false ) ) {
F_80 ( V_32 , L_23 ) ;
goto V_137;
}
}
V_2 = F_111 ( & V_20 , V_129 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_24 ,
V_2 ) ;
goto V_137;
}
V_134 = V_2 ;
V_68 = V_134 ;
F_72 (cpu) {
V_2 = F_84 ( V_32 , V_113 , V_68 ) ;
if ( V_2 < 0 )
goto V_137;
V_68 = V_2 ;
}
V_2 = F_92 ( V_32 , V_134 , V_129 ) ;
if ( V_2 != 0 )
goto V_137;
V_2 = F_96 ( V_32 ) ;
if ( V_2 != 0 )
goto V_137;
return 0 ;
V_137:
F_104 () ;
return V_2 ;
}
static int F_112 ( struct V_31 * V_32 , int V_86 )
{
struct V_126 * V_138 , * V_139 , * V_140 ;
T_9 * V_141 ;
T_5 * V_72 ;
unsigned char * V_142 ;
int V_143 , V_144 , V_145 ;
T_10 V_146 ;
int V_147 ;
int V_2 = - V_122 ;
if ( V_103 [ V_86 ] . V_72 != NULL )
return 0 ;
V_143 = F_86 ( V_148 * V_149 ) ;
V_138 = F_113 ( V_121 , V_143 ) ;
if ( V_138 == NULL ) {
F_71 ( V_32 ,
L_25 ,
V_150 << V_143 ) ;
goto V_137;
}
V_142 = F_88 ( F_89 ( V_138 ) ) ;
V_146 = V_148 * sizeof( * V_141 ) ;
V_144 = F_86 ( V_146 ) ;
V_139 = F_113 ( V_121 , V_144 ) ;
if ( V_139 == NULL ) {
F_71 ( V_32 ,
L_26 ,
V_146 ) ;
goto V_151;
}
V_141 = F_88 ( F_89 ( V_139 ) ) ;
V_145 = F_86 ( sizeof( * V_72 ) ) ;
V_140 = F_113 ( V_121 , V_145 ) ;
if ( V_140 == NULL ) {
F_71 ( V_32 ,
L_27 ,
V_150 << V_145 ) ;
goto V_152;
}
V_72 = F_88 ( F_89 ( V_140 ) ) ;
V_2 = F_114 ( & V_20 , 1 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_71 ( V_32 , L_28 ,
V_2 ) ;
goto V_153;
}
V_147 = V_2 ;
V_2 = F_115 ( V_72 , & V_20 , V_147 , V_86 ,
V_141 , V_146 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_29 , V_2 ) ;
goto V_153;
}
V_103 [ V_86 ] . V_72 = V_72 ;
V_103 [ V_86 ] . V_142 = V_142 ;
return 0 ;
V_153:
F_116 ( V_140 , V_145 ) ;
V_152:
F_116 ( V_139 , V_144 ) ;
V_151:
F_116 ( V_138 , V_143 ) ;
V_137:
return V_2 ;
}
static int F_117 ( struct V_31 * V_32 , T_11 * V_154 ,
const char * V_155 )
{
int V_2 = F_118 ( V_154 , & V_20 , V_155 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_30 , V_155 ) ;
return V_2 ;
}
V_2 = F_119 ( V_154 ) ;
if ( V_2 < 0 || V_2 >= V_100 ) {
F_80 ( V_32 , L_31 , V_2 ) ;
F_120 ( V_154 ) ;
return - V_156 ;
}
return V_2 ;
}
static int F_121 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_113 , V_2 ;
F_122 ( & V_157 ) ;
if ( V_110 < 0 ) {
V_2 = F_108 ( V_32 ) ;
if ( V_2 != 0 )
goto V_137;
}
if ( F_123 ( ( V_158 != NULL ) &&
! strcmp ( V_32 -> V_159 , V_158 ) ) ) {
V_2 = F_117 ( V_32 , & V_39 -> V_154 , L_32 ) ;
if ( V_2 < 0 )
goto V_137;
V_39 -> V_51 = V_2 ;
V_2 = F_117 ( V_32 , & V_39 -> V_160 , L_33 ) ;
if ( V_2 < 0 )
goto V_137;
V_39 -> V_161 = V_2 ;
V_39 -> V_86 = V_2 ;
} else {
V_2 = F_117 ( V_32 , & V_39 -> V_154 , V_32 -> V_159 ) ;
if ( V_2 < 0 )
goto V_137;
V_39 -> V_51 = V_2 ;
V_39 -> V_86 = V_2 ;
}
V_2 = F_112 ( V_32 , V_39 -> V_86 ) ;
if ( V_2 != 0 )
goto V_137;
V_50 [ V_39 -> V_51 ] = V_32 ;
V_2 = F_65 ( V_32 ) ;
if ( V_2 != 0 )
goto V_137;
F_124 ( & V_157 ) ;
F_72 (cpu) {
struct V_24 * V_25 = & F_85 ( V_26 , V_113 ) ;
struct V_93 * V_85 =
& V_25 -> V_85 [ V_39 -> V_86 ] ;
F_125 ( & V_85 -> V_87 , V_162 ,
V_163 ) ;
V_85 -> V_87 . V_164 = F_51 ;
V_85 -> V_32 = V_32 ;
}
F_72 (cpu)
F_126 ( V_32 , V_113 ) ;
F_127 ( V_32 ) ;
return 0 ;
V_137:
if ( V_39 -> V_161 >= 0 ) {
if ( F_120 ( & V_39 -> V_160 ) != 0 )
F_71 ( V_32 , L_34 ) ;
V_39 -> V_161 = - 1 ;
}
if ( V_39 -> V_51 >= 0 ) {
if ( F_120 ( & V_39 -> V_154 ) != 0 )
F_71 ( V_32 , L_35 ) ;
V_39 -> V_51 = - 1 ;
}
V_39 -> V_86 = - 1 ;
V_50 [ V_39 -> V_51 ] = NULL ;
F_124 ( & V_157 ) ;
return ( V_2 > - 512 ) ? V_2 : - V_116 ;
}
static int F_128 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_113 ;
F_72 (cpu) {
struct V_24 * V_25 = & F_85 ( V_26 , V_113 ) ;
struct V_93 * V_85 =
& V_25 -> V_85 [ V_39 -> V_86 ] ;
F_129 ( & V_85 -> V_87 ) ;
F_130 ( V_32 , V_113 ) ;
}
F_122 ( & V_157 ) ;
V_50 [ V_39 -> V_51 ] = NULL ;
( void ) F_65 ( V_32 ) ;
if ( V_39 -> V_161 >= 0 ) {
if ( F_120 ( & V_39 -> V_160 ) != 0 )
F_71 ( V_32 , L_34 ) ;
V_39 -> V_161 = - 1 ;
}
if ( V_39 -> V_51 >= 0 ) {
if ( F_120 ( & V_39 -> V_154 ) != 0 )
F_71 ( V_32 , L_35 ) ;
V_39 -> V_51 = - 1 ;
}
V_39 -> V_86 = - 1 ;
F_124 ( & V_157 ) ;
return 0 ;
}
static inline void * F_131 ( T_12 * V_165 )
{
unsigned long V_166 = F_89 ( F_132 ( V_165 ) ) ;
return F_88 ( V_166 ) + V_165 -> V_167 ;
}
static T_13 F_133 ( struct V_31 * V_32 ,
struct V_73 * V_74 ,
T_5 * V_72 ,
int V_168 )
{
if ( V_74 -> V_78 - V_74 -> V_77 < V_80 - 1 ||
F_45 ( V_72 , V_74 , 32 , false ) != 0 ) {
T_13 V_169 = F_134 ( V_72 , V_168 ) ;
if ( V_169 >= 0 )
return V_169 ;
F_45 ( V_72 , V_74 , V_80 , false ) ;
V_169 = F_134 ( V_72 , V_168 ) ;
if ( V_169 >= 0 )
return V_169 ;
}
F_130 ( V_32 , F_54 () ) ;
F_48 ( V_32 ) ;
return - 1 ;
}
static int F_135 ( struct V_14 * V_15 )
{
struct V_170 * V_171 = F_136 ( V_15 ) ;
unsigned int V_172 = V_15 -> V_172 ;
unsigned int V_173 = V_171 -> V_174 ;
long V_175 = - 1 ;
long V_176 = - 1 ;
long V_177 = - 1 ;
long V_65 ;
int V_168 = 0 ;
int V_178 ;
for ( V_178 = 0 ; V_178 < V_171 -> V_179 ; V_178 ++ ) {
unsigned int V_180 = 0 ;
for ( V_168 ++ ; V_180 < V_173 ; V_168 ++ ) {
while ( V_177 >= V_176 ) {
V_175 ++ ;
V_176 = V_171 -> V_181 [ V_175 ] . V_48 ;
V_177 = 0 ;
}
V_65 = V_173 - V_180 ;
if ( V_65 > V_176 - V_177 )
V_65 = V_176 - V_177 ;
V_177 += V_65 ;
V_180 += V_65 ;
}
V_172 -= V_173 ;
if ( V_172 < V_173 )
V_173 = V_172 ;
}
return V_168 ;
}
static void F_137 ( struct V_14 * V_15 , unsigned char * V_142 ,
T_13 V_169 )
{
struct V_170 * V_171 = F_136 ( V_15 ) ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
unsigned int V_172 = V_15 -> V_172 ;
unsigned char * V_19 = V_15 -> V_19 ;
unsigned int V_186 , V_187 , V_188 , V_173 ;
unsigned int V_189 , V_190 , V_191 , V_192 ;
long V_175 = - 1 ;
long V_176 = - 1 ;
long V_177 = - 1 ;
long V_65 ;
int V_178 ;
V_183 = F_138 ( V_15 ) ;
V_185 = F_139 ( V_15 ) ;
V_186 = F_140 ( V_15 ) ;
V_187 = F_141 ( V_15 ) ;
V_188 = V_187 + F_142 ( V_15 ) ;
V_173 = V_171 -> V_174 ;
V_189 = ( ( 0xFFFF - V_183 -> V_193 ) +
( 0xFFFF - V_183 -> V_194 ) +
( 0xFFFF - V_183 -> V_191 ) ) ;
V_190 = V_185 -> V_193 + ( 0xFFFF ^ F_143 ( V_15 -> V_16 ) ) ;
V_191 = F_144 ( V_183 -> V_191 ) ;
V_192 = F_145 ( V_185 -> V_192 ) ;
for ( V_178 = 0 ; V_178 < V_171 -> V_179 ; V_178 ++ ) {
unsigned char * V_1 ;
unsigned int V_180 = 0 ;
V_1 = V_142 + ( V_169 % V_148 ) * V_149 +
V_59 ;
memcpy ( V_1 , V_19 , V_188 ) ;
V_183 = (struct V_182 * ) ( V_1 + V_186 ) ;
V_183 -> V_194 = F_143 ( V_188 + V_173 - V_186 ) ;
V_183 -> V_191 = F_143 ( V_191 ) ;
V_183 -> V_193 = F_146 ( V_189 + V_183 -> V_194 +
V_183 -> V_191 ) ^ 0xffff ;
V_185 = (struct V_184 * ) ( V_1 + V_187 ) ;
V_185 -> V_192 = F_147 ( V_192 ) ;
V_185 -> V_193 = F_146 ( V_190 + F_143 ( V_188 + V_173 ) ) ;
if ( V_178 != V_171 -> V_179 - 1 ) {
V_185 -> V_195 = 0 ;
V_185 -> V_196 = 0 ;
}
V_169 ++ ;
while ( V_180 < V_173 ) {
while ( V_177 >= V_176 ) {
V_175 ++ ;
V_176 = V_171 -> V_181 [ V_175 ] . V_48 ;
V_177 = 0 ;
}
V_65 = V_173 - V_180 ;
if ( V_65 > V_176 - V_177 )
V_65 = V_176 - V_177 ;
V_177 += V_65 ;
V_180 += V_65 ;
V_169 ++ ;
}
V_191 ++ ;
V_192 += V_173 ;
V_172 -= V_173 ;
if ( V_172 < V_173 )
V_173 = V_172 ;
}
F_14 () ;
}
static void F_148 ( struct V_31 * V_32 , T_5 * V_72 ,
struct V_14 * V_15 , unsigned char * V_142 , T_13 V_169 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
struct V_170 * V_171 = F_136 ( V_15 ) ;
unsigned int V_172 = V_15 -> V_172 ;
unsigned int V_173 = V_171 -> V_174 ;
T_9 V_197 = { { 0 } } ;
T_9 V_198 = { { 0 } } ;
long V_175 = - 1 ;
long V_176 = - 1 ;
long V_177 = - 1 ;
long V_65 ;
unsigned long V_199 = 0 , V_200 = 0 ;
unsigned int V_201 , V_188 ;
int V_178 ;
V_201 = F_149 ( V_15 ) ;
V_188 = F_141 ( V_15 ) + F_142 ( V_15 ) ;
V_197 . V_202 = 1 ;
V_197 . V_201 = V_201 ;
V_197 . V_203 = V_201 + V_15 -> V_204 ;
V_197 . V_205 = V_188 ;
V_197 . V_206 = V_12 ;
V_198 . V_206 = V_12 ;
for ( V_178 = 0 ; V_178 < V_171 -> V_179 ; V_178 ++ ) {
void * V_21 ;
unsigned char * V_1 ;
unsigned int V_180 = 0 ;
V_1 = V_142 + ( V_169 % V_148 ) * V_149 +
V_59 ;
V_197 . V_21 = F_16 ( V_1 ) ;
F_150 ( V_72 , V_197 , V_169 ) ;
V_169 ++ ;
while ( V_180 < V_173 ) {
while ( V_177 >= V_176 ) {
V_175 ++ ;
V_176 = V_171 -> V_181 [ V_175 ] . V_48 ;
V_177 = 0 ;
}
V_21 = F_131 ( & V_171 -> V_181 [ V_175 ] ) + V_177 ;
V_65 = V_173 - V_180 ;
if ( V_65 > V_176 - V_177 )
V_65 = V_176 - V_177 ;
V_177 += V_65 ;
V_180 += V_65 ;
V_198 . V_21 = F_16 ( V_21 ) ;
V_198 . V_205 = V_65 ;
V_198 . V_207 = ! ( V_180 < V_173 ) ;
F_150 ( V_72 , V_198 , V_169 ) ;
V_169 ++ ;
}
V_199 ++ ;
V_200 += V_188 + V_173 ;
V_172 -= V_173 ;
if ( V_172 < V_173 )
V_173 = V_172 ;
}
F_8 ( V_199 , & V_39 -> V_45 . V_199 ) ;
F_8 ( V_200 , & V_39 -> V_45 . V_200 ) ;
}
static int F_151 ( struct V_14 * V_15 , struct V_31 * V_32 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_51 = V_39 -> V_86 ;
struct V_101 * V_102 = & V_103 [ V_51 ] ;
struct V_73 * V_74 = V_25 -> V_104 [ V_51 ] ;
T_5 * V_72 = V_102 -> V_72 ;
unsigned long V_98 ;
int V_168 ;
T_13 V_169 ;
V_168 = F_135 ( V_15 ) ;
F_57 ( V_98 ) ;
V_169 = F_133 ( V_32 , V_74 , V_72 , V_168 ) ;
if ( V_169 < 0 ) {
F_58 ( V_98 ) ;
return V_208 ;
}
F_137 ( V_15 , V_102 -> V_142 , V_169 ) ;
F_148 ( V_32 , V_72 , V_15 , V_102 -> V_142 , V_169 ) ;
F_47 ( V_72 , V_74 , V_169 + V_168 - 1 , V_15 ) ;
F_58 ( V_98 ) ;
F_55 () ;
return V_209 ;
}
static unsigned int F_152 ( struct V_210 * V_181 ,
struct V_14 * V_15 ,
void * V_211 , unsigned int V_212 )
{
unsigned int V_64 , V_65 = 0 ;
struct V_170 * V_171 = F_136 ( V_15 ) ;
if ( V_212 != 0 ) {
V_181 [ V_65 ] . V_1 = V_211 ;
V_181 [ V_65 ++ ] . V_213 = V_212 ;
}
for ( V_64 = 0 ; V_64 < V_171 -> V_214 ; V_64 ++ ) {
T_12 * V_165 = & V_171 -> V_181 [ V_64 ] ;
V_181 [ V_65 ] . V_1 = F_131 ( V_165 ) ;
V_181 [ V_65 ++ ] . V_213 = F_153 ( V_165 ) ;
}
return V_65 ;
}
static int F_154 ( struct V_14 * V_15 , struct V_31 * V_32 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
struct V_101 * V_102 = & V_103 [ V_39 -> V_86 ] ;
T_5 * V_72 = V_102 -> V_72 ;
struct V_73 * V_74 =
V_25 -> V_104 [ V_39 -> V_86 ] ;
unsigned int V_16 = V_15 -> V_16 ;
unsigned char * V_19 = V_15 -> V_19 ;
unsigned int V_168 ;
struct V_210 V_181 [ V_215 ] ;
T_9 V_141 [ V_215 ] ;
unsigned long V_98 ;
T_9 V_216 = { { 0 } } ;
unsigned int V_64 ;
T_13 V_169 ;
if ( F_155 ( V_15 ) )
return F_151 ( V_15 , V_32 ) ;
V_168 = F_152 ( V_181 , V_15 , V_19 , F_156 ( V_15 ) ) ;
V_216 . V_206 = V_12 ;
for ( V_64 = 0 ; V_64 < V_168 ; V_64 ++ ) {
V_216 . V_205 = V_181 [ V_64 ] . V_213 ;
V_216 . V_21 = F_16 ( V_181 [ V_64 ] . V_1 ) ;
V_141 [ V_64 ] = V_216 ;
}
V_141 [ V_168 - 1 ] . V_207 = 1 ;
if ( V_15 -> V_43 == V_217 ) {
unsigned int V_201 = F_149 ( V_15 ) ;
V_141 [ 0 ] . V_202 = 1 ;
V_141 [ 0 ] . V_201 = V_201 ;
V_141 [ 0 ] . V_203 = V_201 + V_15 -> V_204 ;
}
F_57 ( V_98 ) ;
V_169 = F_133 ( V_32 , V_74 , V_72 , V_168 ) ;
if ( V_169 < 0 ) {
F_58 ( V_98 ) ;
return V_208 ;
}
for ( V_64 = 0 ; V_64 < V_168 ; V_64 ++ )
F_150 ( V_72 , V_141 [ V_64 ] , V_169 ++ ) ;
F_47 ( V_72 , V_74 , V_169 - 1 , V_15 ) ;
F_8 ( 1 , & V_39 -> V_45 . V_199 ) ;
F_8 ( F_157 (unsigned int, len, ETH_ZLEN) ,
& V_39 -> V_45 . V_200 ) ;
F_58 ( V_98 ) ;
F_55 () ;
return V_209 ;
}
static T_14 F_158 ( struct V_31 * V_32 , struct V_14 * V_15 )
{
return F_54 () ;
}
static void F_159 ( struct V_31 * V_32 )
{
int V_113 ;
F_72 (cpu)
F_53 ( V_32 , V_113 ) ;
}
static int F_160 ( struct V_31 * V_32 , struct V_218 * V_219 , int V_220 )
{
return - V_221 ;
}
static struct V_222 * F_161 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
return & V_39 -> V_45 ;
}
static int F_162 ( struct V_31 * V_32 , int V_223 )
{
if ( ( V_223 < 68 ) || ( V_223 > 1500 ) )
return - V_156 ;
V_32 -> V_224 = V_223 ;
return 0 ;
}
static int F_163 ( struct V_31 * V_32 , void * V_225 )
{
struct V_226 * V_23 = V_225 ;
if ( ! F_164 ( V_23 -> V_227 ) )
return - V_156 ;
memcpy ( V_32 -> V_36 , V_23 -> V_227 , V_32 -> V_228 ) ;
return 0 ;
}
static void F_165 ( struct V_31 * V_32 )
{
F_63 ( V_110 ) ;
F_44 ( V_110 , NULL ) ;
F_62 ( V_110 , 0 ) ;
}
static void F_166 ( struct V_31 * V_32 )
{
F_167 ( V_32 ) ;
V_32 -> V_229 = & V_230 ;
V_32 -> V_231 = V_232 ;
V_32 -> V_233 |= V_234 ;
V_32 -> V_233 |= V_235 ;
V_32 -> V_233 |= V_236 ;
V_32 -> V_233 |= V_237 ;
V_32 -> V_224 = 1500 ;
}
static void F_168 ( const char * V_159 , const T_3 * V_238 )
{
int V_239 ;
int V_64 ;
int V_240 = 0 ;
struct V_31 * V_32 ;
struct V_38 * V_39 ;
if ( strncmp ( V_159 , L_36 , 4 ) == 0 )
return;
V_32 = F_169 ( sizeof( * V_39 ) , V_159 , F_166 ,
V_241 , 1 ) ;
if ( ! V_32 ) {
F_170 ( L_37 , V_159 ) ;
return;
}
V_39 = F_30 ( V_32 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_32 = V_32 ;
V_39 -> V_51 = - 1 ;
V_39 -> V_161 = - 1 ;
V_39 -> V_86 = - 1 ;
for ( V_64 = 0 ; V_64 < 6 ; V_64 ++ )
V_240 |= V_238 [ V_64 ] ;
if ( V_240 ) {
memcpy ( V_32 -> V_36 , V_238 , 6 ) ;
V_32 -> V_228 = 6 ;
} else {
F_171 ( V_32 -> V_36 ) ;
}
V_239 = F_172 ( V_32 ) ;
if ( V_239 ) {
F_80 ( V_32 , L_38 , V_239 ) ;
F_173 ( V_32 ) ;
return;
}
}
static void F_174 ( void * V_70 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
int V_30 = F_54 () ;
V_25 -> V_106 = false ;
V_25 -> V_30 = V_30 ;
F_125 ( & V_25 -> V_96 , V_162 , V_163 ) ;
V_25 -> V_96 . V_164 = F_56 ;
}
static int T_15 F_175 ( void )
{
int V_64 ;
char V_159 [ V_242 ] ;
T_3 V_238 [ 6 ] ;
F_7 ( L_39 ) ;
F_176 ( & V_157 ) ;
F_177 ( F_174 , NULL , 1 ) ;
for ( V_64 = 0 ; F_178 ( V_64 , V_159 , V_238 ) >= 0 ; V_64 ++ )
F_168 ( V_159 , V_238 ) ;
if ( ! F_1 () )
V_4 = * V_243 ;
return 0 ;
}
