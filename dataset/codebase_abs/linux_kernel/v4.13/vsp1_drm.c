void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 -> V_4 . V_5 -> V_6 ) ;
}
static void F_3 ( struct V_7 * V_4 )
{
struct V_8 * V_3 = F_4 ( V_4 ) ;
if ( V_3 -> V_9 )
V_3 -> V_9 ( V_3 -> V_10 ) ;
}
int F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( ! V_2 )
return - V_13 ;
return 0 ;
}
int F_7 ( struct V_11 * V_12 , const struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_7 * V_4 = & V_2 -> V_3 -> V_4 ;
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 V_19 ;
unsigned int V_20 ;
int V_21 ;
if ( ! V_15 ) {
V_21 = F_8 ( V_4 ) ;
if ( V_21 == - V_22 )
F_9 ( V_2 -> V_12 , L_1 ) ;
F_10 ( & V_4 -> V_5 -> V_23 . V_24 . V_23 ) ;
for ( V_20 = 0 ; V_20 < V_17 -> V_23 . V_25 ; ++ V_20 ) {
V_2 -> V_3 -> V_26 [ V_20 ] . V_27 = false ;
V_17 -> V_26 [ V_20 ] . V_28 = NULL ;
V_4 -> V_26 [ V_20 ] = NULL ;
}
V_4 -> V_29 = 0 ;
V_2 -> V_3 -> V_9 = NULL ;
F_11 ( V_4 -> V_5 -> V_6 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_12 , L_2 , V_30 ) ;
return 0 ;
}
F_13 ( V_2 -> V_12 , L_3 ,
V_30 , V_15 -> V_31 , V_15 -> V_32 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_33 = V_34 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_23 . V_25 ; ++ V_20 ) {
V_19 . V_35 = V_20 ;
V_19 . V_19 . V_31 = V_15 -> V_31 ;
V_19 . V_19 . V_32 = V_15 -> V_32 ;
V_19 . V_19 . V_36 = V_37 ;
V_19 . V_19 . V_38 = V_39 ;
V_21 = F_14 ( & V_17 -> V_23 . V_24 , V_35 ,
V_40 , NULL , & V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_4 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 , V_20 ) ;
}
V_19 . V_35 = V_17 -> V_23 . V_25 ;
V_19 . V_19 . V_31 = V_15 -> V_31 ;
V_19 . V_19 . V_32 = V_15 -> V_32 ;
V_19 . V_19 . V_36 = V_37 ;
V_19 . V_19 . V_38 = V_39 ;
V_21 = F_14 ( & V_17 -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_4 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 , V_20 ) ;
V_19 . V_35 = V_41 ;
V_21 = F_14 ( & V_2 -> V_42 [ 0 ] -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_5 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 ) ;
V_19 . V_35 = V_43 ;
V_21 = F_14 ( & V_2 -> V_42 [ 0 ] -> V_23 . V_24 , V_35 , V_44 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_6 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 ) ;
V_19 . V_35 = V_45 ;
V_21 = F_14 ( & V_2 -> V_46 -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_7 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 ) ;
if ( V_19 . V_19 . V_31 != V_15 -> V_31 ||
V_19 . V_19 . V_32 != V_15 -> V_32 ||
V_19 . V_19 . V_36 != V_37 ) {
F_13 ( V_2 -> V_12 , L_8 , V_30 ) ;
return - V_47 ;
}
V_21 = F_15 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_3 -> V_9 = V_15 -> V_48 ;
V_2 -> V_3 -> V_10 = V_15 -> V_49 ;
V_21 = F_16 ( & V_4 -> V_5 -> V_23 . V_24 . V_23 ,
& V_4 -> V_4 ) ;
if ( V_21 < 0 ) {
F_13 ( V_2 -> V_12 , L_9 , V_30 ) ;
F_12 ( V_2 ) ;
return V_21 ;
}
F_13 ( V_2 -> V_12 , L_10 , V_30 ) ;
return 0 ;
}
void F_17 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_7 * V_4 = & V_2 -> V_3 -> V_4 ;
V_2 -> V_3 -> V_29 = V_4 -> V_29 ;
}
int F_18 ( struct V_11 * V_12 , unsigned int V_50 ,
const struct V_51 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
const struct V_52 * V_53 ;
struct V_54 * V_28 ;
if ( V_50 >= V_2 -> V_55 -> V_56 )
return - V_57 ;
V_28 = V_2 -> V_28 [ V_50 ] ;
if ( ! V_15 ) {
F_13 ( V_2 -> V_12 , L_11 , V_30 ,
V_50 ) ;
V_2 -> V_3 -> V_26 [ V_50 ] . V_27 = false ;
return 0 ;
}
F_13 ( V_2 -> V_12 ,
L_12 ,
V_30 , V_50 ,
V_15 -> V_58 . V_59 , V_15 -> V_58 . V_60 , V_15 -> V_58 . V_31 , V_15 -> V_58 . V_32 ,
V_15 -> V_61 . V_59 , V_15 -> V_61 . V_60 , V_15 -> V_61 . V_31 , V_15 -> V_61 . V_32 ,
V_15 -> V_62 , V_15 -> V_63 , & V_15 -> V_64 [ 0 ] , & V_15 -> V_64 [ 1 ] ,
& V_15 -> V_64 [ 2 ] , V_15 -> V_65 ) ;
V_53 = F_19 ( V_2 , V_15 -> V_62 ) ;
if ( ! V_53 ) {
F_13 ( V_2 -> V_12 , L_13 ,
V_15 -> V_62 ) ;
return - V_57 ;
}
V_28 -> V_53 = V_53 ;
V_28 -> V_19 . V_66 = V_53 -> V_67 ;
V_28 -> V_19 . V_68 [ 0 ] . V_69 = V_15 -> V_63 ;
V_28 -> V_19 . V_68 [ 1 ] . V_69 = V_15 -> V_63 ;
V_28 -> V_70 = V_15 -> V_70 ;
V_28 -> V_64 . V_71 [ 0 ] = V_15 -> V_64 [ 0 ] ;
V_28 -> V_64 . V_71 [ 1 ] = V_15 -> V_64 [ 1 ] ;
V_28 -> V_64 . V_71 [ 2 ] = V_15 -> V_64 [ 2 ] ;
V_2 -> V_3 -> V_26 [ V_50 ] . V_72 = V_15 -> V_58 ;
V_2 -> V_3 -> V_26 [ V_50 ] . V_73 = V_15 -> V_61 ;
V_2 -> V_3 -> V_26 [ V_50 ] . V_65 = V_15 -> V_65 ;
V_2 -> V_3 -> V_26 [ V_50 ] . V_27 = true ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_54 * V_28 , unsigned int V_74 )
{
struct V_75 V_76 ;
struct V_18 V_19 ;
const struct V_77 * V_72 ;
int V_21 ;
V_72 = & V_2 -> V_3 -> V_26 [ V_28 -> V_23 . V_78 ] . V_72 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_33 = V_34 ;
V_19 . V_35 = V_41 ;
V_19 . V_19 . V_31 = V_72 -> V_31 + V_72 -> V_59 ;
V_19 . V_19 . V_32 = V_72 -> V_32 + V_72 -> V_60 ;
V_19 . V_19 . V_36 = V_28 -> V_53 -> V_79 ;
V_19 . V_19 . V_38 = V_39 ;
V_21 = F_14 ( & V_28 -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 ,
L_14 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 , V_28 -> V_23 . V_78 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_33 = V_34 ;
V_76 . V_35 = V_41 ;
V_76 . V_80 = V_81 ;
V_76 . V_82 = * V_72 ;
V_21 = F_14 ( & V_28 -> V_23 . V_24 , V_35 , V_83 , NULL ,
& V_76 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 ,
L_15 ,
V_30 , V_76 . V_82 . V_59 , V_76 . V_82 . V_60 , V_76 . V_82 . V_31 , V_76 . V_82 . V_32 ,
V_28 -> V_23 . V_78 ) ;
V_19 . V_35 = V_43 ;
V_21 = F_14 ( & V_28 -> V_23 . V_24 , V_35 , V_44 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 ,
L_16 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 , V_28 -> V_23 . V_78 ) ;
V_19 . V_19 . V_36 = V_37 ;
V_21 = F_14 ( & V_28 -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
V_19 . V_35 = V_74 ;
V_21 = F_14 ( & V_2 -> V_17 -> V_23 . V_24 , V_35 , V_40 , NULL ,
& V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 , L_4 ,
V_30 , V_19 . V_19 . V_31 , V_19 . V_19 . V_32 ,
V_19 . V_19 . V_36 , V_19 . V_35 ) ;
V_76 . V_35 = V_74 ;
V_76 . V_80 = V_84 ;
V_76 . V_82 = V_2 -> V_3 -> V_26 [ V_28 -> V_23 . V_78 ] . V_73 ;
V_21 = F_14 ( & V_2 -> V_17 -> V_23 . V_24 , V_35 , V_83 ,
NULL , & V_76 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 -> V_12 ,
L_17 ,
V_30 , V_76 . V_82 . V_59 , V_76 . V_82 . V_60 , V_76 . V_82 . V_31 , V_76 . V_82 . V_32 ,
V_76 . V_35 ) ;
return 0 ;
}
static unsigned int F_21 ( struct V_1 * V_2 , struct V_54 * V_28 )
{
return V_2 -> V_3 -> V_26 [ V_28 -> V_23 . V_78 ] . V_65 ;
}
void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_7 * V_4 = & V_2 -> V_3 -> V_4 ;
struct V_54 * V_26 [ V_85 ] = { NULL , } ;
struct V_86 * V_23 ;
struct V_87 * V_88 ;
unsigned long V_89 ;
unsigned int V_20 ;
int V_21 ;
V_88 = F_23 ( V_4 -> V_5 -> V_6 ) ;
V_4 -> V_29 = 0 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_55 -> V_56 ; ++ V_20 ) {
struct V_54 * V_28 = V_2 -> V_28 [ V_20 ] ;
unsigned int V_90 ;
if ( ! V_2 -> V_3 -> V_26 [ V_20 ] . V_27 ) {
V_4 -> V_26 [ V_20 ] = NULL ;
continue;
}
V_4 -> V_26 [ V_20 ] = V_28 ;
for ( V_90 = V_4 -> V_29 ++ ; V_90 > 0 ; -- V_90 ) {
if ( F_21 ( V_2 , V_26 [ V_90 - 1 ] ) <= F_21 ( V_2 , V_28 ) )
break;
V_26 [ V_90 ] = V_26 [ V_90 - 1 ] ;
}
V_26 [ V_90 ] = V_28 ;
}
for ( V_20 = 0 ; V_20 < V_2 -> V_55 -> V_91 ; ++ V_20 ) {
struct V_54 * V_28 = V_26 [ V_20 ] ;
if ( ! V_28 ) {
V_2 -> V_17 -> V_26 [ V_20 ] . V_28 = NULL ;
continue;
}
V_2 -> V_17 -> V_26 [ V_20 ] . V_28 = V_28 ;
V_28 -> V_74 = V_20 ;
V_28 -> V_23 . V_92 = V_20 ;
F_13 ( V_2 -> V_12 , L_18 ,
V_30 , V_28 -> V_23 . V_78 , V_20 ) ;
V_21 = F_20 ( V_2 , V_28 , V_20 ) ;
if ( V_21 < 0 )
F_9 ( V_2 -> V_12 ,
L_19 ,
V_30 , V_28 -> V_23 . V_78 ) ;
}
F_24 (entity, &pipe->entities, list_pipe) {
if ( V_23 -> type == V_93 ) {
struct V_54 * V_28 = F_25 ( & V_23 -> V_24 ) ;
if ( ! V_4 -> V_26 [ V_28 -> V_23 . V_78 ] ) {
F_26 ( V_88 , V_23 -> V_94 -> V_95 ,
V_96 ) ;
continue;
}
}
F_27 ( V_23 , V_4 , V_88 ) ;
if ( V_23 -> V_97 -> V_98 ) {
V_23 -> V_97 -> V_98 ( V_23 , V_4 , V_88 ,
V_99 ) ;
V_23 -> V_97 -> V_98 ( V_23 , V_4 , V_88 ,
V_100 ) ;
V_23 -> V_97 -> V_98 ( V_23 , V_4 , V_88 ,
V_101 ) ;
}
}
F_28 ( V_88 ) ;
if ( ! V_2 -> V_3 -> V_29 && V_4 -> V_29 ) {
F_29 ( V_2 , V_102 , 0 ) ;
F_29 ( V_2 , V_103 , V_104 ) ;
F_30 ( & V_4 -> V_105 , V_89 ) ;
F_31 ( V_4 ) ;
F_32 ( & V_4 -> V_105 , V_89 ) ;
} else if ( V_2 -> V_3 -> V_29 && ! V_4 -> V_29 ) {
F_29 ( V_2 , V_103 , 0 ) ;
F_8 ( V_4 ) ;
}
}
int F_33 ( struct V_11 * V_12 , struct V_106 * V_107 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
return F_34 ( V_2 -> V_108 , V_107 -> V_109 , V_107 -> V_110 ,
V_111 , V_112 ) ;
}
void F_35 ( struct V_11 * V_12 , struct V_106 * V_107 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_36 ( V_2 -> V_108 , V_107 -> V_109 , V_107 -> V_110 ,
V_111 , V_112 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
const T_1 V_89 = V_113 | V_114 ;
unsigned int V_20 ;
int V_21 ;
if ( ! V_2 -> V_17 || ! V_2 -> V_46 )
return - V_115 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_55 -> V_56 ; ++ V_20 ) {
struct V_54 * V_28 = V_2 -> V_28 [ V_20 ] ;
V_21 = F_38 ( & V_28 -> V_23 . V_24 . V_23 ,
V_43 ,
& V_2 -> V_17 -> V_23 . V_24 . V_23 ,
V_20 , V_89 ) ;
if ( V_21 < 0 )
return V_21 ;
V_28 -> V_23 . V_116 = & V_2 -> V_17 -> V_23 . V_24 . V_23 ;
V_28 -> V_23 . V_92 = V_20 ;
}
V_21 = F_38 ( & V_2 -> V_17 -> V_23 . V_24 . V_23 ,
V_2 -> V_17 -> V_23 . V_25 ,
& V_2 -> V_42 [ 0 ] -> V_23 . V_24 . V_23 ,
V_41 , V_89 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_17 -> V_23 . V_116 = & V_2 -> V_42 [ 0 ] -> V_23 . V_24 . V_23 ;
V_2 -> V_17 -> V_23 . V_92 = V_41 ;
V_21 = F_38 ( & V_2 -> V_42 [ 0 ] -> V_23 . V_24 . V_23 ,
V_43 ,
& V_2 -> V_46 -> V_23 . V_24 . V_23 ,
V_45 , V_89 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
unsigned int V_20 ;
V_2 -> V_3 = F_40 ( V_2 -> V_12 , sizeof( * V_2 -> V_3 ) , V_117 ) ;
if ( ! V_2 -> V_3 )
return - V_118 ;
V_4 = & V_2 -> V_3 -> V_4 ;
F_41 ( V_4 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_55 -> V_56 ; ++ V_20 ) {
struct V_54 * V_119 = V_2 -> V_28 [ V_20 ] ;
F_42 ( & V_119 -> V_23 . V_120 , & V_4 -> V_121 ) ;
}
F_42 ( & V_2 -> V_17 -> V_23 . V_120 , & V_4 -> V_121 ) ;
F_42 ( & V_2 -> V_42 [ 0 ] -> V_23 . V_120 , & V_4 -> V_121 ) ;
F_42 ( & V_2 -> V_46 -> V_23 . V_120 , & V_4 -> V_121 ) ;
V_4 -> V_17 = & V_2 -> V_17 -> V_23 ;
V_4 -> V_46 = & V_2 -> V_46 -> V_23 ;
V_4 -> V_5 = V_2 -> V_42 [ 0 ] ;
V_4 -> V_5 -> V_4 = V_4 ;
V_4 -> V_122 = F_3 ;
return 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
}
