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
int V_13 , V_14 ;
int V_15 = F_8 ( V_10 ) ? 1 : 0 ;
for ( V_14 = 0 ; V_14 <= V_15 ; V_14 ++ ) {
if ( V_1 -> V_16 == V_17 )
V_12 = F_9 ( V_18 , V_14 ) ;
else
V_11 = F_9 ( V_17 , V_14 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
F_10 ( V_17 , V_11 , V_14 ) ;
F_9 ( V_17 , V_14 ) ;
F_10 ( V_18 , V_12 , V_14 ) ;
F_9 ( V_18 , V_14 ) ;
}
}
}
static bool F_11 ( struct V_1 * V_1 , T_2 V_19 , T_2 * V_20 )
{
struct V_21 V_22 [] = {
{
. V_19 = V_1 -> V_23 ,
. V_24 = 0 ,
. V_25 = 1 ,
. V_26 = & V_19 ,
} ,
{
. V_19 = V_1 -> V_23 ,
. V_24 = V_27 ,
. V_25 = 1 ,
. V_26 = V_20 ,
}
} ;
int V_28 ;
if ( ( V_28 = F_12 ( V_1 -> V_29 , V_22 , 2 ) ) == 2 )
return true ;
F_13 ( L_1 , V_28 ) ;
return false ;
}
static void F_14 ( struct V_1 * V_1 , T_2 V_30 ,
const void * args , int V_31 )
{
int V_13 ;
F_13 ( L_2 ,
F_15 ( V_1 ) , V_30 ) ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ )
F_13 ( L_3 , ( ( T_2 * ) args ) [ V_13 ] ) ;
for (; V_13 < 8 ; V_13 ++ )
F_13 ( L_4 ) ;
for ( V_13 = 0 ; V_13 < F_16 ( V_32 ) ; V_13 ++ ) {
if ( V_30 == V_32 [ V_13 ] . V_30 ) {
F_13 ( L_5 , V_32 [ V_13 ] . V_33 ) ;
break;
}
}
if ( V_13 == F_16 ( V_32 ) )
F_13 ( L_6 , V_30 ) ;
F_13 ( L_7 ) ;
}
static bool F_17 ( struct V_1 * V_1 , T_2 V_30 ,
const void * args , int V_31 )
{
T_2 V_26 [ V_31 * 2 + 2 ] , V_34 ;
struct V_21 V_22 [ V_31 + 3 ] ;
int V_13 , V_28 ;
F_14 ( V_1 , V_30 , args , V_31 ) ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_22 [ V_13 ] . V_19 = V_1 -> V_23 ;
V_22 [ V_13 ] . V_24 = 0 ;
V_22 [ V_13 ] . V_25 = 2 ;
V_22 [ V_13 ] . V_26 = V_26 + 2 * V_13 ;
V_26 [ 2 * V_13 + 0 ] = V_35 - V_13 ;
V_26 [ 2 * V_13 + 1 ] = ( ( T_2 * ) args ) [ V_13 ] ;
}
V_22 [ V_13 ] . V_19 = V_1 -> V_23 ;
V_22 [ V_13 ] . V_24 = 0 ;
V_22 [ V_13 ] . V_25 = 2 ;
V_22 [ V_13 ] . V_26 = V_26 + 2 * V_13 ;
V_26 [ 2 * V_13 + 0 ] = V_36 ;
V_26 [ 2 * V_13 + 1 ] = V_30 ;
V_34 = V_37 ;
V_22 [ V_13 + 1 ] . V_19 = V_1 -> V_23 ;
V_22 [ V_13 + 1 ] . V_24 = 0 ;
V_22 [ V_13 + 1 ] . V_25 = 1 ;
V_22 [ V_13 + 1 ] . V_26 = & V_34 ;
V_22 [ V_13 + 2 ] . V_19 = V_1 -> V_23 ;
V_22 [ V_13 + 2 ] . V_24 = V_27 ;
V_22 [ V_13 + 2 ] . V_25 = 1 ;
V_22 [ V_13 + 2 ] . V_26 = & V_34 ;
V_28 = F_12 ( V_1 -> V_29 , V_22 , V_13 + 3 ) ;
if ( V_28 < 0 ) {
F_13 ( L_8 , V_28 ) ;
return false ;
}
if ( V_28 != V_13 + 3 ) {
F_13 ( L_9 , V_28 , V_13 + 3 ) ;
return false ;
}
return true ;
}
static bool F_18 ( struct V_1 * V_1 ,
void * V_38 , int V_39 )
{
T_2 V_40 = 5 ;
T_2 V_34 ;
int V_13 ;
F_13 ( L_10 , F_15 ( V_1 ) ) ;
if ( ! F_11 ( V_1 ,
V_37 ,
& V_34 ) )
goto V_41;
while ( ( V_34 == V_42 ||
V_34 == V_43 ) && V_40 -- ) {
F_19 ( 15 ) ;
if ( ! F_11 ( V_1 ,
V_37 ,
& V_34 ) )
goto V_41;
}
if ( V_34 <= V_44 )
F_13 ( L_5 , V_45 [ V_34 ] ) ;
else
F_13 ( L_11 , V_34 ) ;
if ( V_34 != V_46 )
goto V_41;
for ( V_13 = 0 ; V_13 < V_39 ; V_13 ++ ) {
if ( ! F_11 ( V_1 ,
V_47 + V_13 ,
& ( ( T_2 * ) V_38 ) [ V_13 ] ) )
goto V_41;
F_13 ( L_12 , ( ( T_2 * ) V_38 ) [ V_13 ] ) ;
}
F_13 ( L_7 ) ;
return true ;
V_41:
F_13 ( L_13 ) ;
return false ;
}
static int F_20 ( struct V_48 * V_49 )
{
if ( V_49 -> clock >= 100000 )
return 1 ;
else if ( V_49 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_21 ( struct V_1 * V_1 ,
T_2 V_50 )
{
return F_17 ( V_1 ,
V_51 ,
& V_50 , 1 ) ;
}
static bool F_22 ( struct V_1 * V_1 , T_2 V_30 , const void * V_52 , int V_25 )
{
if ( ! F_17 ( V_1 , V_30 , V_52 , V_25 ) )
return false ;
return F_18 ( V_1 , NULL , 0 ) ;
}
static bool
F_23 ( struct V_1 * V_1 , T_2 V_30 , void * V_53 , int V_25 )
{
if ( ! F_17 ( V_1 , V_30 , NULL , 0 ) )
return false ;
return F_18 ( V_1 , V_53 , V_25 ) ;
}
static bool F_24 ( struct V_1 * V_1 )
{
struct V_54 V_55 = { 0 } ;
return F_22 ( V_1 ,
V_56 ,
& V_55 , sizeof( V_55 ) ) ;
}
static bool F_25 ( struct V_1 * V_1 , bool * V_57 , bool * V_58 )
{
struct V_59 V_38 ;
F_26 ( sizeof( V_38 ) != 1 ) ;
if ( ! F_23 ( V_1 , V_60 ,
& V_38 , sizeof( V_38 ) ) )
return false ;
* V_57 = V_38 . V_61 ;
* V_58 = V_38 . V_62 ;
return true ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_3 V_63 )
{
return F_22 ( V_1 ,
V_64 ,
& V_63 , sizeof( V_63 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 ,
int V_49 )
{
T_2 V_65 = V_66 ;
switch ( V_49 ) {
case V_67 :
V_65 = V_66 ;
break;
case V_68 :
V_65 = V_69 ;
break;
case V_70 :
V_65 = V_71 ;
break;
case V_72 :
V_65 = V_73 ;
break;
}
return F_22 ( V_1 ,
V_74 , & V_65 , sizeof( V_65 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 ,
int * V_75 ,
int * V_76 )
{
struct V_77 V_78 ;
F_26 ( sizeof( V_78 ) != 4 ) ;
if ( ! F_23 ( V_1 ,
V_79 ,
& V_78 , sizeof( V_78 ) ) )
return false ;
* V_75 = V_78 . V_80 * 10 ;
* V_76 = V_78 . V_81 * 10 ;
return true ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_3 V_63 )
{
return F_22 ( V_1 ,
V_82 ,
& V_63 , sizeof( V_63 ) ) ;
}
static bool F_31 ( struct V_1 * V_1 , T_2 V_30 ,
struct V_83 * V_84 )
{
return F_22 ( V_1 , V_30 , & V_84 -> V_85 , sizeof( V_84 -> V_85 ) ) &&
F_22 ( V_1 , V_30 + 1 , & V_84 -> V_86 , sizeof( V_84 -> V_86 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_83 * V_84 )
{
return F_31 ( V_1 ,
V_87 , V_84 ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
struct V_83 * V_84 )
{
return F_31 ( V_1 ,
V_88 , V_84 ) ;
}
static bool
F_34 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_89 ,
T_4 V_90 )
{
struct V_91 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_89 = V_89 ;
args . V_90 = V_90 ;
args . V_92 = 0 ;
if ( V_1 -> V_93 &&
( V_1 -> V_94 -> V_95 != V_89 ||
V_1 -> V_94 -> V_96 != V_90 ) )
args . V_97 = 1 ;
return F_22 ( V_1 ,
V_98 ,
& args , sizeof( args ) ) ;
}
static bool F_35 ( struct V_1 * V_1 ,
struct V_83 * V_84 )
{
F_26 ( sizeof( V_84 -> V_85 ) != 8 ) ;
F_26 ( sizeof( V_84 -> V_86 ) != 8 ) ;
return F_23 ( V_1 , V_99 ,
& V_84 -> V_85 , sizeof( V_84 -> V_85 ) ) &&
F_23 ( V_1 , V_100 ,
& V_84 -> V_86 , sizeof( V_84 -> V_86 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_22 ( V_1 , V_101 , & V_8 , 1 ) ;
}
static void F_37 ( struct V_83 * V_84 ,
const struct V_48 * V_49 )
{
T_4 V_89 , V_90 ;
T_4 V_102 , V_103 , V_104 , V_105 ;
T_4 V_106 , V_107 ;
V_89 = V_49 -> V_108 ;
V_90 = V_49 -> V_109 ;
V_102 = V_49 -> V_110 - V_49 -> V_111 ;
V_103 = V_49 -> V_112 - V_49 -> V_113 ;
V_104 = V_49 -> V_114 - V_49 -> V_115 ;
V_105 = V_49 -> V_116 - V_49 -> V_117 ;
V_106 = V_49 -> V_113 - V_49 -> V_111 ;
V_107 = V_49 -> V_117 - V_49 -> V_115 ;
V_84 -> V_85 . clock = V_49 -> clock / 10 ;
V_84 -> V_85 . V_118 = V_89 & 0xff ;
V_84 -> V_85 . V_119 = V_102 & 0xff ;
V_84 -> V_85 . V_120 = ( ( ( V_89 >> 8 ) & 0xf ) << 4 ) |
( ( V_102 >> 8 ) & 0xf ) ;
V_84 -> V_85 . V_121 = V_90 & 0xff ;
V_84 -> V_85 . V_122 = V_104 & 0xff ;
V_84 -> V_85 . V_123 = ( ( ( V_90 >> 8 ) & 0xf ) << 4 ) |
( ( V_104 >> 8 ) & 0xf ) ;
V_84 -> V_86 . V_124 = V_106 & 0xff ;
V_84 -> V_86 . V_125 = V_103 & 0xff ;
V_84 -> V_86 . V_126 = ( V_107 & 0xf ) << 4 |
( V_105 & 0xf ) ;
V_84 -> V_86 . V_127 = ( ( V_106 & 0x300 ) >> 2 ) |
( ( V_103 & 0x300 ) >> 4 ) | ( ( V_107 & 0x30 ) >> 2 ) |
( ( V_105 & 0x30 ) >> 4 ) ;
V_84 -> V_86 . V_128 = 0x18 ;
if ( V_49 -> V_24 & V_129 )
V_84 -> V_86 . V_128 |= 0x2 ;
if ( V_49 -> V_24 & V_130 )
V_84 -> V_86 . V_128 |= 0x4 ;
V_84 -> V_86 . V_131 = 0 ;
V_84 -> V_86 . V_132 = V_107 & 0xc0 ;
V_84 -> V_86 . V_133 = 0 ;
}
static void F_38 ( struct V_48 * V_49 ,
const struct V_83 * V_84 )
{
V_49 -> V_95 = V_84 -> V_85 . V_118 ;
V_49 -> V_95 += ( ( V_84 -> V_85 . V_120 >> 4 ) & 0x0f ) << 8 ;
V_49 -> V_134 = V_49 -> V_95 + V_84 -> V_86 . V_124 ;
V_49 -> V_134 += ( V_84 -> V_86 . V_127 & 0xc0 ) << 2 ;
V_49 -> V_135 = V_49 -> V_134 + V_84 -> V_86 . V_125 ;
V_49 -> V_135 += ( V_84 -> V_86 . V_127 & 0x30 ) << 4 ;
V_49 -> V_136 = V_49 -> V_95 + V_84 -> V_85 . V_119 ;
V_49 -> V_136 += ( V_84 -> V_85 . V_120 & 0xf ) << 8 ;
V_49 -> V_96 = V_84 -> V_85 . V_121 ;
V_49 -> V_96 += ( ( V_84 -> V_85 . V_123 >> 4 ) & 0x0f ) << 8 ;
V_49 -> V_137 = V_49 -> V_96 ;
V_49 -> V_137 += ( V_84 -> V_86 . V_126 >> 4 ) & 0xf ;
V_49 -> V_137 += ( V_84 -> V_86 . V_127 & 0x0c ) << 2 ;
V_49 -> V_137 += V_84 -> V_86 . V_132 & 0xc0 ;
V_49 -> V_138 = V_49 -> V_137 +
( V_84 -> V_86 . V_126 & 0xf ) ;
V_49 -> V_138 += ( V_84 -> V_86 . V_127 & 0x3 ) << 4 ;
V_49 -> V_139 = V_49 -> V_96 + V_84 -> V_85 . V_122 ;
V_49 -> V_139 += ( V_84 -> V_85 . V_123 & 0xf ) << 8 ;
V_49 -> clock = V_84 -> V_85 . clock * 10 ;
V_49 -> V_24 &= ~ ( V_129 | V_130 ) ;
if ( V_84 -> V_86 . V_128 & 0x2 )
V_49 -> V_24 |= V_129 ;
if ( V_84 -> V_86 . V_128 & 0x4 )
V_49 -> V_24 |= V_130 ;
}
static bool F_39 ( struct V_1 * V_1 )
{
struct V_140 V_141 ;
F_26 ( sizeof( V_141 ) != 2 ) ;
return F_23 ( V_1 ,
V_142 ,
& V_141 , sizeof( V_141 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_5 V_49 )
{
return F_22 ( V_1 , V_143 , & V_49 , 1 ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_5 V_49 )
{
return F_22 ( V_1 , V_144 , & V_49 , 1 ) ;
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
struct V_145 V_146 ;
T_6 V_147 ;
V_147 = 1 << V_1 -> V_148 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
memcpy ( & V_146 , & V_147 , V_80 ( sizeof( V_146 ) , sizeof( V_147 ) ) ) ;
F_26 ( sizeof( V_146 ) != 6 ) ;
return F_22 ( V_1 ,
V_149 ,
& V_146 , sizeof( V_146 ) ) ;
}
static bool
F_45 ( struct V_1 * V_1 ,
const struct V_48 * V_49 )
{
struct V_83 V_150 ;
if ( ! F_30 ( V_1 ,
V_1 -> V_151 ) )
return false ;
F_37 ( & V_150 , V_49 ) ;
if ( ! F_33 ( V_1 , & V_150 ) )
return false ;
return true ;
}
static bool
F_46 ( struct V_1 * V_1 ,
const struct V_48 * V_49 ,
struct V_48 * V_152 )
{
if ( ! F_24 ( V_1 ) )
return false ;
if ( ! F_34 ( V_1 ,
V_49 -> clock / 10 ,
V_49 -> V_95 ,
V_49 -> V_96 ) )
return false ;
if ( ! F_35 ( V_1 ,
& V_1 -> V_153 ) )
return false ;
F_38 ( V_152 , & V_1 -> V_153 ) ;
F_47 ( V_152 , 0 ) ;
return true ;
}
static bool F_48 ( struct V_2 * V_3 ,
const struct V_48 * V_49 ,
struct V_48 * V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_154 ;
if ( V_1 -> V_155 ) {
if ( ! F_45 ( V_1 , V_49 ) )
return false ;
( void ) F_46 ( V_1 ,
V_49 ,
V_152 ) ;
} else if ( V_1 -> V_93 ) {
if ( ! F_45 ( V_1 ,
V_1 -> V_94 ) )
return false ;
( void ) F_46 ( V_1 ,
V_49 ,
V_152 ) ;
}
V_154 = F_20 ( V_152 ) ;
F_49 ( V_152 , V_154 ) ;
return true ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
struct V_48 * V_152 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_156 * V_157 = V_3 -> V_157 ;
struct V_158 * V_158 = F_51 ( V_157 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_159 ;
struct V_160 V_161 ;
struct V_83 V_153 ;
int V_162 = F_52 ( V_152 ) ;
int V_163 ;
int V_15 = F_8 ( V_10 ) ? 1 : 0 ;
if ( ! V_49 )
return;
V_161 . V_164 = V_1 -> V_151 ;
V_161 . V_165 = 0 ;
F_22 ( V_1 ,
V_166 ,
& V_161 , sizeof( V_161 ) ) ;
if ( ! F_30 ( V_1 ,
V_1 -> V_151 ) )
return;
if ( V_1 -> V_155 || V_1 -> V_93 ) {
V_153 = V_1 -> V_153 ;
} else {
if ( ! F_30 ( V_1 ,
V_1 -> V_151 ) )
return;
F_37 ( & V_153 , V_152 ) ;
( void ) F_33 ( V_1 , & V_153 ) ;
}
if ( ! F_24 ( V_1 ) )
return;
if ( V_1 -> V_167 ) {
F_40 ( V_1 , V_168 ) ;
F_41 ( V_1 ,
V_169 ) ;
F_42 ( V_1 ) ;
} else
F_40 ( V_1 , V_170 ) ;
if ( V_1 -> V_155 &&
! F_44 ( V_1 ) )
return;
( void ) F_32 ( V_1 , & V_153 ) ;
switch ( V_162 ) {
default:
case 1 : V_163 = V_171 ; break;
case 2 : V_163 = V_172 ; break;
case 4 : V_163 = V_173 ; break;
}
if ( ! F_36 ( V_1 , V_163 ) )
return;
if ( V_15 )
V_159 = F_53 ( V_1 -> V_16 ) ;
else
V_159 = F_54 ( V_1 -> V_16 ) ;
switch ( V_1 -> V_16 ) {
case V_17 :
V_159 &= V_174 ;
break;
case V_18 :
V_159 &= V_175 ;
break;
}
V_159 |= ( 9 << 19 ) | V_176 ;
if ( V_158 -> V_177 == 1 )
V_159 |= V_178 ;
if ( V_1 -> V_179 )
V_159 |= V_180 ;
if ( V_153 . V_86 . V_131 & V_181 )
V_159 |= V_182 ;
F_7 ( V_1 , V_159 ) ;
}
static void F_55 ( struct V_2 * V_3 , int V_49 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_183 ;
int V_13 ;
int V_15 = F_8 ( V_10 ) ? 1 : 0 ;
switch ( V_49 ) {
case V_67 :
F_56 ( L_15 ) ;
break;
case V_72 :
F_56 ( L_16 ) ;
break;
default:
F_56 ( L_17 , V_49 ) ;
}
if ( V_49 != V_67 ) {
F_27 ( V_1 , 0 ) ;
if ( 0 )
F_28 ( V_1 , V_49 ) ;
if ( V_49 == V_72 ) {
if ( V_15 )
V_183 = F_53 ( V_1 -> V_16 ) ;
else
V_183 = F_54 ( V_1 -> V_16 ) ;
if ( ( V_183 & V_184 ) != 0 ) {
F_7 ( V_1 , V_183 & ~ V_184 ) ;
}
}
} else {
bool V_185 , V_186 ;
T_2 V_34 ;
if ( V_15 )
V_183 = F_53 ( V_1 -> V_16 ) ;
else
V_183 = F_54 ( V_1 -> V_16 ) ;
if ( ( V_183 & V_184 ) == 0 )
F_7 ( V_1 , V_183 | V_184 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
F_57 ( V_10 ) ;
V_34 = F_25 ( V_1 , & V_185 , & V_186 ) ;
if ( V_34 == V_46 && ! V_185 ) {
F_13 ( L_18
L_19 , F_15 ( V_1 ) ) ;
}
if ( 0 )
F_28 ( V_1 , V_49 ) ;
F_27 ( V_1 , V_1 -> V_151 ) ;
}
return;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_49 -> V_24 & V_187 )
return V_188 ;
if ( V_1 -> V_189 > V_49 -> clock )
return V_190 ;
if ( V_1 -> V_191 < V_49 -> clock )
return V_192 ;
if ( V_1 -> V_93 ) {
if ( V_49 -> V_95 > V_1 -> V_94 -> V_95 )
return V_193 ;
if ( V_49 -> V_96 > V_1 -> V_94 -> V_96 )
return V_193 ;
}
return V_194 ;
}
static bool F_59 ( struct V_1 * V_1 , struct V_195 * V_196 )
{
F_26 ( sizeof( * V_196 ) != 8 ) ;
if ( ! F_23 ( V_1 ,
V_197 ,
V_196 , sizeof( * V_196 ) ) )
return false ;
F_13 ( L_20
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
V_196 -> V_198 ,
V_196 -> V_199 ,
V_196 -> V_200 ,
V_196 -> V_201 ,
V_196 -> V_202 ,
V_196 -> V_203 ,
V_196 -> V_204 ,
V_196 -> V_205 ,
V_196 -> V_206 ,
V_196 -> V_207 ,
V_196 -> V_208 ,
V_196 -> V_209 ) ;
return true ;
}
static bool
F_60 ( struct V_1 * V_1 )
{
int V_196 = V_1 -> V_196 . V_209 & 0xf ;
return V_196 & - V_196 ;
}
static struct V_210 *
F_61 ( struct V_5 * V_6 )
{
struct V_1 * V_211 = F_3 ( V_6 ) ;
return F_62 ( V_6 , & V_211 -> V_212 ) ;
}
static struct V_210 *
F_63 ( struct V_5 * V_6 )
{
struct V_213 * V_214 = V_6 -> V_10 -> V_215 ;
return F_62 ( V_6 ,
& V_214 -> V_216 [ V_214 -> V_217 ] . V_218 ) ;
}
static enum V_219
F_64 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_219 V_34 ;
struct V_210 * V_210 ;
V_210 = F_61 ( V_6 ) ;
if ( V_210 == NULL && F_60 ( V_1 ) ) {
T_2 V_212 , V_220 = V_1 -> V_50 ;
for ( V_212 = V_1 -> V_50 >> 1 ; V_212 > 1 ; V_212 >>= 1 ) {
V_1 -> V_50 = V_212 ;
V_210 = F_61 ( V_6 ) ;
if ( V_210 )
break;
}
if ( V_210 == NULL )
V_1 -> V_50 = V_220 ;
}
if ( V_210 == NULL )
V_210 = F_63 ( V_6 ) ;
V_34 = V_221 ;
if ( V_210 != NULL ) {
if ( V_210 -> V_222 & V_223 ) {
V_34 = V_224 ;
if ( V_1 -> V_225 ) {
V_1 -> V_167 = F_65 ( V_210 ) ;
V_1 -> V_179 = F_66 ( V_210 ) ;
}
} else
V_34 = V_226 ;
F_67 ( V_210 ) ;
}
if ( V_34 == V_224 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_227 )
V_1 -> V_179 = V_7 -> V_227 > 0 ;
}
return V_34 ;
}
static enum V_219
F_68 ( struct V_5 * V_6 , bool V_228 )
{
T_4 V_38 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_219 V_28 ;
if ( ! F_17 ( V_1 ,
V_229 , NULL , 0 ) )
return V_221 ;
if ( V_1 -> V_196 . V_209 &
( V_230 | V_231 ) )
F_69 ( 30 ) ;
if ( ! F_18 ( V_1 , & V_38 , 2 ) )
return V_221 ;
F_13 ( L_33 ,
V_38 & 0xff , V_38 >> 8 ,
V_7 -> V_232 ) ;
if ( V_38 == 0 )
return V_226 ;
V_1 -> V_151 = V_38 ;
V_1 -> V_167 = false ;
V_1 -> V_179 = false ;
if ( ( V_7 -> V_232 & V_38 ) == 0 )
V_28 = V_226 ;
else if ( F_70 ( V_7 ) )
V_28 = F_64 ( V_6 ) ;
else {
struct V_210 * V_210 ;
V_210 = F_61 ( V_6 ) ;
if ( V_210 == NULL )
V_210 = F_63 ( V_6 ) ;
if ( V_210 != NULL ) {
if ( V_210 -> V_222 & V_223 )
V_28 = V_226 ;
else
V_28 = V_224 ;
F_67 ( V_210 ) ;
} else
V_28 = V_224 ;
}
if ( V_28 == V_224 ) {
V_1 -> V_155 = false ;
V_1 -> V_93 = false ;
V_1 -> V_4 . V_233 = false ;
if ( V_38 & V_234 ) {
V_1 -> V_155 = true ;
V_1 -> V_4 . V_233 = true ;
}
if ( V_38 & V_235 )
V_1 -> V_93 = V_1 -> V_94 != NULL ;
}
return V_28 ;
}
static void F_71 ( struct V_5 * V_6 )
{
struct V_210 * V_210 ;
V_210 = F_61 ( V_6 ) ;
if ( V_210 == NULL )
V_210 = F_63 ( V_6 ) ;
if ( V_210 != NULL ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
bool V_236 = ! ! ( V_210 -> V_222 & V_223 ) ;
bool V_237 = ! ! F_70 ( V_7 ) ;
if ( V_237 == V_236 ) {
F_72 ( V_6 , V_210 ) ;
F_73 ( V_6 , V_210 ) ;
}
F_67 ( V_210 ) ;
}
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_238 V_239 ;
T_6 V_240 = 0 , V_147 = 0 ;
int V_13 ;
V_147 = 1 << V_1 -> V_148 ;
memcpy ( & V_239 , & V_147 ,
V_80 ( sizeof( V_147 ) , sizeof( struct V_238 ) ) ) ;
if ( ! F_30 ( V_1 , V_1 -> V_151 ) )
return;
F_26 ( sizeof( V_239 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_241 ,
& V_239 , sizeof( V_239 ) ) )
return;
if ( ! F_18 ( V_1 , & V_240 , 3 ) )
return;
for ( V_13 = 0 ; V_13 < F_16 ( V_242 ) ; V_13 ++ )
if ( V_240 & ( 1 << V_13 ) ) {
struct V_48 * V_243 ;
V_243 = F_75 ( V_6 -> V_10 ,
& V_242 [ V_13 ] ) ;
if ( V_243 )
F_76 ( V_6 , V_243 ) ;
}
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_213 * V_214 = V_6 -> V_10 -> V_215 ;
struct V_48 * V_244 ;
F_78 ( V_6 , V_1 -> V_29 ) ;
if ( F_79 ( & V_6 -> V_245 ) == false )
goto V_246;
if ( V_214 -> V_247 != NULL ) {
V_244 = F_75 ( V_6 -> V_10 ,
V_214 -> V_247 ) ;
if ( V_244 != NULL ) {
V_244 -> type = ( V_248 |
V_249 ) ;
F_76 ( V_6 , V_244 ) ;
}
}
V_246:
F_80 (newmode, &connector->probed_modes, head) {
if ( V_244 -> type & V_248 ) {
V_1 -> V_94 =
F_75 ( V_6 -> V_10 , V_244 ) ;
F_47 ( V_1 -> V_94 ,
0 ) ;
V_1 -> V_93 = true ;
break;
}
}
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_82 ( V_7 ) )
F_74 ( V_6 ) ;
else if ( F_83 ( V_7 ) )
F_77 ( V_6 ) ;
else
F_71 ( V_6 ) ;
return ! F_79 ( & V_6 -> V_245 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_67 ( V_6 ) ;
}
static bool F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_210 * V_210 ;
bool V_250 = false ;
if ( ! V_1 -> V_225 )
return false ;
V_210 = F_61 ( V_6 ) ;
if ( V_210 != NULL && V_210 -> V_222 & V_223 )
V_250 = F_66 ( V_210 ) ;
return V_250 ;
}
static int
F_88 ( struct V_5 * V_6 ,
struct V_251 * V_252 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_213 * V_214 = V_6 -> V_10 -> V_215 ;
T_4 V_253 ;
T_5 V_30 ;
int V_28 ;
V_28 = F_89 ( & V_6 -> V_4 , V_252 , V_8 ) ;
if ( V_28 )
return V_28 ;
if ( V_252 == V_214 -> V_254 ) {
int V_13 = V_8 ;
bool V_250 ;
if ( V_13 == V_7 -> V_227 )
return 0 ;
V_7 -> V_227 = V_13 ;
if ( V_13 == 0 )
V_250 = F_87 ( V_6 ) ;
else
V_250 = V_13 > 0 ;
if ( V_250 == V_1 -> V_179 )
return 0 ;
V_1 -> V_179 = V_250 ;
goto V_255;
}
if ( V_252 == V_214 -> V_256 ) {
if ( V_8 == ! ! V_1 -> V_257 )
return 0 ;
V_1 -> V_257 = V_8 ? V_258 : 0 ;
goto V_255;
}
#define F_90 ( V_33 , T_8 ) \
if (psb_intel_sdvo_connector->name == property) { \
if (psb_intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (psb_intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
psb_intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_252 == V_7 -> V_259 ) {
if ( V_8 >= V_260 )
return - V_261 ;
if ( V_1 -> V_148 ==
V_7 -> V_262 [ V_8 ] )
return 0 ;
V_1 -> V_148 = V_7 -> V_262 [ V_8 ] ;
goto V_255;
} else if ( F_91 ( V_7 ) ) {
V_253 = V_8 ;
if ( V_7 -> V_263 == V_252 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_264 , V_8 ) ;
if ( V_7 -> V_265 == V_253 )
return 0 ;
V_7 -> V_265 = V_253 ;
V_7 -> V_266 = V_253 ;
V_253 = V_7 -> V_267 -
V_7 -> V_265 ;
V_30 = V_268 ;
goto V_269;
} else if ( V_7 -> V_264 == V_252 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_263 , V_8 ) ;
if ( V_7 -> V_266 == V_253 )
return 0 ;
V_7 -> V_265 = V_253 ;
V_7 -> V_266 = V_253 ;
V_253 = V_7 -> V_267 -
V_7 -> V_265 ;
V_30 = V_268 ;
goto V_269;
} else if ( V_7 -> V_270 == V_252 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_271 , V_8 ) ;
if ( V_7 -> V_272 == V_253 )
return 0 ;
V_7 -> V_272 = V_253 ;
V_7 -> V_273 = V_253 ;
V_253 = V_7 -> V_274 -
V_7 -> V_272 ;
V_30 = V_275 ;
goto V_269;
} else if ( V_7 -> V_271 == V_252 ) {
F_89 ( & V_6 -> V_4 ,
V_7 -> V_270 , V_8 ) ;
if ( V_7 -> V_273 == V_253 )
return 0 ;
V_7 -> V_272 = V_253 ;
V_7 -> V_273 = V_253 ;
V_253 = V_7 -> V_274 -
V_7 -> V_272 ;
V_30 = V_275 ;
goto V_269;
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
return - V_261 ;
V_269:
if ( ! F_22 ( V_1 , V_30 , & V_253 , 2 ) )
return - V_276 ;
V_255:
if ( V_1 -> V_4 . V_4 . V_157 ) {
struct V_156 * V_157 = V_1 -> V_4 . V_4 . V_157 ;
F_92 ( V_157 , & V_157 -> V_49 , V_157 -> V_277 ,
V_157 -> V_278 , V_157 -> V_279 -> V_280 ) ;
}
return 0 ;
#undef F_90
}
static void F_93 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_281 * V_281 = F_4 ( V_6 ) ;
struct V_1 * V_211 = F_1 ( & V_281 -> V_4 ) ;
V_211 -> V_282 = F_54 ( V_211 -> V_16 ) ;
}
static void F_94 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_2 * V_3 = & F_4 ( V_6 ) -> V_4 ;
struct V_1 * V_211 = F_1 ( V_3 ) ;
struct V_156 * V_157 = V_3 -> V_157 ;
F_95 ( V_211 -> V_16 , V_211 -> V_282 ) ;
if ( V_6 -> V_34 == V_224 )
F_92 ( V_157 , & V_157 -> V_49 , V_157 -> V_277 , V_157 -> V_278 ,
NULL ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_94 != NULL )
F_97 ( V_3 -> V_10 ,
V_1 -> V_94 ) ;
F_98 ( & V_1 -> V_212 ) ;
F_99 ( V_3 ) ;
}
static void
F_100 ( struct V_1 * V_211 )
{
V_211 -> V_50 = 2 ;
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
F_101 ( struct V_213 * V_214 ,
struct V_1 * V_211 , T_1 V_283 )
{
struct V_284 * V_285 ;
if ( F_102 ( V_283 ) )
V_285 = & ( V_214 -> V_286 [ 0 ] ) ;
else
V_285 = & ( V_214 -> V_286 [ 1 ] ) ;
if ( V_285 -> V_287 )
V_211 -> V_50 = 1 << ( ( V_285 -> V_288 & 0xf0 ) >> 4 ) ;
else
F_100 ( V_211 ) ;
}
static void
F_103 ( struct V_213 * V_214 ,
struct V_1 * V_211 , T_1 V_283 )
{
struct V_284 * V_285 ;
T_2 V_289 , V_290 ;
if ( F_102 ( V_283 ) )
V_285 = & V_214 -> V_286 [ 0 ] ;
else
V_285 = & V_214 -> V_286 [ 1 ] ;
V_289 = V_291 ;
V_290 = V_292 >> 8 ;
if ( V_285 -> V_287 ) {
V_289 = V_285 -> V_293 ;
V_290 = V_285 -> V_294 ;
}
if ( V_289 < V_295 ) {
V_211 -> V_29 = & V_214 -> V_216 [ V_289 ] . V_218 ;
F_104 ( V_211 -> V_29 , V_290 ) ;
F_105 ( V_211 -> V_29 , true ) ;
} else
V_211 -> V_29 = & V_214 -> V_216 [ V_291 ] . V_218 ;
}
static bool
F_106 ( struct V_1 * V_1 , int V_296 )
{
return F_39 ( V_1 ) ;
}
static T_2
F_107 ( struct V_9 * V_10 , int V_16 )
{
struct V_213 * V_214 = V_10 -> V_215 ;
struct V_284 * V_297 , * V_298 ;
if ( F_102 ( V_16 ) ) {
V_297 = & V_214 -> V_286 [ 0 ] ;
V_298 = & V_214 -> V_286 [ 1 ] ;
} else {
V_297 = & V_214 -> V_286 [ 1 ] ;
V_298 = & V_214 -> V_286 [ 0 ] ;
}
if ( V_297 -> V_23 )
return V_297 -> V_23 ;
if ( V_298 -> V_23 ) {
if ( V_298 -> V_23 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( F_102 ( V_16 ) )
return 0x70 ;
else
return 0x72 ;
}
static void
F_108 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_109 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_299 ,
V_6 -> V_4 . V_4 . V_300 ) ;
F_110 ( & V_6 -> V_4 . V_4 ,
& V_301 ) ;
V_6 -> V_4 . V_4 . V_302 = 0 ;
V_6 -> V_4 . V_4 . V_303 = 0 ;
V_6 -> V_4 . V_4 . V_304 . V_305 = V_306 ;
V_6 -> V_4 . V_307 = F_93 ;
V_6 -> V_4 . V_308 = F_94 ;
F_111 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_112 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_113 ( struct V_7 * V_6 )
{
}
static bool
F_114 ( struct V_1 * V_1 , int V_296 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_309 * V_310 ;
struct V_7 * V_7 ;
V_7 = F_115 ( sizeof( struct V_7 ) , V_311 ) ;
if ( ! V_7 )
return false ;
if ( V_296 == 0 ) {
V_1 -> V_312 |= V_313 ;
V_7 -> V_232 = V_313 ;
} else if ( V_296 == 1 ) {
V_1 -> V_312 |= V_314 ;
V_7 -> V_232 = V_314 ;
}
V_310 = & V_7 -> V_4 ;
V_6 = & V_310 -> V_4 ;
V_3 -> V_315 = V_316 ;
V_6 -> V_300 = V_317 ;
if ( F_106 ( V_1 , V_296 ) ) {
V_6 -> V_300 = V_318 ;
V_1 -> V_225 = true ;
}
V_1 -> V_4 . V_319 = ( ( 1 << V_320 ) |
( 1 << V_321 ) ) ;
F_108 ( V_7 , V_1 ) ;
if ( V_1 -> V_225 )
F_113 ( V_7 ) ;
return true ;
}
static bool
F_116 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_309 * V_310 ;
struct V_7 * V_7 ;
V_7 = F_115 ( sizeof( struct V_7 ) , V_311 ) ;
if ( ! V_7 )
return false ;
V_310 = & V_7 -> V_4 ;
V_6 = & V_310 -> V_4 ;
V_3 -> V_315 = V_322 ;
V_6 -> V_300 = V_323 ;
V_1 -> V_312 |= type ;
V_7 -> V_232 = type ;
V_1 -> V_155 = true ;
V_1 -> V_4 . V_233 = true ;
V_1 -> V_4 . V_319 = 1 << V_324 ;
F_108 ( V_7 , V_1 ) ;
if ( ! F_117 ( V_1 , V_7 , type ) )
goto V_325;
if ( ! F_118 ( V_1 , V_7 ) )
goto V_325;
return true ;
V_325:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_119 ( struct V_1 * V_1 , int V_296 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_309 * V_310 ;
struct V_7 * V_7 ;
V_7 = F_115 ( sizeof( struct V_7 ) , V_311 ) ;
if ( ! V_7 )
return false ;
V_310 = & V_7 -> V_4 ;
V_6 = & V_310 -> V_4 ;
V_6 -> V_326 = V_327 ;
V_3 -> V_315 = V_328 ;
V_6 -> V_300 = V_329 ;
if ( V_296 == 0 ) {
V_1 -> V_312 |= V_330 ;
V_7 -> V_232 = V_330 ;
} else if ( V_296 == 1 ) {
V_1 -> V_312 |= V_331 ;
V_7 -> V_232 = V_331 ;
}
V_1 -> V_4 . V_319 = ( ( 1 << V_320 ) |
( 1 << V_321 ) ) ;
F_108 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_120 ( struct V_1 * V_1 , int V_296 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_309 * V_310 ;
struct V_7 * V_7 ;
V_7 = F_115 ( sizeof( struct V_7 ) , V_311 ) ;
if ( ! V_7 )
return false ;
V_310 = & V_7 -> V_4 ;
V_6 = & V_310 -> V_4 ;
V_3 -> V_315 = V_332 ;
V_6 -> V_300 = V_333 ;
if ( V_296 == 0 ) {
V_1 -> V_312 |= V_334 ;
V_7 -> V_232 = V_334 ;
} else if ( V_296 == 1 ) {
V_1 -> V_312 |= V_335 ;
V_7 -> V_232 = V_335 ;
}
V_1 -> V_4 . V_319 = ( ( 1 << V_321 ) |
( 1 << V_336 ) ) ;
F_108 ( V_7 , V_1 ) ;
if ( ! F_118 ( V_1 , V_7 ) )
goto V_325;
return true ;
V_325:
F_84 ( V_6 ) ;
return false ;
}
static bool
F_121 ( struct V_1 * V_1 , T_4 V_24 )
{
V_1 -> V_155 = false ;
V_1 -> V_4 . V_233 = false ;
V_1 -> V_93 = false ;
if ( V_24 & V_313 )
if ( ! F_114 ( V_1 , 0 ) )
return false ;
if ( ( V_24 & V_337 ) == V_337 )
if ( ! F_114 ( V_1 , 1 ) )
return false ;
if ( V_24 & V_230 )
if ( ! F_116 ( V_1 , V_230 ) )
return false ;
if ( V_24 & V_231 )
if ( ! F_116 ( V_1 , V_231 ) )
return false ;
if ( V_24 & V_330 )
if ( ! F_119 ( V_1 , 0 ) )
return false ;
if ( ( V_24 & V_338 ) == V_338 )
if ( ! F_119 ( V_1 , 1 ) )
return false ;
if ( V_24 & V_334 )
if ( ! F_120 ( V_1 , 0 ) )
return false ;
if ( ( V_24 & V_235 ) == V_235 )
if ( ! F_120 ( V_1 , 1 ) )
return false ;
if ( ( V_24 & V_339 ) == 0 ) {
unsigned char V_340 [ 2 ] ;
V_1 -> V_312 = 0 ;
memcpy ( V_340 , & V_1 -> V_196 . V_209 , 2 ) ;
F_13 ( L_34 ,
F_15 ( V_1 ) ,
V_340 [ 0 ] , V_340 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_341 = ( 1 << 0 ) | ( 1 << 1 ) ;
return true ;
}
static bool F_117 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_145 V_146 ;
T_6 V_147 , V_13 ;
if ( ! F_30 ( V_1 , type ) )
return false ;
F_26 ( sizeof( V_146 ) != 6 ) ;
if ( ! F_23 ( V_1 ,
V_342 ,
& V_146 , sizeof( V_146 ) ) )
return false ;
memcpy ( & V_147 , & V_146 , V_80 ( sizeof( V_147 ) , sizeof( V_146 ) ) ) ;
if ( V_147 == 0 )
return false ;
V_7 -> V_343 = 0 ;
for ( V_13 = 0 ; V_13 < V_260 ; V_13 ++ )
if ( V_147 & ( 1 << V_13 ) )
V_7 -> V_262 [ V_7 -> V_343 ++ ] = V_13 ;
V_7 -> V_259 =
F_122 ( V_10 , V_344 ,
L_35 , V_7 -> V_343 ) ;
if ( ! V_7 -> V_259 )
return false ;
for ( V_13 = 0 ; V_13 < V_7 -> V_343 ; V_13 ++ )
F_123 (
V_7 -> V_259 , V_13 ,
V_13 , V_345 [ V_7 -> V_262 [ V_13 ] ] ) ;
V_1 -> V_148 = V_7 -> V_262 [ 0 ] ;
F_124 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_259 , 0 ) ;
return true ;
}
static bool
F_125 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_346 V_347 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_38 , V_348 [ 2 ] ;
if ( V_347 . V_349 ) {
if ( ! F_23 ( V_1 ,
V_350 ,
& V_348 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_351 ,
& V_38 , 2 ) )
return false ;
V_7 -> V_267 = V_348 [ 0 ] ;
V_7 -> V_265 = V_348 [ 0 ] - V_38 ;
V_7 -> V_266 = V_7 -> V_265 ;
V_7 -> V_263 =
F_126 ( V_10 , 0 , L_36 , 0 , V_348 [ 0 ] ) ;
if ( ! V_7 -> V_263 )
return false ;
F_124 ( & V_6 -> V_4 ,
V_7 -> V_263 ,
V_7 -> V_265 ) ;
V_7 -> V_264 =
F_126 ( V_10 , 0 , L_37 , 0 , V_348 [ 0 ] ) ;
if ( ! V_7 -> V_264 )
return false ;
F_124 ( & V_6 -> V_4 ,
V_7 -> V_264 ,
V_7 -> V_266 ) ;
F_13 ( L_38
L_39 ,
V_348 [ 0 ] , V_348 [ 1 ] , V_38 ) ;
}
if ( V_347 . V_352 ) {
if ( ! F_23 ( V_1 ,
V_353 ,
& V_348 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_354 ,
& V_38 , 2 ) )
return false ;
V_7 -> V_274 = V_348 [ 0 ] ;
V_7 -> V_272 = V_348 [ 0 ] - V_38 ;
V_7 -> V_273 = V_7 -> V_272 ;
V_7 -> V_270 =
F_126 ( V_10 , 0 , L_40 , 0 , V_348 [ 0 ] ) ;
if ( ! V_7 -> V_270 )
return false ;
F_124 ( & V_6 -> V_4 ,
V_7 -> V_270 ,
V_7 -> V_272 ) ;
V_7 -> V_271 =
F_126 ( V_10 , 0 , L_41 , 0 , V_348 [ 0 ] ) ;
if ( ! V_7 -> V_271 )
return false ;
F_124 ( & V_6 -> V_4 ,
V_7 -> V_271 ,
V_7 -> V_273 ) ;
F_13 ( L_42
L_39 ,
V_348 [ 0 ] , V_348 [ 1 ] , V_38 ) ;
}
F_127 ( V_355 , V_356 ) ;
F_127 ( V_357 , V_358 ) ;
F_127 ( V_359 , V_360 ) ;
F_127 ( V_361 , V_362 ) ;
F_127 ( V_363 , V_364 ) ;
F_127 ( V_365 , V_366 ) ;
F_127 ( V_367 , V_368 ) ;
F_127 ( V_369 , V_370 ) ;
F_127 ( V_371 , V_372 ) ;
F_127 ( V_373 , V_374 ) ;
F_127 ( V_375 , V_376 ) ;
F_127 ( V_377 , V_378 ) ;
if ( V_347 . V_379 ) {
if ( ! F_23 ( V_1 , V_380 , & V_38 , 2 ) )
return false ;
V_7 -> V_381 = 1 ;
V_7 -> V_382 = V_38 & 0x1 ;
V_7 -> V_379 =
F_126 ( V_10 , 0 , L_43 , 0 , 1 ) ;
if ( ! V_7 -> V_379 )
return false ;
F_124 ( & V_6 -> V_4 ,
V_7 -> V_379 ,
V_7 -> V_382 ) ;
F_13 ( L_44 , V_38 ) ;
}
return true ;
}
static bool
F_128 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_346 V_347 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_38 , V_348 [ 2 ] ;
F_127 ( V_367 , V_368 ) ;
return true ;
}
static bool F_118 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_346 V_240 ;
T_4 V_38 ;
} V_347 ;
F_26 ( sizeof( V_347 ) != 2 ) ;
V_347 . V_38 = 0 ;
F_23 ( V_1 ,
V_383 ,
& V_347 , sizeof( V_347 ) ) ;
if ( V_347 . V_38 == 0 ) {
F_13 ( L_45 ) ;
return true ;
}
if ( F_82 ( V_7 ) )
return F_125 ( V_1 , V_7 , V_347 . V_240 ) ;
else if( F_83 ( V_7 ) )
return F_128 ( V_1 , V_7 , V_347 . V_240 ) ;
else
return true ;
}
static int F_129 ( struct V_384 * V_218 ,
struct V_21 * V_22 ,
int V_385 )
{
struct V_1 * V_211 = V_218 -> V_386 ;
if ( ! F_21 ( V_211 , V_211 -> V_50 ) )
return - V_276 ;
return V_211 -> V_29 -> V_387 -> V_388 ( V_211 -> V_29 , V_22 , V_385 ) ;
}
static T_1 F_130 ( struct V_384 * V_218 )
{
struct V_1 * V_211 = V_218 -> V_386 ;
return V_211 -> V_29 -> V_387 -> V_389 ( V_211 -> V_29 ) ;
}
static bool
F_131 ( struct V_1 * V_211 ,
struct V_9 * V_10 )
{
V_211 -> V_212 . V_390 = V_391 ;
V_211 -> V_212 . V_392 = V_393 ;
snprintf ( V_211 -> V_212 . V_33 , V_394 , L_46 ) ;
V_211 -> V_212 . V_10 . V_395 = & V_10 -> V_396 -> V_10 ;
V_211 -> V_212 . V_386 = V_211 ;
V_211 -> V_212 . V_387 = & V_397 ;
return F_132 ( & V_211 -> V_212 ) == 0 ;
}
bool F_133 ( struct V_9 * V_10 , int V_16 )
{
struct V_213 * V_214 = V_10 -> V_215 ;
struct V_281 * V_281 ;
struct V_1 * V_1 ;
int V_13 ;
V_1 = F_115 ( sizeof( struct V_1 ) , V_311 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_16 = V_16 ;
V_1 -> V_23 = F_107 ( V_10 , V_16 ) >> 1 ;
F_103 ( V_214 , V_1 , V_16 ) ;
if ( ! F_131 ( V_1 , V_10 ) ) {
F_67 ( V_1 ) ;
return false ;
}
V_281 = & V_1 -> V_4 ;
V_281 -> type = V_398 ;
F_134 ( V_10 , & V_281 -> V_4 , & V_399 ,
0 , NULL ) ;
for ( V_13 = 0 ; V_13 < 0x40 ; V_13 ++ ) {
T_2 V_400 ;
if ( ! F_11 ( V_1 , V_13 , & V_400 ) ) {
F_13 ( L_47 ,
F_102 ( V_16 ) ? 'B' : 'C' ) ;
goto V_325;
}
}
if ( F_102 ( V_16 ) )
V_214 -> V_401 |= V_402 ;
else
V_214 -> V_401 |= V_403 ;
F_135 ( & V_281 -> V_4 , & V_404 ) ;
if ( ! F_59 ( V_1 , & V_1 -> V_196 ) )
goto V_325;
if ( F_121 ( V_1 ,
V_1 -> V_196 . V_209 ) != true ) {
F_13 ( L_48 ,
F_102 ( V_16 ) ? 'B' : 'C' ) ;
goto V_325;
}
F_101 ( V_214 , V_1 , V_16 ) ;
if ( ! F_24 ( V_1 ) )
goto V_325;
if ( ! F_29 ( V_1 ,
& V_1 -> V_189 ,
& V_1 -> V_191 ) )
goto V_325;
F_13 ( L_49
L_50
L_51
L_52 ,
F_15 ( V_1 ) ,
V_1 -> V_196 . V_198 , V_1 -> V_196 . V_199 ,
V_1 -> V_196 . V_200 ,
V_1 -> V_189 / 1000 ,
V_1 -> V_191 / 1000 ,
( V_1 -> V_196 . V_203 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_196 . V_203 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_196 . V_209 &
( V_313 | V_330 ) ? 'Y' : 'N' ,
V_1 -> V_196 . V_209 &
( V_314 | V_331 ) ? 'Y' : 'N' ) ;
return true ;
V_325:
F_136 ( & V_281 -> V_4 ) ;
F_98 ( & V_1 -> V_212 ) ;
F_67 ( V_1 ) ;
return false ;
}
