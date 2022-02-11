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
V_18 = F_35 ( V_7 , V_5 -> V_59 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_7 -> V_60 ) {
struct V_44 * V_45 = & V_7 -> V_60 -> V_53 ;
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
if ( V_18 != - V_61 )
F_13 ( L_9 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_39 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_62 V_63 ,
T_1 * V_64 ,
struct V_6 * V_7 ,
struct V_4 * * V_65 )
{
int V_18 ;
struct V_4 * V_15 ;
* V_65 = NULL ;
V_18 = F_23 ( & V_13 -> V_66 ,
V_7 ,
V_64 - V_13 -> V_67 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_8 ( V_13 , V_7 , & V_15 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_63 == V_68 && V_27 -> V_69 &&
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
if ( V_65 )
* V_65 = V_15 ;
return 0 ;
}
static int
F_42 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_62 V_63 ,
const struct V_70 * V_71 ,
T_1 * V_64 ,
struct V_4 * * V_65 )
{
struct V_72 * V_73 =
& V_13 -> V_74 [ V_63 ] ;
struct V_6 * V_7 ;
struct V_4 * V_15 ;
int V_18 ;
if ( * V_64 == V_75 ) {
if ( V_65 )
* V_65 = NULL ;
if ( V_63 == V_68 ) {
F_13 ( L_12 ) ;
return - V_43 ;
}
return 0 ;
}
if ( F_9 ( V_73 -> V_76 && * V_64 == V_73 -> V_77 ) ) {
const struct V_6 * V_7 = V_73 -> V_7 ;
V_73 -> V_15 -> V_20 = false ;
if ( V_65 )
* V_65 = V_73 -> V_15 ;
return F_23
( & V_13 -> V_66 , V_7 ,
V_64 - V_13 -> V_67 ) ;
}
V_18 = F_43 ( V_27 ,
V_13 -> V_78 -> V_79 ,
* V_64 ,
V_71 ,
& V_7 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_13 ,
( unsigned ) * V_64 ) ;
F_44 () ;
return V_18 ;
}
V_73 -> V_76 = true ;
V_73 -> V_7 = V_7 ;
V_73 -> V_77 = * V_64 ;
V_18 = F_39 ( V_27 , V_13 , V_63 , V_64 ,
V_7 , & V_15 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_80;
V_73 -> V_15 = V_15 ;
if ( V_65 )
* V_65 = V_15 ;
F_21 ( & V_7 ) ;
return 0 ;
V_80:
F_45 ( V_13 -> V_81 != NULL ) ;
V_13 -> V_81 = V_7 ;
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
if ( V_18 != - V_61 )
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
struct V_82 {
T_2 V_41 ;
T_1 V_83 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_82 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_83 , NULL ) ;
}
static int F_49 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_86 {
T_2 V_41 ;
T_3 V_87 ;
} * V_84 ;
struct V_4 * V_88 ;
struct V_4 * V_89 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_86 , V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_87 . V_83 ,
& V_88 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_92 . V_93 , & V_89 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_69 ) {
struct V_94 V_33 ;
V_33 . V_28 = V_88 -> V_7 ;
V_33 . V_7 = V_89 ? V_89 -> V_7 : NULL ;
V_33 . V_95 = V_96 ;
V_33 . V_97 . V_98 = V_84 -> V_87 . type ;
return F_50 ( V_88 -> V_10 , & V_33 ) ;
}
return 0 ;
}
static int F_51 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_86 {
T_2 V_41 ;
T_4 V_87 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_86 , V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_99 . V_93 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_100 . V_93 , NULL ) ;
}
static int F_52 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_86 {
T_2 V_41 ;
T_5 V_87 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_86 , V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_99 . V_93 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_100 . V_93 , NULL ) ;
}
static int F_53 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_86 {
T_2 V_41 ;
T_6 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_86 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_101 . V_93 , NULL ) ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_86 {
T_2 V_41 ;
T_7 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_86 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 , & V_84 -> V_87 . V_93 ,
NULL ) ;
}
static int F_55 ( struct V_26 * V_27 ,
struct V_44 * V_102 ,
struct V_12 * V_13 )
{
struct V_72 * V_103 =
& V_13 -> V_74 [ V_68 ] ;
int V_18 ;
F_45 ( ! V_103 -> V_76 ) ;
V_13 -> V_104 = V_103 -> V_7 ;
if ( F_3 ( V_102 != V_13 -> V_105 ) ) {
if ( F_3 ( V_102 -> V_106 > 4 ) ) {
F_13 ( L_15 ) ;
return - V_43 ;
}
if ( F_3 ( V_13 -> V_105 != NULL ) ) {
V_13 -> V_107 = true ;
V_18 = F_32 ( V_13 ,
V_13 -> V_105 ,
V_27 -> V_69 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_13 -> V_105 = V_102 ;
V_18 = F_32 ( V_13 ,
V_27 -> V_108 ,
V_27 -> V_69 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static void F_56 ( struct V_26 * V_27 ,
struct V_12 * V_13 )
{
if ( V_13 -> V_107 ) {
struct V_72 * V_103 =
& V_13 -> V_74 [ V_68 ] ;
struct V_6 * V_28 ;
int V_18 ;
F_45 ( ! V_103 -> V_76 ) ;
V_28 = V_103 -> V_7 ;
V_18 = F_57 ( V_27 , V_28 -> V_39 ) ;
if ( F_3 ( V_18 != 0 ) )
F_13 ( L_16 ) ;
}
if ( V_27 -> V_109 != V_13 -> V_105 ) {
if ( V_27 -> V_109 ) {
F_58 ( V_27 -> V_109 , false ) ;
F_59 ( & V_27 -> V_109 ) ;
}
if ( ! V_13 -> V_107 ) {
F_58 ( V_13 -> V_105 , true ) ;
F_58 ( V_27 -> V_108 , true ) ;
V_27 -> V_110 = true ;
F_45 ( V_13 -> V_104 == NULL ) ;
V_27 -> V_111 = V_13 -> V_104 -> V_39 ;
V_27 -> V_112 = true ;
V_27 -> V_109 =
F_33 ( V_13 -> V_105 ) ;
}
}
}
static int F_60 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_8 * V_39 ,
struct V_8 * * V_113 )
{
struct V_8 * V_114 = NULL ;
struct V_44 * V_45 ;
T_1 V_77 = * V_39 ;
struct V_115 * V_116 ;
int V_18 ;
V_18 = F_61 ( V_13 -> V_78 -> V_79 , V_77 , & V_114 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_17 ) ;
V_18 = - V_43 ;
goto V_80;
}
V_45 = & V_114 -> V_53 ;
if ( F_3 ( V_13 -> V_117 >= V_118 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_80;
}
V_116 = & V_13 -> V_119 [ V_13 -> V_117 ++ ] ;
V_116 -> V_120 = V_39 ;
V_116 -> V_121 = NULL ;
V_18 = F_32 ( V_13 , V_45 , true , & V_116 -> V_122 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_80;
* V_113 = V_114 ;
return 0 ;
V_80:
F_7 ( & V_114 ) ;
* V_113 = NULL ;
return V_18 ;
}
static int F_62 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_9 * V_123 ,
struct V_8 * * V_113 )
{
struct V_8 * V_114 = NULL ;
struct V_44 * V_45 ;
T_1 V_77 = V_123 -> V_124 ;
struct V_115 * V_116 ;
int V_18 ;
V_18 = F_61 ( V_13 -> V_78 -> V_79 , V_77 , & V_114 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_20 ) ;
V_18 = - V_43 ;
goto V_80;
}
V_45 = & V_114 -> V_53 ;
if ( F_3 ( V_13 -> V_117 >= V_118 ) ) {
F_13 ( L_18
L_19 ) ;
V_18 = - V_43 ;
goto V_80;
}
V_116 = & V_13 -> V_119 [ V_13 -> V_117 ++ ] ;
V_116 -> V_121 = V_123 ;
V_18 = F_32 ( V_13 , V_45 , false , & V_116 -> V_122 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_80;
* V_113 = V_114 ;
return 0 ;
V_80:
F_7 ( & V_114 ) ;
* V_113 = NULL ;
return V_18 ;
}
static int F_63 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_125 {
T_2 V_41 ;
T_10 V_126 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_125 ,
V_41 ) ;
return F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_126 . V_83 ,
NULL ) ;
}
static int F_64 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_127 {
T_2 V_41 ;
T_11 V_126 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_127 ,
V_41 ) ;
if ( F_3 ( V_27 -> V_69 ) ) {
struct {
T_2 V_41 ;
T_10 V_126 ;
} V_128 ;
F_45 ( sizeof( V_128 ) != sizeof( * V_84 ) ) ;
V_128 . V_41 . V_39 = V_129 ;
V_128 . V_41 . V_130 = V_84 -> V_41 . V_130 ;
V_128 . V_126 . V_83 = V_84 -> V_126 . V_83 ;
V_128 . V_126 . type = V_84 -> V_126 . type ;
memcpy ( V_84 , & V_128 , sizeof( * V_84 ) ) ;
return F_63 ( V_27 , V_13 , V_41 ) ;
}
return F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_126 . V_83 ,
NULL ) ;
}
static int F_65 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_114 ;
struct V_131 {
T_2 V_41 ;
T_12 V_126 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_131 , V_41 ) ;
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 ,
& V_84 -> V_126 . V_132 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_55 ( V_27 , & V_114 -> V_53 , V_13 ) ;
F_7 ( & V_114 ) ;
return V_18 ;
}
static int F_66 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_114 ;
struct V_131 {
T_2 V_41 ;
T_13 V_126 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_131 , V_41 ) ;
if ( V_27 -> V_69 ) {
struct {
T_2 V_41 ;
T_12 V_126 ;
} V_128 ;
F_45 ( sizeof( V_128 ) != sizeof( * V_84 ) ) ;
V_128 . V_41 . V_39 = V_133 ;
V_128 . V_41 . V_130 = V_84 -> V_41 . V_130 ;
V_128 . V_126 . V_83 = V_84 -> V_126 . V_83 ;
V_128 . V_126 . type = V_84 -> V_126 . type ;
V_128 . V_126 . V_132 = V_84 -> V_126 . V_134 . V_124 ;
V_128 . V_126 . V_34 = V_84 -> V_126 . V_134 . V_34 ;
memcpy ( V_84 , & V_128 , sizeof( * V_84 ) ) ;
return F_65 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_84 -> V_126 . V_134 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_55 ( V_27 , & V_114 -> V_53 , V_13 ) ;
F_7 ( & V_114 ) ;
return V_18 ;
}
static int F_67 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_114 ;
struct V_131 {
T_2 V_41 ;
T_14 V_126 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_131 , V_41 ) ;
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 ,
& V_84 -> V_126 . V_132 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_114 ) ;
return 0 ;
}
static int F_68 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_114 ;
struct V_131 {
T_2 V_41 ;
T_15 V_126 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_131 , V_41 ) ;
if ( V_27 -> V_69 ) {
struct {
T_2 V_41 ;
T_14 V_126 ;
} V_128 ;
F_45 ( sizeof( V_128 ) != sizeof( * V_84 ) ) ;
V_128 . V_41 . V_39 = V_135 ;
V_128 . V_41 . V_130 = V_84 -> V_41 . V_130 ;
V_128 . V_126 . V_83 = V_84 -> V_126 . V_83 ;
V_128 . V_126 . type = V_84 -> V_126 . type ;
V_128 . V_126 . V_132 = V_84 -> V_126 . V_134 . V_124 ;
V_128 . V_126 . V_34 = V_84 -> V_126 . V_134 . V_34 ;
memcpy ( V_84 , & V_128 , sizeof( * V_84 ) ) ;
return F_67 ( V_27 , V_13 , V_41 ) ;
}
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_84 -> V_126 . V_134 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_114 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_8 * V_114 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_138 {
T_2 V_41 ;
T_16 V_139 ;
} * V_84 ;
int V_18 ;
T_17 * V_140 ;
T_1 V_141 ;
V_84 = F_11 ( V_41 , struct V_138 , V_41 ) ;
V_140 = ( T_17 * ) ( ( unsigned long ) & V_84 -> V_139 +
V_41 -> V_130 - sizeof( * V_140 ) ) ;
if ( F_3 ( V_140 -> V_142 != sizeof( * V_140 ) ) ) {
F_13 ( L_21 ) ;
return - V_43 ;
}
V_18 = F_62 ( V_27 , V_13 ,
& V_84 -> V_139 . V_143 . V_123 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_141 = V_114 -> V_53 . V_106 * V_144 ;
if ( F_3 ( V_84 -> V_139 . V_143 . V_123 . V_34 > V_141 ) ) {
F_13 ( L_22 ) ;
return - V_43 ;
}
V_141 -= V_84 -> V_139 . V_143 . V_123 . V_34 ;
if ( F_3 ( V_140 -> V_145 > V_141 ) )
V_140 -> V_145 = V_141 ;
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 , & V_84 -> V_139 . V_146 . V_93 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) ) {
if ( F_3 ( V_18 != - V_61 ) )
F_13 ( L_23 ) ;
goto V_147;
}
V_137 = F_70 ( V_13 -> V_74 [ V_90 ] . V_7 ) ;
F_71 ( V_137 , V_13 -> V_78 -> V_79 , & V_114 -> V_53 ,
V_41 ) ;
V_147:
F_7 ( & V_114 ) ;
return V_18 ;
}
static int F_72 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_148 {
T_2 V_41 ;
T_18 V_87 ;
} * V_84 ;
T_19 * V_149 = ( T_19 * ) (
( unsigned long ) V_41 + sizeof( * V_84 ) ) ;
T_20 * V_150 ;
T_1 V_151 ;
T_1 V_152 ;
int V_18 ;
V_18 = F_48 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_84 = F_11 ( V_41 , struct V_148 , V_41 ) ;
V_152 = ( V_41 -> V_130 - sizeof( V_84 -> V_87 ) ) / sizeof( * V_149 ) ;
if ( F_3 ( V_84 -> V_87 . V_153 > V_152 ) ) {
F_13 ( L_24 ) ;
return - V_43 ;
}
for ( V_151 = 0 ; V_151 < V_84 -> V_87 . V_153 ; ++ V_151 , ++ V_149 ) {
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_149 -> V_154 . V_155 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_152 = ( V_41 -> V_130 - sizeof( V_84 -> V_87 ) -
V_84 -> V_87 . V_153 * sizeof( * V_149 ) ) / sizeof( * V_150 ) ;
if ( F_3 ( V_84 -> V_87 . V_156 > V_152 ) ) {
F_13 ( L_25 ) ;
return - V_43 ;
}
V_150 = ( T_20 * ) V_149 ;
for ( V_151 = 0 ; V_151 < V_84 -> V_87 . V_156 ; ++ V_151 , ++ V_150 ) {
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_150 -> V_157 . V_155 , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
return 0 ;
}
static int F_73 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_158 {
T_2 V_41 ;
T_21 V_159 ;
} * V_84 ;
T_22 * V_160 = ( T_22 * )
( ( unsigned long ) V_41 + V_41 -> V_130 + sizeof( V_41 ) ) ;
T_22 * V_161 = ( T_22 * )
( ( unsigned long ) V_41 + sizeof( struct V_158 ) ) ;
struct V_4 * V_88 ;
struct V_4 * V_89 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_158 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_159 . V_83 ,
& V_88 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
for (; V_161 < V_160 ; ++ V_161 ) {
if ( F_9 ( V_161 -> V_162 != V_163 ) )
continue;
V_18 = F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_161 -> V_164 , & V_89 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_69 ) {
struct V_94 V_33 ;
V_33 . V_28 = V_88 -> V_7 ;
V_33 . V_7 = V_89 ? V_89 -> V_7 : NULL ;
V_33 . V_95 = V_165 ;
V_33 . V_97 . V_166 = V_161 -> V_167 ;
F_50 ( V_88 -> V_10 ,
& V_33 ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_168 )
{
struct V_8 * V_114 ;
int V_18 ;
struct {
T_1 V_41 ;
T_23 V_87 ;
} * V_84 = V_168 ;
V_18 = F_62 ( V_27 , V_13 ,
& V_84 -> V_87 . V_123 ,
& V_114 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_7 ( & V_114 ) ;
return V_18 ;
}
static int F_75 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
enum V_62 V_63 ,
const struct V_70
* V_71 ,
T_1 * V_169 ,
T_1 * V_170 ,
unsigned long V_171 )
{
int V_18 ;
struct V_8 * V_172 ;
struct V_4 * V_48 ;
V_18 = F_42 ( V_27 , V_13 , V_63 ,
V_71 , V_169 , & V_48 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_60 ( V_27 , V_13 , V_170 , & V_172 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_48 -> V_20 )
V_48 -> V_59 = true ;
F_7 ( & V_48 -> V_9 ) ;
V_48 -> V_9 = V_172 ;
V_48 -> V_11 = V_171 ;
return 0 ;
}
static int F_76 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_173 {
T_2 V_41 ;
T_24 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_173 , V_41 ) ;
return F_75 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_93 , & V_84 -> V_87 . V_132 ,
0 ) ;
}
static int F_77 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_25 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_175 . V_93 , NULL ) ;
}
static int F_78 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_26 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_93 , NULL ) ;
}
static int F_79 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_27 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_175 . V_93 , NULL ) ;
}
static int F_80 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_28 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_93 , NULL ) ;
}
static int F_81 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_29 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_175 . V_93 , NULL ) ;
}
static int F_82 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_174 {
T_2 V_41 ;
T_30 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_174 , V_41 ) ;
return F_42 ( V_27 , V_13 , V_90 ,
V_91 ,
& V_84 -> V_87 . V_93 , NULL ) ;
}
static int F_83 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_176 {
T_2 V_41 ;
T_31 V_87 ;
} * V_84 ;
int V_18 ;
T_32 V_130 ;
struct V_4 * V_5 ;
V_84 = F_11 ( V_41 , struct V_176 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_87 . V_83 ,
& V_5 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_69 ) )
return 0 ;
V_130 = V_84 -> V_41 . V_130 - sizeof( V_84 -> V_87 ) ;
V_18 = F_84 ( V_27 ,
F_85 ( V_5 -> V_7 ) ,
V_84 -> V_87 . V_177 , V_84 + 1 ,
V_84 -> V_87 . type , V_130 ,
& V_13 -> V_178 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_66 ,
NULL , & V_84 -> V_41 . V_39 -
V_13 -> V_67 ) ;
return 0 ;
}
static int F_86 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_179 {
T_2 V_41 ;
T_33 V_87 ;
} * V_84 ;
int V_18 ;
struct V_4 * V_5 ;
V_84 = F_11 ( V_41 , struct V_179 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_87 . V_83 ,
& V_5 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( F_3 ( ! V_27 -> V_69 ) )
return 0 ;
V_18 = F_87 ( F_85 ( V_5 -> V_7 ) ,
V_84 -> V_87 . V_177 ,
V_84 -> V_87 . type ,
& V_13 -> V_178 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
return F_23 ( & V_13 -> V_66 ,
NULL , & V_84 -> V_41 . V_39 -
V_13 -> V_67 ) ;
return 0 ;
}
static int F_88 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_180 {
T_2 V_41 ;
T_34 V_87 ;
} * V_84 ;
struct V_4 * V_88 , * V_89 = NULL ;
struct V_94 V_33 ;
struct V_6 * V_7 = NULL ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_180 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_87 . V_83 ,
& V_88 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( ! V_27 -> V_69 )
return 0 ;
if ( V_84 -> V_87 . V_177 != V_75 ) {
V_7 = F_89
( F_85 ( V_88 -> V_7 ) ,
V_84 -> V_87 . V_177 ,
V_84 -> V_87 . type ) ;
if ( ! F_90 ( V_7 ) ) {
V_18 = F_39 ( V_27 , V_13 ,
V_181 ,
& V_84 -> V_87 . V_177 , V_7 ,
& V_89 ) ;
F_21 ( & V_7 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
}
if ( ! V_89 ) {
V_18 = F_42 ( V_27 , V_13 ,
V_181 ,
V_182 ,
& V_84 -> V_87 . V_177 , & V_89 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
}
V_33 . V_28 = V_88 -> V_7 ;
V_33 . V_7 = V_89 ? V_89 -> V_7 : NULL ;
V_33 . V_95 = V_183 ;
V_33 . V_97 . V_184 = V_84 -> V_87 . type ;
return F_50 ( V_88 -> V_10 , & V_33 ) ;
}
static int F_91 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_185 {
T_2 V_41 ;
T_35 V_87 ;
} * V_84 ;
int V_18 ;
V_84 = F_11 ( V_41 , struct V_185 ,
V_41 ) ;
V_18 = F_42 ( V_27 , V_13 , V_68 ,
V_85 , & V_84 -> V_87 . V_83 ,
NULL ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
if ( V_27 -> V_69 )
V_41 -> V_39 = V_186 ;
return 0 ;
}
static int F_92 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
T_2 * V_41 )
{
struct V_187 {
T_2 V_41 ;
T_36 V_87 ;
} * V_84 ;
V_84 = F_11 ( V_41 , struct V_187 ,
V_41 ) ;
return F_75 ( V_27 , V_13 , V_181 ,
V_182 ,
& V_84 -> V_87 . V_177 , & V_84 -> V_87 . V_132 ,
V_84 -> V_87 . V_188 ) ;
}
static int F_93 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_168 , T_1 * V_130 )
{
T_1 V_189 = * V_130 ;
T_1 V_190 ;
V_190 = F_94 ( ( ( T_1 * ) V_168 ) [ 0 ] ) ;
switch ( V_190 ) {
case V_191 :
* V_130 = sizeof( T_1 ) + sizeof( V_192 ) ;
break;
case V_193 :
* V_130 = sizeof( T_1 ) + sizeof( T_23 ) ;
break;
case V_194 :
* V_130 = sizeof( T_1 ) + sizeof( V_195 ) ;
break;
case V_196 :
* V_130 = sizeof( T_1 ) + sizeof( V_195 ) ;
break;
default:
F_13 ( L_26 , V_190 ) ;
return - V_43 ;
}
if ( * V_130 > V_189 ) {
F_13 ( L_27
L_28 , V_190 ) ;
return - V_43 ;
}
if ( F_3 ( ! V_13 -> V_197 ) ) {
F_13 ( L_29 , V_190 ) ;
return - V_198 ;
}
if ( V_190 == V_193 )
return F_74 ( V_27 , V_13 , V_168 ) ;
return 0 ;
}
static int F_95 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_168 , T_1 * V_130 )
{
T_1 V_190 ;
T_1 V_189 = * V_130 ;
T_2 * V_41 = ( T_2 * ) V_168 ;
int V_18 ;
const struct V_199 * V_31 ;
bool V_200 = V_27 -> V_201 & V_202 ;
V_190 = F_94 ( ( ( T_1 * ) V_168 ) [ 0 ] ) ;
if ( F_3 ( V_190 < V_203 ) )
return F_93 ( V_27 , V_13 , V_168 , V_130 ) ;
V_190 = F_94 ( V_41 -> V_39 ) ;
* V_130 = F_94 ( V_41 -> V_130 ) + sizeof( T_2 ) ;
V_190 -= V_204 ;
if ( F_3 ( * V_130 > V_189 ) )
goto V_205;
if ( F_3 ( V_190 >= V_206 - V_204 ) )
goto V_205;
V_31 = & V_207 [ V_190 ] ;
if ( F_3 ( ! V_31 -> V_208 ) )
goto V_205;
if ( F_3 ( ! V_31 -> V_209 && ! V_13 -> V_197 ) )
goto V_210;
if ( F_3 ( V_31 -> V_211 && V_200 ) )
goto V_212;
if ( F_3 ( V_31 -> V_213 && ! V_200 ) )
goto V_214;
V_18 = V_31 -> V_208 ( V_27 , V_13 , V_41 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_205;
return 0 ;
V_205:
F_13 ( L_30 ,
V_190 + V_204 ) ;
return - V_43 ;
V_210:
F_13 ( L_31 ,
V_190 + V_204 ) ;
return - V_198 ;
V_212:
F_13 ( L_32 ,
V_190 + V_204 ) ;
return - V_43 ;
V_214:
F_13 ( L_33 ,
V_190 + V_204 ) ;
return - V_43 ;
}
static int F_96 ( struct V_26 * V_27 ,
struct V_12 * V_13 ,
void * V_168 ,
T_1 V_130 )
{
T_37 V_215 = V_130 ;
int V_18 ;
V_13 -> V_67 = V_168 ;
while ( V_215 > 0 ) {
V_130 = V_215 ;
V_18 = F_95 ( V_27 , V_13 , V_168 , & V_130 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_168 = ( void * ) ( ( unsigned long ) V_168 + V_130 ) ;
V_215 -= V_130 ;
}
if ( F_3 ( V_215 != 0 ) ) {
F_13 ( L_34 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_97 ( struct V_12 * V_13 )
{
V_13 -> V_117 = 0 ;
}
static void F_98 ( struct V_12 * V_13 )
{
T_1 V_151 ;
struct V_115 * V_116 ;
struct V_51 * V_216 ;
struct V_44 * V_45 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_117 ; ++ V_151 ) {
V_116 = & V_13 -> V_119 [ V_151 ] ;
V_216 = & V_13 -> V_54 [ V_116 -> V_122 ] . V_53 ;
V_45 = V_216 -> V_45 ;
switch ( V_45 -> V_217 . V_218 ) {
case V_219 :
V_116 -> V_121 -> V_34 += V_45 -> V_34 ;
V_116 -> V_121 -> V_124 = V_220 ;
break;
case V_221 :
V_116 -> V_121 -> V_124 = V_45 -> V_217 . V_222 ;
break;
case V_223 :
* V_116 -> V_120 = V_45 -> V_217 . V_222 ;
break;
default:
F_99 () ;
}
}
F_97 ( V_13 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_224 ;
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
struct V_49 * V_31 , * V_225 ;
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
if ( V_45 == V_27 -> V_109 ||
( V_45 == V_27 -> V_108 &&
V_27 -> V_110 ) )
return 0 ;
if ( V_46 )
return F_105 ( V_45 , & V_226 , true , false ) ;
V_18 = F_105 ( V_45 , & V_227 , true , false ) ;
if ( F_9 ( V_18 == 0 || V_18 == - V_61 ) )
return V_18 ;
F_106 ( L_35 ) ;
V_18 = F_105 ( V_45 , & V_228 , true , false ) ;
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
T_1 V_130 )
{
if ( F_9 ( V_13 -> V_229 >= V_130 ) )
return 0 ;
if ( V_13 -> V_229 == 0 )
V_13 -> V_229 = V_230 ;
while ( V_13 -> V_229 < V_130 ) {
V_13 -> V_229 =
F_109 ( V_13 -> V_229 +
( V_13 -> V_229 >> 1 ) ) ;
}
if ( V_13 -> V_231 != NULL )
F_110 ( V_13 -> V_231 ) ;
V_13 -> V_231 = F_111 ( V_13 -> V_229 ) ;
if ( V_13 -> V_231 == NULL ) {
F_13 ( L_36 ) ;
V_13 -> V_229 = 0 ;
return - V_22 ;
}
return 0 ;
}
int F_112 ( struct V_232 * V_233 ,
struct V_26 * V_27 ,
struct V_234 * * V_235 ,
T_1 * V_236 )
{
T_1 V_237 ;
int V_18 ;
bool V_238 = false ;
F_45 ( V_236 != NULL && V_233 == NULL ) ;
V_18 = F_113 ( V_27 , & V_237 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_13 ( L_37 ) ;
V_238 = true ;
}
if ( V_236 != NULL )
V_18 = F_114 ( V_233 , V_27 -> V_239 ,
V_237 , V_235 , V_236 ) ;
else
V_18 = F_115 ( V_27 -> V_239 , V_237 , V_235 ) ;
if ( F_3 ( V_18 != 0 && ! V_238 ) ) {
( void ) F_116 ( V_27 , false , false ,
V_237 , false ,
V_240 ) ;
* V_235 = NULL ;
}
return 0 ;
}
void
F_117 ( struct V_26 * V_27 ,
struct V_241 * V_242 ,
int V_18 ,
struct V_243 T_38 * V_244 ,
struct V_234 * V_245 ,
T_1 V_246 )
{
struct V_243 V_247 ;
if ( V_244 == NULL )
return;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . error = V_18 ;
if ( V_18 == 0 ) {
F_45 ( V_245 == NULL ) ;
V_247 . V_77 = V_246 ;
V_247 . V_248 = V_245 -> V_53 . V_248 ;
F_118 ( V_27 , & V_27 -> V_249 ) ;
V_247 . V_250 = V_27 -> V_251 ;
}
V_18 = F_119 ( V_244 , & V_247 ,
sizeof( V_247 ) ) ;
if ( F_3 ( V_18 != 0 ) && ( V_247 . error == 0 ) ) {
F_120 ( V_242 -> V_79 ,
V_246 , V_252 ) ;
F_13 ( L_38 ) ;
( void ) F_121 ( V_245 , false , false ,
V_240 ) ;
}
}
int F_122 ( struct V_232 * V_233 ,
struct V_26 * V_27 ,
void T_38 * V_253 ,
void * V_254 ,
T_1 V_255 ,
T_39 V_256 ,
struct V_243 T_38 * V_244 ,
struct V_234 * * V_257 )
{
struct V_12 * V_13 = & V_27 -> V_28 ;
struct V_234 * V_245 = NULL ;
struct V_6 * V_81 ;
struct V_1 V_25 ;
struct V_258 V_259 ;
T_1 V_77 ;
void * V_84 ;
int V_18 ;
V_18 = F_123 ( & V_27 -> V_260 ) ;
if ( F_3 ( V_18 != 0 ) )
return - V_61 ;
if ( V_254 == NULL ) {
V_13 -> V_197 = false ;
V_18 = F_108 ( V_13 , V_255 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_261;
V_18 = F_124 ( V_13 -> V_231 ,
V_253 , V_255 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_262 ;
F_13 ( L_39 ) ;
goto V_261;
}
V_254 = V_13 -> V_231 ;
} else
V_13 -> V_197 = true ;
V_13 -> V_78 = V_241 ( V_233 ) ;
V_13 -> V_117 = 0 ;
V_13 -> V_55 = 0 ;
F_41 ( & V_13 -> V_25 ) ;
V_13 -> V_105 = V_27 -> V_109 ;
V_13 -> V_104 = NULL ;
V_13 -> V_107 = false ;
memset ( V_13 -> V_74 , 0 , sizeof( V_13 -> V_74 ) ) ;
F_41 ( & V_13 -> V_58 ) ;
F_41 ( & V_13 -> V_66 ) ;
if ( ! V_13 -> V_263 ) {
V_18 = F_125 ( & V_13 -> V_19 , V_264 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_261;
V_13 -> V_263 = true ;
}
F_41 ( & V_13 -> V_178 ) ;
F_41 ( & V_25 ) ;
V_18 = F_96 ( V_27 , V_13 , V_254 ,
V_255 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_265;
V_18 = F_34 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_265;
V_18 = F_126 ( & V_259 , & V_13 -> V_58 ,
true , NULL ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_266;
V_18 = F_107 ( V_27 , V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_266;
V_18 = F_37 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_266;
if ( V_256 ) {
V_18 = F_127 ( V_27 , & V_27 -> V_249 . V_267 ,
V_256 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_266;
}
V_18 = F_123 ( & V_27 -> V_32 ) ;
if ( F_3 ( V_18 != 0 ) ) {
V_18 = - V_61 ;
goto V_266;
}
if ( V_27 -> V_69 ) {
V_18 = F_46 ( V_13 ) ;
if ( F_3 ( V_18 != 0 ) )
goto V_268;
}
V_84 = F_128 ( V_27 , V_255 ) ;
if ( F_3 ( V_84 == NULL ) ) {
F_13 ( L_40 ) ;
V_18 = - V_22 ;
goto V_268;
}
F_98 ( V_13 ) ;
memcpy ( V_84 , V_254 , V_255 ) ;
F_28 ( V_84 , & V_13 -> V_66 ) ;
F_25 ( & V_13 -> V_66 ) ;
F_129 ( V_27 , V_255 ) ;
F_56 ( V_27 , V_13 ) ;
V_18 = F_112 ( V_233 , V_27 ,
& V_245 ,
( V_244 ) ? & V_77 : NULL ) ;
if ( V_18 != 0 )
F_13 ( L_37 ) ;
F_1 ( & V_13 -> V_25 , false ) ;
F_22 ( & V_27 -> V_32 ) ;
F_130 ( & V_259 , & V_13 -> V_58 ,
( void * ) V_245 ) ;
if ( F_3 ( V_27 -> V_109 != NULL &&
! V_27 -> V_112 ) )
F_131 ( V_27 , V_245 ) ;
F_102 ( V_13 ) ;
F_117 ( V_27 , V_241 ( V_233 ) , V_18 ,
V_244 , V_245 , V_77 ) ;
if ( F_3 ( V_257 != NULL ) ) {
* V_257 = V_245 ;
V_245 = NULL ;
} else if ( F_9 ( V_245 != NULL ) ) {
F_132 ( & V_245 ) ;
}
F_133 ( & V_13 -> V_25 , & V_25 ) ;
F_134 ( & V_13 -> V_178 ) ;
F_22 ( & V_27 -> V_260 ) ;
F_100 ( & V_25 ) ;
return 0 ;
V_268:
F_22 ( & V_27 -> V_32 ) ;
V_266:
F_135 ( & V_259 , & V_13 -> V_58 ) ;
V_265:
F_1 ( & V_13 -> V_25 , true ) ;
F_25 ( & V_13 -> V_66 ) ;
F_97 ( V_13 ) ;
F_102 ( V_13 ) ;
if ( F_3 ( V_27 -> V_109 != NULL &&
! V_27 -> V_112 ) )
F_131 ( V_27 , NULL ) ;
V_261:
F_133 ( & V_13 -> V_25 , & V_25 ) ;
V_81 = V_13 -> V_81 ;
V_13 -> V_81 = NULL ;
F_136 ( & V_13 -> V_178 ) ;
F_22 ( & V_27 -> V_260 ) ;
F_100 ( & V_25 ) ;
if ( F_3 ( V_81 != NULL ) )
F_21 ( & V_81 ) ;
return V_18 ;
}
static void F_137 ( struct V_26 * V_27 )
{
F_13 ( L_41 ) ;
( void ) F_116 ( V_27 , false , true , 0 , false , 10 * V_269 ) ;
F_58 ( V_27 -> V_109 , false ) ;
F_58 ( V_27 -> V_108 , false ) ;
V_27 -> V_110 = false ;
}
void F_131 ( struct V_26 * V_27 ,
struct V_234 * V_245 )
{
int V_18 = 0 ;
struct V_1 V_270 ;
struct V_51 V_271 , V_272 ;
struct V_234 * V_273 = NULL ;
struct V_258 V_259 ;
if ( V_27 -> V_109 == NULL )
goto V_261;
F_41 ( & V_270 ) ;
V_271 . V_45 = F_33 ( V_27 -> V_109 ) ;
V_271 . V_57 = false ;
F_15 ( & V_271 . V_24 , & V_270 ) ;
V_272 . V_45 = F_33 ( V_27 -> V_108 ) ;
V_272 . V_57 = false ;
F_15 ( & V_272 . V_24 , & V_270 ) ;
V_18 = F_126 ( & V_259 , & V_270 ,
false , NULL ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_137 ( V_27 ) ;
goto V_274;
}
if ( V_27 -> V_112 ) {
F_45 ( V_245 != NULL ) ;
V_18 = F_57 ( V_27 , V_27 -> V_111 ) ;
if ( F_3 ( V_18 != 0 ) ) {
F_137 ( V_27 ) ;
goto V_275;
}
V_27 -> V_112 = false ;
}
F_58 ( V_27 -> V_109 , false ) ;
F_58 ( V_27 -> V_108 , false ) ;
V_27 -> V_110 = false ;
if ( V_245 == NULL ) {
( void ) F_112 ( NULL , V_27 , & V_273 ,
NULL ) ;
V_245 = V_273 ;
}
F_130 ( & V_259 , & V_270 , ( void * ) V_245 ) ;
if ( V_273 != NULL )
F_132 ( & V_273 ) ;
F_59 ( & V_272 . V_45 ) ;
F_59 ( & V_271 . V_45 ) ;
F_59 ( & V_27 -> V_109 ) ;
V_261:
return;
V_275:
F_135 ( & V_259 , & V_270 ) ;
V_274:
F_59 ( & V_272 . V_45 ) ;
F_59 ( & V_271 . V_45 ) ;
F_59 ( & V_27 -> V_109 ) ;
}
void F_138 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_260 ) ;
if ( V_27 -> V_112 )
F_131 ( V_27 , NULL ) ;
F_22 ( & V_27 -> V_260 ) ;
}
int F_139 ( struct V_276 * V_277 , void * V_278 ,
struct V_232 * V_233 )
{
struct V_26 * V_27 = F_140 ( V_277 ) ;
struct V_279 * V_280 = (struct V_279 * ) V_278 ;
int V_18 ;
if ( F_3 ( V_280 -> V_281 != V_282 ) ) {
F_13 ( L_42 ) ;
F_13 ( L_43
L_44 ) ;
return - V_43 ;
}
V_18 = F_141 ( & V_27 -> V_283 , true ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_122 ( V_233 , V_27 ,
( void T_38 * ) ( unsigned long ) V_280 -> V_284 ,
NULL , V_280 -> V_255 , V_280 -> V_256 ,
( void T_38 * ) ( unsigned long ) V_280 -> V_247 ,
NULL ) ;
F_142 ( & V_27 -> V_283 ) ;
if ( F_3 ( V_18 != 0 ) )
return V_18 ;
F_143 ( V_27 ) ;
return 0 ;
}
