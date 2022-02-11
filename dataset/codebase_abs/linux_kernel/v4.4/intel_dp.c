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
static unsigned int F_7 ( int V_10 )
{
return ~ ( ( 1 << V_10 ) - 1 ) & 0xf ;
}
static int
F_8 ( struct V_1 * V_1 )
{
int V_11 = V_1 -> V_12 [ V_13 ] ;
switch ( V_11 ) {
case V_14 :
case V_15 :
case V_16 :
break;
default:
F_9 ( 1 , L_1 ,
V_11 ) ;
V_11 = V_14 ;
break;
}
return V_11 ;
}
static T_1 F_10 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_17 , V_18 ;
V_17 = 4 ;
if ( F_11 ( V_7 ) && V_3 -> V_19 == V_20 &&
( V_3 -> V_21 & V_22 ) == 0 )
V_17 = 2 ;
V_18 = F_12 ( V_1 -> V_12 ) ;
return F_13 ( V_17 , V_18 ) ;
}
static int
F_14 ( int V_23 , int V_24 )
{
return ( V_23 * V_24 + 9 ) / 10 ;
}
static int
F_15 ( int V_25 , int V_26 )
{
return ( V_25 * V_26 * 8 ) / 10 ;
}
static enum V_27
F_16 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_30 * V_30 = F_17 ( V_9 ) ;
struct V_28 * V_31 = V_30 -> V_32 . V_31 ;
int V_33 = V_29 -> clock ;
int V_34 , V_35 , V_26 , V_25 ;
if ( F_1 ( V_1 ) && V_31 ) {
if ( V_29 -> V_36 > V_31 -> V_36 )
return V_37 ;
if ( V_29 -> V_38 > V_31 -> V_38 )
return V_37 ;
V_33 = V_31 -> clock ;
}
V_25 = F_18 ( V_1 ) ;
V_26 = F_10 ( V_1 ) ;
V_34 = F_15 ( V_25 , V_26 ) ;
V_35 = F_14 ( V_33 , 18 ) ;
if ( V_35 > V_34 )
return V_39 ;
if ( V_29 -> clock < 10000 )
return V_40 ;
if ( V_29 -> V_41 & V_42 )
return V_43 ;
return V_44 ;
}
T_2 F_19 ( const T_3 * V_45 , int V_46 )
{
int V_47 ;
T_2 V_48 = 0 ;
if ( V_46 > 4 )
V_46 = 4 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
V_48 |= ( ( T_2 ) V_45 [ V_47 ] ) << ( ( 3 - V_47 ) * 8 ) ;
return V_48 ;
}
static void F_20 ( T_2 V_45 , T_3 * V_49 , int V_50 )
{
int V_47 ;
if ( V_50 > 4 )
V_50 = 4 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
V_49 [ V_47 ] = V_45 >> ( ( 3 - V_47 ) * 8 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
V_57 = F_22 ( V_52 ) ;
F_23 ( V_54 , V_57 ) ;
F_24 ( & V_54 -> V_58 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
F_26 ( & V_54 -> V_58 ) ;
V_57 = F_22 ( V_52 ) ;
F_27 ( V_54 , V_57 ) ;
}
static void
F_28 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_59 V_59 = V_1 -> V_60 ;
bool V_61 , V_62 = false ;
enum V_63 V_64 = F_29 ( V_59 ) ;
enum V_65 V_66 = F_30 ( V_59 ) ;
T_2 V_67 ;
if ( F_9 ( F_31 ( V_1 -> V_68 ) & V_69 ,
L_2 ,
F_32 ( V_59 ) , F_33 ( V_3 -> V_19 ) ) )
return;
F_34 ( L_3 ,
F_32 ( V_59 ) , F_33 ( V_3 -> V_19 ) ) ;
V_67 = F_31 ( V_1 -> V_68 ) & V_70 ;
V_67 |= V_71 | V_72 ;
V_67 |= F_35 ( 1 ) ;
V_67 |= V_73 ;
if ( F_36 ( V_7 ) )
V_67 |= F_37 ( V_59 ) ;
else if ( V_59 == V_74 )
V_67 |= V_75 ;
V_61 = F_31 ( F_38 ( V_59 ) ) & V_76 ;
if ( ! V_61 ) {
V_62 = F_36 ( V_7 ) &&
! F_39 ( V_54 , V_64 , V_66 , true ) ;
F_40 ( V_7 , V_59 , F_36 ( V_7 ) ?
& V_77 [ 0 ] . V_78 : & V_79 [ 0 ] . V_78 ) ;
}
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
F_41 ( V_1 -> V_68 , V_67 | V_69 ) ;
F_42 ( V_1 -> V_68 ) ;
F_41 ( V_1 -> V_68 , V_67 & ~ V_69 ) ;
F_42 ( V_1 -> V_68 ) ;
if ( ! V_61 ) {
F_43 ( V_7 , V_59 ) ;
if ( V_62 )
F_39 ( V_54 , V_64 , V_66 , false ) ;
}
}
static enum V_59
F_44 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_51 * V_52 ;
unsigned int V_80 = ( 1 << V_81 ) | ( 1 << V_74 ) ;
enum V_59 V_59 ;
F_45 ( & V_54 -> V_58 ) ;
F_46 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_60 != V_82 )
return V_1 -> V_60 ;
F_47 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_83 ;
if ( V_52 -> type != V_5 )
continue;
V_83 = F_5 ( & V_52 -> V_4 ) ;
if ( V_83 -> V_60 != V_82 )
V_80 &= ~ ( 1 << V_83 -> V_60 ) ;
}
if ( F_46 ( V_80 == 0 ) )
V_59 = V_81 ;
else
V_59 = F_48 ( V_80 ) - 1 ;
F_49 ( V_7 , V_59 ) ;
V_1 -> V_60 = V_59 ;
F_34 ( L_4 ,
F_32 ( V_1 -> V_60 ) ,
F_33 ( V_3 -> V_19 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
F_28 ( V_1 ) ;
return V_1 -> V_60 ;
}
static bool F_52 ( struct V_53 * V_54 ,
enum V_59 V_59 )
{
return F_31 ( F_53 ( V_59 ) ) & V_84 ;
}
static bool F_54 ( struct V_53 * V_54 ,
enum V_59 V_59 )
{
return F_31 ( F_55 ( V_59 ) ) & V_85 ;
}
static bool F_56 ( struct V_53 * V_54 ,
enum V_59 V_59 )
{
return true ;
}
static enum V_59
F_57 ( struct V_53 * V_54 ,
enum V_19 V_19 ,
T_4 V_86 )
{
enum V_59 V_59 ;
for ( V_59 = V_81 ; V_59 <= V_74 ; V_59 ++ ) {
T_5 V_87 = F_31 ( F_58 ( V_59 ) ) &
V_88 ;
if ( V_87 != F_59 ( V_19 ) )
continue;
if ( ! V_86 ( V_54 , V_59 ) )
continue;
return V_59 ;
}
return V_82 ;
}
static void
F_60 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
F_45 ( & V_54 -> V_58 ) ;
V_1 -> V_60 = F_57 ( V_54 , V_19 ,
F_52 ) ;
if ( V_1 -> V_60 == V_82 )
V_1 -> V_60 = F_57 ( V_54 , V_19 ,
F_54 ) ;
if ( V_1 -> V_60 == V_82 )
V_1 -> V_60 = F_57 ( V_54 , V_19 ,
F_56 ) ;
if ( V_1 -> V_60 == V_82 ) {
F_34 ( L_5 ,
F_33 ( V_19 ) ) ;
return;
}
F_34 ( L_6 ,
F_33 ( V_19 ) , F_32 ( V_1 -> V_60 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
void F_61 ( struct V_53 * V_54 )
{
struct V_6 * V_7 = V_54 -> V_7 ;
struct V_51 * V_52 ;
if ( F_46 ( ! F_62 ( V_7 ) ) )
return;
F_47 (encoder, &dev->mode_config.encoder_list, base.head) {
struct V_1 * V_1 ;
if ( V_52 -> type != V_5 )
continue;
V_1 = F_5 ( & V_52 -> V_4 ) ;
V_1 -> V_60 = V_82 ;
}
}
static T_5 F_63 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_64 ( V_7 ) )
return F_65 ( 0 ) ;
else if ( F_66 ( V_7 ) )
return V_89 ;
else
return F_55 ( F_44 ( V_1 ) ) ;
}
static T_5 F_67 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_64 ( V_7 ) )
return F_68 ( 0 ) ;
else if ( F_66 ( V_7 ) )
return V_90 ;
else
return F_53 ( F_44 ( V_1 ) ) ;
}
static int F_69 ( struct V_91 * V_92 , unsigned long V_93 ,
void * V_94 )
{
struct V_1 * V_1 = F_70 ( V_92 , F_71 ( * V_1 ) ,
V_95 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) || V_93 != V_96 )
return 0 ;
F_21 ( V_1 ) ;
if ( F_62 ( V_7 ) ) {
enum V_59 V_59 = F_44 ( V_1 ) ;
T_5 V_97 , V_98 ;
T_5 V_99 ;
V_97 = F_55 ( V_59 ) ;
V_98 = F_72 ( V_59 ) ;
V_99 = F_31 ( V_98 ) ;
V_99 &= V_100 ;
F_41 ( V_98 , V_99 | 0x1F ) ;
F_41 ( V_97 , V_101 | V_102 ) ;
F_73 ( V_1 -> V_103 ) ;
}
F_25 ( V_1 ) ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_45 ( & V_54 -> V_58 ) ;
if ( F_62 ( V_7 ) &&
V_1 -> V_60 == V_82 )
return false ;
return ( F_31 ( F_67 ( V_1 ) ) & V_84 ) != 0 ;
}
static bool F_75 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_45 ( & V_54 -> V_58 ) ;
if ( F_62 ( V_7 ) &&
V_1 -> V_60 == V_82 )
return false ;
return F_31 ( F_63 ( V_1 ) ) & V_85 ;
}
static void
F_76 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_74 ( V_1 ) && ! F_75 ( V_1 ) ) {
F_9 ( 1 , L_7 ) ;
F_34 ( L_8 ,
F_31 ( F_67 ( V_1 ) ) ,
F_31 ( F_63 ( V_1 ) ) ) ;
}
}
static T_2
F_77 ( struct V_1 * V_1 , bool V_104 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_105 = V_1 -> V_106 ;
T_2 V_107 ;
bool V_108 ;
#define F_78 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_104 )
V_108 = F_79 ( V_54 -> V_109 , F_78 ,
F_80 ( 10 ) ) ;
else
V_108 = F_81 ( F_78 , 10 ) == 0 ;
if ( ! V_108 )
F_82 ( L_9 ,
V_104 ) ;
#undef F_78
return V_107 ;
}
static T_2 F_83 ( struct V_1 * V_1 , int V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_110 ? 0 : F_84 ( V_7 ) / 2 ;
}
static T_2 F_85 ( struct V_1 * V_1 , int V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_110 )
return 0 ;
if ( V_3 -> V_19 == V_20 ) {
return F_86 ( V_54 -> V_111 , 2000 ) ;
} else {
return F_86 ( F_87 ( V_7 ) , 2 ) ;
}
}
static T_2 F_88 ( struct V_1 * V_1 , int V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_3 -> V_19 == V_20 ) {
if ( V_110 )
return 0 ;
return F_89 ( V_54 -> V_111 , 2000 ) ;
} else if ( V_54 -> V_112 == V_113 ) {
switch ( V_110 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_110 ? 0 : F_86 ( F_87 ( V_7 ) , 2 ) ;
}
}
static T_2 F_90 ( struct V_1 * V_1 , int V_110 )
{
return V_110 ? 0 : 100 ;
}
static T_2 F_91 ( struct V_1 * V_1 , int V_110 )
{
return V_110 ? 0 : 1 ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
bool V_104 ,
int V_114 ,
T_2 V_115 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_116 , V_117 ;
if ( F_93 ( V_7 ) )
V_116 = 3 ;
else
V_116 = 5 ;
if ( F_94 ( V_7 ) && V_1 -> V_106 == V_118 )
V_117 = V_119 ;
else
V_117 = V_120 ;
return V_121 |
V_122 |
( V_104 ? V_123 : 0 ) |
V_124 |
V_117 |
V_125 |
( V_114 << V_126 ) |
( V_116 << V_127 ) |
( V_115 << V_128 ) ;
}
static T_2 F_95 ( struct V_1 * V_1 ,
bool V_104 ,
int V_114 ,
T_2 V_94 )
{
return V_121 |
V_122 |
( V_104 ? V_123 : 0 ) |
V_124 |
V_129 |
V_125 |
( V_114 << V_126 ) |
F_96 ( 32 ) ;
}
static int
F_97 ( struct V_1 * V_1 ,
const T_3 * V_130 , int V_114 ,
T_3 * V_131 , int V_132 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_105 = V_1 -> V_106 ;
T_2 V_133 = V_105 + 4 ;
T_2 V_115 ;
int V_47 , V_134 , V_135 ;
T_2 V_107 ;
int V_136 , clock = 0 ;
bool V_104 = F_98 ( V_7 ) ;
bool V_137 ;
F_21 ( V_1 ) ;
V_137 = F_99 ( V_1 ) ;
F_100 ( & V_54 -> V_138 , 0 ) ;
F_76 ( V_1 ) ;
for ( V_136 = 0 ; V_136 < 3 ; V_136 ++ ) {
V_107 = F_101 ( V_105 ) ;
if ( ( V_107 & V_121 ) == 0 )
break;
F_73 ( 1 ) ;
}
if ( V_136 == 3 ) {
static T_5 V_139 = - 1 ;
const T_5 V_107 = F_31 ( V_105 ) ;
if ( V_107 != V_139 ) {
F_9 ( 1 , L_10 ,
V_107 ) ;
V_139 = V_107 ;
}
V_134 = - V_140 ;
goto V_141;
}
if ( F_46 ( V_114 > 20 || V_132 > 20 ) ) {
V_134 = - V_142 ;
goto V_141;
}
while ( ( V_115 = V_1 -> V_143 ( V_1 , clock ++ ) ) ) {
T_5 V_144 = V_1 -> V_145 ( V_1 ,
V_104 ,
V_114 ,
V_115 ) ;
for ( V_136 = 0 ; V_136 < 5 ; V_136 ++ ) {
for ( V_47 = 0 ; V_47 < V_114 ; V_47 += 4 )
F_41 ( V_133 + V_47 ,
F_19 ( V_130 + V_47 ,
V_114 - V_47 ) ) ;
F_41 ( V_105 , V_144 ) ;
V_107 = F_77 ( V_1 , V_104 ) ;
F_41 ( V_105 ,
V_107 |
V_122 |
V_124 |
V_125 ) ;
if ( V_107 & V_124 )
continue;
if ( V_107 & V_125 ) {
F_102 ( 400 , 500 ) ;
continue;
}
if ( V_107 & V_122 )
goto V_108;
}
}
if ( ( V_107 & V_122 ) == 0 ) {
F_82 ( L_11 , V_107 ) ;
V_134 = - V_140 ;
goto V_141;
}
V_108:
if ( V_107 & V_125 ) {
F_82 ( L_12 , V_107 ) ;
V_134 = - V_146 ;
goto V_141;
}
if ( V_107 & V_124 ) {
F_34 ( L_13 , V_107 ) ;
V_134 = - V_147 ;
goto V_141;
}
V_135 = ( ( V_107 & V_148 ) >>
V_126 ) ;
if ( V_135 > V_132 )
V_135 = V_132 ;
for ( V_47 = 0 ; V_47 < V_135 ; V_47 += 4 )
F_20 ( F_31 ( V_133 + V_47 ) ,
V_131 + V_47 , V_135 - V_47 ) ;
V_134 = V_135 ;
V_141:
F_100 ( & V_54 -> V_138 , V_149 ) ;
if ( V_137 )
F_103 ( V_1 , false ) ;
F_25 ( V_1 ) ;
return V_134 ;
}
static T_6
F_104 ( struct V_150 * V_151 , struct V_152 * V_153 )
{
struct V_1 * V_1 = F_70 ( V_151 , struct V_1 , V_151 ) ;
T_3 V_154 [ 20 ] , V_155 [ 20 ] ;
T_7 V_156 , V_157 ;
int V_134 ;
V_154 [ 0 ] = ( V_153 -> V_158 << 4 ) |
( ( V_153 -> V_159 >> 16 ) & 0xf ) ;
V_154 [ 1 ] = ( V_153 -> V_159 >> 8 ) & 0xff ;
V_154 [ 2 ] = V_153 -> V_159 & 0xff ;
V_154 [ 3 ] = V_153 -> V_160 - 1 ;
switch ( V_153 -> V_158 & ~ V_161 ) {
case V_162 :
case V_163 :
case V_164 :
V_156 = V_153 -> V_160 ? V_165 + V_153 -> V_160 : V_166 ;
V_157 = 2 ;
if ( F_46 ( V_156 > 20 ) )
return - V_142 ;
memcpy ( V_154 + V_165 , V_153 -> V_167 , V_153 -> V_160 ) ;
V_134 = F_97 ( V_1 , V_154 , V_156 , V_155 , V_157 ) ;
if ( V_134 > 0 ) {
V_153 -> V_168 = V_155 [ 0 ] >> 4 ;
if ( V_134 > 1 ) {
V_134 = F_105 ( int , V_155 [ 1 ] , 0 , V_153 -> V_160 ) ;
} else {
V_134 = V_153 -> V_160 ;
}
}
break;
case V_169 :
case V_170 :
V_156 = V_153 -> V_160 ? V_165 : V_166 ;
V_157 = V_153 -> V_160 + 1 ;
if ( F_46 ( V_157 > 20 ) )
return - V_142 ;
V_134 = F_97 ( V_1 , V_154 , V_156 , V_155 , V_157 ) ;
if ( V_134 > 0 ) {
V_153 -> V_168 = V_155 [ 0 ] >> 4 ;
V_134 -- ;
memcpy ( V_153 -> V_167 , V_155 + 1 , V_134 ) ;
}
break;
default:
V_134 = - V_171 ;
break;
}
return V_134 ;
}
static void
F_106 ( struct V_1 * V_1 , struct V_30 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
struct V_172 * V_173 = & V_54 -> V_174 . V_175 [ V_19 ] ;
const char * V_176 = NULL ;
T_2 V_177 = V_118 ;
int V_134 ;
if ( F_107 ( V_7 ) && V_19 == V_178 ) {
switch ( V_173 -> V_179 ) {
case V_180 :
V_177 = V_181 ;
break;
case V_182 :
V_177 = V_183 ;
break;
case V_184 :
V_177 = V_185 ;
break;
case V_186 :
default:
V_177 = V_118 ;
}
}
switch ( V_19 ) {
case V_20 :
V_1 -> V_106 = V_118 ;
V_176 = L_14 ;
break;
case V_187 :
V_1 -> V_106 = V_188 ;
V_176 = L_15 ;
break;
case V_189 :
V_1 -> V_106 = V_190 ;
V_176 = L_16 ;
break;
case V_191 :
V_1 -> V_106 = V_192 ;
V_176 = L_17 ;
break;
case V_178 :
V_1 -> V_106 = V_177 ;
V_176 = L_18 ;
break;
default:
F_108 () ;
}
if ( ! F_109 ( V_7 ) && ! F_94 ( V_7 ) && V_19 != V_178 )
V_1 -> V_106 = V_1 -> V_68 + 0x10 ;
V_1 -> V_151 . V_176 = V_176 ;
V_1 -> V_151 . V_7 = V_7 -> V_7 ;
V_1 -> V_151 . V_193 = F_104 ;
F_34 ( L_19 , V_176 ,
V_9 -> V_4 . V_194 -> V_195 . V_176 ) ;
V_134 = F_110 ( & V_1 -> V_151 ) ;
if ( V_134 < 0 ) {
F_82 ( L_20 ,
V_176 , V_134 ) ;
return;
}
V_134 = F_111 ( & V_9 -> V_4 . V_194 -> V_195 ,
& V_1 -> V_151 . V_196 . V_7 . V_195 ,
V_1 -> V_151 . V_196 . V_7 . V_195 . V_176 ) ;
if ( V_134 < 0 ) {
F_82 ( L_21 , V_176 , V_134 ) ;
F_112 ( & V_1 -> V_151 ) ;
}
}
static void
F_113 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = F_4 ( & V_30 -> V_4 ) ;
if ( ! V_30 -> V_197 )
F_114 ( & V_30 -> V_4 . V_194 -> V_195 ,
V_1 -> V_151 . V_196 . V_7 . V_195 . V_176 ) ;
F_115 ( V_30 ) ;
}
static void
F_116 ( struct V_198 * V_199 )
{
T_5 V_200 ;
memset ( & V_199 -> V_201 , 0 ,
sizeof( V_199 -> V_201 ) ) ;
V_199 -> V_202 = V_203 ;
V_199 -> V_201 . V_204 = 0 ;
V_199 -> V_201 . V_205 = 0 ;
V_200 = F_117 ( V_203 ) ;
switch ( V_199 -> V_206 / 2 ) {
case 81000 :
V_200 |= F_118 ( V_207 ,
V_203 ) ;
break;
case 135000 :
V_200 |= F_118 ( V_208 ,
V_203 ) ;
break;
case 270000 :
V_200 |= F_118 ( V_209 ,
V_203 ) ;
break;
case 162000 :
V_200 |= F_118 ( V_210 ,
V_203 ) ;
break;
case 108000 :
V_200 |= F_118 ( V_211 ,
V_203 ) ;
break;
case 216000 :
V_200 |= F_118 ( V_212 ,
V_203 ) ;
break;
}
V_199 -> V_201 . V_200 = V_200 ;
}
void
F_119 ( struct V_198 * V_199 )
{
memset ( & V_199 -> V_201 , 0 ,
sizeof( V_199 -> V_201 ) ) ;
switch ( V_199 -> V_206 / 2 ) {
case 81000 :
V_199 -> V_202 = V_213 ;
break;
case 135000 :
V_199 -> V_202 = V_214 ;
break;
case 270000 :
V_199 -> V_202 = V_215 ;
break;
}
}
static int
F_120 ( struct V_1 * V_1 , const int * * V_216 )
{
if ( V_1 -> V_217 ) {
* V_216 = V_1 -> V_216 ;
return V_1 -> V_217 ;
}
* V_216 = V_218 ;
return ( F_8 ( V_1 ) >> 3 ) + 1 ;
}
static bool F_121 ( struct V_6 * V_7 )
{
if ( F_107 ( V_7 ) && F_122 ( V_7 ) <= V_219 )
return false ;
if ( ( F_109 ( V_7 ) && ! F_123 ( V_7 ) ) || F_94 ( V_7 ) ||
( F_124 ( V_7 ) -> V_220 >= 9 ) )
return true ;
else
return false ;
}
static int
F_125 ( struct V_6 * V_7 , const int * * V_221 )
{
int V_160 ;
if ( F_64 ( V_7 ) ) {
* V_221 = V_222 ;
V_160 = F_126 ( V_222 ) ;
} else if ( F_107 ( V_7 ) ) {
* V_221 = V_223 ;
V_160 = F_126 ( V_223 ) ;
} else {
* V_221 = V_218 ;
V_160 = F_126 ( V_218 ) ;
}
if ( ! F_121 ( V_7 ) )
V_160 -- ;
return V_160 ;
}
static void
F_127 ( struct V_51 * V_52 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
const struct V_224 * V_225 = NULL ;
int V_47 , V_226 = 0 ;
if ( F_128 ( V_7 ) ) {
V_225 = V_227 ;
V_226 = F_126 ( V_227 ) ;
} else if ( F_66 ( V_7 ) ) {
V_225 = V_228 ;
V_226 = F_126 ( V_228 ) ;
} else if ( F_36 ( V_7 ) ) {
V_225 = V_77 ;
V_226 = F_126 ( V_77 ) ;
} else if ( F_62 ( V_7 ) ) {
V_225 = V_79 ;
V_226 = F_126 ( V_79 ) ;
}
if ( V_225 && V_226 ) {
for ( V_47 = 0 ; V_47 < V_226 ; V_47 ++ ) {
if ( V_199 -> V_206 == V_225 [ V_47 ] . clock ) {
V_199 -> V_78 = V_225 [ V_47 ] . V_78 ;
V_199 -> V_229 = true ;
break;
}
}
}
}
static int F_129 ( const int * V_221 , int V_230 ,
const int * V_216 , int V_231 ,
int * V_232 )
{
int V_47 = 0 , V_233 = 0 , V_234 = 0 ;
while ( V_47 < V_230 && V_233 < V_231 ) {
if ( V_221 [ V_47 ] == V_216 [ V_233 ] ) {
if ( F_46 ( V_234 >= V_235 ) )
return V_234 ;
V_232 [ V_234 ] = V_221 [ V_47 ] ;
++ V_234 ;
++ V_47 ;
++ V_233 ;
} else if ( V_221 [ V_47 ] < V_216 [ V_233 ] ) {
++ V_47 ;
} else {
++ V_233 ;
}
}
return V_234 ;
}
static int F_130 ( struct V_1 * V_1 ,
int * V_232 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_221 , * V_216 ;
int V_230 , V_231 ;
V_231 = F_120 ( V_1 , & V_216 ) ;
V_230 = F_125 ( V_7 , & V_221 ) ;
return F_129 ( V_221 , V_230 ,
V_216 , V_231 ,
V_232 ) ;
}
static void F_131 ( char * V_236 , T_7 V_237 ,
const int * V_238 , int V_239 )
{
int V_47 ;
V_236 [ 0 ] = '\0' ;
for ( V_47 = 0 ; V_47 < V_239 ; V_47 ++ ) {
int V_240 = snprintf ( V_236 , V_237 , L_22 , V_47 ? L_23 : L_24 , V_238 [ V_47 ] ) ;
if ( V_240 >= V_237 )
return;
V_236 += V_240 ;
V_237 -= V_240 ;
}
}
static void F_132 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
const int * V_221 , * V_216 ;
int V_230 , V_231 , V_241 ;
int V_232 [ V_235 ] ;
char V_236 [ 128 ] ;
if ( ( V_242 & V_243 ) == 0 )
return;
V_230 = F_125 ( V_7 , & V_221 ) ;
F_131 ( V_236 , sizeof( V_236 ) , V_221 , V_230 ) ;
F_34 ( L_25 , V_236 ) ;
V_231 = F_120 ( V_1 , & V_216 ) ;
F_131 ( V_236 , sizeof( V_236 ) , V_216 , V_231 ) ;
F_34 ( L_26 , V_236 ) ;
V_241 = F_130 ( V_1 , V_232 ) ;
F_131 ( V_236 , sizeof( V_236 ) , V_232 , V_241 ) ;
F_34 ( L_27 , V_236 ) ;
}
static int F_133 ( int V_244 , const int * V_245 )
{
int V_47 = 0 ;
for ( V_47 = 0 ; V_47 < V_235 ; ++ V_47 )
if ( V_244 == V_245 [ V_47 ] )
break;
return V_47 ;
}
int
F_18 ( struct V_1 * V_1 )
{
int V_245 [ V_235 ] = {} ;
int V_237 ;
V_237 = F_130 ( V_1 , V_245 ) ;
if ( F_46 ( V_237 <= 0 ) )
return 162000 ;
return V_245 [ F_133 ( 0 , V_245 ) - 1 ] ;
}
int F_134 ( struct V_1 * V_1 , int V_246 )
{
return F_133 ( V_246 , V_1 -> V_216 ) ;
}
static void F_135 ( struct V_1 * V_1 , int V_206 ,
T_3 * V_247 , T_3 * V_248 )
{
if ( V_1 -> V_217 ) {
* V_247 = 0 ;
* V_248 =
F_134 ( V_1 , V_206 ) ;
} else {
* V_247 = F_136 ( V_206 ) ;
* V_248 = 0 ;
}
}
bool
F_137 ( struct V_51 * V_52 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_249 = & V_199 -> V_4 . V_249 ;
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_250 * V_250 = F_138 ( V_199 -> V_4 . V_251 ) ;
struct V_30 * V_30 = V_1 -> V_252 ;
int V_10 , clock ;
int V_253 = 1 ;
int V_254 = F_10 ( V_1 ) ;
int V_255 = 0 ;
int V_256 ;
int V_24 , V_35 ;
int V_257 , V_258 ;
int V_232 [ V_235 ] = {} ;
int V_241 ;
T_3 V_247 , V_248 ;
V_241 = F_130 ( V_1 , V_232 ) ;
F_46 ( V_241 <= 0 ) ;
V_256 = V_241 - 1 ;
if ( F_66 ( V_7 ) && ! F_11 ( V_7 ) && V_19 != V_20 )
V_199 -> V_259 = true ;
V_199 -> V_260 = true ;
V_199 -> V_261 = false ;
V_199 -> V_262 = V_1 -> V_262 && V_19 != V_20 ;
if ( F_1 ( V_1 ) && V_30 -> V_32 . V_31 ) {
F_139 ( V_30 -> V_32 . V_31 ,
V_249 ) ;
if ( F_124 ( V_7 ) -> V_220 >= 9 ) {
int V_134 ;
V_134 = F_140 ( V_199 ) ;
if ( V_134 )
return V_134 ;
}
if ( ! F_66 ( V_7 ) )
F_141 ( V_250 , V_199 ,
V_30 -> V_32 . V_263 ) ;
else
F_142 ( V_250 , V_199 ,
V_30 -> V_32 . V_263 ) ;
}
if ( V_249 -> V_41 & V_42 )
return false ;
F_34 ( L_28
L_29 ,
V_254 , V_232 [ V_256 ] ,
V_249 -> V_264 ) ;
V_24 = V_199 -> V_265 ;
if ( F_1 ( V_1 ) ) {
if ( V_30 -> V_4 . V_266 . V_267 == 0 &&
( V_54 -> V_174 . V_268 && V_54 -> V_174 . V_268 < V_24 ) ) {
F_34 ( L_30 ,
V_54 -> V_174 . V_268 ) ;
V_24 = V_54 -> V_174 . V_268 ;
}
V_253 = V_254 ;
V_255 = V_256 ;
}
for (; V_24 >= 6 * 3 ; V_24 -= 2 * 3 ) {
V_35 = F_14 ( V_249 -> V_264 ,
V_24 ) ;
for ( clock = V_255 ; clock <= V_256 ; clock ++ ) {
for ( V_10 = V_253 ;
V_10 <= V_254 ;
V_10 <<= 1 ) {
V_258 = V_232 [ clock ] ;
V_257 = F_15 ( V_258 ,
V_10 ) ;
if ( V_35 <= V_257 ) {
goto V_269;
}
}
}
}
return false ;
V_269:
if ( V_1 -> V_270 ) {
V_199 -> V_271 =
V_24 != 18 && F_143 ( V_249 ) > 1 ;
} else {
V_199 -> V_271 =
V_1 -> V_271 ;
}
V_199 -> V_10 = V_10 ;
V_199 -> V_265 = V_24 ;
V_199 -> V_206 = V_232 [ clock ] ;
F_135 ( V_1 , V_199 -> V_206 ,
& V_247 , & V_248 ) ;
F_34 ( L_31 ,
V_247 , V_248 , V_199 -> V_10 ,
V_199 -> V_206 , V_24 ) ;
F_34 ( L_32 ,
V_35 , V_257 ) ;
F_144 ( V_24 , V_10 ,
V_249 -> V_264 ,
V_199 -> V_206 ,
& V_199 -> V_272 ) ;
if ( V_30 -> V_32 . V_273 != NULL &&
V_54 -> V_274 . type == V_275 ) {
V_199 -> V_261 = true ;
F_144 ( V_24 , V_10 ,
V_30 -> V_32 . V_273 -> clock ,
V_199 -> V_206 ,
& V_199 -> V_276 ) ;
}
if ( F_107 ( V_7 ) && F_1 ( V_1 ) )
F_116 ( V_199 ) ;
else if ( F_64 ( V_7 ) )
;
else if ( F_109 ( V_7 ) || F_94 ( V_7 ) )
F_119 ( V_199 ) ;
else
F_127 ( V_52 , V_199 ) ;
return true ;
}
static void F_145 ( struct V_1 * V_1 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_250 * V_251 = F_138 ( V_277 -> V_4 . V_4 . V_251 ) ;
struct V_6 * V_7 = V_251 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_278 ;
F_34 ( L_33 ,
V_251 -> V_279 -> V_206 ) ;
V_278 = F_31 ( V_280 ) ;
V_278 &= ~ V_281 ;
if ( V_251 -> V_279 -> V_206 == 162000 ) {
F_34 ( L_34 ) ;
V_278 |= V_282 ;
V_1 -> V_67 |= V_282 ;
} else {
V_278 |= V_283 ;
V_1 -> V_67 |= V_283 ;
}
F_41 ( V_280 , V_278 ) ;
F_42 ( V_280 ) ;
F_146 ( 500 ) ;
}
void F_147 ( struct V_1 * V_1 ,
const struct V_198 * V_199 )
{
V_1 -> V_284 = V_199 -> V_206 ;
V_1 -> V_10 = V_199 -> V_10 ;
}
static void F_148 ( struct V_51 * V_52 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
const struct V_28 * V_249 = & V_251 -> V_279 -> V_4 . V_249 ;
F_147 ( V_1 , V_251 -> V_279 ) ;
V_1 -> V_67 = F_31 ( V_1 -> V_68 ) & V_70 ;
V_1 -> V_67 |= V_71 | V_72 ;
V_1 -> V_67 |= F_35 ( V_251 -> V_279 -> V_10 ) ;
if ( V_251 -> V_279 -> V_262 )
V_1 -> V_67 |= V_285 ;
if ( F_149 ( V_7 ) && V_19 == V_20 ) {
if ( V_249 -> V_41 & V_286 )
V_1 -> V_67 |= V_287 ;
if ( V_249 -> V_41 & V_288 )
V_1 -> V_67 |= V_289 ;
V_1 -> V_67 |= V_290 ;
if ( F_150 ( V_1 -> V_12 ) )
V_1 -> V_67 |= V_291 ;
V_1 -> V_67 |= V_251 -> V_59 << 29 ;
} else if ( F_151 ( V_7 ) && V_19 != V_20 ) {
T_5 V_292 ;
V_1 -> V_67 |= V_290 ;
V_292 = F_31 ( F_152 ( V_251 -> V_59 ) ) ;
if ( F_150 ( V_1 -> V_12 ) )
V_292 |= V_293 ;
else
V_292 &= ~ V_293 ;
F_41 ( F_152 ( V_251 -> V_59 ) , V_292 ) ;
} else {
if ( ! F_66 ( V_7 ) && ! F_62 ( V_7 ) &&
V_251 -> V_279 -> V_271 )
V_1 -> V_67 |= V_294 ;
if ( V_249 -> V_41 & V_286 )
V_1 -> V_67 |= V_287 ;
if ( V_249 -> V_41 & V_288 )
V_1 -> V_67 |= V_289 ;
V_1 -> V_67 |= V_295 ;
if ( F_150 ( V_1 -> V_12 ) )
V_1 -> V_67 |= V_291 ;
if ( F_36 ( V_7 ) )
V_1 -> V_67 |= F_37 ( V_251 -> V_59 ) ;
else if ( V_251 -> V_59 == V_74 )
V_1 -> V_67 |= V_75 ;
}
}
static void F_153 ( struct V_1 * V_1 ,
T_5 V_296 ,
T_5 V_297 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_298 , V_97 ;
F_45 ( & V_54 -> V_58 ) ;
V_298 = F_67 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
F_34 ( L_35 ,
V_296 , V_297 ,
F_31 ( V_298 ) ,
F_31 ( V_97 ) ) ;
if ( F_154 ( ( F_31 ( V_298 ) & V_296 ) == V_297 , 5000 , 10 ) ) {
F_82 ( L_36 ,
F_31 ( V_298 ) ,
F_31 ( V_97 ) ) ;
}
F_34 ( L_37 ) ;
}
static void F_155 ( struct V_1 * V_1 )
{
F_34 ( L_38 ) ;
F_153 ( V_1 , V_299 , V_300 ) ;
}
static void F_156 ( struct V_1 * V_1 )
{
F_34 ( L_39 ) ;
F_153 ( V_1 , V_301 , V_302 ) ;
}
static void F_157 ( struct V_1 * V_1 )
{
F_34 ( L_40 ) ;
F_158 ( V_1 -> V_303 ,
V_1 -> V_103 ) ;
F_153 ( V_1 , V_304 , V_305 ) ;
}
static void F_159 ( struct V_1 * V_1 )
{
F_158 ( V_1 -> V_306 ,
V_1 -> V_307 ) ;
}
static void F_160 ( struct V_1 * V_1 )
{
F_158 ( V_1 -> V_308 ,
V_1 -> V_309 ) ;
}
static T_5 F_161 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_310 ;
F_45 ( & V_54 -> V_58 ) ;
V_310 = F_31 ( F_63 ( V_1 ) ) ;
if ( ! F_64 ( V_7 ) ) {
V_310 &= ~ V_311 ;
V_310 |= V_101 ;
}
return V_310 ;
}
static bool F_99 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_312 ;
T_5 V_298 , V_97 ;
bool V_313 = ! V_1 -> V_314 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_162 ( & V_1 -> V_315 ) ;
V_1 -> V_314 = true ;
if ( F_75 ( V_1 ) )
return V_313 ;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
F_34 ( L_41 ,
F_33 ( V_3 -> V_19 ) ) ;
if ( ! F_74 ( V_1 ) )
F_157 ( V_1 ) ;
V_312 = F_161 ( V_1 ) ;
V_312 |= V_85 ;
V_298 = F_67 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
F_34 ( L_42 ,
F_31 ( V_298 ) , F_31 ( V_97 ) ) ;
if ( ! F_74 ( V_1 ) ) {
F_34 ( L_43 ,
F_33 ( V_3 -> V_19 ) ) ;
F_73 ( V_1 -> V_316 ) ;
}
return V_313 ;
}
void F_163 ( struct V_1 * V_1 )
{
bool V_137 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_137 = F_99 ( V_1 ) ;
F_25 ( V_1 ) ;
F_164 ( ! V_137 , L_44 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
}
static void F_165 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
enum V_56 V_57 ;
T_5 V_312 ;
T_5 V_298 , V_97 ;
F_45 ( & V_54 -> V_58 ) ;
F_46 ( V_1 -> V_314 ) ;
if ( ! F_75 ( V_1 ) )
return;
F_34 ( L_45 ,
F_33 ( V_3 -> V_19 ) ) ;
V_312 = F_161 ( V_1 ) ;
V_312 &= ~ V_85 ;
V_97 = F_63 ( V_1 ) ;
V_298 = F_67 ( V_1 ) ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
F_34 ( L_42 ,
F_31 ( V_298 ) , F_31 ( V_97 ) ) ;
if ( ( V_312 & V_317 ) == 0 )
V_1 -> V_303 = V_318 ;
V_57 = F_22 ( V_51 ) ;
F_27 ( V_54 , V_57 ) ;
}
static void F_166 ( struct V_319 * V_320 )
{
struct V_1 * V_1 = F_70 ( F_167 ( V_320 ) ,
struct V_1 , V_315 ) ;
F_21 ( V_1 ) ;
if ( ! V_1 -> V_314 )
F_165 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_168 ( struct V_1 * V_1 )
{
unsigned long V_321 ;
V_321 = F_169 ( V_1 -> V_103 * 5 ) ;
F_170 ( & V_1 -> V_315 , V_321 ) ;
}
static void F_103 ( struct V_1 * V_1 , bool V_322 )
{
struct V_53 * V_54 =
F_3 ( V_1 ) -> V_55 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_164 ( ! V_1 -> V_314 , L_46 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
V_1 -> V_314 = false ;
if ( V_322 )
F_165 ( V_1 ) ;
else
F_168 ( V_1 ) ;
}
static void F_171 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_312 ;
T_5 V_97 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_47 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
if ( F_9 ( F_74 ( V_1 ) ,
L_48 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) )
return;
F_157 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
V_312 = F_161 ( V_1 ) ;
if ( F_172 ( V_7 ) ) {
V_312 &= ~ V_323 ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
}
V_312 |= V_317 ;
if ( ! F_172 ( V_7 ) )
V_312 |= V_323 ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
F_155 ( V_1 ) ;
V_1 -> V_306 = V_318 ;
if ( F_172 ( V_7 ) ) {
V_312 |= V_323 ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
}
}
void F_173 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_171 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_312 ;
T_5 V_97 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_49 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
F_9 ( ! V_1 -> V_314 , L_50 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
V_312 = F_161 ( V_1 ) ;
V_312 &= ~ ( V_317 | V_323 | V_85 |
V_324 ) ;
V_97 = F_63 ( V_1 ) ;
V_1 -> V_314 = false ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
V_1 -> V_303 = V_318 ;
F_156 ( V_1 ) ;
V_57 = F_22 ( V_51 ) ;
F_27 ( V_54 , V_57 ) ;
}
void F_175 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_174 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_176 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_312 ;
T_5 V_97 ;
F_159 ( V_1 ) ;
F_21 ( V_1 ) ;
V_312 = F_161 ( V_1 ) ;
V_312 |= V_324 ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
F_25 ( V_1 ) ;
}
void F_177 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_51 ) ;
F_178 ( V_1 -> V_252 ) ;
F_176 ( V_1 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_312 ;
T_5 V_97 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_312 = F_161 ( V_1 ) ;
V_312 &= ~ V_324 ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_312 ) ;
F_42 ( V_97 ) ;
F_25 ( V_1 ) ;
V_1 -> V_308 = V_318 ;
F_160 ( V_1 ) ;
}
void F_180 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_51 ) ;
F_179 ( V_1 ) ;
F_181 ( V_1 -> V_252 ) ;
}
static void F_182 ( struct V_30 * V_9 ,
bool V_325 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_326 ;
F_21 ( V_1 ) ;
V_326 = F_161 ( V_1 ) & V_324 ;
F_25 ( V_1 ) ;
if ( V_326 == V_325 )
return;
F_34 ( L_52 ,
V_325 ? L_53 : L_54 ) ;
if ( V_325 )
F_176 ( V_1 ) ;
else
F_179 ( V_1 ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_327 * V_251 = V_3 -> V_4 . V_4 . V_251 ;
struct V_6 * V_7 = V_251 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_278 ;
F_184 ( V_54 ,
F_138 ( V_251 ) -> V_59 ) ;
F_34 ( L_51 ) ;
V_278 = F_31 ( V_280 ) ;
F_9 ( V_278 & V_328 , L_55 ) ;
F_9 ( V_278 & V_69 , L_56 ) ;
V_1 -> V_67 &= ~ ( V_69 | V_285 ) ;
V_1 -> V_67 |= V_328 ;
F_41 ( V_280 , V_1 -> V_67 ) ;
F_42 ( V_280 ) ;
F_146 ( 200 ) ;
}
static void F_185 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_327 * V_251 = V_3 -> V_4 . V_4 . V_251 ;
struct V_6 * V_7 = V_251 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_278 ;
F_184 ( V_54 ,
F_138 ( V_251 ) -> V_59 ) ;
V_278 = F_31 ( V_280 ) ;
F_9 ( ( V_278 & V_328 ) == 0 ,
L_57 ) ;
F_9 ( V_278 & V_69 , L_56 ) ;
V_278 &= ~ V_328 ;
F_41 ( V_280 , V_278 ) ;
F_42 ( V_280 ) ;
F_146 ( 200 ) ;
}
void F_186 ( struct V_1 * V_1 , int V_29 )
{
int V_134 , V_47 ;
if ( V_1 -> V_12 [ V_329 ] < 0x11 )
return;
if ( V_29 != V_330 ) {
V_134 = F_187 ( & V_1 -> V_151 , V_331 ,
V_332 ) ;
} else {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_134 = F_187 ( & V_1 -> V_151 , V_331 ,
V_333 ) ;
if ( V_134 == 1 )
break;
F_73 ( 1 ) ;
}
}
if ( V_134 != 1 )
F_34 ( L_58 ,
V_29 == V_330 ? L_53 : L_54 ) ;
}
static bool F_188 ( struct V_51 * V_52 ,
enum V_59 * V_59 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_83 ;
V_57 = F_189 ( V_52 ) ;
if ( ! F_190 ( V_54 , V_57 ) )
return false ;
V_83 = F_31 ( V_1 -> V_68 ) ;
if ( ! ( V_83 & V_69 ) )
return false ;
if ( F_149 ( V_7 ) && V_19 == V_20 ) {
* V_59 = F_191 ( V_83 ) ;
} else if ( F_151 ( V_7 ) && V_19 != V_20 ) {
enum V_59 V_334 ;
F_192 (dev_priv, p) {
T_5 V_292 = F_31 ( F_152 ( V_334 ) ) ;
if ( F_193 ( V_292 ) == V_19 ) {
* V_59 = V_334 ;
return true ;
}
}
F_34 ( L_59 ,
V_1 -> V_68 ) ;
} else if ( F_36 ( V_7 ) ) {
* V_59 = F_194 ( V_83 ) ;
} else {
* V_59 = F_195 ( V_83 ) ;
}
return true ;
}
static void F_196 ( struct V_51 * V_52 ,
struct V_198 * V_199 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
T_5 V_83 , V_41 = 0 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
int V_335 ;
V_83 = F_31 ( V_1 -> V_68 ) ;
V_199 -> V_262 = V_83 & V_285 && V_19 != V_20 ;
if ( F_151 ( V_7 ) && V_19 != V_20 ) {
T_5 V_292 = F_31 ( F_152 ( V_251 -> V_59 ) ) ;
if ( V_292 & V_336 )
V_41 |= V_286 ;
else
V_41 |= V_337 ;
if ( V_292 & V_338 )
V_41 |= V_288 ;
else
V_41 |= V_339 ;
} else {
if ( V_83 & V_287 )
V_41 |= V_286 ;
else
V_41 |= V_337 ;
if ( V_83 & V_289 )
V_41 |= V_288 ;
else
V_41 |= V_339 ;
}
V_199 -> V_4 . V_249 . V_41 |= V_41 ;
if ( ! F_66 ( V_7 ) && ! F_62 ( V_7 ) &&
V_83 & V_294 )
V_199 -> V_271 = true ;
V_199 -> V_260 = true ;
V_199 -> V_10 =
( ( V_83 & V_340 ) >> V_341 ) + 1 ;
F_197 ( V_251 , V_199 ) ;
if ( V_19 == V_20 ) {
if ( ( F_31 ( V_280 ) & V_281 ) == V_282 )
V_199 -> V_206 = 162000 ;
else
V_199 -> V_206 = 270000 ;
}
V_335 = F_198 ( V_199 -> V_206 ,
& V_199 -> V_272 ) ;
if ( F_66 ( V_54 -> V_7 ) && V_19 != V_20 )
F_199 ( V_199 , V_335 ) ;
V_199 -> V_4 . V_249 . V_264 = V_335 ;
if ( F_1 ( V_1 ) && V_54 -> V_174 . V_268 &&
V_199 -> V_265 > V_54 -> V_174 . V_268 ) {
F_34 ( L_60 ,
V_199 -> V_265 , V_54 -> V_174 . V_268 ) ;
V_54 -> V_174 . V_268 = V_199 -> V_265 ;
}
}
static void F_200 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
if ( V_251 -> V_279 -> V_262 )
F_201 ( V_52 ) ;
if ( F_202 ( V_7 ) && ! F_11 ( V_7 ) )
F_203 ( V_1 ) ;
F_163 ( V_1 ) ;
F_180 ( V_1 ) ;
F_186 ( V_1 , V_342 ) ;
F_175 ( V_1 ) ;
if ( F_124 ( V_7 ) -> V_220 < 5 )
F_204 ( V_1 ) ;
}
static void F_205 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
F_204 ( V_1 ) ;
if ( V_19 == V_20 )
F_185 ( V_1 ) ;
}
static void F_206 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_204 ( V_1 ) ;
}
static void F_207 ( struct V_51 * V_52 ,
bool V_343 )
{
struct V_53 * V_54 = F_208 ( V_52 -> V_4 . V_7 ) ;
enum V_65 V_66 = F_209 ( F_210 ( & V_52 -> V_4 ) ) ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
enum V_59 V_59 = V_251 -> V_59 ;
T_2 V_344 ;
V_344 = F_211 ( V_54 , V_59 , F_212 ( V_66 ) ) ;
if ( V_343 )
V_344 &= ~ ( V_345 | V_346 ) ;
else
V_344 |= V_345 | V_346 ;
F_213 ( V_54 , V_59 , F_212 ( V_66 ) , V_344 ) ;
if ( V_251 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_214 ( V_66 ) ) ;
if ( V_343 )
V_344 &= ~ ( V_345 | V_346 ) ;
else
V_344 |= V_345 | V_346 ;
F_213 ( V_54 , V_59 , F_214 ( V_66 ) , V_344 ) ;
}
V_344 = F_211 ( V_54 , V_59 , F_215 ( V_66 ) ) ;
V_344 |= V_347 ;
if ( V_343 )
V_344 &= ~ V_348 ;
else
V_344 |= V_348 ;
F_213 ( V_54 , V_59 , F_215 ( V_66 ) , V_344 ) ;
if ( V_251 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_216 ( V_66 ) ) ;
V_344 |= V_347 ;
if ( V_343 )
V_344 &= ~ V_348 ;
else
V_344 |= V_348 ;
F_213 ( V_54 , V_59 , F_216 ( V_66 ) , V_344 ) ;
}
}
static void F_217 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_204 ( V_1 ) ;
F_24 ( & V_54 -> V_349 ) ;
F_207 ( V_52 , true ) ;
F_26 ( & V_54 -> V_349 ) ;
}
static void
F_218 ( struct V_1 * V_1 ,
T_2 * V_67 ,
T_3 V_350 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
if ( F_11 ( V_7 ) ) {
T_2 V_351 = F_31 ( F_219 ( V_19 ) ) ;
if ( V_350 & V_352 )
V_351 |= V_353 ;
else
V_351 &= ~ V_353 ;
V_351 &= ~ V_354 ;
switch ( V_350 & V_355 ) {
case V_356 :
V_351 |= V_357 ;
break;
case V_358 :
V_351 |= V_359 ;
break;
case V_360 :
V_351 |= V_361 ;
break;
case V_362 :
V_351 |= V_363 ;
break;
}
F_41 ( F_219 ( V_19 ) , V_351 ) ;
} else if ( ( F_149 ( V_7 ) && V_19 == V_20 ) ||
( F_151 ( V_7 ) && V_19 != V_20 ) ) {
* V_67 &= ~ V_364 ;
switch ( V_350 & V_355 ) {
case V_356 :
* V_67 |= V_290 ;
break;
case V_358 :
* V_67 |= V_365 ;
break;
case V_360 :
* V_67 |= V_366 ;
break;
case V_362 :
F_82 ( L_61 ) ;
* V_67 |= V_366 ;
break;
}
} else {
if ( F_36 ( V_7 ) )
* V_67 &= ~ V_367 ;
else
* V_67 &= ~ V_368 ;
switch ( V_350 & V_355 ) {
case V_356 :
* V_67 |= V_295 ;
break;
case V_358 :
* V_67 |= V_73 ;
break;
case V_360 :
* V_67 |= V_369 ;
break;
case V_362 :
if ( F_36 ( V_7 ) ) {
* V_67 |= V_370 ;
} else {
F_82 ( L_61 ) ;
* V_67 |= V_369 ;
}
break;
}
}
}
static void F_220 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_218 ( V_1 , & V_1 -> V_67 ,
V_358 ) ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_1 -> V_67 |= V_69 ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
}
static void F_221 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
T_2 V_371 = F_31 ( V_1 -> V_68 ) ;
if ( F_46 ( V_371 & V_69 ) )
return;
F_21 ( V_1 ) ;
if ( F_62 ( V_7 ) )
F_222 ( V_1 ) ;
F_220 ( V_1 ) ;
F_99 ( V_1 ) ;
F_171 ( V_1 ) ;
F_103 ( V_1 , true ) ;
F_25 ( V_1 ) ;
if ( F_62 ( V_7 ) ) {
unsigned int V_372 = 0x0 ;
if ( F_36 ( V_7 ) )
V_372 = F_7 ( V_251 -> V_279 -> V_10 ) ;
F_223 ( V_54 , F_2 ( V_1 ) ,
V_372 ) ;
}
F_186 ( V_1 , V_330 ) ;
F_224 ( V_1 ) ;
F_225 ( V_1 ) ;
if ( V_251 -> V_279 -> V_262 ) {
F_226 ( L_62 ,
F_32 ( V_251 -> V_59 ) ) ;
F_227 ( V_52 ) ;
}
}
static void F_228 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_221 ( V_52 ) ;
F_177 ( V_1 ) ;
}
static void F_229 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_177 ( V_1 ) ;
F_230 ( V_1 ) ;
}
static void F_231 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_2 * V_373 = F_2 ( V_1 ) ;
F_148 ( V_52 ) ;
if ( V_373 -> V_19 == V_20 ) {
F_145 ( V_1 ) ;
F_183 ( V_1 ) ;
}
}
static void F_232 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 = V_3 -> V_4 . V_4 . V_7 -> V_55 ;
enum V_59 V_59 = V_1 -> V_60 ;
int V_374 = F_58 ( V_59 ) ;
F_165 ( V_1 ) ;
F_34 ( L_63 ,
F_32 ( V_59 ) , F_33 ( V_3 -> V_19 ) ) ;
F_41 ( V_374 , 0 ) ;
F_42 ( V_374 ) ;
V_1 -> V_60 = V_82 ;
}
static void F_49 ( struct V_6 * V_7 ,
enum V_59 V_59 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_51 * V_52 ;
F_45 ( & V_54 -> V_58 ) ;
if ( F_46 ( V_59 != V_81 && V_59 != V_74 ) )
return;
F_47 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_1 ;
enum V_19 V_19 ;
if ( V_52 -> type != V_5 )
continue;
V_1 = F_5 ( & V_52 -> V_4 ) ;
V_19 = F_2 ( V_1 ) -> V_19 ;
if ( V_1 -> V_60 != V_59 )
continue;
F_34 ( L_64 ,
F_32 ( V_59 ) , F_33 ( V_19 ) ) ;
F_9 ( V_52 -> V_4 . V_251 ,
L_65 ,
F_32 ( V_59 ) , F_33 ( V_19 ) ) ;
F_232 ( V_1 ) ;
}
}
static void F_222 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_251 = F_138 ( V_52 -> V_4 . V_251 ) ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_60 == V_251 -> V_59 )
return;
if ( V_1 -> V_60 != V_82 )
F_232 ( V_1 ) ;
F_49 ( V_7 , V_251 -> V_59 ) ;
V_1 -> V_60 = V_251 -> V_59 ;
F_34 ( L_66 ,
F_32 ( V_1 -> V_60 ) , F_33 ( V_3 -> V_19 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
static void F_233 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_2 * V_373 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_250 = F_138 ( V_52 -> V_4 . V_251 ) ;
enum V_65 V_19 = F_209 ( V_373 ) ;
int V_59 = V_250 -> V_59 ;
T_5 V_344 ;
F_24 ( & V_54 -> V_349 ) ;
V_344 = F_211 ( V_54 , V_59 , F_234 ( V_19 ) ) ;
V_344 = 0 ;
if ( V_59 )
V_344 |= ( 1 << 21 ) ;
else
V_344 &= ~ ( 1 << 21 ) ;
V_344 |= 0x001000c4 ;
F_213 ( V_54 , V_59 , F_235 ( V_19 ) , V_344 ) ;
F_213 ( V_54 , V_59 , F_236 ( V_19 ) , 0x00760018 ) ;
F_213 ( V_54 , V_59 , F_237 ( V_19 ) , 0x00400888 ) ;
F_26 ( & V_54 -> V_349 ) ;
F_221 ( V_52 ) ;
}
static void F_238 ( struct V_51 * V_52 )
{
struct V_2 * V_373 = F_210 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_250 =
F_138 ( V_52 -> V_4 . V_251 ) ;
enum V_65 V_19 = F_209 ( V_373 ) ;
int V_59 = V_250 -> V_59 ;
F_148 ( V_52 ) ;
F_24 ( & V_54 -> V_349 ) ;
F_213 ( V_54 , V_59 , F_239 ( V_19 ) ,
V_345 |
V_346 ) ;
F_213 ( V_54 , V_59 , F_240 ( V_19 ) ,
V_375 |
V_376 |
( 1 << V_377 ) |
V_348 ) ;
F_213 ( V_54 , V_59 , F_241 ( V_19 ) , 0x00750f00 ) ;
F_213 ( V_54 , V_59 , F_242 ( V_19 ) , 0x00001500 ) ;
F_213 ( V_54 , V_59 , F_243 ( V_19 ) , 0x40400000 ) ;
F_26 ( & V_54 -> V_349 ) ;
}
static void F_244 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_2 * V_373 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_250 =
F_138 ( V_52 -> V_4 . V_251 ) ;
enum V_65 V_66 = F_209 ( V_373 ) ;
int V_59 = V_250 -> V_59 ;
int V_378 , V_47 , V_379 ;
T_5 V_344 ;
F_24 ( & V_54 -> V_349 ) ;
V_344 = F_211 ( V_54 , V_59 , F_245 ( V_66 ) ) ;
V_344 &= ~ V_380 ;
F_213 ( V_54 , V_59 , F_245 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_246 ( V_66 ) ) ;
V_344 &= ~ V_380 ;
F_213 ( V_54 , V_59 , F_246 ( V_66 ) , V_344 ) ;
}
for ( V_47 = 0 ; V_47 < V_250 -> V_279 -> V_10 ; V_47 ++ ) {
if ( V_250 -> V_279 -> V_10 == 1 )
V_378 = 0x0 ;
else
V_378 = ( V_47 == 1 ) ? 0x0 : 0x1 ;
F_213 ( V_54 , V_59 , F_247 ( V_66 , V_47 ) ,
V_378 << V_381 ) ;
}
if ( V_250 -> V_279 -> V_206 > 270000 )
V_379 = 0x18 ;
else if ( V_250 -> V_279 -> V_206 > 135000 )
V_379 = 0xd ;
else if ( V_250 -> V_279 -> V_206 > 67500 )
V_379 = 0x7 ;
else if ( V_250 -> V_279 -> V_206 > 33750 )
V_379 = 0x4 ;
else
V_379 = 0x2 ;
V_344 = F_211 ( V_54 , V_59 , F_245 ( V_66 ) ) ;
V_344 |= F_248 ( 0x1f ) ;
F_213 ( V_54 , V_59 , F_245 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_246 ( V_66 ) ) ;
V_344 |= F_248 ( 0x1f ) ;
F_213 ( V_54 , V_59 , F_246 ( V_66 ) , V_344 ) ;
}
F_213 ( V_54 , V_59 , F_249 ( V_66 ) ,
F_250 ( V_379 ) |
V_382 |
F_251 ( 0x1f ) |
F_252 ( 6 ) |
F_253 ( 0 ) ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
F_213 ( V_54 , V_59 , F_254 ( V_66 ) ,
F_250 ( V_379 ) |
V_382 |
F_251 ( 0x1f ) |
F_252 ( 7 ) |
F_253 ( 5 ) ) ;
}
F_207 ( V_52 , false ) ;
F_26 ( & V_54 -> V_349 ) ;
F_221 ( V_52 ) ;
if ( V_373 -> V_383 ) {
F_39 ( V_54 , V_384 , V_385 , false ) ;
V_373 -> V_383 = false ;
}
}
static void F_255 ( struct V_51 * V_52 )
{
struct V_2 * V_373 = F_210 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_250 * V_250 =
F_138 ( V_52 -> V_4 . V_251 ) ;
enum V_65 V_66 = F_209 ( V_373 ) ;
enum V_59 V_59 = V_250 -> V_59 ;
unsigned int V_372 =
F_7 ( V_250 -> V_279 -> V_10 ) ;
T_5 V_344 ;
F_148 ( V_52 ) ;
if ( V_66 == V_386 && V_59 == V_74 )
V_373 -> V_383 =
! F_39 ( V_54 , V_384 , V_385 , true ) ;
F_256 ( V_52 , true , V_372 ) ;
F_24 ( & V_54 -> V_349 ) ;
F_207 ( V_52 , true ) ;
if ( V_59 != V_74 ) {
V_344 = F_211 ( V_54 , V_59 , V_387 ) ;
V_344 &= ~ ( V_388 | V_389 ) ;
if ( V_66 == V_386 )
V_344 |= V_390 ;
if ( V_66 == V_385 )
V_344 |= V_391 ;
F_213 ( V_54 , V_59 , V_387 , V_344 ) ;
} else {
V_344 = F_211 ( V_54 , V_59 , V_392 ) ;
V_344 &= ~ ( V_393 | V_394 ) ;
if ( V_66 == V_386 )
V_344 |= V_395 ;
if ( V_66 == V_385 )
V_344 |= V_396 ;
F_213 ( V_54 , V_59 , V_392 , V_344 ) ;
}
V_344 = F_211 ( V_54 , V_59 , F_234 ( V_66 ) ) ;
V_344 |= V_397 ;
if ( V_59 != V_74 )
V_344 &= ~ V_398 ;
else
V_344 |= V_398 ;
F_213 ( V_54 , V_59 , F_234 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_257 ( V_66 ) ) ;
V_344 |= V_397 ;
if ( V_59 != V_74 )
V_344 &= ~ V_398 ;
else
V_344 |= V_398 ;
F_213 ( V_54 , V_59 , F_257 ( V_66 ) , V_344 ) ;
}
V_344 = F_211 ( V_54 , V_59 , F_258 ( V_66 ) ) ;
if ( V_59 != V_74 )
V_344 &= ~ V_399 ;
else
V_344 |= V_399 ;
F_213 ( V_54 , V_59 , F_258 ( V_66 ) , V_344 ) ;
F_26 ( & V_54 -> V_349 ) ;
}
static void F_259 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_208 ( V_52 -> V_4 . V_7 ) ;
enum V_59 V_59 = F_138 ( V_52 -> V_4 . V_251 ) -> V_59 ;
T_5 V_344 ;
F_24 ( & V_54 -> V_349 ) ;
if ( V_59 != V_74 ) {
V_344 = F_211 ( V_54 , V_59 , V_387 ) ;
V_344 &= ~ ( V_388 | V_389 ) ;
F_213 ( V_54 , V_59 , V_387 , V_344 ) ;
} else {
V_344 = F_211 ( V_54 , V_59 , V_392 ) ;
V_344 &= ~ ( V_393 | V_394 ) ;
F_213 ( V_54 , V_59 , V_392 , V_344 ) ;
}
F_26 ( & V_54 -> V_349 ) ;
F_256 ( V_52 , false , 0x0 ) ;
}
static T_6
F_260 ( struct V_150 * V_151 , unsigned int V_400 ,
void * V_167 , T_7 V_160 )
{
T_6 V_134 ;
int V_47 ;
F_261 ( V_151 , V_329 , V_167 , 1 ) ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_134 = F_261 ( V_151 , V_400 , V_167 , V_160 ) ;
if ( V_134 == V_160 )
return V_134 ;
F_73 ( 1 ) ;
}
return V_134 ;
}
static bool
F_262 ( struct V_1 * V_1 , T_3 V_401 [ V_402 ] )
{
return F_260 ( & V_1 -> V_151 ,
V_403 ,
V_401 ,
V_402 ) == V_402 ;
}
static T_3
F_263 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
if ( F_64 ( V_7 ) )
return V_404 ;
else if ( F_124 ( V_7 ) -> V_220 >= 9 ) {
if ( V_54 -> V_405 && V_19 == V_20 )
return V_404 ;
return V_406 ;
} else if ( F_62 ( V_7 ) )
return V_404 ;
else if ( F_149 ( V_7 ) && V_19 == V_20 )
return V_406 ;
else if ( F_151 ( V_7 ) && V_19 != V_20 )
return V_404 ;
else
return V_406 ;
}
static T_3
F_264 ( struct V_1 * V_1 , T_3 V_407 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
if ( F_124 ( V_7 ) -> V_220 >= 9 ) {
switch ( V_407 & V_408 ) {
case V_409 :
return V_410 ;
case V_411 :
return V_412 ;
case V_406 :
return V_413 ;
case V_404 :
return V_414 ;
default:
return V_414 ;
}
} else if ( F_109 ( V_7 ) || F_94 ( V_7 ) ) {
switch ( V_407 & V_408 ) {
case V_409 :
return V_410 ;
case V_411 :
return V_412 ;
case V_406 :
return V_413 ;
case V_404 :
default:
return V_414 ;
}
} else if ( F_62 ( V_7 ) ) {
switch ( V_407 & V_408 ) {
case V_409 :
return V_410 ;
case V_411 :
return V_412 ;
case V_406 :
return V_413 ;
case V_404 :
default:
return V_414 ;
}
} else if ( F_149 ( V_7 ) && V_19 == V_20 ) {
switch ( V_407 & V_408 ) {
case V_409 :
return V_412 ;
case V_411 :
case V_406 :
return V_413 ;
default:
return V_414 ;
}
} else {
switch ( V_407 & V_408 ) {
case V_409 :
return V_412 ;
case V_411 :
return V_412 ;
case V_406 :
return V_413 ;
case V_404 :
default:
return V_414 ;
}
}
}
static T_2 F_265 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_373 = F_2 ( V_1 ) ;
struct V_250 * V_250 =
F_138 ( V_373 -> V_4 . V_4 . V_251 ) ;
unsigned long V_415 , V_416 ,
V_417 ;
T_3 V_418 = V_1 -> V_418 [ 0 ] ;
enum V_65 V_19 = F_209 ( V_373 ) ;
int V_59 = V_250 -> V_59 ;
switch ( V_418 & V_419 ) {
case V_414 :
V_416 = 0x0004000 ;
switch ( V_418 & V_408 ) {
case V_409 :
V_415 = 0x2B405555 ;
V_417 = 0x552AB83A ;
break;
case V_411 :
V_415 = 0x2B404040 ;
V_417 = 0x5548B83A ;
break;
case V_406 :
V_415 = 0x2B245555 ;
V_417 = 0x5560B83A ;
break;
case V_404 :
V_415 = 0x2B405555 ;
V_417 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_413 :
V_416 = 0x0002000 ;
switch ( V_418 & V_408 ) {
case V_409 :
V_415 = 0x2B404040 ;
V_417 = 0x5552B83A ;
break;
case V_411 :
V_415 = 0x2B404848 ;
V_417 = 0x5580B83A ;
break;
case V_406 :
V_415 = 0x2B404040 ;
V_417 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_412 :
V_416 = 0x0000000 ;
switch ( V_418 & V_408 ) {
case V_409 :
V_415 = 0x2B305555 ;
V_417 = 0x5570B83A ;
break;
case V_411 :
V_415 = 0x2B2B4040 ;
V_417 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_410 :
V_416 = 0x0006000 ;
switch ( V_418 & V_408 ) {
case V_409 :
V_415 = 0x1B405555 ;
V_417 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_54 -> V_349 ) ;
F_213 ( V_54 , V_59 , F_266 ( V_19 ) , 0x00000000 ) ;
F_213 ( V_54 , V_59 , F_267 ( V_19 ) , V_415 ) ;
F_213 ( V_54 , V_59 , F_268 ( V_19 ) ,
V_417 ) ;
F_213 ( V_54 , V_59 , F_269 ( V_19 ) , 0x0C782040 ) ;
F_213 ( V_54 , V_59 , F_270 ( V_19 ) , 0x00030000 ) ;
F_213 ( V_54 , V_59 , F_271 ( V_19 ) , V_416 ) ;
F_213 ( V_54 , V_59 , F_266 ( V_19 ) , 0x80000000 ) ;
F_26 ( & V_54 -> V_349 ) ;
return 0 ;
}
static bool F_272 ( T_3 V_418 )
{
return ( V_418 & V_419 ) == V_414 &&
( V_418 & V_408 ) == V_404 ;
}
static T_2 F_273 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_373 = F_2 ( V_1 ) ;
struct V_250 * V_250 = F_138 ( V_373 -> V_4 . V_4 . V_251 ) ;
T_5 V_420 , V_421 , V_344 ;
T_3 V_418 = V_1 -> V_418 [ 0 ] ;
enum V_65 V_66 = F_209 ( V_373 ) ;
enum V_59 V_59 = V_250 -> V_59 ;
int V_47 ;
switch ( V_418 & V_419 ) {
case V_414 :
switch ( V_418 & V_408 ) {
case V_409 :
V_420 = 128 ;
V_421 = 52 ;
break;
case V_411 :
V_420 = 128 ;
V_421 = 77 ;
break;
case V_406 :
V_420 = 128 ;
V_421 = 102 ;
break;
case V_404 :
V_420 = 128 ;
V_421 = 154 ;
break;
default:
return 0 ;
}
break;
case V_413 :
switch ( V_418 & V_408 ) {
case V_409 :
V_420 = 85 ;
V_421 = 78 ;
break;
case V_411 :
V_420 = 85 ;
V_421 = 116 ;
break;
case V_406 :
V_420 = 85 ;
V_421 = 154 ;
break;
default:
return 0 ;
}
break;
case V_412 :
switch ( V_418 & V_408 ) {
case V_409 :
V_420 = 64 ;
V_421 = 104 ;
break;
case V_411 :
V_420 = 64 ;
V_421 = 154 ;
break;
default:
return 0 ;
}
break;
case V_410 :
switch ( V_418 & V_408 ) {
case V_409 :
V_420 = 43 ;
V_421 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_54 -> V_349 ) ;
V_344 = F_211 ( V_54 , V_59 , F_274 ( V_66 ) ) ;
V_344 &= ~ ( V_422 | V_423 ) ;
V_344 &= ~ ( V_424 | V_425 ) ;
V_344 |= V_426 | V_427 ;
F_213 ( V_54 , V_59 , F_274 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_275 ( V_66 ) ) ;
V_344 &= ~ ( V_422 | V_423 ) ;
V_344 &= ~ ( V_424 | V_425 ) ;
V_344 |= V_426 | V_427 ;
F_213 ( V_54 , V_59 , F_275 ( V_66 ) , V_344 ) ;
}
V_344 = F_211 ( V_54 , V_59 , F_276 ( V_66 ) ) ;
V_344 &= ~ ( V_428 | V_429 ) ;
V_344 |= V_430 | V_431 ;
F_213 ( V_54 , V_59 , F_276 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_277 ( V_66 ) ) ;
V_344 &= ~ ( V_428 | V_429 ) ;
V_344 |= V_430 | V_431 ;
F_213 ( V_54 , V_59 , F_277 ( V_66 ) , V_344 ) ;
}
for ( V_47 = 0 ; V_47 < V_250 -> V_279 -> V_10 ; V_47 ++ ) {
V_344 = F_211 ( V_54 , V_59 , F_278 ( V_66 , V_47 ) ) ;
V_344 &= ~ V_432 ;
V_344 |= V_420 << V_433 ;
F_213 ( V_54 , V_59 , F_278 ( V_66 , V_47 ) , V_344 ) ;
}
for ( V_47 = 0 ; V_47 < V_250 -> V_279 -> V_10 ; V_47 ++ ) {
V_344 = F_211 ( V_54 , V_59 , F_279 ( V_66 , V_47 ) ) ;
V_344 &= ~ V_434 ;
V_344 |= V_421 << V_435 ;
V_344 &= ~ ( 0xff << V_436 ) ;
V_344 |= 0x9a << V_436 ;
F_213 ( V_54 , V_59 , F_279 ( V_66 , V_47 ) , V_344 ) ;
}
for ( V_47 = 0 ; V_47 < V_250 -> V_279 -> V_10 ; V_47 ++ ) {
V_344 = F_211 ( V_54 , V_59 , F_280 ( V_66 , V_47 ) ) ;
if ( F_272 ( V_418 ) )
V_344 |= V_437 ;
else
V_344 &= ~ V_437 ;
F_213 ( V_54 , V_59 , F_280 ( V_66 , V_47 ) , V_344 ) ;
}
V_344 = F_211 ( V_54 , V_59 , F_274 ( V_66 ) ) ;
V_344 |= V_422 | V_423 ;
F_213 ( V_54 , V_59 , F_274 ( V_66 ) , V_344 ) ;
if ( V_250 -> V_279 -> V_10 > 2 ) {
V_344 = F_211 ( V_54 , V_59 , F_275 ( V_66 ) ) ;
V_344 |= V_422 | V_423 ;
F_213 ( V_54 , V_59 , F_275 ( V_66 ) , V_344 ) ;
}
F_26 ( & V_54 -> V_349 ) ;
return 0 ;
}
static void
F_281 ( struct V_1 * V_1 ,
const T_3 V_401 [ V_402 ] )
{
T_3 V_48 = 0 ;
T_3 V_334 = 0 ;
int V_438 ;
T_3 V_439 ;
T_3 V_440 ;
for ( V_438 = 0 ; V_438 < V_1 -> V_10 ; V_438 ++ ) {
T_3 V_441 = F_282 ( V_401 , V_438 ) ;
T_3 V_442 = F_283 ( V_401 , V_438 ) ;
if ( V_441 > V_48 )
V_48 = V_441 ;
if ( V_442 > V_334 )
V_334 = V_442 ;
}
V_439 = F_263 ( V_1 ) ;
if ( V_48 >= V_439 )
V_48 = V_439 | V_443 ;
V_440 = F_264 ( V_1 , V_48 ) ;
if ( V_334 >= V_440 )
V_334 = V_440 | V_444 ;
for ( V_438 = 0 ; V_438 < 4 ; V_438 ++ )
V_1 -> V_418 [ V_438 ] = V_48 | V_334 ;
}
static T_2
F_284 ( T_3 V_418 )
{
T_2 V_445 = 0 ;
switch ( V_418 & V_408 ) {
case V_409 :
default:
V_445 |= V_71 ;
break;
case V_411 :
V_445 |= V_446 ;
break;
case V_406 :
V_445 |= V_447 ;
break;
case V_404 :
V_445 |= V_448 ;
break;
}
switch ( V_418 & V_419 ) {
case V_414 :
default:
V_445 |= V_72 ;
break;
case V_413 :
V_445 |= V_449 ;
break;
case V_412 :
V_445 |= V_450 ;
break;
case V_410 :
V_445 |= V_451 ;
break;
}
return V_445 ;
}
static T_2
F_285 ( T_3 V_418 )
{
int V_445 = V_418 & ( V_408 |
V_419 ) ;
switch ( V_445 ) {
case V_409 | V_414 :
case V_411 | V_414 :
return V_452 ;
case V_409 | V_413 :
return V_453 ;
case V_409 | V_412 :
case V_411 | V_412 :
return V_454 ;
case V_411 | V_413 :
case V_406 | V_413 :
return V_455 ;
case V_406 | V_414 :
case V_404 | V_414 :
return V_456 ;
default:
F_34 ( L_67
L_68 , V_445 ) ;
return V_452 ;
}
}
static T_2
F_286 ( T_3 V_418 )
{
int V_445 = V_418 & ( V_408 |
V_419 ) ;
switch ( V_445 ) {
case V_409 | V_414 :
return V_457 ;
case V_409 | V_413 :
return V_458 ;
case V_409 | V_412 :
return V_459 ;
case V_411 | V_414 :
return V_460 ;
case V_411 | V_413 :
return V_461 ;
case V_406 | V_414 :
return V_462 ;
case V_406 | V_413 :
return V_463 ;
default:
F_34 ( L_67
L_68 , V_445 ) ;
return V_464 ;
}
}
static void
F_287 ( struct V_1 * V_1 , T_2 * V_67 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_445 , V_296 = 0 ;
T_3 V_418 = V_1 -> V_418 [ 0 ] ;
if ( F_11 ( V_7 ) ) {
V_445 = F_288 ( V_1 ) ;
if ( F_64 ( V_7 ) )
V_445 = 0 ;
else
V_296 = V_465 ;
} else if ( F_36 ( V_7 ) ) {
V_445 = F_273 ( V_1 ) ;
} else if ( F_62 ( V_7 ) ) {
V_445 = F_265 ( V_1 ) ;
} else if ( F_149 ( V_7 ) && V_19 == V_20 ) {
V_445 = F_286 ( V_418 ) ;
V_296 = V_466 ;
} else if ( F_93 ( V_7 ) && V_19 == V_20 ) {
V_445 = F_285 ( V_418 ) ;
V_296 = V_467 ;
} else {
V_445 = F_284 ( V_418 ) ;
V_296 = V_468 | V_469 ;
}
if ( V_296 )
F_34 ( L_69 , V_445 ) ;
F_34 ( L_70 ,
V_418 & V_408 ) ;
F_34 ( L_71 ,
( V_418 & V_419 ) >>
V_470 ) ;
* V_67 = ( * V_67 & ~ V_296 ) | V_445 ;
}
static bool
F_289 ( struct V_1 * V_1 ,
T_2 * V_67 ,
T_3 V_350 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 =
F_208 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_3 V_471 [ sizeof( V_1 -> V_418 ) + 1 ] ;
int V_134 , V_237 ;
F_218 ( V_1 , V_67 , V_350 ) ;
F_41 ( V_1 -> V_68 , * V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_471 [ 0 ] = V_350 ;
if ( ( V_350 & V_355 ) ==
V_356 ) {
V_237 = 1 ;
} else {
memcpy ( V_471 + 1 , V_1 -> V_418 , V_1 -> V_10 ) ;
V_237 = V_1 -> V_10 + 1 ;
}
V_134 = F_290 ( & V_1 -> V_151 , V_472 ,
V_471 , V_237 ) ;
return V_134 == V_237 ;
}
static bool
F_291 ( struct V_1 * V_1 , T_2 * V_67 ,
T_3 V_350 )
{
if ( ! V_1 -> V_473 )
memset ( V_1 -> V_418 , 0 , sizeof( V_1 -> V_418 ) ) ;
F_287 ( V_1 , V_67 ) ;
return F_289 ( V_1 , V_67 , V_350 ) ;
}
static bool
F_292 ( struct V_1 * V_1 , T_2 * V_67 ,
const T_3 V_401 [ V_402 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 =
F_208 ( V_3 -> V_4 . V_4 . V_7 ) ;
int V_134 ;
F_281 ( V_1 , V_401 ) ;
F_287 ( V_1 , V_67 ) ;
F_41 ( V_1 -> V_68 , * V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_134 = F_290 ( & V_1 -> V_151 , V_474 ,
V_1 -> V_418 , V_1 -> V_10 ) ;
return V_134 == V_1 -> V_10 ;
}
static void F_293 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
T_2 V_344 ;
if ( ! F_11 ( V_7 ) )
return;
V_344 = F_31 ( F_219 ( V_19 ) ) ;
V_344 &= ~ V_354 ;
V_344 |= V_475 ;
F_41 ( F_219 ( V_19 ) , V_344 ) ;
if ( V_19 == V_20 )
return;
if ( F_294 ( ( F_31 ( F_295 ( V_19 ) ) & V_476 ) ,
1 ) )
F_82 ( L_72 ) ;
}
static void
F_296 ( struct V_1 * V_1 )
{
struct V_477 * V_52 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_52 -> V_7 ;
int V_47 ;
T_3 V_478 ;
int V_479 , V_480 ;
T_2 V_67 = V_1 -> V_67 ;
T_3 V_481 [ 2 ] ;
T_3 V_247 , V_248 ;
if ( F_11 ( V_7 ) )
F_297 ( V_52 ) ;
F_135 ( V_1 , V_1 -> V_284 ,
& V_247 , & V_248 ) ;
V_481 [ 0 ] = V_247 ;
V_481 [ 1 ] = V_1 -> V_10 ;
if ( F_150 ( V_1 -> V_12 ) )
V_481 [ 1 ] |= V_482 ;
F_290 ( & V_1 -> V_151 , V_483 , V_481 , 2 ) ;
if ( V_1 -> V_217 )
F_290 ( & V_1 -> V_151 , V_484 ,
& V_248 , 1 ) ;
V_481 [ 0 ] = 0 ;
V_481 [ 1 ] = V_485 ;
F_290 ( & V_1 -> V_151 , V_486 , V_481 , 2 ) ;
V_67 |= V_69 ;
if ( ! F_291 ( V_1 , & V_67 ,
V_358 |
V_352 ) ) {
F_82 ( L_73 ) ;
return;
}
V_478 = 0xff ;
V_479 = 0 ;
V_480 = 0 ;
for (; ; ) {
T_3 V_401 [ V_402 ] ;
F_298 ( V_1 -> V_12 ) ;
if ( ! F_262 ( V_1 , V_401 ) ) {
F_82 ( L_74 ) ;
break;
}
if ( F_299 ( V_401 , V_1 -> V_10 ) ) {
F_34 ( L_75 ) ;
break;
}
if ( V_1 -> V_473 ) {
F_34 ( L_76 ) ;
V_1 -> V_473 = false ;
if ( ! F_291 ( V_1 , & V_67 ,
V_358 |
V_352 ) ) {
F_82 ( L_73 ) ;
return;
}
continue;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_10 ; V_47 ++ )
if ( ( V_1 -> V_418 [ V_47 ] & V_443 ) == 0 )
break;
if ( V_47 == V_1 -> V_10 ) {
++ V_480 ;
if ( V_480 == 5 ) {
F_82 ( L_77 ) ;
break;
}
F_291 ( V_1 , & V_67 ,
V_358 |
V_352 ) ;
V_479 = 0 ;
continue;
}
if ( ( V_1 -> V_418 [ 0 ] & V_408 ) == V_478 ) {
++ V_479 ;
if ( V_479 == 5 ) {
F_82 ( L_78 ) ;
break;
}
} else
V_479 = 0 ;
V_478 = V_1 -> V_418 [ 0 ] & V_408 ;
if ( ! F_292 ( V_1 , & V_67 , V_401 ) ) {
F_82 ( L_79 ) ;
break;
}
}
V_1 -> V_67 = V_67 ;
}
static void
F_300 ( struct V_1 * V_1 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_277 -> V_4 . V_4 . V_7 ;
bool V_487 = false ;
int V_488 , V_489 ;
T_2 V_67 = V_1 -> V_67 ;
T_2 V_490 = V_360 ;
if ( F_121 ( V_7 ) &&
F_301 ( V_1 -> V_12 ) )
V_490 = V_362 ;
else if ( V_1 -> V_284 == 540000 )
F_82 ( L_80 ) ;
if ( ! F_289 ( V_1 , & V_67 ,
V_490 |
V_352 ) ) {
F_82 ( L_81 ) ;
return;
}
V_488 = 0 ;
V_489 = 0 ;
V_487 = false ;
for (; ; ) {
T_3 V_401 [ V_402 ] ;
if ( V_489 > 5 ) {
F_82 ( L_82 ) ;
break;
}
F_302 ( V_1 -> V_12 ) ;
if ( ! F_262 ( V_1 , V_401 ) ) {
F_82 ( L_74 ) ;
break;
}
if ( ! F_299 ( V_401 ,
V_1 -> V_10 ) ) {
V_1 -> V_473 = false ;
F_296 ( V_1 ) ;
F_289 ( V_1 , & V_67 ,
V_490 |
V_352 ) ;
V_489 ++ ;
continue;
}
if ( F_303 ( V_401 ,
V_1 -> V_10 ) ) {
V_487 = true ;
break;
}
if ( V_488 > 5 ) {
V_1 -> V_473 = false ;
F_296 ( V_1 ) ;
F_289 ( V_1 , & V_67 ,
V_490 |
V_352 ) ;
V_488 = 0 ;
V_489 ++ ;
continue;
}
if ( ! F_292 ( V_1 , & V_67 , V_401 ) ) {
F_82 ( L_79 ) ;
break;
}
++ V_488 ;
}
F_293 ( V_1 ) ;
V_1 -> V_67 = V_67 ;
if ( V_487 ) {
V_1 -> V_473 = true ;
F_34 ( L_83 ) ;
}
}
void F_225 ( struct V_1 * V_1 )
{
F_289 ( V_1 , & V_1 -> V_67 ,
V_356 ) ;
}
void
F_224 ( struct V_1 * V_1 )
{
F_296 ( V_1 ) ;
F_300 ( V_1 ) ;
}
static void
F_204 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_250 * V_251 = F_138 ( V_3 -> V_4 . V_4 . V_251 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_67 = V_1 -> V_67 ;
if ( F_46 ( F_11 ( V_7 ) ) )
return;
if ( F_46 ( ( F_31 ( V_1 -> V_68 ) & V_69 ) == 0 ) )
return;
F_34 ( L_51 ) ;
if ( ( F_149 ( V_7 ) && V_19 == V_20 ) ||
( F_151 ( V_7 ) && V_19 != V_20 ) ) {
V_67 &= ~ V_364 ;
V_67 |= V_491 ;
} else {
if ( F_36 ( V_7 ) )
V_67 &= ~ V_367 ;
else
V_67 &= ~ V_368 ;
V_67 |= V_492 ;
}
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_67 &= ~ ( V_69 | V_285 ) ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
if ( F_304 ( V_7 ) && V_251 -> V_59 == V_74 && V_19 != V_20 ) {
V_67 &= ~ ( V_75 | V_368 ) ;
V_67 |= V_69 | V_73 ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_67 &= ~ V_69 ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
}
F_73 ( V_1 -> V_493 ) ;
}
static bool
F_305 ( struct V_1 * V_1 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_277 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_3 V_494 ;
if ( F_260 ( & V_1 -> V_151 , 0x000 , V_1 -> V_12 ,
sizeof( V_1 -> V_12 ) ) < 0 )
return false ;
F_34 ( L_84 , ( int ) sizeof( V_1 -> V_12 ) , V_1 -> V_12 ) ;
if ( V_1 -> V_12 [ V_329 ] == 0 )
return false ;
memset ( V_1 -> V_495 , 0 , sizeof( V_1 -> V_495 ) ) ;
if ( F_1 ( V_1 ) ) {
F_260 ( & V_1 -> V_151 , V_496 ,
V_1 -> V_495 ,
sizeof( V_1 -> V_495 ) ) ;
if ( V_1 -> V_495 [ 0 ] & V_497 ) {
V_54 -> V_498 . V_499 = true ;
F_34 ( L_85 ) ;
}
if ( F_124 ( V_7 ) -> V_220 >= 9 &&
( V_1 -> V_495 [ 0 ] & V_500 ) ) {
T_3 V_501 ;
V_54 -> V_498 . V_499 = true ;
F_260 ( & V_1 -> V_151 ,
V_502 ,
& V_501 , 1 ) ;
V_54 -> V_498 . V_503 = V_501 ? true : false ;
V_54 -> V_498 . V_504 = V_54 -> V_498 . V_503 ;
F_34 ( L_86 ,
V_54 -> V_498 . V_504 ? L_87 : L_88 ) ;
}
}
F_34 ( L_89 ,
F_306 ( F_121 ( V_7 ) ) ,
F_306 ( F_301 ( V_1 -> V_12 ) ) ) ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_12 [ V_505 ] & V_506 ) &&
( F_260 ( & V_1 -> V_151 , V_507 , & V_494 , 1 ) == 1 ) &&
( V_494 >= 0x03 ) ) {
T_8 V_216 [ V_235 ] ;
int V_47 ;
F_260 ( & V_1 -> V_151 ,
V_508 ,
V_216 ,
sizeof( V_216 ) ) ;
for ( V_47 = 0 ; V_47 < F_126 ( V_216 ) ; V_47 ++ ) {
int V_344 = F_307 ( V_216 [ V_47 ] ) ;
if ( V_344 == 0 )
break;
V_1 -> V_216 [ V_47 ] = ( V_344 * 200 ) / 10 ;
}
V_1 -> V_217 = V_47 ;
}
F_132 ( V_1 ) ;
if ( ! ( V_1 -> V_12 [ V_509 ] &
V_510 ) )
return true ;
if ( V_1 -> V_12 [ V_329 ] == 0x10 )
return true ;
if ( F_260 ( & V_1 -> V_151 , V_511 ,
V_1 -> V_512 ,
V_513 ) < 0 )
return false ;
return true ;
}
static void
F_308 ( struct V_1 * V_1 )
{
T_1 V_471 [ 3 ] ;
if ( ! ( V_1 -> V_12 [ V_514 ] & V_515 ) )
return;
if ( F_260 ( & V_1 -> V_151 , V_516 , V_471 , 3 ) == 3 )
F_34 ( L_90 ,
V_471 [ 0 ] , V_471 [ 1 ] , V_471 [ 2 ] ) ;
if ( F_260 ( & V_1 -> V_151 , V_517 , V_471 , 3 ) == 3 )
F_34 ( L_91 ,
V_471 [ 0 ] , V_471 [ 1 ] , V_471 [ 2 ] ) ;
}
static bool
F_309 ( struct V_1 * V_1 )
{
T_1 V_471 [ 1 ] ;
if ( ! V_1 -> V_518 )
return false ;
if ( V_1 -> V_12 [ V_329 ] < 0x12 )
return false ;
if ( F_260 ( & V_1 -> V_151 , V_519 , V_471 , 1 ) ) {
if ( V_471 [ 0 ] & V_520 ) {
F_34 ( L_92 ) ;
V_1 -> V_521 = true ;
} else {
F_34 ( L_93 ) ;
V_1 -> V_521 = false ;
}
}
F_310 ( & V_1 -> V_522 , V_1 -> V_521 ) ;
return V_1 -> V_521 ;
}
static int F_311 ( struct V_1 * V_1 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_250 * V_250 = F_138 ( V_277 -> V_4 . V_4 . V_251 ) ;
T_1 V_471 ;
int V_134 = 0 ;
if ( F_312 ( & V_1 -> V_151 , V_523 , & V_471 ) < 0 ) {
F_34 ( L_94 ) ;
V_134 = - V_146 ;
goto V_141;
}
if ( F_187 ( & V_1 -> V_151 , V_523 ,
V_471 & ~ V_524 ) < 0 ) {
F_34 ( L_94 ) ;
V_134 = - V_146 ;
goto V_141;
}
V_1 -> V_525 . V_526 = false ;
V_141:
F_313 ( V_250 ) ;
return V_134 ;
}
static int F_314 ( struct V_1 * V_1 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_250 * V_250 = F_138 ( V_277 -> V_4 . V_4 . V_251 ) ;
T_1 V_471 ;
int V_134 ;
if ( V_1 -> V_525 . V_526 ) {
V_134 = F_311 ( V_1 ) ;
if ( V_134 )
return V_134 ;
}
if ( F_312 ( & V_1 -> V_151 , V_527 , & V_471 ) < 0 )
return - V_146 ;
if ( ! ( V_471 & V_528 ) )
return - V_529 ;
V_1 -> V_525 . V_530 = V_471 & V_531 ;
if ( F_312 ( & V_1 -> V_151 , V_523 , & V_471 ) < 0 )
return - V_146 ;
F_315 ( V_250 ) ;
if ( F_187 ( & V_1 -> V_151 , V_523 ,
V_471 | V_524 ) < 0 ) {
F_313 ( V_250 ) ;
return - V_146 ;
}
V_1 -> V_525 . V_526 = true ;
return 0 ;
}
int F_316 ( struct V_1 * V_1 , T_1 * V_532 )
{
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_277 -> V_4 . V_4 . V_7 ;
struct V_250 * V_250 = F_138 ( V_277 -> V_4 . V_4 . V_251 ) ;
T_1 V_471 ;
int V_226 , V_134 ;
int V_533 = 6 ;
bool V_534 ;
V_134 = F_314 ( V_1 ) ;
if ( V_134 )
return V_134 ;
do {
F_317 ( V_7 , V_250 -> V_59 ) ;
if ( F_312 ( & V_1 -> V_151 ,
V_527 , & V_471 ) < 0 ) {
V_134 = - V_146 ;
goto V_535;
}
V_226 = V_471 & V_531 ;
if ( V_226 == 0 )
V_1 -> V_525 . V_530 = 0 ;
if ( F_261 ( & V_1 -> V_151 , V_536 , V_532 , 6 ) < 0 ) {
V_134 = - V_146 ;
goto V_535;
}
V_534 = ( V_226 == V_1 -> V_525 . V_530 &&
! memcmp ( V_1 -> V_525 . V_537 , V_532 ,
6 * sizeof( T_1 ) ) ) ;
} while ( -- V_533 && ( V_226 == 0 || V_534 ) );
V_1 -> V_525 . V_530 = V_471 & V_531 ;
memcpy ( V_1 -> V_525 . V_537 , V_532 , 6 * sizeof( T_1 ) ) ;
if ( V_533 == 0 ) {
if ( V_534 ) {
F_34 ( L_95 ) ;
} else {
F_82 ( L_96 ) ;
V_134 = - V_147 ;
goto V_535;
}
}
V_535:
F_311 ( V_1 ) ;
return V_134 ;
}
static bool
F_318 ( struct V_1 * V_1 , T_1 * V_538 )
{
return F_260 ( & V_1 -> V_151 ,
V_539 ,
V_538 , 1 ) == 1 ;
}
static bool
F_319 ( struct V_1 * V_1 , T_1 * V_538 )
{
int V_134 ;
V_134 = F_260 ( & V_1 -> V_151 ,
V_540 ,
V_538 , 14 ) ;
if ( V_134 != 14 )
return false ;
return true ;
}
static T_3 F_320 ( struct V_1 * V_1 )
{
T_3 V_541 = V_542 ;
return V_541 ;
}
static T_3 F_321 ( struct V_1 * V_1 )
{
T_3 V_541 = V_543 ;
return V_541 ;
}
static T_3 F_322 ( struct V_1 * V_1 )
{
T_3 V_541 = V_543 ;
struct V_30 * V_30 = V_1 -> V_252 ;
struct V_8 * V_9 = & V_30 -> V_4 ;
if ( V_30 -> V_544 == NULL ||
V_9 -> V_545 ||
V_1 -> V_151 . V_546 > 6 ) {
if ( V_1 -> V_151 . V_547 > 0 ||
V_1 -> V_151 . V_546 > 0 )
F_34 ( L_97 ,
V_1 -> V_151 . V_547 ,
V_1 -> V_151 . V_546 ) ;
V_1 -> V_548 = V_549 ;
} else {
struct V_550 * V_551 = V_30 -> V_544 ;
V_551 += V_30 -> V_544 -> V_552 ;
if ( ! F_290 ( & V_1 -> V_151 ,
V_553 ,
& V_551 -> V_554 ,
1 ) )
F_34 ( L_98 ) ;
V_541 = V_542 | V_555 ;
V_1 -> V_548 = V_556 ;
}
V_1 -> V_557 = 1 ;
return V_541 ;
}
static T_3 F_323 ( struct V_1 * V_1 )
{
T_3 V_541 = V_543 ;
return V_541 ;
}
static void F_324 ( struct V_1 * V_1 )
{
T_3 V_558 = V_543 ;
T_3 V_559 = 0 ;
int V_107 = 0 ;
V_1 -> V_557 = 0 ;
V_1 -> V_560 = 0 ;
V_1 -> V_548 = 0 ;
V_1 -> V_151 . V_547 = 0 ;
V_1 -> V_151 . V_546 = 0 ;
V_107 = F_261 ( & V_1 -> V_151 , V_561 , & V_559 , 1 ) ;
if ( V_107 <= 0 ) {
F_34 ( L_99 ) ;
goto V_562;
}
switch ( V_559 ) {
case V_563 :
F_34 ( L_100 ) ;
V_1 -> V_560 = V_563 ;
V_558 = F_320 ( V_1 ) ;
break;
case V_564 :
F_34 ( L_101 ) ;
V_1 -> V_560 = V_564 ;
V_558 = F_321 ( V_1 ) ;
break;
case V_565 :
F_34 ( L_102 ) ;
V_1 -> V_560 = V_565 ;
V_558 = F_322 ( V_1 ) ;
break;
case V_566 :
F_34 ( L_103 ) ;
V_1 -> V_560 = V_566 ;
V_558 = F_323 ( V_1 ) ;
break;
default:
F_34 ( L_104 , V_559 ) ;
break;
}
V_562:
V_107 = F_290 ( & V_1 -> V_151 ,
V_567 ,
& V_558 , 1 ) ;
if ( V_107 <= 0 )
F_34 ( L_105 ) ;
}
static int
F_325 ( struct V_1 * V_1 )
{
bool V_568 ;
if ( V_1 -> V_521 ) {
T_1 V_569 [ 16 ] = { 0 } ;
int V_134 = 0 ;
int V_570 ;
bool V_571 ;
V_568 = F_319 ( V_1 , V_569 ) ;
V_572:
if ( V_568 == true ) {
if ( V_1 -> V_573 &&
! F_303 ( & V_569 [ 10 ] , V_1 -> V_10 ) ) {
F_34 ( L_106 ) ;
F_224 ( V_1 ) ;
F_225 ( V_1 ) ;
}
F_34 ( L_107 , V_569 ) ;
V_134 = F_326 ( & V_1 -> V_522 , V_569 , & V_571 ) ;
if ( V_571 ) {
for ( V_570 = 0 ; V_570 < 3 ; V_570 ++ ) {
int V_574 ;
V_574 = F_290 ( & V_1 -> V_151 ,
V_540 + 1 ,
& V_569 [ 1 ] , 3 ) ;
if ( V_574 == 3 ) {
break;
}
}
V_568 = F_319 ( V_1 , V_569 ) ;
if ( V_568 == true ) {
F_34 ( L_108 , V_569 ) ;
goto V_572;
}
} else
V_134 = 0 ;
return V_134 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_34 ( L_109 ) ;
V_1 -> V_521 = false ;
F_310 ( & V_1 -> V_522 , V_1 -> V_521 ) ;
F_327 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_171 ;
}
static void
F_328 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_51 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_538 ;
T_1 V_401 [ V_402 ] ;
F_46 ( ! F_329 ( & V_7 -> V_575 . V_576 ) ) ;
if ( ! V_51 -> V_4 . V_251 )
return;
if ( ! F_138 ( V_51 -> V_4 . V_251 ) -> V_577 )
return;
if ( ! F_262 ( V_1 , V_401 ) ) {
return;
}
if ( ! F_305 ( V_1 ) ) {
return;
}
if ( V_1 -> V_12 [ V_329 ] >= 0x11 &&
F_318 ( V_1 , & V_538 ) ) {
F_187 ( & V_1 -> V_151 ,
V_539 ,
V_538 ) ;
if ( V_538 & V_578 )
F_226 ( L_110 ) ;
if ( V_538 & ( V_579 | V_580 ) )
F_226 ( L_111 ) ;
}
if ( ! F_303 ( V_401 , V_1 -> V_10 ) ) {
F_34 ( L_112 ,
V_51 -> V_4 . V_176 ) ;
F_224 ( V_1 ) ;
F_225 ( V_1 ) ;
}
}
static enum V_581
F_330 ( struct V_1 * V_1 )
{
T_3 * V_12 = V_1 -> V_12 ;
T_3 type ;
if ( ! F_305 ( V_1 ) )
return V_582 ;
if ( ! ( V_12 [ V_509 ] & V_510 ) )
return V_583 ;
if ( V_1 -> V_12 [ V_329 ] >= 0x11 &&
V_1 -> V_512 [ 0 ] & V_584 ) {
T_3 V_585 ;
if ( F_260 ( & V_1 -> V_151 , V_586 ,
& V_585 , 1 ) < 0 )
return V_587 ;
return F_331 ( V_585 ) ? V_583
: V_582 ;
}
if ( F_332 ( & V_1 -> V_151 . V_196 ) )
return V_583 ;
if ( V_1 -> V_12 [ V_329 ] >= 0x11 ) {
type = V_1 -> V_512 [ 0 ] & V_588 ;
if ( type == V_589 ||
type == V_590 )
return V_587 ;
} else {
type = V_1 -> V_12 [ V_509 ] &
V_591 ;
if ( type == V_592 ||
type == V_593 )
return V_587 ;
}
F_34 ( L_113 ) ;
return V_582 ;
}
static enum V_581
F_333 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_581 V_107 ;
V_107 = F_334 ( V_7 ) ;
if ( V_107 == V_587 )
V_107 = V_583 ;
return V_107 ;
}
static bool F_335 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_594 ;
switch ( V_19 -> V_19 ) {
case V_20 :
return true ;
case V_187 :
V_594 = V_595 ;
break;
case V_189 :
V_594 = V_596 ;
break;
case V_191 :
V_594 = V_597 ;
break;
default:
F_336 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_598 ) & V_594 ;
}
static bool F_337 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_594 ;
switch ( V_19 -> V_19 ) {
case V_20 :
return true ;
case V_187 :
V_594 = V_599 ;
break;
case V_189 :
V_594 = V_600 ;
break;
case V_191 :
V_594 = V_601 ;
break;
case V_178 :
V_594 = V_602 ;
break;
default:
F_336 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_598 ) & V_594 ;
}
static bool F_338 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_594 ;
switch ( V_19 -> V_19 ) {
case V_187 :
V_594 = V_603 ;
break;
case V_189 :
V_594 = V_604 ;
break;
case V_191 :
V_594 = V_605 ;
break;
default:
F_336 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_606 ) & V_594 ;
}
static bool F_339 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_594 ;
switch ( V_19 -> V_19 ) {
case V_187 :
V_594 = V_607 ;
break;
case V_189 :
V_594 = V_608 ;
break;
case V_191 :
V_594 = V_609 ;
break;
default:
F_336 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_606 ) & V_594 ;
}
static bool F_340 ( struct V_53 * V_54 ,
struct V_2 * V_3 )
{
struct V_51 * V_51 = & V_3 -> V_4 ;
enum V_19 V_19 ;
T_5 V_594 ;
F_341 ( V_51 -> V_610 , & V_19 ) ;
switch ( V_19 ) {
case V_20 :
V_594 = V_611 ;
break;
case V_187 :
V_594 = V_612 ;
break;
case V_189 :
V_594 = V_613 ;
break;
default:
F_336 ( V_19 ) ;
return false ;
}
return F_31 ( V_614 ) & V_594 ;
}
bool F_342 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
if ( F_304 ( V_54 ) )
return F_335 ( V_54 , V_19 ) ;
if ( F_66 ( V_54 ) )
return F_337 ( V_54 , V_19 ) ;
else if ( F_64 ( V_54 ) )
return F_340 ( V_54 , V_19 ) ;
else if ( F_62 ( V_54 ) )
return F_339 ( V_54 , V_19 ) ;
else
return F_338 ( V_54 , V_19 ) ;
}
static enum V_581
F_343 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_342 ( V_54 , V_3 ) )
return V_582 ;
return F_330 ( V_1 ) ;
}
static enum V_581
F_344 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
enum V_581 V_107 ;
V_107 = F_334 ( V_7 ) ;
if ( V_107 == V_587 )
V_107 = V_583 ;
return V_107 ;
}
if ( ! F_342 ( V_7 -> V_55 , V_3 ) )
return V_582 ;
return F_330 ( V_1 ) ;
}
static struct V_550 *
F_345 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_252 ;
if ( V_30 -> V_550 ) {
if ( F_346 ( V_30 -> V_550 ) )
return NULL ;
return F_347 ( V_30 -> V_550 ) ;
} else
return F_348 ( & V_30 -> V_4 ,
& V_1 -> V_151 . V_196 ) ;
}
static void
F_349 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_252 ;
struct V_550 * V_550 ;
V_550 = F_345 ( V_1 ) ;
V_30 -> V_544 = V_550 ;
if ( V_1 -> V_615 != V_616 )
V_1 -> V_262 = V_1 -> V_615 == V_617 ;
else
V_1 -> V_262 = F_350 ( V_550 ) ;
}
static void
F_351 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_252 ;
F_352 ( V_30 -> V_544 ) ;
V_30 -> V_544 = NULL ;
V_1 -> V_262 = false ;
}
static enum V_581
F_353 ( struct V_8 * V_9 , bool V_618 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_581 V_107 ;
enum V_56 V_57 ;
bool V_134 ;
T_1 V_538 ;
F_34 ( L_114 ,
V_9 -> V_4 . V_619 , V_9 -> V_176 ) ;
F_351 ( V_1 ) ;
if ( V_1 -> V_521 ) {
if ( V_51 -> type != V_5 )
V_51 -> type = V_620 ;
return V_582 ;
}
V_57 = F_22 ( V_51 ) ;
F_23 ( F_208 ( V_7 ) , V_57 ) ;
if ( F_1 ( V_1 ) )
V_107 = F_333 ( V_1 ) ;
else if ( F_66 ( V_7 ) )
V_107 = F_343 ( V_1 ) ;
else
V_107 = F_344 ( V_1 ) ;
if ( V_107 != V_583 )
goto V_141;
F_308 ( V_1 ) ;
V_134 = F_309 ( V_1 ) ;
if ( V_134 ) {
if ( V_51 -> type != V_5 )
V_51 -> type = V_620 ;
V_107 = V_582 ;
goto V_141;
}
F_349 ( V_1 ) ;
if ( V_51 -> type != V_5 )
V_51 -> type = V_620 ;
V_107 = V_583 ;
if ( V_1 -> V_12 [ V_329 ] >= 0x11 &&
F_318 ( V_1 , & V_538 ) ) {
F_187 ( & V_1 -> V_151 ,
V_539 ,
V_538 ) ;
if ( V_538 & V_578 )
F_324 ( V_1 ) ;
if ( V_538 & ( V_579 | V_580 ) )
F_226 ( L_111 ) ;
}
V_141:
F_27 ( F_208 ( V_7 ) , V_57 ) ;
return V_107 ;
}
static void
F_354 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_51 * V_51 = & F_2 ( V_1 ) -> V_4 ;
struct V_53 * V_54 = F_208 ( V_51 -> V_4 . V_7 ) ;
enum V_56 V_57 ;
F_34 ( L_114 ,
V_9 -> V_4 . V_619 , V_9 -> V_176 ) ;
F_351 ( V_1 ) ;
if ( V_9 -> V_107 != V_583 )
return;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
F_349 ( V_1 ) ;
F_27 ( V_54 , V_57 ) ;
if ( V_51 -> type != V_5 )
V_51 -> type = V_620 ;
}
static int F_355 ( struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
struct V_550 * V_550 ;
V_550 = V_30 -> V_544 ;
if ( V_550 ) {
int V_134 = F_356 ( V_9 , V_550 ) ;
if ( V_134 )
return V_134 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_30 -> V_32 . V_31 ) {
struct V_28 * V_29 ;
V_29 = F_357 ( V_9 -> V_7 ,
V_30 -> V_32 . V_31 ) ;
if ( V_29 ) {
F_358 ( V_9 , V_29 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_359 ( struct V_8 * V_9 )
{
bool V_262 = false ;
struct V_550 * V_550 ;
V_550 = F_17 ( V_9 ) -> V_544 ;
if ( V_550 )
V_262 = F_350 ( V_550 ) ;
return V_262 ;
}
static int
F_360 ( struct V_8 * V_9 ,
struct V_621 * V_622 ,
T_9 V_344 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_30 * V_30 = F_17 ( V_9 ) ;
struct V_51 * V_51 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_51 -> V_4 ) ;
int V_134 ;
V_134 = F_361 ( & V_9 -> V_4 , V_622 , V_344 ) ;
if ( V_134 )
return V_134 ;
if ( V_622 == V_54 -> V_623 ) {
int V_47 = V_344 ;
bool V_262 ;
if ( V_47 == V_1 -> V_615 )
return 0 ;
V_1 -> V_615 = V_47 ;
if ( V_47 == V_616 )
V_262 = F_359 ( V_9 ) ;
else
V_262 = ( V_47 == V_617 ) ;
if ( V_262 == V_1 -> V_262 )
return 0 ;
V_1 -> V_262 = V_262 ;
goto V_108;
}
if ( V_622 == V_54 -> V_624 ) {
bool V_625 = V_1 -> V_270 ;
bool V_626 = V_1 -> V_271 ;
switch ( V_344 ) {
case V_627 :
V_1 -> V_270 = true ;
break;
case V_628 :
V_1 -> V_270 = false ;
V_1 -> V_271 = false ;
break;
case V_629 :
V_1 -> V_270 = false ;
V_1 -> V_271 = true ;
break;
default:
return - V_171 ;
}
if ( V_625 == V_1 -> V_270 &&
V_626 == V_1 -> V_271 )
return 0 ;
goto V_108;
}
if ( F_1 ( V_1 ) &&
V_622 == V_9 -> V_7 -> V_575 . V_630 ) {
if ( V_344 == V_631 ) {
F_34 ( L_115 ) ;
return - V_171 ;
}
if ( V_30 -> V_32 . V_263 == V_344 ) {
return 0 ;
}
V_30 -> V_32 . V_263 = V_344 ;
goto V_108;
}
return - V_171 ;
V_108:
if ( V_51 -> V_4 . V_251 )
F_362 ( V_51 -> V_4 . V_251 ) ;
return 0 ;
}
static void
F_363 ( struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
F_352 ( V_30 -> V_544 ) ;
if ( ! F_364 ( V_30 -> V_550 ) )
F_352 ( V_30 -> V_550 ) ;
if ( V_9 -> V_632 == V_633 )
F_365 ( & V_30 -> V_32 ) ;
F_366 ( V_9 ) ;
F_352 ( V_9 ) ;
}
void F_367 ( struct V_477 * V_52 )
{
struct V_2 * V_3 = F_210 ( V_52 ) ;
struct V_1 * V_1 = & V_3 -> V_634 ;
F_112 ( & V_1 -> V_151 ) ;
F_368 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_369 ( & V_1 -> V_315 ) ;
F_21 ( V_1 ) ;
F_165 ( V_1 ) ;
F_25 ( V_1 ) ;
if ( V_1 -> V_95 . V_635 ) {
F_370 ( & V_1 -> V_95 ) ;
V_1 -> V_95 . V_635 = NULL ;
}
}
F_371 ( V_52 ) ;
F_352 ( V_3 ) ;
}
static void F_372 ( struct V_51 * V_51 )
{
struct V_1 * V_1 = F_5 ( & V_51 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_369 ( & V_1 -> V_315 ) ;
F_21 ( V_1 ) ;
F_165 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_373 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_75 ( V_1 ) )
return;
F_34 ( L_116 ) ;
V_57 = F_22 ( & V_3 -> V_4 ) ;
F_23 ( V_54 , V_57 ) ;
F_168 ( V_1 ) ;
}
static void F_374 ( struct V_477 * V_52 )
{
struct V_1 * V_1 ;
if ( F_375 ( V_52 ) -> type != V_5 )
return;
V_1 = F_5 ( V_52 ) ;
F_21 ( V_1 ) ;
if ( F_62 ( V_52 -> V_7 ) )
F_60 ( V_1 ) ;
F_373 ( V_1 ) ;
F_25 ( V_1 ) ;
}
enum V_636
F_376 ( struct V_2 * V_3 , bool V_637 )
{
struct V_1 * V_1 = & V_3 -> V_634 ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
enum V_636 V_134 = V_638 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_639 )
V_3 -> V_4 . type = V_620 ;
if ( V_637 && V_3 -> V_4 . type == V_5 ) {
F_34 ( L_117 ,
F_33 ( V_3 -> V_19 ) ) ;
return V_640 ;
}
F_34 ( L_118 ,
F_33 ( V_3 -> V_19 ) ,
V_637 ? L_119 : L_120 ) ;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
if ( V_637 ) {
V_1 -> V_473 = false ;
if ( ! F_342 ( V_54 , V_3 ) )
goto V_641;
if ( ! F_305 ( V_1 ) ) {
goto V_641;
}
F_308 ( V_1 ) ;
if ( ! F_309 ( V_1 ) ) {
F_377 ( & V_7 -> V_575 . V_576 , NULL ) ;
F_328 ( V_1 ) ;
F_378 ( & V_7 -> V_575 . V_576 ) ;
goto V_641;
}
} else {
if ( V_1 -> V_521 ) {
if ( F_325 ( V_1 ) == - V_171 )
goto V_641;
}
if ( ! V_1 -> V_521 ) {
F_377 ( & V_7 -> V_575 . V_576 , NULL ) ;
F_328 ( V_1 ) ;
F_378 ( & V_7 -> V_575 . V_576 ) ;
}
}
V_134 = V_640 ;
goto V_642;
V_641:
if ( V_1 -> V_521 ) {
F_34 ( L_121 , V_1 -> V_521 , V_1 -> V_522 . V_643 ) ;
V_1 -> V_521 = false ;
F_310 ( & V_1 -> V_522 , V_1 -> V_521 ) ;
}
V_642:
F_27 ( V_54 , V_57 ) ;
return V_134 ;
}
int
F_379 ( struct V_327 * V_251 )
{
struct V_6 * V_7 = V_251 -> V_7 ;
struct V_51 * V_51 ;
struct V_1 * V_1 ;
F_380 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_51 -> V_4 ) ;
if ( V_51 -> type == V_620 ||
V_51 -> type == V_5 )
return V_1 -> V_68 ;
}
return - 1 ;
}
bool F_381 ( struct V_6 * V_7 , enum V_19 V_19 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_644 * V_645 ;
int V_47 ;
static const short V_646 [] = {
[ V_187 ] = V_647 ,
[ V_189 ] = V_648 ,
[ V_191 ] = V_649 ,
[ V_178 ] = V_650 ,
} ;
if ( F_124 ( V_7 ) -> V_220 < 5 )
return false ;
if ( V_19 == V_20 )
return true ;
if ( ! V_54 -> V_174 . V_651 )
return false ;
for ( V_47 = 0 ; V_47 < V_54 -> V_174 . V_651 ; V_47 ++ ) {
V_645 = V_54 -> V_174 . V_652 + V_47 ;
if ( V_645 -> V_653 . V_654 == V_646 [ V_19 ] &&
( V_645 -> V_653 . V_655 & V_656 ) ==
( V_657 & V_656 ) )
return true ;
}
return false ;
}
void
F_382 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
F_383 ( V_9 ) ;
F_384 ( V_9 ) ;
V_1 -> V_270 = true ;
if ( F_1 ( V_1 ) ) {
F_385 ( V_9 -> V_7 ) ;
F_386 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_575 . V_630 ,
V_658 ) ;
V_30 -> V_32 . V_263 = V_658 ;
}
}
static void F_387 ( struct V_1 * V_1 )
{
V_1 -> V_303 = V_318 ;
V_1 -> V_306 = V_318 ;
V_1 -> V_308 = V_318 ;
}
static void
F_50 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_659 V_660 , V_174 , V_661 ,
* V_662 = & V_1 -> V_663 ;
T_5 V_664 , V_665 , V_99 = 0 , V_666 = 0 ;
int V_97 , V_374 , V_667 , V_98 = 0 ;
F_45 ( & V_54 -> V_58 ) ;
if ( V_662 -> V_668 != 0 )
return;
if ( F_64 ( V_7 ) ) {
V_97 = F_65 ( 0 ) ;
V_374 = F_388 ( 0 ) ;
V_667 = F_389 ( 0 ) ;
} else if ( F_66 ( V_7 ) ) {
V_97 = V_89 ;
V_374 = V_669 ;
V_667 = V_670 ;
V_98 = V_671 ;
} else {
enum V_59 V_59 = F_44 ( V_1 ) ;
V_97 = F_55 ( V_59 ) ;
V_374 = F_58 ( V_59 ) ;
V_667 = F_390 ( V_59 ) ;
V_98 = F_72 ( V_59 ) ;
}
V_666 = F_161 ( V_1 ) ;
V_664 = F_31 ( V_374 ) ;
V_665 = F_31 ( V_667 ) ;
if ( ! F_64 ( V_7 ) ) {
F_41 ( V_97 , V_666 ) ;
V_99 = F_31 ( V_98 ) ;
}
V_660 . V_672 = ( V_664 & V_673 ) >>
V_674 ;
V_660 . V_675 = ( V_664 & V_676 ) >>
V_677 ;
V_660 . V_678 = ( V_665 & V_679 ) >>
V_680 ;
V_660 . V_681 = ( V_665 & V_682 ) >>
V_683 ;
if ( F_64 ( V_7 ) ) {
T_10 V_83 = ( V_666 & V_684 ) >>
V_685 ;
if ( V_83 > 0 )
V_660 . V_668 = ( V_83 - 1 ) * 1000 ;
else
V_660 . V_668 = 0 ;
} else {
V_660 . V_668 = ( ( V_99 & V_686 ) >>
V_687 ) * 1000 ;
}
F_34 ( L_122 ,
V_660 . V_672 , V_660 . V_675 , V_660 . V_678 , V_660 . V_681 , V_660 . V_668 ) ;
V_174 = V_54 -> V_174 . V_688 ;
V_661 . V_672 = 210 * 10 ;
V_661 . V_675 = 50 * 10 ;
V_661 . V_678 = 50 * 10 ;
V_661 . V_681 = 500 * 10 ;
V_661 . V_668 = ( 510 + 100 ) * 10 ;
F_34 ( L_123 ,
V_174 . V_672 , V_174 . V_675 , V_174 . V_678 , V_174 . V_681 , V_174 . V_668 ) ;
#define F_391 ( T_11 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_391 ( V_672 ) ;
F_391 ( V_675 ) ;
F_391 ( V_678 ) ;
F_391 ( V_681 ) ;
F_391 ( V_668 ) ;
#undef F_391
#define F_392 ( T_11 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_316 = F_392 ( V_672 ) ;
V_1 -> V_307 = F_392 ( V_675 ) ;
V_1 -> V_309 = F_392 ( V_678 ) ;
V_1 -> V_493 = F_392 ( V_681 ) ;
V_1 -> V_103 = F_392 ( V_668 ) ;
#undef F_392
F_34 ( L_124 ,
V_1 -> V_316 , V_1 -> V_493 ,
V_1 -> V_103 ) ;
F_34 ( L_125 ,
V_1 -> V_307 , V_1 -> V_309 ) ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_664 , V_665 , V_99 , V_87 = 0 ;
int div = F_66 ( V_7 ) ? F_87 ( V_7 ) : F_84 ( V_7 ) ;
int V_374 , V_667 , V_98 = 0 , V_97 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
const struct V_659 * V_689 = & V_1 -> V_663 ;
F_45 ( & V_54 -> V_58 ) ;
if ( F_64 ( V_7 ) ) {
V_97 = F_65 ( 0 ) ;
V_374 = F_388 ( 0 ) ;
V_667 = F_389 ( 0 ) ;
} else if ( F_66 ( V_7 ) ) {
V_374 = V_669 ;
V_667 = V_670 ;
V_98 = V_671 ;
} else {
enum V_59 V_59 = F_44 ( V_1 ) ;
V_374 = F_58 ( V_59 ) ;
V_667 = F_390 ( V_59 ) ;
V_98 = F_72 ( V_59 ) ;
}
V_664 = ( V_689 -> V_672 << V_674 ) |
( 1 << V_677 ) ;
V_665 = ( 1 << V_680 ) |
( V_689 -> V_681 << V_683 ) ;
if ( F_64 ( V_7 ) ) {
V_99 = F_31 ( V_97 ) ;
V_99 &= ~ V_684 ;
V_99 |= ( F_86 ( ( V_689 -> V_668 + 1 ) , 1000 )
<< V_685 ) ;
} else {
V_99 = ( ( 100 * div ) / 2 - 1 ) << V_690 ;
V_99 |= ( F_86 ( V_689 -> V_668 , 1000 )
<< V_687 ) ;
}
if ( F_62 ( V_7 ) ) {
V_87 = F_59 ( V_19 ) ;
} else if ( F_304 ( V_7 ) || F_151 ( V_7 ) ) {
if ( V_19 == V_20 )
V_87 = V_691 ;
else
V_87 = V_692 ;
}
V_664 |= V_87 ;
F_41 ( V_374 , V_664 ) ;
F_41 ( V_667 , V_665 ) ;
if ( F_64 ( V_7 ) )
F_41 ( V_97 , V_99 ) ;
else
F_41 ( V_98 , V_99 ) ;
F_34 ( L_126 ,
F_31 ( V_374 ) ,
F_31 ( V_667 ) ,
F_64 ( V_7 ) ?
( F_31 ( V_97 ) & V_684 ) :
F_31 ( V_98 ) ) ;
}
static void F_393 ( struct V_6 * V_7 , int V_693 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_51 * V_52 ;
struct V_2 * V_277 = NULL ;
struct V_1 * V_1 = V_54 -> V_274 . V_634 ;
struct V_198 * V_279 = NULL ;
struct V_250 * V_250 = NULL ;
enum V_694 V_110 = V_695 ;
if ( V_693 <= 0 ) {
F_34 ( L_127 ) ;
return;
}
if ( V_1 == NULL ) {
F_34 ( L_128 ) ;
return;
}
V_277 = F_2 ( V_1 ) ;
V_52 = & V_277 -> V_4 ;
V_250 = F_138 ( V_52 -> V_4 . V_251 ) ;
if ( ! V_250 ) {
F_34 ( L_129 ) ;
return;
}
V_279 = V_250 -> V_279 ;
if ( V_54 -> V_274 . type < V_275 ) {
F_34 ( L_130 ) ;
return;
}
if ( V_1 -> V_252 -> V_32 . V_273 -> V_696 ==
V_693 )
V_110 = V_697 ;
if ( V_110 == V_54 -> V_274 . V_698 ) {
F_34 (
L_131 ) ;
return;
}
if ( ! V_250 -> V_577 ) {
F_34 ( L_132 ) ;
return;
}
if ( F_124 ( V_7 ) -> V_220 >= 8 && ! F_36 ( V_7 ) ) {
switch ( V_110 ) {
case V_695 :
F_394 ( V_250 , V_699 ) ;
break;
case V_697 :
F_394 ( V_250 , V_700 ) ;
break;
case V_701 :
default:
F_82 ( L_133 ) ;
}
} else if ( F_124 ( V_7 ) -> V_220 > 6 ) {
T_5 V_585 = F_395 ( V_250 -> V_279 -> V_702 ) ;
T_5 V_344 ;
V_344 = F_31 ( V_585 ) ;
if ( V_110 > V_695 ) {
if ( F_62 ( V_7 ) )
V_344 |= V_703 ;
else
V_344 |= V_704 ;
} else {
if ( F_62 ( V_7 ) )
V_344 &= ~ V_703 ;
else
V_344 &= ~ V_704 ;
}
F_41 ( V_585 , V_344 ) ;
}
V_54 -> V_274 . V_698 = V_110 ;
F_34 ( L_134 , V_693 ) ;
}
void F_396 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_327 * V_251 = V_277 -> V_4 . V_4 . V_251 ;
struct V_250 * V_250 = F_138 ( V_251 ) ;
if ( ! V_250 -> V_279 -> V_261 ) {
F_34 ( L_135 ) ;
return;
}
F_24 ( & V_54 -> V_274 . V_705 ) ;
if ( F_46 ( V_54 -> V_274 . V_634 ) ) {
F_82 ( L_136 ) ;
goto V_706;
}
V_54 -> V_274 . V_707 = 0 ;
V_54 -> V_274 . V_634 = V_1 ;
V_706:
F_26 ( & V_54 -> V_274 . V_705 ) ;
}
void F_397 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_277 = F_2 ( V_1 ) ;
struct V_327 * V_251 = V_277 -> V_4 . V_4 . V_251 ;
struct V_250 * V_250 = F_138 ( V_251 ) ;
if ( ! V_250 -> V_279 -> V_261 )
return;
F_24 ( & V_54 -> V_274 . V_705 ) ;
if ( ! V_54 -> V_274 . V_634 ) {
F_26 ( & V_54 -> V_274 . V_705 ) ;
return;
}
if ( V_54 -> V_274 . V_698 == V_697 )
F_393 ( V_54 -> V_7 ,
V_1 -> V_252 -> V_32 .
V_31 -> V_696 ) ;
V_54 -> V_274 . V_634 = NULL ;
F_26 ( & V_54 -> V_274 . V_705 ) ;
F_369 ( & V_54 -> V_274 . V_708 ) ;
}
static void F_398 ( struct V_319 * V_708 )
{
struct V_53 * V_54 =
F_70 ( V_708 , F_71 ( * V_54 ) , V_274 . V_708 . V_708 ) ;
struct V_1 * V_1 ;
F_24 ( & V_54 -> V_274 . V_705 ) ;
V_1 = V_54 -> V_274 . V_634 ;
if ( ! V_1 )
goto V_706;
if ( V_54 -> V_274 . V_707 )
goto V_706;
if ( V_54 -> V_274 . V_698 != V_697 )
F_393 ( V_54 -> V_7 ,
V_1 -> V_252 -> V_32 .
V_273 -> V_696 ) ;
V_706:
F_26 ( & V_54 -> V_274 . V_705 ) ;
}
void F_399 ( struct V_6 * V_7 ,
unsigned V_709 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_327 * V_251 ;
enum V_59 V_59 ;
if ( V_54 -> V_274 . type == V_710 )
return;
F_162 ( & V_54 -> V_274 . V_708 ) ;
F_24 ( & V_54 -> V_274 . V_705 ) ;
if ( ! V_54 -> V_274 . V_634 ) {
F_26 ( & V_54 -> V_274 . V_705 ) ;
return;
}
V_251 = F_2 ( V_54 -> V_274 . V_634 ) -> V_4 . V_4 . V_251 ;
V_59 = F_138 ( V_251 ) -> V_59 ;
V_709 &= F_400 ( V_59 ) ;
V_54 -> V_274 . V_707 |= V_709 ;
if ( V_709 && V_54 -> V_274 . V_698 == V_697 )
F_393 ( V_54 -> V_7 ,
V_54 -> V_274 . V_634 -> V_252 -> V_32 .
V_31 -> V_696 ) ;
F_26 ( & V_54 -> V_274 . V_705 ) ;
}
void F_401 ( struct V_6 * V_7 ,
unsigned V_709 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_327 * V_251 ;
enum V_59 V_59 ;
if ( V_54 -> V_274 . type == V_710 )
return;
F_162 ( & V_54 -> V_274 . V_708 ) ;
F_24 ( & V_54 -> V_274 . V_705 ) ;
if ( ! V_54 -> V_274 . V_634 ) {
F_26 ( & V_54 -> V_274 . V_705 ) ;
return;
}
V_251 = F_2 ( V_54 -> V_274 . V_634 ) -> V_4 . V_4 . V_251 ;
V_59 = F_138 ( V_251 ) -> V_59 ;
V_709 &= F_400 ( V_59 ) ;
V_54 -> V_274 . V_707 &= ~ V_709 ;
if ( V_709 && V_54 -> V_274 . V_698 == V_697 )
F_393 ( V_54 -> V_7 ,
V_54 -> V_274 . V_634 -> V_252 -> V_32 .
V_31 -> V_696 ) ;
if ( ! V_54 -> V_274 . V_707 )
F_170 ( & V_54 -> V_274 . V_708 ,
F_169 ( 1000 ) ) ;
F_26 ( & V_54 -> V_274 . V_705 ) ;
}
static struct V_28 *
F_402 ( struct V_30 * V_30 ,
struct V_28 * V_31 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_273 = NULL ;
F_403 ( & V_54 -> V_274 . V_708 , F_398 ) ;
F_404 ( & V_54 -> V_274 . V_705 ) ;
if ( F_124 ( V_7 ) -> V_220 <= 6 ) {
F_34 ( L_137 ) ;
return NULL ;
}
if ( V_54 -> V_174 . V_711 != V_275 ) {
F_34 ( L_138 ) ;
return NULL ;
}
V_273 = F_405
( V_7 , V_31 , V_9 ) ;
if ( ! V_273 ) {
F_34 ( L_139 ) ;
return NULL ;
}
V_54 -> V_274 . type = V_54 -> V_174 . V_711 ;
V_54 -> V_274 . V_698 = V_695 ;
F_34 ( L_140 ) ;
return V_273 ;
}
static bool F_406 ( struct V_1 * V_1 ,
struct V_30 * V_30 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_51 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_31 = NULL ;
struct V_28 * V_273 = NULL ;
bool V_712 ;
struct V_28 * V_713 ;
struct V_550 * V_550 ;
enum V_59 V_59 = V_82 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_21 ( V_1 ) ;
F_373 ( V_1 ) ;
F_25 ( V_1 ) ;
V_712 = F_305 ( V_1 ) ;
if ( V_712 ) {
if ( V_1 -> V_12 [ V_329 ] >= 0x11 )
V_54 -> V_714 =
V_1 -> V_12 [ V_715 ] &
V_716 ;
} else {
F_407 ( L_141 ) ;
return false ;
}
F_21 ( V_1 ) ;
F_51 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
F_24 ( & V_7 -> V_575 . V_705 ) ;
V_550 = F_348 ( V_9 , & V_1 -> V_151 . V_196 ) ;
if ( V_550 ) {
if ( F_408 ( V_9 , V_550 ) ) {
F_409 ( V_9 ,
V_550 ) ;
F_410 ( V_9 , V_550 ) ;
} else {
F_352 ( V_550 ) ;
V_550 = F_411 ( - V_171 ) ;
}
} else {
V_550 = F_411 ( - V_717 ) ;
}
V_30 -> V_550 = V_550 ;
F_47 (scan, &connector->probed_modes, head) {
if ( ( V_713 -> type & V_718 ) ) {
V_31 = F_357 ( V_7 , V_713 ) ;
V_273 = F_402 (
V_30 , V_31 ) ;
break;
}
}
if ( ! V_31 && V_54 -> V_174 . V_719 ) {
V_31 = F_357 ( V_7 ,
V_54 -> V_174 . V_719 ) ;
if ( V_31 )
V_31 -> type |= V_718 ;
}
F_26 ( & V_7 -> V_575 . V_705 ) ;
if ( F_62 ( V_7 ) ) {
V_1 -> V_95 . V_635 = F_69 ;
F_412 ( & V_1 -> V_95 ) ;
if ( F_36 ( V_7 ) )
V_59 = F_194 ( V_1 -> V_67 ) ;
else
V_59 = F_195 ( V_1 -> V_67 ) ;
if ( V_59 != V_81 && V_59 != V_74 )
V_59 = V_1 -> V_60 ;
if ( V_59 != V_81 && V_59 != V_74 )
V_59 = V_81 ;
F_34 ( L_142 ,
F_32 ( V_59 ) ) ;
}
F_413 ( & V_30 -> V_32 , V_31 , V_273 ) ;
V_30 -> V_32 . V_720 . V_721 = F_182 ;
F_414 ( V_9 , V_59 ) ;
return true ;
}
bool
F_415 ( struct V_2 * V_3 ,
struct V_30 * V_30 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_634 ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_51 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
int type ;
V_1 -> V_60 = V_82 ;
if ( F_124 ( V_7 ) -> V_220 >= 9 )
V_1 -> V_143 = F_91 ;
else if ( F_62 ( V_7 ) )
V_1 -> V_143 = F_90 ;
else if ( F_109 ( V_7 ) || F_94 ( V_7 ) )
V_1 -> V_143 = F_88 ;
else if ( F_66 ( V_7 ) )
V_1 -> V_143 = F_85 ;
else
V_1 -> V_143 = F_83 ;
if ( F_124 ( V_7 ) -> V_220 >= 9 )
V_1 -> V_145 = F_95 ;
else
V_1 -> V_145 = F_92 ;
V_1 -> V_67 = F_31 ( V_1 -> V_68 ) ;
V_1 -> V_252 = V_30 ;
if ( F_381 ( V_7 , V_19 ) )
type = V_633 ;
else
type = V_722 ;
if ( type == V_633 )
V_51 -> type = V_5 ;
if ( F_46 ( F_62 ( V_7 ) && F_1 ( V_1 ) &&
V_19 != V_187 && V_19 != V_189 ) )
return false ;
F_34 ( L_143 ,
type == V_633 ? L_144 : L_145 ,
F_33 ( V_19 ) ) ;
F_416 ( V_7 , V_9 , & V_723 , type ) ;
F_417 ( V_9 , & V_724 ) ;
V_9 -> V_725 = true ;
V_9 -> V_726 = 0 ;
F_403 ( & V_1 -> V_315 ,
F_166 ) ;
F_418 ( V_30 , V_51 ) ;
F_419 ( V_9 ) ;
if ( F_11 ( V_7 ) )
V_30 -> V_727 = V_728 ;
else
V_30 -> V_727 = V_729 ;
V_30 -> V_730 = F_113 ;
switch ( V_19 ) {
case V_20 :
V_51 -> V_610 = V_731 ;
break;
case V_187 :
V_51 -> V_610 = V_732 ;
if ( F_64 ( V_54 ) && ( F_122 ( V_7 ) < V_733 ) )
V_51 -> V_610 = V_731 ;
break;
case V_189 :
V_51 -> V_610 = V_734 ;
break;
case V_191 :
V_51 -> V_610 = V_735 ;
break;
case V_178 :
V_51 -> V_610 = V_736 ;
break;
default:
F_108 () ;
}
if ( F_1 ( V_1 ) ) {
F_21 ( V_1 ) ;
F_387 ( V_1 ) ;
if ( F_62 ( V_7 ) )
F_60 ( V_1 ) ;
else
F_50 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
}
F_106 ( V_1 , V_30 ) ;
if ( F_420 ( V_7 ) &&
( V_19 == V_187 || V_19 == V_189 || V_19 == V_191 ) )
F_421 ( V_3 ,
V_30 -> V_4 . V_4 . V_619 ) ;
if ( ! F_406 ( V_1 , V_30 ) ) {
F_112 ( & V_1 -> V_151 ) ;
if ( F_1 ( V_1 ) ) {
F_369 ( & V_1 -> V_315 ) ;
F_21 ( V_1 ) ;
F_165 ( V_1 ) ;
F_25 ( V_1 ) ;
}
F_422 ( V_9 ) ;
F_366 ( V_9 ) ;
return false ;
}
F_382 ( V_1 , V_9 ) ;
if ( F_128 ( V_7 ) && ! F_423 ( V_7 ) ) {
T_5 V_351 = F_31 ( V_737 ) ;
F_41 ( V_737 , ( V_351 & ~ 0xf ) | 0xd ) ;
}
F_424 ( V_9 ) ;
return true ;
}
void
F_425 ( struct V_6 * V_7 , int V_68 , enum V_19 V_19 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 ;
struct V_51 * V_51 ;
struct V_477 * V_52 ;
struct V_30 * V_30 ;
V_3 = F_426 ( sizeof( * V_3 ) , V_738 ) ;
if ( ! V_3 )
return;
V_30 = F_427 () ;
if ( ! V_30 )
goto V_739;
V_51 = & V_3 -> V_4 ;
V_52 = & V_51 -> V_4 ;
F_428 ( V_7 , & V_51 -> V_4 , & V_740 ,
V_741 ) ;
V_51 -> V_742 = F_137 ;
V_51 -> V_743 = F_200 ;
V_51 -> V_727 = F_188 ;
V_51 -> V_744 = F_196 ;
V_51 -> V_745 = F_372 ;
if ( F_36 ( V_7 ) ) {
V_51 -> V_746 = F_255 ;
V_51 -> V_747 = F_244 ;
V_51 -> V_325 = F_229 ;
V_51 -> V_748 = F_217 ;
V_51 -> V_749 = F_259 ;
} else if ( F_62 ( V_7 ) ) {
V_51 -> V_746 = F_238 ;
V_51 -> V_747 = F_233 ;
V_51 -> V_325 = F_229 ;
V_51 -> V_748 = F_206 ;
} else {
V_51 -> V_747 = F_231 ;
V_51 -> V_325 = F_228 ;
if ( F_124 ( V_7 ) -> V_220 >= 5 )
V_51 -> V_748 = F_205 ;
}
V_3 -> V_19 = V_19 ;
V_3 -> V_634 . V_68 = V_68 ;
V_51 -> type = V_620 ;
if ( F_36 ( V_7 ) ) {
if ( V_19 == V_191 )
V_51 -> V_750 = 1 << 2 ;
else
V_51 -> V_750 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_51 -> V_750 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_51 -> V_751 = 0 ;
V_3 -> V_752 = F_376 ;
V_54 -> V_753 . V_754 [ V_19 ] = V_3 ;
if ( ! F_415 ( V_3 , V_30 ) )
goto V_755;
return;
V_755:
F_371 ( V_52 ) ;
F_352 ( V_30 ) ;
V_739:
F_352 ( V_3 ) ;
return;
}
void F_429 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_756 ; V_47 ++ ) {
struct V_2 * V_3 = V_54 -> V_753 . V_754 [ V_47 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_620 ) {
if ( ! V_3 -> V_634 . V_518 )
continue;
if ( V_3 -> V_634 . V_521 )
F_430 ( & V_3 -> V_634 . V_522 ) ;
}
}
}
void F_431 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_756 ; V_47 ++ ) {
struct V_2 * V_3 = V_54 -> V_753 . V_754 [ V_47 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_620 ) {
int V_134 ;
if ( ! V_3 -> V_634 . V_518 )
continue;
V_134 = F_432 ( & V_3 -> V_634 . V_522 ) ;
if ( V_134 != 0 ) {
F_325 ( & V_3 -> V_634 ) ;
}
}
}
}
