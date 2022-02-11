void F_1 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_4 )
{
if ( ! V_2 -> V_5 )
V_3 [ 0 ] = '\0' ;
snprintf ( V_3 , V_4 , L_1 , V_2 -> V_6 ) ;
}
static int F_2 (
struct V_1 * V_7 ,
struct V_1 * V_2 )
{
int V_8 ;
if ( V_7 ) {
V_8 = V_7 -> V_8 ;
return V_7 == V_2 ||
V_8 == V_9 ||
V_8 == V_10 ;
}
return 0 ;
}
static T_2
F_3 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_18 ;
switch ( V_12 -> V_19 [ 0 ] ) {
case V_20 :
case V_21 :
case V_22 :
return 0 ;
default:
break;
}
if ( ! V_14 -> V_23 || ! V_17 )
return 0 ;
if ( V_14 -> V_23 != V_17 -> V_24 )
return V_25 ;
if ( V_14 -> V_26 & V_27 ) {
if ( V_14 -> V_28 != V_17 -> V_29 )
return V_25 ;
}
return 0 ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
int V_33 = 0 ;
V_2 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( V_2 ) {
if ( V_2 -> V_7 ) {
F_6 ( V_2 ) ;
return 1 ;
}
if ( ( V_2 -> V_8 == V_34 ) ||
( V_2 -> V_8 == V_35 ) ||
( V_2 -> V_8 == V_9 ) ||
( V_2 -> V_8 == V_10 ) ) {
F_6 ( V_2 ) ;
return 1 ;
}
F_6 ( V_2 ) ;
V_33 = 1 ;
} else {
F_7 ( & V_31 -> V_36 ) ;
V_33 = ( F_8 ( & V_31 -> V_37 ) ) ? 0 : 1 ;
F_9 ( & V_31 -> V_36 ) ;
}
if ( V_33 ) {
F_10 ( L_2
L_3
L_4 ) ;
return - V_38 ;
}
return 0 ;
}
T_2
F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! V_17 || ! V_17 -> V_42 )
goto V_43;
V_41 = F_4 ( V_12 ) ;
if ( V_41 == 1 )
goto V_43;
if ( V_41 < 0 )
return V_25 ;
F_7 ( & V_14 -> V_44 ) ;
if ( ! V_14 -> V_23 || ! V_17 )
goto V_45;
if ( V_14 -> V_23 != V_17 -> V_24 )
goto V_45;
if ( V_14 -> V_28 != V_17 -> V_29 )
goto V_45;
V_14 -> V_23 = NULL ;
V_14 -> V_26 &= ~ V_46 ;
if ( V_14 -> V_26 & V_27 ) {
V_14 -> V_28 = 0 ;
V_14 -> V_26 &= ~ V_27 ;
}
V_40 = V_17 -> V_42 ;
F_12 ( L_5
L_6 ,
V_40 -> V_47 -> V_48 () ,
V_12 -> V_49 -> V_50 , V_12 -> V_51 ,
V_17 -> V_24 -> V_52 ) ;
V_45:
F_9 ( & V_14 -> V_44 ) ;
V_43:
F_13 ( V_12 , V_53 ) ;
return 0 ;
}
T_2
F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_39 * V_40 ;
T_2 V_54 = 0 ;
int V_41 ;
if ( ( V_12 -> V_19 [ 1 ] & 0x01 ) &&
( V_12 -> V_19 [ 1 ] & 0x02 ) ) {
F_10 ( L_7
L_8 ) ;
return V_55 ;
}
if ( ! V_17 || ! V_17 -> V_42 )
goto V_43;
V_41 = F_4 ( V_12 ) ;
if ( V_41 == 1 )
goto V_43;
if ( V_41 < 0 )
return V_25 ;
V_40 = V_17 -> V_42 ;
F_7 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_23 &&
( V_14 -> V_23 != V_17 -> V_24 ) ) {
F_10 ( L_9 ,
V_40 -> V_47 -> V_48 () ) ;
F_10 ( L_10 ,
V_12 -> V_49 -> V_50 ,
V_14 -> V_23 -> V_52 ) ;
F_10 ( L_11
L_12 , V_12 -> V_49 -> V_50 ,
V_12 -> V_51 ,
V_17 -> V_24 -> V_52 ) ;
V_54 = V_25 ;
goto V_45;
}
V_14 -> V_23 = V_17 -> V_24 ;
V_14 -> V_26 |= V_46 ;
if ( V_17 -> V_29 != 0 ) {
V_14 -> V_28 = V_17 -> V_29 ;
V_14 -> V_26 |= V_27 ;
}
F_12 ( L_13
L_14 , V_40 -> V_47 -> V_48 () ,
V_12 -> V_49 -> V_50 , V_12 -> V_51 ,
V_17 -> V_24 -> V_52 ) ;
V_45:
F_9 ( & V_14 -> V_44 ) ;
V_43:
if ( ! V_54 )
F_13 ( V_12 , V_53 ) ;
return V_54 ;
}
static int F_15 ( struct V_11 * V_12 , T_1 V_56 ,
bool V_57 )
{
unsigned char * V_58 = V_12 -> V_19 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_24 * V_59 = V_18 -> V_24 ;
int V_60 = 0 ;
int V_61 = 0 , V_54 = 1 ;
int V_62 = 0 , V_63 = 0 ;
int V_64 = 0 ;
int V_65 = 0 ;
if ( V_57 ) {
V_61 = 0 ;
} else {
struct V_66 * V_67 ;
F_16 () ;
V_67 = F_17 ( V_59 , V_12 -> V_51 ) ;
if ( V_67 )
V_61 = F_18 ( V_68 ,
& V_67 -> V_69 ) ;
F_19 () ;
}
switch ( V_56 ) {
case V_70 :
V_64 = 1 ;
case V_71 :
break;
case V_34 :
V_64 = 1 ;
case V_35 :
V_63 = 1 ;
break;
case V_9 :
V_64 = 1 ;
case V_10 :
V_62 = 1 ;
break;
default:
return - V_72 ;
}
switch ( V_58 [ 0 ] ) {
case V_73 :
if ( V_61 )
return 0 ;
V_54 = ( V_64 ) ? 0 : 1 ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
if ( V_65 ) {
V_54 = 1 ;
break;
}
if ( V_61 ) {
V_54 = 0 ;
break;
}
V_54 = ( V_64 ) ? 0 : 1 ;
break;
case V_79 :
switch ( V_58 [ 1 ] & 0x1f ) {
case V_80 :
case V_81 :
case V_82 :
V_54 = ( V_61 ) ? 0 : 1 ;
break;
case V_83 :
case V_84 :
V_54 = 0 ;
break;
case V_85 :
case V_86 :
V_54 = 1 ;
break;
case V_87 :
V_54 = ( V_61 ) ? 0 : 1 ;
break;
default:
F_10 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return - V_72 ;
}
break;
case V_21 :
case V_22 :
V_54 = 0 ;
break;
case V_88 :
case V_89 :
V_54 = 0 ;
break;
case V_90 :
V_54 = ( V_65 ) ? 1 : 0 ;
break;
case V_91 :
switch ( V_58 [ 1 ] & 0x1f ) {
case V_92 :
if ( V_61 ) {
V_54 = 0 ;
break;
}
V_54 = ( V_64 ) ? 0 : 1 ;
break;
case V_93 :
case V_94 :
if ( V_65 ) {
V_54 = 1 ;
break;
}
if ( V_61 ) {
V_54 = 0 ;
break;
}
V_54 = ( V_64 ) ? 0 : 1 ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_54 = 0 ;
break;
default:
F_10 ( L_17 ,
( V_58 [ 1 ] & 0x1f ) ) ;
return - V_72 ;
}
break;
case V_100 :
case V_101 :
case V_20 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_54 = 0 ;
break;
default:
V_60 = 1 ;
break;
}
if ( ! V_54 && ! V_60 ) {
F_12 ( L_18
L_19 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
return V_54 ;
}
if ( V_64 && ! V_61 ) {
if ( V_12 -> V_107 == V_108 ) {
F_12 ( L_20
L_21 ,
F_21 ( V_12 ) ,
V_18 -> V_24 -> V_52 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
return 1 ;
} else {
if ( ! V_61 ) {
F_12 ( L_22
L_23
L_24 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
}
return 0 ;
}
} else if ( ( V_63 ) || ( V_62 ) ) {
if ( V_61 ) {
F_12 ( L_25
L_26 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
return 0 ;
}
} else if ( V_64 && V_61 ) {
if ( V_12 -> V_107 == V_109 ) {
F_12 ( L_27
L_26 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
return 0 ;
}
}
F_12 ( L_28
L_29 , F_21 ( V_12 ) ,
( V_61 ) ? L_30 : L_31 ,
V_18 -> V_24 -> V_52 , V_58 [ 0 ] ,
F_20 ( V_56 ) ) ;
return 1 ;
}
static T_2
F_22 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_18 ;
T_1 V_56 ;
bool V_57 = false ;
if ( ! V_14 -> V_110 )
return 0 ;
V_56 = V_14 -> V_110 -> V_8 ;
V_12 -> V_111 = V_14 -> V_110 -> V_111 ;
if ( V_14 -> V_110 -> V_112 != V_17 -> V_24 )
goto V_113;
if ( V_14 -> V_110 -> V_5 ) {
if ( V_14 -> V_110 -> V_114 !=
V_17 -> V_29 ) {
V_57 = true ;
goto V_113;
}
}
return 0 ;
V_113:
if ( F_15 ( V_12 , V_56 , V_57 ) )
return V_25 ;
return 0 ;
}
static T_1 F_23 ( struct V_13 * V_14 )
{
T_1 V_115 ;
F_7 ( & V_14 -> V_44 ) ;
V_115 = V_14 -> V_32 . V_116 ++ ;
F_9 ( & V_14 -> V_44 ) ;
return V_115 ;
}
static struct V_1 * F_24 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_49 * V_117 ,
struct V_66 * V_118 ,
T_3 V_119 ,
unsigned char * V_120 ,
T_3 V_121 ,
int V_122 ,
int V_123 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_124 , V_125 ) ;
if ( ! V_2 ) {
F_10 ( L_32 ) ;
return NULL ;
}
F_26 ( & V_2 -> V_126 ) ;
F_26 ( & V_2 -> V_127 ) ;
F_26 ( & V_2 -> V_128 ) ;
F_26 ( & V_2 -> V_129 ) ;
F_26 ( & V_2 -> V_130 ) ;
F_27 ( & V_2 -> V_131 , 0 ) ;
V_2 -> V_112 = V_59 ;
if ( V_118 ) {
V_2 -> V_132 = V_118 ;
} else {
F_16 () ;
V_2 -> V_132 = F_17 ( V_59 , V_119 ) ;
if ( ! V_2 -> V_132 ) {
F_19 () ;
F_10 ( L_33 ,
V_59 -> V_52 , V_119 ) ;
F_28 ( V_124 , V_2 ) ;
return NULL ;
}
F_29 ( & V_2 -> V_132 -> V_133 ) ;
F_19 () ;
}
V_2 -> V_134 = V_119 ;
V_2 -> V_135 = V_117 -> V_50 ;
V_2 -> V_136 = V_117 -> V_137 ;
V_2 -> V_111 = V_121 ;
V_2 -> V_138 = V_122 ;
V_2 -> V_139 = V_123 ;
if ( V_120 != NULL ) {
V_2 -> V_114 = F_30 ( V_120 ) ;
snprintf ( V_2 -> V_6 , V_140 , L_34 , V_120 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_31 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_49 * V_117 ,
struct V_66 * V_141 ,
T_3 V_119 ,
unsigned char * V_120 ,
T_3 V_121 ,
int V_122 ,
int V_123 )
{
struct V_66 * V_142 ;
struct V_24 * V_143 ;
struct V_144 * V_145 ;
struct V_49 * V_146 , * V_147 , * V_148 ;
const struct V_149 * V_150 = V_59 -> V_42 -> V_47 ;
struct V_1 * V_2 , * V_151 , * V_152 , * V_153 ;
int V_54 ;
V_2 = F_24 ( V_14 , V_59 , V_117 , V_141 , V_119 ,
V_120 , V_121 , V_122 ,
V_123 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_122 )
return V_2 ;
F_7 ( & V_14 -> V_154 ) ;
F_32 (lun_tmp, next, &dev->dev_sep_list, lun_dev_link) {
if ( ! F_33 ( & V_146 -> V_155 ) )
continue;
F_9 ( & V_14 -> V_154 ) ;
F_7 ( & V_146 -> V_156 ) ;
F_34 (deve_tmp, &lun_tmp->lun_deve_list, lun_link) {
if ( ! V_142 -> V_144 )
continue;
V_145 = F_35 ( V_142 -> V_144 ,
F_36 ( & V_146 -> V_156 ) ) ;
V_143 = V_145 -> V_157 ;
if ( V_59 == V_143 )
continue;
if ( V_150 != V_143 -> V_42 -> V_47 )
continue;
if ( strcmp ( V_59 -> V_52 , V_143 -> V_52 ) )
continue;
F_29 ( & V_142 -> V_133 ) ;
F_9 ( & V_146 -> V_156 ) ;
V_54 = F_37 ( V_142 ) ;
if ( V_54 < 0 ) {
F_10 ( L_35
L_36 ) ;
F_38 ( & V_146 -> V_155 ) ;
F_39 ( & V_142 -> V_133 , V_158 ) ;
goto V_43;
}
V_148 = F_35 ( V_142 -> V_49 ,
F_40 ( & V_142 -> V_133 . V_159 ) != 0 ) ;
V_151 = F_24 ( V_14 ,
V_143 , V_148 , V_142 ,
V_142 -> V_119 , NULL ,
V_121 , V_122 , V_123 ) ;
if ( ! V_151 ) {
F_38 ( & V_146 -> V_155 ) ;
F_41 ( V_142 ) ;
goto V_43;
}
F_42 ( & V_151 -> V_130 ,
& V_2 -> V_129 ) ;
F_7 ( & V_146 -> V_156 ) ;
}
F_9 ( & V_146 -> V_156 ) ;
F_7 ( & V_14 -> V_154 ) ;
F_38 ( & V_146 -> V_155 ) ;
}
F_9 ( & V_14 -> V_154 ) ;
return V_2 ;
V_43:
F_32 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_43 ( & V_152 -> V_130 ) ;
F_41 ( V_152 -> V_132 ) ;
F_28 ( V_124 , V_152 ) ;
}
F_28 ( V_124 , V_2 ) ;
return NULL ;
}
int F_44 (
struct V_30 * V_31 ,
T_3 V_121 ,
unsigned char * V_160 ,
unsigned char * V_120 ,
T_3 V_119 ,
unsigned char * V_161 ,
T_4 V_162 ,
T_3 V_163 ,
int V_164 ,
int V_122 ,
T_5 type )
{
struct V_1 * V_2 ;
if ( ! V_160 || ! V_161 || ! V_121 ) {
F_10 ( L_37 ) ;
return - V_72 ;
}
V_2 = F_25 ( V_124 , V_165 ) ;
if ( ! V_2 ) {
F_10 ( L_32 ) ;
return - V_166 ;
}
F_26 ( & V_2 -> V_126 ) ;
F_26 ( & V_2 -> V_127 ) ;
F_26 ( & V_2 -> V_128 ) ;
F_26 ( & V_2 -> V_129 ) ;
F_26 ( & V_2 -> V_130 ) ;
F_27 ( & V_2 -> V_131 , 0 ) ;
V_2 -> V_112 = NULL ;
V_2 -> V_132 = NULL ;
V_2 -> V_134 = V_119 ;
V_2 -> V_135 = V_163 ;
V_2 -> V_111 = V_121 ;
V_2 -> V_138 = V_122 ;
V_2 -> V_139 = 1 ;
V_2 -> V_167 = 0 ;
V_2 -> V_8 = type ;
if ( V_120 != NULL ) {
V_2 -> V_114 = F_30 ( V_120 ) ;
snprintf ( V_2 -> V_6 , V_140 , L_34 , V_120 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_168 , V_169 , L_34 , V_160 ) ;
snprintf ( V_2 -> V_170 , V_171 , L_34 , V_161 ) ;
V_2 -> V_172 = V_162 ;
V_2 -> V_7 = V_164 ;
F_42 ( & V_2 -> V_128 , & V_31 -> V_173 ) ;
F_12 ( L_38
L_39 , ( V_164 ) ? L_40 : L_30 ) ;
return 0 ;
}
static void F_45 (
struct V_13 * V_14 ,
struct V_39 * V_40 ,
struct V_24 * V_174 ,
struct V_1 * V_2 )
{
char V_175 [ V_176 ] ;
memset ( V_175 , 0 , V_176 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
F_7 ( & V_14 -> V_44 ) ;
V_14 -> V_110 = V_2 ;
F_9 ( & V_14 -> V_44 ) ;
F_12 ( L_41
L_42 ,
V_40 -> V_47 -> V_48 () ,
F_20 ( V_2 -> V_8 ) ,
( V_2 -> V_138 ) ? 1 : 0 ) ;
F_12 ( L_43 ,
V_40 -> V_47 -> V_48 () , V_174 -> V_52 ,
V_175 ) ;
}
static int F_46 (
struct V_13 * V_14 ,
struct V_39 * V_40 ,
struct V_49 * V_117 ,
T_3 V_163 ,
struct V_24 * V_59 ,
T_3 V_119 )
{
struct V_1 * V_2 , * V_152 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char V_160 [ V_169 ] ;
unsigned char V_161 [ V_171 ] ;
T_4 V_162 ;
memset ( V_160 , 0 , V_169 ) ;
memset ( V_161 , 0 , V_171 ) ;
snprintf ( V_160 , V_169 , L_34 , V_59 -> V_52 ) ;
snprintf ( V_161 , V_171 , L_34 ,
V_40 -> V_47 -> V_177 ( V_40 ) ) ;
V_162 = V_40 -> V_47 -> V_178 ( V_40 ) ;
F_7 ( & V_31 -> V_179 ) ;
F_32 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_168 , V_160 ) &&
( V_2 -> V_134 == V_119 ) &&
! ( strcmp ( V_2 -> V_170 , V_161 ) ) &&
( V_2 -> V_172 == V_162 ) &&
( V_2 -> V_135 == V_163 ) ) {
F_16 () ;
V_2 -> V_132 = F_17 ( V_59 , V_119 ) ;
if ( ! V_2 -> V_132 ) {
F_10 ( L_44
L_45 , V_59 -> V_52 , V_119 ) ;
F_19 () ;
continue;
}
F_29 ( & V_2 -> V_132 -> V_133 ) ;
F_19 () ;
V_2 -> V_112 = V_59 ;
V_2 -> V_136 = V_117 -> V_137 ;
F_43 ( & V_2 -> V_128 ) ;
F_9 ( & V_31 -> V_179 ) ;
F_47 ( V_14 , V_59 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_7 )
F_45 ( V_14 , V_40 ,
V_59 , V_2 ) ;
F_7 ( & V_31 -> V_179 ) ;
V_31 -> V_180 = 1 ;
}
}
F_9 ( & V_31 -> V_179 ) ;
return 0 ;
}
int F_48 (
struct V_13 * V_14 ,
struct V_39 * V_40 ,
struct V_49 * V_117 ,
struct V_24 * V_59 ,
T_3 V_119 )
{
if ( V_14 -> V_26 & V_46 )
return 0 ;
return F_46 ( V_14 , V_40 , V_117 ,
V_117 -> V_50 , V_59 ,
V_119 ) ;
}
static void F_49 (
const struct V_149 * V_150 ,
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_1 * V_2 ,
enum V_181 V_181 )
{
struct V_39 * V_42 = V_59 -> V_42 ;
char V_175 [ V_176 ] ;
memset ( & V_175 [ 0 ] , 0 , V_176 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
F_12 ( L_46
L_47 , V_150 -> V_48 () , ( V_181 == V_182 ) ?
L_48 : ( V_181 == V_183 ) ?
L_49 : L_30 , V_59 -> V_52 ,
V_175 ) ;
F_12 ( L_50 ,
V_150 -> V_48 () , V_150 -> V_177 ( V_42 ) ,
V_150 -> V_178 ( V_42 ) ) ;
F_12 ( L_51
L_52 , V_150 -> V_48 () ,
( V_2 -> V_138 ) ? L_53 : L_54 ,
V_14 -> V_184 -> V_185 ) ;
F_12 ( L_55
L_56 , V_150 -> V_48 () ,
V_2 -> V_111 , V_2 -> V_186 ,
V_2 -> V_139 ) ;
}
static void F_47 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_1 * V_2 ,
enum V_181 V_181 ,
int V_187 )
{
const struct V_149 * V_150 = V_59 -> V_42 -> V_47 ;
struct V_1 * V_152 , * V_153 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_66 * V_141 ;
V_2 -> V_186 = ( V_187 ) ?
V_14 -> V_32 . V_116 ++ :
F_23 ( V_14 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_42 ( & V_2 -> V_126 , & V_31 -> V_37 ) ;
F_49 ( V_150 , V_14 , V_59 , V_2 , V_181 ) ;
F_9 ( & V_31 -> V_36 ) ;
if ( ! V_2 -> V_138 || V_187 )
goto V_43;
F_32 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
struct V_24 * V_143 = V_152 -> V_112 ;
F_43 ( & V_152 -> V_130 ) ;
V_152 -> V_186 = F_23 ( V_14 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_42 ( & V_152 -> V_126 ,
& V_31 -> V_37 ) ;
F_49 ( V_150 , V_14 , V_143 , V_152 ,
V_181 ) ;
F_9 ( & V_31 -> V_36 ) ;
F_16 () ;
V_141 = V_152 -> V_132 ;
if ( V_141 ) {
F_50 ( V_68 , & V_141 -> V_69 ) ;
F_41 ( V_141 ) ;
V_152 -> V_132 = NULL ;
}
F_19 () ;
}
V_43:
F_16 () ;
V_141 = V_2 -> V_132 ;
if ( V_141 ) {
F_50 ( V_68 , & V_141 -> V_69 ) ;
F_39 ( & V_141 -> V_133 , V_158 ) ;
V_2 -> V_132 = NULL ;
}
F_19 () ;
}
static int F_51 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_49 * V_117 ,
struct V_66 * V_141 ,
T_3 V_119 ,
unsigned char * V_120 ,
T_3 V_121 ,
int V_122 ,
int V_123 ,
enum V_181 V_181 ,
int V_187 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_14 , V_59 , V_117 , V_141 , V_119 ,
V_120 , V_121 , V_122 ,
V_123 ) ;
if ( ! V_2 )
return - V_188 ;
F_47 ( V_14 , V_59 , V_2 ,
V_181 , V_187 ) ;
return 0 ;
}
static struct V_1 * F_52 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
unsigned char * V_120 )
{
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_152 ;
struct V_39 * V_40 ;
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_112 != V_59 )
continue;
V_40 = V_2 -> V_112 -> V_42 ;
if ( ! V_2 -> V_5 ) {
if ( V_40 -> V_47 -> V_189 != NULL ) {
if ( V_14 -> V_190 . V_191 )
continue;
}
F_53 ( & V_2 -> V_131 ) ;
F_9 ( & V_31 -> V_36 ) ;
return V_2 ;
}
if ( ! V_120 )
continue;
if ( strcmp ( V_120 , V_2 -> V_6 ) )
continue;
F_53 ( & V_2 -> V_131 ) ;
F_9 ( & V_31 -> V_36 ) ;
return V_2 ;
}
F_9 ( & V_31 -> V_36 ) ;
return NULL ;
}
static struct V_1 * F_5 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_16 * V_17 )
{
struct V_39 * V_40 = V_59 -> V_42 ;
unsigned char V_3 [ V_140 ] , * V_192 = NULL ;
if ( V_40 -> V_47 -> V_189 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_140 ) ;
V_40 -> V_47 -> V_189 ( V_17 , & V_3 [ 0 ] ,
V_140 ) ;
V_192 = & V_3 [ 0 ] ;
}
return F_52 ( V_14 , V_59 , V_192 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_131 ) ;
}
static int F_55 (
struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_24 * V_59 = V_2 -> V_112 ;
struct V_1 * V_7 ;
int V_54 = 0 ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ! V_7 ) {
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
if ( V_7 == V_2 ) {
F_56 ( V_14 , V_59 , V_2 , 0 , 1 ) ;
V_54 = 1 ;
} else if ( V_2 -> V_138 &&
( ! strcmp ( V_7 -> V_112 -> V_52 ,
V_2 -> V_112 -> V_52 ) ) &&
( V_7 -> V_111 == V_2 -> V_111 ) ) {
F_10 ( L_57
L_58
L_59
L_60 , V_2 -> V_111 ) ;
V_54 = - V_188 ;
}
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
static void F_57 (
struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_193 * V_194 ,
int V_195 )
__releases( &pr_tmpl->registration_lock
void F_58 (
struct V_13 * V_14 ,
struct V_24 * V_59 )
{
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_152 , * V_7 ;
bool V_196 = false ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ( V_7 != NULL ) &&
( V_7 -> V_112 == V_59 ) ) {
F_56 ( V_14 , V_59 , V_7 , 0 , 1 ) ;
V_196 = true ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
if ( V_7 && V_196 )
F_57 ( V_14 , V_7 , NULL , 0 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_112 != V_59 )
continue;
F_57 ( V_14 , V_2 , NULL , 0 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
}
void F_59 (
struct V_13 * V_14 )
{
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_152 , * V_7 ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 != NULL ) {
struct V_24 * V_197 = V_7 -> V_112 ;
F_56 ( V_14 , V_197 ,
V_7 , 0 , 0 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_57 ( V_14 , V_2 , NULL , 0 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_179 ) ;
F_32 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_43 ( & V_2 -> V_128 ) ;
F_28 ( V_124 , V_2 ) ;
}
F_9 ( & V_31 -> V_179 ) ;
}
static int F_60 ( struct V_39 * V_40 )
{
return F_61 ( & V_40 -> V_198 . V_199 ) ;
}
static void F_62 ( struct V_39 * V_40 )
{
F_63 ( & V_40 -> V_198 . V_199 ) ;
F_54 ( & V_40 -> V_200 ) ;
}
static int F_64 ( struct V_24 * V_59 )
{
if ( V_59 -> V_201 )
return 0 ;
return F_61 ( & V_59 -> V_202 . V_199 ) ;
}
static void F_65 ( struct V_24 * V_59 )
{
if ( ! V_59 -> V_201 )
F_63 ( & V_59 -> V_202 . V_199 ) ;
F_54 ( & V_59 -> V_203 ) ;
}
static int F_37 ( struct V_66 * V_67 )
{
struct V_144 * V_204 ;
V_204 = F_35 ( V_67 -> V_144 ,
F_40 ( & V_67 -> V_133 . V_159 ) != 0 ) ;
if ( ! V_204 )
return 0 ;
return F_61 ( & V_204 -> V_205 . V_199 ) ;
}
static void F_41 ( struct V_66 * V_67 )
{
struct V_144 * V_204 ;
V_204 = F_35 ( V_67 -> V_144 ,
F_40 ( & V_67 -> V_133 . V_159 ) != 0 ) ;
if ( ! V_204 ) {
F_39 ( & V_67 -> V_133 , V_158 ) ;
return;
}
F_63 ( & V_204 -> V_205 . V_199 ) ;
F_39 ( & V_67 -> V_133 , V_158 ) ;
}
static T_2
F_66 (
struct V_11 * V_12 ,
struct V_39 * V_40 ,
unsigned char * V_206 ,
T_3 V_121 ,
int V_122 ,
int V_123 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_39 * V_207 = NULL , * V_208 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_24 * V_209 = NULL ;
struct V_66 * V_210 = NULL ;
struct V_1 * V_211 , * V_212 , * V_213 ;
struct V_1 * V_152 , * V_153 ;
F_67 ( V_214 ) ;
struct V_215 * V_216 , * V_217 , * V_218 ;
unsigned char * V_3 , * V_219 , V_220 ;
const unsigned char * V_221 = NULL ;
char * V_222 = NULL , V_175 [ V_176 ] ;
T_2 V_54 ;
T_1 V_223 , V_224 = 0 ;
T_1 V_225 = 0 ;
V_216 = F_68 ( sizeof( struct V_215 ) , V_165 ) ;
if ( ! V_216 ) {
F_10 ( L_61 ) ;
return V_226 ;
}
F_26 ( & V_216 -> V_227 ) ;
V_216 -> V_207 = V_40 ;
V_216 -> V_209 = V_18 -> V_24 ;
V_212 = F_31 ( V_12 -> V_15 ,
V_18 -> V_24 , V_12 -> V_49 ,
NULL , V_12 -> V_51 , V_206 ,
V_121 , V_122 , V_123 ) ;
if ( ! V_212 ) {
F_69 ( V_216 ) ;
return V_226 ;
}
V_216 -> V_211 = V_212 ;
V_216 -> V_210 = NULL ;
F_42 ( & V_216 -> V_227 , & V_214 ) ;
if ( V_12 -> V_228 < 28 ) {
F_70 ( L_62
L_63 , V_12 -> V_228 ) ;
V_54 = V_229 ;
goto V_43;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_226 ;
goto V_43;
}
V_223 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_223 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_223 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_223 |= V_3 [ 27 ] & 0xff ;
if ( ( V_223 + 28 ) != V_12 -> V_228 ) {
F_10 ( L_64
L_65 , V_223 ,
V_12 -> V_228 ) ;
V_54 = V_229 ;
goto V_230;
}
V_219 = & V_3 [ 28 ] ;
while ( V_223 > 0 ) {
struct V_49 * V_148 , * V_231 ;
V_220 = ( V_219 [ 0 ] & 0x0f ) ;
V_207 = NULL ;
F_7 ( & V_14 -> V_154 ) ;
F_34 (tmp_lun, &dev->dev_sep_list, lun_dev_link) {
V_208 = V_231 -> V_232 ;
if ( V_208 -> V_233 != V_220 )
continue;
V_225 = V_231 -> V_137 ;
V_221 = F_72 ( V_208 ,
( const char * ) V_219 , & V_224 , & V_222 ) ;
if ( ! V_221 )
continue;
F_53 ( & V_208 -> V_200 ) ;
F_9 ( & V_14 -> V_154 ) ;
if ( F_60 ( V_208 ) ) {
F_10 ( L_66
L_67 ) ;
F_54 ( & V_208 -> V_200 ) ;
V_54 = V_226 ;
goto V_230;
}
F_73 ( & V_208 -> V_234 ) ;
V_209 = F_74 (
V_208 , V_221 ) ;
if ( V_209 )
F_53 ( & V_209 -> V_203 ) ;
F_75 ( & V_208 -> V_234 ) ;
if ( ! V_209 ) {
F_62 ( V_208 ) ;
F_7 ( & V_14 -> V_154 ) ;
continue;
}
if ( F_64 ( V_209 ) ) {
F_10 ( L_68
L_69 ) ;
F_54 ( & V_209 -> V_203 ) ;
F_62 ( V_208 ) ;
V_54 = V_226 ;
goto V_230;
}
V_207 = V_208 ;
F_12 ( L_70
L_71 ,
V_207 -> V_47 -> V_48 () ,
V_209 -> V_52 , V_225 ) ;
F_7 ( & V_14 -> V_154 ) ;
break;
}
F_9 ( & V_14 -> V_154 ) ;
if ( ! V_207 ) {
F_10 ( L_72
L_73 ) ;
V_54 = V_229 ;
goto V_230;
}
F_12 ( L_74
L_75 ,
V_207 -> V_47 -> V_48 () , V_12 -> V_228 ,
V_223 , V_224 , V_221 , V_222 ) ;
if ( V_224 > V_223 ) {
F_10 ( L_76
L_77 , V_224 , V_219 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
V_54 = V_229 ;
goto V_230;
}
V_210 = F_76 ( V_209 ,
V_225 ) ;
if ( ! V_210 ) {
F_10 ( L_78
L_79 ,
V_207 -> V_47 -> V_48 () ,
V_225 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
V_54 = V_229 ;
goto V_230;
}
if ( F_37 ( V_210 ) ) {
F_10 ( L_80
L_81 ) ;
F_39 ( & V_210 -> V_133 , V_158 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
V_54 = V_226 ;
goto V_230;
}
F_12 ( L_82
L_83 ,
V_207 -> V_47 -> V_48 () ,
V_209 -> V_52 , V_210 -> V_119 ) ;
V_213 = F_52 ( V_14 , V_209 ,
V_222 ) ;
if ( V_213 ) {
F_6 ( V_213 ) ;
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
V_219 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
continue;
}
V_216 = F_68 ( sizeof( struct V_215 ) ,
V_165 ) ;
if ( ! V_216 ) {
F_10 ( L_61 ) ;
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
V_54 = V_226 ;
goto V_230;
}
F_26 ( & V_216 -> V_227 ) ;
V_216 -> V_207 = V_207 ;
V_216 -> V_209 = V_209 ;
V_216 -> V_210 = V_210 ;
V_148 = F_35 ( V_210 -> V_49 ,
F_40 ( & V_210 -> V_133 . V_159 ) != 0 ) ;
V_211 = F_31 ( V_12 -> V_15 ,
V_209 , V_148 , V_210 ,
V_210 -> V_119 , V_222 ,
V_121 , V_122 , V_123 ) ;
if ( ! V_211 ) {
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
F_69 ( V_216 ) ;
V_54 = V_229 ;
goto V_230;
}
V_216 -> V_211 = V_211 ;
F_42 ( & V_216 -> V_227 , & V_214 ) ;
V_219 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
}
F_77 ( V_12 ) ;
F_32 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_207 = V_217 -> V_207 ;
V_209 = V_217 -> V_209 ;
V_210 = V_217 -> V_210 ;
V_211 = V_217 -> V_211 ;
F_43 ( & V_217 -> V_227 ) ;
F_69 ( V_217 ) ;
memset ( V_175 , 0 , V_176 ) ;
F_1 ( V_211 , V_175 , V_176 ) ;
F_47 ( V_12 -> V_15 , V_209 ,
V_211 , 0 , 0 ) ;
F_12 ( L_84
L_85
L_45 , V_207 -> V_47 -> V_48 () ,
V_209 -> V_52 , V_175 , ( V_210 ) ?
V_210 -> V_119 : 0 ) ;
if ( ! V_210 ) {
F_39 ( & V_212 -> V_132 -> V_133 ,
V_158 ) ;
continue;
}
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
}
return 0 ;
V_230:
F_77 ( V_12 ) ;
V_43:
F_32 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_207 = V_217 -> V_207 ;
V_209 = V_217 -> V_209 ;
V_210 = V_217 -> V_210 ;
V_211 = V_217 -> V_211 ;
F_43 ( & V_217 -> V_227 ) ;
F_69 ( V_217 ) ;
F_32 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_43 ( & V_152 -> V_130 ) ;
F_41 ( V_152 -> V_132 ) ;
F_28 ( V_124 , V_152 ) ;
}
F_28 ( V_124 , V_211 ) ;
if ( ! V_210 ) {
F_39 ( & V_212 -> V_132 -> V_133 ,
V_158 ) ;
continue;
}
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_207 ) ;
}
return V_54 ;
}
static int F_78 (
struct V_13 * V_14 ,
unsigned char * V_3 ,
T_1 V_235 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned char V_236 [ 512 ] , V_237 [ 32 ] ;
T_6 V_238 = 0 ;
int V_239 = 0 ;
int V_54 = 0 ;
F_7 ( & V_14 -> V_44 ) ;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_34 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
V_236 [ 0 ] = '\0' ;
V_237 [ 0 ] = '\0' ;
V_40 = V_2 -> V_112 -> V_42 ;
if ( V_2 -> V_5 )
snprintf ( V_237 , 32 , L_86 ,
V_2 -> V_6 ) ;
if ( V_14 -> V_110 == V_2 ) {
snprintf ( V_236 , 512 , L_87
L_88
L_89
L_90
L_91
L_92
L_93 , V_239 ,
V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_52 , V_237 ,
V_2 -> V_111 , V_2 -> V_8 ,
V_2 -> V_167 , V_2 -> V_138 ,
V_2 -> V_134 ) ;
} else {
snprintf ( V_236 , 512 , L_94
L_95
L_96
L_97 ,
V_239 , V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_52 , V_237 ,
V_2 -> V_111 , V_2 -> V_138 ,
V_2 -> V_134 ) ;
}
if ( ( V_238 + strlen ( V_236 ) >= V_235 ) ) {
F_10 ( L_98
L_99 ) ;
V_54 = - V_240 ;
goto V_43;
}
V_238 += sprintf ( V_3 + V_238 , L_34 , V_236 ) ;
snprintf ( V_236 , 512 , L_100
L_101
L_102 , V_40 -> V_47 -> V_48 () ,
V_40 -> V_47 -> V_177 ( V_40 ) ,
V_40 -> V_47 -> V_178 ( V_40 ) ,
V_2 -> V_136 , V_2 -> V_135 ,
V_239 ) ;
if ( ( V_238 + strlen ( V_236 ) >= V_235 ) ) {
F_10 ( L_98
L_99 ) ;
V_54 = - V_240 ;
goto V_43;
}
V_238 += sprintf ( V_3 + V_238 , L_34 , V_236 ) ;
V_239 ++ ;
}
if ( ! V_239 )
V_238 += sprintf ( V_3 + V_238 , L_103 ) ;
V_43:
F_9 ( & V_14 -> V_32 . V_36 ) ;
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
static int F_79 (
struct V_13 * V_14 ,
unsigned char * V_3 )
{
struct V_241 * V_242 = & V_14 -> V_241 ;
struct V_243 * V_243 ;
int V_244 = V_245 | V_246 | V_247 ;
char V_248 [ 512 ] ;
T_1 V_235 ;
int V_54 ;
memset ( V_248 , 0 , 512 ) ;
if ( strlen ( & V_242 -> V_249 [ 0 ] ) >= 512 ) {
F_10 ( L_104
L_105 ) ;
return - V_240 ;
}
snprintf ( V_248 , 512 , L_106 , V_250 , & V_242 -> V_249 [ 0 ] ) ;
V_243 = F_80 ( V_248 , V_244 , 0600 ) ;
if ( F_81 ( V_243 ) ) {
F_10 ( L_107
L_81 , V_248 ) ;
return F_82 ( V_243 ) ;
}
V_235 = ( strlen ( V_3 ) + 1 ) ;
V_54 = F_83 ( V_243 , V_3 , V_235 , 0 ) ;
if ( V_54 < 0 )
F_12 ( L_108 , V_248 ) ;
F_84 ( V_243 ) ;
return ( V_54 < 0 ) ? - V_251 : 0 ;
}
static T_2 F_85 ( struct V_13 * V_14 , bool V_123 )
{
unsigned char * V_3 ;
int V_41 , V_238 = V_252 ;
if ( ! V_123 ) {
char * V_253 = L_109 ;
V_41 = F_79 ( V_14 , V_253 ) ;
V_14 -> V_32 . V_180 = 0 ;
F_12 ( L_110 ) ;
if ( V_41 )
return V_226 ;
return 0 ;
}
V_254:
V_3 = F_86 ( V_238 ) ;
if ( ! V_3 )
return V_255 ;
V_41 = F_78 ( V_14 , V_3 , V_238 ) ;
if ( V_41 < 0 ) {
F_87 ( V_3 ) ;
V_238 *= 2 ;
goto V_254;
}
V_41 = F_79 ( V_14 , V_3 ) ;
if ( V_41 != 0 ) {
F_10 ( L_111 ) ;
F_87 ( V_3 ) ;
return V_226 ;
}
V_14 -> V_32 . V_180 = 1 ;
F_87 ( V_3 ) ;
F_12 ( L_112 ) ;
return 0 ;
}
static T_2
F_88 ( struct V_11 * V_12 , T_3 V_256 , T_3 V_121 ,
bool V_123 , bool V_122 , bool V_257 , enum V_181 V_181 )
{
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_258 , * V_152 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char V_237 [ V_140 ] , * V_192 = NULL ;
T_2 V_54 = V_259 ;
int V_260 = 0 , type ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_113 ) ;
return V_226 ;
}
V_42 = V_18 -> V_42 ;
if ( V_42 -> V_47 -> V_189 ) {
memset ( & V_237 [ 0 ] , 0 , V_140 ) ;
V_42 -> V_47 -> V_189 ( V_18 , & V_237 [ 0 ] ,
V_140 ) ;
V_192 = & V_237 [ 0 ] ;
}
V_2 = F_5 ( V_14 , V_18 -> V_24 , V_18 ) ;
if ( ! V_2 ) {
if ( V_256 ) {
F_70 ( L_114
L_115 ) ;
return V_25 ;
}
if ( ! V_121 )
return 0 ;
if ( ! V_257 ) {
if ( F_51 ( V_12 -> V_15 ,
V_18 -> V_24 , V_12 -> V_49 ,
NULL , V_12 -> V_51 , V_192 ,
V_121 , V_122 , V_123 ,
V_181 , 0 ) ) {
F_10 ( L_116
L_117 ) ;
return V_229 ;
}
} else {
V_54 = F_66 ( V_12 , V_42 ,
V_192 , V_121 , V_122 , V_123 ) ;
if ( V_54 != 0 )
return V_54 ;
}
return F_85 ( V_14 , V_123 ) ;
}
if ( ( V_181 == REGISTER ) && ( V_256 != V_2 -> V_111 ) ) {
F_10 ( L_118
L_119
L_120
L_121 , V_256 ,
V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_43;
}
if ( V_257 ) {
F_10 ( L_122
L_123 ) ;
V_54 = V_229 ;
goto V_43;
}
if ( V_2 -> V_138 && ! V_122 ) {
F_10 ( L_124
L_125
L_126 ) ;
V_54 = V_261 ;
goto V_43;
}
if ( V_121 ) {
V_2 -> V_186 = F_23 ( V_12 -> V_15 ) ;
V_2 -> V_111 = V_121 ;
F_12 ( L_127
L_128
L_129 , V_12 -> V_262 -> V_48 () ,
( V_181 == V_183 ) ? L_49 : L_30 ,
V_2 -> V_112 -> V_52 ,
V_2 -> V_111 , V_2 -> V_186 ) ;
} else {
type = V_2 -> V_8 ;
V_260 = F_55 ( V_12 -> V_15 ,
V_2 ) ;
if ( V_260 < 0 ) {
V_54 = V_25 ;
goto V_43;
}
F_7 ( & V_31 -> V_36 ) ;
if ( V_2 -> V_138 ) {
F_32 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_258 -> V_138 )
continue;
if ( V_258 -> V_111 != V_256 )
continue;
if ( V_2 == V_258 )
continue;
if ( strcmp ( V_2 -> V_112 -> V_52 ,
V_258 -> V_112 -> V_52 ) )
continue;
F_57 ( V_14 ,
V_258 , NULL , 0 ) ;
}
}
F_57 ( V_12 -> V_15 , V_2 , NULL , 1 ) ;
V_2 = NULL ;
if ( V_260 &&
( type == V_34 ||
type == V_35 ) ) {
F_34 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_89 (
V_258 -> V_112 ,
V_258 -> V_134 ,
0x2A ,
V_263 ) ;
}
}
F_9 ( & V_31 -> V_36 ) ;
}
V_54 = F_85 ( V_14 , V_123 ) ;
V_43:
if ( V_2 )
F_6 ( V_2 ) ;
return V_54 ;
}
unsigned char * F_20 ( int type )
{
switch ( type ) {
case V_70 :
return L_130 ;
case V_71 :
return L_131 ;
case V_34 :
return L_132 ;
case V_35 :
return L_133 ;
case V_9 :
return L_134 ;
case V_10 :
return L_135 ;
default:
break;
}
return L_136 ;
}
static T_2
F_90 ( struct V_11 * V_12 , int type , int V_264 , T_3 V_256 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_1 * V_2 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
char V_175 [ V_176 ] ;
T_2 V_54 ;
memset ( V_175 , 0 , V_176 ) ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_113 ) ;
return V_226 ;
}
V_2 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_137
L_138 ) ;
return V_226 ;
}
if ( V_256 != V_2 -> V_111 ) {
F_10 ( L_139
L_140
L_121 , V_256 , V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_265;
}
if ( V_264 != V_266 ) {
F_10 ( L_141 , V_264 ) ;
V_54 = V_229 ;
goto V_265;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 ) {
if ( ! F_2 ( V_7 , V_2 ) ) {
struct V_24 * V_197 = V_7 -> V_112 ;
F_10 ( L_142
L_143
L_144 ,
V_12 -> V_262 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_197 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_265;
}
if ( ( V_7 -> V_8 != type ) ||
( V_7 -> V_167 != V_264 ) ) {
struct V_24 * V_197 = V_7 -> V_112 ;
F_10 ( L_142
L_145
L_146
L_4 ,
V_12 -> V_262 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_197 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_265;
}
F_9 ( & V_14 -> V_44 ) ;
V_54 = 0 ;
goto V_265;
}
V_2 -> V_167 = V_264 ;
V_2 -> V_8 = type ;
V_2 -> V_7 = 1 ;
V_14 -> V_110 = V_2 ;
F_1 ( V_2 , V_175 , V_176 ) ;
F_12 ( L_147
L_148 ,
V_12 -> V_262 -> V_48 () , F_20 ( type ) ,
( V_2 -> V_138 ) ? 1 : 0 ) ;
F_12 ( L_43 ,
V_12 -> V_262 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_175 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( V_31 -> V_180 )
F_85 ( V_12 -> V_15 , true ) ;
V_54 = 0 ;
V_265:
F_6 ( V_2 ) ;
return V_54 ;
}
static T_2
F_91 ( struct V_11 * V_12 , int type , int V_264 ,
T_3 V_256 )
{
switch ( type ) {
case V_70 :
case V_71 :
case V_34 :
case V_35 :
case V_9 :
case V_10 :
return F_90 ( V_12 , type , V_264 , V_256 ) ;
default:
F_10 ( L_149
L_150 , type ) ;
return V_261 ;
}
}
static void F_56 (
struct V_13 * V_14 ,
struct V_24 * V_267 ,
struct V_1 * V_2 ,
int V_268 ,
int V_269 )
{
const struct V_149 * V_150 = V_267 -> V_42 -> V_47 ;
char V_175 [ V_176 ] ;
int V_8 = 0 , V_167 = 0 ;
memset ( V_175 , 0 , V_176 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
if ( V_14 -> V_110 ) {
V_8 = V_14 -> V_110 -> V_8 ;
V_167 = V_14 -> V_110 -> V_167 ;
V_14 -> V_110 -> V_8 = 0 ;
V_14 -> V_110 -> V_167 = 0 ;
V_14 -> V_110 -> V_7 = 0 ;
V_14 -> V_110 = NULL ;
}
if ( ! V_269 )
goto V_43;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_92 ( & V_2 -> V_126 ) ;
if ( ! F_8 ( & V_14 -> V_32 . V_37 ) &&
( ( V_8 == V_9 ) ||
( V_8 == V_10 ) ) ) {
V_14 -> V_110 =
F_93 ( V_14 -> V_32 . V_37 . V_147 ,
struct V_1 , V_126 ) ;
V_14 -> V_110 -> V_8 = V_8 ;
V_14 -> V_110 -> V_167 = V_167 ;
V_14 -> V_110 -> V_7 = 1 ;
}
F_9 ( & V_14 -> V_32 . V_36 ) ;
V_43:
if ( ! V_14 -> V_110 ) {
F_12 ( L_151
L_148 ,
V_150 -> V_48 () , ( V_268 ) ? L_152 :
L_153 , F_20 ( V_8 ) ,
( V_2 -> V_138 ) ? 1 : 0 ) ;
}
F_12 ( L_154 ,
V_150 -> V_48 () , V_267 -> V_52 ,
V_175 ) ;
V_2 -> V_7 = V_2 -> V_8 = V_2 -> V_167 = 0 ;
}
static T_2
F_94 ( struct V_11 * V_12 , int type , int V_264 ,
T_3 V_256 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_1 * V_2 , * V_258 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
T_2 V_54 = 0 ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_113 ) ;
return V_226 ;
}
V_2 = F_5 ( V_14 , V_18 -> V_24 , V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_137
L_155 ) ;
return V_226 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ! V_7 ) {
F_9 ( & V_14 -> V_44 ) ;
goto V_265;
}
if ( ! F_2 ( V_7 , V_2 ) ) {
F_9 ( & V_14 -> V_44 ) ;
goto V_265;
}
if ( V_256 != V_2 -> V_111 ) {
F_10 ( L_156
L_140
L_121 , V_256 , V_2 -> V_111 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_265;
}
if ( ( V_7 -> V_8 != type ) ||
( V_7 -> V_167 != V_264 ) ) {
struct V_24 * V_197 = V_7 -> V_112 ;
F_10 ( L_157
L_158
L_159
L_144 ,
V_12 -> V_262 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_197 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_265;
}
F_56 ( V_14 , V_18 -> V_24 ,
V_2 , 1 , 0 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( ( type != V_34 ) &&
( type != V_35 ) &&
( type != V_9 ) &&
( type != V_10 ) ) {
goto V_270;
}
F_7 ( & V_31 -> V_36 ) ;
F_34 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_258 == V_2 )
continue;
F_89 ( V_258 -> V_112 ,
V_258 -> V_134 ,
0x2A , V_263 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
V_270:
if ( V_31 -> V_180 )
F_85 ( V_12 -> V_15 , true ) ;
V_265:
F_6 ( V_2 ) ;
return V_54 ;
}
static T_2
F_95 ( struct V_11 * V_12 , T_3 V_256 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_24 * V_112 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_152 , * V_271 , * V_7 ;
T_3 V_134 = 0 ;
int V_272 = 0 ;
V_271 = F_5 ( V_12 -> V_15 ,
V_18 -> V_24 , V_18 ) ;
if ( ! V_271 ) {
F_10 ( L_137
L_160 ) ;
return V_226 ;
}
if ( V_256 != V_271 -> V_111 ) {
F_10 ( L_118
L_119
L_120
L_121 , V_256 , V_271 -> V_111 ) ;
F_6 ( V_271 ) ;
return V_25 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 ) {
struct V_24 * V_197 = V_7 -> V_112 ;
F_56 ( V_14 , V_197 ,
V_7 , 0 , 0 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_134 = V_2 -> V_134 ;
F_57 ( V_14 , V_2 , NULL ,
V_272 ) ;
if ( ! V_272 )
F_89 ( V_112 , V_134 ,
0x2A , V_273 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_12 ( L_161 ,
V_12 -> V_262 -> V_48 () ) ;
F_85 ( V_12 -> V_15 , false ) ;
F_23 ( V_14 ) ;
return 0 ;
}
static void F_96 (
struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_193 * V_194 ,
int type ,
int V_264 ,
enum V_274 V_274 )
{
struct V_24 * V_59 = V_2 -> V_112 ;
const struct V_149 * V_150 = V_59 -> V_42 -> V_47 ;
char V_175 [ V_176 ] ;
memset ( V_175 , 0 , V_176 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
if ( V_14 -> V_110 )
F_56 ( V_14 , V_59 ,
V_14 -> V_110 , 0 , 0 ) ;
V_14 -> V_110 = V_2 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = type ;
V_2 -> V_167 = V_264 ;
F_12 ( L_162
L_148 ,
V_150 -> V_48 () , ( V_274 == V_275 ) ? L_163 : L_30 ,
F_20 ( type ) ,
( V_2 -> V_138 ) ? 1 : 0 ) ;
F_12 ( L_164 ,
V_150 -> V_48 () , ( V_274 == V_275 ) ? L_163 : L_30 ,
V_59 -> V_52 , V_175 ) ;
if ( V_194 )
F_42 ( & V_2 -> V_127 ,
V_194 ) ;
}
static void F_97 (
struct V_193 * V_194 ,
struct V_1 * V_276 )
{
struct V_1 * V_2 , * V_152 ;
F_32 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_43 ( & V_2 -> V_127 ) ;
if ( V_276 == V_2 )
continue;
if ( V_2 -> V_7 ) {
F_70 ( L_165 ) ;
continue;
}
V_2 -> V_132 = NULL ;
V_2 -> V_112 = NULL ;
F_28 ( V_124 , V_2 ) ;
}
}
static T_2
F_98 ( struct V_11 * V_12 , int type , int V_264 , T_3 V_256 ,
T_3 V_121 , enum V_274 V_274 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_24 * V_112 ;
struct V_16 * V_18 = V_12 -> V_18 ;
F_67 ( V_194 ) ;
struct V_1 * V_2 , * V_152 , * V_271 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
T_3 V_134 = 0 ;
int V_62 = 0 , V_272 = 0 ;
bool V_277 = V_121 != 0 ;
int V_278 = 0 , V_279 = 0 ;
if ( ! V_18 )
return V_226 ;
V_271 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_271 ) {
F_10 ( L_137
L_166 ,
( V_274 == V_275 ) ? L_163 : L_30 ) ;
return V_25 ;
}
if ( V_271 -> V_111 != V_256 ) {
F_6 ( V_271 ) ;
return V_25 ;
}
if ( V_264 != V_266 ) {
F_10 ( L_141 , V_264 ) ;
F_6 ( V_271 ) ;
return V_229 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 &&
( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ) )
V_62 = 1 ;
if ( ! V_62 && ! V_121 ) {
F_9 ( & V_14 -> V_44 ) ;
F_6 ( V_271 ) ;
return V_229 ;
}
if ( ! V_7 || ( V_7 -> V_111 != V_121 ) ) {
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_62 ) {
if ( V_2 -> V_111 != V_121 )
continue;
V_277 = false ;
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_134 = V_2 -> V_134 ;
F_57 ( V_14 , V_2 ,
( V_274 == V_275 ) ? & V_194 :
NULL , V_272 ) ;
} else {
if ( ( V_121 ) &&
( V_2 -> V_111 != V_121 ) )
continue;
V_277 = false ;
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
V_112 = V_2 -> V_112 ;
V_134 = V_2 -> V_134 ;
F_57 ( V_14 , V_2 ,
( V_274 == V_275 ) ? & V_194 :
NULL , 0 ) ;
}
if ( ! V_272 )
F_89 ( V_112 ,
V_134 , 0x2A ,
V_280 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
if ( V_277 ) {
F_9 ( & V_14 -> V_44 ) ;
F_6 ( V_271 ) ;
return V_25 ;
}
if ( V_7 && V_62 && ! ( V_121 ) ) {
F_96 ( V_14 , V_271 ,
( V_274 == V_275 ) ? & V_194 : NULL ,
type , V_264 , V_274 ) ;
if ( V_274 == V_275 )
F_97 (
& V_194 , V_271 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
if ( V_31 -> V_180 )
F_85 ( V_12 -> V_15 , true ) ;
F_6 ( V_271 ) ;
F_23 ( V_12 -> V_15 ) ;
return 0 ;
}
V_278 = V_7 -> V_8 ;
V_279 = V_7 -> V_167 ;
if ( V_271 != V_7 )
F_56 ( V_14 ,
V_7 -> V_112 ,
V_14 -> V_110 , 0 , 0 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
if ( V_2 -> V_111 != V_121 )
continue;
V_112 = V_2 -> V_112 ;
V_134 = V_2 -> V_134 ;
F_57 ( V_14 , V_2 ,
( V_274 == V_275 ) ? & V_194 : NULL ,
V_272 ) ;
F_89 ( V_112 , V_134 , 0x2A ,
V_280 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_96 ( V_14 , V_271 ,
( V_274 == V_275 ) ? & V_194 : NULL ,
type , V_264 , V_274 ) ;
if ( ( V_278 != type ) || ( V_279 != V_264 ) ) {
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
F_89 ( V_2 -> V_112 ,
V_2 -> V_134 , 0x2A ,
V_263 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
if ( V_274 == V_275 ) {
F_99 ( V_14 , NULL , & V_194 , V_12 ) ;
F_97 ( & V_194 ,
V_271 ) ;
}
if ( V_31 -> V_180 )
F_85 ( V_12 -> V_15 , true ) ;
F_6 ( V_271 ) ;
F_23 ( V_12 -> V_15 ) ;
return 0 ;
}
static T_2
F_100 ( struct V_11 * V_12 , int type , int V_264 ,
T_3 V_256 , T_3 V_121 , enum V_274 V_274 )
{
switch ( type ) {
case V_70 :
case V_71 :
case V_34 :
case V_35 :
case V_9 :
case V_10 :
return F_98 ( V_12 , type , V_264 , V_256 ,
V_121 , V_274 ) ;
default:
F_10 ( L_167
L_168 , ( V_274 == V_275 ) ? L_163 : L_30 , type ) ;
return V_261 ;
}
}
static T_2
F_101 ( struct V_11 * V_12 , T_3 V_256 ,
T_3 V_121 , int V_123 , int V_269 )
{
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_66 * V_210 = NULL ;
struct V_49 * V_49 = V_12 -> V_49 , * V_231 ;
struct V_24 * V_197 , * V_112 , * V_209 = NULL ;
struct V_39 * V_42 , * V_281 = NULL ;
const struct V_149 * V_282 = NULL , * V_283 ;
struct V_1 * V_2 , * V_7 , * V_211 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char * V_3 ;
const unsigned char * V_284 ;
char * V_222 = NULL , V_175 [ V_176 ] ;
T_1 V_224 , V_285 ;
int V_286 = 0 , type , V_264 , V_287 ;
T_2 V_54 ;
unsigned short V_288 ;
unsigned char V_220 ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_113 ) ;
return V_226 ;
}
memset ( V_175 , 0 , V_176 ) ;
V_42 = V_18 -> V_42 ;
V_283 = V_42 -> V_47 ;
V_2 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_169
L_170 ) ;
return V_226 ;
}
if ( V_256 != V_2 -> V_111 ) {
F_70 ( L_171
L_172
L_173 , V_256 , V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_265;
}
if ( ! V_121 ) {
F_70 ( L_174
L_175 ) ;
V_54 = V_229 ;
goto V_265;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_226 ;
goto V_265;
}
V_288 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_288 |= V_3 [ 19 ] & 0xff ;
V_224 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_224 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_224 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_224 |= V_3 [ 23 ] & 0xff ;
F_77 ( V_12 ) ;
V_3 = NULL ;
if ( ( V_224 + 24 ) != V_12 -> V_228 ) {
F_10 ( L_176
L_65 , V_224 ,
V_12 -> V_228 ) ;
V_54 = V_229 ;
goto V_265;
}
F_7 ( & V_14 -> V_154 ) ;
F_34 (tmp_lun, &dev->dev_sep_list, lun_dev_link) {
if ( V_231 -> V_137 != V_288 )
continue;
V_281 = V_231 -> V_232 ;
V_282 = V_281 -> V_47 ;
if ( ! V_282 )
continue;
F_53 ( & V_281 -> V_200 ) ;
F_9 ( & V_14 -> V_154 ) ;
if ( F_60 ( V_281 ) ) {
F_10 ( L_177
L_178 ) ;
F_54 ( & V_281 -> V_200 ) ;
V_54 = V_226 ;
goto V_265;
}
F_7 ( & V_14 -> V_154 ) ;
break;
}
F_9 ( & V_14 -> V_154 ) ;
if ( ! V_281 || ! V_282 ) {
F_10 ( L_179
L_180
L_181 , V_288 ) ;
V_54 = V_229 ;
goto V_265;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_226 ;
goto V_265;
}
V_220 = ( V_3 [ 24 ] & 0x0f ) ;
F_12 ( L_182
L_150 , V_220 ) ;
if ( V_220 != V_281 -> V_233 ) {
F_10 ( L_171
L_183
L_184 , V_220 ,
V_281 -> V_233 ,
V_282 -> V_48 () ) ;
V_54 = V_229 ;
goto V_43;
}
V_284 = F_72 ( V_281 ,
( const char * ) & V_3 [ 24 ] , & V_285 , & V_222 ) ;
if ( ! V_284 ) {
F_10 ( L_179
L_185 ) ;
V_54 = V_229 ;
goto V_43;
}
F_77 ( V_12 ) ;
V_3 = NULL ;
F_12 ( L_186
L_187 , V_282 -> V_48 () , ( V_222 != NULL ) ?
L_188 : L_189 , V_284 , ( V_222 != NULL ) ?
V_222 : L_30 ) ;
V_112 = V_2 -> V_112 ;
V_287 = ( ! strcmp ( V_284 ,
V_112 -> V_52 ) ) ? 1 : 0 ;
if ( ! V_287 )
goto V_289;
if ( ! V_222 || ! V_2 -> V_5 ) {
F_10 ( L_190
L_191 , V_284 ,
V_112 -> V_52 ) ;
V_54 = V_229 ;
goto V_43;
}
if ( ! strcmp ( V_222 , V_2 -> V_6 ) ) {
F_10 ( L_192
L_193 ,
V_284 , V_222 , V_112 -> V_52 ,
V_2 -> V_6 ) ;
V_54 = V_229 ;
goto V_43;
}
V_289:
F_73 ( & V_281 -> V_234 ) ;
V_209 = F_74 ( V_281 ,
V_284 ) ;
if ( V_209 )
F_53 ( & V_209 -> V_203 ) ;
F_75 ( & V_281 -> V_234 ) ;
if ( ! V_209 ) {
F_10 ( L_194
L_195 , V_282 -> V_48 () ,
V_284 ) ;
V_54 = V_229 ;
goto V_43;
}
if ( F_64 ( V_209 ) ) {
F_10 ( L_196
L_197 ) ;
F_54 ( & V_209 -> V_203 ) ;
V_209 = NULL ;
V_54 = V_229 ;
goto V_43;
}
F_12 ( L_198
L_199 , V_282 -> V_48 () ,
V_209 -> V_52 ) ;
V_210 = F_76 ( V_209 , V_288 ) ;
if ( ! V_210 ) {
F_10 ( L_200
L_181 , V_282 -> V_48 () , V_288 ) ;
V_54 = V_229 ;
goto V_43;
}
if ( F_37 ( V_210 ) ) {
F_10 ( L_201 ) ;
F_39 ( & V_210 -> V_133 , V_158 ) ;
V_210 = NULL ;
V_54 = V_226 ;
goto V_43;
}
F_12 ( L_202
L_203 ,
V_282 -> V_48 () , V_209 -> V_52 ,
V_210 -> V_119 ) ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ! V_7 ) {
F_70 ( L_204
L_205 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_261 ;
goto V_43;
}
if ( ! F_2 ( V_7 , V_2 ) ) {
F_70 ( L_206
L_207 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_43;
}
if ( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ) {
F_70 ( L_208
L_209 ,
F_20 ( V_7 -> V_8 ) ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_43;
}
V_197 = V_7 -> V_112 ;
type = V_7 -> V_8 ;
V_264 = V_7 -> V_8 ;
V_211 = F_52 ( V_14 , V_209 ,
V_222 ) ;
if ( ! V_211 ) {
struct V_49 * V_148 = F_35 ( V_210 -> V_49 ,
F_40 ( & V_210 -> V_133 . V_159 ) != 0 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( F_51 ( V_12 -> V_15 , V_209 ,
V_148 , V_210 , V_210 -> V_119 ,
V_222 , V_121 , 0 , V_123 , 2 , 1 ) ) {
V_54 = V_229 ;
goto V_43;
}
F_7 ( & V_14 -> V_44 ) ;
V_211 = F_52 ( V_14 , V_209 ,
V_222 ) ;
V_286 = 1 ;
}
F_56 ( V_14 , V_197 ,
V_14 -> V_110 , 0 , 0 ) ;
V_14 -> V_110 = V_211 ;
V_211 -> V_7 = 1 ;
V_211 -> V_8 = type ;
V_2 -> V_167 = V_264 ;
F_1 ( V_2 , V_175 , V_176 ) ;
if ( ! V_286 )
V_211 -> V_186 = V_31 -> V_116 ++ ;
F_9 ( & V_14 -> V_44 ) ;
F_12 ( L_210
L_211
L_212 , V_282 -> V_48 () ,
F_20 ( type ) , V_288 ,
V_211 -> V_186 ) ;
F_12 ( L_213
L_214 ,
V_283 -> V_48 () , V_112 -> V_52 ,
V_175 , V_282 -> V_48 () ,
V_209 -> V_52 , ( V_222 != NULL ) ?
V_222 : L_30 ) ;
F_41 ( V_210 ) ;
F_65 ( V_209 ) ;
F_62 ( V_281 ) ;
if ( V_269 ) {
F_7 ( & V_31 -> V_36 ) ;
F_57 ( V_14 , V_2 , NULL , 1 ) ;
F_9 ( & V_31 -> V_36 ) ;
} else
F_6 ( V_2 ) ;
F_85 ( V_12 -> V_15 , V_123 ) ;
F_77 ( V_12 ) ;
F_6 ( V_211 ) ;
return 0 ;
V_43:
if ( V_3 )
F_77 ( V_12 ) ;
if ( V_210 )
F_41 ( V_210 ) ;
if ( V_209 )
F_65 ( V_209 ) ;
F_62 ( V_281 ) ;
V_265:
F_6 ( V_2 ) ;
return V_54 ;
}
static unsigned long long F_102 ( unsigned char * V_58 )
{
unsigned int V_290 , V_291 ;
V_290 = ( V_58 [ 0 ] << 24 ) | ( V_58 [ 1 ] << 16 ) | ( V_58 [ 2 ] << 8 ) | V_58 [ 3 ] ;
V_291 = ( V_58 [ 4 ] << 24 ) | ( V_58 [ 5 ] << 16 ) | ( V_58 [ 6 ] << 8 ) | V_58 [ 7 ] ;
return ( ( unsigned long long ) V_291 ) | ( unsigned long long ) V_290 << 32 ;
}
T_2
F_103 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned char * V_58 = & V_12 -> V_19 [ 0 ] ;
unsigned char * V_3 ;
T_3 V_256 , V_121 ;
int V_292 , V_264 , type , V_123 ;
int V_257 = 0 , V_122 = 0 , V_269 = 0 ;
T_2 V_54 ;
if ( V_12 -> V_15 -> V_26 & V_46 ) {
F_10 ( L_215
L_216
L_217 ) ;
return V_25 ;
}
if ( ! V_12 -> V_18 )
return V_226 ;
if ( V_12 -> V_228 < 24 ) {
F_70 ( L_62
L_63 , V_12 -> V_228 ) ;
return V_229 ;
}
V_292 = ( V_58 [ 1 ] & 0x1f ) ;
V_264 = ( V_58 [ 2 ] & 0xf0 ) ;
type = ( V_58 [ 2 ] & 0x0f ) ;
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_226 ;
V_256 = F_102 ( & V_3 [ 0 ] ) ;
V_121 = F_102 ( & V_3 [ 8 ] ) ;
if ( V_292 != V_85 ) {
V_257 = ( V_3 [ 20 ] & 0x08 ) ;
V_122 = ( V_3 [ 20 ] & 0x04 ) ;
V_123 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_123 = ( V_3 [ 17 ] & 0x01 ) ;
V_269 = ( V_3 [ 17 ] & 0x02 ) ;
}
if ( V_14 -> V_190 . V_293 )
V_123 = 1 ;
F_77 ( V_12 ) ;
V_3 = NULL ;
if ( V_257 && ( ( V_58 [ 1 ] & 0x1f ) != V_83 ) )
return V_229 ;
if ( ! V_257 && ( ( V_58 [ 1 ] & 0x1f ) != V_85 ) &&
( V_12 -> V_228 != 24 ) ) {
F_70 ( L_218
L_219 , V_12 -> V_228 ) ;
return V_229 ;
}
switch ( V_292 ) {
case V_83 :
V_54 = F_88 ( V_12 ,
V_256 , V_121 , V_123 , V_122 , V_257 , REGISTER ) ;
break;
case V_86 :
V_54 = F_91 ( V_12 , type , V_264 , V_256 ) ;
break;
case V_87 :
V_54 = F_94 ( V_12 , type , V_264 , V_256 ) ;
break;
case V_80 :
V_54 = F_95 ( V_12 , V_256 ) ;
break;
case V_81 :
V_54 = F_100 ( V_12 , type , V_264 ,
V_256 , V_121 , V_294 ) ;
break;
case V_82 :
V_54 = F_100 ( V_12 , type , V_264 ,
V_256 , V_121 , V_275 ) ;
break;
case V_84 :
V_54 = F_88 ( V_12 ,
0 , V_121 , V_123 , V_122 , V_257 , V_183 ) ;
break;
case V_85 :
V_54 = F_101 ( V_12 , V_256 ,
V_121 , V_123 , V_269 ) ;
break;
default:
F_10 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return V_261 ;
}
if ( ! V_54 )
F_13 ( V_12 , V_53 ) ;
return V_54 ;
}
static T_2
F_104 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_295 = 0 , V_296 = 8 ;
if ( V_12 -> V_228 < 8 ) {
F_10 ( L_220
L_221 , V_12 -> V_228 ) ;
return V_261 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_34 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_295 + 8 ) > ( V_12 -> V_228 - 8 ) )
break;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_295 += 8 ;
}
F_9 ( & V_14 -> V_32 . V_36 ) ;
V_3 [ 4 ] = ( ( V_295 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_295 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_295 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_295 & 0xff ) ;
F_77 ( V_12 ) ;
return 0 ;
}
static T_2
F_105 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_3 V_111 ;
T_1 V_295 = 16 ;
if ( V_12 -> V_228 < 8 ) {
F_10 ( L_222
L_221 , V_12 -> V_228 ) ;
return V_261 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_44 ) ;
V_2 = V_14 -> V_110 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_295 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_295 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_295 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_295 & 0xff ) ;
if ( V_12 -> V_228 < 22 )
goto V_297;
if ( ( V_2 -> V_8 == V_9 ) ||
( V_2 -> V_8 == V_10 ) )
V_111 = 0 ;
else
V_111 = V_2 -> V_111 ;
V_3 [ 8 ] = ( ( V_111 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_111 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_111 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_111 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_111 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_111 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_111 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_111 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_167 & 0xf0 ) |
( V_2 -> V_8 & 0x0f ) ;
}
V_297:
F_9 ( & V_14 -> V_44 ) ;
F_77 ( V_12 ) ;
return 0 ;
}
static T_2
F_106 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char * V_3 ;
T_4 V_295 = 8 ;
if ( V_12 -> V_228 < 6 ) {
F_10 ( L_223
L_224 , V_12 -> V_228 ) ;
return V_261 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_295 >> 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_295 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_31 -> V_180 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
F_77 ( V_12 ) ;
return 0 ;
}
static T_2
F_107 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_24 * V_267 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_152 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char * V_3 ;
T_1 V_298 = 0 , V_295 = 0 ;
T_1 V_296 = 8 ;
int V_299 = 0 , V_8 = 0 , V_167 = 0 ;
int V_300 , V_301 ;
bool V_62 = false ;
if ( V_12 -> V_228 < 8 ) {
F_10 ( L_225
L_221 , V_12 -> V_228 ) ;
return V_261 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_110 ) {
struct V_1 * V_260 = V_14 -> V_110 ;
if ( V_260 -> V_8 == V_9 ||
V_260 -> V_8 == V_10 ) {
V_62 = true ;
V_8 = V_260 -> V_8 ;
V_167 = V_260 -> V_167 ;
}
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_267 = V_2 -> V_112 ;
V_42 = V_2 -> V_112 -> V_42 ;
V_298 = 0 ;
F_53 ( & V_2 -> V_131 ) ;
F_9 ( & V_31 -> V_36 ) ;
V_300 = F_108 ( V_267 , V_2 ,
& V_299 ) ;
if ( V_300 < 0 ||
V_300 + V_295 > V_12 -> V_228 ) {
F_70 ( L_226
L_227 , V_12 -> V_228 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_54 ( & V_2 -> V_131 ) ;
break;
}
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_296 += 4 ;
if ( V_2 -> V_138 )
V_3 [ V_296 ] = 0x02 ;
if ( V_2 -> V_7 ) {
V_3 [ V_296 ++ ] |= 0x01 ;
V_3 [ V_296 ++ ] = ( V_2 -> V_167 & 0xf0 ) |
( V_2 -> V_8 & 0x0f ) ;
} else if ( V_62 ) {
V_3 [ V_296 ++ ] |= 0x01 ;
V_3 [ V_296 ++ ] = ( V_167 & 0xf0 ) |
( V_8 & 0x0f ) ;
} else {
V_296 += 2 ;
}
V_296 += 4 ;
if ( ! V_2 -> V_138 ) {
T_4 V_302 = V_2 -> V_136 ;
V_3 [ V_296 ++ ] = ( ( V_302 >> 8 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( V_302 & 0xff ) ;
} else
V_296 += 2 ;
V_3 [ V_296 + 4 ] = V_42 -> V_233 ;
V_301 = F_109 ( V_267 , V_2 ,
& V_299 , & V_3 [ V_296 + 4 ] ) ;
F_7 ( & V_31 -> V_36 ) ;
F_54 ( & V_2 -> V_131 ) ;
if ( V_301 < 0 )
break;
V_3 [ V_296 ++ ] = ( ( V_301 >> 24 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_301 >> 16 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( ( V_301 >> 8 ) & 0xff ) ;
V_3 [ V_296 ++ ] = ( V_301 & 0xff ) ;
V_298 = ( 24 + V_301 ) ;
V_296 += V_301 ;
V_295 += V_298 ;
}
F_9 ( & V_31 -> V_36 ) ;
V_3 [ 4 ] = ( ( V_295 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_295 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_295 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_295 & 0xff ) ;
F_77 ( V_12 ) ;
return 0 ;
}
T_2
F_110 ( struct V_11 * V_12 )
{
T_2 V_54 ;
if ( V_12 -> V_15 -> V_26 & V_46 ) {
F_10 ( L_215
L_216
L_217 ) ;
return V_25 ;
}
switch ( V_12 -> V_19 [ 1 ] & 0x1f ) {
case V_303 :
V_54 = F_104 ( V_12 ) ;
break;
case V_304 :
V_54 = F_105 ( V_12 ) ;
break;
case V_305 :
V_54 = F_106 ( V_12 ) ;
break;
case V_306 :
V_54 = F_107 ( V_12 ) ;
break;
default:
F_10 ( L_228
L_16 , V_12 -> V_19 [ 1 ] & 0x1f ) ;
return V_261 ;
}
if ( ! V_54 )
F_13 ( V_12 , V_53 ) ;
return V_54 ;
}
T_2
F_111 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
T_2 V_54 ;
if ( ! V_12 -> V_18 )
return 0 ;
if ( V_14 -> V_307 -> V_308 & V_309 )
return 0 ;
if ( V_14 -> V_184 -> V_310 & V_311 )
return 0 ;
F_7 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_26 & V_46 )
V_54 = F_3 ( V_12 ) ;
else
V_54 = F_22 ( V_12 ) ;
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
