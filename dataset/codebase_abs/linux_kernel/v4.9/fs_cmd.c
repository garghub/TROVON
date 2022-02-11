int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_6 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_8 ) ] = { 0 } ;
F_3 ( V_6 , V_5 , V_9 ,
V_10 ) ;
F_3 ( V_6 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_6 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_6 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_6 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_5 ( struct V_1 * V_2 ,
T_2 V_14 ,
enum V_17 V_18 ,
enum V_19 type , unsigned int V_20 ,
unsigned int V_21 , struct V_3
* V_22 , unsigned int * V_12 )
{
T_1 V_7 [ F_2 ( V_23 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_24 ) ] = { 0 } ;
int V_25 ;
F_3 ( V_24 , V_5 , V_9 ,
V_26 ) ;
F_3 ( V_24 , V_5 , V_11 , type ) ;
F_3 ( V_24 , V_5 , V_20 , V_20 ) ;
F_3 ( V_24 , V_5 , V_21 , V_21 ) ;
if ( V_14 ) {
F_3 ( V_24 , V_5 , V_15 , V_14 ) ;
F_3 ( V_24 , V_5 , V_16 , 1 ) ;
}
switch ( V_18 ) {
case V_27 :
if ( V_22 ) {
F_3 ( V_24 , V_5 , V_28 , 1 ) ;
F_3 ( V_24 , V_5 , V_29 , V_22 -> V_13 ) ;
}
break;
case V_30 :
F_3 ( V_24 , V_5 , V_18 , 0x1 ) ;
if ( V_22 )
F_3 ( V_24 , V_5 , V_31 ,
V_22 -> V_13 ) ;
break;
}
V_25 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( ! V_25 )
* V_12 = F_6 ( V_23 , V_7 ,
V_12 ) ;
return V_25 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_32 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_33 ) ] = { 0 } ;
F_3 ( V_32 , V_5 , V_9 ,
V_34 ) ;
F_3 ( V_32 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_32 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_32 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_32 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_22 )
{
T_1 V_5 [ F_2 ( V_35 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_36 ) ] = { 0 } ;
F_3 ( V_35 , V_5 , V_9 ,
V_37 ) ;
F_3 ( V_35 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_35 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_18 == V_30 ) {
F_3 ( V_35 , V_5 , V_38 ,
V_39 ) ;
if ( V_22 ) {
F_3 ( V_35 , V_5 ,
V_31 , V_22 -> V_13 ) ;
} else {
F_3 ( V_35 , V_5 ,
V_31 , 0 ) ;
}
} else {
if ( V_4 -> V_14 ) {
F_3 ( V_35 , V_5 , V_15 ,
V_4 -> V_14 ) ;
F_3 ( V_35 , V_5 , V_16 , 1 ) ;
}
F_3 ( V_35 , V_5 , V_38 ,
V_40 ) ;
if ( V_22 ) {
F_3 ( V_35 , V_5 , V_28 , 1 ) ;
F_3 ( V_35 , V_5 , V_29 ,
V_22 -> V_13 ) ;
} else {
F_3 ( V_35 , V_5 , V_28 , 0 ) ;
}
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
unsigned int * V_41 )
{
T_1 V_7 [ F_2 ( V_42 ) ] = { 0 } ;
int V_43 = F_10 ( V_44 ) ;
int V_25 ;
F_3 ( V_44 , V_5 , V_9 ,
V_45 ) ;
F_3 ( V_44 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_44 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_44 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_44 , V_5 , V_16 , 1 ) ;
}
V_25 = F_4 ( V_2 , V_5 , V_43 , V_7 , sizeof( V_7 ) ) ;
if ( ! V_25 )
* V_41 = F_6 ( V_42 , V_7 ,
V_41 ) ;
return V_25 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_41 )
{
T_1 V_7 [ F_2 ( V_46 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_47 ) ] = { 0 } ;
F_3 ( V_47 , V_5 , V_9 ,
V_48 ) ;
F_3 ( V_47 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_47 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_47 , V_5 , V_41 , V_41 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_47 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_47 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_49 , int V_50 ,
struct V_3 * V_4 ,
unsigned V_41 ,
struct V_51 * V_52 )
{
unsigned int V_43 = F_10 ( V_53 ) +
V_52 -> V_54 * F_10 ( V_55 ) ;
T_1 V_7 [ F_2 ( V_56 ) ] = { 0 } ;
struct V_57 * V_58 ;
void * V_59 ;
void * V_60 ;
void * V_61 ;
T_1 * V_5 ;
int V_25 ;
V_5 = F_13 ( V_43 ) ;
if ( ! V_5 ) {
F_14 ( V_2 , L_1 ) ;
return - V_62 ;
}
F_3 ( V_53 , V_5 , V_9 , V_63 ) ;
F_3 ( V_53 , V_5 , V_18 , V_49 ) ;
F_3 ( V_53 , V_5 , V_64 , V_50 ) ;
F_3 ( V_53 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_53 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_53 , V_5 , V_65 , V_52 -> V_66 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_53 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_53 , V_5 , V_16 , 1 ) ;
}
V_59 = F_15 ( V_53 , V_5 , V_67 ) ;
F_3 ( V_67 , V_59 , V_41 , V_41 ) ;
F_3 ( V_67 , V_59 , V_68 , V_52 -> V_68 ) ;
F_3 ( V_67 , V_59 , V_69 , V_52 -> V_69 ) ;
V_60 = F_15 ( V_67 , V_59 ,
V_70 ) ;
memcpy ( V_60 , & V_52 -> V_71 , F_10 ( V_72 ) ) ;
V_61 = F_15 ( V_67 , V_59 , V_73 ) ;
if ( V_52 -> V_69 & V_74 ) {
int V_75 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_13 ;
if ( V_58 -> V_76 . type == V_77 )
continue;
F_3 ( V_55 , V_61 , V_78 ,
V_58 -> V_76 . type ) ;
if ( V_58 -> V_76 . type ==
V_79 ) {
V_13 = V_58 -> V_76 . V_4 -> V_13 ;
} else {
V_13 = V_58 -> V_76 . V_80 ;
}
F_3 ( V_55 , V_61 , V_81 , V_13 ) ;
V_61 += F_10 ( V_55 ) ;
V_75 ++ ;
}
F_3 ( V_67 , V_59 , V_82 ,
V_75 ) ;
}
if ( V_52 -> V_69 & V_83 ) {
int V_75 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
if ( V_58 -> V_76 . type !=
V_77 )
continue;
F_3 ( V_84 , V_61 , V_85 ,
V_58 -> V_76 . V_86 -> V_13 ) ;
V_61 += F_10 ( V_55 ) ;
V_75 ++ ;
}
F_3 ( V_67 , V_59 , V_87 ,
V_75 ) ;
}
V_25 = F_4 ( V_2 , V_5 , V_43 , V_7 , sizeof( V_7 ) ) ;
F_17 ( V_5 ) ;
return V_25 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_41 ,
struct V_51 * V_52 )
{
return F_12 ( V_2 , 0 , 0 , V_4 , V_41 , V_52 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_41 ,
int V_50 ,
struct V_51 * V_52 )
{
int V_49 ;
int V_88 = F_20 ( V_2 ,
V_89 .
V_90 ) ;
if ( ! V_88 )
return - V_91 ;
V_49 = 1 ;
return F_12 ( V_2 , V_49 , V_50 , V_4 , V_41 , V_52 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_66 )
{
T_1 V_7 [ F_2 ( V_92 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_93 ) ] = { 0 } ;
F_3 ( V_93 , V_5 , V_9 , V_94 ) ;
F_3 ( V_93 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_93 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_93 , V_5 , V_65 , V_66 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_93 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_93 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_13 )
{
T_1 V_5 [ F_2 ( V_95 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_96 ) ] = { 0 } ;
int V_25 ;
F_3 ( V_95 , V_5 , V_9 ,
V_97 ) ;
V_25 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( ! V_25 )
* V_13 = F_6 ( V_96 , V_7 , V_85 ) ;
return V_25 ;
}
int F_23 ( struct V_1 * V_2 , T_2 V_13 )
{
T_1 V_5 [ F_2 ( V_98 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_99 ) ] = { 0 } ;
F_3 ( V_98 , V_5 , V_9 ,
V_100 ) ;
F_3 ( V_98 , V_5 , V_85 , V_13 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_13 ,
T_3 * V_101 , T_3 * V_102 )
{
T_1 V_7 [ F_10 ( V_103 ) +
F_10 ( V_104 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_105 ) ] = { 0 } ;
void * V_106 ;
int V_25 = 0 ;
F_3 ( V_105 , V_5 , V_9 ,
V_107 ) ;
F_3 ( V_105 , V_5 , V_18 , 0 ) ;
F_3 ( V_105 , V_5 , V_85 , V_13 ) ;
V_25 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( V_25 )
return V_25 ;
V_106 = F_15 ( V_103 , V_7 , V_108 ) ;
* V_101 = F_25 ( V_104 , V_106 , V_101 ) ;
* V_102 = F_25 ( V_104 , V_106 , V_109 ) ;
return 0 ;
}
struct V_110 *
F_26 ( struct V_1 * V_2 , T_2 V_13 , int V_111 )
{
struct V_110 * V_112 ;
int V_113 =
F_10 ( V_103 ) +
F_10 ( V_104 ) * V_111 ;
V_112 = F_27 ( sizeof( * V_112 ) + V_113 , V_114 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_13 = V_13 ;
V_112 -> V_111 = V_111 ;
V_112 -> V_113 = V_113 ;
return V_112 ;
}
void F_28 ( struct V_110 * V_112 )
{
F_29 ( V_112 ) ;
}
int
F_30 ( struct V_1 * V_2 , struct V_110 * V_112 )
{
T_1 V_5 [ F_2 ( V_105 ) ] = { 0 } ;
F_3 ( V_105 , V_5 , V_9 ,
V_107 ) ;
F_3 ( V_105 , V_5 , V_18 , 0 ) ;
F_3 ( V_105 , V_5 , V_85 , V_112 -> V_13 ) ;
F_3 ( V_105 , V_5 , V_115 , V_112 -> V_111 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_112 -> V_7 , V_112 -> V_113 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_110 * V_112 , T_2 V_13 ,
T_3 * V_101 , T_3 * V_102 )
{
int V_66 = V_13 - V_112 -> V_13 ;
void * V_106 ;
if ( V_66 < 0 || V_66 >= V_112 -> V_111 ) {
F_14 ( V_2 , L_2 ,
V_13 , V_112 -> V_13 , V_112 -> V_13 + V_112 -> V_111 - 1 ) ;
return;
}
V_106 = F_15 ( V_103 , V_112 -> V_7 ,
V_108 [ V_66 ] ) ;
* V_101 = F_25 ( V_104 , V_106 , V_101 ) ;
* V_102 = F_25 ( V_104 , V_106 , V_109 ) ;
}
int F_32 ( struct V_1 * V_2 ,
int V_116 ,
T_4 V_117 ,
void * V_118 ,
T_1 * V_119 )
{
T_1 V_7 [ F_2 ( V_120 ) ] ;
T_1 V_5 [ F_2 ( V_121 ) +
( V_122 / sizeof( T_1 ) ) ] ;
void * V_123 = F_15 ( V_121 , V_5 ,
V_118 ) ;
void * V_124 = F_15 ( V_123 , V_123 ,
V_118 ) ;
int V_43 = V_124 - ( void * ) V_5 + V_117 ;
int V_25 ;
if ( V_117 > V_122 )
return - V_125 ;
memset ( V_5 , 0 , V_43 ) ;
F_3 ( V_121 , V_5 , V_9 ,
V_126 ) ;
F_3 ( V_123 , V_123 , V_127 , V_117 ) ;
F_3 ( V_123 , V_123 , V_116 , V_116 ) ;
memcpy ( V_124 , V_118 , V_117 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_25 = F_4 ( V_2 , V_5 , V_43 , V_7 , sizeof( V_7 ) ) ;
* V_119 = F_6 ( V_120 , V_7 , V_119 ) ;
return V_25 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_119 )
{
T_1 V_5 [ F_2 ( V_128 ) ] ;
T_1 V_7 [ F_2 ( V_129 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_128 , V_5 , V_9 ,
V_130 ) ;
F_3 ( V_128 , V_5 , V_119 , V_119 ) ;
F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
