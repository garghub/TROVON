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
return F_9 ( - V_24 ) ;
V_23 = F_3 ( V_5 , V_6 ) ;
if ( V_23 < 0 )
return F_9 ( V_23 ) ;
return F_11 ( V_5 , V_23 ) ;
}
static T_3 F_12 ( int V_25 , void * V_3 )
{
struct V_26 * V_27 = V_3 ;
F_13 ( V_27 -> V_21 , NULL , NULL , NULL ) ;
return V_28 ;
}
static T_3 F_14 ( int V_25 , void * V_3 )
{
struct V_26 * V_27 = V_3 ;
F_15 ( V_27 -> V_21 , NULL , V_27 -> V_6 ) ;
return V_28 ;
}
static void F_16 ( T_1 V_21 , void * V_3 )
{
}
static T_2 F_17 ( struct V_29 * V_30 ,
void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_1 * V_5 = V_33 -> V_5 ;
struct V_34 * V_35 ;
T_1 V_21 , V_36 ;
struct V_26 * V_27 ;
T_4 V_37 = NULL ;
struct V_19 * V_38 ;
unsigned long V_39 ;
int V_40 , V_6 , V_25 ;
if ( V_30 -> type != V_41 )
return V_42 ;
V_35 = & V_30 -> V_3 . V_43 ;
if ( V_35 -> V_44 != V_45 )
return V_42 ;
V_21 = F_2 ( V_5 -> V_4 ) ;
V_6 = V_35 -> V_46 [ 0 ] ;
if ( V_6 <= 255 ) {
char V_47 [ 5 ] ;
sprintf ( V_47 , L_1 ,
V_35 -> V_48 == V_49 ? 'E' : 'L' ,
V_6 ) ;
if ( F_18 ( F_7 ( V_21 , V_47 , & V_36 ) ) )
V_37 = F_12 ;
}
if ( ! V_37 ) {
if ( F_18 ( F_7 ( V_21 , L_2 , & V_36 ) ) )
V_37 = F_14 ;
}
if ( ! V_37 )
return V_50 ;
V_38 = F_19 ( V_5 , V_6 , L_3 ) ;
if ( F_20 ( V_38 ) ) {
F_21 ( V_5 -> V_4 , L_4 ) ;
return V_51 ;
}
F_22 ( V_38 ) ;
V_40 = F_23 ( V_5 , V_6 ) ;
if ( V_40 ) {
F_21 ( V_5 -> V_4 , L_5 ) ;
goto V_52;
}
V_25 = F_24 ( V_38 ) ;
if ( V_25 < 0 ) {
F_21 ( V_5 -> V_4 , L_6 ) ;
goto V_53;
}
V_39 = V_54 ;
if ( V_35 -> V_48 == V_55 ) {
if ( V_35 -> V_56 == V_57 )
V_39 |= V_58 ;
else
V_39 |= V_59 ;
} else {
switch ( V_35 -> V_56 ) {
case V_57 :
V_39 |= V_60 ;
break;
case V_61 :
V_39 |= V_62 ;
break;
default:
V_39 |= V_60 |
V_62 ;
break;
}
}
V_27 = F_25 ( sizeof( * V_27 ) , V_63 ) ;
if ( ! V_27 )
goto V_53;
V_27 -> V_21 = V_36 ;
V_27 -> V_25 = V_25 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_38 = V_38 ;
V_40 = F_26 ( V_27 -> V_25 , NULL , V_37 , V_39 ,
L_3 , V_27 ) ;
if ( V_40 ) {
F_21 ( V_5 -> V_4 , L_7 ,
V_27 -> V_25 ) ;
goto V_64;
}
F_27 ( & V_27 -> V_65 , & V_33 -> V_66 ) ;
return V_42 ;
V_64:
F_28 ( V_27 ) ;
V_53:
F_29 ( V_5 , V_6 ) ;
V_52:
F_30 ( V_38 ) ;
return V_51 ;
}
void F_31 ( struct V_1 * V_5 )
{
struct V_32 * V_33 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 -> V_4 || ! V_5 -> V_67 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_33 ) ;
if ( F_8 ( V_22 ) )
return;
F_33 ( & V_33 -> V_66 ) ;
F_34 ( F_2 ( V_5 -> V_4 ) , L_8 ,
F_17 , V_33 ) ;
}
void F_35 ( struct V_1 * V_5 )
{
struct V_32 * V_33 ;
struct V_26 * V_27 , * V_68 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 -> V_4 || ! V_5 -> V_67 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_33 ) ;
if ( F_8 ( V_22 ) )
return;
F_36 (event, ep, &acpi_gpio->events, node) {
struct V_19 * V_38 ;
F_37 ( V_27 -> V_25 , V_27 ) ;
V_38 = V_27 -> V_38 ;
if ( F_38 ( F_20 ( V_38 ) ) )
continue;
F_29 ( V_5 , V_27 -> V_6 ) ;
F_30 ( V_38 ) ;
F_39 ( & V_27 -> V_65 ) ;
F_28 ( V_27 ) ;
}
}
int F_40 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
if ( V_70 && V_72 ) {
V_70 -> V_73 = V_72 ;
return 0 ;
}
return - V_18 ;
}
static bool F_41 ( struct V_69 * V_70 ,
const char * V_74 , int V_75 ,
struct V_76 * args )
{
const struct V_71 * V_77 ;
if ( ! V_70 -> V_73 )
return false ;
for ( V_77 = V_70 -> V_73 ; V_77 -> V_74 ; V_77 ++ )
if ( ! strcmp ( V_74 , V_77 -> V_74 ) && V_77 -> V_3 && V_75 < V_77 -> V_78 ) {
const struct V_79 * V_80 = V_77 -> V_3 + V_75 ;
args -> V_70 = V_70 ;
args -> args [ 0 ] = V_80 -> V_81 ;
args -> args [ 1 ] = V_80 -> V_82 ;
args -> args [ 2 ] = V_80 -> V_83 ;
args -> V_84 = 3 ;
return true ;
}
return false ;
}
static int F_42 ( struct V_29 * V_30 , void * V_3 )
{
struct V_85 * V_86 = V_3 ;
if ( V_30 -> type != V_41 )
return 1 ;
if ( V_86 -> V_87 ++ == V_86 -> V_75 && ! V_86 -> V_38 ) {
const struct V_34 * V_35 = & V_30 -> V_3 . V_43 ;
int V_88 = V_86 -> V_88 ;
if ( V_88 >= V_35 -> V_89 )
return 1 ;
V_86 -> V_38 = F_6 ( V_35 -> V_90 . V_91 ,
V_35 -> V_46 [ V_88 ] ) ;
V_86 -> V_92 . V_93 =
V_35 -> V_44 == V_45 ;
if ( V_86 -> V_92 . V_93 )
V_86 -> V_92 . V_83 =
V_35 -> V_56 == V_61 ;
}
return 1 ;
}
struct V_19 * F_43 ( struct V_69 * V_70 ,
const char * V_94 , int V_75 ,
struct V_95 * V_92 )
{
struct V_85 V_86 ;
struct V_96 V_97 ;
bool V_83 = false ;
int V_40 ;
if ( ! V_70 )
return F_9 ( - V_24 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_75 = V_75 ;
if ( V_94 ) {
struct V_76 args ;
F_44 ( & V_70 -> V_4 , L_9 , V_94 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
V_40 = F_45 ( V_70 , V_94 ,
V_75 , & args ) ;
if ( V_40 ) {
bool V_98 = F_41 ( V_70 , V_94 ,
V_75 , & args ) ;
if ( ! V_98 )
return F_9 ( V_40 ) ;
}
V_70 = args . V_70 ;
if ( args . V_84 >= 2 ) {
V_86 . V_75 = args . args [ 0 ] ;
V_86 . V_88 = args . args [ 1 ] ;
if ( args . V_84 >= 3 )
V_83 = ! ! args . args [ 2 ] ;
}
F_44 ( & V_70 -> V_4 , L_10 ,
F_46 ( & V_70 -> V_4 ) , args . V_84 ,
args . args [ 0 ] , args . args [ 1 ] , args . args [ 2 ] ) ;
} else {
F_44 ( & V_70 -> V_4 , L_11 , V_75 ) ;
}
F_33 ( & V_97 ) ;
V_40 = F_47 ( V_70 , & V_97 , F_42 ,
& V_86 ) ;
if ( V_40 < 0 )
return F_9 ( V_40 ) ;
F_48 ( & V_97 ) ;
if ( V_86 . V_38 && V_92 ) {
* V_92 = V_86 . V_92 ;
if ( V_83 )
V_92 -> V_83 = V_83 ;
}
return V_86 . V_38 ? V_86 . V_38 : F_9 ( - V_99 ) ;
}
static T_2
F_49 ( T_5 V_100 , T_6 V_101 ,
T_5 V_102 , T_7 * V_103 , void * V_104 ,
void * V_105 )
{
struct V_32 * V_106 = V_105 ;
struct V_1 * V_5 = V_106 -> V_5 ;
struct V_34 * V_35 ;
struct V_29 * V_30 ;
int V_88 = ( int ) V_101 ;
T_2 V_22 ;
bool V_107 ;
int V_108 ;
int V_12 ;
V_22 = F_50 ( V_106 -> V_109 . V_110 ,
V_106 -> V_109 . V_108 , & V_30 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
if ( F_38 ( V_30 -> type != V_41 ) ) {
F_51 ( V_30 ) ;
return V_50 ;
}
V_35 = & V_30 -> V_3 . V_43 ;
V_107 = V_35 -> V_111 == V_112 ;
if ( F_38 ( V_35 -> V_113 == V_114 &&
V_100 == V_115 ) ) {
F_51 ( V_30 ) ;
return V_50 ;
}
V_108 = F_52 ( V_35 -> V_89 , ( V_116 ) ( V_88 + V_102 ) ) ;
for ( V_12 = V_88 ; V_12 < V_108 ; ++ V_12 ) {
unsigned V_6 = V_35 -> V_46 [ V_12 ] ;
struct V_117 * V_118 ;
struct V_19 * V_38 ;
bool V_98 ;
F_53 ( & V_106 -> V_119 ) ;
V_98 = false ;
F_5 (conn, &achip->conns, node) {
if ( V_118 -> V_6 == V_6 ) {
V_98 = true ;
V_38 = V_118 -> V_38 ;
break;
}
}
if ( ! V_98 ) {
V_38 = F_19 ( V_5 , V_6 ,
L_12 ) ;
if ( F_20 ( V_38 ) ) {
V_22 = V_51 ;
F_54 ( & V_106 -> V_119 ) ;
goto V_120;
}
switch ( V_35 -> V_113 ) {
case V_114 :
F_22 ( V_38 ) ;
break;
case V_121 :
F_55 ( V_38 , V_107 ) ;
break;
default:
break;
}
V_118 = F_25 ( sizeof( * V_118 ) , V_63 ) ;
if ( ! V_118 ) {
V_22 = V_122 ;
F_30 ( V_38 ) ;
F_54 ( & V_106 -> V_119 ) ;
goto V_120;
}
V_118 -> V_6 = V_6 ;
V_118 -> V_38 = V_38 ;
F_27 ( & V_118 -> V_65 , & V_106 -> V_123 ) ;
}
F_54 ( & V_106 -> V_119 ) ;
if ( V_100 == V_115 )
F_56 ( V_38 ,
! ! ( ( 1 << V_12 ) & * V_103 ) ) ;
else
* V_103 |= ( T_7 ) F_57 ( V_38 ) << V_12 ;
}
V_120:
F_51 ( V_30 ) ;
return V_22 ;
}
static void F_58 ( struct V_32 * V_106 )
{
struct V_1 * V_5 = V_106 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
T_2 V_22 ;
F_33 ( & V_106 -> V_123 ) ;
F_59 ( & V_106 -> V_119 ) ;
V_22 = F_60 ( V_21 , V_124 ,
F_49 ,
NULL , V_106 ) ;
if ( F_8 ( V_22 ) )
F_21 ( V_5 -> V_4 , L_13 ) ;
}
static void F_61 ( struct V_32 * V_106 )
{
struct V_1 * V_5 = V_106 -> V_5 ;
T_1 V_21 = F_2 ( V_5 -> V_4 ) ;
struct V_117 * V_118 , * V_125 ;
T_2 V_22 ;
V_22 = F_62 ( V_21 , V_124 ,
F_49 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_14 ) ;
return;
}
F_36 (conn, tmp, &achip->conns, node) {
F_30 ( V_118 -> V_38 ) ;
F_39 ( & V_118 -> V_65 ) ;
F_28 ( V_118 ) ;
}
}
void F_63 ( struct V_1 * V_5 )
{
struct V_32 * V_33 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 || ! V_5 -> V_4 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_33 = F_25 ( sizeof( * V_33 ) , V_63 ) ;
if ( ! V_33 ) {
F_21 ( V_5 -> V_4 ,
L_15 ) ;
return;
}
V_33 -> V_5 = V_5 ;
V_22 = F_64 ( V_21 , F_16 , V_33 ) ;
if ( F_8 ( V_22 ) ) {
F_21 ( V_5 -> V_4 , L_16 ) ;
F_28 ( V_33 ) ;
return;
}
F_58 ( V_33 ) ;
}
void F_65 ( struct V_1 * V_5 )
{
struct V_32 * V_33 ;
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_5 || ! V_5 -> V_4 )
return;
V_21 = F_2 ( V_5 -> V_4 ) ;
if ( ! V_21 )
return;
V_22 = F_32 ( V_21 , F_16 , ( void * * ) & V_33 ) ;
if ( F_8 ( V_22 ) ) {
F_66 ( V_5 -> V_4 , L_17 ) ;
return;
}
F_61 ( V_33 ) ;
F_67 ( V_21 , F_16 ) ;
F_28 ( V_33 ) ;
}
