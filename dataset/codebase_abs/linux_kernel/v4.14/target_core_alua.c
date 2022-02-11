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
F_10 ( V_30 -> V_40 , & V_10 [ V_12 ] ) ;
V_12 += 2 ;
V_12 ++ ;
V_10 [ V_12 ++ ] = ( V_30 -> V_41 & 0xff ) ;
V_10 [ V_12 ++ ] = 0x00 ;
V_10 [ V_12 ++ ] = ( V_30 -> V_36 & 0xff ) ;
V_11 += 8 ;
F_4 ( & V_30 -> V_42 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
V_12 += 2 ;
F_10 ( V_32 -> V_43 , & V_10 [ V_12 ] ) ;
V_12 += 2 ;
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
T_6 V_157 = 0 ;
int V_158 ;
if ( F_39 ( V_153 ) ) {
F_15 ( L_29 , V_150 ) ;
return - V_159 ;
}
V_158 = F_40 ( V_153 , V_151 , V_152 , & V_157 ) ;
if ( V_158 < 0 )
F_15 ( L_30 , V_150 ) ;
F_41 ( V_153 ) ;
return ( V_158 < 0 ) ? - V_160 : 0 ;
}
static int F_42 (
struct V_29 * V_30 )
{
unsigned char * V_151 ;
struct V_161 * V_162 = & V_30 -> V_163 -> V_161 ;
char V_150 [ V_164 ] ;
int V_55 , V_53 ;
V_151 = F_43 ( V_165 , V_166 ) ;
if ( ! V_151 ) {
F_15 ( L_31 ) ;
return - V_167 ;
}
memset ( V_150 , 0 , V_164 ) ;
V_55 = snprintf ( V_151 , V_165 ,
L_32
L_33
L_34 ,
V_30 -> V_40 ,
V_30 -> V_38 ,
V_30 -> V_41 ) ;
snprintf ( V_150 , V_164 ,
L_35 , V_168 , & V_162 -> V_169 [ 0 ] ,
F_44 ( & V_30 -> V_170 . V_171 ) ) ;
V_53 = F_37 ( V_150 , V_151 , V_55 ) ;
F_45 ( V_151 ) ;
return V_53 ;
}
static void F_46 ( struct V_29 * V_30 )
{
struct V_172 * V_173 ;
struct V_31 * V_32 ;
struct V_174 * V_175 ;
F_4 ( & V_30 -> V_42 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
if ( ! F_47 ( & V_32 -> V_176 ) )
continue;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_177 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link) {
V_175 = F_48 ( V_173 -> V_174 ,
F_49 ( & V_32 -> V_177 ) ) ;
if ( ( V_30 -> V_41 ==
V_148 ) &&
( V_30 -> V_178 != NULL ) &&
( V_30 -> V_178 == V_32 ) )
continue;
if ( V_175 && ( V_30 -> V_179 != NULL ) &&
( V_30 -> V_179 == V_175 -> V_180 ) )
continue;
F_50 ( V_173 , 0x2A ,
V_181 ) ;
}
F_6 ( & V_32 -> V_177 ) ;
F_4 ( & V_30 -> V_42 ) ;
F_51 ( & V_32 -> V_176 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
}
static int F_52 (
struct V_29 * V_30 ,
int V_182 ,
int V_137 )
{
int V_183 ;
F_53 ( & V_30 -> V_184 ) ;
if ( V_30 -> V_38 == V_182 ) {
F_54 ( & V_30 -> V_184 ) ;
return 0 ;
}
if ( V_137 && V_182 == V_132 ) {
F_54 ( & V_30 -> V_184 ) ;
return - V_185 ;
}
V_183 = V_30 -> V_38 ;
V_30 -> V_38 = V_132 ;
V_30 -> V_41 = ( V_137 ) ?
V_148 :
V_149 ;
F_46 ( V_30 ) ;
if ( V_182 == V_132 ) {
F_54 ( & V_30 -> V_184 ) ;
return 0 ;
}
if ( V_30 -> V_186 != 0 )
F_36 ( V_30 -> V_186 ) ;
V_30 -> V_38 = V_182 ;
if ( V_30 -> V_187 ) {
F_42 ( V_30 ) ;
}
F_16 ( L_36
L_37 , ( V_137 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_170 . V_171 ) ,
V_30 -> V_40 ,
F_32 ( V_183 ) ,
F_32 ( V_182 ) ) ;
F_46 ( V_30 ) ;
F_54 ( & V_30 -> V_184 ) ;
return 0 ;
}
int F_20 (
struct V_29 * V_51 ,
struct V_3 * V_188 ,
struct V_31 * V_47 ,
struct V_48 * V_189 ,
int V_182 ,
int V_137 )
{
struct V_3 * V_4 ;
struct V_190 * V_191 ;
struct V_192 * V_193 , * V_194 ;
struct V_29 * V_30 ;
int V_57 , V_58 , V_53 = 0 ;
if ( V_188 -> V_123 -> V_124 & V_125 )
return - V_159 ;
V_58 = V_51 -> V_39 ;
if ( F_17 ( V_182 , V_58 , & V_57 ,
V_137 ) != 0 )
return - V_195 ;
V_194 = V_188 -> V_196 ;
F_4 ( & V_194 -> V_197 ) ;
V_191 = V_194 -> V_191 ;
F_55 ( & V_191 -> V_198 ) ;
F_6 ( & V_194 -> V_197 ) ;
if ( ! V_191 -> V_199 ) {
V_51 -> V_178 = V_47 ;
V_51 -> V_179 = V_189 ;
V_53 = F_52 ( V_51 ,
V_182 , V_137 ) ;
F_21 ( & V_191 -> V_198 ) ;
return V_53 ;
}
F_4 ( & V_191 -> V_200 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_193 -> V_201 ;
F_19 ( & V_193 -> V_202 ) ;
F_6 ( & V_191 -> V_200 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
if ( V_51 -> V_40 != V_30 -> V_40 )
continue;
if ( V_51 == V_30 ) {
V_30 -> V_178 = V_47 ;
V_30 -> V_179 = V_189 ;
} else {
V_30 -> V_178 = NULL ;
V_30 -> V_179 = NULL ;
}
F_19 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
V_53 = F_52 ( V_30 ,
V_182 , V_137 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_21 ( & V_30 -> V_67 ) ;
if ( V_53 )
break;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_4 ( & V_191 -> V_200 ) ;
F_21 ( & V_193 -> V_202 ) ;
}
F_6 ( & V_191 -> V_200 ) ;
if ( ! V_53 ) {
F_16 ( L_40
L_41 ,
F_44 ( & V_191 -> V_203 . V_171 ) ,
V_51 -> V_40 ,
( V_137 ) ? L_38 : L_39 ,
F_32 ( V_182 ) ) ;
}
F_21 ( & V_191 -> V_198 ) ;
return V_53 ;
}
static int F_56 ( struct V_31 * V_32 )
{
struct V_204 * V_205 = V_32 -> V_206 ;
unsigned char * V_151 ;
char V_150 [ V_164 ] , V_162 [ V_207 ] ;
int V_55 , V_53 ;
F_53 ( & V_32 -> V_208 ) ;
V_151 = F_43 ( V_165 , V_166 ) ;
if ( ! V_151 ) {
F_15 ( L_31 ) ;
V_53 = - V_167 ;
goto V_209;
}
memset ( V_150 , 0 , V_164 ) ;
memset ( V_162 , 0 , V_207 ) ;
V_55 = snprintf ( V_162 , V_207 , L_42 ,
V_205 -> V_210 -> V_211 ( V_205 ) ) ;
if ( V_205 -> V_210 -> V_212 != NULL )
snprintf ( V_162 + V_55 , V_207 - V_55 , L_43 ,
V_205 -> V_210 -> V_212 ( V_205 ) ) ;
V_55 = snprintf ( V_151 , V_165 , L_44
L_45 ,
F_31 ( & V_32 -> V_126 ) ,
V_32 -> V_213 ) ;
snprintf ( V_150 , V_164 , L_46 ,
V_168 , V_205 -> V_210 -> V_71 () , V_162 ,
V_32 -> V_214 ) ;
V_53 = F_37 ( V_150 , V_151 , V_55 ) ;
F_45 ( V_151 ) ;
V_209:
F_54 ( & V_32 -> V_208 ) ;
return V_53 ;
}
static int F_22 (
struct V_31 * V_32 ,
int V_137 ,
int V_215 )
{
struct V_29 * V_30 ;
int V_216 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( ! V_30 ) {
F_6 ( & V_32 -> V_44 ) ;
F_15 ( L_47
L_48 ) ;
return - V_195 ;
}
V_216 = V_30 -> V_186 ;
if ( V_215 )
F_57 ( & V_32 -> V_126 , 1 ) ;
else
F_57 ( & V_32 -> V_126 , 0 ) ;
V_32 -> V_213 = ( V_137 ) ?
V_148 :
V_149 ;
F_16 ( L_36
L_49 , ( V_137 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_170 . V_171 ) ,
V_30 -> V_40 , ( V_215 ) ? L_50 : L_51 ) ;
F_6 ( & V_32 -> V_44 ) ;
if ( V_216 != 0 )
F_36 ( V_216 ) ;
if ( V_32 -> V_217 )
F_56 ( V_32 ) ;
return 0 ;
}
struct V_6 *
F_58 ( struct V_218 * V_219 ,
T_5 V_92 , T_5 V_91 )
{
struct V_6 * V_220 ;
V_220 = F_59 ( V_221 , V_166 ) ;
if ( ! V_220 ) {
F_15 ( L_52 ) ;
return F_60 ( - V_167 ) ;
}
F_61 ( & V_220 -> V_222 ) ;
V_220 -> V_22 = V_92 ;
V_220 -> V_23 = V_91 ;
F_62 ( & V_220 -> V_18 , V_219 ) ;
return V_220 ;
}
int
F_63 ( struct V_6 * V_220 ,
int V_223 , int V_135 )
{
struct V_8 * V_224 ;
F_8 (lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_224 -> V_27 == V_223 ) {
F_15 ( L_53 , V_223 ) ;
return - V_195 ;
}
}
V_224 = F_59 ( V_225 , V_166 ) ;
if ( ! V_224 ) {
F_15 ( L_54 ) ;
return - V_167 ;
}
V_224 -> V_25 = V_135 ;
V_224 -> V_27 = V_223 ;
F_62 ( & V_224 -> V_222 ,
& V_220 -> V_222 ) ;
return 0 ;
}
void
F_64 ( struct V_218 * V_226 )
{
struct V_6 * V_220 , * V_227 ;
struct V_8 * V_224 , * V_228 ;
F_65 (lba_map, lba_map_tmp, lba_list,
lba_map_list) {
F_65 (lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
F_66 ( & V_224 -> V_222 ) ;
F_67 ( V_225 ,
V_224 ) ;
}
F_66 ( & V_220 -> V_18 ) ;
F_67 ( V_221 , V_220 ) ;
}
}
void
F_68 ( struct V_3 * V_4 , struct V_218 * V_18 ,
int V_79 , int V_80 )
{
struct V_218 V_229 ;
struct V_29 * V_30 ;
int V_230 = 0 , V_231 ;
F_61 ( & V_229 ) ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_84 = V_79 ;
V_4 -> V_16 . V_85 = V_80 ;
F_69 ( & V_4 -> V_16 . V_18 , & V_229 ) ;
if ( V_18 ) {
F_69 ( V_18 , & V_4 -> V_16 . V_18 ) ;
V_230 = 1 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_231 = V_30 -> V_39 ;
if ( V_230 )
V_231 |= V_143 ;
else
V_231 &= ~ V_143 ;
V_30 -> V_39 = V_231 ;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_64 ( & V_229 ) ;
}
struct V_190 *
F_70 ( const char * V_232 , int V_233 )
{
struct V_190 * V_191 ;
V_191 = F_59 ( V_234 , V_166 ) ;
if ( ! V_191 ) {
F_15 ( L_55 ) ;
return F_60 ( - V_167 ) ;
}
F_61 ( & V_191 -> V_235 ) ;
F_61 ( & V_191 -> V_236 ) ;
F_71 ( & V_191 -> V_200 ) ;
F_57 ( & V_191 -> V_198 , 0 ) ;
if ( V_233 ) {
V_191 -> V_199 = V_237 ++ ;
V_191 -> V_238 = 1 ;
V_239 ++ ;
}
return V_191 ;
}
int F_72 ( struct V_190 * V_191 , T_3 V_199 )
{
struct V_190 * V_240 ;
T_3 V_241 ;
if ( V_191 -> V_238 ) {
F_2 ( L_56
L_57 ) ;
return - V_195 ;
}
F_4 ( & V_242 ) ;
if ( V_239 == 0x0000ffff ) {
F_15 ( L_58
L_59 ) ;
F_6 ( & V_242 ) ;
F_67 ( V_234 , V_191 ) ;
return - V_243 ;
}
V_244:
V_241 = ( V_199 != 0 ) ? V_199 :
V_237 ++ ;
F_8 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_240 -> V_199 == V_241 ) {
if ( ! V_199 )
goto V_244;
F_2 ( L_60
L_61 ,
V_199 ) ;
F_6 ( & V_242 ) ;
return - V_195 ;
}
}
V_191 -> V_199 = V_241 ;
V_191 -> V_238 = 1 ;
F_62 ( & V_191 -> V_235 , & V_245 ) ;
V_239 ++ ;
F_6 ( & V_242 ) ;
return 0 ;
}
static struct V_192 *
F_73 ( struct V_3 * V_4 )
{
struct V_192 * V_193 ;
V_193 = F_59 ( V_246 , V_166 ) ;
if ( ! V_193 ) {
F_15 ( L_62 ) ;
return F_60 ( - V_167 ) ;
}
F_61 ( & V_193 -> V_236 ) ;
F_71 ( & V_193 -> V_197 ) ;
F_57 ( & V_193 -> V_202 , 0 ) ;
V_193 -> V_201 = V_4 ;
V_4 -> V_196 = V_193 ;
return V_193 ;
}
void F_74 ( struct V_190 * V_191 )
{
struct V_192 * V_193 , * V_247 ;
F_4 ( & V_242 ) ;
F_66 ( & V_191 -> V_235 ) ;
V_239 -- ;
F_6 ( & V_242 ) ;
while ( F_31 ( & V_191 -> V_198 ) )
F_75 () ;
F_4 ( & V_191 -> V_200 ) ;
F_65 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_193 -> V_248 ) {
F_66 ( & V_193 -> V_236 ) ;
V_191 -> V_249 -- ;
V_193 -> V_248 = 0 ;
}
F_6 ( & V_191 -> V_200 ) ;
F_4 ( & V_193 -> V_197 ) ;
if ( V_191 != V_250 )
F_76 ( V_193 ,
V_250 ) ;
else
V_193 -> V_191 = NULL ;
F_6 ( & V_193 -> V_197 ) ;
F_4 ( & V_191 -> V_200 ) ;
}
F_6 ( & V_191 -> V_200 ) ;
F_67 ( V_234 , V_191 ) ;
}
void F_77 ( struct V_3 * V_4 )
{
struct V_190 * V_191 ;
struct V_192 * V_193 ;
V_193 = V_4 -> V_196 ;
if ( ! V_193 )
return;
while ( F_31 ( & V_193 -> V_202 ) )
F_75 () ;
F_4 ( & V_193 -> V_197 ) ;
V_191 = V_193 -> V_191 ;
if ( V_191 ) {
F_4 ( & V_191 -> V_200 ) ;
if ( V_193 -> V_248 ) {
F_66 ( & V_193 -> V_236 ) ;
V_191 -> V_249 -- ;
V_193 -> V_248 = 0 ;
}
F_6 ( & V_191 -> V_200 ) ;
V_193 -> V_191 = NULL ;
}
F_6 ( & V_193 -> V_197 ) ;
F_67 ( V_246 , V_193 ) ;
}
struct V_190 * F_78 ( const char * V_232 )
{
struct V_190 * V_191 ;
struct V_251 * V_252 ;
F_4 ( & V_242 ) ;
F_8 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_191 -> V_238 )
continue;
V_252 = & V_191 -> V_203 . V_171 ;
if ( ! strcmp ( F_44 ( V_252 ) , V_232 ) ) {
F_55 ( & V_191 -> V_198 ) ;
F_6 ( & V_242 ) ;
return V_191 ;
}
}
F_6 ( & V_242 ) ;
return NULL ;
}
void F_79 ( struct V_190 * V_191 )
{
F_4 ( & V_242 ) ;
F_80 ( & V_191 -> V_198 ) ;
F_6 ( & V_242 ) ;
}
void F_76 (
struct V_192 * V_193 ,
struct V_190 * V_191 )
{
F_4 ( & V_191 -> V_200 ) ;
V_193 -> V_191 = V_191 ;
V_193 -> V_248 = 1 ;
F_62 ( & V_193 -> V_236 , & V_191 -> V_236 ) ;
V_191 -> V_249 ++ ;
F_6 ( & V_191 -> V_200 ) ;
}
void F_81 (
struct V_192 * V_193 ,
struct V_190 * V_191 )
{
F_4 ( & V_191 -> V_200 ) ;
F_66 ( & V_193 -> V_236 ) ;
V_193 -> V_191 = NULL ;
V_193 -> V_248 = 0 ;
V_191 -> V_249 -- ;
F_6 ( & V_191 -> V_200 ) ;
}
struct V_29 * F_82 ( struct V_3 * V_4 ,
const char * V_232 , int V_233 )
{
struct V_29 * V_30 ;
V_30 = F_59 ( V_253 , V_166 ) ;
if ( ! V_30 ) {
F_15 ( L_63 ) ;
return NULL ;
}
F_61 ( & V_30 -> V_254 ) ;
F_61 ( & V_30 -> V_255 ) ;
F_83 ( & V_30 -> V_184 ) ;
F_71 ( & V_30 -> V_42 ) ;
F_57 ( & V_30 -> V_67 , 0 ) ;
V_30 -> V_163 = V_4 ;
V_30 -> V_38 =
V_130 ;
V_30 -> V_63 =
V_64 | V_256 ;
V_30 -> V_129 = V_257 ;
V_30 -> V_186 = V_258 ;
V_30 -> V_46 = V_259 ;
V_30 -> V_39 =
V_145 | V_144 |
V_142 | V_141 | V_140 | V_138 ;
if ( V_233 ) {
F_4 ( & V_4 -> V_16 . V_35 ) ;
V_30 -> V_40 =
V_4 -> V_16 . V_260 ++ ;
V_30 -> V_66 = 1 ;
V_4 -> V_16 . V_261 ++ ;
F_62 ( & V_30 -> V_254 ,
& V_4 -> V_16 . V_262 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
return V_30 ;
}
int F_84 (
struct V_29 * V_30 ,
T_3 V_40 )
{
struct V_3 * V_4 = V_30 -> V_163 ;
struct V_29 * V_263 ;
T_3 V_264 ;
if ( V_30 -> V_66 ) {
F_2 ( L_64
L_57 ) ;
return - V_195 ;
}
F_4 ( & V_4 -> V_16 . V_35 ) ;
if ( V_4 -> V_16 . V_261 == 0x0000ffff ) {
F_15 ( L_65
L_59 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_67 ( V_253 , V_30 ) ;
return - V_243 ;
}
V_244:
V_264 = ( V_40 != 0 ) ? V_40 :
V_4 -> V_16 . V_260 ++ ;
F_8 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_263 -> V_40 == V_264 ) {
if ( ! V_40 )
goto V_244;
F_15 ( L_66
L_67 , V_40 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return - V_195 ;
}
}
V_30 -> V_40 = V_264 ;
V_30 -> V_66 = 1 ;
F_62 ( & V_30 -> V_254 ,
& V_4 -> V_16 . V_262 ) ;
V_4 -> V_16 . V_261 ++ ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return 0 ;
}
void F_85 (
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_163 ;
struct V_31 * V_32 , * V_265 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_66 ( & V_30 -> V_254 ) ;
V_4 -> V_16 . V_260 -- ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
while ( F_31 ( & V_30 -> V_67 ) )
F_75 () ;
F_4 ( & V_30 -> V_42 ) ;
F_65 (lun, next,
&tg_pt_gp->tg_pt_gp_lun_list, lun_tg_pt_gp_link) {
F_86 ( & V_32 -> V_266 ) ;
V_30 -> V_36 -- ;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_44 ) ;
if ( V_30 != V_4 -> V_16 . V_267 ) {
F_87 ( V_32 ,
V_4 -> V_16 . V_267 ) ;
} else
V_32 -> V_45 = NULL ;
F_6 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
F_67 ( V_253 , V_30 ) ;
}
static struct V_29 * F_88 (
struct V_3 * V_4 , const char * V_232 )
{
struct V_29 * V_30 ;
struct V_251 * V_252 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_252 = & V_30 -> V_170 . V_171 ;
if ( ! strcmp ( F_44 ( V_252 ) , V_232 ) ) {
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
struct V_3 * V_4 = V_30 -> V_163 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_80 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
static void F_87 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_172 * V_173 ;
F_90 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
V_32 -> V_45 = V_30 ;
F_62 ( & V_32 -> V_266 , & V_30 -> V_255 ) ;
V_30 -> V_36 ++ ;
F_4 ( & V_32 -> V_177 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link)
F_50 ( V_173 , 0x3f ,
V_268 ) ;
F_6 ( & V_32 -> V_177 ) ;
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
F_86 ( & V_32 -> V_266 ) ;
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
T_7 F_94 ( struct V_31 * V_32 , char * V_269 )
{
struct V_251 * V_270 ;
struct V_29 * V_30 ;
T_7 V_55 = 0 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
V_270 = & V_30 -> V_170 . V_171 ;
V_55 += sprintf ( V_269 , L_68
L_69
L_70
L_71 ,
F_44 ( V_270 ) , V_30 -> V_40 ,
F_32 (
V_30 -> V_38 ) ,
F_33 (
V_30 -> V_41 ) ,
F_31 ( & V_32 -> V_126 ) ?
L_23 : L_26 ,
F_33 ( V_32 -> V_213 ) ) ;
}
F_6 ( & V_32 -> V_44 ) ;
return V_55 ;
}
T_7 F_95 (
struct V_31 * V_32 ,
const char * V_269 ,
T_8 V_271 )
{
struct V_204 * V_272 = V_32 -> V_206 ;
struct V_3 * V_4 = F_96 ( V_32 -> V_273 ) ;
struct V_29 * V_30 = NULL , * V_274 = NULL ;
unsigned char V_10 [ V_275 ] ;
int V_276 = 0 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_159 ;
if ( V_271 > V_275 ) {
F_15 ( L_72 ) ;
return - V_195 ;
}
memset ( V_10 , 0 , V_275 ) ;
memcpy ( V_10 , V_269 , V_271 ) ;
if ( strcmp ( F_97 ( V_10 ) , L_73 ) ) {
V_274 = F_88 ( V_4 ,
F_97 ( V_10 ) ) ;
if ( ! V_274 )
return - V_159 ;
}
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
if ( ! V_274 ) {
F_16 ( L_74
L_75
L_76
L_77 ,
V_272 -> V_210 -> V_211 ( V_272 ) ,
V_272 -> V_210 -> V_212 ( V_272 ) ,
F_44 ( & V_32 -> V_277 . V_171 ) ,
F_44 (
& V_30 -> V_170 . V_171 ) ,
V_30 -> V_40 ) ;
F_92 ( V_32 , V_30 ) ;
F_87 ( V_32 ,
V_4 -> V_16 . V_267 ) ;
F_6 ( & V_32 -> V_44 ) ;
return V_271 ;
}
F_92 ( V_32 , V_30 ) ;
V_276 = 1 ;
}
F_87 ( V_32 , V_274 ) ;
F_6 ( & V_32 -> V_44 ) ;
F_16 ( L_78
L_79 , ( V_276 ) ?
L_80 : L_81 , V_272 -> V_210 -> V_211 ( V_272 ) ,
V_272 -> V_210 -> V_212 ( V_272 ) ,
F_44 ( & V_32 -> V_277 . V_171 ) ,
F_44 ( & V_274 -> V_170 . V_171 ) ,
V_274 -> V_40 ) ;
F_89 ( V_274 ) ;
return V_271 ;
}
T_7 F_98 (
struct V_29 * V_30 ,
char * V_269 )
{
if ( ( V_30 -> V_63 & V_64 ) &&
( V_30 -> V_63 & V_256 ) )
return sprintf ( V_269 , L_82 ) ;
else if ( V_30 -> V_63 & V_256 )
return sprintf ( V_269 , L_83 ) ;
else if ( V_30 -> V_63 & V_64 )
return sprintf ( V_269 , L_84 ) ;
else
return sprintf ( V_269 , L_85 ) ;
}
T_7 F_99 (
struct V_29 * V_30 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_86 ) ;
return V_158 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) && ( V_93 != 2 ) && ( V_93 != 3 ) ) {
F_15 ( L_87
L_88 , V_93 ) ;
return - V_195 ;
}
if ( V_93 == 3 )
V_30 -> V_63 =
V_256 | V_64 ;
else if ( V_93 == 2 )
V_30 -> V_63 = V_64 ;
else if ( V_93 == 1 )
V_30 -> V_63 = V_256 ;
else
V_30 -> V_63 = 0 ;
return V_271 ;
}
T_7 F_101 (
struct V_29 * V_30 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_30 -> V_129 ) ;
}
T_7 F_102 (
struct V_29 * V_30 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_90 ) ;
return V_158 ;
}
if ( V_93 > V_278 ) {
F_15 ( L_91
L_92 , V_93 ,
V_278 ) ;
return - V_195 ;
}
V_30 -> V_129 = ( int ) V_93 ;
return V_271 ;
}
T_7 F_103 (
struct V_29 * V_30 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_30 -> V_186 ) ;
}
T_7 F_104 (
struct V_29 * V_30 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_93 ) ;
return V_158 ;
}
if ( V_93 > V_279 ) {
F_15 ( L_94
L_95 , V_93 ,
V_279 ) ;
return - V_195 ;
}
V_30 -> V_186 = ( int ) V_93 ;
return V_271 ;
}
T_7 F_105 (
struct V_29 * V_30 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_30 -> V_46 ) ;
}
T_7 F_106 (
struct V_29 * V_30 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_96 ) ;
return V_158 ;
}
if ( V_93 > V_280 ) {
F_15 ( L_97
L_98 , V_93 ,
V_280 ) ;
return - V_195 ;
}
V_30 -> V_46 = ( int ) V_93 ;
return V_271 ;
}
T_7 F_107 (
struct V_29 * V_30 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_30 -> V_37 ) ;
}
T_7 F_108 (
struct V_29 * V_30 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_99 ) ;
return V_158 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_100 , V_93 ) ;
return - V_195 ;
}
V_30 -> V_37 = ( int ) V_93 ;
return V_271 ;
}
T_7 F_109 ( struct V_31 * V_32 , char * V_269 )
{
return sprintf ( V_269 , L_89 ,
F_31 ( & V_32 -> V_126 ) ) ;
}
T_7 F_110 (
struct V_31 * V_32 ,
const char * V_269 ,
T_8 V_271 )
{
struct V_3 * V_4 = F_96 ( V_32 -> V_273 ) ;
unsigned long V_93 ;
int V_158 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_159 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_101 ) ;
return V_158 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_102 ,
V_93 ) ;
return - V_195 ;
}
V_158 = F_22 ( V_32 , 0 , ( int ) V_93 ) ;
if ( V_158 < 0 )
return - V_195 ;
return V_271 ;
}
T_7 F_111 (
struct V_31 * V_32 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_32 -> V_213 ) ;
}
T_7 F_112 (
struct V_31 * V_32 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_103 ) ;
return V_158 ;
}
if ( ( V_93 != V_147 ) &&
( V_93 != V_148 ) &&
( V_93 != V_149 ) ) {
F_15 ( L_104 ,
V_93 ) ;
return - V_195 ;
}
V_32 -> V_213 = ( int ) V_93 ;
return V_271 ;
}
T_7 F_113 (
struct V_31 * V_32 ,
char * V_269 )
{
return sprintf ( V_269 , L_89 , V_32 -> V_217 ) ;
}
T_7 F_114 (
struct V_31 * V_32 ,
const char * V_269 ,
T_8 V_271 )
{
unsigned long V_93 ;
int V_158 ;
V_158 = F_100 ( V_269 , 0 , & V_93 ) ;
if ( V_158 < 0 ) {
F_15 ( L_105 ) ;
return V_158 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_15 ( L_106
L_88 , V_93 ) ;
return - V_195 ;
}
V_32 -> V_217 = ( int ) V_93 ;
return V_271 ;
}
int F_115 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_123 -> V_124 &
V_125 ) &&
! ( V_4 -> V_120 -> V_121 & V_122 ) ) {
struct V_192 * V_193 ;
V_193 = F_73 ( V_4 ) ;
if ( F_39 ( V_193 ) )
return F_116 ( V_193 ) ;
F_4 ( & V_193 -> V_197 ) ;
F_76 ( V_193 ,
V_250 ) ;
F_6 ( & V_193 -> V_197 ) ;
F_16 ( L_107
L_108 ,
V_4 -> V_123 -> V_232 ) ;
}
return 0 ;
}
