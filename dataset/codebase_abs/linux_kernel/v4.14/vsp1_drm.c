static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 )
V_5 -> V_6 ( V_5 -> V_7 , V_3 ) ;
}
int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
if ( ! V_11 )
return - V_12 ;
return 0 ;
}
int F_5 ( struct V_8 * V_9 , unsigned int V_13 ,
const struct V_14 * V_15 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
const char * V_20 ;
unsigned int V_21 ;
int V_22 ;
if ( V_13 >= V_11 -> V_23 -> V_24 )
return - V_25 ;
V_5 = & V_11 -> V_26 -> V_2 [ V_13 ] ;
V_2 = & V_5 -> V_2 ;
V_17 = F_6 ( & V_2 -> V_17 -> V_27 ) ;
V_20 = V_2 -> V_17 -> type == V_28 ? L_1 : L_2 ;
if ( ! V_15 ) {
V_22 = F_7 ( V_2 ) ;
if ( V_22 == - V_29 )
F_8 ( V_11 -> V_9 , L_3 ) ;
F_9 ( & V_2 -> V_30 -> V_31 . V_27 . V_31 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_2 -> V_32 ) ; ++ V_21 ) {
struct V_33 * V_34 = V_2 -> V_32 [ V_21 ] ;
if ( ! V_34 )
continue;
F_11 ( F_12 ( & V_34 -> V_31 . V_35 ) ) ;
F_13 ( & V_34 -> V_31 . V_35 ) ;
V_2 -> V_32 [ V_21 ] = NULL ;
V_17 -> V_32 [ V_34 -> V_36 ] . V_34 = NULL ;
}
V_5 -> V_6 = NULL ;
V_2 -> V_37 = 0 ;
F_14 ( V_2 -> V_30 -> V_38 ) ;
F_15 ( V_11 ) ;
F_16 ( V_11 -> V_9 , L_4 , V_39 ) ;
return 0 ;
}
F_16 ( V_11 -> V_9 , L_5 ,
V_39 , V_13 , V_15 -> V_40 , V_15 -> V_41 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_42 = V_43 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_17 -> V_44 ; ++ V_21 ) {
V_19 . V_45 = V_21 ;
V_19 . V_19 . V_40 = V_15 -> V_40 ;
V_19 . V_19 . V_41 = V_15 -> V_41 ;
V_19 . V_19 . V_46 = V_47 ;
V_19 . V_19 . V_48 = V_49 ;
V_22 = F_17 ( & V_2 -> V_17 -> V_27 , V_45 ,
V_50 , NULL , & V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_6 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_20 , V_21 ) ;
}
V_19 . V_45 = V_2 -> V_17 -> V_44 ;
V_19 . V_19 . V_40 = V_15 -> V_40 ;
V_19 . V_19 . V_41 = V_15 -> V_41 ;
V_19 . V_19 . V_46 = V_47 ;
V_19 . V_19 . V_48 = V_49 ;
V_22 = F_17 ( & V_2 -> V_17 -> V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_6 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_20 , V_21 ) ;
V_19 . V_45 = V_51 ;
V_22 = F_17 ( & V_2 -> V_30 -> V_31 . V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_7 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_2 -> V_30 -> V_31 . V_52 ) ;
V_19 . V_45 = V_53 ;
V_22 = F_17 ( & V_2 -> V_30 -> V_31 . V_27 , V_45 , V_54 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_8 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_2 -> V_30 -> V_31 . V_52 ) ;
V_19 . V_45 = V_55 ;
V_22 = F_17 ( & V_2 -> V_56 -> V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_9 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_13 ) ;
if ( V_19 . V_19 . V_40 != V_15 -> V_40 ||
V_19 . V_19 . V_41 != V_15 -> V_41 ||
V_19 . V_19 . V_46 != V_47 ) {
F_16 ( V_11 -> V_9 , L_10 , V_39 ) ;
return - V_57 ;
}
V_22 = F_18 ( V_11 ) ;
if ( V_22 < 0 )
return V_22 ;
V_5 -> V_6 = V_15 -> V_58 ;
V_5 -> V_7 = V_15 -> V_59 ;
V_22 = F_19 ( & V_2 -> V_30 -> V_31 . V_27 . V_31 ,
& V_2 -> V_2 ) ;
if ( V_22 < 0 ) {
F_16 ( V_11 -> V_9 , L_11 , V_39 ) ;
F_15 ( V_11 ) ;
return V_22 ;
}
F_20 ( V_11 , V_60 , 0 ) ;
F_20 ( V_11 , V_61 , 0 ) ;
F_16 ( V_11 -> V_9 , L_12 , V_39 ) ;
return 0 ;
}
void F_21 ( struct V_8 * V_9 , unsigned int V_13 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_4 * V_5 = & V_11 -> V_26 -> V_2 [ V_13 ] ;
V_5 -> V_62 = V_5 -> V_2 . V_37 != 0 ;
}
int F_22 ( struct V_8 * V_9 , unsigned int V_13 ,
unsigned int V_63 ,
const struct V_64 * V_15 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_4 * V_5 = & V_11 -> V_26 -> V_2 [ V_13 ] ;
const struct V_65 * V_66 ;
struct V_33 * V_34 ;
if ( V_63 >= V_11 -> V_23 -> V_67 )
return - V_25 ;
V_34 = V_11 -> V_34 [ V_63 ] ;
if ( ! V_15 ) {
F_16 ( V_11 -> V_9 , L_13 , V_39 ,
V_63 ) ;
V_5 -> V_2 . V_32 [ V_63 ] = NULL ;
return 0 ;
}
F_16 ( V_11 -> V_9 ,
L_14 ,
V_39 , V_63 ,
V_15 -> V_68 . V_69 , V_15 -> V_68 . V_70 , V_15 -> V_68 . V_40 , V_15 -> V_68 . V_41 ,
V_15 -> V_71 . V_69 , V_15 -> V_71 . V_70 , V_15 -> V_71 . V_40 , V_15 -> V_71 . V_41 ,
V_15 -> V_72 , V_15 -> V_73 , & V_15 -> V_74 [ 0 ] , & V_15 -> V_74 [ 1 ] ,
& V_15 -> V_74 [ 2 ] , V_15 -> V_75 ) ;
V_66 = F_23 ( V_11 , V_15 -> V_72 ) ;
if ( ! V_66 ) {
F_16 ( V_11 -> V_9 , L_15 ,
V_15 -> V_72 ) ;
return - V_25 ;
}
V_34 -> V_66 = V_66 ;
V_34 -> V_19 . V_76 = V_66 -> V_77 ;
V_34 -> V_19 . V_78 [ 0 ] . V_79 = V_15 -> V_73 ;
V_34 -> V_19 . V_78 [ 1 ] . V_79 = V_15 -> V_73 ;
V_34 -> V_80 = V_15 -> V_80 ;
V_34 -> V_74 . V_81 [ 0 ] = V_15 -> V_74 [ 0 ] ;
V_34 -> V_74 . V_81 [ 1 ] = V_15 -> V_74 [ 1 ] ;
V_34 -> V_74 . V_81 [ 2 ] = V_15 -> V_74 [ 2 ] ;
V_11 -> V_26 -> V_32 [ V_63 ] . V_82 = V_15 -> V_68 ;
V_11 -> V_26 -> V_32 [ V_63 ] . V_83 = V_15 -> V_71 ;
V_11 -> V_26 -> V_32 [ V_63 ] . V_75 = V_15 -> V_75 ;
V_5 -> V_2 . V_32 [ V_63 ] = V_34 ;
return 0 ;
}
static int F_24 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_33 * V_34 , unsigned int V_36 )
{
struct V_84 V_85 ;
struct V_18 V_19 ;
const struct V_86 * V_82 ;
int V_22 ;
V_82 = & V_11 -> V_26 -> V_32 [ V_34 -> V_31 . V_52 ] . V_82 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_42 = V_43 ;
V_19 . V_45 = V_51 ;
V_19 . V_19 . V_40 = V_82 -> V_40 + V_82 -> V_69 ;
V_19 . V_19 . V_41 = V_82 -> V_41 + V_82 -> V_70 ;
V_19 . V_19 . V_46 = V_34 -> V_66 -> V_87 ;
V_19 . V_19 . V_48 = V_49 ;
V_22 = F_17 ( & V_34 -> V_31 . V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 ,
L_16 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_34 -> V_31 . V_52 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_42 = V_43 ;
V_85 . V_45 = V_51 ;
V_85 . V_88 = V_89 ;
V_85 . V_90 = * V_82 ;
V_22 = F_17 ( & V_34 -> V_31 . V_27 , V_45 , V_91 , NULL ,
& V_85 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 ,
L_17 ,
V_39 , V_85 . V_90 . V_69 , V_85 . V_90 . V_70 , V_85 . V_90 . V_40 , V_85 . V_90 . V_41 ,
V_34 -> V_31 . V_52 ) ;
V_19 . V_45 = V_53 ;
V_22 = F_17 ( & V_34 -> V_31 . V_27 , V_45 , V_54 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 ,
L_18 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_34 -> V_31 . V_52 ) ;
V_19 . V_19 . V_46 = V_47 ;
V_22 = F_17 ( & V_34 -> V_31 . V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
V_19 . V_45 = V_36 ;
V_22 = F_17 ( & V_2 -> V_17 -> V_27 , V_45 , V_50 , NULL ,
& V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 , L_19 ,
V_39 , V_19 . V_19 . V_40 , V_19 . V_19 . V_41 ,
V_19 . V_19 . V_46 , V_19 . V_45 ) ;
V_85 . V_45 = V_36 ;
V_85 . V_88 = V_92 ;
V_85 . V_90 = V_11 -> V_26 -> V_32 [ V_34 -> V_31 . V_52 ] . V_83 ;
V_22 = F_17 ( & V_2 -> V_17 -> V_27 , V_45 , V_91 , NULL ,
& V_85 ) ;
if ( V_22 < 0 )
return V_22 ;
F_16 ( V_11 -> V_9 ,
L_20 ,
V_39 , V_85 . V_90 . V_69 , V_85 . V_90 . V_70 , V_85 . V_90 . V_40 , V_85 . V_90 . V_41 ,
V_85 . V_45 ) ;
return 0 ;
}
static unsigned int F_25 ( struct V_10 * V_11 , struct V_33 * V_34 )
{
return V_11 -> V_26 -> V_32 [ V_34 -> V_31 . V_52 ] . V_75 ;
}
void F_26 ( struct V_8 * V_9 , unsigned int V_13 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_4 * V_5 = & V_11 -> V_26 -> V_2 [ V_13 ] ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_33 * V_32 [ V_93 ] = { NULL , } ;
struct V_16 * V_17 = F_6 ( & V_2 -> V_17 -> V_27 ) ;
struct V_94 * V_31 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
const char * V_20 ;
unsigned long V_98 ;
unsigned int V_21 ;
int V_22 ;
V_20 = V_2 -> V_17 -> type == V_28 ? L_1 : L_2 ;
V_97 = F_27 ( V_2 -> V_30 -> V_38 ) ;
V_2 -> V_37 = 0 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_23 -> V_67 ; ++ V_21 ) {
struct V_33 * V_34 = V_11 -> V_34 [ V_21 ] ;
unsigned int V_99 ;
if ( ! V_2 -> V_32 [ V_21 ] )
continue;
for ( V_99 = V_2 -> V_37 ++ ; V_99 > 0 ; -- V_99 ) {
if ( F_25 ( V_11 , V_32 [ V_99 - 1 ] ) <= F_25 ( V_11 , V_34 ) )
break;
V_32 [ V_99 ] = V_32 [ V_99 - 1 ] ;
}
V_32 [ V_99 ] = V_34 ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_17 -> V_44 ; ++ V_21 ) {
struct V_33 * V_34 = V_32 [ V_21 ] ;
if ( ! V_34 ) {
V_17 -> V_32 [ V_21 ] . V_34 = NULL ;
continue;
}
if ( F_12 ( & V_34 -> V_31 . V_35 ) )
F_28 ( & V_34 -> V_31 . V_35 , & V_2 -> V_100 ) ;
V_17 -> V_32 [ V_21 ] . V_34 = V_34 ;
V_34 -> V_36 = V_21 ;
V_34 -> V_31 . V_101 = V_2 -> V_17 ;
V_34 -> V_31 . V_102 = V_21 ;
F_16 ( V_11 -> V_9 , L_21 ,
V_39 , V_34 -> V_31 . V_52 , V_20 , V_21 ) ;
V_22 = F_24 ( V_11 , V_2 , V_34 , V_21 ) ;
if ( V_22 < 0 )
F_8 ( V_11 -> V_9 ,
L_22 ,
V_39 , V_34 -> V_31 . V_52 ) ;
}
F_29 (entity, next, &pipe->entities, list_pipe) {
if ( V_31 -> type == V_103 &&
! V_2 -> V_32 [ V_31 -> V_52 ] ) {
F_30 ( V_97 , V_31 -> V_104 -> V_105 ,
V_106 ) ;
F_13 ( & V_31 -> V_35 ) ;
continue;
}
F_31 ( V_31 , V_2 , V_97 ) ;
if ( V_31 -> V_107 -> V_108 ) {
V_31 -> V_107 -> V_108 ( V_31 , V_2 , V_97 ,
V_109 ) ;
V_31 -> V_107 -> V_108 ( V_31 , V_2 , V_97 ,
V_110 ) ;
V_31 -> V_107 -> V_108 ( V_31 , V_2 , V_97 ,
V_111 ) ;
}
}
F_32 ( V_97 ) ;
if ( ! V_5 -> V_62 && V_2 -> V_37 ) {
F_33 ( & V_2 -> V_112 , V_98 ) ;
F_34 ( V_2 ) ;
F_35 ( & V_2 -> V_112 , V_98 ) ;
} else if ( V_5 -> V_62 && ! V_2 -> V_37 ) {
F_7 ( V_2 ) ;
}
}
int F_36 ( struct V_8 * V_9 , struct V_113 * V_114 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_37 ( V_11 -> V_115 , V_114 -> V_116 , V_114 -> V_117 ,
V_118 , V_119 ) ;
}
void F_38 ( struct V_8 * V_9 , struct V_113 * V_114 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_39 ( V_11 -> V_115 , V_114 -> V_116 , V_114 -> V_117 ,
V_118 , V_119 ) ;
}
int F_40 ( struct V_10 * V_11 )
{
unsigned int V_21 ;
V_11 -> V_26 = F_41 ( V_11 -> V_9 , sizeof( * V_11 -> V_26 ) , V_120 ) ;
if ( ! V_11 -> V_26 )
return - V_121 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_23 -> V_24 ; ++ V_21 ) {
struct V_4 * V_5 = & V_11 -> V_26 -> V_2 [ V_21 ] ;
struct V_1 * V_2 = & V_5 -> V_2 ;
F_42 ( V_2 ) ;
V_2 -> V_17 = V_21 == 0 ? & V_11 -> V_17 -> V_31 : & V_11 -> V_122 -> V_31 ;
V_2 -> V_56 = & V_11 -> V_56 [ V_21 ] -> V_31 ;
V_2 -> V_30 = V_11 -> V_123 [ V_21 ] ;
V_2 -> V_30 -> V_2 = V_2 ;
V_2 -> V_124 = F_1 ;
V_2 -> V_17 -> V_101 = & V_2 -> V_30 -> V_31 ;
V_2 -> V_17 -> V_102 = 0 ;
V_2 -> V_30 -> V_31 . V_101 = V_2 -> V_56 ;
V_2 -> V_30 -> V_31 . V_102 = 0 ;
F_28 ( & V_2 -> V_17 -> V_35 , & V_2 -> V_100 ) ;
F_28 ( & V_2 -> V_56 -> V_35 , & V_2 -> V_100 ) ;
F_28 ( & V_2 -> V_30 -> V_31 . V_35 , & V_2 -> V_100 ) ;
}
for ( V_21 = 0 ; V_21 < V_11 -> V_23 -> V_67 ; ++ V_21 ) {
struct V_33 * V_125 = V_11 -> V_34 [ V_21 ] ;
F_43 ( & V_125 -> V_31 . V_35 ) ;
}
return 0 ;
}
void F_44 ( struct V_10 * V_11 )
{
}
