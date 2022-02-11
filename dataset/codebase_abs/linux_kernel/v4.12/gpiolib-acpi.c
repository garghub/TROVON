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
static T_2 F_17 ( struct V_33 * V_34 ,
void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_1 * V_22 = V_37 -> V_22 ;
struct V_38 * V_39 ;
T_1 V_23 , V_40 ;
struct V_30 * V_31 ;
T_4 V_41 = NULL ;
struct V_20 * V_42 ;
unsigned long V_43 ;
int V_44 , V_7 , V_29 ;
if ( V_34 -> type != V_45 )
return V_46 ;
V_39 = & V_34 -> V_3 . V_47 ;
if ( V_39 -> V_48 != V_49 )
return V_46 ;
V_23 = F_2 ( V_22 -> V_4 ) ;
V_7 = V_39 -> V_50 [ 0 ] ;
if ( V_7 <= 255 ) {
char V_51 [ 5 ] ;
sprintf ( V_51 , L_1 ,
V_39 -> V_52 == V_53 ? 'E' : 'L' ,
V_7 ) ;
if ( F_18 ( F_7 ( V_23 , V_51 , & V_40 ) ) )
V_41 = F_12 ;
}
if ( ! V_41 ) {
if ( F_18 ( F_7 ( V_23 , L_2 , & V_40 ) ) )
V_41 = F_14 ;
}
if ( ! V_41 )
return V_46 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 )
return V_54 ;
V_42 = F_19 ( V_22 , V_7 , L_3 ) ;
if ( F_20 ( V_42 ) ) {
F_21 ( V_22 -> V_4 , L_4 ) ;
return V_55 ;
}
F_22 ( V_42 ) ;
V_44 = F_23 ( V_22 , V_7 ) ;
if ( V_44 ) {
F_21 ( V_22 -> V_4 , L_5 ) ;
goto V_56;
}
V_29 = F_24 ( V_42 ) ;
if ( V_29 < 0 ) {
F_21 ( V_22 -> V_4 , L_6 ) ;
goto V_57;
}
V_43 = V_58 ;
if ( V_39 -> V_52 == V_59 ) {
if ( V_39 -> V_60 == V_61 )
V_43 |= V_62 ;
else
V_43 |= V_63 ;
} else {
switch ( V_39 -> V_60 ) {
case V_61 :
V_43 |= V_64 ;
break;
case V_65 :
V_43 |= V_66 ;
break;
default:
V_43 |= V_64 |
V_66 ;
break;
}
}
V_31 = F_25 ( sizeof( * V_31 ) , V_67 ) ;
if ( ! V_31 )
goto V_57;
V_31 -> V_23 = V_40 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_7 = V_7 ;
V_31 -> V_42 = V_42 ;
V_44 = F_26 ( V_31 -> V_29 , NULL , V_41 , V_43 ,
L_3 , V_31 ) ;
if ( V_44 ) {
F_21 ( V_22 -> V_4 ,
L_7 ,
V_31 -> V_29 ) ;
goto V_68;
}
if ( V_39 -> V_69 == V_70 )
F_27 ( V_29 ) ;
F_28 ( & V_31 -> V_71 , & V_37 -> V_72 ) ;
return V_46 ;
V_68:
F_29 ( V_31 ) ;
V_57:
F_30 ( V_22 , V_7 ) ;
V_56:
F_31 ( V_42 ) ;
return V_55 ;
}
void F_32 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_73 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_33 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) )
return;
F_34 ( V_23 , L_8 ,
F_17 , V_37 ) ;
}
void F_35 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
struct V_30 * V_31 , * V_74 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_73 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_33 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) )
return;
F_36 (event, ep, &acpi_gpio->events, node) {
struct V_20 * V_42 ;
if ( F_37 ( F_38 ( V_31 -> V_29 ) ) )
F_39 ( V_31 -> V_29 ) ;
F_40 ( V_31 -> V_29 , V_31 ) ;
V_42 = V_31 -> V_42 ;
if ( F_41 ( F_20 ( V_42 ) ) )
continue;
F_30 ( V_22 , V_31 -> V_7 ) ;
F_31 ( V_42 ) ;
F_42 ( & V_31 -> V_71 ) ;
F_29 ( V_31 ) ;
}
}
int F_43 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
if ( V_76 && V_78 ) {
V_76 -> V_79 = V_78 ;
return 0 ;
}
return - V_19 ;
}
static void F_44 ( struct V_80 * V_81 , void * V_82 )
{
F_45 ( F_46 ( V_81 ) ) ;
}
int F_47 ( struct V_80 * V_81 ,
const struct V_77 * V_78 )
{
void * V_82 ;
int V_44 ;
V_82 = F_48 ( F_44 , 0 , V_67 ) ;
if ( ! V_82 )
return - V_83 ;
V_44 = F_43 ( F_46 ( V_81 ) , V_78 ) ;
if ( V_44 ) {
F_49 ( V_82 ) ;
return V_44 ;
}
F_50 ( V_81 , V_82 ) ;
return 0 ;
}
void F_51 ( struct V_80 * V_81 )
{
F_41 ( F_52 ( V_81 , F_44 , NULL , NULL ) ) ;
}
static bool F_53 ( struct V_75 * V_76 ,
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
static int F_54 ( struct V_33 * V_34 , void * V_3 )
{
struct V_95 * V_96 = V_3 ;
if ( V_34 -> type != V_45 )
return 1 ;
if ( V_96 -> V_97 ++ == V_96 -> V_85 && ! V_96 -> V_42 ) {
const struct V_38 * V_39 = & V_34 -> V_3 . V_47 ;
int V_98 = V_96 -> V_98 ;
if ( V_98 >= V_39 -> V_99 )
return 1 ;
V_96 -> V_42 = F_6 ( V_39 -> V_100 . V_101 ,
V_39 -> V_50 [ V_98 ] ) ;
V_96 -> V_102 . V_103 =
V_39 -> V_48 == V_49 ;
if ( V_96 -> V_102 . V_103 ) {
V_96 -> V_102 . V_60 = V_39 -> V_60 ;
V_96 -> V_102 . V_52 = V_39 -> V_52 ;
}
}
return 1 ;
}
static int F_55 ( struct V_95 * V_96 ,
struct V_104 * V_102 )
{
struct V_105 V_106 ;
int V_44 ;
F_56 ( & V_106 ) ;
V_44 = F_57 ( V_96 -> V_76 , & V_106 ,
F_54 ,
V_96 ) ;
if ( V_44 < 0 )
return V_44 ;
F_58 ( & V_106 ) ;
if ( ! V_96 -> V_42 )
return - V_107 ;
if ( V_102 ) {
* V_102 = V_96 -> V_102 ;
if ( V_96 -> V_93 )
V_102 -> V_60 = V_96 -> V_93 ;
}
return 0 ;
}
static int F_59 ( struct V_108 * V_109 ,
const char * V_110 , int V_85 ,
struct V_95 * V_96 )
{
struct V_86 args ;
int V_44 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_44 = F_60 ( V_109 , V_110 , V_85 , 3 ,
& args ) ;
if ( V_44 ) {
struct V_75 * V_76 = F_61 ( V_109 ) ;
if ( ! V_76 )
return V_44 ;
if ( ! F_53 ( V_76 , V_110 , V_85 , & args ) )
return V_44 ;
}
V_96 -> V_76 = args . V_76 ;
if ( args . V_94 != 3 )
return - V_111 ;
V_96 -> V_85 = args . args [ 0 ] ;
V_96 -> V_98 = args . args [ 1 ] ;
V_96 -> V_93 = ! ! args . args [ 2 ] ;
return 0 ;
}
static struct V_20 * F_62 ( struct V_75 * V_76 ,
const char * V_110 , int V_85 ,
struct V_104 * V_102 )
{
struct V_95 V_96 ;
int V_44 ;
if ( ! V_76 )
return F_9 ( - V_26 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_85 = V_85 ;
if ( V_110 ) {
F_63 ( & V_76 -> V_81 , L_9 , V_110 ) ;
V_44 = F_59 ( F_64 ( V_76 ) ,
V_110 , V_85 , & V_96 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
F_63 ( & V_76 -> V_81 , L_10 ,
F_65 ( & V_96 . V_76 -> V_81 ) , V_96 . V_85 ,
V_96 . V_98 , V_96 . V_93 ) ;
} else {
F_63 ( & V_76 -> V_81 , L_11 , V_85 ) ;
V_96 . V_76 = V_76 ;
}
V_44 = F_55 ( & V_96 , V_102 ) ;
return V_44 ? F_9 ( V_44 ) : V_96 . V_42 ;
}
struct V_20 * F_66 ( struct V_80 * V_81 ,
const char * V_112 ,
unsigned int V_113 ,
enum V_114 V_115 ,
enum V_116 * V_117 )
{
struct V_75 * V_76 = F_46 ( V_81 ) ;
struct V_104 V_102 ;
struct V_20 * V_42 ;
char V_110 [ 32 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_67 ( V_118 ) ; V_13 ++ ) {
if ( V_112 && strcmp ( V_112 , L_12 ) ) {
snprintf ( V_110 , sizeof( V_110 ) , L_13 ,
V_112 , V_118 [ V_13 ] ) ;
} else {
snprintf ( V_110 , sizeof( V_110 ) , L_14 ,
V_118 [ V_13 ] ) ;
}
V_42 = F_62 ( V_76 , V_110 , V_113 , & V_102 ) ;
if ( ! F_20 ( V_42 ) )
break;
if ( F_68 ( V_42 ) == - V_27 )
return F_69 ( V_42 ) ;
}
if ( F_20 ( V_42 ) ) {
if ( ! F_70 ( V_76 , V_112 ) )
return F_9 ( - V_107 ) ;
V_42 = F_62 ( V_76 , NULL , V_113 , & V_102 ) ;
if ( F_20 ( V_42 ) )
return V_42 ;
if ( ( V_115 == V_119 || V_115 == V_120 ) &&
V_102 . V_103 ) {
F_63 ( V_81 , L_15 ) ;
return F_9 ( - V_107 ) ;
}
}
if ( V_102 . V_60 == V_121 )
* V_117 |= V_121 ;
return V_42 ;
}
struct V_20 * F_71 ( struct V_108 * V_109 ,
const char * V_110 , int V_85 ,
struct V_104 * V_102 )
{
struct V_95 V_96 ;
struct V_75 * V_76 ;
int V_44 ;
V_76 = F_61 ( V_109 ) ;
if ( V_76 )
return F_62 ( V_76 , V_110 , V_85 , V_102 ) ;
if ( ! F_72 ( V_109 ) )
return F_9 ( - V_26 ) ;
if ( ! V_110 )
return F_9 ( - V_19 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_85 = V_85 ;
V_44 = F_59 ( V_109 , V_110 , V_85 , & V_96 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
V_44 = F_55 ( & V_96 , V_102 ) ;
return V_44 ? F_9 ( V_44 ) : V_96 . V_42 ;
}
int F_73 ( struct V_75 * V_76 , int V_85 )
{
int V_113 , V_13 ;
unsigned int V_122 ;
for ( V_13 = 0 , V_113 = 0 ; V_113 <= V_85 ; V_13 ++ ) {
struct V_104 V_102 ;
struct V_20 * V_42 ;
V_42 = F_62 ( V_76 , NULL , V_13 , & V_102 ) ;
if ( F_20 ( V_42 ) && F_68 ( V_42 ) != - V_27 )
return F_68 ( V_42 ) ;
if ( V_102 . V_103 && V_113 ++ == V_85 ) {
int V_29 ;
if ( F_20 ( V_42 ) )
return F_68 ( V_42 ) ;
V_29 = F_24 ( V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
V_122 = F_74 ( V_102 . V_52 ,
V_102 . V_60 ) ;
if ( V_122 != V_123 &&
V_122 != F_75 ( V_29 ) )
F_76 ( V_29 , V_122 ) ;
return V_29 ;
}
}
return - V_107 ;
}
static T_2
F_77 ( T_5 V_124 , T_6 V_125 ,
T_5 V_126 , T_7 * V_127 , void * V_128 ,
void * V_129 )
{
struct V_36 * V_130 = V_129 ;
struct V_1 * V_22 = V_130 -> V_22 ;
struct V_38 * V_39 ;
struct V_33 * V_34 ;
int V_98 = ( int ) V_125 ;
T_2 V_24 ;
bool V_131 ;
int V_132 ;
int V_13 ;
V_24 = F_78 ( V_130 -> V_133 . V_134 ,
V_130 -> V_133 . V_132 , & V_34 ) ;
if ( F_8 ( V_24 ) )
return V_24 ;
if ( F_41 ( V_34 -> type != V_45 ) ) {
F_79 ( V_34 ) ;
return V_54 ;
}
V_39 = & V_34 -> V_3 . V_47 ;
V_131 = V_39 -> V_135 == V_136 ;
if ( F_41 ( V_39 -> V_137 == V_138 &&
V_124 == V_139 ) ) {
F_79 ( V_34 ) ;
return V_54 ;
}
V_132 = F_80 ( V_39 -> V_99 , ( V_140 ) ( V_98 + V_126 ) ) ;
for ( V_13 = V_98 ; V_13 < V_132 ; ++ V_13 ) {
int V_7 = V_39 -> V_50 [ V_13 ] ;
struct V_141 * V_142 ;
struct V_20 * V_42 ;
bool V_143 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 ) {
V_24 = V_54 ;
goto V_144;
}
F_81 ( & V_130 -> V_145 ) ;
V_143 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_142 -> V_7 == V_7 ) {
V_143 = true ;
V_42 = V_142 -> V_42 ;
break;
}
}
if ( ! V_143 && V_39 -> V_146 == V_147 &&
V_124 == V_148 ) {
struct V_30 * V_31 ;
F_5 (event, &achip->events, node) {
if ( V_31 -> V_7 == V_7 ) {
V_42 = V_31 -> V_42 ;
V_143 = true ;
break;
}
}
}
if ( ! V_143 ) {
V_42 = F_19 ( V_22 , V_7 ,
L_16 ) ;
if ( F_20 ( V_42 ) ) {
V_24 = V_55 ;
F_82 ( & V_130 -> V_145 ) ;
goto V_144;
}
switch ( V_39 -> V_137 ) {
case V_138 :
F_22 ( V_42 ) ;
break;
case V_149 :
F_83 ( V_42 , V_131 ) ;
break;
default:
break;
}
V_142 = F_25 ( sizeof( * V_142 ) , V_67 ) ;
if ( ! V_142 ) {
V_24 = V_150 ;
F_31 ( V_42 ) ;
F_82 ( & V_130 -> V_145 ) ;
goto V_144;
}
V_142 -> V_7 = V_7 ;
V_142 -> V_42 = V_42 ;
F_28 ( & V_142 -> V_71 , & V_130 -> V_151 ) ;
}
F_82 ( & V_130 -> V_145 ) ;
if ( V_124 == V_139 )
F_84 ( V_42 ,
! ! ( ( 1 << V_13 ) & * V_127 ) ) ;
else
* V_127 |= ( T_7 ) F_85 ( V_42 ) << V_13 ;
}
V_144:
F_79 ( V_34 ) ;
return V_24 ;
}
static void F_86 ( struct V_36 * V_130 )
{
struct V_1 * V_22 = V_130 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
T_2 V_24 ;
F_56 ( & V_130 -> V_151 ) ;
F_87 ( & V_130 -> V_145 ) ;
V_24 = F_88 ( V_23 , V_152 ,
F_77 ,
NULL , V_130 ) ;
if ( F_8 ( V_24 ) )
F_21 ( V_22 -> V_4 ,
L_17 ) ;
}
static void F_89 ( struct V_36 * V_130 )
{
struct V_1 * V_22 = V_130 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
struct V_141 * V_142 , * V_153 ;
T_2 V_24 ;
V_24 = F_90 ( V_23 , V_152 ,
F_77 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 ,
L_18 ) ;
return;
}
F_36 (conn, tmp, &achip->conns, node) {
F_31 ( V_142 -> V_42 ) ;
F_42 ( & V_142 -> V_71 ) ;
F_29 ( V_142 ) ;
}
}
static struct V_20 * F_91 (
struct V_36 * V_130 , struct V_108 * V_109 ,
const char * * V_84 , unsigned int * V_154 , unsigned int * V_155 )
{
struct V_1 * V_22 = V_130 -> V_22 ;
struct V_20 * V_42 ;
T_5 V_78 [ 2 ] ;
int V_44 ;
* V_154 = 0 ;
* V_155 = 0 ;
* V_84 = NULL ;
V_44 = F_92 ( V_109 , L_12 , V_78 ,
F_67 ( V_78 ) ) ;
if ( V_44 < 0 )
return F_9 ( V_44 ) ;
V_44 = F_3 ( V_22 -> V_28 , V_78 [ 0 ] ) ;
if ( V_44 < 0 )
return F_9 ( V_44 ) ;
V_42 = F_11 ( V_22 , V_44 ) ;
if ( F_20 ( V_42 ) )
return V_42 ;
if ( V_78 [ 1 ] )
* V_154 |= V_121 ;
if ( F_93 ( V_109 , L_19 ) )
* V_155 |= V_156 ;
else if ( F_93 ( V_109 , L_20 ) )
* V_155 |= V_119 ;
else if ( F_93 ( V_109 , L_21 ) )
* V_155 |= V_120 ;
else
return F_9 ( - V_19 ) ;
F_94 ( V_109 , L_22 , V_84 ) ;
return V_42 ;
}
static void F_95 ( struct V_36 * V_130 )
{
struct V_1 * V_22 = V_130 -> V_22 ;
struct V_108 * V_109 ;
F_96 (chip->parent, fwnode) {
unsigned int V_154 , V_155 ;
struct V_20 * V_42 ;
const char * V_84 ;
int V_44 ;
if ( ! F_93 ( V_109 , L_23 ) )
continue;
V_42 = F_91 ( V_130 , V_109 , & V_84 ,
& V_154 , & V_155 ) ;
if ( F_20 ( V_42 ) )
continue;
V_44 = F_97 ( V_42 , V_84 , V_154 , V_155 ) ;
if ( V_44 ) {
F_21 ( V_22 -> V_4 , L_24 ) ;
F_98 ( V_109 ) ;
return;
}
}
}
void F_99 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 || ! V_22 -> V_4 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_37 = F_25 ( sizeof( * V_37 ) , V_67 ) ;
if ( ! V_37 ) {
F_21 ( V_22 -> V_4 ,
L_25 ) ;
return;
}
V_37 -> V_22 = V_22 ;
F_56 ( & V_37 -> V_72 ) ;
V_24 = F_100 ( V_23 , F_16 , V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 , L_26 ) ;
F_29 ( V_37 ) ;
return;
}
if ( ! V_22 -> V_157 )
F_101 ( V_22 ) ;
F_86 ( V_37 ) ;
F_95 ( V_37 ) ;
F_102 ( V_23 ) ;
}
void F_103 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 || ! V_22 -> V_4 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_33 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_104 ( V_22 -> V_4 , L_27 ) ;
return;
}
F_89 ( V_37 ) ;
F_105 ( V_23 , F_16 ) ;
F_29 ( V_37 ) ;
}
static int F_106 ( const union V_158 * V_159 )
{
const union V_158 * V_160 = V_159 -> V_161 . V_162 ;
const union V_158 * V_163 = V_160 + V_159 -> V_161 . V_164 ;
unsigned int V_164 = 0 ;
while ( V_160 < V_163 ) {
switch ( V_160 -> type ) {
case V_165 :
V_160 += 3 ;
case V_166 :
V_160 ++ ;
V_164 ++ ;
break;
default:
return - V_111 ;
}
}
return V_164 ;
}
static int F_107 ( struct V_33 * V_34 , void * V_3 )
{
unsigned int * V_164 = V_3 ;
if ( V_34 -> type == V_45 )
* V_164 += V_34 -> V_3 . V_47 . V_99 ;
return 1 ;
}
int F_108 ( struct V_80 * V_81 , const char * V_112 )
{
struct V_75 * V_76 = F_46 ( V_81 ) ;
const union V_158 * V_159 ;
const struct V_77 * V_87 ;
int V_164 = - V_107 ;
int V_44 ;
char V_110 [ 32 ] ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_67 ( V_118 ) ; V_13 ++ ) {
if ( V_112 && strcmp ( V_112 , L_12 ) )
snprintf ( V_110 , sizeof( V_110 ) , L_13 ,
V_112 , V_118 [ V_13 ] ) ;
else
snprintf ( V_110 , sizeof( V_110 ) , L_14 ,
V_118 [ V_13 ] ) ;
V_44 = F_109 ( V_76 , V_110 , V_167 ,
& V_159 ) ;
if ( V_44 == 0 ) {
if ( V_159 -> type == V_165 )
V_164 = 1 ;
else if ( V_159 -> type == V_168 )
V_164 = F_106 ( V_159 ) ;
} else if ( V_76 -> V_79 ) {
for ( V_87 = V_76 -> V_79 ; V_87 -> V_84 ; V_87 ++ )
if ( strcmp ( V_110 , V_87 -> V_84 ) == 0 ) {
V_164 = V_87 -> V_88 ;
break;
}
}
if ( V_164 > 0 )
break;
}
if ( V_164 < 0 ) {
struct V_105 V_169 ;
unsigned int V_170 = 0 ;
F_56 ( & V_169 ) ;
F_57 ( V_76 , & V_169 ,
F_107 , & V_170 ) ;
F_58 ( & V_169 ) ;
if ( V_170 > 0 )
V_164 = V_170 ;
}
return V_164 ? V_164 : - V_107 ;
}
bool F_70 ( struct V_75 * V_76 , const char * V_112 )
{
struct V_171 * V_172 , * V_96 = NULL ;
if ( V_76 -> V_3 . V_173 || V_76 -> V_79 )
return false ;
F_81 ( & V_174 ) ;
F_5 (l, &acpi_crs_lookup_list, node) {
if ( V_172 -> V_76 == V_76 ) {
V_96 = V_172 ;
break;
}
}
if ( ! V_96 ) {
V_96 = F_110 ( sizeof( * V_96 ) , V_67 ) ;
if ( V_96 ) {
V_96 -> V_76 = V_76 ;
V_96 -> V_112 = F_111 ( V_112 , V_67 ) ;
F_28 ( & V_96 -> V_71 , & V_175 ) ;
}
}
F_82 ( & V_174 ) ;
return V_96 &&
( ( ! V_96 -> V_112 && ! V_112 ) ||
( V_96 -> V_112 && V_112 &&
strcmp ( V_96 -> V_112 , V_112 ) == 0 ) ) ;
}
