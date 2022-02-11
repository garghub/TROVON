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
V_2 -> V_3 = NULL ;
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
if ( ! V_34 -> V_17 || ! V_34 -> V_31 )
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
struct V_5 * V_6 ,
struct V_225 * V_226 )
{
T_1 V_227 , V_228 ;
V_226 -> V_229 = 0 ;
V_226 -> V_230 = 0 ;
V_227 = F_4 ( V_2 ,
V_6 ,
V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_227 ) ) ;
V_226 -> V_231 = ! ! ( V_227 & V_232 ) ;
V_228 = ( V_227 & V_233 ) >> V_234 ;
if ( V_228 & V_235 )
V_226 -> V_229 |= V_236 ;
if ( V_228 & V_237 )
V_226 -> V_229 |= V_238 ;
V_228 = ( V_227 & V_239 ) >> V_240 ;
if ( V_228 & V_235 )
V_226 -> V_230 |= V_236 ;
if ( V_228 & V_237 )
V_226 -> V_230 |= V_238 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_5 * V_6 , bool V_241 )
{
struct V_225 * V_226 ;
T_4 V_242 , V_243 ;
T_1 V_244 = 0 ;
F_20 ( & V_2 -> V_3 -> V_53 ) ;
V_226 = & V_2 -> V_3 -> V_245 ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
if ( ! V_241 ) {
V_244 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_246 ) ) ;
F_7 ( V_2 , ( V_247 | V_11 ) ,
L_36 ,
V_244 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_246 ) ) ) ;
} else {
F_7 ( V_2 , V_247 ,
L_37 ) ;
goto V_26;
}
if ( V_2 -> V_248 )
V_226 -> V_249 = ! ! ( V_244 & V_250 ) ;
else
V_226 -> V_249 = false ;
V_226 -> V_251 = true ;
switch ( ( V_244 & V_252 ) ) {
case V_253 :
V_226 -> V_254 = 100000 ;
break;
case V_255 :
V_226 -> V_254 = 50000 ;
break;
case V_256 :
V_226 -> V_254 = 40000 ;
break;
case V_257 :
V_226 -> V_254 = 25000 ;
break;
case V_258 :
V_226 -> V_254 = 20000 ;
break;
case V_259 :
V_226 -> V_254 = 10000 ;
break;
case V_260 :
V_226 -> V_251 = false ;
case V_261 :
V_226 -> V_254 = 1000 ;
break;
default:
V_226 -> V_254 = 0 ;
}
if ( V_226 -> V_249 && V_226 -> V_254 )
V_226 -> V_262 = V_226 -> V_254 ;
else
V_226 -> V_262 = 0 ;
V_242 = V_2 -> V_3 -> V_263 . V_264 ;
V_243 = V_2 -> V_3 -> V_263 . V_265 ;
F_70 ( V_2 , V_6 , V_226 , V_242 ) ;
F_71 ( V_2 , V_6 , V_226 , V_243 ) ;
F_72 ( V_2 -> V_145 , V_6 ,
V_226 -> V_266 ) ;
V_226 -> V_267 = ! ! ( V_244 & V_268 ) ;
V_226 -> V_269 = ! ! ( V_244 &
V_270 ) ;
V_226 -> V_271 = ! ! ( V_244 &
V_272 ) ;
V_226 -> V_273 = ! ! ( V_244 & V_274 ) ;
V_226 -> V_275 |=
( V_244 & V_276 ) ?
V_277 : 0 ;
V_226 -> V_275 |=
( V_244 & V_278 ) ?
V_279 : 0 ;
V_226 -> V_275 |=
( V_244 & V_280 ) ?
V_281 : 0 ;
V_226 -> V_275 |=
( V_244 & V_282 ) ?
V_283 : 0 ;
V_226 -> V_275 |=
( V_244 & V_284 ) ?
V_285 : 0 ;
V_226 -> V_275 |=
( V_244 & V_286 ) ?
V_287 : 0 ;
V_226 -> V_275 |=
( V_244 & V_288 ) ?
V_289 : 0 ;
V_226 -> V_275 |=
( V_244 & V_290 ) ?
V_291 : 0 ;
V_226 -> V_292 =
! ! ( V_244 & V_293 ) ;
V_226 -> V_294 =
! ! ( V_244 & V_295 ) ;
switch ( V_244 & V_296 ) {
case V_297 :
V_226 -> V_298 = V_299 ;
break;
case V_300 :
V_226 -> V_298 = V_301 ;
break;
case V_302 :
V_226 -> V_298 = V_303 ;
break;
default:
V_226 -> V_298 = 0 ;
}
V_226 -> V_304 = ! ! ( V_244 & V_305 ) ;
if ( V_2 -> V_3 -> V_306 & V_307 )
F_68 ( V_2 , V_6 , V_226 ) ;
F_73 ( V_2 ) ;
V_26:
F_22 ( & V_2 -> V_3 -> V_53 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_308 )
{
struct V_309 * V_310 = & V_2 -> V_3 -> V_311 ;
struct V_21 V_90 ;
struct V_312 V_313 ;
int V_61 = 0 ;
T_1 V_82 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_82 = V_308 ? V_314 : V_315 ;
if ( ! V_310 -> V_254 . V_316 )
V_313 . V_254 = V_310 -> V_254 . V_317 ;
V_313 . V_318 |= ( V_310 -> V_318 . V_316 ) ? V_319 : 0 ;
V_313 . V_318 |= ( V_310 -> V_318 . V_320 ) ? V_321 : 0 ;
V_313 . V_318 |= ( V_310 -> V_318 . V_322 ) ? V_323 : 0 ;
V_313 . V_324 = V_310 -> V_254 . V_325 ;
V_313 . V_326 = V_310 -> V_326 ;
if ( V_2 -> V_3 -> V_306 & V_307 ) {
if ( V_310 -> V_327 . V_328 )
V_313 . V_329 |= V_330 ;
if ( V_310 -> V_327 . V_331 )
V_313 . V_329 |= V_332 ;
if ( V_310 -> V_327 . V_333 & V_236 )
V_313 . V_329 |= V_334 ;
if ( V_310 -> V_327 . V_333 & V_238 )
V_313 . V_329 |= V_335 ;
V_313 . V_329 |= ( V_310 -> V_327 . V_336 <<
V_337 ) &
V_338 ;
}
V_2 -> V_248 = V_308 ;
if ( V_308 ) {
F_7 ( V_2 , V_247 ,
L_38 ,
V_313 . V_254 ,
V_313 . V_318 ,
V_313 . V_324 ,
V_313 . V_326 ,
V_313 . V_339 ) ;
} else {
F_7 ( V_2 , V_247 ,
L_39 ) ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_82 ;
V_90 . V_78 = & V_313 ;
V_90 . V_79 = sizeof( V_313 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 ) {
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
F_69 ( V_2 , V_6 , ! V_308 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_340 type )
{
enum V_341 V_342 ;
union V_343 V_344 ;
struct V_21 V_90 ;
T_1 V_345 ;
switch ( type ) {
case V_346 :
V_342 = V_347 ;
V_345 = V_348 ;
break;
case V_349 :
V_342 = V_350 ;
V_345 = V_351 ;
break;
case V_352 :
V_342 = V_353 ;
V_345 = V_354 ;
break;
case V_355 :
V_342 = V_356 ;
V_345 = V_357 ;
break;
default:
F_29 ( V_2 , L_41 , type ) ;
return;
}
F_76 ( V_2 -> V_145 , V_342 , & V_344 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_358 ;
V_90 . V_81 = V_345 ;
V_90 . V_78 = & V_344 ;
V_90 . V_79 = sizeof( V_344 ) ;
F_44 ( V_2 , V_6 , & V_90 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_217 * V_359 )
{
struct V_360 * V_34 ;
V_34 = & V_2 -> V_3 -> V_263 ;
V_34 -> V_265 = ( V_359 -> V_361 &
V_362 ) >>
V_363 ;
if ( V_34 -> V_265 < 1 || V_34 -> V_265 > 100 ) {
F_57 ( V_2 ,
L_42 ,
V_34 -> V_265 ) ;
V_34 -> V_265 = 1 ;
}
V_34 -> V_264 = ( V_359 -> V_361 &
V_364 ) >>
V_365 ;
if ( V_34 -> V_264 < 1 || V_34 -> V_264 > 100 ) {
F_57 ( V_2 ,
L_43 ,
V_34 -> V_264 ) ;
V_34 -> V_264 = 100 ;
}
}
static T_1 F_78 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_217 * V_366 , int V_367 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_213 ) ;
T_1 V_204 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_215 = F_5 ( V_204 , V_367 ) ;
T_1 V_15 , V_50 ;
memset ( V_366 , 0 , sizeof( * V_366 ) ) ;
V_50 = F_79 ( T_1 , sizeof( * V_366 ) , F_80 ( V_204 ) ) ;
for ( V_15 = 0 ; V_15 < V_50 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_366 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_215 + ( V_15 << 2 ) ) ;
return V_50 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_360 * V_34 ;
struct V_217 V_368 ;
T_1 V_105 = 0 , V_81 = 0 ;
F_78 ( V_2 , V_6 , & V_368 , F_24 ( V_2 ) ) ;
F_77 ( V_2 , & V_368 ) ;
V_34 = & V_2 -> V_3 -> V_263 ;
F_82 ( V_2 -> V_145 , V_34 -> V_265 ) ;
F_83 ( V_2 -> V_145 , V_34 -> V_264 ) ;
F_45 ( V_2 , V_6 , V_369 , 0 , & V_105 ,
& V_81 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_217 V_368 ;
T_1 V_105 = 0 , V_81 = 0 ;
F_78 ( V_2 , V_6 , & V_368 , F_24 ( V_2 ) ) ;
V_2 -> V_3 -> V_263 . V_370 = ( T_2 ) V_368 . V_371 &
V_372 ;
V_2 -> V_373 . V_370 = V_2 -> V_3 -> V_263 . V_370 ;
if ( ( V_2 -> V_373 . V_374 & F_85 ( V_375 ) ) &&
( V_2 -> V_373 . V_370 != V_376 ) ) {
F_65 ( V_2 , V_6 ,
V_377 , V_2 -> V_373 . V_370 ) ;
F_86 ( V_2 ) ;
}
F_45 ( V_2 , V_6 , V_378 , 0 ,
& V_105 , & V_81 ) ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_33 * V_379 = V_2 -> V_3 ;
int V_61 = 0 ;
bool V_380 = false ;
T_2 V_15 ;
F_7 ( V_2 , V_11 , L_44 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_379 -> V_13 ; V_15 ++ ) {
if ( V_379 -> V_17 [ V_15 ] == V_379 -> V_31 [ V_15 ] )
continue;
V_380 = true ;
F_7 ( V_2 , V_247 ,
L_45 ,
V_15 , V_379 -> V_31 [ V_15 ] , V_379 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_381 :
F_69 ( V_2 , V_6 , false ) ;
break;
case V_382 :
F_60 ( V_2 , V_6 ) ;
break;
case V_383 :
F_88 ( V_2 , V_6 ,
V_384 ) ;
break;
case V_385 :
F_88 ( V_2 , V_6 ,
V_386 ) ;
break;
case V_387 :
F_88 ( V_2 , V_6 ,
V_388 ) ;
break;
case V_389 :
F_66 ( V_2 , V_6 ) ;
break;
case V_346 :
case V_349 :
case V_352 :
case V_355 :
F_75 ( V_2 , V_6 , V_15 ) ;
break;
case V_390 :
F_81 ( V_2 , V_6 ) ;
break;
case V_391 :
F_84 ( V_2 , V_6 ) ;
break;
break;
default:
F_57 ( V_2 , L_46 , V_15 ) ;
V_61 = - V_69 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_379 -> V_13 ) ; V_15 ++ ) {
V_19 V_228 = F_89 ( ( ( T_1 * ) V_379 -> V_17 ) [ V_15 ] ) ;
F_65 ( V_2 , V_6 ,
V_379 -> V_16 + sizeof( T_1 ) +
F_9 ( V_379 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_228 ) ;
}
if ( ! V_380 ) {
F_29 ( V_2 ,
L_47 ) ;
V_61 = - V_69 ;
}
memcpy ( V_379 -> V_31 , V_379 -> V_17 , V_379 -> V_13 ) ;
return V_61 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_392 , T_1 * V_393 )
{
T_1 V_394 ;
if ( F_91 ( V_2 -> V_145 ) ) {
if ( V_2 -> V_395 ) {
struct V_396 * V_397 ;
V_397 = & V_2 -> V_395 -> V_398 ;
* V_392 = V_397 -> V_399 . V_400 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_210 ,
L_48 ) ;
return - V_69 ;
}
}
V_394 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_401 ) ) ;
* V_392 =
F_4 ( V_2 , V_6 ,
F_5 ( V_394 ,
0 ) + F_39 ( struct V_402 , V_400 ) ) ;
if ( V_393 != NULL ) {
* V_393 = F_4 ( V_2 , V_6 ,
F_5 ( V_394 , 0 ) +
F_39 ( struct V_402 ,
V_403 ) ) ;
}
return 0 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_404 )
{
T_1 V_405 , V_406 , V_407 ;
if ( F_91 ( V_2 -> V_145 ) )
return - V_69 ;
V_405 = F_4 ( V_2 , V_6 , V_408 ) ;
if ( ! V_405 ) {
F_29 ( V_2 , L_49 ) ;
return - V_69 ;
}
V_406 = F_4 ( V_2 , V_6 , V_405 + 4 ) ;
V_407 = V_409 + V_406 +
F_39 ( struct V_410 , V_411 ) +
F_39 ( struct V_412 , V_413 ) ;
* V_404 = F_4 ( V_2 , V_6 ,
V_407 ) &
( V_414 |
V_415 |
V_416 ) ;
return 0 ;
}
int F_93 ( struct V_417 * V_145 , T_1 * V_418 )
{
struct V_1 * V_2 = & V_145 -> V_419 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_91 ( V_145 ) )
return - V_69 ;
if ( ! F_1 ( V_2 ) ) {
F_29 ( V_2 , L_12 ) ;
return - V_87 ;
}
* V_418 = V_420 ;
V_6 = F_94 ( V_2 ) ;
if ( ! V_6 )
return - V_87 ;
* V_418 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_39 ( struct V_220 , V_421 ) ) ;
F_95 ( V_2 , V_6 ) ;
return 0 ;
}
static void
F_96 ( struct V_1 * V_2 ,
enum V_422 * V_423 )
{
if ( F_97 ( V_424 , & V_2 -> V_373 . V_425 ) )
* V_423 = V_426 ;
else
* V_423 = V_427 ;
F_7 ( V_2 , V_428 ,
L_50 ,
( T_1 ) * V_423 ) ;
}
static int
F_98 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_422 * V_423 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_429 , 0 , & V_105 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( V_105 != V_430 ) {
F_7 ( V_2 , V_428 ,
L_51 ,
V_105 ) ;
return - V_69 ;
}
switch ( V_81 ) {
case V_431 :
* V_423 = V_427 ;
break;
case V_432 :
* V_423 = V_426 ;
break;
case V_433 :
F_29 ( V_2 ,
L_52 ) ;
* V_423 = V_426 ;
break;
case V_434 :
default:
F_29 ( V_2 ,
L_53 ,
V_81 ) ;
return - V_69 ;
}
F_7 ( V_2 ,
V_428 ,
L_54 ,
( T_1 ) * V_423 , V_105 , V_81 ) ;
return 0 ;
}
static int
F_99 ( struct V_1 * V_2 ,
struct V_217 * V_34 ,
struct V_5 * V_6 ,
enum V_422 * V_423 )
{
int V_61 = 0 ;
switch ( V_34 -> V_361 & V_435 ) {
case V_436 :
if ( ! F_50 ( V_112 ) )
* V_423 = V_427 ;
else if ( F_98 ( V_2 , V_6 , V_423 ) )
F_96 ( V_2 , V_423 ) ;
break;
case V_437 :
* V_423 = V_438 ;
break;
case V_439 :
* V_423 = V_440 ;
break;
case V_441 :
F_29 ( V_2 , L_55 ) ;
default:
V_61 = - V_69 ;
}
return V_61 ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_360 * V_379 ;
struct V_217 V_368 ;
F_78 ( V_2 , V_6 , & V_368 , F_24 ( V_2 ) ) ;
V_379 = & V_2 -> V_3 -> V_263 ;
V_379 -> V_442 = ( V_368 . V_361 &
V_443 ) ? 1 : 0 ;
if ( F_99 ( V_2 , & V_368 , V_6 ,
& V_379 -> V_444 ) ) {
F_34 ( V_2 , L_56 ,
( T_1 ) ( V_368 . V_361 & V_435 ) ) ;
return - V_69 ;
}
F_77 ( V_2 , & V_368 ) ;
if ( V_368 . V_200 || V_368 . V_201 ) {
V_379 -> V_445 [ 0 ] = ( T_4 ) ( V_368 . V_200 >> 8 ) ;
V_379 -> V_445 [ 1 ] = ( T_4 ) ( V_368 . V_200 ) ;
V_379 -> V_445 [ 2 ] = ( T_4 ) ( V_368 . V_201 >> 24 ) ;
V_379 -> V_445 [ 3 ] = ( T_4 ) ( V_368 . V_201 >> 16 ) ;
V_379 -> V_445 [ 4 ] = ( T_4 ) ( V_368 . V_201 >> 8 ) ;
V_379 -> V_445 [ 5 ] = ( T_4 ) ( V_368 . V_201 ) ;
memcpy ( & V_2 -> V_145 -> V_197 , V_379 -> V_445 , V_446 ) ;
} else {
F_29 ( V_2 , L_57 ) ;
}
V_379 -> V_447 = ( V_448 ) V_368 . V_449 |
( ( ( V_448 ) V_368 . V_450 ) << 32 ) ;
V_379 -> V_451 = ( V_448 ) V_368 . V_452 |
( ( ( V_448 ) V_368 . V_453 ) << 32 ) ;
V_379 -> V_370 = ( T_2 ) ( V_368 . V_371 & V_372 ) ;
V_379 -> V_454 = ( T_2 ) V_368 . V_455 ;
V_2 -> V_373 . V_456 = V_457 ;
V_2 -> V_145 -> V_188 = ( T_4 ) V_193 ;
if ( F_1 ( V_2 ) ) {
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_458 , 0 , & V_105 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( V_105 == V_459 )
V_2 -> V_373 . V_456 = V_460 ;
}
F_7 ( V_2 , ( V_11 | V_428 ) ,
L_58 ,
V_379 -> V_442 , V_379 -> V_444 ,
V_379 -> V_265 , V_379 -> V_264 ,
V_379 -> V_445 [ 0 ] , V_379 -> V_445 [ 1 ] , V_379 -> V_445 [ 2 ] ,
V_379 -> V_445 [ 3 ] , V_379 -> V_445 [ 4 ] , V_379 -> V_445 [ 5 ] ,
V_379 -> V_447 , V_379 -> V_451 ,
V_379 -> V_370 , ( T_4 ) V_2 -> V_373 . V_456 ) ;
return 0 ;
}
struct V_309
* F_101 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_311 ;
}
struct V_225
* F_102 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_245 ;
}
struct V_461
* F_103 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_462 ;
}
int F_104 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 ,
V_463 , 1000 , & V_105 , & V_81 ) ;
F_105 ( 1020 ) ;
return V_61 ;
}
int F_106 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_464 )
{
T_1 V_465 ;
if ( F_91 ( V_2 -> V_145 ) )
return - V_69 ;
V_465 = F_4 ( V_2 , V_6 , V_466 ) ;
V_465 = ( V_465 & V_467 ) >>
V_468 ;
V_465 = ( 1 << ( V_465 + V_469 ) ) ;
* V_464 = V_465 ;
return 0 ;
}
static int
F_107 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 V_470 , T_4 V_471 )
{
T_1 V_105 = 0 , V_81 = 0 , V_472 = 0 ;
int V_61 ;
if ( ! F_108 ( V_2 ) )
return 0 ;
V_471 *= V_2 -> V_145 -> V_473 ;
V_81 |= ( V_470 << V_474 ) &
V_475 ;
V_81 |= ( V_471 << V_476 ) &
V_477 ;
V_61 = F_45 ( V_2 , V_6 , V_478 , V_81 ,
& V_105 , & V_472 ) ;
if ( V_105 != V_479 ) {
F_29 ( V_2 , L_59 , V_470 ) ;
V_61 = - V_69 ;
} else {
F_7 ( V_2 , V_210 ,
L_60 ,
V_471 , V_470 ) ;
}
return V_61 ;
}
static int
F_109 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 V_471 )
{
T_1 V_105 = 0 , V_81 = V_471 , V_472 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_480 ,
V_81 , & V_105 , & V_472 ) ;
if ( V_105 != V_481 ) {
F_29 ( V_2 , L_61 ) ;
V_61 = - V_69 ;
} else {
F_7 ( V_2 , V_210 ,
L_62 , V_471 ) ;
}
return V_61 ;
}
int F_110 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 V_470 , T_4 V_471 )
{
if ( F_111 ( V_2 -> V_145 ) )
return F_107 ( V_2 , V_6 , V_470 , V_471 ) ;
else
return F_109 ( V_2 , V_6 , V_471 ) ;
}
int
F_112 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_482 * V_483 )
{
struct V_21 V_90 ;
struct V_484 V_485 ;
V_19 V_228 ;
T_1 V_15 ;
int V_61 ;
memset ( & V_485 , 0 , sizeof( V_485 ) ) ;
V_485 . V_486 = V_483 -> V_486 ;
for ( V_15 = 0 ; V_15 < ( V_487 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_228 = F_89 ( * ( ( T_1 * ) & V_483 -> V_488 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_485 . V_488 [ V_15 * sizeof( T_1 ) ] = V_228 ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_489 ;
V_90 . V_78 = & V_485 ;
V_90 . V_79 = sizeof( V_485 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_113 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_490 , 0 , & V_105 ,
& V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_114 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_491 , V_492 ;
F_65 ( V_2 , V_6 , V_493 , 0xffffffff ) ;
V_491 = F_4 ( V_2 , V_6 , V_494 ) ;
V_491 &= ~ V_495 ;
F_65 ( V_2 , V_6 , V_494 , V_491 ) ;
V_492 = F_4 ( V_2 , V_6 , V_494 ) ;
return ( V_492 & V_495 ) ? - V_64 : 0 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_496 V_497 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_497 ) {
case V_498 :
V_80 = V_499 ;
break;
case V_500 :
V_80 = V_501 ;
break;
case V_502 :
V_80 = V_503 ;
break;
default:
F_29 ( V_2 , L_63 , V_497 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_504 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_40 ) ;
return V_61 ;
}
int F_116 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_505 V_506 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_506 ) {
case V_507 :
V_80 = V_508 ;
break;
case V_509 :
V_80 = V_510 ;
break;
case V_511 :
V_80 = V_512 ;
break;
default:
F_29 ( V_2 , L_64 , V_506 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_513 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_65 ) ;
return V_61 ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_454 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
V_80 = ( T_1 ) V_454 << V_514 ;
V_61 = F_45 ( V_2 , V_6 , V_515 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_66 , V_61 ) ;
return V_61 ;
}
int F_118 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_4 * V_445 )
{
struct V_21 V_90 ;
T_1 V_516 [ 2 ] ;
int V_61 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_517 ;
V_90 . V_81 = V_518 <<
V_519 ;
V_90 . V_81 |= F_24 ( V_2 ) ;
V_516 [ 0 ] = V_445 [ 0 ] << 24 | V_445 [ 1 ] << 16 | V_445 [ 2 ] << 8 | V_445 [ 3 ] ;
V_516 [ 1 ] = V_445 [ 4 ] << 24 | V_445 [ 5 ] << 16 ;
V_90 . V_78 = ( T_4 * ) V_516 ;
V_90 . V_79 = 8 ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
F_34 ( V_2 , L_67 , V_61 ) ;
memcpy ( V_2 -> V_145 -> V_197 , V_445 , V_446 ) ;
return V_61 ;
}
int F_119 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_520 V_521 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
if ( V_2 -> V_373 . V_456 == V_457 ) {
F_7 ( V_2 , V_11 ,
L_68 ) ;
return - V_69 ;
}
switch ( V_521 ) {
case V_193 :
V_80 = V_522 ;
break;
case V_189 :
V_80 = V_523 ;
break;
case V_191 :
V_80 = V_524 ;
break;
default:
F_34 ( V_2 , L_69 , V_521 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_525 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_70 , V_61 ) ;
V_2 -> V_145 -> V_188 = ( T_4 ) V_521 ;
return V_61 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_526 V_527 )
{
T_1 V_105 = 0 , V_81 = 0 ;
T_1 V_80 ;
int V_61 ;
switch ( V_527 ) {
case V_528 :
V_80 = V_529 ;
break;
case V_530 :
V_80 = V_531 ;
break;
case V_532 :
V_80 = V_533 ;
break;
default:
F_34 ( V_2 , L_71 , V_527 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_534 ,
V_80 , & V_105 , & V_81 ) ;
if ( V_61 )
F_34 ( V_2 , L_72 , V_61 ) ;
return V_61 ;
}
int F_121 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_535 V_536 )
{
T_1 V_105 = 0 , V_81 = 0 , V_80 ;
int V_61 ;
switch ( V_536 ) {
case V_537 :
V_80 = V_538 ;
break;
case V_539 :
V_80 = V_540 ;
break;
case V_541 :
V_80 = V_542 ;
break;
default:
F_29 ( V_2 , L_73 , V_536 ) ;
return - V_69 ;
}
V_61 = F_45 ( V_2 , V_6 , V_543 ,
V_80 , & V_105 , & V_81 ) ;
return V_61 ;
}
int F_122 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_544 )
{
T_1 V_105 = 0 , V_81 = 0 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_545 ,
V_544 , & V_105 , & V_81 ) ;
if ( V_61 ) {
F_34 ( V_2 ,
L_74 ) ;
} else if ( V_105 != V_430 ) {
F_34 ( V_2 ,
L_75 ) ;
V_61 = - V_69 ;
}
return V_61 ;
}
int F_123 ( struct V_417 * V_145 , T_1 V_7 , T_4 * V_546 , T_1 V_547 )
{
T_1 V_548 = V_547 , V_549 = 0 , V_550 , V_551 = 0 ;
struct V_1 * V_2 = F_124 ( V_145 ) ;
T_1 V_105 = 0 , V_552 = 0 ;
struct V_5 * V_6 ;
int V_61 = 0 ;
V_6 = F_94 ( V_2 ) ;
if ( ! V_6 )
return - V_87 ;
while ( V_548 > 0 ) {
V_550 = F_79 ( T_1 , V_548 , V_94 ) ;
V_61 = F_46 ( V_2 , V_6 ,
V_553 ,
V_7 + V_549 +
( V_550 <<
V_554 ) ,
& V_105 , & V_552 ,
& V_551 ,
( T_1 * ) ( V_546 + V_549 ) ) ;
if ( V_61 || ( V_105 != V_555 ) ) {
F_29 ( V_145 , L_76 , V_61 ) ;
break;
}
if ( V_548 % 0x1000 <
( V_548 - V_551 ) % 0x1000 )
F_125 ( 1000 , 2000 ) ;
V_549 += V_551 ;
V_548 -= V_551 ;
}
V_145 -> V_556 = V_105 ;
F_95 ( V_2 , V_6 ) ;
return V_61 ;
}
int F_126 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_80 = 0 , V_557 , V_81 ;
int V_61 = 0 ;
V_80 = ( V_558 <<
V_559 ) ;
V_61 = F_45 ( V_2 , V_6 , V_560 ,
V_80 , & V_557 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_557 & V_84 ) != V_430 ) ||
( V_81 != V_561 ) )
V_61 = - V_64 ;
return V_61 ;
}
int F_127 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_80 , V_557 , V_81 ;
int V_61 = 0 ;
V_80 = ( V_562 <<
V_559 ) ;
V_61 = F_45 ( V_2 , V_6 , V_560 ,
V_80 , & V_557 , & V_81 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_557 & V_84 ) != V_430 ) ||
( V_81 != V_561 ) )
V_61 = - V_64 ;
return V_61 ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_563 )
{
T_1 V_80 = 0 , V_557 ;
int V_61 = 0 ;
V_80 = ( V_564 <<
V_559 ) ;
V_61 = F_45 ( V_2 , V_6 , V_560 ,
V_80 , & V_557 , V_563 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_557 & V_84 ) != V_430 ) )
V_61 = - V_69 ;
return V_61 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_565 * V_566 ,
T_1 V_567 )
{
T_1 V_568 = 0 , V_81 , V_105 = 0 , V_552 = 0 ;
int V_61 ;
V_81 = V_569 <<
V_559 ;
V_81 |= V_567 << V_570 ;
V_61 = F_46 ( V_2 , V_6 ,
V_560 , V_81 ,
& V_105 , & V_552 ,
& V_568 ,
( T_1 * ) V_566 ) ;
if ( V_61 )
return V_61 ;
if ( ( ( V_105 & V_84 ) != V_430 ) ||
( V_566 -> V_571 != 1 ) )
V_61 = - V_69 ;
return V_61 ;
}
static int
F_130 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_572 V_573 ,
struct V_574 * V_566 )
{
struct V_565 V_575 ;
enum V_576 type ;
T_1 V_563 , V_15 ;
int V_61 ;
switch ( V_573 ) {
case V_577 :
type = V_578 ;
break;
case V_579 :
type = V_580 ;
break;
default:
F_29 ( V_2 , L_77 ,
V_573 ) ;
return - V_69 ;
}
V_61 = F_128 ( V_2 , V_6 , & V_563 ) ;
if ( V_61 || ! V_563 )
return - V_69 ;
for ( V_15 = 0 ; V_15 < V_563 ; V_15 ++ ) {
V_61 = F_129 ( V_2 , V_6 ,
& V_575 , V_15 ) ;
if ( V_61 )
return V_61 ;
if ( type == V_575 . V_581 )
break;
}
if ( V_15 == V_563 ) {
F_7 ( V_2 , V_582 ,
L_78 ,
V_573 ) ;
return - V_69 ;
}
V_566 -> V_583 = V_575 . V_584 ;
V_566 -> V_12 = V_575 . V_547 ;
return 0 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_572 V_573 ,
T_4 * V_585 , T_1 V_586 )
{
struct V_574 V_587 ;
int V_61 ;
memset ( V_585 , 0 , V_586 ) ;
V_61 = F_130 ( V_2 , V_6 , V_573 , & V_587 ) ;
if ( V_61 )
return V_61 ;
if ( V_587 . V_12 <= 4 ) {
F_7 ( V_2 , V_582 ,
L_79 ,
V_573 , V_587 . V_12 ) ;
return - V_69 ;
}
V_587 . V_12 -= 4 ;
if ( V_587 . V_12 > V_586 ) {
F_7 ( V_2 ,
V_582 ,
L_80 ,
V_573 , V_587 . V_12 , V_586 ) ;
return - V_54 ;
}
return F_123 ( V_2 -> V_145 , V_587 . V_583 ,
V_585 , V_587 . V_12 ) ;
}
static enum V_588 F_132 ( enum V_589 V_590 )
{
enum V_588 V_591 = V_592 ;
switch ( V_590 ) {
case V_593 :
V_591 = V_594 ;
break;
case V_595 :
V_591 = V_596 ;
break;
case V_597 :
V_591 = V_598 ;
break;
case V_599 :
V_591 = V_600 ;
break;
case V_601 :
V_591 = V_602 ;
break;
case V_603 :
V_591 = V_604 ;
break;
case V_605 :
case V_606 :
V_591 = V_607 ;
break;
case V_608 :
V_591 = V_609 ;
break;
case V_610 :
V_591 = V_611 ;
break;
case V_612 :
case V_613 :
V_591 = V_614 ;
break;
case V_615 :
V_591 = V_616 ;
break;
case V_617 :
V_591 = V_618 ;
break;
default:
break;
}
return V_591 ;
}
static int
F_133 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_619 * V_121 ,
struct V_620 * V_123 )
{
struct V_21 V_90 ;
struct V_621 V_622 ;
int V_61 ;
memset ( & V_622 , 0 , sizeof( V_622 ) ) ;
V_622 . V_590 = F_132 ( V_121 -> V_590 ) ;
if ( V_622 . V_590 == V_592 ) {
F_34 ( V_2 ,
L_81 ,
V_121 -> V_590 ,
F_134 ( V_121 -> V_590 ) ) ;
return - V_69 ;
}
switch ( V_121 -> V_82 ) {
case V_623 :
V_622 . V_50 = V_121 -> V_624 ;
case V_625 :
break;
default:
F_34 ( V_2 , L_82 ,
V_121 -> V_82 ) ;
return - V_69 ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_82 = V_121 -> V_82 ;
V_90 . V_81 = V_626 ;
V_90 . V_78 = & V_622 ;
V_90 . V_79 = sizeof( V_622 ) ;
V_90 . V_72 = V_90 . V_78 ;
V_90 . V_73 = V_90 . V_79 ;
F_7 ( V_2 ,
V_11 ,
L_83 ,
V_121 -> V_82 ,
V_121 -> V_590 ,
F_134 ( V_121 -> V_590 ) ,
F_53 ( V_90 . V_81 ,
V_627 ) ,
F_53 ( V_90 . V_81 ,
V_628 ) ,
V_121 -> V_624 ) ;
V_61 = F_44 ( V_2 , V_6 , & V_90 ) ;
if ( V_61 )
return V_61 ;
V_123 -> V_66 = V_90 . V_66 ;
V_123 -> V_70 = V_90 . V_70 ;
V_123 -> V_629 = V_622 . V_50 ;
V_123 -> V_630 = V_622 . V_549 ;
V_123 -> V_631 = V_622 . V_632 ;
V_123 -> V_633 = V_622 . V_634 ;
V_123 -> V_635 = V_622 . V_635 ;
F_7 ( V_2 ,
V_11 ,
L_84 ,
F_53 ( V_123 -> V_70 ,
V_636 ) ,
F_53 ( V_123 -> V_70 ,
V_637 ) ,
V_123 -> V_629 ,
V_123 -> V_630 ,
V_123 -> V_631 ,
V_123 -> V_633 , V_123 -> V_635 ) ;
return 0 ;
}
int
F_135 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_589 V_590 ,
T_1 V_624 , T_1 * V_638 )
{
struct V_620 V_177 ;
struct V_619 V_178 ;
int V_61 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_82 = V_623 ;
V_178 . V_590 = V_590 ;
V_178 . V_624 = V_624 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_133 ( V_2 , V_6 , & V_178 ,
& V_177 ) ;
if ( V_61 )
return V_61 ;
* V_638 = V_177 . V_66 ;
return 0 ;
}
int
F_136 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_589 V_590 ,
T_1 * V_638 , T_1 * V_639 , T_1 * V_640 )
{
struct V_620 V_177 ;
struct V_619 V_178 ;
int V_61 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_82 = V_625 ;
V_178 . V_590 = V_590 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_61 = F_133 ( V_2 , V_6 , & V_178 ,
& V_177 ) ;
if ( V_61 )
return V_61 ;
* V_638 = V_177 . V_66 ;
if ( * V_638 == V_641 ) {
* V_639 = V_177 . V_629 ;
* V_640 = V_177 . V_630 ;
}
return 0 ;
}
int F_137 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_66 , V_70 ;
return F_45 ( V_2 , V_6 , V_642 , 0 ,
& V_66 , & V_70 ) ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_81 , T_1 * V_638 , T_1 * V_643 )
{
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_644 , V_81 ,
V_638 , V_643 ) ;
if ( V_61 )
return V_61 ;
if ( * V_638 == V_645 ) {
F_57 ( V_2 ,
L_85 ) ;
return - V_69 ;
}
if ( * V_643 == V_646 ) {
T_4 V_647 = F_53 ( V_81 , V_648 ) ;
F_29 ( V_2 ,
L_86 ,
V_81 , V_647 ) ;
return - V_69 ;
}
return V_61 ;
}
int
F_139 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_649 * V_176 )
{
T_1 V_81 = 0 , V_66 , V_70 ;
T_4 V_647 ;
int V_61 ;
switch ( V_176 -> V_650 ) {
case V_651 :
V_647 = V_652 ;
V_176 -> V_650 = 0 ;
break;
case V_653 :
V_647 = V_654 ;
V_176 -> V_650 = 0 ;
break;
default:
V_647 = V_655 ;
break;
}
F_52 ( V_81 , V_656 , V_176 -> V_657 ) ;
F_52 ( V_81 , V_648 , V_647 ) ;
F_52 ( V_81 , V_658 , V_176 -> V_650 ) ;
F_7 ( V_2 ,
V_11 ,
L_87 ,
V_81 , V_176 -> V_650 , V_647 , V_176 -> V_657 ) ;
V_61 = F_138 ( V_2 , V_6 , V_81 , & V_66 , & V_70 ) ;
if ( V_61 )
return V_61 ;
V_176 -> V_659 = F_53 ( V_70 , V_660 ) ;
V_647 = F_53 ( V_70 , V_661 ) ;
F_7 ( V_2 ,
V_11 ,
L_88 ,
V_70 , V_647 , V_176 -> V_659 ) ;
switch ( V_647 ) {
case V_662 :
V_176 -> V_663 = true ;
break;
case V_664 :
V_176 -> V_663 = false ;
break;
default:
F_29 ( V_2 ,
L_89 ,
V_70 , V_647 ) ;
return - V_69 ;
}
return 0 ;
}
int
F_140 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_649 * V_176 )
{
T_1 V_665 = 0 ;
int V_61 ;
do {
if ( V_665 ) {
if ( V_176 -> V_666 ) {
T_2 V_667 =
F_141 ( V_176 -> V_668 ,
1000 ) ;
F_105 ( V_667 ) ;
} else {
F_33 ( V_176 -> V_668 ) ;
}
}
V_61 = F_139 ( V_2 , V_6 , V_176 ) ;
if ( V_61 )
return V_61 ;
if ( V_176 -> V_663 )
break;
} while ( V_665 ++ < V_176 -> V_669 );
return 0 ;
}
int
F_142 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_670 * V_176 )
{
T_1 V_81 = 0 , V_66 , V_70 ;
T_4 V_647 ;
int V_61 ;
V_647 = V_176 -> V_671 ? V_672
: V_673 ;
F_52 ( V_81 , V_656 , V_176 -> V_657 ) ;
F_52 ( V_81 , V_648 , V_647 ) ;
F_7 ( V_2 , V_11 ,
L_90 ,
V_81 , V_647 , V_176 -> V_657 ) ;
V_61 = F_138 ( V_2 , V_6 , V_81 , & V_66 , & V_70 ) ;
if ( V_61 )
return V_61 ;
V_647 = F_53 ( V_70 , V_661 ) ;
F_7 ( V_2 , V_11 ,
L_91 ,
V_70 , V_647 ) ;
switch ( V_647 ) {
case V_674 :
F_57 ( V_2 ,
L_92 ,
V_176 -> V_657 ) ;
case V_675 :
V_176 -> V_676 = true ;
break;
case V_677 :
V_176 -> V_676 = false ;
break;
default:
F_29 ( V_2 ,
L_93 ,
V_70 , V_647 ) ;
return - V_69 ;
}
return 0 ;
}
void F_143 ( struct V_649 * V_678 ,
struct V_670 * V_679 ,
enum V_680
V_657 , bool V_681 )
{
if ( V_678 ) {
memset ( V_678 , 0 , sizeof( * V_678 ) ) ;
if ( V_681 ) {
V_678 -> V_650 = V_653 ;
} else {
V_678 -> V_669 = V_682 ;
V_678 -> V_668 =
V_683 ;
V_678 -> V_666 = true ;
}
V_678 -> V_657 = V_657 ;
}
if ( V_679 ) {
memset ( V_679 , 0 , sizeof( * V_679 ) ) ;
V_679 -> V_657 = V_657 ;
}
}
int F_144 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_66 ;
int V_61 ;
V_61 = F_45 ( V_2 , V_6 , V_684 ,
0 , & V_66 , & V_2 -> V_3 -> V_306 ) ;
if ( ! V_61 )
F_7 ( V_2 , ( V_11 | V_685 ) ,
L_94 ,
V_2 -> V_3 -> V_306 ) ;
return V_61 ;
}
int F_145 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_66 , V_70 , V_686 ;
V_686 = V_687 ;
return F_45 ( V_2 , V_6 , V_688 ,
V_686 , & V_66 , & V_70 ) ;
}
