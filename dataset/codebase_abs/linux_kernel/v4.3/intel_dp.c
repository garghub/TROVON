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
return F_62 ( 0 ) ;
else if ( F_63 ( V_7 ) )
return V_94 ;
else
return F_53 ( F_42 ( V_1 ) ) ;
}
static T_5 F_64 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_61 ( V_7 ) )
return F_65 ( 0 ) ;
else if ( F_63 ( V_7 ) )
return V_95 ;
else
return F_51 ( F_42 ( V_1 ) ) ;
}
static int F_66 ( struct V_96 * V_97 , unsigned long V_98 ,
void * V_99 )
{
struct V_1 * V_1 = F_67 ( V_97 , F_68 ( * V_1 ) ,
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
V_103 = F_69 ( V_69 ) ;
V_101 = F_22 ( V_103 ) ;
V_101 &= V_105 ;
F_39 ( V_103 , V_101 | 0x1F ) ;
F_39 ( V_102 , V_106 | V_107 ) ;
F_70 ( V_1 -> V_108 ) ;
}
F_27 ( V_1 ) ;
return 0 ;
}
static bool F_71 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_21 ( V_7 ) &&
V_1 -> V_70 == V_87 )
return false ;
return ( F_22 ( F_64 ( V_1 ) ) & V_89 ) != 0 ;
}
static bool F_72 ( struct V_1 * V_1 )
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
F_73 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_71 ( V_1 ) && ! F_72 ( V_1 ) ) {
F_8 ( 1 , L_7 ) ;
F_33 ( L_8 ,
F_22 ( F_64 ( V_1 ) ) ,
F_22 ( F_60 ( V_1 ) ) ) ;
}
}
static T_2
F_74 ( struct V_1 * V_1 , bool V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_110 = V_1 -> V_111 ;
T_2 V_112 ;
bool V_113 ;
#define F_75 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_109 )
V_113 = F_76 ( V_51 -> V_114 , F_75 ,
F_77 ( 10 ) ) ;
else
V_113 = F_78 ( F_75 , 10 ) == 0 ;
if ( ! V_113 )
F_79 ( L_9 ,
V_109 ) ;
#undef F_75
return V_112 ;
}
static T_2 F_80 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_115 ? 0 : F_20 ( V_7 ) / 2 ;
}
static T_2 F_81 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( V_115 )
return 0 ;
if ( V_3 -> V_18 == V_19 ) {
return F_82 ( V_51 -> V_116 , 2000 ) ;
} else {
return F_82 ( F_83 ( V_7 ) , 2 ) ;
}
}
static T_2 F_84 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( V_3 -> V_18 == V_19 ) {
if ( V_115 )
return 0 ;
return F_85 ( V_51 -> V_116 , 2000 ) ;
} else if ( V_51 -> V_117 == V_118 ) {
switch ( V_115 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_115 ? 0 : F_82 ( F_83 ( V_7 ) , 2 ) ;
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
int V_119 ,
T_2 V_120 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_121 , V_122 ;
if ( F_89 ( V_7 ) )
V_121 = 3 ;
else
V_121 = 5 ;
if ( F_90 ( V_7 ) && V_1 -> V_111 == V_123 )
V_122 = V_124 ;
else
V_122 = V_125 ;
return V_126 |
V_127 |
( V_109 ? V_128 : 0 ) |
V_129 |
V_122 |
V_130 |
( V_119 << V_131 ) |
( V_121 << V_132 ) |
( V_120 << V_133 ) ;
}
static T_2 F_91 ( struct V_1 * V_1 ,
bool V_109 ,
int V_119 ,
T_2 V_99 )
{
return V_126 |
V_127 |
( V_109 ? V_128 : 0 ) |
V_129 |
V_134 |
V_130 |
( V_119 << V_131 ) |
F_92 ( 32 ) ;
}
static int
F_93 ( struct V_1 * V_1 ,
const T_3 * V_135 , int V_119 ,
T_3 * V_136 , int V_137 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_110 = V_1 -> V_111 ;
T_2 V_138 = V_110 + 4 ;
T_2 V_120 ;
int V_46 , V_139 , V_140 ;
T_2 V_112 ;
int V_141 , clock = 0 ;
bool V_109 = F_94 ( V_7 ) ;
bool V_142 ;
F_23 ( V_1 ) ;
V_142 = F_95 ( V_1 ) ;
F_96 ( & V_51 -> V_143 , 0 ) ;
F_73 ( V_1 ) ;
F_97 ( V_51 ) ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_112 = F_98 ( V_110 ) ;
if ( ( V_112 & V_126 ) == 0 )
break;
F_70 ( 1 ) ;
}
if ( V_141 == 3 ) {
static T_5 V_144 = - 1 ;
const T_5 V_112 = F_22 ( V_110 ) ;
if ( V_112 != V_144 ) {
F_8 ( 1 , L_10 ,
V_112 ) ;
V_144 = V_112 ;
}
V_139 = - V_145 ;
goto V_146;
}
if ( F_44 ( V_119 > 20 || V_137 > 20 ) ) {
V_139 = - V_147 ;
goto V_146;
}
while ( ( V_120 = V_1 -> V_148 ( V_1 , clock ++ ) ) ) {
T_5 V_149 = V_1 -> V_150 ( V_1 ,
V_109 ,
V_119 ,
V_120 ) ;
for ( V_141 = 0 ; V_141 < 5 ; V_141 ++ ) {
for ( V_46 = 0 ; V_46 < V_119 ; V_46 += 4 )
F_39 ( V_138 + V_46 ,
F_18 ( V_135 + V_46 ,
V_119 - V_46 ) ) ;
F_39 ( V_110 , V_149 ) ;
V_112 = F_74 ( V_1 , V_109 ) ;
F_39 ( V_110 ,
V_112 |
V_127 |
V_129 |
V_130 ) ;
if ( V_112 & V_129 )
continue;
if ( V_112 & V_130 ) {
F_99 ( 400 , 500 ) ;
continue;
}
if ( V_112 & V_127 )
goto V_113;
}
}
if ( ( V_112 & V_127 ) == 0 ) {
F_79 ( L_11 , V_112 ) ;
V_139 = - V_145 ;
goto V_146;
}
V_113:
if ( V_112 & V_130 ) {
F_79 ( L_12 , V_112 ) ;
V_139 = - V_151 ;
goto V_146;
}
if ( V_112 & V_129 ) {
F_33 ( L_13 , V_112 ) ;
V_139 = - V_152 ;
goto V_146;
}
V_140 = ( ( V_112 & V_153 ) >>
V_131 ) ;
if ( V_140 > V_137 )
V_140 = V_137 ;
for ( V_46 = 0 ; V_46 < V_140 ; V_46 += 4 )
F_19 ( F_22 ( V_138 + V_46 ) ,
V_136 + V_46 , V_140 - V_46 ) ;
V_139 = V_140 ;
V_146:
F_96 ( & V_51 -> V_143 , V_154 ) ;
F_100 ( V_51 ) ;
if ( V_142 )
F_101 ( V_1 , false ) ;
F_27 ( V_1 ) ;
return V_139 ;
}
static T_6
F_102 ( struct V_155 * V_156 , struct V_157 * V_158 )
{
struct V_1 * V_1 = F_67 ( V_156 , struct V_1 , V_156 ) ;
T_3 V_159 [ 20 ] , V_160 [ 20 ] ;
T_7 V_161 , V_162 ;
int V_139 ;
V_159 [ 0 ] = ( V_158 -> V_163 << 4 ) |
( ( V_158 -> V_164 >> 16 ) & 0xf ) ;
V_159 [ 1 ] = ( V_158 -> V_164 >> 8 ) & 0xff ;
V_159 [ 2 ] = V_158 -> V_164 & 0xff ;
V_159 [ 3 ] = V_158 -> V_165 - 1 ;
switch ( V_158 -> V_163 & ~ V_166 ) {
case V_167 :
case V_168 :
V_161 = V_158 -> V_165 ? V_169 + V_158 -> V_165 : V_170 ;
V_162 = 2 ;
if ( F_44 ( V_161 > 20 ) )
return - V_147 ;
memcpy ( V_159 + V_169 , V_158 -> V_171 , V_158 -> V_165 ) ;
V_139 = F_93 ( V_1 , V_159 , V_161 , V_160 , V_162 ) ;
if ( V_139 > 0 ) {
V_158 -> V_172 = V_160 [ 0 ] >> 4 ;
if ( V_139 > 1 ) {
V_139 = F_103 ( int , V_160 [ 1 ] , 0 , V_158 -> V_165 ) ;
} else {
V_139 = V_158 -> V_165 ;
}
}
break;
case V_173 :
case V_174 :
V_161 = V_158 -> V_165 ? V_169 : V_170 ;
V_162 = V_158 -> V_165 + 1 ;
if ( F_44 ( V_162 > 20 ) )
return - V_147 ;
V_139 = F_93 ( V_1 , V_159 , V_161 , V_160 , V_162 ) ;
if ( V_139 > 0 ) {
V_158 -> V_172 = V_160 [ 0 ] >> 4 ;
V_139 -- ;
memcpy ( V_158 -> V_171 , V_160 + 1 , V_139 ) ;
}
break;
default:
V_139 = - V_175 ;
break;
}
return V_139 ;
}
static void
F_104 ( struct V_1 * V_1 , struct V_29 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_176 * V_177 = & V_51 -> V_178 . V_179 [ V_18 ] ;
const char * V_180 = NULL ;
T_2 V_181 = V_123 ;
int V_139 ;
if ( F_105 ( V_7 ) && V_18 == V_182 ) {
switch ( V_177 -> V_183 ) {
case V_184 :
V_181 = V_185 ;
break;
case V_186 :
V_181 = V_187 ;
break;
case V_188 :
V_181 = V_189 ;
break;
case V_190 :
default:
V_181 = V_123 ;
}
}
switch ( V_18 ) {
case V_19 :
V_1 -> V_111 = V_123 ;
V_180 = L_14 ;
break;
case V_191 :
V_1 -> V_111 = V_192 ;
V_180 = L_15 ;
break;
case V_193 :
V_1 -> V_111 = V_194 ;
V_180 = L_16 ;
break;
case V_195 :
V_1 -> V_111 = V_196 ;
V_180 = L_17 ;
break;
case V_182 :
V_1 -> V_111 = V_181 ;
V_180 = L_18 ;
break;
default:
F_106 () ;
}
if ( ! F_107 ( V_7 ) && ! F_90 ( V_7 ) && V_18 != V_182 )
V_1 -> V_111 = V_1 -> V_73 + 0x10 ;
V_1 -> V_156 . V_180 = V_180 ;
V_1 -> V_156 . V_7 = V_7 -> V_7 ;
V_1 -> V_156 . V_197 = F_102 ;
F_33 ( L_19 , V_180 ,
V_9 -> V_4 . V_198 -> V_199 . V_180 ) ;
V_139 = F_108 ( & V_1 -> V_156 ) ;
if ( V_139 < 0 ) {
F_79 ( L_20 ,
V_180 , V_139 ) ;
return;
}
V_139 = F_109 ( & V_9 -> V_4 . V_198 -> V_199 ,
& V_1 -> V_156 . V_200 . V_7 . V_199 ,
V_1 -> V_156 . V_200 . V_7 . V_199 . V_180 ) ;
if ( V_139 < 0 ) {
F_79 ( L_21 , V_180 , V_139 ) ;
F_110 ( & V_1 -> V_156 ) ;
}
}
static void
F_111 ( struct V_29 * V_29 )
{
struct V_1 * V_1 = F_4 ( & V_29 -> V_4 ) ;
if ( ! V_29 -> V_201 )
F_112 ( & V_29 -> V_4 . V_198 -> V_199 ,
V_1 -> V_156 . V_200 . V_7 . V_199 . V_180 ) ;
F_113 ( V_29 ) ;
}
static void
F_114 ( struct V_202 * V_203 )
{
T_5 V_204 ;
memset ( & V_203 -> V_205 , 0 ,
sizeof( V_203 -> V_205 ) ) ;
V_203 -> V_206 = V_207 ;
V_203 -> V_205 . V_208 = 0 ;
V_203 -> V_205 . V_209 = 0 ;
V_204 = F_115 ( V_207 ) ;
switch ( V_203 -> V_210 / 2 ) {
case 81000 :
V_204 |= F_116 ( V_211 ,
V_207 ) ;
break;
case 135000 :
V_204 |= F_116 ( V_212 ,
V_207 ) ;
break;
case 270000 :
V_204 |= F_116 ( V_213 ,
V_207 ) ;
break;
case 162000 :
V_204 |= F_116 ( V_214 ,
V_207 ) ;
break;
case 108000 :
V_204 |= F_116 ( V_215 ,
V_207 ) ;
break;
case 216000 :
V_204 |= F_116 ( V_216 ,
V_207 ) ;
break;
}
V_203 -> V_205 . V_204 = V_204 ;
}
void
F_117 ( struct V_202 * V_203 )
{
memset ( & V_203 -> V_205 , 0 ,
sizeof( V_203 -> V_205 ) ) ;
switch ( V_203 -> V_210 / 2 ) {
case 81000 :
V_203 -> V_206 = V_217 ;
break;
case 135000 :
V_203 -> V_206 = V_218 ;
break;
case 270000 :
V_203 -> V_206 = V_219 ;
break;
}
}
static int
F_118 ( struct V_1 * V_1 , const int * * V_220 )
{
if ( V_1 -> V_221 ) {
* V_220 = V_1 -> V_220 ;
return V_1 -> V_221 ;
}
* V_220 = V_222 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
static bool F_119 ( struct V_6 * V_7 )
{
if ( F_105 ( V_7 ) && F_120 ( V_7 ) <= V_223 )
return false ;
if ( ( F_107 ( V_7 ) && ! F_121 ( V_7 ) ) || F_90 ( V_7 ) ||
( F_122 ( V_7 ) -> V_224 >= 9 ) )
return true ;
else
return false ;
}
static int
F_123 ( struct V_6 * V_7 , const int * * V_225 )
{
int V_165 ;
if ( F_61 ( V_7 ) ) {
* V_225 = V_226 ;
V_165 = F_124 ( V_226 ) ;
} else if ( F_105 ( V_7 ) ) {
* V_225 = V_227 ;
V_165 = F_124 ( V_227 ) ;
} else {
* V_225 = V_222 ;
V_165 = F_124 ( V_222 ) ;
}
if ( ! F_119 ( V_7 ) )
V_165 -- ;
return V_165 ;
}
static void
F_125 ( struct V_64 * V_65 ,
struct V_202 * V_203 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
const struct V_228 * V_229 = NULL ;
int V_46 , V_230 = 0 ;
if ( F_126 ( V_7 ) ) {
V_229 = V_231 ;
V_230 = F_124 ( V_231 ) ;
} else if ( F_63 ( V_7 ) ) {
V_229 = V_232 ;
V_230 = F_124 ( V_232 ) ;
} else if ( F_35 ( V_7 ) ) {
V_229 = V_82 ;
V_230 = F_124 ( V_82 ) ;
} else if ( F_21 ( V_7 ) ) {
V_229 = V_84 ;
V_230 = F_124 ( V_84 ) ;
}
if ( V_229 && V_230 ) {
for ( V_46 = 0 ; V_46 < V_230 ; V_46 ++ ) {
if ( V_203 -> V_210 == V_229 [ V_46 ] . clock ) {
V_203 -> V_83 = V_229 [ V_46 ] . V_83 ;
V_203 -> V_233 = true ;
break;
}
}
}
}
static int F_127 ( const int * V_225 , int V_234 ,
const int * V_220 , int V_235 ,
int * V_236 )
{
int V_46 = 0 , V_237 = 0 , V_238 = 0 ;
while ( V_46 < V_234 && V_237 < V_235 ) {
if ( V_225 [ V_46 ] == V_220 [ V_237 ] ) {
if ( F_44 ( V_238 >= V_239 ) )
return V_238 ;
V_236 [ V_238 ] = V_225 [ V_46 ] ;
++ V_238 ;
++ V_46 ;
++ V_237 ;
} else if ( V_225 [ V_46 ] < V_220 [ V_237 ] ) {
++ V_46 ;
} else {
++ V_237 ;
}
}
return V_238 ;
}
static int F_128 ( struct V_1 * V_1 ,
int * V_236 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_225 , * V_220 ;
int V_234 , V_235 ;
V_235 = F_118 ( V_1 , & V_220 ) ;
V_234 = F_123 ( V_7 , & V_225 ) ;
return F_127 ( V_225 , V_234 ,
V_220 , V_235 ,
V_236 ) ;
}
static void F_129 ( char * V_240 , T_7 V_241 ,
const int * V_242 , int V_243 )
{
int V_46 ;
V_240 [ 0 ] = '\0' ;
for ( V_46 = 0 ; V_46 < V_243 ; V_46 ++ ) {
int V_244 = snprintf ( V_240 , V_241 , L_22 , V_46 ? L_23 : L_24 , V_242 [ V_46 ] ) ;
if ( V_244 >= V_241 )
return;
V_240 += V_244 ;
V_241 -= V_244 ;
}
}
static void F_130 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_225 , * V_220 ;
int V_234 , V_235 , V_245 ;
int V_236 [ V_239 ] ;
char V_240 [ 128 ] ;
if ( ( V_246 & V_247 ) == 0 )
return;
V_234 = F_123 ( V_7 , & V_225 ) ;
F_129 ( V_240 , sizeof( V_240 ) , V_225 , V_234 ) ;
F_33 ( L_25 , V_240 ) ;
V_235 = F_118 ( V_1 , & V_220 ) ;
F_129 ( V_240 , sizeof( V_240 ) , V_220 , V_235 ) ;
F_33 ( L_26 , V_240 ) ;
V_245 = F_128 ( V_1 , V_236 ) ;
F_129 ( V_240 , sizeof( V_240 ) , V_236 , V_245 ) ;
F_33 ( L_27 , V_240 ) ;
}
static int F_131 ( int V_248 , const int * V_249 )
{
int V_46 = 0 ;
for ( V_46 = 0 ; V_46 < V_239 ; ++ V_46 )
if ( V_248 == V_249 [ V_46 ] )
break;
return V_46 ;
}
int
F_17 ( struct V_1 * V_1 )
{
int V_249 [ V_239 ] = {} ;
int V_241 ;
V_241 = F_128 ( V_1 , V_249 ) ;
if ( F_44 ( V_241 <= 0 ) )
return 162000 ;
return V_249 [ F_131 ( 0 , V_249 ) - 1 ] ;
}
int F_132 ( struct V_1 * V_1 , int V_250 )
{
return F_131 ( V_250 , V_1 -> V_220 ) ;
}
bool
F_133 ( struct V_64 * V_65 ,
struct V_202 * V_203 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_251 = & V_203 -> V_4 . V_251 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_252 * V_252 = F_134 ( V_203 -> V_4 . V_253 ) ;
struct V_29 * V_29 = V_1 -> V_254 ;
int V_255 , clock ;
int V_256 = 1 ;
int V_257 = F_9 ( V_1 ) ;
int V_258 = 0 ;
int V_259 ;
int V_23 , V_34 ;
int V_260 , V_261 ;
int V_236 [ V_239 ] = {} ;
int V_245 ;
V_245 = F_128 ( V_1 , V_236 ) ;
F_44 ( V_245 <= 0 ) ;
V_259 = V_245 - 1 ;
if ( F_63 ( V_7 ) && ! F_10 ( V_7 ) && V_18 != V_19 )
V_203 -> V_262 = true ;
V_203 -> V_263 = true ;
V_203 -> V_264 = false ;
V_203 -> V_265 = V_1 -> V_265 && V_18 != V_19 ;
if ( F_1 ( V_1 ) && V_29 -> V_31 . V_30 ) {
F_135 ( V_29 -> V_31 . V_30 ,
V_251 ) ;
if ( F_122 ( V_7 ) -> V_224 >= 9 ) {
int V_139 ;
V_139 = F_136 ( V_203 ) ;
if ( V_139 )
return V_139 ;
}
if ( ! F_63 ( V_7 ) )
F_137 ( V_252 , V_203 ,
V_29 -> V_31 . V_266 ) ;
else
F_138 ( V_252 , V_203 ,
V_29 -> V_31 . V_266 ) ;
}
if ( V_251 -> V_40 & V_41 )
return false ;
F_33 ( L_28
L_29 ,
V_257 , V_236 [ V_259 ] ,
V_251 -> V_267 ) ;
V_23 = V_203 -> V_268 ;
if ( F_1 ( V_1 ) ) {
if ( V_29 -> V_4 . V_269 . V_270 == 0 &&
( V_51 -> V_178 . V_271 && V_51 -> V_178 . V_271 < V_23 ) ) {
F_33 ( L_30 ,
V_51 -> V_178 . V_271 ) ;
V_23 = V_51 -> V_178 . V_271 ;
}
V_256 = V_257 ;
V_258 = V_259 ;
}
for (; V_23 >= 6 * 3 ; V_23 -= 2 * 3 ) {
V_34 = F_13 ( V_251 -> V_267 ,
V_23 ) ;
for ( clock = V_258 ; clock <= V_259 ; clock ++ ) {
for ( V_255 = V_256 ;
V_255 <= V_257 ;
V_255 <<= 1 ) {
V_261 = V_236 [ clock ] ;
V_260 = F_14 ( V_261 ,
V_255 ) ;
if ( V_34 <= V_260 ) {
goto V_272;
}
}
}
}
return false ;
V_272:
if ( V_1 -> V_273 ) {
if ( V_23 != 18 && F_139 ( V_251 ) > 1 )
V_1 -> V_274 = V_275 ;
else
V_1 -> V_274 = 0 ;
}
if ( V_1 -> V_274 )
V_203 -> V_276 = true ;
V_1 -> V_255 = V_255 ;
if ( V_1 -> V_221 ) {
V_1 -> V_277 = 0 ;
V_1 -> V_278 =
F_132 ( V_1 , V_236 [ clock ] ) ;
} else {
V_1 -> V_277 =
F_140 ( V_236 [ clock ] ) ;
V_1 -> V_278 = 0 ;
}
V_203 -> V_268 = V_23 ;
V_203 -> V_210 = V_236 [ clock ] ;
F_33 ( L_31 ,
V_1 -> V_277 , V_1 -> V_255 ,
V_203 -> V_210 , V_23 ) ;
F_33 ( L_32 ,
V_34 , V_260 ) ;
F_141 ( V_23 , V_255 ,
V_251 -> V_267 ,
V_203 -> V_210 ,
& V_203 -> V_279 ) ;
if ( V_29 -> V_31 . V_280 != NULL &&
V_51 -> V_281 . type == V_282 ) {
V_203 -> V_264 = true ;
F_141 ( V_23 , V_255 ,
V_29 -> V_31 . V_280 -> clock ,
V_203 -> V_210 ,
& V_203 -> V_283 ) ;
}
if ( F_105 ( V_7 ) && F_1 ( V_1 ) )
F_114 ( V_203 ) ;
else if ( F_61 ( V_7 ) )
;
else if ( F_107 ( V_7 ) || F_90 ( V_7 ) )
F_117 ( V_203 ) ;
else
F_125 ( V_65 , V_203 ) ;
return true ;
}
static void F_142 ( struct V_1 * V_1 )
{
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_252 * V_253 = F_134 ( V_284 -> V_4 . V_4 . V_253 ) ;
struct V_6 * V_7 = V_253 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_285 ;
F_33 ( L_33 ,
V_253 -> V_286 -> V_210 ) ;
V_285 = F_22 ( V_287 ) ;
V_285 &= ~ V_288 ;
if ( V_253 -> V_286 -> V_210 == 162000 ) {
F_33 ( L_34 ) ;
V_285 |= V_289 ;
V_1 -> V_72 |= V_289 ;
} else {
V_285 |= V_290 ;
V_1 -> V_72 |= V_290 ;
}
F_39 ( V_287 , V_285 ) ;
F_40 ( V_287 ) ;
F_143 ( 500 ) ;
}
static void F_144 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_252 * V_253 = F_134 ( V_65 -> V_4 . V_253 ) ;
struct V_27 * V_251 = & V_253 -> V_286 -> V_4 . V_251 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) & V_75 ;
V_1 -> V_72 |= V_76 | V_77 ;
V_1 -> V_72 |= F_34 ( V_1 -> V_255 ) ;
if ( V_253 -> V_286 -> V_265 )
V_1 -> V_72 |= V_291 ;
if ( F_145 ( V_7 ) && V_18 == V_19 ) {
if ( V_251 -> V_40 & V_292 )
V_1 -> V_72 |= V_293 ;
if ( V_251 -> V_40 & V_294 )
V_1 -> V_72 |= V_295 ;
V_1 -> V_72 |= V_296 ;
if ( F_146 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_297 ;
V_1 -> V_72 |= V_253 -> V_69 << 29 ;
} else if ( F_147 ( V_7 ) && V_18 != V_19 ) {
T_5 V_298 ;
V_1 -> V_72 |= V_296 ;
V_298 = F_22 ( F_148 ( V_253 -> V_69 ) ) ;
if ( F_146 ( V_1 -> V_11 ) )
V_298 |= V_299 ;
else
V_298 &= ~ V_299 ;
F_39 ( F_148 ( V_253 -> V_69 ) , V_298 ) ;
} else {
if ( ! F_63 ( V_7 ) && ! F_21 ( V_7 ) )
V_1 -> V_72 |= V_1 -> V_274 ;
if ( V_251 -> V_40 & V_292 )
V_1 -> V_72 |= V_293 ;
if ( V_251 -> V_40 & V_294 )
V_1 -> V_72 |= V_295 ;
V_1 -> V_72 |= V_300 ;
if ( F_146 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_297 ;
if ( F_35 ( V_7 ) )
V_1 -> V_72 |= F_36 ( V_253 -> V_69 ) ;
else if ( V_253 -> V_69 == V_79 )
V_1 -> V_72 |= V_80 ;
}
}
static void F_149 ( struct V_1 * V_1 ,
T_5 V_301 ,
T_5 V_302 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_303 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
V_303 = F_64 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_33 ( L_35 ,
V_301 , V_302 ,
F_22 ( V_303 ) ,
F_22 ( V_102 ) ) ;
if ( F_150 ( ( F_22 ( V_303 ) & V_301 ) == V_302 , 5000 , 10 ) ) {
F_79 ( L_36 ,
F_22 ( V_303 ) ,
F_22 ( V_102 ) ) ;
}
F_33 ( L_37 ) ;
}
static void F_151 ( struct V_1 * V_1 )
{
F_33 ( L_38 ) ;
F_149 ( V_1 , V_304 , V_305 ) ;
}
static void F_152 ( struct V_1 * V_1 )
{
F_33 ( L_39 ) ;
F_149 ( V_1 , V_306 , V_307 ) ;
}
static void F_153 ( struct V_1 * V_1 )
{
F_33 ( L_40 ) ;
F_154 ( V_1 -> V_308 ,
V_1 -> V_108 ) ;
F_149 ( V_1 , V_309 , V_310 ) ;
}
static void F_155 ( struct V_1 * V_1 )
{
F_154 ( V_1 -> V_311 ,
V_1 -> V_312 ) ;
}
static void F_156 ( struct V_1 * V_1 )
{
F_154 ( V_1 -> V_313 ,
V_1 -> V_314 ) ;
}
static T_5 F_157 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_315 ;
F_43 ( & V_51 -> V_68 ) ;
V_315 = F_22 ( F_60 ( V_1 ) ) ;
if ( ! F_61 ( V_7 ) ) {
V_315 &= ~ V_316 ;
V_315 |= V_106 ;
}
return V_315 ;
}
static bool F_95 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_317 ;
T_5 V_303 , V_102 ;
bool V_318 = ! V_1 -> V_319 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_158 ( & V_1 -> V_320 ) ;
V_1 -> V_319 = true ;
if ( F_72 ( V_1 ) )
return V_318 ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
F_33 ( L_41 ,
F_32 ( V_3 -> V_18 ) ) ;
if ( ! F_71 ( V_1 ) )
F_153 ( V_1 ) ;
V_317 = F_157 ( V_1 ) ;
V_317 |= V_90 ;
V_303 = F_64 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
F_33 ( L_42 ,
F_22 ( V_303 ) , F_22 ( V_102 ) ) ;
if ( ! F_71 ( V_1 ) ) {
F_33 ( L_43 ,
F_32 ( V_3 -> V_18 ) ) ;
F_70 ( V_1 -> V_321 ) ;
}
return V_318 ;
}
void F_159 ( struct V_1 * V_1 )
{
bool V_142 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_142 = F_95 ( V_1 ) ;
F_27 ( V_1 ) ;
F_160 ( ! V_142 , L_44 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
}
static void F_161 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
enum V_66 V_67 ;
T_5 V_317 ;
T_5 V_303 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
F_44 ( V_1 -> V_319 ) ;
if ( ! F_72 ( V_1 ) )
return;
F_33 ( L_45 ,
F_32 ( V_3 -> V_18 ) ) ;
V_317 = F_157 ( V_1 ) ;
V_317 &= ~ V_90 ;
V_102 = F_60 ( V_1 ) ;
V_303 = F_64 ( V_1 ) ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
F_33 ( L_42 ,
F_22 ( V_303 ) , F_22 ( V_102 ) ) ;
if ( ( V_317 & V_322 ) == 0 )
V_1 -> V_308 = V_323 ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
static void F_162 ( struct V_324 * V_325 )
{
struct V_1 * V_1 = F_67 ( F_163 ( V_325 ) ,
struct V_1 , V_320 ) ;
F_23 ( V_1 ) ;
if ( ! V_1 -> V_319 )
F_161 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
unsigned long V_326 ;
V_326 = F_165 ( V_1 -> V_108 * 5 ) ;
F_166 ( & V_1 -> V_320 , V_326 ) ;
}
static void F_101 ( struct V_1 * V_1 , bool V_327 )
{
struct V_50 * V_51 =
F_3 ( V_1 ) -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_160 ( ! V_1 -> V_319 , L_46 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_1 -> V_319 = false ;
if ( V_327 )
F_161 ( V_1 ) ;
else
F_164 ( V_1 ) ;
}
static void F_167 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_317 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_47 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
if ( F_8 ( F_71 ( V_1 ) ,
L_48 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) )
return;
F_153 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
V_317 = F_157 ( V_1 ) ;
if ( F_168 ( V_7 ) ) {
V_317 &= ~ V_328 ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
}
V_317 |= V_322 ;
if ( ! F_168 ( V_7 ) )
V_317 |= V_328 ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
F_151 ( V_1 ) ;
V_1 -> V_311 = V_323 ;
if ( F_168 ( V_7 ) ) {
V_317 |= V_328 ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
}
}
void F_169 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_167 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_170 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_317 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_49 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
F_8 ( ! V_1 -> V_319 , L_50 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_317 = F_157 ( V_1 ) ;
V_317 &= ~ ( V_322 | V_328 | V_90 |
V_329 ) ;
V_102 = F_60 ( V_1 ) ;
V_1 -> V_319 = false ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
V_1 -> V_308 = V_323 ;
F_152 ( V_1 ) ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
void F_171 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_170 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_172 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_317 ;
T_5 V_102 ;
F_155 ( V_1 ) ;
F_23 ( V_1 ) ;
V_317 = F_157 ( V_1 ) ;
V_317 |= V_329 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
}
void F_173 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_51 ) ;
F_174 ( V_1 -> V_254 ) ;
F_172 ( V_1 ) ;
}
static void F_175 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_317 ;
T_5 V_102 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_317 = F_157 ( V_1 ) ;
V_317 &= ~ V_329 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_317 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
V_1 -> V_313 = V_323 ;
F_156 ( V_1 ) ;
}
void F_176 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_51 ) ;
F_175 ( V_1 ) ;
F_177 ( V_1 -> V_254 ) ;
}
static void F_178 ( struct V_29 * V_9 ,
bool V_330 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_331 ;
F_23 ( V_1 ) ;
V_331 = F_157 ( V_1 ) & V_329 ;
F_27 ( V_1 ) ;
if ( V_331 == V_330 )
return;
F_33 ( L_52 ,
V_330 ? L_53 : L_54 ) ;
if ( V_330 )
F_172 ( V_1 ) ;
else
F_175 ( V_1 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_332 * V_253 = V_3 -> V_4 . V_4 . V_253 ;
struct V_6 * V_7 = V_253 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_285 ;
F_180 ( V_51 ,
F_134 ( V_253 ) -> V_69 ) ;
F_33 ( L_51 ) ;
V_285 = F_22 ( V_287 ) ;
F_8 ( V_285 & V_333 , L_55 ) ;
F_8 ( V_285 & V_74 , L_56 ) ;
V_1 -> V_72 &= ~ ( V_74 | V_291 ) ;
V_1 -> V_72 |= V_333 ;
F_39 ( V_287 , V_1 -> V_72 ) ;
F_40 ( V_287 ) ;
F_143 ( 200 ) ;
}
static void F_181 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_332 * V_253 = V_3 -> V_4 . V_4 . V_253 ;
struct V_6 * V_7 = V_253 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_285 ;
F_180 ( V_51 ,
F_134 ( V_253 ) -> V_69 ) ;
V_285 = F_22 ( V_287 ) ;
F_8 ( ( V_285 & V_333 ) == 0 ,
L_57 ) ;
F_8 ( V_285 & V_74 , L_56 ) ;
V_285 &= ~ V_333 ;
F_39 ( V_287 , V_285 ) ;
F_40 ( V_287 ) ;
F_143 ( 200 ) ;
}
void F_182 ( struct V_1 * V_1 , int V_28 )
{
int V_139 , V_46 ;
if ( V_1 -> V_11 [ V_334 ] < 0x11 )
return;
if ( V_28 != V_335 ) {
V_139 = F_183 ( & V_1 -> V_156 , V_336 ,
V_337 ) ;
} else {
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_139 = F_183 ( & V_1 -> V_156 , V_336 ,
V_338 ) ;
if ( V_139 == 1 )
break;
F_70 ( 1 ) ;
}
}
if ( V_139 != 1 )
F_33 ( L_58 ,
V_28 == V_335 ? L_53 : L_54 ) ;
}
static bool F_184 ( struct V_64 * V_65 ,
enum V_69 * V_69 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_88 ;
V_67 = F_24 ( V_65 ) ;
if ( ! F_185 ( V_51 , V_67 ) )
return false ;
V_88 = F_22 ( V_1 -> V_73 ) ;
if ( ! ( V_88 & V_74 ) )
return false ;
if ( F_145 ( V_7 ) && V_18 == V_19 ) {
* V_69 = F_186 ( V_88 ) ;
} else if ( F_147 ( V_7 ) && V_18 != V_19 ) {
enum V_69 V_339 ;
F_187 (dev_priv, p) {
T_5 V_298 = F_22 ( F_148 ( V_339 ) ) ;
if ( F_188 ( V_298 ) == V_18 ) {
* V_69 = V_339 ;
return true ;
}
}
F_33 ( L_59 ,
V_1 -> V_73 ) ;
} else if ( F_35 ( V_7 ) ) {
* V_69 = F_189 ( V_88 ) ;
} else {
* V_69 = F_190 ( V_88 ) ;
}
return true ;
}
static void F_191 ( struct V_64 * V_65 ,
struct V_202 * V_203 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
T_5 V_88 , V_40 = 0 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_252 * V_253 = F_134 ( V_65 -> V_4 . V_253 ) ;
int V_340 ;
V_88 = F_22 ( V_1 -> V_73 ) ;
V_203 -> V_265 = V_88 & V_291 && V_18 != V_19 ;
if ( F_147 ( V_7 ) && V_18 != V_19 ) {
V_88 = F_22 ( F_148 ( V_253 -> V_69 ) ) ;
if ( V_88 & V_341 )
V_40 |= V_292 ;
else
V_40 |= V_342 ;
if ( V_88 & V_343 )
V_40 |= V_294 ;
else
V_40 |= V_344 ;
} else {
if ( V_88 & V_293 )
V_40 |= V_292 ;
else
V_40 |= V_342 ;
if ( V_88 & V_295 )
V_40 |= V_294 ;
else
V_40 |= V_344 ;
}
V_203 -> V_4 . V_251 . V_40 |= V_40 ;
if ( ! F_63 ( V_7 ) && ! F_21 ( V_7 ) &&
V_88 & V_275 )
V_203 -> V_276 = true ;
V_203 -> V_263 = true ;
F_192 ( V_253 , V_203 ) ;
if ( V_18 == V_19 ) {
if ( ( F_22 ( V_287 ) & V_288 ) == V_289 )
V_203 -> V_210 = 162000 ;
else
V_203 -> V_210 = 270000 ;
}
V_340 = F_193 ( V_203 -> V_210 ,
& V_203 -> V_279 ) ;
if ( F_63 ( V_51 -> V_7 ) && V_18 != V_19 )
F_194 ( V_203 , V_340 ) ;
V_203 -> V_4 . V_251 . V_267 = V_340 ;
if ( F_1 ( V_1 ) && V_51 -> V_178 . V_271 &&
V_203 -> V_268 > V_51 -> V_178 . V_271 ) {
F_33 ( L_60 ,
V_203 -> V_268 , V_51 -> V_178 . V_271 ) ;
V_51 -> V_178 . V_271 = V_203 -> V_268 ;
}
}
static void F_195 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_252 * V_253 = F_134 ( V_65 -> V_4 . V_253 ) ;
if ( V_253 -> V_286 -> V_265 )
F_196 ( V_65 ) ;
if ( F_197 ( V_7 ) && ! F_10 ( V_7 ) )
F_198 ( V_1 ) ;
F_159 ( V_1 ) ;
F_176 ( V_1 ) ;
F_182 ( V_1 , V_345 ) ;
F_171 ( V_1 ) ;
if ( F_122 ( V_7 ) -> V_224 < 5 )
F_199 ( V_1 ) ;
}
static void F_200 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
F_199 ( V_1 ) ;
if ( V_18 == V_19 )
F_181 ( V_1 ) ;
}
static void F_201 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_199 ( V_1 ) ;
}
static void F_202 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_252 =
F_134 ( V_65 -> V_4 . V_253 ) ;
enum V_347 V_348 = F_203 ( V_346 ) ;
enum V_69 V_69 = V_252 -> V_69 ;
T_5 V_349 ;
F_199 ( V_1 ) ;
F_26 ( & V_51 -> V_350 ) ;
V_349 = F_204 ( V_51 , V_69 , F_205 ( V_348 ) ) ;
V_349 |= V_351 ;
F_206 ( V_51 , V_69 , F_205 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_207 ( V_348 ) ) ;
V_349 |= V_351 ;
F_206 ( V_51 , V_69 , F_207 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_208 ( V_348 ) ) ;
V_349 &= ~ ( V_352 | V_353 ) ;
F_206 ( V_51 , V_69 , F_208 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_209 ( V_348 ) ) ;
V_349 &= ~ ( V_352 | V_353 ) ;
F_206 ( V_51 , V_69 , F_209 ( V_348 ) , V_349 ) ;
F_28 ( & V_51 -> V_350 ) ;
}
static void
F_210 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_354 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
if ( F_10 ( V_7 ) ) {
T_2 V_355 = F_22 ( F_211 ( V_18 ) ) ;
if ( V_354 & V_356 )
V_355 |= V_357 ;
else
V_355 &= ~ V_357 ;
V_355 &= ~ V_358 ;
switch ( V_354 & V_359 ) {
case V_360 :
V_355 |= V_361 ;
break;
case V_362 :
V_355 |= V_363 ;
break;
case V_364 :
V_355 |= V_365 ;
break;
case V_366 :
V_355 |= V_367 ;
break;
}
F_39 ( F_211 ( V_18 ) , V_355 ) ;
} else if ( ( F_145 ( V_7 ) && V_18 == V_19 ) ||
( F_147 ( V_7 ) && V_18 != V_19 ) ) {
* V_72 &= ~ V_368 ;
switch ( V_354 & V_359 ) {
case V_360 :
* V_72 |= V_296 ;
break;
case V_362 :
* V_72 |= V_369 ;
break;
case V_364 :
* V_72 |= V_370 ;
break;
case V_366 :
F_79 ( L_61 ) ;
* V_72 |= V_370 ;
break;
}
} else {
if ( F_35 ( V_7 ) )
* V_72 &= ~ V_371 ;
else
* V_72 &= ~ V_372 ;
switch ( V_354 & V_359 ) {
case V_360 :
* V_72 |= V_300 ;
break;
case V_362 :
* V_72 |= V_78 ;
break;
case V_364 :
* V_72 |= V_373 ;
break;
case V_366 :
if ( F_35 ( V_7 ) ) {
* V_72 |= V_374 ;
} else {
F_79 ( L_61 ) ;
* V_72 |= V_373 ;
}
break;
}
}
}
static void F_212 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_210 ( V_1 , & V_1 -> V_72 ,
V_362 ) ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_1 -> V_72 |= V_74 ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
static void F_213 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_253 = F_134 ( V_65 -> V_4 . V_253 ) ;
T_2 V_375 = F_22 ( V_1 -> V_73 ) ;
unsigned int V_376 = 0x0 ;
if ( F_44 ( V_375 & V_74 ) )
return;
F_23 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_214 ( V_1 ) ;
F_212 ( V_1 ) ;
F_95 ( V_1 ) ;
F_167 ( V_1 ) ;
F_101 ( V_1 , true ) ;
F_27 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_215 ( V_51 , F_2 ( V_1 ) ,
V_376 ) ;
F_182 ( V_1 , V_335 ) ;
F_216 ( V_1 ) ;
F_217 ( V_1 ) ;
F_218 ( V_1 ) ;
if ( V_253 -> V_286 -> V_265 ) {
F_219 ( L_62 ,
F_31 ( V_253 -> V_69 ) ) ;
F_220 ( V_65 ) ;
}
}
static void F_221 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_213 ( V_65 ) ;
F_173 ( V_1 ) ;
}
static void F_222 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_173 ( V_1 ) ;
F_223 ( V_1 ) ;
}
static void F_224 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
F_144 ( V_65 ) ;
if ( V_346 -> V_18 == V_19 ) {
F_142 ( V_1 ) ;
F_179 ( V_1 ) ;
}
}
static void F_225 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = V_3 -> V_4 . V_4 . V_7 -> V_52 ;
enum V_69 V_69 = V_1 -> V_70 ;
int V_377 = F_56 ( V_69 ) ;
F_161 ( V_1 ) ;
F_33 ( L_63 ,
F_31 ( V_69 ) , F_32 ( V_3 -> V_18 ) ) ;
F_39 ( V_377 , 0 ) ;
F_40 ( V_377 ) ;
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
F_33 ( L_64 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_8 ( V_65 -> V_4 . V_253 ,
L_65 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_225 ( V_1 ) ;
}
}
static void F_214 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_65 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_253 = F_134 ( V_65 -> V_4 . V_253 ) ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_70 == V_253 -> V_69 )
return;
if ( V_1 -> V_70 != V_87 )
F_225 ( V_1 ) ;
F_47 ( V_7 , V_253 -> V_69 ) ;
V_1 -> V_70 = V_253 -> V_69 ;
F_33 ( L_66 ,
F_31 ( V_1 -> V_70 ) , F_32 ( V_3 -> V_18 ) ) ;
F_48 ( V_7 , V_1 ) ;
F_49 ( V_7 , V_1 ) ;
}
static void F_226 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_252 = F_134 ( V_65 -> V_4 . V_253 ) ;
enum V_347 V_18 = F_203 ( V_346 ) ;
int V_69 = V_252 -> V_69 ;
T_5 V_349 ;
F_26 ( & V_51 -> V_350 ) ;
V_349 = F_204 ( V_51 , V_69 , F_227 ( V_18 ) ) ;
V_349 = 0 ;
if ( V_69 )
V_349 |= ( 1 << 21 ) ;
else
V_349 &= ~ ( 1 << 21 ) ;
V_349 |= 0x001000c4 ;
F_206 ( V_51 , V_69 , F_228 ( V_18 ) , V_349 ) ;
F_206 ( V_51 , V_69 , F_229 ( V_18 ) , 0x00760018 ) ;
F_206 ( V_51 , V_69 , F_230 ( V_18 ) , 0x00400888 ) ;
F_28 ( & V_51 -> V_350 ) ;
F_213 ( V_65 ) ;
}
static void F_231 ( struct V_64 * V_65 )
{
struct V_2 * V_346 = F_232 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_252 =
F_134 ( V_65 -> V_4 . V_253 ) ;
enum V_347 V_18 = F_203 ( V_346 ) ;
int V_69 = V_252 -> V_69 ;
F_144 ( V_65 ) ;
F_26 ( & V_51 -> V_350 ) ;
F_206 ( V_51 , V_69 , F_233 ( V_18 ) ,
V_352 |
V_353 ) ;
F_206 ( V_51 , V_69 , F_234 ( V_18 ) ,
V_378 |
V_379 |
( 1 << V_380 ) |
V_381 ) ;
F_206 ( V_51 , V_69 , F_235 ( V_18 ) , 0x00750f00 ) ;
F_206 ( V_51 , V_69 , F_236 ( V_18 ) , 0x00001500 ) ;
F_206 ( V_51 , V_69 , F_237 ( V_18 ) , 0x40400000 ) ;
F_28 ( & V_51 -> V_350 ) ;
}
static void F_238 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_252 =
F_134 ( V_65 -> V_4 . V_253 ) ;
enum V_347 V_348 = F_203 ( V_346 ) ;
int V_69 = V_252 -> V_69 ;
int V_382 , V_46 , V_383 ;
T_5 V_349 ;
F_26 ( & V_51 -> V_350 ) ;
V_349 = F_204 ( V_51 , V_69 , F_239 ( V_348 ) ) ;
V_349 &= ~ V_384 ;
F_206 ( V_51 , V_69 , F_239 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_240 ( V_348 ) ) ;
V_349 &= ~ V_384 ;
F_206 ( V_51 , V_69 , F_240 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_205 ( V_348 ) ) ;
V_349 |= V_351 ;
F_206 ( V_51 , V_69 , F_205 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_207 ( V_348 ) ) ;
V_349 |= V_351 ;
F_206 ( V_51 , V_69 , F_207 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_208 ( V_348 ) ) ;
V_349 |= ( V_352 | V_353 ) ;
F_206 ( V_51 , V_69 , F_208 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_209 ( V_348 ) ) ;
V_349 |= ( V_352 | V_353 ) ;
F_206 ( V_51 , V_69 , F_209 ( V_348 ) , V_349 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_382 = ( V_46 == 1 ) ? 0x0 : 0x1 ;
F_206 ( V_51 , V_69 , F_241 ( V_348 , V_46 ) ,
V_382 << V_385 ) ;
}
if ( V_252 -> V_286 -> V_210 > 270000 )
V_383 = 0x18 ;
else if ( V_252 -> V_286 -> V_210 > 135000 )
V_383 = 0xd ;
else if ( V_252 -> V_286 -> V_210 > 67500 )
V_383 = 0x7 ;
else if ( V_252 -> V_286 -> V_210 > 33750 )
V_383 = 0x4 ;
else
V_383 = 0x2 ;
V_349 = F_204 ( V_51 , V_69 , F_239 ( V_348 ) ) ;
V_349 |= F_242 ( 0x1f ) ;
F_206 ( V_51 , V_69 , F_239 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_240 ( V_348 ) ) ;
V_349 |= F_242 ( 0x1f ) ;
F_206 ( V_51 , V_69 , F_240 ( V_348 ) , V_349 ) ;
F_206 ( V_51 , V_69 , F_243 ( V_348 ) ,
F_244 ( V_383 ) |
V_386 |
F_245 ( 0x1f ) |
F_246 ( 6 ) |
F_247 ( 0 ) ) ;
F_206 ( V_51 , V_69 , F_248 ( V_348 ) ,
F_244 ( V_383 ) |
V_386 |
F_245 ( 0x1f ) |
F_246 ( 7 ) |
F_247 ( 5 ) ) ;
F_28 ( & V_51 -> V_350 ) ;
F_213 ( V_65 ) ;
}
static void F_249 ( struct V_64 * V_65 )
{
struct V_2 * V_346 = F_232 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_252 * V_252 =
F_134 ( V_65 -> V_4 . V_253 ) ;
enum V_347 V_348 = F_203 ( V_346 ) ;
enum V_69 V_69 = V_252 -> V_69 ;
T_5 V_349 ;
F_144 ( V_65 ) ;
F_26 ( & V_51 -> V_350 ) ;
if ( V_69 != V_79 ) {
V_349 = F_204 ( V_51 , V_69 , V_387 ) ;
V_349 &= ~ ( V_388 | V_389 ) ;
if ( V_348 == V_390 )
V_349 |= V_391 ;
if ( V_348 == V_392 )
V_349 |= V_393 ;
F_206 ( V_51 , V_69 , V_387 , V_349 ) ;
} else {
V_349 = F_204 ( V_51 , V_69 , V_394 ) ;
V_349 &= ~ ( V_395 | V_396 ) ;
if ( V_348 == V_390 )
V_349 |= V_397 ;
if ( V_348 == V_392 )
V_349 |= V_398 ;
F_206 ( V_51 , V_69 , V_394 , V_349 ) ;
}
V_349 = F_204 ( V_51 , V_69 , F_227 ( V_348 ) ) ;
V_349 |= V_399 ;
if ( V_69 != V_79 )
V_349 &= ~ V_400 ;
else
V_349 |= V_400 ;
F_206 ( V_51 , V_69 , F_227 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_250 ( V_348 ) ) ;
V_349 |= V_399 ;
if ( V_69 != V_79 )
V_349 &= ~ V_400 ;
else
V_349 |= V_400 ;
F_206 ( V_51 , V_69 , F_250 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_251 ( V_348 ) ) ;
if ( V_69 != V_79 )
V_349 &= ~ V_401 ;
else
V_349 |= V_401 ;
F_206 ( V_51 , V_69 , F_251 ( V_348 ) , V_349 ) ;
F_28 ( & V_51 -> V_350 ) ;
}
static T_6
F_252 ( struct V_155 * V_156 , unsigned int V_402 ,
void * V_171 , T_7 V_165 )
{
T_6 V_139 ;
int V_46 ;
F_253 ( V_156 , V_334 , V_171 , 1 ) ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_139 = F_253 ( V_156 , V_402 , V_171 , V_165 ) ;
if ( V_139 == V_165 )
return V_139 ;
F_70 ( 1 ) ;
}
return V_139 ;
}
static bool
F_254 ( struct V_1 * V_1 , T_3 V_403 [ V_404 ] )
{
return F_252 ( & V_1 -> V_156 ,
V_405 ,
V_403 ,
V_404 ) == V_404 ;
}
static T_3
F_255 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_61 ( V_7 ) )
return V_406 ;
else if ( F_122 ( V_7 ) -> V_224 >= 9 ) {
if ( V_51 -> V_407 && V_18 == V_19 )
return V_406 ;
return V_408 ;
} else if ( F_21 ( V_7 ) )
return V_406 ;
else if ( F_145 ( V_7 ) && V_18 == V_19 )
return V_408 ;
else if ( F_147 ( V_7 ) && V_18 != V_19 )
return V_406 ;
else
return V_408 ;
}
static T_3
F_256 ( struct V_1 * V_1 , T_3 V_409 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_122 ( V_7 ) -> V_224 >= 9 ) {
switch ( V_409 & V_410 ) {
case V_411 :
return V_412 ;
case V_413 :
return V_414 ;
case V_408 :
return V_415 ;
case V_406 :
return V_416 ;
default:
return V_416 ;
}
} else if ( F_107 ( V_7 ) || F_90 ( V_7 ) ) {
switch ( V_409 & V_410 ) {
case V_411 :
return V_412 ;
case V_413 :
return V_414 ;
case V_408 :
return V_415 ;
case V_406 :
default:
return V_416 ;
}
} else if ( F_21 ( V_7 ) ) {
switch ( V_409 & V_410 ) {
case V_411 :
return V_412 ;
case V_413 :
return V_414 ;
case V_408 :
return V_415 ;
case V_406 :
default:
return V_416 ;
}
} else if ( F_145 ( V_7 ) && V_18 == V_19 ) {
switch ( V_409 & V_410 ) {
case V_411 :
return V_414 ;
case V_413 :
case V_408 :
return V_415 ;
default:
return V_416 ;
}
} else {
switch ( V_409 & V_410 ) {
case V_411 :
return V_414 ;
case V_413 :
return V_414 ;
case V_408 :
return V_415 ;
case V_406 :
default:
return V_416 ;
}
}
}
static T_2 F_257 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
struct V_252 * V_252 =
F_134 ( V_346 -> V_4 . V_4 . V_253 ) ;
unsigned long V_417 , V_418 ,
V_419 ;
T_3 V_420 = V_1 -> V_420 [ 0 ] ;
enum V_347 V_18 = F_203 ( V_346 ) ;
int V_69 = V_252 -> V_69 ;
switch ( V_420 & V_421 ) {
case V_416 :
V_418 = 0x0004000 ;
switch ( V_420 & V_410 ) {
case V_411 :
V_417 = 0x2B405555 ;
V_419 = 0x552AB83A ;
break;
case V_413 :
V_417 = 0x2B404040 ;
V_419 = 0x5548B83A ;
break;
case V_408 :
V_417 = 0x2B245555 ;
V_419 = 0x5560B83A ;
break;
case V_406 :
V_417 = 0x2B405555 ;
V_419 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_415 :
V_418 = 0x0002000 ;
switch ( V_420 & V_410 ) {
case V_411 :
V_417 = 0x2B404040 ;
V_419 = 0x5552B83A ;
break;
case V_413 :
V_417 = 0x2B404848 ;
V_419 = 0x5580B83A ;
break;
case V_408 :
V_417 = 0x2B404040 ;
V_419 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_414 :
V_418 = 0x0000000 ;
switch ( V_420 & V_410 ) {
case V_411 :
V_417 = 0x2B305555 ;
V_419 = 0x5570B83A ;
break;
case V_413 :
V_417 = 0x2B2B4040 ;
V_419 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_412 :
V_418 = 0x0006000 ;
switch ( V_420 & V_410 ) {
case V_411 :
V_417 = 0x1B405555 ;
V_419 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_350 ) ;
F_206 ( V_51 , V_69 , F_258 ( V_18 ) , 0x00000000 ) ;
F_206 ( V_51 , V_69 , F_259 ( V_18 ) , V_417 ) ;
F_206 ( V_51 , V_69 , F_260 ( V_18 ) ,
V_419 ) ;
F_206 ( V_51 , V_69 , F_261 ( V_18 ) , 0x0C782040 ) ;
F_206 ( V_51 , V_69 , F_262 ( V_18 ) , 0x00030000 ) ;
F_206 ( V_51 , V_69 , F_263 ( V_18 ) , V_418 ) ;
F_206 ( V_51 , V_69 , F_258 ( V_18 ) , 0x80000000 ) ;
F_28 ( & V_51 -> V_350 ) ;
return 0 ;
}
static T_2 F_264 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_346 = F_2 ( V_1 ) ;
struct V_252 * V_252 = F_134 ( V_346 -> V_4 . V_4 . V_253 ) ;
T_5 V_422 , V_423 , V_349 ;
T_3 V_420 = V_1 -> V_420 [ 0 ] ;
enum V_347 V_348 = F_203 ( V_346 ) ;
enum V_69 V_69 = V_252 -> V_69 ;
int V_46 ;
switch ( V_420 & V_421 ) {
case V_416 :
switch ( V_420 & V_410 ) {
case V_411 :
V_422 = 128 ;
V_423 = 52 ;
break;
case V_413 :
V_422 = 128 ;
V_423 = 77 ;
break;
case V_408 :
V_422 = 128 ;
V_423 = 102 ;
break;
case V_406 :
V_422 = 128 ;
V_423 = 154 ;
break;
default:
return 0 ;
}
break;
case V_415 :
switch ( V_420 & V_410 ) {
case V_411 :
V_422 = 85 ;
V_423 = 78 ;
break;
case V_413 :
V_422 = 85 ;
V_423 = 116 ;
break;
case V_408 :
V_422 = 85 ;
V_423 = 154 ;
break;
default:
return 0 ;
}
break;
case V_414 :
switch ( V_420 & V_410 ) {
case V_411 :
V_422 = 64 ;
V_423 = 104 ;
break;
case V_413 :
V_422 = 64 ;
V_423 = 154 ;
break;
default:
return 0 ;
}
break;
case V_412 :
switch ( V_420 & V_410 ) {
case V_411 :
V_422 = 43 ;
V_423 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_350 ) ;
V_349 = F_204 ( V_51 , V_69 , F_265 ( V_348 ) ) ;
V_349 &= ~ ( V_424 | V_425 ) ;
V_349 &= ~ ( V_426 | V_427 ) ;
V_349 |= V_428 | V_429 ;
F_206 ( V_51 , V_69 , F_265 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_266 ( V_348 ) ) ;
V_349 &= ~ ( V_424 | V_425 ) ;
V_349 &= ~ ( V_426 | V_427 ) ;
V_349 |= V_428 | V_429 ;
F_206 ( V_51 , V_69 , F_266 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_267 ( V_348 ) ) ;
V_349 &= ~ ( V_430 | V_431 ) ;
V_349 |= V_432 | V_433 ;
F_206 ( V_51 , V_69 , F_267 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_268 ( V_348 ) ) ;
V_349 &= ~ ( V_430 | V_431 ) ;
V_349 |= V_432 | V_433 ;
F_206 ( V_51 , V_69 , F_268 ( V_348 ) , V_349 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_349 = F_204 ( V_51 , V_69 , F_269 ( V_348 , V_46 ) ) ;
V_349 &= ~ V_434 ;
V_349 |= V_422 << V_435 ;
F_206 ( V_51 , V_69 , F_269 ( V_348 , V_46 ) , V_349 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_349 = F_204 ( V_51 , V_69 , F_270 ( V_348 , V_46 ) ) ;
V_349 &= ~ V_436 ;
V_349 |= V_423 << V_437 ;
F_206 ( V_51 , V_69 , F_270 ( V_348 , V_46 ) , V_349 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_349 = F_204 ( V_51 , V_69 , F_271 ( V_348 , V_46 ) ) ;
V_349 &= ~ V_438 ;
F_206 ( V_51 , V_69 , F_271 ( V_348 , V_46 ) , V_349 ) ;
}
if ( ( ( V_420 & V_421 )
== V_416 ) &&
( ( V_420 & V_410 )
== V_406 ) ) {
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_349 = F_204 ( V_51 , V_69 , F_271 ( V_348 , V_46 ) ) ;
V_349 |= V_438 ;
F_206 ( V_51 , V_69 , F_271 ( V_348 , V_46 ) , V_349 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_349 = F_204 ( V_51 , V_69 , F_270 ( V_348 , V_46 ) ) ;
V_349 &= ~ ( 0xff << V_439 ) ;
V_349 |= ( 0x9a << V_439 ) ;
F_206 ( V_51 , V_69 , F_270 ( V_348 , V_46 ) , V_349 ) ;
}
}
V_349 = F_204 ( V_51 , V_69 , F_265 ( V_348 ) ) ;
V_349 |= V_424 | V_425 ;
F_206 ( V_51 , V_69 , F_265 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , F_266 ( V_348 ) ) ;
V_349 |= V_424 | V_425 ;
F_206 ( V_51 , V_69 , F_266 ( V_348 ) , V_349 ) ;
V_349 = F_204 ( V_51 , V_69 , V_440 ) ;
V_349 |= V_441 ;
F_206 ( V_51 , V_69 , V_440 , V_349 ) ;
F_28 ( & V_51 -> V_350 ) ;
return 0 ;
}
static void
F_272 ( struct V_1 * V_1 ,
const T_3 V_403 [ V_404 ] )
{
T_3 V_47 = 0 ;
T_3 V_339 = 0 ;
int V_442 ;
T_3 V_443 ;
T_3 V_444 ;
for ( V_442 = 0 ; V_442 < V_1 -> V_255 ; V_442 ++ ) {
T_3 V_445 = F_273 ( V_403 , V_442 ) ;
T_3 V_446 = F_274 ( V_403 , V_442 ) ;
if ( V_445 > V_47 )
V_47 = V_445 ;
if ( V_446 > V_339 )
V_339 = V_446 ;
}
V_443 = F_255 ( V_1 ) ;
if ( V_47 >= V_443 )
V_47 = V_443 | V_447 ;
V_444 = F_256 ( V_1 , V_47 ) ;
if ( V_339 >= V_444 )
V_339 = V_444 | V_448 ;
for ( V_442 = 0 ; V_442 < 4 ; V_442 ++ )
V_1 -> V_420 [ V_442 ] = V_47 | V_339 ;
}
static T_2
F_275 ( T_3 V_420 )
{
T_2 V_449 = 0 ;
switch ( V_420 & V_410 ) {
case V_411 :
default:
V_449 |= V_76 ;
break;
case V_413 :
V_449 |= V_450 ;
break;
case V_408 :
V_449 |= V_451 ;
break;
case V_406 :
V_449 |= V_452 ;
break;
}
switch ( V_420 & V_421 ) {
case V_416 :
default:
V_449 |= V_77 ;
break;
case V_415 :
V_449 |= V_453 ;
break;
case V_414 :
V_449 |= V_454 ;
break;
case V_412 :
V_449 |= V_455 ;
break;
}
return V_449 ;
}
static T_2
F_276 ( T_3 V_420 )
{
int V_449 = V_420 & ( V_410 |
V_421 ) ;
switch ( V_449 ) {
case V_411 | V_416 :
case V_413 | V_416 :
return V_456 ;
case V_411 | V_415 :
return V_457 ;
case V_411 | V_414 :
case V_413 | V_414 :
return V_458 ;
case V_413 | V_415 :
case V_408 | V_415 :
return V_459 ;
case V_408 | V_416 :
case V_406 | V_416 :
return V_460 ;
default:
F_33 ( L_67
L_68 , V_449 ) ;
return V_456 ;
}
}
static T_2
F_277 ( T_3 V_420 )
{
int V_449 = V_420 & ( V_410 |
V_421 ) ;
switch ( V_449 ) {
case V_411 | V_416 :
return V_461 ;
case V_411 | V_415 :
return V_462 ;
case V_411 | V_414 :
return V_463 ;
case V_413 | V_416 :
return V_464 ;
case V_413 | V_415 :
return V_465 ;
case V_408 | V_416 :
return V_466 ;
case V_408 | V_415 :
return V_467 ;
default:
F_33 ( L_67
L_68 , V_449 ) ;
return V_468 ;
}
}
static void
F_278 ( struct V_1 * V_1 , T_2 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_449 , V_301 = 0 ;
T_3 V_420 = V_1 -> V_420 [ 0 ] ;
if ( F_10 ( V_7 ) ) {
V_449 = F_279 ( V_1 ) ;
if ( F_61 ( V_7 ) )
V_449 = 0 ;
else
V_301 = V_469 ;
} else if ( F_35 ( V_7 ) ) {
V_449 = F_264 ( V_1 ) ;
} else if ( F_21 ( V_7 ) ) {
V_449 = F_257 ( V_1 ) ;
} else if ( F_145 ( V_7 ) && V_18 == V_19 ) {
V_449 = F_277 ( V_420 ) ;
V_301 = V_470 ;
} else if ( F_89 ( V_7 ) && V_18 == V_19 ) {
V_449 = F_276 ( V_420 ) ;
V_301 = V_471 ;
} else {
V_449 = F_275 ( V_420 ) ;
V_301 = V_472 | V_473 ;
}
if ( V_301 )
F_33 ( L_69 , V_449 ) ;
F_33 ( L_70 ,
V_420 & V_410 ) ;
F_33 ( L_71 ,
( V_420 & V_421 ) >>
V_474 ) ;
* V_72 = ( * V_72 & ~ V_301 ) | V_449 ;
}
static bool
F_280 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_354 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_475 [ sizeof( V_1 -> V_420 ) + 1 ] ;
int V_139 , V_241 ;
F_210 ( V_1 , V_72 , V_354 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_475 [ 0 ] = V_354 ;
if ( ( V_354 & V_359 ) ==
V_360 ) {
V_241 = 1 ;
} else {
memcpy ( V_475 + 1 , V_1 -> V_420 , V_1 -> V_255 ) ;
V_241 = V_1 -> V_255 + 1 ;
}
V_139 = F_281 ( & V_1 -> V_156 , V_476 ,
V_475 , V_241 ) ;
return V_139 == V_241 ;
}
static bool
F_282 ( struct V_1 * V_1 , T_2 * V_72 ,
T_3 V_354 )
{
if ( ! V_1 -> V_477 )
memset ( V_1 -> V_420 , 0 , sizeof( V_1 -> V_420 ) ) ;
F_278 ( V_1 , V_72 ) ;
return F_280 ( V_1 , V_72 , V_354 ) ;
}
static bool
F_283 ( struct V_1 * V_1 , T_2 * V_72 ,
const T_3 V_403 [ V_404 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
int V_139 ;
F_272 ( V_1 , V_403 ) ;
F_278 ( V_1 , V_72 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_139 = F_281 ( & V_1 -> V_156 , V_478 ,
V_1 -> V_420 , V_1 -> V_255 ) ;
return V_139 == V_1 -> V_255 ;
}
static void F_284 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
T_2 V_349 ;
if ( ! F_10 ( V_7 ) )
return;
V_349 = F_22 ( F_211 ( V_18 ) ) ;
V_349 &= ~ V_358 ;
V_349 |= V_479 ;
F_39 ( F_211 ( V_18 ) , V_349 ) ;
if ( V_18 == V_19 )
return;
if ( F_285 ( ( F_22 ( F_286 ( V_18 ) ) & V_480 ) ,
1 ) )
F_79 ( L_72 ) ;
}
void
F_216 ( struct V_1 * V_1 )
{
struct V_481 * V_65 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_65 -> V_7 ;
int V_46 ;
T_3 V_482 ;
int V_483 , V_484 ;
T_2 V_72 = V_1 -> V_72 ;
T_3 V_485 [ 2 ] ;
if ( F_10 ( V_7 ) )
F_287 ( V_65 ) ;
V_485 [ 0 ] = V_1 -> V_277 ;
V_485 [ 1 ] = V_1 -> V_255 ;
if ( F_146 ( V_1 -> V_11 ) )
V_485 [ 1 ] |= V_486 ;
F_281 ( & V_1 -> V_156 , V_487 , V_485 , 2 ) ;
if ( V_1 -> V_221 )
F_281 ( & V_1 -> V_156 , V_488 ,
& V_1 -> V_278 , 1 ) ;
V_485 [ 0 ] = 0 ;
V_485 [ 1 ] = V_489 ;
F_281 ( & V_1 -> V_156 , V_490 , V_485 , 2 ) ;
V_72 |= V_74 ;
if ( ! F_282 ( V_1 , & V_72 ,
V_362 |
V_356 ) ) {
F_79 ( L_73 ) ;
return;
}
V_482 = 0xff ;
V_483 = 0 ;
V_484 = 0 ;
for (; ; ) {
T_3 V_403 [ V_404 ] ;
F_288 ( V_1 -> V_11 ) ;
if ( ! F_254 ( V_1 , V_403 ) ) {
F_79 ( L_74 ) ;
break;
}
if ( F_289 ( V_403 , V_1 -> V_255 ) ) {
F_33 ( L_75 ) ;
break;
}
if ( V_1 -> V_477 ) {
F_33 ( L_76 ) ;
V_1 -> V_477 = false ;
if ( ! F_282 ( V_1 , & V_72 ,
V_362 |
V_356 ) ) {
F_79 ( L_73 ) ;
return;
}
continue;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_255 ; V_46 ++ )
if ( ( V_1 -> V_420 [ V_46 ] & V_447 ) == 0 )
break;
if ( V_46 == V_1 -> V_255 ) {
++ V_484 ;
if ( V_484 == 5 ) {
F_79 ( L_77 ) ;
break;
}
F_282 ( V_1 , & V_72 ,
V_362 |
V_356 ) ;
V_483 = 0 ;
continue;
}
if ( ( V_1 -> V_420 [ 0 ] & V_410 ) == V_482 ) {
++ V_483 ;
if ( V_483 == 5 ) {
F_79 ( L_78 ) ;
break;
}
} else
V_483 = 0 ;
V_482 = V_1 -> V_420 [ 0 ] & V_410 ;
if ( ! F_283 ( V_1 , & V_72 , V_403 ) ) {
F_79 ( L_79 ) ;
break;
}
}
V_1 -> V_72 = V_72 ;
}
void
F_217 ( struct V_1 * V_1 )
{
bool V_491 = false ;
int V_492 , V_493 ;
T_2 V_72 = V_1 -> V_72 ;
T_2 V_494 = V_364 ;
if ( V_1 -> V_277 == V_15 || V_1 -> V_495 )
V_494 = V_366 ;
if ( ! F_280 ( V_1 , & V_72 ,
V_494 |
V_356 ) ) {
F_79 ( L_80 ) ;
return;
}
V_492 = 0 ;
V_493 = 0 ;
V_491 = false ;
for (; ; ) {
T_3 V_403 [ V_404 ] ;
if ( V_493 > 5 ) {
F_79 ( L_81 ) ;
break;
}
F_290 ( V_1 -> V_11 ) ;
if ( ! F_254 ( V_1 , V_403 ) ) {
F_79 ( L_74 ) ;
break;
}
if ( ! F_289 ( V_403 , V_1 -> V_255 ) ) {
V_1 -> V_477 = false ;
F_216 ( V_1 ) ;
F_280 ( V_1 , & V_72 ,
V_494 |
V_356 ) ;
V_493 ++ ;
continue;
}
if ( F_291 ( V_403 , V_1 -> V_255 ) ) {
V_491 = true ;
break;
}
if ( V_492 > 5 ) {
V_1 -> V_477 = false ;
F_216 ( V_1 ) ;
F_280 ( V_1 , & V_72 ,
V_494 |
V_356 ) ;
V_492 = 0 ;
V_493 ++ ;
continue;
}
if ( ! F_283 ( V_1 , & V_72 , V_403 ) ) {
F_79 ( L_79 ) ;
break;
}
++ V_492 ;
}
F_284 ( V_1 ) ;
V_1 -> V_72 = V_72 ;
if ( V_491 ) {
V_1 -> V_477 = true ;
F_33 ( L_82 ) ;
}
}
void F_218 ( struct V_1 * V_1 )
{
F_280 ( V_1 , & V_1 -> V_72 ,
V_360 ) ;
}
static void
F_199 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_252 * V_253 = F_134 ( V_3 -> V_4 . V_4 . V_253 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_72 = V_1 -> V_72 ;
if ( F_44 ( F_10 ( V_7 ) ) )
return;
if ( F_44 ( ( F_22 ( V_1 -> V_73 ) & V_74 ) == 0 ) )
return;
F_33 ( L_51 ) ;
if ( ( F_145 ( V_7 ) && V_18 == V_19 ) ||
( F_147 ( V_7 ) && V_18 != V_19 ) ) {
V_72 &= ~ V_368 ;
V_72 |= V_496 ;
} else {
if ( F_35 ( V_7 ) )
V_72 &= ~ V_371 ;
else
V_72 &= ~ V_372 ;
V_72 |= V_497 ;
}
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_72 &= ~ ( V_74 | V_291 ) ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
if ( F_292 ( V_7 ) && V_253 -> V_69 == V_79 && V_18 != V_19 ) {
V_72 &= ~ ( V_80 | V_372 ) ;
V_72 |= V_74 | V_78 ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_72 &= ~ V_74 ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
F_70 ( V_1 -> V_498 ) ;
}
static bool
F_293 ( struct V_1 * V_1 )
{
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_284 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_499 ;
if ( F_252 ( & V_1 -> V_156 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_33 ( L_83 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_334 ] == 0 )
return false ;
memset ( V_1 -> V_500 , 0 , sizeof( V_1 -> V_500 ) ) ;
if ( F_1 ( V_1 ) ) {
F_252 ( & V_1 -> V_156 , V_501 ,
V_1 -> V_500 ,
sizeof( V_1 -> V_500 ) ) ;
if ( V_1 -> V_500 [ 0 ] & V_502 ) {
V_51 -> V_503 . V_504 = true ;
F_33 ( L_84 ) ;
}
if ( F_122 ( V_7 ) -> V_224 >= 9 &&
( V_1 -> V_500 [ 0 ] & V_505 ) ) {
T_3 V_506 ;
V_51 -> V_503 . V_504 = true ;
F_252 ( & V_1 -> V_156 ,
V_507 ,
& V_506 , 1 ) ;
V_51 -> V_503 . V_508 = V_506 ? true : false ;
V_51 -> V_503 . V_509 = V_51 -> V_503 . V_508 ;
F_33 ( L_85 ,
V_51 -> V_503 . V_509 ? L_86 : L_87 ) ;
}
}
if ( V_1 -> V_11 [ V_334 ] >= 0x12 &&
V_1 -> V_11 [ V_510 ] & V_511 &&
F_119 ( V_7 ) ) {
V_1 -> V_495 = true ;
F_33 ( L_88 ) ;
} else
V_1 -> V_495 = false ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_11 [ V_512 ] & V_513 ) &&
( F_252 ( & V_1 -> V_156 , V_514 , & V_499 , 1 ) == 1 ) &&
( V_499 >= 0x03 ) ) {
T_8 V_220 [ V_239 ] ;
int V_46 ;
F_252 ( & V_1 -> V_156 ,
V_515 ,
V_220 ,
sizeof( V_220 ) ) ;
for ( V_46 = 0 ; V_46 < F_124 ( V_220 ) ; V_46 ++ ) {
int V_349 = F_294 ( V_220 [ V_46 ] ) ;
if ( V_349 == 0 )
break;
V_1 -> V_220 [ V_46 ] = ( V_349 * 200 ) / 10 ;
}
V_1 -> V_221 = V_46 ;
}
F_130 ( V_1 ) ;
if ( ! ( V_1 -> V_11 [ V_516 ] &
V_517 ) )
return true ;
if ( V_1 -> V_11 [ V_334 ] == 0x10 )
return true ;
if ( F_252 ( & V_1 -> V_156 , V_518 ,
V_1 -> V_519 ,
V_520 ) < 0 )
return false ;
return true ;
}
static void
F_295 ( struct V_1 * V_1 )
{
T_1 V_475 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_521 ] & V_522 ) )
return;
if ( F_252 ( & V_1 -> V_156 , V_523 , V_475 , 3 ) == 3 )
F_33 ( L_89 ,
V_475 [ 0 ] , V_475 [ 1 ] , V_475 [ 2 ] ) ;
if ( F_252 ( & V_1 -> V_156 , V_524 , V_475 , 3 ) == 3 )
F_33 ( L_90 ,
V_475 [ 0 ] , V_475 [ 1 ] , V_475 [ 2 ] ) ;
}
static bool
F_296 ( struct V_1 * V_1 )
{
T_1 V_475 [ 1 ] ;
if ( ! V_1 -> V_525 )
return false ;
if ( V_1 -> V_11 [ V_334 ] < 0x12 )
return false ;
if ( F_252 ( & V_1 -> V_156 , V_526 , V_475 , 1 ) ) {
if ( V_475 [ 0 ] & V_527 ) {
F_33 ( L_91 ) ;
V_1 -> V_528 = true ;
} else {
F_33 ( L_92 ) ;
V_1 -> V_528 = false ;
}
}
F_297 ( & V_1 -> V_529 , V_1 -> V_528 ) ;
return V_1 -> V_528 ;
}
static void F_298 ( struct V_1 * V_1 )
{
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_252 * V_252 = F_134 ( V_284 -> V_4 . V_4 . V_253 ) ;
T_1 V_475 ;
if ( F_299 ( & V_1 -> V_156 , V_530 , & V_475 ) < 0 ) {
F_33 ( L_93 ) ;
return;
}
if ( F_183 ( & V_1 -> V_156 , V_530 ,
V_475 & ~ V_531 ) < 0 )
F_33 ( L_93 ) ;
F_300 ( V_252 ) ;
}
static int F_301 ( struct V_1 * V_1 )
{
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_252 * V_252 = F_134 ( V_284 -> V_4 . V_4 . V_253 ) ;
T_1 V_475 ;
if ( F_299 ( & V_1 -> V_156 , V_532 , & V_475 ) < 0 )
return - V_151 ;
if ( ! ( V_475 & V_533 ) )
return - V_534 ;
if ( F_299 ( & V_1 -> V_156 , V_530 , & V_475 ) < 0 )
return - V_151 ;
F_302 ( V_252 ) ;
if ( F_183 ( & V_1 -> V_156 , V_530 ,
V_475 | V_531 ) < 0 ) {
F_300 ( V_252 ) ;
return - V_151 ;
}
return 0 ;
}
int F_303 ( struct V_1 * V_1 , T_1 * V_535 )
{
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_284 -> V_4 . V_4 . V_7 ;
struct V_252 * V_252 = F_134 ( V_284 -> V_4 . V_4 . V_253 ) ;
T_1 V_475 ;
int V_536 ;
int V_537 = 6 ;
int V_139 ;
V_139 = F_301 ( V_1 ) ;
if ( V_139 )
return V_139 ;
if ( F_299 ( & V_1 -> V_156 , V_532 , & V_475 ) < 0 ) {
V_139 = - V_151 ;
goto V_538;
}
V_536 = V_475 & V_539 ;
do {
if ( F_299 ( & V_1 -> V_156 ,
V_532 , & V_475 ) < 0 ) {
V_139 = - V_151 ;
goto V_538;
}
F_304 ( V_7 , V_252 -> V_69 ) ;
} while ( -- V_537 && ( V_475 & V_539 ) == V_536 );
if ( V_537 == 0 ) {
F_33 ( L_94 ) ;
V_139 = - V_152 ;
goto V_538;
}
if ( F_253 ( & V_1 -> V_156 , V_540 , V_535 , 6 ) < 0 )
V_139 = - V_151 ;
V_538:
F_298 ( V_1 ) ;
return V_139 ;
}
static bool
F_305 ( struct V_1 * V_1 , T_1 * V_541 )
{
return F_252 ( & V_1 -> V_156 ,
V_542 ,
V_541 , 1 ) == 1 ;
}
static bool
F_306 ( struct V_1 * V_1 , T_1 * V_541 )
{
int V_139 ;
V_139 = F_252 ( & V_1 -> V_156 ,
V_543 ,
V_541 , 14 ) ;
if ( V_139 != 14 )
return false ;
return true ;
}
static T_3 F_307 ( struct V_1 * V_1 )
{
T_3 V_544 = V_545 ;
return V_544 ;
}
static T_3 F_308 ( struct V_1 * V_1 )
{
T_3 V_544 = V_546 ;
return V_544 ;
}
static T_3 F_309 ( struct V_1 * V_1 )
{
T_3 V_544 = V_546 ;
struct V_29 * V_29 = V_1 -> V_254 ;
struct V_8 * V_9 = & V_29 -> V_4 ;
if ( V_29 -> V_547 == NULL ||
V_9 -> V_548 ||
V_1 -> V_156 . V_549 > 6 ) {
if ( V_1 -> V_156 . V_550 > 0 ||
V_1 -> V_156 . V_549 > 0 )
F_33 ( L_95 ,
V_1 -> V_156 . V_550 ,
V_1 -> V_156 . V_549 ) ;
V_1 -> V_551 = V_552 ;
} else {
struct V_553 * V_554 = V_29 -> V_547 ;
V_554 += V_29 -> V_547 -> V_555 ;
if ( ! F_281 ( & V_1 -> V_156 ,
V_556 ,
& V_554 -> V_557 ,
1 ) )
F_33 ( L_96 ) ;
V_544 = V_545 | V_558 ;
V_1 -> V_551 = V_559 ;
}
V_1 -> V_560 = 1 ;
return V_544 ;
}
static T_3 F_310 ( struct V_1 * V_1 )
{
T_3 V_544 = V_546 ;
return V_544 ;
}
static void F_311 ( struct V_1 * V_1 )
{
T_3 V_561 = V_546 ;
T_3 V_562 = 0 ;
int V_112 = 0 ;
V_1 -> V_560 = 0 ;
V_1 -> V_563 = 0 ;
V_1 -> V_551 = 0 ;
V_1 -> V_156 . V_550 = 0 ;
V_1 -> V_156 . V_549 = 0 ;
V_112 = F_253 ( & V_1 -> V_156 , V_564 , & V_562 , 1 ) ;
if ( V_112 <= 0 ) {
F_33 ( L_97 ) ;
goto V_565;
}
switch ( V_562 ) {
case V_566 :
F_33 ( L_98 ) ;
V_1 -> V_563 = V_566 ;
V_561 = F_307 ( V_1 ) ;
break;
case V_567 :
F_33 ( L_99 ) ;
V_1 -> V_563 = V_567 ;
V_561 = F_308 ( V_1 ) ;
break;
case V_568 :
F_33 ( L_100 ) ;
V_1 -> V_563 = V_568 ;
V_561 = F_309 ( V_1 ) ;
break;
case V_569 :
F_33 ( L_101 ) ;
V_1 -> V_563 = V_569 ;
V_561 = F_310 ( V_1 ) ;
break;
default:
F_33 ( L_102 , V_562 ) ;
break;
}
V_565:
V_112 = F_281 ( & V_1 -> V_156 ,
V_570 ,
& V_561 , 1 ) ;
if ( V_112 <= 0 )
F_33 ( L_103 ) ;
}
static int
F_312 ( struct V_1 * V_1 )
{
bool V_571 ;
if ( V_1 -> V_528 ) {
T_1 V_572 [ 16 ] = { 0 } ;
int V_139 = 0 ;
int V_573 ;
bool V_574 ;
V_571 = F_306 ( V_1 , V_572 ) ;
V_575:
if ( V_571 == true ) {
if ( V_1 -> V_576 && ! F_291 ( & V_572 [ 10 ] , V_1 -> V_255 ) ) {
F_33 ( L_104 ) ;
F_216 ( V_1 ) ;
F_217 ( V_1 ) ;
F_218 ( V_1 ) ;
}
F_33 ( L_105 , V_572 ) ;
V_139 = F_313 ( & V_1 -> V_529 , V_572 , & V_574 ) ;
if ( V_574 ) {
for ( V_573 = 0 ; V_573 < 3 ; V_573 ++ ) {
int V_577 ;
V_577 = F_281 ( & V_1 -> V_156 ,
V_543 + 1 ,
& V_572 [ 1 ] , 3 ) ;
if ( V_577 == 3 ) {
break;
}
}
V_571 = F_306 ( V_1 , V_572 ) ;
if ( V_571 == true ) {
F_33 ( L_106 , V_572 ) ;
goto V_575;
}
} else
V_139 = 0 ;
return V_139 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_33 ( L_107 ) ;
V_1 -> V_528 = false ;
F_297 ( & V_1 -> V_529 , V_1 -> V_528 ) ;
F_314 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_175 ;
}
static void
F_315 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_541 ;
T_1 V_403 [ V_404 ] ;
F_44 ( ! F_316 ( & V_7 -> V_578 . V_579 ) ) ;
if ( ! V_64 -> V_4 . V_253 )
return;
if ( ! F_134 ( V_64 -> V_4 . V_253 ) -> V_580 )
return;
if ( ! F_254 ( V_1 , V_403 ) ) {
return;
}
if ( ! F_293 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
F_305 ( V_1 , & V_541 ) ) {
F_183 ( & V_1 -> V_156 ,
V_542 ,
V_541 ) ;
if ( V_541 & V_581 )
F_219 ( L_108 ) ;
if ( V_541 & ( V_582 | V_583 ) )
F_219 ( L_109 ) ;
}
if ( ! F_291 ( V_403 , V_1 -> V_255 ) ) {
F_33 ( L_110 ,
V_64 -> V_4 . V_180 ) ;
F_216 ( V_1 ) ;
F_217 ( V_1 ) ;
F_218 ( V_1 ) ;
}
}
static enum V_584
F_317 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_293 ( V_1 ) )
return V_585 ;
if ( ! ( V_11 [ V_516 ] & V_517 ) )
return V_586 ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
V_1 -> V_519 [ 0 ] & V_587 ) {
T_3 V_588 ;
if ( F_252 ( & V_1 -> V_156 , V_589 ,
& V_588 , 1 ) < 0 )
return V_590 ;
return F_318 ( V_588 ) ? V_586
: V_585 ;
}
if ( F_319 ( & V_1 -> V_156 . V_200 ) )
return V_586 ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 ) {
type = V_1 -> V_519 [ 0 ] & V_591 ;
if ( type == V_592 ||
type == V_593 )
return V_590 ;
} else {
type = V_1 -> V_11 [ V_516 ] &
V_594 ;
if ( type == V_595 ||
type == V_596 )
return V_590 ;
}
F_33 ( L_111 ) ;
return V_585 ;
}
static enum V_584
F_320 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_584 V_112 ;
V_112 = F_321 ( V_7 ) ;
if ( V_112 == V_590 )
V_112 = V_586 ;
return V_112 ;
}
static enum V_584
F_322 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_323 ( V_51 , V_3 ) )
return V_585 ;
return F_317 ( V_1 ) ;
}
static int F_324 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_597 ;
if ( F_21 ( V_7 ) ) {
switch ( V_3 -> V_18 ) {
case V_191 :
V_597 = V_598 ;
break;
case V_193 :
V_597 = V_599 ;
break;
case V_195 :
V_597 = V_600 ;
break;
default:
return - V_175 ;
}
} else {
switch ( V_3 -> V_18 ) {
case V_191 :
V_597 = V_601 ;
break;
case V_193 :
V_597 = V_602 ;
break;
case V_195 :
V_597 = V_603 ;
break;
default:
return - V_175 ;
}
}
if ( ( F_22 ( V_604 ) & V_597 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_584
F_325 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_139 ;
if ( F_1 ( V_1 ) ) {
enum V_584 V_112 ;
V_112 = F_321 ( V_7 ) ;
if ( V_112 == V_590 )
V_112 = V_586 ;
return V_112 ;
}
V_139 = F_324 ( V_7 , V_3 ) ;
if ( V_139 == - V_175 )
return V_590 ;
else if ( V_139 == 0 )
return V_585 ;
return F_317 ( V_1 ) ;
}
static struct V_553 *
F_326 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_254 ;
if ( V_29 -> V_553 ) {
if ( F_327 ( V_29 -> V_553 ) )
return NULL ;
return F_328 ( V_29 -> V_553 ) ;
} else
return F_329 ( & V_29 -> V_4 ,
& V_1 -> V_156 . V_200 ) ;
}
static void
F_330 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_254 ;
struct V_553 * V_553 ;
V_553 = F_326 ( V_1 ) ;
V_29 -> V_547 = V_553 ;
if ( V_1 -> V_605 != V_606 )
V_1 -> V_265 = V_1 -> V_605 == V_607 ;
else
V_1 -> V_265 = F_331 ( V_553 ) ;
}
static void
F_332 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_254 ;
F_333 ( V_29 -> V_547 ) ;
V_29 -> V_547 = NULL ;
V_1 -> V_265 = false ;
}
static enum V_66
F_334 ( struct V_1 * V_608 )
{
struct V_64 * V_65 = & F_2 ( V_608 ) -> V_4 ;
enum V_66 V_67 ;
V_67 = F_24 ( V_65 ) ;
F_25 ( F_335 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
return V_67 ;
}
static void
F_336 ( struct V_1 * V_608 ,
enum V_66 V_67 )
{
struct V_64 * V_65 = & F_2 ( V_608 ) -> V_4 ;
F_29 ( F_335 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
}
static enum V_584
F_337 ( struct V_8 * V_9 , bool V_609 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_584 V_112 ;
enum V_66 V_67 ;
bool V_139 ;
T_1 V_541 ;
F_33 ( L_112 ,
V_9 -> V_4 . V_610 , V_9 -> V_180 ) ;
F_332 ( V_1 ) ;
if ( V_1 -> V_528 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_611 ;
return V_585 ;
}
V_67 = F_334 ( V_1 ) ;
if ( F_1 ( V_1 ) )
V_112 = F_320 ( V_1 ) ;
else if ( F_63 ( V_7 ) )
V_112 = F_322 ( V_1 ) ;
else
V_112 = F_325 ( V_1 ) ;
if ( V_112 != V_586 )
goto V_146;
F_295 ( V_1 ) ;
V_139 = F_296 ( V_1 ) ;
if ( V_139 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_611 ;
V_112 = V_585 ;
goto V_146;
}
F_330 ( V_1 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_611 ;
V_112 = V_586 ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
F_305 ( V_1 , & V_541 ) ) {
F_183 ( & V_1 -> V_156 ,
V_542 ,
V_541 ) ;
if ( V_541 & V_581 )
F_311 ( V_1 ) ;
if ( V_541 & ( V_582 | V_583 ) )
F_219 ( L_109 ) ;
}
V_146:
F_336 ( V_1 , V_67 ) ;
return V_112 ;
}
static void
F_338 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
enum V_66 V_67 ;
F_33 ( L_112 ,
V_9 -> V_4 . V_610 , V_9 -> V_180 ) ;
F_332 ( V_1 ) ;
if ( V_9 -> V_112 != V_586 )
return;
V_67 = F_334 ( V_1 ) ;
F_330 ( V_1 ) ;
F_336 ( V_1 , V_67 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_611 ;
}
static int F_339 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_553 * V_553 ;
V_553 = V_29 -> V_547 ;
if ( V_553 ) {
int V_139 = F_340 ( V_9 , V_553 ) ;
if ( V_139 )
return V_139 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_29 -> V_31 . V_30 ) {
struct V_27 * V_28 ;
V_28 = F_341 ( V_9 -> V_7 ,
V_29 -> V_31 . V_30 ) ;
if ( V_28 ) {
F_342 ( V_9 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_343 ( struct V_8 * V_9 )
{
bool V_265 = false ;
struct V_553 * V_553 ;
V_553 = F_16 ( V_9 ) -> V_547 ;
if ( V_553 )
V_265 = F_331 ( V_553 ) ;
return V_265 ;
}
static int
F_344 ( struct V_8 * V_9 ,
struct V_612 * V_613 ,
T_9 V_349 )
{
struct V_50 * V_51 = V_9 -> V_7 -> V_52 ;
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_64 * V_64 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
int V_139 ;
V_139 = F_345 ( & V_9 -> V_4 , V_613 , V_349 ) ;
if ( V_139 )
return V_139 ;
if ( V_613 == V_51 -> V_614 ) {
int V_46 = V_349 ;
bool V_265 ;
if ( V_46 == V_1 -> V_605 )
return 0 ;
V_1 -> V_605 = V_46 ;
if ( V_46 == V_606 )
V_265 = F_343 ( V_9 ) ;
else
V_265 = ( V_46 == V_607 ) ;
if ( V_265 == V_1 -> V_265 )
return 0 ;
V_1 -> V_265 = V_265 ;
goto V_113;
}
if ( V_613 == V_51 -> V_615 ) {
bool V_616 = V_1 -> V_273 ;
T_2 V_617 = V_1 -> V_274 ;
switch ( V_349 ) {
case V_618 :
V_1 -> V_273 = true ;
break;
case V_619 :
V_1 -> V_273 = false ;
V_1 -> V_274 = 0 ;
break;
case V_620 :
V_1 -> V_273 = false ;
V_1 -> V_274 = V_275 ;
break;
default:
return - V_175 ;
}
if ( V_616 == V_1 -> V_273 &&
V_617 == V_1 -> V_274 )
return 0 ;
goto V_113;
}
if ( F_1 ( V_1 ) &&
V_613 == V_9 -> V_7 -> V_578 . V_621 ) {
if ( V_349 == V_622 ) {
F_33 ( L_113 ) ;
return - V_175 ;
}
if ( V_29 -> V_31 . V_266 == V_349 ) {
return 0 ;
}
V_29 -> V_31 . V_266 = V_349 ;
goto V_113;
}
return - V_175 ;
V_113:
if ( V_64 -> V_4 . V_253 )
F_346 ( V_64 -> V_4 . V_253 ) ;
return 0 ;
}
static void
F_347 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
F_333 ( V_29 -> V_547 ) ;
if ( ! F_348 ( V_29 -> V_553 ) )
F_333 ( V_29 -> V_553 ) ;
if ( V_9 -> V_623 == V_624 )
F_349 ( & V_29 -> V_31 ) ;
F_350 ( V_9 ) ;
F_333 ( V_9 ) ;
}
void F_351 ( struct V_481 * V_65 )
{
struct V_2 * V_3 = F_232 ( V_65 ) ;
struct V_1 * V_1 = & V_3 -> V_608 ;
F_110 ( & V_1 -> V_156 ) ;
F_352 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_353 ( & V_1 -> V_320 ) ;
F_23 ( V_1 ) ;
F_161 ( V_1 ) ;
F_27 ( V_1 ) ;
if ( V_1 -> V_100 . V_625 ) {
F_354 ( & V_1 -> V_100 ) ;
V_1 -> V_100 . V_625 = NULL ;
}
}
F_355 ( V_65 ) ;
F_333 ( V_3 ) ;
}
static void F_356 ( struct V_64 * V_64 )
{
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_353 ( & V_1 -> V_320 ) ;
F_23 ( V_1 ) ;
F_161 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_357 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_72 ( V_1 ) )
return;
F_33 ( L_114 ) ;
V_67 = F_24 ( & V_3 -> V_4 ) ;
F_25 ( V_51 , V_67 ) ;
F_164 ( V_1 ) ;
}
static void F_358 ( struct V_481 * V_65 )
{
struct V_1 * V_1 ;
if ( F_359 ( V_65 ) -> type != V_5 )
return;
V_1 = F_5 ( V_65 ) ;
F_23 ( V_1 ) ;
if ( F_21 ( V_65 -> V_7 ) )
F_58 ( V_1 ) ;
F_357 ( V_1 ) ;
F_27 ( V_1 ) ;
}
enum V_626
F_360 ( struct V_2 * V_3 , bool V_627 )
{
struct V_1 * V_1 = & V_3 -> V_608 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
enum V_626 V_139 = V_628 ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_611 ;
if ( V_627 && V_3 -> V_4 . type == V_5 ) {
F_33 ( L_115 ,
F_32 ( V_3 -> V_18 ) ) ;
return V_629 ;
}
F_33 ( L_116 ,
F_32 ( V_3 -> V_18 ) ,
V_627 ? L_117 : L_118 ) ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
if ( V_627 ) {
V_1 -> V_477 = false ;
if ( F_63 ( V_7 ) ) {
if ( ! F_323 ( V_51 , V_3 ) )
goto V_630;
} else {
if ( F_324 ( V_7 , V_3 ) != 1 )
goto V_630;
}
if ( ! F_293 ( V_1 ) ) {
goto V_630;
}
F_295 ( V_1 ) ;
if ( ! F_296 ( V_1 ) ) {
F_361 ( & V_7 -> V_578 . V_579 , NULL ) ;
F_315 ( V_1 ) ;
F_362 ( & V_7 -> V_578 . V_579 ) ;
goto V_630;
}
} else {
if ( V_1 -> V_528 ) {
if ( F_312 ( V_1 ) == - V_175 )
goto V_630;
}
if ( ! V_1 -> V_528 ) {
F_361 ( & V_7 -> V_578 . V_579 , NULL ) ;
F_315 ( V_1 ) ;
F_362 ( & V_7 -> V_578 . V_579 ) ;
}
}
V_139 = V_629 ;
goto V_631;
V_630:
if ( V_1 -> V_528 ) {
F_33 ( L_119 , V_1 -> V_528 , V_1 -> V_529 . V_632 ) ;
V_1 -> V_528 = false ;
F_297 ( & V_1 -> V_529 , V_1 -> V_528 ) ;
}
V_631:
F_29 ( V_51 , V_67 ) ;
return V_139 ;
}
int
F_363 ( struct V_332 * V_253 )
{
struct V_6 * V_7 = V_253 -> V_7 ;
struct V_64 * V_64 ;
struct V_1 * V_1 ;
F_364 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( V_64 -> type == V_611 ||
V_64 -> type == V_5 )
return V_1 -> V_73 ;
}
return - 1 ;
}
bool F_365 ( struct V_6 * V_7 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
union V_633 * V_634 ;
int V_46 ;
static const short V_635 [] = {
[ V_191 ] = V_636 ,
[ V_193 ] = V_637 ,
[ V_195 ] = V_638 ,
[ V_182 ] = V_639 ,
} ;
if ( V_18 == V_19 )
return true ;
if ( ! V_51 -> V_178 . V_640 )
return false ;
for ( V_46 = 0 ; V_46 < V_51 -> V_178 . V_640 ; V_46 ++ ) {
V_634 = V_51 -> V_178 . V_641 + V_46 ;
if ( V_634 -> V_642 . V_643 == V_635 [ V_18 ] &&
( V_634 -> V_642 . V_644 & V_645 ) ==
( V_646 & V_645 ) )
return true ;
}
return false ;
}
void
F_366 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
F_367 ( V_9 ) ;
F_368 ( V_9 ) ;
V_1 -> V_273 = true ;
if ( F_1 ( V_1 ) ) {
F_369 ( V_9 -> V_7 ) ;
F_370 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_578 . V_621 ,
V_647 ) ;
V_29 -> V_31 . V_266 = V_647 ;
}
}
static void F_371 ( struct V_1 * V_1 )
{
V_1 -> V_308 = V_323 ;
V_1 -> V_311 = V_323 ;
V_1 -> V_313 = V_323 ;
}
static void
F_48 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_648 V_649 , V_178 , V_650 ,
* V_651 = & V_1 -> V_652 ;
T_5 V_653 , V_654 , V_101 = 0 , V_655 = 0 ;
int V_102 , V_377 , V_656 , V_103 = 0 ;
F_43 ( & V_51 -> V_68 ) ;
if ( V_651 -> V_657 != 0 )
return;
if ( F_61 ( V_7 ) ) {
V_102 = F_62 ( 0 ) ;
V_377 = F_372 ( 0 ) ;
V_656 = F_373 ( 0 ) ;
} else if ( F_63 ( V_7 ) ) {
V_102 = V_94 ;
V_377 = V_658 ;
V_656 = V_659 ;
V_103 = V_660 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_102 = F_53 ( V_69 ) ;
V_377 = F_56 ( V_69 ) ;
V_656 = F_374 ( V_69 ) ;
V_103 = F_69 ( V_69 ) ;
}
V_655 = F_157 ( V_1 ) ;
V_653 = F_22 ( V_377 ) ;
V_654 = F_22 ( V_656 ) ;
if ( ! F_61 ( V_7 ) ) {
F_39 ( V_102 , V_655 ) ;
V_101 = F_22 ( V_103 ) ;
}
V_649 . V_661 = ( V_653 & V_662 ) >>
V_663 ;
V_649 . V_664 = ( V_653 & V_665 ) >>
V_666 ;
V_649 . V_667 = ( V_654 & V_668 ) >>
V_669 ;
V_649 . V_670 = ( V_654 & V_671 ) >>
V_672 ;
if ( F_61 ( V_7 ) ) {
T_10 V_88 = ( V_655 & V_673 ) >>
V_674 ;
if ( V_88 > 0 )
V_649 . V_657 = ( V_88 - 1 ) * 1000 ;
else
V_649 . V_657 = 0 ;
} else {
V_649 . V_657 = ( ( V_101 & V_675 ) >>
V_676 ) * 1000 ;
}
F_33 ( L_120 ,
V_649 . V_661 , V_649 . V_664 , V_649 . V_667 , V_649 . V_670 , V_649 . V_657 ) ;
V_178 = V_51 -> V_178 . V_677 ;
V_650 . V_661 = 210 * 10 ;
V_650 . V_664 = 50 * 10 ;
V_650 . V_667 = 50 * 10 ;
V_650 . V_670 = 500 * 10 ;
V_650 . V_657 = ( 510 + 100 ) * 10 ;
F_33 ( L_121 ,
V_178 . V_661 , V_178 . V_664 , V_178 . V_667 , V_178 . V_670 , V_178 . V_657 ) ;
#define F_375 ( T_11 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_375 ( V_661 ) ;
F_375 ( V_664 ) ;
F_375 ( V_667 ) ;
F_375 ( V_670 ) ;
F_375 ( V_657 ) ;
#undef F_375
#define F_376 ( T_11 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_321 = F_376 ( V_661 ) ;
V_1 -> V_312 = F_376 ( V_664 ) ;
V_1 -> V_314 = F_376 ( V_667 ) ;
V_1 -> V_498 = F_376 ( V_670 ) ;
V_1 -> V_108 = F_376 ( V_657 ) ;
#undef F_376
F_33 ( L_122 ,
V_1 -> V_321 , V_1 -> V_498 ,
V_1 -> V_108 ) ;
F_33 ( L_123 ,
V_1 -> V_312 , V_1 -> V_314 ) ;
}
static void
F_49 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_653 , V_654 , V_101 , V_92 = 0 ;
int div = F_63 ( V_7 ) ? F_83 ( V_7 ) : F_20 ( V_7 ) ;
int V_377 , V_656 , V_103 = 0 , V_102 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
const struct V_648 * V_678 = & V_1 -> V_652 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_61 ( V_7 ) ) {
V_102 = F_62 ( 0 ) ;
V_377 = F_372 ( 0 ) ;
V_656 = F_373 ( 0 ) ;
} else if ( F_63 ( V_7 ) ) {
V_377 = V_658 ;
V_656 = V_659 ;
V_103 = V_660 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_377 = F_56 ( V_69 ) ;
V_656 = F_374 ( V_69 ) ;
V_103 = F_69 ( V_69 ) ;
}
V_653 = ( V_678 -> V_661 << V_663 ) |
( 1 << V_666 ) ;
V_654 = ( 1 << V_669 ) |
( V_678 -> V_670 << V_672 ) ;
if ( F_61 ( V_7 ) ) {
V_101 = F_22 ( V_102 ) ;
V_101 &= ~ V_673 ;
V_101 |= ( F_82 ( ( V_678 -> V_657 + 1 ) , 1000 )
<< V_674 ) ;
} else {
V_101 = ( ( 100 * div ) / 2 - 1 ) << V_679 ;
V_101 |= ( F_82 ( V_678 -> V_657 , 1000 )
<< V_676 ) ;
}
if ( F_21 ( V_7 ) ) {
V_92 = F_57 ( V_18 ) ;
} else if ( F_292 ( V_7 ) || F_147 ( V_7 ) ) {
if ( V_18 == V_19 )
V_92 = V_680 ;
else
V_92 = V_681 ;
}
V_653 |= V_92 ;
F_39 ( V_377 , V_653 ) ;
F_39 ( V_656 , V_654 ) ;
if ( F_61 ( V_7 ) )
F_39 ( V_102 , V_101 ) ;
else
F_39 ( V_103 , V_101 ) ;
F_33 ( L_124 ,
F_22 ( V_377 ) ,
F_22 ( V_656 ) ,
F_61 ( V_7 ) ?
( F_22 ( V_102 ) & V_673 ) :
F_22 ( V_103 ) ) ;
}
static void F_377 ( struct V_6 * V_7 , int V_682 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_64 * V_65 ;
struct V_2 * V_284 = NULL ;
struct V_1 * V_1 = V_51 -> V_281 . V_608 ;
struct V_202 * V_286 = NULL ;
struct V_252 * V_252 = NULL ;
T_5 V_588 , V_349 ;
enum V_683 V_115 = V_684 ;
if ( V_682 <= 0 ) {
F_33 ( L_125 ) ;
return;
}
if ( V_1 == NULL ) {
F_33 ( L_126 ) ;
return;
}
V_284 = F_2 ( V_1 ) ;
V_65 = & V_284 -> V_4 ;
V_252 = F_134 ( V_65 -> V_4 . V_253 ) ;
if ( ! V_252 ) {
F_33 ( L_127 ) ;
return;
}
V_286 = V_252 -> V_286 ;
if ( V_51 -> V_281 . type < V_282 ) {
F_33 ( L_128 ) ;
return;
}
if ( V_1 -> V_254 -> V_31 . V_280 -> V_685 ==
V_682 )
V_115 = V_686 ;
if ( V_115 == V_51 -> V_281 . V_687 ) {
F_33 (
L_129 ) ;
return;
}
if ( ! V_252 -> V_580 ) {
F_33 ( L_130 ) ;
return;
}
if ( F_122 ( V_7 ) -> V_224 >= 8 && ! F_35 ( V_7 ) ) {
switch ( V_115 ) {
case V_684 :
F_378 ( V_252 , V_688 ) ;
break;
case V_686 :
F_378 ( V_252 , V_689 ) ;
break;
case V_690 :
default:
F_79 ( L_131 ) ;
}
} else if ( F_122 ( V_7 ) -> V_224 > 6 ) {
V_588 = F_379 ( V_252 -> V_286 -> V_691 ) ;
V_349 = F_22 ( V_588 ) ;
if ( V_115 > V_684 ) {
if ( F_21 ( V_7 ) )
V_349 |= V_692 ;
else
V_349 |= V_693 ;
} else {
if ( F_21 ( V_7 ) )
V_349 &= ~ V_692 ;
else
V_349 &= ~ V_693 ;
}
F_39 ( V_588 , V_349 ) ;
}
V_51 -> V_281 . V_687 = V_115 ;
F_33 ( L_132 , V_682 ) ;
}
void F_380 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_332 * V_253 = V_284 -> V_4 . V_4 . V_253 ;
struct V_252 * V_252 = F_134 ( V_253 ) ;
if ( ! V_252 -> V_286 -> V_264 ) {
F_33 ( L_133 ) ;
return;
}
F_26 ( & V_51 -> V_281 . V_694 ) ;
if ( F_44 ( V_51 -> V_281 . V_608 ) ) {
F_79 ( L_134 ) ;
goto V_695;
}
V_51 -> V_281 . V_696 = 0 ;
V_51 -> V_281 . V_608 = V_1 ;
V_695:
F_28 ( & V_51 -> V_281 . V_694 ) ;
}
void F_381 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_284 = F_2 ( V_1 ) ;
struct V_332 * V_253 = V_284 -> V_4 . V_4 . V_253 ;
struct V_252 * V_252 = F_134 ( V_253 ) ;
if ( ! V_252 -> V_286 -> V_264 )
return;
F_26 ( & V_51 -> V_281 . V_694 ) ;
if ( ! V_51 -> V_281 . V_608 ) {
F_28 ( & V_51 -> V_281 . V_694 ) ;
return;
}
if ( V_51 -> V_281 . V_687 == V_686 )
F_377 ( V_51 -> V_7 ,
V_1 -> V_254 -> V_31 .
V_30 -> V_685 ) ;
V_51 -> V_281 . V_608 = NULL ;
F_28 ( & V_51 -> V_281 . V_694 ) ;
F_353 ( & V_51 -> V_281 . V_697 ) ;
}
static void F_382 ( struct V_324 * V_697 )
{
struct V_50 * V_51 =
F_67 ( V_697 , F_68 ( * V_51 ) , V_281 . V_697 . V_697 ) ;
struct V_1 * V_1 ;
F_26 ( & V_51 -> V_281 . V_694 ) ;
V_1 = V_51 -> V_281 . V_608 ;
if ( ! V_1 )
goto V_695;
if ( V_51 -> V_281 . V_696 )
goto V_695;
if ( V_51 -> V_281 . V_687 != V_686 )
F_377 ( V_51 -> V_7 ,
V_1 -> V_254 -> V_31 .
V_280 -> V_685 ) ;
V_695:
F_28 ( & V_51 -> V_281 . V_694 ) ;
}
void F_383 ( struct V_6 * V_7 ,
unsigned V_698 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_332 * V_253 ;
enum V_69 V_69 ;
if ( V_51 -> V_281 . type == V_699 )
return;
F_158 ( & V_51 -> V_281 . V_697 ) ;
F_26 ( & V_51 -> V_281 . V_694 ) ;
if ( ! V_51 -> V_281 . V_608 ) {
F_28 ( & V_51 -> V_281 . V_694 ) ;
return;
}
V_253 = F_2 ( V_51 -> V_281 . V_608 ) -> V_4 . V_4 . V_253 ;
V_69 = F_134 ( V_253 ) -> V_69 ;
V_698 &= F_384 ( V_69 ) ;
V_51 -> V_281 . V_696 |= V_698 ;
if ( V_698 && V_51 -> V_281 . V_687 == V_686 )
F_377 ( V_51 -> V_7 ,
V_51 -> V_281 . V_608 -> V_254 -> V_31 .
V_30 -> V_685 ) ;
F_28 ( & V_51 -> V_281 . V_694 ) ;
}
void F_385 ( struct V_6 * V_7 ,
unsigned V_698 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_332 * V_253 ;
enum V_69 V_69 ;
if ( V_51 -> V_281 . type == V_699 )
return;
F_158 ( & V_51 -> V_281 . V_697 ) ;
F_26 ( & V_51 -> V_281 . V_694 ) ;
if ( ! V_51 -> V_281 . V_608 ) {
F_28 ( & V_51 -> V_281 . V_694 ) ;
return;
}
V_253 = F_2 ( V_51 -> V_281 . V_608 ) -> V_4 . V_4 . V_253 ;
V_69 = F_134 ( V_253 ) -> V_69 ;
V_698 &= F_384 ( V_69 ) ;
V_51 -> V_281 . V_696 &= ~ V_698 ;
if ( V_698 && V_51 -> V_281 . V_687 == V_686 )
F_377 ( V_51 -> V_7 ,
V_51 -> V_281 . V_608 -> V_254 -> V_31 .
V_30 -> V_685 ) ;
if ( ! V_51 -> V_281 . V_696 )
F_166 ( & V_51 -> V_281 . V_697 ,
F_165 ( 1000 ) ) ;
F_28 ( & V_51 -> V_281 . V_694 ) ;
}
static struct V_27 *
F_386 ( struct V_29 * V_29 ,
struct V_27 * V_30 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_280 = NULL ;
F_387 ( & V_51 -> V_281 . V_697 , F_382 ) ;
F_388 ( & V_51 -> V_281 . V_694 ) ;
if ( F_122 ( V_7 ) -> V_224 <= 6 ) {
F_33 ( L_135 ) ;
return NULL ;
}
if ( V_51 -> V_178 . V_700 != V_282 ) {
F_33 ( L_136 ) ;
return NULL ;
}
V_280 = F_389
( V_7 , V_30 , V_9 ) ;
if ( ! V_280 ) {
F_33 ( L_137 ) ;
return NULL ;
}
V_51 -> V_281 . type = V_51 -> V_178 . V_700 ;
V_51 -> V_281 . V_687 = V_684 ;
F_33 ( L_138 ) ;
return V_280 ;
}
static bool F_390 ( struct V_1 * V_1 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_30 = NULL ;
struct V_27 * V_280 = NULL ;
bool V_701 ;
struct V_27 * V_702 ;
struct V_553 * V_553 ;
enum V_69 V_69 = V_87 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_23 ( V_1 ) ;
F_357 ( V_1 ) ;
F_27 ( V_1 ) ;
V_701 = F_293 ( V_1 ) ;
if ( V_701 ) {
if ( V_1 -> V_11 [ V_334 ] >= 0x11 )
V_51 -> V_703 =
V_1 -> V_11 [ V_704 ] &
V_705 ;
} else {
F_391 ( L_139 ) ;
return false ;
}
F_23 ( V_1 ) ;
F_49 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
F_26 ( & V_7 -> V_578 . V_694 ) ;
V_553 = F_329 ( V_9 , & V_1 -> V_156 . V_200 ) ;
if ( V_553 ) {
if ( F_392 ( V_9 , V_553 ) ) {
F_393 ( V_9 ,
V_553 ) ;
F_394 ( V_9 , V_553 ) ;
} else {
F_333 ( V_553 ) ;
V_553 = F_395 ( - V_175 ) ;
}
} else {
V_553 = F_395 ( - V_706 ) ;
}
V_29 -> V_553 = V_553 ;
F_45 (scan, &connector->probed_modes, head) {
if ( ( V_702 -> type & V_707 ) ) {
V_30 = F_341 ( V_7 , V_702 ) ;
V_280 = F_386 (
V_29 , V_30 ) ;
break;
}
}
if ( ! V_30 && V_51 -> V_178 . V_708 ) {
V_30 = F_341 ( V_7 ,
V_51 -> V_178 . V_708 ) ;
if ( V_30 )
V_30 -> type |= V_707 ;
}
F_28 ( & V_7 -> V_578 . V_694 ) ;
if ( F_21 ( V_7 ) ) {
V_1 -> V_100 . V_625 = F_66 ;
F_396 ( & V_1 -> V_100 ) ;
if ( F_35 ( V_7 ) )
V_69 = F_189 ( V_1 -> V_72 ) ;
else
V_69 = F_190 ( V_1 -> V_72 ) ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_1 -> V_70 ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_86 ;
F_33 ( L_140 ,
F_31 ( V_69 ) ) ;
}
F_397 ( & V_29 -> V_31 , V_30 , V_280 ) ;
V_29 -> V_31 . V_709 = F_178 ;
F_398 ( V_9 , V_69 ) ;
return true ;
}
bool
F_399 ( struct V_2 * V_3 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_608 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
int type ;
V_1 -> V_70 = V_87 ;
if ( F_122 ( V_7 ) -> V_224 >= 9 )
V_1 -> V_148 = F_87 ;
else if ( F_21 ( V_7 ) )
V_1 -> V_148 = F_86 ;
else if ( F_107 ( V_7 ) || F_90 ( V_7 ) )
V_1 -> V_148 = F_84 ;
else if ( F_63 ( V_7 ) )
V_1 -> V_148 = F_81 ;
else
V_1 -> V_148 = F_80 ;
if ( F_122 ( V_7 ) -> V_224 >= 9 )
V_1 -> V_150 = F_91 ;
else
V_1 -> V_150 = F_88 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) ;
V_1 -> V_254 = V_29 ;
if ( F_365 ( V_7 , V_18 ) )
type = V_624 ;
else
type = V_710 ;
if ( type == V_624 )
V_64 -> type = V_5 ;
if ( F_44 ( F_21 ( V_7 ) && F_1 ( V_1 ) &&
V_18 != V_191 && V_18 != V_193 ) )
return false ;
F_33 ( L_141 ,
type == V_624 ? L_142 : L_143 ,
F_32 ( V_18 ) ) ;
F_400 ( V_7 , V_9 , & V_711 , type ) ;
F_401 ( V_9 , & V_712 ) ;
V_9 -> V_713 = true ;
V_9 -> V_714 = 0 ;
F_387 ( & V_1 -> V_320 ,
F_162 ) ;
F_402 ( V_29 , V_64 ) ;
F_403 ( V_9 ) ;
if ( F_10 ( V_7 ) )
V_29 -> V_715 = V_716 ;
else
V_29 -> V_715 = V_717 ;
V_29 -> V_718 = F_111 ;
switch ( V_18 ) {
case V_19 :
V_64 -> V_719 = V_720 ;
break;
case V_191 :
V_64 -> V_719 = V_721 ;
break;
case V_193 :
V_64 -> V_719 = V_722 ;
break;
case V_195 :
V_64 -> V_719 = V_723 ;
break;
case V_182 :
V_64 -> V_719 = V_724 ;
break;
default:
F_106 () ;
}
if ( F_1 ( V_1 ) ) {
F_23 ( V_1 ) ;
F_371 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_58 ( V_1 ) ;
else
F_48 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
}
F_104 ( V_1 , V_29 ) ;
if ( F_404 ( V_7 ) &&
( V_18 == V_191 || V_18 == V_193 || V_18 == V_195 ) )
F_405 ( V_3 ,
V_29 -> V_4 . V_4 . V_610 ) ;
if ( ! F_390 ( V_1 , V_29 ) ) {
F_110 ( & V_1 -> V_156 ) ;
if ( F_1 ( V_1 ) ) {
F_353 ( & V_1 -> V_320 ) ;
F_23 ( V_1 ) ;
F_161 ( V_1 ) ;
F_27 ( V_1 ) ;
}
F_406 ( V_9 ) ;
F_350 ( V_9 ) ;
return false ;
}
F_366 ( V_1 , V_9 ) ;
if ( F_126 ( V_7 ) && ! F_407 ( V_7 ) ) {
T_5 V_355 = F_22 ( V_725 ) ;
F_39 ( V_725 , ( V_355 & ~ 0xf ) | 0xd ) ;
}
F_408 ( V_9 ) ;
return true ;
}
void
F_409 ( struct V_6 * V_7 , int V_73 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 ;
struct V_64 * V_64 ;
struct V_481 * V_65 ;
struct V_29 * V_29 ;
V_3 = F_410 ( sizeof( * V_3 ) , V_726 ) ;
if ( ! V_3 )
return;
V_29 = F_411 () ;
if ( ! V_29 ) {
F_333 ( V_3 ) ;
return;
}
V_64 = & V_3 -> V_4 ;
V_65 = & V_64 -> V_4 ;
F_412 ( V_7 , & V_64 -> V_4 , & V_727 ,
V_728 ) ;
V_64 -> V_729 = F_133 ;
V_64 -> V_730 = F_195 ;
V_64 -> V_715 = F_184 ;
V_64 -> V_731 = F_191 ;
V_64 -> V_732 = F_356 ;
if ( F_35 ( V_7 ) ) {
V_64 -> V_733 = F_249 ;
V_64 -> V_734 = F_238 ;
V_64 -> V_330 = F_222 ;
V_64 -> V_735 = F_202 ;
} else if ( F_21 ( V_7 ) ) {
V_64 -> V_733 = F_231 ;
V_64 -> V_734 = F_226 ;
V_64 -> V_330 = F_222 ;
V_64 -> V_735 = F_201 ;
} else {
V_64 -> V_734 = F_224 ;
V_64 -> V_330 = F_221 ;
if ( F_122 ( V_7 ) -> V_224 >= 5 )
V_64 -> V_735 = F_200 ;
}
V_3 -> V_18 = V_18 ;
V_3 -> V_608 . V_73 = V_73 ;
V_64 -> type = V_611 ;
if ( F_35 ( V_7 ) ) {
if ( V_18 == V_195 )
V_64 -> V_736 = 1 << 2 ;
else
V_64 -> V_736 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_64 -> V_736 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_64 -> V_737 = 0 ;
V_3 -> V_738 = F_360 ;
V_51 -> V_739 . V_740 [ V_18 ] = V_3 ;
if ( ! F_399 ( V_3 , V_29 ) ) {
F_355 ( V_65 ) ;
F_333 ( V_3 ) ;
F_333 ( V_29 ) ;
}
}
void F_413 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_741 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_739 . V_740 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_611 ) {
if ( ! V_3 -> V_608 . V_525 )
continue;
if ( V_3 -> V_608 . V_528 )
F_414 ( & V_3 -> V_608 . V_529 ) ;
}
}
}
void F_415 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_741 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_739 . V_740 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_611 ) {
int V_139 ;
if ( ! V_3 -> V_608 . V_525 )
continue;
V_139 = F_416 ( & V_3 -> V_608 . V_529 ) ;
if ( V_139 != 0 ) {
F_312 ( & V_3 -> V_608 ) ;
}
}
}
}
