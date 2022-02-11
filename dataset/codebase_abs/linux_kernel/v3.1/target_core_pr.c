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
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_29 * V_30 = V_18 -> V_31 ;
if ( ! V_18 || ! V_30 )
return 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
if ( V_15 -> V_22 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_15 -> V_22 = NULL ;
V_15 -> V_25 &= ~ V_32 ;
if ( V_15 -> V_25 & V_26 ) {
V_15 -> V_27 = 0 ;
V_15 -> V_25 &= ~ V_26 ;
}
F_7 ( L_2
L_3 , V_30 -> V_33 -> V_34 () ,
V_8 -> V_35 -> V_36 , V_8 -> V_37 -> V_38 ,
V_18 -> V_23 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_29 * V_30 = V_18 -> V_31 ;
if ( ( V_8 -> V_40 [ 1 ] & 0x01 ) &&
( V_8 -> V_40 [ 1 ] & 0x02 ) ) {
F_9 ( L_4
L_5 ) ;
return V_41 ;
}
if ( ! V_18 || ! V_30 )
return 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_22 &&
( V_15 -> V_22 != V_18 -> V_23 ) ) {
F_9 ( L_6 ,
V_30 -> V_33 -> V_34 () ) ;
F_9 ( L_7 ,
V_8 -> V_35 -> V_36 ,
V_15 -> V_22 -> V_39 ) ;
F_9 ( L_8
L_9 , V_8 -> V_35 -> V_36 ,
V_8 -> V_37 -> V_38 ,
V_18 -> V_23 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_42 ;
}
V_15 -> V_22 = V_18 -> V_23 ;
V_15 -> V_25 |= V_32 ;
if ( V_18 -> V_28 != 0 ) {
V_15 -> V_27 = V_18 -> V_28 ;
V_15 -> V_25 |= V_26 ;
}
F_7 ( L_10
L_11 , V_30 -> V_33 -> V_34 () ,
V_8 -> V_35 -> V_36 , V_8 -> V_37 -> V_38 ,
V_18 -> V_23 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_43 * V_44 = V_8 -> V_16 -> V_45 ;
struct V_1 * V_2 ;
struct V_46 * V_47 = & V_44 -> V_48 ;
unsigned char * V_9 = & V_8 -> V_40 [ 0 ] ;
int V_49 = ( V_44 -> V_48 . V_50 == V_51 ) ;
int V_52 = 0 ;
if ( ! V_19 )
return 0 ;
if ( ! V_49 )
goto V_53;
V_2 = F_11 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( V_2 ) {
if ( V_2 -> V_54 ) {
F_12 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_55 == V_56 ) ||
( V_2 -> V_55 == V_57 ) ||
( V_2 -> V_55 == V_58 ) ||
( V_2 -> V_55 == V_59 ) ) {
F_12 ( V_2 ) ;
return 0 ;
}
F_12 ( V_2 ) ;
V_52 = 1 ;
} else {
F_4 ( & V_47 -> V_60 ) ;
V_52 = ( F_13 ( & V_47 -> V_61 ) ) ? 0 : 1 ;
F_5 ( & V_47 -> V_60 ) ;
}
if ( V_52 ) {
F_9 ( L_12
L_13
L_14 ) ;
return V_42 ;
}
V_53:
if ( ( V_9 [ 0 ] == V_62 ) || ( V_9 [ 0 ] == V_63 ) )
return F_8 ( V_8 ) ;
else if ( ( V_9 [ 0 ] == V_12 ) || ( V_9 [ 0 ] == V_13 ) )
return F_6 ( V_8 ) ;
else
return V_64 ;
}
static int F_14 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
struct V_65 * V_37 ;
struct V_17 * V_19 = V_8 -> V_19 ;
int V_66 = 0 , V_67 ;
int V_68 = 0 , V_20 = 1 ;
int V_69 = 0 , V_70 = 0 ;
int V_71 = 0 ;
int V_72 = 0 ;
if ( V_8 -> V_16 -> V_25 & V_32 )
return F_2 ( V_8 ,
V_9 , V_10 ) ;
V_37 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
V_67 = ( V_10 & 0x80000000 ) ;
if ( V_67 )
V_10 &= ~ 0x80000000 ;
switch ( V_10 ) {
case V_75 :
V_71 = 1 ;
case V_76 :
if ( ( V_37 -> V_77 ) && ! ( V_67 ) )
V_68 = 1 ;
break;
case V_56 :
V_71 = 1 ;
case V_57 :
V_70 = 1 ;
if ( ( V_37 -> V_77 ) && ! ( V_67 ) )
V_68 = 1 ;
break;
case V_58 :
V_71 = 1 ;
case V_59 :
V_69 = 1 ;
if ( ( V_37 -> V_77 ) && ! ( V_67 ) )
V_68 = 1 ;
break;
default:
return - V_24 ;
}
switch ( V_9 [ 0 ] ) {
case V_78 :
if ( V_68 )
return 0 ;
V_20 = ( V_71 ) ? 0 : 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
if ( V_72 ) {
V_20 = 1 ;
break;
}
if ( V_68 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_71 ) ? 0 : 1 ;
break;
case V_84 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_85 :
case V_86 :
case V_87 :
V_20 = ( V_68 ) ? 0 : 1 ;
break;
case V_88 :
case V_89 :
V_20 = 0 ;
break;
case V_90 :
case V_91 :
V_20 = 1 ;
break;
case V_92 :
V_20 = ( V_68 ) ? 0 : 1 ;
break;
default:
F_9 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
return - V_24 ;
}
break;
case V_12 :
case V_13 :
V_20 = 0 ;
break;
case V_62 :
case V_63 :
V_20 = 0 ;
break;
case V_93 :
V_20 = ( V_72 ) ? 1 : 0 ;
break;
case V_94 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_95 :
if ( V_68 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_71 ) ? 0 : 1 ;
break;
case V_96 :
case V_97 :
if ( V_72 ) {
V_20 = 1 ;
break;
}
if ( V_68 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_71 ) ? 0 : 1 ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_20 = 0 ;
break;
default:
F_9 ( L_17 ,
( V_9 [ 1 ] & 0x1f ) ) ;
return - V_24 ;
}
break;
case V_103 :
case V_104 :
case V_11 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_20 = 0 ;
break;
default:
V_66 = 1 ;
break;
}
if ( ! V_20 && ! V_66 ) {
#if 0
pr_debug("Allowing explict CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return V_20 ;
}
if ( ( V_71 ) && ! ( V_68 ) ) {
if ( V_8 -> V_109 == V_110 ) {
F_7 ( L_18
L_19 ,
F_15 ( V_8 ) ,
V_19 -> V_23 -> V_39 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
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
} else if ( ( V_70 ) || ( V_69 ) ) {
if ( V_68 ) {
#if 0
pr_debug("Allowing implict CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return 0 ;
}
}
F_7 ( L_20
L_21 , F_15 ( V_8 ) ,
( V_68 ) ? L_22 : L_23 ,
V_19 -> V_23 -> V_39 , V_9 [ 0 ] ,
F_16 ( V_10 ) ) ;
return 1 ;
}
static T_1 F_17 ( struct V_14 * V_15 )
{
struct V_43 * V_44 = V_15 -> V_45 ;
T_1 V_111 ;
F_4 ( & V_15 -> V_21 ) ;
V_111 = V_44 -> V_48 . V_112 ++ ;
F_5 ( & V_15 -> V_21 ) ;
return V_111 ;
}
static int F_18 (
struct V_7 * V_8 ,
T_1 * V_10 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
int V_20 ;
if ( ! V_18 )
return 0 ;
if ( V_15 -> V_25 & V_32 )
return F_3 ( V_8 , V_10 ) ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_113 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
* V_10 = V_15 -> V_113 -> V_55 ;
V_8 -> V_114 = V_15 -> V_113 -> V_114 ;
if ( V_15 -> V_113 -> V_115 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - V_24 ;
}
if ( ! V_15 -> V_113 -> V_5 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_113 -> V_116 ==
V_18 -> V_28 ) ? 0 : - V_24 ;
if ( V_20 != 0 )
* V_10 |= 0x80000000 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static struct V_1 * F_19 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_65 * V_118 ,
unsigned char * V_119 ,
T_2 V_120 ,
int V_121 ,
int V_122 )
{
struct V_43 * V_44 = V_15 -> V_45 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_123 , V_124 ) ;
if ( ! V_2 ) {
F_9 ( L_24 ) ;
return NULL ;
}
V_2 -> V_125 = F_21 ( V_44 -> V_48 . V_126 ,
V_124 ) ;
if ( ! V_2 -> V_125 ) {
F_9 ( L_25 ) ;
F_22 ( V_123 , V_2 ) ;
return NULL ;
}
F_23 ( & V_2 -> V_127 ) ;
F_23 ( & V_2 -> V_128 ) ;
F_23 ( & V_2 -> V_129 ) ;
F_23 ( & V_2 -> V_130 ) ;
F_23 ( & V_2 -> V_131 ) ;
F_24 ( & V_2 -> V_132 , 0 ) ;
V_2 -> V_115 = V_117 ;
V_2 -> V_133 = V_118 ;
V_2 -> V_134 = V_118 -> V_38 ;
V_2 -> V_135 = V_118 -> V_35 -> V_36 ;
V_2 -> V_114 = V_120 ;
V_2 -> V_136 = V_121 ;
V_2 -> V_137 = V_122 ;
V_2 -> V_138 = V_118 -> V_35 ;
if ( V_119 != NULL ) {
V_2 -> V_116 = F_25 ( V_119 ) ;
snprintf ( V_2 -> V_6 , V_139 , L_26 , V_119 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_26 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_65 * V_118 ,
unsigned char * V_119 ,
T_2 V_120 ,
int V_121 ,
int V_122 )
{
struct V_65 * V_140 ;
struct V_23 * V_141 ;
struct V_142 * V_143 , * V_144 ;
struct V_145 * V_146 = V_117 -> V_31 -> V_33 ;
struct V_1 * V_2 , * V_147 , * V_148 , * V_149 ;
int V_20 ;
V_2 = F_19 ( V_15 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_121 )
return V_2 ;
F_4 ( & V_15 -> V_150 ) ;
F_27 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_28 ( & V_143 -> V_151 ) ;
F_29 () ;
F_5 ( & V_15 -> V_150 ) ;
F_30 ( & V_143 -> V_152 ) ;
F_31 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_140 -> V_153 )
continue;
V_141 = V_140 -> V_153 -> V_154 ;
if ( V_117 == V_141 )
continue;
if ( V_146 != V_141 -> V_31 -> V_33 )
continue;
if ( strcmp ( V_117 -> V_39 , V_141 -> V_39 ) )
continue;
F_28 ( & V_140 -> V_155 ) ;
F_29 () ;
F_32 ( & V_143 -> V_152 ) ;
V_20 = F_33 ( V_140 ) ;
if ( V_20 < 0 ) {
F_9 ( L_27
L_28 ) ;
F_34 ( & V_143 -> V_151 ) ;
F_35 () ;
F_34 ( & V_140 -> V_155 ) ;
F_35 () ;
goto V_156;
}
V_147 = F_19 ( V_15 ,
V_141 , V_140 , NULL ,
V_120 , V_121 , V_122 ) ;
if ( ! V_147 ) {
F_34 ( & V_143 -> V_151 ) ;
F_35 () ;
F_34 ( & V_140 -> V_155 ) ;
F_35 () ;
F_36 ( V_140 ) ;
goto V_156;
}
F_37 ( & V_147 -> V_131 ,
& V_2 -> V_130 ) ;
F_30 ( & V_143 -> V_152 ) ;
}
F_32 ( & V_143 -> V_152 ) ;
F_4 ( & V_15 -> V_150 ) ;
F_34 ( & V_143 -> V_151 ) ;
F_35 () ;
}
F_5 ( & V_15 -> V_150 ) ;
return V_2 ;
V_156:
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_38 ( & V_148 -> V_131 ) ;
F_36 ( V_148 -> V_133 ) ;
F_22 ( V_123 , V_148 ) ;
}
F_22 ( V_123 , V_2 ) ;
return NULL ;
}
int F_39 (
struct V_46 * V_47 ,
T_2 V_120 ,
unsigned char * V_157 ,
unsigned char * V_119 ,
T_1 V_38 ,
unsigned char * V_158 ,
T_3 V_159 ,
T_1 V_160 ,
int V_161 ,
int V_121 ,
T_4 type )
{
struct V_1 * V_2 ;
if ( ! V_157 || ! V_158 || ! V_120 ) {
F_9 ( L_29 ) ;
return - V_24 ;
}
V_2 = F_20 ( V_123 , V_162 ) ;
if ( ! V_2 ) {
F_9 ( L_24 ) ;
return - V_163 ;
}
V_2 -> V_125 = F_21 ( V_47 -> V_126 , V_162 ) ;
F_23 ( & V_2 -> V_127 ) ;
F_23 ( & V_2 -> V_128 ) ;
F_23 ( & V_2 -> V_129 ) ;
F_23 ( & V_2 -> V_130 ) ;
F_23 ( & V_2 -> V_131 ) ;
F_24 ( & V_2 -> V_132 , 0 ) ;
V_2 -> V_115 = NULL ;
V_2 -> V_133 = NULL ;
V_2 -> V_134 = V_38 ;
V_2 -> V_135 = V_160 ;
V_2 -> V_114 = V_120 ;
V_2 -> V_136 = V_121 ;
V_2 -> V_137 = 1 ;
V_2 -> V_138 = NULL ;
V_2 -> V_164 = 0 ;
V_2 -> V_55 = type ;
if ( V_119 != NULL ) {
V_2 -> V_116 = F_25 ( V_119 ) ;
snprintf ( V_2 -> V_6 , V_139 , L_26 , V_119 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_165 , V_166 , L_26 , V_157 ) ;
snprintf ( V_2 -> V_167 , V_168 , L_26 , V_158 ) ;
V_2 -> V_169 = V_159 ;
V_2 -> V_54 = V_161 ;
F_37 ( & V_2 -> V_129 , & V_47 -> V_170 ) ;
F_7 ( L_30
L_31 , ( V_161 ) ? L_32 : L_22 ) ;
return 0 ;
}
static void F_40 (
struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_23 * V_171 ,
struct V_1 * V_2 )
{
char V_172 [ V_173 ] ;
int V_174 ;
memset ( V_172 , 0 , V_173 ) ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_15 -> V_113 = V_2 ;
F_5 ( & V_15 -> V_21 ) ;
F_7 ( L_33
L_34 ,
V_30 -> V_33 -> V_34 () ,
F_16 ( V_2 -> V_55 ) ,
( V_2 -> V_136 ) ? 1 : 0 ) ;
F_7 ( L_35 ,
V_30 -> V_33 -> V_34 () , V_171 -> V_39 ,
( V_174 ) ? & V_172 [ 0 ] : L_22 ) ;
}
static int F_41 (
struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_35 * V_175 ,
T_1 V_160 ,
struct V_23 * V_117 ,
struct V_65 * V_118 )
{
struct V_1 * V_2 , * V_148 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
unsigned char V_157 [ V_166 ] ;
unsigned char V_158 [ V_168 ] ;
T_3 V_159 ;
memset ( V_157 , 0 , V_166 ) ;
memset ( V_158 , 0 , V_168 ) ;
snprintf ( V_157 , V_166 , L_26 , V_117 -> V_39 ) ;
snprintf ( V_158 , V_168 , L_26 ,
V_30 -> V_33 -> V_176 ( V_30 ) ) ;
V_159 = V_30 -> V_33 -> V_177 ( V_30 ) ;
F_4 ( & V_47 -> V_178 ) ;
F_27 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_165 , V_157 ) &&
( V_2 -> V_134 == V_118 -> V_38 ) &&
! ( strcmp ( V_2 -> V_167 , V_158 ) ) &&
( V_2 -> V_169 == V_159 ) &&
( V_2 -> V_135 == V_160 ) ) {
V_2 -> V_115 = V_117 ;
V_2 -> V_133 = V_118 ;
V_2 -> V_138 = V_175 ;
F_38 ( & V_2 -> V_129 ) ;
F_5 ( & V_47 -> V_178 ) ;
F_42 ( V_15 , V_117 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_54 )
F_40 ( V_15 , V_30 ,
V_117 , V_2 ) ;
F_4 ( & V_47 -> V_178 ) ;
V_47 -> V_179 = 1 ;
}
}
F_5 ( & V_47 -> V_178 ) ;
return 0 ;
}
int F_43 (
struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_35 * V_175 ,
struct V_153 * V_180 )
{
struct V_43 * V_44 = V_15 -> V_45 ;
struct V_23 * V_117 = V_180 -> V_154 ;
struct V_65 * V_118 = & V_117 -> V_73 [ V_180 -> V_38 ] ;
if ( V_44 -> V_48 . V_50 != V_51 )
return 0 ;
return F_41 ( V_15 , V_30 , V_175 ,
V_175 -> V_36 , V_117 , V_118 ) ;
}
static void F_44 (
struct V_145 * V_146 ,
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_1 * V_2 ,
int V_181 )
{
struct V_29 * V_31 = V_117 -> V_31 ;
char V_172 [ V_173 ] ;
int V_174 ;
memset ( & V_172 [ 0 ] , 0 , V_173 ) ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
F_7 ( L_36
L_37 , V_146 -> V_34 () , ( V_181 == 2 ) ?
L_38 : ( V_181 == 1 ) ?
L_39 : L_22 , V_117 -> V_39 ,
( V_174 ) ? V_172 : L_22 ) ;
F_7 ( L_40 ,
V_146 -> V_34 () , V_146 -> V_176 ( V_31 ) ,
V_146 -> V_177 ( V_31 ) ) ;
F_7 ( L_41
L_42 , V_146 -> V_34 () ,
( V_2 -> V_136 ) ? L_43 : L_44 ,
V_15 -> V_182 -> V_183 ) ;
F_7 ( L_45
L_46 , V_146 -> V_34 () ,
V_2 -> V_114 , V_2 -> V_184 ,
V_2 -> V_137 ) ;
}
static void F_42 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_1 * V_2 ,
int V_181 ,
int V_185 )
{
struct V_43 * V_44 = V_15 -> V_45 ;
struct V_145 * V_146 = V_117 -> V_31 -> V_33 ;
struct V_1 * V_148 , * V_149 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
V_2 -> V_184 = ( V_185 ) ?
V_44 -> V_48 . V_112 ++ :
F_17 ( V_15 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_37 ( & V_2 -> V_127 , & V_47 -> V_61 ) ;
V_2 -> V_133 -> V_77 = 1 ;
F_44 ( V_146 , V_15 , V_117 , V_2 , V_181 ) ;
F_5 ( & V_47 -> V_60 ) ;
if ( ! V_2 -> V_136 || V_185 )
return;
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_38 ( & V_148 -> V_131 ) ;
V_148 -> V_184 = F_17 ( V_15 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_37 ( & V_148 -> V_127 ,
& V_47 -> V_61 ) ;
V_148 -> V_133 -> V_77 = 1 ;
F_44 ( V_146 , V_15 ,
V_148 -> V_115 , V_148 ,
V_181 ) ;
F_5 ( & V_47 -> V_60 ) ;
F_36 ( V_148 -> V_133 ) ;
}
}
static int F_45 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_65 * V_118 ,
unsigned char * V_119 ,
T_2 V_120 ,
int V_121 ,
int V_122 ,
int V_181 ,
int V_185 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_15 , V_117 , V_118 , V_119 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_2 )
return - V_186 ;
F_42 ( V_15 , V_117 , V_2 ,
V_181 , V_185 ) ;
return 0 ;
}
static struct V_1 * F_46 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
unsigned char * V_119 )
{
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
struct V_1 * V_2 , * V_148 ;
struct V_29 * V_30 ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_115 != V_117 )
continue;
V_30 = V_2 -> V_115 -> V_31 ;
if ( ! V_2 -> V_5 ) {
if ( V_30 -> V_33 -> V_187 != NULL ) {
if ( V_15 -> V_45 -> V_188 . V_189 )
continue;
}
F_28 ( & V_2 -> V_132 ) ;
F_29 () ;
F_5 ( & V_47 -> V_60 ) ;
return V_2 ;
}
if ( ! V_119 )
continue;
if ( strcmp ( V_119 , V_2 -> V_6 ) )
continue;
F_28 ( & V_2 -> V_132 ) ;
F_29 () ;
F_5 ( & V_47 -> V_60 ) ;
return V_2 ;
}
F_5 ( & V_47 -> V_60 ) ;
return NULL ;
}
static struct V_1 * F_11 (
struct V_14 * V_15 ,
struct V_23 * V_117 ,
struct V_17 * V_18 )
{
struct V_29 * V_30 = V_117 -> V_31 ;
unsigned char V_3 [ V_139 ] , * V_190 = NULL ;
if ( V_30 -> V_33 -> V_187 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_139 ) ;
V_30 -> V_33 -> V_187 ( V_18 , & V_3 [ 0 ] ,
V_139 ) ;
V_190 = & V_3 [ 0 ] ;
}
return F_46 ( V_15 , V_117 , V_190 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_132 ) ;
F_35 () ;
}
static int F_47 (
struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_23 * V_117 = V_2 -> V_115 ;
struct V_1 * V_54 ;
int V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( ! V_54 ) {
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
if ( V_54 == V_2 ) {
F_48 ( V_15 , V_117 , V_2 , 0 ) ;
V_20 = 1 ;
} else if ( V_2 -> V_136 &&
( ! strcmp ( V_54 -> V_115 -> V_39 ,
V_2 -> V_115 -> V_39 ) ) &&
( V_54 -> V_114 == V_2 -> V_114 ) ) {
F_9 ( L_47
L_48
L_49
L_50 , V_2 -> V_114 ) ;
V_20 = - V_186 ;
}
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static void F_49 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_191 * V_192 ,
int V_193 )
{
struct V_145 * V_146 =
V_2 -> V_115 -> V_31 -> V_33 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
char V_172 [ V_173 ] ;
int V_174 ;
memset ( V_172 , 0 , V_173 ) ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
V_2 -> V_133 -> V_77 = 0 ;
V_2 -> V_133 -> V_114 = 0 ;
F_38 ( & V_2 -> V_127 ) ;
if ( V_193 )
F_12 ( V_2 ) ;
while ( F_50 ( & V_2 -> V_132 ) != 0 ) {
F_5 ( & V_47 -> V_60 ) ;
F_7 ( L_51 ,
V_146 -> V_34 () ) ;
F_51 () ;
F_4 ( & V_47 -> V_60 ) ;
}
F_7 ( L_52
L_37 , V_146 -> V_34 () ,
V_2 -> V_115 -> V_39 ,
( V_174 ) ? & V_172 [ 0 ] : L_22 ) ;
F_7 ( L_41
L_42 , V_146 -> V_34 () ,
( V_2 -> V_136 ) ? L_43 : L_44 ,
V_15 -> V_182 -> V_183 ) ;
F_7 ( L_45
L_53 , V_146 -> V_34 () , V_2 -> V_114 ,
V_2 -> V_184 ) ;
if ( ! V_192 ) {
V_2 -> V_133 = NULL ;
V_2 -> V_115 = NULL ;
F_52 ( V_2 -> V_125 ) ;
F_22 ( V_123 , V_2 ) ;
return;
}
F_37 ( & V_2 -> V_128 , V_192 ) ;
}
void F_53 (
struct V_14 * V_15 ,
struct V_23 * V_117 )
{
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
struct V_1 * V_2 , * V_148 , * V_54 ;
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( ( V_54 != NULL ) &&
( V_54 -> V_115 == V_117 ) )
F_48 ( V_15 , V_117 , V_54 , 0 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_115 != V_117 )
continue;
F_49 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
}
void F_54 (
struct V_14 * V_15 )
{
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
struct V_1 * V_2 , * V_148 , * V_54 ;
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( V_54 != NULL ) {
struct V_23 * V_194 = V_54 -> V_115 ;
F_48 ( V_15 , V_194 ,
V_54 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_49 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
F_4 ( & V_47 -> V_178 ) ;
F_27 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_38 ( & V_2 -> V_129 ) ;
F_52 ( V_2 -> V_125 ) ;
F_22 ( V_123 , V_2 ) ;
}
F_5 ( & V_47 -> V_178 ) ;
}
static int F_55 ( struct V_29 * V_30 )
{
return F_56 ( V_30 -> V_33 -> V_195 ,
& V_30 -> V_196 . V_197 ) ;
}
static void F_57 ( struct V_29 * V_30 )
{
F_58 ( V_30 -> V_33 -> V_195 ,
& V_30 -> V_196 . V_197 ) ;
F_34 ( & V_30 -> V_198 ) ;
F_35 () ;
}
static int F_59 ( struct V_23 * V_117 )
{
struct V_29 * V_30 = V_117 -> V_31 ;
if ( V_117 -> V_199 )
return 0 ;
return F_56 ( V_30 -> V_33 -> V_195 ,
& V_117 -> V_200 . V_197 ) ;
}
static void F_60 ( struct V_23 * V_117 )
{
struct V_29 * V_30 = V_117 -> V_31 ;
if ( V_117 -> V_199 ) {
F_34 ( & V_117 -> V_201 ) ;
F_35 () ;
return;
}
F_58 ( V_30 -> V_33 -> V_195 ,
& V_117 -> V_200 . V_197 ) ;
F_34 ( & V_117 -> V_201 ) ;
F_35 () ;
}
static int F_33 ( struct V_65 * V_37 )
{
struct V_153 * V_180 = V_37 -> V_153 ;
struct V_23 * V_117 ;
struct V_29 * V_30 ;
if ( ! V_180 )
return 0 ;
V_117 = V_180 -> V_154 ;
V_30 = V_117 -> V_31 ;
return F_56 ( V_30 -> V_33 -> V_195 ,
& V_180 -> V_202 . V_197 ) ;
}
static void F_36 ( struct V_65 * V_37 )
{
struct V_153 * V_180 = V_37 -> V_153 ;
struct V_23 * V_117 ;
struct V_29 * V_30 ;
if ( ! V_180 ) {
F_34 ( & V_37 -> V_155 ) ;
F_35 () ;
return;
}
V_117 = V_180 -> V_154 ;
V_30 = V_117 -> V_31 ;
F_58 ( V_30 -> V_33 -> V_195 ,
& V_180 -> V_202 . V_197 ) ;
F_34 ( & V_37 -> V_155 ) ;
F_35 () ;
}
static int F_61 (
struct V_7 * V_8 ,
struct V_29 * V_30 ,
unsigned char * V_203 ,
T_2 V_120 ,
int V_121 ,
int V_122 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_142 * V_204 ;
struct V_29 * V_205 = NULL , * V_206 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_23 * V_207 = NULL ;
struct V_65 * V_208 = NULL , * V_209 ;
struct V_1 * V_210 , * V_211 , * V_212 ;
struct V_1 * V_148 , * V_149 ;
struct V_191 V_213 ;
struct V_214 * V_215 , * V_216 , * V_217 ;
struct V_145 * V_218 ;
unsigned char * V_3 ;
unsigned char * V_219 , * V_220 = NULL , V_221 , V_222 ;
char * V_223 = NULL , V_224 [ 64 ] , V_172 [ V_173 ] ;
T_1 V_225 , V_226 = 0 ;
int V_20 , V_227 , V_174 ;
T_1 V_228 = 0 ;
memset ( V_224 , 0 , 64 ) ;
F_23 ( & V_213 ) ;
V_209 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
V_215 = F_21 ( sizeof( struct V_214 ) , V_162 ) ;
if ( ! V_215 ) {
F_9 ( L_54 ) ;
return V_229 ;
}
F_23 ( & V_215 -> V_230 ) ;
V_215 -> V_205 = V_30 ;
V_215 -> V_207 = V_19 -> V_23 ;
V_215 -> V_208 = V_209 ;
V_211 = F_26 ( V_8 -> V_16 ,
V_19 -> V_23 , V_209 , V_203 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_211 ) {
F_52 ( V_215 ) ;
return V_229 ;
}
V_215 -> V_210 = V_211 ;
V_215 -> V_227 = 1 ;
F_37 ( & V_215 -> V_230 , & V_213 ) ;
V_3 = F_62 ( V_8 ) ;
V_225 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_225 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_225 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_225 |= V_3 [ 27 ] & 0xff ;
if ( ( V_225 + 28 ) != V_8 -> V_231 ) {
F_9 ( L_55
L_56 , V_225 ,
V_8 -> V_231 ) ;
V_20 = V_232 ;
goto V_156;
}
V_219 = & V_3 [ 28 ] ;
while ( V_225 > 0 ) {
V_221 = ( V_219 [ 0 ] & 0x0f ) ;
V_205 = NULL ;
F_4 ( & V_15 -> V_150 ) ;
F_31 (tmp_port, &dev->dev_sep_list, sep_list) {
V_206 = V_204 -> V_233 ;
if ( ! V_206 )
continue;
V_218 = V_206 -> V_33 ;
if ( ! V_218 )
continue;
if ( ! V_218 -> V_234 ||
! V_218 -> V_235 )
continue;
V_222 = V_218 -> V_234 ( V_206 ) ;
if ( V_222 != V_221 )
continue;
V_228 = V_204 -> V_236 ;
V_220 = V_218 -> V_235 (
V_206 , ( const char * ) V_219 , & V_226 ,
& V_223 ) ;
if ( ! V_220 )
continue;
F_28 ( & V_206 -> V_198 ) ;
F_29 () ;
F_5 ( & V_15 -> V_150 ) ;
V_20 = F_55 ( V_206 ) ;
if ( V_20 != 0 ) {
F_9 ( L_57
L_58 ) ;
F_34 ( & V_206 -> V_198 ) ;
F_35 () ;
V_20 = V_229 ;
goto V_156;
}
F_63 ( & V_206 -> V_237 ) ;
V_207 = F_64 (
V_206 , V_220 ) ;
if ( V_207 ) {
F_28 ( & V_207 -> V_201 ) ;
F_29 () ;
}
F_65 ( & V_206 -> V_237 ) ;
if ( ! V_207 ) {
F_57 ( V_206 ) ;
F_4 ( & V_15 -> V_150 ) ;
continue;
}
V_20 = F_59 ( V_207 ) ;
if ( V_20 != 0 ) {
F_9 ( L_59
L_60 ) ;
F_34 ( & V_207 -> V_201 ) ;
F_35 () ;
F_57 ( V_206 ) ;
V_20 = V_229 ;
goto V_156;
}
V_205 = V_206 ;
F_7 ( L_61
L_62 ,
V_205 -> V_33 -> V_34 () ,
V_207 -> V_39 , V_228 ) ;
F_4 ( & V_15 -> V_150 ) ;
break;
}
F_5 ( & V_15 -> V_150 ) ;
if ( ! V_205 ) {
F_9 ( L_63
L_64 ) ;
V_20 = V_232 ;
goto V_156;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
dest_tpg->se_tpg_tfo->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
#endif
if ( V_226 > V_225 ) {
F_9 ( L_65
L_66 , V_226 , V_219 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
V_20 = V_232 ;
goto V_156;
}
V_208 = F_66 ( V_207 ,
V_228 ) ;
if ( ! V_208 ) {
F_9 ( L_67
L_68 ,
V_205 -> V_33 -> V_34 () ,
V_228 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
V_20 = V_232 ;
goto V_156;
}
V_20 = F_33 ( V_208 ) ;
if ( V_20 < 0 ) {
F_9 ( L_69
L_70 ) ;
F_34 ( & V_208 -> V_155 ) ;
F_35 () ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
V_20 = V_229 ;
goto V_156;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
#endif
V_212 = F_46 ( V_15 , V_207 ,
V_223 ) ;
if ( V_212 ) {
F_12 ( V_212 ) ;
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
V_219 += V_226 ;
V_225 -= V_226 ;
V_226 = 0 ;
continue;
}
V_215 = F_21 ( sizeof( struct V_214 ) ,
V_162 ) ;
if ( ! V_215 ) {
F_9 ( L_54 ) ;
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
V_20 = V_229 ;
goto V_156;
}
F_23 ( & V_215 -> V_230 ) ;
V_215 -> V_205 = V_205 ;
V_215 -> V_207 = V_207 ;
V_215 -> V_208 = V_208 ;
V_210 = F_26 ( V_8 -> V_16 ,
V_207 , V_208 , V_223 ,
V_120 , V_121 , V_122 ) ;
if ( ! V_210 ) {
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
F_52 ( V_215 ) ;
V_20 = V_232 ;
goto V_156;
}
V_215 -> V_210 = V_210 ;
F_37 ( & V_215 -> V_230 , & V_213 ) ;
V_219 += V_226 ;
V_225 -= V_226 ;
V_226 = 0 ;
}
F_67 ( V_8 ) ;
F_27 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_205 = V_216 -> V_205 ;
V_207 = V_216 -> V_207 ;
V_208 = V_216 -> V_208 ;
V_210 = V_216 -> V_210 ;
V_227 = V_216 -> V_227 ;
F_38 ( & V_216 -> V_230 ) ;
F_52 ( V_216 ) ;
memset ( V_172 , 0 , V_173 ) ;
V_174 = F_1 ( V_210 , & V_172 [ 0 ] ,
V_173 ) ;
F_42 ( V_8 -> V_16 , V_207 ,
V_210 , 0 , 0 ) ;
F_7 ( L_71
L_72
L_73 , V_205 -> V_33 -> V_34 () ,
V_207 -> V_39 , ( V_174 ) ?
& V_172 [ 0 ] : L_22 , V_208 -> V_38 ) ;
if ( V_227 )
continue;
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
}
return 0 ;
V_156:
F_67 ( V_8 ) ;
F_27 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_205 = V_216 -> V_205 ;
V_207 = V_216 -> V_207 ;
V_208 = V_216 -> V_208 ;
V_210 = V_216 -> V_210 ;
V_227 = V_216 -> V_227 ;
F_38 ( & V_216 -> V_230 ) ;
F_52 ( V_216 ) ;
F_27 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_38 ( & V_148 -> V_131 ) ;
F_36 ( V_148 -> V_133 ) ;
F_22 ( V_123 , V_148 ) ;
}
F_52 ( V_210 -> V_125 ) ;
F_22 ( V_123 , V_210 ) ;
if ( V_227 )
continue;
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_205 ) ;
}
return V_20 ;
}
static int F_68 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_126 ,
int V_238 )
{
struct V_35 * V_175 ;
struct V_29 * V_30 ;
struct V_43 * V_44 = V_15 -> V_45 ;
struct V_1 * V_2 ;
unsigned char V_239 [ 512 ] , V_240 [ 32 ] ;
T_5 V_241 = 0 ;
int V_242 = 0 ;
memset ( V_3 , 0 , V_126 ) ;
if ( V_238 ) {
snprintf ( V_3 , V_126 ,
L_74 ) ;
return 0 ;
}
F_4 ( & V_44 -> V_48 . V_60 ) ;
F_31 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
V_239 [ 0 ] = '\0' ;
V_240 [ 0 ] = '\0' ;
V_30 = V_2 -> V_115 -> V_31 ;
V_175 = V_2 -> V_138 ;
if ( V_2 -> V_5 )
snprintf ( V_240 , 32 , L_75 ,
V_2 -> V_6 ) ;
if ( V_15 -> V_113 == V_2 ) {
snprintf ( V_239 , 512 , L_76
L_77
L_78
L_79
L_80
L_81
L_82 , V_242 ,
V_30 -> V_33 -> V_34 () ,
V_2 -> V_115 -> V_39 , V_240 ,
V_2 -> V_114 , V_2 -> V_55 ,
V_2 -> V_164 , V_2 -> V_136 ,
V_2 -> V_134 ) ;
} else {
snprintf ( V_239 , 512 , L_83
L_84
L_85
L_86 ,
V_242 , V_30 -> V_33 -> V_34 () ,
V_2 -> V_115 -> V_39 , V_240 ,
V_2 -> V_114 , V_2 -> V_136 ,
V_2 -> V_134 ) ;
}
if ( ( V_241 + strlen ( V_239 ) >= V_126 ) ) {
F_9 ( L_87
L_88 ) ;
F_5 ( & V_44 -> V_48 . V_60 ) ;
return - V_243 ;
}
V_241 += sprintf ( V_3 + V_241 , L_26 , V_239 ) ;
snprintf ( V_239 , 512 , L_89
L_90
L_91 , V_30 -> V_33 -> V_34 () ,
V_30 -> V_33 -> V_176 ( V_30 ) ,
V_30 -> V_33 -> V_177 ( V_30 ) ,
V_175 -> V_244 -> V_236 , V_175 -> V_36 , V_242 ) ;
if ( ( V_241 + strlen ( V_239 ) >= V_126 ) ) {
F_9 ( L_87
L_88 ) ;
F_5 ( & V_44 -> V_48 . V_60 ) ;
return - V_243 ;
}
V_241 += sprintf ( V_3 + V_241 , L_26 , V_239 ) ;
V_242 ++ ;
}
F_5 ( & V_44 -> V_48 . V_60 ) ;
if ( ! V_242 )
V_241 += sprintf ( V_3 + V_241 , L_92 ) ;
return 0 ;
}
static int F_69 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_126 ,
int V_238 )
{
int V_20 ;
F_4 ( & V_15 -> V_21 ) ;
V_20 = F_68 ( V_15 , V_3 , V_126 ,
V_238 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_70 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_126 )
{
struct V_245 * V_246 = & V_15 -> V_45 -> V_245 ;
struct V_247 * V_247 ;
struct V_248 V_249 [ 1 ] ;
T_6 V_250 ;
int V_251 = V_252 | V_253 | V_254 ;
char V_255 [ 512 ] ;
int V_20 ;
memset ( V_249 , 0 , sizeof( struct V_248 ) ) ;
memset ( V_255 , 0 , 512 ) ;
if ( strlen ( & V_246 -> V_256 [ 0 ] ) >= 512 ) {
F_9 ( L_93
L_94 ) ;
return - V_243 ;
}
snprintf ( V_255 , 512 , L_95 , & V_246 -> V_256 [ 0 ] ) ;
V_247 = F_71 ( V_255 , V_251 , 0600 ) ;
if ( F_72 ( V_247 ) || ! V_247 || ! V_247 -> V_257 ) {
F_9 ( L_96
L_70 , V_255 ) ;
return ( F_73 ( V_247 ) < 0 ? F_73 ( V_247 ) : - V_258 ) ;
}
V_249 [ 0 ] . V_259 = & V_3 [ 0 ] ;
if ( ! V_126 )
V_249 [ 0 ] . V_260 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_249 [ 0 ] . V_260 = V_126 ;
V_250 = F_74 () ;
F_75 ( F_76 () ) ;
V_20 = F_77 ( V_247 , & V_249 [ 0 ] , 1 , & V_247 -> V_261 ) ;
F_75 ( V_250 ) ;
if ( V_20 < 0 ) {
F_7 ( L_97 , V_255 ) ;
F_78 ( V_247 , NULL ) ;
return - V_262 ;
}
F_78 ( V_247 , NULL ) ;
return 0 ;
}
static int F_79 (
struct V_14 * V_15 ,
unsigned char * V_263 ,
T_1 V_264 )
{
unsigned char V_265 [ 64 ] , * V_3 ;
T_1 V_126 ;
int V_20 , V_238 = 0 ;
if ( ! V_263 ) {
memset ( V_265 , 0 , 64 ) ;
V_3 = & V_265 [ 0 ] ;
V_126 = 64 ;
V_238 = 1 ;
} else {
V_3 = V_263 ;
V_126 = V_264 ;
}
V_20 = F_69 ( V_15 , V_3 , V_126 ,
V_238 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_70 ( V_15 , V_3 , 0 ) ;
if ( V_20 != 0 )
return V_20 ;
return V_20 ;
}
static int F_80 (
struct V_7 * V_8 ,
T_2 V_266 ,
T_2 V_120 ,
int V_122 ,
int V_121 ,
int V_267 ,
int V_268 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_65 * V_37 ;
struct V_35 * V_35 = V_8 -> V_35 ;
struct V_29 * V_31 ;
struct V_1 * V_2 , * V_269 , * V_148 , * V_212 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
unsigned char * V_125 = NULL ;
unsigned char V_240 [ V_139 ] , * V_190 = NULL ;
int V_270 = 0 , V_20 = 0 , type ;
if ( ! V_19 || ! V_35 ) {
F_9 ( L_98 ) ;
return V_229 ;
}
V_31 = V_19 -> V_31 ;
V_37 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
if ( V_31 -> V_33 -> V_187 ) {
memset ( & V_240 [ 0 ] , 0 , V_139 ) ;
V_31 -> V_33 -> V_187 ( V_19 , & V_240 [ 0 ] ,
V_139 ) ;
V_190 = & V_240 [ 0 ] ;
}
V_212 = F_11 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_212 ) {
if ( V_266 ) {
F_81 ( L_99
L_100 ) ;
return V_42 ;
}
if ( ! V_120 )
return V_271 ;
if ( ! V_267 ) {
V_20 = F_45 ( V_8 -> V_16 ,
V_19 -> V_23 , V_37 , V_190 ,
V_120 , V_121 , V_122 ,
V_268 , 0 ) ;
if ( V_20 != 0 ) {
F_9 ( L_101
L_102 ) ;
return V_232 ;
}
} else {
V_20 = F_61 ( V_8 , V_31 ,
V_190 , V_120 , V_121 , V_122 ) ;
if ( V_20 != 0 )
return V_20 ;
}
if ( ! V_122 ) {
V_47 -> V_179 = 0 ;
F_79 ( V_8 -> V_16 , NULL , 0 ) ;
F_7 ( L_103
L_104 ) ;
return 0 ;
}
V_2 = F_11 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
V_20 = F_79 ( V_8 -> V_16 ,
& V_2 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 ) {
V_47 -> V_179 = 1 ;
F_7 ( L_105 ) ;
}
F_12 ( V_2 ) ;
return V_20 ;
} else {
V_2 = V_212 ;
type = V_2 -> V_55 ;
if ( ! V_268 ) {
if ( V_266 != V_2 -> V_114 ) {
F_9 ( L_106
L_107
L_108
L_109 , V_266 ,
V_2 -> V_114 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
}
if ( V_267 ) {
F_9 ( L_110
L_111 ) ;
F_12 ( V_2 ) ;
return V_232 ;
}
if ( V_2 -> V_136 && ! ( V_121 ) ) {
F_9 ( L_112
L_113
L_114 ) ;
F_12 ( V_2 ) ;
return V_64 ;
}
if ( V_122 ) {
V_125 = F_21 ( V_47 -> V_126 ,
V_162 ) ;
if ( ! V_125 ) {
F_9 ( L_101
L_115 ) ;
F_12 ( V_2 ) ;
return V_229 ;
}
}
if ( ! V_120 ) {
V_270 = F_47 (
V_8 -> V_16 , V_2 ) ;
if ( V_270 < 0 ) {
F_52 ( V_125 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
F_4 ( & V_47 -> V_60 ) ;
if ( V_2 -> V_136 ) {
F_27 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_269 -> V_136 )
continue;
if ( V_269 -> V_114 != V_266 )
continue;
if ( V_2 == V_269 )
continue;
if ( strcmp ( V_2 -> V_115 -> V_39 ,
V_269 -> V_115 -> V_39 ) )
continue;
F_49 ( V_15 ,
V_269 , NULL , 0 ) ;
}
}
F_49 ( V_8 -> V_16 , V_2 ,
NULL , 1 ) ;
if ( V_270 &&
( ( type == V_56 ) ||
( type == V_57 ) ) ) {
F_31 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_82 (
V_269 -> V_115 ,
V_269 -> V_134 ,
0x2A ,
V_272 ) ;
}
}
F_5 ( & V_47 -> V_60 ) ;
if ( ! V_122 ) {
V_47 -> V_179 = 0 ;
F_79 ( V_15 , NULL , 0 ) ;
F_7 ( L_116
L_117 ) ;
return 0 ;
}
V_20 = F_79 ( V_15 ,
& V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 ) {
V_47 -> V_179 = 1 ;
F_7 ( L_118
L_117 ) ;
}
F_52 ( V_125 ) ;
return V_20 ;
} else {
V_2 -> V_184 = F_17 (
V_8 -> V_16 ) ;
V_2 -> V_114 = V_120 ;
F_7 ( L_119
L_120
L_53 , V_8 -> V_273 -> V_34 () ,
( V_268 ) ? L_39 : L_22 ,
V_2 -> V_115 -> V_39 ,
V_2 -> V_114 , V_2 -> V_184 ) ;
if ( ! V_122 ) {
V_47 -> V_179 = 0 ;
F_79 ( V_15 , NULL , 0 ) ;
F_12 ( V_2 ) ;
F_7 ( L_116
L_121 ) ;
return 0 ;
}
V_20 = F_79 ( V_15 ,
& V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 ) {
V_47 -> V_179 = 1 ;
F_7 ( L_118
L_121 ) ;
}
F_52 ( V_125 ) ;
F_12 ( V_2 ) ;
}
}
return 0 ;
}
unsigned char * F_16 ( int type )
{
switch ( type ) {
case V_75 :
return L_122 ;
case V_76 :
return L_123 ;
case V_56 :
return L_124 ;
case V_57 :
return L_125 ;
case V_58 :
return L_126 ;
case V_59 :
return L_127 ;
default:
break;
}
return L_128 ;
}
static int F_83 (
struct V_7 * V_8 ,
struct V_14 * V_15 ,
int type ,
int V_274 ,
T_2 V_266 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_65 * V_37 ;
struct V_35 * V_35 = V_8 -> V_35 ;
struct V_29 * V_31 ;
struct V_1 * V_2 , * V_54 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
char V_172 [ V_173 ] ;
int V_20 , V_174 ;
memset ( V_172 , 0 , V_173 ) ;
if ( ! V_19 || ! V_35 ) {
F_9 ( L_98 ) ;
return V_229 ;
}
V_31 = V_19 -> V_31 ;
V_37 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
V_2 = F_11 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_9 ( L_129
L_130 ) ;
return V_229 ;
}
if ( V_266 != V_2 -> V_114 ) {
F_9 ( L_131
L_132
L_109 , V_266 , V_2 -> V_114 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
if ( V_274 != V_275 ) {
F_9 ( L_133 , V_274 ) ;
F_12 ( V_2 ) ;
return V_232 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( ( V_54 ) ) {
if ( V_54 != V_2 ) {
struct V_23 * V_194 = V_54 -> V_115 ;
F_9 ( L_134
L_135
L_136 ,
V_8 -> V_273 -> V_34 () ,
V_19 -> V_23 -> V_39 ,
V_194 -> V_31 -> V_33 -> V_34 () ,
V_54 -> V_115 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
if ( ( V_54 -> V_55 != type ) ||
( V_54 -> V_164 != V_274 ) ) {
struct V_23 * V_194 = V_54 -> V_115 ;
F_9 ( L_134
L_137
L_138
L_14 ,
V_8 -> V_273 -> V_34 () ,
V_19 -> V_23 -> V_39 ,
V_194 -> V_31 -> V_33 -> V_34 () ,
V_54 -> V_115 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_271 ;
}
V_2 -> V_164 = V_274 ;
V_2 -> V_55 = type ;
V_2 -> V_54 = 1 ;
V_15 -> V_113 = V_2 ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
F_7 ( L_139
L_140 ,
V_8 -> V_273 -> V_34 () , F_16 ( type ) ,
( V_2 -> V_136 ) ? 1 : 0 ) ;
F_7 ( L_35 ,
V_8 -> V_273 -> V_34 () ,
V_19 -> V_23 -> V_39 ,
( V_174 ) ? & V_172 [ 0 ] : L_22 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( V_47 -> V_179 ) {
V_20 = F_79 ( V_8 -> V_16 ,
& V_2 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 )
F_7 ( L_141
L_142 ) ;
}
F_12 ( V_2 ) ;
return 0 ;
}
static int F_84 (
struct V_7 * V_8 ,
int type ,
int V_274 ,
T_2 V_266 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
int V_20 = 0 ;
switch ( type ) {
case V_75 :
case V_76 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_20 = F_83 ( V_8 , V_15 , type , V_274 , V_266 ) ;
break;
default:
F_9 ( L_143
L_144 , type ) ;
return V_64 ;
}
return V_20 ;
}
static void F_48 (
struct V_14 * V_15 ,
struct V_23 * V_276 ,
struct V_1 * V_2 ,
int V_277 )
{
struct V_145 * V_146 = V_276 -> V_31 -> V_33 ;
char V_172 [ V_173 ] ;
int V_174 ;
memset ( V_172 , 0 , V_173 ) ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
V_15 -> V_113 = NULL ;
F_7 ( L_145
L_140 ,
V_146 -> V_34 () , ( V_277 ) ? L_146 : L_147 ,
F_16 ( V_2 -> V_55 ) ,
( V_2 -> V_136 ) ? 1 : 0 ) ;
F_7 ( L_148 ,
V_146 -> V_34 () , V_276 -> V_39 ,
( V_174 ) ? & V_172 [ 0 ] : L_22 ) ;
V_2 -> V_54 = V_2 -> V_55 = V_2 -> V_164 = 0 ;
}
static int F_85 (
struct V_7 * V_8 ,
int type ,
int V_274 ,
T_2 V_266 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_35 * V_35 = V_8 -> V_35 ;
struct V_1 * V_2 , * V_269 , * V_54 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
int V_20 , V_69 = 0 ;
if ( ! V_19 || ! V_35 ) {
F_9 ( L_98 ) ;
return V_229 ;
}
V_2 = F_11 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_2 ) {
F_9 ( L_129
L_149 ) ;
return V_229 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( ! V_54 ) {
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_271 ;
}
if ( ( V_54 -> V_55 == V_58 ) ||
( V_54 -> V_55 == V_59 ) )
V_69 = 1 ;
if ( ( V_69 == 0 ) && ( V_54 != V_2 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_271 ;
}
if ( V_266 != V_2 -> V_114 ) {
F_9 ( L_150
L_132
L_109 , V_266 , V_2 -> V_114 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
if ( ( V_54 -> V_55 != type ) ||
( V_54 -> V_164 != V_274 ) ) {
struct V_23 * V_194 = V_54 -> V_115 ;
F_9 ( L_151
L_152
L_153
L_136 ,
V_8 -> V_273 -> V_34 () ,
V_19 -> V_23 -> V_39 ,
V_194 -> V_31 -> V_33 -> V_34 () ,
V_54 -> V_115 -> V_39 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
F_48 ( V_15 , V_19 -> V_23 ,
V_2 , 1 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( ( type != V_56 ) &&
( type != V_57 ) &&
( type != V_58 ) &&
( type != V_59 ) ) {
goto V_278;
}
F_4 ( & V_47 -> V_60 ) ;
F_31 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_269 == V_2 )
continue;
F_82 ( V_269 -> V_115 ,
V_269 -> V_134 ,
0x2A , V_272 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
V_278:
if ( V_47 -> V_179 ) {
V_20 = F_79 ( V_8 -> V_16 ,
& V_2 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 )
F_7 ( L_154 ) ;
}
F_12 ( V_2 ) ;
return 0 ;
}
static int F_86 (
struct V_7 * V_8 ,
T_2 V_266 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_115 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
struct V_1 * V_2 , * V_148 , * V_279 , * V_54 ;
T_1 V_134 = 0 ;
int V_280 = 0 ;
V_279 = F_11 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
if ( ! V_279 ) {
F_9 ( L_129
L_155 ) ;
return V_229 ;
}
if ( V_266 != V_279 -> V_114 ) {
F_9 ( L_106
L_107
L_108
L_109 , V_266 , V_279 -> V_114 ) ;
F_12 ( V_279 ) ;
return V_42 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( V_54 ) {
struct V_23 * V_194 = V_54 -> V_115 ;
F_48 ( V_15 , V_194 ,
V_54 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_280 = ( V_279 == V_2 ) ? 1 : 0 ;
V_115 = V_2 -> V_115 ;
V_134 = V_2 -> V_134 ;
F_49 ( V_15 , V_2 , NULL ,
V_280 ) ;
if ( ! V_280 )
F_82 ( V_115 , V_134 ,
0x2A , V_281 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
F_7 ( L_156 ,
V_8 -> V_273 -> V_34 () ) ;
if ( V_47 -> V_179 ) {
F_79 ( V_8 -> V_16 , NULL , 0 ) ;
F_7 ( L_141
L_157 ) ;
}
F_17 ( V_15 ) ;
return 0 ;
}
static void F_87 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_191 * V_192 ,
int type ,
int V_274 ,
int abort )
{
struct V_23 * V_117 = V_2 -> V_115 ;
struct V_145 * V_146 = V_117 -> V_31 -> V_33 ;
char V_172 [ V_173 ] ;
int V_174 ;
memset ( V_172 , 0 , V_173 ) ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
if ( V_15 -> V_113 )
F_48 ( V_15 , V_117 ,
V_15 -> V_113 , 0 ) ;
V_15 -> V_113 = V_2 ;
V_2 -> V_54 = 1 ;
V_2 -> V_55 = type ;
V_2 -> V_164 = V_274 ;
F_7 ( L_158
L_140 ,
V_146 -> V_34 () , ( abort ) ? L_159 : L_22 ,
F_16 ( type ) ,
( V_2 -> V_136 ) ? 1 : 0 ) ;
F_7 ( L_160 ,
V_146 -> V_34 () , ( abort ) ? L_159 : L_22 ,
V_117 -> V_39 , ( V_174 ) ? & V_172 [ 0 ] : L_22 ) ;
if ( V_192 )
F_37 ( & V_2 -> V_128 ,
V_192 ) ;
}
static void F_88 (
struct V_191 * V_192 ,
struct V_1 * V_282 )
{
struct V_1 * V_2 , * V_148 ;
F_27 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_38 ( & V_2 -> V_128 ) ;
if ( V_282 == V_2 )
continue;
if ( V_2 -> V_54 ) {
F_81 ( L_161 ) ;
continue;
}
V_2 -> V_133 = NULL ;
V_2 -> V_115 = NULL ;
F_52 ( V_2 -> V_125 ) ;
F_22 ( V_123 , V_2 ) ;
}
}
int F_89 (
struct V_191 * V_192 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_148 ;
F_27 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
if ( V_2 -> V_114 == V_8 -> V_114 )
return 0 ;
}
return 1 ;
}
static int F_90 (
struct V_7 * V_8 ,
int type ,
int V_274 ,
T_2 V_266 ,
T_2 V_120 ,
int abort )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_65 * V_37 ;
struct V_23 * V_115 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_191 V_192 ;
struct V_1 * V_2 , * V_148 , * V_279 , * V_54 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
T_1 V_134 = 0 ;
int V_69 = 0 , V_280 = 0 , V_283 = 0 ;
int V_284 = 0 , V_285 = 0 , V_20 ;
if ( ! V_19 )
return V_229 ;
V_37 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
V_279 = F_11 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_279 ) {
F_9 ( L_129
L_162 ,
( abort ) ? L_159 : L_22 ) ;
return V_42 ;
}
if ( V_279 -> V_114 != V_266 ) {
F_12 ( V_279 ) ;
return V_42 ;
}
if ( V_274 != V_275 ) {
F_9 ( L_133 , V_274 ) ;
F_12 ( V_279 ) ;
return V_232 ;
}
F_23 ( & V_192 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( V_54 &&
( ( V_54 -> V_55 == V_58 ) ||
( V_54 -> V_55 == V_59 ) ) )
V_69 = 1 ;
if ( ! V_69 && ! V_120 ) {
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_279 ) ;
return V_232 ;
}
if ( ! V_54 || ( V_54 -> V_114 != V_120 ) ) {
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_69 ) {
if ( V_2 -> V_114 != V_120 )
continue;
V_280 = ( V_279 == V_2 ) ? 1 : 0 ;
V_115 = V_2 -> V_115 ;
V_134 = V_2 -> V_134 ;
F_49 ( V_15 , V_2 ,
( abort ) ? & V_192 :
NULL , V_280 ) ;
V_283 ++ ;
} else {
if ( ( V_120 ) &&
( V_2 -> V_114 != V_120 ) )
continue;
V_280 = ( V_279 == V_2 ) ? 1 : 0 ;
if ( V_280 )
continue;
V_115 = V_2 -> V_115 ;
V_134 = V_2 -> V_134 ;
F_49 ( V_15 , V_2 ,
( abort ) ? & V_192 :
NULL , 0 ) ;
V_283 ++ ;
}
if ( ! V_280 )
F_82 ( V_115 ,
V_134 , 0x2A ,
V_281 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
if ( ! V_283 ) {
F_5 ( & V_15 -> V_21 ) ;
F_12 ( V_279 ) ;
return V_42 ;
}
if ( V_54 && V_69 && ! ( V_120 ) ) {
F_87 ( V_15 , V_279 ,
( abort ) ? & V_192 : NULL ,
type , V_274 , abort ) ;
if ( abort )
F_88 (
& V_192 , V_279 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( V_47 -> V_179 ) {
V_20 = F_79 ( V_8 -> V_16 ,
& V_279 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 )
F_7 ( L_163
L_164 , ( abort ) ?
L_159 : L_22 ) ;
}
F_12 ( V_279 ) ;
F_17 ( V_8 -> V_16 ) ;
return 0 ;
}
V_284 = V_54 -> V_55 ;
V_285 = V_54 -> V_164 ;
if ( V_279 != V_54 )
F_48 ( V_15 ,
V_54 -> V_115 ,
V_15 -> V_113 , 0 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_280 = ( V_279 == V_2 ) ? 1 : 0 ;
if ( V_280 )
continue;
if ( V_2 -> V_114 != V_120 )
continue;
V_115 = V_2 -> V_115 ;
V_134 = V_2 -> V_134 ;
F_49 ( V_15 , V_2 ,
( abort ) ? & V_192 : NULL ,
V_280 ) ;
F_82 ( V_115 , V_134 , 0x2A ,
V_281 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
F_87 ( V_15 , V_279 ,
( abort ) ? & V_192 : NULL ,
type , V_274 , abort ) ;
if ( ( V_284 != type ) || ( V_285 != V_274 ) ) {
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_280 = ( V_279 == V_2 ) ? 1 : 0 ;
if ( V_280 )
continue;
F_82 ( V_2 -> V_115 ,
V_2 -> V_134 , 0x2A ,
V_272 ) ;
}
F_5 ( & V_47 -> V_60 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( abort ) {
F_91 ( V_15 , NULL , & V_192 , V_8 ) ;
F_88 ( & V_192 ,
V_279 ) ;
}
if ( V_47 -> V_179 ) {
V_20 = F_79 ( V_8 -> V_16 ,
& V_279 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 )
F_7 ( L_165
L_166 , ( abort ) ? L_159 : L_22 ) ;
}
F_12 ( V_279 ) ;
F_17 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_92 (
struct V_7 * V_8 ,
int type ,
int V_274 ,
T_2 V_266 ,
T_2 V_120 ,
int abort )
{
int V_20 = 0 ;
switch ( type ) {
case V_75 :
case V_76 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_20 = F_90 ( V_8 , type , V_274 ,
V_266 , V_120 , abort ) ;
break;
default:
F_9 ( L_167
L_168 , ( abort ) ? L_159 : L_22 , type ) ;
return V_64 ;
}
return V_20 ;
}
static int F_93 (
struct V_7 * V_8 ,
T_2 V_266 ,
T_2 V_120 ,
int V_122 ,
int V_286 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_65 * V_37 , * V_208 = NULL ;
struct V_35 * V_35 = V_8 -> V_35 ;
struct V_23 * V_194 , * V_115 , * V_207 = NULL ;
struct V_142 * V_142 ;
struct V_29 * V_31 , * V_287 = NULL ;
struct V_145 * V_288 = NULL , * V_289 ;
struct V_1 * V_2 , * V_54 , * V_210 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
unsigned char * V_3 ;
unsigned char * V_290 ;
char * V_223 = NULL , V_224 [ 64 ] , V_172 [ V_173 ] ;
T_1 V_226 , V_291 ;
int V_292 = 0 , type , V_274 , V_20 , V_293 , V_174 ;
unsigned short V_294 ;
unsigned char V_221 ;
if ( ! V_19 || ! V_35 ) {
F_9 ( L_98 ) ;
return V_229 ;
}
memset ( V_224 , 0 , 64 ) ;
memset ( V_172 , 0 , V_173 ) ;
V_31 = V_19 -> V_31 ;
V_289 = V_31 -> V_33 ;
V_37 = & V_19 -> V_23 -> V_73 [ V_8 -> V_74 ] ;
V_2 = F_11 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_9 ( L_169
L_170 ) ;
return V_229 ;
}
if ( V_266 != V_2 -> V_114 ) {
F_81 ( L_171
L_172
L_173 , V_266 , V_2 -> V_114 ) ;
F_12 ( V_2 ) ;
return V_42 ;
}
if ( ! V_120 ) {
F_81 ( L_174
L_175 ) ;
F_12 ( V_2 ) ;
return V_232 ;
}
V_3 = F_62 ( V_8 ) ;
V_294 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_294 |= V_3 [ 19 ] & 0xff ;
V_226 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_226 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_226 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_226 |= V_3 [ 23 ] & 0xff ;
F_67 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_226 + 24 ) != V_8 -> V_231 ) {
F_9 ( L_176
L_56 , V_226 ,
V_8 -> V_231 ) ;
F_12 ( V_2 ) ;
return V_232 ;
}
F_4 ( & V_15 -> V_150 ) ;
F_31 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_142 -> V_236 != V_294 )
continue;
V_287 = V_142 -> V_233 ;
if ( ! V_287 )
continue;
V_288 = V_287 -> V_33 ;
if ( ! V_288 )
continue;
F_28 ( & V_287 -> V_198 ) ;
F_29 () ;
F_5 ( & V_15 -> V_150 ) ;
V_20 = F_55 ( V_287 ) ;
if ( V_20 != 0 ) {
F_9 ( L_177
L_178 ) ;
F_34 ( & V_287 -> V_198 ) ;
F_35 () ;
F_12 ( V_2 ) ;
return V_229 ;
}
F_4 ( & V_15 -> V_150 ) ;
break;
}
F_5 ( & V_15 -> V_150 ) ;
if ( ! V_287 || ! V_288 ) {
F_9 ( L_179
L_180
L_181 , V_294 ) ;
F_12 ( V_2 ) ;
return V_232 ;
}
V_3 = F_62 ( V_8 ) ;
V_221 = ( V_3 [ 24 ] & 0x0f ) ;
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
#endif
if ( V_221 != V_288 -> V_234 ( V_287 ) ) {
F_9 ( L_171
L_182
L_183 , V_221 ,
V_288 -> V_234 ( V_287 ) ,
V_288 -> V_34 () ) ;
V_20 = V_232 ;
goto V_156;
}
if ( V_288 -> V_235 == NULL ) {
F_9 ( L_184
L_185
L_186 ) ;
V_20 = V_229 ;
goto V_156;
}
V_290 = V_288 -> V_235 ( V_287 ,
( const char * ) & V_3 [ 24 ] , & V_291 , & V_223 ) ;
if ( ! V_290 ) {
F_9 ( L_179
L_187 ) ;
V_20 = V_232 ;
goto V_156;
}
F_67 ( V_8 ) ;
V_3 = NULL ;
F_7 ( L_188
L_189 , V_288 -> V_34 () , ( V_223 != NULL ) ?
L_190 : L_191 , V_290 , ( V_223 != NULL ) ?
V_223 : L_22 ) ;
V_115 = V_2 -> V_115 ;
V_293 = ( ! strcmp ( V_290 ,
V_115 -> V_39 ) ) ? 1 : 0 ;
if ( ! V_293 )
goto V_295;
if ( ! V_223 || ! V_2 -> V_5 ) {
F_9 ( L_192
L_193 , V_290 ,
V_115 -> V_39 ) ;
V_20 = V_232 ;
goto V_156;
}
if ( ! strcmp ( V_223 , V_2 -> V_6 ) ) {
F_9 ( L_194
L_195 ,
V_290 , V_223 , V_115 -> V_39 ,
V_2 -> V_6 ) ;
V_20 = V_232 ;
goto V_156;
}
V_295:
F_63 ( & V_287 -> V_237 ) ;
V_207 = F_64 ( V_287 ,
V_290 ) ;
if ( V_207 ) {
F_28 ( & V_207 -> V_201 ) ;
F_29 () ;
}
F_65 ( & V_287 -> V_237 ) ;
if ( ! V_207 ) {
F_9 ( L_196
L_197 , V_288 -> V_34 () ,
V_290 ) ;
V_20 = V_232 ;
goto V_156;
}
V_20 = F_59 ( V_207 ) ;
if ( V_20 != 0 ) {
F_9 ( L_198
L_199 ) ;
F_34 ( & V_207 -> V_201 ) ;
F_35 () ;
V_207 = NULL ;
V_20 = V_229 ;
goto V_156;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
#endif
V_208 = F_66 ( V_207 , V_294 ) ;
if ( ! V_208 ) {
F_9 ( L_200
L_181 , V_288 -> V_34 () , V_294 ) ;
V_20 = V_232 ;
goto V_156;
}
V_20 = F_33 ( V_208 ) ;
if ( V_20 < 0 ) {
F_9 ( L_201 ) ;
F_34 ( & V_208 -> V_155 ) ;
F_35 () ;
V_208 = NULL ;
V_20 = V_229 ;
goto V_156;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
#endif
F_4 ( & V_15 -> V_21 ) ;
V_54 = V_15 -> V_113 ;
if ( ! V_54 ) {
F_81 ( L_202
L_203 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_64 ;
goto V_156;
}
if ( V_54 != V_2 ) {
F_81 ( L_204
L_205 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_42 ;
goto V_156;
}
if ( ( V_54 -> V_55 == V_58 ) ||
( V_54 -> V_55 == V_59 ) ) {
F_81 ( L_206
L_207 ,
F_16 ( V_54 -> V_55 ) ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_42 ;
goto V_156;
}
V_194 = V_54 -> V_115 ;
type = V_54 -> V_55 ;
V_274 = V_54 -> V_55 ;
V_210 = F_46 ( V_15 , V_207 ,
V_223 ) ;
if ( ! V_210 ) {
V_20 = F_45 ( V_8 -> V_16 ,
V_207 , V_208 , V_223 ,
V_120 , 0 , V_122 , 2 , 1 ) ;
if ( V_20 != 0 ) {
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_232 ;
goto V_156;
}
V_210 = F_46 ( V_15 , V_207 ,
V_223 ) ;
V_292 = 1 ;
}
F_48 ( V_15 , V_194 ,
V_15 -> V_113 , 0 ) ;
V_15 -> V_113 = V_210 ;
V_210 -> V_54 = 1 ;
V_210 -> V_55 = type ;
V_2 -> V_164 = V_274 ;
V_174 = F_1 ( V_2 , & V_172 [ 0 ] ,
V_173 ) ;
if ( ! V_292 )
V_210 -> V_184 = V_47 -> V_112 ++ ;
F_5 ( & V_15 -> V_21 ) ;
F_7 ( L_208
L_209
L_210 , V_288 -> V_34 () ,
F_16 ( type ) , V_294 ,
V_210 -> V_184 ) ;
F_7 ( L_211
L_212 ,
V_289 -> V_34 () , V_115 -> V_39 ,
( V_174 ) ? & V_172 [ 0 ] : L_22 , V_288 -> V_34 () ,
V_207 -> V_39 , ( V_223 != NULL ) ?
V_223 : L_22 ) ;
F_36 ( V_208 ) ;
F_60 ( V_207 ) ;
F_57 ( V_287 ) ;
if ( V_286 ) {
F_4 ( & V_47 -> V_60 ) ;
F_49 ( V_15 , V_2 , NULL , 1 ) ;
F_5 ( & V_47 -> V_60 ) ;
} else
F_12 ( V_2 ) ;
if ( ! V_122 ) {
V_47 -> V_179 = 0 ;
F_79 ( V_8 -> V_16 , NULL , 0 ) ;
F_7 ( L_103
L_213 ) ;
} else {
V_47 -> V_179 = 1 ;
V_20 = F_79 ( V_8 -> V_16 ,
& V_210 -> V_125 [ 0 ] ,
V_47 -> V_126 ) ;
if ( ! V_20 )
F_7 ( L_214
L_213 ) ;
}
F_67 ( V_8 ) ;
F_12 ( V_210 ) ;
return 0 ;
V_156:
if ( V_3 )
F_67 ( V_8 ) ;
if ( V_208 )
F_36 ( V_208 ) ;
if ( V_207 )
F_60 ( V_207 ) ;
F_57 ( V_287 ) ;
F_12 ( V_2 ) ;
return V_20 ;
}
static unsigned long long F_94 ( unsigned char * V_9 )
{
unsigned int V_296 , V_297 ;
V_296 = ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_297 = ( V_9 [ 4 ] << 24 ) | ( V_9 [ 5 ] << 16 ) | ( V_9 [ 6 ] << 8 ) | V_9 [ 7 ] ;
return ( ( unsigned long long ) V_297 ) | ( unsigned long long ) V_296 << 32 ;
}
static int F_95 ( struct V_7 * V_8 , unsigned char * V_9 )
{
unsigned char * V_3 ;
T_2 V_266 , V_120 ;
int V_298 , V_274 , type , V_122 ;
int V_267 = 0 , V_121 = 0 , V_286 = 0 ;
if ( ! V_8 -> V_19 )
return V_229 ;
if ( V_8 -> V_231 < 24 ) {
F_81 ( L_215
L_216 , V_8 -> V_231 ) ;
return V_232 ;
}
V_298 = ( V_9 [ 1 ] & 0x1f ) ;
V_274 = ( V_9 [ 2 ] & 0xf0 ) ;
type = ( V_9 [ 2 ] & 0x0f ) ;
V_3 = F_62 ( V_8 ) ;
V_266 = F_94 ( & V_3 [ 0 ] ) ;
V_120 = F_94 ( & V_3 [ 8 ] ) ;
if ( V_298 != V_90 ) {
V_267 = ( V_3 [ 20 ] & 0x08 ) ;
V_121 = ( V_3 [ 20 ] & 0x04 ) ;
V_122 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_122 = ( V_3 [ 17 ] & 0x01 ) ;
V_286 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_67 ( V_8 ) ;
V_3 = NULL ;
if ( V_267 && ( ( V_9 [ 1 ] & 0x1f ) != V_88 ) )
return V_232 ;
if ( ! V_267 && ( ( V_9 [ 1 ] & 0x1f ) != V_90 ) &&
( V_8 -> V_231 != 24 ) ) {
F_81 ( L_217
L_218 , V_8 -> V_231 ) ;
return V_232 ;
}
switch ( V_298 ) {
case V_88 :
return F_80 ( V_8 ,
V_266 , V_120 , V_122 , V_121 , V_267 , 0 ) ;
case V_91 :
return F_84 ( V_8 ,
type , V_274 , V_266 ) ;
case V_92 :
return F_85 ( V_8 ,
type , V_274 , V_266 ) ;
case V_85 :
return F_86 ( V_8 , V_266 ) ;
case V_86 :
return F_92 ( V_8 , type , V_274 ,
V_266 , V_120 , 0 ) ;
case V_87 :
return F_92 ( V_8 , type , V_274 ,
V_266 , V_120 , 1 ) ;
case V_89 :
return F_80 ( V_8 ,
0 , V_120 , V_122 , V_121 , V_267 , 1 ) ;
case V_90 :
return F_93 ( V_8 , V_266 ,
V_120 , V_122 , V_286 ) ;
default:
F_9 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
return V_64 ;
}
return V_64 ;
}
static int F_96 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_43 * V_44 = V_16 -> V_45 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_299 = 0 , V_300 = 8 ;
if ( V_8 -> V_231 < 8 ) {
F_9 ( L_219
L_220 , V_8 -> V_231 ) ;
return V_64 ;
}
V_3 = F_62 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_44 -> V_48 . V_112 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_44 -> V_48 . V_112 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_44 -> V_48 . V_112 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_44 -> V_48 . V_112 & 0xff ) ;
F_4 ( & V_44 -> V_48 . V_60 ) ;
F_31 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_299 + 8 ) > ( V_8 -> V_231 - 8 ) )
break;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 56 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 48 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 40 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 32 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 24 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 16 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 8 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( V_2 -> V_114 & 0xff ) ;
V_299 += 8 ;
}
F_5 ( & V_44 -> V_48 . V_60 ) ;
V_3 [ 4 ] = ( ( V_299 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_299 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_299 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_299 & 0xff ) ;
F_67 ( V_8 ) ;
return 0 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_43 * V_44 = V_16 -> V_45 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_2 V_114 ;
T_1 V_299 = 16 ;
if ( V_8 -> V_231 < 8 ) {
F_9 ( L_221
L_220 , V_8 -> V_231 ) ;
return V_64 ;
}
V_3 = F_62 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_44 -> V_48 . V_112 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_44 -> V_48 . V_112 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_44 -> V_48 . V_112 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_44 -> V_48 . V_112 & 0xff ) ;
F_4 ( & V_16 -> V_21 ) ;
V_2 = V_16 -> V_113 ;
if ( ( V_2 ) ) {
V_3 [ 4 ] = ( ( V_299 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_299 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_299 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_299 & 0xff ) ;
if ( V_8 -> V_231 < 22 )
goto V_301;
if ( ( V_2 -> V_55 == V_58 ) ||
( V_2 -> V_55 == V_59 ) )
V_114 = 0 ;
else
V_114 = V_2 -> V_114 ;
V_3 [ 8 ] = ( ( V_114 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_114 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_114 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_114 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_114 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_114 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_114 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_114 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_164 & 0xf0 ) |
( V_2 -> V_55 & 0x0f ) ;
}
V_301:
F_5 ( & V_16 -> V_21 ) ;
F_67 ( V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_46 * V_47 = & V_15 -> V_45 -> V_48 ;
unsigned char * V_3 ;
T_3 V_299 = 8 ;
if ( V_8 -> V_231 < 6 ) {
F_9 ( L_222
L_223 , V_8 -> V_231 ) ;
return V_64 ;
}
V_3 = F_62 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_299 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_299 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_47 -> V_179 )
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
static int F_99 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_23 * V_276 ;
struct V_43 * V_44 = V_16 -> V_45 ;
struct V_29 * V_31 ;
struct V_1 * V_2 , * V_148 ;
struct V_46 * V_47 = & V_16 -> V_45 -> V_48 ;
unsigned char * V_3 ;
T_1 V_302 = 0 , V_299 = 0 , V_303 , V_304 ;
T_1 V_300 = 8 ;
int V_305 = 0 ;
if ( V_8 -> V_231 < 8 ) {
F_9 ( L_224
L_220 , V_8 -> V_231 ) ;
return V_64 ;
}
V_3 = F_62 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_44 -> V_48 . V_112 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_44 -> V_48 . V_112 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_44 -> V_48 . V_112 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_44 -> V_48 . V_112 & 0xff ) ;
F_4 ( & V_47 -> V_60 ) ;
F_27 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_276 = V_2 -> V_115 ;
V_31 = V_2 -> V_115 -> V_31 ;
V_302 = 0 ;
F_28 ( & V_2 -> V_132 ) ;
F_29 () ;
F_5 ( & V_47 -> V_60 ) ;
V_304 = V_31 -> V_33 -> V_306 (
V_31 , V_276 , V_2 , & V_305 ) ;
if ( ( V_304 + V_299 ) > V_8 -> V_231 ) {
F_81 ( L_225
L_226 , V_8 -> V_231 ) ;
F_4 ( & V_47 -> V_60 ) ;
F_34 ( & V_2 -> V_132 ) ;
F_35 () ;
break;
}
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 56 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 48 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 40 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 32 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 24 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 16 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_2 -> V_114 >> 8 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( V_2 -> V_114 & 0xff ) ;
V_300 += 4 ;
if ( V_2 -> V_136 )
V_3 [ V_300 ] = 0x02 ;
if ( V_2 -> V_54 ) {
V_3 [ V_300 ++ ] |= 0x01 ;
V_3 [ V_300 ++ ] = ( V_2 -> V_164 & 0xf0 ) |
( V_2 -> V_55 & 0x0f ) ;
} else
V_300 += 2 ;
V_300 += 4 ;
if ( ! V_2 -> V_136 ) {
struct V_142 * V_143 = V_2 -> V_138 -> V_244 ;
V_3 [ V_300 ++ ] = ( ( V_143 -> V_236 >> 8 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( V_143 -> V_236 & 0xff ) ;
} else
V_300 += 2 ;
V_303 = V_31 -> V_33 -> V_307 ( V_31 ,
V_276 , V_2 , & V_305 , & V_3 [ V_300 + 4 ] ) ;
F_4 ( & V_47 -> V_60 ) ;
F_34 ( & V_2 -> V_132 ) ;
F_35 () ;
V_3 [ V_300 ++ ] = ( ( V_303 >> 24 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_303 >> 16 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( ( V_303 >> 8 ) & 0xff ) ;
V_3 [ V_300 ++ ] = ( V_303 & 0xff ) ;
V_302 = ( 24 + V_303 ) ;
V_300 += V_303 ;
V_299 += V_302 ;
}
F_5 ( & V_47 -> V_60 ) ;
V_3 [ 4 ] = ( ( V_299 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_299 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_299 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_299 & 0xff ) ;
F_67 ( V_8 ) ;
return 0 ;
}
static int F_100 ( struct V_7 * V_8 , unsigned char * V_9 )
{
switch ( V_9 [ 1 ] & 0x1f ) {
case V_308 :
return F_96 ( V_8 ) ;
case V_309 :
return F_97 ( V_8 ) ;
case V_310 :
return F_98 ( V_8 ) ;
case V_311 :
return F_99 ( V_8 ) ;
default:
F_9 ( L_227
L_16 , V_9 [ 1 ] & 0x1f ) ;
return V_64 ;
}
}
int F_101 ( struct V_7 * V_8 )
{
unsigned char * V_9 = & V_8 -> V_40 [ 0 ] ;
struct V_14 * V_15 = V_8 -> V_16 ;
if ( V_15 -> V_25 & V_32 ) {
F_9 ( L_228
L_229
L_230 ) ;
return V_42 ;
}
return ( V_9 [ 0 ] == V_84 ) ?
F_95 ( V_8 , V_9 ) :
F_100 ( V_8 , V_9 ) ;
}
static int F_102 ( struct V_7 * V_8 , T_1 * V_55 )
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
int F_104 ( struct V_14 * V_15 , int V_312 )
{
struct V_43 * V_44 = V_15 -> V_45 ;
struct V_46 * V_313 = & V_44 -> V_48 ;
if ( ( ( V_15 -> V_182 -> V_314 == V_315 ) &&
! ( V_15 -> V_45 -> V_188 . V_316 ) ) || V_312 ) {
V_313 -> V_50 = V_317 ;
V_313 -> V_318 . V_319 = & F_102 ;
V_313 -> V_318 . V_320 = & F_103 ;
F_7 ( L_231
L_232 , V_15 -> V_182 -> V_183 ) ;
return 0 ;
}
if ( V_15 -> V_182 -> V_321 ( V_15 ) >= V_322 ) {
V_313 -> V_50 = V_51 ;
V_313 -> V_318 . V_319 = & F_18 ;
V_313 -> V_318 . V_320 = & F_14 ;
F_7 ( L_233
L_232 , V_15 -> V_182 -> V_183 ) ;
} else {
V_313 -> V_50 = V_323 ;
V_313 -> V_318 . V_319 = & F_3 ;
V_313 -> V_318 . V_320 =
& F_2 ;
F_7 ( L_234 ,
V_15 -> V_182 -> V_183 ) ;
}
return 0 ;
}
