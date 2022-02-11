int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 [ F_2 ( V_7 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_9 ) ] = { 0 } ;
if ( ( F_3 ( V_2 , V_10 ) == V_11 ) &&
V_5 == 0 )
return 0 ;
F_4 ( V_7 , V_6 , V_12 ,
V_13 ) ;
F_4 ( V_7 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_7 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_7 , V_6 , V_5 , V_5 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_7 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_7 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_6 ( struct V_1 * V_2 ,
T_2 V_17 ,
enum V_20 V_21 ,
enum V_22 type , unsigned int V_23 ,
unsigned int V_24 , struct V_3
* V_25 , unsigned int * V_15 , T_1 V_26 )
{
int V_27 = ! ! ( V_26 & V_28 ) ;
T_1 V_8 [ F_2 ( V_29 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_30 ) ] = { 0 } ;
int V_31 ;
F_4 ( V_30 , V_6 , V_12 ,
V_32 ) ;
F_4 ( V_30 , V_6 , V_14 , type ) ;
F_4 ( V_30 , V_6 , V_23 , V_23 ) ;
F_4 ( V_30 , V_6 , V_24 , V_24 ) ;
if ( V_17 ) {
F_4 ( V_30 , V_6 , V_18 , V_17 ) ;
F_4 ( V_30 , V_6 , V_19 , 1 ) ;
}
F_4 ( V_30 , V_6 , V_33 , V_27 ) ;
F_4 ( V_30 , V_6 , V_34 , V_27 ) ;
switch ( V_21 ) {
case V_35 :
if ( V_25 ) {
F_4 ( V_30 , V_6 , V_36 , 1 ) ;
F_4 ( V_30 , V_6 , V_37 , V_25 -> V_16 ) ;
}
break;
case V_38 :
F_4 ( V_30 , V_6 , V_21 , 0x1 ) ;
if ( V_25 )
F_4 ( V_30 , V_6 , V_39 ,
V_25 -> V_16 ) ;
break;
}
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_15 = F_7 ( V_29 , V_8 ,
V_15 ) ;
return V_31 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_6 [ F_2 ( V_40 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_41 ) ] = { 0 } ;
F_4 ( V_40 , V_6 , V_12 ,
V_42 ) ;
F_4 ( V_40 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_40 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_40 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_40 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_25 )
{
T_1 V_6 [ F_2 ( V_43 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_44 ) ] = { 0 } ;
F_4 ( V_43 , V_6 , V_12 ,
V_45 ) ;
F_4 ( V_43 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_43 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_21 == V_38 ) {
F_4 ( V_43 , V_6 , V_46 ,
V_47 ) ;
if ( V_25 ) {
F_4 ( V_43 , V_6 ,
V_39 , V_25 -> V_16 ) ;
} else {
F_4 ( V_43 , V_6 ,
V_39 , 0 ) ;
}
} else {
if ( V_4 -> V_17 ) {
F_4 ( V_43 , V_6 , V_18 ,
V_4 -> V_17 ) ;
F_4 ( V_43 , V_6 , V_19 , 1 ) ;
}
F_4 ( V_43 , V_6 , V_46 ,
V_48 ) ;
if ( V_25 ) {
F_4 ( V_43 , V_6 , V_36 , 1 ) ;
F_4 ( V_43 , V_6 , V_37 ,
V_25 -> V_16 ) ;
} else {
F_4 ( V_43 , V_6 , V_36 , 0 ) ;
}
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_6 ,
unsigned int * V_49 )
{
T_1 V_8 [ F_2 ( V_50 ) ] = { 0 } ;
int V_51 = F_11 ( V_52 ) ;
int V_31 ;
F_4 ( V_52 , V_6 , V_12 ,
V_53 ) ;
F_4 ( V_52 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_52 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_52 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_52 , V_6 , V_19 , 1 ) ;
}
V_31 = F_5 ( V_2 , V_6 , V_51 , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_49 = F_7 ( V_50 , V_8 ,
V_49 ) ;
return V_31 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_49 )
{
T_1 V_8 [ F_2 ( V_54 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_55 ) ] = { 0 } ;
F_4 ( V_55 , V_6 , V_12 ,
V_56 ) ;
F_4 ( V_55 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_55 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_55 , V_6 , V_49 , V_49 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_55 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_55 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_57 , int V_58 ,
struct V_3 * V_4 ,
unsigned V_49 ,
struct V_59 * V_60 )
{
unsigned int V_51 = F_11 ( V_61 ) +
V_60 -> V_62 * F_11 ( V_63 ) ;
T_1 V_8 [ F_2 ( V_64 ) ] = { 0 } ;
struct V_65 * V_66 ;
void * V_67 ;
void * V_68 ;
void * V_69 ;
T_1 * V_6 ;
int V_31 ;
V_6 = F_14 ( V_51 ) ;
if ( ! V_6 ) {
F_15 ( V_2 , L_1 ) ;
return - V_70 ;
}
F_4 ( V_61 , V_6 , V_12 , V_71 ) ;
F_4 ( V_61 , V_6 , V_21 , V_57 ) ;
F_4 ( V_61 , V_6 , V_72 , V_58 ) ;
F_4 ( V_61 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_61 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_61 , V_6 , V_73 , V_60 -> V_74 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_61 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_61 , V_6 , V_19 , 1 ) ;
}
V_67 = F_16 ( V_61 , V_6 , V_75 ) ;
F_4 ( V_75 , V_67 , V_49 , V_49 ) ;
F_4 ( V_75 , V_67 , V_76 , V_60 -> V_76 ) ;
F_4 ( V_75 , V_67 , V_77 , V_60 -> V_77 ) ;
F_4 ( V_75 , V_67 , V_78 , V_60 -> V_78 ) ;
F_4 ( V_75 , V_67 , V_79 , V_60 -> V_80 ) ;
V_68 = F_16 ( V_75 , V_67 ,
V_81 ) ;
memcpy ( V_68 , & V_60 -> V_82 , F_11 ( V_83 ) ) ;
V_69 = F_16 ( V_75 , V_67 , V_84 ) ;
if ( V_60 -> V_77 & V_85 ) {
int V_86 = 0 ;
F_17 (dst, &fte->node.children, node.list) {
unsigned int V_16 ;
if ( V_66 -> V_87 . type == V_88 )
continue;
F_4 ( V_63 , V_69 , V_89 ,
V_66 -> V_87 . type ) ;
if ( V_66 -> V_87 . type ==
V_90 ) {
V_16 = V_66 -> V_87 . V_4 -> V_16 ;
} else {
V_16 = V_66 -> V_87 . V_91 ;
}
F_4 ( V_63 , V_69 , V_92 , V_16 ) ;
V_69 += F_11 ( V_63 ) ;
V_86 ++ ;
}
F_4 ( V_75 , V_67 , V_93 ,
V_86 ) ;
}
if ( V_60 -> V_77 & V_94 ) {
int V_86 = 0 ;
F_17 (dst, &fte->node.children, node.list) {
if ( V_66 -> V_87 . type !=
V_88 )
continue;
F_4 ( V_95 , V_69 , V_96 ,
V_66 -> V_87 . V_97 -> V_16 ) ;
V_69 += F_11 ( V_63 ) ;
V_86 ++ ;
}
F_4 ( V_75 , V_67 , V_98 ,
V_86 ) ;
}
V_31 = F_5 ( V_2 , V_6 , V_51 , V_8 , sizeof( V_8 ) ) ;
F_18 ( V_6 ) ;
return V_31 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_49 ,
struct V_59 * V_60 )
{
return F_13 ( V_2 , 0 , 0 , V_4 , V_49 , V_60 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_49 ,
int V_58 ,
struct V_59 * V_60 )
{
int V_57 ;
int V_99 = F_21 ( V_2 ,
V_100 .
V_101 ) ;
if ( ! V_99 )
return - V_102 ;
V_57 = 1 ;
return F_13 ( V_2 , V_57 , V_58 , V_4 , V_49 , V_60 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_74 )
{
T_1 V_8 [ F_2 ( V_103 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_104 ) ] = { 0 } ;
F_4 ( V_104 , V_6 , V_12 , V_105 ) ;
F_4 ( V_104 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_104 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_104 , V_6 , V_73 , V_74 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_104 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_104 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_23 ( struct V_1 * V_2 , T_2 * V_16 )
{
T_1 V_6 [ F_2 ( V_106 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_107 ) ] = { 0 } ;
int V_31 ;
F_4 ( V_106 , V_6 , V_12 ,
V_108 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_16 = F_7 ( V_107 , V_8 , V_96 ) ;
return V_31 ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_6 [ F_2 ( V_109 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_110 ) ] = { 0 } ;
F_4 ( V_109 , V_6 , V_12 ,
V_111 ) ;
F_4 ( V_109 , V_6 , V_96 , V_16 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_25 ( struct V_1 * V_2 , T_2 V_16 ,
T_3 * V_112 , T_3 * V_113 )
{
T_1 V_8 [ F_11 ( V_114 ) +
F_11 ( V_115 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_116 ) ] = { 0 } ;
void * V_117 ;
int V_31 = 0 ;
F_4 ( V_116 , V_6 , V_12 ,
V_118 ) ;
F_4 ( V_116 , V_6 , V_21 , 0 ) ;
F_4 ( V_116 , V_6 , V_96 , V_16 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( V_31 )
return V_31 ;
V_117 = F_16 ( V_114 , V_8 , V_119 ) ;
* V_112 = F_26 ( V_115 , V_117 , V_112 ) ;
* V_113 = F_26 ( V_115 , V_117 , V_120 ) ;
return 0 ;
}
struct V_121 *
F_27 ( struct V_1 * V_2 , T_2 V_16 , int V_122 )
{
struct V_121 * V_123 ;
int V_124 =
F_11 ( V_114 ) +
F_11 ( V_115 ) * V_122 ;
V_123 = F_28 ( sizeof( * V_123 ) + V_124 , V_125 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_16 = V_16 ;
V_123 -> V_122 = V_122 ;
V_123 -> V_124 = V_124 ;
return V_123 ;
}
void F_29 ( struct V_121 * V_123 )
{
F_30 ( V_123 ) ;
}
int
F_31 ( struct V_1 * V_2 , struct V_121 * V_123 )
{
T_1 V_6 [ F_2 ( V_116 ) ] = { 0 } ;
F_4 ( V_116 , V_6 , V_12 ,
V_118 ) ;
F_4 ( V_116 , V_6 , V_21 , 0 ) ;
F_4 ( V_116 , V_6 , V_96 , V_123 -> V_16 ) ;
F_4 ( V_116 , V_6 , V_126 , V_123 -> V_122 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_123 -> V_8 , V_123 -> V_124 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_121 * V_123 , T_2 V_16 ,
T_3 * V_112 , T_3 * V_113 )
{
int V_74 = V_16 - V_123 -> V_16 ;
void * V_117 ;
if ( V_74 < 0 || V_74 >= V_123 -> V_122 ) {
F_15 ( V_2 , L_2 ,
V_16 , V_123 -> V_16 , V_123 -> V_16 + V_123 -> V_122 - 1 ) ;
return;
}
V_117 = F_16 ( V_114 , V_123 -> V_8 ,
V_119 [ V_74 ] ) ;
* V_112 = F_26 ( V_115 , V_117 , V_112 ) ;
* V_113 = F_26 ( V_115 , V_117 , V_120 ) ;
}
int F_33 ( struct V_1 * V_2 ,
int V_127 ,
T_4 V_128 ,
void * V_129 ,
T_1 * V_78 )
{
int V_130 = F_34 ( V_2 , V_131 ) ;
T_1 V_8 [ F_2 ( V_132 ) ] ;
void * V_133 ;
void * V_134 ;
int V_51 ;
int V_31 ;
T_1 * V_6 ;
if ( V_128 > V_130 ) {
F_15 ( V_2 , L_3 ,
V_128 , V_130 ) ;
return - V_135 ;
}
V_6 = F_28 ( F_11 ( V_136 ) + V_128 ,
V_125 ) ;
if ( ! V_6 )
return - V_70 ;
V_133 = F_16 ( V_136 , V_6 , V_129 ) ;
V_134 = F_16 ( V_133 , V_133 , V_129 ) ;
V_51 = V_134 - ( void * ) V_6 + V_128 ;
memset ( V_6 , 0 , V_51 ) ;
F_4 ( V_136 , V_6 , V_12 ,
V_137 ) ;
F_4 ( V_133 , V_133 , V_138 , V_128 ) ;
F_4 ( V_133 , V_133 , V_127 , V_127 ) ;
memcpy ( V_134 , V_129 , V_128 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_51 , V_8 , sizeof( V_8 ) ) ;
* V_78 = F_7 ( V_132 , V_8 , V_78 ) ;
F_30 ( V_6 ) ;
return V_31 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_78 )
{
T_1 V_6 [ F_2 ( V_139 ) ] ;
T_1 V_8 [ F_2 ( V_140 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_139 , V_6 , V_12 ,
V_141 ) ;
F_4 ( V_139 , V_6 , V_78 , V_78 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_36 ( struct V_1 * V_2 ,
T_5 V_142 , T_5 V_143 ,
void * V_144 , T_1 * V_79 )
{
T_1 V_8 [ F_2 ( V_145 ) ] ;
int V_146 , V_147 , V_51 , V_31 ;
void * V_148 ;
T_5 V_14 ;
T_1 * V_6 ;
switch ( V_142 ) {
case V_149 :
V_146 = F_37 ( V_2 , V_150 ) ;
V_14 = V_151 ;
break;
case V_152 :
V_146 = F_38 ( V_2 , V_150 ) ;
V_14 = V_153 ;
break;
default:
return - V_102 ;
}
if ( V_143 > V_146 ) {
F_15 ( V_2 , L_4 ,
V_143 , V_146 ) ;
return - V_102 ;
}
V_147 = F_39 ( V_154 ) * V_143 ;
V_51 = F_11 ( V_155 ) + V_147 ;
V_6 = F_28 ( V_51 , V_125 ) ;
if ( ! V_6 )
return - V_70 ;
F_4 ( V_155 , V_6 , V_12 ,
V_156 ) ;
F_4 ( V_155 , V_6 , V_14 , V_14 ) ;
F_4 ( V_155 , V_6 , V_157 , V_143 ) ;
V_148 = F_16 ( V_155 , V_6 , V_158 ) ;
memcpy ( V_148 , V_144 , V_147 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_51 , V_8 , sizeof( V_8 ) ) ;
* V_79 = F_7 ( V_145 , V_8 , V_79 ) ;
F_30 ( V_6 ) ;
return V_31 ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_79 )
{
T_1 V_6 [ F_2 ( V_159 ) ] ;
T_1 V_8 [ F_2 ( V_160 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_159 , V_6 , V_12 ,
V_161 ) ;
F_4 ( V_159 , V_6 , V_79 ,
V_79 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
