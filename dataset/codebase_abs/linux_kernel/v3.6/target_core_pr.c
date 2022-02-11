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
static int F_2 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
switch ( V_9 [ 0 ] ) {
case V_11 :
case V_12 :
case V_13 :
return 0 ;
default:
return 1 ;
}
return 1 ;
}
static int F_3 ( struct V_7 * V_8 , T_1 * V_10 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
int V_20 ;
if ( ! V_18 )
return 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
if ( V_15 -> V_22 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - V_24 ;
}
if ( ! ( V_15 -> V_25 & V_26 ) ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_27 == V_18 -> V_28 ) ? 0 : - V_24 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_29 * V_30 = V_8 -> V_16 -> V_31 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_30 -> V_34 ;
int V_35 = ( V_30 -> V_34 . V_36 == V_37 ) ;
int V_38 = 0 ;
if ( ! V_35 )
return - V_24 ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( V_2 ) {
if ( V_2 -> V_39 ) {
F_8 ( V_2 ) ;
return 1 ;
}
if ( ( V_2 -> V_40 == V_41 ) ||
( V_2 -> V_40 == V_42 ) ||
( V_2 -> V_40 == V_43 ) ||
( V_2 -> V_40 == V_44 ) ) {
F_8 ( V_2 ) ;
return 1 ;
}
F_8 ( V_2 ) ;
V_38 = 1 ;
} else {
F_4 ( & V_33 -> V_45 ) ;
V_38 = ( F_9 ( & V_33 -> V_46 ) ) ? 0 : 1 ;
F_5 ( & V_33 -> V_45 ) ;
}
if ( V_38 ) {
F_10 ( L_2
L_3
L_4 ) ;
V_8 -> V_47 = V_48 ;
return - V_49 ;
}
return 0 ;
}
int F_11 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_50 * V_51 = V_18 -> V_52 ;
int V_20 = 0 , V_53 ;
if ( ! V_18 || ! V_51 )
goto V_54;
V_53 = F_6 ( V_8 ) ;
if ( V_53 == 1 )
goto V_54;
else if ( V_53 < 0 ) {
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_54;
}
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 )
goto V_55;
if ( V_15 -> V_22 != V_18 -> V_23 )
goto V_55;
if ( V_15 -> V_27 != V_18 -> V_28 )
goto V_55;
V_15 -> V_22 = NULL ;
V_15 -> V_25 &= ~ V_56 ;
if ( V_15 -> V_25 & V_26 ) {
V_15 -> V_27 = 0 ;
V_15 -> V_25 &= ~ V_26 ;
}
F_12 ( L_5
L_6 , V_51 -> V_57 -> V_58 () ,
V_8 -> V_59 -> V_60 , V_8 -> V_61 -> V_62 ,
V_18 -> V_23 -> V_63 ) ;
V_55:
F_5 ( & V_15 -> V_21 ) ;
V_54:
if ( ! V_20 )
F_13 ( V_8 , V_64 ) ;
return V_20 ;
}
int F_14 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_50 * V_51 = V_18 -> V_52 ;
int V_20 = 0 , V_53 ;
if ( ( V_8 -> V_65 [ 1 ] & 0x01 ) &&
( V_8 -> V_65 [ 1 ] & 0x02 ) ) {
F_10 ( L_7
L_8 ) ;
V_8 -> V_47 = V_66 ;
V_20 = - V_24 ;
goto V_54;
}
if ( ! V_18 || ! V_51 )
goto V_54;
V_53 = F_6 ( V_8 ) ;
if ( V_53 == 1 )
goto V_54;
else if ( V_53 < 0 ) {
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_54;
}
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_22 &&
( V_15 -> V_22 != V_18 -> V_23 ) ) {
F_10 ( L_9 ,
V_51 -> V_57 -> V_58 () ) ;
F_10 ( L_10 ,
V_8 -> V_59 -> V_60 ,
V_15 -> V_22 -> V_63 ) ;
F_10 ( L_11
L_12 , V_8 -> V_59 -> V_60 ,
V_8 -> V_61 -> V_62 ,
V_18 -> V_23 -> V_63 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_55;
}
V_15 -> V_22 = V_18 -> V_23 ;
V_15 -> V_25 |= V_56 ;
if ( V_18 -> V_28 != 0 ) {
V_15 -> V_27 = V_18 -> V_28 ;
V_15 -> V_25 |= V_26 ;
}
F_12 ( L_13
L_14 , V_51 -> V_57 -> V_58 () ,
V_8 -> V_59 -> V_60 , V_8 -> V_61 -> V_62 ,
V_18 -> V_23 -> V_63 ) ;
V_55:
F_5 ( & V_15 -> V_21 ) ;
V_54:
if ( ! V_20 )
F_13 ( V_8 , V_64 ) ;
return V_20 ;
}
static int F_15 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
struct V_67 * V_61 ;
struct V_17 * V_19 = V_8 -> V_19 ;
int V_68 = 0 , V_69 ;
int V_70 = 0 , V_20 = 1 ;
int V_71 = 0 , V_72 = 0 ;
int V_73 = 0 ;
int V_74 = 0 ;
if ( V_8 -> V_16 -> V_25 & V_56 )
return F_2 ( V_8 ,
V_9 , V_10 ) ;
V_61 = V_19 -> V_23 -> V_75 [ V_8 -> V_76 ] ;
V_69 = ( V_10 & 0x80000000 ) ;
if ( V_69 )
V_10 &= ~ 0x80000000 ;
switch ( V_10 ) {
case V_77 :
V_73 = 1 ;
case V_78 :
if ( ( V_61 -> V_79 ) && ! ( V_69 ) )
V_70 = 1 ;
break;
case V_41 :
V_73 = 1 ;
case V_42 :
V_72 = 1 ;
if ( ( V_61 -> V_79 ) && ! ( V_69 ) )
V_70 = 1 ;
break;
case V_43 :
V_73 = 1 ;
case V_44 :
V_71 = 1 ;
if ( ( V_61 -> V_79 ) && ! ( V_69 ) )
V_70 = 1 ;
break;
default:
return - V_24 ;
}
switch ( V_9 [ 0 ] ) {
case V_80 :
if ( V_70 )
return 0 ;
V_20 = ( V_73 ) ? 0 : 1 ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( V_74 ) {
V_20 = 1 ;
break;
}
if ( V_70 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_73 ) ? 0 : 1 ;
break;
case V_86 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_87 :
case V_88 :
case V_89 :
V_20 = ( V_70 ) ? 0 : 1 ;
break;
case V_90 :
case V_91 :
V_20 = 0 ;
break;
case V_92 :
case V_93 :
V_20 = 1 ;
break;
case V_94 :
V_20 = ( V_70 ) ? 0 : 1 ;
break;
default:
F_10 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
return - V_24 ;
}
break;
case V_12 :
case V_13 :
V_20 = 0 ;
break;
case V_95 :
case V_96 :
V_20 = 0 ;
break;
case V_97 :
V_20 = ( V_74 ) ? 1 : 0 ;
break;
case V_98 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_99 :
if ( V_70 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_73 ) ? 0 : 1 ;
break;
case V_100 :
case V_101 :
if ( V_74 ) {
V_20 = 1 ;
break;
}
if ( V_70 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_73 ) ? 0 : 1 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_20 = 0 ;
break;
default:
F_10 ( L_17 ,
( V_9 [ 1 ] & 0x1f ) ) ;
return - V_24 ;
}
break;
case V_107 :
case V_108 :
case V_11 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_20 = 0 ;
break;
default:
V_68 = 1 ;
break;
}
if ( ! V_20 && ! V_68 ) {
F_12 ( L_18
L_19 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
return V_20 ;
}
if ( V_73 && ! V_70 ) {
if ( V_8 -> V_114 == V_115 ) {
F_12 ( L_20
L_21 ,
F_17 ( V_8 ) ,
V_19 -> V_23 -> V_63 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
return 1 ;
} else {
if ( ! V_70 ) {
F_12 ( L_22
L_23
L_24 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
}
return 0 ;
}
} else if ( ( V_72 ) || ( V_71 ) ) {
if ( V_70 ) {
F_12 ( L_25
L_26 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
return 0 ;
}
}
F_12 ( L_27
L_28 , F_17 ( V_8 ) ,
( V_70 ) ? L_29 : L_30 ,
V_19 -> V_23 -> V_63 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
return 1 ;
}
static T_1 F_18 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_116 ;
F_4 ( & V_15 -> V_21 ) ;
V_116 = V_30 -> V_34 . V_117 ++ ;
F_5 ( & V_15 -> V_21 ) ;
return V_116 ;
}
static int F_19 (
struct V_7 * V_8 ,
T_1 * V_10 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
int V_20 ;
if ( ! V_18 )
return 0 ;
if ( V_15 -> V_25 & V_56 )
return F_3 ( V_8 , V_10 ) ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_118 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
* V_10 = V_15 -> V_118 -> V_40 ;
V_8 -> V_119 = V_15 -> V_118 -> V_119 ;
if ( V_15 -> V_118 -> V_120 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - V_24 ;
}
if ( ! V_15 -> V_118 -> V_5 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_118 -> V_121 ==
V_18 -> V_28 ) ? 0 : - V_24 ;
if ( V_20 != 0 )
* V_10 |= 0x80000000 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static struct V_1 * F_20 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_67 * V_123 ,
unsigned char * V_124 ,
T_2 V_125 ,
int V_126 ,
int V_127 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_128 , V_129 ) ;
if ( ! V_2 ) {
F_10 ( L_31 ) ;
return NULL ;
}
V_2 -> V_130 = F_22 ( V_30 -> V_34 . V_131 ,
V_129 ) ;
if ( ! V_2 -> V_130 ) {
F_10 ( L_32 ) ;
F_23 ( V_128 , V_2 ) ;
return NULL ;
}
F_24 ( & V_2 -> V_132 ) ;
F_24 ( & V_2 -> V_133 ) ;
F_24 ( & V_2 -> V_134 ) ;
F_24 ( & V_2 -> V_135 ) ;
F_24 ( & V_2 -> V_136 ) ;
F_25 ( & V_2 -> V_137 , 0 ) ;
V_2 -> V_120 = V_122 ;
V_2 -> V_138 = V_123 ;
V_2 -> V_139 = V_123 -> V_62 ;
V_2 -> V_140 = V_123 -> V_59 -> V_60 ;
V_2 -> V_119 = V_125 ;
V_2 -> V_141 = V_126 ;
V_2 -> V_142 = V_127 ;
V_2 -> V_143 = V_123 -> V_59 ;
if ( V_124 != NULL ) {
V_2 -> V_121 = F_26 ( V_124 ) ;
snprintf ( V_2 -> V_6 , V_144 , L_33 , V_124 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_27 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_67 * V_123 ,
unsigned char * V_124 ,
T_2 V_125 ,
int V_126 ,
int V_127 )
{
struct V_67 * V_145 ;
struct V_23 * V_146 ;
struct V_147 * V_148 , * V_149 ;
struct V_150 * V_151 = V_122 -> V_52 -> V_57 ;
struct V_1 * V_2 , * V_152 , * V_153 , * V_154 ;
int V_20 ;
V_2 = F_20 ( V_15 , V_122 , V_123 , V_124 ,
V_125 , V_126 , V_127 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_126 )
return V_2 ;
F_4 ( & V_15 -> V_155 ) ;
F_28 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_29 ( & V_148 -> V_156 ) ;
F_30 () ;
F_5 ( & V_15 -> V_155 ) ;
F_31 ( & V_148 -> V_157 ) ;
F_32 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_145 -> V_158 )
continue;
V_146 = V_145 -> V_158 -> V_159 ;
if ( V_122 == V_146 )
continue;
if ( V_151 != V_146 -> V_52 -> V_57 )
continue;
if ( strcmp ( V_122 -> V_63 , V_146 -> V_63 ) )
continue;
F_29 ( & V_145 -> V_160 ) ;
F_30 () ;
F_33 ( & V_148 -> V_157 ) ;
V_20 = F_34 ( V_145 ) ;
if ( V_20 < 0 ) {
F_10 ( L_34
L_35 ) ;
F_35 ( & V_148 -> V_156 ) ;
F_36 () ;
F_35 ( & V_145 -> V_160 ) ;
F_36 () ;
goto V_54;
}
V_152 = F_20 ( V_15 ,
V_146 , V_145 , NULL ,
V_125 , V_126 , V_127 ) ;
if ( ! V_152 ) {
F_35 ( & V_148 -> V_156 ) ;
F_36 () ;
F_35 ( & V_145 -> V_160 ) ;
F_36 () ;
F_37 ( V_145 ) ;
goto V_54;
}
F_38 ( & V_152 -> V_136 ,
& V_2 -> V_135 ) ;
F_31 ( & V_148 -> V_157 ) ;
}
F_33 ( & V_148 -> V_157 ) ;
F_4 ( & V_15 -> V_155 ) ;
F_35 ( & V_148 -> V_156 ) ;
F_36 () ;
}
F_5 ( & V_15 -> V_155 ) ;
return V_2 ;
V_54:
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_153 -> V_136 ) ;
F_37 ( V_153 -> V_138 ) ;
F_23 ( V_128 , V_153 ) ;
}
F_23 ( V_128 , V_2 ) ;
return NULL ;
}
int F_40 (
struct V_32 * V_33 ,
T_2 V_125 ,
unsigned char * V_161 ,
unsigned char * V_124 ,
T_1 V_62 ,
unsigned char * V_162 ,
T_3 V_163 ,
T_1 V_164 ,
int V_165 ,
int V_126 ,
T_4 type )
{
struct V_1 * V_2 ;
if ( ! V_161 || ! V_162 || ! V_125 ) {
F_10 ( L_36 ) ;
return - V_24 ;
}
V_2 = F_21 ( V_128 , V_166 ) ;
if ( ! V_2 ) {
F_10 ( L_31 ) ;
return - V_167 ;
}
V_2 -> V_130 = F_22 ( V_33 -> V_131 , V_166 ) ;
F_24 ( & V_2 -> V_132 ) ;
F_24 ( & V_2 -> V_133 ) ;
F_24 ( & V_2 -> V_134 ) ;
F_24 ( & V_2 -> V_135 ) ;
F_24 ( & V_2 -> V_136 ) ;
F_25 ( & V_2 -> V_137 , 0 ) ;
V_2 -> V_120 = NULL ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = V_62 ;
V_2 -> V_140 = V_164 ;
V_2 -> V_119 = V_125 ;
V_2 -> V_141 = V_126 ;
V_2 -> V_142 = 1 ;
V_2 -> V_143 = NULL ;
V_2 -> V_168 = 0 ;
V_2 -> V_40 = type ;
if ( V_124 != NULL ) {
V_2 -> V_121 = F_26 ( V_124 ) ;
snprintf ( V_2 -> V_6 , V_144 , L_33 , V_124 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_169 , V_170 , L_33 , V_161 ) ;
snprintf ( V_2 -> V_171 , V_172 , L_33 , V_162 ) ;
V_2 -> V_173 = V_163 ;
V_2 -> V_39 = V_165 ;
F_38 ( & V_2 -> V_134 , & V_33 -> V_174 ) ;
F_12 ( L_37
L_38 , ( V_165 ) ? L_39 : L_29 ) ;
return 0 ;
}
static void F_41 (
struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_23 * V_175 ,
struct V_1 * V_2 )
{
char V_176 [ V_177 ] ;
int V_178 ;
memset ( V_176 , 0 , V_177 ) ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_15 -> V_118 = V_2 ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_40
L_41 ,
V_51 -> V_57 -> V_58 () ,
F_16 ( V_2 -> V_40 ) ,
( V_2 -> V_141 ) ? 1 : 0 ) ;
F_12 ( L_42 ,
V_51 -> V_57 -> V_58 () , V_175 -> V_63 ,
( V_178 ) ? & V_176 [ 0 ] : L_29 ) ;
}
static int F_42 (
struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_59 * V_179 ,
T_1 V_164 ,
struct V_23 * V_122 ,
struct V_67 * V_123 )
{
struct V_1 * V_2 , * V_153 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char V_161 [ V_170 ] ;
unsigned char V_162 [ V_172 ] ;
T_3 V_163 ;
memset ( V_161 , 0 , V_170 ) ;
memset ( V_162 , 0 , V_172 ) ;
snprintf ( V_161 , V_170 , L_33 , V_122 -> V_63 ) ;
snprintf ( V_162 , V_172 , L_33 ,
V_51 -> V_57 -> V_180 ( V_51 ) ) ;
V_163 = V_51 -> V_57 -> V_181 ( V_51 ) ;
F_4 ( & V_33 -> V_182 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_169 , V_161 ) &&
( V_2 -> V_139 == V_123 -> V_62 ) &&
! ( strcmp ( V_2 -> V_171 , V_162 ) ) &&
( V_2 -> V_173 == V_163 ) &&
( V_2 -> V_140 == V_164 ) ) {
V_2 -> V_120 = V_122 ;
V_2 -> V_138 = V_123 ;
V_2 -> V_143 = V_179 ;
F_39 ( & V_2 -> V_134 ) ;
F_5 ( & V_33 -> V_182 ) ;
F_43 ( V_15 , V_122 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_39 )
F_41 ( V_15 , V_51 ,
V_122 , V_2 ) ;
F_4 ( & V_33 -> V_182 ) ;
V_33 -> V_183 = 1 ;
}
}
F_5 ( & V_33 -> V_182 ) ;
return 0 ;
}
int F_44 (
struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_59 * V_179 ,
struct V_158 * V_184 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_23 * V_122 = V_184 -> V_159 ;
struct V_67 * V_123 = V_122 -> V_75 [ V_184 -> V_62 ] ;
if ( V_30 -> V_34 . V_36 != V_37 )
return 0 ;
return F_42 ( V_15 , V_51 , V_179 ,
V_179 -> V_60 , V_122 , V_123 ) ;
}
static void F_45 (
struct V_150 * V_151 ,
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_1 * V_2 ,
int V_185 )
{
struct V_50 * V_52 = V_122 -> V_52 ;
char V_176 [ V_177 ] ;
int V_178 ;
memset ( & V_176 [ 0 ] , 0 , V_177 ) ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
F_12 ( L_43
L_44 , V_151 -> V_58 () , ( V_185 == 2 ) ?
L_45 : ( V_185 == 1 ) ?
L_46 : L_29 , V_122 -> V_63 ,
( V_178 ) ? V_176 : L_29 ) ;
F_12 ( L_47 ,
V_151 -> V_58 () , V_151 -> V_180 ( V_52 ) ,
V_151 -> V_181 ( V_52 ) ) ;
F_12 ( L_48
L_49 , V_151 -> V_58 () ,
( V_2 -> V_141 ) ? L_50 : L_51 ,
V_15 -> V_186 -> V_187 ) ;
F_12 ( L_52
L_53 , V_151 -> V_58 () ,
V_2 -> V_119 , V_2 -> V_188 ,
V_2 -> V_142 ) ;
}
static void F_43 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_1 * V_2 ,
int V_185 ,
int V_189 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_150 * V_151 = V_122 -> V_52 -> V_57 ;
struct V_1 * V_153 , * V_154 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
V_2 -> V_188 = ( V_189 ) ?
V_30 -> V_34 . V_117 ++ :
F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_2 -> V_132 , & V_33 -> V_46 ) ;
V_2 -> V_138 -> V_79 = 1 ;
F_45 ( V_151 , V_15 , V_122 , V_2 , V_185 ) ;
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_2 -> V_141 || V_189 )
return;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_153 -> V_136 ) ;
V_153 -> V_188 = F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_153 -> V_132 ,
& V_33 -> V_46 ) ;
V_153 -> V_138 -> V_79 = 1 ;
F_45 ( V_151 , V_15 ,
V_153 -> V_120 , V_153 ,
V_185 ) ;
F_5 ( & V_33 -> V_45 ) ;
F_37 ( V_153 -> V_138 ) ;
}
}
static int F_46 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_67 * V_123 ,
unsigned char * V_124 ,
T_2 V_125 ,
int V_126 ,
int V_127 ,
int V_185 ,
int V_189 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_15 , V_122 , V_123 , V_124 ,
V_125 , V_126 , V_127 ) ;
if ( ! V_2 )
return - V_190 ;
F_43 ( V_15 , V_122 , V_2 ,
V_185 , V_189 ) ;
return 0 ;
}
static struct V_1 * F_47 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
unsigned char * V_124 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_153 ;
struct V_50 * V_51 ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_120 != V_122 )
continue;
V_51 = V_2 -> V_120 -> V_52 ;
if ( ! V_2 -> V_5 ) {
if ( V_51 -> V_57 -> V_191 != NULL ) {
if ( V_15 -> V_31 -> V_192 . V_193 )
continue;
}
F_29 ( & V_2 -> V_137 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
if ( ! V_124 )
continue;
if ( strcmp ( V_124 , V_2 -> V_6 ) )
continue;
F_29 ( & V_2 -> V_137 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
F_5 ( & V_33 -> V_45 ) ;
return NULL ;
}
static struct V_1 * F_7 (
struct V_14 * V_15 ,
struct V_23 * V_122 ,
struct V_17 * V_18 )
{
struct V_50 * V_51 = V_122 -> V_52 ;
unsigned char V_3 [ V_144 ] , * V_194 = NULL ;
if ( V_51 -> V_57 -> V_191 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_144 ) ;
V_51 -> V_57 -> V_191 ( V_18 , & V_3 [ 0 ] ,
V_144 ) ;
V_194 = & V_3 [ 0 ] ;
}
return F_47 ( V_15 , V_122 , V_194 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_137 ) ;
F_36 () ;
}
static int F_48 (
struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_23 * V_122 = V_2 -> V_120 ;
struct V_1 * V_39 ;
int V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
if ( V_39 == V_2 ) {
F_49 ( V_15 , V_122 , V_2 , 0 ) ;
V_20 = 1 ;
} else if ( V_2 -> V_141 &&
( ! strcmp ( V_39 -> V_120 -> V_63 ,
V_2 -> V_120 -> V_63 ) ) &&
( V_39 -> V_119 == V_2 -> V_119 ) ) {
F_10 ( L_54
L_55
L_56
L_57 , V_2 -> V_119 ) ;
V_20 = - V_190 ;
}
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static void F_50 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_195 * V_196 ,
int V_197 )
{
struct V_150 * V_151 =
V_2 -> V_120 -> V_52 -> V_57 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_176 [ V_177 ] ;
int V_178 ;
memset ( V_176 , 0 , V_177 ) ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
V_2 -> V_138 -> V_79 = 0 ;
V_2 -> V_138 -> V_119 = 0 ;
F_39 ( & V_2 -> V_132 ) ;
if ( V_197 )
F_8 ( V_2 ) ;
while ( F_51 ( & V_2 -> V_137 ) != 0 ) {
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_58 ,
V_151 -> V_58 () ) ;
F_52 () ;
F_4 ( & V_33 -> V_45 ) ;
}
F_12 ( L_59
L_44 , V_151 -> V_58 () ,
V_2 -> V_120 -> V_63 ,
( V_178 ) ? & V_176 [ 0 ] : L_29 ) ;
F_12 ( L_48
L_49 , V_151 -> V_58 () ,
( V_2 -> V_141 ) ? L_50 : L_51 ,
V_15 -> V_186 -> V_187 ) ;
F_12 ( L_52
L_60 , V_151 -> V_58 () , V_2 -> V_119 ,
V_2 -> V_188 ) ;
if ( ! V_196 ) {
V_2 -> V_138 = NULL ;
V_2 -> V_120 = NULL ;
F_53 ( V_2 -> V_130 ) ;
F_23 ( V_128 , V_2 ) ;
return;
}
F_38 ( & V_2 -> V_133 , V_196 ) ;
}
void F_54 (
struct V_14 * V_15 ,
struct V_23 * V_122 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_153 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( ( V_39 != NULL ) &&
( V_39 -> V_120 == V_122 ) )
F_49 ( V_15 , V_122 , V_39 , 0 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_120 != V_122 )
continue;
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
void F_55 (
struct V_14 * V_15 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_153 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( V_39 != NULL ) {
struct V_23 * V_198 = V_39 -> V_120 ;
F_49 ( V_15 , V_198 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_4 ( & V_33 -> V_182 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_39 ( & V_2 -> V_134 ) ;
F_53 ( V_2 -> V_130 ) ;
F_23 ( V_128 , V_2 ) ;
}
F_5 ( & V_33 -> V_182 ) ;
}
static int F_56 ( struct V_50 * V_51 )
{
return F_57 ( V_51 -> V_57 -> V_199 ,
& V_51 -> V_200 . V_201 ) ;
}
static void F_58 ( struct V_50 * V_51 )
{
F_59 ( V_51 -> V_57 -> V_199 ,
& V_51 -> V_200 . V_201 ) ;
F_35 ( & V_51 -> V_202 ) ;
F_36 () ;
}
static int F_60 ( struct V_23 * V_122 )
{
struct V_50 * V_51 = V_122 -> V_52 ;
if ( V_122 -> V_203 )
return 0 ;
return F_57 ( V_51 -> V_57 -> V_199 ,
& V_122 -> V_204 . V_201 ) ;
}
static void F_61 ( struct V_23 * V_122 )
{
struct V_50 * V_51 = V_122 -> V_52 ;
if ( V_122 -> V_203 ) {
F_35 ( & V_122 -> V_205 ) ;
F_36 () ;
return;
}
F_59 ( V_51 -> V_57 -> V_199 ,
& V_122 -> V_204 . V_201 ) ;
F_35 ( & V_122 -> V_205 ) ;
F_36 () ;
}
static int F_34 ( struct V_67 * V_61 )
{
struct V_158 * V_184 = V_61 -> V_158 ;
struct V_23 * V_122 ;
struct V_50 * V_51 ;
if ( ! V_184 )
return 0 ;
V_122 = V_184 -> V_159 ;
V_51 = V_122 -> V_52 ;
return F_57 ( V_51 -> V_57 -> V_199 ,
& V_184 -> V_206 . V_201 ) ;
}
static void F_37 ( struct V_67 * V_61 )
{
struct V_158 * V_184 = V_61 -> V_158 ;
struct V_23 * V_122 ;
struct V_50 * V_51 ;
if ( ! V_184 ) {
F_35 ( & V_61 -> V_160 ) ;
F_36 () ;
return;
}
V_122 = V_184 -> V_159 ;
V_51 = V_122 -> V_52 ;
F_59 ( V_51 -> V_57 -> V_199 ,
& V_184 -> V_206 . V_201 ) ;
F_35 ( & V_61 -> V_160 ) ;
F_36 () ;
}
static int F_62 (
struct V_7 * V_8 ,
struct V_50 * V_51 ,
unsigned char * V_207 ,
T_2 V_125 ,
int V_126 ,
int V_127 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_147 * V_208 ;
struct V_50 * V_209 = NULL , * V_210 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_23 * V_211 = NULL ;
struct V_67 * V_212 = NULL , * V_213 ;
struct V_1 * V_214 , * V_215 , * V_216 ;
struct V_1 * V_153 , * V_154 ;
F_63 ( V_217 ) ;
struct V_218 * V_219 , * V_220 , * V_221 ;
struct V_150 * V_222 ;
unsigned char * V_3 ;
unsigned char * V_223 , * V_224 = NULL , V_225 , V_226 ;
char * V_227 = NULL , V_228 [ 64 ] , V_176 [ V_177 ] ;
T_1 V_229 , V_230 = 0 ;
int V_20 , V_231 , V_178 ;
T_1 V_232 = 0 ;
memset ( V_228 , 0 , 64 ) ;
V_213 = V_19 -> V_23 -> V_75 [ V_8 -> V_76 ] ;
V_219 = F_22 ( sizeof( struct V_218 ) , V_166 ) ;
if ( ! V_219 ) {
F_10 ( L_61 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
F_24 ( & V_219 -> V_234 ) ;
V_219 -> V_209 = V_51 ;
V_219 -> V_211 = V_19 -> V_23 ;
V_219 -> V_212 = V_213 ;
V_215 = F_27 ( V_8 -> V_16 ,
V_19 -> V_23 , V_213 , V_207 ,
V_125 , V_126 , V_127 ) ;
if ( ! V_215 ) {
F_53 ( V_219 ) ;
V_8 -> V_47 = V_233 ;
return - V_167 ;
}
V_219 -> V_214 = V_215 ;
V_219 -> V_231 = 1 ;
F_38 ( & V_219 -> V_234 , & V_217 ) ;
if ( V_8 -> V_235 < 28 ) {
F_64 ( L_62
L_63 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_3 = F_65 ( V_8 ) ;
V_229 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_229 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_229 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_229 |= V_3 [ 27 ] & 0xff ;
if ( ( V_229 + 28 ) != V_8 -> V_235 ) {
F_10 ( L_64
L_65 , V_229 ,
V_8 -> V_235 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_223 = & V_3 [ 28 ] ;
while ( V_229 > 0 ) {
V_225 = ( V_223 [ 0 ] & 0x0f ) ;
V_209 = NULL ;
F_4 ( & V_15 -> V_155 ) ;
F_32 (tmp_port, &dev->dev_sep_list, sep_list) {
V_210 = V_208 -> V_237 ;
if ( ! V_210 )
continue;
V_222 = V_210 -> V_57 ;
if ( ! V_222 )
continue;
if ( ! V_222 -> V_238 ||
! V_222 -> V_239 )
continue;
V_226 = V_222 -> V_238 ( V_210 ) ;
if ( V_226 != V_225 )
continue;
V_232 = V_208 -> V_240 ;
V_224 = V_222 -> V_239 (
V_210 , ( const char * ) V_223 , & V_230 ,
& V_227 ) ;
if ( ! V_224 )
continue;
F_29 ( & V_210 -> V_202 ) ;
F_30 () ;
F_5 ( & V_15 -> V_155 ) ;
V_20 = F_56 ( V_210 ) ;
if ( V_20 != 0 ) {
F_10 ( L_66
L_67 ) ;
F_35 ( & V_210 -> V_202 ) ;
F_36 () ;
V_8 -> V_47 =
V_233 ;
V_20 = - V_24 ;
goto V_54;
}
F_66 ( & V_210 -> V_241 ) ;
V_211 = F_67 (
V_210 , V_224 ) ;
if ( V_211 ) {
F_29 ( & V_211 -> V_205 ) ;
F_30 () ;
}
F_68 ( & V_210 -> V_241 ) ;
if ( ! V_211 ) {
F_58 ( V_210 ) ;
F_4 ( & V_15 -> V_155 ) ;
continue;
}
V_20 = F_60 ( V_211 ) ;
if ( V_20 != 0 ) {
F_10 ( L_68
L_69 ) ;
F_35 ( & V_211 -> V_205 ) ;
F_36 () ;
F_58 ( V_210 ) ;
V_8 -> V_47 =
V_233 ;
V_20 = - V_24 ;
goto V_54;
}
V_209 = V_210 ;
F_12 ( L_70
L_71 ,
V_209 -> V_57 -> V_58 () ,
V_211 -> V_63 , V_232 ) ;
F_4 ( & V_15 -> V_155 ) ;
break;
}
F_5 ( & V_15 -> V_155 ) ;
if ( ! V_209 ) {
F_10 ( L_72
L_73 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
F_12 ( L_74
L_75 ,
V_209 -> V_57 -> V_58 () , V_8 -> V_235 ,
V_229 , V_230 , V_224 , V_227 ) ;
if ( V_230 > V_229 ) {
F_10 ( L_76
L_77 , V_230 , V_223 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_212 = F_69 ( V_211 ,
V_232 ) ;
if ( ! V_212 ) {
F_10 ( L_78
L_79 ,
V_209 -> V_57 -> V_58 () ,
V_232 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_20 = F_34 ( V_212 ) ;
if ( V_20 < 0 ) {
F_10 ( L_80
L_81 ) ;
F_35 ( & V_212 -> V_160 ) ;
F_36 () ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
V_8 -> V_47 =
V_233 ;
V_20 = - V_24 ;
goto V_54;
}
F_12 ( L_82
L_83 ,
V_209 -> V_57 -> V_58 () ,
V_211 -> V_63 , V_212 -> V_62 ) ;
V_216 = F_47 ( V_15 , V_211 ,
V_227 ) ;
if ( V_216 ) {
F_8 ( V_216 ) ;
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
V_223 += V_230 ;
V_229 -= V_230 ;
V_230 = 0 ;
continue;
}
V_219 = F_22 ( sizeof( struct V_218 ) ,
V_166 ) ;
if ( ! V_219 ) {
F_10 ( L_61 ) ;
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
V_8 -> V_47 =
V_233 ;
V_20 = - V_167 ;
goto V_54;
}
F_24 ( & V_219 -> V_234 ) ;
V_219 -> V_209 = V_209 ;
V_219 -> V_211 = V_211 ;
V_219 -> V_212 = V_212 ;
V_214 = F_27 ( V_8 -> V_16 ,
V_211 , V_212 , V_227 ,
V_125 , V_126 , V_127 ) ;
if ( ! V_214 ) {
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
F_53 ( V_219 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_219 -> V_214 = V_214 ;
F_38 ( & V_219 -> V_234 , & V_217 ) ;
V_223 += V_230 ;
V_229 -= V_230 ;
V_230 = 0 ;
}
F_70 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_209 = V_220 -> V_209 ;
V_211 = V_220 -> V_211 ;
V_212 = V_220 -> V_212 ;
V_214 = V_220 -> V_214 ;
V_231 = V_220 -> V_231 ;
F_39 ( & V_220 -> V_234 ) ;
F_53 ( V_220 ) ;
memset ( V_176 , 0 , V_177 ) ;
V_178 = F_1 ( V_214 , & V_176 [ 0 ] ,
V_177 ) ;
F_43 ( V_8 -> V_16 , V_211 ,
V_214 , 0 , 0 ) ;
F_12 ( L_84
L_85
L_86 , V_209 -> V_57 -> V_58 () ,
V_211 -> V_63 , ( V_178 ) ?
& V_176 [ 0 ] : L_29 , V_212 -> V_62 ) ;
if ( V_231 )
continue;
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
}
return 0 ;
V_54:
F_70 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_209 = V_220 -> V_209 ;
V_211 = V_220 -> V_211 ;
V_212 = V_220 -> V_212 ;
V_214 = V_220 -> V_214 ;
V_231 = V_220 -> V_231 ;
F_39 ( & V_220 -> V_234 ) ;
F_53 ( V_220 ) ;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_39 ( & V_153 -> V_136 ) ;
F_37 ( V_153 -> V_138 ) ;
F_23 ( V_128 , V_153 ) ;
}
F_53 ( V_214 -> V_130 ) ;
F_23 ( V_128 , V_214 ) ;
if ( V_231 )
continue;
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_209 ) ;
}
return V_20 ;
}
static int F_71 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_131 ,
int V_242 )
{
struct V_59 * V_179 ;
struct V_50 * V_51 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
unsigned char V_243 [ 512 ] , V_244 [ 32 ] ;
T_5 V_245 = 0 ;
int V_246 = 0 ;
memset ( V_3 , 0 , V_131 ) ;
if ( V_242 ) {
snprintf ( V_3 , V_131 ,
L_87 ) ;
return 0 ;
}
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
V_243 [ 0 ] = '\0' ;
V_244 [ 0 ] = '\0' ;
V_51 = V_2 -> V_120 -> V_52 ;
V_179 = V_2 -> V_143 ;
if ( V_2 -> V_5 )
snprintf ( V_244 , 32 , L_88 ,
V_2 -> V_6 ) ;
if ( V_15 -> V_118 == V_2 ) {
snprintf ( V_243 , 512 , L_89
L_90
L_91
L_92
L_93
L_94
L_95 , V_246 ,
V_51 -> V_57 -> V_58 () ,
V_2 -> V_120 -> V_63 , V_244 ,
V_2 -> V_119 , V_2 -> V_40 ,
V_2 -> V_168 , V_2 -> V_141 ,
V_2 -> V_139 ) ;
} else {
snprintf ( V_243 , 512 , L_96
L_97
L_98
L_99 ,
V_246 , V_51 -> V_57 -> V_58 () ,
V_2 -> V_120 -> V_63 , V_244 ,
V_2 -> V_119 , V_2 -> V_141 ,
V_2 -> V_139 ) ;
}
if ( ( V_245 + strlen ( V_243 ) >= V_131 ) ) {
F_10 ( L_100
L_101 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_247 ;
}
V_245 += sprintf ( V_3 + V_245 , L_33 , V_243 ) ;
snprintf ( V_243 , 512 , L_102
L_103
L_104 , V_51 -> V_57 -> V_58 () ,
V_51 -> V_57 -> V_180 ( V_51 ) ,
V_51 -> V_57 -> V_181 ( V_51 ) ,
V_179 -> V_248 -> V_240 , V_179 -> V_60 , V_246 ) ;
if ( ( V_245 + strlen ( V_243 ) >= V_131 ) ) {
F_10 ( L_100
L_101 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_247 ;
}
V_245 += sprintf ( V_3 + V_245 , L_33 , V_243 ) ;
V_246 ++ ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
if ( ! V_246 )
V_245 += sprintf ( V_3 + V_245 , L_105 ) ;
return 0 ;
}
static int F_72 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_131 ,
int V_242 )
{
int V_20 ;
F_4 ( & V_15 -> V_21 ) ;
V_20 = F_71 ( V_15 , V_3 , V_131 ,
V_242 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_73 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_131 )
{
struct V_249 * V_250 = & V_15 -> V_31 -> V_249 ;
struct V_251 * V_251 ;
struct V_252 V_253 [ 1 ] ;
T_6 V_254 ;
int V_255 = V_256 | V_257 | V_258 ;
char V_259 [ 512 ] ;
int V_20 ;
memset ( V_253 , 0 , sizeof( struct V_252 ) ) ;
memset ( V_259 , 0 , 512 ) ;
if ( strlen ( & V_250 -> V_260 [ 0 ] ) >= 512 ) {
F_10 ( L_106
L_107 ) ;
return - V_247 ;
}
snprintf ( V_259 , 512 , L_108 , & V_250 -> V_260 [ 0 ] ) ;
V_251 = F_74 ( V_259 , V_255 , 0600 ) ;
if ( F_75 ( V_251 ) || ! V_251 || ! V_251 -> V_261 ) {
F_10 ( L_109
L_81 , V_259 ) ;
return F_75 ( V_251 ) ? F_76 ( V_251 ) : - V_262 ;
}
V_253 [ 0 ] . V_263 = & V_3 [ 0 ] ;
if ( ! V_131 )
V_253 [ 0 ] . V_264 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_253 [ 0 ] . V_264 = V_131 ;
V_254 = F_77 () ;
F_78 ( F_79 () ) ;
V_20 = F_80 ( V_251 , & V_253 [ 0 ] , 1 , & V_251 -> V_265 ) ;
F_78 ( V_254 ) ;
if ( V_20 < 0 ) {
F_12 ( L_110 , V_259 ) ;
F_81 ( V_251 , NULL ) ;
return - V_266 ;
}
F_81 ( V_251 , NULL ) ;
return 0 ;
}
static int F_82 (
struct V_14 * V_15 ,
unsigned char * V_267 ,
T_1 V_268 )
{
unsigned char V_269 [ 64 ] , * V_3 ;
T_1 V_131 ;
int V_20 , V_242 = 0 ;
if ( ! V_267 ) {
memset ( V_269 , 0 , 64 ) ;
V_3 = & V_269 [ 0 ] ;
V_131 = 64 ;
V_242 = 1 ;
} else {
V_3 = V_267 ;
V_131 = V_268 ;
}
V_20 = F_72 ( V_15 , V_3 , V_131 ,
V_242 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_73 ( V_15 , V_3 , 0 ) ;
if ( V_20 != 0 )
return V_20 ;
return V_20 ;
}
static int F_83 (
struct V_7 * V_8 ,
T_2 V_270 ,
T_2 V_125 ,
int V_127 ,
int V_126 ,
int V_271 ,
int V_272 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_67 * V_61 ;
struct V_59 * V_59 = V_8 -> V_59 ;
struct V_50 * V_52 ;
struct V_1 * V_2 , * V_273 , * V_153 , * V_216 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_130 = NULL ;
unsigned char V_244 [ V_144 ] , * V_194 = NULL ;
int V_274 = 0 , V_20 = 0 , type ;
if ( ! V_19 || ! V_59 ) {
F_10 ( L_111 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
V_52 = V_19 -> V_52 ;
V_61 = V_19 -> V_23 -> V_75 [ V_8 -> V_76 ] ;
if ( V_52 -> V_57 -> V_191 ) {
memset ( & V_244 [ 0 ] , 0 , V_144 ) ;
V_52 -> V_57 -> V_191 ( V_19 , & V_244 [ 0 ] ,
V_144 ) ;
V_194 = & V_244 [ 0 ] ;
}
V_216 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_216 ) {
if ( V_270 ) {
F_64 ( L_112
L_113 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_125 )
return 0 ;
if ( ! V_271 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_19 -> V_23 , V_61 , V_194 ,
V_125 , V_126 , V_127 ,
V_272 , 0 ) ;
if ( V_20 != 0 ) {
F_10 ( L_114
L_115 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
} else {
V_20 = F_62 ( V_8 , V_52 ,
V_194 , V_125 , V_126 , V_127 ) ;
if ( V_20 != 0 )
return V_20 ;
}
if ( ! V_127 ) {
V_33 -> V_183 = 0 ;
F_82 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_116
L_117 ) ;
return 0 ;
}
V_2 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
V_20 = F_82 ( V_8 -> V_16 ,
& V_2 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 ) {
V_33 -> V_183 = 1 ;
F_12 ( L_118 ) ;
}
F_8 ( V_2 ) ;
return V_20 ;
} else {
V_2 = V_216 ;
type = V_2 -> V_40 ;
if ( ! V_272 ) {
if ( V_270 != V_2 -> V_119 ) {
F_10 ( L_119
L_120
L_121
L_122 , V_270 ,
V_2 -> V_119 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
}
if ( V_271 ) {
F_10 ( L_123
L_124 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
if ( V_2 -> V_141 && ! ( V_126 ) ) {
F_10 ( L_125
L_126
L_127 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
if ( V_127 ) {
V_130 = F_22 ( V_33 -> V_131 ,
V_166 ) ;
if ( ! V_130 ) {
F_10 ( L_114
L_128 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 =
V_233 ;
return - V_24 ;
}
}
if ( ! V_125 ) {
V_274 = F_48 (
V_8 -> V_16 , V_2 ) ;
if ( V_274 < 0 ) {
F_53 ( V_130 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_33 -> V_45 ) ;
if ( V_2 -> V_141 ) {
F_28 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_273 -> V_141 )
continue;
if ( V_273 -> V_119 != V_270 )
continue;
if ( V_2 == V_273 )
continue;
if ( strcmp ( V_2 -> V_120 -> V_63 ,
V_273 -> V_120 -> V_63 ) )
continue;
F_50 ( V_15 ,
V_273 , NULL , 0 ) ;
}
}
F_50 ( V_8 -> V_16 , V_2 ,
NULL , 1 ) ;
if ( V_274 &&
( ( type == V_41 ) ||
( type == V_42 ) ) ) {
F_32 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_84 (
V_273 -> V_120 ,
V_273 -> V_139 ,
0x2A ,
V_276 ) ;
}
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_127 ) {
V_33 -> V_183 = 0 ;
F_82 ( V_15 , NULL , 0 ) ;
F_12 ( L_129
L_130 ) ;
return 0 ;
}
V_20 = F_82 ( V_15 ,
& V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 ) {
V_33 -> V_183 = 1 ;
F_12 ( L_131
L_130 ) ;
}
F_53 ( V_130 ) ;
return V_20 ;
} else {
V_2 -> V_188 = F_18 (
V_8 -> V_16 ) ;
V_2 -> V_119 = V_125 ;
F_12 ( L_132
L_133
L_60 , V_8 -> V_277 -> V_58 () ,
( V_272 ) ? L_46 : L_29 ,
V_2 -> V_120 -> V_63 ,
V_2 -> V_119 , V_2 -> V_188 ) ;
if ( ! V_127 ) {
V_33 -> V_183 = 0 ;
F_82 ( V_15 , NULL , 0 ) ;
F_8 ( V_2 ) ;
F_12 ( L_129
L_134 ) ;
return 0 ;
}
V_20 = F_82 ( V_15 ,
& V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 ) {
V_33 -> V_183 = 1 ;
F_12 ( L_131
L_134 ) ;
}
F_53 ( V_130 ) ;
F_8 ( V_2 ) ;
}
}
return 0 ;
}
unsigned char * F_16 ( int type )
{
switch ( type ) {
case V_77 :
return L_135 ;
case V_78 :
return L_136 ;
case V_41 :
return L_137 ;
case V_42 :
return L_138 ;
case V_43 :
return L_139 ;
case V_44 :
return L_140 ;
default:
break;
}
return L_141 ;
}
static int F_85 (
struct V_7 * V_8 ,
struct V_14 * V_15 ,
int type ,
int V_278 ,
T_2 V_270 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_59 * V_59 = V_8 -> V_59 ;
struct V_1 * V_2 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_176 [ V_177 ] ;
int V_20 , V_178 ;
memset ( V_176 , 0 , V_177 ) ;
if ( ! V_19 || ! V_59 ) {
F_10 ( L_111 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_142
L_143 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
if ( V_270 != V_2 -> V_119 ) {
F_10 ( L_144
L_145
L_122 , V_270 , V_2 -> V_119 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_278 != V_279 ) {
F_10 ( L_146 , V_278 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( V_39 ) {
if ( V_39 != V_2 ) {
struct V_23 * V_198 = V_39 -> V_120 ;
F_10 ( L_147
L_148
L_149 ,
V_8 -> V_277 -> V_58 () ,
V_19 -> V_23 -> V_63 ,
V_198 -> V_52 -> V_57 -> V_58 () ,
V_39 -> V_120 -> V_63 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_168 != V_278 ) ) {
struct V_23 * V_198 = V_39 -> V_120 ;
F_10 ( L_147
L_150
L_151
L_4 ,
V_8 -> V_277 -> V_58 () ,
V_19 -> V_23 -> V_63 ,
V_198 -> V_52 -> V_57 -> V_58 () ,
V_39 -> V_120 -> V_63 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
V_2 -> V_168 = V_278 ;
V_2 -> V_40 = type ;
V_2 -> V_39 = 1 ;
V_15 -> V_118 = V_2 ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
F_12 ( L_152
L_153 ,
V_8 -> V_277 -> V_58 () , F_16 ( type ) ,
( V_2 -> V_141 ) ? 1 : 0 ) ;
F_12 ( L_42 ,
V_8 -> V_277 -> V_58 () ,
V_19 -> V_23 -> V_63 ,
( V_178 ) ? & V_176 [ 0 ] : L_29 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_183 ) {
V_20 = F_82 ( V_8 -> V_16 ,
& V_2 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 )
F_12 ( L_154
L_155 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_86 (
struct V_7 * V_8 ,
int type ,
int V_278 ,
T_2 V_270 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
int V_20 = 0 ;
switch ( type ) {
case V_77 :
case V_78 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_85 ( V_8 , V_15 , type , V_278 , V_270 ) ;
break;
default:
F_10 ( L_156
L_157 , type ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
return V_20 ;
}
static void F_49 (
struct V_14 * V_15 ,
struct V_23 * V_280 ,
struct V_1 * V_2 ,
int V_281 )
{
struct V_150 * V_151 = V_280 -> V_52 -> V_57 ;
char V_176 [ V_177 ] ;
int V_178 ;
memset ( V_176 , 0 , V_177 ) ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
V_15 -> V_118 = NULL ;
F_12 ( L_158
L_153 ,
V_151 -> V_58 () , ( V_281 ) ? L_159 : L_160 ,
F_16 ( V_2 -> V_40 ) ,
( V_2 -> V_141 ) ? 1 : 0 ) ;
F_12 ( L_161 ,
V_151 -> V_58 () , V_280 -> V_63 ,
( V_178 ) ? & V_176 [ 0 ] : L_29 ) ;
V_2 -> V_39 = V_2 -> V_40 = V_2 -> V_168 = 0 ;
}
static int F_87 (
struct V_7 * V_8 ,
int type ,
int V_278 ,
T_2 V_270 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_59 * V_59 = V_8 -> V_59 ;
struct V_1 * V_2 , * V_273 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
int V_20 , V_71 = 0 ;
if ( ! V_19 || ! V_59 ) {
F_10 ( L_111 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
V_2 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_142
L_162 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) )
V_71 = 1 ;
if ( ( V_71 == 0 ) && ( V_39 != V_2 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( V_270 != V_2 -> V_119 ) {
F_10 ( L_163
L_145
L_122 , V_270 , V_2 -> V_119 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_168 != V_278 ) ) {
struct V_23 * V_198 = V_39 -> V_120 ;
F_10 ( L_164
L_165
L_166
L_149 ,
V_8 -> V_277 -> V_58 () ,
V_19 -> V_23 -> V_63 ,
V_198 -> V_52 -> V_57 -> V_58 () ,
V_39 -> V_120 -> V_63 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_49 ( V_15 , V_19 -> V_23 ,
V_2 , 1 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( ( type != V_41 ) &&
( type != V_42 ) &&
( type != V_43 ) &&
( type != V_44 ) ) {
goto V_282;
}
F_4 ( & V_33 -> V_45 ) ;
F_32 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_273 == V_2 )
continue;
F_84 ( V_273 -> V_120 ,
V_273 -> V_139 ,
0x2A , V_276 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
V_282:
if ( V_33 -> V_183 ) {
V_20 = F_82 ( V_8 -> V_16 ,
& V_2 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 )
F_12 ( L_167 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_88 (
struct V_7 * V_8 ,
T_2 V_270 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_120 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_153 , * V_283 , * V_39 ;
T_1 V_139 = 0 ;
int V_284 = 0 ;
V_283 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
if ( ! V_283 ) {
F_10 ( L_142
L_168 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
if ( V_270 != V_283 -> V_119 ) {
F_10 ( L_119
L_120
L_121
L_122 , V_270 , V_283 -> V_119 ) ;
F_8 ( V_283 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( V_39 ) {
struct V_23 * V_198 = V_39 -> V_120 ;
F_49 ( V_15 , V_198 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_284 = ( V_283 == V_2 ) ? 1 : 0 ;
V_120 = V_2 -> V_120 ;
V_139 = V_2 -> V_139 ;
F_50 ( V_15 , V_2 , NULL ,
V_284 ) ;
if ( ! V_284 )
F_84 ( V_120 , V_139 ,
0x2A , V_285 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_169 ,
V_8 -> V_277 -> V_58 () ) ;
if ( V_33 -> V_183 ) {
F_82 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_154
L_170 ) ;
}
F_18 ( V_15 ) ;
return 0 ;
}
static void F_89 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_195 * V_196 ,
int type ,
int V_278 ,
int abort )
{
struct V_23 * V_122 = V_2 -> V_120 ;
struct V_150 * V_151 = V_122 -> V_52 -> V_57 ;
char V_176 [ V_177 ] ;
int V_178 ;
memset ( V_176 , 0 , V_177 ) ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
if ( V_15 -> V_118 )
F_49 ( V_15 , V_122 ,
V_15 -> V_118 , 0 ) ;
V_15 -> V_118 = V_2 ;
V_2 -> V_39 = 1 ;
V_2 -> V_40 = type ;
V_2 -> V_168 = V_278 ;
F_12 ( L_171
L_153 ,
V_151 -> V_58 () , ( abort ) ? L_172 : L_29 ,
F_16 ( type ) ,
( V_2 -> V_141 ) ? 1 : 0 ) ;
F_12 ( L_173 ,
V_151 -> V_58 () , ( abort ) ? L_172 : L_29 ,
V_122 -> V_63 , ( V_178 ) ? & V_176 [ 0 ] : L_29 ) ;
if ( V_196 )
F_38 ( & V_2 -> V_133 ,
V_196 ) ;
}
static void F_90 (
struct V_195 * V_196 ,
struct V_1 * V_286 )
{
struct V_1 * V_2 , * V_153 ;
F_28 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_39 ( & V_2 -> V_133 ) ;
if ( V_286 == V_2 )
continue;
if ( V_2 -> V_39 ) {
F_64 ( L_174 ) ;
continue;
}
V_2 -> V_138 = NULL ;
V_2 -> V_120 = NULL ;
F_53 ( V_2 -> V_130 ) ;
F_23 ( V_128 , V_2 ) ;
}
}
static int F_91 (
struct V_7 * V_8 ,
int type ,
int V_278 ,
T_2 V_270 ,
T_2 V_125 ,
int abort )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_120 ;
struct V_17 * V_19 = V_8 -> V_19 ;
F_63 ( V_196 ) ;
struct V_1 * V_2 , * V_153 , * V_283 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
T_1 V_139 = 0 ;
int V_71 = 0 , V_284 = 0 , V_287 = 0 ;
int V_288 = 0 , V_289 = 0 , V_20 ;
if ( ! V_19 ) {
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
V_283 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_283 ) {
F_10 ( L_142
L_175 ,
( abort ) ? L_172 : L_29 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_283 -> V_119 != V_270 ) {
F_8 ( V_283 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_278 != V_279 ) {
F_10 ( L_146 , V_278 ) ;
F_8 ( V_283 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( V_39 &&
( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) )
V_71 = 1 ;
if ( ! V_71 && ! V_125 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_283 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
if ( ! V_39 || ( V_39 -> V_119 != V_125 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_71 ) {
if ( V_2 -> V_119 != V_125 )
continue;
V_284 = ( V_283 == V_2 ) ? 1 : 0 ;
V_120 = V_2 -> V_120 ;
V_139 = V_2 -> V_139 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_196 :
NULL , V_284 ) ;
V_287 ++ ;
} else {
if ( ( V_125 ) &&
( V_2 -> V_119 != V_125 ) )
continue;
V_284 = ( V_283 == V_2 ) ? 1 : 0 ;
if ( V_284 )
continue;
V_120 = V_2 -> V_120 ;
V_139 = V_2 -> V_139 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_196 :
NULL , 0 ) ;
V_287 ++ ;
}
if ( ! V_284 )
F_84 ( V_120 ,
V_139 , 0x2A ,
V_290 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_287 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_283 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_39 && V_71 && ! ( V_125 ) ) {
F_89 ( V_15 , V_283 ,
( abort ) ? & V_196 : NULL ,
type , V_278 , abort ) ;
if ( abort )
F_90 (
& V_196 , V_283 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_183 ) {
V_20 = F_82 ( V_8 -> V_16 ,
& V_283 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 )
F_12 ( L_176
L_177 , ( abort ) ?
L_172 : L_29 ) ;
}
F_8 ( V_283 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
V_288 = V_39 -> V_40 ;
V_289 = V_39 -> V_168 ;
if ( V_283 != V_39 )
F_49 ( V_15 ,
V_39 -> V_120 ,
V_15 -> V_118 , 0 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_284 = ( V_283 == V_2 ) ? 1 : 0 ;
if ( V_284 )
continue;
if ( V_2 -> V_119 != V_125 )
continue;
V_120 = V_2 -> V_120 ;
V_139 = V_2 -> V_139 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_196 : NULL ,
V_284 ) ;
F_84 ( V_120 , V_139 , 0x2A ,
V_290 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_89 ( V_15 , V_283 ,
( abort ) ? & V_196 : NULL ,
type , V_278 , abort ) ;
if ( ( V_288 != type ) || ( V_289 != V_278 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_284 = ( V_283 == V_2 ) ? 1 : 0 ;
if ( V_284 )
continue;
F_84 ( V_2 -> V_120 ,
V_2 -> V_139 , 0x2A ,
V_276 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( abort ) {
F_92 ( V_15 , NULL , & V_196 , V_8 ) ;
F_90 ( & V_196 ,
V_283 ) ;
}
if ( V_33 -> V_183 ) {
V_20 = F_82 ( V_8 -> V_16 ,
& V_283 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 )
F_12 ( L_178
L_179 , ( abort ) ? L_172 : L_29 ) ;
}
F_8 ( V_283 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_93 (
struct V_7 * V_8 ,
int type ,
int V_278 ,
T_2 V_270 ,
T_2 V_125 ,
int abort )
{
int V_20 = 0 ;
switch ( type ) {
case V_77 :
case V_78 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_91 ( V_8 , type , V_278 ,
V_270 , V_125 , abort ) ;
break;
default:
F_10 ( L_180
L_181 , ( abort ) ? L_172 : L_29 , type ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
return V_20 ;
}
static int F_94 (
struct V_7 * V_8 ,
T_2 V_270 ,
T_2 V_125 ,
int V_127 ,
int V_291 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_67 * V_212 = NULL ;
struct V_59 * V_59 = V_8 -> V_59 ;
struct V_23 * V_198 , * V_120 , * V_211 = NULL ;
struct V_147 * V_147 ;
struct V_50 * V_52 , * V_292 = NULL ;
struct V_150 * V_293 = NULL , * V_294 ;
struct V_1 * V_2 , * V_39 , * V_214 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
unsigned char * V_295 ;
char * V_227 = NULL , V_228 [ 64 ] , V_176 [ V_177 ] ;
T_1 V_230 , V_296 ;
int V_297 = 0 , type , V_278 , V_20 , V_298 , V_178 ;
unsigned short V_299 ;
unsigned char V_225 ;
if ( ! V_19 || ! V_59 ) {
F_10 ( L_111 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
memset ( V_228 , 0 , 64 ) ;
memset ( V_176 , 0 , V_177 ) ;
V_52 = V_19 -> V_52 ;
V_294 = V_52 -> V_57 ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_182
L_183 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
if ( V_270 != V_2 -> V_119 ) {
F_64 ( L_184
L_185
L_186 , V_270 , V_2 -> V_119 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_125 ) {
F_64 ( L_187
L_188 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_299 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_299 |= V_3 [ 19 ] & 0xff ;
V_230 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_230 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_230 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_230 |= V_3 [ 23 ] & 0xff ;
F_70 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_230 + 24 ) != V_8 -> V_235 ) {
F_10 ( L_189
L_65 , V_230 ,
V_8 -> V_235 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_155 ) ;
F_32 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_147 -> V_240 != V_299 )
continue;
V_292 = V_147 -> V_237 ;
if ( ! V_292 )
continue;
V_293 = V_292 -> V_57 ;
if ( ! V_293 )
continue;
F_29 ( & V_292 -> V_202 ) ;
F_30 () ;
F_5 ( & V_15 -> V_155 ) ;
V_20 = F_56 ( V_292 ) ;
if ( V_20 != 0 ) {
F_10 ( L_190
L_191 ) ;
F_35 ( & V_292 -> V_202 ) ;
F_36 () ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_233 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_155 ) ;
break;
}
F_5 ( & V_15 -> V_155 ) ;
if ( ! V_292 || ! V_293 ) {
F_10 ( L_192
L_193
L_194 , V_299 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_236 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_225 = ( V_3 [ 24 ] & 0x0f ) ;
F_12 ( L_195
L_157 , V_225 ) ;
if ( V_225 != V_293 -> V_238 ( V_292 ) ) {
F_10 ( L_184
L_196
L_197 , V_225 ,
V_293 -> V_238 ( V_292 ) ,
V_293 -> V_58 () ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
if ( V_293 -> V_239 == NULL ) {
F_10 ( L_198
L_199
L_200 ) ;
V_8 -> V_47 = V_233 ;
V_20 = - V_24 ;
goto V_54;
}
V_295 = V_293 -> V_239 ( V_292 ,
( const char * ) & V_3 [ 24 ] , & V_296 , & V_227 ) ;
if ( ! V_295 ) {
F_10 ( L_192
L_201 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
F_70 ( V_8 ) ;
V_3 = NULL ;
F_12 ( L_202
L_203 , V_293 -> V_58 () , ( V_227 != NULL ) ?
L_204 : L_205 , V_295 , ( V_227 != NULL ) ?
V_227 : L_29 ) ;
V_120 = V_2 -> V_120 ;
V_298 = ( ! strcmp ( V_295 ,
V_120 -> V_63 ) ) ? 1 : 0 ;
if ( ! V_298 )
goto V_300;
if ( ! V_227 || ! V_2 -> V_5 ) {
F_10 ( L_206
L_207 , V_295 ,
V_120 -> V_63 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
if ( ! strcmp ( V_227 , V_2 -> V_6 ) ) {
F_10 ( L_208
L_209 ,
V_295 , V_227 , V_120 -> V_63 ,
V_2 -> V_6 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_300:
F_66 ( & V_292 -> V_241 ) ;
V_211 = F_67 ( V_292 ,
V_295 ) ;
if ( V_211 ) {
F_29 ( & V_211 -> V_205 ) ;
F_30 () ;
}
F_68 ( & V_292 -> V_241 ) ;
if ( ! V_211 ) {
F_10 ( L_210
L_211 , V_293 -> V_58 () ,
V_295 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_20 = F_60 ( V_211 ) ;
if ( V_20 != 0 ) {
F_10 ( L_212
L_213 ) ;
F_35 ( & V_211 -> V_205 ) ;
F_36 () ;
V_211 = NULL ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
F_12 ( L_214
L_215 , V_293 -> V_58 () ,
V_211 -> V_63 ) ;
V_212 = F_69 ( V_211 , V_299 ) ;
if ( ! V_212 ) {
F_10 ( L_216
L_194 , V_293 -> V_58 () , V_299 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_20 = F_34 ( V_212 ) ;
if ( V_20 < 0 ) {
F_10 ( L_217 ) ;
F_35 ( & V_212 -> V_160 ) ;
F_36 () ;
V_212 = NULL ;
V_8 -> V_47 = V_233 ;
V_20 = - V_24 ;
goto V_54;
}
F_12 ( L_218
L_219 ,
V_293 -> V_58 () , V_211 -> V_63 ,
V_212 -> V_62 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_118 ;
if ( ! V_39 ) {
F_64 ( L_220
L_221 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_275 ;
V_20 = - V_24 ;
goto V_54;
}
if ( V_39 != V_2 ) {
F_64 ( L_222
L_223 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_54;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) {
F_64 ( L_224
L_225 ,
F_16 ( V_39 -> V_40 ) ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_54;
}
V_198 = V_39 -> V_120 ;
type = V_39 -> V_40 ;
V_278 = V_39 -> V_40 ;
V_214 = F_47 ( V_15 , V_211 ,
V_227 ) ;
if ( ! V_214 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_211 , V_212 , V_227 ,
V_125 , 0 , V_127 , 2 , 1 ) ;
if ( V_20 != 0 ) {
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_214 = F_47 ( V_15 , V_211 ,
V_227 ) ;
V_297 = 1 ;
}
F_49 ( V_15 , V_198 ,
V_15 -> V_118 , 0 ) ;
V_15 -> V_118 = V_214 ;
V_214 -> V_39 = 1 ;
V_214 -> V_40 = type ;
V_2 -> V_168 = V_278 ;
V_178 = F_1 ( V_2 , & V_176 [ 0 ] ,
V_177 ) ;
if ( ! V_297 )
V_214 -> V_188 = V_33 -> V_117 ++ ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_226
L_227
L_228 , V_293 -> V_58 () ,
F_16 ( type ) , V_299 ,
V_214 -> V_188 ) ;
F_12 ( L_229
L_230 ,
V_294 -> V_58 () , V_120 -> V_63 ,
( V_178 ) ? & V_176 [ 0 ] : L_29 , V_293 -> V_58 () ,
V_211 -> V_63 , ( V_227 != NULL ) ?
V_227 : L_29 ) ;
F_37 ( V_212 ) ;
F_61 ( V_211 ) ;
F_58 ( V_292 ) ;
if ( V_291 ) {
F_4 ( & V_33 -> V_45 ) ;
F_50 ( V_15 , V_2 , NULL , 1 ) ;
F_5 ( & V_33 -> V_45 ) ;
} else
F_8 ( V_2 ) ;
if ( ! V_127 ) {
V_33 -> V_183 = 0 ;
F_82 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_116
L_231 ) ;
} else {
V_33 -> V_183 = 1 ;
V_20 = F_82 ( V_8 -> V_16 ,
& V_214 -> V_130 [ 0 ] ,
V_33 -> V_131 ) ;
if ( ! V_20 )
F_12 ( L_232
L_231 ) ;
}
F_70 ( V_8 ) ;
F_8 ( V_214 ) ;
return 0 ;
V_54:
if ( V_3 )
F_70 ( V_8 ) ;
if ( V_212 )
F_37 ( V_212 ) ;
if ( V_211 )
F_61 ( V_211 ) ;
F_58 ( V_292 ) ;
F_8 ( V_2 ) ;
return V_20 ;
}
static unsigned long long F_95 ( unsigned char * V_9 )
{
unsigned int V_301 , V_302 ;
V_301 = ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_302 = ( V_9 [ 4 ] << 24 ) | ( V_9 [ 5 ] << 16 ) | ( V_9 [ 6 ] << 8 ) | V_9 [ 7 ] ;
return ( ( unsigned long long ) V_302 ) | ( unsigned long long ) V_301 << 32 ;
}
int F_96 ( struct V_7 * V_8 )
{
unsigned char * V_9 = & V_8 -> V_65 [ 0 ] ;
unsigned char * V_3 ;
T_2 V_270 , V_125 ;
int V_303 , V_278 , type , V_127 ;
int V_271 = 0 , V_126 = 0 , V_291 = 0 ;
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_56 ) {
F_10 ( L_233
L_234
L_235 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_54;
}
if ( ! V_8 -> V_19 ) {
V_8 -> V_47 = V_233 ;
V_20 = - V_24 ;
goto V_54;
}
if ( V_8 -> V_235 < 24 ) {
F_64 ( L_62
L_63 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
V_303 = ( V_9 [ 1 ] & 0x1f ) ;
V_278 = ( V_9 [ 2 ] & 0xf0 ) ;
type = ( V_9 [ 2 ] & 0x0f ) ;
V_3 = F_65 ( V_8 ) ;
V_270 = F_95 ( & V_3 [ 0 ] ) ;
V_125 = F_95 ( & V_3 [ 8 ] ) ;
if ( V_303 != V_92 ) {
V_271 = ( V_3 [ 20 ] & 0x08 ) ;
V_126 = ( V_3 [ 20 ] & 0x04 ) ;
V_127 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_127 = ( V_3 [ 17 ] & 0x01 ) ;
V_291 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_70 ( V_8 ) ;
V_3 = NULL ;
if ( V_271 && ( ( V_9 [ 1 ] & 0x1f ) != V_90 ) ) {
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
if ( ! V_271 && ( ( V_9 [ 1 ] & 0x1f ) != V_92 ) &&
( V_8 -> V_235 != 24 ) ) {
F_64 ( L_236
L_237 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_236 ;
V_20 = - V_24 ;
goto V_54;
}
switch ( V_303 ) {
case V_90 :
V_20 = F_83 ( V_8 ,
V_270 , V_125 , V_127 , V_126 , V_271 , 0 ) ;
break;
case V_93 :
V_20 = F_86 ( V_8 , type , V_278 , V_270 ) ;
break;
case V_94 :
V_20 = F_87 ( V_8 , type , V_278 , V_270 ) ;
break;
case V_87 :
V_20 = F_88 ( V_8 , V_270 ) ;
break;
case V_88 :
V_20 = F_93 ( V_8 , type , V_278 ,
V_270 , V_125 , 0 ) ;
break;
case V_89 :
V_20 = F_93 ( V_8 , type , V_278 ,
V_270 , V_125 , 1 ) ;
break;
case V_91 :
V_20 = F_83 ( V_8 ,
0 , V_125 , V_127 , V_126 , V_271 , 1 ) ;
break;
case V_92 :
V_20 = F_94 ( V_8 , V_270 ,
V_125 , V_127 , V_291 ) ;
break;
default:
F_10 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_275 ;
V_20 = - V_24 ;
break;
}
V_54:
if ( ! V_20 )
F_13 ( V_8 , V_64 ) ;
return V_20 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_304 = 0 , V_305 = 8 ;
if ( V_8 -> V_235 < 8 ) {
F_10 ( L_238
L_239 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_117 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_117 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_117 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_117 & 0xff ) ;
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_304 + 8 ) > ( V_8 -> V_235 - 8 ) )
break;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 56 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 48 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 40 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 32 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 24 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 16 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_2 -> V_119 & 0xff ) ;
V_304 += 8 ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
V_3 [ 4 ] = ( ( V_304 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_304 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_304 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_304 & 0xff ) ;
F_70 ( V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_2 V_119 ;
T_1 V_304 = 16 ;
if ( V_8 -> V_235 < 8 ) {
F_10 ( L_240
L_239 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_117 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_117 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_117 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_117 & 0xff ) ;
F_4 ( & V_16 -> V_21 ) ;
V_2 = V_16 -> V_118 ;
if ( V_2 ) {
V_3 [ 4 ] = ( ( V_304 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_304 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_304 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_304 & 0xff ) ;
if ( V_8 -> V_235 < 22 )
goto V_306;
if ( ( V_2 -> V_40 == V_43 ) ||
( V_2 -> V_40 == V_44 ) )
V_119 = 0 ;
else
V_119 = V_2 -> V_119 ;
V_3 [ 8 ] = ( ( V_119 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_119 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_119 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_119 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_119 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_119 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_119 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_119 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_168 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
}
V_306:
F_5 ( & V_16 -> V_21 ) ;
F_70 ( V_8 ) ;
return 0 ;
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_3 V_304 = 8 ;
if ( V_8 -> V_235 < 6 ) {
F_10 ( L_241
L_242 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_304 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_304 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_33 -> V_183 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
F_70 ( V_8 ) ;
return 0 ;
}
static int F_100 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_23 * V_280 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_50 * V_52 ;
struct V_1 * V_2 , * V_153 ;
struct V_32 * V_33 = & V_16 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_1 V_307 = 0 , V_304 = 0 , V_308 , V_309 ;
T_1 V_305 = 8 ;
int V_310 = 0 ;
if ( V_8 -> V_235 < 8 ) {
F_10 ( L_243
L_239 , V_8 -> V_235 ) ;
V_8 -> V_47 = V_275 ;
return - V_24 ;
}
V_3 = F_65 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_117 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_117 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_117 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_117 & 0xff ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_280 = V_2 -> V_120 ;
V_52 = V_2 -> V_120 -> V_52 ;
V_307 = 0 ;
F_29 ( & V_2 -> V_137 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
V_309 = V_52 -> V_57 -> V_311 (
V_52 , V_280 , V_2 , & V_310 ) ;
if ( ( V_309 + V_304 ) > V_8 -> V_235 ) {
F_64 ( L_244
L_245 , V_8 -> V_235 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_137 ) ;
F_36 () ;
break;
}
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 56 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 48 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 40 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 32 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 24 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 16 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_119 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_2 -> V_119 & 0xff ) ;
V_305 += 4 ;
if ( V_2 -> V_141 )
V_3 [ V_305 ] = 0x02 ;
if ( V_2 -> V_39 ) {
V_3 [ V_305 ++ ] |= 0x01 ;
V_3 [ V_305 ++ ] = ( V_2 -> V_168 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
} else
V_305 += 2 ;
V_305 += 4 ;
if ( ! V_2 -> V_141 ) {
struct V_147 * V_148 = V_2 -> V_143 -> V_248 ;
V_3 [ V_305 ++ ] = ( ( V_148 -> V_240 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_148 -> V_240 & 0xff ) ;
} else
V_305 += 2 ;
V_308 = V_52 -> V_57 -> V_312 ( V_52 ,
V_280 , V_2 , & V_310 , & V_3 [ V_305 + 4 ] ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_137 ) ;
F_36 () ;
V_3 [ V_305 ++ ] = ( ( V_308 >> 24 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_308 >> 16 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_308 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_308 & 0xff ) ;
V_307 = ( 24 + V_308 ) ;
V_305 += V_308 ;
V_304 += V_307 ;
}
F_5 ( & V_33 -> V_45 ) ;
V_3 [ 4 ] = ( ( V_304 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_304 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_304 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_304 & 0xff ) ;
F_70 ( V_8 ) ;
return 0 ;
}
int F_101 ( struct V_7 * V_8 )
{
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_56 ) {
F_10 ( L_233
L_234
L_235 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
switch ( V_8 -> V_65 [ 1 ] & 0x1f ) {
case V_313 :
V_20 = F_97 ( V_8 ) ;
break;
case V_314 :
V_20 = F_98 ( V_8 ) ;
break;
case V_315 :
V_20 = F_99 ( V_8 ) ;
break;
case V_316 :
V_20 = F_100 ( V_8 ) ;
break;
default:
F_10 ( L_246
L_16 , V_8 -> V_65 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_275 ;
V_20 = - V_24 ;
break;
}
if ( ! V_20 )
F_13 ( V_8 , V_64 ) ;
return V_20 ;
}
static int F_102 ( struct V_7 * V_8 , T_1 * V_40 )
{
return 0 ;
}
static int F_103 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
return 0 ;
}
int F_104 ( struct V_14 * V_15 , int V_317 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_32 * V_318 = & V_30 -> V_34 ;
if ( ( ( V_15 -> V_186 -> V_319 == V_320 ) &&
! ( V_15 -> V_31 -> V_192 . V_321 ) ) || V_317 ) {
V_318 -> V_36 = V_322 ;
V_318 -> V_323 . V_324 = & F_102 ;
V_318 -> V_323 . V_325 = & F_103 ;
F_12 ( L_247
L_248 , V_15 -> V_186 -> V_187 ) ;
return 0 ;
}
if ( V_15 -> V_186 -> V_326 ( V_15 ) >= V_327 ) {
V_318 -> V_36 = V_37 ;
V_318 -> V_323 . V_324 = & F_19 ;
V_318 -> V_323 . V_325 = & F_15 ;
F_12 ( L_249
L_248 , V_15 -> V_186 -> V_187 ) ;
} else {
V_318 -> V_36 = V_328 ;
V_318 -> V_323 . V_324 = & F_3 ;
V_318 -> V_323 . V_325 =
& F_2 ;
F_12 ( L_250 ,
V_15 -> V_186 -> V_187 ) ;
}
return 0 ;
}
