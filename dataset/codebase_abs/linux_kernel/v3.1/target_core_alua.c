int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned char * V_13 ;
T_1 V_14 = 0 , V_15 = 4 ;
V_13 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_4 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_10 -> V_18 )
V_13 [ V_15 ] = 0x80 ;
V_13 [ V_15 ++ ] |= ( F_5 (
& V_10 -> V_19 ) & 0xff ) ;
V_13 [ V_15 ] = 0x80 ;
V_13 [ V_15 ] |= 0x40 ;
V_13 [ V_15 ] |= 0x8 ;
V_13 [ V_15 ] |= 0x4 ;
V_13 [ V_15 ] |= 0x2 ;
V_13 [ V_15 ++ ] |= 0x1 ;
V_13 [ V_15 ++ ] = ( ( V_10 -> V_20 >> 8 ) & 0xff ) ;
V_13 [ V_15 ++ ] = ( V_10 -> V_20 & 0xff ) ;
V_15 ++ ;
V_13 [ V_15 ++ ] = ( V_10 -> V_21 & 0xff ) ;
V_13 [ V_15 ++ ] = 0x00 ;
V_13 [ V_15 ++ ] = ( V_10 -> V_22 & 0xff ) ;
V_14 += 8 ;
F_3 ( & V_10 -> V_23 ) ;
F_4 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_8 = V_12 -> V_24 ;
V_15 += 2 ;
V_13 [ V_15 ++ ] = ( ( V_8 -> V_25 >> 8 ) & 0xff ) ;
V_13 [ V_15 ++ ] = ( V_8 -> V_25 & 0xff ) ;
V_14 += 4 ;
}
F_6 ( & V_10 -> V_23 ) ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
V_13 [ 0 ] = ( ( V_14 >> 24 ) & 0xff ) ;
V_13 [ 1 ] = ( ( V_14 >> 16 ) & 0xff ) ;
V_13 [ 2 ] = ( ( V_14 >> 8 ) & 0xff ) ;
V_13 [ 3 ] = ( V_14 & 0xff ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_5 ;
struct V_3 * V_4 = V_27 -> V_6 ;
struct V_7 * V_8 , * V_28 = V_2 -> V_29 -> V_30 ;
struct V_31 * V_32 = V_2 -> V_33 -> V_31 ;
struct V_9 * V_10 = NULL , * V_34 ;
struct V_11 * V_12 , * V_35 ;
unsigned char * V_13 ;
unsigned char * V_36 ;
T_1 V_37 = 4 ;
int V_38 , V_39 = 0 , V_40 ;
T_2 V_41 , V_42 ;
if ( ! V_28 )
return V_43 ;
V_13 = F_2 ( V_2 ) ;
V_35 = V_28 -> V_44 ;
if ( ! V_35 ) {
F_9 ( L_1 ) ;
V_40 = V_45 ;
goto V_46;
}
F_3 ( & V_35 -> V_47 ) ;
V_34 = V_35 -> V_10 ;
if ( ! V_34 ) {
F_6 ( & V_35 -> V_47 ) ;
F_9 ( L_2 ) ;
V_40 = V_45 ;
goto V_46;
}
V_40 = ( V_34 -> V_48 & V_49 ) ;
F_6 ( & V_35 -> V_47 ) ;
if ( ! V_40 ) {
F_10 ( L_3
L_4 ) ;
V_40 = V_45 ;
goto V_46;
}
V_36 = & V_13 [ 4 ] ;
while ( V_37 < V_2 -> V_50 ) {
V_38 = ( V_36 [ 0 ] & 0x0f ) ;
V_40 = F_11 ( V_38 , & V_39 ) ;
if ( V_40 != 0 ) {
V_40 = V_51 ;
goto V_46;
}
V_40 = - 1 ;
if ( V_39 ) {
V_41 = ( ( V_36 [ 2 ] << 8 ) & 0xff ) ;
V_41 |= ( V_36 [ 3 ] & 0xff ) ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_4 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_52 )
continue;
if ( V_41 != V_10 -> V_20 )
continue;
F_12 ( & V_10 -> V_53 ) ;
F_13 () ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
V_40 = F_14 ( V_10 ,
V_27 , V_28 , V_32 ,
V_38 , 1 ) ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_15 ( & V_10 -> V_53 ) ;
F_16 () ;
break;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
if ( V_40 != 0 ) {
V_40 = V_51 ;
goto V_46;
}
} else {
V_42 = ( ( V_36 [ 2 ] << 8 ) & 0xff ) ;
V_42 |= ( V_36 [ 3 ] & 0xff ) ;
F_3 ( & V_27 -> V_54 ) ;
F_4 (port, &dev->dev_sep_list,
sep_list) {
if ( V_8 -> V_25 != V_42 )
continue;
V_12 = V_8 -> V_44 ;
F_6 ( & V_27 -> V_54 ) ;
V_40 = F_17 (
V_12 , V_8 , 1 , 1 ) ;
F_3 ( & V_27 -> V_54 ) ;
break;
}
F_6 ( & V_27 -> V_54 ) ;
if ( V_40 != 0 ) {
V_40 = V_51 ;
goto V_46;
}
}
V_36 += 4 ;
V_37 += 4 ;
}
V_46:
F_7 ( V_2 ) ;
return 0 ;
}
static inline int F_18 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
int V_56 ,
T_3 * V_57 )
{
V_2 -> V_58 |= V_59 ;
V_2 -> V_60 = V_56 ;
return 0 ;
}
static inline int F_19 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
T_3 * V_57 )
{
switch ( V_55 [ 0 ] ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
switch ( V_55 [ 1 ] ) {
case V_70 :
return 0 ;
default:
* V_57 = V_71 ;
return 1 ;
}
case V_72 :
switch ( V_55 [ 1 ] ) {
case V_73 :
return 0 ;
default:
* V_57 = V_71 ;
return 1 ;
}
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
return 0 ;
default:
* V_57 = V_71 ;
return 1 ;
}
return 0 ;
}
static inline int F_20 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
T_3 * V_57 )
{
switch ( V_55 [ 0 ] ) {
case V_61 :
case V_66 :
case V_69 :
switch ( V_55 [ 1 ] ) {
case V_70 :
return 0 ;
default:
* V_57 = V_79 ;
return 1 ;
}
case V_72 :
switch ( V_55 [ 1 ] ) {
case V_73 :
return 0 ;
default:
* V_57 = V_79 ;
return 1 ;
}
case V_74 :
case V_77 :
case V_78 :
return 0 ;
default:
* V_57 = V_79 ;
return 1 ;
}
return 0 ;
}
static inline int F_21 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
T_3 * V_57 )
{
switch ( V_55 [ 0 ] ) {
case V_61 :
case V_66 :
case V_69 :
switch ( V_55 [ 1 ] ) {
case V_70 :
return 0 ;
default:
* V_57 = V_80 ;
return 1 ;
}
case V_74 :
case V_77 :
case V_78 :
return 0 ;
default:
* V_57 = V_80 ;
return 1 ;
}
return 0 ;
}
static int F_22 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
T_3 * V_57 )
{
return 0 ;
}
static int F_23 (
struct V_1 * V_2 ,
unsigned char * V_55 ,
T_3 * V_57 )
{
struct V_29 * V_81 = V_2 -> V_29 ;
struct V_7 * V_8 = V_81 -> V_30 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_82 , V_56 ;
if ( ! V_8 )
return 0 ;
if ( F_5 ( & V_8 -> V_83 ) ) {
* V_57 = V_84 ;
F_10 ( L_5
L_6 ) ;
* V_57 = V_84 ;
return 1 ;
}
V_12 = V_8 -> V_44 ;
F_3 ( & V_12 -> V_47 ) ;
V_10 = V_12 -> V_10 ;
V_82 = F_5 ( & V_10 -> V_19 ) ;
V_56 = V_10 -> V_85 ;
F_6 ( & V_12 -> V_47 ) ;
if ( V_82 == V_86 )
return 0 ;
switch ( V_82 ) {
case V_87 :
return F_18 ( V_2 , V_55 ,
V_56 , V_57 ) ;
case V_88 :
return F_19 ( V_2 , V_55 , V_57 ) ;
case V_89 :
return F_20 ( V_2 , V_55 , V_57 ) ;
case V_90 :
return F_21 ( V_2 , V_55 , V_57 ) ;
case V_91 :
default:
F_9 ( L_7 ,
V_82 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_11 ( int V_93 , int * V_39 )
{
switch ( V_93 ) {
case V_86 :
case V_87 :
case V_88 :
case V_89 :
* V_39 = 1 ;
break;
case V_91 :
* V_39 = 0 ;
break;
default:
F_9 ( L_7 , V_93 ) ;
return - V_92 ;
}
return 0 ;
}
static char * F_24 ( int V_93 )
{
switch ( V_93 ) {
case V_86 :
return L_8 ;
case V_87 :
return L_9 ;
case V_88 :
return L_10 ;
case V_89 :
return L_11 ;
case V_91 :
return L_12 ;
default:
return L_13 ;
}
return NULL ;
}
char * F_25 ( int V_94 )
{
switch ( V_94 ) {
case V_95 :
return L_14 ;
case V_96 :
return L_15 ;
case V_97 :
return L_16 ;
default:
return L_13 ;
}
return NULL ;
}
int F_26 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_58 & V_59 ) )
return 0 ;
if ( F_27 () )
return 0 ;
if ( ! V_2 -> V_60 )
return 0 ;
F_28 ( V_2 -> V_60 ) ;
return 0 ;
}
static int F_29 (
const char * V_98 ,
unsigned char * V_99 ,
T_1 V_100 )
{
T_4 V_101 ;
struct V_102 * V_102 ;
struct V_103 V_104 [ 1 ] ;
int V_105 = V_106 | V_107 | V_108 , V_109 ;
memset ( V_104 , 0 , sizeof( struct V_103 ) ) ;
V_102 = F_30 ( V_98 , V_105 , 0600 ) ;
if ( F_31 ( V_102 ) || ! V_102 || ! V_102 -> V_110 ) {
F_9 ( L_17 ,
V_98 ) ;
return - V_111 ;
}
V_104 [ 0 ] . V_112 = & V_99 [ 0 ] ;
V_104 [ 0 ] . V_113 = V_100 ;
V_101 = F_32 () ;
F_33 ( F_34 () ) ;
V_109 = F_35 ( V_102 , & V_104 [ 0 ] , 1 , & V_102 -> V_114 ) ;
F_33 ( V_101 ) ;
if ( V_109 < 0 ) {
F_9 ( L_18 , V_98 ) ;
F_36 ( V_102 , NULL ) ;
return - V_115 ;
}
F_36 ( V_102 , NULL ) ;
return 0 ;
}
static int F_37 (
struct V_9 * V_10 ,
int V_116 ,
unsigned char * V_99 )
{
struct V_3 * V_4 = V_10 -> V_117 ;
struct V_118 * V_119 = & V_4 -> V_118 ;
char V_98 [ V_120 ] ;
int V_37 ;
memset ( V_98 , 0 , V_120 ) ;
V_37 = snprintf ( V_99 , V_10 -> V_121 ,
L_19
L_20
L_21 ,
V_10 -> V_20 , V_116 ,
V_10 -> V_21 ) ;
snprintf ( V_98 , V_120 ,
L_22 , & V_119 -> V_122 [ 0 ] ,
F_38 ( & V_10 -> V_123 . V_124 ) ) ;
return F_29 ( V_98 , V_99 , V_37 ) ;
}
static int F_39 (
struct V_9 * V_10 ,
struct V_7 * V_28 ,
struct V_31 * V_32 ,
unsigned char * V_99 ,
int V_125 ,
int V_126 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_7 * V_8 ;
struct V_11 * V_131 ;
int V_132 = 0 ;
V_132 = F_5 ( & V_10 -> V_19 ) ;
F_40 ( & V_10 -> V_19 ,
V_90 ) ;
V_10 -> V_21 = ( V_126 ) ?
V_96 :
V_97 ;
if ( V_10 -> V_133 != 0 )
F_28 ( V_10 -> V_133 ) ;
F_3 ( & V_10 -> V_23 ) ;
F_4 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_8 = V_131 -> V_24 ;
F_12 ( & V_131 -> V_134 ) ;
F_13 () ;
F_6 ( & V_10 -> V_23 ) ;
F_41 ( & V_8 -> V_135 ) ;
F_4 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_130 = V_128 -> V_129 ;
if ( ! V_130 )
continue;
if ( V_126 &&
( V_32 != NULL ) && ( V_32 == V_130 -> V_136 ) &&
( V_28 != NULL ) && ( V_28 == V_8 ) )
continue;
F_42 ( V_130 -> V_136 ,
V_128 -> V_137 , 0x2A ,
V_138 ) ;
}
F_43 ( & V_8 -> V_135 ) ;
F_3 ( & V_10 -> V_23 ) ;
F_15 ( & V_131 -> V_134 ) ;
F_16 () ;
}
F_6 ( & V_10 -> V_23 ) ;
if ( V_10 -> V_139 ) {
F_44 ( & V_10 -> V_140 ) ;
F_37 ( V_10 ,
V_125 , V_99 ) ;
F_45 ( & V_10 -> V_140 ) ;
}
F_40 ( & V_10 -> V_19 , V_125 ) ;
F_10 ( L_23
L_24 , ( V_126 ) ? L_25 :
L_26 , F_38 ( & V_10 -> V_123 . V_124 ) ,
V_10 -> V_20 , F_24 ( V_132 ) ,
F_24 ( V_125 ) ) ;
return 0 ;
}
int F_14 (
struct V_9 * V_34 ,
struct V_26 * V_141 ,
struct V_7 * V_28 ,
struct V_31 * V_142 ,
int V_125 ,
int V_126 )
{
struct V_26 * V_27 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
struct V_143 * V_144 ;
struct V_145 * V_146 , * V_147 ;
struct V_9 * V_10 ;
unsigned char * V_99 ;
int V_39 ;
if ( F_11 ( V_125 , & V_39 ) != 0 )
return - V_92 ;
V_99 = F_46 ( V_34 -> V_121 , V_148 ) ;
if ( ! V_99 ) {
F_9 ( L_27 ) ;
return - V_149 ;
}
V_147 = V_141 -> V_150 ;
F_3 ( & V_147 -> V_151 ) ;
V_144 = V_147 -> V_144 ;
F_12 ( & V_144 -> V_152 ) ;
F_13 () ;
F_6 ( & V_147 -> V_151 ) ;
if ( ! V_144 -> V_153 ) {
F_39 ( V_34 , V_28 , V_142 ,
V_99 , V_125 , V_126 ) ;
F_15 ( & V_144 -> V_152 ) ;
F_16 () ;
F_47 ( V_99 ) ;
return 0 ;
}
F_3 ( & V_144 -> V_154 ) ;
F_4 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_27 = V_146 -> V_155 ;
V_4 = V_27 -> V_6 ;
F_12 ( & V_146 -> V_156 ) ;
F_13 () ;
F_6 ( & V_144 -> V_154 ) ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_4 (tg_pt_gp,
&su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_52 )
continue;
if ( V_34 -> V_20 != V_10 -> V_20 )
continue;
if ( V_34 == V_10 ) {
V_8 = V_28 ;
V_32 = V_142 ;
} else {
V_8 = NULL ;
V_32 = NULL ;
}
F_12 ( & V_10 -> V_53 ) ;
F_13 () ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_39 ( V_10 , V_8 ,
V_32 , V_99 , V_125 , V_126 ) ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_15 ( & V_10 -> V_53 ) ;
F_16 () ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_3 ( & V_144 -> V_154 ) ;
F_15 ( & V_146 -> V_156 ) ;
F_16 () ;
}
F_6 ( & V_144 -> V_154 ) ;
F_10 ( L_28
L_29 ,
F_38 ( & V_144 -> V_157 . V_124 ) ,
V_34 -> V_20 , ( V_126 ) ? L_25 : L_26 ,
F_24 ( V_125 ) ) ;
F_15 ( & V_144 -> V_152 ) ;
F_16 () ;
F_47 ( V_99 ) ;
return 0 ;
}
static int F_48 (
struct V_11 * V_12 ,
struct V_7 * V_8 ,
unsigned char * V_99 ,
T_1 V_100 )
{
struct V_158 * V_159 = V_8 -> V_160 ;
char V_98 [ V_120 ] , V_119 [ V_161 ] ;
int V_37 ;
memset ( V_98 , 0 , V_120 ) ;
memset ( V_119 , 0 , V_161 ) ;
V_37 = snprintf ( V_119 , V_161 , L_30 ,
V_159 -> V_162 -> V_163 ( V_159 ) ) ;
if ( V_159 -> V_162 -> V_164 != NULL )
snprintf ( V_119 + V_37 , V_161 - V_37 , L_31 ,
V_159 -> V_162 -> V_164 ( V_159 ) ) ;
V_37 = snprintf ( V_99 , V_100 , L_32
L_33 ,
F_5 ( & V_8 -> V_83 ) ,
V_8 -> V_165 ) ;
snprintf ( V_98 , V_120 , L_34 ,
V_159 -> V_162 -> V_166 () , V_119 ,
V_8 -> V_167 -> V_168 ) ;
return F_29 ( V_98 , V_99 , V_37 ) ;
}
static int F_17 (
struct V_11 * V_12 ,
struct V_7 * V_8 ,
int V_126 ,
int V_169 )
{
struct V_9 * V_10 ;
unsigned char * V_99 ;
T_1 V_100 ;
int V_170 ;
F_3 ( & V_12 -> V_47 ) ;
V_10 = V_12 -> V_10 ;
if ( ! V_10 ) {
F_6 ( & V_12 -> V_47 ) ;
F_9 ( L_35
L_36 ) ;
return - V_92 ;
}
V_170 = V_10 -> V_133 ;
if ( V_169 )
F_40 ( & V_8 -> V_83 , 1 ) ;
else
F_40 ( & V_8 -> V_83 , 0 ) ;
V_100 = V_10 -> V_121 ;
V_8 -> V_165 = ( V_126 ) ?
V_96 :
V_97 ;
F_10 ( L_23
L_37 , ( V_126 ) ? L_25 :
L_26 , F_38 ( & V_10 -> V_123 . V_124 ) ,
V_10 -> V_20 , ( V_169 ) ? L_38 : L_39 ) ;
F_6 ( & V_12 -> V_47 ) ;
if ( V_170 != 0 )
F_28 ( V_170 ) ;
if ( V_8 -> V_171 ) {
V_99 = F_46 ( V_100 , V_148 ) ;
if ( ! V_99 ) {
F_9 ( L_40
L_41 ) ;
return - V_149 ;
}
F_44 ( & V_8 -> V_172 ) ;
F_48 ( V_12 , V_8 ,
V_99 , V_100 ) ;
F_45 ( & V_8 -> V_172 ) ;
F_47 ( V_99 ) ;
}
return 0 ;
}
struct V_143 *
F_49 ( const char * V_173 , int V_174 )
{
struct V_143 * V_144 ;
V_144 = F_50 ( V_175 , V_148 ) ;
if ( ! V_144 ) {
F_9 ( L_42 ) ;
return F_51 ( - V_149 ) ;
}
F_52 ( & V_144 -> V_176 ) ;
F_52 ( & V_144 -> V_177 ) ;
F_53 ( & V_144 -> V_154 ) ;
F_40 ( & V_144 -> V_152 , 0 ) ;
if ( V_174 ) {
V_144 -> V_153 = V_178 ++ ;
V_144 -> V_179 = 1 ;
V_180 ++ ;
}
return V_144 ;
}
int F_54 ( struct V_143 * V_144 , T_2 V_153 )
{
struct V_143 * V_181 ;
T_2 V_182 ;
if ( V_144 -> V_179 ) {
F_55 ( L_43
L_44 ) ;
return - V_92 ;
}
F_3 ( & V_183 ) ;
if ( V_180 == 0x0000ffff ) {
F_9 ( L_45
L_46 ) ;
F_6 ( & V_183 ) ;
F_56 ( V_175 , V_144 ) ;
return - V_184 ;
}
V_185:
V_182 = ( V_153 != 0 ) ? V_153 :
V_178 ++ ;
F_4 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_181 -> V_153 == V_182 ) {
if ( ! V_153 )
goto V_185;
F_55 ( L_47
L_48 ,
V_153 ) ;
F_6 ( & V_183 ) ;
return - V_92 ;
}
}
V_144 -> V_153 = V_182 ;
V_144 -> V_179 = 1 ;
F_57 ( & V_144 -> V_176 , & V_186 ) ;
V_180 ++ ;
F_6 ( & V_183 ) ;
return 0 ;
}
static struct V_145 *
F_58 ( struct V_26 * V_27 )
{
struct V_145 * V_146 ;
V_146 = F_50 ( V_187 , V_148 ) ;
if ( ! V_146 ) {
F_9 ( L_49 ) ;
return F_51 ( - V_149 ) ;
}
F_52 ( & V_146 -> V_177 ) ;
F_53 ( & V_146 -> V_151 ) ;
F_40 ( & V_146 -> V_156 , 0 ) ;
V_146 -> V_155 = V_27 ;
V_27 -> V_150 = V_146 ;
return V_146 ;
}
void F_59 ( struct V_143 * V_144 )
{
struct V_145 * V_146 , * V_188 ;
F_3 ( & V_183 ) ;
F_40 ( & V_144 -> V_189 , 1 ) ;
F_60 ( & V_144 -> V_176 ) ;
V_180 -- ;
F_6 ( & V_183 ) ;
while ( F_5 ( & V_144 -> V_152 ) )
F_61 () ;
F_3 ( & V_144 -> V_154 ) ;
F_62 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_146 -> V_190 ) {
F_60 ( & V_146 -> V_177 ) ;
V_144 -> V_191 -- ;
V_146 -> V_190 = 0 ;
}
F_6 ( & V_144 -> V_154 ) ;
F_3 ( & V_146 -> V_151 ) ;
if ( V_144 != V_192 )
F_63 ( V_146 ,
V_192 ) ;
else
V_146 -> V_144 = NULL ;
F_6 ( & V_146 -> V_151 ) ;
F_3 ( & V_144 -> V_154 ) ;
}
F_6 ( & V_144 -> V_154 ) ;
F_56 ( V_175 , V_144 ) ;
}
void F_64 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_6 ;
struct V_16 * V_193 = & V_4 -> V_16 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
if ( V_193 -> V_194 != V_195 )
return;
V_146 = V_27 -> V_150 ;
if ( ! V_146 )
return;
while ( F_5 ( & V_146 -> V_156 ) )
F_61 () ;
F_3 ( & V_146 -> V_151 ) ;
V_144 = V_146 -> V_144 ;
if ( V_144 ) {
F_3 ( & V_144 -> V_154 ) ;
if ( V_146 -> V_190 ) {
F_60 ( & V_146 -> V_177 ) ;
V_144 -> V_191 -- ;
V_146 -> V_190 = 0 ;
}
F_6 ( & V_144 -> V_154 ) ;
V_146 -> V_144 = NULL ;
}
F_6 ( & V_146 -> V_151 ) ;
F_56 ( V_187 , V_146 ) ;
}
struct V_143 * F_65 ( const char * V_173 )
{
struct V_143 * V_144 ;
struct V_196 * V_197 ;
F_3 ( & V_183 ) ;
F_4 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_144 -> V_179 )
continue;
V_197 = & V_144 -> V_157 . V_124 ;
if ( ! strcmp ( F_38 ( V_197 ) , V_173 ) ) {
F_12 ( & V_144 -> V_152 ) ;
F_6 ( & V_183 ) ;
return V_144 ;
}
}
F_6 ( & V_183 ) ;
return NULL ;
}
void F_66 ( struct V_143 * V_144 )
{
F_3 ( & V_183 ) ;
F_15 ( & V_144 -> V_152 ) ;
F_6 ( & V_183 ) ;
}
void F_63 (
struct V_145 * V_146 ,
struct V_143 * V_144 )
{
F_3 ( & V_144 -> V_154 ) ;
V_146 -> V_144 = V_144 ;
V_146 -> V_190 = 1 ;
F_57 ( & V_146 -> V_177 , & V_144 -> V_177 ) ;
V_144 -> V_191 ++ ;
F_6 ( & V_144 -> V_154 ) ;
}
void F_67 (
struct V_145 * V_146 ,
struct V_143 * V_144 )
{
F_3 ( & V_144 -> V_154 ) ;
F_60 ( & V_146 -> V_177 ) ;
V_146 -> V_144 = NULL ;
V_146 -> V_190 = 0 ;
V_144 -> V_191 -- ;
F_6 ( & V_144 -> V_154 ) ;
}
struct V_9 * F_68 (
struct V_3 * V_4 ,
const char * V_173 ,
int V_174 )
{
struct V_9 * V_10 ;
V_10 = F_50 ( V_198 , V_148 ) ;
if ( ! V_10 ) {
F_9 ( L_50 ) ;
return NULL ;
}
F_52 ( & V_10 -> V_199 ) ;
F_52 ( & V_10 -> V_200 ) ;
F_69 ( & V_10 -> V_140 ) ;
F_53 ( & V_10 -> V_23 ) ;
F_40 ( & V_10 -> V_53 , 0 ) ;
V_10 -> V_117 = V_4 ;
V_10 -> V_121 = V_201 ;
F_40 ( & V_10 -> V_19 ,
V_86 ) ;
V_10 -> V_48 =
V_49 | V_202 ;
V_10 -> V_85 = V_203 ;
V_10 -> V_133 = V_204 ;
if ( V_174 ) {
F_3 ( & V_4 -> V_16 . V_17 ) ;
V_10 -> V_20 =
V_4 -> V_16 . V_205 ++ ;
V_10 -> V_52 = 1 ;
V_4 -> V_16 . V_206 ++ ;
F_57 ( & V_10 -> V_199 ,
& V_4 -> V_16 . V_207 ) ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
}
return V_10 ;
}
int F_70 (
struct V_9 * V_10 ,
T_2 V_20 )
{
struct V_3 * V_4 = V_10 -> V_117 ;
struct V_9 * V_208 ;
T_2 V_209 ;
if ( V_10 -> V_52 ) {
F_55 ( L_51
L_44 ) ;
return - V_92 ;
}
F_3 ( & V_4 -> V_16 . V_17 ) ;
if ( V_4 -> V_16 . V_206 == 0x0000ffff ) {
F_9 ( L_52
L_46 ) ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_56 ( V_198 , V_10 ) ;
return - V_184 ;
}
V_185:
V_209 = ( V_20 != 0 ) ? V_20 :
V_4 -> V_16 . V_205 ++ ;
F_4 (tg_pt_gp_tmp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_208 -> V_20 == V_209 ) {
if ( ! V_20 )
goto V_185;
F_9 ( L_53
L_54 , V_20 ) ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
return - V_92 ;
}
}
V_10 -> V_20 = V_209 ;
V_10 -> V_52 = 1 ;
F_57 ( & V_10 -> V_199 ,
& V_4 -> V_16 . V_207 ) ;
V_4 -> V_16 . V_206 ++ ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
return 0 ;
}
struct V_11 * F_71 (
struct V_7 * V_8 )
{
struct V_11 * V_12 ;
V_12 = F_50 ( V_210 ,
V_148 ) ;
if ( ! V_12 ) {
F_9 ( L_55 ) ;
return F_51 ( - V_149 ) ;
}
F_52 ( & V_12 -> V_200 ) ;
F_53 ( & V_12 -> V_47 ) ;
F_40 ( & V_12 -> V_134 , 0 ) ;
V_12 -> V_24 = V_8 ;
V_8 -> V_44 = V_12 ;
F_40 ( & V_8 -> V_211 , 1 ) ;
return V_12 ;
}
void F_72 (
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_117 ;
struct V_11 * V_12 , * V_212 ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_60 ( & V_10 -> V_199 ) ;
V_4 -> V_16 . V_205 -- ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
while ( F_5 ( & V_10 -> V_53 ) )
F_61 () ;
F_3 ( & V_10 -> V_23 ) ;
F_62 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_12 -> V_213 ) {
F_60 ( & V_12 -> V_200 ) ;
V_10 -> V_22 -- ;
V_12 -> V_213 = 0 ;
}
F_6 ( & V_10 -> V_23 ) ;
F_3 ( & V_12 -> V_47 ) ;
if ( V_10 != V_4 -> V_16 . V_214 ) {
F_73 ( V_12 ,
V_4 -> V_16 . V_214 ) ;
} else
V_12 -> V_10 = NULL ;
F_6 ( & V_12 -> V_47 ) ;
F_3 ( & V_10 -> V_23 ) ;
}
F_6 ( & V_10 -> V_23 ) ;
F_56 ( V_198 , V_10 ) ;
}
void F_74 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_167 -> V_215 -> V_6 ;
struct V_16 * V_193 = & V_4 -> V_16 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( V_193 -> V_194 != V_195 )
return;
V_12 = V_8 -> V_44 ;
if ( ! V_12 )
return;
while ( F_5 ( & V_12 -> V_134 ) )
F_61 () ;
F_3 ( & V_12 -> V_47 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
F_3 ( & V_10 -> V_23 ) ;
if ( V_12 -> V_213 ) {
F_60 ( & V_12 -> V_200 ) ;
V_10 -> V_22 -- ;
V_12 -> V_213 = 0 ;
}
F_6 ( & V_10 -> V_23 ) ;
V_12 -> V_10 = NULL ;
}
F_6 ( & V_12 -> V_47 ) ;
F_56 ( V_210 , V_12 ) ;
}
static struct V_9 * F_75 (
struct V_3 * V_4 ,
const char * V_173 )
{
struct V_9 * V_10 ;
struct V_196 * V_197 ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_4 (tg_pt_gp, &su_dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_10 -> V_52 )
continue;
V_197 = & V_10 -> V_123 . V_124 ;
if ( ! strcmp ( F_38 ( V_197 ) , V_173 ) ) {
F_12 ( & V_10 -> V_53 ) ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
return V_10 ;
}
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
return NULL ;
}
static void F_76 (
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_117 ;
F_3 ( & V_4 -> V_16 . V_17 ) ;
F_15 ( & V_10 -> V_53 ) ;
F_6 ( & V_4 -> V_16 . V_17 ) ;
}
void F_73 (
struct V_11 * V_12 ,
struct V_9 * V_10 )
{
F_3 ( & V_10 -> V_23 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_213 = 1 ;
F_57 ( & V_12 -> V_200 ,
& V_10 -> V_200 ) ;
V_10 -> V_22 ++ ;
F_6 ( & V_10 -> V_23 ) ;
}
static void F_77 (
struct V_11 * V_12 ,
struct V_9 * V_10 )
{
F_3 ( & V_10 -> V_23 ) ;
F_60 ( & V_12 -> V_200 ) ;
V_12 -> V_10 = NULL ;
V_12 -> V_213 = 0 ;
V_10 -> V_22 -- ;
F_6 ( & V_10 -> V_23 ) ;
}
T_5 F_78 ( struct V_7 * V_8 , char * V_216 )
{
struct V_3 * V_4 = V_8 -> V_167 -> V_215 -> V_6 ;
struct V_196 * V_217 ;
struct V_16 * V_193 = & V_4 -> V_16 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_5 V_37 = 0 ;
if ( V_193 -> V_194 != V_195 )
return V_37 ;
V_12 = V_8 -> V_44 ;
if ( ! V_12 )
return V_37 ;
F_3 ( & V_12 -> V_47 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
V_217 = & V_10 -> V_123 . V_124 ;
V_37 += sprintf ( V_216 , L_56
L_57
L_58
L_59 ,
F_38 ( V_217 ) , V_10 -> V_20 ,
F_24 ( F_5 (
& V_10 -> V_19 ) ) ,
F_25 (
V_10 -> V_21 ) ,
( F_5 ( & V_8 -> V_83 ) ) ?
L_12 : L_14 ,
F_25 ( V_8 -> V_165 ) ) ;
}
F_6 ( & V_12 -> V_47 ) ;
return V_37 ;
}
T_5 F_79 (
struct V_7 * V_8 ,
const char * V_216 ,
T_6 V_218 )
{
struct V_158 * V_219 ;
struct V_29 * V_81 ;
struct V_3 * V_4 = V_8 -> V_167 -> V_215 -> V_6 ;
struct V_9 * V_10 = NULL , * V_220 = NULL ;
struct V_11 * V_12 ;
unsigned char V_13 [ V_221 ] ;
int V_222 = 0 ;
V_219 = V_8 -> V_160 ;
V_81 = V_8 -> V_167 ;
if ( V_4 -> V_16 . V_194 != V_195 ) {
F_55 ( L_60
L_61 , V_219 -> V_162 -> V_163 ( V_219 ) ,
V_219 -> V_162 -> V_164 ( V_219 ) ,
F_38 ( & V_81 -> V_223 . V_124 ) ) ;
return - V_92 ;
}
if ( V_218 > V_221 ) {
F_9 ( L_62 ) ;
return - V_92 ;
}
memset ( V_13 , 0 , V_221 ) ;
memcpy ( V_13 , V_216 , V_218 ) ;
if ( strcmp ( F_80 ( V_13 ) , L_63 ) ) {
V_220 = F_75 ( V_4 ,
F_80 ( V_13 ) ) ;
if ( ! V_220 )
return - V_111 ;
}
V_12 = V_8 -> V_44 ;
if ( ! V_12 ) {
if ( V_220 )
F_76 ( V_220 ) ;
F_9 ( L_64 ) ;
return - V_92 ;
}
F_3 ( & V_12 -> V_47 ) ;
V_10 = V_12 -> V_10 ;
if ( V_10 ) {
if ( ! V_220 ) {
F_10 ( L_65
L_66
L_67
L_68 ,
V_219 -> V_162 -> V_163 ( V_219 ) ,
V_219 -> V_162 -> V_164 ( V_219 ) ,
F_38 ( & V_81 -> V_223 . V_124 ) ,
F_38 (
& V_10 -> V_123 . V_124 ) ,
V_10 -> V_20 ) ;
F_77 ( V_12 , V_10 ) ;
F_73 ( V_12 ,
V_4 -> V_16 . V_214 ) ;
F_6 ( & V_12 -> V_47 ) ;
return V_218 ;
}
F_77 ( V_12 , V_10 ) ;
V_222 = 1 ;
}
F_73 ( V_12 , V_220 ) ;
F_6 ( & V_12 -> V_47 ) ;
F_10 ( L_69
L_70 , ( V_222 ) ?
L_71 : L_72 , V_219 -> V_162 -> V_163 ( V_219 ) ,
V_219 -> V_162 -> V_164 ( V_219 ) ,
F_38 ( & V_81 -> V_223 . V_124 ) ,
F_38 ( & V_220 -> V_123 . V_124 ) ,
V_220 -> V_20 ) ;
F_76 ( V_220 ) ;
return V_218 ;
}
T_5 F_81 (
struct V_9 * V_10 ,
char * V_216 )
{
if ( ( V_10 -> V_48 & V_49 ) &&
( V_10 -> V_48 & V_202 ) )
return sprintf ( V_216 , L_73 ) ;
else if ( V_10 -> V_48 & V_202 )
return sprintf ( V_216 , L_74 ) ;
else if ( V_10 -> V_48 & V_49 )
return sprintf ( V_216 , L_75 ) ;
else
return sprintf ( V_216 , L_76 ) ;
}
T_5 F_82 (
struct V_9 * V_10 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_77 ) ;
return - V_92 ;
}
if ( ( V_224 != 0 ) && ( V_224 != 1 ) && ( V_224 != 2 ) && ( V_224 != 3 ) ) {
F_9 ( L_78
L_79 , V_224 ) ;
return - V_92 ;
}
if ( V_224 == 3 )
V_10 -> V_48 =
V_202 | V_49 ;
else if ( V_224 == 2 )
V_10 -> V_48 = V_49 ;
else if ( V_224 == 1 )
V_10 -> V_48 = V_202 ;
else
V_10 -> V_48 = 0 ;
return V_218 ;
}
T_5 F_84 (
struct V_9 * V_10 ,
char * V_216 )
{
return sprintf ( V_216 , L_80 , V_10 -> V_85 ) ;
}
T_5 F_85 (
struct V_9 * V_10 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_81 ) ;
return - V_92 ;
}
if ( V_224 > V_225 ) {
F_9 ( L_82
L_83 , V_224 ,
V_225 ) ;
return - V_92 ;
}
V_10 -> V_85 = ( int ) V_224 ;
return V_218 ;
}
T_5 F_86 (
struct V_9 * V_10 ,
char * V_216 )
{
return sprintf ( V_216 , L_80 , V_10 -> V_133 ) ;
}
T_5 F_87 (
struct V_9 * V_10 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_84 ) ;
return - V_92 ;
}
if ( V_224 > V_226 ) {
F_9 ( L_85
L_86 , V_224 ,
V_226 ) ;
return - V_92 ;
}
V_10 -> V_133 = ( int ) V_224 ;
return V_218 ;
}
T_5 F_88 (
struct V_9 * V_10 ,
char * V_216 )
{
return sprintf ( V_216 , L_80 , V_10 -> V_18 ) ;
}
T_5 F_89 (
struct V_9 * V_10 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_87 ) ;
return - V_92 ;
}
if ( ( V_224 != 0 ) && ( V_224 != 1 ) ) {
F_9 ( L_88 , V_224 ) ;
return - V_92 ;
}
V_10 -> V_18 = ( int ) V_224 ;
return V_218 ;
}
T_5 F_90 ( struct V_29 * V_81 , char * V_216 )
{
if ( ! V_81 -> V_30 )
return - V_111 ;
return sprintf ( V_216 , L_80 ,
F_5 ( & V_81 -> V_30 -> V_83 ) ) ;
}
T_5 F_91 (
struct V_29 * V_81 ,
const char * V_216 ,
T_6 V_218 )
{
struct V_11 * V_12 ;
unsigned long V_224 ;
int V_109 ;
if ( ! V_81 -> V_30 )
return - V_111 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_89 ) ;
return - V_92 ;
}
if ( ( V_224 != 0 ) && ( V_224 != 1 ) ) {
F_9 ( L_90 ,
V_224 ) ;
return - V_92 ;
}
V_12 = V_81 -> V_30 -> V_44 ;
if ( ! V_12 ) {
F_9 ( L_91 ) ;
return - V_92 ;
}
V_109 = F_17 ( V_12 ,
V_81 -> V_30 , 0 , ( int ) V_224 ) ;
if ( V_109 < 0 )
return - V_92 ;
return V_218 ;
}
T_5 F_92 (
struct V_29 * V_81 ,
char * V_216 )
{
return sprintf ( V_216 , L_80 , V_81 -> V_30 -> V_165 ) ;
}
T_5 F_93 (
struct V_29 * V_81 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_92 ) ;
return - V_92 ;
}
if ( ( V_224 != V_95 ) &&
( V_224 != V_96 ) &&
( V_224 != V_97 ) ) {
F_9 ( L_93 ,
V_224 ) ;
return - V_92 ;
}
V_81 -> V_30 -> V_165 = ( int ) V_224 ;
return V_218 ;
}
T_5 F_94 (
struct V_29 * V_81 ,
char * V_216 )
{
return sprintf ( V_216 , L_80 ,
V_81 -> V_30 -> V_171 ) ;
}
T_5 F_95 (
struct V_29 * V_81 ,
const char * V_216 ,
T_6 V_218 )
{
unsigned long V_224 ;
int V_109 ;
V_109 = F_83 ( V_216 , 0 , & V_224 ) ;
if ( V_109 < 0 ) {
F_9 ( L_94 ) ;
return - V_92 ;
}
if ( ( V_224 != 0 ) && ( V_224 != 1 ) ) {
F_9 ( L_95
L_79 , V_224 ) ;
return - V_92 ;
}
V_81 -> V_30 -> V_171 = ( int ) V_224 ;
return V_218 ;
}
int F_96 ( struct V_26 * V_27 , int V_227 )
{
struct V_3 * V_4 = V_27 -> V_6 ;
struct V_16 * V_193 = & V_4 -> V_16 ;
struct V_145 * V_146 ;
if ( ( ( V_27 -> V_228 -> V_229 == V_230 ) &&
! ( V_27 -> V_6 -> V_231 . V_232 ) ) || V_227 ) {
V_193 -> V_194 = V_233 ;
V_193 -> V_234 = & F_22 ;
F_10 ( L_96
L_97 , V_27 -> V_228 -> V_173 ) ;
return 0 ;
}
if ( V_27 -> V_228 -> V_235 ( V_27 ) >= V_236 ) {
F_10 ( L_98
L_99 , V_27 -> V_228 -> V_173 ) ;
V_146 = F_58 ( V_27 ) ;
if ( F_31 ( V_146 ) )
return F_97 ( V_146 ) ;
V_193 -> V_194 = V_195 ;
V_193 -> V_234 = & F_23 ;
F_3 ( & V_146 -> V_151 ) ;
F_63 ( V_146 ,
V_192 ) ;
F_6 ( & V_146 -> V_151 ) ;
F_10 ( L_100
L_101 ,
V_27 -> V_228 -> V_173 ) ;
} else {
V_193 -> V_194 = V_237 ;
V_193 -> V_234 = & F_22 ;
F_10 ( L_102
L_99 , V_27 -> V_228 -> V_173 ) ;
}
return 0 ;
}
