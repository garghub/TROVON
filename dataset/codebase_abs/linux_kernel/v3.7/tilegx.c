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
static void F_48 ( struct V_31 * V_32 ,
int V_85 )
{
struct V_24 * V_25 = & F_49 ( V_26 , V_85 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
struct V_86 * V_87 = & V_25 -> V_87 [ V_39 -> V_88 ] ;
F_50 ( & V_87 -> V_89 ,
F_51 ( 0 , V_90 * 1000UL ) ,
V_91 ) ;
}
static enum V_92 F_52 ( struct V_93 * V_94 )
{
struct V_86 * V_87 =
F_53 ( V_94 , struct V_86 , V_89 ) ;
F_54 ( V_87 -> V_32 , V_87 -> V_85 ) ;
return V_95 ;
}
static void F_55 ( void )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
if ( ! V_25 -> V_96 ) {
F_50 ( & V_25 -> V_97 ,
F_51 ( 0 , V_98 * 1000UL ) ,
V_91 ) ;
V_25 -> V_96 = true ;
}
}
static enum V_92 F_56 ( struct V_93 * V_94 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
unsigned long V_99 ;
bool V_100 = false ;
int V_64 ;
F_57 ( V_99 ) ;
V_25 -> V_96 = false ;
for ( V_64 = 0 ; V_64 < V_101 ; V_64 ++ ) {
struct V_102 * V_103 = & V_104 [ V_64 ] ;
struct V_73 * V_74 = V_25 -> V_105 [ V_64 ] ;
if ( V_74 -> V_77 >= V_74 -> V_78 )
continue;
F_45 ( V_103 -> V_72 , V_74 , - 1 , true ) ;
V_100 = V_100 || ( V_74 -> V_77 < V_74 -> V_78 ) ;
}
if ( V_100 )
F_55 () ;
F_58 ( V_99 ) ;
return V_95 ;
}
static void F_59 ( void * V_106 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_31 * V_32 = V_106 ;
if ( ! V_25 -> V_107 )
return;
if ( V_32 != NULL ) {
if ( ! V_25 -> V_108 ) {
F_60 ( V_32 , & V_25 -> V_61 ,
F_39 , V_109 ) ;
V_25 -> V_108 = true ;
}
if ( ! V_25 -> V_110 ) {
F_61 ( & V_25 -> V_61 ) ;
V_25 -> V_110 = true ;
}
F_62 ( V_111 , 0 ) ;
} else {
F_63 ( V_111 ) ;
if ( V_25 -> V_110 ) {
F_64 ( & V_25 -> V_61 ) ;
V_25 -> V_110 = false ;
}
}
}
static int F_65 ( struct V_31 * V_32 )
{
static T_7 V_112 ;
bool V_113 = false ;
int V_51 ;
int V_2 ;
int V_114 ;
F_66 ( & V_112 , & V_20 ) ;
for ( V_51 = 0 ; V_51 < V_101 ; V_51 ++ ) {
if ( V_50 [ V_51 ] == NULL )
continue;
if ( ! V_113 ) {
V_113 = true ;
F_67 ( & V_112 , V_115 ,
V_116 , NULL ) ;
F_68 ( & V_112 , V_59 ) ;
}
F_69 ( & V_112 , V_51 ) ;
}
V_2 = F_70 ( & V_112 ) ;
if ( V_2 != 0 ) {
F_71 ( V_32 , L_7 , V_2 ) ;
return - V_117 ;
}
F_72 (cpu)
F_73 ( V_114 , F_59 ,
( V_113 ? V_32 : NULL ) , 1 ) ;
if ( V_113 )
F_74 ( 0 , - 1 ) ;
return 0 ;
}
static int F_75 ( struct V_31 * V_32 , int V_118 )
{
T_8 V_119 = F_76 ((pte_t) { 0 }, PAGE_HOME_HASH) ;
int V_2 ;
V_120 =
F_77 ( F_78 ( V_118 ) ,
64 * 1024 ) ;
V_2 = F_79 ( & V_20 , 2 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_8 ,
V_2 ) ;
return V_2 ;
}
V_11 = V_2 ;
V_12 = V_2 + 1 ;
V_121 =
F_81 ( V_120 , V_122 ) ;
if ( V_121 == NULL ) {
F_80 ( V_32 ,
L_9 ,
V_120 ) ;
return - V_123 ;
}
V_2 = F_82 ( & V_20 , V_11 ,
V_49 ,
V_121 ,
V_120 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_10 , V_2 ) ;
return V_2 ;
}
V_2 = F_83 ( & V_20 , V_11 ,
V_119 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 ,
L_11 ,
V_2 ) ;
return V_2 ;
}
V_124 =
F_81 ( V_120 , V_122 ) ;
if ( V_124 == NULL ) {
F_80 ( V_32 ,
L_9 ,
V_120 ) ;
return - V_123 ;
}
V_2 = F_82 ( & V_20 , V_12 ,
V_125 ,
V_124 ,
V_120 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_12 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_83 ( & V_20 , V_12 ,
V_119 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 ,
L_11 ,
V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_84 ( struct V_31 * V_32 ,
int V_114 , int V_68 )
{
struct V_24 * V_25 = & F_49 ( V_26 , V_114 ) ;
int V_126 , V_64 , V_2 ;
struct V_127 * V_127 ;
void * V_23 ;
V_126 = F_85 ( V_128 ) ;
V_127 = F_86 ( V_122 , V_126 , V_114 ) ;
if ( V_127 == NULL ) {
F_80 ( V_32 , L_13 ,
V_128 ) ;
return - V_123 ;
}
V_23 = F_87 ( F_88 ( V_127 ) ) ;
memset ( V_23 , 0 , V_128 ) ;
for ( V_64 = 0 ; V_64 < V_101 ; V_64 ++ )
V_25 -> V_105 [ V_64 ] =
V_23 + V_64 * sizeof( struct V_73 ) ;
if ( F_89 ( V_114 , V_4 ) ) {
V_126 = F_85 ( V_129 ) ;
V_127 = F_86 ( V_122 , V_126 , V_114 ) ;
if ( V_127 == NULL ) {
F_80 ( V_32 ,
L_14 ,
V_129 ) ;
return - V_123 ;
}
V_23 = F_87 ( F_88 ( V_127 ) ) ;
V_2 = F_90 ( & V_25 -> V_56 , & V_20 , V_68 ++ ,
V_23 , V_129 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 ,
L_15 , V_2 ) ;
return V_2 ;
}
V_25 -> V_107 = true ;
}
return V_68 ;
}
static int F_91 ( struct V_31 * V_32 ,
int V_68 , int V_130 )
{
int V_131 , V_2 ;
V_2 = F_92 ( & V_20 , 1 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_16 ,
V_2 ) ;
return V_2 ;
}
V_131 = V_2 ;
if ( V_130 > 4 )
V_116 = 256 ;
else if ( V_130 > 1 )
V_116 = 16 ;
V_2 = F_93 ( & V_20 , V_116 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_17 , V_2 ) ;
return V_2 ;
}
V_115 = V_2 ;
V_2 = F_94 (
& V_20 , V_131 , V_68 , V_130 ,
V_115 , V_116 ,
V_132 ) ;
if ( V_2 != 0 ) {
F_80 (
V_32 ,
L_18 ,
V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_95 ( struct V_31 * V_32 )
{
int V_114 , V_2 ;
V_2 = F_96 () ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_19 , V_2 ) ;
return V_2 ;
}
V_111 = V_2 ;
F_97 ( V_111 , V_133 ) ;
V_2 = F_98 ( V_111 , F_44 ,
0 , L_20 , NULL ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_21 , V_2 ) ;
F_99 ( V_111 ) ;
V_111 = - 1 ;
return V_2 ;
}
F_72 (cpu) {
struct V_24 * V_25 = & F_49 ( V_26 , V_114 ) ;
if ( V_25 -> V_107 ) {
F_100 (
& V_20 , F_101 ( V_114 ) , F_102 ( V_114 ) ,
1 , V_111 , V_25 -> V_56 . V_68 ) ;
}
}
return 0 ;
}
static void F_103 ( void )
{
int V_114 ;
if ( V_11 >= 0 )
F_19 ( V_11 ) ;
if ( V_12 >= 0 )
F_19 ( V_12 ) ;
F_104 ( & V_20 ) ;
F_72 (cpu) {
struct V_24 * V_25 = & F_49 ( V_26 , V_114 ) ;
F_105 ( ( unsigned long ) ( V_25 -> V_105 [ 0 ] ) ,
F_85 ( V_128 ) ) ;
V_25 -> V_105 [ 0 ] = NULL ;
F_105 ( ( unsigned long ) ( V_25 -> V_56 . V_134 ) ,
F_85 ( V_129 ) ) ;
V_25 -> V_56 . V_134 = NULL ;
}
if ( V_121 )
F_106 ( V_121 , V_120 ) ;
if ( V_124 )
F_106 ( V_124 , V_120 ) ;
V_121 = NULL ;
V_124 = NULL ;
V_12 = - 1 ;
V_11 = - 1 ;
V_115 = - 1 ;
}
static int F_107 ( struct V_31 * V_32 )
{
int V_64 , V_118 , V_2 ;
int V_114 ;
int V_135 , V_68 ;
int V_130 = F_108 ( V_4 ) ;
if ( ! V_136 ) {
F_80 ( V_32 , L_22 ) ;
return - V_117 ;
}
V_2 = F_109 ( & V_20 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_23 , V_2 ) ;
return - V_117 ;
}
V_118 =
V_130 * ( V_137 + V_66 ) ;
V_2 = F_75 ( V_32 , V_118 ) ;
if ( V_2 != 0 )
goto V_138;
V_2 = - V_123 ;
for ( V_64 = 0 ; V_64 < V_118 ; V_64 ++ ) {
if ( ! F_11 ( true ) ) {
F_80 ( V_32 , L_24 ) ;
goto V_138;
}
}
for ( V_64 = 0 ; V_64 < V_118 ; V_64 ++ ) {
if ( ! F_11 ( false ) ) {
F_80 ( V_32 , L_24 ) ;
goto V_138;
}
}
V_2 = F_110 ( & V_20 , V_130 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_25 ,
V_2 ) ;
goto V_138;
}
V_135 = V_2 ;
V_68 = V_135 ;
F_72 (cpu) {
V_2 = F_84 ( V_32 , V_114 , V_68 ) ;
if ( V_2 < 0 )
goto V_138;
V_68 = V_2 ;
}
V_2 = F_91 ( V_32 , V_135 , V_130 ) ;
if ( V_2 != 0 )
goto V_138;
V_2 = F_95 ( V_32 ) ;
if ( V_2 != 0 )
goto V_138;
return 0 ;
V_138:
F_103 () ;
return V_2 ;
}
static int F_111 ( struct V_31 * V_32 , int V_88 )
{
struct V_127 * V_139 , * V_140 , * V_141 ;
T_9 * V_142 ;
T_5 * V_72 ;
unsigned char * V_143 ;
int V_144 , V_145 , V_146 ;
T_10 V_147 ;
int V_148 ;
int V_2 = - V_123 ;
if ( V_104 [ V_88 ] . V_72 != NULL )
return 0 ;
V_144 = F_85 ( V_149 * V_150 ) ;
V_139 = F_112 ( V_122 , V_144 ) ;
if ( V_139 == NULL ) {
F_71 ( V_32 ,
L_26 ,
V_151 << V_144 ) ;
goto V_138;
}
V_143 = F_87 ( F_88 ( V_139 ) ) ;
V_147 = V_149 * sizeof( * V_142 ) ;
V_145 = F_85 ( V_147 ) ;
V_140 = F_112 ( V_122 , V_145 ) ;
if ( V_140 == NULL ) {
F_71 ( V_32 ,
L_27 ,
V_147 ) ;
goto V_152;
}
V_142 = F_87 ( F_88 ( V_140 ) ) ;
V_146 = F_85 ( sizeof( * V_72 ) ) ;
V_141 = F_112 ( V_122 , V_146 ) ;
if ( V_141 == NULL ) {
F_71 ( V_32 ,
L_28 ,
V_151 << V_146 ) ;
goto V_153;
}
V_72 = F_87 ( F_88 ( V_141 ) ) ;
V_2 = F_113 ( & V_20 , 1 , 0 , 0 ) ;
if ( V_2 < 0 ) {
F_71 ( V_32 , L_29 ,
V_2 ) ;
goto V_154;
}
V_148 = V_2 ;
V_2 = F_114 ( V_72 , & V_20 , V_148 , V_88 ,
V_142 , V_147 , 0 ) ;
if ( V_2 != 0 ) {
F_80 ( V_32 , L_30 , V_2 ) ;
goto V_154;
}
V_104 [ V_88 ] . V_72 = V_72 ;
V_104 [ V_88 ] . V_143 = V_143 ;
return 0 ;
V_154:
F_115 ( V_141 , V_146 ) ;
V_153:
F_115 ( V_140 , V_145 ) ;
V_152:
F_115 ( V_139 , V_144 ) ;
V_138:
return V_2 ;
}
static int F_116 ( struct V_31 * V_32 , T_11 * V_155 ,
const char * V_156 )
{
int V_2 = F_117 ( V_155 , & V_20 , V_156 , 0 ) ;
if ( V_2 < 0 ) {
F_80 ( V_32 , L_31 , V_156 ) ;
return V_2 ;
}
V_2 = F_118 ( V_155 ) ;
if ( V_2 < 0 || V_2 >= V_101 ) {
F_80 ( V_32 , L_32 , V_2 ) ;
F_119 ( V_155 ) ;
return - V_157 ;
}
return V_2 ;
}
static int F_120 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_114 , V_2 ;
F_121 ( & V_158 ) ;
if ( V_111 < 0 ) {
V_2 = F_107 ( V_32 ) ;
if ( V_2 != 0 )
goto V_138;
}
if ( F_122 ( ( V_159 != NULL ) &&
! strcmp ( V_32 -> V_160 , V_159 ) ) ) {
V_2 = F_116 ( V_32 , & V_39 -> V_155 , L_33 ) ;
if ( V_2 < 0 )
goto V_138;
V_39 -> V_51 = V_2 ;
V_2 = F_116 ( V_32 , & V_39 -> V_161 , L_34 ) ;
if ( V_2 < 0 )
goto V_138;
V_39 -> V_162 = V_2 ;
V_39 -> V_88 = V_2 ;
} else {
V_2 = F_116 ( V_32 , & V_39 -> V_155 , V_32 -> V_160 ) ;
if ( V_2 < 0 )
goto V_138;
V_39 -> V_51 = V_2 ;
V_39 -> V_88 = V_2 ;
}
V_2 = F_111 ( V_32 , V_39 -> V_88 ) ;
if ( V_2 != 0 )
goto V_138;
V_50 [ V_39 -> V_51 ] = V_32 ;
V_2 = F_65 ( V_32 ) ;
if ( V_2 != 0 )
goto V_138;
F_123 ( & V_158 ) ;
F_72 (cpu) {
struct V_24 * V_25 = & F_49 ( V_26 , V_114 ) ;
struct V_86 * V_87 =
& V_25 -> V_87 [ V_39 -> V_88 ] ;
F_124 ( & V_87 -> V_89 , V_163 ,
V_164 ) ;
V_87 -> V_85 = V_114 ;
V_87 -> V_89 . V_165 = F_52 ;
V_87 -> V_32 = V_32 ;
}
F_72 (cpu)
F_125 ( V_32 , V_114 ) ;
F_126 ( V_32 ) ;
return 0 ;
V_138:
if ( V_39 -> V_162 >= 0 ) {
if ( F_119 ( & V_39 -> V_161 ) != 0 )
F_71 ( V_32 , L_35 ) ;
V_39 -> V_162 = - 1 ;
}
if ( V_39 -> V_51 >= 0 ) {
if ( F_119 ( & V_39 -> V_155 ) != 0 )
F_71 ( V_32 , L_36 ) ;
V_39 -> V_51 = - 1 ;
}
V_39 -> V_88 = - 1 ;
V_50 [ V_39 -> V_51 ] = NULL ;
F_123 ( & V_158 ) ;
return ( V_2 > - 512 ) ? V_2 : - V_117 ;
}
static int F_127 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_114 ;
F_72 (cpu) {
struct V_24 * V_25 = & F_49 ( V_26 , V_114 ) ;
struct V_86 * V_87 =
& V_25 -> V_87 [ V_39 -> V_88 ] ;
F_128 ( & V_87 -> V_89 ) ;
F_129 ( V_32 , V_114 ) ;
}
F_121 ( & V_158 ) ;
V_50 [ V_39 -> V_51 ] = NULL ;
( void ) F_65 ( V_32 ) ;
if ( V_39 -> V_162 >= 0 ) {
if ( F_119 ( & V_39 -> V_161 ) != 0 )
F_71 ( V_32 , L_35 ) ;
V_39 -> V_162 = - 1 ;
}
if ( V_39 -> V_51 >= 0 ) {
if ( F_119 ( & V_39 -> V_155 ) != 0 )
F_71 ( V_32 , L_36 ) ;
V_39 -> V_51 = - 1 ;
}
V_39 -> V_88 = - 1 ;
F_123 ( & V_158 ) ;
return 0 ;
}
static inline void * F_130 ( T_12 * V_166 )
{
unsigned long V_167 = F_88 ( F_131 ( V_166 ) ) ;
return F_87 ( V_167 ) + V_166 -> V_168 ;
}
static T_13 F_132 ( struct V_31 * V_32 ,
int V_85 ,
struct V_73 * V_74 ,
T_5 * V_72 ,
int V_169 )
{
if ( V_74 -> V_78 - V_74 -> V_77 < V_80 - 1 ||
F_45 ( V_72 , V_74 , 32 , false ) != 0 ) {
T_13 V_170 = F_133 ( V_72 , V_169 ) ;
if ( V_170 >= 0 )
return V_170 ;
F_45 ( V_72 , V_74 , V_80 , false ) ;
V_170 = F_133 ( V_72 , V_169 ) ;
if ( V_170 >= 0 )
return V_170 ;
}
F_129 ( V_32 , V_85 ) ;
F_48 ( V_32 , V_85 ) ;
return - 1 ;
}
static int F_134 ( struct V_14 * V_15 )
{
struct V_171 * V_172 = F_135 ( V_15 ) ;
unsigned int V_173 = F_136 ( V_15 ) + F_137 ( V_15 ) ;
unsigned int V_174 = V_15 -> V_16 - V_173 ;
unsigned int V_175 = V_172 -> V_176 ;
long V_177 = - 1 ;
long V_178 = F_138 ( V_15 ) - V_173 ;
long V_179 = 0 ;
long V_65 ;
int V_169 = 0 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_172 -> V_181 ; V_180 ++ ) {
unsigned int V_182 = 0 ;
for ( V_169 ++ ; V_182 < V_175 ; V_169 ++ ) {
while ( V_179 >= V_178 ) {
V_177 ++ ;
V_178 = F_139 ( & V_172 -> V_183 [ V_177 ] ) ;
V_179 = 0 ;
}
V_65 = V_175 - V_182 ;
if ( V_65 > V_178 - V_179 )
V_65 = V_178 - V_179 ;
V_179 += V_65 ;
V_182 += V_65 ;
}
V_174 -= V_175 ;
if ( V_174 < V_175 )
V_175 = V_174 ;
}
return V_169 ;
}
static void F_140 ( struct V_14 * V_15 , unsigned char * V_143 ,
T_13 V_170 )
{
struct V_171 * V_172 = F_135 ( V_15 ) ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
unsigned int V_173 = F_136 ( V_15 ) + F_137 ( V_15 ) ;
unsigned int V_174 = V_15 -> V_16 - V_173 ;
unsigned char * V_19 = V_15 -> V_19 ;
unsigned int V_188 , V_189 , V_175 ;
unsigned int V_190 , V_191 , V_192 , V_193 ;
long V_177 = - 1 ;
long V_178 = F_138 ( V_15 ) - V_173 ;
long V_179 = 0 ;
long V_65 ;
int V_180 ;
V_185 = F_141 ( V_15 ) ;
V_187 = F_142 ( V_15 ) ;
V_188 = F_143 ( V_15 ) ;
V_189 = F_136 ( V_15 ) ;
V_175 = V_172 -> V_176 ;
V_190 = ( ( 0xFFFF - V_185 -> V_194 ) +
( 0xFFFF - V_185 -> V_195 ) +
( 0xFFFF - V_185 -> V_192 ) ) ;
V_191 = V_187 -> V_194 + ( 0xFFFF ^ F_144 ( V_15 -> V_16 ) ) ;
V_192 = F_145 ( V_185 -> V_192 ) ;
V_193 = F_146 ( V_187 -> V_193 ) ;
for ( V_180 = 0 ; V_180 < V_172 -> V_181 ; V_180 ++ ) {
unsigned char * V_1 ;
unsigned int V_182 = 0 ;
V_1 = V_143 + ( V_170 % V_149 ) * V_150 +
V_59 ;
memcpy ( V_1 , V_19 , V_173 ) ;
V_185 = (struct V_184 * ) ( V_1 + V_188 ) ;
V_185 -> V_195 = F_144 ( V_173 + V_175 - V_188 ) ;
V_185 -> V_192 = F_144 ( V_192 ) ;
V_185 -> V_194 = F_147 ( V_190 + V_185 -> V_195 +
V_185 -> V_192 ) ^ 0xffff ;
V_187 = (struct V_186 * ) ( V_1 + V_189 ) ;
V_187 -> V_193 = F_148 ( V_193 ) ;
V_187 -> V_194 = F_147 ( V_191 + F_144 ( V_173 + V_175 ) ) ;
if ( V_180 != V_172 -> V_181 - 1 ) {
V_187 -> V_196 = 0 ;
V_187 -> V_197 = 0 ;
}
V_170 ++ ;
while ( V_182 < V_175 ) {
while ( V_179 >= V_178 ) {
V_177 ++ ;
V_178 = F_139 ( & V_172 -> V_183 [ V_177 ] ) ;
V_179 = 0 ;
}
V_65 = V_175 - V_182 ;
if ( V_65 > V_178 - V_179 )
V_65 = V_178 - V_179 ;
V_179 += V_65 ;
V_182 += V_65 ;
V_170 ++ ;
}
V_192 ++ ;
V_193 += V_175 ;
V_174 -= V_175 ;
if ( V_174 < V_175 )
V_175 = V_174 ;
}
F_14 () ;
}
static void F_149 ( struct V_31 * V_32 , T_5 * V_72 ,
struct V_14 * V_15 , unsigned char * V_143 , T_13 V_170 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
struct V_171 * V_172 = F_135 ( V_15 ) ;
unsigned int V_173 = F_136 ( V_15 ) + F_137 ( V_15 ) ;
unsigned int V_174 = V_15 -> V_16 - V_173 ;
unsigned int V_175 = V_172 -> V_176 ;
T_9 V_198 = { { 0 } } ;
T_9 V_199 = { { 0 } } ;
long V_177 = - 1 ;
long V_178 = F_138 ( V_15 ) - V_173 ;
long V_179 = 0 ;
void * V_200 = V_15 -> V_19 + V_173 ;
long V_65 ;
unsigned long V_201 = 0 , V_202 = 0 ;
unsigned int V_203 ;
int V_180 ;
V_203 = F_150 ( V_15 ) ;
V_198 . V_204 = 1 ;
V_198 . V_203 = V_203 ;
V_198 . V_205 = V_203 + V_15 -> V_206 ;
V_198 . V_207 = V_173 ;
V_198 . V_208 = V_12 ;
V_199 . V_208 = V_12 ;
for ( V_180 = 0 ; V_180 < V_172 -> V_181 ; V_180 ++ ) {
unsigned char * V_1 ;
unsigned int V_182 = 0 ;
V_1 = V_143 + ( V_170 % V_149 ) * V_150 +
V_59 ;
V_198 . V_21 = F_16 ( V_1 ) ;
F_151 ( V_72 , V_198 , V_170 ) ;
V_170 ++ ;
while ( V_182 < V_175 ) {
void * V_21 ;
while ( V_179 >= V_178 ) {
V_177 ++ ;
V_178 = F_139 ( & V_172 -> V_183 [ V_177 ] ) ;
V_200 = F_130 ( & V_172 -> V_183 [ V_177 ] ) ;
V_179 = 0 ;
}
V_21 = V_200 + V_179 ;
V_65 = V_175 - V_182 ;
if ( V_65 > V_178 - V_179 )
V_65 = V_178 - V_179 ;
V_179 += V_65 ;
V_182 += V_65 ;
V_199 . V_21 = F_16 ( V_21 ) ;
V_199 . V_207 = V_65 ;
V_199 . V_209 = ! ( V_182 < V_175 ) ;
F_151 ( V_72 , V_199 , V_170 ) ;
V_170 ++ ;
}
V_201 ++ ;
V_202 += V_173 + V_175 ;
V_174 -= V_175 ;
if ( V_174 < V_175 )
V_175 = V_174 ;
}
F_8 ( V_201 , & V_39 -> V_45 . V_201 ) ;
F_8 ( V_202 , & V_39 -> V_45 . V_202 ) ;
}
static int F_152 ( struct V_14 * V_15 , struct V_31 * V_32 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
int V_51 = V_39 -> V_88 ;
struct V_102 * V_103 = & V_104 [ V_51 ] ;
struct V_73 * V_74 = V_25 -> V_105 [ V_51 ] ;
T_5 * V_72 = V_103 -> V_72 ;
unsigned long V_99 ;
int V_169 ;
T_13 V_170 ;
V_169 = F_134 ( V_15 ) ;
F_57 ( V_99 ) ;
V_170 = F_132 ( V_32 , V_15 -> V_210 , V_74 ,
V_72 , V_169 ) ;
if ( V_170 < 0 ) {
F_58 ( V_99 ) ;
return V_211 ;
}
F_140 ( V_15 , V_103 -> V_143 , V_170 ) ;
F_149 ( V_32 , V_72 , V_15 , V_103 -> V_143 , V_170 ) ;
F_47 ( V_72 , V_74 , V_170 + V_169 - 1 , V_15 ) ;
F_58 ( V_99 ) ;
F_55 () ;
return V_212 ;
}
static unsigned int F_153 ( struct V_213 * V_183 ,
struct V_14 * V_15 ,
void * V_214 , unsigned int V_215 )
{
unsigned int V_64 , V_65 = 0 ;
struct V_171 * V_172 = F_135 ( V_15 ) ;
if ( V_215 != 0 ) {
V_183 [ V_65 ] . V_1 = V_214 ;
V_183 [ V_65 ++ ] . V_216 = V_215 ;
}
for ( V_64 = 0 ; V_64 < V_172 -> V_217 ; V_64 ++ ) {
T_12 * V_166 = & V_172 -> V_183 [ V_64 ] ;
V_183 [ V_65 ] . V_1 = F_130 ( V_166 ) ;
V_183 [ V_65 ++ ] . V_216 = F_139 ( V_166 ) ;
}
return V_65 ;
}
static int F_154 ( struct V_14 * V_15 , struct V_31 * V_32 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
struct V_38 * V_39 = F_30 ( V_32 ) ;
struct V_102 * V_103 = & V_104 [ V_39 -> V_88 ] ;
T_5 * V_72 = V_103 -> V_72 ;
struct V_73 * V_74 =
V_25 -> V_105 [ V_39 -> V_88 ] ;
unsigned int V_16 = V_15 -> V_16 ;
unsigned char * V_19 = V_15 -> V_19 ;
unsigned int V_169 ;
struct V_213 V_183 [ V_218 ] ;
T_9 V_142 [ V_218 ] ;
unsigned long V_99 ;
T_9 V_219 = { { 0 } } ;
unsigned int V_64 ;
T_13 V_170 ;
if ( F_155 ( V_15 ) )
return F_152 ( V_15 , V_32 ) ;
V_169 = F_153 ( V_183 , V_15 , V_19 , F_138 ( V_15 ) ) ;
V_219 . V_208 = V_12 ;
for ( V_64 = 0 ; V_64 < V_169 ; V_64 ++ ) {
V_219 . V_207 = V_183 [ V_64 ] . V_216 ;
V_219 . V_21 = F_16 ( V_183 [ V_64 ] . V_1 ) ;
V_142 [ V_64 ] = V_219 ;
}
V_142 [ V_169 - 1 ] . V_209 = 1 ;
if ( V_15 -> V_43 == V_220 ) {
unsigned int V_203 = F_150 ( V_15 ) ;
V_142 [ 0 ] . V_204 = 1 ;
V_142 [ 0 ] . V_203 = V_203 ;
V_142 [ 0 ] . V_205 = V_203 + V_15 -> V_206 ;
}
F_57 ( V_99 ) ;
V_170 = F_132 ( V_32 , V_15 -> V_210 , V_74 ,
V_72 , V_169 ) ;
if ( V_170 < 0 ) {
F_58 ( V_99 ) ;
return V_211 ;
}
for ( V_64 = 0 ; V_64 < V_169 ; V_64 ++ )
F_151 ( V_72 , V_142 [ V_64 ] , V_170 ++ ) ;
F_47 ( V_72 , V_74 , V_170 - 1 , V_15 ) ;
F_8 ( 1 , & V_39 -> V_45 . V_201 ) ;
F_8 ( F_156 (unsigned int, len, ETH_ZLEN) ,
& V_39 -> V_45 . V_202 ) ;
F_58 ( V_99 ) ;
F_55 () ;
return V_212 ;
}
static T_14 F_157 ( struct V_31 * V_32 , struct V_14 * V_15 )
{
return F_158 () ;
}
static void F_159 ( struct V_31 * V_32 )
{
int V_114 ;
F_72 (cpu)
F_54 ( V_32 , V_114 ) ;
}
static int F_160 ( struct V_31 * V_32 , struct V_221 * V_222 , int V_223 )
{
return - V_224 ;
}
static struct V_225 * F_161 ( struct V_31 * V_32 )
{
struct V_38 * V_39 = F_30 ( V_32 ) ;
return & V_39 -> V_45 ;
}
static int F_162 ( struct V_31 * V_32 , int V_226 )
{
if ( ( V_226 < 68 ) || ( V_226 > 1500 ) )
return - V_157 ;
V_32 -> V_227 = V_226 ;
return 0 ;
}
static int F_163 ( struct V_31 * V_32 , void * V_228 )
{
struct V_229 * V_23 = V_228 ;
if ( ! F_164 ( V_23 -> V_230 ) )
return - V_157 ;
memcpy ( V_32 -> V_36 , V_23 -> V_230 , V_32 -> V_231 ) ;
return 0 ;
}
static void F_165 ( struct V_31 * V_32 )
{
F_63 ( V_111 ) ;
F_44 ( V_111 , NULL ) ;
F_62 ( V_111 , 0 ) ;
}
static void F_166 ( struct V_31 * V_32 )
{
F_167 ( V_32 ) ;
V_32 -> V_232 = & V_233 ;
V_32 -> V_234 = V_235 ;
V_32 -> V_236 |= V_237 ;
V_32 -> V_236 |= V_238 ;
V_32 -> V_236 |= V_239 ;
V_32 -> V_236 |= V_240 ;
V_32 -> V_227 = 1500 ;
}
static void F_168 ( const char * V_160 , const T_3 * V_241 )
{
int V_242 ;
int V_64 ;
int V_243 = 0 ;
struct V_31 * V_32 ;
struct V_38 * V_39 ;
if ( strncmp ( V_160 , L_37 , 4 ) == 0 )
return;
V_32 = F_169 ( sizeof( * V_39 ) , V_160 , F_166 ,
V_244 , 1 ) ;
if ( ! V_32 ) {
F_170 ( L_38 , V_160 ) ;
return;
}
V_39 = F_30 ( V_32 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_32 = V_32 ;
V_39 -> V_51 = - 1 ;
V_39 -> V_162 = - 1 ;
V_39 -> V_88 = - 1 ;
for ( V_64 = 0 ; V_64 < 6 ; V_64 ++ )
V_243 |= V_241 [ V_64 ] ;
if ( V_243 ) {
memcpy ( V_32 -> V_36 , V_241 , 6 ) ;
V_32 -> V_231 = 6 ;
} else {
F_171 ( V_32 ) ;
}
V_242 = F_172 ( V_32 ) ;
if ( V_242 ) {
F_80 ( V_32 , L_39 , V_242 ) ;
F_173 ( V_32 ) ;
return;
}
}
static void F_174 ( void * V_70 )
{
struct V_24 * V_25 = & F_24 ( V_26 ) ;
int V_30 = F_158 () ;
V_25 -> V_107 = false ;
V_25 -> V_30 = V_30 ;
F_124 ( & V_25 -> V_97 , V_163 , V_164 ) ;
V_25 -> V_97 . V_165 = F_56 ;
}
static int T_15 F_175 ( void )
{
int V_64 ;
char V_160 [ V_245 ] ;
T_3 V_241 [ 6 ] ;
F_7 ( L_40 ) ;
F_176 ( & V_158 ) ;
F_177 ( F_174 , NULL , 1 ) ;
for ( V_64 = 0 ; F_178 ( V_64 , V_160 , V_241 ) >= 0 ; V_64 ++ )
F_168 ( V_160 , V_241 ) ;
if ( ! F_1 () )
V_4 = * V_246 ;
return 0 ;
}
