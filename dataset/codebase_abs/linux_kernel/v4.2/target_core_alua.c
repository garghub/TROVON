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
V_10 [ V_12 ++ ] |= ( F_13 (
& V_30 -> V_38 ) & 0xff ) ;
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
F_14 ( V_11 , & V_10 [ 0 ] ) ;
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
F_15 ( struct V_1 * V_2 )
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
F_16 ( L_8 ) ;
V_53 = V_19 ;
goto V_62;
}
if ( ! ( V_51 -> V_63 & V_64 ) ) {
F_6 ( & V_47 -> V_44 ) ;
F_17 ( L_9
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
V_53 = F_18 ( V_56 ,
V_58 , & V_57 ) ;
if ( V_53 ) {
goto V_62;
}
if ( V_57 ) {
V_59 = F_19 ( V_52 + 2 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
if ( V_59 != V_30 -> V_40 )
continue;
F_20 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
if ( ! F_21 ( V_30 ,
V_4 , V_47 , V_49 ,
V_56 , 1 ) )
V_65 = true ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_22 ( & V_30 -> V_67 ) ;
break;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
} else {
struct V_31 * V_32 ;
V_60 = F_19 ( V_52 + 2 ) ;
F_4 ( & V_4 -> V_68 ) ;
F_8 (lun, &dev->dev_sep_list,
lun_dev_link) {
if ( V_32 -> V_43 != V_60 )
continue;
F_6 ( & V_4 -> V_68 ) ;
if ( ! F_23 (
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
static inline void F_24 ( struct V_1 * V_2 , T_4 V_69 )
{
F_17 ( L_11
L_12
L_13 ,
V_2 -> V_70 -> V_71 () , V_69 ) ;
V_2 -> V_72 = 0x04 ;
V_2 -> V_73 = V_69 ;
}
static inline void F_25 (
struct V_1 * V_2 ,
unsigned char * V_74 ,
int V_75 )
{
V_2 -> V_76 |= V_77 ;
V_2 -> V_78 = V_75 ;
}
static inline int F_26 (
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
V_90 = F_27 ( V_93 , V_79 * V_80 ) ;
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
F_24 ( V_2 , V_94 ) ;
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
F_24 ( V_2 , V_96 ) ;
return 1 ;
case V_97 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_24 ( V_2 , V_94 ) ;
return 1 ;
default:
break;
}
}
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
return 0 ;
}
static inline int F_28 (
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
F_24 ( V_2 , V_96 ) ;
return 1 ;
}
case V_109 :
switch ( V_74 [ 1 ] & 0x1f ) {
case V_110 :
return 0 ;
default:
F_24 ( V_2 , V_96 ) ;
return 1 ;
}
case V_111 :
switch ( V_74 [ 1 ] ) {
case V_112 :
return 0 ;
default:
F_24 ( V_2 , V_96 ) ;
return 1 ;
}
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
return 0 ;
default:
F_24 ( V_2 , V_96 ) ;
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
F_24 ( V_2 , V_94 ) ;
return 1 ;
}
case V_111 :
switch ( V_74 [ 1 ] ) {
case V_112 :
return 0 ;
default:
F_24 ( V_2 , V_94 ) ;
return 1 ;
}
case V_113 :
case V_116 :
case V_117 :
return 0 ;
default:
F_24 ( V_2 , V_94 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_30 (
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
F_24 ( V_2 , V_118 ) ;
return 1 ;
}
case V_113 :
case V_116 :
case V_117 :
return 0 ;
default:
F_24 ( V_2 , V_118 ) ;
return 1 ;
}
return 0 ;
}
T_1
F_31 ( struct V_1 * V_2 )
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
if ( F_13 ( & V_32 -> V_126 ) ) {
F_17 ( L_14
L_15 ) ;
F_24 ( V_2 , V_127 ) ;
return V_128 ;
}
if ( ! V_32 -> V_45 )
return 0 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
V_119 = F_13 ( & V_30 -> V_38 ) ;
V_75 = V_30 -> V_129 ;
F_6 ( & V_32 -> V_44 ) ;
if ( V_119 == V_130 )
return 0 ;
switch ( V_119 ) {
case V_131 :
F_25 ( V_2 , V_74 , V_75 ) ;
break;
case V_95 :
if ( F_28 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_97 :
if ( F_29 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_132 :
if ( F_30 ( V_2 , V_74 ) )
return V_128 ;
break;
case V_133 :
if ( F_26 ( V_2 , V_30 ) )
return V_128 ;
break;
case V_134 :
default:
F_16 ( L_16 ,
V_119 ) ;
return V_14 ;
}
return 0 ;
}
static T_1
F_18 ( int V_135 , int V_136 , int * V_57 )
{
switch ( V_135 ) {
case V_130 :
if ( ! ( V_136 & V_137 ) )
goto V_138;
* V_57 = 1 ;
break;
case V_131 :
if ( ! ( V_136 & V_139 ) )
goto V_138;
* V_57 = 1 ;
break;
case V_95 :
if ( ! ( V_136 & V_140 ) )
goto V_138;
* V_57 = 1 ;
break;
case V_97 :
if ( ! ( V_136 & V_141 ) )
goto V_138;
* V_57 = 1 ;
break;
case V_133 :
if ( ! ( V_136 & V_142 ) )
goto V_138;
* V_57 = 1 ;
break;
case V_134 :
if ( ! ( V_136 & V_143 ) )
goto V_138;
* V_57 = 0 ;
break;
case V_132 :
goto V_138;
default:
F_16 ( L_16 , V_135 ) ;
return V_61 ;
}
return 0 ;
V_138:
F_16 ( L_17 ,
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
char * F_33 ( int V_144 )
{
switch ( V_144 ) {
case V_145 :
return L_26 ;
case V_146 :
return L_27 ;
case V_147 :
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
const char * V_148 ,
unsigned char * V_149 ,
T_2 V_150 )
{
struct V_151 * V_151 = F_38 ( V_148 , V_152 | V_153 | V_154 , 0600 ) ;
int V_155 ;
if ( F_39 ( V_151 ) ) {
F_16 ( L_29 , V_148 ) ;
return - V_156 ;
}
V_155 = F_40 ( V_151 , V_149 , V_150 , 0 ) ;
if ( V_155 < 0 )
F_16 ( L_30 , V_148 ) ;
F_41 ( V_151 ) ;
return ( V_155 < 0 ) ? - V_157 : 0 ;
}
static int F_42 (
struct V_29 * V_30 )
{
unsigned char * V_149 ;
struct V_158 * V_159 = & V_30 -> V_160 -> V_158 ;
char V_148 [ V_161 ] ;
int V_55 , V_53 ;
V_149 = F_43 ( V_162 , V_163 ) ;
if ( ! V_149 ) {
F_16 ( L_31 ) ;
return - V_164 ;
}
memset ( V_148 , 0 , V_161 ) ;
V_55 = snprintf ( V_149 , V_162 ,
L_32
L_33
L_34 ,
V_30 -> V_40 ,
V_30 -> V_165 ,
V_30 -> V_41 ) ;
snprintf ( V_148 , V_161 ,
L_35 , & V_159 -> V_166 [ 0 ] ,
F_44 ( & V_30 -> V_167 . V_168 ) ) ;
V_53 = F_37 ( V_148 , V_149 , V_55 ) ;
F_45 ( V_149 ) ;
return V_53 ;
}
static void F_46 ( struct V_29 * V_30 )
{
struct V_169 * V_170 ;
struct V_31 * V_32 ;
struct V_171 * V_172 ;
F_4 ( & V_30 -> V_42 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
if ( ! F_47 ( & V_32 -> V_173 ) )
continue;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_174 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link) {
V_172 = F_48 ( V_170 -> V_171 ,
F_49 ( & V_32 -> V_174 ) ) ;
if ( ( V_30 -> V_41 ==
V_146 ) &&
( V_30 -> V_175 != NULL ) &&
( V_30 -> V_175 == V_32 ) )
continue;
if ( V_172 && ( V_30 -> V_176 != NULL ) &&
( V_30 -> V_176 == V_172 -> V_177 ) )
continue;
F_50 ( V_170 , 0x2A ,
V_178 ) ;
}
F_6 ( & V_32 -> V_174 ) ;
F_4 ( & V_30 -> V_42 ) ;
F_51 ( & V_32 -> V_173 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
}
static void F_52 ( struct V_179 * V_180 )
{
struct V_29 * V_30 = F_53 ( V_180 ,
struct V_29 , V_181 . V_180 ) ;
struct V_3 * V_4 = V_30 -> V_160 ;
bool V_182 = ( V_30 -> V_41 ==
V_146 ) ;
if ( V_30 -> V_183 ) {
F_54 ( & V_30 -> V_184 ) ;
F_42 ( V_30 ) ;
F_55 ( & V_30 -> V_184 ) ;
}
F_56 ( & V_30 -> V_38 ,
V_30 -> V_165 ) ;
F_17 ( L_36
L_37 , ( V_182 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_167 . V_168 ) ,
V_30 -> V_40 ,
F_32 ( V_30 -> V_185 ) ,
F_32 ( V_30 -> V_165 ) ) ;
F_46 ( V_30 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_57 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
if ( V_30 -> V_186 )
F_58 ( V_30 -> V_186 ) ;
}
static int F_59 (
struct V_29 * V_30 ,
int V_187 ,
int V_182 )
{
struct V_3 * V_4 = V_30 -> V_160 ;
F_60 ( V_188 ) ;
if ( F_13 ( & V_30 -> V_38 ) == V_187 )
return 0 ;
if ( V_187 == V_132 )
return - V_189 ;
if ( ! V_182 && V_30 -> V_46 &&
F_13 ( & V_30 -> V_38 ) ==
V_132 ) {
V_30 -> V_165 = V_187 ;
V_30 -> V_186 = & V_188 ;
F_61 ( & V_30 -> V_181 ) ;
F_62 ( & V_188 ) ;
V_30 -> V_186 = NULL ;
return 0 ;
}
V_30 -> V_185 =
F_13 ( & V_30 -> V_38 ) ;
V_30 -> V_165 = V_187 ;
F_56 ( & V_30 -> V_38 ,
V_132 ) ;
V_30 -> V_41 = ( V_182 ) ?
V_146 :
V_147 ;
F_46 ( V_30 ) ;
if ( V_30 -> V_190 != 0 )
F_36 ( V_30 -> V_190 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_63 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
if ( ! V_182 && V_30 -> V_46 ) {
unsigned long V_191 ;
V_191 = V_30 -> V_46 * V_192 ;
F_64 ( V_30 -> V_160 -> V_193 ,
& V_30 -> V_181 ,
V_191 ) ;
} else {
V_30 -> V_186 = & V_188 ;
F_64 ( V_30 -> V_160 -> V_193 ,
& V_30 -> V_181 , 0 ) ;
F_62 ( & V_188 ) ;
V_30 -> V_186 = NULL ;
}
return 0 ;
}
int F_21 (
struct V_29 * V_51 ,
struct V_3 * V_194 ,
struct V_31 * V_47 ,
struct V_48 * V_195 ,
int V_187 ,
int V_182 )
{
struct V_3 * V_4 ;
struct V_196 * V_197 ;
struct V_198 * V_199 , * V_200 ;
struct V_29 * V_30 ;
int V_57 , V_58 , V_53 = 0 ;
V_58 = V_51 -> V_39 ;
if ( F_18 ( V_187 , V_58 , & V_57 ) != 0 )
return - V_201 ;
V_200 = V_194 -> V_202 ;
F_4 ( & V_200 -> V_203 ) ;
V_197 = V_200 -> V_197 ;
F_63 ( & V_197 -> V_204 ) ;
F_6 ( & V_200 -> V_203 ) ;
if ( ! V_197 -> V_205 ) {
V_51 -> V_175 = V_47 ;
V_51 -> V_176 = V_195 ;
V_53 = F_59 ( V_51 ,
V_187 , V_182 ) ;
F_22 ( & V_197 -> V_204 ) ;
return V_53 ;
}
F_4 ( & V_197 -> V_206 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_199 -> V_207 ;
F_20 ( & V_199 -> V_208 ) ;
F_6 ( & V_197 -> V_206 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
if ( V_51 -> V_40 != V_30 -> V_40 )
continue;
if ( V_51 == V_30 ) {
V_30 -> V_175 = V_47 ;
V_30 -> V_176 = V_195 ;
} else {
V_30 -> V_175 = NULL ;
V_30 -> V_176 = NULL ;
}
F_20 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
V_53 = F_59 ( V_30 ,
V_187 , V_182 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_22 ( & V_30 -> V_67 ) ;
if ( V_53 )
break;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_4 ( & V_197 -> V_206 ) ;
F_22 ( & V_199 -> V_208 ) ;
}
F_6 ( & V_197 -> V_206 ) ;
if ( ! V_53 ) {
F_17 ( L_40
L_41 ,
F_44 ( & V_197 -> V_209 . V_168 ) ,
V_51 -> V_40 ,
( V_182 ) ? L_38 : L_39 ,
F_32 ( V_187 ) ) ;
}
F_22 ( & V_197 -> V_204 ) ;
return V_53 ;
}
static int F_65 ( struct V_31 * V_32 )
{
struct V_210 * V_211 = V_32 -> V_212 ;
unsigned char * V_149 ;
char V_148 [ V_161 ] , V_159 [ V_213 ] ;
int V_55 , V_53 ;
F_54 ( & V_32 -> V_214 ) ;
V_149 = F_43 ( V_162 , V_163 ) ;
if ( ! V_149 ) {
F_16 ( L_31 ) ;
V_53 = - V_164 ;
goto V_215;
}
memset ( V_148 , 0 , V_161 ) ;
memset ( V_159 , 0 , V_213 ) ;
V_55 = snprintf ( V_159 , V_213 , L_42 ,
V_211 -> V_216 -> V_217 ( V_211 ) ) ;
if ( V_211 -> V_216 -> V_218 != NULL )
snprintf ( V_159 + V_55 , V_213 - V_55 , L_43 ,
V_211 -> V_216 -> V_218 ( V_211 ) ) ;
V_55 = snprintf ( V_149 , V_162 , L_44
L_45 ,
F_13 ( & V_32 -> V_126 ) ,
V_32 -> V_219 ) ;
snprintf ( V_148 , V_161 , L_46 ,
V_211 -> V_216 -> V_71 () , V_159 ,
V_32 -> V_220 ) ;
V_53 = F_37 ( V_148 , V_149 , V_55 ) ;
F_45 ( V_149 ) ;
V_215:
F_55 ( & V_32 -> V_214 ) ;
return V_53 ;
}
static int F_23 (
struct V_31 * V_32 ,
int V_182 ,
int V_221 )
{
struct V_29 * V_30 ;
int V_222 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( ! V_30 ) {
F_6 ( & V_32 -> V_44 ) ;
F_16 ( L_47
L_48 ) ;
return - V_201 ;
}
V_222 = V_30 -> V_190 ;
if ( V_221 )
F_56 ( & V_32 -> V_126 , 1 ) ;
else
F_56 ( & V_32 -> V_126 , 0 ) ;
V_32 -> V_219 = ( V_182 ) ?
V_146 :
V_147 ;
F_17 ( L_36
L_49 , ( V_182 ) ? L_38 :
L_39 , F_44 ( & V_30 -> V_167 . V_168 ) ,
V_30 -> V_40 , ( V_221 ) ? L_50 : L_51 ) ;
F_6 ( & V_32 -> V_44 ) ;
if ( V_222 != 0 )
F_36 ( V_222 ) ;
if ( V_32 -> V_223 )
F_65 ( V_32 ) ;
return 0 ;
}
struct V_6 *
F_66 ( struct V_224 * V_225 ,
T_5 V_92 , T_5 V_91 )
{
struct V_6 * V_226 ;
V_226 = F_67 ( V_227 , V_163 ) ;
if ( ! V_226 ) {
F_16 ( L_52 ) ;
return F_68 ( - V_164 ) ;
}
F_69 ( & V_226 -> V_228 ) ;
V_226 -> V_22 = V_92 ;
V_226 -> V_23 = V_91 ;
F_70 ( & V_226 -> V_18 , V_225 ) ;
return V_226 ;
}
int
F_71 ( struct V_6 * V_226 ,
int V_229 , int V_135 )
{
struct V_8 * V_230 ;
F_8 (lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_230 -> V_27 == V_229 ) {
F_16 ( L_53 , V_229 ) ;
return - V_201 ;
}
}
V_230 = F_67 ( V_231 , V_163 ) ;
if ( ! V_230 ) {
F_16 ( L_54 ) ;
return - V_164 ;
}
V_230 -> V_25 = V_135 ;
V_230 -> V_27 = V_229 ;
F_70 ( & V_230 -> V_228 ,
& V_226 -> V_228 ) ;
return 0 ;
}
void
F_72 ( struct V_224 * V_232 )
{
struct V_6 * V_226 , * V_233 ;
struct V_8 * V_230 , * V_234 ;
F_73 (lba_map, lba_map_tmp, lba_list,
lba_map_list) {
F_73 (lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
F_74 ( & V_230 -> V_228 ) ;
F_75 ( V_231 ,
V_230 ) ;
}
F_74 ( & V_226 -> V_18 ) ;
F_75 ( V_227 , V_226 ) ;
}
}
void
F_76 ( struct V_3 * V_4 , struct V_224 * V_18 ,
int V_79 , int V_80 )
{
struct V_224 V_235 ;
struct V_29 * V_30 ;
int V_236 = 0 , V_237 ;
F_69 ( & V_235 ) ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_84 = V_79 ;
V_4 -> V_16 . V_85 = V_80 ;
F_77 ( & V_4 -> V_16 . V_18 , & V_235 ) ;
if ( V_18 ) {
F_77 ( V_18 , & V_4 -> V_16 . V_18 ) ;
V_236 = 1 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_237 = V_30 -> V_39 ;
if ( V_236 )
V_237 |= V_142 ;
else
V_237 &= ~ V_142 ;
V_30 -> V_39 = V_237 ;
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_72 ( & V_235 ) ;
}
struct V_196 *
F_78 ( const char * V_238 , int V_239 )
{
struct V_196 * V_197 ;
V_197 = F_67 ( V_240 , V_163 ) ;
if ( ! V_197 ) {
F_16 ( L_55 ) ;
return F_68 ( - V_164 ) ;
}
F_69 ( & V_197 -> V_241 ) ;
F_69 ( & V_197 -> V_242 ) ;
F_79 ( & V_197 -> V_206 ) ;
F_56 ( & V_197 -> V_204 , 0 ) ;
if ( V_239 ) {
V_197 -> V_205 = V_243 ++ ;
V_197 -> V_244 = 1 ;
V_245 ++ ;
}
return V_197 ;
}
int F_80 ( struct V_196 * V_197 , T_3 V_205 )
{
struct V_196 * V_246 ;
T_3 V_247 ;
if ( V_197 -> V_244 ) {
F_2 ( L_56
L_57 ) ;
return - V_201 ;
}
F_4 ( & V_248 ) ;
if ( V_245 == 0x0000ffff ) {
F_16 ( L_58
L_59 ) ;
F_6 ( & V_248 ) ;
F_75 ( V_240 , V_197 ) ;
return - V_249 ;
}
V_250:
V_247 = ( V_205 != 0 ) ? V_205 :
V_243 ++ ;
F_8 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_246 -> V_205 == V_247 ) {
if ( ! V_205 )
goto V_250;
F_2 ( L_60
L_61 ,
V_205 ) ;
F_6 ( & V_248 ) ;
return - V_201 ;
}
}
V_197 -> V_205 = V_247 ;
V_197 -> V_244 = 1 ;
F_70 ( & V_197 -> V_241 , & V_251 ) ;
V_245 ++ ;
F_6 ( & V_248 ) ;
return 0 ;
}
static struct V_198 *
F_81 ( struct V_3 * V_4 )
{
struct V_198 * V_199 ;
V_199 = F_67 ( V_252 , V_163 ) ;
if ( ! V_199 ) {
F_16 ( L_62 ) ;
return F_68 ( - V_164 ) ;
}
F_69 ( & V_199 -> V_242 ) ;
F_79 ( & V_199 -> V_203 ) ;
F_56 ( & V_199 -> V_208 , 0 ) ;
V_199 -> V_207 = V_4 ;
V_4 -> V_202 = V_199 ;
return V_199 ;
}
void F_82 ( struct V_196 * V_197 )
{
struct V_198 * V_199 , * V_253 ;
F_4 ( & V_248 ) ;
F_74 ( & V_197 -> V_241 ) ;
V_245 -- ;
F_6 ( & V_248 ) ;
while ( F_13 ( & V_197 -> V_204 ) )
F_83 () ;
F_4 ( & V_197 -> V_206 ) ;
F_73 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_199 -> V_254 ) {
F_74 ( & V_199 -> V_242 ) ;
V_197 -> V_255 -- ;
V_199 -> V_254 = 0 ;
}
F_6 ( & V_197 -> V_206 ) ;
F_4 ( & V_199 -> V_203 ) ;
if ( V_197 != V_256 )
F_84 ( V_199 ,
V_256 ) ;
else
V_199 -> V_197 = NULL ;
F_6 ( & V_199 -> V_203 ) ;
F_4 ( & V_197 -> V_206 ) ;
}
F_6 ( & V_197 -> V_206 ) ;
F_75 ( V_240 , V_197 ) ;
}
void F_85 ( struct V_3 * V_4 )
{
struct V_196 * V_197 ;
struct V_198 * V_199 ;
V_199 = V_4 -> V_202 ;
if ( ! V_199 )
return;
while ( F_13 ( & V_199 -> V_208 ) )
F_83 () ;
F_4 ( & V_199 -> V_203 ) ;
V_197 = V_199 -> V_197 ;
if ( V_197 ) {
F_4 ( & V_197 -> V_206 ) ;
if ( V_199 -> V_254 ) {
F_74 ( & V_199 -> V_242 ) ;
V_197 -> V_255 -- ;
V_199 -> V_254 = 0 ;
}
F_6 ( & V_197 -> V_206 ) ;
V_199 -> V_197 = NULL ;
}
F_6 ( & V_199 -> V_203 ) ;
F_75 ( V_252 , V_199 ) ;
}
struct V_196 * F_86 ( const char * V_238 )
{
struct V_196 * V_197 ;
struct V_257 * V_258 ;
F_4 ( & V_248 ) ;
F_8 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_197 -> V_244 )
continue;
V_258 = & V_197 -> V_209 . V_168 ;
if ( ! strcmp ( F_44 ( V_258 ) , V_238 ) ) {
F_63 ( & V_197 -> V_204 ) ;
F_6 ( & V_248 ) ;
return V_197 ;
}
}
F_6 ( & V_248 ) ;
return NULL ;
}
void F_87 ( struct V_196 * V_197 )
{
F_4 ( & V_248 ) ;
F_57 ( & V_197 -> V_204 ) ;
F_6 ( & V_248 ) ;
}
void F_84 (
struct V_198 * V_199 ,
struct V_196 * V_197 )
{
F_4 ( & V_197 -> V_206 ) ;
V_199 -> V_197 = V_197 ;
V_199 -> V_254 = 1 ;
F_70 ( & V_199 -> V_242 , & V_197 -> V_242 ) ;
V_197 -> V_255 ++ ;
F_6 ( & V_197 -> V_206 ) ;
}
void F_88 (
struct V_198 * V_199 ,
struct V_196 * V_197 )
{
F_4 ( & V_197 -> V_206 ) ;
F_74 ( & V_199 -> V_242 ) ;
V_199 -> V_197 = NULL ;
V_199 -> V_254 = 0 ;
V_197 -> V_255 -- ;
F_6 ( & V_197 -> V_206 ) ;
}
struct V_29 * F_89 ( struct V_3 * V_4 ,
const char * V_238 , int V_239 )
{
struct V_29 * V_30 ;
V_30 = F_67 ( V_259 , V_163 ) ;
if ( ! V_30 ) {
F_16 ( L_63 ) ;
return NULL ;
}
F_69 ( & V_30 -> V_260 ) ;
F_69 ( & V_30 -> V_261 ) ;
F_90 ( & V_30 -> V_184 ) ;
F_79 ( & V_30 -> V_42 ) ;
F_56 ( & V_30 -> V_67 , 0 ) ;
F_91 ( & V_30 -> V_181 ,
F_52 ) ;
V_30 -> V_160 = V_4 ;
F_56 ( & V_30 -> V_38 ,
V_130 ) ;
V_30 -> V_63 =
V_64 | V_262 ;
V_30 -> V_129 = V_263 ;
V_30 -> V_190 = V_264 ;
V_30 -> V_46 = V_265 ;
V_30 -> V_39 =
V_266 | V_143 |
V_141 | V_140 | V_139 | V_137 ;
if ( V_239 ) {
F_4 ( & V_4 -> V_16 . V_35 ) ;
V_30 -> V_40 =
V_4 -> V_16 . V_267 ++ ;
V_30 -> V_66 = 1 ;
V_4 -> V_16 . V_268 ++ ;
F_70 ( & V_30 -> V_260 ,
& V_4 -> V_16 . V_269 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
return V_30 ;
}
int F_92 (
struct V_29 * V_30 ,
T_3 V_40 )
{
struct V_3 * V_4 = V_30 -> V_160 ;
struct V_29 * V_270 ;
T_3 V_271 ;
if ( V_30 -> V_66 ) {
F_2 ( L_64
L_57 ) ;
return - V_201 ;
}
F_4 ( & V_4 -> V_16 . V_35 ) ;
if ( V_4 -> V_16 . V_268 == 0x0000ffff ) {
F_16 ( L_65
L_59 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_75 ( V_259 , V_30 ) ;
return - V_249 ;
}
V_250:
V_271 = ( V_40 != 0 ) ? V_40 :
V_4 -> V_16 . V_267 ++ ;
F_8 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_270 -> V_40 == V_271 ) {
if ( ! V_40 )
goto V_250;
F_16 ( L_66
L_67 , V_40 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return - V_201 ;
}
}
V_30 -> V_40 = V_271 ;
V_30 -> V_66 = 1 ;
F_70 ( & V_30 -> V_260 ,
& V_4 -> V_16 . V_269 ) ;
V_4 -> V_16 . V_268 ++ ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return 0 ;
}
void F_93 (
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_160 ;
struct V_31 * V_32 , * V_272 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_74 ( & V_30 -> V_260 ) ;
V_4 -> V_16 . V_267 -- ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
F_61 ( & V_30 -> V_181 ) ;
while ( F_13 ( & V_30 -> V_67 ) )
F_83 () ;
F_4 ( & V_30 -> V_42 ) ;
F_73 (lun, next,
&tg_pt_gp->tg_pt_gp_lun_list, lun_tg_pt_gp_link) {
F_94 ( & V_32 -> V_273 ) ;
V_30 -> V_36 -- ;
F_6 ( & V_30 -> V_42 ) ;
F_4 ( & V_32 -> V_44 ) ;
if ( V_30 != V_4 -> V_16 . V_274 ) {
F_95 ( V_32 ,
V_4 -> V_16 . V_274 ) ;
} else
V_32 -> V_45 = NULL ;
F_6 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
}
F_6 ( & V_30 -> V_42 ) ;
F_75 ( V_259 , V_30 ) ;
}
static struct V_29 * F_96 (
struct V_3 * V_4 , const char * V_238 )
{
struct V_29 * V_30 ;
struct V_257 * V_258 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_30 -> V_66 )
continue;
V_258 = & V_30 -> V_167 . V_168 ;
if ( ! strcmp ( F_44 ( V_258 ) , V_238 ) ) {
F_63 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
return V_30 ;
}
}
F_6 ( & V_4 -> V_16 . V_35 ) ;
return NULL ;
}
static void F_97 (
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_160 ;
F_4 ( & V_4 -> V_16 . V_35 ) ;
F_57 ( & V_30 -> V_67 ) ;
F_6 ( & V_4 -> V_16 . V_35 ) ;
}
static void F_95 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_169 * V_170 ;
F_98 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
V_32 -> V_45 = V_30 ;
F_70 ( & V_32 -> V_273 , & V_30 -> V_261 ) ;
V_30 -> V_36 ++ ;
F_4 ( & V_32 -> V_174 ) ;
F_8 (se_deve, &lun->lun_deve_list, lun_link)
F_50 ( V_170 , 0x3f ,
V_275 ) ;
F_6 ( & V_32 -> V_174 ) ;
F_6 ( & V_30 -> V_42 ) ;
}
void F_99 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
F_4 ( & V_32 -> V_44 ) ;
F_95 ( V_32 , V_30 ) ;
F_6 ( & V_32 -> V_44 ) ;
}
static void F_100 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
F_98 ( & V_32 -> V_44 ) ;
F_4 ( & V_30 -> V_42 ) ;
F_94 ( & V_32 -> V_273 ) ;
V_30 -> V_36 -- ;
F_6 ( & V_30 -> V_42 ) ;
V_32 -> V_45 = NULL ;
}
void F_101 ( struct V_31 * V_32 )
{
struct V_29 * V_30 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 )
F_100 ( V_32 , V_30 ) ;
F_6 ( & V_32 -> V_44 ) ;
}
T_6 F_102 ( struct V_31 * V_32 , char * V_276 )
{
struct V_257 * V_277 ;
struct V_29 * V_30 ;
T_6 V_55 = 0 ;
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
V_277 = & V_30 -> V_167 . V_168 ;
V_55 += sprintf ( V_276 , L_68
L_69
L_70
L_71 ,
F_44 ( V_277 ) , V_30 -> V_40 ,
F_32 ( F_13 (
& V_30 -> V_38 ) ) ,
F_33 (
V_30 -> V_41 ) ,
F_13 ( & V_32 -> V_126 ) ?
L_23 : L_26 ,
F_33 ( V_32 -> V_219 ) ) ;
}
F_6 ( & V_32 -> V_44 ) ;
return V_55 ;
}
T_6 F_103 (
struct V_31 * V_32 ,
const char * V_276 ,
T_7 V_278 )
{
struct V_210 * V_279 = V_32 -> V_212 ;
struct V_3 * V_4 = F_104 ( V_32 -> V_280 ) ;
struct V_29 * V_30 = NULL , * V_281 = NULL ;
unsigned char V_10 [ V_282 ] ;
int V_283 = 0 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_156 ;
if ( V_278 > V_282 ) {
F_16 ( L_72 ) ;
return - V_201 ;
}
memset ( V_10 , 0 , V_282 ) ;
memcpy ( V_10 , V_276 , V_278 ) ;
if ( strcmp ( F_105 ( V_10 ) , L_73 ) ) {
V_281 = F_96 ( V_4 ,
F_105 ( V_10 ) ) ;
if ( ! V_281 )
return - V_156 ;
}
F_4 ( & V_32 -> V_44 ) ;
V_30 = V_32 -> V_45 ;
if ( V_30 ) {
if ( ! V_281 ) {
F_17 ( L_74
L_75
L_76
L_77 ,
V_279 -> V_216 -> V_217 ( V_279 ) ,
V_279 -> V_216 -> V_218 ( V_279 ) ,
F_44 ( & V_32 -> V_284 . V_168 ) ,
F_44 (
& V_30 -> V_167 . V_168 ) ,
V_30 -> V_40 ) ;
F_100 ( V_32 , V_30 ) ;
F_95 ( V_32 ,
V_4 -> V_16 . V_274 ) ;
F_6 ( & V_32 -> V_44 ) ;
return V_278 ;
}
F_100 ( V_32 , V_30 ) ;
V_283 = 1 ;
}
F_95 ( V_32 , V_281 ) ;
F_6 ( & V_32 -> V_44 ) ;
F_17 ( L_78
L_79 , ( V_283 ) ?
L_80 : L_81 , V_279 -> V_216 -> V_217 ( V_279 ) ,
V_279 -> V_216 -> V_218 ( V_279 ) ,
F_44 ( & V_32 -> V_284 . V_168 ) ,
F_44 ( & V_281 -> V_167 . V_168 ) ,
V_281 -> V_40 ) ;
F_97 ( V_281 ) ;
return V_278 ;
}
T_6 F_106 (
struct V_29 * V_30 ,
char * V_276 )
{
if ( ( V_30 -> V_63 & V_64 ) &&
( V_30 -> V_63 & V_262 ) )
return sprintf ( V_276 , L_82 ) ;
else if ( V_30 -> V_63 & V_262 )
return sprintf ( V_276 , L_83 ) ;
else if ( V_30 -> V_63 & V_64 )
return sprintf ( V_276 , L_84 ) ;
else
return sprintf ( V_276 , L_85 ) ;
}
T_6 F_107 (
struct V_29 * V_30 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_86 ) ;
return V_155 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) && ( V_93 != 2 ) && ( V_93 != 3 ) ) {
F_16 ( L_87
L_88 , V_93 ) ;
return - V_201 ;
}
if ( V_93 == 3 )
V_30 -> V_63 =
V_262 | V_64 ;
else if ( V_93 == 2 )
V_30 -> V_63 = V_64 ;
else if ( V_93 == 1 )
V_30 -> V_63 = V_262 ;
else
V_30 -> V_63 = 0 ;
return V_278 ;
}
T_6 F_109 (
struct V_29 * V_30 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_30 -> V_129 ) ;
}
T_6 F_110 (
struct V_29 * V_30 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_90 ) ;
return V_155 ;
}
if ( V_93 > V_285 ) {
F_16 ( L_91
L_92 , V_93 ,
V_285 ) ;
return - V_201 ;
}
V_30 -> V_129 = ( int ) V_93 ;
return V_278 ;
}
T_6 F_111 (
struct V_29 * V_30 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_30 -> V_190 ) ;
}
T_6 F_112 (
struct V_29 * V_30 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_93 ) ;
return V_155 ;
}
if ( V_93 > V_286 ) {
F_16 ( L_94
L_95 , V_93 ,
V_286 ) ;
return - V_201 ;
}
V_30 -> V_190 = ( int ) V_93 ;
return V_278 ;
}
T_6 F_113 (
struct V_29 * V_30 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_30 -> V_46 ) ;
}
T_6 F_114 (
struct V_29 * V_30 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_96 ) ;
return V_155 ;
}
if ( V_93 > V_287 ) {
F_16 ( L_97
L_98 , V_93 ,
V_287 ) ;
return - V_201 ;
}
V_30 -> V_46 = ( int ) V_93 ;
return V_278 ;
}
T_6 F_115 (
struct V_29 * V_30 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_30 -> V_37 ) ;
}
T_6 F_116 (
struct V_29 * V_30 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_99 ) ;
return V_155 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_16 ( L_100 , V_93 ) ;
return - V_201 ;
}
V_30 -> V_37 = ( int ) V_93 ;
return V_278 ;
}
T_6 F_117 ( struct V_31 * V_32 , char * V_276 )
{
return sprintf ( V_276 , L_89 ,
F_13 ( & V_32 -> V_126 ) ) ;
}
T_6 F_118 (
struct V_31 * V_32 ,
const char * V_276 ,
T_7 V_278 )
{
struct V_3 * V_4 = F_104 ( V_32 -> V_280 ) ;
unsigned long V_93 ;
int V_155 ;
if ( V_4 -> V_123 -> V_124 & V_125 ||
( V_4 -> V_120 -> V_121 & V_122 ) )
return - V_156 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_101 ) ;
return V_155 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_16 ( L_102 ,
V_93 ) ;
return - V_201 ;
}
V_155 = F_23 ( V_32 , 0 , ( int ) V_93 ) ;
if ( V_155 < 0 )
return - V_201 ;
return V_278 ;
}
T_6 F_119 (
struct V_31 * V_32 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_32 -> V_219 ) ;
}
T_6 F_120 (
struct V_31 * V_32 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_103 ) ;
return V_155 ;
}
if ( ( V_93 != V_145 ) &&
( V_93 != V_146 ) &&
( V_93 != V_147 ) ) {
F_16 ( L_104 ,
V_93 ) ;
return - V_201 ;
}
V_32 -> V_219 = ( int ) V_93 ;
return V_278 ;
}
T_6 F_121 (
struct V_31 * V_32 ,
char * V_276 )
{
return sprintf ( V_276 , L_89 , V_32 -> V_223 ) ;
}
T_6 F_122 (
struct V_31 * V_32 ,
const char * V_276 ,
T_7 V_278 )
{
unsigned long V_93 ;
int V_155 ;
V_155 = F_108 ( V_276 , 0 , & V_93 ) ;
if ( V_155 < 0 ) {
F_16 ( L_105 ) ;
return V_155 ;
}
if ( ( V_93 != 0 ) && ( V_93 != 1 ) ) {
F_16 ( L_106
L_88 , V_93 ) ;
return - V_201 ;
}
V_32 -> V_223 = ( int ) V_93 ;
return V_278 ;
}
int F_123 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_123 -> V_124 & V_125 ) &&
! ( V_4 -> V_120 -> V_121 & V_122 ) ) {
struct V_198 * V_199 ;
V_199 = F_81 ( V_4 ) ;
if ( F_39 ( V_199 ) )
return F_124 ( V_199 ) ;
F_4 ( & V_199 -> V_203 ) ;
F_84 ( V_199 ,
V_256 ) ;
F_6 ( & V_199 -> V_203 ) ;
F_17 ( L_107
L_108 ,
V_4 -> V_123 -> V_238 ) ;
}
return 0 ;
}
