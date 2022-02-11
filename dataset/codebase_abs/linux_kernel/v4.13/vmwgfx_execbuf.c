static T_1 F_1 ( void * V_1 , void * V_2 )
{
return ( unsigned long ) V_2 - ( unsigned long ) V_1 ;
}
static void F_2 ( struct V_3 * V_4 ,
bool V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_4 -> V_10 ;
if ( V_4 -> V_11 && ! V_5 )
F_3 ( V_4 -> V_12 ,
V_4 -> V_11 ) ;
F_4 (val, list, head) {
struct V_13 * V_14 = V_7 -> V_14 ;
bool V_15 =
( V_5 ) ? false : V_7 -> V_16 ;
if ( F_5 ( V_7 -> V_17 ) ) {
if ( ! V_5 ) {
F_6
( F_7 ( V_7 -> V_14 ) ,
V_7 -> V_17 ) ;
}
if ( V_7 -> V_17 != V_4 -> V_17 )
F_8 ( V_7 -> V_17 ) ;
else
V_4 -> V_18 = false ;
V_7 -> V_17 = NULL ;
}
F_9 ( V_14 , V_15 , V_7 -> V_19 ,
V_7 -> V_20 ) ;
F_10 ( & V_7 -> V_19 ) ;
}
}
static int F_11 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
struct V_6 * V_23 )
{
int V_24 ;
V_24 = F_12 ( V_22 , V_4 , V_23 -> V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
if ( ! V_4 -> V_17 ) {
V_4 -> V_17 =
F_13 ( V_22 ) ;
if ( F_14 ( V_4 -> V_17 ) ) {
F_15 ( L_1
L_2 ) ;
V_24 = F_16 ( V_4 -> V_17 ) ;
V_4 -> V_17 = NULL ;
goto V_25;
}
}
if ( V_4 -> V_18 ) {
V_23 -> V_17 = F_13 ( V_22 ) ;
if ( F_14 ( V_23 -> V_17 ) ) {
F_15 ( L_1
L_2 ) ;
V_24 = F_16 ( V_23 -> V_17 ) ;
V_23 -> V_17 = NULL ;
goto V_25;
}
} else {
V_23 -> V_17 = V_4 -> V_17 ;
V_4 -> V_18 = true ;
}
return 0 ;
V_25:
return V_24 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_6 * * V_26 )
{
struct V_21 * V_22 = V_14 -> V_22 ;
struct V_6 * V_23 ;
struct V_27 * V_28 ;
int V_24 ;
if ( F_18 ( F_19 ( & V_4 -> V_29 , ( unsigned long ) V_14 ,
& V_28 ) == 0 ) ) {
V_23 = F_20 ( V_28 , struct V_6 , V_28 ) ;
V_23 -> V_30 = false ;
if ( F_5 ( V_26 != NULL ) )
* V_26 = V_23 ;
return 0 ;
}
V_23 = F_21 ( sizeof( * V_23 ) , V_31 ) ;
if ( F_5 ( ! V_23 ) ) {
F_15 ( L_3
L_4 ) ;
return - V_32 ;
}
V_23 -> V_28 . V_33 = ( unsigned long ) V_14 ;
V_24 = F_22 ( & V_4 -> V_29 , & V_23 -> V_28 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_5
L_4 ) ;
F_23 ( V_23 ) ;
return V_24 ;
}
V_23 -> V_14 = F_24 ( V_14 ) ;
V_23 -> V_30 = true ;
if ( F_5 ( V_26 != NULL ) )
* V_26 = V_23 ;
if ( ! V_22 -> V_34 ) {
F_25 ( & V_23 -> V_35 , & V_4 -> V_10 ) ;
return 0 ;
}
switch ( F_26 ( V_14 ) ) {
case V_36 :
case V_37 :
F_27 ( & V_23 -> V_35 , & V_4 -> V_38 ) ;
V_24 = F_11 ( V_22 , V_4 , V_23 ) ;
break;
case V_39 :
F_25 ( & V_23 -> V_35 , & V_4 -> V_38 ) ;
break;
default:
F_25 ( & V_23 -> V_35 , & V_4 -> V_10 ) ;
break;
}
return V_24 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_13 * V_40 )
{
int V_24 ;
V_24 = F_17 ( V_4 , F_29 ( V_40 ) , NULL ) ;
if ( V_24 )
return V_24 ;
return F_17 ( V_4 , V_40 , NULL ) ;
}
static int F_30 ( struct V_3 * V_4 ,
enum V_41 V_42 , T_2 V_43 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_40 ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_40 = F_31 ( V_4 -> V_47 , V_42 , V_43 ) ;
if ( F_14 ( V_40 ) )
return F_16 ( V_40 ) ;
V_24 = F_28 ( V_4 , V_40 ) ;
F_32 ( & V_40 ) ;
return V_24 ;
}
static int F_12 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
struct V_13 * V_48 )
{
struct V_8 * V_49 ;
struct V_50 * V_51 ;
int V_24 = 0 ;
struct V_13 * V_14 ;
T_2 V_52 ;
if ( V_22 -> V_53 && F_26 ( V_48 ) == V_37 ) {
for ( V_52 = 0 ; V_52 < V_54 ; ++ V_52 ) {
V_14 = F_33 ( V_48 , V_52 ) ;
if ( F_14 ( V_14 ) )
continue;
V_24 = F_17 ( V_4 , V_14 , NULL ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
}
F_34 ( & V_22 -> V_55 ) ;
V_49 = F_35 ( V_48 ) ;
F_4 (entry, binding_list, ctx_list) {
V_14 = F_36 ( V_51 -> V_14 ) ;
if ( F_5 ( V_14 == NULL ) )
continue;
if ( F_26 ( V_51 -> V_14 ) == V_56 )
V_24 = F_28 ( V_4 , V_51 -> V_14 ) ;
else
V_24 = F_17 ( V_4 , V_51 -> V_14 ,
NULL ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
break;
}
if ( V_22 -> V_53 && F_26 ( V_48 ) == V_37 ) {
struct V_57 * V_11 ;
V_11 = F_37 ( V_48 ) ;
if ( V_11 )
V_24 = F_38 ( V_4 ,
V_11 ,
true , NULL ) ;
}
F_39 ( & V_22 -> V_55 ) ;
return V_24 ;
}
static int F_40 ( struct V_8 * V_9 ,
const struct V_13 * V_14 ,
unsigned long V_58 ,
enum V_59
V_60 )
{
struct V_61 * V_62 ;
V_62 = F_41 ( sizeof( * V_62 ) , V_31 ) ;
if ( F_5 ( ! V_62 ) ) {
F_15 ( L_7 ) ;
return - V_32 ;
}
V_62 -> V_14 = V_14 ;
V_62 -> V_58 = V_58 ;
V_62 -> V_60 = V_60 ;
F_25 ( & V_62 -> V_35 , V_9 ) ;
return 0 ;
}
static void F_42 ( struct V_8 * V_9 )
{
struct V_61 * V_62 , * V_63 ;
F_43 (rel, n, list, head) {
F_44 ( & V_62 -> V_35 ) ;
F_23 ( V_62 ) ;
}
}
static void F_45 ( T_3 * V_64 ,
struct V_8 * V_9 )
{
struct V_61 * V_62 ;
F_46 ( V_65 >= ( 1 << 29 ) ) ;
F_46 ( V_66 >= ( 1 << 3 ) ) ;
F_4 (rel, list, head) {
T_2 * V_67 = ( T_2 * ) ( ( unsigned long ) V_64 + V_62 -> V_58 ) ;
switch ( V_62 -> V_60 ) {
case V_68 :
* V_67 = V_62 -> V_14 -> V_43 ;
break;
case V_69 :
* V_67 = V_70 ;
break;
default:
if ( V_62 -> V_14 -> V_43 == - 1 )
* V_67 = V_70 ;
break;
}
}
}
static int F_47 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
return - V_46 ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_57 * V_72 ,
bool V_73 ,
T_3 * V_74 )
{
T_3 V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_27 * V_28 ;
int V_24 ;
if ( F_18 ( F_19 ( & V_4 -> V_29 , ( unsigned long ) V_72 ,
& V_28 ) == 0 ) ) {
V_77 = F_20 ( V_28 , struct V_76 ,
V_28 ) ;
if ( F_5 ( V_77 -> V_73 != V_73 ) ) {
F_15 ( L_8 ) ;
return - V_46 ;
}
V_79 = & V_77 -> V_80 ;
V_75 = V_77 - V_4 -> V_81 ;
} else {
V_75 = V_4 -> V_82 ;
if ( F_5 ( V_75 >= V_83 ) ) {
F_15 ( L_9
L_10 ) ;
return - V_46 ;
}
V_77 = & V_4 -> V_81 [ V_75 ] ;
V_77 -> V_28 . V_33 = ( unsigned long ) V_72 ;
V_24 = F_22 ( & V_4 -> V_29 , & V_77 -> V_28 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_11
L_4 ) ;
return V_24 ;
}
++ V_4 -> V_82 ;
V_79 = & V_77 -> V_80 ;
V_79 -> V_84 = F_49 ( & V_72 -> V_80 ) ;
V_79 -> V_85 = false ;
F_25 ( & V_79 -> V_35 , & V_4 -> V_86 ) ;
V_77 -> V_73 = V_73 ;
}
if ( V_74 )
* V_74 = V_75 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 = 0 ;
F_4 (val, &sw_context->resource_list, head) {
struct V_13 * V_14 = V_7 -> V_14 ;
V_24 = F_51 ( V_14 , true , V_7 -> V_87 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_14 -> V_88 ) {
struct V_57 * V_72 = V_14 -> V_88 ;
V_24 = F_38
( V_4 , V_72 ,
F_52 ( V_14 ) , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
}
if ( V_4 -> V_11 ) {
struct V_57 * V_89 ;
V_89 =
F_37 ( V_4 -> V_12 ) ;
if ( V_89 &&
V_89 != V_4 -> V_11 ) {
V_24 = - V_46 ;
}
}
return V_24 ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 ;
F_4 (val, &sw_context->resource_list, head) {
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_57 * V_88 = V_14 -> V_88 ;
V_24 = F_54 ( V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( V_24 != - V_90 )
F_15 ( L_12 ) ;
return V_24 ;
}
if ( V_88 && V_14 -> V_88 && ( V_88 != V_14 -> V_88 ) ) {
struct V_57 * V_72 = V_14 -> V_88 ;
V_24 = F_38
( V_4 , V_72 ,
F_52 ( V_14 ) , NULL ) ;
if ( V_24 ) {
F_55 ( & V_72 -> V_80 ) ;
return V_24 ;
}
}
}
return 0 ;
}
static int F_56 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_3 * V_91 ,
struct V_13 * V_14 ,
struct V_6 * * V_92 )
{
int V_24 ;
struct V_6 * V_23 ;
* V_92 = NULL ;
V_24 = F_40 ( & V_4 -> V_93 ,
V_14 ,
F_1 ( V_4 -> V_94 ,
V_91 ) ,
V_68 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_17 ( V_4 , V_14 , & V_23 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_92 )
* V_92 = V_23 ;
return 0 ;
}
static int
F_57 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
enum F_26 V_95 ,
const struct V_96 * V_97 ,
T_3 * V_91 ,
struct V_6 * * V_92 )
{
struct V_98 * V_99 =
& V_4 -> V_100 [ V_95 ] ;
struct V_13 * V_14 ;
struct V_6 * V_23 ;
int V_24 ;
if ( * V_91 == V_101 ) {
if ( V_92 )
* V_92 = NULL ;
if ( V_95 == V_36 ) {
F_15 ( L_13 ) ;
return - V_46 ;
}
return 0 ;
}
if ( F_18 ( V_99 -> V_102 && * V_91 == V_99 -> V_103 ) ) {
const struct V_13 * V_14 = V_99 -> V_14 ;
V_99 -> V_23 -> V_30 = false ;
if ( V_92 )
* V_92 = V_99 -> V_23 ;
return F_40
( & V_4 -> V_93 , V_14 ,
F_1 ( V_4 -> V_94 , V_91 ) ,
V_68 ) ;
}
V_24 = F_58 ( V_22 ,
V_4 -> V_104 -> V_105 ,
* V_91 ,
V_97 ,
& V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_14 ,
( unsigned ) * V_91 ) ;
F_59 () ;
return V_24 ;
}
V_99 -> V_102 = true ;
V_99 -> V_14 = V_14 ;
V_99 -> V_103 = * V_91 ;
V_24 = F_56 ( V_22 , V_4 , V_91 ,
V_14 , & V_23 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_106;
V_99 -> V_23 = V_23 ;
if ( V_92 )
* V_92 = V_23 ;
F_32 ( & V_14 ) ;
return 0 ;
V_106:
F_60 ( V_4 -> V_107 != NULL ) ;
V_4 -> V_107 = V_14 ;
return V_24 ;
}
static int F_61 ( struct V_13 * V_108 )
{
struct V_21 * V_22 = V_108 -> V_22 ;
struct V_57 * V_11 ;
struct {
T_4 V_71 ;
T_5 V_109 ;
} * V_110 ;
V_11 = F_37 ( V_108 ) ;
if ( ! V_11 || V_11 -> V_12 )
return 0 ;
V_110 = F_62 ( V_22 , sizeof( * V_110 ) , V_108 -> V_43 ) ;
if ( V_110 == NULL ) {
F_15 ( L_15 ) ;
return - V_32 ;
}
V_110 -> V_71 . V_43 = V_111 ;
V_110 -> V_71 . V_112 = sizeof( V_110 -> V_109 ) ;
V_110 -> V_109 . V_113 = V_108 -> V_43 ;
V_110 -> V_109 . V_114 = V_11 -> V_80 . V_115 . V_116 ;
F_63 ( V_22 , sizeof( * V_110 ) ) ;
F_3 ( V_108 , V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 ;
F_4 (val, &sw_context->resource_list, head) {
if ( F_5 ( ! V_7 -> V_17 ) )
break;
V_24 = F_65
( F_7 ( V_7 -> V_14 ) ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( V_24 != - V_90 )
F_15 ( L_16 ) ;
return V_24 ;
}
V_24 = F_61 ( V_7 -> V_14 ) ;
if ( V_24 != 0 )
return V_24 ;
}
return 0 ;
}
static int F_66 ( struct V_3 * V_4 ,
enum V_41 V_42 ,
enum V_117 V_118 ,
T_6 V_119 ,
T_6 V_120 [] , T_2 V_121 ,
T_2 V_122 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_123 * V_47 ;
T_2 V_52 ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_47 = V_4 -> V_47 ;
for ( V_52 = 0 ; V_52 < V_121 ; ++ V_52 ) {
struct V_124 V_125 ;
struct V_13 * V_40 = NULL ;
if ( V_120 [ V_52 ] != V_101 ) {
V_40 = F_31 ( V_47 , V_42 , V_120 [ V_52 ] ) ;
if ( F_14 ( V_40 ) ) {
F_15 ( L_17 ) ;
return F_16 ( V_40 ) ;
}
V_24 = F_28 ( V_4 , V_40 ) ;
if ( V_24 ) {
F_15 ( L_18
L_19 ) ;
F_32 ( & V_40 ) ;
return V_24 ;
}
}
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_40 ;
V_125 . V_126 . V_127 = V_118 ;
V_125 . V_119 = V_119 ;
V_125 . V_128 = V_122 + V_52 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
V_119 , V_125 . V_128 ) ;
if ( V_40 )
F_32 ( & V_40 ) ;
}
return 0 ;
}
static int F_68 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_129 {
T_4 V_71 ;
T_3 V_113 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_129 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_113 , NULL ) ;
}
static int F_69 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_131 {
T_4 V_71 ;
T_7 V_109 ;
} * V_110 ;
struct V_6 * V_44 ;
struct V_6 * V_132 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_131 , V_71 ) ;
if ( V_110 -> V_109 . type >= V_133 ) {
F_15 ( L_20 ,
( unsigned ) V_110 -> V_109 . type ) ;
return - V_46 ;
}
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_109 . V_113 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_136 . V_137 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 ) {
struct V_124 V_125 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_132 ? V_132 -> V_14 : NULL ;
V_125 . V_126 . V_127 = V_138 ;
V_125 . V_128 = V_110 -> V_109 . type ;
F_67 ( V_44 -> V_17 ,
& V_125 . V_126 , 0 , V_125 . V_128 ) ;
}
return 0 ;
}
static int F_70 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_131 {
T_4 V_71 ;
T_8 V_109 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_131 , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_139 . V_137 , NULL ) ;
if ( V_24 )
return V_24 ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_140 . V_137 , NULL ) ;
}
static int F_71 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_9 V_109 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_139 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_140 , NULL ) ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_10 V_109 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_141 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_142 , NULL ) ;
}
static int F_74 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_131 {
T_4 V_71 ;
T_11 V_109 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_131 , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_139 . V_137 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_140 . V_137 , NULL ) ;
}
static int F_75 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_131 {
T_4 V_71 ;
T_12 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_131 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_143 . V_137 , NULL ) ;
}
static int F_76 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_131 {
T_4 V_71 ;
T_13 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_131 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 , & V_110 -> V_109 . V_137 ,
NULL ) ;
}
static int F_77 ( struct V_21 * V_22 ,
struct V_57 * V_144 ,
struct V_3 * V_4 )
{
struct V_98 * V_145 =
& V_4 -> V_100 [ V_36 ] ;
int V_24 ;
F_60 ( ! V_145 -> V_102 ) ;
V_4 -> V_146 = V_145 -> V_14 ;
if ( F_5 ( V_144 != V_4 -> V_147 ) ) {
if ( F_5 ( V_144 -> V_80 . V_148 > 4 ) ) {
F_15 ( L_21 ) ;
return - V_46 ;
}
if ( F_5 ( V_4 -> V_147 != NULL ) ) {
V_4 -> V_149 = true ;
V_24 = F_38 ( V_4 ,
V_4 -> V_147 ,
V_22 -> V_34 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_4 -> V_147 = V_144 ;
V_24 = F_38 ( V_4 ,
V_22 -> V_150 ,
V_22 -> V_34 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static void F_78 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_149 ) {
struct V_98 * V_145 =
& V_4 -> V_100 [ V_36 ] ;
struct V_13 * V_48 ;
int V_24 ;
F_60 ( ! V_145 -> V_102 ) ;
V_48 = V_145 -> V_14 ;
V_24 = F_79 ( V_22 , V_48 -> V_43 ) ;
if ( F_5 ( V_24 != 0 ) )
F_15 ( L_22 ) ;
}
if ( V_22 -> V_151 != V_4 -> V_147 ) {
if ( V_22 -> V_151 ) {
F_80 ( V_22 -> V_151 , false ) ;
F_10 ( & V_22 -> V_151 ) ;
}
if ( ! V_4 -> V_149 ) {
F_80 ( V_4 -> V_147 , true ) ;
if ( ! V_22 -> V_152 ) {
F_80 ( V_22 -> V_150 ,
true ) ;
V_22 -> V_152 = true ;
}
F_60 ( V_4 -> V_146 == NULL ) ;
V_22 -> V_153 = V_4 -> V_146 -> V_43 ;
V_22 -> V_154 = true ;
V_22 -> V_151 =
F_81 ( V_4 -> V_147 ) ;
}
}
}
static int F_82 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_14 * V_43 ,
struct V_57 * * V_155 )
{
struct V_57 * V_156 = NULL ;
T_3 V_103 = * V_43 ;
struct V_157 * V_158 ;
int V_24 ;
V_24 = F_83 ( V_4 -> V_104 -> V_105 , V_103 , & V_156 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_23 ) ;
V_24 = - V_46 ;
goto V_106;
}
if ( F_5 ( V_4 -> V_159 >= V_160 ) ) {
F_15 ( L_24
L_25 ) ;
V_24 = - V_46 ;
goto V_106;
}
V_158 = & V_4 -> V_161 [ V_4 -> V_159 ++ ] ;
V_158 -> V_162 = V_43 ;
V_158 -> V_163 = NULL ;
V_24 = F_38 ( V_4 , V_156 , true , & V_158 -> V_164 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_106;
* V_155 = V_156 ;
return 0 ;
V_106:
F_10 ( & V_156 ) ;
* V_155 = NULL ;
return V_24 ;
}
static int F_84 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_15 * V_165 ,
struct V_57 * * V_155 )
{
struct V_57 * V_156 = NULL ;
T_3 V_103 = V_165 -> V_166 ;
struct V_157 * V_158 ;
int V_24 ;
V_24 = F_83 ( V_4 -> V_104 -> V_105 , V_103 , & V_156 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_26 ) ;
V_24 = - V_46 ;
goto V_106;
}
if ( F_5 ( V_4 -> V_159 >= V_160 ) ) {
F_15 ( L_24
L_25 ) ;
V_24 = - V_46 ;
goto V_106;
}
V_158 = & V_4 -> V_161 [ V_4 -> V_159 ++ ] ;
V_158 -> V_163 = V_165 ;
V_24 = F_38 ( V_4 , V_156 , false , & V_158 -> V_164 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_106;
* V_155 = V_156 ;
return 0 ;
V_106:
F_10 ( & V_156 ) ;
* V_155 = NULL ;
return V_24 ;
}
static int F_85 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_167 {
T_4 V_71 ;
T_16 V_168 ;
} * V_110 ;
int V_24 ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_169 ;
if ( V_44 == NULL ) {
F_15 ( L_27 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , struct V_167 , V_71 ) ;
if ( V_110 -> V_168 . type < V_170 ||
V_110 -> V_168 . type >= V_171 )
return - V_46 ;
V_169 = F_33 ( V_44 -> V_14 , V_172 ) ;
V_24 = F_86 ( V_169 , V_110 -> V_168 . V_173 ) ;
F_32 ( & V_169 ) ;
return V_24 ;
}
static int F_87 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_174 {
T_4 V_71 ;
T_17 V_168 ;
} * V_110 ;
struct V_57 * V_156 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_174 , V_71 ) ;
V_24 = F_82 ( V_22 , V_4 , & V_110 -> V_168 . V_114 ,
& V_156 ) ;
if ( V_24 != 0 )
return V_24 ;
V_4 -> V_11 = V_156 ;
V_4 -> V_12 = V_4 -> V_45 -> V_14 ;
F_10 ( & V_156 ) ;
return V_24 ;
}
static int F_88 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_175 {
T_4 V_71 ;
T_18 V_168 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_175 ,
V_71 ) ;
return F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_168 . V_113 ,
NULL ) ;
}
static int F_89 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_176 {
T_4 V_71 ;
T_19 V_168 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_176 ,
V_71 ) ;
if ( F_5 ( V_22 -> V_34 ) ) {
struct {
T_4 V_71 ;
T_18 V_168 ;
} V_177 ;
F_60 ( sizeof( V_177 ) != sizeof( * V_110 ) ) ;
V_177 . V_71 . V_43 = V_178 ;
V_177 . V_71 . V_112 = V_110 -> V_71 . V_112 ;
V_177 . V_168 . V_113 = V_110 -> V_168 . V_113 ;
V_177 . V_168 . type = V_110 -> V_168 . type ;
memcpy ( V_110 , & V_177 , sizeof( * V_110 ) ) ;
return F_88 ( V_22 , V_4 , V_71 ) ;
}
return F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_168 . V_113 ,
NULL ) ;
}
static int F_90 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_156 ;
struct V_179 {
T_4 V_71 ;
T_20 V_168 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_179 , V_71 ) ;
V_24 = F_68 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_82 ( V_22 , V_4 ,
& V_110 -> V_168 . V_114 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_77 ( V_22 , V_156 , V_4 ) ;
F_10 ( & V_156 ) ;
return V_24 ;
}
static int F_91 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_156 ;
struct V_179 {
T_4 V_71 ;
T_21 V_168 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_179 , V_71 ) ;
if ( V_22 -> V_34 ) {
struct {
T_4 V_71 ;
T_20 V_168 ;
} V_177 ;
F_60 ( sizeof( V_177 ) != sizeof( * V_110 ) ) ;
V_177 . V_71 . V_43 = V_180 ;
V_177 . V_71 . V_112 = V_110 -> V_71 . V_112 ;
V_177 . V_168 . V_113 = V_110 -> V_168 . V_113 ;
V_177 . V_168 . type = V_110 -> V_168 . type ;
V_177 . V_168 . V_114 = V_110 -> V_168 . V_181 . V_166 ;
V_177 . V_168 . V_58 = V_110 -> V_168 . V_181 . V_58 ;
memcpy ( V_110 , & V_177 , sizeof( * V_110 ) ) ;
return F_90 ( V_22 , V_4 , V_71 ) ;
}
V_24 = F_68 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_84 ( V_22 , V_4 ,
& V_110 -> V_168 . V_181 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_77 ( V_22 , V_156 , V_4 ) ;
F_10 ( & V_156 ) ;
return V_24 ;
}
static int F_92 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_156 ;
struct V_179 {
T_4 V_71 ;
T_22 V_168 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_179 , V_71 ) ;
V_24 = F_68 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_82 ( V_22 , V_4 ,
& V_110 -> V_168 . V_114 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_156 ) ;
return 0 ;
}
static int F_93 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_156 ;
struct V_179 {
T_4 V_71 ;
T_23 V_168 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_179 , V_71 ) ;
if ( V_22 -> V_34 ) {
struct {
T_4 V_71 ;
T_22 V_168 ;
} V_177 ;
F_60 ( sizeof( V_177 ) != sizeof( * V_110 ) ) ;
V_177 . V_71 . V_43 = V_182 ;
V_177 . V_71 . V_112 = V_110 -> V_71 . V_112 ;
V_177 . V_168 . V_113 = V_110 -> V_168 . V_113 ;
V_177 . V_168 . type = V_110 -> V_168 . type ;
V_177 . V_168 . V_114 = V_110 -> V_168 . V_181 . V_166 ;
V_177 . V_168 . V_58 = V_110 -> V_168 . V_181 . V_58 ;
memcpy ( V_110 , & V_177 , sizeof( * V_110 ) ) ;
return F_92 ( V_22 , V_4 , V_71 ) ;
}
V_24 = F_68 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_84 ( V_22 , V_4 ,
& V_110 -> V_168 . V_181 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_156 ) ;
return 0 ;
}
static int F_94 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_156 = NULL ;
struct V_183 * V_184 = NULL ;
struct V_185 {
T_4 V_71 ;
T_24 V_186 ;
} * V_110 ;
int V_24 ;
T_25 * V_187 ;
T_3 V_188 ;
V_110 = F_20 ( V_71 , struct V_185 , V_71 ) ;
V_187 = ( T_25 * ) ( ( unsigned long ) & V_110 -> V_186 +
V_71 -> V_112 - sizeof( * V_187 ) ) ;
if ( F_5 ( V_187 -> V_189 != sizeof( * V_187 ) ) ) {
F_15 ( L_28 ) ;
return - V_46 ;
}
V_24 = F_84 ( V_22 , V_4 ,
& V_110 -> V_186 . V_190 . V_165 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_188 = V_156 -> V_80 . V_148 * V_191 ;
if ( F_5 ( V_110 -> V_186 . V_190 . V_165 . V_58 > V_188 ) ) {
F_15 ( L_29 ) ;
return - V_46 ;
}
V_188 -= V_110 -> V_186 . V_190 . V_165 . V_58 ;
if ( F_5 ( V_187 -> V_192 > V_188 ) )
V_187 -> V_192 = V_188 ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 , & V_110 -> V_186 . V_193 . V_137 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( F_5 ( V_24 != - V_90 ) )
F_15 ( L_30 ) ;
goto V_194;
}
V_184 = F_95 ( V_4 -> V_100 [ V_134 ] . V_14 ) ;
F_96 ( V_184 , V_4 -> V_104 -> V_105 , & V_156 -> V_80 ,
V_71 ) ;
V_194:
F_10 ( & V_156 ) ;
return V_24 ;
}
static int F_97 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_195 {
T_4 V_71 ;
T_26 V_109 ;
} * V_110 ;
T_27 * V_196 = ( T_27 * ) (
( unsigned long ) V_71 + sizeof( * V_110 ) ) ;
T_28 * V_197 ;
T_3 V_52 ;
T_3 V_198 ;
int V_24 ;
V_24 = F_68 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_110 = F_20 ( V_71 , struct V_195 , V_71 ) ;
V_198 = ( V_71 -> V_112 - sizeof( V_110 -> V_109 ) ) / sizeof( * V_196 ) ;
if ( F_5 ( V_110 -> V_109 . V_199 > V_198 ) ) {
F_15 ( L_31 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_110 -> V_109 . V_199 ; ++ V_52 , ++ V_196 ) {
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_196 -> V_200 . V_201 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_198 = ( V_71 -> V_112 - sizeof( V_110 -> V_109 ) -
V_110 -> V_109 . V_199 * sizeof( * V_196 ) ) / sizeof( * V_197 ) ;
if ( F_5 ( V_110 -> V_109 . V_202 > V_198 ) ) {
F_15 ( L_32 ) ;
return - V_46 ;
}
V_197 = ( T_28 * ) V_196 ;
for ( V_52 = 0 ; V_52 < V_110 -> V_109 . V_202 ; ++ V_52 , ++ V_197 ) {
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_197 -> V_203 . V_201 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static int F_98 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_204 {
T_4 V_71 ;
T_29 V_205 ;
} * V_110 ;
T_30 * V_206 = ( T_30 * )
( ( unsigned long ) V_71 + V_71 -> V_112 + sizeof( V_71 ) ) ;
T_30 * V_207 = ( T_30 * )
( ( unsigned long ) V_71 + sizeof( struct V_204 ) ) ;
struct V_6 * V_44 ;
struct V_6 * V_132 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_204 ,
V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_205 . V_113 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
for (; V_207 < V_206 ; ++ V_207 ) {
if ( F_18 ( V_207 -> V_208 != V_209 ) )
continue;
if ( V_207 -> V_210 >= V_211 ) {
F_15 ( L_33 ,
( unsigned ) V_207 -> V_210 ) ;
return - V_46 ;
}
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_207 -> V_212 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 ) {
struct V_213 V_125 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_132 ? V_132 -> V_14 : NULL ;
V_125 . V_126 . V_127 = V_214 ;
V_125 . V_215 = V_207 -> V_210 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
0 , V_125 . V_215 ) ;
}
}
return 0 ;
}
static int F_99 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_216 )
{
struct V_57 * V_156 ;
int V_24 ;
struct {
T_3 V_71 ;
T_31 V_109 ;
} * V_110 = V_216 ;
V_24 = F_84 ( V_22 , V_4 ,
& V_110 -> V_109 . V_165 ,
& V_156 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_156 ) ;
return V_24 ;
}
static int F_100 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
struct V_6 * V_75 ,
T_3 * V_217 ,
unsigned long V_218 )
{
struct V_57 * V_219 ;
int V_24 ;
V_24 = F_82 ( V_22 , V_4 , V_217 , & V_219 ) ;
if ( V_24 )
return V_24 ;
V_75 -> V_16 = true ;
if ( V_75 -> V_30 )
V_75 -> V_87 = true ;
F_10 ( & V_75 -> V_19 ) ;
V_75 -> V_19 = V_219 ;
V_75 -> V_20 = V_218 ;
return 0 ;
}
static int F_101 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
enum F_26 V_95 ,
const struct V_96
* V_97 ,
T_3 * V_220 ,
T_3 * V_217 ,
unsigned long V_218 )
{
struct V_6 * V_75 ;
int V_24 ;
V_24 = F_57 ( V_22 , V_4 , V_95 ,
V_97 , V_220 , & V_75 ) ;
if ( V_24 )
return V_24 ;
return F_100 ( V_22 , V_4 , V_75 ,
V_217 , V_218 ) ;
}
static int F_102 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_221 {
T_4 V_71 ;
T_32 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_221 , V_71 ) ;
return F_101 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , & V_110 -> V_109 . V_114 ,
0 ) ;
}
static int F_103 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_33 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_223 . V_137 , NULL ) ;
}
static int F_104 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_34 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , NULL ) ;
}
static int F_105 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_35 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_223 . V_137 , NULL ) ;
}
static int F_106 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_36 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , NULL ) ;
}
static int F_107 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_37 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_223 . V_137 , NULL ) ;
}
static int F_108 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_38 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , NULL ) ;
}
static int F_109 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_224 {
T_4 V_71 ;
T_39 V_109 ;
} * V_110 ;
int V_24 ;
T_1 V_112 ;
struct V_6 * V_7 ;
V_110 = F_20 ( V_71 , struct V_224 ,
V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_109 . V_113 ,
& V_7 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( F_5 ( ! V_22 -> V_34 ) )
return 0 ;
V_112 = V_110 -> V_71 . V_112 - sizeof( V_110 -> V_109 ) ;
V_24 = F_110 ( V_22 ,
F_111 ( V_7 -> V_14 ) ,
V_110 -> V_109 . V_225 , V_110 + 1 ,
V_110 -> V_109 . type , V_112 ,
& V_4 -> V_226 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_40 ( & V_4 -> V_93 ,
NULL ,
F_1 ( V_4 -> V_94 ,
& V_110 -> V_71 . V_43 ) ,
V_69 ) ;
}
static int F_112 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_227 {
T_4 V_71 ;
T_40 V_109 ;
} * V_110 ;
int V_24 ;
struct V_6 * V_7 ;
V_110 = F_20 ( V_71 , struct V_227 ,
V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_109 . V_113 ,
& V_7 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( F_5 ( ! V_22 -> V_34 ) )
return 0 ;
V_24 = F_113 ( F_111 ( V_7 -> V_14 ) ,
V_110 -> V_109 . V_225 ,
V_110 -> V_109 . type ,
& V_4 -> V_226 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_40 ( & V_4 -> V_93 ,
NULL ,
F_1 ( V_4 -> V_94 ,
& V_110 -> V_71 . V_43 ) ,
V_69 ) ;
}
static int F_114 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_228 {
T_4 V_71 ;
T_41 V_109 ;
} * V_110 ;
struct V_6 * V_44 , * V_132 = NULL ;
struct V_229 V_125 ;
struct V_13 * V_14 = NULL ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_228 ,
V_71 ) ;
if ( V_110 -> V_109 . type >= V_230 ) {
F_15 ( L_34 ,
( unsigned ) V_110 -> V_109 . type ) ;
return - V_46 ;
}
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_109 . V_113 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( ! V_22 -> V_34 )
return 0 ;
if ( V_110 -> V_109 . V_225 != V_101 ) {
V_14 = F_115 ( F_111 ( V_44 -> V_14 ) ,
V_110 -> V_109 . V_225 ,
V_110 -> V_109 . type ) ;
if ( ! F_14 ( V_14 ) ) {
V_24 = F_56 ( V_22 , V_4 ,
& V_110 -> V_109 . V_225 , V_14 ,
& V_132 ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
}
if ( ! V_132 ) {
V_24 = F_57 ( V_22 , V_4 ,
V_231 ,
V_232 ,
& V_110 -> V_109 . V_225 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_132 ? V_132 -> V_14 : NULL ;
V_125 . V_126 . V_127 = V_233 ;
V_125 . V_119 = V_110 -> V_109 . type - V_234 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
V_125 . V_119 , 0 ) ;
return 0 ;
}
static int F_116 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_235 {
T_4 V_71 ;
T_42 V_109 ;
} * V_110 ;
int V_24 ;
V_110 = F_20 ( V_71 , struct V_235 ,
V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 , & V_110 -> V_109 . V_113 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 )
V_71 -> V_43 = V_236 ;
return 0 ;
}
static int F_117 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_237 {
T_4 V_71 ;
T_43 V_109 ;
} * V_110 ;
V_110 = F_20 ( V_71 , struct V_237 ,
V_71 ) ;
return F_101 ( V_22 , V_4 , V_231 ,
V_232 ,
& V_110 -> V_109 . V_225 , & V_110 -> V_109 . V_114 ,
V_110 -> V_109 . V_238 ) ;
}
static int
F_118 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_44 V_109 ;
} * V_110 ;
struct V_6 * V_132 = NULL ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_239 V_125 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_132 ? V_132 -> V_14 : NULL ;
V_125 . V_126 . V_127 = V_240 ;
V_125 . V_119 = V_110 -> V_109 . type - V_234 ;
V_125 . V_58 = V_110 -> V_109 . V_238 ;
V_125 . V_112 = V_110 -> V_109 . V_241 ;
V_125 . V_128 = V_110 -> V_109 . V_128 ;
if ( V_125 . V_119 >= V_242 ||
V_125 . V_128 >= V_243 ) {
F_15 ( L_35 ,
( unsigned ) V_110 -> V_109 . type ,
( unsigned ) V_125 . V_128 ) ;
return - V_46 ;
}
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
V_125 . V_119 , V_125 . V_128 ) ;
return 0 ;
}
static int F_119 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_45 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
T_2 V_244 = ( V_110 -> V_71 . V_112 - sizeof( V_110 -> V_109 ) ) /
sizeof( V_245 ) ;
if ( ( V_246 ) V_110 -> V_109 . V_247 + ( V_246 ) V_244 >
( V_246 ) V_248 ||
V_110 -> V_109 . type >= V_249 ) {
F_15 ( L_36 ) ;
return - V_46 ;
}
return F_66 ( V_4 , V_250 ,
V_251 ,
V_110 -> V_109 . type - V_234 ,
( void * ) & V_110 [ 1 ] , V_244 ,
V_110 -> V_109 . V_247 ) ;
}
static int F_120 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_46 V_109 ;
} * V_110 ;
struct V_13 * V_14 = NULL ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_229 V_125 ;
int V_24 = 0 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
if ( V_110 -> V_109 . type >= V_249 ) {
F_15 ( L_34 ,
( unsigned ) V_110 -> V_109 . type ) ;
return - V_46 ;
}
if ( V_110 -> V_109 . V_252 != V_101 ) {
V_14 = F_115 ( V_4 -> V_47 , V_110 -> V_109 . V_252 , 0 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( L_37 ) ;
return F_16 ( V_14 ) ;
}
V_24 = F_17 ( V_4 , V_14 , NULL ) ;
if ( V_24 )
goto V_253;
}
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = V_14 ;
V_125 . V_126 . V_127 = V_254 ;
V_125 . V_119 = V_110 -> V_109 . type - V_234 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
V_125 . V_119 , 0 ) ;
V_253:
if ( V_14 )
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_121 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_255 V_125 ;
struct V_6 * V_132 ;
struct {
T_4 V_71 ;
T_47 V_109 ;
T_48 V_216 [] ;
} * V_110 ;
int V_52 , V_24 , V_256 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_256 = ( V_110 -> V_71 . V_112 - sizeof( V_110 -> V_109 ) ) /
sizeof( T_48 ) ;
if ( ( V_246 ) V_256 + ( V_246 ) V_110 -> V_109 . V_257 >
( V_246 ) V_258 ) {
F_15 ( L_38 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_256 ; V_52 ++ ) {
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_216 [ V_52 ] . V_137 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_127 = V_259 ;
V_125 . V_126 . V_14 = ( ( V_132 ) ? V_132 -> V_14 : NULL ) ;
V_125 . V_58 = V_110 -> V_216 [ V_52 ] . V_58 ;
V_125 . V_260 = V_110 -> V_216 [ V_52 ] . V_260 ;
V_125 . V_128 = V_52 + V_110 -> V_109 . V_257 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
0 , V_125 . V_128 ) ;
}
return 0 ;
}
static int F_122 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_261 V_125 ;
struct V_6 * V_132 ;
struct {
T_4 V_71 ;
T_49 V_109 ;
} * V_110 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_137 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = ( ( V_132 ) ? V_132 -> V_14 : NULL ) ;
V_125 . V_126 . V_127 = V_262 ;
V_125 . V_58 = V_110 -> V_109 . V_58 ;
V_125 . V_263 = V_110 -> V_109 . V_263 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 , 0 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_50 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
int V_24 ;
T_2 V_264 = ( V_110 -> V_71 . V_112 - sizeof( V_110 -> V_109 ) ) /
sizeof( V_265 ) ;
if ( V_264 > V_266 ) {
F_15 ( L_39 ) ;
return - V_46 ;
}
V_24 = F_66 ( V_4 , V_267 ,
V_268 , 0 ,
& V_110 -> V_109 . V_269 , 1 , 0 ) ;
if ( V_24 )
return V_24 ;
return F_66 ( V_4 , V_270 ,
V_271 , 0 ,
( void * ) & V_110 [ 1 ] , V_264 , 0 ) ;
}
static int F_124 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_51 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
return F_30 ( V_4 , V_270 ,
V_110 -> V_109 . V_272 ) ;
}
static int F_125 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_52 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
return F_30 ( V_4 , V_267 ,
V_110 -> V_109 . V_269 ) ;
}
static int F_126 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_6 * V_273 ;
struct V_13 * V_14 ;
enum V_41 V_42 ;
int V_24 ;
struct {
T_4 V_71 ;
T_6 V_274 ;
T_6 V_137 ;
} * V_110 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_42 = F_127 ( V_71 -> V_43 ) ;
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_137 , & V_273 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_14 = F_33 ( V_44 -> V_14 , V_275 [ V_42 ] ) ;
V_24 = F_86 ( V_14 , V_110 -> V_274 ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_128 ( V_4 -> V_47 ,
V_44 -> V_14 ,
V_273 -> V_14 ,
V_42 ,
V_110 -> V_274 ,
V_71 ,
V_71 -> V_112 + sizeof( * V_71 ) ,
& V_4 -> V_226 ) ;
}
static int F_129 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_276 V_125 ;
struct V_6 * V_132 ;
struct {
T_4 V_71 ;
T_53 V_109 ;
T_54 V_277 [] ;
} * V_110 ;
int V_52 , V_24 , V_256 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_256 = ( V_110 -> V_71 . V_112 - sizeof( V_110 -> V_109 ) ) /
sizeof( T_54 ) ;
if ( V_256 > V_278 ) {
F_15 ( L_40 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_256 ; V_52 ++ ) {
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_277 [ V_52 ] . V_137 , & V_132 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_125 . V_126 . V_48 = V_44 -> V_14 ;
V_125 . V_126 . V_14 = ( ( V_132 ) ? V_132 -> V_14 : NULL ) ;
V_125 . V_126 . V_127 = V_279 ,
V_125 . V_58 = V_110 -> V_277 [ V_52 ] . V_58 ;
V_125 . V_112 = V_110 -> V_277 [ V_52 ] . V_241 ;
V_125 . V_128 = V_52 ;
F_67 ( V_44 -> V_17 , & V_125 . V_126 ,
0 , V_125 . V_128 ) ;
}
return 0 ;
}
static int F_130 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_6 V_274 ;
} * V_110 ;
enum V_280 V_281 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_281 = F_131 ( V_71 -> V_43 ) ;
V_14 = F_33 ( V_44 -> V_14 , V_282 [ V_281 ] ) ;
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
V_24 = F_86 ( V_14 , V_110 -> V_274 ) ;
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_132 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
union {
T_55 V_283 ;
T_56 V_284 ;
T_57 V_285 ;
T_58 V_137 ;
};
} * V_110 ;
F_46 ( F_133 ( F_72 ( * V_110 ) , V_283 . V_137 ) !=
F_133 ( F_72 ( * V_110 ) , V_137 ) ) ;
F_46 ( F_133 ( F_72 ( * V_110 ) , V_284 . V_137 ) !=
F_133 ( F_72 ( * V_110 ) , V_137 ) ) ;
F_46 ( F_133 ( F_72 ( * V_110 ) , V_285 . V_137 ) !=
F_133 ( F_72 ( * V_110 ) , V_137 ) ) ;
V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_137 , NULL ) ;
}
static int F_134 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_135 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct {
T_4 V_71 ;
union V_286 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
enum V_41 V_42 = F_127 ( V_71 -> V_43 ) ;
struct V_13 * V_40 ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_24 = F_136 ( V_4 -> V_47 ,
V_110 -> V_109 . V_287 , V_42 ,
& V_4 -> V_226 ,
& V_40 ) ;
if ( V_24 || ! V_40 )
return V_24 ;
return F_40 ( & V_4 -> V_93 ,
V_40 ,
F_1 ( V_4 -> V_94 ,
& V_110 -> V_71 . V_43 ) ,
V_288 ) ;
}
static int F_137 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_59 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_14 = F_33 ( V_44 -> V_14 , V_289 ) ;
V_24 = F_86 ( V_14 , V_110 -> V_109 . V_252 ) ;
F_32 ( & V_14 ) ;
if ( V_24 )
return V_24 ;
return F_138 ( V_4 -> V_47 , V_44 -> V_14 ,
V_110 -> V_109 . V_252 , V_110 -> V_109 . type ,
& V_4 -> V_226 ) ;
}
static int F_139 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct {
T_4 V_71 ;
T_60 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_24 = F_113 ( V_4 -> V_47 , V_110 -> V_109 . V_252 , 0 ,
& V_4 -> V_226 ) ;
if ( V_24 )
F_15 ( L_41 ) ;
return V_24 ;
}
static int F_140 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 ;
struct V_6 * V_132 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_61 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
int V_24 ;
if ( V_110 -> V_109 . V_113 != V_101 ) {
V_24 = F_57 ( V_22 , V_4 , V_36 ,
V_130 ,
& V_110 -> V_109 . V_113 , & V_44 ) ;
if ( V_24 )
return V_24 ;
} else {
V_44 = V_4 -> V_45 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
}
V_14 = F_115 ( F_111 ( V_44 -> V_14 ) ,
V_110 -> V_109 . V_225 , 0 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( L_42 ) ;
return F_16 ( V_14 ) ;
}
V_24 = F_17 ( V_4 , V_14 , & V_132 ) ;
if ( V_24 ) {
F_15 ( L_43 ) ;
goto V_253;
}
V_24 = F_100 ( V_22 , V_4 , V_132 ,
& V_110 -> V_109 . V_114 ,
V_110 -> V_109 . V_238 ) ;
V_253:
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_141 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_62 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
return F_30 ( V_4 , V_250 ,
V_110 -> V_109 . V_290 ) ;
}
static int F_142 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_63 V_109 ;
} * V_110 = F_20 ( V_71 , F_72 ( * V_110 ) , V_71 ) ;
int V_24 ;
V_24 = F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_141 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_57 ( V_22 , V_4 , V_134 ,
V_135 ,
& V_110 -> V_109 . V_291 , NULL ) ;
}
static int F_143 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_216 , T_3 * V_112 )
{
T_3 V_292 = * V_112 ;
T_3 V_293 ;
V_293 = ( ( T_3 * ) V_216 ) [ 0 ] ;
switch ( V_293 ) {
case V_294 :
* V_112 = sizeof( T_3 ) + sizeof( V_295 ) ;
break;
case V_296 :
* V_112 = sizeof( T_3 ) + sizeof( T_31 ) ;
break;
case V_297 :
* V_112 = sizeof( T_3 ) + sizeof( V_298 ) ;
break;
case V_299 :
* V_112 = sizeof( T_3 ) + sizeof( V_298 ) ;
break;
default:
F_15 ( L_44 , V_293 ) ;
return - V_46 ;
}
if ( * V_112 > V_292 ) {
F_15 ( L_45
L_46 , V_293 ) ;
return - V_46 ;
}
if ( F_5 ( ! V_4 -> V_300 ) ) {
F_15 ( L_47 , V_293 ) ;
return - V_301 ;
}
if ( V_293 == V_296 )
return F_99 ( V_22 , V_4 , V_216 ) ;
return 0 ;
}
static int F_144 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_216 , T_3 * V_112 )
{
T_3 V_293 ;
T_3 V_292 = * V_112 ;
T_4 * V_71 = ( T_4 * ) V_216 ;
int V_24 ;
const struct V_302 * V_51 ;
bool V_303 = V_22 -> V_304 & V_305 ;
V_293 = ( ( T_3 * ) V_216 ) [ 0 ] ;
if ( F_5 ( V_293 < V_306 ) )
return F_143 ( V_22 , V_4 , V_216 , V_112 ) ;
V_293 = V_71 -> V_43 ;
* V_112 = V_71 -> V_112 + sizeof( T_4 ) ;
V_293 -= V_307 ;
if ( F_5 ( * V_112 > V_292 ) )
goto V_308;
if ( F_5 ( V_293 >= V_309 - V_307 ) )
goto V_308;
V_51 = & V_310 [ V_293 ] ;
if ( F_5 ( ! V_51 -> V_311 ) )
goto V_308;
if ( F_5 ( ! V_51 -> V_312 && ! V_4 -> V_300 ) )
goto V_313;
if ( F_5 ( V_51 -> V_314 && V_303 ) )
goto V_315;
if ( F_5 ( V_51 -> V_316 && ! V_303 ) )
goto V_317;
V_24 = V_51 -> V_311 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_308;
return 0 ;
V_308:
F_15 ( L_48 ,
V_293 + V_307 ) ;
return - V_46 ;
V_313:
F_15 ( L_49 ,
V_293 + V_307 ) ;
return - V_301 ;
V_315:
F_15 ( L_50 ,
V_293 + V_307 ) ;
return - V_46 ;
V_317:
F_15 ( L_51 ,
V_293 + V_307 ) ;
return - V_46 ;
}
static int F_145 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_216 ,
T_3 V_112 )
{
T_64 V_318 = V_112 ;
int V_24 ;
V_4 -> V_94 = V_216 ;
while ( V_318 > 0 ) {
V_112 = V_318 ;
V_24 = F_144 ( V_22 , V_4 , V_216 , & V_112 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_216 = ( void * ) ( ( unsigned long ) V_216 + V_112 ) ;
V_318 -= V_112 ;
}
if ( F_5 ( V_318 != 0 ) ) {
F_15 ( L_52 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_146 ( struct V_3 * V_4 )
{
V_4 -> V_159 = 0 ;
}
static void F_147 ( struct V_3 * V_4 )
{
T_3 V_52 ;
struct V_157 * V_158 ;
struct V_78 * V_319 ;
struct V_320 * V_84 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_159 ; ++ V_52 ) {
V_158 = & V_4 -> V_161 [ V_52 ] ;
V_319 = & V_4 -> V_81 [ V_158 -> V_164 ] . V_80 ;
V_84 = V_319 -> V_84 ;
switch ( V_84 -> V_115 . V_321 ) {
case V_322 :
V_158 -> V_163 -> V_58 += V_84 -> V_58 ;
V_158 -> V_163 -> V_166 = V_323 ;
break;
case V_324 :
V_158 -> V_163 -> V_166 = V_84 -> V_115 . V_116 ;
break;
case V_325 :
* V_158 -> V_162 = V_84 -> V_115 . V_116 ;
break;
default:
F_148 () ;
}
}
F_146 ( V_4 ) ;
}
static void F_149 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 , * V_326 ;
F_43 (val, val_next, list, head) {
F_150 ( & V_7 -> V_35 ) ;
F_32 ( & V_7 -> V_14 ) ;
if ( V_7 -> V_17 ) {
if ( V_7 -> V_17 != V_4 -> V_17 )
F_8 ( V_7 -> V_17 ) ;
else
V_4 -> V_18 = false ;
V_7 -> V_17 = NULL ;
}
F_23 ( V_7 ) ;
}
}
static void F_151 ( struct V_3 * V_4 )
{
struct V_76 * V_51 , * V_327 ;
struct V_6 * V_7 ;
F_43 (entry, next, &sw_context->validate_nodes,
base.head) {
F_44 ( & V_51 -> V_80 . V_35 ) ;
F_152 ( & V_51 -> V_80 . V_84 ) ;
( void ) F_153 ( & V_4 -> V_29 , & V_51 -> V_28 ) ;
V_4 -> V_82 -- ;
}
F_60 ( V_4 -> V_82 != 0 ) ;
F_4 (val, &sw_context->resource_list, head)
( void ) F_153 ( & V_4 -> V_29 , & V_7 -> V_28 ) ;
}
int F_154 ( struct V_21 * V_22 ,
struct V_320 * V_84 ,
bool V_328 ,
bool V_73 )
{
struct V_57 * V_72 = F_20 ( V_84 , struct V_57 ,
V_80 ) ;
int V_24 ;
if ( V_72 -> V_329 > 0 )
return 0 ;
if ( V_73 )
return F_155 ( V_84 , & V_330 , V_328 ,
false ) ;
V_24 = F_155 ( V_84 , & V_331 , V_328 ,
false ) ;
if ( F_18 ( V_24 == 0 || V_24 == - V_90 ) )
return V_24 ;
V_24 = F_155 ( V_84 , & V_332 , V_328 , false ) ;
return V_24 ;
}
static int F_156 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
struct V_76 * V_51 ;
int V_24 ;
F_4 (entry, &sw_context->validate_nodes, base.head) {
V_24 = F_154 ( V_22 , V_51 -> V_80 . V_84 ,
true ,
V_51 -> V_73 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static int F_157 ( struct V_3 * V_4 ,
T_3 V_112 )
{
if ( F_18 ( V_4 -> V_333 >= V_112 ) )
return 0 ;
if ( V_4 -> V_333 == 0 )
V_4 -> V_333 = V_334 ;
while ( V_4 -> V_333 < V_112 ) {
V_4 -> V_333 =
F_158 ( V_4 -> V_333 +
( V_4 -> V_333 >> 1 ) ) ;
}
F_159 ( V_4 -> V_335 ) ;
V_4 -> V_335 = F_160 ( V_4 -> V_333 ) ;
if ( V_4 -> V_335 == NULL ) {
F_15 ( L_53 ) ;
V_4 -> V_333 = 0 ;
return - V_32 ;
}
return 0 ;
}
int F_161 ( struct V_336 * V_337 ,
struct V_21 * V_22 ,
struct V_338 * * V_339 ,
T_3 * V_340 )
{
T_3 V_341 ;
int V_24 ;
bool V_342 = false ;
F_60 ( V_340 != NULL && V_337 == NULL ) ;
V_24 = F_162 ( V_22 , & V_341 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_54 ) ;
V_342 = true ;
}
if ( V_340 != NULL )
V_24 = F_163 ( V_337 , V_22 -> V_343 ,
V_341 , V_339 , V_340 ) ;
else
V_24 = F_164 ( V_22 -> V_343 , V_341 , V_339 ) ;
if ( F_5 ( V_24 != 0 && ! V_342 ) ) {
( void ) F_165 ( V_22 , false , false ,
V_341 , false ,
V_344 ) ;
* V_339 = NULL ;
}
return 0 ;
}
void
F_166 ( struct V_21 * V_22 ,
struct V_345 * V_346 ,
int V_24 ,
struct V_347 T_65 * V_348 ,
struct V_338 * V_349 ,
T_3 V_350 )
{
struct V_347 V_351 ;
if ( V_348 == NULL )
return;
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
V_351 . error = V_24 ;
if ( V_24 == 0 ) {
F_60 ( V_349 == NULL ) ;
V_351 . V_103 = V_350 ;
V_351 . V_352 = V_349 -> V_80 . V_352 ;
F_167 ( V_22 , & V_22 -> V_353 ) ;
V_351 . V_354 = V_22 -> V_355 ;
}
V_24 = F_168 ( V_348 , & V_351 ,
sizeof( V_351 ) ) ;
if ( F_5 ( V_24 != 0 ) && ( V_351 . error == 0 ) ) {
F_169 ( V_346 -> V_105 ,
V_350 , V_356 ) ;
F_15 ( L_55 ) ;
( void ) F_170 ( V_349 , false , false ,
V_344 ) ;
}
}
static int F_171 ( struct V_21 * V_22 ,
void * V_357 ,
T_2 V_358 ,
struct V_3 * V_4 )
{
void * V_110 ;
if ( V_4 -> V_45 )
V_110 = F_62 ( V_22 , V_358 ,
V_4 -> V_45 -> V_14 -> V_43 ) ;
else
V_110 = F_172 ( V_22 , V_358 ) ;
if ( ! V_110 ) {
F_15 ( L_56 ) ;
return - V_32 ;
}
F_147 ( V_4 ) ;
memcpy ( V_110 , V_357 , V_358 ) ;
F_45 ( V_110 , & V_4 -> V_93 ) ;
F_42 ( & V_4 -> V_93 ) ;
F_63 ( V_22 , V_358 ) ;
return 0 ;
}
static int F_173 ( struct V_21 * V_22 ,
struct V_359 * V_71 ,
T_2 V_358 ,
struct V_3 * V_4 )
{
T_2 V_43 = ( ( V_4 -> V_45 ) ? V_4 -> V_45 -> V_14 -> V_43 :
V_101 ) ;
void * V_110 = F_174 ( V_22 -> V_360 , V_358 ,
V_43 , false , V_71 ) ;
F_147 ( V_4 ) ;
F_45 ( V_110 , & V_4 -> V_93 ) ;
F_42 ( & V_4 -> V_93 ) ;
F_175 ( V_22 -> V_360 , V_358 , V_71 , false ) ;
return 0 ;
}
static void * F_176 ( struct V_21 * V_22 ,
void T_65 * V_361 ,
void * V_357 ,
T_2 V_358 ,
struct V_359 * * V_71 )
{
T_1 V_362 ;
int V_24 ;
* V_71 = NULL ;
if ( V_358 > V_65 ) {
F_15 ( L_57 ) ;
return F_177 ( - V_46 ) ;
}
if ( ! V_22 -> V_360 || V_357 )
return V_357 ;
V_362 = V_358 + 512 ;
V_362 = F_178 ( T_1 , V_362 , V_65 ) ;
V_357 = F_179 ( V_22 -> V_360 , V_362 ,
true , V_71 ) ;
if ( F_14 ( V_357 ) )
return V_357 ;
V_24 = F_180 ( V_357 , V_361 ,
V_358 ) ;
if ( V_24 ) {
F_15 ( L_58 ) ;
F_181 ( * V_71 ) ;
* V_71 = NULL ;
return F_177 ( - V_363 ) ;
}
return V_357 ;
}
static int F_182 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_6 * V_44 ;
struct V_13 * V_14 ;
int V_24 ;
if ( V_103 == V_101 )
return 0 ;
V_24 = F_58 ( V_22 , V_4 -> V_104 -> V_105 ,
V_103 , V_130 ,
& V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_59 ,
( unsigned ) V_103 ) ;
return V_24 ;
}
V_24 = F_17 ( V_4 , V_14 , & V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_4 -> V_45 = V_44 ;
V_4 -> V_47 = F_111 ( V_14 ) ;
V_25:
F_32 ( & V_14 ) ;
return V_24 ;
}
int F_183 ( struct V_336 * V_337 ,
struct V_21 * V_22 ,
void T_65 * V_361 ,
void * V_357 ,
T_3 V_358 ,
T_66 V_364 ,
T_3 V_365 ,
struct V_347 T_65 * V_348 ,
struct V_338 * * V_366 )
{
struct V_3 * V_4 = & V_22 -> V_48 ;
struct V_338 * V_349 = NULL ;
struct V_13 * V_107 ;
struct V_8 V_10 ;
struct V_359 * V_71 ;
struct V_367 V_368 ;
T_3 V_103 ;
int V_24 ;
if ( V_364 ) {
V_24 = F_184 ( V_22 , & V_22 -> V_353 . V_369 ,
V_364 ) ;
if ( V_24 )
return V_24 ;
}
V_357 = F_176 ( V_22 , V_361 ,
V_357 , V_358 ,
& V_71 ) ;
if ( F_14 ( V_357 ) )
return F_16 ( V_357 ) ;
V_24 = F_185 ( & V_22 -> V_370 ) ;
if ( V_24 ) {
V_24 = - V_90 ;
goto V_371;
}
V_4 -> V_300 = false ;
if ( V_357 == NULL ) {
V_24 = F_157 ( V_4 , V_358 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_372;
V_24 = F_180 ( V_4 -> V_335 ,
V_361 , V_358 ) ;
if ( F_5 ( V_24 != 0 ) ) {
V_24 = - V_363 ;
F_15 ( L_58 ) ;
goto V_372;
}
V_357 = V_4 -> V_335 ;
} else if ( ! V_71 )
V_4 -> V_300 = true ;
V_4 -> V_104 = V_345 ( V_337 ) ;
V_4 -> V_159 = 0 ;
V_4 -> V_82 = 0 ;
F_186 ( & V_4 -> V_10 ) ;
F_186 ( & V_4 -> V_38 ) ;
V_4 -> V_147 = V_22 -> V_151 ;
V_4 -> V_146 = NULL ;
V_4 -> V_149 = false ;
V_4 -> V_45 = NULL ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = NULL ;
memset ( V_4 -> V_100 , 0 , sizeof( V_4 -> V_100 ) ) ;
F_186 ( & V_4 -> V_86 ) ;
F_186 ( & V_4 -> V_93 ) ;
if ( V_4 -> V_17 )
F_187 ( V_4 -> V_17 ) ;
if ( ! V_4 -> V_373 ) {
V_24 = F_188 ( & V_4 -> V_29 , V_374 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_372;
V_4 -> V_373 = true ;
}
F_186 ( & V_4 -> V_226 ) ;
F_186 ( & V_10 ) ;
V_24 = F_182 ( V_22 , V_4 , V_365 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_189 ( & V_4 -> V_38 ,
& V_4 -> V_10 ) ;
goto V_375;
}
V_24 = F_145 ( V_22 , V_4 , V_357 ,
V_358 ) ;
F_189 ( & V_4 -> V_38 ,
& V_4 -> V_10 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_375;
V_24 = F_50 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_375;
V_24 = F_190 ( & V_368 , & V_4 -> V_86 ,
true , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_375;
V_24 = F_156 ( V_22 , V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_24 = F_53 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_24 = F_185 ( & V_22 -> V_55 ) ;
if ( F_5 ( V_24 != 0 ) ) {
V_24 = - V_90 ;
goto V_25;
}
if ( V_22 -> V_34 ) {
V_24 = F_64 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_376;
}
if ( ! V_71 ) {
V_24 = F_171 ( V_22 , V_357 ,
V_358 , V_4 ) ;
} else {
V_24 = F_173 ( V_22 , V_71 , V_358 ,
V_4 ) ;
V_71 = NULL ;
}
F_39 ( & V_22 -> V_55 ) ;
if ( V_24 )
goto V_25;
F_78 ( V_22 , V_4 ) ;
V_24 = F_161 ( V_337 , V_22 ,
& V_349 ,
( V_348 ) ? & V_103 : NULL ) ;
if ( V_24 != 0 )
F_15 ( L_54 ) ;
F_2 ( V_4 , false ) ;
F_191 ( & V_368 , & V_4 -> V_86 ,
( void * ) V_349 ) ;
if ( F_5 ( V_22 -> V_151 != NULL &&
! V_22 -> V_154 ) )
F_192 ( V_22 , V_349 ) ;
F_151 ( V_4 ) ;
F_166 ( V_22 , V_345 ( V_337 ) , V_24 ,
V_348 , V_349 , V_103 ) ;
if ( F_5 ( V_366 != NULL ) ) {
* V_366 = V_349 ;
V_349 = NULL ;
} else if ( F_18 ( V_349 != NULL ) ) {
F_193 ( & V_349 ) ;
}
F_189 ( & V_4 -> V_10 , & V_10 ) ;
F_194 ( & V_4 -> V_226 ) ;
F_39 ( & V_22 -> V_370 ) ;
F_149 ( V_4 , & V_10 ) ;
return 0 ;
V_376:
F_39 ( & V_22 -> V_55 ) ;
V_25:
F_195 ( & V_368 , & V_4 -> V_86 ) ;
V_375:
F_2 ( V_4 , true ) ;
F_42 ( & V_4 -> V_93 ) ;
F_146 ( V_4 ) ;
F_151 ( V_4 ) ;
if ( F_5 ( V_22 -> V_151 != NULL &&
! V_22 -> V_154 ) )
F_192 ( V_22 , NULL ) ;
V_372:
F_189 ( & V_4 -> V_10 , & V_10 ) ;
V_107 = V_4 -> V_107 ;
V_4 -> V_107 = NULL ;
F_196 ( & V_4 -> V_226 ) ;
F_39 ( & V_22 -> V_370 ) ;
F_149 ( V_4 , & V_10 ) ;
if ( F_5 ( V_107 != NULL ) )
F_32 ( & V_107 ) ;
V_371:
if ( V_71 )
F_181 ( V_71 ) ;
return V_24 ;
}
static void F_197 ( struct V_21 * V_22 )
{
F_15 ( L_60 ) ;
( void ) F_165 ( V_22 , false , true , 0 , false , 10 * V_377 ) ;
F_80 ( V_22 -> V_151 , false ) ;
if ( V_22 -> V_152 ) {
F_80 ( V_22 -> V_150 , false ) ;
V_22 -> V_152 = false ;
}
}
void F_192 ( struct V_21 * V_22 ,
struct V_338 * V_349 )
{
int V_24 = 0 ;
struct V_8 V_378 ;
struct V_78 V_379 , V_380 ;
struct V_338 * V_381 = NULL ;
struct V_367 V_368 ;
if ( V_22 -> V_151 == NULL )
goto V_372;
F_186 ( & V_378 ) ;
V_379 . V_84 = F_49 ( & V_22 -> V_151 -> V_80 ) ;
V_379 . V_85 = false ;
F_25 ( & V_379 . V_35 , & V_378 ) ;
V_380 . V_84 = F_49 ( & V_22 -> V_150 -> V_80 ) ;
V_380 . V_85 = false ;
F_25 ( & V_380 . V_35 , & V_378 ) ;
V_24 = F_190 ( & V_368 , & V_378 ,
false , NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_197 ( V_22 ) ;
goto V_382;
}
if ( V_22 -> V_154 ) {
F_60 ( V_349 != NULL ) ;
V_24 = F_79 ( V_22 , V_22 -> V_153 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_197 ( V_22 ) ;
goto V_383;
}
V_22 -> V_154 = false ;
}
F_80 ( V_22 -> V_151 , false ) ;
if ( V_22 -> V_152 ) {
F_80 ( V_22 -> V_150 , false ) ;
V_22 -> V_152 = false ;
}
if ( V_349 == NULL ) {
( void ) F_161 ( NULL , V_22 , & V_381 ,
NULL ) ;
V_349 = V_381 ;
}
F_191 ( & V_368 , & V_378 , ( void * ) V_349 ) ;
if ( V_381 != NULL )
F_193 ( & V_381 ) ;
F_152 ( & V_380 . V_84 ) ;
F_152 ( & V_379 . V_84 ) ;
F_10 ( & V_22 -> V_151 ) ;
V_372:
return;
V_383:
F_195 ( & V_368 , & V_378 ) ;
V_382:
F_152 ( & V_380 . V_84 ) ;
F_152 ( & V_379 . V_84 ) ;
F_10 ( & V_22 -> V_151 ) ;
}
void F_198 ( struct V_21 * V_22 )
{
F_34 ( & V_22 -> V_370 ) ;
if ( V_22 -> V_154 )
F_192 ( V_22 , NULL ) ;
F_39 ( & V_22 -> V_370 ) ;
}
int F_199 ( struct V_384 * V_385 , unsigned long V_386 ,
struct V_336 * V_337 , T_1 V_112 )
{
struct V_21 * V_22 = F_200 ( V_385 ) ;
struct V_387 V_388 ;
int V_24 ;
static const T_1 V_389 [] = {
F_133 ( struct V_387 , V_390 ) ,
sizeof(struct V_387 ) } ;
if ( F_5 ( V_112 < V_389 [ 0 ] ) ) {
F_15 ( L_61 ,
V_391 ) ;
return - V_46 ;
}
if ( F_180 ( & V_388 , ( void T_65 * ) V_386 , V_389 [ 0 ] ) != 0 )
return - V_363 ;
if ( F_5 ( V_388 . V_392 > V_393 ||
V_388 . V_392 == 0 ) ) {
F_15 ( L_62 ) ;
return - V_46 ;
}
if ( V_388 . V_392 > 1 &&
F_180 ( & V_388 . V_390 ,
( void T_65 * ) ( V_386 + V_389 [ 0 ] ) ,
V_389 [ V_388 . V_392 - 1 ] -
V_389 [ 0 ] ) != 0 )
return - V_363 ;
switch ( V_388 . V_392 ) {
case 1 :
V_388 . V_390 = ( T_3 ) - 1 ;
break;
case 2 :
if ( V_388 . V_394 != 0 ) {
F_15 ( L_63 ) ;
return - V_46 ;
}
break;
default:
break;
}
V_24 = F_201 ( & V_22 -> V_395 , true ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_183 ( V_337 , V_22 ,
( void T_65 * ) ( unsigned long ) V_388 . V_396 ,
NULL , V_388 . V_358 , V_388 . V_364 ,
V_388 . V_390 ,
( void T_65 * ) ( unsigned long ) V_388 . V_351 ,
NULL ) ;
F_202 ( & V_22 -> V_395 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_203 ( V_22 ) ;
return 0 ;
}
