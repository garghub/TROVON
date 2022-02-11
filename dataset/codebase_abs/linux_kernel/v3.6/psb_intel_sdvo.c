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
while ( V_32 == V_40 && V_38 -- ) {
F_19 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_35 ,
& V_32 ) )
goto V_39;
}
if ( V_32 <= V_41 )
F_15 ( L_5 , V_42 [ V_32 ] ) ;
else
F_15 ( L_11 , V_32 ) ;
if ( V_32 != V_43 )
goto V_39;
for ( V_13 = 0 ; V_13 < V_37 ; V_13 ++ ) {
if ( ! F_10 ( V_1 ,
V_44 + V_13 ,
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
static int F_20 ( struct V_45 * V_46 )
{
if ( V_46 -> clock >= 100000 )
return 1 ;
else if ( V_46 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_21 ( struct V_1 * V_1 ,
T_2 V_47 )
{
return F_17 ( V_1 ,
V_48 ,
& V_47 , 1 ) ;
}
static bool F_22 ( struct V_1 * V_1 , T_2 V_28 , const void * V_49 , int V_23 )
{
if ( ! F_17 ( V_1 , V_28 , V_49 , V_23 ) )
return false ;
return F_18 ( V_1 , NULL , 0 ) ;
}
static bool
F_23 ( struct V_1 * V_1 , T_2 V_28 , void * V_50 , int V_23 )
{
if ( ! F_17 ( V_1 , V_28 , NULL , 0 ) )
return false ;
return F_18 ( V_1 , V_50 , V_23 ) ;
}
static bool F_24 ( struct V_1 * V_1 )
{
struct V_51 V_52 = { 0 } ;
return F_22 ( V_1 ,
V_53 ,
& V_52 , sizeof( V_52 ) ) ;
}
static bool F_25 ( struct V_1 * V_1 , bool * V_54 , bool * V_55 )
{
struct V_56 V_36 ;
F_26 ( sizeof( V_36 ) != 1 ) ;
if ( ! F_23 ( V_1 , V_57 ,
& V_36 , sizeof( V_36 ) ) )
return false ;
* V_54 = V_36 . V_58 ;
* V_55 = V_36 . V_59 ;
return true ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_3 V_60 )
{
return F_22 ( V_1 ,
V_61 ,
& V_60 , sizeof( V_60 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 ,
int V_46 )
{
T_2 V_62 = V_63 ;
switch ( V_46 ) {
case V_64 :
V_62 = V_63 ;
break;
case V_65 :
V_62 = V_66 ;
break;
case V_67 :
V_62 = V_68 ;
break;
case V_69 :
V_62 = V_70 ;
break;
}
return F_22 ( V_1 ,
V_71 , & V_62 , sizeof( V_62 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 ,
int * V_72 ,
int * V_73 )
{
struct V_74 V_75 ;
F_26 ( sizeof( V_75 ) != 4 ) ;
if ( ! F_23 ( V_1 ,
V_76 ,
& V_75 , sizeof( V_75 ) ) )
return false ;
* V_72 = V_75 . V_77 * 10 ;
* V_73 = V_75 . V_78 * 10 ;
return true ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_3 V_60 )
{
return F_22 ( V_1 ,
V_79 ,
& V_60 , sizeof( V_60 ) ) ;
}
static bool F_31 ( struct V_1 * V_1 , T_2 V_28 ,
struct V_80 * V_81 )
{
return F_22 ( V_1 , V_28 , & V_81 -> V_82 , sizeof( V_81 -> V_82 ) ) &&
F_22 ( V_1 , V_28 + 1 , & V_81 -> V_83 , sizeof( V_81 -> V_83 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_80 * V_81 )
{
return F_31 ( V_1 ,
V_84 , V_81 ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
struct V_80 * V_81 )
{
return F_31 ( V_1 ,
V_85 , V_81 ) ;
}
static bool
F_34 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_86 ,
T_4 V_87 )
{
struct V_88 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_86 = V_86 ;
args . V_87 = V_87 ;
args . V_89 = 0 ;
if ( V_1 -> V_90 &&
( V_1 -> V_91 -> V_92 != V_86 ||
V_1 -> V_91 -> V_93 != V_87 ) )
args . V_94 = 1 ;
return F_22 ( V_1 ,
V_95 ,
& args , sizeof( args ) ) ;
}
static bool F_35 ( struct V_1 * V_1 ,
struct V_80 * V_81 )
{
F_26 ( sizeof( V_81 -> V_82 ) != 8 ) ;
F_26 ( sizeof( V_81 -> V_83 ) != 8 ) ;
return F_23 ( V_1 , V_96 ,
& V_81 -> V_82 , sizeof( V_81 -> V_82 ) ) &&
F_23 ( V_1 , V_97 ,
& V_81 -> V_83 , sizeof( V_81 -> V_83 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_22 ( V_1 , V_98 , & V_8 , 1 ) ;
}
static void F_37 ( struct V_80 * V_81 ,
const struct V_45 * V_46 )
{
T_4 V_86 , V_87 ;
T_4 V_99 , V_100 , V_101 , V_102 ;
T_4 V_103 , V_104 ;
V_86 = V_46 -> V_105 ;
V_87 = V_46 -> V_106 ;
V_99 = V_46 -> V_107 - V_46 -> V_108 ;
V_100 = V_46 -> V_109 - V_46 -> V_110 ;
V_101 = V_46 -> V_111 - V_46 -> V_112 ;
V_102 = V_46 -> V_113 - V_46 -> V_114 ;
V_103 = V_46 -> V_110 - V_46 -> V_108 ;
V_104 = V_46 -> V_114 - V_46 -> V_112 ;
V_81 -> V_82 . clock = V_46 -> clock / 10 ;
V_81 -> V_82 . V_115 = V_86 & 0xff ;
V_81 -> V_82 . V_116 = V_99 & 0xff ;
V_81 -> V_82 . V_117 = ( ( ( V_86 >> 8 ) & 0xf ) << 4 ) |
( ( V_99 >> 8 ) & 0xf ) ;
V_81 -> V_82 . V_118 = V_87 & 0xff ;
V_81 -> V_82 . V_119 = V_101 & 0xff ;
V_81 -> V_82 . V_120 = ( ( ( V_87 >> 8 ) & 0xf ) << 4 ) |
( ( V_101 >> 8 ) & 0xf ) ;
V_81 -> V_83 . V_121 = V_103 & 0xff ;
V_81 -> V_83 . V_122 = V_100 & 0xff ;
V_81 -> V_83 . V_123 = ( V_104 & 0xf ) << 4 |
( V_102 & 0xf ) ;
V_81 -> V_83 . V_124 = ( ( V_103 & 0x300 ) >> 2 ) |
( ( V_100 & 0x300 ) >> 4 ) | ( ( V_104 & 0x30 ) >> 2 ) |
( ( V_102 & 0x30 ) >> 4 ) ;
V_81 -> V_83 . V_125 = 0x18 ;
if ( V_46 -> V_22 & V_126 )
V_81 -> V_83 . V_125 |= 0x2 ;
if ( V_46 -> V_22 & V_127 )
V_81 -> V_83 . V_125 |= 0x4 ;
V_81 -> V_83 . V_128 = 0 ;
V_81 -> V_83 . V_129 = V_104 & 0xc0 ;
V_81 -> V_83 . V_130 = 0 ;
}
static void F_38 ( struct V_45 * V_46 ,
const struct V_80 * V_81 )
{
V_46 -> V_92 = V_81 -> V_82 . V_115 ;
V_46 -> V_92 += ( ( V_81 -> V_82 . V_117 >> 4 ) & 0x0f ) << 8 ;
V_46 -> V_131 = V_46 -> V_92 + V_81 -> V_83 . V_121 ;
V_46 -> V_131 += ( V_81 -> V_83 . V_124 & 0xc0 ) << 2 ;
V_46 -> V_132 = V_46 -> V_131 + V_81 -> V_83 . V_122 ;
V_46 -> V_132 += ( V_81 -> V_83 . V_124 & 0x30 ) << 4 ;
V_46 -> V_133 = V_46 -> V_92 + V_81 -> V_82 . V_116 ;
V_46 -> V_133 += ( V_81 -> V_82 . V_117 & 0xf ) << 8 ;
V_46 -> V_93 = V_81 -> V_82 . V_118 ;
V_46 -> V_93 += ( ( V_81 -> V_82 . V_120 >> 4 ) & 0x0f ) << 8 ;
V_46 -> V_134 = V_46 -> V_93 ;
V_46 -> V_134 += ( V_81 -> V_83 . V_123 >> 4 ) & 0xf ;
V_46 -> V_134 += ( V_81 -> V_83 . V_124 & 0x0c ) << 2 ;
V_46 -> V_134 += V_81 -> V_83 . V_129 & 0xc0 ;
V_46 -> V_135 = V_46 -> V_134 +
( V_81 -> V_83 . V_123 & 0xf ) ;
V_46 -> V_135 += ( V_81 -> V_83 . V_124 & 0x3 ) << 4 ;
V_46 -> V_136 = V_46 -> V_93 + V_81 -> V_82 . V_119 ;
V_46 -> V_136 += ( V_81 -> V_82 . V_120 & 0xf ) << 8 ;
V_46 -> clock = V_81 -> V_82 . clock * 10 ;
V_46 -> V_22 &= ~ ( V_126 | V_127 ) ;
if ( V_81 -> V_83 . V_125 & 0x2 )
V_46 -> V_22 |= V_126 ;
if ( V_81 -> V_83 . V_125 & 0x4 )
V_46 -> V_22 |= V_127 ;
}
static bool F_39 ( struct V_1 * V_1 )
{
struct V_137 V_138 ;
F_26 ( sizeof( V_138 ) != 2 ) ;
return F_23 ( V_1 ,
V_139 ,
& V_138 , sizeof( V_138 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_5 V_46 )
{
return F_22 ( V_1 , V_140 , & V_46 , 1 ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_5 V_46 )
{
return F_22 ( V_1 , V_141 , & V_46 , 1 ) ;
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
struct V_142 V_143 ;
T_6 V_144 ;
V_144 = 1 << V_1 -> V_145 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
memcpy ( & V_143 , & V_144 , V_77 ( sizeof( V_143 ) , sizeof( V_144 ) ) ) ;
F_26 ( sizeof( V_143 ) != 6 ) ;
return F_22 ( V_1 ,
V_146 ,
& V_143 , sizeof( V_143 ) ) ;
}
static bool
F_45 ( struct V_1 * V_1 ,
const struct V_45 * V_46 )
{
struct V_80 V_147 ;
if ( ! F_30 ( V_1 ,
V_1 -> V_148 ) )
return false ;
F_37 ( & V_147 , V_46 ) ;
if ( ! F_33 ( V_1 , & V_147 ) )
return false ;
return true ;
}
static bool
F_46 ( struct V_1 * V_1 ,
const struct V_45 * V_46 ,
struct V_45 * V_149 )
{
if ( ! F_24 ( V_1 ) )
return false ;
if ( ! F_34 ( V_1 ,
V_46 -> clock / 10 ,
V_46 -> V_92 ,
V_46 -> V_93 ) )
return false ;
if ( ! F_35 ( V_1 ,
& V_1 -> V_150 ) )
return false ;
F_38 ( V_149 , & V_1 -> V_150 ) ;
F_47 ( V_149 , 0 ) ;
return true ;
}
static bool F_48 ( struct V_2 * V_3 ,
const struct V_45 * V_46 ,
struct V_45 * V_149 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_151 ;
if ( V_1 -> V_152 ) {
if ( ! F_45 ( V_1 , V_46 ) )
return false ;
( void ) F_46 ( V_1 ,
V_46 ,
V_149 ) ;
} else if ( V_1 -> V_90 ) {
if ( ! F_45 ( V_1 ,
V_1 -> V_91 ) )
return false ;
( void ) F_46 ( V_1 ,
V_46 ,
V_149 ) ;
}
V_151 = F_20 ( V_149 ) ;
F_49 ( V_149 , V_151 ) ;
return true ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_45 * V_46 ,
struct V_45 * V_149 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_153 * V_154 = V_3 -> V_154 ;
struct V_155 * V_155 = F_51 ( V_154 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_156 ;
struct V_157 V_158 ;
struct V_80 V_150 ;
int V_159 = F_52 ( V_149 ) ;
int V_160 ;
if ( ! V_46 )
return;
V_158 . V_161 = V_1 -> V_148 ;
V_158 . V_162 = 0 ;
F_22 ( V_1 ,
V_163 ,
& V_158 , sizeof( V_158 ) ) ;
if ( ! F_30 ( V_1 ,
V_1 -> V_148 ) )
return;
if ( V_1 -> V_152 || V_1 -> V_90 ) {
V_150 = V_1 -> V_150 ;
} else {
if ( ! F_30 ( V_1 ,
V_1 -> V_148 ) )
return;
F_37 ( & V_150 , V_149 ) ;
( void ) F_33 ( V_1 , & V_150 ) ;
}
if ( ! F_24 ( V_1 ) )
return;
if ( V_1 -> V_164 ) {
F_40 ( V_1 , V_165 ) ;
F_41 ( V_1 ,
V_166 ) ;
F_42 ( V_1 ) ;
} else
F_40 ( V_1 , V_167 ) ;
if ( V_1 -> V_152 &&
! F_44 ( V_1 ) )
return;
( void ) F_32 ( V_1 , & V_150 ) ;
switch ( V_159 ) {
default:
case 1 : V_160 = V_168 ; break;
case 2 : V_160 = V_169 ; break;
case 4 : V_160 = V_170 ; break;
}
if ( ! F_36 ( V_1 , V_160 ) )
return;
V_156 = F_8 ( V_1 -> V_14 ) ;
switch ( V_1 -> V_14 ) {
case V_15 :
V_156 &= V_171 ;
break;
case V_16 :
V_156 &= V_172 ;
break;
}
V_156 |= ( 9 << 19 ) | V_173 ;
if ( V_155 -> V_174 == 1 )
V_156 |= V_175 ;
if ( V_1 -> V_176 )
V_156 |= V_177 ;
if ( V_150 . V_83 . V_128 & V_178 )
V_156 |= V_179 ;
F_7 ( V_1 , V_156 ) ;
}
static void F_53 ( struct V_2 * V_3 , int V_46 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_180 ;
switch ( V_46 ) {
case V_64 :
F_54 ( L_15 ) ;
break;
case V_69 :
F_54 ( L_16 ) ;
break;
default:
F_54 ( L_17 , V_46 ) ;
}
if ( V_46 != V_64 ) {
F_27 ( V_1 , 0 ) ;
if ( 0 )
F_28 ( V_1 , V_46 ) ;
if ( V_46 == V_69 ) {
V_180 = F_8 ( V_1 -> V_14 ) ;
if ( ( V_180 & V_181 ) != 0 ) {
F_7 ( V_1 , V_180 & ~ V_181 ) ;
}
}
} else {
bool V_182 , V_183 ;
int V_13 ;
T_2 V_32 ;
V_180 = F_8 ( V_1 -> V_14 ) ;
if ( ( V_180 & V_181 ) == 0 )
F_7 ( V_1 , V_180 | V_181 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
F_55 ( V_10 ) ;
V_32 = F_25 ( V_1 , & V_182 , & V_183 ) ;
if ( V_32 == V_43 && ! V_182 ) {
F_12 ( L_18
L_19 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_28 ( V_1 , V_46 ) ;
F_27 ( V_1 , V_1 -> V_148 ) ;
}
return;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_46 -> V_22 & V_184 )
return V_185 ;
if ( V_1 -> V_186 > V_46 -> clock )
return V_187 ;
if ( V_1 -> V_188 < V_46 -> clock )
return V_189 ;
if ( V_1 -> V_90 ) {
if ( V_46 -> V_92 > V_1 -> V_91 -> V_92 )
return V_190 ;
if ( V_46 -> V_93 > V_1 -> V_91 -> V_93 )
return V_190 ;
}
return V_191 ;
}
static bool F_57 ( struct V_1 * V_1 , struct V_192 * V_193 )
{
F_26 ( sizeof( * V_193 ) != 8 ) ;
if ( ! F_23 ( V_1 ,
V_194 ,
V_193 , sizeof( * V_193 ) ) )
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
V_193 -> V_195 ,
V_193 -> V_196 ,
V_193 -> V_197 ,
V_193 -> V_198 ,
V_193 -> V_199 ,
V_193 -> V_200 ,
V_193 -> V_201 ,
V_193 -> V_202 ,
V_193 -> V_203 ,
V_193 -> V_204 ,
V_193 -> V_205 ,
V_193 -> V_206 ) ;
return true ;
}
static bool
F_58 ( struct V_1 * V_1 )
{
int V_193 = V_1 -> V_193 . V_206 & 0xf ;
return V_193 & - V_193 ;
}
static struct V_207 *
F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_208 = F_3 ( V_6 ) ;
return F_60 ( V_6 , & V_208 -> V_209 ) ;
}
static struct V_207 *
F_61 ( struct V_5 * V_6 )
{
struct V_210 * V_211 = V_6 -> V_10 -> V_212 ;
return F_60 ( V_6 ,
& V_211 -> V_213 [ V_211 -> V_214 ] . V_215 ) ;
return NULL ;
}
static enum V_216
F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_216 V_32 ;
struct V_207 * V_207 ;
V_207 = F_59 ( V_6 ) ;
if ( V_207 == NULL && F_58 ( V_1 ) ) {
T_2 V_209 , V_217 = V_1 -> V_47 ;
for ( V_209 = V_1 -> V_47 >> 1 ; V_209 > 1 ; V_209 >>= 1 ) {
V_1 -> V_47 = V_209 ;
V_207 = F_59 ( V_6 ) ;
if ( V_207 )
break;
}
if ( V_207 == NULL )
V_1 -> V_47 = V_217 ;
}
if ( V_207 == NULL )
V_207 = F_61 ( V_6 ) ;
V_32 = V_218 ;
if ( V_207 != NULL ) {
if ( V_207 -> V_219 & V_220 ) {
V_32 = V_221 ;
if ( V_1 -> V_222 ) {
V_1 -> V_164 = F_63 ( V_207 ) ;
V_1 -> V_176 = F_64 ( V_207 ) ;
}
} else
V_32 = V_223 ;
V_6 -> V_224 . V_225 = NULL ;
F_65 ( V_207 ) ;
}
if ( V_32 == V_221 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_226 )
V_1 -> V_176 = V_7 -> V_226 > 0 ;
}
return V_32 ;
}
static enum V_216
F_66 ( struct V_5 * V_6 , bool V_227 )
{
T_4 V_36 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_216 V_26 ;
if ( ! F_17 ( V_1 ,
V_228 , NULL , 0 ) )
return V_218 ;
if ( V_1 -> V_193 . V_206 &
( V_229 | V_230 ) )
F_67 ( 30 ) ;
if ( ! F_18 ( V_1 , & V_36 , 2 ) )
return V_218 ;
F_12 ( L_33 ,
V_36 & 0xff , V_36 >> 8 ,
V_7 -> V_231 ) ;
if ( V_36 == 0 )
return V_223 ;
V_1 -> V_148 = V_36 ;
V_1 -> V_164 = false ;
V_1 -> V_176 = false ;
if ( ( V_7 -> V_231 & V_36 ) == 0 )
V_26 = V_223 ;
else if ( F_68 ( V_7 ) )
V_26 = F_62 ( V_6 ) ;
else {
struct V_207 * V_207 ;
V_207 = F_59 ( V_6 ) ;
if ( V_207 == NULL )
V_207 = F_61 ( V_6 ) ;
if ( V_207 != NULL ) {
if ( V_207 -> V_219 & V_220 )
V_26 = V_223 ;
else
V_26 = V_221 ;
V_6 -> V_224 . V_225 = NULL ;
F_65 ( V_207 ) ;
} else
V_26 = V_221 ;
}
if ( V_26 == V_221 ) {
V_1 -> V_152 = false ;
V_1 -> V_90 = false ;
V_1 -> V_4 . V_232 = false ;
if ( V_36 & V_233 ) {
V_1 -> V_152 = true ;
V_1 -> V_4 . V_232 = true ;
}
if ( V_36 & V_234 )
V_1 -> V_90 = V_1 -> V_91 != NULL ;
}
return V_26 ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_207 * V_207 ;
V_207 = F_59 ( V_6 ) ;
if ( V_207 == NULL )
V_207 = F_61 ( V_6 ) ;
if ( V_207 != NULL ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
bool V_235 = ! ! ( V_207 -> V_219 & V_220 ) ;
bool V_236 = ! ! F_68 ( V_7 ) ;
if ( V_236 == V_235 ) {
F_70 ( V_6 , V_207 ) ;
F_71 ( V_6 , V_207 ) ;
}
V_6 -> V_224 . V_225 = NULL ;
F_65 ( V_207 ) ;
}
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_237 V_238 ;
T_6 V_239 = 0 , V_144 = 0 ;
int V_13 ;
V_144 = 1 << V_1 -> V_145 ;
memcpy ( & V_238 , & V_144 ,
V_77 ( sizeof( V_144 ) , sizeof( struct V_237 ) ) ) ;
if ( ! F_30 ( V_1 , V_1 -> V_148 ) )
return;
F_26 ( sizeof( V_238 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_240 ,
& V_238 , sizeof( V_238 ) ) )
return;
if ( ! F_18 ( V_1 , & V_239 , 3 ) )
return;
for ( V_13 = 0 ; V_13 < F_16 ( V_241 ) ; V_13 ++ )
if ( V_239 & ( 1 << V_13 ) ) {
struct V_45 * V_242 ;
V_242 = F_73 ( V_6 -> V_10 ,
& V_241 [ V_13 ] ) ;
if ( V_242 )
F_74 ( V_6 , V_242 ) ;
}
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_210 * V_211 = V_6 -> V_10 -> V_212 ;
struct V_45 * V_243 ;
F_76 ( V_6 , V_1 -> V_27 ) ;
if ( F_77 ( & V_6 -> V_244 ) == false )
goto V_245;
if ( V_211 -> V_246 != NULL ) {
V_243 = F_73 ( V_6 -> V_10 ,
V_211 -> V_246 ) ;
if ( V_243 != NULL ) {
V_243 -> type = ( V_247 |
V_248 ) ;
F_74 ( V_6 , V_243 ) ;
}
}
V_245:
F_78 (newmode, &connector->probed_modes, head) {
if ( V_243 -> type & V_247 ) {
V_1 -> V_91 =
F_73 ( V_6 -> V_10 , V_243 ) ;
F_47 ( V_1 -> V_91 ,
0 ) ;
V_1 -> V_90 = true ;
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
return ! F_77 ( & V_6 -> V_244 ) ;
}
static void
F_82 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
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
if ( V_7 -> V_265 )
F_83 ( V_10 , V_7 -> V_265 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_266 )
F_83 ( V_6 -> V_10 ,
V_7 -> V_266 ) ;
F_82 ( V_6 ) ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_65 ( V_6 ) ;
}
static bool F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_207 * V_207 ;
bool V_267 = false ;
if ( ! V_1 -> V_222 )
return false ;
V_207 = F_59 ( V_6 ) ;
if ( V_207 != NULL && V_207 -> V_219 & V_220 )
V_267 = F_64 ( V_207 ) ;
return V_267 ;
}
static int
F_88 ( struct V_5 * V_6 ,
struct V_268 * V_269 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_210 * V_211 = V_6 -> V_10 -> V_212 ;
T_4 V_270 ;
T_5 V_28 ;
int V_26 ;
V_26 = F_89 ( V_6 , V_269 , V_8 ) ;
if ( V_26 )
return V_26 ;
if ( V_269 == V_211 -> V_271 ) {
int V_13 = V_8 ;
bool V_267 ;
if ( V_13 == V_7 -> V_226 )
return 0 ;
V_7 -> V_226 = V_13 ;
if ( V_13 == 0 )
V_267 = F_87 ( V_6 ) ;
else
V_267 = V_13 > 0 ;
if ( V_267 == V_1 -> V_176 )
return 0 ;
V_1 -> V_176 = V_267 ;
goto V_272;
}
if ( V_269 == V_211 -> V_273 ) {
if ( V_8 == ! ! V_1 -> V_274 )
return 0 ;
V_1 -> V_274 = V_8 ? V_275 : 0 ;
goto V_272;
}
#define F_90 ( V_31 , T_8 ) \
if (psb_intel_sdvo_connector->name == property) { \
if (psb_intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (psb_intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
psb_intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_269 == V_7 -> V_266 ) {
if ( V_8 >= V_276 )
return - V_277 ;
if ( V_1 -> V_145 ==
V_7 -> V_278 [ V_8 ] )
return 0 ;
V_1 -> V_145 = V_7 -> V_278 [ V_8 ] ;
goto V_272;
} else if ( F_91 ( V_7 ) ) {
V_270 = V_8 ;
if ( V_7 -> V_249 == V_269 ) {
F_89 ( V_6 ,
V_7 -> V_250 , V_8 ) ;
if ( V_7 -> V_279 == V_270 )
return 0 ;
V_7 -> V_279 = V_270 ;
V_7 -> V_280 = V_270 ;
V_270 = V_7 -> V_281 -
V_7 -> V_279 ;
V_28 = V_282 ;
goto V_283;
} else if ( V_7 -> V_250 == V_269 ) {
F_89 ( V_6 ,
V_7 -> V_249 , V_8 ) ;
if ( V_7 -> V_280 == V_270 )
return 0 ;
V_7 -> V_279 = V_270 ;
V_7 -> V_280 = V_270 ;
V_270 = V_7 -> V_281 -
V_7 -> V_279 ;
V_28 = V_282 ;
goto V_283;
} else if ( V_7 -> V_251 == V_269 ) {
F_89 ( V_6 ,
V_7 -> V_252 , V_8 ) ;
if ( V_7 -> V_284 == V_270 )
return 0 ;
V_7 -> V_284 = V_270 ;
V_7 -> V_285 = V_270 ;
V_270 = V_7 -> V_286 -
V_7 -> V_284 ;
V_28 = V_287 ;
goto V_283;
} else if ( V_7 -> V_252 == V_269 ) {
F_89 ( V_6 ,
V_7 -> V_251 , V_8 ) ;
if ( V_7 -> V_285 == V_270 )
return 0 ;
V_7 -> V_284 = V_270 ;
V_7 -> V_285 = V_270 ;
V_270 = V_7 -> V_286 -
V_7 -> V_284 ;
V_28 = V_287 ;
goto V_283;
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
return - V_277 ;
V_283:
if ( ! F_22 ( V_1 , V_28 , & V_270 , 2 ) )
return - V_288 ;
V_272:
if ( V_1 -> V_4 . V_4 . V_154 ) {
struct V_153 * V_154 = V_1 -> V_4 . V_4 . V_154 ;
F_92 ( V_154 , & V_154 -> V_46 , V_154 -> V_289 ,
V_154 -> V_290 , V_154 -> V_291 ) ;
}
return 0 ;
#undef F_90
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_91 != NULL )
F_94 ( V_3 -> V_10 ,
V_1 -> V_91 ) ;
F_95 ( & V_1 -> V_209 ) ;
F_96 ( V_3 ) ;
}
static void
F_97 ( struct V_1 * V_208 )
{
V_208 -> V_47 = 2 ;
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
F_98 ( struct V_210 * V_211 ,
struct V_1 * V_208 , T_1 V_292 )
{
struct V_293 * V_294 ;
if ( F_99 ( V_292 ) )
V_294 = & ( V_211 -> V_295 [ 0 ] ) ;
else
V_294 = & ( V_211 -> V_295 [ 1 ] ) ;
if ( V_294 -> V_296 )
V_208 -> V_47 = 1 << ( ( V_294 -> V_297 & 0xf0 ) >> 4 ) ;
else
F_97 ( V_208 ) ;
}
static void
F_100 ( struct V_210 * V_211 ,
struct V_1 * V_208 , T_1 V_292 )
{
struct V_293 * V_294 ;
T_2 V_298 , V_299 ;
if ( F_99 ( V_292 ) )
V_294 = & V_211 -> V_295 [ 0 ] ;
else
V_294 = & V_211 -> V_295 [ 1 ] ;
V_298 = V_300 ;
V_299 = V_301 >> 8 ;
if ( V_294 -> V_296 ) {
V_298 = V_294 -> V_302 ;
V_299 = V_294 -> V_303 ;
}
if ( V_298 < V_304 ) {
V_208 -> V_27 = & V_211 -> V_213 [ V_298 ] . V_215 ;
F_101 ( V_208 -> V_27 , V_299 ) ;
F_102 ( V_208 -> V_27 , true ) ;
} else
V_208 -> V_27 = & V_211 -> V_213 [ V_300 ] . V_215 ;
}
static bool
F_103 ( struct V_1 * V_1 , int V_305 )
{
return F_39 ( V_1 ) ;
}
static T_2
F_104 ( struct V_9 * V_10 , int V_14 )
{
struct V_210 * V_211 = V_10 -> V_212 ;
struct V_293 * V_306 , * V_307 ;
if ( F_99 ( V_14 ) ) {
V_306 = & V_211 -> V_295 [ 0 ] ;
V_307 = & V_211 -> V_295 [ 1 ] ;
} else {
V_306 = & V_211 -> V_295 [ 1 ] ;
V_307 = & V_211 -> V_295 [ 0 ] ;
}
if ( V_306 -> V_21 )
return V_306 -> V_21 ;
if ( V_307 -> V_21 ) {
if ( V_307 -> V_21 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( F_99 ( V_14 ) )
return 0x70 ;
else
return 0x72 ;
}
static void
F_105 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_106 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_308 ,
V_6 -> V_4 . V_4 . V_309 ) ;
F_107 ( & V_6 -> V_4 . V_4 ,
& V_310 ) ;
V_6 -> V_4 . V_4 . V_311 = 0 ;
V_6 -> V_4 . V_4 . V_312 = 0 ;
V_6 -> V_4 . V_4 . V_224 . V_313 = V_314 ;
F_108 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_109 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_110 ( struct V_7 * V_6 )
{
}
static bool
F_111 ( struct V_1 * V_1 , int V_305 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_315 * V_316 ;
struct V_7 * V_7 ;
V_7 = F_112 ( sizeof( struct V_7 ) , V_317 ) ;
if ( ! V_7 )
return false ;
if ( V_305 == 0 ) {
V_1 -> V_318 |= V_319 ;
V_7 -> V_231 = V_319 ;
} else if ( V_305 == 1 ) {
V_1 -> V_318 |= V_320 ;
V_7 -> V_231 = V_320 ;
}
V_316 = & V_7 -> V_4 ;
V_6 = & V_316 -> V_4 ;
V_3 -> V_321 = V_322 ;
V_6 -> V_309 = V_323 ;
if ( F_103 ( V_1 , V_305 ) ) {
V_6 -> V_309 = V_324 ;
V_1 -> V_222 = true ;
}
V_1 -> V_4 . V_325 = ( ( 1 << V_326 ) |
( 1 << V_327 ) ) ;
F_105 ( V_7 , V_1 ) ;
if ( V_1 -> V_222 )
F_110 ( V_7 ) ;
return true ;
}
static bool
F_113 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_315 * V_316 ;
struct V_7 * V_7 ;
V_7 = F_112 ( sizeof( struct V_7 ) , V_317 ) ;
if ( ! V_7 )
return false ;
V_316 = & V_7 -> V_4 ;
V_6 = & V_316 -> V_4 ;
V_3 -> V_321 = V_328 ;
V_6 -> V_309 = V_329 ;
V_1 -> V_318 |= type ;
V_7 -> V_231 = type ;
V_1 -> V_152 = true ;
V_1 -> V_4 . V_232 = true ;
V_1 -> V_4 . V_325 = 1 << V_330 ;
F_105 ( V_7 , V_1 ) ;
if ( ! F_114 ( V_1 , V_7 , type ) )
goto V_331;
if ( ! F_115 ( V_1 , V_7 ) )
goto V_331;
return true ;
V_331:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_116 ( struct V_1 * V_1 , int V_305 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_315 * V_316 ;
struct V_7 * V_7 ;
V_7 = F_112 ( sizeof( struct V_7 ) , V_317 ) ;
if ( ! V_7 )
return false ;
V_316 = & V_7 -> V_4 ;
V_6 = & V_316 -> V_4 ;
V_6 -> V_332 = V_333 ;
V_3 -> V_321 = V_334 ;
V_6 -> V_309 = V_335 ;
if ( V_305 == 0 ) {
V_1 -> V_318 |= V_336 ;
V_7 -> V_231 = V_336 ;
} else if ( V_305 == 1 ) {
V_1 -> V_318 |= V_337 ;
V_7 -> V_231 = V_337 ;
}
V_1 -> V_4 . V_325 = ( ( 1 << V_326 ) |
( 1 << V_327 ) ) ;
F_105 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_117 ( struct V_1 * V_1 , int V_305 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_315 * V_316 ;
struct V_7 * V_7 ;
V_7 = F_112 ( sizeof( struct V_7 ) , V_317 ) ;
if ( ! V_7 )
return false ;
V_316 = & V_7 -> V_4 ;
V_6 = & V_316 -> V_4 ;
V_3 -> V_321 = V_338 ;
V_6 -> V_309 = V_339 ;
if ( V_305 == 0 ) {
V_1 -> V_318 |= V_340 ;
V_7 -> V_231 = V_340 ;
} else if ( V_305 == 1 ) {
V_1 -> V_318 |= V_341 ;
V_7 -> V_231 = V_341 ;
}
V_1 -> V_4 . V_325 = ( ( 1 << V_327 ) |
( 1 << V_342 ) ) ;
F_105 ( V_7 , V_1 ) ;
if ( ! F_115 ( V_1 , V_7 ) )
goto V_331;
return true ;
V_331:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_118 ( struct V_1 * V_1 , T_4 V_22 )
{
V_1 -> V_152 = false ;
V_1 -> V_4 . V_232 = false ;
V_1 -> V_90 = false ;
if ( V_22 & V_319 )
if ( ! F_111 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_343 ) == V_343 )
if ( ! F_111 ( V_1 , 1 ) )
return false ;
if ( V_22 & V_229 )
if ( ! F_113 ( V_1 , V_229 ) )
return false ;
if ( V_22 & V_230 )
if ( ! F_113 ( V_1 , V_230 ) )
return false ;
if ( V_22 & V_336 )
if ( ! F_116 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_344 ) == V_344 )
if ( ! F_116 ( V_1 , 1 ) )
return false ;
if ( V_22 & V_340 )
if ( ! F_117 ( V_1 , 0 ) )
return false ;
if ( ( V_22 & V_234 ) == V_234 )
if ( ! F_117 ( V_1 , 1 ) )
return false ;
if ( ( V_22 & V_345 ) == 0 ) {
unsigned char V_346 [ 2 ] ;
V_1 -> V_318 = 0 ;
memcpy ( V_346 , & V_1 -> V_193 . V_206 , 2 ) ;
F_12 ( L_34 ,
F_14 ( V_1 ) ,
V_346 [ 0 ] , V_346 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_347 = ( 1 << 0 ) | ( 1 << 1 ) ;
return true ;
}
static bool F_114 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_142 V_143 ;
T_6 V_144 , V_13 ;
if ( ! F_30 ( V_1 , type ) )
return false ;
F_26 ( sizeof( V_143 ) != 6 ) ;
if ( ! F_23 ( V_1 ,
V_348 ,
& V_143 , sizeof( V_143 ) ) )
return false ;
memcpy ( & V_144 , & V_143 , V_77 ( sizeof( V_144 ) , sizeof( V_143 ) ) ) ;
if ( V_144 == 0 )
return false ;
V_7 -> V_349 = 0 ;
for ( V_13 = 0 ; V_13 < V_276 ; V_13 ++ )
if ( V_144 & ( 1 << V_13 ) )
V_7 -> V_278 [ V_7 -> V_349 ++ ] = V_13 ;
V_7 -> V_266 =
F_119 ( V_10 , V_350 ,
L_35 , V_7 -> V_349 ) ;
if ( ! V_7 -> V_266 )
return false ;
for ( V_13 = 0 ; V_13 < V_7 -> V_349 ; V_13 ++ )
F_120 (
V_7 -> V_266 , V_13 ,
V_13 , V_351 [ V_7 -> V_278 [ V_13 ] ] ) ;
V_1 -> V_145 = V_7 -> V_278 [ 0 ] ;
F_121 ( & V_7 -> V_4 . V_4 ,
V_7 -> V_266 , 0 ) ;
return true ;
}
static bool
F_122 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_352 V_353 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_36 , V_354 [ 2 ] ;
if ( V_353 . V_355 ) {
if ( ! F_23 ( V_1 ,
V_356 ,
& V_354 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_357 ,
& V_36 , 2 ) )
return false ;
V_7 -> V_281 = V_354 [ 0 ] ;
V_7 -> V_279 = V_354 [ 0 ] - V_36 ;
V_7 -> V_280 = V_7 -> V_279 ;
V_7 -> V_249 =
F_123 ( V_10 , 0 , L_36 , 0 , V_354 [ 0 ] ) ;
if ( ! V_7 -> V_249 )
return false ;
F_121 ( V_6 ,
V_7 -> V_249 ,
V_7 -> V_279 ) ;
V_7 -> V_250 =
F_123 ( V_10 , 0 , L_37 , 0 , V_354 [ 0 ] ) ;
if ( ! V_7 -> V_250 )
return false ;
F_121 ( V_6 ,
V_7 -> V_250 ,
V_7 -> V_280 ) ;
F_12 ( L_38
L_39 ,
V_354 [ 0 ] , V_354 [ 1 ] , V_36 ) ;
}
if ( V_353 . V_358 ) {
if ( ! F_23 ( V_1 ,
V_359 ,
& V_354 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_360 ,
& V_36 , 2 ) )
return false ;
V_7 -> V_286 = V_354 [ 0 ] ;
V_7 -> V_284 = V_354 [ 0 ] - V_36 ;
V_7 -> V_285 = V_7 -> V_284 ;
V_7 -> V_251 =
F_123 ( V_10 , 0 , L_40 , 0 , V_354 [ 0 ] ) ;
if ( ! V_7 -> V_251 )
return false ;
F_121 ( V_6 ,
V_7 -> V_251 ,
V_7 -> V_284 ) ;
V_7 -> V_252 =
F_123 ( V_10 , 0 , L_41 , 0 , V_354 [ 0 ] ) ;
if ( ! V_7 -> V_252 )
return false ;
F_121 ( V_6 ,
V_7 -> V_252 ,
V_7 -> V_285 ) ;
F_12 ( L_42
L_39 ,
V_354 [ 0 ] , V_354 [ 1 ] , V_36 ) ;
}
F_124 ( V_253 , V_361 ) ;
F_124 ( V_254 , V_362 ) ;
F_124 ( V_255 , V_363 ) ;
F_124 ( V_256 , V_364 ) ;
F_124 ( V_257 , V_365 ) ;
F_124 ( V_258 , V_366 ) ;
F_124 ( V_265 , V_367 ) ;
F_124 ( V_259 , V_368 ) ;
F_124 ( V_261 , V_369 ) ;
F_124 ( V_260 , V_370 ) ;
F_124 ( V_263 , V_371 ) ;
F_124 ( V_262 , V_372 ) ;
if ( V_353 . V_264 ) {
if ( ! F_23 ( V_1 , V_373 , & V_36 , 2 ) )
return false ;
V_7 -> V_374 = 1 ;
V_7 -> V_375 = V_36 & 0x1 ;
V_7 -> V_264 =
F_123 ( V_10 , 0 , L_43 , 0 , 1 ) ;
if ( ! V_7 -> V_264 )
return false ;
F_121 ( V_6 ,
V_7 -> V_264 ,
V_7 -> V_375 ) ;
F_12 ( L_44 , V_36 ) ;
}
return true ;
}
static bool
F_125 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_352 V_353 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_36 , V_354 [ 2 ] ;
F_124 ( V_265 , V_367 ) ;
return true ;
}
static bool F_115 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_352 V_239 ;
T_4 V_36 ;
} V_353 ;
F_26 ( sizeof( V_353 ) != 2 ) ;
V_353 . V_36 = 0 ;
F_23 ( V_1 ,
V_376 ,
& V_353 , sizeof( V_353 ) ) ;
if ( V_353 . V_36 == 0 ) {
F_12 ( L_45 ) ;
return true ;
}
if ( F_80 ( V_7 ) )
return F_122 ( V_1 , V_7 , V_353 . V_239 ) ;
else if( F_81 ( V_7 ) )
return F_125 ( V_1 , V_7 , V_353 . V_239 ) ;
else
return true ;
}
static int F_126 ( struct V_377 * V_215 ,
struct V_19 * V_20 ,
int V_378 )
{
struct V_1 * V_208 = V_215 -> V_379 ;
if ( ! F_21 ( V_208 , V_208 -> V_47 ) )
return - V_288 ;
return V_208 -> V_27 -> V_380 -> V_381 ( V_208 -> V_27 , V_20 , V_378 ) ;
}
static T_1 F_127 ( struct V_377 * V_215 )
{
struct V_1 * V_208 = V_215 -> V_379 ;
return V_208 -> V_27 -> V_380 -> V_382 ( V_208 -> V_27 ) ;
}
static bool
F_128 ( struct V_1 * V_208 ,
struct V_9 * V_10 )
{
V_208 -> V_209 . V_383 = V_384 ;
V_208 -> V_209 . V_385 = V_386 ;
snprintf ( V_208 -> V_209 . V_31 , V_387 , L_46 ) ;
V_208 -> V_209 . V_10 . V_388 = & V_10 -> V_389 -> V_10 ;
V_208 -> V_209 . V_379 = V_208 ;
V_208 -> V_209 . V_380 = & V_390 ;
return F_129 ( & V_208 -> V_209 ) == 0 ;
}
bool F_130 ( struct V_9 * V_10 , int V_14 )
{
struct V_210 * V_211 = V_10 -> V_212 ;
struct V_391 * V_391 ;
struct V_1 * V_1 ;
int V_13 ;
V_1 = F_112 ( sizeof( struct V_1 ) , V_317 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_14 = V_14 ;
V_1 -> V_21 = F_104 ( V_10 , V_14 ) >> 1 ;
F_100 ( V_211 , V_1 , V_14 ) ;
if ( ! F_128 ( V_1 , V_10 ) ) {
F_65 ( V_1 ) ;
return false ;
}
V_391 = & V_1 -> V_4 ;
V_391 -> type = V_392 ;
F_131 ( V_10 , & V_391 -> V_4 , & V_393 , 0 ) ;
for ( V_13 = 0 ; V_13 < 0x40 ; V_13 ++ ) {
T_2 V_394 ;
if ( ! F_10 ( V_1 , V_13 , & V_394 ) ) {
F_12 ( L_47 ,
F_99 ( V_14 ) ? 'B' : 'C' ) ;
goto V_331;
}
}
if ( F_99 ( V_14 ) )
V_211 -> V_395 |= V_396 ;
else
V_211 -> V_395 |= V_397 ;
F_132 ( & V_391 -> V_4 , & V_398 ) ;
if ( ! F_57 ( V_1 , & V_1 -> V_193 ) )
goto V_331;
if ( F_118 ( V_1 ,
V_1 -> V_193 . V_206 ) != true ) {
F_12 ( L_48 ,
F_99 ( V_14 ) ? 'B' : 'C' ) ;
goto V_331;
}
F_98 ( V_211 , V_1 , V_14 ) ;
if ( ! F_24 ( V_1 ) )
goto V_331;
if ( ! F_29 ( V_1 ,
& V_1 -> V_186 ,
& V_1 -> V_188 ) )
goto V_331;
F_12 ( L_49
L_50
L_51
L_52 ,
F_14 ( V_1 ) ,
V_1 -> V_193 . V_195 , V_1 -> V_193 . V_196 ,
V_1 -> V_193 . V_197 ,
V_1 -> V_186 / 1000 ,
V_1 -> V_188 / 1000 ,
( V_1 -> V_193 . V_200 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_193 . V_200 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_193 . V_206 &
( V_319 | V_336 ) ? 'Y' : 'N' ,
V_1 -> V_193 . V_206 &
( V_320 | V_337 ) ? 'Y' : 'N' ) ;
return true ;
V_331:
F_133 ( & V_391 -> V_4 ) ;
F_95 ( & V_1 -> V_209 ) ;
F_65 ( V_1 ) ;
return false ;
}
