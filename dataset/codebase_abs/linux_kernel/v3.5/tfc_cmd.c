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
if ( ( V_8 -> V_16 & V_75 ) &&
V_28 -> V_30 . V_76 ( V_28 , V_5 -> V_72 ,
V_8 -> V_77 ,
V_8 -> V_14 ) )
V_2 -> V_78 = 1 ;
}
}
V_28 -> V_30 . V_59 ( V_28 , V_2 -> V_13 , V_26 ) ;
return 0 ;
}
T_2 F_26 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
if ( V_2 -> V_35 )
return ~ 0 ;
return F_5 ( V_2 -> V_13 ) -> V_22 ;
}
int F_27 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_28 ( struct V_6 * V_7 , struct V_25 * V_26 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
struct V_64 * V_65 ;
if ( F_29 ( F_30 ( V_26 ) ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_35 = true ;
return;
}
V_65 = F_24 ( V_26 ) ;
switch ( V_65 -> V_74 ) {
case V_80 :
F_31 ( V_2 , V_26 ) ;
break;
case V_81 :
case V_82 :
case V_69 :
default:
F_2 ( L_7 ,
V_36 , V_65 -> V_74 ) ;
F_32 ( V_2 ) ;
F_9 ( V_26 ) ;
F_15 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_33 ( struct V_27 * V_28 ,
const struct V_25 * V_83 ,
T_2 V_84 , enum V_85 V_86 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
const struct V_64 * V_65 ;
T_1 V_34 ;
struct V_32 * V_33 ;
struct V_87 * V_88 ;
V_65 = F_24 ( V_83 ) ;
F_2 ( L_8 ,
F_25 ( V_65 -> V_89 ) , F_34 ( V_65 -> V_90 ) , V_84 , V_86 ) ;
V_34 = sizeof( * V_33 ) ;
if ( V_84 == V_91 )
V_34 += sizeof( * V_88 ) ;
V_26 = F_17 ( V_28 , V_34 ) ;
if ( ! V_26 )
return;
V_33 = F_18 ( V_26 , V_34 ) ;
memset ( V_33 , 0 , V_34 ) ;
V_33 -> V_39 . V_40 = V_84 ;
if ( V_84 == V_91 ) {
V_33 -> V_44 . V_92 = F_19 ( sizeof( * V_88 ) ) ;
V_33 -> V_39 . V_42 |= V_93 ;
V_88 = (struct V_87 * ) ( V_33 + 1 ) ;
V_88 -> V_94 = V_86 ;
}
F_35 ( V_26 , V_83 , V_54 , 0 ) ;
V_7 = F_8 ( V_26 ) ;
if ( V_7 ) {
V_28 -> V_30 . V_59 ( V_28 , V_7 , V_26 ) ;
V_28 -> V_30 . V_60 ( V_7 ) ;
} else {
V_28 -> V_30 . V_95 ( V_28 , V_26 ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
F_33 ( V_2 -> V_12 -> V_96 -> V_28 ,
V_2 -> V_29 , V_91 , V_86 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
F_36 ( V_2 , V_86 ) ;
F_6 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_97 * V_33 ;
int V_98 ;
T_3 V_99 ;
V_33 = F_18 ( V_2 -> V_29 , sizeof( * V_33 ) ) ;
switch ( V_33 -> V_100 ) {
case V_101 :
V_99 = V_102 ;
break;
case V_103 :
V_99 = V_104 ;
break;
case V_105 :
V_99 = V_106 ;
break;
case V_107 :
V_99 = V_108 ;
break;
case V_109 :
V_99 = V_110 ;
break;
default:
F_2 ( L_9 , V_33 -> V_100 ) ;
F_37 ( V_2 , V_111 ) ;
return;
}
V_98 = F_39 ( & V_2 -> V_8 , V_2 -> V_12 -> V_112 ,
& V_2 -> V_113 [ 0 ] , F_40 ( & V_33 -> V_114 ) ,
V_2 , V_99 , V_115 , 0 , 0 ) ;
if ( V_98 < 0 )
F_37 ( V_2 , V_116 ) ;
}
int F_41 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 , struct V_1 , V_8 ) ;
struct V_117 * V_118 = V_8 -> V_117 ;
enum V_85 V_86 ;
if ( V_2 -> V_35 )
return 0 ;
switch ( V_118 -> V_119 ) {
case V_120 :
V_86 = V_121 ;
break;
case V_122 :
V_86 = V_123 ;
break;
case V_124 :
V_86 = V_125 ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
default:
V_86 = V_116 ;
break;
}
F_2 ( L_10 ,
V_118 -> V_131 , V_118 -> V_119 , V_86 ) ;
F_36 ( V_2 , V_86 ) ;
return 0 ;
}
static void F_42 ( struct V_132 * V_12 , struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = V_12 -> V_96 -> V_28 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_133 ) ;
if ( ! V_2 )
goto V_134;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_28 -> V_30 . V_135 ( V_28 , V_26 ) ;
if ( ! V_2 -> V_13 ) {
F_11 ( V_2 ) ;
goto V_134;
}
V_2 -> V_29 = V_26 ;
F_44 ( & V_2 -> V_136 , V_137 ) ;
F_45 ( V_12 -> V_96 -> V_138 -> V_139 , & V_2 -> V_136 ) ;
return;
V_134:
F_2 ( L_11 ) ;
F_33 ( V_28 , V_26 , V_140 , 0 ) ;
F_9 ( V_26 ) ;
F_10 ( V_12 ) ;
}
void F_46 ( struct V_132 * V_12 , struct V_25 * V_26 )
{
struct V_64 * V_65 = F_24 ( V_26 ) ;
switch ( V_65 -> V_74 ) {
case V_141 :
F_42 ( V_12 , V_26 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_69 :
case V_142 :
default:
F_2 ( L_7 ,
V_36 , V_65 -> V_74 ) ;
F_9 ( V_26 ) ;
F_10 ( V_12 ) ;
break;
}
}
static void V_137 ( struct V_143 * V_136 )
{
struct V_1 * V_2 = F_13 ( V_136 , struct V_1 , V_136 ) ;
struct V_64 * V_65 = F_24 ( V_2 -> V_29 ) ;
struct V_97 * V_33 ;
int V_144 = 0 ;
int V_145 ;
V_33 = F_18 ( V_2 -> V_29 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
goto V_146;
if ( V_33 -> V_147 & V_148 )
goto V_146;
if ( V_33 -> V_100 ) {
F_38 ( V_2 ) ;
return;
}
switch ( V_33 -> V_147 & ( V_149 | V_150 ) ) {
case 0 :
V_144 = V_151 ;
break;
case V_149 :
V_144 = V_152 ;
break;
case V_150 :
V_144 = V_153 ;
break;
case V_150 | V_149 :
goto V_146;
}
switch ( V_33 -> V_154 & V_155 ) {
case V_156 :
V_145 = V_157 ;
break;
case V_158 :
V_145 = V_159 ;
break;
case V_160 :
V_145 = V_161 ;
break;
case V_162 :
default:
V_145 = V_163 ;
}
F_5 ( V_2 -> V_13 ) -> V_37 -> V_30 . V_164 ( V_2 -> V_13 , F_28 , V_2 ) ;
F_47 ( & V_2 -> V_8 , V_2 -> V_12 -> V_112 , V_33 -> V_165 ,
& V_2 -> V_113 [ 0 ] , F_40 ( & V_33 -> V_114 ) ,
F_48 ( V_33 -> V_166 ) , V_145 , V_144 , 0 ) ;
F_2 ( L_12 , V_65 -> V_74 ) ;
return;
V_146:
F_37 ( V_2 , V_111 ) ;
}
