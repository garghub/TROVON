static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 ;
F_2 (val, list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 =
V_3 ? NULL : V_5 -> V_9 ;
F_3 ( V_7 , V_9 ,
V_5 -> V_10 ) ;
F_4 ( & V_5 -> V_9 ) ;
}
}
static int F_5 ( struct V_11 * V_12 ,
struct V_6 * V_7 ,
struct V_4 * * V_13 )
{
struct V_4 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
if ( F_6 ( F_7 ( & V_12 -> V_18 , ( unsigned long ) V_7 ,
& V_16 ) == 0 ) ) {
V_14 = F_8 ( V_16 , struct V_4 , V_16 ) ;
V_14 -> V_19 = false ;
if ( F_9 ( V_13 != NULL ) )
* V_13 = V_14 ;
return 0 ;
}
V_14 = F_10 ( sizeof( * V_14 ) , V_20 ) ;
if ( F_9 ( V_14 == NULL ) ) {
F_11 ( L_1
L_2 ) ;
return - V_21 ;
}
V_14 -> V_16 . V_22 = ( unsigned long ) V_7 ;
V_17 = F_12 ( & V_12 -> V_18 , & V_14 -> V_16 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_11 ( L_3
L_2 ) ;
F_13 ( V_14 ) ;
return V_17 ;
}
F_14 ( & V_14 -> V_23 , & V_12 -> V_24 ) ;
V_14 -> V_7 = F_15 ( V_7 ) ;
V_14 -> V_19 = true ;
if ( F_9 ( V_13 != NULL ) )
* V_13 = V_14 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
unsigned long V_25 )
{
struct V_26 * V_27 ;
V_27 = F_17 ( sizeof( * V_27 ) , V_20 ) ;
if ( F_9 ( V_27 == NULL ) ) {
F_11 ( L_4 ) ;
return - V_21 ;
}
V_27 -> V_7 = V_7 ;
V_27 -> V_25 = V_25 ;
F_14 ( & V_27 -> V_23 , V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_27 , * V_28 ;
F_19 (rel, n, list, head) {
F_20 ( & V_27 -> V_23 ) ;
F_13 ( V_27 ) ;
}
}
static void F_21 ( T_1 * V_29 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 ;
F_2 (rel, list, head)
V_29 [ V_27 -> V_25 ] = V_27 -> V_7 -> V_30 ;
}
static int F_22 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
return F_23 ( V_34 ) ? : - V_35 ;
}
static int F_24 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
return 0 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_36 * V_37 ,
T_1 * V_38 )
{
T_1 V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_15 * V_16 ;
int V_17 ;
if ( F_6 ( F_7 ( & V_12 -> V_18 , ( unsigned long ) V_37 ,
& V_16 ) == 0 ) ) {
V_41 = F_8 ( V_16 , struct V_40 ,
V_16 ) ;
V_43 = & V_41 -> V_44 ;
V_39 = V_41 - V_12 -> V_45 ;
} else {
V_39 = V_12 -> V_46 ;
if ( F_9 ( V_39 >= V_47 ) ) {
F_11 ( L_5
L_6 ) ;
return - V_35 ;
}
V_41 = & V_12 -> V_45 [ V_39 ] ;
V_41 -> V_16 . V_22 = ( unsigned long ) V_37 ;
V_17 = F_12 ( & V_12 -> V_18 , & V_41 -> V_16 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_11 ( L_7
L_2 ) ;
return V_17 ;
}
++ V_12 -> V_46 ;
V_43 = & V_41 -> V_44 ;
V_43 -> V_37 = F_26 ( V_37 ) ;
V_43 -> V_48 = false ;
F_14 ( & V_43 -> V_23 , & V_12 -> V_49 ) ;
}
V_12 -> V_50 |= V_51 ;
if ( V_38 )
* V_38 = V_39 ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_4 * V_5 ;
int V_17 ;
F_2 (val, &sw_context->resource_list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
V_17 = F_28 ( V_7 , V_5 -> V_52 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
if ( V_7 -> V_53 ) {
struct V_36 * V_37 = & V_7 -> V_53 -> V_44 ;
V_17 = F_25
( V_12 , V_37 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
}
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_4 * V_5 ;
int V_17 ;
F_2 (val, &sw_context->resource_list, head) {
struct V_6 * V_7 = V_5 -> V_7 ;
V_17 = F_30 ( V_7 ) ;
if ( F_9 ( V_17 != 0 ) ) {
if ( V_17 != - V_54 )
F_11 ( L_8 ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_31 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
enum V_55 V_56 ,
const struct V_57 * V_58 ,
T_1 * V_30 ,
struct V_4 * * V_59 )
{
struct V_60 * V_61 =
& V_12 -> V_62 [ V_56 ] ;
struct V_6 * V_7 ;
struct V_4 * V_14 ;
int V_17 ;
if ( * V_30 == V_63 )
return 0 ;
if ( F_6 ( V_61 -> V_64 && * V_30 == V_61 -> V_65 ) ) {
const struct V_6 * V_7 = V_61 -> V_7 ;
V_61 -> V_14 -> V_19 = false ;
if ( V_59 )
* V_59 = V_61 -> V_14 ;
return F_16
( & V_12 -> V_66 , V_7 ,
V_30 - V_12 -> V_67 ) ;
}
V_17 = F_32 ( V_32 ,
V_12 -> V_68 ,
* V_30 ,
V_58 ,
& V_7 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_11 ( L_9 ,
( unsigned ) * V_30 ) ;
F_33 () ;
return V_17 ;
}
V_61 -> V_64 = true ;
V_61 -> V_7 = V_7 ;
V_61 -> V_65 = * V_30 ;
V_17 = F_16 ( & V_12 -> V_66 ,
V_7 ,
V_30 - V_12 -> V_67 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_69;
V_17 = F_5 ( V_12 , V_7 , & V_14 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_69;
V_61 -> V_14 = V_14 ;
if ( V_59 )
* V_59 = V_14 ;
F_34 ( & V_7 ) ;
return 0 ;
V_69:
F_35 ( V_12 -> V_70 != NULL ) ;
V_12 -> V_70 = V_7 ;
return V_17 ;
}
static int F_36 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_71 {
T_2 V_33 ;
T_3 V_72 ;
} * V_73 ;
V_73 = F_8 ( V_33 , struct V_71 , V_33 ) ;
return F_31 ( V_32 , V_12 , V_74 ,
V_75 , & V_73 -> V_72 , NULL ) ;
}
static int F_37 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_76 {
T_2 V_33 ;
T_4 V_77 ;
} * V_73 ;
int V_17 ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_73 = F_8 ( V_33 , struct V_76 , V_33 ) ;
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_80 . V_81 , NULL ) ;
return V_17 ;
}
static int F_38 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_76 {
T_2 V_33 ;
T_5 V_77 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_76 , V_33 ) ;
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_82 . V_81 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
return F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_83 . V_81 , NULL ) ;
}
static int F_39 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_76 {
T_2 V_33 ;
T_6 V_77 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_76 , V_33 ) ;
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_82 . V_81 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
return F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_83 . V_81 , NULL ) ;
}
static int F_40 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_76 {
T_2 V_33 ;
T_7 V_77 ;
} * V_73 ;
V_73 = F_8 ( V_33 , struct V_76 , V_33 ) ;
if ( F_9 ( ! V_12 -> V_84 ) ) {
F_11 ( L_10 , V_73 -> V_33 . V_30 ) ;
return - V_85 ;
}
return F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_73 -> V_77 . V_86 . V_81 , NULL ) ;
}
static int F_41 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_76 {
T_2 V_33 ;
T_8 V_77 ;
} * V_73 ;
V_73 = F_8 ( V_33 , struct V_76 , V_33 ) ;
if ( F_9 ( ! V_12 -> V_84 ) ) {
F_11 ( L_10 , V_73 -> V_33 . V_30 ) ;
return - V_85 ;
}
return F_31 ( V_32 , V_12 , V_78 ,
V_79 , & V_73 -> V_77 . V_81 ,
NULL ) ;
}
static int F_42 ( struct V_31 * V_32 ,
struct V_36 * V_87 ,
struct V_11 * V_12 )
{
struct V_60 * V_88 =
& V_12 -> V_62 [ V_74 ] ;
int V_17 ;
F_35 ( ! V_88 -> V_64 ) ;
V_12 -> V_89 = V_88 -> V_7 ;
if ( F_9 ( V_87 != V_12 -> V_90 ) ) {
if ( F_9 ( V_87 -> V_91 > 4 ) ) {
F_11 ( L_11 ) ;
return - V_35 ;
}
if ( F_9 ( V_12 -> V_90 != NULL ) ) {
V_12 -> V_92 = true ;
V_17 = F_25 ( V_12 ,
V_12 -> V_90 ,
NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
V_12 -> V_90 = V_87 ;
V_17 = F_25 ( V_12 ,
V_32 -> V_93 ,
NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
return 0 ;
}
static void F_43 ( struct V_31 * V_32 ,
struct V_11 * V_12 )
{
if ( V_12 -> V_92 ) {
struct V_60 * V_88 =
& V_12 -> V_62 [ V_74 ] ;
struct V_6 * V_94 ;
int V_17 ;
F_35 ( ! V_88 -> V_64 ) ;
V_94 = V_88 -> V_7 ;
V_17 = F_44 ( V_32 , V_94 -> V_30 ) ;
if ( F_9 ( V_17 != 0 ) )
F_11 ( L_12 ) ;
}
if ( V_32 -> V_95 != V_12 -> V_90 ) {
if ( V_32 -> V_95 ) {
F_45 ( V_32 -> V_95 , false ) ;
F_46 ( & V_32 -> V_95 ) ;
}
if ( ! V_12 -> V_92 ) {
F_45 ( V_12 -> V_90 , true ) ;
F_45 ( V_32 -> V_93 , true ) ;
V_32 -> V_96 = true ;
F_35 ( V_12 -> V_89 == NULL ) ;
V_32 -> V_97 = V_12 -> V_89 -> V_30 ;
V_32 -> V_98 = true ;
V_32 -> V_95 =
F_26 ( V_12 -> V_90 ) ;
}
}
}
static int F_47 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_9 * V_99 ,
struct V_8 * * V_100 )
{
struct V_8 * V_101 = NULL ;
struct V_36 * V_37 ;
T_1 V_65 = V_99 -> V_102 ;
struct V_103 * V_104 ;
int V_17 ;
V_17 = F_48 ( V_12 -> V_68 , V_65 , & V_101 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_11 ( L_13 ) ;
return - V_35 ;
}
V_37 = & V_101 -> V_44 ;
if ( F_9 ( V_12 -> V_105 >= V_106 ) ) {
F_11 ( L_14
L_15 ) ;
V_17 = - V_35 ;
goto V_69;
}
V_104 = & V_12 -> V_107 [ V_12 -> V_105 ++ ] ;
V_104 -> V_108 = V_99 ;
V_17 = F_25 ( V_12 , V_37 , & V_104 -> V_109 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_69;
* V_100 = V_101 ;
return 0 ;
V_69:
F_4 ( & V_101 ) ;
V_100 = NULL ;
return V_17 ;
}
static int F_49 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_110 {
T_2 V_33 ;
T_10 V_111 ;
} * V_73 ;
V_73 = F_8 ( V_33 , struct V_110 ,
V_33 ) ;
return F_31 ( V_32 , V_12 , V_74 ,
V_75 , & V_73 -> V_111 . V_72 ,
NULL ) ;
}
static int F_50 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_8 * V_101 ;
struct V_112 {
T_2 V_33 ;
T_11 V_111 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_112 , V_33 ) ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_47 ( V_32 , V_12 ,
& V_73 -> V_111 . V_113 ,
& V_101 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_42 ( V_32 , & V_101 -> V_44 , V_12 ) ;
F_4 ( & V_101 ) ;
return V_17 ;
}
static int F_51 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_8 * V_101 ;
struct V_112 {
T_2 V_33 ;
T_12 V_111 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_112 , V_33 ) ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_47 ( V_32 , V_12 ,
& V_73 -> V_111 . V_113 ,
& V_101 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
F_4 ( & V_101 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_8 * V_101 = NULL ;
struct V_114 * V_115 = NULL ;
struct V_116 {
T_2 V_33 ;
T_13 V_117 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_116 , V_33 ) ;
V_17 = F_47 ( V_32 , V_12 ,
& V_73 -> V_117 . V_118 . V_99 ,
& V_101 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 , & V_73 -> V_117 . V_119 . V_81 ,
NULL ) ;
if ( F_9 ( V_17 != 0 ) ) {
if ( F_9 ( V_17 != - V_54 ) )
F_11 ( L_16 ) ;
goto V_120;
}
V_115 = F_53 ( V_12 -> V_62 [ V_78 ] . V_7 ) ;
F_54 ( V_115 , V_12 -> V_68 , & V_101 -> V_44 , V_33 ) ;
V_120:
F_4 ( & V_101 ) ;
return V_17 ;
}
static int F_55 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_121 {
T_2 V_33 ;
T_14 V_77 ;
} * V_73 ;
T_15 * V_122 = ( T_15 * ) (
( unsigned long ) V_33 + sizeof( * V_73 ) ) ;
T_16 * V_123 ;
T_1 V_124 ;
T_1 V_125 ;
int V_17 ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_73 = F_8 ( V_33 , struct V_121 , V_33 ) ;
V_125 = ( V_33 -> V_126 - sizeof( V_73 -> V_77 ) ) / sizeof( * V_122 ) ;
if ( F_9 ( V_73 -> V_77 . V_127 > V_125 ) ) {
F_11 ( L_17 ) ;
return - V_35 ;
}
for ( V_124 = 0 ; V_124 < V_73 -> V_77 . V_127 ; ++ V_124 , ++ V_122 ) {
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_122 -> V_128 . V_129 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
V_125 = ( V_33 -> V_126 - sizeof( V_73 -> V_77 ) -
V_73 -> V_77 . V_127 * sizeof( * V_122 ) ) / sizeof( * V_123 ) ;
if ( F_9 ( V_73 -> V_77 . V_130 > V_125 ) ) {
F_11 ( L_18 ) ;
return - V_35 ;
}
V_123 = ( T_16 * ) V_122 ;
for ( V_124 = 0 ; V_124 < V_73 -> V_77 . V_130 ; ++ V_124 , ++ V_123 ) {
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_123 -> V_131 . V_129 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
return 0 ;
}
static int F_56 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_132 {
T_2 V_33 ;
T_17 V_133 ;
};
T_18 * V_134 = ( T_18 * )
( ( unsigned long ) V_33 + V_33 -> V_126 + sizeof( V_33 ) ) ;
T_18 * V_135 = ( T_18 * )
( ( unsigned long ) V_33 + sizeof( struct V_132 ) ) ;
int V_17 ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
for (; V_135 < V_134 ; ++ V_135 ) {
if ( F_6 ( V_135 -> V_136 != V_137 ) )
continue;
V_17 = F_31 ( V_32 , V_12 , V_78 ,
V_79 ,
& V_135 -> V_138 , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
return 0 ;
}
static int F_57 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
void * V_139 )
{
struct V_8 * V_101 ;
int V_17 ;
struct {
T_1 V_33 ;
T_19 V_77 ;
} * V_73 = V_139 ;
V_17 = F_47 ( V_32 , V_12 ,
& V_73 -> V_77 . V_99 ,
& V_101 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
F_4 ( & V_101 ) ;
return V_17 ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
T_2 * V_33 )
{
struct V_140 {
T_2 V_33 ;
T_20 V_77 ;
} * V_73 ;
int V_17 ;
V_73 = F_8 ( V_33 , struct V_140 ,
V_33 ) ;
V_17 = F_36 ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
return 0 ;
}
static int F_59 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
void * V_139 , T_1 * V_126 )
{
T_1 V_141 = * V_126 ;
T_1 V_142 ;
V_142 = F_60 ( ( ( T_1 * ) V_139 ) [ 0 ] ) ;
switch ( V_142 ) {
case V_143 :
* V_126 = sizeof( T_1 ) + sizeof( V_144 ) ;
break;
case V_145 :
* V_126 = sizeof( T_1 ) + sizeof( T_19 ) ;
break;
case V_146 :
* V_126 = sizeof( T_1 ) + sizeof( V_147 ) ;
break;
case V_148 :
* V_126 = sizeof( T_1 ) + sizeof( V_147 ) ;
break;
default:
F_11 ( L_19 , V_142 ) ;
return - V_35 ;
}
if ( * V_126 > V_141 ) {
F_11 ( L_20
L_21 , V_142 ) ;
return - V_35 ;
}
if ( F_9 ( ! V_12 -> V_84 ) ) {
F_11 ( L_22 , V_142 ) ;
return - V_85 ;
}
if ( V_142 == V_145 )
return F_57 ( V_32 , V_12 , V_139 ) ;
return 0 ;
}
static int F_61 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
void * V_139 , T_1 * V_126 )
{
T_1 V_142 ;
T_1 V_141 = * V_126 ;
T_2 * V_33 = ( T_2 * ) V_139 ;
int V_17 ;
V_142 = F_60 ( ( ( T_1 * ) V_139 ) [ 0 ] ) ;
if ( F_9 ( V_142 < V_149 ) )
return F_59 ( V_32 , V_12 , V_139 , V_126 ) ;
V_142 = F_60 ( V_33 -> V_30 ) ;
* V_126 = F_60 ( V_33 -> V_126 ) + sizeof( T_2 ) ;
V_142 -= V_150 ;
if ( F_9 ( * V_126 > V_141 ) )
goto V_151;
if ( F_9 ( V_142 >= V_152 - V_150 ) )
goto V_151;
V_17 = V_153 [ V_142 ] ( V_32 , V_12 , V_33 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
return 0 ;
V_151:
F_11 ( L_23 ,
V_142 + V_150 ) ;
return - V_35 ;
}
static int F_62 ( struct V_31 * V_32 ,
struct V_11 * V_12 ,
void * V_139 ,
T_1 V_126 )
{
T_21 V_154 = V_126 ;
int V_17 ;
V_12 -> V_67 = V_139 ;
while ( V_154 > 0 ) {
V_126 = V_154 ;
V_17 = F_61 ( V_32 , V_12 , V_139 , & V_126 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_139 = ( void * ) ( ( unsigned long ) V_139 + V_126 ) ;
V_154 -= V_126 ;
}
if ( F_9 ( V_154 != 0 ) ) {
F_11 ( L_24 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_63 ( struct V_11 * V_12 )
{
V_12 -> V_105 = 0 ;
}
static void F_64 ( struct V_11 * V_12 )
{
T_1 V_124 ;
struct V_103 * V_104 ;
struct V_42 * V_155 ;
struct V_36 * V_37 ;
for ( V_124 = 0 ; V_124 < V_12 -> V_105 ; ++ V_124 ) {
V_104 = & V_12 -> V_107 [ V_124 ] ;
V_155 = & V_12 -> V_45 [ V_104 -> V_109 ] . V_44 ;
V_37 = V_155 -> V_37 ;
switch ( V_37 -> V_156 . V_157 ) {
case V_158 :
V_104 -> V_108 -> V_25 += V_37 -> V_25 ;
V_104 -> V_108 -> V_102 = V_159 ;
break;
case V_160 :
V_104 -> V_108 -> V_102 = V_37 -> V_156 . V_161 ;
break;
default:
F_65 () ;
}
}
F_63 ( V_12 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_162 ;
F_19 (val, val_next, list, head) {
F_67 ( & V_5 -> V_23 ) ;
F_34 ( & V_5 -> V_7 ) ;
F_13 ( V_5 ) ;
}
}
static void F_68 ( struct V_11 * V_12 )
{
struct V_40 * V_163 , * V_164 ;
struct V_4 * V_5 ;
F_19 (entry, next, &sw_context->validate_nodes,
base.head) {
F_20 ( & V_163 -> V_44 . V_23 ) ;
F_46 ( & V_163 -> V_44 . V_37 ) ;
( void ) F_69 ( & V_12 -> V_18 , & V_163 -> V_16 ) ;
V_12 -> V_46 -- ;
}
F_35 ( V_12 -> V_46 != 0 ) ;
F_2 (val, &sw_context->resource_list, head)
( void ) F_69 ( & V_12 -> V_18 , & V_5 -> V_16 ) ;
}
static int F_70 ( struct V_31 * V_32 ,
struct V_36 * V_37 )
{
int V_17 ;
if ( V_37 == V_32 -> V_95 ||
( V_37 == V_32 -> V_93 &&
V_32 -> V_96 ) )
return 0 ;
V_17 = F_71 ( V_37 , & V_165 , true , false ) ;
if ( F_6 ( V_17 == 0 || V_17 == - V_54 ) )
return V_17 ;
F_72 ( L_25 ) ;
V_17 = F_71 ( V_37 , & V_166 , true , false ) ;
return V_17 ;
}
static int F_73 ( struct V_31 * V_32 ,
struct V_11 * V_12 )
{
struct V_40 * V_163 ;
int V_17 ;
F_2 (entry, &sw_context->validate_nodes, base.head) {
V_17 = F_70 ( V_32 , V_163 -> V_44 . V_37 ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
}
return 0 ;
}
static int F_74 ( struct V_11 * V_12 ,
T_1 V_126 )
{
if ( F_6 ( V_12 -> V_167 >= V_126 ) )
return 0 ;
if ( V_12 -> V_167 == 0 )
V_12 -> V_167 = V_168 ;
while ( V_12 -> V_167 < V_126 ) {
V_12 -> V_167 =
F_75 ( V_12 -> V_167 +
( V_12 -> V_167 >> 1 ) ) ;
}
if ( V_12 -> V_169 != NULL )
F_76 ( V_12 -> V_169 ) ;
V_12 -> V_169 = F_77 ( V_12 -> V_167 ) ;
if ( V_12 -> V_169 == NULL ) {
F_11 ( L_26 ) ;
V_12 -> V_167 = 0 ;
return - V_21 ;
}
return 0 ;
}
int F_78 ( struct V_170 * V_171 ,
struct V_31 * V_32 ,
struct V_172 * * V_173 ,
T_1 * V_174 )
{
T_1 V_175 ;
int V_17 ;
bool V_176 = false ;
F_35 ( V_174 != NULL && V_171 == NULL ) ;
V_17 = F_79 ( V_32 , & V_175 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_11 ( L_27 ) ;
V_176 = true ;
}
if ( V_174 != NULL )
V_17 = F_80 ( V_171 , V_32 -> V_177 ,
V_175 ,
V_51 ,
V_173 , V_174 ) ;
else
V_17 = F_81 ( V_32 -> V_177 , V_175 ,
V_51 ,
V_173 ) ;
if ( F_9 ( V_17 != 0 && ! V_176 ) ) {
( void ) F_82 ( V_32 , false , false ,
V_175 , false ,
V_178 ) ;
* V_173 = NULL ;
}
return 0 ;
}
void
F_83 ( struct V_31 * V_32 ,
struct V_179 * V_180 ,
int V_17 ,
struct V_181 T_22 * V_182 ,
struct V_172 * V_183 ,
T_1 V_184 )
{
struct V_181 V_185 ;
if ( V_182 == NULL )
return;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_185 . error = V_17 ;
if ( V_17 == 0 ) {
F_35 ( V_183 == NULL ) ;
V_185 . V_65 = V_184 ;
V_185 . V_186 = V_183 -> V_186 ;
F_84 ( V_32 , & V_32 -> V_187 ) ;
V_185 . V_188 = V_32 -> V_189 ;
}
V_17 = F_85 ( V_182 , & V_185 ,
sizeof( V_185 ) ) ;
if ( F_9 ( V_17 != 0 ) && ( V_185 . error == 0 ) ) {
F_86 ( V_180 -> V_68 ,
V_184 , V_190 ) ;
F_11 ( L_28 ) ;
( void ) F_87 ( V_183 , V_183 -> V_191 ,
false , false ,
V_178 ) ;
}
}
int F_88 ( struct V_170 * V_171 ,
struct V_31 * V_32 ,
void T_22 * V_192 ,
void * V_193 ,
T_1 V_194 ,
T_23 V_195 ,
struct V_181 T_22 * V_182 ,
struct V_172 * * V_196 )
{
struct V_11 * V_12 = & V_32 -> V_94 ;
struct V_172 * V_183 = NULL ;
struct V_6 * V_70 ;
struct V_1 V_24 ;
struct V_197 V_198 ;
T_1 V_65 ;
void * V_73 ;
int V_17 ;
V_17 = F_89 ( & V_32 -> V_199 ) ;
if ( F_9 ( V_17 != 0 ) )
return - V_54 ;
if ( V_193 == NULL ) {
V_12 -> V_84 = false ;
V_17 = F_74 ( V_12 , V_194 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_200;
V_17 = F_90 ( V_12 -> V_169 ,
V_192 , V_194 ) ;
if ( F_9 ( V_17 != 0 ) ) {
V_17 = - V_201 ;
F_11 ( L_29 ) ;
goto V_200;
}
V_193 = V_12 -> V_169 ;
} else
V_12 -> V_84 = true ;
V_12 -> V_68 = V_179 ( V_171 ) -> V_68 ;
V_12 -> V_105 = 0 ;
V_12 -> V_46 = 0 ;
V_12 -> V_50 = 0 ;
F_91 ( & V_12 -> V_24 ) ;
V_12 -> V_90 = V_32 -> V_95 ;
V_12 -> V_89 = NULL ;
V_12 -> V_92 = false ;
memset ( V_12 -> V_62 , 0 , sizeof( V_12 -> V_62 ) ) ;
F_91 ( & V_12 -> V_49 ) ;
F_91 ( & V_12 -> V_66 ) ;
if ( ! V_12 -> V_202 ) {
V_17 = F_92 ( & V_12 -> V_18 , V_203 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_200;
V_12 -> V_202 = true ;
}
F_91 ( & V_24 ) ;
V_17 = F_62 ( V_32 , V_12 , V_193 ,
V_194 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
V_17 = F_27 ( V_12 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
V_17 = F_93 ( & V_198 , & V_12 -> V_49 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
V_17 = F_73 ( V_32 , V_12 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
V_17 = F_29 ( V_12 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
if ( V_195 ) {
V_17 = F_94 ( V_32 , & V_32 -> V_187 . V_204 ,
V_195 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_151;
}
V_73 = F_95 ( V_32 , V_194 ) ;
if ( F_9 ( V_73 == NULL ) ) {
F_11 ( L_30 ) ;
V_17 = - V_21 ;
goto V_151;
}
F_64 ( V_12 ) ;
memcpy ( V_73 , V_193 , V_194 ) ;
F_21 ( V_73 , & V_12 -> V_66 ) ;
F_18 ( & V_12 -> V_66 ) ;
F_96 ( V_32 , V_194 ) ;
F_43 ( V_32 , V_12 ) ;
V_17 = F_78 ( V_171 , V_32 ,
& V_183 ,
( V_182 ) ? & V_65 : NULL ) ;
if ( V_17 != 0 )
F_11 ( L_27 ) ;
F_1 ( & V_12 -> V_24 , false ) ;
F_97 ( & V_198 , & V_12 -> V_49 ,
( void * ) V_183 ) ;
if ( F_9 ( V_32 -> V_95 != NULL &&
! V_32 -> V_98 ) )
F_98 ( V_32 , V_183 ) ;
F_68 ( V_12 ) ;
F_83 ( V_32 , V_179 ( V_171 ) , V_17 ,
V_182 , V_183 , V_65 ) ;
if ( F_9 ( V_196 != NULL ) ) {
* V_196 = V_183 ;
V_183 = NULL ;
} else if ( F_6 ( V_183 != NULL ) ) {
F_99 ( & V_183 ) ;
}
F_100 ( & V_12 -> V_24 , & V_24 ) ;
F_101 ( & V_32 -> V_199 ) ;
F_66 ( & V_24 ) ;
return 0 ;
V_151:
F_18 ( & V_12 -> V_66 ) ;
F_63 ( V_12 ) ;
F_102 ( & V_198 , & V_12 -> V_49 ) ;
F_1 ( & V_12 -> V_24 , true ) ;
F_68 ( V_12 ) ;
if ( F_9 ( V_32 -> V_95 != NULL &&
! V_32 -> V_98 ) )
F_98 ( V_32 , NULL ) ;
V_200:
F_100 ( & V_12 -> V_24 , & V_24 ) ;
V_70 = V_12 -> V_70 ;
V_12 -> V_70 = NULL ;
F_101 ( & V_32 -> V_199 ) ;
F_66 ( & V_24 ) ;
if ( F_9 ( V_70 != NULL ) )
F_34 ( & V_70 ) ;
return V_17 ;
}
static void F_103 ( struct V_31 * V_32 )
{
F_11 ( L_31 ) ;
( void ) F_82 ( V_32 , false , true , 0 , false , 10 * V_205 ) ;
F_45 ( V_32 -> V_95 , false ) ;
F_45 ( V_32 -> V_93 , false ) ;
V_32 -> V_96 = false ;
}
void F_98 ( struct V_31 * V_32 ,
struct V_172 * V_183 )
{
int V_17 = 0 ;
struct V_1 V_206 ;
struct V_42 V_207 , V_208 ;
struct V_172 * V_209 = NULL ;
struct V_197 V_198 ;
if ( V_32 -> V_95 == NULL )
goto V_200;
F_91 ( & V_206 ) ;
V_207 . V_37 = F_26 ( V_32 -> V_95 ) ;
F_14 ( & V_207 . V_23 , & V_206 ) ;
V_208 . V_37 = F_26 ( V_32 -> V_93 ) ;
F_14 ( & V_208 . V_23 , & V_206 ) ;
do {
V_17 = F_93 ( & V_198 , & V_206 ) ;
} while ( V_17 == - V_54 );
if ( F_9 ( V_17 != 0 ) ) {
F_103 ( V_32 ) ;
goto V_210;
}
if ( V_32 -> V_98 ) {
F_35 ( V_183 != NULL ) ;
V_17 = F_44 ( V_32 , V_32 -> V_97 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_103 ( V_32 ) ;
goto V_211;
}
V_32 -> V_98 = false ;
}
F_45 ( V_32 -> V_95 , false ) ;
F_45 ( V_32 -> V_93 , false ) ;
V_32 -> V_96 = false ;
if ( V_183 == NULL ) {
( void ) F_78 ( NULL , V_32 , & V_209 ,
NULL ) ;
V_183 = V_209 ;
}
F_97 ( & V_198 , & V_206 , ( void * ) V_183 ) ;
if ( V_209 != NULL )
F_99 ( & V_209 ) ;
F_46 ( & V_208 . V_37 ) ;
F_46 ( & V_207 . V_37 ) ;
F_46 ( & V_32 -> V_95 ) ;
V_200:
return;
V_211:
F_102 ( & V_198 , & V_206 ) ;
V_210:
F_46 ( & V_208 . V_37 ) ;
F_46 ( & V_207 . V_37 ) ;
F_46 ( & V_32 -> V_95 ) ;
}
void F_104 ( struct V_31 * V_32 )
{
F_105 ( & V_32 -> V_199 ) ;
if ( V_32 -> V_98 )
F_98 ( V_32 , NULL ) ;
F_101 ( & V_32 -> V_199 ) ;
}
int F_106 ( struct V_212 * V_213 , void * V_214 ,
struct V_170 * V_171 )
{
struct V_31 * V_32 = F_107 ( V_213 ) ;
struct V_215 * V_216 = (struct V_215 * ) V_214 ;
struct V_217 * V_218 = V_217 ( V_171 -> V_219 ) ;
int V_17 ;
if ( F_9 ( V_216 -> V_220 != V_221 ) ) {
F_11 ( L_32 ) ;
F_11 ( L_33
L_34 ) ;
return - V_35 ;
}
V_17 = F_108 ( & V_218 -> V_222 , true ) ;
if ( F_9 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_88 ( V_171 , V_32 ,
( void T_22 * ) ( unsigned long ) V_216 -> V_223 ,
NULL , V_216 -> V_194 , V_216 -> V_195 ,
( void T_22 * ) ( unsigned long ) V_216 -> V_185 ,
NULL ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_200;
F_109 ( V_32 ) ;
V_200:
F_110 ( & V_218 -> V_222 ) ;
return V_17 ;
}
