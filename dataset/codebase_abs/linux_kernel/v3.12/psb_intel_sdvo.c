static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static struct V_7 * F_5 ( struct V_5 * V_6 )
{
return F_2 ( F_6 ( V_6 ) , struct V_7 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_8 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_1 V_11 = V_8 , V_12 = V_8 ;
int V_13 ;
if ( V_1 -> V_14 == V_15 ) {
V_12 = F_8 ( V_16 ) ;
} else {
V_11 = F_8 ( V_15 ) ;
}
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
{
F_9 ( V_15 , V_11 ) ;
F_8 ( V_15 ) ;
F_9 ( V_16 , V_12 ) ;
F_8 ( V_16 ) ;
}
}
static bool F_10 ( struct V_1 * V_1 , T_2 V_17 , T_2 * V_18 )
{
struct V_19 V_20 [] = {
{
. V_17 = V_1 -> V_21 ,
. V_22 = 0 ,
. V_23 = 1 ,
. V_24 = & V_17 ,
} ,
{
. V_17 = V_1 -> V_21 ,
. V_22 = V_25 ,
. V_23 = 1 ,
. V_24 = V_18 ,
}
} ;
int V_26 ;
if ( ( V_26 = F_11 ( V_1 -> V_27 , V_20 , 2 ) ) == 2 )
return true ;
F_12 ( L_1 , V_26 ) ;
return false ;
}
static void F_13 ( struct V_1 * V_1 , T_2 V_28 ,
const void * args , int V_29 )
{
int V_13 ;
F_12 ( L_2 ,
F_14 ( V_1 ) , V_28 ) ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 ++ )
F_15 ( L_3 , ( ( T_2 * ) args ) [ V_13 ] ) ;
for (; V_13 < 8 ; V_13 ++ )
F_15 ( L_4 ) ;
for ( V_13 = 0 ; V_13 < F_16 ( V_30 ) ; V_13 ++ ) {
if ( V_28 == V_30 [ V_13 ] . V_28 ) {
F_15 ( L_5 , V_30 [ V_13 ] . V_31 ) ;
break;
}
}
if ( V_13 == F_16 ( V_30 ) )
F_15 ( L_6 , V_28 ) ;
F_15 ( L_7 ) ;
}
static bool F_17 ( struct V_1 * V_1 , T_2 V_28 ,
const void * args , int V_29 )
{
T_2 V_24 [ V_29 * 2 + 2 ] , V_32 ;
struct V_19 V_20 [ V_29 + 3 ] ;
int V_13 , V_26 ;
F_13 ( V_1 , V_28 , args , V_29 ) ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 ++ ) {
V_20 [ V_13 ] . V_17 = V_1 -> V_21 ;
V_20 [ V_13 ] . V_22 = 0 ;
V_20 [ V_13 ] . V_23 = 2 ;
V_20 [ V_13 ] . V_24 = V_24 + 2 * V_13 ;
V_24 [ 2 * V_13 + 0 ] = V_33 - V_13 ;
V_24 [ 2 * V_13 + 1 ] = ( ( T_2 * ) args ) [ V_13 ] ;
}
V_20 [ V_13 ] . V_17 = V_1 -> V_21 ;
V_20 [ V_13 ] . V_22 = 0 ;
V_20 [ V_13 ] . V_23 = 2 ;
V_20 [ V_13 ] . V_24 = V_24 + 2 * V_13 ;
V_24 [ 2 * V_13 + 0 ] = V_34 ;
V_24 [ 2 * V_13 + 1 ] = V_28 ;
V_32 = V_35 ;
V_20 [ V_13 + 1 ] . V_17 = V_1 -> V_21 ;
V_20 [ V_13 + 1 ] . V_22 = 0 ;
V_20 [ V_13 + 1 ] . V_23 = 1 ;
V_20 [ V_13 + 1 ] . V_24 = & V_32 ;
V_20 [ V_13 + 2 ] . V_17 = V_1 -> V_21 ;
V_20 [ V_13 + 2 ] . V_22 = V_25 ;
V_20 [ V_13 + 2 ] . V_23 = 1 ;
V_20 [ V_13 + 2 ] . V_24 = & V_32 ;
V_26 = F_11 ( V_1 -> V_27 , V_20 , V_13 + 3 ) ;
if ( V_26 < 0 ) {
F_12 ( L_8 , V_26 ) ;
return false ;
}
if ( V_26 != V_13 + 3 ) {
F_12 ( L_9 , V_26 , V_13 + 3 ) ;
return false ;
}
return true ;
}
static bool F_18 ( struct V_1 * V_1 ,
void * V_36 , int V_37 )
{
T_2 V_38 = 5 ;
T_2 V_32 ;
int V_13 ;
F_12 ( L_10 , F_14 ( V_1 ) ) ;
if ( ! F_10 ( V_1 ,
V_35 ,
& V_32 ) )
goto V_39;
while ( ( V_32 == V_40 ||
V_32 == V_41 ) && V_38 -- ) {
F_19 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_35 ,
& V_32 ) )
goto V_39;
}
if ( V_32 <= V_42 )
F_15 ( L_5 , V_43 [ V_32 ] ) ;
else
F_15 ( L_11 , V_32 ) ;
if ( V_32 != V_44 )
goto V_39;
for ( V_13 = 0 ; V_13 < V_37 ; V_13 ++ ) {
if ( ! F_10 ( V_1 ,
V_45 + V_13 ,
& ( ( T_2 * ) V_36 ) [ V_13 ] ) )
goto V_39;
F_15 ( L_12 , ( ( T_2 * ) V_36 ) [ V_13 ] ) ;
}
F_15 ( L_7 ) ;
return true ;
V_39:
F_15 ( L_13 ) ;
return false ;
}
static int F_20 ( struct V_46 * V_47 )
{
if ( V_47 -> clock >= 100000 )
return 1 ;
else if ( V_47 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_21 ( struct V_1 * V_1 ,
T_2 V_48 )
{
return F_17 ( V_1 ,
V_49 ,
& V_48 , 1 ) ;
}
static bool F_22 ( struct V_1 * V_1 , T_2 V_28 , const void * V_50 , int V_23 )
{
if ( ! F_17 ( V_1 , V_28 , V_50 , V_23 ) )
return false ;
return F_18 ( V_1 , NULL , 0 ) ;
}
static bool
F_23 ( struct V_1 * V_1 , T_2 V_28 , void * V_51 , int V_23 )
{
if ( ! F_17 ( V_1 , V_28 , NULL , 0 ) )
return false ;
return F_18 ( V_1 , V_51 , V_23 ) ;
}
static bool F_24 ( struct V_1 * V_1 )
{
struct V_52 V_53 = { 0 } ;
return F_22 ( V_1 ,
V_54 ,
& V_53 , sizeof( V_53 ) ) ;
}
static bool F_25 ( struct V_1 * V_1 , bool * V_55 , bool * V_56 )
{
struct V_57 V_36 ;
F_26 ( sizeof( V_36 ) != 1 ) ;
if ( ! F_23 ( V_1 , V_58 ,
& V_36 , sizeof( V_36 ) ) )
return false ;
* V_55 = V_36 . V_59 ;
* V_56 = V_36 . V_60 ;
return true ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_3 V_61 )
{
return F_22 ( V_1 ,
V_62 ,
& V_61 , sizeof( V_61 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 ,
int V_47 )
{
T_2 V_63 = V_64 ;
switch ( V_47 ) {
case V_65 :
V_63 = V_64 ;
break;
case V_66 :
V_63 = V_67 ;
break;
case V_68 :
V_63 = V_69 ;
break;
case V_70 :
V_63 = V_71 ;
break;
}
return F_22 ( V_1 ,
V_72 , & V_63 , sizeof( V_63 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 ,
int * V_73 ,
int * V_74 )
{
struct V_75 V_76 ;
F_26 ( sizeof( V_76 ) != 4 ) ;
if ( ! F_23 ( V_1 ,
V_77 ,
& V_76 , sizeof( V_76 ) ) )
return false ;
* V_73 = V_76 . V_78 * 10 ;
* V_74 = V_76 . V_79 * 10 ;
return true ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_3 V_61 )
{
return F_22 ( V_1 ,
V_80 ,
& V_61 , sizeof( V_61 ) ) ;
}
static bool F_31 ( struct V_1 * V_1 , T_2 V_28 ,
struct V_81 * V_82 )
{
return F_22 ( V_1 , V_28 , & V_82 -> V_83 , sizeof( V_82 -> V_83 ) ) &&
F_22 ( V_1 , V_28 + 1 , & V_82 -> V_84 , sizeof( V_82 -> V_84 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_81 * V_82 )
{
return F_31 ( V_1 ,
V_85 , V_82 ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
struct V_81 * V_82 )
{
return F_31 ( V_1 ,
V_86 , V_82 ) ;
}
static bool
F_34 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_87 ,
T_4 V_88 )
{
struct V_89 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_87 = V_87 ;
args . V_88 = V_88 ;
args . V_90 = 0 ;
if ( V_1 -> V_91 &&
( V_1 -> V_92 -> V_93 != V_87 ||
V_1 -> V_92 -> V_94 != V_88 ) )
args . V_95 = 1 ;
return F_22 ( V_1 ,
V_96 ,
& args , sizeof( args ) ) ;
}
static bool F_35 ( struct V_1 * V_1 ,
struct V_81 * V_82 )
{
F_26 ( sizeof( V_82 -> V_83 ) != 8 ) ;
F_26 ( sizeof( V_82 -> V_84 ) != 8 ) ;
return F_23 ( V_1 , V_97 ,
& V_82 -> V_83 , sizeof( V_82 -> V_83 ) ) &&
F_23 ( V_1 , V_98 ,
& V_82 -> V_84 , sizeof( V_82 -> V_84 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_22 ( V_1 , V_99 , & V_8 , 1 ) ;
}
static void F_37 ( struct V_81 * V_82 ,
const struct V_46 * V_47 )
{
T_4 V_87 , V_88 ;
T_4 V_100 , V_101 , V_102 , V_103 ;
T_4 V_104 , V_105 ;
V_87 = V_47 -> V_106 ;
V_88 = V_47 -> V_107 ;
V_100 = V_47 -> V_108 - V_47 -> V_109 ;
V_101 = V_47 -> V_110 - V_47 -> V_111 ;
V_102 = V_47 -> V_112 - V_47 -> V_113 ;
V_103 = V_47 -> V_114 - V_47 -> V_115 ;
V_104 = V_47 -> V_111 - V_47 -> V_109 ;
V_105 = V_47 -> V_115 - V_47 -> V_113 ;
V_82 -> V_83 . clock = V_47 -> clock / 10 ;
V_82 -> V_83 . V_116 = V_87 & 0xff ;
V_82 -> V_83 . V_117 = V_100 & 0xff ;
V_82 -> V_83 . V_118 = ( ( ( V_87 >> 8 ) & 0xf ) << 4 ) |
( ( V_100 >> 8 ) & 0xf ) ;
V_82 -> V_83 . V_119 = V_88 & 0xff ;
V_82 -> V_83 . V_120 = V_102 & 0xff ;
V_82 -> V_83 . V_121 = ( ( ( V_88 >> 8 ) & 0xf ) << 4 ) |
( ( V_102 >> 8 ) & 0xf ) ;
V_82 -> V_84 . V_122 = V_104 & 0xff ;
V_82 -> V_84 . V_123 = V_101 & 0xff ;
V_82 -> V_84 . V_124 = ( V_105 & 0xf ) << 4 |
( V_103 & 0xf ) ;
V_82 -> V_84 . V_125 = ( ( V_104 & 0x300 ) >> 2 ) |
( ( V_101 & 0x300 ) >> 4 ) | ( ( V_105 & 0x30 ) >> 2 ) |
( ( V_103 & 0x30 ) >> 4 ) ;
V_82 -> V_84 . V_126 = 0x18 ;
if ( V_47 -> V_22 & V_127 )
V_82 -> V_84 . V_126 |= 0x2 ;
if ( V_47 -> V_22 & V_128 )
V_82 -> V_84 . V_126 |= 0x4 ;
V_82 -> V_84 . V_129 = 0 ;
V_82 -> V_84 . V_130 = V_105 & 0xc0 ;
V_82 -> V_84 . V_131 = 0 ;
}
static void F_38 ( struct V_46 * V_47 ,
const struct V_81 * V_82 )
{
V_47 -> V_93 = V_82 -> V_83 . V_116 ;
V_47 -> V_93 += ( ( V_82 -> V_83 . V_118 >> 4 ) & 0x0f ) << 8 ;
V_47 -> V_132 = V_47 -> V_93 + V_82 -> V_84 . V_122 ;
V_47 -> V_132 += ( V_82 -> V_84 . V_125 & 0xc0 ) << 2 ;
V_47 -> V_133 = V_47 -> V_132 + V_82 -> V_84 . V_123 ;
V_47 -> V_133 += ( V_82 -> V_84 . V_125 & 0x30 ) << 4 ;
V_47 -> V_134 = V_47 -> V_93 + V_82 -> V_83 . V_117 ;
V_47 -> V_134 += ( V_82 -> V_83 . V_118 & 0xf ) << 8 ;
V_47 -> V_94 = V_82 -> V_83 . V_119 ;
V_47 -> V_94 += ( ( V_82 -> V_83 . V_121 >> 4 ) & 0x0f ) << 8 ;
V_47 -> V_135 = V_47 -> V_94 ;
V_47 -> V_135 += ( V_82 -> V_84 . V_124 >> 4 ) & 0xf ;
V_47 -> V_135 += ( V_82 -> V_84 . V_125 & 0x0c ) << 2 ;
V_47 -> V_135 += V_82 -> V_84 . V_130 & 0xc0 ;
V_47 -> V_136 = V_47 -> V_135 +
( V_82 -> V_84 . V_124 & 0xf ) ;
V_47 -> V_136 += ( V_82 -> V_84 . V_125 & 0x3 ) << 4 ;
V_47 -> V_137 = V_47 -> V_94 + V_82 -> V_83 . V_120 ;
V_47 -> V_137 += ( V_82 -> V_83 . V_121 & 0xf ) << 8 ;
V_47 -> clock = V_82 -> V_83 . clock * 10 ;
V_47 -> V_22 &= ~ ( V_127 | V_128 ) ;
if ( V_82 -> V_84 . V_126 & 0x2 )
V_47 -> V_22 |= V_127 ;
if ( V_82 -> V_84 . V_126 & 0x4 )
V_47 -> V_22 |= V_128 ;
}
static bool F_39 ( struct V_1 * V_1 )
{
struct V_138 V_139 ;
F_26 ( sizeof( V_139 ) != 2 ) ;
return F_23 ( V_1 ,
V_140 ,
& V_139 , sizeof( V_139 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_5 V_47 )
{
return F_22 ( V_1 , V_141 , & V_47 , 1 ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_5 V_47 )
{
return F_22 ( V_1 , V_142 , & V_47 , 1 ) ;
}
static bool F_42 ( struct V_1 * V_1 )
{
F_43 ( L_14 ) ;
return false ;
#if 0
struct dip_infoframe avi_if = {
.type = DIP_TYPE_AVI,
.ver = DIP_VERSION_AVI,
.len = DIP_LEN_AVI,
};
uint8_t tx_rate = SDVO_HBUF_TX_VSYNC;
uint8_t set_buf_index[2] = { 1, 0 };
uint64_t *data = (uint64_t *)&avi_if;
unsigned i;
intel_dip_infoframe_csum(&avi_if);
if (!psb_intel_sdvo_set_value(psb_intel_sdvo,
SDVO_CMD_SET_HBUF_INDEX,
set_buf_index, 2))
return false;
for (i = 0; i < sizeof(avi_if); i += 8) {
if (!psb_intel_sdvo_set_value(psb_intel_sdvo,
SDVO_CMD_SET_HBUF_DATA,
data, 8))
return false;
data++;
}
return psb_intel_sdvo_set_value(psb_intel_sdvo,
SDVO_CMD_SET_HBUF_TXRATE,
&tx_rate, 1);
#endif
}
static bool F_44 ( struct V_1 * V_1 )
{
struct V_143 V_144 ;
T_6 V_145 ;
V_145 = 1 << V_1 -> V_146 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
memcpy ( & V_144 , & V_145 , V_78 ( sizeof( V_144 ) , sizeof( V_145 ) ) ) ;
F_26 ( sizeof( V_144 ) != 6 ) ;
return F_22 ( V_1 ,
V_147 ,
& V_144 , sizeof( V_144 ) ) ;
}
static bool
F_45 ( struct V_1 * V_1 ,
const struct V_46 * V_47 )
{
struct V_81 V_148 ;
if ( ! F_30 ( V_1 ,
V_1 -> V_149 ) )
return false ;
F_37 ( & V_148 , V_47 ) ;
if ( ! F_33 ( V_1 , & V_148 ) )
return false ;
return true ;
}
static bool
F_46 ( struct V_1 * V_1 ,
const struct V_46 * V_47 ,
struct V_46 * V_150 )
{
if ( ! F_24 ( V_1 ) )
return false ;
if ( ! F_34 ( V_1 ,
V_47 -> clock / 10 ,
V_47 -> V_93 ,
V_47 -> V_94 ) )
return false ;
if ( ! F_35 ( V_1 ,
& V_1 -> V_151 ) )
return false ;
F_38 ( V_150 , & V_1 -> V_151 ) ;
F_47 ( V_150 , 0 ) ;
return true ;
}
static bool F_48 ( struct V_2 * V_3 ,
const struct V_46 * V_47 ,
struct V_46 * V_150 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_152 ;
if ( V_1 -> V_153 ) {
if ( ! F_45 ( V_1 , V_47 ) )
return false ;
( void ) F_46 ( V_1 ,
V_47 ,
V_150 ) ;
} else if ( V_1 -> V_91 ) {
if ( ! F_45 ( V_1 ,
V_1 -> V_92 ) )
return false ;
( void ) F_46 ( V_1 ,
V_47 ,
V_150 ) ;
}
V_152 = F_20 ( V_150 ) ;
F_49 ( V_150 , V_152 ) ;
return true ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_46 * V_47 ,
struct V_46 * V_150 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_154 * V_155 = V_3 -> V_155 ;
struct V_156 * V_156 = F_51 ( V_155 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_157 ;
struct V_158 V_159 ;
struct V_81 V_151 ;
int V_160 = F_52 ( V_150 ) ;
int V_161 ;
if ( ! V_47 )
return;
V_159 . V_162 = V_1 -> V_149 ;
V_159 . V_163 = 0 ;
F_22 ( V_1 ,
V_164 ,
& V_159 , sizeof( V_159 ) ) ;
if ( ! F_30 ( V_1 ,
V_1 -> V_149 ) )
return;
if ( V_1 -> V_153 || V_1 -> V_91 ) {
V_151 = V_1 -> V_151 ;
} else {
if ( ! F_30 ( V_1 ,
V_1 -> V_149 ) )
return;
F_37 ( & V_151 , V_150 ) ;
( void ) F_33 ( V_1 , & V_151 ) ;
}
if ( ! F_24 ( V_1 ) )
return;
if ( V_1 -> V_165 ) {
F_40 ( V_1 , V_166 ) ;
F_41 ( V_1 ,
V_167 ) ;
F_42 ( V_1 ) ;
} else
F_40 ( V_1 , V_168 ) ;
if ( V_1 -> V_153 &&
! F_44 ( V_1 ) )
return;
( void ) F_32 ( V_1 , & V_151 ) ;
switch ( V_160 ) {
default:
case 1 : V_161 = V_169 ; break;
case 2 : V_161 = V_170 ; break;
case 4 : V_161 = V_171 ; break;
}
if ( ! F_36 ( V_1 , V_161 ) )
return;
V_157 = F_8 ( V_1 -> V_14 ) ;
switch ( V_1 -> V_14 ) {
case V_15 :
V_157 &= V_172 ;
break;
case V_16 :
V_157 &= V_173 ;
break;
}
V_157 |= ( 9 << 19 ) | V_174 ;
if ( V_156 -> V_175 == 1 )
V_157 |= V_176 ;
if ( V_1 -> V_177 )
V_157 |= V_178 ;
if ( V_151 . V_84 . V_129 & V_179 )
V_157 |= V_180 ;
F_7 ( V_1 , V_157 ) ;
}
static void F_53 ( struct V_2 * V_3 , int V_47 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_181 ;
switch ( V_47 ) {
case V_65 :
F_54 ( L_15 ) ;
break;
case V_70 :
F_54 ( L_16 ) ;
break;
default:
F_54 ( L_17 , V_47 ) ;
}
if ( V_47 != V_65 ) {
F_27 ( V_1 , 0 ) ;
if ( 0 )
F_28 ( V_1 , V_47 ) ;
if ( V_47 == V_70 ) {
V_181 = F_8 ( V_1 -> V_14 ) ;
if ( ( V_181 & V_182 ) != 0 ) {
F_7 ( V_1 , V_181 & ~ V_182 ) ;
}
}
} else {
bool V_183 , V_184 ;
int V_13 ;
T_2 V_32 ;
V_181 = F_8 ( V_1 -> V_14 ) ;
if ( ( V_181 & V_182 ) == 0 )
F_7 ( V_1 , V_181 | V_182 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
F_55 ( V_10 ) ;
V_32 = F_25 ( V_1 , & V_183 , & V_184 ) ;
if ( V_32 == V_44 && ! V_183 ) {
F_12 ( L_18
L_19 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_28 ( V_1 , V_47 ) ;
F_27 ( V_1 , V_1 -> V_149 ) ;
}
return;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_47 -> V_22 & V_185 )
return V_186 ;
if ( V_1 -> V_187 > V_47 -> clock )
return V_188 ;
if ( V_1 -> V_189 < V_47 -> clock )
return V_190 ;
if ( V_1 -> V_91 ) {
if ( V_47 -> V_93 > V_1 -> V_92 -> V_93 )
return V_191 ;
if ( V_47 -> V_94 > V_1 -> V_92 -> V_94 )
return V_191 ;
}
return V_192 ;
}
static bool F_57 ( struct V_1 * V_1 , struct V_193 * V_194 )
{
F_26 ( sizeof( * V_194 ) != 8 ) ;
if ( ! F_23 ( V_1 ,
V_195 ,
V_194 , sizeof( * V_194 ) ) )
return false ;
F_12 ( L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32 ,
V_194 -> V_196 ,
V_194 -> V_197 ,
V_194 -> V_198 ,
V_194 -> V_199 ,
V_194 -> V_200 ,
V_194 -> V_201 ,
V_194 -> V_202 ,
V_194 -> V_203 ,
V_194 -> V_204 ,
V_194 -> V_205 ,
V_194 -> V_206 ,
V_194 -> V_207 ) ;
return true ;
}
static bool
F_58 ( struct V_1 * V_1 )
{
int V_194 = V_1 -> V_194 . V_207 & 0xf ;
return V_194 & - V_194 ;
}
static struct V_208 *
F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_209 = F_3 ( V_6 ) ;
return F_60 ( V_6 , & V_209 -> V_210 ) ;
}
static struct V_208 *
F_61 ( struct V_5 * V_6 )
{
struct V_211 * V_212 = V_6 -> V_10 -> V_213 ;
return F_60 ( V_6 ,
& V_212 -> V_214 [ V_212 -> V_215 ] . V_216 ) ;
}
static enum V_217
F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_217 V_32 ;
struct V_208 * V_208 ;
V_208 = F_59 ( V_6 ) ;
if ( V_208 == NULL && F_58 ( V_1 ) ) {
T_2 V_210 , V_218 = V_1 -> V_48 ;
for ( V_210 = V_1 -> V_48 >> 1 ; V_210 > 1 ; V_210 >>= 1 ) {
V_1 -> V_48 = V_210 ;
V_208 = F_59 ( V_6 ) ;
if ( V_208 )
break;
}
if ( V_208 == NULL )
V_1 -> V_48 = V_218 ;
}
if ( V_208 == NULL )
V_208 = F_61 ( V_6 ) ;
V_32 = V_219 ;
if ( V_208 != NULL ) {
if ( V_208 -> V_220 & V_221 ) {
V_32 = V_222 ;
if ( V_1 -> V_223 ) {
V_1 -> V_165 = F_63 ( V_208 ) ;
V_1 -> V_177 = F_64 ( V_208 ) ;
}
} else
V_32 = V_224 ;
F_65 ( V_208 ) ;
}
if ( V_32 == V_222 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_225 )
V_1 -> V_177 = V_7 -> V_225 > 0 ;
}
return V_32 ;
}
static enum V_217
F_66 ( struct V_5 * V_6 , bool V_226 )
{
T_4 V_36 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_217 V_26 ;
if ( ! F_17 ( V_1 ,
V_227 , NULL , 0 ) )
return V_219 ;
if ( V_1 -> V_194 . V_207 &
( V_228 | V_229 ) )
F_67 ( 30 ) ;
if ( ! F_18 ( V_1 , & V_36 , 2 ) )
return V_219 ;
F_12 ( L_33 ,
V_36 & 0xff , V_36 >> 8 ,
V_7 -> V_230 ) ;
if ( V_36 == 0 )
return V_224 ;
V_1 -> V_149 = V_36 ;
V_1 -> V_165 = false ;
V_1 -> V_177 = false ;
if ( ( V_7 -> V_230 & V_36 ) == 0 )
V_26 = V_224 ;
else if ( F_68 ( V_7 ) )
V_26 = F_62 ( V_6 ) ;
else {
struct V_208 * V_208 ;
V_208 = F_59 ( V_6 ) ;
if ( V_208 == NULL )
V_208 = F_61 ( V_6 ) ;
if ( V_208 != NULL ) {
if ( V_208 -> V_220 & V_221 )
V_26 = V_224 ;
else
V_26 = V_222 ;
F_65 ( V_208 ) ;
} else
V_26 = V_222 ;
}
if ( V_26 == V_222 ) {
V_1 -> V_153 = false ;
V_1 -> V_91 = false ;
V_1 -> V_4 . V_231 = false ;
if ( V_36 & V_232 ) {
V_1 -> V_153 = true ;
V_1 -> V_4 . V_231 = true ;
}
if ( V_36 & V_233 )
V_1 -> V_91 = V_1 -> V_92 != NULL ;
}
return V_26 ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_208 * V_208 ;
V_208 = F_59 ( V_6 ) ;
if ( V_208 == NULL )
V_208 = F_61 ( V_6 ) ;
if ( V_208 != NULL ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
bool V_234 = ! ! ( V_208 -> V_220 & V_221 ) ;
bool V_235 = ! ! F_68 ( V_7 ) ;
if ( V_235 == V_234 ) {
F_70 ( V_6 , V_208 ) ;
F_71 ( V_6 , V_208 ) ;
}
F_65 ( V_208 ) ;
}
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_236 V_237 ;
T_6 V_238 = 0 , V_145 = 0 ;
int V_13 ;
V_145 = 1 << V_1 -> V_146 ;
memcpy ( & V_237 , & V_145 ,
V_78 ( sizeof( V_145 ) , sizeof( struct V_236 ) ) ) ;
if ( ! F_30 ( V_1 , V_1 -> V_149 ) )
return;
F_26 ( sizeof( V_237 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_239 ,
& V_237 , sizeof( V_237 ) ) )
return;
if ( ! F_18 ( V_1 , & V_238 , 3 ) )
return;
for ( V_13 = 0 ; V_13 < F_16 ( V_240 ) ; V_13 ++ )
if ( V_238 & ( 1 << V_13 ) ) {
struct V_46 * V_241 ;
V_241 = F_73 ( V_6 -> V_10 ,
& V_240 [ V_13 ] ) ;
if ( V_241 )
F_74 ( V_6 , V_241 ) ;
}
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_211 * V_212 = V_6 -> V_10 -> V_213 ;
struct V_46 * V_242 ;
F_76 ( V_6 , V_1 -> V_27 ) ;
if ( F_77 ( & V_6 -> V_243 ) == false )
goto V_244;
if ( V_212 -> V_245 != NULL ) {
V_242 = F_73 ( V_6 -> V_10 ,
V_212 -> V_245 ) ;
if ( V_242 != NULL ) {
V_242 -> type = ( V_246 |
V_247 ) ;
F_74 ( V_6 , V_242 ) ;
}
}
V_244:
F_78 (newmode, &connector->probed_modes, head) {
if ( V_242 -> type & V_246 ) {
V_1 -> V_92 =
F_73 ( V_6 -> V_10 , V_242 ) ;
F_47 ( V_1 -> V_92 ,
0 ) ;
V_1 -> V_91 = true ;
break;
}
}
}
static int F_79 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_80 ( V_7 ) )
F_72 ( V_6 ) ;
else if ( F_81 ( V_7 ) )
F_75 ( V_6 ) ;
else
F_69 ( V_6 ) ;
return ! F_77 ( & V_6 -> V_243 ) ;
}
static void
F_82 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_248 )
F_83 ( V_10 , V_7 -> V_248 ) ;
if ( V_7 -> V_249 )
F_83 ( V_10 , V_7 -> V_249 ) ;
if ( V_7 -> V_250 )
F_83 ( V_10 , V_7 -> V_250 ) ;
if ( V_7 -> V_251 )
F_83 ( V_10 , V_7 -> V_251 ) ;
if ( V_7 -> V_252 )
F_83 ( V_10 , V_7 -> V_252 ) ;
if ( V_7 -> V_253 )
F_83 ( V_10 , V_7 -> V_253 ) ;
if ( V_7 -> V_254 )
F_83 ( V_10 , V_7 -> V_254 ) ;
if ( V_7 -> V_255 )
F_83 ( V_10 , V_7 -> V_255 ) ;
if ( V_7 -> V_256 )
F_83 ( V_10 , V_7 -> V_256 ) ;
if ( V_7 -> V_257 )
F_83 ( V_10 , V_7 -> V_257 ) ;
if ( V_7 -> V_258 )
F_83 ( V_10 , V_7 -> V_258 ) ;
if ( V_7 -> V_259 )
F_83 ( V_10 , V_7 -> V_259 ) ;
if ( V_7 -> V_260 )
F_83 ( V_10 , V_7 -> V_260 ) ;
if ( V_7 -> V_261 )
F_83 ( V_10 , V_7 -> V_261 ) ;
if ( V_7 -> V_262 )
F_83 ( V_10 , V_7 -> V_262 ) ;
if ( V_7 -> V_263 )
F_83 ( V_10 , V_7 -> V_263 ) ;
if ( V_7 -> V_264 )
F_83 ( V_10 , V_7 -> V_264 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_265 )
F_83 ( V_6 -> V_10 ,
V_7 -> V_265 ) ;
F_82 ( V_6 ) ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_65 ( V_6 ) ;
}
static bool F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_208 * V_208 ;
bool V_266 = false ;
if ( ! V_1 -> V_223 )
return false ;
V_208 = F_59 ( V_6 ) ;
if ( V_208 != NULL && V_208 -> V_220 & V_221 )
V_266 = F_64 ( V_208 ) ;
return V_266 ;
}
static int
F_88 ( struct V_5 * V_6 ,
struct V_267 * V_268 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_211 * V_212 = V_6 -> V_10 -> V_213 ;
T_4 V_269 ;
T_5 V_28 ;
int V_26 ;
V_26 = F_89 ( & V_6 -> V_4 , V_268 , V_8 ) ;
if ( V_26 )
return V_26 ;
if ( V_268 == V_212 -> V_270 ) {
int V_13 = V_8 ;
bool V_266 ;
if ( V_13 == V_7 -> V_225 )
return 0 ;
V_7 -> V_225 = V_13 ;
if ( V_13 == 0 )
V_266 = F_87 ( V_6 ) ;
else
V_266 = V_13 > 0 ;
if ( V_266 == V_1 -> V_177 )
return 0 ;
V_1 -> V_177 = V_266 ;
goto V_271;
}
if ( V_268 == V_212 -> V_272 ) {
if ( V_8 == ! ! V_1 -> V_273 )
return 0 ;
V_1 -> V_273 = V_8 ? V_274 : 0 ;
goto V_271;
}
#define F_90 ( V_31 , T_8 ) \
if (psb_intel_sdvo_connector->name == property) { \
if (psb_intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (psb_intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
psb_intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_268 == V_7 -> V_265 ) {
if ( V_8 >= V_275 )
return - V_276 ;
if ( V_1 -> V_146 ==
V_7 -> V_277 [ V_8 ] )
return 0 ;
V_1 -> V_146 = V_7 -> V_277 [ V_8 ] ;
goto V_271;
} else if ( F_91 ( V_7 ) ) {
V_269 = V_8 ;
if ( V_7 -> V_248 == V_268 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_249 , V_8 ) ;
if ( V_7 -> V_278 == V_269 )
return 0 ;
V_7 -> V_278 = V_269 ;
V_7 -> V_279 = V_269 ;
V_269 = V_7 -> V_280 -
V_7 -> V_278 ;
V_28 = V_281 ;
goto V_282;
} else if ( V_7 -> V_249 == V_268 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_248 , V_8 ) ;
if ( V_7 -> V_279 == V_269 )
return 0 ;
V_7 -> V_278 = V_269 ;
V_7 -> V_279 = V_269 ;
V_269 = V_7 -> V_280 -
V_7 -> V_278 ;
V_28 = V_281 ;
goto V_282;
} else if ( V_7 -> V_250 == V_268 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_251 , V_8 ) ;
if ( V_7 -> V_283 == V_269 )
return 0 ;
V_7 -> V_283 = V_269 ;
V_7 -> V_284 = V_269 ;
V_269 = V_7 -> V_285 -
V_7 -> V_283 ;
V_28 = V_286 ;
goto V_282;
} else if ( V_7 -> V_251 == V_268 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_250 , V_8 ) ;
if ( V_7 -> V_284 == V_269 )
return 0 ;
V_7 -> V_283 = V_269 ;
V_7 -> V_284 = V_269 ;
V_269 = V_7 -> V_285 -
V_7 -> V_283 ;
V_28 = V_286 ;
goto V_282;
}
F_90 (hpos, HPOS)
F_90 (vpos, VPOS)
F_90 (saturation, SATURATION)
F_90 (contrast, CONTRAST)
F_90 (hue, HUE)
F_90 (brightness, BRIGHTNESS)
F_90 (sharpness, SHARPNESS)
F_90 (flicker_filter, FLICKER_FILTER)
F_90 (flicker_filter_2d, FLICKER_FILTER_2D)
F_90 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_90 (tv_chroma_filter, TV_CHROMA_FILTER)
F_90 (tv_luma_filter, TV_LUMA_FILTER)
F_90 (dot_crawl, DOT_CRAWL)
}
return - V_276 ;
V_282:
if ( ! F_22 ( V_1 , V_28 , & V_269 , 2 ) )
return - V_287 ;
V_271:
if ( V_1 -> V_4 . V_4 . V_155 ) {
struct V_154 * V_155 = V_1 -> V_4 . V_4 . V_155 ;
F_92 ( V_155 , & V_155 -> V_47 , V_155 -> V_288 ,
V_155 -> V_289 , V_155 -> V_290 ) ;
}
return 0 ;
#undef F_90
}
static void F_93 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_291 * V_291 = F_4 ( V_6 ) ;
struct V_1 * V_209 = F_1 ( & V_291 -> V_4 ) ;
V_209 -> V_292 = F_8 ( V_209 -> V_14 ) ;
}
static void F_94 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_2 * V_3 = & F_4 ( V_6 ) -> V_4 ;
struct V_1 * V_209 = F_1 ( V_3 ) ;
struct V_154 * V_155 = V_3 -> V_155 ;
F_9 ( V_209 -> V_14 , V_209 -> V_292 ) ;
if ( V_6 -> V_32 == V_222 )
F_92 ( V_155 , & V_155 -> V_47 , V_155 -> V_288 , V_155 -> V_289 ,
NULL ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_92 != NULL )
F_96 ( V_3 -> V_10 ,
V_1 -> V_92 ) ;
F_97 ( & V_1 -> V_210 ) ;
F_98 ( V_3 ) ;
}
static void
F_99 ( struct V_1 * V_209 )
{
V_209 -> V_48 = 2 ;
#if 0
uint16_t mask = 0;
unsigned int num_bits;
switch (sdvo->controlled_output) {
case SDVO_OUTPUT_LVDS1:
mask |= SDVO_OUTPUT_LVDS1;
case SDVO_OUTPUT_LVDS0:
mask |= SDVO_OUTPUT_LVDS0;
case SDVO_OUTPUT_TMDS1:
mask |= SDVO_OUTPUT_TMDS1;
case SDVO_OUTPUT_TMDS0:
mask |= SDVO_OUTPUT_TMDS0;
case SDVO_OUTPUT_RGB1:
mask |= SDVO_OUTPUT_RGB1;
case SDVO_OUTPUT_RGB0:
mask |= SDVO_OUTPUT_RGB0;
break;
}
mask &= sdvo->caps.output_flags;
num_bits = hweight16(mask);
if (num_bits > 3)
num_bits = 3;
sdvo->ddc_bus = 1 << num_bits;
#endif
}
static void
F_100 ( struct V_211 * V_212 ,
struct V_1 * V_209 , T_1 V_293 )
{
struct V_294 * V_295 ;
if ( F_101 ( V_293 ) )
V_295 = & ( V_212 -> V_296 [ 0 ] ) ;
else
V_295 = & ( V_212 -> V_296 [ 1 ] ) ;
if ( V_295 -> V_297 )
V_209 -> V_48 = 1 << ( ( V_295 -> V_298 & 0xf0 ) >> 4 ) ;
else
F_99 ( V_209 ) ;
}
static void
F_102 ( struct V_211 * V_212 ,
struct V_1 * V_209 , T_1 V_293 )
{
struct V_294 * V_295 ;
T_2 V_299 , V_300 ;
if ( F_101 ( V_293 ) )
V_295 = & V_212 -> V_296 [ 0 ] ;
else
V_295 = & V_212 -> V_296 [ 1 ] ;
V_299 = V_301 ;
V_300 = V_302 >> 8 ;
if ( V_295 -> V_297 ) {
V_299 = V_295 -> V_303 ;
V_300 = V_295 -> V_304 ;
}
if ( V_299 < V_305 ) {
V_209 -> V_27 = & V_212 -> V_214 [ V_299 ] . V_216 ;
F_103 ( V_209 -> V_27 , V_300 ) ;
F_104 ( V_209 -> V_27 , true ) ;
} else
V_209 -> V_27 = & V_212 -> V_214 [ V_301 ] . V_216 ;
}
static bool
F_105 ( struct V_1 * V_1 , int V_306 )
{
return F_39 ( V_1 ) ;
}
static T_2
F_106 ( struct V_9 * V_10 , int V_14 )
{
struct V_211 * V_212 = V_10 -> V_213 ;
struct V_294 * V_307 , * V_308 ;
if ( F_101 ( V_14 ) ) {
V_307 = & V_212 -> V_296 [ 0 ] ;
V_308 = & V_212 -> V_296 [ 1 ] ;
} else {
V_307 = & V_212 -> V_296 [ 1 ] ;
V_308 = & V_212 -> V_296 [ 0 ] ;
}
if ( V_307 -> V_21 )
return V_307 -> V_21 ;
if ( V_308 -> V_21 ) {
if ( V_308 -> V_21 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( F_101 ( V_14 ) )
return 0x70 ;
else
return 0x72 ;
}
static void
F_107 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_108 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_309 ,
V_6 -> V_4 . V_4 . V_310 ) ;
F_109 ( & V_6 -> V_4 . V_4 ,
& V_311 ) ;
V_6 -> V_4 . V_4 . V_312 = 0 ;
V_6 -> V_4 . V_4 . V_313 = 0 ;
V_6 -> V_4 . V_4 . V_314 . V_315 = V_316 ;
F_110 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_111 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_112 ( struct V_7 * V_6 )
{
}
static bool
F_113 ( struct V_1 * V_1 , int V_306 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_317 * V_318 ;
struct V_7 * V_7 ;
V_7 = F_114 ( sizeof( struct V_7 ) , V_319 ) ;
if ( ! V_7 )
return false ;
if ( V_306 == 0 ) {
V_1 -> V_320 |= V_321 ;
V_7 -> V_230 = V_321 ;
} else if ( V_306 == 1 ) {
V_1 -> V_320 |= V_322 ;
V_7 -> V_230 = V_322 ;
}
V_318 = & V_7 -> V_4 ;
V_6 = & V_318 -> V_4 ;
V_3 -> V_323 = V_324 ;
V_6 -> V_310 = V_325 ;
if ( F_105 ( V_1 , V_306 ) ) {
V_6 -> V_310 = V_326 ;
V_1 -> V_223 = true ;
}
V_1 -> V_4 . V_327 = ( ( 1 << V_328 ) |
( 1 << V_329 ) ) ;
F_107 ( V_7 , V_1 ) ;
if ( V_1 -> V_223 )
F_112 ( V_7 ) ;
return true ;
}
static bool
F_115 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_317 * V_318 ;
struct V_7 * V_7 ;
V_7 = F_114 ( sizeof( struct V_7 ) , V_319 ) ;
if ( ! V_7 )
return false ;
V_318 = & V_7 -> V_4 ;
V_6 = & V_318 -> V_4 ;
V_3 -> V_323 = V_330 ;
V_6 -> V_310 = V_331 ;
V_1 -> V_320 |= type ;
V_7 -> V_230 = type ;
V_1 -> V_153 = true ;
V_1 -> V_4 . V_231 = true ;
V_1 -> V_4 . V_327 = 1 << V_332 ;
F_107 ( V_7 , V_1 ) ;
if ( ! F_116 ( V_1 , V_7 , type ) )
goto V_333;
if ( ! F_117 ( V_1 , V_7 ) )
goto V_333;
return true ;
V_333:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_118 ( struct V_1 * V_1 , int V_306 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_317 * V_318 ;
struct V_7 * V_7 ;
V_7 = F_114 ( sizeof( struct V_7 ) , V_319 ) ;
if ( ! V_7 )
return false ;
V_318 = & V_7 -> V_4 ;
V_6 = & V_318 -> V_4 ;
V_6 -> V_334 = V_335 ;
V_3 -> V_323 = V_336 ;
V_6 -> V_310 = V_337 ;
if ( V_306 == 0 ) {
V_1 -> V_320 |= V_338 ;
V_7 -> V_230 = V_338 ;
} else if ( V_306 == 1 ) {
V_1 -> V_320 |= V_339 ;
V_7 -> V_230 = V_339 ;
}
V_1 -> V_4 . V_327 = ( ( 1 << V_328 ) |
( 1 << V_329 ) ) ;
F_107 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_119 ( struct V_1 * V_1 , int V_306 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_317 * V_318 ;
struct V_7 * V_7 ;
V_7 = F_114 ( sizeof( struct V_7 ) , V_319 ) ;
if ( ! V_7 )
return false ;
V_318 = & V_7 -> V_4 ;
V_6 = & V_318 -> V_4 ;
V_3 -> V_323 = V_340 ;
V_6 -> V_310 = V_341 ;
if ( V_306 == 0 ) {
V_1 -> V_320 |= V_342 ;
V_7 -> V_230 = V_342 ;
} else if ( V_306 == 1 ) {
V_1 -> V_320 |= V_343 ;
V_7 -> V_230 = V_343 ;
}
V_1 -> V_4 . V_327 = ( ( 1 << V_329 ) |
( 1 << V_344 ) ) ;
F_107 ( V_7 , V_1 ) ;
if ( ! F_117 ( V_1 , V_7 ) )
goto V_333;
return true ;
V_333:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_120 ( struct V_1 * V_1 , T_4 V_22 )
{
V_1 -> V_153 = false ;
V_1 -> V_4 . V_231 = false ;
V_1 -> V_91 = false ;
if ( V_22 & V_321 )
if ( ! F_113 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_345 ) == V_345 )
if ( ! F_113 ( V_1 , 1 ) )
return false ;
if ( V_22 & V_228 )
if ( ! F_115 ( V_1 , V_228 ) )
return false ;
if ( V_22 & V_229 )
if ( ! F_115 ( V_1 , V_229 ) )
return false ;
if ( V_22 & V_338 )
if ( ! F_118 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_346 ) == V_346 )
if ( ! F_118 ( V_1 , 1 ) )
return false ;
if ( V_22 & V_342 )
if ( ! F_119 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_233 ) == V_233 )
if ( ! F_119 ( V_1 , 1 ) )
return false ;
if ( ( V_22 & V_347 ) == 0 ) {
unsigned char V_348 [ 2 ] ;
V_1 -> V_320 = 0 ;
memcpy ( V_348 , & V_1 -> V_194 . V_207 , 2 ) ;
F_12 ( L_34 ,
F_14 ( V_1 ) ,
V_348 [ 0 ] , V_348 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_349 = ( 1 << 0 ) | ( 1 << 1 ) ;
return true ;
}
static bool F_116 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_143 V_144 ;
T_6 V_145 , V_13 ;
if ( ! F_30 ( V_1 , type ) )
return false ;
F_26 ( sizeof( V_144 ) != 6 ) ;
if ( ! F_23 ( V_1 ,
V_350 ,
& V_144 , sizeof( V_144 ) ) )
return false ;
memcpy ( & V_145 , & V_144 , V_78 ( sizeof( V_145 ) , sizeof( V_144 ) ) ) ;
if ( V_145 == 0 )
return false ;
V_7 -> V_351 = 0 ;
for ( V_13 = 0 ; V_13 < V_275 ; V_13 ++ )
if ( V_145 & ( 1 << V_13 ) )
V_7 -> V_277 [ V_7 -> V_351 ++ ] = V_13 ;
V_7 -> V_265 =
F_121 ( V_10 , V_352 ,
L_35 , V_7 -> V_351 ) ;
if ( ! V_7 -> V_265 )
return false ;
for ( V_13 = 0 ; V_13 < V_7 -> V_351 ; V_13 ++ )
F_122 (
V_7 -> V_265 , V_13 ,
V_13 , V_353 [ V_7 -> V_277 [ V_13 ] ] ) ;
V_1 -> V_146 = V_7 -> V_277 [ 0 ] ;
F_123 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_265 , 0 ) ;
return true ;
}
static bool
F_124 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_354 V_355 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_36 , V_356 [ 2 ] ;
if ( V_355 . V_357 ) {
if ( ! F_23 ( V_1 ,
V_358 ,
& V_356 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_359 ,
& V_36 , 2 ) )
return false ;
V_7 -> V_280 = V_356 [ 0 ] ;
V_7 -> V_278 = V_356 [ 0 ] - V_36 ;
V_7 -> V_279 = V_7 -> V_278 ;
V_7 -> V_248 =
F_125 ( V_10 , 0 , L_36 , 0 , V_356 [ 0 ] ) ;
if ( ! V_7 -> V_248 )
return false ;
F_123 ( & V_6 -> V_4 ,
V_7 -> V_248 ,
V_7 -> V_278 ) ;
V_7 -> V_249 =
F_125 ( V_10 , 0 , L_37 , 0 , V_356 [ 0 ] ) ;
if ( ! V_7 -> V_249 )
return false ;
F_123 ( & V_6 -> V_4 ,
V_7 -> V_249 ,
V_7 -> V_279 ) ;
F_12 ( L_38
L_39 ,
V_356 [ 0 ] , V_356 [ 1 ] , V_36 ) ;
}
if ( V_355 . V_360 ) {
if ( ! F_23 ( V_1 ,
V_361 ,
& V_356 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_362 ,
& V_36 , 2 ) )
return false ;
V_7 -> V_285 = V_356 [ 0 ] ;
V_7 -> V_283 = V_356 [ 0 ] - V_36 ;
V_7 -> V_284 = V_7 -> V_283 ;
V_7 -> V_250 =
F_125 ( V_10 , 0 , L_40 , 0 , V_356 [ 0 ] ) ;
if ( ! V_7 -> V_250 )
return false ;
F_123 ( & V_6 -> V_4 ,
V_7 -> V_250 ,
V_7 -> V_283 ) ;
V_7 -> V_251 =
F_125 ( V_10 , 0 , L_41 , 0 , V_356 [ 0 ] ) ;
if ( ! V_7 -> V_251 )
return false ;
F_123 ( & V_6 -> V_4 ,
V_7 -> V_251 ,
V_7 -> V_284 ) ;
F_12 ( L_42
L_39 ,
V_356 [ 0 ] , V_356 [ 1 ] , V_36 ) ;
}
F_126 ( V_252 , V_363 ) ;
F_126 ( V_253 , V_364 ) ;
F_126 ( V_254 , V_365 ) ;
F_126 ( V_255 , V_366 ) ;
F_126 ( V_256 , V_367 ) ;
F_126 ( V_257 , V_368 ) ;
F_126 ( V_264 , V_369 ) ;
F_126 ( V_258 , V_370 ) ;
F_126 ( V_260 , V_371 ) ;
F_126 ( V_259 , V_372 ) ;
F_126 ( V_262 , V_373 ) ;
F_126 ( V_261 , V_374 ) ;
if ( V_355 . V_263 ) {
if ( ! F_23 ( V_1 , V_375 , & V_36 , 2 ) )
return false ;
V_7 -> V_376 = 1 ;
V_7 -> V_377 = V_36 & 0x1 ;
V_7 -> V_263 =
F_125 ( V_10 , 0 , L_43 , 0 , 1 ) ;
if ( ! V_7 -> V_263 )
return false ;
F_123 ( & V_6 -> V_4 ,
V_7 -> V_263 ,
V_7 -> V_377 ) ;
F_12 ( L_44 , V_36 ) ;
}
return true ;
}
static bool
F_127 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_354 V_355 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_36 , V_356 [ 2 ] ;
F_126 ( V_264 , V_369 ) ;
return true ;
}
static bool F_117 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_354 V_238 ;
T_4 V_36 ;
} V_355 ;
F_26 ( sizeof( V_355 ) != 2 ) ;
V_355 . V_36 = 0 ;
F_23 ( V_1 ,
V_378 ,
& V_355 , sizeof( V_355 ) ) ;
if ( V_355 . V_36 == 0 ) {
F_12 ( L_45 ) ;
return true ;
}
if ( F_80 ( V_7 ) )
return F_124 ( V_1 , V_7 , V_355 . V_238 ) ;
else if( F_81 ( V_7 ) )
return F_127 ( V_1 , V_7 , V_355 . V_238 ) ;
else
return true ;
}
static int F_128 ( struct V_379 * V_216 ,
struct V_19 * V_20 ,
int V_380 )
{
struct V_1 * V_209 = V_216 -> V_381 ;
if ( ! F_21 ( V_209 , V_209 -> V_48 ) )
return - V_287 ;
return V_209 -> V_27 -> V_382 -> V_383 ( V_209 -> V_27 , V_20 , V_380 ) ;
}
static T_1 F_129 ( struct V_379 * V_216 )
{
struct V_1 * V_209 = V_216 -> V_381 ;
return V_209 -> V_27 -> V_382 -> V_384 ( V_209 -> V_27 ) ;
}
static bool
F_130 ( struct V_1 * V_209 ,
struct V_9 * V_10 )
{
V_209 -> V_210 . V_385 = V_386 ;
V_209 -> V_210 . V_387 = V_388 ;
snprintf ( V_209 -> V_210 . V_31 , V_389 , L_46 ) ;
V_209 -> V_210 . V_10 . V_390 = & V_10 -> V_391 -> V_10 ;
V_209 -> V_210 . V_381 = V_209 ;
V_209 -> V_210 . V_382 = & V_392 ;
return F_131 ( & V_209 -> V_210 ) == 0 ;
}
bool F_132 ( struct V_9 * V_10 , int V_14 )
{
struct V_211 * V_212 = V_10 -> V_213 ;
struct V_291 * V_291 ;
struct V_1 * V_1 ;
int V_13 ;
V_1 = F_114 ( sizeof( struct V_1 ) , V_319 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_14 = V_14 ;
V_1 -> V_21 = F_106 ( V_10 , V_14 ) >> 1 ;
F_102 ( V_212 , V_1 , V_14 ) ;
if ( ! F_130 ( V_1 , V_10 ) ) {
F_65 ( V_1 ) ;
return false ;
}
V_291 = & V_1 -> V_4 ;
V_291 -> type = V_393 ;
F_133 ( V_10 , & V_291 -> V_4 , & V_394 , 0 ) ;
for ( V_13 = 0 ; V_13 < 0x40 ; V_13 ++ ) {
T_2 V_395 ;
if ( ! F_10 ( V_1 , V_13 , & V_395 ) ) {
F_12 ( L_47 ,
F_101 ( V_14 ) ? 'B' : 'C' ) ;
goto V_333;
}
}
if ( F_101 ( V_14 ) )
V_212 -> V_396 |= V_397 ;
else
V_212 -> V_396 |= V_398 ;
F_134 ( & V_291 -> V_4 , & V_399 ) ;
if ( ! F_57 ( V_1 , & V_1 -> V_194 ) )
goto V_333;
if ( F_120 ( V_1 ,
V_1 -> V_194 . V_207 ) != true ) {
F_12 ( L_48 ,
F_101 ( V_14 ) ? 'B' : 'C' ) ;
goto V_333;
}
F_100 ( V_212 , V_1 , V_14 ) ;
if ( ! F_24 ( V_1 ) )
goto V_333;
if ( ! F_29 ( V_1 ,
& V_1 -> V_187 ,
& V_1 -> V_189 ) )
goto V_333;
F_12 ( L_49
L_50
L_51
L_52 ,
F_14 ( V_1 ) ,
V_1 -> V_194 . V_196 , V_1 -> V_194 . V_197 ,
V_1 -> V_194 . V_198 ,
V_1 -> V_187 / 1000 ,
V_1 -> V_189 / 1000 ,
( V_1 -> V_194 . V_201 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_194 . V_201 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_194 . V_207 &
( V_321 | V_338 ) ? 'Y' : 'N' ,
V_1 -> V_194 . V_207 &
( V_322 | V_339 ) ? 'Y' : 'N' ) ;
return true ;
V_333:
F_135 ( & V_291 -> V_4 ) ;
F_97 ( & V_1 -> V_210 ) ;
F_65 ( V_1 ) ;
return false ;
}
