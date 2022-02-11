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
* V_22 , unsigned int * V_12 , T_1 V_23 )
{
int V_24 = ! ! ( V_23 & V_25 ) ;
T_1 V_7 [ F_2 ( V_26 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_27 ) ] = { 0 } ;
int V_28 ;
F_3 ( V_27 , V_5 , V_9 ,
V_29 ) ;
F_3 ( V_27 , V_5 , V_11 , type ) ;
F_3 ( V_27 , V_5 , V_20 , V_20 ) ;
F_3 ( V_27 , V_5 , V_21 , V_21 ) ;
if ( V_14 ) {
F_3 ( V_27 , V_5 , V_15 , V_14 ) ;
F_3 ( V_27 , V_5 , V_16 , 1 ) ;
}
F_3 ( V_27 , V_5 , V_30 , V_24 ) ;
F_3 ( V_27 , V_5 , V_31 , V_24 ) ;
switch ( V_18 ) {
case V_32 :
if ( V_22 ) {
F_3 ( V_27 , V_5 , V_33 , 1 ) ;
F_3 ( V_27 , V_5 , V_34 , V_22 -> V_13 ) ;
}
break;
case V_35 :
F_3 ( V_27 , V_5 , V_18 , 0x1 ) ;
if ( V_22 )
F_3 ( V_27 , V_5 , V_36 ,
V_22 -> V_13 ) ;
break;
}
V_28 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( ! V_28 )
* V_12 = F_6 ( V_26 , V_7 ,
V_12 ) ;
return V_28 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_37 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_38 ) ] = { 0 } ;
F_3 ( V_37 , V_5 , V_9 ,
V_39 ) ;
F_3 ( V_37 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_37 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_37 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_37 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_22 )
{
T_1 V_5 [ F_2 ( V_40 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_41 ) ] = { 0 } ;
F_3 ( V_40 , V_5 , V_9 ,
V_42 ) ;
F_3 ( V_40 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_40 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_18 == V_35 ) {
F_3 ( V_40 , V_5 , V_43 ,
V_44 ) ;
if ( V_22 ) {
F_3 ( V_40 , V_5 ,
V_36 , V_22 -> V_13 ) ;
} else {
F_3 ( V_40 , V_5 ,
V_36 , 0 ) ;
}
} else {
if ( V_4 -> V_14 ) {
F_3 ( V_40 , V_5 , V_15 ,
V_4 -> V_14 ) ;
F_3 ( V_40 , V_5 , V_16 , 1 ) ;
}
F_3 ( V_40 , V_5 , V_43 ,
V_45 ) ;
if ( V_22 ) {
F_3 ( V_40 , V_5 , V_33 , 1 ) ;
F_3 ( V_40 , V_5 , V_34 ,
V_22 -> V_13 ) ;
} else {
F_3 ( V_40 , V_5 , V_33 , 0 ) ;
}
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
unsigned int * V_46 )
{
T_1 V_7 [ F_2 ( V_47 ) ] = { 0 } ;
int V_48 = F_10 ( V_49 ) ;
int V_28 ;
F_3 ( V_49 , V_5 , V_9 ,
V_50 ) ;
F_3 ( V_49 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_49 , V_5 , V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_49 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_49 , V_5 , V_16 , 1 ) ;
}
V_28 = F_4 ( V_2 , V_5 , V_48 , V_7 , sizeof( V_7 ) ) ;
if ( ! V_28 )
* V_46 = F_6 ( V_47 , V_7 ,
V_46 ) ;
return V_28 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_46 )
{
T_1 V_7 [ F_2 ( V_51 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_52 ) ] = { 0 } ;
F_3 ( V_52 , V_5 , V_9 ,
V_53 ) ;
F_3 ( V_52 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_52 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_52 , V_5 , V_46 , V_46 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_52 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_52 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_54 , int V_55 ,
struct V_3 * V_4 ,
unsigned V_46 ,
struct V_56 * V_57 )
{
unsigned int V_48 = F_10 ( V_58 ) +
V_57 -> V_59 * F_10 ( V_60 ) ;
T_1 V_7 [ F_2 ( V_61 ) ] = { 0 } ;
struct V_62 * V_63 ;
void * V_64 ;
void * V_65 ;
void * V_66 ;
T_1 * V_5 ;
int V_28 ;
V_5 = F_13 ( V_48 ) ;
if ( ! V_5 ) {
F_14 ( V_2 , L_1 ) ;
return - V_67 ;
}
F_3 ( V_58 , V_5 , V_9 , V_68 ) ;
F_3 ( V_58 , V_5 , V_18 , V_54 ) ;
F_3 ( V_58 , V_5 , V_69 , V_55 ) ;
F_3 ( V_58 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_58 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_58 , V_5 , V_70 , V_57 -> V_71 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_58 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_58 , V_5 , V_16 , 1 ) ;
}
V_64 = F_15 ( V_58 , V_5 , V_72 ) ;
F_3 ( V_72 , V_64 , V_46 , V_46 ) ;
F_3 ( V_72 , V_64 , V_73 , V_57 -> V_73 ) ;
F_3 ( V_72 , V_64 , V_74 , V_57 -> V_74 ) ;
F_3 ( V_72 , V_64 , V_75 , V_57 -> V_75 ) ;
V_65 = F_15 ( V_72 , V_64 ,
V_76 ) ;
memcpy ( V_65 , & V_57 -> V_77 , F_10 ( V_78 ) ) ;
V_66 = F_15 ( V_72 , V_64 , V_79 ) ;
if ( V_57 -> V_74 & V_80 ) {
int V_81 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_13 ;
if ( V_63 -> V_82 . type == V_83 )
continue;
F_3 ( V_60 , V_66 , V_84 ,
V_63 -> V_82 . type ) ;
if ( V_63 -> V_82 . type ==
V_85 ) {
V_13 = V_63 -> V_82 . V_4 -> V_13 ;
} else {
V_13 = V_63 -> V_82 . V_86 ;
}
F_3 ( V_60 , V_66 , V_87 , V_13 ) ;
V_66 += F_10 ( V_60 ) ;
V_81 ++ ;
}
F_3 ( V_72 , V_64 , V_88 ,
V_81 ) ;
}
if ( V_57 -> V_74 & V_89 ) {
int V_81 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
if ( V_63 -> V_82 . type !=
V_83 )
continue;
F_3 ( V_90 , V_66 , V_91 ,
V_63 -> V_82 . V_92 -> V_13 ) ;
V_66 += F_10 ( V_60 ) ;
V_81 ++ ;
}
F_3 ( V_72 , V_64 , V_93 ,
V_81 ) ;
}
V_28 = F_4 ( V_2 , V_5 , V_48 , V_7 , sizeof( V_7 ) ) ;
F_17 ( V_5 ) ;
return V_28 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_46 ,
struct V_56 * V_57 )
{
return F_12 ( V_2 , 0 , 0 , V_4 , V_46 , V_57 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_46 ,
int V_55 ,
struct V_56 * V_57 )
{
int V_54 ;
int V_94 = F_20 ( V_2 ,
V_95 .
V_96 ) ;
if ( ! V_94 )
return - V_97 ;
V_54 = 1 ;
return F_12 ( V_2 , V_54 , V_55 , V_4 , V_46 , V_57 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_71 )
{
T_1 V_7 [ F_2 ( V_98 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_99 ) ] = { 0 } ;
F_3 ( V_99 , V_5 , V_9 , V_100 ) ;
F_3 ( V_99 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_99 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_99 , V_5 , V_70 , V_71 ) ;
if ( V_4 -> V_14 ) {
F_3 ( V_99 , V_5 , V_15 , V_4 -> V_14 ) ;
F_3 ( V_99 , V_5 , V_16 , 1 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_13 )
{
T_1 V_5 [ F_2 ( V_101 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_102 ) ] = { 0 } ;
int V_28 ;
F_3 ( V_101 , V_5 , V_9 ,
V_103 ) ;
V_28 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( ! V_28 )
* V_13 = F_6 ( V_102 , V_7 , V_91 ) ;
return V_28 ;
}
int F_23 ( struct V_1 * V_2 , T_2 V_13 )
{
T_1 V_5 [ F_2 ( V_104 ) ] = { 0 } ;
T_1 V_7 [ F_2 ( V_105 ) ] = { 0 } ;
F_3 ( V_104 , V_5 , V_9 ,
V_106 ) ;
F_3 ( V_104 , V_5 , V_91 , V_13 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_13 ,
T_3 * V_107 , T_3 * V_108 )
{
T_1 V_7 [ F_10 ( V_109 ) +
F_10 ( V_110 ) ] = { 0 } ;
T_1 V_5 [ F_2 ( V_111 ) ] = { 0 } ;
void * V_112 ;
int V_28 = 0 ;
F_3 ( V_111 , V_5 , V_9 ,
V_113 ) ;
F_3 ( V_111 , V_5 , V_18 , 0 ) ;
F_3 ( V_111 , V_5 , V_91 , V_13 ) ;
V_28 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( V_28 )
return V_28 ;
V_112 = F_15 ( V_109 , V_7 , V_114 ) ;
* V_107 = F_25 ( V_110 , V_112 , V_107 ) ;
* V_108 = F_25 ( V_110 , V_112 , V_115 ) ;
return 0 ;
}
struct V_116 *
F_26 ( struct V_1 * V_2 , T_2 V_13 , int V_117 )
{
struct V_116 * V_118 ;
int V_119 =
F_10 ( V_109 ) +
F_10 ( V_110 ) * V_117 ;
V_118 = F_27 ( sizeof( * V_118 ) + V_119 , V_120 ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_13 = V_13 ;
V_118 -> V_117 = V_117 ;
V_118 -> V_119 = V_119 ;
return V_118 ;
}
void F_28 ( struct V_116 * V_118 )
{
F_29 ( V_118 ) ;
}
int
F_30 ( struct V_1 * V_2 , struct V_116 * V_118 )
{
T_1 V_5 [ F_2 ( V_111 ) ] = { 0 } ;
F_3 ( V_111 , V_5 , V_9 ,
V_113 ) ;
F_3 ( V_111 , V_5 , V_18 , 0 ) ;
F_3 ( V_111 , V_5 , V_91 , V_118 -> V_13 ) ;
F_3 ( V_111 , V_5 , V_121 , V_118 -> V_117 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_118 -> V_7 , V_118 -> V_119 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_116 * V_118 , T_2 V_13 ,
T_3 * V_107 , T_3 * V_108 )
{
int V_71 = V_13 - V_118 -> V_13 ;
void * V_112 ;
if ( V_71 < 0 || V_71 >= V_118 -> V_117 ) {
F_14 ( V_2 , L_2 ,
V_13 , V_118 -> V_13 , V_118 -> V_13 + V_118 -> V_117 - 1 ) ;
return;
}
V_112 = F_15 ( V_109 , V_118 -> V_7 ,
V_114 [ V_71 ] ) ;
* V_107 = F_25 ( V_110 , V_112 , V_107 ) ;
* V_108 = F_25 ( V_110 , V_112 , V_115 ) ;
}
int F_32 ( struct V_1 * V_2 ,
int V_122 ,
T_4 V_123 ,
void * V_124 ,
T_1 * V_75 )
{
int V_125 = F_33 ( V_2 , V_126 ) ;
T_1 V_7 [ F_2 ( V_127 ) ] ;
void * V_128 ;
void * V_129 ;
int V_48 ;
int V_28 ;
T_1 * V_5 ;
if ( V_123 > F_33 ( V_2 , V_126 ) )
return - V_130 ;
V_5 = F_27 ( F_10 ( V_131 ) + V_125 ,
V_120 ) ;
if ( ! V_5 )
return - V_67 ;
V_128 = F_15 ( V_131 , V_5 , V_124 ) ;
V_129 = F_15 ( V_128 , V_128 , V_124 ) ;
V_48 = V_129 - ( void * ) V_5 + V_123 ;
memset ( V_5 , 0 , V_48 ) ;
F_3 ( V_131 , V_5 , V_9 ,
V_132 ) ;
F_3 ( V_128 , V_128 , V_133 , V_123 ) ;
F_3 ( V_128 , V_128 , V_122 , V_122 ) ;
memcpy ( V_129 , V_124 , V_123 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_28 = F_4 ( V_2 , V_5 , V_48 , V_7 , sizeof( V_7 ) ) ;
* V_75 = F_6 ( V_127 , V_7 , V_75 ) ;
F_29 ( V_5 ) ;
return V_28 ;
}
void F_34 ( struct V_1 * V_2 , T_1 V_75 )
{
T_1 V_5 [ F_2 ( V_134 ) ] ;
T_1 V_7 [ F_2 ( V_135 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_134 , V_5 , V_9 ,
V_136 ) ;
F_3 ( V_134 , V_5 , V_75 , V_75 ) ;
F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
