static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 ;
F_2 (val, list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 =
V_3 ? NULL : V_5 -> V_9 ;
if ( F_3 ( V_5 -> V_10 ) ) {
if ( ! V_3 ) {
F_4
( V_5 -> V_7 , V_5 -> V_10 ) ;
}
F_5 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
}
F_6 ( V_7 , V_9 ,
V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_9 ) ;
}
}
static int F_8 ( struct V_12 * V_13 ,
struct V_6 * V_7 ,
struct V_4 * * V_14 )
{
struct V_4 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
if ( F_9 ( F_10 ( & V_13 -> V_19 , ( unsigned long ) V_7 ,
& V_17 ) == 0 ) ) {
V_15 = F_11 ( V_17 , struct V_4 , V_17 ) ;
V_15 -> V_20 = false ;
if ( F_3 ( V_14 != NULL ) )
* V_14 = V_15 ;
return 0 ;
}
V_15 = F_12 ( sizeof( * V_15 ) , V_21 ) ;
if ( F_3 ( V_15 == NULL ) ) {
F_13 ( L_1
L_2 ) ;
return - V_22 ;
}
V_15 -> V_17 . V_23 = ( unsigned long ) V_7 ;
V_18 = F_14 ( & V_13 -> V_19 , & V_15 -> V_17 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_3
L_2 ) ;
F_5 ( V_15 ) ;
return V_18 ;
}
F_15 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_15 -> V_7 = F_16 ( V_7 ) ;
V_15 -> V_20 = true ;
if ( F_3 ( V_14 != NULL ) )
* V_14 = V_15 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
struct V_6 * V_28 )
{
struct V_1 * V_29 ;
struct V_30 * V_31 ;
int V_18 = 0 ;
struct V_6 * V_7 ;
F_18 ( & V_27 -> V_32 ) ;
V_29 = F_19 ( V_28 ) ;
F_2 (entry, binding_list, ctx_list) {
V_7 = F_20 ( V_31 -> V_33 . V_7 ) ;
if ( F_3 ( V_7 == NULL ) )
continue;
V_18 = F_8 ( V_13 , V_31 -> V_33 . V_7 , NULL ) ;
F_21 ( & V_7 ) ;
if ( F_3 ( V_18 != 0 ) )
break;
}
F_22 ( & V_27 -> V_32 ) ;
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
unsigned long V_34 )
{
struct V_35 * V_36 ;
V_36 = F_24 ( sizeof( * V_36 ) , V_21 ) ;
if ( F_3 ( V_36 == NULL ) ) {
F_13 ( L_4 ) ;
return - V_22 ;
}
V_36 -> V_7 = V_7 ;
V_36 -> V_34 = V_34 ;
F_15 ( & V_36 -> V_24 , V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_35 * V_36 , * V_37 ;
F_26 (rel, n, list, head) {
F_27 ( & V_36 -> V_24 ) ;
F_5 ( V_36 ) ;
}
}
static void F_28 ( T_1 * V_38 ,
struct V_1 * V_2 )
{
struct V_35 * V_36 ;
F_2 (rel, list, head) {
if ( F_9 ( V_36 -> V_7 != NULL ) )
V_38 [ V_36 -> V_34 ] = V_36 -> V_7 -> V_39 ;
else
V_38 [ V_36 -> V_34 ] = V_40 ;
}
}
static int F_29 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
return F_30 ( V_42 ) ? : - V_43 ;
}
static int F_31 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
return 0 ;
}
static int F_32 ( struct V_12 * V_13 ,
struct V_44 * V_45 ,
bool V_46 ,
T_1 * V_47 )
{
T_1 V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_16 * V_17 ;
int V_18 ;
if ( F_9 ( F_10 ( & V_13 -> V_19 , ( unsigned long ) V_45 ,
& V_17 ) == 0 ) ) {
V_50 = F_11 ( V_17 , struct V_49 ,
V_17 ) ;
if ( F_3 ( V_50 -> V_46 != V_46 ) ) {
F_13 ( L_5 ) ;
return - V_43 ;
}
V_52 = & V_50 -> V_53 ;
V_48 = V_50 - V_13 -> V_54 ;
} else {
V_48 = V_13 -> V_55 ;
if ( F_3 ( V_48 >= V_56 ) ) {
F_13 ( L_6
L_7 ) ;
return - V_43 ;
}
V_50 = & V_13 -> V_54 [ V_48 ] ;
V_50 -> V_17 . V_23 = ( unsigned long ) V_45 ;
V_18 = F_14 ( & V_13 -> V_19 , & V_50 -> V_17 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_8
L_2 ) ;
return V_18 ;
}
++ V_13 -> V_55 ;
V_52 = & V_50 -> V_53 ;
V_52 -> V_45 = F_33 ( V_45 ) ;
V_52 -> V_57 = false ;
F_15 ( & V_52 -> V_24 , & V_13 -> V_58 ) ;
V_50 -> V_46 = V_46 ;
}
V_13 -> V_59 |= V_60 ;
if ( V_47 )
* V_47 = V_48 ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
int V_18 ;
F_2 (val, &sw_context->resource_list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
V_18 = F_35 ( V_7 , V_5 -> V_61 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_7 -> V_62 ) {
struct V_44 * V_45 = & V_7 -> V_62 -> V_53 ;
V_18 = F_32
( V_13 , V_45 ,
F_36 ( V_7 ) , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
}
return 0 ;
}
static int F_37 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
int V_18 ;
F_2 (val, &sw_context->resource_list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
V_18 = F_38 ( V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( V_18 != - V_63 )
F_13 ( L_9 ) ;
return V_18 ;
}
}
return 0 ;
}
static int
F_39 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
const struct V_66 * V_67 ,
T_1 V_39 ,
T_1 * V_68 ,
struct V_4 * * V_69 )
{
struct V_70 * V_71 =
& V_13 -> V_72 [ V_65 ] ;
struct V_6 * V_7 ;
struct V_4 * V_15 ;
int V_18 ;
if ( V_39 == V_73 ) {
if ( V_69 )
* V_69 = NULL ;
if ( V_65 == V_74 ) {
F_13 ( L_10 ) ;
return - V_43 ;
}
return 0 ;
}
if ( F_9 ( V_71 -> V_75 && V_39 == V_71 -> V_76 ) ) {
const struct V_6 * V_7 = V_71 -> V_7 ;
V_71 -> V_15 -> V_20 = false ;
if ( V_69 )
* V_69 = V_71 -> V_15 ;
return F_23
( & V_13 -> V_77 , V_7 ,
V_68 - V_13 -> V_78 ) ;
}
V_18 = F_40 ( V_27 ,
V_13 -> V_79 -> V_80 ,
V_39 ,
V_67 ,
& V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_11 ,
( unsigned ) V_39 ) ;
F_41 () ;
return V_18 ;
}
V_71 -> V_75 = true ;
V_71 -> V_7 = V_7 ;
V_71 -> V_76 = V_39 ;
V_18 = F_23 ( & V_13 -> V_77 ,
V_7 ,
V_68 - V_13 -> V_78 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_81;
V_18 = F_8 ( V_13 , V_7 , & V_15 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_81;
V_71 -> V_15 = V_15 ;
if ( V_69 )
* V_69 = V_15 ;
if ( V_27 -> V_82 && V_15 -> V_20 &&
V_65 == V_74 ) {
V_18 = F_17 ( V_27 , V_13 , V_7 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_81;
V_15 -> V_10 =
F_12 ( sizeof( * V_15 -> V_10 ) , V_21 ) ;
if ( V_15 -> V_10 == NULL ) {
F_13 ( L_12
L_13 ) ;
goto V_81;
}
F_42 ( & V_15 -> V_10 -> V_2 ) ;
}
F_21 ( & V_7 ) ;
return 0 ;
V_81:
F_43 ( V_13 -> V_83 != NULL ) ;
V_13 -> V_83 = V_7 ;
return V_18 ;
}
static int
F_44 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
const struct V_66 * V_67 ,
T_1 * V_68 ,
struct V_4 * * V_69 )
{
return F_39 ( V_27 , V_13 , V_65 ,
V_67 , * V_68 , V_68 , V_69 ) ;
}
static int F_45 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
int V_18 ;
F_2 (val, &sw_context->resource_list, head) {
if ( F_9 ( ! V_5 -> V_10 ) )
continue;
V_18 = F_46 ( V_5 -> V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( V_18 != - V_63 )
F_13 ( L_14 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_47 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_84 {
T_2 V_41 ;
T_1 V_85 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_84 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_85 , NULL ) ;
}
static int F_48 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_3 V_89 ;
} * V_86 ;
struct V_4 * V_90 ;
struct V_4 * V_91 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_94 . V_95 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_82 ) {
struct V_96 V_33 ;
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_98 ;
V_33 . V_99 . V_100 = V_86 -> V_89 . type ;
return F_49 ( V_90 -> V_10 , & V_33 ) ;
}
return 0 ;
}
static int F_50 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_4 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_101 . V_95 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_102 . V_95 , NULL ) ;
}
static int F_51 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_5 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_101 . V_95 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_102 . V_95 , NULL ) ;
}
static int F_52 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_6 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_103 . V_95 , NULL ) ;
}
static int F_53 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_7 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 , & V_86 -> V_89 . V_95 ,
NULL ) ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_44 * V_104 ,
struct V_12 * V_13 )
{
struct V_70 * V_105 =
& V_13 -> V_72 [ V_74 ] ;
int V_18 ;
F_43 ( ! V_105 -> V_75 ) ;
V_13 -> V_106 = V_105 -> V_7 ;
if ( F_3 ( V_104 != V_13 -> V_107 ) ) {
if ( F_3 ( V_104 -> V_108 > 4 ) ) {
F_13 ( L_15 ) ;
return - V_43 ;
}
if ( F_3 ( V_13 -> V_107 != NULL ) ) {
V_13 -> V_109 = true ;
V_18 = F_32 ( V_13 ,
V_13 -> V_107 ,
V_27 -> V_82 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_13 -> V_107 = V_104 ;
V_18 = F_32 ( V_13 ,
V_27 -> V_110 ,
V_27 -> V_82 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static void F_55 ( struct V_26 * V_27 ,
struct V_12 * V_13 )
{
if ( V_13 -> V_109 ) {
struct V_70 * V_105 =
& V_13 -> V_72 [ V_74 ] ;
struct V_6 * V_28 ;
int V_18 ;
F_43 ( ! V_105 -> V_75 ) ;
V_28 = V_105 -> V_7 ;
V_18 = F_56 ( V_27 , V_28 -> V_39 ) ;
if ( F_3 ( V_18 != 0 ) )
F_13 ( L_16 ) ;
}
if ( V_27 -> V_111 != V_13 -> V_107 ) {
if ( V_27 -> V_111 ) {
F_57 ( V_27 -> V_111 , false ) ;
F_58 ( & V_27 -> V_111 ) ;
}
if ( ! V_13 -> V_109 ) {
F_57 ( V_13 -> V_107 , true ) ;
F_57 ( V_27 -> V_110 , true ) ;
V_27 -> V_112 = true ;
F_43 ( V_13 -> V_106 == NULL ) ;
V_27 -> V_113 = V_13 -> V_106 -> V_39 ;
V_27 -> V_114 = true ;
V_27 -> V_111 =
F_33 ( V_13 -> V_107 ) ;
}
}
}
static int F_59 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_8 * V_39 ,
struct V_8 * * V_115 )
{
struct V_8 * V_116 = NULL ;
struct V_44 * V_45 ;
T_1 V_76 = * V_39 ;
struct V_117 * V_118 ;
int V_18 ;
V_18 = F_60 ( V_13 -> V_79 -> V_80 , V_76 , & V_116 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_17 ) ;
return - V_43 ;
}
V_45 = & V_116 -> V_53 ;
if ( F_3 ( V_13 -> V_119 >= V_120 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_81;
}
V_118 = & V_13 -> V_121 [ V_13 -> V_119 ++ ] ;
V_118 -> V_122 = V_39 ;
V_118 -> V_123 = NULL ;
V_18 = F_32 ( V_13 , V_45 , true , & V_118 -> V_124 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_81;
* V_115 = V_116 ;
return 0 ;
V_81:
F_7 ( & V_116 ) ;
V_115 = NULL ;
return V_18 ;
}
static int F_61 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_9 * V_125 ,
struct V_8 * * V_115 )
{
struct V_8 * V_116 = NULL ;
struct V_44 * V_45 ;
T_1 V_76 = V_125 -> V_126 ;
struct V_117 * V_118 ;
int V_18 ;
V_18 = F_60 ( V_13 -> V_79 -> V_80 , V_76 , & V_116 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_20 ) ;
return - V_43 ;
}
V_45 = & V_116 -> V_53 ;
if ( F_3 ( V_13 -> V_119 >= V_120 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_81;
}
V_118 = & V_13 -> V_121 [ V_13 -> V_119 ++ ] ;
V_118 -> V_123 = V_125 ;
V_18 = F_32 ( V_13 , V_45 , false , & V_118 -> V_124 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_81;
* V_115 = V_116 ;
return 0 ;
V_81:
F_7 ( & V_116 ) ;
V_115 = NULL ;
return V_18 ;
}
static int F_62 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_127 {
T_2 V_41 ;
T_10 V_128 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_127 ,
V_41 ) ;
return F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_128 . V_85 ,
NULL ) ;
}
static int F_63 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_129 {
T_2 V_41 ;
T_11 V_128 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_129 ,
V_41 ) ;
if ( F_3 ( V_27 -> V_82 ) ) {
struct {
T_2 V_41 ;
T_10 V_128 ;
} V_130 ;
F_43 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_131 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_62 ( V_27 , V_13 , V_41 ) ;
}
return F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_128 . V_85 ,
NULL ) ;
}
static int F_64 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_116 ;
struct V_133 {
T_2 V_41 ;
T_12 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
V_18 = F_47 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_59 ( V_27 , V_13 ,
& V_86 -> V_128 . V_134 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_54 ( V_27 , & V_116 -> V_53 , V_13 ) ;
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_65 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_116 ;
struct V_133 {
T_2 V_41 ;
T_13 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
if ( V_27 -> V_82 ) {
struct {
T_2 V_41 ;
T_12 V_128 ;
} V_130 ;
F_43 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_135 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
V_130 . V_128 . V_134 = V_86 -> V_128 . V_136 . V_126 ;
V_130 . V_128 . V_34 = V_86 -> V_128 . V_136 . V_34 ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_64 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_47 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_61 ( V_27 , V_13 ,
& V_86 -> V_128 . V_136 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_54 ( V_27 , & V_116 -> V_53 , V_13 ) ;
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_66 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_116 ;
struct V_133 {
T_2 V_41 ;
T_14 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
V_18 = F_47 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_59 ( V_27 , V_13 ,
& V_86 -> V_128 . V_134 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_116 ) ;
return 0 ;
}
static int F_67 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_116 ;
struct V_133 {
T_2 V_41 ;
T_15 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
if ( V_27 -> V_82 ) {
struct {
T_2 V_41 ;
T_14 V_128 ;
} V_130 ;
F_43 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_137 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
V_130 . V_128 . V_134 = V_86 -> V_128 . V_136 . V_126 ;
V_130 . V_128 . V_34 = V_86 -> V_128 . V_136 . V_34 ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_66 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_47 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_61 ( V_27 , V_13 ,
& V_86 -> V_128 . V_136 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_116 ) ;
return 0 ;
}
static int F_68 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_116 = NULL ;
struct V_138 * V_139 = NULL ;
struct V_140 {
T_2 V_41 ;
T_16 V_141 ;
} * V_86 ;
int V_18 ;
T_17 * V_142 ;
T_1 V_143 ;
V_86 = F_11 ( V_41 , struct V_140 , V_41 ) ;
V_142 = ( T_17 * ) ( ( unsigned long ) & V_86 -> V_141 +
V_41 -> V_132 - sizeof( * V_142 ) ) ;
if ( F_3 ( V_142 -> V_144 != sizeof( * V_142 ) ) ) {
F_13 ( L_21 ) ;
return - V_43 ;
}
V_18 = F_61 ( V_27 , V_13 ,
& V_86 -> V_141 . V_145 . V_125 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_143 = V_116 -> V_53 . V_108 * V_146 ;
if ( F_3 ( V_86 -> V_141 . V_145 . V_125 . V_34 > V_143 ) ) {
F_13 ( L_22 ) ;
return - V_43 ;
}
V_143 -= V_86 -> V_141 . V_145 . V_125 . V_34 ;
if ( F_3 ( V_142 -> V_147 > V_143 ) )
V_142 -> V_147 = V_143 ;
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 , & V_86 -> V_141 . V_148 . V_95 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( F_3 ( V_18 != - V_63 ) )
F_13 ( L_23 ) ;
goto V_149;
}
V_139 = F_69 ( V_13 -> V_72 [ V_92 ] . V_7 ) ;
F_70 ( V_139 , V_13 -> V_79 -> V_80 , & V_116 -> V_53 ,
V_41 ) ;
V_149:
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_71 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_150 {
T_2 V_41 ;
T_18 V_89 ;
} * V_86 ;
T_19 * V_151 = ( T_19 * ) (
( unsigned long ) V_41 + sizeof( * V_86 ) ) ;
T_20 * V_152 ;
T_1 V_153 ;
T_1 V_154 ;
int V_18 ;
V_18 = F_47 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_86 = F_11 ( V_41 , struct V_150 , V_41 ) ;
V_154 = ( V_41 -> V_132 - sizeof( V_86 -> V_89 ) ) / sizeof( * V_151 ) ;
if ( F_3 ( V_86 -> V_89 . V_155 > V_154 ) ) {
F_13 ( L_24 ) ;
return - V_43 ;
}
for ( V_153 = 0 ; V_153 < V_86 -> V_89 . V_155 ; ++ V_153 , ++ V_151 ) {
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_151 -> V_156 . V_157 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_154 = ( V_41 -> V_132 - sizeof( V_86 -> V_89 ) -
V_86 -> V_89 . V_155 * sizeof( * V_151 ) ) / sizeof( * V_152 ) ;
if ( F_3 ( V_86 -> V_89 . V_158 > V_154 ) ) {
F_13 ( L_25 ) ;
return - V_43 ;
}
V_152 = ( T_20 * ) V_151 ;
for ( V_153 = 0 ; V_153 < V_86 -> V_89 . V_158 ; ++ V_153 , ++ V_152 ) {
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_152 -> V_159 . V_157 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static int F_72 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_160 {
T_2 V_41 ;
T_21 V_161 ;
} * V_86 ;
T_22 * V_162 = ( T_22 * )
( ( unsigned long ) V_41 + V_41 -> V_132 + sizeof( V_41 ) ) ;
T_22 * V_163 = ( T_22 * )
( ( unsigned long ) V_41 + sizeof( struct V_160 ) ) ;
struct V_4 * V_90 ;
struct V_4 * V_91 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_160 ,
V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_161 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
for (; V_163 < V_162 ; ++ V_163 ) {
if ( F_9 ( V_163 -> V_164 != V_165 ) )
continue;
V_18 = F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_163 -> V_166 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_82 ) {
struct V_96 V_33 ;
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_167 ;
V_33 . V_99 . V_168 = V_163 -> V_169 ;
F_49 ( V_90 -> V_10 ,
& V_33 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 )
{
struct V_8 * V_116 ;
int V_18 ;
struct {
T_1 V_41 ;
T_23 V_89 ;
} * V_86 = V_170 ;
V_18 = F_61 ( V_27 , V_13 ,
& V_86 -> V_89 . V_125 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_74 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
const struct V_66
* V_67 ,
T_1 * V_171 ,
T_1 * V_172 ,
unsigned long V_173 )
{
int V_18 ;
struct V_8 * V_174 ;
struct V_4 * V_48 ;
V_18 = F_44 ( V_27 , V_13 , V_65 ,
V_67 , V_171 , & V_48 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_59 ( V_27 , V_13 , V_172 , & V_174 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_48 -> V_20 )
V_48 -> V_61 = true ;
F_7 ( & V_48 -> V_9 ) ;
V_48 -> V_9 = V_174 ;
V_48 -> V_11 = V_173 ;
return 0 ;
}
static int F_75 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_175 {
T_2 V_41 ;
T_24 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_175 , V_41 ) ;
return F_74 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , & V_86 -> V_89 . V_134 ,
0 ) ;
}
static int F_76 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_25 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_77 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_26 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_78 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_27 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_79 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_28 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_80 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_29 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_81 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_30 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_44 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_82 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_178 {
T_2 V_41 ;
T_31 V_89 ;
} * V_86 ;
int V_18 ;
T_32 V_132 ;
V_86 = F_11 ( V_41 , struct V_178 ,
V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_89 . V_85 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_82 ) )
return 0 ;
V_132 = V_86 -> V_41 . V_132 - sizeof( V_86 -> V_89 ) ;
V_18 = F_83 ( V_13 -> V_79 -> V_179 ,
V_86 -> V_89 . V_180 , V_86 + 1 ,
V_86 -> V_89 . type , V_132 ,
V_13 -> V_79 -> V_80 ,
& V_13 -> V_181 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_77 ,
NULL , & V_86 -> V_41 . V_39 -
V_13 -> V_78 ) ;
return 0 ;
}
static int F_84 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_182 {
T_2 V_41 ;
T_33 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_182 ,
V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_89 . V_85 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_82 ) )
return 0 ;
V_18 = F_85 ( V_13 -> V_79 -> V_179 ,
V_86 -> V_89 . V_180 ,
V_86 -> V_89 . type ,
& V_13 -> V_181 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_77 ,
NULL , & V_86 -> V_41 . V_39 -
V_13 -> V_78 ) ;
return 0 ;
}
static int F_86 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_183 {
T_2 V_41 ;
T_34 V_89 ;
} * V_86 ;
struct V_4 * V_90 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_183 ,
V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_82 ) {
struct V_96 V_33 ;
struct V_4 * V_91 ;
T_35 V_180 = V_86 -> V_89 . V_180 ;
if ( V_180 != V_73 )
( void ) F_87 ( V_13 -> V_79 -> V_179 ,
V_86 -> V_89 . type ,
& V_180 ) ;
V_18 = F_39 ( V_27 , V_13 ,
V_184 ,
V_185 ,
V_180 ,
& V_86 -> V_89 . V_180 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_186 ;
V_33 . V_99 . V_187 = V_86 -> V_89 . type ;
return F_49 ( V_90 -> V_10 , & V_33 ) ;
}
return 0 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_188 {
T_2 V_41 ;
T_36 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_188 ,
V_41 ) ;
V_18 = F_44 ( V_27 , V_13 , V_74 ,
V_87 , & V_86 -> V_89 . V_85 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_82 )
V_41 -> V_39 = V_189 ;
return 0 ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_190 {
T_2 V_41 ;
T_37 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_190 ,
V_41 ) ;
return F_74 ( V_27 , V_13 , V_184 ,
V_185 ,
& V_86 -> V_89 . V_180 , & V_86 -> V_89 . V_134 ,
V_86 -> V_89 . V_191 ) ;
}
static int F_90 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 , T_1 * V_132 )
{
T_1 V_192 = * V_132 ;
T_1 V_193 ;
V_193 = F_91 ( ( ( T_1 * ) V_170 ) [ 0 ] ) ;
switch ( V_193 ) {
case V_194 :
* V_132 = sizeof( T_1 ) + sizeof( V_195 ) ;
break;
case V_196 :
* V_132 = sizeof( T_1 ) + sizeof( T_23 ) ;
break;
case V_197 :
* V_132 = sizeof( T_1 ) + sizeof( V_198 ) ;
break;
case V_199 :
* V_132 = sizeof( T_1 ) + sizeof( V_198 ) ;
break;
default:
F_13 ( L_26 , V_193 ) ;
return - V_43 ;
}
if ( * V_132 > V_192 ) {
F_13 ( L_27
L_28 , V_193 ) ;
return - V_43 ;
}
if ( F_3 ( ! V_13 -> V_200 ) ) {
F_13 ( L_29 , V_193 ) ;
return - V_201 ;
}
if ( V_193 == V_196 )
return F_73 ( V_27 , V_13 , V_170 ) ;
return 0 ;
}
static int F_92 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 , T_1 * V_132 )
{
T_1 V_193 ;
T_1 V_192 = * V_132 ;
T_2 * V_41 = ( T_2 * ) V_170 ;
int V_18 ;
const struct V_202 * V_31 ;
bool V_203 = V_27 -> V_204 & V_205 ;
V_193 = F_91 ( ( ( T_1 * ) V_170 ) [ 0 ] ) ;
if ( F_3 ( V_193 < V_206 ) )
return F_90 ( V_27 , V_13 , V_170 , V_132 ) ;
V_193 = F_91 ( V_41 -> V_39 ) ;
* V_132 = F_91 ( V_41 -> V_132 ) + sizeof( T_2 ) ;
V_193 -= V_207 ;
if ( F_3 ( * V_132 > V_192 ) )
goto V_208;
if ( F_3 ( V_193 >= V_209 - V_207 ) )
goto V_208;
V_31 = & V_210 [ V_193 ] ;
if ( F_3 ( ! V_31 -> V_211 ) )
goto V_208;
if ( F_3 ( ! V_31 -> V_212 && ! V_13 -> V_200 ) )
goto V_213;
if ( F_3 ( V_31 -> V_214 && V_203 ) )
goto V_215;
if ( F_3 ( V_31 -> V_216 && ! V_203 ) )
goto V_217;
V_18 = V_31 -> V_211 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_208;
return 0 ;
V_208:
F_13 ( L_30 ,
V_193 + V_207 ) ;
return - V_43 ;
V_213:
F_13 ( L_31 ,
V_193 + V_207 ) ;
return - V_201 ;
V_215:
F_13 ( L_32 ,
V_193 + V_207 ) ;
return - V_43 ;
V_217:
F_13 ( L_33 ,
V_193 + V_207 ) ;
return - V_43 ;
}
static int F_93 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 ,
T_1 V_132 )
{
T_38 V_218 = V_132 ;
int V_18 ;
V_13 -> V_78 = V_170 ;
while ( V_218 > 0 ) {
V_132 = V_218 ;
V_18 = F_92 ( V_27 , V_13 , V_170 , & V_132 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_170 = ( void * ) ( ( unsigned long ) V_170 + V_132 ) ;
V_218 -= V_132 ;
}
if ( F_3 ( V_218 != 0 ) ) {
F_13 ( L_34 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_94 ( struct V_12 * V_13 )
{
V_13 -> V_119 = 0 ;
}
static void F_95 ( struct V_12 * V_13 )
{
T_1 V_153 ;
struct V_117 * V_118 ;
struct V_51 * V_219 ;
struct V_44 * V_45 ;
for ( V_153 = 0 ; V_153 < V_13 -> V_119 ; ++ V_153 ) {
V_118 = & V_13 -> V_121 [ V_153 ] ;
V_219 = & V_13 -> V_54 [ V_118 -> V_124 ] . V_53 ;
V_45 = V_219 -> V_45 ;
switch ( V_45 -> V_220 . V_221 ) {
case V_222 :
V_118 -> V_123 -> V_34 += V_45 -> V_34 ;
V_118 -> V_123 -> V_126 = V_223 ;
break;
case V_224 :
V_118 -> V_123 -> V_126 = V_45 -> V_220 . V_225 ;
break;
case V_226 :
* V_118 -> V_122 = V_45 -> V_220 . V_225 ;
break;
default:
F_96 () ;
}
}
F_94 ( V_13 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_227 ;
F_26 (val, val_next, list, head) {
F_98 ( & V_5 -> V_24 ) ;
F_21 ( & V_5 -> V_7 ) ;
if ( F_3 ( V_5 -> V_10 ) )
F_5 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
}
}
static void F_99 ( struct V_12 * V_13 )
{
struct V_49 * V_31 , * V_228 ;
struct V_4 * V_5 ;
F_26 (entry, next, &sw_context->validate_nodes,
base.head) {
F_27 ( & V_31 -> V_53 . V_24 ) ;
F_58 ( & V_31 -> V_53 . V_45 ) ;
( void ) F_100 ( & V_13 -> V_19 , & V_31 -> V_17 ) ;
V_13 -> V_55 -- ;
}
F_43 ( V_13 -> V_55 != 0 ) ;
F_2 (val, &sw_context->resource_list, head)
( void ) F_100 ( & V_13 -> V_19 , & V_5 -> V_17 ) ;
}
static int F_101 ( struct V_26 * V_27 ,
struct V_44 * V_45 ,
bool V_46 )
{
int V_18 ;
if ( V_45 == V_27 -> V_111 ||
( V_45 == V_27 -> V_110 &&
V_27 -> V_112 ) )
return 0 ;
if ( V_46 )
return F_102 ( V_45 , & V_229 , true , false ) ;
V_18 = F_102 ( V_45 , & V_230 , true , false ) ;
if ( F_9 ( V_18 == 0 || V_18 == - V_63 ) )
return V_18 ;
F_103 ( L_35 ) ;
V_18 = F_102 ( V_45 , & V_231 , true , false ) ;
return V_18 ;
}
static int F_104 ( struct V_26 * V_27 ,
struct V_12 * V_13 )
{
struct V_49 * V_31 ;
int V_18 ;
F_2 (entry, &sw_context->validate_nodes, base.head) {
V_18 = F_101 ( V_27 , V_31 -> V_53 . V_45 ,
V_31 -> V_46 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static int F_105 ( struct V_12 * V_13 ,
T_1 V_132 )
{
if ( F_9 ( V_13 -> V_232 >= V_132 ) )
return 0 ;
if ( V_13 -> V_232 == 0 )
V_13 -> V_232 = V_233 ;
while ( V_13 -> V_232 < V_132 ) {
V_13 -> V_232 =
F_106 ( V_13 -> V_232 +
( V_13 -> V_232 >> 1 ) ) ;
}
if ( V_13 -> V_234 != NULL )
F_107 ( V_13 -> V_234 ) ;
V_13 -> V_234 = F_108 ( V_13 -> V_232 ) ;
if ( V_13 -> V_234 == NULL ) {
F_13 ( L_36 ) ;
V_13 -> V_232 = 0 ;
return - V_22 ;
}
return 0 ;
}
int F_109 ( struct V_235 * V_236 ,
struct V_26 * V_27 ,
struct V_237 * * V_238 ,
T_1 * V_239 )
{
T_1 V_240 ;
int V_18 ;
bool V_241 = false ;
F_43 ( V_239 != NULL && V_236 == NULL ) ;
V_18 = F_110 ( V_27 , & V_240 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_37 ) ;
V_241 = true ;
}
if ( V_239 != NULL )
V_18 = F_111 ( V_236 , V_27 -> V_242 ,
V_240 ,
V_60 ,
V_238 , V_239 ) ;
else
V_18 = F_112 ( V_27 -> V_242 , V_240 ,
V_60 ,
V_238 ) ;
if ( F_3 ( V_18 != 0 && ! V_241 ) ) {
( void ) F_113 ( V_27 , false , false ,
V_240 , false ,
V_243 ) ;
* V_238 = NULL ;
}
return 0 ;
}
void
F_114 ( struct V_26 * V_27 ,
struct V_244 * V_245 ,
int V_18 ,
struct V_246 T_39 * V_247 ,
struct V_237 * V_248 ,
T_1 V_249 )
{
struct V_246 V_250 ;
if ( V_247 == NULL )
return;
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . error = V_18 ;
if ( V_18 == 0 ) {
F_43 ( V_248 == NULL ) ;
V_250 . V_76 = V_249 ;
V_250 . V_251 = V_248 -> V_251 ;
F_115 ( V_27 , & V_27 -> V_252 ) ;
V_250 . V_253 = V_27 -> V_254 ;
}
V_18 = F_116 ( V_247 , & V_250 ,
sizeof( V_250 ) ) ;
if ( F_3 ( V_18 != 0 ) && ( V_250 . error == 0 ) ) {
F_117 ( V_245 -> V_80 ,
V_249 , V_255 ) ;
F_13 ( L_38 ) ;
( void ) F_118 ( V_248 , V_248 -> V_256 ,
false , false ,
V_243 ) ;
}
}
int F_119 ( struct V_235 * V_236 ,
struct V_26 * V_27 ,
void T_39 * V_257 ,
void * V_258 ,
T_1 V_259 ,
T_40 V_260 ,
struct V_246 T_39 * V_247 ,
struct V_237 * * V_261 )
{
struct V_12 * V_13 = & V_27 -> V_28 ;
struct V_237 * V_248 = NULL ;
struct V_6 * V_83 ;
struct V_1 V_25 ;
struct V_262 V_263 ;
T_1 V_76 ;
void * V_86 ;
int V_18 ;
V_18 = F_120 ( & V_27 -> V_264 ) ;
if ( F_3 ( V_18 != 0 ) )
return - V_63 ;
if ( V_258 == NULL ) {
V_13 -> V_200 = false ;
V_18 = F_105 ( V_13 , V_259 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_265;
V_18 = F_121 ( V_13 -> V_234 ,
V_257 , V_259 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_266 ;
F_13 ( L_39 ) ;
goto V_265;
}
V_258 = V_13 -> V_234 ;
} else
V_13 -> V_200 = true ;
V_13 -> V_79 = V_244 ( V_236 ) ;
V_13 -> V_119 = 0 ;
V_13 -> V_55 = 0 ;
V_13 -> V_59 = 0 ;
F_42 ( & V_13 -> V_25 ) ;
V_13 -> V_107 = V_27 -> V_111 ;
V_13 -> V_106 = NULL ;
V_13 -> V_109 = false ;
memset ( V_13 -> V_72 , 0 , sizeof( V_13 -> V_72 ) ) ;
F_42 ( & V_13 -> V_58 ) ;
F_42 ( & V_13 -> V_77 ) ;
if ( ! V_13 -> V_267 ) {
V_18 = F_122 ( & V_13 -> V_19 , V_268 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_265;
V_13 -> V_267 = true ;
}
F_42 ( & V_13 -> V_181 ) ;
F_42 ( & V_25 ) ;
V_18 = F_93 ( V_27 , V_13 , V_258 ,
V_259 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
V_18 = F_34 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
V_18 = F_123 ( & V_263 , & V_13 -> V_58 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_270;
V_18 = F_104 ( V_27 , V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_270;
V_18 = F_37 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_270;
if ( V_260 ) {
V_18 = F_124 ( V_27 , & V_27 -> V_252 . V_271 ,
V_260 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_270;
}
V_18 = F_120 ( & V_27 -> V_32 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_63 ;
goto V_270;
}
if ( V_27 -> V_82 ) {
V_18 = F_45 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_272;
}
V_86 = F_125 ( V_27 , V_259 ) ;
if ( F_3 ( V_86 == NULL ) ) {
F_13 ( L_40 ) ;
V_18 = - V_22 ;
goto V_272;
}
F_95 ( V_13 ) ;
memcpy ( V_86 , V_258 , V_259 ) ;
F_28 ( V_86 , & V_13 -> V_77 ) ;
F_25 ( & V_13 -> V_77 ) ;
F_126 ( V_27 , V_259 ) ;
F_55 ( V_27 , V_13 ) ;
V_18 = F_109 ( V_236 , V_27 ,
& V_248 ,
( V_247 ) ? & V_76 : NULL ) ;
if ( V_18 != 0 )
F_13 ( L_37 ) ;
F_1 ( & V_13 -> V_25 , false ) ;
F_22 ( & V_27 -> V_32 ) ;
F_127 ( & V_263 , & V_13 -> V_58 ,
( void * ) V_248 ) ;
if ( F_3 ( V_27 -> V_111 != NULL &&
! V_27 -> V_114 ) )
F_128 ( V_27 , V_248 ) ;
F_99 ( V_13 ) ;
F_114 ( V_27 , V_244 ( V_236 ) , V_18 ,
V_247 , V_248 , V_76 ) ;
if ( F_3 ( V_261 != NULL ) ) {
* V_261 = V_248 ;
V_248 = NULL ;
} else if ( F_9 ( V_248 != NULL ) ) {
F_129 ( & V_248 ) ;
}
F_130 ( & V_13 -> V_25 , & V_25 ) ;
F_131 ( V_13 -> V_79 -> V_179 ,
& V_13 -> V_181 ) ;
F_22 ( & V_27 -> V_264 ) ;
F_97 ( & V_25 ) ;
return 0 ;
V_272:
F_22 ( & V_27 -> V_32 ) ;
V_270:
F_132 ( & V_263 , & V_13 -> V_58 ) ;
V_269:
F_1 ( & V_13 -> V_25 , true ) ;
F_25 ( & V_13 -> V_77 ) ;
F_94 ( V_13 ) ;
F_99 ( V_13 ) ;
if ( F_3 ( V_27 -> V_111 != NULL &&
! V_27 -> V_114 ) )
F_128 ( V_27 , NULL ) ;
V_265:
F_130 ( & V_13 -> V_25 , & V_25 ) ;
V_83 = V_13 -> V_83 ;
V_13 -> V_83 = NULL ;
F_133 ( V_13 -> V_79 -> V_179 ,
& V_13 -> V_181 ) ;
F_22 ( & V_27 -> V_264 ) ;
F_97 ( & V_25 ) ;
if ( F_3 ( V_83 != NULL ) )
F_21 ( & V_83 ) ;
return V_18 ;
}
static void F_134 ( struct V_26 * V_27 )
{
F_13 ( L_41 ) ;
( void ) F_113 ( V_27 , false , true , 0 , false , 10 * V_273 ) ;
F_57 ( V_27 -> V_111 , false ) ;
F_57 ( V_27 -> V_110 , false ) ;
V_27 -> V_112 = false ;
}
void F_128 ( struct V_26 * V_27 ,
struct V_237 * V_248 )
{
int V_18 = 0 ;
struct V_1 V_274 ;
struct V_51 V_275 , V_276 ;
struct V_237 * V_277 = NULL ;
struct V_262 V_263 ;
if ( V_27 -> V_111 == NULL )
goto V_265;
F_42 ( & V_274 ) ;
V_275 . V_45 = F_33 ( V_27 -> V_111 ) ;
F_15 ( & V_275 . V_24 , & V_274 ) ;
V_276 . V_45 = F_33 ( V_27 -> V_110 ) ;
F_15 ( & V_276 . V_24 , & V_274 ) ;
do {
V_18 = F_123 ( & V_263 , & V_274 ) ;
} while ( V_18 == - V_63 );
if ( F_3 ( V_18 != 0 ) ) {
F_134 ( V_27 ) ;
goto V_278;
}
if ( V_27 -> V_114 ) {
F_43 ( V_248 != NULL ) ;
V_18 = F_56 ( V_27 , V_27 -> V_113 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_134 ( V_27 ) ;
goto V_279;
}
V_27 -> V_114 = false ;
}
F_57 ( V_27 -> V_111 , false ) ;
F_57 ( V_27 -> V_110 , false ) ;
V_27 -> V_112 = false ;
if ( V_248 == NULL ) {
( void ) F_109 ( NULL , V_27 , & V_277 ,
NULL ) ;
V_248 = V_277 ;
}
F_127 ( & V_263 , & V_274 , ( void * ) V_248 ) ;
if ( V_277 != NULL )
F_129 ( & V_277 ) ;
F_58 ( & V_276 . V_45 ) ;
F_58 ( & V_275 . V_45 ) ;
F_58 ( & V_27 -> V_111 ) ;
V_265:
return;
V_279:
F_132 ( & V_263 , & V_274 ) ;
V_278:
F_58 ( & V_276 . V_45 ) ;
F_58 ( & V_275 . V_45 ) ;
F_58 ( & V_27 -> V_111 ) ;
}
void F_135 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_264 ) ;
if ( V_27 -> V_114 )
F_128 ( V_27 , NULL ) ;
F_22 ( & V_27 -> V_264 ) ;
}
int F_136 ( struct V_280 * V_281 , void * V_282 ,
struct V_235 * V_236 )
{
struct V_26 * V_27 = F_137 ( V_281 ) ;
struct V_283 * V_284 = (struct V_283 * ) V_282 ;
int V_18 ;
if ( F_3 ( V_284 -> V_285 != V_286 ) ) {
F_13 ( L_42 ) ;
F_13 ( L_43
L_44 ) ;
return - V_43 ;
}
V_18 = F_138 ( & V_27 -> V_287 , true ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_119 ( V_236 , V_27 ,
( void T_39 * ) ( unsigned long ) V_284 -> V_288 ,
NULL , V_284 -> V_259 , V_284 -> V_260 ,
( void T_39 * ) ( unsigned long ) V_284 -> V_250 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_265;
F_139 ( V_27 ) ;
V_265:
F_140 ( & V_27 -> V_287 ) ;
return V_18 ;
}
