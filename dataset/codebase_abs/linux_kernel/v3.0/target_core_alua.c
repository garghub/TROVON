int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned char * V_12 = ( unsigned char * ) F_3 ( V_2 ) -> V_13 ;
T_1 V_14 = 0 , V_15 = 4 ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_6 (tg_pt_gp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_9 -> V_17 )
V_12 [ V_15 ] = 0x80 ;
V_12 [ V_15 ++ ] |= ( F_7 (
& V_9 -> V_18 ) & 0xff ) ;
V_12 [ V_15 ] = 0x80 ;
V_12 [ V_15 ] |= 0x40 ;
V_12 [ V_15 ] |= 0x8 ;
V_12 [ V_15 ] |= 0x4 ;
V_12 [ V_15 ] |= 0x2 ;
V_12 [ V_15 ++ ] |= 0x1 ;
V_12 [ V_15 ++ ] = ( ( V_9 -> V_19 >> 8 ) & 0xff ) ;
V_12 [ V_15 ++ ] = ( V_9 -> V_19 & 0xff ) ;
V_15 ++ ;
V_12 [ V_15 ++ ] = ( V_9 -> V_20 & 0xff ) ;
V_12 [ V_15 ++ ] = 0x00 ;
V_12 [ V_15 ++ ] = ( V_9 -> V_21 & 0xff ) ;
V_14 += 8 ;
F_4 ( & V_9 -> V_22 ) ;
F_6 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_11 -> V_23 ;
V_15 += 2 ;
V_12 [ V_15 ++ ] = ( ( V_7 -> V_24 >> 8 ) & 0xff ) ;
V_12 [ V_15 ++ ] = ( V_7 -> V_24 & 0xff ) ;
V_14 += 4 ;
}
F_8 ( & V_9 -> V_22 ) ;
}
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
V_12 [ 0 ] = ( ( V_14 >> 24 ) & 0xff ) ;
V_12 [ 1 ] = ( ( V_14 >> 16 ) & 0xff ) ;
V_12 [ 2 ] = ( ( V_14 >> 8 ) & 0xff ) ;
V_12 [ 3 ] = ( V_14 & 0xff ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 , * V_27 = F_10 ( V_2 ) -> V_28 ;
struct V_29 * V_30 = F_11 ( V_2 ) -> V_29 ;
struct V_8 * V_9 = NULL , * V_31 ;
struct V_10 * V_11 , * V_32 ;
unsigned char * V_12 = ( unsigned char * ) F_3 ( V_2 ) -> V_13 ;
unsigned char * V_33 = & V_12 [ 4 ] ;
T_1 V_34 = 4 ;
int V_35 , V_36 = 0 , V_37 ;
T_2 V_38 , V_39 ;
if ( ! ( V_27 ) )
return V_40 ;
V_32 = V_27 -> V_41 ;
if ( ! ( V_32 ) ) {
F_12 ( V_42 L_1 ) ;
return V_43 ;
}
F_4 ( & V_32 -> V_44 ) ;
V_31 = V_32 -> V_9 ;
if ( ! ( V_31 ) ) {
F_8 ( & V_32 -> V_44 ) ;
F_12 ( V_42 L_2 ) ;
return V_43 ;
}
V_37 = ( V_31 -> V_45 & V_46 ) ;
F_8 ( & V_32 -> V_44 ) ;
if ( ! ( V_37 ) ) {
F_12 ( V_47 L_3
L_4 ) ;
return V_43 ;
}
while ( V_34 < V_2 -> V_48 ) {
V_35 = ( V_33 [ 0 ] & 0x0f ) ;
V_37 = F_13 ( V_35 , & V_36 ) ;
if ( V_37 != 0 ) {
return V_49 ;
}
V_37 = - 1 ;
if ( V_36 ) {
V_38 = ( ( V_33 [ 2 ] << 8 ) & 0xff ) ;
V_38 |= ( V_33 [ 3 ] & 0xff ) ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_6 (tg_pt_gp,
&T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! ( V_9 -> V_50 ) )
continue;
if ( V_38 != V_9 -> V_19 )
continue;
F_14 ( & V_9 -> V_51 ) ;
F_15 () ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
V_37 = F_16 ( V_9 ,
V_26 , V_27 , V_30 ,
V_35 , 1 ) ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_17 ( & V_9 -> V_51 ) ;
F_18 () ;
break;
}
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
if ( V_37 != 0 )
return V_49 ;
} else {
V_39 = ( ( V_33 [ 2 ] << 8 ) & 0xff ) ;
V_39 |= ( V_33 [ 3 ] & 0xff ) ;
F_4 ( & V_26 -> V_52 ) ;
F_6 (port, &dev->dev_sep_list,
sep_list) {
if ( V_7 -> V_24 != V_39 )
continue;
V_11 = V_7 -> V_41 ;
F_8 ( & V_26 -> V_52 ) ;
V_37 = F_19 (
V_11 , V_7 , 1 , 1 ) ;
F_4 ( & V_26 -> V_52 ) ;
break;
}
F_8 ( & V_26 -> V_52 ) ;
if ( V_37 != 0 )
return V_49 ;
}
V_33 += 4 ;
V_34 += 4 ;
}
return 0 ;
}
static inline int F_20 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
int V_54 ,
T_3 * V_55 )
{
V_2 -> V_56 |= V_57 ;
V_2 -> V_58 = V_54 ;
return 0 ;
}
static inline int F_21 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
T_3 * V_55 )
{
switch ( V_53 [ 0 ] ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
switch ( V_53 [ 1 ] ) {
case V_68 :
return 0 ;
default:
* V_55 = V_69 ;
return 1 ;
}
case V_70 :
switch ( V_53 [ 1 ] ) {
case V_71 :
return 0 ;
default:
* V_55 = V_69 ;
return 1 ;
}
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
return 0 ;
default:
* V_55 = V_69 ;
return 1 ;
}
return 0 ;
}
static inline int F_22 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
T_3 * V_55 )
{
switch ( V_53 [ 0 ] ) {
case V_59 :
case V_64 :
case V_67 :
switch ( V_53 [ 1 ] ) {
case V_68 :
return 0 ;
default:
* V_55 = V_77 ;
return 1 ;
}
case V_70 :
switch ( V_53 [ 1 ] ) {
case V_71 :
return 0 ;
default:
* V_55 = V_77 ;
return 1 ;
}
case V_72 :
case V_75 :
case V_76 :
return 0 ;
default:
* V_55 = V_77 ;
return 1 ;
}
return 0 ;
}
static inline int F_23 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
T_3 * V_55 )
{
switch ( V_53 [ 0 ] ) {
case V_59 :
case V_64 :
case V_67 :
switch ( V_53 [ 1 ] ) {
case V_68 :
return 0 ;
default:
* V_55 = V_78 ;
return 1 ;
}
case V_72 :
case V_75 :
case V_76 :
return 0 ;
default:
* V_55 = V_78 ;
return 1 ;
}
return 0 ;
}
static int F_24 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
T_3 * V_55 )
{
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
unsigned char * V_53 ,
T_3 * V_55 )
{
struct V_79 * V_80 = F_10 ( V_2 ) ;
struct V_6 * V_7 = V_80 -> V_28 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_81 , V_54 ;
if ( ! ( V_7 ) )
return 0 ;
if ( F_7 ( & V_7 -> V_82 ) ) {
* V_55 = V_83 ;
F_12 ( V_47 L_5
L_6 ) ;
* V_55 = V_83 ;
return 1 ;
}
V_11 = V_7 -> V_41 ;
F_4 ( & V_11 -> V_44 ) ;
V_9 = V_11 -> V_9 ;
V_81 = F_7 ( & V_9 -> V_18 ) ;
V_54 = V_9 -> V_84 ;
F_8 ( & V_11 -> V_44 ) ;
if ( V_81 == V_85 )
return 0 ;
switch ( V_81 ) {
case V_86 :
return F_20 ( V_2 , V_53 ,
V_54 , V_55 ) ;
case V_87 :
return F_21 ( V_2 , V_53 , V_55 ) ;
case V_88 :
return F_22 ( V_2 , V_53 , V_55 ) ;
case V_89 :
return F_23 ( V_2 , V_53 , V_55 ) ;
case V_90 :
default:
F_12 ( V_42 L_7 ,
V_81 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( int V_91 , int * V_36 )
{
switch ( V_91 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
* V_36 = 1 ;
break;
case V_90 :
* V_36 = 0 ;
break;
default:
F_12 ( V_42 L_7 , V_91 ) ;
return - 1 ;
}
return 0 ;
}
static char * F_26 ( int V_91 )
{
switch ( V_91 ) {
case V_85 :
return L_8 ;
case V_86 :
return L_9 ;
case V_87 :
return L_10 ;
case V_88 :
return L_11 ;
case V_90 :
return L_12 ;
default:
return L_13 ;
}
return NULL ;
}
char * F_27 ( int V_92 )
{
switch ( V_92 ) {
case V_93 :
return L_14 ;
case V_94 :
return L_15 ;
case V_95 :
return L_16 ;
default:
return L_13 ;
}
return NULL ;
}
int F_28 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_56 & V_57 ) )
return 0 ;
if ( F_29 () )
return 0 ;
if ( ! ( V_2 -> V_58 ) )
return 0 ;
F_30 ( V_2 -> V_58 ) ;
return 0 ;
}
static int F_31 (
const char * V_96 ,
unsigned char * V_97 ,
T_1 V_98 )
{
T_4 V_99 ;
struct V_100 * V_100 ;
struct V_101 V_102 [ 1 ] ;
int V_103 = V_104 | V_105 | V_106 , V_107 ;
memset ( V_102 , 0 , sizeof( struct V_101 ) ) ;
V_100 = F_32 ( V_96 , V_103 , 0600 ) ;
if ( F_33 ( V_100 ) || ! V_100 || ! V_100 -> V_108 ) {
F_12 ( V_42 L_17 ,
V_96 ) ;
return - V_109 ;
}
V_102 [ 0 ] . V_110 = & V_97 [ 0 ] ;
V_102 [ 0 ] . V_111 = V_98 ;
V_99 = F_34 () ;
F_35 ( F_36 () ) ;
V_107 = F_37 ( V_100 , & V_102 [ 0 ] , 1 , & V_100 -> V_112 ) ;
F_35 ( V_99 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_18 , V_96 ) ;
F_38 ( V_100 , NULL ) ;
return - V_113 ;
}
F_38 ( V_100 , NULL ) ;
return 0 ;
}
static int F_39 (
struct V_8 * V_9 ,
int V_114 ,
unsigned char * V_97 )
{
struct V_3 * V_4 = V_9 -> V_115 ;
struct V_116 * V_117 = & V_4 -> V_116 ;
char V_96 [ V_118 ] ;
int V_34 ;
memset ( V_96 , 0 , V_118 ) ;
V_34 = snprintf ( V_97 , V_9 -> V_119 ,
L_19
L_20
L_21 ,
V_9 -> V_19 , V_114 ,
V_9 -> V_20 ) ;
snprintf ( V_96 , V_118 ,
L_22 , & V_117 -> V_120 [ 0 ] ,
F_40 ( & V_9 -> V_121 . V_122 ) ) ;
return F_31 ( V_96 , V_97 , V_34 ) ;
}
static int F_41 (
struct V_8 * V_9 ,
struct V_6 * V_27 ,
struct V_29 * V_30 ,
unsigned char * V_97 ,
int V_123 ,
int V_124 )
{
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_6 * V_7 ;
struct V_10 * V_129 ;
int V_130 = 0 ;
V_130 = F_7 ( & V_9 -> V_18 ) ;
F_42 ( & V_9 -> V_18 ,
V_89 ) ;
V_9 -> V_20 = ( V_124 ) ?
V_94 :
V_95 ;
if ( V_9 -> V_131 != 0 )
F_30 ( V_9 -> V_131 ) ;
F_4 ( & V_9 -> V_22 ) ;
F_6 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_129 -> V_23 ;
F_14 ( & V_129 -> V_132 ) ;
F_15 () ;
F_8 ( & V_9 -> V_22 ) ;
F_43 ( & V_7 -> V_133 ) ;
F_6 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_128 = V_126 -> V_127 ;
if ( ! ( V_128 ) )
continue;
if ( V_124 &&
( V_30 != NULL ) && ( V_30 == V_128 -> V_134 ) &&
( V_27 != NULL ) && ( V_27 == V_7 ) )
continue;
F_44 ( V_128 -> V_134 ,
V_126 -> V_135 , 0x2A ,
V_136 ) ;
}
F_45 ( & V_7 -> V_133 ) ;
F_4 ( & V_9 -> V_22 ) ;
F_17 ( & V_129 -> V_132 ) ;
F_18 () ;
}
F_8 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_137 ) {
F_46 ( & V_9 -> V_138 ) ;
F_39 ( V_9 ,
V_123 , V_97 ) ;
F_47 ( & V_9 -> V_138 ) ;
}
F_42 ( & V_9 -> V_18 , V_123 ) ;
F_12 ( V_47 L_23
L_24 , ( V_124 ) ? L_25 :
L_26 , F_40 ( & V_9 -> V_121 . V_122 ) ,
V_9 -> V_19 , F_26 ( V_130 ) ,
F_26 ( V_123 ) ) ;
return 0 ;
}
int F_16 (
struct V_8 * V_31 ,
struct V_25 * V_139 ,
struct V_6 * V_27 ,
struct V_29 * V_140 ,
int V_123 ,
int V_124 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
struct V_3 * V_4 ;
struct V_29 * V_30 ;
struct V_141 * V_142 ;
struct V_143 * V_144 , * V_145 ;
struct V_8 * V_9 ;
unsigned char * V_97 ;
int V_36 ;
if ( F_13 ( V_123 , & V_36 ) != 0 )
return - V_146 ;
V_97 = F_48 ( V_31 -> V_119 , V_147 ) ;
if ( ! ( V_97 ) ) {
F_12 ( L_27 ) ;
return - V_148 ;
}
V_145 = V_139 -> V_149 ;
F_4 ( & V_145 -> V_150 ) ;
V_142 = V_145 -> V_142 ;
F_14 ( & V_142 -> V_151 ) ;
F_15 () ;
F_8 ( & V_145 -> V_150 ) ;
if ( ! ( V_142 -> V_152 ) ) {
F_41 ( V_31 , V_27 , V_140 ,
V_97 , V_123 , V_124 ) ;
F_17 ( & V_142 -> V_151 ) ;
F_18 () ;
F_49 ( V_97 ) ;
return 0 ;
}
F_4 ( & V_142 -> V_153 ) ;
F_6 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_26 = V_144 -> V_154 ;
V_4 = V_26 -> V_5 ;
F_14 ( & V_144 -> V_155 ) ;
F_15 () ;
F_8 ( & V_142 -> V_153 ) ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_6 (tg_pt_gp,
&T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! ( V_9 -> V_50 ) )
continue;
if ( V_31 -> V_19 != V_9 -> V_19 )
continue;
if ( V_31 == V_9 ) {
V_7 = V_27 ;
V_30 = V_140 ;
} else {
V_7 = NULL ;
V_30 = NULL ;
}
F_14 ( & V_9 -> V_51 ) ;
F_15 () ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
F_41 ( V_9 , V_7 ,
V_30 , V_97 , V_123 , V_124 ) ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_17 ( & V_9 -> V_51 ) ;
F_18 () ;
}
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
F_4 ( & V_142 -> V_153 ) ;
F_17 ( & V_144 -> V_155 ) ;
F_18 () ;
}
F_8 ( & V_142 -> V_153 ) ;
F_12 ( V_47 L_28
L_29 ,
F_40 ( & V_142 -> V_156 . V_122 ) ,
V_31 -> V_19 , ( V_124 ) ? L_25 : L_26 ,
F_26 ( V_123 ) ) ;
F_17 ( & V_142 -> V_151 ) ;
F_18 () ;
F_49 ( V_97 ) ;
return 0 ;
}
static int F_50 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
unsigned char * V_97 ,
T_1 V_98 )
{
struct V_157 * V_158 = V_7 -> V_159 ;
char V_96 [ V_118 ] , V_117 [ V_160 ] ;
int V_34 ;
memset ( V_96 , 0 , V_118 ) ;
memset ( V_117 , 0 , V_160 ) ;
V_34 = snprintf ( V_117 , V_160 , L_30 ,
F_51 ( V_158 ) -> F_52 ( V_158 ) ) ;
if ( F_51 ( V_158 ) -> V_161 != NULL )
snprintf ( V_117 + V_34 , V_160 - V_34 , L_31 ,
F_51 ( V_158 ) -> V_161 ( V_158 ) ) ;
V_34 = snprintf ( V_97 , V_98 , L_32
L_33 ,
F_7 ( & V_7 -> V_82 ) ,
V_7 -> V_162 ) ;
snprintf ( V_96 , V_118 , L_34 ,
F_51 ( V_158 ) -> F_53 () , V_117 ,
V_7 -> V_163 -> V_164 ) ;
return F_31 ( V_96 , V_97 , V_34 ) ;
}
static int F_19 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
int V_124 ,
int V_165 )
{
struct V_8 * V_9 ;
unsigned char * V_97 ;
T_1 V_98 ;
int V_166 ;
F_4 ( & V_11 -> V_44 ) ;
V_9 = V_11 -> V_9 ;
if ( ! ( V_9 ) ) {
F_8 ( & V_11 -> V_44 ) ;
F_12 ( V_42 L_35
L_36 ) ;
return - 1 ;
}
V_166 = V_9 -> V_131 ;
if ( V_165 )
F_42 ( & V_7 -> V_82 , 1 ) ;
else
F_42 ( & V_7 -> V_82 , 0 ) ;
V_98 = V_9 -> V_119 ;
V_7 -> V_162 = ( V_124 ) ?
V_94 :
V_95 ;
F_12 ( V_47 L_23
L_37 , ( V_124 ) ? L_25 :
L_26 , F_40 ( & V_9 -> V_121 . V_122 ) ,
V_9 -> V_19 , ( V_165 ) ? L_38 : L_39 ) ;
F_8 ( & V_11 -> V_44 ) ;
if ( V_166 != 0 )
F_30 ( V_166 ) ;
if ( V_7 -> V_167 ) {
V_97 = F_48 ( V_98 , V_147 ) ;
if ( ! ( V_97 ) ) {
F_12 ( V_42 L_40
L_41 ) ;
return - 1 ;
}
F_46 ( & V_7 -> V_168 ) ;
F_50 ( V_11 , V_7 ,
V_97 , V_98 ) ;
F_47 ( & V_7 -> V_168 ) ;
F_49 ( V_97 ) ;
}
return 0 ;
}
struct V_141 *
F_54 ( const char * V_169 , int V_170 )
{
struct V_141 * V_142 ;
V_142 = F_55 ( V_171 , V_147 ) ;
if ( ! ( V_142 ) ) {
F_12 ( V_42 L_42 ) ;
return F_56 ( - V_148 ) ;
}
F_57 ( & V_142 -> V_172 ) ;
F_57 ( & V_142 -> V_173 ) ;
F_58 ( & V_142 -> V_153 ) ;
F_42 ( & V_142 -> V_151 , 0 ) ;
if ( V_170 ) {
V_142 -> V_152 = V_174 -> V_175 ++ ;
V_142 -> V_176 = 1 ;
V_174 -> V_177 ++ ;
}
return V_142 ;
}
int F_59 ( struct V_141 * V_142 , T_2 V_152 )
{
struct V_141 * V_178 ;
T_2 V_179 ;
if ( V_142 -> V_176 ) {
F_12 ( V_180 L_43
L_44 ) ;
return - 1 ;
}
F_4 ( & V_174 -> V_181 ) ;
if ( V_174 -> V_177 == 0x0000ffff ) {
F_12 ( V_42 L_45
L_46 ) ;
F_8 ( & V_174 -> V_181 ) ;
F_60 ( V_171 , V_142 ) ;
return - 1 ;
}
V_182:
V_179 = ( V_152 != 0 ) ? V_152 :
V_174 -> V_175 ++ ;
F_6 (lu_gp_tmp, &se_global->g_lu_gps_list, lu_gp_list) {
if ( V_178 -> V_152 == V_179 ) {
if ( ! ( V_152 ) )
goto V_182;
F_12 ( V_180 L_47
L_48 ,
V_152 ) ;
F_8 ( & V_174 -> V_181 ) ;
return - 1 ;
}
}
V_142 -> V_152 = V_179 ;
V_142 -> V_176 = 1 ;
F_61 ( & V_142 -> V_172 , & V_174 -> V_183 ) ;
V_174 -> V_177 ++ ;
F_8 ( & V_174 -> V_181 ) ;
return 0 ;
}
static struct V_143 *
F_62 ( struct V_25 * V_26 )
{
struct V_143 * V_144 ;
V_144 = F_55 ( V_184 , V_147 ) ;
if ( ! ( V_144 ) ) {
F_12 ( V_42 L_49 ) ;
return F_56 ( - V_148 ) ;
}
F_57 ( & V_144 -> V_173 ) ;
F_58 ( & V_144 -> V_150 ) ;
F_42 ( & V_144 -> V_155 , 0 ) ;
V_144 -> V_154 = V_26 ;
V_26 -> V_149 = V_144 ;
return V_144 ;
}
void F_63 ( struct V_141 * V_142 )
{
struct V_143 * V_144 , * V_185 ;
F_4 ( & V_174 -> V_181 ) ;
F_42 ( & V_142 -> V_186 , 1 ) ;
F_64 ( & V_142 -> V_172 ) ;
V_174 -> V_177 -- ;
F_8 ( & V_174 -> V_181 ) ;
while ( F_7 ( & V_142 -> V_151 ) )
F_65 () ;
F_4 ( & V_142 -> V_153 ) ;
F_66 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_144 -> V_187 ) {
F_64 ( & V_144 -> V_173 ) ;
V_142 -> V_188 -- ;
V_144 -> V_187 = 0 ;
}
F_8 ( & V_142 -> V_153 ) ;
F_4 ( & V_144 -> V_150 ) ;
if ( V_142 != V_174 -> V_189 )
F_67 ( V_144 ,
V_174 -> V_189 ) ;
else
V_144 -> V_142 = NULL ;
F_8 ( & V_144 -> V_150 ) ;
F_4 ( & V_142 -> V_153 ) ;
}
F_8 ( & V_142 -> V_153 ) ;
F_60 ( V_171 , V_142 ) ;
}
void F_68 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = V_26 -> V_5 ;
struct V_190 * V_191 = F_5 ( V_4 ) ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
if ( V_191 -> V_192 != V_193 )
return;
V_144 = V_26 -> V_149 ;
if ( ! ( V_144 ) )
return;
while ( F_7 ( & V_144 -> V_155 ) )
F_65 () ;
F_4 ( & V_144 -> V_150 ) ;
V_142 = V_144 -> V_142 ;
if ( ( V_142 ) ) {
F_4 ( & V_142 -> V_153 ) ;
if ( V_144 -> V_187 ) {
F_64 ( & V_144 -> V_173 ) ;
V_142 -> V_188 -- ;
V_144 -> V_187 = 0 ;
}
F_8 ( & V_142 -> V_153 ) ;
V_144 -> V_142 = NULL ;
}
F_8 ( & V_144 -> V_150 ) ;
F_60 ( V_184 , V_144 ) ;
}
struct V_141 * F_69 ( const char * V_169 )
{
struct V_141 * V_142 ;
struct V_194 * V_195 ;
F_4 ( & V_174 -> V_181 ) ;
F_6 (lu_gp, &se_global->g_lu_gps_list, lu_gp_list) {
if ( ! ( V_142 -> V_176 ) )
continue;
V_195 = & V_142 -> V_156 . V_122 ;
if ( ! ( strcmp ( F_40 ( V_195 ) , V_169 ) ) ) {
F_14 ( & V_142 -> V_151 ) ;
F_8 ( & V_174 -> V_181 ) ;
return V_142 ;
}
}
F_8 ( & V_174 -> V_181 ) ;
return NULL ;
}
void F_70 ( struct V_141 * V_142 )
{
F_4 ( & V_174 -> V_181 ) ;
F_17 ( & V_142 -> V_151 ) ;
F_8 ( & V_174 -> V_181 ) ;
}
void F_67 (
struct V_143 * V_144 ,
struct V_141 * V_142 )
{
F_4 ( & V_142 -> V_153 ) ;
V_144 -> V_142 = V_142 ;
V_144 -> V_187 = 1 ;
F_61 ( & V_144 -> V_173 , & V_142 -> V_173 ) ;
V_142 -> V_188 ++ ;
F_8 ( & V_142 -> V_153 ) ;
}
void F_71 (
struct V_143 * V_144 ,
struct V_141 * V_142 )
{
F_4 ( & V_142 -> V_153 ) ;
F_64 ( & V_144 -> V_173 ) ;
V_144 -> V_142 = NULL ;
V_144 -> V_187 = 0 ;
V_142 -> V_188 -- ;
F_8 ( & V_142 -> V_153 ) ;
}
struct V_8 * F_72 (
struct V_3 * V_4 ,
const char * V_169 ,
int V_170 )
{
struct V_8 * V_9 ;
V_9 = F_55 ( V_196 , V_147 ) ;
if ( ! ( V_9 ) ) {
F_12 ( V_42 L_50 ) ;
return NULL ;
}
F_57 ( & V_9 -> V_197 ) ;
F_57 ( & V_9 -> V_198 ) ;
F_73 ( & V_9 -> V_138 ) ;
F_58 ( & V_9 -> V_22 ) ;
F_42 ( & V_9 -> V_51 , 0 ) ;
V_9 -> V_115 = V_4 ;
V_9 -> V_119 = V_199 ;
F_42 ( & V_9 -> V_18 ,
V_85 ) ;
V_9 -> V_45 =
V_46 | V_200 ;
V_9 -> V_84 = V_201 ;
V_9 -> V_131 = V_202 ;
if ( V_170 ) {
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
V_9 -> V_19 =
F_5 ( V_4 ) -> V_203 ++ ;
V_9 -> V_50 = 1 ;
F_5 ( V_4 ) -> V_204 ++ ;
F_61 ( & V_9 -> V_197 ,
& F_5 ( V_4 ) -> V_205 ) ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
}
return V_9 ;
}
int F_74 (
struct V_8 * V_9 ,
T_2 V_19 )
{
struct V_3 * V_4 = V_9 -> V_115 ;
struct V_8 * V_206 ;
T_2 V_207 ;
if ( V_9 -> V_50 ) {
F_12 ( V_180 L_51
L_44 ) ;
return - 1 ;
}
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
if ( F_5 ( V_4 ) -> V_204 == 0x0000ffff ) {
F_12 ( V_42 L_52
L_46 ) ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
F_60 ( V_196 , V_9 ) ;
return - 1 ;
}
V_182:
V_207 = ( V_19 != 0 ) ? V_19 :
F_5 ( V_4 ) -> V_203 ++ ;
F_6 (tg_pt_gp_tmp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_206 -> V_19 == V_207 ) {
if ( ! ( V_19 ) )
goto V_182;
F_12 ( V_42 L_53
L_54 , V_19 ) ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
return - 1 ;
}
}
V_9 -> V_19 = V_207 ;
V_9 -> V_50 = 1 ;
F_61 ( & V_9 -> V_197 ,
& F_5 ( V_4 ) -> V_205 ) ;
F_5 ( V_4 ) -> V_204 ++ ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
return 0 ;
}
struct V_10 * F_75 (
struct V_6 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_55 ( V_208 ,
V_147 ) ;
if ( ! ( V_11 ) ) {
F_12 ( V_42 L_55 ) ;
return F_56 ( - V_148 ) ;
}
F_57 ( & V_11 -> V_198 ) ;
F_58 ( & V_11 -> V_44 ) ;
F_42 ( & V_11 -> V_132 , 0 ) ;
V_11 -> V_23 = V_7 ;
V_7 -> V_41 = V_11 ;
F_42 ( & V_7 -> V_209 , 1 ) ;
return V_11 ;
}
void F_76 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_115 ;
struct V_10 * V_11 , * V_210 ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_64 ( & V_9 -> V_197 ) ;
F_5 ( V_4 ) -> V_203 -- ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
while ( F_7 ( & V_9 -> V_51 ) )
F_65 () ;
F_4 ( & V_9 -> V_22 ) ;
F_66 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_11 -> V_211 ) {
F_64 ( & V_11 -> V_198 ) ;
V_9 -> V_21 -- ;
V_11 -> V_211 = 0 ;
}
F_8 ( & V_9 -> V_22 ) ;
F_4 ( & V_11 -> V_44 ) ;
if ( V_9 != F_5 ( V_4 ) -> V_212 ) {
F_77 ( V_11 ,
F_5 ( V_4 ) -> V_212 ) ;
} else
V_11 -> V_9 = NULL ;
F_8 ( & V_11 -> V_44 ) ;
F_4 ( & V_9 -> V_22 ) ;
}
F_8 ( & V_9 -> V_22 ) ;
F_60 ( V_196 , V_9 ) ;
}
void F_78 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_163 -> V_213 -> V_5 ;
struct V_190 * V_191 = F_5 ( V_4 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_191 -> V_192 != V_193 )
return;
V_11 = V_7 -> V_41 ;
if ( ! ( V_11 ) )
return;
while ( F_7 ( & V_11 -> V_132 ) )
F_65 () ;
F_4 ( & V_11 -> V_44 ) ;
V_9 = V_11 -> V_9 ;
if ( ( V_9 ) ) {
F_4 ( & V_9 -> V_22 ) ;
if ( V_11 -> V_211 ) {
F_64 ( & V_11 -> V_198 ) ;
V_9 -> V_21 -- ;
V_11 -> V_211 = 0 ;
}
F_8 ( & V_9 -> V_22 ) ;
V_11 -> V_9 = NULL ;
}
F_8 ( & V_11 -> V_44 ) ;
F_60 ( V_208 , V_11 ) ;
}
static struct V_8 * F_79 (
struct V_3 * V_4 ,
const char * V_169 )
{
struct V_8 * V_9 ;
struct V_194 * V_195 ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_6 (tg_pt_gp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! ( V_9 -> V_50 ) )
continue;
V_195 = & V_9 -> V_121 . V_122 ;
if ( ! ( strcmp ( F_40 ( V_195 ) , V_169 ) ) ) {
F_14 ( & V_9 -> V_51 ) ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
return V_9 ;
}
}
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
return NULL ;
}
static void F_80 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_115 ;
F_4 ( & F_5 ( V_4 ) -> V_16 ) ;
F_17 ( & V_9 -> V_51 ) ;
F_8 ( & F_5 ( V_4 ) -> V_16 ) ;
}
void F_77 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_22 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_211 = 1 ;
F_61 ( & V_11 -> V_198 ,
& V_9 -> V_198 ) ;
V_9 -> V_21 ++ ;
F_8 ( & V_9 -> V_22 ) ;
}
static void F_81 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_22 ) ;
F_64 ( & V_11 -> V_198 ) ;
V_11 -> V_9 = NULL ;
V_11 -> V_211 = 0 ;
V_9 -> V_21 -- ;
F_8 ( & V_9 -> V_22 ) ;
}
T_5 F_82 ( struct V_6 * V_7 , char * V_214 )
{
struct V_3 * V_4 = V_7 -> V_163 -> V_213 -> V_5 ;
struct V_194 * V_215 ;
struct V_190 * V_191 = F_5 ( V_4 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_5 V_34 = 0 ;
if ( V_191 -> V_192 != V_193 )
return V_34 ;
V_11 = V_7 -> V_41 ;
if ( ! ( V_11 ) )
return V_34 ;
F_4 ( & V_11 -> V_44 ) ;
V_9 = V_11 -> V_9 ;
if ( ( V_9 ) ) {
V_215 = & V_9 -> V_121 . V_122 ;
V_34 += sprintf ( V_214 , L_56
L_57
L_58
L_59 ,
F_40 ( V_215 ) , V_9 -> V_19 ,
F_26 ( F_7 (
& V_9 -> V_18 ) ) ,
F_27 (
V_9 -> V_20 ) ,
( F_7 ( & V_7 -> V_82 ) ) ?
L_12 : L_14 ,
F_27 ( V_7 -> V_162 ) ) ;
}
F_8 ( & V_11 -> V_44 ) ;
return V_34 ;
}
T_5 F_83 (
struct V_6 * V_7 ,
const char * V_214 ,
T_6 V_216 )
{
struct V_157 * V_217 ;
struct V_79 * V_80 ;
struct V_3 * V_4 = V_7 -> V_163 -> V_213 -> V_5 ;
struct V_8 * V_9 = NULL , * V_218 = NULL ;
struct V_10 * V_11 ;
unsigned char V_12 [ V_219 ] ;
int V_220 = 0 ;
V_217 = V_7 -> V_159 ;
V_80 = V_7 -> V_163 ;
if ( F_5 ( V_4 ) -> V_192 != V_193 ) {
F_12 ( V_180 L_60
L_61 , F_51 ( V_217 ) -> F_52 ( V_217 ) ,
F_51 ( V_217 ) -> V_161 ( V_217 ) ,
F_40 ( & V_80 -> V_221 . V_122 ) ) ;
return - V_146 ;
}
if ( V_216 > V_219 ) {
F_12 ( V_42 L_62 ) ;
return - V_146 ;
}
memset ( V_12 , 0 , V_219 ) ;
memcpy ( V_12 , V_214 , V_216 ) ;
if ( strcmp ( F_84 ( V_12 ) , L_63 ) ) {
V_218 = F_79 ( V_4 ,
F_84 ( V_12 ) ) ;
if ( ! ( V_218 ) )
return - V_109 ;
}
V_11 = V_7 -> V_41 ;
if ( ! ( V_11 ) ) {
if ( V_218 )
F_80 ( V_218 ) ;
F_12 ( V_42 L_64 ) ;
return - V_146 ;
}
F_4 ( & V_11 -> V_44 ) ;
V_9 = V_11 -> V_9 ;
if ( ( V_9 ) ) {
if ( ! ( V_218 ) ) {
F_12 ( V_47 L_65
L_66
L_67
L_68 ,
F_51 ( V_217 ) -> F_52 ( V_217 ) ,
F_51 ( V_217 ) -> V_161 ( V_217 ) ,
F_40 ( & V_80 -> V_221 . V_122 ) ,
F_40 (
& V_9 -> V_121 . V_122 ) ,
V_9 -> V_19 ) ;
F_81 ( V_11 , V_9 ) ;
F_77 ( V_11 ,
F_5 ( V_4 ) -> V_212 ) ;
F_8 ( & V_11 -> V_44 ) ;
return V_216 ;
}
F_81 ( V_11 , V_9 ) ;
V_220 = 1 ;
}
F_77 ( V_11 , V_218 ) ;
F_8 ( & V_11 -> V_44 ) ;
F_12 ( V_47 L_69
L_70 , ( V_220 ) ?
L_71 : L_72 , F_51 ( V_217 ) -> F_52 ( V_217 ) ,
F_51 ( V_217 ) -> V_161 ( V_217 ) ,
F_40 ( & V_80 -> V_221 . V_122 ) ,
F_40 ( & V_218 -> V_121 . V_122 ) ,
V_218 -> V_19 ) ;
F_80 ( V_218 ) ;
return V_216 ;
}
T_5 F_85 (
struct V_8 * V_9 ,
char * V_214 )
{
if ( ( V_9 -> V_45 & V_46 ) &&
( V_9 -> V_45 & V_200 ) )
return sprintf ( V_214 , L_73 ) ;
else if ( V_9 -> V_45 & V_200 )
return sprintf ( V_214 , L_74 ) ;
else if ( V_9 -> V_45 & V_46 )
return sprintf ( V_214 , L_75 ) ;
else
return sprintf ( V_214 , L_76 ) ;
}
T_5 F_86 (
struct V_8 * V_9 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_77 ) ;
return - V_146 ;
}
if ( ( V_222 != 0 ) && ( V_222 != 1 ) && ( V_222 != 2 ) && ( V_222 != 3 ) ) {
F_12 ( V_42 L_78
L_79 , V_222 ) ;
return - V_146 ;
}
if ( V_222 == 3 )
V_9 -> V_45 =
V_200 | V_46 ;
else if ( V_222 == 2 )
V_9 -> V_45 = V_46 ;
else if ( V_222 == 1 )
V_9 -> V_45 = V_200 ;
else
V_9 -> V_45 = 0 ;
return V_216 ;
}
T_5 F_88 (
struct V_8 * V_9 ,
char * V_214 )
{
return sprintf ( V_214 , L_80 , V_9 -> V_84 ) ;
}
T_5 F_89 (
struct V_8 * V_9 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_81 ) ;
return - V_146 ;
}
if ( V_222 > V_223 ) {
F_12 ( V_42 L_82
L_83 , V_222 ,
V_223 ) ;
return - V_146 ;
}
V_9 -> V_84 = ( int ) V_222 ;
return V_216 ;
}
T_5 F_90 (
struct V_8 * V_9 ,
char * V_214 )
{
return sprintf ( V_214 , L_80 , V_9 -> V_131 ) ;
}
T_5 F_91 (
struct V_8 * V_9 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_84 ) ;
return - V_146 ;
}
if ( V_222 > V_224 ) {
F_12 ( V_42 L_85
L_86 , V_222 ,
V_224 ) ;
return - V_146 ;
}
V_9 -> V_131 = ( int ) V_222 ;
return V_216 ;
}
T_5 F_92 (
struct V_8 * V_9 ,
char * V_214 )
{
return sprintf ( V_214 , L_80 , V_9 -> V_17 ) ;
}
T_5 F_93 (
struct V_8 * V_9 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_87 ) ;
return - V_146 ;
}
if ( ( V_222 != 0 ) && ( V_222 != 1 ) ) {
F_12 ( V_42 L_88 , V_222 ) ;
return - V_146 ;
}
V_9 -> V_17 = ( int ) V_222 ;
return V_216 ;
}
T_5 F_94 ( struct V_79 * V_80 , char * V_214 )
{
if ( ! ( V_80 -> V_28 ) )
return - V_109 ;
return sprintf ( V_214 , L_80 ,
F_7 ( & V_80 -> V_28 -> V_82 ) ) ;
}
T_5 F_95 (
struct V_79 * V_80 ,
const char * V_214 ,
T_6 V_216 )
{
struct V_10 * V_11 ;
unsigned long V_222 ;
int V_107 ;
if ( ! ( V_80 -> V_28 ) )
return - V_109 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_89 ) ;
return - V_146 ;
}
if ( ( V_222 != 0 ) && ( V_222 != 1 ) ) {
F_12 ( V_42 L_90 ,
V_222 ) ;
return - V_146 ;
}
V_11 = V_80 -> V_28 -> V_41 ;
if ( ! ( V_11 ) ) {
F_12 ( V_42 L_91 ) ;
return - V_146 ;
}
V_107 = F_19 ( V_11 ,
V_80 -> V_28 , 0 , ( int ) V_222 ) ;
if ( V_107 < 0 )
return - V_146 ;
return V_216 ;
}
T_5 F_96 (
struct V_79 * V_80 ,
char * V_214 )
{
return sprintf ( V_214 , L_80 , V_80 -> V_28 -> V_162 ) ;
}
T_5 F_97 (
struct V_79 * V_80 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_92 ) ;
return - V_146 ;
}
if ( ( V_222 != V_93 ) &&
( V_222 != V_94 ) &&
( V_222 != V_95 ) ) {
F_12 ( V_42 L_93 ,
V_222 ) ;
return - V_146 ;
}
V_80 -> V_28 -> V_162 = ( int ) V_222 ;
return V_216 ;
}
T_5 F_98 (
struct V_79 * V_80 ,
char * V_214 )
{
return sprintf ( V_214 , L_80 ,
V_80 -> V_28 -> V_167 ) ;
}
T_5 F_99 (
struct V_79 * V_80 ,
const char * V_214 ,
T_6 V_216 )
{
unsigned long V_222 ;
int V_107 ;
V_107 = F_87 ( V_214 , 0 , & V_222 ) ;
if ( V_107 < 0 ) {
F_12 ( V_42 L_94 ) ;
return - V_146 ;
}
if ( ( V_222 != 0 ) && ( V_222 != 1 ) ) {
F_12 ( V_42 L_95
L_79 , V_222 ) ;
return - V_146 ;
}
V_80 -> V_28 -> V_167 = ( int ) V_222 ;
return V_216 ;
}
int F_100 ( struct V_25 * V_26 , int V_225 )
{
struct V_3 * V_4 = V_26 -> V_5 ;
struct V_190 * V_191 = F_5 ( V_4 ) ;
struct V_143 * V_144 ;
if ( ( ( F_101 ( V_26 ) -> V_226 == V_227 ) &&
! ( F_102 ( V_26 ) -> V_228 ) ) || V_225 ) {
V_191 -> V_192 = V_229 ;
V_191 -> V_230 = & F_24 ;
F_12 ( V_47 L_96
L_97 , F_101 ( V_26 ) -> V_169 ) ;
return 0 ;
}
if ( F_101 ( V_26 ) -> F_103 ( V_26 ) >= V_231 ) {
F_12 ( V_47 L_98
L_99 , F_101 ( V_26 ) -> V_169 ) ;
V_144 = F_62 ( V_26 ) ;
if ( F_33 ( V_144 ) || ! V_144 )
return - 1 ;
V_191 -> V_192 = V_193 ;
V_191 -> V_230 = & F_25 ;
F_4 ( & V_144 -> V_150 ) ;
F_67 ( V_144 ,
V_174 -> V_189 ) ;
F_8 ( & V_144 -> V_150 ) ;
F_12 ( V_47 L_100
L_101 ,
F_101 ( V_26 ) -> V_169 ) ;
} else {
V_191 -> V_192 = V_232 ;
V_191 -> V_230 = & F_24 ;
F_12 ( V_47 L_102
L_99 , F_101 ( V_26 ) -> V_169 ) ;
}
return 0 ;
}
