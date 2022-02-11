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
static int F_6 ( struct V_7 * V_8 , int * V_20 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_29 * V_30 = V_8 -> V_16 -> V_31 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_30 -> V_34 ;
int V_35 = ( V_30 -> V_34 . V_36 == V_37 ) ;
int V_38 = 0 ;
if ( ! V_35 )
return false ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( V_2 ) {
if ( V_2 -> V_39 ) {
F_8 ( V_2 ) ;
* V_20 = 0 ;
return false ;
}
if ( ( V_2 -> V_40 == V_41 ) ||
( V_2 -> V_40 == V_42 ) ||
( V_2 -> V_40 == V_43 ) ||
( V_2 -> V_40 == V_44 ) ) {
F_8 ( V_2 ) ;
* V_20 = 0 ;
return true ;
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
return true ;
}
return false ;
}
int F_11 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_52 * V_53 = V_18 -> V_54 ;
int V_20 = 0 ;
if ( ! V_18 || ! V_53 )
goto V_55;
if ( F_6 ( V_8 , & V_20 ) )
goto V_55;
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_22 || ! V_18 )
goto V_56;
if ( V_15 -> V_22 != V_18 -> V_23 )
goto V_56;
V_15 -> V_22 = NULL ;
V_15 -> V_25 &= ~ V_57 ;
if ( V_15 -> V_25 & V_26 ) {
V_15 -> V_27 = 0 ;
V_15 -> V_25 &= ~ V_26 ;
}
F_12 ( L_5
L_6 , V_53 -> V_58 -> V_59 () ,
V_8 -> V_60 -> V_61 , V_8 -> V_62 -> V_63 ,
V_18 -> V_23 -> V_64 ) ;
V_56:
F_5 ( & V_15 -> V_21 ) ;
V_55:
if ( ! V_20 ) {
V_50 -> V_65 = V_66 ;
F_13 ( V_50 , 1 ) ;
}
return V_20 ;
}
int F_14 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_52 * V_53 = V_18 -> V_54 ;
int V_20 = 0 ;
if ( ( V_8 -> V_67 [ 1 ] & 0x01 ) &&
( V_8 -> V_67 [ 1 ] & 0x02 ) ) {
F_10 ( L_7
L_8 ) ;
V_8 -> V_47 = V_68 ;
V_20 = - V_24 ;
goto V_55;
}
if ( ! V_18 || ! V_53 )
goto V_55;
if ( F_6 ( V_8 , & V_20 ) )
goto V_55;
V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_22 &&
( V_15 -> V_22 != V_18 -> V_23 ) ) {
F_10 ( L_9 ,
V_53 -> V_58 -> V_59 () ) ;
F_10 ( L_10 ,
V_8 -> V_60 -> V_61 ,
V_15 -> V_22 -> V_64 ) ;
F_10 ( L_11
L_12 , V_8 -> V_60 -> V_61 ,
V_8 -> V_62 -> V_63 ,
V_18 -> V_23 -> V_64 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_56;
}
V_15 -> V_22 = V_18 -> V_23 ;
V_15 -> V_25 |= V_57 ;
if ( V_18 -> V_28 != 0 ) {
V_15 -> V_27 = V_18 -> V_28 ;
V_15 -> V_25 |= V_26 ;
}
F_12 ( L_13
L_14 , V_53 -> V_58 -> V_59 () ,
V_8 -> V_60 -> V_61 , V_8 -> V_62 -> V_63 ,
V_18 -> V_23 -> V_64 ) ;
V_56:
F_5 ( & V_15 -> V_21 ) ;
V_55:
if ( ! V_20 ) {
V_50 -> V_65 = V_66 ;
F_13 ( V_50 , 1 ) ;
}
return V_20 ;
}
static int F_15 (
struct V_7 * V_8 ,
unsigned char * V_9 ,
T_1 V_10 )
{
struct V_69 * V_62 ;
struct V_17 * V_19 = V_8 -> V_19 ;
int V_70 = 0 , V_71 ;
int V_72 = 0 , V_20 = 1 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 = 0 ;
int V_76 = 0 ;
if ( V_8 -> V_16 -> V_25 & V_57 )
return F_2 ( V_8 ,
V_9 , V_10 ) ;
V_62 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
V_71 = ( V_10 & 0x80000000 ) ;
if ( V_71 )
V_10 &= ~ 0x80000000 ;
switch ( V_10 ) {
case V_79 :
V_75 = 1 ;
case V_80 :
if ( ( V_62 -> V_81 ) && ! ( V_71 ) )
V_72 = 1 ;
break;
case V_41 :
V_75 = 1 ;
case V_42 :
V_74 = 1 ;
if ( ( V_62 -> V_81 ) && ! ( V_71 ) )
V_72 = 1 ;
break;
case V_43 :
V_75 = 1 ;
case V_44 :
V_73 = 1 ;
if ( ( V_62 -> V_81 ) && ! ( V_71 ) )
V_72 = 1 ;
break;
default:
return - V_24 ;
}
switch ( V_9 [ 0 ] ) {
case V_82 :
if ( V_72 )
return 0 ;
V_20 = ( V_75 ) ? 0 : 1 ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
if ( V_76 ) {
V_20 = 1 ;
break;
}
if ( V_72 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_75 ) ? 0 : 1 ;
break;
case V_88 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_89 :
case V_90 :
case V_91 :
V_20 = ( V_72 ) ? 0 : 1 ;
break;
case V_92 :
case V_93 :
V_20 = 0 ;
break;
case V_94 :
case V_95 :
V_20 = 1 ;
break;
case V_96 :
V_20 = ( V_72 ) ? 0 : 1 ;
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
case V_97 :
case V_98 :
V_20 = 0 ;
break;
case V_99 :
V_20 = ( V_76 ) ? 1 : 0 ;
break;
case V_100 :
switch ( V_9 [ 1 ] & 0x1f ) {
case V_101 :
if ( V_72 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_75 ) ? 0 : 1 ;
break;
case V_102 :
case V_103 :
if ( V_76 ) {
V_20 = 1 ;
break;
}
if ( V_72 ) {
V_20 = 0 ;
break;
}
V_20 = ( V_75 ) ? 0 : 1 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_20 = 0 ;
break;
default:
F_10 ( L_17 ,
( V_9 [ 1 ] & 0x1f ) ) ;
return - V_24 ;
}
break;
case V_109 :
case V_110 :
case V_11 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_20 = 0 ;
break;
default:
V_70 = 1 ;
break;
}
if ( ! V_20 && ! V_70 ) {
#if 0
pr_debug("Allowing explict CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return V_20 ;
}
if ( ( V_75 ) && ! ( V_72 ) ) {
if ( V_8 -> V_115 == V_116 ) {
F_12 ( L_18
L_19 ,
F_16 ( V_8 ) ,
V_19 -> V_23 -> V_64 , V_9 [ 0 ] ,
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
} else if ( ( V_74 ) || ( V_73 ) ) {
if ( V_72 ) {
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
( V_72 ) ? L_22 : L_23 ,
V_19 -> V_23 -> V_64 , V_9 [ 0 ] ,
F_17 ( V_10 ) ) ;
return 1 ;
}
static T_1 F_18 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
T_1 V_117 ;
F_4 ( & V_15 -> V_21 ) ;
V_117 = V_30 -> V_34 . V_118 ++ ;
F_5 ( & V_15 -> V_21 ) ;
return V_117 ;
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
if ( V_15 -> V_25 & V_57 )
return F_3 ( V_8 , V_10 ) ;
F_4 ( & V_15 -> V_21 ) ;
if ( ! V_15 -> V_119 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
* V_10 = V_15 -> V_119 -> V_40 ;
V_8 -> V_120 = V_15 -> V_119 -> V_120 ;
if ( V_15 -> V_119 -> V_121 != V_18 -> V_23 ) {
F_5 ( & V_15 -> V_21 ) ;
return - V_24 ;
}
if ( ! V_15 -> V_119 -> V_5 ) {
F_5 ( & V_15 -> V_21 ) ;
return 0 ;
}
V_20 = ( V_15 -> V_119 -> V_122 ==
V_18 -> V_28 ) ? 0 : - V_24 ;
if ( V_20 != 0 )
* V_10 |= 0x80000000 ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static struct V_1 * F_20 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_69 * V_124 ,
unsigned char * V_125 ,
T_2 V_126 ,
int V_127 ,
int V_128 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_129 , V_130 ) ;
if ( ! V_2 ) {
F_10 ( L_24 ) ;
return NULL ;
}
V_2 -> V_131 = F_22 ( V_30 -> V_34 . V_132 ,
V_130 ) ;
if ( ! V_2 -> V_131 ) {
F_10 ( L_25 ) ;
F_23 ( V_129 , V_2 ) ;
return NULL ;
}
F_24 ( & V_2 -> V_133 ) ;
F_24 ( & V_2 -> V_134 ) ;
F_24 ( & V_2 -> V_135 ) ;
F_24 ( & V_2 -> V_136 ) ;
F_24 ( & V_2 -> V_137 ) ;
F_25 ( & V_2 -> V_138 , 0 ) ;
V_2 -> V_121 = V_123 ;
V_2 -> V_139 = V_124 ;
V_2 -> V_140 = V_124 -> V_63 ;
V_2 -> V_141 = V_124 -> V_60 -> V_61 ;
V_2 -> V_120 = V_126 ;
V_2 -> V_142 = V_127 ;
V_2 -> V_143 = V_128 ;
V_2 -> V_144 = V_124 -> V_60 ;
if ( V_125 != NULL ) {
V_2 -> V_122 = F_26 ( V_125 ) ;
snprintf ( V_2 -> V_6 , V_145 , L_26 , V_125 ) ;
V_2 -> V_5 = 1 ;
}
return V_2 ;
}
static struct V_1 * F_27 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_69 * V_124 ,
unsigned char * V_125 ,
T_2 V_126 ,
int V_127 ,
int V_128 )
{
struct V_69 * V_146 ;
struct V_23 * V_147 ;
struct V_148 * V_149 , * V_150 ;
struct V_151 * V_152 = V_123 -> V_54 -> V_58 ;
struct V_1 * V_2 , * V_153 , * V_154 , * V_155 ;
int V_20 ;
V_2 = F_20 ( V_15 , V_123 , V_124 , V_125 ,
V_126 , V_127 , V_128 ) ;
if ( ! V_2 )
return NULL ;
if ( ! V_127 )
return V_2 ;
F_4 ( & V_15 -> V_156 ) ;
F_28 (port, port_tmp, &dev->dev_sep_list, sep_list) {
F_29 ( & V_149 -> V_157 ) ;
F_30 () ;
F_5 ( & V_15 -> V_156 ) ;
F_31 ( & V_149 -> V_158 ) ;
F_32 (deve_tmp, &port->sep_alua_list,
alua_port_list) {
if ( ! V_146 -> V_159 )
continue;
V_147 = V_146 -> V_159 -> V_160 ;
if ( V_123 == V_147 )
continue;
if ( V_152 != V_147 -> V_54 -> V_58 )
continue;
if ( strcmp ( V_123 -> V_64 , V_147 -> V_64 ) )
continue;
F_29 ( & V_146 -> V_161 ) ;
F_30 () ;
F_33 ( & V_149 -> V_158 ) ;
V_20 = F_34 ( V_146 ) ;
if ( V_20 < 0 ) {
F_10 ( L_27
L_28 ) ;
F_35 ( & V_149 -> V_157 ) ;
F_36 () ;
F_35 ( & V_146 -> V_161 ) ;
F_36 () ;
goto V_55;
}
V_153 = F_20 ( V_15 ,
V_147 , V_146 , NULL ,
V_126 , V_127 , V_128 ) ;
if ( ! V_153 ) {
F_35 ( & V_149 -> V_157 ) ;
F_36 () ;
F_35 ( & V_146 -> V_161 ) ;
F_36 () ;
F_37 ( V_146 ) ;
goto V_55;
}
F_38 ( & V_153 -> V_137 ,
& V_2 -> V_136 ) ;
F_31 ( & V_149 -> V_158 ) ;
}
F_33 ( & V_149 -> V_158 ) ;
F_4 ( & V_15 -> V_156 ) ;
F_35 ( & V_149 -> V_157 ) ;
F_36 () ;
}
F_5 ( & V_15 -> V_156 ) ;
return V_2 ;
V_55:
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_154 -> V_137 ) ;
F_37 ( V_154 -> V_139 ) ;
F_23 ( V_129 , V_154 ) ;
}
F_23 ( V_129 , V_2 ) ;
return NULL ;
}
int F_40 (
struct V_32 * V_33 ,
T_2 V_126 ,
unsigned char * V_162 ,
unsigned char * V_125 ,
T_1 V_63 ,
unsigned char * V_163 ,
T_3 V_164 ,
T_1 V_165 ,
int V_166 ,
int V_127 ,
T_4 type )
{
struct V_1 * V_2 ;
if ( ! V_162 || ! V_163 || ! V_126 ) {
F_10 ( L_29 ) ;
return - V_24 ;
}
V_2 = F_21 ( V_129 , V_167 ) ;
if ( ! V_2 ) {
F_10 ( L_24 ) ;
return - V_168 ;
}
V_2 -> V_131 = F_22 ( V_33 -> V_132 , V_167 ) ;
F_24 ( & V_2 -> V_133 ) ;
F_24 ( & V_2 -> V_134 ) ;
F_24 ( & V_2 -> V_135 ) ;
F_24 ( & V_2 -> V_136 ) ;
F_24 ( & V_2 -> V_137 ) ;
F_25 ( & V_2 -> V_138 , 0 ) ;
V_2 -> V_121 = NULL ;
V_2 -> V_139 = NULL ;
V_2 -> V_140 = V_63 ;
V_2 -> V_141 = V_165 ;
V_2 -> V_120 = V_126 ;
V_2 -> V_142 = V_127 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = NULL ;
V_2 -> V_169 = 0 ;
V_2 -> V_40 = type ;
if ( V_125 != NULL ) {
V_2 -> V_122 = F_26 ( V_125 ) ;
snprintf ( V_2 -> V_6 , V_145 , L_26 , V_125 ) ;
V_2 -> V_5 = 1 ;
}
snprintf ( V_2 -> V_170 , V_171 , L_26 , V_162 ) ;
snprintf ( V_2 -> V_172 , V_173 , L_26 , V_163 ) ;
V_2 -> V_174 = V_164 ;
V_2 -> V_39 = V_166 ;
F_38 ( & V_2 -> V_135 , & V_33 -> V_175 ) ;
F_12 ( L_30
L_31 , ( V_166 ) ? L_32 : L_22 ) ;
return 0 ;
}
static void F_41 (
struct V_14 * V_15 ,
struct V_52 * V_53 ,
struct V_23 * V_176 ,
struct V_1 * V_2 )
{
char V_177 [ V_178 ] ;
int V_179 ;
memset ( V_177 , 0 , V_178 ) ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_15 -> V_119 = V_2 ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_33
L_34 ,
V_53 -> V_58 -> V_59 () ,
F_17 ( V_2 -> V_40 ) ,
( V_2 -> V_142 ) ? 1 : 0 ) ;
F_12 ( L_35 ,
V_53 -> V_58 -> V_59 () , V_176 -> V_64 ,
( V_179 ) ? & V_177 [ 0 ] : L_22 ) ;
}
static int F_42 (
struct V_14 * V_15 ,
struct V_52 * V_53 ,
struct V_60 * V_180 ,
T_1 V_165 ,
struct V_23 * V_123 ,
struct V_69 * V_124 )
{
struct V_1 * V_2 , * V_154 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char V_162 [ V_171 ] ;
unsigned char V_163 [ V_173 ] ;
T_3 V_164 ;
memset ( V_162 , 0 , V_171 ) ;
memset ( V_163 , 0 , V_173 ) ;
snprintf ( V_162 , V_171 , L_26 , V_123 -> V_64 ) ;
snprintf ( V_163 , V_173 , L_26 ,
V_53 -> V_58 -> V_181 ( V_53 ) ) ;
V_164 = V_53 -> V_58 -> V_182 ( V_53 ) ;
F_4 ( & V_33 -> V_183 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if ( ! strcmp ( V_2 -> V_170 , V_162 ) &&
( V_2 -> V_140 == V_124 -> V_63 ) &&
! ( strcmp ( V_2 -> V_172 , V_163 ) ) &&
( V_2 -> V_174 == V_164 ) &&
( V_2 -> V_141 == V_165 ) ) {
V_2 -> V_121 = V_123 ;
V_2 -> V_139 = V_124 ;
V_2 -> V_144 = V_180 ;
F_39 ( & V_2 -> V_135 ) ;
F_5 ( & V_33 -> V_183 ) ;
F_43 ( V_15 , V_123 , V_2 , 0 , 0 ) ;
if ( V_2 -> V_39 )
F_41 ( V_15 , V_53 ,
V_123 , V_2 ) ;
F_4 ( & V_33 -> V_183 ) ;
V_33 -> V_184 = 1 ;
}
}
F_5 ( & V_33 -> V_183 ) ;
return 0 ;
}
int F_44 (
struct V_14 * V_15 ,
struct V_52 * V_53 ,
struct V_60 * V_180 ,
struct V_159 * V_185 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_23 * V_123 = V_185 -> V_160 ;
struct V_69 * V_124 = & V_123 -> V_77 [ V_185 -> V_63 ] ;
if ( V_30 -> V_34 . V_36 != V_37 )
return 0 ;
return F_42 ( V_15 , V_53 , V_180 ,
V_180 -> V_61 , V_123 , V_124 ) ;
}
static void F_45 (
struct V_151 * V_152 ,
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_1 * V_2 ,
int V_186 )
{
struct V_52 * V_54 = V_123 -> V_54 ;
char V_177 [ V_178 ] ;
int V_179 ;
memset ( & V_177 [ 0 ] , 0 , V_178 ) ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
F_12 ( L_36
L_37 , V_152 -> V_59 () , ( V_186 == 2 ) ?
L_38 : ( V_186 == 1 ) ?
L_39 : L_22 , V_123 -> V_64 ,
( V_179 ) ? V_177 : L_22 ) ;
F_12 ( L_40 ,
V_152 -> V_59 () , V_152 -> V_181 ( V_54 ) ,
V_152 -> V_182 ( V_54 ) ) ;
F_12 ( L_41
L_42 , V_152 -> V_59 () ,
( V_2 -> V_142 ) ? L_43 : L_44 ,
V_15 -> V_187 -> V_188 ) ;
F_12 ( L_45
L_46 , V_152 -> V_59 () ,
V_2 -> V_120 , V_2 -> V_189 ,
V_2 -> V_143 ) ;
}
static void F_43 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_1 * V_2 ,
int V_186 ,
int V_190 )
{
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_151 * V_152 = V_123 -> V_54 -> V_58 ;
struct V_1 * V_154 , * V_155 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
V_2 -> V_189 = ( V_190 ) ?
V_30 -> V_34 . V_118 ++ :
F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_2 -> V_133 , & V_33 -> V_46 ) ;
V_2 -> V_139 -> V_81 = 1 ;
F_45 ( V_152 , V_15 , V_123 , V_2 , V_186 ) ;
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_2 -> V_142 || V_190 )
return;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
F_39 ( & V_154 -> V_137 ) ;
V_154 -> V_189 = F_18 ( V_15 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_38 ( & V_154 -> V_133 ,
& V_33 -> V_46 ) ;
V_154 -> V_139 -> V_81 = 1 ;
F_45 ( V_152 , V_15 ,
V_154 -> V_121 , V_154 ,
V_186 ) ;
F_5 ( & V_33 -> V_45 ) ;
F_37 ( V_154 -> V_139 ) ;
}
}
static int F_46 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_69 * V_124 ,
unsigned char * V_125 ,
T_2 V_126 ,
int V_127 ,
int V_128 ,
int V_186 ,
int V_190 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_15 , V_123 , V_124 , V_125 ,
V_126 , V_127 , V_128 ) ;
if ( ! V_2 )
return - V_191 ;
F_43 ( V_15 , V_123 , V_2 ,
V_186 , V_190 ) ;
return 0 ;
}
static struct V_1 * F_47 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
unsigned char * V_125 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_154 ;
struct V_52 * V_53 ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_121 != V_123 )
continue;
V_53 = V_2 -> V_121 -> V_54 ;
if ( ! V_2 -> V_5 ) {
if ( V_53 -> V_58 -> V_192 != NULL ) {
if ( V_15 -> V_31 -> V_193 . V_194 )
continue;
}
F_29 ( & V_2 -> V_138 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
if ( ! V_125 )
continue;
if ( strcmp ( V_125 , V_2 -> V_6 ) )
continue;
F_29 ( & V_2 -> V_138 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
return V_2 ;
}
F_5 ( & V_33 -> V_45 ) ;
return NULL ;
}
static struct V_1 * F_7 (
struct V_14 * V_15 ,
struct V_23 * V_123 ,
struct V_17 * V_18 )
{
struct V_52 * V_53 = V_123 -> V_54 ;
unsigned char V_3 [ V_145 ] , * V_195 = NULL ;
if ( V_53 -> V_58 -> V_192 != NULL ) {
memset ( & V_3 [ 0 ] , 0 , V_145 ) ;
V_53 -> V_58 -> V_192 ( V_18 , & V_3 [ 0 ] ,
V_145 ) ;
V_195 = & V_3 [ 0 ] ;
}
return F_47 ( V_15 , V_123 , V_195 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_138 ) ;
F_36 () ;
}
static int F_48 (
struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_23 * V_123 = V_2 -> V_121 ;
struct V_1 * V_39 ;
int V_20 = 0 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
if ( V_39 == V_2 ) {
F_49 ( V_15 , V_123 , V_2 , 0 ) ;
V_20 = 1 ;
} else if ( V_2 -> V_142 &&
( ! strcmp ( V_39 -> V_121 -> V_64 ,
V_2 -> V_121 -> V_64 ) ) &&
( V_39 -> V_120 == V_2 -> V_120 ) ) {
F_10 ( L_47
L_48
L_49
L_50 , V_2 -> V_120 ) ;
V_20 = - V_191 ;
}
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static void F_50 (
struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_196 * V_197 ,
int V_198 )
{
struct V_151 * V_152 =
V_2 -> V_121 -> V_54 -> V_58 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_177 [ V_178 ] ;
int V_179 ;
memset ( V_177 , 0 , V_178 ) ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
V_2 -> V_139 -> V_81 = 0 ;
V_2 -> V_139 -> V_120 = 0 ;
F_39 ( & V_2 -> V_133 ) ;
if ( V_198 )
F_8 ( V_2 ) ;
while ( F_51 ( & V_2 -> V_138 ) != 0 ) {
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_51 ,
V_152 -> V_59 () ) ;
F_52 () ;
F_4 ( & V_33 -> V_45 ) ;
}
F_12 ( L_52
L_37 , V_152 -> V_59 () ,
V_2 -> V_121 -> V_64 ,
( V_179 ) ? & V_177 [ 0 ] : L_22 ) ;
F_12 ( L_41
L_42 , V_152 -> V_59 () ,
( V_2 -> V_142 ) ? L_43 : L_44 ,
V_15 -> V_187 -> V_188 ) ;
F_12 ( L_45
L_53 , V_152 -> V_59 () , V_2 -> V_120 ,
V_2 -> V_189 ) ;
if ( ! V_197 ) {
V_2 -> V_139 = NULL ;
V_2 -> V_121 = NULL ;
F_53 ( V_2 -> V_131 ) ;
F_23 ( V_129 , V_2 ) ;
return;
}
F_38 ( & V_2 -> V_134 , V_197 ) ;
}
void F_54 (
struct V_14 * V_15 ,
struct V_23 * V_123 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_154 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( ( V_39 != NULL ) &&
( V_39 -> V_121 == V_123 ) )
F_49 ( V_15 , V_123 , V_39 , 0 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( V_2 -> V_121 != V_123 )
continue;
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
void F_55 (
struct V_14 * V_15 )
{
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_154 , * V_39 ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( V_39 != NULL ) {
struct V_23 * V_199 = V_39 -> V_121 ;
F_49 ( V_15 , V_199 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
F_50 ( V_15 , V_2 , NULL , 0 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_4 ( & V_33 -> V_183 ) ;
F_28 (pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
F_39 ( & V_2 -> V_135 ) ;
F_53 ( V_2 -> V_131 ) ;
F_23 ( V_129 , V_2 ) ;
}
F_5 ( & V_33 -> V_183 ) ;
}
static int F_56 ( struct V_52 * V_53 )
{
return F_57 ( V_53 -> V_58 -> V_200 ,
& V_53 -> V_201 . V_202 ) ;
}
static void F_58 ( struct V_52 * V_53 )
{
F_59 ( V_53 -> V_58 -> V_200 ,
& V_53 -> V_201 . V_202 ) ;
F_35 ( & V_53 -> V_203 ) ;
F_36 () ;
}
static int F_60 ( struct V_23 * V_123 )
{
struct V_52 * V_53 = V_123 -> V_54 ;
if ( V_123 -> V_204 )
return 0 ;
return F_57 ( V_53 -> V_58 -> V_200 ,
& V_123 -> V_205 . V_202 ) ;
}
static void F_61 ( struct V_23 * V_123 )
{
struct V_52 * V_53 = V_123 -> V_54 ;
if ( V_123 -> V_204 ) {
F_35 ( & V_123 -> V_206 ) ;
F_36 () ;
return;
}
F_59 ( V_53 -> V_58 -> V_200 ,
& V_123 -> V_205 . V_202 ) ;
F_35 ( & V_123 -> V_206 ) ;
F_36 () ;
}
static int F_34 ( struct V_69 * V_62 )
{
struct V_159 * V_185 = V_62 -> V_159 ;
struct V_23 * V_123 ;
struct V_52 * V_53 ;
if ( ! V_185 )
return 0 ;
V_123 = V_185 -> V_160 ;
V_53 = V_123 -> V_54 ;
return F_57 ( V_53 -> V_58 -> V_200 ,
& V_185 -> V_207 . V_202 ) ;
}
static void F_37 ( struct V_69 * V_62 )
{
struct V_159 * V_185 = V_62 -> V_159 ;
struct V_23 * V_123 ;
struct V_52 * V_53 ;
if ( ! V_185 ) {
F_35 ( & V_62 -> V_161 ) ;
F_36 () ;
return;
}
V_123 = V_185 -> V_160 ;
V_53 = V_123 -> V_54 ;
F_59 ( V_53 -> V_58 -> V_200 ,
& V_185 -> V_207 . V_202 ) ;
F_35 ( & V_62 -> V_161 ) ;
F_36 () ;
}
static int F_62 (
struct V_7 * V_8 ,
struct V_52 * V_53 ,
unsigned char * V_208 ,
T_2 V_126 ,
int V_127 ,
int V_128 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_148 * V_209 ;
struct V_52 * V_210 = NULL , * V_211 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_23 * V_212 = NULL ;
struct V_69 * V_213 = NULL , * V_214 ;
struct V_1 * V_215 , * V_216 , * V_217 ;
struct V_1 * V_154 , * V_155 ;
struct V_196 V_218 ;
struct V_219 * V_220 , * V_221 , * V_222 ;
struct V_151 * V_223 ;
unsigned char * V_3 ;
unsigned char * V_224 , * V_225 = NULL , V_226 , V_227 ;
char * V_228 = NULL , V_229 [ 64 ] , V_177 [ V_178 ] ;
T_1 V_230 , V_231 = 0 ;
int V_20 , V_232 , V_179 ;
T_1 V_233 = 0 ;
memset ( V_229 , 0 , 64 ) ;
F_24 ( & V_218 ) ;
V_214 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
V_220 = F_22 ( sizeof( struct V_219 ) , V_167 ) ;
if ( ! V_220 ) {
F_10 ( L_54 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
F_24 ( & V_220 -> V_235 ) ;
V_220 -> V_210 = V_53 ;
V_220 -> V_212 = V_19 -> V_23 ;
V_220 -> V_213 = V_214 ;
V_216 = F_27 ( V_8 -> V_16 ,
V_19 -> V_23 , V_214 , V_208 ,
V_126 , V_127 , V_128 ) ;
if ( ! V_216 ) {
F_53 ( V_220 ) ;
V_8 -> V_47 = V_234 ;
return - V_168 ;
}
V_220 -> V_215 = V_216 ;
V_220 -> V_232 = 1 ;
F_38 ( & V_220 -> V_235 , & V_218 ) ;
V_3 = F_63 ( V_8 ) ;
V_230 = ( V_3 [ 24 ] & 0xff ) << 24 ;
V_230 |= ( V_3 [ 25 ] & 0xff ) << 16 ;
V_230 |= ( V_3 [ 26 ] & 0xff ) << 8 ;
V_230 |= V_3 [ 27 ] & 0xff ;
if ( ( V_230 + 28 ) != V_8 -> V_236 ) {
F_10 ( L_55
L_56 , V_230 ,
V_8 -> V_236 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_224 = & V_3 [ 28 ] ;
while ( V_230 > 0 ) {
V_226 = ( V_224 [ 0 ] & 0x0f ) ;
V_210 = NULL ;
F_4 ( & V_15 -> V_156 ) ;
F_32 (tmp_port, &dev->dev_sep_list, sep_list) {
V_211 = V_209 -> V_238 ;
if ( ! V_211 )
continue;
V_223 = V_211 -> V_58 ;
if ( ! V_223 )
continue;
if ( ! V_223 -> V_239 ||
! V_223 -> V_240 )
continue;
V_227 = V_223 -> V_239 ( V_211 ) ;
if ( V_227 != V_226 )
continue;
V_233 = V_209 -> V_241 ;
V_225 = V_223 -> V_240 (
V_211 , ( const char * ) V_224 , & V_231 ,
& V_228 ) ;
if ( ! V_225 )
continue;
F_29 ( & V_211 -> V_203 ) ;
F_30 () ;
F_5 ( & V_15 -> V_156 ) ;
V_20 = F_56 ( V_211 ) ;
if ( V_20 != 0 ) {
F_10 ( L_57
L_58 ) ;
F_35 ( & V_211 -> V_203 ) ;
F_36 () ;
V_8 -> V_47 =
V_234 ;
V_20 = - V_24 ;
goto V_55;
}
F_64 ( & V_211 -> V_242 ) ;
V_212 = F_65 (
V_211 , V_225 ) ;
if ( V_212 ) {
F_29 ( & V_212 -> V_206 ) ;
F_30 () ;
}
F_66 ( & V_211 -> V_242 ) ;
if ( ! V_212 ) {
F_58 ( V_211 ) ;
F_4 ( & V_15 -> V_156 ) ;
continue;
}
V_20 = F_60 ( V_212 ) ;
if ( V_20 != 0 ) {
F_10 ( L_59
L_60 ) ;
F_35 ( & V_212 -> V_206 ) ;
F_36 () ;
F_58 ( V_211 ) ;
V_8 -> V_47 =
V_234 ;
V_20 = - V_24 ;
goto V_55;
}
V_210 = V_211 ;
F_12 ( L_61
L_62 ,
V_210 -> V_58 -> V_59 () ,
V_212 -> V_64 , V_233 ) ;
F_4 ( & V_15 -> V_156 ) ;
break;
}
F_5 ( & V_15 -> V_156 ) ;
if ( ! V_210 ) {
F_10 ( L_63
L_64 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
dest_tpg->se_tpg_tfo->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
#endif
if ( V_231 > V_230 ) {
F_10 ( L_65
L_66 , V_231 , V_224 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_213 = F_67 ( V_212 ,
V_233 ) ;
if ( ! V_213 ) {
F_10 ( L_67
L_68 ,
V_210 -> V_58 -> V_59 () ,
V_233 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_20 = F_34 ( V_213 ) ;
if ( V_20 < 0 ) {
F_10 ( L_69
L_70 ) ;
F_35 ( & V_213 -> V_161 ) ;
F_36 () ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
V_8 -> V_47 =
V_234 ;
V_20 = - V_24 ;
goto V_55;
}
#if 0
pr_debug("SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
#endif
V_217 = F_47 ( V_15 , V_212 ,
V_228 ) ;
if ( V_217 ) {
F_8 ( V_217 ) ;
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
V_224 += V_231 ;
V_230 -= V_231 ;
V_231 = 0 ;
continue;
}
V_220 = F_22 ( sizeof( struct V_219 ) ,
V_167 ) ;
if ( ! V_220 ) {
F_10 ( L_54 ) ;
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
V_8 -> V_47 =
V_234 ;
V_20 = - V_168 ;
goto V_55;
}
F_24 ( & V_220 -> V_235 ) ;
V_220 -> V_210 = V_210 ;
V_220 -> V_212 = V_212 ;
V_220 -> V_213 = V_213 ;
V_215 = F_27 ( V_8 -> V_16 ,
V_212 , V_213 , V_228 ,
V_126 , V_127 , V_128 ) ;
if ( ! V_215 ) {
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
F_53 ( V_220 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_220 -> V_215 = V_215 ;
F_38 ( & V_220 -> V_235 , & V_218 ) ;
V_224 += V_231 ;
V_230 -= V_231 ;
V_231 = 0 ;
}
F_68 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_210 = V_221 -> V_210 ;
V_212 = V_221 -> V_212 ;
V_213 = V_221 -> V_213 ;
V_215 = V_221 -> V_215 ;
V_232 = V_221 -> V_232 ;
F_39 ( & V_221 -> V_235 ) ;
F_53 ( V_221 ) ;
memset ( V_177 , 0 , V_178 ) ;
V_179 = F_1 ( V_215 , & V_177 [ 0 ] ,
V_178 ) ;
F_43 ( V_8 -> V_16 , V_212 ,
V_215 , 0 , 0 ) ;
F_12 ( L_71
L_72
L_73 , V_210 -> V_58 -> V_59 () ,
V_212 -> V_64 , ( V_179 ) ?
& V_177 [ 0 ] : L_22 , V_213 -> V_63 ) ;
if ( V_232 )
continue;
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
}
return 0 ;
V_55:
F_68 ( V_8 ) ;
F_28 (tidh, tidh_tmp, &tid_dest_list, dest_list) {
V_210 = V_221 -> V_210 ;
V_212 = V_221 -> V_212 ;
V_213 = V_221 -> V_213 ;
V_215 = V_221 -> V_215 ;
V_232 = V_221 -> V_232 ;
F_39 ( & V_221 -> V_235 ) ;
F_53 ( V_221 ) ;
F_28 (pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
F_39 ( & V_154 -> V_137 ) ;
F_37 ( V_154 -> V_139 ) ;
F_23 ( V_129 , V_154 ) ;
}
F_53 ( V_215 -> V_131 ) ;
F_23 ( V_129 , V_215 ) ;
if ( V_232 )
continue;
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_210 ) ;
}
return V_20 ;
}
static int F_69 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_132 ,
int V_243 )
{
struct V_60 * V_180 ;
struct V_52 * V_53 ;
struct V_29 * V_30 = V_15 -> V_31 ;
struct V_1 * V_2 ;
unsigned char V_244 [ 512 ] , V_245 [ 32 ] ;
T_5 V_246 = 0 ;
int V_247 = 0 ;
memset ( V_3 , 0 , V_132 ) ;
if ( V_243 ) {
snprintf ( V_3 , V_132 ,
L_74 ) ;
return 0 ;
}
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
V_244 [ 0 ] = '\0' ;
V_245 [ 0 ] = '\0' ;
V_53 = V_2 -> V_121 -> V_54 ;
V_180 = V_2 -> V_144 ;
if ( V_2 -> V_5 )
snprintf ( V_245 , 32 , L_75 ,
V_2 -> V_6 ) ;
if ( V_15 -> V_119 == V_2 ) {
snprintf ( V_244 , 512 , L_76
L_77
L_78
L_79
L_80
L_81
L_82 , V_247 ,
V_53 -> V_58 -> V_59 () ,
V_2 -> V_121 -> V_64 , V_245 ,
V_2 -> V_120 , V_2 -> V_40 ,
V_2 -> V_169 , V_2 -> V_142 ,
V_2 -> V_140 ) ;
} else {
snprintf ( V_244 , 512 , L_83
L_84
L_85
L_86 ,
V_247 , V_53 -> V_58 -> V_59 () ,
V_2 -> V_121 -> V_64 , V_245 ,
V_2 -> V_120 , V_2 -> V_142 ,
V_2 -> V_140 ) ;
}
if ( ( V_246 + strlen ( V_244 ) >= V_132 ) ) {
F_10 ( L_87
L_88 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_248 ;
}
V_246 += sprintf ( V_3 + V_246 , L_26 , V_244 ) ;
snprintf ( V_244 , 512 , L_89
L_90
L_91 , V_53 -> V_58 -> V_59 () ,
V_53 -> V_58 -> V_181 ( V_53 ) ,
V_53 -> V_58 -> V_182 ( V_53 ) ,
V_180 -> V_249 -> V_241 , V_180 -> V_61 , V_247 ) ;
if ( ( V_246 + strlen ( V_244 ) >= V_132 ) ) {
F_10 ( L_87
L_88 ) ;
F_5 ( & V_30 -> V_34 . V_45 ) ;
return - V_248 ;
}
V_246 += sprintf ( V_3 + V_246 , L_26 , V_244 ) ;
V_247 ++ ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
if ( ! V_247 )
V_246 += sprintf ( V_3 + V_246 , L_92 ) ;
return 0 ;
}
static int F_70 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_132 ,
int V_243 )
{
int V_20 ;
F_4 ( & V_15 -> V_21 ) ;
V_20 = F_69 ( V_15 , V_3 , V_132 ,
V_243 ) ;
F_5 ( & V_15 -> V_21 ) ;
return V_20 ;
}
static int F_71 (
struct V_14 * V_15 ,
unsigned char * V_3 ,
T_1 V_132 )
{
struct V_250 * V_251 = & V_15 -> V_31 -> V_250 ;
struct V_252 * V_252 ;
struct V_253 V_254 [ 1 ] ;
T_6 V_255 ;
int V_256 = V_257 | V_258 | V_259 ;
char V_260 [ 512 ] ;
int V_20 ;
memset ( V_254 , 0 , sizeof( struct V_253 ) ) ;
memset ( V_260 , 0 , 512 ) ;
if ( strlen ( & V_251 -> V_261 [ 0 ] ) >= 512 ) {
F_10 ( L_93
L_94 ) ;
return - V_248 ;
}
snprintf ( V_260 , 512 , L_95 , & V_251 -> V_261 [ 0 ] ) ;
V_252 = F_72 ( V_260 , V_256 , 0600 ) ;
if ( F_73 ( V_252 ) || ! V_252 || ! V_252 -> V_262 ) {
F_10 ( L_96
L_70 , V_260 ) ;
return ( F_74 ( V_252 ) < 0 ? F_74 ( V_252 ) : - V_263 ) ;
}
V_254 [ 0 ] . V_264 = & V_3 [ 0 ] ;
if ( ! V_132 )
V_254 [ 0 ] . V_265 = ( strlen ( & V_3 [ 0 ] ) + 1 ) ;
else
V_254 [ 0 ] . V_265 = V_132 ;
V_255 = F_75 () ;
F_76 ( F_77 () ) ;
V_20 = F_78 ( V_252 , & V_254 [ 0 ] , 1 , & V_252 -> V_266 ) ;
F_76 ( V_255 ) ;
if ( V_20 < 0 ) {
F_12 ( L_97 , V_260 ) ;
F_79 ( V_252 , NULL ) ;
return - V_267 ;
}
F_79 ( V_252 , NULL ) ;
return 0 ;
}
static int F_80 (
struct V_14 * V_15 ,
unsigned char * V_268 ,
T_1 V_269 )
{
unsigned char V_270 [ 64 ] , * V_3 ;
T_1 V_132 ;
int V_20 , V_243 = 0 ;
if ( ! V_268 ) {
memset ( V_270 , 0 , 64 ) ;
V_3 = & V_270 [ 0 ] ;
V_132 = 64 ;
V_243 = 1 ;
} else {
V_3 = V_268 ;
V_132 = V_269 ;
}
V_20 = F_70 ( V_15 , V_3 , V_132 ,
V_243 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_71 ( V_15 , V_3 , 0 ) ;
if ( V_20 != 0 )
return V_20 ;
return V_20 ;
}
static int F_81 (
struct V_7 * V_8 ,
T_2 V_271 ,
T_2 V_126 ,
int V_128 ,
int V_127 ,
int V_272 ,
int V_273 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_69 * V_62 ;
struct V_60 * V_60 = V_8 -> V_60 ;
struct V_52 * V_54 ;
struct V_1 * V_2 , * V_274 , * V_154 , * V_217 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_131 = NULL ;
unsigned char V_245 [ V_145 ] , * V_195 = NULL ;
int V_275 = 0 , V_20 = 0 , type ;
if ( ! V_19 || ! V_60 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
V_54 = V_19 -> V_54 ;
V_62 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
if ( V_54 -> V_58 -> V_192 ) {
memset ( & V_245 [ 0 ] , 0 , V_145 ) ;
V_54 -> V_58 -> V_192 ( V_19 , & V_245 [ 0 ] ,
V_145 ) ;
V_195 = & V_245 [ 0 ] ;
}
V_217 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_217 ) {
if ( V_271 ) {
F_82 ( L_99
L_100 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_126 )
return 0 ;
if ( ! V_272 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_19 -> V_23 , V_62 , V_195 ,
V_126 , V_127 , V_128 ,
V_273 , 0 ) ;
if ( V_20 != 0 ) {
F_10 ( L_101
L_102 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
} else {
V_20 = F_62 ( V_8 , V_54 ,
V_195 , V_126 , V_127 , V_128 ) ;
if ( V_20 != 0 )
return V_20 ;
}
if ( ! V_128 ) {
V_33 -> V_184 = 0 ;
F_80 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_103
L_104 ) ;
return 0 ;
}
V_2 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 ) {
V_33 -> V_184 = 1 ;
F_12 ( L_105 ) ;
}
F_8 ( V_2 ) ;
return V_20 ;
} else {
V_2 = V_217 ;
type = V_2 -> V_40 ;
if ( ! V_273 ) {
if ( V_271 != V_2 -> V_120 ) {
F_10 ( L_106
L_107
L_108
L_109 , V_271 ,
V_2 -> V_120 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
}
if ( V_272 ) {
F_10 ( L_110
L_111 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( V_2 -> V_142 && ! ( V_127 ) ) {
F_10 ( L_112
L_113
L_114 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
if ( V_128 ) {
V_131 = F_22 ( V_33 -> V_132 ,
V_167 ) ;
if ( ! V_131 ) {
F_10 ( L_101
L_115 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 =
V_234 ;
return - V_24 ;
}
}
if ( ! V_126 ) {
V_275 = F_48 (
V_8 -> V_16 , V_2 ) ;
if ( V_275 < 0 ) {
F_53 ( V_131 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_33 -> V_45 ) ;
if ( V_2 -> V_142 ) {
F_28 (pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if ( ! V_274 -> V_142 )
continue;
if ( V_274 -> V_120 != V_271 )
continue;
if ( V_2 == V_274 )
continue;
if ( strcmp ( V_2 -> V_121 -> V_64 ,
V_274 -> V_121 -> V_64 ) )
continue;
F_50 ( V_15 ,
V_274 , NULL , 0 ) ;
}
}
F_50 ( V_8 -> V_16 , V_2 ,
NULL , 1 ) ;
if ( V_275 &&
( ( type == V_41 ) ||
( type == V_42 ) ) ) {
F_32 (pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
F_83 (
V_274 -> V_121 ,
V_274 -> V_140 ,
0x2A ,
V_277 ) ;
}
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_128 ) {
V_33 -> V_184 = 0 ;
F_80 ( V_15 , NULL , 0 ) ;
F_12 ( L_116
L_117 ) ;
return 0 ;
}
V_20 = F_80 ( V_15 ,
& V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 ) {
V_33 -> V_184 = 1 ;
F_12 ( L_118
L_117 ) ;
}
F_53 ( V_131 ) ;
return V_20 ;
} else {
V_2 -> V_189 = F_18 (
V_8 -> V_16 ) ;
V_2 -> V_120 = V_126 ;
F_12 ( L_119
L_120
L_53 , V_8 -> V_278 -> V_59 () ,
( V_273 ) ? L_39 : L_22 ,
V_2 -> V_121 -> V_64 ,
V_2 -> V_120 , V_2 -> V_189 ) ;
if ( ! V_128 ) {
V_33 -> V_184 = 0 ;
F_80 ( V_15 , NULL , 0 ) ;
F_8 ( V_2 ) ;
F_12 ( L_116
L_121 ) ;
return 0 ;
}
V_20 = F_80 ( V_15 ,
& V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 ) {
V_33 -> V_184 = 1 ;
F_12 ( L_118
L_121 ) ;
}
F_53 ( V_131 ) ;
F_8 ( V_2 ) ;
}
}
return 0 ;
}
unsigned char * F_17 ( int type )
{
switch ( type ) {
case V_79 :
return L_122 ;
case V_80 :
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
int V_279 ,
T_2 V_271 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_69 * V_62 ;
struct V_60 * V_60 = V_8 -> V_60 ;
struct V_52 * V_54 ;
struct V_1 * V_2 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
char V_177 [ V_178 ] ;
int V_20 , V_179 ;
memset ( V_177 , 0 , V_178 ) ;
if ( ! V_19 || ! V_60 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
V_54 = V_19 -> V_54 ;
V_62 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_129
L_130 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
if ( V_271 != V_2 -> V_120 ) {
F_10 ( L_131
L_132
L_109 , V_271 , V_2 -> V_120 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_279 != V_280 ) {
F_10 ( L_133 , V_279 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( ( V_39 ) ) {
if ( V_39 != V_2 ) {
struct V_23 * V_199 = V_39 -> V_121 ;
F_10 ( L_134
L_135
L_136 ,
V_8 -> V_278 -> V_59 () ,
V_19 -> V_23 -> V_64 ,
V_199 -> V_54 -> V_58 -> V_59 () ,
V_39 -> V_121 -> V_64 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_169 != V_279 ) ) {
struct V_23 * V_199 = V_39 -> V_121 ;
F_10 ( L_134
L_137
L_138
L_4 ,
V_8 -> V_278 -> V_59 () ,
V_19 -> V_23 -> V_64 ,
V_199 -> V_54 -> V_58 -> V_59 () ,
V_39 -> V_121 -> V_64 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
V_2 -> V_169 = V_279 ;
V_2 -> V_40 = type ;
V_2 -> V_39 = 1 ;
V_15 -> V_119 = V_2 ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
F_12 ( L_139
L_140 ,
V_8 -> V_278 -> V_59 () , F_17 ( type ) ,
( V_2 -> V_142 ) ? 1 : 0 ) ;
F_12 ( L_35 ,
V_8 -> V_278 -> V_59 () ,
V_19 -> V_23 -> V_64 ,
( V_179 ) ? & V_177 [ 0 ] : L_22 ) ;
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_184 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
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
int V_279 ,
T_2 V_271 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
int V_20 = 0 ;
switch ( type ) {
case V_79 :
case V_80 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_84 ( V_8 , V_15 , type , V_279 , V_271 ) ;
break;
default:
F_10 ( L_143
L_144 , type ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
return V_20 ;
}
static void F_49 (
struct V_14 * V_15 ,
struct V_23 * V_281 ,
struct V_1 * V_2 ,
int V_282 )
{
struct V_151 * V_152 = V_281 -> V_54 -> V_58 ;
char V_177 [ V_178 ] ;
int V_179 ;
memset ( V_177 , 0 , V_178 ) ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
V_15 -> V_119 = NULL ;
F_12 ( L_145
L_140 ,
V_152 -> V_59 () , ( V_282 ) ? L_146 : L_147 ,
F_17 ( V_2 -> V_40 ) ,
( V_2 -> V_142 ) ? 1 : 0 ) ;
F_12 ( L_148 ,
V_152 -> V_59 () , V_281 -> V_64 ,
( V_179 ) ? & V_177 [ 0 ] : L_22 ) ;
V_2 -> V_39 = V_2 -> V_40 = V_2 -> V_169 = 0 ;
}
static int F_86 (
struct V_7 * V_8 ,
int type ,
int V_279 ,
T_2 V_271 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_60 * V_60 = V_8 -> V_60 ;
struct V_1 * V_2 , * V_274 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
int V_20 , V_73 = 0 ;
if ( ! V_19 || ! V_60 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
V_2 = F_7 ( V_15 , V_19 -> V_23 , V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_129
L_149 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( ! V_39 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) )
V_73 = 1 ;
if ( ( V_73 == 0 ) && ( V_39 != V_2 ) ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( V_271 != V_2 -> V_120 ) {
F_10 ( L_150
L_132
L_109 , V_271 , V_2 -> V_120 ) ;
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ( V_39 -> V_40 != type ) ||
( V_39 -> V_169 != V_279 ) ) {
struct V_23 * V_199 = V_39 -> V_121 ;
F_10 ( L_151
L_152
L_153
L_136 ,
V_8 -> V_278 -> V_59 () ,
V_19 -> V_23 -> V_64 ,
V_199 -> V_54 -> V_58 -> V_59 () ,
V_39 -> V_121 -> V_64 ) ;
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
goto V_283;
}
F_4 ( & V_33 -> V_45 ) ;
F_32 (pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if ( V_274 == V_2 )
continue;
F_83 ( V_274 -> V_121 ,
V_274 -> V_140 ,
0x2A , V_277 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
V_283:
if ( V_33 -> V_184 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_2 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 )
F_12 ( L_154 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_87 (
struct V_7 * V_8 ,
T_2 V_271 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_23 * V_121 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
struct V_1 * V_2 , * V_154 , * V_284 , * V_39 ;
T_1 V_140 = 0 ;
int V_285 = 0 ;
V_284 = F_7 ( V_8 -> V_16 ,
V_19 -> V_23 , V_19 ) ;
if ( ! V_284 ) {
F_10 ( L_129
L_155 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
if ( V_271 != V_284 -> V_120 ) {
F_10 ( L_106
L_107
L_108
L_109 , V_271 , V_284 -> V_120 ) ;
F_8 ( V_284 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( V_39 ) {
struct V_23 * V_199 = V_39 -> V_121 ;
F_49 ( V_15 , V_199 ,
V_39 , 0 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_285 = ( V_284 == V_2 ) ? 1 : 0 ;
V_121 = V_2 -> V_121 ;
V_140 = V_2 -> V_140 ;
F_50 ( V_15 , V_2 , NULL ,
V_285 ) ;
if ( ! V_285 )
F_83 ( V_121 , V_140 ,
0x2A , V_286 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_12 ( L_156 ,
V_8 -> V_278 -> V_59 () ) ;
if ( V_33 -> V_184 ) {
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
struct V_196 * V_197 ,
int type ,
int V_279 ,
int abort )
{
struct V_23 * V_123 = V_2 -> V_121 ;
struct V_151 * V_152 = V_123 -> V_54 -> V_58 ;
char V_177 [ V_178 ] ;
int V_179 ;
memset ( V_177 , 0 , V_178 ) ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
if ( V_15 -> V_119 )
F_49 ( V_15 , V_123 ,
V_15 -> V_119 , 0 ) ;
V_15 -> V_119 = V_2 ;
V_2 -> V_39 = 1 ;
V_2 -> V_40 = type ;
V_2 -> V_169 = V_279 ;
F_12 ( L_158
L_140 ,
V_152 -> V_59 () , ( abort ) ? L_159 : L_22 ,
F_17 ( type ) ,
( V_2 -> V_142 ) ? 1 : 0 ) ;
F_12 ( L_160 ,
V_152 -> V_59 () , ( abort ) ? L_159 : L_22 ,
V_123 -> V_64 , ( V_179 ) ? & V_177 [ 0 ] : L_22 ) ;
if ( V_197 )
F_38 ( & V_2 -> V_134 ,
V_197 ) ;
}
static void F_89 (
struct V_196 * V_197 ,
struct V_1 * V_287 )
{
struct V_1 * V_2 , * V_154 ;
F_28 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
F_39 ( & V_2 -> V_134 ) ;
if ( V_287 == V_2 )
continue;
if ( V_2 -> V_39 ) {
F_82 ( L_161 ) ;
continue;
}
V_2 -> V_139 = NULL ;
V_2 -> V_121 = NULL ;
F_53 ( V_2 -> V_131 ) ;
F_23 ( V_129 , V_2 ) ;
}
}
int F_90 (
struct V_196 * V_197 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 , * V_154 ;
F_28 (pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
if ( V_2 -> V_120 == V_8 -> V_120 )
return 0 ;
}
return 1 ;
}
static int F_91 (
struct V_7 * V_8 ,
int type ,
int V_279 ,
T_2 V_271 ,
T_2 V_126 ,
int abort )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_69 * V_62 ;
struct V_23 * V_121 ;
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_196 V_197 ;
struct V_1 * V_2 , * V_154 , * V_284 , * V_39 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
T_1 V_140 = 0 ;
int V_73 = 0 , V_285 = 0 , V_288 = 0 ;
int V_289 = 0 , V_290 = 0 , V_20 ;
if ( ! V_19 ) {
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
V_62 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
V_284 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_284 ) {
F_10 ( L_129
L_162 ,
( abort ) ? L_159 : L_22 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_284 -> V_120 != V_271 ) {
F_8 ( V_284 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_279 != V_280 ) {
F_10 ( L_133 , V_279 ) ;
F_8 ( V_284 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_24 ( & V_197 ) ;
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( V_39 &&
( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) )
V_73 = 1 ;
if ( ! V_73 && ! V_126 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_284 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
if ( ! V_39 || ( V_39 -> V_120 != V_126 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if ( ! V_73 ) {
if ( V_2 -> V_120 != V_126 )
continue;
V_285 = ( V_284 == V_2 ) ? 1 : 0 ;
V_121 = V_2 -> V_121 ;
V_140 = V_2 -> V_140 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_197 :
NULL , V_285 ) ;
V_288 ++ ;
} else {
if ( ( V_126 ) &&
( V_2 -> V_120 != V_126 ) )
continue;
V_285 = ( V_284 == V_2 ) ? 1 : 0 ;
if ( V_285 )
continue;
V_121 = V_2 -> V_121 ;
V_140 = V_2 -> V_140 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_197 :
NULL , 0 ) ;
V_288 ++ ;
}
if ( ! V_285 )
F_83 ( V_121 ,
V_140 , 0x2A ,
V_286 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
if ( ! V_288 ) {
F_5 ( & V_15 -> V_21 ) ;
F_8 ( V_284 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( V_39 && V_73 && ! ( V_126 ) ) {
F_88 ( V_15 , V_284 ,
( abort ) ? & V_197 : NULL ,
type , V_279 , abort ) ;
if ( abort )
F_89 (
& V_197 , V_284 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( V_33 -> V_184 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_284 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 )
F_12 ( L_163
L_164 , ( abort ) ?
L_159 : L_22 ) ;
}
F_8 ( V_284 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
V_289 = V_39 -> V_40 ;
V_290 = V_39 -> V_169 ;
if ( V_284 != V_39 )
F_49 ( V_15 ,
V_39 -> V_121 ,
V_15 -> V_119 , 0 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_285 = ( V_284 == V_2 ) ? 1 : 0 ;
if ( V_285 )
continue;
if ( V_2 -> V_120 != V_126 )
continue;
V_121 = V_2 -> V_121 ;
V_140 = V_2 -> V_140 ;
F_50 ( V_15 , V_2 ,
( abort ) ? & V_197 : NULL ,
V_285 ) ;
F_83 ( V_121 , V_140 , 0x2A ,
V_286 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
F_88 ( V_15 , V_284 ,
( abort ) ? & V_197 : NULL ,
type , V_279 , abort ) ;
if ( ( V_289 != type ) || ( V_290 != V_279 ) ) {
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_285 = ( V_284 == V_2 ) ? 1 : 0 ;
if ( V_285 )
continue;
F_83 ( V_2 -> V_121 ,
V_2 -> V_140 , 0x2A ,
V_277 ) ;
}
F_5 ( & V_33 -> V_45 ) ;
}
F_5 ( & V_15 -> V_21 ) ;
if ( abort ) {
F_92 ( V_15 , NULL , & V_197 , V_8 ) ;
F_89 ( & V_197 ,
V_284 ) ;
}
if ( V_33 -> V_184 ) {
V_20 = F_80 ( V_8 -> V_16 ,
& V_284 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 )
F_12 ( L_165
L_166 , ( abort ) ? L_159 : L_22 ) ;
}
F_8 ( V_284 ) ;
F_18 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_93 (
struct V_7 * V_8 ,
int type ,
int V_279 ,
T_2 V_271 ,
T_2 V_126 ,
int abort )
{
int V_20 = 0 ;
switch ( type ) {
case V_79 :
case V_80 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_20 = F_91 ( V_8 , type , V_279 ,
V_271 , V_126 , abort ) ;
break;
default:
F_10 ( L_167
L_168 , ( abort ) ? L_159 : L_22 , type ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
return V_20 ;
}
static int F_94 (
struct V_7 * V_8 ,
T_2 V_271 ,
T_2 V_126 ,
int V_128 ,
int V_291 )
{
struct V_17 * V_19 = V_8 -> V_19 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_69 * V_62 , * V_213 = NULL ;
struct V_60 * V_60 = V_8 -> V_60 ;
struct V_23 * V_199 , * V_121 , * V_212 = NULL ;
struct V_148 * V_148 ;
struct V_52 * V_54 , * V_292 = NULL ;
struct V_151 * V_293 = NULL , * V_294 ;
struct V_1 * V_2 , * V_39 , * V_215 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
unsigned char * V_295 ;
char * V_228 = NULL , V_229 [ 64 ] , V_177 [ V_178 ] ;
T_1 V_231 , V_296 ;
int V_297 = 0 , type , V_279 , V_20 , V_298 , V_179 ;
unsigned short V_299 ;
unsigned char V_226 ;
if ( ! V_19 || ! V_60 ) {
F_10 ( L_98 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
memset ( V_229 , 0 , 64 ) ;
memset ( V_177 , 0 , V_178 ) ;
V_54 = V_19 -> V_54 ;
V_294 = V_54 -> V_58 ;
V_62 = & V_19 -> V_23 -> V_77 [ V_8 -> V_78 ] ;
V_2 = F_7 ( V_8 -> V_16 , V_19 -> V_23 ,
V_19 ) ;
if ( ! V_2 ) {
F_10 ( L_169
L_170 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
if ( V_271 != V_2 -> V_120 ) {
F_82 ( L_171
L_172
L_173 , V_271 , V_2 -> V_120 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
if ( ! V_126 ) {
F_82 ( L_174
L_175 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_299 = ( V_3 [ 18 ] & 0xff ) << 8 ;
V_299 |= V_3 [ 19 ] & 0xff ;
V_231 = ( V_3 [ 20 ] & 0xff ) << 24 ;
V_231 |= ( V_3 [ 21 ] & 0xff ) << 16 ;
V_231 |= ( V_3 [ 22 ] & 0xff ) << 8 ;
V_231 |= V_3 [ 23 ] & 0xff ;
F_68 ( V_8 ) ;
V_3 = NULL ;
if ( ( V_231 + 24 ) != V_8 -> V_236 ) {
F_10 ( L_176
L_56 , V_231 ,
V_8 -> V_236 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_156 ) ;
F_32 (se_port, &dev->dev_sep_list, sep_list) {
if ( V_148 -> V_241 != V_299 )
continue;
V_292 = V_148 -> V_238 ;
if ( ! V_292 )
continue;
V_293 = V_292 -> V_58 ;
if ( ! V_293 )
continue;
F_29 ( & V_292 -> V_203 ) ;
F_30 () ;
F_5 ( & V_15 -> V_156 ) ;
V_20 = F_56 ( V_292 ) ;
if ( V_20 != 0 ) {
F_10 ( L_177
L_178 ) ;
F_35 ( & V_292 -> V_203 ) ;
F_36 () ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
F_4 ( & V_15 -> V_156 ) ;
break;
}
F_5 ( & V_15 -> V_156 ) ;
if ( ! V_292 || ! V_293 ) {
F_10 ( L_179
L_180
L_181 , V_299 ) ;
F_8 ( V_2 ) ;
V_8 -> V_47 = V_237 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_226 = ( V_3 [ 24 ] & 0x0f ) ;
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
#endif
if ( V_226 != V_293 -> V_239 ( V_292 ) ) {
F_10 ( L_171
L_182
L_183 , V_226 ,
V_293 -> V_239 ( V_292 ) ,
V_293 -> V_59 () ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
if ( V_293 -> V_240 == NULL ) {
F_10 ( L_184
L_185
L_186 ) ;
V_8 -> V_47 = V_234 ;
V_20 = - V_24 ;
goto V_55;
}
V_295 = V_293 -> V_240 ( V_292 ,
( const char * ) & V_3 [ 24 ] , & V_296 , & V_228 ) ;
if ( ! V_295 ) {
F_10 ( L_179
L_187 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
F_68 ( V_8 ) ;
V_3 = NULL ;
F_12 ( L_188
L_189 , V_293 -> V_59 () , ( V_228 != NULL ) ?
L_190 : L_191 , V_295 , ( V_228 != NULL ) ?
V_228 : L_22 ) ;
V_121 = V_2 -> V_121 ;
V_298 = ( ! strcmp ( V_295 ,
V_121 -> V_64 ) ) ? 1 : 0 ;
if ( ! V_298 )
goto V_300;
if ( ! V_228 || ! V_2 -> V_5 ) {
F_10 ( L_192
L_193 , V_295 ,
V_121 -> V_64 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
if ( ! strcmp ( V_228 , V_2 -> V_6 ) ) {
F_10 ( L_194
L_195 ,
V_295 , V_228 , V_121 -> V_64 ,
V_2 -> V_6 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_300:
F_64 ( & V_292 -> V_242 ) ;
V_212 = F_65 ( V_292 ,
V_295 ) ;
if ( V_212 ) {
F_29 ( & V_212 -> V_206 ) ;
F_30 () ;
}
F_66 ( & V_292 -> V_242 ) ;
if ( ! V_212 ) {
F_10 ( L_196
L_197 , V_293 -> V_59 () ,
V_295 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_20 = F_60 ( V_212 ) ;
if ( V_20 != 0 ) {
F_10 ( L_198
L_199 ) ;
F_35 ( & V_212 -> V_206 ) ;
F_36 () ;
V_212 = NULL ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
#endif
V_213 = F_67 ( V_212 , V_299 ) ;
if ( ! V_213 ) {
F_10 ( L_200
L_181 , V_293 -> V_59 () , V_299 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_20 = F_34 ( V_213 ) ;
if ( V_20 < 0 ) {
F_10 ( L_201 ) ;
F_35 ( & V_213 -> V_161 ) ;
F_36 () ;
V_213 = NULL ;
V_8 -> V_47 = V_234 ;
V_20 = - V_24 ;
goto V_55;
}
#if 0
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
#endif
F_4 ( & V_15 -> V_21 ) ;
V_39 = V_15 -> V_119 ;
if ( ! V_39 ) {
F_82 ( L_202
L_203 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_276 ;
V_20 = - V_24 ;
goto V_55;
}
if ( V_39 != V_2 ) {
F_82 ( L_204
L_205 ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_55;
}
if ( ( V_39 -> V_40 == V_43 ) ||
( V_39 -> V_40 == V_44 ) ) {
F_82 ( L_206
L_207 ,
F_17 ( V_39 -> V_40 ) ) ;
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_48 ;
V_20 = - V_24 ;
goto V_55;
}
V_199 = V_39 -> V_121 ;
type = V_39 -> V_40 ;
V_279 = V_39 -> V_40 ;
V_215 = F_47 ( V_15 , V_212 ,
V_228 ) ;
if ( ! V_215 ) {
V_20 = F_46 ( V_8 -> V_16 ,
V_212 , V_213 , V_228 ,
V_126 , 0 , V_128 , 2 , 1 ) ;
if ( V_20 != 0 ) {
F_5 ( & V_15 -> V_21 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_215 = F_47 ( V_15 , V_212 ,
V_228 ) ;
V_297 = 1 ;
}
F_49 ( V_15 , V_199 ,
V_15 -> V_119 , 0 ) ;
V_15 -> V_119 = V_215 ;
V_215 -> V_39 = 1 ;
V_215 -> V_40 = type ;
V_2 -> V_169 = V_279 ;
V_179 = F_1 ( V_2 , & V_177 [ 0 ] ,
V_178 ) ;
if ( ! V_297 )
V_215 -> V_189 = V_33 -> V_118 ++ ;
F_5 ( & V_15 -> V_21 ) ;
F_12 ( L_208
L_209
L_210 , V_293 -> V_59 () ,
F_17 ( type ) , V_299 ,
V_215 -> V_189 ) ;
F_12 ( L_211
L_212 ,
V_294 -> V_59 () , V_121 -> V_64 ,
( V_179 ) ? & V_177 [ 0 ] : L_22 , V_293 -> V_59 () ,
V_212 -> V_64 , ( V_228 != NULL ) ?
V_228 : L_22 ) ;
F_37 ( V_213 ) ;
F_61 ( V_212 ) ;
F_58 ( V_292 ) ;
if ( V_291 ) {
F_4 ( & V_33 -> V_45 ) ;
F_50 ( V_15 , V_2 , NULL , 1 ) ;
F_5 ( & V_33 -> V_45 ) ;
} else
F_8 ( V_2 ) ;
if ( ! V_128 ) {
V_33 -> V_184 = 0 ;
F_80 ( V_8 -> V_16 , NULL , 0 ) ;
F_12 ( L_103
L_213 ) ;
} else {
V_33 -> V_184 = 1 ;
V_20 = F_80 ( V_8 -> V_16 ,
& V_215 -> V_131 [ 0 ] ,
V_33 -> V_132 ) ;
if ( ! V_20 )
F_12 ( L_214
L_213 ) ;
}
F_68 ( V_8 ) ;
F_8 ( V_215 ) ;
return 0 ;
V_55:
if ( V_3 )
F_68 ( V_8 ) ;
if ( V_213 )
F_37 ( V_213 ) ;
if ( V_212 )
F_61 ( V_212 ) ;
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
int F_96 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
unsigned char * V_9 = & V_8 -> V_67 [ 0 ] ;
unsigned char * V_3 ;
T_2 V_271 , V_126 ;
int V_303 , V_279 , type , V_128 ;
int V_272 = 0 , V_127 = 0 , V_291 = 0 ;
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_57 ) {
F_10 ( L_215
L_216
L_217 ) ;
V_8 -> V_47 = V_48 ;
V_20 = V_24 ;
goto V_55;
}
if ( ! V_8 -> V_19 ) {
V_8 -> V_47 = V_234 ;
return - V_24 ;
}
if ( V_8 -> V_236 < 24 ) {
F_82 ( L_218
L_219 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
V_303 = ( V_9 [ 1 ] & 0x1f ) ;
V_279 = ( V_9 [ 2 ] & 0xf0 ) ;
type = ( V_9 [ 2 ] & 0x0f ) ;
V_3 = F_63 ( V_8 ) ;
V_271 = F_95 ( & V_3 [ 0 ] ) ;
V_126 = F_95 ( & V_3 [ 8 ] ) ;
if ( V_303 != V_94 ) {
V_272 = ( V_3 [ 20 ] & 0x08 ) ;
V_127 = ( V_3 [ 20 ] & 0x04 ) ;
V_128 = ( V_3 [ 20 ] & 0x01 ) ;
} else {
V_128 = ( V_3 [ 17 ] & 0x01 ) ;
V_291 = ( V_3 [ 17 ] & 0x02 ) ;
}
F_68 ( V_8 ) ;
V_3 = NULL ;
if ( V_272 && ( ( V_9 [ 1 ] & 0x1f ) != V_92 ) ) {
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
if ( ! V_272 && ( ( V_9 [ 1 ] & 0x1f ) != V_94 ) &&
( V_8 -> V_236 != 24 ) ) {
F_82 ( L_220
L_221 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_237 ;
V_20 = - V_24 ;
goto V_55;
}
switch ( V_303 ) {
case V_92 :
V_20 = F_81 ( V_8 ,
V_271 , V_126 , V_128 , V_127 , V_272 , 0 ) ;
break;
case V_95 :
V_20 = F_85 ( V_8 , type , V_279 , V_271 ) ;
break;
case V_96 :
V_20 = F_86 ( V_8 , type , V_279 , V_271 ) ;
break;
case V_89 :
V_20 = F_87 ( V_8 , V_271 ) ;
break;
case V_90 :
V_20 = F_93 ( V_8 , type , V_279 ,
V_271 , V_126 , 0 ) ;
break;
case V_91 :
V_20 = F_93 ( V_8 , type , V_279 ,
V_271 , V_126 , 1 ) ;
break;
case V_93 :
V_20 = F_81 ( V_8 ,
0 , V_126 , V_128 , V_127 , V_272 , 1 ) ;
break;
case V_94 :
V_20 = F_94 ( V_8 , V_271 ,
V_126 , V_128 , V_291 ) ;
break;
default:
F_10 ( L_15
L_16 , V_9 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_276 ;
V_20 = - V_24 ;
break;
}
V_55:
if ( ! V_20 ) {
V_50 -> V_65 = V_66 ;
F_13 ( V_50 , 1 ) ;
}
return V_20 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_1 V_304 = 0 , V_305 = 8 ;
if ( V_8 -> V_236 < 8 ) {
F_10 ( L_222
L_223 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_118 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_118 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_118 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_118 & 0xff ) ;
F_4 ( & V_30 -> V_34 . V_45 ) ;
F_32 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
if ( ( V_304 + 8 ) > ( V_8 -> V_236 - 8 ) )
break;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 56 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 48 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 40 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 32 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 24 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 16 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_2 -> V_120 & 0xff ) ;
V_304 += 8 ;
}
F_5 ( & V_30 -> V_34 . V_45 ) ;
V_3 [ 4 ] = ( ( V_304 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_304 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_304 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_304 & 0xff ) ;
F_68 ( V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_1 * V_2 ;
unsigned char * V_3 ;
T_2 V_120 ;
T_1 V_304 = 16 ;
if ( V_8 -> V_236 < 8 ) {
F_10 ( L_224
L_223 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_118 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_118 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_118 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_118 & 0xff ) ;
F_4 ( & V_16 -> V_21 ) ;
V_2 = V_16 -> V_119 ;
if ( ( V_2 ) ) {
V_3 [ 4 ] = ( ( V_304 >> 24 ) & 0xff ) ;
V_3 [ 5 ] = ( ( V_304 >> 16 ) & 0xff ) ;
V_3 [ 6 ] = ( ( V_304 >> 8 ) & 0xff ) ;
V_3 [ 7 ] = ( V_304 & 0xff ) ;
if ( V_8 -> V_236 < 22 )
goto V_306;
if ( ( V_2 -> V_40 == V_43 ) ||
( V_2 -> V_40 == V_44 ) )
V_120 = 0 ;
else
V_120 = V_2 -> V_120 ;
V_3 [ 8 ] = ( ( V_120 >> 56 ) & 0xff ) ;
V_3 [ 9 ] = ( ( V_120 >> 48 ) & 0xff ) ;
V_3 [ 10 ] = ( ( V_120 >> 40 ) & 0xff ) ;
V_3 [ 11 ] = ( ( V_120 >> 32 ) & 0xff ) ;
V_3 [ 12 ] = ( ( V_120 >> 24 ) & 0xff ) ;
V_3 [ 13 ] = ( ( V_120 >> 16 ) & 0xff ) ;
V_3 [ 14 ] = ( ( V_120 >> 8 ) & 0xff ) ;
V_3 [ 15 ] = ( V_120 & 0xff ) ;
V_3 [ 21 ] = ( V_2 -> V_169 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
}
V_306:
F_5 ( & V_16 -> V_21 ) ;
F_68 ( V_8 ) ;
return 0 ;
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_32 * V_33 = & V_15 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_3 V_304 = 8 ;
if ( V_8 -> V_236 < 6 ) {
F_10 ( L_225
L_226 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_304 << 8 ) & 0xff ) ;
V_3 [ 1 ] = ( V_304 & 0xff ) ;
V_3 [ 2 ] |= 0x10 ;
V_3 [ 2 ] |= 0x08 ;
V_3 [ 2 ] |= 0x04 ;
V_3 [ 2 ] |= 0x01 ;
V_3 [ 3 ] |= 0x80 ;
V_3 [ 3 ] |= 0x10 ;
if ( V_33 -> V_184 )
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
static int F_100 ( struct V_7 * V_8 )
{
struct V_14 * V_16 = V_8 -> V_16 ;
struct V_23 * V_281 ;
struct V_29 * V_30 = V_16 -> V_31 ;
struct V_52 * V_54 ;
struct V_1 * V_2 , * V_154 ;
struct V_32 * V_33 = & V_16 -> V_31 -> V_34 ;
unsigned char * V_3 ;
T_1 V_307 = 0 , V_304 = 0 , V_308 , V_309 ;
T_1 V_305 = 8 ;
int V_310 = 0 ;
if ( V_8 -> V_236 < 8 ) {
F_10 ( L_227
L_223 , V_8 -> V_236 ) ;
V_8 -> V_47 = V_276 ;
return - V_24 ;
}
V_3 = F_63 ( V_8 ) ;
V_3 [ 0 ] = ( ( V_30 -> V_34 . V_118 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_30 -> V_34 . V_118 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_30 -> V_34 . V_118 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 -> V_34 . V_118 & 0xff ) ;
F_4 ( & V_33 -> V_45 ) ;
F_28 (pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
V_281 = V_2 -> V_121 ;
V_54 = V_2 -> V_121 -> V_54 ;
V_307 = 0 ;
F_29 ( & V_2 -> V_138 ) ;
F_30 () ;
F_5 ( & V_33 -> V_45 ) ;
V_309 = V_54 -> V_58 -> V_311 (
V_54 , V_281 , V_2 , & V_310 ) ;
if ( ( V_309 + V_304 ) > V_8 -> V_236 ) {
F_82 ( L_228
L_229 , V_8 -> V_236 ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_138 ) ;
F_36 () ;
break;
}
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 56 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 48 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 40 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 32 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 24 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 16 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( ( V_2 -> V_120 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_2 -> V_120 & 0xff ) ;
V_305 += 4 ;
if ( V_2 -> V_142 )
V_3 [ V_305 ] = 0x02 ;
if ( V_2 -> V_39 ) {
V_3 [ V_305 ++ ] |= 0x01 ;
V_3 [ V_305 ++ ] = ( V_2 -> V_169 & 0xf0 ) |
( V_2 -> V_40 & 0x0f ) ;
} else
V_305 += 2 ;
V_305 += 4 ;
if ( ! V_2 -> V_142 ) {
struct V_148 * V_149 = V_2 -> V_144 -> V_249 ;
V_3 [ V_305 ++ ] = ( ( V_149 -> V_241 >> 8 ) & 0xff ) ;
V_3 [ V_305 ++ ] = ( V_149 -> V_241 & 0xff ) ;
} else
V_305 += 2 ;
V_308 = V_54 -> V_58 -> V_312 ( V_54 ,
V_281 , V_2 , & V_310 , & V_3 [ V_305 + 4 ] ) ;
F_4 ( & V_33 -> V_45 ) ;
F_35 ( & V_2 -> V_138 ) ;
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
F_68 ( V_8 ) ;
return 0 ;
}
int F_101 ( struct V_49 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_51 ;
int V_20 ;
if ( V_8 -> V_16 -> V_25 & V_57 ) {
F_10 ( L_215
L_216
L_217 ) ;
V_8 -> V_47 = V_48 ;
return - V_24 ;
}
switch ( V_8 -> V_67 [ 1 ] & 0x1f ) {
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
F_10 ( L_230
L_16 , V_8 -> V_67 [ 1 ] & 0x1f ) ;
V_8 -> V_47 = V_276 ;
V_20 = - V_24 ;
break;
}
if ( ! V_20 ) {
V_50 -> V_65 = V_66 ;
F_13 ( V_50 , 1 ) ;
}
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
if ( ( ( V_15 -> V_187 -> V_319 == V_320 ) &&
! ( V_15 -> V_31 -> V_193 . V_321 ) ) || V_317 ) {
V_318 -> V_36 = V_322 ;
V_318 -> V_323 . V_324 = & F_102 ;
V_318 -> V_323 . V_325 = & F_103 ;
F_12 ( L_231
L_232 , V_15 -> V_187 -> V_188 ) ;
return 0 ;
}
if ( V_15 -> V_187 -> V_326 ( V_15 ) >= V_327 ) {
V_318 -> V_36 = V_37 ;
V_318 -> V_323 . V_324 = & F_19 ;
V_318 -> V_323 . V_325 = & F_15 ;
F_12 ( L_233
L_232 , V_15 -> V_187 -> V_188 ) ;
} else {
V_318 -> V_36 = V_328 ;
V_318 -> V_323 . V_324 = & F_3 ;
V_318 -> V_323 . V_325 =
& F_2 ;
F_12 ( L_234 ,
V_15 -> V_187 -> V_188 ) ;
}
return 0 ;
}
