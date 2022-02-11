static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static struct V_6 * F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_4 ) ;
}
static int
F_7 ( struct V_1 * V_1 )
{
int V_10 = V_1 -> V_11 [ V_12 ] ;
switch ( V_10 ) {
case V_13 :
case V_14 :
case V_15 :
break;
default:
F_8 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_13 ;
break;
}
return V_10 ;
}
static T_1 F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_16 , V_17 ;
V_16 = 4 ;
if ( F_10 ( V_7 ) && V_3 -> V_18 == V_19 &&
( V_3 -> V_20 & V_21 ) == 0 )
V_16 = 2 ;
V_17 = F_11 ( V_1 -> V_11 ) ;
return F_12 ( V_16 , V_17 ) ;
}
static int
F_13 ( int V_22 , int V_23 )
{
return ( V_22 * V_23 + 9 ) / 10 ;
}
static int
F_14 ( int V_24 , int V_25 )
{
return ( V_24 * V_25 * 8 ) / 10 ;
}
static enum V_26
F_15 ( struct V_8 * V_9 ,
struct V_27 * V_28 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_27 * V_30 = V_29 -> V_31 . V_30 ;
int V_32 = V_28 -> clock ;
int V_33 , V_34 , V_25 , V_24 ;
if ( F_1 ( V_1 ) && V_30 ) {
if ( V_28 -> V_35 > V_30 -> V_35 )
return V_36 ;
if ( V_28 -> V_37 > V_30 -> V_37 )
return V_36 ;
V_32 = V_30 -> clock ;
}
V_24 = F_17 ( V_1 ) ;
V_25 = F_9 ( V_1 ) ;
V_33 = F_14 ( V_24 , V_25 ) ;
V_34 = F_13 ( V_32 , 18 ) ;
if ( V_34 > V_33 )
return V_38 ;
if ( V_28 -> clock < 10000 )
return V_39 ;
if ( V_28 -> V_40 & V_41 )
return V_42 ;
return V_43 ;
}
T_2 F_18 ( const T_3 * V_44 , int V_45 )
{
int V_46 ;
T_2 V_47 = 0 ;
if ( V_45 > 4 )
V_45 = 4 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ )
V_47 |= ( ( T_2 ) V_44 [ V_46 ] ) << ( ( 3 - V_46 ) * 8 ) ;
return V_47 ;
}
static void F_19 ( T_2 V_44 , T_3 * V_48 , int V_49 )
{
int V_46 ;
if ( V_49 > 4 )
V_49 = 4 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ )
V_48 [ V_46 ] = V_44 >> ( ( 3 - V_46 ) * 8 ) ;
}
static int
F_20 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_53 ;
if ( F_21 ( V_7 ) )
return 200 ;
V_53 = F_22 ( V_54 ) ;
switch ( V_53 & V_55 ) {
case V_56 :
return 100 ;
case V_57 :
return 133 ;
case V_58 :
return 166 ;
case V_59 :
return 200 ;
case V_60 :
return 266 ;
case V_61 :
return 333 ;
case V_62 :
case V_63 :
return 400 ;
default:
return 133 ;
}
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_65 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
V_67 = F_24 ( V_65 ) ;
F_25 ( V_51 , V_67 ) ;
F_26 ( & V_51 -> V_68 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_65 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
F_28 ( & V_51 -> V_68 ) ;
V_67 = F_24 ( V_65 ) ;
F_29 ( V_51 , V_67 ) ;
}
static void
F_30 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_69 V_69 = V_1 -> V_70 ;
bool V_71 ;
T_2 V_72 ;
if ( F_8 ( F_22 ( V_1 -> V_73 ) & V_74 ,
L_2 ,
F_31 ( V_69 ) , F_32 ( V_3 -> V_18 ) ) )
return;
F_33 ( L_3 ,
F_31 ( V_69 ) , F_32 ( V_3 -> V_18 ) ) ;
V_72 = F_22 ( V_1 -> V_73 ) & V_75 ;
V_72 |= V_76 | V_77 ;
V_72 |= F_34 ( 1 ) ;
V_72 |= V_78 ;
if ( F_35 ( V_7 ) )
V_72 |= F_36 ( V_69 ) ;
else if ( V_69 == V_79 )
V_72 |= V_80 ;
V_71 = F_22 ( F_37 ( V_69 ) ) & V_81 ;
if ( ! V_71 )
F_38 ( V_7 , V_69 , F_35 ( V_7 ) ?
& V_82 [ 0 ] . V_83 : & V_84 [ 0 ] . V_83 ) ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
F_39 ( V_1 -> V_73 , V_72 | V_74 ) ;
F_40 ( V_1 -> V_73 ) ;
F_39 ( V_1 -> V_73 , V_72 & ~ V_74 ) ;
F_40 ( V_1 -> V_73 ) ;
if ( ! V_71 )
F_41 ( V_7 , V_69 ) ;
}
static enum V_69
F_42 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_64 * V_65 ;
unsigned int V_85 = ( 1 << V_86 ) | ( 1 << V_79 ) ;
enum V_69 V_69 ;
F_43 ( & V_51 -> V_68 ) ;
F_44 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_70 != V_87 )
return V_1 -> V_70 ;
F_45 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_88 ;
if ( V_65 -> type != V_5 )
continue;
V_88 = F_5 ( & V_65 -> V_4 ) ;
if ( V_88 -> V_70 != V_87 )
V_85 &= ~ ( 1 << V_88 -> V_70 ) ;
}
if ( F_44 ( V_85 == 0 ) )
V_69 = V_86 ;
else
V_69 = F_46 ( V_85 ) - 1 ;
F_47 ( V_7 , V_69 ) ;
V_1 -> V_70 = V_69 ;
F_33 ( L_4 ,
F_31 ( V_1 -> V_70 ) ,
F_32 ( V_3 -> V_18 ) ) ;
F_48 ( V_7 , V_1 ) ;
F_49 ( V_7 , V_1 ) ;
F_30 ( V_1 ) ;
return V_1 -> V_70 ;
}
static bool F_50 ( struct V_50 * V_51 ,
enum V_69 V_69 )
{
return F_22 ( F_51 ( V_69 ) ) & V_89 ;
}
static bool F_52 ( struct V_50 * V_51 ,
enum V_69 V_69 )
{
return F_22 ( F_53 ( V_69 ) ) & V_90 ;
}
static bool F_54 ( struct V_50 * V_51 ,
enum V_69 V_69 )
{
return true ;
}
static enum V_69
F_55 ( struct V_50 * V_51 ,
enum V_18 V_18 ,
T_4 V_91 )
{
enum V_69 V_69 ;
for ( V_69 = V_86 ; V_69 <= V_79 ; V_69 ++ ) {
T_5 V_92 = F_22 ( F_56 ( V_69 ) ) &
V_93 ;
if ( V_92 != F_57 ( V_18 ) )
continue;
if ( ! V_91 ( V_51 , V_69 ) )
continue;
return V_69 ;
}
return V_87 ;
}
static void
F_58 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
F_43 ( & V_51 -> V_68 ) ;
V_1 -> V_70 = F_55 ( V_51 , V_18 ,
F_50 ) ;
if ( V_1 -> V_70 == V_87 )
V_1 -> V_70 = F_55 ( V_51 , V_18 ,
F_52 ) ;
if ( V_1 -> V_70 == V_87 )
V_1 -> V_70 = F_55 ( V_51 , V_18 ,
F_54 ) ;
if ( V_1 -> V_70 == V_87 ) {
F_33 ( L_5 ,
F_32 ( V_18 ) ) ;
return;
}
F_33 ( L_6 ,
F_32 ( V_18 ) , F_31 ( V_1 -> V_70 ) ) ;
F_48 ( V_7 , V_1 ) ;
F_49 ( V_7 , V_1 ) ;
}
void F_59 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = V_51 -> V_7 ;
struct V_64 * V_65 ;
if ( F_44 ( ! F_21 ( V_7 ) ) )
return;
F_45 (encoder, &dev->mode_config.encoder_list, base.head) {
struct V_1 * V_1 ;
if ( V_65 -> type != V_5 )
continue;
V_1 = F_5 ( & V_65 -> V_4 ) ;
V_1 -> V_70 = V_87 ;
}
}
static T_5 F_60 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_61 ( V_7 ) )
return V_94 ;
else
return F_53 ( F_42 ( V_1 ) ) ;
}
static T_5 F_62 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_61 ( V_7 ) )
return V_95 ;
else
return F_51 ( F_42 ( V_1 ) ) ;
}
static int F_63 ( struct V_96 * V_97 , unsigned long V_98 ,
void * V_99 )
{
struct V_1 * V_1 = F_64 ( V_97 , F_65 ( * V_1 ) ,
V_100 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_101 ;
T_5 V_102 , V_103 ;
if ( ! F_1 ( V_1 ) || V_98 != V_104 )
return 0 ;
F_23 ( V_1 ) ;
if ( F_21 ( V_7 ) ) {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_102 = F_53 ( V_69 ) ;
V_103 = F_66 ( V_69 ) ;
V_101 = F_22 ( V_103 ) ;
V_101 &= V_105 ;
F_39 ( V_103 , V_101 | 0x1F ) ;
F_39 ( V_102 , V_106 | V_107 ) ;
F_67 ( V_1 -> V_108 ) ;
}
F_27 ( V_1 ) ;
return 0 ;
}
static bool F_68 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_21 ( V_7 ) &&
V_1 -> V_70 == V_87 )
return false ;
return ( F_22 ( F_62 ( V_1 ) ) & V_89 ) != 0 ;
}
static bool F_69 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_21 ( V_7 ) &&
V_1 -> V_70 == V_87 )
return false ;
return F_22 ( F_60 ( V_1 ) ) & V_90 ;
}
static void
F_70 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_68 ( V_1 ) && ! F_69 ( V_1 ) ) {
F_8 ( 1 , L_7 ) ;
F_33 ( L_8 ,
F_22 ( F_62 ( V_1 ) ) ,
F_22 ( F_60 ( V_1 ) ) ) ;
}
}
static T_2
F_71 ( struct V_1 * V_1 , bool V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_110 = V_1 -> V_111 ;
T_2 V_112 ;
bool V_113 ;
#define F_72 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_109 )
V_113 = F_73 ( V_51 -> V_114 , F_72 ,
F_74 ( 10 ) ) ;
else
V_113 = F_75 ( F_72 , 10 ) == 0 ;
if ( ! V_113 )
F_76 ( L_9 ,
V_109 ) ;
#undef F_72
return V_112 ;
}
static T_2 F_77 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_115 ? 0 : F_20 ( V_7 ) / 2 ;
}
static T_2 F_78 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
if ( V_115 )
return 0 ;
if ( V_3 -> V_18 == V_19 ) {
if ( F_79 ( V_7 ) || F_80 ( V_7 ) )
return 200 ;
else
return 225 ;
} else {
return F_81 ( F_82 ( V_7 ) , 2 ) ;
}
}
static T_2 F_83 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( V_3 -> V_18 == V_19 ) {
if ( V_115 )
return 0 ;
return F_84 ( F_85 ( V_51 ) , 2000 ) ;
} else if ( V_51 -> V_116 == V_117 ) {
switch ( V_115 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_115 ? 0 : F_81 ( F_82 ( V_7 ) , 2 ) ;
}
}
static T_2 F_86 ( struct V_1 * V_1 , int V_115 )
{
return V_115 ? 0 : 100 ;
}
static T_2 F_87 ( struct V_1 * V_1 , int V_115 )
{
return V_115 ? 0 : 1 ;
}
static T_2 F_88 ( struct V_1 * V_1 ,
bool V_109 ,
int V_118 ,
T_2 V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_120 , V_121 ;
if ( F_79 ( V_7 ) )
V_120 = 3 ;
else
V_120 = 5 ;
if ( F_89 ( V_7 ) && V_1 -> V_111 == V_122 )
V_121 = V_123 ;
else
V_121 = V_124 ;
return V_125 |
V_126 |
( V_109 ? V_127 : 0 ) |
V_128 |
V_121 |
V_129 |
( V_118 << V_130 ) |
( V_120 << V_131 ) |
( V_119 << V_132 ) ;
}
static T_2 F_90 ( struct V_1 * V_1 ,
bool V_109 ,
int V_118 ,
T_2 V_99 )
{
return V_125 |
V_126 |
( V_109 ? V_127 : 0 ) |
V_128 |
V_133 |
V_129 |
( V_118 << V_130 ) |
F_91 ( 32 ) ;
}
static int
F_92 ( struct V_1 * V_1 ,
const T_3 * V_134 , int V_118 ,
T_3 * V_135 , int V_136 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_110 = V_1 -> V_111 ;
T_2 V_137 = V_110 + 4 ;
T_2 V_119 ;
int V_46 , V_138 , V_139 ;
T_2 V_112 ;
int V_140 , clock = 0 ;
bool V_109 = F_93 ( V_7 ) ;
bool V_141 ;
F_23 ( V_1 ) ;
V_141 = F_94 ( V_1 ) ;
F_95 ( & V_51 -> V_142 , 0 ) ;
F_70 ( V_1 ) ;
F_96 ( V_51 ) ;
for ( V_140 = 0 ; V_140 < 3 ; V_140 ++ ) {
V_112 = F_97 ( V_110 ) ;
if ( ( V_112 & V_125 ) == 0 )
break;
F_67 ( 1 ) ;
}
if ( V_140 == 3 ) {
F_8 ( 1 , L_10 ,
F_22 ( V_110 ) ) ;
V_138 = - V_143 ;
goto V_144;
}
if ( F_44 ( V_118 > 20 || V_136 > 20 ) ) {
V_138 = - V_145 ;
goto V_144;
}
while ( ( V_119 = V_1 -> V_146 ( V_1 , clock ++ ) ) ) {
T_5 V_147 = V_1 -> V_148 ( V_1 ,
V_109 ,
V_118 ,
V_119 ) ;
for ( V_140 = 0 ; V_140 < 5 ; V_140 ++ ) {
for ( V_46 = 0 ; V_46 < V_118 ; V_46 += 4 )
F_39 ( V_137 + V_46 ,
F_18 ( V_134 + V_46 ,
V_118 - V_46 ) ) ;
F_39 ( V_110 , V_147 ) ;
V_112 = F_71 ( V_1 , V_109 ) ;
F_39 ( V_110 ,
V_112 |
V_126 |
V_128 |
V_129 ) ;
if ( V_112 & ( V_128 |
V_129 ) )
continue;
if ( V_112 & V_126 )
goto V_113;
}
}
if ( ( V_112 & V_126 ) == 0 ) {
F_76 ( L_11 , V_112 ) ;
V_138 = - V_143 ;
goto V_144;
}
V_113:
if ( V_112 & V_129 ) {
F_76 ( L_12 , V_112 ) ;
V_138 = - V_149 ;
goto V_144;
}
if ( V_112 & V_128 ) {
F_33 ( L_13 , V_112 ) ;
V_138 = - V_150 ;
goto V_144;
}
V_139 = ( ( V_112 & V_151 ) >>
V_130 ) ;
if ( V_139 > V_136 )
V_139 = V_136 ;
for ( V_46 = 0 ; V_46 < V_139 ; V_46 += 4 )
F_19 ( F_22 ( V_137 + V_46 ) ,
V_135 + V_46 , V_139 - V_46 ) ;
V_138 = V_139 ;
V_144:
F_95 ( & V_51 -> V_142 , V_152 ) ;
F_98 ( V_51 ) ;
if ( V_141 )
F_99 ( V_1 , false ) ;
F_27 ( V_1 ) ;
return V_138 ;
}
static T_6
F_100 ( struct V_153 * V_154 , struct V_155 * V_156 )
{
struct V_1 * V_1 = F_64 ( V_154 , struct V_1 , V_154 ) ;
T_3 V_157 [ 20 ] , V_158 [ 20 ] ;
T_7 V_159 , V_160 ;
int V_138 ;
V_157 [ 0 ] = ( V_156 -> V_161 << 4 ) |
( ( V_156 -> V_162 >> 16 ) & 0xf ) ;
V_157 [ 1 ] = ( V_156 -> V_162 >> 8 ) & 0xff ;
V_157 [ 2 ] = V_156 -> V_162 & 0xff ;
V_157 [ 3 ] = V_156 -> V_163 - 1 ;
switch ( V_156 -> V_161 & ~ V_164 ) {
case V_165 :
case V_166 :
V_159 = V_156 -> V_163 ? V_167 + V_156 -> V_163 : V_168 ;
V_160 = 2 ;
if ( F_44 ( V_159 > 20 ) )
return - V_145 ;
memcpy ( V_157 + V_167 , V_156 -> V_169 , V_156 -> V_163 ) ;
V_138 = F_92 ( V_1 , V_157 , V_159 , V_158 , V_160 ) ;
if ( V_138 > 0 ) {
V_156 -> V_170 = V_158 [ 0 ] >> 4 ;
if ( V_138 > 1 ) {
V_138 = F_101 ( int , V_158 [ 1 ] , 0 , V_156 -> V_163 ) ;
} else {
V_138 = V_156 -> V_163 ;
}
}
break;
case V_171 :
case V_172 :
V_159 = V_156 -> V_163 ? V_167 : V_168 ;
V_160 = V_156 -> V_163 + 1 ;
if ( F_44 ( V_160 > 20 ) )
return - V_145 ;
V_138 = F_92 ( V_1 , V_157 , V_159 , V_158 , V_160 ) ;
if ( V_138 > 0 ) {
V_156 -> V_170 = V_158 [ 0 ] >> 4 ;
V_138 -- ;
memcpy ( V_156 -> V_169 , V_158 + 1 , V_138 ) ;
}
break;
default:
V_138 = - V_173 ;
break;
}
return V_138 ;
}
static void
F_102 ( struct V_1 * V_1 , struct V_29 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
const char * V_174 = NULL ;
int V_138 ;
switch ( V_18 ) {
case V_19 :
V_1 -> V_111 = V_122 ;
V_174 = L_14 ;
break;
case V_175 :
V_1 -> V_111 = V_176 ;
V_174 = L_15 ;
break;
case V_177 :
V_1 -> V_111 = V_178 ;
V_174 = L_16 ;
break;
case V_179 :
V_1 -> V_111 = V_180 ;
V_174 = L_17 ;
break;
default:
F_103 () ;
}
if ( ! F_104 ( V_7 ) && ! F_89 ( V_7 ) )
V_1 -> V_111 = V_1 -> V_73 + 0x10 ;
V_1 -> V_154 . V_174 = V_174 ;
V_1 -> V_154 . V_7 = V_7 -> V_7 ;
V_1 -> V_154 . V_181 = F_100 ;
F_33 ( L_18 , V_174 ,
V_9 -> V_4 . V_182 -> V_183 . V_174 ) ;
V_138 = F_105 ( & V_1 -> V_154 ) ;
if ( V_138 < 0 ) {
F_76 ( L_19 ,
V_174 , V_138 ) ;
return;
}
V_138 = F_106 ( & V_9 -> V_4 . V_182 -> V_183 ,
& V_1 -> V_154 . V_184 . V_7 . V_183 ,
V_1 -> V_154 . V_184 . V_7 . V_183 . V_174 ) ;
if ( V_138 < 0 ) {
F_76 ( L_20 , V_174 , V_138 ) ;
F_107 ( & V_1 -> V_154 ) ;
}
}
static void
F_108 ( struct V_29 * V_29 )
{
struct V_1 * V_1 = F_4 ( & V_29 -> V_4 ) ;
if ( ! V_29 -> V_185 )
F_109 ( & V_29 -> V_4 . V_182 -> V_183 ,
V_1 -> V_154 . V_184 . V_7 . V_183 . V_174 ) ;
F_110 ( V_29 ) ;
}
static void
F_111 ( struct V_186 * V_187 , int V_188 )
{
T_5 V_189 ;
V_187 -> V_190 = V_191 ;
V_187 -> V_192 . V_193 = 0 ;
V_187 -> V_192 . V_194 = 0 ;
V_189 = F_112 ( V_191 ) ;
switch ( V_188 / 2 ) {
case 81000 :
V_189 |= F_113 ( V_195 ,
V_191 ) ;
break;
case 135000 :
V_189 |= F_113 ( V_196 ,
V_191 ) ;
break;
case 270000 :
V_189 |= F_113 ( V_197 ,
V_191 ) ;
break;
case 162000 :
V_189 |= F_113 ( V_198 ,
V_191 ) ;
break;
case 108000 :
V_189 |= F_113 ( V_199 ,
V_191 ) ;
break;
case 216000 :
V_189 |= F_113 ( V_200 ,
V_191 ) ;
break;
}
V_187 -> V_192 . V_189 = V_189 ;
}
static void
F_114 ( struct V_186 * V_187 , int V_201 )
{
switch ( V_201 ) {
case V_13 :
V_187 -> V_190 = V_202 ;
break;
case V_14 :
V_187 -> V_190 = V_203 ;
break;
case V_15 :
V_187 -> V_190 = V_204 ;
break;
}
}
static int
F_115 ( struct V_1 * V_1 , const int * * V_205 )
{
if ( V_1 -> V_206 ) {
* V_205 = V_1 -> V_205 ;
return V_1 -> V_206 ;
}
* V_205 = V_207 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
static int
F_116 ( struct V_6 * V_7 , const int * * V_208 )
{
if ( F_117 ( V_7 ) -> V_209 >= 9 ) {
* V_208 = V_210 ;
return F_118 ( V_210 ) ;
} else if ( F_35 ( V_7 ) ) {
* V_208 = V_211 ;
return F_118 ( V_211 ) ;
}
* V_208 = V_207 ;
if ( F_119 ( V_7 ) && F_120 ( V_7 ) <= V_212 )
return ( V_14 >> 3 ) + 1 ;
else if ( F_117 ( V_7 ) -> V_209 >= 8 ||
( F_104 ( V_7 ) && ! F_121 ( V_7 ) ) )
return ( V_15 >> 3 ) + 1 ;
else
return ( V_14 >> 3 ) + 1 ;
}
static void
F_122 ( struct V_64 * V_65 ,
struct V_186 * V_187 , int V_201 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
const struct V_213 * V_214 = NULL ;
int V_46 , V_215 = 0 ;
if ( F_123 ( V_7 ) ) {
V_214 = V_216 ;
V_215 = F_118 ( V_216 ) ;
} else if ( F_61 ( V_7 ) ) {
V_214 = V_217 ;
V_215 = F_118 ( V_217 ) ;
} else if ( F_35 ( V_7 ) ) {
V_214 = V_82 ;
V_215 = F_118 ( V_82 ) ;
} else if ( F_21 ( V_7 ) ) {
V_214 = V_84 ;
V_215 = F_118 ( V_84 ) ;
}
if ( V_214 && V_215 ) {
for ( V_46 = 0 ; V_46 < V_215 ; V_46 ++ ) {
if ( V_201 == V_214 [ V_46 ] . V_201 ) {
V_187 -> V_83 = V_214 [ V_46 ] . V_83 ;
V_187 -> V_218 = true ;
break;
}
}
}
}
static int F_124 ( const int * V_208 , int V_219 ,
const int * V_205 , int V_220 ,
int * V_221 )
{
int V_46 = 0 , V_222 = 0 , V_223 = 0 ;
while ( V_46 < V_219 && V_222 < V_220 ) {
if ( V_208 [ V_46 ] == V_205 [ V_222 ] ) {
if ( F_44 ( V_223 >= V_224 ) )
return V_223 ;
V_221 [ V_223 ] = V_208 [ V_46 ] ;
++ V_223 ;
++ V_46 ;
++ V_222 ;
} else if ( V_208 [ V_46 ] < V_205 [ V_222 ] ) {
++ V_46 ;
} else {
++ V_222 ;
}
}
return V_223 ;
}
static int F_125 ( struct V_1 * V_1 ,
int * V_221 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_208 , * V_205 ;
int V_219 , V_220 ;
V_220 = F_115 ( V_1 , & V_205 ) ;
V_219 = F_116 ( V_7 , & V_208 ) ;
return F_124 ( V_208 , V_219 ,
V_205 , V_220 ,
V_221 ) ;
}
static void F_126 ( char * V_225 , T_7 V_226 ,
const int * V_227 , int V_228 )
{
int V_46 ;
V_225 [ 0 ] = '\0' ;
for ( V_46 = 0 ; V_46 < V_228 ; V_46 ++ ) {
int V_229 = snprintf ( V_225 , V_226 , L_21 , V_227 [ V_46 ] ) ;
if ( V_229 >= V_226 )
return;
V_225 += V_229 ;
V_226 -= V_229 ;
}
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_208 , * V_205 ;
int V_219 , V_220 , V_230 ;
int V_221 [ V_224 ] ;
char V_225 [ 128 ] ;
if ( ( V_231 & V_232 ) == 0 )
return;
V_219 = F_116 ( V_7 , & V_208 ) ;
F_126 ( V_225 , sizeof( V_225 ) , V_208 , V_219 ) ;
F_33 ( L_22 , V_225 ) ;
V_220 = F_115 ( V_1 , & V_205 ) ;
F_126 ( V_225 , sizeof( V_225 ) , V_205 , V_220 ) ;
F_33 ( L_23 , V_225 ) ;
V_230 = F_125 ( V_1 , V_221 ) ;
F_126 ( V_225 , sizeof( V_225 ) , V_221 , V_230 ) ;
F_33 ( L_24 , V_225 ) ;
}
static int F_128 ( int V_233 , const int * V_234 )
{
int V_46 = 0 ;
for ( V_46 = 0 ; V_46 < V_224 ; ++ V_46 )
if ( V_233 == V_234 [ V_46 ] )
break;
return V_46 ;
}
int
F_17 ( struct V_1 * V_1 )
{
int V_234 [ V_224 ] = {} ;
int V_226 ;
V_226 = F_125 ( V_1 , V_234 ) ;
if ( F_44 ( V_226 <= 0 ) )
return 162000 ;
return V_234 [ F_128 ( 0 , V_234 ) - 1 ] ;
}
int F_129 ( struct V_1 * V_1 , int V_235 )
{
return F_128 ( V_235 , V_1 -> V_205 ) ;
}
bool
F_130 ( struct V_64 * V_65 ,
struct V_186 * V_187 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_236 = & V_187 -> V_4 . V_236 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_237 * V_237 = F_131 ( V_187 -> V_4 . V_238 ) ;
struct V_29 * V_29 = V_1 -> V_239 ;
int V_240 , clock ;
int V_241 = 1 ;
int V_242 = F_9 ( V_1 ) ;
int V_243 = 0 ;
int V_244 ;
int V_23 , V_34 ;
int V_245 , V_188 ;
int V_221 [ V_224 ] = {} ;
int V_230 ;
V_230 = F_125 ( V_1 , V_221 ) ;
F_44 ( V_230 <= 0 ) ;
V_244 = V_230 - 1 ;
if ( F_61 ( V_7 ) && ! F_10 ( V_7 ) && V_18 != V_19 )
V_187 -> V_246 = true ;
V_187 -> V_247 = true ;
V_187 -> V_248 = false ;
V_187 -> V_249 = V_1 -> V_249 && V_18 != V_19 ;
if ( F_1 ( V_1 ) && V_29 -> V_31 . V_30 ) {
F_132 ( V_29 -> V_31 . V_30 ,
V_236 ) ;
if ( ! F_61 ( V_7 ) )
F_133 ( V_237 , V_187 ,
V_29 -> V_31 . V_250 ) ;
else
F_134 ( V_237 , V_187 ,
V_29 -> V_31 . V_250 ) ;
}
if ( V_236 -> V_40 & V_41 )
return false ;
F_33 ( L_25
L_26 ,
V_242 , V_221 [ V_244 ] ,
V_236 -> V_251 ) ;
V_23 = V_187 -> V_252 ;
if ( F_1 ( V_1 ) ) {
if ( V_51 -> V_253 . V_254 && V_51 -> V_253 . V_254 < V_23 ) {
F_33 ( L_27 ,
V_51 -> V_253 . V_254 ) ;
V_23 = V_51 -> V_253 . V_254 ;
}
V_241 = V_242 ;
V_243 = V_244 ;
}
for (; V_23 >= 6 * 3 ; V_23 -= 2 * 3 ) {
V_34 = F_13 ( V_236 -> V_251 ,
V_23 ) ;
for ( clock = V_243 ; clock <= V_244 ; clock ++ ) {
for ( V_240 = V_241 ;
V_240 <= V_242 ;
V_240 <<= 1 ) {
V_188 = V_221 [ clock ] ;
V_245 = F_14 ( V_188 ,
V_240 ) ;
if ( V_34 <= V_245 ) {
goto V_255;
}
}
}
}
return false ;
V_255:
if ( V_1 -> V_256 ) {
if ( V_23 != 18 && F_135 ( V_236 ) > 1 )
V_1 -> V_257 = V_258 ;
else
V_1 -> V_257 = 0 ;
}
if ( V_1 -> V_257 )
V_187 -> V_259 = true ;
V_1 -> V_240 = V_240 ;
if ( V_1 -> V_206 ) {
V_1 -> V_201 = 0 ;
V_1 -> V_260 =
F_129 ( V_1 , V_221 [ clock ] ) ;
} else {
V_1 -> V_201 =
F_136 ( V_221 [ clock ] ) ;
V_1 -> V_260 = 0 ;
}
V_187 -> V_252 = V_23 ;
V_187 -> V_261 = V_221 [ clock ] ;
F_33 ( L_28 ,
V_1 -> V_201 , V_1 -> V_240 ,
V_187 -> V_261 , V_23 ) ;
F_33 ( L_29 ,
V_34 , V_245 ) ;
F_137 ( V_23 , V_240 ,
V_236 -> V_251 ,
V_187 -> V_261 ,
& V_187 -> V_262 ) ;
if ( V_29 -> V_31 . V_263 != NULL &&
V_51 -> V_264 . type == V_265 ) {
V_187 -> V_248 = true ;
F_137 ( V_23 , V_240 ,
V_29 -> V_31 . V_263 -> clock ,
V_187 -> V_261 ,
& V_187 -> V_266 ) ;
}
if ( F_119 ( V_7 ) && F_1 ( V_1 ) )
F_111 ( V_187 , V_221 [ clock ] ) ;
else if ( F_104 ( V_7 ) || F_89 ( V_7 ) )
F_114 ( V_187 , V_1 -> V_201 ) ;
else
F_122 ( V_65 , V_187 , V_1 -> V_201 ) ;
return true ;
}
static void F_138 ( struct V_1 * V_1 )
{
struct V_2 * V_267 = F_2 ( V_1 ) ;
struct V_237 * V_238 = F_131 ( V_267 -> V_4 . V_4 . V_238 ) ;
struct V_6 * V_7 = V_238 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_268 ;
F_33 ( L_30 ,
V_238 -> V_269 -> V_261 ) ;
V_268 = F_22 ( V_270 ) ;
V_268 &= ~ V_271 ;
if ( V_238 -> V_269 -> V_261 == 162000 ) {
F_33 ( L_31 ) ;
V_268 |= V_272 ;
V_1 -> V_72 |= V_272 ;
} else {
V_268 |= V_273 ;
V_1 -> V_72 |= V_273 ;
}
F_39 ( V_270 , V_268 ) ;
F_40 ( V_270 ) ;
F_139 ( 500 ) ;
}
static void F_140 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_237 * V_238 = F_131 ( V_65 -> V_4 . V_238 ) ;
struct V_27 * V_236 = & V_238 -> V_269 -> V_4 . V_236 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) & V_75 ;
V_1 -> V_72 |= V_76 | V_77 ;
V_1 -> V_72 |= F_34 ( V_1 -> V_240 ) ;
if ( V_238 -> V_269 -> V_249 )
V_1 -> V_72 |= V_274 ;
if ( V_18 == V_19 && F_80 ( V_7 ) && ! F_21 ( V_7 ) ) {
if ( V_236 -> V_40 & V_275 )
V_1 -> V_72 |= V_276 ;
if ( V_236 -> V_40 & V_277 )
V_1 -> V_72 |= V_278 ;
V_1 -> V_72 |= V_279 ;
if ( F_141 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_280 ;
V_1 -> V_72 |= V_238 -> V_69 << 29 ;
} else if ( ! F_142 ( V_7 ) || V_18 == V_19 ) {
if ( ! F_61 ( V_7 ) && ! F_21 ( V_7 ) )
V_1 -> V_72 |= V_1 -> V_257 ;
if ( V_236 -> V_40 & V_275 )
V_1 -> V_72 |= V_276 ;
if ( V_236 -> V_40 & V_277 )
V_1 -> V_72 |= V_278 ;
V_1 -> V_72 |= V_281 ;
if ( F_141 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_280 ;
if ( ! F_35 ( V_7 ) ) {
if ( V_238 -> V_69 == 1 )
V_1 -> V_72 |= V_80 ;
} else {
V_1 -> V_72 |= F_36 ( V_238 -> V_69 ) ;
}
} else {
V_1 -> V_72 |= V_279 ;
}
}
static void F_143 ( struct V_1 * V_1 ,
T_5 V_282 ,
T_5 V_283 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_284 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
V_284 = F_62 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_33 ( L_32 ,
V_282 , V_283 ,
F_22 ( V_284 ) ,
F_22 ( V_102 ) ) ;
if ( F_144 ( ( F_22 ( V_284 ) & V_282 ) == V_283 , 5000 , 10 ) ) {
F_76 ( L_33 ,
F_22 ( V_284 ) ,
F_22 ( V_102 ) ) ;
}
F_33 ( L_34 ) ;
}
static void F_145 ( struct V_1 * V_1 )
{
F_33 ( L_35 ) ;
F_143 ( V_1 , V_285 , V_286 ) ;
}
static void F_146 ( struct V_1 * V_1 )
{
F_33 ( L_36 ) ;
F_143 ( V_1 , V_287 , V_288 ) ;
}
static void F_147 ( struct V_1 * V_1 )
{
F_33 ( L_37 ) ;
F_148 ( V_1 -> V_289 ,
V_1 -> V_108 ) ;
F_143 ( V_1 , V_290 , V_291 ) ;
}
static void F_149 ( struct V_1 * V_1 )
{
F_148 ( V_1 -> V_292 ,
V_1 -> V_293 ) ;
}
static void F_150 ( struct V_1 * V_1 )
{
F_148 ( V_1 -> V_294 ,
V_1 -> V_295 ) ;
}
static T_5 F_151 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_296 ;
F_43 ( & V_51 -> V_68 ) ;
V_296 = F_22 ( F_60 ( V_1 ) ) ;
V_296 &= ~ V_297 ;
V_296 |= V_106 ;
return V_296 ;
}
static bool F_94 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_298 ;
T_5 V_284 , V_102 ;
bool V_299 = ! V_1 -> V_300 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_152 ( & V_1 -> V_301 ) ;
V_1 -> V_300 = true ;
if ( F_69 ( V_1 ) )
return V_299 ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
F_33 ( L_38 ,
F_32 ( V_3 -> V_18 ) ) ;
if ( ! F_68 ( V_1 ) )
F_147 ( V_1 ) ;
V_298 = F_151 ( V_1 ) ;
V_298 |= V_90 ;
V_284 = F_62 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
F_33 ( L_39 ,
F_22 ( V_284 ) , F_22 ( V_102 ) ) ;
if ( ! F_68 ( V_1 ) ) {
F_33 ( L_40 ,
F_32 ( V_3 -> V_18 ) ) ;
F_67 ( V_1 -> V_302 ) ;
}
return V_299 ;
}
void F_153 ( struct V_1 * V_1 )
{
bool V_141 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_141 = F_94 ( V_1 ) ;
F_27 ( V_1 ) ;
F_154 ( ! V_141 , L_41 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
}
static void F_155 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
enum V_66 V_67 ;
T_5 V_298 ;
T_5 V_284 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
F_44 ( V_1 -> V_300 ) ;
if ( ! F_69 ( V_1 ) )
return;
F_33 ( L_42 ,
F_32 ( V_3 -> V_18 ) ) ;
V_298 = F_151 ( V_1 ) ;
V_298 &= ~ V_90 ;
V_102 = F_60 ( V_1 ) ;
V_284 = F_62 ( V_1 ) ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
F_33 ( L_39 ,
F_22 ( V_284 ) , F_22 ( V_102 ) ) ;
if ( ( V_298 & V_303 ) == 0 )
V_1 -> V_289 = V_304 ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
static void F_156 ( struct V_305 * V_306 )
{
struct V_1 * V_1 = F_64 ( F_157 ( V_306 ) ,
struct V_1 , V_301 ) ;
F_23 ( V_1 ) ;
if ( ! V_1 -> V_300 )
F_155 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_158 ( struct V_1 * V_1 )
{
unsigned long V_307 ;
V_307 = F_159 ( V_1 -> V_108 * 5 ) ;
F_160 ( & V_1 -> V_301 , V_307 ) ;
}
static void F_99 ( struct V_1 * V_1 , bool V_308 )
{
struct V_50 * V_51 =
F_3 ( V_1 ) -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_154 ( ! V_1 -> V_300 , L_43 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_1 -> V_300 = false ;
if ( V_308 )
F_155 ( V_1 ) ;
else
F_158 ( V_1 ) ;
}
static void F_161 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_298 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_44 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
if ( F_8 ( F_68 ( V_1 ) ,
L_45 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) )
return;
F_147 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
V_298 = F_151 ( V_1 ) ;
if ( F_162 ( V_7 ) ) {
V_298 &= ~ V_309 ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
}
V_298 |= V_303 ;
if ( ! F_162 ( V_7 ) )
V_298 |= V_309 ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
F_145 ( V_1 ) ;
V_1 -> V_292 = V_304 ;
if ( F_162 ( V_7 ) ) {
V_298 |= V_309 ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
}
}
void F_163 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_161 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_298 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_46 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
F_8 ( ! V_1 -> V_300 , L_47 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_298 = F_151 ( V_1 ) ;
V_298 &= ~ ( V_303 | V_309 | V_90 |
V_310 ) ;
V_102 = F_60 ( V_1 ) ;
V_1 -> V_300 = false ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
V_1 -> V_289 = V_304 ;
F_146 ( V_1 ) ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
void F_165 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_164 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_298 ;
T_5 V_102 ;
F_149 ( V_1 ) ;
F_23 ( V_1 ) ;
V_298 = F_151 ( V_1 ) ;
V_298 |= V_310 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
}
void F_167 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_48 ) ;
F_168 ( V_1 -> V_239 ) ;
F_166 ( V_1 ) ;
}
static void F_169 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_298 ;
T_5 V_102 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_298 = F_151 ( V_1 ) ;
V_298 &= ~ V_310 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_298 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
V_1 -> V_294 = V_304 ;
F_150 ( V_1 ) ;
}
void F_170 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_48 ) ;
F_169 ( V_1 ) ;
F_171 ( V_1 -> V_239 ) ;
}
static void F_172 ( struct V_29 * V_9 ,
bool V_311 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_312 ;
F_23 ( V_1 ) ;
V_312 = F_151 ( V_1 ) & V_310 ;
F_27 ( V_1 ) ;
if ( V_312 == V_311 )
return;
F_33 ( L_49 ,
V_311 ? L_50 : L_51 ) ;
if ( V_311 )
F_166 ( V_1 ) ;
else
F_169 ( V_1 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_313 * V_238 = V_3 -> V_4 . V_4 . V_238 ;
struct V_6 * V_7 = V_238 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_268 ;
F_174 ( V_51 ,
F_131 ( V_238 ) -> V_69 ) ;
F_33 ( L_48 ) ;
V_268 = F_22 ( V_270 ) ;
F_8 ( V_268 & V_314 , L_52 ) ;
F_8 ( V_268 & V_74 , L_53 ) ;
V_1 -> V_72 &= ~ ( V_74 | V_274 ) ;
V_1 -> V_72 |= V_314 ;
F_39 ( V_270 , V_1 -> V_72 ) ;
F_40 ( V_270 ) ;
F_139 ( 200 ) ;
}
static void F_175 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_313 * V_238 = V_3 -> V_4 . V_4 . V_238 ;
struct V_6 * V_7 = V_238 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_268 ;
F_174 ( V_51 ,
F_131 ( V_238 ) -> V_69 ) ;
V_268 = F_22 ( V_270 ) ;
F_8 ( ( V_268 & V_314 ) == 0 ,
L_54 ) ;
F_8 ( V_268 & V_74 , L_53 ) ;
V_268 &= ~ V_314 ;
F_39 ( V_270 , V_268 ) ;
F_40 ( V_270 ) ;
F_139 ( 200 ) ;
}
void F_176 ( struct V_1 * V_1 , int V_28 )
{
int V_138 , V_46 ;
if ( V_1 -> V_11 [ V_315 ] < 0x11 )
return;
if ( V_28 != V_316 ) {
V_138 = F_177 ( & V_1 -> V_154 , V_317 ,
V_318 ) ;
} else {
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_138 = F_177 ( & V_1 -> V_154 , V_317 ,
V_319 ) ;
if ( V_138 == 1 )
break;
F_67 ( 1 ) ;
}
}
if ( V_138 != 1 )
F_33 ( L_55 ,
V_28 == V_316 ? L_50 : L_51 ) ;
}
static bool F_178 ( struct V_64 * V_65 ,
enum V_69 * V_69 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_88 ;
V_67 = F_24 ( V_65 ) ;
if ( ! F_179 ( V_51 , V_67 ) )
return false ;
V_88 = F_22 ( V_1 -> V_73 ) ;
if ( ! ( V_88 & V_74 ) )
return false ;
if ( V_18 == V_19 && F_80 ( V_7 ) && ! F_21 ( V_7 ) ) {
* V_69 = F_180 ( V_88 ) ;
} else if ( F_35 ( V_7 ) ) {
* V_69 = F_181 ( V_88 ) ;
} else if ( ! F_142 ( V_7 ) || V_18 == V_19 ) {
* V_69 = F_182 ( V_88 ) ;
} else {
T_5 V_320 ;
T_5 V_321 ;
int V_46 ;
switch ( V_1 -> V_73 ) {
case V_322 :
V_320 = V_323 ;
break;
case V_324 :
V_320 = V_325 ;
break;
case V_326 :
V_320 = V_327 ;
break;
default:
return true ;
}
F_183 (dev_priv, i) {
V_321 = F_22 ( F_184 ( V_46 ) ) ;
if ( ( V_321 & V_328 ) == V_320 ) {
* V_69 = V_46 ;
return true ;
}
}
F_33 ( L_56 ,
V_1 -> V_73 ) ;
}
return true ;
}
static void F_185 ( struct V_64 * V_65 ,
struct V_186 * V_187 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
T_5 V_88 , V_40 = 0 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_237 * V_238 = F_131 ( V_65 -> V_4 . V_238 ) ;
int V_329 ;
V_88 = F_22 ( V_1 -> V_73 ) ;
V_187 -> V_249 = V_88 & V_274 && V_18 != V_19 ;
if ( ( V_18 == V_19 ) || ! F_142 ( V_7 ) ) {
if ( V_88 & V_276 )
V_40 |= V_275 ;
else
V_40 |= V_330 ;
if ( V_88 & V_278 )
V_40 |= V_277 ;
else
V_40 |= V_331 ;
} else {
V_88 = F_22 ( F_184 ( V_238 -> V_69 ) ) ;
if ( V_88 & V_332 )
V_40 |= V_275 ;
else
V_40 |= V_330 ;
if ( V_88 & V_333 )
V_40 |= V_277 ;
else
V_40 |= V_331 ;
}
V_187 -> V_4 . V_236 . V_40 |= V_40 ;
if ( ! F_61 ( V_7 ) && ! F_21 ( V_7 ) &&
V_88 & V_258 )
V_187 -> V_259 = true ;
V_187 -> V_247 = true ;
F_186 ( V_238 , V_187 ) ;
if ( V_18 == V_19 ) {
if ( ( F_22 ( V_270 ) & V_271 ) == V_272 )
V_187 -> V_261 = 162000 ;
else
V_187 -> V_261 = 270000 ;
}
V_329 = F_187 ( V_187 -> V_261 ,
& V_187 -> V_262 ) ;
if ( F_61 ( V_51 -> V_7 ) && V_18 != V_19 )
F_188 ( V_187 , V_329 ) ;
V_187 -> V_4 . V_236 . V_251 = V_329 ;
if ( F_1 ( V_1 ) && V_51 -> V_253 . V_254 &&
V_187 -> V_252 > V_51 -> V_253 . V_254 ) {
F_33 ( L_57 ,
V_187 -> V_252 , V_51 -> V_253 . V_254 ) ;
V_51 -> V_253 . V_254 = V_187 -> V_252 ;
}
}
static void F_189 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_237 * V_238 = F_131 ( V_65 -> V_4 . V_238 ) ;
if ( V_238 -> V_269 -> V_249 )
F_190 ( V_65 ) ;
if ( F_191 ( V_7 ) && ! F_10 ( V_7 ) )
F_192 ( V_1 ) ;
F_153 ( V_1 ) ;
F_170 ( V_1 ) ;
F_176 ( V_1 , V_334 ) ;
F_165 ( V_1 ) ;
if ( F_117 ( V_7 ) -> V_209 < 5 )
F_193 ( V_1 ) ;
}
static void F_194 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
F_193 ( V_1 ) ;
if ( V_18 == V_19 )
F_175 ( V_1 ) ;
}
static void F_195 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_193 ( V_1 ) ;
}
static void F_196 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_237 =
F_131 ( V_65 -> V_4 . V_238 ) ;
enum V_336 V_337 = F_197 ( V_335 ) ;
enum V_69 V_69 = V_237 -> V_69 ;
T_5 V_338 ;
F_193 ( V_1 ) ;
F_26 ( & V_51 -> V_339 ) ;
V_338 = F_198 ( V_51 , V_69 , F_199 ( V_337 ) ) ;
V_338 |= V_340 ;
F_200 ( V_51 , V_69 , F_199 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_201 ( V_337 ) ) ;
V_338 |= V_340 ;
F_200 ( V_51 , V_69 , F_201 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_202 ( V_337 ) ) ;
V_338 &= ~ ( V_341 | V_342 ) ;
F_200 ( V_51 , V_69 , F_202 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_203 ( V_337 ) ) ;
V_338 &= ~ ( V_341 | V_342 ) ;
F_200 ( V_51 , V_69 , F_203 ( V_337 ) , V_338 ) ;
F_28 ( & V_51 -> V_339 ) ;
}
static void
F_204 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_343 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
if ( F_10 ( V_7 ) ) {
T_2 V_344 = F_22 ( F_205 ( V_18 ) ) ;
if ( V_343 & V_345 )
V_344 |= V_346 ;
else
V_344 &= ~ V_346 ;
V_344 &= ~ V_347 ;
switch ( V_343 & V_348 ) {
case V_349 :
V_344 |= V_350 ;
break;
case V_351 :
V_344 |= V_352 ;
break;
case V_353 :
V_344 |= V_354 ;
break;
case V_355 :
V_344 |= V_356 ;
break;
}
F_39 ( F_205 ( V_18 ) , V_344 ) ;
} else if ( F_142 ( V_7 ) && ( F_80 ( V_7 ) || V_18 != V_19 ) ) {
* V_72 &= ~ V_357 ;
switch ( V_343 & V_348 ) {
case V_349 :
* V_72 |= V_279 ;
break;
case V_351 :
* V_72 |= V_358 ;
break;
case V_353 :
* V_72 |= V_359 ;
break;
case V_355 :
F_76 ( L_58 ) ;
* V_72 |= V_359 ;
break;
}
} else {
if ( F_35 ( V_7 ) )
* V_72 &= ~ V_360 ;
else
* V_72 &= ~ V_361 ;
switch ( V_343 & V_348 ) {
case V_349 :
* V_72 |= V_281 ;
break;
case V_351 :
* V_72 |= V_78 ;
break;
case V_353 :
* V_72 |= V_362 ;
break;
case V_355 :
if ( F_35 ( V_7 ) ) {
* V_72 |= V_363 ;
} else {
F_76 ( L_58 ) ;
* V_72 |= V_362 ;
}
break;
}
}
}
static void F_206 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_204 ( V_1 , & V_1 -> V_72 ,
V_351 ) ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_1 -> V_72 |= V_74 ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
static void F_207 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_238 = F_131 ( V_65 -> V_4 . V_238 ) ;
T_2 V_364 = F_22 ( V_1 -> V_73 ) ;
if ( F_44 ( V_364 & V_74 ) )
return;
F_23 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_208 ( V_1 ) ;
F_206 ( V_1 ) ;
F_94 ( V_1 ) ;
F_161 ( V_1 ) ;
F_99 ( V_1 , true ) ;
F_27 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_209 ( V_51 , F_2 ( V_1 ) ) ;
F_176 ( V_1 , V_316 ) ;
F_210 ( V_1 ) ;
F_211 ( V_1 ) ;
F_212 ( V_1 ) ;
if ( V_238 -> V_269 -> V_249 ) {
F_213 ( L_59 ,
F_31 ( V_238 -> V_69 ) ) ;
F_214 ( V_65 ) ;
}
}
static void F_215 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_207 ( V_65 ) ;
F_167 ( V_1 ) ;
}
static void F_216 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_167 ( V_1 ) ;
F_217 ( V_1 ) ;
}
static void F_218 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
F_140 ( V_65 ) ;
if ( V_335 -> V_18 == V_19 ) {
F_138 ( V_1 ) ;
F_173 ( V_1 ) ;
}
}
static void F_219 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = V_3 -> V_4 . V_4 . V_7 -> V_52 ;
enum V_69 V_69 = V_1 -> V_70 ;
int V_365 = F_56 ( V_69 ) ;
F_155 ( V_1 ) ;
F_33 ( L_60 ,
F_31 ( V_69 ) , F_32 ( V_3 -> V_18 ) ) ;
F_39 ( V_365 , 0 ) ;
F_40 ( V_365 ) ;
V_1 -> V_70 = V_87 ;
}
static void F_47 ( struct V_6 * V_7 ,
enum V_69 V_69 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_64 * V_65 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_44 ( V_69 != V_86 && V_69 != V_79 ) )
return;
F_45 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_1 ;
enum V_18 V_18 ;
if ( V_65 -> type != V_5 )
continue;
V_1 = F_5 ( & V_65 -> V_4 ) ;
V_18 = F_2 ( V_1 ) -> V_18 ;
if ( V_1 -> V_70 != V_69 )
continue;
F_33 ( L_61 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_8 ( V_65 -> V_366 ,
L_62 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_219 ( V_1 ) ;
}
}
static void F_208 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_65 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_238 = F_131 ( V_65 -> V_4 . V_238 ) ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_70 == V_238 -> V_69 )
return;
if ( V_1 -> V_70 != V_87 )
F_219 ( V_1 ) ;
F_47 ( V_7 , V_238 -> V_69 ) ;
V_1 -> V_70 = V_238 -> V_69 ;
F_33 ( L_63 ,
F_31 ( V_1 -> V_70 ) , F_32 ( V_3 -> V_18 ) ) ;
F_48 ( V_7 , V_1 ) ;
F_49 ( V_7 , V_1 ) ;
}
static void F_220 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_237 = F_131 ( V_65 -> V_4 . V_238 ) ;
enum V_336 V_18 = F_197 ( V_335 ) ;
int V_69 = V_237 -> V_69 ;
T_5 V_338 ;
F_26 ( & V_51 -> V_339 ) ;
V_338 = F_198 ( V_51 , V_69 , F_221 ( V_18 ) ) ;
V_338 = 0 ;
if ( V_69 )
V_338 |= ( 1 << 21 ) ;
else
V_338 &= ~ ( 1 << 21 ) ;
V_338 |= 0x001000c4 ;
F_200 ( V_51 , V_69 , F_222 ( V_18 ) , V_338 ) ;
F_200 ( V_51 , V_69 , F_223 ( V_18 ) , 0x00760018 ) ;
F_200 ( V_51 , V_69 , F_224 ( V_18 ) , 0x00400888 ) ;
F_28 ( & V_51 -> V_339 ) ;
F_207 ( V_65 ) ;
}
static void F_225 ( struct V_64 * V_65 )
{
struct V_2 * V_335 = F_226 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_237 =
F_131 ( V_65 -> V_4 . V_238 ) ;
enum V_336 V_18 = F_197 ( V_335 ) ;
int V_69 = V_237 -> V_69 ;
F_140 ( V_65 ) ;
F_26 ( & V_51 -> V_339 ) ;
F_200 ( V_51 , V_69 , F_227 ( V_18 ) ,
V_341 |
V_342 ) ;
F_200 ( V_51 , V_69 , F_228 ( V_18 ) ,
V_367 |
V_368 |
( 1 << V_369 ) |
V_370 ) ;
F_200 ( V_51 , V_69 , F_229 ( V_18 ) , 0x00750f00 ) ;
F_200 ( V_51 , V_69 , F_230 ( V_18 ) , 0x00001500 ) ;
F_200 ( V_51 , V_69 , F_231 ( V_18 ) , 0x40400000 ) ;
F_28 ( & V_51 -> V_339 ) ;
}
static void F_232 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_237 =
F_131 ( V_65 -> V_4 . V_238 ) ;
enum V_336 V_337 = F_197 ( V_335 ) ;
int V_69 = V_237 -> V_69 ;
int V_371 , V_46 ;
T_5 V_338 ;
F_26 ( & V_51 -> V_339 ) ;
V_338 = F_198 ( V_51 , V_69 , F_233 ( V_337 ) ) ;
V_338 &= ~ V_372 ;
F_200 ( V_51 , V_69 , F_233 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_234 ( V_337 ) ) ;
V_338 &= ~ V_372 ;
F_200 ( V_51 , V_69 , F_234 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_199 ( V_337 ) ) ;
V_338 |= V_340 ;
F_200 ( V_51 , V_69 , F_199 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_201 ( V_337 ) ) ;
V_338 |= V_340 ;
F_200 ( V_51 , V_69 , F_201 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_202 ( V_337 ) ) ;
V_338 |= ( V_341 | V_342 ) ;
F_200 ( V_51 , V_69 , F_202 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_203 ( V_337 ) ) ;
V_338 |= ( V_341 | V_342 ) ;
F_200 ( V_51 , V_69 , F_203 ( V_337 ) , V_338 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_371 = ( V_46 == 1 ) ? 0x0 : 0x1 ;
F_200 ( V_51 , V_69 , F_235 ( V_337 , V_46 ) ,
V_371 << V_373 ) ;
}
F_28 ( & V_51 -> V_339 ) ;
F_207 ( V_65 ) ;
}
static void F_236 ( struct V_64 * V_65 )
{
struct V_2 * V_335 = F_226 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_237 * V_237 =
F_131 ( V_65 -> V_4 . V_238 ) ;
enum V_336 V_337 = F_197 ( V_335 ) ;
enum V_69 V_69 = V_237 -> V_69 ;
T_5 V_338 ;
F_140 ( V_65 ) ;
F_26 ( & V_51 -> V_339 ) ;
if ( V_69 != V_79 ) {
V_338 = F_198 ( V_51 , V_69 , V_374 ) ;
V_338 &= ~ ( V_375 | V_376 ) ;
if ( V_337 == V_377 )
V_338 |= V_378 ;
if ( V_337 == V_379 )
V_338 |= V_380 ;
F_200 ( V_51 , V_69 , V_374 , V_338 ) ;
} else {
V_338 = F_198 ( V_51 , V_69 , V_381 ) ;
V_338 &= ~ ( V_382 | V_383 ) ;
if ( V_337 == V_377 )
V_338 |= V_384 ;
if ( V_337 == V_379 )
V_338 |= V_385 ;
F_200 ( V_51 , V_69 , V_381 , V_338 ) ;
}
V_338 = F_198 ( V_51 , V_69 , F_221 ( V_337 ) ) ;
V_338 |= V_386 ;
if ( V_69 != V_79 )
V_338 &= ~ V_387 ;
else
V_338 |= V_387 ;
F_200 ( V_51 , V_69 , F_221 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_237 ( V_337 ) ) ;
V_338 |= V_386 ;
if ( V_69 != V_79 )
V_338 &= ~ V_387 ;
else
V_338 |= V_387 ;
F_200 ( V_51 , V_69 , F_237 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_238 ( V_337 ) ) ;
if ( V_69 != V_79 )
V_338 &= ~ V_388 ;
else
V_338 |= V_388 ;
F_200 ( V_51 , V_69 , F_238 ( V_337 ) , V_338 ) ;
F_28 ( & V_51 -> V_339 ) ;
}
static T_6
F_239 ( struct V_153 * V_154 , unsigned int V_389 ,
void * V_169 , T_7 V_163 )
{
T_6 V_138 ;
int V_46 ;
F_240 ( V_154 , V_315 , V_169 , 1 ) ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_138 = F_240 ( V_154 , V_389 , V_169 , V_163 ) ;
if ( V_138 == V_163 )
return V_138 ;
F_67 ( 1 ) ;
}
return V_138 ;
}
static bool
F_241 ( struct V_1 * V_1 , T_3 V_390 [ V_391 ] )
{
return F_239 ( & V_1 -> V_154 ,
V_392 ,
V_390 ,
V_391 ) == V_391 ;
}
static T_3
F_242 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_117 ( V_7 ) -> V_209 >= 9 ) {
if ( V_51 -> V_253 . V_393 && V_18 == V_19 )
return V_394 ;
return V_395 ;
} else if ( F_21 ( V_7 ) )
return V_394 ;
else if ( F_80 ( V_7 ) && V_18 == V_19 )
return V_395 ;
else if ( F_142 ( V_7 ) && V_18 != V_19 )
return V_394 ;
else
return V_395 ;
}
static T_3
F_243 ( struct V_1 * V_1 , T_3 V_396 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_117 ( V_7 ) -> V_209 >= 9 ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_399 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
return V_403 ;
default:
return V_403 ;
}
} else if ( F_104 ( V_7 ) || F_89 ( V_7 ) ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_399 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
} else if ( F_21 ( V_7 ) ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_399 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
} else if ( F_80 ( V_7 ) && V_18 == V_19 ) {
switch ( V_396 & V_397 ) {
case V_398 :
return V_401 ;
case V_400 :
case V_395 :
return V_402 ;
default:
return V_403 ;
}
} else {
switch ( V_396 & V_397 ) {
case V_398 :
return V_401 ;
case V_400 :
return V_401 ;
case V_395 :
return V_402 ;
case V_394 :
default:
return V_403 ;
}
}
}
static T_2 F_244 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
struct V_237 * V_237 =
F_131 ( V_335 -> V_4 . V_4 . V_238 ) ;
unsigned long V_404 , V_405 ,
V_406 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
enum V_336 V_18 = F_197 ( V_335 ) ;
int V_69 = V_237 -> V_69 ;
switch ( V_407 & V_408 ) {
case V_403 :
V_405 = 0x0004000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B405555 ;
V_406 = 0x552AB83A ;
break;
case V_400 :
V_404 = 0x2B404040 ;
V_406 = 0x5548B83A ;
break;
case V_395 :
V_404 = 0x2B245555 ;
V_406 = 0x5560B83A ;
break;
case V_394 :
V_404 = 0x2B405555 ;
V_406 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_402 :
V_405 = 0x0002000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B404040 ;
V_406 = 0x5552B83A ;
break;
case V_400 :
V_404 = 0x2B404848 ;
V_406 = 0x5580B83A ;
break;
case V_395 :
V_404 = 0x2B404040 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_401 :
V_405 = 0x0000000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x2B305555 ;
V_406 = 0x5570B83A ;
break;
case V_400 :
V_404 = 0x2B2B4040 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_399 :
V_405 = 0x0006000 ;
switch ( V_407 & V_397 ) {
case V_398 :
V_404 = 0x1B405555 ;
V_406 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_339 ) ;
F_200 ( V_51 , V_69 , F_245 ( V_18 ) , 0x00000000 ) ;
F_200 ( V_51 , V_69 , F_246 ( V_18 ) , V_404 ) ;
F_200 ( V_51 , V_69 , F_247 ( V_18 ) ,
V_406 ) ;
F_200 ( V_51 , V_69 , F_248 ( V_18 ) , 0x0C782040 ) ;
F_200 ( V_51 , V_69 , F_249 ( V_18 ) , 0x00030000 ) ;
F_200 ( V_51 , V_69 , F_250 ( V_18 ) , V_405 ) ;
F_200 ( V_51 , V_69 , F_245 ( V_18 ) , 0x80000000 ) ;
F_28 ( & V_51 -> V_339 ) ;
return 0 ;
}
static T_2 F_251 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_335 = F_2 ( V_1 ) ;
struct V_237 * V_237 = F_131 ( V_335 -> V_4 . V_4 . V_238 ) ;
T_5 V_409 , V_410 , V_338 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
enum V_336 V_337 = F_197 ( V_335 ) ;
enum V_69 V_69 = V_237 -> V_69 ;
int V_46 ;
switch ( V_407 & V_408 ) {
case V_403 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 128 ;
V_410 = 52 ;
break;
case V_400 :
V_409 = 128 ;
V_410 = 77 ;
break;
case V_395 :
V_409 = 128 ;
V_410 = 102 ;
break;
case V_394 :
V_409 = 128 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_402 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 85 ;
V_410 = 78 ;
break;
case V_400 :
V_409 = 85 ;
V_410 = 116 ;
break;
case V_395 :
V_409 = 85 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_401 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 64 ;
V_410 = 104 ;
break;
case V_400 :
V_409 = 64 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
case V_399 :
switch ( V_407 & V_397 ) {
case V_398 :
V_409 = 43 ;
V_410 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_339 ) ;
V_338 = F_198 ( V_51 , V_69 , F_252 ( V_337 ) ) ;
V_338 &= ~ ( V_411 | V_412 ) ;
V_338 &= ~ ( V_413 | V_414 ) ;
V_338 |= V_415 | V_416 ;
F_200 ( V_51 , V_69 , F_252 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_253 ( V_337 ) ) ;
V_338 &= ~ ( V_411 | V_412 ) ;
V_338 &= ~ ( V_413 | V_414 ) ;
V_338 |= V_415 | V_416 ;
F_200 ( V_51 , V_69 , F_253 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_254 ( V_337 ) ) ;
V_338 &= ~ ( V_417 | V_418 ) ;
V_338 |= V_419 | V_420 ;
F_200 ( V_51 , V_69 , F_254 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_255 ( V_337 ) ) ;
V_338 &= ~ ( V_417 | V_418 ) ;
V_338 |= V_419 | V_420 ;
F_200 ( V_51 , V_69 , F_255 ( V_337 ) , V_338 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_338 = F_198 ( V_51 , V_69 , F_256 ( V_337 , V_46 ) ) ;
V_338 &= ~ V_421 ;
V_338 |= V_409 << V_422 ;
F_200 ( V_51 , V_69 , F_256 ( V_337 , V_46 ) , V_338 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_338 = F_198 ( V_51 , V_69 , F_257 ( V_337 , V_46 ) ) ;
V_338 &= ~ V_423 ;
V_338 |= V_410 << V_424 ;
F_200 ( V_51 , V_69 , F_257 ( V_337 , V_46 ) , V_338 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_338 = F_198 ( V_51 , V_69 , F_258 ( V_337 , V_46 ) ) ;
V_338 &= ~ V_425 ;
F_200 ( V_51 , V_69 , F_258 ( V_337 , V_46 ) , V_338 ) ;
}
if ( ( ( V_407 & V_408 )
== V_403 ) &&
( ( V_407 & V_397 )
== V_394 ) ) {
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_338 = F_198 ( V_51 , V_69 , F_258 ( V_337 , V_46 ) ) ;
V_338 |= V_425 ;
F_200 ( V_51 , V_69 , F_258 ( V_337 , V_46 ) , V_338 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_338 = F_198 ( V_51 , V_69 , F_257 ( V_337 , V_46 ) ) ;
V_338 &= ~ ( 0xff << V_426 ) ;
V_338 |= ( 0x9a << V_426 ) ;
F_200 ( V_51 , V_69 , F_257 ( V_337 , V_46 ) , V_338 ) ;
}
}
V_338 = F_198 ( V_51 , V_69 , F_252 ( V_337 ) ) ;
V_338 |= V_411 | V_412 ;
F_200 ( V_51 , V_69 , F_252 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , F_253 ( V_337 ) ) ;
V_338 |= V_411 | V_412 ;
F_200 ( V_51 , V_69 , F_253 ( V_337 ) , V_338 ) ;
V_338 = F_198 ( V_51 , V_69 , V_427 ) ;
V_338 |= V_428 ;
F_200 ( V_51 , V_69 , V_427 , V_338 ) ;
F_28 ( & V_51 -> V_339 ) ;
return 0 ;
}
static void
F_259 ( struct V_1 * V_1 ,
const T_3 V_390 [ V_391 ] )
{
T_3 V_47 = 0 ;
T_3 V_429 = 0 ;
int V_430 ;
T_3 V_431 ;
T_3 V_432 ;
for ( V_430 = 0 ; V_430 < V_1 -> V_240 ; V_430 ++ ) {
T_3 V_433 = F_260 ( V_390 , V_430 ) ;
T_3 V_434 = F_261 ( V_390 , V_430 ) ;
if ( V_433 > V_47 )
V_47 = V_433 ;
if ( V_434 > V_429 )
V_429 = V_434 ;
}
V_431 = F_242 ( V_1 ) ;
if ( V_47 >= V_431 )
V_47 = V_431 | V_435 ;
V_432 = F_243 ( V_1 , V_47 ) ;
if ( V_429 >= V_432 )
V_429 = V_432 | V_436 ;
for ( V_430 = 0 ; V_430 < 4 ; V_430 ++ )
V_1 -> V_407 [ V_430 ] = V_47 | V_429 ;
}
static T_2
F_262 ( T_3 V_407 )
{
T_2 V_437 = 0 ;
switch ( V_407 & V_397 ) {
case V_398 :
default:
V_437 |= V_76 ;
break;
case V_400 :
V_437 |= V_438 ;
break;
case V_395 :
V_437 |= V_439 ;
break;
case V_394 :
V_437 |= V_440 ;
break;
}
switch ( V_407 & V_408 ) {
case V_403 :
default:
V_437 |= V_77 ;
break;
case V_402 :
V_437 |= V_441 ;
break;
case V_401 :
V_437 |= V_442 ;
break;
case V_399 :
V_437 |= V_443 ;
break;
}
return V_437 ;
}
static T_2
F_263 ( T_3 V_407 )
{
int V_437 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_437 ) {
case V_398 | V_403 :
case V_400 | V_403 :
return V_444 ;
case V_398 | V_402 :
return V_445 ;
case V_398 | V_401 :
case V_400 | V_401 :
return V_446 ;
case V_400 | V_402 :
case V_395 | V_402 :
return V_447 ;
case V_395 | V_403 :
case V_394 | V_403 :
return V_448 ;
default:
F_33 ( L_64
L_65 , V_437 ) ;
return V_444 ;
}
}
static T_2
F_264 ( T_3 V_407 )
{
int V_437 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_437 ) {
case V_398 | V_403 :
return V_449 ;
case V_398 | V_402 :
return V_450 ;
case V_398 | V_401 :
return V_451 ;
case V_400 | V_403 :
return V_452 ;
case V_400 | V_402 :
return V_453 ;
case V_395 | V_403 :
return V_454 ;
case V_395 | V_402 :
return V_455 ;
default:
F_33 ( L_64
L_65 , V_437 ) ;
return V_456 ;
}
}
static T_2
F_265 ( T_3 V_407 )
{
int V_437 = V_407 & ( V_397 |
V_408 ) ;
switch ( V_437 ) {
case V_398 | V_403 :
return F_266 ( 0 ) ;
case V_398 | V_402 :
return F_266 ( 1 ) ;
case V_398 | V_401 :
return F_266 ( 2 ) ;
case V_398 | V_399 :
return F_266 ( 3 ) ;
case V_400 | V_403 :
return F_266 ( 4 ) ;
case V_400 | V_402 :
return F_266 ( 5 ) ;
case V_400 | V_401 :
return F_266 ( 6 ) ;
case V_395 | V_403 :
return F_266 ( 7 ) ;
case V_395 | V_402 :
return F_266 ( 8 ) ;
case V_394 | V_403 :
return F_266 ( 9 ) ;
default:
F_33 ( L_64
L_65 , V_437 ) ;
return F_266 ( 0 ) ;
}
}
static void
F_267 ( struct V_1 * V_1 , T_2 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_437 , V_282 ;
T_3 V_407 = V_1 -> V_407 [ 0 ] ;
if ( F_104 ( V_7 ) || F_89 ( V_7 ) || F_117 ( V_7 ) -> V_209 >= 9 ) {
V_437 = F_265 ( V_407 ) ;
V_282 = V_457 ;
} else if ( F_35 ( V_7 ) ) {
V_437 = F_251 ( V_1 ) ;
V_282 = 0 ;
} else if ( F_21 ( V_7 ) ) {
V_437 = F_244 ( V_1 ) ;
V_282 = 0 ;
} else if ( F_80 ( V_7 ) && V_18 == V_19 ) {
V_437 = F_264 ( V_407 ) ;
V_282 = V_458 ;
} else if ( F_79 ( V_7 ) && V_18 == V_19 ) {
V_437 = F_263 ( V_407 ) ;
V_282 = V_459 ;
} else {
V_437 = F_262 ( V_407 ) ;
V_282 = V_460 | V_461 ;
}
F_33 ( L_66 , V_437 ) ;
* V_72 = ( * V_72 & ~ V_282 ) | V_437 ;
}
static bool
F_268 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_343 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_462 [ sizeof( V_1 -> V_407 ) + 1 ] ;
int V_138 , V_226 ;
F_204 ( V_1 , V_72 , V_343 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_462 [ 0 ] = V_343 ;
if ( ( V_343 & V_348 ) ==
V_349 ) {
V_226 = 1 ;
} else {
memcpy ( V_462 + 1 , V_1 -> V_407 , V_1 -> V_240 ) ;
V_226 = V_1 -> V_240 + 1 ;
}
V_138 = F_269 ( & V_1 -> V_154 , V_463 ,
V_462 , V_226 ) ;
return V_138 == V_226 ;
}
static bool
F_270 ( struct V_1 * V_1 , T_2 * V_72 ,
T_3 V_343 )
{
memset ( V_1 -> V_407 , 0 , sizeof( V_1 -> V_407 ) ) ;
F_267 ( V_1 , V_72 ) ;
return F_268 ( V_1 , V_72 , V_343 ) ;
}
static bool
F_271 ( struct V_1 * V_1 , T_2 * V_72 ,
const T_3 V_390 [ V_391 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
int V_138 ;
F_259 ( V_1 , V_390 ) ;
F_267 ( V_1 , V_72 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_138 = F_269 ( & V_1 -> V_154 , V_464 ,
V_1 -> V_407 , V_1 -> V_240 ) ;
return V_138 == V_1 -> V_240 ;
}
static void F_272 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
T_2 V_338 ;
if ( ! F_10 ( V_7 ) )
return;
V_338 = F_22 ( F_205 ( V_18 ) ) ;
V_338 &= ~ V_347 ;
V_338 |= V_465 ;
F_39 ( F_205 ( V_18 ) , V_338 ) ;
if ( V_18 == V_19 )
return;
if ( F_273 ( ( F_22 ( F_274 ( V_18 ) ) & V_466 ) ,
1 ) )
F_76 ( L_67 ) ;
}
void
F_210 ( struct V_1 * V_1 )
{
struct V_467 * V_65 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_65 -> V_7 ;
int V_46 ;
T_3 V_468 ;
int V_469 , V_470 ;
T_2 V_72 = V_1 -> V_72 ;
T_3 V_471 [ 2 ] ;
if ( F_10 ( V_7 ) )
F_275 ( V_65 ) ;
V_471 [ 0 ] = V_1 -> V_201 ;
V_471 [ 1 ] = V_1 -> V_240 ;
if ( F_141 ( V_1 -> V_11 ) )
V_471 [ 1 ] |= V_472 ;
F_269 ( & V_1 -> V_154 , V_473 , V_471 , 2 ) ;
if ( V_1 -> V_206 )
F_269 ( & V_1 -> V_154 , V_474 ,
& V_1 -> V_260 , 1 ) ;
V_471 [ 0 ] = 0 ;
V_471 [ 1 ] = V_475 ;
F_269 ( & V_1 -> V_154 , V_476 , V_471 , 2 ) ;
V_72 |= V_74 ;
if ( ! F_270 ( V_1 , & V_72 ,
V_351 |
V_345 ) ) {
F_76 ( L_68 ) ;
return;
}
V_468 = 0xff ;
V_469 = 0 ;
V_470 = 0 ;
for (; ; ) {
T_3 V_390 [ V_391 ] ;
F_276 ( V_1 -> V_11 ) ;
if ( ! F_241 ( V_1 , V_390 ) ) {
F_76 ( L_69 ) ;
break;
}
if ( F_277 ( V_390 , V_1 -> V_240 ) ) {
F_33 ( L_70 ) ;
break;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_240 ; V_46 ++ )
if ( ( V_1 -> V_407 [ V_46 ] & V_435 ) == 0 )
break;
if ( V_46 == V_1 -> V_240 ) {
++ V_470 ;
if ( V_470 == 5 ) {
F_76 ( L_71 ) ;
break;
}
F_270 ( V_1 , & V_72 ,
V_351 |
V_345 ) ;
V_469 = 0 ;
continue;
}
if ( ( V_1 -> V_407 [ 0 ] & V_397 ) == V_468 ) {
++ V_469 ;
if ( V_469 == 5 ) {
F_76 ( L_72 ) ;
break;
}
} else
V_469 = 0 ;
V_468 = V_1 -> V_407 [ 0 ] & V_397 ;
if ( ! F_271 ( V_1 , & V_72 , V_390 ) ) {
F_76 ( L_73 ) ;
break;
}
}
V_1 -> V_72 = V_72 ;
}
void
F_211 ( struct V_1 * V_1 )
{
bool V_477 = false ;
int V_478 , V_479 ;
T_2 V_72 = V_1 -> V_72 ;
T_2 V_480 = V_353 ;
if ( V_1 -> V_201 == V_15 || V_1 -> V_481 )
V_480 = V_355 ;
if ( ! F_268 ( V_1 , & V_72 ,
V_480 |
V_345 ) ) {
F_76 ( L_74 ) ;
return;
}
V_478 = 0 ;
V_479 = 0 ;
V_477 = false ;
for (; ; ) {
T_3 V_390 [ V_391 ] ;
if ( V_479 > 5 ) {
F_76 ( L_75 ) ;
break;
}
F_278 ( V_1 -> V_11 ) ;
if ( ! F_241 ( V_1 , V_390 ) ) {
F_76 ( L_69 ) ;
break;
}
if ( ! F_277 ( V_390 , V_1 -> V_240 ) ) {
F_210 ( V_1 ) ;
F_268 ( V_1 , & V_72 ,
V_480 |
V_345 ) ;
V_479 ++ ;
continue;
}
if ( F_279 ( V_390 , V_1 -> V_240 ) ) {
V_477 = true ;
break;
}
if ( V_478 > 5 ) {
F_210 ( V_1 ) ;
F_268 ( V_1 , & V_72 ,
V_480 |
V_345 ) ;
V_478 = 0 ;
V_479 ++ ;
continue;
}
if ( ! F_271 ( V_1 , & V_72 , V_390 ) ) {
F_76 ( L_73 ) ;
break;
}
++ V_478 ;
}
F_272 ( V_1 ) ;
V_1 -> V_72 = V_72 ;
if ( V_477 )
F_33 ( L_76 ) ;
}
void F_212 ( struct V_1 * V_1 )
{
F_268 ( V_1 , & V_1 -> V_72 ,
V_349 ) ;
}
static void
F_193 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_72 = V_1 -> V_72 ;
if ( F_44 ( F_10 ( V_7 ) ) )
return;
if ( F_44 ( ( F_22 ( V_1 -> V_73 ) & V_74 ) == 0 ) )
return;
F_33 ( L_48 ) ;
if ( F_142 ( V_7 ) && ( F_80 ( V_7 ) || V_18 != V_19 ) ) {
V_72 &= ~ V_357 ;
F_39 ( V_1 -> V_73 , V_72 | V_482 ) ;
} else {
if ( F_35 ( V_7 ) )
V_72 &= ~ V_360 ;
else
V_72 &= ~ V_361 ;
F_39 ( V_1 -> V_73 , V_72 | V_483 ) ;
}
F_40 ( V_1 -> V_73 ) ;
if ( F_280 ( V_7 ) &&
F_22 ( V_1 -> V_73 ) & V_80 ) {
V_72 &= ~ V_80 ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
V_72 &= ~ V_274 ;
F_39 ( V_1 -> V_73 , V_72 & ~ V_74 ) ;
F_40 ( V_1 -> V_73 ) ;
F_67 ( V_1 -> V_484 ) ;
}
static bool
F_281 ( struct V_1 * V_1 )
{
struct V_2 * V_267 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_267 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_485 ;
if ( F_239 ( & V_1 -> V_154 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_33 ( L_77 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_315 ] == 0 )
return false ;
memset ( V_1 -> V_486 , 0 , sizeof( V_1 -> V_486 ) ) ;
if ( F_1 ( V_1 ) ) {
F_239 ( & V_1 -> V_154 , V_487 ,
V_1 -> V_486 ,
sizeof( V_1 -> V_486 ) ) ;
if ( V_1 -> V_486 [ 0 ] & V_488 ) {
V_51 -> V_489 . V_490 = true ;
F_33 ( L_78 ) ;
}
}
if ( V_1 -> V_11 [ V_315 ] >= 0x12 &&
V_1 -> V_11 [ V_491 ] & V_492 &&
( F_104 ( V_51 ) || F_117 ( V_51 ) -> V_209 >= 8 ) ) {
V_1 -> V_481 = true ;
F_33 ( L_79 ) ;
} else
V_1 -> V_481 = false ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_11 [ V_493 ] & V_494 ) &&
( F_239 ( & V_1 -> V_154 , V_495 , & V_485 , 1 ) == 1 ) &&
( V_485 >= 0x03 ) ) {
T_8 V_205 [ V_224 ] ;
int V_46 ;
F_239 ( & V_1 -> V_154 ,
V_496 ,
V_205 ,
sizeof( V_205 ) ) ;
for ( V_46 = 0 ; V_46 < F_118 ( V_205 ) ; V_46 ++ ) {
int V_338 = F_282 ( V_205 [ V_46 ] ) ;
if ( V_338 == 0 )
break;
V_1 -> V_205 [ V_46 ] = ( V_338 * 200 ) / 10 ;
}
V_1 -> V_206 = V_46 ;
}
F_127 ( V_1 ) ;
if ( ! ( V_1 -> V_11 [ V_497 ] &
V_498 ) )
return true ;
if ( V_1 -> V_11 [ V_315 ] == 0x10 )
return true ;
if ( F_239 ( & V_1 -> V_154 , V_499 ,
V_1 -> V_500 ,
V_501 ) < 0 )
return false ;
return true ;
}
static void
F_283 ( struct V_1 * V_1 )
{
T_1 V_462 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_502 ] & V_503 ) )
return;
if ( F_239 ( & V_1 -> V_154 , V_504 , V_462 , 3 ) == 3 )
F_33 ( L_80 ,
V_462 [ 0 ] , V_462 [ 1 ] , V_462 [ 2 ] ) ;
if ( F_239 ( & V_1 -> V_154 , V_505 , V_462 , 3 ) == 3 )
F_33 ( L_81 ,
V_462 [ 0 ] , V_462 [ 1 ] , V_462 [ 2 ] ) ;
}
static bool
F_284 ( struct V_1 * V_1 )
{
T_1 V_462 [ 1 ] ;
if ( ! V_1 -> V_506 )
return false ;
if ( V_1 -> V_11 [ V_315 ] < 0x12 )
return false ;
if ( F_239 ( & V_1 -> V_154 , V_507 , V_462 , 1 ) ) {
if ( V_462 [ 0 ] & V_508 ) {
F_33 ( L_82 ) ;
V_1 -> V_509 = true ;
} else {
F_33 ( L_83 ) ;
V_1 -> V_509 = false ;
}
}
F_285 ( & V_1 -> V_510 , V_1 -> V_509 ) ;
return V_1 -> V_509 ;
}
int F_286 ( struct V_1 * V_1 , T_1 * V_511 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_237 * V_237 =
F_131 ( V_3 -> V_4 . V_4 . V_238 ) ;
T_1 V_462 ;
int V_512 ;
int V_513 = 6 ;
if ( F_287 ( & V_1 -> V_154 , V_514 , & V_462 ) < 0 )
return - V_149 ;
if ( ! ( V_462 & V_515 ) )
return - V_516 ;
if ( F_287 ( & V_1 -> V_154 , V_517 , & V_462 ) < 0 )
return - V_149 ;
if ( F_177 ( & V_1 -> V_154 , V_517 ,
V_462 | V_518 ) < 0 )
return - V_149 ;
if ( F_287 ( & V_1 -> V_154 , V_514 , & V_462 ) < 0 )
return - V_149 ;
V_512 = V_462 & V_519 ;
do {
if ( F_287 ( & V_1 -> V_154 ,
V_514 , & V_462 ) < 0 )
return - V_149 ;
F_288 ( V_7 , V_237 -> V_69 ) ;
} while ( -- V_513 && ( V_462 & V_519 ) == V_512 );
if ( V_513 == 0 ) {
F_33 ( L_84 ) ;
return - V_150 ;
}
if ( F_240 ( & V_1 -> V_154 , V_520 , V_511 , 6 ) < 0 )
return - V_149 ;
if ( F_287 ( & V_1 -> V_154 , V_517 , & V_462 ) < 0 )
return - V_149 ;
if ( F_177 ( & V_1 -> V_154 , V_517 ,
V_462 & ~ V_518 ) < 0 )
return - V_149 ;
return 0 ;
}
static bool
F_289 ( struct V_1 * V_1 , T_1 * V_521 )
{
return F_239 ( & V_1 -> V_154 ,
V_522 ,
V_521 , 1 ) == 1 ;
}
static bool
F_290 ( struct V_1 * V_1 , T_1 * V_521 )
{
int V_138 ;
V_138 = F_239 ( & V_1 -> V_154 ,
V_523 ,
V_521 , 14 ) ;
if ( V_138 != 14 )
return false ;
return true ;
}
static void
F_291 ( struct V_1 * V_1 )
{
F_177 ( & V_1 -> V_154 , V_524 , V_525 ) ;
}
static int
F_292 ( struct V_1 * V_1 )
{
bool V_526 ;
if ( V_1 -> V_509 ) {
T_1 V_527 [ 16 ] = { 0 } ;
int V_138 = 0 ;
int V_528 ;
bool V_529 ;
V_526 = F_290 ( V_1 , V_527 ) ;
V_530:
if ( V_526 == true ) {
if ( V_1 -> V_531 && ! F_279 ( & V_527 [ 10 ] , V_1 -> V_240 ) ) {
F_33 ( L_85 ) ;
F_210 ( V_1 ) ;
F_211 ( V_1 ) ;
F_212 ( V_1 ) ;
}
F_33 ( L_86 , V_527 ) ;
V_138 = F_293 ( & V_1 -> V_510 , V_527 , & V_529 ) ;
if ( V_529 ) {
for ( V_528 = 0 ; V_528 < 3 ; V_528 ++ ) {
int V_532 ;
V_532 = F_269 ( & V_1 -> V_154 ,
V_523 + 1 ,
& V_527 [ 1 ] , 3 ) ;
if ( V_532 == 3 ) {
break;
}
}
V_526 = F_290 ( V_1 , V_527 ) ;
if ( V_526 == true ) {
F_33 ( L_87 , V_527 ) ;
goto V_530;
}
} else
V_138 = 0 ;
return V_138 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_33 ( L_88 ) ;
V_1 -> V_509 = false ;
F_285 ( & V_1 -> V_510 , V_1 -> V_509 ) ;
F_294 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_173 ;
}
static void
F_295 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_521 ;
T_1 V_390 [ V_391 ] ;
F_44 ( ! F_296 ( & V_7 -> V_533 . V_534 ) ) ;
if ( ! V_64 -> V_366 )
return;
if ( F_44 ( ! V_64 -> V_4 . V_238 ) )
return;
if ( ! F_131 ( V_64 -> V_4 . V_238 ) -> V_535 )
return;
if ( ! F_241 ( V_1 , V_390 ) ) {
return;
}
if ( ! F_281 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_315 ] >= 0x11 &&
F_289 ( V_1 , & V_521 ) ) {
F_177 ( & V_1 -> V_154 ,
V_522 ,
V_521 ) ;
if ( V_521 & V_536 )
F_291 ( V_1 ) ;
if ( V_521 & ( V_537 | V_538 ) )
F_213 ( L_89 ) ;
}
if ( ! F_279 ( V_390 , V_1 -> V_240 ) ) {
F_33 ( L_90 ,
V_64 -> V_4 . V_174 ) ;
F_210 ( V_1 ) ;
F_211 ( V_1 ) ;
F_212 ( V_1 ) ;
}
}
static enum V_539
F_297 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_281 ( V_1 ) )
return V_540 ;
if ( ! ( V_11 [ V_497 ] & V_498 ) )
return V_541 ;
if ( V_1 -> V_11 [ V_315 ] >= 0x11 &&
V_1 -> V_500 [ 0 ] & V_542 ) {
T_3 V_543 ;
if ( F_239 ( & V_1 -> V_154 , V_544 ,
& V_543 , 1 ) < 0 )
return V_545 ;
return F_298 ( V_543 ) ? V_541
: V_540 ;
}
if ( F_299 ( & V_1 -> V_154 . V_184 ) )
return V_541 ;
if ( V_1 -> V_11 [ V_315 ] >= 0x11 ) {
type = V_1 -> V_500 [ 0 ] & V_546 ;
if ( type == V_547 ||
type == V_548 )
return V_545 ;
} else {
type = V_1 -> V_11 [ V_497 ] &
V_549 ;
if ( type == V_550 ||
type == V_551 )
return V_545 ;
}
F_33 ( L_91 ) ;
return V_540 ;
}
static enum V_539
F_300 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_539 V_112 ;
V_112 = F_301 ( V_7 ) ;
if ( V_112 == V_545 )
V_112 = V_541 ;
return V_112 ;
}
static enum V_539
F_302 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_303 ( V_51 , V_3 ) )
return V_540 ;
return F_297 ( V_1 ) ;
}
static int F_304 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_552 ;
if ( F_21 ( V_7 ) ) {
switch ( V_3 -> V_18 ) {
case V_175 :
V_552 = V_553 ;
break;
case V_177 :
V_552 = V_554 ;
break;
case V_179 :
V_552 = V_555 ;
break;
default:
return - V_173 ;
}
} else {
switch ( V_3 -> V_18 ) {
case V_175 :
V_552 = V_556 ;
break;
case V_177 :
V_552 = V_557 ;
break;
case V_179 :
V_552 = V_558 ;
break;
default:
return - V_173 ;
}
}
if ( ( F_22 ( V_559 ) & V_552 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_539
F_305 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_138 ;
if ( F_1 ( V_1 ) ) {
enum V_539 V_112 ;
V_112 = F_301 ( V_7 ) ;
if ( V_112 == V_545 )
V_112 = V_541 ;
return V_112 ;
}
V_138 = F_304 ( V_7 , V_3 ) ;
if ( V_138 == - V_173 )
return V_545 ;
else if ( V_138 == 0 )
return V_540 ;
return F_297 ( V_1 ) ;
}
static struct V_560 *
F_306 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_239 ;
if ( V_29 -> V_560 ) {
if ( F_307 ( V_29 -> V_560 ) )
return NULL ;
return F_308 ( V_29 -> V_560 ) ;
} else
return F_309 ( & V_29 -> V_4 ,
& V_1 -> V_154 . V_184 ) ;
}
static void
F_310 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_239 ;
struct V_560 * V_560 ;
V_560 = F_306 ( V_1 ) ;
V_29 -> V_561 = V_560 ;
if ( V_1 -> V_562 != V_563 )
V_1 -> V_249 = V_1 -> V_562 == V_564 ;
else
V_1 -> V_249 = F_311 ( V_560 ) ;
}
static void
F_312 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_239 ;
F_313 ( V_29 -> V_561 ) ;
V_29 -> V_561 = NULL ;
V_1 -> V_249 = false ;
}
static enum V_66
F_314 ( struct V_1 * V_565 )
{
struct V_64 * V_65 = & F_2 ( V_565 ) -> V_4 ;
enum V_66 V_67 ;
V_67 = F_24 ( V_65 ) ;
F_25 ( F_315 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
return V_67 ;
}
static void
F_316 ( struct V_1 * V_565 ,
enum V_66 V_67 )
{
struct V_64 * V_65 = & F_2 ( V_565 ) -> V_4 ;
F_29 ( F_315 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
}
static enum V_539
F_317 ( struct V_8 * V_9 , bool V_566 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_539 V_112 ;
enum V_66 V_67 ;
bool V_138 ;
F_33 ( L_92 ,
V_9 -> V_4 . V_567 , V_9 -> V_174 ) ;
F_312 ( V_1 ) ;
if ( V_1 -> V_509 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_568 ;
return V_540 ;
}
V_67 = F_314 ( V_1 ) ;
if ( F_1 ( V_1 ) )
V_112 = F_300 ( V_1 ) ;
else if ( F_61 ( V_7 ) )
V_112 = F_302 ( V_1 ) ;
else
V_112 = F_305 ( V_1 ) ;
if ( V_112 != V_541 )
goto V_144;
F_283 ( V_1 ) ;
V_138 = F_284 ( V_1 ) ;
if ( V_138 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_568 ;
V_112 = V_540 ;
goto V_144;
}
F_310 ( V_1 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_568 ;
V_112 = V_541 ;
V_144:
F_316 ( V_1 , V_67 ) ;
return V_112 ;
}
static void
F_318 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
enum V_66 V_67 ;
F_33 ( L_92 ,
V_9 -> V_4 . V_567 , V_9 -> V_174 ) ;
F_312 ( V_1 ) ;
if ( V_9 -> V_112 != V_541 )
return;
V_67 = F_314 ( V_1 ) ;
F_310 ( V_1 ) ;
F_316 ( V_1 , V_67 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_568 ;
}
static int F_319 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_560 * V_560 ;
V_560 = V_29 -> V_561 ;
if ( V_560 ) {
int V_138 = F_320 ( V_9 , V_560 ) ;
if ( V_138 )
return V_138 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_29 -> V_31 . V_30 ) {
struct V_27 * V_28 ;
V_28 = F_321 ( V_9 -> V_7 ,
V_29 -> V_31 . V_30 ) ;
if ( V_28 ) {
F_322 ( V_9 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_323 ( struct V_8 * V_9 )
{
bool V_249 = false ;
struct V_560 * V_560 ;
V_560 = F_16 ( V_9 ) -> V_561 ;
if ( V_560 )
V_249 = F_311 ( V_560 ) ;
return V_249 ;
}
static int
F_324 ( struct V_8 * V_9 ,
struct V_569 * V_570 ,
T_9 V_338 )
{
struct V_50 * V_51 = V_9 -> V_7 -> V_52 ;
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_64 * V_64 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
int V_138 ;
V_138 = F_325 ( & V_9 -> V_4 , V_570 , V_338 ) ;
if ( V_138 )
return V_138 ;
if ( V_570 == V_51 -> V_571 ) {
int V_46 = V_338 ;
bool V_249 ;
if ( V_46 == V_1 -> V_562 )
return 0 ;
V_1 -> V_562 = V_46 ;
if ( V_46 == V_563 )
V_249 = F_323 ( V_9 ) ;
else
V_249 = ( V_46 == V_564 ) ;
if ( V_249 == V_1 -> V_249 )
return 0 ;
V_1 -> V_249 = V_249 ;
goto V_113;
}
if ( V_570 == V_51 -> V_572 ) {
bool V_573 = V_1 -> V_256 ;
T_2 V_574 = V_1 -> V_257 ;
switch ( V_338 ) {
case V_575 :
V_1 -> V_256 = true ;
break;
case V_576 :
V_1 -> V_256 = false ;
V_1 -> V_257 = 0 ;
break;
case V_577 :
V_1 -> V_256 = false ;
V_1 -> V_257 = V_258 ;
break;
default:
return - V_173 ;
}
if ( V_573 == V_1 -> V_256 &&
V_574 == V_1 -> V_257 )
return 0 ;
goto V_113;
}
if ( F_1 ( V_1 ) &&
V_570 == V_9 -> V_7 -> V_533 . V_578 ) {
if ( V_338 == V_579 ) {
F_33 ( L_93 ) ;
return - V_173 ;
}
if ( V_29 -> V_31 . V_250 == V_338 ) {
return 0 ;
}
V_29 -> V_31 . V_250 = V_338 ;
goto V_113;
}
return - V_173 ;
V_113:
if ( V_64 -> V_4 . V_238 )
F_326 ( V_64 -> V_4 . V_238 ) ;
return 0 ;
}
static void
F_327 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
F_313 ( V_29 -> V_561 ) ;
if ( ! F_328 ( V_29 -> V_560 ) )
F_313 ( V_29 -> V_560 ) ;
if ( V_9 -> V_580 == V_581 )
F_329 ( & V_29 -> V_31 ) ;
F_330 ( V_9 ) ;
F_313 ( V_9 ) ;
}
void F_331 ( struct V_467 * V_65 )
{
struct V_2 * V_3 = F_226 ( V_65 ) ;
struct V_1 * V_1 = & V_3 -> V_565 ;
F_107 ( & V_1 -> V_154 ) ;
F_332 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_333 ( & V_1 -> V_301 ) ;
F_23 ( V_1 ) ;
F_155 ( V_1 ) ;
F_27 ( V_1 ) ;
if ( V_1 -> V_100 . V_582 ) {
F_334 ( & V_1 -> V_100 ) ;
V_1 -> V_100 . V_582 = NULL ;
}
}
F_335 ( V_65 ) ;
F_313 ( V_3 ) ;
}
static void F_336 ( struct V_64 * V_64 )
{
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_333 ( & V_1 -> V_301 ) ;
F_23 ( V_1 ) ;
F_155 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_337 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_69 ( V_1 ) )
return;
F_33 ( L_94 ) ;
V_67 = F_24 ( & V_3 -> V_4 ) ;
F_25 ( V_51 , V_67 ) ;
F_158 ( V_1 ) ;
}
static void F_338 ( struct V_467 * V_65 )
{
struct V_1 * V_1 ;
if ( F_339 ( V_65 ) -> type != V_5 )
return;
V_1 = F_5 ( V_65 ) ;
F_23 ( V_1 ) ;
if ( F_21 ( V_65 -> V_7 ) )
F_58 ( V_1 ) ;
F_337 ( V_1 ) ;
F_27 ( V_1 ) ;
}
void
F_340 ( struct V_64 * V_64 )
{
return;
}
enum V_583
F_341 ( struct V_2 * V_3 , bool V_584 )
{
struct V_1 * V_1 = & V_3 -> V_565 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
enum V_583 V_138 = V_585 ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_568 ;
if ( V_584 && V_3 -> V_4 . type == V_5 ) {
F_33 ( L_95 ,
F_32 ( V_3 -> V_18 ) ) ;
return V_586 ;
}
F_33 ( L_96 ,
F_32 ( V_3 -> V_18 ) ,
V_584 ? L_97 : L_98 ) ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
if ( V_584 ) {
if ( F_61 ( V_7 ) ) {
if ( ! F_303 ( V_51 , V_3 ) )
goto V_587;
} else {
if ( F_304 ( V_7 , V_3 ) != 1 )
goto V_587;
}
if ( ! F_281 ( V_1 ) ) {
goto V_587;
}
F_283 ( V_1 ) ;
if ( ! F_284 ( V_1 ) )
goto V_587;
} else {
if ( V_1 -> V_509 ) {
if ( F_292 ( V_1 ) == - V_173 )
goto V_587;
}
if ( ! V_1 -> V_509 ) {
F_342 ( & V_7 -> V_533 . V_534 , NULL ) ;
F_295 ( V_1 ) ;
F_343 ( & V_7 -> V_533 . V_534 ) ;
}
}
V_138 = V_586 ;
goto V_588;
V_587:
if ( V_1 -> V_509 ) {
F_33 ( L_99 , V_1 -> V_509 , V_1 -> V_510 . V_589 ) ;
V_1 -> V_509 = false ;
F_285 ( & V_1 -> V_510 , V_1 -> V_509 ) ;
}
V_588:
F_29 ( V_51 , V_67 ) ;
return V_138 ;
}
int
F_344 ( struct V_313 * V_238 )
{
struct V_6 * V_7 = V_238 -> V_7 ;
struct V_64 * V_64 ;
struct V_1 * V_1 ;
F_345 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( V_64 -> type == V_568 ||
V_64 -> type == V_5 )
return V_1 -> V_73 ;
}
return - 1 ;
}
bool F_346 ( struct V_6 * V_7 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
union V_590 * V_591 ;
int V_46 ;
static const short V_592 [] = {
[ V_175 ] = V_593 ,
[ V_177 ] = V_594 ,
[ V_179 ] = V_595 ,
} ;
if ( V_18 == V_19 )
return true ;
if ( ! V_51 -> V_253 . V_596 )
return false ;
for ( V_46 = 0 ; V_46 < V_51 -> V_253 . V_596 ; V_46 ++ ) {
V_591 = V_51 -> V_253 . V_597 + V_46 ;
if ( V_591 -> V_598 . V_599 == V_592 [ V_18 ] &&
( V_591 -> V_598 . V_600 & V_601 ) ==
( V_602 & V_601 ) )
return true ;
}
return false ;
}
void
F_347 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
F_348 ( V_9 ) ;
F_349 ( V_9 ) ;
V_1 -> V_256 = true ;
if ( F_1 ( V_1 ) ) {
F_350 ( V_9 -> V_7 ) ;
F_351 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_533 . V_578 ,
V_603 ) ;
V_29 -> V_31 . V_250 = V_603 ;
}
}
static void F_352 ( struct V_1 * V_1 )
{
V_1 -> V_289 = V_304 ;
V_1 -> V_292 = V_304 ;
V_1 -> V_294 = V_304 ;
}
static void
F_48 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_604 V_605 , V_253 , V_606 ,
* V_607 = & V_1 -> V_608 ;
T_5 V_609 , V_610 , V_101 , V_298 ;
int V_102 , V_365 , V_611 , V_103 ;
F_43 ( & V_51 -> V_68 ) ;
if ( V_607 -> V_612 != 0 )
return;
if ( F_61 ( V_7 ) ) {
V_102 = V_94 ;
V_365 = V_613 ;
V_611 = V_614 ;
V_103 = V_615 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_102 = F_53 ( V_69 ) ;
V_365 = F_56 ( V_69 ) ;
V_611 = F_353 ( V_69 ) ;
V_103 = F_66 ( V_69 ) ;
}
V_298 = F_151 ( V_1 ) ;
F_39 ( V_102 , V_298 ) ;
V_609 = F_22 ( V_365 ) ;
V_610 = F_22 ( V_611 ) ;
V_101 = F_22 ( V_103 ) ;
V_605 . V_616 = ( V_609 & V_617 ) >>
V_618 ;
V_605 . V_619 = ( V_609 & V_620 ) >>
V_621 ;
V_605 . V_622 = ( V_610 & V_623 ) >>
V_624 ;
V_605 . V_625 = ( V_610 & V_626 ) >>
V_627 ;
V_605 . V_612 = ( ( V_101 & V_628 ) >>
V_629 ) * 1000 ;
F_33 ( L_100 ,
V_605 . V_616 , V_605 . V_619 , V_605 . V_622 , V_605 . V_625 , V_605 . V_612 ) ;
V_253 = V_51 -> V_253 . V_630 ;
V_606 . V_616 = 210 * 10 ;
V_606 . V_619 = 50 * 10 ;
V_606 . V_622 = 50 * 10 ;
V_606 . V_625 = 500 * 10 ;
V_606 . V_612 = ( 510 + 100 ) * 10 ;
F_33 ( L_101 ,
V_253 . V_616 , V_253 . V_619 , V_253 . V_622 , V_253 . V_625 , V_253 . V_612 ) ;
#define F_354 ( T_10 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_354 ( V_616 ) ;
F_354 ( V_619 ) ;
F_354 ( V_622 ) ;
F_354 ( V_625 ) ;
F_354 ( V_612 ) ;
#undef F_354
#define F_355 ( T_10 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_302 = F_355 ( V_616 ) ;
V_1 -> V_293 = F_355 ( V_619 ) ;
V_1 -> V_295 = F_355 ( V_622 ) ;
V_1 -> V_484 = F_355 ( V_625 ) ;
V_1 -> V_108 = F_355 ( V_612 ) ;
#undef F_355
F_33 ( L_102 ,
V_1 -> V_302 , V_1 -> V_484 ,
V_1 -> V_108 ) ;
F_33 ( L_103 ,
V_1 -> V_293 , V_1 -> V_295 ) ;
}
static void
F_49 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_609 , V_610 , V_101 , V_92 = 0 ;
int div = F_61 ( V_7 ) ? F_82 ( V_7 ) : F_20 ( V_7 ) ;
int V_365 , V_611 , V_103 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
const struct V_604 * V_631 = & V_1 -> V_608 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_61 ( V_7 ) ) {
V_365 = V_613 ;
V_611 = V_614 ;
V_103 = V_615 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_365 = F_56 ( V_69 ) ;
V_611 = F_353 ( V_69 ) ;
V_103 = F_66 ( V_69 ) ;
}
V_609 = ( V_631 -> V_616 << V_618 ) |
( 1 << V_621 ) ;
V_610 = ( 1 << V_624 ) |
( V_631 -> V_625 << V_627 ) ;
V_101 = ( ( 100 * div ) / 2 - 1 ) << V_632 ;
V_101 |= ( F_81 ( V_631 -> V_612 , 1000 )
<< V_629 ) ;
if ( F_21 ( V_7 ) ) {
V_92 = F_57 ( V_18 ) ;
} else if ( F_280 ( V_7 ) || F_142 ( V_7 ) ) {
if ( V_18 == V_19 )
V_92 = V_633 ;
else
V_92 = V_634 ;
}
V_609 |= V_92 ;
F_39 ( V_365 , V_609 ) ;
F_39 ( V_611 , V_610 ) ;
F_39 ( V_103 , V_101 ) ;
F_33 ( L_104 ,
F_22 ( V_365 ) ,
F_22 ( V_611 ) ,
F_22 ( V_103 ) ) ;
}
static void F_356 ( struct V_6 * V_7 , int V_635 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_64 * V_65 ;
struct V_2 * V_267 = NULL ;
struct V_1 * V_1 = V_51 -> V_264 . V_565 ;
struct V_186 * V_269 = NULL ;
struct V_237 * V_237 = NULL ;
T_5 V_543 , V_338 ;
enum V_636 V_115 = V_637 ;
if ( V_635 <= 0 ) {
F_33 ( L_105 ) ;
return;
}
if ( V_1 == NULL ) {
F_33 ( L_106 ) ;
return;
}
V_267 = F_2 ( V_1 ) ;
V_65 = & V_267 -> V_4 ;
V_237 = F_131 ( V_65 -> V_4 . V_238 ) ;
if ( ! V_237 ) {
F_33 ( L_107 ) ;
return;
}
V_269 = V_237 -> V_269 ;
if ( V_51 -> V_264 . type < V_265 ) {
F_33 ( L_108 ) ;
return;
}
if ( V_1 -> V_239 -> V_31 . V_263 -> V_638 ==
V_635 )
V_115 = V_639 ;
if ( V_115 == V_51 -> V_264 . V_640 ) {
F_33 (
L_109 ) ;
return;
}
if ( ! V_237 -> V_535 ) {
F_33 ( L_110 ) ;
return;
}
if ( F_117 ( V_7 ) -> V_209 >= 8 && ! F_35 ( V_7 ) ) {
switch ( V_115 ) {
case V_637 :
F_357 ( V_237 , V_641 ) ;
break;
case V_639 :
F_357 ( V_237 , V_642 ) ;
break;
case V_643 :
default:
F_76 ( L_111 ) ;
}
} else if ( F_117 ( V_7 ) -> V_209 > 6 ) {
V_543 = F_358 ( V_237 -> V_269 -> V_644 ) ;
V_338 = F_22 ( V_543 ) ;
if ( V_115 > V_637 ) {
if ( F_21 ( V_7 ) )
V_338 |= V_645 ;
else
V_338 |= V_646 ;
} else {
if ( F_21 ( V_7 ) )
V_338 &= ~ V_645 ;
else
V_338 &= ~ V_646 ;
}
F_39 ( V_543 , V_338 ) ;
}
V_51 -> V_264 . V_640 = V_115 ;
F_33 ( L_112 , V_635 ) ;
}
void F_359 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_267 = F_2 ( V_1 ) ;
struct V_313 * V_238 = V_267 -> V_4 . V_4 . V_238 ;
struct V_237 * V_237 = F_131 ( V_238 ) ;
if ( ! V_237 -> V_269 -> V_248 ) {
F_33 ( L_113 ) ;
return;
}
F_26 ( & V_51 -> V_264 . V_647 ) ;
if ( F_44 ( V_51 -> V_264 . V_565 ) ) {
F_76 ( L_114 ) ;
goto V_648;
}
V_51 -> V_264 . V_649 = 0 ;
V_51 -> V_264 . V_565 = V_1 ;
V_648:
F_28 ( & V_51 -> V_264 . V_647 ) ;
}
void F_360 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_267 = F_2 ( V_1 ) ;
struct V_313 * V_238 = V_267 -> V_4 . V_4 . V_238 ;
struct V_237 * V_237 = F_131 ( V_238 ) ;
if ( ! V_237 -> V_269 -> V_248 )
return;
F_26 ( & V_51 -> V_264 . V_647 ) ;
if ( ! V_51 -> V_264 . V_565 ) {
F_28 ( & V_51 -> V_264 . V_647 ) ;
return;
}
if ( V_51 -> V_264 . V_640 == V_639 )
F_356 ( V_51 -> V_7 ,
V_1 -> V_239 -> V_31 .
V_30 -> V_638 ) ;
V_51 -> V_264 . V_565 = NULL ;
F_28 ( & V_51 -> V_264 . V_647 ) ;
F_333 ( & V_51 -> V_264 . V_650 ) ;
}
static void F_361 ( struct V_305 * V_650 )
{
struct V_50 * V_51 =
F_64 ( V_650 , F_65 ( * V_51 ) , V_264 . V_650 . V_650 ) ;
struct V_1 * V_1 ;
F_26 ( & V_51 -> V_264 . V_647 ) ;
V_1 = V_51 -> V_264 . V_565 ;
if ( ! V_1 )
goto V_648;
if ( V_51 -> V_264 . V_649 )
goto V_648;
if ( V_51 -> V_264 . V_640 != V_639 )
F_356 ( V_51 -> V_7 ,
V_1 -> V_239 -> V_31 .
V_263 -> V_638 ) ;
V_648:
F_28 ( & V_51 -> V_264 . V_647 ) ;
}
void F_362 ( struct V_6 * V_7 ,
unsigned V_651 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_313 * V_238 ;
enum V_69 V_69 ;
if ( V_51 -> V_264 . type == V_652 )
return;
F_152 ( & V_51 -> V_264 . V_650 ) ;
F_26 ( & V_51 -> V_264 . V_647 ) ;
if ( ! V_51 -> V_264 . V_565 ) {
F_28 ( & V_51 -> V_264 . V_647 ) ;
return;
}
V_238 = F_2 ( V_51 -> V_264 . V_565 ) -> V_4 . V_4 . V_238 ;
V_69 = F_131 ( V_238 ) -> V_69 ;
if ( V_51 -> V_264 . V_640 == V_639 ) {
F_356 ( V_51 -> V_7 ,
V_51 -> V_264 . V_565 -> V_239 -> V_31 .
V_30 -> V_638 ) ;
}
V_651 &= F_363 ( V_69 ) ;
V_51 -> V_264 . V_649 |= V_651 ;
F_28 ( & V_51 -> V_264 . V_647 ) ;
}
void F_364 ( struct V_6 * V_7 ,
unsigned V_651 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_313 * V_238 ;
enum V_69 V_69 ;
if ( V_51 -> V_264 . type == V_652 )
return;
F_152 ( & V_51 -> V_264 . V_650 ) ;
F_26 ( & V_51 -> V_264 . V_647 ) ;
if ( ! V_51 -> V_264 . V_565 ) {
F_28 ( & V_51 -> V_264 . V_647 ) ;
return;
}
V_238 = F_2 ( V_51 -> V_264 . V_565 ) -> V_4 . V_4 . V_238 ;
V_69 = F_131 ( V_238 ) -> V_69 ;
V_51 -> V_264 . V_649 &= ~ V_651 ;
if ( V_51 -> V_264 . V_640 != V_639 &&
! V_51 -> V_264 . V_649 )
F_160 ( & V_51 -> V_264 . V_650 ,
F_159 ( 1000 ) ) ;
F_28 ( & V_51 -> V_264 . V_647 ) ;
}
static struct V_27 *
F_365 ( struct V_29 * V_29 ,
struct V_27 * V_30 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_263 = NULL ;
F_366 ( & V_51 -> V_264 . V_650 , F_361 ) ;
F_367 ( & V_51 -> V_264 . V_647 ) ;
if ( F_117 ( V_7 ) -> V_209 <= 6 ) {
F_33 ( L_115 ) ;
return NULL ;
}
if ( V_51 -> V_253 . V_653 != V_265 ) {
F_33 ( L_116 ) ;
return NULL ;
}
V_263 = F_368
( V_7 , V_30 , V_9 ) ;
if ( ! V_263 ) {
F_33 ( L_117 ) ;
return NULL ;
}
V_51 -> V_264 . type = V_51 -> V_253 . V_653 ;
V_51 -> V_264 . V_640 = V_637 ;
F_33 ( L_118 ) ;
return V_263 ;
}
static bool F_369 ( struct V_1 * V_1 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_30 = NULL ;
struct V_27 * V_263 = NULL ;
bool V_654 ;
struct V_27 * V_655 ;
struct V_560 * V_560 ;
enum V_69 V_69 = V_87 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_23 ( V_1 ) ;
F_337 ( V_1 ) ;
F_27 ( V_1 ) ;
V_654 = F_281 ( V_1 ) ;
if ( V_654 ) {
if ( V_1 -> V_11 [ V_315 ] >= 0x11 )
V_51 -> V_656 =
V_1 -> V_11 [ V_657 ] &
V_658 ;
} else {
F_370 ( L_119 ) ;
return false ;
}
F_23 ( V_1 ) ;
F_49 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
F_26 ( & V_7 -> V_533 . V_647 ) ;
V_560 = F_309 ( V_9 , & V_1 -> V_154 . V_184 ) ;
if ( V_560 ) {
if ( F_371 ( V_9 , V_560 ) ) {
F_372 ( V_9 ,
V_560 ) ;
F_373 ( V_9 , V_560 ) ;
} else {
F_313 ( V_560 ) ;
V_560 = F_374 ( - V_173 ) ;
}
} else {
V_560 = F_374 ( - V_659 ) ;
}
V_29 -> V_560 = V_560 ;
F_45 (scan, &connector->probed_modes, head) {
if ( ( V_655 -> type & V_660 ) ) {
V_30 = F_321 ( V_7 , V_655 ) ;
V_263 = F_365 (
V_29 , V_30 ) ;
break;
}
}
if ( ! V_30 && V_51 -> V_253 . V_661 ) {
V_30 = F_321 ( V_7 ,
V_51 -> V_253 . V_661 ) ;
if ( V_30 )
V_30 -> type |= V_660 ;
}
F_28 ( & V_7 -> V_533 . V_647 ) ;
if ( F_21 ( V_7 ) ) {
V_1 -> V_100 . V_582 = F_63 ;
F_375 ( & V_1 -> V_100 ) ;
if ( F_35 ( V_7 ) )
V_69 = F_181 ( V_1 -> V_72 ) ;
else
V_69 = F_182 ( V_1 -> V_72 ) ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_1 -> V_70 ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_86 ;
F_33 ( L_120 ,
F_31 ( V_69 ) ) ;
}
F_376 ( & V_29 -> V_31 , V_30 , V_263 ) ;
V_29 -> V_31 . V_662 = F_172 ;
F_377 ( V_9 , V_69 ) ;
return true ;
}
bool
F_378 ( struct V_2 * V_3 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_565 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
int type ;
V_1 -> V_70 = V_87 ;
if ( F_117 ( V_7 ) -> V_209 >= 9 )
V_1 -> V_146 = F_87 ;
else if ( F_21 ( V_7 ) )
V_1 -> V_146 = F_86 ;
else if ( F_104 ( V_7 ) || F_89 ( V_7 ) )
V_1 -> V_146 = F_83 ;
else if ( F_61 ( V_7 ) )
V_1 -> V_146 = F_78 ;
else
V_1 -> V_146 = F_77 ;
if ( F_117 ( V_7 ) -> V_209 >= 9 )
V_1 -> V_148 = F_90 ;
else
V_1 -> V_148 = F_88 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) ;
V_1 -> V_239 = V_29 ;
if ( F_346 ( V_7 , V_18 ) )
type = V_581 ;
else
type = V_663 ;
if ( type == V_581 )
V_64 -> type = V_5 ;
if ( F_44 ( F_21 ( V_7 ) && F_1 ( V_1 ) &&
V_18 != V_175 && V_18 != V_177 ) )
return false ;
F_33 ( L_121 ,
type == V_581 ? L_122 : L_123 ,
F_32 ( V_18 ) ) ;
F_379 ( V_7 , V_9 , & V_664 , type ) ;
F_380 ( V_9 , & V_665 ) ;
V_9 -> V_666 = true ;
V_9 -> V_667 = 0 ;
F_366 ( & V_1 -> V_301 ,
F_156 ) ;
F_381 ( V_29 , V_64 ) ;
F_382 ( V_9 ) ;
if ( F_10 ( V_7 ) )
V_29 -> V_668 = V_669 ;
else
V_29 -> V_668 = V_670 ;
V_29 -> V_671 = F_108 ;
switch ( V_18 ) {
case V_19 :
V_64 -> V_672 = V_673 ;
break;
case V_175 :
V_64 -> V_672 = V_674 ;
break;
case V_177 :
V_64 -> V_672 = V_675 ;
break;
case V_179 :
V_64 -> V_672 = V_676 ;
break;
default:
F_103 () ;
}
if ( F_1 ( V_1 ) ) {
F_23 ( V_1 ) ;
F_352 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_58 ( V_1 ) ;
else
F_48 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
}
F_102 ( V_1 , V_29 ) ;
if ( F_104 ( V_7 ) || F_89 ( V_7 ) || F_117 ( V_7 ) -> V_209 >= 9 ) {
if ( V_18 == V_175 || V_18 == V_177 || V_18 == V_179 ) {
F_383 ( V_3 ,
V_29 -> V_4 . V_4 . V_567 ) ;
}
}
if ( ! F_369 ( V_1 , V_29 ) ) {
F_107 ( & V_1 -> V_154 ) ;
if ( F_1 ( V_1 ) ) {
F_333 ( & V_1 -> V_301 ) ;
F_23 ( V_1 ) ;
F_155 ( V_1 ) ;
F_27 ( V_1 ) ;
}
F_384 ( V_9 ) ;
F_330 ( V_9 ) ;
return false ;
}
F_347 ( V_1 , V_9 ) ;
if ( F_123 ( V_7 ) && ! F_385 ( V_7 ) ) {
T_5 V_344 = F_22 ( V_677 ) ;
F_39 ( V_677 , ( V_344 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_386 ( struct V_6 * V_7 , int V_73 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 ;
struct V_64 * V_64 ;
struct V_467 * V_65 ;
struct V_29 * V_29 ;
V_3 = F_387 ( sizeof( * V_3 ) , V_678 ) ;
if ( ! V_3 )
return;
V_29 = F_388 () ;
if ( ! V_29 ) {
F_313 ( V_3 ) ;
return;
}
V_64 = & V_3 -> V_4 ;
V_65 = & V_64 -> V_4 ;
F_389 ( V_7 , & V_64 -> V_4 , & V_679 ,
V_680 ) ;
V_64 -> V_681 = F_130 ;
V_64 -> V_682 = F_189 ;
V_64 -> V_668 = F_178 ;
V_64 -> V_683 = F_185 ;
V_64 -> V_684 = F_336 ;
if ( F_35 ( V_7 ) ) {
V_64 -> V_685 = F_236 ;
V_64 -> V_686 = F_232 ;
V_64 -> V_311 = F_216 ;
V_64 -> V_687 = F_196 ;
} else if ( F_21 ( V_7 ) ) {
V_64 -> V_685 = F_225 ;
V_64 -> V_686 = F_220 ;
V_64 -> V_311 = F_216 ;
V_64 -> V_687 = F_195 ;
} else {
V_64 -> V_686 = F_218 ;
V_64 -> V_311 = F_215 ;
if ( F_117 ( V_7 ) -> V_209 >= 5 )
V_64 -> V_687 = F_194 ;
}
V_3 -> V_18 = V_18 ;
V_3 -> V_565 . V_73 = V_73 ;
V_64 -> type = V_568 ;
if ( F_35 ( V_7 ) ) {
if ( V_18 == V_179 )
V_64 -> V_688 = 1 << 2 ;
else
V_64 -> V_688 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_64 -> V_688 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_64 -> V_689 = 0 ;
V_64 -> V_690 = F_340 ;
V_3 -> V_691 = F_341 ;
V_51 -> V_692 [ V_18 ] = V_3 ;
if ( ! F_378 ( V_3 , V_29 ) ) {
F_335 ( V_65 ) ;
F_313 ( V_3 ) ;
F_313 ( V_29 ) ;
}
}
void F_390 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_693 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_692 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_568 ) {
if ( ! V_3 -> V_565 . V_506 )
continue;
if ( V_3 -> V_565 . V_509 )
F_391 ( & V_3 -> V_565 . V_510 ) ;
}
}
}
void F_392 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_693 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_692 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_568 ) {
int V_138 ;
if ( ! V_3 -> V_565 . V_506 )
continue;
V_138 = F_393 ( & V_3 -> V_565 . V_510 ) ;
if ( V_138 != 0 ) {
F_292 ( & V_3 -> V_565 ) ;
}
}
}
}
