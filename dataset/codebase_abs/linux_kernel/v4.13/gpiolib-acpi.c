static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
static int F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
if ( F_4 ( & V_6 -> V_10 ) )
return V_7 ;
F_5 (pin_range, &gdev->pin_ranges, node) {
const struct V_11 * V_12 = & V_9 -> V_12 ;
int V_13 ;
if ( V_12 -> V_14 ) {
for ( V_13 = 0 ; V_13 < V_12 -> V_15 ; V_13 ++ ) {
if ( V_12 -> V_14 [ V_13 ] == V_7 )
return V_12 -> V_16 + V_13 - V_6 -> V_16 ;
}
} else {
if ( V_7 >= V_12 -> V_17 &&
V_7 < V_12 -> V_17 + V_12 -> V_15 ) {
unsigned V_18 ;
V_18 = V_12 -> V_16 - V_6 -> V_16 ;
return V_18 + V_7 - V_12 -> V_17 ;
}
}
}
return - V_19 ;
}
static inline int F_3 ( struct V_5 * V_6 ,
int V_7 )
{
return V_7 ;
}
static struct V_20 * F_6 ( char * V_21 , int V_7 )
{
struct V_1 * V_22 ;
T_1 V_23 ;
T_2 V_24 ;
int V_25 ;
V_24 = F_7 ( NULL , V_21 , & V_23 ) ;
if ( F_8 ( V_24 ) )
return F_9 ( - V_26 ) ;
V_22 = F_10 ( V_23 , F_1 ) ;
if ( ! V_22 )
return F_9 ( - V_27 ) ;
V_25 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_25 < 0 )
return F_9 ( V_25 ) ;
return F_11 ( V_22 , V_25 ) ;
}
static T_3 F_12 ( int V_29 , void * V_3 )
{
struct V_30 * V_31 = V_3 ;
F_13 ( V_31 -> V_23 , NULL , NULL , NULL ) ;
return V_32 ;
}
static T_3 F_14 ( int V_29 , void * V_3 )
{
struct V_30 * V_31 = V_3 ;
F_15 ( V_31 -> V_23 , NULL , V_31 -> V_7 ) ;
return V_32 ;
}
static void F_16 ( T_1 V_23 , void * V_3 )
{
}
bool F_17 ( struct V_33 * V_34 ,
struct V_35 * * V_36 )
{
struct V_35 * V_37 ;
if ( V_34 -> type != V_38 )
return false ;
V_37 = & V_34 -> V_3 . V_37 ;
if ( V_37 -> V_39 != V_40 )
return false ;
* V_36 = V_37 ;
return true ;
}
static T_2 F_18 ( struct V_33 * V_34 ,
void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_1 * V_22 = V_43 -> V_22 ;
struct V_35 * V_36 ;
T_1 V_23 , V_44 ;
struct V_30 * V_31 ;
T_4 V_45 = NULL ;
struct V_20 * V_46 ;
unsigned long V_47 ;
int V_48 , V_7 , V_29 ;
if ( ! F_17 ( V_34 , & V_36 ) )
return V_49 ;
V_23 = F_2 ( V_22 -> V_4 ) ;
V_7 = V_36 -> V_50 [ 0 ] ;
if ( V_7 <= 255 ) {
char V_51 [ 5 ] ;
sprintf ( V_51 , L_1 ,
V_36 -> V_52 == V_53 ? 'E' : 'L' ,
V_7 ) ;
if ( F_19 ( F_7 ( V_23 , V_51 , & V_44 ) ) )
V_45 = F_12 ;
}
if ( ! V_45 ) {
if ( F_19 ( F_7 ( V_23 , L_2 , & V_44 ) ) )
V_45 = F_14 ;
}
if ( ! V_45 )
return V_49 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 )
return V_54 ;
V_46 = F_20 ( V_22 , V_7 , L_3 ) ;
if ( F_21 ( V_46 ) ) {
F_22 ( V_22 -> V_4 , L_4 ) ;
return V_55 ;
}
F_23 ( V_46 ) ;
V_48 = F_24 ( V_22 , V_7 ) ;
if ( V_48 ) {
F_22 ( V_22 -> V_4 , L_5 ) ;
goto V_56;
}
V_29 = F_25 ( V_46 ) ;
if ( V_29 < 0 ) {
F_22 ( V_22 -> V_4 , L_6 ) ;
goto V_57;
}
V_47 = V_58 ;
if ( V_36 -> V_52 == V_59 ) {
if ( V_36 -> V_60 == V_61 )
V_47 |= V_62 ;
else
V_47 |= V_63 ;
} else {
switch ( V_36 -> V_60 ) {
case V_61 :
V_47 |= V_64 ;
break;
case V_65 :
V_47 |= V_66 ;
break;
default:
V_47 |= V_64 |
V_66 ;
break;
}
}
V_31 = F_26 ( sizeof( * V_31 ) , V_67 ) ;
if ( ! V_31 )
goto V_57;
V_31 -> V_23 = V_44 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_7 = V_7 ;
V_31 -> V_46 = V_46 ;
V_48 = F_27 ( V_31 -> V_29 , NULL , V_45 , V_47 ,
L_3 , V_31 ) ;
if ( V_48 ) {
F_22 ( V_22 -> V_4 ,
L_7 ,
V_31 -> V_29 ) ;
goto V_68;
}
if ( V_36 -> V_69 == V_70 )
F_28 ( V_29 ) ;
F_29 ( & V_31 -> V_71 , & V_43 -> V_72 ) ;
return V_49 ;
V_68:
F_30 ( V_31 ) ;
V_57:
F_31 ( V_22 , V_7 ) ;
V_56:
F_32 ( V_46 ) ;
return V_55 ;
}
void F_33 ( struct V_1 * V_22 )
{
struct V_42 * V_43 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_73 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_34 ( V_23 , F_16 , ( void * * ) & V_43 ) ;
if ( F_8 ( V_24 ) )
return;
F_35 ( V_23 , L_8 ,
F_18 , V_43 ) ;
}
void F_36 ( struct V_1 * V_22 )
{
struct V_42 * V_43 ;
struct V_30 * V_31 , * V_74 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_73 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_34 ( V_23 , F_16 , ( void * * ) & V_43 ) ;
if ( F_8 ( V_24 ) )
return;
F_37 (event, ep, &acpi_gpio->events, node) {
struct V_20 * V_46 ;
if ( F_38 ( F_39 ( V_31 -> V_29 ) ) )
F_40 ( V_31 -> V_29 ) ;
F_41 ( V_31 -> V_29 , V_31 ) ;
V_46 = V_31 -> V_46 ;
if ( F_42 ( F_21 ( V_46 ) ) )
continue;
F_31 ( V_22 , V_31 -> V_7 ) ;
F_32 ( V_46 ) ;
F_43 ( & V_31 -> V_71 ) ;
F_30 ( V_31 ) ;
}
}
int F_44 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
if ( V_76 && V_78 ) {
V_76 -> V_79 = V_78 ;
return 0 ;
}
return - V_19 ;
}
static void F_45 ( struct V_80 * V_81 , void * V_82 )
{
F_46 ( F_47 ( V_81 ) ) ;
}
int F_48 ( struct V_80 * V_81 ,
const struct V_77 * V_78 )
{
void * V_82 ;
int V_48 ;
V_82 = F_49 ( F_45 , 0 , V_67 ) ;
if ( ! V_82 )
return - V_83 ;
V_48 = F_44 ( F_47 ( V_81 ) , V_78 ) ;
if ( V_48 ) {
F_50 ( V_82 ) ;
return V_48 ;
}
F_51 ( V_81 , V_82 ) ;
return 0 ;
}
void F_52 ( struct V_80 * V_81 )
{
F_42 ( F_53 ( V_81 , F_45 , NULL , NULL ) ) ;
}
static bool F_54 ( struct V_75 * V_76 ,
const char * V_84 , int V_85 ,
struct V_86 * args )
{
const struct V_77 * V_87 ;
if ( ! V_76 -> V_79 )
return false ;
for ( V_87 = V_76 -> V_79 ; V_87 -> V_84 ; V_87 ++ )
if ( ! strcmp ( V_84 , V_87 -> V_84 ) && V_87 -> V_3 && V_85 < V_87 -> V_88 ) {
const struct V_89 * V_90 = V_87 -> V_3 + V_85 ;
args -> V_76 = V_76 ;
args -> args [ 0 ] = V_90 -> V_91 ;
args -> args [ 1 ] = V_90 -> V_92 ;
args -> args [ 2 ] = V_90 -> V_93 ;
args -> V_94 = 3 ;
return true ;
}
return false ;
}
static enum V_95
F_55 ( const struct V_35 * V_36 )
{
bool V_96 = V_36 -> V_97 == V_98 ;
switch ( V_36 -> V_99 ) {
case V_100 :
return V_101 ;
case V_102 :
return V_96 ? V_103 : V_104 ;
default:
return V_105 ;
}
}
int
F_56 ( enum V_95 * V_106 , enum V_95 V_107 )
{
int V_48 = 0 ;
if ( V_107 & V_108 ) {
enum V_95 V_109 = * V_106 ^ V_107 ;
if ( ( ( * V_106 & V_108 ) && ( V_109 & V_110 ) ) ||
( ( * V_106 & V_110 ) && ( V_109 & V_111 ) ) )
V_48 = - V_19 ;
* V_106 = V_107 ;
}
return V_48 ;
}
static int F_57 ( struct V_33 * V_34 , void * V_3 )
{
struct V_112 * V_113 = V_3 ;
if ( V_34 -> type != V_38 )
return 1 ;
if ( V_113 -> V_114 ++ == V_113 -> V_85 && ! V_113 -> V_46 ) {
const struct V_35 * V_36 = & V_34 -> V_3 . V_37 ;
int V_115 = V_113 -> V_115 ;
if ( V_115 >= V_36 -> V_116 )
return 1 ;
V_113 -> V_46 = F_6 ( V_36 -> V_117 . V_118 ,
V_36 -> V_50 [ V_115 ] ) ;
V_113 -> V_119 . V_120 =
V_36 -> V_39 == V_40 ;
if ( V_113 -> V_119 . V_120 ) {
V_113 -> V_119 . V_106 = V_101 ;
V_113 -> V_119 . V_60 = V_36 -> V_60 ;
V_113 -> V_119 . V_52 = V_36 -> V_52 ;
} else {
V_113 -> V_119 . V_106 = F_55 ( V_36 ) ;
}
}
return 1 ;
}
static int F_58 ( struct V_112 * V_113 ,
struct V_121 * V_119 )
{
struct V_122 V_123 ;
int V_48 ;
F_59 ( & V_123 ) ;
V_48 = F_60 ( V_113 -> V_76 , & V_123 ,
F_57 ,
V_113 ) ;
if ( V_48 < 0 )
return V_48 ;
F_61 ( & V_123 ) ;
if ( ! V_113 -> V_46 )
return - V_124 ;
if ( V_119 ) {
* V_119 = V_113 -> V_119 ;
if ( V_113 -> V_93 )
V_119 -> V_60 = V_113 -> V_93 ;
}
return 0 ;
}
static int F_62 ( struct V_125 * V_126 ,
const char * V_127 , int V_85 ,
struct V_112 * V_113 )
{
struct V_86 args ;
int V_48 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_48 = F_63 ( V_126 , V_127 , V_85 , 3 ,
& args ) ;
if ( V_48 ) {
struct V_75 * V_76 = F_64 ( V_126 ) ;
if ( ! V_76 )
return V_48 ;
if ( ! F_54 ( V_76 , V_127 , V_85 , & args ) )
return V_48 ;
}
V_113 -> V_76 = args . V_76 ;
if ( args . V_94 != 3 )
return - V_128 ;
V_113 -> V_85 = args . args [ 0 ] ;
V_113 -> V_115 = args . args [ 1 ] ;
V_113 -> V_93 = ! ! args . args [ 2 ] ;
return 0 ;
}
static struct V_20 * F_65 ( struct V_75 * V_76 ,
const char * V_127 , int V_85 ,
struct V_121 * V_119 )
{
struct V_112 V_113 ;
int V_48 ;
if ( ! V_76 )
return F_9 ( - V_26 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_85 = V_85 ;
if ( V_127 ) {
F_66 ( & V_76 -> V_81 , L_9 , V_127 ) ;
V_48 = F_62 ( F_67 ( V_76 ) ,
V_127 , V_85 , & V_113 ) ;
if ( V_48 )
return F_9 ( V_48 ) ;
F_66 ( & V_76 -> V_81 , L_10 ,
F_68 ( & V_113 . V_76 -> V_81 ) , V_113 . V_85 ,
V_113 . V_115 , V_113 . V_93 ) ;
} else {
F_66 ( & V_76 -> V_81 , L_11 , V_85 ) ;
V_113 . V_76 = V_76 ;
}
V_48 = F_58 ( & V_113 , V_119 ) ;
return V_48 ? F_9 ( V_48 ) : V_113 . V_46 ;
}
struct V_20 * F_69 ( struct V_80 * V_81 ,
const char * V_129 ,
unsigned int V_130 ,
enum V_95 * V_131 ,
enum V_132 * V_133 )
{
struct V_75 * V_76 = F_47 ( V_81 ) ;
struct V_121 V_119 ;
struct V_20 * V_46 ;
char V_127 [ 32 ] ;
int V_134 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_70 ( V_135 ) ; V_13 ++ ) {
if ( V_129 ) {
snprintf ( V_127 , sizeof( V_127 ) , L_12 ,
V_129 , V_135 [ V_13 ] ) ;
} else {
snprintf ( V_127 , sizeof( V_127 ) , L_13 ,
V_135 [ V_13 ] ) ;
}
V_46 = F_65 ( V_76 , V_127 , V_130 , & V_119 ) ;
if ( ! F_21 ( V_46 ) )
break;
if ( F_71 ( V_46 ) == - V_27 )
return F_72 ( V_46 ) ;
}
if ( F_21 ( V_46 ) ) {
if ( ! F_73 ( V_76 , V_129 ) )
return F_9 ( - V_124 ) ;
V_46 = F_65 ( V_76 , NULL , V_130 , & V_119 ) ;
if ( F_21 ( V_46 ) )
return V_46 ;
}
if ( V_119 . V_120 &&
( * V_131 == V_104 || * V_131 == V_103 ) ) {
F_66 ( V_81 , L_14 ) ;
return F_9 ( - V_124 ) ;
}
if ( V_119 . V_60 == V_136 )
* V_133 |= V_136 ;
V_134 = F_56 ( V_131 , V_119 . V_106 ) ;
if ( V_134 )
F_66 ( V_81 , L_15 ) ;
return V_46 ;
}
struct V_20 * F_74 ( struct V_125 * V_126 ,
const char * V_127 , int V_85 ,
struct V_121 * V_119 )
{
struct V_112 V_113 ;
struct V_75 * V_76 ;
int V_48 ;
V_76 = F_64 ( V_126 ) ;
if ( V_76 )
return F_65 ( V_76 , V_127 , V_85 , V_119 ) ;
if ( ! F_75 ( V_126 ) )
return F_9 ( - V_26 ) ;
if ( ! V_127 )
return F_9 ( - V_19 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_85 = V_85 ;
V_48 = F_62 ( V_126 , V_127 , V_85 , & V_113 ) ;
if ( V_48 )
return F_9 ( V_48 ) ;
V_48 = F_58 ( & V_113 , V_119 ) ;
return V_48 ? F_9 ( V_48 ) : V_113 . V_46 ;
}
int F_76 ( struct V_75 * V_76 , int V_85 )
{
int V_130 , V_13 ;
unsigned int V_137 ;
int V_48 ;
for ( V_13 = 0 , V_130 = 0 ; V_130 <= V_85 ; V_13 ++ ) {
struct V_121 V_119 ;
struct V_20 * V_46 ;
V_46 = F_65 ( V_76 , NULL , V_13 , & V_119 ) ;
if ( F_21 ( V_46 ) && F_71 ( V_46 ) != - V_27 )
return F_71 ( V_46 ) ;
if ( V_119 . V_120 && V_130 ++ == V_85 ) {
char V_138 [ 32 ] ;
int V_29 ;
if ( F_21 ( V_46 ) )
return F_71 ( V_46 ) ;
V_29 = F_25 ( V_46 ) ;
if ( V_29 < 0 )
return V_29 ;
snprintf ( V_138 , sizeof( V_138 ) , L_16 , V_85 ) ;
V_48 = F_77 ( V_46 , V_138 , 0 , V_119 . V_106 ) ;
if ( V_48 < 0 )
return V_48 ;
V_137 = F_78 ( V_119 . V_52 ,
V_119 . V_60 ) ;
if ( V_137 != V_139 &&
V_137 != F_79 ( V_29 ) )
F_80 ( V_29 , V_137 ) ;
return V_29 ;
}
}
return - V_124 ;
}
static T_2
F_81 ( T_5 V_140 , T_6 V_141 ,
T_5 V_142 , T_7 * V_143 , void * V_144 ,
void * V_145 )
{
struct V_42 * V_146 = V_145 ;
struct V_1 * V_22 = V_146 -> V_22 ;
struct V_35 * V_36 ;
struct V_33 * V_34 ;
int V_115 = ( int ) V_141 ;
T_2 V_24 ;
int V_147 ;
int V_13 ;
V_24 = F_82 ( V_146 -> V_148 . V_149 ,
V_146 -> V_148 . V_147 , & V_34 ) ;
if ( F_8 ( V_24 ) )
return V_24 ;
if ( F_42 ( V_34 -> type != V_38 ) ) {
F_83 ( V_34 ) ;
return V_54 ;
}
V_36 = & V_34 -> V_3 . V_37 ;
if ( F_42 ( V_36 -> V_99 == V_100 &&
V_140 == V_150 ) ) {
F_83 ( V_34 ) ;
return V_54 ;
}
V_147 = F_84 ( V_36 -> V_116 , ( V_151 ) ( V_115 + V_142 ) ) ;
for ( V_13 = V_115 ; V_13 < V_147 ; ++ V_13 ) {
int V_7 = V_36 -> V_50 [ V_13 ] ;
struct V_152 * V_153 ;
struct V_20 * V_46 ;
bool V_154 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 ) {
V_24 = V_54 ;
goto V_155;
}
F_85 ( & V_146 -> V_156 ) ;
V_154 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_153 -> V_7 == V_7 ) {
V_154 = true ;
V_46 = V_153 -> V_46 ;
break;
}
}
if ( ! V_154 && V_36 -> V_157 == V_158 &&
V_140 == V_159 ) {
struct V_30 * V_31 ;
F_5 (event, &achip->events, node) {
if ( V_31 -> V_7 == V_7 ) {
V_46 = V_31 -> V_46 ;
V_154 = true ;
break;
}
}
}
if ( ! V_154 ) {
enum V_95 V_106 = F_55 ( V_36 ) ;
const char * V_138 = L_17 ;
int V_134 ;
V_46 = F_20 ( V_22 , V_7 , V_138 ) ;
if ( F_21 ( V_46 ) ) {
V_24 = V_55 ;
F_86 ( & V_146 -> V_156 ) ;
goto V_155;
}
V_134 = F_77 ( V_46 , V_138 , 0 , V_106 ) ;
if ( V_134 < 0 ) {
V_24 = V_160 ;
F_32 ( V_46 ) ;
F_86 ( & V_146 -> V_156 ) ;
goto V_155;
}
V_153 = F_26 ( sizeof( * V_153 ) , V_67 ) ;
if ( ! V_153 ) {
V_24 = V_161 ;
F_32 ( V_46 ) ;
F_86 ( & V_146 -> V_156 ) ;
goto V_155;
}
V_153 -> V_7 = V_7 ;
V_153 -> V_46 = V_46 ;
F_29 ( & V_153 -> V_71 , & V_146 -> V_162 ) ;
}
F_86 ( & V_146 -> V_156 ) ;
if ( V_140 == V_150 )
F_87 ( V_46 ,
! ! ( ( 1 << V_13 ) & * V_143 ) ) ;
else
* V_143 |= ( T_7 ) F_88 ( V_46 ) << V_13 ;
}
V_155:
F_83 ( V_34 ) ;
return V_24 ;
}
static void F_89 ( struct V_42 * V_146 )
{
struct V_1 * V_22 = V_146 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
T_2 V_24 ;
F_59 ( & V_146 -> V_162 ) ;
F_90 ( & V_146 -> V_156 ) ;
V_24 = F_91 ( V_23 , V_163 ,
F_81 ,
NULL , V_146 ) ;
if ( F_8 ( V_24 ) )
F_22 ( V_22 -> V_4 ,
L_18 ) ;
}
static void F_92 ( struct V_42 * V_146 )
{
struct V_1 * V_22 = V_146 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
struct V_152 * V_153 , * V_164 ;
T_2 V_24 ;
V_24 = F_93 ( V_23 , V_163 ,
F_81 ) ;
if ( F_8 ( V_24 ) ) {
F_22 ( V_22 -> V_4 ,
L_19 ) ;
return;
}
F_37 (conn, tmp, &achip->conns, node) {
F_32 ( V_153 -> V_46 ) ;
F_43 ( & V_153 -> V_71 ) ;
F_30 ( V_153 ) ;
}
}
static struct V_20 * F_94 (
struct V_42 * V_146 , struct V_125 * V_126 ,
const char * * V_84 , unsigned int * V_165 , unsigned int * V_131 )
{
struct V_1 * V_22 = V_146 -> V_22 ;
struct V_20 * V_46 ;
T_5 V_78 [ 2 ] ;
int V_48 ;
* V_165 = 0 ;
* V_131 = 0 ;
* V_84 = NULL ;
V_48 = F_95 ( V_126 , L_20 , V_78 ,
F_70 ( V_78 ) ) ;
if ( V_48 < 0 )
return F_9 ( V_48 ) ;
V_48 = F_3 ( V_22 -> V_28 , V_78 [ 0 ] ) ;
if ( V_48 < 0 )
return F_9 ( V_48 ) ;
V_46 = F_11 ( V_22 , V_48 ) ;
if ( F_21 ( V_46 ) )
return V_46 ;
if ( V_78 [ 1 ] )
* V_165 |= V_136 ;
if ( F_96 ( V_126 , L_21 ) )
* V_131 |= V_101 ;
else if ( F_96 ( V_126 , L_22 ) )
* V_131 |= V_104 ;
else if ( F_96 ( V_126 , L_23 ) )
* V_131 |= V_103 ;
else
return F_9 ( - V_19 ) ;
F_97 ( V_126 , L_24 , V_84 ) ;
return V_46 ;
}
static void F_98 ( struct V_42 * V_146 )
{
struct V_1 * V_22 = V_146 -> V_22 ;
struct V_125 * V_126 ;
F_99 (chip->parent, fwnode) {
unsigned int V_165 , V_131 ;
struct V_20 * V_46 ;
const char * V_84 ;
int V_48 ;
if ( ! F_96 ( V_126 , L_25 ) )
continue;
V_46 = F_94 ( V_146 , V_126 , & V_84 ,
& V_165 , & V_131 ) ;
if ( F_21 ( V_46 ) )
continue;
V_48 = F_100 ( V_46 , V_84 , V_165 , V_131 ) ;
if ( V_48 ) {
F_22 ( V_22 -> V_4 , L_26 ) ;
F_101 ( V_126 ) ;
return;
}
}
}
void F_102 ( struct V_1 * V_22 )
{
struct V_42 * V_43 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 || ! V_22 -> V_4 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_43 = F_26 ( sizeof( * V_43 ) , V_67 ) ;
if ( ! V_43 ) {
F_22 ( V_22 -> V_4 ,
L_27 ) ;
return;
}
V_43 -> V_22 = V_22 ;
F_59 ( & V_43 -> V_72 ) ;
V_24 = F_103 ( V_23 , F_16 , V_43 ) ;
if ( F_8 ( V_24 ) ) {
F_22 ( V_22 -> V_4 , L_28 ) ;
F_30 ( V_43 ) ;
return;
}
if ( ! V_22 -> V_166 )
F_104 ( V_22 ) ;
F_89 ( V_43 ) ;
F_98 ( V_43 ) ;
F_105 ( V_23 ) ;
}
void F_106 ( struct V_1 * V_22 )
{
struct V_42 * V_43 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 || ! V_22 -> V_4 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_34 ( V_23 , F_16 , ( void * * ) & V_43 ) ;
if ( F_8 ( V_24 ) ) {
F_107 ( V_22 -> V_4 , L_29 ) ;
return;
}
F_92 ( V_43 ) ;
F_108 ( V_23 , F_16 ) ;
F_30 ( V_43 ) ;
}
static int F_109 ( const union V_167 * V_168 )
{
const union V_167 * V_169 = V_168 -> V_170 . V_171 ;
const union V_167 * V_172 = V_169 + V_168 -> V_170 . V_173 ;
unsigned int V_173 = 0 ;
while ( V_169 < V_172 ) {
switch ( V_169 -> type ) {
case V_174 :
V_169 += 3 ;
case V_175 :
V_169 ++ ;
V_173 ++ ;
break;
default:
return - V_128 ;
}
}
return V_173 ;
}
static int F_110 ( struct V_33 * V_34 , void * V_3 )
{
unsigned int * V_173 = V_3 ;
if ( V_34 -> type == V_38 )
* V_173 += V_34 -> V_3 . V_37 . V_116 ;
return 1 ;
}
int F_111 ( struct V_80 * V_81 , const char * V_129 )
{
struct V_75 * V_76 = F_47 ( V_81 ) ;
const union V_167 * V_168 ;
const struct V_77 * V_87 ;
int V_173 = - V_124 ;
int V_48 ;
char V_127 [ 32 ] ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_70 ( V_135 ) ; V_13 ++ ) {
if ( V_129 )
snprintf ( V_127 , sizeof( V_127 ) , L_12 ,
V_129 , V_135 [ V_13 ] ) ;
else
snprintf ( V_127 , sizeof( V_127 ) , L_13 ,
V_135 [ V_13 ] ) ;
V_48 = F_112 ( V_76 , V_127 , V_176 ,
& V_168 ) ;
if ( V_48 == 0 ) {
if ( V_168 -> type == V_174 )
V_173 = 1 ;
else if ( V_168 -> type == V_177 )
V_173 = F_109 ( V_168 ) ;
} else if ( V_76 -> V_79 ) {
for ( V_87 = V_76 -> V_79 ; V_87 -> V_84 ; V_87 ++ )
if ( strcmp ( V_127 , V_87 -> V_84 ) == 0 ) {
V_173 = V_87 -> V_88 ;
break;
}
}
if ( V_173 > 0 )
break;
}
if ( V_173 < 0 ) {
struct V_122 V_178 ;
unsigned int V_179 = 0 ;
if ( ! F_73 ( V_76 , V_129 ) )
return V_173 ;
F_59 ( & V_178 ) ;
F_60 ( V_76 , & V_178 ,
F_110 , & V_179 ) ;
F_61 ( & V_178 ) ;
if ( V_179 > 0 )
V_173 = V_179 ;
}
return V_173 ? V_173 : - V_124 ;
}
bool F_73 ( struct V_75 * V_76 , const char * V_129 )
{
if ( V_76 -> V_3 . V_180 || V_76 -> V_79 )
return false ;
return V_129 == NULL ;
}
