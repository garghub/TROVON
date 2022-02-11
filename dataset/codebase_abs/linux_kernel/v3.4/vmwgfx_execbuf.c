static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
return F_2 ( V_6 ) ? : - V_7 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
return 0 ;
}
static void F_4 ( struct V_3 * V_4 ,
struct V_8 * * V_9 )
{
struct V_8 * V_10 = * V_9 ;
if ( F_5 ( & V_10 -> V_11 ) ) {
F_6 ( & V_10 -> V_11 , & V_4 -> V_12 ) ;
* V_9 = NULL ;
} else
F_7 ( V_9 ) ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
T_2 V_15 ,
T_2 * V_16 )
{
T_2 V_17 ;
struct V_18 * V_19 ;
V_17 = F_9 ( V_14 , V_4 -> V_20 ) ;
if ( F_10 ( V_17 >= V_21 ) ) {
F_11 ( L_1
L_2 ) ;
return - V_7 ;
}
V_19 = & V_4 -> V_22 [ V_17 ] ;
if ( F_10 ( V_17 == V_4 -> V_20 ) ) {
V_19 -> V_23 = NULL ;
V_19 -> V_14 = F_12 ( V_14 ) ;
F_6 ( & V_19 -> V_24 , & V_4 -> V_25 ) ;
++ V_4 -> V_20 ;
}
V_19 -> V_23 = ( void * )
( ( unsigned long ) V_19 -> V_23 | V_15 ) ;
V_4 -> V_15 |= V_15 ;
if ( V_16 )
* V_16 = V_17 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_8 * V_26 ;
struct V_27 {
T_1 V_5 ;
T_3 V_28 ;
} * V_29 ;
int V_30 ;
V_29 = F_14 ( V_5 , struct V_27 , V_5 ) ;
if ( F_15 ( V_4 -> V_31 && V_29 -> V_28 == V_4 -> V_32 ) )
return 0 ;
V_30 = F_16 ( V_2 , V_4 -> V_33 , V_29 -> V_28 ,
& V_26 ) ;
if ( F_10 ( V_30 != 0 ) ) {
F_11 ( L_3 ,
( unsigned ) V_29 -> V_28 ) ;
return V_30 ;
}
V_4 -> V_32 = V_29 -> V_28 ;
V_4 -> V_31 = true ;
V_4 -> V_34 = V_26 ;
F_4 ( V_4 , & V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_35 )
{
struct V_36 * V_37 ;
int V_30 ;
struct V_8 * V_10 ;
if ( * V_35 == V_38 )
return 0 ;
if ( F_15 ( ( V_4 -> V_39 &&
* V_35 == V_4 -> V_40 ) ) ) {
* V_35 = V_4 -> V_41 ;
return 0 ;
}
V_30 = F_18 ( V_2 ,
V_4 -> V_33 ,
* V_35 , & V_37 ) ;
if ( F_10 ( V_30 != 0 ) ) {
F_11 ( L_4
L_5 ,
( unsigned int ) * V_35 ,
( unsigned long ) V_35 ) ;
return V_30 ;
}
V_30 = F_19 ( V_2 , V_37 ) ;
if ( F_10 ( V_30 != 0 ) ) {
if ( V_30 != - V_42 )
F_11 ( L_6 ) ;
F_20 ( & V_37 ) ;
return V_30 ;
}
V_4 -> V_40 = * V_35 ;
V_4 -> V_39 = true ;
V_4 -> V_41 = V_37 -> V_10 . V_43 ;
* V_35 = V_4 -> V_41 ;
V_10 = & V_37 -> V_10 ;
F_4 ( V_4 , & V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_44 {
T_1 V_5 ;
T_4 V_45 ;
} * V_29 ;
int V_30 ;
V_30 = F_13 ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_29 = F_14 ( V_5 , struct V_44 , V_5 ) ;
V_30 = F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_46 . V_35 ) ;
return V_30 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_44 {
T_1 V_5 ;
T_5 V_45 ;
} * V_29 ;
int V_30 ;
V_29 = F_14 ( V_5 , struct V_44 , V_5 ) ;
V_30 = F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_47 . V_35 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
return F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_48 . V_35 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_44 {
T_1 V_5 ;
T_6 V_45 ;
} * V_29 ;
int V_30 ;
V_29 = F_14 ( V_5 , struct V_44 , V_5 ) ;
V_30 = F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_47 . V_35 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
return F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_48 . V_35 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_44 {
T_1 V_5 ;
T_7 V_45 ;
} * V_29 ;
V_29 = F_14 ( V_5 , struct V_44 , V_5 ) ;
if ( F_10 ( ! V_4 -> V_49 ) ) {
F_11 ( L_7 , V_29 -> V_5 . V_43 ) ;
return - V_50 ;
}
return F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_51 . V_35 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_44 {
T_1 V_5 ;
T_8 V_45 ;
} * V_29 ;
V_29 = F_14 ( V_5 , struct V_44 , V_5 ) ;
if ( F_10 ( ! V_4 -> V_49 ) ) {
F_11 ( L_7 , V_29 -> V_5 . V_43 ) ;
return - V_50 ;
}
return F_17 ( V_2 , V_4 , & V_29 -> V_45 . V_35 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_2 V_28 ,
struct V_13 * V_52 ,
struct V_3 * V_4 )
{
int V_30 ;
bool V_53 = false ;
T_2 V_54 ;
if ( F_10 ( V_52 != V_4 -> V_55 ) ) {
if ( F_10 ( V_52 -> V_56 > 4 ) ) {
F_11 ( L_8 ) ;
return - V_7 ;
}
if ( F_10 ( V_4 -> V_55 != NULL ) ) {
F_27 ( ! V_4 -> V_57 ) ;
V_53 = true ;
V_54 = V_4 -> V_58 ;
V_30 = F_8 ( V_4 ,
V_4 -> V_55 ,
V_59 ,
NULL ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
V_4 -> V_55 = V_52 ;
V_30 = F_8 ( V_4 ,
V_2 -> V_60 ,
V_59 ,
NULL ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
if ( F_10 ( V_28 != V_4 -> V_58 &&
V_4 -> V_57 ) ) {
V_53 = true ;
V_54 = V_4 -> V_58 ;
}
V_4 -> V_58 = V_28 ;
V_4 -> V_57 = true ;
if ( V_53 ) {
struct V_8 * V_26 = V_4 -> V_34 ;
if ( F_5 ( & V_26 -> V_61 ) )
F_6 ( & V_26 -> V_61 ,
& V_4 -> V_62 ) ;
V_30 = F_8 ( V_4 ,
V_2 -> V_60 ,
V_59 ,
NULL ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_26 , * V_63 ;
int V_30 ;
F_29 (ctx, next_ctx, &sw_context->query_list,
query_head) {
F_30 ( & V_26 -> V_61 ) ;
F_27 ( F_5 ( & V_26 -> V_11 ) ) ;
V_30 = F_31 ( V_2 , V_26 -> V_43 ) ;
if ( F_10 ( V_30 != 0 ) )
F_11 ( L_9 ) ;
}
if ( V_2 -> V_64 != V_4 -> V_55 ) {
if ( V_2 -> V_64 ) {
F_32 ( V_2 -> V_64 , false ) ;
F_33 ( & V_2 -> V_64 ) ;
}
F_32 ( V_4 -> V_55 , true ) ;
F_32 ( V_2 -> V_60 , true ) ;
V_2 -> V_65 = true ;
V_2 -> V_66 = V_4 -> V_58 ;
V_2 -> V_64 =
F_12 ( V_4 -> V_55 ) ;
}
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_67 * V_68 , * V_69 ;
F_35 (list, next, &sw_context->query_list) {
F_30 ( V_68 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_9 * V_70 ,
struct V_71 * * V_72 )
{
struct V_71 * V_73 = NULL ;
struct V_13 * V_14 ;
T_2 V_74 = V_70 -> V_75 ;
struct V_76 * V_77 ;
int V_30 ;
V_30 = F_37 ( V_4 -> V_33 , V_74 , & V_73 ) ;
if ( F_10 ( V_30 != 0 ) ) {
F_11 ( L_10 ) ;
return - V_7 ;
}
V_14 = & V_73 -> V_78 ;
if ( F_10 ( V_4 -> V_79 >= V_80 ) ) {
F_11 ( L_11
L_12 ) ;
V_30 = - V_7 ;
goto V_81;
}
V_77 = & V_4 -> V_82 [ V_4 -> V_79 ++ ] ;
V_77 -> V_83 = V_70 ;
V_30 = F_8 ( V_4 , V_14 , V_59 ,
& V_77 -> V_84 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_81;
* V_72 = V_73 ;
return 0 ;
V_81:
F_38 ( & V_73 ) ;
V_72 = NULL ;
return V_30 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_71 * V_73 ;
struct V_85 {
T_1 V_5 ;
T_10 V_86 ;
} * V_29 ;
int V_30 ;
V_29 = F_14 ( V_5 , struct V_85 , V_5 ) ;
V_30 = F_13 ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_36 ( V_2 , V_4 ,
& V_29 -> V_86 . V_87 ,
& V_73 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_26 ( V_2 , V_29 -> V_86 . V_28 ,
& V_73 -> V_78 , V_4 ) ;
F_38 ( & V_73 ) ;
return V_30 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_71 * V_73 ;
struct V_85 {
T_1 V_5 ;
T_11 V_86 ;
} * V_29 ;
int V_30 ;
struct V_8 * V_26 ;
V_29 = F_14 ( V_5 , struct V_85 , V_5 ) ;
V_30 = F_13 ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_36 ( V_2 , V_4 ,
& V_29 -> V_86 . V_87 ,
& V_73 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
F_38 ( & V_73 ) ;
V_26 = V_4 -> V_34 ;
if ( ! F_5 ( & V_26 -> V_61 ) )
F_30 ( & V_26 -> V_61 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_71 * V_73 = NULL ;
struct V_13 * V_14 ;
struct V_36 * V_37 = NULL ;
struct V_88 {
T_1 V_5 ;
T_12 V_89 ;
} * V_29 ;
int V_30 ;
struct V_8 * V_10 ;
V_29 = F_14 ( V_5 , struct V_88 , V_5 ) ;
V_30 = F_36 ( V_2 , V_4 ,
& V_29 -> V_89 . V_90 . V_70 ,
& V_73 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_14 = & V_73 -> V_78 ;
V_30 = F_18 ( V_2 , V_4 -> V_33 ,
V_29 -> V_89 . V_91 . V_35 , & V_37 ) ;
if ( V_30 ) {
F_11 ( L_13 ) ;
goto V_81;
}
V_30 = F_19 ( V_2 , V_37 ) ;
if ( F_10 ( V_30 != 0 ) ) {
if ( V_30 != - V_42 )
F_11 ( L_14 ) ;
goto V_92;
}
V_29 -> V_89 . V_91 . V_35 = V_37 -> V_10 . V_43 ;
F_42 ( V_37 , V_4 -> V_33 , V_14 , V_5 ) ;
F_38 ( & V_73 ) ;
V_10 = & V_37 -> V_10 ;
F_4 ( V_4 , & V_10 ) ;
return 0 ;
V_92:
F_20 ( & V_37 ) ;
V_81:
F_38 ( & V_73 ) ;
return V_30 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_93 {
T_1 V_5 ;
T_13 V_45 ;
} * V_29 ;
T_14 * V_94 = ( T_14 * ) (
( unsigned long ) V_5 + sizeof( * V_29 ) ) ;
T_15 * V_95 ;
T_2 V_96 ;
T_2 V_97 ;
int V_30 ;
V_30 = F_13 ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_29 = F_14 ( V_5 , struct V_93 , V_5 ) ;
V_97 = ( V_5 -> V_98 - sizeof( V_29 -> V_45 ) ) / sizeof( * V_94 ) ;
if ( F_10 ( V_29 -> V_45 . V_99 > V_97 ) ) {
F_11 ( L_15 ) ;
return - V_7 ;
}
for ( V_96 = 0 ; V_96 < V_29 -> V_45 . V_99 ; ++ V_96 , ++ V_94 ) {
V_30 = F_17 ( V_2 , V_4 ,
& V_94 -> V_100 . V_101 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
V_97 = ( V_5 -> V_98 - sizeof( V_29 -> V_45 ) -
V_29 -> V_45 . V_99 * sizeof( * V_94 ) ) / sizeof( * V_95 ) ;
if ( F_10 ( V_29 -> V_45 . V_102 > V_97 ) ) {
F_11 ( L_16 ) ;
return - V_7 ;
}
V_95 = ( T_15 * ) V_94 ;
for ( V_96 = 0 ; V_96 < V_29 -> V_45 . V_102 ; ++ V_96 , ++ V_95 ) {
V_30 = F_17 ( V_2 , V_4 ,
& V_95 -> V_103 . V_101 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_104 {
T_1 V_5 ;
T_16 V_105 ;
};
T_17 * V_106 = ( T_17 * )
( ( unsigned long ) V_5 + V_5 -> V_98 + sizeof( V_5 ) ) ;
T_17 * V_107 = ( T_17 * )
( ( unsigned long ) V_5 + sizeof( struct V_104 ) ) ;
int V_30 ;
V_30 = F_13 ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
for (; V_107 < V_106 ; ++ V_107 ) {
if ( F_15 ( V_107 -> V_108 != V_109 ) )
continue;
V_30 = F_17 ( V_2 , V_4 ,
& V_107 -> V_110 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_111 )
{
struct V_71 * V_73 ;
int V_30 ;
struct {
T_2 V_5 ;
T_18 V_45 ;
} * V_29 = V_111 ;
V_30 = F_36 ( V_2 , V_4 ,
& V_29 -> V_45 . V_70 ,
& V_73 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
F_38 ( & V_73 ) ;
return V_30 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_111 , T_2 * V_98 )
{
T_2 V_112 = * V_98 ;
T_2 V_113 ;
V_113 = F_47 ( ( ( T_2 * ) V_111 ) [ 0 ] ) ;
switch ( V_113 ) {
case V_114 :
* V_98 = sizeof( T_2 ) + sizeof( V_115 ) ;
break;
case V_116 :
* V_98 = sizeof( T_2 ) + sizeof( T_18 ) ;
break;
case V_117 :
* V_98 = sizeof( T_2 ) + sizeof( V_118 ) ;
break;
case V_119 :
* V_98 = sizeof( T_2 ) + sizeof( V_118 ) ;
break;
default:
F_11 ( L_17 , V_113 ) ;
return - V_7 ;
}
if ( * V_98 > V_112 ) {
F_11 ( L_18
L_19 , V_113 ) ;
return - V_7 ;
}
if ( F_10 ( ! V_4 -> V_49 ) ) {
F_11 ( L_20 , V_113 ) ;
return - V_50 ;
}
if ( V_113 == V_116 )
return F_45 ( V_2 , V_4 , V_111 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_111 , T_2 * V_98 )
{
T_2 V_113 ;
T_2 V_112 = * V_98 ;
T_1 * V_5 = ( T_1 * ) V_111 ;
int V_30 ;
V_113 = F_47 ( ( ( T_2 * ) V_111 ) [ 0 ] ) ;
if ( F_10 ( V_113 < V_120 ) )
return F_46 ( V_2 , V_4 , V_111 , V_98 ) ;
V_113 = F_47 ( V_5 -> V_43 ) ;
* V_98 = F_47 ( V_5 -> V_98 ) + sizeof( T_1 ) ;
V_113 -= V_121 ;
if ( F_10 ( * V_98 > V_112 ) )
goto V_122;
if ( F_10 ( V_113 >= V_123 - V_121 ) )
goto V_122;
V_30 = V_124 [ V_113 ] ( V_2 , V_4 , V_5 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_122;
return 0 ;
V_122:
F_11 ( L_21 ,
V_113 + V_121 ) ;
return - V_7 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_111 ,
T_2 V_98 )
{
T_19 V_125 = V_98 ;
int V_30 ;
while ( V_125 > 0 ) {
V_98 = V_125 ;
V_30 = F_48 ( V_2 , V_4 , V_111 , & V_98 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_111 = ( void * ) ( ( unsigned long ) V_111 + V_98 ) ;
V_125 -= V_98 ;
}
if ( F_10 ( V_125 != 0 ) ) {
F_11 ( L_22 ) ;
return - V_7 ;
}
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
V_4 -> V_79 = 0 ;
}
static void F_51 ( struct V_3 * V_4 )
{
T_2 V_96 ;
struct V_76 * V_77 ;
struct V_18 * V_126 ;
struct V_13 * V_14 ;
for ( V_96 = 0 ; V_96 < V_4 -> V_79 ; ++ V_96 ) {
V_77 = & V_4 -> V_82 [ V_96 ] ;
V_126 = & V_4 -> V_22 [ V_77 -> V_84 ] ;
V_14 = V_126 -> V_14 ;
if ( V_14 -> V_127 . V_128 == V_129 ) {
V_77 -> V_83 -> V_130 += V_14 -> V_130 ;
V_77 -> V_83 -> V_75 = V_131 ;
} else
V_77 -> V_83 -> V_75 = V_14 -> V_127 . V_132 ;
}
F_50 ( V_4 ) ;
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_18 * V_133 , * V_69 ;
struct V_8 * V_10 , * V_134 ;
F_29 (entry, next, &sw_context->validate_nodes,
head) {
F_53 ( & V_133 -> V_24 ) ;
F_54 ( V_133 -> V_14 ) ;
F_33 ( & V_133 -> V_14 ) ;
V_4 -> V_20 -- ;
}
F_27 ( V_4 -> V_20 != 0 ) ;
F_55 ( & V_4 -> V_12 ) ;
F_29 (res, res_next, &sw_context->resource_list,
validate_head) {
F_30 ( & V_10 -> V_11 ) ;
F_7 ( & V_10 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_30 ;
if ( V_14 == V_2 -> V_64 ||
( V_14 == V_2 -> V_60 &&
V_2 -> V_65 ) )
return 0 ;
V_30 = F_57 ( V_14 , & V_135 , true , false , false ) ;
if ( F_15 ( V_30 == 0 || V_30 == - V_42 ) )
return V_30 ;
F_58 ( L_23 ) ;
V_30 = F_57 ( V_14 , & V_136 , true , false , false ) ;
return V_30 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_133 ;
int V_30 ;
F_60 (entry, &sw_context->validate_nodes, head) {
V_30 = F_56 ( V_2 , V_133 -> V_14 ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
static int F_61 ( struct V_3 * V_4 ,
T_2 V_98 )
{
if ( F_15 ( V_4 -> V_137 >= V_98 ) )
return 0 ;
if ( V_4 -> V_137 == 0 )
V_4 -> V_137 = V_138 ;
while ( V_4 -> V_137 < V_98 ) {
V_4 -> V_137 =
F_62 ( V_4 -> V_137 +
( V_4 -> V_137 >> 1 ) ) ;
}
if ( V_4 -> V_139 != NULL )
F_63 ( V_4 -> V_139 ) ;
V_4 -> V_139 = F_64 ( V_4 -> V_137 ) ;
if ( V_4 -> V_139 == NULL ) {
F_11 ( L_24 ) ;
V_4 -> V_137 = 0 ;
return - V_140 ;
}
return 0 ;
}
int F_65 ( struct V_141 * V_142 ,
struct V_1 * V_2 ,
struct V_143 * * V_144 ,
T_2 * V_145 )
{
T_2 V_146 ;
int V_30 ;
bool V_147 = false ;
F_27 ( V_145 != NULL && V_142 == NULL ) ;
V_30 = F_66 ( V_2 , & V_146 ) ;
if ( F_10 ( V_30 != 0 ) ) {
F_11 ( L_25 ) ;
V_147 = true ;
}
if ( V_145 != NULL )
V_30 = F_67 ( V_142 , V_2 -> V_148 ,
V_146 ,
V_59 ,
V_144 , V_145 ) ;
else
V_30 = F_68 ( V_2 -> V_148 , V_146 ,
V_59 ,
V_144 ) ;
if ( F_10 ( V_30 != 0 && ! V_147 ) ) {
( void ) F_69 ( V_2 , false , false ,
V_146 , false ,
V_149 ) ;
* V_144 = NULL ;
}
return 0 ;
}
void
F_70 ( struct V_1 * V_2 ,
struct V_150 * V_151 ,
int V_30 ,
struct V_152 T_20 * V_153 ,
struct V_143 * V_154 ,
T_2 V_155 )
{
struct V_152 V_156 ;
if ( V_153 == NULL )
return;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . error = V_30 ;
if ( V_30 == 0 ) {
F_27 ( V_154 == NULL ) ;
V_156 . V_74 = V_155 ;
V_156 . V_157 = V_154 -> V_157 ;
F_71 ( V_2 , & V_2 -> V_158 ) ;
V_156 . V_159 = V_2 -> V_160 ;
}
V_30 = F_72 ( V_153 , & V_156 ,
sizeof( V_156 ) ) ;
if ( F_10 ( V_30 != 0 ) && ( V_156 . error == 0 ) ) {
F_73 ( V_151 -> V_33 ,
V_155 , V_161 ) ;
F_11 ( L_26 ) ;
( void ) F_74 ( V_154 , V_154 -> V_162 ,
false , false ,
V_149 ) ;
}
}
int F_75 ( struct V_141 * V_142 ,
struct V_1 * V_2 ,
void T_20 * V_163 ,
void * V_164 ,
T_2 V_165 ,
T_21 V_166 ,
struct V_152 T_20 * V_153 ,
struct V_143 * * V_167 )
{
struct V_3 * V_4 = & V_2 -> V_26 ;
struct V_143 * V_154 = NULL ;
T_2 V_74 ;
void * V_29 ;
int V_30 ;
V_30 = F_76 ( & V_2 -> V_168 ) ;
if ( F_10 ( V_30 != 0 ) )
return - V_42 ;
if ( V_164 == NULL ) {
V_4 -> V_49 = false ;
V_30 = F_61 ( V_4 , V_165 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_169;
V_30 = F_77 ( V_4 -> V_139 ,
V_163 , V_165 ) ;
if ( F_10 ( V_30 != 0 ) ) {
V_30 = - V_170 ;
F_11 ( L_27 ) ;
goto V_169;
}
V_164 = V_4 -> V_139 ;
} else
V_4 -> V_49 = true ;
V_4 -> V_33 = V_150 ( V_142 ) -> V_33 ;
V_4 -> V_31 = false ;
V_4 -> V_39 = false ;
V_4 -> V_79 = 0 ;
V_4 -> V_20 = 0 ;
V_4 -> V_15 = 0 ;
F_78 ( & V_4 -> V_62 ) ;
F_78 ( & V_4 -> V_12 ) ;
V_4 -> V_55 = V_2 -> V_64 ;
V_4 -> V_58 = V_2 -> V_66 ;
V_4 -> V_57 = ( V_2 -> V_64 != NULL ) ;
F_78 ( & V_4 -> V_25 ) ;
V_30 = F_49 ( V_2 , V_4 , V_164 ,
V_165 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_122;
V_30 = F_79 ( & V_4 -> V_25 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_122;
V_30 = F_59 ( V_2 , V_4 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_122;
F_51 ( V_4 ) ;
if ( V_166 ) {
V_30 = F_80 ( V_2 , & V_2 -> V_158 . V_171 ,
V_166 ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_172;
}
V_29 = F_81 ( V_2 , V_165 ) ;
if ( F_10 ( V_29 == NULL ) ) {
F_11 ( L_28 ) ;
V_30 = - V_140 ;
goto V_172;
}
memcpy ( V_29 , V_164 , V_165 ) ;
F_82 ( V_2 , V_165 ) ;
F_28 ( V_2 , V_4 ) ;
V_30 = F_65 ( V_142 , V_2 ,
& V_154 ,
( V_153 ) ? & V_74 : NULL ) ;
if ( V_30 != 0 )
F_11 ( L_25 ) ;
F_83 ( & V_4 -> V_25 ,
( void * ) V_154 ) ;
F_52 ( V_4 ) ;
F_70 ( V_2 , V_150 ( V_142 ) , V_30 ,
V_153 , V_154 , V_74 ) ;
if ( F_10 ( V_167 != NULL ) ) {
* V_167 = V_154 ;
V_154 = NULL ;
} else if ( F_15 ( V_154 != NULL ) ) {
F_84 ( & V_154 ) ;
}
F_85 ( & V_2 -> V_168 ) ;
return 0 ;
V_122:
F_50 ( V_4 ) ;
V_172:
F_34 ( V_4 ) ;
F_86 ( & V_4 -> V_25 ) ;
F_52 ( V_4 ) ;
V_169:
F_85 ( & V_2 -> V_168 ) ;
return V_30 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_11 ( L_29 ) ;
( void ) F_69 ( V_2 , false , true , 0 , false , 10 * V_173 ) ;
F_32 ( V_2 -> V_64 , false ) ;
F_32 ( V_2 -> V_60 , false ) ;
V_2 -> V_65 = false ;
}
void F_88 ( struct V_1 * V_2 ,
bool V_174 , T_2 V_28 )
{
int V_30 = 0 ;
struct V_67 V_175 ;
struct V_18 V_176 , V_177 ;
struct V_143 * V_154 ;
F_89 ( & V_2 -> V_168 ) ;
if ( V_2 -> V_64 == NULL )
goto V_169;
if ( V_174 && V_28 != V_2 -> V_66 )
goto V_169;
F_78 ( & V_175 ) ;
V_176 . V_23 = ( void * ) ( unsigned long )
V_59 ;
V_176 . V_14 = F_12 ( V_2 -> V_64 ) ;
F_6 ( & V_176 . V_24 , & V_175 ) ;
V_177 . V_23 = V_176 . V_23 ;
V_177 . V_14 = F_12 ( V_2 -> V_60 ) ;
F_6 ( & V_177 . V_24 , & V_175 ) ;
do {
V_30 = F_79 ( & V_175 ) ;
} while ( V_30 == - V_42 );
if ( F_10 ( V_30 != 0 ) ) {
F_87 ( V_2 ) ;
goto V_178;
}
V_30 = F_31 ( V_2 , V_2 -> V_66 ) ;
if ( F_10 ( V_30 != 0 ) ) {
F_87 ( V_2 ) ;
goto V_179;
}
F_32 ( V_2 -> V_64 , false ) ;
F_32 ( V_2 -> V_60 , false ) ;
V_2 -> V_65 = false ;
( void ) F_65 ( NULL , V_2 , & V_154 , NULL ) ;
F_83 ( & V_175 , ( void * ) V_154 ) ;
F_33 ( & V_177 . V_14 ) ;
F_33 ( & V_176 . V_14 ) ;
F_33 ( & V_2 -> V_64 ) ;
V_169:
F_85 ( & V_2 -> V_168 ) ;
return;
V_179:
F_86 ( & V_175 ) ;
V_178:
F_33 ( & V_177 . V_14 ) ;
F_33 ( & V_176 . V_14 ) ;
F_33 ( & V_2 -> V_64 ) ;
F_85 ( & V_2 -> V_168 ) ;
}
int F_90 ( struct V_180 * V_181 , void * V_182 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_91 ( V_181 ) ;
struct V_183 * V_184 = (struct V_183 * ) V_182 ;
struct V_185 * V_186 = V_185 ( V_142 -> V_187 ) ;
int V_30 ;
if ( F_10 ( V_184 -> V_188 != V_189 ) ) {
F_11 ( L_30 ) ;
F_11 ( L_31
L_32 ) ;
return - V_7 ;
}
V_30 = F_92 ( & V_186 -> V_190 , true ) ;
if ( F_10 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_75 ( V_142 , V_2 ,
( void T_20 * ) ( unsigned long ) V_184 -> V_191 ,
NULL , V_184 -> V_165 , V_184 -> V_166 ,
( void T_20 * ) ( unsigned long ) V_184 -> V_156 ,
NULL ) ;
if ( F_10 ( V_30 != 0 ) )
goto V_169;
F_93 ( V_2 ) ;
V_169:
F_94 ( & V_186 -> V_190 ) ;
return V_30 ;
}
