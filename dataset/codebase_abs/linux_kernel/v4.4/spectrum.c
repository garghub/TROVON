static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
char * V_5 = F_2 ( V_2 , V_6 ) ;
memset ( V_5 , 0 , V_6 ) ;
F_3 ( V_5 , V_7 ) ;
F_4 ( V_5 , V_8 ) ;
F_5 ( V_5 , V_9 ) ;
F_6 ( V_5 , 0 ) ;
F_7 ( V_5 , 1 ) ;
F_8 ( V_5 , V_4 -> V_10 ) ;
F_9 ( V_5 , V_11 ) ;
}
static int F_10 ( struct V_12 * V_12 )
{
char V_13 [ V_14 ] ;
int V_15 ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_17 ) , V_13 ) ;
if ( V_15 )
return V_15 ;
F_13 ( V_13 , V_12 -> V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_19 ,
bool V_20 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_21 [ V_22 ] ;
F_15 ( V_21 , V_19 -> V_10 ,
V_20 ? V_23 :
V_24 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_25 ) , V_21 ) ;
}
static int F_17 ( struct V_19 * V_19 ,
bool * V_26 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_21 [ V_22 ] ;
T_1 V_27 ;
int V_15 ;
F_15 ( V_21 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_25 ) , V_21 ) ;
if ( V_15 )
return V_15 ;
V_27 = F_18 ( V_21 ) ;
* V_26 = V_27 == V_23 ? true : false ;
return 0 ;
}
static int F_19 ( struct V_12 * V_12 , T_2 V_28 )
{
char V_29 [ V_30 ] ;
int V_15 ;
F_20 ( V_29 , V_31 ,
V_32 + V_28 , 0 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_33 ) , V_29 ) ;
if ( V_15 )
return V_15 ;
F_21 ( V_28 , V_12 -> V_34 ) ;
return 0 ;
}
static void F_22 ( struct V_12 * V_12 , T_2 V_28 )
{
char V_29 [ V_30 ] ;
F_23 ( V_28 , V_12 -> V_34 ) ;
F_20 ( V_29 , V_35 ,
V_32 + V_28 , 0 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_33 ) , V_29 ) ;
}
static int F_24 ( struct V_19 * V_19 ,
unsigned char * V_36 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_37 [ V_38 ] ;
F_25 ( V_37 , true , V_19 -> V_10 ) ;
F_26 ( V_37 , V_36 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_39 ) , V_37 ) ;
}
static int F_27 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
unsigned char * V_36 = V_19 -> V_40 -> V_41 ;
F_28 ( V_36 , V_12 -> V_18 ) ;
V_36 [ V_42 - 1 ] += V_19 -> V_10 ;
return F_24 ( V_19 , V_36 ) ;
}
static int F_29 ( struct V_19 * V_19 ,
T_2 V_43 , enum V_44 V_45 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_46 ;
int V_15 ;
V_46 = F_30 ( V_47 , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
F_31 ( V_46 , V_19 -> V_10 ) ;
F_32 ( V_46 , V_43 , V_45 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_50 ) , V_46 ) ;
F_33 ( V_46 ) ;
return V_15 ;
}
static int F_34 ( struct V_19 * V_19 , T_2 V_51 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_52 [ V_53 ] ;
int V_54 ;
int V_15 ;
V_51 += V_6 + V_55 ;
F_35 ( V_52 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_56 ) , V_52 ) ;
if ( V_15 )
return V_15 ;
V_54 = F_36 ( V_52 ) ;
if ( V_51 > V_54 )
return - V_57 ;
F_35 ( V_52 , V_19 -> V_10 , V_51 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_56 ) , V_52 ) ;
}
static int F_37 ( struct V_19 * V_19 , T_1 V_58 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_59 [ V_60 ] ;
F_38 ( V_59 , V_58 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_61 ) , V_59 ) ;
}
static int F_39 ( struct V_19 * V_19 ,
bool V_62 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_63 [ V_64 ] ;
F_40 ( V_63 , V_19 -> V_10 , V_62 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_65 ) , V_63 ) ;
}
int F_41 ( struct V_19 * V_19 ,
enum V_66 V_67 , bool V_68 , T_2 V_69 ,
T_2 V_43 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_70 [ V_71 ] ;
F_42 ( V_70 , V_19 -> V_10 , V_67 , V_68 ,
V_69 , V_43 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_72 ) , V_70 ) ;
}
static int F_43 ( struct V_19 * V_19 ,
T_2 V_43 , bool V_73 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_74 ;
int V_15 ;
V_74 = F_30 ( V_75 , V_48 ) ;
if ( ! V_74 )
return - V_49 ;
F_44 ( V_74 , V_19 -> V_10 , V_43 , V_43 ,
V_73 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_76 ) , V_74 ) ;
F_33 ( V_74 ) ;
return V_15 ;
}
static int
F_45 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_77 [ V_78 ] ;
F_46 ( V_77 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_79 ) , V_77 ) ;
}
static int F_47 ( struct V_19 * V_19 ,
bool * V_80 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_81 [ V_82 ] ;
int V_15 ;
F_48 ( V_81 , V_19 -> V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_83 ) , V_81 ) ;
if ( V_15 )
return V_15 ;
* V_80 = F_49 ( V_81 ) ? true : false ;
return 0 ;
}
static int F_50 ( struct V_84 * V_40 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
int V_15 ;
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 )
return V_15 ;
F_52 ( V_40 ) ;
return 0 ;
}
static int F_53 ( struct V_84 * V_40 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
F_54 ( V_40 ) ;
return F_14 ( V_19 , false ) ;
}
static T_3 F_55 ( struct V_1 * V_2 ,
struct V_84 * V_40 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_85 * V_86 ;
const struct V_3 V_4 = {
. V_10 = V_19 -> V_10 ,
. V_87 = false ,
} ;
T_4 V_88 ;
int V_15 ;
if ( F_56 ( V_12 , & V_4 ) )
return V_89 ;
if ( F_57 ( F_58 ( V_2 ) < V_6 ) ) {
struct V_1 * V_90 = V_2 ;
V_2 = F_59 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_60 ( V_19 -> V_86 -> V_91 ) ;
F_61 ( V_90 ) ;
return V_92 ;
}
}
if ( F_62 ( V_2 ) ) {
F_60 ( V_19 -> V_86 -> V_91 ) ;
return V_92 ;
}
F_1 ( V_2 , & V_4 ) ;
V_88 = V_2 -> V_88 ;
V_15 = F_63 ( V_12 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_86 = F_64 ( V_19 -> V_86 ) ;
F_65 ( & V_86 -> V_93 ) ;
V_86 -> V_94 ++ ;
V_86 -> V_95 += V_88 ;
F_66 ( & V_86 -> V_93 ) ;
} else {
F_60 ( V_19 -> V_86 -> V_91 ) ;
F_61 ( V_2 ) ;
}
return V_92 ;
}
static int F_67 ( struct V_84 * V_40 , void * V_96 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_97 * V_36 = V_96 ;
int V_15 ;
if ( ! F_68 ( V_36 -> V_98 ) )
return - V_99 ;
V_15 = F_24 ( V_19 , V_36 -> V_98 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_40 -> V_41 , V_36 -> V_98 , V_40 -> V_100 ) ;
return 0 ;
}
static int F_69 ( struct V_84 * V_40 , int V_51 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
int V_15 ;
V_15 = F_34 ( V_19 , V_51 ) ;
if ( V_15 )
return V_15 ;
V_40 -> V_51 = V_51 ;
return 0 ;
}
static struct V_101 *
F_70 ( struct V_84 * V_40 ,
struct V_101 * V_102 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_85 * V_96 ;
T_4 V_103 , V_104 , V_94 , V_95 ;
T_5 V_91 = 0 ;
unsigned int V_105 ;
int V_106 ;
F_71 (i) {
V_96 = F_72 ( V_19 -> V_86 , V_106 ) ;
do {
V_105 = F_73 ( & V_96 -> V_93 ) ;
V_103 = V_96 -> V_103 ;
V_104 = V_96 -> V_104 ;
V_94 = V_96 -> V_94 ;
V_95 = V_96 -> V_95 ;
} while ( F_74 ( & V_96 -> V_93 , V_105 ) );
V_102 -> V_103 += V_103 ;
V_102 -> V_104 += V_104 ;
V_102 -> V_94 += V_94 ;
V_102 -> V_95 += V_95 ;
V_91 += V_96 -> V_91 ;
}
V_102 -> V_91 = V_91 ;
return V_102 ;
}
int F_75 ( struct V_19 * V_19 , T_2 V_107 ,
T_2 V_108 , bool V_109 , bool V_110 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_111 ;
int V_15 ;
V_111 = F_30 ( V_112 , V_48 ) ;
if ( ! V_111 )
return - V_49 ;
F_76 ( V_111 , V_19 -> V_10 , V_107 ,
V_108 , V_109 , V_110 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_113 ) , V_111 ) ;
F_33 ( V_111 ) ;
return V_15 ;
}
static int F_77 ( struct V_19 * V_19 )
{
enum V_66 V_67 = V_114 ;
T_2 V_43 , V_115 ;
int V_15 ;
F_78 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_41 ( V_19 , V_67 , true , V_43 ,
V_43 ) ;
if ( V_15 ) {
V_115 = V_43 ;
goto V_116;
}
}
V_15 = F_39 ( V_19 , true ) ;
if ( V_15 ) {
V_115 = V_117 ;
goto V_116;
}
return 0 ;
V_116:
F_78 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_41 ( V_19 , V_67 , false , V_43 ,
V_43 ) ;
return V_15 ;
}
static int F_79 ( struct V_19 * V_19 )
{
enum V_66 V_67 = V_114 ;
T_2 V_43 ;
int V_15 ;
V_15 = F_39 ( V_19 , false ) ;
if ( V_15 )
return V_15 ;
F_78 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_41 ( V_19 , V_67 , false ,
V_43 , V_43 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int F_80 ( struct V_84 * V_40 , T_6 T_7 V_118 ,
T_2 V_43 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_119 ;
int V_15 ;
if ( ! V_43 )
return 0 ;
if ( F_81 ( V_43 , V_19 -> V_34 ) ) {
F_82 ( V_40 , L_1 , V_43 ) ;
return 0 ;
}
if ( ! F_81 ( V_43 , V_12 -> V_34 ) ) {
V_15 = F_19 ( V_12 , V_43 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_2 ,
V_32 + V_43 ) ;
return V_15 ;
}
V_119 = F_30 ( V_120 , V_48 ) ;
if ( ! V_119 ) {
V_15 = - V_49 ;
goto V_121;
}
F_84 ( V_119 , 0 , V_43 ,
V_122 , 0 ,
V_123 , true ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_124 ) , V_119 ) ;
F_33 ( V_119 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_3 ) ;
goto V_125;
}
}
if ( ! V_19 -> V_126 ) {
V_15 = F_77 ( V_19 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_4 ) ;
return V_15 ;
}
}
V_15 = F_41 ( V_19 ,
V_114 ,
true , V_32 + V_43 , V_43 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_5 ,
V_43 , V_32 + V_43 ) ;
goto V_116;
}
V_15 = F_43 ( V_19 , V_43 , false ) ;
if ( V_15 ) {
F_83 ( V_40 , L_6 , V_43 ) ;
goto V_127;
}
V_15 = F_75 ( V_19 , V_43 , V_43 , true , false ) ;
if ( V_15 ) {
F_83 ( V_40 , L_7 ,
V_43 ) ;
goto V_128;
}
V_15 = F_29 ( V_19 , V_43 ,
V_129 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_8 , V_43 ) ;
goto V_130;
}
V_19 -> V_126 ++ ;
F_21 ( V_43 , V_19 -> V_34 ) ;
return 0 ;
V_125:
V_121:
F_22 ( V_12 , V_43 ) ;
return V_15 ;
V_130:
F_75 ( V_19 , V_43 , V_43 , false , false ) ;
V_128:
F_43 ( V_19 , V_43 , true ) ;
V_127:
F_41 ( V_19 ,
V_114 , false ,
V_32 + V_43 , V_43 ) ;
V_116:
F_79 ( V_19 ) ;
return V_15 ;
}
int F_85 ( struct V_84 * V_40 ,
T_6 T_7 V_118 , T_2 V_43 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
int V_15 ;
if ( ! V_43 )
return 0 ;
if ( ! F_81 ( V_43 , V_19 -> V_34 ) ) {
F_82 ( V_40 , L_9 , V_43 ) ;
return 0 ;
}
V_15 = F_29 ( V_19 , V_43 ,
V_131 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_8 , V_43 ) ;
return V_15 ;
}
V_15 = F_75 ( V_19 , V_43 , V_43 , false , false ) ;
if ( V_15 ) {
F_83 ( V_40 , L_7 ,
V_43 ) ;
return V_15 ;
}
V_15 = F_43 ( V_19 , V_43 , true ) ;
if ( V_15 ) {
F_83 ( V_40 , L_10 , V_43 ) ;
return V_15 ;
}
V_15 = F_41 ( V_19 ,
V_114 ,
false , V_32 + V_43 ,
V_43 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_11 ,
V_43 , V_32 + V_43 ) ;
return V_15 ;
}
if ( V_19 -> V_126 == 1 ) {
V_15 = F_79 ( V_19 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_12 ) ;
return V_15 ;
}
}
V_19 -> V_126 -- ;
F_23 ( V_43 , V_19 -> V_34 ) ;
return 0 ;
}
static void F_86 ( struct V_84 * V_40 ,
struct V_132 * V_133 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
F_87 ( V_133 -> V_134 , V_135 , sizeof( V_133 -> V_134 ) ) ;
F_87 ( V_133 -> V_136 , V_137 ,
sizeof( V_133 -> V_136 ) ) ;
snprintf ( V_133 -> V_138 , sizeof( V_133 -> V_138 ) ,
L_13 ,
V_12 -> V_139 -> V_140 . V_141 ,
V_12 -> V_139 -> V_140 . V_142 ,
V_12 -> V_139 -> V_140 . V_143 ) ;
F_87 ( V_133 -> V_139 , V_12 -> V_139 -> V_144 ,
sizeof( V_133 -> V_139 ) ) ;
}
static void F_88 ( struct V_84 * V_40 ,
T_5 V_145 , T_1 * V_146 )
{
T_1 * V_96 = V_146 ;
int V_106 ;
switch ( V_145 ) {
case V_147 :
for ( V_106 = 0 ; V_106 < V_148 ; V_106 ++ ) {
memcpy ( V_96 , V_149 [ V_106 ] . V_150 ,
V_151 ) ;
V_96 += V_151 ;
}
break;
}
}
static void F_89 ( struct V_84 * V_40 ,
struct V_152 * V_102 , T_4 * V_146 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_153 [ V_154 ] ;
int V_106 ;
int V_15 ;
F_90 ( V_153 , V_19 -> V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_155 ) , V_153 ) ;
for ( V_106 = 0 ; V_106 < V_148 ; V_106 ++ )
V_146 [ V_106 ] = ! V_15 ? V_149 [ V_106 ] . F_91 ( V_153 ) : 0 ;
}
static int F_92 ( struct V_84 * V_40 , int V_156 )
{
switch ( V_156 ) {
case V_147 :
return V_148 ;
default:
return - V_157 ;
}
}
static T_5 F_93 ( T_5 V_158 )
{
if ( V_158 & ( V_159 |
V_160 |
V_161 |
V_162 |
V_163 |
V_164 ) )
return V_165 ;
if ( V_158 & ( V_166 |
V_167 |
V_168 |
V_169 |
V_170 ) )
return V_171 ;
return 0 ;
}
static T_5 F_94 ( T_5 V_158 )
{
T_5 V_172 = 0 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_173 ; V_106 ++ ) {
if ( V_158 & V_174 [ V_106 ] . V_175 )
V_172 |= V_174 [ V_106 ] . V_176 ;
}
return V_172 ;
}
static T_5 F_95 ( T_5 V_158 )
{
T_5 V_172 = 0 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_173 ; V_106 ++ ) {
if ( V_158 & V_174 [ V_106 ] . V_175 )
V_172 |= V_174 [ V_106 ] . V_177 ;
}
return V_172 ;
}
static void F_96 ( bool V_178 , T_5 V_158 ,
struct V_179 * V_180 )
{
T_5 V_181 = V_182 ;
T_1 V_183 = V_184 ;
int V_106 ;
if ( ! V_178 )
goto V_185;
for ( V_106 = 0 ; V_106 < V_173 ; V_106 ++ ) {
if ( V_158 & V_174 [ V_106 ] . V_175 ) {
V_181 = V_174 [ V_106 ] . V_181 ;
V_183 = V_186 ;
break;
}
}
V_185:
F_97 ( V_180 , V_181 ) ;
V_180 -> V_183 = V_183 ;
}
static T_1 F_98 ( T_5 V_158 )
{
if ( V_158 & ( V_160 |
V_162 |
V_163 |
V_164 ) )
return V_187 ;
if ( V_158 & ( V_159 |
V_161 |
V_188 ) )
return V_189 ;
if ( V_158 & ( V_166 |
V_167 |
V_168 |
V_169 ) )
return V_190 ;
return V_191 ;
}
static int F_99 ( struct V_84 * V_40 ,
struct V_179 * V_180 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_192 [ V_193 ] ;
T_5 V_194 ;
T_5 V_195 ;
T_5 V_196 ;
int V_15 ;
F_100 ( V_192 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_197 ) , V_192 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_14 ) ;
return V_15 ;
}
F_101 ( V_192 , & V_194 ,
& V_195 , & V_196 ) ;
V_180 -> V_176 = F_93 ( V_194 ) |
F_94 ( V_194 ) |
V_198 | V_199 ;
V_180 -> V_200 = F_95 ( V_195 ) ;
F_96 ( F_102 ( V_40 ) ,
V_196 , V_180 ) ;
V_196 = V_196 ? V_196 : V_194 ;
V_180 -> V_201 = F_98 ( V_196 ) ;
V_180 -> V_202 = F_95 ( V_196 ) ;
V_180 -> V_203 = V_204 ;
return 0 ;
}
static T_5 F_103 ( T_5 V_200 )
{
T_5 V_205 = 0 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_173 ; V_106 ++ ) {
if ( V_200 & V_174 [ V_106 ] . V_177 )
V_205 |= V_174 [ V_106 ] . V_175 ;
}
return V_205 ;
}
static T_5 F_104 ( T_5 V_181 )
{
T_5 V_205 = 0 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_173 ; V_106 ++ ) {
if ( V_181 == V_174 [ V_106 ] . V_181 )
V_205 |= V_174 [ V_106 ] . V_175 ;
}
return V_205 ;
}
static int F_105 ( struct V_84 * V_40 ,
struct V_179 * V_180 )
{
struct V_19 * V_19 = F_51 ( V_40 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_192 [ V_193 ] ;
T_5 V_181 ;
T_5 V_206 ;
T_5 V_194 ;
T_5 V_195 ;
bool V_20 ;
int V_15 ;
V_181 = F_106 ( V_180 ) ;
V_206 = V_180 -> V_207 == V_208 ?
F_103 ( V_180 -> V_200 ) :
F_104 ( V_181 ) ;
F_100 ( V_192 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_197 ) , V_192 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_14 ) ;
return V_15 ;
}
F_101 ( V_192 , & V_194 , & V_195 , NULL ) ;
V_206 = V_206 & V_194 ;
if ( ! V_206 ) {
F_83 ( V_40 , L_15 ) ;
return - V_57 ;
}
if ( V_206 == V_195 )
return 0 ;
F_100 ( V_192 , V_19 -> V_10 , V_206 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_197 ) , V_192 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_16 ) ;
return V_15 ;
}
V_15 = F_17 ( V_19 , & V_20 ) ;
if ( V_15 ) {
F_83 ( V_40 , L_17 ) ;
return V_15 ;
}
if ( ! V_20 )
return 0 ;
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 ) {
F_83 ( V_40 , L_18 ) ;
return V_15 ;
}
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 ) {
F_83 ( V_40 , L_18 ) ;
return V_15 ;
}
return 0 ;
}
static int F_107 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_19 * V_19 ;
struct V_84 * V_40 ;
bool V_209 ;
int V_15 ;
V_40 = F_108 ( sizeof( struct V_19 ) ) ;
if ( ! V_40 )
return - V_49 ;
V_19 = F_51 ( V_40 ) ;
V_19 -> V_40 = V_40 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_10 = V_10 ;
V_19 -> V_210 = 1 ;
V_19 -> V_211 = 1 ;
V_19 -> V_212 = 1 ;
V_19 -> V_213 = 1 ;
V_19 -> V_86 =
F_109 ( struct V_85 ) ;
if ( ! V_19 -> V_86 ) {
V_15 = - V_49 ;
goto V_214;
}
V_40 -> V_215 = & V_216 ;
V_40 -> V_217 = & V_218 ;
V_15 = F_27 ( V_19 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_19 ,
V_19 -> V_10 ) ;
goto V_219;
}
F_111 ( V_40 ) ;
V_40 -> V_220 |= V_221 | V_222 | V_223 |
V_224 ;
V_40 -> V_225 += V_6 ;
V_15 = F_47 ( V_19 , & V_209 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_20 ,
V_19 -> V_10 ) ;
goto V_226;
}
if ( ! V_209 ) {
F_112 ( V_12 -> V_139 -> V_40 , L_21 ,
V_19 -> V_10 ) ;
goto V_227;
}
V_15 = F_45 ( V_19 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_22 ,
V_19 -> V_10 ) ;
goto V_228;
}
V_15 = F_37 ( V_19 , 0 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_23 ,
V_19 -> V_10 ) ;
goto V_229;
}
V_15 = F_34 ( V_19 , V_230 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_24 ,
V_19 -> V_10 ) ;
goto V_231;
}
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 )
goto V_232;
V_15 = F_113 ( V_19 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_25 ,
V_19 -> V_10 ) ;
goto V_233;
}
F_114 ( V_19 ) ;
V_15 = F_115 ( V_40 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_26 ,
V_19 -> V_10 ) ;
goto V_234;
}
V_15 = F_116 ( V_19 ) ;
if ( V_15 )
goto V_235;
V_12 -> V_236 [ V_10 ] = V_19 ;
return 0 ;
V_235:
F_117 ( V_40 ) ;
V_234:
V_233:
V_232:
V_231:
V_229:
V_228:
V_227:
V_226:
V_219:
F_118 ( V_19 -> V_86 ) ;
V_214:
F_119 ( V_40 ) ;
return V_15 ;
}
static void F_120 ( struct V_12 * V_12 )
{
T_2 V_28 ;
F_78 (vfid, mlxsw_sp->active_vfids, VLAN_N_VID)
F_22 ( V_12 , V_28 ) ;
}
static void F_121 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_19 * V_19 = V_12 -> V_236 [ V_10 ] ;
if ( ! V_19 )
return;
F_85 ( V_19 -> V_40 , 0 , 1 ) ;
F_117 ( V_19 -> V_40 ) ;
F_122 ( V_19 ) ;
F_118 ( V_19 -> V_86 ) ;
F_119 ( V_19 -> V_40 ) ;
}
static void F_123 ( struct V_12 * V_12 )
{
int V_106 ;
for ( V_106 = 1 ; V_106 < V_237 ; V_106 ++ )
F_121 ( V_12 , V_106 ) ;
F_33 ( V_12 -> V_236 ) ;
}
static int F_124 ( struct V_12 * V_12 )
{
T_8 V_238 ;
int V_106 ;
int V_15 ;
V_238 = sizeof( struct V_19 * ) * V_237 ;
V_12 -> V_236 = F_125 ( V_238 , V_48 ) ;
if ( ! V_12 -> V_236 )
return - V_49 ;
for ( V_106 = 1 ; V_106 < V_237 ; V_106 ++ ) {
V_15 = F_107 ( V_12 , V_106 ) ;
if ( V_15 )
goto V_239;
}
return 0 ;
V_239:
for ( V_106 -- ; V_106 >= 1 ; V_106 -- )
F_121 ( V_12 , V_106 ) ;
F_33 ( V_12 -> V_236 ) ;
return V_15 ;
}
static void F_126 ( const struct V_240 * V_241 ,
char * V_242 , void * V_243 )
{
struct V_12 * V_12 = V_243 ;
struct V_19 * V_19 ;
enum V_244 V_245 ;
T_1 V_10 ;
V_10 = F_127 ( V_242 ) ;
V_19 = V_12 -> V_236 [ V_10 ] ;
if ( ! V_19 ) {
F_128 ( V_12 -> V_139 -> V_40 , L_27 ,
V_10 ) ;
return;
}
V_245 = F_129 ( V_242 ) ;
if ( V_245 == V_246 ) {
F_130 ( V_19 -> V_40 , L_28 ) ;
F_131 ( V_19 -> V_40 ) ;
} else {
F_130 ( V_19 -> V_40 , L_29 ) ;
F_111 ( V_19 -> V_40 ) ;
}
}
static int F_132 ( struct V_12 * V_12 ,
enum V_247 V_248 )
{
struct V_249 * V_250 ;
char V_251 [ V_252 ] ;
int V_15 ;
switch ( V_248 ) {
case V_253 :
V_250 = & V_254 ;
break;
}
V_15 = F_133 ( V_12 -> V_16 , V_250 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_134 ( V_251 , V_255 , V_248 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_256 ) , V_251 ) ;
if ( V_15 )
goto V_257;
return 0 ;
V_257:
F_135 ( V_12 -> V_16 , V_250 , V_12 ) ;
return V_15 ;
}
static void F_136 ( struct V_12 * V_12 ,
enum V_247 V_248 )
{
struct V_249 * V_250 ;
switch ( V_248 ) {
case V_253 :
V_250 = & V_254 ;
break;
}
F_135 ( V_12 -> V_16 , V_250 , V_12 ) ;
}
static void F_137 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_243 )
{
struct V_12 * V_12 = V_243 ;
struct V_19 * V_19 = V_12 -> V_236 [ V_10 ] ;
struct V_85 * V_86 ;
if ( F_57 ( ! V_19 ) ) {
F_138 ( V_12 -> V_139 -> V_40 , L_30 ,
V_10 ) ;
return;
}
V_2 -> V_40 = V_19 -> V_40 ;
V_86 = F_64 ( V_19 -> V_86 ) ;
F_65 ( & V_86 -> V_93 ) ;
V_86 -> V_103 ++ ;
V_86 -> V_104 += V_2 -> V_88 ;
F_66 ( & V_86 -> V_93 ) ;
V_2 -> V_258 = F_139 ( V_2 , V_2 -> V_40 ) ;
F_140 ( V_2 ) ;
}
static int F_141 ( struct V_12 * V_12 )
{
char V_259 [ V_260 ] ;
char V_251 [ V_252 ] ;
int V_106 ;
int V_15 ;
F_142 ( V_259 , V_261 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_262 ) , V_259 ) ;
if ( V_15 )
return V_15 ;
F_142 ( V_259 , V_263 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_262 ) , V_259 ) ;
if ( V_15 )
return V_15 ;
for ( V_106 = 0 ; V_106 < F_143 ( V_264 ) ; V_106 ++ ) {
V_15 = F_144 ( V_12 -> V_16 ,
& V_264 [ V_106 ] ,
V_12 ) ;
if ( V_15 )
goto V_265;
F_134 ( V_251 , V_266 ,
V_264 [ V_106 ] . V_248 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_256 ) , V_251 ) ;
if ( V_15 )
goto V_267;
}
return 0 ;
V_267:
F_145 ( V_12 -> V_16 ,
& V_264 [ V_106 ] ,
V_12 ) ;
V_265:
for ( V_106 -- ; V_106 >= 0 ; V_106 -- ) {
F_134 ( V_251 , V_255 ,
V_264 [ V_106 ] . V_248 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_256 ) , V_251 ) ;
F_145 ( V_12 -> V_16 ,
& V_264 [ V_106 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_146 ( struct V_12 * V_12 )
{
char V_251 [ V_252 ] ;
int V_106 ;
for ( V_106 = 0 ; V_106 < F_143 ( V_264 ) ; V_106 ++ ) {
F_134 ( V_251 , V_255 ,
V_264 [ V_106 ] . V_248 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_256 ) , V_251 ) ;
F_145 ( V_12 -> V_16 ,
& V_264 [ V_106 ] ,
V_12 ) ;
}
}
static int F_147 ( struct V_268 * V_268 ,
enum V_269 type ,
enum V_270 V_271 )
{
enum V_272 V_273 ;
enum V_274 V_275 ;
char V_276 [ V_277 ] ;
if ( V_271 == V_278 ) {
V_273 = V_122 ;
V_275 = 0 ;
} else {
V_273 = V_279 ;
if ( type == V_280 )
V_275 = V_281 ;
else
V_275 = V_282 ;
}
F_148 ( V_276 , type , V_271 , V_273 ,
V_275 ) ;
return F_16 ( V_268 , F_12 ( V_283 ) , V_276 ) ;
}
static int F_149 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_284 ; type ++ ) {
if ( type == V_285 )
continue;
V_15 = F_147 ( V_12 -> V_16 , type ,
V_278 ) ;
if ( V_15 )
return V_15 ;
}
for ( type = 0 ; type < V_284 ; type ++ ) {
if ( type == V_285 )
continue;
V_15 = F_147 ( V_12 -> V_16 , type ,
V_286 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_150 ( void * V_243 , struct V_268 * V_268 ,
const struct V_287 * V_287 )
{
struct V_12 * V_12 = V_243 ;
int V_15 ;
V_12 -> V_16 = V_268 ;
V_12 -> V_139 = V_287 ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_31 ) ;
return V_15 ;
}
V_15 = F_124 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_32 ) ;
goto V_288;
}
V_15 = F_132 ( V_12 , V_253 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_33 ) ;
goto V_289;
}
V_15 = F_141 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_34 ) ;
goto V_265;
}
V_15 = F_149 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_35 ) ;
goto V_290;
}
V_15 = F_151 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_36 ) ;
goto V_291;
}
V_15 = F_152 ( V_12 ) ;
if ( V_15 ) {
F_110 ( V_12 -> V_139 -> V_40 , L_37 ) ;
goto V_292;
}
return 0 ;
V_292:
V_291:
V_290:
F_146 ( V_12 ) ;
V_265:
F_136 ( V_12 , V_253 ) ;
V_289:
F_123 ( V_12 ) ;
V_288:
F_120 ( V_12 ) ;
return V_15 ;
}
static void F_153 ( void * V_243 )
{
struct V_12 * V_12 = V_243 ;
F_154 ( V_12 ) ;
F_146 ( V_12 ) ;
F_136 ( V_12 , V_253 ) ;
F_123 ( V_12 ) ;
F_120 ( V_12 ) ;
}
static bool F_155 ( const struct V_84 * V_40 )
{
return V_40 -> V_215 == & V_216 ;
}
static int F_156 ( struct V_19 * V_19 )
{
struct V_84 * V_40 = V_19 -> V_40 ;
int V_15 ;
V_15 = F_85 ( V_40 , 0 , 1 ) ;
if ( V_15 )
F_83 ( V_40 , L_38 ) ;
return V_15 ;
}
static int F_157 ( struct V_19 * V_19 )
{
struct V_84 * V_40 = V_19 -> V_40 ;
int V_15 ;
V_15 = F_80 ( V_40 , 0 , 1 ) ;
if ( V_15 )
F_83 ( V_40 , L_39 ) ;
return V_15 ;
}
static bool F_158 ( struct V_12 * V_12 ,
struct V_84 * V_293 )
{
return ! V_12 -> V_294 . V_40 ||
V_12 -> V_294 . V_40 == V_293 ;
}
static void F_159 ( struct V_12 * V_12 ,
struct V_84 * V_293 )
{
V_12 -> V_294 . V_40 = V_293 ;
V_12 -> V_294 . V_295 ++ ;
}
static void F_160 ( struct V_12 * V_12 ,
struct V_84 * V_293 )
{
if ( -- V_12 -> V_294 . V_295 == 0 )
V_12 -> V_294 . V_40 = NULL ;
}
static int F_161 ( struct V_296 * V_297 ,
unsigned long V_298 , void * V_299 )
{
struct V_84 * V_40 = F_162 ( V_299 ) ;
struct V_300 * V_301 ;
struct V_19 * V_19 ;
struct V_84 * V_302 ;
struct V_12 * V_12 ;
int V_15 ;
if ( ! F_155 ( V_40 ) )
return V_303 ;
V_19 = F_51 ( V_40 ) ;
V_12 = V_19 -> V_12 ;
V_301 = V_299 ;
switch ( V_298 ) {
case V_304 :
V_302 = V_301 -> V_302 ;
if ( V_301 -> V_305 && V_301 -> V_306 &&
F_163 ( V_302 ) &&
! F_158 ( V_12 , V_302 ) )
return V_307 ;
break;
case V_308 :
V_302 = V_301 -> V_302 ;
if ( V_301 -> V_305 &&
F_163 ( V_302 ) ) {
if ( V_301 -> V_306 ) {
V_15 = F_156 ( V_19 ) ;
if ( V_15 )
F_83 ( V_40 , L_40 ) ;
F_159 ( V_12 , V_302 ) ;
V_19 -> V_309 = 1 ;
} else {
V_15 = F_157 ( V_19 ) ;
if ( V_15 )
F_83 ( V_40 , L_41 ) ;
V_19 -> V_309 = 0 ;
F_160 ( V_12 , V_302 ) ;
}
}
break;
}
return V_303 ;
}
static int T_9 F_164 ( void )
{
int V_15 ;
F_165 ( & V_310 ) ;
V_15 = F_166 ( & V_311 ) ;
if ( V_15 )
goto V_312;
return 0 ;
V_312:
F_167 ( & V_310 ) ;
return V_15 ;
}
static void T_10 F_168 ( void )
{
F_169 ( & V_311 ) ;
F_167 ( & V_310 ) ;
}
