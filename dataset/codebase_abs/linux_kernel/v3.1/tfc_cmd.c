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
V_3 , V_2 , V_2 -> V_14 ) ;
F_2 ( L_3 , V_3 , V_2 , V_2 -> V_15 ) ;
F_2 ( L_4 ,
V_3 , V_2 , V_8 -> V_16 ,
V_8 -> V_17 , V_8 -> V_18 ) ;
F_3 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, count)
F_2 ( L_5
L_6 ,
V_3 , V_2 , V_10 ,
F_4 ( V_10 ) , V_10 -> V_19 , V_10 -> V_20 ) ;
V_7 = V_2 -> V_13 ;
if ( V_7 ) {
V_5 = F_5 ( V_7 ) ;
F_2 ( L_7
L_8 ,
V_3 , V_2 , V_5 -> V_21 , V_5 -> V_22 , V_5 -> V_23 , V_5 -> V_24 ,
V_7 -> V_25 , V_5 -> V_26 ) ;
}
F_6 ( V_27 , L_9 , V_28 ,
16 , 4 , V_2 -> V_14 , V_29 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! V_2 )
return;
V_31 = V_2 -> V_34 ;
V_33 = F_8 ( V_31 ) ;
if ( F_9 ( V_31 ) )
V_33 -> V_35 . V_36 ( F_9 ( V_31 ) ) ;
F_10 ( V_31 ) ;
F_11 ( V_2 -> V_12 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
F_7 ( V_2 ) ;
}
void F_15 ( struct V_8 * V_8 )
{
F_16 ( V_8 , 0 , 0 ) ;
}
int F_17 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_32 * V_33 ;
struct V_4 * V_5 ;
T_1 V_39 ;
F_1 ( V_2 , V_40 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_33 = V_5 -> V_41 ;
V_39 = sizeof( * V_38 ) + V_8 -> V_42 ;
V_31 = F_18 ( V_33 , V_39 ) ;
if ( ! V_31 ) {
return 0 ;
}
V_38 = F_19 ( V_31 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_43 . V_44 = V_8 -> V_45 ;
V_39 = V_8 -> V_42 ;
if ( V_39 ) {
V_38 -> V_43 . V_46 |= V_47 ;
V_38 -> V_48 . V_49 = F_20 ( V_39 ) ;
memcpy ( ( V_38 + 1 ) , V_8 -> V_50 , V_39 ) ;
}
if ( V_8 -> V_18 & ( V_51 | V_52 ) ) {
if ( V_8 -> V_18 & V_51 )
V_38 -> V_43 . V_46 |= V_53 ;
else
V_38 -> V_43 . V_46 |= V_54 ;
V_38 -> V_48 . V_55 = F_21 ( V_8 -> V_56 ) ;
}
V_2 -> V_13 = V_33 -> V_35 . V_57 ( V_2 -> V_13 ) ;
F_22 ( V_31 , V_58 , V_5 -> V_22 , V_5 -> V_21 , V_59 ,
V_60 | V_61 | V_62 , 0 ) ;
V_33 -> V_35 . V_63 ( V_33 , V_2 -> V_13 , V_31 ) ;
V_33 -> V_35 . V_64 ( V_2 -> V_13 ) ;
return 0 ;
}
int F_23 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_65 != V_8 -> V_17 ;
}
int F_24 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
struct V_30 * V_31 ;
struct V_66 * V_67 ;
struct V_32 * V_33 ;
struct V_4 * V_5 ;
struct V_68 * V_69 ;
T_2 V_70 ;
F_1 ( V_2 , V_40 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_33 = V_5 -> V_41 ;
V_31 = F_18 ( V_33 , sizeof( * V_67 ) ) ;
if ( ! V_31 )
return V_71 ;
V_67 = F_19 ( V_31 , sizeof( * V_67 ) ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_72 = F_20 ( V_8 -> V_17 ) ;
V_2 -> V_13 = V_33 -> V_35 . V_57 ( V_2 -> V_13 ) ;
F_22 ( V_31 , V_73 , V_5 -> V_22 , V_5 -> V_21 , V_59 ,
V_60 | V_62 | V_74 , 0 ) ;
V_69 = F_25 ( V_31 ) ;
V_70 = F_26 ( V_69 -> V_75 ) ;
if ( V_70 & V_60 ) {
if ( ( V_5 -> V_76 <= V_33 -> V_77 ) &&
( V_69 -> V_78 == V_73 ) ) {
if ( V_8 -> V_18 & V_79 ) {
F_27 ( V_8 ) ;
V_2 -> V_10 = V_8 -> V_80 ;
V_2 -> V_81 =
V_8 -> V_82 ;
}
if ( V_2 -> V_10 && V_33 -> V_35 . V_83 ( V_33 , V_5 -> V_76 ,
V_2 -> V_10 ,
V_2 -> V_81 ) )
V_2 -> V_84 = 1 ;
}
}
V_33 -> V_35 . V_63 ( V_33 , V_2 -> V_13 , V_31 ) ;
return 0 ;
}
T_2 F_28 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
return F_5 ( V_2 -> V_13 ) -> V_24 ;
}
int F_29 ( struct V_8 * V_8 )
{
return 0 ;
}
int F_30 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , struct V_30 * V_31 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_68 * V_69 ;
if ( F_32 ( V_31 ) ) {
V_2 -> V_8 . V_86 = V_87 ;
V_2 -> V_13 = NULL ;
F_16 ( & V_2 -> V_8 , 0 , 0 ) ;
return;
}
V_69 = F_25 ( V_31 ) ;
switch ( V_69 -> V_78 ) {
case V_88 :
F_33 ( V_2 , V_31 ) ;
break;
case V_89 :
case V_90 :
case V_73 :
default:
F_2 ( L_10 ,
V_40 , V_69 -> V_78 ) ;
F_34 ( V_2 ) ;
F_10 ( V_31 ) ;
F_16 ( & V_2 -> V_8 , 0 , 0 ) ;
break;
}
}
static void F_35 ( struct V_32 * V_33 ,
const struct V_30 * V_91 ,
T_2 V_92 , enum V_93 V_94 )
{
struct V_30 * V_31 ;
struct V_6 * V_7 ;
const struct V_68 * V_69 ;
T_1 V_39 ;
struct V_37 * V_38 ;
struct V_95 * V_96 ;
V_69 = F_25 ( V_91 ) ;
F_2 ( L_11 ,
F_26 ( V_69 -> V_97 ) , F_36 ( V_69 -> V_98 ) , V_92 , V_94 ) ;
V_39 = sizeof( * V_38 ) ;
if ( V_92 == V_99 )
V_39 += sizeof( * V_96 ) ;
V_31 = F_18 ( V_33 , V_39 ) ;
if ( ! V_31 )
return;
V_38 = F_19 ( V_31 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_43 . V_44 = V_92 ;
if ( V_92 == V_99 ) {
V_38 -> V_48 . V_100 = F_20 ( sizeof( * V_96 ) ) ;
V_38 -> V_43 . V_46 |= V_101 ;
V_96 = (struct V_95 * ) ( V_38 + 1 ) ;
V_96 -> V_102 = V_94 ;
}
F_37 ( V_31 , V_91 , V_58 , 0 ) ;
V_7 = F_9 ( V_31 ) ;
if ( V_7 )
V_33 -> V_35 . V_63 ( V_33 , V_7 , V_31 ) ;
else
V_33 -> V_35 . V_103 ( V_33 , V_31 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
enum V_93 V_94 )
{
F_35 ( V_2 -> V_12 -> V_104 -> V_33 ,
V_2 -> V_34 , V_99 , V_94 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
enum V_93 V_94 )
{
F_38 ( V_2 , V_94 ) ;
F_7 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_107 * V_38 ;
struct V_108 * V_12 ;
T_3 V_109 ;
V_38 = F_19 ( V_2 -> V_34 , sizeof( * V_38 ) ) ;
switch ( V_38 -> V_110 ) {
case V_111 :
V_109 = V_112 ;
break;
case V_113 :
V_109 = V_114 ;
break;
case V_115 :
V_109 = V_116 ;
break;
case V_117 :
V_109 = V_118 ;
break;
case V_119 :
V_109 = V_120 ;
break;
default:
F_2 ( L_12 , V_38 -> V_110 ) ;
F_39 ( V_2 , V_121 ) ;
return;
}
F_2 ( L_13 , V_109 ) ;
V_106 = F_41 ( & V_2 -> V_8 , V_2 , V_109 ) ;
if ( ! V_106 ) {
F_2 ( L_14 ) ;
F_39 ( V_2 , V_122 ) ;
return;
}
V_2 -> V_8 . V_105 = V_106 ;
switch ( V_38 -> V_110 ) {
case V_111 :
V_2 -> V_15 = F_42 ( (struct V_123 * ) V_38 -> V_124 ) ;
if ( F_43 ( & V_2 -> V_8 , V_2 -> V_15 ) < 0 ) {
F_2 ( L_15
L_16 ,
V_109 , & V_2 -> V_8 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_40 ) ;
V_12 = V_2 -> V_12 ;
F_44 ( & V_2 -> V_8 ,
V_2 -> V_8 . V_125 , 0 ) ;
F_16 ( & V_2 -> V_8 , 0 , 0 ) ;
F_11 ( V_12 ) ;
return;
}
break;
case V_113 :
case V_115 :
case V_117 :
case V_119 :
break;
default:
return;
}
F_45 ( & V_2 -> V_8 ) ;
}
int F_46 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 , struct V_1 , V_8 ) ;
struct V_105 * V_106 = V_8 -> V_105 ;
enum V_93 V_94 ;
switch ( V_106 -> V_126 ) {
case V_127 :
V_94 = V_128 ;
break;
case V_129 :
V_94 = V_130 ;
break;
case V_131 :
V_94 = V_132 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
default:
V_94 = V_122 ;
break;
}
F_2 ( L_17 ,
V_106 -> V_138 , V_106 -> V_126 , V_94 ) ;
F_38 ( V_2 , V_94 ) ;
return 0 ;
}
static void F_47 ( struct V_108 * V_12 , struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 = V_12 -> V_104 -> V_33 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
goto V_140;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_33 -> V_35 . V_141 ( V_33 , V_31 ) ;
if ( ! V_2 -> V_13 ) {
F_12 ( V_2 ) ;
goto V_140;
}
V_2 -> V_34 = V_31 ;
F_49 ( & V_2 -> V_142 , V_143 ) ;
F_50 ( V_12 -> V_104 -> V_144 -> V_145 , & V_2 -> V_142 ) ;
return;
V_140:
F_2 ( L_18 ) ;
F_35 ( V_33 , V_31 , V_146 , 0 ) ;
F_10 ( V_31 ) ;
F_11 ( V_12 ) ;
}
void F_51 ( struct V_108 * V_12 , struct V_30 * V_31 )
{
struct V_68 * V_69 = F_25 ( V_31 ) ;
switch ( V_69 -> V_78 ) {
case V_147 :
F_47 ( V_12 , V_31 ) ;
break;
case V_88 :
case V_89 :
case V_90 :
case V_73 :
case V_148 :
default:
F_2 ( L_10 ,
V_40 , V_69 -> V_78 ) ;
F_10 ( V_31 ) ;
F_11 ( V_12 ) ;
break;
}
}
static void V_143 ( struct V_149 * V_142 )
{
struct V_1 * V_2 = F_14 ( V_142 , struct V_1 , V_142 ) ;
struct V_68 * V_69 = F_25 ( V_2 -> V_34 ) ;
struct V_8 * V_8 ;
struct V_107 * V_38 ;
int V_150 = 0 ;
T_2 V_151 ;
int V_152 ;
int V_153 ;
V_38 = F_19 ( V_2 -> V_34 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
goto V_154;
if ( V_38 -> V_155 & V_156 )
goto V_154;
if ( V_38 -> V_110 ) {
V_152 = V_157 ;
V_150 = V_158 ;
V_151 = 0 ;
} else {
switch ( V_38 -> V_155 & ( V_159 | V_160 ) ) {
case 0 :
V_150 = V_158 ;
break;
case V_159 :
V_150 = V_161 ;
break;
case V_160 :
V_150 = V_162 ;
break;
case V_160 | V_159 :
goto V_154;
}
switch ( V_38 -> V_163 & V_164 ) {
case V_165 :
V_152 = V_166 ;
break;
case V_167 :
V_152 = V_168 ;
break;
case V_169 :
V_152 = V_170 ;
break;
case V_157 :
default:
V_152 = V_171 ;
}
V_152 = V_38 -> V_163 & V_164 ;
V_151 = F_52 ( V_38 -> V_172 ) ;
V_2 -> V_14 = V_38 -> V_173 ;
}
V_8 = & V_2 -> V_8 ;
F_53 ( V_8 , & V_174 -> V_175 , V_2 -> V_12 -> V_176 ,
V_151 , V_150 , V_152 ,
& V_2 -> V_177 [ 0 ] ) ;
if ( V_38 -> V_110 ) {
F_40 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_13 ) -> V_41 -> V_35 . V_178 ( V_2 -> V_13 , F_31 , V_2 ) ;
V_2 -> V_15 = F_42 ( (struct V_123 * ) V_38 -> V_124 ) ;
V_153 = F_54 ( & V_2 -> V_8 , V_2 -> V_15 ) ;
if ( V_153 < 0 ) {
F_1 ( V_2 , V_40 ) ;
F_44 ( & V_2 -> V_8 ,
V_2 -> V_8 . V_125 , 0 ) ;
return;
}
V_153 = F_55 ( V_8 , V_2 -> V_14 ) ;
F_2 ( L_19 , V_69 -> V_78 , V_153 ) ;
F_1 ( V_2 , V_40 ) ;
if ( V_153 == - V_179 ) {
F_44 ( V_8 ,
V_180 , 0 ) ;
F_16 ( V_8 , 0 , 0 ) ;
return;
}
if ( V_153 == - V_181 ) {
if ( V_8 -> V_18 & V_182 )
F_17 ( V_8 ) ;
else
F_44 ( V_8 ,
V_8 -> V_125 , 0 ) ;
F_16 ( V_8 , 0 , 0 ) ;
return;
}
F_56 ( V_8 ) ;
return;
V_154:
F_39 ( V_2 , V_121 ) ;
}
