static T_1 F_1 ( struct V_1 * V_1 ,
T_1 V_2 )
{
T_1 V_3 = V_2 ;
if ( F_2 ( V_1 ) ) {
T_1 V_4 = F_3 ( V_1 ) ;
V_3 = F_4 ( V_4 ) ;
}
if ( ! V_3 )
V_3 = V_1 -> V_5 ;
return V_3 ;
}
static struct V_1 *
F_5 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_1 * V_8 ;
T_1 V_2 ;
if ( ! F_6 ( V_7 ) )
return V_1 ;
V_2 = F_7 ( V_7 ) ;
V_8 = F_8 ( V_1 , V_2 ) ;
F_9 ( ! V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_11 ( V_7 ) ;
struct V_11 * V_11 = V_1 -> V_11 ;
V_1 = F_5 ( V_10 -> V_12 , V_1 ) ;
if ( ! V_1 )
return - V_13 ;
switch ( V_10 -> V_14 ) {
case V_15 :
V_10 -> V_16 . V_17 . V_18 = sizeof( V_11 -> V_19 ) ;
memcpy ( & V_10 -> V_16 . V_17 . V_14 , & V_11 -> V_19 ,
V_10 -> V_16 . V_17 . V_18 ) ;
break;
case V_20 :
V_10 -> V_16 . V_21 =
( V_1 -> V_22 ? V_23 : 0 ) |
( V_1 -> V_24 ? V_25 : 0 ) |
( V_1 -> V_26 ? V_27 : 0 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 ,
T_2 V_29 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
enum V_30 V_31 ;
char * V_32 ;
T_1 V_2 ;
int V_33 ;
switch ( V_29 ) {
case V_34 :
V_31 = V_35 ;
break;
case V_36 :
V_31 = V_37 ;
break;
case V_38 :
case V_39 :
case V_40 :
V_31 = V_41 ;
break;
default:
F_13 () ;
}
V_32 = F_14 ( V_42 , V_43 ) ;
if ( ! V_32 )
return - V_44 ;
F_15 ( V_32 , V_1 -> V_45 ) ;
if ( F_2 ( V_1 ) ) {
V_2 = F_16 ( V_1 ) ;
F_17 ( V_32 , V_2 , V_31 ) ;
} else {
F_18 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_17 ( V_32 , V_2 , V_31 ) ;
}
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_47 ) , V_32 ) ;
F_21 ( V_32 ) ;
return V_33 ;
}
static int F_22 ( struct V_1 * V_1 ,
struct V_48 * V_49 ,
T_2 V_29 )
{
if ( F_23 ( V_49 ) )
return 0 ;
V_1 -> V_50 = V_29 ;
return F_12 ( V_1 , V_29 ) ;
}
static bool F_24 ( T_1 V_4 )
{
return V_4 >= V_51 ;
}
static int F_25 ( struct V_1 * V_1 ,
T_1 V_52 , T_1 V_53 , bool V_54 ,
bool V_55 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
T_1 V_45 = V_1 -> V_45 ;
enum V_56 V_57 ;
T_1 V_58 = V_53 - V_52 + 1 ;
char * V_59 ;
int V_33 ;
if ( F_2 ( V_1 ) ) {
V_57 = V_60 ;
if ( F_24 ( V_52 ) )
V_45 = V_1 -> V_45 ;
else
V_45 = V_61 ;
} else {
V_57 = V_62 ;
}
V_59 = F_14 ( V_63 , V_43 ) ;
if ( ! V_59 )
return - V_44 ;
F_26 ( V_59 , V_64 , V_52 ,
V_57 , V_58 , V_45 , V_54 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_65 ) , V_59 ) ;
if ( V_33 )
goto V_66;
if ( V_55 )
goto V_66;
F_26 ( V_59 , V_67 , V_52 ,
V_57 , V_58 , V_45 , V_54 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_65 ) , V_59 ) ;
V_66:
F_21 ( V_59 ) ;
return V_33 ;
}
static int F_27 ( struct V_1 * V_1 ,
bool V_54 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
T_1 V_2 , V_68 ;
int V_33 ;
if ( F_2 ( V_1 ) ) {
T_1 V_4 = F_3 ( V_1 ) ;
return F_25 ( V_1 , V_4 , V_4 ,
V_54 , true ) ;
}
F_18 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_33 = F_25 ( V_1 , V_2 , V_2 , V_54 ,
true ) ;
if ( V_33 ) {
V_68 = V_2 ;
goto V_69;
}
}
return 0 ;
V_69:
F_18 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_25 ( V_1 , V_2 , V_2 , ! V_54 , true ) ;
F_28 ( V_7 , L_1 ) ;
return V_33 ;
}
int F_29 ( struct V_1 * V_8 , T_1 V_4 ,
bool V_54 , bool V_55 )
{
return F_25 ( V_8 , V_4 , V_4 , V_54 ,
V_55 ) ;
}
static int F_30 ( struct V_1 * V_1 ,
struct V_48 * V_49 ,
unsigned long V_21 )
{
unsigned long V_26 = V_1 -> V_26 ? V_27 : 0 ;
bool V_54 ;
int V_33 ;
if ( ! V_1 -> V_70 )
return - V_13 ;
if ( F_23 ( V_49 ) )
return 0 ;
if ( ( V_26 ^ V_21 ) & V_27 ) {
V_54 = V_1 -> V_26 ? false : true ;
V_33 = F_27 ( V_1 , V_54 ) ;
if ( V_33 )
return V_33 ;
}
V_1 -> V_26 = V_21 & V_27 ? 1 : 0 ;
V_1 -> V_22 = V_21 & V_23 ? 1 : 0 ;
V_1 -> V_24 = V_21 & V_25 ? 1 : 0 ;
return 0 ;
}
static int F_31 ( struct V_11 * V_11 , T_3 V_71 )
{
char V_72 [ V_73 ] ;
int V_33 ;
F_32 ( V_72 , V_71 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_74 ) , V_72 ) ;
if ( V_33 )
return V_33 ;
V_11 -> V_71 = V_71 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 ,
struct V_48 * V_49 ,
unsigned long V_75 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
unsigned long V_76 = F_34 ( V_75 ) ;
T_3 V_71 = F_35 ( V_76 ) / 1000 ;
if ( F_23 ( V_49 ) )
return 0 ;
return F_31 ( V_11 , V_71 ) ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_48 * V_49 ,
struct V_6 * V_12 ,
bool V_77 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
if ( ( ! V_77 ) && ( V_11 -> V_78 . V_7 == V_12 ) ) {
F_28 ( V_1 -> V_7 , L_2 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_37 ( struct V_6 * V_7 ,
const struct V_9 * V_10 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_11 ( V_7 ) ;
int V_33 = 0 ;
V_1 = F_5 ( V_10 -> V_12 , V_1 ) ;
if ( ! V_1 )
return - V_13 ;
switch ( V_10 -> V_14 ) {
case V_79 :
V_33 = F_22 ( V_1 , V_49 ,
V_10 -> V_16 . V_50 ) ;
break;
case V_20 :
V_33 = F_30 ( V_1 , V_49 ,
V_10 -> V_16 . V_21 ) ;
break;
case V_80 :
V_33 = F_33 ( V_1 , V_49 ,
V_10 -> V_16 . V_71 ) ;
break;
case V_81 :
V_33 = F_36 ( V_1 , V_49 ,
V_10 -> V_12 ,
V_10 -> V_16 . V_82 ) ;
break;
default:
V_33 = - V_28 ;
break;
}
return V_33 ;
}
static int F_38 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
char V_83 [ V_84 ] ;
F_39 ( V_83 , V_1 -> V_45 , V_2 ) ;
return F_19 ( V_11 -> V_46 , F_20 ( V_85 ) , V_83 ) ;
}
static int F_40 ( struct V_1 * V_1 ,
bool V_86 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
char V_87 [ V_88 ] ;
F_41 ( V_87 , V_1 -> V_45 , V_86 ) ;
return F_19 ( V_11 -> V_46 , F_20 ( V_89 ) , V_87 ) ;
}
int F_42 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
int V_33 ;
if ( ! V_2 ) {
V_33 = F_40 ( V_1 , false ) ;
if ( V_33 ) {
F_28 ( V_7 , L_3 ) ;
return V_33 ;
}
} else {
V_33 = F_38 ( V_1 , V_2 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_4 ) ;
return V_33 ;
}
if ( ! V_1 -> V_5 ) {
V_33 = F_40 ( V_1 ,
true ) ;
if ( V_33 ) {
F_28 ( V_7 , L_5 ) ;
goto V_90;
}
}
}
V_1 -> V_5 = V_2 ;
return 0 ;
V_90:
F_38 ( V_1 , V_1 -> V_5 ) ;
return V_33 ;
}
static int F_43 ( struct V_11 * V_11 , T_1 V_3 )
{
char V_91 [ V_92 ] ;
int V_33 ;
F_44 ( V_91 , V_93 , V_3 , V_3 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_94 ) , V_91 ) ;
if ( V_33 )
return V_33 ;
F_45 ( V_3 , V_11 -> V_95 ) ;
return 0 ;
}
static void F_46 ( struct V_11 * V_11 , T_1 V_3 )
{
char V_91 [ V_92 ] ;
F_47 ( V_3 , V_11 -> V_95 ) ;
F_44 ( V_91 , V_96 ,
V_3 , V_3 ) ;
F_19 ( V_11 -> V_46 , F_20 ( V_94 ) , V_91 ) ;
}
static int F_48 ( struct V_1 * V_1 , T_1 V_3 )
{
enum V_97 V_98 ;
if ( ! F_49 ( & V_1 -> V_99 ) )
V_98 = V_100 ;
else
V_98 = V_101 ;
return F_50 ( V_1 , V_98 , true , V_3 , V_3 ) ;
}
static int F_51 ( struct V_1 * V_1 , T_1 V_3 )
{
enum V_97 V_98 ;
if ( F_49 ( & V_1 -> V_99 ) )
return 0 ;
V_98 = V_100 ;
return F_50 ( V_1 , V_98 , false , V_3 , V_3 ) ;
}
static int F_52 ( struct V_6 * V_7 , T_1 V_102 ,
T_1 V_103 )
{
T_1 V_2 ;
int V_33 ;
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
V_33 = F_53 ( V_7 , 0 , V_2 ) ;
if ( V_33 )
goto V_104;
}
return 0 ;
V_104:
for ( V_2 -- ; V_2 >= V_102 ; V_2 -- )
F_54 ( V_7 , 0 , V_2 ) ;
return V_33 ;
}
static int F_55 ( struct V_1 * V_1 ,
T_1 V_102 , T_1 V_103 , bool V_105 ,
bool V_106 )
{
T_1 V_2 , V_107 ;
int V_33 ;
for ( V_2 = V_102 ; V_2 <= V_103 ;
V_2 += V_108 ) {
V_107 = F_56 ( ( T_1 ) ( V_2 + V_108 - 1 ) ,
V_103 ) ;
V_33 = F_57 ( V_1 , V_2 , V_107 ,
V_105 , V_106 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_1 ,
T_1 V_102 , T_1 V_103 ,
bool V_109 , bool V_110 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
struct V_6 * V_7 = V_1 -> V_7 ;
T_1 V_2 , V_68 , V_111 ;
enum V_97 V_98 ;
int V_33 ;
if ( ! V_1 -> V_70 )
return F_52 ( V_7 , V_102 , V_103 ) ;
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
if ( ! F_59 ( V_2 , V_11 -> V_95 ) ) {
V_33 = F_43 ( V_11 , V_2 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_6 ,
V_2 ) ;
return V_33 ;
}
V_98 = V_101 ;
V_33 = F_50 ( V_1 , V_98 ,
true , V_2 , V_2 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_7 ,
V_2 ) ;
goto V_112;
}
}
}
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
V_33 = F_48 ( V_1 , V_2 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_8 , V_2 ) ;
V_68 = -- V_2 ;
goto V_113;
}
}
V_33 = F_25 ( V_1 , V_102 , V_103 ,
true , false ) ;
if ( V_33 ) {
F_28 ( V_7 , L_9 ) ;
goto V_69;
}
V_33 = F_55 ( V_1 , V_102 , V_103 ,
true , V_109 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_10 , V_102 ,
V_103 ) ;
goto V_114;
}
V_111 = V_1 -> V_5 ;
if ( V_110 && V_111 != V_102 ) {
V_33 = F_42 ( V_1 , V_102 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_11 , V_102 ) ;
goto V_115;
}
} else if ( ! V_110 && V_111 >= V_102 && V_111 <= V_103 ) {
V_33 = F_42 ( V_1 , 0 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_12 ) ;
goto V_115;
}
}
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
F_45 ( V_2 , V_1 -> V_116 ) ;
if ( V_109 )
F_45 ( V_2 , V_1 -> V_117 ) ;
else
F_47 ( V_2 , V_1 -> V_117 ) ;
}
V_33 = F_12 ( V_1 ,
V_1 -> V_50 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_13 ) ;
goto V_118;
}
return 0 ;
V_112:
F_46 ( V_11 , V_2 ) ;
return V_33 ;
V_118:
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ )
F_47 ( V_2 , V_1 -> V_116 ) ;
if ( V_111 != V_1 -> V_5 )
F_42 ( V_1 , V_111 ) ;
V_115:
F_55 ( V_1 , V_102 , V_103 , false ,
false ) ;
V_114:
F_25 ( V_1 , V_102 , V_103 , false ,
false ) ;
V_69:
V_68 = V_103 ;
V_113:
for ( V_2 = V_68 ; V_2 >= V_102 ; V_2 -- )
F_51 ( V_1 , V_2 ) ;
return V_33 ;
}
static int F_60 ( struct V_1 * V_1 ,
const struct V_119 * V_120 ,
struct V_48 * V_49 )
{
bool V_109 = V_120 -> V_121 & V_122 ;
bool V_110 = V_120 -> V_121 & V_123 ;
if ( F_23 ( V_49 ) )
return 0 ;
return F_58 ( V_1 ,
V_120 -> V_102 , V_120 -> V_103 ,
V_109 , V_110 ) ;
}
static enum V_124 F_61 ( bool V_125 )
{
return V_125 ? V_126 :
V_127 ;
}
static enum V_128 F_62 ( bool V_129 )
{
return V_129 ? V_130 :
V_131 ;
}
static int F_63 ( struct V_11 * V_11 , T_2 V_45 ,
const char * V_132 , T_1 V_3 , bool V_129 ,
bool V_125 )
{
char * V_133 ;
int V_33 ;
V_133 = F_14 ( V_134 , V_43 ) ;
if ( ! V_133 )
return - V_44 ;
F_64 ( V_133 , F_62 ( V_129 ) , 0 ) ;
F_65 ( V_133 , 0 , F_61 ( V_125 ) ,
V_132 , V_3 , V_135 ,
V_45 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_136 ) , V_133 ) ;
F_21 ( V_133 ) ;
return V_33 ;
}
static int F_66 ( struct V_11 * V_11 , T_1 V_137 ,
const char * V_132 , T_1 V_3 , T_1 V_138 ,
bool V_129 , bool V_125 )
{
char * V_133 ;
int V_33 ;
V_133 = F_14 ( V_134 , V_43 ) ;
if ( ! V_133 )
return - V_44 ;
F_64 ( V_133 , F_62 ( V_129 ) , 0 ) ;
F_67 ( V_133 , 0 , F_61 ( V_125 ) ,
V_132 , V_3 , V_135 ,
V_138 , V_137 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_136 ) , V_133 ) ;
F_21 ( V_133 ) ;
return V_33 ;
}
static int
F_68 ( struct V_1 * V_1 ,
const struct V_139 * V_140 ,
struct V_48 * V_49 )
{
T_1 V_3 = F_1 ( V_1 , V_140 -> V_2 ) ;
T_1 V_138 = 0 ;
if ( F_23 ( V_49 ) )
return 0 ;
if ( F_2 ( V_1 ) ) {
V_138 = F_16 ( V_1 ) ;
}
if ( ! V_1 -> V_141 )
return F_63 ( V_1 -> V_11 ,
V_1 -> V_45 ,
V_140 -> V_142 , V_3 , true , false ) ;
else
return F_66 ( V_1 -> V_11 ,
V_1 -> V_137 ,
V_140 -> V_142 , V_3 , V_138 ,
true , false ) ;
}
static int F_69 ( struct V_11 * V_11 , const char * V_142 ,
T_1 V_3 , T_1 V_143 , bool V_129 )
{
char * V_133 ;
int V_33 ;
V_133 = F_14 ( V_134 , V_43 ) ;
if ( ! V_133 )
return - V_44 ;
F_64 ( V_133 , F_62 ( V_129 ) , 0 ) ;
F_70 ( V_133 , 0 , V_142 , V_3 ,
V_135 , V_143 ) ;
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_136 ) , V_133 ) ;
F_21 ( V_133 ) ;
return V_33 ;
}
static int F_71 ( struct V_1 * V_1 , T_1 V_143 ,
bool V_144 , bool V_145 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
char * V_146 ;
int V_33 , V_147 ;
V_146 = F_14 ( V_148 , V_43 ) ;
if ( ! V_146 )
return - V_44 ;
F_72 ( V_146 , V_143 , V_1 -> V_45 , V_144 ) ;
if ( V_145 ) {
for ( V_147 = 1 ; V_147 < V_149 ; V_147 ++ )
if ( V_11 -> V_150 [ V_147 ] )
F_73 ( V_146 , V_147 , 1 ) ;
}
V_33 = F_19 ( V_11 -> V_46 , F_20 ( V_151 ) , V_146 ) ;
F_21 ( V_146 ) ;
return V_33 ;
}
static struct V_152 * F_74 ( struct V_11 * V_11 ,
const unsigned char * V_142 ,
T_1 V_2 )
{
struct V_152 * V_143 ;
F_75 (mid, &mlxsw_sp->br_mids.list, list) {
if ( F_76 ( V_143 -> V_142 , V_142 ) && V_143 -> V_2 == V_2 )
return V_143 ;
}
return NULL ;
}
static struct V_152 * F_77 ( struct V_11 * V_11 ,
const unsigned char * V_142 ,
T_1 V_2 )
{
struct V_152 * V_143 ;
T_1 V_153 ;
V_153 = F_78 ( V_11 -> V_154 . V_155 ,
V_156 ) ;
if ( V_153 == V_156 )
return NULL ;
V_143 = F_79 ( sizeof( * V_143 ) , V_43 ) ;
if ( ! V_143 )
return NULL ;
F_45 ( V_153 , V_11 -> V_154 . V_155 ) ;
F_80 ( V_143 -> V_142 , V_142 ) ;
V_143 -> V_2 = V_2 ;
V_143 -> V_143 = V_153 ;
V_143 -> V_157 = 0 ;
F_81 ( & V_143 -> V_158 , & V_11 -> V_154 . V_158 ) ;
return V_143 ;
}
static int F_82 ( struct V_11 * V_11 ,
struct V_152 * V_143 )
{
if ( -- V_143 -> V_157 == 0 ) {
F_83 ( & V_143 -> V_158 ) ;
F_47 ( V_143 -> V_143 , V_11 -> V_154 . V_155 ) ;
F_21 ( V_143 ) ;
return 1 ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_1 ,
const struct V_159 * V_160 ,
struct V_48 * V_49 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_152 * V_143 ;
T_1 V_3 = F_1 ( V_1 , V_160 -> V_2 ) ;
int V_33 = 0 ;
if ( F_23 ( V_49 ) )
return 0 ;
V_143 = F_74 ( V_11 , V_160 -> V_142 , V_160 -> V_2 ) ;
if ( ! V_143 ) {
V_143 = F_77 ( V_11 , V_160 -> V_142 , V_160 -> V_2 ) ;
if ( ! V_143 ) {
F_28 ( V_7 , L_14 ) ;
return - V_44 ;
}
}
V_143 -> V_157 ++ ;
V_33 = F_71 ( V_1 , V_143 -> V_143 , true ,
V_143 -> V_157 == 1 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_15 ) ;
goto V_161;
}
if ( V_143 -> V_157 == 1 ) {
V_33 = F_69 ( V_11 , V_160 -> V_142 , V_3 , V_143 -> V_143 ,
true ) ;
if ( V_33 ) {
F_28 ( V_7 , L_16 ) ;
goto V_161;
}
}
return 0 ;
V_161:
F_82 ( V_11 , V_143 ) ;
return V_33 ;
}
static int F_85 ( struct V_6 * V_7 ,
const struct V_162 * V_163 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_11 ( V_7 ) ;
int V_33 = 0 ;
V_1 = F_5 ( V_163 -> V_12 , V_1 ) ;
if ( ! V_1 )
return - V_13 ;
switch ( V_163 -> V_14 ) {
case V_164 :
if ( F_2 ( V_1 ) )
return 0 ;
V_33 = F_60 ( V_1 ,
F_86 ( V_163 ) ,
V_49 ) ;
break;
case V_165 :
V_33 = F_68 ( V_1 ,
F_87 ( V_163 ) ,
V_49 ) ;
break;
case V_166 :
V_33 = F_84 ( V_1 ,
F_88 ( V_163 ) ,
V_49 ) ;
break;
default:
V_33 = - V_28 ;
break;
}
return V_33 ;
}
static int F_89 ( struct V_6 * V_7 , T_1 V_102 ,
T_1 V_103 )
{
T_1 V_2 ;
int V_33 ;
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
V_33 = F_54 ( V_7 , 0 , V_2 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_1 ,
T_1 V_102 , T_1 V_103 , bool V_167 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
T_1 V_2 , V_5 ;
int V_33 ;
if ( ! V_167 && ! V_1 -> V_70 )
return F_89 ( V_7 , V_102 , V_103 ) ;
V_33 = F_55 ( V_1 , V_102 , V_103 ,
false , false ) ;
if ( V_33 ) {
F_28 ( V_7 , L_17 , V_102 ,
V_103 ) ;
return V_33 ;
}
if ( V_167 )
goto V_168;
V_5 = V_1 -> V_5 ;
if ( V_5 >= V_102 && V_5 <= V_103 ) {
V_33 = F_42 ( V_1 , 0 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_18 , V_5 ) ;
return V_33 ;
}
}
V_33 = F_25 ( V_1 , V_102 , V_103 ,
false , false ) ;
if ( V_33 ) {
F_28 ( V_7 , L_19 ) ;
return V_33 ;
}
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ ) {
V_33 = F_51 ( V_1 , V_2 ) ;
if ( V_33 ) {
F_28 ( V_7 , L_20 , V_2 ) ;
return V_33 ;
}
}
V_168:
for ( V_2 = V_102 ; V_2 <= V_103 ; V_2 ++ )
F_47 ( V_2 , V_1 -> V_116 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_1 ,
const struct V_119 * V_120 )
{
return F_90 ( V_1 ,
V_120 -> V_102 , V_120 -> V_103 , false ) ;
}
void F_92 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_18 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_90 ( V_1 , V_2 , V_2 , false ) ;
}
static int
F_93 ( struct V_1 * V_1 ,
const struct V_139 * V_140 )
{
T_1 V_3 = F_1 ( V_1 , V_140 -> V_2 ) ;
T_1 V_138 = 0 ;
if ( F_2 ( V_1 ) ) {
V_138 = F_16 ( V_1 ) ;
}
if ( ! V_1 -> V_141 )
return F_63 ( V_1 -> V_11 ,
V_1 -> V_45 ,
V_140 -> V_142 , V_3 ,
false , false ) ;
else
return F_66 ( V_1 -> V_11 ,
V_1 -> V_137 ,
V_140 -> V_142 , V_3 , V_138 ,
false , false ) ;
}
static int F_94 ( struct V_1 * V_1 ,
const struct V_159 * V_160 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_152 * V_143 ;
T_1 V_3 = F_1 ( V_1 , V_160 -> V_2 ) ;
T_1 V_153 ;
int V_33 = 0 ;
V_143 = F_74 ( V_11 , V_160 -> V_142 , V_160 -> V_2 ) ;
if ( ! V_143 ) {
F_28 ( V_7 , L_21 ) ;
return - V_13 ;
}
V_33 = F_71 ( V_1 , V_143 -> V_143 , false , false ) ;
if ( V_33 )
F_28 ( V_7 , L_22 ) ;
V_153 = V_143 -> V_143 ;
if ( F_82 ( V_11 , V_143 ) ) {
V_33 = F_69 ( V_11 , V_160 -> V_142 , V_3 , V_153 ,
false ) ;
if ( V_33 )
F_28 ( V_7 , L_23 ) ;
}
return V_33 ;
}
static int F_95 ( struct V_6 * V_7 ,
const struct V_162 * V_163 )
{
struct V_1 * V_1 = F_11 ( V_7 ) ;
int V_33 = 0 ;
V_1 = F_5 ( V_163 -> V_12 , V_1 ) ;
if ( ! V_1 )
return - V_13 ;
switch ( V_163 -> V_14 ) {
case V_164 :
if ( F_2 ( V_1 ) )
return 0 ;
V_33 = F_91 ( V_1 ,
F_86 ( V_163 ) ) ;
break;
case V_165 :
V_33 = F_93 ( V_1 ,
F_87 ( V_163 ) ) ;
break;
case V_166 :
V_33 = F_94 ( V_1 ,
F_88 ( V_163 ) ) ;
break;
default:
V_33 = - V_28 ;
break;
}
return V_33 ;
}
static struct V_1 * F_96 ( struct V_11 * V_11 ,
T_1 V_137 )
{
struct V_1 * V_1 ;
int V_147 ;
for ( V_147 = 0 ; V_147 < V_169 ; V_147 ++ ) {
V_1 = F_97 ( V_11 , V_137 , V_147 ) ;
if ( V_1 )
return V_1 ;
}
return NULL ;
}
static int F_98 ( struct V_1 * V_1 ,
struct V_139 * V_140 ,
T_4 * V_170 ,
struct V_6 * V_12 )
{
struct V_11 * V_11 = V_1 -> V_11 ;
struct V_1 * V_171 ;
T_1 V_172 = 0 ;
char * V_133 ;
char V_132 [ V_173 ] ;
T_1 V_3 ;
T_2 V_45 ;
T_1 V_137 ;
T_2 V_174 ;
int V_175 = 0 ;
int V_147 ;
int V_33 ;
V_133 = F_14 ( V_134 , V_43 ) ;
if ( ! V_133 )
return - V_44 ;
if ( F_2 ( V_1 ) ) {
T_1 V_171 ;
V_171 = F_3 ( V_1 ) ;
V_172 = F_4 ( V_171 ) ;
}
F_64 ( V_133 , V_176 , 0 ) ;
do {
F_99 ( V_133 , V_177 ) ;
V_33 = F_100 ( V_11 -> V_46 , F_20 ( V_136 ) , V_133 ) ;
if ( V_33 )
goto V_168;
V_174 = F_101 ( V_133 ) ;
if ( V_175 )
continue;
for ( V_147 = 0 ; V_147 < V_174 ; V_147 ++ ) {
switch ( F_102 ( V_133 , V_147 ) ) {
case V_178 :
F_103 ( V_133 , V_147 , V_132 , & V_3 ,
& V_45 ) ;
if ( V_45 == V_1 -> V_45 ) {
if ( V_172 && V_172 == V_3 )
V_140 -> V_2 = 0 ;
else if ( ! V_172 &&
! F_104 ( V_3 ) )
V_140 -> V_2 = V_3 ;
else
continue;
F_80 ( V_140 -> V_142 , V_132 ) ;
V_140 -> V_179 = V_180 ;
V_33 = V_170 ( & V_140 -> V_163 ) ;
if ( V_33 )
V_175 = V_33 ;
}
break;
case V_181 :
F_105 ( V_133 , V_147 ,
V_132 , & V_3 , & V_137 ) ;
V_171 = F_96 ( V_11 , V_137 ) ;
if ( V_171 && V_171 -> V_45 ==
V_1 -> V_45 ) {
if ( ! F_106 ( V_12 ) &&
! F_6 ( V_12 ) )
continue;
if ( V_172 && V_172 == V_3 )
V_140 -> V_2 = 0 ;
else if ( ! V_172 &&
! F_104 ( V_3 ) )
V_140 -> V_2 = V_3 ;
else
continue;
F_80 ( V_140 -> V_142 , V_132 ) ;
V_140 -> V_179 = V_180 ;
V_33 = V_170 ( & V_140 -> V_163 ) ;
if ( V_33 )
V_175 = V_33 ;
}
break;
}
}
} while ( V_174 == V_177 );
V_168:
F_21 ( V_133 ) ;
return V_175 ? V_175 : V_33 ;
}
static int F_107 ( struct V_1 * V_1 ,
struct V_119 * V_120 ,
T_4 * V_170 )
{
T_1 V_2 ;
int V_33 = 0 ;
if ( F_2 ( V_1 ) ) {
V_120 -> V_121 = 0 ;
V_120 -> V_102 = F_16 ( V_1 ) ;
V_120 -> V_103 = F_16 ( V_1 ) ;
return V_170 ( & V_120 -> V_163 ) ;
}
F_18 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_120 -> V_121 = 0 ;
if ( V_2 == V_1 -> V_5 )
V_120 -> V_121 |= V_123 ;
if ( F_59 ( V_2 , V_1 -> V_117 ) )
V_120 -> V_121 |= V_122 ;
V_120 -> V_102 = V_2 ;
V_120 -> V_103 = V_2 ;
V_33 = V_170 ( & V_120 -> V_163 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_108 ( struct V_6 * V_7 ,
struct V_162 * V_163 ,
T_4 * V_170 )
{
struct V_1 * V_1 = F_11 ( V_7 ) ;
int V_33 = 0 ;
V_1 = F_5 ( V_163 -> V_12 , V_1 ) ;
if ( ! V_1 )
return - V_13 ;
switch ( V_163 -> V_14 ) {
case V_164 :
V_33 = F_107 ( V_1 ,
F_86 ( V_163 ) , V_170 ) ;
break;
case V_165 :
V_33 = F_98 ( V_1 ,
F_87 ( V_163 ) , V_170 ,
V_163 -> V_12 ) ;
break;
default:
V_33 = - V_28 ;
break;
}
return V_33 ;
}
static void F_109 ( bool V_24 , bool V_129 ,
char * V_132 , T_1 V_2 ,
struct V_6 * V_7 )
{
struct V_182 V_183 ;
unsigned long V_184 ;
if ( V_24 ) {
V_183 . V_142 = V_132 ;
V_183 . V_2 = V_2 ;
V_184 = V_129 ? V_185 : V_186 ;
F_110 ( V_184 , V_7 , & V_183 . V_183 ) ;
}
}
static void F_111 ( struct V_11 * V_11 ,
char * V_187 , int V_188 ,
bool V_129 )
{
struct V_1 * V_1 ;
char V_132 [ V_173 ] ;
T_2 V_45 ;
T_1 V_2 , V_3 ;
bool V_189 = true ;
int V_33 ;
F_112 ( V_187 , V_188 , V_132 , & V_3 , & V_45 ) ;
V_1 = V_11 -> V_150 [ V_45 ] ;
if ( ! V_1 ) {
F_113 ( V_11 -> V_190 -> V_7 , L_24 ) ;
goto V_191;
}
if ( F_104 ( V_3 ) ) {
T_1 V_4 = F_114 ( V_3 ) ;
struct V_1 * V_8 ;
V_8 = F_115 ( V_1 ,
V_4 ) ;
if ( ! V_8 ) {
F_28 ( V_1 -> V_7 , L_25 ) ;
goto V_191;
}
V_2 = 0 ;
V_1 = V_8 ;
} else {
V_2 = V_3 ;
}
V_129 = V_129 && V_1 -> V_22 ;
V_192:
V_33 = F_63 ( V_11 , V_45 , V_132 , V_3 ,
V_129 , true ) ;
if ( V_33 ) {
if ( F_116 () )
F_28 ( V_1 -> V_7 , L_26 ) ;
return;
}
if ( ! V_189 )
return;
F_109 ( V_1 -> V_24 ,
V_129 , V_132 , V_2 , V_1 -> V_7 ) ;
return;
V_191:
V_129 = false ;
V_189 = false ;
goto V_192;
}
static void F_117 ( struct V_11 * V_11 ,
char * V_187 , int V_188 ,
bool V_129 )
{
struct V_1 * V_1 ;
struct V_6 * V_7 ;
char V_132 [ V_173 ] ;
T_1 V_138 = 0 ;
T_1 V_137 ;
T_1 V_2 , V_3 ;
bool V_189 = true ;
int V_33 ;
F_118 ( V_187 , V_188 , V_132 , & V_3 , & V_137 ) ;
V_1 = F_96 ( V_11 , V_137 ) ;
if ( ! V_1 ) {
F_113 ( V_11 -> V_190 -> V_7 , L_27 ) ;
goto V_191;
}
if ( F_104 ( V_3 ) ) {
T_1 V_4 = F_114 ( V_3 ) ;
struct V_1 * V_8 ;
V_8 = F_115 ( V_1 ,
V_4 ) ;
if ( ! V_8 ) {
F_28 ( V_1 -> V_7 , L_25 ) ;
goto V_191;
}
V_138 = F_16 ( V_8 ) ;
V_7 = V_8 -> V_7 ;
V_2 = 0 ;
V_1 = V_8 ;
} else {
V_7 = F_119 ( V_11 , V_137 ) -> V_7 ;
V_2 = V_3 ;
}
V_129 = V_129 && V_1 -> V_22 ;
V_192:
V_33 = F_66 ( V_11 , V_137 , V_132 , V_3 , V_138 ,
V_129 , true ) ;
if ( V_33 ) {
if ( F_116 () )
F_28 ( V_1 -> V_7 , L_26 ) ;
return;
}
if ( ! V_189 )
return;
F_109 ( V_1 -> V_24 , V_129 , V_132 ,
V_2 , V_7 ) ;
return;
V_191:
V_129 = false ;
V_189 = false ;
goto V_192;
}
static void F_120 ( struct V_11 * V_11 ,
char * V_187 , int V_188 )
{
switch ( F_121 ( V_187 , V_188 ) ) {
case V_193 :
F_111 ( V_11 , V_187 ,
V_188 , true ) ;
break;
case V_194 :
F_111 ( V_11 , V_187 ,
V_188 , false ) ;
break;
case V_195 :
F_117 ( V_11 , V_187 ,
V_188 , true ) ;
break;
case V_196 :
F_117 ( V_11 , V_187 ,
V_188 , false ) ;
break;
}
}
static void F_122 ( struct V_11 * V_11 )
{
F_123 ( & V_11 -> V_197 . V_198 ,
F_124 ( V_11 -> V_197 . V_199 ) ) ;
}
static void F_125 ( struct V_200 * V_201 )
{
struct V_11 * V_11 ;
char * V_187 ;
T_2 V_174 ;
int V_147 ;
int V_33 ;
V_187 = F_14 ( V_202 , V_43 ) ;
if ( ! V_187 )
return;
V_11 = F_126 ( V_201 , struct V_11 , V_197 . V_198 . V_201 ) ;
F_127 () ;
do {
F_128 ( V_187 ) ;
V_33 = F_100 ( V_11 -> V_46 , F_20 ( V_203 ) , V_187 ) ;
if ( V_33 ) {
F_113 ( V_11 -> V_190 -> V_7 , L_28 ) ;
break;
}
V_174 = F_129 ( V_187 ) ;
for ( V_147 = 0 ; V_147 < V_174 ; V_147 ++ )
F_120 ( V_11 , V_187 , V_147 ) ;
} while ( V_174 );
F_130 () ;
F_21 ( V_187 ) ;
F_122 ( V_11 ) ;
}
static int F_131 ( struct V_11 * V_11 )
{
int V_33 ;
V_33 = F_31 ( V_11 , V_204 ) ;
if ( V_33 ) {
F_132 ( V_11 -> V_190 -> V_7 , L_29 ) ;
return V_33 ;
}
F_133 ( & V_11 -> V_197 . V_198 , F_125 ) ;
V_11 -> V_197 . V_199 = V_205 ;
F_122 ( V_11 ) ;
return 0 ;
}
static void F_134 ( struct V_11 * V_11 )
{
F_135 ( & V_11 -> V_197 . V_198 ) ;
}
static void F_136 ( struct V_11 * V_11 )
{
T_1 V_3 ;
F_18 (fid, mlxsw_sp->active_fids, VLAN_N_VID)
F_46 ( V_11 , V_3 ) ;
}
int F_137 ( struct V_11 * V_11 )
{
return F_131 ( V_11 ) ;
}
void F_138 ( struct V_11 * V_11 )
{
F_134 ( V_11 ) ;
F_136 ( V_11 ) ;
}
int F_139 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
int V_33 ;
V_1 -> V_5 = 1 ;
V_33 = F_90 ( V_1 , 0 , V_206 - 1 ,
true ) ;
if ( V_33 ) {
F_28 ( V_7 , L_30 ) ;
return V_33 ;
}
V_33 = F_53 ( V_7 , 0 , 1 ) ;
if ( V_33 )
F_28 ( V_7 , L_31 ) ;
return V_33 ;
}
void F_140 ( struct V_1 * V_1 )
{
V_1 -> V_7 -> V_207 = & V_208 ;
}
void F_141 ( struct V_1 * V_1 )
{
}
