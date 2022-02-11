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
F_21 ( & V_2 -> V_124 ) ;
F_21 ( & V_2 -> V_125 ) ;
F_21 ( & V_2 -> V_126 ) ;
F_21 ( & V_2 -> V_127 ) ;
F_21 ( & V_2 -> V_128 ) ;
F_22 ( & V_2 -> V_129 , 0 ) ;
V_2 -> V_111 = V_116 ;
V_2 -> V_130 = V_117 ;
V_2 -> V_131 = V_117 -> V_52 ;
V_2 -> V_132 = V_117 -> V_49 -> V_50 ;
V_2 -> V_110 = V_119 ;
V_2 -> V_133 = V_120 ;
V_2 -> V_134 = V_121 ;
V_2 -> V_135 = V_117 -> V_49 ;
if ( V_118 != NULL ) {
V_2 -> V_113 = F_23 ( V_118 ) ;
snprintf ( V_2 -> V_6 , V_136 , L_32 , V_118 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_24 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_59 * V_117 ,
unsigned char * V_118 ,
T_3 V_119 ,
int V_120 ,
int V_121 )
{
struct V_59 * V_137 ;
struct V_20 * V_138 ;
struct V_139 * V_140 , * V_141 ;
struct V_142 * V_143 = V_116 -> V_42 -> V_47 ;
struct V_1 * V_2 , * V_144 , * V_145 , * V_146 ;
int V_55 ;
V_2 = F_19 ( V_10 , V_116 , V_117 , V_118 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_120 )
return V_2 ;
F_6 ( & V_10 -> V_147 ) ;
F_25 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_26 ( & V_140 -> V_148 ) ;
F_27 () ;
F_8 ( & V_10 -> V_147 ) ;
F_28 ( & V_140 -> V_149 ) ;
F_29 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_137 -> V_150 )
continue;
V_138 = V_137 -> V_150 -> V_151 ;
if ( V_116 == V_138 )
continue;
if ( V_143 != V_138 -> V_42 -> V_47 )
continue;
if ( strcmp ( V_116 -> V_53 , V_138 -> V_53 ) )
continue;
F_26 ( & V_137 -> V_152 ) ;
F_27 () ;
F_30 ( & V_140 -> V_149 ) ;
V_55 = F_31 ( V_137 ) ;
if ( V_55 < 0 ) {
F_9 ( L_33
L_34 ) ;
F_32 ( & V_140 -> V_148 ) ;
F_33 () ;
F_32 ( & V_137 -> V_152 ) ;
F_33 () ;
goto V_43;
}
V_144 = F_19 ( V_10 ,
V_138 , V_137 , NULL ,
V_119 , V_120 , V_121 ) ;
if ( ! V_144 ) {
F_32 ( & V_140 -> V_148 ) ;
F_33 () ;
F_32 ( & V_137 -> V_152 ) ;
F_33 () ;
F_34 ( V_137 ) ;
goto V_43;
}
F_35 ( & V_144 -> V_128 ,
& V_2 -> V_127 ) ;
F_28 ( & V_140 -> V_149 ) ;
}
F_30 ( & V_140 -> V_149 ) ;
F_6 ( & V_10 -> V_147 ) ;
F_32 ( & V_140 -> V_148 ) ;
F_33 () ;
}
F_8 ( & V_10 -> V_147 ) ;
return V_2 ;
V_43:
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_36 ( & V_145 -> V_128 ) ;
F_34 ( V_145 -> V_130 ) ;
F_37 ( V_122 , V_145 ) ;
}
F_37 ( V_122 , V_2 ) ;
return NULL ;
}
int F_38 (
struct V_26 * V_27 ,
T_3 V_119 ,
unsigned char * V_153 ,
unsigned char * V_118 ,
T_1 V_52 ,
unsigned char * V_154 ,
T_4 V_155 ,
T_1 V_156 ,
int V_157 ,
int V_120 ,
T_5 type )
{
struct V_1 * V_2 ;
if ( ! V_153 || ! V_154 || ! V_119 ) {
F_9 ( L_35 ) ;
return - V_72 ;
}
V_2 = F_20 ( V_122 , V_158 ) ;
if ( ! V_2 ) {
F_9 ( L_31 ) ;
return - V_159 ;
}
F_21 ( & V_2 -> V_124 ) ;
F_21 ( & V_2 -> V_125 ) ;
F_21 ( & V_2 -> V_126 ) ;
F_21 ( & V_2 -> V_127 ) ;
F_21 ( & V_2 -> V_128 ) ;
F_22 ( & V_2 -> V_129 , 0 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_130 = NULL ;
V_2 -> V_131 = V_52 ;
V_2 -> V_132 = V_156 ;
V_2 -> V_110 = V_119 ;
V_2 -> V_133 = V_120 ;
V_2 -> V_134 = 1 ;
V_2 -> V_135 = NULL ;
V_2 -> V_160 = 0 ;
V_2 -> V_31 = type ;
if ( V_118 != NULL ) {
V_2 -> V_113 = F_23 ( V_118 ) ;
snprintf ( V_2 -> V_6 , V_136 , L_32 , V_118 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_161 , V_162 , L_32 , V_153 ) ;
snprintf ( V_2 -> V_163 , V_164 , L_32 , V_154 ) ;
V_2 -> V_165 = V_155 ;
V_2 -> V_30 = V_157 ;
F_35 ( & V_2 -> V_126 , & V_27 -> V_166 ) ;
F_11 ( L_36
L_37 , ( V_157 ) ? L_38 : L_29 ) ;
return 0 ;
}
static void F_39 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_20 * V_167 ,
struct V_1 * V_2 )
{
char V_168 [ V_169 ] ;
memset ( V_168 , 0 , V_169 ) ;
F_1 ( V_2 , V_168 , V_169 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_10 -> V_109 = V_2 ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_39
L_40 ,
V_40 -> V_47 -> V_48 () ,
F_15 ( V_2 -> V_31 ) ,
( V_2 -> V_133 ) ? 1 : 0 ) ;
F_11 ( L_41 ,
V_40 -> V_47 -> V_48 () , V_167 -> V_53 ,
V_168 ) ;
}
static int F_40 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_170 ,
T_1 V_156 ,
struct V_20 * V_116 ,
struct V_59 * V_117 )
{
struct V_1 * V_2 , * V_145 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char V_153 [ V_162 ] ;
unsigned char V_154 [ V_164 ] ;
T_4 V_155 ;
memset ( V_153 , 0 , V_162 ) ;
memset ( V_154 , 0 , V_164 ) ;
snprintf ( V_153 , V_162 , L_32 , V_116 -> V_53 ) ;
snprintf ( V_154 , V_164 , L_32 ,
V_40 -> V_47 -> V_171 ( V_40 ) ) ;
V_155 = V_40 -> V_47 -> V_172 ( V_40 ) ;
F_6 ( & V_27 -> V_173 ) ;
F_25 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_161 , V_153 ) &&
( V_2 -> V_131 == V_117 -> V_52 ) &&
! ( strcmp ( V_2 -> V_163 , V_154 ) ) &&
( V_2 -> V_165 == V_155 ) &&
( V_2 -> V_132 == V_156 ) ) {
V_2 -> V_111 = V_116 ;
V_2 -> V_130 = V_117 ;
V_2 -> V_135 = V_170 ;
F_36 ( & V_2 -> V_126 ) ;
F_8 ( & V_27 -> V_173 ) ;
F_41 ( V_10 , V_116 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_39 ( V_10 , V_40 ,
V_116 , V_2 ) ;
F_6 ( & V_27 -> V_173 ) ;
V_27 -> V_174 = 1 ;
}
}
F_8 ( & V_27 -> V_173 ) ;
return 0 ;
}
int F_42 (
struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_49 * V_170 ,
struct V_150 * V_175 )
{
struct V_20 * V_116 = V_175 -> V_151 ;
struct V_59 * V_117 = V_116 -> V_67 [ V_175 -> V_52 ] ;
if ( V_10 -> V_22 & V_46 )
return 0 ;
return F_40 ( V_10 , V_40 , V_170 ,
V_170 -> V_50 , V_116 , V_117 ) ;
}
static void F_43 (
struct V_142 * V_143 ,
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_1 * V_2 ,
enum V_176 V_176 )
{
struct V_39 * V_42 = V_116 -> V_42 ;
char V_168 [ V_169 ] ;
memset ( & V_168 [ 0 ] , 0 , V_169 ) ;
F_1 ( V_2 , V_168 , V_169 ) ;
F_11 ( L_42
L_43 , V_143 -> V_48 () , ( V_176 == V_177 ) ?
L_44 : ( V_176 == V_178 ) ?
L_45 : L_29 , V_116 -> V_53 ,
V_168 ) ;
F_11 ( L_46 ,
V_143 -> V_48 () , V_143 -> V_171 ( V_42 ) ,
V_143 -> V_172 ( V_42 ) ) ;
F_11 ( L_47
L_48 , V_143 -> V_48 () ,
( V_2 -> V_133 ) ? L_49 : L_50 ,
V_10 -> V_179 -> V_180 ) ;
F_11 ( L_51
L_52 , V_143 -> V_48 () ,
V_2 -> V_110 , V_2 -> V_181 ,
V_2 -> V_134 ) ;
}
static void F_41 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_1 * V_2 ,
enum V_176 V_176 ,
int V_182 )
{
struct V_142 * V_143 = V_116 -> V_42 -> V_47 ;
struct V_1 * V_145 , * V_146 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
V_2 -> V_181 = ( V_182 ) ?
V_10 -> V_28 . V_115 ++ :
F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_35 ( & V_2 -> V_124 , & V_27 -> V_37 ) ;
V_2 -> V_130 -> V_71 = 1 ;
F_43 ( V_143 , V_10 , V_116 , V_2 , V_176 ) ;
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_2 -> V_133 || V_182 )
return;
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_36 ( & V_145 -> V_128 ) ;
V_145 -> V_181 = F_18 ( V_10 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_35 ( & V_145 -> V_124 ,
& V_27 -> V_37 ) ;
V_145 -> V_130 -> V_71 = 1 ;
F_43 ( V_143 , V_10 ,
V_145 -> V_111 , V_145 ,
V_176 ) ;
F_8 ( & V_27 -> V_36 ) ;
F_34 ( V_145 -> V_130 ) ;
}
}
static int F_44 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
struct V_59 * V_117 ,
unsigned char * V_118 ,
T_3 V_119 ,
int V_120 ,
int V_121 ,
enum V_176 V_176 ,
int V_182 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_10 , V_116 , V_117 , V_118 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_2 )
return - V_183 ;
F_41 ( V_10 , V_116 , V_2 ,
V_176 , V_182 ) ;
return 0 ;
}
static struct V_1 * F_45 (
struct V_9 * V_10 ,
struct V_20 * V_116 ,
unsigned char * V_118 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_145 ;
struct V_39 * V_40 ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_111 != V_116 )
continue;
V_40 = V_2 -> V_111 -> V_42 ;
if ( ! V_2 -> V_5 ) {
if ( V_40 -> V_47 -> V_184 != NULL ) {
if ( V_10 -> V_185 . V_186 )
continue;
}
F_26 ( & V_2 -> V_129 ) ;
F_27 () ;
F_8 ( & V_27 -> V_36 ) ;
return V_2 ;
}
if ( ! V_118 )
continue;
if ( strcmp ( V_118 , V_2 -> V_6 ) )
continue;
F_26 ( & V_2 -> V_129 ) ;
F_27 () ;
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
unsigned char V_3 [ V_136 ] , * V_187 = NULL ;
if ( V_40 -> V_47 -> V_184 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_136 ) ;
V_40 -> V_47 -> V_184 ( V_13 , & V_3 [ 0 ] ,
V_136 ) ;
V_187 = & V_3 [ 0 ] ;
}
return F_45 ( V_10 , V_116 , V_187 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_129 ) ;
F_33 () ;
}
static int F_46 (
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
F_47 ( V_10 , V_116 , V_2 , 0 ) ;
V_55 = 1 ;
} else if ( V_2 -> V_133 &&
( ! strcmp ( V_30 -> V_111 -> V_53 ,
V_2 -> V_111 -> V_53 ) ) &&
( V_30 -> V_110 == V_2 -> V_110 ) ) {
F_9 ( L_53
L_54
L_55
L_56 , V_2 -> V_110 ) ;
V_55 = - V_183 ;
}
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static void F_48 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_188 * V_189 ,
int V_190 )
{
struct V_142 * V_143 =
V_2 -> V_111 -> V_42 -> V_47 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_168 [ V_169 ] ;
memset ( V_168 , 0 , V_169 ) ;
F_1 ( V_2 , V_168 , V_169 ) ;
V_2 -> V_130 -> V_71 = 0 ;
V_2 -> V_130 -> V_110 = 0 ;
F_36 ( & V_2 -> V_124 ) ;
if ( V_190 )
F_5 ( V_2 ) ;
while ( F_49 ( & V_2 -> V_129 ) != 0 ) {
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_57 ,
V_143 -> V_48 () ) ;
F_50 () ;
F_6 ( & V_27 -> V_36 ) ;
}
F_11 ( L_58
L_43 , V_143 -> V_48 () ,
V_2 -> V_111 -> V_53 ,
V_168 ) ;
F_11 ( L_47
L_48 , V_143 -> V_48 () ,
( V_2 -> V_133 ) ? L_49 : L_50 ,
V_10 -> V_179 -> V_180 ) ;
F_11 ( L_51
L_59 , V_143 -> V_48 () , V_2 -> V_110 ,
V_2 -> V_181 ) ;
if ( ! V_189 ) {
V_2 -> V_130 = NULL ;
V_2 -> V_111 = NULL ;
F_37 ( V_122 , V_2 ) ;
return;
}
F_35 ( & V_2 -> V_125 , V_189 ) ;
}
void F_51 (
struct V_9 * V_10 ,
struct V_20 * V_116 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_145 , * V_30 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ( V_30 != NULL ) &&
( V_30 -> V_111 == V_116 ) )
F_47 ( V_10 , V_116 , V_30 , 0 ) ;
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_111 != V_116 )
continue;
F_48 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
void F_52 (
struct V_9 * V_10 )
{
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_145 , * V_30 ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 != NULL ) {
struct V_20 * V_191 = V_30 -> V_111 ;
F_47 ( V_10 , V_191 ,
V_30 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_48 ( V_10 , V_2 , NULL , 0 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_6 ( & V_27 -> V_173 ) ;
F_25 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_36 ( & V_2 -> V_126 ) ;
F_37 ( V_122 , V_2 ) ;
}
F_8 ( & V_27 -> V_173 ) ;
}
static int F_53 ( struct V_39 * V_40 )
{
return F_54 ( V_40 -> V_47 -> V_192 ,
& V_40 -> V_193 . V_194 ) ;
}
static void F_55 ( struct V_39 * V_40 )
{
F_56 ( V_40 -> V_47 -> V_192 ,
& V_40 -> V_193 . V_194 ) ;
F_32 ( & V_40 -> V_195 ) ;
F_33 () ;
}
static int F_57 ( struct V_20 * V_116 )
{
struct V_39 * V_40 = V_116 -> V_42 ;
if ( V_116 -> V_196 )
return 0 ;
return F_54 ( V_40 -> V_47 -> V_192 ,
& V_116 -> V_197 . V_194 ) ;
}
static void F_58 ( struct V_20 * V_116 )
{
struct V_39 * V_40 = V_116 -> V_42 ;
if ( V_116 -> V_196 ) {
F_32 ( & V_116 -> V_198 ) ;
F_33 () ;
return;
}
F_56 ( V_40 -> V_47 -> V_192 ,
& V_116 -> V_197 . V_194 ) ;
F_32 ( & V_116 -> V_198 ) ;
F_33 () ;
}
static int F_31 ( struct V_59 * V_51 )
{
struct V_150 * V_175 = V_51 -> V_150 ;
struct V_20 * V_116 ;
struct V_39 * V_40 ;
if ( ! V_175 )
return 0 ;
V_116 = V_175 -> V_151 ;
V_40 = V_116 -> V_42 ;
return F_54 ( V_40 -> V_47 -> V_192 ,
& V_175 -> V_199 . V_194 ) ;
}
static void F_34 ( struct V_59 * V_51 )
{
struct V_150 * V_175 = V_51 -> V_150 ;
struct V_20 * V_116 ;
struct V_39 * V_40 ;
if ( ! V_175 ) {
F_32 ( & V_51 -> V_152 ) ;
F_33 () ;
return;
}
V_116 = V_175 -> V_151 ;
V_40 = V_116 -> V_42 ;
F_56 ( V_40 -> V_47 -> V_192 ,
& V_175 -> V_199 . V_194 ) ;
F_32 ( & V_51 -> V_152 ) ;
F_33 () ;
}
static T_2
F_59 (
struct V_7 * V_8 ,
struct V_39 * V_40 ,
unsigned char * V_200 ,
T_3 V_119 ,
int V_120 ,
int V_121 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_139 * V_201 ;
struct V_39 * V_202 = NULL , * V_203 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_20 * V_204 = NULL ;
struct V_59 * V_205 = NULL , * V_206 ;
struct V_1 * V_207 , * V_208 , * V_209 ;
struct V_1 * V_145 , * V_146 ;
F_60 ( V_210 ) ;
struct V_211 * V_212 , * V_213 , * V_214 ;
struct V_142 * V_215 ;
unsigned char * V_3 ;
unsigned char * V_216 , * V_217 = NULL , V_218 , V_219 ;
char * V_220 = NULL , V_221 [ 64 ] , V_168 [ V_169 ] ;
T_2 V_55 ;
T_1 V_222 , V_223 = 0 ;
int V_224 ;
T_1 V_225 = 0 ;
memset ( V_221 , 0 , 64 ) ;
V_206 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
V_212 = F_61 ( sizeof( struct V_211 ) , V_158 ) ;
if ( ! V_212 ) {
F_9 ( L_60 ) ;
return V_226 ;
}
F_21 ( & V_212 -> V_227 ) ;
V_212 -> V_202 = V_40 ;
V_212 -> V_204 = V_14 -> V_20 ;
V_212 -> V_205 = V_206 ;
V_208 = F_24 ( V_8 -> V_11 ,
V_14 -> V_20 , V_206 , V_200 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_208 ) {
F_62 ( V_212 ) ;
return V_226 ;
}
V_212 -> V_207 = V_208 ;
V_212 -> V_224 = 1 ;
F_35 ( & V_212 -> V_227 , & V_210 ) ;
if ( V_8 -> V_228 < 28 ) {
F_63 ( L_61
L_62 , V_8 -> V_228 ) ;
V_55 = V_229 ;
goto V_43;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_226 ;
goto V_43;
}
V_222 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_222 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_222 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_222 |= V_3 [ 27 ] & 0xff ;
if ( ( V_222 + 28 ) != V_8 -> V_228 ) {
F_9 ( L_63
L_64 , V_222 ,
V_8 -> V_228 ) ;
V_55 = V_229 ;
goto V_230;
}
V_216 = & V_3 [ 28 ] ;
while ( V_222 > 0 ) {
V_218 = ( V_216 [ 0 ] & 0x0f ) ;
V_202 = NULL ;
F_6 ( & V_10 -> V_147 ) ;
F_29 (tmp_port, &dev->dev_sep_list, sep_list) {
V_203 = V_201 -> V_231 ;
if ( ! V_203 )
continue;
V_215 = V_203 -> V_47 ;
if ( ! V_215 )
continue;
if ( ! V_215 -> V_232 ||
! V_215 -> V_233 )
continue;
V_219 = V_215 -> V_232 ( V_203 ) ;
if ( V_219 != V_218 )
continue;
V_225 = V_201 -> V_234 ;
V_217 = V_215 -> V_233 (
V_203 , ( const char * ) V_216 , & V_223 ,
& V_220 ) ;
if ( ! V_217 )
continue;
F_26 ( & V_203 -> V_195 ) ;
F_27 () ;
F_8 ( & V_10 -> V_147 ) ;
if ( F_53 ( V_203 ) ) {
F_9 ( L_65
L_66 ) ;
F_32 ( & V_203 -> V_195 ) ;
F_33 () ;
V_55 = V_226 ;
goto V_230;
}
F_65 ( & V_203 -> V_235 ) ;
V_204 = F_66 (
V_203 , V_217 ) ;
if ( V_204 ) {
F_26 ( & V_204 -> V_198 ) ;
F_27 () ;
}
F_67 ( & V_203 -> V_235 ) ;
if ( ! V_204 ) {
F_55 ( V_203 ) ;
F_6 ( & V_10 -> V_147 ) ;
continue;
}
if ( F_57 ( V_204 ) ) {
F_9 ( L_67
L_68 ) ;
F_32 ( & V_204 -> V_198 ) ;
F_33 () ;
F_55 ( V_203 ) ;
V_55 = V_226 ;
goto V_230;
}
V_202 = V_203 ;
F_11 ( L_69
L_70 ,
V_202 -> V_47 -> V_48 () ,
V_204 -> V_53 , V_225 ) ;
F_6 ( & V_10 -> V_147 ) ;
break;
}
F_8 ( & V_10 -> V_147 ) ;
if ( ! V_202 ) {
F_9 ( L_71
L_72 ) ;
V_55 = V_229 ;
goto V_230;
}
F_11 ( L_73
L_74 ,
V_202 -> V_47 -> V_48 () , V_8 -> V_228 ,
V_222 , V_223 , V_217 , V_220 ) ;
if ( V_223 > V_222 ) {
F_9 ( L_75
L_76 , V_223 , V_216 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
V_55 = V_229 ;
goto V_230;
}
V_205 = F_68 ( V_204 ,
V_225 ) ;
if ( ! V_205 ) {
F_9 ( L_77
L_78 ,
V_202 -> V_47 -> V_48 () ,
V_225 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
V_55 = V_229 ;
goto V_230;
}
if ( F_31 ( V_205 ) ) {
F_9 ( L_79
L_80 ) ;
F_32 ( & V_205 -> V_152 ) ;
F_33 () ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
V_55 = V_226 ;
goto V_230;
}
F_11 ( L_81
L_82 ,
V_202 -> V_47 -> V_48 () ,
V_204 -> V_53 , V_205 -> V_52 ) ;
V_209 = F_45 ( V_10 , V_204 ,
V_220 ) ;
if ( V_209 ) {
F_5 ( V_209 ) ;
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
V_216 += V_223 ;
V_222 -= V_223 ;
V_223 = 0 ;
continue;
}
V_212 = F_61 ( sizeof( struct V_211 ) ,
V_158 ) ;
if ( ! V_212 ) {
F_9 ( L_60 ) ;
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
V_55 = V_226 ;
goto V_230;
}
F_21 ( & V_212 -> V_227 ) ;
V_212 -> V_202 = V_202 ;
V_212 -> V_204 = V_204 ;
V_212 -> V_205 = V_205 ;
V_207 = F_24 ( V_8 -> V_11 ,
V_204 , V_205 , V_220 ,
V_119 , V_120 , V_121 ) ;
if ( ! V_207 ) {
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
F_62 ( V_212 ) ;
V_55 = V_229 ;
goto V_230;
}
V_212 -> V_207 = V_207 ;
F_35 ( & V_212 -> V_227 , & V_210 ) ;
V_216 += V_223 ;
V_222 -= V_223 ;
V_223 = 0 ;
}
F_69 ( V_8 ) ;
F_25 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_202 = V_213 -> V_202 ;
V_204 = V_213 -> V_204 ;
V_205 = V_213 -> V_205 ;
V_207 = V_213 -> V_207 ;
V_224 = V_213 -> V_224 ;
F_36 ( & V_213 -> V_227 ) ;
F_62 ( V_213 ) ;
memset ( V_168 , 0 , V_169 ) ;
F_1 ( V_207 , V_168 , V_169 ) ;
F_41 ( V_8 -> V_11 , V_204 ,
V_207 , 0 , 0 ) ;
F_11 ( L_83
L_84
L_85 , V_202 -> V_47 -> V_48 () ,
V_204 -> V_53 , V_168 , V_205 -> V_52 ) ;
if ( V_224 )
continue;
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
}
return 0 ;
V_230:
F_69 ( V_8 ) ;
V_43:
F_25 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_202 = V_213 -> V_202 ;
V_204 = V_213 -> V_204 ;
V_205 = V_213 -> V_205 ;
V_207 = V_213 -> V_207 ;
V_224 = V_213 -> V_224 ;
F_36 ( & V_213 -> V_227 ) ;
F_62 ( V_213 ) ;
F_25 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_36 ( & V_145 -> V_128 ) ;
F_34 ( V_145 -> V_130 ) ;
F_37 ( V_122 , V_145 ) ;
}
F_37 ( V_122 , V_207 ) ;
if ( V_224 )
continue;
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_202 ) ;
}
return V_55 ;
}
static int F_70 (
struct V_9 * V_10 ,
unsigned char * V_3 ,
T_1 V_236 )
{
struct V_49 * V_170 ;
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned char V_237 [ 512 ] , V_238 [ 32 ] ;
T_6 V_239 = 0 ;
int V_240 = 0 ;
int V_55 = 0 ;
F_6 ( & V_10 -> V_44 ) ;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_29 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
V_237 [ 0 ] = '\0' ;
V_238 [ 0 ] = '\0' ;
V_40 = V_2 -> V_111 -> V_42 ;
V_170 = V_2 -> V_135 ;
if ( V_2 -> V_5 )
snprintf ( V_238 , 32 , L_86 ,
V_2 -> V_6 ) ;
if ( V_10 -> V_109 == V_2 ) {
snprintf ( V_237 , 512 , L_87
L_88
L_89
L_90
L_91
L_92
L_93 , V_240 ,
V_40 -> V_47 -> V_48 () ,
V_2 -> V_111 -> V_53 , V_238 ,
V_2 -> V_110 , V_2 -> V_31 ,
V_2 -> V_160 , V_2 -> V_133 ,
V_2 -> V_131 ) ;
} else {
snprintf ( V_237 , 512 , L_94
L_95
L_96
L_97 ,
V_240 , V_40 -> V_47 -> V_48 () ,
V_2 -> V_111 -> V_53 , V_238 ,
V_2 -> V_110 , V_2 -> V_133 ,
V_2 -> V_131 ) ;
}
if ( ( V_239 + strlen ( V_237 ) >= V_236 ) ) {
F_9 ( L_98
L_99 ) ;
V_55 = - V_241 ;
goto V_43;
}
V_239 += sprintf ( V_3 + V_239 , L_32 , V_237 ) ;
snprintf ( V_237 , 512 , L_100
L_101
L_102 , V_40 -> V_47 -> V_48 () ,
V_40 -> V_47 -> V_171 ( V_40 ) ,
V_40 -> V_47 -> V_172 ( V_40 ) ,
V_170 -> V_242 -> V_234 , V_170 -> V_50 , V_240 ) ;
if ( ( V_239 + strlen ( V_237 ) >= V_236 ) ) {
F_9 ( L_98
L_99 ) ;
V_55 = - V_241 ;
goto V_43;
}
V_239 += sprintf ( V_3 + V_239 , L_32 , V_237 ) ;
V_240 ++ ;
}
if ( ! V_240 )
V_239 += sprintf ( V_3 + V_239 , L_103 ) ;
V_43:
F_8 ( & V_10 -> V_28 . V_36 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
static int F_71 (
struct V_9 * V_10 ,
unsigned char * V_3 )
{
struct V_243 * V_244 = & V_10 -> V_243 ;
struct V_245 * V_245 ;
int V_246 = V_247 | V_248 | V_249 ;
char V_250 [ 512 ] ;
T_1 V_236 ;
int V_55 ;
memset ( V_250 , 0 , 512 ) ;
if ( strlen ( & V_244 -> V_251 [ 0 ] ) >= 512 ) {
F_9 ( L_104
L_105 ) ;
return - V_241 ;
}
snprintf ( V_250 , 512 , L_106 , & V_244 -> V_251 [ 0 ] ) ;
V_245 = F_72 ( V_250 , V_246 , 0600 ) ;
if ( F_73 ( V_245 ) ) {
F_9 ( L_107
L_80 , V_250 ) ;
return F_74 ( V_245 ) ;
}
V_236 = ( strlen ( V_3 ) + 1 ) ;
V_55 = F_75 ( V_245 , V_3 , V_236 , 0 ) ;
if ( V_55 < 0 )
F_11 ( L_108 , V_250 ) ;
F_76 ( V_245 ) ;
return V_55 ? - V_252 : 0 ;
}
static T_2 F_77 ( struct V_9 * V_10 , bool V_121 )
{
unsigned char * V_3 ;
int V_41 ;
if ( ! V_121 ) {
char * V_253 = L_109 ;
V_41 = F_71 ( V_10 , V_253 ) ;
V_10 -> V_28 . V_174 = 0 ;
F_11 ( L_110 ) ;
if ( V_41 )
return V_226 ;
return 0 ;
}
V_3 = F_61 ( V_254 , V_158 ) ;
if ( ! V_3 )
return V_255 ;
V_41 = F_70 ( V_10 , V_3 , V_254 ) ;
if ( V_41 < 0 ) {
F_62 ( V_3 ) ;
return V_255 ;
}
V_41 = F_71 ( V_10 , V_3 ) ;
if ( V_41 != 0 ) {
F_9 ( L_111 ) ;
F_62 ( V_3 ) ;
return V_226 ;
}
V_10 -> V_28 . V_174 = 1 ;
F_62 ( V_3 ) ;
F_11 ( L_112 ) ;
return 0 ;
}
static T_2
F_78 ( struct V_7 * V_8 , T_3 V_256 , T_3 V_119 ,
bool V_121 , bool V_120 , bool V_257 , enum V_176 V_176 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_51 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_258 , * V_145 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char V_238 [ V_136 ] , * V_187 = NULL ;
T_2 V_55 = V_259 ;
int V_260 = 0 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_113 ) ;
return V_226 ;
}
V_42 = V_14 -> V_42 ;
V_51 = V_14 -> V_20 -> V_67 [ V_8 -> V_68 ] ;
if ( V_42 -> V_47 -> V_184 ) {
memset ( & V_238 [ 0 ] , 0 , V_136 ) ;
V_42 -> V_47 -> V_184 ( V_14 , & V_238 [ 0 ] ,
V_136 ) ;
V_187 = & V_238 [ 0 ] ;
}
V_2 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_2 ) {
if ( V_256 ) {
F_63 ( L_114
L_115 ) ;
return V_21 ;
}
if ( ! V_119 )
return 0 ;
if ( ! V_257 ) {
if ( F_44 ( V_8 -> V_11 ,
V_14 -> V_20 , V_51 , V_187 ,
V_119 , V_120 , V_121 ,
V_176 , 0 ) ) {
F_9 ( L_116
L_117 ) ;
return V_229 ;
}
} else {
V_55 = F_59 ( V_8 , V_42 ,
V_187 , V_119 , V_120 , V_121 ) ;
if ( V_55 != 0 )
return V_55 ;
}
return F_77 ( V_10 , V_121 ) ;
}
if ( ( V_176 == REGISTER ) && ( V_256 != V_2 -> V_110 ) ) {
F_9 ( L_118
L_119
L_120
L_121 , V_256 ,
V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_43;
}
if ( V_257 ) {
F_9 ( L_122
L_123 ) ;
V_55 = V_229 ;
goto V_43;
}
if ( V_2 -> V_133 && ! V_120 ) {
F_9 ( L_124
L_125
L_126 ) ;
V_55 = V_261 ;
goto V_43;
}
if ( V_119 ) {
V_2 -> V_181 = F_18 ( V_8 -> V_11 ) ;
V_2 -> V_110 = V_119 ;
F_11 ( L_127
L_128
L_59 , V_8 -> V_262 -> V_48 () ,
( V_176 == V_178 ) ? L_45 : L_29 ,
V_2 -> V_111 -> V_53 ,
V_2 -> V_110 , V_2 -> V_181 ) ;
} else {
V_260 = F_46 (
V_8 -> V_11 , V_2 ) ;
if ( V_260 < 0 ) {
V_55 = V_21 ;
goto V_43;
}
F_6 ( & V_27 -> V_36 ) ;
if ( V_2 -> V_133 ) {
F_25 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_258 -> V_133 )
continue;
if ( V_258 -> V_110 != V_256 )
continue;
if ( V_2 == V_258 )
continue;
if ( strcmp ( V_2 -> V_111 -> V_53 ,
V_258 -> V_111 -> V_53 ) )
continue;
F_48 ( V_10 ,
V_258 , NULL , 0 ) ;
}
}
F_48 ( V_8 -> V_11 , V_2 , NULL , 1 ) ;
if ( V_260 &&
( V_2 -> V_31 == V_32 ||
V_2 -> V_31 == V_33 ) ) {
F_29 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_79 (
V_258 -> V_111 ,
V_258 -> V_131 ,
0x2A ,
V_263 ) ;
}
}
F_8 ( & V_27 -> V_36 ) ;
}
V_55 = F_77 ( V_10 , V_121 ) ;
V_43:
F_5 ( V_2 ) ;
return V_55 ;
}
unsigned char * F_15 ( int type )
{
switch ( type ) {
case V_69 :
return L_129 ;
case V_70 :
return L_130 ;
case V_32 :
return L_131 ;
case V_33 :
return L_132 ;
case V_34 :
return L_133 ;
case V_35 :
return L_134 ;
default:
break;
}
return L_135 ;
}
static T_2
F_80 ( struct V_7 * V_8 , int type , int V_264 , T_3 V_256 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
char V_168 [ V_169 ] ;
T_2 V_55 ;
memset ( V_168 , 0 , V_169 ) ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_113 ) ;
return V_226 ;
}
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_136
L_137 ) ;
return V_226 ;
}
if ( V_256 != V_2 -> V_110 ) {
F_9 ( L_138
L_139
L_121 , V_256 , V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_265;
}
if ( V_264 != V_266 ) {
F_9 ( L_140 , V_264 ) ;
V_55 = V_229 ;
goto V_265;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 ) {
if ( V_30 != V_2 ) {
struct V_20 * V_191 = V_30 -> V_111 ;
F_9 ( L_141
L_142
L_143 ,
V_8 -> V_262 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_191 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_265;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_160 != V_264 ) ) {
struct V_20 * V_191 = V_30 -> V_111 ;
F_9 ( L_141
L_144
L_145
L_4 ,
V_8 -> V_262 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_191 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_265;
}
F_8 ( & V_10 -> V_44 ) ;
V_55 = 0 ;
goto V_265;
}
V_2 -> V_160 = V_264 ;
V_2 -> V_31 = type ;
V_2 -> V_30 = 1 ;
V_10 -> V_109 = V_2 ;
F_1 ( V_2 , V_168 , V_169 ) ;
F_11 ( L_146
L_147 ,
V_8 -> V_262 -> V_48 () , F_15 ( type ) ,
( V_2 -> V_133 ) ? 1 : 0 ) ;
F_11 ( L_41 ,
V_8 -> V_262 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_168 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_174 )
F_77 ( V_8 -> V_11 , true ) ;
V_55 = 0 ;
V_265:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_81 ( struct V_7 * V_8 , int type , int V_264 ,
T_3 V_256 )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_80 ( V_8 , type , V_264 , V_256 ) ;
default:
F_9 ( L_148
L_149 , type ) ;
return V_261 ;
}
}
static void F_47 (
struct V_9 * V_10 ,
struct V_20 * V_267 ,
struct V_1 * V_2 ,
int V_268 )
{
struct V_142 * V_143 = V_267 -> V_42 -> V_47 ;
char V_168 [ V_169 ] ;
memset ( V_168 , 0 , V_169 ) ;
F_1 ( V_2 , V_168 , V_169 ) ;
V_10 -> V_109 = NULL ;
F_11 ( L_150
L_147 ,
V_143 -> V_48 () , ( V_268 ) ? L_151 : L_152 ,
F_15 ( V_2 -> V_31 ) ,
( V_2 -> V_133 ) ? 1 : 0 ) ;
F_11 ( L_153 ,
V_143 -> V_48 () , V_267 -> V_53 ,
V_168 ) ;
V_2 -> V_30 = V_2 -> V_31 = V_2 -> V_160 = 0 ;
}
static T_2
F_82 ( struct V_7 * V_8 , int type , int V_264 ,
T_3 V_256 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_1 * V_2 , * V_258 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
int V_63 = 0 ;
T_2 V_55 = 0 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_113 ) ;
return V_226 ;
}
V_2 = F_4 ( V_10 , V_14 -> V_20 , V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_136
L_154 ) ;
return V_226 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ! V_30 ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_265;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) )
V_63 = 1 ;
if ( ( V_63 == 0 ) && ( V_30 != V_2 ) ) {
F_8 ( & V_10 -> V_44 ) ;
goto V_265;
}
if ( V_256 != V_2 -> V_110 ) {
F_9 ( L_155
L_139
L_121 , V_256 , V_2 -> V_110 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_265;
}
if ( ( V_30 -> V_31 != type ) ||
( V_30 -> V_160 != V_264 ) ) {
struct V_20 * V_191 = V_30 -> V_111 ;
F_9 ( L_156
L_157
L_158
L_143 ,
V_8 -> V_262 -> V_48 () ,
V_14 -> V_20 -> V_53 ,
V_191 -> V_42 -> V_47 -> V_48 () ,
V_30 -> V_111 -> V_53 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_265;
}
F_47 ( V_10 , V_14 -> V_20 ,
V_2 , 1 ) ;
F_8 ( & V_10 -> V_44 ) ;
if ( ( type != V_32 ) &&
( type != V_33 ) &&
( type != V_34 ) &&
( type != V_35 ) ) {
goto V_269;
}
F_6 ( & V_27 -> V_36 ) ;
F_29 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_258 == V_2 )
continue;
F_79 ( V_258 -> V_111 ,
V_258 -> V_131 ,
0x2A , V_263 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
V_269:
if ( V_27 -> V_174 )
F_77 ( V_8 -> V_11 , true ) ;
V_265:
F_5 ( V_2 ) ;
return V_55 ;
}
static T_2
F_83 ( struct V_7 * V_8 , T_3 V_256 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_111 ;
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
struct V_1 * V_2 , * V_145 , * V_270 , * V_30 ;
T_1 V_131 = 0 ;
int V_271 = 0 ;
V_270 = F_4 ( V_8 -> V_11 ,
V_14 -> V_20 , V_14 ) ;
if ( ! V_270 ) {
F_9 ( L_136
L_159 ) ;
return V_226 ;
}
if ( V_256 != V_270 -> V_110 ) {
F_9 ( L_118
L_119
L_120
L_121 , V_256 , V_270 -> V_110 ) ;
F_5 ( V_270 ) ;
return V_21 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 ) {
struct V_20 * V_191 = V_30 -> V_111 ;
F_47 ( V_10 , V_191 ,
V_30 , 0 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_271 = ( V_270 == V_2 ) ? 1 : 0 ;
V_111 = V_2 -> V_111 ;
V_131 = V_2 -> V_131 ;
F_48 ( V_10 , V_2 , NULL ,
V_271 ) ;
if ( ! V_271 )
F_79 ( V_111 , V_131 ,
0x2A , V_272 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_11 ( L_160 ,
V_8 -> V_262 -> V_48 () ) ;
F_77 ( V_8 -> V_11 , false ) ;
F_18 ( V_10 ) ;
return 0 ;
}
static void F_84 (
struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_188 * V_189 ,
int type ,
int V_264 ,
enum V_273 V_273 )
{
struct V_20 * V_116 = V_2 -> V_111 ;
struct V_142 * V_143 = V_116 -> V_42 -> V_47 ;
char V_168 [ V_169 ] ;
memset ( V_168 , 0 , V_169 ) ;
F_1 ( V_2 , V_168 , V_169 ) ;
if ( V_10 -> V_109 )
F_47 ( V_10 , V_116 ,
V_10 -> V_109 , 0 ) ;
V_10 -> V_109 = V_2 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = type ;
V_2 -> V_160 = V_264 ;
F_11 ( L_161
L_147 ,
V_143 -> V_48 () , ( V_273 == V_274 ) ? L_162 : L_29 ,
F_15 ( type ) ,
( V_2 -> V_133 ) ? 1 : 0 ) ;
F_11 ( L_163 ,
V_143 -> V_48 () , ( V_273 == V_274 ) ? L_162 : L_29 ,
V_116 -> V_53 , V_168 ) ;
if ( V_189 )
F_35 ( & V_2 -> V_125 ,
V_189 ) ;
}
static void F_85 (
struct V_188 * V_189 ,
struct V_1 * V_275 )
{
struct V_1 * V_2 , * V_145 ;
F_25 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_36 ( & V_2 -> V_125 ) ;
if ( V_275 == V_2 )
continue;
if ( V_2 -> V_30 ) {
F_63 ( L_164 ) ;
continue;
}
V_2 -> V_130 = NULL ;
V_2 -> V_111 = NULL ;
F_37 ( V_122 , V_2 ) ;
}
}
static T_2
F_86 ( struct V_7 * V_8 , int type , int V_264 , T_3 V_256 ,
T_3 V_119 , enum V_273 V_273 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_111 ;
struct V_12 * V_14 = V_8 -> V_14 ;
F_60 ( V_189 ) ;
struct V_1 * V_2 , * V_145 , * V_270 , * V_30 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
T_1 V_131 = 0 ;
int V_63 = 0 , V_271 = 0 , V_276 = 0 ;
int V_277 = 0 , V_278 = 0 ;
if ( ! V_14 )
return V_226 ;
V_270 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_270 ) {
F_9 ( L_136
L_165 ,
( V_273 == V_274 ) ? L_162 : L_29 ) ;
return V_21 ;
}
if ( V_270 -> V_110 != V_256 ) {
F_5 ( V_270 ) ;
return V_21 ;
}
if ( V_264 != V_266 ) {
F_9 ( L_140 , V_264 ) ;
F_5 ( V_270 ) ;
return V_229 ;
}
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( V_30 &&
( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) )
V_63 = 1 ;
if ( ! V_63 && ! V_119 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_270 ) ;
return V_229 ;
}
if ( ! V_30 || ( V_30 -> V_110 != V_119 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_63 ) {
if ( V_2 -> V_110 != V_119 )
continue;
V_271 = ( V_270 == V_2 ) ? 1 : 0 ;
V_111 = V_2 -> V_111 ;
V_131 = V_2 -> V_131 ;
F_48 ( V_10 , V_2 ,
( V_273 == V_274 ) ? & V_189 :
NULL , V_271 ) ;
V_276 ++ ;
} else {
if ( ( V_119 ) &&
( V_2 -> V_110 != V_119 ) )
continue;
V_271 = ( V_270 == V_2 ) ? 1 : 0 ;
if ( V_271 )
continue;
V_111 = V_2 -> V_111 ;
V_131 = V_2 -> V_131 ;
F_48 ( V_10 , V_2 ,
( V_273 == V_274 ) ? & V_189 :
NULL , 0 ) ;
V_276 ++ ;
}
if ( ! V_271 )
F_79 ( V_111 ,
V_131 , 0x2A ,
V_279 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
if ( ! V_276 ) {
F_8 ( & V_10 -> V_44 ) ;
F_5 ( V_270 ) ;
return V_21 ;
}
if ( V_30 && V_63 && ! ( V_119 ) ) {
F_84 ( V_10 , V_270 ,
( V_273 == V_274 ) ? & V_189 : NULL ,
type , V_264 , V_273 ) ;
if ( V_273 == V_274 )
F_85 (
& V_189 , V_270 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( V_27 -> V_174 )
F_77 ( V_8 -> V_11 , true ) ;
F_5 ( V_270 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
V_277 = V_30 -> V_31 ;
V_278 = V_30 -> V_160 ;
if ( V_270 != V_30 )
F_47 ( V_10 ,
V_30 -> V_111 ,
V_10 -> V_109 , 0 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_271 = ( V_270 == V_2 ) ? 1 : 0 ;
if ( V_271 )
continue;
if ( V_2 -> V_110 != V_119 )
continue;
V_111 = V_2 -> V_111 ;
V_131 = V_2 -> V_131 ;
F_48 ( V_10 , V_2 ,
( V_273 == V_274 ) ? & V_189 : NULL ,
V_271 ) ;
F_79 ( V_111 , V_131 , 0x2A ,
V_279 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
F_84 ( V_10 , V_270 ,
( V_273 == V_274 ) ? & V_189 : NULL ,
type , V_264 , V_273 ) ;
if ( ( V_277 != type ) || ( V_278 != V_264 ) ) {
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_271 = ( V_270 == V_2 ) ? 1 : 0 ;
if ( V_271 )
continue;
F_79 ( V_2 -> V_111 ,
V_2 -> V_131 , 0x2A ,
V_263 ) ;
}
F_8 ( & V_27 -> V_36 ) ;
}
F_8 ( & V_10 -> V_44 ) ;
if ( V_273 == V_274 ) {
F_87 ( V_10 , NULL , & V_189 , V_8 ) ;
F_85 ( & V_189 ,
V_270 ) ;
}
if ( V_27 -> V_174 )
F_77 ( V_8 -> V_11 , true ) ;
F_5 ( V_270 ) ;
F_18 ( V_8 -> V_11 ) ;
return 0 ;
}
static T_2
F_88 ( struct V_7 * V_8 , int type , int V_264 ,
T_3 V_256 , T_3 V_119 , enum V_273 V_273 )
{
switch ( type ) {
case V_69 :
case V_70 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_86 ( V_8 , type , V_264 , V_256 ,
V_119 , V_273 ) ;
default:
F_9 ( L_166
L_167 , ( V_273 == V_274 ) ? L_162 : L_29 , type ) ;
return V_261 ;
}
}
static T_2
F_89 ( struct V_7 * V_8 , T_3 V_256 ,
T_3 V_119 , int V_121 , int V_280 )
{
struct V_12 * V_14 = V_8 -> V_14 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_205 = NULL ;
struct V_49 * V_49 = V_8 -> V_49 ;
struct V_20 * V_191 , * V_111 , * V_204 = NULL ;
struct V_139 * V_139 ;
struct V_39 * V_42 , * V_281 = NULL ;
struct V_142 * V_282 = NULL , * V_283 ;
struct V_1 * V_2 , * V_30 , * V_207 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
unsigned char * V_284 ;
char * V_220 = NULL , V_221 [ 64 ] , V_168 [ V_169 ] ;
T_1 V_223 , V_285 ;
int V_286 = 0 , type , V_264 , V_287 ;
T_2 V_55 ;
unsigned short V_288 ;
unsigned char V_218 ;
if ( ! V_14 || ! V_49 ) {
F_9 ( L_113 ) ;
return V_226 ;
}
memset ( V_221 , 0 , 64 ) ;
memset ( V_168 , 0 , V_169 ) ;
V_42 = V_14 -> V_42 ;
V_283 = V_42 -> V_47 ;
V_2 = F_4 ( V_8 -> V_11 , V_14 -> V_20 ,
V_14 ) ;
if ( ! V_2 ) {
F_9 ( L_168
L_169 ) ;
return V_226 ;
}
if ( V_256 != V_2 -> V_110 ) {
F_63 ( L_170
L_171
L_172 , V_256 , V_2 -> V_110 ) ;
V_55 = V_21 ;
goto V_265;
}
if ( ! V_119 ) {
F_63 ( L_173
L_174 ) ;
V_55 = V_229 ;
goto V_265;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_226 ;
goto V_265;
}
V_288 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_288 |= V_3 [ 19 ] & 0xff ;
V_223 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_223 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_223 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_223 |= V_3 [ 23 ] & 0xff ;
F_69 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_223 + 24 ) != V_8 -> V_228 ) {
F_9 ( L_175
L_64 , V_223 ,
V_8 -> V_228 ) ;
V_55 = V_229 ;
goto V_265;
}
F_6 ( & V_10 -> V_147 ) ;
F_29 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_139 -> V_234 != V_288 )
continue;
V_281 = V_139 -> V_231 ;
if ( ! V_281 )
continue;
V_282 = V_281 -> V_47 ;
if ( ! V_282 )
continue;
F_26 ( & V_281 -> V_195 ) ;
F_27 () ;
F_8 ( & V_10 -> V_147 ) ;
if ( F_53 ( V_281 ) ) {
F_9 ( L_176
L_177 ) ;
F_32 ( & V_281 -> V_195 ) ;
F_33 () ;
V_55 = V_226 ;
goto V_265;
}
F_6 ( & V_10 -> V_147 ) ;
break;
}
F_8 ( & V_10 -> V_147 ) ;
if ( ! V_281 || ! V_282 ) {
F_9 ( L_178
L_179
L_180 , V_288 ) ;
V_55 = V_229 ;
goto V_265;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 ) {
V_55 = V_226 ;
goto V_265;
}
V_218 = ( V_3 [ 24 ] & 0x0f ) ;
F_11 ( L_181
L_149 , V_218 ) ;
if ( V_218 != V_282 -> V_232 ( V_281 ) ) {
F_9 ( L_170
L_182
L_183 , V_218 ,
V_282 -> V_232 ( V_281 ) ,
V_282 -> V_48 () ) ;
V_55 = V_229 ;
goto V_43;
}
if ( V_282 -> V_233 == NULL ) {
F_9 ( L_184
L_185
L_186 ) ;
V_55 = V_226 ;
goto V_43;
}
V_284 = V_282 -> V_233 ( V_281 ,
( const char * ) & V_3 [ 24 ] , & V_285 , & V_220 ) ;
if ( ! V_284 ) {
F_9 ( L_178
L_187 ) ;
V_55 = V_229 ;
goto V_43;
}
F_69 ( V_8 ) ;
V_3 = NULL ;
F_11 ( L_188
L_189 , V_282 -> V_48 () , ( V_220 != NULL ) ?
L_190 : L_191 , V_284 , ( V_220 != NULL ) ?
V_220 : L_29 ) ;
V_111 = V_2 -> V_111 ;
V_287 = ( ! strcmp ( V_284 ,
V_111 -> V_53 ) ) ? 1 : 0 ;
if ( ! V_287 )
goto V_289;
if ( ! V_220 || ! V_2 -> V_5 ) {
F_9 ( L_192
L_193 , V_284 ,
V_111 -> V_53 ) ;
V_55 = V_229 ;
goto V_43;
}
if ( ! strcmp ( V_220 , V_2 -> V_6 ) ) {
F_9 ( L_194
L_195 ,
V_284 , V_220 , V_111 -> V_53 ,
V_2 -> V_6 ) ;
V_55 = V_229 ;
goto V_43;
}
V_289:
F_65 ( & V_281 -> V_235 ) ;
V_204 = F_66 ( V_281 ,
V_284 ) ;
if ( V_204 ) {
F_26 ( & V_204 -> V_198 ) ;
F_27 () ;
}
F_67 ( & V_281 -> V_235 ) ;
if ( ! V_204 ) {
F_9 ( L_196
L_197 , V_282 -> V_48 () ,
V_284 ) ;
V_55 = V_229 ;
goto V_43;
}
if ( F_57 ( V_204 ) ) {
F_9 ( L_198
L_199 ) ;
F_32 ( & V_204 -> V_198 ) ;
F_33 () ;
V_204 = NULL ;
V_55 = V_229 ;
goto V_43;
}
F_11 ( L_200
L_201 , V_282 -> V_48 () ,
V_204 -> V_53 ) ;
V_205 = F_68 ( V_204 , V_288 ) ;
if ( ! V_205 ) {
F_9 ( L_202
L_180 , V_282 -> V_48 () , V_288 ) ;
V_55 = V_229 ;
goto V_43;
}
if ( F_31 ( V_205 ) ) {
F_9 ( L_203 ) ;
F_32 ( & V_205 -> V_152 ) ;
F_33 () ;
V_205 = NULL ;
V_55 = V_226 ;
goto V_43;
}
F_11 ( L_204
L_205 ,
V_282 -> V_48 () , V_204 -> V_53 ,
V_205 -> V_52 ) ;
F_6 ( & V_10 -> V_44 ) ;
V_30 = V_10 -> V_109 ;
if ( ! V_30 ) {
F_63 ( L_206
L_207 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_261 ;
goto V_43;
}
if ( V_30 != V_2 ) {
F_63 ( L_208
L_209 ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
if ( ( V_30 -> V_31 == V_34 ) ||
( V_30 -> V_31 == V_35 ) ) {
F_63 ( L_210
L_211 ,
F_15 ( V_30 -> V_31 ) ) ;
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_21 ;
goto V_43;
}
V_191 = V_30 -> V_111 ;
type = V_30 -> V_31 ;
V_264 = V_30 -> V_31 ;
V_207 = F_45 ( V_10 , V_204 ,
V_220 ) ;
if ( ! V_207 ) {
if ( F_44 ( V_8 -> V_11 ,
V_204 , V_205 , V_220 ,
V_119 , 0 , V_121 , 2 , 1 ) ) {
F_8 ( & V_10 -> V_44 ) ;
V_55 = V_229 ;
goto V_43;
}
V_207 = F_45 ( V_10 , V_204 ,
V_220 ) ;
V_286 = 1 ;
}
F_47 ( V_10 , V_191 ,
V_10 -> V_109 , 0 ) ;
V_10 -> V_109 = V_207 ;
V_207 -> V_30 = 1 ;
V_207 -> V_31 = type ;
V_2 -> V_160 = V_264 ;
F_1 ( V_2 , V_168 , V_169 ) ;
if ( ! V_286 )
V_207 -> V_181 = V_27 -> V_115 ++ ;
F_8 ( & V_10 -> V_44 ) ;
F_11 ( L_212
L_213
L_214 , V_282 -> V_48 () ,
F_15 ( type ) , V_288 ,
V_207 -> V_181 ) ;
F_11 ( L_215
L_216 ,
V_283 -> V_48 () , V_111 -> V_53 ,
V_168 , V_282 -> V_48 () ,
V_204 -> V_53 , ( V_220 != NULL ) ?
V_220 : L_29 ) ;
F_34 ( V_205 ) ;
F_58 ( V_204 ) ;
F_55 ( V_281 ) ;
if ( V_280 ) {
F_6 ( & V_27 -> V_36 ) ;
F_48 ( V_10 , V_2 , NULL , 1 ) ;
F_8 ( & V_27 -> V_36 ) ;
} else
F_5 ( V_2 ) ;
F_77 ( V_8 -> V_11 , V_121 ) ;
F_69 ( V_8 ) ;
F_5 ( V_207 ) ;
return 0 ;
V_43:
if ( V_3 )
F_69 ( V_8 ) ;
if ( V_205 )
F_34 ( V_205 ) ;
if ( V_204 )
F_58 ( V_204 ) ;
F_55 ( V_281 ) ;
V_265:
F_5 ( V_2 ) ;
return V_55 ;
}
static unsigned long long F_90 ( unsigned char * V_58 )
{
unsigned int V_290 , V_291 ;
V_290 = ( V_58 [ 0 ] << 24 ) | ( V_58 [ 1 ] << 16 ) | ( V_58 [ 2 ] << 8 ) | V_58 [ 3 ] ;
V_291 = ( V_58 [ 4 ] << 24 ) | ( V_58 [ 5 ] << 16 ) | ( V_58 [ 6 ] << 8 ) | V_58 [ 7 ] ;
return ( ( unsigned long long ) V_291 ) | ( unsigned long long ) V_290 << 32 ;
}
T_2
F_91 ( struct V_7 * V_8 )
{
unsigned char * V_58 = & V_8 -> V_15 [ 0 ] ;
unsigned char * V_3 ;
T_3 V_256 , V_119 ;
int V_292 , V_264 , type , V_121 ;
int V_257 = 0 , V_120 = 0 , V_280 = 0 ;
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_217
L_218
L_219 ) ;
return V_21 ;
}
if ( ! V_8 -> V_14 )
return V_226 ;
if ( V_8 -> V_228 < 24 ) {
F_63 ( L_61
L_62 , V_8 -> V_228 ) ;
return V_229 ;
}
V_292 = ( V_58 [ 1 ] & 0x1f ) ;
V_264 = ( V_58 [ 2 ] & 0xf0 ) ;
type = ( V_58 [ 2 ] & 0x0f ) ;
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_226 ;
V_256 = F_90 ( & V_3 [ 0 ] ) ;
V_119 = F_90 ( & V_3 [ 8 ] ) ;
if ( V_292 != V_85 ) {
V_257 = ( V_3 [ 20 ] & 0x08 ) ;
V_120 = ( V_3 [ 20 ] & 0x04 ) ;
V_121 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_121 = ( V_3 [ 17 ] & 0x01 ) ;
V_280 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_69 ( V_8 ) ;
V_3 = NULL ;
if ( V_257 && ( ( V_58 [ 1 ] & 0x1f ) != V_83 ) )
return V_229 ;
if ( ! V_257 && ( ( V_58 [ 1 ] & 0x1f ) != V_85 ) &&
( V_8 -> V_228 != 24 ) ) {
F_63 ( L_220
L_221 , V_8 -> V_228 ) ;
return V_229 ;
}
switch ( V_292 ) {
case V_83 :
V_55 = F_78 ( V_8 ,
V_256 , V_119 , V_121 , V_120 , V_257 , REGISTER ) ;
break;
case V_86 :
V_55 = F_81 ( V_8 , type , V_264 , V_256 ) ;
break;
case V_87 :
V_55 = F_82 ( V_8 , type , V_264 , V_256 ) ;
break;
case V_80 :
V_55 = F_83 ( V_8 , V_256 ) ;
break;
case V_81 :
V_55 = F_88 ( V_8 , type , V_264 ,
V_256 , V_119 , V_293 ) ;
break;
case V_82 :
V_55 = F_88 ( V_8 , type , V_264 ,
V_256 , V_119 , V_274 ) ;
break;
case V_84 :
V_55 = F_78 ( V_8 ,
0 , V_119 , V_121 , V_120 , V_257 , V_178 ) ;
break;
case V_85 :
V_55 = F_89 ( V_8 , V_256 ,
V_119 , V_121 , V_280 ) ;
break;
default:
F_9 ( L_15
L_16 , V_58 [ 1 ] & 0x1f ) ;
return V_261 ;
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
T_1 V_294 = 0 , V_295 = 8 ;
if ( V_8 -> V_228 < 8 ) {
F_9 ( L_222
L_223 , V_8 -> V_228 ) ;
return V_261 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_10 -> V_28 . V_36 ) ;
F_29 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_294 + 8 ) > ( V_8 -> V_228 - 8 ) )
break;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 56 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 48 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 40 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 32 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 24 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 16 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 8 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( V_2 -> V_110 & 0xff ) ;
V_294 += 8 ;
}
F_8 ( & V_10 -> V_28 . V_36 ) ;
V_3 [ 4 ] = ( ( V_294 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_294 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_294 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_294 & 0xff ) ;
F_69 ( V_8 ) ;
return 0 ;
}
static T_2
F_93 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_3 V_110 ;
T_1 V_294 = 16 ;
if ( V_8 -> V_228 < 8 ) {
F_9 ( L_224
L_223 , V_8 -> V_228 ) ;
return V_261 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_10 -> V_44 ) ;
V_2 = V_10 -> V_109 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_294 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_294 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_294 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_294 & 0xff ) ;
if ( V_8 -> V_228 < 22 )
goto V_296;
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
V_3 [ 21 ] = ( V_2 -> V_160 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
}
V_296:
F_8 ( & V_10 -> V_44 ) ;
F_69 ( V_8 ) ;
return 0 ;
}
static T_2
F_94 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_4 V_294 = 8 ;
if ( V_8 -> V_228 < 6 ) {
F_9 ( L_225
L_226 , V_8 -> V_228 ) ;
return V_261 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_294 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_294 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_27 -> V_174 )
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
F_95 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_20 * V_267 ;
struct V_39 * V_42 ;
struct V_1 * V_2 , * V_145 ;
struct V_26 * V_27 = & V_10 -> V_28 ;
unsigned char * V_3 ;
T_1 V_297 = 0 , V_294 = 0 , V_298 , V_299 ;
T_1 V_295 = 8 ;
int V_300 = 0 ;
if ( V_8 -> V_228 < 8 ) {
F_9 ( L_227
L_223 , V_8 -> V_228 ) ;
return V_261 ;
}
V_3 = F_64 ( V_8 ) ;
if ( ! V_3 )
return V_226 ;
V_3 [ 0 ] = ( ( V_10 -> V_28 . V_115 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_10 -> V_28 . V_115 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_10 -> V_28 . V_115 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_10 -> V_28 . V_115 & 0xff ) ;
F_6 ( & V_27 -> V_36 ) ;
F_25 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_267 = V_2 -> V_111 ;
V_42 = V_2 -> V_111 -> V_42 ;
V_297 = 0 ;
F_26 ( & V_2 -> V_129 ) ;
F_27 () ;
F_8 ( & V_27 -> V_36 ) ;
V_299 = V_42 -> V_47 -> V_301 (
V_42 , V_267 , V_2 , & V_300 ) ;
if ( ( V_299 + V_294 ) > V_8 -> V_228 ) {
F_63 ( L_228
L_229 , V_8 -> V_228 ) ;
F_6 ( & V_27 -> V_36 ) ;
F_32 ( & V_2 -> V_129 ) ;
F_33 () ;
break;
}
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 56 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 48 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 40 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 32 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 24 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 16 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_2 -> V_110 >> 8 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( V_2 -> V_110 & 0xff ) ;
V_295 += 4 ;
if ( V_2 -> V_133 )
V_3 [ V_295 ] = 0x02 ;
if ( V_2 -> V_30 ) {
V_3 [ V_295 ++ ] |= 0x01 ;
V_3 [ V_295 ++ ] = ( V_2 -> V_160 & 0xf0 ) |
( V_2 -> V_31 & 0x0f ) ;
} else
V_295 += 2 ;
V_295 += 4 ;
if ( ! V_2 -> V_133 ) {
struct V_139 * V_140 = V_2 -> V_135 -> V_242 ;
V_3 [ V_295 ++ ] = ( ( V_140 -> V_234 >> 8 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( V_140 -> V_234 & 0xff ) ;
} else
V_295 += 2 ;
V_298 = V_42 -> V_47 -> V_302 ( V_42 ,
V_267 , V_2 , & V_300 , & V_3 [ V_295 + 4 ] ) ;
F_6 ( & V_27 -> V_36 ) ;
F_32 ( & V_2 -> V_129 ) ;
F_33 () ;
V_3 [ V_295 ++ ] = ( ( V_298 >> 24 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_298 >> 16 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( ( V_298 >> 8 ) & 0xff ) ;
V_3 [ V_295 ++ ] = ( V_298 & 0xff ) ;
V_297 = ( 24 + V_298 ) ;
V_295 += V_298 ;
V_294 += V_297 ;
}
F_8 ( & V_27 -> V_36 ) ;
V_3 [ 4 ] = ( ( V_294 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_294 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_294 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_294 & 0xff ) ;
F_69 ( V_8 ) ;
return 0 ;
}
T_2
F_96 ( struct V_7 * V_8 )
{
T_2 V_55 ;
if ( V_8 -> V_11 -> V_22 & V_46 ) {
F_9 ( L_217
L_218
L_219 ) ;
return V_21 ;
}
switch ( V_8 -> V_15 [ 1 ] & 0x1f ) {
case V_303 :
V_55 = F_92 ( V_8 ) ;
break;
case V_304 :
V_55 = F_93 ( V_8 ) ;
break;
case V_305 :
V_55 = F_94 ( V_8 ) ;
break;
case V_306 :
V_55 = F_95 ( V_8 ) ;
break;
default:
F_9 ( L_230
L_16 , V_8 -> V_15 [ 1 ] & 0x1f ) ;
return V_261 ;
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
if ( V_10 -> V_307 -> V_308 & V_309 )
return 0 ;
if ( V_10 -> V_179 -> V_310 == V_311 )
return 0 ;
F_6 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_22 & V_46 )
V_55 = F_2 ( V_8 ) ;
else
V_55 = F_17 ( V_8 ) ;
F_8 ( & V_10 -> V_44 ) ;
return V_55 ;
}
