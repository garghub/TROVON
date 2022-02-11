void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = & V_2 -> V_8 ;
F_2 ( L_1 ,
V_3 , V_2 , V_2 -> V_12 , V_2 -> V_13 , V_8 ) ;
F_2 ( L_2 ,
V_3 , V_2 , V_8 -> V_14 ,
V_8 -> V_15 , V_8 -> V_16 ) ;
F_3 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, count)
F_2 ( L_3
L_4 ,
V_3 , V_2 , V_10 ,
F_4 ( V_10 ) , V_10 -> V_17 , V_10 -> V_18 ) ;
V_7 = V_2 -> V_13 ;
if ( V_7 ) {
V_5 = F_5 ( V_7 ) ;
F_2 ( L_5
L_6 ,
V_3 , V_2 , V_5 -> V_19 , V_5 -> V_20 , V_5 -> V_21 , V_5 -> V_22 ,
V_7 -> V_23 , V_5 -> V_24 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
if ( ! V_2 )
return;
V_26 = V_2 -> V_29 ;
V_28 = F_7 ( V_26 ) ;
if ( F_8 ( V_26 ) )
V_28 -> V_30 . V_31 ( F_8 ( V_26 ) ) ;
F_9 ( V_26 ) ;
F_10 ( V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
}
void F_12 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
F_6 ( V_2 ) ;
}
int F_14 ( struct V_8 * V_8 )
{
F_15 ( V_8 , 0 ) ;
return 1 ;
}
int F_16 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
struct V_25 * V_26 ;
struct V_32 * V_33 ;
struct V_27 * V_28 ;
struct V_4 * V_5 ;
T_1 V_34 ;
if ( V_2 -> V_35 )
return 0 ;
F_1 ( V_2 , V_36 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_28 = V_5 -> V_37 ;
V_34 = sizeof( * V_33 ) + V_8 -> V_38 ;
V_26 = F_17 ( V_28 , V_34 ) ;
if ( ! V_26 ) {
return 0 ;
}
V_33 = F_18 ( V_26 , V_34 ) ;
memset ( V_33 , 0 , V_34 ) ;
V_33 -> V_39 . V_40 = V_8 -> V_41 ;
V_34 = V_8 -> V_38 ;
if ( V_34 ) {
V_33 -> V_39 . V_42 |= V_43 ;
V_33 -> V_44 . V_45 = F_19 ( V_34 ) ;
memcpy ( ( V_33 + 1 ) , V_8 -> V_46 , V_34 ) ;
}
if ( V_8 -> V_16 & ( V_47 | V_48 ) ) {
if ( V_8 -> V_16 & V_47 )
V_33 -> V_39 . V_42 |= V_49 ;
else
V_33 -> V_39 . V_42 |= V_50 ;
V_33 -> V_44 . V_51 = F_20 ( V_8 -> V_52 ) ;
}
V_2 -> V_13 = V_28 -> V_30 . V_53 ( V_2 -> V_13 ) ;
F_21 ( V_26 , V_54 , V_5 -> V_20 , V_5 -> V_19 , V_55 ,
V_56 | V_57 | V_58 , 0 ) ;
V_28 -> V_30 . V_59 ( V_28 , V_2 -> V_13 , V_26 ) ;
V_28 -> V_30 . V_60 ( V_2 -> V_13 ) ;
return 0 ;
}
int F_22 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_61 != V_8 -> V_15 ;
}
int F_23 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
struct V_25 * V_26 ;
struct V_62 * V_63 ;
struct V_27 * V_28 ;
struct V_4 * V_5 ;
struct V_64 * V_65 ;
T_2 V_66 ;
F_1 ( V_2 , V_36 ) ;
if ( V_2 -> V_35 )
return 0 ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_28 = V_5 -> V_37 ;
V_26 = F_17 ( V_28 , sizeof( * V_63 ) ) ;
if ( ! V_26 )
return - V_67 ;
V_63 = F_18 ( V_26 , sizeof( * V_63 ) ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_68 = F_19 ( V_8 -> V_15 ) ;
V_2 -> V_13 = V_28 -> V_30 . V_53 ( V_2 -> V_13 ) ;
F_21 ( V_26 , V_69 , V_5 -> V_20 , V_5 -> V_19 , V_55 ,
V_56 | V_58 | V_70 , 0 ) ;
V_65 = F_24 ( V_26 ) ;
V_66 = F_25 ( V_65 -> V_71 ) ;
if ( V_66 & V_56 ) {
if ( ( V_5 -> V_72 <= V_28 -> V_73 ) &&
( V_65 -> V_74 == V_69 ) ) {
if ( V_8 -> V_16 & V_75 ) {
F_26 ( V_8 ) ;
V_2 -> V_10 = V_8 -> V_76 ;
V_2 -> V_77 =
V_8 -> V_78 ;
}
if ( V_2 -> V_10 && V_28 -> V_30 . V_79 ( V_28 , V_5 -> V_72 ,
V_2 -> V_10 ,
V_2 -> V_77 ) )
V_2 -> V_80 = 1 ;
}
}
V_28 -> V_30 . V_59 ( V_28 , V_2 -> V_13 , V_26 ) ;
return 0 ;
}
T_2 F_27 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
return F_5 ( V_2 -> V_13 ) -> V_22 ;
}
int F_28 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_29 ( struct V_6 * V_7 , struct V_25 * V_26 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
struct V_64 * V_65 ;
if ( F_30 ( F_31 ( V_26 ) ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_35 = true ;
return;
}
V_65 = F_24 ( V_26 ) ;
switch ( V_65 -> V_74 ) {
case V_82 :
F_32 ( V_2 , V_26 ) ;
break;
case V_83 :
case V_84 :
case V_69 :
default:
F_2 ( L_7 ,
V_36 , V_65 -> V_74 ) ;
F_33 ( V_2 ) ;
F_9 ( V_26 ) ;
F_15 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_34 ( struct V_27 * V_28 ,
const struct V_25 * V_85 ,
T_2 V_86 , enum V_87 V_88 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
const struct V_64 * V_65 ;
T_1 V_34 ;
struct V_32 * V_33 ;
struct V_89 * V_90 ;
V_65 = F_24 ( V_85 ) ;
F_2 ( L_8 ,
F_25 ( V_65 -> V_91 ) , F_35 ( V_65 -> V_92 ) , V_86 , V_88 ) ;
V_34 = sizeof( * V_33 ) ;
if ( V_86 == V_93 )
V_34 += sizeof( * V_90 ) ;
V_26 = F_17 ( V_28 , V_34 ) ;
if ( ! V_26 )
return;
V_33 = F_18 ( V_26 , V_34 ) ;
memset ( V_33 , 0 , V_34 ) ;
V_33 -> V_39 . V_40 = V_86 ;
if ( V_86 == V_93 ) {
V_33 -> V_44 . V_94 = F_19 ( sizeof( * V_90 ) ) ;
V_33 -> V_39 . V_42 |= V_95 ;
V_90 = (struct V_89 * ) ( V_33 + 1 ) ;
V_90 -> V_96 = V_88 ;
}
F_36 ( V_26 , V_85 , V_54 , 0 ) ;
V_7 = F_8 ( V_26 ) ;
if ( V_7 ) {
V_28 -> V_30 . V_59 ( V_28 , V_7 , V_26 ) ;
V_28 -> V_30 . V_60 ( V_7 ) ;
} else {
V_28 -> V_30 . V_97 ( V_28 , V_26 ) ;
}
}
static void F_37 ( struct V_1 * V_2 ,
enum V_87 V_88 )
{
F_34 ( V_2 -> V_12 -> V_98 -> V_28 ,
V_2 -> V_29 , V_93 , V_88 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
enum V_87 V_88 )
{
F_37 ( V_2 , V_88 ) ;
F_6 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_99 * V_33 ;
int V_100 ;
T_3 V_101 ;
V_33 = F_18 ( V_2 -> V_29 , sizeof( * V_33 ) ) ;
switch ( V_33 -> V_102 ) {
case V_103 :
V_101 = V_104 ;
break;
case V_105 :
V_101 = V_106 ;
break;
case V_107 :
V_101 = V_108 ;
break;
case V_109 :
V_101 = V_110 ;
break;
case V_111 :
V_101 = V_112 ;
break;
default:
F_2 ( L_9 , V_33 -> V_102 ) ;
F_38 ( V_2 , V_113 ) ;
return;
}
V_100 = F_40 ( & V_2 -> V_8 , V_2 -> V_12 -> V_114 ,
& V_2 -> V_115 [ 0 ] , F_41 ( & V_33 -> V_116 ) ,
V_2 , V_101 , V_117 , 0 , 0 ) ;
if ( V_100 < 0 )
F_38 ( V_2 , V_118 ) ;
}
int F_42 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
struct V_119 * V_120 = V_8 -> V_119 ;
enum V_87 V_88 ;
if ( V_2 -> V_35 )
return 0 ;
switch ( V_120 -> V_121 ) {
case V_122 :
V_88 = V_123 ;
break;
case V_124 :
V_88 = V_125 ;
break;
case V_126 :
V_88 = V_127 ;
break;
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
default:
V_88 = V_118 ;
break;
}
F_2 ( L_10 ,
V_120 -> V_133 , V_120 -> V_121 , V_88 ) ;
F_37 ( V_2 , V_88 ) ;
return 0 ;
}
static void F_43 ( struct V_134 * V_12 , struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = V_12 -> V_98 -> V_28 ;
V_2 = F_44 ( sizeof( * V_2 ) , V_135 ) ;
if ( ! V_2 )
goto V_136;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_28 -> V_30 . V_137 ( V_28 , V_26 ) ;
if ( ! V_2 -> V_13 ) {
F_11 ( V_2 ) ;
goto V_136;
}
V_2 -> V_29 = V_26 ;
F_45 ( & V_2 -> V_138 , V_139 ) ;
F_46 ( V_12 -> V_98 -> V_140 -> V_141 , & V_2 -> V_138 ) ;
return;
V_136:
F_2 ( L_11 ) ;
F_34 ( V_28 , V_26 , V_142 , 0 ) ;
F_9 ( V_26 ) ;
F_10 ( V_12 ) ;
}
void F_47 ( struct V_134 * V_12 , struct V_25 * V_26 )
{
struct V_64 * V_65 = F_24 ( V_26 ) ;
switch ( V_65 -> V_74 ) {
case V_143 :
F_43 ( V_12 , V_26 ) ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_69 :
case V_144 :
default:
F_2 ( L_7 ,
V_36 , V_65 -> V_74 ) ;
F_9 ( V_26 ) ;
F_10 ( V_12 ) ;
break;
}
}
static void V_139 ( struct V_145 * V_138 )
{
struct V_1 * V_2 = F_13 ( V_138 , struct V_1 , V_138 ) ;
struct V_64 * V_65 = F_24 ( V_2 -> V_29 ) ;
struct V_99 * V_33 ;
int V_146 = 0 ;
int V_147 ;
V_33 = F_18 ( V_2 -> V_29 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
goto V_148;
if ( V_33 -> V_149 & V_150 )
goto V_148;
if ( V_33 -> V_102 ) {
F_39 ( V_2 ) ;
return;
}
switch ( V_33 -> V_149 & ( V_151 | V_152 ) ) {
case 0 :
V_146 = V_153 ;
break;
case V_151 :
V_146 = V_154 ;
break;
case V_152 :
V_146 = V_155 ;
break;
case V_152 | V_151 :
goto V_148;
}
switch ( V_33 -> V_156 & V_157 ) {
case V_158 :
V_147 = V_159 ;
break;
case V_160 :
V_147 = V_161 ;
break;
case V_162 :
V_147 = V_163 ;
break;
case V_164 :
default:
V_147 = V_165 ;
}
F_5 ( V_2 -> V_13 ) -> V_37 -> V_30 . V_166 ( V_2 -> V_13 , F_29 , V_2 ) ;
F_48 ( & V_2 -> V_8 , V_2 -> V_12 -> V_114 , V_33 -> V_167 ,
& V_2 -> V_115 [ 0 ] , F_41 ( & V_33 -> V_116 ) ,
F_49 ( V_33 -> V_168 ) , V_147 , V_146 , 0 ) ;
F_2 ( L_12 , V_65 -> V_74 ) ;
return;
V_148:
F_38 ( V_2 , V_113 ) ;
}
