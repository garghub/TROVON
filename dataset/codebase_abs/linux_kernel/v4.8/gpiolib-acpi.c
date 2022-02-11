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
F_27 ( & V_31 -> V_69 , & V_37 -> V_70 ) ;
return V_46 ;
V_68:
F_28 ( V_31 ) ;
V_57:
F_29 ( V_22 , V_7 ) ;
V_56:
F_30 ( V_42 ) ;
return V_55 ;
}
void F_31 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_71 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_32 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) )
return;
F_33 ( V_23 , L_8 ,
F_17 , V_37 ) ;
}
void F_34 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
struct V_30 * V_31 , * V_72 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 -> V_4 || ! V_22 -> V_71 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_32 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) )
return;
F_35 (event, ep, &acpi_gpio->events, node) {
struct V_20 * V_42 ;
F_36 ( V_31 -> V_29 , V_31 ) ;
V_42 = V_31 -> V_42 ;
if ( F_37 ( F_20 ( V_42 ) ) )
continue;
F_29 ( V_22 , V_31 -> V_7 ) ;
F_30 ( V_42 ) ;
F_38 ( & V_31 -> V_69 ) ;
F_28 ( V_31 ) ;
}
}
int F_39 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
if ( V_74 && V_76 ) {
V_74 -> V_77 = V_76 ;
return 0 ;
}
return - V_19 ;
}
static bool F_40 ( struct V_73 * V_74 ,
const char * V_78 , int V_79 ,
struct V_80 * args )
{
const struct V_75 * V_81 ;
if ( ! V_74 -> V_77 )
return false ;
for ( V_81 = V_74 -> V_77 ; V_81 -> V_78 ; V_81 ++ )
if ( ! strcmp ( V_78 , V_81 -> V_78 ) && V_81 -> V_3 && V_79 < V_81 -> V_82 ) {
const struct V_83 * V_84 = V_81 -> V_3 + V_79 ;
args -> V_74 = V_74 ;
args -> args [ 0 ] = V_84 -> V_85 ;
args -> args [ 1 ] = V_84 -> V_86 ;
args -> args [ 2 ] = V_84 -> V_87 ;
args -> V_88 = 3 ;
return true ;
}
return false ;
}
static int F_41 ( struct V_33 * V_34 , void * V_3 )
{
struct V_89 * V_90 = V_3 ;
if ( V_34 -> type != V_45 )
return 1 ;
if ( V_90 -> V_91 ++ == V_90 -> V_79 && ! V_90 -> V_42 ) {
const struct V_38 * V_39 = & V_34 -> V_3 . V_47 ;
int V_92 = V_90 -> V_92 ;
if ( V_92 >= V_39 -> V_93 )
return 1 ;
V_90 -> V_42 = F_6 ( V_39 -> V_94 . V_95 ,
V_39 -> V_50 [ V_92 ] ) ;
V_90 -> V_96 . V_97 =
V_39 -> V_48 == V_49 ;
if ( V_90 -> V_96 . V_97 ) {
V_90 -> V_96 . V_60 = V_39 -> V_60 ;
V_90 -> V_96 . V_52 = V_39 -> V_52 ;
}
}
return 1 ;
}
static int F_42 ( struct V_89 * V_90 ,
struct V_98 * V_96 )
{
struct V_99 V_100 ;
int V_44 ;
F_43 ( & V_100 ) ;
V_44 = F_44 ( V_90 -> V_74 , & V_100 , F_41 ,
V_90 ) ;
if ( V_44 < 0 )
return V_44 ;
F_45 ( & V_100 ) ;
if ( ! V_90 -> V_42 )
return - V_101 ;
if ( V_96 ) {
* V_96 = V_90 -> V_96 ;
if ( V_90 -> V_87 )
V_96 -> V_60 = V_90 -> V_87 ;
}
return 0 ;
}
static int F_46 ( struct V_102 * V_103 ,
const char * V_104 , int V_79 ,
struct V_89 * V_90 )
{
struct V_80 args ;
int V_44 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_44 = F_47 ( V_103 , V_104 , V_79 , & args ) ;
if ( V_44 ) {
struct V_73 * V_74 = F_48 ( V_103 ) ;
if ( ! V_74 )
return V_44 ;
if ( ! F_40 ( V_74 , V_104 , V_79 , & args ) )
return V_44 ;
}
V_90 -> V_74 = args . V_74 ;
if ( args . V_88 >= 2 ) {
V_90 -> V_79 = args . args [ 0 ] ;
V_90 -> V_92 = args . args [ 1 ] ;
if ( args . V_88 >= 3 )
V_90 -> V_87 = ! ! args . args [ 2 ] ;
}
return 0 ;
}
struct V_20 * F_49 ( struct V_73 * V_74 ,
const char * V_104 , int V_79 ,
struct V_98 * V_96 )
{
struct V_89 V_90 ;
int V_44 ;
if ( ! V_74 )
return F_9 ( - V_26 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_79 = V_79 ;
if ( V_104 ) {
F_50 ( & V_74 -> V_105 , L_9 , V_104 ) ;
V_44 = F_46 ( F_51 ( V_74 ) ,
V_104 , V_79 , & V_90 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
F_50 ( & V_74 -> V_105 , L_10 ,
F_52 ( & V_90 . V_74 -> V_105 ) , V_90 . V_79 ,
V_90 . V_92 , V_90 . V_87 ) ;
} else {
F_50 ( & V_74 -> V_105 , L_11 , V_79 ) ;
V_90 . V_74 = V_74 ;
}
V_44 = F_42 ( & V_90 , V_96 ) ;
return V_44 ? F_9 ( V_44 ) : V_90 . V_42 ;
}
struct V_20 * F_53 ( struct V_102 * V_103 ,
const char * V_104 , int V_79 ,
struct V_98 * V_96 )
{
struct V_89 V_90 ;
struct V_73 * V_74 ;
int V_44 ;
V_74 = F_48 ( V_103 ) ;
if ( V_74 )
return F_49 ( V_74 , V_104 , V_79 , V_96 ) ;
if ( ! F_54 ( V_103 ) )
return F_9 ( - V_26 ) ;
if ( ! V_104 )
return F_9 ( - V_19 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_79 = V_79 ;
V_44 = F_46 ( V_103 , V_104 , V_79 , & V_90 ) ;
if ( V_44 )
return F_9 ( V_44 ) ;
V_44 = F_42 ( & V_90 , V_96 ) ;
return V_44 ? F_9 ( V_44 ) : V_90 . V_42 ;
}
int F_55 ( struct V_73 * V_74 , int V_79 )
{
int V_106 , V_13 ;
unsigned int V_107 ;
for ( V_13 = 0 , V_106 = 0 ; V_106 <= V_79 ; V_13 ++ ) {
struct V_98 V_96 ;
struct V_20 * V_42 ;
V_42 = F_49 ( V_74 , NULL , V_13 , & V_96 ) ;
if ( F_20 ( V_42 ) )
break;
if ( V_96 . V_97 && V_106 ++ == V_79 ) {
int V_29 = F_24 ( V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
V_107 = F_56 ( V_96 . V_52 ,
V_96 . V_60 ) ;
if ( V_107 != V_108 &&
V_107 != F_57 ( V_29 ) )
F_58 ( V_29 , V_107 ) ;
return V_29 ;
}
}
return - V_101 ;
}
static T_2
F_59 ( T_5 V_109 , T_6 V_110 ,
T_5 V_111 , T_7 * V_112 , void * V_113 ,
void * V_114 )
{
struct V_36 * V_115 = V_114 ;
struct V_1 * V_22 = V_115 -> V_22 ;
struct V_38 * V_39 ;
struct V_33 * V_34 ;
int V_92 = ( int ) V_110 ;
T_2 V_24 ;
bool V_116 ;
int V_117 ;
int V_13 ;
V_24 = F_60 ( V_115 -> V_118 . V_119 ,
V_115 -> V_118 . V_117 , & V_34 ) ;
if ( F_8 ( V_24 ) )
return V_24 ;
if ( F_37 ( V_34 -> type != V_45 ) ) {
F_61 ( V_34 ) ;
return V_54 ;
}
V_39 = & V_34 -> V_3 . V_47 ;
V_116 = V_39 -> V_120 == V_121 ;
if ( F_37 ( V_39 -> V_122 == V_123 &&
V_109 == V_124 ) ) {
F_61 ( V_34 ) ;
return V_54 ;
}
V_117 = F_62 ( V_39 -> V_93 , ( V_125 ) ( V_92 + V_111 ) ) ;
for ( V_13 = V_92 ; V_13 < V_117 ; ++ V_13 ) {
int V_7 = V_39 -> V_50 [ V_13 ] ;
struct V_126 * V_127 ;
struct V_20 * V_42 ;
bool V_128 ;
V_7 = F_3 ( V_22 -> V_28 , V_7 ) ;
if ( V_7 < 0 ) {
V_24 = V_54 ;
goto V_129;
}
F_63 ( & V_115 -> V_130 ) ;
V_128 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_127 -> V_7 == V_7 ) {
V_128 = true ;
V_42 = V_127 -> V_42 ;
break;
}
}
if ( ! V_128 && V_39 -> V_131 == V_132 &&
V_109 == V_133 ) {
struct V_30 * V_31 ;
F_5 (event, &achip->events, node) {
if ( V_31 -> V_7 == V_7 ) {
V_42 = V_31 -> V_42 ;
V_128 = true ;
break;
}
}
}
if ( ! V_128 ) {
V_42 = F_19 ( V_22 , V_7 ,
L_12 ) ;
if ( F_20 ( V_42 ) ) {
V_24 = V_55 ;
F_64 ( & V_115 -> V_130 ) ;
goto V_129;
}
switch ( V_39 -> V_122 ) {
case V_123 :
F_22 ( V_42 ) ;
break;
case V_134 :
F_65 ( V_42 , V_116 ) ;
break;
default:
break;
}
V_127 = F_25 ( sizeof( * V_127 ) , V_67 ) ;
if ( ! V_127 ) {
V_24 = V_135 ;
F_30 ( V_42 ) ;
F_64 ( & V_115 -> V_130 ) ;
goto V_129;
}
V_127 -> V_7 = V_7 ;
V_127 -> V_42 = V_42 ;
F_27 ( & V_127 -> V_69 , & V_115 -> V_136 ) ;
}
F_64 ( & V_115 -> V_130 ) ;
if ( V_109 == V_124 )
F_66 ( V_42 ,
! ! ( ( 1 << V_13 ) & * V_112 ) ) ;
else
* V_112 |= ( T_7 ) F_67 ( V_42 ) << V_13 ;
}
V_129:
F_61 ( V_34 ) ;
return V_24 ;
}
static void F_68 ( struct V_36 * V_115 )
{
struct V_1 * V_22 = V_115 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
T_2 V_24 ;
F_43 ( & V_115 -> V_136 ) ;
F_69 ( & V_115 -> V_130 ) ;
V_24 = F_70 ( V_23 , V_137 ,
F_59 ,
NULL , V_115 ) ;
if ( F_8 ( V_24 ) )
F_21 ( V_22 -> V_4 ,
L_13 ) ;
}
static void F_71 ( struct V_36 * V_115 )
{
struct V_1 * V_22 = V_115 -> V_22 ;
T_1 V_23 = F_2 ( V_22 -> V_4 ) ;
struct V_126 * V_127 , * V_138 ;
T_2 V_24 ;
V_24 = F_72 ( V_23 , V_137 ,
F_59 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 ,
L_14 ) ;
return;
}
F_35 (conn, tmp, &achip->conns, node) {
F_30 ( V_127 -> V_42 ) ;
F_38 ( & V_127 -> V_69 ) ;
F_28 ( V_127 ) ;
}
}
void F_73 ( struct V_1 * V_22 )
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
L_15 ) ;
return;
}
V_37 -> V_22 = V_22 ;
F_43 ( & V_37 -> V_70 ) ;
V_24 = F_74 ( V_23 , F_16 , V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_21 ( V_22 -> V_4 , L_16 ) ;
F_28 ( V_37 ) ;
return;
}
F_68 ( V_37 ) ;
F_75 ( V_23 ) ;
}
void F_76 ( struct V_1 * V_22 )
{
struct V_36 * V_37 ;
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_22 || ! V_22 -> V_4 )
return;
V_23 = F_2 ( V_22 -> V_4 ) ;
if ( ! V_23 )
return;
V_24 = F_32 ( V_23 , F_16 , ( void * * ) & V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_77 ( V_22 -> V_4 , L_17 ) ;
return;
}
F_71 ( V_37 ) ;
F_78 ( V_23 , F_16 ) ;
F_28 ( V_37 ) ;
}
static unsigned int F_79 ( const union V_139 * V_140 )
{
const union V_139 * V_141 = V_140 -> V_142 . V_143 ;
const union V_139 * V_144 = V_141 + V_140 -> V_142 . V_145 ;
unsigned int V_145 = 0 ;
while ( V_141 < V_144 ) {
if ( V_141 -> type == V_146 )
V_145 ++ ;
V_141 ++ ;
}
return V_145 ;
}
static int F_80 ( struct V_33 * V_34 , void * V_3 )
{
unsigned int * V_145 = V_3 ;
if ( V_34 -> type == V_45 )
* V_145 += V_34 -> V_3 . V_47 . V_93 ;
return 1 ;
}
int F_81 ( struct V_147 * V_105 , const char * V_148 )
{
struct V_73 * V_74 = F_82 ( V_105 ) ;
const union V_139 * V_140 ;
const struct V_75 * V_81 ;
int V_145 = - V_101 ;
int V_44 ;
char V_104 [ 32 ] ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_83 ( V_149 ) ; V_13 ++ ) {
if ( V_148 && strcmp ( V_148 , L_18 ) )
snprintf ( V_104 , sizeof( V_104 ) , L_19 ,
V_148 , V_149 [ V_13 ] ) ;
else
snprintf ( V_104 , sizeof( V_104 ) , L_20 ,
V_149 [ V_13 ] ) ;
V_44 = F_84 ( V_74 , V_104 , V_150 ,
& V_140 ) ;
if ( V_44 == 0 ) {
if ( V_140 -> type == V_146 )
V_145 = 1 ;
else if ( V_140 -> type == V_151 )
V_145 = F_79 ( V_140 ) ;
} else if ( V_74 -> V_77 ) {
for ( V_81 = V_74 -> V_77 ; V_81 -> V_78 ; V_81 ++ )
if ( strcmp ( V_104 , V_81 -> V_78 ) == 0 ) {
V_145 = V_81 -> V_82 ;
break;
}
}
if ( V_145 >= 0 )
break;
}
if ( V_145 < 0 ) {
struct V_99 V_152 ;
unsigned int V_153 = 0 ;
F_43 ( & V_152 ) ;
F_44 ( V_74 , & V_152 ,
F_80 , & V_153 ) ;
F_45 ( & V_152 ) ;
if ( V_153 > 0 )
V_145 = V_153 ;
}
return V_145 ;
}
bool F_85 ( struct V_73 * V_74 , const char * V_148 )
{
struct V_154 * V_155 , * V_90 = NULL ;
if ( V_74 -> V_3 . V_156 || V_74 -> V_77 )
return false ;
F_63 ( & V_157 ) ;
F_5 (l, &acpi_crs_lookup_list, node) {
if ( V_155 -> V_74 == V_74 ) {
V_90 = V_155 ;
break;
}
}
if ( ! V_90 ) {
V_90 = F_86 ( sizeof( * V_90 ) , V_67 ) ;
if ( V_90 ) {
V_90 -> V_74 = V_74 ;
V_90 -> V_148 = F_87 ( V_148 , V_67 ) ;
F_27 ( & V_90 -> V_69 , & V_158 ) ;
}
}
F_64 ( & V_157 ) ;
return V_90 &&
( ( ! V_90 -> V_148 && ! V_148 ) ||
( V_90 -> V_148 && V_148 &&
strcmp ( V_90 -> V_148 , V_148 ) == 0 ) ) ;
}
