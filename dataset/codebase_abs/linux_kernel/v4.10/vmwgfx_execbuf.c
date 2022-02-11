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
if ( F_5 ( V_23 == NULL ) ) {
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
if ( F_5 ( V_62 == NULL ) ) {
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
return F_48 ( V_72 ) ? : - V_46 ;
}
static int F_49 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_57 * V_73 ,
bool V_74 ,
T_3 * V_75 )
{
T_3 V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_27 * V_28 ;
int V_24 ;
if ( F_18 ( F_19 ( & V_4 -> V_29 , ( unsigned long ) V_73 ,
& V_28 ) == 0 ) ) {
V_78 = F_20 ( V_28 , struct V_77 ,
V_28 ) ;
if ( F_5 ( V_78 -> V_74 != V_74 ) ) {
F_15 ( L_8 ) ;
return - V_46 ;
}
V_80 = & V_78 -> V_81 ;
V_76 = V_78 - V_4 -> V_82 ;
} else {
V_76 = V_4 -> V_83 ;
if ( F_5 ( V_76 >= V_84 ) ) {
F_15 ( L_9
L_10 ) ;
return - V_46 ;
}
V_78 = & V_4 -> V_82 [ V_76 ] ;
V_78 -> V_28 . V_33 = ( unsigned long ) V_73 ;
V_24 = F_22 ( & V_4 -> V_29 , & V_78 -> V_28 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_11
L_4 ) ;
return V_24 ;
}
++ V_4 -> V_83 ;
V_80 = & V_78 -> V_81 ;
V_80 -> V_85 = F_50 ( & V_73 -> V_81 ) ;
V_80 -> V_86 = false ;
F_25 ( & V_80 -> V_35 , & V_4 -> V_87 ) ;
V_78 -> V_74 = V_74 ;
}
if ( V_75 )
* V_75 = V_76 ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 = 0 ;
F_4 (val, &sw_context->resource_list, head) {
struct V_13 * V_14 = V_7 -> V_14 ;
V_24 = F_52 ( V_14 , true , V_7 -> V_88 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_14 -> V_89 ) {
struct V_57 * V_73 = V_14 -> V_89 ;
V_24 = F_38
( V_4 , V_73 ,
F_53 ( V_14 ) , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
}
if ( V_4 -> V_11 ) {
struct V_57 * V_90 ;
V_90 =
F_37 ( V_4 -> V_12 ) ;
if ( V_90 &&
V_90 != V_4 -> V_11 ) {
V_24 = - V_46 ;
}
}
return V_24 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 ;
F_4 (val, &sw_context->resource_list, head) {
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_57 * V_89 = V_14 -> V_89 ;
V_24 = F_55 ( V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( V_24 != - V_91 )
F_15 ( L_12 ) ;
return V_24 ;
}
if ( V_89 && V_14 -> V_89 && ( V_89 != V_14 -> V_89 ) ) {
struct V_57 * V_73 = V_14 -> V_89 ;
V_24 = F_38
( V_4 , V_73 ,
F_53 ( V_14 ) , NULL ) ;
if ( V_24 ) {
F_56 ( & V_73 -> V_81 ) ;
return V_24 ;
}
}
}
return 0 ;
}
static int F_57 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_3 * V_92 ,
struct V_13 * V_14 ,
struct V_6 * * V_93 )
{
int V_24 ;
struct V_6 * V_23 ;
* V_93 = NULL ;
V_24 = F_40 ( & V_4 -> V_94 ,
V_14 ,
F_1 ( V_4 -> V_95 ,
V_92 ) ,
V_68 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_17 ( V_4 , V_14 , & V_23 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_93 )
* V_93 = V_23 ;
return 0 ;
}
static int
F_58 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
enum F_26 V_96 ,
const struct V_97 * V_98 ,
T_3 * V_92 ,
struct V_6 * * V_93 )
{
struct V_99 * V_100 =
& V_4 -> V_101 [ V_96 ] ;
struct V_13 * V_14 ;
struct V_6 * V_23 ;
int V_24 ;
if ( * V_92 == V_102 ) {
if ( V_93 )
* V_93 = NULL ;
if ( V_96 == V_36 ) {
F_15 ( L_13 ) ;
return - V_46 ;
}
return 0 ;
}
if ( F_18 ( V_100 -> V_103 && * V_92 == V_100 -> V_104 ) ) {
const struct V_13 * V_14 = V_100 -> V_14 ;
V_100 -> V_23 -> V_30 = false ;
if ( V_93 )
* V_93 = V_100 -> V_23 ;
return F_40
( & V_4 -> V_94 , V_14 ,
F_1 ( V_4 -> V_95 , V_92 ) ,
V_68 ) ;
}
V_24 = F_59 ( V_22 ,
V_4 -> V_105 -> V_106 ,
* V_92 ,
V_98 ,
& V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_14 ,
( unsigned ) * V_92 ) ;
F_60 () ;
return V_24 ;
}
V_100 -> V_103 = true ;
V_100 -> V_14 = V_14 ;
V_100 -> V_104 = * V_92 ;
V_24 = F_57 ( V_22 , V_4 , V_92 ,
V_14 , & V_23 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_107;
V_100 -> V_23 = V_23 ;
if ( V_93 )
* V_93 = V_23 ;
F_32 ( & V_14 ) ;
return 0 ;
V_107:
F_61 ( V_4 -> V_108 != NULL ) ;
V_4 -> V_108 = V_14 ;
return V_24 ;
}
static int F_62 ( struct V_13 * V_109 )
{
struct V_21 * V_22 = V_109 -> V_22 ;
struct V_57 * V_11 ;
struct {
T_4 V_71 ;
T_5 V_110 ;
} * V_111 ;
V_11 = F_37 ( V_109 ) ;
if ( ! V_11 || V_11 -> V_12 )
return 0 ;
V_111 = F_63 ( V_22 , sizeof( * V_111 ) , V_109 -> V_43 ) ;
if ( V_111 == NULL ) {
F_15 ( L_15 ) ;
return - V_32 ;
}
V_111 -> V_71 . V_43 = V_112 ;
V_111 -> V_71 . V_113 = sizeof( V_111 -> V_110 ) ;
V_111 -> V_110 . V_114 = V_109 -> V_43 ;
V_111 -> V_110 . V_115 = V_11 -> V_81 . V_116 . V_117 ;
F_64 ( V_22 , sizeof( * V_111 ) ) ;
F_3 ( V_109 , V_11 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 ;
F_4 (val, &sw_context->resource_list, head) {
if ( F_5 ( ! V_7 -> V_17 ) )
break;
V_24 = F_66
( F_7 ( V_7 -> V_14 ) ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( V_24 != - V_91 )
F_15 ( L_16 ) ;
return V_24 ;
}
V_24 = F_62 ( V_7 -> V_14 ) ;
if ( V_24 != 0 )
return V_24 ;
}
return 0 ;
}
static int F_67 ( struct V_3 * V_4 ,
enum V_41 V_42 ,
enum V_118 V_119 ,
T_6 V_120 ,
T_6 V_121 [] , T_2 V_122 ,
T_2 V_123 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_124 * V_47 ;
T_2 V_52 ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_47 = V_4 -> V_47 ;
for ( V_52 = 0 ; V_52 < V_122 ; ++ V_52 ) {
struct V_125 V_126 ;
struct V_13 * V_40 = NULL ;
if ( V_121 [ V_52 ] != V_102 ) {
V_40 = F_31 ( V_47 , V_42 , V_121 [ V_52 ] ) ;
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
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_40 ;
V_126 . V_127 . V_128 = V_119 ;
V_126 . V_120 = V_120 ;
V_126 . V_129 = V_123 + V_52 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
V_120 , V_126 . V_129 ) ;
if ( V_40 )
F_32 ( & V_40 ) ;
}
return 0 ;
}
static int F_69 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_130 {
T_4 V_71 ;
T_3 V_114 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_130 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_114 , NULL ) ;
}
static int F_70 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_132 {
T_4 V_71 ;
T_7 V_110 ;
} * V_111 ;
struct V_6 * V_44 ;
struct V_6 * V_133 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_132 , V_71 ) ;
if ( V_111 -> V_110 . type >= V_134 ) {
F_15 ( L_20 ,
( unsigned ) V_111 -> V_110 . type ) ;
return - V_46 ;
}
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_110 . V_114 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_137 . V_138 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 ) {
struct V_125 V_126 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_133 ? V_133 -> V_14 : NULL ;
V_126 . V_127 . V_128 = V_139 ;
V_126 . V_129 = V_111 -> V_110 . type ;
F_68 ( V_44 -> V_17 ,
& V_126 . V_127 , 0 , V_126 . V_129 ) ;
}
return 0 ;
}
static int F_71 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_132 {
T_4 V_71 ;
T_8 V_110 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_132 , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_140 . V_138 , NULL ) ;
if ( V_24 )
return V_24 ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_141 . V_138 , NULL ) ;
}
static int F_72 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_9 V_110 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_140 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_141 , NULL ) ;
}
static int F_74 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_10 V_110 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_142 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_143 , NULL ) ;
}
static int F_75 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_132 {
T_4 V_71 ;
T_11 V_110 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_132 , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_140 . V_138 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_141 . V_138 , NULL ) ;
}
static int F_76 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_132 {
T_4 V_71 ;
T_12 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_132 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_144 . V_138 , NULL ) ;
}
static int F_77 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_132 {
T_4 V_71 ;
T_13 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_132 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 , & V_111 -> V_110 . V_138 ,
NULL ) ;
}
static int F_78 ( struct V_21 * V_22 ,
struct V_57 * V_145 ,
struct V_3 * V_4 )
{
struct V_99 * V_146 =
& V_4 -> V_101 [ V_36 ] ;
int V_24 ;
F_61 ( ! V_146 -> V_103 ) ;
V_4 -> V_147 = V_146 -> V_14 ;
if ( F_5 ( V_145 != V_4 -> V_148 ) ) {
if ( F_5 ( V_145 -> V_81 . V_149 > 4 ) ) {
F_15 ( L_21 ) ;
return - V_46 ;
}
if ( F_5 ( V_4 -> V_148 != NULL ) ) {
V_4 -> V_150 = true ;
V_24 = F_38 ( V_4 ,
V_4 -> V_148 ,
V_22 -> V_34 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_4 -> V_148 = V_145 ;
V_24 = F_38 ( V_4 ,
V_22 -> V_151 ,
V_22 -> V_34 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static void F_79 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_150 ) {
struct V_99 * V_146 =
& V_4 -> V_101 [ V_36 ] ;
struct V_13 * V_48 ;
int V_24 ;
F_61 ( ! V_146 -> V_103 ) ;
V_48 = V_146 -> V_14 ;
V_24 = F_80 ( V_22 , V_48 -> V_43 ) ;
if ( F_5 ( V_24 != 0 ) )
F_15 ( L_22 ) ;
}
if ( V_22 -> V_152 != V_4 -> V_148 ) {
if ( V_22 -> V_152 ) {
F_81 ( V_22 -> V_152 , false ) ;
F_10 ( & V_22 -> V_152 ) ;
}
if ( ! V_4 -> V_150 ) {
F_81 ( V_4 -> V_148 , true ) ;
if ( ! V_22 -> V_153 ) {
F_81 ( V_22 -> V_151 ,
true ) ;
V_22 -> V_153 = true ;
}
F_61 ( V_4 -> V_147 == NULL ) ;
V_22 -> V_154 = V_4 -> V_147 -> V_43 ;
V_22 -> V_155 = true ;
V_22 -> V_152 =
F_82 ( V_4 -> V_148 ) ;
}
}
}
static int F_83 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_14 * V_43 ,
struct V_57 * * V_156 )
{
struct V_57 * V_157 = NULL ;
T_3 V_104 = * V_43 ;
struct V_158 * V_159 ;
int V_24 ;
V_24 = F_84 ( V_4 -> V_105 -> V_106 , V_104 , & V_157 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_23 ) ;
V_24 = - V_46 ;
goto V_107;
}
if ( F_5 ( V_4 -> V_160 >= V_161 ) ) {
F_15 ( L_24
L_25 ) ;
V_24 = - V_46 ;
goto V_107;
}
V_159 = & V_4 -> V_162 [ V_4 -> V_160 ++ ] ;
V_159 -> V_163 = V_43 ;
V_159 -> V_164 = NULL ;
V_24 = F_38 ( V_4 , V_157 , true , & V_159 -> V_165 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_107;
* V_156 = V_157 ;
return 0 ;
V_107:
F_10 ( & V_157 ) ;
* V_156 = NULL ;
return V_24 ;
}
static int F_85 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_15 * V_166 ,
struct V_57 * * V_156 )
{
struct V_57 * V_157 = NULL ;
T_3 V_104 = V_166 -> V_167 ;
struct V_158 * V_159 ;
int V_24 ;
V_24 = F_84 ( V_4 -> V_105 -> V_106 , V_104 , & V_157 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_26 ) ;
V_24 = - V_46 ;
goto V_107;
}
if ( F_5 ( V_4 -> V_160 >= V_161 ) ) {
F_15 ( L_24
L_25 ) ;
V_24 = - V_46 ;
goto V_107;
}
V_159 = & V_4 -> V_162 [ V_4 -> V_160 ++ ] ;
V_159 -> V_164 = V_166 ;
V_24 = F_38 ( V_4 , V_157 , false , & V_159 -> V_165 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_107;
* V_156 = V_157 ;
return 0 ;
V_107:
F_10 ( & V_157 ) ;
* V_156 = NULL ;
return V_24 ;
}
static int F_86 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_168 {
T_4 V_71 ;
T_16 V_169 ;
} * V_111 ;
int V_24 ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_170 ;
if ( V_44 == NULL ) {
F_15 ( L_27 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , struct V_168 , V_71 ) ;
if ( V_111 -> V_169 . type < V_171 ||
V_111 -> V_169 . type >= V_172 )
return - V_46 ;
V_170 = F_33 ( V_44 -> V_14 , V_173 ) ;
V_24 = F_87 ( V_170 , V_111 -> V_169 . V_174 ) ;
F_32 ( & V_170 ) ;
return V_24 ;
}
static int F_88 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_175 {
T_4 V_71 ;
T_17 V_169 ;
} * V_111 ;
struct V_57 * V_157 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_175 , V_71 ) ;
V_24 = F_83 ( V_22 , V_4 , & V_111 -> V_169 . V_115 ,
& V_157 ) ;
if ( V_24 != 0 )
return V_24 ;
V_4 -> V_11 = V_157 ;
V_4 -> V_12 = V_4 -> V_45 -> V_14 ;
F_10 ( & V_157 ) ;
return V_24 ;
}
static int F_89 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_176 {
T_4 V_71 ;
T_18 V_169 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_176 ,
V_71 ) ;
return F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_169 . V_114 ,
NULL ) ;
}
static int F_90 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_177 {
T_4 V_71 ;
T_19 V_169 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_177 ,
V_71 ) ;
if ( F_5 ( V_22 -> V_34 ) ) {
struct {
T_4 V_71 ;
T_18 V_169 ;
} V_178 ;
F_61 ( sizeof( V_178 ) != sizeof( * V_111 ) ) ;
V_178 . V_71 . V_43 = V_179 ;
V_178 . V_71 . V_113 = V_111 -> V_71 . V_113 ;
V_178 . V_169 . V_114 = V_111 -> V_169 . V_114 ;
V_178 . V_169 . type = V_111 -> V_169 . type ;
memcpy ( V_111 , & V_178 , sizeof( * V_111 ) ) ;
return F_89 ( V_22 , V_4 , V_71 ) ;
}
return F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_169 . V_114 ,
NULL ) ;
}
static int F_91 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_157 ;
struct V_180 {
T_4 V_71 ;
T_20 V_169 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_180 , V_71 ) ;
V_24 = F_69 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_83 ( V_22 , V_4 ,
& V_111 -> V_169 . V_115 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_78 ( V_22 , V_157 , V_4 ) ;
F_10 ( & V_157 ) ;
return V_24 ;
}
static int F_92 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_157 ;
struct V_180 {
T_4 V_71 ;
T_21 V_169 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_180 , V_71 ) ;
if ( V_22 -> V_34 ) {
struct {
T_4 V_71 ;
T_20 V_169 ;
} V_178 ;
F_61 ( sizeof( V_178 ) != sizeof( * V_111 ) ) ;
V_178 . V_71 . V_43 = V_181 ;
V_178 . V_71 . V_113 = V_111 -> V_71 . V_113 ;
V_178 . V_169 . V_114 = V_111 -> V_169 . V_114 ;
V_178 . V_169 . type = V_111 -> V_169 . type ;
V_178 . V_169 . V_115 = V_111 -> V_169 . V_182 . V_167 ;
V_178 . V_169 . V_58 = V_111 -> V_169 . V_182 . V_58 ;
memcpy ( V_111 , & V_178 , sizeof( * V_111 ) ) ;
return F_91 ( V_22 , V_4 , V_71 ) ;
}
V_24 = F_69 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_85 ( V_22 , V_4 ,
& V_111 -> V_169 . V_182 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_78 ( V_22 , V_157 , V_4 ) ;
F_10 ( & V_157 ) ;
return V_24 ;
}
static int F_93 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_157 ;
struct V_180 {
T_4 V_71 ;
T_22 V_169 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_180 , V_71 ) ;
V_24 = F_69 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_83 ( V_22 , V_4 ,
& V_111 -> V_169 . V_115 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_157 ) ;
return 0 ;
}
static int F_94 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_157 ;
struct V_180 {
T_4 V_71 ;
T_23 V_169 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_180 , V_71 ) ;
if ( V_22 -> V_34 ) {
struct {
T_4 V_71 ;
T_22 V_169 ;
} V_178 ;
F_61 ( sizeof( V_178 ) != sizeof( * V_111 ) ) ;
V_178 . V_71 . V_43 = V_183 ;
V_178 . V_71 . V_113 = V_111 -> V_71 . V_113 ;
V_178 . V_169 . V_114 = V_111 -> V_169 . V_114 ;
V_178 . V_169 . type = V_111 -> V_169 . type ;
V_178 . V_169 . V_115 = V_111 -> V_169 . V_182 . V_167 ;
V_178 . V_169 . V_58 = V_111 -> V_169 . V_182 . V_58 ;
memcpy ( V_111 , & V_178 , sizeof( * V_111 ) ) ;
return F_93 ( V_22 , V_4 , V_71 ) ;
}
V_24 = F_69 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_85 ( V_22 , V_4 ,
& V_111 -> V_169 . V_182 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_157 ) ;
return 0 ;
}
static int F_95 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_57 * V_157 = NULL ;
struct V_184 * V_185 = NULL ;
struct V_186 {
T_4 V_71 ;
T_24 V_187 ;
} * V_111 ;
int V_24 ;
T_25 * V_188 ;
T_3 V_189 ;
V_111 = F_20 ( V_71 , struct V_186 , V_71 ) ;
V_188 = ( T_25 * ) ( ( unsigned long ) & V_111 -> V_187 +
V_71 -> V_113 - sizeof( * V_188 ) ) ;
if ( F_5 ( V_188 -> V_190 != sizeof( * V_188 ) ) ) {
F_15 ( L_28 ) ;
return - V_46 ;
}
V_24 = F_85 ( V_22 , V_4 ,
& V_111 -> V_187 . V_191 . V_166 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_189 = V_157 -> V_81 . V_149 * V_192 ;
if ( F_5 ( V_111 -> V_187 . V_191 . V_166 . V_58 > V_189 ) ) {
F_15 ( L_29 ) ;
return - V_46 ;
}
V_189 -= V_111 -> V_187 . V_191 . V_166 . V_58 ;
if ( F_5 ( V_188 -> V_193 > V_189 ) )
V_188 -> V_193 = V_189 ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 , & V_111 -> V_187 . V_194 . V_138 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
if ( F_5 ( V_24 != - V_91 ) )
F_15 ( L_30 ) ;
goto V_195;
}
V_185 = F_96 ( V_4 -> V_101 [ V_135 ] . V_14 ) ;
F_97 ( V_185 , V_4 -> V_105 -> V_106 , & V_157 -> V_81 ,
V_71 ) ;
V_195:
F_10 ( & V_157 ) ;
return V_24 ;
}
static int F_98 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_196 {
T_4 V_71 ;
T_26 V_110 ;
} * V_111 ;
T_27 * V_197 = ( T_27 * ) (
( unsigned long ) V_71 + sizeof( * V_111 ) ) ;
T_28 * V_198 ;
T_3 V_52 ;
T_3 V_199 ;
int V_24 ;
V_24 = F_69 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_111 = F_20 ( V_71 , struct V_196 , V_71 ) ;
V_199 = ( V_71 -> V_113 - sizeof( V_111 -> V_110 ) ) / sizeof( * V_197 ) ;
if ( F_5 ( V_111 -> V_110 . V_200 > V_199 ) ) {
F_15 ( L_31 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_111 -> V_110 . V_200 ; ++ V_52 , ++ V_197 ) {
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_197 -> V_201 . V_202 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_199 = ( V_71 -> V_113 - sizeof( V_111 -> V_110 ) -
V_111 -> V_110 . V_200 * sizeof( * V_197 ) ) / sizeof( * V_198 ) ;
if ( F_5 ( V_111 -> V_110 . V_203 > V_199 ) ) {
F_15 ( L_32 ) ;
return - V_46 ;
}
V_198 = ( T_28 * ) V_197 ;
for ( V_52 = 0 ; V_52 < V_111 -> V_110 . V_203 ; ++ V_52 , ++ V_198 ) {
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_198 -> V_204 . V_202 , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static int F_99 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_205 {
T_4 V_71 ;
T_29 V_206 ;
} * V_111 ;
T_30 * V_207 = ( T_30 * )
( ( unsigned long ) V_71 + V_71 -> V_113 + sizeof( V_71 ) ) ;
T_30 * V_208 = ( T_30 * )
( ( unsigned long ) V_71 + sizeof( struct V_205 ) ) ;
struct V_6 * V_44 ;
struct V_6 * V_133 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_205 ,
V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_206 . V_114 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
for (; V_208 < V_207 ; ++ V_208 ) {
if ( F_18 ( V_208 -> V_209 != V_210 ) )
continue;
if ( V_208 -> V_211 >= V_212 ) {
F_15 ( L_33 ,
( unsigned ) V_208 -> V_211 ) ;
return - V_46 ;
}
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_208 -> V_213 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 ) {
struct V_214 V_126 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_133 ? V_133 -> V_14 : NULL ;
V_126 . V_127 . V_128 = V_215 ;
V_126 . V_216 = V_208 -> V_211 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
0 , V_126 . V_216 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_217 )
{
struct V_57 * V_157 ;
int V_24 ;
struct {
T_3 V_71 ;
T_31 V_110 ;
} * V_111 = V_217 ;
V_24 = F_85 ( V_22 , V_4 ,
& V_111 -> V_110 . V_166 ,
& V_157 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_10 ( & V_157 ) ;
return V_24 ;
}
static int F_101 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
struct V_6 * V_76 ,
T_3 * V_218 ,
unsigned long V_219 )
{
struct V_57 * V_220 ;
int V_24 ;
V_24 = F_83 ( V_22 , V_4 , V_218 , & V_220 ) ;
if ( V_24 )
return V_24 ;
V_76 -> V_16 = true ;
if ( V_76 -> V_30 )
V_76 -> V_88 = true ;
F_10 ( & V_76 -> V_19 ) ;
V_76 -> V_19 = V_220 ;
V_76 -> V_20 = V_219 ;
return 0 ;
}
static int F_102 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
enum F_26 V_96 ,
const struct V_97
* V_98 ,
T_3 * V_221 ,
T_3 * V_218 ,
unsigned long V_219 )
{
struct V_6 * V_76 ;
int V_24 ;
V_24 = F_58 ( V_22 , V_4 , V_96 ,
V_98 , V_221 , & V_76 ) ;
if ( V_24 )
return V_24 ;
return F_101 ( V_22 , V_4 , V_76 ,
V_218 , V_219 ) ;
}
static int F_103 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_222 {
T_4 V_71 ;
T_32 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_222 , V_71 ) ;
return F_102 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , & V_111 -> V_110 . V_115 ,
0 ) ;
}
static int F_104 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_33 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_224 . V_138 , NULL ) ;
}
static int F_105 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_34 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , NULL ) ;
}
static int F_106 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_35 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_224 . V_138 , NULL ) ;
}
static int F_107 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_36 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , NULL ) ;
}
static int F_108 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_37 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_224 . V_138 , NULL ) ;
}
static int F_109 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_223 {
T_4 V_71 ;
T_38 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_223 , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , NULL ) ;
}
static int F_110 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_225 {
T_4 V_71 ;
T_39 V_110 ;
} * V_111 ;
int V_24 ;
T_1 V_113 ;
struct V_6 * V_7 ;
V_111 = F_20 ( V_71 , struct V_225 ,
V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_110 . V_114 ,
& V_7 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( F_5 ( ! V_22 -> V_34 ) )
return 0 ;
V_113 = V_111 -> V_71 . V_113 - sizeof( V_111 -> V_110 ) ;
V_24 = F_111 ( V_22 ,
F_112 ( V_7 -> V_14 ) ,
V_111 -> V_110 . V_226 , V_111 + 1 ,
V_111 -> V_110 . type , V_113 ,
& V_4 -> V_227 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_40 ( & V_4 -> V_94 ,
NULL ,
F_1 ( V_4 -> V_95 ,
& V_111 -> V_71 . V_43 ) ,
V_69 ) ;
}
static int F_113 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_228 {
T_4 V_71 ;
T_40 V_110 ;
} * V_111 ;
int V_24 ;
struct V_6 * V_7 ;
V_111 = F_20 ( V_71 , struct V_228 ,
V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_110 . V_114 ,
& V_7 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( F_5 ( ! V_22 -> V_34 ) )
return 0 ;
V_24 = F_114 ( F_112 ( V_7 -> V_14 ) ,
V_111 -> V_110 . V_226 ,
V_111 -> V_110 . type ,
& V_4 -> V_227 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_40 ( & V_4 -> V_94 ,
NULL ,
F_1 ( V_4 -> V_95 ,
& V_111 -> V_71 . V_43 ) ,
V_69 ) ;
}
static int F_115 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_229 {
T_4 V_71 ;
T_41 V_110 ;
} * V_111 ;
struct V_6 * V_44 , * V_133 = NULL ;
struct V_230 V_126 ;
struct V_13 * V_14 = NULL ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_229 ,
V_71 ) ;
if ( V_111 -> V_110 . type >= V_231 ) {
F_15 ( L_34 ,
( unsigned ) V_111 -> V_110 . type ) ;
return - V_46 ;
}
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_110 . V_114 ,
& V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( ! V_22 -> V_34 )
return 0 ;
if ( V_111 -> V_110 . V_226 != V_102 ) {
V_14 = F_116 ( F_112 ( V_44 -> V_14 ) ,
V_111 -> V_110 . V_226 ,
V_111 -> V_110 . type ) ;
if ( ! F_14 ( V_14 ) ) {
V_24 = F_57 ( V_22 , V_4 ,
& V_111 -> V_110 . V_226 , V_14 ,
& V_133 ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
}
if ( ! V_133 ) {
V_24 = F_58 ( V_22 , V_4 ,
V_232 ,
V_233 ,
& V_111 -> V_110 . V_226 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_133 ? V_133 -> V_14 : NULL ;
V_126 . V_127 . V_128 = V_234 ;
V_126 . V_120 = V_111 -> V_110 . type - V_235 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
V_126 . V_120 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_236 {
T_4 V_71 ;
T_42 V_110 ;
} * V_111 ;
int V_24 ;
V_111 = F_20 ( V_71 , struct V_236 ,
V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 , & V_111 -> V_110 . V_114 ,
NULL ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
if ( V_22 -> V_34 )
V_71 -> V_43 = V_237 ;
return 0 ;
}
static int F_118 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_238 {
T_4 V_71 ;
T_43 V_110 ;
} * V_111 ;
V_111 = F_20 ( V_71 , struct V_238 ,
V_71 ) ;
return F_102 ( V_22 , V_4 , V_232 ,
V_233 ,
& V_111 -> V_110 . V_226 , & V_111 -> V_110 . V_115 ,
V_111 -> V_110 . V_239 ) ;
}
static int
F_119 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_44 V_110 ;
} * V_111 ;
struct V_6 * V_133 = NULL ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_240 V_126 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_133 ? V_133 -> V_14 : NULL ;
V_126 . V_127 . V_128 = V_241 ;
V_126 . V_120 = V_111 -> V_110 . type - V_235 ;
V_126 . V_58 = V_111 -> V_110 . V_239 ;
V_126 . V_113 = V_111 -> V_110 . V_242 ;
V_126 . V_129 = V_111 -> V_110 . V_129 ;
if ( V_126 . V_120 >= V_243 ||
V_126 . V_129 >= V_244 ) {
F_15 ( L_35 ,
( unsigned ) V_111 -> V_110 . type ,
( unsigned ) V_126 . V_129 ) ;
return - V_46 ;
}
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
V_126 . V_120 , V_126 . V_129 ) ;
return 0 ;
}
static int F_120 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_45 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
T_2 V_245 = ( V_111 -> V_71 . V_113 - sizeof( V_111 -> V_110 ) ) /
sizeof( V_246 ) ;
if ( ( V_247 ) V_111 -> V_110 . V_248 + ( V_247 ) V_245 >
( V_247 ) V_249 ||
V_111 -> V_110 . type >= V_250 ) {
F_15 ( L_36 ) ;
return - V_46 ;
}
return F_67 ( V_4 , V_251 ,
V_252 ,
V_111 -> V_110 . type - V_235 ,
( void * ) & V_111 [ 1 ] , V_245 ,
V_111 -> V_110 . V_248 ) ;
}
static int F_121 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_46 V_110 ;
} * V_111 ;
struct V_13 * V_14 = NULL ;
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_230 V_126 ;
int V_24 = 0 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
if ( V_111 -> V_110 . type >= V_250 ) {
F_15 ( L_34 ,
( unsigned ) V_111 -> V_110 . type ) ;
return - V_46 ;
}
if ( V_111 -> V_110 . V_253 != V_102 ) {
V_14 = F_116 ( V_4 -> V_47 , V_111 -> V_110 . V_253 , 0 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( L_37 ) ;
return F_16 ( V_14 ) ;
}
V_24 = F_17 ( V_4 , V_14 , NULL ) ;
if ( V_24 )
goto V_254;
}
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = V_14 ;
V_126 . V_127 . V_128 = V_255 ;
V_126 . V_120 = V_111 -> V_110 . type - V_235 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
V_126 . V_120 , 0 ) ;
V_254:
if ( V_14 )
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_122 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_256 V_126 ;
struct V_6 * V_133 ;
struct {
T_4 V_71 ;
T_47 V_110 ;
T_48 V_217 [] ;
} * V_111 ;
int V_52 , V_24 , V_257 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_257 = ( V_111 -> V_71 . V_113 - sizeof( V_111 -> V_110 ) ) /
sizeof( T_48 ) ;
if ( ( V_247 ) V_257 + ( V_247 ) V_111 -> V_110 . V_258 >
( V_247 ) V_259 ) {
F_15 ( L_38 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_257 ; V_52 ++ ) {
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_217 [ V_52 ] . V_138 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_128 = V_260 ;
V_126 . V_127 . V_14 = ( ( V_133 ) ? V_133 -> V_14 : NULL ) ;
V_126 . V_58 = V_111 -> V_217 [ V_52 ] . V_58 ;
V_126 . V_261 = V_111 -> V_217 [ V_52 ] . V_261 ;
V_126 . V_129 = V_52 + V_111 -> V_110 . V_258 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
0 , V_126 . V_129 ) ;
}
return 0 ;
}
static int F_123 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_262 V_126 ;
struct V_6 * V_133 ;
struct {
T_4 V_71 ;
T_49 V_110 ;
} * V_111 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_138 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = ( ( V_133 ) ? V_133 -> V_14 : NULL ) ;
V_126 . V_127 . V_128 = V_263 ;
V_126 . V_58 = V_111 -> V_110 . V_58 ;
V_126 . V_264 = V_111 -> V_110 . V_264 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 , 0 , 0 ) ;
return 0 ;
}
static int F_124 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_50 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
int V_24 ;
T_2 V_265 = ( V_111 -> V_71 . V_113 - sizeof( V_111 -> V_110 ) ) /
sizeof( V_266 ) ;
if ( V_265 > V_267 ) {
F_15 ( L_39 ) ;
return - V_46 ;
}
V_24 = F_67 ( V_4 , V_268 ,
V_269 , 0 ,
& V_111 -> V_110 . V_270 , 1 , 0 ) ;
if ( V_24 )
return V_24 ;
return F_67 ( V_4 , V_271 ,
V_272 , 0 ,
( void * ) & V_111 [ 1 ] , V_265 , 0 ) ;
}
static int F_125 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_51 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
return F_30 ( V_4 , V_271 ,
V_111 -> V_110 . V_273 ) ;
}
static int F_126 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_52 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
return F_30 ( V_4 , V_268 ,
V_111 -> V_110 . V_270 ) ;
}
static int F_127 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_6 * V_274 ;
struct V_13 * V_14 ;
enum V_41 V_42 ;
int V_24 ;
struct {
T_4 V_71 ;
T_6 V_275 ;
T_6 V_138 ;
} * V_111 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_42 = F_128 ( V_71 -> V_43 ) ;
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_138 , & V_274 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_14 = F_33 ( V_44 -> V_14 , V_276 [ V_42 ] ) ;
V_24 = F_87 ( V_14 , V_111 -> V_275 ) ;
F_32 ( & V_14 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
return F_129 ( V_4 -> V_47 ,
V_44 -> V_14 ,
V_274 -> V_14 ,
V_42 ,
V_111 -> V_275 ,
V_71 ,
V_71 -> V_113 + sizeof( * V_71 ) ,
& V_4 -> V_227 ) ;
}
static int F_130 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_277 V_126 ;
struct V_6 * V_133 ;
struct {
T_4 V_71 ;
T_53 V_110 ;
T_54 V_278 [] ;
} * V_111 ;
int V_52 , V_24 , V_257 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_257 = ( V_111 -> V_71 . V_113 - sizeof( V_111 -> V_110 ) ) /
sizeof( T_54 ) ;
if ( V_257 > V_279 ) {
F_15 ( L_40 ) ;
return - V_46 ;
}
for ( V_52 = 0 ; V_52 < V_257 ; V_52 ++ ) {
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_278 [ V_52 ] . V_138 , & V_133 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_126 . V_127 . V_48 = V_44 -> V_14 ;
V_126 . V_127 . V_14 = ( ( V_133 ) ? V_133 -> V_14 : NULL ) ;
V_126 . V_127 . V_128 = V_280 ,
V_126 . V_58 = V_111 -> V_278 [ V_52 ] . V_58 ;
V_126 . V_113 = V_111 -> V_278 [ V_52 ] . V_242 ;
V_126 . V_129 = V_52 ;
F_68 ( V_44 -> V_17 , & V_126 . V_127 ,
0 , V_126 . V_129 ) ;
}
return 0 ;
}
static int F_131 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_6 V_275 ;
} * V_111 ;
enum V_281 V_282 ;
int V_24 ;
if ( F_5 ( V_44 == NULL ) ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_282 = F_132 ( V_71 -> V_43 ) ;
V_14 = F_33 ( V_44 -> V_14 , V_283 [ V_282 ] ) ;
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
V_24 = F_87 ( V_14 , V_111 -> V_275 ) ;
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_133 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
union {
T_55 V_284 ;
T_56 V_285 ;
T_57 V_286 ;
T_58 V_138 ;
};
} * V_111 ;
F_46 ( F_134 ( F_73 ( * V_111 ) , V_284 . V_138 ) !=
F_134 ( F_73 ( * V_111 ) , V_138 ) ) ;
F_46 ( F_134 ( F_73 ( * V_111 ) , V_285 . V_138 ) !=
F_134 ( F_73 ( * V_111 ) , V_138 ) ) ;
F_46 ( F_134 ( F_73 ( * V_111 ) , V_286 . V_138 ) !=
F_134 ( F_73 ( * V_111 ) , V_138 ) ) ;
V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_138 , NULL ) ;
}
static int F_135 ( struct V_21 * V_22 ,
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
static int F_136 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct {
T_4 V_71 ;
union V_287 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
enum V_41 V_42 = F_128 ( V_71 -> V_43 ) ;
struct V_13 * V_40 ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_24 = F_137 ( V_4 -> V_47 ,
V_111 -> V_110 . V_288 , V_42 ,
& V_4 -> V_227 ,
& V_40 ) ;
if ( V_24 || ! V_40 )
return V_24 ;
return F_40 ( & V_4 -> V_94 ,
V_40 ,
F_1 ( V_4 -> V_95 ,
& V_111 -> V_71 . V_43 ) ,
V_289 ) ;
}
static int F_138 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_59 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_14 = F_33 ( V_44 -> V_14 , V_290 ) ;
V_24 = F_87 ( V_14 , V_111 -> V_110 . V_253 ) ;
F_32 ( & V_14 ) ;
if ( V_24 )
return V_24 ;
return F_139 ( V_4 -> V_47 , V_44 -> V_14 ,
V_111 -> V_110 . V_253 , V_111 -> V_110 . type ,
& V_4 -> V_227 ) ;
}
static int F_140 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 = V_4 -> V_45 ;
struct {
T_4 V_71 ;
T_60 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
int V_24 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
V_24 = F_114 ( V_4 -> V_47 , V_111 -> V_110 . V_253 , 0 ,
& V_4 -> V_227 ) ;
if ( V_24 )
F_15 ( L_41 ) ;
return V_24 ;
}
static int F_141 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct V_6 * V_44 ;
struct V_6 * V_133 ;
struct V_13 * V_14 ;
struct {
T_4 V_71 ;
T_61 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
int V_24 ;
if ( V_111 -> V_110 . V_114 != V_102 ) {
V_24 = F_58 ( V_22 , V_4 , V_36 ,
V_131 ,
& V_111 -> V_110 . V_114 , & V_44 ) ;
if ( V_24 )
return V_24 ;
} else {
V_44 = V_4 -> V_45 ;
if ( ! V_44 ) {
F_15 ( L_6 ) ;
return - V_46 ;
}
}
V_14 = F_116 ( F_112 ( V_44 -> V_14 ) ,
V_111 -> V_110 . V_226 , 0 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( L_42 ) ;
return F_16 ( V_14 ) ;
}
V_24 = F_17 ( V_4 , V_14 , & V_133 ) ;
if ( V_24 ) {
F_15 ( L_43 ) ;
goto V_254;
}
V_24 = F_101 ( V_22 , V_4 , V_133 ,
& V_111 -> V_110 . V_115 ,
V_111 -> V_110 . V_239 ) ;
V_254:
F_32 ( & V_14 ) ;
return V_24 ;
}
static int F_142 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_62 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
return F_30 ( V_4 , V_251 ,
V_111 -> V_110 . V_291 ) ;
}
static int F_143 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_4 * V_71 )
{
struct {
T_4 V_71 ;
T_63 V_110 ;
} * V_111 = F_20 ( V_71 , F_73 ( * V_111 ) , V_71 ) ;
int V_24 ;
V_24 = F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_142 , NULL ) ;
if ( V_24 != 0 )
return V_24 ;
return F_58 ( V_22 , V_4 , V_135 ,
V_136 ,
& V_111 -> V_110 . V_292 , NULL ) ;
}
static int F_144 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_217 , T_3 * V_113 )
{
T_3 V_293 = * V_113 ;
T_3 V_294 ;
V_294 = ( ( T_3 * ) V_217 ) [ 0 ] ;
switch ( V_294 ) {
case V_295 :
* V_113 = sizeof( T_3 ) + sizeof( V_296 ) ;
break;
case V_297 :
* V_113 = sizeof( T_3 ) + sizeof( T_31 ) ;
break;
case V_298 :
* V_113 = sizeof( T_3 ) + sizeof( V_299 ) ;
break;
case V_300 :
* V_113 = sizeof( T_3 ) + sizeof( V_299 ) ;
break;
default:
F_15 ( L_44 , V_294 ) ;
return - V_46 ;
}
if ( * V_113 > V_293 ) {
F_15 ( L_45
L_46 , V_294 ) ;
return - V_46 ;
}
if ( F_5 ( ! V_4 -> V_301 ) ) {
F_15 ( L_47 , V_294 ) ;
return - V_302 ;
}
if ( V_294 == V_297 )
return F_100 ( V_22 , V_4 , V_217 ) ;
return 0 ;
}
static int F_145 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_217 , T_3 * V_113 )
{
T_3 V_294 ;
T_3 V_293 = * V_113 ;
T_4 * V_71 = ( T_4 * ) V_217 ;
int V_24 ;
const struct V_303 * V_51 ;
bool V_304 = V_22 -> V_305 & V_306 ;
V_294 = ( ( T_3 * ) V_217 ) [ 0 ] ;
if ( F_5 ( V_294 < V_307 ) )
return F_144 ( V_22 , V_4 , V_217 , V_113 ) ;
V_294 = V_71 -> V_43 ;
* V_113 = V_71 -> V_113 + sizeof( T_4 ) ;
V_294 -= V_308 ;
if ( F_5 ( * V_113 > V_293 ) )
goto V_309;
if ( F_5 ( V_294 >= V_310 - V_308 ) )
goto V_309;
V_51 = & V_311 [ V_294 ] ;
if ( F_5 ( ! V_51 -> V_312 ) )
goto V_309;
if ( F_5 ( ! V_51 -> V_313 && ! V_4 -> V_301 ) )
goto V_314;
if ( F_5 ( V_51 -> V_315 && V_304 ) )
goto V_316;
if ( F_5 ( V_51 -> V_317 && ! V_304 ) )
goto V_318;
V_24 = V_51 -> V_312 ( V_22 , V_4 , V_71 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_309;
return 0 ;
V_309:
F_15 ( L_48 ,
V_294 + V_308 ) ;
return - V_46 ;
V_314:
F_15 ( L_49 ,
V_294 + V_308 ) ;
return - V_302 ;
V_316:
F_15 ( L_50 ,
V_294 + V_308 ) ;
return - V_46 ;
V_318:
F_15 ( L_51 ,
V_294 + V_308 ) ;
return - V_46 ;
}
static int F_146 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
void * V_217 ,
T_3 V_113 )
{
T_64 V_319 = V_113 ;
int V_24 ;
V_4 -> V_95 = V_217 ;
while ( V_319 > 0 ) {
V_113 = V_319 ;
V_24 = F_145 ( V_22 , V_4 , V_217 , & V_113 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_217 = ( void * ) ( ( unsigned long ) V_217 + V_113 ) ;
V_319 -= V_113 ;
}
if ( F_5 ( V_319 != 0 ) ) {
F_15 ( L_52 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_147 ( struct V_3 * V_4 )
{
V_4 -> V_160 = 0 ;
}
static void F_148 ( struct V_3 * V_4 )
{
T_3 V_52 ;
struct V_158 * V_159 ;
struct V_79 * V_320 ;
struct V_321 * V_85 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_160 ; ++ V_52 ) {
V_159 = & V_4 -> V_162 [ V_52 ] ;
V_320 = & V_4 -> V_82 [ V_159 -> V_165 ] . V_81 ;
V_85 = V_320 -> V_85 ;
switch ( V_85 -> V_116 . V_322 ) {
case V_323 :
V_159 -> V_164 -> V_58 += V_85 -> V_58 ;
V_159 -> V_164 -> V_167 = V_324 ;
break;
case V_325 :
V_159 -> V_164 -> V_167 = V_85 -> V_116 . V_117 ;
break;
case V_326 :
* V_159 -> V_163 = V_85 -> V_116 . V_117 ;
break;
default:
F_149 () ;
}
}
F_147 ( V_4 ) ;
}
static void F_150 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 , * V_327 ;
F_43 (val, val_next, list, head) {
F_151 ( & V_7 -> V_35 ) ;
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
static void F_152 ( struct V_3 * V_4 )
{
struct V_77 * V_51 , * V_328 ;
struct V_6 * V_7 ;
F_43 (entry, next, &sw_context->validate_nodes,
base.head) {
F_44 ( & V_51 -> V_81 . V_35 ) ;
F_153 ( & V_51 -> V_81 . V_85 ) ;
( void ) F_154 ( & V_4 -> V_29 , & V_51 -> V_28 ) ;
V_4 -> V_83 -- ;
}
F_61 ( V_4 -> V_83 != 0 ) ;
F_4 (val, &sw_context->resource_list, head)
( void ) F_154 ( & V_4 -> V_29 , & V_7 -> V_28 ) ;
}
int F_155 ( struct V_21 * V_22 ,
struct V_321 * V_85 ,
bool V_329 ,
bool V_74 )
{
struct V_57 * V_73 = F_20 ( V_85 , struct V_57 ,
V_81 ) ;
int V_24 ;
if ( V_73 -> V_330 > 0 )
return 0 ;
if ( V_74 )
return F_156 ( V_85 , & V_331 , V_329 ,
false ) ;
V_24 = F_156 ( V_85 , & V_332 , V_329 ,
false ) ;
if ( F_18 ( V_24 == 0 || V_24 == - V_91 ) )
return V_24 ;
V_24 = F_156 ( V_85 , & V_333 , V_329 , false ) ;
return V_24 ;
}
static int F_157 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
struct V_77 * V_51 ;
int V_24 ;
F_4 (entry, &sw_context->validate_nodes, base.head) {
V_24 = F_155 ( V_22 , V_51 -> V_81 . V_85 ,
true ,
V_51 -> V_74 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
}
return 0 ;
}
static int F_158 ( struct V_3 * V_4 ,
T_3 V_113 )
{
if ( F_18 ( V_4 -> V_334 >= V_113 ) )
return 0 ;
if ( V_4 -> V_334 == 0 )
V_4 -> V_334 = V_335 ;
while ( V_4 -> V_334 < V_113 ) {
V_4 -> V_334 =
F_159 ( V_4 -> V_334 +
( V_4 -> V_334 >> 1 ) ) ;
}
F_160 ( V_4 -> V_336 ) ;
V_4 -> V_336 = F_161 ( V_4 -> V_334 ) ;
if ( V_4 -> V_336 == NULL ) {
F_15 ( L_53 ) ;
V_4 -> V_334 = 0 ;
return - V_32 ;
}
return 0 ;
}
int F_162 ( struct V_337 * V_338 ,
struct V_21 * V_22 ,
struct V_339 * * V_340 ,
T_3 * V_341 )
{
T_3 V_342 ;
int V_24 ;
bool V_343 = false ;
F_61 ( V_341 != NULL && V_338 == NULL ) ;
V_24 = F_163 ( V_22 , & V_342 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_54 ) ;
V_343 = true ;
}
if ( V_341 != NULL )
V_24 = F_164 ( V_338 , V_22 -> V_344 ,
V_342 , V_340 , V_341 ) ;
else
V_24 = F_165 ( V_22 -> V_344 , V_342 , V_340 ) ;
if ( F_5 ( V_24 != 0 && ! V_343 ) ) {
( void ) F_166 ( V_22 , false , false ,
V_342 , false ,
V_345 ) ;
* V_340 = NULL ;
}
return 0 ;
}
void
F_167 ( struct V_21 * V_22 ,
struct V_346 * V_347 ,
int V_24 ,
struct V_348 T_65 * V_349 ,
struct V_339 * V_350 ,
T_3 V_351 )
{
struct V_348 V_352 ;
if ( V_349 == NULL )
return;
memset ( & V_352 , 0 , sizeof( V_352 ) ) ;
V_352 . error = V_24 ;
if ( V_24 == 0 ) {
F_61 ( V_350 == NULL ) ;
V_352 . V_104 = V_351 ;
V_352 . V_353 = V_350 -> V_81 . V_353 ;
F_168 ( V_22 , & V_22 -> V_354 ) ;
V_352 . V_355 = V_22 -> V_356 ;
}
V_24 = F_169 ( V_349 , & V_352 ,
sizeof( V_352 ) ) ;
if ( F_5 ( V_24 != 0 ) && ( V_352 . error == 0 ) ) {
F_170 ( V_347 -> V_106 ,
V_351 , V_357 ) ;
F_15 ( L_55 ) ;
( void ) F_171 ( V_350 , false , false ,
V_345 ) ;
}
}
static int F_172 ( struct V_21 * V_22 ,
void * V_358 ,
T_2 V_359 ,
struct V_3 * V_4 )
{
void * V_111 ;
if ( V_4 -> V_45 )
V_111 = F_63 ( V_22 , V_359 ,
V_4 -> V_45 -> V_14 -> V_43 ) ;
else
V_111 = F_173 ( V_22 , V_359 ) ;
if ( ! V_111 ) {
F_15 ( L_56 ) ;
return - V_32 ;
}
F_148 ( V_4 ) ;
memcpy ( V_111 , V_358 , V_359 ) ;
F_45 ( V_111 , & V_4 -> V_94 ) ;
F_42 ( & V_4 -> V_94 ) ;
F_64 ( V_22 , V_359 ) ;
return 0 ;
}
static int F_174 ( struct V_21 * V_22 ,
struct V_360 * V_71 ,
T_2 V_359 ,
struct V_3 * V_4 )
{
T_2 V_43 = ( ( V_4 -> V_45 ) ? V_4 -> V_45 -> V_14 -> V_43 :
V_102 ) ;
void * V_111 = F_175 ( V_22 -> V_361 , V_359 ,
V_43 , false , V_71 ) ;
F_148 ( V_4 ) ;
F_45 ( V_111 , & V_4 -> V_94 ) ;
F_42 ( & V_4 -> V_94 ) ;
F_176 ( V_22 -> V_361 , V_359 , V_71 , false ) ;
return 0 ;
}
static void * F_177 ( struct V_21 * V_22 ,
void T_65 * V_362 ,
void * V_358 ,
T_2 V_359 ,
struct V_360 * * V_71 )
{
T_1 V_363 ;
int V_24 ;
* V_71 = NULL ;
if ( V_359 > V_65 ) {
F_15 ( L_57 ) ;
return F_178 ( - V_46 ) ;
}
if ( ! V_22 -> V_361 || V_358 )
return V_358 ;
V_363 = V_359 + 512 ;
V_363 = F_179 ( T_1 , V_363 , V_65 ) ;
V_358 = F_180 ( V_22 -> V_361 , V_363 ,
true , V_71 ) ;
if ( F_14 ( V_358 ) )
return V_358 ;
V_24 = F_181 ( V_358 , V_362 ,
V_359 ) ;
if ( V_24 ) {
F_15 ( L_58 ) ;
F_182 ( * V_71 ) ;
* V_71 = NULL ;
return F_178 ( - V_364 ) ;
}
return V_358 ;
}
static int F_183 ( struct V_21 * V_22 ,
struct V_3 * V_4 ,
T_3 V_104 )
{
struct V_6 * V_44 ;
struct V_13 * V_14 ;
int V_24 ;
if ( V_104 == V_102 )
return 0 ;
V_24 = F_59 ( V_22 , V_4 -> V_105 -> V_106 ,
V_104 , V_131 ,
& V_14 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_15 ( L_59 ,
( unsigned ) V_104 ) ;
return V_24 ;
}
V_24 = F_17 ( V_4 , V_14 , & V_44 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_4 -> V_45 = V_44 ;
V_4 -> V_47 = F_112 ( V_14 ) ;
V_25:
F_32 ( & V_14 ) ;
return V_24 ;
}
int F_184 ( struct V_337 * V_338 ,
struct V_21 * V_22 ,
void T_65 * V_362 ,
void * V_358 ,
T_3 V_359 ,
T_66 V_365 ,
T_3 V_366 ,
struct V_348 T_65 * V_349 ,
struct V_339 * * V_367 )
{
struct V_3 * V_4 = & V_22 -> V_48 ;
struct V_339 * V_350 = NULL ;
struct V_13 * V_108 ;
struct V_8 V_10 ;
struct V_360 * V_71 ;
struct V_368 V_369 ;
T_3 V_104 ;
int V_24 ;
if ( V_365 ) {
V_24 = F_185 ( V_22 , & V_22 -> V_354 . V_370 ,
V_365 ) ;
if ( V_24 )
return V_24 ;
}
V_358 = F_177 ( V_22 , V_362 ,
V_358 , V_359 ,
& V_71 ) ;
if ( F_14 ( V_358 ) )
return F_16 ( V_358 ) ;
V_24 = F_186 ( & V_22 -> V_371 ) ;
if ( V_24 ) {
V_24 = - V_91 ;
goto V_372;
}
V_4 -> V_301 = false ;
if ( V_358 == NULL ) {
V_24 = F_158 ( V_4 , V_359 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_373;
V_24 = F_181 ( V_4 -> V_336 ,
V_362 , V_359 ) ;
if ( F_5 ( V_24 != 0 ) ) {
V_24 = - V_364 ;
F_15 ( L_58 ) ;
goto V_373;
}
V_358 = V_4 -> V_336 ;
} else if ( ! V_71 )
V_4 -> V_301 = true ;
V_4 -> V_105 = V_346 ( V_338 ) ;
V_4 -> V_160 = 0 ;
V_4 -> V_83 = 0 ;
F_187 ( & V_4 -> V_10 ) ;
F_187 ( & V_4 -> V_38 ) ;
V_4 -> V_148 = V_22 -> V_152 ;
V_4 -> V_147 = NULL ;
V_4 -> V_150 = false ;
V_4 -> V_45 = NULL ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = NULL ;
memset ( V_4 -> V_101 , 0 , sizeof( V_4 -> V_101 ) ) ;
F_187 ( & V_4 -> V_87 ) ;
F_187 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_17 )
F_188 ( V_4 -> V_17 ) ;
if ( ! V_4 -> V_374 ) {
V_24 = F_189 ( & V_4 -> V_29 , V_375 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_373;
V_4 -> V_374 = true ;
}
F_187 ( & V_4 -> V_227 ) ;
F_187 ( & V_10 ) ;
V_24 = F_183 ( V_22 , V_4 , V_366 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_190 ( & V_4 -> V_38 ,
& V_4 -> V_10 ) ;
goto V_376;
}
V_24 = F_146 ( V_22 , V_4 , V_358 ,
V_359 ) ;
F_190 ( & V_4 -> V_38 ,
& V_4 -> V_10 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_376;
V_24 = F_51 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_376;
V_24 = F_191 ( & V_369 , & V_4 -> V_87 ,
true , NULL ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_376;
V_24 = F_157 ( V_22 , V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_24 = F_54 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_25;
V_24 = F_186 ( & V_22 -> V_55 ) ;
if ( F_5 ( V_24 != 0 ) ) {
V_24 = - V_91 ;
goto V_25;
}
if ( V_22 -> V_34 ) {
V_24 = F_65 ( V_4 ) ;
if ( F_5 ( V_24 != 0 ) )
goto V_377;
}
if ( ! V_71 ) {
V_24 = F_172 ( V_22 , V_358 ,
V_359 , V_4 ) ;
} else {
V_24 = F_174 ( V_22 , V_71 , V_359 ,
V_4 ) ;
V_71 = NULL ;
}
F_39 ( & V_22 -> V_55 ) ;
if ( V_24 )
goto V_25;
F_79 ( V_22 , V_4 ) ;
V_24 = F_162 ( V_338 , V_22 ,
& V_350 ,
( V_349 ) ? & V_104 : NULL ) ;
if ( V_24 != 0 )
F_15 ( L_54 ) ;
F_2 ( V_4 , false ) ;
F_192 ( & V_369 , & V_4 -> V_87 ,
( void * ) V_350 ) ;
if ( F_5 ( V_22 -> V_152 != NULL &&
! V_22 -> V_155 ) )
F_193 ( V_22 , V_350 ) ;
F_152 ( V_4 ) ;
F_167 ( V_22 , V_346 ( V_338 ) , V_24 ,
V_349 , V_350 , V_104 ) ;
if ( F_5 ( V_367 != NULL ) ) {
* V_367 = V_350 ;
V_350 = NULL ;
} else if ( F_18 ( V_350 != NULL ) ) {
F_194 ( & V_350 ) ;
}
F_190 ( & V_4 -> V_10 , & V_10 ) ;
F_195 ( & V_4 -> V_227 ) ;
F_39 ( & V_22 -> V_371 ) ;
F_150 ( V_4 , & V_10 ) ;
return 0 ;
V_377:
F_39 ( & V_22 -> V_55 ) ;
V_25:
F_196 ( & V_369 , & V_4 -> V_87 ) ;
V_376:
F_2 ( V_4 , true ) ;
F_42 ( & V_4 -> V_94 ) ;
F_147 ( V_4 ) ;
F_152 ( V_4 ) ;
if ( F_5 ( V_22 -> V_152 != NULL &&
! V_22 -> V_155 ) )
F_193 ( V_22 , NULL ) ;
V_373:
F_190 ( & V_4 -> V_10 , & V_10 ) ;
V_108 = V_4 -> V_108 ;
V_4 -> V_108 = NULL ;
F_197 ( & V_4 -> V_227 ) ;
F_39 ( & V_22 -> V_371 ) ;
F_150 ( V_4 , & V_10 ) ;
if ( F_5 ( V_108 != NULL ) )
F_32 ( & V_108 ) ;
V_372:
if ( V_71 )
F_182 ( V_71 ) ;
return V_24 ;
}
static void F_198 ( struct V_21 * V_22 )
{
F_15 ( L_60 ) ;
( void ) F_166 ( V_22 , false , true , 0 , false , 10 * V_378 ) ;
F_81 ( V_22 -> V_152 , false ) ;
if ( V_22 -> V_153 ) {
F_81 ( V_22 -> V_151 , false ) ;
V_22 -> V_153 = false ;
}
}
void F_193 ( struct V_21 * V_22 ,
struct V_339 * V_350 )
{
int V_24 = 0 ;
struct V_8 V_379 ;
struct V_79 V_380 , V_381 ;
struct V_339 * V_382 = NULL ;
struct V_368 V_369 ;
if ( V_22 -> V_152 == NULL )
goto V_373;
F_187 ( & V_379 ) ;
V_380 . V_85 = F_50 ( & V_22 -> V_152 -> V_81 ) ;
V_380 . V_86 = false ;
F_25 ( & V_380 . V_35 , & V_379 ) ;
V_381 . V_85 = F_50 ( & V_22 -> V_151 -> V_81 ) ;
V_381 . V_86 = false ;
F_25 ( & V_381 . V_35 , & V_379 ) ;
V_24 = F_191 ( & V_369 , & V_379 ,
false , NULL ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_198 ( V_22 ) ;
goto V_383;
}
if ( V_22 -> V_155 ) {
F_61 ( V_350 != NULL ) ;
V_24 = F_80 ( V_22 , V_22 -> V_154 ) ;
if ( F_5 ( V_24 != 0 ) ) {
F_198 ( V_22 ) ;
goto V_384;
}
V_22 -> V_155 = false ;
}
F_81 ( V_22 -> V_152 , false ) ;
if ( V_22 -> V_153 ) {
F_81 ( V_22 -> V_151 , false ) ;
V_22 -> V_153 = false ;
}
if ( V_350 == NULL ) {
( void ) F_162 ( NULL , V_22 , & V_382 ,
NULL ) ;
V_350 = V_382 ;
}
F_192 ( & V_369 , & V_379 , ( void * ) V_350 ) ;
if ( V_382 != NULL )
F_194 ( & V_382 ) ;
F_153 ( & V_381 . V_85 ) ;
F_153 ( & V_380 . V_85 ) ;
F_10 ( & V_22 -> V_152 ) ;
V_373:
return;
V_384:
F_196 ( & V_369 , & V_379 ) ;
V_383:
F_153 ( & V_381 . V_85 ) ;
F_153 ( & V_380 . V_85 ) ;
F_10 ( & V_22 -> V_152 ) ;
}
void F_199 ( struct V_21 * V_22 )
{
F_34 ( & V_22 -> V_371 ) ;
if ( V_22 -> V_155 )
F_193 ( V_22 , NULL ) ;
F_39 ( & V_22 -> V_371 ) ;
}
int F_200 ( struct V_385 * V_386 , unsigned long V_387 ,
struct V_337 * V_338 , T_1 V_113 )
{
struct V_21 * V_22 = F_201 ( V_386 ) ;
struct V_388 V_389 ;
int V_24 ;
static const T_1 V_390 [] = {
F_134 ( struct V_388 , V_391 ) ,
sizeof(struct V_388 ) } ;
if ( F_5 ( V_113 < V_390 [ 0 ] ) ) {
F_15 ( L_61 ,
V_392 ) ;
return - V_46 ;
}
if ( F_181 ( & V_389 , ( void T_65 * ) V_387 , V_390 [ 0 ] ) != 0 )
return - V_364 ;
if ( F_5 ( V_389 . V_393 > V_394 ||
V_389 . V_393 == 0 ) ) {
F_15 ( L_62 ) ;
return - V_46 ;
}
if ( V_389 . V_393 > 1 &&
F_181 ( & V_389 . V_391 ,
( void T_65 * ) ( V_387 + V_390 [ 0 ] ) ,
V_390 [ V_389 . V_393 - 1 ] -
V_390 [ 0 ] ) != 0 )
return - V_364 ;
switch ( V_389 . V_393 ) {
case 1 :
V_389 . V_391 = ( T_3 ) - 1 ;
break;
case 2 :
if ( V_389 . V_395 != 0 ) {
F_15 ( L_63 ) ;
return - V_46 ;
}
break;
default:
break;
}
V_24 = F_202 ( & V_22 -> V_396 , true ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_184 ( V_338 , V_22 ,
( void T_65 * ) ( unsigned long ) V_389 . V_397 ,
NULL , V_389 . V_359 , V_389 . V_365 ,
V_389 . V_391 ,
( void T_65 * ) ( unsigned long ) V_389 . V_352 ,
NULL ) ;
F_203 ( & V_22 -> V_396 ) ;
if ( F_5 ( V_24 != 0 ) )
return V_24 ;
F_204 ( V_22 ) ;
return 0 ;
}
