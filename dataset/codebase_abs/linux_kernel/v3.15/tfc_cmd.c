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
struct V_30 * V_12 ;
if ( ! V_2 )
return;
V_12 = V_2 -> V_12 ;
V_27 = V_2 -> V_31 ;
V_29 = F_9 ( V_27 ) ;
if ( F_10 ( V_27 ) )
V_29 -> V_32 . V_33 ( F_10 ( V_27 ) ) ;
F_11 ( V_27 ) ;
F_12 ( & V_12 -> V_34 -> V_35 , V_2 -> V_8 . V_36 ) ;
F_13 ( V_12 ) ;
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
struct V_37 * V_38 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
T_1 V_39 ;
if ( V_2 -> V_40 )
return 0 ;
F_6 ( V_2 , V_41 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_42 ;
V_39 = sizeof( * V_38 ) + V_8 -> V_43 ;
V_27 = F_19 ( V_29 , V_39 ) ;
if ( ! V_27 ) {
return 0 ;
}
V_38 = F_20 ( V_27 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_44 . V_45 = V_8 -> V_46 ;
V_39 = V_8 -> V_43 ;
if ( V_39 ) {
V_38 -> V_44 . V_47 |= V_48 ;
V_38 -> V_49 . V_50 = F_21 ( V_39 ) ;
memcpy ( ( V_38 + 1 ) , V_8 -> V_51 , V_39 ) ;
}
if ( V_8 -> V_16 & ( V_52 | V_53 ) ) {
if ( V_8 -> V_16 & V_52 )
V_38 -> V_44 . V_47 |= V_54 ;
else
V_38 -> V_44 . V_47 |= V_55 ;
V_38 -> V_49 . V_56 = F_22 ( V_8 -> V_57 ) ;
}
V_2 -> V_13 = V_29 -> V_32 . V_58 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_59 , V_5 -> V_20 , V_5 -> V_19 , V_60 ,
V_61 | V_62 | V_63 , 0 ) ;
V_29 -> V_32 . V_64 ( V_29 , V_2 -> V_13 , V_27 ) ;
V_29 -> V_32 . V_65 ( V_2 -> V_13 ) ;
return 0 ;
}
int F_24 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_66 != V_8 -> V_15 ;
}
int F_25 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_67 * V_68 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
struct V_69 * V_70 ;
T_2 V_71 ;
F_6 ( V_2 , V_41 ) ;
if ( V_2 -> V_40 )
return 0 ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_42 ;
V_27 = F_19 ( V_29 , sizeof( * V_68 ) ) ;
if ( ! V_27 )
return - V_72 ;
V_68 = F_20 ( V_27 , sizeof( * V_68 ) ) ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_73 = F_21 ( V_8 -> V_15 ) ;
V_2 -> V_13 = V_29 -> V_32 . V_58 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_74 , V_5 -> V_20 , V_5 -> V_19 , V_60 ,
V_61 | V_63 | V_75 , 0 ) ;
V_70 = F_26 ( V_27 ) ;
V_71 = F_27 ( V_70 -> V_76 ) ;
if ( V_71 & V_61 ) {
if ( ( V_5 -> V_77 <= V_29 -> V_78 ) &&
( V_70 -> V_79 == V_74 ) ) {
if ( ( V_8 -> V_16 & V_80 ) &&
V_29 -> V_32 . V_81 ( V_29 , V_5 -> V_77 ,
V_8 -> V_82 ,
V_8 -> V_14 ) )
V_2 -> V_83 = 1 ;
}
}
V_29 -> V_32 . V_64 ( V_29 , V_2 -> V_13 , V_27 ) ;
return 0 ;
}
T_2 F_28 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
if ( V_2 -> V_40 )
return ~ 0 ;
return F_5 ( V_2 -> V_13 ) -> V_22 ;
}
int F_29 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_30 ( struct V_6 * V_7 , struct V_26 * V_27 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_69 * V_70 ;
if ( F_7 ( F_31 ( V_27 ) ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_40 = true ;
return;
}
V_70 = F_26 ( V_27 ) ;
switch ( V_70 -> V_79 ) {
case V_85 :
F_32 ( V_2 , V_27 ) ;
break;
case V_86 :
case V_87 :
case V_74 :
default:
F_2 ( L_7 ,
V_41 , V_70 -> V_79 ) ;
F_33 ( V_2 ) ;
F_11 ( V_27 ) ;
F_17 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_34 ( struct V_28 * V_29 ,
const struct V_26 * V_88 ,
T_2 V_89 , enum V_90 V_91 )
{
struct V_26 * V_27 ;
struct V_6 * V_7 ;
const struct V_69 * V_70 ;
T_1 V_39 ;
struct V_37 * V_38 ;
struct V_92 * V_93 ;
V_70 = F_26 ( V_88 ) ;
F_2 ( L_8 ,
F_27 ( V_70 -> V_94 ) , F_35 ( V_70 -> V_95 ) , V_89 , V_91 ) ;
V_39 = sizeof( * V_38 ) ;
if ( V_89 == V_96 )
V_39 += sizeof( * V_93 ) ;
V_27 = F_19 ( V_29 , V_39 ) ;
if ( ! V_27 )
return;
V_38 = F_20 ( V_27 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_44 . V_45 = V_89 ;
if ( V_89 == V_96 ) {
V_38 -> V_49 . V_97 = F_21 ( sizeof( * V_93 ) ) ;
V_38 -> V_44 . V_47 |= V_98 ;
V_93 = (struct V_92 * ) ( V_38 + 1 ) ;
V_93 -> V_99 = V_91 ;
}
F_36 ( V_27 , V_88 , V_59 , 0 ) ;
V_7 = F_10 ( V_27 ) ;
if ( V_7 ) {
V_29 -> V_32 . V_64 ( V_29 , V_7 , V_27 ) ;
V_29 -> V_32 . V_65 ( V_7 ) ;
} else {
V_29 -> V_32 . V_100 ( V_29 , V_27 ) ;
}
}
static void F_37 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
F_34 ( V_2 -> V_12 -> V_101 -> V_29 ,
V_2 -> V_31 , V_96 , V_91 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
F_37 ( V_2 , V_91 ) ;
F_8 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_102 * V_38 ;
int V_103 ;
T_3 V_104 ;
V_38 = F_20 ( V_2 -> V_31 , sizeof( * V_38 ) ) ;
switch ( V_38 -> V_105 ) {
case V_106 :
V_104 = V_107 ;
break;
case V_108 :
V_104 = V_109 ;
break;
case V_110 :
V_104 = V_111 ;
break;
case V_112 :
V_104 = V_113 ;
break;
case V_114 :
V_104 = V_115 ;
break;
default:
F_2 ( L_9 , V_38 -> V_105 ) ;
F_38 ( V_2 , V_116 ) ;
return;
}
V_103 = F_40 ( & V_2 -> V_8 , V_2 -> V_12 -> V_34 ,
& V_2 -> V_117 [ 0 ] , F_41 ( & V_38 -> V_118 ) ,
V_2 , V_104 , V_119 , 0 , 0 ) ;
if ( V_103 < 0 )
F_38 ( V_2 , V_120 ) ;
}
void F_42 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_121 * V_122 = V_8 -> V_121 ;
enum V_90 V_91 ;
if ( V_2 -> V_40 )
return;
switch ( V_122 -> V_123 ) {
case V_124 :
V_91 = V_125 ;
break;
case V_126 :
V_91 = V_127 ;
break;
case V_128 :
V_91 = V_129 ;
break;
case V_130 :
case V_131 :
default:
V_91 = V_120 ;
break;
}
F_2 ( L_10 ,
V_122 -> V_132 , V_122 -> V_123 , V_91 ) ;
F_37 ( V_2 , V_91 ) ;
}
void F_43 ( struct V_8 * V_8 )
{
return;
}
static void F_44 ( struct V_30 * V_12 , struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_12 -> V_101 -> V_29 ;
struct V_133 * V_34 = V_12 -> V_34 ;
int V_134 ;
V_134 = F_45 ( & V_34 -> V_35 , V_135 ) ;
if ( V_134 < 0 )
goto V_136;
V_2 = & ( (struct V_1 * ) V_34 -> V_137 ) [ V_134 ] ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_8 . V_36 = V_134 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_29 -> V_32 . V_138 ( V_29 , V_27 ) ;
if ( ! V_2 -> V_13 ) {
F_12 ( & V_34 -> V_35 , V_134 ) ;
goto V_136;
}
V_2 -> V_31 = V_27 ;
F_46 ( & V_2 -> V_139 , V_140 ) ;
F_47 ( V_12 -> V_101 -> V_141 -> V_142 , & V_2 -> V_139 ) ;
return;
V_136:
F_2 ( L_11 ) ;
F_34 ( V_29 , V_27 , V_143 , 0 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
}
void F_48 ( struct V_30 * V_12 , struct V_26 * V_27 )
{
struct V_69 * V_70 = F_26 ( V_27 ) ;
switch ( V_70 -> V_79 ) {
case V_144 :
F_44 ( V_12 , V_27 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_74 :
case V_145 :
default:
F_2 ( L_7 ,
V_41 , V_70 -> V_79 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
break;
}
}
static void V_140 ( struct V_146 * V_139 )
{
struct V_1 * V_2 = F_15 ( V_139 , struct V_1 , V_139 ) ;
struct V_69 * V_70 = F_26 ( V_2 -> V_31 ) ;
struct V_102 * V_38 ;
int V_147 = 0 ;
int V_148 ;
V_38 = F_20 ( V_2 -> V_31 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
goto V_149;
if ( V_38 -> V_150 & V_151 )
goto V_149;
if ( V_38 -> V_105 ) {
F_39 ( V_2 ) ;
return;
}
switch ( V_38 -> V_150 & ( V_152 | V_153 ) ) {
case 0 :
V_147 = V_154 ;
break;
case V_152 :
V_147 = V_155 ;
break;
case V_153 :
V_147 = V_156 ;
break;
case V_153 | V_152 :
goto V_149;
}
switch ( V_38 -> V_157 & V_158 ) {
case V_159 :
V_148 = V_160 ;
break;
case V_161 :
V_148 = V_162 ;
break;
case V_163 :
V_148 = V_164 ;
break;
case V_165 :
default:
V_148 = V_166 ;
}
F_5 ( V_2 -> V_13 ) -> V_42 -> V_32 . V_167 ( V_2 -> V_13 , F_30 , V_2 ) ;
if ( F_49 ( & V_2 -> V_8 , V_2 -> V_12 -> V_34 , V_38 -> V_168 ,
& V_2 -> V_117 [ 0 ] , F_41 ( & V_38 -> V_118 ) ,
F_50 ( V_38 -> V_169 ) , V_148 , V_147 , 0 ) )
goto V_149;
F_2 ( L_12 , V_70 -> V_79 ) ;
return;
V_149:
F_38 ( V_2 , V_116 ) ;
}
