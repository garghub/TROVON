static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
static int F_3 ( struct V_1 * V_5 , int V_6 )
{
struct V_7 * V_8 ;
if ( F_4 ( & V_5 -> V_9 ) )
return V_6 ;
F_5 (pin_range, &chip->pin_ranges, node) {
const struct V_10 * V_11 = & V_8 -> V_11 ;
int V_12 ;
if ( V_11 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_11 -> V_14 ; V_12 ++ ) {
if ( V_11 -> V_13 [ V_12 ] == V_6 )
return V_11 -> V_15 + V_12 - V_5 -> V_15 ;
}
} else {
if ( V_6 >= V_11 -> V_16 &&
V_6 < V_11 -> V_16 + V_11 -> V_14 ) {
unsigned V_17 ;
V_17 = V_11 -> V_15 - V_5 -> V_15 ;
return V_17 + V_6 - V_11 -> V_16 ;
}
}
}
return - V_18 ;
}
static inline int F_3 ( struct V_1 * V_5 ,
int V_6 )
{
return V_6 ;
}
static struct V_19 * F_6 ( char * V_20 , int V_6 )
{
struct V_1 * V_5 ;
T_1 V_21 ;
T_2 V_22 ;
int V_23 ;
V_22 = F_7 ( NULL , V_20 , & V_21 ) ;
if ( F_8 ( V_22 ) )
return F_9 ( - V_24 ) ;
V_5 = F_10 ( V_21 , F_1 ) ;
if ( ! V_5 )
return F_9 ( - V_25 ) ;
V_23 = F_3 ( V_5 , V_6 ) ;
if ( V_23 < 0 )
return F_9 ( V_23 ) ;
return F_11 ( V_5 , V_23 ) ;
}
static T_3 F_12 ( int V_26 , void * V_3 )
{
struct V_27 * V_28 = V_3 ;
F_13 ( V_28 -> V_21 , NULL , NULL , NULL ) ;
return V_29 ;
}
static T_3 F_14 ( int V_26 , void * V_3 )
{
struct V_27 * V_28 = V_3 ;
F_15 ( V_28 -> V_21 , NULL , V_28 -> V_6 ) ;
return V_29 ;
}
static void F_16 ( T_1 V_21 , void * V_3 )
{
}
static T_2 F_17 ( struct V_30 * V_31 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_1 * V_5 = V_34 -> V_5 ;
struct V_35 * V_36 ;
T_1 V_21 , V_37 ;
struct V_27 * V_28 ;
T_4 V_38 = NULL ;
struct V_19 * V_39 ;
unsigned long V_40 ;
int V_41 , V_6 , V_26 ;
if ( V_31 -> type != V_42 )
return V_43 ;
V_36 = & V_31 -> V_3 . V_44 ;
if ( V_36 -> V_45 != V_46 )
return V_43 ;
V_21 = F_2 ( V_5 -> V_4 ) ;
V_6 = V_36 -> V_47 [ 0 ] ;
if ( V_6 <= 255 ) {
char V_48 [ 5 ] ;
sprintf ( V_48 , L_1 ,
V_36 -> V_49 == V_50 ? 'E' : 'L' ,
V_6 ) ;
if ( F_18 ( F_7 ( V_21 , V_48 , & V_37 ) ) )
V_38 = F_12 ;
}
if ( ! V_38 ) {
if ( F_18 ( F_7 ( V_21 , L_2 , & V_37 ) ) )
V_38 = F_14 ;
}
if ( ! V_38 )
return V_51 ;
V_6 = F_3 ( V_5 , V_6 ) ;
if ( V_6 < 0 )
return V_51 ;
V_39 = F_19 ( V_5 , V_6 , L_3 ) ;
if ( F_20 ( V_39 ) ) {
F_21 ( V_5 -> V_4 , L_4 ) ;
return V_52 ;
}
F_22 ( V_39 ) ;
V_41 = F_23 ( V_5 , V_6 ) ;
if ( V_41 ) {
F_21 ( V_5 -> V_4 , L_5 ) ;
goto V_53;
}
V_26 = F_24 ( V_39 ) ;
if ( V_26 < 0 ) {
F_21 ( V_5 -> V_4 , L_6 ) ;
goto V_54;
}
V_40 = V_55 ;
if ( V_36 -> V_49 == V_56 ) {
if ( V_36 -> V_57 == V_58 )
V_40 |= V_59 ;
else
V_40 |= V_60 ;
} else {
switch ( V_36 -> V_57 ) {
case V_58 :
V_40 |= V_61 ;
break;
case V_62 :
V_40 |= V_63 ;
break;
default:
V_40 |= V_61 |
V_63 ;
break;
}
}
V_28 = F_25 ( sizeof( * V_28 ) , V_64 ) ;
if ( ! V_28 )
goto V_54;
V_28 -> V_21 = V_37 ;
V_28 -> V_26 = V_26 ;
V_28 -> V_6 = V_6 ;
V_28 -> V_39 = V_39 ;
V_41 = F_26 ( V_28 -> V_26 , NULL , V_38 , V_40 ,
L_3 , V_28 ) ;
if ( V_41 ) {
F_21 ( V_5 -> V_4 , L_7 ,
V_28 -> V_26 ) ;
goto V_65;
}
F_27 ( & V_28 -> V_66 , & V_34 -> V_67 ) ;
return V_43 ;
V_65:
F_28 ( V_28 ) ;
V_54:
F_29 ( V_5 , V_6 ) ;
V_53:
F_30 ( V_39 ) ;
return V_52 ;
}
void F_31 ( struct V_1 * V_5 )
{
struct V_33 * V_34 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 -> V_4 || ! V_5 -> V_68 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_34 ) ;
if ( F_8 ( V_22 ) )
return;
F_33 ( V_21 , L_8 ,
F_17 , V_34 ) ;
}
void F_34 ( struct V_1 * V_5 )
{
struct V_33 * V_34 ;
struct V_27 * V_28 , * V_69 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 -> V_4 || ! V_5 -> V_68 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_34 ) ;
if ( F_8 ( V_22 ) )
return;
F_35 (event, ep, &acpi_gpio->events, node) {
struct V_19 * V_39 ;
F_36 ( V_28 -> V_26 , V_28 ) ;
V_39 = V_28 -> V_39 ;
if ( F_37 ( F_20 ( V_39 ) ) )
continue;
F_29 ( V_5 , V_28 -> V_6 ) ;
F_30 ( V_39 ) ;
F_38 ( & V_28 -> V_66 ) ;
F_28 ( V_28 ) ;
}
}
int F_39 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
if ( V_71 && V_73 ) {
V_71 -> V_74 = V_73 ;
return 0 ;
}
return - V_18 ;
}
static bool F_40 ( struct V_70 * V_71 ,
const char * V_75 , int V_76 ,
struct V_77 * args )
{
const struct V_72 * V_78 ;
if ( ! V_71 -> V_74 )
return false ;
for ( V_78 = V_71 -> V_74 ; V_78 -> V_75 ; V_78 ++ )
if ( ! strcmp ( V_75 , V_78 -> V_75 ) && V_78 -> V_3 && V_76 < V_78 -> V_79 ) {
const struct V_80 * V_81 = V_78 -> V_3 + V_76 ;
args -> V_71 = V_71 ;
args -> args [ 0 ] = V_81 -> V_82 ;
args -> args [ 1 ] = V_81 -> V_83 ;
args -> args [ 2 ] = V_81 -> V_84 ;
args -> V_85 = 3 ;
return true ;
}
return false ;
}
static int F_41 ( struct V_30 * V_31 , void * V_3 )
{
struct V_86 * V_87 = V_3 ;
if ( V_31 -> type != V_42 )
return 1 ;
if ( V_87 -> V_88 ++ == V_87 -> V_76 && ! V_87 -> V_39 ) {
const struct V_35 * V_36 = & V_31 -> V_3 . V_44 ;
int V_89 = V_87 -> V_89 ;
if ( V_89 >= V_36 -> V_90 )
return 1 ;
V_87 -> V_39 = F_6 ( V_36 -> V_91 . V_92 ,
V_36 -> V_47 [ V_89 ] ) ;
V_87 -> V_93 . V_94 =
V_36 -> V_45 == V_46 ;
if ( V_87 -> V_93 . V_94 )
V_87 -> V_93 . V_84 =
V_36 -> V_57 == V_62 ;
}
return 1 ;
}
static int F_42 ( struct V_86 * V_87 ,
struct V_95 * V_93 )
{
struct V_96 V_97 ;
int V_41 ;
F_43 ( & V_97 ) ;
V_41 = F_44 ( V_87 -> V_71 , & V_97 , F_41 ,
V_87 ) ;
if ( V_41 < 0 )
return V_41 ;
F_45 ( & V_97 ) ;
if ( ! V_87 -> V_39 )
return - V_98 ;
if ( V_93 ) {
* V_93 = V_87 -> V_93 ;
if ( V_87 -> V_84 )
V_93 -> V_84 = V_87 -> V_84 ;
}
return 0 ;
}
static int F_46 ( struct V_99 * V_100 ,
const char * V_101 , int V_76 ,
struct V_86 * V_87 )
{
struct V_77 args ;
int V_41 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_41 = F_47 ( V_100 , V_101 , V_76 , & args ) ;
if ( V_41 ) {
struct V_70 * V_71 = F_48 ( V_100 ) ;
if ( ! V_71 )
return V_41 ;
if ( ! F_40 ( V_71 , V_101 , V_76 , & args ) )
return V_41 ;
}
V_87 -> V_71 = args . V_71 ;
if ( args . V_85 >= 2 ) {
V_87 -> V_76 = args . args [ 0 ] ;
V_87 -> V_89 = args . args [ 1 ] ;
if ( args . V_85 >= 3 )
V_87 -> V_84 = ! ! args . args [ 2 ] ;
}
return 0 ;
}
struct V_19 * F_49 ( struct V_70 * V_71 ,
const char * V_101 , int V_76 ,
struct V_95 * V_93 )
{
struct V_86 V_87 ;
int V_41 ;
if ( ! V_71 )
return F_9 ( - V_24 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_76 = V_76 ;
if ( V_101 ) {
F_50 ( & V_71 -> V_4 , L_9 , V_101 ) ;
V_41 = F_46 ( F_51 ( V_71 ) ,
V_101 , V_76 , & V_87 ) ;
if ( V_41 )
return F_9 ( V_41 ) ;
F_50 ( & V_71 -> V_4 , L_10 ,
F_52 ( & V_87 . V_71 -> V_4 ) , V_87 . V_76 ,
V_87 . V_89 , V_87 . V_84 ) ;
} else {
F_50 ( & V_71 -> V_4 , L_11 , V_76 ) ;
V_87 . V_71 = V_71 ;
}
V_41 = F_42 ( & V_87 , V_93 ) ;
return V_41 ? F_9 ( V_41 ) : V_87 . V_39 ;
}
struct V_19 * F_53 ( struct V_99 * V_100 ,
const char * V_101 , int V_76 ,
struct V_95 * V_93 )
{
struct V_86 V_87 ;
struct V_70 * V_71 ;
int V_41 ;
V_71 = F_48 ( V_100 ) ;
if ( V_71 )
return F_49 ( V_71 , V_101 , V_76 , V_93 ) ;
if ( ! F_54 ( V_100 ) )
return F_9 ( - V_24 ) ;
if ( ! V_101 )
return F_9 ( - V_18 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_76 = V_76 ;
V_41 = F_46 ( V_100 , V_101 , V_76 , & V_87 ) ;
if ( V_41 )
return F_9 ( V_41 ) ;
V_41 = F_42 ( & V_87 , V_93 ) ;
return V_41 ? F_9 ( V_41 ) : V_87 . V_39 ;
}
int F_55 ( struct V_70 * V_71 , int V_76 )
{
int V_102 , V_12 ;
for ( V_12 = 0 , V_102 = 0 ; V_102 <= V_76 ; V_12 ++ ) {
struct V_95 V_93 ;
struct V_19 * V_39 ;
V_39 = F_49 ( V_71 , NULL , V_12 , & V_93 ) ;
if ( F_20 ( V_39 ) )
break;
if ( V_93 . V_94 && V_102 ++ == V_76 )
return F_24 ( V_39 ) ;
}
return - V_98 ;
}
static T_2
F_56 ( T_5 V_103 , T_6 V_104 ,
T_5 V_105 , T_7 * V_106 , void * V_107 ,
void * V_108 )
{
struct V_33 * V_109 = V_108 ;
struct V_1 * V_5 = V_109 -> V_5 ;
struct V_35 * V_36 ;
struct V_30 * V_31 ;
int V_89 = ( int ) V_104 ;
T_2 V_22 ;
bool V_110 ;
int V_111 ;
int V_12 ;
V_22 = F_57 ( V_109 -> V_112 . V_113 ,
V_109 -> V_112 . V_111 , & V_31 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
if ( F_37 ( V_31 -> type != V_42 ) ) {
F_58 ( V_31 ) ;
return V_51 ;
}
V_36 = & V_31 -> V_3 . V_44 ;
V_110 = V_36 -> V_114 == V_115 ;
if ( F_37 ( V_36 -> V_116 == V_117 &&
V_103 == V_118 ) ) {
F_58 ( V_31 ) ;
return V_51 ;
}
V_111 = F_59 ( V_36 -> V_90 , ( V_119 ) ( V_89 + V_105 ) ) ;
for ( V_12 = V_89 ; V_12 < V_111 ; ++ V_12 ) {
int V_6 = V_36 -> V_47 [ V_12 ] ;
struct V_120 * V_121 ;
struct V_19 * V_39 ;
bool V_122 ;
V_6 = F_3 ( V_5 , V_6 ) ;
if ( V_6 < 0 ) {
V_22 = V_51 ;
goto V_123;
}
F_60 ( & V_109 -> V_124 ) ;
V_122 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_121 -> V_6 == V_6 ) {
V_122 = true ;
V_39 = V_121 -> V_39 ;
break;
}
}
if ( ! V_122 && V_36 -> V_125 == V_126 &&
V_103 == V_127 ) {
struct V_27 * V_28 ;
F_5 (event, &achip->events, node) {
if ( V_28 -> V_6 == V_6 ) {
V_39 = V_28 -> V_39 ;
V_122 = true ;
break;
}
}
}
if ( ! V_122 ) {
V_39 = F_19 ( V_5 , V_6 ,
L_12 ) ;
if ( F_20 ( V_39 ) ) {
V_22 = V_52 ;
F_61 ( & V_109 -> V_124 ) ;
goto V_123;
}
switch ( V_36 -> V_116 ) {
case V_117 :
F_22 ( V_39 ) ;
break;
case V_128 :
F_62 ( V_39 , V_110 ) ;
break;
default:
break;
}
V_121 = F_25 ( sizeof( * V_121 ) , V_64 ) ;
if ( ! V_121 ) {
V_22 = V_129 ;
F_30 ( V_39 ) ;
F_61 ( & V_109 -> V_124 ) ;
goto V_123;
}
V_121 -> V_6 = V_6 ;
V_121 -> V_39 = V_39 ;
F_27 ( & V_121 -> V_66 , & V_109 -> V_130 ) ;
}
F_61 ( & V_109 -> V_124 ) ;
if ( V_103 == V_118 )
F_63 ( V_39 ,
! ! ( ( 1 << V_12 ) & * V_106 ) ) ;
else
* V_106 |= ( T_7 ) F_64 ( V_39 ) << V_12 ;
}
V_123:
F_58 ( V_31 ) ;
return V_22 ;
}
static void F_65 ( struct V_33 * V_109 )
{
struct V_1 * V_5 = V_109 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
T_2 V_22 ;
F_43 ( & V_109 -> V_130 ) ;
F_66 ( & V_109 -> V_124 ) ;
V_22 = F_67 ( V_21 , V_131 ,
F_56 ,
NULL , V_109 ) ;
if ( F_8 ( V_22 ) )
F_21 ( V_5 -> V_4 , L_13 ) ;
}
static void F_68 ( struct V_33 * V_109 )
{
struct V_1 * V_5 = V_109 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
struct V_120 * V_121 , * V_132 ;
T_2 V_22 ;
V_22 = F_69 ( V_21 , V_131 ,
F_56 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_14 ) ;
return;
}
F_35 (conn, tmp, &achip->conns, node) {
F_30 ( V_121 -> V_39 ) ;
F_38 ( & V_121 -> V_66 ) ;
F_28 ( V_121 ) ;
}
}
void F_70 ( struct V_1 * V_5 )
{
struct V_33 * V_34 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 || ! V_5 -> V_4 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_34 = F_25 ( sizeof( * V_34 ) , V_64 ) ;
if ( ! V_34 ) {
F_21 ( V_5 -> V_4 ,
L_15 ) ;
return;
}
V_34 -> V_5 = V_5 ;
F_43 ( & V_34 -> V_67 ) ;
V_22 = F_71 ( V_21 , F_16 , V_34 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_16 ) ;
F_28 ( V_34 ) ;
return;
}
F_65 ( V_34 ) ;
}
void F_72 ( struct V_1 * V_5 )
{
struct V_33 * V_34 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 || ! V_5 -> V_4 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_34 ) ;
if ( F_8 ( V_22 ) ) {
F_73 ( V_5 -> V_4 , L_17 ) ;
return;
}
F_68 ( V_34 ) ;
F_74 ( V_21 , F_16 ) ;
F_28 ( V_34 ) ;
}
static unsigned int F_75 ( const union V_133 * V_134 )
{
const union V_133 * V_135 = V_134 -> V_136 . V_137 ;
const union V_133 * V_138 = V_135 + V_134 -> V_136 . V_139 ;
unsigned int V_139 = 0 ;
while ( V_135 < V_138 ) {
if ( V_135 -> type == V_140 )
V_139 ++ ;
V_135 ++ ;
}
return V_139 ;
}
static int F_76 ( struct V_30 * V_31 , void * V_3 )
{
unsigned int * V_139 = V_3 ;
if ( V_31 -> type == V_42 )
* V_139 += V_31 -> V_3 . V_44 . V_90 ;
return 1 ;
}
int F_77 ( struct V_141 * V_4 , const char * V_142 )
{
struct V_70 * V_71 = F_78 ( V_4 ) ;
const union V_133 * V_134 ;
const struct V_72 * V_78 ;
int V_139 = - V_98 ;
int V_41 ;
char V_101 [ 32 ] ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < F_79 ( V_143 ) ; V_12 ++ ) {
if ( V_142 && strcmp ( V_142 , L_18 ) )
snprintf ( V_101 , sizeof( V_101 ) , L_19 ,
V_142 , V_143 [ V_12 ] ) ;
else
snprintf ( V_101 , sizeof( V_101 ) , L_20 ,
V_143 [ V_12 ] ) ;
V_41 = F_80 ( V_71 , V_101 , V_144 ,
& V_134 ) ;
if ( V_41 == 0 ) {
if ( V_134 -> type == V_140 )
V_139 = 1 ;
else if ( V_134 -> type == V_145 )
V_139 = F_75 ( V_134 ) ;
} else if ( V_71 -> V_74 ) {
for ( V_78 = V_71 -> V_74 ; V_78 -> V_75 ; V_78 ++ )
if ( strcmp ( V_101 , V_78 -> V_75 ) == 0 ) {
V_139 = V_78 -> V_79 ;
break;
}
}
if ( V_139 >= 0 )
break;
}
if ( V_139 < 0 ) {
struct V_96 V_146 ;
unsigned int V_147 = 0 ;
F_43 ( & V_146 ) ;
F_44 ( V_71 , & V_146 ,
F_76 , & V_147 ) ;
F_45 ( & V_146 ) ;
if ( V_147 > 0 )
V_139 = V_147 ;
}
return V_139 ;
}
