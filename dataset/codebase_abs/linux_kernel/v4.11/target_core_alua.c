T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned char * V_10 ;
T_2 V_11 = 0 , V_12 ;
if ( V_2 -> V_13 < 4 ) {
F_2 ( L_1
L_2 , V_2 -> V_13 ) ;
return V_14 ;
}
V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return V_15 ;
V_12 = 4 ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
if ( F_5 ( & V_4 -> V_16 . V_18 ) ) {
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_7 ( V_2 ) ;
return V_19 ;
}
F_8 (map, &dev->t10_alua.lba_map_list,
lba_map_list) {
int V_20 = V_12 + 3 ;
int V_21 ;
V_12 += 4 ;
if ( V_2 -> V_13 > V_12 )
F_9 ( V_7 -> V_22 , & V_10 [ V_12 ] ) ;
V_12 += 8 ;
if ( V_2 -> V_13 > V_12 )
F_9 ( V_7 -> V_23 , & V_10 [ V_12 ] ) ;
V_12 += 8 ;
V_11 += 20 ;
V_21 = 0 ;
F_8 (map_mem, &map->lba_map_mem_list,
lba_map_mem_list) {
int V_24 = V_9 -> V_25 ;
int V_26 = V_9 -> V_27 ;
if ( V_2 -> V_13 > V_12 )
V_10 [ V_12 ] = V_24 & 0x0f ;
V_12 += 2 ;
if ( V_2 -> V_13 > V_12 )
V_10 [ V_12 ] = ( V_26 >> 8 ) & 0xff ;
V_12 ++ ;
if ( V_2 -> V_13 > V_12 )
V_10 [ V_12 ] = ( V_26 & 0xff ) ;
V_12 ++ ;
V_11 += 4 ;
V_21 ++ ;
}
if ( V_2 -> V_13 > V_20 )
V_10 [ V_20 ] = V_21 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_10 ( V_11 , & V_10 [ 2 ] ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 , V_28 ) ;
return 0 ;
}
T_1
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned char * V_10 ;
T_2 V_11 = 0 , V_12 ;
int V_33 = ( V_2 -> V_34 [ 1 ] & 0x20 ) ;
if ( V_33 != 0 )
V_12 = 8 ;
else
V_12 = 4 ;
if ( V_2 -> V_13 < V_12 ) {
F_2 ( L_3
L_4 , V_2 -> V_13 ,
( V_33 ) ? L_5 : L_6 ) ;
return V_14 ;
}
V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return V_15 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ( V_12 + 8 + ( V_30 -> V_36 * 4 ) ) >
V_2 -> V_13 ) {
V_11 += 8 + ( V_30 -> V_36 * 4 ) ;
continue;
}
if ( V_30 -> V_37 )
V_10 [ V_12 ] = 0x80 ;
V_10 [ V_12 ++ ] |= V_30 -> V_38 & 0xff ;
V_10 [ V_12 ++ ] |= V_30 -> V_39 ;
V_10 [ V_12 ++ ] = ( ( V_30 -> V_40 >> 8 ) & 0xff ) ;
V_10 [ V_12 ++ ] = ( V_30 -> V_40 & 0xff ) ;
V_12 ++ ;
V_10 [ V_12 ++ ] = ( V_30 -> V_41 & 0xff ) ;
V_10 [ V_12 ++ ] = 0x00 ;
V_10 [ V_12 ++ ] = ( V_30 -> V_36 & 0xff ) ;
V_11 += 8 ;
F_4 ( & V_30 -> V_42 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
V_12 += 2 ;
V_10 [ V_12 ++ ] = ( ( V_32 -> V_43 >> 8 ) & 0xff ) ;
V_10 [ V_12 ++ ] = ( V_32 -> V_43 & 0xff ) ;
V_11 += 4 ;
}
F_6 ( & V_30 -> V_42 ) ;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_13 ( V_11 , & V_10 [ 0 ] ) ;
if ( V_33 != 0 ) {
V_10 [ 4 ] = 0x10 ;
F_4 ( & V_2 -> V_31 -> V_44 ) ;
V_30 = V_2 -> V_31 -> V_45 ;
if ( V_30 )
V_10 [ 5 ] = V_30 -> V_46 ;
F_6 ( & V_2 -> V_31 -> V_44 ) ;
}
F_7 ( V_2 ) ;
F_11 ( V_2 , V_28 ) ;
return 0 ;
}
T_1
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_47 = V_2 -> V_31 ;
struct V_48 * V_49 = V_2 -> V_50 -> V_48 ;
struct V_29 * V_30 = NULL , * V_51 ;
unsigned char * V_10 ;
unsigned char * V_52 ;
T_1 V_53 = V_54 ;
T_2 V_55 = 4 ;
int V_56 , V_57 = 0 , V_58 ;
T_3 V_59 , V_60 ;
if ( V_2 -> V_13 < 4 ) {
F_2 ( L_7
L_2 , V_2 -> V_13 ) ;
return V_61 ;
}
V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return V_15 ;
F_4 ( & V_47 -> V_44 ) ;
V_51 = V_47 -> V_45 ;
if ( ! V_51 ) {
F_6 ( & V_47 -> V_44 ) ;
F_15 ( L_8 ) ;
V_53 = V_19 ;
goto V_62;
}
if ( ! ( V_51 -> V_63 & V_64 ) ) {
F_6 ( & V_47 -> V_44 ) ;
F_16 ( L_9
L_10 ) ;
V_53 = V_19 ;
goto V_62;
}
V_58 = V_51 -> V_39 ;
F_6 ( & V_47 -> V_44 ) ;
V_52 = & V_10 [ 4 ] ;
while ( V_55 < V_2 -> V_13 ) {
bool V_65 = false ;
V_56 = ( V_52 [ 0 ] & 0x0f ) ;
V_53 = F_17 ( V_56 , V_58 ,
& V_57 , 1 ) ;
if ( V_53 ) {
goto V_62;
}
if ( V_57 ) {
V_59 = F_18 ( V_52 + 2 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
if ( V_59 != V_30 -> V_40 )
continue;
F_19 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
if ( ! F_20 ( V_30 ,
V_4 , V_47 , V_49 ,
V_56 , 1 ) )
V_65 = true ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_21 ( & V_30 -> V_67 ) ;
break;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
} else {
struct V_31 * V_32 ;
V_60 = F_18 ( V_52 + 2 ) ;
F_4 ( & V_4 -> V_68 ) ;
F_8 (lun, &dev->dev_sep_list,
lun_dev_link) {
if ( V_32 -> V_43 != V_60 )
continue;
F_6 ( & V_4 -> V_68 ) ;
if ( ! F_22 (
V_32 , 1 , 1 ) )
V_65 = true ;
F_4 ( & V_4 -> V_68 ) ;
break;
}
F_6 ( & V_4 -> V_68 ) ;
}
if ( ! V_65 ) {
V_53 = V_61 ;
goto V_62;
}
V_52 += 4 ;
V_55 += 4 ;
}
V_62:
F_7 ( V_2 ) ;
if ( ! V_53 )
F_11 ( V_2 , V_28 ) ;
return V_53 ;
}
static inline void F_23 ( struct V_1 * V_2 , T_4 V_69 )
{
F_16 ( L_11
L_12
L_13 ,
V_2 -> V_70 -> V_71 () , V_69 ) ;
V_2 -> V_72 = 0x04 ;
V_2 -> V_73 = V_69 ;
}
static inline void F_24 (
struct V_1 * V_2 ,
unsigned char * V_74 ,
int V_75 )
{
V_2 -> V_76 |= V_77 ;
V_2 -> V_78 = V_75 ;
}
static inline int F_25 (
struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_79 , V_80 , V_81 , V_82 ;
if ( ! ( V_2 -> V_76 & V_83 ) )
return 0 ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_79 = V_4 -> V_16 . V_84 ;
V_80 = V_4 -> V_16 . V_85 ;
V_81 = V_2 -> V_13 / V_4 -> V_86 . V_87 ;
V_82 = V_2 -> V_88 ;
while ( V_82 < V_2 -> V_88 + V_81 ) {
struct V_6 * V_89 = NULL , * V_7 ;
struct V_8 * V_9 ;
F_8 (map, &dev->t10_alua.lba_map_list,
lba_map_list) {
T_5 V_90 , V_91 ;
T_5 V_92 = V_7 -> V_22 ;
if ( V_80 ) {
T_5 V_93 = V_82 ;
V_90 = F_26 ( V_93 , V_79 * V_80 ) ;
V_91 = V_92 + V_79 - 1 ;
if ( V_90 >= V_92 &&
V_90 <= V_91 ) {
V_82 += V_79 ;
V_89 = V_7 ;
break;
}
} else {
V_91 = V_7 -> V_23 ;
if ( V_82 >= V_92 && V_82 <= V_91 ) {
V_82 = V_91 + 1 ;
V_89 = V_7 ;
break;
}
}
}
if ( ! V_89 ) {
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_23 ( V_2 , V_94 ) ;
return 1 ;
}
F_8 (map_mem, &cur_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_9 -> V_27 !=
V_30 -> V_40 )
continue;
switch( V_9 -> V_25 ) {
case V_95 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_23 ( V_2 , V_96 ) ;
return 1 ;
case V_97 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_23 ( V_2 , V_94 ) ;
return 1 ;
default:
break;
}
}
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
return 0 ;
}
static inline int F_27 (
struct V_1 * V_2 ,
unsigned char * V_74 )
{
switch ( V_74 [ 0 ] ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
return 0 ;
case V_107 :
switch ( V_74 [ 1 ] & 0x1f ) {
case V_108 :
return 0 ;
default:
F_23 ( V_2 , V_96 ) ;
return 1 ;
}
case V_109 :
switch ( V_74 [ 1 ] & 0x1f ) {
case V_110 :
return 0 ;
default:
F_23 ( V_2 , V_96 ) ;
return 1 ;
}
case V_111 :
switch ( V_74 [ 1 ] ) {
case V_112 :
return 0 ;
default:
F_23 ( V_2 , V_96 ) ;
return 1 ;
}
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
return 0 ;
default:
F_23 ( V_2 , V_96 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_28 (
struct V_1 * V_2 ,
unsigned char * V_74 )
{
switch ( V_74 [ 0 ] ) {
case V_98 :
case V_103 :
return 0 ;
case V_109 :
switch ( V_74 [ 1 ] & 0x1f ) {
case V_110 :
return 0 ;
default:
F_23 ( V_2 , V_94 ) ;
return 1 ;
}
case V_111 :
switch ( V_74 [ 1 ] ) {
case V_112 :
return 0 ;
default:
F_23 ( V_2 , V_94 ) ;
return 1 ;
}
case V_113 :
case V_116 :
case V_117 :
return 0 ;
default:
F_23 ( V_2 , V_94 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_29 (
struct V_1 * V_2 ,
unsigned char * V_74 )
{
switch ( V_74 [ 0 ] ) {
case V_98 :
case V_103 :
return 0 ;
case V_109 :
switch ( V_74 [ 1 ] & 0x1f ) {
case V_110 :
return 0 ;
default:
F_23 ( V_2 , V_118 ) ;
return 1 ;
}
case V_113 :
case V_116 :
case V_117 :
return 0 ;
default:
F_23 ( V_2 , V_118 ) ;
return 1 ;
}
return 0 ;
}
T_1
F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_74 = V_2 -> V_34 ;
struct V_31 * V_32 = V_2 -> V_31 ;
struct V_29 * V_30 ;
int V_119 , V_75 ;
if ( V_4 -> V_120 -> V_121 & V_122 )
return 0 ;
if ( V_4 -> V_123 -> V_124 & V_125 )
return 0 ;
if ( F_31 ( & V_32 -> V_126 ) ) {
F_16 ( L_14
L_15 ) ;
F_23 ( V_2 , V_127 ) ;
return V_128 ;
}
if ( ! V_32 -> V_45 )
return 0 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
V_119 = V_30 -> V_38 ;
V_75 = V_30 -> V_129 ;
F_6 ( & V_32 -> V_44 ) ;
if ( V_119 == V_130 )
return 0 ;
switch ( V_119 ) {
case V_131 :
F_24 ( V_2 , V_74 , V_75 ) ;
break;
case V_95 :
if ( F_27 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_97 :
if ( F_28 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_132 :
if ( F_29 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_133 :
if ( F_25 ( V_2 , V_30 ) )
return V_128 ;
break;
case V_134 :
default:
F_15 ( L_16 ,
V_119 ) ;
return V_14 ;
}
return 0 ;
}
static T_1
F_17 ( int V_135 , int V_136 , int * V_57 , int V_137 )
{
switch ( V_135 ) {
case V_130 :
if ( ! ( V_136 & V_138 ) )
goto V_139;
* V_57 = 1 ;
break;
case V_131 :
if ( ! ( V_136 & V_140 ) )
goto V_139;
* V_57 = 1 ;
break;
case V_95 :
if ( ! ( V_136 & V_141 ) )
goto V_139;
* V_57 = 1 ;
break;
case V_97 :
if ( ! ( V_136 & V_142 ) )
goto V_139;
* V_57 = 1 ;
break;
case V_133 :
if ( ! ( V_136 & V_143 ) )
goto V_139;
* V_57 = 1 ;
break;
case V_134 :
if ( ! ( V_136 & V_144 ) )
goto V_139;
* V_57 = 0 ;
break;
case V_132 :
if ( ! ( V_136 & V_145 ) || V_137 )
goto V_139;
* V_57 = 0 ;
break;
default:
F_15 ( L_16 , V_135 ) ;
return V_61 ;
}
return 0 ;
V_139:
F_15 ( L_17 ,
F_32 ( V_135 ) ) ;
return V_61 ;
}
static char * F_32 ( int V_135 )
{
switch ( V_135 ) {
case V_130 :
return L_18 ;
case V_131 :
return L_19 ;
case V_133 :
return L_20 ;
case V_95 :
return L_21 ;
case V_97 :
return L_22 ;
case V_134 :
return L_23 ;
case V_132 :
return L_24 ;
default:
return L_25 ;
}
return NULL ;
}
char * F_33 ( int V_146 )
{
switch ( V_146 ) {
case V_147 :
return L_26 ;
case V_148 :
return L_27 ;
case V_149 :
return L_28 ;
default:
return L_25 ;
}
return NULL ;
}
int F_34 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_76 & V_77 ) )
return 0 ;
if ( F_35 () )
return 0 ;
if ( ! V_2 -> V_78 )
return 0 ;
F_36 ( V_2 -> V_78 ) ;
return 0 ;
}
static int F_37 (
const char * V_150 ,
unsigned char * V_151 ,
T_2 V_152 )
{
struct V_153 * V_153 = F_38 ( V_150 , V_154 | V_155 | V_156 , 0600 ) ;
int V_157 ;
if ( F_39 ( V_153 ) ) {
F_15 ( L_29 , V_150 ) ;
return - V_158 ;
}
V_157 = F_40 ( V_153 , V_151 , V_152 , 0 ) ;
if ( V_157 < 0 )
F_15 ( L_30 , V_150 ) ;
F_41 ( V_153 ) ;
return ( V_157 < 0 ) ? - V_159 : 0 ;
}
static int F_42 (
struct V_29 * V_30 )
{
unsigned char * V_151 ;
struct V_160 * V_161 = & V_30 -> V_162 -> V_160 ;
char V_150 [ V_163 ] ;
int V_55 , V_53 ;
V_151 = F_43 ( V_164 , V_165 ) ;
if ( ! V_151 ) {
F_15 ( L_31 ) ;
return - V_166 ;
}
memset ( V_150 , 0 , V_163 ) ;
V_55 = snprintf ( V_151 , V_164 ,
L_32
L_33
L_34 ,
V_30 -> V_40 ,
V_30 -> V_38 ,
V_30 -> V_41 ) ;
snprintf ( V_150 , V_163 ,
L_35 , V_167 , & V_161 -> V_168 [ 0 ] ,
F_44 ( & V_30 -> V_169 . V_170 ) ) ;
V_53 = F_37 ( V_150 , V_151 , V_55 ) ;
F_45 ( V_151 ) ;
return V_53 ;
}
static void F_46 ( struct V_29 * V_30 )
{
struct V_171 * V_172 ;
struct V_31 * V_32 ;
struct V_173 * V_174 ;
F_4 ( & V_30 -> V_42 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
if ( ! F_47 ( & V_32 -> V_175 ) )
continue;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_176 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link) {
V_174 = F_48 ( V_172 -> V_173 ,
F_49 ( & V_32 -> V_176 ) ) ;
if ( ( V_30 -> V_41 ==
V_148 ) &&
( V_30 -> V_177 != NULL ) &&
( V_30 -> V_177 == V_32 ) )
continue;
if ( V_174 && ( V_30 -> V_178 != NULL ) &&
( V_30 -> V_178 == V_174 -> V_179 ) )
continue;
F_50 ( V_172 , 0x2A ,
V_180 ) ;
}
F_6 ( & V_32 -> V_176 ) ;
F_4 ( & V_30 -> V_42 ) ;
F_51 ( & V_32 -> V_175 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
}
static int F_52 (
struct V_29 * V_30 ,
int V_181 ,
int V_137 )
{
int V_182 ;
F_53 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_38 == V_181 ) {
F_54 ( & V_30 -> V_183 ) ;
return 0 ;
}
if ( V_137 && V_181 == V_132 ) {
F_54 ( & V_30 -> V_183 ) ;
return - V_184 ;
}
V_182 = V_30 -> V_38 ;
V_30 -> V_38 = V_132 ;
V_30 -> V_41 = ( V_137 ) ?
V_148 :
V_149 ;
F_46 ( V_30 ) ;
if ( V_181 == V_132 ) {
F_54 ( & V_30 -> V_183 ) ;
return 0 ;
}
if ( V_30 -> V_185 != 0 )
F_36 ( V_30 -> V_185 ) ;
V_30 -> V_38 = V_181 ;
if ( V_30 -> V_186 ) {
F_42 ( V_30 ) ;
}
F_16 ( L_36
L_37 , ( V_137 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_169 . V_170 ) ,
V_30 -> V_40 ,
F_32 ( V_182 ) ,
F_32 ( V_181 ) ) ;
F_46 ( V_30 ) ;
F_54 ( & V_30 -> V_183 ) ;
return 0 ;
}
int F_20 (
struct V_29 * V_51 ,
struct V_3 * V_187 ,
struct V_31 * V_47 ,
struct V_48 * V_188 ,
int V_181 ,
int V_137 )
{
struct V_3 * V_4 ;
struct V_189 * V_190 ;
struct V_191 * V_192 , * V_193 ;
struct V_29 * V_30 ;
int V_57 , V_58 , V_53 = 0 ;
if ( V_187 -> V_123 -> V_124 & V_125 )
return - V_158 ;
V_58 = V_51 -> V_39 ;
if ( F_17 ( V_181 , V_58 , & V_57 ,
V_137 ) != 0 )
return - V_194 ;
V_193 = V_187 -> V_195 ;
F_4 ( & V_193 -> V_196 ) ;
V_190 = V_193 -> V_190 ;
F_55 ( & V_190 -> V_197 ) ;
F_6 ( & V_193 -> V_196 ) ;
if ( ! V_190 -> V_198 ) {
V_51 -> V_177 = V_47 ;
V_51 -> V_178 = V_188 ;
V_53 = F_52 ( V_51 ,
V_181 , V_137 ) ;
F_21 ( & V_190 -> V_197 ) ;
return V_53 ;
}
F_4 ( & V_190 -> V_199 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_192 -> V_200 ;
F_19 ( & V_192 -> V_201 ) ;
F_6 ( & V_190 -> V_199 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
if ( V_51 -> V_40 != V_30 -> V_40 )
continue;
if ( V_51 == V_30 ) {
V_30 -> V_177 = V_47 ;
V_30 -> V_178 = V_188 ;
} else {
V_30 -> V_177 = NULL ;
V_30 -> V_178 = NULL ;
}
F_19 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
V_53 = F_52 ( V_30 ,
V_181 , V_137 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_21 ( & V_30 -> V_67 ) ;
if ( V_53 )
break;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_4 ( & V_190 -> V_199 ) ;
F_21 ( & V_192 -> V_201 ) ;
}
F_6 ( & V_190 -> V_199 ) ;
if ( ! V_53 ) {
F_16 ( L_40
L_41 ,
F_44 ( & V_190 -> V_202 . V_170 ) ,
V_51 -> V_40 ,
( V_137 ) ? L_38 : L_39 ,
F_32 ( V_181 ) ) ;
}
F_21 ( & V_190 -> V_197 ) ;
return V_53 ;
}
static int F_56 ( struct V_31 * V_32 )
{
struct V_203 * V_204 = V_32 -> V_205 ;
unsigned char * V_151 ;
char V_150 [ V_163 ] , V_161 [ V_206 ] ;
int V_55 , V_53 ;
F_53 ( & V_32 -> V_207 ) ;
V_151 = F_43 ( V_164 , V_165 ) ;
if ( ! V_151 ) {
F_15 ( L_31 ) ;
V_53 = - V_166 ;
goto V_208;
}
memset ( V_150 , 0 , V_163 ) ;
memset ( V_161 , 0 , V_206 ) ;
V_55 = snprintf ( V_161 , V_206 , L_42 ,
V_204 -> V_209 -> V_210 ( V_204 ) ) ;
if ( V_204 -> V_209 -> V_211 != NULL )
snprintf ( V_161 + V_55 , V_206 - V_55 , L_43 ,
V_204 -> V_209 -> V_211 ( V_204 ) ) ;
V_55 = snprintf ( V_151 , V_164 , L_44
L_45 ,
F_31 ( & V_32 -> V_126 ) ,
V_32 -> V_212 ) ;
snprintf ( V_150 , V_163 , L_46 ,
V_167 , V_204 -> V_209 -> V_71 () , V_161 ,
V_32 -> V_213 ) ;
V_53 = F_37 ( V_150 , V_151 , V_55 ) ;
F_45 ( V_151 ) ;
V_208:
F_54 ( & V_32 -> V_207 ) ;
return V_53 ;
}
static int F_22 (
struct V_31 * V_32 ,
int V_137 ,
int V_214 )
{
struct V_29 * V_30 ;
int V_215 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( ! V_30 ) {
F_6 ( & V_32 -> V_44 ) ;
F_15 ( L_47
L_48 ) ;
return - V_194 ;
}
V_215 = V_30 -> V_185 ;
if ( V_214 )
F_57 ( & V_32 -> V_126 , 1 ) ;
else
F_57 ( & V_32 -> V_126 , 0 ) ;
V_32 -> V_212 = ( V_137 ) ?
V_148 :
V_149 ;
F_16 ( L_36
L_49 , ( V_137 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_169 . V_170 ) ,
V_30 -> V_40 , ( V_214 ) ? L_50 : L_51 ) ;
F_6 ( & V_32 -> V_44 ) ;
if ( V_215 != 0 )
F_36 ( V_215 ) ;
if ( V_32 -> V_216 )
F_56 ( V_32 ) ;
return 0 ;
}
struct V_6 *
F_58 ( struct V_217 * V_218 ,
T_5 V_92 , T_5 V_91 )
{
struct V_6 * V_219 ;
V_219 = F_59 ( V_220 , V_165 ) ;
if ( ! V_219 ) {
F_15 ( L_52 ) ;
return F_60 ( - V_166 ) ;
}
F_61 ( & V_219 -> V_221 ) ;
V_219 -> V_22 = V_92 ;
V_219 -> V_23 = V_91 ;
F_62 ( & V_219 -> V_18 , V_218 ) ;
return V_219 ;
}
int
F_63 ( struct V_6 * V_219 ,
int V_222 , int V_135 )
{
struct V_8 * V_223 ;
F_8 (lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_223 -> V_27 == V_222 ) {
F_15 ( L_53 , V_222 ) ;
return - V_194 ;
}
}
V_223 = F_59 ( V_224 , V_165 ) ;
if ( ! V_223 ) {
F_15 ( L_54 ) ;
return - V_166 ;
}
V_223 -> V_25 = V_135 ;
V_223 -> V_27 = V_222 ;
F_62 ( & V_223 -> V_221 ,
& V_219 -> V_221 ) ;
return 0 ;
}
void
F_64 ( struct V_217 * V_225 )
{
struct V_6 * V_219 , * V_226 ;
struct V_8 * V_223 , * V_227 ;
F_65 (lba_map, lba_map_tmp, lba_list,
lba_map_list) {
F_65 (lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
F_66 ( & V_223 -> V_221 ) ;
F_67 ( V_224 ,
V_223 ) ;
}
F_66 ( & V_219 -> V_18 ) ;
F_67 ( V_220 , V_219 ) ;
}
}
void
F_68 ( struct V_3 * V_4 , struct V_217 * V_18 ,
int V_79 , int V_80 )
{
struct V_217 V_228 ;
struct V_29 * V_30 ;
int V_229 = 0 , V_230 ;
F_61 ( & V_228 ) ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_84 = V_79 ;
V_4 -> V_16 . V_85 = V_80 ;
F_69 ( & V_4 -> V_16 . V_18 , & V_228 ) ;
if ( V_18 ) {
F_69 ( V_18 , & V_4 -> V_16 . V_18 ) ;
V_229 = 1 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_230 = V_30 -> V_39 ;
if ( V_229 )
V_230 |= V_143 ;
else
V_230 &= ~ V_143 ;
V_30 -> V_39 = V_230 ;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_64 ( & V_228 ) ;
}
struct V_189 *
F_70 ( const char * V_231 , int V_232 )
{
struct V_189 * V_190 ;
V_190 = F_59 ( V_233 , V_165 ) ;
if ( ! V_190 ) {
F_15 ( L_55 ) ;
return F_60 ( - V_166 ) ;
}
F_61 ( & V_190 -> V_234 ) ;
F_61 ( & V_190 -> V_235 ) ;
F_71 ( & V_190 -> V_199 ) ;
F_57 ( & V_190 -> V_197 , 0 ) ;
if ( V_232 ) {
V_190 -> V_198 = V_236 ++ ;
V_190 -> V_237 = 1 ;
V_238 ++ ;
}
return V_190 ;
}
int F_72 ( struct V_189 * V_190 , T_3 V_198 )
{
struct V_189 * V_239 ;
T_3 V_240 ;
if ( V_190 -> V_237 ) {
F_2 ( L_56
L_57 ) ;
return - V_194 ;
}
F_4 ( & V_241 ) ;
if ( V_238 == 0x0000ffff ) {
F_15 ( L_58
L_59 ) ;
F_6 ( & V_241 ) ;
F_67 ( V_233 , V_190 ) ;
return - V_242 ;
}
V_243:
V_240 = ( V_198 != 0 ) ? V_198 :
V_236 ++ ;
F_8 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_239 -> V_198 == V_240 ) {
if ( ! V_198 )
goto V_243;
F_2 ( L_60
L_61 ,
V_198 ) ;
F_6 ( & V_241 ) ;
return - V_194 ;
}
}
V_190 -> V_198 = V_240 ;
V_190 -> V_237 = 1 ;
F_62 ( & V_190 -> V_234 , & V_244 ) ;
V_238 ++ ;
F_6 ( & V_241 ) ;
return 0 ;
}
static struct V_191 *
F_73 ( struct V_3 * V_4 )
{
struct V_191 * V_192 ;
V_192 = F_59 ( V_245 , V_165 ) ;
if ( ! V_192 ) {
F_15 ( L_62 ) ;
return F_60 ( - V_166 ) ;
}
F_61 ( & V_192 -> V_235 ) ;
F_71 ( & V_192 -> V_196 ) ;
F_57 ( & V_192 -> V_201 , 0 ) ;
V_192 -> V_200 = V_4 ;
V_4 -> V_195 = V_192 ;
return V_192 ;
}
void F_74 ( struct V_189 * V_190 )
{
struct V_191 * V_192 , * V_246 ;
F_4 ( & V_241 ) ;
F_66 ( & V_190 -> V_234 ) ;
V_238 -- ;
F_6 ( & V_241 ) ;
while ( F_31 ( & V_190 -> V_197 ) )
F_75 () ;
F_4 ( & V_190 -> V_199 ) ;
F_65 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_192 -> V_247 ) {
F_66 ( & V_192 -> V_235 ) ;
V_190 -> V_248 -- ;
V_192 -> V_247 = 0 ;
}
F_6 ( & V_190 -> V_199 ) ;
F_4 ( & V_192 -> V_196 ) ;
if ( V_190 != V_249 )
F_76 ( V_192 ,
V_249 ) ;
else
V_192 -> V_190 = NULL ;
F_6 ( & V_192 -> V_196 ) ;
F_4 ( & V_190 -> V_199 ) ;
}
F_6 ( & V_190 -> V_199 ) ;
F_67 ( V_233 , V_190 ) ;
}
void F_77 ( struct V_3 * V_4 )
{
struct V_189 * V_190 ;
struct V_191 * V_192 ;
V_192 = V_4 -> V_195 ;
if ( ! V_192 )
return;
while ( F_31 ( & V_192 -> V_201 ) )
F_75 () ;
F_4 ( & V_192 -> V_196 ) ;
V_190 = V_192 -> V_190 ;
if ( V_190 ) {
F_4 ( & V_190 -> V_199 ) ;
if ( V_192 -> V_247 ) {
F_66 ( & V_192 -> V_235 ) ;
V_190 -> V_248 -- ;
V_192 -> V_247 = 0 ;
}
F_6 ( & V_190 -> V_199 ) ;
V_192 -> V_190 = NULL ;
}
F_6 ( & V_192 -> V_196 ) ;
F_67 ( V_245 , V_192 ) ;
}
struct V_189 * F_78 ( const char * V_231 )
{
struct V_189 * V_190 ;
struct V_250 * V_251 ;
F_4 ( & V_241 ) ;
F_8 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_190 -> V_237 )
continue;
V_251 = & V_190 -> V_202 . V_170 ;
if ( ! strcmp ( F_44 ( V_251 ) , V_231 ) ) {
F_55 ( & V_190 -> V_197 ) ;
F_6 ( & V_241 ) ;
return V_190 ;
}
}
F_6 ( & V_241 ) ;
return NULL ;
}
void F_79 ( struct V_189 * V_190 )
{
F_4 ( & V_241 ) ;
F_80 ( & V_190 -> V_197 ) ;
F_6 ( & V_241 ) ;
}
void F_76 (
struct V_191 * V_192 ,
struct V_189 * V_190 )
{
F_4 ( & V_190 -> V_199 ) ;
V_192 -> V_190 = V_190 ;
V_192 -> V_247 = 1 ;
F_62 ( & V_192 -> V_235 , & V_190 -> V_235 ) ;
V_190 -> V_248 ++ ;
F_6 ( & V_190 -> V_199 ) ;
}
void F_81 (
struct V_191 * V_192 ,
struct V_189 * V_190 )
{
F_4 ( & V_190 -> V_199 ) ;
F_66 ( & V_192 -> V_235 ) ;
V_192 -> V_190 = NULL ;
V_192 -> V_247 = 0 ;
V_190 -> V_248 -- ;
F_6 ( & V_190 -> V_199 ) ;
}
struct V_29 * F_82 ( struct V_3 * V_4 ,
const char * V_231 , int V_232 )
{
struct V_29 * V_30 ;
V_30 = F_59 ( V_252 , V_165 ) ;
if ( ! V_30 ) {
F_15 ( L_63 ) ;
return NULL ;
}
F_61 ( & V_30 -> V_253 ) ;
F_61 ( & V_30 -> V_254 ) ;
F_83 ( & V_30 -> V_183 ) ;
F_71 ( & V_30 -> V_42 ) ;
F_57 ( & V_30 -> V_67 , 0 ) ;
V_30 -> V_162 = V_4 ;
V_30 -> V_38 =
V_130 ;
V_30 -> V_63 =
V_64 | V_255 ;
V_30 -> V_129 = V_256 ;
V_30 -> V_185 = V_257 ;
V_30 -> V_46 = V_258 ;
V_30 -> V_39 =
V_145 | V_144 |
V_142 | V_141 | V_140 | V_138 ;
if ( V_232 ) {
F_4 ( & V_4 -> V_16 . V_35 ) ;
V_30 -> V_40 =
V_4 -> V_16 . V_259 ++ ;
V_30 -> V_66 = 1 ;
V_4 -> V_16 . V_260 ++ ;
F_62 ( & V_30 -> V_253 ,
& V_4 -> V_16 . V_261 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
return V_30 ;
}
int F_84 (
struct V_29 * V_30 ,
T_3 V_40 )
{
struct V_3 * V_4 = V_30 -> V_162 ;
struct V_29 * V_262 ;
T_3 V_263 ;
if ( V_30 -> V_66 ) {
F_2 ( L_64
L_57 ) ;
return - V_194 ;
}
F_4 ( & V_4 -> V_16 . V_35 ) ;
if ( V_4 -> V_16 . V_260 == 0x0000ffff ) {
F_15 ( L_65
L_59 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_67 ( V_252 , V_30 ) ;
return - V_242 ;
}
V_243:
V_263 = ( V_40 != 0 ) ? V_40 :
V_4 -> V_16 . V_259 ++ ;
F_8 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_262 -> V_40 == V_263 ) {
if ( ! V_40 )
goto V_243;
F_15 ( L_66
L_67 , V_40 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return - V_194 ;
}
}
V_30 -> V_40 = V_263 ;
V_30 -> V_66 = 1 ;
F_62 ( & V_30 -> V_253 ,
& V_4 -> V_16 . V_261 ) ;
V_4 -> V_16 . V_260 ++ ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return 0 ;
}
void F_85 (
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_162 ;
struct V_31 * V_32 , * V_264 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_66 ( & V_30 -> V_253 ) ;
V_4 -> V_16 . V_259 -- ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
while ( F_31 ( & V_30 -> V_67 ) )
F_75 () ;
F_4 ( & V_30 -> V_42 ) ;
F_65 (lun, next,
&tg_pt_gp->tg_pt_gp_lun_list, lun_tg_pt_gp_link) {
F_86 ( & V_32 -> V_265 ) ;
V_30 -> V_36 -- ;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_44 ) ;
if ( V_30 != V_4 -> V_16 . V_266 ) {
F_87 ( V_32 ,
V_4 -> V_16 . V_266 ) ;
} else
V_32 -> V_45 = NULL ;
F_6 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
F_67 ( V_252 , V_30 ) ;
}
static struct V_29 * F_88 (
struct V_3 * V_4 , const char * V_231 )
{
struct V_29 * V_30 ;
struct V_250 * V_251 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_251 = & V_30 -> V_169 . V_170 ;
if ( ! strcmp ( F_44 ( V_251 ) , V_231 ) ) {
F_55 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return V_30 ;
}
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
return NULL ;
}
static void F_89 (
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_162 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_80 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
static void F_87 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_171 * V_172 ;
F_90 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
V_32 -> V_45 = V_30 ;
F_62 ( & V_32 -> V_265 , & V_30 -> V_254 ) ;
V_30 -> V_36 ++ ;
F_4 ( & V_32 -> V_176 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link)
F_50 ( V_172 , 0x3f ,
V_267 ) ;
F_6 ( & V_32 -> V_176 ) ;
F_6 ( & V_30 -> V_42 ) ;
}
void F_91 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
F_4 ( & V_32 -> V_44 ) ;
F_87 ( V_32 , V_30 ) ;
F_6 ( & V_32 -> V_44 ) ;
}
static void F_92 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
F_90 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
F_86 ( & V_32 -> V_265 ) ;
V_30 -> V_36 -- ;
F_6 ( & V_30 -> V_42 ) ;
V_32 -> V_45 = NULL ;
}
void F_93 ( struct V_31 * V_32 )
{
struct V_29 * V_30 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 )
F_92 ( V_32 , V_30 ) ;
F_6 ( & V_32 -> V_44 ) ;
}
T_6 F_94 ( struct V_31 * V_32 , char * V_268 )
{
struct V_250 * V_269 ;
struct V_29 * V_30 ;
T_6 V_55 = 0 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
V_269 = & V_30 -> V_169 . V_170 ;
V_55 += sprintf ( V_268 , L_68
L_69
L_70
L_71 ,
F_44 ( V_269 ) , V_30 -> V_40 ,
F_32 (
V_30 -> V_38 ) ,
F_33 (
V_30 -> V_41 ) ,
F_31 ( & V_32 -> V_126 ) ?
L_23 : L_26 ,
F_33 ( V_32 -> V_212 ) ) ;
}
F_6 ( & V_32 -> V_44 ) ;
return V_55 ;
}
T_6 F_95 (
struct V_31 * V_32 ,
const char * V_268 ,
T_7 V_270 )
{
struct V_203 * V_271 = V_32 -> V_205 ;
struct V_3 * V_4 = F_96 ( V_32 -> V_272 ) ;
struct V_29 * V_30 = NULL , * V_273 = NULL ;
unsigned char V_10 [ V_274 ] ;
int V_275 = 0 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_158 ;
if ( V_270 > V_274 ) {
F_15 ( L_72 ) ;
return - V_194 ;
}
memset ( V_10 , 0 , V_274 ) ;
memcpy ( V_10 , V_268 , V_270 ) ;
if ( strcmp ( F_97 ( V_10 ) , L_73 ) ) {
V_273 = F_88 ( V_4 ,
F_97 ( V_10 ) ) ;
if ( ! V_273 )
return - V_158 ;
}
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
if ( ! V_273 ) {
F_16 ( L_74
L_75
L_76
L_77 ,
V_271 -> V_209 -> V_210 ( V_271 ) ,
V_271 -> V_209 -> V_211 ( V_271 ) ,
F_44 ( & V_32 -> V_276 . V_170 ) ,
F_44 (
& V_30 -> V_169 . V_170 ) ,
V_30 -> V_40 ) ;
F_92 ( V_32 , V_30 ) ;
F_87 ( V_32 ,
V_4 -> V_16 . V_266 ) ;
F_6 ( & V_32 -> V_44 ) ;
return V_270 ;
}
F_92 ( V_32 , V_30 ) ;
V_275 = 1 ;
}
F_87 ( V_32 , V_273 ) ;
F_6 ( & V_32 -> V_44 ) ;
F_16 ( L_78
L_79 , ( V_275 ) ?
L_80 : L_81 , V_271 -> V_209 -> V_210 ( V_271 ) ,
V_271 -> V_209 -> V_211 ( V_271 ) ,
F_44 ( & V_32 -> V_276 . V_170 ) ,
F_44 ( & V_273 -> V_169 . V_170 ) ,
V_273 -> V_40 ) ;
F_89 ( V_273 ) ;
return V_270 ;
}
T_6 F_98 (
struct V_29 * V_30 ,
char * V_268 )
{
if ( ( V_30 -> V_63 & V_64 ) &&
( V_30 -> V_63 & V_255 ) )
return sprintf ( V_268 , L_82 ) ;
else if ( V_30 -> V_63 & V_255 )
return sprintf ( V_268 , L_83 ) ;
else if ( V_30 -> V_63 & V_64 )
return sprintf ( V_268 , L_84 ) ;
else
return sprintf ( V_268 , L_85 ) ;
}
T_6 F_99 (
struct V_29 * V_30 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_86 ) ;
return V_157 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) && ( V_93 != 2 ) && ( V_93 != 3 ) ) {
F_15 ( L_87
L_88 , V_93 ) ;
return - V_194 ;
}
if ( V_93 == 3 )
V_30 -> V_63 =
V_255 | V_64 ;
else if ( V_93 == 2 )
V_30 -> V_63 = V_64 ;
else if ( V_93 == 1 )
V_30 -> V_63 = V_255 ;
else
V_30 -> V_63 = 0 ;
return V_270 ;
}
T_6 F_101 (
struct V_29 * V_30 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_30 -> V_129 ) ;
}
T_6 F_102 (
struct V_29 * V_30 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_90 ) ;
return V_157 ;
}
if ( V_93 > V_277 ) {
F_15 ( L_91
L_92 , V_93 ,
V_277 ) ;
return - V_194 ;
}
V_30 -> V_129 = ( int ) V_93 ;
return V_270 ;
}
T_6 F_103 (
struct V_29 * V_30 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_30 -> V_185 ) ;
}
T_6 F_104 (
struct V_29 * V_30 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_93 ) ;
return V_157 ;
}
if ( V_93 > V_278 ) {
F_15 ( L_94
L_95 , V_93 ,
V_278 ) ;
return - V_194 ;
}
V_30 -> V_185 = ( int ) V_93 ;
return V_270 ;
}
T_6 F_105 (
struct V_29 * V_30 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_30 -> V_46 ) ;
}
T_6 F_106 (
struct V_29 * V_30 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_96 ) ;
return V_157 ;
}
if ( V_93 > V_279 ) {
F_15 ( L_97
L_98 , V_93 ,
V_279 ) ;
return - V_194 ;
}
V_30 -> V_46 = ( int ) V_93 ;
return V_270 ;
}
T_6 F_107 (
struct V_29 * V_30 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_30 -> V_37 ) ;
}
T_6 F_108 (
struct V_29 * V_30 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_99 ) ;
return V_157 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_100 , V_93 ) ;
return - V_194 ;
}
V_30 -> V_37 = ( int ) V_93 ;
return V_270 ;
}
T_6 F_109 ( struct V_31 * V_32 , char * V_268 )
{
return sprintf ( V_268 , L_89 ,
F_31 ( & V_32 -> V_126 ) ) ;
}
T_6 F_110 (
struct V_31 * V_32 ,
const char * V_268 ,
T_7 V_270 )
{
struct V_3 * V_4 = F_96 ( V_32 -> V_272 ) ;
unsigned long V_93 ;
int V_157 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_158 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_101 ) ;
return V_157 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_102 ,
V_93 ) ;
return - V_194 ;
}
V_157 = F_22 ( V_32 , 0 , ( int ) V_93 ) ;
if ( V_157 < 0 )
return - V_194 ;
return V_270 ;
}
T_6 F_111 (
struct V_31 * V_32 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_32 -> V_212 ) ;
}
T_6 F_112 (
struct V_31 * V_32 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_103 ) ;
return V_157 ;
}
if ( ( V_93 != V_147 ) &&
( V_93 != V_148 ) &&
( V_93 != V_149 ) ) {
F_15 ( L_104 ,
V_93 ) ;
return - V_194 ;
}
V_32 -> V_212 = ( int ) V_93 ;
return V_270 ;
}
T_6 F_113 (
struct V_31 * V_32 ,
char * V_268 )
{
return sprintf ( V_268 , L_89 , V_32 -> V_216 ) ;
}
T_6 F_114 (
struct V_31 * V_32 ,
const char * V_268 ,
T_7 V_270 )
{
unsigned long V_93 ;
int V_157 ;
V_157 = F_100 ( V_268 , 0 , & V_93 ) ;
if ( V_157 < 0 ) {
F_15 ( L_105 ) ;
return V_157 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_106
L_88 , V_93 ) ;
return - V_194 ;
}
V_32 -> V_216 = ( int ) V_93 ;
return V_270 ;
}
int F_115 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_123 -> V_124 &
V_125 ) &&
! ( V_4 -> V_120 -> V_121 & V_122 ) ) {
struct V_191 * V_192 ;
V_192 = F_73 ( V_4 ) ;
if ( F_39 ( V_192 ) )
return F_116 ( V_192 ) ;
F_4 ( & V_192 -> V_196 ) ;
F_76 ( V_192 ,
V_249 ) ;
F_6 ( & V_192 -> V_196 ) ;
F_16 ( L_107
L_108 ,
V_4 -> V_123 -> V_231 ) ;
}
return 0 ;
}
