T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned char * V_12 ;
T_2 V_13 = 0 , V_14 ;
int V_15 = ( V_2 -> V_16 [ 1 ] & 0x20 ) ;
if ( V_15 != 0 )
V_14 = 8 ;
else
V_14 = 4 ;
if ( V_2 -> V_17 < V_14 ) {
F_2 ( L_1
L_2 , V_2 -> V_17 ,
( V_15 ) ? L_3 : L_4 ) ;
return V_18 ;
}
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 )
return V_19 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ( V_14 + 8 + ( V_9 -> V_22 * 4 ) ) >
V_2 -> V_17 ) {
V_13 += 8 + ( V_9 -> V_22 * 4 ) ;
continue;
}
if ( V_9 -> V_23 )
V_12 [ V_14 ] = 0x80 ;
V_12 [ V_14 ++ ] |= ( F_6 (
& V_9 -> V_24 ) & 0xff ) ;
V_12 [ V_14 ] = 0x80 ;
V_12 [ V_14 ] |= 0x40 ;
V_12 [ V_14 ] |= 0x8 ;
V_12 [ V_14 ] |= 0x4 ;
V_12 [ V_14 ] |= 0x2 ;
V_12 [ V_14 ++ ] |= 0x1 ;
V_12 [ V_14 ++ ] = ( ( V_9 -> V_25 >> 8 ) & 0xff ) ;
V_12 [ V_14 ++ ] = ( V_9 -> V_25 & 0xff ) ;
V_14 ++ ;
V_12 [ V_14 ++ ] = ( V_9 -> V_26 & 0xff ) ;
V_12 [ V_14 ++ ] = 0x00 ;
V_12 [ V_14 ++ ] = ( V_9 -> V_22 & 0xff ) ;
V_13 += 8 ;
F_4 ( & V_9 -> V_27 ) ;
F_5 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_11 -> V_28 ;
V_14 += 2 ;
V_12 [ V_14 ++ ] = ( ( V_7 -> V_29 >> 8 ) & 0xff ) ;
V_12 [ V_14 ++ ] = ( V_7 -> V_29 & 0xff ) ;
V_13 += 4 ;
}
F_7 ( & V_9 -> V_27 ) ;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_8 ( V_13 , & V_12 [ 0 ] ) ;
if ( V_15 != 0 ) {
V_12 [ 4 ] = 0x10 ;
V_7 = V_2 -> V_30 -> V_31 ;
V_11 = V_7 -> V_32 ;
if ( V_11 ) {
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 )
V_12 [ 5 ] = V_9 -> V_34 ;
F_7 ( & V_11 -> V_33 ) ;
}
}
F_9 ( V_2 ) ;
F_10 ( V_2 , V_35 ) ;
return 0 ;
}
T_1
F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_36 = V_2 -> V_30 -> V_31 ;
struct V_37 * V_38 = V_2 -> V_39 -> V_37 ;
struct V_8 * V_9 = NULL , * V_40 ;
struct V_10 * V_11 , * V_41 ;
unsigned char * V_12 ;
unsigned char * V_42 ;
T_1 V_43 = V_44 ;
T_2 V_45 = 4 ;
int V_46 , V_47 = 0 ;
T_3 V_48 , V_49 ;
if ( ! V_36 )
return V_19 ;
if ( V_2 -> V_17 < 4 ) {
F_2 ( L_5
L_6 , V_2 -> V_17 ) ;
return V_50 ;
}
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 )
return V_19 ;
V_41 = V_36 -> V_32 ;
if ( ! V_41 ) {
F_12 ( L_7 ) ;
V_43 = V_51 ;
goto V_52;
}
F_4 ( & V_41 -> V_33 ) ;
V_40 = V_41 -> V_9 ;
if ( ! V_40 ) {
F_7 ( & V_41 -> V_33 ) ;
F_12 ( L_8 ) ;
V_43 = V_51 ;
goto V_52;
}
F_7 ( & V_41 -> V_33 ) ;
if ( ! ( V_40 -> V_53 & V_54 ) ) {
F_13 ( L_9
L_10 ) ;
V_43 = V_51 ;
goto V_52;
}
V_42 = & V_12 [ 4 ] ;
while ( V_45 < V_2 -> V_17 ) {
bool V_55 = false ;
V_46 = ( V_42 [ 0 ] & 0x0f ) ;
V_43 = F_14 ( V_46 , & V_47 ) ;
if ( V_43 ) {
goto V_52;
}
if ( V_47 ) {
V_48 = F_15 ( V_42 + 2 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_56 )
continue;
if ( V_48 != V_9 -> V_25 )
continue;
F_16 ( & V_9 -> V_57 ) ;
F_17 () ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
if ( ! F_18 ( V_9 ,
V_4 , V_36 , V_38 ,
V_46 , 1 ) )
V_55 = true ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_57 ) ;
F_20 () ;
break;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
} else {
V_49 = F_15 ( V_42 + 2 ) ;
F_4 ( & V_4 -> V_58 ) ;
F_5 (port, &dev->dev_sep_list,
sep_list) {
if ( V_7 -> V_29 != V_49 )
continue;
V_11 = V_7 -> V_32 ;
F_7 ( & V_4 -> V_58 ) ;
if ( ! F_21 (
V_11 , V_7 , 1 , 1 ) )
V_55 = true ;
F_4 ( & V_4 -> V_58 ) ;
break;
}
F_7 ( & V_4 -> V_58 ) ;
}
if ( ! V_55 ) {
V_43 = V_50 ;
goto V_52;
}
V_42 += 4 ;
V_45 += 4 ;
}
V_52:
F_9 ( V_2 ) ;
if ( ! V_43 )
F_10 ( V_2 , V_35 ) ;
return V_43 ;
}
static inline int F_22 (
struct V_1 * V_2 ,
unsigned char * V_59 ,
int V_60 ,
T_4 * V_61 )
{
V_2 -> V_62 |= V_63 ;
V_2 -> V_64 = V_60 ;
return 0 ;
}
static inline int F_23 (
struct V_1 * V_2 ,
unsigned char * V_59 ,
T_4 * V_61 )
{
switch ( V_59 [ 0 ] ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
return 0 ;
case V_73 :
switch ( V_59 [ 1 ] & 0x1f ) {
case V_74 :
return 0 ;
default:
* V_61 = V_75 ;
return 1 ;
}
case V_76 :
switch ( V_59 [ 1 ] ) {
case V_77 :
return 0 ;
default:
* V_61 = V_75 ;
return 1 ;
}
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return 0 ;
default:
* V_61 = V_75 ;
return 1 ;
}
return 0 ;
}
static inline int F_24 (
struct V_1 * V_2 ,
unsigned char * V_59 ,
T_4 * V_61 )
{
switch ( V_59 [ 0 ] ) {
case V_65 :
case V_70 :
return 0 ;
case V_73 :
switch ( V_59 [ 1 ] & 0x1f ) {
case V_74 :
return 0 ;
default:
* V_61 = V_83 ;
return 1 ;
}
case V_76 :
switch ( V_59 [ 1 ] ) {
case V_77 :
return 0 ;
default:
* V_61 = V_83 ;
return 1 ;
}
case V_78 :
case V_81 :
case V_82 :
return 0 ;
default:
* V_61 = V_83 ;
return 1 ;
}
return 0 ;
}
static inline int F_25 (
struct V_1 * V_2 ,
unsigned char * V_59 ,
T_4 * V_61 )
{
switch ( V_59 [ 0 ] ) {
case V_65 :
case V_70 :
return 0 ;
case V_73 :
switch ( V_59 [ 1 ] & 0x1f ) {
case V_74 :
return 0 ;
default:
* V_61 = V_84 ;
return 1 ;
}
case V_78 :
case V_81 :
case V_82 :
return 0 ;
default:
* V_61 = V_84 ;
return 1 ;
}
return 0 ;
}
T_1
F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_59 = V_2 -> V_16 ;
struct V_30 * V_85 = V_2 -> V_30 ;
struct V_6 * V_7 = V_85 -> V_31 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_86 , V_60 ;
T_4 V_61 ;
int V_87 ;
if ( V_4 -> V_88 -> V_89 & V_90 )
return 0 ;
if ( V_4 -> V_91 -> V_92 == V_93 )
return 0 ;
if ( ! V_7 )
return 0 ;
if ( F_6 ( & V_7 -> V_94 ) ) {
F_13 ( L_11
L_12 ) ;
V_61 = V_95 ;
V_87 = 1 ;
goto V_52;
}
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return 0 ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
V_86 = F_6 ( & V_9 -> V_24 ) ;
V_60 = V_9 -> V_96 ;
F_7 ( & V_11 -> V_33 ) ;
if ( V_86 == V_97 )
return 0 ;
switch ( V_86 ) {
case V_98 :
V_87 = F_22 ( V_2 , V_59 ,
V_60 , & V_61 ) ;
break;
case V_99 :
V_87 = F_23 ( V_2 , V_59 , & V_61 ) ;
break;
case V_100 :
V_87 = F_24 ( V_2 , V_59 , & V_61 ) ;
break;
case V_101 :
V_87 = F_25 ( V_2 , V_59 , & V_61 ) ;
break;
case V_102 :
default:
F_12 ( L_13 ,
V_86 ) ;
return V_18 ;
}
V_52:
if ( V_87 > 0 ) {
F_13 ( L_14
L_15
L_16 ,
V_2 -> V_103 -> V_104 () , V_61 ) ;
V_2 -> V_105 = 0x04 ;
V_2 -> V_106 = V_61 ;
return V_107 ;
}
return 0 ;
}
static T_1
F_14 ( int V_108 , int * V_47 )
{
switch ( V_108 ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
* V_47 = 1 ;
break;
case V_102 :
* V_47 = 0 ;
break;
default:
F_12 ( L_13 , V_108 ) ;
return V_50 ;
}
return 0 ;
}
static char * F_27 ( int V_108 )
{
switch ( V_108 ) {
case V_97 :
return L_17 ;
case V_98 :
return L_18 ;
case V_99 :
return L_19 ;
case V_100 :
return L_20 ;
case V_102 :
return L_21 ;
default:
return L_22 ;
}
return NULL ;
}
char * F_28 ( int V_109 )
{
switch ( V_109 ) {
case V_110 :
return L_23 ;
case V_111 :
return L_24 ;
case V_112 :
return L_25 ;
default:
return L_22 ;
}
return NULL ;
}
int F_29 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_62 & V_63 ) )
return 0 ;
if ( F_30 () )
return 0 ;
if ( ! V_2 -> V_64 )
return 0 ;
F_31 ( V_2 -> V_64 ) ;
return 0 ;
}
static int F_32 (
const char * V_113 ,
unsigned char * V_114 ,
T_2 V_115 )
{
struct V_116 * V_116 = F_33 ( V_113 , V_117 | V_118 | V_119 , 0600 ) ;
int V_87 ;
if ( F_34 ( V_116 ) ) {
F_12 ( L_26 , V_113 ) ;
return - V_120 ;
}
V_87 = F_35 ( V_116 , V_114 , V_115 , 0 ) ;
if ( V_87 < 0 )
F_12 ( L_27 , V_113 ) ;
F_36 ( V_116 ) ;
return ( V_87 < 0 ) ? - V_121 : 0 ;
}
static int F_37 (
struct V_8 * V_9 ,
int V_122 ,
unsigned char * V_114 )
{
struct V_123 * V_124 = & V_9 -> V_125 -> V_123 ;
char V_113 [ V_126 ] ;
int V_45 ;
memset ( V_113 , 0 , V_126 ) ;
V_45 = snprintf ( V_114 , V_9 -> V_127 ,
L_28
L_29
L_30 ,
V_9 -> V_25 , V_122 ,
V_9 -> V_26 ) ;
snprintf ( V_113 , V_126 ,
L_31 , & V_124 -> V_128 [ 0 ] ,
F_38 ( & V_9 -> V_129 . V_130 ) ) ;
return F_32 ( V_113 , V_114 , V_45 ) ;
}
static int F_39 (
struct V_8 * V_9 ,
struct V_6 * V_36 ,
struct V_37 * V_38 ,
unsigned char * V_114 ,
int V_131 ,
int V_132 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_6 * V_7 ;
struct V_10 * V_137 ;
int V_138 = 0 ;
V_138 = F_6 ( & V_9 -> V_24 ) ;
F_40 ( & V_9 -> V_24 ,
V_101 ) ;
V_9 -> V_26 = ( V_132 ) ?
V_111 :
V_112 ;
if ( V_9 -> V_139 != 0 )
F_31 ( V_9 -> V_139 ) ;
F_4 ( & V_9 -> V_27 ) ;
F_5 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_137 -> V_28 ;
F_16 ( & V_137 -> V_140 ) ;
F_17 () ;
F_7 ( & V_9 -> V_27 ) ;
F_41 ( & V_7 -> V_141 ) ;
F_5 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_136 = V_134 -> V_135 ;
if ( ! V_136 )
continue;
if ( V_132 &&
( V_38 != NULL ) && ( V_38 == V_136 -> V_142 ) &&
( V_36 != NULL ) && ( V_36 == V_7 ) )
continue;
F_42 ( V_136 -> V_142 ,
V_134 -> V_143 , 0x2A ,
V_144 ) ;
}
F_43 ( & V_7 -> V_141 ) ;
F_4 ( & V_9 -> V_27 ) ;
F_19 ( & V_137 -> V_140 ) ;
F_20 () ;
}
F_7 ( & V_9 -> V_27 ) ;
if ( V_9 -> V_145 ) {
F_44 ( & V_9 -> V_146 ) ;
F_37 ( V_9 ,
V_131 , V_114 ) ;
F_45 ( & V_9 -> V_146 ) ;
}
F_40 ( & V_9 -> V_24 , V_131 ) ;
F_13 ( L_32
L_33 , ( V_132 ) ? L_34 :
L_35 , F_38 ( & V_9 -> V_129 . V_130 ) ,
V_9 -> V_25 , F_27 ( V_138 ) ,
F_27 ( V_131 ) ) ;
return 0 ;
}
int F_18 (
struct V_8 * V_40 ,
struct V_3 * V_147 ,
struct V_6 * V_36 ,
struct V_37 * V_148 ,
int V_131 ,
int V_132 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_149 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_8 * V_9 ;
unsigned char * V_114 ;
int V_47 ;
if ( F_14 ( V_131 , & V_47 ) != 0 )
return - V_154 ;
V_114 = F_46 ( V_40 -> V_127 , V_155 ) ;
if ( ! V_114 ) {
F_12 ( L_36 ) ;
return - V_156 ;
}
V_153 = V_147 -> V_157 ;
F_4 ( & V_153 -> V_158 ) ;
V_150 = V_153 -> V_150 ;
F_16 ( & V_150 -> V_159 ) ;
F_17 () ;
F_7 ( & V_153 -> V_158 ) ;
if ( ! V_150 -> V_160 ) {
F_39 ( V_40 , V_36 , V_148 ,
V_114 , V_131 , V_132 ) ;
F_19 ( & V_150 -> V_159 ) ;
F_20 () ;
F_47 ( V_114 ) ;
return 0 ;
}
F_4 ( & V_150 -> V_161 ) ;
F_5 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_152 -> V_162 ;
F_16 ( & V_152 -> V_163 ) ;
F_17 () ;
F_7 ( & V_150 -> V_161 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_56 )
continue;
if ( V_40 -> V_25 != V_9 -> V_25 )
continue;
if ( V_40 == V_9 ) {
V_7 = V_36 ;
V_38 = V_148 ;
} else {
V_7 = NULL ;
V_38 = NULL ;
}
F_16 ( & V_9 -> V_57 ) ;
F_17 () ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_39 ( V_9 , V_7 ,
V_38 , V_114 , V_131 , V_132 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_57 ) ;
F_20 () ;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_4 ( & V_150 -> V_161 ) ;
F_19 ( & V_152 -> V_163 ) ;
F_20 () ;
}
F_7 ( & V_150 -> V_161 ) ;
F_13 ( L_37
L_38 ,
F_38 ( & V_150 -> V_164 . V_130 ) ,
V_40 -> V_25 , ( V_132 ) ? L_34 : L_35 ,
F_27 ( V_131 ) ) ;
F_19 ( & V_150 -> V_159 ) ;
F_20 () ;
F_47 ( V_114 ) ;
return 0 ;
}
static int F_48 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
unsigned char * V_114 ,
T_2 V_115 )
{
struct V_165 * V_166 = V_7 -> V_167 ;
char V_113 [ V_126 ] , V_124 [ V_168 ] ;
int V_45 ;
memset ( V_113 , 0 , V_126 ) ;
memset ( V_124 , 0 , V_168 ) ;
V_45 = snprintf ( V_124 , V_168 , L_39 ,
V_166 -> V_169 -> V_170 ( V_166 ) ) ;
if ( V_166 -> V_169 -> V_171 != NULL )
snprintf ( V_124 + V_45 , V_168 - V_45 , L_40 ,
V_166 -> V_169 -> V_171 ( V_166 ) ) ;
V_45 = snprintf ( V_114 , V_115 , L_41
L_42 ,
F_6 ( & V_7 -> V_94 ) ,
V_7 -> V_172 ) ;
snprintf ( V_113 , V_126 , L_43 ,
V_166 -> V_169 -> V_104 () , V_124 ,
V_7 -> V_173 -> V_174 ) ;
return F_32 ( V_113 , V_114 , V_45 ) ;
}
static int F_21 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
int V_132 ,
int V_175 )
{
struct V_8 * V_9 ;
unsigned char * V_114 ;
T_2 V_115 ;
int V_176 ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( ! V_9 ) {
F_7 ( & V_11 -> V_33 ) ;
F_12 ( L_44
L_45 ) ;
return - V_154 ;
}
V_176 = V_9 -> V_139 ;
if ( V_175 )
F_40 ( & V_7 -> V_94 , 1 ) ;
else
F_40 ( & V_7 -> V_94 , 0 ) ;
V_115 = V_9 -> V_127 ;
V_7 -> V_172 = ( V_132 ) ?
V_111 :
V_112 ;
F_13 ( L_32
L_46 , ( V_132 ) ? L_34 :
L_35 , F_38 ( & V_9 -> V_129 . V_130 ) ,
V_9 -> V_25 , ( V_175 ) ? L_47 : L_48 ) ;
F_7 ( & V_11 -> V_33 ) ;
if ( V_176 != 0 )
F_31 ( V_176 ) ;
if ( V_7 -> V_177 ) {
V_114 = F_46 ( V_115 , V_155 ) ;
if ( ! V_114 ) {
F_12 ( L_49
L_50 ) ;
return - V_156 ;
}
F_44 ( & V_7 -> V_178 ) ;
F_48 ( V_11 , V_7 ,
V_114 , V_115 ) ;
F_45 ( & V_7 -> V_178 ) ;
F_47 ( V_114 ) ;
}
return 0 ;
}
struct V_149 *
F_49 ( const char * V_179 , int V_180 )
{
struct V_149 * V_150 ;
V_150 = F_50 ( V_181 , V_155 ) ;
if ( ! V_150 ) {
F_12 ( L_51 ) ;
return F_51 ( - V_156 ) ;
}
F_52 ( & V_150 -> V_182 ) ;
F_52 ( & V_150 -> V_183 ) ;
F_53 ( & V_150 -> V_161 ) ;
F_40 ( & V_150 -> V_159 , 0 ) ;
if ( V_180 ) {
V_150 -> V_160 = V_184 ++ ;
V_150 -> V_185 = 1 ;
V_186 ++ ;
}
return V_150 ;
}
int F_54 ( struct V_149 * V_150 , T_3 V_160 )
{
struct V_149 * V_187 ;
T_3 V_188 ;
if ( V_150 -> V_185 ) {
F_2 ( L_52
L_53 ) ;
return - V_154 ;
}
F_4 ( & V_189 ) ;
if ( V_186 == 0x0000ffff ) {
F_12 ( L_54
L_55 ) ;
F_7 ( & V_189 ) ;
F_55 ( V_181 , V_150 ) ;
return - V_190 ;
}
V_191:
V_188 = ( V_160 != 0 ) ? V_160 :
V_184 ++ ;
F_5 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_187 -> V_160 == V_188 ) {
if ( ! V_160 )
goto V_191;
F_2 ( L_56
L_57 ,
V_160 ) ;
F_7 ( & V_189 ) ;
return - V_154 ;
}
}
V_150 -> V_160 = V_188 ;
V_150 -> V_185 = 1 ;
F_56 ( & V_150 -> V_182 , & V_192 ) ;
V_186 ++ ;
F_7 ( & V_189 ) ;
return 0 ;
}
static struct V_151 *
F_57 ( struct V_3 * V_4 )
{
struct V_151 * V_152 ;
V_152 = F_50 ( V_193 , V_155 ) ;
if ( ! V_152 ) {
F_12 ( L_58 ) ;
return F_51 ( - V_156 ) ;
}
F_52 ( & V_152 -> V_183 ) ;
F_53 ( & V_152 -> V_158 ) ;
F_40 ( & V_152 -> V_163 , 0 ) ;
V_152 -> V_162 = V_4 ;
V_4 -> V_157 = V_152 ;
return V_152 ;
}
void F_58 ( struct V_149 * V_150 )
{
struct V_151 * V_152 , * V_194 ;
F_4 ( & V_189 ) ;
F_59 ( & V_150 -> V_182 ) ;
V_186 -- ;
F_7 ( & V_189 ) ;
while ( F_6 ( & V_150 -> V_159 ) )
F_60 () ;
F_4 ( & V_150 -> V_161 ) ;
F_61 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_152 -> V_195 ) {
F_59 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_161 ) ;
F_4 ( & V_152 -> V_158 ) ;
if ( V_150 != V_197 )
F_62 ( V_152 ,
V_197 ) ;
else
V_152 -> V_150 = NULL ;
F_7 ( & V_152 -> V_158 ) ;
F_4 ( & V_150 -> V_161 ) ;
}
F_7 ( & V_150 -> V_161 ) ;
F_55 ( V_181 , V_150 ) ;
}
void F_63 ( struct V_3 * V_4 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
V_152 = V_4 -> V_157 ;
if ( ! V_152 )
return;
while ( F_6 ( & V_152 -> V_163 ) )
F_60 () ;
F_4 ( & V_152 -> V_158 ) ;
V_150 = V_152 -> V_150 ;
if ( V_150 ) {
F_4 ( & V_150 -> V_161 ) ;
if ( V_152 -> V_195 ) {
F_59 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_161 ) ;
V_152 -> V_150 = NULL ;
}
F_7 ( & V_152 -> V_158 ) ;
F_55 ( V_193 , V_152 ) ;
}
struct V_149 * F_64 ( const char * V_179 )
{
struct V_149 * V_150 ;
struct V_198 * V_199 ;
F_4 ( & V_189 ) ;
F_5 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_150 -> V_185 )
continue;
V_199 = & V_150 -> V_164 . V_130 ;
if ( ! strcmp ( F_38 ( V_199 ) , V_179 ) ) {
F_16 ( & V_150 -> V_159 ) ;
F_7 ( & V_189 ) ;
return V_150 ;
}
}
F_7 ( & V_189 ) ;
return NULL ;
}
void F_65 ( struct V_149 * V_150 )
{
F_4 ( & V_189 ) ;
F_19 ( & V_150 -> V_159 ) ;
F_7 ( & V_189 ) ;
}
void F_62 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_161 ) ;
V_152 -> V_150 = V_150 ;
V_152 -> V_195 = 1 ;
F_56 ( & V_152 -> V_183 , & V_150 -> V_183 ) ;
V_150 -> V_196 ++ ;
F_7 ( & V_150 -> V_161 ) ;
}
void F_66 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_161 ) ;
F_59 ( & V_152 -> V_183 ) ;
V_152 -> V_150 = NULL ;
V_152 -> V_195 = 0 ;
V_150 -> V_196 -- ;
F_7 ( & V_150 -> V_161 ) ;
}
struct V_8 * F_67 ( struct V_3 * V_4 ,
const char * V_179 , int V_180 )
{
struct V_8 * V_9 ;
V_9 = F_50 ( V_200 , V_155 ) ;
if ( ! V_9 ) {
F_12 ( L_59 ) ;
return NULL ;
}
F_52 ( & V_9 -> V_201 ) ;
F_52 ( & V_9 -> V_202 ) ;
F_68 ( & V_9 -> V_146 ) ;
F_53 ( & V_9 -> V_27 ) ;
F_40 ( & V_9 -> V_57 , 0 ) ;
V_9 -> V_125 = V_4 ;
V_9 -> V_127 = V_203 ;
F_40 ( & V_9 -> V_24 ,
V_97 ) ;
V_9 -> V_53 =
V_54 | V_204 ;
V_9 -> V_96 = V_205 ;
V_9 -> V_139 = V_206 ;
V_9 -> V_34 = V_207 ;
if ( V_180 ) {
F_4 ( & V_4 -> V_20 . V_21 ) ;
V_9 -> V_25 =
V_4 -> V_20 . V_208 ++ ;
V_9 -> V_56 = 1 ;
V_4 -> V_20 . V_209 ++ ;
F_56 ( & V_9 -> V_201 ,
& V_4 -> V_20 . V_210 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
return V_9 ;
}
int F_69 (
struct V_8 * V_9 ,
T_3 V_25 )
{
struct V_3 * V_4 = V_9 -> V_125 ;
struct V_8 * V_211 ;
T_3 V_212 ;
if ( V_9 -> V_56 ) {
F_2 ( L_60
L_53 ) ;
return - V_154 ;
}
F_4 ( & V_4 -> V_20 . V_21 ) ;
if ( V_4 -> V_20 . V_209 == 0x0000ffff ) {
F_12 ( L_61
L_55 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_55 ( V_200 , V_9 ) ;
return - V_190 ;
}
V_191:
V_212 = ( V_25 != 0 ) ? V_25 :
V_4 -> V_20 . V_208 ++ ;
F_5 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_211 -> V_25 == V_212 ) {
if ( ! V_25 )
goto V_191;
F_12 ( L_62
L_63 , V_25 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return - V_154 ;
}
}
V_9 -> V_25 = V_212 ;
V_9 -> V_56 = 1 ;
F_56 ( & V_9 -> V_201 ,
& V_4 -> V_20 . V_210 ) ;
V_4 -> V_20 . V_209 ++ ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return 0 ;
}
struct V_10 * F_70 (
struct V_6 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_50 ( V_213 ,
V_155 ) ;
if ( ! V_11 ) {
F_12 ( L_64 ) ;
return F_51 ( - V_156 ) ;
}
F_52 ( & V_11 -> V_202 ) ;
F_53 ( & V_11 -> V_33 ) ;
F_40 ( & V_11 -> V_140 , 0 ) ;
V_11 -> V_28 = V_7 ;
V_7 -> V_32 = V_11 ;
return V_11 ;
}
void F_71 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_125 ;
struct V_10 * V_11 , * V_214 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_59 ( & V_9 -> V_201 ) ;
V_4 -> V_20 . V_208 -- ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
while ( F_6 ( & V_9 -> V_57 ) )
F_60 () ;
F_4 ( & V_9 -> V_27 ) ;
F_61 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_11 -> V_215 ) {
F_59 ( & V_11 -> V_202 ) ;
V_9 -> V_22 -- ;
V_11 -> V_215 = 0 ;
}
F_7 ( & V_9 -> V_27 ) ;
F_4 ( & V_11 -> V_33 ) ;
if ( V_9 != V_4 -> V_20 . V_216 ) {
F_72 ( V_11 ,
V_4 -> V_20 . V_216 ) ;
} else
V_11 -> V_9 = NULL ;
F_7 ( & V_11 -> V_33 ) ;
F_4 ( & V_9 -> V_27 ) ;
}
F_7 ( & V_9 -> V_27 ) ;
F_55 ( V_200 , V_9 ) ;
}
void F_73 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return;
while ( F_6 ( & V_11 -> V_140 ) )
F_60 () ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
F_4 ( & V_9 -> V_27 ) ;
if ( V_11 -> V_215 ) {
F_59 ( & V_11 -> V_202 ) ;
V_9 -> V_22 -- ;
V_11 -> V_215 = 0 ;
}
F_7 ( & V_9 -> V_27 ) ;
V_11 -> V_9 = NULL ;
}
F_7 ( & V_11 -> V_33 ) ;
F_55 ( V_213 , V_11 ) ;
}
static struct V_8 * F_74 (
struct V_3 * V_4 , const char * V_179 )
{
struct V_8 * V_9 ;
struct V_198 * V_199 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_56 )
continue;
V_199 = & V_9 -> V_129 . V_130 ;
if ( ! strcmp ( F_38 ( V_199 ) , V_179 ) ) {
F_16 ( & V_9 -> V_57 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return V_9 ;
}
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
return NULL ;
}
static void F_75 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_125 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_57 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
void F_72 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_27 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_215 = 1 ;
F_56 ( & V_11 -> V_202 ,
& V_9 -> V_202 ) ;
V_9 -> V_22 ++ ;
F_7 ( & V_9 -> V_27 ) ;
}
static void F_76 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_27 ) ;
F_59 ( & V_11 -> V_202 ) ;
V_11 -> V_9 = NULL ;
V_11 -> V_215 = 0 ;
V_9 -> V_22 -- ;
F_7 ( & V_9 -> V_27 ) ;
}
T_5 F_77 ( struct V_6 * V_7 , char * V_217 )
{
struct V_198 * V_218 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_5 V_45 = 0 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return V_45 ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
V_218 = & V_9 -> V_129 . V_130 ;
V_45 += sprintf ( V_217 , L_65
L_66
L_67
L_68 ,
F_38 ( V_218 ) , V_9 -> V_25 ,
F_27 ( F_6 (
& V_9 -> V_24 ) ) ,
F_28 (
V_9 -> V_26 ) ,
( F_6 ( & V_7 -> V_94 ) ) ?
L_21 : L_23 ,
F_28 ( V_7 -> V_172 ) ) ;
}
F_7 ( & V_11 -> V_33 ) ;
return V_45 ;
}
T_5 F_78 (
struct V_6 * V_7 ,
const char * V_217 ,
T_6 V_219 )
{
struct V_165 * V_220 ;
struct V_30 * V_85 ;
struct V_3 * V_4 = V_7 -> V_173 -> V_221 ;
struct V_8 * V_9 = NULL , * V_222 = NULL ;
struct V_10 * V_11 ;
unsigned char V_12 [ V_223 ] ;
int V_224 = 0 ;
V_220 = V_7 -> V_167 ;
V_85 = V_7 -> V_173 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return 0 ;
if ( V_219 > V_223 ) {
F_12 ( L_69 ) ;
return - V_154 ;
}
memset ( V_12 , 0 , V_223 ) ;
memcpy ( V_12 , V_217 , V_219 ) ;
if ( strcmp ( F_79 ( V_12 ) , L_70 ) ) {
V_222 = F_74 ( V_4 ,
F_79 ( V_12 ) ) ;
if ( ! V_222 )
return - V_120 ;
}
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
if ( ! V_222 ) {
F_13 ( L_71
L_72
L_73
L_74 ,
V_220 -> V_169 -> V_170 ( V_220 ) ,
V_220 -> V_169 -> V_171 ( V_220 ) ,
F_38 ( & V_85 -> V_225 . V_130 ) ,
F_38 (
& V_9 -> V_129 . V_130 ) ,
V_9 -> V_25 ) ;
F_76 ( V_11 , V_9 ) ;
F_72 ( V_11 ,
V_4 -> V_20 . V_216 ) ;
F_7 ( & V_11 -> V_33 ) ;
return V_219 ;
}
F_76 ( V_11 , V_9 ) ;
V_224 = 1 ;
}
F_72 ( V_11 , V_222 ) ;
F_7 ( & V_11 -> V_33 ) ;
F_13 ( L_75
L_76 , ( V_224 ) ?
L_77 : L_78 , V_220 -> V_169 -> V_170 ( V_220 ) ,
V_220 -> V_169 -> V_171 ( V_220 ) ,
F_38 ( & V_85 -> V_225 . V_130 ) ,
F_38 ( & V_222 -> V_129 . V_130 ) ,
V_222 -> V_25 ) ;
F_75 ( V_222 ) ;
return V_219 ;
}
T_5 F_80 (
struct V_8 * V_9 ,
char * V_217 )
{
if ( ( V_9 -> V_53 & V_54 ) &&
( V_9 -> V_53 & V_204 ) )
return sprintf ( V_217 , L_79 ) ;
else if ( V_9 -> V_53 & V_204 )
return sprintf ( V_217 , L_80 ) ;
else if ( V_9 -> V_53 & V_54 )
return sprintf ( V_217 , L_81 ) ;
else
return sprintf ( V_217 , L_82 ) ;
}
T_5 F_81 (
struct V_8 * V_9 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_83 ) ;
return V_87 ;
}
if ( ( V_226 != 0 ) && ( V_226 != 1 ) && ( V_226 != 2 ) && ( V_226 != 3 ) ) {
F_12 ( L_84
L_85 , V_226 ) ;
return - V_154 ;
}
if ( V_226 == 3 )
V_9 -> V_53 =
V_204 | V_54 ;
else if ( V_226 == 2 )
V_9 -> V_53 = V_54 ;
else if ( V_226 == 1 )
V_9 -> V_53 = V_204 ;
else
V_9 -> V_53 = 0 ;
return V_219 ;
}
T_5 F_83 (
struct V_8 * V_9 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 , V_9 -> V_96 ) ;
}
T_5 F_84 (
struct V_8 * V_9 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_87 ) ;
return V_87 ;
}
if ( V_226 > V_227 ) {
F_12 ( L_88
L_89 , V_226 ,
V_227 ) ;
return - V_154 ;
}
V_9 -> V_96 = ( int ) V_226 ;
return V_219 ;
}
T_5 F_85 (
struct V_8 * V_9 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 , V_9 -> V_139 ) ;
}
T_5 F_86 (
struct V_8 * V_9 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_90 ) ;
return V_87 ;
}
if ( V_226 > V_228 ) {
F_12 ( L_91
L_92 , V_226 ,
V_228 ) ;
return - V_154 ;
}
V_9 -> V_139 = ( int ) V_226 ;
return V_219 ;
}
T_5 F_87 (
struct V_8 * V_9 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 , V_9 -> V_34 ) ;
}
T_5 F_88 (
struct V_8 * V_9 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_93 ) ;
return V_87 ;
}
if ( V_226 > V_229 ) {
F_12 ( L_94
L_95 , V_226 ,
V_229 ) ;
return - V_154 ;
}
V_9 -> V_34 = ( int ) V_226 ;
return V_219 ;
}
T_5 F_89 (
struct V_8 * V_9 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 , V_9 -> V_23 ) ;
}
T_5 F_90 (
struct V_8 * V_9 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_96 ) ;
return V_87 ;
}
if ( ( V_226 != 0 ) && ( V_226 != 1 ) ) {
F_12 ( L_97 , V_226 ) ;
return - V_154 ;
}
V_9 -> V_23 = ( int ) V_226 ;
return V_219 ;
}
T_5 F_91 ( struct V_30 * V_85 , char * V_217 )
{
if ( ! V_85 -> V_31 )
return - V_120 ;
return sprintf ( V_217 , L_86 ,
F_6 ( & V_85 -> V_31 -> V_94 ) ) ;
}
T_5 F_92 (
struct V_30 * V_85 ,
const char * V_217 ,
T_6 V_219 )
{
struct V_10 * V_11 ;
unsigned long V_226 ;
int V_87 ;
if ( ! V_85 -> V_31 )
return - V_120 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_98 ) ;
return V_87 ;
}
if ( ( V_226 != 0 ) && ( V_226 != 1 ) ) {
F_12 ( L_99 ,
V_226 ) ;
return - V_154 ;
}
V_11 = V_85 -> V_31 -> V_32 ;
if ( ! V_11 ) {
F_12 ( L_100 ) ;
return - V_154 ;
}
V_87 = F_21 ( V_11 ,
V_85 -> V_31 , 0 , ( int ) V_226 ) ;
if ( V_87 < 0 )
return - V_154 ;
return V_219 ;
}
T_5 F_93 (
struct V_30 * V_85 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 , V_85 -> V_31 -> V_172 ) ;
}
T_5 F_94 (
struct V_30 * V_85 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_101 ) ;
return V_87 ;
}
if ( ( V_226 != V_110 ) &&
( V_226 != V_111 ) &&
( V_226 != V_112 ) ) {
F_12 ( L_102 ,
V_226 ) ;
return - V_154 ;
}
V_85 -> V_31 -> V_172 = ( int ) V_226 ;
return V_219 ;
}
T_5 F_95 (
struct V_30 * V_85 ,
char * V_217 )
{
return sprintf ( V_217 , L_86 ,
V_85 -> V_31 -> V_177 ) ;
}
T_5 F_96 (
struct V_30 * V_85 ,
const char * V_217 ,
T_6 V_219 )
{
unsigned long V_226 ;
int V_87 ;
V_87 = F_82 ( V_217 , 0 , & V_226 ) ;
if ( V_87 < 0 ) {
F_12 ( L_103 ) ;
return V_87 ;
}
if ( ( V_226 != 0 ) && ( V_226 != 1 ) ) {
F_12 ( L_104
L_85 , V_226 ) ;
return - V_154 ;
}
V_85 -> V_31 -> V_177 = ( int ) V_226 ;
return V_219 ;
}
int F_97 ( struct V_3 * V_4 )
{
if ( V_4 -> V_91 -> V_92 != V_93 &&
! ( V_4 -> V_88 -> V_89 & V_90 ) ) {
struct V_151 * V_152 ;
V_152 = F_57 ( V_4 ) ;
if ( F_34 ( V_152 ) )
return F_98 ( V_152 ) ;
F_4 ( & V_152 -> V_158 ) ;
F_62 ( V_152 ,
V_197 ) ;
F_7 ( & V_152 -> V_158 ) ;
F_13 ( L_105
L_106 ,
V_4 -> V_91 -> V_179 ) ;
}
return 0 ;
}
