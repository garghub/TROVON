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
struct V_33 * V_34 ;
unsigned char * V_10 ;
T_2 V_11 = 0 , V_12 ;
int V_35 = ( V_2 -> V_36 [ 1 ] & 0x20 ) ;
if ( V_35 != 0 )
V_12 = 8 ;
else
V_12 = 4 ;
if ( V_2 -> V_13 < V_12 ) {
F_2 ( L_3
L_4 , V_2 -> V_13 ,
( V_35 ) ? L_5 : L_6 ) ;
return V_14 ;
}
V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return V_15 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ( V_12 + 8 + ( V_32 -> V_38 * 4 ) ) >
V_2 -> V_13 ) {
V_11 += 8 + ( V_32 -> V_38 * 4 ) ;
continue;
}
if ( V_32 -> V_39 )
V_10 [ V_12 ] = 0x80 ;
V_10 [ V_12 ++ ] |= ( F_13 (
& V_32 -> V_40 ) & 0xff ) ;
V_10 [ V_12 ++ ] |= V_32 -> V_41 ;
V_10 [ V_12 ++ ] = ( ( V_32 -> V_42 >> 8 ) & 0xff ) ;
V_10 [ V_12 ++ ] = ( V_32 -> V_42 & 0xff ) ;
V_12 ++ ;
V_10 [ V_12 ++ ] = ( V_32 -> V_43 & 0xff ) ;
V_10 [ V_12 ++ ] = 0x00 ;
V_10 [ V_12 ++ ] = ( V_32 -> V_38 & 0xff ) ;
V_11 += 8 ;
F_4 ( & V_32 -> V_44 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_30 = V_34 -> V_45 ;
V_12 += 2 ;
V_10 [ V_12 ++ ] = ( ( V_30 -> V_46 >> 8 ) & 0xff ) ;
V_10 [ V_12 ++ ] = ( V_30 -> V_46 & 0xff ) ;
V_11 += 4 ;
}
F_6 ( & V_32 -> V_44 ) ;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_14 ( V_11 , & V_10 [ 0 ] ) ;
if ( V_35 != 0 ) {
V_10 [ 4 ] = 0x10 ;
V_30 = V_2 -> V_47 -> V_48 ;
V_34 = V_30 -> V_49 ;
if ( V_34 ) {
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 )
V_10 [ 5 ] = V_32 -> V_51 ;
F_6 ( & V_34 -> V_50 ) ;
}
}
F_7 ( V_2 ) ;
F_11 ( V_2 , V_28 ) ;
return 0 ;
}
T_1
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 , * V_52 = V_2 -> V_47 -> V_48 ;
struct V_53 * V_54 = V_2 -> V_55 -> V_53 ;
struct V_31 * V_32 = NULL , * V_56 ;
struct V_33 * V_34 , * V_57 ;
unsigned char * V_10 ;
unsigned char * V_58 ;
T_1 V_59 = V_60 ;
T_2 V_61 = 4 ;
int V_62 , V_63 = 0 , V_64 ;
T_3 V_65 , V_66 ;
if ( ! V_52 )
return V_15 ;
if ( V_2 -> V_13 < 4 ) {
F_2 ( L_7
L_2 , V_2 -> V_13 ) ;
return V_67 ;
}
V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return V_15 ;
V_57 = V_52 -> V_49 ;
if ( ! V_57 ) {
F_16 ( L_8 ) ;
V_59 = V_19 ;
goto V_68;
}
F_4 ( & V_57 -> V_50 ) ;
V_56 = V_57 -> V_32 ;
if ( ! V_56 ) {
F_6 ( & V_57 -> V_50 ) ;
F_16 ( L_9 ) ;
V_59 = V_19 ;
goto V_68;
}
F_6 ( & V_57 -> V_50 ) ;
if ( ! ( V_56 -> V_69 & V_70 ) ) {
F_17 ( L_10
L_11 ) ;
V_59 = V_19 ;
goto V_68;
}
V_64 = V_56 -> V_41 ;
V_58 = & V_10 [ 4 ] ;
while ( V_61 < V_2 -> V_13 ) {
bool V_71 = false ;
V_62 = ( V_58 [ 0 ] & 0x0f ) ;
V_59 = F_18 ( V_62 ,
V_64 , & V_63 ) ;
if ( V_59 ) {
goto V_68;
}
if ( V_63 ) {
V_65 = F_19 ( V_58 + 2 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
if ( V_65 != V_32 -> V_42 )
continue;
F_20 ( & V_32 -> V_73 ) ;
F_21 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
if ( ! F_22 ( V_32 ,
V_4 , V_52 , V_54 ,
V_62 , 1 ) )
V_71 = true ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_24 () ;
break;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
} else {
V_66 = F_19 ( V_58 + 2 ) ;
F_4 ( & V_4 -> V_74 ) ;
F_8 (port, &dev->dev_sep_list,
sep_list) {
if ( V_30 -> V_46 != V_66 )
continue;
V_34 = V_30 -> V_49 ;
F_6 ( & V_4 -> V_74 ) ;
if ( ! F_25 (
V_34 , V_30 , 1 , 1 ) )
V_71 = true ;
F_4 ( & V_4 -> V_74 ) ;
break;
}
F_6 ( & V_4 -> V_74 ) ;
}
if ( ! V_71 ) {
V_59 = V_67 ;
goto V_68;
}
V_58 += 4 ;
V_61 += 4 ;
}
V_68:
F_7 ( V_2 ) ;
if ( ! V_59 )
F_11 ( V_2 , V_28 ) ;
return V_59 ;
}
static inline void F_26 ( struct V_1 * V_2 , T_4 V_75 )
{
F_17 ( L_12
L_13
L_14 ,
V_2 -> V_76 -> V_77 () , V_75 ) ;
V_2 -> V_78 = 0x04 ;
V_2 -> V_79 = V_75 ;
}
static inline void F_27 (
struct V_1 * V_2 ,
unsigned char * V_80 ,
int V_81 )
{
V_2 -> V_82 |= V_83 ;
V_2 -> V_84 = V_81 ;
}
static inline int F_28 (
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_85 , V_86 , V_87 , V_88 ;
if ( ! ( V_2 -> V_82 & V_89 ) )
return 0 ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_85 = V_4 -> V_16 . V_90 ;
V_86 = V_4 -> V_16 . V_91 ;
V_87 = V_2 -> V_13 / V_4 -> V_92 . V_93 ;
V_88 = V_2 -> V_94 ;
while ( V_88 < V_2 -> V_94 + V_87 ) {
struct V_6 * V_95 = NULL , * V_7 ;
struct V_8 * V_9 ;
F_8 (map, &dev->t10_alua.lba_map_list,
lba_map_list) {
T_5 V_96 , V_97 ;
T_5 V_98 = V_7 -> V_22 ;
if ( V_86 ) {
T_5 V_99 = V_88 ;
V_96 = F_29 ( V_99 , V_85 * V_86 ) ;
V_97 = V_98 + V_85 - 1 ;
if ( V_96 >= V_98 &&
V_96 <= V_97 ) {
V_88 += V_85 ;
V_95 = V_7 ;
break;
}
} else {
V_97 = V_7 -> V_23 ;
if ( V_88 >= V_98 && V_88 <= V_97 ) {
V_88 = V_97 + 1 ;
V_95 = V_7 ;
break;
}
}
}
if ( ! V_95 ) {
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_26 ( V_2 , V_100 ) ;
return 1 ;
}
F_8 (map_mem, &cur_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_9 -> V_27 !=
V_32 -> V_42 )
continue;
switch( V_9 -> V_25 ) {
case V_101 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_26 ( V_2 , V_102 ) ;
return 1 ;
case V_103 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_26 ( V_2 , V_100 ) ;
return 1 ;
default:
break;
}
}
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
return 0 ;
}
static inline int F_30 (
struct V_1 * V_2 ,
unsigned char * V_80 )
{
switch ( V_80 [ 0 ] ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
return 0 ;
case V_113 :
switch ( V_80 [ 1 ] & 0x1f ) {
case V_114 :
return 0 ;
default:
F_26 ( V_2 , V_102 ) ;
return 1 ;
}
case V_115 :
switch ( V_80 [ 1 ] & 0x1f ) {
case V_116 :
return 0 ;
default:
F_26 ( V_2 , V_102 ) ;
return 1 ;
}
case V_117 :
switch ( V_80 [ 1 ] ) {
case V_118 :
return 0 ;
default:
F_26 ( V_2 , V_102 ) ;
return 1 ;
}
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
return 0 ;
default:
F_26 ( V_2 , V_102 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_31 (
struct V_1 * V_2 ,
unsigned char * V_80 )
{
switch ( V_80 [ 0 ] ) {
case V_104 :
case V_109 :
return 0 ;
case V_115 :
switch ( V_80 [ 1 ] & 0x1f ) {
case V_116 :
return 0 ;
default:
F_26 ( V_2 , V_100 ) ;
return 1 ;
}
case V_117 :
switch ( V_80 [ 1 ] ) {
case V_118 :
return 0 ;
default:
F_26 ( V_2 , V_100 ) ;
return 1 ;
}
case V_119 :
case V_122 :
case V_123 :
return 0 ;
default:
F_26 ( V_2 , V_100 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_32 (
struct V_1 * V_2 ,
unsigned char * V_80 )
{
switch ( V_80 [ 0 ] ) {
case V_104 :
case V_109 :
return 0 ;
case V_115 :
switch ( V_80 [ 1 ] & 0x1f ) {
case V_116 :
return 0 ;
default:
F_26 ( V_2 , V_124 ) ;
return 1 ;
}
case V_119 :
case V_122 :
case V_123 :
return 0 ;
default:
F_26 ( V_2 , V_124 ) ;
return 1 ;
}
return 0 ;
}
T_1
F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_80 = V_2 -> V_36 ;
struct V_47 * V_125 = V_2 -> V_47 ;
struct V_29 * V_30 = V_125 -> V_48 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_126 , V_81 ;
if ( V_4 -> V_127 -> V_128 & V_129 )
return 0 ;
if ( V_4 -> V_130 -> V_131 == V_132 )
return 0 ;
if ( ! V_30 )
return 0 ;
if ( F_13 ( & V_30 -> V_133 ) ) {
F_17 ( L_15
L_16 ) ;
F_26 ( V_2 , V_134 ) ;
return V_135 ;
}
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return 0 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
V_126 = F_13 ( & V_32 -> V_40 ) ;
V_81 = V_32 -> V_136 ;
F_6 ( & V_34 -> V_50 ) ;
if ( V_126 == V_137 )
return 0 ;
switch ( V_126 ) {
case V_138 :
F_27 ( V_2 , V_80 , V_81 ) ;
break;
case V_101 :
if ( F_30 ( V_2 , V_80 ) )
return V_135 ;
break;
case V_103 :
if ( F_31 ( V_2 , V_80 ) )
return V_135 ;
break;
case V_139 :
if ( F_32 ( V_2 , V_80 ) )
return V_135 ;
break;
case V_140 :
if ( F_28 ( V_2 , V_32 ) )
return V_135 ;
break;
case V_141 :
default:
F_16 ( L_17 ,
V_126 ) ;
return V_14 ;
}
return 0 ;
}
static T_1
F_18 ( int V_142 , int V_143 , int * V_63 )
{
switch ( V_142 ) {
case V_137 :
if ( ! ( V_143 & V_144 ) )
goto V_145;
* V_63 = 1 ;
break;
case V_138 :
if ( ! ( V_143 & V_146 ) )
goto V_145;
* V_63 = 1 ;
break;
case V_101 :
if ( ! ( V_143 & V_147 ) )
goto V_145;
* V_63 = 1 ;
break;
case V_103 :
if ( ! ( V_143 & V_148 ) )
goto V_145;
* V_63 = 1 ;
break;
case V_140 :
if ( ! ( V_143 & V_149 ) )
goto V_145;
* V_63 = 1 ;
break;
case V_141 :
if ( ! ( V_143 & V_150 ) )
goto V_145;
* V_63 = 0 ;
break;
case V_139 :
goto V_145;
default:
F_16 ( L_17 , V_142 ) ;
return V_67 ;
}
return 0 ;
V_145:
F_16 ( L_18 ,
F_34 ( V_142 ) ) ;
return V_67 ;
}
static char * F_34 ( int V_142 )
{
switch ( V_142 ) {
case V_137 :
return L_19 ;
case V_138 :
return L_20 ;
case V_140 :
return L_21 ;
case V_101 :
return L_22 ;
case V_103 :
return L_23 ;
case V_141 :
return L_24 ;
case V_139 :
return L_25 ;
default:
return L_26 ;
}
return NULL ;
}
char * F_35 ( int V_151 )
{
switch ( V_151 ) {
case V_152 :
return L_27 ;
case V_153 :
return L_28 ;
case V_154 :
return L_29 ;
default:
return L_26 ;
}
return NULL ;
}
int F_36 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_82 & V_83 ) )
return 0 ;
if ( F_37 () )
return 0 ;
if ( ! V_2 -> V_84 )
return 0 ;
F_38 ( V_2 -> V_84 ) ;
return 0 ;
}
static int F_39 (
const char * V_155 ,
unsigned char * V_156 ,
T_2 V_157 )
{
struct V_158 * V_158 = F_40 ( V_155 , V_159 | V_160 | V_161 , 0600 ) ;
int V_162 ;
if ( F_41 ( V_158 ) ) {
F_16 ( L_30 , V_155 ) ;
return - V_163 ;
}
V_162 = F_42 ( V_158 , V_156 , V_157 , 0 ) ;
if ( V_162 < 0 )
F_16 ( L_31 , V_155 ) ;
F_43 ( V_158 ) ;
return ( V_162 < 0 ) ? - V_164 : 0 ;
}
static int F_44 (
struct V_31 * V_32 )
{
unsigned char * V_156 ;
struct V_165 * V_166 = & V_32 -> V_167 -> V_165 ;
char V_155 [ V_168 ] ;
int V_61 , V_59 ;
V_156 = F_45 ( V_169 , V_170 ) ;
if ( ! V_156 ) {
F_16 ( L_32 ) ;
return - V_171 ;
}
memset ( V_155 , 0 , V_168 ) ;
V_61 = snprintf ( V_156 , V_169 ,
L_33
L_34
L_35 ,
V_32 -> V_42 ,
V_32 -> V_172 ,
V_32 -> V_43 ) ;
snprintf ( V_155 , V_168 ,
L_36 , & V_166 -> V_173 [ 0 ] ,
F_46 ( & V_32 -> V_174 . V_175 ) ) ;
V_59 = F_39 ( V_155 , V_156 , V_61 ) ;
F_47 ( V_156 ) ;
return V_59 ;
}
static void F_48 ( struct V_176 * V_177 )
{
struct V_31 * V_32 = F_49 ( V_177 ,
struct V_31 , V_178 . V_177 ) ;
struct V_3 * V_4 = V_32 -> V_167 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_29 * V_30 ;
struct V_33 * V_183 ;
bool V_184 = ( V_32 -> V_43 ==
V_153 ) ;
F_4 ( & V_32 -> V_44 ) ;
F_8 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_30 = V_183 -> V_45 ;
F_20 ( & V_183 -> V_185 ) ;
F_21 () ;
F_6 ( & V_32 -> V_44 ) ;
F_50 ( & V_30 -> V_186 ) ;
F_8 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_182 = V_180 -> V_181 ;
if ( ! V_182 )
continue;
if ( ( V_32 -> V_43 ==
V_153 ) &&
( V_32 -> V_187 != NULL ) &&
( V_32 -> V_187 == V_182 -> V_188 ) &&
( V_32 -> V_189 != NULL ) &&
( V_32 -> V_189 == V_30 ) )
continue;
F_51 ( V_182 -> V_188 ,
V_180 -> V_190 , 0x2A ,
V_191 ) ;
}
F_52 ( & V_30 -> V_186 ) ;
F_4 ( & V_32 -> V_44 ) ;
F_23 ( & V_183 -> V_185 ) ;
F_24 () ;
}
F_6 ( & V_32 -> V_44 ) ;
if ( V_32 -> V_192 ) {
F_53 ( & V_32 -> V_193 ) ;
F_44 ( V_32 ) ;
F_54 ( & V_32 -> V_193 ) ;
}
F_55 ( & V_32 -> V_40 ,
V_32 -> V_172 ) ;
F_17 ( L_37
L_38 , ( V_184 ) ? L_39 :
L_40 , F_46 ( & V_32 -> V_174 . V_175 ) ,
V_32 -> V_42 ,
F_34 ( V_32 -> V_194 ) ,
F_34 ( V_32 -> V_172 ) ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_24 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
if ( V_32 -> V_195 )
F_56 ( V_32 -> V_195 ) ;
}
static int F_57 (
struct V_31 * V_32 ,
int V_196 ,
int V_184 )
{
struct V_3 * V_4 = V_32 -> V_167 ;
F_58 ( V_197 ) ;
if ( F_13 ( & V_32 -> V_40 ) == V_196 )
return 0 ;
if ( V_196 == V_139 )
return - V_198 ;
if ( ! V_184 && V_32 -> V_51 &&
F_13 ( & V_32 -> V_40 ) ==
V_139 ) {
V_32 -> V_172 = V_196 ;
V_32 -> V_195 = & V_197 ;
F_59 ( & V_32 -> V_178 ) ;
F_60 ( & V_197 ) ;
V_32 -> V_195 = NULL ;
return 0 ;
}
V_32 -> V_194 =
F_13 ( & V_32 -> V_40 ) ;
V_32 -> V_172 = V_196 ;
F_55 ( & V_32 -> V_40 ,
V_139 ) ;
V_32 -> V_43 = ( V_184 ) ?
V_153 :
V_154 ;
if ( V_32 -> V_199 != 0 )
F_38 ( V_32 -> V_199 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_20 ( & V_32 -> V_73 ) ;
F_21 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
if ( ! V_184 && V_32 -> V_51 ) {
unsigned long V_200 ;
V_200 = V_32 -> V_51 * V_201 ;
F_61 ( V_32 -> V_167 -> V_202 ,
& V_32 -> V_178 ,
V_200 ) ;
} else {
V_32 -> V_195 = & V_197 ;
F_61 ( V_32 -> V_167 -> V_202 ,
& V_32 -> V_178 , 0 ) ;
F_60 ( & V_197 ) ;
V_32 -> V_195 = NULL ;
}
return 0 ;
}
int F_22 (
struct V_31 * V_56 ,
struct V_3 * V_203 ,
struct V_29 * V_52 ,
struct V_53 * V_204 ,
int V_196 ,
int V_184 )
{
struct V_3 * V_4 ;
struct V_205 * V_206 ;
struct V_207 * V_208 , * V_209 ;
struct V_31 * V_32 ;
int V_63 , V_64 , V_59 = 0 ;
V_64 = V_56 -> V_41 ;
if ( F_18 ( V_196 , V_64 , & V_63 ) != 0 )
return - V_210 ;
V_209 = V_203 -> V_211 ;
F_4 ( & V_209 -> V_212 ) ;
V_206 = V_209 -> V_206 ;
F_20 ( & V_206 -> V_213 ) ;
F_21 () ;
F_6 ( & V_209 -> V_212 ) ;
if ( ! V_206 -> V_214 ) {
V_56 -> V_189 = V_52 ;
V_56 -> V_187 = V_204 ;
V_59 = F_57 ( V_56 ,
V_196 , V_184 ) ;
F_23 ( & V_206 -> V_213 ) ;
F_24 () ;
return V_59 ;
}
F_4 ( & V_206 -> V_215 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_208 -> V_216 ;
F_20 ( & V_208 -> V_217 ) ;
F_21 () ;
F_6 ( & V_206 -> V_215 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
if ( V_56 -> V_42 != V_32 -> V_42 )
continue;
if ( V_56 == V_32 ) {
V_32 -> V_189 = V_52 ;
V_32 -> V_187 = V_204 ;
} else {
V_32 -> V_189 = NULL ;
V_32 -> V_187 = NULL ;
}
F_20 ( & V_32 -> V_73 ) ;
F_21 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
V_59 = F_57 ( V_32 ,
V_196 , V_184 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_24 () ;
if ( V_59 )
break;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_4 ( & V_206 -> V_215 ) ;
F_23 ( & V_208 -> V_217 ) ;
F_24 () ;
}
F_6 ( & V_206 -> V_215 ) ;
if ( ! V_59 ) {
F_17 ( L_41
L_42 ,
F_46 ( & V_206 -> V_218 . V_175 ) ,
V_56 -> V_42 ,
( V_184 ) ? L_39 : L_40 ,
F_34 ( V_196 ) ) ;
}
F_23 ( & V_206 -> V_213 ) ;
F_24 () ;
return V_59 ;
}
static int F_62 (
struct V_33 * V_34 ,
struct V_29 * V_30 )
{
unsigned char * V_156 ;
struct V_219 * V_220 = V_30 -> V_221 ;
char V_155 [ V_168 ] , V_166 [ V_222 ] ;
int V_61 , V_59 ;
V_156 = F_45 ( V_169 , V_170 ) ;
if ( ! V_156 ) {
F_16 ( L_32 ) ;
return - V_171 ;
}
memset ( V_155 , 0 , V_168 ) ;
memset ( V_166 , 0 , V_222 ) ;
V_61 = snprintf ( V_166 , V_222 , L_43 ,
V_220 -> V_223 -> V_224 ( V_220 ) ) ;
if ( V_220 -> V_223 -> V_225 != NULL )
snprintf ( V_166 + V_61 , V_222 - V_61 , L_44 ,
V_220 -> V_223 -> V_225 ( V_220 ) ) ;
V_61 = snprintf ( V_156 , V_169 , L_45
L_46 ,
F_13 ( & V_30 -> V_133 ) ,
V_30 -> V_226 ) ;
snprintf ( V_155 , V_168 , L_47 ,
V_220 -> V_223 -> V_77 () , V_166 ,
V_30 -> V_227 -> V_228 ) ;
V_59 = F_39 ( V_155 , V_156 , V_61 ) ;
F_47 ( V_156 ) ;
return V_59 ;
}
static int F_25 (
struct V_33 * V_34 ,
struct V_29 * V_30 ,
int V_184 ,
int V_229 )
{
struct V_31 * V_32 ;
int V_230 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( ! V_32 ) {
F_6 ( & V_34 -> V_50 ) ;
F_16 ( L_48
L_49 ) ;
return - V_210 ;
}
V_230 = V_32 -> V_199 ;
if ( V_229 )
F_55 ( & V_30 -> V_133 , 1 ) ;
else
F_55 ( & V_30 -> V_133 , 0 ) ;
V_30 -> V_226 = ( V_184 ) ?
V_153 :
V_154 ;
F_17 ( L_37
L_50 , ( V_184 ) ? L_39 :
L_40 , F_46 ( & V_32 -> V_174 . V_175 ) ,
V_32 -> V_42 , ( V_229 ) ? L_51 : L_52 ) ;
F_6 ( & V_34 -> V_50 ) ;
if ( V_230 != 0 )
F_38 ( V_230 ) ;
if ( V_30 -> V_231 ) {
F_53 ( & V_30 -> V_232 ) ;
F_62 ( V_34 , V_30 ) ;
F_54 ( & V_30 -> V_232 ) ;
}
return 0 ;
}
struct V_6 *
F_63 ( struct V_233 * V_234 ,
T_5 V_98 , T_5 V_97 )
{
struct V_6 * V_235 ;
V_235 = F_64 ( V_236 , V_170 ) ;
if ( ! V_235 ) {
F_16 ( L_53 ) ;
return F_65 ( - V_171 ) ;
}
F_66 ( & V_235 -> V_237 ) ;
V_235 -> V_22 = V_98 ;
V_235 -> V_23 = V_97 ;
F_67 ( & V_235 -> V_18 , V_234 ) ;
return V_235 ;
}
int
F_68 ( struct V_6 * V_235 ,
int V_238 , int V_142 )
{
struct V_8 * V_239 ;
F_8 (lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_239 -> V_27 == V_238 ) {
F_16 ( L_54 , V_238 ) ;
return - V_210 ;
}
}
V_239 = F_64 ( V_240 , V_170 ) ;
if ( ! V_239 ) {
F_16 ( L_55 ) ;
return - V_171 ;
}
V_239 -> V_25 = V_142 ;
V_239 -> V_27 = V_238 ;
F_67 ( & V_239 -> V_237 ,
& V_235 -> V_237 ) ;
return 0 ;
}
void
F_69 ( struct V_233 * V_241 )
{
struct V_6 * V_235 , * V_242 ;
struct V_8 * V_239 , * V_243 ;
F_70 (lba_map, lba_map_tmp, lba_list,
lba_map_list) {
F_70 (lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
F_71 ( & V_239 -> V_237 ) ;
F_72 ( V_240 ,
V_239 ) ;
}
F_71 ( & V_235 -> V_18 ) ;
F_72 ( V_236 , V_235 ) ;
}
}
void
F_73 ( struct V_3 * V_4 , struct V_233 * V_18 ,
int V_85 , int V_86 )
{
struct V_233 V_244 ;
struct V_31 * V_32 ;
int V_245 = 0 , V_246 ;
F_66 ( & V_244 ) ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_90 = V_85 ;
V_4 -> V_16 . V_91 = V_86 ;
F_74 ( & V_4 -> V_16 . V_18 , & V_244 ) ;
if ( V_18 ) {
F_74 ( V_18 , & V_4 -> V_16 . V_18 ) ;
V_245 = 1 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
V_246 = V_32 -> V_41 ;
if ( V_245 )
V_246 |= V_149 ;
else
V_246 &= ~ V_149 ;
V_32 -> V_41 = V_246 ;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_69 ( & V_244 ) ;
}
struct V_205 *
F_75 ( const char * V_247 , int V_248 )
{
struct V_205 * V_206 ;
V_206 = F_64 ( V_249 , V_170 ) ;
if ( ! V_206 ) {
F_16 ( L_56 ) ;
return F_65 ( - V_171 ) ;
}
F_66 ( & V_206 -> V_250 ) ;
F_66 ( & V_206 -> V_251 ) ;
F_76 ( & V_206 -> V_215 ) ;
F_55 ( & V_206 -> V_213 , 0 ) ;
if ( V_248 ) {
V_206 -> V_214 = V_252 ++ ;
V_206 -> V_253 = 1 ;
V_254 ++ ;
}
return V_206 ;
}
int F_77 ( struct V_205 * V_206 , T_3 V_214 )
{
struct V_205 * V_255 ;
T_3 V_256 ;
if ( V_206 -> V_253 ) {
F_2 ( L_57
L_58 ) ;
return - V_210 ;
}
F_4 ( & V_257 ) ;
if ( V_254 == 0x0000ffff ) {
F_16 ( L_59
L_60 ) ;
F_6 ( & V_257 ) ;
F_72 ( V_249 , V_206 ) ;
return - V_258 ;
}
V_259:
V_256 = ( V_214 != 0 ) ? V_214 :
V_252 ++ ;
F_8 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_255 -> V_214 == V_256 ) {
if ( ! V_214 )
goto V_259;
F_2 ( L_61
L_62 ,
V_214 ) ;
F_6 ( & V_257 ) ;
return - V_210 ;
}
}
V_206 -> V_214 = V_256 ;
V_206 -> V_253 = 1 ;
F_67 ( & V_206 -> V_250 , & V_260 ) ;
V_254 ++ ;
F_6 ( & V_257 ) ;
return 0 ;
}
static struct V_207 *
F_78 ( struct V_3 * V_4 )
{
struct V_207 * V_208 ;
V_208 = F_64 ( V_261 , V_170 ) ;
if ( ! V_208 ) {
F_16 ( L_63 ) ;
return F_65 ( - V_171 ) ;
}
F_66 ( & V_208 -> V_251 ) ;
F_76 ( & V_208 -> V_212 ) ;
F_55 ( & V_208 -> V_217 , 0 ) ;
V_208 -> V_216 = V_4 ;
V_4 -> V_211 = V_208 ;
return V_208 ;
}
void F_79 ( struct V_205 * V_206 )
{
struct V_207 * V_208 , * V_262 ;
F_4 ( & V_257 ) ;
F_71 ( & V_206 -> V_250 ) ;
V_254 -- ;
F_6 ( & V_257 ) ;
while ( F_13 ( & V_206 -> V_213 ) )
F_80 () ;
F_4 ( & V_206 -> V_215 ) ;
F_70 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_208 -> V_263 ) {
F_71 ( & V_208 -> V_251 ) ;
V_206 -> V_264 -- ;
V_208 -> V_263 = 0 ;
}
F_6 ( & V_206 -> V_215 ) ;
F_4 ( & V_208 -> V_212 ) ;
if ( V_206 != V_265 )
F_81 ( V_208 ,
V_265 ) ;
else
V_208 -> V_206 = NULL ;
F_6 ( & V_208 -> V_212 ) ;
F_4 ( & V_206 -> V_215 ) ;
}
F_6 ( & V_206 -> V_215 ) ;
F_72 ( V_249 , V_206 ) ;
}
void F_82 ( struct V_3 * V_4 )
{
struct V_205 * V_206 ;
struct V_207 * V_208 ;
V_208 = V_4 -> V_211 ;
if ( ! V_208 )
return;
while ( F_13 ( & V_208 -> V_217 ) )
F_80 () ;
F_4 ( & V_208 -> V_212 ) ;
V_206 = V_208 -> V_206 ;
if ( V_206 ) {
F_4 ( & V_206 -> V_215 ) ;
if ( V_208 -> V_263 ) {
F_71 ( & V_208 -> V_251 ) ;
V_206 -> V_264 -- ;
V_208 -> V_263 = 0 ;
}
F_6 ( & V_206 -> V_215 ) ;
V_208 -> V_206 = NULL ;
}
F_6 ( & V_208 -> V_212 ) ;
F_72 ( V_261 , V_208 ) ;
}
struct V_205 * F_83 ( const char * V_247 )
{
struct V_205 * V_206 ;
struct V_266 * V_267 ;
F_4 ( & V_257 ) ;
F_8 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_206 -> V_253 )
continue;
V_267 = & V_206 -> V_218 . V_175 ;
if ( ! strcmp ( F_46 ( V_267 ) , V_247 ) ) {
F_20 ( & V_206 -> V_213 ) ;
F_6 ( & V_257 ) ;
return V_206 ;
}
}
F_6 ( & V_257 ) ;
return NULL ;
}
void F_84 ( struct V_205 * V_206 )
{
F_4 ( & V_257 ) ;
F_23 ( & V_206 -> V_213 ) ;
F_6 ( & V_257 ) ;
}
void F_81 (
struct V_207 * V_208 ,
struct V_205 * V_206 )
{
F_4 ( & V_206 -> V_215 ) ;
V_208 -> V_206 = V_206 ;
V_208 -> V_263 = 1 ;
F_67 ( & V_208 -> V_251 , & V_206 -> V_251 ) ;
V_206 -> V_264 ++ ;
F_6 ( & V_206 -> V_215 ) ;
}
void F_85 (
struct V_207 * V_208 ,
struct V_205 * V_206 )
{
F_4 ( & V_206 -> V_215 ) ;
F_71 ( & V_208 -> V_251 ) ;
V_208 -> V_206 = NULL ;
V_208 -> V_263 = 0 ;
V_206 -> V_264 -- ;
F_6 ( & V_206 -> V_215 ) ;
}
struct V_31 * F_86 ( struct V_3 * V_4 ,
const char * V_247 , int V_248 )
{
struct V_31 * V_32 ;
V_32 = F_64 ( V_268 , V_170 ) ;
if ( ! V_32 ) {
F_16 ( L_64 ) ;
return NULL ;
}
F_66 ( & V_32 -> V_269 ) ;
F_66 ( & V_32 -> V_270 ) ;
F_87 ( & V_32 -> V_193 ) ;
F_76 ( & V_32 -> V_44 ) ;
F_55 ( & V_32 -> V_73 , 0 ) ;
F_88 ( & V_32 -> V_178 ,
F_48 ) ;
V_32 -> V_167 = V_4 ;
F_55 ( & V_32 -> V_40 ,
V_137 ) ;
V_32 -> V_69 =
V_70 | V_271 ;
V_32 -> V_136 = V_272 ;
V_32 -> V_199 = V_273 ;
V_32 -> V_51 = V_274 ;
V_32 -> V_41 =
V_275 | V_150 |
V_148 | V_147 | V_146 | V_144 ;
if ( V_248 ) {
F_4 ( & V_4 -> V_16 . V_37 ) ;
V_32 -> V_42 =
V_4 -> V_16 . V_276 ++ ;
V_32 -> V_72 = 1 ;
V_4 -> V_16 . V_277 ++ ;
F_67 ( & V_32 -> V_269 ,
& V_4 -> V_16 . V_278 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
}
return V_32 ;
}
int F_89 (
struct V_31 * V_32 ,
T_3 V_42 )
{
struct V_3 * V_4 = V_32 -> V_167 ;
struct V_31 * V_279 ;
T_3 V_280 ;
if ( V_32 -> V_72 ) {
F_2 ( L_65
L_58 ) ;
return - V_210 ;
}
F_4 ( & V_4 -> V_16 . V_37 ) ;
if ( V_4 -> V_16 . V_277 == 0x0000ffff ) {
F_16 ( L_66
L_60 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_72 ( V_268 , V_32 ) ;
return - V_258 ;
}
V_259:
V_280 = ( V_42 != 0 ) ? V_42 :
V_4 -> V_16 . V_276 ++ ;
F_8 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_279 -> V_42 == V_280 ) {
if ( ! V_42 )
goto V_259;
F_16 ( L_67
L_68 , V_42 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return - V_210 ;
}
}
V_32 -> V_42 = V_280 ;
V_32 -> V_72 = 1 ;
F_67 ( & V_32 -> V_269 ,
& V_4 -> V_16 . V_278 ) ;
V_4 -> V_16 . V_277 ++ ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return 0 ;
}
struct V_33 * F_90 (
struct V_29 * V_30 )
{
struct V_33 * V_34 ;
V_34 = F_64 ( V_281 ,
V_170 ) ;
if ( ! V_34 ) {
F_16 ( L_69 ) ;
return F_65 ( - V_171 ) ;
}
F_66 ( & V_34 -> V_270 ) ;
F_76 ( & V_34 -> V_50 ) ;
F_55 ( & V_34 -> V_185 , 0 ) ;
V_34 -> V_45 = V_30 ;
V_30 -> V_49 = V_34 ;
return V_34 ;
}
void F_91 (
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_167 ;
struct V_33 * V_34 , * V_282 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_71 ( & V_32 -> V_269 ) ;
V_4 -> V_16 . V_276 -- ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_59 ( & V_32 -> V_178 ) ;
while ( F_13 ( & V_32 -> V_73 ) )
F_80 () ;
F_4 ( & V_32 -> V_44 ) ;
F_70 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_34 -> V_283 ) {
F_71 ( & V_34 -> V_270 ) ;
V_32 -> V_38 -- ;
V_34 -> V_283 = 0 ;
}
F_6 ( & V_32 -> V_44 ) ;
F_4 ( & V_34 -> V_50 ) ;
if ( V_32 != V_4 -> V_16 . V_284 ) {
F_92 ( V_34 ,
V_4 -> V_16 . V_284 ) ;
} else
V_34 -> V_32 = NULL ;
F_6 ( & V_34 -> V_50 ) ;
F_4 ( & V_32 -> V_44 ) ;
}
F_6 ( & V_32 -> V_44 ) ;
F_72 ( V_268 , V_32 ) ;
}
void F_93 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return;
while ( F_13 ( & V_34 -> V_185 ) )
F_80 () ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
F_4 ( & V_32 -> V_44 ) ;
if ( V_34 -> V_283 ) {
F_71 ( & V_34 -> V_270 ) ;
V_32 -> V_38 -- ;
V_34 -> V_283 = 0 ;
}
F_6 ( & V_32 -> V_44 ) ;
V_34 -> V_32 = NULL ;
}
F_6 ( & V_34 -> V_50 ) ;
F_72 ( V_281 , V_34 ) ;
}
static struct V_31 * F_94 (
struct V_3 * V_4 , const char * V_247 )
{
struct V_31 * V_32 ;
struct V_266 * V_267 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
V_267 = & V_32 -> V_174 . V_175 ;
if ( ! strcmp ( F_46 ( V_267 ) , V_247 ) ) {
F_20 ( & V_32 -> V_73 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return V_32 ;
}
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
return NULL ;
}
static void F_95 (
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_167 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
}
void F_92 (
struct V_33 * V_34 ,
struct V_31 * V_32 )
{
F_4 ( & V_32 -> V_44 ) ;
V_34 -> V_32 = V_32 ;
V_34 -> V_283 = 1 ;
F_67 ( & V_34 -> V_270 ,
& V_32 -> V_270 ) ;
V_32 -> V_38 ++ ;
F_6 ( & V_32 -> V_44 ) ;
}
static void F_96 (
struct V_33 * V_34 ,
struct V_31 * V_32 )
{
F_4 ( & V_32 -> V_44 ) ;
F_71 ( & V_34 -> V_270 ) ;
V_34 -> V_32 = NULL ;
V_34 -> V_283 = 0 ;
V_32 -> V_38 -- ;
F_6 ( & V_32 -> V_44 ) ;
}
T_6 F_97 ( struct V_29 * V_30 , char * V_285 )
{
struct V_266 * V_286 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_6 V_61 = 0 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return V_61 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
V_286 = & V_32 -> V_174 . V_175 ;
V_61 += sprintf ( V_285 , L_70
L_71
L_72
L_73 ,
F_46 ( V_286 ) , V_32 -> V_42 ,
F_34 ( F_13 (
& V_32 -> V_40 ) ) ,
F_35 (
V_32 -> V_43 ) ,
( F_13 ( & V_30 -> V_133 ) ) ?
L_24 : L_27 ,
F_35 ( V_30 -> V_226 ) ) ;
}
F_6 ( & V_34 -> V_50 ) ;
return V_61 ;
}
T_6 F_98 (
struct V_29 * V_30 ,
const char * V_285 ,
T_7 V_287 )
{
struct V_219 * V_288 ;
struct V_47 * V_125 ;
struct V_3 * V_4 = V_30 -> V_227 -> V_289 ;
struct V_31 * V_32 = NULL , * V_290 = NULL ;
struct V_33 * V_34 ;
unsigned char V_10 [ V_291 ] ;
int V_292 = 0 ;
V_288 = V_30 -> V_221 ;
V_125 = V_30 -> V_227 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return 0 ;
if ( V_287 > V_291 ) {
F_16 ( L_74 ) ;
return - V_210 ;
}
memset ( V_10 , 0 , V_291 ) ;
memcpy ( V_10 , V_285 , V_287 ) ;
if ( strcmp ( F_99 ( V_10 ) , L_75 ) ) {
V_290 = F_94 ( V_4 ,
F_99 ( V_10 ) ) ;
if ( ! V_290 )
return - V_163 ;
}
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
if ( ! V_290 ) {
F_17 ( L_76
L_77
L_78
L_79 ,
V_288 -> V_223 -> V_224 ( V_288 ) ,
V_288 -> V_223 -> V_225 ( V_288 ) ,
F_46 ( & V_125 -> V_293 . V_175 ) ,
F_46 (
& V_32 -> V_174 . V_175 ) ,
V_32 -> V_42 ) ;
F_96 ( V_34 , V_32 ) ;
F_92 ( V_34 ,
V_4 -> V_16 . V_284 ) ;
F_6 ( & V_34 -> V_50 ) ;
return V_287 ;
}
F_96 ( V_34 , V_32 ) ;
V_292 = 1 ;
}
F_92 ( V_34 , V_290 ) ;
F_6 ( & V_34 -> V_50 ) ;
F_17 ( L_80
L_81 , ( V_292 ) ?
L_82 : L_83 , V_288 -> V_223 -> V_224 ( V_288 ) ,
V_288 -> V_223 -> V_225 ( V_288 ) ,
F_46 ( & V_125 -> V_293 . V_175 ) ,
F_46 ( & V_290 -> V_174 . V_175 ) ,
V_290 -> V_42 ) ;
F_95 ( V_290 ) ;
return V_287 ;
}
T_6 F_100 (
struct V_31 * V_32 ,
char * V_285 )
{
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_69 & V_271 ) )
return sprintf ( V_285 , L_84 ) ;
else if ( V_32 -> V_69 & V_271 )
return sprintf ( V_285 , L_85 ) ;
else if ( V_32 -> V_69 & V_70 )
return sprintf ( V_285 , L_86 ) ;
else
return sprintf ( V_285 , L_87 ) ;
}
T_6 F_101 (
struct V_31 * V_32 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_88 ) ;
return V_162 ;
}
if ( ( V_99 != 0 ) && ( V_99 != 1 ) && ( V_99 != 2 ) && ( V_99 != 3 ) ) {
F_16 ( L_89
L_90 , V_99 ) ;
return - V_210 ;
}
if ( V_99 == 3 )
V_32 -> V_69 =
V_271 | V_70 ;
else if ( V_99 == 2 )
V_32 -> V_69 = V_70 ;
else if ( V_99 == 1 )
V_32 -> V_69 = V_271 ;
else
V_32 -> V_69 = 0 ;
return V_287 ;
}
T_6 F_103 (
struct V_31 * V_32 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 , V_32 -> V_136 ) ;
}
T_6 F_104 (
struct V_31 * V_32 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_92 ) ;
return V_162 ;
}
if ( V_99 > V_294 ) {
F_16 ( L_93
L_94 , V_99 ,
V_294 ) ;
return - V_210 ;
}
V_32 -> V_136 = ( int ) V_99 ;
return V_287 ;
}
T_6 F_105 (
struct V_31 * V_32 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 , V_32 -> V_199 ) ;
}
T_6 F_106 (
struct V_31 * V_32 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_95 ) ;
return V_162 ;
}
if ( V_99 > V_295 ) {
F_16 ( L_96
L_97 , V_99 ,
V_295 ) ;
return - V_210 ;
}
V_32 -> V_199 = ( int ) V_99 ;
return V_287 ;
}
T_6 F_107 (
struct V_31 * V_32 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 , V_32 -> V_51 ) ;
}
T_6 F_108 (
struct V_31 * V_32 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_98 ) ;
return V_162 ;
}
if ( V_99 > V_296 ) {
F_16 ( L_99
L_100 , V_99 ,
V_296 ) ;
return - V_210 ;
}
V_32 -> V_51 = ( int ) V_99 ;
return V_287 ;
}
T_6 F_109 (
struct V_31 * V_32 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 , V_32 -> V_39 ) ;
}
T_6 F_110 (
struct V_31 * V_32 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_101 ) ;
return V_162 ;
}
if ( ( V_99 != 0 ) && ( V_99 != 1 ) ) {
F_16 ( L_102 , V_99 ) ;
return - V_210 ;
}
V_32 -> V_39 = ( int ) V_99 ;
return V_287 ;
}
T_6 F_111 ( struct V_47 * V_125 , char * V_285 )
{
if ( ! V_125 -> V_48 )
return - V_163 ;
return sprintf ( V_285 , L_91 ,
F_13 ( & V_125 -> V_48 -> V_133 ) ) ;
}
T_6 F_112 (
struct V_47 * V_125 ,
const char * V_285 ,
T_7 V_287 )
{
struct V_33 * V_34 ;
unsigned long V_99 ;
int V_162 ;
if ( ! V_125 -> V_48 )
return - V_163 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_103 ) ;
return V_162 ;
}
if ( ( V_99 != 0 ) && ( V_99 != 1 ) ) {
F_16 ( L_104 ,
V_99 ) ;
return - V_210 ;
}
V_34 = V_125 -> V_48 -> V_49 ;
if ( ! V_34 ) {
F_16 ( L_105 ) ;
return - V_210 ;
}
V_162 = F_25 ( V_34 ,
V_125 -> V_48 , 0 , ( int ) V_99 ) ;
if ( V_162 < 0 )
return - V_210 ;
return V_287 ;
}
T_6 F_113 (
struct V_47 * V_125 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 , V_125 -> V_48 -> V_226 ) ;
}
T_6 F_114 (
struct V_47 * V_125 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_106 ) ;
return V_162 ;
}
if ( ( V_99 != V_152 ) &&
( V_99 != V_153 ) &&
( V_99 != V_154 ) ) {
F_16 ( L_107 ,
V_99 ) ;
return - V_210 ;
}
V_125 -> V_48 -> V_226 = ( int ) V_99 ;
return V_287 ;
}
T_6 F_115 (
struct V_47 * V_125 ,
char * V_285 )
{
return sprintf ( V_285 , L_91 ,
V_125 -> V_48 -> V_231 ) ;
}
T_6 F_116 (
struct V_47 * V_125 ,
const char * V_285 ,
T_7 V_287 )
{
unsigned long V_99 ;
int V_162 ;
V_162 = F_102 ( V_285 , 0 , & V_99 ) ;
if ( V_162 < 0 ) {
F_16 ( L_108 ) ;
return V_162 ;
}
if ( ( V_99 != 0 ) && ( V_99 != 1 ) ) {
F_16 ( L_109
L_90 , V_99 ) ;
return - V_210 ;
}
V_125 -> V_48 -> V_231 = ( int ) V_99 ;
return V_287 ;
}
int F_117 ( struct V_3 * V_4 )
{
if ( V_4 -> V_130 -> V_131 != V_132 &&
! ( V_4 -> V_127 -> V_128 & V_129 ) ) {
struct V_207 * V_208 ;
V_208 = F_78 ( V_4 ) ;
if ( F_41 ( V_208 ) )
return F_118 ( V_208 ) ;
F_4 ( & V_208 -> V_212 ) ;
F_81 ( V_208 ,
V_265 ) ;
F_6 ( & V_208 -> V_212 ) ;
F_17 ( L_110
L_111 ,
V_4 -> V_130 -> V_247 ) ;
}
return 0 ;
}
