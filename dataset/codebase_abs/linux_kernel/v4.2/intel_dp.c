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
struct V_50 * V_51 = V_7 -> V_52 ;
if ( V_115 )
return 0 ;
if ( V_3 -> V_18 == V_19 ) {
return F_79 ( V_51 -> V_116 . V_117 ( V_7 ) , 2000 ) ;
} else {
return F_79 ( F_80 ( V_7 ) , 2 ) ;
}
}
static T_2 F_81 ( struct V_1 * V_1 , int V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
if ( V_3 -> V_18 == V_19 ) {
if ( V_115 )
return 0 ;
return F_82 ( V_51 -> V_116 . V_117 ( V_7 ) , 2000 ) ;
} else if ( V_51 -> V_118 == V_119 ) {
switch ( V_115 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_115 ? 0 : F_79 ( F_80 ( V_7 ) , 2 ) ;
}
}
static T_2 F_83 ( struct V_1 * V_1 , int V_115 )
{
return V_115 ? 0 : 100 ;
}
static T_2 F_84 ( struct V_1 * V_1 , int V_115 )
{
return V_115 ? 0 : 1 ;
}
static T_2 F_85 ( struct V_1 * V_1 ,
bool V_109 ,
int V_120 ,
T_2 V_121 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_122 , V_123 ;
if ( F_86 ( V_7 ) )
V_122 = 3 ;
else
V_122 = 5 ;
if ( F_87 ( V_7 ) && V_1 -> V_111 == V_124 )
V_123 = V_125 ;
else
V_123 = V_126 ;
return V_127 |
V_128 |
( V_109 ? V_129 : 0 ) |
V_130 |
V_123 |
V_131 |
( V_120 << V_132 ) |
( V_122 << V_133 ) |
( V_121 << V_134 ) ;
}
static T_2 F_88 ( struct V_1 * V_1 ,
bool V_109 ,
int V_120 ,
T_2 V_99 )
{
return V_127 |
V_128 |
( V_109 ? V_129 : 0 ) |
V_130 |
V_135 |
V_131 |
( V_120 << V_132 ) |
F_89 ( 32 ) ;
}
static int
F_90 ( struct V_1 * V_1 ,
const T_3 * V_136 , int V_120 ,
T_3 * V_137 , int V_138 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_110 = V_1 -> V_111 ;
T_2 V_139 = V_110 + 4 ;
T_2 V_121 ;
int V_46 , V_140 , V_141 ;
T_2 V_112 ;
int V_142 , clock = 0 ;
bool V_109 = F_91 ( V_7 ) ;
bool V_143 ;
F_23 ( V_1 ) ;
V_143 = F_92 ( V_1 ) ;
F_93 ( & V_51 -> V_144 , 0 ) ;
F_70 ( V_1 ) ;
F_94 ( V_51 ) ;
for ( V_142 = 0 ; V_142 < 3 ; V_142 ++ ) {
V_112 = F_95 ( V_110 ) ;
if ( ( V_112 & V_127 ) == 0 )
break;
F_67 ( 1 ) ;
}
if ( V_142 == 3 ) {
F_8 ( 1 , L_10 ,
F_22 ( V_110 ) ) ;
V_140 = - V_145 ;
goto V_146;
}
if ( F_44 ( V_120 > 20 || V_138 > 20 ) ) {
V_140 = - V_147 ;
goto V_146;
}
while ( ( V_121 = V_1 -> V_148 ( V_1 , clock ++ ) ) ) {
T_5 V_149 = V_1 -> V_150 ( V_1 ,
V_109 ,
V_120 ,
V_121 ) ;
for ( V_142 = 0 ; V_142 < 5 ; V_142 ++ ) {
for ( V_46 = 0 ; V_46 < V_120 ; V_46 += 4 )
F_39 ( V_139 + V_46 ,
F_18 ( V_136 + V_46 ,
V_120 - V_46 ) ) ;
F_39 ( V_110 , V_149 ) ;
V_112 = F_71 ( V_1 , V_109 ) ;
F_39 ( V_110 ,
V_112 |
V_128 |
V_130 |
V_131 ) ;
if ( V_112 & V_130 )
continue;
if ( V_112 & V_131 ) {
F_96 ( 400 , 500 ) ;
continue;
}
if ( V_112 & V_128 )
goto V_113;
}
}
if ( ( V_112 & V_128 ) == 0 ) {
F_76 ( L_11 , V_112 ) ;
V_140 = - V_145 ;
goto V_146;
}
V_113:
if ( V_112 & V_131 ) {
F_76 ( L_12 , V_112 ) ;
V_140 = - V_151 ;
goto V_146;
}
if ( V_112 & V_130 ) {
F_33 ( L_13 , V_112 ) ;
V_140 = - V_152 ;
goto V_146;
}
V_141 = ( ( V_112 & V_153 ) >>
V_132 ) ;
if ( V_141 > V_138 )
V_141 = V_138 ;
for ( V_46 = 0 ; V_46 < V_141 ; V_46 += 4 )
F_19 ( F_22 ( V_139 + V_46 ) ,
V_137 + V_46 , V_141 - V_46 ) ;
V_140 = V_141 ;
V_146:
F_93 ( & V_51 -> V_144 , V_154 ) ;
F_97 ( V_51 ) ;
if ( V_143 )
F_98 ( V_1 , false ) ;
F_27 ( V_1 ) ;
return V_140 ;
}
static T_6
F_99 ( struct V_155 * V_156 , struct V_157 * V_158 )
{
struct V_1 * V_1 = F_64 ( V_156 , struct V_1 , V_156 ) ;
T_3 V_159 [ 20 ] , V_160 [ 20 ] ;
T_7 V_161 , V_162 ;
int V_140 ;
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
V_140 = F_90 ( V_1 , V_159 , V_161 , V_160 , V_162 ) ;
if ( V_140 > 0 ) {
V_158 -> V_172 = V_160 [ 0 ] >> 4 ;
if ( V_140 > 1 ) {
V_140 = F_100 ( int , V_160 [ 1 ] , 0 , V_158 -> V_165 ) ;
} else {
V_140 = V_158 -> V_165 ;
}
}
break;
case V_173 :
case V_174 :
V_161 = V_158 -> V_165 ? V_169 : V_170 ;
V_162 = V_158 -> V_165 + 1 ;
if ( F_44 ( V_162 > 20 ) )
return - V_147 ;
V_140 = F_90 ( V_1 , V_159 , V_161 , V_160 , V_162 ) ;
if ( V_140 > 0 ) {
V_158 -> V_172 = V_160 [ 0 ] >> 4 ;
V_140 -- ;
memcpy ( V_158 -> V_171 , V_160 + 1 , V_140 ) ;
}
break;
default:
V_140 = - V_175 ;
break;
}
return V_140 ;
}
static void
F_101 ( struct V_1 * V_1 , struct V_29 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
const char * V_176 = NULL ;
int V_140 ;
switch ( V_18 ) {
case V_19 :
V_1 -> V_111 = V_124 ;
V_176 = L_14 ;
break;
case V_177 :
V_1 -> V_111 = V_178 ;
V_176 = L_15 ;
break;
case V_179 :
V_1 -> V_111 = V_180 ;
V_176 = L_16 ;
break;
case V_181 :
V_1 -> V_111 = V_182 ;
V_176 = L_17 ;
break;
default:
F_102 () ;
}
if ( ! F_103 ( V_7 ) && ! F_87 ( V_7 ) )
V_1 -> V_111 = V_1 -> V_73 + 0x10 ;
V_1 -> V_156 . V_176 = V_176 ;
V_1 -> V_156 . V_7 = V_7 -> V_7 ;
V_1 -> V_156 . V_183 = F_99 ;
F_33 ( L_18 , V_176 ,
V_9 -> V_4 . V_184 -> V_185 . V_176 ) ;
V_140 = F_104 ( & V_1 -> V_156 ) ;
if ( V_140 < 0 ) {
F_76 ( L_19 ,
V_176 , V_140 ) ;
return;
}
V_140 = F_105 ( & V_9 -> V_4 . V_184 -> V_185 ,
& V_1 -> V_156 . V_186 . V_7 . V_185 ,
V_1 -> V_156 . V_186 . V_7 . V_185 . V_176 ) ;
if ( V_140 < 0 ) {
F_76 ( L_20 , V_176 , V_140 ) ;
F_106 ( & V_1 -> V_156 ) ;
}
}
static void
F_107 ( struct V_29 * V_29 )
{
struct V_1 * V_1 = F_4 ( & V_29 -> V_4 ) ;
if ( ! V_29 -> V_187 )
F_108 ( & V_29 -> V_4 . V_184 -> V_185 ,
V_1 -> V_156 . V_186 . V_7 . V_185 . V_176 ) ;
F_109 ( V_29 ) ;
}
static void
F_110 ( struct V_188 * V_189 , int V_190 )
{
T_5 V_191 ;
memset ( & V_189 -> V_192 , 0 ,
sizeof( V_189 -> V_192 ) ) ;
V_189 -> V_193 = V_194 ;
V_189 -> V_192 . V_195 = 0 ;
V_189 -> V_192 . V_196 = 0 ;
V_191 = F_111 ( V_194 ) ;
switch ( V_190 / 2 ) {
case 81000 :
V_191 |= F_112 ( V_197 ,
V_194 ) ;
break;
case 135000 :
V_191 |= F_112 ( V_198 ,
V_194 ) ;
break;
case 270000 :
V_191 |= F_112 ( V_199 ,
V_194 ) ;
break;
case 162000 :
V_191 |= F_112 ( V_200 ,
V_194 ) ;
break;
case 108000 :
V_191 |= F_112 ( V_201 ,
V_194 ) ;
break;
case 216000 :
V_191 |= F_112 ( V_202 ,
V_194 ) ;
break;
}
V_189 -> V_192 . V_191 = V_191 ;
}
static void
F_113 ( struct V_188 * V_189 , int V_203 )
{
memset ( & V_189 -> V_192 , 0 ,
sizeof( V_189 -> V_192 ) ) ;
switch ( V_203 ) {
case V_13 :
V_189 -> V_193 = V_204 ;
break;
case V_14 :
V_189 -> V_193 = V_205 ;
break;
case V_15 :
V_189 -> V_193 = V_206 ;
break;
}
}
static int
F_114 ( struct V_1 * V_1 , const int * * V_207 )
{
if ( V_1 -> V_208 ) {
* V_207 = V_1 -> V_207 ;
return V_1 -> V_208 ;
}
* V_207 = V_209 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
static bool F_115 ( struct V_6 * V_7 )
{
if ( F_116 ( V_7 ) && F_117 ( V_7 ) <= V_210 )
return false ;
if ( ( F_103 ( V_7 ) && ! F_118 ( V_7 ) ) || F_87 ( V_7 ) ||
( F_119 ( V_7 ) -> V_211 >= 9 ) )
return true ;
else
return false ;
}
static int
F_120 ( struct V_6 * V_7 , const int * * V_212 )
{
if ( F_116 ( V_7 ) ) {
* V_212 = V_213 ;
return F_121 ( V_213 ) ;
}
* V_212 = V_209 ;
if ( F_115 ( V_7 ) )
return ( V_15 >> 3 ) + 1 ;
else
return ( V_14 >> 3 ) + 1 ;
}
static void
F_122 ( struct V_64 * V_65 ,
struct V_188 * V_189 , int V_203 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
const struct V_214 * V_215 = NULL ;
int V_46 , V_216 = 0 ;
if ( F_123 ( V_7 ) ) {
V_215 = V_217 ;
V_216 = F_121 ( V_217 ) ;
} else if ( F_61 ( V_7 ) ) {
V_215 = V_218 ;
V_216 = F_121 ( V_218 ) ;
} else if ( F_35 ( V_7 ) ) {
V_215 = V_82 ;
V_216 = F_121 ( V_82 ) ;
} else if ( F_21 ( V_7 ) ) {
V_215 = V_84 ;
V_216 = F_121 ( V_84 ) ;
}
if ( V_215 && V_216 ) {
for ( V_46 = 0 ; V_46 < V_216 ; V_46 ++ ) {
if ( V_203 == V_215 [ V_46 ] . V_203 ) {
V_189 -> V_83 = V_215 [ V_46 ] . V_83 ;
V_189 -> V_219 = true ;
break;
}
}
}
}
static int F_124 ( const int * V_212 , int V_220 ,
const int * V_207 , int V_221 ,
int * V_222 )
{
int V_46 = 0 , V_223 = 0 , V_224 = 0 ;
while ( V_46 < V_220 && V_223 < V_221 ) {
if ( V_212 [ V_46 ] == V_207 [ V_223 ] ) {
if ( F_44 ( V_224 >= V_225 ) )
return V_224 ;
V_222 [ V_224 ] = V_212 [ V_46 ] ;
++ V_224 ;
++ V_46 ;
++ V_223 ;
} else if ( V_212 [ V_46 ] < V_207 [ V_223 ] ) {
++ V_46 ;
} else {
++ V_223 ;
}
}
return V_224 ;
}
static int F_125 ( struct V_1 * V_1 ,
int * V_222 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_212 , * V_207 ;
int V_220 , V_221 ;
V_221 = F_114 ( V_1 , & V_207 ) ;
V_220 = F_120 ( V_7 , & V_212 ) ;
return F_124 ( V_212 , V_220 ,
V_207 , V_221 ,
V_222 ) ;
}
static void F_126 ( char * V_226 , T_7 V_227 ,
const int * V_228 , int V_229 )
{
int V_46 ;
V_226 [ 0 ] = '\0' ;
for ( V_46 = 0 ; V_46 < V_229 ; V_46 ++ ) {
int V_230 = snprintf ( V_226 , V_227 , L_21 , V_46 ? L_22 : L_23 , V_228 [ V_46 ] ) ;
if ( V_230 >= V_227 )
return;
V_226 += V_230 ;
V_227 -= V_230 ;
}
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_212 , * V_207 ;
int V_220 , V_221 , V_231 ;
int V_222 [ V_225 ] ;
char V_226 [ 128 ] ;
if ( ( V_232 & V_233 ) == 0 )
return;
V_220 = F_120 ( V_7 , & V_212 ) ;
F_126 ( V_226 , sizeof( V_226 ) , V_212 , V_220 ) ;
F_33 ( L_24 , V_226 ) ;
V_221 = F_114 ( V_1 , & V_207 ) ;
F_126 ( V_226 , sizeof( V_226 ) , V_207 , V_221 ) ;
F_33 ( L_25 , V_226 ) ;
V_231 = F_125 ( V_1 , V_222 ) ;
F_126 ( V_226 , sizeof( V_226 ) , V_222 , V_231 ) ;
F_33 ( L_26 , V_226 ) ;
}
static int F_128 ( int V_234 , const int * V_235 )
{
int V_46 = 0 ;
for ( V_46 = 0 ; V_46 < V_225 ; ++ V_46 )
if ( V_234 == V_235 [ V_46 ] )
break;
return V_46 ;
}
int
F_17 ( struct V_1 * V_1 )
{
int V_235 [ V_225 ] = {} ;
int V_227 ;
V_227 = F_125 ( V_1 , V_235 ) ;
if ( F_44 ( V_227 <= 0 ) )
return 162000 ;
return V_235 [ F_128 ( 0 , V_235 ) - 1 ] ;
}
int F_129 ( struct V_1 * V_1 , int V_236 )
{
return F_128 ( V_236 , V_1 -> V_207 ) ;
}
bool
F_130 ( struct V_64 * V_65 ,
struct V_188 * V_189 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_237 = & V_189 -> V_4 . V_237 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_238 * V_238 = F_131 ( V_189 -> V_4 . V_239 ) ;
struct V_29 * V_29 = V_1 -> V_240 ;
int V_241 , clock ;
int V_242 = 1 ;
int V_243 = F_9 ( V_1 ) ;
int V_244 = 0 ;
int V_245 ;
int V_23 , V_34 ;
int V_246 , V_190 ;
int V_222 [ V_225 ] = {} ;
int V_231 ;
V_231 = F_125 ( V_1 , V_222 ) ;
F_44 ( V_231 <= 0 ) ;
V_245 = V_231 - 1 ;
if ( F_61 ( V_7 ) && ! F_10 ( V_7 ) && V_18 != V_19 )
V_189 -> V_247 = true ;
V_189 -> V_248 = true ;
V_189 -> V_249 = false ;
V_189 -> V_250 = V_1 -> V_250 && V_18 != V_19 ;
if ( F_1 ( V_1 ) && V_29 -> V_31 . V_30 ) {
F_132 ( V_29 -> V_31 . V_30 ,
V_237 ) ;
if ( F_119 ( V_7 ) -> V_211 >= 9 ) {
int V_140 ;
V_140 = F_133 ( V_238 , V_189 , NULL , NULL , 0 ) ;
if ( V_140 )
return V_140 ;
}
if ( ! F_61 ( V_7 ) )
F_134 ( V_238 , V_189 ,
V_29 -> V_31 . V_251 ) ;
else
F_135 ( V_238 , V_189 ,
V_29 -> V_31 . V_251 ) ;
}
if ( V_237 -> V_40 & V_41 )
return false ;
F_33 ( L_27
L_28 ,
V_243 , V_222 [ V_245 ] ,
V_237 -> V_252 ) ;
V_23 = V_189 -> V_253 ;
if ( F_1 ( V_1 ) ) {
if ( V_51 -> V_254 . V_255 && V_51 -> V_254 . V_255 < V_23 ) {
F_33 ( L_29 ,
V_51 -> V_254 . V_255 ) ;
V_23 = V_51 -> V_254 . V_255 ;
}
V_242 = V_243 ;
V_244 = V_245 ;
}
for (; V_23 >= 6 * 3 ; V_23 -= 2 * 3 ) {
V_34 = F_13 ( V_237 -> V_252 ,
V_23 ) ;
for ( clock = V_244 ; clock <= V_245 ; clock ++ ) {
for ( V_241 = V_242 ;
V_241 <= V_243 ;
V_241 <<= 1 ) {
V_190 = V_222 [ clock ] ;
V_246 = F_14 ( V_190 ,
V_241 ) ;
if ( V_34 <= V_246 ) {
goto V_256;
}
}
}
}
return false ;
V_256:
if ( V_1 -> V_257 ) {
if ( V_23 != 18 && F_136 ( V_237 ) > 1 )
V_1 -> V_258 = V_259 ;
else
V_1 -> V_258 = 0 ;
}
if ( V_1 -> V_258 )
V_189 -> V_260 = true ;
V_1 -> V_241 = V_241 ;
if ( V_1 -> V_208 ) {
V_1 -> V_203 = 0 ;
V_1 -> V_261 =
F_129 ( V_1 , V_222 [ clock ] ) ;
} else {
V_1 -> V_203 =
F_137 ( V_222 [ clock ] ) ;
V_1 -> V_261 = 0 ;
}
V_189 -> V_253 = V_23 ;
V_189 -> V_262 = V_222 [ clock ] ;
F_33 ( L_30 ,
V_1 -> V_203 , V_1 -> V_241 ,
V_189 -> V_262 , V_23 ) ;
F_33 ( L_31 ,
V_34 , V_246 ) ;
F_138 ( V_23 , V_241 ,
V_237 -> V_252 ,
V_189 -> V_262 ,
& V_189 -> V_263 ) ;
if ( V_29 -> V_31 . V_264 != NULL &&
V_51 -> V_265 . type == V_266 ) {
V_189 -> V_249 = true ;
F_138 ( V_23 , V_241 ,
V_29 -> V_31 . V_264 -> clock ,
V_189 -> V_262 ,
& V_189 -> V_267 ) ;
}
if ( F_116 ( V_7 ) && F_1 ( V_1 ) )
F_110 ( V_189 , V_222 [ clock ] ) ;
else if ( F_139 ( V_7 ) )
;
else if ( F_103 ( V_7 ) || F_87 ( V_7 ) )
F_113 ( V_189 , V_1 -> V_203 ) ;
else
F_122 ( V_65 , V_189 , V_1 -> V_203 ) ;
return true ;
}
static void F_140 ( struct V_1 * V_1 )
{
struct V_2 * V_268 = F_2 ( V_1 ) ;
struct V_238 * V_239 = F_131 ( V_268 -> V_4 . V_4 . V_239 ) ;
struct V_6 * V_7 = V_239 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_269 ;
F_33 ( L_32 ,
V_239 -> V_270 -> V_262 ) ;
V_269 = F_22 ( V_271 ) ;
V_269 &= ~ V_272 ;
if ( V_239 -> V_270 -> V_262 == 162000 ) {
F_33 ( L_33 ) ;
V_269 |= V_273 ;
V_1 -> V_72 |= V_273 ;
} else {
V_269 |= V_274 ;
V_1 -> V_72 |= V_274 ;
}
F_39 ( V_271 , V_269 ) ;
F_40 ( V_271 ) ;
F_141 ( 500 ) ;
}
static void F_142 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_238 * V_239 = F_131 ( V_65 -> V_4 . V_239 ) ;
struct V_27 * V_237 = & V_239 -> V_270 -> V_4 . V_237 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) & V_75 ;
V_1 -> V_72 |= V_76 | V_77 ;
V_1 -> V_72 |= F_34 ( V_1 -> V_241 ) ;
if ( V_239 -> V_270 -> V_250 )
V_1 -> V_72 |= V_275 ;
if ( F_143 ( V_7 ) && V_18 == V_19 ) {
if ( V_237 -> V_40 & V_276 )
V_1 -> V_72 |= V_277 ;
if ( V_237 -> V_40 & V_278 )
V_1 -> V_72 |= V_279 ;
V_1 -> V_72 |= V_280 ;
if ( F_144 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_281 ;
V_1 -> V_72 |= V_239 -> V_69 << 29 ;
} else if ( F_145 ( V_7 ) && V_18 != V_19 ) {
T_5 V_282 ;
V_1 -> V_72 |= V_280 ;
V_282 = F_22 ( F_146 ( V_239 -> V_69 ) ) ;
if ( F_144 ( V_1 -> V_11 ) )
V_282 |= V_283 ;
else
V_282 &= ~ V_283 ;
F_39 ( F_146 ( V_239 -> V_69 ) , V_282 ) ;
} else {
if ( ! F_61 ( V_7 ) && ! F_21 ( V_7 ) )
V_1 -> V_72 |= V_1 -> V_258 ;
if ( V_237 -> V_40 & V_276 )
V_1 -> V_72 |= V_277 ;
if ( V_237 -> V_40 & V_278 )
V_1 -> V_72 |= V_279 ;
V_1 -> V_72 |= V_284 ;
if ( F_144 ( V_1 -> V_11 ) )
V_1 -> V_72 |= V_281 ;
if ( F_35 ( V_7 ) )
V_1 -> V_72 |= F_36 ( V_239 -> V_69 ) ;
else if ( V_239 -> V_69 == V_79 )
V_1 -> V_72 |= V_80 ;
}
}
static void F_147 ( struct V_1 * V_1 ,
T_5 V_285 ,
T_5 V_286 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_287 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
V_287 = F_62 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_33 ( L_34 ,
V_285 , V_286 ,
F_22 ( V_287 ) ,
F_22 ( V_102 ) ) ;
if ( F_148 ( ( F_22 ( V_287 ) & V_285 ) == V_286 , 5000 , 10 ) ) {
F_76 ( L_35 ,
F_22 ( V_287 ) ,
F_22 ( V_102 ) ) ;
}
F_33 ( L_36 ) ;
}
static void F_149 ( struct V_1 * V_1 )
{
F_33 ( L_37 ) ;
F_147 ( V_1 , V_288 , V_289 ) ;
}
static void F_150 ( struct V_1 * V_1 )
{
F_33 ( L_38 ) ;
F_147 ( V_1 , V_290 , V_291 ) ;
}
static void F_151 ( struct V_1 * V_1 )
{
F_33 ( L_39 ) ;
F_152 ( V_1 -> V_292 ,
V_1 -> V_108 ) ;
F_147 ( V_1 , V_293 , V_294 ) ;
}
static void F_153 ( struct V_1 * V_1 )
{
F_152 ( V_1 -> V_295 ,
V_1 -> V_296 ) ;
}
static void F_154 ( struct V_1 * V_1 )
{
F_152 ( V_1 -> V_297 ,
V_1 -> V_298 ) ;
}
static T_5 F_155 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_299 ;
F_43 ( & V_51 -> V_68 ) ;
V_299 = F_22 ( F_60 ( V_1 ) ) ;
V_299 &= ~ V_300 ;
V_299 |= V_106 ;
return V_299 ;
}
static bool F_92 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_301 ;
T_5 V_287 , V_102 ;
bool V_302 = ! V_1 -> V_303 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_156 ( & V_1 -> V_304 ) ;
V_1 -> V_303 = true ;
if ( F_69 ( V_1 ) )
return V_302 ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
F_33 ( L_40 ,
F_32 ( V_3 -> V_18 ) ) ;
if ( ! F_68 ( V_1 ) )
F_151 ( V_1 ) ;
V_301 = F_155 ( V_1 ) ;
V_301 |= V_90 ;
V_287 = F_62 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
F_33 ( L_41 ,
F_22 ( V_287 ) , F_22 ( V_102 ) ) ;
if ( ! F_68 ( V_1 ) ) {
F_33 ( L_42 ,
F_32 ( V_3 -> V_18 ) ) ;
F_67 ( V_1 -> V_305 ) ;
}
return V_302 ;
}
void F_157 ( struct V_1 * V_1 )
{
bool V_143 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_143 = F_92 ( V_1 ) ;
F_27 ( V_1 ) ;
F_158 ( ! V_143 , L_43 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
}
static void F_159 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
enum V_66 V_67 ;
T_5 V_301 ;
T_5 V_287 , V_102 ;
F_43 ( & V_51 -> V_68 ) ;
F_44 ( V_1 -> V_303 ) ;
if ( ! F_69 ( V_1 ) )
return;
F_33 ( L_44 ,
F_32 ( V_3 -> V_18 ) ) ;
V_301 = F_155 ( V_1 ) ;
V_301 &= ~ V_90 ;
V_102 = F_60 ( V_1 ) ;
V_287 = F_62 ( V_1 ) ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
F_33 ( L_41 ,
F_22 ( V_287 ) , F_22 ( V_102 ) ) ;
if ( ( V_301 & V_306 ) == 0 )
V_1 -> V_292 = V_307 ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
static void F_160 ( struct V_308 * V_309 )
{
struct V_1 * V_1 = F_64 ( F_161 ( V_309 ) ,
struct V_1 , V_304 ) ;
F_23 ( V_1 ) ;
if ( ! V_1 -> V_303 )
F_159 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_162 ( struct V_1 * V_1 )
{
unsigned long V_310 ;
V_310 = F_163 ( V_1 -> V_108 * 5 ) ;
F_164 ( & V_1 -> V_304 , V_310 ) ;
}
static void F_98 ( struct V_1 * V_1 , bool V_311 )
{
struct V_50 * V_51 =
F_3 ( V_1 ) -> V_52 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_158 ( ! V_1 -> V_303 , L_45 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_1 -> V_303 = false ;
if ( V_311 )
F_159 ( V_1 ) ;
else
F_162 ( V_1 ) ;
}
static void F_165 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_301 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_46 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
if ( F_8 ( F_68 ( V_1 ) ,
L_47 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) )
return;
F_151 ( V_1 ) ;
V_102 = F_60 ( V_1 ) ;
V_301 = F_155 ( V_1 ) ;
if ( F_166 ( V_7 ) ) {
V_301 &= ~ V_312 ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
}
V_301 |= V_306 ;
if ( ! F_166 ( V_7 ) )
V_301 |= V_312 ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
F_149 ( V_1 ) ;
V_1 -> V_295 = V_307 ;
if ( F_166 ( V_7 ) ) {
V_301 |= V_312 ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
}
}
void F_167 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_165 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_168 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_301 ;
T_5 V_102 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_48 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
F_8 ( ! V_1 -> V_303 , L_49 ,
F_32 ( F_2 ( V_1 ) -> V_18 ) ) ;
V_301 = F_155 ( V_1 ) ;
V_301 &= ~ ( V_306 | V_312 | V_90 |
V_313 ) ;
V_102 = F_60 ( V_1 ) ;
V_1 -> V_303 = false ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
V_1 -> V_292 = V_307 ;
F_150 ( V_1 ) ;
V_67 = F_24 ( V_64 ) ;
F_29 ( V_51 , V_67 ) ;
}
void F_169 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
F_168 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_170 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_301 ;
T_5 V_102 ;
F_153 ( V_1 ) ;
F_23 ( V_1 ) ;
V_301 = F_155 ( V_1 ) ;
V_301 |= V_313 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
}
void F_171 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_50 ) ;
F_172 ( V_1 -> V_240 ) ;
F_170 ( V_1 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_301 ;
T_5 V_102 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( V_1 ) ;
V_301 = F_155 ( V_1 ) ;
V_301 &= ~ V_313 ;
V_102 = F_60 ( V_1 ) ;
F_39 ( V_102 , V_301 ) ;
F_40 ( V_102 ) ;
F_27 ( V_1 ) ;
V_1 -> V_297 = V_307 ;
F_154 ( V_1 ) ;
}
void F_174 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_50 ) ;
F_173 ( V_1 ) ;
F_175 ( V_1 -> V_240 ) ;
}
static void F_176 ( struct V_29 * V_9 ,
bool V_314 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_315 ;
F_23 ( V_1 ) ;
V_315 = F_155 ( V_1 ) & V_313 ;
F_27 ( V_1 ) ;
if ( V_315 == V_314 )
return;
F_33 ( L_51 ,
V_314 ? L_52 : L_53 ) ;
if ( V_314 )
F_170 ( V_1 ) ;
else
F_173 ( V_1 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_316 * V_239 = V_3 -> V_4 . V_4 . V_239 ;
struct V_6 * V_7 = V_239 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_269 ;
F_178 ( V_51 ,
F_131 ( V_239 ) -> V_69 ) ;
F_33 ( L_50 ) ;
V_269 = F_22 ( V_271 ) ;
F_8 ( V_269 & V_317 , L_54 ) ;
F_8 ( V_269 & V_74 , L_55 ) ;
V_1 -> V_72 &= ~ ( V_74 | V_275 ) ;
V_1 -> V_72 |= V_317 ;
F_39 ( V_271 , V_1 -> V_72 ) ;
F_40 ( V_271 ) ;
F_141 ( 200 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_316 * V_239 = V_3 -> V_4 . V_4 . V_239 ;
struct V_6 * V_7 = V_239 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_269 ;
F_178 ( V_51 ,
F_131 ( V_239 ) -> V_69 ) ;
V_269 = F_22 ( V_271 ) ;
F_8 ( ( V_269 & V_317 ) == 0 ,
L_56 ) ;
F_8 ( V_269 & V_74 , L_55 ) ;
V_269 &= ~ V_317 ;
F_39 ( V_271 , V_269 ) ;
F_40 ( V_271 ) ;
F_141 ( 200 ) ;
}
void F_180 ( struct V_1 * V_1 , int V_28 )
{
int V_140 , V_46 ;
if ( V_1 -> V_11 [ V_318 ] < 0x11 )
return;
if ( V_28 != V_319 ) {
V_140 = F_181 ( & V_1 -> V_156 , V_320 ,
V_321 ) ;
} else {
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_140 = F_181 ( & V_1 -> V_156 , V_320 ,
V_322 ) ;
if ( V_140 == 1 )
break;
F_67 ( 1 ) ;
}
}
if ( V_140 != 1 )
F_33 ( L_57 ,
V_28 == V_319 ? L_52 : L_53 ) ;
}
static bool F_182 ( struct V_64 * V_65 ,
enum V_69 * V_69 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
T_5 V_88 ;
V_67 = F_24 ( V_65 ) ;
if ( ! F_183 ( V_51 , V_67 ) )
return false ;
V_88 = F_22 ( V_1 -> V_73 ) ;
if ( ! ( V_88 & V_74 ) )
return false ;
if ( F_143 ( V_7 ) && V_18 == V_19 ) {
* V_69 = F_184 ( V_88 ) ;
} else if ( F_145 ( V_7 ) && V_18 != V_19 ) {
enum V_69 V_323 ;
F_185 (dev_priv, p) {
T_5 V_282 = F_22 ( F_146 ( V_323 ) ) ;
if ( F_186 ( V_282 ) == V_18 ) {
* V_69 = V_323 ;
return true ;
}
}
F_33 ( L_58 ,
V_1 -> V_73 ) ;
} else if ( F_35 ( V_7 ) ) {
* V_69 = F_187 ( V_88 ) ;
} else {
* V_69 = F_188 ( V_88 ) ;
}
return true ;
}
static void F_189 ( struct V_64 * V_65 ,
struct V_188 * V_189 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
T_5 V_88 , V_40 = 0 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
struct V_238 * V_239 = F_131 ( V_65 -> V_4 . V_239 ) ;
int V_324 ;
V_88 = F_22 ( V_1 -> V_73 ) ;
V_189 -> V_250 = V_88 & V_275 && V_18 != V_19 ;
if ( F_145 ( V_7 ) && V_18 != V_19 ) {
V_88 = F_22 ( F_146 ( V_239 -> V_69 ) ) ;
if ( V_88 & V_325 )
V_40 |= V_276 ;
else
V_40 |= V_326 ;
if ( V_88 & V_327 )
V_40 |= V_278 ;
else
V_40 |= V_328 ;
} else {
if ( V_88 & V_277 )
V_40 |= V_276 ;
else
V_40 |= V_326 ;
if ( V_88 & V_279 )
V_40 |= V_278 ;
else
V_40 |= V_328 ;
}
V_189 -> V_4 . V_237 . V_40 |= V_40 ;
if ( ! F_61 ( V_7 ) && ! F_21 ( V_7 ) &&
V_88 & V_259 )
V_189 -> V_260 = true ;
V_189 -> V_248 = true ;
F_190 ( V_239 , V_189 ) ;
if ( V_18 == V_19 ) {
if ( ( F_22 ( V_271 ) & V_272 ) == V_273 )
V_189 -> V_262 = 162000 ;
else
V_189 -> V_262 = 270000 ;
}
V_324 = F_191 ( V_189 -> V_262 ,
& V_189 -> V_263 ) ;
if ( F_61 ( V_51 -> V_7 ) && V_18 != V_19 )
F_192 ( V_189 , V_324 ) ;
V_189 -> V_4 . V_237 . V_252 = V_324 ;
if ( F_1 ( V_1 ) && V_51 -> V_254 . V_255 &&
V_189 -> V_253 > V_51 -> V_254 . V_255 ) {
F_33 ( L_59 ,
V_189 -> V_253 , V_51 -> V_254 . V_255 ) ;
V_51 -> V_254 . V_255 = V_189 -> V_253 ;
}
}
static void F_193 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_238 * V_239 = F_131 ( V_65 -> V_4 . V_239 ) ;
if ( V_239 -> V_270 -> V_250 )
F_194 ( V_65 ) ;
if ( F_195 ( V_7 ) && ! F_10 ( V_7 ) )
F_196 ( V_1 ) ;
F_157 ( V_1 ) ;
F_174 ( V_1 ) ;
F_180 ( V_1 , V_329 ) ;
F_169 ( V_1 ) ;
if ( F_119 ( V_7 ) -> V_211 < 5 )
F_197 ( V_1 ) ;
}
static void F_198 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
F_197 ( V_1 ) ;
if ( V_18 == V_19 )
F_179 ( V_1 ) ;
}
static void F_199 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_197 ( V_1 ) ;
}
static void F_200 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_238 =
F_131 ( V_65 -> V_4 . V_239 ) ;
enum V_331 V_332 = F_201 ( V_330 ) ;
enum V_69 V_69 = V_238 -> V_69 ;
T_5 V_333 ;
F_197 ( V_1 ) ;
F_26 ( & V_51 -> V_334 ) ;
V_333 = F_202 ( V_51 , V_69 , F_203 ( V_332 ) ) ;
V_333 |= V_335 ;
F_204 ( V_51 , V_69 , F_203 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_205 ( V_332 ) ) ;
V_333 |= V_335 ;
F_204 ( V_51 , V_69 , F_205 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_206 ( V_332 ) ) ;
V_333 &= ~ ( V_336 | V_337 ) ;
F_204 ( V_51 , V_69 , F_206 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_207 ( V_332 ) ) ;
V_333 &= ~ ( V_336 | V_337 ) ;
F_204 ( V_51 , V_69 , F_207 ( V_332 ) , V_333 ) ;
F_28 ( & V_51 -> V_334 ) ;
}
static void
F_208 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_338 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
if ( F_10 ( V_7 ) ) {
T_2 V_339 = F_22 ( F_209 ( V_18 ) ) ;
if ( V_338 & V_340 )
V_339 |= V_341 ;
else
V_339 &= ~ V_341 ;
V_339 &= ~ V_342 ;
switch ( V_338 & V_343 ) {
case V_344 :
V_339 |= V_345 ;
break;
case V_346 :
V_339 |= V_347 ;
break;
case V_348 :
V_339 |= V_349 ;
break;
case V_350 :
V_339 |= V_351 ;
break;
}
F_39 ( F_209 ( V_18 ) , V_339 ) ;
} else if ( ( F_143 ( V_7 ) && V_18 == V_19 ) ||
( F_145 ( V_7 ) && V_18 != V_19 ) ) {
* V_72 &= ~ V_352 ;
switch ( V_338 & V_343 ) {
case V_344 :
* V_72 |= V_280 ;
break;
case V_346 :
* V_72 |= V_353 ;
break;
case V_348 :
* V_72 |= V_354 ;
break;
case V_350 :
F_76 ( L_60 ) ;
* V_72 |= V_354 ;
break;
}
} else {
if ( F_35 ( V_7 ) )
* V_72 &= ~ V_355 ;
else
* V_72 &= ~ V_356 ;
switch ( V_338 & V_343 ) {
case V_344 :
* V_72 |= V_284 ;
break;
case V_346 :
* V_72 |= V_78 ;
break;
case V_348 :
* V_72 |= V_357 ;
break;
case V_350 :
if ( F_35 ( V_7 ) ) {
* V_72 |= V_358 ;
} else {
F_76 ( L_60 ) ;
* V_72 |= V_357 ;
}
break;
}
}
}
static void F_210 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
F_208 ( V_1 , & V_1 -> V_72 ,
V_346 ) ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_1 -> V_72 |= V_74 ;
F_39 ( V_1 -> V_73 , V_1 -> V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
static void F_211 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_239 = F_131 ( V_65 -> V_4 . V_239 ) ;
T_2 V_359 = F_22 ( V_1 -> V_73 ) ;
unsigned int V_360 = 0x0 ;
if ( F_44 ( V_359 & V_74 ) )
return;
F_23 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_212 ( V_1 ) ;
F_210 ( V_1 ) ;
F_92 ( V_1 ) ;
F_165 ( V_1 ) ;
F_98 ( V_1 , true ) ;
F_27 ( V_1 ) ;
if ( F_21 ( V_7 ) )
F_213 ( V_51 , F_2 ( V_1 ) ,
V_360 ) ;
F_180 ( V_1 , V_319 ) ;
F_214 ( V_1 ) ;
F_215 ( V_1 ) ;
F_216 ( V_1 ) ;
if ( V_239 -> V_270 -> V_250 ) {
F_217 ( L_61 ,
F_31 ( V_239 -> V_69 ) ) ;
F_218 ( V_65 ) ;
}
}
static void F_219 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_211 ( V_65 ) ;
F_171 ( V_1 ) ;
}
static void F_220 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
F_171 ( V_1 ) ;
F_221 ( V_1 ) ;
}
static void F_222 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
F_142 ( V_65 ) ;
if ( V_330 -> V_18 == V_19 ) {
F_140 ( V_1 ) ;
F_177 ( V_1 ) ;
}
}
static void F_223 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = V_3 -> V_4 . V_4 . V_7 -> V_52 ;
enum V_69 V_69 = V_1 -> V_70 ;
int V_361 = F_56 ( V_69 ) ;
F_159 ( V_1 ) ;
F_33 ( L_62 ,
F_31 ( V_69 ) , F_32 ( V_3 -> V_18 ) ) ;
F_39 ( V_361 , 0 ) ;
F_40 ( V_361 ) ;
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
F_33 ( L_63 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_8 ( V_65 -> V_362 ,
L_64 ,
F_31 ( V_69 ) , F_32 ( V_18 ) ) ;
F_223 ( V_1 ) ;
}
}
static void F_212 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_65 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_239 = F_131 ( V_65 -> V_4 . V_239 ) ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_70 == V_239 -> V_69 )
return;
if ( V_1 -> V_70 != V_87 )
F_223 ( V_1 ) ;
F_47 ( V_7 , V_239 -> V_69 ) ;
V_1 -> V_70 = V_239 -> V_69 ;
F_33 ( L_65 ,
F_31 ( V_1 -> V_70 ) , F_32 ( V_3 -> V_18 ) ) ;
F_48 ( V_7 , V_1 ) ;
F_49 ( V_7 , V_1 ) ;
}
static void F_224 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_238 = F_131 ( V_65 -> V_4 . V_239 ) ;
enum V_331 V_18 = F_201 ( V_330 ) ;
int V_69 = V_238 -> V_69 ;
T_5 V_333 ;
F_26 ( & V_51 -> V_334 ) ;
V_333 = F_202 ( V_51 , V_69 , F_225 ( V_18 ) ) ;
V_333 = 0 ;
if ( V_69 )
V_333 |= ( 1 << 21 ) ;
else
V_333 &= ~ ( 1 << 21 ) ;
V_333 |= 0x001000c4 ;
F_204 ( V_51 , V_69 , F_226 ( V_18 ) , V_333 ) ;
F_204 ( V_51 , V_69 , F_227 ( V_18 ) , 0x00760018 ) ;
F_204 ( V_51 , V_69 , F_228 ( V_18 ) , 0x00400888 ) ;
F_28 ( & V_51 -> V_334 ) ;
F_211 ( V_65 ) ;
}
static void F_229 ( struct V_64 * V_65 )
{
struct V_2 * V_330 = F_230 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_238 =
F_131 ( V_65 -> V_4 . V_239 ) ;
enum V_331 V_18 = F_201 ( V_330 ) ;
int V_69 = V_238 -> V_69 ;
F_142 ( V_65 ) ;
F_26 ( & V_51 -> V_334 ) ;
F_204 ( V_51 , V_69 , F_231 ( V_18 ) ,
V_336 |
V_337 ) ;
F_204 ( V_51 , V_69 , F_232 ( V_18 ) ,
V_363 |
V_364 |
( 1 << V_365 ) |
V_366 ) ;
F_204 ( V_51 , V_69 , F_233 ( V_18 ) , 0x00750f00 ) ;
F_204 ( V_51 , V_69 , F_234 ( V_18 ) , 0x00001500 ) ;
F_204 ( V_51 , V_69 , F_235 ( V_18 ) , 0x40400000 ) ;
F_28 ( & V_51 -> V_334 ) ;
}
static void F_236 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_5 ( & V_65 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_238 =
F_131 ( V_65 -> V_4 . V_239 ) ;
enum V_331 V_332 = F_201 ( V_330 ) ;
int V_69 = V_238 -> V_69 ;
int V_367 , V_46 , V_368 ;
T_5 V_333 ;
F_26 ( & V_51 -> V_334 ) ;
V_333 = F_202 ( V_51 , V_69 , F_237 ( V_332 ) ) ;
V_333 &= ~ V_369 ;
F_204 ( V_51 , V_69 , F_237 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_238 ( V_332 ) ) ;
V_333 &= ~ V_369 ;
F_204 ( V_51 , V_69 , F_238 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_203 ( V_332 ) ) ;
V_333 |= V_335 ;
F_204 ( V_51 , V_69 , F_203 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_205 ( V_332 ) ) ;
V_333 |= V_335 ;
F_204 ( V_51 , V_69 , F_205 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_206 ( V_332 ) ) ;
V_333 |= ( V_336 | V_337 ) ;
F_204 ( V_51 , V_69 , F_206 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_207 ( V_332 ) ) ;
V_333 |= ( V_336 | V_337 ) ;
F_204 ( V_51 , V_69 , F_207 ( V_332 ) , V_333 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_367 = ( V_46 == 1 ) ? 0x0 : 0x1 ;
F_204 ( V_51 , V_69 , F_239 ( V_332 , V_46 ) ,
V_367 << V_370 ) ;
}
if ( V_238 -> V_270 -> V_262 > 270000 )
V_368 = 0x18 ;
else if ( V_238 -> V_270 -> V_262 > 135000 )
V_368 = 0xd ;
else if ( V_238 -> V_270 -> V_262 > 67500 )
V_368 = 0x7 ;
else if ( V_238 -> V_270 -> V_262 > 33750 )
V_368 = 0x4 ;
else
V_368 = 0x2 ;
V_333 = F_202 ( V_51 , V_69 , F_237 ( V_332 ) ) ;
V_333 |= F_240 ( 0x1f ) ;
F_204 ( V_51 , V_69 , F_237 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_238 ( V_332 ) ) ;
V_333 |= F_240 ( 0x1f ) ;
F_204 ( V_51 , V_69 , F_238 ( V_332 ) , V_333 ) ;
F_204 ( V_51 , V_69 , F_241 ( V_332 ) ,
F_242 ( V_368 ) |
V_371 |
F_243 ( 0x1f ) |
F_244 ( 6 ) |
F_245 ( 0 ) ) ;
F_204 ( V_51 , V_69 , F_246 ( V_332 ) ,
F_242 ( V_368 ) |
V_371 |
F_243 ( 0x1f ) |
F_244 ( 7 ) |
F_245 ( 5 ) ) ;
F_28 ( & V_51 -> V_334 ) ;
F_211 ( V_65 ) ;
}
static void F_247 ( struct V_64 * V_65 )
{
struct V_2 * V_330 = F_230 ( & V_65 -> V_4 ) ;
struct V_6 * V_7 = V_65 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_238 * V_238 =
F_131 ( V_65 -> V_4 . V_239 ) ;
enum V_331 V_332 = F_201 ( V_330 ) ;
enum V_69 V_69 = V_238 -> V_69 ;
T_5 V_333 ;
F_142 ( V_65 ) ;
F_26 ( & V_51 -> V_334 ) ;
if ( V_69 != V_79 ) {
V_333 = F_202 ( V_51 , V_69 , V_372 ) ;
V_333 &= ~ ( V_373 | V_374 ) ;
if ( V_332 == V_375 )
V_333 |= V_376 ;
if ( V_332 == V_377 )
V_333 |= V_378 ;
F_204 ( V_51 , V_69 , V_372 , V_333 ) ;
} else {
V_333 = F_202 ( V_51 , V_69 , V_379 ) ;
V_333 &= ~ ( V_380 | V_381 ) ;
if ( V_332 == V_375 )
V_333 |= V_382 ;
if ( V_332 == V_377 )
V_333 |= V_383 ;
F_204 ( V_51 , V_69 , V_379 , V_333 ) ;
}
V_333 = F_202 ( V_51 , V_69 , F_225 ( V_332 ) ) ;
V_333 |= V_384 ;
if ( V_69 != V_79 )
V_333 &= ~ V_385 ;
else
V_333 |= V_385 ;
F_204 ( V_51 , V_69 , F_225 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_248 ( V_332 ) ) ;
V_333 |= V_384 ;
if ( V_69 != V_79 )
V_333 &= ~ V_385 ;
else
V_333 |= V_385 ;
F_204 ( V_51 , V_69 , F_248 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_249 ( V_332 ) ) ;
if ( V_69 != V_79 )
V_333 &= ~ V_386 ;
else
V_333 |= V_386 ;
F_204 ( V_51 , V_69 , F_249 ( V_332 ) , V_333 ) ;
F_28 ( & V_51 -> V_334 ) ;
}
static T_6
F_250 ( struct V_155 * V_156 , unsigned int V_387 ,
void * V_171 , T_7 V_165 )
{
T_6 V_140 ;
int V_46 ;
F_251 ( V_156 , V_318 , V_171 , 1 ) ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_140 = F_251 ( V_156 , V_387 , V_171 , V_165 ) ;
if ( V_140 == V_165 )
return V_140 ;
F_67 ( 1 ) ;
}
return V_140 ;
}
static bool
F_252 ( struct V_1 * V_1 , T_3 V_388 [ V_389 ] )
{
return F_250 ( & V_1 -> V_156 ,
V_390 ,
V_388 ,
V_389 ) == V_389 ;
}
static T_3
F_253 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_139 ( V_7 ) )
return V_391 ;
else if ( F_119 ( V_7 ) -> V_211 >= 9 ) {
if ( V_51 -> V_392 && V_18 == V_19 )
return V_391 ;
return V_393 ;
} else if ( F_21 ( V_7 ) )
return V_391 ;
else if ( F_143 ( V_7 ) && V_18 == V_19 )
return V_393 ;
else if ( F_145 ( V_7 ) && V_18 != V_19 )
return V_391 ;
else
return V_393 ;
}
static T_3
F_254 ( struct V_1 * V_1 , T_3 V_394 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
if ( F_119 ( V_7 ) -> V_211 >= 9 ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
return V_401 ;
default:
return V_401 ;
}
} else if ( F_103 ( V_7 ) || F_87 ( V_7 ) ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
} else if ( F_21 ( V_7 ) ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
} else if ( F_143 ( V_7 ) && V_18 == V_19 ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_399 ;
case V_398 :
case V_393 :
return V_400 ;
default:
return V_401 ;
}
} else {
switch ( V_394 & V_395 ) {
case V_396 :
return V_399 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
}
}
static T_2 F_255 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_238 * V_238 =
F_131 ( V_330 -> V_4 . V_4 . V_239 ) ;
unsigned long V_402 , V_403 ,
V_404 ;
T_3 V_405 = V_1 -> V_405 [ 0 ] ;
enum V_331 V_18 = F_201 ( V_330 ) ;
int V_69 = V_238 -> V_69 ;
switch ( V_405 & V_406 ) {
case V_401 :
V_403 = 0x0004000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B405555 ;
V_404 = 0x552AB83A ;
break;
case V_398 :
V_402 = 0x2B404040 ;
V_404 = 0x5548B83A ;
break;
case V_393 :
V_402 = 0x2B245555 ;
V_404 = 0x5560B83A ;
break;
case V_391 :
V_402 = 0x2B405555 ;
V_404 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_400 :
V_403 = 0x0002000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B404040 ;
V_404 = 0x5552B83A ;
break;
case V_398 :
V_402 = 0x2B404848 ;
V_404 = 0x5580B83A ;
break;
case V_393 :
V_402 = 0x2B404040 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_399 :
V_403 = 0x0000000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B305555 ;
V_404 = 0x5570B83A ;
break;
case V_398 :
V_402 = 0x2B2B4040 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_397 :
V_403 = 0x0006000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x1B405555 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_334 ) ;
F_204 ( V_51 , V_69 , F_256 ( V_18 ) , 0x00000000 ) ;
F_204 ( V_51 , V_69 , F_257 ( V_18 ) , V_402 ) ;
F_204 ( V_51 , V_69 , F_258 ( V_18 ) ,
V_404 ) ;
F_204 ( V_51 , V_69 , F_259 ( V_18 ) , 0x0C782040 ) ;
F_204 ( V_51 , V_69 , F_260 ( V_18 ) , 0x00030000 ) ;
F_204 ( V_51 , V_69 , F_261 ( V_18 ) , V_403 ) ;
F_204 ( V_51 , V_69 , F_256 ( V_18 ) , 0x80000000 ) ;
F_28 ( & V_51 -> V_334 ) ;
return 0 ;
}
static T_2 F_262 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_238 * V_238 = F_131 ( V_330 -> V_4 . V_4 . V_239 ) ;
T_5 V_407 , V_408 , V_333 ;
T_3 V_405 = V_1 -> V_405 [ 0 ] ;
enum V_331 V_332 = F_201 ( V_330 ) ;
enum V_69 V_69 = V_238 -> V_69 ;
int V_46 ;
switch ( V_405 & V_406 ) {
case V_401 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 128 ;
V_408 = 52 ;
break;
case V_398 :
V_407 = 128 ;
V_408 = 77 ;
break;
case V_393 :
V_407 = 128 ;
V_408 = 102 ;
break;
case V_391 :
V_407 = 128 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
case V_400 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 85 ;
V_408 = 78 ;
break;
case V_398 :
V_407 = 85 ;
V_408 = 116 ;
break;
case V_393 :
V_407 = 85 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
case V_399 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 64 ;
V_408 = 104 ;
break;
case V_398 :
V_407 = 64 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
case V_397 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 43 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_26 ( & V_51 -> V_334 ) ;
V_333 = F_202 ( V_51 , V_69 , F_263 ( V_332 ) ) ;
V_333 &= ~ ( V_409 | V_410 ) ;
V_333 &= ~ ( V_411 | V_412 ) ;
V_333 |= V_413 | V_414 ;
F_204 ( V_51 , V_69 , F_263 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_264 ( V_332 ) ) ;
V_333 &= ~ ( V_409 | V_410 ) ;
V_333 &= ~ ( V_411 | V_412 ) ;
V_333 |= V_413 | V_414 ;
F_204 ( V_51 , V_69 , F_264 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_265 ( V_332 ) ) ;
V_333 &= ~ ( V_415 | V_416 ) ;
V_333 |= V_417 | V_418 ;
F_204 ( V_51 , V_69 , F_265 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_266 ( V_332 ) ) ;
V_333 &= ~ ( V_415 | V_416 ) ;
V_333 |= V_417 | V_418 ;
F_204 ( V_51 , V_69 , F_266 ( V_332 ) , V_333 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_333 = F_202 ( V_51 , V_69 , F_267 ( V_332 , V_46 ) ) ;
V_333 &= ~ V_419 ;
V_333 |= V_407 << V_420 ;
F_204 ( V_51 , V_69 , F_267 ( V_332 , V_46 ) , V_333 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_333 = F_202 ( V_51 , V_69 , F_268 ( V_332 , V_46 ) ) ;
V_333 &= ~ V_421 ;
V_333 |= V_408 << V_422 ;
F_204 ( V_51 , V_69 , F_268 ( V_332 , V_46 ) , V_333 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_333 = F_202 ( V_51 , V_69 , F_269 ( V_332 , V_46 ) ) ;
V_333 &= ~ V_423 ;
F_204 ( V_51 , V_69 , F_269 ( V_332 , V_46 ) , V_333 ) ;
}
if ( ( ( V_405 & V_406 )
== V_401 ) &&
( ( V_405 & V_395 )
== V_391 ) ) {
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_333 = F_202 ( V_51 , V_69 , F_269 ( V_332 , V_46 ) ) ;
V_333 |= V_423 ;
F_204 ( V_51 , V_69 , F_269 ( V_332 , V_46 ) , V_333 ) ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_333 = F_202 ( V_51 , V_69 , F_268 ( V_332 , V_46 ) ) ;
V_333 &= ~ ( 0xff << V_424 ) ;
V_333 |= ( 0x9a << V_424 ) ;
F_204 ( V_51 , V_69 , F_268 ( V_332 , V_46 ) , V_333 ) ;
}
}
V_333 = F_202 ( V_51 , V_69 , F_263 ( V_332 ) ) ;
V_333 |= V_409 | V_410 ;
F_204 ( V_51 , V_69 , F_263 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , F_264 ( V_332 ) ) ;
V_333 |= V_409 | V_410 ;
F_204 ( V_51 , V_69 , F_264 ( V_332 ) , V_333 ) ;
V_333 = F_202 ( V_51 , V_69 , V_425 ) ;
V_333 |= V_426 ;
F_204 ( V_51 , V_69 , V_425 , V_333 ) ;
F_28 ( & V_51 -> V_334 ) ;
return 0 ;
}
static void
F_270 ( struct V_1 * V_1 ,
const T_3 V_388 [ V_389 ] )
{
T_3 V_47 = 0 ;
T_3 V_323 = 0 ;
int V_427 ;
T_3 V_428 ;
T_3 V_429 ;
for ( V_427 = 0 ; V_427 < V_1 -> V_241 ; V_427 ++ ) {
T_3 V_430 = F_271 ( V_388 , V_427 ) ;
T_3 V_431 = F_272 ( V_388 , V_427 ) ;
if ( V_430 > V_47 )
V_47 = V_430 ;
if ( V_431 > V_323 )
V_323 = V_431 ;
}
V_428 = F_253 ( V_1 ) ;
if ( V_47 >= V_428 )
V_47 = V_428 | V_432 ;
V_429 = F_254 ( V_1 , V_47 ) ;
if ( V_323 >= V_429 )
V_323 = V_429 | V_433 ;
for ( V_427 = 0 ; V_427 < 4 ; V_427 ++ )
V_1 -> V_405 [ V_427 ] = V_47 | V_323 ;
}
static T_2
F_273 ( T_3 V_405 )
{
T_2 V_434 = 0 ;
switch ( V_405 & V_395 ) {
case V_396 :
default:
V_434 |= V_76 ;
break;
case V_398 :
V_434 |= V_435 ;
break;
case V_393 :
V_434 |= V_436 ;
break;
case V_391 :
V_434 |= V_437 ;
break;
}
switch ( V_405 & V_406 ) {
case V_401 :
default:
V_434 |= V_77 ;
break;
case V_400 :
V_434 |= V_438 ;
break;
case V_399 :
V_434 |= V_439 ;
break;
case V_397 :
V_434 |= V_440 ;
break;
}
return V_434 ;
}
static T_2
F_274 ( T_3 V_405 )
{
int V_434 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_434 ) {
case V_396 | V_401 :
case V_398 | V_401 :
return V_441 ;
case V_396 | V_400 :
return V_442 ;
case V_396 | V_399 :
case V_398 | V_399 :
return V_443 ;
case V_398 | V_400 :
case V_393 | V_400 :
return V_444 ;
case V_393 | V_401 :
case V_391 | V_401 :
return V_445 ;
default:
F_33 ( L_66
L_67 , V_434 ) ;
return V_441 ;
}
}
static T_2
F_275 ( T_3 V_405 )
{
int V_434 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_434 ) {
case V_396 | V_401 :
return V_446 ;
case V_396 | V_400 :
return V_447 ;
case V_396 | V_399 :
return V_448 ;
case V_398 | V_401 :
return V_449 ;
case V_398 | V_400 :
return V_450 ;
case V_393 | V_401 :
return V_451 ;
case V_393 | V_400 :
return V_452 ;
default:
F_33 ( L_66
L_67 , V_434 ) ;
return V_453 ;
}
}
static T_2
F_276 ( T_3 V_405 )
{
int V_434 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_434 ) {
case V_396 | V_401 :
return F_277 ( 0 ) ;
case V_396 | V_400 :
return F_277 ( 1 ) ;
case V_396 | V_399 :
return F_277 ( 2 ) ;
case V_396 | V_397 :
return F_277 ( 3 ) ;
case V_398 | V_401 :
return F_277 ( 4 ) ;
case V_398 | V_400 :
return F_277 ( 5 ) ;
case V_398 | V_399 :
return F_277 ( 6 ) ;
case V_393 | V_401 :
return F_277 ( 7 ) ;
case V_393 | V_400 :
return F_277 ( 8 ) ;
case V_391 | V_401 :
return F_277 ( 9 ) ;
default:
F_33 ( L_66
L_67 , V_434 ) ;
return F_277 ( 0 ) ;
}
}
static void F_278 ( struct V_1 * V_1 )
{
struct V_2 * V_330 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_330 -> V_18 ;
struct V_6 * V_7 = V_330 -> V_4 . V_4 . V_7 ;
struct V_64 * V_65 = & V_330 -> V_4 ;
T_3 V_405 = V_1 -> V_405 [ 0 ] ;
T_2 V_454 = 0 ;
int V_434 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_434 ) {
default:
F_33 ( L_68 ) ;
case V_396 | V_401 :
V_454 = 0 ;
break;
case V_396 | V_400 :
V_454 = 1 ;
break;
case V_396 | V_399 :
V_454 = 2 ;
break;
case V_396 | V_397 :
V_454 = 3 ;
break;
case V_398 | V_401 :
V_454 = 4 ;
break;
case V_398 | V_400 :
V_454 = 5 ;
break;
case V_398 | V_399 :
V_454 = 6 ;
break;
case V_393 | V_401 :
V_454 = 7 ;
break;
case V_393 | V_400 :
V_454 = 8 ;
break;
case V_391 | V_401 :
V_454 = 9 ;
break;
}
F_279 ( V_7 , V_454 , V_18 , V_65 -> type ) ;
}
static void
F_280 ( struct V_1 * V_1 , T_2 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_434 , V_285 ;
T_3 V_405 = V_1 -> V_405 [ 0 ] ;
if ( F_139 ( V_7 ) ) {
V_434 = 0 ;
F_278 ( V_1 ) ;
V_285 = 0 ;
} else if ( F_10 ( V_7 ) ) {
V_434 = F_276 ( V_405 ) ;
V_285 = V_455 ;
} else if ( F_35 ( V_7 ) ) {
V_434 = F_262 ( V_1 ) ;
V_285 = 0 ;
} else if ( F_21 ( V_7 ) ) {
V_434 = F_255 ( V_1 ) ;
V_285 = 0 ;
} else if ( F_143 ( V_7 ) && V_18 == V_19 ) {
V_434 = F_275 ( V_405 ) ;
V_285 = V_456 ;
} else if ( F_86 ( V_7 ) && V_18 == V_19 ) {
V_434 = F_274 ( V_405 ) ;
V_285 = V_457 ;
} else {
V_434 = F_273 ( V_405 ) ;
V_285 = V_458 | V_459 ;
}
if ( V_285 )
F_33 ( L_69 , V_434 ) ;
F_33 ( L_70 ,
V_405 & V_395 ) ;
F_33 ( L_71 ,
( V_405 & V_406 ) >>
V_460 ) ;
* V_72 = ( * V_72 & ~ V_285 ) | V_434 ;
}
static bool
F_281 ( struct V_1 * V_1 ,
T_2 * V_72 ,
T_3 V_338 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_461 [ sizeof( V_1 -> V_405 ) + 1 ] ;
int V_140 , V_227 ;
F_208 ( V_1 , V_72 , V_338 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_461 [ 0 ] = V_338 ;
if ( ( V_338 & V_343 ) ==
V_344 ) {
V_227 = 1 ;
} else {
memcpy ( V_461 + 1 , V_1 -> V_405 , V_1 -> V_241 ) ;
V_227 = V_1 -> V_241 + 1 ;
}
V_140 = F_282 ( & V_1 -> V_156 , V_462 ,
V_461 , V_227 ) ;
return V_140 == V_227 ;
}
static bool
F_283 ( struct V_1 * V_1 , T_2 * V_72 ,
T_3 V_338 )
{
if ( ! V_1 -> V_463 )
memset ( V_1 -> V_405 , 0 , sizeof( V_1 -> V_405 ) ) ;
F_280 ( V_1 , V_72 ) ;
return F_281 ( V_1 , V_72 , V_338 ) ;
}
static bool
F_284 ( struct V_1 * V_1 , T_2 * V_72 ,
const T_3 V_388 [ V_389 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
int V_140 ;
F_270 ( V_1 , V_388 ) ;
F_280 ( V_1 , V_72 ) ;
F_39 ( V_1 -> V_73 , * V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_140 = F_282 ( & V_1 -> V_156 , V_464 ,
V_1 -> V_405 , V_1 -> V_241 ) ;
return V_140 == V_1 -> V_241 ;
}
static void F_285 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
T_2 V_333 ;
if ( ! F_10 ( V_7 ) )
return;
V_333 = F_22 ( F_209 ( V_18 ) ) ;
V_333 &= ~ V_342 ;
V_333 |= V_465 ;
F_39 ( F_209 ( V_18 ) , V_333 ) ;
if ( V_18 == V_19 )
return;
if ( F_286 ( ( F_22 ( F_287 ( V_18 ) ) & V_466 ) ,
1 ) )
F_76 ( L_72 ) ;
}
void
F_214 ( struct V_1 * V_1 )
{
struct V_467 * V_65 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_65 -> V_7 ;
int V_46 ;
T_3 V_468 ;
int V_469 , V_470 ;
T_2 V_72 = V_1 -> V_72 ;
T_3 V_471 [ 2 ] ;
if ( F_10 ( V_7 ) )
F_288 ( V_65 ) ;
V_471 [ 0 ] = V_1 -> V_203 ;
V_471 [ 1 ] = V_1 -> V_241 ;
if ( F_144 ( V_1 -> V_11 ) )
V_471 [ 1 ] |= V_472 ;
F_282 ( & V_1 -> V_156 , V_473 , V_471 , 2 ) ;
if ( V_1 -> V_208 )
F_282 ( & V_1 -> V_156 , V_474 ,
& V_1 -> V_261 , 1 ) ;
V_471 [ 0 ] = 0 ;
V_471 [ 1 ] = V_475 ;
F_282 ( & V_1 -> V_156 , V_476 , V_471 , 2 ) ;
V_72 |= V_74 ;
if ( ! F_283 ( V_1 , & V_72 ,
V_346 |
V_340 ) ) {
F_76 ( L_73 ) ;
return;
}
V_468 = 0xff ;
V_469 = 0 ;
V_470 = 0 ;
for (; ; ) {
T_3 V_388 [ V_389 ] ;
F_289 ( V_1 -> V_11 ) ;
if ( ! F_252 ( V_1 , V_388 ) ) {
F_76 ( L_74 ) ;
break;
}
if ( F_290 ( V_388 , V_1 -> V_241 ) ) {
F_33 ( L_75 ) ;
break;
}
if ( V_1 -> V_463 ) {
F_33 ( L_76 ) ;
V_1 -> V_463 = false ;
if ( ! F_283 ( V_1 , & V_72 ,
V_346 |
V_340 ) ) {
F_76 ( L_73 ) ;
return;
}
continue;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_241 ; V_46 ++ )
if ( ( V_1 -> V_405 [ V_46 ] & V_432 ) == 0 )
break;
if ( V_46 == V_1 -> V_241 ) {
++ V_470 ;
if ( V_470 == 5 ) {
F_76 ( L_77 ) ;
break;
}
F_283 ( V_1 , & V_72 ,
V_346 |
V_340 ) ;
V_469 = 0 ;
continue;
}
if ( ( V_1 -> V_405 [ 0 ] & V_395 ) == V_468 ) {
++ V_469 ;
if ( V_469 == 5 ) {
F_76 ( L_78 ) ;
break;
}
} else
V_469 = 0 ;
V_468 = V_1 -> V_405 [ 0 ] & V_395 ;
if ( ! F_284 ( V_1 , & V_72 , V_388 ) ) {
F_76 ( L_79 ) ;
break;
}
}
V_1 -> V_72 = V_72 ;
}
void
F_215 ( struct V_1 * V_1 )
{
bool V_477 = false ;
int V_478 , V_479 ;
T_2 V_72 = V_1 -> V_72 ;
T_2 V_480 = V_348 ;
if ( V_1 -> V_203 == V_15 || V_1 -> V_481 )
V_480 = V_350 ;
if ( ! F_281 ( V_1 , & V_72 ,
V_480 |
V_340 ) ) {
F_76 ( L_80 ) ;
return;
}
V_478 = 0 ;
V_479 = 0 ;
V_477 = false ;
for (; ; ) {
T_3 V_388 [ V_389 ] ;
if ( V_479 > 5 ) {
F_76 ( L_81 ) ;
break;
}
F_291 ( V_1 -> V_11 ) ;
if ( ! F_252 ( V_1 , V_388 ) ) {
F_76 ( L_74 ) ;
break;
}
if ( ! F_290 ( V_388 , V_1 -> V_241 ) ) {
V_1 -> V_463 = false ;
F_214 ( V_1 ) ;
F_281 ( V_1 , & V_72 ,
V_480 |
V_340 ) ;
V_479 ++ ;
continue;
}
if ( F_292 ( V_388 , V_1 -> V_241 ) ) {
V_477 = true ;
break;
}
if ( V_478 > 5 ) {
V_1 -> V_463 = false ;
F_214 ( V_1 ) ;
F_281 ( V_1 , & V_72 ,
V_480 |
V_340 ) ;
V_478 = 0 ;
V_479 ++ ;
continue;
}
if ( ! F_284 ( V_1 , & V_72 , V_388 ) ) {
F_76 ( L_79 ) ;
break;
}
++ V_478 ;
}
F_285 ( V_1 ) ;
V_1 -> V_72 = V_72 ;
if ( V_477 ) {
V_1 -> V_463 = true ;
F_33 ( L_82 ) ;
}
}
void F_216 ( struct V_1 * V_1 )
{
F_281 ( V_1 , & V_1 -> V_72 ,
V_344 ) ;
}
static void
F_197 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_238 * V_239 = F_131 ( V_3 -> V_4 . V_4 . V_239 ) ;
enum V_18 V_18 = V_3 -> V_18 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_72 = V_1 -> V_72 ;
if ( F_44 ( F_10 ( V_7 ) ) )
return;
if ( F_44 ( ( F_22 ( V_1 -> V_73 ) & V_74 ) == 0 ) )
return;
F_33 ( L_50 ) ;
if ( ( F_143 ( V_7 ) && V_18 == V_19 ) ||
( F_145 ( V_7 ) && V_18 != V_19 ) ) {
V_72 &= ~ V_352 ;
V_72 |= V_482 ;
} else {
if ( F_35 ( V_7 ) )
V_72 &= ~ V_355 ;
else
V_72 &= ~ V_356 ;
V_72 |= V_483 ;
}
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_72 &= ~ ( V_74 | V_275 ) ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
if ( F_293 ( V_7 ) && V_239 -> V_69 == V_79 && V_18 != V_19 ) {
V_72 &= ~ ( V_80 | V_356 ) ;
V_72 |= V_74 | V_78 ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
V_72 &= ~ V_74 ;
F_39 ( V_1 -> V_73 , V_72 ) ;
F_40 ( V_1 -> V_73 ) ;
}
F_67 ( V_1 -> V_484 ) ;
}
static bool
F_294 ( struct V_1 * V_1 )
{
struct V_2 * V_268 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_268 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
T_3 V_485 ;
if ( F_250 ( & V_1 -> V_156 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_33 ( L_83 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_318 ] == 0 )
return false ;
memset ( V_1 -> V_486 , 0 , sizeof( V_1 -> V_486 ) ) ;
if ( F_1 ( V_1 ) ) {
F_250 ( & V_1 -> V_156 , V_487 ,
V_1 -> V_486 ,
sizeof( V_1 -> V_486 ) ) ;
if ( V_1 -> V_486 [ 0 ] & V_488 ) {
V_51 -> V_489 . V_490 = true ;
F_33 ( L_84 ) ;
}
if ( F_119 ( V_7 ) -> V_211 >= 9 &&
( V_1 -> V_486 [ 0 ] & V_491 ) ) {
T_3 V_492 ;
V_51 -> V_489 . V_490 = true ;
F_250 ( & V_1 -> V_156 ,
V_493 ,
& V_492 , 1 ) ;
V_51 -> V_489 . V_494 = V_492 ? true : false ;
V_51 -> V_489 . V_495 = V_51 -> V_489 . V_494 ;
F_33 ( L_85 ,
V_51 -> V_489 . V_495 ? L_86 : L_87 ) ;
}
}
if ( V_1 -> V_11 [ V_318 ] >= 0x12 &&
V_1 -> V_11 [ V_496 ] & V_497 &&
F_115 ( V_7 ) ) {
V_1 -> V_481 = true ;
F_33 ( L_88 ) ;
} else
V_1 -> V_481 = false ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_11 [ V_498 ] & V_499 ) &&
( F_250 ( & V_1 -> V_156 , V_500 , & V_485 , 1 ) == 1 ) &&
( V_485 >= 0x03 ) ) {
T_8 V_207 [ V_225 ] ;
int V_46 ;
F_250 ( & V_1 -> V_156 ,
V_501 ,
V_207 ,
sizeof( V_207 ) ) ;
for ( V_46 = 0 ; V_46 < F_121 ( V_207 ) ; V_46 ++ ) {
int V_333 = F_295 ( V_207 [ V_46 ] ) ;
if ( V_333 == 0 )
break;
V_1 -> V_207 [ V_46 ] = ( V_333 * 200 ) / 10 ;
}
V_1 -> V_208 = V_46 ;
}
F_127 ( V_1 ) ;
if ( ! ( V_1 -> V_11 [ V_502 ] &
V_503 ) )
return true ;
if ( V_1 -> V_11 [ V_318 ] == 0x10 )
return true ;
if ( F_250 ( & V_1 -> V_156 , V_504 ,
V_1 -> V_505 ,
V_506 ) < 0 )
return false ;
return true ;
}
static void
F_296 ( struct V_1 * V_1 )
{
T_1 V_461 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_507 ] & V_508 ) )
return;
if ( F_250 ( & V_1 -> V_156 , V_509 , V_461 , 3 ) == 3 )
F_33 ( L_89 ,
V_461 [ 0 ] , V_461 [ 1 ] , V_461 [ 2 ] ) ;
if ( F_250 ( & V_1 -> V_156 , V_510 , V_461 , 3 ) == 3 )
F_33 ( L_90 ,
V_461 [ 0 ] , V_461 [ 1 ] , V_461 [ 2 ] ) ;
}
static bool
F_297 ( struct V_1 * V_1 )
{
T_1 V_461 [ 1 ] ;
if ( ! V_1 -> V_511 )
return false ;
if ( V_1 -> V_11 [ V_318 ] < 0x12 )
return false ;
if ( F_250 ( & V_1 -> V_156 , V_512 , V_461 , 1 ) ) {
if ( V_461 [ 0 ] & V_513 ) {
F_33 ( L_91 ) ;
V_1 -> V_514 = true ;
} else {
F_33 ( L_92 ) ;
V_1 -> V_514 = false ;
}
}
F_298 ( & V_1 -> V_515 , V_1 -> V_514 ) ;
return V_1 -> V_514 ;
}
int F_299 ( struct V_1 * V_1 , T_1 * V_516 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_238 * V_238 =
F_131 ( V_3 -> V_4 . V_4 . V_239 ) ;
T_1 V_461 ;
int V_517 ;
int V_518 = 6 ;
int V_140 = 0 ;
F_300 ( V_238 ) ;
if ( F_301 ( & V_1 -> V_156 , V_519 , & V_461 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
if ( ! ( V_461 & V_520 ) ) {
V_140 = - V_521 ;
goto V_146;
}
if ( F_301 ( & V_1 -> V_156 , V_522 , & V_461 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
if ( F_181 ( & V_1 -> V_156 , V_522 ,
V_461 | V_523 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
if ( F_301 ( & V_1 -> V_156 , V_519 , & V_461 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
V_517 = V_461 & V_524 ;
do {
if ( F_301 ( & V_1 -> V_156 ,
V_519 , & V_461 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
F_302 ( V_7 , V_238 -> V_69 ) ;
} while ( -- V_518 && ( V_461 & V_524 ) == V_517 );
if ( V_518 == 0 ) {
F_33 ( L_93 ) ;
V_140 = - V_152 ;
goto V_146;
}
if ( F_251 ( & V_1 -> V_156 , V_525 , V_516 , 6 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
if ( F_301 ( & V_1 -> V_156 , V_522 , & V_461 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
if ( F_181 ( & V_1 -> V_156 , V_522 ,
V_461 & ~ V_523 ) < 0 ) {
V_140 = - V_151 ;
goto V_146;
}
V_146:
F_303 ( V_238 ) ;
return V_140 ;
}
static bool
F_304 ( struct V_1 * V_1 , T_1 * V_526 )
{
return F_250 ( & V_1 -> V_156 ,
V_527 ,
V_526 , 1 ) == 1 ;
}
static bool
F_305 ( struct V_1 * V_1 , T_1 * V_526 )
{
int V_140 ;
V_140 = F_250 ( & V_1 -> V_156 ,
V_528 ,
V_526 , 14 ) ;
if ( V_140 != 14 )
return false ;
return true ;
}
static T_3 F_306 ( struct V_1 * V_1 )
{
T_3 V_529 = V_530 ;
return V_529 ;
}
static T_3 F_307 ( struct V_1 * V_1 )
{
T_3 V_529 = V_531 ;
return V_529 ;
}
static T_3 F_308 ( struct V_1 * V_1 )
{
T_3 V_529 = V_531 ;
struct V_29 * V_29 = V_1 -> V_240 ;
struct V_8 * V_9 = & V_29 -> V_4 ;
if ( V_29 -> V_532 == NULL ||
V_9 -> V_533 ||
V_1 -> V_156 . V_534 > 6 ) {
if ( V_1 -> V_156 . V_535 > 0 ||
V_1 -> V_156 . V_534 > 0 )
F_33 ( L_94 ,
V_1 -> V_156 . V_535 ,
V_1 -> V_156 . V_534 ) ;
V_1 -> V_536 = V_537 ;
} else {
if ( ! F_282 ( & V_1 -> V_156 ,
V_538 ,
& V_29 -> V_532 -> V_539 ,
1 ) )
F_33 ( L_95 ) ;
V_529 = V_530 | V_540 ;
V_1 -> V_536 = V_541 ;
}
V_1 -> V_542 = 1 ;
return V_529 ;
}
static T_3 F_309 ( struct V_1 * V_1 )
{
T_3 V_529 = V_531 ;
return V_529 ;
}
static void F_310 ( struct V_1 * V_1 )
{
T_3 V_543 = V_531 ;
T_3 V_544 = 0 ;
int V_112 = 0 ;
V_1 -> V_542 = 0 ;
V_1 -> V_545 = 0 ;
V_1 -> V_536 = 0 ;
V_1 -> V_156 . V_535 = 0 ;
V_1 -> V_156 . V_534 = 0 ;
V_112 = F_251 ( & V_1 -> V_156 , V_546 , & V_544 , 1 ) ;
if ( V_112 <= 0 ) {
F_33 ( L_96 ) ;
goto V_547;
}
switch ( V_544 ) {
case V_548 :
F_33 ( L_97 ) ;
V_1 -> V_545 = V_548 ;
V_543 = F_306 ( V_1 ) ;
break;
case V_549 :
F_33 ( L_98 ) ;
V_1 -> V_545 = V_549 ;
V_543 = F_307 ( V_1 ) ;
break;
case V_550 :
F_33 ( L_99 ) ;
V_1 -> V_545 = V_550 ;
V_543 = F_308 ( V_1 ) ;
break;
case V_551 :
F_33 ( L_100 ) ;
V_1 -> V_545 = V_551 ;
V_543 = F_309 ( V_1 ) ;
break;
default:
F_33 ( L_101 , V_544 ) ;
break;
}
V_547:
V_112 = F_282 ( & V_1 -> V_156 ,
V_552 ,
& V_543 , 1 ) ;
if ( V_112 <= 0 )
F_33 ( L_102 ) ;
}
static int
F_311 ( struct V_1 * V_1 )
{
bool V_553 ;
if ( V_1 -> V_514 ) {
T_1 V_554 [ 16 ] = { 0 } ;
int V_140 = 0 ;
int V_555 ;
bool V_556 ;
V_553 = F_305 ( V_1 , V_554 ) ;
V_557:
if ( V_553 == true ) {
if ( V_1 -> V_558 && ! F_292 ( & V_554 [ 10 ] , V_1 -> V_241 ) ) {
F_33 ( L_103 ) ;
F_214 ( V_1 ) ;
F_215 ( V_1 ) ;
F_216 ( V_1 ) ;
}
F_33 ( L_104 , V_554 ) ;
V_140 = F_312 ( & V_1 -> V_515 , V_554 , & V_556 ) ;
if ( V_556 ) {
for ( V_555 = 0 ; V_555 < 3 ; V_555 ++ ) {
int V_559 ;
V_559 = F_282 ( & V_1 -> V_156 ,
V_528 + 1 ,
& V_554 [ 1 ] , 3 ) ;
if ( V_559 == 3 ) {
break;
}
}
V_553 = F_305 ( V_1 , V_554 ) ;
if ( V_553 == true ) {
F_33 ( L_105 , V_554 ) ;
goto V_557;
}
} else
V_140 = 0 ;
return V_140 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_33 ( L_106 ) ;
V_1 -> V_514 = false ;
F_298 ( & V_1 -> V_515 , V_1 -> V_514 ) ;
F_313 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_175 ;
}
static void
F_314 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_526 ;
T_1 V_388 [ V_389 ] ;
F_44 ( ! F_315 ( & V_7 -> V_560 . V_561 ) ) ;
if ( ! V_64 -> V_362 )
return;
if ( F_44 ( ! V_64 -> V_4 . V_239 ) )
return;
if ( ! F_131 ( V_64 -> V_4 . V_239 ) -> V_562 )
return;
if ( ! F_252 ( V_1 , V_388 ) ) {
return;
}
if ( ! F_294 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_318 ] >= 0x11 &&
F_304 ( V_1 , & V_526 ) ) {
F_181 ( & V_1 -> V_156 ,
V_527 ,
V_526 ) ;
if ( V_526 & V_563 )
F_217 ( L_107 ) ;
if ( V_526 & ( V_564 | V_565 ) )
F_217 ( L_108 ) ;
}
if ( ! F_292 ( V_388 , V_1 -> V_241 ) ) {
F_33 ( L_109 ,
V_64 -> V_4 . V_176 ) ;
F_214 ( V_1 ) ;
F_215 ( V_1 ) ;
F_216 ( V_1 ) ;
}
}
static enum V_566
F_316 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_294 ( V_1 ) )
return V_567 ;
if ( ! ( V_11 [ V_502 ] & V_503 ) )
return V_568 ;
if ( V_1 -> V_11 [ V_318 ] >= 0x11 &&
V_1 -> V_505 [ 0 ] & V_569 ) {
T_3 V_570 ;
if ( F_250 ( & V_1 -> V_156 , V_571 ,
& V_570 , 1 ) < 0 )
return V_572 ;
return F_317 ( V_570 ) ? V_568
: V_567 ;
}
if ( F_318 ( & V_1 -> V_156 . V_186 ) )
return V_568 ;
if ( V_1 -> V_11 [ V_318 ] >= 0x11 ) {
type = V_1 -> V_505 [ 0 ] & V_573 ;
if ( type == V_574 ||
type == V_575 )
return V_572 ;
} else {
type = V_1 -> V_11 [ V_502 ] &
V_576 ;
if ( type == V_577 ||
type == V_578 )
return V_572 ;
}
F_33 ( L_110 ) ;
return V_567 ;
}
static enum V_566
F_319 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_566 V_112 ;
V_112 = F_320 ( V_7 ) ;
if ( V_112 == V_572 )
V_112 = V_568 ;
return V_112 ;
}
static enum V_566
F_321 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_322 ( V_51 , V_3 ) )
return V_567 ;
return F_316 ( V_1 ) ;
}
static int F_323 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_2 V_579 ;
if ( F_21 ( V_7 ) ) {
switch ( V_3 -> V_18 ) {
case V_177 :
V_579 = V_580 ;
break;
case V_179 :
V_579 = V_581 ;
break;
case V_181 :
V_579 = V_582 ;
break;
default:
return - V_175 ;
}
} else {
switch ( V_3 -> V_18 ) {
case V_177 :
V_579 = V_583 ;
break;
case V_179 :
V_579 = V_584 ;
break;
case V_181 :
V_579 = V_585 ;
break;
default:
return - V_175 ;
}
}
if ( ( F_22 ( V_586 ) & V_579 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_566
F_324 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_140 ;
if ( F_1 ( V_1 ) ) {
enum V_566 V_112 ;
V_112 = F_320 ( V_7 ) ;
if ( V_112 == V_572 )
V_112 = V_568 ;
return V_112 ;
}
V_140 = F_323 ( V_7 , V_3 ) ;
if ( V_140 == - V_175 )
return V_572 ;
else if ( V_140 == 0 )
return V_567 ;
return F_316 ( V_1 ) ;
}
static struct V_587 *
F_325 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_240 ;
if ( V_29 -> V_587 ) {
if ( F_326 ( V_29 -> V_587 ) )
return NULL ;
return F_327 ( V_29 -> V_587 ) ;
} else
return F_328 ( & V_29 -> V_4 ,
& V_1 -> V_156 . V_186 ) ;
}
static void
F_329 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_240 ;
struct V_587 * V_587 ;
V_587 = F_325 ( V_1 ) ;
V_29 -> V_532 = V_587 ;
if ( V_1 -> V_588 != V_589 )
V_1 -> V_250 = V_1 -> V_588 == V_590 ;
else
V_1 -> V_250 = F_330 ( V_587 ) ;
}
static void
F_331 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_240 ;
F_332 ( V_29 -> V_532 ) ;
V_29 -> V_532 = NULL ;
V_1 -> V_250 = false ;
}
static enum V_66
F_333 ( struct V_1 * V_591 )
{
struct V_64 * V_65 = & F_2 ( V_591 ) -> V_4 ;
enum V_66 V_67 ;
V_67 = F_24 ( V_65 ) ;
F_25 ( F_334 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
return V_67 ;
}
static void
F_335 ( struct V_1 * V_591 ,
enum V_66 V_67 )
{
struct V_64 * V_65 = & F_2 ( V_591 ) -> V_4 ;
F_29 ( F_334 ( V_65 -> V_4 . V_7 ) , V_67 ) ;
}
static enum V_566
F_336 ( struct V_8 * V_9 , bool V_592 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_566 V_112 ;
enum V_66 V_67 ;
bool V_140 ;
T_1 V_526 ;
F_33 ( L_111 ,
V_9 -> V_4 . V_593 , V_9 -> V_176 ) ;
F_331 ( V_1 ) ;
if ( V_1 -> V_514 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_594 ;
return V_567 ;
}
V_67 = F_333 ( V_1 ) ;
if ( F_1 ( V_1 ) )
V_112 = F_319 ( V_1 ) ;
else if ( F_61 ( V_7 ) )
V_112 = F_321 ( V_1 ) ;
else
V_112 = F_324 ( V_1 ) ;
if ( V_112 != V_568 )
goto V_146;
F_296 ( V_1 ) ;
V_140 = F_297 ( V_1 ) ;
if ( V_140 ) {
if ( V_64 -> type != V_5 )
V_64 -> type = V_594 ;
V_112 = V_567 ;
goto V_146;
}
F_329 ( V_1 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_594 ;
V_112 = V_568 ;
if ( V_1 -> V_11 [ V_318 ] >= 0x11 &&
F_304 ( V_1 , & V_526 ) ) {
F_181 ( & V_1 -> V_156 ,
V_527 ,
V_526 ) ;
if ( V_526 & V_563 )
F_310 ( V_1 ) ;
if ( V_526 & ( V_564 | V_565 ) )
F_217 ( L_108 ) ;
}
V_146:
F_335 ( V_1 , V_67 ) ;
return V_112 ;
}
static void
F_337 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_64 * V_64 = & F_2 ( V_1 ) -> V_4 ;
enum V_66 V_67 ;
F_33 ( L_111 ,
V_9 -> V_4 . V_593 , V_9 -> V_176 ) ;
F_331 ( V_1 ) ;
if ( V_9 -> V_112 != V_568 )
return;
V_67 = F_333 ( V_1 ) ;
F_329 ( V_1 ) ;
F_335 ( V_1 , V_67 ) ;
if ( V_64 -> type != V_5 )
V_64 -> type = V_594 ;
}
static int F_338 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_587 * V_587 ;
V_587 = V_29 -> V_532 ;
if ( V_587 ) {
int V_140 = F_339 ( V_9 , V_587 ) ;
if ( V_140 )
return V_140 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_29 -> V_31 . V_30 ) {
struct V_27 * V_28 ;
V_28 = F_340 ( V_9 -> V_7 ,
V_29 -> V_31 . V_30 ) ;
if ( V_28 ) {
F_341 ( V_9 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_342 ( struct V_8 * V_9 )
{
bool V_250 = false ;
struct V_587 * V_587 ;
V_587 = F_16 ( V_9 ) -> V_532 ;
if ( V_587 )
V_250 = F_330 ( V_587 ) ;
return V_250 ;
}
static int
F_343 ( struct V_8 * V_9 ,
struct V_595 * V_596 ,
T_9 V_333 )
{
struct V_50 * V_51 = V_9 -> V_7 -> V_52 ;
struct V_29 * V_29 = F_16 ( V_9 ) ;
struct V_64 * V_64 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
int V_140 ;
V_140 = F_344 ( & V_9 -> V_4 , V_596 , V_333 ) ;
if ( V_140 )
return V_140 ;
if ( V_596 == V_51 -> V_597 ) {
int V_46 = V_333 ;
bool V_250 ;
if ( V_46 == V_1 -> V_588 )
return 0 ;
V_1 -> V_588 = V_46 ;
if ( V_46 == V_589 )
V_250 = F_342 ( V_9 ) ;
else
V_250 = ( V_46 == V_590 ) ;
if ( V_250 == V_1 -> V_250 )
return 0 ;
V_1 -> V_250 = V_250 ;
goto V_113;
}
if ( V_596 == V_51 -> V_598 ) {
bool V_599 = V_1 -> V_257 ;
T_2 V_600 = V_1 -> V_258 ;
switch ( V_333 ) {
case V_601 :
V_1 -> V_257 = true ;
break;
case V_602 :
V_1 -> V_257 = false ;
V_1 -> V_258 = 0 ;
break;
case V_603 :
V_1 -> V_257 = false ;
V_1 -> V_258 = V_259 ;
break;
default:
return - V_175 ;
}
if ( V_599 == V_1 -> V_257 &&
V_600 == V_1 -> V_258 )
return 0 ;
goto V_113;
}
if ( F_1 ( V_1 ) &&
V_596 == V_9 -> V_7 -> V_560 . V_604 ) {
if ( V_333 == V_605 ) {
F_33 ( L_112 ) ;
return - V_175 ;
}
if ( V_29 -> V_31 . V_251 == V_333 ) {
return 0 ;
}
V_29 -> V_31 . V_251 = V_333 ;
goto V_113;
}
return - V_175 ;
V_113:
if ( V_64 -> V_4 . V_239 )
F_345 ( V_64 -> V_4 . V_239 ) ;
return 0 ;
}
static void
F_346 ( struct V_8 * V_9 )
{
struct V_29 * V_29 = F_16 ( V_9 ) ;
F_332 ( V_29 -> V_532 ) ;
if ( ! F_347 ( V_29 -> V_587 ) )
F_332 ( V_29 -> V_587 ) ;
if ( V_9 -> V_606 == V_607 )
F_348 ( & V_29 -> V_31 ) ;
F_349 ( V_9 ) ;
F_332 ( V_9 ) ;
}
void F_350 ( struct V_467 * V_65 )
{
struct V_2 * V_3 = F_230 ( V_65 ) ;
struct V_1 * V_1 = & V_3 -> V_591 ;
F_106 ( & V_1 -> V_156 ) ;
F_351 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_352 ( & V_1 -> V_304 ) ;
F_23 ( V_1 ) ;
F_159 ( V_1 ) ;
F_27 ( V_1 ) ;
if ( V_1 -> V_100 . V_608 ) {
F_353 ( & V_1 -> V_100 ) ;
V_1 -> V_100 . V_608 = NULL ;
}
}
F_354 ( V_65 ) ;
F_332 ( V_3 ) ;
}
static void F_355 ( struct V_64 * V_64 )
{
struct V_1 * V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_352 ( & V_1 -> V_304 ) ;
F_23 ( V_1 ) ;
F_159 ( V_1 ) ;
F_27 ( V_1 ) ;
}
static void F_356 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
F_43 ( & V_51 -> V_68 ) ;
if ( ! F_69 ( V_1 ) )
return;
F_33 ( L_113 ) ;
V_67 = F_24 ( & V_3 -> V_4 ) ;
F_25 ( V_51 , V_67 ) ;
F_162 ( V_1 ) ;
}
static void F_357 ( struct V_467 * V_65 )
{
struct V_1 * V_1 ;
if ( F_358 ( V_65 ) -> type != V_5 )
return;
V_1 = F_5 ( V_65 ) ;
F_23 ( V_1 ) ;
if ( F_21 ( V_65 -> V_7 ) )
F_58 ( V_1 ) ;
F_356 ( V_1 ) ;
F_27 ( V_1 ) ;
}
void
F_359 ( struct V_64 * V_64 )
{
return;
}
enum V_609
F_360 ( struct V_2 * V_3 , bool V_610 )
{
struct V_1 * V_1 = & V_3 -> V_591 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_66 V_67 ;
enum V_609 V_140 = V_611 ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_594 ;
if ( V_610 && V_3 -> V_4 . type == V_5 ) {
F_33 ( L_114 ,
F_32 ( V_3 -> V_18 ) ) ;
return V_612 ;
}
F_33 ( L_115 ,
F_32 ( V_3 -> V_18 ) ,
V_610 ? L_116 : L_117 ) ;
V_67 = F_24 ( V_64 ) ;
F_25 ( V_51 , V_67 ) ;
if ( V_610 ) {
V_1 -> V_463 = false ;
if ( F_61 ( V_7 ) ) {
if ( ! F_322 ( V_51 , V_3 ) )
goto V_613;
} else {
if ( F_323 ( V_7 , V_3 ) != 1 )
goto V_613;
}
if ( ! F_294 ( V_1 ) ) {
goto V_613;
}
F_296 ( V_1 ) ;
if ( ! F_297 ( V_1 ) )
goto V_613;
} else {
if ( V_1 -> V_514 ) {
if ( F_311 ( V_1 ) == - V_175 )
goto V_613;
}
if ( ! V_1 -> V_514 ) {
F_361 ( & V_7 -> V_560 . V_561 , NULL ) ;
F_314 ( V_1 ) ;
F_362 ( & V_7 -> V_560 . V_561 ) ;
}
}
V_140 = V_612 ;
goto V_614;
V_613:
if ( V_1 -> V_514 ) {
F_33 ( L_118 , V_1 -> V_514 , V_1 -> V_515 . V_615 ) ;
V_1 -> V_514 = false ;
F_298 ( & V_1 -> V_515 , V_1 -> V_514 ) ;
}
V_614:
F_29 ( V_51 , V_67 ) ;
return V_140 ;
}
int
F_363 ( struct V_316 * V_239 )
{
struct V_6 * V_7 = V_239 -> V_7 ;
struct V_64 * V_64 ;
struct V_1 * V_1 ;
F_364 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_64 -> V_4 ) ;
if ( V_64 -> type == V_594 ||
V_64 -> type == V_5 )
return V_1 -> V_73 ;
}
return - 1 ;
}
bool F_365 ( struct V_6 * V_7 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
union V_616 * V_617 ;
int V_46 ;
static const short V_618 [] = {
[ V_177 ] = V_619 ,
[ V_179 ] = V_620 ,
[ V_181 ] = V_621 ,
} ;
if ( V_18 == V_19 )
return true ;
if ( ! V_51 -> V_254 . V_622 )
return false ;
for ( V_46 = 0 ; V_46 < V_51 -> V_254 . V_622 ; V_46 ++ ) {
V_617 = V_51 -> V_254 . V_623 + V_46 ;
if ( V_617 -> V_624 . V_625 == V_618 [ V_18 ] &&
( V_617 -> V_624 . V_626 & V_627 ) ==
( V_628 & V_627 ) )
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
V_1 -> V_257 = true ;
if ( F_1 ( V_1 ) ) {
F_369 ( V_9 -> V_7 ) ;
F_370 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_560 . V_604 ,
V_629 ) ;
V_29 -> V_31 . V_251 = V_629 ;
}
}
static void F_371 ( struct V_1 * V_1 )
{
V_1 -> V_292 = V_307 ;
V_1 -> V_295 = V_307 ;
V_1 -> V_297 = V_307 ;
}
static void
F_48 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_630 V_631 , V_254 , V_632 ,
* V_633 = & V_1 -> V_634 ;
T_5 V_635 , V_636 , V_101 , V_301 ;
int V_102 , V_361 , V_637 , V_103 ;
F_43 ( & V_51 -> V_68 ) ;
if ( V_633 -> V_638 != 0 )
return;
if ( F_61 ( V_7 ) ) {
V_102 = V_94 ;
V_361 = V_639 ;
V_637 = V_640 ;
V_103 = V_641 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_102 = F_53 ( V_69 ) ;
V_361 = F_56 ( V_69 ) ;
V_637 = F_372 ( V_69 ) ;
V_103 = F_66 ( V_69 ) ;
}
V_301 = F_155 ( V_1 ) ;
F_39 ( V_102 , V_301 ) ;
V_635 = F_22 ( V_361 ) ;
V_636 = F_22 ( V_637 ) ;
V_101 = F_22 ( V_103 ) ;
V_631 . V_642 = ( V_635 & V_643 ) >>
V_644 ;
V_631 . V_645 = ( V_635 & V_646 ) >>
V_647 ;
V_631 . V_648 = ( V_636 & V_649 ) >>
V_650 ;
V_631 . V_651 = ( V_636 & V_652 ) >>
V_653 ;
V_631 . V_638 = ( ( V_101 & V_654 ) >>
V_655 ) * 1000 ;
F_33 ( L_119 ,
V_631 . V_642 , V_631 . V_645 , V_631 . V_648 , V_631 . V_651 , V_631 . V_638 ) ;
V_254 = V_51 -> V_254 . V_656 ;
V_632 . V_642 = 210 * 10 ;
V_632 . V_645 = 50 * 10 ;
V_632 . V_648 = 50 * 10 ;
V_632 . V_651 = 500 * 10 ;
V_632 . V_638 = ( 510 + 100 ) * 10 ;
F_33 ( L_120 ,
V_254 . V_642 , V_254 . V_645 , V_254 . V_648 , V_254 . V_651 , V_254 . V_638 ) ;
#define F_373 ( T_10 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_373 ( V_642 ) ;
F_373 ( V_645 ) ;
F_373 ( V_648 ) ;
F_373 ( V_651 ) ;
F_373 ( V_638 ) ;
#undef F_373
#define F_374 ( T_10 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_305 = F_374 ( V_642 ) ;
V_1 -> V_296 = F_374 ( V_645 ) ;
V_1 -> V_298 = F_374 ( V_648 ) ;
V_1 -> V_484 = F_374 ( V_651 ) ;
V_1 -> V_108 = F_374 ( V_638 ) ;
#undef F_374
F_33 ( L_121 ,
V_1 -> V_305 , V_1 -> V_484 ,
V_1 -> V_108 ) ;
F_33 ( L_122 ,
V_1 -> V_296 , V_1 -> V_298 ) ;
}
static void
F_49 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
T_5 V_635 , V_636 , V_101 , V_92 = 0 ;
int div = F_61 ( V_7 ) ? F_80 ( V_7 ) : F_20 ( V_7 ) ;
int V_361 , V_637 , V_103 ;
enum V_18 V_18 = F_2 ( V_1 ) -> V_18 ;
const struct V_630 * V_657 = & V_1 -> V_634 ;
F_43 ( & V_51 -> V_68 ) ;
if ( F_61 ( V_7 ) ) {
V_361 = V_639 ;
V_637 = V_640 ;
V_103 = V_641 ;
} else {
enum V_69 V_69 = F_42 ( V_1 ) ;
V_361 = F_56 ( V_69 ) ;
V_637 = F_372 ( V_69 ) ;
V_103 = F_66 ( V_69 ) ;
}
V_635 = ( V_657 -> V_642 << V_644 ) |
( 1 << V_647 ) ;
V_636 = ( 1 << V_650 ) |
( V_657 -> V_651 << V_653 ) ;
V_101 = ( ( 100 * div ) / 2 - 1 ) << V_658 ;
V_101 |= ( F_79 ( V_657 -> V_638 , 1000 )
<< V_655 ) ;
if ( F_21 ( V_7 ) ) {
V_92 = F_57 ( V_18 ) ;
} else if ( F_293 ( V_7 ) || F_145 ( V_7 ) ) {
if ( V_18 == V_19 )
V_92 = V_659 ;
else
V_92 = V_660 ;
}
V_635 |= V_92 ;
F_39 ( V_361 , V_635 ) ;
F_39 ( V_637 , V_636 ) ;
F_39 ( V_103 , V_101 ) ;
F_33 ( L_123 ,
F_22 ( V_361 ) ,
F_22 ( V_637 ) ,
F_22 ( V_103 ) ) ;
}
static void F_375 ( struct V_6 * V_7 , int V_661 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_64 * V_65 ;
struct V_2 * V_268 = NULL ;
struct V_1 * V_1 = V_51 -> V_265 . V_591 ;
struct V_188 * V_270 = NULL ;
struct V_238 * V_238 = NULL ;
T_5 V_570 , V_333 ;
enum V_662 V_115 = V_663 ;
if ( V_661 <= 0 ) {
F_33 ( L_124 ) ;
return;
}
if ( V_1 == NULL ) {
F_33 ( L_125 ) ;
return;
}
V_268 = F_2 ( V_1 ) ;
V_65 = & V_268 -> V_4 ;
V_238 = F_131 ( V_65 -> V_4 . V_239 ) ;
if ( ! V_238 ) {
F_33 ( L_126 ) ;
return;
}
V_270 = V_238 -> V_270 ;
if ( V_51 -> V_265 . type < V_266 ) {
F_33 ( L_127 ) ;
return;
}
if ( V_1 -> V_240 -> V_31 . V_264 -> V_664 ==
V_661 )
V_115 = V_665 ;
if ( V_115 == V_51 -> V_265 . V_666 ) {
F_33 (
L_128 ) ;
return;
}
if ( ! V_238 -> V_562 ) {
F_33 ( L_129 ) ;
return;
}
if ( F_119 ( V_7 ) -> V_211 >= 8 && ! F_35 ( V_7 ) ) {
switch ( V_115 ) {
case V_663 :
F_376 ( V_238 , V_667 ) ;
break;
case V_665 :
F_376 ( V_238 , V_668 ) ;
break;
case V_669 :
default:
F_76 ( L_130 ) ;
}
} else if ( F_119 ( V_7 ) -> V_211 > 6 ) {
V_570 = F_377 ( V_238 -> V_270 -> V_670 ) ;
V_333 = F_22 ( V_570 ) ;
if ( V_115 > V_663 ) {
if ( F_21 ( V_7 ) )
V_333 |= V_671 ;
else
V_333 |= V_672 ;
} else {
if ( F_21 ( V_7 ) )
V_333 &= ~ V_671 ;
else
V_333 &= ~ V_672 ;
}
F_39 ( V_570 , V_333 ) ;
}
V_51 -> V_265 . V_666 = V_115 ;
F_33 ( L_131 , V_661 ) ;
}
void F_378 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_268 = F_2 ( V_1 ) ;
struct V_316 * V_239 = V_268 -> V_4 . V_4 . V_239 ;
struct V_238 * V_238 = F_131 ( V_239 ) ;
if ( ! V_238 -> V_270 -> V_249 ) {
F_33 ( L_132 ) ;
return;
}
F_26 ( & V_51 -> V_265 . V_673 ) ;
if ( F_44 ( V_51 -> V_265 . V_591 ) ) {
F_76 ( L_133 ) ;
goto V_674;
}
V_51 -> V_265 . V_675 = 0 ;
V_51 -> V_265 . V_591 = V_1 ;
V_674:
F_28 ( & V_51 -> V_265 . V_673 ) ;
}
void F_379 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_268 = F_2 ( V_1 ) ;
struct V_316 * V_239 = V_268 -> V_4 . V_4 . V_239 ;
struct V_238 * V_238 = F_131 ( V_239 ) ;
if ( ! V_238 -> V_270 -> V_249 )
return;
F_26 ( & V_51 -> V_265 . V_673 ) ;
if ( ! V_51 -> V_265 . V_591 ) {
F_28 ( & V_51 -> V_265 . V_673 ) ;
return;
}
if ( V_51 -> V_265 . V_666 == V_665 )
F_375 ( V_51 -> V_7 ,
V_1 -> V_240 -> V_31 .
V_30 -> V_664 ) ;
V_51 -> V_265 . V_591 = NULL ;
F_28 ( & V_51 -> V_265 . V_673 ) ;
F_352 ( & V_51 -> V_265 . V_676 ) ;
}
static void F_380 ( struct V_308 * V_676 )
{
struct V_50 * V_51 =
F_64 ( V_676 , F_65 ( * V_51 ) , V_265 . V_676 . V_676 ) ;
struct V_1 * V_1 ;
F_26 ( & V_51 -> V_265 . V_673 ) ;
V_1 = V_51 -> V_265 . V_591 ;
if ( ! V_1 )
goto V_674;
if ( V_51 -> V_265 . V_675 )
goto V_674;
if ( V_51 -> V_265 . V_666 != V_665 )
F_375 ( V_51 -> V_7 ,
V_1 -> V_240 -> V_31 .
V_264 -> V_664 ) ;
V_674:
F_28 ( & V_51 -> V_265 . V_673 ) ;
}
void F_381 ( struct V_6 * V_7 ,
unsigned V_677 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_316 * V_239 ;
enum V_69 V_69 ;
if ( V_51 -> V_265 . type == V_678 )
return;
F_156 ( & V_51 -> V_265 . V_676 ) ;
F_26 ( & V_51 -> V_265 . V_673 ) ;
if ( ! V_51 -> V_265 . V_591 ) {
F_28 ( & V_51 -> V_265 . V_673 ) ;
return;
}
V_239 = F_2 ( V_51 -> V_265 . V_591 ) -> V_4 . V_4 . V_239 ;
V_69 = F_131 ( V_239 ) -> V_69 ;
if ( V_51 -> V_265 . V_666 == V_665 ) {
F_375 ( V_51 -> V_7 ,
V_51 -> V_265 . V_591 -> V_240 -> V_31 .
V_30 -> V_664 ) ;
}
V_677 &= F_382 ( V_69 ) ;
V_51 -> V_265 . V_675 |= V_677 ;
F_28 ( & V_51 -> V_265 . V_673 ) ;
}
void F_383 ( struct V_6 * V_7 ,
unsigned V_677 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_316 * V_239 ;
enum V_69 V_69 ;
if ( V_51 -> V_265 . type == V_678 )
return;
F_156 ( & V_51 -> V_265 . V_676 ) ;
F_26 ( & V_51 -> V_265 . V_673 ) ;
if ( ! V_51 -> V_265 . V_591 ) {
F_28 ( & V_51 -> V_265 . V_673 ) ;
return;
}
V_239 = F_2 ( V_51 -> V_265 . V_591 ) -> V_4 . V_4 . V_239 ;
V_69 = F_131 ( V_239 ) -> V_69 ;
V_51 -> V_265 . V_675 &= ~ V_677 ;
if ( V_51 -> V_265 . V_666 != V_665 &&
! V_51 -> V_265 . V_675 )
F_164 ( & V_51 -> V_265 . V_676 ,
F_163 ( 1000 ) ) ;
F_28 ( & V_51 -> V_265 . V_673 ) ;
}
static struct V_27 *
F_384 ( struct V_29 * V_29 ,
struct V_27 * V_30 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_264 = NULL ;
F_385 ( & V_51 -> V_265 . V_676 , F_380 ) ;
F_386 ( & V_51 -> V_265 . V_673 ) ;
if ( F_119 ( V_7 ) -> V_211 <= 6 ) {
F_33 ( L_134 ) ;
return NULL ;
}
if ( V_51 -> V_254 . V_679 != V_266 ) {
F_33 ( L_135 ) ;
return NULL ;
}
V_264 = F_387
( V_7 , V_30 , V_9 ) ;
if ( ! V_264 ) {
F_33 ( L_136 ) ;
return NULL ;
}
V_51 -> V_265 . type = V_51 -> V_254 . V_679 ;
V_51 -> V_265 . V_666 = V_663 ;
F_33 ( L_137 ) ;
return V_264 ;
}
static bool F_388 ( struct V_1 * V_1 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_27 * V_30 = NULL ;
struct V_27 * V_264 = NULL ;
bool V_680 ;
struct V_27 * V_681 ;
struct V_587 * V_587 ;
enum V_69 V_69 = V_87 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_23 ( V_1 ) ;
F_356 ( V_1 ) ;
F_27 ( V_1 ) ;
V_680 = F_294 ( V_1 ) ;
if ( V_680 ) {
if ( V_1 -> V_11 [ V_318 ] >= 0x11 )
V_51 -> V_682 =
V_1 -> V_11 [ V_683 ] &
V_684 ;
} else {
F_389 ( L_138 ) ;
return false ;
}
F_23 ( V_1 ) ;
F_49 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
F_26 ( & V_7 -> V_560 . V_673 ) ;
V_587 = F_328 ( V_9 , & V_1 -> V_156 . V_186 ) ;
if ( V_587 ) {
if ( F_390 ( V_9 , V_587 ) ) {
F_391 ( V_9 ,
V_587 ) ;
F_392 ( V_9 , V_587 ) ;
} else {
F_332 ( V_587 ) ;
V_587 = F_393 ( - V_175 ) ;
}
} else {
V_587 = F_393 ( - V_685 ) ;
}
V_29 -> V_587 = V_587 ;
F_45 (scan, &connector->probed_modes, head) {
if ( ( V_681 -> type & V_686 ) ) {
V_30 = F_340 ( V_7 , V_681 ) ;
V_264 = F_384 (
V_29 , V_30 ) ;
break;
}
}
if ( ! V_30 && V_51 -> V_254 . V_687 ) {
V_30 = F_340 ( V_7 ,
V_51 -> V_254 . V_687 ) ;
if ( V_30 )
V_30 -> type |= V_686 ;
}
F_28 ( & V_7 -> V_560 . V_673 ) ;
if ( F_21 ( V_7 ) ) {
V_1 -> V_100 . V_608 = F_63 ;
F_394 ( & V_1 -> V_100 ) ;
if ( F_35 ( V_7 ) )
V_69 = F_187 ( V_1 -> V_72 ) ;
else
V_69 = F_188 ( V_1 -> V_72 ) ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_1 -> V_70 ;
if ( V_69 != V_86 && V_69 != V_79 )
V_69 = V_86 ;
F_33 ( L_139 ,
F_31 ( V_69 ) ) ;
}
F_395 ( & V_29 -> V_31 , V_30 , V_264 ) ;
V_29 -> V_31 . V_688 = F_176 ;
F_396 ( V_9 , V_69 ) ;
return true ;
}
bool
F_397 ( struct V_2 * V_3 ,
struct V_29 * V_29 )
{
struct V_8 * V_9 = & V_29 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_591 ;
struct V_64 * V_64 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_64 -> V_4 . V_7 ;
struct V_50 * V_51 = V_7 -> V_52 ;
enum V_18 V_18 = V_3 -> V_18 ;
int type ;
V_1 -> V_70 = V_87 ;
if ( F_119 ( V_7 ) -> V_211 >= 9 )
V_1 -> V_148 = F_84 ;
else if ( F_21 ( V_7 ) )
V_1 -> V_148 = F_83 ;
else if ( F_103 ( V_7 ) || F_87 ( V_7 ) )
V_1 -> V_148 = F_81 ;
else if ( F_61 ( V_7 ) )
V_1 -> V_148 = F_78 ;
else
V_1 -> V_148 = F_77 ;
if ( F_119 ( V_7 ) -> V_211 >= 9 )
V_1 -> V_150 = F_88 ;
else
V_1 -> V_150 = F_85 ;
V_1 -> V_72 = F_22 ( V_1 -> V_73 ) ;
V_1 -> V_240 = V_29 ;
if ( F_365 ( V_7 , V_18 ) )
type = V_607 ;
else
type = V_689 ;
if ( type == V_607 )
V_64 -> type = V_5 ;
if ( F_44 ( F_21 ( V_7 ) && F_1 ( V_1 ) &&
V_18 != V_177 && V_18 != V_179 ) )
return false ;
F_33 ( L_140 ,
type == V_607 ? L_141 : L_142 ,
F_32 ( V_18 ) ) ;
F_398 ( V_7 , V_9 , & V_690 , type ) ;
F_399 ( V_9 , & V_691 ) ;
V_9 -> V_692 = true ;
V_9 -> V_693 = 0 ;
F_385 ( & V_1 -> V_304 ,
F_160 ) ;
F_400 ( V_29 , V_64 ) ;
F_401 ( V_9 ) ;
if ( F_10 ( V_7 ) )
V_29 -> V_694 = V_695 ;
else
V_29 -> V_694 = V_696 ;
V_29 -> V_697 = F_107 ;
switch ( V_18 ) {
case V_19 :
V_64 -> V_698 = V_699 ;
break;
case V_177 :
V_64 -> V_698 = V_700 ;
break;
case V_179 :
V_64 -> V_698 = V_701 ;
break;
case V_181 :
V_64 -> V_698 = V_702 ;
break;
default:
F_102 () ;
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
F_101 ( V_1 , V_29 ) ;
if ( F_402 ( V_7 ) &&
( V_18 == V_177 || V_18 == V_179 || V_18 == V_181 ) )
F_403 ( V_3 ,
V_29 -> V_4 . V_4 . V_593 ) ;
if ( ! F_388 ( V_1 , V_29 ) ) {
F_106 ( & V_1 -> V_156 ) ;
if ( F_1 ( V_1 ) ) {
F_352 ( & V_1 -> V_304 ) ;
F_23 ( V_1 ) ;
F_159 ( V_1 ) ;
F_27 ( V_1 ) ;
}
F_404 ( V_9 ) ;
F_349 ( V_9 ) ;
return false ;
}
F_366 ( V_1 , V_9 ) ;
if ( F_123 ( V_7 ) && ! F_405 ( V_7 ) ) {
T_5 V_339 = F_22 ( V_703 ) ;
F_39 ( V_703 , ( V_339 & ~ 0xf ) | 0xd ) ;
}
F_406 ( V_9 ) ;
return true ;
}
void
F_407 ( struct V_6 * V_7 , int V_73 , enum V_18 V_18 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
struct V_2 * V_3 ;
struct V_64 * V_64 ;
struct V_467 * V_65 ;
struct V_29 * V_29 ;
V_3 = F_408 ( sizeof( * V_3 ) , V_704 ) ;
if ( ! V_3 )
return;
V_29 = F_409 () ;
if ( ! V_29 ) {
F_332 ( V_3 ) ;
return;
}
V_64 = & V_3 -> V_4 ;
V_65 = & V_64 -> V_4 ;
F_410 ( V_7 , & V_64 -> V_4 , & V_705 ,
V_706 ) ;
V_64 -> V_707 = F_130 ;
V_64 -> V_708 = F_193 ;
V_64 -> V_694 = F_182 ;
V_64 -> V_709 = F_189 ;
V_64 -> V_710 = F_355 ;
if ( F_35 ( V_7 ) ) {
V_64 -> V_711 = F_247 ;
V_64 -> V_712 = F_236 ;
V_64 -> V_314 = F_220 ;
V_64 -> V_713 = F_200 ;
} else if ( F_21 ( V_7 ) ) {
V_64 -> V_711 = F_229 ;
V_64 -> V_712 = F_224 ;
V_64 -> V_314 = F_220 ;
V_64 -> V_713 = F_199 ;
} else {
V_64 -> V_712 = F_222 ;
V_64 -> V_314 = F_219 ;
if ( F_119 ( V_7 ) -> V_211 >= 5 )
V_64 -> V_713 = F_198 ;
}
V_3 -> V_18 = V_18 ;
V_3 -> V_591 . V_73 = V_73 ;
V_64 -> type = V_594 ;
if ( F_35 ( V_7 ) ) {
if ( V_18 == V_181 )
V_64 -> V_714 = 1 << 2 ;
else
V_64 -> V_714 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_64 -> V_714 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_64 -> V_715 = 0 ;
V_64 -> V_716 = F_359 ;
V_3 -> V_717 = F_360 ;
V_51 -> V_718 [ V_18 ] = V_3 ;
if ( ! F_397 ( V_3 , V_29 ) ) {
F_354 ( V_65 ) ;
F_332 ( V_3 ) ;
F_332 ( V_29 ) ;
}
}
void F_411 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_719 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_718 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_594 ) {
if ( ! V_3 -> V_591 . V_511 )
continue;
if ( V_3 -> V_591 . V_514 )
F_412 ( & V_3 -> V_591 . V_515 ) ;
}
}
}
void F_413 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = V_7 -> V_52 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_719 ; V_46 ++ ) {
struct V_2 * V_3 = V_51 -> V_718 [ V_46 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_594 ) {
int V_140 ;
if ( ! V_3 -> V_591 . V_511 )
continue;
V_140 = F_414 ( & V_3 -> V_591 . V_515 ) ;
if ( V_140 != 0 ) {
F_311 ( & V_3 -> V_591 ) ;
}
}
}
}
