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
int
F_7 ( struct V_1 * V_1 )
{
int V_10 = V_1 -> V_11 [ V_12 ] ;
struct V_6 * V_7 = V_1 -> V_13 -> V_4 . V_7 ;
switch ( V_10 ) {
case V_14 :
case V_15 :
break;
case V_16 :
if ( ( ( F_8 ( V_7 ) && ! F_9 ( V_7 ) ) ||
F_10 ( V_7 ) -> V_17 >= 8 ) &&
V_1 -> V_11 [ V_18 ] >= 0x12 )
V_10 = V_16 ;
else
V_10 = V_15 ;
break;
default:
F_11 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_14 ;
break;
}
return V_10 ;
}
static T_1 F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_19 , V_20 ;
V_19 = 4 ;
if ( F_13 ( V_7 ) && V_3 -> V_21 == V_22 &&
( V_3 -> V_23 & V_24 ) == 0 )
V_19 = 2 ;
V_20 = F_14 ( V_1 -> V_11 ) ;
return F_15 ( V_19 , V_20 ) ;
}
static int
F_16 ( int V_25 , int V_26 )
{
return ( V_25 * V_26 + 9 ) / 10 ;
}
static int
F_17 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 * 8 ) / 10 ;
}
static enum V_29
F_18 ( struct V_8 * V_9 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_30 * V_33 = V_32 -> V_34 . V_33 ;
int V_35 = V_31 -> clock ;
int V_36 , V_37 , V_28 , V_27 ;
if ( F_1 ( V_1 ) && V_33 ) {
if ( V_31 -> V_38 > V_33 -> V_38 )
return V_39 ;
if ( V_31 -> V_40 > V_33 -> V_40 )
return V_39 ;
V_35 = V_33 -> clock ;
}
V_27 = F_20 ( F_7 ( V_1 ) ) ;
V_28 = F_12 ( V_1 ) ;
V_36 = F_17 ( V_27 , V_28 ) ;
V_37 = F_16 ( V_35 , 18 ) ;
if ( V_37 > V_36 )
return V_41 ;
if ( V_31 -> clock < 10000 )
return V_42 ;
if ( V_31 -> V_43 & V_44 )
return V_45 ;
return V_46 ;
}
T_2 F_21 ( const T_3 * V_47 , int V_48 )
{
int V_49 ;
T_2 V_50 = 0 ;
if ( V_48 > 4 )
V_48 = 4 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_50 |= ( ( T_2 ) V_47 [ V_49 ] ) << ( ( 3 - V_49 ) * 8 ) ;
return V_50 ;
}
void F_22 ( T_2 V_47 , T_3 * V_51 , int V_52 )
{
int V_49 ;
if ( V_52 > 4 )
V_52 = 4 ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
V_51 [ V_49 ] = V_47 >> ( ( 3 - V_49 ) * 8 ) ;
}
static int
F_23 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_56 ;
if ( F_24 ( V_7 ) )
return 200 ;
V_56 = F_25 ( V_57 ) ;
switch ( V_56 & V_58 ) {
case V_59 :
return 100 ;
case V_60 :
return 133 ;
case V_61 :
return 166 ;
case V_62 :
return 200 ;
case V_63 :
return 266 ;
case V_64 :
return 333 ;
case V_65 :
case V_66 :
return 400 ;
default:
return 133 ;
}
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
V_70 = F_27 ( V_68 ) ;
F_28 ( V_54 , V_70 ) ;
F_29 ( & V_54 -> V_71 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
F_31 ( & V_54 -> V_71 ) ;
V_70 = F_27 ( V_68 ) ;
F_32 ( V_54 , V_70 ) ;
}
static void
F_33 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_72 V_72 = V_1 -> V_73 ;
bool V_74 ;
T_2 V_75 ;
if ( F_11 ( F_25 ( V_1 -> V_76 ) & V_77 ,
L_2 ,
F_34 ( V_72 ) , F_35 ( V_3 -> V_21 ) ) )
return;
F_36 ( L_3 ,
F_34 ( V_72 ) , F_35 ( V_3 -> V_21 ) ) ;
V_75 = F_25 ( V_1 -> V_76 ) & V_78 ;
V_75 |= V_79 | V_80 ;
V_75 |= F_37 ( 1 ) ;
V_75 |= V_81 ;
if ( F_38 ( V_7 ) )
V_75 |= F_39 ( V_72 ) ;
else if ( V_72 == V_82 )
V_75 |= V_83 ;
V_74 = F_25 ( F_40 ( V_72 ) ) & V_84 ;
if ( ! V_74 )
F_41 ( V_7 , V_72 , F_38 ( V_7 ) ?
& V_85 [ 0 ] . V_86 : & V_87 [ 0 ] . V_86 ) ;
F_42 ( V_1 -> V_76 , V_75 ) ;
F_43 ( V_1 -> V_76 ) ;
F_42 ( V_1 -> V_76 , V_75 | V_77 ) ;
F_43 ( V_1 -> V_76 ) ;
F_42 ( V_1 -> V_76 , V_75 & ~ V_77 ) ;
F_43 ( V_1 -> V_76 ) ;
if ( ! V_74 )
F_44 ( V_7 , V_72 ) ;
}
static enum V_72
F_45 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
unsigned int V_88 = ( 1 << V_89 ) | ( 1 << V_82 ) ;
enum V_72 V_72 ;
F_46 ( & V_54 -> V_71 ) ;
F_47 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_73 != V_90 )
return V_1 -> V_73 ;
F_48 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_91 ;
if ( V_68 -> type != V_5 )
continue;
V_91 = F_5 ( & V_68 -> V_4 ) ;
if ( V_91 -> V_73 != V_90 )
V_88 &= ~ ( 1 << V_91 -> V_73 ) ;
}
if ( F_47 ( V_88 == 0 ) )
V_72 = V_89 ;
else
V_72 = F_49 ( V_88 ) - 1 ;
F_50 ( V_7 , V_72 ) ;
V_1 -> V_73 = V_72 ;
F_36 ( L_4 ,
F_34 ( V_1 -> V_73 ) ,
F_35 ( V_3 -> V_21 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
F_33 ( V_1 ) ;
return V_1 -> V_73 ;
}
static bool F_53 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return F_25 ( F_54 ( V_72 ) ) & V_92 ;
}
static bool F_55 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return F_25 ( F_56 ( V_72 ) ) & V_93 ;
}
static bool F_57 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return true ;
}
static enum V_72
F_58 ( struct V_53 * V_54 ,
enum V_21 V_21 ,
T_4 V_94 )
{
enum V_72 V_72 ;
for ( V_72 = V_89 ; V_72 <= V_82 ; V_72 ++ ) {
T_5 V_95 = F_25 ( F_59 ( V_72 ) ) &
V_96 ;
if ( V_95 != F_60 ( V_21 ) )
continue;
if ( ! V_94 ( V_54 , V_72 ) )
continue;
return V_72 ;
}
return V_90 ;
}
static void
F_61 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
F_46 ( & V_54 -> V_71 ) ;
V_1 -> V_73 = F_58 ( V_54 , V_21 ,
F_53 ) ;
if ( V_1 -> V_73 == V_90 )
V_1 -> V_73 = F_58 ( V_54 , V_21 ,
F_55 ) ;
if ( V_1 -> V_73 == V_90 )
V_1 -> V_73 = F_58 ( V_54 , V_21 ,
F_57 ) ;
if ( V_1 -> V_73 == V_90 ) {
F_36 ( L_5 ,
F_35 ( V_21 ) ) ;
return;
}
F_36 ( L_6 ,
F_35 ( V_21 ) , F_34 ( V_1 -> V_73 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
void F_62 ( struct V_53 * V_54 )
{
struct V_6 * V_7 = V_54 -> V_7 ;
struct V_67 * V_68 ;
if ( F_47 ( ! F_24 ( V_7 ) ) )
return;
F_48 (encoder, &dev->mode_config.encoder_list, base.head) {
struct V_1 * V_1 ;
if ( V_68 -> type != V_5 )
continue;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_1 -> V_73 = V_90 ;
}
}
static T_5 F_63 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_64 ( V_7 ) )
return V_97 ;
else
return F_56 ( F_45 ( V_1 ) ) ;
}
static T_5 F_65 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_64 ( V_7 ) )
return V_98 ;
else
return F_54 ( F_45 ( V_1 ) ) ;
}
static int F_66 ( struct V_99 * V_100 , unsigned long V_101 ,
void * V_102 )
{
struct V_1 * V_1 = F_67 ( V_100 , F_68 ( * V_1 ) ,
V_103 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_104 ;
T_5 V_105 , V_106 ;
if ( ! F_1 ( V_1 ) || V_101 != V_107 )
return 0 ;
F_26 ( V_1 ) ;
if ( F_24 ( V_7 ) ) {
enum V_72 V_72 = F_45 ( V_1 ) ;
V_105 = F_56 ( V_72 ) ;
V_106 = F_69 ( V_72 ) ;
V_104 = F_25 ( V_106 ) ;
V_104 &= V_108 ;
F_42 ( V_106 , V_104 | 0x1F ) ;
F_42 ( V_105 , V_109 | V_110 ) ;
F_70 ( V_1 -> V_111 ) ;
}
F_30 ( V_1 ) ;
return 0 ;
}
static bool F_71 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_46 ( & V_54 -> V_71 ) ;
if ( F_24 ( V_7 ) &&
V_1 -> V_73 == V_90 )
return false ;
return ( F_25 ( F_65 ( V_1 ) ) & V_92 ) != 0 ;
}
static bool F_72 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_46 ( & V_54 -> V_71 ) ;
if ( F_24 ( V_7 ) &&
V_1 -> V_73 == V_90 )
return false ;
return F_25 ( F_63 ( V_1 ) ) & V_93 ;
}
static void
F_73 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_71 ( V_1 ) && ! F_72 ( V_1 ) ) {
F_11 ( 1 , L_7 ) ;
F_36 ( L_8 ,
F_25 ( F_65 ( V_1 ) ) ,
F_25 ( F_63 ( V_1 ) ) ) ;
}
}
static T_2
F_74 ( struct V_1 * V_1 , bool V_112 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_113 = V_1 -> V_114 ;
T_2 V_115 ;
bool V_116 ;
#define F_75 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_112 )
V_116 = F_76 ( V_54 -> V_117 , F_75 ,
F_77 ( 10 ) ) ;
else
V_116 = F_78 ( F_75 , 10 ) == 0 ;
if ( ! V_116 )
F_79 ( L_9 ,
V_112 ) ;
#undef F_75
return V_115 ;
}
static T_2 F_80 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_118 ? 0 : F_23 ( V_7 ) / 2 ;
}
static T_2 F_81 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
if ( V_118 )
return 0 ;
if ( V_3 -> V_21 == V_22 ) {
if ( F_82 ( V_7 ) || F_83 ( V_7 ) )
return 200 ;
else
return 225 ;
} else {
return F_84 ( F_85 ( V_7 ) , 2 ) ;
}
}
static T_2 F_86 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_3 -> V_21 == V_22 ) {
if ( V_118 )
return 0 ;
return F_87 ( F_88 ( V_54 ) , 2000 ) ;
} else if ( V_54 -> V_119 == V_120 ) {
switch ( V_118 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_118 ? 0 : F_84 ( F_85 ( V_7 ) , 2 ) ;
}
}
static T_2 F_89 ( struct V_1 * V_1 , int V_118 )
{
return V_118 ? 0 : 100 ;
}
static T_2 F_90 ( struct V_1 * V_1 , int V_118 )
{
return V_118 ? 0 : 1 ;
}
static T_2 F_91 ( struct V_1 * V_1 ,
bool V_112 ,
int V_121 ,
T_2 V_122 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_123 , V_124 ;
if ( F_82 ( V_7 ) )
V_123 = 3 ;
else
V_123 = 5 ;
if ( F_92 ( V_7 ) && V_1 -> V_114 == V_125 )
V_124 = V_126 ;
else
V_124 = V_127 ;
return V_128 |
V_129 |
( V_112 ? V_130 : 0 ) |
V_131 |
V_124 |
V_132 |
( V_121 << V_133 ) |
( V_123 << V_134 ) |
( V_122 << V_135 ) ;
}
static T_2 F_93 ( struct V_1 * V_1 ,
bool V_112 ,
int V_121 ,
T_2 V_102 )
{
return V_128 |
V_129 |
( V_112 ? V_130 : 0 ) |
V_131 |
V_136 |
V_132 |
( V_121 << V_133 ) |
F_94 ( 32 ) ;
}
static int
F_95 ( struct V_1 * V_1 ,
const T_3 * V_137 , int V_121 ,
T_3 * V_138 , int V_139 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_113 = V_1 -> V_114 ;
T_2 V_140 = V_113 + 4 ;
T_2 V_122 ;
int V_49 , V_141 , V_142 ;
T_2 V_115 ;
int V_143 , clock = 0 ;
bool V_112 = F_96 ( V_7 ) ;
bool V_144 ;
F_26 ( V_1 ) ;
V_144 = F_97 ( V_1 ) ;
F_98 ( & V_54 -> V_145 , 0 ) ;
F_73 ( V_1 ) ;
F_99 ( V_54 ) ;
for ( V_143 = 0 ; V_143 < 3 ; V_143 ++ ) {
V_115 = F_100 ( V_113 ) ;
if ( ( V_115 & V_128 ) == 0 )
break;
F_70 ( 1 ) ;
}
if ( V_143 == 3 ) {
F_11 ( 1 , L_10 ,
F_25 ( V_113 ) ) ;
V_141 = - V_146 ;
goto V_147;
}
if ( F_47 ( V_121 > 20 || V_139 > 20 ) ) {
V_141 = - V_148 ;
goto V_147;
}
while ( ( V_122 = V_1 -> V_149 ( V_1 , clock ++ ) ) ) {
T_5 V_150 = V_1 -> V_151 ( V_1 ,
V_112 ,
V_121 ,
V_122 ) ;
for ( V_143 = 0 ; V_143 < 5 ; V_143 ++ ) {
for ( V_49 = 0 ; V_49 < V_121 ; V_49 += 4 )
F_42 ( V_140 + V_49 ,
F_21 ( V_137 + V_49 ,
V_121 - V_49 ) ) ;
F_42 ( V_113 , V_150 ) ;
V_115 = F_74 ( V_1 , V_112 ) ;
F_42 ( V_113 ,
V_115 |
V_129 |
V_131 |
V_132 ) ;
if ( V_115 & ( V_131 |
V_132 ) )
continue;
if ( V_115 & V_129 )
break;
}
if ( V_115 & V_129 )
break;
}
if ( ( V_115 & V_129 ) == 0 ) {
F_79 ( L_11 , V_115 ) ;
V_141 = - V_146 ;
goto V_147;
}
if ( V_115 & V_132 ) {
F_79 ( L_12 , V_115 ) ;
V_141 = - V_152 ;
goto V_147;
}
if ( V_115 & V_131 ) {
F_36 ( L_13 , V_115 ) ;
V_141 = - V_153 ;
goto V_147;
}
V_142 = ( ( V_115 & V_154 ) >>
V_133 ) ;
if ( V_142 > V_139 )
V_142 = V_139 ;
for ( V_49 = 0 ; V_49 < V_142 ; V_49 += 4 )
F_22 ( F_25 ( V_140 + V_49 ) ,
V_138 + V_49 , V_142 - V_49 ) ;
V_141 = V_142 ;
V_147:
F_98 ( & V_54 -> V_145 , V_155 ) ;
F_101 ( V_54 ) ;
if ( V_144 )
F_102 ( V_1 , false ) ;
F_30 ( V_1 ) ;
return V_141 ;
}
static T_6
F_103 ( struct V_156 * V_157 , struct V_158 * V_159 )
{
struct V_1 * V_1 = F_67 ( V_157 , struct V_1 , V_157 ) ;
T_3 V_160 [ 20 ] , V_161 [ 20 ] ;
T_7 V_162 , V_163 ;
int V_141 ;
V_160 [ 0 ] = V_159 -> V_164 << 4 ;
V_160 [ 1 ] = V_159 -> V_165 >> 8 ;
V_160 [ 2 ] = V_159 -> V_165 & 0xff ;
V_160 [ 3 ] = V_159 -> V_166 - 1 ;
switch ( V_159 -> V_164 & ~ V_167 ) {
case V_168 :
case V_169 :
V_162 = V_159 -> V_166 ? V_170 + V_159 -> V_166 : V_171 ;
V_163 = 1 ;
if ( F_47 ( V_162 > 20 ) )
return - V_148 ;
memcpy ( V_160 + V_170 , V_159 -> V_172 , V_159 -> V_166 ) ;
V_141 = F_95 ( V_1 , V_160 , V_162 , V_161 , V_163 ) ;
if ( V_141 > 0 ) {
V_159 -> V_173 = V_161 [ 0 ] >> 4 ;
V_141 = V_159 -> V_166 ;
}
break;
case V_174 :
case V_175 :
V_162 = V_159 -> V_166 ? V_170 : V_171 ;
V_163 = V_159 -> V_166 + 1 ;
if ( F_47 ( V_163 > 20 ) )
return - V_148 ;
V_141 = F_95 ( V_1 , V_160 , V_162 , V_161 , V_163 ) ;
if ( V_141 > 0 ) {
V_159 -> V_173 = V_161 [ 0 ] >> 4 ;
V_141 -- ;
memcpy ( V_159 -> V_172 , V_161 + 1 , V_141 ) ;
}
break;
default:
V_141 = - V_176 ;
break;
}
return V_141 ;
}
static void
F_104 ( struct V_1 * V_1 , struct V_32 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
const char * V_177 = NULL ;
int V_141 ;
switch ( V_21 ) {
case V_22 :
V_1 -> V_114 = V_125 ;
V_177 = L_14 ;
break;
case V_178 :
V_1 -> V_114 = V_179 ;
V_177 = L_15 ;
break;
case V_180 :
V_1 -> V_114 = V_181 ;
V_177 = L_16 ;
break;
case V_182 :
V_1 -> V_114 = V_183 ;
V_177 = L_17 ;
break;
default:
F_105 () ;
}
if ( ! F_8 ( V_7 ) && ! F_92 ( V_7 ) )
V_1 -> V_114 = V_1 -> V_76 + 0x10 ;
V_1 -> V_157 . V_177 = V_177 ;
V_1 -> V_157 . V_7 = V_7 -> V_7 ;
V_1 -> V_157 . V_184 = F_103 ;
F_36 ( L_18 , V_177 ,
V_9 -> V_4 . V_185 -> V_186 . V_177 ) ;
V_141 = F_106 ( & V_1 -> V_157 ) ;
if ( V_141 < 0 ) {
F_79 ( L_19 ,
V_177 , V_141 ) ;
return;
}
V_141 = F_107 ( & V_9 -> V_4 . V_185 -> V_186 ,
& V_1 -> V_157 . V_187 . V_7 . V_186 ,
V_1 -> V_157 . V_187 . V_7 . V_186 . V_177 ) ;
if ( V_141 < 0 ) {
F_79 ( L_20 , V_177 , V_141 ) ;
F_108 ( & V_1 -> V_157 ) ;
}
}
static void
F_109 ( struct V_32 * V_32 )
{
struct V_1 * V_1 = F_4 ( & V_32 -> V_4 ) ;
if ( ! V_32 -> V_188 )
F_110 ( & V_32 -> V_4 . V_185 -> V_186 ,
V_1 -> V_157 . V_187 . V_7 . V_186 . V_177 ) ;
F_111 ( V_32 ) ;
}
static void
F_112 ( struct V_189 * V_190 , int V_191 )
{
T_5 V_192 ;
V_190 -> V_193 = V_194 ;
V_190 -> V_195 . V_196 = 0 ;
V_190 -> V_195 . V_197 = 0 ;
V_192 = F_113 ( V_194 ) ;
switch ( V_191 ) {
case V_14 :
V_192 |= F_114 ( V_198 ,
V_194 ) ;
break;
case V_15 :
V_192 |= F_114 ( V_199 ,
V_194 ) ;
break;
case V_16 :
V_192 |= F_114 ( V_200 ,
V_194 ) ;
break;
}
V_190 -> V_195 . V_192 = V_192 ;
}
static void
F_115 ( struct V_189 * V_190 , int V_191 )
{
switch ( V_191 ) {
case V_14 :
V_190 -> V_193 = V_201 ;
break;
case V_15 :
V_190 -> V_193 = V_202 ;
break;
case V_16 :
V_190 -> V_193 = V_203 ;
break;
}
}
static void
F_116 ( struct V_67 * V_68 ,
struct V_189 * V_190 , int V_191 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
const struct V_204 * V_205 = NULL ;
int V_49 , V_206 = 0 ;
if ( F_117 ( V_7 ) ) {
V_205 = V_207 ;
V_206 = F_118 ( V_207 ) ;
} else if ( F_64 ( V_7 ) ) {
V_205 = V_208 ;
V_206 = F_118 ( V_208 ) ;
} else if ( F_38 ( V_7 ) ) {
V_205 = V_85 ;
V_206 = F_118 ( V_85 ) ;
} else if ( F_24 ( V_7 ) ) {
V_205 = V_87 ;
V_206 = F_118 ( V_87 ) ;
}
if ( V_205 && V_206 ) {
for ( V_49 = 0 ; V_49 < V_206 ; V_49 ++ ) {
if ( V_191 == V_205 [ V_49 ] . V_191 ) {
V_190 -> V_86 = V_205 [ V_49 ] . V_86 ;
V_190 -> V_209 = true ;
break;
}
}
}
}
bool
F_119 ( struct V_67 * V_68 ,
struct V_189 * V_190 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_210 = & V_190 -> V_210 ;
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_211 * V_211 = V_68 -> V_212 ;
struct V_32 * V_32 = V_1 -> V_13 ;
int V_213 , clock ;
int V_214 = 1 ;
int V_215 = F_12 ( V_1 ) ;
int V_216 = 0 ;
int V_217 = F_7 ( V_1 ) >> 3 ;
int V_26 , V_37 ;
static int V_218 [] = { V_14 , V_15 , V_16 } ;
int V_219 , V_220 ;
if ( F_64 ( V_7 ) && ! F_13 ( V_7 ) && V_21 != V_22 )
V_190 -> V_221 = true ;
V_190 -> V_222 = true ;
V_190 -> V_223 = false ;
V_190 -> V_224 = V_1 -> V_224 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
F_120 ( V_32 -> V_34 . V_33 ,
V_210 ) ;
if ( ! F_64 ( V_7 ) )
F_121 ( V_211 , V_190 ,
V_32 -> V_34 . V_225 ) ;
else
F_122 ( V_211 , V_190 ,
V_32 -> V_34 . V_225 ) ;
}
if ( V_210 -> V_43 & V_44 )
return false ;
F_36 ( L_21
L_22 ,
V_215 , V_218 [ V_217 ] ,
V_210 -> V_226 ) ;
V_26 = V_190 -> V_227 ;
if ( F_1 ( V_1 ) ) {
if ( V_54 -> V_228 . V_229 && V_54 -> V_228 . V_229 < V_26 ) {
F_36 ( L_23 ,
V_54 -> V_228 . V_229 ) ;
V_26 = V_54 -> V_228 . V_229 ;
}
V_214 = V_215 ;
V_216 = V_217 ;
}
for (; V_26 >= 6 * 3 ; V_26 -= 2 * 3 ) {
V_37 = F_16 ( V_210 -> V_226 ,
V_26 ) ;
for ( clock = V_216 ; clock <= V_217 ; clock ++ ) {
for ( V_213 = V_214 ; V_213 <= V_215 ; V_213 <<= 1 ) {
V_220 = F_20 ( V_218 [ clock ] ) ;
V_219 = F_17 ( V_220 ,
V_213 ) ;
if ( V_37 <= V_219 ) {
goto V_230;
}
}
}
}
return false ;
V_230:
if ( V_1 -> V_231 ) {
if ( V_26 != 18 && F_123 ( V_210 ) > 1 )
V_1 -> V_232 = V_233 ;
else
V_1 -> V_232 = 0 ;
}
if ( V_1 -> V_232 )
V_190 -> V_234 = true ;
V_1 -> V_191 = V_218 [ clock ] ;
V_1 -> V_213 = V_213 ;
V_190 -> V_227 = V_26 ;
V_190 -> V_235 = F_20 ( V_1 -> V_191 ) ;
F_36 ( L_24 ,
V_1 -> V_191 , V_1 -> V_213 ,
V_190 -> V_235 , V_26 ) ;
F_36 ( L_25 ,
V_37 , V_219 ) ;
F_124 ( V_26 , V_213 ,
V_210 -> V_226 ,
V_190 -> V_235 ,
& V_190 -> V_236 ) ;
if ( V_32 -> V_34 . V_237 != NULL &&
V_1 -> V_238 . type == V_239 ) {
V_190 -> V_223 = true ;
F_124 ( V_26 , V_213 ,
V_32 -> V_34 . V_237 -> clock ,
V_190 -> V_235 ,
& V_190 -> V_240 ) ;
}
if ( F_125 ( V_7 ) && F_1 ( V_1 ) )
F_112 ( V_190 , V_1 -> V_191 ) ;
else if ( F_8 ( V_7 ) || F_92 ( V_7 ) )
F_115 ( V_190 , V_1 -> V_191 ) ;
else
F_116 ( V_68 , V_190 , V_1 -> V_191 ) ;
return true ;
}
static void F_126 ( struct V_1 * V_1 )
{
struct V_2 * V_241 = F_2 ( V_1 ) ;
struct V_211 * V_242 = F_127 ( V_241 -> V_4 . V_4 . V_242 ) ;
struct V_6 * V_7 = V_242 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_243 ;
F_36 ( L_26 , V_242 -> V_244 . V_235 ) ;
V_243 = F_25 ( V_245 ) ;
V_243 &= ~ V_246 ;
if ( V_242 -> V_244 . V_235 == 162000 ) {
F_36 ( L_27 ) ;
V_243 |= V_247 ;
V_1 -> V_75 |= V_247 ;
} else {
V_243 |= V_248 ;
V_1 -> V_75 |= V_248 ;
}
F_42 ( V_245 , V_243 ) ;
F_43 ( V_245 ) ;
F_128 ( 500 ) ;
}
static void F_129 ( struct V_67 * V_68 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_211 * V_242 = F_127 ( V_68 -> V_4 . V_242 ) ;
struct V_30 * V_210 = & V_242 -> V_244 . V_210 ;
V_1 -> V_75 = F_25 ( V_1 -> V_76 ) & V_78 ;
V_1 -> V_75 |= V_79 | V_80 ;
V_1 -> V_75 |= F_37 ( V_1 -> V_213 ) ;
if ( V_242 -> V_244 . V_224 )
V_1 -> V_75 |= V_249 ;
if ( V_21 == V_22 && F_83 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_210 -> V_43 & V_250 )
V_1 -> V_75 |= V_251 ;
if ( V_210 -> V_43 & V_252 )
V_1 -> V_75 |= V_253 ;
V_1 -> V_75 |= V_254 ;
if ( F_130 ( V_1 -> V_11 ) )
V_1 -> V_75 |= V_255 ;
V_1 -> V_75 |= V_242 -> V_72 << 29 ;
} else if ( ! F_131 ( V_7 ) || V_21 == V_22 ) {
if ( ! F_64 ( V_7 ) && ! F_24 ( V_7 ) )
V_1 -> V_75 |= V_1 -> V_232 ;
if ( V_210 -> V_43 & V_250 )
V_1 -> V_75 |= V_251 ;
if ( V_210 -> V_43 & V_252 )
V_1 -> V_75 |= V_253 ;
V_1 -> V_75 |= V_256 ;
if ( F_130 ( V_1 -> V_11 ) )
V_1 -> V_75 |= V_255 ;
if ( ! F_38 ( V_7 ) ) {
if ( V_242 -> V_72 == 1 )
V_1 -> V_75 |= V_83 ;
} else {
V_1 -> V_75 |= F_39 ( V_242 -> V_72 ) ;
}
} else {
V_1 -> V_75 |= V_254 ;
}
}
static void F_132 ( struct V_1 * V_1 ,
T_5 V_257 ,
T_5 V_258 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_259 , V_105 ;
F_46 ( & V_54 -> V_71 ) ;
V_259 = F_65 ( V_1 ) ;
V_105 = F_63 ( V_1 ) ;
F_36 ( L_28 ,
V_257 , V_258 ,
F_25 ( V_259 ) ,
F_25 ( V_105 ) ) ;
if ( F_133 ( ( F_25 ( V_259 ) & V_257 ) == V_258 , 5000 , 10 ) ) {
F_79 ( L_29 ,
F_25 ( V_259 ) ,
F_25 ( V_105 ) ) ;
}
F_36 ( L_30 ) ;
}
static void F_134 ( struct V_1 * V_1 )
{
F_36 ( L_31 ) ;
F_132 ( V_1 , V_260 , V_261 ) ;
}
static void F_135 ( struct V_1 * V_1 )
{
F_36 ( L_32 ) ;
F_132 ( V_1 , V_262 , V_263 ) ;
}
static void F_136 ( struct V_1 * V_1 )
{
F_36 ( L_33 ) ;
F_137 ( V_1 -> V_264 ,
V_1 -> V_111 ) ;
F_132 ( V_1 , V_265 , V_266 ) ;
}
static void F_138 ( struct V_1 * V_1 )
{
F_137 ( V_1 -> V_267 ,
V_1 -> V_268 ) ;
}
static void F_139 ( struct V_1 * V_1 )
{
F_137 ( V_1 -> V_269 ,
V_1 -> V_270 ) ;
}
static T_5 F_140 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_271 ;
F_46 ( & V_54 -> V_71 ) ;
V_271 = F_25 ( F_63 ( V_1 ) ) ;
V_271 &= ~ V_272 ;
V_271 |= V_109 ;
return V_271 ;
}
static bool F_97 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_273 ;
T_5 V_259 , V_105 ;
bool V_274 = ! V_1 -> V_275 ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_141 ( & V_1 -> V_276 ) ;
V_1 -> V_275 = true ;
if ( F_72 ( V_1 ) )
return V_274 ;
V_70 = F_27 ( V_67 ) ;
F_28 ( V_54 , V_70 ) ;
F_36 ( L_34 ,
F_35 ( V_3 -> V_21 ) ) ;
if ( ! F_71 ( V_1 ) )
F_136 ( V_1 ) ;
V_273 = F_140 ( V_1 ) ;
V_273 |= V_93 ;
V_259 = F_65 ( V_1 ) ;
V_105 = F_63 ( V_1 ) ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
F_36 ( L_35 ,
F_25 ( V_259 ) , F_25 ( V_105 ) ) ;
if ( ! F_71 ( V_1 ) ) {
F_36 ( L_36 ,
F_35 ( V_3 -> V_21 ) ) ;
F_70 ( V_1 -> V_277 ) ;
}
return V_274 ;
}
void F_142 ( struct V_1 * V_1 )
{
bool V_144 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
V_144 = F_97 ( V_1 ) ;
F_30 ( V_1 ) ;
F_11 ( ! V_144 , L_37 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) ;
}
static void F_143 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
enum V_69 V_70 ;
T_5 V_273 ;
T_5 V_259 , V_105 ;
F_46 ( & V_54 -> V_71 ) ;
F_47 ( V_1 -> V_275 ) ;
if ( ! F_72 ( V_1 ) )
return;
F_36 ( L_38 ,
F_35 ( V_3 -> V_21 ) ) ;
V_273 = F_140 ( V_1 ) ;
V_273 &= ~ V_93 ;
V_105 = F_63 ( V_1 ) ;
V_259 = F_65 ( V_1 ) ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
F_36 ( L_35 ,
F_25 ( V_259 ) , F_25 ( V_105 ) ) ;
if ( ( V_273 & V_278 ) == 0 )
V_1 -> V_264 = V_279 ;
V_70 = F_27 ( V_67 ) ;
F_32 ( V_54 , V_70 ) ;
}
static void F_144 ( struct V_280 * V_281 )
{
struct V_1 * V_1 = F_67 ( F_145 ( V_281 ) ,
struct V_1 , V_276 ) ;
F_26 ( V_1 ) ;
if ( ! V_1 -> V_275 )
F_143 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_146 ( struct V_1 * V_1 )
{
unsigned long V_282 ;
V_282 = F_147 ( V_1 -> V_111 * 5 ) ;
F_148 ( & V_1 -> V_276 , V_282 ) ;
}
static void F_102 ( struct V_1 * V_1 , bool V_283 )
{
struct V_53 * V_54 =
F_3 ( V_1 ) -> V_55 ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_11 ( ! V_1 -> V_275 , L_39 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) ;
V_1 -> V_275 = false ;
if ( V_283 )
F_143 ( V_1 ) ;
else
F_146 ( V_1 ) ;
}
static void F_149 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_273 ;
T_5 V_105 ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_36 ( L_40 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) ;
if ( F_11 ( F_71 ( V_1 ) ,
L_41 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) )
return;
F_136 ( V_1 ) ;
V_105 = F_63 ( V_1 ) ;
V_273 = F_140 ( V_1 ) ;
if ( F_150 ( V_7 ) ) {
V_273 &= ~ V_284 ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
}
V_273 |= V_278 ;
if ( ! F_150 ( V_7 ) )
V_273 |= V_284 ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
F_134 ( V_1 ) ;
V_1 -> V_267 = V_279 ;
if ( F_150 ( V_7 ) ) {
V_273 |= V_284 ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
}
}
void F_151 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
F_149 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_152 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_273 ;
T_5 V_105 ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_36 ( L_42 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) ;
F_11 ( ! V_1 -> V_275 , L_43 ,
F_35 ( F_2 ( V_1 ) -> V_21 ) ) ;
V_273 = F_140 ( V_1 ) ;
V_273 &= ~ ( V_278 | V_284 | V_93 |
V_285 ) ;
V_105 = F_63 ( V_1 ) ;
V_1 -> V_275 = false ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
V_1 -> V_264 = V_279 ;
F_135 ( V_1 ) ;
V_70 = F_27 ( V_67 ) ;
F_32 ( V_54 , V_70 ) ;
}
void F_153 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
F_152 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_154 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_273 ;
T_5 V_105 ;
F_138 ( V_1 ) ;
F_26 ( V_1 ) ;
V_273 = F_140 ( V_1 ) ;
V_273 |= V_285 ;
V_105 = F_63 ( V_1 ) ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
F_30 ( V_1 ) ;
}
void F_155 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_36 ( L_44 ) ;
F_156 ( V_1 -> V_13 ) ;
F_154 ( V_1 ) ;
}
static void F_157 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_273 ;
T_5 V_105 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
V_273 = F_140 ( V_1 ) ;
V_273 &= ~ V_285 ;
V_105 = F_63 ( V_1 ) ;
F_42 ( V_105 , V_273 ) ;
F_43 ( V_105 ) ;
F_30 ( V_1 ) ;
V_1 -> V_269 = V_279 ;
F_139 ( V_1 ) ;
}
void F_158 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_36 ( L_44 ) ;
F_157 ( V_1 ) ;
F_159 ( V_1 -> V_13 ) ;
}
static void F_160 ( struct V_32 * V_9 ,
bool V_286 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_287 ;
F_26 ( V_1 ) ;
V_287 = F_140 ( V_1 ) & V_285 ;
F_30 ( V_1 ) ;
if ( V_287 == V_286 )
return;
F_36 ( L_45 ,
V_286 ? L_46 : L_47 ) ;
if ( V_286 )
F_154 ( V_1 ) ;
else
F_157 ( V_1 ) ;
}
static void F_161 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_288 * V_242 = V_3 -> V_4 . V_4 . V_242 ;
struct V_6 * V_7 = V_242 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_243 ;
F_162 ( V_54 ,
F_127 ( V_242 ) -> V_72 ) ;
F_36 ( L_44 ) ;
V_243 = F_25 ( V_245 ) ;
F_11 ( V_243 & V_289 , L_48 ) ;
F_11 ( V_243 & V_77 , L_49 ) ;
V_1 -> V_75 &= ~ ( V_77 | V_249 ) ;
V_1 -> V_75 |= V_289 ;
F_42 ( V_245 , V_1 -> V_75 ) ;
F_43 ( V_245 ) ;
F_128 ( 200 ) ;
}
static void F_163 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_288 * V_242 = V_3 -> V_4 . V_4 . V_242 ;
struct V_6 * V_7 = V_242 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_243 ;
F_162 ( V_54 ,
F_127 ( V_242 ) -> V_72 ) ;
V_243 = F_25 ( V_245 ) ;
F_11 ( ( V_243 & V_289 ) == 0 ,
L_50 ) ;
F_11 ( V_243 & V_77 , L_49 ) ;
V_243 &= ~ V_289 ;
F_42 ( V_245 , V_243 ) ;
F_43 ( V_245 ) ;
F_128 ( 200 ) ;
}
void F_164 ( struct V_1 * V_1 , int V_31 )
{
int V_141 , V_49 ;
if ( V_1 -> V_11 [ V_18 ] < 0x11 )
return;
if ( V_31 != V_290 ) {
V_141 = F_165 ( & V_1 -> V_157 , V_291 ,
V_292 ) ;
} else {
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_141 = F_165 ( & V_1 -> V_157 , V_291 ,
V_293 ) ;
if ( V_141 == 1 )
break;
F_70 ( 1 ) ;
}
}
if ( V_141 != 1 )
F_36 ( L_51 ,
V_31 == V_290 ? L_46 : L_47 ) ;
}
static bool F_166 ( struct V_67 * V_68 ,
enum V_72 * V_72 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_91 ;
V_70 = F_27 ( V_68 ) ;
if ( ! F_167 ( V_54 , V_70 ) )
return false ;
V_91 = F_25 ( V_1 -> V_76 ) ;
if ( ! ( V_91 & V_77 ) )
return false ;
if ( V_21 == V_22 && F_83 ( V_7 ) && ! F_24 ( V_7 ) ) {
* V_72 = F_168 ( V_91 ) ;
} else if ( F_38 ( V_7 ) ) {
* V_72 = F_169 ( V_91 ) ;
} else if ( ! F_131 ( V_7 ) || V_21 == V_22 ) {
* V_72 = F_170 ( V_91 ) ;
} else {
T_5 V_294 ;
T_5 V_295 ;
int V_49 ;
switch ( V_1 -> V_76 ) {
case V_296 :
V_294 = V_297 ;
break;
case V_298 :
V_294 = V_299 ;
break;
case V_300 :
V_294 = V_301 ;
break;
default:
return true ;
}
F_171 (dev_priv, i) {
V_295 = F_25 ( F_172 ( V_49 ) ) ;
if ( ( V_295 & V_302 ) == V_294 ) {
* V_72 = V_49 ;
return true ;
}
}
F_36 ( L_52 ,
V_1 -> V_76 ) ;
}
return true ;
}
static void F_173 ( struct V_67 * V_68 ,
struct V_189 * V_190 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
T_5 V_91 , V_43 = 0 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_211 * V_242 = F_127 ( V_68 -> V_4 . V_242 ) ;
int V_303 ;
V_91 = F_25 ( V_1 -> V_76 ) ;
if ( V_91 & V_249 )
V_190 -> V_224 = true ;
if ( ( V_21 == V_22 ) || ! F_131 ( V_7 ) ) {
if ( V_91 & V_251 )
V_43 |= V_250 ;
else
V_43 |= V_304 ;
if ( V_91 & V_253 )
V_43 |= V_252 ;
else
V_43 |= V_305 ;
} else {
V_91 = F_25 ( F_172 ( V_242 -> V_72 ) ) ;
if ( V_91 & V_306 )
V_43 |= V_250 ;
else
V_43 |= V_304 ;
if ( V_91 & V_307 )
V_43 |= V_252 ;
else
V_43 |= V_305 ;
}
V_190 -> V_210 . V_43 |= V_43 ;
if ( ! F_64 ( V_7 ) && ! F_24 ( V_7 ) &&
V_91 & V_233 )
V_190 -> V_234 = true ;
V_190 -> V_222 = true ;
F_174 ( V_242 , V_190 ) ;
if ( V_21 == V_22 ) {
if ( ( F_25 ( V_245 ) & V_246 ) == V_247 )
V_190 -> V_235 = 162000 ;
else
V_190 -> V_235 = 270000 ;
}
V_303 = F_175 ( V_190 -> V_235 ,
& V_190 -> V_236 ) ;
if ( F_64 ( V_54 -> V_7 ) && V_21 != V_22 )
F_176 ( V_190 , V_303 ) ;
V_190 -> V_210 . V_226 = V_303 ;
if ( F_1 ( V_1 ) && V_54 -> V_228 . V_229 &&
V_190 -> V_227 > V_54 -> V_228 . V_229 ) {
F_36 ( L_53 ,
V_190 -> V_227 , V_54 -> V_228 . V_229 ) ;
V_54 -> V_228 . V_229 = V_190 -> V_227 ;
}
}
static void F_177 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_211 * V_242 = F_127 ( V_68 -> V_4 . V_242 ) ;
if ( V_242 -> V_244 . V_224 )
F_178 ( V_68 ) ;
F_142 ( V_1 ) ;
F_158 ( V_1 ) ;
F_164 ( V_1 , V_308 ) ;
F_153 ( V_1 ) ;
if ( F_10 ( V_7 ) -> V_17 < 5 )
F_179 ( V_1 ) ;
}
static void F_180 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
F_179 ( V_1 ) ;
if ( V_21 == V_22 )
F_163 ( V_1 ) ;
}
static void F_181 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_179 ( V_1 ) ;
}
static void F_182 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 =
F_127 ( V_68 -> V_4 . V_242 ) ;
enum V_310 V_311 = F_183 ( V_309 ) ;
enum V_72 V_72 = V_211 -> V_72 ;
T_5 V_312 ;
F_179 ( V_1 ) ;
F_29 ( & V_54 -> V_313 ) ;
V_312 = F_184 ( V_54 , V_72 , F_185 ( V_311 ) ) ;
V_312 |= V_314 ;
F_186 ( V_54 , V_72 , F_185 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_187 ( V_311 ) ) ;
V_312 |= V_314 ;
F_186 ( V_54 , V_72 , F_187 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_188 ( V_311 ) ) ;
V_312 &= ~ ( V_315 | V_316 ) ;
F_186 ( V_54 , V_72 , F_188 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_189 ( V_311 ) ) ;
V_312 &= ~ ( V_315 | V_316 ) ;
F_186 ( V_54 , V_72 , F_189 ( V_311 ) , V_312 ) ;
F_31 ( & V_54 -> V_313 ) ;
}
static void
F_190 ( struct V_1 * V_1 ,
T_2 * V_75 ,
T_3 V_317 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
if ( F_13 ( V_7 ) ) {
T_2 V_318 = F_25 ( F_191 ( V_21 ) ) ;
if ( V_317 & V_319 )
V_318 |= V_320 ;
else
V_318 &= ~ V_320 ;
V_318 &= ~ V_321 ;
switch ( V_317 & V_322 ) {
case V_323 :
V_318 |= V_324 ;
break;
case V_325 :
V_318 |= V_326 ;
break;
case V_327 :
V_318 |= V_328 ;
break;
case V_329 :
V_318 |= V_330 ;
break;
}
F_42 ( F_191 ( V_21 ) , V_318 ) ;
} else if ( F_131 ( V_7 ) && ( F_83 ( V_7 ) || V_21 != V_22 ) ) {
* V_75 &= ~ V_331 ;
switch ( V_317 & V_322 ) {
case V_323 :
* V_75 |= V_254 ;
break;
case V_325 :
* V_75 |= V_332 ;
break;
case V_327 :
* V_75 |= V_333 ;
break;
case V_329 :
F_79 ( L_54 ) ;
* V_75 |= V_333 ;
break;
}
} else {
if ( F_38 ( V_7 ) )
* V_75 &= ~ V_334 ;
else
* V_75 &= ~ V_335 ;
switch ( V_317 & V_322 ) {
case V_323 :
* V_75 |= V_256 ;
break;
case V_325 :
* V_75 |= V_81 ;
break;
case V_327 :
* V_75 |= V_336 ;
break;
case V_329 :
if ( F_38 ( V_7 ) ) {
* V_75 |= V_337 ;
} else {
F_79 ( L_54 ) ;
* V_75 |= V_336 ;
}
break;
}
}
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_190 ( V_1 , & V_1 -> V_75 ,
V_325 ) ;
F_42 ( V_1 -> V_76 , V_1 -> V_75 ) ;
F_43 ( V_1 -> V_76 ) ;
V_1 -> V_75 |= V_77 ;
F_42 ( V_1 -> V_76 , V_1 -> V_75 ) ;
F_43 ( V_1 -> V_76 ) ;
}
static void F_193 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_242 = F_127 ( V_68 -> V_4 . V_242 ) ;
T_2 V_338 = F_25 ( V_1 -> V_76 ) ;
if ( F_47 ( V_338 & V_77 ) )
return;
F_26 ( V_1 ) ;
if ( F_24 ( V_7 ) )
F_194 ( V_1 ) ;
F_192 ( V_1 ) ;
F_97 ( V_1 ) ;
F_149 ( V_1 ) ;
F_102 ( V_1 , true ) ;
F_30 ( V_1 ) ;
if ( F_24 ( V_7 ) )
F_195 ( V_54 , F_2 ( V_1 ) ) ;
F_164 ( V_1 , V_290 ) ;
F_196 ( V_1 ) ;
F_197 ( V_1 ) ;
F_198 ( V_1 ) ;
if ( V_242 -> V_244 . V_224 ) {
F_199 ( L_55 ,
F_34 ( V_242 -> V_72 ) ) ;
F_200 ( V_68 ) ;
}
}
static void F_201 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_193 ( V_68 ) ;
F_155 ( V_1 ) ;
}
static void F_202 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_155 ( V_1 ) ;
}
static void F_203 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
F_129 ( V_68 ) ;
if ( V_309 -> V_21 == V_22 ) {
F_126 ( V_1 ) ;
F_161 ( V_1 ) ;
}
}
static void F_204 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 = V_3 -> V_4 . V_4 . V_7 -> V_55 ;
enum V_72 V_72 = V_1 -> V_73 ;
int V_339 = F_59 ( V_72 ) ;
F_143 ( V_1 ) ;
F_36 ( L_56 ,
F_34 ( V_72 ) , F_35 ( V_3 -> V_21 ) ) ;
F_42 ( V_339 , 0 ) ;
F_43 ( V_339 ) ;
V_1 -> V_73 = V_90 ;
}
static void F_50 ( struct V_6 * V_7 ,
enum V_72 V_72 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
F_46 ( & V_54 -> V_71 ) ;
if ( F_47 ( V_72 != V_89 && V_72 != V_82 ) )
return;
F_48 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_1 ;
enum V_21 V_21 ;
if ( V_68 -> type != V_5 )
continue;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_21 = F_2 ( V_1 ) -> V_21 ;
if ( V_1 -> V_73 != V_72 )
continue;
F_36 ( L_57 ,
F_34 ( V_72 ) , F_35 ( V_21 ) ) ;
F_11 ( V_68 -> V_340 ,
L_58 ,
F_34 ( V_72 ) , F_35 ( V_21 ) ) ;
F_204 ( V_1 ) ;
}
}
static void F_194 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_242 = F_127 ( V_68 -> V_4 . V_242 ) ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_73 == V_242 -> V_72 )
return;
if ( V_1 -> V_73 != V_90 )
F_204 ( V_1 ) ;
F_50 ( V_7 , V_242 -> V_72 ) ;
V_1 -> V_73 = V_242 -> V_72 ;
F_36 ( L_59 ,
F_34 ( V_1 -> V_73 ) , F_35 ( V_3 -> V_21 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
static void F_205 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 = F_127 ( V_68 -> V_4 . V_242 ) ;
enum V_310 V_21 = F_183 ( V_309 ) ;
int V_72 = V_211 -> V_72 ;
T_5 V_312 ;
F_29 ( & V_54 -> V_313 ) ;
V_312 = F_184 ( V_54 , V_72 , F_206 ( V_21 ) ) ;
V_312 = 0 ;
if ( V_72 )
V_312 |= ( 1 << 21 ) ;
else
V_312 &= ~ ( 1 << 21 ) ;
V_312 |= 0x001000c4 ;
F_186 ( V_54 , V_72 , F_207 ( V_21 ) , V_312 ) ;
F_186 ( V_54 , V_72 , F_208 ( V_21 ) , 0x00760018 ) ;
F_186 ( V_54 , V_72 , F_209 ( V_21 ) , 0x00400888 ) ;
F_31 ( & V_54 -> V_313 ) ;
F_193 ( V_68 ) ;
}
static void F_210 ( struct V_67 * V_68 )
{
struct V_2 * V_309 = F_211 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 =
F_127 ( V_68 -> V_4 . V_242 ) ;
enum V_310 V_21 = F_183 ( V_309 ) ;
int V_72 = V_211 -> V_72 ;
F_129 ( V_68 ) ;
F_29 ( & V_54 -> V_313 ) ;
F_186 ( V_54 , V_72 , F_212 ( V_21 ) ,
V_315 |
V_316 ) ;
F_186 ( V_54 , V_72 , F_213 ( V_21 ) ,
V_341 |
V_342 |
( 1 << V_343 ) |
V_344 ) ;
F_186 ( V_54 , V_72 , F_214 ( V_21 ) , 0x00750f00 ) ;
F_186 ( V_54 , V_72 , F_215 ( V_21 ) , 0x00001500 ) ;
F_186 ( V_54 , V_72 , F_216 ( V_21 ) , 0x40400000 ) ;
F_31 ( & V_54 -> V_313 ) ;
}
static void F_217 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 =
F_127 ( V_68 -> V_4 . V_242 ) ;
enum V_310 V_311 = F_183 ( V_309 ) ;
int V_72 = V_211 -> V_72 ;
int V_345 , V_49 ;
T_5 V_312 ;
F_29 ( & V_54 -> V_313 ) ;
V_312 = F_184 ( V_54 , V_72 , F_218 ( V_311 ) ) ;
V_312 &= ~ V_346 ;
F_186 ( V_54 , V_72 , F_218 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_219 ( V_311 ) ) ;
V_312 &= ~ V_346 ;
F_186 ( V_54 , V_72 , F_219 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_185 ( V_311 ) ) ;
V_312 |= V_314 ;
F_186 ( V_54 , V_72 , F_185 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_187 ( V_311 ) ) ;
V_312 |= V_314 ;
F_186 ( V_54 , V_72 , F_187 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_188 ( V_311 ) ) ;
V_312 |= ( V_315 | V_316 ) ;
F_186 ( V_54 , V_72 , F_188 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_189 ( V_311 ) ) ;
V_312 |= ( V_315 | V_316 ) ;
F_186 ( V_54 , V_72 , F_189 ( V_311 ) , V_312 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_345 = ( V_49 == 1 ) ? 0x0 : 0x6 ;
F_186 ( V_54 , V_72 , F_220 ( V_311 , V_49 ) ,
V_345 << V_347 ) ;
V_345 = ( V_49 == 1 ) ? 0x0 : 0x1 ;
F_186 ( V_54 , V_72 , F_221 ( V_311 , V_49 ) ,
V_345 << V_348 ) ;
}
F_31 ( & V_54 -> V_313 ) ;
F_193 ( V_68 ) ;
}
static void F_222 ( struct V_67 * V_68 )
{
struct V_2 * V_309 = F_211 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 =
F_127 ( V_68 -> V_4 . V_242 ) ;
enum V_310 V_311 = F_183 ( V_309 ) ;
enum V_72 V_72 = V_211 -> V_72 ;
T_5 V_312 ;
F_129 ( V_68 ) ;
F_29 ( & V_54 -> V_313 ) ;
if ( V_72 != V_82 ) {
V_312 = F_184 ( V_54 , V_72 , V_349 ) ;
V_312 &= ~ ( V_350 | V_351 ) ;
if ( V_311 == V_352 )
V_312 |= V_353 ;
if ( V_311 == V_354 )
V_312 |= V_355 ;
F_186 ( V_54 , V_72 , V_349 , V_312 ) ;
} else {
V_312 = F_184 ( V_54 , V_72 , V_356 ) ;
V_312 &= ~ ( V_357 | V_358 ) ;
if ( V_311 == V_352 )
V_312 |= V_359 ;
if ( V_311 == V_354 )
V_312 |= V_360 ;
F_186 ( V_54 , V_72 , V_356 , V_312 ) ;
}
V_312 = F_184 ( V_54 , V_72 , F_206 ( V_311 ) ) ;
V_312 |= V_361 ;
if ( V_72 != V_82 )
V_312 &= ~ V_362 ;
else
V_312 |= V_362 ;
F_186 ( V_54 , V_72 , F_206 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_223 ( V_311 ) ) ;
V_312 |= V_361 ;
if ( V_72 != V_82 )
V_312 &= ~ V_362 ;
else
V_312 |= V_362 ;
F_186 ( V_54 , V_72 , F_223 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_224 ( V_311 ) ) ;
if ( V_72 != V_82 )
V_312 &= ~ V_363 ;
else
V_312 |= V_363 ;
F_186 ( V_54 , V_72 , F_224 ( V_311 ) , V_312 ) ;
F_31 ( & V_54 -> V_313 ) ;
}
static T_6
F_225 ( struct V_156 * V_157 , unsigned int V_364 ,
void * V_172 , T_7 V_166 )
{
T_6 V_141 ;
int V_49 ;
F_226 ( V_157 , V_18 , V_172 , 1 ) ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_141 = F_226 ( V_157 , V_364 , V_172 , V_166 ) ;
if ( V_141 == V_166 )
return V_141 ;
F_70 ( 1 ) ;
}
return V_141 ;
}
static bool
F_227 ( struct V_1 * V_1 , T_3 V_365 [ V_366 ] )
{
return F_225 ( & V_1 -> V_157 ,
V_367 ,
V_365 ,
V_366 ) == V_366 ;
}
static T_3
F_228 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_10 ( V_7 ) -> V_17 >= 9 )
return V_368 ;
else if ( F_24 ( V_7 ) )
return V_369 ;
else if ( F_83 ( V_7 ) && V_21 == V_22 )
return V_368 ;
else if ( F_131 ( V_7 ) && V_21 != V_22 )
return V_369 ;
else
return V_368 ;
}
static T_3
F_229 ( struct V_1 * V_1 , T_3 V_370 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_10 ( V_7 ) -> V_17 >= 9 ) {
switch ( V_370 & V_371 ) {
case V_372 :
return V_373 ;
case V_374 :
return V_375 ;
case V_368 :
return V_376 ;
default:
return V_377 ;
}
} else if ( F_8 ( V_7 ) || F_92 ( V_7 ) ) {
switch ( V_370 & V_371 ) {
case V_372 :
return V_373 ;
case V_374 :
return V_375 ;
case V_368 :
return V_376 ;
case V_369 :
default:
return V_377 ;
}
} else if ( F_24 ( V_7 ) ) {
switch ( V_370 & V_371 ) {
case V_372 :
return V_373 ;
case V_374 :
return V_375 ;
case V_368 :
return V_376 ;
case V_369 :
default:
return V_377 ;
}
} else if ( F_83 ( V_7 ) && V_21 == V_22 ) {
switch ( V_370 & V_371 ) {
case V_372 :
return V_375 ;
case V_374 :
case V_368 :
return V_376 ;
default:
return V_377 ;
}
} else {
switch ( V_370 & V_371 ) {
case V_372 :
return V_375 ;
case V_374 :
return V_375 ;
case V_368 :
return V_376 ;
case V_369 :
default:
return V_377 ;
}
}
}
static T_2 F_230 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
struct V_211 * V_211 =
F_127 ( V_309 -> V_4 . V_4 . V_242 ) ;
unsigned long V_378 , V_379 ,
V_380 ;
T_3 V_381 = V_1 -> V_381 [ 0 ] ;
enum V_310 V_21 = F_183 ( V_309 ) ;
int V_72 = V_211 -> V_72 ;
switch ( V_381 & V_382 ) {
case V_377 :
V_379 = 0x0004000 ;
switch ( V_381 & V_371 ) {
case V_372 :
V_378 = 0x2B405555 ;
V_380 = 0x552AB83A ;
break;
case V_374 :
V_378 = 0x2B404040 ;
V_380 = 0x5548B83A ;
break;
case V_368 :
V_378 = 0x2B245555 ;
V_380 = 0x5560B83A ;
break;
case V_369 :
V_378 = 0x2B405555 ;
V_380 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_376 :
V_379 = 0x0002000 ;
switch ( V_381 & V_371 ) {
case V_372 :
V_378 = 0x2B404040 ;
V_380 = 0x5552B83A ;
break;
case V_374 :
V_378 = 0x2B404848 ;
V_380 = 0x5580B83A ;
break;
case V_368 :
V_378 = 0x2B404040 ;
V_380 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_375 :
V_379 = 0x0000000 ;
switch ( V_381 & V_371 ) {
case V_372 :
V_378 = 0x2B305555 ;
V_380 = 0x5570B83A ;
break;
case V_374 :
V_378 = 0x2B2B4040 ;
V_380 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_373 :
V_379 = 0x0006000 ;
switch ( V_381 & V_371 ) {
case V_372 :
V_378 = 0x1B405555 ;
V_380 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_29 ( & V_54 -> V_313 ) ;
F_186 ( V_54 , V_72 , F_231 ( V_21 ) , 0x00000000 ) ;
F_186 ( V_54 , V_72 , F_232 ( V_21 ) , V_378 ) ;
F_186 ( V_54 , V_72 , F_233 ( V_21 ) ,
V_380 ) ;
F_186 ( V_54 , V_72 , F_234 ( V_21 ) , 0x0C782040 ) ;
F_186 ( V_54 , V_72 , F_235 ( V_21 ) , 0x00030000 ) ;
F_186 ( V_54 , V_72 , F_236 ( V_21 ) , V_379 ) ;
F_186 ( V_54 , V_72 , F_231 ( V_21 ) , 0x80000000 ) ;
F_31 ( & V_54 -> V_313 ) ;
return 0 ;
}
static T_2 F_237 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_309 = F_2 ( V_1 ) ;
struct V_211 * V_211 = F_127 ( V_309 -> V_4 . V_4 . V_242 ) ;
T_5 V_383 , V_384 , V_312 ;
T_3 V_381 = V_1 -> V_381 [ 0 ] ;
enum V_310 V_311 = F_183 ( V_309 ) ;
enum V_72 V_72 = V_211 -> V_72 ;
int V_49 ;
switch ( V_381 & V_382 ) {
case V_377 :
switch ( V_381 & V_371 ) {
case V_372 :
V_383 = 128 ;
V_384 = 52 ;
break;
case V_374 :
V_383 = 128 ;
V_384 = 77 ;
break;
case V_368 :
V_383 = 128 ;
V_384 = 102 ;
break;
case V_369 :
V_383 = 128 ;
V_384 = 154 ;
break;
default:
return 0 ;
}
break;
case V_376 :
switch ( V_381 & V_371 ) {
case V_372 :
V_383 = 85 ;
V_384 = 78 ;
break;
case V_374 :
V_383 = 85 ;
V_384 = 116 ;
break;
case V_368 :
V_383 = 85 ;
V_384 = 154 ;
break;
default:
return 0 ;
}
break;
case V_375 :
switch ( V_381 & V_371 ) {
case V_372 :
V_383 = 64 ;
V_384 = 104 ;
break;
case V_374 :
V_383 = 64 ;
V_384 = 154 ;
break;
default:
return 0 ;
}
break;
case V_373 :
switch ( V_381 & V_371 ) {
case V_372 :
V_383 = 43 ;
V_384 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_29 ( & V_54 -> V_313 ) ;
V_312 = F_184 ( V_54 , V_72 , F_238 ( V_311 ) ) ;
V_312 &= ~ ( V_385 | V_386 ) ;
V_312 &= ~ ( V_387 | V_388 ) ;
V_312 |= V_389 | V_390 ;
F_186 ( V_54 , V_72 , F_238 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_239 ( V_311 ) ) ;
V_312 &= ~ ( V_385 | V_386 ) ;
V_312 &= ~ ( V_387 | V_388 ) ;
V_312 |= V_389 | V_390 ;
F_186 ( V_54 , V_72 , F_239 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_240 ( V_311 ) ) ;
V_312 &= ~ ( V_391 | V_392 ) ;
V_312 |= V_393 | V_394 ;
F_186 ( V_54 , V_72 , F_240 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_241 ( V_311 ) ) ;
V_312 &= ~ ( V_391 | V_392 ) ;
V_312 |= V_393 | V_394 ;
F_186 ( V_54 , V_72 , F_241 ( V_311 ) , V_312 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_312 = F_184 ( V_54 , V_72 , F_242 ( V_311 , V_49 ) ) ;
V_312 &= ~ V_395 ;
V_312 |= V_383 << V_396 ;
F_186 ( V_54 , V_72 , F_242 ( V_311 , V_49 ) , V_312 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_312 = F_184 ( V_54 , V_72 , F_243 ( V_311 , V_49 ) ) ;
V_312 &= ~ V_397 ;
V_312 |= V_384 << V_398 ;
F_186 ( V_54 , V_72 , F_243 ( V_311 , V_49 ) , V_312 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_312 = F_184 ( V_54 , V_72 , F_244 ( V_311 , V_49 ) ) ;
V_312 &= ~ V_399 ;
F_186 ( V_54 , V_72 , F_244 ( V_311 , V_49 ) , V_312 ) ;
}
if ( ( ( V_381 & V_382 )
== V_377 ) &&
( ( V_381 & V_371 )
== V_369 ) ) {
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_312 = F_184 ( V_54 , V_72 , F_244 ( V_311 , V_49 ) ) ;
V_312 |= V_399 ;
F_186 ( V_54 , V_72 , F_244 ( V_311 , V_49 ) , V_312 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_312 = F_184 ( V_54 , V_72 , F_243 ( V_311 , V_49 ) ) ;
V_312 &= ~ ( 0xff << V_400 ) ;
V_312 |= ( 0x9a << V_400 ) ;
F_186 ( V_54 , V_72 , F_243 ( V_311 , V_49 ) , V_312 ) ;
}
}
V_312 = F_184 ( V_54 , V_72 , F_238 ( V_311 ) ) ;
V_312 |= V_385 | V_386 ;
F_186 ( V_54 , V_72 , F_238 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , F_239 ( V_311 ) ) ;
V_312 |= V_385 | V_386 ;
F_186 ( V_54 , V_72 , F_239 ( V_311 ) , V_312 ) ;
V_312 = F_184 ( V_54 , V_72 , V_401 ) ;
V_312 |= V_402 ;
F_186 ( V_54 , V_72 , V_401 , V_312 ) ;
F_31 ( & V_54 -> V_313 ) ;
return 0 ;
}
static void
F_245 ( struct V_1 * V_1 ,
const T_3 V_365 [ V_366 ] )
{
T_3 V_50 = 0 ;
T_3 V_403 = 0 ;
int V_404 ;
T_3 V_405 ;
T_3 V_406 ;
for ( V_404 = 0 ; V_404 < V_1 -> V_213 ; V_404 ++ ) {
T_3 V_407 = F_246 ( V_365 , V_404 ) ;
T_3 V_408 = F_247 ( V_365 , V_404 ) ;
if ( V_407 > V_50 )
V_50 = V_407 ;
if ( V_408 > V_403 )
V_403 = V_408 ;
}
V_405 = F_228 ( V_1 ) ;
if ( V_50 >= V_405 )
V_50 = V_405 | V_409 ;
V_406 = F_229 ( V_1 , V_50 ) ;
if ( V_403 >= V_406 )
V_403 = V_406 | V_410 ;
for ( V_404 = 0 ; V_404 < 4 ; V_404 ++ )
V_1 -> V_381 [ V_404 ] = V_50 | V_403 ;
}
static T_2
F_248 ( T_3 V_381 )
{
T_2 V_411 = 0 ;
switch ( V_381 & V_371 ) {
case V_372 :
default:
V_411 |= V_79 ;
break;
case V_374 :
V_411 |= V_412 ;
break;
case V_368 :
V_411 |= V_413 ;
break;
case V_369 :
V_411 |= V_414 ;
break;
}
switch ( V_381 & V_382 ) {
case V_377 :
default:
V_411 |= V_80 ;
break;
case V_376 :
V_411 |= V_415 ;
break;
case V_375 :
V_411 |= V_416 ;
break;
case V_373 :
V_411 |= V_417 ;
break;
}
return V_411 ;
}
static T_2
F_249 ( T_3 V_381 )
{
int V_411 = V_381 & ( V_371 |
V_382 ) ;
switch ( V_411 ) {
case V_372 | V_377 :
case V_374 | V_377 :
return V_418 ;
case V_372 | V_376 :
return V_419 ;
case V_372 | V_375 :
case V_374 | V_375 :
return V_420 ;
case V_374 | V_376 :
case V_368 | V_376 :
return V_421 ;
case V_368 | V_377 :
case V_369 | V_377 :
return V_422 ;
default:
F_36 ( L_60
L_61 , V_411 ) ;
return V_418 ;
}
}
static T_2
F_250 ( T_3 V_381 )
{
int V_411 = V_381 & ( V_371 |
V_382 ) ;
switch ( V_411 ) {
case V_372 | V_377 :
return V_423 ;
case V_372 | V_376 :
return V_424 ;
case V_372 | V_375 :
return V_425 ;
case V_374 | V_377 :
return V_426 ;
case V_374 | V_376 :
return V_427 ;
case V_368 | V_377 :
return V_428 ;
case V_368 | V_376 :
return V_429 ;
default:
F_36 ( L_60
L_61 , V_411 ) ;
return V_430 ;
}
}
static T_2
F_251 ( T_3 V_381 )
{
int V_411 = V_381 & ( V_371 |
V_382 ) ;
switch ( V_411 ) {
case V_372 | V_377 :
return F_252 ( 0 ) ;
case V_372 | V_376 :
return F_252 ( 1 ) ;
case V_372 | V_375 :
return F_252 ( 2 ) ;
case V_372 | V_373 :
return F_252 ( 3 ) ;
case V_374 | V_377 :
return F_252 ( 4 ) ;
case V_374 | V_376 :
return F_252 ( 5 ) ;
case V_374 | V_375 :
return F_252 ( 6 ) ;
case V_368 | V_377 :
return F_252 ( 7 ) ;
case V_368 | V_376 :
return F_252 ( 8 ) ;
default:
F_36 ( L_60
L_61 , V_411 ) ;
return F_252 ( 0 ) ;
}
}
static void
F_253 ( struct V_1 * V_1 , T_2 * V_75 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_411 , V_257 ;
T_3 V_381 = V_1 -> V_381 [ 0 ] ;
if ( F_8 ( V_7 ) || F_92 ( V_7 ) || F_10 ( V_7 ) -> V_17 >= 9 ) {
V_411 = F_251 ( V_381 ) ;
V_257 = V_431 ;
} else if ( F_38 ( V_7 ) ) {
V_411 = F_237 ( V_1 ) ;
V_257 = 0 ;
} else if ( F_24 ( V_7 ) ) {
V_411 = F_230 ( V_1 ) ;
V_257 = 0 ;
} else if ( F_83 ( V_7 ) && V_21 == V_22 ) {
V_411 = F_250 ( V_381 ) ;
V_257 = V_432 ;
} else if ( F_82 ( V_7 ) && V_21 == V_22 ) {
V_411 = F_249 ( V_381 ) ;
V_257 = V_433 ;
} else {
V_411 = F_248 ( V_381 ) ;
V_257 = V_434 | V_435 ;
}
F_36 ( L_62 , V_411 ) ;
* V_75 = ( * V_75 & ~ V_257 ) | V_411 ;
}
static bool
F_254 ( struct V_1 * V_1 ,
T_2 * V_75 ,
T_3 V_317 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_3 V_436 [ sizeof( V_1 -> V_381 ) + 1 ] ;
int V_141 , V_437 ;
F_190 ( V_1 , V_75 , V_317 ) ;
F_42 ( V_1 -> V_76 , * V_75 ) ;
F_43 ( V_1 -> V_76 ) ;
V_436 [ 0 ] = V_317 ;
if ( ( V_317 & V_322 ) ==
V_323 ) {
V_437 = 1 ;
} else {
memcpy ( V_436 + 1 , V_1 -> V_381 , V_1 -> V_213 ) ;
V_437 = V_1 -> V_213 + 1 ;
}
V_141 = F_255 ( & V_1 -> V_157 , V_438 ,
V_436 , V_437 ) ;
return V_141 == V_437 ;
}
static bool
F_256 ( struct V_1 * V_1 , T_2 * V_75 ,
T_3 V_317 )
{
memset ( V_1 -> V_381 , 0 , sizeof( V_1 -> V_381 ) ) ;
F_253 ( V_1 , V_75 ) ;
return F_254 ( V_1 , V_75 , V_317 ) ;
}
static bool
F_257 ( struct V_1 * V_1 , T_2 * V_75 ,
const T_3 V_365 [ V_366 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
int V_141 ;
F_245 ( V_1 , V_365 ) ;
F_253 ( V_1 , V_75 ) ;
F_42 ( V_1 -> V_76 , * V_75 ) ;
F_43 ( V_1 -> V_76 ) ;
V_141 = F_255 ( & V_1 -> V_157 , V_439 ,
V_1 -> V_381 , V_1 -> V_213 ) ;
return V_141 == V_1 -> V_213 ;
}
static void F_258 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_2 V_312 ;
if ( ! F_13 ( V_7 ) )
return;
V_312 = F_25 ( F_191 ( V_21 ) ) ;
V_312 &= ~ V_321 ;
V_312 |= V_440 ;
F_42 ( F_191 ( V_21 ) , V_312 ) ;
if ( V_21 == V_22 )
return;
if ( F_259 ( ( F_25 ( F_260 ( V_21 ) ) & V_441 ) ,
1 ) )
F_79 ( L_63 ) ;
}
void
F_196 ( struct V_1 * V_1 )
{
struct V_442 * V_68 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_68 -> V_7 ;
int V_49 ;
T_3 V_443 ;
int V_444 , V_445 ;
T_2 V_75 = V_1 -> V_75 ;
T_3 V_446 [ 2 ] ;
if ( F_13 ( V_7 ) )
F_261 ( V_68 ) ;
V_446 [ 0 ] = V_1 -> V_191 ;
V_446 [ 1 ] = V_1 -> V_213 ;
if ( F_130 ( V_1 -> V_11 ) )
V_446 [ 1 ] |= V_447 ;
F_255 ( & V_1 -> V_157 , V_448 , V_446 , 2 ) ;
V_446 [ 0 ] = 0 ;
V_446 [ 1 ] = V_449 ;
F_255 ( & V_1 -> V_157 , V_450 , V_446 , 2 ) ;
V_75 |= V_77 ;
if ( ! F_256 ( V_1 , & V_75 ,
V_325 |
V_319 ) ) {
F_79 ( L_64 ) ;
return;
}
V_443 = 0xff ;
V_444 = 0 ;
V_445 = 0 ;
for (; ; ) {
T_3 V_365 [ V_366 ] ;
F_262 ( V_1 -> V_11 ) ;
if ( ! F_227 ( V_1 , V_365 ) ) {
F_79 ( L_65 ) ;
break;
}
if ( F_263 ( V_365 , V_1 -> V_213 ) ) {
F_36 ( L_66 ) ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_213 ; V_49 ++ )
if ( ( V_1 -> V_381 [ V_49 ] & V_409 ) == 0 )
break;
if ( V_49 == V_1 -> V_213 ) {
++ V_445 ;
if ( V_445 == 5 ) {
F_79 ( L_67 ) ;
break;
}
F_256 ( V_1 , & V_75 ,
V_325 |
V_319 ) ;
V_444 = 0 ;
continue;
}
if ( ( V_1 -> V_381 [ 0 ] & V_371 ) == V_443 ) {
++ V_444 ;
if ( V_444 == 5 ) {
F_79 ( L_68 ) ;
break;
}
} else
V_444 = 0 ;
V_443 = V_1 -> V_381 [ 0 ] & V_371 ;
if ( ! F_257 ( V_1 , & V_75 , V_365 ) ) {
F_79 ( L_69 ) ;
break;
}
}
V_1 -> V_75 = V_75 ;
}
void
F_197 ( struct V_1 * V_1 )
{
bool V_451 = false ;
int V_452 , V_453 ;
T_2 V_75 = V_1 -> V_75 ;
T_2 V_454 = V_327 ;
if ( V_1 -> V_191 == V_16 || V_1 -> V_455 )
V_454 = V_329 ;
if ( ! F_254 ( V_1 , & V_75 ,
V_454 |
V_319 ) ) {
F_79 ( L_70 ) ;
return;
}
V_452 = 0 ;
V_453 = 0 ;
V_451 = false ;
for (; ; ) {
T_3 V_365 [ V_366 ] ;
if ( V_453 > 5 ) {
F_79 ( L_71 ) ;
break;
}
F_264 ( V_1 -> V_11 ) ;
if ( ! F_227 ( V_1 , V_365 ) ) {
F_79 ( L_65 ) ;
break;
}
if ( ! F_263 ( V_365 , V_1 -> V_213 ) ) {
F_196 ( V_1 ) ;
F_254 ( V_1 , & V_75 ,
V_454 |
V_319 ) ;
V_453 ++ ;
continue;
}
if ( F_265 ( V_365 , V_1 -> V_213 ) ) {
V_451 = true ;
break;
}
if ( V_452 > 5 ) {
F_196 ( V_1 ) ;
F_254 ( V_1 , & V_75 ,
V_454 |
V_319 ) ;
V_452 = 0 ;
V_453 ++ ;
continue;
}
if ( ! F_257 ( V_1 , & V_75 , V_365 ) ) {
F_79 ( L_69 ) ;
break;
}
++ V_452 ;
}
F_258 ( V_1 ) ;
V_1 -> V_75 = V_75 ;
if ( V_451 )
F_36 ( L_72 ) ;
}
void F_198 ( struct V_1 * V_1 )
{
F_254 ( V_1 , & V_1 -> V_75 ,
V_323 ) ;
}
static void
F_179 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_211 * V_211 =
F_127 ( V_3 -> V_4 . V_4 . V_242 ) ;
T_2 V_75 = V_1 -> V_75 ;
if ( F_47 ( F_13 ( V_7 ) ) )
return;
if ( F_47 ( ( F_25 ( V_1 -> V_76 ) & V_77 ) == 0 ) )
return;
F_36 ( L_44 ) ;
if ( F_131 ( V_7 ) && ( F_83 ( V_7 ) || V_21 != V_22 ) ) {
V_75 &= ~ V_331 ;
F_42 ( V_1 -> V_76 , V_75 | V_456 ) ;
} else {
if ( F_38 ( V_7 ) )
V_75 &= ~ V_334 ;
else
V_75 &= ~ V_335 ;
F_42 ( V_1 -> V_76 , V_75 | V_457 ) ;
}
F_43 ( V_1 -> V_76 ) ;
if ( F_266 ( V_7 ) &&
F_25 ( V_1 -> V_76 ) & V_83 ) {
struct V_288 * V_242 = V_3 -> V_4 . V_4 . V_242 ;
V_75 &= ~ V_83 ;
F_42 ( V_1 -> V_76 , V_75 ) ;
if ( F_47 ( V_242 == NULL ) ) {
F_43 ( V_1 -> V_76 ) ;
F_70 ( 50 ) ;
} else
F_267 ( V_7 , V_211 -> V_72 ) ;
}
V_75 &= ~ V_249 ;
F_42 ( V_1 -> V_76 , V_75 & ~ V_77 ) ;
F_43 ( V_1 -> V_76 ) ;
F_70 ( V_1 -> V_458 ) ;
}
static bool
F_268 ( struct V_1 * V_1 )
{
struct V_2 * V_241 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_241 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( F_225 ( & V_1 -> V_157 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_36 ( L_73 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_18 ] == 0 )
return false ;
memset ( V_1 -> V_459 , 0 , sizeof( V_1 -> V_459 ) ) ;
if ( F_1 ( V_1 ) ) {
F_225 ( & V_1 -> V_157 , V_460 ,
V_1 -> V_459 ,
sizeof( V_1 -> V_459 ) ) ;
if ( V_1 -> V_459 [ 0 ] & V_461 ) {
V_54 -> V_462 . V_463 = true ;
F_36 ( L_74 ) ;
}
}
if ( V_1 -> V_11 [ V_18 ] >= 0x12 &&
V_1 -> V_11 [ V_464 ] & V_465 &&
( F_8 ( V_54 ) || F_10 ( V_54 ) -> V_17 >= 8 ) ) {
V_1 -> V_455 = true ;
F_36 ( L_75 ) ;
} else
V_1 -> V_455 = false ;
if ( ! ( V_1 -> V_11 [ V_466 ] &
V_467 ) )
return true ;
if ( V_1 -> V_11 [ V_18 ] == 0x10 )
return true ;
if ( F_225 ( & V_1 -> V_157 , V_468 ,
V_1 -> V_469 ,
V_470 ) < 0 )
return false ;
return true ;
}
static void
F_269 ( struct V_1 * V_1 )
{
T_1 V_436 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_471 ] & V_472 ) )
return;
if ( F_225 ( & V_1 -> V_157 , V_473 , V_436 , 3 ) == 3 )
F_36 ( L_76 ,
V_436 [ 0 ] , V_436 [ 1 ] , V_436 [ 2 ] ) ;
if ( F_225 ( & V_1 -> V_157 , V_474 , V_436 , 3 ) == 3 )
F_36 ( L_77 ,
V_436 [ 0 ] , V_436 [ 1 ] , V_436 [ 2 ] ) ;
}
static bool
F_270 ( struct V_1 * V_1 )
{
T_1 V_436 [ 1 ] ;
if ( ! V_1 -> V_475 )
return false ;
if ( V_1 -> V_11 [ V_18 ] < 0x12 )
return false ;
if ( F_225 ( & V_1 -> V_157 , V_476 , V_436 , 1 ) ) {
if ( V_436 [ 0 ] & V_477 ) {
F_36 ( L_78 ) ;
V_1 -> V_478 = true ;
} else {
F_36 ( L_79 ) ;
V_1 -> V_478 = false ;
}
}
F_271 ( & V_1 -> V_479 , V_1 -> V_478 ) ;
return V_1 -> V_478 ;
}
int F_272 ( struct V_1 * V_1 , T_1 * V_480 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_211 * V_211 =
F_127 ( V_3 -> V_4 . V_4 . V_242 ) ;
T_1 V_436 ;
int V_481 ;
int V_482 = 6 ;
if ( F_273 ( & V_1 -> V_157 , V_483 , & V_436 ) < 0 )
return - V_152 ;
if ( ! ( V_436 & V_484 ) )
return - V_485 ;
if ( F_273 ( & V_1 -> V_157 , V_486 , & V_436 ) < 0 )
return - V_152 ;
if ( F_165 ( & V_1 -> V_157 , V_486 ,
V_436 | V_487 ) < 0 )
return - V_152 ;
if ( F_273 ( & V_1 -> V_157 , V_483 , & V_436 ) < 0 )
return - V_152 ;
V_481 = V_436 & V_488 ;
do {
if ( F_273 ( & V_1 -> V_157 ,
V_483 , & V_436 ) < 0 )
return - V_152 ;
F_267 ( V_7 , V_211 -> V_72 ) ;
} while ( -- V_482 && ( V_436 & V_488 ) == V_481 );
if ( V_482 == 0 ) {
F_36 ( L_80 ) ;
return - V_153 ;
}
if ( F_226 ( & V_1 -> V_157 , V_489 , V_480 , 6 ) < 0 )
return - V_152 ;
if ( F_273 ( & V_1 -> V_157 , V_486 , & V_436 ) < 0 )
return - V_152 ;
if ( F_165 ( & V_1 -> V_157 , V_486 ,
V_436 & ~ V_487 ) < 0 )
return - V_152 ;
return 0 ;
}
static bool
F_274 ( struct V_1 * V_1 , T_1 * V_490 )
{
return F_225 ( & V_1 -> V_157 ,
V_491 ,
V_490 , 1 ) == 1 ;
}
static bool
F_275 ( struct V_1 * V_1 , T_1 * V_490 )
{
int V_141 ;
V_141 = F_225 ( & V_1 -> V_157 ,
V_492 ,
V_490 , 14 ) ;
if ( V_141 != 14 )
return false ;
return true ;
}
static void
F_276 ( struct V_1 * V_1 )
{
F_165 ( & V_1 -> V_157 , V_493 , V_494 ) ;
}
static int
F_277 ( struct V_1 * V_1 )
{
bool V_495 ;
if ( V_1 -> V_478 ) {
T_1 V_496 [ 16 ] = { 0 } ;
int V_141 = 0 ;
int V_497 ;
bool V_498 ;
V_495 = F_275 ( V_1 , V_496 ) ;
V_499:
if ( V_495 == true ) {
if ( V_1 -> V_500 && ! F_265 ( & V_496 [ 10 ] , V_1 -> V_213 ) ) {
F_36 ( L_81 ) ;
F_196 ( V_1 ) ;
F_197 ( V_1 ) ;
F_198 ( V_1 ) ;
}
F_36 ( L_82 , V_496 [ 0 ] , V_496 [ 1 ] , V_496 [ 2 ] ) ;
V_141 = F_278 ( & V_1 -> V_479 , V_496 , & V_498 ) ;
if ( V_498 ) {
for ( V_497 = 0 ; V_497 < 3 ; V_497 ++ ) {
int V_501 ;
V_501 = F_255 ( & V_1 -> V_157 ,
V_492 + 1 ,
& V_496 [ 1 ] , 3 ) ;
if ( V_501 == 3 ) {
break;
}
}
V_495 = F_275 ( V_1 , V_496 ) ;
if ( V_495 == true ) {
F_36 ( L_83 , V_496 [ 0 ] , V_496 [ 1 ] , V_496 [ 2 ] ) ;
goto V_499;
}
} else
V_141 = 0 ;
return V_141 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_36 ( L_84 ) ;
V_1 -> V_478 = false ;
F_271 ( & V_1 -> V_479 , V_1 -> V_478 ) ;
F_279 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_176 ;
}
void
F_280 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_67 * V_67 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_490 ;
T_1 V_365 [ V_366 ] ;
F_47 ( ! F_281 ( & V_7 -> V_502 . V_503 ) ) ;
if ( ! V_67 -> V_340 )
return;
if ( F_47 ( ! V_67 -> V_4 . V_242 ) )
return;
if ( ! F_127 ( V_67 -> V_4 . V_242 ) -> V_504 )
return;
if ( ! F_227 ( V_1 , V_365 ) ) {
return;
}
if ( ! F_268 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
F_274 ( V_1 , & V_490 ) ) {
F_165 ( & V_1 -> V_157 ,
V_491 ,
V_490 ) ;
if ( V_490 & V_505 )
F_276 ( V_1 ) ;
if ( V_490 & ( V_506 | V_507 ) )
F_199 ( L_85 ) ;
}
if ( ! F_265 ( V_365 , V_1 -> V_213 ) ) {
F_36 ( L_86 ,
V_67 -> V_4 . V_177 ) ;
F_196 ( V_1 ) ;
F_197 ( V_1 ) ;
F_198 ( V_1 ) ;
}
}
static enum V_508
F_282 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_268 ( V_1 ) )
return V_509 ;
if ( ! ( V_11 [ V_466 ] & V_467 ) )
return V_510 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
V_1 -> V_469 [ 0 ] & V_511 ) {
T_3 V_512 ;
if ( F_225 ( & V_1 -> V_157 , V_513 ,
& V_512 , 1 ) < 0 )
return V_514 ;
return F_283 ( V_512 ) ? V_510
: V_509 ;
}
if ( F_284 ( & V_1 -> V_157 . V_187 ) )
return V_510 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 ) {
type = V_1 -> V_469 [ 0 ] & V_515 ;
if ( type == V_516 ||
type == V_517 )
return V_514 ;
} else {
type = V_1 -> V_11 [ V_466 ] &
V_518 ;
if ( type == V_519 ||
type == V_520 )
return V_514 ;
}
F_36 ( L_87 ) ;
return V_509 ;
}
static enum V_508
F_285 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_508 V_115 ;
V_115 = F_286 ( V_7 ) ;
if ( V_115 == V_514 )
V_115 = V_510 ;
return V_115 ;
}
static enum V_508
F_287 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_288 ( V_54 , V_3 ) )
return V_509 ;
return F_282 ( V_1 ) ;
}
static int F_289 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_521 ;
if ( F_24 ( V_7 ) ) {
switch ( V_3 -> V_21 ) {
case V_178 :
V_521 = V_522 ;
break;
case V_180 :
V_521 = V_523 ;
break;
case V_182 :
V_521 = V_524 ;
break;
default:
return - V_176 ;
}
} else {
switch ( V_3 -> V_21 ) {
case V_178 :
V_521 = V_525 ;
break;
case V_180 :
V_521 = V_526 ;
break;
case V_182 :
V_521 = V_527 ;
break;
default:
return - V_176 ;
}
}
if ( ( F_25 ( V_528 ) & V_521 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_508
F_290 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_141 ;
if ( F_1 ( V_1 ) ) {
enum V_508 V_115 ;
V_115 = F_286 ( V_7 ) ;
if ( V_115 == V_514 )
V_115 = V_510 ;
return V_115 ;
}
V_141 = F_289 ( V_7 , V_3 ) ;
if ( V_141 == - V_176 )
return V_514 ;
else if ( V_141 == 0 )
return V_509 ;
return F_282 ( V_1 ) ;
}
static struct V_529 *
F_291 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
if ( V_32 -> V_529 ) {
if ( F_292 ( V_32 -> V_529 ) )
return NULL ;
return F_293 ( V_32 -> V_529 ) ;
} else
return F_294 ( & V_32 -> V_4 ,
& V_1 -> V_157 . V_187 ) ;
}
static void
F_295 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
struct V_529 * V_529 ;
V_529 = F_291 ( V_1 ) ;
V_32 -> V_530 = V_529 ;
if ( V_1 -> V_531 != V_532 )
V_1 -> V_224 = V_1 -> V_531 == V_533 ;
else
V_1 -> V_224 = F_296 ( V_529 ) ;
}
static void
F_297 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
F_298 ( V_32 -> V_530 ) ;
V_32 -> V_530 = NULL ;
V_1 -> V_224 = false ;
}
static enum V_69
F_299 ( struct V_1 * V_534 )
{
struct V_67 * V_68 = & F_2 ( V_534 ) -> V_4 ;
enum V_69 V_70 ;
V_70 = F_27 ( V_68 ) ;
F_28 ( F_300 ( V_68 -> V_4 . V_7 ) , V_70 ) ;
return V_70 ;
}
static void
F_301 ( struct V_1 * V_534 ,
enum V_69 V_70 )
{
struct V_67 * V_68 = & F_2 ( V_534 ) -> V_4 ;
F_32 ( F_300 ( V_68 -> V_4 . V_7 ) , V_70 ) ;
}
static enum V_508
F_302 ( struct V_8 * V_9 , bool V_535 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_508 V_115 ;
enum V_69 V_70 ;
bool V_141 ;
F_36 ( L_88 ,
V_9 -> V_4 . V_536 , V_9 -> V_177 ) ;
F_297 ( V_1 ) ;
if ( V_1 -> V_478 ) {
if ( V_67 -> type != V_5 )
V_67 -> type = V_537 ;
return V_509 ;
}
V_70 = F_299 ( V_1 ) ;
if ( F_1 ( V_1 ) )
V_115 = F_285 ( V_1 ) ;
else if ( F_64 ( V_7 ) )
V_115 = F_287 ( V_1 ) ;
else
V_115 = F_290 ( V_1 ) ;
if ( V_115 != V_510 )
goto V_147;
F_269 ( V_1 ) ;
V_141 = F_270 ( V_1 ) ;
if ( V_141 ) {
if ( V_67 -> type != V_5 )
V_67 -> type = V_537 ;
V_115 = V_509 ;
goto V_147;
}
F_295 ( V_1 ) ;
if ( V_67 -> type != V_5 )
V_67 -> type = V_537 ;
V_115 = V_510 ;
V_147:
F_301 ( V_1 , V_70 ) ;
return V_115 ;
}
static void
F_303 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_67 * V_67 = & F_2 ( V_1 ) -> V_4 ;
enum V_69 V_70 ;
F_36 ( L_88 ,
V_9 -> V_4 . V_536 , V_9 -> V_177 ) ;
F_297 ( V_1 ) ;
if ( V_9 -> V_115 != V_510 )
return;
V_70 = F_299 ( V_1 ) ;
F_295 ( V_1 ) ;
F_301 ( V_1 , V_70 ) ;
if ( V_67 -> type != V_5 )
V_67 -> type = V_537 ;
}
static int F_304 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_529 * V_529 ;
V_529 = V_32 -> V_530 ;
if ( V_529 ) {
int V_141 = F_305 ( V_9 , V_529 ) ;
if ( V_141 )
return V_141 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_32 -> V_34 . V_33 ) {
struct V_30 * V_31 ;
V_31 = F_306 ( V_9 -> V_7 ,
V_32 -> V_34 . V_33 ) ;
if ( V_31 ) {
F_307 ( V_9 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_308 ( struct V_8 * V_9 )
{
bool V_224 = false ;
struct V_529 * V_529 ;
V_529 = F_19 ( V_9 ) -> V_530 ;
if ( V_529 )
V_224 = F_296 ( V_529 ) ;
return V_224 ;
}
static int
F_309 ( struct V_8 * V_9 ,
struct V_538 * V_539 ,
T_8 V_312 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_67 * V_67 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_67 -> V_4 ) ;
int V_141 ;
V_141 = F_310 ( & V_9 -> V_4 , V_539 , V_312 ) ;
if ( V_141 )
return V_141 ;
if ( V_539 == V_54 -> V_540 ) {
int V_49 = V_312 ;
bool V_224 ;
if ( V_49 == V_1 -> V_531 )
return 0 ;
V_1 -> V_531 = V_49 ;
if ( V_49 == V_532 )
V_224 = F_308 ( V_9 ) ;
else
V_224 = ( V_49 == V_533 ) ;
if ( V_224 == V_1 -> V_224 )
return 0 ;
V_1 -> V_224 = V_224 ;
goto V_116;
}
if ( V_539 == V_54 -> V_541 ) {
bool V_542 = V_1 -> V_231 ;
T_2 V_543 = V_1 -> V_232 ;
switch ( V_312 ) {
case V_544 :
V_1 -> V_231 = true ;
break;
case V_545 :
V_1 -> V_231 = false ;
V_1 -> V_232 = 0 ;
break;
case V_546 :
V_1 -> V_231 = false ;
V_1 -> V_232 = V_233 ;
break;
default:
return - V_176 ;
}
if ( V_542 == V_1 -> V_231 &&
V_543 == V_1 -> V_232 )
return 0 ;
goto V_116;
}
if ( F_1 ( V_1 ) &&
V_539 == V_9 -> V_7 -> V_502 . V_547 ) {
if ( V_312 == V_548 ) {
F_36 ( L_89 ) ;
return - V_176 ;
}
if ( V_32 -> V_34 . V_225 == V_312 ) {
return 0 ;
}
V_32 -> V_34 . V_225 = V_312 ;
goto V_116;
}
return - V_176 ;
V_116:
if ( V_67 -> V_4 . V_242 )
F_311 ( V_67 -> V_4 . V_242 ) ;
return 0 ;
}
static void
F_312 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_298 ( V_32 -> V_530 ) ;
if ( ! F_313 ( V_32 -> V_529 ) )
F_298 ( V_32 -> V_529 ) ;
if ( V_9 -> V_549 == V_550 )
F_314 ( & V_32 -> V_34 ) ;
F_315 ( V_9 ) ;
F_298 ( V_9 ) ;
}
void F_316 ( struct V_442 * V_68 )
{
struct V_2 * V_3 = F_211 ( V_68 ) ;
struct V_1 * V_1 = & V_3 -> V_534 ;
F_108 ( & V_1 -> V_157 ) ;
F_317 ( V_3 ) ;
F_318 ( V_68 ) ;
if ( F_1 ( V_1 ) ) {
F_319 ( & V_1 -> V_276 ) ;
F_26 ( V_1 ) ;
F_143 ( V_1 ) ;
F_30 ( V_1 ) ;
if ( V_1 -> V_103 . V_551 ) {
F_320 ( & V_1 -> V_103 ) ;
V_1 -> V_103 . V_551 = NULL ;
}
}
F_298 ( V_3 ) ;
}
static void F_321 ( struct V_67 * V_67 )
{
struct V_1 * V_1 = F_5 ( & V_67 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_319 ( & V_1 -> V_276 ) ;
F_26 ( V_1 ) ;
F_143 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_322 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
F_46 ( & V_54 -> V_71 ) ;
if ( ! F_72 ( V_1 ) )
return;
F_36 ( L_90 ) ;
V_70 = F_27 ( & V_3 -> V_4 ) ;
F_28 ( V_54 , V_70 ) ;
F_146 ( V_1 ) ;
}
static void F_323 ( struct V_442 * V_68 )
{
struct V_1 * V_1 ;
if ( F_324 ( V_68 ) -> type != V_5 )
return;
V_1 = F_5 ( V_68 ) ;
F_26 ( V_1 ) ;
if ( F_24 ( V_68 -> V_7 ) )
F_61 ( V_1 ) ;
F_322 ( V_1 ) ;
F_30 ( V_1 ) ;
}
void
F_325 ( struct V_67 * V_67 )
{
return;
}
bool
F_326 ( struct V_2 * V_3 , bool V_552 )
{
struct V_1 * V_1 = & V_3 -> V_534 ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
bool V_141 = true ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_537 ;
if ( V_552 && V_3 -> V_4 . type == V_5 ) {
F_36 ( L_91 ,
F_35 ( V_3 -> V_21 ) ) ;
return false ;
}
F_36 ( L_92 ,
F_35 ( V_3 -> V_21 ) ,
V_552 ? L_93 : L_94 ) ;
V_70 = F_27 ( V_67 ) ;
F_28 ( V_54 , V_70 ) ;
if ( V_552 ) {
if ( F_64 ( V_7 ) ) {
if ( ! F_288 ( V_54 , V_3 ) )
goto V_553;
} else {
if ( F_289 ( V_7 , V_3 ) != 1 )
goto V_553;
}
if ( ! F_268 ( V_1 ) ) {
goto V_553;
}
F_269 ( V_1 ) ;
if ( ! F_270 ( V_1 ) )
goto V_553;
} else {
if ( V_1 -> V_478 ) {
if ( F_277 ( V_1 ) == - V_176 )
goto V_553;
}
if ( ! V_1 -> V_478 ) {
F_327 ( & V_7 -> V_502 . V_503 , NULL ) ;
F_280 ( V_1 ) ;
F_328 ( & V_7 -> V_502 . V_503 ) ;
}
}
V_141 = false ;
goto V_554;
V_553:
if ( V_1 -> V_478 ) {
F_36 ( L_95 , V_1 -> V_478 , V_1 -> V_479 . V_555 ) ;
V_1 -> V_478 = false ;
F_271 ( & V_1 -> V_479 , V_1 -> V_478 ) ;
}
V_554:
F_32 ( V_54 , V_70 ) ;
return V_141 ;
}
int
F_329 ( struct V_288 * V_242 )
{
struct V_6 * V_7 = V_242 -> V_7 ;
struct V_67 * V_67 ;
struct V_1 * V_1 ;
F_330 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_67 -> V_4 ) ;
if ( V_67 -> type == V_537 ||
V_67 -> type == V_5 )
return V_1 -> V_76 ;
}
return - 1 ;
}
bool F_331 ( struct V_6 * V_7 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_556 * V_557 ;
int V_49 ;
static const short V_558 [] = {
[ V_178 ] = V_559 ,
[ V_180 ] = V_560 ,
[ V_182 ] = V_561 ,
} ;
if ( V_21 == V_22 )
return true ;
if ( ! V_54 -> V_228 . V_562 )
return false ;
for ( V_49 = 0 ; V_49 < V_54 -> V_228 . V_562 ; V_49 ++ ) {
V_557 = V_54 -> V_228 . V_563 + V_49 ;
if ( V_557 -> V_564 . V_565 == V_558 [ V_21 ] &&
( V_557 -> V_564 . V_566 & V_567 ) ==
( V_568 & V_567 ) )
return true ;
}
return false ;
}
void
F_332 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_333 ( V_9 ) ;
F_334 ( V_9 ) ;
V_1 -> V_231 = true ;
if ( F_1 ( V_1 ) ) {
F_335 ( V_9 -> V_7 ) ;
F_336 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_502 . V_547 ,
V_569 ) ;
V_32 -> V_34 . V_225 = V_569 ;
}
}
static void F_337 ( struct V_1 * V_1 )
{
V_1 -> V_264 = V_279 ;
V_1 -> V_267 = V_279 ;
V_1 -> V_269 = V_279 ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_570 V_571 , V_228 , V_572 ,
* V_573 = & V_1 -> V_574 ;
T_5 V_575 , V_576 , V_104 , V_273 ;
int V_105 , V_339 , V_577 , V_106 ;
F_46 ( & V_54 -> V_71 ) ;
if ( V_573 -> V_578 != 0 )
return;
if ( F_64 ( V_7 ) ) {
V_105 = V_97 ;
V_339 = V_579 ;
V_577 = V_580 ;
V_106 = V_581 ;
} else {
enum V_72 V_72 = F_45 ( V_1 ) ;
V_105 = F_56 ( V_72 ) ;
V_339 = F_59 ( V_72 ) ;
V_577 = F_338 ( V_72 ) ;
V_106 = F_69 ( V_72 ) ;
}
V_273 = F_140 ( V_1 ) ;
F_42 ( V_105 , V_273 ) ;
V_575 = F_25 ( V_339 ) ;
V_576 = F_25 ( V_577 ) ;
V_104 = F_25 ( V_106 ) ;
V_571 . V_582 = ( V_575 & V_583 ) >>
V_584 ;
V_571 . V_585 = ( V_575 & V_586 ) >>
V_587 ;
V_571 . V_588 = ( V_576 & V_589 ) >>
V_590 ;
V_571 . V_591 = ( V_576 & V_592 ) >>
V_593 ;
V_571 . V_578 = ( ( V_104 & V_594 ) >>
V_595 ) * 1000 ;
F_36 ( L_96 ,
V_571 . V_582 , V_571 . V_585 , V_571 . V_588 , V_571 . V_591 , V_571 . V_578 ) ;
V_228 = V_54 -> V_228 . V_596 ;
V_572 . V_582 = 210 * 10 ;
V_572 . V_585 = 50 * 10 ;
V_572 . V_588 = 50 * 10 ;
V_572 . V_591 = 500 * 10 ;
V_572 . V_578 = ( 510 + 100 ) * 10 ;
F_36 ( L_97 ,
V_228 . V_582 , V_228 . V_585 , V_228 . V_588 , V_228 . V_591 , V_228 . V_578 ) ;
#define F_339 ( T_9 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_339 ( V_582 ) ;
F_339 ( V_585 ) ;
F_339 ( V_588 ) ;
F_339 ( V_591 ) ;
F_339 ( V_578 ) ;
#undef F_339
#define F_340 ( T_9 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_277 = F_340 ( V_582 ) ;
V_1 -> V_268 = F_340 ( V_585 ) ;
V_1 -> V_270 = F_340 ( V_588 ) ;
V_1 -> V_458 = F_340 ( V_591 ) ;
V_1 -> V_111 = F_340 ( V_578 ) ;
#undef F_340
F_36 ( L_98 ,
V_1 -> V_277 , V_1 -> V_458 ,
V_1 -> V_111 ) ;
F_36 ( L_99 ,
V_1 -> V_268 , V_1 -> V_270 ) ;
}
static void
F_52 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_575 , V_576 , V_104 , V_95 = 0 ;
int div = F_64 ( V_7 ) ? F_85 ( V_7 ) : F_23 ( V_7 ) ;
int V_339 , V_577 , V_106 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
const struct V_570 * V_597 = & V_1 -> V_574 ;
F_46 ( & V_54 -> V_71 ) ;
if ( F_64 ( V_7 ) ) {
V_339 = V_579 ;
V_577 = V_580 ;
V_106 = V_581 ;
} else {
enum V_72 V_72 = F_45 ( V_1 ) ;
V_339 = F_59 ( V_72 ) ;
V_577 = F_338 ( V_72 ) ;
V_106 = F_69 ( V_72 ) ;
}
V_575 = ( V_597 -> V_582 << V_584 ) |
( 1 << V_587 ) ;
V_576 = ( 1 << V_590 ) |
( V_597 -> V_591 << V_593 ) ;
V_104 = ( ( 100 * div ) / 2 - 1 ) << V_598 ;
V_104 |= ( F_84 ( V_597 -> V_578 , 1000 )
<< V_595 ) ;
if ( F_24 ( V_7 ) ) {
V_95 = F_60 ( V_21 ) ;
} else if ( F_266 ( V_7 ) || F_131 ( V_7 ) ) {
if ( V_21 == V_22 )
V_95 = V_599 ;
else
V_95 = V_600 ;
}
V_575 |= V_95 ;
F_42 ( V_339 , V_575 ) ;
F_42 ( V_577 , V_576 ) ;
F_42 ( V_106 , V_104 ) ;
F_36 ( L_100 ,
F_25 ( V_339 ) ,
F_25 ( V_577 ) ,
F_25 ( V_106 ) ) ;
}
void F_341 ( struct V_6 * V_7 , int V_601 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
struct V_1 * V_1 = NULL ;
struct V_189 * V_244 = NULL ;
struct V_211 * V_211 = NULL ;
struct V_32 * V_32 = V_54 -> V_602 . V_9 ;
T_5 V_512 , V_312 ;
enum V_603 V_118 = V_604 ;
if ( V_601 <= 0 ) {
F_36 ( L_101 ) ;
return;
}
if ( V_32 == NULL ) {
F_36 ( L_102 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 < 8 && F_342 ( V_7 ) ) {
F_36 ( L_103 ) ;
return;
}
V_68 = F_6 ( & V_32 -> V_4 ) ;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_211 = V_68 -> V_212 ;
if ( ! V_211 ) {
F_36 ( L_104 ) ;
return;
}
V_244 = & V_211 -> V_244 ;
if ( V_1 -> V_238 . type < V_239 ) {
F_36 ( L_105 ) ;
return;
}
if ( V_32 -> V_34 . V_237 -> V_605 == V_601 )
V_118 = V_606 ;
if ( V_118 == V_1 -> V_238 . V_607 ) {
F_36 (
L_106 ) ;
return;
}
if ( ! V_211 -> V_504 ) {
F_36 ( L_107 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 > 6 && F_10 ( V_7 ) -> V_17 < 8 ) {
V_512 = F_343 ( V_211 -> V_244 . V_608 ) ;
V_312 = F_25 ( V_512 ) ;
if ( V_118 > V_604 ) {
V_312 |= V_609 ;
F_344 ( V_211 ) ;
} else {
V_312 &= ~ V_609 ;
}
F_42 ( V_512 , V_312 ) ;
}
F_29 ( & V_1 -> V_238 . V_610 ) ;
V_1 -> V_238 . V_607 = V_118 ;
F_31 ( & V_1 -> V_238 . V_610 ) ;
F_36 ( L_108 , V_601 ) ;
}
static struct V_30 *
F_345 ( struct V_2 * V_3 ,
struct V_32 * V_32 ,
struct V_30 * V_33 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_534 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_237 = NULL ;
if ( F_10 ( V_7 ) -> V_17 <= 6 ) {
F_36 ( L_109 ) ;
return NULL ;
}
if ( V_54 -> V_228 . V_611 != V_239 ) {
F_36 ( L_110 ) ;
return NULL ;
}
V_237 = F_346
( V_7 , V_33 , V_9 ) ;
if ( ! V_237 ) {
F_36 ( L_111 ) ;
return NULL ;
}
V_54 -> V_602 . V_9 = V_32 ;
F_347 ( & V_1 -> V_238 . V_610 ) ;
V_1 -> V_238 . type = V_54 -> V_228 . V_611 ;
V_1 -> V_238 . V_607 = V_604 ;
F_36 ( L_112 ) ;
return V_237 ;
}
static bool F_348 ( struct V_1 * V_1 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_67 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_33 = NULL ;
struct V_30 * V_237 = NULL ;
bool V_612 ;
struct V_30 * V_613 ;
struct V_529 * V_529 ;
enum V_72 V_72 = V_90 ;
V_1 -> V_238 . type = V_614 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_26 ( V_1 ) ;
F_322 ( V_1 ) ;
F_30 ( V_1 ) ;
V_612 = F_268 ( V_1 ) ;
if ( V_612 ) {
if ( V_1 -> V_11 [ V_18 ] >= 0x11 )
V_54 -> V_615 =
V_1 -> V_11 [ V_616 ] &
V_617 ;
} else {
F_349 ( L_113 ) ;
return false ;
}
F_26 ( V_1 ) ;
F_52 ( V_7 , V_1 ) ;
F_30 ( V_1 ) ;
F_29 ( & V_7 -> V_502 . V_610 ) ;
V_529 = F_294 ( V_9 , & V_1 -> V_157 . V_187 ) ;
if ( V_529 ) {
if ( F_350 ( V_9 , V_529 ) ) {
F_351 ( V_9 ,
V_529 ) ;
F_352 ( V_9 , V_529 ) ;
} else {
F_298 ( V_529 ) ;
V_529 = F_353 ( - V_176 ) ;
}
} else {
V_529 = F_353 ( - V_618 ) ;
}
V_32 -> V_529 = V_529 ;
F_48 (scan, &connector->probed_modes, head) {
if ( ( V_613 -> type & V_619 ) ) {
V_33 = F_306 ( V_7 , V_613 ) ;
V_237 = F_345 (
V_3 ,
V_32 , V_33 ) ;
break;
}
}
if ( ! V_33 && V_54 -> V_228 . V_620 ) {
V_33 = F_306 ( V_7 ,
V_54 -> V_228 . V_620 ) ;
if ( V_33 )
V_33 -> type |= V_619 ;
}
F_31 ( & V_7 -> V_502 . V_610 ) ;
if ( F_24 ( V_7 ) ) {
V_1 -> V_103 . V_551 = F_66 ;
F_354 ( & V_1 -> V_103 ) ;
if ( F_38 ( V_7 ) )
V_72 = F_169 ( V_1 -> V_75 ) ;
else
V_72 = F_170 ( V_1 -> V_75 ) ;
if ( V_72 != V_89 && V_72 != V_82 )
V_72 = V_1 -> V_73 ;
if ( V_72 != V_89 && V_72 != V_82 )
V_72 = V_89 ;
F_36 ( L_114 ,
F_34 ( V_72 ) ) ;
}
F_355 ( & V_32 -> V_34 , V_33 , V_237 ) ;
V_32 -> V_34 . V_621 = F_160 ;
F_356 ( V_9 , V_72 ) ;
return true ;
}
bool
F_357 ( struct V_2 * V_3 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_534 ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_67 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
int type ;
V_1 -> V_73 = V_90 ;
if ( F_10 ( V_7 ) -> V_17 >= 9 )
V_1 -> V_149 = F_90 ;
else if ( F_24 ( V_7 ) )
V_1 -> V_149 = F_89 ;
else if ( F_8 ( V_7 ) || F_92 ( V_7 ) )
V_1 -> V_149 = F_86 ;
else if ( F_64 ( V_7 ) )
V_1 -> V_149 = F_81 ;
else
V_1 -> V_149 = F_80 ;
if ( F_10 ( V_7 ) -> V_17 >= 9 )
V_1 -> V_151 = F_93 ;
else
V_1 -> V_151 = F_91 ;
V_1 -> V_75 = F_25 ( V_1 -> V_76 ) ;
V_1 -> V_13 = V_32 ;
if ( F_331 ( V_7 , V_21 ) )
type = V_550 ;
else
type = V_622 ;
if ( type == V_550 )
V_67 -> type = V_5 ;
if ( F_47 ( F_24 ( V_7 ) && F_1 ( V_1 ) &&
V_21 != V_178 && V_21 != V_180 ) )
return false ;
F_36 ( L_115 ,
type == V_550 ? L_116 : L_117 ,
F_35 ( V_21 ) ) ;
F_358 ( V_7 , V_9 , & V_623 , type ) ;
F_359 ( V_9 , & V_624 ) ;
V_9 -> V_625 = true ;
V_9 -> V_626 = 0 ;
F_360 ( & V_1 -> V_276 ,
F_144 ) ;
F_361 ( V_32 , V_67 ) ;
F_362 ( V_9 ) ;
if ( F_13 ( V_7 ) )
V_32 -> V_627 = V_628 ;
else
V_32 -> V_627 = V_629 ;
V_32 -> V_630 = F_109 ;
switch ( V_21 ) {
case V_22 :
V_67 -> V_631 = V_632 ;
break;
case V_178 :
V_67 -> V_631 = V_633 ;
break;
case V_180 :
V_67 -> V_631 = V_634 ;
break;
case V_182 :
V_67 -> V_631 = V_635 ;
break;
default:
F_105 () ;
}
if ( F_1 ( V_1 ) ) {
F_26 ( V_1 ) ;
F_337 ( V_1 ) ;
if ( F_24 ( V_7 ) )
F_61 ( V_1 ) ;
else
F_51 ( V_7 , V_1 ) ;
F_30 ( V_1 ) ;
}
F_104 ( V_1 , V_32 ) ;
if ( F_8 ( V_7 ) || F_92 ( V_7 ) ) {
if ( V_21 == V_178 || V_21 == V_180 || V_21 == V_182 ) {
F_363 ( V_3 ,
V_32 -> V_4 . V_4 . V_536 ) ;
}
}
if ( ! F_348 ( V_1 , V_32 ) ) {
F_108 ( & V_1 -> V_157 ) ;
if ( F_1 ( V_1 ) ) {
F_319 ( & V_1 -> V_276 ) ;
F_26 ( V_1 ) ;
F_143 ( V_1 ) ;
F_30 ( V_1 ) ;
}
F_364 ( V_9 ) ;
F_315 ( V_9 ) ;
return false ;
}
F_332 ( V_1 , V_9 ) ;
if ( F_117 ( V_7 ) && ! F_365 ( V_7 ) ) {
T_5 V_318 = F_25 ( V_636 ) ;
F_42 ( V_636 , ( V_318 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_366 ( struct V_6 * V_7 , int V_76 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 ;
struct V_67 * V_67 ;
struct V_442 * V_68 ;
struct V_32 * V_32 ;
V_3 = F_367 ( sizeof( * V_3 ) , V_637 ) ;
if ( ! V_3 )
return;
V_32 = F_367 ( sizeof( * V_32 ) , V_637 ) ;
if ( ! V_32 ) {
F_298 ( V_3 ) ;
return;
}
V_67 = & V_3 -> V_4 ;
V_68 = & V_67 -> V_4 ;
F_368 ( V_7 , & V_67 -> V_4 , & V_638 ,
V_639 ) ;
V_67 -> V_640 = F_119 ;
V_67 -> V_641 = F_177 ;
V_67 -> V_627 = F_166 ;
V_67 -> V_642 = F_173 ;
V_67 -> V_643 = F_321 ;
if ( F_38 ( V_7 ) ) {
V_67 -> V_644 = F_222 ;
V_67 -> V_645 = F_217 ;
V_67 -> V_286 = F_202 ;
V_67 -> V_646 = F_182 ;
} else if ( F_24 ( V_7 ) ) {
V_67 -> V_644 = F_210 ;
V_67 -> V_645 = F_205 ;
V_67 -> V_286 = F_202 ;
V_67 -> V_646 = F_181 ;
} else {
V_67 -> V_645 = F_203 ;
V_67 -> V_286 = F_201 ;
if ( F_10 ( V_7 ) -> V_17 >= 5 )
V_67 -> V_646 = F_180 ;
}
V_3 -> V_21 = V_21 ;
V_3 -> V_534 . V_76 = V_76 ;
V_67 -> type = V_537 ;
if ( F_38 ( V_7 ) ) {
if ( V_21 == V_182 )
V_67 -> V_647 = 1 << 2 ;
else
V_67 -> V_647 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_67 -> V_647 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_67 -> V_648 = 0 ;
V_67 -> V_649 = F_325 ;
V_3 -> V_650 = F_326 ;
V_54 -> V_651 [ V_21 ] = V_3 ;
if ( ! F_357 ( V_3 , V_32 ) ) {
F_318 ( V_68 ) ;
F_298 ( V_3 ) ;
F_298 ( V_32 ) ;
}
}
void F_369 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_652 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_651 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_537 ) {
if ( ! V_3 -> V_534 . V_475 )
continue;
if ( V_3 -> V_534 . V_478 )
F_370 ( & V_3 -> V_534 . V_479 ) ;
}
}
}
void F_371 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_652 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_651 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_537 ) {
int V_141 ;
if ( ! V_3 -> V_534 . V_475 )
continue;
V_141 = F_372 ( & V_3 -> V_534 . V_479 ) ;
if ( V_141 != 0 ) {
F_277 ( & V_3 -> V_534 ) ;
}
}
}
}
