int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_6 ) ] ;
T_1 V_7 [ F_2 ( V_8 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_6 , V_5 , V_9 ,
V_10 ) ;
F_3 ( V_6 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_6 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_6 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_6 , V_5 , V_16 , 1 ) ;
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_5 ( struct V_1 * V_2 ,
T_2 V_14 ,
enum V_17 type , unsigned int V_18 ,
unsigned int V_19 , struct V_3
* V_20 , unsigned int * V_12 )
{
T_1 V_7 [ F_2 ( V_21 ) ] ;
T_1 V_5 [ F_2 ( V_22 ) ] ;
int V_23 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_22 , V_5 , V_9 ,
V_24 ) ;
if ( V_20 ) {
F_3 ( V_22 , V_5 , V_25 , 1 ) ;
F_3 ( V_22 , V_5 , V_26 , V_20 -> V_13 ) ;
}
F_3 ( V_22 , V_5 , V_11 , type ) ;
F_3 ( V_22 , V_5 , V_18 , V_18 ) ;
F_3 ( V_22 , V_5 , V_19 , V_19 ) ;
if ( V_14 ) {
F_3 ( V_22 , V_5 , V_15 , V_14 ) ;
F_3 ( V_22 , V_5 , V_16 , 1 ) ;
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_23 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
if ( ! V_23 )
* V_12 = F_6 ( V_21 , V_7 ,
V_12 ) ;
return V_23 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_27 ) ] ;
T_1 V_7 [ F_2 ( V_28 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_27 , V_5 , V_9 ,
V_29 ) ;
F_3 ( V_27 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_27 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_27 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_27 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_20 )
{
T_1 V_5 [ F_2 ( V_30 ) ] ;
T_1 V_7 [ F_2 ( V_31 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_30 , V_5 , V_9 ,
V_32 ) ;
F_3 ( V_30 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_30 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_30 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_30 , V_5 , V_16 , 1 ) ;
}
F_3 ( V_30 , V_5 , V_33 ,
V_34 ) ;
if ( V_20 ) {
F_3 ( V_30 , V_5 , V_25 , 1 ) ;
F_3 ( V_30 , V_5 , V_26 , V_20 -> V_13 ) ;
} else {
F_3 ( V_30 , V_5 , V_25 , 0 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
unsigned int * V_35 )
{
int V_36 = F_10 ( V_37 ) ;
T_1 V_7 [ F_2 ( V_38 ) ] ;
int V_23 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_37 , V_5 , V_9 ,
V_39 ) ;
F_3 ( V_37 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_37 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_37 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_37 , V_5 , V_16 , 1 ) ;
}
V_23 = F_4 ( V_2 , V_5 ,
V_36 , V_7 ,
sizeof( V_7 ) ) ;
if ( ! V_23 )
* V_35 = F_6 ( V_38 , V_7 ,
V_35 ) ;
return V_23 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_35 )
{
T_1 V_7 [ F_2 ( V_40 ) ] ;
T_1 V_5 [ F_2 ( V_41 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_41 , V_5 , V_9 ,
V_42 ) ;
F_3 ( V_41 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_41 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_41 , V_5 , V_35 , V_35 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_41 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_41 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_43 , int V_44 ,
struct V_3 * V_4 ,
unsigned V_35 ,
struct V_45 * V_46 )
{
unsigned int V_36 = F_10 ( V_47 ) +
V_46 -> V_48 * F_10 ( V_49 ) ;
T_1 V_7 [ F_2 ( V_50 ) ] ;
struct V_51 * V_52 ;
void * V_53 ;
void * V_54 ;
void * V_55 ;
T_1 * V_5 ;
int V_23 ;
V_5 = F_13 ( V_36 ) ;
if ( ! V_5 ) {
F_14 ( V_2 , L_1 ) ;
return - V_56 ;
}
F_3 ( V_47 , V_5 , V_9 , V_57 ) ;
F_3 ( V_47 , V_5 , V_58 , V_43 ) ;
F_3 ( V_47 , V_5 , V_59 , V_44 ) ;
F_3 ( V_47 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_47 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_47 , V_5 , V_60 , V_46 -> V_61 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_47 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_47 , V_5 , V_16 , 1 ) ;
}
V_53 = F_15 ( V_47 , V_5 , V_62 ) ;
F_3 ( V_62 , V_53 , V_35 , V_35 ) ;
F_3 ( V_62 , V_53 , V_63 , V_46 -> V_63 ) ;
F_3 ( V_62 , V_53 , V_64 , V_46 -> V_64 ) ;
V_54 = F_15 ( V_62 , V_53 ,
V_65 ) ;
memcpy ( V_54 , & V_46 -> V_66 , F_10 ( V_67 ) ) ;
V_55 = F_15 ( V_62 , V_53 , V_68 ) ;
if ( V_46 -> V_64 & V_69 ) {
int V_70 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_13 ;
if ( V_52 -> V_71 . type == V_72 )
continue;
F_3 ( V_49 , V_55 , V_73 ,
V_52 -> V_71 . type ) ;
if ( V_52 -> V_71 . type ==
V_74 ) {
V_13 = V_52 -> V_71 . V_4 -> V_13 ;
} else {
V_13 = V_52 -> V_71 . V_75 ;
}
F_3 ( V_49 , V_55 , V_76 , V_13 ) ;
V_55 += F_10 ( V_49 ) ;
V_70 ++ ;
}
F_3 ( V_62 , V_53 , V_77 ,
V_70 ) ;
}
if ( V_46 -> V_64 & V_78 ) {
int V_70 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
if ( V_52 -> V_71 . type !=
V_72 )
continue;
F_3 ( V_79 , V_55 , V_80 ,
V_52 -> V_71 . V_81 -> V_13 ) ;
V_55 += F_10 ( V_49 ) ;
V_70 ++ ;
}
F_3 ( V_62 , V_53 , V_82 ,
V_70 ) ;
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_23 = F_4 ( V_2 , V_5 , V_36 , V_7 ,
sizeof( V_7 ) ) ;
F_17 ( V_5 ) ;
return V_23 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_35 ,
struct V_45 * V_46 )
{
return F_12 ( V_2 , 0 , 0 , V_4 , V_35 , V_46 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_35 ,
int V_44 ,
struct V_45 * V_46 )
{
int V_43 ;
int V_83 = F_20 ( V_2 ,
V_84 .
V_85 ) ;
if ( ! V_83 )
return - V_86 ;
V_43 = 1 ;
return F_12 ( V_2 , V_43 , V_44 , V_4 , V_35 , V_46 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_61 )
{
T_1 V_7 [ F_2 ( V_87 ) ] ;
T_1 V_5 [ F_2 ( V_88 ) ] ;
int V_23 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_88 , V_5 , V_9 , V_89 ) ;
F_3 ( V_88 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_88 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_88 , V_5 , V_60 , V_61 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_88 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_88 , V_5 , V_16 , 1 ) ;
}
V_23 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
return V_23 ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_13 )
{
T_1 V_5 [ F_2 ( V_90 ) ] ;
T_1 V_7 [ F_2 ( V_91 ) ] ;
int V_23 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_90 , V_5 , V_9 ,
V_92 ) ;
V_23 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
if ( V_23 )
return V_23 ;
* V_13 = F_6 ( V_91 , V_7 , V_80 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_2 V_13 )
{
T_1 V_5 [ F_2 ( V_93 ) ] ;
T_1 V_7 [ F_2 ( V_94 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_93 , V_5 , V_9 ,
V_95 ) ;
F_3 ( V_93 , V_5 , V_80 , V_13 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_13 ,
T_3 * V_96 , T_3 * V_97 )
{
T_1 V_7 [ F_10 ( V_98 ) +
F_10 ( V_99 ) ] ;
T_1 V_5 [ F_2 ( V_100 ) ] ;
void * V_101 ;
int V_23 = 0 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_100 , V_5 , V_9 ,
V_102 ) ;
F_3 ( V_100 , V_5 , V_58 , 0 ) ;
F_3 ( V_100 , V_5 , V_80 , V_13 ) ;
V_23 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( V_23 )
return V_23 ;
V_101 = F_15 ( V_98 , V_7 , V_103 ) ;
* V_96 = F_25 ( V_99 , V_101 , V_96 ) ;
* V_97 = F_25 ( V_99 , V_101 , V_104 ) ;
return 0 ;
}
struct V_105 *
F_26 ( struct V_1 * V_2 , T_2 V_13 , int V_106 )
{
struct V_105 * V_107 ;
int V_108 =
F_10 ( V_98 ) +
F_10 ( V_99 ) * V_106 ;
V_107 = F_27 ( sizeof( * V_107 ) + V_108 , V_109 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_13 = V_13 ;
V_107 -> V_106 = V_106 ;
V_107 -> V_108 = V_108 ;
return V_107 ;
}
void F_28 ( struct V_105 * V_107 )
{
F_29 ( V_107 ) ;
}
int
F_30 ( struct V_1 * V_2 , struct V_105 * V_107 )
{
T_1 V_5 [ F_2 ( V_100 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_100 , V_5 , V_9 ,
V_102 ) ;
F_3 ( V_100 , V_5 , V_58 , 0 ) ;
F_3 ( V_100 , V_5 , V_80 , V_107 -> V_13 ) ;
F_3 ( V_100 , V_5 , V_110 , V_107 -> V_106 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) ,
V_107 -> V_7 , V_107 -> V_108 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_105 * V_107 , T_2 V_13 ,
T_3 * V_96 , T_3 * V_97 )
{
int V_61 = V_13 - V_107 -> V_13 ;
void * V_101 ;
if ( V_61 < 0 || V_61 >= V_107 -> V_106 ) {
F_14 ( V_2 , L_2 ,
V_13 , V_107 -> V_13 , V_107 -> V_13 + V_107 -> V_106 - 1 ) ;
return;
}
V_101 = F_15 ( V_98 , V_107 -> V_7 ,
V_103 [ V_61 ] ) ;
* V_96 = F_25 ( V_99 , V_101 , V_96 ) ;
* V_97 = F_25 ( V_99 , V_101 , V_104 ) ;
}
