static T_1 F_1 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
T_1 V_5 = V_2 ;
V_5 = V_4 ? V_4 -> V_5 : V_5 ;
if ( ! V_5 )
V_5 = V_1 -> V_6 ;
return V_5 ;
}
static struct V_1 *
F_3 ( struct V_7 * V_8 ,
struct V_1 * V_1 )
{
struct V_1 * V_9 ;
T_1 V_2 ;
if ( ! F_4 ( V_8 ) )
return V_1 ;
V_2 = F_5 ( V_8 ) ;
V_9 = F_6 ( V_1 , V_2 ) ;
F_7 ( ! V_9 ) ;
return V_9 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_12 * V_12 = V_1 -> V_12 ;
V_1 = F_3 ( V_11 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_11 -> V_15 ) {
case V_16 :
V_11 -> V_17 . V_18 . V_19 = sizeof( V_12 -> V_20 ) ;
memcpy ( & V_11 -> V_17 . V_18 . V_15 , & V_12 -> V_20 ,
V_11 -> V_17 . V_18 . V_19 ) ;
break;
case V_21 :
V_11 -> V_17 . V_22 =
( V_1 -> V_23 ? V_24 : 0 ) |
( V_1 -> V_25 ? V_26 : 0 ) |
( V_1 -> V_27 ? V_28 : 0 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
T_2 V_30 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
enum V_31 V_32 ;
char * V_33 ;
T_1 V_2 ;
int V_34 ;
switch ( V_30 ) {
case V_35 :
V_32 = V_36 ;
break;
case V_37 :
V_32 = V_38 ;
break;
case V_39 :
case V_40 :
case V_41 :
V_32 = V_42 ;
break;
default:
F_11 () ;
}
V_33 = F_12 ( V_43 , V_44 ) ;
if ( ! V_33 )
return - V_45 ;
F_13 ( V_33 , V_1 -> V_46 ) ;
if ( F_14 ( V_1 ) ) {
V_2 = F_15 ( V_1 ) ;
F_16 ( V_33 , V_2 , V_32 ) ;
} else {
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_16 ( V_33 , V_2 , V_32 ) ;
}
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_48 ) , V_33 ) ;
F_20 ( V_33 ) ;
return V_34 ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
T_2 V_30 )
{
if ( F_22 ( V_50 ) )
return 0 ;
V_1 -> V_51 = V_30 ;
return F_10 ( V_1 , V_30 ) ;
}
static int F_23 ( struct V_1 * V_1 ,
T_1 V_52 , T_1 V_53 , bool V_54 ,
bool V_55 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
T_1 V_46 = V_1 -> V_46 ;
enum V_56 V_57 ;
T_1 V_58 = V_53 - V_52 + 1 ;
char * V_59 ;
int V_34 ;
if ( F_14 ( V_1 ) )
V_57 = V_60 ;
else
V_57 = V_61 ;
V_59 = F_12 ( V_62 , V_44 ) ;
if ( ! V_59 )
return - V_45 ;
F_24 ( V_59 , V_63 , V_52 ,
V_57 , V_58 , V_46 , V_54 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
if ( V_34 )
goto V_65;
F_24 ( V_59 , V_66 , V_52 ,
V_57 , V_58 , V_46 , V_55 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
if ( V_34 )
goto V_67;
goto V_65;
V_67:
F_24 ( V_59 , V_63 , V_52 ,
V_57 , V_58 , V_46 , ! V_54 ) ;
F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
V_65:
F_20 ( V_59 ) ;
return V_34 ;
}
static int F_25 ( struct V_1 * V_1 ,
bool V_68 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_69 ;
int V_34 ;
if ( F_14 ( V_1 ) ) {
T_1 V_5 = F_2 ( V_1 ) -> V_5 ;
T_1 V_70 = F_26 ( V_5 ) ;
return F_23 ( V_1 , V_70 , V_70 ,
V_68 , true ) ;
}
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_34 = F_23 ( V_1 , V_2 , V_2 , V_68 ,
true ) ;
if ( V_34 ) {
V_69 = V_2 ;
goto V_71;
}
}
return 0 ;
V_71:
F_17 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_23 ( V_1 , V_2 , V_2 , ! V_68 , true ) ;
F_27 ( V_8 , L_1 ) ;
return V_34 ;
}
int F_28 ( struct V_1 * V_9 , T_1 V_5 ,
bool V_68 )
{
T_1 V_70 ;
V_70 = F_26 ( V_5 ) ;
return F_23 ( V_9 , V_70 , V_70 , V_68 , V_68 ) ;
}
static int F_29 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_22 )
{
unsigned long V_27 = V_1 -> V_27 ? V_28 : 0 ;
bool V_68 ;
int V_34 ;
if ( ! V_1 -> V_72 )
return - V_14 ;
if ( F_22 ( V_50 ) )
return 0 ;
if ( ( V_27 ^ V_22 ) & V_28 ) {
V_68 = V_1 -> V_27 ? false : true ;
V_34 = F_25 ( V_1 , V_68 ) ;
if ( V_34 )
return V_34 ;
}
V_1 -> V_27 = V_22 & V_28 ? 1 : 0 ;
V_1 -> V_23 = V_22 & V_24 ? 1 : 0 ;
V_1 -> V_25 = V_22 & V_26 ? 1 : 0 ;
return 0 ;
}
static int F_30 ( struct V_12 * V_12 , T_3 V_73 )
{
char V_74 [ V_75 ] ;
int V_34 ;
F_31 ( V_74 , V_73 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_76 ) , V_74 ) ;
if ( V_34 )
return V_34 ;
V_12 -> V_73 = V_73 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_77 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
unsigned long V_78 = F_33 ( V_77 ) ;
T_3 V_73 = F_34 ( V_78 ) / 1000 ;
if ( F_22 ( V_50 ) ) {
if ( V_73 < V_79 ||
V_73 > V_80 )
return - V_81 ;
else
return 0 ;
}
return F_30 ( V_12 , V_73 ) ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
struct V_7 * V_13 ,
bool V_82 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
if ( ( ! V_82 ) && ( V_12 -> V_83 . V_8 == V_13 ) ) {
F_27 ( V_1 -> V_8 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 ,
const struct V_10 * V_11 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_11 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_11 -> V_15 ) {
case V_84 :
V_34 = F_21 ( V_1 , V_50 ,
V_11 -> V_17 . V_51 ) ;
break;
case V_21 :
V_34 = F_29 ( V_1 , V_50 ,
V_11 -> V_17 . V_22 ) ;
break;
case V_85 :
V_34 = F_32 ( V_1 , V_50 ,
V_11 -> V_17 . V_73 ) ;
break;
case V_86 :
V_34 = F_35 ( V_1 , V_50 ,
V_11 -> V_13 ,
V_11 -> V_17 . V_87 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_37 ( struct V_12 * V_12 , T_1 V_5 , bool V_88 )
{
char V_89 [ V_90 ] ;
F_38 ( V_89 , ! V_88 , V_5 , V_5 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_91 ) , V_89 ) ;
}
static int F_39 ( struct V_12 * V_12 , T_1 V_5 , bool V_92 )
{
enum V_93 V_94 = V_95 ;
char V_96 [ V_97 ] ;
F_40 ( V_96 , 0 , V_94 , V_92 , V_5 , V_5 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_98 ) , V_96 ) ;
}
static struct V_3 * F_41 ( T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_42 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_5 ;
return V_4 ;
}
struct V_3 * F_43 ( struct V_12 * V_12 , T_1 V_5 )
{
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_37 ( V_12 , V_5 , true ) ;
if ( V_34 )
return F_44 ( V_34 ) ;
V_34 = F_39 ( V_12 , V_5 , true ) ;
if ( V_34 )
goto V_99;
V_4 = F_41 ( V_5 ) ;
if ( ! V_4 ) {
V_34 = - V_45 ;
goto V_100;
}
F_45 ( & V_4 -> V_101 , & V_12 -> V_102 ) ;
return V_4 ;
V_100:
F_39 ( V_12 , V_5 , false ) ;
V_99:
F_37 ( V_12 , V_5 , false ) ;
return F_44 ( V_34 ) ;
}
void F_46 ( struct V_12 * V_12 , struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_5 ;
F_47 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_103 )
F_48 ( V_12 , V_4 -> V_103 ) ;
F_20 ( V_4 ) ;
F_39 ( V_12 , V_5 , false ) ;
F_37 ( V_12 , V_5 , false ) ;
}
static int F_49 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
if ( F_50 ( V_5 , V_1 -> V_104 ) )
return 0 ;
V_4 = F_51 ( V_1 -> V_12 , V_5 ) ;
if ( ! V_4 ) {
V_4 = F_43 ( V_1 -> V_12 , V_5 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
}
V_4 -> V_105 ++ ;
F_54 ( V_1 -> V_8 , L_3 , V_5 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_51 ( V_1 -> V_12 , V_5 ) ;
if ( F_7 ( ! V_4 ) )
return;
F_54 ( V_1 -> V_8 , L_4 , V_5 ) ;
F_56 ( V_1 , V_5 ) ;
if ( -- V_4 -> V_105 == 0 )
F_46 ( V_1 -> V_12 , V_4 ) ;
}
static int F_57 ( struct V_1 * V_1 , T_1 V_5 ,
bool V_92 )
{
enum V_93 V_94 = V_106 ;
if ( F_58 ( & V_1 -> V_107 ) )
return 0 ;
return F_59 ( V_1 , V_94 , V_92 , V_5 , V_5 ) ;
}
static int F_60 ( struct V_1 * V_1 ,
T_1 V_108 , T_1 V_109 )
{
int V_5 , V_34 ;
for ( V_5 = V_108 ; V_5 <= V_109 ; V_5 ++ ) {
V_34 = F_49 ( V_1 , V_5 ) ;
if ( V_34 )
goto V_110;
}
V_34 = F_23 ( V_1 , V_108 , V_109 ,
V_1 -> V_27 , true ) ;
if ( V_34 )
goto V_71;
for ( V_5 = V_108 ; V_5 <= V_109 ; V_5 ++ ) {
V_34 = F_57 ( V_1 , V_5 , true ) ;
if ( V_34 )
goto V_111;
}
return 0 ;
V_111:
for ( V_5 -- ; V_5 >= V_108 ; V_5 -- )
F_57 ( V_1 , V_5 , false ) ;
F_23 ( V_1 , V_108 , V_109 , false ,
false ) ;
V_71:
V_5 = V_109 ;
V_110:
for ( V_5 -- ; V_5 >= V_108 ; V_5 -- )
F_55 ( V_1 , V_5 ) ;
return V_34 ;
}
static void F_61 ( struct V_1 * V_1 ,
T_1 V_108 , T_1 V_109 )
{
int V_5 ;
for ( V_5 = V_108 ; V_5 <= V_109 ; V_5 ++ )
F_57 ( V_1 , V_5 , false ) ;
F_23 ( V_1 , V_108 , V_109 , false ,
false ) ;
for ( V_5 = V_108 ; V_5 <= V_109 ; V_5 ++ )
F_55 ( V_1 , V_5 ) ;
}
static int F_62 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char V_112 [ V_113 ] ;
F_63 ( V_112 , V_1 -> V_46 , V_2 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_114 ) , V_112 ) ;
}
static int F_64 ( struct V_1 * V_1 ,
bool V_115 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char V_116 [ V_117 ] ;
F_65 ( V_116 , V_1 -> V_46 , V_115 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_118 ) , V_116 ) ;
}
int F_66 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
int V_34 ;
if ( ! V_2 ) {
V_34 = F_64 ( V_1 , false ) ;
if ( V_34 ) {
F_27 ( V_8 , L_5 ) ;
return V_34 ;
}
} else {
V_34 = F_62 ( V_1 , V_2 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_6 ) ;
return V_34 ;
}
if ( ! V_1 -> V_6 ) {
V_34 = F_64 ( V_1 ,
true ) ;
if ( V_34 ) {
F_27 ( V_8 , L_7 ) ;
goto V_119;
}
}
}
V_1 -> V_6 = V_2 ;
return 0 ;
V_119:
F_62 ( V_1 , V_1 -> V_6 ) ;
return V_34 ;
}
static int F_67 ( struct V_1 * V_1 ,
T_1 V_120 , T_1 V_121 , bool V_122 ,
bool V_123 )
{
T_1 V_2 , V_124 ;
int V_34 ;
for ( V_2 = V_120 ; V_2 <= V_121 ;
V_2 += V_125 ) {
V_124 = F_68 ( ( T_1 ) ( V_2 + V_125 - 1 ) ,
V_121 ) ;
V_34 = F_69 ( V_1 , V_2 , V_124 ,
V_122 , V_123 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_1 ,
T_1 V_120 , T_1 V_121 ,
bool V_126 , bool V_127 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_128 ;
int V_34 ;
if ( ! V_1 -> V_72 )
return - V_14 ;
V_34 = F_60 ( V_1 , V_120 , V_121 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_8 ) ;
return V_34 ;
}
V_34 = F_67 ( V_1 , V_120 , V_121 ,
true , V_126 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_9 , V_120 ,
V_121 ) ;
goto V_129;
}
V_128 = V_1 -> V_6 ;
if ( V_127 && V_128 != V_120 ) {
V_34 = F_66 ( V_1 , V_120 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_10 , V_120 ) ;
goto V_130;
}
} else if ( ! V_127 && V_128 >= V_120 && V_128 <= V_121 ) {
V_34 = F_66 ( V_1 , 0 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_11 ) ;
goto V_130;
}
}
for ( V_2 = V_120 ; V_2 <= V_121 ; V_2 ++ ) {
F_71 ( V_2 , V_1 -> V_104 ) ;
if ( V_126 )
F_71 ( V_2 , V_1 -> V_131 ) ;
else
F_72 ( V_2 , V_1 -> V_131 ) ;
}
V_34 = F_10 ( V_1 ,
V_1 -> V_51 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_12 ) ;
goto V_132;
}
return 0 ;
V_132:
for ( V_2 = V_120 ; V_2 <= V_121 ; V_2 ++ )
F_72 ( V_2 , V_1 -> V_104 ) ;
if ( V_128 != V_1 -> V_6 )
F_66 ( V_1 , V_128 ) ;
V_130:
F_67 ( V_1 , V_120 , V_121 , false ,
false ) ;
V_129:
F_61 ( V_1 , V_120 , V_121 ) ;
return V_34 ;
}
static int F_73 ( struct V_1 * V_1 ,
const struct V_133 * V_134 ,
struct V_49 * V_50 )
{
bool V_126 = V_134 -> V_135 & V_136 ;
bool V_127 = V_134 -> V_135 & V_137 ;
if ( F_22 ( V_50 ) )
return 0 ;
return F_70 ( V_1 ,
V_134 -> V_120 , V_134 -> V_121 ,
V_126 , V_127 ) ;
}
static enum V_138 F_74 ( bool V_139 )
{
return V_139 ? V_140 :
V_141 ;
}
static enum V_142 F_75 ( bool V_143 )
{
return V_143 ? V_144 :
V_145 ;
}
static int F_76 ( struct V_12 * V_12 , T_2 V_46 ,
const char * V_146 , T_1 V_5 , bool V_143 ,
enum V_147 V_148 ,
bool V_139 )
{
char * V_149 ;
int V_34 ;
V_149 = F_12 ( V_150 , V_44 ) ;
if ( ! V_149 )
return - V_45 ;
F_77 ( V_149 , F_75 ( V_143 ) , 0 ) ;
F_78 ( V_149 , 0 , F_74 ( V_139 ) ,
V_146 , V_5 , V_148 , V_46 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_151 ) , V_149 ) ;
F_20 ( V_149 ) ;
return V_34 ;
}
static int F_79 ( struct V_12 * V_12 , T_2 V_46 ,
const char * V_146 , T_1 V_5 , bool V_143 ,
bool V_139 )
{
return F_76 ( V_12 , V_46 , V_146 , V_5 , V_143 ,
V_152 , V_139 ) ;
}
int F_80 ( struct V_12 * V_12 , const char * V_146 , T_1 V_5 ,
bool V_143 )
{
return F_76 ( V_12 , 0 , V_146 , V_5 , V_143 ,
V_153 ,
false ) ;
}
static int F_81 ( struct V_12 * V_12 , T_1 V_154 ,
const char * V_146 , T_1 V_5 , T_1 V_155 ,
bool V_143 , bool V_139 )
{
char * V_149 ;
int V_34 ;
V_149 = F_12 ( V_150 , V_44 ) ;
if ( ! V_149 )
return - V_45 ;
F_77 ( V_149 , F_75 ( V_143 ) , 0 ) ;
F_82 ( V_149 , 0 , F_74 ( V_139 ) ,
V_146 , V_5 , V_152 ,
V_155 , V_154 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_151 ) , V_149 ) ;
F_20 ( V_149 ) ;
return V_34 ;
}
static int
F_83 ( struct V_1 * V_1 ,
const struct V_156 * V_157 ,
struct V_49 * V_50 )
{
T_1 V_5 = F_1 ( V_1 , V_157 -> V_2 ) ;
T_1 V_155 = 0 ;
if ( F_22 ( V_50 ) )
return 0 ;
if ( F_14 ( V_1 ) ) {
V_155 = F_15 ( V_1 ) ;
}
if ( ! V_1 -> V_158 )
return F_79 ( V_1 -> V_12 ,
V_1 -> V_46 ,
V_157 -> V_159 , V_5 , true , false ) ;
else
return F_81 ( V_1 -> V_12 ,
V_1 -> V_154 ,
V_157 -> V_159 , V_5 , V_155 ,
true , false ) ;
}
static int F_84 ( struct V_12 * V_12 , const char * V_159 ,
T_1 V_5 , T_1 V_160 , bool V_143 )
{
char * V_149 ;
int V_34 ;
V_149 = F_12 ( V_150 , V_44 ) ;
if ( ! V_149 )
return - V_45 ;
F_77 ( V_149 , F_75 ( V_143 ) , 0 ) ;
F_85 ( V_149 , 0 , V_159 , V_5 ,
V_152 , V_160 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_151 ) , V_149 ) ;
F_20 ( V_149 ) ;
return V_34 ;
}
static int F_86 ( struct V_1 * V_1 , T_1 V_160 ,
bool V_161 , bool V_162 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char * V_163 ;
int V_34 , V_164 ;
V_163 = F_12 ( V_165 , V_44 ) ;
if ( ! V_163 )
return - V_45 ;
F_87 ( V_163 , V_160 , V_1 -> V_46 , V_161 ) ;
if ( V_162 ) {
for ( V_164 = 1 ; V_164 < V_166 ; V_164 ++ )
if ( V_12 -> V_167 [ V_164 ] )
F_88 ( V_163 , V_164 , 1 ) ;
}
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_168 ) , V_163 ) ;
F_20 ( V_163 ) ;
return V_34 ;
}
static struct V_169 * F_89 ( struct V_12 * V_12 ,
const unsigned char * V_159 ,
T_1 V_2 )
{
struct V_169 * V_160 ;
F_90 (mid, &mlxsw_sp->br_mids.list, list) {
if ( F_91 ( V_160 -> V_159 , V_159 ) && V_160 -> V_2 == V_2 )
return V_160 ;
}
return NULL ;
}
static struct V_169 * F_92 ( struct V_12 * V_12 ,
const unsigned char * V_159 ,
T_1 V_2 )
{
struct V_169 * V_160 ;
T_1 V_170 ;
V_170 = F_93 ( V_12 -> V_171 . V_172 ,
V_173 ) ;
if ( V_170 == V_173 )
return NULL ;
V_160 = F_42 ( sizeof( * V_160 ) , V_44 ) ;
if ( ! V_160 )
return NULL ;
F_71 ( V_170 , V_12 -> V_171 . V_172 ) ;
F_94 ( V_160 -> V_159 , V_159 ) ;
V_160 -> V_2 = V_2 ;
V_160 -> V_160 = V_170 ;
V_160 -> V_105 = 0 ;
F_95 ( & V_160 -> V_101 , & V_12 -> V_171 . V_101 ) ;
return V_160 ;
}
static int F_96 ( struct V_12 * V_12 ,
struct V_169 * V_160 )
{
if ( -- V_160 -> V_105 == 0 ) {
F_47 ( & V_160 -> V_101 ) ;
F_72 ( V_160 -> V_160 , V_12 -> V_171 . V_172 ) ;
F_20 ( V_160 ) ;
return 1 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_1 ,
const struct V_174 * V_175 ,
struct V_49 * V_50 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_169 * V_160 ;
T_1 V_5 = F_1 ( V_1 , V_175 -> V_2 ) ;
int V_34 = 0 ;
if ( F_22 ( V_50 ) )
return 0 ;
V_160 = F_89 ( V_12 , V_175 -> V_159 , V_175 -> V_2 ) ;
if ( ! V_160 ) {
V_160 = F_92 ( V_12 , V_175 -> V_159 , V_175 -> V_2 ) ;
if ( ! V_160 ) {
F_27 ( V_8 , L_13 ) ;
return - V_45 ;
}
}
V_160 -> V_105 ++ ;
V_34 = F_86 ( V_1 , V_160 -> V_160 , true ,
V_160 -> V_105 == 1 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_14 ) ;
goto V_176;
}
if ( V_160 -> V_105 == 1 ) {
V_34 = F_84 ( V_12 , V_175 -> V_159 , V_5 , V_160 -> V_160 ,
true ) ;
if ( V_34 ) {
F_27 ( V_8 , L_15 ) ;
goto V_176;
}
}
return 0 ;
V_176:
F_96 ( V_12 , V_160 ) ;
return V_34 ;
}
static int F_98 ( struct V_7 * V_8 ,
const struct V_177 * V_178 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_178 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_178 -> V_15 ) {
case V_179 :
if ( F_14 ( V_1 ) )
return 0 ;
V_34 = F_73 ( V_1 ,
F_99 ( V_178 ) ,
V_50 ) ;
break;
case V_180 :
V_34 = F_100 ( V_1 ,
F_101 ( V_178 ) ,
V_50 ) ;
break;
case V_181 :
V_34 = F_83 ( V_1 ,
F_102 ( V_178 ) ,
V_50 ) ;
break;
case V_182 :
V_34 = F_97 ( V_1 ,
F_103 ( V_178 ) ,
V_50 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_104 ( struct V_1 * V_1 ,
T_1 V_120 , T_1 V_121 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_6 ;
int V_34 ;
if ( ! V_1 -> V_72 )
return - V_14 ;
V_34 = F_67 ( V_1 , V_120 , V_121 ,
false , false ) ;
if ( V_34 ) {
F_27 ( V_8 , L_16 , V_120 ,
V_121 ) ;
return V_34 ;
}
V_6 = V_1 -> V_6 ;
if ( V_6 >= V_120 && V_6 <= V_121 ) {
V_34 = F_66 ( V_1 , 0 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_17 , V_6 ) ;
return V_34 ;
}
}
F_61 ( V_1 , V_120 , V_121 ) ;
for ( V_2 = V_120 ; V_2 <= V_121 ; V_2 ++ )
F_72 ( V_2 , V_1 -> V_104 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_1 ,
const struct V_133 * V_134 )
{
return F_104 ( V_1 , V_134 -> V_120 ,
V_134 -> V_121 ) ;
}
void F_106 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_104 ( V_1 , V_2 , V_2 ) ;
}
static int
F_107 ( struct V_1 * V_1 ,
const struct V_156 * V_157 )
{
T_1 V_5 = F_1 ( V_1 , V_157 -> V_2 ) ;
T_1 V_155 = 0 ;
if ( F_14 ( V_1 ) ) {
V_155 = F_15 ( V_1 ) ;
}
if ( ! V_1 -> V_158 )
return F_79 ( V_1 -> V_12 ,
V_1 -> V_46 ,
V_157 -> V_159 , V_5 ,
false , false ) ;
else
return F_81 ( V_1 -> V_12 ,
V_1 -> V_154 ,
V_157 -> V_159 , V_5 , V_155 ,
false , false ) ;
}
static int F_108 ( struct V_1 * V_1 ,
const struct V_174 * V_175 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_169 * V_160 ;
T_1 V_5 = F_1 ( V_1 , V_175 -> V_2 ) ;
T_1 V_170 ;
int V_34 = 0 ;
V_160 = F_89 ( V_12 , V_175 -> V_159 , V_175 -> V_2 ) ;
if ( ! V_160 ) {
F_27 ( V_8 , L_18 ) ;
return - V_14 ;
}
V_34 = F_86 ( V_1 , V_160 -> V_160 , false , false ) ;
if ( V_34 )
F_27 ( V_8 , L_19 ) ;
V_170 = V_160 -> V_160 ;
if ( F_96 ( V_12 , V_160 ) ) {
V_34 = F_84 ( V_12 , V_175 -> V_159 , V_5 , V_170 ,
false ) ;
if ( V_34 )
F_27 ( V_8 , L_20 ) ;
}
return V_34 ;
}
static int F_109 ( struct V_7 * V_8 ,
const struct V_177 * V_178 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_178 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_178 -> V_15 ) {
case V_179 :
if ( F_14 ( V_1 ) )
return 0 ;
V_34 = F_105 ( V_1 ,
F_99 ( V_178 ) ) ;
break;
case V_180 :
V_34 = F_110 ( V_1 ,
F_101 ( V_178 ) ) ;
break;
case V_181 :
V_34 = F_107 ( V_1 ,
F_102 ( V_178 ) ) ;
break;
case V_182 :
V_34 = F_108 ( V_1 ,
F_103 ( V_178 ) ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static struct V_1 * F_111 ( struct V_12 * V_12 ,
T_1 V_154 )
{
struct V_1 * V_1 ;
int V_164 ;
for ( V_164 = 0 ; V_164 < V_183 ; V_164 ++ ) {
V_1 = F_112 ( V_12 , V_154 , V_164 ) ;
if ( V_1 )
return V_1 ;
}
return NULL ;
}
static int F_113 ( struct V_1 * V_1 ,
struct V_156 * V_157 ,
T_4 * V_184 ,
struct V_7 * V_13 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_1 * V_185 ;
struct V_3 * V_4 ;
T_1 V_186 ;
char * V_149 ;
char V_146 [ V_187 ] ;
T_1 V_5 ;
T_2 V_46 ;
T_1 V_154 ;
T_2 V_188 ;
int V_189 = 0 ;
int V_164 ;
int V_34 ;
V_149 = F_12 ( V_150 , V_44 ) ;
if ( ! V_149 )
return - V_45 ;
V_4 = F_2 ( V_1 ) ;
V_186 = V_4 ? V_4 -> V_5 : 0 ;
F_77 ( V_149 , V_190 , 0 ) ;
do {
F_114 ( V_149 , V_191 ) ;
V_34 = F_115 ( V_12 -> V_47 , F_19 ( V_151 ) , V_149 ) ;
if ( V_34 )
goto V_192;
V_188 = F_116 ( V_149 ) ;
if ( V_189 )
continue;
for ( V_164 = 0 ; V_164 < V_188 ; V_164 ++ ) {
switch ( F_117 ( V_149 , V_164 ) ) {
case V_193 :
F_118 ( V_149 , V_164 , V_146 , & V_5 ,
& V_46 ) ;
if ( V_46 == V_1 -> V_46 ) {
if ( V_186 && V_186 == V_5 )
V_157 -> V_2 = 0 ;
else if ( ! V_186 &&
! F_119 ( V_5 ) )
V_157 -> V_2 = V_5 ;
else
continue;
F_94 ( V_157 -> V_159 , V_146 ) ;
V_157 -> V_194 = V_195 ;
V_34 = V_184 ( & V_157 -> V_178 ) ;
if ( V_34 )
V_189 = V_34 ;
}
break;
case V_196 :
F_120 ( V_149 , V_164 ,
V_146 , & V_5 , & V_154 ) ;
V_185 = F_111 ( V_12 , V_154 ) ;
if ( V_185 && V_185 -> V_46 ==
V_1 -> V_46 ) {
if ( ! F_121 ( V_13 ) &&
! F_4 ( V_13 ) )
continue;
if ( V_186 && V_186 == V_5 )
V_157 -> V_2 = 0 ;
else if ( ! V_186 &&
! F_119 ( V_5 ) )
V_157 -> V_2 = V_5 ;
else
continue;
F_94 ( V_157 -> V_159 , V_146 ) ;
V_157 -> V_194 = V_195 ;
V_34 = V_184 ( & V_157 -> V_178 ) ;
if ( V_34 )
V_189 = V_34 ;
}
break;
}
}
} while ( V_188 == V_191 );
V_192:
F_20 ( V_149 ) ;
return V_189 ? V_189 : V_34 ;
}
static int F_122 ( struct V_1 * V_1 ,
struct V_133 * V_134 ,
T_4 * V_184 )
{
T_1 V_2 ;
int V_34 = 0 ;
if ( F_14 ( V_1 ) ) {
V_134 -> V_135 = 0 ;
V_134 -> V_120 = F_15 ( V_1 ) ;
V_134 -> V_121 = F_15 ( V_1 ) ;
return V_184 ( & V_134 -> V_178 ) ;
}
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_134 -> V_135 = 0 ;
if ( V_2 == V_1 -> V_6 )
V_134 -> V_135 |= V_137 ;
if ( F_50 ( V_2 , V_1 -> V_131 ) )
V_134 -> V_135 |= V_136 ;
V_134 -> V_120 = V_2 ;
V_134 -> V_121 = V_2 ;
V_34 = V_184 ( & V_134 -> V_178 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static int F_123 ( struct V_7 * V_8 ,
struct V_177 * V_178 ,
T_4 * V_184 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_178 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_178 -> V_15 ) {
case V_179 :
V_34 = F_122 ( V_1 ,
F_99 ( V_178 ) , V_184 ) ;
break;
case V_181 :
V_34 = F_113 ( V_1 ,
F_102 ( V_178 ) , V_184 ,
V_178 -> V_13 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static void F_124 ( bool V_25 , bool V_143 ,
char * V_146 , T_1 V_2 ,
struct V_7 * V_8 )
{
struct V_197 V_198 ;
unsigned long V_199 ;
if ( V_25 ) {
V_198 . V_159 = V_146 ;
V_198 . V_2 = V_2 ;
V_199 = V_143 ? V_200 : V_201 ;
F_125 ( V_199 , V_8 , & V_198 . V_198 ) ;
}
}
static void F_126 ( struct V_12 * V_12 ,
char * V_202 , int V_203 ,
bool V_143 )
{
struct V_1 * V_1 ;
char V_146 [ V_187 ] ;
T_2 V_46 ;
T_1 V_2 , V_5 ;
bool V_204 = true ;
int V_34 ;
F_127 ( V_202 , V_203 , V_146 , & V_5 , & V_46 ) ;
V_1 = V_12 -> V_167 [ V_46 ] ;
if ( ! V_1 ) {
F_128 ( V_12 -> V_205 -> V_8 , L_21 ) ;
goto V_206;
}
if ( F_119 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_129 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_27 ( V_1 -> V_8 , L_22 ) ;
goto V_206;
}
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_2 = V_5 ;
}
V_143 = V_143 && V_1 -> V_23 ;
V_207:
V_34 = F_79 ( V_12 , V_46 , V_146 , V_5 ,
V_143 , true ) ;
if ( V_34 ) {
if ( F_130 () )
F_27 ( V_1 -> V_8 , L_23 ) ;
return;
}
if ( ! V_204 )
return;
F_124 ( V_1 -> V_25 ,
V_143 , V_146 , V_2 , V_1 -> V_8 ) ;
return;
V_206:
V_143 = false ;
V_204 = false ;
goto V_207;
}
static void F_131 ( struct V_12 * V_12 ,
char * V_202 , int V_203 ,
bool V_143 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
char V_146 [ V_187 ] ;
T_1 V_155 = 0 ;
T_1 V_154 ;
T_1 V_2 , V_5 ;
bool V_204 = true ;
int V_34 ;
F_132 ( V_202 , V_203 , V_146 , & V_5 , & V_154 ) ;
V_1 = F_111 ( V_12 , V_154 ) ;
if ( ! V_1 ) {
F_128 ( V_12 -> V_205 -> V_8 , L_24 ) ;
goto V_206;
}
if ( F_119 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_129 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_27 ( V_1 -> V_8 , L_22 ) ;
goto V_206;
}
V_155 = F_15 ( V_9 ) ;
V_8 = V_9 -> V_8 ;
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_8 = F_133 ( V_12 , V_154 ) -> V_8 ;
V_2 = V_5 ;
}
V_143 = V_143 && V_1 -> V_23 ;
V_207:
V_34 = F_81 ( V_12 , V_154 , V_146 , V_5 , V_155 ,
V_143 , true ) ;
if ( V_34 ) {
if ( F_130 () )
F_27 ( V_1 -> V_8 , L_23 ) ;
return;
}
if ( ! V_204 )
return;
F_124 ( V_1 -> V_25 , V_143 , V_146 ,
V_2 , V_8 ) ;
return;
V_206:
V_143 = false ;
V_204 = false ;
goto V_207;
}
static void F_134 ( struct V_12 * V_12 ,
char * V_202 , int V_203 )
{
switch ( F_135 ( V_202 , V_203 ) ) {
case V_208 :
F_126 ( V_12 , V_202 ,
V_203 , true ) ;
break;
case V_209 :
F_126 ( V_12 , V_202 ,
V_203 , false ) ;
break;
case V_210 :
F_131 ( V_12 , V_202 ,
V_203 , true ) ;
break;
case V_211 :
F_131 ( V_12 , V_202 ,
V_203 , false ) ;
break;
}
}
static void F_136 ( struct V_12 * V_12 )
{
F_137 ( & V_12 -> V_212 . V_213 ,
F_138 ( V_12 -> V_212 . V_214 ) ) ;
}
static void F_139 ( struct V_215 * V_216 )
{
struct V_12 * V_12 ;
char * V_202 ;
T_2 V_188 ;
int V_164 ;
int V_34 ;
V_202 = F_12 ( V_217 , V_44 ) ;
if ( ! V_202 )
return;
V_12 = F_140 ( V_216 , struct V_12 , V_212 . V_213 . V_216 ) ;
F_141 () ;
do {
F_142 ( V_202 ) ;
V_34 = F_115 ( V_12 -> V_47 , F_19 ( V_218 ) , V_202 ) ;
if ( V_34 ) {
F_128 ( V_12 -> V_205 -> V_8 , L_25 ) ;
break;
}
V_188 = F_143 ( V_202 ) ;
for ( V_164 = 0 ; V_164 < V_188 ; V_164 ++ )
F_134 ( V_12 , V_202 , V_164 ) ;
} while ( V_188 );
F_144 () ;
F_20 ( V_202 ) ;
F_136 ( V_12 ) ;
}
static int F_145 ( struct V_12 * V_12 )
{
int V_34 ;
V_34 = F_30 ( V_12 , V_219 ) ;
if ( V_34 ) {
F_146 ( V_12 -> V_205 -> V_8 , L_26 ) ;
return V_34 ;
}
F_147 ( & V_12 -> V_212 . V_213 , F_139 ) ;
V_12 -> V_212 . V_214 = V_220 ;
F_136 ( V_12 ) ;
return 0 ;
}
static void F_148 ( struct V_12 * V_12 )
{
F_149 ( & V_12 -> V_212 . V_213 ) ;
}
int F_150 ( struct V_12 * V_12 )
{
return F_145 ( V_12 ) ;
}
void F_151 ( struct V_12 * V_12 )
{
F_148 ( V_12 ) ;
}
void F_152 ( struct V_1 * V_1 )
{
V_1 -> V_8 -> V_221 = & V_222 ;
}
void F_153 ( struct V_1 * V_1 )
{
}
