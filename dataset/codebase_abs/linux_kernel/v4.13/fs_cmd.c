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
F_4 ( V_30 , V_6 , V_33 . V_23 , V_23 ) ;
F_4 ( V_30 , V_6 , V_33 . V_24 , V_24 ) ;
if ( V_17 ) {
F_4 ( V_30 , V_6 , V_18 , V_17 ) ;
F_4 ( V_30 , V_6 , V_19 , 1 ) ;
}
F_4 ( V_30 , V_6 , V_33 . V_34 ,
V_27 ) ;
F_4 ( V_30 , V_6 , V_33 . V_35 ,
V_27 ) ;
switch ( V_21 ) {
case V_36 :
if ( V_25 ) {
F_4 ( V_30 , V_6 ,
V_33 . V_37 , 1 ) ;
F_4 ( V_30 , V_6 ,
V_33 . V_38 , V_25 -> V_16 ) ;
}
break;
case V_39 :
F_4 ( V_30 , V_6 , V_21 , 0x1 ) ;
if ( V_25 )
F_4 ( V_30 , V_6 ,
V_33 . V_40 ,
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
T_1 V_6 [ F_2 ( V_41 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_42 ) ] = { 0 } ;
F_4 ( V_41 , V_6 , V_12 ,
V_43 ) ;
F_4 ( V_41 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_41 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_41 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_41 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_25 )
{
T_1 V_6 [ F_2 ( V_44 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_45 ) ] = { 0 } ;
F_4 ( V_44 , V_6 , V_12 ,
V_46 ) ;
F_4 ( V_44 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_44 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_21 == V_39 ) {
F_4 ( V_44 , V_6 , V_47 ,
V_48 ) ;
if ( V_25 ) {
F_4 ( V_44 , V_6 ,
V_33 . V_40 , V_25 -> V_16 ) ;
} else {
F_4 ( V_44 , V_6 ,
V_33 . V_40 , 0 ) ;
}
} else {
if ( V_4 -> V_17 ) {
F_4 ( V_44 , V_6 , V_18 ,
V_4 -> V_17 ) ;
F_4 ( V_44 , V_6 , V_19 , 1 ) ;
}
F_4 ( V_44 , V_6 , V_47 ,
V_49 ) ;
if ( V_25 ) {
F_4 ( V_44 , V_6 ,
V_33 . V_37 , 1 ) ;
F_4 ( V_44 , V_6 ,
V_33 . V_38 ,
V_25 -> V_16 ) ;
} else {
F_4 ( V_44 , V_6 ,
V_33 . V_37 , 0 ) ;
}
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_6 ,
unsigned int * V_50 )
{
T_1 V_8 [ F_2 ( V_51 ) ] = { 0 } ;
int V_52 = F_11 ( V_53 ) ;
int V_31 ;
F_4 ( V_53 , V_6 , V_12 ,
V_54 ) ;
F_4 ( V_53 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_53 , V_6 , V_15 , V_4 -> V_16 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_53 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_53 , V_6 , V_19 , 1 ) ;
}
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_50 = F_7 ( V_51 , V_8 ,
V_50 ) ;
return V_31 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_50 )
{
T_1 V_8 [ F_2 ( V_55 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_56 ) ] = { 0 } ;
F_4 ( V_56 , V_6 , V_12 ,
V_57 ) ;
F_4 ( V_56 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_56 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_56 , V_6 , V_50 , V_50 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_56 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_56 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_58 , int V_59 ,
struct V_3 * V_4 ,
unsigned V_50 ,
struct V_60 * V_61 )
{
unsigned int V_52 = F_11 ( V_62 ) +
V_61 -> V_63 * F_11 ( V_64 ) ;
T_1 V_8 [ F_2 ( V_65 ) ] = { 0 } ;
struct V_66 * V_67 ;
void * V_68 ;
void * V_69 ;
void * V_70 ;
T_1 * V_6 ;
int V_31 ;
V_6 = F_14 ( V_52 , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
F_4 ( V_62 , V_6 , V_12 , V_73 ) ;
F_4 ( V_62 , V_6 , V_21 , V_58 ) ;
F_4 ( V_62 , V_6 , V_74 , V_59 ) ;
F_4 ( V_62 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_62 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_62 , V_6 , V_75 , V_61 -> V_76 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_62 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_62 , V_6 , V_19 , 1 ) ;
}
V_68 = F_15 ( V_62 , V_6 , V_77 ) ;
F_4 ( V_77 , V_68 , V_50 , V_50 ) ;
F_4 ( V_77 , V_68 , V_78 , V_61 -> V_78 ) ;
F_4 ( V_77 , V_68 , V_79 , V_61 -> V_79 ) ;
F_4 ( V_77 , V_68 , V_80 , V_61 -> V_80 ) ;
F_4 ( V_77 , V_68 , V_81 , V_61 -> V_82 ) ;
V_69 = F_15 ( V_77 , V_68 ,
V_83 ) ;
memcpy ( V_69 , & V_61 -> V_84 , F_11 ( V_85 ) ) ;
V_70 = F_15 ( V_77 , V_68 , V_86 ) ;
if ( V_61 -> V_79 & V_87 ) {
int V_88 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_16 ;
if ( V_67 -> V_89 . type == V_90 )
continue;
F_4 ( V_64 , V_70 , V_91 ,
V_67 -> V_89 . type ) ;
if ( V_67 -> V_89 . type ==
V_92 ) {
V_16 = V_67 -> V_89 . V_4 -> V_16 ;
} else {
V_16 = V_67 -> V_89 . V_93 ;
}
F_4 ( V_64 , V_70 , V_94 , V_16 ) ;
V_70 += F_11 ( V_64 ) ;
V_88 ++ ;
}
F_4 ( V_77 , V_68 , V_95 ,
V_88 ) ;
}
if ( V_61 -> V_79 & V_96 ) {
int V_88 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
if ( V_67 -> V_89 . type !=
V_90 )
continue;
F_4 ( V_97 , V_70 , V_98 ,
V_67 -> V_89 . V_99 -> V_16 ) ;
V_70 += F_11 ( V_64 ) ;
V_88 ++ ;
}
F_4 ( V_77 , V_68 , V_100 ,
V_88 ) ;
}
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
F_17 ( V_6 ) ;
return V_31 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_50 ,
struct V_60 * V_61 )
{
return F_13 ( V_2 , 0 , 0 , V_4 , V_50 , V_61 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_50 ,
int V_59 ,
struct V_60 * V_61 )
{
int V_58 ;
int V_101 = F_20 ( V_2 ,
V_102 .
V_103 ) ;
if ( ! V_101 )
return - V_104 ;
V_58 = 1 ;
return F_13 ( V_2 , V_58 , V_59 , V_4 , V_50 , V_61 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_76 )
{
T_1 V_8 [ F_2 ( V_105 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_106 ) ] = { 0 } ;
F_4 ( V_106 , V_6 , V_12 , V_107 ) ;
F_4 ( V_106 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_106 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_106 , V_6 , V_75 , V_76 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_106 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_106 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_16 )
{
T_1 V_6 [ F_2 ( V_108 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_109 ) ] = { 0 } ;
int V_31 ;
F_4 ( V_108 , V_6 , V_12 ,
V_110 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_16 = F_7 ( V_109 , V_8 , V_98 ) ;
return V_31 ;
}
int F_23 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_6 [ F_2 ( V_111 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_112 ) ] = { 0 } ;
F_4 ( V_111 , V_6 , V_12 ,
V_113 ) ;
F_4 ( V_111 , V_6 , V_98 , V_16 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_16 ,
T_3 * V_114 , T_3 * V_115 )
{
T_1 V_8 [ F_11 ( V_116 ) +
F_11 ( V_117 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_118 ) ] = { 0 } ;
void * V_119 ;
int V_31 = 0 ;
F_4 ( V_118 , V_6 , V_12 ,
V_120 ) ;
F_4 ( V_118 , V_6 , V_21 , 0 ) ;
F_4 ( V_118 , V_6 , V_98 , V_16 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( V_31 )
return V_31 ;
V_119 = F_15 ( V_116 , V_8 , V_121 ) ;
* V_114 = F_25 ( V_117 , V_119 , V_114 ) ;
* V_115 = F_25 ( V_117 , V_119 , V_122 ) ;
return 0 ;
}
struct V_123 *
F_26 ( struct V_1 * V_2 , T_2 V_16 , int V_124 )
{
struct V_123 * V_125 ;
int V_126 =
F_11 ( V_116 ) +
F_11 ( V_117 ) * V_124 ;
V_125 = F_27 ( sizeof( * V_125 ) + V_126 , V_71 ) ;
if ( ! V_125 )
return NULL ;
V_125 -> V_16 = V_16 ;
V_125 -> V_124 = V_124 ;
V_125 -> V_126 = V_126 ;
return V_125 ;
}
void F_28 ( struct V_123 * V_125 )
{
F_29 ( V_125 ) ;
}
int
F_30 ( struct V_1 * V_2 , struct V_123 * V_125 )
{
T_1 V_6 [ F_2 ( V_118 ) ] = { 0 } ;
F_4 ( V_118 , V_6 , V_12 ,
V_120 ) ;
F_4 ( V_118 , V_6 , V_21 , 0 ) ;
F_4 ( V_118 , V_6 , V_98 , V_125 -> V_16 ) ;
F_4 ( V_118 , V_6 , V_127 , V_125 -> V_124 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_125 -> V_8 , V_125 -> V_126 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_123 * V_125 , T_2 V_16 ,
T_3 * V_114 , T_3 * V_115 )
{
int V_76 = V_16 - V_125 -> V_16 ;
void * V_119 ;
if ( V_76 < 0 || V_76 >= V_125 -> V_124 ) {
F_32 ( V_2 , L_1 ,
V_16 , V_125 -> V_16 , V_125 -> V_16 + V_125 -> V_124 - 1 ) ;
return;
}
V_119 = F_15 ( V_116 , V_125 -> V_8 ,
V_121 [ V_76 ] ) ;
* V_114 = F_25 ( V_117 , V_119 , V_114 ) ;
* V_115 = F_25 ( V_117 , V_119 , V_122 ) ;
}
int F_33 ( struct V_1 * V_2 ,
int V_128 ,
T_4 V_129 ,
void * V_130 ,
T_1 * V_80 )
{
int V_131 = F_34 ( V_2 , V_132 ) ;
T_1 V_8 [ F_2 ( V_133 ) ] ;
void * V_134 ;
void * V_135 ;
int V_52 ;
int V_31 ;
T_1 * V_6 ;
if ( V_129 > V_131 ) {
F_32 ( V_2 , L_2 ,
V_129 , V_131 ) ;
return - V_136 ;
}
V_6 = F_27 ( F_11 ( V_137 ) + V_129 ,
V_71 ) ;
if ( ! V_6 )
return - V_72 ;
V_134 = F_15 ( V_137 , V_6 , V_130 ) ;
V_135 = F_15 ( V_134 , V_134 , V_130 ) ;
V_52 = V_135 - ( void * ) V_6 + V_129 ;
memset ( V_6 , 0 , V_52 ) ;
F_4 ( V_137 , V_6 , V_12 ,
V_138 ) ;
F_4 ( V_134 , V_134 , V_139 , V_129 ) ;
F_4 ( V_134 , V_134 , V_128 , V_128 ) ;
memcpy ( V_135 , V_130 , V_129 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
* V_80 = F_7 ( V_133 , V_8 , V_80 ) ;
F_29 ( V_6 ) ;
return V_31 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_80 )
{
T_1 V_6 [ F_2 ( V_140 ) ] ;
T_1 V_8 [ F_2 ( V_141 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_140 , V_6 , V_12 ,
V_142 ) ;
F_4 ( V_140 , V_6 , V_80 , V_80 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_36 ( struct V_1 * V_2 ,
T_5 V_143 , T_5 V_144 ,
void * V_145 , T_1 * V_81 )
{
T_1 V_8 [ F_2 ( V_146 ) ] ;
int V_147 , V_148 , V_52 , V_31 ;
void * V_149 ;
T_5 V_14 ;
T_1 * V_6 ;
switch ( V_143 ) {
case V_150 :
V_147 = F_37 ( V_2 , V_151 ) ;
V_14 = V_152 ;
break;
case V_153 :
V_147 = F_38 ( V_2 , V_151 ) ;
V_14 = V_154 ;
break;
default:
return - V_104 ;
}
if ( V_144 > V_147 ) {
F_32 ( V_2 , L_3 ,
V_144 , V_147 ) ;
return - V_104 ;
}
V_148 = F_39 ( V_155 ) * V_144 ;
V_52 = F_11 ( V_156 ) + V_148 ;
V_6 = F_27 ( V_52 , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
F_4 ( V_156 , V_6 , V_12 ,
V_157 ) ;
F_4 ( V_156 , V_6 , V_14 , V_14 ) ;
F_4 ( V_156 , V_6 , V_158 , V_144 ) ;
V_149 = F_15 ( V_156 , V_6 , V_159 ) ;
memcpy ( V_149 , V_145 , V_148 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
* V_81 = F_7 ( V_146 , V_8 , V_81 ) ;
F_29 ( V_6 ) ;
return V_31 ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_81 )
{
T_1 V_6 [ F_2 ( V_160 ) ] ;
T_1 V_8 [ F_2 ( V_161 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_160 , V_6 , V_12 ,
V_162 ) ;
F_4 ( V_160 , V_6 , V_81 ,
V_81 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
