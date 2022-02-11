static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
if ( V_2 -> V_9 && ! V_3 )
F_2 ( V_2 -> V_10 ,
V_2 -> V_9 ) ;
F_3 (val, list, head) {
struct V_11 * V_12 = V_5 -> V_12 ;
bool V_13 =
( V_3 ) ? false : V_5 -> V_14 ;
if ( F_4 ( V_5 -> V_15 ) ) {
if ( ! V_3 ) {
F_5
( F_6 ( V_5 -> V_12 ) ,
V_5 -> V_15 ) ;
}
if ( V_5 -> V_15 != V_2 -> V_15 )
F_7 ( V_5 -> V_15 ) ;
else
V_2 -> V_16 = false ;
V_5 -> V_15 = NULL ;
}
F_8 ( V_12 , V_13 , V_5 -> V_17 ,
V_5 -> V_18 ) ;
F_9 ( & V_5 -> V_17 ) ;
}
}
static int F_10 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
struct V_4 * V_21 )
{
int V_22 ;
V_22 = F_11 ( V_20 , V_2 , V_21 -> V_12 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_23;
if ( ! V_2 -> V_15 ) {
V_2 -> V_15 =
F_12 ( V_20 ) ;
if ( F_13 ( V_2 -> V_15 ) ) {
F_14 ( L_1
L_2 ) ;
V_22 = F_15 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
goto V_23;
}
}
if ( V_2 -> V_16 ) {
V_21 -> V_15 = F_12 ( V_20 ) ;
if ( F_13 ( V_21 -> V_15 ) ) {
F_14 ( L_1
L_2 ) ;
V_22 = F_15 ( V_21 -> V_15 ) ;
V_21 -> V_15 = NULL ;
goto V_23;
}
} else {
V_21 -> V_15 = V_2 -> V_15 ;
V_2 -> V_16 = true ;
}
return 0 ;
V_23:
return V_22 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_4 * * V_24 )
{
struct V_19 * V_20 = V_12 -> V_20 ;
struct V_4 * V_21 ;
struct V_25 * V_26 ;
int V_22 ;
if ( F_17 ( F_18 ( & V_2 -> V_27 , ( unsigned long ) V_12 ,
& V_26 ) == 0 ) ) {
V_21 = F_19 ( V_26 , struct V_4 , V_26 ) ;
V_21 -> V_28 = false ;
if ( F_4 ( V_24 != NULL ) )
* V_24 = V_21 ;
return 0 ;
}
V_21 = F_20 ( sizeof( * V_21 ) , V_29 ) ;
if ( F_4 ( V_21 == NULL ) ) {
F_14 ( L_3
L_4 ) ;
return - V_30 ;
}
V_21 -> V_26 . V_31 = ( unsigned long ) V_12 ;
V_22 = F_21 ( & V_2 -> V_27 , & V_21 -> V_26 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_5
L_4 ) ;
F_22 ( V_21 ) ;
return V_22 ;
}
V_21 -> V_12 = F_23 ( V_12 ) ;
V_21 -> V_28 = true ;
if ( F_4 ( V_24 != NULL ) )
* V_24 = V_21 ;
if ( ! V_20 -> V_32 ) {
F_24 ( & V_21 -> V_33 , & V_2 -> V_8 ) ;
return 0 ;
}
switch ( F_25 ( V_12 ) ) {
case V_34 :
case V_35 :
F_26 ( & V_21 -> V_33 , & V_2 -> V_36 ) ;
V_22 = F_10 ( V_20 , V_2 , V_21 ) ;
break;
case V_37 :
F_24 ( & V_21 -> V_33 , & V_2 -> V_36 ) ;
break;
default:
F_24 ( & V_21 -> V_33 , & V_2 -> V_8 ) ;
break;
}
return V_22 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_11 * V_38 )
{
int V_22 ;
V_22 = F_16 ( V_2 , F_28 ( V_38 ) , NULL ) ;
if ( V_22 )
return V_22 ;
return F_16 ( V_2 , V_38 , NULL ) ;
}
static int F_29 ( struct V_1 * V_2 ,
enum V_39 V_40 , T_1 V_41 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_11 * V_38 ;
int V_22 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_38 = F_30 ( V_2 -> V_45 , V_40 , V_41 ) ;
if ( F_13 ( V_38 ) )
return F_15 ( V_38 ) ;
V_22 = F_27 ( V_2 , V_38 ) ;
F_31 ( & V_38 ) ;
return V_22 ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
struct V_11 * V_46 )
{
struct V_6 * V_47 ;
struct V_48 * V_49 ;
int V_22 = 0 ;
struct V_11 * V_12 ;
T_1 V_50 ;
if ( V_20 -> V_51 && F_25 ( V_46 ) == V_35 ) {
for ( V_50 = 0 ; V_50 < V_52 ; ++ V_50 ) {
V_12 = F_32 ( V_46 , V_50 ) ;
if ( F_13 ( V_12 ) )
continue;
V_22 = F_16 ( V_2 , V_12 , NULL ) ;
F_31 ( & V_12 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
}
F_33 ( & V_20 -> V_53 ) ;
V_47 = F_34 ( V_46 ) ;
F_3 (entry, binding_list, ctx_list) {
V_12 = F_35 ( V_49 -> V_12 ) ;
if ( F_4 ( V_12 == NULL ) )
continue;
if ( F_25 ( V_49 -> V_12 ) == V_54 )
V_22 = F_27 ( V_2 , V_49 -> V_12 ) ;
else
V_22 = F_16 ( V_2 , V_49 -> V_12 ,
NULL ) ;
F_31 ( & V_12 ) ;
if ( F_4 ( V_22 != 0 ) )
break;
}
if ( V_20 -> V_51 && F_25 ( V_46 ) == V_35 ) {
struct V_55 * V_9 ;
V_9 = F_36 ( V_46 ) ;
if ( V_9 )
V_22 = F_37 ( V_2 ,
V_9 ,
true , NULL ) ;
}
F_38 ( & V_20 -> V_53 ) ;
return V_22 ;
}
static int F_39 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
unsigned long V_56 )
{
struct V_57 * V_58 ;
V_58 = F_40 ( sizeof( * V_58 ) , V_29 ) ;
if ( F_4 ( V_58 == NULL ) ) {
F_14 ( L_7 ) ;
return - V_30 ;
}
V_58 -> V_12 = V_12 ;
V_58 -> V_56 = V_56 ;
F_24 ( & V_58 -> V_33 , V_7 ) ;
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_57 * V_58 , * V_59 ;
F_42 (rel, n, list, head) {
F_43 ( & V_58 -> V_33 ) ;
F_22 ( V_58 ) ;
}
}
static void F_44 ( T_2 * V_60 ,
struct V_6 * V_7 )
{
struct V_57 * V_58 ;
F_3 (rel, list, head) {
if ( F_17 ( V_58 -> V_12 != NULL ) )
V_60 [ V_58 -> V_56 ] = V_58 -> V_12 -> V_41 ;
else
V_60 [ V_58 -> V_56 ] = V_61 ;
}
}
static int F_45 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
return F_46 ( V_63 ) ? : - V_44 ;
}
static int F_47 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_55 * V_64 ,
bool V_65 ,
T_2 * V_66 )
{
T_2 V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_25 * V_26 ;
int V_22 ;
if ( F_17 ( F_18 ( & V_2 -> V_27 , ( unsigned long ) V_64 ,
& V_26 ) == 0 ) ) {
V_69 = F_19 ( V_26 , struct V_68 ,
V_26 ) ;
if ( F_4 ( V_69 -> V_65 != V_65 ) ) {
F_14 ( L_8 ) ;
return - V_44 ;
}
V_71 = & V_69 -> V_72 ;
V_67 = V_69 - V_2 -> V_73 ;
} else {
V_67 = V_2 -> V_74 ;
if ( F_4 ( V_67 >= V_75 ) ) {
F_14 ( L_9
L_10 ) ;
return - V_44 ;
}
V_69 = & V_2 -> V_73 [ V_67 ] ;
V_69 -> V_26 . V_31 = ( unsigned long ) V_64 ;
V_22 = F_21 ( & V_2 -> V_27 , & V_69 -> V_26 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_11
L_4 ) ;
return V_22 ;
}
++ V_2 -> V_74 ;
V_71 = & V_69 -> V_72 ;
V_71 -> V_76 = F_48 ( & V_64 -> V_72 ) ;
V_71 -> V_77 = false ;
F_24 ( & V_71 -> V_33 , & V_2 -> V_78 ) ;
V_69 -> V_65 = V_65 ;
}
if ( V_66 )
* V_66 = V_67 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_22 = 0 ;
F_3 (val, &sw_context->resource_list, head) {
struct V_11 * V_12 = V_5 -> V_12 ;
V_22 = F_50 ( V_12 , true , V_5 -> V_79 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( V_12 -> V_80 ) {
struct V_55 * V_64 = V_12 -> V_80 ;
V_22 = F_37
( V_2 , V_64 ,
F_51 ( V_12 ) , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
}
if ( V_2 -> V_9 ) {
struct V_55 * V_81 ;
V_81 =
F_36 ( V_2 -> V_10 ) ;
if ( V_81 &&
V_81 != V_2 -> V_9 ) {
V_22 = - V_44 ;
}
}
return V_22 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_22 ;
F_3 (val, &sw_context->resource_list, head) {
struct V_11 * V_12 = V_5 -> V_12 ;
struct V_55 * V_80 = V_12 -> V_80 ;
V_22 = F_53 ( V_12 ) ;
if ( F_4 ( V_22 != 0 ) ) {
if ( V_22 != - V_82 )
F_14 ( L_12 ) ;
return V_22 ;
}
if ( V_80 && V_12 -> V_80 && ( V_80 != V_12 -> V_80 ) ) {
struct V_55 * V_64 = V_12 -> V_80 ;
V_22 = F_37
( V_2 , V_64 ,
F_51 ( V_12 ) , NULL ) ;
if ( V_22 ) {
F_54 ( & V_64 -> V_72 ) ;
return V_22 ;
}
}
}
return 0 ;
}
static int F_55 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_2 * V_83 ,
struct V_11 * V_12 ,
struct V_4 * * V_84 )
{
int V_22 ;
struct V_4 * V_21 ;
* V_84 = NULL ;
V_22 = F_39 ( & V_2 -> V_85 ,
V_12 ,
V_83 - V_2 -> V_86 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_16 ( V_2 , V_12 , & V_21 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( V_84 )
* V_84 = V_21 ;
return 0 ;
}
static int
F_56 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
enum F_25 V_87 ,
const struct V_88 * V_89 ,
T_2 * V_83 ,
struct V_4 * * V_84 )
{
struct V_90 * V_91 =
& V_2 -> V_92 [ V_87 ] ;
struct V_11 * V_12 ;
struct V_4 * V_21 ;
int V_22 ;
if ( * V_83 == V_93 ) {
if ( V_84 )
* V_84 = NULL ;
if ( V_87 == V_34 ) {
F_14 ( L_13 ) ;
return - V_44 ;
}
return 0 ;
}
if ( F_17 ( V_91 -> V_94 && * V_83 == V_91 -> V_95 ) ) {
const struct V_11 * V_12 = V_91 -> V_12 ;
V_91 -> V_21 -> V_28 = false ;
if ( V_84 )
* V_84 = V_91 -> V_21 ;
return F_39
( & V_2 -> V_85 , V_12 ,
V_83 - V_2 -> V_86 ) ;
}
V_22 = F_57 ( V_20 ,
V_2 -> V_96 -> V_97 ,
* V_83 ,
V_89 ,
& V_12 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_14 ,
( unsigned ) * V_83 ) ;
F_58 () ;
return V_22 ;
}
V_91 -> V_94 = true ;
V_91 -> V_12 = V_12 ;
V_91 -> V_95 = * V_83 ;
V_22 = F_55 ( V_20 , V_2 , V_83 ,
V_12 , & V_21 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_98;
V_91 -> V_21 = V_21 ;
if ( V_84 )
* V_84 = V_21 ;
F_31 ( & V_12 ) ;
return 0 ;
V_98:
F_59 ( V_2 -> V_99 != NULL ) ;
V_2 -> V_99 = V_12 ;
return V_22 ;
}
static int F_60 ( struct V_11 * V_100 )
{
struct V_19 * V_20 = V_100 -> V_20 ;
struct V_55 * V_9 ;
struct {
T_3 V_62 ;
T_4 V_101 ;
} * V_102 ;
V_9 = F_36 ( V_100 ) ;
if ( ! V_9 || V_9 -> V_10 )
return 0 ;
V_102 = F_61 ( V_20 , sizeof( * V_102 ) , V_100 -> V_41 ) ;
if ( V_102 == NULL ) {
F_14 ( L_15 ) ;
return - V_30 ;
}
V_102 -> V_62 . V_41 = V_103 ;
V_102 -> V_62 . V_104 = sizeof( V_102 -> V_101 ) ;
V_102 -> V_101 . V_105 = V_100 -> V_41 ;
V_102 -> V_101 . V_106 = V_9 -> V_72 . V_107 . V_108 ;
F_62 ( V_20 , sizeof( * V_102 ) ) ;
F_2 ( V_100 , V_9 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_22 ;
F_3 (val, &sw_context->resource_list, head) {
if ( F_4 ( ! V_5 -> V_15 ) )
break;
V_22 = F_64
( F_6 ( V_5 -> V_12 ) ) ;
if ( F_4 ( V_22 != 0 ) ) {
if ( V_22 != - V_82 )
F_14 ( L_16 ) ;
return V_22 ;
}
V_22 = F_60 ( V_5 -> V_12 ) ;
if ( V_22 != 0 )
return V_22 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
enum V_39 V_40 ,
enum V_109 V_110 ,
T_5 V_111 ,
T_5 V_112 [] , T_1 V_113 ,
T_1 V_114 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_115 * V_45 ;
T_1 V_50 ;
int V_22 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_45 = V_2 -> V_45 ;
for ( V_50 = 0 ; V_50 < V_113 ; ++ V_50 ) {
struct V_116 V_117 ;
struct V_11 * V_38 = NULL ;
if ( V_112 [ V_50 ] != V_93 ) {
V_38 = F_30 ( V_45 , V_40 , V_112 [ V_50 ] ) ;
if ( F_13 ( V_38 ) ) {
F_14 ( L_17 ) ;
return F_15 ( V_38 ) ;
}
V_22 = F_27 ( V_2 , V_38 ) ;
if ( V_22 ) {
F_14 ( L_18
L_19 ) ;
F_31 ( & V_38 ) ;
return V_22 ;
}
}
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_38 ;
V_117 . V_118 . V_119 = V_110 ;
V_117 . V_111 = V_111 ;
V_117 . V_120 = V_114 + V_50 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
V_111 , V_117 . V_120 ) ;
if ( V_38 )
F_31 ( & V_38 ) ;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_121 {
T_3 V_62 ;
T_2 V_105 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_121 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_105 , NULL ) ;
}
static int F_68 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_123 {
T_3 V_62 ;
T_6 V_101 ;
} * V_102 ;
struct V_4 * V_42 ;
struct V_4 * V_124 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_123 , V_62 ) ;
if ( V_102 -> V_101 . type >= V_125 ) {
F_14 ( L_20 ,
( unsigned ) V_102 -> V_101 . type ) ;
return - V_44 ;
}
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_101 . V_105 ,
& V_42 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_128 . V_129 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( V_20 -> V_32 ) {
struct V_116 V_117 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_124 ? V_124 -> V_12 : NULL ;
V_117 . V_118 . V_119 = V_130 ;
V_117 . V_120 = V_102 -> V_101 . type ;
F_66 ( V_42 -> V_15 ,
& V_117 . V_118 , 0 , V_117 . V_120 ) ;
}
return 0 ;
}
static int F_69 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_123 {
T_3 V_62 ;
T_7 V_101 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_123 , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_131 . V_129 , NULL ) ;
if ( V_22 )
return V_22 ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_132 . V_129 , NULL ) ;
}
static int F_70 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_8 V_101 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_131 , NULL ) ;
if ( V_22 != 0 )
return V_22 ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_132 , NULL ) ;
}
static int F_72 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_9 V_101 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_133 , NULL ) ;
if ( V_22 != 0 )
return V_22 ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_134 , NULL ) ;
}
static int F_73 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_123 {
T_3 V_62 ;
T_10 V_101 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_123 , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_131 . V_129 , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_132 . V_129 , NULL ) ;
}
static int F_74 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_123 {
T_3 V_62 ;
T_11 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_123 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_135 . V_129 , NULL ) ;
}
static int F_75 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_123 {
T_3 V_62 ;
T_12 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_123 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 , & V_102 -> V_101 . V_129 ,
NULL ) ;
}
static int F_76 ( struct V_19 * V_20 ,
struct V_55 * V_136 ,
struct V_1 * V_2 )
{
struct V_90 * V_137 =
& V_2 -> V_92 [ V_34 ] ;
int V_22 ;
F_59 ( ! V_137 -> V_94 ) ;
V_2 -> V_138 = V_137 -> V_12 ;
if ( F_4 ( V_136 != V_2 -> V_139 ) ) {
if ( F_4 ( V_136 -> V_72 . V_140 > 4 ) ) {
F_14 ( L_21 ) ;
return - V_44 ;
}
if ( F_4 ( V_2 -> V_139 != NULL ) ) {
V_2 -> V_141 = true ;
V_22 = F_37 ( V_2 ,
V_2 -> V_139 ,
V_20 -> V_32 , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
V_2 -> V_139 = V_136 ;
V_22 = F_37 ( V_2 ,
V_20 -> V_142 ,
V_20 -> V_32 , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
return 0 ;
}
static void F_77 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_141 ) {
struct V_90 * V_137 =
& V_2 -> V_92 [ V_34 ] ;
struct V_11 * V_46 ;
int V_22 ;
F_59 ( ! V_137 -> V_94 ) ;
V_46 = V_137 -> V_12 ;
V_22 = F_78 ( V_20 , V_46 -> V_41 ) ;
if ( F_4 ( V_22 != 0 ) )
F_14 ( L_22 ) ;
}
if ( V_20 -> V_143 != V_2 -> V_139 ) {
if ( V_20 -> V_143 ) {
F_79 ( V_20 -> V_143 , false ) ;
F_9 ( & V_20 -> V_143 ) ;
}
if ( ! V_2 -> V_141 ) {
F_79 ( V_2 -> V_139 , true ) ;
if ( ! V_20 -> V_144 ) {
F_79 ( V_20 -> V_142 ,
true ) ;
V_20 -> V_144 = true ;
}
F_59 ( V_2 -> V_138 == NULL ) ;
V_20 -> V_145 = V_2 -> V_138 -> V_41 ;
V_20 -> V_146 = true ;
V_20 -> V_143 =
F_80 ( V_2 -> V_139 ) ;
}
}
}
static int F_81 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_13 * V_41 ,
struct V_55 * * V_147 )
{
struct V_55 * V_148 = NULL ;
T_2 V_95 = * V_41 ;
struct V_149 * V_150 ;
int V_22 ;
V_22 = F_82 ( V_2 -> V_96 -> V_97 , V_95 , & V_148 ,
NULL ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_23 ) ;
V_22 = - V_44 ;
goto V_98;
}
if ( F_4 ( V_2 -> V_151 >= V_152 ) ) {
F_14 ( L_24
L_25 ) ;
V_22 = - V_44 ;
goto V_98;
}
V_150 = & V_2 -> V_153 [ V_2 -> V_151 ++ ] ;
V_150 -> V_154 = V_41 ;
V_150 -> V_155 = NULL ;
V_22 = F_37 ( V_2 , V_148 , true , & V_150 -> V_156 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_98;
* V_147 = V_148 ;
return 0 ;
V_98:
F_9 ( & V_148 ) ;
* V_147 = NULL ;
return V_22 ;
}
static int F_83 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_14 * V_157 ,
struct V_55 * * V_147 )
{
struct V_55 * V_148 = NULL ;
T_2 V_95 = V_157 -> V_158 ;
struct V_149 * V_150 ;
int V_22 ;
V_22 = F_82 ( V_2 -> V_96 -> V_97 , V_95 , & V_148 ,
NULL ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_26 ) ;
V_22 = - V_44 ;
goto V_98;
}
if ( F_4 ( V_2 -> V_151 >= V_152 ) ) {
F_14 ( L_24
L_25 ) ;
V_22 = - V_44 ;
goto V_98;
}
V_150 = & V_2 -> V_153 [ V_2 -> V_151 ++ ] ;
V_150 -> V_155 = V_157 ;
V_22 = F_37 ( V_2 , V_148 , false , & V_150 -> V_156 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_98;
* V_147 = V_148 ;
return 0 ;
V_98:
F_9 ( & V_148 ) ;
* V_147 = NULL ;
return V_22 ;
}
static int F_84 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_159 {
T_3 V_62 ;
T_15 V_160 ;
} * V_102 ;
int V_22 ;
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_11 * V_161 ;
if ( V_42 == NULL ) {
F_14 ( L_27 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , struct V_159 , V_62 ) ;
if ( V_102 -> V_160 . type < V_162 ||
V_102 -> V_160 . type >= V_163 )
return - V_44 ;
V_161 = F_32 ( V_42 -> V_12 , V_164 ) ;
V_22 = F_85 ( V_161 , V_102 -> V_160 . V_165 ) ;
F_31 ( & V_161 ) ;
return V_22 ;
}
static int F_86 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_166 {
T_3 V_62 ;
T_16 V_160 ;
} * V_102 ;
struct V_55 * V_148 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_166 , V_62 ) ;
V_22 = F_81 ( V_20 , V_2 , & V_102 -> V_160 . V_106 ,
& V_148 ) ;
if ( V_22 != 0 )
return V_22 ;
V_2 -> V_9 = V_148 ;
V_2 -> V_10 = V_2 -> V_43 -> V_12 ;
F_9 ( & V_148 ) ;
return V_22 ;
}
static int F_87 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_167 {
T_3 V_62 ;
T_17 V_160 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_167 ,
V_62 ) ;
return F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_160 . V_105 ,
NULL ) ;
}
static int F_88 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_168 {
T_3 V_62 ;
T_18 V_160 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_168 ,
V_62 ) ;
if ( F_4 ( V_20 -> V_32 ) ) {
struct {
T_3 V_62 ;
T_17 V_160 ;
} V_169 ;
F_59 ( sizeof( V_169 ) != sizeof( * V_102 ) ) ;
V_169 . V_62 . V_41 = V_170 ;
V_169 . V_62 . V_104 = V_102 -> V_62 . V_104 ;
V_169 . V_160 . V_105 = V_102 -> V_160 . V_105 ;
V_169 . V_160 . type = V_102 -> V_160 . type ;
memcpy ( V_102 , & V_169 , sizeof( * V_102 ) ) ;
return F_87 ( V_20 , V_2 , V_62 ) ;
}
return F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_160 . V_105 ,
NULL ) ;
}
static int F_89 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_55 * V_148 ;
struct V_171 {
T_3 V_62 ;
T_19 V_160 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_171 , V_62 ) ;
V_22 = F_67 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_81 ( V_20 , V_2 ,
& V_102 -> V_160 . V_106 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_76 ( V_20 , V_148 , V_2 ) ;
F_9 ( & V_148 ) ;
return V_22 ;
}
static int F_90 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_55 * V_148 ;
struct V_171 {
T_3 V_62 ;
T_20 V_160 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_171 , V_62 ) ;
if ( V_20 -> V_32 ) {
struct {
T_3 V_62 ;
T_19 V_160 ;
} V_169 ;
F_59 ( sizeof( V_169 ) != sizeof( * V_102 ) ) ;
V_169 . V_62 . V_41 = V_172 ;
V_169 . V_62 . V_104 = V_102 -> V_62 . V_104 ;
V_169 . V_160 . V_105 = V_102 -> V_160 . V_105 ;
V_169 . V_160 . type = V_102 -> V_160 . type ;
V_169 . V_160 . V_106 = V_102 -> V_160 . V_173 . V_158 ;
V_169 . V_160 . V_56 = V_102 -> V_160 . V_173 . V_56 ;
memcpy ( V_102 , & V_169 , sizeof( * V_102 ) ) ;
return F_89 ( V_20 , V_2 , V_62 ) ;
}
V_22 = F_67 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_83 ( V_20 , V_2 ,
& V_102 -> V_160 . V_173 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_76 ( V_20 , V_148 , V_2 ) ;
F_9 ( & V_148 ) ;
return V_22 ;
}
static int F_91 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_55 * V_148 ;
struct V_171 {
T_3 V_62 ;
T_21 V_160 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_171 , V_62 ) ;
V_22 = F_67 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_81 ( V_20 , V_2 ,
& V_102 -> V_160 . V_106 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
F_9 ( & V_148 ) ;
return 0 ;
}
static int F_92 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_55 * V_148 ;
struct V_171 {
T_3 V_62 ;
T_22 V_160 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_171 , V_62 ) ;
if ( V_20 -> V_32 ) {
struct {
T_3 V_62 ;
T_21 V_160 ;
} V_169 ;
F_59 ( sizeof( V_169 ) != sizeof( * V_102 ) ) ;
V_169 . V_62 . V_41 = V_174 ;
V_169 . V_62 . V_104 = V_102 -> V_62 . V_104 ;
V_169 . V_160 . V_105 = V_102 -> V_160 . V_105 ;
V_169 . V_160 . type = V_102 -> V_160 . type ;
V_169 . V_160 . V_106 = V_102 -> V_160 . V_173 . V_158 ;
V_169 . V_160 . V_56 = V_102 -> V_160 . V_173 . V_56 ;
memcpy ( V_102 , & V_169 , sizeof( * V_102 ) ) ;
return F_91 ( V_20 , V_2 , V_62 ) ;
}
V_22 = F_67 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_83 ( V_20 , V_2 ,
& V_102 -> V_160 . V_173 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
F_9 ( & V_148 ) ;
return 0 ;
}
static int F_93 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_55 * V_148 = NULL ;
struct V_175 * V_176 = NULL ;
struct V_177 {
T_3 V_62 ;
T_23 V_178 ;
} * V_102 ;
int V_22 ;
T_24 * V_179 ;
T_2 V_180 ;
V_102 = F_19 ( V_62 , struct V_177 , V_62 ) ;
V_179 = ( T_24 * ) ( ( unsigned long ) & V_102 -> V_178 +
V_62 -> V_104 - sizeof( * V_179 ) ) ;
if ( F_4 ( V_179 -> V_181 != sizeof( * V_179 ) ) ) {
F_14 ( L_28 ) ;
return - V_44 ;
}
V_22 = F_83 ( V_20 , V_2 ,
& V_102 -> V_178 . V_182 . V_157 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_180 = V_148 -> V_72 . V_140 * V_183 ;
if ( F_4 ( V_102 -> V_178 . V_182 . V_157 . V_56 > V_180 ) ) {
F_14 ( L_29 ) ;
return - V_44 ;
}
V_180 -= V_102 -> V_178 . V_182 . V_157 . V_56 ;
if ( F_4 ( V_179 -> V_184 > V_180 ) )
V_179 -> V_184 = V_180 ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 , & V_102 -> V_178 . V_185 . V_129 ,
NULL ) ;
if ( F_4 ( V_22 != 0 ) ) {
if ( F_4 ( V_22 != - V_82 ) )
F_14 ( L_30 ) ;
goto V_186;
}
V_176 = F_94 ( V_2 -> V_92 [ V_126 ] . V_12 ) ;
F_95 ( V_176 , V_2 -> V_96 -> V_97 , & V_148 -> V_72 ,
V_62 ) ;
V_186:
F_9 ( & V_148 ) ;
return V_22 ;
}
static int F_96 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_187 {
T_3 V_62 ;
T_25 V_101 ;
} * V_102 ;
T_26 * V_188 = ( T_26 * ) (
( unsigned long ) V_62 + sizeof( * V_102 ) ) ;
T_27 * V_189 ;
T_2 V_50 ;
T_2 V_190 ;
int V_22 ;
V_22 = F_67 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_102 = F_19 ( V_62 , struct V_187 , V_62 ) ;
V_190 = ( V_62 -> V_104 - sizeof( V_102 -> V_101 ) ) / sizeof( * V_188 ) ;
if ( F_4 ( V_102 -> V_101 . V_191 > V_190 ) ) {
F_14 ( L_31 ) ;
return - V_44 ;
}
for ( V_50 = 0 ; V_50 < V_102 -> V_101 . V_191 ; ++ V_50 , ++ V_188 ) {
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_188 -> V_192 . V_193 , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
V_190 = ( V_62 -> V_104 - sizeof( V_102 -> V_101 ) -
V_102 -> V_101 . V_191 * sizeof( * V_188 ) ) / sizeof( * V_189 ) ;
if ( F_4 ( V_102 -> V_101 . V_194 > V_190 ) ) {
F_14 ( L_32 ) ;
return - V_44 ;
}
V_189 = ( T_27 * ) V_188 ;
for ( V_50 = 0 ; V_50 < V_102 -> V_101 . V_194 ; ++ V_50 , ++ V_189 ) {
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_189 -> V_195 . V_193 , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
return 0 ;
}
static int F_97 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_196 {
T_3 V_62 ;
T_28 V_197 ;
} * V_102 ;
T_29 * V_198 = ( T_29 * )
( ( unsigned long ) V_62 + V_62 -> V_104 + sizeof( V_62 ) ) ;
T_29 * V_199 = ( T_29 * )
( ( unsigned long ) V_62 + sizeof( struct V_196 ) ) ;
struct V_4 * V_42 ;
struct V_4 * V_124 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_196 ,
V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_197 . V_105 ,
& V_42 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
for (; V_199 < V_198 ; ++ V_199 ) {
if ( F_17 ( V_199 -> V_200 != V_201 ) )
continue;
if ( V_199 -> V_202 >= V_203 ) {
F_14 ( L_33 ,
( unsigned ) V_199 -> V_202 ) ;
return - V_44 ;
}
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_199 -> V_204 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( V_20 -> V_32 ) {
struct V_205 V_117 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_124 ? V_124 -> V_12 : NULL ;
V_117 . V_118 . V_119 = V_206 ;
V_117 . V_207 = V_199 -> V_202 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
0 , V_117 . V_207 ) ;
}
}
return 0 ;
}
static int F_98 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
void * V_208 )
{
struct V_55 * V_148 ;
int V_22 ;
struct {
T_2 V_62 ;
T_30 V_101 ;
} * V_102 = V_208 ;
V_22 = F_83 ( V_20 , V_2 ,
& V_102 -> V_101 . V_157 ,
& V_148 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
F_9 ( & V_148 ) ;
return V_22 ;
}
static int F_99 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
struct V_4 * V_67 ,
T_2 * V_209 ,
unsigned long V_210 )
{
struct V_55 * V_211 ;
int V_22 ;
V_22 = F_81 ( V_20 , V_2 , V_209 , & V_211 ) ;
if ( V_22 )
return V_22 ;
V_67 -> V_14 = true ;
if ( V_67 -> V_28 )
V_67 -> V_79 = true ;
F_9 ( & V_67 -> V_17 ) ;
V_67 -> V_17 = V_211 ;
V_67 -> V_18 = V_210 ;
return 0 ;
}
static int F_100 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
enum F_25 V_87 ,
const struct V_88
* V_89 ,
T_2 * V_212 ,
T_2 * V_209 ,
unsigned long V_210 )
{
struct V_4 * V_67 ;
int V_22 ;
V_22 = F_56 ( V_20 , V_2 , V_87 ,
V_89 , V_212 , & V_67 ) ;
if ( V_22 )
return V_22 ;
return F_99 ( V_20 , V_2 , V_67 ,
V_209 , V_210 ) ;
}
static int F_101 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_213 {
T_3 V_62 ;
T_31 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_213 , V_62 ) ;
return F_100 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , & V_102 -> V_101 . V_106 ,
0 ) ;
}
static int F_102 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_32 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_215 . V_129 , NULL ) ;
}
static int F_103 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_33 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , NULL ) ;
}
static int F_104 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_34 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_215 . V_129 , NULL ) ;
}
static int F_105 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_35 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , NULL ) ;
}
static int F_106 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_36 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_215 . V_129 , NULL ) ;
}
static int F_107 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_214 {
T_3 V_62 ;
T_37 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_214 , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , NULL ) ;
}
static int F_108 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_216 {
T_3 V_62 ;
T_38 V_101 ;
} * V_102 ;
int V_22 ;
T_39 V_104 ;
struct V_4 * V_5 ;
V_102 = F_19 ( V_62 , struct V_216 ,
V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_101 . V_105 ,
& V_5 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( F_4 ( ! V_20 -> V_32 ) )
return 0 ;
V_104 = V_102 -> V_62 . V_104 - sizeof( V_102 -> V_101 ) ;
V_22 = F_109 ( V_20 ,
F_110 ( V_5 -> V_12 ) ,
V_102 -> V_101 . V_217 , V_102 + 1 ,
V_102 -> V_101 . type , V_104 ,
& V_2 -> V_218 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
return F_39 ( & V_2 -> V_85 ,
NULL , & V_102 -> V_62 . V_41 -
V_2 -> V_86 ) ;
return 0 ;
}
static int F_111 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_219 {
T_3 V_62 ;
T_40 V_101 ;
} * V_102 ;
int V_22 ;
struct V_4 * V_5 ;
V_102 = F_19 ( V_62 , struct V_219 ,
V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_101 . V_105 ,
& V_5 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( F_4 ( ! V_20 -> V_32 ) )
return 0 ;
V_22 = F_112 ( F_110 ( V_5 -> V_12 ) ,
V_102 -> V_101 . V_217 ,
V_102 -> V_101 . type ,
& V_2 -> V_218 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
return F_39 ( & V_2 -> V_85 ,
NULL , & V_102 -> V_62 . V_41 -
V_2 -> V_86 ) ;
return 0 ;
}
static int F_113 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_220 {
T_3 V_62 ;
T_41 V_101 ;
} * V_102 ;
struct V_4 * V_42 , * V_124 = NULL ;
struct V_221 V_117 ;
struct V_11 * V_12 = NULL ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_220 ,
V_62 ) ;
if ( V_102 -> V_101 . type >= V_222 ) {
F_14 ( L_34 ,
( unsigned ) V_102 -> V_101 . type ) ;
return - V_44 ;
}
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_101 . V_105 ,
& V_42 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( ! V_20 -> V_32 )
return 0 ;
if ( V_102 -> V_101 . V_217 != V_93 ) {
V_12 = F_114 ( F_110 ( V_42 -> V_12 ) ,
V_102 -> V_101 . V_217 ,
V_102 -> V_101 . type ) ;
if ( ! F_13 ( V_12 ) ) {
V_22 = F_55 ( V_20 , V_2 ,
& V_102 -> V_101 . V_217 , V_12 ,
& V_124 ) ;
F_31 ( & V_12 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
}
if ( ! V_124 ) {
V_22 = F_56 ( V_20 , V_2 ,
V_223 ,
V_224 ,
& V_102 -> V_101 . V_217 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_124 ? V_124 -> V_12 : NULL ;
V_117 . V_118 . V_119 = V_225 ;
V_117 . V_111 = V_102 -> V_101 . type - V_226 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
V_117 . V_111 , 0 ) ;
return 0 ;
}
static int F_115 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_227 {
T_3 V_62 ;
T_42 V_101 ;
} * V_102 ;
int V_22 ;
V_102 = F_19 ( V_62 , struct V_227 ,
V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 , & V_102 -> V_101 . V_105 ,
NULL ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
if ( V_20 -> V_32 )
V_62 -> V_41 = V_228 ;
return 0 ;
}
static int F_116 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_229 {
T_3 V_62 ;
T_43 V_101 ;
} * V_102 ;
V_102 = F_19 ( V_62 , struct V_229 ,
V_62 ) ;
return F_100 ( V_20 , V_2 , V_223 ,
V_224 ,
& V_102 -> V_101 . V_217 , & V_102 -> V_101 . V_106 ,
V_102 -> V_101 . V_230 ) ;
}
static int
F_117 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_44 V_101 ;
} * V_102 ;
struct V_4 * V_124 = NULL ;
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_231 V_117 ;
int V_22 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_124 ? V_124 -> V_12 : NULL ;
V_117 . V_118 . V_119 = V_232 ;
V_117 . V_111 = V_102 -> V_101 . type - V_226 ;
V_117 . V_56 = V_102 -> V_101 . V_230 ;
V_117 . V_104 = V_102 -> V_101 . V_233 ;
V_117 . V_120 = V_102 -> V_101 . V_120 ;
if ( V_117 . V_111 >= V_234 ||
V_117 . V_120 >= V_235 ) {
F_14 ( L_35 ,
( unsigned ) V_102 -> V_101 . type ,
( unsigned ) V_117 . V_120 ) ;
return - V_44 ;
}
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
V_117 . V_111 , V_117 . V_120 ) ;
return 0 ;
}
static int F_118 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_45 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
T_1 V_236 = ( V_102 -> V_62 . V_104 - sizeof( V_102 -> V_101 ) ) /
sizeof( V_237 ) ;
if ( ( V_238 ) V_102 -> V_101 . V_239 + ( V_238 ) V_236 >
( V_238 ) V_240 ||
V_102 -> V_101 . type >= V_241 ) {
F_14 ( L_36 ) ;
return - V_44 ;
}
return F_65 ( V_2 , V_242 ,
V_243 ,
V_102 -> V_101 . type - V_226 ,
( void * ) & V_102 [ 1 ] , V_236 ,
V_102 -> V_101 . V_239 ) ;
}
static int F_119 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_46 V_101 ;
} * V_102 ;
struct V_11 * V_12 = NULL ;
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_221 V_117 ;
int V_22 = 0 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
if ( V_102 -> V_101 . type >= V_241 ) {
F_14 ( L_34 ,
( unsigned ) V_102 -> V_101 . type ) ;
return - V_44 ;
}
if ( V_102 -> V_101 . V_244 != V_93 ) {
V_12 = F_114 ( V_2 -> V_45 , V_102 -> V_101 . V_244 , 0 ) ;
if ( F_13 ( V_12 ) ) {
F_14 ( L_37 ) ;
return F_15 ( V_12 ) ;
}
V_22 = F_16 ( V_2 , V_12 , NULL ) ;
if ( V_22 )
goto V_245;
}
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = V_12 ;
V_117 . V_118 . V_119 = V_246 ;
V_117 . V_111 = V_102 -> V_101 . type - V_226 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
V_117 . V_111 , 0 ) ;
V_245:
if ( V_12 )
F_31 ( & V_12 ) ;
return V_22 ;
}
static int F_120 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_247 V_117 ;
struct V_4 * V_124 ;
struct {
T_3 V_62 ;
T_47 V_101 ;
T_48 V_208 [] ;
} * V_102 ;
int V_50 , V_22 , V_248 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_248 = ( V_102 -> V_62 . V_104 - sizeof( V_102 -> V_101 ) ) /
sizeof( T_48 ) ;
if ( ( V_238 ) V_248 + ( V_238 ) V_102 -> V_101 . V_249 >
( V_238 ) V_250 ) {
F_14 ( L_38 ) ;
return - V_44 ;
}
for ( V_50 = 0 ; V_50 < V_248 ; V_50 ++ ) {
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_208 [ V_50 ] . V_129 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_119 = V_251 ;
V_117 . V_118 . V_12 = ( ( V_124 ) ? V_124 -> V_12 : NULL ) ;
V_117 . V_56 = V_102 -> V_208 [ V_50 ] . V_56 ;
V_117 . V_252 = V_102 -> V_208 [ V_50 ] . V_252 ;
V_117 . V_120 = V_50 + V_102 -> V_101 . V_249 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
0 , V_117 . V_120 ) ;
}
return 0 ;
}
static int F_121 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_253 V_117 ;
struct V_4 * V_124 ;
struct {
T_3 V_62 ;
T_49 V_101 ;
} * V_102 ;
int V_22 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_101 . V_129 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = ( ( V_124 ) ? V_124 -> V_12 : NULL ) ;
V_117 . V_118 . V_119 = V_254 ;
V_117 . V_56 = V_102 -> V_101 . V_56 ;
V_117 . V_255 = V_102 -> V_101 . V_255 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 , 0 , 0 ) ;
return 0 ;
}
static int F_122 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_50 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
int V_22 ;
T_1 V_256 = ( V_102 -> V_62 . V_104 - sizeof( V_102 -> V_101 ) ) /
sizeof( V_257 ) ;
if ( V_256 > V_258 ) {
F_14 ( L_39 ) ;
return - V_44 ;
}
V_22 = F_65 ( V_2 , V_259 ,
V_260 , 0 ,
& V_102 -> V_101 . V_261 , 1 , 0 ) ;
if ( V_22 )
return V_22 ;
return F_65 ( V_2 , V_262 ,
V_263 , 0 ,
( void * ) & V_102 [ 1 ] , V_256 , 0 ) ;
}
static int F_123 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_51 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
return F_29 ( V_2 , V_262 ,
V_102 -> V_101 . V_264 ) ;
}
static int F_124 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_52 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
return F_29 ( V_2 , V_259 ,
V_102 -> V_101 . V_261 ) ;
}
static int F_125 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_4 * V_265 ;
struct V_11 * V_12 ;
enum V_39 V_40 ;
int V_22 ;
struct {
T_3 V_62 ;
T_5 V_266 ;
T_5 V_129 ;
} * V_102 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_40 = F_126 ( V_62 -> V_41 ) ;
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_129 , & V_265 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_12 = F_32 ( V_42 -> V_12 , V_267 [ V_40 ] ) ;
V_22 = F_85 ( V_12 , V_102 -> V_266 ) ;
F_31 ( & V_12 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
return F_127 ( V_2 -> V_45 ,
V_42 -> V_12 ,
V_265 -> V_12 ,
V_40 ,
V_102 -> V_266 ,
V_62 ,
V_62 -> V_104 + sizeof( * V_62 ) ,
& V_2 -> V_218 ) ;
}
static int F_128 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_268 V_117 ;
struct V_4 * V_124 ;
struct {
T_3 V_62 ;
T_53 V_101 ;
T_54 V_269 [] ;
} * V_102 ;
int V_50 , V_22 , V_248 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_248 = ( V_102 -> V_62 . V_104 - sizeof( V_102 -> V_101 ) ) /
sizeof( T_54 ) ;
if ( V_248 > V_270 ) {
F_14 ( L_40 ) ;
return - V_44 ;
}
for ( V_50 = 0 ; V_50 < V_248 ; V_50 ++ ) {
V_22 = F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_269 [ V_50 ] . V_129 , & V_124 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_117 . V_118 . V_46 = V_42 -> V_12 ;
V_117 . V_118 . V_12 = ( ( V_124 ) ? V_124 -> V_12 : NULL ) ;
V_117 . V_118 . V_119 = V_271 ,
V_117 . V_56 = V_102 -> V_269 [ V_50 ] . V_56 ;
V_117 . V_104 = V_102 -> V_269 [ V_50 ] . V_233 ;
V_117 . V_120 = V_50 ;
F_66 ( V_42 -> V_15 , & V_117 . V_118 ,
0 , V_117 . V_120 ) ;
}
return 0 ;
}
static int F_129 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_11 * V_12 ;
struct {
T_3 V_62 ;
T_5 V_266 ;
} * V_102 ;
enum V_272 V_273 ;
int V_22 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_273 = F_130 ( V_62 -> V_41 ) ;
V_12 = F_32 ( V_42 -> V_12 , V_274 [ V_273 ] ) ;
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
V_22 = F_85 ( V_12 , V_102 -> V_266 ) ;
F_31 ( & V_12 ) ;
return V_22 ;
}
static int F_131 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
union {
T_55 V_275 ;
T_56 V_276 ;
T_57 V_277 ;
T_58 V_129 ;
};
} * V_102 ;
F_132 ( F_133 ( F_71 ( * V_102 ) , V_275 . V_129 ) !=
F_133 ( F_71 ( * V_102 ) , V_129 ) ) ;
F_132 ( F_133 ( F_71 ( * V_102 ) , V_276 . V_129 ) !=
F_133 ( F_71 ( * V_102 ) , V_129 ) ) ;
F_132 ( F_133 ( F_71 ( * V_102 ) , V_277 . V_129 ) !=
F_133 ( F_71 ( * V_102 ) , V_129 ) ) ;
V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
return F_56 ( V_20 , V_2 , V_126 ,
V_127 ,
& V_102 -> V_129 , NULL ) ;
}
static int F_134 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
if ( F_4 ( V_42 == NULL ) ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_135 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct {
T_3 V_62 ;
union V_278 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
enum V_39 V_40 = F_126 ( V_62 -> V_41 ) ;
struct V_11 * V_38 ;
int V_22 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_22 = F_136 ( V_2 -> V_45 ,
V_102 -> V_101 . V_279 , V_40 ,
& V_2 -> V_218 ,
& V_38 ) ;
if ( V_22 || ! V_38 )
return V_22 ;
return F_27 ( V_2 , V_38 ) ;
}
static int F_137 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct V_11 * V_12 ;
struct {
T_3 V_62 ;
T_59 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
int V_22 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_12 = F_32 ( V_42 -> V_12 , V_280 ) ;
V_22 = F_85 ( V_12 , V_102 -> V_101 . V_244 ) ;
F_31 ( & V_12 ) ;
if ( V_22 )
return V_22 ;
return F_138 ( V_2 -> V_45 , V_42 -> V_12 ,
V_102 -> V_101 . V_244 , V_102 -> V_101 . type ,
& V_2 -> V_218 ) ;
}
static int F_139 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 = V_2 -> V_43 ;
struct {
T_3 V_62 ;
T_60 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
int V_22 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
V_22 = F_112 ( V_2 -> V_45 , V_102 -> V_101 . V_244 , 0 ,
& V_2 -> V_218 ) ;
if ( V_22 )
F_14 ( L_41 ) ;
return V_22 ;
}
static int F_140 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct V_4 * V_42 ;
struct V_4 * V_124 ;
struct V_11 * V_12 ;
struct {
T_3 V_62 ;
T_61 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
int V_22 ;
if ( V_102 -> V_101 . V_105 != V_93 ) {
V_22 = F_56 ( V_20 , V_2 , V_34 ,
V_122 ,
& V_102 -> V_101 . V_105 , & V_42 ) ;
if ( V_22 )
return V_22 ;
} else {
V_42 = V_2 -> V_43 ;
if ( ! V_42 ) {
F_14 ( L_6 ) ;
return - V_44 ;
}
}
V_12 = F_114 ( F_110 ( V_42 -> V_12 ) ,
V_102 -> V_101 . V_217 , 0 ) ;
if ( F_13 ( V_12 ) ) {
F_14 ( L_42 ) ;
return F_15 ( V_12 ) ;
}
V_22 = F_16 ( V_2 , V_12 , & V_124 ) ;
if ( V_22 ) {
F_14 ( L_43 ) ;
goto V_245;
}
V_22 = F_99 ( V_20 , V_2 , V_124 ,
& V_102 -> V_101 . V_106 ,
V_102 -> V_101 . V_230 ) ;
V_245:
F_31 ( & V_12 ) ;
return V_22 ;
}
static int F_141 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_3 * V_62 )
{
struct {
T_3 V_62 ;
T_62 V_101 ;
} * V_102 = F_19 ( V_62 , F_71 ( * V_102 ) , V_62 ) ;
return F_29 ( V_2 , V_242 ,
V_102 -> V_101 . V_281 ) ;
}
static int F_142 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
void * V_208 , T_2 * V_104 )
{
T_2 V_282 = * V_104 ;
T_2 V_283 ;
V_283 = ( ( T_2 * ) V_208 ) [ 0 ] ;
switch ( V_283 ) {
case V_284 :
* V_104 = sizeof( T_2 ) + sizeof( V_285 ) ;
break;
case V_286 :
* V_104 = sizeof( T_2 ) + sizeof( T_30 ) ;
break;
case V_287 :
* V_104 = sizeof( T_2 ) + sizeof( V_288 ) ;
break;
case V_289 :
* V_104 = sizeof( T_2 ) + sizeof( V_288 ) ;
break;
default:
F_14 ( L_44 , V_283 ) ;
return - V_44 ;
}
if ( * V_104 > V_282 ) {
F_14 ( L_45
L_46 , V_283 ) ;
return - V_44 ;
}
if ( F_4 ( ! V_2 -> V_290 ) ) {
F_14 ( L_47 , V_283 ) ;
return - V_291 ;
}
if ( V_283 == V_286 )
return F_98 ( V_20 , V_2 , V_208 ) ;
return 0 ;
}
static int F_143 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
void * V_208 , T_2 * V_104 )
{
T_2 V_283 ;
T_2 V_282 = * V_104 ;
T_3 * V_62 = ( T_3 * ) V_208 ;
int V_22 ;
const struct V_292 * V_49 ;
bool V_293 = V_20 -> V_294 & V_295 ;
V_283 = ( ( T_2 * ) V_208 ) [ 0 ] ;
if ( F_4 ( V_283 < V_296 ) )
return F_142 ( V_20 , V_2 , V_208 , V_104 ) ;
V_283 = V_62 -> V_41 ;
* V_104 = V_62 -> V_104 + sizeof( T_3 ) ;
V_283 -= V_297 ;
if ( F_4 ( * V_104 > V_282 ) )
goto V_298;
if ( F_4 ( V_283 >= V_299 - V_297 ) )
goto V_298;
V_49 = & V_300 [ V_283 ] ;
if ( F_4 ( ! V_49 -> V_301 ) )
goto V_298;
if ( F_4 ( ! V_49 -> V_302 && ! V_2 -> V_290 ) )
goto V_303;
if ( F_4 ( V_49 -> V_304 && V_293 ) )
goto V_305;
if ( F_4 ( V_49 -> V_306 && ! V_293 ) )
goto V_307;
V_22 = V_49 -> V_301 ( V_20 , V_2 , V_62 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_298;
return 0 ;
V_298:
F_14 ( L_48 ,
V_283 + V_297 ) ;
return - V_44 ;
V_303:
F_14 ( L_49 ,
V_283 + V_297 ) ;
return - V_291 ;
V_305:
F_14 ( L_50 ,
V_283 + V_297 ) ;
return - V_44 ;
V_307:
F_14 ( L_51 ,
V_283 + V_297 ) ;
return - V_44 ;
}
static int F_144 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
void * V_208 ,
T_2 V_104 )
{
T_63 V_308 = V_104 ;
int V_22 ;
V_2 -> V_86 = V_208 ;
while ( V_308 > 0 ) {
V_104 = V_308 ;
V_22 = F_143 ( V_20 , V_2 , V_208 , & V_104 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_208 = ( void * ) ( ( unsigned long ) V_208 + V_104 ) ;
V_308 -= V_104 ;
}
if ( F_4 ( V_308 != 0 ) ) {
F_14 ( L_52 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
V_2 -> V_151 = 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
T_2 V_50 ;
struct V_149 * V_150 ;
struct V_70 * V_309 ;
struct V_310 * V_76 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_151 ; ++ V_50 ) {
V_150 = & V_2 -> V_153 [ V_50 ] ;
V_309 = & V_2 -> V_73 [ V_150 -> V_156 ] . V_72 ;
V_76 = V_309 -> V_76 ;
switch ( V_76 -> V_107 . V_311 ) {
case V_312 :
V_150 -> V_155 -> V_56 += V_76 -> V_56 ;
V_150 -> V_155 -> V_158 = V_313 ;
break;
case V_314 :
V_150 -> V_155 -> V_158 = V_76 -> V_107 . V_108 ;
break;
case V_315 :
* V_150 -> V_154 = V_76 -> V_107 . V_108 ;
break;
default:
F_147 () ;
}
}
F_145 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_4 * V_5 , * V_316 ;
F_42 (val, val_next, list, head) {
F_149 ( & V_5 -> V_33 ) ;
F_31 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_15 ) {
if ( V_5 -> V_15 != V_2 -> V_15 )
F_7 ( V_5 -> V_15 ) ;
else
V_2 -> V_16 = false ;
V_5 -> V_15 = NULL ;
}
F_22 ( V_5 ) ;
}
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_68 * V_49 , * V_317 ;
struct V_4 * V_5 ;
F_42 (entry, next, &sw_context->validate_nodes,
base.head) {
F_43 ( & V_49 -> V_72 . V_33 ) ;
F_151 ( & V_49 -> V_72 . V_76 ) ;
( void ) F_152 ( & V_2 -> V_27 , & V_49 -> V_26 ) ;
V_2 -> V_74 -- ;
}
F_59 ( V_2 -> V_74 != 0 ) ;
F_3 (val, &sw_context->resource_list, head)
( void ) F_152 ( & V_2 -> V_27 , & V_5 -> V_26 ) ;
}
int F_153 ( struct V_19 * V_20 ,
struct V_310 * V_76 ,
bool V_318 ,
bool V_65 )
{
struct V_55 * V_64 = F_19 ( V_76 , struct V_55 ,
V_72 ) ;
int V_22 ;
if ( V_64 -> V_319 > 0 )
return 0 ;
if ( V_65 )
return F_154 ( V_76 , & V_320 , V_318 ,
false ) ;
V_22 = F_154 ( V_76 , & V_321 , V_318 ,
false ) ;
if ( F_17 ( V_22 == 0 || V_22 == - V_82 ) )
return V_22 ;
V_22 = F_154 ( V_76 , & V_322 , V_318 , false ) ;
return V_22 ;
}
static int F_155 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_68 * V_49 ;
int V_22 ;
F_3 (entry, &sw_context->validate_nodes, base.head) {
V_22 = F_153 ( V_20 , V_49 -> V_72 . V_76 ,
true ,
V_49 -> V_65 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
}
return 0 ;
}
static int F_156 ( struct V_1 * V_2 ,
T_2 V_104 )
{
if ( F_17 ( V_2 -> V_323 >= V_104 ) )
return 0 ;
if ( V_2 -> V_323 == 0 )
V_2 -> V_323 = V_324 ;
while ( V_2 -> V_323 < V_104 ) {
V_2 -> V_323 =
F_157 ( V_2 -> V_323 +
( V_2 -> V_323 >> 1 ) ) ;
}
F_158 ( V_2 -> V_325 ) ;
V_2 -> V_325 = F_159 ( V_2 -> V_323 ) ;
if ( V_2 -> V_325 == NULL ) {
F_14 ( L_53 ) ;
V_2 -> V_323 = 0 ;
return - V_30 ;
}
return 0 ;
}
int F_160 ( struct V_326 * V_327 ,
struct V_19 * V_20 ,
struct V_328 * * V_329 ,
T_2 * V_330 )
{
T_2 V_331 ;
int V_22 ;
bool V_332 = false ;
F_59 ( V_330 != NULL && V_327 == NULL ) ;
V_22 = F_161 ( V_20 , & V_331 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_54 ) ;
V_332 = true ;
}
if ( V_330 != NULL )
V_22 = F_162 ( V_327 , V_20 -> V_333 ,
V_331 , V_329 , V_330 ) ;
else
V_22 = F_163 ( V_20 -> V_333 , V_331 , V_329 ) ;
if ( F_4 ( V_22 != 0 && ! V_332 ) ) {
( void ) F_164 ( V_20 , false , false ,
V_331 , false ,
V_334 ) ;
* V_329 = NULL ;
}
return 0 ;
}
void
F_165 ( struct V_19 * V_20 ,
struct V_335 * V_336 ,
int V_22 ,
struct V_337 T_64 * V_338 ,
struct V_328 * V_339 ,
T_2 V_340 )
{
struct V_337 V_341 ;
if ( V_338 == NULL )
return;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . error = V_22 ;
if ( V_22 == 0 ) {
F_59 ( V_339 == NULL ) ;
V_341 . V_95 = V_340 ;
V_341 . V_342 = V_339 -> V_72 . V_342 ;
F_166 ( V_20 , & V_20 -> V_343 ) ;
V_341 . V_344 = V_20 -> V_345 ;
}
V_22 = F_167 ( V_338 , & V_341 ,
sizeof( V_341 ) ) ;
if ( F_4 ( V_22 != 0 ) && ( V_341 . error == 0 ) ) {
F_168 ( V_336 -> V_97 ,
V_340 , V_346 ) ;
F_14 ( L_55 ) ;
( void ) F_169 ( V_339 , false , false ,
V_334 ) ;
}
}
static int F_170 ( struct V_19 * V_20 ,
void * V_347 ,
T_1 V_348 ,
struct V_1 * V_2 )
{
void * V_102 ;
if ( V_2 -> V_43 )
V_102 = F_61 ( V_20 , V_348 ,
V_2 -> V_43 -> V_12 -> V_41 ) ;
else
V_102 = F_171 ( V_20 , V_348 ) ;
if ( ! V_102 ) {
F_14 ( L_56 ) ;
return - V_30 ;
}
F_146 ( V_2 ) ;
memcpy ( V_102 , V_347 , V_348 ) ;
F_44 ( V_102 , & V_2 -> V_85 ) ;
F_41 ( & V_2 -> V_85 ) ;
F_62 ( V_20 , V_348 ) ;
return 0 ;
}
static int F_172 ( struct V_19 * V_20 ,
struct V_349 * V_62 ,
T_1 V_348 ,
struct V_1 * V_2 )
{
T_1 V_41 = ( ( V_2 -> V_43 ) ? V_2 -> V_43 -> V_12 -> V_41 :
V_93 ) ;
void * V_102 = F_173 ( V_20 -> V_350 , V_348 ,
V_41 , false , V_62 ) ;
F_146 ( V_2 ) ;
F_44 ( V_102 , & V_2 -> V_85 ) ;
F_41 ( & V_2 -> V_85 ) ;
F_174 ( V_20 -> V_350 , V_348 , V_62 , false ) ;
return 0 ;
}
static void * F_175 ( struct V_19 * V_20 ,
void T_64 * V_351 ,
void * V_347 ,
T_1 V_348 ,
struct V_349 * * V_62 )
{
T_39 V_352 ;
int V_22 ;
* V_62 = NULL ;
if ( ! V_20 -> V_350 || V_347 )
return V_347 ;
if ( V_348 > V_353 ) {
F_14 ( L_57 ) ;
return F_176 ( - V_44 ) ;
}
V_352 = V_348 + 512 ;
V_352 = F_177 ( T_39 , V_352 , V_353 ) ;
V_347 = F_178 ( V_20 -> V_350 , V_352 ,
true , V_62 ) ;
if ( F_13 ( V_347 ) )
return V_347 ;
V_22 = F_179 ( V_347 , V_351 ,
V_348 ) ;
if ( V_22 ) {
F_14 ( L_58 ) ;
F_180 ( * V_62 ) ;
* V_62 = NULL ;
return F_176 ( - V_354 ) ;
}
return V_347 ;
}
static int F_181 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
T_2 V_95 )
{
struct V_4 * V_42 ;
struct V_11 * V_12 ;
int V_22 ;
if ( V_95 == V_93 )
return 0 ;
V_22 = F_57 ( V_20 , V_2 -> V_96 -> V_97 ,
V_95 , V_122 ,
& V_12 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_14 ( L_59 ,
( unsigned ) V_95 ) ;
return V_22 ;
}
V_22 = F_16 ( V_2 , V_12 , & V_42 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_23;
V_2 -> V_43 = V_42 ;
V_2 -> V_45 = F_110 ( V_12 ) ;
V_23:
F_31 ( & V_12 ) ;
return V_22 ;
}
int F_182 ( struct V_326 * V_327 ,
struct V_19 * V_20 ,
void T_64 * V_351 ,
void * V_347 ,
T_2 V_348 ,
T_65 V_355 ,
T_2 V_356 ,
struct V_337 T_64 * V_338 ,
struct V_328 * * V_357 )
{
struct V_1 * V_2 = & V_20 -> V_46 ;
struct V_328 * V_339 = NULL ;
struct V_11 * V_99 ;
struct V_6 V_8 ;
struct V_349 * V_62 ;
struct V_358 V_359 ;
T_2 V_95 ;
int V_22 ;
if ( V_355 ) {
V_22 = F_183 ( V_20 , & V_20 -> V_343 . V_360 ,
V_355 ) ;
if ( V_22 )
return V_22 ;
}
V_347 = F_175 ( V_20 , V_351 ,
V_347 , V_348 ,
& V_62 ) ;
if ( F_13 ( V_347 ) )
return F_15 ( V_347 ) ;
V_22 = F_184 ( & V_20 -> V_361 ) ;
if ( V_22 ) {
V_22 = - V_82 ;
goto V_362;
}
V_2 -> V_290 = false ;
if ( V_347 == NULL ) {
V_22 = F_156 ( V_2 , V_348 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_363;
V_22 = F_179 ( V_2 -> V_325 ,
V_351 , V_348 ) ;
if ( F_4 ( V_22 != 0 ) ) {
V_22 = - V_354 ;
F_14 ( L_58 ) ;
goto V_363;
}
V_347 = V_2 -> V_325 ;
} else if ( ! V_62 )
V_2 -> V_290 = true ;
V_2 -> V_96 = V_335 ( V_327 ) ;
V_2 -> V_151 = 0 ;
V_2 -> V_74 = 0 ;
F_185 ( & V_2 -> V_8 ) ;
F_185 ( & V_2 -> V_36 ) ;
V_2 -> V_139 = V_20 -> V_143 ;
V_2 -> V_138 = NULL ;
V_2 -> V_141 = false ;
V_2 -> V_43 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = NULL ;
memset ( V_2 -> V_92 , 0 , sizeof( V_2 -> V_92 ) ) ;
F_185 ( & V_2 -> V_78 ) ;
F_185 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_15 )
F_186 ( V_2 -> V_15 ) ;
if ( ! V_2 -> V_364 ) {
V_22 = F_187 ( & V_2 -> V_27 , V_365 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_363;
V_2 -> V_364 = true ;
}
F_185 ( & V_2 -> V_218 ) ;
F_185 ( & V_8 ) ;
V_22 = F_181 ( V_20 , V_2 , V_356 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_188 ( & V_2 -> V_36 ,
& V_2 -> V_8 ) ;
goto V_366;
}
V_22 = F_144 ( V_20 , V_2 , V_347 ,
V_348 ) ;
F_188 ( & V_2 -> V_36 ,
& V_2 -> V_8 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_366;
V_22 = F_49 ( V_2 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_366;
V_22 = F_189 ( & V_359 , & V_2 -> V_78 ,
true , NULL ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_366;
V_22 = F_155 ( V_20 , V_2 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_23;
V_22 = F_52 ( V_2 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_23;
V_22 = F_184 ( & V_20 -> V_53 ) ;
if ( F_4 ( V_22 != 0 ) ) {
V_22 = - V_82 ;
goto V_23;
}
if ( V_20 -> V_32 ) {
V_22 = F_63 ( V_2 ) ;
if ( F_4 ( V_22 != 0 ) )
goto V_367;
}
if ( ! V_62 ) {
V_22 = F_170 ( V_20 , V_347 ,
V_348 , V_2 ) ;
} else {
V_22 = F_172 ( V_20 , V_62 , V_348 ,
V_2 ) ;
V_62 = NULL ;
}
F_38 ( & V_20 -> V_53 ) ;
if ( V_22 )
goto V_23;
F_77 ( V_20 , V_2 ) ;
V_22 = F_160 ( V_327 , V_20 ,
& V_339 ,
( V_338 ) ? & V_95 : NULL ) ;
if ( V_22 != 0 )
F_14 ( L_54 ) ;
F_1 ( V_2 , false ) ;
F_190 ( & V_359 , & V_2 -> V_78 ,
( void * ) V_339 ) ;
if ( F_4 ( V_20 -> V_143 != NULL &&
! V_20 -> V_146 ) )
F_191 ( V_20 , V_339 ) ;
F_150 ( V_2 ) ;
F_165 ( V_20 , V_335 ( V_327 ) , V_22 ,
V_338 , V_339 , V_95 ) ;
if ( F_4 ( V_357 != NULL ) ) {
* V_357 = V_339 ;
V_339 = NULL ;
} else if ( F_17 ( V_339 != NULL ) ) {
F_192 ( & V_339 ) ;
}
F_188 ( & V_2 -> V_8 , & V_8 ) ;
F_193 ( & V_2 -> V_218 ) ;
F_38 ( & V_20 -> V_361 ) ;
F_148 ( V_2 , & V_8 ) ;
return 0 ;
V_367:
F_38 ( & V_20 -> V_53 ) ;
V_23:
F_194 ( & V_359 , & V_2 -> V_78 ) ;
V_366:
F_1 ( V_2 , true ) ;
F_41 ( & V_2 -> V_85 ) ;
F_145 ( V_2 ) ;
F_150 ( V_2 ) ;
if ( F_4 ( V_20 -> V_143 != NULL &&
! V_20 -> V_146 ) )
F_191 ( V_20 , NULL ) ;
V_363:
F_188 ( & V_2 -> V_8 , & V_8 ) ;
V_99 = V_2 -> V_99 ;
V_2 -> V_99 = NULL ;
F_195 ( & V_2 -> V_218 ) ;
F_38 ( & V_20 -> V_361 ) ;
F_148 ( V_2 , & V_8 ) ;
if ( F_4 ( V_99 != NULL ) )
F_31 ( & V_99 ) ;
V_362:
if ( V_62 )
F_180 ( V_62 ) ;
return V_22 ;
}
static void F_196 ( struct V_19 * V_20 )
{
F_14 ( L_60 ) ;
( void ) F_164 ( V_20 , false , true , 0 , false , 10 * V_368 ) ;
F_79 ( V_20 -> V_143 , false ) ;
if ( V_20 -> V_144 ) {
F_79 ( V_20 -> V_142 , false ) ;
V_20 -> V_144 = false ;
}
}
void F_191 ( struct V_19 * V_20 ,
struct V_328 * V_339 )
{
int V_22 = 0 ;
struct V_6 V_369 ;
struct V_70 V_370 , V_371 ;
struct V_328 * V_372 = NULL ;
struct V_358 V_359 ;
if ( V_20 -> V_143 == NULL )
goto V_363;
F_185 ( & V_369 ) ;
V_370 . V_76 = F_48 ( & V_20 -> V_143 -> V_72 ) ;
V_370 . V_77 = false ;
F_24 ( & V_370 . V_33 , & V_369 ) ;
V_371 . V_76 = F_48 ( & V_20 -> V_142 -> V_72 ) ;
V_371 . V_77 = false ;
F_24 ( & V_371 . V_33 , & V_369 ) ;
V_22 = F_189 ( & V_359 , & V_369 ,
false , NULL ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_196 ( V_20 ) ;
goto V_373;
}
if ( V_20 -> V_146 ) {
F_59 ( V_339 != NULL ) ;
V_22 = F_78 ( V_20 , V_20 -> V_145 ) ;
if ( F_4 ( V_22 != 0 ) ) {
F_196 ( V_20 ) ;
goto V_374;
}
V_20 -> V_146 = false ;
}
F_79 ( V_20 -> V_143 , false ) ;
if ( V_20 -> V_144 ) {
F_79 ( V_20 -> V_142 , false ) ;
V_20 -> V_144 = false ;
}
if ( V_339 == NULL ) {
( void ) F_160 ( NULL , V_20 , & V_372 ,
NULL ) ;
V_339 = V_372 ;
}
F_190 ( & V_359 , & V_369 , ( void * ) V_339 ) ;
if ( V_372 != NULL )
F_192 ( & V_372 ) ;
F_151 ( & V_371 . V_76 ) ;
F_151 ( & V_370 . V_76 ) ;
F_9 ( & V_20 -> V_143 ) ;
F_197 ( L_61 ,
V_20 -> V_142 -> V_319 ) ;
V_363:
return;
V_374:
F_194 ( & V_359 , & V_369 ) ;
V_373:
F_151 ( & V_371 . V_76 ) ;
F_151 ( & V_370 . V_76 ) ;
F_9 ( & V_20 -> V_143 ) ;
}
void F_198 ( struct V_19 * V_20 )
{
F_33 ( & V_20 -> V_361 ) ;
if ( V_20 -> V_146 )
F_191 ( V_20 , NULL ) ;
F_38 ( & V_20 -> V_361 ) ;
}
int F_199 ( struct V_375 * V_376 , unsigned long V_377 ,
struct V_326 * V_327 , T_39 V_104 )
{
struct V_19 * V_20 = F_200 ( V_376 ) ;
struct V_378 V_379 ;
int V_22 ;
static const T_39 V_380 [] = {
F_133 ( struct V_378 , V_381 ) ,
sizeof(struct V_378 ) } ;
if ( F_4 ( V_104 < V_380 [ 0 ] ) ) {
F_14 ( L_62 ,
V_382 ) ;
return - V_44 ;
}
if ( F_179 ( & V_379 , ( void T_64 * ) V_377 , V_380 [ 0 ] ) != 0 )
return - V_354 ;
if ( F_4 ( V_379 . V_383 > V_384 ||
V_379 . V_383 == 0 ) ) {
F_14 ( L_63 ) ;
return - V_44 ;
}
if ( V_379 . V_383 > 1 &&
F_179 ( & V_379 . V_381 ,
( void T_64 * ) ( V_377 + V_380 [ 0 ] ) ,
V_380 [ V_379 . V_383 - 1 ] -
V_380 [ 0 ] ) != 0 )
return - V_354 ;
switch ( V_379 . V_383 ) {
case 1 :
V_379 . V_381 = ( T_2 ) - 1 ;
break;
case 2 :
if ( V_379 . V_385 != 0 ) {
F_14 ( L_64 ) ;
return - V_44 ;
}
break;
default:
break;
}
V_22 = F_201 ( & V_20 -> V_386 , true ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
V_22 = F_182 ( V_327 , V_20 ,
( void T_64 * ) ( unsigned long ) V_379 . V_387 ,
NULL , V_379 . V_348 , V_379 . V_355 ,
V_379 . V_381 ,
( void T_64 * ) ( unsigned long ) V_379 . V_341 ,
NULL ) ;
F_202 ( & V_20 -> V_386 ) ;
if ( F_4 ( V_22 != 0 ) )
return V_22 ;
F_203 ( V_20 ) ;
return 0 ;
}
