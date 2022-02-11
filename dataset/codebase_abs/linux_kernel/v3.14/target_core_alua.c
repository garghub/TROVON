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
static inline int F_26 (
struct V_1 * V_2 ,
unsigned char * V_75 ,
int V_76 ,
T_4 * V_77 )
{
V_2 -> V_78 |= V_79 ;
V_2 -> V_80 = V_76 ;
return 0 ;
}
static inline int F_27 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_4 * V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_81 , V_82 , V_83 , V_84 ;
if ( ! ( V_2 -> V_78 & V_85 ) )
return 0 ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_81 = V_4 -> V_16 . V_86 ;
V_82 = V_4 -> V_16 . V_87 ;
V_83 = V_2 -> V_13 / V_4 -> V_88 . V_89 ;
V_84 = V_2 -> V_90 ;
while ( V_84 < V_2 -> V_90 + V_83 ) {
struct V_6 * V_91 = NULL , * V_7 ;
struct V_8 * V_9 ;
F_8 (map, &dev->t10_alua.lba_map_list,
lba_map_list) {
T_5 V_92 , V_93 ;
T_5 V_94 = V_7 -> V_22 ;
if ( V_82 ) {
T_5 V_95 = V_84 ;
V_92 = F_28 ( V_95 , V_81 * V_82 ) ;
V_93 = V_94 + V_81 - 1 ;
if ( V_92 >= V_94 &&
V_92 <= V_93 ) {
V_84 += V_81 ;
V_91 = V_7 ;
break;
}
} else {
V_93 = V_7 -> V_23 ;
if ( V_84 >= V_94 && V_84 <= V_93 ) {
V_84 = V_93 + 1 ;
V_91 = V_7 ;
break;
}
}
}
if ( ! V_91 ) {
F_6 ( & V_4 -> V_16 . V_17 ) ;
* V_77 = V_96 ;
return 1 ;
}
F_8 (map_mem, &cur_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_9 -> V_27 !=
V_32 -> V_42 )
continue;
switch( V_9 -> V_25 ) {
case V_97 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
* V_77 = V_98 ;
return 1 ;
case V_99 :
F_6 ( & V_4 -> V_16 . V_17 ) ;
* V_77 = V_96 ;
return 1 ;
default:
break;
}
}
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
return 0 ;
}
static inline int F_29 (
struct V_1 * V_2 ,
unsigned char * V_75 ,
T_4 * V_77 )
{
switch ( V_75 [ 0 ] ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
return 0 ;
case V_108 :
switch ( V_75 [ 1 ] & 0x1f ) {
case V_109 :
return 0 ;
default:
* V_77 = V_98 ;
return 1 ;
}
case V_110 :
switch ( V_75 [ 1 ] ) {
case V_111 :
return 0 ;
default:
* V_77 = V_98 ;
return 1 ;
}
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
return 0 ;
default:
* V_77 = V_98 ;
return 1 ;
}
return 0 ;
}
static inline int F_30 (
struct V_1 * V_2 ,
unsigned char * V_75 ,
T_4 * V_77 )
{
switch ( V_75 [ 0 ] ) {
case V_100 :
case V_105 :
return 0 ;
case V_108 :
switch ( V_75 [ 1 ] & 0x1f ) {
case V_109 :
return 0 ;
default:
* V_77 = V_96 ;
return 1 ;
}
case V_110 :
switch ( V_75 [ 1 ] ) {
case V_111 :
return 0 ;
default:
* V_77 = V_96 ;
return 1 ;
}
case V_112 :
case V_115 :
case V_116 :
return 0 ;
default:
* V_77 = V_96 ;
return 1 ;
}
return 0 ;
}
static inline int F_31 (
struct V_1 * V_2 ,
unsigned char * V_75 ,
T_4 * V_77 )
{
switch ( V_75 [ 0 ] ) {
case V_100 :
case V_105 :
return 0 ;
case V_108 :
switch ( V_75 [ 1 ] & 0x1f ) {
case V_109 :
return 0 ;
default:
* V_77 = V_117 ;
return 1 ;
}
case V_112 :
case V_115 :
case V_116 :
return 0 ;
default:
* V_77 = V_117 ;
return 1 ;
}
return 0 ;
}
T_1
F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_75 = V_2 -> V_36 ;
struct V_47 * V_118 = V_2 -> V_47 ;
struct V_29 * V_30 = V_118 -> V_48 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_119 , V_76 ;
T_4 V_77 ;
int V_120 ;
if ( V_4 -> V_121 -> V_122 & V_123 )
return 0 ;
if ( V_4 -> V_124 -> V_125 == V_126 )
return 0 ;
if ( ! V_30 )
return 0 ;
if ( F_13 ( & V_30 -> V_127 ) ) {
F_17 ( L_12
L_13 ) ;
V_77 = V_128 ;
V_120 = 1 ;
goto V_68;
}
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return 0 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
V_119 = F_13 ( & V_32 -> V_40 ) ;
V_76 = V_32 -> V_129 ;
F_6 ( & V_34 -> V_50 ) ;
if ( V_119 == V_130 )
return 0 ;
switch ( V_119 ) {
case V_131 :
V_120 = F_26 ( V_2 , V_75 ,
V_76 , & V_77 ) ;
break;
case V_97 :
V_120 = F_29 ( V_2 , V_75 , & V_77 ) ;
break;
case V_99 :
V_120 = F_30 ( V_2 , V_75 , & V_77 ) ;
break;
case V_132 :
V_120 = F_31 ( V_2 , V_75 , & V_77 ) ;
break;
case V_133 :
V_120 = F_27 ( V_2 , V_32 , & V_77 ) ;
break;
case V_134 :
default:
F_16 ( L_14 ,
V_119 ) ;
return V_14 ;
}
V_68:
if ( V_120 > 0 ) {
F_17 ( L_15
L_16
L_17 ,
V_2 -> V_135 -> V_136 () , V_77 ) ;
V_2 -> V_137 = 0x04 ;
V_2 -> V_138 = V_77 ;
return V_139 ;
}
return 0 ;
}
static T_1
F_18 ( int V_140 , int V_141 , int * V_63 )
{
switch ( V_140 ) {
case V_130 :
if ( ! ( V_141 & V_142 ) )
goto V_143;
* V_63 = 1 ;
break;
case V_131 :
if ( ! ( V_141 & V_144 ) )
goto V_143;
* V_63 = 1 ;
break;
case V_97 :
if ( ! ( V_141 & V_145 ) )
goto V_143;
* V_63 = 1 ;
break;
case V_99 :
if ( ! ( V_141 & V_146 ) )
goto V_143;
* V_63 = 1 ;
break;
case V_133 :
if ( ! ( V_141 & V_147 ) )
goto V_143;
* V_63 = 1 ;
break;
case V_134 :
if ( ! ( V_141 & V_148 ) )
goto V_143;
* V_63 = 0 ;
break;
case V_132 :
goto V_143;
default:
F_16 ( L_14 , V_140 ) ;
return V_67 ;
}
return 0 ;
V_143:
F_16 ( L_18 ,
F_33 ( V_140 ) ) ;
return V_67 ;
}
static char * F_33 ( int V_140 )
{
switch ( V_140 ) {
case V_130 :
return L_19 ;
case V_131 :
return L_20 ;
case V_133 :
return L_21 ;
case V_97 :
return L_22 ;
case V_99 :
return L_23 ;
case V_134 :
return L_24 ;
case V_132 :
return L_25 ;
default:
return L_26 ;
}
return NULL ;
}
char * F_34 ( int V_149 )
{
switch ( V_149 ) {
case V_150 :
return L_27 ;
case V_151 :
return L_28 ;
case V_152 :
return L_29 ;
default:
return L_26 ;
}
return NULL ;
}
int F_35 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_78 & V_79 ) )
return 0 ;
if ( F_36 () )
return 0 ;
if ( ! V_2 -> V_80 )
return 0 ;
F_37 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_38 (
const char * V_153 ,
unsigned char * V_154 ,
T_2 V_155 )
{
struct V_156 * V_156 = F_39 ( V_153 , V_157 | V_158 | V_159 , 0600 ) ;
int V_120 ;
if ( F_40 ( V_156 ) ) {
F_16 ( L_30 , V_153 ) ;
return - V_160 ;
}
V_120 = F_41 ( V_156 , V_154 , V_155 , 0 ) ;
if ( V_120 < 0 )
F_16 ( L_31 , V_153 ) ;
F_42 ( V_156 ) ;
return ( V_120 < 0 ) ? - V_161 : 0 ;
}
static int F_43 (
struct V_31 * V_32 )
{
unsigned char * V_154 ;
struct V_162 * V_163 = & V_32 -> V_164 -> V_162 ;
char V_153 [ V_165 ] ;
int V_61 , V_59 ;
V_154 = F_44 ( V_166 , V_167 ) ;
if ( ! V_154 ) {
F_16 ( L_32 ) ;
return - V_168 ;
}
memset ( V_153 , 0 , V_165 ) ;
V_61 = snprintf ( V_154 , V_166 ,
L_33
L_34
L_35 ,
V_32 -> V_42 ,
V_32 -> V_169 ,
V_32 -> V_43 ) ;
snprintf ( V_153 , V_165 ,
L_36 , & V_163 -> V_170 [ 0 ] ,
F_45 ( & V_32 -> V_171 . V_172 ) ) ;
V_59 = F_38 ( V_153 , V_154 , V_61 ) ;
F_46 ( V_154 ) ;
return V_59 ;
}
static void F_47 ( struct V_173 * V_174 )
{
struct V_31 * V_32 = F_48 ( V_174 ,
struct V_31 , V_175 . V_174 ) ;
struct V_3 * V_4 = V_32 -> V_164 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_29 * V_30 ;
struct V_33 * V_180 ;
bool V_181 = ( V_32 -> V_43 ==
V_151 ) ;
F_4 ( & V_32 -> V_44 ) ;
F_8 (mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_30 = V_180 -> V_45 ;
F_20 ( & V_180 -> V_182 ) ;
F_21 () ;
F_6 ( & V_32 -> V_44 ) ;
F_49 ( & V_30 -> V_183 ) ;
F_8 (se_deve, &port->sep_alua_list,
alua_port_list) {
V_179 = V_177 -> V_178 ;
if ( ! V_179 )
continue;
if ( ( V_32 -> V_43 ==
V_151 ) &&
( V_32 -> V_184 != NULL ) &&
( V_32 -> V_184 == V_179 -> V_185 ) &&
( V_32 -> V_186 != NULL ) &&
( V_32 -> V_186 == V_30 ) )
continue;
F_50 ( V_179 -> V_185 ,
V_177 -> V_187 , 0x2A ,
V_188 ) ;
}
F_51 ( & V_30 -> V_183 ) ;
F_4 ( & V_32 -> V_44 ) ;
F_23 ( & V_180 -> V_182 ) ;
F_24 () ;
}
F_6 ( & V_32 -> V_44 ) ;
if ( V_32 -> V_189 ) {
F_52 ( & V_32 -> V_190 ) ;
F_43 ( V_32 ) ;
F_53 ( & V_32 -> V_190 ) ;
}
F_54 ( & V_32 -> V_40 ,
V_32 -> V_169 ) ;
F_17 ( L_37
L_38 , ( V_181 ) ? L_39 :
L_40 , F_45 ( & V_32 -> V_171 . V_172 ) ,
V_32 -> V_42 ,
F_33 ( V_32 -> V_191 ) ,
F_33 ( V_32 -> V_169 ) ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_24 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
if ( V_32 -> V_192 )
F_55 ( V_32 -> V_192 ) ;
}
static int F_56 (
struct V_31 * V_32 ,
int V_193 ,
int V_181 )
{
struct V_3 * V_4 = V_32 -> V_164 ;
F_57 ( V_194 ) ;
if ( F_13 ( & V_32 -> V_40 ) == V_193 )
return 0 ;
if ( V_193 == V_132 )
return - V_195 ;
if ( ! V_181 && V_32 -> V_51 &&
F_13 ( & V_32 -> V_40 ) ==
V_132 ) {
V_32 -> V_169 = V_193 ;
V_32 -> V_192 = & V_194 ;
F_58 ( & V_32 -> V_175 ) ;
F_59 ( & V_194 ) ;
V_32 -> V_192 = NULL ;
return 0 ;
}
V_32 -> V_191 =
F_13 ( & V_32 -> V_40 ) ;
V_32 -> V_169 = V_193 ;
F_54 ( & V_32 -> V_40 ,
V_132 ) ;
V_32 -> V_43 = ( V_181 ) ?
V_151 :
V_152 ;
if ( V_32 -> V_196 != 0 )
F_37 ( V_32 -> V_196 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_20 ( & V_32 -> V_73 ) ;
F_21 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
if ( ! V_181 && V_32 -> V_51 ) {
unsigned long V_197 ;
V_197 = V_32 -> V_51 * V_198 ;
F_60 ( V_32 -> V_164 -> V_199 ,
& V_32 -> V_175 ,
V_197 ) ;
} else {
V_32 -> V_192 = & V_194 ;
F_60 ( V_32 -> V_164 -> V_199 ,
& V_32 -> V_175 , 0 ) ;
F_59 ( & V_194 ) ;
V_32 -> V_192 = NULL ;
}
return 0 ;
}
int F_22 (
struct V_31 * V_56 ,
struct V_3 * V_200 ,
struct V_29 * V_52 ,
struct V_53 * V_201 ,
int V_193 ,
int V_181 )
{
struct V_3 * V_4 ;
struct V_202 * V_203 ;
struct V_204 * V_205 , * V_206 ;
struct V_31 * V_32 ;
int V_63 , V_64 , V_59 = 0 ;
V_64 = V_56 -> V_41 ;
if ( F_18 ( V_193 , V_64 , & V_63 ) != 0 )
return - V_207 ;
V_206 = V_200 -> V_208 ;
F_4 ( & V_206 -> V_209 ) ;
V_203 = V_206 -> V_203 ;
F_20 ( & V_203 -> V_210 ) ;
F_21 () ;
F_6 ( & V_206 -> V_209 ) ;
if ( ! V_203 -> V_211 ) {
V_56 -> V_186 = V_52 ;
V_56 -> V_184 = V_201 ;
V_59 = F_56 ( V_56 ,
V_193 , V_181 ) ;
F_23 ( & V_203 -> V_210 ) ;
F_24 () ;
return V_59 ;
}
F_4 ( & V_203 -> V_212 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
V_4 = V_205 -> V_213 ;
F_20 ( & V_205 -> V_214 ) ;
F_21 () ;
F_6 ( & V_203 -> V_212 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
if ( V_56 -> V_42 != V_32 -> V_42 )
continue;
if ( V_56 == V_32 ) {
V_32 -> V_186 = V_52 ;
V_32 -> V_184 = V_201 ;
} else {
V_32 -> V_186 = NULL ;
V_32 -> V_184 = NULL ;
}
F_20 ( & V_32 -> V_73 ) ;
F_21 () ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
V_59 = F_56 ( V_32 ,
V_193 , V_181 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_24 () ;
if ( V_59 )
break;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_4 ( & V_203 -> V_212 ) ;
F_23 ( & V_205 -> V_214 ) ;
F_24 () ;
}
F_6 ( & V_203 -> V_212 ) ;
if ( ! V_59 ) {
F_17 ( L_41
L_42 ,
F_45 ( & V_203 -> V_215 . V_172 ) ,
V_56 -> V_42 ,
( V_181 ) ? L_39 : L_40 ,
F_33 ( V_193 ) ) ;
}
F_23 ( & V_203 -> V_210 ) ;
F_24 () ;
return V_59 ;
}
static int F_61 (
struct V_33 * V_34 ,
struct V_29 * V_30 )
{
unsigned char * V_154 ;
struct V_216 * V_217 = V_30 -> V_218 ;
char V_153 [ V_165 ] , V_163 [ V_219 ] ;
int V_61 , V_59 ;
V_154 = F_44 ( V_166 , V_167 ) ;
if ( ! V_154 ) {
F_16 ( L_32 ) ;
return - V_168 ;
}
memset ( V_153 , 0 , V_165 ) ;
memset ( V_163 , 0 , V_219 ) ;
V_61 = snprintf ( V_163 , V_219 , L_43 ,
V_217 -> V_220 -> V_221 ( V_217 ) ) ;
if ( V_217 -> V_220 -> V_222 != NULL )
snprintf ( V_163 + V_61 , V_219 - V_61 , L_44 ,
V_217 -> V_220 -> V_222 ( V_217 ) ) ;
V_61 = snprintf ( V_154 , V_166 , L_45
L_46 ,
F_13 ( & V_30 -> V_127 ) ,
V_30 -> V_223 ) ;
snprintf ( V_153 , V_165 , L_47 ,
V_217 -> V_220 -> V_136 () , V_163 ,
V_30 -> V_224 -> V_225 ) ;
V_59 = F_38 ( V_153 , V_154 , V_61 ) ;
F_46 ( V_154 ) ;
return V_59 ;
}
static int F_25 (
struct V_33 * V_34 ,
struct V_29 * V_30 ,
int V_181 ,
int V_226 )
{
struct V_31 * V_32 ;
int V_227 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( ! V_32 ) {
F_6 ( & V_34 -> V_50 ) ;
F_16 ( L_48
L_49 ) ;
return - V_207 ;
}
V_227 = V_32 -> V_196 ;
if ( V_226 )
F_54 ( & V_30 -> V_127 , 1 ) ;
else
F_54 ( & V_30 -> V_127 , 0 ) ;
V_30 -> V_223 = ( V_181 ) ?
V_151 :
V_152 ;
F_17 ( L_37
L_50 , ( V_181 ) ? L_39 :
L_40 , F_45 ( & V_32 -> V_171 . V_172 ) ,
V_32 -> V_42 , ( V_226 ) ? L_51 : L_52 ) ;
F_6 ( & V_34 -> V_50 ) ;
if ( V_227 != 0 )
F_37 ( V_227 ) ;
if ( V_30 -> V_228 ) {
F_52 ( & V_30 -> V_229 ) ;
F_61 ( V_34 , V_30 ) ;
F_53 ( & V_30 -> V_229 ) ;
}
return 0 ;
}
struct V_6 *
F_62 ( struct V_230 * V_231 ,
T_5 V_94 , T_5 V_93 )
{
struct V_6 * V_232 ;
V_232 = F_63 ( V_233 , V_167 ) ;
if ( ! V_232 ) {
F_16 ( L_53 ) ;
return F_64 ( - V_168 ) ;
}
F_65 ( & V_232 -> V_234 ) ;
V_232 -> V_22 = V_94 ;
V_232 -> V_23 = V_93 ;
F_66 ( & V_232 -> V_18 , V_231 ) ;
return V_232 ;
}
int
F_67 ( struct V_6 * V_232 ,
int V_235 , int V_140 )
{
struct V_8 * V_236 ;
F_8 (lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if ( V_236 -> V_27 == V_235 ) {
F_16 ( L_54 , V_235 ) ;
return - V_207 ;
}
}
V_236 = F_63 ( V_237 , V_167 ) ;
if ( ! V_236 ) {
F_16 ( L_55 ) ;
return - V_168 ;
}
V_236 -> V_25 = V_140 ;
V_236 -> V_27 = V_235 ;
F_66 ( & V_236 -> V_234 ,
& V_232 -> V_234 ) ;
return 0 ;
}
void
F_68 ( struct V_230 * V_238 )
{
struct V_6 * V_232 , * V_239 ;
struct V_8 * V_236 , * V_240 ;
F_69 (lba_map, lba_map_tmp, lba_list,
lba_map_list) {
F_69 (lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
F_70 ( & V_236 -> V_234 ) ;
F_71 ( V_237 ,
V_236 ) ;
}
F_70 ( & V_232 -> V_18 ) ;
F_71 ( V_233 , V_232 ) ;
}
}
void
F_72 ( struct V_3 * V_4 , struct V_230 * V_18 ,
int V_81 , int V_82 )
{
struct V_230 V_241 ;
struct V_31 * V_32 ;
int V_242 = 0 , V_243 ;
F_65 ( & V_241 ) ;
F_4 ( & V_4 -> V_16 . V_17 ) ;
V_4 -> V_16 . V_86 = V_81 ;
V_4 -> V_16 . V_87 = V_82 ;
F_73 ( & V_4 -> V_16 . V_18 , & V_241 ) ;
if ( V_18 ) {
F_73 ( V_18 , & V_4 -> V_16 . V_18 ) ;
V_242 = 1 ;
}
F_6 ( & V_4 -> V_16 . V_17 ) ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
V_243 = V_32 -> V_41 ;
if ( V_242 )
V_243 |= V_147 ;
else
V_243 &= ~ V_147 ;
V_32 -> V_41 = V_243 ;
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_68 ( & V_241 ) ;
}
struct V_202 *
F_74 ( const char * V_244 , int V_245 )
{
struct V_202 * V_203 ;
V_203 = F_63 ( V_246 , V_167 ) ;
if ( ! V_203 ) {
F_16 ( L_56 ) ;
return F_64 ( - V_168 ) ;
}
F_65 ( & V_203 -> V_247 ) ;
F_65 ( & V_203 -> V_248 ) ;
F_75 ( & V_203 -> V_212 ) ;
F_54 ( & V_203 -> V_210 , 0 ) ;
if ( V_245 ) {
V_203 -> V_211 = V_249 ++ ;
V_203 -> V_250 = 1 ;
V_251 ++ ;
}
return V_203 ;
}
int F_76 ( struct V_202 * V_203 , T_3 V_211 )
{
struct V_202 * V_252 ;
T_3 V_253 ;
if ( V_203 -> V_250 ) {
F_2 ( L_57
L_58 ) ;
return - V_207 ;
}
F_4 ( & V_254 ) ;
if ( V_251 == 0x0000ffff ) {
F_16 ( L_59
L_60 ) ;
F_6 ( & V_254 ) ;
F_71 ( V_246 , V_203 ) ;
return - V_255 ;
}
V_256:
V_253 = ( V_211 != 0 ) ? V_211 :
V_249 ++ ;
F_8 (lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if ( V_252 -> V_211 == V_253 ) {
if ( ! V_211 )
goto V_256;
F_2 ( L_61
L_62 ,
V_211 ) ;
F_6 ( & V_254 ) ;
return - V_207 ;
}
}
V_203 -> V_211 = V_253 ;
V_203 -> V_250 = 1 ;
F_66 ( & V_203 -> V_247 , & V_257 ) ;
V_251 ++ ;
F_6 ( & V_254 ) ;
return 0 ;
}
static struct V_204 *
F_77 ( struct V_3 * V_4 )
{
struct V_204 * V_205 ;
V_205 = F_63 ( V_258 , V_167 ) ;
if ( ! V_205 ) {
F_16 ( L_63 ) ;
return F_64 ( - V_168 ) ;
}
F_65 ( & V_205 -> V_248 ) ;
F_75 ( & V_205 -> V_209 ) ;
F_54 ( & V_205 -> V_214 , 0 ) ;
V_205 -> V_213 = V_4 ;
V_4 -> V_208 = V_205 ;
return V_205 ;
}
void F_78 ( struct V_202 * V_203 )
{
struct V_204 * V_205 , * V_259 ;
F_4 ( & V_254 ) ;
F_70 ( & V_203 -> V_247 ) ;
V_251 -- ;
F_6 ( & V_254 ) ;
while ( F_13 ( & V_203 -> V_210 ) )
F_79 () ;
F_4 ( & V_203 -> V_212 ) ;
F_69 (lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if ( V_205 -> V_260 ) {
F_70 ( & V_205 -> V_248 ) ;
V_203 -> V_261 -- ;
V_205 -> V_260 = 0 ;
}
F_6 ( & V_203 -> V_212 ) ;
F_4 ( & V_205 -> V_209 ) ;
if ( V_203 != V_262 )
F_80 ( V_205 ,
V_262 ) ;
else
V_205 -> V_203 = NULL ;
F_6 ( & V_205 -> V_209 ) ;
F_4 ( & V_203 -> V_212 ) ;
}
F_6 ( & V_203 -> V_212 ) ;
F_71 ( V_246 , V_203 ) ;
}
void F_81 ( struct V_3 * V_4 )
{
struct V_202 * V_203 ;
struct V_204 * V_205 ;
V_205 = V_4 -> V_208 ;
if ( ! V_205 )
return;
while ( F_13 ( & V_205 -> V_214 ) )
F_79 () ;
F_4 ( & V_205 -> V_209 ) ;
V_203 = V_205 -> V_203 ;
if ( V_203 ) {
F_4 ( & V_203 -> V_212 ) ;
if ( V_205 -> V_260 ) {
F_70 ( & V_205 -> V_248 ) ;
V_203 -> V_261 -- ;
V_205 -> V_260 = 0 ;
}
F_6 ( & V_203 -> V_212 ) ;
V_205 -> V_203 = NULL ;
}
F_6 ( & V_205 -> V_209 ) ;
F_71 ( V_258 , V_205 ) ;
}
struct V_202 * F_82 ( const char * V_244 )
{
struct V_202 * V_203 ;
struct V_263 * V_264 ;
F_4 ( & V_254 ) ;
F_8 (lu_gp, &lu_gps_list, lu_gp_node) {
if ( ! V_203 -> V_250 )
continue;
V_264 = & V_203 -> V_215 . V_172 ;
if ( ! strcmp ( F_45 ( V_264 ) , V_244 ) ) {
F_20 ( & V_203 -> V_210 ) ;
F_6 ( & V_254 ) ;
return V_203 ;
}
}
F_6 ( & V_254 ) ;
return NULL ;
}
void F_83 ( struct V_202 * V_203 )
{
F_4 ( & V_254 ) ;
F_23 ( & V_203 -> V_210 ) ;
F_6 ( & V_254 ) ;
}
void F_80 (
struct V_204 * V_205 ,
struct V_202 * V_203 )
{
F_4 ( & V_203 -> V_212 ) ;
V_205 -> V_203 = V_203 ;
V_205 -> V_260 = 1 ;
F_66 ( & V_205 -> V_248 , & V_203 -> V_248 ) ;
V_203 -> V_261 ++ ;
F_6 ( & V_203 -> V_212 ) ;
}
void F_84 (
struct V_204 * V_205 ,
struct V_202 * V_203 )
{
F_4 ( & V_203 -> V_212 ) ;
F_70 ( & V_205 -> V_248 ) ;
V_205 -> V_203 = NULL ;
V_205 -> V_260 = 0 ;
V_203 -> V_261 -- ;
F_6 ( & V_203 -> V_212 ) ;
}
struct V_31 * F_85 ( struct V_3 * V_4 ,
const char * V_244 , int V_245 )
{
struct V_31 * V_32 ;
V_32 = F_63 ( V_265 , V_167 ) ;
if ( ! V_32 ) {
F_16 ( L_64 ) ;
return NULL ;
}
F_65 ( & V_32 -> V_266 ) ;
F_65 ( & V_32 -> V_267 ) ;
F_86 ( & V_32 -> V_190 ) ;
F_75 ( & V_32 -> V_44 ) ;
F_54 ( & V_32 -> V_73 , 0 ) ;
F_87 ( & V_32 -> V_175 ,
F_47 ) ;
V_32 -> V_164 = V_4 ;
F_54 ( & V_32 -> V_40 ,
V_130 ) ;
V_32 -> V_69 =
V_70 | V_268 ;
V_32 -> V_129 = V_269 ;
V_32 -> V_196 = V_270 ;
V_32 -> V_51 = V_271 ;
V_32 -> V_41 =
V_272 | V_148 |
V_146 | V_145 | V_144 | V_142 ;
if ( V_245 ) {
F_4 ( & V_4 -> V_16 . V_37 ) ;
V_32 -> V_42 =
V_4 -> V_16 . V_273 ++ ;
V_32 -> V_72 = 1 ;
V_4 -> V_16 . V_274 ++ ;
F_66 ( & V_32 -> V_266 ,
& V_4 -> V_16 . V_275 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
}
return V_32 ;
}
int F_88 (
struct V_31 * V_32 ,
T_3 V_42 )
{
struct V_3 * V_4 = V_32 -> V_164 ;
struct V_31 * V_276 ;
T_3 V_277 ;
if ( V_32 -> V_72 ) {
F_2 ( L_65
L_58 ) ;
return - V_207 ;
}
F_4 ( & V_4 -> V_16 . V_37 ) ;
if ( V_4 -> V_16 . V_274 == 0x0000ffff ) {
F_16 ( L_66
L_60 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_71 ( V_265 , V_32 ) ;
return - V_255 ;
}
V_256:
V_277 = ( V_42 != 0 ) ? V_42 :
V_4 -> V_16 . V_273 ++ ;
F_8 (tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( V_276 -> V_42 == V_277 ) {
if ( ! V_42 )
goto V_256;
F_16 ( L_67
L_68 , V_42 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return - V_207 ;
}
}
V_32 -> V_42 = V_277 ;
V_32 -> V_72 = 1 ;
F_66 ( & V_32 -> V_266 ,
& V_4 -> V_16 . V_275 ) ;
V_4 -> V_16 . V_274 ++ ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return 0 ;
}
struct V_33 * F_89 (
struct V_29 * V_30 )
{
struct V_33 * V_34 ;
V_34 = F_63 ( V_278 ,
V_167 ) ;
if ( ! V_34 ) {
F_16 ( L_69 ) ;
return F_64 ( - V_168 ) ;
}
F_65 ( & V_34 -> V_267 ) ;
F_75 ( & V_34 -> V_50 ) ;
F_54 ( & V_34 -> V_182 , 0 ) ;
V_34 -> V_45 = V_30 ;
V_30 -> V_49 = V_34 ;
return V_34 ;
}
void F_90 (
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_164 ;
struct V_33 * V_34 , * V_279 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_70 ( & V_32 -> V_266 ) ;
V_4 -> V_16 . V_273 -- ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
F_58 ( & V_32 -> V_175 ) ;
while ( F_13 ( & V_32 -> V_73 ) )
F_79 () ;
F_4 ( & V_32 -> V_44 ) ;
F_69 (tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if ( V_34 -> V_280 ) {
F_70 ( & V_34 -> V_267 ) ;
V_32 -> V_38 -- ;
V_34 -> V_280 = 0 ;
}
F_6 ( & V_32 -> V_44 ) ;
F_4 ( & V_34 -> V_50 ) ;
if ( V_32 != V_4 -> V_16 . V_281 ) {
F_91 ( V_34 ,
V_4 -> V_16 . V_281 ) ;
} else
V_34 -> V_32 = NULL ;
F_6 ( & V_34 -> V_50 ) ;
F_4 ( & V_32 -> V_44 ) ;
}
F_6 ( & V_32 -> V_44 ) ;
F_71 ( V_265 , V_32 ) ;
}
void F_92 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return;
while ( F_13 ( & V_34 -> V_182 ) )
F_79 () ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
F_4 ( & V_32 -> V_44 ) ;
if ( V_34 -> V_280 ) {
F_70 ( & V_34 -> V_267 ) ;
V_32 -> V_38 -- ;
V_34 -> V_280 = 0 ;
}
F_6 ( & V_32 -> V_44 ) ;
V_34 -> V_32 = NULL ;
}
F_6 ( & V_34 -> V_50 ) ;
F_71 ( V_278 , V_34 ) ;
}
static struct V_31 * F_93 (
struct V_3 * V_4 , const char * V_244 )
{
struct V_31 * V_32 ;
struct V_263 * V_264 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_8 (tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ( ! V_32 -> V_72 )
continue;
V_264 = & V_32 -> V_171 . V_172 ;
if ( ! strcmp ( F_45 ( V_264 ) , V_244 ) ) {
F_20 ( & V_32 -> V_73 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
return V_32 ;
}
}
F_6 ( & V_4 -> V_16 . V_37 ) ;
return NULL ;
}
static void F_94 (
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_164 ;
F_4 ( & V_4 -> V_16 . V_37 ) ;
F_23 ( & V_32 -> V_73 ) ;
F_6 ( & V_4 -> V_16 . V_37 ) ;
}
void F_91 (
struct V_33 * V_34 ,
struct V_31 * V_32 )
{
F_4 ( & V_32 -> V_44 ) ;
V_34 -> V_32 = V_32 ;
V_34 -> V_280 = 1 ;
F_66 ( & V_34 -> V_267 ,
& V_32 -> V_267 ) ;
V_32 -> V_38 ++ ;
F_6 ( & V_32 -> V_44 ) ;
}
static void F_95 (
struct V_33 * V_34 ,
struct V_31 * V_32 )
{
F_4 ( & V_32 -> V_44 ) ;
F_70 ( & V_34 -> V_267 ) ;
V_34 -> V_32 = NULL ;
V_34 -> V_280 = 0 ;
V_32 -> V_38 -- ;
F_6 ( & V_32 -> V_44 ) ;
}
T_6 F_96 ( struct V_29 * V_30 , char * V_282 )
{
struct V_263 * V_283 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_6 V_61 = 0 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return V_61 ;
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
V_283 = & V_32 -> V_171 . V_172 ;
V_61 += sprintf ( V_282 , L_70
L_71
L_72
L_73 ,
F_45 ( V_283 ) , V_32 -> V_42 ,
F_33 ( F_13 (
& V_32 -> V_40 ) ) ,
F_34 (
V_32 -> V_43 ) ,
( F_13 ( & V_30 -> V_127 ) ) ?
L_24 : L_27 ,
F_34 ( V_30 -> V_223 ) ) ;
}
F_6 ( & V_34 -> V_50 ) ;
return V_61 ;
}
T_6 F_97 (
struct V_29 * V_30 ,
const char * V_282 ,
T_7 V_284 )
{
struct V_216 * V_285 ;
struct V_47 * V_118 ;
struct V_3 * V_4 = V_30 -> V_224 -> V_286 ;
struct V_31 * V_32 = NULL , * V_287 = NULL ;
struct V_33 * V_34 ;
unsigned char V_10 [ V_288 ] ;
int V_289 = 0 ;
V_285 = V_30 -> V_218 ;
V_118 = V_30 -> V_224 ;
V_34 = V_30 -> V_49 ;
if ( ! V_34 )
return 0 ;
if ( V_284 > V_288 ) {
F_16 ( L_74 ) ;
return - V_207 ;
}
memset ( V_10 , 0 , V_288 ) ;
memcpy ( V_10 , V_282 , V_284 ) ;
if ( strcmp ( F_98 ( V_10 ) , L_75 ) ) {
V_287 = F_93 ( V_4 ,
F_98 ( V_10 ) ) ;
if ( ! V_287 )
return - V_160 ;
}
F_4 ( & V_34 -> V_50 ) ;
V_32 = V_34 -> V_32 ;
if ( V_32 ) {
if ( ! V_287 ) {
F_17 ( L_76
L_77
L_78
L_79 ,
V_285 -> V_220 -> V_221 ( V_285 ) ,
V_285 -> V_220 -> V_222 ( V_285 ) ,
F_45 ( & V_118 -> V_290 . V_172 ) ,
F_45 (
& V_32 -> V_171 . V_172 ) ,
V_32 -> V_42 ) ;
F_95 ( V_34 , V_32 ) ;
F_91 ( V_34 ,
V_4 -> V_16 . V_281 ) ;
F_6 ( & V_34 -> V_50 ) ;
return V_284 ;
}
F_95 ( V_34 , V_32 ) ;
V_289 = 1 ;
}
F_91 ( V_34 , V_287 ) ;
F_6 ( & V_34 -> V_50 ) ;
F_17 ( L_80
L_81 , ( V_289 ) ?
L_82 : L_83 , V_285 -> V_220 -> V_221 ( V_285 ) ,
V_285 -> V_220 -> V_222 ( V_285 ) ,
F_45 ( & V_118 -> V_290 . V_172 ) ,
F_45 ( & V_287 -> V_171 . V_172 ) ,
V_287 -> V_42 ) ;
F_94 ( V_287 ) ;
return V_284 ;
}
T_6 F_99 (
struct V_31 * V_32 ,
char * V_282 )
{
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_69 & V_268 ) )
return sprintf ( V_282 , L_84 ) ;
else if ( V_32 -> V_69 & V_268 )
return sprintf ( V_282 , L_85 ) ;
else if ( V_32 -> V_69 & V_70 )
return sprintf ( V_282 , L_86 ) ;
else
return sprintf ( V_282 , L_87 ) ;
}
T_6 F_100 (
struct V_31 * V_32 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_88 ) ;
return V_120 ;
}
if ( ( V_95 != 0 ) && ( V_95 != 1 ) && ( V_95 != 2 ) && ( V_95 != 3 ) ) {
F_16 ( L_89
L_90 , V_95 ) ;
return - V_207 ;
}
if ( V_95 == 3 )
V_32 -> V_69 =
V_268 | V_70 ;
else if ( V_95 == 2 )
V_32 -> V_69 = V_70 ;
else if ( V_95 == 1 )
V_32 -> V_69 = V_268 ;
else
V_32 -> V_69 = 0 ;
return V_284 ;
}
T_6 F_102 (
struct V_31 * V_32 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 , V_32 -> V_129 ) ;
}
T_6 F_103 (
struct V_31 * V_32 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_92 ) ;
return V_120 ;
}
if ( V_95 > V_291 ) {
F_16 ( L_93
L_94 , V_95 ,
V_291 ) ;
return - V_207 ;
}
V_32 -> V_129 = ( int ) V_95 ;
return V_284 ;
}
T_6 F_104 (
struct V_31 * V_32 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 , V_32 -> V_196 ) ;
}
T_6 F_105 (
struct V_31 * V_32 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_95 ) ;
return V_120 ;
}
if ( V_95 > V_292 ) {
F_16 ( L_96
L_97 , V_95 ,
V_292 ) ;
return - V_207 ;
}
V_32 -> V_196 = ( int ) V_95 ;
return V_284 ;
}
T_6 F_106 (
struct V_31 * V_32 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 , V_32 -> V_51 ) ;
}
T_6 F_107 (
struct V_31 * V_32 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_98 ) ;
return V_120 ;
}
if ( V_95 > V_293 ) {
F_16 ( L_99
L_100 , V_95 ,
V_293 ) ;
return - V_207 ;
}
V_32 -> V_51 = ( int ) V_95 ;
return V_284 ;
}
T_6 F_108 (
struct V_31 * V_32 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 , V_32 -> V_39 ) ;
}
T_6 F_109 (
struct V_31 * V_32 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_101 ) ;
return V_120 ;
}
if ( ( V_95 != 0 ) && ( V_95 != 1 ) ) {
F_16 ( L_102 , V_95 ) ;
return - V_207 ;
}
V_32 -> V_39 = ( int ) V_95 ;
return V_284 ;
}
T_6 F_110 ( struct V_47 * V_118 , char * V_282 )
{
if ( ! V_118 -> V_48 )
return - V_160 ;
return sprintf ( V_282 , L_91 ,
F_13 ( & V_118 -> V_48 -> V_127 ) ) ;
}
T_6 F_111 (
struct V_47 * V_118 ,
const char * V_282 ,
T_7 V_284 )
{
struct V_33 * V_34 ;
unsigned long V_95 ;
int V_120 ;
if ( ! V_118 -> V_48 )
return - V_160 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_103 ) ;
return V_120 ;
}
if ( ( V_95 != 0 ) && ( V_95 != 1 ) ) {
F_16 ( L_104 ,
V_95 ) ;
return - V_207 ;
}
V_34 = V_118 -> V_48 -> V_49 ;
if ( ! V_34 ) {
F_16 ( L_105 ) ;
return - V_207 ;
}
V_120 = F_25 ( V_34 ,
V_118 -> V_48 , 0 , ( int ) V_95 ) ;
if ( V_120 < 0 )
return - V_207 ;
return V_284 ;
}
T_6 F_112 (
struct V_47 * V_118 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 , V_118 -> V_48 -> V_223 ) ;
}
T_6 F_113 (
struct V_47 * V_118 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_106 ) ;
return V_120 ;
}
if ( ( V_95 != V_150 ) &&
( V_95 != V_151 ) &&
( V_95 != V_152 ) ) {
F_16 ( L_107 ,
V_95 ) ;
return - V_207 ;
}
V_118 -> V_48 -> V_223 = ( int ) V_95 ;
return V_284 ;
}
T_6 F_114 (
struct V_47 * V_118 ,
char * V_282 )
{
return sprintf ( V_282 , L_91 ,
V_118 -> V_48 -> V_228 ) ;
}
T_6 F_115 (
struct V_47 * V_118 ,
const char * V_282 ,
T_7 V_284 )
{
unsigned long V_95 ;
int V_120 ;
V_120 = F_101 ( V_282 , 0 , & V_95 ) ;
if ( V_120 < 0 ) {
F_16 ( L_108 ) ;
return V_120 ;
}
if ( ( V_95 != 0 ) && ( V_95 != 1 ) ) {
F_16 ( L_109
L_90 , V_95 ) ;
return - V_207 ;
}
V_118 -> V_48 -> V_228 = ( int ) V_95 ;
return V_284 ;
}
int F_116 ( struct V_3 * V_4 )
{
if ( V_4 -> V_124 -> V_125 != V_126 &&
! ( V_4 -> V_121 -> V_122 & V_123 ) ) {
struct V_204 * V_205 ;
V_205 = F_77 ( V_4 ) ;
if ( F_40 ( V_205 ) )
return F_117 ( V_205 ) ;
F_4 ( & V_205 -> V_209 ) ;
F_80 ( V_205 ,
V_262 ) ;
F_6 ( & V_205 -> V_209 ) ;
F_17 ( L_110
L_111 ,
V_4 -> V_124 -> V_244 ) ;
}
return 0 ;
}
