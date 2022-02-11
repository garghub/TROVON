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
V_2 -> V_132 = V_118 ;
V_2 -> V_133 = V_119 ;
V_2 -> V_134 = V_117 -> V_50 ;
V_2 -> V_135 = V_117 -> V_136 ;
V_2 -> V_111 = V_121 ;
V_2 -> V_137 = V_122 ;
V_2 -> V_138 = V_123 ;
if ( V_120 != NULL ) {
V_2 -> V_114 = F_28 ( V_120 ) ;
snprintf ( V_2 -> V_6 , V_139 , L_33 , V_120 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_29 (
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
struct V_66 * V_140 ;
struct V_24 * V_141 ;
struct V_142 * V_143 ;
struct V_49 * V_144 , * V_145 , * V_146 ;
const struct V_147 * V_148 = V_59 -> V_42 -> V_47 ;
struct V_1 * V_2 , * V_149 , * V_150 , * V_151 ;
int V_54 ;
V_2 = F_24 ( V_14 , V_59 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ,
V_123 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_122 )
return V_2 ;
F_7 ( & V_14 -> V_152 ) ;
F_30 (lun_tmp, next, &dev->dev_sep_list, lun_dev_link) {
if ( ! F_31 ( & V_144 -> V_153 ) )
continue;
F_9 ( & V_14 -> V_152 ) ;
F_7 ( & V_144 -> V_154 ) ;
F_32 (deve_tmp, &lun_tmp->lun_deve_list, lun_link) {
if ( ! V_140 -> V_142 )
continue;
V_143 = F_33 ( V_140 -> V_142 ,
F_34 ( & V_144 -> V_154 ) ) ;
V_141 = V_143 -> V_155 ;
if ( V_59 == V_141 )
continue;
if ( V_148 != V_141 -> V_42 -> V_47 )
continue;
if ( strcmp ( V_59 -> V_52 , V_141 -> V_52 ) )
continue;
F_35 ( & V_140 -> V_156 ) ;
F_9 ( & V_144 -> V_154 ) ;
V_54 = F_36 ( V_140 ) ;
if ( V_54 < 0 ) {
F_10 ( L_34
L_35 ) ;
F_37 ( & V_144 -> V_153 ) ;
F_38 ( & V_140 -> V_156 , V_157 ) ;
goto V_43;
}
V_146 = F_33 ( V_140 -> V_49 ,
F_39 ( & V_140 -> V_156 . V_158 ) != 0 ) ;
V_149 = F_24 ( V_14 ,
V_141 , V_146 , V_140 ,
V_140 -> V_119 , NULL ,
V_121 , V_122 , V_123 ) ;
if ( ! V_149 ) {
F_37 ( & V_144 -> V_153 ) ;
F_40 ( V_140 ) ;
goto V_43;
}
F_41 ( & V_149 -> V_130 ,
& V_2 -> V_129 ) ;
F_7 ( & V_144 -> V_154 ) ;
}
F_9 ( & V_144 -> V_154 ) ;
F_7 ( & V_14 -> V_152 ) ;
F_37 ( & V_144 -> V_153 ) ;
}
F_9 ( & V_14 -> V_152 ) ;
return V_2 ;
V_43:
F_30 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_42 ( & V_150 -> V_130 ) ;
F_40 ( V_150 -> V_132 ) ;
F_43 ( V_124 , V_150 ) ;
}
F_43 ( V_124 , V_2 ) ;
return NULL ;
}
int F_44 (
struct V_30 * V_31 ,
T_3 V_121 ,
unsigned char * V_159 ,
unsigned char * V_120 ,
T_3 V_119 ,
unsigned char * V_160 ,
T_4 V_161 ,
T_3 V_162 ,
int V_163 ,
int V_122 ,
T_5 type )
{
struct V_1 * V_2 ;
if ( ! V_159 || ! V_160 || ! V_121 ) {
F_10 ( L_36 ) ;
return - V_72 ;
}
V_2 = F_25 ( V_124 , V_164 ) ;
if ( ! V_2 ) {
F_10 ( L_32 ) ;
return - V_165 ;
}
F_26 ( & V_2 -> V_126 ) ;
F_26 ( & V_2 -> V_127 ) ;
F_26 ( & V_2 -> V_128 ) ;
F_26 ( & V_2 -> V_129 ) ;
F_26 ( & V_2 -> V_130 ) ;
F_27 ( & V_2 -> V_131 , 0 ) ;
V_2 -> V_112 = NULL ;
V_2 -> V_132 = NULL ;
V_2 -> V_133 = V_119 ;
V_2 -> V_134 = V_162 ;
V_2 -> V_111 = V_121 ;
V_2 -> V_137 = V_122 ;
V_2 -> V_138 = 1 ;
V_2 -> V_166 = 0 ;
V_2 -> V_8 = type ;
if ( V_120 != NULL ) {
V_2 -> V_114 = F_28 ( V_120 ) ;
snprintf ( V_2 -> V_6 , V_139 , L_33 , V_120 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_167 , V_168 , L_33 , V_159 ) ;
snprintf ( V_2 -> V_169 , V_170 , L_33 , V_160 ) ;
V_2 -> V_171 = V_161 ;
V_2 -> V_7 = V_163 ;
F_41 ( & V_2 -> V_128 , & V_31 -> V_172 ) ;
F_12 ( L_37
L_38 , ( V_163 ) ? L_39 : L_30 ) ;
return 0 ;
}
static void F_45 (
struct V_13 * V_14 ,
struct V_39 * V_40 ,
struct V_24 * V_173 ,
struct V_1 * V_2 )
{
char V_174 [ V_175 ] ;
memset ( V_174 , 0 , V_175 ) ;
F_1 ( V_2 , V_174 , V_175 ) ;
F_7 ( & V_14 -> V_44 ) ;
V_14 -> V_110 = V_2 ;
F_9 ( & V_14 -> V_44 ) ;
F_12 ( L_40
L_41 ,
V_40 -> V_47 -> V_48 () ,
F_20 ( V_2 -> V_8 ) ,
( V_2 -> V_137 ) ? 1 : 0 ) ;
F_12 ( L_42 ,
V_40 -> V_47 -> V_48 () , V_173 -> V_52 ,
V_174 ) ;
}
static int F_46 (
struct V_13 * V_14 ,
struct V_39 * V_40 ,
struct V_49 * V_117 ,
T_3 V_162 ,
struct V_24 * V_59 ,
T_3 V_119 )
{
struct V_1 * V_2 , * V_150 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char V_159 [ V_168 ] ;
unsigned char V_160 [ V_170 ] ;
T_4 V_161 ;
memset ( V_159 , 0 , V_168 ) ;
memset ( V_160 , 0 , V_170 ) ;
snprintf ( V_159 , V_168 , L_33 , V_59 -> V_52 ) ;
snprintf ( V_160 , V_170 , L_33 ,
V_40 -> V_47 -> V_176 ( V_40 ) ) ;
V_161 = V_40 -> V_47 -> V_177 ( V_40 ) ;
F_7 ( & V_31 -> V_178 ) ;
F_30 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_167 , V_159 ) &&
( V_2 -> V_133 == V_119 ) &&
! ( strcmp ( V_2 -> V_169 , V_160 ) ) &&
( V_2 -> V_171 == V_161 ) &&
( V_2 -> V_134 == V_162 ) ) {
V_2 -> V_112 = V_59 ;
V_2 -> V_135 = V_117 -> V_136 ;
F_42 ( & V_2 -> V_128 ) ;
F_9 ( & V_31 -> V_178 ) ;
F_47 ( V_14 , V_59 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_7 )
F_45 ( V_14 , V_40 ,
V_59 , V_2 ) ;
F_7 ( & V_31 -> V_178 ) ;
V_31 -> V_179 = 1 ;
}
}
F_9 ( & V_31 -> V_178 ) ;
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
const struct V_147 * V_148 ,
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_1 * V_2 ,
enum V_180 V_180 )
{
struct V_39 * V_42 = V_59 -> V_42 ;
char V_174 [ V_175 ] ;
memset ( & V_174 [ 0 ] , 0 , V_175 ) ;
F_1 ( V_2 , V_174 , V_175 ) ;
F_12 ( L_43
L_44 , V_148 -> V_48 () , ( V_180 == V_181 ) ?
L_45 : ( V_180 == V_182 ) ?
L_46 : L_30 , V_59 -> V_52 ,
V_174 ) ;
F_12 ( L_47 ,
V_148 -> V_48 () , V_148 -> V_176 ( V_42 ) ,
V_148 -> V_177 ( V_42 ) ) ;
F_12 ( L_48
L_49 , V_148 -> V_48 () ,
( V_2 -> V_137 ) ? L_50 : L_51 ,
V_14 -> V_183 -> V_184 ) ;
F_12 ( L_52
L_53 , V_148 -> V_48 () ,
V_2 -> V_111 , V_2 -> V_185 ,
V_2 -> V_138 ) ;
}
static void F_47 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_1 * V_2 ,
enum V_180 V_180 ,
int V_186 )
{
const struct V_147 * V_148 = V_59 -> V_42 -> V_47 ;
struct V_1 * V_150 , * V_151 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_66 * V_118 ;
V_2 -> V_185 = ( V_186 ) ?
V_14 -> V_32 . V_116 ++ :
F_23 ( V_14 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_41 ( & V_2 -> V_126 , & V_31 -> V_37 ) ;
F_49 ( V_148 , V_14 , V_59 , V_2 , V_180 ) ;
F_9 ( & V_31 -> V_36 ) ;
F_16 () ;
V_118 = V_2 -> V_132 ;
if ( V_118 )
F_50 ( V_68 , & V_118 -> V_69 ) ;
F_19 () ;
if ( ! V_2 -> V_137 || V_186 )
return;
F_30 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
struct V_24 * V_141 = V_150 -> V_112 ;
F_42 ( & V_150 -> V_130 ) ;
V_150 -> V_185 = F_23 ( V_14 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_41 ( & V_150 -> V_126 ,
& V_31 -> V_37 ) ;
F_49 ( V_148 , V_14 , V_141 , V_150 ,
V_180 ) ;
F_9 ( & V_31 -> V_36 ) ;
F_16 () ;
V_118 = V_150 -> V_132 ;
if ( V_118 )
F_50 ( V_68 , & V_118 -> V_69 ) ;
F_19 () ;
F_40 ( V_150 -> V_132 ) ;
}
}
static int F_51 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
struct V_49 * V_117 ,
struct V_66 * V_118 ,
T_3 V_119 ,
unsigned char * V_120 ,
T_3 V_121 ,
int V_122 ,
int V_123 ,
enum V_180 V_180 ,
int V_186 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_14 , V_59 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ,
V_123 ) ;
if ( ! V_2 )
return - V_187 ;
F_47 ( V_14 , V_59 , V_2 ,
V_180 , V_186 ) ;
return 0 ;
}
static struct V_1 * F_52 (
struct V_13 * V_14 ,
struct V_24 * V_59 ,
unsigned char * V_120 )
{
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_150 ;
struct V_39 * V_40 ;
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_112 != V_59 )
continue;
V_40 = V_2 -> V_112 -> V_42 ;
if ( ! V_2 -> V_5 ) {
if ( V_40 -> V_47 -> V_188 != NULL ) {
if ( V_14 -> V_189 . V_190 )
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
unsigned char V_3 [ V_139 ] , * V_191 = NULL ;
if ( V_40 -> V_47 -> V_188 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_139 ) ;
V_40 -> V_47 -> V_188 ( V_17 , & V_3 [ 0 ] ,
V_139 ) ;
V_191 = & V_3 [ 0 ] ;
}
return F_52 ( V_14 , V_59 , V_191 ) ;
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
} else if ( V_2 -> V_137 &&
( ! strcmp ( V_7 -> V_112 -> V_52 ,
V_2 -> V_112 -> V_52 ) ) &&
( V_7 -> V_111 == V_2 -> V_111 ) ) {
F_10 ( L_54
L_55
L_56
L_57 , V_2 -> V_111 ) ;
V_54 = - V_187 ;
}
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
static void F_57 (
struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_192 * V_193 ,
int V_194 )
__releases( &pr_tmpl->registration_lock
void F_58 (
struct V_13 * V_14 ,
struct V_24 * V_59 )
{
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_150 , * V_7 ;
bool V_195 = false ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ( V_7 != NULL ) &&
( V_7 -> V_112 == V_59 ) ) {
F_56 ( V_14 , V_59 , V_7 , 0 , 1 ) ;
V_195 = true ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
if ( V_7 && V_195 )
F_57 ( V_14 , V_7 , NULL , 0 ) ;
F_30 (pr_reg, pr_reg_tmp,
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
struct V_1 * V_2 , * V_150 , * V_7 ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 != NULL ) {
struct V_24 * V_196 = V_7 -> V_112 ;
F_56 ( V_14 , V_196 ,
V_7 , 0 , 0 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_57 ( V_14 , V_2 , NULL , 0 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_178 ) ;
F_30 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_42 ( & V_2 -> V_128 ) ;
F_43 ( V_124 , V_2 ) ;
}
F_9 ( & V_31 -> V_178 ) ;
}
static int F_60 ( struct V_39 * V_40 )
{
return F_61 ( & V_40 -> V_197 . V_198 ) ;
}
static void F_62 ( struct V_39 * V_40 )
{
F_63 ( & V_40 -> V_197 . V_198 ) ;
F_54 ( & V_40 -> V_199 ) ;
}
static int F_64 ( struct V_24 * V_59 )
{
if ( V_59 -> V_200 )
return 0 ;
return F_61 ( & V_59 -> V_201 . V_198 ) ;
}
static void F_65 ( struct V_24 * V_59 )
{
if ( ! V_59 -> V_200 )
F_63 ( & V_59 -> V_201 . V_198 ) ;
F_54 ( & V_59 -> V_202 ) ;
}
static int F_36 ( struct V_66 * V_67 )
{
struct V_142 * V_203 ;
struct V_24 * V_59 ;
struct V_39 * V_40 ;
V_203 = F_33 ( V_67 -> V_142 ,
F_39 ( & V_67 -> V_156 . V_158 ) != 0 ) ;
if ( ! V_203 )
return 0 ;
V_59 = V_203 -> V_155 ;
V_40 = V_59 -> V_42 ;
return F_61 ( & V_203 -> V_204 . V_198 ) ;
}
static void F_40 ( struct V_66 * V_67 )
{
struct V_142 * V_203 ;
struct V_24 * V_59 ;
struct V_39 * V_40 ;
V_203 = F_33 ( V_67 -> V_142 ,
F_39 ( & V_67 -> V_156 . V_158 ) != 0 ) ;
if ( ! V_203 ) {
F_38 ( & V_67 -> V_156 , V_157 ) ;
return;
}
V_59 = V_203 -> V_155 ;
V_40 = V_59 -> V_42 ;
F_63 ( & V_203 -> V_204 . V_198 ) ;
F_38 ( & V_67 -> V_156 , V_157 ) ;
}
static T_2
F_66 (
struct V_11 * V_12 ,
struct V_39 * V_40 ,
unsigned char * V_205 ,
T_3 V_121 ,
int V_122 ,
int V_123 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_39 * V_206 = NULL , * V_207 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_24 * V_208 = NULL ;
struct V_66 * V_209 = NULL ;
struct V_1 * V_210 , * V_211 , * V_212 ;
struct V_1 * V_150 , * V_151 ;
F_67 ( V_213 ) ;
struct V_214 * V_215 , * V_216 , * V_217 ;
unsigned char * V_3 , * V_218 , V_219 ;
const unsigned char * V_220 = NULL ;
char * V_221 = NULL , V_174 [ V_175 ] ;
T_2 V_54 ;
T_1 V_222 , V_223 = 0 ;
T_1 V_224 = 0 ;
V_215 = F_68 ( sizeof( struct V_214 ) , V_164 ) ;
if ( ! V_215 ) {
F_10 ( L_58 ) ;
return V_225 ;
}
F_26 ( & V_215 -> V_226 ) ;
V_215 -> V_206 = V_40 ;
V_215 -> V_208 = V_18 -> V_24 ;
V_211 = F_29 ( V_12 -> V_15 ,
V_18 -> V_24 , V_12 -> V_49 ,
NULL , V_12 -> V_51 , V_205 ,
V_121 , V_122 , V_123 ) ;
if ( ! V_211 ) {
F_69 ( V_215 ) ;
return V_225 ;
}
V_215 -> V_210 = V_211 ;
V_215 -> V_209 = NULL ;
F_41 ( & V_215 -> V_226 , & V_213 ) ;
if ( V_12 -> V_227 < 28 ) {
F_70 ( L_59
L_60 , V_12 -> V_227 ) ;
V_54 = V_228 ;
goto V_43;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_225 ;
goto V_43;
}
V_222 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_222 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_222 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_222 |= V_3 [ 27 ] & 0xff ;
if ( ( V_222 + 28 ) != V_12 -> V_227 ) {
F_10 ( L_61
L_62 , V_222 ,
V_12 -> V_227 ) ;
V_54 = V_228 ;
goto V_229;
}
V_218 = & V_3 [ 28 ] ;
while ( V_222 > 0 ) {
struct V_49 * V_146 , * V_230 ;
V_219 = ( V_218 [ 0 ] & 0x0f ) ;
V_206 = NULL ;
F_7 ( & V_14 -> V_152 ) ;
F_32 (tmp_lun, &dev->dev_sep_list, lun_dev_link) {
V_207 = V_230 -> V_231 ;
if ( V_207 -> V_232 != V_219 )
continue;
V_224 = V_230 -> V_136 ;
V_220 = F_72 ( V_207 ,
( const char * ) V_218 , & V_223 , & V_221 ) ;
if ( ! V_220 )
continue;
F_53 ( & V_207 -> V_199 ) ;
F_9 ( & V_14 -> V_152 ) ;
if ( F_60 ( V_207 ) ) {
F_10 ( L_63
L_64 ) ;
F_54 ( & V_207 -> V_199 ) ;
V_54 = V_225 ;
goto V_229;
}
F_73 ( & V_207 -> V_233 ) ;
V_208 = F_74 (
V_207 , V_220 ) ;
if ( V_208 )
F_53 ( & V_208 -> V_202 ) ;
F_75 ( & V_207 -> V_233 ) ;
if ( ! V_208 ) {
F_62 ( V_207 ) ;
F_7 ( & V_14 -> V_152 ) ;
continue;
}
if ( F_64 ( V_208 ) ) {
F_10 ( L_65
L_66 ) ;
F_54 ( & V_208 -> V_202 ) ;
F_62 ( V_207 ) ;
V_54 = V_225 ;
goto V_229;
}
V_206 = V_207 ;
F_12 ( L_67
L_68 ,
V_206 -> V_47 -> V_48 () ,
V_208 -> V_52 , V_224 ) ;
F_7 ( & V_14 -> V_152 ) ;
break;
}
F_9 ( & V_14 -> V_152 ) ;
if ( ! V_206 ) {
F_10 ( L_69
L_70 ) ;
V_54 = V_228 ;
goto V_229;
}
F_12 ( L_71
L_72 ,
V_206 -> V_47 -> V_48 () , V_12 -> V_227 ,
V_222 , V_223 , V_220 , V_221 ) ;
if ( V_223 > V_222 ) {
F_10 ( L_73
L_74 , V_223 , V_218 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
V_54 = V_228 ;
goto V_229;
}
V_209 = F_76 ( V_208 ,
V_224 ) ;
if ( ! V_209 ) {
F_10 ( L_75
L_76 ,
V_206 -> V_47 -> V_48 () ,
V_224 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
V_54 = V_228 ;
goto V_229;
}
if ( F_36 ( V_209 ) ) {
F_10 ( L_77
L_78 ) ;
F_38 ( & V_209 -> V_156 , V_157 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
V_54 = V_225 ;
goto V_229;
}
F_12 ( L_79
L_80 ,
V_206 -> V_47 -> V_48 () ,
V_208 -> V_52 , V_209 -> V_119 ) ;
V_212 = F_52 ( V_14 , V_208 ,
V_221 ) ;
if ( V_212 ) {
F_6 ( V_212 ) ;
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
V_218 += V_223 ;
V_222 -= V_223 ;
V_223 = 0 ;
continue;
}
V_215 = F_68 ( sizeof( struct V_214 ) ,
V_164 ) ;
if ( ! V_215 ) {
F_10 ( L_58 ) ;
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
V_54 = V_225 ;
goto V_229;
}
F_26 ( & V_215 -> V_226 ) ;
V_215 -> V_206 = V_206 ;
V_215 -> V_208 = V_208 ;
V_215 -> V_209 = V_209 ;
V_146 = F_33 ( V_209 -> V_49 ,
F_39 ( & V_209 -> V_156 . V_158 ) != 0 ) ;
V_210 = F_29 ( V_12 -> V_15 ,
V_208 , V_146 , V_209 ,
V_209 -> V_119 , V_221 ,
V_121 , V_122 , V_123 ) ;
if ( ! V_210 ) {
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
F_69 ( V_215 ) ;
V_54 = V_228 ;
goto V_229;
}
V_215 -> V_210 = V_210 ;
F_41 ( & V_215 -> V_226 , & V_213 ) ;
V_218 += V_223 ;
V_222 -= V_223 ;
V_223 = 0 ;
}
F_77 ( V_12 ) ;
F_30 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_206 = V_216 -> V_206 ;
V_208 = V_216 -> V_208 ;
V_209 = V_216 -> V_209 ;
V_210 = V_216 -> V_210 ;
F_42 ( & V_216 -> V_226 ) ;
F_69 ( V_216 ) ;
memset ( V_174 , 0 , V_175 ) ;
F_1 ( V_210 , V_174 , V_175 ) ;
F_47 ( V_12 -> V_15 , V_208 ,
V_210 , 0 , 0 ) ;
F_12 ( L_81
L_82
L_83 , V_206 -> V_47 -> V_48 () ,
V_208 -> V_52 , V_174 , ( V_209 ) ?
V_209 -> V_119 : 0 ) ;
if ( ! V_209 )
continue;
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
}
return 0 ;
V_229:
F_77 ( V_12 ) ;
V_43:
F_30 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_206 = V_216 -> V_206 ;
V_208 = V_216 -> V_208 ;
V_209 = V_216 -> V_209 ;
V_210 = V_216 -> V_210 ;
F_42 ( & V_216 -> V_226 ) ;
F_69 ( V_216 ) ;
F_30 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_42 ( & V_150 -> V_130 ) ;
F_40 ( V_150 -> V_132 ) ;
F_43 ( V_124 , V_150 ) ;
}
F_43 ( V_124 , V_210 ) ;
if ( ! V_209 )
continue;
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_206 ) ;
}
return V_54 ;
}
static int F_78 (
struct V_13 * V_14 ,
unsigned char * V_3 ,
T_1 V_234 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned char V_235 [ 512 ] , V_236 [ 32 ] ;
T_6 V_237 = 0 ;
int V_238 = 0 ;
int V_54 = 0 ;
F_7 ( & V_14 -> V_44 ) ;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_32 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
V_235 [ 0 ] = '\0' ;
V_236 [ 0 ] = '\0' ;
V_40 = V_2 -> V_112 -> V_42 ;
if ( V_2 -> V_5 )
snprintf ( V_236 , 32 , L_84 ,
V_2 -> V_6 ) ;
if ( V_14 -> V_110 == V_2 ) {
snprintf ( V_235 , 512 , L_85
L_86
L_87
L_88
L_89
L_90
L_91 , V_238 ,
V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_52 , V_236 ,
V_2 -> V_111 , V_2 -> V_8 ,
V_2 -> V_166 , V_2 -> V_137 ,
V_2 -> V_133 ) ;
} else {
snprintf ( V_235 , 512 , L_92
L_93
L_94
L_95 ,
V_238 , V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_52 , V_236 ,
V_2 -> V_111 , V_2 -> V_137 ,
V_2 -> V_133 ) ;
}
if ( ( V_237 + strlen ( V_235 ) >= V_234 ) ) {
F_10 ( L_96
L_97 ) ;
V_54 = - V_239 ;
goto V_43;
}
V_237 += sprintf ( V_3 + V_237 , L_33 , V_235 ) ;
snprintf ( V_235 , 512 , L_98
L_99
L_100 , V_40 -> V_47 -> V_48 () ,
V_40 -> V_47 -> V_176 ( V_40 ) ,
V_40 -> V_47 -> V_177 ( V_40 ) ,
V_2 -> V_135 , V_2 -> V_134 ,
V_238 ) ;
if ( ( V_237 + strlen ( V_235 ) >= V_234 ) ) {
F_10 ( L_96
L_97 ) ;
V_54 = - V_239 ;
goto V_43;
}
V_237 += sprintf ( V_3 + V_237 , L_33 , V_235 ) ;
V_238 ++ ;
}
if ( ! V_238 )
V_237 += sprintf ( V_3 + V_237 , L_101 ) ;
V_43:
F_9 ( & V_14 -> V_32 . V_36 ) ;
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
static int F_79 (
struct V_13 * V_14 ,
unsigned char * V_3 )
{
struct V_240 * V_241 = & V_14 -> V_240 ;
struct V_242 * V_242 ;
int V_243 = V_244 | V_245 | V_246 ;
char V_247 [ 512 ] ;
T_1 V_234 ;
int V_54 ;
memset ( V_247 , 0 , 512 ) ;
if ( strlen ( & V_241 -> V_248 [ 0 ] ) >= 512 ) {
F_10 ( L_102
L_103 ) ;
return - V_239 ;
}
snprintf ( V_247 , 512 , L_104 , & V_241 -> V_248 [ 0 ] ) ;
V_242 = F_80 ( V_247 , V_243 , 0600 ) ;
if ( F_81 ( V_242 ) ) {
F_10 ( L_105
L_78 , V_247 ) ;
return F_82 ( V_242 ) ;
}
V_234 = ( strlen ( V_3 ) + 1 ) ;
V_54 = F_83 ( V_242 , V_3 , V_234 , 0 ) ;
if ( V_54 < 0 )
F_12 ( L_106 , V_247 ) ;
F_84 ( V_242 ) ;
return ( V_54 < 0 ) ? - V_249 : 0 ;
}
static T_2 F_85 ( struct V_13 * V_14 , bool V_123 )
{
unsigned char * V_3 ;
int V_41 , V_237 = V_250 ;
if ( ! V_123 ) {
char * V_251 = L_107 ;
V_41 = F_79 ( V_14 , V_251 ) ;
V_14 -> V_32 . V_179 = 0 ;
F_12 ( L_108 ) ;
if ( V_41 )
return V_225 ;
return 0 ;
}
V_252:
V_3 = F_86 ( V_237 ) ;
if ( ! V_3 )
return V_253 ;
V_41 = F_78 ( V_14 , V_3 , V_237 ) ;
if ( V_41 < 0 ) {
F_87 ( V_3 ) ;
V_237 *= 2 ;
goto V_252;
}
V_41 = F_79 ( V_14 , V_3 ) ;
if ( V_41 != 0 ) {
F_10 ( L_109 ) ;
F_87 ( V_3 ) ;
return V_225 ;
}
V_14 -> V_32 . V_179 = 1 ;
F_87 ( V_3 ) ;
F_12 ( L_110 ) ;
return 0 ;
}
static T_2
F_88 ( struct V_11 * V_12 , T_3 V_254 , T_3 V_121 ,
bool V_123 , bool V_122 , bool V_255 , enum V_180 V_180 )
{
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_256 , * V_150 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char V_236 [ V_139 ] , * V_191 = NULL ;
T_2 V_54 = V_257 ;
int V_258 = 0 , type ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_111 ) ;
return V_225 ;
}
V_42 = V_18 -> V_42 ;
if ( V_42 -> V_47 -> V_188 ) {
memset ( & V_236 [ 0 ] , 0 , V_139 ) ;
V_42 -> V_47 -> V_188 ( V_18 , & V_236 [ 0 ] ,
V_139 ) ;
V_191 = & V_236 [ 0 ] ;
}
V_2 = F_5 ( V_14 , V_18 -> V_24 , V_18 ) ;
if ( ! V_2 ) {
if ( V_254 ) {
F_70 ( L_112
L_113 ) ;
return V_25 ;
}
if ( ! V_121 )
return 0 ;
if ( ! V_255 ) {
if ( F_51 ( V_12 -> V_15 ,
V_18 -> V_24 , V_12 -> V_49 ,
NULL , V_12 -> V_51 , V_191 ,
V_121 , V_122 , V_123 ,
V_180 , 0 ) ) {
F_10 ( L_114
L_115 ) ;
return V_228 ;
}
} else {
V_54 = F_66 ( V_12 , V_42 ,
V_191 , V_121 , V_122 , V_123 ) ;
if ( V_54 != 0 )
return V_54 ;
}
return F_85 ( V_14 , V_123 ) ;
}
if ( ( V_180 == REGISTER ) && ( V_254 != V_2 -> V_111 ) ) {
F_10 ( L_116
L_117
L_118
L_119 , V_254 ,
V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_43;
}
if ( V_255 ) {
F_10 ( L_120
L_121 ) ;
V_54 = V_228 ;
goto V_43;
}
if ( V_2 -> V_137 && ! V_122 ) {
F_10 ( L_122
L_123
L_124 ) ;
V_54 = V_259 ;
goto V_43;
}
if ( V_121 ) {
V_2 -> V_185 = F_23 ( V_12 -> V_15 ) ;
V_2 -> V_111 = V_121 ;
F_12 ( L_125
L_126
L_127 , V_12 -> V_260 -> V_48 () ,
( V_180 == V_182 ) ? L_46 : L_30 ,
V_2 -> V_112 -> V_52 ,
V_2 -> V_111 , V_2 -> V_185 ) ;
} else {
type = V_2 -> V_8 ;
V_258 = F_55 ( V_12 -> V_15 ,
V_2 ) ;
if ( V_258 < 0 ) {
V_54 = V_25 ;
goto V_43;
}
F_7 ( & V_31 -> V_36 ) ;
if ( V_2 -> V_137 ) {
F_30 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_256 -> V_137 )
continue;
if ( V_256 -> V_111 != V_254 )
continue;
if ( V_2 == V_256 )
continue;
if ( strcmp ( V_2 -> V_112 -> V_52 ,
V_256 -> V_112 -> V_52 ) )
continue;
F_57 ( V_14 ,
V_256 , NULL , 0 ) ;
}
}
F_57 ( V_12 -> V_15 , V_2 , NULL , 1 ) ;
V_2 = NULL ;
if ( V_258 &&
( type == V_34 ||
type == V_35 ) ) {
F_32 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_89 (
V_256 -> V_112 ,
V_256 -> V_133 ,
0x2A ,
V_261 ) ;
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
return L_128 ;
case V_71 :
return L_129 ;
case V_34 :
return L_130 ;
case V_35 :
return L_131 ;
case V_9 :
return L_132 ;
case V_10 :
return L_133 ;
default:
break;
}
return L_134 ;
}
static T_2
F_90 ( struct V_11 * V_12 , int type , int V_262 , T_3 V_254 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_1 * V_2 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
char V_174 [ V_175 ] ;
T_2 V_54 ;
memset ( V_174 , 0 , V_175 ) ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_111 ) ;
return V_225 ;
}
V_2 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_135
L_136 ) ;
return V_225 ;
}
if ( V_254 != V_2 -> V_111 ) {
F_10 ( L_137
L_138
L_119 , V_254 , V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_263;
}
if ( V_262 != V_264 ) {
F_10 ( L_139 , V_262 ) ;
V_54 = V_228 ;
goto V_263;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 ) {
if ( ! F_2 ( V_7 , V_2 ) ) {
struct V_24 * V_196 = V_7 -> V_112 ;
F_10 ( L_140
L_141
L_142 ,
V_12 -> V_260 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_196 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_263;
}
if ( ( V_7 -> V_8 != type ) ||
( V_7 -> V_166 != V_262 ) ) {
struct V_24 * V_196 = V_7 -> V_112 ;
F_10 ( L_140
L_143
L_144
L_4 ,
V_12 -> V_260 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_196 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_263;
}
F_9 ( & V_14 -> V_44 ) ;
V_54 = 0 ;
goto V_263;
}
V_2 -> V_166 = V_262 ;
V_2 -> V_8 = type ;
V_2 -> V_7 = 1 ;
V_14 -> V_110 = V_2 ;
F_1 ( V_2 , V_174 , V_175 ) ;
F_12 ( L_145
L_146 ,
V_12 -> V_260 -> V_48 () , F_20 ( type ) ,
( V_2 -> V_137 ) ? 1 : 0 ) ;
F_12 ( L_42 ,
V_12 -> V_260 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_174 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( V_31 -> V_179 )
F_85 ( V_12 -> V_15 , true ) ;
V_54 = 0 ;
V_263:
F_6 ( V_2 ) ;
return V_54 ;
}
static T_2
F_91 ( struct V_11 * V_12 , int type , int V_262 ,
T_3 V_254 )
{
switch ( type ) {
case V_70 :
case V_71 :
case V_34 :
case V_35 :
case V_9 :
case V_10 :
return F_90 ( V_12 , type , V_262 , V_254 ) ;
default:
F_10 ( L_147
L_148 , type ) ;
return V_259 ;
}
}
static void F_56 (
struct V_13 * V_14 ,
struct V_24 * V_265 ,
struct V_1 * V_2 ,
int V_266 ,
int V_267 )
{
const struct V_147 * V_148 = V_265 -> V_42 -> V_47 ;
char V_174 [ V_175 ] ;
int V_8 = 0 , V_166 = 0 ;
memset ( V_174 , 0 , V_175 ) ;
F_1 ( V_2 , V_174 , V_175 ) ;
if ( V_14 -> V_110 ) {
V_8 = V_14 -> V_110 -> V_8 ;
V_166 = V_14 -> V_110 -> V_166 ;
V_14 -> V_110 -> V_8 = 0 ;
V_14 -> V_110 -> V_166 = 0 ;
V_14 -> V_110 -> V_7 = 0 ;
V_14 -> V_110 = NULL ;
}
if ( ! V_267 )
goto V_43;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_92 ( & V_2 -> V_126 ) ;
if ( ! F_8 ( & V_14 -> V_32 . V_37 ) &&
( ( V_8 == V_9 ) ||
( V_8 == V_10 ) ) ) {
V_14 -> V_110 =
F_93 ( V_14 -> V_32 . V_37 . V_145 ,
struct V_1 , V_126 ) ;
V_14 -> V_110 -> V_8 = V_8 ;
V_14 -> V_110 -> V_166 = V_166 ;
V_14 -> V_110 -> V_7 = 1 ;
}
F_9 ( & V_14 -> V_32 . V_36 ) ;
V_43:
if ( ! V_14 -> V_110 ) {
F_12 ( L_149
L_146 ,
V_148 -> V_48 () , ( V_266 ) ? L_150 :
L_151 , F_20 ( V_8 ) ,
( V_2 -> V_137 ) ? 1 : 0 ) ;
}
F_12 ( L_152 ,
V_148 -> V_48 () , V_265 -> V_52 ,
V_174 ) ;
V_2 -> V_7 = V_2 -> V_8 = V_2 -> V_166 = 0 ;
}
static T_2
F_94 ( struct V_11 * V_12 , int type , int V_262 ,
T_3 V_254 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_1 * V_2 , * V_256 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
T_2 V_54 = 0 ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_111 ) ;
return V_225 ;
}
V_2 = F_5 ( V_14 , V_18 -> V_24 , V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_135
L_153 ) ;
return V_225 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ! V_7 ) {
F_9 ( & V_14 -> V_44 ) ;
goto V_263;
}
if ( ! F_2 ( V_7 , V_2 ) ) {
F_9 ( & V_14 -> V_44 ) ;
goto V_263;
}
if ( V_254 != V_2 -> V_111 ) {
F_10 ( L_154
L_138
L_119 , V_254 , V_2 -> V_111 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_263;
}
if ( ( V_7 -> V_8 != type ) ||
( V_7 -> V_166 != V_262 ) ) {
struct V_24 * V_196 = V_7 -> V_112 ;
F_10 ( L_155
L_156
L_157
L_142 ,
V_12 -> V_260 -> V_48 () ,
V_18 -> V_24 -> V_52 ,
V_196 -> V_42 -> V_47 -> V_48 () ,
V_7 -> V_112 -> V_52 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_263;
}
F_56 ( V_14 , V_18 -> V_24 ,
V_2 , 1 , 0 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( ( type != V_34 ) &&
( type != V_35 ) &&
( type != V_9 ) &&
( type != V_10 ) ) {
goto V_268;
}
F_7 ( & V_31 -> V_36 ) ;
F_32 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_256 == V_2 )
continue;
F_89 ( V_256 -> V_112 ,
V_256 -> V_133 ,
0x2A , V_261 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
V_268:
if ( V_31 -> V_179 )
F_85 ( V_12 -> V_15 , true ) ;
V_263:
F_6 ( V_2 ) ;
return V_54 ;
}
static T_2
F_95 ( struct V_11 * V_12 , T_3 V_254 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_24 * V_112 ;
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
struct V_1 * V_2 , * V_150 , * V_269 , * V_7 ;
T_3 V_133 = 0 ;
int V_270 = 0 ;
V_269 = F_5 ( V_12 -> V_15 ,
V_18 -> V_24 , V_18 ) ;
if ( ! V_269 ) {
F_10 ( L_135
L_158 ) ;
return V_225 ;
}
if ( V_254 != V_269 -> V_111 ) {
F_10 ( L_116
L_117
L_118
L_119 , V_254 , V_269 -> V_111 ) ;
F_6 ( V_269 ) ;
return V_25 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 ) {
struct V_24 * V_196 = V_7 -> V_112 ;
F_56 ( V_14 , V_196 ,
V_7 , 0 , 0 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_270 = ( V_269 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_133 = V_2 -> V_133 ;
F_57 ( V_14 , V_2 , NULL ,
V_270 ) ;
if ( ! V_270 )
F_89 ( V_112 , V_133 ,
0x2A , V_271 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_12 ( L_159 ,
V_12 -> V_260 -> V_48 () ) ;
F_85 ( V_12 -> V_15 , false ) ;
F_23 ( V_14 ) ;
return 0 ;
}
static void F_96 (
struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_192 * V_193 ,
int type ,
int V_262 ,
enum V_272 V_272 )
{
struct V_24 * V_59 = V_2 -> V_112 ;
const struct V_147 * V_148 = V_59 -> V_42 -> V_47 ;
char V_174 [ V_175 ] ;
memset ( V_174 , 0 , V_175 ) ;
F_1 ( V_2 , V_174 , V_175 ) ;
if ( V_14 -> V_110 )
F_56 ( V_14 , V_59 ,
V_14 -> V_110 , 0 , 0 ) ;
V_14 -> V_110 = V_2 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = type ;
V_2 -> V_166 = V_262 ;
F_12 ( L_160
L_146 ,
V_148 -> V_48 () , ( V_272 == V_273 ) ? L_161 : L_30 ,
F_20 ( type ) ,
( V_2 -> V_137 ) ? 1 : 0 ) ;
F_12 ( L_162 ,
V_148 -> V_48 () , ( V_272 == V_273 ) ? L_161 : L_30 ,
V_59 -> V_52 , V_174 ) ;
if ( V_193 )
F_41 ( & V_2 -> V_127 ,
V_193 ) ;
}
static void F_97 (
struct V_192 * V_193 ,
struct V_1 * V_274 )
{
struct V_1 * V_2 , * V_150 ;
F_30 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_42 ( & V_2 -> V_127 ) ;
if ( V_274 == V_2 )
continue;
if ( V_2 -> V_7 ) {
F_70 ( L_163 ) ;
continue;
}
V_2 -> V_132 = NULL ;
V_2 -> V_112 = NULL ;
F_43 ( V_124 , V_2 ) ;
}
}
static T_2
F_98 ( struct V_11 * V_12 , int type , int V_262 , T_3 V_254 ,
T_3 V_121 , enum V_272 V_272 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_24 * V_112 ;
struct V_16 * V_18 = V_12 -> V_18 ;
F_67 ( V_193 ) ;
struct V_1 * V_2 , * V_150 , * V_269 , * V_7 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
T_3 V_133 = 0 ;
int V_62 = 0 , V_270 = 0 ;
bool V_275 = V_121 != 0 ;
int V_276 = 0 , V_277 = 0 ;
if ( ! V_18 )
return V_225 ;
V_269 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_269 ) {
F_10 ( L_135
L_164 ,
( V_272 == V_273 ) ? L_161 : L_30 ) ;
return V_25 ;
}
if ( V_269 -> V_111 != V_254 ) {
F_6 ( V_269 ) ;
return V_25 ;
}
if ( V_262 != V_264 ) {
F_10 ( L_139 , V_262 ) ;
F_6 ( V_269 ) ;
return V_228 ;
}
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( V_7 &&
( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ) )
V_62 = 1 ;
if ( ! V_62 && ! V_121 ) {
F_9 ( & V_14 -> V_44 ) ;
F_6 ( V_269 ) ;
return V_228 ;
}
if ( ! V_7 || ( V_7 -> V_111 != V_121 ) ) {
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_62 ) {
if ( V_2 -> V_111 != V_121 )
continue;
V_275 = false ;
V_270 = ( V_269 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_133 = V_2 -> V_133 ;
F_57 ( V_14 , V_2 ,
( V_272 == V_273 ) ? & V_193 :
NULL , V_270 ) ;
} else {
if ( ( V_121 ) &&
( V_2 -> V_111 != V_121 ) )
continue;
V_275 = false ;
V_270 = ( V_269 == V_2 ) ? 1 : 0 ;
if ( V_270 )
continue;
V_112 = V_2 -> V_112 ;
V_133 = V_2 -> V_133 ;
F_57 ( V_14 , V_2 ,
( V_272 == V_273 ) ? & V_193 :
NULL , 0 ) ;
}
if ( ! V_270 )
F_89 ( V_112 ,
V_133 , 0x2A ,
V_278 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
if ( V_275 ) {
F_9 ( & V_14 -> V_44 ) ;
F_6 ( V_269 ) ;
return V_25 ;
}
if ( V_7 && V_62 && ! ( V_121 ) ) {
F_96 ( V_14 , V_269 ,
( V_272 == V_273 ) ? & V_193 : NULL ,
type , V_262 , V_272 ) ;
if ( V_272 == V_273 )
F_97 (
& V_193 , V_269 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
if ( V_31 -> V_179 )
F_85 ( V_12 -> V_15 , true ) ;
F_6 ( V_269 ) ;
F_23 ( V_12 -> V_15 ) ;
return 0 ;
}
V_276 = V_7 -> V_8 ;
V_277 = V_7 -> V_166 ;
if ( V_269 != V_7 )
F_56 ( V_14 ,
V_7 -> V_112 ,
V_14 -> V_110 , 0 , 0 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_270 = ( V_269 == V_2 ) ? 1 : 0 ;
if ( V_270 )
continue;
if ( V_2 -> V_111 != V_121 )
continue;
V_112 = V_2 -> V_112 ;
V_133 = V_2 -> V_133 ;
F_57 ( V_14 , V_2 ,
( V_272 == V_273 ) ? & V_193 : NULL ,
V_270 ) ;
F_89 ( V_112 , V_133 , 0x2A ,
V_278 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
F_96 ( V_14 , V_269 ,
( V_272 == V_273 ) ? & V_193 : NULL ,
type , V_262 , V_272 ) ;
if ( ( V_276 != type ) || ( V_277 != V_262 ) ) {
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_270 = ( V_269 == V_2 ) ? 1 : 0 ;
if ( V_270 )
continue;
F_89 ( V_2 -> V_112 ,
V_2 -> V_133 , 0x2A ,
V_261 ) ;
}
F_9 ( & V_31 -> V_36 ) ;
}
F_9 ( & V_14 -> V_44 ) ;
if ( V_272 == V_273 ) {
F_99 ( V_14 , NULL , & V_193 , V_12 ) ;
F_97 ( & V_193 ,
V_269 ) ;
}
if ( V_31 -> V_179 )
F_85 ( V_12 -> V_15 , true ) ;
F_6 ( V_269 ) ;
F_23 ( V_12 -> V_15 ) ;
return 0 ;
}
static T_2
F_100 ( struct V_11 * V_12 , int type , int V_262 ,
T_3 V_254 , T_3 V_121 , enum V_272 V_272 )
{
switch ( type ) {
case V_70 :
case V_71 :
case V_34 :
case V_35 :
case V_9 :
case V_10 :
return F_98 ( V_12 , type , V_262 , V_254 ,
V_121 , V_272 ) ;
default:
F_10 ( L_165
L_166 , ( V_272 == V_273 ) ? L_161 : L_30 , type ) ;
return V_259 ;
}
}
static T_2
F_101 ( struct V_11 * V_12 , T_3 V_254 ,
T_3 V_121 , int V_123 , int V_267 )
{
struct V_16 * V_18 = V_12 -> V_18 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_66 * V_209 = NULL ;
struct V_49 * V_49 = V_12 -> V_49 , * V_230 ;
struct V_24 * V_196 , * V_112 , * V_208 = NULL ;
struct V_39 * V_42 , * V_279 = NULL ;
const struct V_147 * V_280 = NULL , * V_281 ;
struct V_1 * V_2 , * V_7 , * V_210 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char * V_3 ;
const unsigned char * V_282 ;
char * V_221 = NULL , V_174 [ V_175 ] ;
T_1 V_223 , V_283 ;
int V_284 = 0 , type , V_262 , V_285 ;
T_2 V_54 ;
unsigned short V_286 ;
unsigned char V_219 ;
if ( ! V_18 || ! V_49 ) {
F_10 ( L_111 ) ;
return V_225 ;
}
memset ( V_174 , 0 , V_175 ) ;
V_42 = V_18 -> V_42 ;
V_281 = V_42 -> V_47 ;
V_2 = F_5 ( V_12 -> V_15 , V_18 -> V_24 ,
V_18 ) ;
if ( ! V_2 ) {
F_10 ( L_167
L_168 ) ;
return V_225 ;
}
if ( V_254 != V_2 -> V_111 ) {
F_70 ( L_169
L_170
L_171 , V_254 , V_2 -> V_111 ) ;
V_54 = V_25 ;
goto V_263;
}
if ( ! V_121 ) {
F_70 ( L_172
L_173 ) ;
V_54 = V_228 ;
goto V_263;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_225 ;
goto V_263;
}
V_286 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_286 |= V_3 [ 19 ] & 0xff ;
V_223 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_223 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_223 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_223 |= V_3 [ 23 ] & 0xff ;
F_77 ( V_12 ) ;
V_3 = NULL ;
if ( ( V_223 + 24 ) != V_12 -> V_227 ) {
F_10 ( L_174
L_62 , V_223 ,
V_12 -> V_227 ) ;
V_54 = V_228 ;
goto V_263;
}
F_7 ( & V_14 -> V_152 ) ;
F_32 (tmp_lun, &dev->dev_sep_list, lun_dev_link) {
if ( V_230 -> V_136 != V_286 )
continue;
V_279 = V_230 -> V_231 ;
V_280 = V_279 -> V_47 ;
if ( ! V_280 )
continue;
F_53 ( & V_279 -> V_199 ) ;
F_9 ( & V_14 -> V_152 ) ;
if ( F_60 ( V_279 ) ) {
F_10 ( L_175
L_176 ) ;
F_54 ( & V_279 -> V_199 ) ;
V_54 = V_225 ;
goto V_263;
}
F_7 ( & V_14 -> V_152 ) ;
break;
}
F_9 ( & V_14 -> V_152 ) ;
if ( ! V_279 || ! V_280 ) {
F_10 ( L_177
L_178
L_179 , V_286 ) ;
V_54 = V_228 ;
goto V_263;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 ) {
V_54 = V_225 ;
goto V_263;
}
V_219 = ( V_3 [ 24 ] & 0x0f ) ;
F_12 ( L_180
L_148 , V_219 ) ;
if ( V_219 != V_279 -> V_232 ) {
F_10 ( L_169
L_181
L_182 , V_219 ,
V_279 -> V_232 ,
V_280 -> V_48 () ) ;
V_54 = V_228 ;
goto V_43;
}
V_282 = F_72 ( V_279 ,
( const char * ) & V_3 [ 24 ] , & V_283 , & V_221 ) ;
if ( ! V_282 ) {
F_10 ( L_177
L_183 ) ;
V_54 = V_228 ;
goto V_43;
}
F_77 ( V_12 ) ;
V_3 = NULL ;
F_12 ( L_184
L_185 , V_280 -> V_48 () , ( V_221 != NULL ) ?
L_186 : L_187 , V_282 , ( V_221 != NULL ) ?
V_221 : L_30 ) ;
V_112 = V_2 -> V_112 ;
V_285 = ( ! strcmp ( V_282 ,
V_112 -> V_52 ) ) ? 1 : 0 ;
if ( ! V_285 )
goto V_287;
if ( ! V_221 || ! V_2 -> V_5 ) {
F_10 ( L_188
L_189 , V_282 ,
V_112 -> V_52 ) ;
V_54 = V_228 ;
goto V_43;
}
if ( ! strcmp ( V_221 , V_2 -> V_6 ) ) {
F_10 ( L_190
L_191 ,
V_282 , V_221 , V_112 -> V_52 ,
V_2 -> V_6 ) ;
V_54 = V_228 ;
goto V_43;
}
V_287:
F_73 ( & V_279 -> V_233 ) ;
V_208 = F_74 ( V_279 ,
V_282 ) ;
if ( V_208 )
F_53 ( & V_208 -> V_202 ) ;
F_75 ( & V_279 -> V_233 ) ;
if ( ! V_208 ) {
F_10 ( L_192
L_193 , V_280 -> V_48 () ,
V_282 ) ;
V_54 = V_228 ;
goto V_43;
}
if ( F_64 ( V_208 ) ) {
F_10 ( L_194
L_195 ) ;
F_54 ( & V_208 -> V_202 ) ;
V_208 = NULL ;
V_54 = V_228 ;
goto V_43;
}
F_12 ( L_196
L_197 , V_280 -> V_48 () ,
V_208 -> V_52 ) ;
V_209 = F_76 ( V_208 , V_286 ) ;
if ( ! V_209 ) {
F_10 ( L_198
L_179 , V_280 -> V_48 () , V_286 ) ;
V_54 = V_228 ;
goto V_43;
}
if ( F_36 ( V_209 ) ) {
F_10 ( L_199 ) ;
F_38 ( & V_209 -> V_156 , V_157 ) ;
V_209 = NULL ;
V_54 = V_225 ;
goto V_43;
}
F_12 ( L_200
L_201 ,
V_280 -> V_48 () , V_208 -> V_52 ,
V_209 -> V_119 ) ;
F_7 ( & V_14 -> V_44 ) ;
V_7 = V_14 -> V_110 ;
if ( ! V_7 ) {
F_70 ( L_202
L_203 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_259 ;
goto V_43;
}
if ( ! F_2 ( V_7 , V_2 ) ) {
F_70 ( L_204
L_205 ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_43;
}
if ( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ) {
F_70 ( L_206
L_207 ,
F_20 ( V_7 -> V_8 ) ) ;
F_9 ( & V_14 -> V_44 ) ;
V_54 = V_25 ;
goto V_43;
}
V_196 = V_7 -> V_112 ;
type = V_7 -> V_8 ;
V_262 = V_7 -> V_8 ;
V_210 = F_52 ( V_14 , V_208 ,
V_221 ) ;
if ( ! V_210 ) {
struct V_49 * V_146 = F_33 ( V_209 -> V_49 ,
F_39 ( & V_209 -> V_156 . V_158 ) != 0 ) ;
F_9 ( & V_14 -> V_44 ) ;
if ( F_51 ( V_12 -> V_15 , V_208 ,
V_146 , V_209 , V_209 -> V_119 ,
V_221 , V_121 , 0 , V_123 , 2 , 1 ) ) {
V_54 = V_228 ;
goto V_43;
}
F_7 ( & V_14 -> V_44 ) ;
V_210 = F_52 ( V_14 , V_208 ,
V_221 ) ;
V_284 = 1 ;
}
F_56 ( V_14 , V_196 ,
V_14 -> V_110 , 0 , 0 ) ;
V_14 -> V_110 = V_210 ;
V_210 -> V_7 = 1 ;
V_210 -> V_8 = type ;
V_2 -> V_166 = V_262 ;
F_1 ( V_2 , V_174 , V_175 ) ;
if ( ! V_284 )
V_210 -> V_185 = V_31 -> V_116 ++ ;
F_9 ( & V_14 -> V_44 ) ;
F_12 ( L_208
L_209
L_210 , V_280 -> V_48 () ,
F_20 ( type ) , V_286 ,
V_210 -> V_185 ) ;
F_12 ( L_211
L_212 ,
V_281 -> V_48 () , V_112 -> V_52 ,
V_174 , V_280 -> V_48 () ,
V_208 -> V_52 , ( V_221 != NULL ) ?
V_221 : L_30 ) ;
F_40 ( V_209 ) ;
F_65 ( V_208 ) ;
F_62 ( V_279 ) ;
if ( V_267 ) {
F_7 ( & V_31 -> V_36 ) ;
F_57 ( V_14 , V_2 , NULL , 1 ) ;
F_9 ( & V_31 -> V_36 ) ;
} else
F_6 ( V_2 ) ;
F_85 ( V_12 -> V_15 , V_123 ) ;
F_77 ( V_12 ) ;
F_6 ( V_210 ) ;
return 0 ;
V_43:
if ( V_3 )
F_77 ( V_12 ) ;
if ( V_209 )
F_40 ( V_209 ) ;
if ( V_208 )
F_65 ( V_208 ) ;
F_62 ( V_279 ) ;
V_263:
F_6 ( V_2 ) ;
return V_54 ;
}
static unsigned long long F_102 ( unsigned char * V_58 )
{
unsigned int V_288 , V_289 ;
V_288 = ( V_58 [ 0 ] << 24 ) | ( V_58 [ 1 ] << 16 ) | ( V_58 [ 2 ] << 8 ) | V_58 [ 3 ] ;
V_289 = ( V_58 [ 4 ] << 24 ) | ( V_58 [ 5 ] << 16 ) | ( V_58 [ 6 ] << 8 ) | V_58 [ 7 ] ;
return ( ( unsigned long long ) V_289 ) | ( unsigned long long ) V_288 << 32 ;
}
T_2
F_103 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned char * V_58 = & V_12 -> V_19 [ 0 ] ;
unsigned char * V_3 ;
T_3 V_254 , V_121 ;
int V_290 , V_262 , type , V_123 ;
int V_255 = 0 , V_122 = 0 , V_267 = 0 ;
T_2 V_54 ;
if ( V_12 -> V_15 -> V_26 & V_46 ) {
F_10 ( L_213
L_214
L_215 ) ;
return V_25 ;
}
if ( ! V_12 -> V_18 )
return V_225 ;
if ( V_12 -> V_227 < 24 ) {
F_70 ( L_59
L_60 , V_12 -> V_227 ) ;
return V_228 ;
}
V_290 = ( V_58 [ 1 ] & 0x1f ) ;
V_262 = ( V_58 [ 2 ] & 0xf0 ) ;
type = ( V_58 [ 2 ] & 0x0f ) ;
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_225 ;
V_254 = F_102 ( & V_3 [ 0 ] ) ;
V_121 = F_102 ( & V_3 [ 8 ] ) ;
if ( V_290 != V_85 ) {
V_255 = ( V_3 [ 20 ] & 0x08 ) ;
V_122 = ( V_3 [ 20 ] & 0x04 ) ;
V_123 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_123 = ( V_3 [ 17 ] & 0x01 ) ;
V_267 = ( V_3 [ 17 ] & 0x02 ) ;
}
if ( V_14 -> V_189 . V_291 )
V_123 = 1 ;
F_77 ( V_12 ) ;
V_3 = NULL ;
if ( V_255 && ( ( V_58 [ 1 ] & 0x1f ) != V_83 ) )
return V_228 ;
if ( ! V_255 && ( ( V_58 [ 1 ] & 0x1f ) != V_85 ) &&
( V_12 -> V_227 != 24 ) ) {
F_70 ( L_216
L_217 , V_12 -> V_227 ) ;
return V_228 ;
}
switch ( V_290 ) {
case V_83 :
V_54 = F_88 ( V_12 ,
V_254 , V_121 , V_123 , V_122 , V_255 , REGISTER ) ;
break;
case V_86 :
V_54 = F_91 ( V_12 , type , V_262 , V_254 ) ;
break;
case V_87 :
V_54 = F_94 ( V_12 , type , V_262 , V_254 ) ;
break;
case V_80 :
V_54 = F_95 ( V_12 , V_254 ) ;
break;
case V_81 :
V_54 = F_100 ( V_12 , type , V_262 ,
V_254 , V_121 , V_292 ) ;
break;
case V_82 :
V_54 = F_100 ( V_12 , type , V_262 ,
V_254 , V_121 , V_273 ) ;
break;
case V_84 :
V_54 = F_88 ( V_12 ,
0 , V_121 , V_123 , V_122 , V_255 , V_182 ) ;
break;
case V_85 :
V_54 = F_101 ( V_12 , V_254 ,
V_121 , V_123 , V_267 ) ;
break;
default:
F_10 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return V_259 ;
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
T_1 V_293 = 0 , V_294 = 8 ;
if ( V_12 -> V_227 < 8 ) {
F_10 ( L_218
L_219 , V_12 -> V_227 ) ;
return V_259 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_225 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_32 . V_36 ) ;
F_32 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_293 + 8 ) > ( V_12 -> V_227 - 8 ) )
break;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_293 += 8 ;
}
F_9 ( & V_14 -> V_32 . V_36 ) ;
V_3 [ 4 ] = ( ( V_293 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_293 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_293 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_293 & 0xff ) ;
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
T_1 V_293 = 16 ;
if ( V_12 -> V_227 < 8 ) {
F_10 ( L_220
L_219 , V_12 -> V_227 ) ;
return V_259 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_225 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_44 ) ;
V_2 = V_14 -> V_110 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_293 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_293 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_293 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_293 & 0xff ) ;
if ( V_12 -> V_227 < 22 )
goto V_295;
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
V_3 [ 21 ] = ( V_2 -> V_166 & 0xf0 ) |
( V_2 -> V_8 & 0x0f ) ;
}
V_295:
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
T_4 V_293 = 8 ;
if ( V_12 -> V_227 < 6 ) {
F_10 ( L_221
L_222 , V_12 -> V_227 ) ;
return V_259 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_225 ;
V_3 [ 0 ] = ( ( V_293 >> 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_293 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_31 -> V_179 )
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
struct V_24 * V_265 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_150 ;
struct V_30 * V_31 = & V_14 -> V_32 ;
unsigned char * V_3 ;
T_1 V_296 = 0 , V_293 = 0 ;
T_1 V_294 = 8 ;
int V_297 = 0 , V_8 = 0 , V_166 = 0 ;
int V_298 , V_299 ;
bool V_62 = false ;
if ( V_12 -> V_227 < 8 ) {
F_10 ( L_223
L_219 , V_12 -> V_227 ) ;
return V_259 ;
}
V_3 = F_71 ( V_12 ) ;
if ( ! V_3 )
return V_225 ;
V_3 [ 0 ] = ( ( V_14 -> V_32 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_14 -> V_32 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_14 -> V_32 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_14 -> V_32 . V_116 & 0xff ) ;
F_7 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_110 ) {
struct V_1 * V_258 = V_14 -> V_110 ;
if ( V_258 -> V_8 == V_9 ||
V_258 -> V_8 == V_10 ) {
V_62 = true ;
V_8 = V_258 -> V_8 ;
V_166 = V_258 -> V_166 ;
}
}
F_9 ( & V_14 -> V_44 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_30 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_265 = V_2 -> V_112 ;
V_42 = V_2 -> V_112 -> V_42 ;
V_296 = 0 ;
F_53 ( & V_2 -> V_131 ) ;
F_9 ( & V_31 -> V_36 ) ;
V_298 = F_108 ( V_265 , V_2 ,
& V_297 ) ;
if ( V_298 < 0 ||
V_298 + V_293 > V_12 -> V_227 ) {
F_70 ( L_224
L_225 , V_12 -> V_227 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_54 ( & V_2 -> V_131 ) ;
break;
}
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_294 += 4 ;
if ( V_2 -> V_137 )
V_3 [ V_294 ] = 0x02 ;
if ( V_2 -> V_7 ) {
V_3 [ V_294 ++ ] |= 0x01 ;
V_3 [ V_294 ++ ] = ( V_2 -> V_166 & 0xf0 ) |
( V_2 -> V_8 & 0x0f ) ;
} else if ( V_62 ) {
V_3 [ V_294 ++ ] |= 0x01 ;
V_3 [ V_294 ++ ] = ( V_166 & 0xf0 ) |
( V_8 & 0x0f ) ;
} else {
V_294 += 2 ;
}
V_294 += 4 ;
if ( ! V_2 -> V_137 ) {
T_4 V_300 = V_2 -> V_135 ;
V_3 [ V_294 ++ ] = ( ( V_300 >> 8 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( V_300 & 0xff ) ;
} else
V_294 += 2 ;
V_3 [ V_294 + 4 ] = V_42 -> V_232 ;
V_299 = F_109 ( V_265 , V_2 ,
& V_297 , & V_3 [ V_294 + 4 ] ) ;
F_7 ( & V_31 -> V_36 ) ;
F_54 ( & V_2 -> V_131 ) ;
if ( V_299 < 0 )
break;
V_3 [ V_294 ++ ] = ( ( V_299 >> 24 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_299 >> 16 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( ( V_299 >> 8 ) & 0xff ) ;
V_3 [ V_294 ++ ] = ( V_299 & 0xff ) ;
V_296 = ( 24 + V_299 ) ;
V_294 += V_299 ;
V_293 += V_296 ;
}
F_9 ( & V_31 -> V_36 ) ;
V_3 [ 4 ] = ( ( V_293 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_293 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_293 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_293 & 0xff ) ;
F_77 ( V_12 ) ;
return 0 ;
}
T_2
F_110 ( struct V_11 * V_12 )
{
T_2 V_54 ;
if ( V_12 -> V_15 -> V_26 & V_46 ) {
F_10 ( L_213
L_214
L_215 ) ;
return V_25 ;
}
switch ( V_12 -> V_19 [ 1 ] & 0x1f ) {
case V_301 :
V_54 = F_104 ( V_12 ) ;
break;
case V_302 :
V_54 = F_105 ( V_12 ) ;
break;
case V_303 :
V_54 = F_106 ( V_12 ) ;
break;
case V_304 :
V_54 = F_107 ( V_12 ) ;
break;
default:
F_10 ( L_226
L_16 , V_12 -> V_19 [ 1 ] & 0x1f ) ;
return V_259 ;
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
if ( V_14 -> V_305 -> V_306 & V_307 )
return 0 ;
if ( V_14 -> V_183 -> V_308 & V_309 )
return 0 ;
F_7 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_26 & V_46 )
V_54 = F_3 ( V_12 ) ;
else
V_54 = F_22 ( V_12 ) ;
F_9 ( & V_14 -> V_44 ) ;
return V_54 ;
}
