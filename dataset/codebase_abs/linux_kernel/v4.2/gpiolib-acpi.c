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
F_33 ( & V_34 -> V_67 ) ;
F_34 ( V_21 , L_8 ,
F_17 , V_34 ) ;
}
void F_35 ( struct V_1 * V_5 )
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
F_36 (event, ep, &acpi_gpio->events, node) {
struct V_19 * V_39 ;
F_37 ( V_28 -> V_26 , V_28 ) ;
V_39 = V_28 -> V_39 ;
if ( F_38 ( F_20 ( V_39 ) ) )
continue;
F_29 ( V_5 , V_28 -> V_6 ) ;
F_30 ( V_39 ) ;
F_39 ( & V_28 -> V_66 ) ;
F_28 ( V_28 ) ;
}
}
int F_40 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
if ( V_71 && V_73 ) {
V_71 -> V_74 = V_73 ;
return 0 ;
}
return - V_18 ;
}
static bool F_41 ( struct V_70 * V_71 ,
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
static int F_42 ( struct V_30 * V_31 , void * V_3 )
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
struct V_19 * F_43 ( struct V_70 * V_71 ,
const char * V_95 , int V_76 ,
struct V_96 * V_93 )
{
struct V_86 V_87 ;
struct V_97 V_98 ;
bool V_84 = false ;
int V_41 ;
if ( ! V_71 )
return F_9 ( - V_24 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_76 = V_76 ;
if ( V_95 ) {
struct V_77 args ;
F_44 ( & V_71 -> V_4 , L_9 , V_95 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
V_41 = F_45 ( V_71 , V_95 ,
V_76 , & args ) ;
if ( V_41 ) {
bool V_99 = F_41 ( V_71 , V_95 ,
V_76 , & args ) ;
if ( ! V_99 )
return F_9 ( V_41 ) ;
}
V_71 = args . V_71 ;
if ( args . V_85 >= 2 ) {
V_87 . V_76 = args . args [ 0 ] ;
V_87 . V_89 = args . args [ 1 ] ;
if ( args . V_85 >= 3 )
V_84 = ! ! args . args [ 2 ] ;
}
F_44 ( & V_71 -> V_4 , L_10 ,
F_46 ( & V_71 -> V_4 ) , args . V_85 ,
args . args [ 0 ] , args . args [ 1 ] , args . args [ 2 ] ) ;
} else {
F_44 ( & V_71 -> V_4 , L_11 , V_76 ) ;
}
F_33 ( & V_98 ) ;
V_41 = F_47 ( V_71 , & V_98 , F_42 ,
& V_87 ) ;
if ( V_41 < 0 )
return F_9 ( V_41 ) ;
F_48 ( & V_98 ) ;
if ( V_87 . V_39 && V_93 ) {
* V_93 = V_87 . V_93 ;
if ( V_84 )
V_93 -> V_84 = V_84 ;
}
return V_87 . V_39 ? V_87 . V_39 : F_9 ( - V_100 ) ;
}
int F_49 ( struct V_70 * V_71 , int V_76 )
{
int V_101 , V_12 ;
for ( V_12 = 0 , V_101 = 0 ; V_101 <= V_76 ; V_12 ++ ) {
struct V_96 V_93 ;
struct V_19 * V_39 ;
V_39 = F_43 ( V_71 , NULL , V_12 , & V_93 ) ;
if ( F_20 ( V_39 ) )
break;
if ( V_93 . V_94 && V_101 ++ == V_76 )
return F_24 ( V_39 ) ;
}
return - V_100 ;
}
static T_2
F_50 ( T_5 V_102 , T_6 V_103 ,
T_5 V_104 , T_7 * V_105 , void * V_106 ,
void * V_107 )
{
struct V_33 * V_108 = V_107 ;
struct V_1 * V_5 = V_108 -> V_5 ;
struct V_35 * V_36 ;
struct V_30 * V_31 ;
int V_89 = ( int ) V_103 ;
T_2 V_22 ;
bool V_109 ;
int V_110 ;
int V_12 ;
V_22 = F_51 ( V_108 -> V_111 . V_112 ,
V_108 -> V_111 . V_110 , & V_31 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
if ( F_38 ( V_31 -> type != V_42 ) ) {
F_52 ( V_31 ) ;
return V_51 ;
}
V_36 = & V_31 -> V_3 . V_44 ;
V_109 = V_36 -> V_113 == V_114 ;
if ( F_38 ( V_36 -> V_115 == V_116 &&
V_102 == V_117 ) ) {
F_52 ( V_31 ) ;
return V_51 ;
}
V_110 = F_53 ( V_36 -> V_90 , ( V_118 ) ( V_89 + V_104 ) ) ;
for ( V_12 = V_89 ; V_12 < V_110 ; ++ V_12 ) {
int V_6 = V_36 -> V_47 [ V_12 ] ;
struct V_119 * V_120 ;
struct V_19 * V_39 ;
bool V_99 ;
V_6 = F_3 ( V_5 , V_6 ) ;
if ( V_6 < 0 ) {
V_22 = V_51 ;
goto V_121;
}
F_54 ( & V_108 -> V_122 ) ;
V_99 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_120 -> V_6 == V_6 ) {
V_99 = true ;
V_39 = V_120 -> V_39 ;
break;
}
}
if ( ! V_99 ) {
V_39 = F_19 ( V_5 , V_6 ,
L_12 ) ;
if ( F_20 ( V_39 ) ) {
V_22 = V_52 ;
F_55 ( & V_108 -> V_122 ) ;
goto V_121;
}
switch ( V_36 -> V_115 ) {
case V_116 :
F_22 ( V_39 ) ;
break;
case V_123 :
F_56 ( V_39 , V_109 ) ;
break;
default:
break;
}
V_120 = F_25 ( sizeof( * V_120 ) , V_64 ) ;
if ( ! V_120 ) {
V_22 = V_124 ;
F_30 ( V_39 ) ;
F_55 ( & V_108 -> V_122 ) ;
goto V_121;
}
V_120 -> V_6 = V_6 ;
V_120 -> V_39 = V_39 ;
F_27 ( & V_120 -> V_66 , & V_108 -> V_125 ) ;
}
F_55 ( & V_108 -> V_122 ) ;
if ( V_102 == V_117 )
F_57 ( V_39 ,
! ! ( ( 1 << V_12 ) & * V_105 ) ) ;
else
* V_105 |= ( T_7 ) F_58 ( V_39 ) << V_12 ;
}
V_121:
F_52 ( V_31 ) ;
return V_22 ;
}
static void F_59 ( struct V_33 * V_108 )
{
struct V_1 * V_5 = V_108 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
T_2 V_22 ;
F_33 ( & V_108 -> V_125 ) ;
F_60 ( & V_108 -> V_122 ) ;
V_22 = F_61 ( V_21 , V_126 ,
F_50 ,
NULL , V_108 ) ;
if ( F_8 ( V_22 ) )
F_21 ( V_5 -> V_4 , L_13 ) ;
}
static void F_62 ( struct V_33 * V_108 )
{
struct V_1 * V_5 = V_108 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
struct V_119 * V_120 , * V_127 ;
T_2 V_22 ;
V_22 = F_63 ( V_21 , V_126 ,
F_50 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_14 ) ;
return;
}
F_36 (conn, tmp, &achip->conns, node) {
F_30 ( V_120 -> V_39 ) ;
F_39 ( & V_120 -> V_66 ) ;
F_28 ( V_120 ) ;
}
}
void F_64 ( struct V_1 * V_5 )
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
V_22 = F_65 ( V_21 , F_16 , V_34 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_16 ) ;
F_28 ( V_34 ) ;
return;
}
F_59 ( V_34 ) ;
}
void F_66 ( struct V_1 * V_5 )
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
F_67 ( V_5 -> V_4 , L_17 ) ;
return;
}
F_62 ( V_34 ) ;
F_68 ( V_21 , F_16 ) ;
F_28 ( V_34 ) ;
}
static unsigned int F_69 ( const union V_128 * V_129 )
{
const union V_128 * V_130 = V_129 -> V_131 . V_132 ;
const union V_128 * V_133 = V_130 + V_129 -> V_131 . V_134 ;
unsigned int V_134 = 0 ;
while ( V_130 < V_133 ) {
if ( V_130 -> type == V_135 )
V_134 ++ ;
V_130 ++ ;
}
return V_134 ;
}
static int F_70 ( struct V_30 * V_31 , void * V_3 )
{
unsigned int * V_134 = V_3 ;
if ( V_31 -> type == V_42 )
* V_134 += V_31 -> V_3 . V_44 . V_90 ;
return 1 ;
}
int F_71 ( struct V_136 * V_4 , const char * V_137 )
{
struct V_70 * V_71 = F_72 ( V_4 ) ;
const union V_128 * V_129 ;
const struct V_72 * V_78 ;
int V_134 = - V_100 ;
int V_41 ;
char V_95 [ 32 ] ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < F_73 ( V_138 ) ; V_12 ++ ) {
if ( V_137 && strcmp ( V_137 , L_18 ) )
snprintf ( V_95 , sizeof( V_95 ) , L_19 ,
V_137 , V_138 [ V_12 ] ) ;
else
snprintf ( V_95 , sizeof( V_95 ) , L_20 ,
V_138 [ V_12 ] ) ;
V_41 = F_74 ( V_71 , V_95 , V_139 ,
& V_129 ) ;
if ( V_41 == 0 ) {
if ( V_129 -> type == V_135 )
V_134 = 1 ;
else if ( V_129 -> type == V_140 )
V_134 = F_69 ( V_129 ) ;
} else if ( V_71 -> V_74 ) {
for ( V_78 = V_71 -> V_74 ; V_78 -> V_75 ; V_78 ++ )
if ( strcmp ( V_95 , V_78 -> V_75 ) == 0 ) {
V_134 = V_78 -> V_79 ;
break;
}
}
if ( V_134 >= 0 )
break;
}
if ( V_134 < 0 ) {
struct V_97 V_98 ;
unsigned int V_141 = 0 ;
F_33 ( & V_98 ) ;
F_47 ( V_71 , & V_98 ,
F_70 , & V_141 ) ;
F_48 ( & V_98 ) ;
if ( V_141 > 0 )
V_134 = V_141 ;
}
return V_134 ;
}
