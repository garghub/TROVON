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
memcpy ( V_69 , & V_61 -> V_84 , sizeof( V_61 -> V_84 ) ) ;
V_70 = F_15 ( V_77 , V_68 , V_85 ) ;
if ( V_61 -> V_79 & V_86 ) {
int V_87 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_16 ;
if ( V_67 -> V_88 . type == V_89 )
continue;
F_4 ( V_64 , V_70 , V_90 ,
V_67 -> V_88 . type ) ;
if ( V_67 -> V_88 . type ==
V_91 ) {
V_16 = V_67 -> V_88 . V_4 -> V_16 ;
} else {
V_16 = V_67 -> V_88 . V_92 ;
}
F_4 ( V_64 , V_70 , V_93 , V_16 ) ;
V_70 += F_11 ( V_64 ) ;
V_87 ++ ;
}
F_4 ( V_77 , V_68 , V_94 ,
V_87 ) ;
}
if ( V_61 -> V_79 & V_95 ) {
int V_96 = F_17 ( F_18 ( V_2 ,
V_97 ,
V_4 -> type ) ) ;
int V_87 = 0 ;
F_16 (dst, &fte->node.children, node.list) {
if ( V_67 -> V_88 . type !=
V_89 )
continue;
F_4 ( V_98 , V_70 , V_99 ,
V_67 -> V_88 . V_100 -> V_16 ) ;
V_70 += F_11 ( V_64 ) ;
V_87 ++ ;
}
if ( V_87 > V_96 ) {
V_31 = - V_101 ;
goto V_102;
}
F_4 ( V_77 , V_68 , V_103 ,
V_87 ) ;
}
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
V_102:
F_19 ( V_6 ) ;
return V_31 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_50 ,
struct V_60 * V_61 )
{
return F_13 ( V_2 , 0 , 0 , V_4 , V_50 , V_61 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_50 ,
int V_59 ,
struct V_60 * V_61 )
{
int V_58 ;
int V_104 = F_22 ( V_2 ,
V_105 .
V_106 ) ;
if ( ! V_104 )
return - V_107 ;
V_58 = 1 ;
return F_13 ( V_2 , V_58 , V_59 , V_4 , V_50 , V_61 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_76 )
{
T_1 V_8 [ F_2 ( V_108 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_109 ) ] = { 0 } ;
F_4 ( V_109 , V_6 , V_12 , V_110 ) ;
F_4 ( V_109 , V_6 , V_14 , V_4 -> type ) ;
F_4 ( V_109 , V_6 , V_15 , V_4 -> V_16 ) ;
F_4 ( V_109 , V_6 , V_75 , V_76 ) ;
if ( V_4 -> V_17 ) {
F_4 ( V_109 , V_6 , V_18 , V_4 -> V_17 ) ;
F_4 ( V_109 , V_6 , V_19 , 1 ) ;
}
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 * V_16 )
{
T_1 V_6 [ F_2 ( V_111 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_112 ) ] = { 0 } ;
int V_31 ;
F_4 ( V_111 , V_6 , V_12 ,
V_113 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( ! V_31 )
* V_16 = F_7 ( V_112 , V_8 , V_99 ) ;
return V_31 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_6 [ F_2 ( V_114 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_115 ) ] = { 0 } ;
F_4 ( V_114 , V_6 , V_12 ,
V_116 ) ;
F_4 ( V_114 , V_6 , V_99 , V_16 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_16 ,
T_3 * V_117 , T_3 * V_118 )
{
T_1 V_8 [ F_11 ( V_119 ) +
F_11 ( V_120 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_121 ) ] = { 0 } ;
void * V_122 ;
int V_31 = 0 ;
F_4 ( V_121 , V_6 , V_12 ,
V_123 ) ;
F_4 ( V_121 , V_6 , V_21 , 0 ) ;
F_4 ( V_121 , V_6 , V_99 , V_16 ) ;
V_31 = F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( V_31 )
return V_31 ;
V_122 = F_15 ( V_119 , V_8 , V_124 ) ;
* V_117 = F_27 ( V_120 , V_122 , V_117 ) ;
* V_118 = F_27 ( V_120 , V_122 , V_125 ) ;
return 0 ;
}
struct V_126 *
F_28 ( struct V_1 * V_2 , T_1 V_16 , int V_127 )
{
struct V_126 * V_128 ;
int V_129 =
F_11 ( V_119 ) +
F_11 ( V_120 ) * V_127 ;
V_128 = F_29 ( sizeof( * V_128 ) + V_129 , V_71 ) ;
if ( ! V_128 )
return NULL ;
V_128 -> V_16 = V_16 ;
V_128 -> V_127 = V_127 ;
V_128 -> V_129 = V_129 ;
return V_128 ;
}
void F_30 ( struct V_126 * V_128 )
{
F_31 ( V_128 ) ;
}
int
F_32 ( struct V_1 * V_2 , struct V_126 * V_128 )
{
T_1 V_6 [ F_2 ( V_121 ) ] = { 0 } ;
F_4 ( V_121 , V_6 , V_12 ,
V_123 ) ;
F_4 ( V_121 , V_6 , V_21 , 0 ) ;
F_4 ( V_121 , V_6 , V_99 , V_128 -> V_16 ) ;
F_4 ( V_121 , V_6 , V_130 , V_128 -> V_127 ) ;
return F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_128 -> V_8 , V_128 -> V_129 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_126 * V_128 , T_1 V_16 ,
T_3 * V_117 , T_3 * V_118 )
{
int V_76 = V_16 - V_128 -> V_16 ;
void * V_122 ;
if ( V_76 < 0 || V_76 >= V_128 -> V_127 ) {
F_34 ( V_2 , L_1 ,
V_16 , V_128 -> V_16 , V_128 -> V_16 + V_128 -> V_127 - 1 ) ;
return;
}
V_122 = F_15 ( V_119 , V_128 -> V_8 ,
V_124 [ V_76 ] ) ;
* V_117 = F_27 ( V_120 , V_122 , V_117 ) ;
* V_118 = F_27 ( V_120 , V_122 , V_125 ) ;
}
int F_35 ( struct V_1 * V_2 ,
int V_131 ,
T_4 V_132 ,
void * V_133 ,
T_1 * V_80 )
{
int V_134 = F_36 ( V_2 , V_135 ) ;
T_1 V_8 [ F_2 ( V_136 ) ] ;
void * V_137 ;
void * V_138 ;
int V_52 ;
int V_31 ;
T_1 * V_6 ;
if ( V_132 > V_134 ) {
F_34 ( V_2 , L_2 ,
V_132 , V_134 ) ;
return - V_101 ;
}
V_6 = F_29 ( F_11 ( V_139 ) + V_132 ,
V_71 ) ;
if ( ! V_6 )
return - V_72 ;
V_137 = F_15 ( V_139 , V_6 , V_133 ) ;
V_138 = F_15 ( V_137 , V_137 , V_133 ) ;
V_52 = V_138 - ( void * ) V_6 + V_132 ;
memset ( V_6 , 0 , V_52 ) ;
F_4 ( V_139 , V_6 , V_12 ,
V_140 ) ;
F_4 ( V_137 , V_137 , V_141 , V_132 ) ;
F_4 ( V_137 , V_137 , V_131 , V_131 ) ;
memcpy ( V_138 , V_133 , V_132 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
* V_80 = F_7 ( V_136 , V_8 , V_80 ) ;
F_31 ( V_6 ) ;
return V_31 ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_80 )
{
T_1 V_6 [ F_2 ( V_142 ) ] ;
T_1 V_8 [ F_2 ( V_143 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_142 , V_6 , V_12 ,
V_144 ) ;
F_4 ( V_142 , V_6 , V_80 , V_80 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_38 ( struct V_1 * V_2 ,
T_5 V_145 , T_5 V_146 ,
void * V_147 , T_1 * V_81 )
{
T_1 V_8 [ F_2 ( V_148 ) ] ;
int V_149 , V_150 , V_52 , V_31 ;
void * V_151 ;
T_5 V_14 ;
T_1 * V_6 ;
switch ( V_145 ) {
case V_152 :
V_149 = F_39 ( V_2 , V_153 ) ;
V_14 = V_154 ;
break;
case V_155 :
V_149 = F_40 ( V_2 , V_153 ) ;
V_14 = V_156 ;
break;
default:
return - V_107 ;
}
if ( V_146 > V_149 ) {
F_34 ( V_2 , L_3 ,
V_146 , V_149 ) ;
return - V_107 ;
}
V_150 = F_41 ( V_157 ) * V_146 ;
V_52 = F_11 ( V_158 ) + V_150 ;
V_6 = F_29 ( V_52 , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
F_4 ( V_158 , V_6 , V_12 ,
V_159 ) ;
F_4 ( V_158 , V_6 , V_14 , V_14 ) ;
F_4 ( V_158 , V_6 , V_160 , V_146 ) ;
V_151 = F_15 ( V_158 , V_6 , V_161 ) ;
memcpy ( V_151 , V_147 , V_150 ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_31 = F_5 ( V_2 , V_6 , V_52 , V_8 , sizeof( V_8 ) ) ;
* V_81 = F_7 ( V_148 , V_8 , V_81 ) ;
F_31 ( V_6 ) ;
return V_31 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_81 )
{
T_1 V_6 [ F_2 ( V_162 ) ] ;
T_1 V_8 [ F_2 ( V_163 ) ] ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
F_4 ( V_162 , V_6 , V_12 ,
V_164 ) ;
F_4 ( V_162 , V_6 , V_81 ,
V_81 ) ;
F_5 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
