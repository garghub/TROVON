int F_1 (
struct V_1 * V_2 ,
char * V_3 ,
T_1 V_4 )
{
if ( ! ( V_2 -> V_5 ) )
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
if ( ! ( V_18 ) )
return 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
if ( V_15 -> V_22 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - 1 ;
}
if ( ! ( V_15 -> V_24 & V_25 ) ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_26 == V_18 -> V_27 ) ? 0 : - 1 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_28 * V_29 = V_18 -> V_30 ;
if ( ! ( V_18 ) || ! ( V_29 ) )
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
V_15 -> V_24 &= ~ V_31 ;
if ( V_15 -> V_24 & V_25 ) {
V_15 -> V_26 = 0 ;
V_15 -> V_24 &= ~ V_25 ;
}
F_7 ( V_32 L_2
L_3 , F_8 ( V_29 ) -> F_9 () ,
F_10 ( V_8 ) -> V_33 , V_8 -> V_34 -> V_35 ,
V_18 -> V_23 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_28 * V_29 = V_18 -> V_30 ;
if ( ( F_12 ( V_8 ) -> V_37 [ 1 ] & 0x01 ) &&
( F_12 ( V_8 ) -> V_37 [ 1 ] & 0x02 ) ) {
F_7 ( V_38 L_4
L_5 ) ;
return V_39 ;
}
if ( ! ( V_18 ) || ! ( V_29 ) )
return 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_22 &&
( V_15 -> V_22 != V_18 -> V_23 ) ) {
F_7 ( V_38 L_6 ,
F_8 ( V_29 ) -> F_9 () ) ;
F_7 ( V_38 L_7 ,
F_10 ( V_8 ) -> V_33 ,
V_15 -> V_22 -> V_36 ) ;
F_7 ( V_38 L_8
L_9 , F_10 ( V_8 ) -> V_33 ,
V_8 -> V_34 -> V_35 ,
V_18 -> V_23 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_40 ;
}
V_15 -> V_22 = V_18 -> V_23 ;
V_15 -> V_24 |= V_31 ;
if ( V_18 -> V_27 != 0 ) {
V_15 -> V_26 = V_18 -> V_27 ;
V_15 -> V_24 |= V_25 ;
}
F_7 ( V_32 L_10
L_11 , F_8 ( V_29 ) -> F_9 () ,
F_10 ( V_8 ) -> V_33 , V_8 -> V_34 -> V_35 ,
V_18 -> V_23 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
int F_13 ( struct V_7 * V_8 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_41 * V_42 = V_8 -> V_16 -> V_43 ;
struct V_1 * V_2 ;
struct V_44 * V_45 = & V_42 -> V_46 ;
unsigned char * V_9 = & F_12 ( V_8 ) -> V_37 [ 0 ] ;
int V_47 = ( F_14 ( V_42 ) -> V_48 == V_49 ) ;
int V_50 = 0 ;
if ( ! ( V_19 ) )
return 0 ;
if ( ! ( V_47 ) )
goto V_51;
V_2 = F_15 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( V_2 ) {
if ( V_2 -> V_52 ) {
F_16 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_53 == V_54 ) ||
( V_2 -> V_53 == V_55 ) ||
( V_2 -> V_53 == V_56 ) ||
( V_2 -> V_53 == V_57 ) ) {
F_16 ( V_2 ) ;
return 0 ;
}
F_16 ( V_2 ) ;
V_50 = 1 ;
} else {
F_4 ( & V_45 -> V_58 ) ;
V_50 = ( F_17 ( & V_45 -> V_59 ) ) ? 0 : 1 ;
F_5 ( & V_45 -> V_58 ) ;
}
if ( V_50 ) {
F_7 ( V_38 L_12
L_13
L_14 ) ;
return V_40 ;
}
V_51:
if ( ( V_9 [ 0 ] == V_60 ) || ( V_9 [ 0 ] == V_61 ) )
return F_11 ( V_8 ) ;
else if ( ( V_9 [ 0 ] == V_12 ) || ( V_9 [ 0 ] == V_13 ) )
return F_6 ( V_8 ) ;
else
return V_62 ;
}
static int F_18 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
struct V_63 * V_34 ;
struct V_17 * V_19 = F_19 ( V_8 ) ;
int V_64 = 0 , V_65 ;
int V_66 = 0 , V_20 = 1 ;
int V_67 = 0 , V_68 = 0 ;
int V_69 = 0 ;
int V_70 = 0 ;
if ( V_8 -> V_16 -> V_24 & V_31 )
return F_2 ( V_8 ,
V_9 , V_10 ) ;
V_34 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
V_65 = ( V_10 & 0x80000000 ) ;
if ( V_65 )
V_10 &= ~ 0x80000000 ;
switch ( V_10 ) {
case V_73 :
V_69 = 1 ;
case V_74 :
if ( ( V_34 -> V_75 ) && ! ( V_65 ) )
V_66 = 1 ;
break;
case V_54 :
V_69 = 1 ;
case V_55 :
V_68 = 1 ;
if ( ( V_34 -> V_75 ) && ! ( V_65 ) )
V_66 = 1 ;
break;
case V_56 :
V_69 = 1 ;
case V_57 :
V_67 = 1 ;
if ( ( V_34 -> V_75 ) && ! ( V_65 ) )
V_66 = 1 ;
break;
default:
return - 1 ;
}
switch ( V_9 [ 0 ] ) {
case V_76 :
if ( V_66 )
return 0 ;
V_20 = ( V_69 ) ? 0 : 1 ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
if ( V_70 ) {
V_20 = 1 ;
break;
}
if ( V_66 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_69 ) ? 0 : 1 ;
break;
case V_82 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_83 :
case V_84 :
case V_85 :
V_20 = ( V_66 ) ? 0 : 1 ;
break;
case V_86 :
case V_87 :
V_20 = 0 ;
break;
case V_88 :
case V_89 :
V_20 = 1 ;
break;
case V_90 :
V_20 = ( V_66 ) ? 0 : 1 ;
break;
default:
F_7 ( V_38 L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
return - 1 ;
}
break;
case V_12 :
case V_13 :
V_20 = 0 ;
break;
case V_60 :
case V_61 :
V_20 = 0 ;
break;
case V_91 :
V_20 = ( V_70 ) ? 1 : 0 ;
break;
case V_92 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_93 :
if ( V_66 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_69 ) ? 0 : 1 ;
break;
case V_94 :
case V_95 :
if ( V_70 ) {
V_20 = 1 ;
break;
}
if ( V_66 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_69 ) ? 0 : 1 ;
break;
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_20 = 0 ;
break;
default:
F_7 ( V_38 L_17 ,
( V_9 [ 1 ] & 0x1f ) ) ;
return - 1 ;
}
break;
case V_101 :
case V_102 :
case V_11 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_20 = 0 ;
break;
default:
V_64 = 1 ;
break;
}
if ( ! ( V_20 ) && ! ( V_64 ) ) {
#if 0
printk(KERN_INFO "Allowing explict CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return V_20 ;
}
if ( ( V_69 ) && ! ( V_66 ) ) {
if ( V_8 -> V_107 == V_108 ) {
F_7 ( V_32 L_18
L_19 ,
F_20 ( V_8 ) ,
V_19 -> V_23 -> V_36 , V_9 [ 0 ] ,
F_21 ( V_10 ) ) ;
return 1 ;
} else {
#if 0
if (!(registered_nexus)) {
printk(KERN_INFO "Allowing implict CDB: 0x%02x"
" for %s reservation on unregistered"
" nexus\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
}
#endif
return 0 ;
}
} else if ( ( V_68 ) || ( V_67 ) ) {
if ( V_66 ) {
#if 0
printk(KERN_INFO "Allowing implict CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return 0 ;
}
}
F_7 ( V_32 L_20
L_21 , F_20 ( V_8 ) ,
( V_66 ) ? L_22 : L_23 ,
V_19 -> V_23 -> V_36 , V_9 [ 0 ] ,
F_21 ( V_10 ) ) ;
return 1 ;
}
static T_1 F_22 ( struct V_14 * V_15 )
{
struct V_41 * V_42 = F_23 ( V_15 ) ;
T_1 V_109 ;
F_4 ( & V_15 -> V_21 ) ;
V_109 = F_14 ( V_42 ) -> V_110 ++ ;
F_5 ( & V_15 -> V_21 ) ;
return V_109 ;
}
static int F_24 (
struct V_7 * V_8 ,
T_1 * V_10 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
int V_20 ;
if ( ! ( V_18 ) )
return 0 ;
if ( V_15 -> V_24 & V_31 )
return F_3 ( V_8 , V_10 ) ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! ( V_15 -> V_111 ) ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
* V_10 = V_15 -> V_111 -> V_53 ;
V_8 -> V_112 = V_15 -> V_111 -> V_112 ;
if ( V_15 -> V_111 -> V_113 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - 1 ;
}
if ( ! ( V_15 -> V_111 -> V_5 ) ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_111 -> V_114 ==
V_18 -> V_27 ) ? 0 : - 1 ;
if ( V_20 != 0 )
* V_10 |= 0x80000000 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static struct V_1 * F_25 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_63 * V_116 ,
unsigned char * V_117 ,
T_2 V_118 ,
int V_119 ,
int V_120 )
{
struct V_41 * V_42 = F_23 ( V_15 ) ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_121 , V_122 ) ;
if ( ! ( V_2 ) ) {
F_7 ( V_38 L_24 ) ;
return NULL ;
}
V_2 -> V_123 = F_27 ( F_14 ( V_42 ) -> V_124 ,
V_122 ) ;
if ( ! ( V_2 -> V_123 ) ) {
F_7 ( V_38 L_25 ) ;
F_28 ( V_121 , V_2 ) ;
return NULL ;
}
F_29 ( & V_2 -> V_125 ) ;
F_29 ( & V_2 -> V_126 ) ;
F_29 ( & V_2 -> V_127 ) ;
F_29 ( & V_2 -> V_128 ) ;
F_29 ( & V_2 -> V_129 ) ;
F_30 ( & V_2 -> V_130 , 0 ) ;
V_2 -> V_113 = V_115 ;
V_2 -> V_131 = V_116 ;
V_2 -> V_132 = V_116 -> V_35 ;
V_2 -> V_133 = V_116 -> V_134 -> V_33 ;
V_2 -> V_112 = V_118 ;
V_2 -> V_135 = V_119 ;
V_2 -> V_136 = V_120 ;
V_2 -> V_137 = V_116 -> V_134 ;
if ( V_117 != NULL ) {
V_2 -> V_114 = F_31 ( V_117 ) ;
snprintf ( V_2 -> V_6 , V_138 , L_26 , V_117 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_32 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_63 * V_116 ,
unsigned char * V_117 ,
T_2 V_118 ,
int V_119 ,
int V_120 )
{
struct V_63 * V_139 ;
struct V_23 * V_140 ;
struct V_141 * V_142 , * V_143 ;
struct V_144 * V_145 = V_115 -> V_30 -> V_146 ;
struct V_1 * V_2 , * V_147 , * V_148 , * V_149 ;
int V_20 ;
V_2 = F_25 ( V_15 , V_115 , V_116 , V_117 ,
V_118 , V_119 , V_120 ) ;
if ( ! ( V_2 ) )
return NULL ;
if ( ! ( V_119 ) )
return V_2 ;
F_4 ( & V_15 -> V_150 ) ;
F_33 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_34 ( & V_142 -> V_151 ) ;
F_35 () ;
F_5 ( & V_15 -> V_150 ) ;
F_36 ( & V_142 -> V_152 ) ;
F_37 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! ( V_139 -> V_153 ) )
continue;
V_140 = V_139 -> V_153 -> V_154 ;
if ( V_115 == V_140 )
continue;
if ( V_145 != V_140 -> V_30 -> V_146 )
continue;
if ( strcmp ( V_115 -> V_36 , V_140 -> V_36 ) )
continue;
F_34 ( & V_139 -> V_155 ) ;
F_35 () ;
F_38 ( & V_142 -> V_152 ) ;
V_20 = F_39 ( V_139 ) ;
if ( V_20 < 0 ) {
F_7 ( V_38 L_27
L_28 ) ;
F_40 ( & V_142 -> V_151 ) ;
F_41 () ;
F_40 ( & V_139 -> V_155 ) ;
F_41 () ;
goto V_156;
}
V_147 = F_25 ( V_15 ,
V_140 , V_139 , NULL ,
V_118 , V_119 , V_120 ) ;
if ( ! ( V_147 ) ) {
F_40 ( & V_142 -> V_151 ) ;
F_41 () ;
F_40 ( & V_139 -> V_155 ) ;
F_41 () ;
F_42 ( V_139 ) ;
goto V_156;
}
F_43 ( & V_147 -> V_129 ,
& V_2 -> V_128 ) ;
F_36 ( & V_142 -> V_152 ) ;
}
F_38 ( & V_142 -> V_152 ) ;
F_4 ( & V_15 -> V_150 ) ;
F_40 ( & V_142 -> V_151 ) ;
F_41 () ;
}
F_5 ( & V_15 -> V_150 ) ;
return V_2 ;
V_156:
F_33 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_44 ( & V_148 -> V_129 ) ;
F_42 ( V_148 -> V_131 ) ;
F_28 ( V_121 , V_148 ) ;
}
F_28 ( V_121 , V_2 ) ;
return NULL ;
}
int F_45 (
struct V_44 * V_45 ,
T_2 V_118 ,
unsigned char * V_157 ,
unsigned char * V_117 ,
T_1 V_35 ,
unsigned char * V_158 ,
T_3 V_159 ,
T_1 V_160 ,
int V_161 ,
int V_119 ,
T_4 type )
{
struct V_1 * V_2 ;
if ( ! ( V_157 ) || ! ( V_158 ) || ! ( V_118 ) ) {
F_7 ( V_38 L_29 ) ;
return - 1 ;
}
V_2 = F_26 ( V_121 , V_162 ) ;
if ( ! ( V_2 ) ) {
F_7 ( V_38 L_24 ) ;
return - 1 ;
}
V_2 -> V_123 = F_27 ( V_45 -> V_124 , V_162 ) ;
F_29 ( & V_2 -> V_125 ) ;
F_29 ( & V_2 -> V_126 ) ;
F_29 ( & V_2 -> V_127 ) ;
F_29 ( & V_2 -> V_128 ) ;
F_29 ( & V_2 -> V_129 ) ;
F_30 ( & V_2 -> V_130 , 0 ) ;
V_2 -> V_113 = NULL ;
V_2 -> V_131 = NULL ;
V_2 -> V_132 = V_35 ;
V_2 -> V_133 = V_160 ;
V_2 -> V_112 = V_118 ;
V_2 -> V_135 = V_119 ;
V_2 -> V_136 = 1 ;
V_2 -> V_137 = NULL ;
V_2 -> V_163 = 0 ;
V_2 -> V_53 = type ;
if ( V_117 != NULL ) {
V_2 -> V_114 = F_31 ( V_117 ) ;
snprintf ( V_2 -> V_6 , V_138 , L_26 , V_117 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_164 , V_165 , L_26 , V_157 ) ;
snprintf ( V_2 -> V_166 , V_167 , L_26 , V_158 ) ;
V_2 -> V_168 = V_159 ;
V_2 -> V_52 = V_161 ;
F_43 ( & V_2 -> V_127 , & V_45 -> V_169 ) ;
F_7 ( V_32 L_30
L_31 , ( V_161 ) ? L_32 : L_22 ) ;
return 0 ;
}
static void F_46 (
struct V_14 * V_15 ,
struct V_28 * V_29 ,
struct V_23 * V_170 ,
struct V_1 * V_2 )
{
char V_171 [ V_172 ] ;
int V_173 ;
memset ( V_171 , 0 , V_172 ) ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_15 -> V_111 = V_2 ;
F_5 ( & V_15 -> V_21 ) ;
F_7 ( V_32 L_33
L_34 ,
F_8 ( V_29 ) -> F_9 () ,
F_21 ( V_2 -> V_53 ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_7 ( V_32 L_35 ,
F_8 ( V_29 ) -> F_9 () , V_170 -> V_36 ,
( V_173 ) ? & V_171 [ 0 ] : L_22 ) ;
}
static int F_47 (
struct V_14 * V_15 ,
struct V_28 * V_29 ,
struct V_134 * V_174 ,
T_1 V_160 ,
struct V_23 * V_115 ,
struct V_63 * V_116 )
{
struct V_1 * V_2 , * V_148 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
unsigned char V_157 [ V_165 ] ;
unsigned char V_158 [ V_167 ] ;
T_3 V_159 ;
memset ( V_157 , 0 , V_165 ) ;
memset ( V_158 , 0 , V_167 ) ;
snprintf ( V_157 , V_165 , L_26 , V_115 -> V_36 ) ;
snprintf ( V_158 , V_167 , L_26 ,
F_8 ( V_29 ) -> F_48 ( V_29 ) ) ;
V_159 = F_8 ( V_29 ) -> F_49 ( V_29 ) ;
F_4 ( & V_45 -> V_175 ) ;
F_33 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! ( strcmp ( V_2 -> V_164 , V_157 ) ) &&
( V_2 -> V_132 == V_116 -> V_35 ) &&
! ( strcmp ( V_2 -> V_166 , V_158 ) ) &&
( V_2 -> V_168 == V_159 ) &&
( V_2 -> V_133 == V_160 ) ) {
V_2 -> V_113 = V_115 ;
V_2 -> V_131 = V_116 ;
V_2 -> V_137 = V_174 ;
F_44 ( & V_2 -> V_127 ) ;
F_5 ( & V_45 -> V_175 ) ;
F_50 ( V_15 , V_115 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_52 )
F_46 ( V_15 , V_29 ,
V_115 , V_2 ) ;
F_4 ( & V_45 -> V_175 ) ;
V_45 -> V_176 = 1 ;
}
}
F_5 ( & V_45 -> V_175 ) ;
return 0 ;
}
int F_51 (
struct V_14 * V_15 ,
struct V_28 * V_29 ,
struct V_134 * V_174 ,
struct V_153 * V_177 )
{
struct V_41 * V_42 = F_23 ( V_15 ) ;
struct V_23 * V_115 = V_177 -> V_154 ;
struct V_63 * V_116 = & V_115 -> V_71 [ V_177 -> V_35 ] ;
if ( F_14 ( V_42 ) -> V_48 != V_49 )
return 0 ;
return F_47 ( V_15 , V_29 , V_174 ,
V_174 -> V_33 , V_115 , V_116 ) ;
}
static void F_52 (
struct V_144 * V_145 ,
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_1 * V_2 ,
int V_178 )
{
struct V_28 * V_30 = V_115 -> V_30 ;
char V_171 [ V_172 ] ;
int V_173 ;
memset ( & V_171 [ 0 ] , 0 , V_172 ) ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
F_7 ( V_32 L_36
L_37 , V_145 -> F_9 () , ( V_178 == 2 ) ?
L_38 : ( V_178 == 1 ) ?
L_39 : L_22 , V_115 -> V_36 ,
( V_173 ) ? V_171 : L_22 ) ;
F_7 ( V_32 L_40 ,
V_145 -> F_9 () , V_145 -> F_48 ( V_30 ) ,
V_145 -> F_49 ( V_30 ) ) ;
F_7 ( V_32 L_41
L_42 , V_145 -> F_9 () ,
( V_2 -> V_135 ) ? L_43 : L_44 ,
F_53 ( V_15 ) -> V_179 ) ;
F_7 ( V_32 L_45
L_46 , V_145 -> F_9 () ,
V_2 -> V_112 , V_2 -> V_180 ,
V_2 -> V_136 ) ;
}
static void F_50 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_1 * V_2 ,
int V_178 ,
int V_181 )
{
struct V_41 * V_42 = F_23 ( V_15 ) ;
struct V_144 * V_145 = V_115 -> V_30 -> V_146 ;
struct V_1 * V_148 , * V_149 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
V_2 -> V_180 = ( V_181 ) ?
F_14 ( V_42 ) -> V_110 ++ :
F_22 ( V_15 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_43 ( & V_2 -> V_125 , & V_45 -> V_59 ) ;
V_2 -> V_131 -> V_75 = 1 ;
F_52 ( V_145 , V_15 , V_115 , V_2 , V_178 ) ;
F_5 ( & V_45 -> V_58 ) ;
if ( ! ( V_2 -> V_135 ) || ( V_181 ) )
return;
F_33 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_44 ( & V_148 -> V_129 ) ;
V_148 -> V_180 = F_22 ( V_15 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_43 ( & V_148 -> V_125 ,
& V_45 -> V_59 ) ;
V_148 -> V_131 -> V_75 = 1 ;
F_52 ( V_145 , V_15 ,
V_148 -> V_113 , V_148 ,
V_178 ) ;
F_5 ( & V_45 -> V_58 ) ;
F_42 ( V_148 -> V_131 ) ;
}
}
static int F_54 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_63 * V_116 ,
unsigned char * V_117 ,
T_2 V_118 ,
int V_119 ,
int V_120 ,
int V_178 ,
int V_181 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( V_15 , V_115 , V_116 , V_117 ,
V_118 , V_119 , V_120 ) ;
if ( ! ( V_2 ) )
return - 1 ;
F_50 ( V_15 , V_115 , V_2 ,
V_178 , V_181 ) ;
return 0 ;
}
static struct V_1 * F_55 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
unsigned char * V_117 )
{
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
struct V_1 * V_2 , * V_148 ;
struct V_28 * V_29 ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_113 != V_115 )
continue;
V_29 = V_2 -> V_113 -> V_30 ;
if ( ! ( V_2 -> V_5 ) ) {
if ( F_8 ( V_29 ) -> V_182 != NULL ) {
if ( F_56 ( V_15 ) -> V_183 )
continue;
}
F_34 ( & V_2 -> V_130 ) ;
F_35 () ;
F_5 ( & V_45 -> V_58 ) ;
return V_2 ;
}
if ( ! ( V_117 ) )
continue;
if ( strcmp ( V_117 , V_2 -> V_6 ) )
continue;
F_34 ( & V_2 -> V_130 ) ;
F_35 () ;
F_5 ( & V_45 -> V_58 ) ;
return V_2 ;
}
F_5 ( & V_45 -> V_58 ) ;
return NULL ;
}
static struct V_1 * F_15 (
struct V_14 * V_15 ,
struct V_23 * V_115 ,
struct V_17 * V_18 )
{
struct V_28 * V_29 = V_115 -> V_30 ;
unsigned char V_3 [ V_138 ] , * V_184 = NULL ;
if ( F_8 ( V_29 ) -> V_182 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_138 ) ;
F_8 ( V_29 ) -> V_182 ( V_18 , & V_3 [ 0 ] ,
V_138 ) ;
V_184 = & V_3 [ 0 ] ;
}
return F_55 ( V_15 , V_115 , V_184 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_130 ) ;
F_41 () ;
}
static int F_57 (
struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_23 * V_115 = V_2 -> V_113 ;
struct V_1 * V_52 ;
int V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( ! ( V_52 ) ) {
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
if ( V_52 == V_2 ) {
F_58 ( V_15 , V_115 , V_2 , 0 ) ;
V_20 = 1 ;
} else if ( V_2 -> V_135 &&
( ! strcmp ( V_52 -> V_113 -> V_36 ,
V_2 -> V_113 -> V_36 ) ) &&
( V_52 -> V_112 == V_2 -> V_112 ) ) {
F_7 ( V_38 L_47
L_48
L_49
L_50 , V_2 -> V_112 ) ;
V_20 = - 1 ;
}
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static void F_59 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_185 * V_186 ,
int V_187 )
{
struct V_144 * V_145 =
V_2 -> V_113 -> V_30 -> V_146 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
char V_171 [ V_172 ] ;
int V_173 ;
memset ( V_171 , 0 , V_172 ) ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
V_2 -> V_131 -> V_75 = 0 ;
V_2 -> V_131 -> V_112 = 0 ;
F_44 ( & V_2 -> V_125 ) ;
if ( V_187 )
F_16 ( V_2 ) ;
while ( F_60 ( & V_2 -> V_130 ) != 0 ) {
F_5 ( & V_45 -> V_58 ) ;
F_7 ( L_51 ,
V_145 -> F_9 () ) ;
F_61 () ;
F_4 ( & V_45 -> V_58 ) ;
}
F_7 ( V_32 L_52
L_37 , V_145 -> F_9 () ,
V_2 -> V_113 -> V_36 ,
( V_173 ) ? & V_171 [ 0 ] : L_22 ) ;
F_7 ( V_32 L_41
L_42 , V_145 -> F_9 () ,
( V_2 -> V_135 ) ? L_43 : L_44 ,
F_53 ( V_15 ) -> V_179 ) ;
F_7 ( V_32 L_45
L_53 , V_145 -> F_9 () , V_2 -> V_112 ,
V_2 -> V_180 ) ;
if ( ! ( V_186 ) ) {
V_2 -> V_131 = NULL ;
V_2 -> V_113 = NULL ;
F_62 ( V_2 -> V_123 ) ;
F_28 ( V_121 , V_2 ) ;
return;
}
F_43 ( & V_2 -> V_126 , V_186 ) ;
}
void F_63 (
struct V_14 * V_15 ,
struct V_23 * V_115 )
{
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
struct V_1 * V_2 , * V_148 , * V_52 ;
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( ( V_52 != NULL ) &&
( V_52 -> V_113 == V_115 ) )
F_58 ( V_15 , V_115 , V_52 , 0 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_113 != V_115 )
continue;
F_59 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
}
void F_64 (
struct V_14 * V_15 )
{
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
struct V_1 * V_2 , * V_148 , * V_52 ;
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( V_52 != NULL ) {
struct V_23 * V_188 = V_52 -> V_113 ;
F_58 ( V_15 , V_188 ,
V_52 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_59 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
F_4 ( & V_45 -> V_175 ) ;
F_33 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_44 ( & V_2 -> V_127 ) ;
F_62 ( V_2 -> V_123 ) ;
F_28 ( V_121 , V_2 ) ;
}
F_5 ( & V_45 -> V_175 ) ;
}
static int F_65 ( struct V_28 * V_29 )
{
return F_66 ( F_8 ( V_29 ) -> V_189 ,
& V_29 -> V_190 . V_191 ) ;
}
static void F_67 ( struct V_28 * V_29 )
{
F_68 ( F_8 ( V_29 ) -> V_189 ,
& V_29 -> V_190 . V_191 ) ;
F_40 ( & V_29 -> V_192 ) ;
F_41 () ;
}
static int F_69 ( struct V_23 * V_115 )
{
struct V_28 * V_29 = V_115 -> V_30 ;
if ( V_115 -> V_193 )
return 0 ;
return F_66 ( F_8 ( V_29 ) -> V_189 ,
& V_115 -> V_194 . V_191 ) ;
}
static void F_70 ( struct V_23 * V_115 )
{
struct V_28 * V_29 = V_115 -> V_30 ;
if ( V_115 -> V_193 ) {
F_40 ( & V_115 -> V_195 ) ;
F_41 () ;
return;
}
F_68 ( F_8 ( V_29 ) -> V_189 ,
& V_115 -> V_194 . V_191 ) ;
F_40 ( & V_115 -> V_195 ) ;
F_41 () ;
}
static int F_39 ( struct V_63 * V_34 )
{
struct V_153 * V_177 = V_34 -> V_153 ;
struct V_23 * V_115 ;
struct V_28 * V_29 ;
if ( ! ( V_177 ) )
return 0 ;
V_115 = V_177 -> V_154 ;
V_29 = V_115 -> V_30 ;
return F_66 ( F_8 ( V_29 ) -> V_189 ,
& V_177 -> V_196 . V_191 ) ;
}
static void F_42 ( struct V_63 * V_34 )
{
struct V_153 * V_177 = V_34 -> V_153 ;
struct V_23 * V_115 ;
struct V_28 * V_29 ;
if ( ! ( V_177 ) ) {
F_40 ( & V_34 -> V_155 ) ;
F_41 () ;
return;
}
V_115 = V_177 -> V_154 ;
V_29 = V_115 -> V_30 ;
F_68 ( F_8 ( V_29 ) -> V_189 ,
& V_177 -> V_196 . V_191 ) ;
F_40 ( & V_34 -> V_155 ) ;
F_41 () ;
}
static int F_71 (
struct V_7 * V_8 ,
struct V_28 * V_29 ,
unsigned char * V_197 ,
T_2 V_118 ,
int V_119 ,
int V_120 )
{
struct V_14 * V_15 = F_72 ( V_8 ) ;
struct V_141 * V_198 ;
struct V_28 * V_199 = NULL , * V_200 ;
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_23 * V_201 = NULL ;
struct V_63 * V_202 = NULL , * V_203 ;
struct V_1 * V_204 , * V_205 , * V_206 ;
struct V_1 * V_148 , * V_149 ;
struct V_185 V_207 ;
struct V_208 * V_209 , * V_210 , * V_211 ;
struct V_144 * V_212 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
unsigned char * V_214 , * V_215 = NULL , V_216 , V_217 ;
char * V_218 = NULL , V_219 [ 64 ] , V_171 [ V_172 ] ;
T_1 V_220 , V_221 = 0 ;
int V_20 , V_222 , V_173 ;
T_1 V_223 = 0 ;
memset ( V_219 , 0 , 64 ) ;
F_29 ( & V_207 ) ;
V_203 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
V_209 = F_27 ( sizeof( struct V_208 ) , V_162 ) ;
if ( ! ( V_209 ) ) {
F_7 ( V_38 L_54 ) ;
return V_224 ;
}
F_29 ( & V_209 -> V_225 ) ;
V_209 -> V_199 = V_29 ;
V_209 -> V_201 = V_19 -> V_23 ;
V_209 -> V_202 = V_203 ;
V_205 = F_32 ( F_72 ( V_8 ) ,
V_19 -> V_23 , V_203 , V_197 ,
V_118 , V_119 , V_120 ) ;
if ( ! ( V_205 ) ) {
F_62 ( V_209 ) ;
return V_224 ;
}
V_209 -> V_204 = V_205 ;
V_209 -> V_222 = 1 ;
F_43 ( & V_209 -> V_225 , & V_207 ) ;
V_220 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_220 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_220 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_220 |= V_3 [ 27 ] & 0xff ;
if ( ( V_220 + 28 ) != V_8 -> V_226 ) {
F_7 ( V_38 L_55
L_56 , V_220 ,
V_8 -> V_226 ) ;
V_20 = V_227 ;
goto V_156;
}
V_214 = & V_3 [ 28 ] ;
while ( V_220 > 0 ) {
V_216 = ( V_214 [ 0 ] & 0x0f ) ;
V_199 = NULL ;
F_4 ( & V_15 -> V_150 ) ;
F_37 (tmp_port, &dev->dev_sep_list, sep_list) {
V_200 = V_198 -> V_228 ;
if ( ! ( V_200 ) )
continue;
V_212 = F_8 ( V_200 ) ;
if ( ! ( V_212 ) )
continue;
if ( ! ( V_212 -> V_229 ) ||
! ( V_212 -> V_230 ) )
continue;
V_217 = V_212 -> V_229 ( V_200 ) ;
if ( V_217 != V_216 )
continue;
V_223 = V_198 -> V_231 ;
V_215 = V_212 -> V_230 (
V_200 , ( const char * ) V_214 , & V_221 ,
& V_218 ) ;
if ( ! ( V_215 ) )
continue;
F_34 ( & V_200 -> V_192 ) ;
F_35 () ;
F_5 ( & V_15 -> V_150 ) ;
V_20 = F_65 ( V_200 ) ;
if ( V_20 != 0 ) {
F_7 ( V_38 L_57
L_58 ) ;
F_40 ( & V_200 -> V_192 ) ;
F_41 () ;
V_20 = V_224 ;
goto V_156;
}
F_36 ( & V_200 -> V_232 ) ;
V_201 = F_73 (
V_200 , V_215 ) ;
if ( V_201 ) {
F_34 ( & V_201 -> V_195 ) ;
F_35 () ;
}
F_38 ( & V_200 -> V_232 ) ;
if ( ! ( V_201 ) ) {
F_67 ( V_200 ) ;
F_4 ( & V_15 -> V_150 ) ;
continue;
}
V_20 = F_69 ( V_201 ) ;
if ( V_20 != 0 ) {
F_7 ( V_38 L_59
L_60 ) ;
F_40 ( & V_201 -> V_195 ) ;
F_41 () ;
F_67 ( V_200 ) ;
V_20 = V_224 ;
goto V_156;
}
V_199 = V_200 ;
F_7 ( V_32 L_61
L_62 ,
F_8 ( V_199 ) -> F_9 () ,
V_201 -> V_36 , V_223 ) ;
F_4 ( & V_15 -> V_150 ) ;
break;
}
F_5 ( & V_15 -> V_150 ) ;
if ( ! ( V_199 ) ) {
F_7 ( V_38 L_63
L_64 ) ;
V_20 = V_227 ;
goto V_156;
}
#if 0
printk("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
TPG_TFO(dest_tpg)->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
#endif
if ( V_221 > V_220 ) {
F_7 ( V_38 L_65
L_66 , V_221 , V_214 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
V_20 = V_227 ;
goto V_156;
}
V_202 = F_74 ( V_201 ,
V_223 ) ;
if ( ! ( V_202 ) ) {
F_7 ( V_38 L_67
L_68 ,
F_8 ( V_199 ) -> F_9 () ,
V_223 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
V_20 = V_227 ;
goto V_156;
}
V_20 = F_39 ( V_202 ) ;
if ( V_20 < 0 ) {
F_7 ( V_38 L_69
L_70 ) ;
F_40 ( & V_202 -> V_155 ) ;
F_41 () ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
V_20 = V_224 ;
goto V_156;
}
#if 0
printk(KERN_INFO "SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
TPG_TFO(dest_tpg)->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
#endif
V_206 = F_55 ( V_15 , V_201 ,
V_218 ) ;
if ( V_206 ) {
F_16 ( V_206 ) ;
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
V_214 += V_221 ;
V_220 -= V_221 ;
V_221 = 0 ;
continue;
}
V_209 = F_27 ( sizeof( struct V_208 ) ,
V_162 ) ;
if ( ! ( V_209 ) ) {
F_7 ( V_38 L_54 ) ;
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
V_20 = V_224 ;
goto V_156;
}
F_29 ( & V_209 -> V_225 ) ;
V_209 -> V_199 = V_199 ;
V_209 -> V_201 = V_201 ;
V_209 -> V_202 = V_202 ;
V_204 = F_32 ( F_72 ( V_8 ) ,
V_201 , V_202 , V_218 ,
V_118 , V_119 , V_120 ) ;
if ( ! ( V_204 ) ) {
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
F_62 ( V_209 ) ;
V_20 = V_227 ;
goto V_156;
}
V_209 -> V_204 = V_204 ;
F_43 ( & V_209 -> V_225 , & V_207 ) ;
V_214 += V_221 ;
V_220 -= V_221 ;
V_221 = 0 ;
}
F_33 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_199 = V_210 -> V_199 ;
V_201 = V_210 -> V_201 ;
V_202 = V_210 -> V_202 ;
V_204 = V_210 -> V_204 ;
V_222 = V_210 -> V_222 ;
F_44 ( & V_210 -> V_225 ) ;
F_62 ( V_210 ) ;
memset ( V_171 , 0 , V_172 ) ;
V_173 = F_1 ( V_204 , & V_171 [ 0 ] ,
V_172 ) ;
F_50 ( F_72 ( V_8 ) , V_201 ,
V_204 , 0 , 0 ) ;
F_7 ( V_32 L_71
L_72
L_73 , F_8 ( V_199 ) -> F_9 () ,
V_201 -> V_36 , ( V_173 ) ?
& V_171 [ 0 ] : L_22 , V_202 -> V_35 ) ;
if ( V_222 )
continue;
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
}
return 0 ;
V_156:
F_33 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_199 = V_210 -> V_199 ;
V_201 = V_210 -> V_201 ;
V_202 = V_210 -> V_202 ;
V_204 = V_210 -> V_204 ;
V_222 = V_210 -> V_222 ;
F_44 ( & V_210 -> V_225 ) ;
F_62 ( V_210 ) ;
F_33 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_44 ( & V_148 -> V_129 ) ;
F_42 ( V_148 -> V_131 ) ;
F_28 ( V_121 , V_148 ) ;
}
F_62 ( V_204 -> V_123 ) ;
F_28 ( V_121 , V_204 ) ;
if ( V_222 )
continue;
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_199 ) ;
}
return V_20 ;
}
static int F_75 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_124 ,
int V_233 )
{
struct V_134 * V_174 ;
struct V_28 * V_29 ;
struct V_41 * V_42 = F_23 ( V_15 ) ;
struct V_1 * V_2 ;
unsigned char V_234 [ 512 ] , V_235 [ 32 ] ;
T_5 V_236 = 0 ;
int V_237 = 0 ;
memset ( V_3 , 0 , V_124 ) ;
if ( V_233 ) {
snprintf ( V_3 , V_124 ,
L_74 ) ;
return 0 ;
}
F_4 ( & F_14 ( V_42 ) -> V_58 ) ;
F_37 (pr_reg, &T10_RES(su_dev)->registration_list,
pr_reg_list) {
V_234 [ 0 ] = '\0' ;
V_235 [ 0 ] = '\0' ;
V_29 = V_2 -> V_113 -> V_30 ;
V_174 = V_2 -> V_137 ;
if ( V_2 -> V_5 )
snprintf ( V_235 , 32 , L_75 ,
V_2 -> V_6 ) ;
if ( V_15 -> V_111 == V_2 ) {
snprintf ( V_234 , 512 , L_76
L_77
L_78
L_79
L_80
L_81
L_82 , V_237 ,
F_8 ( V_29 ) -> F_9 () ,
V_2 -> V_113 -> V_36 , V_235 ,
V_2 -> V_112 , V_2 -> V_53 ,
V_2 -> V_163 , V_2 -> V_135 ,
V_2 -> V_132 ) ;
} else {
snprintf ( V_234 , 512 , L_83
L_84
L_85
L_86 ,
V_237 , F_8 ( V_29 ) -> F_9 () ,
V_2 -> V_113 -> V_36 , V_235 ,
V_2 -> V_112 , V_2 -> V_135 ,
V_2 -> V_132 ) ;
}
if ( ( V_236 + strlen ( V_234 ) >= V_124 ) ) {
F_7 ( V_38 L_87
L_88 ) ;
F_5 ( & F_14 ( V_42 ) -> V_58 ) ;
return - 1 ;
}
V_236 += sprintf ( V_3 + V_236 , L_26 , V_234 ) ;
snprintf ( V_234 , 512 , L_89
L_90
L_91 , F_8 ( V_29 ) -> F_9 () ,
F_8 ( V_29 ) -> F_48 ( V_29 ) ,
F_8 ( V_29 ) -> F_49 ( V_29 ) ,
V_174 -> V_238 -> V_231 , V_174 -> V_33 , V_237 ) ;
if ( ( V_236 + strlen ( V_234 ) >= V_124 ) ) {
F_7 ( V_38 L_87
L_88 ) ;
F_5 ( & F_14 ( V_42 ) -> V_58 ) ;
return - 1 ;
}
V_236 += sprintf ( V_3 + V_236 , L_26 , V_234 ) ;
V_237 ++ ;
}
F_5 ( & F_14 ( V_42 ) -> V_58 ) ;
if ( ! ( V_237 ) )
V_236 += sprintf ( V_3 + V_236 , L_92 ) ;
return 0 ;
}
static int F_76 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_124 ,
int V_233 )
{
int V_20 ;
F_4 ( & V_15 -> V_21 ) ;
V_20 = F_75 ( V_15 , V_3 , V_124 ,
V_233 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_77 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_124 )
{
struct V_239 * V_240 = & F_23 ( V_15 ) -> V_239 ;
struct V_241 * V_241 ;
struct V_242 V_243 [ 1 ] ;
T_6 V_244 ;
int V_245 = V_246 | V_247 | V_248 ;
char V_249 [ 512 ] ;
int V_20 ;
memset ( V_243 , 0 , sizeof( struct V_242 ) ) ;
memset ( V_249 , 0 , 512 ) ;
if ( strlen ( & V_240 -> V_250 [ 0 ] ) >= 512 ) {
F_7 ( V_38 L_93
L_94 ) ;
return - 1 ;
}
snprintf ( V_249 , 512 , L_95 , & V_240 -> V_250 [ 0 ] ) ;
V_241 = F_78 ( V_249 , V_245 , 0600 ) ;
if ( F_79 ( V_241 ) || ! V_241 || ! V_241 -> V_251 ) {
F_7 ( V_38 L_96
L_70 , V_249 ) ;
return - 1 ;
}
V_243 [ 0 ] . V_252 = & V_3 [ 0 ] ;
if ( ! ( V_124 ) )
V_243 [ 0 ] . V_253 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_243 [ 0 ] . V_253 = V_124 ;
V_244 = F_80 () ;
F_81 ( F_82 () ) ;
V_20 = F_83 ( V_241 , & V_243 [ 0 ] , 1 , & V_241 -> V_254 ) ;
F_81 ( V_244 ) ;
if ( V_20 < 0 ) {
F_7 ( L_97 , V_249 ) ;
F_84 ( V_241 , NULL ) ;
return - 1 ;
}
F_84 ( V_241 , NULL ) ;
return 0 ;
}
static int F_85 (
struct V_14 * V_15 ,
unsigned char * V_255 ,
T_1 V_256 )
{
unsigned char V_257 [ 64 ] , * V_3 ;
T_1 V_124 ;
int V_20 , V_233 = 0 ;
if ( ! ( V_255 ) ) {
memset ( V_257 , 0 , 64 ) ;
V_3 = & V_257 [ 0 ] ;
V_124 = 64 ;
V_233 = 1 ;
} else {
V_3 = V_255 ;
V_124 = V_256 ;
}
V_20 = F_76 ( V_15 , V_3 , V_124 ,
V_233 ) ;
if ( V_20 != 0 )
return - 1 ;
V_20 = F_77 ( V_15 , V_3 , 0 ) ;
if ( V_20 != 0 )
return - 1 ;
return V_20 ;
}
static int F_86 (
struct V_7 * V_8 ,
T_2 V_258 ,
T_2 V_118 ,
int V_120 ,
int V_119 ,
int V_259 ,
int V_260 )
{
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_14 * V_15 = F_72 ( V_8 ) ;
struct V_63 * V_34 ;
struct V_134 * V_134 = F_10 ( V_8 ) ;
struct V_28 * V_30 ;
struct V_1 * V_2 , * V_261 , * V_148 , * V_206 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
unsigned char * V_123 = NULL ;
unsigned char V_235 [ V_138 ] , * V_184 = NULL ;
int V_262 = 0 , V_20 = 0 , type ;
if ( ! ( V_19 ) || ! ( V_134 ) ) {
F_7 ( V_38 L_98 ) ;
return V_224 ;
}
V_30 = V_19 -> V_30 ;
V_34 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
if ( F_8 ( V_30 ) -> V_182 != NULL ) {
memset ( & V_235 [ 0 ] , 0 , V_138 ) ;
F_8 ( V_30 ) -> V_182 ( V_19 , & V_235 [ 0 ] ,
V_138 ) ;
V_184 = & V_235 [ 0 ] ;
}
V_206 = F_15 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! ( V_206 ) ) {
if ( V_258 ) {
F_7 ( V_263 L_99
L_100 ) ;
return V_40 ;
}
if ( ! ( V_118 ) )
return V_264 ;
if ( ! ( V_259 ) ) {
V_20 = F_54 ( F_72 ( V_8 ) ,
V_19 -> V_23 , V_34 , V_184 ,
V_118 , V_119 , V_120 ,
V_260 , 0 ) ;
if ( V_20 != 0 ) {
F_7 ( V_38 L_101
L_102 ) ;
return V_227 ;
}
} else {
V_20 = F_71 ( V_8 , V_30 ,
V_184 , V_118 , V_119 , V_120 ) ;
if ( V_20 != 0 )
return V_20 ;
}
if ( ! ( V_120 ) ) {
V_45 -> V_176 = 0 ;
F_85 ( F_72 ( V_8 ) , NULL , 0 ) ;
F_7 ( L_103
L_104 ) ;
return 0 ;
}
V_2 = F_15 ( F_72 ( V_8 ) ,
V_19 -> V_23 , V_19 ) ;
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_2 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) ) {
V_45 -> V_176 = 1 ;
F_7 ( L_105 ) ;
}
F_16 ( V_2 ) ;
return V_20 ;
} else {
V_2 = V_206 ;
type = V_2 -> V_53 ;
if ( ! ( V_260 ) ) {
if ( V_258 != V_2 -> V_112 ) {
F_7 ( V_38 L_106
L_107
L_108
L_109 , V_258 ,
V_2 -> V_112 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
}
if ( V_259 ) {
F_7 ( V_38 L_110
L_111 ) ;
F_16 ( V_2 ) ;
return V_227 ;
}
if ( V_2 -> V_135 && ! ( V_119 ) ) {
F_7 ( V_38 L_112
L_113
L_114 ) ;
F_16 ( V_2 ) ;
return V_62 ;
}
if ( V_120 ) {
V_123 = F_27 ( V_45 -> V_124 ,
V_162 ) ;
if ( ! ( V_123 ) ) {
F_7 ( V_38 L_101
L_115 ) ;
F_16 ( V_2 ) ;
return V_224 ;
}
}
if ( ! ( V_118 ) ) {
V_262 = F_57 (
F_72 ( V_8 ) , V_2 ) ;
if ( V_262 < 0 ) {
F_62 ( V_123 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
F_4 ( & V_45 -> V_58 ) ;
if ( V_2 -> V_135 ) {
F_33 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! ( V_261 -> V_135 ) )
continue;
if ( V_261 -> V_112 != V_258 )
continue;
if ( V_2 == V_261 )
continue;
if ( strcmp ( V_2 -> V_113 -> V_36 ,
V_261 -> V_113 -> V_36 ) )
continue;
F_59 ( V_15 ,
V_261 , NULL , 0 ) ;
}
}
F_59 ( F_72 ( V_8 ) , V_2 ,
NULL , 1 ) ;
if ( V_262 &&
( ( type == V_54 ) ||
( type == V_55 ) ) ) {
F_37 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_87 (
V_261 -> V_113 ,
V_261 -> V_132 ,
0x2A ,
V_265 ) ;
}
}
F_5 ( & V_45 -> V_58 ) ;
if ( ! ( V_120 ) ) {
V_45 -> V_176 = 0 ;
F_85 ( V_15 , NULL , 0 ) ;
F_7 ( L_116
L_117 ) ;
return 0 ;
}
V_20 = F_85 ( V_15 ,
& V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) ) {
V_45 -> V_176 = 1 ;
F_7 ( L_118
L_117 ) ;
}
F_62 ( V_123 ) ;
return V_20 ;
} else {
V_2 -> V_180 = F_22 (
F_72 ( V_8 ) ) ;
V_2 -> V_112 = V_118 ;
F_7 ( L_119
L_120
L_53 , F_88 ( V_8 ) -> F_9 () ,
( V_260 ) ? L_39 : L_22 ,
V_2 -> V_113 -> V_36 ,
V_2 -> V_112 , V_2 -> V_180 ) ;
if ( ! ( V_120 ) ) {
V_45 -> V_176 = 0 ;
F_85 ( V_15 , NULL , 0 ) ;
F_16 ( V_2 ) ;
F_7 ( L_116
L_121 ) ;
return 0 ;
}
V_20 = F_85 ( V_15 ,
& V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) ) {
V_45 -> V_176 = 1 ;
F_7 ( L_118
L_121 ) ;
}
F_62 ( V_123 ) ;
F_16 ( V_2 ) ;
}
}
return 0 ;
}
unsigned char * F_21 ( int type )
{
switch ( type ) {
case V_73 :
return L_122 ;
case V_74 :
return L_123 ;
case V_54 :
return L_124 ;
case V_55 :
return L_125 ;
case V_56 :
return L_126 ;
case V_57 :
return L_127 ;
default:
break;
}
return L_128 ;
}
static int F_89 (
struct V_7 * V_8 ,
struct V_14 * V_15 ,
int type ,
int V_266 ,
T_2 V_258 )
{
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_63 * V_34 ;
struct V_134 * V_134 = F_10 ( V_8 ) ;
struct V_28 * V_30 ;
struct V_1 * V_2 , * V_52 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
char V_171 [ V_172 ] ;
int V_20 , V_173 ;
memset ( V_171 , 0 , V_172 ) ;
if ( ! ( V_19 ) || ! ( V_134 ) ) {
F_7 ( V_38 L_98 ) ;
return V_224 ;
}
V_30 = V_19 -> V_30 ;
V_34 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
V_2 = F_15 ( F_72 ( V_8 ) , V_19 -> V_23 ,
V_19 ) ;
if ( ! ( V_2 ) ) {
F_7 ( V_38 L_129
L_130 ) ;
return V_224 ;
}
if ( V_258 != V_2 -> V_112 ) {
F_7 ( V_38 L_131
L_132
L_109 , V_258 , V_2 -> V_112 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
if ( V_266 != V_267 ) {
F_7 ( V_38 L_133 , V_266 ) ;
F_16 ( V_2 ) ;
return V_227 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( ( V_52 ) ) {
if ( V_52 != V_2 ) {
struct V_23 * V_188 = V_52 -> V_113 ;
F_7 ( V_38 L_134
L_135
L_136 ,
F_88 ( V_8 ) -> F_9 () ,
V_19 -> V_23 -> V_36 ,
F_8 ( V_188 -> V_30 ) -> F_9 () ,
V_52 -> V_113 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
if ( ( V_52 -> V_53 != type ) ||
( V_52 -> V_163 != V_266 ) ) {
struct V_23 * V_188 = V_52 -> V_113 ;
F_7 ( V_38 L_134
L_137
L_138
L_14 ,
F_88 ( V_8 ) -> F_9 () ,
V_19 -> V_23 -> V_36 ,
F_8 ( V_188 -> V_30 ) -> F_9 () ,
V_52 -> V_113 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_264 ;
}
V_2 -> V_163 = V_266 ;
V_2 -> V_53 = type ;
V_2 -> V_52 = 1 ;
V_15 -> V_111 = V_2 ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
F_7 ( V_32 L_139
L_140 ,
F_88 ( V_8 ) -> F_9 () , F_21 ( type ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_7 ( V_32 L_35 ,
F_88 ( V_8 ) -> F_9 () ,
V_19 -> V_23 -> V_36 ,
( V_173 ) ? & V_171 [ 0 ] : L_22 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( V_45 -> V_176 ) {
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_2 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) )
F_7 ( V_32 L_141
L_142 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_90 (
struct V_7 * V_8 ,
int type ,
int V_266 ,
T_2 V_258 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
int V_20 = 0 ;
switch ( type ) {
case V_73 :
case V_74 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_20 = F_89 ( V_8 , V_15 , type , V_266 , V_258 ) ;
break;
default:
F_7 ( V_38 L_143
L_144 , type ) ;
return V_62 ;
}
return V_20 ;
}
static void F_58 (
struct V_14 * V_15 ,
struct V_23 * V_268 ,
struct V_1 * V_2 ,
int V_269 )
{
struct V_144 * V_145 = V_268 -> V_30 -> V_146 ;
char V_171 [ V_172 ] ;
int V_173 ;
memset ( V_171 , 0 , V_172 ) ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
V_15 -> V_111 = NULL ;
F_7 ( V_32 L_145
L_140 ,
V_145 -> F_9 () , ( V_269 ) ? L_146 : L_147 ,
F_21 ( V_2 -> V_53 ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_7 ( V_32 L_148 ,
V_145 -> F_9 () , V_268 -> V_36 ,
( V_173 ) ? & V_171 [ 0 ] : L_22 ) ;
V_2 -> V_52 = V_2 -> V_53 = V_2 -> V_163 = 0 ;
}
static int F_91 (
struct V_7 * V_8 ,
int type ,
int V_266 ,
T_2 V_258 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_134 * V_134 = F_10 ( V_8 ) ;
struct V_1 * V_2 , * V_261 , * V_52 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
int V_20 , V_67 = 0 ;
if ( ! ( V_19 ) || ! ( V_134 ) ) {
F_7 ( V_38 L_98 ) ;
return V_224 ;
}
V_2 = F_15 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! ( V_2 ) ) {
F_7 ( V_38 L_129
L_149 ) ;
return V_224 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( ! ( V_52 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_264 ;
}
if ( ( V_52 -> V_53 == V_56 ) ||
( V_52 -> V_53 == V_57 ) )
V_67 = 1 ;
if ( ( V_67 == 0 ) && ( V_52 != V_2 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_264 ;
}
if ( V_258 != V_2 -> V_112 ) {
F_7 ( V_38 L_150
L_132
L_109 , V_258 , V_2 -> V_112 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
if ( ( V_52 -> V_53 != type ) ||
( V_52 -> V_163 != V_266 ) ) {
struct V_23 * V_188 = V_52 -> V_113 ;
F_7 ( V_38 L_151
L_152
L_153
L_136 ,
F_88 ( V_8 ) -> F_9 () ,
V_19 -> V_23 -> V_36 ,
F_8 ( V_188 -> V_30 ) -> F_9 () ,
V_52 -> V_113 -> V_36 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
F_58 ( V_15 , V_19 -> V_23 ,
V_2 , 1 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( ( type != V_54 ) &&
( type != V_55 ) &&
( type != V_56 ) &&
( type != V_57 ) ) {
goto V_270;
}
F_4 ( & V_45 -> V_58 ) ;
F_37 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_261 == V_2 )
continue;
F_87 ( V_261 -> V_113 ,
V_261 -> V_132 ,
0x2A , V_265 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
V_270:
if ( V_45 -> V_176 ) {
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_2 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) )
F_7 ( L_154 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_92 (
struct V_7 * V_8 ,
T_2 V_258 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_113 ;
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
struct V_1 * V_2 , * V_148 , * V_271 , * V_52 ;
T_1 V_132 = 0 ;
int V_272 = 0 ;
V_271 = F_15 ( F_72 ( V_8 ) ,
V_19 -> V_23 , V_19 ) ;
if ( ! ( V_271 ) ) {
F_7 ( V_38 L_129
L_155 ) ;
return V_224 ;
}
if ( V_258 != V_271 -> V_112 ) {
F_7 ( V_38 L_106
L_107
L_108
L_109 , V_258 , V_271 -> V_112 ) ;
F_16 ( V_271 ) ;
return V_40 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( V_52 ) {
struct V_23 * V_188 = V_52 -> V_113 ;
F_58 ( V_15 , V_188 ,
V_52 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
V_113 = V_2 -> V_113 ;
V_132 = V_2 -> V_132 ;
F_59 ( V_15 , V_2 , NULL ,
V_272 ) ;
if ( ! ( V_272 ) )
F_87 ( V_113 , V_132 ,
0x2A , V_273 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
F_7 ( V_32 L_156 ,
F_88 ( V_8 ) -> F_9 () ) ;
if ( V_45 -> V_176 ) {
F_85 ( F_72 ( V_8 ) , NULL , 0 ) ;
F_7 ( V_32 L_141
L_157 ) ;
}
F_22 ( V_15 ) ;
return 0 ;
}
static void F_93 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_185 * V_186 ,
int type ,
int V_266 ,
int abort )
{
struct V_23 * V_115 = V_2 -> V_113 ;
struct V_144 * V_145 = V_115 -> V_30 -> V_146 ;
char V_171 [ V_172 ] ;
int V_173 ;
memset ( V_171 , 0 , V_172 ) ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
if ( V_15 -> V_111 )
F_58 ( V_15 , V_115 ,
V_15 -> V_111 , 0 ) ;
V_15 -> V_111 = V_2 ;
V_2 -> V_52 = 1 ;
V_2 -> V_53 = type ;
V_2 -> V_163 = V_266 ;
F_7 ( V_32 L_158
L_140 ,
V_145 -> F_9 () , ( abort ) ? L_159 : L_22 ,
F_21 ( type ) ,
( V_2 -> V_135 ) ? 1 : 0 ) ;
F_7 ( V_32 L_160 ,
V_145 -> F_9 () , ( abort ) ? L_159 : L_22 ,
V_115 -> V_36 , ( V_173 ) ? & V_171 [ 0 ] : L_22 ) ;
if ( V_186 )
F_43 ( & V_2 -> V_126 ,
V_186 ) ;
}
static void F_94 (
struct V_185 * V_186 ,
struct V_1 * V_274 )
{
struct V_1 * V_2 , * V_148 ;
F_33 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_44 ( & V_2 -> V_126 ) ;
if ( V_274 == V_2 )
continue;
if ( V_2 -> V_52 ) {
F_7 ( V_263 L_161 ) ;
continue;
}
V_2 -> V_131 = NULL ;
V_2 -> V_113 = NULL ;
F_62 ( V_2 -> V_123 ) ;
F_28 ( V_121 , V_2 ) ;
}
}
int F_95 (
struct V_185 * V_186 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_148 ;
F_33 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
if ( V_2 -> V_112 == V_8 -> V_112 )
return 0 ;
}
return 1 ;
}
static int F_96 (
struct V_7 * V_8 ,
int type ,
int V_266 ,
T_2 V_258 ,
T_2 V_118 ,
int abort )
{
struct V_14 * V_15 = F_72 ( V_8 ) ;
struct V_63 * V_34 ;
struct V_23 * V_113 ;
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_185 V_186 ;
struct V_1 * V_2 , * V_148 , * V_271 , * V_52 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
T_1 V_132 = 0 ;
int V_67 = 0 , V_272 = 0 , V_275 = 0 ;
int V_276 = 0 , V_277 = 0 , V_20 ;
if ( ! ( V_19 ) )
return V_224 ;
V_34 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
V_271 = F_15 ( F_72 ( V_8 ) , V_19 -> V_23 ,
V_19 ) ;
if ( ! ( V_271 ) ) {
F_7 ( V_38 L_129
L_162 ,
( abort ) ? L_159 : L_22 ) ;
return V_40 ;
}
if ( V_271 -> V_112 != V_258 ) {
F_16 ( V_271 ) ;
return V_40 ;
}
if ( V_266 != V_267 ) {
F_7 ( V_38 L_133 , V_266 ) ;
F_16 ( V_271 ) ;
return V_227 ;
}
F_29 ( & V_186 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( V_52 &&
( ( V_52 -> V_53 == V_56 ) ||
( V_52 -> V_53 == V_57 ) ) )
V_67 = 1 ;
if ( ! ( V_67 ) && ! ( V_118 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_271 ) ;
return V_227 ;
}
if ( ! ( V_52 ) || ( V_52 -> V_112 != V_118 ) ) {
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! ( V_67 ) ) {
if ( V_2 -> V_112 != V_118 )
continue;
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
V_113 = V_2 -> V_113 ;
V_132 = V_2 -> V_132 ;
F_59 ( V_15 , V_2 ,
( abort ) ? & V_186 :
NULL , V_272 ) ;
V_275 ++ ;
} else {
if ( ( V_118 ) &&
( V_2 -> V_112 != V_118 ) )
continue;
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
V_113 = V_2 -> V_113 ;
V_132 = V_2 -> V_132 ;
F_59 ( V_15 , V_2 ,
( abort ) ? & V_186 :
NULL , 0 ) ;
V_275 ++ ;
}
if ( ! ( V_272 ) )
F_87 ( V_113 ,
V_132 , 0x2A ,
V_273 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
if ( ! ( V_275 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_16 ( V_271 ) ;
return V_40 ;
}
if ( V_52 && V_67 && ! ( V_118 ) ) {
F_93 ( V_15 , V_271 ,
( abort ) ? & V_186 : NULL ,
type , V_266 , abort ) ;
if ( abort )
F_94 (
& V_186 , V_271 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( V_45 -> V_176 ) {
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_271 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) )
F_7 ( V_32 L_163
L_164 , ( abort ) ?
L_159 : L_22 ) ;
}
F_16 ( V_271 ) ;
F_22 ( F_72 ( V_8 ) ) ;
return 0 ;
}
V_276 = V_52 -> V_53 ;
V_277 = V_52 -> V_163 ;
if ( V_271 != V_52 )
F_58 ( V_15 ,
V_52 -> V_113 ,
V_15 -> V_111 , 0 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
if ( V_2 -> V_112 != V_118 )
continue;
V_113 = V_2 -> V_113 ;
V_132 = V_2 -> V_132 ;
F_59 ( V_15 , V_2 ,
( abort ) ? & V_186 : NULL ,
V_272 ) ;
F_87 ( V_113 , V_132 , 0x2A ,
V_273 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
F_93 ( V_15 , V_271 ,
( abort ) ? & V_186 : NULL ,
type , V_266 , abort ) ;
if ( ( V_276 != type ) || ( V_277 != V_266 ) ) {
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_272 = ( V_271 == V_2 ) ? 1 : 0 ;
if ( V_272 )
continue;
F_87 ( V_2 -> V_113 ,
V_2 -> V_132 , 0x2A ,
V_265 ) ;
}
F_5 ( & V_45 -> V_58 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( abort ) {
F_97 ( V_15 , NULL , & V_186 , V_8 ) ;
F_94 ( & V_186 ,
V_271 ) ;
}
if ( V_45 -> V_176 ) {
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_271 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) )
F_7 ( L_165
L_166 , ( abort ) ? L_159 : L_22 ) ;
}
F_16 ( V_271 ) ;
F_22 ( F_72 ( V_8 ) ) ;
return 0 ;
}
static int F_98 (
struct V_7 * V_8 ,
int type ,
int V_266 ,
T_2 V_258 ,
T_2 V_118 ,
int abort )
{
int V_20 = 0 ;
switch ( type ) {
case V_73 :
case V_74 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_20 = F_96 ( V_8 , type , V_266 ,
V_258 , V_118 , abort ) ;
break;
default:
F_7 ( V_38 L_167
L_168 , ( abort ) ? L_159 : L_22 , type ) ;
return V_62 ;
}
return V_20 ;
}
static int F_99 (
struct V_7 * V_8 ,
T_2 V_258 ,
T_2 V_118 ,
int V_120 ,
int V_278 )
{
struct V_17 * V_19 = F_19 ( V_8 ) ;
struct V_14 * V_15 = F_72 ( V_8 ) ;
struct V_63 * V_34 , * V_202 = NULL ;
struct V_134 * V_134 = F_10 ( V_8 ) ;
struct V_23 * V_188 , * V_113 , * V_201 = NULL ;
struct V_141 * V_141 ;
struct V_28 * V_30 , * V_279 = NULL ;
struct V_144 * V_280 = NULL , * V_281 ;
struct V_1 * V_2 , * V_52 , * V_204 ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
unsigned char * V_282 ;
char * V_218 = NULL , V_219 [ 64 ] , V_171 [ V_172 ] ;
T_1 V_221 , V_283 ;
int V_284 = 0 , type , V_266 , V_20 , V_285 , V_173 ;
unsigned short V_286 ;
unsigned char V_216 ;
if ( ! ( V_19 ) || ! ( V_134 ) ) {
F_7 ( V_38 L_98 ) ;
return V_224 ;
}
memset ( V_219 , 0 , 64 ) ;
memset ( V_171 , 0 , V_172 ) ;
V_30 = V_19 -> V_30 ;
V_281 = F_8 ( V_30 ) ;
V_34 = & V_19 -> V_23 -> V_71 [ V_8 -> V_72 ] ;
V_2 = F_15 ( F_72 ( V_8 ) , V_19 -> V_23 ,
V_19 ) ;
if ( ! ( V_2 ) ) {
F_7 ( V_38 L_169
L_170 ) ;
return V_224 ;
}
if ( V_258 != V_2 -> V_112 ) {
F_7 ( V_263 L_171
L_172
L_173 , V_258 , V_2 -> V_112 ) ;
F_16 ( V_2 ) ;
return V_40 ;
}
if ( ! ( V_118 ) ) {
F_7 ( V_263 L_174
L_175 ) ;
F_16 ( V_2 ) ;
return V_227 ;
}
V_286 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_286 |= V_3 [ 19 ] & 0xff ;
V_221 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_221 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_221 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_221 |= V_3 [ 23 ] & 0xff ;
if ( ( V_221 + 24 ) != V_8 -> V_226 ) {
F_7 ( V_38 L_176
L_56 , V_221 ,
V_8 -> V_226 ) ;
F_16 ( V_2 ) ;
return V_227 ;
}
F_4 ( & V_15 -> V_150 ) ;
F_37 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_141 -> V_231 != V_286 )
continue;
V_279 = V_141 -> V_228 ;
if ( ! ( V_279 ) )
continue;
V_280 = F_8 ( V_279 ) ;
if ( ! ( V_280 ) )
continue;
F_34 ( & V_279 -> V_192 ) ;
F_35 () ;
F_5 ( & V_15 -> V_150 ) ;
V_20 = F_65 ( V_279 ) ;
if ( V_20 != 0 ) {
F_7 ( V_38 L_177
L_178 ) ;
F_40 ( & V_279 -> V_192 ) ;
F_41 () ;
F_16 ( V_2 ) ;
return V_224 ;
}
F_4 ( & V_15 -> V_150 ) ;
break;
}
F_5 ( & V_15 -> V_150 ) ;
if ( ! ( V_279 ) || ( ! V_280 ) ) {
F_7 ( V_38 L_179
L_180
L_181 , V_286 ) ;
F_16 ( V_2 ) ;
return V_227 ;
}
V_216 = ( V_3 [ 24 ] & 0x0f ) ;
#if 0
printk("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
#endif
if ( V_216 != V_280 -> V_229 ( V_279 ) ) {
F_7 ( V_38 L_171
L_182
L_183 , V_216 ,
V_280 -> V_229 ( V_279 ) ,
V_280 -> F_9 () ) ;
V_20 = V_227 ;
goto V_156;
}
if ( V_280 -> V_230 == NULL ) {
F_7 ( V_38 L_184
L_185
L_186 ) ;
V_20 = V_224 ;
goto V_156;
}
V_282 = V_280 -> V_230 ( V_279 ,
( const char * ) & V_3 [ 24 ] , & V_283 , & V_218 ) ;
if ( ! ( V_282 ) ) {
F_7 ( V_38 L_179
L_187 ) ;
V_20 = V_227 ;
goto V_156;
}
F_7 ( V_32 L_188
L_189 , V_280 -> F_9 () , ( V_218 != NULL ) ?
L_190 : L_191 , V_282 , ( V_218 != NULL ) ?
V_218 : L_22 ) ;
V_113 = V_2 -> V_113 ;
V_285 = ( ! strcmp ( V_282 ,
V_113 -> V_36 ) ) ? 1 : 0 ;
if ( ! ( V_285 ) )
goto V_287;
if ( ! ( V_218 ) || ! ( V_2 -> V_5 ) ) {
F_7 ( V_38 L_192
L_193 , V_282 ,
V_113 -> V_36 ) ;
V_20 = V_227 ;
goto V_156;
}
if ( ! ( strcmp ( V_218 , V_2 -> V_6 ) ) ) {
F_7 ( V_38 L_194
L_195 ,
V_282 , V_218 , V_113 -> V_36 ,
V_2 -> V_6 ) ;
V_20 = V_227 ;
goto V_156;
}
V_287:
F_36 ( & V_279 -> V_232 ) ;
V_201 = F_73 ( V_279 ,
V_282 ) ;
if ( V_201 ) {
F_34 ( & V_201 -> V_195 ) ;
F_35 () ;
}
F_38 ( & V_279 -> V_232 ) ;
if ( ! ( V_201 ) ) {
F_7 ( V_38 L_196
L_197 , V_280 -> F_9 () ,
V_282 ) ;
V_20 = V_227 ;
goto V_156;
}
V_20 = F_69 ( V_201 ) ;
if ( V_20 != 0 ) {
F_7 ( V_38 L_198
L_199 ) ;
F_40 ( & V_201 -> V_195 ) ;
F_41 () ;
V_201 = NULL ;
V_20 = V_224 ;
goto V_156;
}
#if 0
printk(KERN_INFO "SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
#endif
V_202 = F_74 ( V_201 , V_286 ) ;
if ( ! ( V_202 ) ) {
F_7 ( V_38 L_200
L_181 , V_280 -> F_9 () , V_286 ) ;
V_20 = V_227 ;
goto V_156;
}
V_20 = F_39 ( V_202 ) ;
if ( V_20 < 0 ) {
F_7 ( V_38 L_201 ) ;
F_40 ( & V_202 -> V_155 ) ;
F_41 () ;
V_202 = NULL ;
V_20 = V_224 ;
goto V_156;
}
#if 0
printk(KERN_INFO "SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
#endif
F_4 ( & V_15 -> V_21 ) ;
V_52 = V_15 -> V_111 ;
if ( ! ( V_52 ) ) {
F_7 ( V_263 L_202
L_203 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_62 ;
goto V_156;
}
if ( V_52 != V_2 ) {
F_7 ( V_263 L_204
L_205 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_40 ;
goto V_156;
}
if ( ( V_52 -> V_53 == V_56 ) ||
( V_52 -> V_53 == V_57 ) ) {
F_7 ( V_263 L_206
L_207 ,
F_21 ( V_52 -> V_53 ) ) ;
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_40 ;
goto V_156;
}
V_188 = V_52 -> V_113 ;
type = V_52 -> V_53 ;
V_266 = V_52 -> V_53 ;
V_204 = F_55 ( V_15 , V_201 ,
V_218 ) ;
if ( ! ( V_204 ) ) {
V_20 = F_54 ( F_72 ( V_8 ) ,
V_201 , V_202 , V_218 ,
V_118 , 0 , V_120 , 2 , 1 ) ;
if ( V_20 != 0 ) {
F_5 ( & V_15 -> V_21 ) ;
V_20 = V_227 ;
goto V_156;
}
V_204 = F_55 ( V_15 , V_201 ,
V_218 ) ;
V_284 = 1 ;
}
F_58 ( V_15 , V_188 ,
V_15 -> V_111 , 0 ) ;
V_15 -> V_111 = V_204 ;
V_204 -> V_52 = 1 ;
V_204 -> V_53 = type ;
V_2 -> V_163 = V_266 ;
V_173 = F_1 ( V_2 , & V_171 [ 0 ] ,
V_172 ) ;
if ( ! ( V_284 ) )
V_204 -> V_180 = V_45 -> V_110 ++ ;
F_5 ( & V_15 -> V_21 ) ;
F_7 ( V_32 L_208
L_209
L_210 , V_280 -> F_9 () ,
F_21 ( type ) , V_286 ,
V_204 -> V_180 ) ;
F_7 ( V_32 L_211
L_212 ,
V_281 -> F_9 () , V_113 -> V_36 ,
( V_173 ) ? & V_171 [ 0 ] : L_22 , V_280 -> F_9 () ,
V_201 -> V_36 , ( V_218 != NULL ) ?
V_218 : L_22 ) ;
F_42 ( V_202 ) ;
F_70 ( V_201 ) ;
F_67 ( V_279 ) ;
if ( V_278 ) {
F_4 ( & V_45 -> V_58 ) ;
F_59 ( V_15 , V_2 , NULL , 1 ) ;
F_5 ( & V_45 -> V_58 ) ;
} else
F_16 ( V_2 ) ;
if ( ! ( V_120 ) ) {
V_45 -> V_176 = 0 ;
F_85 ( F_72 ( V_8 ) , NULL , 0 ) ;
F_7 ( L_103
L_213 ) ;
} else {
V_45 -> V_176 = 1 ;
V_20 = F_85 ( F_72 ( V_8 ) ,
& V_204 -> V_123 [ 0 ] ,
V_45 -> V_124 ) ;
if ( ! ( V_20 ) )
F_7 ( L_214
L_213 ) ;
}
F_16 ( V_204 ) ;
return 0 ;
V_156:
if ( V_202 )
F_42 ( V_202 ) ;
if ( V_201 )
F_70 ( V_201 ) ;
F_67 ( V_279 ) ;
F_16 ( V_2 ) ;
return V_20 ;
}
static unsigned long long F_100 ( unsigned char * V_9 )
{
unsigned int V_288 , V_289 ;
V_288 = ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_289 = ( V_9 [ 4 ] << 24 ) | ( V_9 [ 5 ] << 16 ) | ( V_9 [ 6 ] << 8 ) | V_9 [ 7 ] ;
return ( ( unsigned long long ) V_289 ) | ( unsigned long long ) V_288 << 32 ;
}
static int F_101 ( struct V_7 * V_8 , unsigned char * V_9 )
{
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
T_2 V_258 , V_118 ;
int V_290 , V_266 , type , V_120 ;
int V_259 = 0 , V_119 = 0 , V_278 = 0 ;
if ( ! ( F_19 ( V_8 ) ) )
return V_224 ;
if ( V_8 -> V_226 < 24 ) {
F_7 ( V_263 L_215
L_216 , V_8 -> V_226 ) ;
return V_227 ;
}
V_290 = ( V_9 [ 1 ] & 0x1f ) ;
V_266 = ( V_9 [ 2 ] & 0xf0 ) ;
type = ( V_9 [ 2 ] & 0x0f ) ;
V_258 = F_100 ( & V_3 [ 0 ] ) ;
V_118 = F_100 ( & V_3 [ 8 ] ) ;
if ( V_290 != V_88 ) {
V_259 = ( V_3 [ 20 ] & 0x08 ) ;
V_119 = ( V_3 [ 20 ] & 0x04 ) ;
V_120 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_120 = ( V_3 [ 17 ] & 0x01 ) ;
V_278 = ( V_3 [ 17 ] & 0x02 ) ;
}
if ( V_259 && ( ( V_9 [ 1 ] & 0x1f ) != V_86 ) )
return V_227 ;
if ( ! ( V_259 ) && ( ( V_9 [ 1 ] & 0x1f ) != V_88 ) &&
( V_8 -> V_226 != 24 ) ) {
F_7 ( V_263 L_217
L_218 , V_8 -> V_226 ) ;
return V_227 ;
}
switch ( V_290 ) {
case V_86 :
return F_86 ( V_8 ,
V_258 , V_118 , V_120 , V_119 , V_259 , 0 ) ;
case V_89 :
return F_90 ( V_8 ,
type , V_266 , V_258 ) ;
case V_90 :
return F_91 ( V_8 ,
type , V_266 , V_258 ) ;
case V_83 :
return F_92 ( V_8 , V_258 ) ;
case V_84 :
return F_98 ( V_8 , type , V_266 ,
V_258 , V_118 , 0 ) ;
case V_85 :
return F_98 ( V_8 , type , V_266 ,
V_258 , V_118 , 1 ) ;
case V_87 :
return F_86 ( V_8 ,
0 , V_118 , V_120 , V_119 , V_259 , 1 ) ;
case V_88 :
return F_99 ( V_8 , V_258 ,
V_118 , V_120 , V_278 ) ;
default:
F_7 ( V_38 L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
return V_62 ;
}
return V_62 ;
}
static int F_102 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = F_72 ( V_8 ) ;
struct V_41 * V_42 = F_23 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
T_1 V_291 = 0 , V_292 = 8 ;
if ( V_8 -> V_226 < 8 ) {
F_7 ( V_38 L_219
L_220 , V_8 -> V_226 ) ;
return V_62 ;
}
V_3 [ 0 ] = ( ( F_14 ( V_42 ) -> V_110 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( F_14 ( V_42 ) -> V_110 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( F_14 ( V_42 ) -> V_110 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( F_14 ( V_42 ) -> V_110 & 0xff ) ;
F_4 ( & F_14 ( V_42 ) -> V_58 ) ;
F_37 (pr_reg, &T10_RES(su_dev)->registration_list,
pr_reg_list) {
if ( ( V_291 + 8 ) > ( V_8 -> V_226 - 8 ) )
break;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 56 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 48 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 40 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 32 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 24 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 16 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 8 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( V_2 -> V_112 & 0xff ) ;
V_291 += 8 ;
}
F_5 ( & F_14 ( V_42 ) -> V_58 ) ;
V_3 [ 4 ] = ( ( V_291 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_291 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_291 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_291 & 0xff ) ;
return 0 ;
}
static int F_103 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = F_72 ( V_8 ) ;
struct V_41 * V_42 = F_23 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
T_2 V_112 ;
T_1 V_291 = 16 ;
if ( V_8 -> V_226 < 8 ) {
F_7 ( V_38 L_221
L_220 , V_8 -> V_226 ) ;
return V_62 ;
}
V_3 [ 0 ] = ( ( F_14 ( V_42 ) -> V_110 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( F_14 ( V_42 ) -> V_110 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( F_14 ( V_42 ) -> V_110 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( F_14 ( V_42 ) -> V_110 & 0xff ) ;
F_4 ( & V_16 -> V_21 ) ;
V_2 = V_16 -> V_111 ;
if ( ( V_2 ) ) {
V_3 [ 4 ] = ( ( V_291 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_291 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_291 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_291 & 0xff ) ;
if ( V_8 -> V_226 < 22 ) {
F_5 ( & V_16 -> V_21 ) ;
return 0 ;
}
if ( ( V_2 -> V_53 == V_56 ) ||
( V_2 -> V_53 == V_57 ) )
V_112 = 0 ;
else
V_112 = V_2 -> V_112 ;
V_3 [ 8 ] = ( ( V_112 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_112 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_112 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_112 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_112 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_112 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_112 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_112 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_163 & 0xf0 ) |
( V_2 -> V_53 & 0x0f ) ;
}
F_5 ( & V_16 -> V_21 ) ;
return 0 ;
}
static int F_104 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_72 ( V_8 ) ;
struct V_44 * V_45 = & F_23 ( V_15 ) -> V_46 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
T_3 V_291 = 8 ;
if ( V_8 -> V_226 < 6 ) {
F_7 ( V_38 L_222
L_223 , V_8 -> V_226 ) ;
return V_62 ;
}
V_3 [ 0 ] = ( ( V_291 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_291 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_45 -> V_176 )
V_3 [ 3 ] |= 0x01 ;
V_3 [ 4 ] |= 0x80 ;
V_3 [ 4 ] |= 0x40 ;
V_3 [ 4 ] |= 0x20 ;
V_3 [ 4 ] |= 0x08 ;
V_3 [ 4 ] |= 0x02 ;
V_3 [ 5 ] |= 0x01 ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = F_72 ( V_8 ) ;
struct V_23 * V_268 ;
struct V_41 * V_42 = F_23 ( V_16 ) ;
struct V_28 * V_30 ;
struct V_1 * V_2 , * V_148 ;
struct V_44 * V_45 = & F_23 ( V_16 ) -> V_46 ;
unsigned char * V_3 = ( unsigned char * ) F_12 ( V_8 ) -> V_213 ;
T_1 V_293 = 0 , V_291 = 0 , V_294 , V_295 ;
T_1 V_292 = 8 ;
int V_296 = 0 ;
if ( V_8 -> V_226 < 8 ) {
F_7 ( V_38 L_224
L_220 , V_8 -> V_226 ) ;
return V_62 ;
}
V_3 [ 0 ] = ( ( F_14 ( V_42 ) -> V_110 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( F_14 ( V_42 ) -> V_110 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( F_14 ( V_42 ) -> V_110 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( F_14 ( V_42 ) -> V_110 & 0xff ) ;
F_4 ( & V_45 -> V_58 ) ;
F_33 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_268 = V_2 -> V_113 ;
V_30 = V_2 -> V_113 -> V_30 ;
V_293 = 0 ;
F_34 ( & V_2 -> V_130 ) ;
F_35 () ;
F_5 ( & V_45 -> V_58 ) ;
V_295 = F_8 ( V_30 ) -> F_106 (
V_30 , V_268 , V_2 , & V_296 ) ;
if ( ( V_295 + V_291 ) > V_8 -> V_226 ) {
F_7 ( V_263 L_225
L_226 , V_8 -> V_226 ) ;
F_4 ( & V_45 -> V_58 ) ;
F_40 ( & V_2 -> V_130 ) ;
F_41 () ;
break;
}
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 56 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 48 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 40 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 32 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 24 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 16 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_2 -> V_112 >> 8 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( V_2 -> V_112 & 0xff ) ;
V_292 += 4 ;
if ( V_2 -> V_135 )
V_3 [ V_292 ] = 0x02 ;
if ( V_2 -> V_52 ) {
V_3 [ V_292 ++ ] |= 0x01 ;
V_3 [ V_292 ++ ] = ( V_2 -> V_163 & 0xf0 ) |
( V_2 -> V_53 & 0x0f ) ;
} else
V_292 += 2 ;
V_292 += 4 ;
if ( ! ( V_2 -> V_135 ) ) {
struct V_141 * V_142 = V_2 -> V_137 -> V_238 ;
V_3 [ V_292 ++ ] = ( ( V_142 -> V_231 >> 8 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( V_142 -> V_231 & 0xff ) ;
} else
V_292 += 2 ;
V_294 = F_8 ( V_30 ) -> F_107 ( V_30 ,
V_268 , V_2 , & V_296 , & V_3 [ V_292 + 4 ] ) ;
F_4 ( & V_45 -> V_58 ) ;
F_40 ( & V_2 -> V_130 ) ;
F_41 () ;
V_3 [ V_292 ++ ] = ( ( V_294 >> 24 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_294 >> 16 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( ( V_294 >> 8 ) & 0xff ) ;
V_3 [ V_292 ++ ] = ( V_294 & 0xff ) ;
V_293 = ( 24 + V_294 ) ;
V_292 += V_294 ;
V_291 += V_293 ;
}
F_5 ( & V_45 -> V_58 ) ;
V_3 [ 4 ] = ( ( V_291 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_291 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_291 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_291 & 0xff ) ;
return 0 ;
}
static int F_108 ( struct V_7 * V_8 , unsigned char * V_9 )
{
switch ( V_9 [ 1 ] & 0x1f ) {
case V_297 :
return F_102 ( V_8 ) ;
case V_298 :
return F_103 ( V_8 ) ;
case V_299 :
return F_104 ( V_8 ) ;
case V_300 :
return F_105 ( V_8 ) ;
default:
F_7 ( V_38 L_227
L_16 , V_9 [ 1 ] & 0x1f ) ;
return V_62 ;
}
}
int F_109 ( struct V_7 * V_8 )
{
unsigned char * V_9 = & F_12 ( V_8 ) -> V_37 [ 0 ] ;
struct V_14 * V_15 = V_8 -> V_16 ;
if ( V_15 -> V_24 & V_31 ) {
F_7 ( V_38 L_228
L_229
L_230 ) ;
return V_40 ;
}
return ( V_9 [ 0 ] == V_82 ) ?
F_101 ( V_8 , V_9 ) :
F_108 ( V_8 , V_9 ) ;
}
static int F_110 ( struct V_7 * V_8 , T_1 * V_53 )
{
return 0 ;
}
static int F_111 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
return 0 ;
}
int F_112 ( struct V_14 * V_15 , int V_301 )
{
struct V_41 * V_42 = V_15 -> V_43 ;
struct V_44 * V_302 = & V_42 -> V_46 ;
if ( ( ( F_53 ( V_15 ) -> V_303 == V_304 ) &&
! ( F_56 ( V_15 ) -> V_305 ) ) || V_301 ) {
V_302 -> V_48 = V_306 ;
V_302 -> V_307 . V_308 = & F_110 ;
V_302 -> V_307 . V_309 = & F_111 ;
F_7 ( V_32 L_231
L_232 , F_53 ( V_15 ) -> V_179 ) ;
return 0 ;
}
if ( F_53 ( V_15 ) -> F_113 ( V_15 ) >= V_310 ) {
V_302 -> V_48 = V_49 ;
V_302 -> V_307 . V_308 = & F_24 ;
V_302 -> V_307 . V_309 = & F_18 ;
F_7 ( V_32 L_233
L_232 , F_53 ( V_15 ) -> V_179 ) ;
} else {
V_302 -> V_48 = V_311 ;
V_302 -> V_307 . V_308 = & F_3 ;
V_302 -> V_307 . V_309 =
& F_2 ;
F_7 ( V_32 L_234 ,
F_53 ( V_15 ) -> V_179 ) ;
}
return 0 ;
}
