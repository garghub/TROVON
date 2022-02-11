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
return F_17 ( V_8 , 0 ) ;
}
int F_18 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_37 * V_38 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
T_1 V_39 ;
int V_40 ;
if ( V_2 -> V_41 )
return 0 ;
F_6 ( V_2 , V_42 ) ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_43 ;
V_39 = sizeof( * V_38 ) + V_8 -> V_44 ;
V_27 = F_19 ( V_29 , V_39 ) ;
if ( ! V_27 ) {
V_8 -> V_45 = V_46 ;
return - V_47 ;
}
V_38 = F_20 ( V_27 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_48 . V_49 = V_8 -> V_45 ;
V_39 = V_8 -> V_44 ;
if ( V_39 ) {
V_38 -> V_48 . V_50 |= V_51 ;
V_38 -> V_52 . V_53 = F_21 ( V_39 ) ;
memcpy ( ( V_38 + 1 ) , V_8 -> V_54 , V_39 ) ;
}
if ( V_8 -> V_16 & ( V_55 | V_56 ) ) {
if ( V_8 -> V_16 & V_55 )
V_38 -> V_48 . V_50 |= V_57 ;
else
V_38 -> V_48 . V_50 |= V_58 ;
V_38 -> V_52 . V_59 = F_22 ( V_8 -> V_60 ) ;
}
V_2 -> V_13 = V_29 -> V_32 . V_61 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_62 , V_5 -> V_20 , V_5 -> V_19 , V_63 ,
V_64 | V_65 | V_66 , 0 ) ;
V_40 = V_29 -> V_32 . V_67 ( V_29 , V_2 -> V_13 , V_27 ) ;
if ( V_40 ) {
F_24 ( L_7
L_8 , V_42 , V_27 , V_5 -> V_68 ) ;
V_8 -> V_45 = V_46 ;
return - V_47 ;
}
V_29 -> V_32 . V_69 ( V_2 -> V_13 ) ;
F_25 ( & V_2 -> V_8 ) ;
return 0 ;
}
int F_26 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_70 != V_8 -> V_15 ;
}
int F_27 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_26 * V_27 ;
struct V_71 * V_72 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
struct V_73 * V_74 ;
T_2 V_75 ;
F_6 ( V_2 , V_42 ) ;
if ( V_2 -> V_41 )
return 0 ;
V_5 = F_5 ( V_2 -> V_13 ) ;
V_29 = V_5 -> V_43 ;
V_27 = F_19 ( V_29 , sizeof( * V_72 ) ) ;
if ( ! V_27 )
return - V_47 ;
V_72 = F_20 ( V_27 , sizeof( * V_72 ) ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_76 = F_21 ( V_8 -> V_15 ) ;
V_2 -> V_13 = V_29 -> V_32 . V_61 ( V_2 -> V_13 ) ;
F_23 ( V_27 , V_77 , V_5 -> V_20 , V_5 -> V_19 , V_63 ,
V_64 | V_66 | V_78 , 0 ) ;
V_74 = F_28 ( V_27 ) ;
V_75 = F_29 ( V_74 -> V_79 ) ;
if ( V_75 & V_64 ) {
if ( ( V_5 -> V_68 <= V_29 -> V_80 ) &&
( V_74 -> V_81 == V_77 ) ) {
if ( ( V_8 -> V_16 & V_82 ) &&
V_29 -> V_32 . V_83 ( V_29 , V_5 -> V_68 ,
V_8 -> V_84 ,
V_8 -> V_14 ) )
V_2 -> V_85 = 1 ;
}
}
V_29 -> V_32 . V_67 ( V_29 , V_2 -> V_13 , V_27 ) ;
return 0 ;
}
int F_30 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , struct V_26 * V_27 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_73 * V_74 ;
if ( F_32 ( V_27 ) ) {
V_2 -> V_13 = NULL ;
V_2 -> V_41 = true ;
return;
}
V_74 = F_28 ( V_27 ) ;
switch ( V_74 -> V_81 ) {
case V_87 :
F_33 ( V_2 , V_27 ) ;
break;
case V_88 :
case V_89 :
case V_77 :
default:
F_2 ( L_9 ,
V_42 , V_74 -> V_81 ) ;
F_34 ( V_2 ) ;
F_11 ( V_27 ) ;
F_17 ( & V_2 -> V_8 , 0 ) ;
break;
}
}
static void F_35 ( struct V_28 * V_29 ,
const struct V_26 * V_90 ,
T_2 V_91 , enum V_92 V_93 )
{
struct V_26 * V_27 ;
struct V_6 * V_7 ;
const struct V_73 * V_74 ;
T_1 V_39 ;
struct V_37 * V_38 ;
struct V_94 * V_95 ;
V_74 = F_28 ( V_90 ) ;
F_2 ( L_10 ,
F_29 ( V_74 -> V_96 ) , F_36 ( V_74 -> V_97 ) , V_91 , V_93 ) ;
V_39 = sizeof( * V_38 ) ;
if ( V_91 == V_98 )
V_39 += sizeof( * V_95 ) ;
V_27 = F_19 ( V_29 , V_39 ) ;
if ( ! V_27 )
return;
V_38 = F_20 ( V_27 , V_39 ) ;
memset ( V_38 , 0 , V_39 ) ;
V_38 -> V_48 . V_49 = V_91 ;
if ( V_91 == V_98 ) {
V_38 -> V_52 . V_99 = F_21 ( sizeof( * V_95 ) ) ;
V_38 -> V_48 . V_50 |= V_100 ;
V_95 = (struct V_94 * ) ( V_38 + 1 ) ;
V_95 -> V_101 = V_93 ;
}
F_37 ( V_27 , V_90 , V_62 , 0 ) ;
V_7 = F_10 ( V_27 ) ;
if ( V_7 ) {
V_29 -> V_32 . V_67 ( V_29 , V_7 , V_27 ) ;
V_29 -> V_32 . V_69 ( V_7 ) ;
} else {
V_29 -> V_32 . V_102 ( V_29 , V_27 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
enum V_92 V_93 )
{
F_35 ( V_2 -> V_12 -> V_103 -> V_29 ,
V_2 -> V_31 , V_98 , V_93 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
enum V_92 V_93 )
{
F_38 ( V_2 , V_93 ) ;
F_8 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_104 * V_38 ;
int V_40 ;
T_3 V_105 ;
V_38 = F_20 ( V_2 -> V_31 , sizeof( * V_38 ) ) ;
switch ( V_38 -> V_106 ) {
case V_107 :
V_105 = V_108 ;
break;
case V_109 :
V_105 = V_110 ;
break;
case V_111 :
V_105 = V_112 ;
break;
case V_113 :
V_105 = V_114 ;
break;
case V_115 :
V_105 = V_116 ;
break;
default:
F_2 ( L_11 , V_38 -> V_106 ) ;
F_39 ( V_2 , V_117 ) ;
return;
}
V_40 = F_41 ( & V_2 -> V_8 , V_2 -> V_12 -> V_34 ,
& V_2 -> V_118 [ 0 ] , F_42 ( & V_38 -> V_119 ) ,
V_2 , V_105 , V_120 , 0 , V_121 ) ;
if ( V_40 < 0 )
F_39 ( V_2 , V_122 ) ;
}
void F_43 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_8 , struct V_1 , V_8 ) ;
struct V_123 * V_124 = V_8 -> V_123 ;
enum V_92 V_93 ;
if ( V_2 -> V_41 )
return;
switch ( V_124 -> V_125 ) {
case V_126 :
V_93 = V_127 ;
break;
case V_128 :
V_93 = V_129 ;
break;
case V_130 :
V_93 = V_131 ;
break;
case V_132 :
case V_133 :
default:
V_93 = V_122 ;
break;
}
F_2 ( L_12 ,
V_124 -> V_134 , V_124 -> V_125 , V_93 ) ;
F_38 ( V_2 , V_93 ) ;
F_25 ( & V_2 -> V_8 ) ;
}
void F_44 ( struct V_8 * V_8 )
{
return;
}
static void F_45 ( struct V_30 * V_12 , struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_12 -> V_103 -> V_29 ;
struct V_135 * V_34 = V_12 -> V_34 ;
int V_136 ;
V_136 = F_46 ( & V_34 -> V_35 , V_137 ) ;
if ( V_136 < 0 )
goto V_138;
V_2 = & ( (struct V_1 * ) V_34 -> V_139 ) [ V_136 ] ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_8 . V_36 = V_136 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_29 -> V_32 . V_140 ( V_29 , V_27 ) ;
if ( ! V_2 -> V_13 ) {
F_12 ( & V_34 -> V_35 , V_136 ) ;
goto V_138;
}
V_2 -> V_31 = V_27 ;
F_47 ( & V_2 -> V_141 , V_142 ) ;
F_48 ( V_12 -> V_103 -> V_143 -> V_144 , & V_2 -> V_141 ) ;
return;
V_138:
F_2 ( L_13 ) ;
F_35 ( V_29 , V_27 , V_145 , 0 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
}
void F_49 ( struct V_30 * V_12 , struct V_26 * V_27 )
{
struct V_73 * V_74 = F_28 ( V_27 ) ;
switch ( V_74 -> V_81 ) {
case V_146 :
F_45 ( V_12 , V_27 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
case V_77 :
case V_147 :
default:
F_2 ( L_9 ,
V_42 , V_74 -> V_81 ) ;
F_11 ( V_27 ) ;
F_13 ( V_12 ) ;
break;
}
}
static void V_142 ( struct V_148 * V_141 )
{
struct V_1 * V_2 = F_15 ( V_141 , struct V_1 , V_141 ) ;
struct V_73 * V_74 = F_28 ( V_2 -> V_31 ) ;
struct V_104 * V_38 ;
int V_149 = 0 ;
int V_150 ;
V_38 = F_20 ( V_2 -> V_31 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
goto V_151;
if ( V_38 -> V_152 & V_153 )
goto V_151;
if ( V_38 -> V_106 ) {
F_40 ( V_2 ) ;
return;
}
switch ( V_38 -> V_152 & ( V_154 | V_155 ) ) {
case 0 :
V_149 = V_156 ;
break;
case V_154 :
V_149 = V_157 ;
break;
case V_155 :
V_149 = V_158 ;
break;
case V_155 | V_154 :
goto V_151;
}
switch ( V_38 -> V_159 & V_160 ) {
case V_161 :
V_150 = V_162 ;
break;
case V_163 :
V_150 = V_164 ;
break;
case V_165 :
V_150 = V_166 ;
break;
case V_167 :
default:
V_150 = V_168 ;
}
F_5 ( V_2 -> V_13 ) -> V_43 -> V_32 . V_169 ( V_2 -> V_13 , F_31 , V_2 ) ;
V_2 -> V_8 . V_136 = F_5 ( V_2 -> V_13 ) -> V_22 ;
if ( F_50 ( & V_2 -> V_8 , V_2 -> V_12 -> V_34 , V_38 -> V_170 ,
& V_2 -> V_118 [ 0 ] , F_42 ( & V_38 -> V_119 ) ,
F_51 ( V_38 -> V_171 ) , V_150 , V_149 ,
V_121 | V_172 ) )
goto V_151;
F_2 ( L_14 , V_74 -> V_81 , V_2 ) ;
return;
V_151:
F_39 ( V_2 , V_117 ) ;
}
