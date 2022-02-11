static void F_1 ( struct V_1 * V_2 , const char * V_3 )
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
void F_6 ( struct V_1 * V_2 , const char * V_3 )
{
if ( F_7 ( V_25 ) )
F_1 ( V_2 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( ! V_2 )
return;
V_27 = V_2 -> V_30 ;
V_29 = F_9 ( V_27 ) ;
if ( F_10 ( V_27 ) )
V_29 -> V_31 . V_32 ( F_10 ( V_27 ) ) ;
F_11 ( V_27 ) ;
F_12 ( V_2 -> V_12 ) ;
F_13 ( V_2 ) ;
}
void F_14 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
F_8 ( V_2 ) ;
}
int F_16 ( struct V_8 * V_8 )
{
F_17 ( V_8 , 0 ) ;
return 1 ;
}
int F_18 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
T_1 V_35 ;
if ( V_2 -> V_36 )
return 0 ;
F_6 ( V_2 , V_37 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_38 ;
V_35 = sizeof( * V_34 ) + V_8 -> V_39 ;
V_27 = F_19 ( V_29 , V_35 ) ;
if ( ! V_27 ) {
return 0 ;
}
V_34 = F_20 ( V_27 , V_35 ) ;
memset ( V_34 , 0 , V_35 ) ;
V_34 -> V_40 . V_41 = V_8 -> V_42 ;
V_35 = V_8 -> V_39 ;
if ( V_35 ) {
V_34 -> V_40 . V_43 |= V_44 ;
V_34 -> V_45 . V_46 = F_21 ( V_35 ) ;
memcpy ( ( V_34 + 1 ) , V_8 -> V_47 , V_35 ) ;
}
if ( V_8 -> V_16 & ( V_48 | V_49 ) ) {
if ( V_8 -> V_16 & V_48 )
V_34 -> V_40 . V_43 |= V_50 ;
else
V_34 -> V_40 . V_43 |= V_51 ;
V_34 -> V_45 . V_52 = F_22 ( V_8 -> V_53 ) ;
}
V_2 -> V_13 = V_29 -> V_31 . V_54 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_55 , V_5 -> V_20 , V_5 -> V_19 , V_56 ,
V_57 | V_58 | V_59 , 0 ) ;
V_29 -> V_31 . V_60 ( V_29 , V_2 -> V_13 , V_27 ) ;
V_29 -> V_31 . V_61 ( V_2 -> V_13 ) ;
return 0 ;
}
int F_24 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_62 != V_8 -> V_15 ;
}
int F_25 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_63 * V_64 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
struct V_65 * V_66 ;
T_2 V_67 ;
F_6 ( V_2 , V_37 ) ;
if ( V_2 -> V_36 )
return 0 ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_38 ;
V_27 = F_19 ( V_29 , sizeof( * V_64 ) ) ;
if ( ! V_27 )
return - V_68 ;
V_64 = F_20 ( V_27 , sizeof( * V_64 ) ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_69 = F_21 ( V_8 -> V_15 ) ;
V_2 -> V_13 = V_29 -> V_31 . V_54 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_70 , V_5 -> V_20 , V_5 -> V_19 , V_56 ,
V_57 | V_59 | V_71 , 0 ) ;
V_66 = F_26 ( V_27 ) ;
V_67 = F_27 ( V_66 -> V_72 ) ;
if ( V_67 & V_57 ) {
if ( ( V_5 -> V_73 <= V_29 -> V_74 ) &&
( V_66 -> V_75 == V_70 ) ) {
if ( ( V_8 -> V_16 & V_76 ) &&
V_29 -> V_31 . V_77 ( V_29 , V_5 -> V_73 ,
V_8 -> V_78 ,
V_8 -> V_14 ) )
V_2 -> V_79 = 1 ;
}
}
V_29 -> V_31 . V_60 ( V_29 , V_2 -> V_13 , V_27 ) ;
return 0 ;
}
T_2 F_28 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
if ( V_2 -> V_36 )
return ~ 0 ;
return F_5 ( V_2 -> V_13 ) -> V_22 ;
}
int F_29 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_30 ( struct V_6 * V_7 , struct V_26 * V_27 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
struct V_65 * V_66 ;
if ( F_7 ( F_31 ( V_27 ) ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_36 = true ;
return;
}
V_66 = F_26 ( V_27 ) ;
switch ( V_66 -> V_75 ) {
case V_81 :
F_32 ( V_2 , V_27 ) ;
break;
case V_82 :
case V_83 :
case V_70 :
default:
F_2 ( L_7 ,
V_37 , V_66 -> V_75 ) ;
F_33 ( V_2 ) ;
F_11 ( V_27 ) ;
F_17 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_34 ( struct V_28 * V_29 ,
const struct V_26 * V_84 ,
T_2 V_85 , enum V_86 V_87 )
{
struct V_26 * V_27 ;
struct V_6 * V_7 ;
const struct V_65 * V_66 ;
T_1 V_35 ;
struct V_33 * V_34 ;
struct V_88 * V_89 ;
V_66 = F_26 ( V_84 ) ;
F_2 ( L_8 ,
F_27 ( V_66 -> V_90 ) , F_35 ( V_66 -> V_91 ) , V_85 , V_87 ) ;
V_35 = sizeof( * V_34 ) ;
if ( V_85 == V_92 )
V_35 += sizeof( * V_89 ) ;
V_27 = F_19 ( V_29 , V_35 ) ;
if ( ! V_27 )
return;
V_34 = F_20 ( V_27 , V_35 ) ;
memset ( V_34 , 0 , V_35 ) ;
V_34 -> V_40 . V_41 = V_85 ;
if ( V_85 == V_92 ) {
V_34 -> V_45 . V_93 = F_21 ( sizeof( * V_89 ) ) ;
V_34 -> V_40 . V_43 |= V_94 ;
V_89 = (struct V_88 * ) ( V_34 + 1 ) ;
V_89 -> V_95 = V_87 ;
}
F_36 ( V_27 , V_84 , V_55 , 0 ) ;
V_7 = F_10 ( V_27 ) ;
if ( V_7 ) {
V_29 -> V_31 . V_60 ( V_29 , V_7 , V_27 ) ;
V_29 -> V_31 . V_61 ( V_7 ) ;
} else {
V_29 -> V_31 . V_96 ( V_29 , V_27 ) ;
}
}
static void F_37 ( struct V_1 * V_2 ,
enum V_86 V_87 )
{
F_34 ( V_2 -> V_12 -> V_97 -> V_29 ,
V_2 -> V_30 , V_92 , V_87 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
enum V_86 V_87 )
{
F_37 ( V_2 , V_87 ) ;
F_8 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_98 * V_34 ;
int V_99 ;
T_3 V_100 ;
V_34 = F_20 ( V_2 -> V_30 , sizeof( * V_34 ) ) ;
switch ( V_34 -> V_101 ) {
case V_102 :
V_100 = V_103 ;
break;
case V_104 :
V_100 = V_105 ;
break;
case V_106 :
V_100 = V_107 ;
break;
case V_108 :
V_100 = V_109 ;
break;
case V_110 :
V_100 = V_111 ;
break;
default:
F_2 ( L_9 , V_34 -> V_101 ) ;
F_38 ( V_2 , V_112 ) ;
return;
}
V_99 = F_40 ( & V_2 -> V_8 , V_2 -> V_12 -> V_113 ,
& V_2 -> V_114 [ 0 ] , F_41 ( & V_34 -> V_115 ) ,
V_2 , V_100 , V_116 , 0 , 0 ) ;
if ( V_99 < 0 )
F_38 ( V_2 , V_117 ) ;
}
int F_42 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_118 * V_119 = V_8 -> V_118 ;
enum V_86 V_87 ;
if ( V_2 -> V_36 )
return 0 ;
switch ( V_119 -> V_120 ) {
case V_121 :
V_87 = V_122 ;
break;
case V_123 :
V_87 = V_124 ;
break;
case V_125 :
V_87 = V_126 ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
default:
V_87 = V_117 ;
break;
}
F_2 ( L_10 ,
V_119 -> V_132 , V_119 -> V_120 , V_87 ) ;
F_37 ( V_2 , V_87 ) ;
return 0 ;
}
static void F_43 ( struct V_133 * V_12 , struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_12 -> V_97 -> V_29 ;
V_2 = F_44 ( sizeof( * V_2 ) , V_134 ) ;
if ( ! V_2 )
goto V_135;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_29 -> V_31 . V_136 ( V_29 , V_27 ) ;
if ( ! V_2 -> V_13 ) {
F_13 ( V_2 ) ;
goto V_135;
}
V_2 -> V_30 = V_27 ;
F_45 ( & V_2 -> V_137 , V_138 ) ;
F_46 ( V_12 -> V_97 -> V_139 -> V_140 , & V_2 -> V_137 ) ;
return;
V_135:
F_2 ( L_11 ) ;
F_34 ( V_29 , V_27 , V_141 , 0 ) ;
F_11 ( V_27 ) ;
F_12 ( V_12 ) ;
}
void F_47 ( struct V_133 * V_12 , struct V_26 * V_27 )
{
struct V_65 * V_66 = F_26 ( V_27 ) ;
switch ( V_66 -> V_75 ) {
case V_142 :
F_43 ( V_12 , V_27 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_70 :
case V_143 :
default:
F_2 ( L_7 ,
V_37 , V_66 -> V_75 ) ;
F_11 ( V_27 ) ;
F_12 ( V_12 ) ;
break;
}
}
static void V_138 ( struct V_144 * V_137 )
{
struct V_1 * V_2 = F_15 ( V_137 , struct V_1 , V_137 ) ;
struct V_65 * V_66 = F_26 ( V_2 -> V_30 ) ;
struct V_98 * V_34 ;
int V_145 = 0 ;
int V_146 ;
V_34 = F_20 ( V_2 -> V_30 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
goto V_147;
if ( V_34 -> V_148 & V_149 )
goto V_147;
if ( V_34 -> V_101 ) {
F_39 ( V_2 ) ;
return;
}
switch ( V_34 -> V_148 & ( V_150 | V_151 ) ) {
case 0 :
V_145 = V_152 ;
break;
case V_150 :
V_145 = V_153 ;
break;
case V_151 :
V_145 = V_154 ;
break;
case V_151 | V_150 :
goto V_147;
}
switch ( V_34 -> V_155 & V_156 ) {
case V_157 :
V_146 = V_158 ;
break;
case V_159 :
V_146 = V_160 ;
break;
case V_161 :
V_146 = V_162 ;
break;
case V_163 :
default:
V_146 = V_164 ;
}
F_5 ( V_2 -> V_13 ) -> V_38 -> V_31 . V_165 ( V_2 -> V_13 , F_30 , V_2 ) ;
if ( F_48 ( & V_2 -> V_8 , V_2 -> V_12 -> V_113 , V_34 -> V_166 ,
& V_2 -> V_114 [ 0 ] , F_41 ( & V_34 -> V_115 ) ,
F_49 ( V_34 -> V_167 ) , V_146 , V_145 , 0 ) )
goto V_147;
F_2 ( L_12 , V_66 -> V_75 ) ;
return;
V_147:
F_38 ( V_2 , V_112 ) ;
}
