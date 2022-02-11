bool F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return false ;
return true ;
}
void F_2 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_8 ) ;
T_1 V_9 = F_4 ( V_2 , V_6 , V_7 ) ;
V_2 -> V_3 -> V_10 = F_5 ( V_9 ,
F_6 ( V_2 ) ) ;
F_7 ( V_2 , V_11 ,
L_1 ,
V_2 -> V_3 -> V_10 , F_6 ( V_2 ) ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_12 = F_9 ( V_2 -> V_3 -> V_13 ) ;
T_1 V_14 , V_15 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
V_14 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_16 +
( V_15 << 2 ) + sizeof( T_1 ) ) ;
( ( T_1 * ) V_2 -> V_3 -> V_17 ) [ V_15 ] =
F_10 ( ( V_18 V_19 ) V_14 ) ;
}
}
static struct V_20 *
F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_2 V_23 )
{
struct V_20 * V_24 = NULL ;
V_24 = F_12 ( sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
goto V_26;
V_24 -> V_22 = V_22 ;
V_24 -> V_23 = V_23 ;
F_13 ( & V_24 -> V_27 , & V_2 -> V_3 -> V_28 ) ;
V_26:
return V_24 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_20 * V_24 )
{
F_15 ( & V_24 -> V_27 ) ;
F_16 ( V_24 ) ;
}
static struct V_20 * F_17 ( struct V_1 * V_2 ,
T_2 V_29 )
{
struct V_20 * V_24 = NULL ;
F_18 (p_cmd_elem, &p_hwfn->mcp_info->cmd_list, list) {
if ( V_24 -> V_23 == V_29 )
return V_24 ;
}
return NULL ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
struct V_20 * V_24 , * V_30 ;
F_16 ( V_2 -> V_3 -> V_17 ) ;
F_16 ( V_2 -> V_3 -> V_31 ) ;
F_20 ( & V_2 -> V_3 -> V_32 ) ;
F_21 (p_cmd_elem,
p_tmp,
&p_hwfn->mcp_info->cmd_list, list) {
F_14 ( V_2 , V_24 ) ;
}
F_22 ( & V_2 -> V_3 -> V_32 ) ;
}
F_16 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_33 * V_34 = V_2 -> V_3 ;
T_1 V_35 , V_9 ;
T_1 V_36 = F_24 ( V_2 ) ;
V_34 -> V_4 = F_4 ( V_2 , V_6 , V_37 ) ;
if ( ! V_34 -> V_4 )
return 0 ;
V_34 -> V_4 |= V_38 ;
V_35 = F_4 ( V_2 , V_6 ,
F_3 ( V_34 -> V_4 ,
V_39 ) ) ;
V_34 -> V_40 = F_5 ( V_35 , V_36 ) ;
F_7 ( V_2 , V_11 ,
L_2 ,
V_35 , V_34 -> V_40 , V_36 ) ;
V_9 = F_4 ( V_2 , V_6 ,
F_3 ( V_34 -> V_4 ,
V_41 ) ) ;
V_34 -> V_16 = F_5 ( V_9 , V_36 ) ;
V_34 -> V_13 = ( T_2 ) F_4 ( V_2 , V_6 , V_34 -> V_16 ) ;
V_34 -> V_42 = F_25 ( V_2 , V_6 , V_43 ) &
V_44 ;
V_34 -> V_45 = F_25 ( V_2 , V_6 , V_46 ) &
V_47 ;
V_34 -> V_48 = F_4 ( V_2 , V_6 , V_49 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_33 * V_34 ;
T_1 V_50 ;
V_2 -> V_3 = F_12 ( sizeof( * V_2 -> V_3 ) , V_51 ) ;
if ( ! V_2 -> V_3 )
goto V_52;
V_34 = V_2 -> V_3 ;
F_27 ( & V_34 -> V_32 ) ;
F_27 ( & V_34 -> V_53 ) ;
F_28 ( & V_34 -> V_28 ) ;
if ( F_23 ( V_2 , V_6 ) != 0 ) {
F_29 ( V_2 , L_3 ) ;
return 0 ;
}
V_50 = F_9 ( V_34 -> V_13 ) * sizeof( T_1 ) ;
V_34 -> V_17 = F_12 ( V_50 , V_51 ) ;
V_34 -> V_31 = F_12 ( V_50 , V_51 ) ;
if ( ! V_34 -> V_31 || ! V_34 -> V_16 )
goto V_52;
return 0 ;
V_52:
F_19 ( V_2 ) ;
return - V_54 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_55 = F_4 ( V_2 , V_6 , V_49 ) ;
if ( V_2 -> V_3 -> V_48 != V_55 ) {
F_7 ( V_2 ,
V_11 ,
L_4 ,
V_2 -> V_3 -> V_48 , V_55 ) ;
F_23 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_6 ) ;
}
}
int F_31 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_56 , V_57 , V_58 = V_59 , V_60 = 0 ;
int V_61 = 0 ;
F_20 ( & V_2 -> V_3 -> V_32 ) ;
V_56 = F_4 ( V_2 , V_6 , V_49 ) ;
F_30 ( V_2 , V_6 ) ;
V_57 = ++ V_2 -> V_3 -> V_42 ;
F_32 ( V_2 , V_6 , V_43 , ( V_62 | V_57 ) ) ;
do {
F_33 ( V_58 ) ;
} while ( ( V_56 == F_4 ( V_2 , V_6 ,
V_49 ) ) &&
( V_60 ++ < V_63 ) );
if ( V_56 !=
F_4 ( V_2 , V_6 , V_49 ) ) {
F_7 ( V_2 , V_11 ,
L_5 , V_60 * V_58 ) ;
} else {
F_34 ( V_2 , L_6 ) ;
V_61 = - V_64 ;
}
F_22 ( & V_2 -> V_3 -> V_32 ) ;
return V_61 ;
}
static bool F_35 ( struct V_1 * V_2 )
{
struct V_20 * V_24 ;
if ( ! F_36 ( & V_2 -> V_3 -> V_28 ) ) {
V_24 = F_37 ( & V_2 -> V_3 -> V_28 ,
struct V_20 , V_27 ) ;
return ! V_24 -> V_65 ;
}
return false ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
struct V_20 * V_24 ;
T_1 V_66 ;
T_2 V_29 ;
V_66 = F_25 ( V_2 , V_6 , V_67 ) ;
V_29 = ( T_2 ) ( V_66 & V_68 ) ;
if ( V_29 != V_2 -> V_3 -> V_42 )
return - V_64 ;
V_24 = F_17 ( V_2 , V_29 ) ;
if ( ! V_24 ) {
F_34 ( V_2 ,
L_7 ,
V_29 ) ;
return - V_69 ;
}
V_22 = V_24 -> V_22 ;
V_22 -> V_66 = V_66 ;
V_22 -> V_70 = F_25 ( V_2 , V_6 , V_71 ) ;
if ( V_22 -> V_72 != NULL && V_22 -> V_73 ) {
T_1 V_74 = V_2 -> V_3 -> V_40 +
F_39 ( struct V_75 ,
V_76 ) ;
F_40 ( V_2 , V_6 , V_22 -> V_72 ,
V_74 , V_22 -> V_73 ) ;
}
V_24 -> V_65 = true ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_21 * V_22 ,
T_2 V_29 )
{
union V_77 V_76 ;
T_1 V_74 ;
V_74 = V_2 -> V_3 -> V_40 +
F_39 ( struct V_75 , V_76 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
if ( V_22 -> V_78 != NULL && V_22 -> V_79 )
memcpy ( & V_76 , V_22 -> V_78 ,
V_22 -> V_79 ) ;
F_42 ( V_2 , V_6 , V_74 , & V_76 ,
sizeof( V_76 ) ) ;
F_32 ( V_2 , V_6 , V_80 , V_22 -> V_81 ) ;
F_32 ( V_2 , V_6 , V_43 , ( V_22 -> V_82 | V_29 ) ) ;
F_7 ( V_2 , V_11 ,
L_8 ,
( V_22 -> V_82 | V_29 ) , V_22 -> V_81 ) ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_21 * V_22 ,
T_1 V_83 , T_1 V_58 )
{
struct V_20 * V_24 ;
T_1 V_60 = 0 ;
T_2 V_29 ;
int V_61 = 0 ;
do {
F_20 ( & V_2 -> V_3 -> V_32 ) ;
if ( ! F_35 ( V_2 ) )
break;
V_61 = F_38 ( V_2 , V_6 ) ;
if ( ! V_61 )
break;
else if ( V_61 != - V_64 )
goto V_52;
F_22 ( & V_2 -> V_3 -> V_32 ) ;
F_33 ( V_58 ) ;
} while ( ++ V_60 < V_83 );
if ( V_60 >= V_83 ) {
F_29 ( V_2 ,
L_9 ,
V_22 -> V_82 , V_22 -> V_81 ) ;
return - V_64 ;
}
F_30 ( V_2 , V_6 ) ;
V_29 = ++ V_2 -> V_3 -> V_42 ;
V_24 = F_11 ( V_2 , V_22 , V_29 ) ;
if ( ! V_24 ) {
V_61 = - V_54 ;
goto V_52;
}
F_41 ( V_2 , V_6 , V_22 , V_29 ) ;
F_22 ( & V_2 -> V_3 -> V_32 ) ;
do {
F_33 ( V_58 ) ;
F_20 ( & V_2 -> V_3 -> V_32 ) ;
if ( V_24 -> V_65 )
break;
V_61 = F_38 ( V_2 , V_6 ) ;
if ( ! V_61 )
break;
else if ( V_61 != - V_64 )
goto V_52;
F_22 ( & V_2 -> V_3 -> V_32 ) ;
} while ( ++ V_60 < V_83 );
if ( V_60 >= V_83 ) {
F_29 ( V_2 ,
L_10 ,
V_22 -> V_82 , V_22 -> V_81 ) ;
F_20 ( & V_2 -> V_3 -> V_32 ) ;
F_14 ( V_2 , V_24 ) ;
F_22 ( & V_2 -> V_3 -> V_32 ) ;
return - V_64 ;
}
F_14 ( V_2 , V_24 ) ;
F_22 ( & V_2 -> V_3 -> V_32 ) ;
F_7 ( V_2 ,
V_11 ,
L_11 ,
V_22 -> V_66 ,
V_22 -> V_70 ,
( V_60 * V_58 ) / 1000 , ( V_60 * V_58 ) % 1000 ) ;
V_22 -> V_66 &= V_84 ;
return 0 ;
V_52:
F_22 ( & V_2 -> V_3 -> V_32 ) ;
return V_61 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
T_3 V_85 = sizeof( union V_77 ) ;
T_1 V_83 = V_86 ;
T_1 V_58 = V_59 ;
if ( ! F_1 ( V_2 ) ) {
F_29 ( V_2 , L_12 ) ;
return - V_87 ;
}
if ( V_22 -> V_79 > V_85 ||
V_22 -> V_73 > V_85 ) {
F_34 ( V_2 ,
L_13 ,
V_22 -> V_79 ,
V_22 -> V_73 , V_85 ) ;
return - V_69 ;
}
return F_43 ( V_2 , V_6 , V_22 , V_83 ,
V_58 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_82 ,
T_1 V_81 ,
T_1 * V_88 ,
T_1 * V_89 )
{
struct V_21 V_90 ;
int V_61 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_82 ;
V_90 . V_81 = V_81 ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
return V_61 ;
* V_88 = V_90 . V_66 ;
* V_89 = V_90 . V_70 ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_82 ,
T_1 V_81 ,
T_1 * V_88 ,
T_1 * V_89 , T_1 * V_91 , T_1 * V_92 )
{
struct V_21 V_90 ;
T_4 V_93 [ V_94 ] ;
int V_61 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_82 ;
V_90 . V_81 = V_81 ;
V_90 . V_72 = V_93 ;
V_90 . V_73 = V_94 ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
return V_61 ;
* V_88 = V_90 . V_66 ;
* V_89 = V_90 . V_70 ;
* V_91 = * V_89 ;
memcpy ( V_92 , V_93 , * V_91 ) ;
return 0 ;
}
static bool
F_47 ( T_4 V_95 ,
T_4 V_96 ,
enum V_97 V_98 )
{
bool V_99 = false ;
switch ( V_98 ) {
case V_100 :
V_99 = true ;
break;
case V_101 :
V_99 = false ;
break;
default:
V_99 = ( V_95 == V_102 &&
V_96 == V_103 ) ||
( V_95 == V_104 &&
V_96 == V_102 ) ;
break;
}
return V_99 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_106 , 0 ,
& V_105 , & V_81 ) ;
if ( V_61 )
F_29 ( V_2 ,
L_14 , V_61 ) ;
return V_61 ;
}
static T_1 F_49 ( void )
{
T_1 V_107 = 0x0 ;
if ( F_50 ( V_108 ) )
V_107 |= V_109 ;
if ( F_50 ( V_110 ) )
V_107 |= V_111 ;
if ( F_50 ( V_112 ) )
V_107 |= V_113 ;
if ( F_50 ( V_114 ) )
V_107 |= V_115 ;
if ( F_50 ( V_116 ) )
V_107 |= V_117 ;
if ( F_50 ( V_118 ) )
V_107 |= V_119 ;
return V_107 ;
}
static int
F_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_21 V_90 ;
struct V_124 V_125 ;
struct V_126 V_127 ;
T_1 V_128 ;
int V_61 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_129 = V_121 -> V_129 ;
V_125 . V_130 = V_121 -> V_130 ;
V_125 . V_131 = V_121 -> V_131 ;
F_52 ( V_125 . V_132 , V_133 , V_121 -> V_95 ) ;
F_52 ( V_125 . V_132 , V_134 ,
V_121 -> V_135 ) ;
F_52 ( V_125 . V_132 , V_136 ,
V_121 -> V_137 ) ;
F_52 ( V_125 . V_132 , V_138 ,
V_121 -> V_139 ) ;
V_128 = ( V_121 -> V_128 == V_140 ) ?
V_141 :
( V_121 -> V_128 << V_142 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_143 ;
V_90 . V_81 = V_144 | V_128 | V_2 -> V_145 -> V_146 ;
V_90 . V_78 = & V_125 ;
V_90 . V_79 = sizeof( V_125 ) ;
V_90 . V_72 = & V_127 ;
V_90 . V_73 = sizeof( V_127 ) ;
F_7 ( V_2 , V_11 ,
L_15 ,
V_90 . V_81 ,
F_53 ( V_90 . V_81 , V_147 ) ,
F_53 ( V_90 . V_81 , V_148 ) ,
F_53 ( V_90 . V_81 , V_149 ) ,
F_53 ( V_90 . V_81 , V_150 ) ) ;
if ( V_121 -> V_128 != V_151 ) {
F_7 ( V_2 , V_11 ,
L_16 ,
V_125 . V_129 ,
V_125 . V_130 ,
V_125 . V_131 ,
V_125 . V_132 ,
F_53 ( V_125 . V_132 , V_133 ) ,
F_53 ( V_125 . V_132 ,
V_134 ) ,
F_53 ( V_125 . V_132 , V_136 ) ,
F_53 ( V_125 . V_132 , V_138 ) ) ;
}
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 ) {
F_29 ( V_2 , L_17 , V_61 ) ;
return V_61 ;
}
F_7 ( V_2 , V_11 ,
L_18 , V_90 . V_66 ) ;
V_123 -> V_152 = V_90 . V_66 ;
if ( V_121 -> V_128 != V_151 &&
V_123 -> V_152 != V_153 ) {
F_7 ( V_2 ,
V_11 ,
L_19 ,
V_127 . V_129 ,
V_127 . V_130 ,
V_127 . V_131 ,
V_127 . V_132 ,
F_53 ( V_127 . V_132 , V_154 ) ,
F_53 ( V_127 . V_132 , V_155 ) ,
F_53 ( V_127 . V_132 , V_156 ) ) ;
V_123 -> V_157 = V_127 . V_129 ;
V_123 -> V_158 = V_127 . V_130 ;
V_123 -> V_159 = V_127 . V_131 ;
V_123 -> V_96 =
F_53 ( V_127 . V_132 , V_154 ) ;
V_123 -> V_160 =
F_53 ( V_127 . V_132 , V_155 ) ;
V_123 -> V_161 =
F_53 ( V_127 . V_132 , V_156 ) &
V_162 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_163 V_95 ,
T_4 * V_164 )
{
switch ( V_95 ) {
case V_165 :
* V_164 = V_102 ;
break;
case V_166 :
* V_164 = V_104 ;
break;
default:
F_34 ( V_2 , L_20 , V_95 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
enum V_167 V_137 ,
T_4 * V_168 )
{
switch ( V_137 ) {
case V_169 :
* V_168 = V_170 ;
break;
case V_171 :
* V_168 = V_172 ;
break;
case V_173 :
* V_168 = V_174 ;
break;
}
}
int F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_175 * V_176 )
{
struct V_122 V_177 ;
struct V_120 V_178 ;
T_4 V_179 , V_180 ;
int V_61 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_128 = V_140 ;
V_178 . V_129 = V_181 ;
V_178 . V_130 = F_49 () ;
V_178 . V_131 = V_182 ;
V_61 = F_54 ( V_2 , V_176 -> V_95 , & V_179 ) ;
if ( V_61 )
return V_61 ;
V_178 . V_95 = V_179 ;
V_178 . V_135 = V_176 -> V_135 ;
F_55 ( V_2 ,
V_169 , & V_180 ) ;
V_178 . V_137 = V_180 ;
V_178 . V_139 = V_176 -> V_139 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_51 ( V_2 , V_6 , & V_178 , & V_177 ) ;
if ( V_61 )
return V_61 ;
if ( V_177 . V_152 == V_153 ) {
F_57 ( V_2 ,
L_21 ) ;
V_178 . V_128 = V_151 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_51 ( V_2 , V_6 , & V_178 , & V_177 ) ;
if ( V_61 )
return V_61 ;
} else if ( V_177 . V_152 ==
V_183 ) {
if ( F_47 ( V_178 . V_95 ,
V_177 . V_96 ,
V_176 -> V_98 ) ) {
F_57 ( V_2 ,
L_22 ,
V_178 . V_95 , V_178 . V_131 ,
V_178 . V_129 , V_178 . V_130 ,
V_177 . V_96 ,
V_177 . V_159 ,
V_177 . V_157 ,
V_177 . V_158 ) ;
F_55 ( V_2 ,
V_173 ,
& V_180 ) ;
V_178 . V_137 = V_180 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_51 ( V_2 , V_6 , & V_178 ,
& V_177 ) ;
if ( V_61 )
return V_61 ;
} else {
F_29 ( V_2 ,
L_23 ,
V_178 . V_95 , V_178 . V_131 ,
V_178 . V_129 , V_178 . V_130 ,
V_177 . V_96 ,
V_177 . V_159 ,
V_177 . V_157 ,
V_177 . V_158 ) ;
F_29 ( V_2 ,
L_24 ) ;
F_48 ( V_2 , V_6 ) ;
return - V_87 ;
}
}
switch ( V_177 . V_152 ) {
case V_184 :
case V_185 :
case V_186 :
if ( V_177 . V_160 != V_151 &&
V_177 . V_161 ) {
F_29 ( V_2 ,
L_25 ) ;
return - V_69 ;
}
break;
default:
F_29 ( V_2 ,
L_26 ,
V_177 . V_152 ) ;
return - V_87 ;
}
V_176 -> V_152 = V_177 . V_152 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_187 , V_66 , V_70 ;
switch ( V_2 -> V_145 -> V_188 ) {
case V_189 :
V_187 = V_190 ;
break;
case V_191 :
V_187 = V_192 ;
break;
default:
F_29 ( V_2 ,
L_27 ,
V_2 -> V_145 -> V_188 ) ;
case V_193 :
V_187 = V_194 ;
}
return F_45 ( V_2 , V_6 , V_195 , V_187 ,
& V_66 , & V_70 ) ;
}
int F_59 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_21 V_90 ;
struct V_196 V_197 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_198 ;
if ( V_2 -> V_145 -> V_188 == V_191 ) {
T_4 * V_199 = V_2 -> V_145 -> V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_200 = V_199 [ 0 ] << 8 | V_199 [ 1 ] ;
V_197 . V_201 = V_199 [ 2 ] << 24 | V_199 [ 3 ] << 16 |
V_199 [ 4 ] << 8 | V_199 [ 5 ] ;
F_7 ( V_2 ,
( V_11 | V_202 ) ,
L_28 ,
V_199 , V_197 . V_200 , V_197 . V_201 ) ;
V_90 . V_78 = & V_197 ;
V_90 . V_79 = sizeof( V_197 ) ;
}
return F_44 ( V_2 , V_6 , & V_90 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_203 ) ;
T_1 V_204 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_205 = F_5 ( V_204 ,
F_61 ( V_2 ) ) ;
T_1 V_206 [ V_207 / 32 ] ;
int V_15 ;
F_7 ( V_2 ,
V_11 ,
L_29 ,
V_204 , V_205 ) ;
for ( V_15 = 0 ; V_15 < ( V_207 / 32 ) ; V_15 ++ ) {
V_206 [ V_15 ] = F_4 ( V_2 , V_6 ,
V_205 +
F_39 ( struct V_208 ,
V_209 ) +
sizeof( T_1 ) * V_15 ) ;
F_7 ( V_2 , ( V_11 | V_210 ) ,
L_30 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_206 [ V_15 ] ) ;
}
if ( F_62 ( V_2 , V_206 ) )
F_63 ( V_2 , V_211 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_212 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_213 ) ;
T_1 V_214 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_215 = F_5 ( V_214 ,
F_24 ( V_2 ) ) ;
struct V_21 V_90 ;
int V_61 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < ( V_207 / 32 ) ; V_15 ++ )
F_7 ( V_2 , ( V_11 | V_210 ) ,
L_31 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_212 [ V_15 ] ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_216 ;
V_90 . V_78 = V_212 ;
V_90 . V_79 = V_207 / 8 ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 ) {
F_29 ( V_2 , L_32 ) ;
return - V_87 ;
}
for ( V_15 = 0 ; V_15 < ( V_207 / 32 ) ; V_15 ++ )
F_65 ( V_2 , V_6 ,
V_215 +
F_39 ( struct V_217 , V_218 ) +
V_15 * sizeof( T_1 ) , 0 ) ;
return V_61 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_219 ;
V_219 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 ,
V_221 ) ) ;
F_7 ( V_2 ,
( V_222 | V_11 ) ,
L_33 ,
V_219 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_221 ) ) ) ;
V_219 = F_67 ( V_219 ,
V_223 ) ;
if ( V_219 == V_224 )
F_29 ( V_2 , L_34 ) ;
else
F_29 ( V_2 , L_35 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_5 * V_6 , bool V_225 )
{
struct V_226 * V_227 ;
T_4 V_228 , V_229 ;
T_1 V_230 = 0 ;
F_20 ( & V_2 -> V_3 -> V_53 ) ;
V_227 = & V_2 -> V_3 -> V_231 ;
memset ( V_227 , 0 , sizeof( * V_227 ) ) ;
if ( ! V_225 ) {
V_230 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_232 ) ) ;
F_7 ( V_2 , ( V_233 | V_11 ) ,
L_36 ,
V_230 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_232 ) ) ) ;
} else {
F_7 ( V_2 , V_233 ,
L_37 ) ;
goto V_26;
}
if ( V_2 -> V_234 )
V_227 -> V_235 = ! ! ( V_230 & V_236 ) ;
else
V_227 -> V_235 = false ;
V_227 -> V_237 = true ;
switch ( ( V_230 & V_238 ) ) {
case V_239 :
V_227 -> V_240 = 100000 ;
break;
case V_241 :
V_227 -> V_240 = 50000 ;
break;
case V_242 :
V_227 -> V_240 = 40000 ;
break;
case V_243 :
V_227 -> V_240 = 25000 ;
break;
case V_244 :
V_227 -> V_240 = 20000 ;
break;
case V_245 :
V_227 -> V_240 = 10000 ;
break;
case V_246 :
V_227 -> V_237 = false ;
case V_247 :
V_227 -> V_240 = 1000 ;
break;
default:
V_227 -> V_240 = 0 ;
}
if ( V_227 -> V_235 && V_227 -> V_240 )
V_227 -> V_248 = V_227 -> V_240 ;
else
V_227 -> V_248 = 0 ;
V_228 = V_2 -> V_3 -> V_249 . V_250 ;
V_229 = V_2 -> V_3 -> V_249 . V_251 ;
F_69 ( V_2 , V_6 , V_227 , V_228 ) ;
F_70 ( V_2 , V_6 , V_227 , V_229 ) ;
F_71 ( V_2 -> V_145 , V_6 ,
V_227 -> V_252 ) ;
V_227 -> V_253 = ! ! ( V_230 & V_254 ) ;
V_227 -> V_255 = ! ! ( V_230 &
V_256 ) ;
V_227 -> V_257 = ! ! ( V_230 &
V_258 ) ;
V_227 -> V_259 = ! ! ( V_230 & V_260 ) ;
V_227 -> V_261 |=
( V_230 & V_262 ) ?
V_263 : 0 ;
V_227 -> V_261 |=
( V_230 & V_264 ) ?
V_265 : 0 ;
V_227 -> V_261 |=
( V_230 & V_266 ) ?
V_267 : 0 ;
V_227 -> V_261 |=
( V_230 & V_268 ) ?
V_269 : 0 ;
V_227 -> V_261 |=
( V_230 & V_270 ) ?
V_271 : 0 ;
V_227 -> V_261 |=
( V_230 & V_272 ) ?
V_273 : 0 ;
V_227 -> V_261 |=
( V_230 & V_274 ) ?
V_275 : 0 ;
V_227 -> V_261 |=
( V_230 & V_276 ) ?
V_277 : 0 ;
V_227 -> V_278 =
! ! ( V_230 & V_279 ) ;
V_227 -> V_280 =
! ! ( V_230 & V_281 ) ;
switch ( V_230 & V_282 ) {
case V_283 :
V_227 -> V_284 = V_285 ;
break;
case V_286 :
V_227 -> V_284 = V_287 ;
break;
case V_288 :
V_227 -> V_284 = V_289 ;
break;
default:
V_227 -> V_284 = 0 ;
}
V_227 -> V_290 = ! ! ( V_230 & V_291 ) ;
F_72 ( V_2 ) ;
V_26:
F_22 ( & V_2 -> V_3 -> V_53 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_292 )
{
struct V_293 * V_294 = & V_2 -> V_3 -> V_295 ;
struct V_21 V_90 ;
struct V_296 V_297 ;
int V_61 = 0 ;
T_1 V_82 ;
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
V_82 = V_292 ? V_298 : V_299 ;
if ( ! V_294 -> V_240 . V_300 )
V_297 . V_240 = V_294 -> V_240 . V_301 ;
V_297 . V_302 |= ( V_294 -> V_302 . V_300 ) ? V_303 : 0 ;
V_297 . V_302 |= ( V_294 -> V_302 . V_304 ) ? V_305 : 0 ;
V_297 . V_302 |= ( V_294 -> V_302 . V_306 ) ? V_307 : 0 ;
V_297 . V_308 = V_294 -> V_240 . V_309 ;
V_297 . V_310 = V_294 -> V_310 ;
V_2 -> V_234 = V_292 ;
if ( V_292 ) {
F_7 ( V_2 , V_233 ,
L_38 ,
V_297 . V_240 ,
V_297 . V_302 ,
V_297 . V_308 ,
V_297 . V_310 ,
V_297 . V_311 ) ;
} else {
F_7 ( V_2 , V_233 ,
L_39 ) ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_82 ;
V_90 . V_78 = & V_297 ;
V_90 . V_79 = sizeof( V_297 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 ) {
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
F_68 ( V_2 , V_6 , ! V_292 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_312 type )
{
enum V_313 V_314 ;
union V_315 V_316 ;
struct V_21 V_90 ;
T_1 V_317 ;
switch ( type ) {
case V_318 :
V_314 = V_319 ;
V_317 = V_320 ;
break;
case V_321 :
V_314 = V_322 ;
V_317 = V_323 ;
break;
case V_324 :
V_314 = V_325 ;
V_317 = V_326 ;
break;
case V_327 :
V_314 = V_328 ;
V_317 = V_329 ;
break;
default:
F_29 ( V_2 , L_41 , type ) ;
return;
}
F_75 ( V_2 -> V_145 , V_314 , & V_316 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_330 ;
V_90 . V_81 = V_317 ;
V_90 . V_78 = & V_316 ;
V_90 . V_79 = sizeof( V_316 ) ;
F_44 ( V_2 , V_6 , & V_90 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_217 * V_331 )
{
struct V_332 * V_34 ;
V_34 = & V_2 -> V_3 -> V_249 ;
V_34 -> V_251 = ( V_331 -> V_333 &
V_334 ) >>
V_335 ;
if ( V_34 -> V_251 < 1 || V_34 -> V_251 > 100 ) {
F_57 ( V_2 ,
L_42 ,
V_34 -> V_251 ) ;
V_34 -> V_251 = 1 ;
}
V_34 -> V_250 = ( V_331 -> V_333 &
V_336 ) >>
V_337 ;
if ( V_34 -> V_250 < 1 || V_34 -> V_250 > 100 ) {
F_57 ( V_2 ,
L_43 ,
V_34 -> V_250 ) ;
V_34 -> V_250 = 100 ;
}
}
static T_1 F_77 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_217 * V_338 , int V_339 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_213 ) ;
T_1 V_204 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_215 = F_5 ( V_204 , V_339 ) ;
T_1 V_15 , V_50 ;
memset ( V_338 , 0 , sizeof( * V_338 ) ) ;
V_50 = F_78 ( T_1 , sizeof( * V_338 ) , F_79 ( V_204 ) ) ;
for ( V_15 = 0 ; V_15 < V_50 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_338 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_215 + ( V_15 << 2 ) ) ;
return V_50 ;
}
static void F_80 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_332 * V_34 ;
struct V_217 V_340 ;
T_1 V_105 = 0 , V_81 = 0 ;
F_77 ( V_2 , V_6 , & V_340 , F_24 ( V_2 ) ) ;
F_76 ( V_2 , & V_340 ) ;
V_34 = & V_2 -> V_3 -> V_249 ;
F_81 ( V_2 -> V_145 , V_34 -> V_251 ) ;
F_82 ( V_2 -> V_145 , V_34 -> V_250 ) ;
F_45 ( V_2 , V_6 , V_341 , 0 , & V_105 ,
& V_81 ) ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_33 * V_342 = V_2 -> V_3 ;
int V_61 = 0 ;
bool V_343 = false ;
T_2 V_15 ;
F_7 ( V_2 , V_11 , L_44 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_342 -> V_13 ; V_15 ++ ) {
if ( V_342 -> V_17 [ V_15 ] == V_342 -> V_31 [ V_15 ] )
continue;
V_343 = true ;
F_7 ( V_2 , V_233 ,
L_45 ,
V_15 , V_342 -> V_31 [ V_15 ] , V_342 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_344 :
F_68 ( V_2 , V_6 , false ) ;
break;
case V_345 :
F_60 ( V_2 , V_6 ) ;
break;
case V_346 :
F_84 ( V_2 , V_6 ,
V_347 ) ;
break;
case V_348 :
F_84 ( V_2 , V_6 ,
V_349 ) ;
break;
case V_350 :
F_84 ( V_2 , V_6 ,
V_351 ) ;
break;
case V_352 :
F_66 ( V_2 , V_6 ) ;
break;
case V_318 :
case V_321 :
case V_324 :
case V_327 :
F_74 ( V_2 , V_6 , V_15 ) ;
break;
case V_353 :
F_80 ( V_2 , V_6 ) ;
break;
default:
F_57 ( V_2 , L_46 , V_15 ) ;
V_61 = - V_69 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_342 -> V_13 ) ; V_15 ++ ) {
V_19 V_354 = F_85 ( ( ( T_1 * ) V_342 -> V_17 ) [ V_15 ] ) ;
F_65 ( V_2 , V_6 ,
V_342 -> V_16 + sizeof( T_1 ) +
F_9 ( V_342 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_354 ) ;
}
if ( ! V_343 ) {
F_29 ( V_2 ,
L_47 ) ;
V_61 = - V_69 ;
}
memcpy ( V_342 -> V_31 , V_342 -> V_17 , V_342 -> V_13 ) ;
return V_61 ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_355 , T_1 * V_356 )
{
T_1 V_357 ;
if ( F_87 ( V_2 -> V_145 ) ) {
if ( V_2 -> V_358 ) {
struct V_359 * V_360 ;
V_360 = & V_2 -> V_358 -> V_361 ;
* V_355 = V_360 -> V_362 . V_363 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_210 ,
L_48 ) ;
return - V_69 ;
}
}
V_357 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_364 ) ) ;
* V_355 =
F_4 ( V_2 , V_6 ,
F_5 ( V_357 ,
0 ) + F_39 ( struct V_365 , V_363 ) ) ;
if ( V_356 != NULL ) {
* V_356 = F_4 ( V_2 , V_6 ,
F_5 ( V_357 , 0 ) +
F_39 ( struct V_365 ,
V_366 ) ) ;
}
return 0 ;
}
int F_88 ( struct V_367 * V_145 , T_1 * V_368 )
{
struct V_1 * V_2 = & V_145 -> V_369 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_87 ( V_145 ) )
return - V_69 ;
if ( ! F_1 ( V_2 ) ) {
F_29 ( V_2 , L_12 ) ;
return - V_87 ;
}
* V_368 = V_370 ;
V_6 = F_89 ( V_2 ) ;
if ( ! V_6 )
return - V_87 ;
* V_368 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_371 ) ) ;
F_90 ( V_2 , V_6 ) ;
return 0 ;
}
static void
F_91 ( struct V_1 * V_2 ,
enum V_372 * V_373 )
{
if ( F_92 ( V_374 , & V_2 -> V_375 . V_376 ) )
* V_373 = V_377 ;
else
* V_373 = V_378 ;
F_7 ( V_2 , V_379 ,
L_49 ,
( T_1 ) * V_373 ) ;
}
static int
F_93 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_372 * V_373 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_380 , 0 , & V_105 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( V_105 != V_381 ) {
F_7 ( V_2 , V_379 ,
L_50 ,
V_105 ) ;
return - V_69 ;
}
switch ( V_81 ) {
case V_382 :
* V_373 = V_378 ;
break;
case V_383 :
* V_373 = V_377 ;
break;
case V_384 :
F_29 ( V_2 ,
L_51 ) ;
* V_373 = V_377 ;
break;
case V_385 :
default:
F_29 ( V_2 ,
L_52 ,
V_81 ) ;
return - V_69 ;
}
F_7 ( V_2 ,
V_379 ,
L_53 ,
( T_1 ) * V_373 , V_105 , V_81 ) ;
return 0 ;
}
static int
F_94 ( struct V_1 * V_2 ,
struct V_217 * V_34 ,
struct V_5 * V_6 ,
enum V_372 * V_373 )
{
int V_61 = 0 ;
switch ( V_34 -> V_333 & V_386 ) {
case V_387 :
if ( ! F_50 ( V_112 ) )
* V_373 = V_378 ;
else if ( F_93 ( V_2 , V_6 , V_373 ) )
F_91 ( V_2 , V_373 ) ;
break;
case V_388 :
* V_373 = V_389 ;
break;
case V_390 :
* V_373 = V_391 ;
break;
case V_392 :
F_29 ( V_2 , L_54 ) ;
default:
V_61 = - V_69 ;
}
return V_61 ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_332 * V_342 ;
struct V_217 V_340 ;
F_77 ( V_2 , V_6 , & V_340 , F_24 ( V_2 ) ) ;
V_342 = & V_2 -> V_3 -> V_249 ;
V_342 -> V_393 = ( V_340 . V_333 &
V_394 ) ? 1 : 0 ;
if ( F_94 ( V_2 , & V_340 , V_6 ,
& V_342 -> V_395 ) ) {
F_34 ( V_2 , L_55 ,
( T_1 ) ( V_340 . V_333 & V_386 ) ) ;
return - V_69 ;
}
F_76 ( V_2 , & V_340 ) ;
if ( V_340 . V_200 || V_340 . V_201 ) {
V_342 -> V_396 [ 0 ] = ( T_4 ) ( V_340 . V_200 >> 8 ) ;
V_342 -> V_396 [ 1 ] = ( T_4 ) ( V_340 . V_200 ) ;
V_342 -> V_396 [ 2 ] = ( T_4 ) ( V_340 . V_201 >> 24 ) ;
V_342 -> V_396 [ 3 ] = ( T_4 ) ( V_340 . V_201 >> 16 ) ;
V_342 -> V_396 [ 4 ] = ( T_4 ) ( V_340 . V_201 >> 8 ) ;
V_342 -> V_396 [ 5 ] = ( T_4 ) ( V_340 . V_201 ) ;
memcpy ( & V_2 -> V_145 -> V_197 , V_342 -> V_396 , V_397 ) ;
} else {
F_29 ( V_2 , L_56 ) ;
}
V_342 -> V_398 = ( V_399 ) V_340 . V_400 |
( ( ( V_399 ) V_340 . V_401 ) << 32 ) ;
V_342 -> V_402 = ( V_399 ) V_340 . V_403 |
( ( ( V_399 ) V_340 . V_404 ) << 32 ) ;
V_342 -> V_405 = ( T_2 ) ( V_340 . V_406 & V_407 ) ;
V_342 -> V_408 = ( T_2 ) V_340 . V_409 ;
V_2 -> V_375 . V_410 = V_411 ;
V_2 -> V_145 -> V_188 = ( T_4 ) V_193 ;
if ( F_1 ( V_2 ) ) {
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_412 , 0 , & V_105 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( V_105 == V_413 )
V_2 -> V_375 . V_410 = V_414 ;
}
F_7 ( V_2 , ( V_11 | V_379 ) ,
L_57 ,
V_342 -> V_393 , V_342 -> V_395 ,
V_342 -> V_251 , V_342 -> V_250 ,
V_342 -> V_396 [ 0 ] , V_342 -> V_396 [ 1 ] , V_342 -> V_396 [ 2 ] ,
V_342 -> V_396 [ 3 ] , V_342 -> V_396 [ 4 ] , V_342 -> V_396 [ 5 ] ,
V_342 -> V_398 , V_342 -> V_402 ,
V_342 -> V_405 , ( T_4 ) V_2 -> V_375 . V_410 ) ;
return 0 ;
}
struct V_293
* F_96 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_295 ;
}
struct V_226
* F_97 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_231 ;
}
struct V_415
* F_98 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_416 ;
}
int F_99 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_417 , 1000 , & V_105 , & V_81 ) ;
F_100 ( 1020 ) ;
return V_61 ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_418 )
{
T_1 V_419 ;
if ( F_87 ( V_2 -> V_145 ) )
return - V_69 ;
V_419 = F_4 ( V_2 , V_6 , V_420 ) ;
V_419 = ( V_419 & V_421 ) >>
V_422 ;
V_419 = ( 1 << ( V_419 + V_423 ) ) ;
* V_418 = V_419 ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 V_424 , T_4 V_425 )
{
T_1 V_105 = 0 , V_81 = 0 , V_426 = 0 ;
int V_61 ;
if ( ! F_103 ( V_2 ) )
return 0 ;
V_425 *= V_2 -> V_145 -> V_427 ;
V_81 |= ( V_424 << V_428 ) &
V_429 ;
V_81 |= ( V_425 << V_430 ) &
V_431 ;
V_61 = F_45 ( V_2 , V_6 , V_432 , V_81 ,
& V_105 , & V_426 ) ;
if ( V_105 != V_433 ) {
F_29 ( V_2 , L_58 , V_424 ) ;
V_61 = - V_69 ;
} else {
F_7 ( V_2 , V_210 ,
L_59 ,
V_425 , V_424 ) ;
}
return V_61 ;
}
int
F_104 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_434 * V_435 )
{
struct V_21 V_90 ;
struct V_436 V_437 ;
V_19 V_354 ;
T_1 V_15 ;
int V_61 ;
memset ( & V_437 , 0 , sizeof( V_437 ) ) ;
V_437 . V_438 = V_435 -> V_438 ;
for ( V_15 = 0 ; V_15 < ( V_439 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_354 = F_85 ( * ( ( T_1 * ) & V_435 -> V_440 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_437 . V_440 [ V_15 * sizeof( T_1 ) ] = V_354 ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_441 ;
V_90 . V_78 = & V_437 ;
V_90 . V_79 = sizeof( V_437 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_105 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_442 , 0 , & V_105 ,
& V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_106 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_443 , V_444 ;
F_65 ( V_2 , V_6 , V_445 , 0xffffffff ) ;
V_443 = F_4 ( V_2 , V_6 , V_446 ) ;
V_443 &= ~ V_447 ;
F_65 ( V_2 , V_6 , V_446 , V_443 ) ;
V_444 = F_4 ( V_2 , V_6 , V_446 ) ;
return ( V_444 & V_447 ) ? - V_64 : 0 ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_448 V_449 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_449 ) {
case V_450 :
V_80 = V_451 ;
break;
case V_452 :
V_80 = V_453 ;
break;
case V_454 :
V_80 = V_455 ;
break;
default:
F_29 ( V_2 , L_60 , V_449 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_456 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_457 V_458 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_458 ) {
case V_459 :
V_80 = V_460 ;
break;
case V_461 :
V_80 = V_462 ;
break;
case V_463 :
V_80 = V_464 ;
break;
default:
F_29 ( V_2 , L_61 , V_458 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_465 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_62 ) ;
return V_61 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_408 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
V_80 = ( T_1 ) V_408 << V_466 ;
V_61 = F_45 ( V_2 , V_6 , V_467 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_63 , V_61 ) ;
return V_61 ;
}
int F_110 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 * V_396 )
{
struct V_21 V_90 ;
T_1 V_468 [ 2 ] ;
int V_61 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_469 ;
V_90 . V_81 = V_470 <<
V_471 ;
V_90 . V_81 |= F_24 ( V_2 ) ;
V_468 [ 0 ] = V_396 [ 0 ] << 24 | V_396 [ 1 ] << 16 | V_396 [ 2 ] << 8 | V_396 [ 3 ] ;
V_468 [ 1 ] = V_396 [ 4 ] << 24 | V_396 [ 5 ] << 16 ;
V_90 . V_78 = ( T_4 * ) V_468 ;
V_90 . V_79 = 8 ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
F_34 ( V_2 , L_64 , V_61 ) ;
memcpy ( V_2 -> V_145 -> V_197 , V_396 , V_397 ) ;
return V_61 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_472 V_473 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
if ( V_2 -> V_375 . V_410 == V_411 ) {
F_7 ( V_2 , V_11 ,
L_65 ) ;
return - V_69 ;
}
switch ( V_473 ) {
case V_193 :
V_80 = V_474 ;
break;
case V_189 :
V_80 = V_475 ;
break;
case V_191 :
V_80 = V_476 ;
break;
default:
F_34 ( V_2 , L_66 , V_473 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_477 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_67 , V_61 ) ;
V_2 -> V_145 -> V_188 = ( T_4 ) V_473 ;
return V_61 ;
}
int F_112 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_478 V_479 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_479 ) {
case V_480 :
V_80 = V_481 ;
break;
case V_482 :
V_80 = V_483 ;
break;
case V_484 :
V_80 = V_485 ;
break;
default:
F_34 ( V_2 , L_68 , V_479 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_486 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_69 , V_61 ) ;
return V_61 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_487 V_488 )
{
T_1 V_105 = 0 , V_81 = 0 , V_80 ;
int V_61 ;
switch ( V_488 ) {
case V_489 :
V_80 = V_490 ;
break;
case V_491 :
V_80 = V_492 ;
break;
case V_493 :
V_80 = V_494 ;
break;
default:
F_29 ( V_2 , L_70 , V_488 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_495 ,
V_80 , & V_105 , & V_81 ) ;
return V_61 ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_496 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_497 ,
V_496 , & V_105 , & V_81 ) ;
if ( V_61 ) {
F_34 ( V_2 ,
L_71 ) ;
} else if ( V_105 != V_381 ) {
F_34 ( V_2 ,
L_72 ) ;
V_61 = - V_69 ;
}
return V_61 ;
}
int F_115 ( struct V_367 * V_145 , T_1 V_7 , T_4 * V_498 , T_1 V_499 )
{
T_1 V_500 = V_499 , V_501 = 0 , V_502 , V_503 = 0 ;
struct V_1 * V_2 = F_116 ( V_145 ) ;
T_1 V_105 = 0 , V_504 = 0 ;
struct V_5 * V_6 ;
int V_61 = 0 ;
V_6 = F_89 ( V_2 ) ;
if ( ! V_6 )
return - V_87 ;
while ( V_500 > 0 ) {
V_502 = F_78 ( T_1 , V_500 , V_94 ) ;
V_61 = F_46 ( V_2 , V_6 ,
V_505 ,
V_7 + V_501 +
( V_502 <<
V_506 ) ,
& V_105 , & V_504 ,
& V_503 ,
( T_1 * ) ( V_498 + V_501 ) ) ;
if ( V_61 || ( V_105 != V_507 ) ) {
F_29 ( V_145 , L_73 , V_61 ) ;
break;
}
if ( V_500 % 0x1000 <
( V_500 - V_503 ) % 0x1000 )
F_117 ( 1000 , 2000 ) ;
V_501 += V_503 ;
V_500 -= V_503 ;
}
V_145 -> V_508 = V_105 ;
F_90 ( V_2 , V_6 ) ;
return V_61 ;
}
int F_118 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_80 = 0 , V_509 , V_81 ;
int V_61 = 0 ;
V_80 = ( V_510 <<
V_511 ) ;
V_61 = F_45 ( V_2 , V_6 , V_512 ,
V_80 , & V_509 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_509 & V_84 ) != V_381 ) ||
( V_81 != V_513 ) )
V_61 = - V_64 ;
return V_61 ;
}
int F_119 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_80 , V_509 , V_81 ;
int V_61 = 0 ;
V_80 = ( V_514 <<
V_511 ) ;
V_61 = F_45 ( V_2 , V_6 , V_512 ,
V_80 , & V_509 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_509 & V_84 ) != V_381 ) ||
( V_81 != V_513 ) )
V_61 = - V_64 ;
return V_61 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_515 )
{
T_1 V_80 = 0 , V_509 ;
int V_61 = 0 ;
V_80 = ( V_516 <<
V_511 ) ;
V_61 = F_45 ( V_2 , V_6 , V_512 ,
V_80 , & V_509 , V_515 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_509 & V_84 ) != V_381 ) )
V_61 = - V_69 ;
return V_61 ;
}
int F_121 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_517 * V_518 ,
T_1 V_519 )
{
T_1 V_520 = 0 , V_81 , V_105 = 0 , V_504 = 0 ;
int V_61 ;
V_81 = V_521 <<
V_511 ;
V_81 |= V_519 << V_522 ;
V_61 = F_46 ( V_2 , V_6 ,
V_512 , V_81 ,
& V_105 , & V_504 ,
& V_520 ,
( T_1 * ) V_518 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_105 & V_84 ) != V_381 ) ||
( V_518 -> V_523 != 1 ) )
V_61 = - V_69 ;
return V_61 ;
}
static enum V_524 F_122 ( enum V_525 V_526 )
{
enum V_524 V_527 = V_528 ;
switch ( V_526 ) {
case V_529 :
V_527 = V_530 ;
break;
case V_531 :
V_527 = V_532 ;
break;
case V_533 :
V_527 = V_534 ;
break;
case V_535 :
V_527 = V_536 ;
break;
case V_537 :
V_527 = V_538 ;
break;
case V_539 :
V_527 = V_540 ;
break;
case V_541 :
case V_542 :
V_527 = V_543 ;
break;
case V_544 :
V_527 = V_545 ;
break;
case V_546 :
V_527 = V_547 ;
break;
case V_548 :
case V_549 :
V_527 = V_550 ;
break;
case V_551 :
V_527 = V_552 ;
break;
case V_553 :
V_527 = V_554 ;
break;
default:
break;
}
return V_527 ;
}
static int
F_123 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_555 * V_121 ,
struct V_556 * V_123 )
{
struct V_21 V_90 ;
struct V_557 V_558 ;
int V_61 ;
memset ( & V_558 , 0 , sizeof( V_558 ) ) ;
V_558 . V_526 = F_122 ( V_121 -> V_526 ) ;
if ( V_558 . V_526 == V_528 ) {
F_34 ( V_2 ,
L_74 ,
V_121 -> V_526 ,
F_124 ( V_121 -> V_526 ) ) ;
return - V_69 ;
}
switch ( V_121 -> V_82 ) {
case V_559 :
V_558 . V_50 = V_121 -> V_560 ;
case V_561 :
break;
default:
F_34 ( V_2 , L_75 ,
V_121 -> V_82 ) ;
return - V_69 ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_121 -> V_82 ;
V_90 . V_81 = V_562 ;
V_90 . V_78 = & V_558 ;
V_90 . V_79 = sizeof( V_558 ) ;
V_90 . V_72 = V_90 . V_78 ;
V_90 . V_73 = V_90 . V_79 ;
F_7 ( V_2 ,
V_11 ,
L_76 ,
V_121 -> V_82 ,
V_121 -> V_526 ,
F_124 ( V_121 -> V_526 ) ,
F_53 ( V_90 . V_81 ,
V_563 ) ,
F_53 ( V_90 . V_81 ,
V_564 ) ,
V_121 -> V_560 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
return V_61 ;
V_123 -> V_66 = V_90 . V_66 ;
V_123 -> V_70 = V_90 . V_70 ;
V_123 -> V_565 = V_558 . V_50 ;
V_123 -> V_566 = V_558 . V_501 ;
V_123 -> V_567 = V_558 . V_568 ;
V_123 -> V_569 = V_558 . V_570 ;
V_123 -> V_571 = V_558 . V_571 ;
F_7 ( V_2 ,
V_11 ,
L_77 ,
F_53 ( V_123 -> V_70 ,
V_572 ) ,
F_53 ( V_123 -> V_70 ,
V_573 ) ,
V_123 -> V_565 ,
V_123 -> V_566 ,
V_123 -> V_567 ,
V_123 -> V_569 , V_123 -> V_571 ) ;
return 0 ;
}
int
F_125 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_525 V_526 ,
T_1 V_560 , T_1 * V_574 )
{
struct V_556 V_177 ;
struct V_555 V_178 ;
int V_61 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_82 = V_559 ;
V_178 . V_526 = V_526 ;
V_178 . V_560 = V_560 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_123 ( V_2 , V_6 , & V_178 ,
& V_177 ) ;
if ( V_61 )
return V_61 ;
* V_574 = V_177 . V_66 ;
return 0 ;
}
int
F_126 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_525 V_526 ,
T_1 * V_574 , T_1 * V_575 , T_1 * V_576 )
{
struct V_556 V_177 ;
struct V_555 V_178 ;
int V_61 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_82 = V_561 ;
V_178 . V_526 = V_526 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_123 ( V_2 , V_6 , & V_178 ,
& V_177 ) ;
if ( V_61 )
return V_61 ;
* V_574 = V_177 . V_66 ;
if ( * V_574 == V_577 ) {
* V_575 = V_177 . V_565 ;
* V_576 = V_177 . V_566 ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_66 , V_70 ;
return F_45 ( V_2 , V_6 , V_578 , 0 ,
& V_66 , & V_70 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_81 , T_1 * V_574 , T_1 * V_579 )
{
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_580 , V_81 ,
V_574 , V_579 ) ;
if ( V_61 )
return V_61 ;
if ( * V_574 == V_581 ) {
F_57 ( V_2 ,
L_78 ) ;
return - V_69 ;
}
if ( * V_579 == V_582 ) {
T_4 V_583 = F_53 ( V_81 , V_584 ) ;
F_29 ( V_2 ,
L_79 ,
V_81 , V_583 ) ;
return - V_69 ;
}
return V_61 ;
}
int
F_129 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_585 * V_176 )
{
T_1 V_81 = 0 , V_66 , V_70 ;
T_4 V_583 ;
int V_61 ;
switch ( V_176 -> V_586 ) {
case V_587 :
V_583 = V_588 ;
V_176 -> V_586 = 0 ;
break;
case V_589 :
V_583 = V_590 ;
V_176 -> V_586 = 0 ;
break;
default:
V_583 = V_591 ;
break;
}
F_52 ( V_81 , V_592 , V_176 -> V_593 ) ;
F_52 ( V_81 , V_584 , V_583 ) ;
F_52 ( V_81 , V_594 , V_176 -> V_586 ) ;
F_7 ( V_2 ,
V_11 ,
L_80 ,
V_81 , V_176 -> V_586 , V_583 , V_176 -> V_593 ) ;
V_61 = F_128 ( V_2 , V_6 , V_81 , & V_66 , & V_70 ) ;
if ( V_61 )
return V_61 ;
V_176 -> V_595 = F_53 ( V_70 , V_596 ) ;
V_583 = F_53 ( V_70 , V_597 ) ;
F_7 ( V_2 ,
V_11 ,
L_81 ,
V_70 , V_583 , V_176 -> V_595 ) ;
switch ( V_583 ) {
case V_598 :
V_176 -> V_599 = true ;
break;
case V_600 :
V_176 -> V_599 = false ;
break;
default:
F_29 ( V_2 ,
L_82 ,
V_70 , V_583 ) ;
return - V_69 ;
}
return 0 ;
}
int
F_130 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_585 * V_176 )
{
T_1 V_601 = 0 ;
int V_61 ;
do {
if ( V_601 ) {
if ( V_176 -> V_602 ) {
T_2 V_603 =
F_131 ( V_176 -> V_604 ,
1000 ) ;
F_100 ( V_603 ) ;
} else {
F_33 ( V_176 -> V_604 ) ;
}
}
V_61 = F_129 ( V_2 , V_6 , V_176 ) ;
if ( V_61 )
return V_61 ;
if ( V_176 -> V_599 )
break;
} while ( V_601 ++ < V_176 -> V_605 );
return 0 ;
}
int
F_132 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_606 * V_176 )
{
T_1 V_81 = 0 , V_66 , V_70 ;
T_4 V_583 ;
int V_61 ;
V_583 = V_176 -> V_607 ? V_608
: V_609 ;
F_52 ( V_81 , V_592 , V_176 -> V_593 ) ;
F_52 ( V_81 , V_584 , V_583 ) ;
F_7 ( V_2 , V_11 ,
L_83 ,
V_81 , V_583 , V_176 -> V_593 ) ;
V_61 = F_128 ( V_2 , V_6 , V_81 , & V_66 , & V_70 ) ;
if ( V_61 )
return V_61 ;
V_583 = F_53 ( V_70 , V_597 ) ;
F_7 ( V_2 , V_11 ,
L_84 ,
V_70 , V_583 ) ;
switch ( V_583 ) {
case V_610 :
F_57 ( V_2 ,
L_85 ,
V_176 -> V_593 ) ;
case V_611 :
V_176 -> V_612 = true ;
break;
case V_613 :
V_176 -> V_612 = false ;
break;
default:
F_29 ( V_2 ,
L_86 ,
V_70 , V_583 ) ;
return - V_69 ;
}
return 0 ;
}
void F_133 ( struct V_585 * V_614 ,
struct V_606 * V_615 ,
enum V_616
V_593 , bool V_617 )
{
if ( V_614 ) {
memset ( V_614 , 0 , sizeof( * V_614 ) ) ;
if ( V_617 ) {
V_614 -> V_586 = V_589 ;
} else {
V_614 -> V_605 = V_618 ;
V_614 -> V_604 =
V_619 ;
V_614 -> V_602 = true ;
}
V_614 -> V_593 = V_593 ;
}
if ( V_615 ) {
memset ( V_615 , 0 , sizeof( * V_615 ) ) ;
V_615 -> V_593 = V_593 ;
}
}
