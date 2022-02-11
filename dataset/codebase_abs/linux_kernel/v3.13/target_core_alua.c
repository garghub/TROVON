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
V_12 [ V_14 ++ ] |= V_9 -> V_25 ;
V_12 [ V_14 ++ ] = ( ( V_9 -> V_26 >> 8 ) & 0xff ) ;
V_12 [ V_14 ++ ] = ( V_9 -> V_26 & 0xff ) ;
V_14 ++ ;
V_12 [ V_14 ++ ] = ( V_9 -> V_27 & 0xff ) ;
V_12 [ V_14 ++ ] = 0x00 ;
V_12 [ V_14 ++ ] = ( V_9 -> V_22 & 0xff ) ;
V_13 += 8 ;
F_4 ( & V_9 -> V_28 ) ;
F_5 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_11 -> V_29 ;
V_14 += 2 ;
V_12 [ V_14 ++ ] = ( ( V_7 -> V_30 >> 8 ) & 0xff ) ;
V_12 [ V_14 ++ ] = ( V_7 -> V_30 & 0xff ) ;
V_13 += 4 ;
}
F_7 ( & V_9 -> V_28 ) ;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_8 ( V_13 , & V_12 [ 0 ] ) ;
if ( V_15 != 0 ) {
V_12 [ 4 ] = 0x10 ;
V_7 = V_2 -> V_31 -> V_32 ;
V_11 = V_7 -> V_33 ;
if ( V_11 ) {
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 )
V_12 [ 5 ] = V_9 -> V_35 ;
F_7 ( & V_11 -> V_34 ) ;
}
}
F_9 ( V_2 ) ;
F_10 ( V_2 , V_36 ) ;
return 0 ;
}
T_1
F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_37 = V_2 -> V_31 -> V_32 ;
struct V_38 * V_39 = V_2 -> V_40 -> V_38 ;
struct V_8 * V_9 = NULL , * V_41 ;
struct V_10 * V_11 , * V_42 ;
unsigned char * V_12 ;
unsigned char * V_43 ;
T_1 V_44 = V_45 ;
T_2 V_46 = 4 ;
int V_47 , V_48 = 0 ;
T_3 V_49 , V_50 ;
if ( ! V_37 )
return V_19 ;
if ( V_2 -> V_17 < 4 ) {
F_2 ( L_5
L_6 , V_2 -> V_17 ) ;
return V_51 ;
}
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 )
return V_19 ;
V_42 = V_37 -> V_33 ;
if ( ! V_42 ) {
F_12 ( L_7 ) ;
V_44 = V_52 ;
goto V_53;
}
F_4 ( & V_42 -> V_34 ) ;
V_41 = V_42 -> V_9 ;
if ( ! V_41 ) {
F_7 ( & V_42 -> V_34 ) ;
F_12 ( L_8 ) ;
V_44 = V_52 ;
goto V_53;
}
F_7 ( & V_42 -> V_34 ) ;
if ( ! ( V_41 -> V_54 & V_55 ) ) {
F_13 ( L_9
L_10 ) ;
V_44 = V_52 ;
goto V_53;
}
V_43 = & V_12 [ 4 ] ;
while ( V_46 < V_2 -> V_17 ) {
bool V_56 = false ;
V_47 = ( V_43 [ 0 ] & 0x0f ) ;
V_44 = F_14 ( V_47 , & V_48 ) ;
if ( V_44 ) {
goto V_53;
}
if ( V_48 ) {
V_49 = F_15 ( V_43 + 2 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_57 )
continue;
if ( V_49 != V_9 -> V_26 )
continue;
F_16 ( & V_9 -> V_58 ) ;
F_17 () ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
if ( ! F_18 ( V_9 ,
V_4 , V_37 , V_39 ,
V_47 , 1 ) )
V_56 = true ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_58 ) ;
F_20 () ;
break;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
} else {
V_50 = F_15 ( V_43 + 2 ) ;
F_4 ( & V_4 -> V_59 ) ;
F_5 (port, &dev->dev_sep_list,
sep_list) {
if ( V_7 -> V_30 != V_50 )
continue;
V_11 = V_7 -> V_33 ;
F_7 ( & V_4 -> V_59 ) ;
if ( ! F_21 (
V_11 , V_7 , 1 , 1 ) )
V_56 = true ;
F_4 ( & V_4 -> V_59 ) ;
break;
}
F_7 ( & V_4 -> V_59 ) ;
}
if ( ! V_56 ) {
V_44 = V_51 ;
goto V_53;
}
V_43 += 4 ;
V_46 += 4 ;
}
V_53:
F_9 ( V_2 ) ;
if ( ! V_44 )
F_10 ( V_2 , V_36 ) ;
return V_44 ;
}
static inline int F_22 (
struct V_1 * V_2 ,
unsigned char * V_60 ,
int V_61 ,
T_4 * V_62 )
{
V_2 -> V_63 |= V_64 ;
V_2 -> V_65 = V_61 ;
return 0 ;
}
static inline int F_23 (
struct V_1 * V_2 ,
unsigned char * V_60 ,
T_4 * V_62 )
{
switch ( V_60 [ 0 ] ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
return 0 ;
case V_74 :
switch ( V_60 [ 1 ] & 0x1f ) {
case V_75 :
return 0 ;
default:
* V_62 = V_76 ;
return 1 ;
}
case V_77 :
switch ( V_60 [ 1 ] ) {
case V_78 :
return 0 ;
default:
* V_62 = V_76 ;
return 1 ;
}
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
return 0 ;
default:
* V_62 = V_76 ;
return 1 ;
}
return 0 ;
}
static inline int F_24 (
struct V_1 * V_2 ,
unsigned char * V_60 ,
T_4 * V_62 )
{
switch ( V_60 [ 0 ] ) {
case V_66 :
case V_71 :
return 0 ;
case V_74 :
switch ( V_60 [ 1 ] & 0x1f ) {
case V_75 :
return 0 ;
default:
* V_62 = V_84 ;
return 1 ;
}
case V_77 :
switch ( V_60 [ 1 ] ) {
case V_78 :
return 0 ;
default:
* V_62 = V_84 ;
return 1 ;
}
case V_79 :
case V_82 :
case V_83 :
return 0 ;
default:
* V_62 = V_84 ;
return 1 ;
}
return 0 ;
}
static inline int F_25 (
struct V_1 * V_2 ,
unsigned char * V_60 ,
T_4 * V_62 )
{
switch ( V_60 [ 0 ] ) {
case V_66 :
case V_71 :
return 0 ;
case V_74 :
switch ( V_60 [ 1 ] & 0x1f ) {
case V_75 :
return 0 ;
default:
* V_62 = V_85 ;
return 1 ;
}
case V_79 :
case V_82 :
case V_83 :
return 0 ;
default:
* V_62 = V_85 ;
return 1 ;
}
return 0 ;
}
T_1
F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_60 = V_2 -> V_16 ;
struct V_31 * V_86 = V_2 -> V_31 ;
struct V_6 * V_7 = V_86 -> V_32 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_87 , V_61 ;
T_4 V_62 ;
int V_88 ;
if ( V_4 -> V_89 -> V_90 & V_91 )
return 0 ;
if ( V_4 -> V_92 -> V_93 == V_94 )
return 0 ;
if ( ! V_7 )
return 0 ;
if ( F_6 ( & V_7 -> V_95 ) ) {
F_13 ( L_11
L_12 ) ;
V_62 = V_96 ;
V_88 = 1 ;
goto V_53;
}
V_11 = V_7 -> V_33 ;
if ( ! V_11 )
return 0 ;
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
V_87 = F_6 ( & V_9 -> V_24 ) ;
V_61 = V_9 -> V_97 ;
F_7 ( & V_11 -> V_34 ) ;
if ( V_87 == V_98 )
return 0 ;
switch ( V_87 ) {
case V_99 :
V_88 = F_22 ( V_2 , V_60 ,
V_61 , & V_62 ) ;
break;
case V_100 :
V_88 = F_23 ( V_2 , V_60 , & V_62 ) ;
break;
case V_101 :
V_88 = F_24 ( V_2 , V_60 , & V_62 ) ;
break;
case V_102 :
V_88 = F_25 ( V_2 , V_60 , & V_62 ) ;
break;
case V_103 :
default:
F_12 ( L_13 ,
V_87 ) ;
return V_18 ;
}
V_53:
if ( V_88 > 0 ) {
F_13 ( L_14
L_15
L_16 ,
V_2 -> V_104 -> V_105 () , V_62 ) ;
V_2 -> V_106 = 0x04 ;
V_2 -> V_107 = V_62 ;
return V_108 ;
}
return 0 ;
}
static T_1
F_14 ( int V_109 , int * V_48 )
{
switch ( V_109 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
* V_48 = 1 ;
break;
case V_103 :
* V_48 = 0 ;
break;
default:
F_12 ( L_13 , V_109 ) ;
return V_51 ;
}
return 0 ;
}
static char * F_27 ( int V_109 )
{
switch ( V_109 ) {
case V_98 :
return L_17 ;
case V_99 :
return L_18 ;
case V_100 :
return L_19 ;
case V_101 :
return L_20 ;
case V_103 :
return L_21 ;
default:
return L_22 ;
}
return NULL ;
}
char * F_28 ( int V_110 )
{
switch ( V_110 ) {
case V_111 :
return L_23 ;
case V_112 :
return L_24 ;
case V_113 :
return L_25 ;
default:
return L_22 ;
}
return NULL ;
}
int F_29 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_63 & V_64 ) )
return 0 ;
if ( F_30 () )
return 0 ;
if ( ! V_2 -> V_65 )
return 0 ;
F_31 ( V_2 -> V_65 ) ;
return 0 ;
}
static int F_32 (
const char * V_114 ,
unsigned char * V_115 ,
T_2 V_116 )
{
struct V_117 * V_117 = F_33 ( V_114 , V_118 | V_119 | V_120 , 0600 ) ;
int V_88 ;
if ( F_34 ( V_117 ) ) {
F_12 ( L_26 , V_114 ) ;
return - V_121 ;
}
V_88 = F_35 ( V_117 , V_115 , V_116 , 0 ) ;
if ( V_88 < 0 )
F_12 ( L_27 , V_114 ) ;
F_36 ( V_117 ) ;
return ( V_88 < 0 ) ? - V_122 : 0 ;
}
static int F_37 (
struct V_8 * V_9 ,
int V_123 ,
unsigned char * V_115 )
{
struct V_124 * V_125 = & V_9 -> V_126 -> V_124 ;
char V_114 [ V_127 ] ;
int V_46 ;
memset ( V_114 , 0 , V_127 ) ;
V_46 = snprintf ( V_115 , V_9 -> V_128 ,
L_28
L_29
L_30 ,
V_9 -> V_26 , V_123 ,
V_9 -> V_27 ) ;
snprintf ( V_114 , V_127 ,
L_31 , & V_125 -> V_129 [ 0 ] ,
F_38 ( & V_9 -> V_130 . V_131 ) ) ;
return F_32 ( V_114 , V_115 , V_46 ) ;
}
static int F_39 (
struct V_8 * V_9 ,
struct V_6 * V_37 ,
struct V_38 * V_39 ,
unsigned char * V_115 ,
int V_132 ,
int V_133 )
{
struct V_134 * V_135 ;
struct V_136 * V_137 ;
struct V_6 * V_7 ;
struct V_10 * V_138 ;
int V_139 = 0 ;
V_139 = F_6 ( & V_9 -> V_24 ) ;
F_40 ( & V_9 -> V_24 ,
V_102 ) ;
V_9 -> V_27 = ( V_133 ) ?
V_112 :
V_113 ;
if ( V_9 -> V_140 != 0 )
F_31 ( V_9 -> V_140 ) ;
F_4 ( & V_9 -> V_28 ) ;
F_5 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_138 -> V_29 ;
F_16 ( & V_138 -> V_141 ) ;
F_17 () ;
F_7 ( & V_9 -> V_28 ) ;
F_41 ( & V_7 -> V_142 ) ;
F_5 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_137 = V_135 -> V_136 ;
if ( ! V_137 )
continue;
if ( V_133 &&
( V_39 != NULL ) && ( V_39 == V_137 -> V_143 ) &&
( V_37 != NULL ) && ( V_37 == V_7 ) )
continue;
F_42 ( V_137 -> V_143 ,
V_135 -> V_144 , 0x2A ,
V_145 ) ;
}
F_43 ( & V_7 -> V_142 ) ;
F_4 ( & V_9 -> V_28 ) ;
F_19 ( & V_138 -> V_141 ) ;
F_20 () ;
}
F_7 ( & V_9 -> V_28 ) ;
if ( V_9 -> V_146 ) {
F_44 ( & V_9 -> V_147 ) ;
F_37 ( V_9 ,
V_132 , V_115 ) ;
F_45 ( & V_9 -> V_147 ) ;
}
F_40 ( & V_9 -> V_24 , V_132 ) ;
F_13 ( L_32
L_33 , ( V_133 ) ? L_34 :
L_35 , F_38 ( & V_9 -> V_130 . V_131 ) ,
V_9 -> V_26 , F_27 ( V_139 ) ,
F_27 ( V_132 ) ) ;
return 0 ;
}
int F_18 (
struct V_8 * V_41 ,
struct V_3 * V_148 ,
struct V_6 * V_37 ,
struct V_38 * V_149 ,
int V_132 ,
int V_133 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_38 * V_39 ;
struct V_150 * V_151 ;
struct V_152 * V_153 , * V_154 ;
struct V_8 * V_9 ;
unsigned char * V_115 ;
int V_48 ;
if ( F_14 ( V_132 , & V_48 ) != 0 )
return - V_155 ;
V_115 = F_46 ( V_41 -> V_128 , V_156 ) ;
if ( ! V_115 ) {
F_12 ( L_36 ) ;
return - V_157 ;
}
V_154 = V_148 -> V_158 ;
F_4 ( & V_154 -> V_159 ) ;
V_151 = V_154 -> V_151 ;
F_16 ( & V_151 -> V_160 ) ;
F_17 () ;
F_7 ( & V_154 -> V_159 ) ;
if ( ! V_151 -> V_161 ) {
F_39 ( V_41 , V_37 , V_149 ,
V_115 , V_132 , V_133 ) ;
F_19 ( & V_151 -> V_160 ) ;
F_20 () ;
F_47 ( V_115 ) ;
return 0 ;
}
F_4 ( & V_151 -> V_162 ) ;
F_5 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_153 -> V_163 ;
F_16 ( & V_153 -> V_164 ) ;
F_17 () ;
F_7 ( & V_151 -> V_162 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_57 )
continue;
if ( V_41 -> V_26 != V_9 -> V_26 )
continue;
if ( V_41 == V_9 ) {
V_7 = V_37 ;
V_39 = V_149 ;
} else {
V_7 = NULL ;
V_39 = NULL ;
}
F_16 ( & V_9 -> V_58 ) ;
F_17 () ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_39 ( V_9 , V_7 ,
V_39 , V_115 , V_132 , V_133 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_58 ) ;
F_20 () ;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_4 ( & V_151 -> V_162 ) ;
F_19 ( & V_153 -> V_164 ) ;
F_20 () ;
}
F_7 ( & V_151 -> V_162 ) ;
F_13 ( L_37
L_38 ,
F_38 ( & V_151 -> V_165 . V_131 ) ,
V_41 -> V_26 , ( V_133 ) ? L_34 : L_35 ,
F_27 ( V_132 ) ) ;
F_19 ( & V_151 -> V_160 ) ;
F_20 () ;
F_47 ( V_115 ) ;
return 0 ;
}
static int F_48 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
unsigned char * V_115 ,
T_2 V_116 )
{
struct V_166 * V_167 = V_7 -> V_168 ;
char V_114 [ V_127 ] , V_125 [ V_169 ] ;
int V_46 ;
memset ( V_114 , 0 , V_127 ) ;
memset ( V_125 , 0 , V_169 ) ;
V_46 = snprintf ( V_125 , V_169 , L_39 ,
V_167 -> V_170 -> V_171 ( V_167 ) ) ;
if ( V_167 -> V_170 -> V_172 != NULL )
snprintf ( V_125 + V_46 , V_169 - V_46 , L_40 ,
V_167 -> V_170 -> V_172 ( V_167 ) ) ;
V_46 = snprintf ( V_115 , V_116 , L_41
L_42 ,
F_6 ( & V_7 -> V_95 ) ,
V_7 -> V_173 ) ;
snprintf ( V_114 , V_127 , L_43 ,
V_167 -> V_170 -> V_105 () , V_125 ,
V_7 -> V_174 -> V_175 ) ;
return F_32 ( V_114 , V_115 , V_46 ) ;
}
static int F_21 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
int V_133 ,
int V_176 )
{
struct V_8 * V_9 ;
unsigned char * V_115 ;
T_2 V_116 ;
int V_177 ;
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
if ( ! V_9 ) {
F_7 ( & V_11 -> V_34 ) ;
F_12 ( L_44
L_45 ) ;
return - V_155 ;
}
V_177 = V_9 -> V_140 ;
if ( V_176 )
F_40 ( & V_7 -> V_95 , 1 ) ;
else
F_40 ( & V_7 -> V_95 , 0 ) ;
V_116 = V_9 -> V_128 ;
V_7 -> V_173 = ( V_133 ) ?
V_112 :
V_113 ;
F_13 ( L_32
L_46 , ( V_133 ) ? L_34 :
L_35 , F_38 ( & V_9 -> V_130 . V_131 ) ,
V_9 -> V_26 , ( V_176 ) ? L_47 : L_48 ) ;
F_7 ( & V_11 -> V_34 ) ;
if ( V_177 != 0 )
F_31 ( V_177 ) ;
if ( V_7 -> V_178 ) {
V_115 = F_46 ( V_116 , V_156 ) ;
if ( ! V_115 ) {
F_12 ( L_49
L_50 ) ;
return - V_157 ;
}
F_44 ( & V_7 -> V_179 ) ;
F_48 ( V_11 , V_7 ,
V_115 , V_116 ) ;
F_45 ( & V_7 -> V_179 ) ;
F_47 ( V_115 ) ;
}
return 0 ;
}
struct V_150 *
F_49 ( const char * V_180 , int V_181 )
{
struct V_150 * V_151 ;
V_151 = F_50 ( V_182 , V_156 ) ;
if ( ! V_151 ) {
F_12 ( L_51 ) ;
return F_51 ( - V_157 ) ;
}
F_52 ( & V_151 -> V_183 ) ;
F_52 ( & V_151 -> V_184 ) ;
F_53 ( & V_151 -> V_162 ) ;
F_40 ( & V_151 -> V_160 , 0 ) ;
if ( V_181 ) {
V_151 -> V_161 = V_185 ++ ;
V_151 -> V_186 = 1 ;
V_187 ++ ;
}
return V_151 ;
}
int F_54 ( struct V_150 * V_151 , T_3 V_161 )
{
struct V_150 * V_188 ;
T_3 V_189 ;
if ( V_151 -> V_186 ) {
F_2 ( L_52
L_53 ) ;
return - V_155 ;
}
F_4 ( & V_190 ) ;
if ( V_187 == 0x0000ffff ) {
F_12 ( L_54
L_55 ) ;
F_7 ( & V_190 ) ;
F_55 ( V_182 , V_151 ) ;
return - V_191 ;
}
V_192:
V_189 = ( V_161 != 0 ) ? V_161 :
V_185 ++ ;
F_5 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_188 -> V_161 == V_189 ) {
if ( ! V_161 )
goto V_192;
F_2 ( L_56
L_57 ,
V_161 ) ;
F_7 ( & V_190 ) ;
return - V_155 ;
}
}
V_151 -> V_161 = V_189 ;
V_151 -> V_186 = 1 ;
F_56 ( & V_151 -> V_183 , & V_193 ) ;
V_187 ++ ;
F_7 ( & V_190 ) ;
return 0 ;
}
static struct V_152 *
F_57 ( struct V_3 * V_4 )
{
struct V_152 * V_153 ;
V_153 = F_50 ( V_194 , V_156 ) ;
if ( ! V_153 ) {
F_12 ( L_58 ) ;
return F_51 ( - V_157 ) ;
}
F_52 ( & V_153 -> V_184 ) ;
F_53 ( & V_153 -> V_159 ) ;
F_40 ( & V_153 -> V_164 , 0 ) ;
V_153 -> V_163 = V_4 ;
V_4 -> V_158 = V_153 ;
return V_153 ;
}
void F_58 ( struct V_150 * V_151 )
{
struct V_152 * V_153 , * V_195 ;
F_4 ( & V_190 ) ;
F_59 ( & V_151 -> V_183 ) ;
V_187 -- ;
F_7 ( & V_190 ) ;
while ( F_6 ( & V_151 -> V_160 ) )
F_60 () ;
F_4 ( & V_151 -> V_162 ) ;
F_61 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_153 -> V_196 ) {
F_59 ( & V_153 -> V_184 ) ;
V_151 -> V_197 -- ;
V_153 -> V_196 = 0 ;
}
F_7 ( & V_151 -> V_162 ) ;
F_4 ( & V_153 -> V_159 ) ;
if ( V_151 != V_198 )
F_62 ( V_153 ,
V_198 ) ;
else
V_153 -> V_151 = NULL ;
F_7 ( & V_153 -> V_159 ) ;
F_4 ( & V_151 -> V_162 ) ;
}
F_7 ( & V_151 -> V_162 ) ;
F_55 ( V_182 , V_151 ) ;
}
void F_63 ( struct V_3 * V_4 )
{
struct V_150 * V_151 ;
struct V_152 * V_153 ;
V_153 = V_4 -> V_158 ;
if ( ! V_153 )
return;
while ( F_6 ( & V_153 -> V_164 ) )
F_60 () ;
F_4 ( & V_153 -> V_159 ) ;
V_151 = V_153 -> V_151 ;
if ( V_151 ) {
F_4 ( & V_151 -> V_162 ) ;
if ( V_153 -> V_196 ) {
F_59 ( & V_153 -> V_184 ) ;
V_151 -> V_197 -- ;
V_153 -> V_196 = 0 ;
}
F_7 ( & V_151 -> V_162 ) ;
V_153 -> V_151 = NULL ;
}
F_7 ( & V_153 -> V_159 ) ;
F_55 ( V_194 , V_153 ) ;
}
struct V_150 * F_64 ( const char * V_180 )
{
struct V_150 * V_151 ;
struct V_199 * V_200 ;
F_4 ( & V_190 ) ;
F_5 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_151 -> V_186 )
continue;
V_200 = & V_151 -> V_165 . V_131 ;
if ( ! strcmp ( F_38 ( V_200 ) , V_180 ) ) {
F_16 ( & V_151 -> V_160 ) ;
F_7 ( & V_190 ) ;
return V_151 ;
}
}
F_7 ( & V_190 ) ;
return NULL ;
}
void F_65 ( struct V_150 * V_151 )
{
F_4 ( & V_190 ) ;
F_19 ( & V_151 -> V_160 ) ;
F_7 ( & V_190 ) ;
}
void F_62 (
struct V_152 * V_153 ,
struct V_150 * V_151 )
{
F_4 ( & V_151 -> V_162 ) ;
V_153 -> V_151 = V_151 ;
V_153 -> V_196 = 1 ;
F_56 ( & V_153 -> V_184 , & V_151 -> V_184 ) ;
V_151 -> V_197 ++ ;
F_7 ( & V_151 -> V_162 ) ;
}
void F_66 (
struct V_152 * V_153 ,
struct V_150 * V_151 )
{
F_4 ( & V_151 -> V_162 ) ;
F_59 ( & V_153 -> V_184 ) ;
V_153 -> V_151 = NULL ;
V_153 -> V_196 = 0 ;
V_151 -> V_197 -- ;
F_7 ( & V_151 -> V_162 ) ;
}
struct V_8 * F_67 ( struct V_3 * V_4 ,
const char * V_180 , int V_181 )
{
struct V_8 * V_9 ;
V_9 = F_50 ( V_201 , V_156 ) ;
if ( ! V_9 ) {
F_12 ( L_59 ) ;
return NULL ;
}
F_52 ( & V_9 -> V_202 ) ;
F_52 ( & V_9 -> V_203 ) ;
F_68 ( & V_9 -> V_147 ) ;
F_53 ( & V_9 -> V_28 ) ;
F_40 ( & V_9 -> V_58 , 0 ) ;
V_9 -> V_126 = V_4 ;
V_9 -> V_128 = V_204 ;
F_40 ( & V_9 -> V_24 ,
V_98 ) ;
V_9 -> V_54 =
V_55 | V_205 ;
V_9 -> V_97 = V_206 ;
V_9 -> V_140 = V_207 ;
V_9 -> V_35 = V_208 ;
V_9 -> V_25 =
V_209 | V_210 |
V_211 | V_212 | V_213 | V_214 ;
if ( V_181 ) {
F_4 ( & V_4 -> V_20 . V_21 ) ;
V_9 -> V_26 =
V_4 -> V_20 . V_215 ++ ;
V_9 -> V_57 = 1 ;
V_4 -> V_20 . V_216 ++ ;
F_56 ( & V_9 -> V_202 ,
& V_4 -> V_20 . V_217 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
return V_9 ;
}
int F_69 (
struct V_8 * V_9 ,
T_3 V_26 )
{
struct V_3 * V_4 = V_9 -> V_126 ;
struct V_8 * V_218 ;
T_3 V_219 ;
if ( V_9 -> V_57 ) {
F_2 ( L_60
L_53 ) ;
return - V_155 ;
}
F_4 ( & V_4 -> V_20 . V_21 ) ;
if ( V_4 -> V_20 . V_216 == 0x0000ffff ) {
F_12 ( L_61
L_55 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_55 ( V_201 , V_9 ) ;
return - V_191 ;
}
V_192:
V_219 = ( V_26 != 0 ) ? V_26 :
V_4 -> V_20 . V_215 ++ ;
F_5 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_218 -> V_26 == V_219 ) {
if ( ! V_26 )
goto V_192;
F_12 ( L_62
L_63 , V_26 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return - V_155 ;
}
}
V_9 -> V_26 = V_219 ;
V_9 -> V_57 = 1 ;
F_56 ( & V_9 -> V_202 ,
& V_4 -> V_20 . V_217 ) ;
V_4 -> V_20 . V_216 ++ ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return 0 ;
}
struct V_10 * F_70 (
struct V_6 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_50 ( V_220 ,
V_156 ) ;
if ( ! V_11 ) {
F_12 ( L_64 ) ;
return F_51 ( - V_157 ) ;
}
F_52 ( & V_11 -> V_203 ) ;
F_53 ( & V_11 -> V_34 ) ;
F_40 ( & V_11 -> V_141 , 0 ) ;
V_11 -> V_29 = V_7 ;
V_7 -> V_33 = V_11 ;
return V_11 ;
}
void F_71 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_126 ;
struct V_10 * V_11 , * V_221 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_59 ( & V_9 -> V_202 ) ;
V_4 -> V_20 . V_215 -- ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
while ( F_6 ( & V_9 -> V_58 ) )
F_60 () ;
F_4 ( & V_9 -> V_28 ) ;
F_61 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_11 -> V_222 ) {
F_59 ( & V_11 -> V_203 ) ;
V_9 -> V_22 -- ;
V_11 -> V_222 = 0 ;
}
F_7 ( & V_9 -> V_28 ) ;
F_4 ( & V_11 -> V_34 ) ;
if ( V_9 != V_4 -> V_20 . V_223 ) {
F_72 ( V_11 ,
V_4 -> V_20 . V_223 ) ;
} else
V_11 -> V_9 = NULL ;
F_7 ( & V_11 -> V_34 ) ;
F_4 ( & V_9 -> V_28 ) ;
}
F_7 ( & V_9 -> V_28 ) ;
F_55 ( V_201 , V_9 ) ;
}
void F_73 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_11 = V_7 -> V_33 ;
if ( ! V_11 )
return;
while ( F_6 ( & V_11 -> V_141 ) )
F_60 () ;
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
F_4 ( & V_9 -> V_28 ) ;
if ( V_11 -> V_222 ) {
F_59 ( & V_11 -> V_203 ) ;
V_9 -> V_22 -- ;
V_11 -> V_222 = 0 ;
}
F_7 ( & V_9 -> V_28 ) ;
V_11 -> V_9 = NULL ;
}
F_7 ( & V_11 -> V_34 ) ;
F_55 ( V_220 , V_11 ) ;
}
static struct V_8 * F_74 (
struct V_3 * V_4 , const char * V_180 )
{
struct V_8 * V_9 ;
struct V_199 * V_200 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_57 )
continue;
V_200 = & V_9 -> V_130 . V_131 ;
if ( ! strcmp ( F_38 ( V_200 ) , V_180 ) ) {
F_16 ( & V_9 -> V_58 ) ;
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
struct V_3 * V_4 = V_9 -> V_126 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_58 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
void F_72 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_28 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_222 = 1 ;
F_56 ( & V_11 -> V_203 ,
& V_9 -> V_203 ) ;
V_9 -> V_22 ++ ;
F_7 ( & V_9 -> V_28 ) ;
}
static void F_76 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_28 ) ;
F_59 ( & V_11 -> V_203 ) ;
V_11 -> V_9 = NULL ;
V_11 -> V_222 = 0 ;
V_9 -> V_22 -- ;
F_7 ( & V_9 -> V_28 ) ;
}
T_5 F_77 ( struct V_6 * V_7 , char * V_224 )
{
struct V_199 * V_225 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_5 V_46 = 0 ;
V_11 = V_7 -> V_33 ;
if ( ! V_11 )
return V_46 ;
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
V_225 = & V_9 -> V_130 . V_131 ;
V_46 += sprintf ( V_224 , L_65
L_66
L_67
L_68 ,
F_38 ( V_225 ) , V_9 -> V_26 ,
F_27 ( F_6 (
& V_9 -> V_24 ) ) ,
F_28 (
V_9 -> V_27 ) ,
( F_6 ( & V_7 -> V_95 ) ) ?
L_21 : L_23 ,
F_28 ( V_7 -> V_173 ) ) ;
}
F_7 ( & V_11 -> V_34 ) ;
return V_46 ;
}
T_5 F_78 (
struct V_6 * V_7 ,
const char * V_224 ,
T_6 V_226 )
{
struct V_166 * V_227 ;
struct V_31 * V_86 ;
struct V_3 * V_4 = V_7 -> V_174 -> V_228 ;
struct V_8 * V_9 = NULL , * V_229 = NULL ;
struct V_10 * V_11 ;
unsigned char V_12 [ V_230 ] ;
int V_231 = 0 ;
V_227 = V_7 -> V_168 ;
V_86 = V_7 -> V_174 ;
V_11 = V_7 -> V_33 ;
if ( ! V_11 )
return 0 ;
if ( V_226 > V_230 ) {
F_12 ( L_69 ) ;
return - V_155 ;
}
memset ( V_12 , 0 , V_230 ) ;
memcpy ( V_12 , V_224 , V_226 ) ;
if ( strcmp ( F_79 ( V_12 ) , L_70 ) ) {
V_229 = F_74 ( V_4 ,
F_79 ( V_12 ) ) ;
if ( ! V_229 )
return - V_121 ;
}
F_4 ( & V_11 -> V_34 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
if ( ! V_229 ) {
F_13 ( L_71
L_72
L_73
L_74 ,
V_227 -> V_170 -> V_171 ( V_227 ) ,
V_227 -> V_170 -> V_172 ( V_227 ) ,
F_38 ( & V_86 -> V_232 . V_131 ) ,
F_38 (
& V_9 -> V_130 . V_131 ) ,
V_9 -> V_26 ) ;
F_76 ( V_11 , V_9 ) ;
F_72 ( V_11 ,
V_4 -> V_20 . V_223 ) ;
F_7 ( & V_11 -> V_34 ) ;
return V_226 ;
}
F_76 ( V_11 , V_9 ) ;
V_231 = 1 ;
}
F_72 ( V_11 , V_229 ) ;
F_7 ( & V_11 -> V_34 ) ;
F_13 ( L_75
L_76 , ( V_231 ) ?
L_77 : L_78 , V_227 -> V_170 -> V_171 ( V_227 ) ,
V_227 -> V_170 -> V_172 ( V_227 ) ,
F_38 ( & V_86 -> V_232 . V_131 ) ,
F_38 ( & V_229 -> V_130 . V_131 ) ,
V_229 -> V_26 ) ;
F_75 ( V_229 ) ;
return V_226 ;
}
T_5 F_80 (
struct V_8 * V_9 ,
char * V_224 )
{
if ( ( V_9 -> V_54 & V_55 ) &&
( V_9 -> V_54 & V_205 ) )
return sprintf ( V_224 , L_79 ) ;
else if ( V_9 -> V_54 & V_205 )
return sprintf ( V_224 , L_80 ) ;
else if ( V_9 -> V_54 & V_55 )
return sprintf ( V_224 , L_81 ) ;
else
return sprintf ( V_224 , L_82 ) ;
}
T_5 F_81 (
struct V_8 * V_9 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_83 ) ;
return V_88 ;
}
if ( ( V_233 != 0 ) && ( V_233 != 1 ) && ( V_233 != 2 ) && ( V_233 != 3 ) ) {
F_12 ( L_84
L_85 , V_233 ) ;
return - V_155 ;
}
if ( V_233 == 3 )
V_9 -> V_54 =
V_205 | V_55 ;
else if ( V_233 == 2 )
V_9 -> V_54 = V_55 ;
else if ( V_233 == 1 )
V_9 -> V_54 = V_205 ;
else
V_9 -> V_54 = 0 ;
return V_226 ;
}
T_5 F_83 (
struct V_8 * V_9 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 , V_9 -> V_97 ) ;
}
T_5 F_84 (
struct V_8 * V_9 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_87 ) ;
return V_88 ;
}
if ( V_233 > V_234 ) {
F_12 ( L_88
L_89 , V_233 ,
V_234 ) ;
return - V_155 ;
}
V_9 -> V_97 = ( int ) V_233 ;
return V_226 ;
}
T_5 F_85 (
struct V_8 * V_9 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 , V_9 -> V_140 ) ;
}
T_5 F_86 (
struct V_8 * V_9 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_90 ) ;
return V_88 ;
}
if ( V_233 > V_235 ) {
F_12 ( L_91
L_92 , V_233 ,
V_235 ) ;
return - V_155 ;
}
V_9 -> V_140 = ( int ) V_233 ;
return V_226 ;
}
T_5 F_87 (
struct V_8 * V_9 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 , V_9 -> V_35 ) ;
}
T_5 F_88 (
struct V_8 * V_9 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_93 ) ;
return V_88 ;
}
if ( V_233 > V_236 ) {
F_12 ( L_94
L_95 , V_233 ,
V_236 ) ;
return - V_155 ;
}
V_9 -> V_35 = ( int ) V_233 ;
return V_226 ;
}
T_5 F_89 (
struct V_8 * V_9 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 , V_9 -> V_23 ) ;
}
T_5 F_90 (
struct V_8 * V_9 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_96 ) ;
return V_88 ;
}
if ( ( V_233 != 0 ) && ( V_233 != 1 ) ) {
F_12 ( L_97 , V_233 ) ;
return - V_155 ;
}
V_9 -> V_23 = ( int ) V_233 ;
return V_226 ;
}
T_5 F_91 ( struct V_31 * V_86 , char * V_224 )
{
if ( ! V_86 -> V_32 )
return - V_121 ;
return sprintf ( V_224 , L_86 ,
F_6 ( & V_86 -> V_32 -> V_95 ) ) ;
}
T_5 F_92 (
struct V_31 * V_86 ,
const char * V_224 ,
T_6 V_226 )
{
struct V_10 * V_11 ;
unsigned long V_233 ;
int V_88 ;
if ( ! V_86 -> V_32 )
return - V_121 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_98 ) ;
return V_88 ;
}
if ( ( V_233 != 0 ) && ( V_233 != 1 ) ) {
F_12 ( L_99 ,
V_233 ) ;
return - V_155 ;
}
V_11 = V_86 -> V_32 -> V_33 ;
if ( ! V_11 ) {
F_12 ( L_100 ) ;
return - V_155 ;
}
V_88 = F_21 ( V_11 ,
V_86 -> V_32 , 0 , ( int ) V_233 ) ;
if ( V_88 < 0 )
return - V_155 ;
return V_226 ;
}
T_5 F_93 (
struct V_31 * V_86 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 , V_86 -> V_32 -> V_173 ) ;
}
T_5 F_94 (
struct V_31 * V_86 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_101 ) ;
return V_88 ;
}
if ( ( V_233 != V_111 ) &&
( V_233 != V_112 ) &&
( V_233 != V_113 ) ) {
F_12 ( L_102 ,
V_233 ) ;
return - V_155 ;
}
V_86 -> V_32 -> V_173 = ( int ) V_233 ;
return V_226 ;
}
T_5 F_95 (
struct V_31 * V_86 ,
char * V_224 )
{
return sprintf ( V_224 , L_86 ,
V_86 -> V_32 -> V_178 ) ;
}
T_5 F_96 (
struct V_31 * V_86 ,
const char * V_224 ,
T_6 V_226 )
{
unsigned long V_233 ;
int V_88 ;
V_88 = F_82 ( V_224 , 0 , & V_233 ) ;
if ( V_88 < 0 ) {
F_12 ( L_103 ) ;
return V_88 ;
}
if ( ( V_233 != 0 ) && ( V_233 != 1 ) ) {
F_12 ( L_104
L_85 , V_233 ) ;
return - V_155 ;
}
V_86 -> V_32 -> V_178 = ( int ) V_233 ;
return V_226 ;
}
int F_97 ( struct V_3 * V_4 )
{
if ( V_4 -> V_92 -> V_93 != V_94 &&
! ( V_4 -> V_89 -> V_90 & V_91 ) ) {
struct V_152 * V_153 ;
V_153 = F_57 ( V_4 ) ;
if ( F_34 ( V_153 ) )
return F_98 ( V_153 ) ;
F_4 ( & V_153 -> V_159 ) ;
F_62 ( V_153 ,
V_198 ) ;
F_7 ( & V_153 -> V_159 ) ;
F_13 ( L_105
L_106 ,
V_4 -> V_92 -> V_180 ) ;
}
return 0 ;
}
