int F_1 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_4 )
{
if ( ! V_2 -> V_5 )
return 0 ;
snprintf ( V_3 , V_4 , L_1 , & V_2 -> V_6 [ 0 ] ) ;
return 1 ;
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
}
F_11 ( L_27
L_28 , F_16 ( V_8 ) ,
( V_62 ) ? L_29 : L_30 ,
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
if ( ! V_10 -> V_109 )
return 0 ;
V_57 = V_10 -> V_109 -> V_31 ;
V_8 -> V_110 = V_10 -> V_109 -> V_110 ;
if ( V_10 -> V_109 -> V_111 != V_13 -> V_20 )
goto V_112;
if ( V_10 -> V_109 -> V_5 ) {
if ( V_10 -> V_109 -> V_113 !=
V_13 -> V_25 ) {
V_57 |= 0x80000000 ;
goto V_112;
}
}
return 0 ;
V_112:
if ( F_14 ( V_8 , V_57 ) )
return V_21 ;
return 0 ;
}
static T_1 F_18 ( struct V_9 * V_10 )
{
T_1 V_114 ;
F_6 ( & V_10 -> V_44 ) ;
V_114 = V_10 -> V_28 . V_115 ++ ;
F_8 ( & V_10 -> V_44 ) ;
return V_114 ;
}
static struct V_1 * F_19 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_59 * V_117 ,
unsigned char * V_118 ,
T_3 V_119 ,
int V_120 ,
int V_121 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_122 , V_123 ) ;
if ( ! V_2 ) {
F_9 ( L_31 ) ;
return NULL ;
}
V_2 -> V_124 = F_21 ( V_10 -> V_28 . V_125 ,
V_123 ) ;
if ( ! V_2 -> V_124 ) {
F_9 ( L_32 ) ;
F_22 ( V_122 , V_2 ) ;
return NULL ;
}
F_23 ( & V_2 -> V_126 ) ;
F_23 ( & V_2 -> V_127 ) ;
F_23 ( & V_2 -> V_128 ) ;
F_23 ( & V_2 -> V_129 ) ;
F_23 ( & V_2 -> V_130 ) ;
F_24 ( & V_2 -> V_131 , 0 ) ;
V_2 -> V_111 = V_116 ;
V_2 -> V_132 = V_117 ;
V_2 -> V_133 = V_117 -> V_52 ;
V_2 -> V_134 = V_117 -> V_49 -> V_50 ;
V_2 -> V_110 = V_119 ;
V_2 -> V_135 = V_120 ;
V_2 -> V_136 = V_121 ;
V_2 -> V_137 = V_117 -> V_49 ;
if ( V_118 != NULL ) {
V_2 -> V_113 = F_25 ( V_118 ) ;
snprintf ( V_2 -> V_6 , V_138 , L_33 , V_118 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_26 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_59 * V_117 ,
unsigned char * V_118 ,
T_3 V_119 ,
int V_120 ,
int V_121 )
{
struct V_59 * V_139 ;
struct V_20 * V_140 ;
struct V_141 * V_142 , * V_143 ;
struct V_144 * V_145 = V_116 -> V_42 -> V_47 ;
struct V_1 * V_2 , * V_146 , * V_147 , * V_148 ;
int V_55 ;
V_2 = F_19 ( V_10 , V_116 , V_117 , V_118 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_120 )
return V_2 ;
F_6 ( & V_10 -> V_149 ) ;
F_27 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_28 ( & V_142 -> V_150 ) ;
F_29 () ;
F_8 ( & V_10 -> V_149 ) ;
F_30 ( & V_142 -> V_151 ) ;
F_31 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_139 -> V_152 )
continue;
V_140 = V_139 -> V_152 -> V_153 ;
if ( V_116 == V_140 )
continue;
if ( V_145 != V_140 -> V_42 -> V_47 )
continue;
if ( strcmp ( V_116 -> V_53 , V_140 -> V_53 ) )
continue;
F_28 ( & V_139 -> V_154 ) ;
F_29 () ;
F_32 ( & V_142 -> V_151 ) ;
V_55 = F_33 ( V_139 ) ;
if ( V_55 < 0 ) {
F_9 ( L_34
L_35 ) ;
F_34 ( & V_142 -> V_150 ) ;
F_35 () ;
F_34 ( & V_139 -> V_154 ) ;
F_35 () ;
goto V_43;
}
V_146 = F_19 ( V_10 ,
V_140 , V_139 , NULL ,
V_119 , V_120 , V_121 ) ;
if ( ! V_146 ) {
F_34 ( & V_142 -> V_150 ) ;
F_35 () ;
F_34 ( & V_139 -> V_154 ) ;
F_35 () ;
F_36 ( V_139 ) ;
goto V_43;
}
F_37 ( & V_146 -> V_130 ,
& V_2 -> V_129 ) ;
F_30 ( & V_142 -> V_151 ) ;
}
F_32 ( & V_142 -> V_151 ) ;
F_6 ( & V_10 -> V_149 ) ;
F_34 ( & V_142 -> V_150 ) ;
F_35 () ;
}
F_8 ( & V_10 -> V_149 ) ;
return V_2 ;
V_43:
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_38 ( & V_147 -> V_130 ) ;
F_36 ( V_147 -> V_132 ) ;
F_22 ( V_122 , V_147 ) ;
}
F_22 ( V_122 , V_2 ) ;
return NULL ;
}
int F_39 (
struct V_26 * V_27 ,
T_3 V_119 ,
unsigned char * V_155 ,
unsigned char * V_118 ,
T_1 V_52 ,
unsigned char * V_156 ,
T_4 V_157 ,
T_1 V_158 ,
int V_159 ,
int V_120 ,
T_5 type )
{
struct V_1 * V_2 ;
if ( ! V_155 || ! V_156 || ! V_119 ) {
F_9 ( L_36 ) ;
return - V_72 ;
}
V_2 = F_20 ( V_122 , V_160 ) ;
if ( ! V_2 ) {
F_9 ( L_31 ) ;
return - V_161 ;
}
V_2 -> V_124 = F_21 ( V_27 -> V_125 , V_160 ) ;
F_23 ( & V_2 -> V_126 ) ;
F_23 ( & V_2 -> V_127 ) ;
F_23 ( & V_2 -> V_128 ) ;
F_23 ( & V_2 -> V_129 ) ;
F_23 ( & V_2 -> V_130 ) ;
F_24 ( & V_2 -> V_131 , 0 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_132 = NULL ;
V_2 -> V_133 = V_52 ;
V_2 -> V_134 = V_158 ;
V_2 -> V_110 = V_119 ;
V_2 -> V_135 = V_120 ;
V_2 -> V_136 = 1 ;
V_2 -> V_137 = NULL ;
V_2 -> V_162 = 0 ;
V_2 -> V_31 = type ;
if ( V_118 != NULL ) {
V_2 -> V_113 = F_25 ( V_118 ) ;
snprintf ( V_2 -> V_6 , V_138 , L_33 , V_118 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_163 , V_164 , L_33 , V_155 ) ;
snprintf ( V_2 -> V_165 , V_166 , L_33 , V_156 ) ;
V_2 -> V_167 = V_157 ;
V_2 -> V_30 = V_159 ;
F_37 ( & V_2 -> V_128 , & V_27 -> V_168 ) ;
F_11 ( L_37
L_38 , ( V_159 ) ? L_39 : L_29 ) ;
return 0 ;
}
static void F_40 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_20 * V_169 ,
struct V_1 * V_2 )
{
char V_170 [ V_171 ] ;
int V_172 ;
memset ( V_170 , 0 , V_171 ) ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_10 -> V_109 = V_2 ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_40
L_41 ,
V_40 -> V_47 -> V_48 () ,
F_15 ( V_2 -> V_31 ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_11 ( L_42 ,
V_40 -> V_47 -> V_48 () , V_169 -> V_53 ,
( V_172 ) ? & V_170 [ 0 ] : L_29 ) ;
}
static int F_41 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_173 ,
T_1 V_158 ,
struct V_20 * V_116 ,
struct V_59 * V_117 )
{
struct V_1 * V_2 , * V_147 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char V_155 [ V_164 ] ;
unsigned char V_156 [ V_166 ] ;
T_4 V_157 ;
memset ( V_155 , 0 , V_164 ) ;
memset ( V_156 , 0 , V_166 ) ;
snprintf ( V_155 , V_164 , L_33 , V_116 -> V_53 ) ;
snprintf ( V_156 , V_166 , L_33 ,
V_40 -> V_47 -> V_174 ( V_40 ) ) ;
V_157 = V_40 -> V_47 -> V_175 ( V_40 ) ;
F_6 ( & V_27 -> V_176 ) ;
F_27 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_163 , V_155 ) &&
( V_2 -> V_133 == V_117 -> V_52 ) &&
! ( strcmp ( V_2 -> V_165 , V_156 ) ) &&
( V_2 -> V_167 == V_157 ) &&
( V_2 -> V_134 == V_158 ) ) {
V_2 -> V_111 = V_116 ;
V_2 -> V_132 = V_117 ;
V_2 -> V_137 = V_173 ;
F_38 ( & V_2 -> V_128 ) ;
F_8 ( & V_27 -> V_176 ) ;
F_42 ( V_10 , V_116 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_40 ( V_10 , V_40 ,
V_116 , V_2 ) ;
F_6 ( & V_27 -> V_176 ) ;
V_27 -> V_177 = 1 ;
}
}
F_8 ( & V_27 -> V_176 ) ;
return 0 ;
}
int F_43 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_173 ,
struct V_152 * V_178 )
{
struct V_20 * V_116 = V_178 -> V_153 ;
struct V_59 * V_117 = V_116 -> V_67 [ V_178 -> V_52 ] ;
if ( V_10 -> V_22 & V_46 )
return 0 ;
return F_41 ( V_10 , V_40 , V_173 ,
V_173 -> V_50 , V_116 , V_117 ) ;
}
static void F_44 (
struct V_144 * V_145 ,
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_1 * V_2 ,
int V_179 )
{
struct V_39 * V_42 = V_116 -> V_42 ;
char V_170 [ V_171 ] ;
int V_172 ;
memset ( & V_170 [ 0 ] , 0 , V_171 ) ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
F_11 ( L_43
L_44 , V_145 -> V_48 () , ( V_179 == 2 ) ?
L_45 : ( V_179 == 1 ) ?
L_46 : L_29 , V_116 -> V_53 ,
( V_172 ) ? V_170 : L_29 ) ;
F_11 ( L_47 ,
V_145 -> V_48 () , V_145 -> V_174 ( V_42 ) ,
V_145 -> V_175 ( V_42 ) ) ;
F_11 ( L_48
L_49 , V_145 -> V_48 () ,
( V_2 -> V_135 ) ? L_50 : L_51 ,
V_10 -> V_180 -> V_181 ) ;
F_11 ( L_52
L_53 , V_145 -> V_48 () ,
V_2 -> V_110 , V_2 -> V_182 ,
V_2 -> V_136 ) ;
}
static void F_42 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_1 * V_2 ,
int V_179 ,
int V_183 )
{
struct V_144 * V_145 = V_116 -> V_42 -> V_47 ;
struct V_1 * V_147 , * V_148 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
V_2 -> V_182 = ( V_183 ) ?
V_10 -> V_28 . V_115 ++ :
F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_37 ( & V_2 -> V_126 , & V_27 -> V_37 ) ;
V_2 -> V_132 -> V_71 = 1 ;
F_44 ( V_145 , V_10 , V_116 , V_2 , V_179 ) ;
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_2 -> V_135 || V_183 )
return;
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_38 ( & V_147 -> V_130 ) ;
V_147 -> V_182 = F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_37 ( & V_147 -> V_126 ,
& V_27 -> V_37 ) ;
V_147 -> V_132 -> V_71 = 1 ;
F_44 ( V_145 , V_10 ,
V_147 -> V_111 , V_147 ,
V_179 ) ;
F_8 ( & V_27 -> V_36 ) ;
F_36 ( V_147 -> V_132 ) ;
}
}
static int F_45 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_59 * V_117 ,
unsigned char * V_118 ,
T_3 V_119 ,
int V_120 ,
int V_121 ,
int V_179 ,
int V_183 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_10 , V_116 , V_117 , V_118 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_2 )
return - V_184 ;
F_42 ( V_10 , V_116 , V_2 ,
V_179 , V_183 ) ;
return 0 ;
}
static struct V_1 * F_46 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
unsigned char * V_118 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_147 ;
struct V_39 * V_40 ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_111 != V_116 )
continue;
V_40 = V_2 -> V_111 -> V_42 ;
if ( ! V_2 -> V_5 ) {
if ( V_40 -> V_47 -> V_185 != NULL ) {
if ( V_10 -> V_186 . V_187 )
continue;
}
F_28 ( & V_2 -> V_131 ) ;
F_29 () ;
F_8 ( & V_27 -> V_36 ) ;
return V_2 ;
}
if ( ! V_118 )
continue;
if ( strcmp ( V_118 , V_2 -> V_6 ) )
continue;
F_28 ( & V_2 -> V_131 ) ;
F_29 () ;
F_8 ( & V_27 -> V_36 ) ;
return V_2 ;
}
F_8 ( & V_27 -> V_36 ) ;
return NULL ;
}
static struct V_1 * F_4 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_12 * V_13 )
{
struct V_39 * V_40 = V_116 -> V_42 ;
unsigned char V_3 [ V_138 ] , * V_188 = NULL ;
if ( V_40 -> V_47 -> V_185 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_138 ) ;
V_40 -> V_47 -> V_185 ( V_13 , & V_3 [ 0 ] ,
V_138 ) ;
V_188 = & V_3 [ 0 ] ;
}
return F_46 ( V_10 , V_116 , V_188 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_131 ) ;
F_35 () ;
}
static int F_47 (
struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_20 * V_116 = V_2 -> V_111 ;
struct V_1 * V_30 ;
int V_55 = 0 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ! V_30 ) {
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
if ( V_30 == V_2 ) {
F_48 ( V_10 , V_116 , V_2 , 0 ) ;
V_55 = 1 ;
} else if ( V_2 -> V_135 &&
( ! strcmp ( V_30 -> V_111 -> V_53 ,
V_2 -> V_111 -> V_53 ) ) &&
( V_30 -> V_110 == V_2 -> V_110 ) ) {
F_9 ( L_54
L_55
L_56
L_57 , V_2 -> V_110 ) ;
V_55 = - V_184 ;
}
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static void F_49 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_189 * V_190 ,
int V_191 )
{
struct V_144 * V_145 =
V_2 -> V_111 -> V_42 -> V_47 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_170 [ V_171 ] ;
int V_172 ;
memset ( V_170 , 0 , V_171 ) ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
V_2 -> V_132 -> V_71 = 0 ;
V_2 -> V_132 -> V_110 = 0 ;
F_38 ( & V_2 -> V_126 ) ;
if ( V_191 )
F_5 ( V_2 ) ;
while ( F_50 ( & V_2 -> V_131 ) != 0 ) {
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_58 ,
V_145 -> V_48 () ) ;
F_51 () ;
F_6 ( & V_27 -> V_36 ) ;
}
F_11 ( L_59
L_44 , V_145 -> V_48 () ,
V_2 -> V_111 -> V_53 ,
( V_172 ) ? & V_170 [ 0 ] : L_29 ) ;
F_11 ( L_48
L_49 , V_145 -> V_48 () ,
( V_2 -> V_135 ) ? L_50 : L_51 ,
V_10 -> V_180 -> V_181 ) ;
F_11 ( L_52
L_60 , V_145 -> V_48 () , V_2 -> V_110 ,
V_2 -> V_182 ) ;
if ( ! V_190 ) {
V_2 -> V_132 = NULL ;
V_2 -> V_111 = NULL ;
F_52 ( V_2 -> V_124 ) ;
F_22 ( V_122 , V_2 ) ;
return;
}
F_37 ( & V_2 -> V_127 , V_190 ) ;
}
void F_53 (
struct V_9 * V_10 ,
struct V_20 * V_116 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_147 , * V_30 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ( V_30 != NULL ) &&
( V_30 -> V_111 == V_116 ) )
F_48 ( V_10 , V_116 , V_30 , 0 ) ;
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_111 != V_116 )
continue;
F_49 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
void F_54 (
struct V_9 * V_10 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_147 , * V_30 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 != NULL ) {
struct V_20 * V_192 = V_30 -> V_111 ;
F_48 ( V_10 , V_192 ,
V_30 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_49 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_6 ( & V_27 -> V_176 ) ;
F_27 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_38 ( & V_2 -> V_128 ) ;
F_52 ( V_2 -> V_124 ) ;
F_22 ( V_122 , V_2 ) ;
}
F_8 ( & V_27 -> V_176 ) ;
}
static int F_55 ( struct V_39 * V_40 )
{
return F_56 ( V_40 -> V_47 -> V_193 ,
& V_40 -> V_194 . V_195 ) ;
}
static void F_57 ( struct V_39 * V_40 )
{
F_58 ( V_40 -> V_47 -> V_193 ,
& V_40 -> V_194 . V_195 ) ;
F_34 ( & V_40 -> V_196 ) ;
F_35 () ;
}
static int F_59 ( struct V_20 * V_116 )
{
struct V_39 * V_40 = V_116 -> V_42 ;
if ( V_116 -> V_197 )
return 0 ;
return F_56 ( V_40 -> V_47 -> V_193 ,
& V_116 -> V_198 . V_195 ) ;
}
static void F_60 ( struct V_20 * V_116 )
{
struct V_39 * V_40 = V_116 -> V_42 ;
if ( V_116 -> V_197 ) {
F_34 ( & V_116 -> V_199 ) ;
F_35 () ;
return;
}
F_58 ( V_40 -> V_47 -> V_193 ,
& V_116 -> V_198 . V_195 ) ;
F_34 ( & V_116 -> V_199 ) ;
F_35 () ;
}
static int F_33 ( struct V_59 * V_51 )
{
struct V_152 * V_178 = V_51 -> V_152 ;
struct V_20 * V_116 ;
struct V_39 * V_40 ;
if ( ! V_178 )
return 0 ;
V_116 = V_178 -> V_153 ;
V_40 = V_116 -> V_42 ;
return F_56 ( V_40 -> V_47 -> V_193 ,
& V_178 -> V_200 . V_195 ) ;
}
static void F_36 ( struct V_59 * V_51 )
{
struct V_152 * V_178 = V_51 -> V_152 ;
struct V_20 * V_116 ;
struct V_39 * V_40 ;
if ( ! V_178 ) {
F_34 ( & V_51 -> V_154 ) ;
F_35 () ;
return;
}
V_116 = V_178 -> V_153 ;
V_40 = V_116 -> V_42 ;
F_58 ( V_40 -> V_47 -> V_193 ,
& V_178 -> V_200 . V_195 ) ;
F_34 ( & V_51 -> V_154 ) ;
F_35 () ;
}
static T_2
F_61 (
struct V_7 * V_8 ,
struct V_39 * V_40 ,
unsigned char * V_201 ,
T_3 V_119 ,
int V_120 ,
int V_121 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_141 * V_202 ;
struct V_39 * V_203 = NULL , * V_204 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_20 * V_205 = NULL ;
struct V_59 * V_206 = NULL , * V_207 ;
struct V_1 * V_208 , * V_209 , * V_210 ;
struct V_1 * V_147 , * V_148 ;
F_62 ( V_211 ) ;
struct V_212 * V_213 , * V_214 , * V_215 ;
struct V_144 * V_216 ;
unsigned char * V_3 ;
unsigned char * V_217 , * V_218 = NULL , V_219 , V_220 ;
char * V_221 = NULL , V_222 [ 64 ] , V_170 [ V_171 ] ;
T_2 V_55 ;
T_1 V_223 , V_224 = 0 ;
int V_225 , V_172 ;
T_1 V_226 = 0 ;
memset ( V_222 , 0 , 64 ) ;
V_207 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
V_213 = F_21 ( sizeof( struct V_212 ) , V_160 ) ;
if ( ! V_213 ) {
F_9 ( L_61 ) ;
return V_227 ;
}
F_23 ( & V_213 -> V_228 ) ;
V_213 -> V_203 = V_40 ;
V_213 -> V_205 = V_14 -> V_20 ;
V_213 -> V_206 = V_207 ;
V_209 = F_26 ( V_8 -> V_11 ,
V_14 -> V_20 , V_207 , V_201 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_209 ) {
F_52 ( V_213 ) ;
return V_227 ;
}
V_213 -> V_208 = V_209 ;
V_213 -> V_225 = 1 ;
F_37 ( & V_213 -> V_228 , & V_211 ) ;
if ( V_8 -> V_229 < 28 ) {
F_63 ( L_62
L_63 , V_8 -> V_229 ) ;
V_55 = V_230 ;
goto V_43;
}
V_3 = F_64 ( V_8 ) ;
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
V_217 = & V_3 [ 28 ] ;
while ( V_223 > 0 ) {
V_219 = ( V_217 [ 0 ] & 0x0f ) ;
V_203 = NULL ;
F_6 ( & V_10 -> V_149 ) ;
F_31 (tmp_port, &dev->dev_sep_list, sep_list) {
V_204 = V_202 -> V_232 ;
if ( ! V_204 )
continue;
V_216 = V_204 -> V_47 ;
if ( ! V_216 )
continue;
if ( ! V_216 -> V_233 ||
! V_216 -> V_234 )
continue;
V_220 = V_216 -> V_233 ( V_204 ) ;
if ( V_220 != V_219 )
continue;
V_226 = V_202 -> V_235 ;
V_218 = V_216 -> V_234 (
V_204 , ( const char * ) V_217 , & V_224 ,
& V_221 ) ;
if ( ! V_218 )
continue;
F_28 ( & V_204 -> V_196 ) ;
F_29 () ;
F_8 ( & V_10 -> V_149 ) ;
if ( F_55 ( V_204 ) ) {
F_9 ( L_66
L_67 ) ;
F_34 ( & V_204 -> V_196 ) ;
F_35 () ;
V_55 = V_227 ;
goto V_231;
}
F_65 ( & V_204 -> V_236 ) ;
V_205 = F_66 (
V_204 , V_218 ) ;
if ( V_205 ) {
F_28 ( & V_205 -> V_199 ) ;
F_29 () ;
}
F_67 ( & V_204 -> V_236 ) ;
if ( ! V_205 ) {
F_57 ( V_204 ) ;
F_6 ( & V_10 -> V_149 ) ;
continue;
}
if ( F_59 ( V_205 ) ) {
F_9 ( L_68
L_69 ) ;
F_34 ( & V_205 -> V_199 ) ;
F_35 () ;
F_57 ( V_204 ) ;
V_55 = V_227 ;
goto V_231;
}
V_203 = V_204 ;
F_11 ( L_70
L_71 ,
V_203 -> V_47 -> V_48 () ,
V_205 -> V_53 , V_226 ) ;
F_6 ( & V_10 -> V_149 ) ;
break;
}
F_8 ( & V_10 -> V_149 ) ;
if ( ! V_203 ) {
F_9 ( L_72
L_73 ) ;
V_55 = V_230 ;
goto V_231;
}
F_11 ( L_74
L_75 ,
V_203 -> V_47 -> V_48 () , V_8 -> V_229 ,
V_223 , V_224 , V_218 , V_221 ) ;
if ( V_224 > V_223 ) {
F_9 ( L_76
L_77 , V_224 , V_217 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
V_55 = V_230 ;
goto V_231;
}
V_206 = F_68 ( V_205 ,
V_226 ) ;
if ( ! V_206 ) {
F_9 ( L_78
L_79 ,
V_203 -> V_47 -> V_48 () ,
V_226 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
V_55 = V_230 ;
goto V_231;
}
if ( F_33 ( V_206 ) ) {
F_9 ( L_80
L_81 ) ;
F_34 ( & V_206 -> V_154 ) ;
F_35 () ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
V_55 = V_227 ;
goto V_231;
}
F_11 ( L_82
L_83 ,
V_203 -> V_47 -> V_48 () ,
V_205 -> V_53 , V_206 -> V_52 ) ;
V_210 = F_46 ( V_10 , V_205 ,
V_221 ) ;
if ( V_210 ) {
F_5 ( V_210 ) ;
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
V_217 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
continue;
}
V_213 = F_21 ( sizeof( struct V_212 ) ,
V_160 ) ;
if ( ! V_213 ) {
F_9 ( L_61 ) ;
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
V_55 = V_227 ;
goto V_231;
}
F_23 ( & V_213 -> V_228 ) ;
V_213 -> V_203 = V_203 ;
V_213 -> V_205 = V_205 ;
V_213 -> V_206 = V_206 ;
V_208 = F_26 ( V_8 -> V_11 ,
V_205 , V_206 , V_221 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_208 ) {
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
F_52 ( V_213 ) ;
V_55 = V_230 ;
goto V_231;
}
V_213 -> V_208 = V_208 ;
F_37 ( & V_213 -> V_228 , & V_211 ) ;
V_217 += V_224 ;
V_223 -= V_224 ;
V_224 = 0 ;
}
F_69 ( V_8 ) ;
F_27 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_203 = V_214 -> V_203 ;
V_205 = V_214 -> V_205 ;
V_206 = V_214 -> V_206 ;
V_208 = V_214 -> V_208 ;
V_225 = V_214 -> V_225 ;
F_38 ( & V_214 -> V_228 ) ;
F_52 ( V_214 ) ;
memset ( V_170 , 0 , V_171 ) ;
V_172 = F_1 ( V_208 , & V_170 [ 0 ] ,
V_171 ) ;
F_42 ( V_8 -> V_11 , V_205 ,
V_208 , 0 , 0 ) ;
F_11 ( L_84
L_85
L_86 , V_203 -> V_47 -> V_48 () ,
V_205 -> V_53 , ( V_172 ) ?
& V_170 [ 0 ] : L_29 , V_206 -> V_52 ) ;
if ( V_225 )
continue;
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
}
return 0 ;
V_231:
F_69 ( V_8 ) ;
V_43:
F_27 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_203 = V_214 -> V_203 ;
V_205 = V_214 -> V_205 ;
V_206 = V_214 -> V_206 ;
V_208 = V_214 -> V_208 ;
V_225 = V_214 -> V_225 ;
F_38 ( & V_214 -> V_228 ) ;
F_52 ( V_214 ) ;
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_38 ( & V_147 -> V_130 ) ;
F_36 ( V_147 -> V_132 ) ;
F_22 ( V_122 , V_147 ) ;
}
F_52 ( V_208 -> V_124 ) ;
F_22 ( V_122 , V_208 ) ;
if ( V_225 )
continue;
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_203 ) ;
}
return V_55 ;
}
static int F_70 (
struct V_9 * V_10 ,
unsigned char * V_3 ,
T_1 V_125 ,
int V_237 )
{
struct V_49 * V_173 ;
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned char V_238 [ 512 ] , V_239 [ 32 ] ;
T_6 V_240 = 0 ;
int V_241 = 0 ;
memset ( V_3 , 0 , V_125 ) ;
if ( V_237 ) {
snprintf ( V_3 , V_125 ,
L_87 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_31 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
V_238 [ 0 ] = '\0' ;
V_239 [ 0 ] = '\0' ;
V_40 = V_2 -> V_111 -> V_42 ;
V_173 = V_2 -> V_137 ;
if ( V_2 -> V_5 )
snprintf ( V_239 , 32 , L_88 ,
V_2 -> V_6 ) ;
if ( V_10 -> V_109 == V_2 ) {
snprintf ( V_238 , 512 , L_89
L_90
L_91
L_92
L_93
L_94
L_95 , V_241 ,
V_40 -> V_47 -> V_48 () ,
V_2 -> V_111 -> V_53 , V_239 ,
V_2 -> V_110 , V_2 -> V_31 ,
V_2 -> V_162 , V_2 -> V_135 ,
V_2 -> V_133 ) ;
} else {
snprintf ( V_238 , 512 , L_96
L_97
L_98
L_99 ,
V_241 , V_40 -> V_47 -> V_48 () ,
V_2 -> V_111 -> V_53 , V_239 ,
V_2 -> V_110 , V_2 -> V_135 ,
V_2 -> V_133 ) ;
}
if ( ( V_240 + strlen ( V_238 ) >= V_125 ) ) {
F_9 ( L_100
L_101 ) ;
F_8 ( & V_10 -> V_28 . V_36 ) ;
return - V_242 ;
}
V_240 += sprintf ( V_3 + V_240 , L_33 , V_238 ) ;
snprintf ( V_238 , 512 , L_102
L_103
L_104 , V_40 -> V_47 -> V_48 () ,
V_40 -> V_47 -> V_174 ( V_40 ) ,
V_40 -> V_47 -> V_175 ( V_40 ) ,
V_173 -> V_243 -> V_235 , V_173 -> V_50 , V_241 ) ;
if ( ( V_240 + strlen ( V_238 ) >= V_125 ) ) {
F_9 ( L_100
L_101 ) ;
F_8 ( & V_10 -> V_28 . V_36 ) ;
return - V_242 ;
}
V_240 += sprintf ( V_3 + V_240 , L_33 , V_238 ) ;
V_241 ++ ;
}
F_8 ( & V_10 -> V_28 . V_36 ) ;
if ( ! V_241 )
V_240 += sprintf ( V_3 + V_240 , L_105 ) ;
return 0 ;
}
static int F_71 (
struct V_9 * V_10 ,
unsigned char * V_3 ,
T_1 V_125 ,
int V_237 )
{
int V_55 ;
F_6 ( & V_10 -> V_44 ) ;
V_55 = F_70 ( V_10 , V_3 , V_125 ,
V_237 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static int F_72 (
struct V_9 * V_10 ,
unsigned char * V_3 ,
T_1 V_125 )
{
struct V_244 * V_245 = & V_10 -> V_244 ;
struct V_246 * V_246 ;
struct V_247 V_248 [ 1 ] ;
T_7 V_249 ;
int V_250 = V_251 | V_252 | V_253 ;
char V_254 [ 512 ] ;
int V_55 ;
memset ( V_248 , 0 , sizeof( struct V_247 ) ) ;
memset ( V_254 , 0 , 512 ) ;
if ( strlen ( & V_245 -> V_255 [ 0 ] ) >= 512 ) {
F_9 ( L_106
L_107 ) ;
return - V_242 ;
}
snprintf ( V_254 , 512 , L_108 , & V_245 -> V_255 [ 0 ] ) ;
V_246 = F_73 ( V_254 , V_250 , 0600 ) ;
if ( F_74 ( V_246 ) || ! V_246 || ! V_246 -> V_256 ) {
F_9 ( L_109
L_81 , V_254 ) ;
return F_74 ( V_246 ) ? F_75 ( V_246 ) : - V_257 ;
}
V_248 [ 0 ] . V_258 = & V_3 [ 0 ] ;
if ( ! V_125 )
V_248 [ 0 ] . V_259 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_248 [ 0 ] . V_259 = V_125 ;
V_249 = F_76 () ;
F_77 ( F_78 () ) ;
V_55 = F_79 ( V_246 , & V_248 [ 0 ] , 1 , & V_246 -> V_260 ) ;
F_77 ( V_249 ) ;
if ( V_55 < 0 ) {
F_11 ( L_110 , V_254 ) ;
F_80 ( V_246 , NULL ) ;
return - V_261 ;
}
F_80 ( V_246 , NULL ) ;
return 0 ;
}
static int
F_81 ( struct V_9 * V_10 , unsigned char * V_262 ,
T_1 V_263 )
{
unsigned char V_264 [ 64 ] , * V_3 ;
T_1 V_125 ;
int V_237 = 0 ;
int V_55 ;
if ( ! V_262 ) {
memset ( V_264 , 0 , 64 ) ;
V_3 = & V_264 [ 0 ] ;
V_125 = 64 ;
V_237 = 1 ;
} else {
V_3 = V_262 ;
V_125 = V_263 ;
}
V_55 = F_71 ( V_10 , V_3 , V_125 ,
V_237 ) ;
if ( V_55 != 0 )
return V_55 ;
return F_72 ( V_10 , V_3 , 0 ) ;
}
static T_2
F_82 ( struct V_7 * V_8 , T_3 V_265 , T_3 V_119 ,
int V_121 , int V_120 , int V_266 , int V_267 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_51 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_268 , * V_147 , * V_210 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_124 = NULL ;
unsigned char V_239 [ V_138 ] , * V_188 = NULL ;
T_2 V_55 = V_269 ;
int V_270 = 0 , type ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_111 ) ;
return V_227 ;
}
V_42 = V_14 -> V_42 ;
V_51 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
if ( V_42 -> V_47 -> V_185 ) {
memset ( & V_239 [ 0 ] , 0 , V_138 ) ;
V_42 -> V_47 -> V_185 ( V_14 , & V_239 [ 0 ] ,
V_138 ) ;
V_188 = & V_239 [ 0 ] ;
}
V_210 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_210 ) {
if ( V_265 ) {
F_63 ( L_112
L_113 ) ;
return V_21 ;
}
if ( ! V_119 )
return 0 ;
if ( ! V_266 ) {
if ( F_45 ( V_8 -> V_11 ,
V_14 -> V_20 , V_51 , V_188 ,
V_119 , V_120 , V_121 ,
V_267 , 0 ) ) {
F_9 ( L_114
L_115 ) ;
return V_230 ;
}
} else {
V_55 = F_61 ( V_8 , V_42 ,
V_188 , V_119 , V_120 , V_121 ) ;
if ( V_55 != 0 )
return V_55 ;
}
if ( ! V_121 ) {
V_27 -> V_177 = 0 ;
F_81 ( V_8 -> V_11 , NULL , 0 ) ;
F_11 ( L_116
L_117 ) ;
return 0 ;
}
V_2 = F_4 ( V_8 -> V_11 ,
V_14 -> V_20 , V_14 ) ;
if ( F_81 ( V_8 -> V_11 ,
& V_2 -> V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
V_27 -> V_177 = 1 ;
F_11 ( L_118 ) ;
}
goto V_271;
}
V_2 = V_210 ;
type = V_2 -> V_31 ;
if ( ! V_267 ) {
if ( V_265 != V_2 -> V_110 ) {
F_9 ( L_119
L_120
L_121
L_122 , V_265 ,
V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_271;
}
}
if ( V_266 ) {
F_9 ( L_123
L_124 ) ;
V_55 = V_230 ;
goto V_271;
}
if ( V_2 -> V_135 && ! ( V_120 ) ) {
F_9 ( L_125
L_126
L_127 ) ;
V_55 = V_272 ;
goto V_271;
}
if ( V_121 ) {
V_124 = F_21 ( V_27 -> V_125 ,
V_160 ) ;
if ( ! V_124 ) {
F_9 ( L_114
L_128 ) ;
V_55 = V_227 ;
goto V_271;
}
}
if ( ! V_119 ) {
V_270 = F_47 (
V_8 -> V_11 , V_2 ) ;
if ( V_270 < 0 ) {
F_52 ( V_124 ) ;
V_55 = V_21 ;
goto V_271;
}
F_6 ( & V_27 -> V_36 ) ;
if ( V_2 -> V_135 ) {
F_27 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_268 -> V_135 )
continue;
if ( V_268 -> V_110 != V_265 )
continue;
if ( V_2 == V_268 )
continue;
if ( strcmp ( V_2 -> V_111 -> V_53 ,
V_268 -> V_111 -> V_53 ) )
continue;
F_49 ( V_10 ,
V_268 , NULL , 0 ) ;
}
}
F_49 ( V_8 -> V_11 , V_2 , NULL , 1 ) ;
if ( V_270 &&
( type == V_32 ||
type == V_33 ) ) {
F_31 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_83 (
V_268 -> V_111 ,
V_268 -> V_133 ,
0x2A ,
V_273 ) ;
}
}
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_121 ) {
V_27 -> V_177 = 0 ;
F_81 ( V_10 , NULL , 0 ) ;
F_11 ( L_129
L_130 ) ;
return 0 ;
}
if ( ! F_81 ( V_10 , & V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
V_27 -> V_177 = 1 ;
F_11 ( L_131
L_130 ) ;
}
goto V_274;
}
V_2 -> V_182 = F_18 ( V_8 -> V_11 ) ;
V_2 -> V_110 = V_119 ;
F_11 ( L_132
L_133
L_60 , V_8 -> V_275 -> V_48 () ,
( V_267 ) ? L_46 : L_29 ,
V_2 -> V_111 -> V_53 ,
V_2 -> V_110 , V_2 -> V_182 ) ;
if ( ! V_121 ) {
V_27 -> V_177 = 0 ;
F_81 ( V_10 , NULL , 0 ) ;
F_11 ( L_129
L_134 ) ;
V_55 = 0 ;
goto V_271;
}
if ( ! F_81 ( V_10 , & V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
V_27 -> V_177 = 1 ;
F_11 ( L_131
L_134 ) ;
}
V_274:
F_52 ( V_124 ) ;
V_55 = 0 ;
V_271:
F_5 ( V_2 ) ;
return V_55 ;
}
unsigned char * F_15 ( int type )
{
switch ( type ) {
case V_69 :
return L_135 ;
case V_70 :
return L_136 ;
case V_32 :
return L_137 ;
case V_33 :
return L_138 ;
case V_34 :
return L_139 ;
case V_35 :
return L_140 ;
default:
break;
}
return L_141 ;
}
static T_2
F_84 ( struct V_7 * V_8 , int type , int V_276 , T_3 V_265 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_170 [ V_171 ] ;
T_2 V_55 ;
int V_172 ;
memset ( V_170 , 0 , V_171 ) ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_111 ) ;
return V_227 ;
}
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_142
L_143 ) ;
return V_227 ;
}
if ( V_265 != V_2 -> V_110 ) {
F_9 ( L_144
L_145
L_122 , V_265 , V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_271;
}
if ( V_276 != V_277 ) {
F_9 ( L_146 , V_276 ) ;
V_55 = V_230 ;
goto V_271;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 ) {
if ( V_30 != V_2 ) {
struct V_20 * V_192 = V_30 -> V_111 ;
F_9 ( L_147
L_148
L_149 ,
V_8 -> V_275 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_271;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_162 != V_276 ) ) {
struct V_20 * V_192 = V_30 -> V_111 ;
F_9 ( L_147
L_150
L_151
L_4 ,
V_8 -> V_275 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_271;
}
F_8 ( & V_10 -> V_44 ) ;
V_55 = 0 ;
goto V_271;
}
V_2 -> V_162 = V_276 ;
V_2 -> V_31 = type ;
V_2 -> V_30 = 1 ;
V_10 -> V_109 = V_2 ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
F_11 ( L_152
L_153 ,
V_8 -> V_275 -> V_48 () , F_15 ( type ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_11 ( L_42 ,
V_8 -> V_275 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
( V_172 ) ? & V_170 [ 0 ] : L_29 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_177 ) {
if ( ! F_81 ( V_8 -> V_11 ,
& V_2 -> V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
F_11 ( L_154
L_155 ) ;
}
}
V_55 = 0 ;
V_271:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_85 ( struct V_7 * V_8 , int type , int V_276 ,
T_3 V_265 )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_84 ( V_8 , type , V_276 , V_265 ) ;
default:
F_9 ( L_156
L_157 , type ) ;
return V_272 ;
}
}
static void F_48 (
struct V_9 * V_10 ,
struct V_20 * V_278 ,
struct V_1 * V_2 ,
int V_279 )
{
struct V_144 * V_145 = V_278 -> V_42 -> V_47 ;
char V_170 [ V_171 ] ;
int V_172 ;
memset ( V_170 , 0 , V_171 ) ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
V_10 -> V_109 = NULL ;
F_11 ( L_158
L_153 ,
V_145 -> V_48 () , ( V_279 ) ? L_159 : L_160 ,
F_15 ( V_2 -> V_31 ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_11 ( L_161 ,
V_145 -> V_48 () , V_278 -> V_53 ,
( V_172 ) ? & V_170 [ 0 ] : L_29 ) ;
V_2 -> V_30 = V_2 -> V_31 = V_2 -> V_162 = 0 ;
}
static T_2
F_86 ( struct V_7 * V_8 , int type , int V_276 ,
T_3 V_265 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_268 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
int V_63 = 0 ;
T_2 V_55 = 0 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_111 ) ;
return V_227 ;
}
V_2 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_142
L_162 ) ;
return V_227 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ! V_30 ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_271;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) )
V_63 = 1 ;
if ( ( V_63 == 0 ) && ( V_30 != V_2 ) ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_271;
}
if ( V_265 != V_2 -> V_110 ) {
F_9 ( L_163
L_145
L_122 , V_265 , V_2 -> V_110 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_271;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_162 != V_276 ) ) {
struct V_20 * V_192 = V_30 -> V_111 ;
F_9 ( L_164
L_165
L_166
L_149 ,
V_8 -> V_275 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_192 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_271;
}
F_48 ( V_10 , V_14 -> V_20 ,
V_2 , 1 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( ( type != V_32 ) &&
( type != V_33 ) &&
( type != V_34 ) &&
( type != V_35 ) ) {
goto V_280;
}
F_6 ( & V_27 -> V_36 ) ;
F_31 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_268 == V_2 )
continue;
F_83 ( V_268 -> V_111 ,
V_268 -> V_133 ,
0x2A , V_273 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
V_280:
if ( V_27 -> V_177 ) {
if ( ! F_81 ( V_8 -> V_11 ,
& V_2 -> V_124 [ 0 ] , V_27 -> V_125 ) ) {
F_11 ( L_167 ) ;
}
}
V_271:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_87 ( struct V_7 * V_8 , T_3 V_265 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_111 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_147 , * V_281 , * V_30 ;
T_1 V_133 = 0 ;
int V_282 = 0 ;
V_281 = F_4 ( V_8 -> V_11 ,
V_14 -> V_20 , V_14 ) ;
if ( ! V_281 ) {
F_9 ( L_142
L_168 ) ;
return V_227 ;
}
if ( V_265 != V_281 -> V_110 ) {
F_9 ( L_119
L_120
L_121
L_122 , V_265 , V_281 -> V_110 ) ;
F_5 ( V_281 ) ;
return V_21 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 ) {
struct V_20 * V_192 = V_30 -> V_111 ;
F_48 ( V_10 , V_192 ,
V_30 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_282 = ( V_281 == V_2 ) ? 1 : 0 ;
V_111 = V_2 -> V_111 ;
V_133 = V_2 -> V_133 ;
F_49 ( V_10 , V_2 , NULL ,
V_282 ) ;
if ( ! V_282 )
F_83 ( V_111 , V_133 ,
0x2A , V_283 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_169 ,
V_8 -> V_275 -> V_48 () ) ;
if ( V_27 -> V_177 ) {
F_81 ( V_8 -> V_11 , NULL , 0 ) ;
F_11 ( L_154
L_170 ) ;
}
F_18 ( V_10 ) ;
return 0 ;
}
static void F_88 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_189 * V_190 ,
int type ,
int V_276 ,
int abort )
{
struct V_20 * V_116 = V_2 -> V_111 ;
struct V_144 * V_145 = V_116 -> V_42 -> V_47 ;
char V_170 [ V_171 ] ;
int V_172 ;
memset ( V_170 , 0 , V_171 ) ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
if ( V_10 -> V_109 )
F_48 ( V_10 , V_116 ,
V_10 -> V_109 , 0 ) ;
V_10 -> V_109 = V_2 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = type ;
V_2 -> V_162 = V_276 ;
F_11 ( L_171
L_153 ,
V_145 -> V_48 () , ( abort ) ? L_172 : L_29 ,
F_15 ( type ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_11 ( L_173 ,
V_145 -> V_48 () , ( abort ) ? L_172 : L_29 ,
V_116 -> V_53 , ( V_172 ) ? & V_170 [ 0 ] : L_29 ) ;
if ( V_190 )
F_37 ( & V_2 -> V_127 ,
V_190 ) ;
}
static void F_89 (
struct V_189 * V_190 ,
struct V_1 * V_284 )
{
struct V_1 * V_2 , * V_147 ;
F_27 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_38 ( & V_2 -> V_127 ) ;
if ( V_284 == V_2 )
continue;
if ( V_2 -> V_30 ) {
F_63 ( L_174 ) ;
continue;
}
V_2 -> V_132 = NULL ;
V_2 -> V_111 = NULL ;
F_52 ( V_2 -> V_124 ) ;
F_22 ( V_122 , V_2 ) ;
}
}
static T_2
F_90 ( struct V_7 * V_8 , int type , int V_276 , T_3 V_265 ,
T_3 V_119 , int abort )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_111 ;
struct V_12 * V_14 = V_8 -> V_14 ;
F_62 ( V_190 ) ;
struct V_1 * V_2 , * V_147 , * V_281 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
T_1 V_133 = 0 ;
int V_63 = 0 , V_282 = 0 , V_285 = 0 ;
int V_286 = 0 , V_287 = 0 ;
if ( ! V_14 )
return V_227 ;
V_281 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_281 ) {
F_9 ( L_142
L_175 ,
( abort ) ? L_172 : L_29 ) ;
return V_21 ;
}
if ( V_281 -> V_110 != V_265 ) {
F_5 ( V_281 ) ;
return V_21 ;
}
if ( V_276 != V_277 ) {
F_9 ( L_146 , V_276 ) ;
F_5 ( V_281 ) ;
return V_230 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 &&
( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) )
V_63 = 1 ;
if ( ! V_63 && ! V_119 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_281 ) ;
return V_230 ;
}
if ( ! V_30 || ( V_30 -> V_110 != V_119 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_63 ) {
if ( V_2 -> V_110 != V_119 )
continue;
V_282 = ( V_281 == V_2 ) ? 1 : 0 ;
V_111 = V_2 -> V_111 ;
V_133 = V_2 -> V_133 ;
F_49 ( V_10 , V_2 ,
( abort ) ? & V_190 :
NULL , V_282 ) ;
V_285 ++ ;
} else {
if ( ( V_119 ) &&
( V_2 -> V_110 != V_119 ) )
continue;
V_282 = ( V_281 == V_2 ) ? 1 : 0 ;
if ( V_282 )
continue;
V_111 = V_2 -> V_111 ;
V_133 = V_2 -> V_133 ;
F_49 ( V_10 , V_2 ,
( abort ) ? & V_190 :
NULL , 0 ) ;
V_285 ++ ;
}
if ( ! V_282 )
F_83 ( V_111 ,
V_133 , 0x2A ,
V_288 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_285 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_281 ) ;
return V_21 ;
}
if ( V_30 && V_63 && ! ( V_119 ) ) {
F_88 ( V_10 , V_281 ,
( abort ) ? & V_190 : NULL ,
type , V_276 , abort ) ;
if ( abort )
F_89 (
& V_190 , V_281 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_177 ) {
if ( ! F_81 ( V_8 -> V_11 ,
& V_281 -> V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
F_11 ( L_176
L_177 , ( abort ) ?
L_172 : L_29 ) ;
}
}
F_5 ( V_281 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
V_286 = V_30 -> V_31 ;
V_287 = V_30 -> V_162 ;
if ( V_281 != V_30 )
F_48 ( V_10 ,
V_30 -> V_111 ,
V_10 -> V_109 , 0 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_282 = ( V_281 == V_2 ) ? 1 : 0 ;
if ( V_282 )
continue;
if ( V_2 -> V_110 != V_119 )
continue;
V_111 = V_2 -> V_111 ;
V_133 = V_2 -> V_133 ;
F_49 ( V_10 , V_2 ,
( abort ) ? & V_190 : NULL ,
V_282 ) ;
F_83 ( V_111 , V_133 , 0x2A ,
V_288 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_88 ( V_10 , V_281 ,
( abort ) ? & V_190 : NULL ,
type , V_276 , abort ) ;
if ( ( V_286 != type ) || ( V_287 != V_276 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_282 = ( V_281 == V_2 ) ? 1 : 0 ;
if ( V_282 )
continue;
F_83 ( V_2 -> V_111 ,
V_2 -> V_133 , 0x2A ,
V_273 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( abort ) {
F_91 ( V_10 , NULL , & V_190 , V_8 ) ;
F_89 ( & V_190 ,
V_281 ) ;
}
if ( V_27 -> V_177 ) {
if ( ! F_81 ( V_8 -> V_11 ,
& V_281 -> V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
F_11 ( L_178
L_179 , abort ? L_172 : L_29 ) ;
}
}
F_5 ( V_281 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
static T_2
F_92 ( struct V_7 * V_8 , int type , int V_276 ,
T_3 V_265 , T_3 V_119 , int abort )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_90 ( V_8 , type , V_276 , V_265 ,
V_119 , abort ) ;
default:
F_9 ( L_180
L_181 , ( abort ) ? L_172 : L_29 , type ) ;
return V_272 ;
}
}
static T_2
F_93 ( struct V_7 * V_8 , T_3 V_265 ,
T_3 V_119 , int V_121 , int V_289 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_206 = NULL ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_20 * V_192 , * V_111 , * V_205 = NULL ;
struct V_141 * V_141 ;
struct V_39 * V_42 , * V_290 = NULL ;
struct V_144 * V_291 = NULL , * V_292 ;
struct V_1 * V_2 , * V_30 , * V_208 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
unsigned char * V_293 ;
char * V_221 = NULL , V_222 [ 64 ] , V_170 [ V_171 ] ;
T_1 V_224 , V_294 ;
int V_295 = 0 , type , V_276 , V_296 , V_172 ;
T_2 V_55 ;
unsigned short V_297 ;
unsigned char V_219 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_111 ) ;
return V_227 ;
}
memset ( V_222 , 0 , 64 ) ;
memset ( V_170 , 0 , V_171 ) ;
V_42 = V_14 -> V_42 ;
V_292 = V_42 -> V_47 ;
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_182
L_183 ) ;
return V_227 ;
}
if ( V_265 != V_2 -> V_110 ) {
F_63 ( L_184
L_185
L_186 , V_265 , V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_271;
}
if ( ! V_119 ) {
F_63 ( L_187
L_188 ) ;
V_55 = V_230 ;
goto V_271;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_227 ;
goto V_271;
}
V_297 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_297 |= V_3 [ 19 ] & 0xff ;
V_224 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_224 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_224 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_224 |= V_3 [ 23 ] & 0xff ;
F_69 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_224 + 24 ) != V_8 -> V_229 ) {
F_9 ( L_189
L_65 , V_224 ,
V_8 -> V_229 ) ;
V_55 = V_230 ;
goto V_271;
}
F_6 ( & V_10 -> V_149 ) ;
F_31 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_141 -> V_235 != V_297 )
continue;
V_290 = V_141 -> V_232 ;
if ( ! V_290 )
continue;
V_291 = V_290 -> V_47 ;
if ( ! V_291 )
continue;
F_28 ( & V_290 -> V_196 ) ;
F_29 () ;
F_8 ( & V_10 -> V_149 ) ;
if ( F_55 ( V_290 ) ) {
F_9 ( L_190
L_191 ) ;
F_34 ( & V_290 -> V_196 ) ;
F_35 () ;
V_55 = V_227 ;
goto V_271;
}
F_6 ( & V_10 -> V_149 ) ;
break;
}
F_8 ( & V_10 -> V_149 ) ;
if ( ! V_290 || ! V_291 ) {
F_9 ( L_192
L_193
L_194 , V_297 ) ;
V_55 = V_230 ;
goto V_271;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_227 ;
goto V_271;
}
V_219 = ( V_3 [ 24 ] & 0x0f ) ;
F_11 ( L_195
L_157 , V_219 ) ;
if ( V_219 != V_291 -> V_233 ( V_290 ) ) {
F_9 ( L_184
L_196
L_197 , V_219 ,
V_291 -> V_233 ( V_290 ) ,
V_291 -> V_48 () ) ;
V_55 = V_230 ;
goto V_43;
}
if ( V_291 -> V_234 == NULL ) {
F_9 ( L_198
L_199
L_200 ) ;
V_55 = V_227 ;
goto V_43;
}
V_293 = V_291 -> V_234 ( V_290 ,
( const char * ) & V_3 [ 24 ] , & V_294 , & V_221 ) ;
if ( ! V_293 ) {
F_9 ( L_192
L_201 ) ;
V_55 = V_230 ;
goto V_43;
}
F_69 ( V_8 ) ;
V_3 = NULL ;
F_11 ( L_202
L_203 , V_291 -> V_48 () , ( V_221 != NULL ) ?
L_204 : L_205 , V_293 , ( V_221 != NULL ) ?
V_221 : L_29 ) ;
V_111 = V_2 -> V_111 ;
V_296 = ( ! strcmp ( V_293 ,
V_111 -> V_53 ) ) ? 1 : 0 ;
if ( ! V_296 )
goto V_298;
if ( ! V_221 || ! V_2 -> V_5 ) {
F_9 ( L_206
L_207 , V_293 ,
V_111 -> V_53 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( ! strcmp ( V_221 , V_2 -> V_6 ) ) {
F_9 ( L_208
L_209 ,
V_293 , V_221 , V_111 -> V_53 ,
V_2 -> V_6 ) ;
V_55 = V_230 ;
goto V_43;
}
V_298:
F_65 ( & V_290 -> V_236 ) ;
V_205 = F_66 ( V_290 ,
V_293 ) ;
if ( V_205 ) {
F_28 ( & V_205 -> V_199 ) ;
F_29 () ;
}
F_67 ( & V_290 -> V_236 ) ;
if ( ! V_205 ) {
F_9 ( L_210
L_211 , V_291 -> V_48 () ,
V_293 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( F_59 ( V_205 ) ) {
F_9 ( L_212
L_213 ) ;
F_34 ( & V_205 -> V_199 ) ;
F_35 () ;
V_205 = NULL ;
V_55 = V_230 ;
goto V_43;
}
F_11 ( L_214
L_215 , V_291 -> V_48 () ,
V_205 -> V_53 ) ;
V_206 = F_68 ( V_205 , V_297 ) ;
if ( ! V_206 ) {
F_9 ( L_216
L_194 , V_291 -> V_48 () , V_297 ) ;
V_55 = V_230 ;
goto V_43;
}
if ( F_33 ( V_206 ) ) {
F_9 ( L_217 ) ;
F_34 ( & V_206 -> V_154 ) ;
F_35 () ;
V_206 = NULL ;
V_55 = V_227 ;
goto V_43;
}
F_11 ( L_218
L_219 ,
V_291 -> V_48 () , V_205 -> V_53 ,
V_206 -> V_52 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ! V_30 ) {
F_63 ( L_220
L_221 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_272 ;
goto V_43;
}
if ( V_30 != V_2 ) {
F_63 ( L_222
L_223 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) {
F_63 ( L_224
L_225 ,
F_15 ( V_30 -> V_31 ) ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
V_192 = V_30 -> V_111 ;
type = V_30 -> V_31 ;
V_276 = V_30 -> V_31 ;
V_208 = F_46 ( V_10 , V_205 ,
V_221 ) ;
if ( ! V_208 ) {
if ( F_45 ( V_8 -> V_11 ,
V_205 , V_206 , V_221 ,
V_119 , 0 , V_121 , 2 , 1 ) ) {
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_230 ;
goto V_43;
}
V_208 = F_46 ( V_10 , V_205 ,
V_221 ) ;
V_295 = 1 ;
}
F_48 ( V_10 , V_192 ,
V_10 -> V_109 , 0 ) ;
V_10 -> V_109 = V_208 ;
V_208 -> V_30 = 1 ;
V_208 -> V_31 = type ;
V_2 -> V_162 = V_276 ;
V_172 = F_1 ( V_2 , & V_170 [ 0 ] ,
V_171 ) ;
if ( ! V_295 )
V_208 -> V_182 = V_27 -> V_115 ++ ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_226
L_227
L_228 , V_291 -> V_48 () ,
F_15 ( type ) , V_297 ,
V_208 -> V_182 ) ;
F_11 ( L_229
L_230 ,
V_292 -> V_48 () , V_111 -> V_53 ,
( V_172 ) ? & V_170 [ 0 ] : L_29 , V_291 -> V_48 () ,
V_205 -> V_53 , ( V_221 != NULL ) ?
V_221 : L_29 ) ;
F_36 ( V_206 ) ;
F_60 ( V_205 ) ;
F_57 ( V_290 ) ;
if ( V_289 ) {
F_6 ( & V_27 -> V_36 ) ;
F_49 ( V_10 , V_2 , NULL , 1 ) ;
F_8 ( & V_27 -> V_36 ) ;
} else
F_5 ( V_2 ) ;
if ( ! V_121 ) {
V_27 -> V_177 = 0 ;
F_81 ( V_8 -> V_11 , NULL , 0 ) ;
F_11 ( L_116
L_231 ) ;
} else {
V_27 -> V_177 = 1 ;
if ( ! F_81 ( V_8 -> V_11 ,
& V_208 -> V_124 [ 0 ] ,
V_27 -> V_125 ) ) {
F_11 ( L_232
L_231 ) ;
}
}
F_69 ( V_8 ) ;
F_5 ( V_208 ) ;
return 0 ;
V_43:
if ( V_3 )
F_69 ( V_8 ) ;
if ( V_206 )
F_36 ( V_206 ) ;
if ( V_205 )
F_60 ( V_205 ) ;
F_57 ( V_290 ) ;
V_271:
F_5 ( V_2 ) ;
return V_55 ;
}
static unsigned long long F_94 ( unsigned char * V_58 )
{
unsigned int V_299 , V_300 ;
V_299 = ( V_58 [ 0 ] << 24 ) | ( V_58 [ 1 ] << 16 ) | ( V_58 [ 2 ] << 8 ) | V_58 [ 3 ] ;
V_300 = ( V_58 [ 4 ] << 24 ) | ( V_58 [ 5 ] << 16 ) | ( V_58 [ 6 ] << 8 ) | V_58 [ 7 ] ;
return ( ( unsigned long long ) V_300 ) | ( unsigned long long ) V_299 << 32 ;
}
T_2
F_95 ( struct V_7 * V_8 )
{
unsigned char * V_58 = & V_8 -> V_15 [ 0 ] ;
unsigned char * V_3 ;
T_3 V_265 , V_119 ;
int V_301 , V_276 , type , V_121 ;
int V_266 = 0 , V_120 = 0 , V_289 = 0 ;
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_233
L_234
L_235 ) ;
return V_21 ;
}
if ( ! V_8 -> V_14 )
return V_227 ;
if ( V_8 -> V_229 < 24 ) {
F_63 ( L_62
L_63 , V_8 -> V_229 ) ;
return V_230 ;
}
V_301 = ( V_58 [ 1 ] & 0x1f ) ;
V_276 = ( V_58 [ 2 ] & 0xf0 ) ;
type = ( V_58 [ 2 ] & 0x0f ) ;
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_265 = F_94 ( & V_3 [ 0 ] ) ;
V_119 = F_94 ( & V_3 [ 8 ] ) ;
if ( V_301 != V_85 ) {
V_266 = ( V_3 [ 20 ] & 0x08 ) ;
V_120 = ( V_3 [ 20 ] & 0x04 ) ;
V_121 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_121 = ( V_3 [ 17 ] & 0x01 ) ;
V_289 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_69 ( V_8 ) ;
V_3 = NULL ;
if ( V_266 && ( ( V_58 [ 1 ] & 0x1f ) != V_83 ) )
return V_230 ;
if ( ! V_266 && ( ( V_58 [ 1 ] & 0x1f ) != V_85 ) &&
( V_8 -> V_229 != 24 ) ) {
F_63 ( L_236
L_237 , V_8 -> V_229 ) ;
return V_230 ;
}
switch ( V_301 ) {
case V_83 :
V_55 = F_82 ( V_8 ,
V_265 , V_119 , V_121 , V_120 , V_266 , 0 ) ;
break;
case V_86 :
V_55 = F_85 ( V_8 , type , V_276 , V_265 ) ;
break;
case V_87 :
V_55 = F_86 ( V_8 , type , V_276 , V_265 ) ;
break;
case V_80 :
V_55 = F_87 ( V_8 , V_265 ) ;
break;
case V_81 :
V_55 = F_92 ( V_8 , type , V_276 ,
V_265 , V_119 , 0 ) ;
break;
case V_82 :
V_55 = F_92 ( V_8 , type , V_276 ,
V_265 , V_119 , 1 ) ;
break;
case V_84 :
V_55 = F_82 ( V_8 ,
0 , V_119 , V_121 , V_120 , V_266 , 1 ) ;
break;
case V_85 :
V_55 = F_93 ( V_8 , V_265 ,
V_119 , V_121 , V_289 ) ;
break;
default:
F_9 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return V_272 ;
}
if ( ! V_55 )
F_12 ( V_8 , V_54 ) ;
return V_55 ;
}
static T_2
F_96 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_302 = 0 , V_303 = 8 ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_238
L_239 , V_8 -> V_229 ) ;
return V_272 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_31 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_302 + 8 ) > ( V_8 -> V_229 - 8 ) )
break;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 56 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 48 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 40 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 32 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 24 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 16 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 8 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( V_2 -> V_110 & 0xff ) ;
V_302 += 8 ;
}
F_8 ( & V_10 -> V_28 . V_36 ) ;
V_3 [ 4 ] = ( ( V_302 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_302 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_302 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_302 & 0xff ) ;
F_69 ( V_8 ) ;
return 0 ;
}
static T_2
F_97 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_3 V_110 ;
T_1 V_302 = 16 ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_240
L_239 , V_8 -> V_229 ) ;
return V_272 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_10 -> V_44 ) ;
V_2 = V_10 -> V_109 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_302 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_302 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_302 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_302 & 0xff ) ;
if ( V_8 -> V_229 < 22 )
goto V_304;
if ( ( V_2 -> V_31 == V_34 ) ||
( V_2 -> V_31 == V_35 ) )
V_110 = 0 ;
else
V_110 = V_2 -> V_110 ;
V_3 [ 8 ] = ( ( V_110 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_110 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_110 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_110 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_110 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_110 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_110 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_110 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_162 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
}
V_304:
F_8 ( & V_10 -> V_44 ) ;
F_69 ( V_8 ) ;
return 0 ;
}
static T_2
F_98 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_4 V_302 = 8 ;
if ( V_8 -> V_229 < 6 ) {
F_9 ( L_241
L_242 , V_8 -> V_229 ) ;
return V_272 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_302 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_302 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_27 -> V_177 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
F_69 ( V_8 ) ;
return 0 ;
}
static T_2
F_99 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_278 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_147 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_1 V_305 = 0 , V_302 = 0 , V_306 , V_307 ;
T_1 V_303 = 8 ;
int V_308 = 0 ;
if ( V_8 -> V_229 < 8 ) {
F_9 ( L_243
L_239 , V_8 -> V_229 ) ;
return V_272 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_227 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_27 -> V_36 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_278 = V_2 -> V_111 ;
V_42 = V_2 -> V_111 -> V_42 ;
V_305 = 0 ;
F_28 ( & V_2 -> V_131 ) ;
F_29 () ;
F_8 ( & V_27 -> V_36 ) ;
V_307 = V_42 -> V_47 -> V_309 (
V_42 , V_278 , V_2 , & V_308 ) ;
if ( ( V_307 + V_302 ) > V_8 -> V_229 ) {
F_63 ( L_244
L_245 , V_8 -> V_229 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_35 () ;
break;
}
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 56 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 48 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 40 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 32 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 24 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 16 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_2 -> V_110 >> 8 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( V_2 -> V_110 & 0xff ) ;
V_303 += 4 ;
if ( V_2 -> V_135 )
V_3 [ V_303 ] = 0x02 ;
if ( V_2 -> V_30 ) {
V_3 [ V_303 ++ ] |= 0x01 ;
V_3 [ V_303 ++ ] = ( V_2 -> V_162 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
} else
V_303 += 2 ;
V_303 += 4 ;
if ( ! V_2 -> V_135 ) {
struct V_141 * V_142 = V_2 -> V_137 -> V_243 ;
V_3 [ V_303 ++ ] = ( ( V_142 -> V_235 >> 8 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( V_142 -> V_235 & 0xff ) ;
} else
V_303 += 2 ;
V_306 = V_42 -> V_47 -> V_310 ( V_42 ,
V_278 , V_2 , & V_308 , & V_3 [ V_303 + 4 ] ) ;
F_6 ( & V_27 -> V_36 ) ;
F_34 ( & V_2 -> V_131 ) ;
F_35 () ;
V_3 [ V_303 ++ ] = ( ( V_306 >> 24 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_306 >> 16 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( ( V_306 >> 8 ) & 0xff ) ;
V_3 [ V_303 ++ ] = ( V_306 & 0xff ) ;
V_305 = ( 24 + V_306 ) ;
V_303 += V_306 ;
V_302 += V_305 ;
}
F_8 ( & V_27 -> V_36 ) ;
V_3 [ 4 ] = ( ( V_302 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_302 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_302 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_302 & 0xff ) ;
F_69 ( V_8 ) ;
return 0 ;
}
T_2
F_100 ( struct V_7 * V_8 )
{
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_233
L_234
L_235 ) ;
return V_21 ;
}
switch ( V_8 -> V_15 [ 1 ] & 0x1f ) {
case V_311 :
V_55 = F_96 ( V_8 ) ;
break;
case V_312 :
V_55 = F_97 ( V_8 ) ;
break;
case V_313 :
V_55 = F_98 ( V_8 ) ;
break;
case V_314 :
V_55 = F_99 ( V_8 ) ;
break;
default:
F_9 ( L_246
L_16 , V_8 -> V_15 [ 1 ] & 0x1f ) ;
return V_272 ;
}
if ( ! V_55 )
F_12 ( V_8 , V_54 ) ;
return V_55 ;
}
T_2
F_101 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
T_2 V_55 ;
if ( ! V_8 -> V_14 )
return 0 ;
if ( V_10 -> V_315 -> V_316 & V_317 )
return 0 ;
if ( V_10 -> V_180 -> V_318 == V_319 )
return 0 ;
F_6 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_22 & V_46 )
V_55 = F_2 ( V_8 ) ;
else
V_55 = F_17 ( V_8 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
