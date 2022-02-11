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
static int F_39 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
T_1 * V_66 ,
struct V_6 * V_7 ,
struct V_4 * * V_67 )
{
int V_18 ;
struct V_4 * V_15 ;
* V_67 = NULL ;
V_18 = F_23 ( & V_13 -> V_68 ,
V_7 ,
V_66 - V_13 -> V_69 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_8 ( V_13 , V_7 , & V_15 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_65 == V_70 && V_27 -> V_71 &&
V_15 -> V_20 ) {
F_27 ( & V_15 -> V_24 ) ;
F_40 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_18 = F_17 ( V_27 , V_13 , V_7 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_15 -> V_10 =
F_12 ( sizeof( * V_15 -> V_10 ) , V_21 ) ;
if ( V_15 -> V_10 == NULL ) {
F_13 ( L_10
L_11 ) ;
return - V_22 ;
}
F_41 ( & V_15 -> V_10 -> V_2 ) ;
}
if ( V_67 )
* V_67 = V_15 ;
return 0 ;
}
static int
F_42 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
const struct V_72 * V_73 ,
T_1 * V_66 ,
struct V_4 * * V_67 )
{
struct V_74 * V_75 =
& V_13 -> V_76 [ V_65 ] ;
struct V_6 * V_7 ;
struct V_4 * V_15 ;
int V_18 ;
if ( * V_66 == V_77 ) {
if ( V_67 )
* V_67 = NULL ;
if ( V_65 == V_70 ) {
F_13 ( L_12 ) ;
return - V_43 ;
}
return 0 ;
}
if ( F_9 ( V_75 -> V_78 && * V_66 == V_75 -> V_79 ) ) {
const struct V_6 * V_7 = V_75 -> V_7 ;
V_75 -> V_15 -> V_20 = false ;
if ( V_67 )
* V_67 = V_75 -> V_15 ;
return F_23
( & V_13 -> V_68 , V_7 ,
V_66 - V_13 -> V_69 ) ;
}
V_18 = F_43 ( V_27 ,
V_13 -> V_80 -> V_81 ,
* V_66 ,
V_73 ,
& V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_13 ,
( unsigned ) * V_66 ) ;
F_44 () ;
return V_18 ;
}
V_75 -> V_78 = true ;
V_75 -> V_7 = V_7 ;
V_75 -> V_79 = * V_66 ;
V_18 = F_39 ( V_27 , V_13 , V_65 , V_66 ,
V_7 , & V_15 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_82;
V_75 -> V_15 = V_15 ;
if ( V_67 )
* V_67 = V_15 ;
F_21 ( & V_7 ) ;
return 0 ;
V_82:
F_45 ( V_13 -> V_83 != NULL ) ;
V_13 -> V_83 = V_7 ;
return V_18 ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
int V_18 ;
F_2 (val, &sw_context->resource_list, head) {
if ( F_3 ( ! V_5 -> V_10 ) )
break;
V_18 = F_47 ( V_5 -> V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( V_18 != - V_63 )
F_13 ( L_14 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_48 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_84 {
T_2 V_41 ;
T_1 V_85 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_84 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_85 , NULL ) ;
}
static int F_49 ( struct V_26 * V_27 ,
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
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_94 . V_95 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_71 ) {
struct V_96 V_33 ;
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_98 ;
V_33 . V_99 . V_100 = V_86 -> V_89 . type ;
return F_50 ( V_90 -> V_10 , & V_33 ) ;
}
return 0 ;
}
static int F_51 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_4 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_101 . V_95 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_102 . V_95 , NULL ) ;
}
static int F_52 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_5 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_101 . V_95 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_102 . V_95 , NULL ) ;
}
static int F_53 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_6 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_103 . V_95 , NULL ) ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_88 {
T_2 V_41 ;
T_7 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_88 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 , & V_86 -> V_89 . V_95 ,
NULL ) ;
}
static int F_55 ( struct V_26 * V_27 ,
struct V_44 * V_104 ,
struct V_12 * V_13 )
{
struct V_74 * V_105 =
& V_13 -> V_76 [ V_70 ] ;
int V_18 ;
F_45 ( ! V_105 -> V_78 ) ;
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
V_27 -> V_71 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_13 -> V_107 = V_104 ;
V_18 = F_32 ( V_13 ,
V_27 -> V_110 ,
V_27 -> V_71 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static void F_56 ( struct V_26 * V_27 ,
struct V_12 * V_13 )
{
if ( V_13 -> V_109 ) {
struct V_74 * V_105 =
& V_13 -> V_76 [ V_70 ] ;
struct V_6 * V_28 ;
int V_18 ;
F_45 ( ! V_105 -> V_78 ) ;
V_28 = V_105 -> V_7 ;
V_18 = F_57 ( V_27 , V_28 -> V_39 ) ;
if ( F_3 ( V_18 != 0 ) )
F_13 ( L_16 ) ;
}
if ( V_27 -> V_111 != V_13 -> V_107 ) {
if ( V_27 -> V_111 ) {
F_58 ( V_27 -> V_111 , false ) ;
F_59 ( & V_27 -> V_111 ) ;
}
if ( ! V_13 -> V_109 ) {
F_58 ( V_13 -> V_107 , true ) ;
F_58 ( V_27 -> V_110 , true ) ;
V_27 -> V_112 = true ;
F_45 ( V_13 -> V_106 == NULL ) ;
V_27 -> V_113 = V_13 -> V_106 -> V_39 ;
V_27 -> V_114 = true ;
V_27 -> V_111 =
F_33 ( V_13 -> V_107 ) ;
}
}
}
static int F_60 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_8 * V_39 ,
struct V_8 * * V_115 )
{
struct V_8 * V_116 = NULL ;
struct V_44 * V_45 ;
T_1 V_79 = * V_39 ;
struct V_117 * V_118 ;
int V_18 ;
V_18 = F_61 ( V_13 -> V_80 -> V_81 , V_79 , & V_116 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_17 ) ;
return - V_43 ;
}
V_45 = & V_116 -> V_53 ;
if ( F_3 ( V_13 -> V_119 >= V_120 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_82;
}
V_118 = & V_13 -> V_121 [ V_13 -> V_119 ++ ] ;
V_118 -> V_122 = V_39 ;
V_118 -> V_123 = NULL ;
V_18 = F_32 ( V_13 , V_45 , true , & V_118 -> V_124 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_82;
* V_115 = V_116 ;
return 0 ;
V_82:
F_7 ( & V_116 ) ;
V_115 = NULL ;
return V_18 ;
}
static int F_62 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_9 * V_125 ,
struct V_8 * * V_115 )
{
struct V_8 * V_116 = NULL ;
struct V_44 * V_45 ;
T_1 V_79 = V_125 -> V_126 ;
struct V_117 * V_118 ;
int V_18 ;
V_18 = F_61 ( V_13 -> V_80 -> V_81 , V_79 , & V_116 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_20 ) ;
return - V_43 ;
}
V_45 = & V_116 -> V_53 ;
if ( F_3 ( V_13 -> V_119 >= V_120 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_82;
}
V_118 = & V_13 -> V_121 [ V_13 -> V_119 ++ ] ;
V_118 -> V_123 = V_125 ;
V_18 = F_32 ( V_13 , V_45 , false , & V_118 -> V_124 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_82;
* V_115 = V_116 ;
return 0 ;
V_82:
F_7 ( & V_116 ) ;
V_115 = NULL ;
return V_18 ;
}
static int F_63 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_127 {
T_2 V_41 ;
T_10 V_128 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_127 ,
V_41 ) ;
return F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_128 . V_85 ,
NULL ) ;
}
static int F_64 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_129 {
T_2 V_41 ;
T_11 V_128 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_129 ,
V_41 ) ;
if ( F_3 ( V_27 -> V_71 ) ) {
struct {
T_2 V_41 ;
T_10 V_128 ;
} V_130 ;
F_45 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_131 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_63 ( V_27 , V_13 , V_41 ) ;
}
return F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_128 . V_85 ,
NULL ) ;
}
static int F_65 ( struct V_26 * V_27 ,
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
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 ,
& V_86 -> V_128 . V_134 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_55 ( V_27 , & V_116 -> V_53 , V_13 ) ;
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
T_13 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
if ( V_27 -> V_71 ) {
struct {
T_2 V_41 ;
T_12 V_128 ;
} V_130 ;
F_45 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_135 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
V_130 . V_128 . V_134 = V_86 -> V_128 . V_136 . V_126 ;
V_130 . V_128 . V_34 = V_86 -> V_128 . V_136 . V_34 ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_65 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_86 -> V_128 . V_136 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_55 ( V_27 , & V_116 -> V_53 , V_13 ) ;
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_67 ( struct V_26 * V_27 ,
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
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 ,
& V_86 -> V_128 . V_134 ,
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
struct V_8 * V_116 ;
struct V_133 {
T_2 V_41 ;
T_15 V_128 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_133 , V_41 ) ;
if ( V_27 -> V_71 ) {
struct {
T_2 V_41 ;
T_14 V_128 ;
} V_130 ;
F_45 ( sizeof( V_130 ) != sizeof( * V_86 ) ) ;
V_130 . V_41 . V_39 = V_137 ;
V_130 . V_41 . V_132 = V_86 -> V_41 . V_132 ;
V_130 . V_128 . V_85 = V_86 -> V_128 . V_85 ;
V_130 . V_128 . type = V_86 -> V_128 . type ;
V_130 . V_128 . V_134 = V_86 -> V_128 . V_136 . V_126 ;
V_130 . V_128 . V_34 = V_86 -> V_128 . V_136 . V_34 ;
memcpy ( V_86 , & V_130 , sizeof( * V_86 ) ) ;
return F_67 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_86 -> V_128 . V_136 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_116 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 ,
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
V_18 = F_62 ( V_27 , V_13 ,
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
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 , & V_86 -> V_141 . V_148 . V_95 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( F_3 ( V_18 != - V_63 ) )
F_13 ( L_23 ) ;
goto V_149;
}
V_139 = F_70 ( V_13 -> V_76 [ V_92 ] . V_7 ) ;
F_71 ( V_139 , V_13 -> V_80 -> V_81 , & V_116 -> V_53 ,
V_41 ) ;
V_149:
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_72 ( struct V_26 * V_27 ,
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
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_86 = F_11 ( V_41 , struct V_150 , V_41 ) ;
V_154 = ( V_41 -> V_132 - sizeof( V_86 -> V_89 ) ) / sizeof( * V_151 ) ;
if ( F_3 ( V_86 -> V_89 . V_155 > V_154 ) ) {
F_13 ( L_24 ) ;
return - V_43 ;
}
for ( V_153 = 0 ; V_153 < V_86 -> V_89 . V_155 ; ++ V_153 , ++ V_151 ) {
V_18 = F_42 ( V_27 , V_13 , V_92 ,
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
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_152 -> V_159 . V_157 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static int F_73 ( struct V_26 * V_27 ,
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
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_161 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
for (; V_163 < V_162 ; ++ V_163 ) {
if ( F_9 ( V_163 -> V_164 != V_165 ) )
continue;
V_18 = F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_163 -> V_166 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_71 ) {
struct V_96 V_33 ;
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_167 ;
V_33 . V_99 . V_168 = V_163 -> V_169 ;
F_50 ( V_90 -> V_10 ,
& V_33 ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 )
{
struct V_8 * V_116 ;
int V_18 ;
struct {
T_1 V_41 ;
T_23 V_89 ;
} * V_86 = V_170 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_86 -> V_89 . V_125 ,
& V_116 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_116 ) ;
return V_18 ;
}
static int F_75 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_64 V_65 ,
const struct V_72
* V_73 ,
T_1 * V_171 ,
T_1 * V_172 ,
unsigned long V_173 )
{
int V_18 ;
struct V_8 * V_174 ;
struct V_4 * V_48 ;
V_18 = F_42 ( V_27 , V_13 , V_65 ,
V_73 , V_171 , & V_48 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 , V_172 , & V_174 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_48 -> V_20 )
V_48 -> V_61 = true ;
F_7 ( & V_48 -> V_9 ) ;
V_48 -> V_9 = V_174 ;
V_48 -> V_11 = V_173 ;
return 0 ;
}
static int F_76 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_175 {
T_2 V_41 ;
T_24 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_175 , V_41 ) ;
return F_75 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , & V_86 -> V_89 . V_134 ,
0 ) ;
}
static int F_77 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_25 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_78 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_26 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_79 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_27 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_80 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_28 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_81 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_29 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_177 . V_95 , NULL ) ;
}
static int F_82 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_30 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_176 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_92 ,
V_93 ,
& V_86 -> V_89 . V_95 , NULL ) ;
}
static int F_83 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_178 {
T_2 V_41 ;
T_31 V_89 ;
} * V_86 ;
int V_18 ;
T_32 V_132 ;
struct V_4 * V_5 ;
V_86 = F_11 ( V_41 , struct V_178 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_5 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_71 ) )
return 0 ;
V_132 = V_86 -> V_41 . V_132 - sizeof( V_86 -> V_89 ) ;
V_18 = F_84 ( V_27 ,
F_85 ( V_5 -> V_7 ) ,
V_86 -> V_89 . V_179 , V_86 + 1 ,
V_86 -> V_89 . type , V_132 ,
& V_13 -> V_180 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_68 ,
NULL , & V_86 -> V_41 . V_39 -
V_13 -> V_69 ) ;
return 0 ;
}
static int F_86 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_181 {
T_2 V_41 ;
T_33 V_89 ;
} * V_86 ;
int V_18 ;
struct V_4 * V_5 ;
V_86 = F_11 ( V_41 , struct V_181 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_5 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_71 ) )
return 0 ;
V_18 = F_87 ( F_85 ( V_5 -> V_7 ) ,
V_86 -> V_89 . V_179 ,
V_86 -> V_89 . type ,
& V_13 -> V_180 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_68 ,
NULL , & V_86 -> V_41 . V_39 -
V_13 -> V_69 ) ;
return 0 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_182 {
T_2 V_41 ;
T_34 V_89 ;
} * V_86 ;
struct V_4 * V_90 , * V_91 = NULL ;
struct V_96 V_33 ;
struct V_6 * V_7 = NULL ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_182 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_89 . V_85 ,
& V_90 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( ! V_27 -> V_71 )
return 0 ;
if ( V_86 -> V_89 . V_179 != V_77 ) {
V_7 = F_89
( F_85 ( V_90 -> V_7 ) ,
V_86 -> V_89 . V_179 ,
V_86 -> V_89 . type ) ;
if ( ! F_90 ( V_7 ) ) {
V_18 = F_39 ( V_27 , V_13 ,
V_183 ,
& V_86 -> V_89 . V_179 , V_7 ,
& V_91 ) ;
F_21 ( & V_7 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
}
if ( ! V_91 ) {
V_18 = F_42 ( V_27 , V_13 ,
V_183 ,
V_184 ,
& V_86 -> V_89 . V_179 , & V_91 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_33 . V_28 = V_90 -> V_7 ;
V_33 . V_7 = V_91 ? V_91 -> V_7 : NULL ;
V_33 . V_97 = V_185 ;
V_33 . V_99 . V_186 = V_86 -> V_89 . type ;
return F_50 ( V_90 -> V_10 , & V_33 ) ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_187 {
T_2 V_41 ;
T_35 V_89 ;
} * V_86 ;
int V_18 ;
V_86 = F_11 ( V_41 , struct V_187 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_70 ,
V_87 , & V_86 -> V_89 . V_85 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_71 )
V_41 -> V_39 = V_188 ;
return 0 ;
}
static int F_92 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_189 {
T_2 V_41 ;
T_36 V_89 ;
} * V_86 ;
V_86 = F_11 ( V_41 , struct V_189 ,
V_41 ) ;
return F_75 ( V_27 , V_13 , V_183 ,
V_184 ,
& V_86 -> V_89 . V_179 , & V_86 -> V_89 . V_134 ,
V_86 -> V_89 . V_190 ) ;
}
static int F_93 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 , T_1 * V_132 )
{
T_1 V_191 = * V_132 ;
T_1 V_192 ;
V_192 = F_94 ( ( ( T_1 * ) V_170 ) [ 0 ] ) ;
switch ( V_192 ) {
case V_193 :
* V_132 = sizeof( T_1 ) + sizeof( V_194 ) ;
break;
case V_195 :
* V_132 = sizeof( T_1 ) + sizeof( T_23 ) ;
break;
case V_196 :
* V_132 = sizeof( T_1 ) + sizeof( V_197 ) ;
break;
case V_198 :
* V_132 = sizeof( T_1 ) + sizeof( V_197 ) ;
break;
default:
F_13 ( L_26 , V_192 ) ;
return - V_43 ;
}
if ( * V_132 > V_191 ) {
F_13 ( L_27
L_28 , V_192 ) ;
return - V_43 ;
}
if ( F_3 ( ! V_13 -> V_199 ) ) {
F_13 ( L_29 , V_192 ) ;
return - V_200 ;
}
if ( V_192 == V_195 )
return F_74 ( V_27 , V_13 , V_170 ) ;
return 0 ;
}
static int F_95 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 , T_1 * V_132 )
{
T_1 V_192 ;
T_1 V_191 = * V_132 ;
T_2 * V_41 = ( T_2 * ) V_170 ;
int V_18 ;
const struct V_201 * V_31 ;
bool V_202 = V_27 -> V_203 & V_204 ;
V_192 = F_94 ( ( ( T_1 * ) V_170 ) [ 0 ] ) ;
if ( F_3 ( V_192 < V_205 ) )
return F_93 ( V_27 , V_13 , V_170 , V_132 ) ;
V_192 = F_94 ( V_41 -> V_39 ) ;
* V_132 = F_94 ( V_41 -> V_132 ) + sizeof( T_2 ) ;
V_192 -= V_206 ;
if ( F_3 ( * V_132 > V_191 ) )
goto V_207;
if ( F_3 ( V_192 >= V_208 - V_206 ) )
goto V_207;
V_31 = & V_209 [ V_192 ] ;
if ( F_3 ( ! V_31 -> V_210 ) )
goto V_207;
if ( F_3 ( ! V_31 -> V_211 && ! V_13 -> V_199 ) )
goto V_212;
if ( F_3 ( V_31 -> V_213 && V_202 ) )
goto V_214;
if ( F_3 ( V_31 -> V_215 && ! V_202 ) )
goto V_216;
V_18 = V_31 -> V_210 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_207;
return 0 ;
V_207:
F_13 ( L_30 ,
V_192 + V_206 ) ;
return - V_43 ;
V_212:
F_13 ( L_31 ,
V_192 + V_206 ) ;
return - V_200 ;
V_214:
F_13 ( L_32 ,
V_192 + V_206 ) ;
return - V_43 ;
V_216:
F_13 ( L_33 ,
V_192 + V_206 ) ;
return - V_43 ;
}
static int F_96 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_170 ,
T_1 V_132 )
{
T_37 V_217 = V_132 ;
int V_18 ;
V_13 -> V_69 = V_170 ;
while ( V_217 > 0 ) {
V_132 = V_217 ;
V_18 = F_95 ( V_27 , V_13 , V_170 , & V_132 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_170 = ( void * ) ( ( unsigned long ) V_170 + V_132 ) ;
V_217 -= V_132 ;
}
if ( F_3 ( V_217 != 0 ) ) {
F_13 ( L_34 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_97 ( struct V_12 * V_13 )
{
V_13 -> V_119 = 0 ;
}
static void F_98 ( struct V_12 * V_13 )
{
T_1 V_153 ;
struct V_117 * V_118 ;
struct V_51 * V_218 ;
struct V_44 * V_45 ;
for ( V_153 = 0 ; V_153 < V_13 -> V_119 ; ++ V_153 ) {
V_118 = & V_13 -> V_121 [ V_153 ] ;
V_218 = & V_13 -> V_54 [ V_118 -> V_124 ] . V_53 ;
V_45 = V_218 -> V_45 ;
switch ( V_45 -> V_219 . V_220 ) {
case V_221 :
V_118 -> V_123 -> V_34 += V_45 -> V_34 ;
V_118 -> V_123 -> V_126 = V_222 ;
break;
case V_223 :
V_118 -> V_123 -> V_126 = V_45 -> V_219 . V_224 ;
break;
case V_225 :
* V_118 -> V_122 = V_45 -> V_219 . V_224 ;
break;
default:
F_99 () ;
}
}
F_97 ( V_13 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_226 ;
F_26 (val, val_next, list, head) {
F_101 ( & V_5 -> V_24 ) ;
F_21 ( & V_5 -> V_7 ) ;
if ( F_3 ( V_5 -> V_10 ) )
F_5 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
}
}
static void F_102 ( struct V_12 * V_13 )
{
struct V_49 * V_31 , * V_227 ;
struct V_4 * V_5 ;
F_26 (entry, next, &sw_context->validate_nodes,
base.head) {
F_27 ( & V_31 -> V_53 . V_24 ) ;
F_59 ( & V_31 -> V_53 . V_45 ) ;
( void ) F_103 ( & V_13 -> V_19 , & V_31 -> V_17 ) ;
V_13 -> V_55 -- ;
}
F_45 ( V_13 -> V_55 != 0 ) ;
F_2 (val, &sw_context->resource_list, head)
( void ) F_103 ( & V_13 -> V_19 , & V_5 -> V_17 ) ;
}
static int F_104 ( struct V_26 * V_27 ,
struct V_44 * V_45 ,
bool V_46 )
{
int V_18 ;
if ( V_45 == V_27 -> V_111 ||
( V_45 == V_27 -> V_110 &&
V_27 -> V_112 ) )
return 0 ;
if ( V_46 )
return F_105 ( V_45 , & V_228 , true , false ) ;
V_18 = F_105 ( V_45 , & V_229 , true , false ) ;
if ( F_9 ( V_18 == 0 || V_18 == - V_63 ) )
return V_18 ;
F_106 ( L_35 ) ;
V_18 = F_105 ( V_45 , & V_230 , true , false ) ;
return V_18 ;
}
static int F_107 ( struct V_26 * V_27 ,
struct V_12 * V_13 )
{
struct V_49 * V_31 ;
int V_18 ;
F_2 (entry, &sw_context->validate_nodes, base.head) {
V_18 = F_104 ( V_27 , V_31 -> V_53 . V_45 ,
V_31 -> V_46 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static int F_108 ( struct V_12 * V_13 ,
T_1 V_132 )
{
if ( F_9 ( V_13 -> V_231 >= V_132 ) )
return 0 ;
if ( V_13 -> V_231 == 0 )
V_13 -> V_231 = V_232 ;
while ( V_13 -> V_231 < V_132 ) {
V_13 -> V_231 =
F_109 ( V_13 -> V_231 +
( V_13 -> V_231 >> 1 ) ) ;
}
if ( V_13 -> V_233 != NULL )
F_110 ( V_13 -> V_233 ) ;
V_13 -> V_233 = F_111 ( V_13 -> V_231 ) ;
if ( V_13 -> V_233 == NULL ) {
F_13 ( L_36 ) ;
V_13 -> V_231 = 0 ;
return - V_22 ;
}
return 0 ;
}
int F_112 ( struct V_234 * V_235 ,
struct V_26 * V_27 ,
struct V_236 * * V_237 ,
T_1 * V_238 )
{
T_1 V_239 ;
int V_18 ;
bool V_240 = false ;
F_45 ( V_238 != NULL && V_235 == NULL ) ;
V_18 = F_113 ( V_27 , & V_239 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_37 ) ;
V_240 = true ;
}
if ( V_238 != NULL )
V_18 = F_114 ( V_235 , V_27 -> V_241 ,
V_239 ,
V_60 ,
V_237 , V_238 ) ;
else
V_18 = F_115 ( V_27 -> V_241 , V_239 ,
V_60 ,
V_237 ) ;
if ( F_3 ( V_18 != 0 && ! V_240 ) ) {
( void ) F_116 ( V_27 , false , false ,
V_239 , false ,
V_242 ) ;
* V_237 = NULL ;
}
return 0 ;
}
void
F_117 ( struct V_26 * V_27 ,
struct V_243 * V_244 ,
int V_18 ,
struct V_245 T_38 * V_246 ,
struct V_236 * V_247 ,
T_1 V_248 )
{
struct V_245 V_249 ;
if ( V_246 == NULL )
return;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_249 . error = V_18 ;
if ( V_18 == 0 ) {
F_45 ( V_247 == NULL ) ;
V_249 . V_79 = V_248 ;
V_249 . V_250 = V_247 -> V_250 ;
F_118 ( V_27 , & V_27 -> V_251 ) ;
V_249 . V_252 = V_27 -> V_253 ;
}
V_18 = F_119 ( V_246 , & V_249 ,
sizeof( V_249 ) ) ;
if ( F_3 ( V_18 != 0 ) && ( V_249 . error == 0 ) ) {
F_120 ( V_244 -> V_81 ,
V_248 , V_254 ) ;
F_13 ( L_38 ) ;
( void ) F_121 ( V_247 , V_247 -> V_255 ,
false , false ,
V_242 ) ;
}
}
int F_122 ( struct V_234 * V_235 ,
struct V_26 * V_27 ,
void T_38 * V_256 ,
void * V_257 ,
T_1 V_258 ,
T_39 V_259 ,
struct V_245 T_38 * V_246 ,
struct V_236 * * V_260 )
{
struct V_12 * V_13 = & V_27 -> V_28 ;
struct V_236 * V_247 = NULL ;
struct V_6 * V_83 ;
struct V_1 V_25 ;
struct V_261 V_262 ;
T_1 V_79 ;
void * V_86 ;
int V_18 ;
V_18 = F_123 ( & V_27 -> V_263 ) ;
if ( F_3 ( V_18 != 0 ) )
return - V_63 ;
if ( V_257 == NULL ) {
V_13 -> V_199 = false ;
V_18 = F_108 ( V_13 , V_258 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_264;
V_18 = F_124 ( V_13 -> V_233 ,
V_256 , V_258 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_265 ;
F_13 ( L_39 ) ;
goto V_264;
}
V_257 = V_13 -> V_233 ;
} else
V_13 -> V_199 = true ;
V_13 -> V_80 = V_243 ( V_235 ) ;
V_13 -> V_119 = 0 ;
V_13 -> V_55 = 0 ;
V_13 -> V_59 = 0 ;
F_41 ( & V_13 -> V_25 ) ;
V_13 -> V_107 = V_27 -> V_111 ;
V_13 -> V_106 = NULL ;
V_13 -> V_109 = false ;
memset ( V_13 -> V_76 , 0 , sizeof( V_13 -> V_76 ) ) ;
F_41 ( & V_13 -> V_58 ) ;
F_41 ( & V_13 -> V_68 ) ;
if ( ! V_13 -> V_266 ) {
V_18 = F_125 ( & V_13 -> V_19 , V_267 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_264;
V_13 -> V_266 = true ;
}
F_41 ( & V_13 -> V_180 ) ;
F_41 ( & V_25 ) ;
V_18 = F_96 ( V_27 , V_13 , V_257 ,
V_258 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_268;
V_18 = F_34 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_268;
V_18 = F_126 ( & V_262 , & V_13 -> V_58 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
V_18 = F_107 ( V_27 , V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
V_18 = F_37 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
if ( V_259 ) {
V_18 = F_127 ( V_27 , & V_27 -> V_251 . V_270 ,
V_259 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_269;
}
V_18 = F_123 ( & V_27 -> V_32 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_63 ;
goto V_269;
}
if ( V_27 -> V_71 ) {
V_18 = F_46 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_271;
}
V_86 = F_128 ( V_27 , V_258 ) ;
if ( F_3 ( V_86 == NULL ) ) {
F_13 ( L_40 ) ;
V_18 = - V_22 ;
goto V_271;
}
F_98 ( V_13 ) ;
memcpy ( V_86 , V_257 , V_258 ) ;
F_28 ( V_86 , & V_13 -> V_68 ) ;
F_25 ( & V_13 -> V_68 ) ;
F_129 ( V_27 , V_258 ) ;
F_56 ( V_27 , V_13 ) ;
V_18 = F_112 ( V_235 , V_27 ,
& V_247 ,
( V_246 ) ? & V_79 : NULL ) ;
if ( V_18 != 0 )
F_13 ( L_37 ) ;
F_1 ( & V_13 -> V_25 , false ) ;
F_22 ( & V_27 -> V_32 ) ;
F_130 ( & V_262 , & V_13 -> V_58 ,
( void * ) V_247 ) ;
if ( F_3 ( V_27 -> V_111 != NULL &&
! V_27 -> V_114 ) )
F_131 ( V_27 , V_247 ) ;
F_102 ( V_13 ) ;
F_117 ( V_27 , V_243 ( V_235 ) , V_18 ,
V_246 , V_247 , V_79 ) ;
if ( F_3 ( V_260 != NULL ) ) {
* V_260 = V_247 ;
V_247 = NULL ;
} else if ( F_9 ( V_247 != NULL ) ) {
F_132 ( & V_247 ) ;
}
F_133 ( & V_13 -> V_25 , & V_25 ) ;
F_134 ( & V_13 -> V_180 ) ;
F_22 ( & V_27 -> V_263 ) ;
F_100 ( & V_25 ) ;
return 0 ;
V_271:
F_22 ( & V_27 -> V_32 ) ;
V_269:
F_135 ( & V_262 , & V_13 -> V_58 ) ;
V_268:
F_1 ( & V_13 -> V_25 , true ) ;
F_25 ( & V_13 -> V_68 ) ;
F_97 ( V_13 ) ;
F_102 ( V_13 ) ;
if ( F_3 ( V_27 -> V_111 != NULL &&
! V_27 -> V_114 ) )
F_131 ( V_27 , NULL ) ;
V_264:
F_133 ( & V_13 -> V_25 , & V_25 ) ;
V_83 = V_13 -> V_83 ;
V_13 -> V_83 = NULL ;
F_136 ( & V_13 -> V_180 ) ;
F_22 ( & V_27 -> V_263 ) ;
F_100 ( & V_25 ) ;
if ( F_3 ( V_83 != NULL ) )
F_21 ( & V_83 ) ;
return V_18 ;
}
static void F_137 ( struct V_26 * V_27 )
{
F_13 ( L_41 ) ;
( void ) F_116 ( V_27 , false , true , 0 , false , 10 * V_272 ) ;
F_58 ( V_27 -> V_111 , false ) ;
F_58 ( V_27 -> V_110 , false ) ;
V_27 -> V_112 = false ;
}
void F_131 ( struct V_26 * V_27 ,
struct V_236 * V_247 )
{
int V_18 = 0 ;
struct V_1 V_273 ;
struct V_51 V_274 , V_275 ;
struct V_236 * V_276 = NULL ;
struct V_261 V_262 ;
if ( V_27 -> V_111 == NULL )
goto V_264;
F_41 ( & V_273 ) ;
V_274 . V_45 = F_33 ( V_27 -> V_111 ) ;
F_15 ( & V_274 . V_24 , & V_273 ) ;
V_275 . V_45 = F_33 ( V_27 -> V_110 ) ;
F_15 ( & V_275 . V_24 , & V_273 ) ;
do {
V_18 = F_126 ( & V_262 , & V_273 ) ;
} while ( V_18 == - V_63 );
if ( F_3 ( V_18 != 0 ) ) {
F_137 ( V_27 ) ;
goto V_277;
}
if ( V_27 -> V_114 ) {
F_45 ( V_247 != NULL ) ;
V_18 = F_57 ( V_27 , V_27 -> V_113 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_137 ( V_27 ) ;
goto V_278;
}
V_27 -> V_114 = false ;
}
F_58 ( V_27 -> V_111 , false ) ;
F_58 ( V_27 -> V_110 , false ) ;
V_27 -> V_112 = false ;
if ( V_247 == NULL ) {
( void ) F_112 ( NULL , V_27 , & V_276 ,
NULL ) ;
V_247 = V_276 ;
}
F_130 ( & V_262 , & V_273 , ( void * ) V_247 ) ;
if ( V_276 != NULL )
F_132 ( & V_276 ) ;
F_59 ( & V_275 . V_45 ) ;
F_59 ( & V_274 . V_45 ) ;
F_59 ( & V_27 -> V_111 ) ;
V_264:
return;
V_278:
F_135 ( & V_262 , & V_273 ) ;
V_277:
F_59 ( & V_275 . V_45 ) ;
F_59 ( & V_274 . V_45 ) ;
F_59 ( & V_27 -> V_111 ) ;
}
void F_138 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_263 ) ;
if ( V_27 -> V_114 )
F_131 ( V_27 , NULL ) ;
F_22 ( & V_27 -> V_263 ) ;
}
int F_139 ( struct V_279 * V_280 , void * V_281 ,
struct V_234 * V_235 )
{
struct V_26 * V_27 = F_140 ( V_280 ) ;
struct V_282 * V_283 = (struct V_282 * ) V_281 ;
int V_18 ;
if ( F_3 ( V_283 -> V_284 != V_285 ) ) {
F_13 ( L_42 ) ;
F_13 ( L_43
L_44 ) ;
return - V_43 ;
}
V_18 = F_141 ( & V_27 -> V_286 , true ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_122 ( V_235 , V_27 ,
( void T_38 * ) ( unsigned long ) V_283 -> V_287 ,
NULL , V_283 -> V_258 , V_283 -> V_259 ,
( void T_38 * ) ( unsigned long ) V_283 -> V_249 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_264;
F_142 ( V_27 ) ;
V_264:
F_143 ( & V_27 -> V_286 ) ;
return V_18 ;
}
