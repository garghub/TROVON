void F_1 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_4 )
{
if ( ! V_2 -> V_5 )
V_3 [ 0 ] = '\0' ;
snprintf ( V_3 , V_4 , L_1 , V_2 -> V_6 ) ;
}
static T_2
F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_8 -> V_14 ;
switch ( V_8 -> V_15 [ 0 ] ) {
case V_16 :
case V_17 :
case V_18 :
return 0 ;
default:
break;
}
if ( ! V_10 -> V_19 || ! V_13 )
return 0 ;
if ( V_10 -> V_19 != V_13 -> V_20 )
return V_21 ;
if ( V_10 -> V_22 & V_23 ) {
if ( V_10 -> V_24 != V_13 -> V_25 )
return V_21 ;
}
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
int V_29 = 0 ;
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( V_2 ) {
if ( V_2 -> V_30 ) {
F_5 ( V_2 ) ;
return 1 ;
}
if ( ( V_2 -> V_31 == V_32 ) ||
( V_2 -> V_31 == V_33 ) ||
( V_2 -> V_31 == V_34 ) ||
( V_2 -> V_31 == V_35 ) ) {
F_5 ( V_2 ) ;
return 1 ;
}
F_5 ( V_2 ) ;
V_29 = 1 ;
} else {
F_6 ( & V_27 -> V_36 ) ;
V_29 = ( F_7 ( & V_27 -> V_37 ) ) ? 0 : 1 ;
F_8 ( & V_27 -> V_36 ) ;
}
if ( V_29 ) {
F_9 ( L_2
L_3
L_4 ) ;
return - V_38 ;
}
return 0 ;
}
T_2
F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! V_13 || ! V_13 -> V_42 )
goto V_43;
V_41 = F_3 ( V_8 ) ;
if ( V_41 == 1 )
goto V_43;
if ( V_41 < 0 )
return V_21 ;
F_6 ( & V_10 -> V_44 ) ;
if ( ! V_10 -> V_19 || ! V_13 )
goto V_45;
if ( V_10 -> V_19 != V_13 -> V_20 )
goto V_45;
if ( V_10 -> V_24 != V_13 -> V_25 )
goto V_45;
V_10 -> V_19 = NULL ;
V_10 -> V_22 &= ~ V_46 ;
if ( V_10 -> V_22 & V_23 ) {
V_10 -> V_24 = 0 ;
V_10 -> V_22 &= ~ V_23 ;
}
V_40 = V_13 -> V_42 ;
F_11 ( L_5
L_6 , V_40 -> V_47 -> V_48 () ,
V_8 -> V_49 -> V_50 , V_8 -> V_51 -> V_52 ,
V_13 -> V_20 -> V_53 ) ;
V_45:
F_8 ( & V_10 -> V_44 ) ;
V_43:
F_12 ( V_8 , V_54 ) ;
return 0 ;
}
T_2
F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_39 * V_40 ;
T_2 V_55 = 0 ;
int V_41 ;
if ( ( V_8 -> V_15 [ 1 ] & 0x01 ) &&
( V_8 -> V_15 [ 1 ] & 0x02 ) ) {
F_9 ( L_7
L_8 ) ;
return V_56 ;
}
if ( ! V_13 || ! V_13 -> V_42 )
goto V_43;
V_41 = F_3 ( V_8 ) ;
if ( V_41 == 1 )
goto V_43;
if ( V_41 < 0 )
return V_21 ;
V_40 = V_13 -> V_42 ;
F_6 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_19 &&
( V_10 -> V_19 != V_13 -> V_20 ) ) {
F_9 ( L_9 ,
V_40 -> V_47 -> V_48 () ) ;
F_9 ( L_10 ,
V_8 -> V_49 -> V_50 ,
V_10 -> V_19 -> V_53 ) ;
F_9 ( L_11
L_12 , V_8 -> V_49 -> V_50 ,
V_8 -> V_51 -> V_52 ,
V_13 -> V_20 -> V_53 ) ;
V_55 = V_21 ;
goto V_45;
}
V_10 -> V_19 = V_13 -> V_20 ;
V_10 -> V_22 |= V_46 ;
if ( V_13 -> V_25 != 0 ) {
V_10 -> V_24 = V_13 -> V_25 ;
V_10 -> V_22 |= V_23 ;
}
F_11 ( L_13
L_14 , V_40 -> V_47 -> V_48 () ,
V_8 -> V_49 -> V_50 , V_8 -> V_51 -> V_52 ,
V_13 -> V_20 -> V_53 ) ;
V_45:
F_8 ( & V_10 -> V_44 ) ;
V_43:
if ( ! V_55 )
F_12 ( V_8 , V_54 ) ;
return V_55 ;
}
static int F_14 (
struct V_7 * V_8 ,
T_1 V_57 )
{
unsigned char * V_58 = V_8 -> V_15 ;
struct V_59 * V_51 ;
struct V_12 * V_14 = V_8 -> V_14 ;
int V_60 = 0 , V_61 ;
int V_62 = 0 , V_55 = 1 ;
int V_63 = 0 , V_64 = 0 ;
int V_65 = 0 ;
int V_66 = 0 ;
V_51 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
V_61 = ( V_57 & 0x80000000 ) ;
if ( V_61 )
V_57 &= ~ 0x80000000 ;
switch ( V_57 ) {
case V_69 :
V_65 = 1 ;
case V_70 :
if ( ( V_51 -> V_71 ) && ! ( V_61 ) )
V_62 = 1 ;
break;
case V_32 :
V_65 = 1 ;
case V_33 :
V_64 = 1 ;
if ( ( V_51 -> V_71 ) && ! ( V_61 ) )
V_62 = 1 ;
break;
case V_34 :
V_65 = 1 ;
case V_35 :
V_63 = 1 ;
if ( ( V_51 -> V_71 ) && ! ( V_61 ) )
V_62 = 1 ;
break;
default:
return - V_72 ;
}
switch ( V_58 [ 0 ] ) {
case V_73 :
if ( V_62 )
return 0 ;
V_55 = ( V_65 ) ? 0 : 1 ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
if ( V_66 ) {
V_55 = 1 ;
break;
}
if ( V_62 ) {
V_55 = 0 ;
break;
}
V_55 = ( V_65 ) ? 0 : 1 ;
break;
case V_79 :
switch ( V_58 [ 1 ] & 0x1f ) {
case V_80 :
case V_81 :
case V_82 :
V_55 = ( V_62 ) ? 0 : 1 ;
break;
case V_83 :
case V_84 :
V_55 = 0 ;
break;
case V_85 :
case V_86 :
V_55 = 1 ;
break;
case V_87 :
V_55 = ( V_62 ) ? 0 : 1 ;
break;
default:
F_9 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return - V_72 ;
}
break;
case V_17 :
case V_18 :
V_55 = 0 ;
break;
case V_88 :
case V_89 :
V_55 = 0 ;
break;
case V_90 :
V_55 = ( V_66 ) ? 1 : 0 ;
break;
case V_91 :
switch ( V_58 [ 1 ] & 0x1f ) {
case V_92 :
if ( V_62 ) {
V_55 = 0 ;
break;
}
V_55 = ( V_65 ) ? 0 : 1 ;
break;
case V_93 :
case V_94 :
if ( V_66 ) {
V_55 = 1 ;
break;
}
if ( V_62 ) {
V_55 = 0 ;
break;
}
V_55 = ( V_65 ) ? 0 : 1 ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_55 = 0 ;
break;
default:
F_9 ( L_17 ,
( V_58 [ 1 ] & 0x1f ) ) ;
return - V_72 ;
}
break;
case V_100 :
case V_101 :
case V_16 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_55 = 0 ;
break;
default:
V_60 = 1 ;
break;
}
if ( ! V_55 && ! V_60 ) {
F_11 ( L_18
L_19 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
return V_55 ;
}
if ( V_65 && ! V_62 ) {
if ( V_8 -> V_107 == V_108 ) {
F_11 ( L_20
L_21 ,
F_16 ( V_8 ) ,
V_14 -> V_20 -> V_53 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
return 1 ;
} else {
if ( ! V_62 ) {
F_11 ( L_22
L_23
L_24 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
}
return 0 ;
}
} else if ( ( V_64 ) || ( V_63 ) ) {
if ( V_62 ) {
F_11 ( L_25
L_26 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
return 0 ;
}
} else if ( V_65 && V_62 ) {
if ( V_8 -> V_107 == V_109 ) {
F_11 ( L_27
L_26 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
return 0 ;
}
}
F_11 ( L_28
L_29 , F_16 ( V_8 ) ,
( V_62 ) ? L_30 : L_31 ,
V_14 -> V_20 -> V_53 , V_58 [ 0 ] ,
F_15 ( V_57 ) ) ;
return 1 ;
}
static T_2
F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_8 -> V_14 ;
T_1 V_57 ;
if ( ! V_10 -> V_110 )
return 0 ;
V_57 = V_10 -> V_110 -> V_31 ;
V_8 -> V_111 = V_10 -> V_110 -> V_111 ;
if ( V_10 -> V_110 -> V_112 != V_13 -> V_20 )
goto V_113;
if ( V_10 -> V_110 -> V_5 ) {
if ( V_10 -> V_110 -> V_114 !=
V_13 -> V_25 ) {
V_57 |= 0x80000000 ;
goto V_113;
}
}
return 0 ;
V_113:
if ( F_14 ( V_8 , V_57 ) )
return V_21 ;
return 0 ;
}
static T_1 F_18 ( struct V_9 * V_10 )
{
T_1 V_115 ;
F_6 ( & V_10 -> V_44 ) ;
V_115 = V_10 -> V_28 . V_116 ++ ;
F_8 ( & V_10 -> V_44 ) ;
return V_115 ;
}
static struct V_1 * F_19 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_59 * V_118 ,
unsigned char * V_119 ,
T_3 V_120 ,
int V_121 ,
int V_122 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_123 , V_124 ) ;
if ( ! V_2 ) {
F_9 ( L_32 ) ;
return NULL ;
}
F_21 ( & V_2 -> V_125 ) ;
F_21 ( & V_2 -> V_126 ) ;
F_21 ( & V_2 -> V_127 ) ;
F_21 ( & V_2 -> V_128 ) ;
F_21 ( & V_2 -> V_129 ) ;
F_22 ( & V_2 -> V_130 , 0 ) ;
V_2 -> V_112 = V_117 ;
V_2 -> V_131 = V_118 ;
V_2 -> V_132 = V_118 -> V_52 ;
V_2 -> V_133 = V_118 -> V_49 -> V_50 ;
V_2 -> V_111 = V_120 ;
V_2 -> V_134 = V_121 ;
V_2 -> V_135 = V_122 ;
V_2 -> V_136 = V_118 -> V_49 ;
if ( V_119 != NULL ) {
V_2 -> V_114 = F_23 ( V_119 ) ;
snprintf ( V_2 -> V_6 , V_137 , L_33 , V_119 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_24 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_59 * V_118 ,
unsigned char * V_119 ,
T_3 V_120 ,
int V_121 ,
int V_122 )
{
struct V_59 * V_138 ;
struct V_20 * V_139 ;
struct V_140 * V_141 , * V_142 ;
struct V_143 * V_144 = V_117 -> V_42 -> V_47 ;
struct V_1 * V_2 , * V_145 , * V_146 , * V_147 ;
int V_55 ;
V_2 = F_19 ( V_10 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_121 )
return V_2 ;
F_6 ( & V_10 -> V_148 ) ;
F_25 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_26 ( & V_141 -> V_149 ) ;
F_8 ( & V_10 -> V_148 ) ;
F_27 ( & V_141 -> V_150 ) ;
F_28 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_138 -> V_151 )
continue;
V_139 = V_138 -> V_151 -> V_152 ;
if ( V_117 == V_139 )
continue;
if ( V_144 != V_139 -> V_42 -> V_47 )
continue;
if ( strcmp ( V_117 -> V_53 , V_139 -> V_53 ) )
continue;
F_26 ( & V_138 -> V_153 ) ;
F_29 ( & V_141 -> V_150 ) ;
V_55 = F_30 ( V_138 ) ;
if ( V_55 < 0 ) {
F_9 ( L_34
L_35 ) ;
F_31 ( & V_141 -> V_149 ) ;
F_31 ( & V_138 -> V_153 ) ;
goto V_43;
}
V_145 = F_19 ( V_10 ,
V_139 , V_138 , NULL ,
V_120 , V_121 , V_122 ) ;
if ( ! V_145 ) {
F_31 ( & V_141 -> V_149 ) ;
F_31 ( & V_138 -> V_153 ) ;
F_32 ( V_138 ) ;
goto V_43;
}
F_33 ( & V_145 -> V_129 ,
& V_2 -> V_128 ) ;
F_27 ( & V_141 -> V_150 ) ;
}
F_29 ( & V_141 -> V_150 ) ;
F_6 ( & V_10 -> V_148 ) ;
F_31 ( & V_141 -> V_149 ) ;
}
F_8 ( & V_10 -> V_148 ) ;
return V_2 ;
V_43:
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_34 ( & V_146 -> V_129 ) ;
F_32 ( V_146 -> V_131 ) ;
F_35 ( V_123 , V_146 ) ;
}
F_35 ( V_123 , V_2 ) ;
return NULL ;
}
int F_36 (
struct V_26 * V_27 ,
T_3 V_120 ,
unsigned char * V_154 ,
unsigned char * V_119 ,
T_1 V_52 ,
unsigned char * V_155 ,
T_4 V_156 ,
T_1 V_157 ,
int V_158 ,
int V_121 ,
T_5 type )
{
struct V_1 * V_2 ;
if ( ! V_154 || ! V_155 || ! V_120 ) {
F_9 ( L_36 ) ;
return - V_72 ;
}
V_2 = F_20 ( V_123 , V_159 ) ;
if ( ! V_2 ) {
F_9 ( L_32 ) ;
return - V_160 ;
}
F_21 ( & V_2 -> V_125 ) ;
F_21 ( & V_2 -> V_126 ) ;
F_21 ( & V_2 -> V_127 ) ;
F_21 ( & V_2 -> V_128 ) ;
F_21 ( & V_2 -> V_129 ) ;
F_22 ( & V_2 -> V_130 , 0 ) ;
V_2 -> V_112 = NULL ;
V_2 -> V_131 = NULL ;
V_2 -> V_132 = V_52 ;
V_2 -> V_133 = V_157 ;
V_2 -> V_111 = V_120 ;
V_2 -> V_134 = V_121 ;
V_2 -> V_135 = 1 ;
V_2 -> V_136 = NULL ;
V_2 -> V_161 = 0 ;
V_2 -> V_31 = type ;
if ( V_119 != NULL ) {
V_2 -> V_114 = F_23 ( V_119 ) ;
snprintf ( V_2 -> V_6 , V_137 , L_33 , V_119 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_162 , V_163 , L_33 , V_154 ) ;
snprintf ( V_2 -> V_164 , V_165 , L_33 , V_155 ) ;
V_2 -> V_166 = V_156 ;
V_2 -> V_30 = V_158 ;
F_33 ( & V_2 -> V_127 , & V_27 -> V_167 ) ;
F_11 ( L_37
L_38 , ( V_158 ) ? L_39 : L_30 ) ;
return 0 ;
}
static void F_37 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_20 * V_168 ,
struct V_1 * V_2 )
{
char V_169 [ V_170 ] ;
memset ( V_169 , 0 , V_170 ) ;
F_1 ( V_2 , V_169 , V_170 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_10 -> V_110 = V_2 ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_40
L_41 ,
V_40 -> V_47 -> V_48 () ,
F_15 ( V_2 -> V_31 ) ,
( V_2 -> V_134 ) ? 1 : 0 ) ;
F_11 ( L_42 ,
V_40 -> V_47 -> V_48 () , V_168 -> V_53 ,
V_169 ) ;
}
static int F_38 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_171 ,
T_1 V_157 ,
struct V_20 * V_117 ,
struct V_59 * V_118 )
{
struct V_1 * V_2 , * V_146 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char V_154 [ V_163 ] ;
unsigned char V_155 [ V_165 ] ;
T_4 V_156 ;
memset ( V_154 , 0 , V_163 ) ;
memset ( V_155 , 0 , V_165 ) ;
snprintf ( V_154 , V_163 , L_33 , V_117 -> V_53 ) ;
snprintf ( V_155 , V_165 , L_33 ,
V_40 -> V_47 -> V_172 ( V_40 ) ) ;
V_156 = V_40 -> V_47 -> V_173 ( V_40 ) ;
F_6 ( & V_27 -> V_174 ) ;
F_25 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_162 , V_154 ) &&
( V_2 -> V_132 == V_118 -> V_52 ) &&
! ( strcmp ( V_2 -> V_164 , V_155 ) ) &&
( V_2 -> V_166 == V_156 ) &&
( V_2 -> V_133 == V_157 ) ) {
V_2 -> V_112 = V_117 ;
V_2 -> V_131 = V_118 ;
V_2 -> V_136 = V_171 ;
F_34 ( & V_2 -> V_127 ) ;
F_8 ( & V_27 -> V_174 ) ;
F_39 ( V_10 , V_117 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_37 ( V_10 , V_40 ,
V_117 , V_2 ) ;
F_6 ( & V_27 -> V_174 ) ;
V_27 -> V_175 = 1 ;
}
}
F_8 ( & V_27 -> V_174 ) ;
return 0 ;
}
int F_40 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_171 ,
struct V_20 * V_117 ,
T_1 V_52 )
{
struct V_59 * V_118 = V_117 -> V_67 [ V_52 ] ;
if ( V_10 -> V_22 & V_46 )
return 0 ;
return F_38 ( V_10 , V_40 , V_171 ,
V_171 -> V_50 , V_117 , V_118 ) ;
}
static void F_41 (
struct V_143 * V_144 ,
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_1 * V_2 ,
enum V_176 V_176 )
{
struct V_39 * V_42 = V_117 -> V_42 ;
char V_169 [ V_170 ] ;
memset ( & V_169 [ 0 ] , 0 , V_170 ) ;
F_1 ( V_2 , V_169 , V_170 ) ;
F_11 ( L_43
L_44 , V_144 -> V_48 () , ( V_176 == V_177 ) ?
L_45 : ( V_176 == V_178 ) ?
L_46 : L_30 , V_117 -> V_53 ,
V_169 ) ;
F_11 ( L_47 ,
V_144 -> V_48 () , V_144 -> V_172 ( V_42 ) ,
V_144 -> V_173 ( V_42 ) ) ;
F_11 ( L_48
L_49 , V_144 -> V_48 () ,
( V_2 -> V_134 ) ? L_50 : L_51 ,
V_10 -> V_179 -> V_180 ) ;
F_11 ( L_52
L_53 , V_144 -> V_48 () ,
V_2 -> V_111 , V_2 -> V_181 ,
V_2 -> V_135 ) ;
}
static void F_39 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_1 * V_2 ,
enum V_176 V_176 ,
int V_182 )
{
struct V_143 * V_144 = V_117 -> V_42 -> V_47 ;
struct V_1 * V_146 , * V_147 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
V_2 -> V_181 = ( V_182 ) ?
V_10 -> V_28 . V_116 ++ :
F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_33 ( & V_2 -> V_125 , & V_27 -> V_37 ) ;
V_2 -> V_131 -> V_71 = 1 ;
F_41 ( V_144 , V_10 , V_117 , V_2 , V_176 ) ;
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_2 -> V_134 || V_182 )
return;
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_34 ( & V_146 -> V_129 ) ;
V_146 -> V_181 = F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_33 ( & V_146 -> V_125 ,
& V_27 -> V_37 ) ;
V_146 -> V_131 -> V_71 = 1 ;
F_41 ( V_144 , V_10 ,
V_146 -> V_112 , V_146 ,
V_176 ) ;
F_8 ( & V_27 -> V_36 ) ;
F_32 ( V_146 -> V_131 ) ;
}
}
static int F_42 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_59 * V_118 ,
unsigned char * V_119 ,
T_3 V_120 ,
int V_121 ,
int V_122 ,
enum V_176 V_176 ,
int V_182 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_10 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_2 )
return - V_183 ;
F_39 ( V_10 , V_117 , V_2 ,
V_176 , V_182 ) ;
return 0 ;
}
static struct V_1 * F_43 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
unsigned char * V_119 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_146 ;
struct V_39 * V_40 ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_112 != V_117 )
continue;
V_40 = V_2 -> V_112 -> V_42 ;
if ( ! V_2 -> V_5 ) {
if ( V_40 -> V_47 -> V_184 != NULL ) {
if ( V_10 -> V_185 . V_186 )
continue;
}
F_26 ( & V_2 -> V_130 ) ;
F_8 ( & V_27 -> V_36 ) ;
return V_2 ;
}
if ( ! V_119 )
continue;
if ( strcmp ( V_119 , V_2 -> V_6 ) )
continue;
F_26 ( & V_2 -> V_130 ) ;
F_8 ( & V_27 -> V_36 ) ;
return V_2 ;
}
F_8 ( & V_27 -> V_36 ) ;
return NULL ;
}
static struct V_1 * F_4 (
struct V_9 * V_10 ,
struct V_20 * V_117 ,
struct V_12 * V_13 )
{
struct V_39 * V_40 = V_117 -> V_42 ;
unsigned char V_3 [ V_137 ] , * V_187 = NULL ;
if ( V_40 -> V_47 -> V_184 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_137 ) ;
V_40 -> V_47 -> V_184 ( V_13 , & V_3 [ 0 ] ,
V_137 ) ;
V_187 = & V_3 [ 0 ] ;
}
return F_43 ( V_10 , V_117 , V_187 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_130 ) ;
}
static int F_44 (
struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_20 * V_117 = V_2 -> V_112 ;
struct V_1 * V_30 ;
int V_55 = 0 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( ! V_30 ) {
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
if ( V_30 == V_2 ) {
F_45 ( V_10 , V_117 , V_2 , 0 , 1 ) ;
V_55 = 1 ;
} else if ( V_2 -> V_134 &&
( ! strcmp ( V_30 -> V_112 -> V_53 ,
V_2 -> V_112 -> V_53 ) ) &&
( V_30 -> V_111 == V_2 -> V_111 ) ) {
F_9 ( L_54
L_55
L_56
L_57 , V_2 -> V_111 ) ;
V_55 = - V_183 ;
}
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static void F_46 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_188 * V_189 ,
int V_190 )
{
struct V_143 * V_144 =
V_2 -> V_112 -> V_42 -> V_47 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_169 [ V_170 ] ;
memset ( V_169 , 0 , V_170 ) ;
F_1 ( V_2 , V_169 , V_170 ) ;
V_2 -> V_131 -> V_71 = 0 ;
V_2 -> V_131 -> V_111 = 0 ;
if ( ! F_7 ( & V_2 -> V_125 ) )
F_34 ( & V_2 -> V_125 ) ;
if ( V_190 )
F_5 ( V_2 ) ;
while ( F_47 ( & V_2 -> V_130 ) != 0 ) {
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_58 ,
V_144 -> V_48 () ) ;
F_48 () ;
F_6 ( & V_27 -> V_36 ) ;
}
F_11 ( L_59
L_44 , V_144 -> V_48 () ,
V_2 -> V_112 -> V_53 ,
V_169 ) ;
F_11 ( L_48
L_49 , V_144 -> V_48 () ,
( V_2 -> V_134 ) ? L_50 : L_51 ,
V_10 -> V_179 -> V_180 ) ;
F_11 ( L_52
L_60 , V_144 -> V_48 () , V_2 -> V_111 ,
V_2 -> V_181 ) ;
if ( ! V_189 ) {
V_2 -> V_131 = NULL ;
V_2 -> V_112 = NULL ;
F_35 ( V_123 , V_2 ) ;
return;
}
F_33 ( & V_2 -> V_126 , V_189 ) ;
}
void F_49 (
struct V_9 * V_10 ,
struct V_20 * V_117 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_146 , * V_30 ;
bool V_191 = false ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( ( V_30 != NULL ) &&
( V_30 -> V_112 == V_117 ) ) {
F_45 ( V_10 , V_117 , V_30 , 0 , 1 ) ;
V_191 = true ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
if ( V_30 && V_191 )
F_46 ( V_10 , V_30 , NULL , 0 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_112 != V_117 )
continue;
F_46 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
void F_50 (
struct V_9 * V_10 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_146 , * V_30 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( V_30 != NULL ) {
struct V_20 * V_192 = V_30 -> V_112 ;
F_45 ( V_10 , V_192 ,
V_30 , 0 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_46 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_6 ( & V_27 -> V_174 ) ;
F_25 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_34 ( & V_2 -> V_127 ) ;
F_35 ( V_123 , V_2 ) ;
}
F_8 ( & V_27 -> V_174 ) ;
}
static int F_51 ( struct V_39 * V_40 )
{
return F_52 ( V_40 -> V_47 -> V_193 ,
& V_40 -> V_194 . V_195 ) ;
}
static void F_53 ( struct V_39 * V_40 )
{
F_54 ( V_40 -> V_47 -> V_193 ,
& V_40 -> V_194 . V_195 ) ;
F_31 ( & V_40 -> V_196 ) ;
}
static int F_55 ( struct V_20 * V_117 )
{
struct V_39 * V_40 = V_117 -> V_42 ;
if ( V_117 -> V_197 )
return 0 ;
return F_52 ( V_40 -> V_47 -> V_193 ,
& V_117 -> V_198 . V_195 ) ;
}
static void F_56 ( struct V_20 * V_117 )
{
struct V_39 * V_40 = V_117 -> V_42 ;
if ( V_117 -> V_197 ) {
F_31 ( & V_117 -> V_199 ) ;
return;
}
F_54 ( V_40 -> V_47 -> V_193 ,
& V_117 -> V_198 . V_195 ) ;
F_31 ( & V_117 -> V_199 ) ;
}
static int F_30 ( struct V_59 * V_51 )
{
struct V_151 * V_200 = V_51 -> V_151 ;
struct V_20 * V_117 ;
struct V_39 * V_40 ;
if ( ! V_200 )
return 0 ;
V_117 = V_200 -> V_152 ;
V_40 = V_117 -> V_42 ;
return F_52 ( V_40 -> V_47 -> V_193 ,
& V_200 -> V_201 . V_195 ) ;
}
static void F_32 ( struct V_59 * V_51 )
{
struct V_151 * V_200 = V_51 -> V_151 ;
struct V_20 * V_117 ;
struct V_39 * V_40 ;
if ( ! V_200 ) {
F_31 ( & V_51 -> V_153 ) ;
return;
}
V_117 = V_200 -> V_152 ;
V_40 = V_117 -> V_42 ;
F_54 ( V_40 -> V_47 -> V_193 ,
& V_200 -> V_201 . V_195 ) ;
F_31 ( & V_51 -> V_153 ) ;
}
static T_2
F_57 (
struct V_7 * V_8 ,
struct V_39 * V_40 ,
unsigned char * V_202 ,
T_3 V_120 ,
int V_121 ,
int V_122 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_140 * V_203 ;
struct V_39 * V_204 = NULL , * V_205 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_20 * V_206 = NULL ;
struct V_59 * V_207 = NULL , * V_208 ;
struct V_1 * V_209 , * V_210 , * V_211 ;
struct V_1 * V_146 , * V_147 ;
F_58 ( V_212 ) ;
struct V_213 * V_214 , * V_215 , * V_216 ;
struct V_143 * V_217 ;
unsigned char * V_3 ;
unsigned char * V_218 , * V_219 = NULL , V_220 , V_221 ;
char * V_222 = NULL , V_169 [ V_170 ] ;
T_2 V_55 ;
T_1 V_223 , V_224 = 0 ;
int V_225 ;
T_1 V_226 = 0 ;
V_208 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
V_214 = F_59 ( sizeof( struct V_213 ) , V_159 ) ;
if ( ! V_214 ) {
F_9 ( L_61 ) ;
return V_227 ;
}
F_21 ( & V_214 -> V_228 ) ;
V_214 -> V_204 = V_40 ;
V_214 -> V_206 = V_14 -> V_20 ;
V_214 -> V_207 = V_208 ;
V_210 = F_24 ( V_8 -> V_11 ,
V_14 -> V_20 , V_208 , V_202 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_210 ) {
F_60 ( V_214 ) ;
return V_227 ;
}
V_214 -> V_209 = V_210 ;
V_214 -> V_225 = 1 ;
F_33 ( & V_214 -> V_228 , & V_212 ) ;
if ( V_8 -> V_229 < 28 ) {
F_61 ( L_62
L_63 , V_8 -> V_229 ) ;
V_55 = V_230 ;
goto V_43;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_227 ;
goto V_43;
}
V_223 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_223 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_223 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_223 |= V_3 [ 27 ] & 0xff ;
if ( ( V_223 + 28 ) != V_8 -> V_229 ) {
F_9 ( L_64
L_65 , V_223 ,
V_8 -> V_229 ) ;
V_55 = V_230 ;
goto V_231;
}
V_218 = & V_3 [ 28 ] ;
while ( V_223 > 0 ) {
V_220 = ( V_218 [ 0 ] & 0x0f ) ;
V_204 = NULL ;
F_6 ( & V_10 -> V_148 ) ;
F_28 (tmp_port, &dev->dev_sep_list, sep_list) {
V_205 = V_203 -> V_232 ;
if ( ! V_205 )
continue;
V_217 = V_205 -> V_47 ;
if ( ! V_217 )
continue;
if ( ! V_217 -> V_233 ||
! V_217 -> V_234 )
continue;
V_221 = V_217 -> V_233 ( V_205 ) ;
if ( V_221 != V_220 )
continue;
V_226 = V_203 -> V_235 ;
V_219 = V_217 -> V_234 (
V_205 , ( const char * ) V_218 , & V_224 ,
& V_222 ) ;
if ( ! V_219 )
continue;
F_26 ( & V_205 -> V_196 ) ;
F_8 ( & V_10 -> V_148 ) ;
if ( F_51 ( V_205 ) ) {
F_9 ( L_66
L_67 ) ;
F_31 ( & V_205 -> V_196 ) ;
V_55 = V_227 ;
goto V_231;
}
F_63 ( & V_205 -> V_236 ) ;
V_206 = F_64 (
V_205 , V_219 ) ;
if ( V_206 )
F_26 ( & V_206 -> V_199 ) ;
F_65 ( & V_205 -> V_236 ) ;
if ( ! V_206 ) {
F_53 ( V_205 ) ;
F_6 ( & V_10 -> V_148 ) ;
continue;
}
if ( F_55 ( V_206 ) ) {
F_9 ( L_68
L_69 ) ;
F_31 ( & V_206 -> V_199 ) ;
F_53 ( V_205 ) ;
V_55 = V_227 ;
goto V_231;
}
V_204 = V_205 ;
F_11 ( L_70
L_71 ,
V_204 -> V_47 -> V_48 () ,
V_206 -> V_53 , V_226 ) ;
F_6 ( & V_10 -> V_148 ) ;
break;
}
F_8 ( & V_10 -> V_148 ) ;
if ( ! V_204 ) {
F_9 ( L_72
L_73 ) ;
V_55 = V_230 ;
goto V_231;
}
F_11 ( L_74
L_75 ,
V_204 -> V_47 -> V_48 () , V_8 -> V_229 ,
V_223 , V_224 , V_219 , V_222 ) ;
if ( V_224 > V_223 ) {
F_9 ( L_76
L_77 , V_224 , V_218 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
V_55 = V_230 ;
goto V_231;
}
V_207 = F_66 ( V_206 ,
V_226 ) ;
if ( ! V_207 ) {
F_9 ( L_78
L_79 ,
V_204 -> V_47 -> V_48 () ,
V_226 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
V_55 = V_230 ;
goto V_231;
}
if ( F_30 ( V_207 ) ) {
F_9 ( L_80
L_81 ) ;
F_31 ( & V_207 -> V_153 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
V_55 = V_227 ;
goto V_231;
}
F_11 ( L_82
L_83 ,
V_204 -> V_47 -> V_48 () ,
V_206 -> V_53 , V_207 -> V_52 ) ;
V_211 = F_43 ( V_10 , V_206 ,
V_222 ) ;
if ( V_211 ) {
F_5 ( V_211 ) ;
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
V_218 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
continue;
}
V_214 = F_59 ( sizeof( struct V_213 ) ,
V_159 ) ;
if ( ! V_214 ) {
F_9 ( L_61 ) ;
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
V_55 = V_227 ;
goto V_231;
}
F_21 ( & V_214 -> V_228 ) ;
V_214 -> V_204 = V_204 ;
V_214 -> V_206 = V_206 ;
V_214 -> V_207 = V_207 ;
V_209 = F_24 ( V_8 -> V_11 ,
V_206 , V_207 , V_222 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_209 ) {
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
F_60 ( V_214 ) ;
V_55 = V_230 ;
goto V_231;
}
V_214 -> V_209 = V_209 ;
F_33 ( & V_214 -> V_228 , & V_212 ) ;
V_218 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
}
F_67 ( V_8 ) ;
F_25 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_204 = V_215 -> V_204 ;
V_206 = V_215 -> V_206 ;
V_207 = V_215 -> V_207 ;
V_209 = V_215 -> V_209 ;
V_225 = V_215 -> V_225 ;
F_34 ( & V_215 -> V_228 ) ;
F_60 ( V_215 ) ;
memset ( V_169 , 0 , V_170 ) ;
F_1 ( V_209 , V_169 , V_170 ) ;
F_39 ( V_8 -> V_11 , V_206 ,
V_209 , 0 , 0 ) ;
F_11 ( L_84
L_85
L_86 , V_204 -> V_47 -> V_48 () ,
V_206 -> V_53 , V_169 , V_207 -> V_52 ) ;
if ( V_225 )
continue;
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
}
return 0 ;
V_231:
F_67 ( V_8 ) ;
V_43:
F_25 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_204 = V_215 -> V_204 ;
V_206 = V_215 -> V_206 ;
V_207 = V_215 -> V_207 ;
V_209 = V_215 -> V_209 ;
V_225 = V_215 -> V_225 ;
F_34 ( & V_215 -> V_228 ) ;
F_60 ( V_215 ) ;
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_34 ( & V_146 -> V_129 ) ;
F_32 ( V_146 -> V_131 ) ;
F_35 ( V_123 , V_146 ) ;
}
F_35 ( V_123 , V_209 ) ;
if ( V_225 )
continue;
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_204 ) ;
}
return V_55 ;
}
static int F_68 (
struct V_9 * V_10 ,
unsigned char * V_3 ,
T_1 V_237 )
{
struct V_49 * V_171 ;
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned char V_238 [ 512 ] , V_239 [ 32 ] ;
T_6 V_240 = 0 ;
int V_241 = 0 ;
int V_55 = 0 ;
F_6 ( & V_10 -> V_44 ) ;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_28 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
V_238 [ 0 ] = '\0' ;
V_239 [ 0 ] = '\0' ;
V_40 = V_2 -> V_112 -> V_42 ;
V_171 = V_2 -> V_136 ;
if ( V_2 -> V_5 )
snprintf ( V_239 , 32 , L_87 ,
V_2 -> V_6 ) ;
if ( V_10 -> V_110 == V_2 ) {
snprintf ( V_238 , 512 , L_88
L_89
L_90
L_91
L_92
L_93
L_94 , V_241 ,
V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_53 , V_239 ,
V_2 -> V_111 , V_2 -> V_31 ,
V_2 -> V_161 , V_2 -> V_134 ,
V_2 -> V_132 ) ;
} else {
snprintf ( V_238 , 512 , L_95
L_96
L_97
L_98 ,
V_241 , V_40 -> V_47 -> V_48 () ,
V_2 -> V_112 -> V_53 , V_239 ,
V_2 -> V_111 , V_2 -> V_134 ,
V_2 -> V_132 ) ;
}
if ( ( V_240 + strlen ( V_238 ) >= V_237 ) ) {
F_9 ( L_99
L_100 ) ;
V_55 = - V_242 ;
goto V_43;
}
V_240 += sprintf ( V_3 + V_240 , L_33 , V_238 ) ;
snprintf ( V_238 , 512 , L_101
L_102
L_103 , V_40 -> V_47 -> V_48 () ,
V_40 -> V_47 -> V_172 ( V_40 ) ,
V_40 -> V_47 -> V_173 ( V_40 ) ,
V_171 -> V_243 -> V_235 , V_171 -> V_50 , V_241 ) ;
if ( ( V_240 + strlen ( V_238 ) >= V_237 ) ) {
F_9 ( L_99
L_100 ) ;
V_55 = - V_242 ;
goto V_43;
}
V_240 += sprintf ( V_3 + V_240 , L_33 , V_238 ) ;
V_241 ++ ;
}
if ( ! V_241 )
V_240 += sprintf ( V_3 + V_240 , L_104 ) ;
V_43:
F_8 ( & V_10 -> V_28 . V_36 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static int F_69 (
struct V_9 * V_10 ,
unsigned char * V_3 )
{
struct V_244 * V_245 = & V_10 -> V_244 ;
struct V_246 * V_246 ;
int V_247 = V_248 | V_249 | V_250 ;
char V_251 [ 512 ] ;
T_1 V_237 ;
int V_55 ;
memset ( V_251 , 0 , 512 ) ;
if ( strlen ( & V_245 -> V_252 [ 0 ] ) >= 512 ) {
F_9 ( L_105
L_106 ) ;
return - V_242 ;
}
snprintf ( V_251 , 512 , L_107 , & V_245 -> V_252 [ 0 ] ) ;
V_246 = F_70 ( V_251 , V_247 , 0600 ) ;
if ( F_71 ( V_246 ) ) {
F_9 ( L_108
L_81 , V_251 ) ;
return F_72 ( V_246 ) ;
}
V_237 = ( strlen ( V_3 ) + 1 ) ;
V_55 = F_73 ( V_246 , V_3 , V_237 , 0 ) ;
if ( V_55 < 0 )
F_11 ( L_109 , V_251 ) ;
F_74 ( V_246 ) ;
return ( V_55 < 0 ) ? - V_253 : 0 ;
}
static T_2 F_75 ( struct V_9 * V_10 , bool V_122 )
{
unsigned char * V_3 ;
int V_41 ;
if ( ! V_122 ) {
char * V_254 = L_110 ;
V_41 = F_69 ( V_10 , V_254 ) ;
V_10 -> V_28 . V_175 = 0 ;
F_11 ( L_111 ) ;
if ( V_41 )
return V_227 ;
return 0 ;
}
V_3 = F_59 ( V_255 , V_159 ) ;
if ( ! V_3 )
return V_256 ;
V_41 = F_68 ( V_10 , V_3 , V_255 ) ;
if ( V_41 < 0 ) {
F_60 ( V_3 ) ;
return V_256 ;
}
V_41 = F_69 ( V_10 , V_3 ) ;
if ( V_41 != 0 ) {
F_9 ( L_112 ) ;
F_60 ( V_3 ) ;
return V_227 ;
}
V_10 -> V_28 . V_175 = 1 ;
F_60 ( V_3 ) ;
F_11 ( L_113 ) ;
return 0 ;
}
static T_2
F_76 ( struct V_7 * V_8 , T_3 V_257 , T_3 V_120 ,
bool V_122 , bool V_121 , bool V_258 , enum V_176 V_176 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_51 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_259 , * V_146 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char V_239 [ V_137 ] , * V_187 = NULL ;
T_2 V_55 = V_260 ;
int V_261 = 0 , type ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_114 ) ;
return V_227 ;
}
V_42 = V_14 -> V_42 ;
V_51 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
if ( V_42 -> V_47 -> V_184 ) {
memset ( & V_239 [ 0 ] , 0 , V_137 ) ;
V_42 -> V_47 -> V_184 ( V_14 , & V_239 [ 0 ] ,
V_137 ) ;
V_187 = & V_239 [ 0 ] ;
}
V_2 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_2 ) {
if ( V_257 ) {
F_61 ( L_115
L_116 ) ;
return V_21 ;
}
if ( ! V_120 )
return 0 ;
if ( ! V_258 ) {
if ( F_42 ( V_8 -> V_11 ,
V_14 -> V_20 , V_51 , V_187 ,
V_120 , V_121 , V_122 ,
V_176 , 0 ) ) {
F_9 ( L_117
L_118 ) ;
return V_230 ;
}
} else {
V_55 = F_57 ( V_8 , V_42 ,
V_187 , V_120 , V_121 , V_122 ) ;
if ( V_55 != 0 )
return V_55 ;
}
return F_75 ( V_10 , V_122 ) ;
}
if ( ( V_176 == REGISTER ) && ( V_257 != V_2 -> V_111 ) ) {
F_9 ( L_119
L_120
L_121
L_122 , V_257 ,
V_2 -> V_111 ) ;
V_55 = V_21 ;
goto V_43;
}
if ( V_258 ) {
F_9 ( L_123
L_124 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( V_2 -> V_134 && ! V_121 ) {
F_9 ( L_125
L_126
L_127 ) ;
V_55 = V_262 ;
goto V_43;
}
if ( V_120 ) {
V_2 -> V_181 = F_18 ( V_8 -> V_11 ) ;
V_2 -> V_111 = V_120 ;
F_11 ( L_128
L_129
L_60 , V_8 -> V_263 -> V_48 () ,
( V_176 == V_178 ) ? L_46 : L_30 ,
V_2 -> V_112 -> V_53 ,
V_2 -> V_111 , V_2 -> V_181 ) ;
} else {
type = V_2 -> V_31 ;
V_261 = F_44 ( V_8 -> V_11 ,
V_2 ) ;
if ( V_261 < 0 ) {
V_55 = V_21 ;
goto V_43;
}
F_6 ( & V_27 -> V_36 ) ;
if ( V_2 -> V_134 ) {
F_25 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_259 -> V_134 )
continue;
if ( V_259 -> V_111 != V_257 )
continue;
if ( V_2 == V_259 )
continue;
if ( strcmp ( V_2 -> V_112 -> V_53 ,
V_259 -> V_112 -> V_53 ) )
continue;
F_46 ( V_10 ,
V_259 , NULL , 0 ) ;
}
}
F_46 ( V_8 -> V_11 , V_2 , NULL , 1 ) ;
V_2 = NULL ;
if ( V_261 &&
( type == V_32 ||
type == V_33 ) ) {
F_28 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_77 (
V_259 -> V_112 ,
V_259 -> V_132 ,
0x2A ,
V_264 ) ;
}
}
F_8 ( & V_27 -> V_36 ) ;
}
V_55 = F_75 ( V_10 , V_122 ) ;
V_43:
if ( V_2 )
F_5 ( V_2 ) ;
return V_55 ;
}
unsigned char * F_15 ( int type )
{
switch ( type ) {
case V_69 :
return L_130 ;
case V_70 :
return L_131 ;
case V_32 :
return L_132 ;
case V_33 :
return L_133 ;
case V_34 :
return L_134 ;
case V_35 :
return L_135 ;
default:
break;
}
return L_136 ;
}
static T_2
F_78 ( struct V_7 * V_8 , int type , int V_265 , T_3 V_257 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_169 [ V_170 ] ;
T_2 V_55 ;
memset ( V_169 , 0 , V_170 ) ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_114 ) ;
return V_227 ;
}
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_137
L_138 ) ;
return V_227 ;
}
if ( V_257 != V_2 -> V_111 ) {
F_9 ( L_139
L_140
L_122 , V_257 , V_2 -> V_111 ) ;
V_55 = V_21 ;
goto V_266;
}
if ( V_265 != V_267 ) {
F_9 ( L_141 , V_265 ) ;
V_55 = V_230 ;
goto V_266;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( V_30 ) {
int V_31 = V_30 -> V_31 ;
if ( ( V_30 != V_2 ) &&
( V_31 != V_34 ) &&
( V_31 != V_35 ) ) {
struct V_20 * V_192 = V_30 -> V_112 ;
F_9 ( L_142
L_143
L_144 ,
V_8 -> V_263 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_112 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_266;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_161 != V_265 ) ) {
struct V_20 * V_192 = V_30 -> V_112 ;
F_9 ( L_142
L_145
L_146
L_4 ,
V_8 -> V_263 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_112 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_266;
}
F_8 ( & V_10 -> V_44 ) ;
V_55 = 0 ;
goto V_266;
}
V_2 -> V_161 = V_265 ;
V_2 -> V_31 = type ;
V_2 -> V_30 = 1 ;
V_10 -> V_110 = V_2 ;
F_1 ( V_2 , V_169 , V_170 ) ;
F_11 ( L_147
L_148 ,
V_8 -> V_263 -> V_48 () , F_15 ( type ) ,
( V_2 -> V_134 ) ? 1 : 0 ) ;
F_11 ( L_42 ,
V_8 -> V_263 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_169 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_175 )
F_75 ( V_8 -> V_11 , true ) ;
V_55 = 0 ;
V_266:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_79 ( struct V_7 * V_8 , int type , int V_265 ,
T_3 V_257 )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_78 ( V_8 , type , V_265 , V_257 ) ;
default:
F_9 ( L_149
L_150 , type ) ;
return V_262 ;
}
}
static void F_45 (
struct V_9 * V_10 ,
struct V_20 * V_268 ,
struct V_1 * V_2 ,
int V_269 ,
int V_270 )
{
struct V_143 * V_144 = V_268 -> V_42 -> V_47 ;
char V_169 [ V_170 ] ;
int V_31 = 0 , V_161 = 0 ;
memset ( V_169 , 0 , V_170 ) ;
F_1 ( V_2 , V_169 , V_170 ) ;
if ( V_10 -> V_110 ) {
V_31 = V_10 -> V_110 -> V_31 ;
V_161 = V_10 -> V_110 -> V_161 ;
V_10 -> V_110 -> V_31 = 0 ;
V_10 -> V_110 -> V_161 = 0 ;
V_10 -> V_110 -> V_30 = 0 ;
V_10 -> V_110 = NULL ;
}
if ( ! V_270 )
goto V_43;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_80 ( & V_2 -> V_125 ) ;
if ( ! F_7 ( & V_10 -> V_28 . V_37 ) &&
( ( V_31 == V_34 ) ||
( V_31 == V_35 ) ) ) {
V_10 -> V_110 =
F_81 ( V_10 -> V_28 . V_37 . V_271 ,
struct V_1 , V_125 ) ;
V_10 -> V_110 -> V_31 = V_31 ;
V_10 -> V_110 -> V_161 = V_161 ;
V_10 -> V_110 -> V_30 = 1 ;
}
F_8 ( & V_10 -> V_28 . V_36 ) ;
V_43:
if ( ! V_10 -> V_110 ) {
F_11 ( L_151
L_148 ,
V_144 -> V_48 () , ( V_269 ) ? L_152 :
L_153 , F_15 ( V_31 ) ,
( V_2 -> V_134 ) ? 1 : 0 ) ;
}
F_11 ( L_154 ,
V_144 -> V_48 () , V_268 -> V_53 ,
V_169 ) ;
V_2 -> V_30 = V_2 -> V_31 = V_2 -> V_161 = 0 ;
}
static T_2
F_82 ( struct V_7 * V_8 , int type , int V_265 ,
T_3 V_257 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_259 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
int V_63 = 0 ;
T_2 V_55 = 0 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_114 ) ;
return V_227 ;
}
V_2 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_137
L_155 ) ;
return V_227 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( ! V_30 ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_266;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) )
V_63 = 1 ;
if ( ( V_63 == 0 ) && ( V_30 != V_2 ) ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_266;
}
if ( V_257 != V_2 -> V_111 ) {
F_9 ( L_156
L_140
L_122 , V_257 , V_2 -> V_111 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_266;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_161 != V_265 ) ) {
struct V_20 * V_192 = V_30 -> V_112 ;
F_9 ( L_157
L_158
L_159
L_144 ,
V_8 -> V_263 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_112 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_266;
}
F_45 ( V_10 , V_14 -> V_20 ,
V_2 , 1 , 0 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( ( type != V_32 ) &&
( type != V_33 ) &&
( type != V_34 ) &&
( type != V_35 ) ) {
goto V_272;
}
F_6 ( & V_27 -> V_36 ) ;
F_28 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_259 == V_2 )
continue;
F_77 ( V_259 -> V_112 ,
V_259 -> V_132 ,
0x2A , V_264 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
V_272:
if ( V_27 -> V_175 )
F_75 ( V_8 -> V_11 , true ) ;
V_266:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_83 ( struct V_7 * V_8 , T_3 V_257 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_112 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_146 , * V_273 , * V_30 ;
T_1 V_132 = 0 ;
int V_274 = 0 ;
V_273 = F_4 ( V_8 -> V_11 ,
V_14 -> V_20 , V_14 ) ;
if ( ! V_273 ) {
F_9 ( L_137
L_160 ) ;
return V_227 ;
}
if ( V_257 != V_273 -> V_111 ) {
F_9 ( L_119
L_120
L_121
L_122 , V_257 , V_273 -> V_111 ) ;
F_5 ( V_273 ) ;
return V_21 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( V_30 ) {
struct V_20 * V_192 = V_30 -> V_112 ;
F_45 ( V_10 , V_192 ,
V_30 , 0 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_274 = ( V_273 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_132 = V_2 -> V_132 ;
F_46 ( V_10 , V_2 , NULL ,
V_274 ) ;
if ( ! V_274 )
F_77 ( V_112 , V_132 ,
0x2A , V_275 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_161 ,
V_8 -> V_263 -> V_48 () ) ;
F_75 ( V_8 -> V_11 , false ) ;
F_18 ( V_10 ) ;
return 0 ;
}
static void F_84 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_188 * V_189 ,
int type ,
int V_265 ,
enum V_276 V_276 )
{
struct V_20 * V_117 = V_2 -> V_112 ;
struct V_143 * V_144 = V_117 -> V_42 -> V_47 ;
char V_169 [ V_170 ] ;
memset ( V_169 , 0 , V_170 ) ;
F_1 ( V_2 , V_169 , V_170 ) ;
if ( V_10 -> V_110 )
F_45 ( V_10 , V_117 ,
V_10 -> V_110 , 0 , 0 ) ;
V_10 -> V_110 = V_2 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = type ;
V_2 -> V_161 = V_265 ;
F_11 ( L_162
L_148 ,
V_144 -> V_48 () , ( V_276 == V_277 ) ? L_163 : L_30 ,
F_15 ( type ) ,
( V_2 -> V_134 ) ? 1 : 0 ) ;
F_11 ( L_164 ,
V_144 -> V_48 () , ( V_276 == V_277 ) ? L_163 : L_30 ,
V_117 -> V_53 , V_169 ) ;
if ( V_189 )
F_33 ( & V_2 -> V_126 ,
V_189 ) ;
}
static void F_85 (
struct V_188 * V_189 ,
struct V_1 * V_278 )
{
struct V_1 * V_2 , * V_146 ;
F_25 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_34 ( & V_2 -> V_126 ) ;
if ( V_278 == V_2 )
continue;
if ( V_2 -> V_30 ) {
F_61 ( L_165 ) ;
continue;
}
V_2 -> V_131 = NULL ;
V_2 -> V_112 = NULL ;
F_35 ( V_123 , V_2 ) ;
}
}
static T_2
F_86 ( struct V_7 * V_8 , int type , int V_265 , T_3 V_257 ,
T_3 V_120 , enum V_276 V_276 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_112 ;
struct V_12 * V_14 = V_8 -> V_14 ;
F_58 ( V_189 ) ;
struct V_1 * V_2 , * V_146 , * V_273 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
T_1 V_132 = 0 ;
int V_63 = 0 , V_274 = 0 ;
bool V_279 = V_120 != 0 ;
int V_280 = 0 , V_281 = 0 ;
if ( ! V_14 )
return V_227 ;
V_273 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_273 ) {
F_9 ( L_137
L_166 ,
( V_276 == V_277 ) ? L_163 : L_30 ) ;
return V_21 ;
}
if ( V_273 -> V_111 != V_257 ) {
F_5 ( V_273 ) ;
return V_21 ;
}
if ( V_265 != V_267 ) {
F_9 ( L_141 , V_265 ) ;
F_5 ( V_273 ) ;
return V_230 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( V_30 &&
( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) )
V_63 = 1 ;
if ( ! V_63 && ! V_120 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_273 ) ;
return V_230 ;
}
if ( ! V_30 || ( V_30 -> V_111 != V_120 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_63 ) {
if ( V_2 -> V_111 != V_120 )
continue;
V_279 = false ;
V_274 = ( V_273 == V_2 ) ? 1 : 0 ;
V_112 = V_2 -> V_112 ;
V_132 = V_2 -> V_132 ;
F_46 ( V_10 , V_2 ,
( V_276 == V_277 ) ? & V_189 :
NULL , V_274 ) ;
} else {
if ( ( V_120 ) &&
( V_2 -> V_111 != V_120 ) )
continue;
V_279 = false ;
V_274 = ( V_273 == V_2 ) ? 1 : 0 ;
if ( V_274 )
continue;
V_112 = V_2 -> V_112 ;
V_132 = V_2 -> V_132 ;
F_46 ( V_10 , V_2 ,
( V_276 == V_277 ) ? & V_189 :
NULL , 0 ) ;
}
if ( ! V_274 )
F_77 ( V_112 ,
V_132 , 0x2A ,
V_282 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
if ( V_279 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_273 ) ;
return V_21 ;
}
if ( V_30 && V_63 && ! ( V_120 ) ) {
F_84 ( V_10 , V_273 ,
( V_276 == V_277 ) ? & V_189 : NULL ,
type , V_265 , V_276 ) ;
if ( V_276 == V_277 )
F_85 (
& V_189 , V_273 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_175 )
F_75 ( V_8 -> V_11 , true ) ;
F_5 ( V_273 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
V_280 = V_30 -> V_31 ;
V_281 = V_30 -> V_161 ;
if ( V_273 != V_30 )
F_45 ( V_10 ,
V_30 -> V_112 ,
V_10 -> V_110 , 0 , 0 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_274 = ( V_273 == V_2 ) ? 1 : 0 ;
if ( V_274 )
continue;
if ( V_2 -> V_111 != V_120 )
continue;
V_112 = V_2 -> V_112 ;
V_132 = V_2 -> V_132 ;
F_46 ( V_10 , V_2 ,
( V_276 == V_277 ) ? & V_189 : NULL ,
V_274 ) ;
F_77 ( V_112 , V_132 , 0x2A ,
V_282 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_84 ( V_10 , V_273 ,
( V_276 == V_277 ) ? & V_189 : NULL ,
type , V_265 , V_276 ) ;
if ( ( V_280 != type ) || ( V_281 != V_265 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_274 = ( V_273 == V_2 ) ? 1 : 0 ;
if ( V_274 )
continue;
F_77 ( V_2 -> V_112 ,
V_2 -> V_132 , 0x2A ,
V_264 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( V_276 == V_277 ) {
F_87 ( V_10 , NULL , & V_189 , V_8 ) ;
F_85 ( & V_189 ,
V_273 ) ;
}
if ( V_27 -> V_175 )
F_75 ( V_8 -> V_11 , true ) ;
F_5 ( V_273 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
static T_2
F_88 ( struct V_7 * V_8 , int type , int V_265 ,
T_3 V_257 , T_3 V_120 , enum V_276 V_276 )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_86 ( V_8 , type , V_265 , V_257 ,
V_120 , V_276 ) ;
default:
F_9 ( L_167
L_168 , ( V_276 == V_277 ) ? L_163 : L_30 , type ) ;
return V_262 ;
}
}
static T_2
F_89 ( struct V_7 * V_8 , T_3 V_257 ,
T_3 V_120 , int V_122 , int V_270 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_207 = NULL ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_20 * V_192 , * V_112 , * V_206 = NULL ;
struct V_140 * V_140 ;
struct V_39 * V_42 , * V_283 = NULL ;
struct V_143 * V_284 = NULL , * V_285 ;
struct V_1 * V_2 , * V_30 , * V_209 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
unsigned char * V_286 ;
char * V_222 = NULL , V_169 [ V_170 ] ;
T_1 V_224 , V_287 ;
int V_288 = 0 , type , V_265 , V_289 ;
T_2 V_55 ;
unsigned short V_290 ;
unsigned char V_220 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_114 ) ;
return V_227 ;
}
memset ( V_169 , 0 , V_170 ) ;
V_42 = V_14 -> V_42 ;
V_285 = V_42 -> V_47 ;
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_169
L_170 ) ;
return V_227 ;
}
if ( V_257 != V_2 -> V_111 ) {
F_61 ( L_171
L_172
L_173 , V_257 , V_2 -> V_111 ) ;
V_55 = V_21 ;
goto V_266;
}
if ( ! V_120 ) {
F_61 ( L_174
L_175 ) ;
V_55 = V_230 ;
goto V_266;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_227 ;
goto V_266;
}
V_290 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_290 |= V_3 [ 19 ] & 0xff ;
V_224 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_224 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_224 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_224 |= V_3 [ 23 ] & 0xff ;
F_67 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_224 + 24 ) != V_8 -> V_229 ) {
F_9 ( L_176
L_65 , V_224 ,
V_8 -> V_229 ) ;
V_55 = V_230 ;
goto V_266;
}
F_6 ( & V_10 -> V_148 ) ;
F_28 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_140 -> V_235 != V_290 )
continue;
V_283 = V_140 -> V_232 ;
if ( ! V_283 )
continue;
V_284 = V_283 -> V_47 ;
if ( ! V_284 )
continue;
F_26 ( & V_283 -> V_196 ) ;
F_8 ( & V_10 -> V_148 ) ;
if ( F_51 ( V_283 ) ) {
F_9 ( L_177
L_178 ) ;
F_31 ( & V_283 -> V_196 ) ;
V_55 = V_227 ;
goto V_266;
}
F_6 ( & V_10 -> V_148 ) ;
break;
}
F_8 ( & V_10 -> V_148 ) ;
if ( ! V_283 || ! V_284 ) {
F_9 ( L_179
L_180
L_181 , V_290 ) ;
V_55 = V_230 ;
goto V_266;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_227 ;
goto V_266;
}
V_220 = ( V_3 [ 24 ] & 0x0f ) ;
F_11 ( L_182
L_150 , V_220 ) ;
if ( V_220 != V_284 -> V_233 ( V_283 ) ) {
F_9 ( L_171
L_183
L_184 , V_220 ,
V_284 -> V_233 ( V_283 ) ,
V_284 -> V_48 () ) ;
V_55 = V_230 ;
goto V_43;
}
if ( V_284 -> V_234 == NULL ) {
F_9 ( L_185
L_186
L_187 ) ;
V_55 = V_227 ;
goto V_43;
}
V_286 = V_284 -> V_234 ( V_283 ,
( const char * ) & V_3 [ 24 ] , & V_287 , & V_222 ) ;
if ( ! V_286 ) {
F_9 ( L_179
L_188 ) ;
V_55 = V_230 ;
goto V_43;
}
F_67 ( V_8 ) ;
V_3 = NULL ;
F_11 ( L_189
L_190 , V_284 -> V_48 () , ( V_222 != NULL ) ?
L_191 : L_192 , V_286 , ( V_222 != NULL ) ?
V_222 : L_30 ) ;
V_112 = V_2 -> V_112 ;
V_289 = ( ! strcmp ( V_286 ,
V_112 -> V_53 ) ) ? 1 : 0 ;
if ( ! V_289 )
goto V_291;
if ( ! V_222 || ! V_2 -> V_5 ) {
F_9 ( L_193
L_194 , V_286 ,
V_112 -> V_53 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( ! strcmp ( V_222 , V_2 -> V_6 ) ) {
F_9 ( L_195
L_196 ,
V_286 , V_222 , V_112 -> V_53 ,
V_2 -> V_6 ) ;
V_55 = V_230 ;
goto V_43;
}
V_291:
F_63 ( & V_283 -> V_236 ) ;
V_206 = F_64 ( V_283 ,
V_286 ) ;
if ( V_206 )
F_26 ( & V_206 -> V_199 ) ;
F_65 ( & V_283 -> V_236 ) ;
if ( ! V_206 ) {
F_9 ( L_197
L_198 , V_284 -> V_48 () ,
V_286 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( F_55 ( V_206 ) ) {
F_9 ( L_199
L_200 ) ;
F_31 ( & V_206 -> V_199 ) ;
V_206 = NULL ;
V_55 = V_230 ;
goto V_43;
}
F_11 ( L_201
L_202 , V_284 -> V_48 () ,
V_206 -> V_53 ) ;
V_207 = F_66 ( V_206 , V_290 ) ;
if ( ! V_207 ) {
F_9 ( L_203
L_181 , V_284 -> V_48 () , V_290 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( F_30 ( V_207 ) ) {
F_9 ( L_204 ) ;
F_31 ( & V_207 -> V_153 ) ;
V_207 = NULL ;
V_55 = V_227 ;
goto V_43;
}
F_11 ( L_205
L_206 ,
V_284 -> V_48 () , V_206 -> V_53 ,
V_207 -> V_52 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_110 ;
if ( ! V_30 ) {
F_61 ( L_207
L_208 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_262 ;
goto V_43;
}
if ( V_30 != V_2 ) {
F_61 ( L_209
L_210 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) {
F_61 ( L_211
L_212 ,
F_15 ( V_30 -> V_31 ) ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
V_192 = V_30 -> V_112 ;
type = V_30 -> V_31 ;
V_265 = V_30 -> V_31 ;
V_209 = F_43 ( V_10 , V_206 ,
V_222 ) ;
if ( ! V_209 ) {
if ( F_42 ( V_8 -> V_11 ,
V_206 , V_207 , V_222 ,
V_120 , 0 , V_122 , 2 , 1 ) ) {
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_230 ;
goto V_43;
}
V_209 = F_43 ( V_10 , V_206 ,
V_222 ) ;
V_288 = 1 ;
}
F_45 ( V_10 , V_192 ,
V_10 -> V_110 , 0 , 0 ) ;
V_10 -> V_110 = V_209 ;
V_209 -> V_30 = 1 ;
V_209 -> V_31 = type ;
V_2 -> V_161 = V_265 ;
F_1 ( V_2 , V_169 , V_170 ) ;
if ( ! V_288 )
V_209 -> V_181 = V_27 -> V_116 ++ ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_213
L_214
L_215 , V_284 -> V_48 () ,
F_15 ( type ) , V_290 ,
V_209 -> V_181 ) ;
F_11 ( L_216
L_217 ,
V_285 -> V_48 () , V_112 -> V_53 ,
V_169 , V_284 -> V_48 () ,
V_206 -> V_53 , ( V_222 != NULL ) ?
V_222 : L_30 ) ;
F_32 ( V_207 ) ;
F_56 ( V_206 ) ;
F_53 ( V_283 ) ;
if ( V_270 ) {
F_6 ( & V_27 -> V_36 ) ;
F_46 ( V_10 , V_2 , NULL , 1 ) ;
F_8 ( & V_27 -> V_36 ) ;
} else
F_5 ( V_2 ) ;
F_75 ( V_8 -> V_11 , V_122 ) ;
F_67 ( V_8 ) ;
F_5 ( V_209 ) ;
return 0 ;
V_43:
if ( V_3 )
F_67 ( V_8 ) ;
if ( V_207 )
F_32 ( V_207 ) ;
if ( V_206 )
F_56 ( V_206 ) ;
F_53 ( V_283 ) ;
V_266:
F_5 ( V_2 ) ;
return V_55 ;
}
static unsigned long long F_90 ( unsigned char * V_58 )
{
unsigned int V_292 , V_293 ;
V_292 = ( V_58 [ 0 ] << 24 ) | ( V_58 [ 1 ] << 16 ) | ( V_58 [ 2 ] << 8 ) | V_58 [ 3 ] ;
V_293 = ( V_58 [ 4 ] << 24 ) | ( V_58 [ 5 ] << 16 ) | ( V_58 [ 6 ] << 8 ) | V_58 [ 7 ] ;
return ( ( unsigned long long ) V_293 ) | ( unsigned long long ) V_292 << 32 ;
}
T_2
F_91 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned char * V_58 = & V_8 -> V_15 [ 0 ] ;
unsigned char * V_3 ;
T_3 V_257 , V_120 ;
int V_294 , V_265 , type , V_122 ;
int V_258 = 0 , V_121 = 0 , V_270 = 0 ;
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_218
L_219
L_220 ) ;
return V_21 ;
}
if ( ! V_8 -> V_14 )
return V_227 ;
if ( V_8 -> V_229 < 24 ) {
F_61 ( L_62
L_63 , V_8 -> V_229 ) ;
return V_230 ;
}
V_294 = ( V_58 [ 1 ] & 0x1f ) ;
V_265 = ( V_58 [ 2 ] & 0xf0 ) ;
type = ( V_58 [ 2 ] & 0x0f ) ;
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_257 = F_90 ( & V_3 [ 0 ] ) ;
V_120 = F_90 ( & V_3 [ 8 ] ) ;
if ( V_294 != V_85 ) {
V_258 = ( V_3 [ 20 ] & 0x08 ) ;
V_121 = ( V_3 [ 20 ] & 0x04 ) ;
V_122 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_122 = ( V_3 [ 17 ] & 0x01 ) ;
V_270 = ( V_3 [ 17 ] & 0x02 ) ;
}
if ( V_10 -> V_185 . V_295 )
V_122 = 1 ;
F_67 ( V_8 ) ;
V_3 = NULL ;
if ( V_258 && ( ( V_58 [ 1 ] & 0x1f ) != V_83 ) )
return V_230 ;
if ( ! V_258 && ( ( V_58 [ 1 ] & 0x1f ) != V_85 ) &&
( V_8 -> V_229 != 24 ) ) {
F_61 ( L_221
L_222 , V_8 -> V_229 ) ;
return V_230 ;
}
switch ( V_294 ) {
case V_83 :
V_55 = F_76 ( V_8 ,
V_257 , V_120 , V_122 , V_121 , V_258 , REGISTER ) ;
break;
case V_86 :
V_55 = F_79 ( V_8 , type , V_265 , V_257 ) ;
break;
case V_87 :
V_55 = F_82 ( V_8 , type , V_265 , V_257 ) ;
break;
case V_80 :
V_55 = F_83 ( V_8 , V_257 ) ;
break;
case V_81 :
V_55 = F_88 ( V_8 , type , V_265 ,
V_257 , V_120 , V_296 ) ;
break;
case V_82 :
V_55 = F_88 ( V_8 , type , V_265 ,
V_257 , V_120 , V_277 ) ;
break;
case V_84 :
V_55 = F_76 ( V_8 ,
0 , V_120 , V_122 , V_121 , V_258 , V_178 ) ;
break;
case V_85 :
V_55 = F_89 ( V_8 , V_257 ,
V_120 , V_122 , V_270 ) ;
break;
default:
F_9 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return V_262 ;
}
if ( ! V_55 )
F_12 ( V_8 , V_54 ) ;
return V_55 ;
}
static T_2
F_92 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_297 = 0 , V_298 = 8 ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_223
L_224 , V_8 -> V_229 ) ;
return V_262 ;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_116 & 0xff ) ;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_28 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_297 + 8 ) > ( V_8 -> V_229 - 8 ) )
break;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_297 += 8 ;
}
F_8 ( & V_10 -> V_28 . V_36 ) ;
V_3 [ 4 ] = ( ( V_297 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_297 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_297 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_297 & 0xff ) ;
F_67 ( V_8 ) ;
return 0 ;
}
static T_2
F_93 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_3 V_111 ;
T_1 V_297 = 16 ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_225
L_224 , V_8 -> V_229 ) ;
return V_262 ;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_116 & 0xff ) ;
F_6 ( & V_10 -> V_44 ) ;
V_2 = V_10 -> V_110 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_297 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_297 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_297 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_297 & 0xff ) ;
if ( V_8 -> V_229 < 22 )
goto V_299;
if ( ( V_2 -> V_31 == V_34 ) ||
( V_2 -> V_31 == V_35 ) )
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
V_3 [ 21 ] = ( V_2 -> V_161 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
}
V_299:
F_8 ( & V_10 -> V_44 ) ;
F_67 ( V_8 ) ;
return 0 ;
}
static T_2
F_94 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_4 V_297 = 8 ;
if ( V_8 -> V_229 < 6 ) {
F_9 ( L_226
L_227 , V_8 -> V_229 ) ;
return V_262 ;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_297 >> 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_297 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_27 -> V_175 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
F_67 ( V_8 ) ;
return 0 ;
}
static T_2
F_95 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_268 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_146 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_1 V_300 = 0 , V_297 = 0 , V_301 , V_302 ;
T_1 V_298 = 8 ;
int V_303 = 0 , V_31 = 0 , V_161 = 0 ;
bool V_63 = false ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_228
L_224 , V_8 -> V_229 ) ;
return V_262 ;
}
V_3 = F_62 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_116 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_116 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_116 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_116 & 0xff ) ;
F_6 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_110 ) {
struct V_1 * V_261 = V_10 -> V_110 ;
if ( V_261 -> V_31 == V_34 ||
V_261 -> V_31 == V_35 ) {
V_63 = true ;
V_31 = V_261 -> V_31 ;
V_161 = V_261 -> V_161 ;
}
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_268 = V_2 -> V_112 ;
V_42 = V_2 -> V_112 -> V_42 ;
V_300 = 0 ;
F_26 ( & V_2 -> V_130 ) ;
F_8 ( & V_27 -> V_36 ) ;
V_302 = V_42 -> V_47 -> V_304 (
V_42 , V_268 , V_2 , & V_303 ) ;
if ( ( V_302 + V_297 ) > V_8 -> V_229 ) {
F_61 ( L_229
L_230 , V_8 -> V_229 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_31 ( & V_2 -> V_130 ) ;
break;
}
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 56 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 48 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 40 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 32 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 24 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 16 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_2 -> V_111 >> 8 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( V_2 -> V_111 & 0xff ) ;
V_298 += 4 ;
if ( V_2 -> V_134 )
V_3 [ V_298 ] = 0x02 ;
if ( V_2 -> V_30 ) {
V_3 [ V_298 ++ ] |= 0x01 ;
V_3 [ V_298 ++ ] = ( V_2 -> V_161 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
} else if ( V_63 ) {
V_3 [ V_298 ++ ] |= 0x01 ;
V_3 [ V_298 ++ ] = ( V_161 & 0xf0 ) |
( V_31 & 0x0f ) ;
} else {
V_298 += 2 ;
}
V_298 += 4 ;
if ( ! V_2 -> V_134 ) {
struct V_140 * V_141 = V_2 -> V_136 -> V_243 ;
V_3 [ V_298 ++ ] = ( ( V_141 -> V_235 >> 8 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( V_141 -> V_235 & 0xff ) ;
} else
V_298 += 2 ;
V_301 = V_42 -> V_47 -> V_305 ( V_42 ,
V_268 , V_2 , & V_303 , & V_3 [ V_298 + 4 ] ) ;
F_6 ( & V_27 -> V_36 ) ;
F_31 ( & V_2 -> V_130 ) ;
V_3 [ V_298 ++ ] = ( ( V_301 >> 24 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_301 >> 16 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( ( V_301 >> 8 ) & 0xff ) ;
V_3 [ V_298 ++ ] = ( V_301 & 0xff ) ;
V_300 = ( 24 + V_301 ) ;
V_298 += V_301 ;
V_297 += V_300 ;
}
F_8 ( & V_27 -> V_36 ) ;
V_3 [ 4 ] = ( ( V_297 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_297 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_297 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_297 & 0xff ) ;
F_67 ( V_8 ) ;
return 0 ;
}
T_2
F_96 ( struct V_7 * V_8 )
{
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_218
L_219
L_220 ) ;
return V_21 ;
}
switch ( V_8 -> V_15 [ 1 ] & 0x1f ) {
case V_306 :
V_55 = F_92 ( V_8 ) ;
break;
case V_307 :
V_55 = F_93 ( V_8 ) ;
break;
case V_308 :
V_55 = F_94 ( V_8 ) ;
break;
case V_309 :
V_55 = F_95 ( V_8 ) ;
break;
default:
F_9 ( L_231
L_16 , V_8 -> V_15 [ 1 ] & 0x1f ) ;
return V_262 ;
}
if ( ! V_55 )
F_12 ( V_8 , V_54 ) ;
return V_55 ;
}
T_2
F_97 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
T_2 V_55 ;
if ( ! V_8 -> V_14 )
return 0 ;
if ( V_10 -> V_310 -> V_311 & V_312 )
return 0 ;
if ( V_10 -> V_179 -> V_313 == V_314 )
return 0 ;
F_6 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_22 & V_46 )
V_55 = F_2 ( V_8 ) ;
else
V_55 = F_17 ( V_8 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
