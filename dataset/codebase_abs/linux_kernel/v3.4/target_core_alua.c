int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned char * V_16 ;
T_1 V_17 = 0 , V_18 = 4 ;
if ( V_4 -> V_19 < 4 ) {
F_2 ( L_1
L_2 , V_4 -> V_19 ) ;
return - V_20 ;
}
V_16 = F_3 ( V_4 ) ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_5 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ( V_18 + 8 + ( V_13 -> V_23 * 4 ) ) >
V_4 -> V_19 ) {
V_17 += 8 + ( V_13 -> V_23 * 4 ) ;
continue;
}
if ( V_13 -> V_24 )
V_16 [ V_18 ] = 0x80 ;
V_16 [ V_18 ++ ] |= ( F_6 (
& V_13 -> V_25 ) & 0xff ) ;
V_16 [ V_18 ] = 0x80 ;
V_16 [ V_18 ] |= 0x40 ;
V_16 [ V_18 ] |= 0x8 ;
V_16 [ V_18 ] |= 0x4 ;
V_16 [ V_18 ] |= 0x2 ;
V_16 [ V_18 ++ ] |= 0x1 ;
V_16 [ V_18 ++ ] = ( ( V_13 -> V_26 >> 8 ) & 0xff ) ;
V_16 [ V_18 ++ ] = ( V_13 -> V_26 & 0xff ) ;
V_18 ++ ;
V_16 [ V_18 ++ ] = ( V_13 -> V_27 & 0xff ) ;
V_16 [ V_18 ++ ] = 0x00 ;
V_16 [ V_18 ++ ] = ( V_13 -> V_23 & 0xff ) ;
V_17 += 8 ;
F_4 ( & V_13 -> V_28 ) ;
F_5 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_11 = V_15 -> V_29 ;
V_18 += 2 ;
V_16 [ V_18 ++ ] = ( ( V_11 -> V_30 >> 8 ) & 0xff ) ;
V_16 [ V_18 ++ ] = ( V_11 -> V_30 & 0xff ) ;
V_17 += 4 ;
}
F_7 ( & V_13 -> V_28 ) ;
}
F_7 ( & V_7 -> V_21 . V_22 ) ;
V_16 [ 0 ] = ( ( V_17 >> 24 ) & 0xff ) ;
V_16 [ 1 ] = ( ( V_17 >> 16 ) & 0xff ) ;
V_16 [ 2 ] = ( ( V_17 >> 8 ) & 0xff ) ;
V_16 [ 3 ] = ( V_17 & 0xff ) ;
F_8 ( V_4 ) ;
V_2 -> V_31 = V_32 ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = V_4 -> V_8 ;
struct V_6 * V_7 = V_34 -> V_9 ;
struct V_10 * V_11 , * V_35 = V_4 -> V_36 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_40 -> V_38 ;
struct V_12 * V_13 = NULL , * V_41 ;
struct V_14 * V_15 , * V_42 ;
unsigned char * V_16 ;
unsigned char * V_43 ;
T_1 V_44 = 4 ;
int V_45 , V_46 = 0 , V_47 ;
T_2 V_48 , V_49 ;
if ( ! V_35 ) {
V_4 -> V_50 = V_51 ;
return - V_20 ;
}
V_16 = F_3 ( V_4 ) ;
V_42 = V_35 -> V_52 ;
if ( ! V_42 ) {
F_11 ( L_3 ) ;
V_4 -> V_50 = V_53 ;
V_47 = - V_20 ;
goto V_54;
}
F_4 ( & V_42 -> V_55 ) ;
V_41 = V_42 -> V_13 ;
if ( ! V_41 ) {
F_7 ( & V_42 -> V_55 ) ;
F_11 ( L_4 ) ;
V_4 -> V_50 = V_53 ;
V_47 = - V_20 ;
goto V_54;
}
V_47 = ( V_41 -> V_56 & V_57 ) ;
F_7 ( & V_42 -> V_55 ) ;
if ( ! V_47 ) {
F_12 ( L_5
L_6 ) ;
V_4 -> V_50 = V_53 ;
V_47 = - V_20 ;
goto V_54;
}
V_43 = & V_16 [ 4 ] ;
while ( V_44 < V_4 -> V_19 ) {
V_45 = ( V_43 [ 0 ] & 0x0f ) ;
V_47 = F_13 ( V_45 , & V_46 ) ;
if ( V_47 != 0 ) {
V_4 -> V_50 = V_58 ;
V_47 = - V_20 ;
goto V_54;
}
V_47 = - 1 ;
if ( V_46 ) {
V_48 = F_14 ( V_43 + 2 ) ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_5 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_13 -> V_59 )
continue;
if ( V_48 != V_13 -> V_26 )
continue;
F_15 ( & V_13 -> V_60 ) ;
F_16 () ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
V_47 = F_17 ( V_13 ,
V_34 , V_35 , V_39 ,
V_45 , 1 ) ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_18 ( & V_13 -> V_60 ) ;
F_19 () ;
break;
}
F_7 ( & V_7 -> V_21 . V_22 ) ;
if ( V_47 != 0 ) {
V_4 -> V_50 = V_58 ;
V_47 = - V_20 ;
goto V_54;
}
} else {
V_49 = F_14 ( V_43 + 2 ) ;
F_4 ( & V_34 -> V_61 ) ;
F_5 (port, &dev->dev_sep_list,
sep_list) {
if ( V_11 -> V_30 != V_49 )
continue;
V_15 = V_11 -> V_52 ;
F_7 ( & V_34 -> V_61 ) ;
V_47 = F_20 (
V_15 , V_11 , 1 , 1 ) ;
F_4 ( & V_34 -> V_61 ) ;
break;
}
F_7 ( & V_34 -> V_61 ) ;
if ( V_47 != 0 ) {
V_4 -> V_50 = V_58 ;
V_47 = - V_20 ;
goto V_54;
}
}
V_43 += 4 ;
V_44 += 4 ;
}
V_54:
F_8 ( V_4 ) ;
V_2 -> V_31 = V_32 ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static inline int F_21 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
int V_63 ,
T_3 * V_64 )
{
V_4 -> V_65 |= V_66 ;
V_4 -> V_67 = V_63 ;
return 0 ;
}
static inline int F_22 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
switch ( V_62 [ 0 ] ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
switch ( V_62 [ 1 ] ) {
case V_77 :
return 0 ;
default:
* V_64 = V_78 ;
return 1 ;
}
case V_79 :
switch ( V_62 [ 1 ] ) {
case V_80 :
return 0 ;
default:
* V_64 = V_78 ;
return 1 ;
}
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
return 0 ;
default:
* V_64 = V_78 ;
return 1 ;
}
return 0 ;
}
static inline int F_23 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
switch ( V_62 [ 0 ] ) {
case V_68 :
case V_73 :
case V_76 :
switch ( V_62 [ 1 ] ) {
case V_77 :
return 0 ;
default:
* V_64 = V_86 ;
return 1 ;
}
case V_79 :
switch ( V_62 [ 1 ] ) {
case V_80 :
return 0 ;
default:
* V_64 = V_86 ;
return 1 ;
}
case V_81 :
case V_84 :
case V_85 :
return 0 ;
default:
* V_64 = V_86 ;
return 1 ;
}
return 0 ;
}
static inline int F_24 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
switch ( V_62 [ 0 ] ) {
case V_68 :
case V_73 :
case V_76 :
switch ( V_62 [ 1 ] ) {
case V_77 :
return 0 ;
default:
* V_64 = V_87 ;
return 1 ;
}
case V_81 :
case V_84 :
case V_85 :
return 0 ;
default:
* V_64 = V_87 ;
return 1 ;
}
return 0 ;
}
static int F_25 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
return 0 ;
}
static int F_26 (
struct V_3 * V_4 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
struct V_36 * V_88 = V_4 -> V_36 ;
struct V_10 * V_11 = V_88 -> V_37 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_89 , V_63 ;
if ( ! V_11 )
return 0 ;
if ( F_6 ( & V_11 -> V_90 ) ) {
* V_64 = V_91 ;
F_12 ( L_7
L_8 ) ;
* V_64 = V_91 ;
return 1 ;
}
V_15 = V_11 -> V_52 ;
F_4 ( & V_15 -> V_55 ) ;
V_13 = V_15 -> V_13 ;
V_89 = F_6 ( & V_13 -> V_25 ) ;
V_63 = V_13 -> V_92 ;
F_7 ( & V_15 -> V_55 ) ;
if ( V_89 == V_93 )
return 0 ;
switch ( V_89 ) {
case V_94 :
return F_21 ( V_4 , V_62 ,
V_63 , V_64 ) ;
case V_95 :
return F_22 ( V_4 , V_62 , V_64 ) ;
case V_96 :
return F_23 ( V_4 , V_62 , V_64 ) ;
case V_97 :
return F_24 ( V_4 , V_62 , V_64 ) ;
case V_98 :
default:
F_11 ( L_9 ,
V_89 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_13 ( int V_99 , int * V_46 )
{
switch ( V_99 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
* V_46 = 1 ;
break;
case V_98 :
* V_46 = 0 ;
break;
default:
F_11 ( L_9 , V_99 ) ;
return - V_20 ;
}
return 0 ;
}
static char * F_27 ( int V_99 )
{
switch ( V_99 ) {
case V_93 :
return L_10 ;
case V_94 :
return L_11 ;
case V_95 :
return L_12 ;
case V_96 :
return L_13 ;
case V_98 :
return L_14 ;
default:
return L_15 ;
}
return NULL ;
}
char * F_28 ( int V_100 )
{
switch ( V_100 ) {
case V_101 :
return L_16 ;
case V_102 :
return L_17 ;
case V_103 :
return L_18 ;
default:
return L_15 ;
}
return NULL ;
}
int F_29 (
struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_65 & V_66 ) )
return 0 ;
if ( F_30 () )
return 0 ;
if ( ! V_4 -> V_67 )
return 0 ;
F_31 ( V_4 -> V_67 ) ;
return 0 ;
}
static int F_32 (
const char * V_104 ,
unsigned char * V_105 ,
T_1 V_106 )
{
T_4 V_107 ;
struct V_108 * V_108 ;
struct V_109 V_110 [ 1 ] ;
int V_111 = V_112 | V_113 | V_114 , V_115 ;
memset ( V_110 , 0 , sizeof( struct V_109 ) ) ;
V_108 = F_33 ( V_104 , V_111 , 0600 ) ;
if ( F_34 ( V_108 ) || ! V_108 || ! V_108 -> V_116 ) {
F_11 ( L_19 ,
V_104 ) ;
return - V_117 ;
}
V_110 [ 0 ] . V_118 = & V_105 [ 0 ] ;
V_110 [ 0 ] . V_119 = V_106 ;
V_107 = F_35 () ;
F_36 ( F_37 () ) ;
V_115 = F_38 ( V_108 , & V_110 [ 0 ] , 1 , & V_108 -> V_120 ) ;
F_36 ( V_107 ) ;
if ( V_115 < 0 ) {
F_11 ( L_20 , V_104 ) ;
F_39 ( V_108 , NULL ) ;
return - V_121 ;
}
F_39 ( V_108 , NULL ) ;
return 0 ;
}
static int F_40 (
struct V_12 * V_13 ,
int V_122 ,
unsigned char * V_105 )
{
struct V_6 * V_7 = V_13 -> V_123 ;
struct V_124 * V_125 = & V_7 -> V_124 ;
char V_104 [ V_126 ] ;
int V_44 ;
memset ( V_104 , 0 , V_126 ) ;
V_44 = snprintf ( V_105 , V_13 -> V_127 ,
L_21
L_22
L_23 ,
V_13 -> V_26 , V_122 ,
V_13 -> V_27 ) ;
snprintf ( V_104 , V_126 ,
L_24 , & V_125 -> V_128 [ 0 ] ,
F_41 ( & V_13 -> V_129 . V_130 ) ) ;
return F_32 ( V_104 , V_105 , V_44 ) ;
}
static int F_42 (
struct V_12 * V_13 ,
struct V_10 * V_35 ,
struct V_38 * V_39 ,
unsigned char * V_105 ,
int V_131 ,
int V_132 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_10 * V_11 ;
struct V_14 * V_137 ;
int V_138 = 0 ;
V_138 = F_6 ( & V_13 -> V_25 ) ;
F_43 ( & V_13 -> V_25 ,
V_97 ) ;
V_13 -> V_27 = ( V_132 ) ?
V_102 :
V_103 ;
if ( V_13 -> V_139 != 0 )
F_31 ( V_13 -> V_139 ) ;
F_4 ( & V_13 -> V_28 ) ;
F_5 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_11 = V_137 -> V_29 ;
F_15 ( & V_137 -> V_140 ) ;
F_16 () ;
F_7 ( & V_13 -> V_28 ) ;
F_44 ( & V_11 -> V_141 ) ;
F_5 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_136 = V_134 -> V_135 ;
if ( ! V_136 )
continue;
if ( V_132 &&
( V_39 != NULL ) && ( V_39 == V_136 -> V_142 ) &&
( V_35 != NULL ) && ( V_35 == V_11 ) )
continue;
F_45 ( V_136 -> V_142 ,
V_134 -> V_143 , 0x2A ,
V_144 ) ;
}
F_46 ( & V_11 -> V_141 ) ;
F_4 ( & V_13 -> V_28 ) ;
F_18 ( & V_137 -> V_140 ) ;
F_19 () ;
}
F_7 ( & V_13 -> V_28 ) ;
if ( V_13 -> V_145 ) {
F_47 ( & V_13 -> V_146 ) ;
F_40 ( V_13 ,
V_131 , V_105 ) ;
F_48 ( & V_13 -> V_146 ) ;
}
F_43 ( & V_13 -> V_25 , V_131 ) ;
F_12 ( L_25
L_26 , ( V_132 ) ? L_27 :
L_28 , F_41 ( & V_13 -> V_129 . V_130 ) ,
V_13 -> V_26 , F_27 ( V_138 ) ,
F_27 ( V_131 ) ) ;
return 0 ;
}
int F_17 (
struct V_12 * V_41 ,
struct V_33 * V_147 ,
struct V_10 * V_35 ,
struct V_38 * V_148 ,
int V_131 ,
int V_132 )
{
struct V_33 * V_34 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_38 * V_39 ;
struct V_149 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_12 * V_13 ;
unsigned char * V_105 ;
int V_46 ;
if ( F_13 ( V_131 , & V_46 ) != 0 )
return - V_20 ;
V_105 = F_49 ( V_41 -> V_127 , V_154 ) ;
if ( ! V_105 ) {
F_11 ( L_29 ) ;
return - V_155 ;
}
V_153 = V_147 -> V_156 ;
F_4 ( & V_153 -> V_157 ) ;
V_150 = V_153 -> V_150 ;
F_15 ( & V_150 -> V_158 ) ;
F_16 () ;
F_7 ( & V_153 -> V_157 ) ;
if ( ! V_150 -> V_159 ) {
F_42 ( V_41 , V_35 , V_148 ,
V_105 , V_131 , V_132 ) ;
F_18 ( & V_150 -> V_158 ) ;
F_19 () ;
F_50 ( V_105 ) ;
return 0 ;
}
F_4 ( & V_150 -> V_160 ) ;
F_5 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_34 = V_152 -> V_161 ;
V_7 = V_34 -> V_9 ;
F_15 ( & V_152 -> V_162 ) ;
F_16 () ;
F_7 ( & V_150 -> V_160 ) ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_5 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_13 -> V_59 )
continue;
if ( V_41 -> V_26 != V_13 -> V_26 )
continue;
if ( V_41 == V_13 ) {
V_11 = V_35 ;
V_39 = V_148 ;
} else {
V_11 = NULL ;
V_39 = NULL ;
}
F_15 ( & V_13 -> V_60 ) ;
F_16 () ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
F_42 ( V_13 , V_11 ,
V_39 , V_105 , V_131 , V_132 ) ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_18 ( & V_13 -> V_60 ) ;
F_19 () ;
}
F_7 ( & V_7 -> V_21 . V_22 ) ;
F_4 ( & V_150 -> V_160 ) ;
F_18 ( & V_152 -> V_162 ) ;
F_19 () ;
}
F_7 ( & V_150 -> V_160 ) ;
F_12 ( L_30
L_31 ,
F_41 ( & V_150 -> V_163 . V_130 ) ,
V_41 -> V_26 , ( V_132 ) ? L_27 : L_28 ,
F_27 ( V_131 ) ) ;
F_18 ( & V_150 -> V_158 ) ;
F_19 () ;
F_50 ( V_105 ) ;
return 0 ;
}
static int F_51 (
struct V_14 * V_15 ,
struct V_10 * V_11 ,
unsigned char * V_105 ,
T_1 V_106 )
{
struct V_164 * V_165 = V_11 -> V_166 ;
char V_104 [ V_126 ] , V_125 [ V_167 ] ;
int V_44 ;
memset ( V_104 , 0 , V_126 ) ;
memset ( V_125 , 0 , V_167 ) ;
V_44 = snprintf ( V_125 , V_167 , L_32 ,
V_165 -> V_168 -> V_169 ( V_165 ) ) ;
if ( V_165 -> V_168 -> V_170 != NULL )
snprintf ( V_125 + V_44 , V_167 - V_44 , L_33 ,
V_165 -> V_168 -> V_170 ( V_165 ) ) ;
V_44 = snprintf ( V_105 , V_106 , L_34
L_35 ,
F_6 ( & V_11 -> V_90 ) ,
V_11 -> V_171 ) ;
snprintf ( V_104 , V_126 , L_36 ,
V_165 -> V_168 -> V_172 () , V_125 ,
V_11 -> V_173 -> V_174 ) ;
return F_32 ( V_104 , V_105 , V_44 ) ;
}
static int F_20 (
struct V_14 * V_15 ,
struct V_10 * V_11 ,
int V_132 ,
int V_175 )
{
struct V_12 * V_13 ;
unsigned char * V_105 ;
T_1 V_106 ;
int V_176 ;
F_4 ( & V_15 -> V_55 ) ;
V_13 = V_15 -> V_13 ;
if ( ! V_13 ) {
F_7 ( & V_15 -> V_55 ) ;
F_11 ( L_37
L_38 ) ;
return - V_20 ;
}
V_176 = V_13 -> V_139 ;
if ( V_175 )
F_43 ( & V_11 -> V_90 , 1 ) ;
else
F_43 ( & V_11 -> V_90 , 0 ) ;
V_106 = V_13 -> V_127 ;
V_11 -> V_171 = ( V_132 ) ?
V_102 :
V_103 ;
F_12 ( L_25
L_39 , ( V_132 ) ? L_27 :
L_28 , F_41 ( & V_13 -> V_129 . V_130 ) ,
V_13 -> V_26 , ( V_175 ) ? L_40 : L_41 ) ;
F_7 ( & V_15 -> V_55 ) ;
if ( V_176 != 0 )
F_31 ( V_176 ) ;
if ( V_11 -> V_177 ) {
V_105 = F_49 ( V_106 , V_154 ) ;
if ( ! V_105 ) {
F_11 ( L_42
L_43 ) ;
return - V_155 ;
}
F_47 ( & V_11 -> V_178 ) ;
F_51 ( V_15 , V_11 ,
V_105 , V_106 ) ;
F_48 ( & V_11 -> V_178 ) ;
F_50 ( V_105 ) ;
}
return 0 ;
}
struct V_149 *
F_52 ( const char * V_179 , int V_180 )
{
struct V_149 * V_150 ;
V_150 = F_53 ( V_181 , V_154 ) ;
if ( ! V_150 ) {
F_11 ( L_44 ) ;
return F_54 ( - V_155 ) ;
}
F_55 ( & V_150 -> V_182 ) ;
F_55 ( & V_150 -> V_183 ) ;
F_56 ( & V_150 -> V_160 ) ;
F_43 ( & V_150 -> V_158 , 0 ) ;
if ( V_180 ) {
V_150 -> V_159 = V_184 ++ ;
V_150 -> V_185 = 1 ;
V_186 ++ ;
}
return V_150 ;
}
int F_57 ( struct V_149 * V_150 , T_2 V_159 )
{
struct V_149 * V_187 ;
T_2 V_188 ;
if ( V_150 -> V_185 ) {
F_2 ( L_45
L_46 ) ;
return - V_20 ;
}
F_4 ( & V_189 ) ;
if ( V_186 == 0x0000ffff ) {
F_11 ( L_47
L_48 ) ;
F_7 ( & V_189 ) ;
F_58 ( V_181 , V_150 ) ;
return - V_190 ;
}
V_191:
V_188 = ( V_159 != 0 ) ? V_159 :
V_184 ++ ;
F_5 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_187 -> V_159 == V_188 ) {
if ( ! V_159 )
goto V_191;
F_2 ( L_49
L_50 ,
V_159 ) ;
F_7 ( & V_189 ) ;
return - V_20 ;
}
}
V_150 -> V_159 = V_188 ;
V_150 -> V_185 = 1 ;
F_59 ( & V_150 -> V_182 , & V_192 ) ;
V_186 ++ ;
F_7 ( & V_189 ) ;
return 0 ;
}
static struct V_151 *
F_60 ( struct V_33 * V_34 )
{
struct V_151 * V_152 ;
V_152 = F_53 ( V_193 , V_154 ) ;
if ( ! V_152 ) {
F_11 ( L_51 ) ;
return F_54 ( - V_155 ) ;
}
F_55 ( & V_152 -> V_183 ) ;
F_56 ( & V_152 -> V_157 ) ;
F_43 ( & V_152 -> V_162 , 0 ) ;
V_152 -> V_161 = V_34 ;
V_34 -> V_156 = V_152 ;
return V_152 ;
}
void F_61 ( struct V_149 * V_150 )
{
struct V_151 * V_152 , * V_194 ;
F_4 ( & V_189 ) ;
F_62 ( & V_150 -> V_182 ) ;
V_186 -- ;
F_7 ( & V_189 ) ;
while ( F_6 ( & V_150 -> V_158 ) )
F_63 () ;
F_4 ( & V_150 -> V_160 ) ;
F_64 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_152 -> V_195 ) {
F_62 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_160 ) ;
F_4 ( & V_152 -> V_157 ) ;
if ( V_150 != V_197 )
F_65 ( V_152 ,
V_197 ) ;
else
V_152 -> V_150 = NULL ;
F_7 ( & V_152 -> V_157 ) ;
F_4 ( & V_150 -> V_160 ) ;
}
F_7 ( & V_150 -> V_160 ) ;
F_58 ( V_181 , V_150 ) ;
}
void F_66 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_9 ;
struct V_21 * V_198 = & V_7 -> V_21 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
if ( V_198 -> V_199 != V_200 )
return;
V_152 = V_34 -> V_156 ;
if ( ! V_152 )
return;
while ( F_6 ( & V_152 -> V_162 ) )
F_63 () ;
F_4 ( & V_152 -> V_157 ) ;
V_150 = V_152 -> V_150 ;
if ( V_150 ) {
F_4 ( & V_150 -> V_160 ) ;
if ( V_152 -> V_195 ) {
F_62 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_160 ) ;
V_152 -> V_150 = NULL ;
}
F_7 ( & V_152 -> V_157 ) ;
F_58 ( V_193 , V_152 ) ;
}
struct V_149 * F_67 ( const char * V_179 )
{
struct V_149 * V_150 ;
struct V_201 * V_202 ;
F_4 ( & V_189 ) ;
F_5 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_150 -> V_185 )
continue;
V_202 = & V_150 -> V_163 . V_130 ;
if ( ! strcmp ( F_41 ( V_202 ) , V_179 ) ) {
F_15 ( & V_150 -> V_158 ) ;
F_7 ( & V_189 ) ;
return V_150 ;
}
}
F_7 ( & V_189 ) ;
return NULL ;
}
void F_68 ( struct V_149 * V_150 )
{
F_4 ( & V_189 ) ;
F_18 ( & V_150 -> V_158 ) ;
F_7 ( & V_189 ) ;
}
void F_65 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_160 ) ;
V_152 -> V_150 = V_150 ;
V_152 -> V_195 = 1 ;
F_59 ( & V_152 -> V_183 , & V_150 -> V_183 ) ;
V_150 -> V_196 ++ ;
F_7 ( & V_150 -> V_160 ) ;
}
void F_69 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_160 ) ;
F_62 ( & V_152 -> V_183 ) ;
V_152 -> V_150 = NULL ;
V_152 -> V_195 = 0 ;
V_150 -> V_196 -- ;
F_7 ( & V_150 -> V_160 ) ;
}
struct V_12 * F_70 (
struct V_6 * V_7 ,
const char * V_179 ,
int V_180 )
{
struct V_12 * V_13 ;
V_13 = F_53 ( V_203 , V_154 ) ;
if ( ! V_13 ) {
F_11 ( L_52 ) ;
return NULL ;
}
F_55 ( & V_13 -> V_204 ) ;
F_55 ( & V_13 -> V_205 ) ;
F_71 ( & V_13 -> V_146 ) ;
F_56 ( & V_13 -> V_28 ) ;
F_43 ( & V_13 -> V_60 , 0 ) ;
V_13 -> V_123 = V_7 ;
V_13 -> V_127 = V_206 ;
F_43 ( & V_13 -> V_25 ,
V_93 ) ;
V_13 -> V_56 =
V_57 | V_207 ;
V_13 -> V_92 = V_208 ;
V_13 -> V_139 = V_209 ;
if ( V_180 ) {
F_4 ( & V_7 -> V_21 . V_22 ) ;
V_13 -> V_26 =
V_7 -> V_21 . V_210 ++ ;
V_13 -> V_59 = 1 ;
V_7 -> V_21 . V_211 ++ ;
F_59 ( & V_13 -> V_204 ,
& V_7 -> V_21 . V_212 ) ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
}
return V_13 ;
}
int F_72 (
struct V_12 * V_13 ,
T_2 V_26 )
{
struct V_6 * V_7 = V_13 -> V_123 ;
struct V_12 * V_213 ;
T_2 V_214 ;
if ( V_13 -> V_59 ) {
F_2 ( L_53
L_46 ) ;
return - V_20 ;
}
F_4 ( & V_7 -> V_21 . V_22 ) ;
if ( V_7 -> V_21 . V_211 == 0x0000ffff ) {
F_11 ( L_54
L_48 ) ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
F_58 ( V_203 , V_13 ) ;
return - V_190 ;
}
V_191:
V_214 = ( V_26 != 0 ) ? V_26 :
V_7 -> V_21 . V_210 ++ ;
F_5 (tg_pt_gp_tmp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_213 -> V_26 == V_214 ) {
if ( ! V_26 )
goto V_191;
F_11 ( L_55
L_56 , V_26 ) ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
return - V_20 ;
}
}
V_13 -> V_26 = V_214 ;
V_13 -> V_59 = 1 ;
F_59 ( & V_13 -> V_204 ,
& V_7 -> V_21 . V_212 ) ;
V_7 -> V_21 . V_211 ++ ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
return 0 ;
}
struct V_14 * F_73 (
struct V_10 * V_11 )
{
struct V_14 * V_15 ;
V_15 = F_53 ( V_215 ,
V_154 ) ;
if ( ! V_15 ) {
F_11 ( L_57 ) ;
return F_54 ( - V_155 ) ;
}
F_55 ( & V_15 -> V_205 ) ;
F_56 ( & V_15 -> V_55 ) ;
F_43 ( & V_15 -> V_140 , 0 ) ;
V_15 -> V_29 = V_11 ;
V_11 -> V_52 = V_15 ;
return V_15 ;
}
void F_74 (
struct V_12 * V_13 )
{
struct V_6 * V_7 = V_13 -> V_123 ;
struct V_14 * V_15 , * V_216 ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_62 ( & V_13 -> V_204 ) ;
V_7 -> V_21 . V_210 -- ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
while ( F_6 ( & V_13 -> V_60 ) )
F_63 () ;
F_4 ( & V_13 -> V_28 ) ;
F_64 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_15 -> V_217 ) {
F_62 ( & V_15 -> V_205 ) ;
V_13 -> V_23 -- ;
V_15 -> V_217 = 0 ;
}
F_7 ( & V_13 -> V_28 ) ;
F_4 ( & V_15 -> V_55 ) ;
if ( V_13 != V_7 -> V_21 . V_218 ) {
F_75 ( V_15 ,
V_7 -> V_21 . V_218 ) ;
} else
V_15 -> V_13 = NULL ;
F_7 ( & V_15 -> V_55 ) ;
F_4 ( & V_13 -> V_28 ) ;
}
F_7 ( & V_13 -> V_28 ) ;
F_58 ( V_203 , V_13 ) ;
}
void F_76 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_173 -> V_219 -> V_9 ;
struct V_21 * V_198 = & V_7 -> V_21 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( V_198 -> V_199 != V_200 )
return;
V_15 = V_11 -> V_52 ;
if ( ! V_15 )
return;
while ( F_6 ( & V_15 -> V_140 ) )
F_63 () ;
F_4 ( & V_15 -> V_55 ) ;
V_13 = V_15 -> V_13 ;
if ( V_13 ) {
F_4 ( & V_13 -> V_28 ) ;
if ( V_15 -> V_217 ) {
F_62 ( & V_15 -> V_205 ) ;
V_13 -> V_23 -- ;
V_15 -> V_217 = 0 ;
}
F_7 ( & V_13 -> V_28 ) ;
V_15 -> V_13 = NULL ;
}
F_7 ( & V_15 -> V_55 ) ;
F_58 ( V_215 , V_15 ) ;
}
static struct V_12 * F_77 (
struct V_6 * V_7 ,
const char * V_179 )
{
struct V_12 * V_13 ;
struct V_201 * V_202 ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_5 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_13 -> V_59 )
continue;
V_202 = & V_13 -> V_129 . V_130 ;
if ( ! strcmp ( F_41 ( V_202 ) , V_179 ) ) {
F_15 ( & V_13 -> V_60 ) ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
return V_13 ;
}
}
F_7 ( & V_7 -> V_21 . V_22 ) ;
return NULL ;
}
static void F_78 (
struct V_12 * V_13 )
{
struct V_6 * V_7 = V_13 -> V_123 ;
F_4 ( & V_7 -> V_21 . V_22 ) ;
F_18 ( & V_13 -> V_60 ) ;
F_7 ( & V_7 -> V_21 . V_22 ) ;
}
void F_75 (
struct V_14 * V_15 ,
struct V_12 * V_13 )
{
F_4 ( & V_13 -> V_28 ) ;
V_15 -> V_13 = V_13 ;
V_15 -> V_217 = 1 ;
F_59 ( & V_15 -> V_205 ,
& V_13 -> V_205 ) ;
V_13 -> V_23 ++ ;
F_7 ( & V_13 -> V_28 ) ;
}
static void F_79 (
struct V_14 * V_15 ,
struct V_12 * V_13 )
{
F_4 ( & V_13 -> V_28 ) ;
F_62 ( & V_15 -> V_205 ) ;
V_15 -> V_13 = NULL ;
V_15 -> V_217 = 0 ;
V_13 -> V_23 -- ;
F_7 ( & V_13 -> V_28 ) ;
}
T_5 F_80 ( struct V_10 * V_11 , char * V_220 )
{
struct V_6 * V_7 = V_11 -> V_173 -> V_219 -> V_9 ;
struct V_201 * V_221 ;
struct V_21 * V_198 = & V_7 -> V_21 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_5 V_44 = 0 ;
if ( V_198 -> V_199 != V_200 )
return V_44 ;
V_15 = V_11 -> V_52 ;
if ( ! V_15 )
return V_44 ;
F_4 ( & V_15 -> V_55 ) ;
V_13 = V_15 -> V_13 ;
if ( V_13 ) {
V_221 = & V_13 -> V_129 . V_130 ;
V_44 += sprintf ( V_220 , L_58
L_59
L_60
L_61 ,
F_41 ( V_221 ) , V_13 -> V_26 ,
F_27 ( F_6 (
& V_13 -> V_25 ) ) ,
F_28 (
V_13 -> V_27 ) ,
( F_6 ( & V_11 -> V_90 ) ) ?
L_14 : L_16 ,
F_28 ( V_11 -> V_171 ) ) ;
}
F_7 ( & V_15 -> V_55 ) ;
return V_44 ;
}
T_5 F_81 (
struct V_10 * V_11 ,
const char * V_220 ,
T_6 V_222 )
{
struct V_164 * V_223 ;
struct V_36 * V_88 ;
struct V_6 * V_7 = V_11 -> V_173 -> V_219 -> V_9 ;
struct V_12 * V_13 = NULL , * V_224 = NULL ;
struct V_14 * V_15 ;
unsigned char V_16 [ V_225 ] ;
int V_226 = 0 ;
V_223 = V_11 -> V_166 ;
V_88 = V_11 -> V_173 ;
if ( V_7 -> V_21 . V_199 != V_200 ) {
F_2 ( L_62
L_63 , V_223 -> V_168 -> V_169 ( V_223 ) ,
V_223 -> V_168 -> V_170 ( V_223 ) ,
F_41 ( & V_88 -> V_227 . V_130 ) ) ;
return - V_20 ;
}
if ( V_222 > V_225 ) {
F_11 ( L_64 ) ;
return - V_20 ;
}
memset ( V_16 , 0 , V_225 ) ;
memcpy ( V_16 , V_220 , V_222 ) ;
if ( strcmp ( F_82 ( V_16 ) , L_65 ) ) {
V_224 = F_77 ( V_7 ,
F_82 ( V_16 ) ) ;
if ( ! V_224 )
return - V_117 ;
}
V_15 = V_11 -> V_52 ;
if ( ! V_15 ) {
if ( V_224 )
F_78 ( V_224 ) ;
F_11 ( L_66 ) ;
return - V_20 ;
}
F_4 ( & V_15 -> V_55 ) ;
V_13 = V_15 -> V_13 ;
if ( V_13 ) {
if ( ! V_224 ) {
F_12 ( L_67
L_68
L_69
L_70 ,
V_223 -> V_168 -> V_169 ( V_223 ) ,
V_223 -> V_168 -> V_170 ( V_223 ) ,
F_41 ( & V_88 -> V_227 . V_130 ) ,
F_41 (
& V_13 -> V_129 . V_130 ) ,
V_13 -> V_26 ) ;
F_79 ( V_15 , V_13 ) ;
F_75 ( V_15 ,
V_7 -> V_21 . V_218 ) ;
F_7 ( & V_15 -> V_55 ) ;
return V_222 ;
}
F_79 ( V_15 , V_13 ) ;
V_226 = 1 ;
}
F_75 ( V_15 , V_224 ) ;
F_7 ( & V_15 -> V_55 ) ;
F_12 ( L_71
L_72 , ( V_226 ) ?
L_73 : L_74 , V_223 -> V_168 -> V_169 ( V_223 ) ,
V_223 -> V_168 -> V_170 ( V_223 ) ,
F_41 ( & V_88 -> V_227 . V_130 ) ,
F_41 ( & V_224 -> V_129 . V_130 ) ,
V_224 -> V_26 ) ;
F_78 ( V_224 ) ;
return V_222 ;
}
T_5 F_83 (
struct V_12 * V_13 ,
char * V_220 )
{
if ( ( V_13 -> V_56 & V_57 ) &&
( V_13 -> V_56 & V_207 ) )
return sprintf ( V_220 , L_75 ) ;
else if ( V_13 -> V_56 & V_207 )
return sprintf ( V_220 , L_76 ) ;
else if ( V_13 -> V_56 & V_57 )
return sprintf ( V_220 , L_77 ) ;
else
return sprintf ( V_220 , L_78 ) ;
}
T_5 F_84 (
struct V_12 * V_13 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_79 ) ;
return - V_20 ;
}
if ( ( V_228 != 0 ) && ( V_228 != 1 ) && ( V_228 != 2 ) && ( V_228 != 3 ) ) {
F_11 ( L_80
L_81 , V_228 ) ;
return - V_20 ;
}
if ( V_228 == 3 )
V_13 -> V_56 =
V_207 | V_57 ;
else if ( V_228 == 2 )
V_13 -> V_56 = V_57 ;
else if ( V_228 == 1 )
V_13 -> V_56 = V_207 ;
else
V_13 -> V_56 = 0 ;
return V_222 ;
}
T_5 F_86 (
struct V_12 * V_13 ,
char * V_220 )
{
return sprintf ( V_220 , L_82 , V_13 -> V_92 ) ;
}
T_5 F_87 (
struct V_12 * V_13 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_83 ) ;
return - V_20 ;
}
if ( V_228 > V_229 ) {
F_11 ( L_84
L_85 , V_228 ,
V_229 ) ;
return - V_20 ;
}
V_13 -> V_92 = ( int ) V_228 ;
return V_222 ;
}
T_5 F_88 (
struct V_12 * V_13 ,
char * V_220 )
{
return sprintf ( V_220 , L_82 , V_13 -> V_139 ) ;
}
T_5 F_89 (
struct V_12 * V_13 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_86 ) ;
return - V_20 ;
}
if ( V_228 > V_230 ) {
F_11 ( L_87
L_88 , V_228 ,
V_230 ) ;
return - V_20 ;
}
V_13 -> V_139 = ( int ) V_228 ;
return V_222 ;
}
T_5 F_90 (
struct V_12 * V_13 ,
char * V_220 )
{
return sprintf ( V_220 , L_82 , V_13 -> V_24 ) ;
}
T_5 F_91 (
struct V_12 * V_13 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_89 ) ;
return - V_20 ;
}
if ( ( V_228 != 0 ) && ( V_228 != 1 ) ) {
F_11 ( L_90 , V_228 ) ;
return - V_20 ;
}
V_13 -> V_24 = ( int ) V_228 ;
return V_222 ;
}
T_5 F_92 ( struct V_36 * V_88 , char * V_220 )
{
if ( ! V_88 -> V_37 )
return - V_117 ;
return sprintf ( V_220 , L_82 ,
F_6 ( & V_88 -> V_37 -> V_90 ) ) ;
}
T_5 F_93 (
struct V_36 * V_88 ,
const char * V_220 ,
T_6 V_222 )
{
struct V_14 * V_15 ;
unsigned long V_228 ;
int V_115 ;
if ( ! V_88 -> V_37 )
return - V_117 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_91 ) ;
return - V_20 ;
}
if ( ( V_228 != 0 ) && ( V_228 != 1 ) ) {
F_11 ( L_92 ,
V_228 ) ;
return - V_20 ;
}
V_15 = V_88 -> V_37 -> V_52 ;
if ( ! V_15 ) {
F_11 ( L_93 ) ;
return - V_20 ;
}
V_115 = F_20 ( V_15 ,
V_88 -> V_37 , 0 , ( int ) V_228 ) ;
if ( V_115 < 0 )
return - V_20 ;
return V_222 ;
}
T_5 F_94 (
struct V_36 * V_88 ,
char * V_220 )
{
return sprintf ( V_220 , L_82 , V_88 -> V_37 -> V_171 ) ;
}
T_5 F_95 (
struct V_36 * V_88 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_94 ) ;
return - V_20 ;
}
if ( ( V_228 != V_101 ) &&
( V_228 != V_102 ) &&
( V_228 != V_103 ) ) {
F_11 ( L_95 ,
V_228 ) ;
return - V_20 ;
}
V_88 -> V_37 -> V_171 = ( int ) V_228 ;
return V_222 ;
}
T_5 F_96 (
struct V_36 * V_88 ,
char * V_220 )
{
return sprintf ( V_220 , L_82 ,
V_88 -> V_37 -> V_177 ) ;
}
T_5 F_97 (
struct V_36 * V_88 ,
const char * V_220 ,
T_6 V_222 )
{
unsigned long V_228 ;
int V_115 ;
V_115 = F_85 ( V_220 , 0 , & V_228 ) ;
if ( V_115 < 0 ) {
F_11 ( L_96 ) ;
return - V_20 ;
}
if ( ( V_228 != 0 ) && ( V_228 != 1 ) ) {
F_11 ( L_97
L_81 , V_228 ) ;
return - V_20 ;
}
V_88 -> V_37 -> V_177 = ( int ) V_228 ;
return V_222 ;
}
int F_98 ( struct V_33 * V_34 , int V_231 )
{
struct V_6 * V_7 = V_34 -> V_9 ;
struct V_21 * V_198 = & V_7 -> V_21 ;
struct V_151 * V_152 ;
if ( ( ( V_34 -> V_232 -> V_233 == V_234 ) &&
! ( V_34 -> V_9 -> V_235 . V_236 ) ) || V_231 ) {
V_198 -> V_199 = V_237 ;
V_198 -> V_238 = & F_25 ;
F_12 ( L_98
L_99 , V_34 -> V_232 -> V_179 ) ;
return 0 ;
}
if ( V_34 -> V_232 -> V_239 ( V_34 ) >= V_240 ) {
F_12 ( L_100
L_101 , V_34 -> V_232 -> V_179 ) ;
V_152 = F_60 ( V_34 ) ;
if ( F_34 ( V_152 ) )
return F_99 ( V_152 ) ;
V_198 -> V_199 = V_200 ;
V_198 -> V_238 = & F_26 ;
F_4 ( & V_152 -> V_157 ) ;
F_65 ( V_152 ,
V_197 ) ;
F_7 ( & V_152 -> V_157 ) ;
F_12 ( L_102
L_103 ,
V_34 -> V_232 -> V_179 ) ;
} else {
V_198 -> V_199 = V_241 ;
V_198 -> V_238 = & F_25 ;
F_12 ( L_104
L_101 , V_34 -> V_232 -> V_179 ) ;
}
return 0 ;
}
