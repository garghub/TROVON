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
struct V_28 * V_12 ;
if ( ! V_2 )
return;
V_12 = V_2 -> V_12 ;
V_27 = V_2 -> V_29 ;
if ( F_9 ( V_27 ) )
F_10 ( F_9 ( V_27 ) ) ;
F_11 ( V_27 ) ;
F_12 ( & V_12 -> V_30 -> V_31 , V_2 -> V_8 . V_32 ) ;
F_13 ( V_12 ) ;
}
void F_14 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
F_8 ( V_2 ) ;
}
int F_16 ( struct V_8 * V_8 )
{
return F_17 ( V_8 , 0 ) ;
}
int F_18 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_4 * V_5 ;
T_1 V_37 ;
int V_38 ;
if ( V_2 -> V_39 )
return 0 ;
F_6 ( V_2 , V_40 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_36 = V_5 -> V_41 ;
V_37 = sizeof( * V_34 ) + V_8 -> V_42 ;
V_27 = F_19 ( V_36 , V_37 ) ;
if ( ! V_27 ) {
V_8 -> V_43 = V_44 ;
return - V_45 ;
}
V_34 = F_20 ( V_27 , V_37 ) ;
memset ( V_34 , 0 , V_37 ) ;
V_34 -> V_46 . V_47 = V_8 -> V_43 ;
V_37 = V_8 -> V_42 ;
if ( V_37 ) {
V_34 -> V_46 . V_48 |= V_49 ;
V_34 -> V_50 . V_51 = F_21 ( V_37 ) ;
memcpy ( ( V_34 + 1 ) , V_8 -> V_52 , V_37 ) ;
}
if ( V_8 -> V_16 & ( V_53 | V_54 ) ) {
if ( V_8 -> V_16 & V_53 )
V_34 -> V_46 . V_48 |= V_55 ;
else
V_34 -> V_46 . V_48 |= V_56 ;
V_34 -> V_50 . V_57 = F_22 ( V_8 -> V_58 ) ;
}
V_2 -> V_13 = F_23 ( V_2 -> V_13 ) ;
F_24 ( V_27 , V_59 , V_5 -> V_20 , V_5 -> V_19 , V_60 ,
V_61 | V_62 | V_63 , 0 ) ;
V_38 = F_25 ( V_36 , V_2 -> V_13 , V_27 ) ;
if ( V_38 ) {
F_26 ( L_7
L_8 , V_40 , V_27 , V_5 -> V_64 ) ;
V_8 -> V_43 = V_44 ;
return - V_45 ;
}
F_27 ( V_2 -> V_13 ) ;
F_28 ( & V_2 -> V_8 ) ;
return 0 ;
}
int F_29 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_65 != V_8 -> V_15 ;
}
int F_30 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_66 * V_67 ;
struct V_35 * V_36 ;
struct V_4 * V_5 ;
struct V_68 * V_69 ;
T_2 V_70 ;
F_6 ( V_2 , V_40 ) ;
if ( V_2 -> V_39 )
return 0 ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_36 = V_5 -> V_41 ;
V_27 = F_19 ( V_36 , sizeof( * V_67 ) ) ;
if ( ! V_27 )
return - V_45 ;
V_67 = F_20 ( V_27 , sizeof( * V_67 ) ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_71 = F_21 ( V_8 -> V_15 ) ;
V_2 -> V_13 = F_23 ( V_2 -> V_13 ) ;
F_24 ( V_27 , V_72 , V_5 -> V_20 , V_5 -> V_19 , V_60 ,
V_61 | V_63 | V_73 , 0 ) ;
V_69 = F_31 ( V_27 ) ;
V_70 = F_32 ( V_69 -> V_74 ) ;
if ( V_70 & V_61 ) {
if ( ( V_5 -> V_64 <= V_36 -> V_75 ) &&
( V_69 -> V_76 == V_72 ) ) {
if ( ( V_8 -> V_16 & V_77 ) &&
V_36 -> V_78 . V_79 ( V_36 , V_5 -> V_64 ,
V_8 -> V_80 ,
V_8 -> V_14 ) )
V_2 -> V_81 = 1 ;
}
}
F_25 ( V_36 , V_2 -> V_13 , V_27 ) ;
return 0 ;
}
int F_33 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_34 ( struct V_6 * V_7 , struct V_26 * V_27 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
struct V_68 * V_69 ;
if ( F_35 ( V_27 ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_39 = true ;
return;
}
V_69 = F_31 ( V_27 ) ;
switch ( V_69 -> V_76 ) {
case V_83 :
F_36 ( V_2 , V_27 ) ;
break;
case V_84 :
case V_85 :
case V_72 :
default:
F_2 ( L_9 ,
V_40 , V_69 -> V_76 ) ;
F_37 ( V_2 ) ;
F_11 ( V_27 ) ;
F_17 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_38 ( struct V_35 * V_36 ,
const struct V_26 * V_86 ,
T_2 V_87 , enum V_88 V_89 )
{
struct V_26 * V_27 ;
struct V_6 * V_7 ;
const struct V_68 * V_69 ;
T_1 V_37 ;
struct V_33 * V_34 ;
struct V_90 * V_91 ;
V_69 = F_31 ( V_86 ) ;
F_2 ( L_10 ,
F_32 ( V_69 -> V_92 ) , F_39 ( V_69 -> V_93 ) , V_87 , V_89 ) ;
V_37 = sizeof( * V_34 ) ;
if ( V_87 == V_94 )
V_37 += sizeof( * V_91 ) ;
V_27 = F_19 ( V_36 , V_37 ) ;
if ( ! V_27 )
return;
V_34 = F_20 ( V_27 , V_37 ) ;
memset ( V_34 , 0 , V_37 ) ;
V_34 -> V_46 . V_47 = V_87 ;
if ( V_87 == V_94 ) {
V_34 -> V_50 . V_95 = F_21 ( sizeof( * V_91 ) ) ;
V_34 -> V_46 . V_48 |= V_96 ;
V_91 = (struct V_90 * ) ( V_34 + 1 ) ;
V_91 -> V_97 = V_89 ;
}
F_40 ( V_27 , V_86 , V_59 , 0 ) ;
V_7 = F_9 ( V_27 ) ;
if ( V_7 ) {
F_25 ( V_36 , V_7 , V_27 ) ;
F_27 ( V_7 ) ;
} else {
V_36 -> V_78 . V_98 ( V_36 , V_27 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
F_38 ( V_2 -> V_12 -> V_99 -> V_36 ,
V_2 -> V_29 , V_94 , V_89 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
F_41 ( V_2 , V_89 ) ;
F_8 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_100 * V_34 ;
int V_38 ;
T_3 V_101 ;
V_34 = F_20 ( V_2 -> V_29 , sizeof( * V_34 ) ) ;
switch ( V_34 -> V_102 ) {
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
F_2 ( L_11 , V_34 -> V_102 ) ;
F_42 ( V_2 , V_113 ) ;
return;
}
V_38 = F_44 ( & V_2 -> V_8 , V_2 -> V_12 -> V_30 ,
& V_2 -> V_114 [ 0 ] , F_45 ( & V_34 -> V_115 ) ,
V_2 , V_101 , V_116 , 0 , V_117 ) ;
if ( V_38 < 0 )
F_42 ( V_2 , V_118 ) ;
}
void F_46 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_119 * V_120 = V_8 -> V_119 ;
enum V_88 V_89 ;
if ( V_2 -> V_39 )
return;
switch ( V_120 -> V_121 ) {
case V_122 :
V_89 = V_123 ;
break;
case V_124 :
V_89 = V_125 ;
break;
case V_126 :
V_89 = V_127 ;
break;
case V_128 :
case V_129 :
default:
V_89 = V_118 ;
break;
}
F_2 ( L_12 ,
V_120 -> V_130 , V_120 -> V_121 , V_89 ) ;
F_41 ( V_2 , V_89 ) ;
F_28 ( & V_2 -> V_8 ) ;
}
void F_47 ( struct V_8 * V_8 )
{
return;
}
static void F_48 ( struct V_28 * V_12 , struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 = V_12 -> V_99 -> V_36 ;
struct V_131 * V_30 = V_12 -> V_30 ;
int V_132 ;
V_132 = F_49 ( & V_30 -> V_31 , V_133 ) ;
if ( V_132 < 0 )
goto V_134;
V_2 = & ( (struct V_1 * ) V_30 -> V_135 ) [ V_132 ] ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_8 . V_32 = V_132 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = F_50 ( V_36 , V_27 ) ;
if ( ! V_2 -> V_13 ) {
F_12 ( & V_30 -> V_31 , V_132 ) ;
goto V_134;
}
V_2 -> V_29 = V_27 ;
F_51 ( & V_2 -> V_136 , V_137 ) ;
F_52 ( V_12 -> V_99 -> V_138 -> V_139 , & V_2 -> V_136 ) ;
return;
V_134:
F_2 ( L_13 ) ;
F_38 ( V_36 , V_27 , V_140 , 0 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
}
void F_53 ( struct V_28 * V_12 , struct V_26 * V_27 )
{
struct V_68 * V_69 = F_31 ( V_27 ) ;
switch ( V_69 -> V_76 ) {
case V_141 :
F_48 ( V_12 , V_27 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_72 :
case V_142 :
default:
F_2 ( L_9 ,
V_40 , V_69 -> V_76 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
break;
}
}
static void V_137 ( struct V_143 * V_136 )
{
struct V_1 * V_2 = F_15 ( V_136 , struct V_1 , V_136 ) ;
struct V_68 * V_69 = F_31 ( V_2 -> V_29 ) ;
struct V_100 * V_34 ;
int V_144 = 0 ;
int V_145 ;
V_34 = F_20 ( V_2 -> V_29 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
goto V_146;
if ( V_34 -> V_147 & V_148 )
goto V_146;
if ( V_34 -> V_102 ) {
F_43 ( V_2 ) ;
return;
}
switch ( V_34 -> V_147 & ( V_149 | V_150 ) ) {
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
switch ( V_34 -> V_154 & V_155 ) {
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
F_54 ( V_2 -> V_13 , F_34 , V_2 ) ;
V_2 -> V_8 . V_132 = F_5 ( V_2 -> V_13 ) -> V_22 ;
if ( F_55 ( & V_2 -> V_8 , V_2 -> V_12 -> V_30 , V_34 -> V_164 ,
& V_2 -> V_114 [ 0 ] , F_45 ( & V_34 -> V_115 ) ,
F_56 ( V_34 -> V_165 ) , V_145 , V_144 ,
V_117 | V_166 ) )
goto V_146;
F_2 ( L_14 , V_69 -> V_76 , V_2 ) ;
return;
V_146:
F_42 ( V_2 , V_113 ) ;
}
