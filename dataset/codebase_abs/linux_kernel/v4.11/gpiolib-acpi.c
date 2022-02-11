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
return V_54 ;
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
static bool F_44 ( struct V_75 * V_76 ,
const char * V_80 , int V_81 ,
struct V_82 * args )
{
const struct V_77 * V_83 ;
if ( ! V_76 -> V_79 )
return false ;
for ( V_83 = V_76 -> V_79 ; V_83 -> V_80 ; V_83 ++ )
if ( ! strcmp ( V_80 , V_83 -> V_80 ) && V_83 -> V_3 && V_81 < V_83 -> V_84 ) {
const struct V_85 * V_86 = V_83 -> V_3 + V_81 ;
args -> V_76 = V_76 ;
args -> args [ 0 ] = V_86 -> V_87 ;
args -> args [ 1 ] = V_86 -> V_88 ;
args -> args [ 2 ] = V_86 -> V_89 ;
args -> V_90 = 3 ;
return true ;
}
return false ;
}
static int F_45 ( struct V_33 * V_34 , void * V_3 )
{
struct V_91 * V_92 = V_3 ;
if ( V_34 -> type != V_45 )
return 1 ;
if ( V_92 -> V_93 ++ == V_92 -> V_81 && ! V_92 -> V_42 ) {
const struct V_38 * V_39 = & V_34 -> V_3 . V_47 ;
int V_94 = V_92 -> V_94 ;
if ( V_94 >= V_39 -> V_95 )
return 1 ;
V_92 -> V_42 = F_6 ( V_39 -> V_96 . V_97 ,
V_39 -> V_50 [ V_94 ] ) ;
V_92 -> V_98 . V_99 =
V_39 -> V_48 == V_49 ;
if ( V_92 -> V_98 . V_99 ) {
V_92 -> V_98 . V_60 = V_39 -> V_60 ;
V_92 -> V_98 . V_52 = V_39 -> V_52 ;
}
}
return 1 ;
}
static int F_46 ( struct V_91 * V_92 ,
struct V_100 * V_98 )
{
struct V_101 V_102 ;
int V_44 ;
F_47 ( & V_102 ) ;
V_44 = F_48 ( V_92 -> V_76 , & V_102 ,
F_45 ,
V_92 ) ;
if ( V_44 < 0 )
return V_44 ;
F_49 ( & V_102 ) ;
if ( ! V_92 -> V_42 )
return - V_103 ;
if ( V_98 ) {
* V_98 = V_92 -> V_98 ;
if ( V_92 -> V_89 )
V_98 -> V_60 = V_92 -> V_89 ;
}
return 0 ;
}
static int F_50 ( struct V_104 * V_105 ,
const char * V_106 , int V_81 ,
struct V_91 * V_92 )
{
struct V_82 args ;
int V_44 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_44 = F_51 ( V_105 , V_106 , V_81 , 3 ,
& args ) ;
if ( V_44 ) {
struct V_75 * V_76 = F_52 ( V_105 ) ;
if ( ! V_76 )
return V_44 ;
if ( ! F_44 ( V_76 , V_106 , V_81 , & args ) )
return V_44 ;
}
V_92 -> V_76 = args . V_76 ;
if ( args . V_90 != 3 )
return - V_107 ;
V_92 -> V_81 = args . args [ 0 ] ;
V_92 -> V_94 = args . args [ 1 ] ;
V_92 -> V_89 = ! ! args . args [ 2 ] ;
return 0 ;
}
static struct V_20 * F_53 ( struct V_75 * V_76 ,
const char * V_106 , int V_81 ,
struct V_100 * V_98 )
{
struct V_91 V_92 ;
int V_44 ;
if ( ! V_76 )
return F_9 ( - V_26 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_81 = V_81 ;
if ( V_106 ) {
F_54 ( & V_76 -> V_108 , L_9 , V_106 ) ;
V_44 = F_50 ( F_55 ( V_76 ) ,
V_106 , V_81 , & V_92 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
F_54 ( & V_76 -> V_108 , L_10 ,
F_56 ( & V_92 . V_76 -> V_108 ) , V_92 . V_81 ,
V_92 . V_94 , V_92 . V_89 ) ;
} else {
F_54 ( & V_76 -> V_108 , L_11 , V_81 ) ;
V_92 . V_76 = V_76 ;
}
V_44 = F_46 ( & V_92 , V_98 ) ;
return V_44 ? F_9 ( V_44 ) : V_92 . V_42 ;
}
struct V_20 * F_57 ( struct V_109 * V_108 ,
const char * V_110 ,
unsigned int V_111 ,
enum V_112 V_113 ,
enum V_114 * V_115 )
{
struct V_75 * V_76 = F_58 ( V_108 ) ;
struct V_100 V_98 ;
struct V_20 * V_42 ;
char V_106 [ 32 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_59 ( V_116 ) ; V_13 ++ ) {
if ( V_110 && strcmp ( V_110 , L_12 ) ) {
snprintf ( V_106 , sizeof( V_106 ) , L_13 ,
V_110 , V_116 [ V_13 ] ) ;
} else {
snprintf ( V_106 , sizeof( V_106 ) , L_14 ,
V_116 [ V_13 ] ) ;
}
V_42 = F_53 ( V_76 , V_106 , V_111 , & V_98 ) ;
if ( ! F_20 ( V_42 ) )
break;
if ( F_60 ( V_42 ) == - V_27 )
return F_61 ( V_42 ) ;
}
if ( F_20 ( V_42 ) ) {
if ( ! F_62 ( V_76 , V_110 ) )
return F_9 ( - V_103 ) ;
V_42 = F_53 ( V_76 , NULL , V_111 , & V_98 ) ;
if ( F_20 ( V_42 ) )
return V_42 ;
if ( ( V_113 == V_117 || V_113 == V_118 ) &&
V_98 . V_99 ) {
F_54 ( V_108 , L_15 ) ;
return F_9 ( - V_103 ) ;
}
}
if ( V_98 . V_60 == V_119 )
* V_115 |= V_119 ;
return V_42 ;
}
struct V_20 * F_63 ( struct V_104 * V_105 ,
const char * V_106 , int V_81 ,
struct V_100 * V_98 )
{
struct V_91 V_92 ;
struct V_75 * V_76 ;
int V_44 ;
V_76 = F_52 ( V_105 ) ;
if ( V_76 )
return F_53 ( V_76 , V_106 , V_81 , V_98 ) ;
if ( ! F_64 ( V_105 ) )
return F_9 ( - V_26 ) ;
if ( ! V_106 )
return F_9 ( - V_19 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_81 = V_81 ;
V_44 = F_50 ( V_105 , V_106 , V_81 , & V_92 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
V_44 = F_46 ( & V_92 , V_98 ) ;
return V_44 ? F_9 ( V_44 ) : V_92 . V_42 ;
}
int F_65 ( struct V_75 * V_76 , int V_81 )
{
int V_111 , V_13 ;
unsigned int V_120 ;
int V_44 = - V_103 ;
for ( V_13 = 0 , V_111 = 0 ; V_111 <= V_81 ; V_13 ++ ) {
struct V_100 V_98 ;
struct V_20 * V_42 ;
V_42 = F_53 ( V_76 , NULL , V_13 , & V_98 ) ;
if ( F_20 ( V_42 ) ) {
V_44 = F_60 ( V_42 ) ;
break;
}
if ( V_98 . V_99 && V_111 ++ == V_81 ) {
int V_29 = F_24 ( V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
V_120 = F_66 ( V_98 . V_52 ,
V_98 . V_60 ) ;
if ( V_120 != V_121 &&
V_120 != F_67 ( V_29 ) )
F_68 ( V_29 , V_120 ) ;
return V_29 ;
}
}
return V_44 ;
}
static T_2
F_69 ( T_5 V_122 , T_6 V_123 ,
T_5 V_124 , T_7 * V_125 , void * V_126 ,
void * V_127 )
{
struct V_36 * V_128 = V_127 ;
struct V_1 * V_22 = V_128 -> V_22 ;
struct V_38 * V_39 ;
struct V_33 * V_34 ;
int V_94 = ( int ) V_123 ;
T_2 V_24 ;
bool V_129 ;
int V_130 ;
int V_13 ;
V_24 = F_70 ( V_128 -> V_131 . V_132 ,
V_128 -> V_131 . V_130 , & V_34 ) ;
if ( F_8 ( V_24 ) )
return V_24 ;
if ( F_41 ( V_34 -> type != V_45 ) ) {
F_71 ( V_34 ) ;
return V_54 ;
}
V_39 = & V_34 -> V_3 . V_47 ;
V_129 = V_39 -> V_133 == V_134 ;
if ( F_41 ( V_39 -> V_135 == V_136 &&
V_122 == V_137 ) ) {
F_71 ( V_34 ) ;
return V_54 ;
}
V_130 = F_72 ( V_39 -> V_95 , ( V_138 ) ( V_94 + V_124 ) ) ;
for ( V_13 = V_94 ; V_13 < V_130 ; ++ V_13 ) {
int V_7 = V_39 -> V_50 [ V_13 ] ;
struct V_139 * V_140 ;
struct V_20 * V_42 ;
bool V_141 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 ) {
V_24 = V_54 ;
goto V_142;
}
F_73 ( & V_128 -> V_143 ) ;
V_141 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_140 -> V_7 == V_7 ) {
V_141 = true ;
V_42 = V_140 -> V_42 ;
break;
}
}
if ( ! V_141 && V_39 -> V_144 == V_145 &&
V_122 == V_146 ) {
struct V_30 * V_31 ;
F_5 (event, &achip->events, node) {
if ( V_31 -> V_7 == V_7 ) {
V_42 = V_31 -> V_42 ;
V_141 = true ;
break;
}
}
}
if ( ! V_141 ) {
V_42 = F_19 ( V_22 , V_7 ,
L_16 ) ;
if ( F_20 ( V_42 ) ) {
V_24 = V_55 ;
F_74 ( & V_128 -> V_143 ) ;
goto V_142;
}
switch ( V_39 -> V_135 ) {
case V_136 :
F_22 ( V_42 ) ;
break;
case V_147 :
F_75 ( V_42 , V_129 ) ;
break;
default:
break;
}
V_140 = F_25 ( sizeof( * V_140 ) , V_67 ) ;
if ( ! V_140 ) {
V_24 = V_148 ;
F_31 ( V_42 ) ;
F_74 ( & V_128 -> V_143 ) ;
goto V_142;
}
V_140 -> V_7 = V_7 ;
V_140 -> V_42 = V_42 ;
F_28 ( & V_140 -> V_71 , & V_128 -> V_149 ) ;
}
F_74 ( & V_128 -> V_143 ) ;
if ( V_122 == V_137 )
F_76 ( V_42 ,
! ! ( ( 1 << V_13 ) & * V_125 ) ) ;
else
* V_125 |= ( T_7 ) F_77 ( V_42 ) << V_13 ;
}
V_142:
F_71 ( V_34 ) ;
return V_24 ;
}
static void F_78 ( struct V_36 * V_128 )
{
struct V_1 * V_22 = V_128 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
T_2 V_24 ;
F_47 ( & V_128 -> V_149 ) ;
F_79 ( & V_128 -> V_143 ) ;
V_24 = F_80 ( V_23 , V_150 ,
F_69 ,
NULL , V_128 ) ;
if ( F_8 ( V_24 ) )
F_21 ( V_22 -> V_4 ,
L_17 ) ;
}
static void F_81 ( struct V_36 * V_128 )
{
struct V_1 * V_22 = V_128 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
struct V_139 * V_140 , * V_151 ;
T_2 V_24 ;
V_24 = F_82 ( V_23 , V_150 ,
F_69 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 ,
L_18 ) ;
return;
}
F_36 (conn, tmp, &achip->conns, node) {
F_31 ( V_140 -> V_42 ) ;
F_42 ( & V_140 -> V_71 ) ;
F_29 ( V_140 ) ;
}
}
static struct V_20 * F_83 (
struct V_36 * V_128 , struct V_104 * V_105 ,
const char * * V_80 , unsigned int * V_152 , unsigned int * V_153 )
{
struct V_1 * V_22 = V_128 -> V_22 ;
struct V_20 * V_42 ;
T_5 V_78 [ 2 ] ;
int V_44 ;
* V_152 = 0 ;
* V_153 = 0 ;
* V_80 = NULL ;
V_44 = F_84 ( V_105 , L_12 , V_78 ,
F_59 ( V_78 ) ) ;
if ( V_44 < 0 )
return F_9 ( V_44 ) ;
V_44 = F_3 ( V_22 -> V_28 , V_78 [ 0 ] ) ;
if ( V_44 < 0 )
return F_9 ( V_44 ) ;
V_42 = F_11 ( V_22 , V_44 ) ;
if ( F_20 ( V_42 ) )
return V_42 ;
if ( V_78 [ 1 ] )
* V_152 |= V_119 ;
if ( F_85 ( V_105 , L_19 ) )
* V_153 |= V_154 ;
else if ( F_85 ( V_105 , L_20 ) )
* V_153 |= V_117 ;
else if ( F_85 ( V_105 , L_21 ) )
* V_153 |= V_118 ;
else
return F_9 ( - V_19 ) ;
F_86 ( V_105 , L_22 , V_80 ) ;
return V_42 ;
}
static void F_87 ( struct V_36 * V_128 )
{
struct V_1 * V_22 = V_128 -> V_22 ;
struct V_104 * V_105 ;
F_88 (chip->parent, fwnode) {
unsigned int V_152 , V_153 ;
struct V_20 * V_42 ;
const char * V_80 ;
int V_44 ;
if ( ! F_85 ( V_105 , L_23 ) )
continue;
V_42 = F_83 ( V_128 , V_105 , & V_80 ,
& V_152 , & V_153 ) ;
if ( F_20 ( V_42 ) )
continue;
V_44 = F_89 ( V_42 , V_80 , V_152 , V_153 ) ;
if ( V_44 ) {
F_21 ( V_22 -> V_4 , L_24 ) ;
F_90 ( V_105 ) ;
return;
}
}
}
void F_91 ( struct V_1 * V_22 )
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
F_47 ( & V_37 -> V_72 ) ;
V_24 = F_92 ( V_23 , F_16 , V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 , L_26 ) ;
F_29 ( V_37 ) ;
return;
}
if ( ! V_22 -> V_155 )
F_93 ( V_22 ) ;
F_78 ( V_37 ) ;
F_87 ( V_37 ) ;
F_94 ( V_23 ) ;
}
void F_95 ( struct V_1 * V_22 )
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
F_96 ( V_22 -> V_4 , L_27 ) ;
return;
}
F_81 ( V_37 ) ;
F_97 ( V_23 , F_16 ) ;
F_29 ( V_37 ) ;
}
static int F_98 ( const union V_156 * V_157 )
{
const union V_156 * V_158 = V_157 -> V_159 . V_160 ;
const union V_156 * V_161 = V_158 + V_157 -> V_159 . V_162 ;
unsigned int V_162 = 0 ;
while ( V_158 < V_161 ) {
switch ( V_158 -> type ) {
case V_163 :
V_158 += 3 ;
case V_164 :
V_158 ++ ;
V_162 ++ ;
break;
default:
return - V_107 ;
}
}
return V_162 ;
}
static int F_99 ( struct V_33 * V_34 , void * V_3 )
{
unsigned int * V_162 = V_3 ;
if ( V_34 -> type == V_45 )
* V_162 += V_34 -> V_3 . V_47 . V_95 ;
return 1 ;
}
int F_100 ( struct V_109 * V_108 , const char * V_110 )
{
struct V_75 * V_76 = F_58 ( V_108 ) ;
const union V_156 * V_157 ;
const struct V_77 * V_83 ;
int V_162 = - V_103 ;
int V_44 ;
char V_106 [ 32 ] ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_59 ( V_116 ) ; V_13 ++ ) {
if ( V_110 && strcmp ( V_110 , L_12 ) )
snprintf ( V_106 , sizeof( V_106 ) , L_13 ,
V_110 , V_116 [ V_13 ] ) ;
else
snprintf ( V_106 , sizeof( V_106 ) , L_14 ,
V_116 [ V_13 ] ) ;
V_44 = F_101 ( V_76 , V_106 , V_165 ,
& V_157 ) ;
if ( V_44 == 0 ) {
if ( V_157 -> type == V_163 )
V_162 = 1 ;
else if ( V_157 -> type == V_166 )
V_162 = F_98 ( V_157 ) ;
} else if ( V_76 -> V_79 ) {
for ( V_83 = V_76 -> V_79 ; V_83 -> V_80 ; V_83 ++ )
if ( strcmp ( V_106 , V_83 -> V_80 ) == 0 ) {
V_162 = V_83 -> V_84 ;
break;
}
}
if ( V_162 >= 0 )
break;
}
if ( V_162 < 0 ) {
struct V_101 V_167 ;
unsigned int V_168 = 0 ;
F_47 ( & V_167 ) ;
F_48 ( V_76 , & V_167 ,
F_99 , & V_168 ) ;
F_49 ( & V_167 ) ;
if ( V_168 > 0 )
V_162 = V_168 ;
}
return V_162 ;
}
bool F_62 ( struct V_75 * V_76 , const char * V_110 )
{
struct V_169 * V_170 , * V_92 = NULL ;
if ( V_76 -> V_3 . V_171 || V_76 -> V_79 )
return false ;
F_73 ( & V_172 ) ;
F_5 (l, &acpi_crs_lookup_list, node) {
if ( V_170 -> V_76 == V_76 ) {
V_92 = V_170 ;
break;
}
}
if ( ! V_92 ) {
V_92 = F_102 ( sizeof( * V_92 ) , V_67 ) ;
if ( V_92 ) {
V_92 -> V_76 = V_76 ;
V_92 -> V_110 = F_103 ( V_110 , V_67 ) ;
F_28 ( & V_92 -> V_71 , & V_173 ) ;
}
}
F_74 ( & V_172 ) ;
return V_92 &&
( ( ! V_92 -> V_110 && ! V_110 ) ||
( V_92 -> V_110 && V_110 &&
strcmp ( V_92 -> V_110 , V_110 ) == 0 ) ) ;
}
