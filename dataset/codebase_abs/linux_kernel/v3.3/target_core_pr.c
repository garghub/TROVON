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
int F_11 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_53 * V_54 = V_18 -> V_55 ;
int V_20 = 0 , V_56 ;
if ( ! V_18 || ! V_54 )
goto V_57;
V_56 = F_6 ( V_8 ) ;
if ( V_56 == 1 )
goto V_57;
else if ( V_56 < 0 ) {
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_57;
}
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 )
goto V_58;
if ( V_15 -> V_22 != V_18 -> V_23 )
goto V_58;
V_15 -> V_22 = NULL ;
V_15 -> V_25 &= ~ V_59 ;
if ( V_15 -> V_25 & V_26 ) {
V_15 -> V_27 = 0 ;
V_15 -> V_25 &= ~ V_26 ;
}
F_12 ( L_5
L_6 , V_54 -> V_60 -> V_61 () ,
V_8 -> V_62 -> V_63 , V_8 -> V_64 -> V_65 ,
V_18 -> V_23 -> V_66 ) ;
V_58:
F_5 ( & V_15 -> V_21 ) ;
V_57:
if ( ! V_20 ) {
V_51 -> V_67 = V_68 ;
F_13 ( V_51 , 1 ) ;
}
return V_20 ;
}
int F_14 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_53 * V_54 = V_18 -> V_55 ;
int V_20 = 0 , V_56 ;
if ( ( V_8 -> V_69 [ 1 ] & 0x01 ) &&
( V_8 -> V_69 [ 1 ] & 0x02 ) ) {
F_10 ( L_7
L_8 ) ;
V_8 -> V_47 = V_70 ;
V_20 = - V_24 ;
goto V_57;
}
if ( ! V_18 || ! V_54 )
goto V_57;
V_56 = F_6 ( V_8 ) ;
if ( V_56 == 1 )
goto V_57;
else if ( V_56 < 0 ) {
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_57;
}
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_22 &&
( V_15 -> V_22 != V_18 -> V_23 ) ) {
F_10 ( L_9 ,
V_54 -> V_60 -> V_61 () ) ;
F_10 ( L_10 ,
V_8 -> V_62 -> V_63 ,
V_15 -> V_22 -> V_66 ) ;
F_10 ( L_11
L_12 , V_8 -> V_62 -> V_63 ,
V_8 -> V_64 -> V_65 ,
V_18 -> V_23 -> V_66 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_58;
}
V_15 -> V_22 = V_18 -> V_23 ;
V_15 -> V_25 |= V_59 ;
if ( V_18 -> V_28 != 0 ) {
V_15 -> V_27 = V_18 -> V_28 ;
V_15 -> V_25 |= V_26 ;
}
F_12 ( L_13
L_14 , V_54 -> V_60 -> V_61 () ,
V_8 -> V_62 -> V_63 , V_8 -> V_64 -> V_65 ,
V_18 -> V_23 -> V_66 ) ;
V_58:
F_5 ( & V_15 -> V_21 ) ;
V_57:
if ( ! V_20 ) {
V_51 -> V_67 = V_68 ;
F_13 ( V_51 , 1 ) ;
}
return V_20 ;
}
static int F_15 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
struct V_71 * V_64 ;
struct V_17 * V_19 = V_8 -> V_19 ;
int V_72 = 0 , V_73 ;
int V_74 = 0 , V_20 = 1 ;
int V_75 = 0 , V_76 = 0 ;
int V_77 = 0 ;
int V_78 = 0 ;
if ( V_8 -> V_16 -> V_25 & V_59 )
return F_2 ( V_8 ,
V_9 , V_10 ) ;
V_64 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
V_73 = ( V_10 & 0x80000000 ) ;
if ( V_73 )
V_10 &= ~ 0x80000000 ;
switch ( V_10 ) {
case V_81 :
V_77 = 1 ;
case V_82 :
if ( ( V_64 -> V_83 ) && ! ( V_73 ) )
V_74 = 1 ;
break;
case V_41 :
V_77 = 1 ;
case V_42 :
V_76 = 1 ;
if ( ( V_64 -> V_83 ) && ! ( V_73 ) )
V_74 = 1 ;
break;
case V_43 :
V_77 = 1 ;
case V_44 :
V_75 = 1 ;
if ( ( V_64 -> V_83 ) && ! ( V_73 ) )
V_74 = 1 ;
break;
default:
return - V_24 ;
}
switch ( V_9 [ 0 ] ) {
case V_84 :
if ( V_74 )
return 0 ;
V_20 = ( V_77 ) ? 0 : 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( V_78 ) {
V_20 = 1 ;
break;
}
if ( V_74 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_77 ) ? 0 : 1 ;
break;
case V_90 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_91 :
case V_92 :
case V_93 :
V_20 = ( V_74 ) ? 0 : 1 ;
break;
case V_94 :
case V_95 :
V_20 = 0 ;
break;
case V_96 :
case V_97 :
V_20 = 1 ;
break;
case V_98 :
V_20 = ( V_74 ) ? 0 : 1 ;
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
case V_99 :
case V_100 :
V_20 = 0 ;
break;
case V_101 :
V_20 = ( V_78 ) ? 1 : 0 ;
break;
case V_102 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_103 :
if ( V_74 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_77 ) ? 0 : 1 ;
break;
case V_104 :
case V_105 :
if ( V_78 ) {
V_20 = 1 ;
break;
}
if ( V_74 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_77 ) ? 0 : 1 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_20 = 0 ;
break;
default:
F_10 ( L_17 ,
( V_9 [ 1 ] & 0x1f ) ) ;
return - V_24 ;
}
break;
case V_111 :
case V_112 :
case V_11 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_20 = 0 ;
break;
default:
V_72 = 1 ;
break;
}
if ( ! V_20 && ! V_72 ) {
#if 0
pr_debug("Allowing explict CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return V_20 ;
}
if ( ( V_77 ) && ! ( V_74 ) ) {
if ( V_8 -> V_118 == V_119 ) {
F_12 ( L_18
L_19 ,
F_16 ( V_8 ) ,
V_19 -> V_23 -> V_66 , V_9 [ 0 ] ,
F_17 ( V_10 ) ) ;
return 1 ;
} else {
#if 0
if (!registered_nexus) {
pr_debug("Allowing implict CDB: 0x%02x"
" for %s reservation on unregistered"
" nexus\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
}
#endif
return 0 ;
}
} else if ( ( V_76 ) || ( V_75 ) ) {
if ( V_74 ) {
#if 0
pr_debug("Allowing implict CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return 0 ;
}
}
F_12 ( L_20
L_21 , F_16 ( V_8 ) ,
( V_74 ) ? L_22 : L_23 ,
V_19 -> V_23 -> V_66 , V_9 [ 0 ] ,
F_17 ( V_10 ) ) ;
return 1 ;
}
static T_1 F_18 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_120 ;
F_4 ( & V_15 -> V_21 ) ;
V_120 = V_30 -> V_34 . V_121 ++ ;
F_5 ( & V_15 -> V_21 ) ;
return V_120 ;
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
if ( V_15 -> V_25 & V_59 )
return F_3 ( V_8 , V_10 ) ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_122 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
* V_10 = V_15 -> V_122 -> V_40 ;
V_8 -> V_123 = V_15 -> V_122 -> V_123 ;
if ( V_15 -> V_122 -> V_124 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - V_24 ;
}
if ( ! V_15 -> V_122 -> V_5 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_122 -> V_125 ==
V_18 -> V_28 ) ? 0 : - V_24 ;
if ( V_20 != 0 )
* V_10 |= 0x80000000 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static struct V_1 * F_20 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_71 * V_127 ,
unsigned char * V_128 ,
T_2 V_129 ,
int V_130 ,
int V_131 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_132 , V_133 ) ;
if ( ! V_2 ) {
F_10 ( L_24 ) ;
return NULL ;
}
V_2 -> V_134 = F_22 ( V_30 -> V_34 . V_135 ,
V_133 ) ;
if ( ! V_2 -> V_134 ) {
F_10 ( L_25 ) ;
F_23 ( V_132 , V_2 ) ;
return NULL ;
}
F_24 ( & V_2 -> V_136 ) ;
F_24 ( & V_2 -> V_137 ) ;
F_24 ( & V_2 -> V_138 ) ;
F_24 ( & V_2 -> V_139 ) ;
F_24 ( & V_2 -> V_140 ) ;
F_25 ( & V_2 -> V_141 , 0 ) ;
V_2 -> V_124 = V_126 ;
V_2 -> V_142 = V_127 ;
V_2 -> V_143 = V_127 -> V_65 ;
V_2 -> V_144 = V_127 -> V_62 -> V_63 ;
V_2 -> V_123 = V_129 ;
V_2 -> V_145 = V_130 ;
V_2 -> V_146 = V_131 ;
V_2 -> V_147 = V_127 -> V_62 ;
if ( V_128 != NULL ) {
V_2 -> V_125 = F_26 ( V_128 ) ;
snprintf ( V_2 -> V_6 , V_148 , L_26 , V_128 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_27 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_71 * V_127 ,
unsigned char * V_128 ,
T_2 V_129 ,
int V_130 ,
int V_131 )
{
struct V_71 * V_149 ;
struct V_23 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_154 * V_155 = V_126 -> V_55 -> V_60 ;
struct V_1 * V_2 , * V_156 , * V_157 , * V_158 ;
int V_20 ;
V_2 = F_20 ( V_15 , V_126 , V_127 , V_128 ,
V_129 , V_130 , V_131 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_130 )
return V_2 ;
F_4 ( & V_15 -> V_159 ) ;
F_28 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_29 ( & V_152 -> V_160 ) ;
F_30 () ;
F_5 ( & V_15 -> V_159 ) ;
F_31 ( & V_152 -> V_161 ) ;
F_32 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_149 -> V_162 )
continue;
V_150 = V_149 -> V_162 -> V_163 ;
if ( V_126 == V_150 )
continue;
if ( V_155 != V_150 -> V_55 -> V_60 )
continue;
if ( strcmp ( V_126 -> V_66 , V_150 -> V_66 ) )
continue;
F_29 ( & V_149 -> V_164 ) ;
F_30 () ;
F_33 ( & V_152 -> V_161 ) ;
V_20 = F_34 ( V_149 ) ;
if ( V_20 < 0 ) {
F_10 ( L_27
L_28 ) ;
F_35 ( & V_152 -> V_160 ) ;
F_36 () ;
F_35 ( & V_149 -> V_164 ) ;
F_36 () ;
goto V_57;
}
V_156 = F_20 ( V_15 ,
V_150 , V_149 , NULL ,
V_129 , V_130 , V_131 ) ;
if ( ! V_156 ) {
F_35 ( & V_152 -> V_160 ) ;
F_36 () ;
F_35 ( & V_149 -> V_164 ) ;
F_36 () ;
F_37 ( V_149 ) ;
goto V_57;
}
F_38 ( & V_156 -> V_140 ,
& V_2 -> V_139 ) ;
F_31 ( & V_152 -> V_161 ) ;
}
F_33 ( & V_152 -> V_161 ) ;
F_4 ( & V_15 -> V_159 ) ;
F_35 ( & V_152 -> V_160 ) ;
F_36 () ;
}
F_5 ( & V_15 -> V_159 ) ;
return V_2 ;
V_57:
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_157 -> V_140 ) ;
F_37 ( V_157 -> V_142 ) ;
F_23 ( V_132 , V_157 ) ;
}
F_23 ( V_132 , V_2 ) ;
return NULL ;
}
int F_40 (
struct V_32 * V_33 ,
T_2 V_129 ,
unsigned char * V_165 ,
unsigned char * V_128 ,
T_1 V_65 ,
unsigned char * V_166 ,
T_3 V_167 ,
T_1 V_168 ,
int V_169 ,
int V_130 ,
T_4 type )
{
struct V_1 * V_2 ;
if ( ! V_165 || ! V_166 || ! V_129 ) {
F_10 ( L_29 ) ;
return - V_24 ;
}
V_2 = F_21 ( V_132 , V_170 ) ;
if ( ! V_2 ) {
F_10 ( L_24 ) ;
return - V_171 ;
}
V_2 -> V_134 = F_22 ( V_33 -> V_135 , V_170 ) ;
F_24 ( & V_2 -> V_136 ) ;
F_24 ( & V_2 -> V_137 ) ;
F_24 ( & V_2 -> V_138 ) ;
F_24 ( & V_2 -> V_139 ) ;
F_24 ( & V_2 -> V_140 ) ;
F_25 ( & V_2 -> V_141 , 0 ) ;
V_2 -> V_124 = NULL ;
V_2 -> V_142 = NULL ;
V_2 -> V_143 = V_65 ;
V_2 -> V_144 = V_168 ;
V_2 -> V_123 = V_129 ;
V_2 -> V_145 = V_130 ;
V_2 -> V_146 = 1 ;
V_2 -> V_147 = NULL ;
V_2 -> V_172 = 0 ;
V_2 -> V_40 = type ;
if ( V_128 != NULL ) {
V_2 -> V_125 = F_26 ( V_128 ) ;
snprintf ( V_2 -> V_6 , V_148 , L_26 , V_128 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_173 , V_174 , L_26 , V_165 ) ;
snprintf ( V_2 -> V_175 , V_176 , L_26 , V_166 ) ;
V_2 -> V_177 = V_167 ;
V_2 -> V_39 = V_169 ;
F_38 ( & V_2 -> V_138 , & V_33 -> V_178 ) ;
F_12 ( L_30
L_31 , ( V_169 ) ? L_32 : L_22 ) ;
return 0 ;
}
static void F_41 (
struct V_14 * V_15 ,
struct V_53 * V_54 ,
struct V_23 * V_179 ,
struct V_1 * V_2 )
{
char V_180 [ V_181 ] ;
int V_182 ;
memset ( V_180 , 0 , V_181 ) ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_15 -> V_122 = V_2 ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_33
L_34 ,
V_54 -> V_60 -> V_61 () ,
F_17 ( V_2 -> V_40 ) ,
( V_2 -> V_145 ) ? 1 : 0 ) ;
F_12 ( L_35 ,
V_54 -> V_60 -> V_61 () , V_179 -> V_66 ,
( V_182 ) ? & V_180 [ 0 ] : L_22 ) ;
}
static int F_42 (
struct V_14 * V_15 ,
struct V_53 * V_54 ,
struct V_62 * V_183 ,
T_1 V_168 ,
struct V_23 * V_126 ,
struct V_71 * V_127 )
{
struct V_1 * V_2 , * V_157 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char V_165 [ V_174 ] ;
unsigned char V_166 [ V_176 ] ;
T_3 V_167 ;
memset ( V_165 , 0 , V_174 ) ;
memset ( V_166 , 0 , V_176 ) ;
snprintf ( V_165 , V_174 , L_26 , V_126 -> V_66 ) ;
snprintf ( V_166 , V_176 , L_26 ,
V_54 -> V_60 -> V_184 ( V_54 ) ) ;
V_167 = V_54 -> V_60 -> V_185 ( V_54 ) ;
F_4 ( & V_33 -> V_186 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_173 , V_165 ) &&
( V_2 -> V_143 == V_127 -> V_65 ) &&
! ( strcmp ( V_2 -> V_175 , V_166 ) ) &&
( V_2 -> V_177 == V_167 ) &&
( V_2 -> V_144 == V_168 ) ) {
V_2 -> V_124 = V_126 ;
V_2 -> V_142 = V_127 ;
V_2 -> V_147 = V_183 ;
F_39 ( & V_2 -> V_138 ) ;
F_5 ( & V_33 -> V_186 ) ;
F_43 ( V_15 , V_126 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_39 )
F_41 ( V_15 , V_54 ,
V_126 , V_2 ) ;
F_4 ( & V_33 -> V_186 ) ;
V_33 -> V_187 = 1 ;
}
}
F_5 ( & V_33 -> V_186 ) ;
return 0 ;
}
int F_44 (
struct V_14 * V_15 ,
struct V_53 * V_54 ,
struct V_62 * V_183 ,
struct V_162 * V_188 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_23 * V_126 = V_188 -> V_163 ;
struct V_71 * V_127 = & V_126 -> V_79 [ V_188 -> V_65 ] ;
if ( V_30 -> V_34 . V_36 != V_37 )
return 0 ;
return F_42 ( V_15 , V_54 , V_183 ,
V_183 -> V_63 , V_126 , V_127 ) ;
}
static void F_45 (
struct V_154 * V_155 ,
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_1 * V_2 ,
int V_189 )
{
struct V_53 * V_55 = V_126 -> V_55 ;
char V_180 [ V_181 ] ;
int V_182 ;
memset ( & V_180 [ 0 ] , 0 , V_181 ) ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
F_12 ( L_36
L_37 , V_155 -> V_61 () , ( V_189 == 2 ) ?
L_38 : ( V_189 == 1 ) ?
L_39 : L_22 , V_126 -> V_66 ,
( V_182 ) ? V_180 : L_22 ) ;
F_12 ( L_40 ,
V_155 -> V_61 () , V_155 -> V_184 ( V_55 ) ,
V_155 -> V_185 ( V_55 ) ) ;
F_12 ( L_41
L_42 , V_155 -> V_61 () ,
( V_2 -> V_145 ) ? L_43 : L_44 ,
V_15 -> V_190 -> V_191 ) ;
F_12 ( L_45
L_46 , V_155 -> V_61 () ,
V_2 -> V_123 , V_2 -> V_192 ,
V_2 -> V_146 ) ;
}
static void F_43 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_1 * V_2 ,
int V_189 ,
int V_193 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_154 * V_155 = V_126 -> V_55 -> V_60 ;
struct V_1 * V_157 , * V_158 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
V_2 -> V_192 = ( V_193 ) ?
V_30 -> V_34 . V_121 ++ :
F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_2 -> V_136 , & V_33 -> V_46 ) ;
V_2 -> V_142 -> V_83 = 1 ;
F_45 ( V_155 , V_15 , V_126 , V_2 , V_189 ) ;
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_2 -> V_145 || V_193 )
return;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_157 -> V_140 ) ;
V_157 -> V_192 = F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_157 -> V_136 ,
& V_33 -> V_46 ) ;
V_157 -> V_142 -> V_83 = 1 ;
F_45 ( V_155 , V_15 ,
V_157 -> V_124 , V_157 ,
V_189 ) ;
F_5 ( & V_33 -> V_45 ) ;
F_37 ( V_157 -> V_142 ) ;
}
}
static int F_46 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_71 * V_127 ,
unsigned char * V_128 ,
T_2 V_129 ,
int V_130 ,
int V_131 ,
int V_189 ,
int V_193 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_15 , V_126 , V_127 , V_128 ,
V_129 , V_130 , V_131 ) ;
if ( ! V_2 )
return - V_194 ;
F_43 ( V_15 , V_126 , V_2 ,
V_189 , V_193 ) ;
return 0 ;
}
static struct V_1 * F_47 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
unsigned char * V_128 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_157 ;
struct V_53 * V_54 ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_124 != V_126 )
continue;
V_54 = V_2 -> V_124 -> V_55 ;
if ( ! V_2 -> V_5 ) {
if ( V_54 -> V_60 -> V_195 != NULL ) {
if ( V_15 -> V_31 -> V_196 . V_197 )
continue;
}
F_29 ( & V_2 -> V_141 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
if ( ! V_128 )
continue;
if ( strcmp ( V_128 , V_2 -> V_6 ) )
continue;
F_29 ( & V_2 -> V_141 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
F_5 ( & V_33 -> V_45 ) ;
return NULL ;
}
static struct V_1 * F_7 (
struct V_14 * V_15 ,
struct V_23 * V_126 ,
struct V_17 * V_18 )
{
struct V_53 * V_54 = V_126 -> V_55 ;
unsigned char V_3 [ V_148 ] , * V_198 = NULL ;
if ( V_54 -> V_60 -> V_195 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_148 ) ;
V_54 -> V_60 -> V_195 ( V_18 , & V_3 [ 0 ] ,
V_148 ) ;
V_198 = & V_3 [ 0 ] ;
}
return F_47 ( V_15 , V_126 , V_198 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_141 ) ;
F_36 () ;
}
static int F_48 (
struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_23 * V_126 = V_2 -> V_124 ;
struct V_1 * V_39 ;
int V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
if ( V_39 == V_2 ) {
F_49 ( V_15 , V_126 , V_2 , 0 ) ;
V_20 = 1 ;
} else if ( V_2 -> V_145 &&
( ! strcmp ( V_39 -> V_124 -> V_66 ,
V_2 -> V_124 -> V_66 ) ) &&
( V_39 -> V_123 == V_2 -> V_123 ) ) {
F_10 ( L_47
L_48
L_49
L_50 , V_2 -> V_123 ) ;
V_20 = - V_194 ;
}
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static void F_50 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_199 * V_200 ,
int V_201 )
{
struct V_154 * V_155 =
V_2 -> V_124 -> V_55 -> V_60 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_180 [ V_181 ] ;
int V_182 ;
memset ( V_180 , 0 , V_181 ) ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
V_2 -> V_142 -> V_83 = 0 ;
V_2 -> V_142 -> V_123 = 0 ;
F_39 ( & V_2 -> V_136 ) ;
if ( V_201 )
F_8 ( V_2 ) ;
while ( F_51 ( & V_2 -> V_141 ) != 0 ) {
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_51 ,
V_155 -> V_61 () ) ;
F_52 () ;
F_4 ( & V_33 -> V_45 ) ;
}
F_12 ( L_52
L_37 , V_155 -> V_61 () ,
V_2 -> V_124 -> V_66 ,
( V_182 ) ? & V_180 [ 0 ] : L_22 ) ;
F_12 ( L_41
L_42 , V_155 -> V_61 () ,
( V_2 -> V_145 ) ? L_43 : L_44 ,
V_15 -> V_190 -> V_191 ) ;
F_12 ( L_45
L_53 , V_155 -> V_61 () , V_2 -> V_123 ,
V_2 -> V_192 ) ;
if ( ! V_200 ) {
V_2 -> V_142 = NULL ;
V_2 -> V_124 = NULL ;
F_53 ( V_2 -> V_134 ) ;
F_23 ( V_132 , V_2 ) ;
return;
}
F_38 ( & V_2 -> V_137 , V_200 ) ;
}
void F_54 (
struct V_14 * V_15 ,
struct V_23 * V_126 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_157 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( ( V_39 != NULL ) &&
( V_39 -> V_124 == V_126 ) )
F_49 ( V_15 , V_126 , V_39 , 0 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_124 != V_126 )
continue;
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
void F_55 (
struct V_14 * V_15 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_157 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( V_39 != NULL ) {
struct V_23 * V_202 = V_39 -> V_124 ;
F_49 ( V_15 , V_202 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_4 ( & V_33 -> V_186 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_39 ( & V_2 -> V_138 ) ;
F_53 ( V_2 -> V_134 ) ;
F_23 ( V_132 , V_2 ) ;
}
F_5 ( & V_33 -> V_186 ) ;
}
static int F_56 ( struct V_53 * V_54 )
{
return F_57 ( V_54 -> V_60 -> V_203 ,
& V_54 -> V_204 . V_205 ) ;
}
static void F_58 ( struct V_53 * V_54 )
{
F_59 ( V_54 -> V_60 -> V_203 ,
& V_54 -> V_204 . V_205 ) ;
F_35 ( & V_54 -> V_206 ) ;
F_36 () ;
}
static int F_60 ( struct V_23 * V_126 )
{
struct V_53 * V_54 = V_126 -> V_55 ;
if ( V_126 -> V_207 )
return 0 ;
return F_57 ( V_54 -> V_60 -> V_203 ,
& V_126 -> V_208 . V_205 ) ;
}
static void F_61 ( struct V_23 * V_126 )
{
struct V_53 * V_54 = V_126 -> V_55 ;
if ( V_126 -> V_207 ) {
F_35 ( & V_126 -> V_209 ) ;
F_36 () ;
return;
}
F_59 ( V_54 -> V_60 -> V_203 ,
& V_126 -> V_208 . V_205 ) ;
F_35 ( & V_126 -> V_209 ) ;
F_36 () ;
}
static int F_34 ( struct V_71 * V_64 )
{
struct V_162 * V_188 = V_64 -> V_162 ;
struct V_23 * V_126 ;
struct V_53 * V_54 ;
if ( ! V_188 )
return 0 ;
V_126 = V_188 -> V_163 ;
V_54 = V_126 -> V_55 ;
return F_57 ( V_54 -> V_60 -> V_203 ,
& V_188 -> V_210 . V_205 ) ;
}
static void F_37 ( struct V_71 * V_64 )
{
struct V_162 * V_188 = V_64 -> V_162 ;
struct V_23 * V_126 ;
struct V_53 * V_54 ;
if ( ! V_188 ) {
F_35 ( & V_64 -> V_164 ) ;
F_36 () ;
return;
}
V_126 = V_188 -> V_163 ;
V_54 = V_126 -> V_55 ;
F_59 ( V_54 -> V_60 -> V_203 ,
& V_188 -> V_210 . V_205 ) ;
F_35 ( & V_64 -> V_164 ) ;
F_36 () ;
}
static int F_62 (
struct V_7 * V_8 ,
struct V_53 * V_54 ,
unsigned char * V_211 ,
T_2 V_129 ,
int V_130 ,
int V_131 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_151 * V_212 ;
struct V_53 * V_213 = NULL , * V_214 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_23 * V_215 = NULL ;
struct V_71 * V_216 = NULL , * V_217 ;
struct V_1 * V_218 , * V_219 , * V_220 ;
struct V_1 * V_157 , * V_158 ;
struct V_199 V_221 ;
struct V_222 * V_223 , * V_224 , * V_225 ;
struct V_154 * V_226 ;
unsigned char * V_3 ;
unsigned char * V_227 , * V_228 = NULL , V_229 , V_230 ;
char * V_231 = NULL , V_232 [ 64 ] , V_180 [ V_181 ] ;
T_1 V_233 , V_234 = 0 ;
int V_20 , V_235 , V_182 ;
T_1 V_236 = 0 ;
memset ( V_232 , 0 , 64 ) ;
F_24 ( & V_221 ) ;
V_217 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
V_223 = F_22 ( sizeof( struct V_222 ) , V_170 ) ;
if ( ! V_223 ) {
F_10 ( L_54 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_24 ( & V_223 -> V_238 ) ;
V_223 -> V_213 = V_54 ;
V_223 -> V_215 = V_19 -> V_23 ;
V_223 -> V_216 = V_217 ;
V_219 = F_27 ( V_8 -> V_16 ,
V_19 -> V_23 , V_217 , V_211 ,
V_129 , V_130 , V_131 ) ;
if ( ! V_219 ) {
F_53 ( V_223 ) ;
V_8 -> V_47 = V_237 ;
return - V_171 ;
}
V_223 -> V_218 = V_219 ;
V_223 -> V_235 = 1 ;
F_38 ( & V_223 -> V_238 , & V_221 ) ;
V_3 = F_63 ( V_8 ) ;
V_233 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_233 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_233 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_233 |= V_3 [ 27 ] & 0xff ;
if ( ( V_233 + 28 ) != V_8 -> V_239 ) {
F_10 ( L_55
L_56 , V_233 ,
V_8 -> V_239 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_227 = & V_3 [ 28 ] ;
while ( V_233 > 0 ) {
V_229 = ( V_227 [ 0 ] & 0x0f ) ;
V_213 = NULL ;
F_4 ( & V_15 -> V_159 ) ;
F_32 (tmp_port, &dev->dev_sep_list, sep_list) {
V_214 = V_212 -> V_241 ;
if ( ! V_214 )
continue;
V_226 = V_214 -> V_60 ;
if ( ! V_226 )
continue;
if ( ! V_226 -> V_242 ||
! V_226 -> V_243 )
continue;
V_230 = V_226 -> V_242 ( V_214 ) ;
if ( V_230 != V_229 )
continue;
V_236 = V_212 -> V_244 ;
V_228 = V_226 -> V_243 (
V_214 , ( const char * ) V_227 , & V_234 ,
& V_231 ) ;
if ( ! V_228 )
continue;
F_29 ( & V_214 -> V_206 ) ;
F_30 () ;
F_5 ( & V_15 -> V_159 ) ;
V_20 = F_56 ( V_214 ) ;
if ( V_20 != 0 ) {
F_10 ( L_57
L_58 ) ;
F_35 ( & V_214 -> V_206 ) ;
F_36 () ;
V_8 -> V_47 =
V_237 ;
V_20 = - V_24 ;
goto V_57;
}
F_64 ( & V_214 -> V_245 ) ;
V_215 = F_65 (
V_214 , V_228 ) ;
if ( V_215 ) {
F_29 ( & V_215 -> V_209 ) ;
F_30 () ;
}
F_66 ( & V_214 -> V_245 ) ;
if ( ! V_215 ) {
F_58 ( V_214 ) ;
F_4 ( & V_15 -> V_159 ) ;
continue;
}
V_20 = F_60 ( V_215 ) ;
if ( V_20 != 0 ) {
F_10 ( L_59
L_60 ) ;
F_35 ( & V_215 -> V_209 ) ;
F_36 () ;
F_58 ( V_214 ) ;
V_8 -> V_47 =
V_237 ;
V_20 = - V_24 ;
goto V_57;
}
V_213 = V_214 ;
F_12 ( L_61
L_62 ,
V_213 -> V_60 -> V_61 () ,
V_215 -> V_66 , V_236 ) ;
F_4 ( & V_15 -> V_159 ) ;
break;
}
F_5 ( & V_15 -> V_159 ) ;
if ( ! V_213 ) {
F_10 ( L_63
L_64 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
dest_tpg->se_tpg_tfo->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
#endif
if ( V_234 > V_233 ) {
F_10 ( L_65
L_66 , V_234 , V_227 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_216 = F_67 ( V_215 ,
V_236 ) ;
if ( ! V_216 ) {
F_10 ( L_67
L_68 ,
V_213 -> V_60 -> V_61 () ,
V_236 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_20 = F_34 ( V_216 ) ;
if ( V_20 < 0 ) {
F_10 ( L_69
L_70 ) ;
F_35 ( & V_216 -> V_164 ) ;
F_36 () ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
V_8 -> V_47 =
V_237 ;
V_20 = - V_24 ;
goto V_57;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
#endif
V_220 = F_47 ( V_15 , V_215 ,
V_231 ) ;
if ( V_220 ) {
F_8 ( V_220 ) ;
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
V_227 += V_234 ;
V_233 -= V_234 ;
V_234 = 0 ;
continue;
}
V_223 = F_22 ( sizeof( struct V_222 ) ,
V_170 ) ;
if ( ! V_223 ) {
F_10 ( L_54 ) ;
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
V_8 -> V_47 =
V_237 ;
V_20 = - V_171 ;
goto V_57;
}
F_24 ( & V_223 -> V_238 ) ;
V_223 -> V_213 = V_213 ;
V_223 -> V_215 = V_215 ;
V_223 -> V_216 = V_216 ;
V_218 = F_27 ( V_8 -> V_16 ,
V_215 , V_216 , V_231 ,
V_129 , V_130 , V_131 ) ;
if ( ! V_218 ) {
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
F_53 ( V_223 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_223 -> V_218 = V_218 ;
F_38 ( & V_223 -> V_238 , & V_221 ) ;
V_227 += V_234 ;
V_233 -= V_234 ;
V_234 = 0 ;
}
F_68 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_213 = V_224 -> V_213 ;
V_215 = V_224 -> V_215 ;
V_216 = V_224 -> V_216 ;
V_218 = V_224 -> V_218 ;
V_235 = V_224 -> V_235 ;
F_39 ( & V_224 -> V_238 ) ;
F_53 ( V_224 ) ;
memset ( V_180 , 0 , V_181 ) ;
V_182 = F_1 ( V_218 , & V_180 [ 0 ] ,
V_181 ) ;
F_43 ( V_8 -> V_16 , V_215 ,
V_218 , 0 , 0 ) ;
F_12 ( L_71
L_72
L_73 , V_213 -> V_60 -> V_61 () ,
V_215 -> V_66 , ( V_182 ) ?
& V_180 [ 0 ] : L_22 , V_216 -> V_65 ) ;
if ( V_235 )
continue;
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
}
return 0 ;
V_57:
F_68 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_213 = V_224 -> V_213 ;
V_215 = V_224 -> V_215 ;
V_216 = V_224 -> V_216 ;
V_218 = V_224 -> V_218 ;
V_235 = V_224 -> V_235 ;
F_39 ( & V_224 -> V_238 ) ;
F_53 ( V_224 ) ;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_39 ( & V_157 -> V_140 ) ;
F_37 ( V_157 -> V_142 ) ;
F_23 ( V_132 , V_157 ) ;
}
F_53 ( V_218 -> V_134 ) ;
F_23 ( V_132 , V_218 ) ;
if ( V_235 )
continue;
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_213 ) ;
}
return V_20 ;
}
static int F_69 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_135 ,
int V_246 )
{
struct V_62 * V_183 ;
struct V_53 * V_54 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
unsigned char V_247 [ 512 ] , V_248 [ 32 ] ;
T_5 V_249 = 0 ;
int V_250 = 0 ;
memset ( V_3 , 0 , V_135 ) ;
if ( V_246 ) {
snprintf ( V_3 , V_135 ,
L_74 ) ;
return 0 ;
}
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
V_247 [ 0 ] = '\0' ;
V_248 [ 0 ] = '\0' ;
V_54 = V_2 -> V_124 -> V_55 ;
V_183 = V_2 -> V_147 ;
if ( V_2 -> V_5 )
snprintf ( V_248 , 32 , L_75 ,
V_2 -> V_6 ) ;
if ( V_15 -> V_122 == V_2 ) {
snprintf ( V_247 , 512 , L_76
L_77
L_78
L_79
L_80
L_81
L_82 , V_250 ,
V_54 -> V_60 -> V_61 () ,
V_2 -> V_124 -> V_66 , V_248 ,
V_2 -> V_123 , V_2 -> V_40 ,
V_2 -> V_172 , V_2 -> V_145 ,
V_2 -> V_143 ) ;
} else {
snprintf ( V_247 , 512 , L_83
L_84
L_85
L_86 ,
V_250 , V_54 -> V_60 -> V_61 () ,
V_2 -> V_124 -> V_66 , V_248 ,
V_2 -> V_123 , V_2 -> V_145 ,
V_2 -> V_143 ) ;
}
if ( ( V_249 + strlen ( V_247 ) >= V_135 ) ) {
F_10 ( L_87
L_88 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_251 ;
}
V_249 += sprintf ( V_3 + V_249 , L_26 , V_247 ) ;
snprintf ( V_247 , 512 , L_89
L_90
L_91 , V_54 -> V_60 -> V_61 () ,
V_54 -> V_60 -> V_184 ( V_54 ) ,
V_54 -> V_60 -> V_185 ( V_54 ) ,
V_183 -> V_252 -> V_244 , V_183 -> V_63 , V_250 ) ;
if ( ( V_249 + strlen ( V_247 ) >= V_135 ) ) {
F_10 ( L_87
L_88 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_251 ;
}
V_249 += sprintf ( V_3 + V_249 , L_26 , V_247 ) ;
V_250 ++ ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
if ( ! V_250 )
V_249 += sprintf ( V_3 + V_249 , L_92 ) ;
return 0 ;
}
static int F_70 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_135 ,
int V_246 )
{
int V_20 ;
F_4 ( & V_15 -> V_21 ) ;
V_20 = F_69 ( V_15 , V_3 , V_135 ,
V_246 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_71 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_135 )
{
struct V_253 * V_254 = & V_15 -> V_31 -> V_253 ;
struct V_255 * V_255 ;
struct V_256 V_257 [ 1 ] ;
T_6 V_258 ;
int V_259 = V_260 | V_261 | V_262 ;
char V_263 [ 512 ] ;
int V_20 ;
memset ( V_257 , 0 , sizeof( struct V_256 ) ) ;
memset ( V_263 , 0 , 512 ) ;
if ( strlen ( & V_254 -> V_264 [ 0 ] ) >= 512 ) {
F_10 ( L_93
L_94 ) ;
return - V_251 ;
}
snprintf ( V_263 , 512 , L_95 , & V_254 -> V_264 [ 0 ] ) ;
V_255 = F_72 ( V_263 , V_259 , 0600 ) ;
if ( F_73 ( V_255 ) || ! V_255 || ! V_255 -> V_265 ) {
F_10 ( L_96
L_70 , V_263 ) ;
return ( F_74 ( V_255 ) < 0 ? F_74 ( V_255 ) : - V_266 ) ;
}
V_257 [ 0 ] . V_267 = & V_3 [ 0 ] ;
if ( ! V_135 )
V_257 [ 0 ] . V_268 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_257 [ 0 ] . V_268 = V_135 ;
V_258 = F_75 () ;
F_76 ( F_77 () ) ;
V_20 = F_78 ( V_255 , & V_257 [ 0 ] , 1 , & V_255 -> V_269 ) ;
F_76 ( V_258 ) ;
if ( V_20 < 0 ) {
F_12 ( L_97 , V_263 ) ;
F_79 ( V_255 , NULL ) ;
return - V_270 ;
}
F_79 ( V_255 , NULL ) ;
return 0 ;
}
static int F_80 (
struct V_14 * V_15 ,
unsigned char * V_271 ,
T_1 V_272 )
{
unsigned char V_273 [ 64 ] , * V_3 ;
T_1 V_135 ;
int V_20 , V_246 = 0 ;
if ( ! V_271 ) {
memset ( V_273 , 0 , 64 ) ;
V_3 = & V_273 [ 0 ] ;
V_135 = 64 ;
V_246 = 1 ;
} else {
V_3 = V_271 ;
V_135 = V_272 ;
}
V_20 = F_70 ( V_15 , V_3 , V_135 ,
V_246 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_71 ( V_15 , V_3 , 0 ) ;
if ( V_20 != 0 )
return V_20 ;
return V_20 ;
}
static int F_81 (
struct V_7 * V_8 ,
T_2 V_274 ,
T_2 V_129 ,
int V_131 ,
int V_130 ,
int V_275 ,
int V_276 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_71 * V_64 ;
struct V_62 * V_62 = V_8 -> V_62 ;
struct V_53 * V_55 ;
struct V_1 * V_2 , * V_277 , * V_157 , * V_220 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_134 = NULL ;
unsigned char V_248 [ V_148 ] , * V_198 = NULL ;
int V_278 = 0 , V_20 = 0 , type ;
if ( ! V_19 || ! V_62 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_55 = V_19 -> V_55 ;
V_64 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
if ( V_55 -> V_60 -> V_195 ) {
memset ( & V_248 [ 0 ] , 0 , V_148 ) ;
V_55 -> V_60 -> V_195 ( V_19 , & V_248 [ 0 ] ,
V_148 ) ;
V_198 = & V_248 [ 0 ] ;
}
V_220 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_220 ) {
if ( V_274 ) {
F_82 ( L_99
L_100 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_129 )
return 0 ;
if ( ! V_275 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_19 -> V_23 , V_64 , V_198 ,
V_129 , V_130 , V_131 ,
V_276 , 0 ) ;
if ( V_20 != 0 ) {
F_10 ( L_101
L_102 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
} else {
V_20 = F_62 ( V_8 , V_55 ,
V_198 , V_129 , V_130 , V_131 ) ;
if ( V_20 != 0 )
return V_20 ;
}
if ( ! V_131 ) {
V_33 -> V_187 = 0 ;
F_80 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_103
L_104 ) ;
return 0 ;
}
V_2 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 ) {
V_33 -> V_187 = 1 ;
F_12 ( L_105 ) ;
}
F_8 ( V_2 ) ;
return V_20 ;
} else {
V_2 = V_220 ;
type = V_2 -> V_40 ;
if ( ! V_276 ) {
if ( V_274 != V_2 -> V_123 ) {
F_10 ( L_106
L_107
L_108
L_109 , V_274 ,
V_2 -> V_123 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
}
if ( V_275 ) {
F_10 ( L_110
L_111 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
if ( V_2 -> V_145 && ! ( V_130 ) ) {
F_10 ( L_112
L_113
L_114 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
if ( V_131 ) {
V_134 = F_22 ( V_33 -> V_135 ,
V_170 ) ;
if ( ! V_134 ) {
F_10 ( L_101
L_115 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 =
V_237 ;
return - V_24 ;
}
}
if ( ! V_129 ) {
V_278 = F_48 (
V_8 -> V_16 , V_2 ) ;
if ( V_278 < 0 ) {
F_53 ( V_134 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_33 -> V_45 ) ;
if ( V_2 -> V_145 ) {
F_28 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_277 -> V_145 )
continue;
if ( V_277 -> V_123 != V_274 )
continue;
if ( V_2 == V_277 )
continue;
if ( strcmp ( V_2 -> V_124 -> V_66 ,
V_277 -> V_124 -> V_66 ) )
continue;
F_50 ( V_15 ,
V_277 , NULL , 0 ) ;
}
}
F_50 ( V_8 -> V_16 , V_2 ,
NULL , 1 ) ;
if ( V_278 &&
( ( type == V_41 ) ||
( type == V_42 ) ) ) {
F_32 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_83 (
V_277 -> V_124 ,
V_277 -> V_143 ,
0x2A ,
V_280 ) ;
}
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_131 ) {
V_33 -> V_187 = 0 ;
F_80 ( V_15 , NULL , 0 ) ;
F_12 ( L_116
L_117 ) ;
return 0 ;
}
V_20 = F_80 ( V_15 ,
& V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 ) {
V_33 -> V_187 = 1 ;
F_12 ( L_118
L_117 ) ;
}
F_53 ( V_134 ) ;
return V_20 ;
} else {
V_2 -> V_192 = F_18 (
V_8 -> V_16 ) ;
V_2 -> V_123 = V_129 ;
F_12 ( L_119
L_120
L_53 , V_8 -> V_281 -> V_61 () ,
( V_276 ) ? L_39 : L_22 ,
V_2 -> V_124 -> V_66 ,
V_2 -> V_123 , V_2 -> V_192 ) ;
if ( ! V_131 ) {
V_33 -> V_187 = 0 ;
F_80 ( V_15 , NULL , 0 ) ;
F_8 ( V_2 ) ;
F_12 ( L_116
L_121 ) ;
return 0 ;
}
V_20 = F_80 ( V_15 ,
& V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 ) {
V_33 -> V_187 = 1 ;
F_12 ( L_118
L_121 ) ;
}
F_53 ( V_134 ) ;
F_8 ( V_2 ) ;
}
}
return 0 ;
}
unsigned char * F_17 ( int type )
{
switch ( type ) {
case V_81 :
return L_122 ;
case V_82 :
return L_123 ;
case V_41 :
return L_124 ;
case V_42 :
return L_125 ;
case V_43 :
return L_126 ;
case V_44 :
return L_127 ;
default:
break;
}
return L_128 ;
}
static int F_84 (
struct V_7 * V_8 ,
struct V_14 * V_15 ,
int type ,
int V_282 ,
T_2 V_274 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_71 * V_64 ;
struct V_62 * V_62 = V_8 -> V_62 ;
struct V_53 * V_55 ;
struct V_1 * V_2 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_180 [ V_181 ] ;
int V_20 , V_182 ;
memset ( V_180 , 0 , V_181 ) ;
if ( ! V_19 || ! V_62 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_55 = V_19 -> V_55 ;
V_64 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_129
L_130 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( V_274 != V_2 -> V_123 ) {
F_10 ( L_131
L_132
L_109 , V_274 , V_2 -> V_123 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_282 != V_283 ) {
F_10 ( L_133 , V_282 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( ( V_39 ) ) {
if ( V_39 != V_2 ) {
struct V_23 * V_202 = V_39 -> V_124 ;
F_10 ( L_134
L_135
L_136 ,
V_8 -> V_281 -> V_61 () ,
V_19 -> V_23 -> V_66 ,
V_202 -> V_55 -> V_60 -> V_61 () ,
V_39 -> V_124 -> V_66 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_172 != V_282 ) ) {
struct V_23 * V_202 = V_39 -> V_124 ;
F_10 ( L_134
L_137
L_138
L_4 ,
V_8 -> V_281 -> V_61 () ,
V_19 -> V_23 -> V_66 ,
V_202 -> V_55 -> V_60 -> V_61 () ,
V_39 -> V_124 -> V_66 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
V_2 -> V_172 = V_282 ;
V_2 -> V_40 = type ;
V_2 -> V_39 = 1 ;
V_15 -> V_122 = V_2 ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
F_12 ( L_139
L_140 ,
V_8 -> V_281 -> V_61 () , F_17 ( type ) ,
( V_2 -> V_145 ) ? 1 : 0 ) ;
F_12 ( L_35 ,
V_8 -> V_281 -> V_61 () ,
V_19 -> V_23 -> V_66 ,
( V_182 ) ? & V_180 [ 0 ] : L_22 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_187 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 )
F_12 ( L_141
L_142 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_85 (
struct V_7 * V_8 ,
int type ,
int V_282 ,
T_2 V_274 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
int V_20 = 0 ;
switch ( type ) {
case V_81 :
case V_82 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_84 ( V_8 , V_15 , type , V_282 , V_274 ) ;
break;
default:
F_10 ( L_143
L_144 , type ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
return V_20 ;
}
static void F_49 (
struct V_14 * V_15 ,
struct V_23 * V_284 ,
struct V_1 * V_2 ,
int V_285 )
{
struct V_154 * V_155 = V_284 -> V_55 -> V_60 ;
char V_180 [ V_181 ] ;
int V_182 ;
memset ( V_180 , 0 , V_181 ) ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
V_15 -> V_122 = NULL ;
F_12 ( L_145
L_140 ,
V_155 -> V_61 () , ( V_285 ) ? L_146 : L_147 ,
F_17 ( V_2 -> V_40 ) ,
( V_2 -> V_145 ) ? 1 : 0 ) ;
F_12 ( L_148 ,
V_155 -> V_61 () , V_284 -> V_66 ,
( V_182 ) ? & V_180 [ 0 ] : L_22 ) ;
V_2 -> V_39 = V_2 -> V_40 = V_2 -> V_172 = 0 ;
}
static int F_86 (
struct V_7 * V_8 ,
int type ,
int V_282 ,
T_2 V_274 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_62 * V_62 = V_8 -> V_62 ;
struct V_1 * V_2 , * V_277 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
int V_20 , V_75 = 0 ;
if ( ! V_19 || ! V_62 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_2 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_129
L_149 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) )
V_75 = 1 ;
if ( ( V_75 == 0 ) && ( V_39 != V_2 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( V_274 != V_2 -> V_123 ) {
F_10 ( L_150
L_132
L_109 , V_274 , V_2 -> V_123 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_172 != V_282 ) ) {
struct V_23 * V_202 = V_39 -> V_124 ;
F_10 ( L_151
L_152
L_153
L_136 ,
V_8 -> V_281 -> V_61 () ,
V_19 -> V_23 -> V_66 ,
V_202 -> V_55 -> V_60 -> V_61 () ,
V_39 -> V_124 -> V_66 ) ;
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
goto V_286;
}
F_4 ( & V_33 -> V_45 ) ;
F_32 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_277 == V_2 )
continue;
F_83 ( V_277 -> V_124 ,
V_277 -> V_143 ,
0x2A , V_280 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
V_286:
if ( V_33 -> V_187 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 )
F_12 ( L_154 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_87 (
struct V_7 * V_8 ,
T_2 V_274 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_124 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_157 , * V_287 , * V_39 ;
T_1 V_143 = 0 ;
int V_288 = 0 ;
V_287 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
if ( ! V_287 ) {
F_10 ( L_129
L_155 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( V_274 != V_287 -> V_123 ) {
F_10 ( L_106
L_107
L_108
L_109 , V_274 , V_287 -> V_123 ) ;
F_8 ( V_287 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( V_39 ) {
struct V_23 * V_202 = V_39 -> V_124 ;
F_49 ( V_15 , V_202 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_288 = ( V_287 == V_2 ) ? 1 : 0 ;
V_124 = V_2 -> V_124 ;
V_143 = V_2 -> V_143 ;
F_50 ( V_15 , V_2 , NULL ,
V_288 ) ;
if ( ! V_288 )
F_83 ( V_124 , V_143 ,
0x2A , V_289 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_156 ,
V_8 -> V_281 -> V_61 () ) ;
if ( V_33 -> V_187 ) {
F_80 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_141
L_157 ) ;
}
F_18 ( V_15 ) ;
return 0 ;
}
static void F_88 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_199 * V_200 ,
int type ,
int V_282 ,
int abort )
{
struct V_23 * V_126 = V_2 -> V_124 ;
struct V_154 * V_155 = V_126 -> V_55 -> V_60 ;
char V_180 [ V_181 ] ;
int V_182 ;
memset ( V_180 , 0 , V_181 ) ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
if ( V_15 -> V_122 )
F_49 ( V_15 , V_126 ,
V_15 -> V_122 , 0 ) ;
V_15 -> V_122 = V_2 ;
V_2 -> V_39 = 1 ;
V_2 -> V_40 = type ;
V_2 -> V_172 = V_282 ;
F_12 ( L_158
L_140 ,
V_155 -> V_61 () , ( abort ) ? L_159 : L_22 ,
F_17 ( type ) ,
( V_2 -> V_145 ) ? 1 : 0 ) ;
F_12 ( L_160 ,
V_155 -> V_61 () , ( abort ) ? L_159 : L_22 ,
V_126 -> V_66 , ( V_182 ) ? & V_180 [ 0 ] : L_22 ) ;
if ( V_200 )
F_38 ( & V_2 -> V_137 ,
V_200 ) ;
}
static void F_89 (
struct V_199 * V_200 ,
struct V_1 * V_290 )
{
struct V_1 * V_2 , * V_157 ;
F_28 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_39 ( & V_2 -> V_137 ) ;
if ( V_290 == V_2 )
continue;
if ( V_2 -> V_39 ) {
F_82 ( L_161 ) ;
continue;
}
V_2 -> V_142 = NULL ;
V_2 -> V_124 = NULL ;
F_53 ( V_2 -> V_134 ) ;
F_23 ( V_132 , V_2 ) ;
}
}
static int F_90 (
struct V_7 * V_8 ,
int type ,
int V_282 ,
T_2 V_274 ,
T_2 V_129 ,
int abort )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_71 * V_64 ;
struct V_23 * V_124 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_199 V_200 ;
struct V_1 * V_2 , * V_157 , * V_287 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
T_1 V_143 = 0 ;
int V_75 = 0 , V_288 = 0 , V_291 = 0 ;
int V_292 = 0 , V_293 = 0 , V_20 ;
if ( ! V_19 ) {
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_64 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
V_287 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_287 ) {
F_10 ( L_129
L_162 ,
( abort ) ? L_159 : L_22 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_287 -> V_123 != V_274 ) {
F_8 ( V_287 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_282 != V_283 ) {
F_10 ( L_133 , V_282 ) ;
F_8 ( V_287 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
F_24 ( & V_200 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( V_39 &&
( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) )
V_75 = 1 ;
if ( ! V_75 && ! V_129 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_287 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
if ( ! V_39 || ( V_39 -> V_123 != V_129 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_75 ) {
if ( V_2 -> V_123 != V_129 )
continue;
V_288 = ( V_287 == V_2 ) ? 1 : 0 ;
V_124 = V_2 -> V_124 ;
V_143 = V_2 -> V_143 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_200 :
NULL , V_288 ) ;
V_291 ++ ;
} else {
if ( ( V_129 ) &&
( V_2 -> V_123 != V_129 ) )
continue;
V_288 = ( V_287 == V_2 ) ? 1 : 0 ;
if ( V_288 )
continue;
V_124 = V_2 -> V_124 ;
V_143 = V_2 -> V_143 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_200 :
NULL , 0 ) ;
V_291 ++ ;
}
if ( ! V_288 )
F_83 ( V_124 ,
V_143 , 0x2A ,
V_294 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_291 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_287 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_39 && V_75 && ! ( V_129 ) ) {
F_88 ( V_15 , V_287 ,
( abort ) ? & V_200 : NULL ,
type , V_282 , abort ) ;
if ( abort )
F_89 (
& V_200 , V_287 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_187 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_287 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 )
F_12 ( L_163
L_164 , ( abort ) ?
L_159 : L_22 ) ;
}
F_8 ( V_287 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
V_292 = V_39 -> V_40 ;
V_293 = V_39 -> V_172 ;
if ( V_287 != V_39 )
F_49 ( V_15 ,
V_39 -> V_124 ,
V_15 -> V_122 , 0 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_288 = ( V_287 == V_2 ) ? 1 : 0 ;
if ( V_288 )
continue;
if ( V_2 -> V_123 != V_129 )
continue;
V_124 = V_2 -> V_124 ;
V_143 = V_2 -> V_143 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_200 : NULL ,
V_288 ) ;
F_83 ( V_124 , V_143 , 0x2A ,
V_294 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_88 ( V_15 , V_287 ,
( abort ) ? & V_200 : NULL ,
type , V_282 , abort ) ;
if ( ( V_292 != type ) || ( V_293 != V_282 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_288 = ( V_287 == V_2 ) ? 1 : 0 ;
if ( V_288 )
continue;
F_83 ( V_2 -> V_124 ,
V_2 -> V_143 , 0x2A ,
V_280 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( abort ) {
F_91 ( V_15 , NULL , & V_200 , V_8 ) ;
F_89 ( & V_200 ,
V_287 ) ;
}
if ( V_33 -> V_187 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_287 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 )
F_12 ( L_165
L_166 , ( abort ) ? L_159 : L_22 ) ;
}
F_8 ( V_287 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_92 (
struct V_7 * V_8 ,
int type ,
int V_282 ,
T_2 V_274 ,
T_2 V_129 ,
int abort )
{
int V_20 = 0 ;
switch ( type ) {
case V_81 :
case V_82 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_90 ( V_8 , type , V_282 ,
V_274 , V_129 , abort ) ;
break;
default:
F_10 ( L_167
L_168 , ( abort ) ? L_159 : L_22 , type ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
return V_20 ;
}
static int F_93 (
struct V_7 * V_8 ,
T_2 V_274 ,
T_2 V_129 ,
int V_131 ,
int V_295 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_71 * V_64 , * V_216 = NULL ;
struct V_62 * V_62 = V_8 -> V_62 ;
struct V_23 * V_202 , * V_124 , * V_215 = NULL ;
struct V_151 * V_151 ;
struct V_53 * V_55 , * V_296 = NULL ;
struct V_154 * V_297 = NULL , * V_298 ;
struct V_1 * V_2 , * V_39 , * V_218 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
unsigned char * V_299 ;
char * V_231 = NULL , V_232 [ 64 ] , V_180 [ V_181 ] ;
T_1 V_234 , V_300 ;
int V_301 = 0 , type , V_282 , V_20 , V_302 , V_182 ;
unsigned short V_303 ;
unsigned char V_229 ;
if ( ! V_19 || ! V_62 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
memset ( V_232 , 0 , 64 ) ;
memset ( V_180 , 0 , V_181 ) ;
V_55 = V_19 -> V_55 ;
V_298 = V_55 -> V_60 ;
V_64 = & V_19 -> V_23 -> V_79 [ V_8 -> V_80 ] ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_169
L_170 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( V_274 != V_2 -> V_123 ) {
F_82 ( L_171
L_172
L_173 , V_274 , V_2 -> V_123 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_129 ) {
F_82 ( L_174
L_175 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_303 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_303 |= V_3 [ 19 ] & 0xff ;
V_234 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_234 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_234 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_234 |= V_3 [ 23 ] & 0xff ;
F_68 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_234 + 24 ) != V_8 -> V_239 ) {
F_10 ( L_176
L_56 , V_234 ,
V_8 -> V_239 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_159 ) ;
F_32 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_151 -> V_244 != V_303 )
continue;
V_296 = V_151 -> V_241 ;
if ( ! V_296 )
continue;
V_297 = V_296 -> V_60 ;
if ( ! V_297 )
continue;
F_29 ( & V_296 -> V_206 ) ;
F_30 () ;
F_5 ( & V_15 -> V_159 ) ;
V_20 = F_56 ( V_296 ) ;
if ( V_20 != 0 ) {
F_10 ( L_177
L_178 ) ;
F_35 ( & V_296 -> V_206 ) ;
F_36 () ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_159 ) ;
break;
}
F_5 ( & V_15 -> V_159 ) ;
if ( ! V_296 || ! V_297 ) {
F_10 ( L_179
L_180
L_181 , V_303 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_240 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_229 = ( V_3 [ 24 ] & 0x0f ) ;
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
#endif
if ( V_229 != V_297 -> V_242 ( V_296 ) ) {
F_10 ( L_171
L_182
L_183 , V_229 ,
V_297 -> V_242 ( V_296 ) ,
V_297 -> V_61 () ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
if ( V_297 -> V_243 == NULL ) {
F_10 ( L_184
L_185
L_186 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_57;
}
V_299 = V_297 -> V_243 ( V_296 ,
( const char * ) & V_3 [ 24 ] , & V_300 , & V_231 ) ;
if ( ! V_299 ) {
F_10 ( L_179
L_187 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
F_68 ( V_8 ) ;
V_3 = NULL ;
F_12 ( L_188
L_189 , V_297 -> V_61 () , ( V_231 != NULL ) ?
L_190 : L_191 , V_299 , ( V_231 != NULL ) ?
V_231 : L_22 ) ;
V_124 = V_2 -> V_124 ;
V_302 = ( ! strcmp ( V_299 ,
V_124 -> V_66 ) ) ? 1 : 0 ;
if ( ! V_302 )
goto V_304;
if ( ! V_231 || ! V_2 -> V_5 ) {
F_10 ( L_192
L_193 , V_299 ,
V_124 -> V_66 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
if ( ! strcmp ( V_231 , V_2 -> V_6 ) ) {
F_10 ( L_194
L_195 ,
V_299 , V_231 , V_124 -> V_66 ,
V_2 -> V_6 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_304:
F_64 ( & V_296 -> V_245 ) ;
V_215 = F_65 ( V_296 ,
V_299 ) ;
if ( V_215 ) {
F_29 ( & V_215 -> V_209 ) ;
F_30 () ;
}
F_66 ( & V_296 -> V_245 ) ;
if ( ! V_215 ) {
F_10 ( L_196
L_197 , V_297 -> V_61 () ,
V_299 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_20 = F_60 ( V_215 ) ;
if ( V_20 != 0 ) {
F_10 ( L_198
L_199 ) ;
F_35 ( & V_215 -> V_209 ) ;
F_36 () ;
V_215 = NULL ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
#endif
V_216 = F_67 ( V_215 , V_303 ) ;
if ( ! V_216 ) {
F_10 ( L_200
L_181 , V_297 -> V_61 () , V_303 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_20 = F_34 ( V_216 ) ;
if ( V_20 < 0 ) {
F_10 ( L_201 ) ;
F_35 ( & V_216 -> V_164 ) ;
F_36 () ;
V_216 = NULL ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_57;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
#endif
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_122 ;
if ( ! V_39 ) {
F_82 ( L_202
L_203 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_279 ;
V_20 = - V_24 ;
goto V_57;
}
if ( V_39 != V_2 ) {
F_82 ( L_204
L_205 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_57;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) {
F_82 ( L_206
L_207 ,
F_17 ( V_39 -> V_40 ) ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_57;
}
V_202 = V_39 -> V_124 ;
type = V_39 -> V_40 ;
V_282 = V_39 -> V_40 ;
V_218 = F_47 ( V_15 , V_215 ,
V_231 ) ;
if ( ! V_218 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_215 , V_216 , V_231 ,
V_129 , 0 , V_131 , 2 , 1 ) ;
if ( V_20 != 0 ) {
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_218 = F_47 ( V_15 , V_215 ,
V_231 ) ;
V_301 = 1 ;
}
F_49 ( V_15 , V_202 ,
V_15 -> V_122 , 0 ) ;
V_15 -> V_122 = V_218 ;
V_218 -> V_39 = 1 ;
V_218 -> V_40 = type ;
V_2 -> V_172 = V_282 ;
V_182 = F_1 ( V_2 , & V_180 [ 0 ] ,
V_181 ) ;
if ( ! V_301 )
V_218 -> V_192 = V_33 -> V_121 ++ ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_208
L_209
L_210 , V_297 -> V_61 () ,
F_17 ( type ) , V_303 ,
V_218 -> V_192 ) ;
F_12 ( L_211
L_212 ,
V_298 -> V_61 () , V_124 -> V_66 ,
( V_182 ) ? & V_180 [ 0 ] : L_22 , V_297 -> V_61 () ,
V_215 -> V_66 , ( V_231 != NULL ) ?
V_231 : L_22 ) ;
F_37 ( V_216 ) ;
F_61 ( V_215 ) ;
F_58 ( V_296 ) ;
if ( V_295 ) {
F_4 ( & V_33 -> V_45 ) ;
F_50 ( V_15 , V_2 , NULL , 1 ) ;
F_5 ( & V_33 -> V_45 ) ;
} else
F_8 ( V_2 ) ;
if ( ! V_131 ) {
V_33 -> V_187 = 0 ;
F_80 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_103
L_213 ) ;
} else {
V_33 -> V_187 = 1 ;
V_20 = F_80 ( V_8 -> V_16 ,
& V_218 -> V_134 [ 0 ] ,
V_33 -> V_135 ) ;
if ( ! V_20 )
F_12 ( L_214
L_213 ) ;
}
F_68 ( V_8 ) ;
F_8 ( V_218 ) ;
return 0 ;
V_57:
if ( V_3 )
F_68 ( V_8 ) ;
if ( V_216 )
F_37 ( V_216 ) ;
if ( V_215 )
F_61 ( V_215 ) ;
F_58 ( V_296 ) ;
F_8 ( V_2 ) ;
return V_20 ;
}
static unsigned long long F_94 ( unsigned char * V_9 )
{
unsigned int V_305 , V_306 ;
V_305 = ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_306 = ( V_9 [ 4 ] << 24 ) | ( V_9 [ 5 ] << 16 ) | ( V_9 [ 6 ] << 8 ) | V_9 [ 7 ] ;
return ( ( unsigned long long ) V_306 ) | ( unsigned long long ) V_305 << 32 ;
}
int F_95 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
unsigned char * V_9 = & V_8 -> V_69 [ 0 ] ;
unsigned char * V_3 ;
T_2 V_274 , V_129 ;
int V_307 , V_282 , type , V_131 ;
int V_275 = 0 , V_130 = 0 , V_295 = 0 ;
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_59 ) {
F_10 ( L_215
L_216
L_217 ) ;
V_8 -> V_47 = V_48 ;
V_20 = V_24 ;
goto V_57;
}
if ( ! V_8 -> V_19 ) {
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( V_8 -> V_239 < 24 ) {
F_82 ( L_218
L_219 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
V_307 = ( V_9 [ 1 ] & 0x1f ) ;
V_282 = ( V_9 [ 2 ] & 0xf0 ) ;
type = ( V_9 [ 2 ] & 0x0f ) ;
V_3 = F_63 ( V_8 ) ;
V_274 = F_94 ( & V_3 [ 0 ] ) ;
V_129 = F_94 ( & V_3 [ 8 ] ) ;
if ( V_307 != V_96 ) {
V_275 = ( V_3 [ 20 ] & 0x08 ) ;
V_130 = ( V_3 [ 20 ] & 0x04 ) ;
V_131 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_131 = ( V_3 [ 17 ] & 0x01 ) ;
V_295 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_68 ( V_8 ) ;
V_3 = NULL ;
if ( V_275 && ( ( V_9 [ 1 ] & 0x1f ) != V_94 ) ) {
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
if ( ! V_275 && ( ( V_9 [ 1 ] & 0x1f ) != V_96 ) &&
( V_8 -> V_239 != 24 ) ) {
F_82 ( L_220
L_221 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_240 ;
V_20 = - V_24 ;
goto V_57;
}
switch ( V_307 ) {
case V_94 :
V_20 = F_81 ( V_8 ,
V_274 , V_129 , V_131 , V_130 , V_275 , 0 ) ;
break;
case V_97 :
V_20 = F_85 ( V_8 , type , V_282 , V_274 ) ;
break;
case V_98 :
V_20 = F_86 ( V_8 , type , V_282 , V_274 ) ;
break;
case V_91 :
V_20 = F_87 ( V_8 , V_274 ) ;
break;
case V_92 :
V_20 = F_92 ( V_8 , type , V_282 ,
V_274 , V_129 , 0 ) ;
break;
case V_93 :
V_20 = F_92 ( V_8 , type , V_282 ,
V_274 , V_129 , 1 ) ;
break;
case V_95 :
V_20 = F_81 ( V_8 ,
0 , V_129 , V_131 , V_130 , V_275 , 1 ) ;
break;
case V_96 :
V_20 = F_93 ( V_8 , V_274 ,
V_129 , V_131 , V_295 ) ;
break;
default:
F_10 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_279 ;
V_20 = - V_24 ;
break;
}
V_57:
if ( ! V_20 ) {
V_51 -> V_67 = V_68 ;
F_13 ( V_51 , 1 ) ;
}
return V_20 ;
}
static int F_96 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_308 = 0 , V_309 = 8 ;
if ( V_8 -> V_239 < 8 ) {
F_10 ( L_222
L_223 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_121 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_121 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_121 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_121 & 0xff ) ;
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_308 + 8 ) > ( V_8 -> V_239 - 8 ) )
break;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 56 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 48 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 40 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 32 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 24 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 16 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 8 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( V_2 -> V_123 & 0xff ) ;
V_308 += 8 ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
V_3 [ 4 ] = ( ( V_308 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_308 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_308 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_308 & 0xff ) ;
F_68 ( V_8 ) ;
return 0 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_2 V_123 ;
T_1 V_308 = 16 ;
if ( V_8 -> V_239 < 8 ) {
F_10 ( L_224
L_223 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_121 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_121 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_121 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_121 & 0xff ) ;
F_4 ( & V_16 -> V_21 ) ;
V_2 = V_16 -> V_122 ;
if ( ( V_2 ) ) {
V_3 [ 4 ] = ( ( V_308 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_308 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_308 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_308 & 0xff ) ;
if ( V_8 -> V_239 < 22 )
goto V_310;
if ( ( V_2 -> V_40 == V_43 ) ||
( V_2 -> V_40 == V_44 ) )
V_123 = 0 ;
else
V_123 = V_2 -> V_123 ;
V_3 [ 8 ] = ( ( V_123 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_123 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_123 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_123 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_123 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_123 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_123 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_123 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_172 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
}
V_310:
F_5 ( & V_16 -> V_21 ) ;
F_68 ( V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_3 V_308 = 8 ;
if ( V_8 -> V_239 < 6 ) {
F_10 ( L_225
L_226 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_308 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_308 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_33 -> V_187 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
F_68 ( V_8 ) ;
return 0 ;
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_23 * V_284 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_53 * V_55 ;
struct V_1 * V_2 , * V_157 ;
struct V_32 * V_33 = & V_16 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_1 V_311 = 0 , V_308 = 0 , V_312 , V_313 ;
T_1 V_309 = 8 ;
int V_314 = 0 ;
if ( V_8 -> V_239 < 8 ) {
F_10 ( L_227
L_223 , V_8 -> V_239 ) ;
V_8 -> V_47 = V_279 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_121 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_121 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_121 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_121 & 0xff ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_284 = V_2 -> V_124 ;
V_55 = V_2 -> V_124 -> V_55 ;
V_311 = 0 ;
F_29 ( & V_2 -> V_141 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
V_313 = V_55 -> V_60 -> V_315 (
V_55 , V_284 , V_2 , & V_314 ) ;
if ( ( V_313 + V_308 ) > V_8 -> V_239 ) {
F_82 ( L_228
L_229 , V_8 -> V_239 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_141 ) ;
F_36 () ;
break;
}
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 56 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 48 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 40 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 32 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 24 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 16 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_2 -> V_123 >> 8 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( V_2 -> V_123 & 0xff ) ;
V_309 += 4 ;
if ( V_2 -> V_145 )
V_3 [ V_309 ] = 0x02 ;
if ( V_2 -> V_39 ) {
V_3 [ V_309 ++ ] |= 0x01 ;
V_3 [ V_309 ++ ] = ( V_2 -> V_172 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
} else
V_309 += 2 ;
V_309 += 4 ;
if ( ! V_2 -> V_145 ) {
struct V_151 * V_152 = V_2 -> V_147 -> V_252 ;
V_3 [ V_309 ++ ] = ( ( V_152 -> V_244 >> 8 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( V_152 -> V_244 & 0xff ) ;
} else
V_309 += 2 ;
V_312 = V_55 -> V_60 -> V_316 ( V_55 ,
V_284 , V_2 , & V_314 , & V_3 [ V_309 + 4 ] ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_141 ) ;
F_36 () ;
V_3 [ V_309 ++ ] = ( ( V_312 >> 24 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_312 >> 16 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( ( V_312 >> 8 ) & 0xff ) ;
V_3 [ V_309 ++ ] = ( V_312 & 0xff ) ;
V_311 = ( 24 + V_312 ) ;
V_309 += V_312 ;
V_308 += V_311 ;
}
F_5 ( & V_33 -> V_45 ) ;
V_3 [ 4 ] = ( ( V_308 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_308 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_308 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_308 & 0xff ) ;
F_68 ( V_8 ) ;
return 0 ;
}
int F_100 ( struct V_50 * V_51 )
{
struct V_7 * V_8 = V_51 -> V_52 ;
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_59 ) {
F_10 ( L_215
L_216
L_217 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
switch ( V_8 -> V_69 [ 1 ] & 0x1f ) {
case V_317 :
V_20 = F_96 ( V_8 ) ;
break;
case V_318 :
V_20 = F_97 ( V_8 ) ;
break;
case V_319 :
V_20 = F_98 ( V_8 ) ;
break;
case V_320 :
V_20 = F_99 ( V_8 ) ;
break;
default:
F_10 ( L_230
L_16 , V_8 -> V_69 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_279 ;
V_20 = - V_24 ;
break;
}
if ( ! V_20 ) {
V_51 -> V_67 = V_68 ;
F_13 ( V_51 , 1 ) ;
}
return V_20 ;
}
static int F_101 ( struct V_7 * V_8 , T_1 * V_40 )
{
return 0 ;
}
static int F_102 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
return 0 ;
}
int F_103 ( struct V_14 * V_15 , int V_321 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_32 * V_322 = & V_30 -> V_34 ;
if ( ( ( V_15 -> V_190 -> V_323 == V_324 ) &&
! ( V_15 -> V_31 -> V_196 . V_325 ) ) || V_321 ) {
V_322 -> V_36 = V_326 ;
V_322 -> V_327 . V_328 = & F_101 ;
V_322 -> V_327 . V_329 = & F_102 ;
F_12 ( L_231
L_232 , V_15 -> V_190 -> V_191 ) ;
return 0 ;
}
if ( V_15 -> V_190 -> V_330 ( V_15 ) >= V_331 ) {
V_322 -> V_36 = V_37 ;
V_322 -> V_327 . V_328 = & F_19 ;
V_322 -> V_327 . V_329 = & F_15 ;
F_12 ( L_233
L_232 , V_15 -> V_190 -> V_191 ) ;
} else {
V_322 -> V_36 = V_332 ;
V_322 -> V_327 . V_328 = & F_3 ;
V_322 -> V_327 . V_329 =
& F_2 ;
F_12 ( L_234 ,
V_15 -> V_190 -> V_191 ) ;
}
return 0 ;
}
