static bool F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 )
return true ;
}
return false ;
}
static const char * F_2 ( enum V_5 V_6 )
{
int V_7 , V_8 = F_3 ( V_9 ) ;
const char * V_10 = L_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( V_9 [ V_7 ] . V_6 == V_6 ) {
V_10 = V_9 [ V_7 ] . V_10 ;
break;
}
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 ,
bool V_15 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
int type = V_17 -> type ;
const char * V_18 ;
if ( V_17 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
if ( V_15 )
return 0 ;
V_18 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_19 &= ~ V_6 ;
V_18 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
return F_4 ( V_12 , V_13 , V_14 , V_6 ,
false ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_15 ;
if ( F_10 ( & V_21 -> V_22 , V_23 ) )
return 0 ;
V_15 = F_10 ( & V_21 -> V_22 ,
V_24 ) ;
if ( F_11 ( V_25 ) &&
! F_12 ( V_21 , L_5 ) )
return - V_26 ;
if ( F_11 ( V_27 ) ) {
if ( F_8 ( V_12 , V_28 , L_6 ,
V_29 ) )
return - V_26 ;
}
if ( F_11 ( V_30 ) &&
F_4 ( V_12 , V_31 , L_7 ,
V_32 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_33 ) &&
F_8 ( V_12 , V_34 , L_8 ,
V_35 ) )
return - V_26 ;
if ( F_11 ( V_36 ) &&
F_8 ( V_12 , V_37 , L_9 ,
V_38 ) )
return - V_26 ;
if ( F_11 ( V_39 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_10
L_11
L_12 ) ;
return - V_26 ;
}
if ( F_11 ( V_40 ) && ! F_11 ( V_39 ) ) {
F_6 ( L_13
L_14 ) ;
return - V_26 ;
}
if ( F_11 ( V_41 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_15
L_11
L_16 ) ;
return - V_26 ;
}
if ( F_11 ( V_42 ) && ! F_11 ( V_27 ) ) {
F_6 ( L_17
L_18 ) ;
return - V_26 ;
}
if ( F_11 ( V_43 ) &&
! ( F_13 ( V_21 -> V_44 ) &
V_45 ) ) {
F_6 ( L_19
L_20 ) ;
return - V_26 ;
}
if ( ( F_11 ( V_46 ) || F_11 ( V_47 ) ) &&
F_8 ( V_12 , V_48 , L_21 ,
V_49 | V_50 ) )
return - V_26 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_51 , L_22 ,
V_52 ) )
return - V_26 ;
if ( F_11 ( V_53 ) &&
F_4 ( V_12 , V_54 , L_23 ,
V_55 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_56 ) &&
F_8 ( V_12 , V_57 , L_24 ,
V_58 ) )
return - V_26 ;
if ( F_11 ( V_59 ) &&
F_8 ( V_12 , V_60 , L_25 ,
V_61 ) )
return - V_26 ;
return 0 ;
}
static void F_14 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_62 = 0 ;
if ( F_11 ( V_27 ) )
V_3 [ type ] . V_62 |= V_63 ;
if ( F_11 ( V_39 ) )
V_3 [ type ] . V_62 |= V_64 ;
if ( F_11 ( V_41 ) )
V_3 [ type ] . V_62 |= V_65 ;
if ( F_11 ( V_40 ) )
V_3 [ type ] . V_62 |= V_66 ;
if ( F_11 ( V_42 ) )
V_3 [ type ] . V_62 |= V_67 ;
}
static int F_15 ( struct V_20 * V_21 )
{
unsigned int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_16 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_68 ) {
F_6 ( L_26
L_27 ,
F_17 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_19 &&
F_9 ( V_12 , V_21 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_14 ( & V_12 -> V_17 ) ;
}
if ( ! V_69 ) {
bool V_70 = false ;
bool V_71 = false ;
F_18 (session->evlist, evsel) {
V_71 = true ;
if ( V_12 -> V_17 . V_13 & V_72 ) {
V_70 = true ;
break;
}
}
if ( V_71 && ! V_70 )
V_73 . V_70 = false ;
}
if ( V_73 . V_70 &&
! V_3 [ V_74 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_74 ;
F_18 (session->evlist, evsel) {
if ( V_12 -> V_17 . type != V_1 )
continue;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_72 ) {
V_3 [ V_1 ] . V_19 |= V_29 ;
V_3 [ V_1 ] . V_19 |= V_75 ;
V_3 [ V_1 ] . V_19 |= V_76 ;
F_14 ( V_17 ) ;
goto V_77;
}
}
}
V_77:
return 0 ;
}
static void F_19 ( struct V_78 * V_79 ,
struct V_16 * V_17 )
{
struct V_80 * V_81 = & V_79 -> V_82 ;
T_2 V_83 = V_17 -> V_84 ;
unsigned V_7 = 0 , V_85 ;
if ( ! V_81 )
return;
F_20 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_86 = V_81 -> V_81 [ V_7 ++ ] ;
printf ( L_28 V_87 L_29 , F_21 ( V_85 ) , V_86 ) ;
}
}
static void F_22 ( struct V_78 * V_79 ,
struct V_88 * V_88 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_89 ;
unsigned long long V_90 ;
if ( F_11 ( V_91 ) ) {
if ( V_92 )
printf ( L_30 , F_23 ( V_88 ) ) ;
else if ( F_11 ( V_27 ) && V_73 . V_70 )
printf ( L_31 , F_23 ( V_88 ) ) ;
else
printf ( L_32 , F_23 ( V_88 ) ) ;
}
if ( F_11 ( V_46 ) && F_11 ( V_47 ) )
printf ( L_33 , V_79 -> V_93 , V_79 -> V_94 ) ;
else if ( F_11 ( V_46 ) )
printf ( L_34 , V_79 -> V_93 ) ;
else if ( F_11 ( V_47 ) )
printf ( L_34 , V_79 -> V_94 ) ;
if ( F_11 ( V_53 ) ) {
if ( V_92 )
printf ( L_35 , V_79 -> V_95 ) ;
else
printf ( L_36 , V_79 -> V_95 ) ;
}
if ( F_11 ( TIME ) ) {
V_90 = V_79 -> time ;
V_89 = V_90 / V_96 ;
V_90 -= V_89 * V_96 ;
if ( V_97 )
printf ( L_37 , V_89 , V_90 ) ;
else {
char V_98 [ 32 ] ;
F_24 ( V_79 -> time , V_98 , sizeof( V_98 ) ) ;
printf ( L_38 , V_98 ) ;
}
}
}
static inline char
F_25 ( struct V_99 * V_100 )
{
if ( ! ( V_100 -> V_101 . V_102 || V_100 -> V_101 . V_103 ) )
return '-' ;
return V_100 -> V_101 . V_103 ? 'P' : 'M' ;
}
static void F_26 ( struct V_78 * V_79 )
{
struct V_104 * V_100 = V_79 -> V_104 ;
T_1 V_7 ;
if ( ! ( V_100 && V_100 -> V_105 ) )
return;
for ( V_7 = 0 ; V_7 < V_100 -> V_105 ; V_7 ++ ) {
printf ( L_39 V_87 L_40 V_87 L_41 ,
V_100 -> V_106 [ V_7 ] . V_107 ,
V_100 -> V_106 [ V_7 ] . V_108 ,
F_25 ( V_100 -> V_106 + V_7 ) ,
V_100 -> V_106 [ V_7 ] . V_101 . V_109 ? 'X' : '-' ,
V_100 -> V_106 [ V_7 ] . V_101 . abort ? 'A' : '-' ,
V_100 -> V_106 [ V_7 ] . V_101 . V_110 ) ;
}
}
static void F_27 ( struct V_78 * V_79 ,
struct V_88 * V_88 )
{
struct V_104 * V_100 = V_79 -> V_104 ;
struct V_111 V_112 , V_113 ;
T_1 V_7 , V_107 , V_108 ;
if ( ! ( V_100 && V_100 -> V_105 ) )
return;
for ( V_7 = 0 ; V_7 < V_100 -> V_105 ; V_7 ++ ) {
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_107 = V_100 -> V_106 [ V_7 ] . V_107 ;
V_108 = V_100 -> V_106 [ V_7 ] . V_108 ;
F_28 ( V_88 , V_79 -> V_114 , V_115 , V_107 , & V_112 ) ;
if ( V_112 . V_116 )
V_112 . V_117 = F_29 ( V_112 . V_116 , V_112 . V_118 ) ;
F_28 ( V_88 , V_79 -> V_114 , V_115 , V_108 , & V_113 ) ;
if ( V_113 . V_116 )
V_113 . V_117 = F_29 ( V_113 . V_116 , V_113 . V_118 ) ;
F_30 ( V_112 . V_117 , & V_112 , stdout ) ;
putchar ( '/' ) ;
F_30 ( V_113 . V_117 , & V_113 , stdout ) ;
printf ( L_41 ,
F_25 ( V_100 -> V_106 + V_7 ) ,
V_100 -> V_106 [ V_7 ] . V_101 . V_109 ? 'X' : '-' ,
V_100 -> V_106 [ V_7 ] . V_101 . abort ? 'A' : '-' ,
V_100 -> V_106 [ V_7 ] . V_101 . V_110 ) ;
}
}
static int F_31 ( T_3 * V_119 , T_1 V_120 , T_1 V_121 ,
struct V_122 * V_122 , struct V_88 * V_88 ,
bool * V_123 , T_3 * V_114 , bool V_124 )
{
long V_125 , V_126 ;
struct V_111 V_127 ;
bool V_128 ;
if ( ! V_120 || ! V_121 )
return 0 ;
V_128 = F_32 ( V_122 , V_120 ) ;
if ( V_128 )
* V_114 = V_129 ;
else
* V_114 = V_130 ;
if ( V_128 != F_32 ( V_122 , V_121 ) ) {
printf ( L_42 V_87 L_43 V_87 L_44 ,
V_120 , V_121 ) ;
return - V_131 ;
}
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( V_121 - V_120 > V_132 - V_133 ) {
if ( V_124 )
printf ( L_45 V_87 L_43 V_87 L_46 , V_120 , V_121 ) ;
else
printf ( L_42 V_87 L_43 V_87 L_47 V_134 L_48 , V_120 , V_121 , V_121 - V_120 ) ;
return 0 ;
}
F_28 ( V_88 , * V_114 , V_115 , V_120 , & V_127 ) ;
if ( ! V_127 . V_116 || ! V_127 . V_116 -> V_135 ) {
printf ( L_49 V_87 L_43 V_87 L_50 , V_120 , V_121 ) ;
return 0 ;
}
if ( V_127 . V_116 -> V_135 -> V_136 . V_137 == V_138 ) {
printf ( L_49 V_87 L_43 V_87 L_50 , V_120 , V_121 ) ;
return 0 ;
}
F_33 ( V_127 . V_116 ) ;
V_125 = V_127 . V_116 -> V_139 ( V_127 . V_116 , V_120 ) ;
V_126 = F_34 ( V_127 . V_116 -> V_135 , V_122 , V_125 , ( T_3 * ) V_119 ,
V_121 - V_120 + V_133 ) ;
* V_123 = V_127 . V_116 -> V_135 -> V_140 ;
if ( V_126 <= 0 )
printf ( L_51 V_87 L_43 V_87 L_50 ,
V_120 , V_121 ) ;
return V_126 ;
}
static void F_35 ( T_2 V_141 , struct V_99 * V_142 ,
struct V_143 * V_144 , T_3 * V_145 , int V_126 ,
int V_146 )
{
printf ( L_52 V_87 L_53 ,
V_141 ,
F_36 ( V_144 , V_141 , V_145 , V_126 , NULL ) ,
V_142 -> V_101 . V_103 ? L_54 : L_1 ,
V_142 -> V_101 . V_102 ? L_55 : L_1 ,
V_142 -> V_101 . V_109 ? L_56 : L_1 ,
V_142 -> V_101 . abort ? L_57 : L_1 ) ;
if ( V_142 -> V_101 . V_110 ) {
printf ( L_58 , V_142 -> V_101 . V_110 ) ;
if ( V_146 )
printf ( L_59 , ( float ) V_146 / V_142 -> V_101 . V_110 ) ;
}
putchar ( '\n' ) ;
}
static void F_37 ( struct V_88 * V_88 , T_3 V_114 , int V_95 ,
T_2 V_118 , struct V_147 * * V_148 ,
struct V_16 * V_17 )
{
struct V_111 V_127 ;
int V_149 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
F_28 ( V_88 , V_114 , V_115 , V_118 , & V_127 ) ;
if ( ! V_127 . V_116 )
F_28 ( V_88 , V_114 , V_150 ,
V_118 , & V_127 ) ;
if ( ( * V_148 ) && V_127 . V_118 >= ( * V_148 ) -> V_120 && V_127 . V_118 < ( * V_148 ) -> V_121 )
return;
V_127 . V_95 = V_95 ;
V_127 . V_117 = NULL ;
if ( V_127 . V_116 )
V_127 . V_117 = F_29 ( V_127 . V_116 , V_127 . V_118 ) ;
if ( ! V_127 . V_117 )
return;
if ( V_127 . V_118 < V_127 . V_117 -> V_121 )
V_149 = V_127 . V_118 - V_127 . V_117 -> V_120 ;
else
V_149 = V_127 . V_118 - V_127 . V_116 -> V_120 - V_127 . V_117 -> V_120 ;
printf ( L_60 , V_127 . V_117 -> V_151 ) ;
if ( V_149 )
printf ( L_61 , V_149 ) ;
putchar ( ':' ) ;
if ( F_11 ( V_42 ) )
F_38 ( V_127 . V_116 , V_127 . V_118 , L_62 , stdout ) ;
putchar ( '\n' ) ;
* V_148 = V_127 . V_117 ;
}
static void F_39 ( struct V_78 * V_79 ,
struct V_88 * V_88 ,
struct V_16 * V_17 ,
struct V_122 * V_122 )
{
struct V_104 * V_100 = V_79 -> V_104 ;
T_1 V_120 , V_121 ;
int V_7 , V_146 , V_126 , V_105 , V_152 ;
struct V_143 V_144 ;
T_3 V_119 [ V_132 ] ;
unsigned V_149 ;
struct V_147 * V_148 = NULL ;
if ( ! ( V_100 && V_100 -> V_105 ) )
return;
V_105 = V_100 -> V_105 ;
if ( V_153 && V_105 > V_153 + 1 )
V_105 = V_153 + 1 ;
V_144 . V_88 = V_88 ;
V_144 . V_95 = V_79 -> V_95 ;
putchar ( '\n' ) ;
V_126 = F_31 ( V_119 , V_100 -> V_106 [ V_105 - 1 ] . V_107 ,
V_100 -> V_106 [ V_105 - 1 ] . V_107 ,
V_122 , V_88 , & V_144 . V_123 , & V_144 . V_114 , false ) ;
if ( V_126 > 0 ) {
F_37 ( V_88 , V_144 . V_114 , V_144 . V_95 ,
V_100 -> V_106 [ V_105 - 1 ] . V_107 , & V_148 , V_17 ) ;
F_35 ( V_100 -> V_106 [ V_105 - 1 ] . V_107 , & V_100 -> V_106 [ V_105 - 1 ] ,
& V_144 , V_119 , V_126 , 0 ) ;
}
for ( V_7 = V_105 - 2 ; V_7 >= 0 ; V_7 -- ) {
if ( V_100 -> V_106 [ V_7 ] . V_107 || V_100 -> V_106 [ V_7 ] . V_108 )
F_7 ( L_63 V_87 L_43 V_87 L_50 , V_7 ,
V_100 -> V_106 [ V_7 ] . V_107 ,
V_100 -> V_106 [ V_7 ] . V_108 ) ;
V_120 = V_100 -> V_106 [ V_7 + 1 ] . V_108 ;
V_121 = V_100 -> V_106 [ V_7 ] . V_107 ;
V_126 = F_31 ( V_119 , V_120 , V_121 , V_122 , V_88 , & V_144 . V_123 , & V_144 . V_114 , false ) ;
if ( V_126 == - V_131 && V_7 > 0 ) {
V_121 = V_100 -> V_106 [ -- V_7 ] . V_107 ;
F_7 ( L_64 V_87 L_43 V_87 L_50 , V_120 , V_121 ) ;
V_126 = F_31 ( V_119 , V_120 , V_121 , V_122 , V_88 , & V_144 . V_123 , & V_144 . V_114 , false ) ;
}
if ( V_126 <= 0 )
continue;
V_146 = 0 ;
for ( V_149 = 0 ; ; V_149 += V_152 ) {
T_2 V_141 = V_120 + V_149 ;
F_37 ( V_88 , V_144 . V_114 , V_144 . V_95 , V_141 , & V_148 , V_17 ) ;
if ( V_141 == V_121 ) {
F_35 ( V_141 , & V_100 -> V_106 [ V_7 ] , & V_144 , V_119 + V_149 , V_126 - V_149 , V_146 ) ;
break;
} else {
printf ( L_52 V_87 L_65 , V_141 ,
F_36 ( & V_144 , V_141 , V_119 + V_149 , V_126 - V_149 , & V_152 ) ) ;
if ( V_152 == 0 )
break;
V_146 ++ ;
}
}
}
if ( V_100 -> V_106 [ 0 ] . V_107 == V_79 -> V_141 )
return;
if ( V_100 -> V_106 [ 0 ] . V_101 . abort )
return;
V_120 = V_100 -> V_106 [ 0 ] . V_108 ;
V_121 = V_79 -> V_141 ;
V_126 = F_31 ( V_119 , V_120 , V_121 , V_122 , V_88 , & V_144 . V_123 , & V_144 . V_114 , true ) ;
F_37 ( V_88 , V_144 . V_114 , V_144 . V_95 , V_120 , & V_148 , V_17 ) ;
if ( V_126 <= 0 ) {
V_126 = F_31 ( V_119 , V_79 -> V_141 , V_79 -> V_141 ,
V_122 , V_88 , & V_144 . V_123 , & V_144 . V_114 , false ) ;
if ( V_126 <= 0 )
return;
printf ( L_52 V_87 L_65 , V_79 -> V_141 ,
F_36 ( & V_144 , V_79 -> V_141 , V_119 , V_126 , NULL ) ) ;
return;
}
for ( V_149 = 0 ; V_149 <= V_121 - V_120 ; V_149 += V_152 ) {
printf ( L_52 V_87 L_65 , V_120 + V_149 ,
F_36 ( & V_144 , V_120 + V_149 , V_119 + V_149 , V_126 - V_149 , & V_152 ) ) ;
if ( V_152 == 0 )
break;
}
}
static void F_40 ( struct V_78 * V_79 ,
struct V_88 * V_88 ,
struct V_16 * V_17 )
{
struct V_111 V_127 ;
printf ( L_66 V_87 , V_79 -> V_118 ) ;
if ( ! F_41 ( V_17 ) )
return;
F_42 ( V_88 , & V_127 , V_79 ) ;
if ( F_11 ( V_39 ) ) {
printf ( L_29 ) ;
if ( F_11 ( V_40 ) )
F_30 ( V_127 . V_117 , & V_127 , stdout ) ;
else
F_43 ( V_127 . V_117 , stdout ) ;
}
if ( F_11 ( V_41 ) ) {
printf ( L_67 ) ;
F_44 ( V_127 . V_116 , stdout ) ;
printf ( L_68 ) ;
}
}
static void F_45 ( struct V_78 * V_79 ,
struct V_11 * V_12 ,
struct V_88 * V_88 ,
struct V_111 * V_127 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
T_4 V_154 = F_46 ( V_88 ) ;
struct V_111 V_155 ;
const char * V_151 = NULL ;
static int V_156 ;
int V_126 = 0 ;
T_1 V_141 = 0 ;
if ( V_88 -> V_157 && V_79 -> V_101 & V_158 )
V_154 += 1 ;
if ( V_79 -> V_101 & ( V_159 | V_160 ) ) {
if ( F_41 ( V_17 ) ) {
F_42 ( V_88 , & V_155 , V_79 ) ;
if ( V_155 . V_117 )
V_151 = V_155 . V_117 -> V_151 ;
else
V_141 = V_79 -> V_118 ;
} else {
V_141 = V_79 -> V_118 ;
}
} else if ( V_79 -> V_101 & ( V_158 | V_161 ) ) {
if ( V_127 -> V_117 )
V_151 = V_127 -> V_117 -> V_151 ;
else
V_141 = V_79 -> V_141 ;
}
if ( V_151 )
V_126 = printf ( L_69 , ( int ) V_154 * 4 , L_1 , V_151 ) ;
else if ( V_141 )
V_126 = printf ( L_70 V_87 , ( int ) V_154 * 4 , L_1 , V_141 ) ;
if ( V_126 < 0 )
return;
if ( V_126 > V_156 || ( V_126 && V_126 < V_156 - 52 ) )
V_156 = F_47 ( V_126 + 4 , 32 ) ;
if ( V_126 < V_156 )
printf ( L_71 , V_156 - V_126 , L_1 ) ;
}
static void F_48 ( struct V_78 * V_79 ,
struct V_16 * V_17 ,
struct V_88 * V_88 ,
struct V_122 * V_122 )
{
if ( F_11 ( V_162 ) )
printf ( L_72 , V_79 -> V_163 ) ;
if ( F_11 ( V_164 ) ) {
int V_7 ;
printf ( L_73 ) ;
for ( V_7 = 0 ; V_7 < V_79 -> V_163 ; V_7 ++ )
printf ( L_74 , ( unsigned char ) V_79 -> V_146 [ V_7 ] ) ;
}
if ( F_11 ( V_43 ) )
F_39 ( V_79 , V_88 , V_17 , V_122 ) ;
}
static void F_49 ( struct V_78 * V_79 ,
struct V_11 * V_12 ,
struct V_88 * V_88 ,
struct V_111 * V_127 ,
struct V_122 * V_122 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_165 = false ;
if ( F_11 ( V_166 ) )
F_45 ( V_79 , V_12 , V_88 , V_127 ) ;
if ( F_11 ( V_27 ) ) {
unsigned int V_167 = V_3 [ V_17 -> type ] . V_62 ;
struct V_168 * V_169 = NULL ;
if ( V_73 . V_70 && V_79 -> V_170 &&
F_50 ( V_127 -> V_88 , & V_168 , V_12 ,
V_79 , NULL , NULL , V_171 ) == 0 )
V_169 = & V_168 ;
if ( V_169 == NULL ) {
putchar ( ' ' ) ;
if ( V_167 & V_67 ) {
V_165 = true ;
V_167 &= ~ V_67 ;
}
} else
putchar ( '\n' ) ;
F_51 ( V_79 , V_127 , 0 , V_167 , V_169 , stdout ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_75 ) ;
F_40 ( V_79 , V_88 , V_17 ) ;
}
if ( V_165 )
F_38 ( V_127 -> V_116 , V_127 -> V_118 , L_76 , stdout ) ;
F_48 ( V_79 , V_17 , V_88 , V_122 ) ;
printf ( L_50 ) ;
}
static void F_52 ( T_5 V_101 )
{
const char * V_172 = V_173 ;
const int V_174 = strlen ( V_173 ) ;
bool V_109 = V_101 & V_175 ;
const char * V_151 = NULL ;
char V_10 [ 33 ] ;
int V_7 , V_176 = 0 ;
for ( V_7 = 0 ; V_177 [ V_7 ] . V_151 ; V_7 ++ ) {
if ( V_177 [ V_7 ] . V_101 == ( V_101 & ~ V_175 ) ) {
V_151 = V_177 [ V_7 ] . V_151 ;
break;
}
}
for ( V_7 = 0 ; V_7 < V_174 ; V_7 ++ , V_101 >>= 1 ) {
if ( V_101 & 1 )
V_10 [ V_176 ++ ] = V_172 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_101 >>= 1 ) {
if ( V_101 & 1 )
V_10 [ V_176 ++ ] = '?' ;
}
V_10 [ V_176 ] = 0 ;
if ( V_151 )
printf ( L_77 , V_151 , V_109 ? L_78 : L_1 ) ;
else
printf ( L_79 , V_10 ) ;
}
static void
F_53 ( enum V_178 V_179 ,
unsigned int V_86 ,
void * V_180 )
{
unsigned char V_181 = ( unsigned char ) V_86 ;
struct V_182 * V_182 = V_180 ;
switch ( V_179 ) {
case V_183 :
printf ( L_50 ) ;
break;
case V_184 :
printf ( L_80 , ! V_182 -> V_185 ? L_81 :
L_82 ) ;
break;
case V_186 :
printf ( L_83 , V_86 ) ;
break;
case V_187 :
printf ( L_74 , V_86 ) ;
break;
case V_188 :
printf ( L_84 ) ;
break;
case V_189 :
printf ( L_85 ) ;
break;
case V_190 :
if ( V_182 -> V_191 && V_181 )
V_182 -> V_192 = false ;
if ( ! isprint ( V_181 ) ) {
printf ( L_86 , '.' ) ;
if ( ! V_182 -> V_192 )
break;
if ( V_181 == '\0' )
V_182 -> V_191 = true ;
else
V_182 -> V_192 = false ;
} else {
printf ( L_86 , V_181 ) ;
}
break;
case V_193 :
printf ( L_29 ) ;
break;
case V_194 :
printf ( L_50 ) ;
V_182 -> V_185 ++ ;
break;
case V_195 :
default:
break;
}
}
static void F_54 ( struct V_78 * V_79 )
{
unsigned int V_196 = V_79 -> V_197 ;
struct V_182 V_182 = { 0 , false , true } ;
F_55 ( V_79 -> V_198 , V_196 , 8 ,
F_53 , & V_182 ) ;
if ( V_182 . V_192 && V_182 . V_191 )
printf ( L_87 , L_88 ,
( char * ) ( V_79 -> V_198 ) ) ;
}
static int F_56 ( struct V_199 * V_44 )
{
struct V_11 * V_12 ;
int V_200 = 0 ;
F_18 (evlist, evsel) {
int V_126 = strlen ( F_5 ( V_12 ) ) ;
V_200 = F_57 ( V_126 , V_200 ) ;
}
return V_200 ;
}
static T_4 F_58 ( T_1 V_201 )
{
struct V_202 V_203 = { . V_201 . V_86 = V_201 } ;
char V_204 [ 100 ] ;
char V_77 [ 100 ] ;
static int V_205 ;
int V_126 ;
F_59 ( V_204 , 100 , & V_203 ) ;
V_126 = F_60 ( V_77 , 100 , L_66 V_87 L_89 , V_201 , V_204 ) ;
if ( V_205 < V_126 )
V_205 = V_126 ;
return printf ( L_90 , V_205 , V_77 ) ;
}
static void F_61 ( struct V_206 * V_207 ,
struct V_78 * V_79 , struct V_11 * V_12 ,
struct V_111 * V_127 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 = V_127 -> V_88 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_22 ( V_79 , V_88 , V_12 ) ;
if ( F_11 ( V_56 ) )
printf ( L_91 V_134 L_29 , V_79 -> V_208 ) ;
if ( F_11 ( V_209 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_207 -> V_210 )
V_207 -> V_210 = F_56 ( V_207 -> V_21 -> V_44 ) ;
printf ( L_92 , V_207 -> V_210 ,
V_18 ? V_18 : L_93 ) ;
}
if ( V_211 )
F_52 ( V_79 -> V_101 ) ;
if ( F_62 ( V_17 ) ) {
F_49 ( V_79 , V_12 , V_88 , V_127 , V_122 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_63 ( V_12 -> V_212 , V_79 -> V_95 ,
V_79 -> V_198 , V_79 -> V_197 ) ;
if ( F_11 ( V_30 ) )
F_40 ( V_79 , V_88 , V_17 ) ;
if ( F_11 ( V_33 ) )
F_58 ( V_79 -> V_201 ) ;
if ( F_11 ( V_36 ) )
printf ( L_66 V_134 , V_79 -> V_213 ) ;
if ( F_11 ( V_27 ) ) {
struct V_168 * V_169 = NULL ;
if ( V_73 . V_70 && V_79 -> V_170 &&
F_50 ( V_127 -> V_88 , & V_168 , V_12 ,
V_79 , NULL , NULL , V_171 ) == 0 )
V_169 = & V_168 ;
putchar ( V_169 ? '\n' : ' ' ) ;
F_51 ( V_79 , V_127 , 0 , V_3 [ V_17 -> type ] . V_62 , V_169 , stdout ) ;
}
if ( F_11 ( V_59 ) )
F_19 ( V_79 , V_17 ) ;
if ( F_11 ( V_214 ) )
F_26 ( V_79 ) ;
else if ( F_11 ( V_215 ) )
F_27 ( V_79 , V_88 ) ;
if ( F_64 ( V_12 ) && F_11 ( V_216 ) )
F_54 ( V_79 ) ;
F_48 ( V_79 , V_17 , V_88 , V_122 ) ;
printf ( L_50 ) ;
}
static void F_65 ( struct V_11 * V_217 , T_1 V_218 )
{
int V_219 = F_66 ( V_217 -> V_220 ) ;
int V_221 = F_67 ( V_217 ) ;
int V_95 , V_88 ;
static int V_222 ;
if ( V_217 -> V_223 )
V_219 = 1 ;
if ( ! V_222 ) {
printf ( L_94 ,
L_23 , L_95 , L_96 , L_97 , L_98 , L_22 , L_99 ) ;
V_222 = 1 ;
}
for ( V_88 = 0 ; V_88 < V_219 ; V_88 ++ ) {
for ( V_95 = 0 ; V_95 < V_221 ; V_95 ++ ) {
struct V_224 * V_225 ;
V_225 = F_68 ( V_217 -> V_225 , V_95 , V_88 ) ;
printf ( L_100 V_134 L_101 V_134 L_101 V_134 L_101 V_134 L_102 ,
V_217 -> V_226 -> V_116 [ V_95 ] ,
F_69 ( V_217 -> V_220 , V_88 ) ,
V_225 -> V_86 ,
V_225 -> V_227 ,
V_225 -> V_228 ,
V_218 ,
F_5 ( V_217 ) ) ;
}
}
}
static void F_70 ( struct V_11 * V_217 , T_1 V_218 )
{
if ( V_229 && V_229 -> F_70 )
V_229 -> F_70 ( & V_230 , V_217 , V_218 ) ;
else
F_65 ( V_217 , V_218 ) ;
}
static void F_71 ( T_1 V_218 )
{
if ( V_229 && V_229 -> F_71 )
V_229 -> F_71 ( V_218 ) ;
}
static void F_72 ( void )
{
F_73 () ;
F_74 () ;
}
static int F_75 ( void )
{
return V_229 ? V_229 -> V_231 () : 0 ;
}
static int F_76 ( void )
{
F_7 ( L_103 ) ;
return V_229 ? V_229 -> V_232 () : 0 ;
}
static int F_77 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_11 * V_12 ,
struct V_122 * V_122 )
{
struct V_206 * V_237 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_111 V_127 ;
if ( F_79 ( & V_237 -> V_238 , V_79 -> time ) )
return 0 ;
if ( V_239 ) {
if ( V_79 -> time < V_240 ) {
F_6 ( L_104 V_134
L_105 V_134 L_50 , V_240 ,
V_79 -> time ) ;
V_241 ++ ;
}
V_240 = V_79 -> time ;
return 0 ;
}
if ( F_80 ( V_122 , & V_127 , V_79 ) < 0 ) {
F_6 ( L_106 ,
V_236 -> V_22 . type ) ;
return - 1 ;
}
if ( V_127 . V_242 )
goto V_243;
if ( V_244 && ! F_81 ( V_79 -> V_95 , V_245 ) )
goto V_243;
if ( V_229 )
V_229 -> F_61 ( V_236 , V_79 , V_12 , & V_127 ) ;
else
F_61 ( V_237 , V_79 , V_12 , & V_127 , V_122 ) ;
V_243:
F_82 ( & V_127 ) ;
return 0 ;
}
static int F_83 ( struct V_233 * V_234 , union V_235 * V_236 ,
struct V_199 * * V_246 )
{
struct V_206 * V_237 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_199 * V_44 ;
struct V_11 * V_12 , * V_176 ;
int V_247 ;
V_247 = F_84 ( V_234 , V_236 , V_246 ) ;
if ( V_247 )
return V_247 ;
V_44 = * V_246 ;
V_12 = F_85 ( * V_246 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_18 (evlist, pos) {
if ( V_176 -> V_17 . type == V_12 -> V_17 . type && V_176 != V_12 )
return 0 ;
}
F_14 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_247 = F_9 ( V_12 , V_237 -> V_21 ) ;
return V_247 ;
}
static int F_86 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
int V_249 = - 1 ;
V_88 = F_88 ( V_122 , V_236 -> V_250 . V_93 , V_236 -> V_250 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_107 ) ;
return - 1 ;
}
if ( F_89 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
goto V_77;
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = 0 ;
V_79 -> V_94 = V_236 -> V_250 . V_94 ;
V_79 -> V_93 = V_236 -> V_250 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
V_249 = 0 ;
V_77:
F_91 ( V_88 ) ;
return V_249 ;
}
static int F_92 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
int V_249 = - 1 ;
V_88 = F_88 ( V_122 , V_236 -> V_252 . V_93 ,
V_236 -> V_252 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_108 ) ;
return - 1 ;
}
if ( F_93 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
goto V_77;
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = 0 ;
V_79 -> V_94 = V_236 -> V_252 . V_94 ;
V_79 -> V_93 = V_236 -> V_252 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
V_249 = 0 ;
V_77:
F_91 ( V_88 ) ;
return V_249 ;
}
static int F_94 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
if ( F_95 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
return - 1 ;
V_88 = F_88 ( V_122 , V_236 -> V_253 . V_93 , V_236 -> V_253 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_109 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = V_236 -> V_253 . time ;
V_79 -> V_94 = V_236 -> V_253 . V_94 ;
V_79 -> V_93 = V_236 -> V_253 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
F_91 ( V_88 ) ;
return 0 ;
}
static int F_96 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
int V_247 = 0 ;
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
V_88 = F_88 ( V_122 , V_236 -> V_253 . V_93 , V_236 -> V_253 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_110 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = 0 ;
V_79 -> V_94 = V_236 -> V_253 . V_94 ;
V_79 -> V_93 = V_236 -> V_253 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
if ( F_97 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
V_247 = - 1 ;
F_91 ( V_88 ) ;
return V_247 ;
}
static int F_98 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
if ( F_99 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
return - 1 ;
V_88 = F_88 ( V_122 , V_236 -> V_254 . V_93 , V_236 -> V_254 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_111 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = 0 ;
V_79 -> V_94 = V_236 -> V_254 . V_94 ;
V_79 -> V_93 = V_236 -> V_254 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
F_91 ( V_88 ) ;
return 0 ;
}
static int F_100 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
if ( F_101 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
return - 1 ;
V_88 = F_88 ( V_122 , V_236 -> V_255 . V_93 , V_236 -> V_255 . V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_112 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_251 ) {
V_79 -> V_95 = 0 ;
V_79 -> time = 0 ;
V_79 -> V_94 = V_236 -> V_255 . V_94 ;
V_79 -> V_93 = V_236 -> V_255 . V_93 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
F_91 ( V_88 ) ;
return 0 ;
}
static int F_102 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_78 * V_79 ,
struct V_122 * V_122 )
{
struct V_88 * V_88 ;
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
struct V_20 * V_21 = V_207 -> V_21 ;
struct V_11 * V_12 = F_87 ( V_21 -> V_44 , V_79 -> V_248 ) ;
if ( F_103 ( V_234 , V_236 , V_79 , V_122 ) < 0 )
return - 1 ;
V_88 = F_88 ( V_122 , V_79 -> V_93 ,
V_79 -> V_94 ) ;
if ( V_88 == NULL ) {
F_7 ( L_113 ) ;
return - 1 ;
}
F_22 ( V_79 , V_88 , V_12 ) ;
F_90 ( V_236 , stdout ) ;
F_91 ( V_88 ) ;
return 0 ;
}
static void F_104 ( int T_6 V_256 )
{
V_257 = 1 ;
}
static int F_105 ( struct V_206 * V_207 )
{
int V_249 ;
signal ( V_258 , F_104 ) ;
if ( V_207 -> V_259 ) {
V_207 -> V_234 . V_250 = F_86 ;
V_207 -> V_234 . V_253 = F_94 ;
V_207 -> V_234 . exit = F_96 ;
}
if ( V_207 -> V_260 ) {
V_207 -> V_234 . V_254 = F_98 ;
V_207 -> V_234 . V_255 = F_100 ;
}
if ( V_207 -> V_261 )
V_207 -> V_234 . V_262 = F_102 ;
if ( V_207 -> V_263 )
V_207 -> V_234 . V_252 = F_92 ;
V_249 = F_106 ( V_207 -> V_21 ) ;
if ( V_239 )
F_6 ( L_114 V_134 L_50 , V_241 ) ;
return V_249 ;
}
static struct V_264 * F_107 ( const char * V_265 ,
struct V_229 * V_266 )
{
struct V_264 * V_267 = malloc ( sizeof( * V_267 ) + strlen ( V_265 ) + 1 ) ;
if ( V_267 != NULL ) {
strcpy ( V_267 -> V_265 , V_265 ) ;
V_267 -> V_266 = V_266 ;
}
return V_267 ;
}
static void F_108 ( struct V_264 * V_267 )
{
F_109 ( & V_267 -> V_268 , & V_269 ) ;
}
static struct V_264 * F_110 ( const char * V_265 )
{
struct V_264 * V_267 ;
F_111 (s, &script_specs, node)
if ( strcasecmp ( V_267 -> V_265 , V_265 ) == 0 )
return V_267 ;
return NULL ;
}
int F_112 ( const char * V_265 , struct V_229 * V_266 )
{
struct V_264 * V_267 ;
V_267 = F_110 ( V_265 ) ;
if ( V_267 )
return - 1 ;
V_267 = F_107 ( V_265 , V_266 ) ;
if ( ! V_267 )
return - 1 ;
else
F_108 ( V_267 ) ;
return 0 ;
}
static struct V_229 * F_113 ( const char * V_265 )
{
struct V_264 * V_267 = F_110 ( V_265 ) ;
if ( ! V_267 )
return NULL ;
return V_267 -> V_266 ;
}
static void F_114 ( void )
{
struct V_264 * V_267 ;
fprintf ( V_270 , L_50 ) ;
fprintf ( V_270 , L_115
L_116 ) ;
F_111 (s, &script_specs, node)
fprintf ( V_270 , L_117 , V_267 -> V_265 , V_267 -> V_266 -> V_151 ) ;
fprintf ( V_270 , L_50 ) ;
}
static int F_115 ( const struct V_271 * T_7 V_256 ,
const char * V_10 , int T_8 V_256 )
{
char V_265 [ V_272 ] ;
const char * V_207 , * V_273 ;
int V_126 ;
if ( strcmp ( V_10 , L_118 ) == 0 ) {
F_114 () ;
exit ( 0 ) ;
}
V_207 = strchr ( V_10 , ':' ) ;
if ( V_207 ) {
V_126 = V_207 - V_10 ;
if ( V_126 >= V_272 ) {
fprintf ( V_270 , L_119 ) ;
return - 1 ;
}
strncpy ( V_265 , V_10 , V_126 ) ;
V_265 [ V_126 ] = '\0' ;
V_229 = F_113 ( V_265 ) ;
if ( ! V_229 ) {
fprintf ( V_270 , L_119 ) ;
return - 1 ;
}
V_207 ++ ;
} else {
V_207 = V_10 ;
V_273 = strrchr ( V_207 , '.' ) ;
if ( ! V_273 ) {
fprintf ( V_270 , L_120 ) ;
return - 1 ;
}
V_229 = F_113 ( ++ V_273 ) ;
if ( ! V_229 ) {
fprintf ( V_270 , L_120 ) ;
return - 1 ;
}
}
V_274 = F_116 ( V_207 ) ;
return 0 ;
}
static int F_117 ( const struct V_271 * T_7 V_256 ,
const char * V_275 , int T_8 V_256 )
{
char * V_276 , * V_277 = NULL ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_278 = 0 ;
char * V_10 = F_116 ( V_275 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_279 ;
V_276 = strchr ( V_10 , ':' ) ;
if ( V_276 ) {
* V_276 = '\0' ;
V_276 ++ ;
if ( ! strcmp ( V_10 , L_121 ) )
type = V_280 ;
else if ( ! strcmp ( V_10 , L_122 ) )
type = V_281 ;
else if ( ! strcmp ( V_10 , L_123 ) )
type = V_74 ;
else if ( ! strcmp ( V_10 , L_124 ) )
type = V_282 ;
else if ( ! strcmp ( V_10 , L_125 ) )
type = V_283 ;
else {
fprintf ( V_270 , L_126 ) ;
V_278 = - V_26 ;
goto V_77;
}
if ( V_3 [ type ] . V_4 )
F_118 ( L_127 ,
F_17 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_68 = false ;
} else {
V_276 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_270 ,
L_128 ) ;
V_278 = - V_26 ;
goto V_77;
}
if ( F_1 () )
F_118 ( L_129 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_68 = true ;
}
}
for ( V_276 = strtok_r ( V_276 , L_130 , & V_277 ) ; V_276 ; V_276 = strtok_r ( NULL , L_130 , & V_277 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_276 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_276 , L_131 ) == 0 ) {
V_211 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_270 , L_132 ) ;
V_278 = - V_26 ;
goto V_77;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_284 & V_9 [ V_7 ] . V_6 ) {
F_118 ( L_133 ,
V_9 [ V_7 ] . V_10 , F_17 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_284 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_270 , L_134 ,
V_9 [ V_7 ] . V_10 , F_17 ( type ) ) ;
V_278 = - V_26 ;
goto V_77;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_135
L_136 , F_17 ( type ) ) ;
}
}
V_77:
free ( V_10 ) ;
return V_278 ;
}
static int F_119 ( const char * V_285 , const struct V_286 * V_287 )
{
char V_288 [ V_272 ] ;
struct V_289 V_290 ;
sprintf ( V_288 , L_137 , V_285 , V_287 -> V_291 ) ;
if ( V_289 ( V_288 , & V_290 ) )
return 0 ;
return F_120 ( V_290 . V_292 ) ;
}
static struct V_293 * F_121 ( const char * V_151 )
{
struct V_293 * V_267 = F_122 ( sizeof( * V_267 ) ) ;
if ( V_267 != NULL && V_151 )
V_267 -> V_151 = F_116 ( V_151 ) ;
return V_267 ;
}
static void F_123 ( struct V_293 * V_267 )
{
F_124 ( & V_267 -> V_151 ) ;
F_124 ( & V_267 -> V_294 ) ;
F_124 ( & V_267 -> args ) ;
free ( V_267 ) ;
}
static void F_125 ( struct V_293 * V_267 )
{
F_109 ( & V_267 -> V_268 , & V_295 ) ;
}
static struct V_293 * F_126 ( const char * V_151 )
{
struct V_293 * V_267 ;
F_111 (s, &script_descs, node)
if ( strcasecmp ( V_267 -> V_151 , V_151 ) == 0 )
return V_267 ;
return NULL ;
}
static struct V_293 * F_127 ( const char * V_151 )
{
struct V_293 * V_267 = F_126 ( V_151 ) ;
if ( V_267 )
return V_267 ;
V_267 = F_121 ( V_151 ) ;
if ( ! V_267 )
goto V_296;
F_125 ( V_267 ) ;
return V_267 ;
V_296:
F_123 ( V_267 ) ;
return NULL ;
}
static const char * F_128 ( const char * V_10 , const char * V_297 )
{
T_4 V_298 = strlen ( V_297 ) ;
const char * V_299 = V_10 ;
if ( strlen ( V_10 ) > V_298 ) {
V_299 = V_10 + strlen ( V_10 ) - V_298 ;
if ( ! strncmp ( V_299 , V_297 , V_298 ) )
return V_299 ;
}
return NULL ;
}
static int F_129 ( struct V_293 * V_300 , const char * V_301 )
{
char line [ V_302 ] , * V_299 ;
T_9 * V_303 ;
V_303 = fopen ( V_301 , L_138 ) ;
if ( ! V_303 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_303 ) ) {
V_299 = F_130 ( line ) ;
if ( strlen ( V_299 ) == 0 )
continue;
if ( * V_299 != '#' )
continue;
V_299 ++ ;
if ( strlen ( V_299 ) && * V_299 == '!' )
continue;
V_299 = F_130 ( V_299 ) ;
if ( strlen ( V_299 ) && V_299 [ strlen ( V_299 ) - 1 ] == '\n' )
V_299 [ strlen ( V_299 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_299 , L_139 , strlen ( L_139 ) ) ) {
V_299 += strlen ( L_139 ) ;
V_300 -> V_294 = F_116 ( F_130 ( V_299 ) ) ;
continue;
}
if ( ! strncmp ( V_299 , L_140 , strlen ( L_140 ) ) ) {
V_299 += strlen ( L_140 ) ;
V_300 -> args = F_116 ( F_130 ( V_299 ) ) ;
continue;
}
}
fclose ( V_303 ) ;
return 0 ;
}
static char * F_131 ( struct V_286 * V_304 , const char * V_297 )
{
char * V_305 , * V_10 ;
V_305 = F_116 ( V_304 -> V_291 ) ;
if ( ! V_305 )
return NULL ;
V_10 = ( char * ) F_128 ( V_305 , V_297 ) ;
if ( ! V_10 ) {
free ( V_305 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_305 ;
}
static int F_132 ( const struct V_271 * T_7 V_256 ,
const char * V_267 V_256 ,
int T_8 V_256 )
{
struct V_286 * V_304 , * V_306 ;
char V_307 [ V_308 ] ;
T_10 * V_309 , * V_310 ;
char V_311 [ V_308 ] ;
char V_312 [ V_308 ] ;
struct V_293 * V_300 ;
char V_313 [ V_302 ] ;
char * V_305 ;
snprintf ( V_307 , V_308 , L_141 , F_133 () ) ;
V_309 = F_134 ( V_307 ) ;
if ( ! V_309 ) {
fprintf ( stdout ,
L_142
L_143 ,
V_307 ) ;
exit ( - 1 ) ;
}
F_135 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_312 , V_308 , L_144 , V_307 ,
V_306 -> V_291 ) ;
V_310 = F_134 ( V_312 ) ;
if ( ! V_310 )
continue;
F_136 (lang_path, lang_dir, script_dirent) {
V_305 = F_131 ( V_304 , V_314 ) ;
if ( V_305 ) {
V_300 = F_127 ( V_305 ) ;
snprintf ( V_311 , V_308 , L_137 ,
V_312 , V_304 -> V_291 ) ;
F_129 ( V_300 , V_311 ) ;
free ( V_305 ) ;
}
}
}
fprintf ( stdout , L_145 ) ;
F_111 (desc, &script_descs, node) {
sprintf ( V_313 , L_146 , V_300 -> V_151 ,
V_300 -> args ? V_300 -> args : L_1 ) ;
fprintf ( stdout , L_147 , V_313 ,
V_300 -> V_294 ? V_300 -> V_294 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_137 ( char * V_315 , char * V_316 ,
struct V_20 * V_21 )
{
char V_301 [ V_308 ] , V_18 [ 128 ] ;
char line [ V_302 ] , * V_299 ;
struct V_11 * V_176 ;
int V_317 , V_126 ;
T_9 * V_303 ;
sprintf ( V_301 , L_148 , V_315 , V_316 ) ;
V_303 = fopen ( V_301 , L_138 ) ;
if ( ! V_303 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_303 ) ) {
V_299 = F_130 ( line ) ;
if ( * V_299 == '#' )
continue;
while ( strlen ( V_299 ) ) {
V_299 = strstr ( V_299 , L_149 ) ;
if ( ! V_299 )
break;
V_299 += 2 ;
V_299 = F_130 ( V_299 ) ;
V_126 = strcspn ( V_299 , L_150 ) ;
if ( ! V_126 )
break;
snprintf ( V_18 , V_126 + 1 , L_151 , V_299 ) ;
V_317 = 0 ;
F_18 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_176 ) , V_18 ) ) {
V_317 = 1 ;
break;
}
}
if ( ! V_317 ) {
fclose ( V_303 ) ;
return - 1 ;
}
}
}
fclose ( V_303 ) ;
return 0 ;
}
int F_138 ( char * * V_318 , char * * V_319 )
{
struct V_286 * V_304 , * V_306 ;
char V_307 [ V_308 ] , V_312 [ V_308 ] ;
T_10 * V_309 , * V_310 ;
struct V_20 * V_21 ;
struct V_320 V_321 = {
. V_288 = V_322 ,
. V_323 = V_324 ,
} ;
char * V_325 ;
int V_7 = 0 ;
V_21 = F_139 ( & V_321 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_307 , V_308 , L_141 , F_133 () ) ;
V_309 = F_134 ( V_307 ) ;
if ( ! V_309 ) {
F_140 ( V_21 ) ;
return - 1 ;
}
F_135 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_312 , V_308 , L_137 , V_307 ,
V_306 -> V_291 ) ;
#ifdef F_141
if ( strstr ( V_312 , L_152 ) )
continue;
#endif
#ifdef F_142
if ( strstr ( V_312 , L_153 ) )
continue;
#endif
V_310 = F_134 ( V_312 ) ;
if ( ! V_310 )
continue;
F_136 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_304 -> V_291 , L_154 ) )
continue;
sprintf ( V_319 [ V_7 ] , L_137 , V_312 ,
V_304 -> V_291 ) ;
V_325 = strchr ( V_304 -> V_291 , '.' ) ;
snprintf ( V_318 [ V_7 ] ,
( V_325 - V_304 -> V_291 ) + 1 ,
L_151 , V_304 -> V_291 ) ;
if ( F_137 ( V_312 ,
V_318 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_143 ( V_310 ) ;
}
F_143 ( V_309 ) ;
F_140 ( V_21 ) ;
return V_7 ;
}
static char * F_144 ( const char * V_305 , const char * V_297 )
{
struct V_286 * V_304 , * V_306 ;
char V_307 [ V_308 ] ;
char V_311 [ V_308 ] ;
T_10 * V_309 , * V_310 ;
char V_312 [ V_308 ] ;
char * V_326 ;
snprintf ( V_307 , V_308 , L_141 , F_133 () ) ;
V_309 = F_134 ( V_307 ) ;
if ( ! V_309 )
return NULL ;
F_135 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_312 , V_308 , L_144 , V_307 ,
V_306 -> V_291 ) ;
V_310 = F_134 ( V_312 ) ;
if ( ! V_310 )
continue;
F_136 (lang_path, lang_dir, script_dirent) {
V_326 = F_131 ( V_304 , V_297 ) ;
if ( V_326 && ! strcmp ( V_305 , V_326 ) ) {
free ( V_326 ) ;
F_143 ( V_310 ) ;
F_143 ( V_309 ) ;
snprintf ( V_311 , V_308 , L_137 ,
V_312 , V_304 -> V_291 ) ;
return F_116 ( V_311 ) ;
}
free ( V_326 ) ;
}
F_143 ( V_310 ) ;
}
F_143 ( V_309 ) ;
return NULL ;
}
static bool F_145 ( const char * V_311 )
{
return F_128 ( V_311 , L_155 ) == NULL ? false : true ;
}
static int F_146 ( char * V_311 )
{
struct V_293 * V_300 ;
int V_327 = 0 ;
char * V_299 ;
V_300 = F_121 ( NULL ) ;
if ( F_129 ( V_300 , V_311 ) )
goto V_77;
if ( ! V_300 -> args )
goto V_77;
for ( V_299 = V_300 -> args ; * V_299 ; V_299 ++ )
if ( * V_299 == '<' )
V_327 ++ ;
V_77:
F_123 ( V_300 ) ;
return V_327 ;
}
static int F_147 ( int V_328 , const char * * V_329 )
{
char * * V_330 = malloc ( sizeof( const char * ) * V_328 ) ;
if ( ! V_330 ) {
F_6 ( L_156 ) ;
return - 1 ;
}
memcpy ( V_330 , V_329 , sizeof( const char * ) * V_328 ) ;
V_328 = F_148 ( V_328 , ( const char * * ) V_330 , V_331 ,
NULL , V_332 ) ;
free ( V_330 ) ;
V_223 = ( V_328 == 0 ) ;
return 0 ;
}
static void F_149 ( struct V_206 * V_207 )
{
struct V_20 * V_21 = V_207 -> V_21 ;
T_1 V_13 = F_150 ( V_21 -> V_44 ) ;
if ( V_73 . V_70 || V_73 . V_333 ) {
if ( ( V_13 & V_334 ) &&
( V_13 & V_335 ) )
V_336 . V_337 = V_338 ;
else if ( V_13 & V_339 )
V_336 . V_337 = V_340 ;
else
V_336 . V_337 = V_341 ;
}
}
static int F_151 ( struct V_233 * V_234 V_256 ,
union V_235 * V_236 ,
struct V_20 * V_21 )
{
struct V_342 * V_343 = & V_236 -> V_344 ;
struct V_11 * V_217 ;
F_18 (session->evlist, counter) {
F_152 ( & V_230 , V_217 ) ;
F_70 ( V_217 , V_343 -> time ) ;
}
F_71 ( V_343 -> time ) ;
return 0 ;
}
static int F_153 ( struct V_233 * V_234 V_256 ,
union V_235 * V_236 ,
struct V_20 * V_21 V_256 )
{
F_154 ( & V_230 , & V_236 -> V_230 ) ;
return 0 ;
}
static int F_155 ( struct V_206 * V_207 )
{
struct V_199 * V_44 = V_207 -> V_21 -> V_44 ;
if ( ! V_207 -> V_226 || ! V_207 -> V_220 )
return 0 ;
if ( F_156 ( V_207 -> V_345 , L_157 ) )
return - V_26 ;
F_157 ( V_44 , V_207 -> V_226 , V_207 -> V_220 ) ;
if ( F_158 ( V_44 , true ) )
return - V_279 ;
V_207 -> V_345 = true ;
return 0 ;
}
static
int F_159 ( struct V_233 * V_234 ,
union V_235 * V_236 ,
struct V_20 * V_21 V_256 )
{
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
if ( V_207 -> V_220 ) {
F_118 ( L_158 ) ;
return 0 ;
}
V_207 -> V_220 = F_160 ( & V_236 -> V_346 ) ;
if ( ! V_207 -> V_220 )
return - V_279 ;
return F_155 ( V_207 ) ;
}
static
int F_161 ( struct V_233 * V_234 V_256 ,
union V_235 * V_236 ,
struct V_20 * V_21 V_256 )
{
struct V_206 * V_207 = F_78 ( V_234 , struct V_206 , V_234 ) ;
if ( V_207 -> V_226 ) {
F_118 ( L_159 ) ;
return 0 ;
}
V_207 -> V_226 = F_162 ( & V_236 -> V_347 . V_136 ) ;
if ( ! V_207 -> V_226 )
return - V_279 ;
return F_155 ( V_207 ) ;
}
int F_163 ( int V_328 , const char * * V_329 )
{
bool V_348 = false ;
bool V_22 = false ;
bool V_349 = false ;
bool V_350 = false ;
char * V_351 = NULL ;
char * V_352 = NULL ;
struct V_20 * V_21 ;
struct V_353 V_353 = { . V_354 = false , } ;
char * V_311 = NULL ;
const char * * V_330 ;
int V_7 , V_1 , V_247 = 0 ;
struct V_206 V_207 = {
. V_234 = {
. V_79 = F_77 ,
. V_254 = F_99 ,
. V_255 = F_101 ,
. V_250 = F_89 ,
. V_252 = F_93 ,
. exit = F_97 ,
. V_253 = F_95 ,
. V_17 = F_83 ,
. V_355 = V_356 ,
. V_357 = V_358 ,
. V_359 = V_360 ,
. V_361 = V_362 ,
. V_363 = V_364 ,
. V_365 = V_366 ,
. V_367 = V_368 ,
. V_289 = V_369 ,
. V_344 = F_151 ,
. V_230 = F_153 ,
. V_346 = F_159 ,
. V_347 = F_161 ,
. V_370 = true ,
. V_371 = true ,
} ,
} ;
struct V_320 V_321 = {
. V_323 = V_324 ,
} ;
const struct V_271 V_372 [] = {
F_164 ( 'D' , L_160 , & V_373 ,
L_161 ) ,
F_165 ( 'v' , L_162 , & V_374 ,
L_163 ) ,
F_164 ( 'L' , L_164 , & V_92 ,
L_165 ) ,
F_166 ( 'l' , L_166 , NULL , NULL , L_167 ,
F_132 ) ,
F_167 ( 's' , L_168 , NULL , L_169 ,
L_170 ,
F_115 ) ,
F_168 ( 'g' , L_171 , & V_375 , L_118 ,
L_172 ) ,
F_168 ( 'i' , L_173 , & V_322 , L_174 , L_175 ) ,
F_164 ( 'd' , L_176 , & V_239 ,
L_177 ) ,
F_164 ( 0 , L_178 , & V_22 , L_179 ) ,
F_164 ( 0 , L_180 , & V_349 , L_181 ) ,
F_168 ( 'k' , L_182 , & V_73 . V_376 ,
L_174 , L_183 ) ,
F_168 ( 0 , L_184 , & V_73 . V_377 ,
L_174 , L_185 ) ,
F_164 ( 'G' , L_186 , & V_69 ,
L_187 ) ,
F_167 ( 0 , L_188 , NULL , L_189 ,
L_190 ,
V_378 ) ,
F_167 ( 'F' , L_191 , NULL , L_192 ,
L_193
L_194
L_195
L_196
L_197 ,
F_117 ) ,
F_164 ( 'a' , L_198 , & V_223 ,
L_199 ) ,
F_168 ( 'S' , L_200 , & V_73 . V_379 , L_201 ,
L_202 ) ,
F_168 ( 0 , L_203 , & V_73 . V_380 , L_201 ,
L_204 ) ,
F_168 ( 'C' , L_205 , & V_244 , L_205 , L_206 ) ,
F_168 ( 'c' , L_207 , & V_73 . V_381 , L_208 ,
L_209 ) ,
F_168 ( 0 , L_210 , & V_73 . V_382 , L_211 ,
L_212 ) ,
F_168 ( 0 , L_213 , & V_73 . V_383 , L_214 ,
L_215 ) ,
F_169 ( 0 , L_216 , & V_171 ,
L_217
L_218
L_219 F_170 ( V_384 ) ) ,
F_164 ( 'I' , L_220 , & V_348 ,
L_221 ) ,
F_164 ( '\0' , L_222 , & V_73 . V_385 ,
L_223 ) ,
F_164 ( '\0' , L_224 , & V_207 . V_259 ,
L_225 ) ,
F_164 ( '\0' , L_226 , & V_207 . V_260 ,
L_227 ) ,
F_164 ( '\0' , L_228 , & V_207 . V_261 ,
L_229 ) ,
F_164 ( '\0' , L_230 , & V_207 . V_263 ,
L_231 ) ,
F_164 ( 'f' , L_232 , & V_73 . V_386 , L_233 ) ,
F_171 ( 0 , L_234 , & V_153 ,
L_235 ) ,
F_164 ( 0 , L_236 , & V_97 ,
L_237 ) ,
F_172 ( 0 , L_238 , & V_353 , NULL , L_239 ,
L_240 ,
V_387 ) ,
F_164 ( 0 , L_241 , & V_388 ,
L_242 ) ,
F_164 ( 0 , L_243 , & V_73 . V_389 ,
L_244 ) ,
F_164 ( 0 , L_245 , & V_73 . V_390 ,
L_246 ) ,
F_168 ( 0 , L_247 , & V_207 . V_391 , L_192 ,
L_248 ) ,
F_164 ( 0 , L_249 , & V_73 . V_392 ,
L_250 ) ,
F_173 ()
} ;
const char * const V_393 [] = { L_251 , L_252 , NULL } ;
const char * V_394 [] = {
L_253 ,
L_254 ,
L_255 ,
L_256 ,
L_257 ,
NULL
} ;
F_72 () ;
V_328 = F_174 ( V_328 , V_329 , V_372 , V_393 , V_394 ,
V_332 ) ;
V_321 . V_288 = V_322 ;
V_321 . V_386 = V_73 . V_386 ;
if ( V_328 > 1 && ! strncmp ( V_329 [ 0 ] , L_258 , strlen ( L_258 ) ) ) {
V_351 = F_144 ( V_329 [ 1 ] , V_395 ) ;
if ( ! V_351 )
return F_175 ( V_328 , V_329 ) ;
}
if ( V_328 > 1 && ! strncmp ( V_329 [ 0 ] , L_259 , strlen ( L_259 ) ) ) {
V_352 = F_144 ( V_329 [ 1 ] , V_314 ) ;
if ( ! V_352 ) {
fprintf ( V_270 ,
L_260
L_261 ) ;
return - 1 ;
}
}
if ( V_353 . V_170 &&
V_353 . V_396 > V_171 )
V_171 = V_353 . V_396 ;
F_176 ( F_133 () ) ;
if ( V_328 && ! V_274 && ! V_351 && ! V_352 ) {
int V_397 [ 2 ] ;
int V_398 ;
T_11 V_93 ;
V_351 = F_144 ( V_329 [ 0 ] , V_395 ) ;
V_352 = F_144 ( V_329 [ 0 ] , V_314 ) ;
if ( ! V_351 && ! V_352 ) {
F_177 ( V_394 , V_372 ,
L_262
L_263 , V_329 [ 0 ] ) ;
}
if ( F_145 ( V_329 [ 0 ] ) ) {
V_398 = V_328 - 1 ;
} else {
int V_399 ;
V_398 = F_146 ( V_352 ) ;
V_399 = ( V_328 - 1 ) - V_398 ;
if ( V_399 < 0 ) {
F_177 ( V_394 , V_372 ,
L_264
L_265
L_266 , V_329 [ 0 ] ) ;
}
}
if ( F_178 ( V_397 ) < 0 ) {
perror ( L_267 ) ;
return - 1 ;
}
V_93 = V_253 () ;
if ( V_93 < 0 ) {
perror ( L_268 ) ;
return - 1 ;
}
if ( ! V_93 ) {
V_1 = 0 ;
F_179 ( V_397 [ 1 ] , 1 ) ;
F_180 ( V_397 [ 0 ] ) ;
if ( F_145 ( V_329 [ 0 ] ) ) {
V_223 = true ;
} else if ( ! V_223 ) {
if ( F_147 ( V_328 - V_398 , & V_329 [ V_398 ] ) != 0 ) {
V_247 = - 1 ;
goto V_77;
}
}
V_330 = malloc ( ( V_328 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_330 ) {
F_6 ( L_156 ) ;
V_247 = - V_279 ;
goto V_77;
}
V_330 [ V_1 ++ ] = L_269 ;
V_330 [ V_1 ++ ] = V_351 ;
if ( V_223 )
V_330 [ V_1 ++ ] = L_270 ;
V_330 [ V_1 ++ ] = L_271 ;
V_330 [ V_1 ++ ] = L_272 ;
V_330 [ V_1 ++ ] = L_273 ;
for ( V_7 = V_398 + 1 ; V_7 < V_328 ; V_7 ++ )
V_330 [ V_1 ++ ] = V_329 [ V_7 ] ;
V_330 [ V_1 ++ ] = NULL ;
F_181 ( L_269 , ( char * * ) V_330 ) ;
free ( V_330 ) ;
exit ( - 1 ) ;
}
F_179 ( V_397 [ 0 ] , 0 ) ;
F_180 ( V_397 [ 1 ] ) ;
V_330 = malloc ( ( V_328 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_330 ) {
F_6 ( L_156 ) ;
V_247 = - V_279 ;
goto V_77;
}
V_1 = 0 ;
V_330 [ V_1 ++ ] = L_269 ;
V_330 [ V_1 ++ ] = V_352 ;
for ( V_7 = 1 ; V_7 < V_398 + 1 ; V_7 ++ )
V_330 [ V_1 ++ ] = V_329 [ V_7 ] ;
V_330 [ V_1 ++ ] = L_274 ;
V_330 [ V_1 ++ ] = L_273 ;
V_330 [ V_1 ++ ] = NULL ;
F_181 ( L_269 , ( char * * ) V_330 ) ;
free ( V_330 ) ;
exit ( - 1 ) ;
}
if ( V_351 )
V_311 = V_351 ;
if ( V_352 )
V_311 = V_352 ;
if ( V_311 ) {
V_1 = 0 ;
if ( ! V_351 )
V_223 = false ;
else if ( ! V_223 ) {
if ( F_147 ( V_328 - 1 , & V_329 [ 1 ] ) != 0 ) {
V_247 = - 1 ;
goto V_77;
}
}
V_330 = malloc ( ( V_328 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_330 ) {
F_6 ( L_156 ) ;
V_247 = - V_279 ;
goto V_77;
}
V_330 [ V_1 ++ ] = L_269 ;
V_330 [ V_1 ++ ] = V_311 ;
if ( V_223 )
V_330 [ V_1 ++ ] = L_270 ;
for ( V_7 = 2 ; V_7 < V_328 ; V_7 ++ )
V_330 [ V_1 ++ ] = V_329 [ V_7 ] ;
V_330 [ V_1 ++ ] = NULL ;
F_181 ( L_269 , ( char * * ) V_330 ) ;
free ( V_330 ) ;
exit ( - 1 ) ;
}
if ( ! V_274 )
F_182 () ;
V_21 = F_139 ( & V_321 , false , & V_207 . V_234 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_349 ) {
F_183 ( V_21 , stdout , V_348 ) ;
if ( V_349 )
goto V_400;
}
if ( F_184 ( & V_21 -> V_22 . V_401 ) < 0 )
goto V_400;
V_207 . V_21 = V_21 ;
F_149 ( & V_207 ) ;
if ( V_3 [ V_280 ] . V_19 & V_402 )
V_353 . V_403 = true ;
V_21 -> V_353 = & V_353 ;
if ( V_244 ) {
V_247 = F_185 ( V_21 , V_244 , V_245 ) ;
if ( V_247 < 0 )
goto V_400;
}
if ( ! V_69 )
V_73 . V_70 = true ;
else
V_73 . V_70 = false ;
if ( V_21 -> V_404 . V_405 &&
F_186 ( V_21 -> V_404 . V_405 ,
V_406 ,
& V_21 -> V_407 . V_408 ) < 0 ) {
F_6 ( L_275 , V_409 ) ;
return - 1 ;
}
if ( V_375 ) {
struct V_289 V_410 ;
int V_411 ;
if ( F_1 () ) {
fprintf ( V_270 ,
L_276 ) ;
V_247 = - V_26 ;
goto V_400;
}
V_411 = F_187 ( V_321 . V_288 , V_412 ) ;
if ( V_411 < 0 ) {
V_247 = - V_413 ;
perror ( L_277 ) ;
goto V_400;
}
V_247 = F_188 ( V_411 , & V_410 ) ;
if ( V_247 < 0 ) {
perror ( L_278 ) ;
goto V_400;
}
if ( ! V_410 . V_414 ) {
fprintf ( V_270 , L_279 ) ;
goto V_400;
}
V_229 = F_113 ( V_375 ) ;
if ( ! V_229 ) {
fprintf ( V_270 , L_119 ) ;
V_247 = - V_415 ;
goto V_400;
}
V_247 = V_229 -> V_416 ( V_21 -> V_404 . V_405 ,
L_280 ) ;
goto V_400;
}
if ( V_274 ) {
V_247 = V_229 -> V_417 ( V_274 , V_328 , V_329 ) ;
if ( V_247 )
goto V_400;
F_7 ( L_281 , V_274 ) ;
V_350 = true ;
}
V_247 = F_15 ( V_21 ) ;
if ( V_247 < 0 )
goto V_400;
if ( F_189 ( & V_207 . V_238 , V_207 . V_391 ) != 0 ) {
F_6 ( L_282 ) ;
return - V_26 ;
}
V_247 = F_105 ( & V_207 ) ;
F_75 () ;
V_400:
F_190 ( V_21 -> V_44 ) ;
F_140 ( V_21 ) ;
if ( V_350 )
F_76 () ;
V_77:
return V_247 ;
}
