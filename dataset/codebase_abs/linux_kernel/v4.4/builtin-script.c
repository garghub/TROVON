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
V_15 = F_10 ( & V_21 -> V_22 ,
V_23 ) ;
if ( F_11 ( V_24 ) &&
! F_12 ( V_21 , L_5 ) )
return - V_25 ;
if ( F_11 ( V_26 ) ) {
if ( F_8 ( V_12 , V_27 , L_6 ,
V_28 ) )
return - V_25 ;
}
if ( F_11 ( V_29 ) &&
F_4 ( V_12 , V_30 , L_7 ,
V_31 , V_15 ) )
return - V_25 ;
if ( F_11 ( V_32 ) && ! F_11 ( V_26 ) && ! F_11 ( V_29 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_25 ;
}
if ( F_11 ( V_33 ) && ! F_11 ( V_32 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_25 ;
}
if ( F_11 ( V_34 ) && ! F_11 ( V_26 ) && ! F_11 ( V_29 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_25 ;
}
if ( F_11 ( V_35 ) && ! F_11 ( V_26 ) ) {
F_6 ( L_15
L_16 ) ;
return - V_25 ;
}
if ( ( F_11 ( V_36 ) || F_11 ( V_37 ) ) &&
F_8 ( V_12 , V_38 , L_17 ,
V_39 | V_40 ) )
return - V_25 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_41 , L_18 ,
V_42 ) )
return - V_25 ;
if ( F_11 ( V_43 ) &&
F_4 ( V_12 , V_44 , L_19 ,
V_45 , V_15 ) )
return - V_25 ;
if ( F_11 ( V_46 ) &&
F_8 ( V_12 , V_47 , L_20 ,
V_48 ) )
return - V_25 ;
if ( F_11 ( V_49 ) &&
F_8 ( V_12 , V_50 , L_21 ,
V_51 ) )
return - V_25 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_52 = 0 ;
if ( F_11 ( V_26 ) )
V_3 [ type ] . V_52 |= V_53 ;
if ( F_11 ( V_32 ) )
V_3 [ type ] . V_52 |= V_54 ;
if ( F_11 ( V_34 ) )
V_3 [ type ] . V_52 |= V_55 ;
if ( F_11 ( V_33 ) )
V_3 [ type ] . V_52 |= V_56 ;
if ( F_11 ( V_35 ) )
V_3 [ type ] . V_52 |= V_57 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_58 ) {
F_6 ( L_22
L_23 ,
F_16 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_19 &&
F_9 ( V_12 , V_21 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_13 ( & V_12 -> V_17 ) ;
}
if ( ! V_59 ) {
bool V_60 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_61 ) {
V_60 = true ;
break;
}
}
if ( ! V_60 )
V_62 . V_60 = false ;
}
if ( V_62 . V_60 &&
! V_3 [ V_63 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_63 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_64;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_61 ) {
V_3 [ V_1 ] . V_19 |= V_28 ;
V_3 [ V_1 ] . V_19 |= V_65 ;
V_3 [ V_1 ] . V_19 |= V_66 ;
F_13 ( V_17 ) ;
}
}
V_64:
return 0 ;
}
static void F_18 ( union V_67 * T_2 V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_71 V_68 ,
struct V_16 * V_17 )
{
struct V_72 * V_73 = & V_70 -> V_74 ;
T_3 V_75 = V_17 -> V_76 ;
unsigned V_7 = 0 , V_77 ;
if ( ! V_73 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_78 = V_73 -> V_73 [ V_7 ++ ] ;
printf ( L_24 V_79 L_25 , F_20 ( V_77 ) , V_78 ) ;
}
}
static void F_21 ( struct V_69 * V_70 ,
struct V_71 * V_71 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_80 ;
unsigned long V_81 ;
unsigned long long V_82 ;
if ( F_11 ( V_83 ) ) {
if ( V_84 )
printf ( L_26 , F_22 ( V_71 ) ) ;
else if ( F_11 ( V_26 ) && V_62 . V_60 )
printf ( L_27 , F_22 ( V_71 ) ) ;
else
printf ( L_28 , F_22 ( V_71 ) ) ;
}
if ( F_11 ( V_36 ) && F_11 ( V_37 ) )
printf ( L_29 , V_70 -> V_85 , V_70 -> V_86 ) ;
else if ( F_11 ( V_36 ) )
printf ( L_30 , V_70 -> V_85 ) ;
else if ( F_11 ( V_37 ) )
printf ( L_30 , V_70 -> V_86 ) ;
if ( F_11 ( V_43 ) ) {
if ( V_84 )
printf ( L_31 , V_70 -> V_87 ) ;
else
printf ( L_32 , V_70 -> V_87 ) ;
}
if ( F_11 ( TIME ) ) {
V_82 = V_70 -> time ;
V_80 = V_82 / V_88 ;
V_82 -= V_80 * V_88 ;
V_81 = V_82 / V_89 ;
if ( V_90 )
printf ( L_33 , V_80 , V_82 ) ;
else
printf ( L_34 , V_80 , V_81 ) ;
}
}
static inline char
F_23 ( struct V_91 * V_92 )
{
if ( ! ( V_92 -> V_93 . V_94 || V_92 -> V_93 . V_95 ) )
return '-' ;
return V_92 -> V_93 . V_95 ? 'P' : 'M' ;
}
static void F_24 ( union V_67 * T_2 V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_71 V_68 ,
struct V_16 * V_17 V_68 )
{
struct V_96 * V_92 = V_70 -> V_96 ;
T_1 V_7 ;
if ( ! ( V_92 && V_92 -> V_97 ) )
return;
for ( V_7 = 0 ; V_7 < V_92 -> V_97 ; V_7 ++ ) {
printf ( L_35 V_79 L_36 V_79 L_37 ,
V_92 -> V_98 [ V_7 ] . V_99 ,
V_92 -> V_98 [ V_7 ] . V_100 ,
F_23 ( V_92 -> V_98 + V_7 ) ,
V_92 -> V_98 [ V_7 ] . V_93 . V_101 ? 'X' : '-' ,
V_92 -> V_98 [ V_7 ] . V_93 . abort ? 'A' : '-' ,
V_92 -> V_98 [ V_7 ] . V_93 . V_102 ) ;
}
}
static void F_25 ( union V_67 * T_2 V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_71 V_68 ,
struct V_16 * V_17 V_68 )
{
struct V_96 * V_92 = V_70 -> V_96 ;
struct V_103 V_104 , V_105 ;
T_4 V_106 = T_2 -> V_22 . V_107 & V_108 ;
T_1 V_7 , V_99 , V_100 ;
if ( ! ( V_92 && V_92 -> V_97 ) )
return;
for ( V_7 = 0 ; V_7 < V_92 -> V_97 ; V_7 ++ ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_99 = V_92 -> V_98 [ V_7 ] . V_99 ;
V_100 = V_92 -> V_98 [ V_7 ] . V_100 ;
F_26 ( V_71 , V_106 , V_109 , V_99 , & V_104 ) ;
if ( V_104 . V_110 )
V_104 . V_111 = F_27 ( V_104 . V_110 , V_104 . V_112 , NULL ) ;
F_26 ( V_71 , V_106 , V_109 , V_100 , & V_105 ) ;
if ( V_105 . V_110 )
V_105 . V_111 = F_27 ( V_105 . V_110 , V_105 . V_112 , NULL ) ;
F_28 ( V_104 . V_111 , & V_104 , stdout ) ;
putchar ( '/' ) ;
F_28 ( V_105 . V_111 , & V_105 , stdout ) ;
printf ( L_37 ,
F_23 ( V_92 -> V_98 + V_7 ) ,
V_92 -> V_98 [ V_7 ] . V_93 . V_101 ? 'X' : '-' ,
V_92 -> V_98 [ V_7 ] . V_93 . abort ? 'A' : '-' ,
V_92 -> V_98 [ V_7 ] . V_93 . V_102 ) ;
}
}
static void F_29 ( union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_71 * V_71 ,
struct V_16 * V_17 )
{
struct V_103 V_113 ;
printf ( L_38 V_79 , V_70 -> V_112 ) ;
if ( ! F_30 ( V_17 ) )
return;
F_31 ( T_2 , V_70 , V_71 , & V_113 ) ;
if ( F_11 ( V_32 ) ) {
printf ( L_25 ) ;
if ( F_11 ( V_33 ) )
F_28 ( V_113 . V_111 , & V_113 , stdout ) ;
else
F_32 ( V_113 . V_111 , stdout ) ;
}
if ( F_11 ( V_34 ) ) {
printf ( L_39 ) ;
F_33 ( V_113 . V_110 , stdout ) ;
printf ( L_40 ) ;
}
}
static void F_34 ( union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_11 * V_12 ,
struct V_71 * V_71 ,
struct V_103 * V_113 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_114 = false ;
if ( F_11 ( V_26 ) ) {
unsigned int V_115 = V_3 [ V_17 -> type ] . V_52 ;
if ( V_62 . V_60 && V_70 -> V_116 ) {
printf ( L_41 ) ;
} else {
printf ( L_25 ) ;
if ( V_115 & V_57 ) {
V_114 = true ;
V_115 &= ~ V_57 ;
}
}
F_35 ( V_12 , V_70 , V_113 , V_115 ,
V_117 ) ;
}
if ( F_11 ( V_29 ) ||
( ( V_12 -> V_17 . V_13 & V_30 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_42 ) ;
F_29 ( T_2 , V_70 , V_71 , V_17 ) ;
}
if ( V_114 )
F_36 ( V_113 -> V_110 , V_113 -> V_112 , L_43 , stdout ) ;
printf ( L_41 ) ;
}
static void F_37 ( T_5 V_93 )
{
const char * V_118 = V_119 ;
const int V_120 = strlen ( V_119 ) ;
char V_10 [ 33 ] ;
int V_7 , V_121 = 0 ;
for ( V_7 = 0 ; V_7 < V_120 ; V_7 ++ , V_93 >>= 1 ) {
if ( V_93 & 1 )
V_10 [ V_121 ++ ] = V_118 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_93 >>= 1 ) {
if ( V_93 & 1 )
V_10 [ V_121 ++ ] = '?' ;
}
V_10 [ V_121 ] = 0 ;
printf ( L_44 , V_10 ) ;
}
static void F_38 ( union V_67 * T_2 , struct V_69 * V_70 ,
struct V_11 * V_12 , struct V_103 * V_113 )
{
struct V_71 * V_71 = V_113 -> V_71 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_70 , V_71 , V_12 ) ;
if ( F_11 ( V_46 ) )
printf ( L_45 V_122 L_25 , V_70 -> V_123 ) ;
if ( F_11 ( V_124 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
printf ( L_46 , V_18 ? V_18 : L_47 ) ;
}
if ( V_125 )
F_37 ( V_70 -> V_93 ) ;
if ( F_39 ( V_17 ) ) {
F_34 ( T_2 , V_70 , V_12 , V_71 , V_113 ) ;
return;
}
if ( F_11 ( V_24 ) )
F_40 ( V_12 -> V_126 , V_70 -> V_87 ,
V_70 -> V_127 , V_70 -> V_128 ) ;
if ( F_11 ( V_29 ) )
F_29 ( T_2 , V_70 , V_71 , V_17 ) ;
if ( F_11 ( V_26 ) ) {
if ( ! V_62 . V_60 )
printf ( L_25 ) ;
else
printf ( L_41 ) ;
F_35 ( V_12 , V_70 , V_113 ,
V_3 [ V_17 -> type ] . V_52 ,
V_117 ) ;
}
if ( F_11 ( V_49 ) )
F_18 ( T_2 , V_70 , V_71 , V_17 ) ;
if ( F_11 ( V_129 ) )
F_24 ( T_2 , V_70 , V_71 , V_17 ) ;
else if ( F_11 ( V_130 ) )
F_25 ( T_2 , V_70 , V_71 , V_17 ) ;
printf ( L_41 ) ;
}
static int F_41 ( const char * T_6 V_68 ,
int T_7 V_68 ,
const char * * T_8 V_68 )
{
return 0 ;
}
static int F_42 ( void )
{
return 0 ;
}
static int F_43 ( void )
{
return 0 ;
}
static int F_44 ( struct V_131 * V_131 V_68 ,
const char * T_9 V_68 )
{
return 0 ;
}
static void F_45 ( void )
{
F_46 () ;
F_47 () ;
V_132 = & V_133 ;
}
static int F_48 ( void )
{
return V_132 -> V_134 () ;
}
static int F_49 ( void )
{
F_7 ( L_48 ) ;
return V_132 -> V_135 () ;
}
static int F_50 ( struct V_136 * T_10 V_68 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_11 * V_12 ,
struct V_137 * V_137 )
{
struct V_103 V_113 ;
if ( V_138 ) {
if ( V_70 -> time < V_139 ) {
F_6 ( L_49 V_122
L_50 V_122 L_41 , V_139 ,
V_70 -> time ) ;
V_140 ++ ;
}
V_139 = V_70 -> time ;
return 0 ;
}
if ( F_51 ( T_2 , V_137 , & V_113 , V_70 ) < 0 ) {
F_6 ( L_51 ,
T_2 -> V_22 . type ) ;
return - 1 ;
}
if ( V_113 . V_141 )
goto V_142;
if ( V_143 && ! F_52 ( V_70 -> V_87 , V_144 ) )
goto V_142;
V_132 -> F_38 ( T_2 , V_70 , V_12 , & V_113 ) ;
V_142:
F_53 ( & V_113 ) ;
return 0 ;
}
static int F_54 ( struct V_136 * T_10 , union V_67 * T_2 ,
struct V_145 * * V_146 )
{
struct V_147 * V_148 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_145 * V_149 ;
struct V_11 * V_12 , * V_121 ;
int V_150 ;
V_150 = F_56 ( T_10 , T_2 , V_146 ) ;
if ( V_150 )
return V_150 ;
V_149 = * V_146 ;
V_12 = F_57 ( * V_146 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_121 -> V_17 . type == V_12 -> V_17 . type && V_121 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_150 = F_9 ( V_12 , V_148 -> V_21 ) ;
return V_150 ;
}
static int F_58 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
int V_152 = - 1 ;
V_71 = F_60 ( V_137 , T_2 -> V_153 . V_85 , T_2 -> V_153 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_52 ) ;
return - 1 ;
}
if ( F_61 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
goto V_64;
if ( ! V_12 -> V_17 . V_154 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_153 . V_86 ;
V_70 -> V_85 = T_2 -> V_153 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
V_152 = 0 ;
V_64:
F_63 ( V_71 ) ;
return V_152 ;
}
static int F_64 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
if ( F_65 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
return - 1 ;
V_71 = F_60 ( V_137 , T_2 -> V_155 . V_85 , T_2 -> V_155 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_53 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_154 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = T_2 -> V_155 . time ;
V_70 -> V_86 = T_2 -> V_155 . V_86 ;
V_70 -> V_85 = T_2 -> V_155 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
F_63 ( V_71 ) ;
return 0 ;
}
static int F_66 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
int V_150 = 0 ;
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
V_71 = F_60 ( V_137 , T_2 -> V_155 . V_85 , T_2 -> V_155 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_54 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_154 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_155 . V_86 ;
V_70 -> V_85 = T_2 -> V_155 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
if ( F_67 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
V_150 = - 1 ;
F_63 ( V_71 ) ;
return V_150 ;
}
static int F_68 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
if ( F_69 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
return - 1 ;
V_71 = F_60 ( V_137 , T_2 -> V_156 . V_85 , T_2 -> V_156 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_55 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_154 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_156 . V_86 ;
V_70 -> V_85 = T_2 -> V_156 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
F_63 ( V_71 ) ;
return 0 ;
}
static int F_70 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
if ( F_71 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
return - 1 ;
V_71 = F_60 ( V_137 , T_2 -> V_157 . V_85 , T_2 -> V_157 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_56 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_154 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_157 . V_86 ;
V_70 -> V_85 = T_2 -> V_157 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
F_63 ( V_71 ) ;
return 0 ;
}
static int F_72 ( struct V_136 * T_10 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_137 * V_137 )
{
struct V_71 * V_71 ;
struct V_147 * T_6 = F_55 ( T_10 , struct V_147 , T_10 ) ;
struct V_20 * V_21 = T_6 -> V_21 ;
struct V_11 * V_12 = F_59 ( V_21 -> V_149 , V_70 -> V_151 ) ;
if ( F_73 ( T_10 , T_2 , V_70 , V_137 ) < 0 )
return - 1 ;
V_71 = F_60 ( V_137 , V_70 -> V_85 ,
V_70 -> V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_57 ) ;
return - 1 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_62 ( T_2 , stdout ) ;
F_63 ( V_71 ) ;
return 0 ;
}
static void F_74 ( int T_11 V_68 )
{
V_158 = 1 ;
}
static int F_75 ( struct V_147 * T_6 )
{
int V_152 ;
signal ( V_159 , F_74 ) ;
if ( T_6 -> V_160 ) {
T_6 -> T_10 . V_153 = F_58 ;
T_6 -> T_10 . V_155 = F_64 ;
T_6 -> T_10 . exit = F_66 ;
}
if ( T_6 -> V_161 ) {
T_6 -> T_10 . V_156 = F_68 ;
T_6 -> T_10 . V_157 = F_70 ;
}
if ( T_6 -> V_162 )
T_6 -> T_10 . V_163 = F_72 ;
V_152 = F_76 ( T_6 -> V_21 ) ;
if ( V_138 )
F_6 ( L_58 V_122 L_41 , V_140 ) ;
return V_152 ;
}
static struct V_164 * F_77 ( const char * V_165 ,
struct V_132 * V_166 )
{
struct V_164 * V_167 = malloc ( sizeof( * V_167 ) + strlen ( V_165 ) + 1 ) ;
if ( V_167 != NULL ) {
strcpy ( V_167 -> V_165 , V_165 ) ;
V_167 -> V_166 = V_166 ;
}
return V_167 ;
}
static void F_78 ( struct V_164 * V_167 )
{
F_79 ( & V_167 -> V_168 , & V_169 ) ;
}
static struct V_164 * F_80 ( const char * V_165 )
{
struct V_164 * V_167 ;
F_81 (s, &script_specs, node)
if ( strcasecmp ( V_167 -> V_165 , V_165 ) == 0 )
return V_167 ;
return NULL ;
}
static struct V_164 * F_82 ( const char * V_165 ,
struct V_132 * V_166 )
{
struct V_164 * V_167 = F_80 ( V_165 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_77 ( V_165 , V_166 ) ;
if ( ! V_167 )
return NULL ;
F_78 ( V_167 ) ;
return V_167 ;
}
int F_83 ( const char * V_165 , struct V_132 * V_166 )
{
struct V_164 * V_167 ;
V_167 = F_80 ( V_165 ) ;
if ( V_167 )
return - 1 ;
V_167 = F_82 ( V_165 , V_166 ) ;
if ( ! V_167 )
return - 1 ;
return 0 ;
}
static struct V_132 * F_84 ( const char * V_165 )
{
struct V_164 * V_167 = F_80 ( V_165 ) ;
if ( ! V_167 )
return NULL ;
return V_167 -> V_166 ;
}
static void F_85 ( void )
{
struct V_164 * V_167 ;
fprintf ( V_170 , L_41 ) ;
fprintf ( V_170 , L_59
L_60 ) ;
F_81 (s, &script_specs, node)
fprintf ( V_170 , L_61 , V_167 -> V_165 , V_167 -> V_166 -> V_171 ) ;
fprintf ( V_170 , L_41 ) ;
}
static int F_86 ( const struct V_172 * T_12 V_68 ,
const char * V_10 , int T_13 V_68 )
{
char V_165 [ V_173 ] ;
const char * T_6 , * V_174 ;
int V_175 ;
if ( strcmp ( V_10 , L_62 ) == 0 ) {
F_85 () ;
exit ( 0 ) ;
}
T_6 = strchr ( V_10 , ':' ) ;
if ( T_6 ) {
V_175 = T_6 - V_10 ;
if ( V_175 >= V_173 ) {
fprintf ( V_170 , L_63 ) ;
return - 1 ;
}
strncpy ( V_165 , V_10 , V_175 ) ;
V_165 [ V_175 ] = '\0' ;
V_132 = F_84 ( V_165 ) ;
if ( ! V_132 ) {
fprintf ( V_170 , L_63 ) ;
return - 1 ;
}
T_6 ++ ;
} else {
T_6 = V_10 ;
V_174 = strrchr ( T_6 , '.' ) ;
if ( ! V_174 ) {
fprintf ( V_170 , L_64 ) ;
return - 1 ;
}
V_132 = F_84 ( ++ V_174 ) ;
if ( ! V_132 ) {
fprintf ( V_170 , L_64 ) ;
return - 1 ;
}
}
V_176 = F_87 ( T_6 ) ;
return 0 ;
}
static int F_88 ( const struct V_172 * T_12 V_68 ,
const char * V_177 , int T_13 V_68 )
{
char * V_178 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_179 = 0 ;
char * V_10 = F_87 ( V_177 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_180 ;
V_178 = strchr ( V_10 , ':' ) ;
if ( V_178 ) {
* V_178 = '\0' ;
V_178 ++ ;
if ( ! strcmp ( V_10 , L_65 ) )
type = V_181 ;
else if ( ! strcmp ( V_10 , L_66 ) )
type = V_182 ;
else if ( ! strcmp ( V_10 , L_67 ) )
type = V_63 ;
else if ( ! strcmp ( V_10 , L_68 ) )
type = V_183 ;
else {
fprintf ( V_170 , L_69 ) ;
V_179 = - V_25 ;
goto V_64;
}
if ( V_3 [ type ] . V_4 )
F_89 ( L_70 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_58 = false ;
} else {
V_178 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_170 ,
L_71 ) ;
V_179 = - V_25 ;
goto V_64;
}
if ( F_1 () )
F_89 ( L_72 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_58 = true ;
}
}
for ( V_178 = strtok ( V_178 , L_73 ) ; V_178 ; V_178 = strtok ( NULL , L_73 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_178 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_178 , L_74 ) == 0 ) {
V_125 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_170 , L_75 ) ;
V_179 = - V_25 ;
goto V_64;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_184 & V_9 [ V_7 ] . V_6 ) {
F_89 ( L_76 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_184 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_170 , L_77 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_179 = - V_25 ;
goto V_64;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_78
L_79 , F_16 ( type ) ) ;
}
}
V_64:
free ( V_10 ) ;
return V_179 ;
}
static int F_90 ( const char * V_185 , const struct V_186 * V_187 )
{
char V_188 [ V_173 ] ;
struct V_189 V_190 ;
sprintf ( V_188 , L_80 , V_185 , V_187 -> V_191 ) ;
if ( V_189 ( V_188 , & V_190 ) )
return 0 ;
return F_91 ( V_190 . V_192 ) ;
}
static struct V_193 * F_92 ( const char * V_171 )
{
struct V_193 * V_167 = F_93 ( sizeof( * V_167 ) ) ;
if ( V_167 != NULL && V_171 )
V_167 -> V_171 = F_87 ( V_171 ) ;
return V_167 ;
}
static void F_94 ( struct V_193 * V_167 )
{
F_95 ( & V_167 -> V_171 ) ;
F_95 ( & V_167 -> V_194 ) ;
F_95 ( & V_167 -> args ) ;
free ( V_167 ) ;
}
static void F_96 ( struct V_193 * V_167 )
{
F_79 ( & V_167 -> V_168 , & V_195 ) ;
}
static struct V_193 * F_97 ( const char * V_171 )
{
struct V_193 * V_167 ;
F_81 (s, &script_descs, node)
if ( strcasecmp ( V_167 -> V_171 , V_171 ) == 0 )
return V_167 ;
return NULL ;
}
static struct V_193 * F_98 ( const char * V_171 )
{
struct V_193 * V_167 = F_97 ( V_171 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_92 ( V_171 ) ;
if ( ! V_167 )
goto V_196;
F_96 ( V_167 ) ;
return V_167 ;
V_196:
F_94 ( V_167 ) ;
return NULL ;
}
static const char * F_99 ( const char * V_10 , const char * V_197 )
{
T_14 V_198 = strlen ( V_197 ) ;
const char * V_199 = V_10 ;
if ( strlen ( V_10 ) > V_198 ) {
V_199 = V_10 + strlen ( V_10 ) - V_198 ;
if ( ! strncmp ( V_199 , V_197 , V_198 ) )
return V_199 ;
}
return NULL ;
}
static int F_100 ( struct V_193 * V_200 , const char * V_201 )
{
char line [ V_202 ] , * V_199 ;
T_15 * V_203 ;
V_203 = fopen ( V_201 , L_81 ) ;
if ( ! V_203 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_203 ) ) {
V_199 = F_101 ( line ) ;
if ( strlen ( V_199 ) == 0 )
continue;
if ( * V_199 != '#' )
continue;
V_199 ++ ;
if ( strlen ( V_199 ) && * V_199 == '!' )
continue;
V_199 = F_101 ( V_199 ) ;
if ( strlen ( V_199 ) && V_199 [ strlen ( V_199 ) - 1 ] == '\n' )
V_199 [ strlen ( V_199 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_199 , L_82 , strlen ( L_82 ) ) ) {
V_199 += strlen ( L_82 ) ;
V_200 -> V_194 = F_87 ( F_101 ( V_199 ) ) ;
continue;
}
if ( ! strncmp ( V_199 , L_83 , strlen ( L_83 ) ) ) {
V_199 += strlen ( L_83 ) ;
V_200 -> args = F_87 ( F_101 ( V_199 ) ) ;
continue;
}
}
fclose ( V_203 ) ;
return 0 ;
}
static char * F_102 ( struct V_186 * V_204 , const char * V_197 )
{
char * V_205 , * V_10 ;
V_205 = F_87 ( V_204 -> V_191 ) ;
if ( ! V_205 )
return NULL ;
V_10 = ( char * ) F_99 ( V_205 , V_197 ) ;
if ( ! V_10 ) {
free ( V_205 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_205 ;
}
static int F_103 ( const struct V_172 * T_12 V_68 ,
const char * V_167 V_68 ,
int T_13 V_68 )
{
struct V_186 * V_206 , * V_207 , V_204 , V_208 ;
char V_209 [ V_210 ] ;
T_16 * V_211 , * V_212 ;
char V_213 [ V_210 ] ;
char V_214 [ V_210 ] ;
struct V_193 * V_200 ;
char V_215 [ V_202 ] ;
char * V_205 ;
snprintf ( V_209 , V_210 , L_84 , F_104 () ) ;
V_211 = F_105 ( V_209 ) ;
if ( ! V_211 )
return - 1 ;
F_106 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_214 , V_210 , L_85 , V_209 ,
V_208 . V_191 ) ;
V_212 = F_105 ( V_214 ) ;
if ( ! V_212 )
continue;
F_107 (lang_path, lang_dir, script_dirent, script_next) {
V_205 = F_102 ( & V_204 , V_216 ) ;
if ( V_205 ) {
V_200 = F_98 ( V_205 ) ;
snprintf ( V_213 , V_210 , L_80 ,
V_214 , V_204 . V_191 ) ;
F_100 ( V_200 , V_213 ) ;
free ( V_205 ) ;
}
}
}
fprintf ( stdout , L_86 ) ;
F_81 (desc, &script_descs, node) {
sprintf ( V_215 , L_87 , V_200 -> V_171 ,
V_200 -> args ? V_200 -> args : L_1 ) ;
fprintf ( stdout , L_88 , V_215 ,
V_200 -> V_194 ? V_200 -> V_194 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_108 ( char * V_217 , char * V_218 ,
struct V_20 * V_21 )
{
char V_201 [ V_210 ] , V_18 [ 128 ] ;
char line [ V_202 ] , * V_199 ;
struct V_11 * V_121 ;
int V_219 , V_175 ;
T_15 * V_203 ;
sprintf ( V_201 , L_89 , V_217 , V_218 ) ;
V_203 = fopen ( V_201 , L_81 ) ;
if ( ! V_203 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_203 ) ) {
V_199 = F_101 ( line ) ;
if ( * V_199 == '#' )
continue;
while ( strlen ( V_199 ) ) {
V_199 = strstr ( V_199 , L_90 ) ;
if ( ! V_199 )
break;
V_199 += 2 ;
V_199 = F_101 ( V_199 ) ;
V_175 = strcspn ( V_199 , L_91 ) ;
if ( ! V_175 )
break;
snprintf ( V_18 , V_175 + 1 , L_92 , V_199 ) ;
V_219 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_121 ) , V_18 ) ) {
V_219 = 1 ;
break;
}
}
if ( ! V_219 ) {
fclose ( V_203 ) ;
return - 1 ;
}
}
}
fclose ( V_203 ) ;
return 0 ;
}
int F_109 ( char * * V_220 , char * * V_221 )
{
struct V_186 * V_206 , * V_207 , V_204 , V_208 ;
char V_209 [ V_210 ] , V_214 [ V_210 ] ;
T_16 * V_211 , * V_212 ;
struct V_20 * V_21 ;
struct V_222 V_223 = {
. V_188 = V_224 ,
. V_225 = V_226 ,
} ;
char * V_227 ;
int V_7 = 0 ;
V_21 = F_110 ( & V_223 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_209 , V_210 , L_84 , F_104 () ) ;
V_211 = F_105 ( V_209 ) ;
if ( ! V_211 ) {
F_111 ( V_21 ) ;
return - 1 ;
}
F_106 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_214 , V_210 , L_80 , V_209 ,
V_208 . V_191 ) ;
#ifdef F_112
if ( strstr ( V_214 , L_93 ) )
continue;
#endif
#ifdef F_113
if ( strstr ( V_214 , L_94 ) )
continue;
#endif
V_212 = F_105 ( V_214 ) ;
if ( ! V_212 )
continue;
F_107 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_204 . V_191 , L_95 ) )
continue;
sprintf ( V_221 [ V_7 ] , L_80 , V_214 ,
V_204 . V_191 ) ;
V_227 = strchr ( V_204 . V_191 , '.' ) ;
snprintf ( V_220 [ V_7 ] ,
( V_227 - V_204 . V_191 ) + 1 ,
L_92 , V_204 . V_191 ) ;
if ( F_108 ( V_214 ,
V_220 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_114 ( V_212 ) ;
}
F_114 ( V_211 ) ;
F_111 ( V_21 ) ;
return V_7 ;
}
static char * F_115 ( const char * V_205 , const char * V_197 )
{
struct V_186 * V_206 , * V_207 , V_204 , V_208 ;
char V_209 [ V_210 ] ;
char V_213 [ V_210 ] ;
T_16 * V_211 , * V_212 ;
char V_214 [ V_210 ] ;
char * V_228 ;
snprintf ( V_209 , V_210 , L_84 , F_104 () ) ;
V_211 = F_105 ( V_209 ) ;
if ( ! V_211 )
return NULL ;
F_106 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_214 , V_210 , L_85 , V_209 ,
V_208 . V_191 ) ;
V_212 = F_105 ( V_214 ) ;
if ( ! V_212 )
continue;
F_107 (lang_path, lang_dir, script_dirent, script_next) {
V_228 = F_102 ( & V_204 , V_197 ) ;
if ( V_228 && ! strcmp ( V_205 , V_228 ) ) {
free ( V_228 ) ;
F_114 ( V_212 ) ;
F_114 ( V_211 ) ;
snprintf ( V_213 , V_210 , L_80 ,
V_214 , V_204 . V_191 ) ;
return F_87 ( V_213 ) ;
}
free ( V_228 ) ;
}
F_114 ( V_212 ) ;
}
F_114 ( V_211 ) ;
return NULL ;
}
static bool F_116 ( const char * V_213 )
{
return F_99 ( V_213 , L_96 ) == NULL ? false : true ;
}
static int F_117 ( char * V_213 )
{
struct V_193 * V_200 ;
int V_229 = 0 ;
char * V_199 ;
V_200 = F_92 ( NULL ) ;
if ( F_100 ( V_200 , V_213 ) )
goto V_64;
if ( ! V_200 -> args )
goto V_64;
for ( V_199 = V_200 -> args ; * V_199 ; V_199 ++ )
if ( * V_199 == '<' )
V_229 ++ ;
V_64:
F_94 ( V_200 ) ;
return V_229 ;
}
static int F_118 ( int T_7 , const char * * T_8 )
{
char * * V_230 = malloc ( sizeof( const char * ) * T_7 ) ;
if ( ! V_230 ) {
F_6 ( L_97 ) ;
return - 1 ;
}
memcpy ( V_230 , T_8 , sizeof( const char * ) * T_7 ) ;
T_7 = F_119 ( T_7 , ( const char * * ) V_230 , V_231 ,
NULL , V_232 ) ;
free ( V_230 ) ;
V_233 = ( T_7 == 0 ) ;
return 0 ;
}
static void F_120 ( struct V_147 * T_6 )
{
struct V_20 * V_21 = T_6 -> V_21 ;
T_1 V_13 = F_121 ( V_21 -> V_149 ) ;
if ( V_62 . V_60 || V_62 . V_234 ) {
if ( ( V_13 & V_235 ) &&
( V_13 & V_236 ) )
V_237 . V_238 = V_239 ;
else if ( V_13 & V_240 )
V_237 . V_238 = V_241 ;
else
V_237 . V_238 = V_242 ;
}
}
int F_122 ( int T_7 , const char * * T_8 , const char * T_17 V_68 )
{
bool V_243 = false ;
bool V_22 = false ;
bool V_244 = false ;
bool V_245 = false ;
char * V_246 = NULL ;
char * V_247 = NULL ;
struct V_20 * V_21 ;
struct V_248 V_248 = { . V_249 = false , } ;
char * V_213 = NULL ;
const char * * V_230 ;
int V_7 , V_1 , V_150 = 0 ;
struct V_147 T_6 = {
. T_10 = {
. V_70 = F_50 ,
. V_156 = F_69 ,
. V_157 = F_71 ,
. V_153 = F_61 ,
. exit = F_67 ,
. V_155 = F_65 ,
. V_17 = F_54 ,
. V_250 = V_251 ,
. V_252 = V_253 ,
. V_254 = V_255 ,
. V_256 = V_257 ,
. V_258 = V_259 ,
. V_260 = V_261 ,
. V_262 = true ,
. V_263 = true ,
} ,
} ;
struct V_222 V_223 = {
. V_225 = V_226 ,
} ;
const struct V_172 V_264 [] = {
F_123 ( 'D' , L_98 , & V_265 ,
L_99 ) ,
F_124 ( 'v' , L_100 , & V_266 ,
L_101 ) ,
F_123 ( 'L' , L_102 , & V_84 ,
L_103 ) ,
F_125 ( 'l' , L_104 , NULL , NULL , L_105 ,
F_103 ) ,
F_126 ( 's' , L_106 , NULL , L_107 ,
L_108 ,
F_86 ) ,
F_127 ( 'g' , L_109 , & V_267 , L_62 ,
L_110 ) ,
F_127 ( 'i' , L_111 , & V_224 , L_112 , L_113 ) ,
F_123 ( 'd' , L_114 , & V_138 ,
L_115 ) ,
F_123 ( 0 , L_116 , & V_22 , L_117 ) ,
F_123 ( 0 , L_118 , & V_244 , L_119 ) ,
F_127 ( 'k' , L_120 , & V_62 . V_268 ,
L_112 , L_121 ) ,
F_127 ( 0 , L_122 , & V_62 . V_269 ,
L_112 , L_123 ) ,
F_123 ( 'G' , L_124 , & V_59 ,
L_125 ) ,
F_127 ( 0 , L_126 , & V_62 . V_270 , L_127 ,
L_128 ) ,
F_126 ( 'F' , L_129 , NULL , L_130 ,
L_131
L_132
L_133
L_134 , F_88 ) ,
F_123 ( 'a' , L_135 , & V_233 ,
L_136 ) ,
F_127 ( 'S' , L_137 , & V_62 . V_271 , L_138 ,
L_139 ) ,
F_127 ( 'C' , L_140 , & V_143 , L_140 , L_141 ) ,
F_127 ( 'c' , L_142 , & V_62 . V_272 , L_143 ,
L_144 ) ,
F_127 ( 0 , L_145 , & V_62 . V_273 , L_146 ,
L_147 ) ,
F_127 ( 0 , L_148 , & V_62 . V_274 , L_149 ,
L_150 ) ,
F_123 ( 'I' , L_151 , & V_243 ,
L_152 ) ,
F_123 ( '\0' , L_153 , & V_62 . V_275 ,
L_154 ) ,
F_123 ( '\0' , L_155 , & T_6 . V_160 ,
L_156 ) ,
F_123 ( '\0' , L_157 , & T_6 . V_161 ,
L_158 ) ,
F_123 ( '\0' , L_159 , & T_6 . V_162 ,
L_160 ) ,
F_123 ( 'f' , L_161 , & V_223 . V_276 , L_162 ) ,
F_123 ( 0 , L_163 , & V_90 ,
L_164 ) ,
F_128 ( 0 , L_165 , & V_248 , NULL , L_166 ,
L_167 ,
V_277 ) ,
F_123 ( 0 , L_168 , & V_278 ,
L_169 ) ,
F_123 ( 0 , L_170 , & V_62 . V_279 ,
L_171 ) ,
F_123 ( 0 , L_172 , & V_62 . V_280 ,
L_173 ) ,
F_129 ()
} ;
const char * const V_281 [] = { L_174 , L_175 , NULL } ;
const char * V_282 [] = {
L_176 ,
L_177 ,
L_178 ,
L_179 ,
L_180 ,
NULL
} ;
F_45 () ;
T_7 = F_130 ( T_7 , T_8 , V_264 , V_281 , V_282 ,
V_232 ) ;
V_223 . V_188 = V_224 ;
if ( T_7 > 1 && ! strncmp ( T_8 [ 0 ] , L_181 , strlen ( L_181 ) ) ) {
V_246 = F_115 ( T_8 [ 1 ] , V_283 ) ;
if ( ! V_246 )
return F_131 ( T_7 , T_8 , NULL ) ;
}
if ( T_7 > 1 && ! strncmp ( T_8 [ 0 ] , L_182 , strlen ( L_182 ) ) ) {
V_247 = F_115 ( T_8 [ 1 ] , V_216 ) ;
if ( ! V_247 ) {
fprintf ( V_170 ,
L_183
L_184 ) ;
return - 1 ;
}
}
if ( V_248 . V_116 &&
V_248 . V_284 > V_117 )
V_117 = V_248 . V_284 ;
F_132 ( F_104 () ) ;
if ( T_7 && ! V_176 && ! V_246 && ! V_247 ) {
int V_285 [ 2 ] ;
int V_286 ;
T_18 V_85 ;
V_246 = F_115 ( T_8 [ 0 ] , V_283 ) ;
V_247 = F_115 ( T_8 [ 0 ] , V_216 ) ;
if ( ! V_246 && ! V_247 ) {
F_133 ( V_282 , V_264 ,
L_185
L_186 , T_8 [ 0 ] ) ;
}
if ( F_116 ( T_8 [ 0 ] ) ) {
V_286 = T_7 - 1 ;
} else {
int V_287 ;
V_286 = F_117 ( V_247 ) ;
V_287 = ( T_7 - 1 ) - V_286 ;
if ( V_287 < 0 ) {
F_133 ( V_282 , V_264 ,
L_187
L_188
L_189 , T_8 [ 0 ] ) ;
}
}
if ( F_134 ( V_285 ) < 0 ) {
perror ( L_190 ) ;
return - 1 ;
}
V_85 = V_155 () ;
if ( V_85 < 0 ) {
perror ( L_191 ) ;
return - 1 ;
}
if ( ! V_85 ) {
V_1 = 0 ;
F_135 ( V_285 [ 1 ] , 1 ) ;
F_136 ( V_285 [ 0 ] ) ;
if ( F_116 ( T_8 [ 0 ] ) ) {
V_233 = true ;
} else if ( ! V_233 ) {
if ( F_118 ( T_7 - V_286 , & T_8 [ V_286 ] ) != 0 ) {
V_150 = - 1 ;
goto V_64;
}
}
V_230 = malloc ( ( T_7 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_230 ) {
F_6 ( L_97 ) ;
V_150 = - V_180 ;
goto V_64;
}
V_230 [ V_1 ++ ] = L_192 ;
V_230 [ V_1 ++ ] = V_246 ;
if ( V_233 )
V_230 [ V_1 ++ ] = L_193 ;
V_230 [ V_1 ++ ] = L_194 ;
V_230 [ V_1 ++ ] = L_195 ;
V_230 [ V_1 ++ ] = L_196 ;
for ( V_7 = V_286 + 1 ; V_7 < T_7 ; V_7 ++ )
V_230 [ V_1 ++ ] = T_8 [ V_7 ] ;
V_230 [ V_1 ++ ] = NULL ;
F_137 ( L_192 , ( char * * ) V_230 ) ;
free ( V_230 ) ;
exit ( - 1 ) ;
}
F_135 ( V_285 [ 0 ] , 0 ) ;
F_136 ( V_285 [ 1 ] ) ;
V_230 = malloc ( ( T_7 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_230 ) {
F_6 ( L_97 ) ;
V_150 = - V_180 ;
goto V_64;
}
V_1 = 0 ;
V_230 [ V_1 ++ ] = L_192 ;
V_230 [ V_1 ++ ] = V_247 ;
for ( V_7 = 1 ; V_7 < V_286 + 1 ; V_7 ++ )
V_230 [ V_1 ++ ] = T_8 [ V_7 ] ;
V_230 [ V_1 ++ ] = L_197 ;
V_230 [ V_1 ++ ] = L_196 ;
V_230 [ V_1 ++ ] = NULL ;
F_137 ( L_192 , ( char * * ) V_230 ) ;
free ( V_230 ) ;
exit ( - 1 ) ;
}
if ( V_246 )
V_213 = V_246 ;
if ( V_247 )
V_213 = V_247 ;
if ( V_213 ) {
V_1 = 0 ;
if ( ! V_246 )
V_233 = false ;
else if ( ! V_233 ) {
if ( F_118 ( T_7 - 1 , & T_8 [ 1 ] ) != 0 ) {
V_150 = - 1 ;
goto V_64;
}
}
V_230 = malloc ( ( T_7 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_230 ) {
F_6 ( L_97 ) ;
V_150 = - V_180 ;
goto V_64;
}
V_230 [ V_1 ++ ] = L_192 ;
V_230 [ V_1 ++ ] = V_213 ;
if ( V_233 )
V_230 [ V_1 ++ ] = L_193 ;
for ( V_7 = 2 ; V_7 < T_7 ; V_7 ++ )
V_230 [ V_1 ++ ] = T_8 [ V_7 ] ;
V_230 [ V_1 ++ ] = NULL ;
F_137 ( L_192 , ( char * * ) V_230 ) ;
free ( V_230 ) ;
exit ( - 1 ) ;
}
if ( ! V_176 )
F_138 () ;
V_21 = F_110 ( & V_223 , false , & T_6 . T_10 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_244 ) {
F_139 ( V_21 , stdout , V_243 ) ;
if ( V_244 )
goto V_288;
}
if ( F_140 ( & V_21 -> V_22 . V_289 ) < 0 )
goto V_288;
T_6 . V_21 = V_21 ;
F_120 ( & T_6 ) ;
V_21 -> V_248 = & V_248 ;
if ( V_143 ) {
V_150 = F_141 ( V_21 , V_143 , V_144 ) ;
if ( V_150 < 0 )
goto V_288;
}
if ( ! V_59 )
V_62 . V_60 = true ;
else
V_62 . V_60 = false ;
if ( V_21 -> V_290 . V_131 &&
F_142 ( V_21 -> V_290 . V_131 ,
V_291 ,
& V_21 -> V_292 . V_293 ) < 0 ) {
F_6 ( L_198 , V_294 ) ;
return - 1 ;
}
if ( V_267 ) {
struct V_189 V_295 ;
int V_296 ;
if ( F_1 () ) {
fprintf ( V_170 ,
L_199 ) ;
V_150 = - V_25 ;
goto V_288;
}
V_296 = F_143 ( V_223 . V_188 , V_297 ) ;
if ( V_296 < 0 ) {
V_150 = - V_298 ;
perror ( L_200 ) ;
goto V_288;
}
V_150 = F_144 ( V_296 , & V_295 ) ;
if ( V_150 < 0 ) {
perror ( L_201 ) ;
goto V_288;
}
if ( ! V_295 . V_299 ) {
fprintf ( V_170 , L_202 ) ;
goto V_288;
}
V_132 = F_84 ( V_267 ) ;
if ( ! V_132 ) {
fprintf ( V_170 , L_63 ) ;
V_150 = - V_300 ;
goto V_288;
}
V_150 = V_132 -> V_301 ( V_21 -> V_290 . V_131 ,
L_203 ) ;
goto V_288;
}
if ( V_176 ) {
V_150 = V_132 -> V_302 ( V_176 , T_7 , T_8 ) ;
if ( V_150 )
goto V_288;
F_7 ( L_204 , V_176 ) ;
V_245 = true ;
}
V_150 = F_14 ( V_21 ) ;
if ( V_150 < 0 )
goto V_288;
V_150 = F_75 ( & T_6 ) ;
F_48 () ;
V_288:
F_111 ( V_21 ) ;
if ( V_245 )
F_49 () ;
V_64:
return V_150 ;
}
