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
T_5 V_116 ;
struct V_117 * V_117 ;
struct V_118 V_119 [ 1 ] ;
int V_120 = V_121 | V_122 | V_123 , V_87 ;
memset ( V_119 , 0 , sizeof( struct V_118 ) ) ;
V_117 = F_33 ( V_113 , V_120 , 0600 ) ;
if ( F_34 ( V_117 ) || ! V_117 || ! V_117 -> V_124 ) {
F_12 ( L_26 ,
V_113 ) ;
return - V_125 ;
}
V_119 [ 0 ] . V_126 = & V_114 [ 0 ] ;
V_119 [ 0 ] . V_127 = V_115 ;
V_116 = F_35 () ;
F_36 ( F_37 () ) ;
V_87 = F_38 ( V_117 , & V_119 [ 0 ] , 1 , & V_117 -> V_128 ) ;
F_36 ( V_116 ) ;
if ( V_87 < 0 ) {
F_12 ( L_27 , V_113 ) ;
F_39 ( V_117 , NULL ) ;
return - V_129 ;
}
F_39 ( V_117 , NULL ) ;
return 0 ;
}
static int F_40 (
struct V_8 * V_9 ,
int V_130 ,
unsigned char * V_114 )
{
struct V_131 * V_132 = & V_9 -> V_133 -> V_131 ;
char V_113 [ V_134 ] ;
int V_45 ;
memset ( V_113 , 0 , V_134 ) ;
V_45 = snprintf ( V_114 , V_9 -> V_135 ,
L_28
L_29
L_30 ,
V_9 -> V_25 , V_130 ,
V_9 -> V_26 ) ;
snprintf ( V_113 , V_134 ,
L_31 , & V_132 -> V_136 [ 0 ] ,
F_41 ( & V_9 -> V_137 . V_138 ) ) ;
return F_32 ( V_113 , V_114 , V_45 ) ;
}
static int F_42 (
struct V_8 * V_9 ,
struct V_6 * V_36 ,
struct V_37 * V_38 ,
unsigned char * V_114 ,
int V_139 ,
int V_140 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_6 * V_7 ;
struct V_10 * V_145 ;
int V_146 = 0 ;
V_146 = F_6 ( & V_9 -> V_24 ) ;
F_43 ( & V_9 -> V_24 ,
V_101 ) ;
V_9 -> V_26 = ( V_140 ) ?
V_111 :
V_112 ;
if ( V_9 -> V_147 != 0 )
F_31 ( V_9 -> V_147 ) ;
F_4 ( & V_9 -> V_27 ) ;
F_5 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_7 = V_145 -> V_28 ;
F_16 ( & V_145 -> V_148 ) ;
F_17 () ;
F_7 ( & V_9 -> V_27 ) ;
F_44 ( & V_7 -> V_149 ) ;
F_5 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_144 = V_142 -> V_143 ;
if ( ! V_144 )
continue;
if ( V_140 &&
( V_38 != NULL ) && ( V_38 == V_144 -> V_150 ) &&
( V_36 != NULL ) && ( V_36 == V_7 ) )
continue;
F_45 ( V_144 -> V_150 ,
V_142 -> V_151 , 0x2A ,
V_152 ) ;
}
F_46 ( & V_7 -> V_149 ) ;
F_4 ( & V_9 -> V_27 ) ;
F_19 ( & V_145 -> V_148 ) ;
F_20 () ;
}
F_7 ( & V_9 -> V_27 ) ;
if ( V_9 -> V_153 ) {
F_47 ( & V_9 -> V_154 ) ;
F_40 ( V_9 ,
V_139 , V_114 ) ;
F_48 ( & V_9 -> V_154 ) ;
}
F_43 ( & V_9 -> V_24 , V_139 ) ;
F_13 ( L_32
L_33 , ( V_140 ) ? L_34 :
L_35 , F_41 ( & V_9 -> V_137 . V_138 ) ,
V_9 -> V_25 , F_27 ( V_146 ) ,
F_27 ( V_139 ) ) ;
return 0 ;
}
int F_18 (
struct V_8 * V_40 ,
struct V_3 * V_155 ,
struct V_6 * V_36 ,
struct V_37 * V_156 ,
int V_139 ,
int V_140 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_157 * V_158 ;
struct V_159 * V_160 , * V_161 ;
struct V_8 * V_9 ;
unsigned char * V_114 ;
int V_47 ;
if ( F_14 ( V_139 , & V_47 ) != 0 )
return - V_162 ;
V_114 = F_49 ( V_40 -> V_135 , V_163 ) ;
if ( ! V_114 ) {
F_12 ( L_36 ) ;
return - V_164 ;
}
V_161 = V_155 -> V_165 ;
F_4 ( & V_161 -> V_166 ) ;
V_158 = V_161 -> V_158 ;
F_16 ( & V_158 -> V_167 ) ;
F_17 () ;
F_7 ( & V_161 -> V_166 ) ;
if ( ! V_158 -> V_168 ) {
F_42 ( V_40 , V_36 , V_156 ,
V_114 , V_139 , V_140 ) ;
F_19 ( & V_158 -> V_167 ) ;
F_20 () ;
F_50 ( V_114 ) ;
return 0 ;
}
F_4 ( & V_158 -> V_169 ) ;
F_5 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_160 -> V_170 ;
F_16 ( & V_160 -> V_171 ) ;
F_17 () ;
F_7 ( & V_158 -> V_169 ) ;
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
V_38 = V_156 ;
} else {
V_7 = NULL ;
V_38 = NULL ;
}
F_16 ( & V_9 -> V_57 ) ;
F_17 () ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_42 ( V_9 , V_7 ,
V_38 , V_114 , V_139 , V_140 ) ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_57 ) ;
F_20 () ;
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_4 ( & V_158 -> V_169 ) ;
F_19 ( & V_160 -> V_171 ) ;
F_20 () ;
}
F_7 ( & V_158 -> V_169 ) ;
F_13 ( L_37
L_38 ,
F_41 ( & V_158 -> V_172 . V_138 ) ,
V_40 -> V_25 , ( V_140 ) ? L_34 : L_35 ,
F_27 ( V_139 ) ) ;
F_19 ( & V_158 -> V_167 ) ;
F_20 () ;
F_50 ( V_114 ) ;
return 0 ;
}
static int F_51 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
unsigned char * V_114 ,
T_2 V_115 )
{
struct V_173 * V_174 = V_7 -> V_175 ;
char V_113 [ V_134 ] , V_132 [ V_176 ] ;
int V_45 ;
memset ( V_113 , 0 , V_134 ) ;
memset ( V_132 , 0 , V_176 ) ;
V_45 = snprintf ( V_132 , V_176 , L_39 ,
V_174 -> V_177 -> V_178 ( V_174 ) ) ;
if ( V_174 -> V_177 -> V_179 != NULL )
snprintf ( V_132 + V_45 , V_176 - V_45 , L_40 ,
V_174 -> V_177 -> V_179 ( V_174 ) ) ;
V_45 = snprintf ( V_114 , V_115 , L_41
L_42 ,
F_6 ( & V_7 -> V_94 ) ,
V_7 -> V_180 ) ;
snprintf ( V_113 , V_134 , L_43 ,
V_174 -> V_177 -> V_104 () , V_132 ,
V_7 -> V_181 -> V_182 ) ;
return F_32 ( V_113 , V_114 , V_45 ) ;
}
static int F_21 (
struct V_10 * V_11 ,
struct V_6 * V_7 ,
int V_140 ,
int V_183 )
{
struct V_8 * V_9 ;
unsigned char * V_114 ;
T_2 V_115 ;
int V_184 ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( ! V_9 ) {
F_7 ( & V_11 -> V_33 ) ;
F_12 ( L_44
L_45 ) ;
return - V_162 ;
}
V_184 = V_9 -> V_147 ;
if ( V_183 )
F_43 ( & V_7 -> V_94 , 1 ) ;
else
F_43 ( & V_7 -> V_94 , 0 ) ;
V_115 = V_9 -> V_135 ;
V_7 -> V_180 = ( V_140 ) ?
V_111 :
V_112 ;
F_13 ( L_32
L_46 , ( V_140 ) ? L_34 :
L_35 , F_41 ( & V_9 -> V_137 . V_138 ) ,
V_9 -> V_25 , ( V_183 ) ? L_47 : L_48 ) ;
F_7 ( & V_11 -> V_33 ) ;
if ( V_184 != 0 )
F_31 ( V_184 ) ;
if ( V_7 -> V_185 ) {
V_114 = F_49 ( V_115 , V_163 ) ;
if ( ! V_114 ) {
F_12 ( L_49
L_50 ) ;
return - V_164 ;
}
F_47 ( & V_7 -> V_186 ) ;
F_51 ( V_11 , V_7 ,
V_114 , V_115 ) ;
F_48 ( & V_7 -> V_186 ) ;
F_50 ( V_114 ) ;
}
return 0 ;
}
struct V_157 *
F_52 ( const char * V_187 , int V_188 )
{
struct V_157 * V_158 ;
V_158 = F_53 ( V_189 , V_163 ) ;
if ( ! V_158 ) {
F_12 ( L_51 ) ;
return F_54 ( - V_164 ) ;
}
F_55 ( & V_158 -> V_190 ) ;
F_55 ( & V_158 -> V_191 ) ;
F_56 ( & V_158 -> V_169 ) ;
F_43 ( & V_158 -> V_167 , 0 ) ;
if ( V_188 ) {
V_158 -> V_168 = V_192 ++ ;
V_158 -> V_193 = 1 ;
V_194 ++ ;
}
return V_158 ;
}
int F_57 ( struct V_157 * V_158 , T_3 V_168 )
{
struct V_157 * V_195 ;
T_3 V_196 ;
if ( V_158 -> V_193 ) {
F_2 ( L_52
L_53 ) ;
return - V_162 ;
}
F_4 ( & V_197 ) ;
if ( V_194 == 0x0000ffff ) {
F_12 ( L_54
L_55 ) ;
F_7 ( & V_197 ) ;
F_58 ( V_189 , V_158 ) ;
return - V_198 ;
}
V_199:
V_196 = ( V_168 != 0 ) ? V_168 :
V_192 ++ ;
F_5 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_195 -> V_168 == V_196 ) {
if ( ! V_168 )
goto V_199;
F_2 ( L_56
L_57 ,
V_168 ) ;
F_7 ( & V_197 ) ;
return - V_162 ;
}
}
V_158 -> V_168 = V_196 ;
V_158 -> V_193 = 1 ;
F_59 ( & V_158 -> V_190 , & V_200 ) ;
V_194 ++ ;
F_7 ( & V_197 ) ;
return 0 ;
}
static struct V_159 *
F_60 ( struct V_3 * V_4 )
{
struct V_159 * V_160 ;
V_160 = F_53 ( V_201 , V_163 ) ;
if ( ! V_160 ) {
F_12 ( L_58 ) ;
return F_54 ( - V_164 ) ;
}
F_55 ( & V_160 -> V_191 ) ;
F_56 ( & V_160 -> V_166 ) ;
F_43 ( & V_160 -> V_171 , 0 ) ;
V_160 -> V_170 = V_4 ;
V_4 -> V_165 = V_160 ;
return V_160 ;
}
void F_61 ( struct V_157 * V_158 )
{
struct V_159 * V_160 , * V_202 ;
F_4 ( & V_197 ) ;
F_62 ( & V_158 -> V_190 ) ;
V_194 -- ;
F_7 ( & V_197 ) ;
while ( F_6 ( & V_158 -> V_167 ) )
F_63 () ;
F_4 ( & V_158 -> V_169 ) ;
F_64 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_160 -> V_203 ) {
F_62 ( & V_160 -> V_191 ) ;
V_158 -> V_204 -- ;
V_160 -> V_203 = 0 ;
}
F_7 ( & V_158 -> V_169 ) ;
F_4 ( & V_160 -> V_166 ) ;
if ( V_158 != V_205 )
F_65 ( V_160 ,
V_205 ) ;
else
V_160 -> V_158 = NULL ;
F_7 ( & V_160 -> V_166 ) ;
F_4 ( & V_158 -> V_169 ) ;
}
F_7 ( & V_158 -> V_169 ) ;
F_58 ( V_189 , V_158 ) ;
}
void F_66 ( struct V_3 * V_4 )
{
struct V_157 * V_158 ;
struct V_159 * V_160 ;
V_160 = V_4 -> V_165 ;
if ( ! V_160 )
return;
while ( F_6 ( & V_160 -> V_171 ) )
F_63 () ;
F_4 ( & V_160 -> V_166 ) ;
V_158 = V_160 -> V_158 ;
if ( V_158 ) {
F_4 ( & V_158 -> V_169 ) ;
if ( V_160 -> V_203 ) {
F_62 ( & V_160 -> V_191 ) ;
V_158 -> V_204 -- ;
V_160 -> V_203 = 0 ;
}
F_7 ( & V_158 -> V_169 ) ;
V_160 -> V_158 = NULL ;
}
F_7 ( & V_160 -> V_166 ) ;
F_58 ( V_201 , V_160 ) ;
}
struct V_157 * F_67 ( const char * V_187 )
{
struct V_157 * V_158 ;
struct V_206 * V_207 ;
F_4 ( & V_197 ) ;
F_5 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_158 -> V_193 )
continue;
V_207 = & V_158 -> V_172 . V_138 ;
if ( ! strcmp ( F_41 ( V_207 ) , V_187 ) ) {
F_16 ( & V_158 -> V_167 ) ;
F_7 ( & V_197 ) ;
return V_158 ;
}
}
F_7 ( & V_197 ) ;
return NULL ;
}
void F_68 ( struct V_157 * V_158 )
{
F_4 ( & V_197 ) ;
F_19 ( & V_158 -> V_167 ) ;
F_7 ( & V_197 ) ;
}
void F_65 (
struct V_159 * V_160 ,
struct V_157 * V_158 )
{
F_4 ( & V_158 -> V_169 ) ;
V_160 -> V_158 = V_158 ;
V_160 -> V_203 = 1 ;
F_59 ( & V_160 -> V_191 , & V_158 -> V_191 ) ;
V_158 -> V_204 ++ ;
F_7 ( & V_158 -> V_169 ) ;
}
void F_69 (
struct V_159 * V_160 ,
struct V_157 * V_158 )
{
F_4 ( & V_158 -> V_169 ) ;
F_62 ( & V_160 -> V_191 ) ;
V_160 -> V_158 = NULL ;
V_160 -> V_203 = 0 ;
V_158 -> V_204 -- ;
F_7 ( & V_158 -> V_169 ) ;
}
struct V_8 * F_70 ( struct V_3 * V_4 ,
const char * V_187 , int V_188 )
{
struct V_8 * V_9 ;
V_9 = F_53 ( V_208 , V_163 ) ;
if ( ! V_9 ) {
F_12 ( L_59 ) ;
return NULL ;
}
F_55 ( & V_9 -> V_209 ) ;
F_55 ( & V_9 -> V_210 ) ;
F_71 ( & V_9 -> V_154 ) ;
F_56 ( & V_9 -> V_27 ) ;
F_43 ( & V_9 -> V_57 , 0 ) ;
V_9 -> V_133 = V_4 ;
V_9 -> V_135 = V_211 ;
F_43 ( & V_9 -> V_24 ,
V_97 ) ;
V_9 -> V_53 =
V_54 | V_212 ;
V_9 -> V_96 = V_213 ;
V_9 -> V_147 = V_214 ;
V_9 -> V_34 = V_215 ;
if ( V_188 ) {
F_4 ( & V_4 -> V_20 . V_21 ) ;
V_9 -> V_25 =
V_4 -> V_20 . V_216 ++ ;
V_9 -> V_56 = 1 ;
V_4 -> V_20 . V_217 ++ ;
F_59 ( & V_9 -> V_209 ,
& V_4 -> V_20 . V_218 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
return V_9 ;
}
int F_72 (
struct V_8 * V_9 ,
T_3 V_25 )
{
struct V_3 * V_4 = V_9 -> V_133 ;
struct V_8 * V_219 ;
T_3 V_220 ;
if ( V_9 -> V_56 ) {
F_2 ( L_60
L_53 ) ;
return - V_162 ;
}
F_4 ( & V_4 -> V_20 . V_21 ) ;
if ( V_4 -> V_20 . V_217 == 0x0000ffff ) {
F_12 ( L_61
L_55 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
F_58 ( V_208 , V_9 ) ;
return - V_198 ;
}
V_199:
V_220 = ( V_25 != 0 ) ? V_25 :
V_4 -> V_20 . V_216 ++ ;
F_5 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_219 -> V_25 == V_220 ) {
if ( ! V_25 )
goto V_199;
F_12 ( L_62
L_63 , V_25 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return - V_162 ;
}
}
V_9 -> V_25 = V_220 ;
V_9 -> V_56 = 1 ;
F_59 ( & V_9 -> V_209 ,
& V_4 -> V_20 . V_218 ) ;
V_4 -> V_20 . V_217 ++ ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return 0 ;
}
struct V_10 * F_73 (
struct V_6 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_53 ( V_221 ,
V_163 ) ;
if ( ! V_11 ) {
F_12 ( L_64 ) ;
return F_54 ( - V_164 ) ;
}
F_55 ( & V_11 -> V_210 ) ;
F_56 ( & V_11 -> V_33 ) ;
F_43 ( & V_11 -> V_148 , 0 ) ;
V_11 -> V_28 = V_7 ;
V_7 -> V_32 = V_11 ;
return V_11 ;
}
void F_74 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_133 ;
struct V_10 * V_11 , * V_222 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_62 ( & V_9 -> V_209 ) ;
V_4 -> V_20 . V_216 -- ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
while ( F_6 ( & V_9 -> V_57 ) )
F_63 () ;
F_4 ( & V_9 -> V_27 ) ;
F_64 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_11 -> V_223 ) {
F_62 ( & V_11 -> V_210 ) ;
V_9 -> V_22 -- ;
V_11 -> V_223 = 0 ;
}
F_7 ( & V_9 -> V_27 ) ;
F_4 ( & V_11 -> V_33 ) ;
if ( V_9 != V_4 -> V_20 . V_224 ) {
F_75 ( V_11 ,
V_4 -> V_20 . V_224 ) ;
} else
V_11 -> V_9 = NULL ;
F_7 ( & V_11 -> V_33 ) ;
F_4 ( & V_9 -> V_27 ) ;
}
F_7 ( & V_9 -> V_27 ) ;
F_58 ( V_208 , V_9 ) ;
}
void F_76 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return;
while ( F_6 ( & V_11 -> V_148 ) )
F_63 () ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
F_4 ( & V_9 -> V_27 ) ;
if ( V_11 -> V_223 ) {
F_62 ( & V_11 -> V_210 ) ;
V_9 -> V_22 -- ;
V_11 -> V_223 = 0 ;
}
F_7 ( & V_9 -> V_27 ) ;
V_11 -> V_9 = NULL ;
}
F_7 ( & V_11 -> V_33 ) ;
F_58 ( V_221 , V_11 ) ;
}
static struct V_8 * F_77 (
struct V_3 * V_4 , const char * V_187 )
{
struct V_8 * V_9 ;
struct V_206 * V_207 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_5 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_9 -> V_56 )
continue;
V_207 = & V_9 -> V_137 . V_138 ;
if ( ! strcmp ( F_41 ( V_207 ) , V_187 ) ) {
F_16 ( & V_9 -> V_57 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
return V_9 ;
}
}
F_7 ( & V_4 -> V_20 . V_21 ) ;
return NULL ;
}
static void F_78 (
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_133 ;
F_4 ( & V_4 -> V_20 . V_21 ) ;
F_19 ( & V_9 -> V_57 ) ;
F_7 ( & V_4 -> V_20 . V_21 ) ;
}
void F_75 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_27 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_223 = 1 ;
F_59 ( & V_11 -> V_210 ,
& V_9 -> V_210 ) ;
V_9 -> V_22 ++ ;
F_7 ( & V_9 -> V_27 ) ;
}
static void F_79 (
struct V_10 * V_11 ,
struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_27 ) ;
F_62 ( & V_11 -> V_210 ) ;
V_11 -> V_9 = NULL ;
V_11 -> V_223 = 0 ;
V_9 -> V_22 -- ;
F_7 ( & V_9 -> V_27 ) ;
}
T_6 F_80 ( struct V_6 * V_7 , char * V_225 )
{
struct V_206 * V_226 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_6 V_45 = 0 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return V_45 ;
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
V_226 = & V_9 -> V_137 . V_138 ;
V_45 += sprintf ( V_225 , L_65
L_66
L_67
L_68 ,
F_41 ( V_226 ) , V_9 -> V_25 ,
F_27 ( F_6 (
& V_9 -> V_24 ) ) ,
F_28 (
V_9 -> V_26 ) ,
( F_6 ( & V_7 -> V_94 ) ) ?
L_21 : L_23 ,
F_28 ( V_7 -> V_180 ) ) ;
}
F_7 ( & V_11 -> V_33 ) ;
return V_45 ;
}
T_6 F_81 (
struct V_6 * V_7 ,
const char * V_225 ,
T_7 V_227 )
{
struct V_173 * V_228 ;
struct V_30 * V_85 ;
struct V_3 * V_4 = V_7 -> V_181 -> V_229 ;
struct V_8 * V_9 = NULL , * V_230 = NULL ;
struct V_10 * V_11 ;
unsigned char V_12 [ V_231 ] ;
int V_232 = 0 ;
V_228 = V_7 -> V_175 ;
V_85 = V_7 -> V_181 ;
V_11 = V_7 -> V_32 ;
if ( ! V_11 )
return 0 ;
if ( V_227 > V_231 ) {
F_12 ( L_69 ) ;
return - V_162 ;
}
memset ( V_12 , 0 , V_231 ) ;
memcpy ( V_12 , V_225 , V_227 ) ;
if ( strcmp ( F_82 ( V_12 ) , L_70 ) ) {
V_230 = F_77 ( V_4 ,
F_82 ( V_12 ) ) ;
if ( ! V_230 )
return - V_125 ;
}
F_4 ( & V_11 -> V_33 ) ;
V_9 = V_11 -> V_9 ;
if ( V_9 ) {
if ( ! V_230 ) {
F_13 ( L_71
L_72
L_73
L_74 ,
V_228 -> V_177 -> V_178 ( V_228 ) ,
V_228 -> V_177 -> V_179 ( V_228 ) ,
F_41 ( & V_85 -> V_233 . V_138 ) ,
F_41 (
& V_9 -> V_137 . V_138 ) ,
V_9 -> V_25 ) ;
F_79 ( V_11 , V_9 ) ;
F_75 ( V_11 ,
V_4 -> V_20 . V_224 ) ;
F_7 ( & V_11 -> V_33 ) ;
return V_227 ;
}
F_79 ( V_11 , V_9 ) ;
V_232 = 1 ;
}
F_75 ( V_11 , V_230 ) ;
F_7 ( & V_11 -> V_33 ) ;
F_13 ( L_75
L_76 , ( V_232 ) ?
L_77 : L_78 , V_228 -> V_177 -> V_178 ( V_228 ) ,
V_228 -> V_177 -> V_179 ( V_228 ) ,
F_41 ( & V_85 -> V_233 . V_138 ) ,
F_41 ( & V_230 -> V_137 . V_138 ) ,
V_230 -> V_25 ) ;
F_78 ( V_230 ) ;
return V_227 ;
}
T_6 F_83 (
struct V_8 * V_9 ,
char * V_225 )
{
if ( ( V_9 -> V_53 & V_54 ) &&
( V_9 -> V_53 & V_212 ) )
return sprintf ( V_225 , L_79 ) ;
else if ( V_9 -> V_53 & V_212 )
return sprintf ( V_225 , L_80 ) ;
else if ( V_9 -> V_53 & V_54 )
return sprintf ( V_225 , L_81 ) ;
else
return sprintf ( V_225 , L_82 ) ;
}
T_6 F_84 (
struct V_8 * V_9 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_83 ) ;
return - V_162 ;
}
if ( ( V_234 != 0 ) && ( V_234 != 1 ) && ( V_234 != 2 ) && ( V_234 != 3 ) ) {
F_12 ( L_84
L_85 , V_234 ) ;
return - V_162 ;
}
if ( V_234 == 3 )
V_9 -> V_53 =
V_212 | V_54 ;
else if ( V_234 == 2 )
V_9 -> V_53 = V_54 ;
else if ( V_234 == 1 )
V_9 -> V_53 = V_212 ;
else
V_9 -> V_53 = 0 ;
return V_227 ;
}
T_6 F_86 (
struct V_8 * V_9 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 , V_9 -> V_96 ) ;
}
T_6 F_87 (
struct V_8 * V_9 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_87 ) ;
return - V_162 ;
}
if ( V_234 > V_235 ) {
F_12 ( L_88
L_89 , V_234 ,
V_235 ) ;
return - V_162 ;
}
V_9 -> V_96 = ( int ) V_234 ;
return V_227 ;
}
T_6 F_88 (
struct V_8 * V_9 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 , V_9 -> V_147 ) ;
}
T_6 F_89 (
struct V_8 * V_9 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_90 ) ;
return - V_162 ;
}
if ( V_234 > V_236 ) {
F_12 ( L_91
L_92 , V_234 ,
V_236 ) ;
return - V_162 ;
}
V_9 -> V_147 = ( int ) V_234 ;
return V_227 ;
}
T_6 F_90 (
struct V_8 * V_9 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 , V_9 -> V_34 ) ;
}
T_6 F_91 (
struct V_8 * V_9 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_93 ) ;
return - V_162 ;
}
if ( V_234 > V_237 ) {
F_12 ( L_94
L_95 , V_234 ,
V_237 ) ;
return - V_162 ;
}
V_9 -> V_34 = ( int ) V_234 ;
return V_227 ;
}
T_6 F_92 (
struct V_8 * V_9 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 , V_9 -> V_23 ) ;
}
T_6 F_93 (
struct V_8 * V_9 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_96 ) ;
return - V_162 ;
}
if ( ( V_234 != 0 ) && ( V_234 != 1 ) ) {
F_12 ( L_97 , V_234 ) ;
return - V_162 ;
}
V_9 -> V_23 = ( int ) V_234 ;
return V_227 ;
}
T_6 F_94 ( struct V_30 * V_85 , char * V_225 )
{
if ( ! V_85 -> V_31 )
return - V_125 ;
return sprintf ( V_225 , L_86 ,
F_6 ( & V_85 -> V_31 -> V_94 ) ) ;
}
T_6 F_95 (
struct V_30 * V_85 ,
const char * V_225 ,
T_7 V_227 )
{
struct V_10 * V_11 ;
unsigned long V_234 ;
int V_87 ;
if ( ! V_85 -> V_31 )
return - V_125 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_98 ) ;
return - V_162 ;
}
if ( ( V_234 != 0 ) && ( V_234 != 1 ) ) {
F_12 ( L_99 ,
V_234 ) ;
return - V_162 ;
}
V_11 = V_85 -> V_31 -> V_32 ;
if ( ! V_11 ) {
F_12 ( L_100 ) ;
return - V_162 ;
}
V_87 = F_21 ( V_11 ,
V_85 -> V_31 , 0 , ( int ) V_234 ) ;
if ( V_87 < 0 )
return - V_162 ;
return V_227 ;
}
T_6 F_96 (
struct V_30 * V_85 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 , V_85 -> V_31 -> V_180 ) ;
}
T_6 F_97 (
struct V_30 * V_85 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_101 ) ;
return - V_162 ;
}
if ( ( V_234 != V_110 ) &&
( V_234 != V_111 ) &&
( V_234 != V_112 ) ) {
F_12 ( L_102 ,
V_234 ) ;
return - V_162 ;
}
V_85 -> V_31 -> V_180 = ( int ) V_234 ;
return V_227 ;
}
T_6 F_98 (
struct V_30 * V_85 ,
char * V_225 )
{
return sprintf ( V_225 , L_86 ,
V_85 -> V_31 -> V_185 ) ;
}
T_6 F_99 (
struct V_30 * V_85 ,
const char * V_225 ,
T_7 V_227 )
{
unsigned long V_234 ;
int V_87 ;
V_87 = F_85 ( V_225 , 0 , & V_234 ) ;
if ( V_87 < 0 ) {
F_12 ( L_103 ) ;
return - V_162 ;
}
if ( ( V_234 != 0 ) && ( V_234 != 1 ) ) {
F_12 ( L_104
L_85 , V_234 ) ;
return - V_162 ;
}
V_85 -> V_31 -> V_185 = ( int ) V_234 ;
return V_227 ;
}
int F_100 ( struct V_3 * V_4 )
{
if ( V_4 -> V_91 -> V_92 != V_93 &&
! ( V_4 -> V_88 -> V_89 & V_90 ) ) {
struct V_159 * V_160 ;
V_160 = F_60 ( V_4 ) ;
if ( F_34 ( V_160 ) )
return F_101 ( V_160 ) ;
F_4 ( & V_160 -> V_166 ) ;
F_65 ( V_160 ,
V_205 ) ;
F_7 ( & V_160 -> V_166 ) ;
F_13 ( L_105
L_106 ,
V_4 -> V_91 -> V_187 ) ;
}
return 0 ;
}
