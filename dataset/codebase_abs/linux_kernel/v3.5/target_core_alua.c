int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned char * V_13 ;
T_1 V_14 = 0 , V_15 ;
int V_16 = ( V_2 -> V_17 [ 1 ] & 0x20 ) ;
if ( V_16 != 0 )
V_15 = 8 ;
else
V_15 = 4 ;
if ( V_2 -> V_18 < V_15 ) {
F_2 ( L_1
L_2 , V_2 -> V_18 ,
( V_16 ) ? L_3 : L_4 ) ;
V_2 -> V_19 = V_20 ;
return - V_21 ;
}
V_13 = F_3 ( V_2 ) ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_5 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ( V_15 + 8 + ( V_10 -> V_24 * 4 ) ) >
V_2 -> V_18 ) {
V_14 += 8 + ( V_10 -> V_24 * 4 ) ;
continue;
}
if ( V_10 -> V_25 )
V_13 [ V_15 ] = 0x80 ;
V_13 [ V_15 ++ ] |= ( F_6 (
& V_10 -> V_26 ) & 0xff ) ;
V_13 [ V_15 ] = 0x80 ;
V_13 [ V_15 ] |= 0x40 ;
V_13 [ V_15 ] |= 0x8 ;
V_13 [ V_15 ] |= 0x4 ;
V_13 [ V_15 ] |= 0x2 ;
V_13 [ V_15 ++ ] |= 0x1 ;
V_13 [ V_15 ++ ] = ( ( V_10 -> V_27 >> 8 ) & 0xff ) ;
V_13 [ V_15 ++ ] = ( V_10 -> V_27 & 0xff ) ;
V_15 ++ ;
V_13 [ V_15 ++ ] = ( V_10 -> V_28 & 0xff ) ;
V_13 [ V_15 ++ ] = 0x00 ;
V_13 [ V_15 ++ ] = ( V_10 -> V_24 & 0xff ) ;
V_14 += 8 ;
F_4 ( & V_10 -> V_29 ) ;
F_5 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_8 = V_12 -> V_30 ;
V_15 += 2 ;
V_13 [ V_15 ++ ] = ( ( V_8 -> V_31 >> 8 ) & 0xff ) ;
V_13 [ V_15 ++ ] = ( V_8 -> V_31 & 0xff ) ;
V_14 += 4 ;
}
F_7 ( & V_10 -> V_29 ) ;
}
F_7 ( & V_4 -> V_22 . V_23 ) ;
F_8 ( V_14 , & V_13 [ 0 ] ) ;
if ( V_16 != 0 ) {
V_13 [ 4 ] = 0x10 ;
V_8 = V_2 -> V_32 -> V_33 ;
V_12 = V_8 -> V_34 ;
if ( V_12 ) {
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 )
V_13 [ 5 ] = V_10 -> V_36 ;
F_7 ( & V_12 -> V_35 ) ;
}
}
F_9 ( V_2 ) ;
F_10 ( V_2 , V_37 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_5 ;
struct V_3 * V_4 = V_39 -> V_6 ;
struct V_7 * V_8 , * V_40 = V_2 -> V_32 -> V_33 ;
struct V_41 * V_42 = V_2 -> V_43 -> V_41 ;
struct V_9 * V_10 = NULL , * V_44 ;
struct V_11 * V_12 , * V_45 ;
unsigned char * V_13 ;
unsigned char * V_46 ;
T_1 V_47 = 4 ;
int V_48 , V_49 = 0 , V_50 ;
T_2 V_51 , V_52 ;
if ( ! V_40 ) {
V_2 -> V_19 = V_53 ;
return - V_21 ;
}
V_13 = F_3 ( V_2 ) ;
V_45 = V_40 -> V_34 ;
if ( ! V_45 ) {
F_12 ( L_5 ) ;
V_2 -> V_19 = V_54 ;
V_50 = - V_21 ;
goto V_55;
}
F_4 ( & V_45 -> V_35 ) ;
V_44 = V_45 -> V_10 ;
if ( ! V_44 ) {
F_7 ( & V_45 -> V_35 ) ;
F_12 ( L_6 ) ;
V_2 -> V_19 = V_54 ;
V_50 = - V_21 ;
goto V_55;
}
V_50 = ( V_44 -> V_56 & V_57 ) ;
F_7 ( & V_45 -> V_35 ) ;
if ( ! V_50 ) {
F_13 ( L_7
L_8 ) ;
V_2 -> V_19 = V_54 ;
V_50 = - V_21 ;
goto V_55;
}
V_46 = & V_13 [ 4 ] ;
while ( V_47 < V_2 -> V_18 ) {
V_48 = ( V_46 [ 0 ] & 0x0f ) ;
V_50 = F_14 ( V_48 , & V_49 ) ;
if ( V_50 != 0 ) {
V_2 -> V_19 = V_58 ;
V_50 = - V_21 ;
goto V_55;
}
V_50 = - 1 ;
if ( V_49 ) {
V_51 = F_15 ( V_46 + 2 ) ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_5 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_59 )
continue;
if ( V_51 != V_10 -> V_27 )
continue;
F_16 ( & V_10 -> V_60 ) ;
F_17 () ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
V_50 = F_18 ( V_10 ,
V_39 , V_40 , V_42 ,
V_48 , 1 ) ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_19 ( & V_10 -> V_60 ) ;
F_20 () ;
break;
}
F_7 ( & V_4 -> V_22 . V_23 ) ;
if ( V_50 != 0 ) {
V_2 -> V_19 = V_58 ;
V_50 = - V_21 ;
goto V_55;
}
} else {
V_52 = F_15 ( V_46 + 2 ) ;
F_4 ( & V_39 -> V_61 ) ;
F_5 (port, &dev->dev_sep_list,
sep_list) {
if ( V_8 -> V_31 != V_52 )
continue;
V_12 = V_8 -> V_34 ;
F_7 ( & V_39 -> V_61 ) ;
V_50 = F_21 (
V_12 , V_8 , 1 , 1 ) ;
F_4 ( & V_39 -> V_61 ) ;
break;
}
F_7 ( & V_39 -> V_61 ) ;
if ( V_50 != 0 ) {
V_2 -> V_19 = V_58 ;
V_50 = - V_21 ;
goto V_55;
}
}
V_46 += 4 ;
V_47 += 4 ;
}
V_55:
F_9 ( V_2 ) ;
if ( ! V_50 )
F_10 ( V_2 , V_37 ) ;
return V_50 ;
}
static inline int F_22 (
struct V_1 * V_2 ,
unsigned char * V_62 ,
int V_63 ,
T_3 * V_64 )
{
V_2 -> V_65 |= V_66 ;
V_2 -> V_67 = V_63 ;
return 0 ;
}
static inline int F_23 (
struct V_1 * V_2 ,
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
switch ( V_62 [ 1 ] & 0x1f ) {
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
static inline int F_24 (
struct V_1 * V_2 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
switch ( V_62 [ 0 ] ) {
case V_68 :
case V_73 :
case V_76 :
switch ( V_62 [ 1 ] & 0x1f ) {
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
static inline int F_25 (
struct V_1 * V_2 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
switch ( V_62 [ 0 ] ) {
case V_68 :
case V_73 :
case V_76 :
switch ( V_62 [ 1 ] & 0x1f ) {
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
static int F_26 (
struct V_1 * V_2 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
return 0 ;
}
static int F_27 (
struct V_1 * V_2 ,
unsigned char * V_62 ,
T_3 * V_64 )
{
struct V_32 * V_88 = V_2 -> V_32 ;
struct V_7 * V_8 = V_88 -> V_33 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_89 , V_63 ;
if ( ! V_8 )
return 0 ;
if ( F_6 ( & V_8 -> V_90 ) ) {
* V_64 = V_91 ;
F_13 ( L_9
L_10 ) ;
* V_64 = V_91 ;
return 1 ;
}
V_12 = V_8 -> V_34 ;
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
V_89 = F_6 ( & V_10 -> V_26 ) ;
V_63 = V_10 -> V_92 ;
F_7 ( & V_12 -> V_35 ) ;
if ( V_89 == V_93 )
return 0 ;
switch ( V_89 ) {
case V_94 :
return F_22 ( V_2 , V_62 ,
V_63 , V_64 ) ;
case V_95 :
return F_23 ( V_2 , V_62 , V_64 ) ;
case V_96 :
return F_24 ( V_2 , V_62 , V_64 ) ;
case V_97 :
return F_25 ( V_2 , V_62 , V_64 ) ;
case V_98 :
default:
F_12 ( L_11 ,
V_89 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_14 ( int V_99 , int * V_49 )
{
switch ( V_99 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
* V_49 = 1 ;
break;
case V_98 :
* V_49 = 0 ;
break;
default:
F_12 ( L_11 , V_99 ) ;
return - V_21 ;
}
return 0 ;
}
static char * F_28 ( int V_99 )
{
switch ( V_99 ) {
case V_93 :
return L_12 ;
case V_94 :
return L_13 ;
case V_95 :
return L_14 ;
case V_96 :
return L_15 ;
case V_98 :
return L_16 ;
default:
return L_17 ;
}
return NULL ;
}
char * F_29 ( int V_100 )
{
switch ( V_100 ) {
case V_101 :
return L_18 ;
case V_102 :
return L_19 ;
case V_103 :
return L_20 ;
default:
return L_17 ;
}
return NULL ;
}
int F_30 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_65 & V_66 ) )
return 0 ;
if ( F_31 () )
return 0 ;
if ( ! V_2 -> V_67 )
return 0 ;
F_32 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_33 (
const char * V_104 ,
unsigned char * V_105 ,
T_1 V_106 )
{
T_4 V_107 ;
struct V_108 * V_108 ;
struct V_109 V_110 [ 1 ] ;
int V_111 = V_112 | V_113 | V_114 , V_115 ;
memset ( V_110 , 0 , sizeof( struct V_109 ) ) ;
V_108 = F_34 ( V_104 , V_111 , 0600 ) ;
if ( F_35 ( V_108 ) || ! V_108 || ! V_108 -> V_116 ) {
F_12 ( L_21 ,
V_104 ) ;
return - V_117 ;
}
V_110 [ 0 ] . V_118 = & V_105 [ 0 ] ;
V_110 [ 0 ] . V_119 = V_106 ;
V_107 = F_36 () ;
F_37 ( F_38 () ) ;
V_115 = F_39 ( V_108 , & V_110 [ 0 ] , 1 , & V_108 -> V_120 ) ;
F_37 ( V_107 ) ;
if ( V_115 < 0 ) {
F_12 ( L_22 , V_104 ) ;
F_40 ( V_108 , NULL ) ;
return - V_121 ;
}
F_40 ( V_108 , NULL ) ;
return 0 ;
}
static int F_41 (
struct V_9 * V_10 ,
int V_122 ,
unsigned char * V_105 )
{
struct V_3 * V_4 = V_10 -> V_123 ;
struct V_124 * V_125 = & V_4 -> V_124 ;
char V_104 [ V_126 ] ;
int V_47 ;
memset ( V_104 , 0 , V_126 ) ;
V_47 = snprintf ( V_105 , V_10 -> V_127 ,
L_23
L_24
L_25 ,
V_10 -> V_27 , V_122 ,
V_10 -> V_28 ) ;
snprintf ( V_104 , V_126 ,
L_26 , & V_125 -> V_128 [ 0 ] ,
F_42 ( & V_10 -> V_129 . V_130 ) ) ;
return F_33 ( V_104 , V_105 , V_47 ) ;
}
static int F_43 (
struct V_9 * V_10 ,
struct V_7 * V_40 ,
struct V_41 * V_42 ,
unsigned char * V_105 ,
int V_131 ,
int V_132 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_7 * V_8 ;
struct V_11 * V_137 ;
int V_138 = 0 ;
V_138 = F_6 ( & V_10 -> V_26 ) ;
F_44 ( & V_10 -> V_26 ,
V_97 ) ;
V_10 -> V_28 = ( V_132 ) ?
V_102 :
V_103 ;
if ( V_10 -> V_139 != 0 )
F_32 ( V_10 -> V_139 ) ;
F_4 ( & V_10 -> V_29 ) ;
F_5 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_8 = V_137 -> V_30 ;
F_16 ( & V_137 -> V_140 ) ;
F_17 () ;
F_7 ( & V_10 -> V_29 ) ;
F_45 ( & V_8 -> V_141 ) ;
F_5 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_136 = V_134 -> V_135 ;
if ( ! V_136 )
continue;
if ( V_132 &&
( V_42 != NULL ) && ( V_42 == V_136 -> V_142 ) &&
( V_40 != NULL ) && ( V_40 == V_8 ) )
continue;
F_46 ( V_136 -> V_142 ,
V_134 -> V_143 , 0x2A ,
V_144 ) ;
}
F_47 ( & V_8 -> V_141 ) ;
F_4 ( & V_10 -> V_29 ) ;
F_19 ( & V_137 -> V_140 ) ;
F_20 () ;
}
F_7 ( & V_10 -> V_29 ) ;
if ( V_10 -> V_145 ) {
F_48 ( & V_10 -> V_146 ) ;
F_41 ( V_10 ,
V_131 , V_105 ) ;
F_49 ( & V_10 -> V_146 ) ;
}
F_44 ( & V_10 -> V_26 , V_131 ) ;
F_13 ( L_27
L_28 , ( V_132 ) ? L_29 :
L_30 , F_42 ( & V_10 -> V_129 . V_130 ) ,
V_10 -> V_27 , F_28 ( V_138 ) ,
F_28 ( V_131 ) ) ;
return 0 ;
}
int F_18 (
struct V_9 * V_44 ,
struct V_38 * V_147 ,
struct V_7 * V_40 ,
struct V_41 * V_148 ,
int V_131 ,
int V_132 )
{
struct V_38 * V_39 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
struct V_149 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_9 * V_10 ;
unsigned char * V_105 ;
int V_49 ;
if ( F_14 ( V_131 , & V_49 ) != 0 )
return - V_21 ;
V_105 = F_50 ( V_44 -> V_127 , V_154 ) ;
if ( ! V_105 ) {
F_12 ( L_31 ) ;
return - V_155 ;
}
V_153 = V_147 -> V_156 ;
F_4 ( & V_153 -> V_157 ) ;
V_150 = V_153 -> V_150 ;
F_16 ( & V_150 -> V_158 ) ;
F_17 () ;
F_7 ( & V_153 -> V_157 ) ;
if ( ! V_150 -> V_159 ) {
F_43 ( V_44 , V_40 , V_148 ,
V_105 , V_131 , V_132 ) ;
F_19 ( & V_150 -> V_158 ) ;
F_20 () ;
F_51 ( V_105 ) ;
return 0 ;
}
F_4 ( & V_150 -> V_160 ) ;
F_5 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_39 = V_152 -> V_161 ;
V_4 = V_39 -> V_6 ;
F_16 ( & V_152 -> V_162 ) ;
F_17 () ;
F_7 ( & V_150 -> V_160 ) ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_5 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_59 )
continue;
if ( V_44 -> V_27 != V_10 -> V_27 )
continue;
if ( V_44 == V_10 ) {
V_8 = V_40 ;
V_42 = V_148 ;
} else {
V_8 = NULL ;
V_42 = NULL ;
}
F_16 ( & V_10 -> V_60 ) ;
F_17 () ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
F_43 ( V_10 , V_8 ,
V_42 , V_105 , V_131 , V_132 ) ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_19 ( & V_10 -> V_60 ) ;
F_20 () ;
}
F_7 ( & V_4 -> V_22 . V_23 ) ;
F_4 ( & V_150 -> V_160 ) ;
F_19 ( & V_152 -> V_162 ) ;
F_20 () ;
}
F_7 ( & V_150 -> V_160 ) ;
F_13 ( L_32
L_33 ,
F_42 ( & V_150 -> V_163 . V_130 ) ,
V_44 -> V_27 , ( V_132 ) ? L_29 : L_30 ,
F_28 ( V_131 ) ) ;
F_19 ( & V_150 -> V_158 ) ;
F_20 () ;
F_51 ( V_105 ) ;
return 0 ;
}
static int F_52 (
struct V_11 * V_12 ,
struct V_7 * V_8 ,
unsigned char * V_105 ,
T_1 V_106 )
{
struct V_164 * V_165 = V_8 -> V_166 ;
char V_104 [ V_126 ] , V_125 [ V_167 ] ;
int V_47 ;
memset ( V_104 , 0 , V_126 ) ;
memset ( V_125 , 0 , V_167 ) ;
V_47 = snprintf ( V_125 , V_167 , L_34 ,
V_165 -> V_168 -> V_169 ( V_165 ) ) ;
if ( V_165 -> V_168 -> V_170 != NULL )
snprintf ( V_125 + V_47 , V_167 - V_47 , L_35 ,
V_165 -> V_168 -> V_170 ( V_165 ) ) ;
V_47 = snprintf ( V_105 , V_106 , L_36
L_37 ,
F_6 ( & V_8 -> V_90 ) ,
V_8 -> V_171 ) ;
snprintf ( V_104 , V_126 , L_38 ,
V_165 -> V_168 -> V_172 () , V_125 ,
V_8 -> V_173 -> V_174 ) ;
return F_33 ( V_104 , V_105 , V_47 ) ;
}
static int F_21 (
struct V_11 * V_12 ,
struct V_7 * V_8 ,
int V_132 ,
int V_175 )
{
struct V_9 * V_10 ;
unsigned char * V_105 ;
T_1 V_106 ;
int V_176 ;
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
if ( ! V_10 ) {
F_7 ( & V_12 -> V_35 ) ;
F_12 ( L_39
L_40 ) ;
return - V_21 ;
}
V_176 = V_10 -> V_139 ;
if ( V_175 )
F_44 ( & V_8 -> V_90 , 1 ) ;
else
F_44 ( & V_8 -> V_90 , 0 ) ;
V_106 = V_10 -> V_127 ;
V_8 -> V_171 = ( V_132 ) ?
V_102 :
V_103 ;
F_13 ( L_27
L_41 , ( V_132 ) ? L_29 :
L_30 , F_42 ( & V_10 -> V_129 . V_130 ) ,
V_10 -> V_27 , ( V_175 ) ? L_42 : L_43 ) ;
F_7 ( & V_12 -> V_35 ) ;
if ( V_176 != 0 )
F_32 ( V_176 ) ;
if ( V_8 -> V_177 ) {
V_105 = F_50 ( V_106 , V_154 ) ;
if ( ! V_105 ) {
F_12 ( L_44
L_45 ) ;
return - V_155 ;
}
F_48 ( & V_8 -> V_178 ) ;
F_52 ( V_12 , V_8 ,
V_105 , V_106 ) ;
F_49 ( & V_8 -> V_178 ) ;
F_51 ( V_105 ) ;
}
return 0 ;
}
struct V_149 *
F_53 ( const char * V_179 , int V_180 )
{
struct V_149 * V_150 ;
V_150 = F_54 ( V_181 , V_154 ) ;
if ( ! V_150 ) {
F_12 ( L_46 ) ;
return F_55 ( - V_155 ) ;
}
F_56 ( & V_150 -> V_182 ) ;
F_56 ( & V_150 -> V_183 ) ;
F_57 ( & V_150 -> V_160 ) ;
F_44 ( & V_150 -> V_158 , 0 ) ;
if ( V_180 ) {
V_150 -> V_159 = V_184 ++ ;
V_150 -> V_185 = 1 ;
V_186 ++ ;
}
return V_150 ;
}
int F_58 ( struct V_149 * V_150 , T_2 V_159 )
{
struct V_149 * V_187 ;
T_2 V_188 ;
if ( V_150 -> V_185 ) {
F_2 ( L_47
L_48 ) ;
return - V_21 ;
}
F_4 ( & V_189 ) ;
if ( V_186 == 0x0000ffff ) {
F_12 ( L_49
L_50 ) ;
F_7 ( & V_189 ) ;
F_59 ( V_181 , V_150 ) ;
return - V_190 ;
}
V_191:
V_188 = ( V_159 != 0 ) ? V_159 :
V_184 ++ ;
F_5 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_187 -> V_159 == V_188 ) {
if ( ! V_159 )
goto V_191;
F_2 ( L_51
L_52 ,
V_159 ) ;
F_7 ( & V_189 ) ;
return - V_21 ;
}
}
V_150 -> V_159 = V_188 ;
V_150 -> V_185 = 1 ;
F_60 ( & V_150 -> V_182 , & V_192 ) ;
V_186 ++ ;
F_7 ( & V_189 ) ;
return 0 ;
}
static struct V_151 *
F_61 ( struct V_38 * V_39 )
{
struct V_151 * V_152 ;
V_152 = F_54 ( V_193 , V_154 ) ;
if ( ! V_152 ) {
F_12 ( L_53 ) ;
return F_55 ( - V_155 ) ;
}
F_56 ( & V_152 -> V_183 ) ;
F_57 ( & V_152 -> V_157 ) ;
F_44 ( & V_152 -> V_162 , 0 ) ;
V_152 -> V_161 = V_39 ;
V_39 -> V_156 = V_152 ;
return V_152 ;
}
void F_62 ( struct V_149 * V_150 )
{
struct V_151 * V_152 , * V_194 ;
F_4 ( & V_189 ) ;
F_63 ( & V_150 -> V_182 ) ;
V_186 -- ;
F_7 ( & V_189 ) ;
while ( F_6 ( & V_150 -> V_158 ) )
F_64 () ;
F_4 ( & V_150 -> V_160 ) ;
F_65 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_152 -> V_195 ) {
F_63 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_160 ) ;
F_4 ( & V_152 -> V_157 ) ;
if ( V_150 != V_197 )
F_66 ( V_152 ,
V_197 ) ;
else
V_152 -> V_150 = NULL ;
F_7 ( & V_152 -> V_157 ) ;
F_4 ( & V_150 -> V_160 ) ;
}
F_7 ( & V_150 -> V_160 ) ;
F_59 ( V_181 , V_150 ) ;
}
void F_67 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = V_39 -> V_6 ;
struct V_22 * V_198 = & V_4 -> V_22 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
if ( V_198 -> V_199 != V_200 )
return;
V_152 = V_39 -> V_156 ;
if ( ! V_152 )
return;
while ( F_6 ( & V_152 -> V_162 ) )
F_64 () ;
F_4 ( & V_152 -> V_157 ) ;
V_150 = V_152 -> V_150 ;
if ( V_150 ) {
F_4 ( & V_150 -> V_160 ) ;
if ( V_152 -> V_195 ) {
F_63 ( & V_152 -> V_183 ) ;
V_150 -> V_196 -- ;
V_152 -> V_195 = 0 ;
}
F_7 ( & V_150 -> V_160 ) ;
V_152 -> V_150 = NULL ;
}
F_7 ( & V_152 -> V_157 ) ;
F_59 ( V_193 , V_152 ) ;
}
struct V_149 * F_68 ( const char * V_179 )
{
struct V_149 * V_150 ;
struct V_201 * V_202 ;
F_4 ( & V_189 ) ;
F_5 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_150 -> V_185 )
continue;
V_202 = & V_150 -> V_163 . V_130 ;
if ( ! strcmp ( F_42 ( V_202 ) , V_179 ) ) {
F_16 ( & V_150 -> V_158 ) ;
F_7 ( & V_189 ) ;
return V_150 ;
}
}
F_7 ( & V_189 ) ;
return NULL ;
}
void F_69 ( struct V_149 * V_150 )
{
F_4 ( & V_189 ) ;
F_19 ( & V_150 -> V_158 ) ;
F_7 ( & V_189 ) ;
}
void F_66 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_160 ) ;
V_152 -> V_150 = V_150 ;
V_152 -> V_195 = 1 ;
F_60 ( & V_152 -> V_183 , & V_150 -> V_183 ) ;
V_150 -> V_196 ++ ;
F_7 ( & V_150 -> V_160 ) ;
}
void F_70 (
struct V_151 * V_152 ,
struct V_149 * V_150 )
{
F_4 ( & V_150 -> V_160 ) ;
F_63 ( & V_152 -> V_183 ) ;
V_152 -> V_150 = NULL ;
V_152 -> V_195 = 0 ;
V_150 -> V_196 -- ;
F_7 ( & V_150 -> V_160 ) ;
}
struct V_9 * F_71 (
struct V_3 * V_4 ,
const char * V_179 ,
int V_180 )
{
struct V_9 * V_10 ;
V_10 = F_54 ( V_203 , V_154 ) ;
if ( ! V_10 ) {
F_12 ( L_54 ) ;
return NULL ;
}
F_56 ( & V_10 -> V_204 ) ;
F_56 ( & V_10 -> V_205 ) ;
F_72 ( & V_10 -> V_146 ) ;
F_57 ( & V_10 -> V_29 ) ;
F_44 ( & V_10 -> V_60 , 0 ) ;
V_10 -> V_123 = V_4 ;
V_10 -> V_127 = V_206 ;
F_44 ( & V_10 -> V_26 ,
V_93 ) ;
V_10 -> V_56 =
V_57 | V_207 ;
V_10 -> V_92 = V_208 ;
V_10 -> V_139 = V_209 ;
V_10 -> V_36 = V_210 ;
if ( V_180 ) {
F_4 ( & V_4 -> V_22 . V_23 ) ;
V_10 -> V_27 =
V_4 -> V_22 . V_211 ++ ;
V_10 -> V_59 = 1 ;
V_4 -> V_22 . V_212 ++ ;
F_60 ( & V_10 -> V_204 ,
& V_4 -> V_22 . V_213 ) ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
}
return V_10 ;
}
int F_73 (
struct V_9 * V_10 ,
T_2 V_27 )
{
struct V_3 * V_4 = V_10 -> V_123 ;
struct V_9 * V_214 ;
T_2 V_215 ;
if ( V_10 -> V_59 ) {
F_2 ( L_55
L_48 ) ;
return - V_21 ;
}
F_4 ( & V_4 -> V_22 . V_23 ) ;
if ( V_4 -> V_22 . V_212 == 0x0000ffff ) {
F_12 ( L_56
L_50 ) ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
F_59 ( V_203 , V_10 ) ;
return - V_190 ;
}
V_191:
V_215 = ( V_27 != 0 ) ? V_27 :
V_4 -> V_22 . V_211 ++ ;
F_5 (tg_pt_gp_tmp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_214 -> V_27 == V_215 ) {
if ( ! V_27 )
goto V_191;
F_12 ( L_57
L_58 , V_27 ) ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
return - V_21 ;
}
}
V_10 -> V_27 = V_215 ;
V_10 -> V_59 = 1 ;
F_60 ( & V_10 -> V_204 ,
& V_4 -> V_22 . V_213 ) ;
V_4 -> V_22 . V_212 ++ ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
return 0 ;
}
struct V_11 * F_74 (
struct V_7 * V_8 )
{
struct V_11 * V_12 ;
V_12 = F_54 ( V_216 ,
V_154 ) ;
if ( ! V_12 ) {
F_12 ( L_59 ) ;
return F_55 ( - V_155 ) ;
}
F_56 ( & V_12 -> V_205 ) ;
F_57 ( & V_12 -> V_35 ) ;
F_44 ( & V_12 -> V_140 , 0 ) ;
V_12 -> V_30 = V_8 ;
V_8 -> V_34 = V_12 ;
return V_12 ;
}
void F_75 (
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_123 ;
struct V_11 * V_12 , * V_217 ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_63 ( & V_10 -> V_204 ) ;
V_4 -> V_22 . V_211 -- ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
while ( F_6 ( & V_10 -> V_60 ) )
F_64 () ;
F_4 ( & V_10 -> V_29 ) ;
F_65 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_12 -> V_218 ) {
F_63 ( & V_12 -> V_205 ) ;
V_10 -> V_24 -- ;
V_12 -> V_218 = 0 ;
}
F_7 ( & V_10 -> V_29 ) ;
F_4 ( & V_12 -> V_35 ) ;
if ( V_10 != V_4 -> V_22 . V_219 ) {
F_76 ( V_12 ,
V_4 -> V_22 . V_219 ) ;
} else
V_12 -> V_10 = NULL ;
F_7 ( & V_12 -> V_35 ) ;
F_4 ( & V_10 -> V_29 ) ;
}
F_7 ( & V_10 -> V_29 ) ;
F_59 ( V_203 , V_10 ) ;
}
void F_77 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_173 -> V_220 -> V_6 ;
struct V_22 * V_198 = & V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( V_198 -> V_199 != V_200 )
return;
V_12 = V_8 -> V_34 ;
if ( ! V_12 )
return;
while ( F_6 ( & V_12 -> V_140 ) )
F_64 () ;
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
F_4 ( & V_10 -> V_29 ) ;
if ( V_12 -> V_218 ) {
F_63 ( & V_12 -> V_205 ) ;
V_10 -> V_24 -- ;
V_12 -> V_218 = 0 ;
}
F_7 ( & V_10 -> V_29 ) ;
V_12 -> V_10 = NULL ;
}
F_7 ( & V_12 -> V_35 ) ;
F_59 ( V_216 , V_12 ) ;
}
static struct V_9 * F_78 (
struct V_3 * V_4 ,
const char * V_179 )
{
struct V_9 * V_10 ;
struct V_201 * V_202 ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_5 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_59 )
continue;
V_202 = & V_10 -> V_129 . V_130 ;
if ( ! strcmp ( F_42 ( V_202 ) , V_179 ) ) {
F_16 ( & V_10 -> V_60 ) ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
return V_10 ;
}
}
F_7 ( & V_4 -> V_22 . V_23 ) ;
return NULL ;
}
static void F_79 (
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_123 ;
F_4 ( & V_4 -> V_22 . V_23 ) ;
F_19 ( & V_10 -> V_60 ) ;
F_7 ( & V_4 -> V_22 . V_23 ) ;
}
void F_76 (
struct V_11 * V_12 ,
struct V_9 * V_10 )
{
F_4 ( & V_10 -> V_29 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_218 = 1 ;
F_60 ( & V_12 -> V_205 ,
& V_10 -> V_205 ) ;
V_10 -> V_24 ++ ;
F_7 ( & V_10 -> V_29 ) ;
}
static void F_80 (
struct V_11 * V_12 ,
struct V_9 * V_10 )
{
F_4 ( & V_10 -> V_29 ) ;
F_63 ( & V_12 -> V_205 ) ;
V_12 -> V_10 = NULL ;
V_12 -> V_218 = 0 ;
V_10 -> V_24 -- ;
F_7 ( & V_10 -> V_29 ) ;
}
T_5 F_81 ( struct V_7 * V_8 , char * V_221 )
{
struct V_3 * V_4 = V_8 -> V_173 -> V_220 -> V_6 ;
struct V_201 * V_222 ;
struct V_22 * V_198 = & V_4 -> V_22 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_5 V_47 = 0 ;
if ( V_198 -> V_199 != V_200 )
return V_47 ;
V_12 = V_8 -> V_34 ;
if ( ! V_12 )
return V_47 ;
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
V_222 = & V_10 -> V_129 . V_130 ;
V_47 += sprintf ( V_221 , L_60
L_61
L_62
L_63 ,
F_42 ( V_222 ) , V_10 -> V_27 ,
F_28 ( F_6 (
& V_10 -> V_26 ) ) ,
F_29 (
V_10 -> V_28 ) ,
( F_6 ( & V_8 -> V_90 ) ) ?
L_16 : L_18 ,
F_29 ( V_8 -> V_171 ) ) ;
}
F_7 ( & V_12 -> V_35 ) ;
return V_47 ;
}
T_5 F_82 (
struct V_7 * V_8 ,
const char * V_221 ,
T_6 V_223 )
{
struct V_164 * V_224 ;
struct V_32 * V_88 ;
struct V_3 * V_4 = V_8 -> V_173 -> V_220 -> V_6 ;
struct V_9 * V_10 = NULL , * V_225 = NULL ;
struct V_11 * V_12 ;
unsigned char V_13 [ V_226 ] ;
int V_227 = 0 ;
V_224 = V_8 -> V_166 ;
V_88 = V_8 -> V_173 ;
if ( V_4 -> V_22 . V_199 != V_200 ) {
F_2 ( L_64
L_65 , V_224 -> V_168 -> V_169 ( V_224 ) ,
V_224 -> V_168 -> V_170 ( V_224 ) ,
F_42 ( & V_88 -> V_228 . V_130 ) ) ;
return - V_21 ;
}
if ( V_223 > V_226 ) {
F_12 ( L_66 ) ;
return - V_21 ;
}
memset ( V_13 , 0 , V_226 ) ;
memcpy ( V_13 , V_221 , V_223 ) ;
if ( strcmp ( F_83 ( V_13 ) , L_67 ) ) {
V_225 = F_78 ( V_4 ,
F_83 ( V_13 ) ) ;
if ( ! V_225 )
return - V_117 ;
}
V_12 = V_8 -> V_34 ;
if ( ! V_12 ) {
if ( V_225 )
F_79 ( V_225 ) ;
F_12 ( L_68 ) ;
return - V_21 ;
}
F_4 ( & V_12 -> V_35 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
if ( ! V_225 ) {
F_13 ( L_69
L_70
L_71
L_72 ,
V_224 -> V_168 -> V_169 ( V_224 ) ,
V_224 -> V_168 -> V_170 ( V_224 ) ,
F_42 ( & V_88 -> V_228 . V_130 ) ,
F_42 (
& V_10 -> V_129 . V_130 ) ,
V_10 -> V_27 ) ;
F_80 ( V_12 , V_10 ) ;
F_76 ( V_12 ,
V_4 -> V_22 . V_219 ) ;
F_7 ( & V_12 -> V_35 ) ;
return V_223 ;
}
F_80 ( V_12 , V_10 ) ;
V_227 = 1 ;
}
F_76 ( V_12 , V_225 ) ;
F_7 ( & V_12 -> V_35 ) ;
F_13 ( L_73
L_74 , ( V_227 ) ?
L_75 : L_76 , V_224 -> V_168 -> V_169 ( V_224 ) ,
V_224 -> V_168 -> V_170 ( V_224 ) ,
F_42 ( & V_88 -> V_228 . V_130 ) ,
F_42 ( & V_225 -> V_129 . V_130 ) ,
V_225 -> V_27 ) ;
F_79 ( V_225 ) ;
return V_223 ;
}
T_5 F_84 (
struct V_9 * V_10 ,
char * V_221 )
{
if ( ( V_10 -> V_56 & V_57 ) &&
( V_10 -> V_56 & V_207 ) )
return sprintf ( V_221 , L_77 ) ;
else if ( V_10 -> V_56 & V_207 )
return sprintf ( V_221 , L_78 ) ;
else if ( V_10 -> V_56 & V_57 )
return sprintf ( V_221 , L_79 ) ;
else
return sprintf ( V_221 , L_80 ) ;
}
T_5 F_85 (
struct V_9 * V_10 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_81 ) ;
return - V_21 ;
}
if ( ( V_229 != 0 ) && ( V_229 != 1 ) && ( V_229 != 2 ) && ( V_229 != 3 ) ) {
F_12 ( L_82
L_83 , V_229 ) ;
return - V_21 ;
}
if ( V_229 == 3 )
V_10 -> V_56 =
V_207 | V_57 ;
else if ( V_229 == 2 )
V_10 -> V_56 = V_57 ;
else if ( V_229 == 1 )
V_10 -> V_56 = V_207 ;
else
V_10 -> V_56 = 0 ;
return V_223 ;
}
T_5 F_87 (
struct V_9 * V_10 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 , V_10 -> V_92 ) ;
}
T_5 F_88 (
struct V_9 * V_10 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_85 ) ;
return - V_21 ;
}
if ( V_229 > V_230 ) {
F_12 ( L_86
L_87 , V_229 ,
V_230 ) ;
return - V_21 ;
}
V_10 -> V_92 = ( int ) V_229 ;
return V_223 ;
}
T_5 F_89 (
struct V_9 * V_10 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 , V_10 -> V_139 ) ;
}
T_5 F_90 (
struct V_9 * V_10 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_88 ) ;
return - V_21 ;
}
if ( V_229 > V_231 ) {
F_12 ( L_89
L_90 , V_229 ,
V_231 ) ;
return - V_21 ;
}
V_10 -> V_139 = ( int ) V_229 ;
return V_223 ;
}
T_5 F_91 (
struct V_9 * V_10 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 , V_10 -> V_36 ) ;
}
T_5 F_92 (
struct V_9 * V_10 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_91 ) ;
return - V_21 ;
}
if ( V_229 > V_232 ) {
F_12 ( L_92
L_93 , V_229 ,
V_232 ) ;
return - V_21 ;
}
V_10 -> V_36 = ( int ) V_229 ;
return V_223 ;
}
T_5 F_93 (
struct V_9 * V_10 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 , V_10 -> V_25 ) ;
}
T_5 F_94 (
struct V_9 * V_10 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_94 ) ;
return - V_21 ;
}
if ( ( V_229 != 0 ) && ( V_229 != 1 ) ) {
F_12 ( L_95 , V_229 ) ;
return - V_21 ;
}
V_10 -> V_25 = ( int ) V_229 ;
return V_223 ;
}
T_5 F_95 ( struct V_32 * V_88 , char * V_221 )
{
if ( ! V_88 -> V_33 )
return - V_117 ;
return sprintf ( V_221 , L_84 ,
F_6 ( & V_88 -> V_33 -> V_90 ) ) ;
}
T_5 F_96 (
struct V_32 * V_88 ,
const char * V_221 ,
T_6 V_223 )
{
struct V_11 * V_12 ;
unsigned long V_229 ;
int V_115 ;
if ( ! V_88 -> V_33 )
return - V_117 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_96 ) ;
return - V_21 ;
}
if ( ( V_229 != 0 ) && ( V_229 != 1 ) ) {
F_12 ( L_97 ,
V_229 ) ;
return - V_21 ;
}
V_12 = V_88 -> V_33 -> V_34 ;
if ( ! V_12 ) {
F_12 ( L_98 ) ;
return - V_21 ;
}
V_115 = F_21 ( V_12 ,
V_88 -> V_33 , 0 , ( int ) V_229 ) ;
if ( V_115 < 0 )
return - V_21 ;
return V_223 ;
}
T_5 F_97 (
struct V_32 * V_88 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 , V_88 -> V_33 -> V_171 ) ;
}
T_5 F_98 (
struct V_32 * V_88 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_99 ) ;
return - V_21 ;
}
if ( ( V_229 != V_101 ) &&
( V_229 != V_102 ) &&
( V_229 != V_103 ) ) {
F_12 ( L_100 ,
V_229 ) ;
return - V_21 ;
}
V_88 -> V_33 -> V_171 = ( int ) V_229 ;
return V_223 ;
}
T_5 F_99 (
struct V_32 * V_88 ,
char * V_221 )
{
return sprintf ( V_221 , L_84 ,
V_88 -> V_33 -> V_177 ) ;
}
T_5 F_100 (
struct V_32 * V_88 ,
const char * V_221 ,
T_6 V_223 )
{
unsigned long V_229 ;
int V_115 ;
V_115 = F_86 ( V_221 , 0 , & V_229 ) ;
if ( V_115 < 0 ) {
F_12 ( L_101 ) ;
return - V_21 ;
}
if ( ( V_229 != 0 ) && ( V_229 != 1 ) ) {
F_12 ( L_102
L_83 , V_229 ) ;
return - V_21 ;
}
V_88 -> V_33 -> V_177 = ( int ) V_229 ;
return V_223 ;
}
int F_101 ( struct V_38 * V_39 , int V_233 )
{
struct V_3 * V_4 = V_39 -> V_6 ;
struct V_22 * V_198 = & V_4 -> V_22 ;
struct V_151 * V_152 ;
if ( ( ( V_39 -> V_234 -> V_235 == V_236 ) &&
! ( V_39 -> V_6 -> V_237 . V_238 ) ) || V_233 ) {
V_198 -> V_199 = V_239 ;
V_198 -> V_240 = & F_26 ;
F_13 ( L_103
L_104 , V_39 -> V_234 -> V_179 ) ;
return 0 ;
}
if ( V_39 -> V_234 -> V_241 ( V_39 ) >= V_242 ) {
F_13 ( L_105
L_106 , V_39 -> V_234 -> V_179 ) ;
V_152 = F_61 ( V_39 ) ;
if ( F_35 ( V_152 ) )
return F_102 ( V_152 ) ;
V_198 -> V_199 = V_200 ;
V_198 -> V_240 = & F_27 ;
F_4 ( & V_152 -> V_157 ) ;
F_66 ( V_152 ,
V_197 ) ;
F_7 ( & V_152 -> V_157 ) ;
F_13 ( L_107
L_108 ,
V_39 -> V_234 -> V_179 ) ;
} else {
V_198 -> V_199 = V_243 ;
V_198 -> V_240 = & F_26 ;
F_13 ( L_109
L_106 , V_39 -> V_234 -> V_179 ) ;
}
return 0 ;
}
