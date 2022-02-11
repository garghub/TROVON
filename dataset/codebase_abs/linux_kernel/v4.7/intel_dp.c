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
T_1 V_17 , V_18 ;
V_17 = V_3 -> V_19 ;
V_18 = F_11 ( V_1 -> V_12 ) ;
return F_12 ( V_17 , V_18 ) ;
}
static int
F_13 ( int V_20 , int V_21 )
{
return ( V_20 * V_21 + 9 ) / 10 ;
}
static int
F_14 ( int V_22 , int V_19 )
{
return ( V_22 * V_19 * 8 ) / 10 ;
}
static enum V_23
F_15 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_26 * V_26 = F_16 ( V_9 ) ;
struct V_24 * V_27 = V_26 -> V_28 . V_27 ;
int V_29 = V_25 -> clock ;
int V_30 , V_31 , V_19 , V_22 ;
int V_32 = F_17 ( V_9 -> V_7 ) -> V_33 ;
if ( F_1 ( V_1 ) && V_27 ) {
if ( V_25 -> V_34 > V_27 -> V_34 )
return V_35 ;
if ( V_25 -> V_36 > V_27 -> V_36 )
return V_35 ;
V_29 = V_27 -> clock ;
}
V_22 = F_18 ( V_1 ) ;
V_19 = F_10 ( V_1 ) ;
V_30 = F_14 ( V_22 , V_19 ) ;
V_31 = F_13 ( V_29 , 18 ) ;
if ( V_31 > V_30 || V_29 > V_32 )
return V_37 ;
if ( V_25 -> clock < 10000 )
return V_38 ;
if ( V_25 -> V_39 & V_40 )
return V_41 ;
return V_42 ;
}
T_2 F_19 ( const T_3 * V_43 , int V_44 )
{
int V_45 ;
T_2 V_46 = 0 ;
if ( V_44 > 4 )
V_44 = 4 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ )
V_46 |= ( ( T_2 ) V_43 [ V_45 ] ) << ( ( 3 - V_45 ) * 8 ) ;
return V_46 ;
}
static void F_20 ( T_2 V_43 , T_3 * V_47 , int V_48 )
{
int V_45 ;
if ( V_48 > 4 )
V_48 = 4 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ )
V_47 [ V_45 ] = V_43 >> ( ( 3 - V_45 ) * 8 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_50 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
V_55 = F_22 ( V_50 ) ;
F_23 ( V_52 , V_55 ) ;
F_24 ( & V_52 -> V_56 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_50 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
F_26 ( & V_52 -> V_56 ) ;
V_55 = F_22 ( V_50 ) ;
F_27 ( V_52 , V_55 ) ;
}
static void
F_28 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_57 V_57 = V_1 -> V_58 ;
bool V_59 , V_60 = false ;
enum V_61 V_62 = F_29 ( V_57 ) ;
enum V_63 V_64 = F_30 ( V_57 ) ;
T_2 V_65 ;
if ( F_9 ( F_31 ( V_1 -> V_66 ) & V_67 ,
L_2 ,
F_32 ( V_57 ) , F_33 ( V_3 -> V_68 ) ) )
return;
F_34 ( L_3 ,
F_32 ( V_57 ) , F_33 ( V_3 -> V_68 ) ) ;
V_65 = F_31 ( V_1 -> V_66 ) & V_69 ;
V_65 |= V_70 | V_71 ;
V_65 |= F_35 ( 1 ) ;
V_65 |= V_72 ;
if ( F_36 ( V_7 ) )
V_65 |= F_37 ( V_57 ) ;
else if ( V_57 == V_73 )
V_65 |= V_74 ;
V_59 = F_31 ( F_38 ( V_57 ) ) & V_75 ;
if ( ! V_59 ) {
V_60 = F_36 ( V_7 ) &&
! F_39 ( V_52 , V_62 , V_64 , true ) ;
if ( F_40 ( V_7 , V_57 , F_36 ( V_7 ) ?
& V_76 [ 0 ] . V_77 : & V_78 [ 0 ] . V_77 ) ) {
F_41 ( L_4 ,
F_32 ( V_57 ) ) ;
return;
}
}
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
F_42 ( V_1 -> V_66 , V_65 | V_67 ) ;
F_43 ( V_1 -> V_66 ) ;
F_42 ( V_1 -> V_66 , V_65 & ~ V_67 ) ;
F_43 ( V_1 -> V_66 ) ;
if ( ! V_59 ) {
F_44 ( V_7 , V_57 ) ;
if ( V_60 )
F_39 ( V_52 , V_62 , V_64 , false ) ;
}
}
static enum V_57
F_45 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_49 * V_50 ;
unsigned int V_79 = ( 1 << V_80 ) | ( 1 << V_73 ) ;
enum V_57 V_57 ;
F_46 ( & V_52 -> V_56 ) ;
F_47 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_58 != V_81 )
return V_1 -> V_58 ;
F_48 (dev, encoder) {
struct V_1 * V_82 ;
if ( V_50 -> type != V_5 )
continue;
V_82 = F_5 ( & V_50 -> V_4 ) ;
if ( V_82 -> V_58 != V_81 )
V_79 &= ~ ( 1 << V_82 -> V_58 ) ;
}
if ( F_47 ( V_79 == 0 ) )
V_57 = V_80 ;
else
V_57 = F_49 ( V_79 ) - 1 ;
F_50 ( V_7 , V_57 ) ;
V_1 -> V_58 = V_57 ;
F_34 ( L_5 ,
F_32 ( V_1 -> V_58 ) ,
F_33 ( V_3 -> V_68 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
F_28 ( V_1 ) ;
return V_1 -> V_58 ;
}
static bool F_53 ( struct V_51 * V_52 ,
enum V_57 V_57 )
{
return F_31 ( F_54 ( V_57 ) ) & V_83 ;
}
static bool F_55 ( struct V_51 * V_52 ,
enum V_57 V_57 )
{
return F_31 ( F_56 ( V_57 ) ) & V_84 ;
}
static bool F_57 ( struct V_51 * V_52 ,
enum V_57 V_57 )
{
return true ;
}
static enum V_57
F_58 ( struct V_51 * V_52 ,
enum V_68 V_68 ,
T_4 V_85 )
{
enum V_57 V_57 ;
for ( V_57 = V_80 ; V_57 <= V_73 ; V_57 ++ ) {
T_5 V_86 = F_31 ( F_59 ( V_57 ) ) &
V_87 ;
if ( V_86 != F_60 ( V_68 ) )
continue;
if ( ! V_85 ( V_52 , V_57 ) )
continue;
return V_57 ;
}
return V_81 ;
}
static void
F_61 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
F_46 ( & V_52 -> V_56 ) ;
V_1 -> V_58 = F_58 ( V_52 , V_68 ,
F_53 ) ;
if ( V_1 -> V_58 == V_81 )
V_1 -> V_58 = F_58 ( V_52 , V_68 ,
F_55 ) ;
if ( V_1 -> V_58 == V_81 )
V_1 -> V_58 = F_58 ( V_52 , V_68 ,
F_57 ) ;
if ( V_1 -> V_58 == V_81 ) {
F_34 ( L_6 ,
F_33 ( V_68 ) ) ;
return;
}
F_34 ( L_7 ,
F_33 ( V_68 ) , F_32 ( V_1 -> V_58 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
void F_62 ( struct V_51 * V_52 )
{
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_49 * V_50 ;
if ( F_47 ( ! F_63 ( V_7 ) && ! F_36 ( V_7 ) ) )
return;
F_48 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_50 -> type != V_5 )
continue;
V_1 = F_5 ( & V_50 -> V_4 ) ;
V_1 -> V_58 = V_81 ;
}
}
static T_6
F_64 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_65 ( V_7 ) )
return F_66 ( 0 ) ;
else if ( F_67 ( V_7 ) )
return V_88 ;
else
return F_56 ( F_45 ( V_1 ) ) ;
}
static T_6
F_68 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_65 ( V_7 ) )
return F_69 ( 0 ) ;
else if ( F_67 ( V_7 ) )
return V_89 ;
else
return F_54 ( F_45 ( V_1 ) ) ;
}
static int F_70 ( struct V_90 * V_91 , unsigned long V_92 ,
void * V_93 )
{
struct V_1 * V_1 = F_71 ( V_91 , F_72 ( * V_1 ) ,
V_94 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( ! F_1 ( V_1 ) || V_92 != V_95 )
return 0 ;
F_21 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
enum V_57 V_57 = F_45 ( V_1 ) ;
T_6 V_96 , V_97 ;
T_5 V_98 ;
V_96 = F_56 ( V_57 ) ;
V_97 = F_73 ( V_57 ) ;
V_98 = F_31 ( V_97 ) ;
V_98 &= V_99 ;
F_42 ( V_97 , V_98 | 0x1F ) ;
F_42 ( V_96 , V_100 | V_101 ) ;
F_74 ( V_1 -> V_102 ) ;
}
F_25 ( V_1 ) ;
return 0 ;
}
static bool F_75 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ( F_63 ( V_7 ) || F_36 ( V_7 ) ) &&
V_1 -> V_58 == V_81 )
return false ;
return ( F_31 ( F_68 ( V_1 ) ) & V_83 ) != 0 ;
}
static bool F_76 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ( F_63 ( V_7 ) || F_36 ( V_7 ) ) &&
V_1 -> V_58 == V_81 )
return false ;
return F_31 ( F_64 ( V_1 ) ) & V_84 ;
}
static void
F_77 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_75 ( V_1 ) && ! F_76 ( V_1 ) ) {
F_9 ( 1 , L_8 ) ;
F_34 ( L_9 ,
F_31 ( F_68 ( V_1 ) ) ,
F_31 ( F_64 ( V_1 ) ) ) ;
}
}
static T_2
F_78 ( struct V_1 * V_1 , bool V_103 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_6 V_104 = V_1 -> V_105 ;
T_2 V_106 ;
bool V_107 ;
#define F_79 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_103 )
V_107 = F_80 ( V_52 -> V_108 , F_79 ,
F_81 ( 10 ) ) ;
else
V_107 = F_82 ( F_79 , 10 ) == 0 ;
if ( ! V_107 )
F_41 ( L_10 ,
V_103 ) ;
#undef F_79
return V_106 ;
}
static T_2 F_83 ( struct V_1 * V_1 , int V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = F_17 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_109 )
return 0 ;
return F_84 ( V_52 -> V_110 , 2000 ) ;
}
static T_2 F_85 ( struct V_1 * V_1 , int V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = F_17 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_109 )
return 0 ;
if ( V_3 -> V_68 == V_111 )
return F_84 ( V_52 -> V_112 , 2000 ) ;
else
return F_84 ( V_52 -> V_110 , 2000 ) ;
}
static T_2 F_86 ( struct V_1 * V_1 , int V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = F_17 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_68 != V_111 && F_87 ( V_52 ) ) {
switch ( V_109 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_85 ( V_1 , V_109 ) ;
}
static T_2 F_88 ( struct V_1 * V_1 , int V_109 )
{
return V_109 ? 0 : 1 ;
}
static T_2 F_89 ( struct V_1 * V_1 ,
bool V_103 ,
int V_113 ,
T_2 V_114 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_115 , V_116 ;
if ( F_90 ( V_7 ) )
V_115 = 3 ;
else
V_115 = 5 ;
if ( F_91 ( V_7 ) && V_3 -> V_68 == V_111 )
V_116 = V_117 ;
else
V_116 = V_118 ;
return V_119 |
V_120 |
( V_103 ? V_121 : 0 ) |
V_122 |
V_116 |
V_123 |
( V_113 << V_124 ) |
( V_115 << V_125 ) |
( V_114 << V_126 ) ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
bool V_103 ,
int V_113 ,
T_2 V_93 )
{
return V_119 |
V_120 |
( V_103 ? V_121 : 0 ) |
V_122 |
V_127 |
V_123 |
( V_113 << V_124 ) |
F_93 ( 32 ) ;
}
static int
F_94 ( struct V_1 * V_1 ,
const T_3 * V_128 , int V_113 ,
T_3 * V_129 , int V_130 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_6 V_104 = V_1 -> V_105 ;
T_2 V_114 ;
int V_45 , V_131 , V_132 ;
T_2 V_106 ;
int V_133 , clock = 0 ;
bool V_103 = F_95 ( V_7 ) ;
bool V_134 ;
F_21 ( V_1 ) ;
V_134 = F_96 ( V_1 ) ;
F_97 ( & V_52 -> V_135 , 0 ) ;
F_77 ( V_1 ) ;
for ( V_133 = 0 ; V_133 < 3 ; V_133 ++ ) {
V_106 = F_98 ( V_104 ) ;
if ( ( V_106 & V_119 ) == 0 )
break;
F_74 ( 1 ) ;
}
if ( V_133 == 3 ) {
static T_5 V_136 = - 1 ;
const T_5 V_106 = F_31 ( V_104 ) ;
if ( V_106 != V_136 ) {
F_9 ( 1 , L_11 ,
V_106 ) ;
V_136 = V_106 ;
}
V_131 = - V_137 ;
goto V_138;
}
if ( F_47 ( V_113 > 20 || V_130 > 20 ) ) {
V_131 = - V_139 ;
goto V_138;
}
while ( ( V_114 = V_1 -> V_140 ( V_1 , clock ++ ) ) ) {
T_5 V_141 = V_1 -> V_142 ( V_1 ,
V_103 ,
V_113 ,
V_114 ) ;
for ( V_133 = 0 ; V_133 < 5 ; V_133 ++ ) {
for ( V_45 = 0 ; V_45 < V_113 ; V_45 += 4 )
F_42 ( V_1 -> V_143 [ V_45 >> 2 ] ,
F_19 ( V_128 + V_45 ,
V_113 - V_45 ) ) ;
F_42 ( V_104 , V_141 ) ;
V_106 = F_78 ( V_1 , V_103 ) ;
F_42 ( V_104 ,
V_106 |
V_120 |
V_122 |
V_123 ) ;
if ( V_106 & V_122 )
continue;
if ( V_106 & V_123 ) {
F_99 ( 400 , 500 ) ;
continue;
}
if ( V_106 & V_120 )
goto V_107;
}
}
if ( ( V_106 & V_120 ) == 0 ) {
F_41 ( L_12 , V_106 ) ;
V_131 = - V_137 ;
goto V_138;
}
V_107:
if ( V_106 & V_123 ) {
F_41 ( L_13 , V_106 ) ;
V_131 = - V_144 ;
goto V_138;
}
if ( V_106 & V_122 ) {
F_34 ( L_14 , V_106 ) ;
V_131 = - V_145 ;
goto V_138;
}
V_132 = ( ( V_106 & V_146 ) >>
V_124 ) ;
if ( V_132 == 0 || V_132 > 20 ) {
F_34 ( L_15 ,
V_132 ) ;
F_99 ( 1000 , 1500 ) ;
V_131 = - V_137 ;
goto V_138;
}
if ( V_132 > V_130 )
V_132 = V_130 ;
for ( V_45 = 0 ; V_45 < V_132 ; V_45 += 4 )
F_20 ( F_31 ( V_1 -> V_143 [ V_45 >> 2 ] ) ,
V_129 + V_45 , V_132 - V_45 ) ;
V_131 = V_132 ;
V_138:
F_97 ( & V_52 -> V_135 , V_147 ) ;
if ( V_134 )
F_100 ( V_1 , false ) ;
F_25 ( V_1 ) ;
return V_131 ;
}
static T_7
F_101 ( struct V_148 * V_149 , struct V_150 * V_151 )
{
struct V_1 * V_1 = F_71 ( V_149 , struct V_1 , V_149 ) ;
T_3 V_152 [ 20 ] , V_153 [ 20 ] ;
T_8 V_154 , V_155 ;
int V_131 ;
V_152 [ 0 ] = ( V_151 -> V_156 << 4 ) |
( ( V_151 -> V_157 >> 16 ) & 0xf ) ;
V_152 [ 1 ] = ( V_151 -> V_157 >> 8 ) & 0xff ;
V_152 [ 2 ] = V_151 -> V_157 & 0xff ;
V_152 [ 3 ] = V_151 -> V_158 - 1 ;
switch ( V_151 -> V_156 & ~ V_159 ) {
case V_160 :
case V_161 :
case V_162 :
V_154 = V_151 -> V_158 ? V_163 + V_151 -> V_158 : V_164 ;
V_155 = 2 ;
if ( F_47 ( V_154 > 20 ) )
return - V_139 ;
if ( V_151 -> V_165 )
memcpy ( V_152 + V_163 , V_151 -> V_165 , V_151 -> V_158 ) ;
else
F_47 ( V_151 -> V_158 ) ;
V_131 = F_94 ( V_1 , V_152 , V_154 , V_153 , V_155 ) ;
if ( V_131 > 0 ) {
V_151 -> V_166 = V_153 [ 0 ] >> 4 ;
if ( V_131 > 1 ) {
V_131 = F_102 ( int , V_153 [ 1 ] , 0 , V_151 -> V_158 ) ;
} else {
V_131 = V_151 -> V_158 ;
}
}
break;
case V_167 :
case V_168 :
V_154 = V_151 -> V_158 ? V_163 : V_164 ;
V_155 = V_151 -> V_158 + 1 ;
if ( F_47 ( V_155 > 20 ) )
return - V_139 ;
V_131 = F_94 ( V_1 , V_152 , V_154 , V_153 , V_155 ) ;
if ( V_131 > 0 ) {
V_151 -> V_166 = V_153 [ 0 ] >> 4 ;
V_131 -- ;
memcpy ( V_151 -> V_165 , V_153 + 1 , V_131 ) ;
}
break;
default:
V_131 = - V_169 ;
break;
}
return V_131 ;
}
static T_6 F_103 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
switch ( V_68 ) {
case V_170 :
case V_171 :
case V_172 :
return F_104 ( V_68 ) ;
default:
F_105 ( V_68 ) ;
return F_104 ( V_170 ) ;
}
}
static T_6 F_106 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
switch ( V_68 ) {
case V_170 :
case V_171 :
case V_172 :
return F_107 ( V_68 , V_109 ) ;
default:
F_105 ( V_68 ) ;
return F_107 ( V_170 , V_109 ) ;
}
}
static T_6 F_108 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
switch ( V_68 ) {
case V_111 :
return F_104 ( V_68 ) ;
case V_170 :
case V_171 :
case V_172 :
return F_109 ( V_68 ) ;
default:
F_105 ( V_68 ) ;
return F_104 ( V_111 ) ;
}
}
static T_6 F_110 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
switch ( V_68 ) {
case V_111 :
return F_107 ( V_68 , V_109 ) ;
case V_170 :
case V_171 :
case V_172 :
return F_111 ( V_68 , V_109 ) ;
default:
F_105 ( V_68 ) ;
return F_107 ( V_111 , V_109 ) ;
}
}
static enum V_68 F_112 ( struct V_51 * V_52 )
{
const struct V_173 * V_174 =
& V_52 -> V_175 . V_176 [ V_177 ] ;
switch ( V_174 -> V_178 ) {
case V_179 :
return V_111 ;
case V_180 :
return V_170 ;
case V_181 :
return V_171 ;
case V_182 :
return V_172 ;
default:
F_105 ( V_174 -> V_178 ) ;
return V_111 ;
}
}
static T_6 F_113 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
if ( V_68 == V_177 )
V_68 = F_112 ( V_52 ) ;
switch ( V_68 ) {
case V_111 :
case V_170 :
case V_171 :
case V_172 :
return F_104 ( V_68 ) ;
default:
F_105 ( V_68 ) ;
return F_104 ( V_111 ) ;
}
}
static T_6 F_114 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
if ( V_68 == V_177 )
V_68 = F_112 ( V_52 ) ;
switch ( V_68 ) {
case V_111 :
case V_170 :
case V_171 :
case V_172 :
return F_107 ( V_68 , V_109 ) ;
default:
F_105 ( V_68 ) ;
return F_107 ( V_111 , V_109 ) ;
}
}
static T_6 F_115 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
if ( F_116 ( V_52 ) -> V_183 >= 9 )
return F_113 ( V_52 , V_68 ) ;
else if ( F_67 ( V_52 ) )
return F_108 ( V_52 , V_68 ) ;
else
return F_103 ( V_52 , V_68 ) ;
}
static T_6 F_117 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
if ( F_116 ( V_52 ) -> V_183 >= 9 )
return F_114 ( V_52 , V_68 , V_109 ) ;
else if ( F_67 ( V_52 ) )
return F_110 ( V_52 , V_68 , V_109 ) ;
else
return F_106 ( V_52 , V_68 , V_109 ) ;
}
static void F_118 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = F_17 ( F_3 ( V_1 ) ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
int V_45 ;
V_1 -> V_105 = F_115 ( V_52 , V_68 ) ;
for ( V_45 = 0 ; V_45 < F_119 ( V_1 -> V_143 ) ; V_45 ++ )
V_1 -> V_143 [ V_45 ] = F_117 ( V_52 , V_68 , V_45 ) ;
}
static void
F_120 ( struct V_1 * V_1 )
{
F_121 ( & V_1 -> V_149 ) ;
F_122 ( V_1 -> V_149 . V_184 ) ;
}
static int
F_123 ( struct V_1 * V_1 , struct V_26 * V_9 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
int V_131 ;
F_118 ( V_1 ) ;
V_1 -> V_149 . V_184 = F_124 ( V_185 , L_16 , F_33 ( V_68 ) ) ;
if ( ! V_1 -> V_149 . V_184 )
return - V_186 ;
V_1 -> V_149 . V_7 = V_9 -> V_4 . V_187 ;
V_1 -> V_149 . V_188 = F_101 ;
F_34 ( L_17 ,
V_1 -> V_149 . V_184 ,
V_9 -> V_4 . V_187 -> V_189 . V_184 ) ;
V_131 = F_125 ( & V_1 -> V_149 ) ;
if ( V_131 < 0 ) {
F_41 ( L_18 ,
V_1 -> V_149 . V_184 , V_131 ) ;
F_122 ( V_1 -> V_149 . V_184 ) ;
return V_131 ;
}
return 0 ;
}
static void
F_126 ( struct V_26 * V_26 )
{
struct V_1 * V_1 = F_4 ( & V_26 -> V_4 ) ;
F_120 ( V_1 ) ;
F_127 ( V_26 ) ;
}
static int
F_128 ( struct V_1 * V_1 , const int * * V_190 )
{
if ( V_1 -> V_191 ) {
* V_190 = V_1 -> V_190 ;
return V_1 -> V_191 ;
}
* V_190 = V_192 ;
return ( F_8 ( V_1 ) >> 3 ) + 1 ;
}
bool F_129 ( struct V_1 * V_1 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
if ( F_130 ( V_7 , 0 , V_194 ) )
return false ;
if ( ( F_131 ( V_7 ) && ! F_132 ( V_7 ) ) || F_91 ( V_7 ) ||
( F_116 ( V_7 ) -> V_183 >= 9 ) )
return true ;
else
return false ;
}
static int
F_133 ( struct V_1 * V_1 , const int * * V_195 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
int V_158 ;
if ( F_65 ( V_7 ) ) {
* V_195 = V_196 ;
V_158 = F_119 ( V_196 ) ;
} else if ( F_134 ( V_7 ) || F_135 ( V_7 ) ) {
* V_195 = V_197 ;
V_158 = F_119 ( V_197 ) ;
} else {
* V_195 = V_192 ;
V_158 = F_119 ( V_192 ) ;
}
if ( ! F_129 ( V_1 ) )
V_158 -- ;
return V_158 ;
}
static void
F_136 ( struct V_49 * V_50 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
const struct V_200 * V_201 = NULL ;
int V_45 , V_202 = 0 ;
if ( F_137 ( V_7 ) ) {
V_201 = V_203 ;
V_202 = F_119 ( V_203 ) ;
} else if ( F_67 ( V_7 ) ) {
V_201 = V_204 ;
V_202 = F_119 ( V_204 ) ;
} else if ( F_36 ( V_7 ) ) {
V_201 = V_76 ;
V_202 = F_119 ( V_76 ) ;
} else if ( F_63 ( V_7 ) ) {
V_201 = V_78 ;
V_202 = F_119 ( V_78 ) ;
}
if ( V_201 && V_202 ) {
for ( V_45 = 0 ; V_45 < V_202 ; V_45 ++ ) {
if ( V_199 -> V_205 == V_201 [ V_45 ] . clock ) {
V_199 -> V_77 = V_201 [ V_45 ] . V_77 ;
V_199 -> V_206 = true ;
break;
}
}
}
}
static int F_138 ( const int * V_195 , int V_207 ,
const int * V_190 , int V_208 ,
int * V_209 )
{
int V_45 = 0 , V_210 = 0 , V_211 = 0 ;
while ( V_45 < V_207 && V_210 < V_208 ) {
if ( V_195 [ V_45 ] == V_190 [ V_210 ] ) {
if ( F_47 ( V_211 >= V_212 ) )
return V_211 ;
V_209 [ V_211 ] = V_195 [ V_45 ] ;
++ V_211 ;
++ V_45 ;
++ V_210 ;
} else if ( V_195 [ V_45 ] < V_190 [ V_210 ] ) {
++ V_45 ;
} else {
++ V_210 ;
}
}
return V_211 ;
}
static int F_139 ( struct V_1 * V_1 ,
int * V_209 )
{
const int * V_195 , * V_190 ;
int V_207 , V_208 ;
V_208 = F_128 ( V_1 , & V_190 ) ;
V_207 = F_133 ( V_1 , & V_195 ) ;
return F_138 ( V_195 , V_207 ,
V_190 , V_208 ,
V_209 ) ;
}
static void F_140 ( char * V_213 , T_8 V_214 ,
const int * V_215 , int V_216 )
{
int V_45 ;
V_213 [ 0 ] = '\0' ;
for ( V_45 = 0 ; V_45 < V_216 ; V_45 ++ ) {
int V_217 = snprintf ( V_213 , V_214 , L_19 , V_45 ? L_20 : L_21 , V_215 [ V_45 ] ) ;
if ( V_217 >= V_214 )
return;
V_213 += V_217 ;
V_214 -= V_217 ;
}
}
static void F_141 ( struct V_1 * V_1 )
{
const int * V_195 , * V_190 ;
int V_207 , V_208 , V_218 ;
int V_209 [ V_212 ] ;
char V_213 [ 128 ] ;
if ( ( V_219 & V_220 ) == 0 )
return;
V_207 = F_133 ( V_1 , & V_195 ) ;
F_140 ( V_213 , sizeof( V_213 ) , V_195 , V_207 ) ;
F_34 ( L_22 , V_213 ) ;
V_208 = F_128 ( V_1 , & V_190 ) ;
F_140 ( V_213 , sizeof( V_213 ) , V_190 , V_208 ) ;
F_34 ( L_23 , V_213 ) ;
V_218 = F_139 ( V_1 , V_209 ) ;
F_140 ( V_213 , sizeof( V_213 ) , V_209 , V_218 ) ;
F_34 ( L_24 , V_213 ) ;
}
static int F_142 ( int V_221 , const int * V_222 )
{
int V_45 = 0 ;
for ( V_45 = 0 ; V_45 < V_212 ; ++ V_45 )
if ( V_221 == V_222 [ V_45 ] )
break;
return V_45 ;
}
int
F_18 ( struct V_1 * V_1 )
{
int V_222 [ V_212 ] = {} ;
int V_214 ;
V_214 = F_139 ( V_1 , V_222 ) ;
if ( F_47 ( V_214 <= 0 ) )
return 162000 ;
return V_222 [ F_142 ( 0 , V_222 ) - 1 ] ;
}
int F_143 ( struct V_1 * V_1 , int V_223 )
{
return F_142 ( V_223 , V_1 -> V_190 ) ;
}
void F_144 ( struct V_1 * V_1 , int V_205 ,
T_3 * V_224 , T_3 * V_225 )
{
if ( V_1 -> V_191 ) {
* V_224 = 0 ;
* V_225 =
F_143 ( V_1 , V_205 ) ;
} else {
* V_224 = F_145 ( V_205 ) ;
* V_225 = 0 ;
}
}
bool
F_146 ( struct V_49 * V_50 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_226 = & V_199 -> V_4 . V_226 ;
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_227 * V_227 = F_147 ( V_199 -> V_4 . V_228 ) ;
struct V_26 * V_26 = V_1 -> V_229 ;
int V_10 , clock ;
int V_230 = 1 ;
int V_231 = F_10 ( V_1 ) ;
int V_232 = 0 ;
int V_233 ;
int V_21 , V_31 ;
int V_234 , V_235 ;
int V_209 [ V_212 ] = {} ;
int V_218 ;
T_3 V_224 , V_225 ;
V_218 = F_139 ( V_1 , V_209 ) ;
F_47 ( V_218 <= 0 ) ;
V_233 = V_218 - 1 ;
if ( F_67 ( V_7 ) && ! F_148 ( V_7 ) && V_68 != V_111 )
V_199 -> V_236 = true ;
V_199 -> V_237 = true ;
V_199 -> V_238 = false ;
V_199 -> V_239 = V_1 -> V_239 && V_68 != V_111 ;
if ( F_1 ( V_1 ) && V_26 -> V_28 . V_27 ) {
F_149 ( V_26 -> V_28 . V_27 ,
V_226 ) ;
if ( F_116 ( V_7 ) -> V_183 >= 9 ) {
int V_131 ;
V_131 = F_150 ( V_199 ) ;
if ( V_131 )
return V_131 ;
}
if ( F_151 ( V_7 ) )
F_152 ( V_227 , V_199 ,
V_26 -> V_28 . V_240 ) ;
else
F_153 ( V_227 , V_199 ,
V_26 -> V_28 . V_240 ) ;
}
if ( V_226 -> V_39 & V_40 )
return false ;
F_34 ( L_25
L_26 ,
V_231 , V_209 [ V_233 ] ,
V_226 -> V_241 ) ;
V_21 = V_199 -> V_242 ;
if ( F_1 ( V_1 ) ) {
if ( V_26 -> V_4 . V_243 . V_244 == 0 &&
( V_52 -> V_175 . V_245 . V_21 && V_52 -> V_175 . V_245 . V_21 < V_21 ) ) {
F_34 ( L_27 ,
V_52 -> V_175 . V_245 . V_21 ) ;
V_21 = V_52 -> V_175 . V_245 . V_21 ;
}
V_230 = V_231 ;
V_232 = V_233 ;
}
for (; V_21 >= 6 * 3 ; V_21 -= 2 * 3 ) {
V_31 = F_13 ( V_226 -> V_241 ,
V_21 ) ;
for ( clock = V_232 ; clock <= V_233 ; clock ++ ) {
for ( V_10 = V_230 ;
V_10 <= V_231 ;
V_10 <<= 1 ) {
V_235 = V_209 [ clock ] ;
V_234 = F_14 ( V_235 ,
V_10 ) ;
if ( V_31 <= V_234 ) {
goto V_246;
}
}
}
}
return false ;
V_246:
if ( V_1 -> V_247 ) {
V_199 -> V_248 =
V_21 != 18 && F_154 ( V_226 ) > 1 ;
} else {
V_199 -> V_248 =
V_1 -> V_248 ;
}
V_199 -> V_10 = V_10 ;
V_199 -> V_242 = V_21 ;
V_199 -> V_205 = V_209 [ clock ] ;
F_144 ( V_1 , V_199 -> V_205 ,
& V_224 , & V_225 ) ;
F_34 ( L_28 ,
V_224 , V_225 , V_199 -> V_10 ,
V_199 -> V_205 , V_21 ) ;
F_34 ( L_29 ,
V_31 , V_234 ) ;
F_155 ( V_21 , V_10 ,
V_226 -> V_241 ,
V_199 -> V_205 ,
& V_199 -> V_249 ) ;
if ( V_26 -> V_28 . V_250 != NULL &&
V_52 -> V_251 . type == V_252 ) {
V_199 -> V_238 = true ;
F_155 ( V_21 , V_10 ,
V_26 -> V_28 . V_250 -> clock ,
V_199 -> V_205 ,
& V_199 -> V_253 ) ;
}
if ( ! F_148 ( V_7 ) )
F_136 ( V_50 , V_199 ) ;
return true ;
}
void F_156 ( struct V_1 * V_1 ,
const struct V_198 * V_199 )
{
V_1 -> V_254 = V_199 -> V_205 ;
V_1 -> V_10 = V_199 -> V_10 ;
}
static void F_157 ( struct V_49 * V_50 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
const struct V_24 * V_226 = & V_228 -> V_255 -> V_4 . V_226 ;
F_156 ( V_1 , V_228 -> V_255 ) ;
V_1 -> V_65 = F_31 ( V_1 -> V_66 ) & V_69 ;
V_1 -> V_65 |= V_70 | V_71 ;
V_1 -> V_65 |= F_35 ( V_228 -> V_255 -> V_10 ) ;
if ( F_158 ( V_7 ) && V_68 == V_111 ) {
if ( V_226 -> V_39 & V_256 )
V_1 -> V_65 |= V_257 ;
if ( V_226 -> V_39 & V_258 )
V_1 -> V_65 |= V_259 ;
V_1 -> V_65 |= V_260 ;
if ( F_159 ( V_1 -> V_12 ) )
V_1 -> V_65 |= V_261 ;
V_1 -> V_65 |= V_228 -> V_57 << 29 ;
} else if ( F_160 ( V_7 ) && V_68 != V_111 ) {
T_5 V_262 ;
V_1 -> V_65 |= V_260 ;
V_262 = F_31 ( F_161 ( V_228 -> V_57 ) ) ;
if ( F_159 ( V_1 -> V_12 ) )
V_262 |= V_263 ;
else
V_262 &= ~ V_263 ;
F_42 ( F_161 ( V_228 -> V_57 ) , V_262 ) ;
} else {
if ( ! F_67 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_36 ( V_7 ) && V_228 -> V_255 -> V_248 )
V_1 -> V_65 |= V_264 ;
if ( V_226 -> V_39 & V_256 )
V_1 -> V_65 |= V_257 ;
if ( V_226 -> V_39 & V_258 )
V_1 -> V_65 |= V_259 ;
V_1 -> V_65 |= V_265 ;
if ( F_159 ( V_1 -> V_12 ) )
V_1 -> V_65 |= V_261 ;
if ( F_36 ( V_7 ) )
V_1 -> V_65 |= F_37 ( V_228 -> V_57 ) ;
else if ( V_228 -> V_57 == V_73 )
V_1 -> V_65 |= V_74 ;
}
}
static void F_162 ( struct V_1 * V_1 ,
T_5 V_266 ,
T_5 V_267 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_6 V_268 , V_96 ;
F_46 ( & V_52 -> V_56 ) ;
V_268 = F_68 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
F_34 ( L_30 ,
V_266 , V_267 ,
F_31 ( V_268 ) ,
F_31 ( V_96 ) ) ;
if ( F_163 ( ( F_31 ( V_268 ) & V_266 ) == V_267 ,
5 * V_269 , 10 * V_270 ) )
F_41 ( L_31 ,
F_31 ( V_268 ) ,
F_31 ( V_96 ) ) ;
F_34 ( L_32 ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
F_34 ( L_33 ) ;
F_162 ( V_1 , V_271 , V_272 ) ;
}
static void F_165 ( struct V_1 * V_1 )
{
F_34 ( L_34 ) ;
F_162 ( V_1 , V_273 , V_274 ) ;
}
static void F_166 ( struct V_1 * V_1 )
{
T_9 V_275 ;
T_10 V_276 ;
F_34 ( L_35 ) ;
V_275 = F_167 () ;
V_276 = F_168 ( V_275 , V_1 -> V_277 ) ;
if ( V_276 < ( T_10 ) V_1 -> V_102 )
F_169 ( V_278 ,
V_1 -> V_102 - V_276 ) ;
F_162 ( V_1 , V_279 , V_280 ) ;
}
static void F_170 ( struct V_1 * V_1 )
{
F_169 ( V_1 -> V_281 ,
V_1 -> V_282 ) ;
}
static void F_171 ( struct V_1 * V_1 )
{
F_169 ( V_1 -> V_283 ,
V_1 -> V_284 ) ;
}
static T_5 F_172 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_285 ;
F_46 ( & V_52 -> V_56 ) ;
V_285 = F_31 ( F_64 ( V_1 ) ) ;
if ( ! F_65 ( V_7 ) ) {
V_285 &= ~ V_286 ;
V_285 |= V_100 ;
}
return V_285 ;
}
static bool F_96 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_287 ;
T_6 V_268 , V_96 ;
bool V_288 = ! V_1 -> V_289 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_173 ( & V_1 -> V_290 ) ;
V_1 -> V_289 = true ;
if ( F_76 ( V_1 ) )
return V_288 ;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
F_34 ( L_36 ,
F_33 ( V_3 -> V_68 ) ) ;
if ( ! F_75 ( V_1 ) )
F_166 ( V_1 ) ;
V_287 = F_172 ( V_1 ) ;
V_287 |= V_84 ;
V_268 = F_68 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
F_34 ( L_37 ,
F_31 ( V_268 ) , F_31 ( V_96 ) ) ;
if ( ! F_75 ( V_1 ) ) {
F_34 ( L_38 ,
F_33 ( V_3 -> V_68 ) ) ;
F_74 ( V_1 -> V_291 ) ;
}
return V_288 ;
}
void F_174 ( struct V_1 * V_1 )
{
bool V_134 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_134 = F_96 ( V_1 ) ;
F_25 ( V_1 ) ;
F_175 ( ! V_134 , L_39 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
}
static void F_176 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
enum V_54 V_55 ;
T_5 V_287 ;
T_6 V_268 , V_96 ;
F_46 ( & V_52 -> V_56 ) ;
F_47 ( V_1 -> V_289 ) ;
if ( ! F_76 ( V_1 ) )
return;
F_34 ( L_40 ,
F_33 ( V_3 -> V_68 ) ) ;
V_287 = F_172 ( V_1 ) ;
V_287 &= ~ V_84 ;
V_96 = F_64 ( V_1 ) ;
V_268 = F_68 ( V_1 ) ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
F_34 ( L_37 ,
F_31 ( V_268 ) , F_31 ( V_96 ) ) ;
if ( ( V_287 & V_292 ) == 0 )
V_1 -> V_277 = F_167 () ;
V_55 = F_22 ( V_49 ) ;
F_27 ( V_52 , V_55 ) ;
}
static void F_177 ( struct V_293 * V_294 )
{
struct V_1 * V_1 = F_71 ( F_178 ( V_294 ) ,
struct V_1 , V_290 ) ;
F_21 ( V_1 ) ;
if ( ! V_1 -> V_289 )
F_176 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
unsigned long V_295 ;
V_295 = F_180 ( V_1 -> V_102 * 5 ) ;
F_181 ( & V_1 -> V_290 , V_295 ) ;
}
static void F_100 ( struct V_1 * V_1 , bool V_296 )
{
struct V_51 * V_52 =
F_3 ( V_1 ) -> V_53 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_175 ( ! V_1 -> V_289 , L_41 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
V_1 -> V_289 = false ;
if ( V_296 )
F_176 ( V_1 ) ;
else
F_179 ( V_1 ) ;
}
static void F_182 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_287 ;
T_6 V_96 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_42 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
if ( F_9 ( F_75 ( V_1 ) ,
L_43 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) )
return;
F_166 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
V_287 = F_172 ( V_1 ) ;
if ( F_183 ( V_7 ) ) {
V_287 &= ~ V_297 ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
}
V_287 |= V_292 ;
if ( ! F_183 ( V_7 ) )
V_287 |= V_297 ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
F_164 ( V_1 ) ;
V_1 -> V_281 = V_278 ;
if ( F_183 ( V_7 ) ) {
V_287 |= V_297 ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
}
}
void F_184 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_182 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_185 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_287 ;
T_6 V_96 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_44 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
F_9 ( ! V_1 -> V_289 , L_45 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
V_287 = F_172 ( V_1 ) ;
V_287 &= ~ ( V_292 | V_297 | V_84 |
V_298 ) ;
V_96 = F_64 ( V_1 ) ;
V_1 -> V_289 = false ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
V_1 -> V_277 = F_167 () ;
F_165 ( V_1 ) ;
V_55 = F_22 ( V_49 ) ;
F_27 ( V_52 , V_55 ) ;
}
void F_186 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_185 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_187 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_287 ;
T_6 V_96 ;
F_170 ( V_1 ) ;
F_21 ( V_1 ) ;
V_287 = F_172 ( V_1 ) ;
V_287 |= V_298 ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
F_25 ( V_1 ) ;
}
void F_188 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_189 ( V_1 -> V_229 ) ;
F_187 ( V_1 ) ;
}
static void F_190 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_287 ;
T_6 V_96 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_287 = F_172 ( V_1 ) ;
V_287 &= ~ V_298 ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_287 ) ;
F_43 ( V_96 ) ;
F_25 ( V_1 ) ;
V_1 -> V_283 = V_278 ;
F_171 ( V_1 ) ;
}
void F_191 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_190 ( V_1 ) ;
F_192 ( V_1 -> V_229 ) ;
}
static void F_193 ( struct V_26 * V_9 ,
bool V_299 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_300 ;
F_21 ( V_1 ) ;
V_300 = F_172 ( V_1 ) & V_298 ;
F_25 ( V_1 ) ;
if ( V_300 == V_299 )
return;
F_34 ( L_47 ,
V_299 ? L_48 : L_49 ) ;
if ( V_299 )
F_187 ( V_1 ) ;
else
F_190 ( V_1 ) ;
}
static void F_194 ( struct V_1 * V_1 , bool V_301 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_51 * V_52 = F_17 ( V_193 -> V_4 . V_4 . V_7 ) ;
bool V_302 = F_31 ( V_1 -> V_66 ) & V_67 ;
F_175 ( V_302 != V_301 ,
L_50 ,
F_33 ( V_193 -> V_68 ) ,
F_195 ( V_301 ) , F_195 ( V_302 ) ) ;
}
static void F_196 ( struct V_51 * V_52 , bool V_301 )
{
bool V_302 = F_31 ( V_303 ) & V_304 ;
F_175 ( V_302 != V_301 ,
L_51 ,
F_195 ( V_301 ) , F_195 ( V_302 ) ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_227 * V_228 = F_147 ( V_3 -> V_4 . V_4 . V_228 ) ;
struct V_51 * V_52 = F_17 ( V_228 -> V_4 . V_7 ) ;
F_198 ( V_52 , V_228 -> V_57 ) ;
F_199 ( V_1 ) ;
F_200 ( V_52 ) ;
F_34 ( L_52 ,
V_228 -> V_255 -> V_205 ) ;
V_1 -> V_65 &= ~ V_305 ;
if ( V_228 -> V_255 -> V_205 == 162000 )
V_1 -> V_65 |= V_306 ;
else
V_1 -> V_65 |= V_307 ;
F_42 ( V_303 , V_1 -> V_65 ) ;
F_43 ( V_303 ) ;
F_201 ( 500 ) ;
if ( F_183 ( V_52 ) )
F_202 ( V_52 -> V_7 , ! V_228 -> V_57 ) ;
V_1 -> V_65 |= V_304 ;
F_42 ( V_303 , V_1 -> V_65 ) ;
F_43 ( V_303 ) ;
F_201 ( 200 ) ;
}
static void F_203 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_227 * V_228 = F_147 ( V_3 -> V_4 . V_4 . V_228 ) ;
struct V_51 * V_52 = F_17 ( V_228 -> V_4 . V_7 ) ;
F_198 ( V_52 , V_228 -> V_57 ) ;
F_199 ( V_1 ) ;
F_204 ( V_52 ) ;
F_34 ( L_53 ) ;
V_1 -> V_65 &= ~ V_304 ;
F_42 ( V_303 , V_1 -> V_65 ) ;
F_43 ( V_303 ) ;
F_201 ( 200 ) ;
}
void F_205 ( struct V_1 * V_1 , int V_25 )
{
int V_131 , V_45 ;
if ( V_1 -> V_12 [ V_308 ] < 0x11 )
return;
if ( V_25 != V_309 ) {
V_131 = F_206 ( & V_1 -> V_149 , V_310 ,
V_311 ) ;
} else {
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_131 = F_206 ( & V_1 -> V_149 , V_310 ,
V_312 ) ;
if ( V_131 == 1 )
break;
F_74 ( 1 ) ;
}
}
if ( V_131 != 1 )
F_34 ( L_54 ,
V_25 == V_309 ? L_48 : L_49 ) ;
}
static bool F_207 ( struct V_49 * V_50 ,
enum V_57 * V_57 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_82 ;
bool V_131 ;
V_55 = F_208 ( V_50 ) ;
if ( ! F_209 ( V_52 , V_55 ) )
return false ;
V_131 = false ;
V_82 = F_31 ( V_1 -> V_66 ) ;
if ( ! ( V_82 & V_67 ) )
goto V_138;
if ( F_158 ( V_7 ) && V_68 == V_111 ) {
* V_57 = F_210 ( V_82 ) ;
} else if ( F_160 ( V_7 ) && V_68 != V_111 ) {
enum V_57 V_313 ;
F_211 (dev_priv, p) {
T_5 V_262 = F_31 ( F_161 ( V_313 ) ) ;
if ( F_212 ( V_262 ) == V_68 ) {
* V_57 = V_313 ;
V_131 = true ;
goto V_138;
}
}
F_34 ( L_55 ,
F_213 ( V_1 -> V_66 ) ) ;
} else if ( F_36 ( V_7 ) ) {
* V_57 = F_214 ( V_82 ) ;
} else {
* V_57 = F_215 ( V_82 ) ;
}
V_131 = true ;
V_138:
F_27 ( V_52 , V_55 ) ;
return V_131 ;
}
static void F_216 ( struct V_49 * V_50 ,
struct V_198 * V_199 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
T_5 V_82 , V_39 = 0 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
V_82 = F_31 ( V_1 -> V_66 ) ;
V_199 -> V_239 = V_82 & V_314 && V_68 != V_111 ;
if ( F_160 ( V_7 ) && V_68 != V_111 ) {
T_5 V_262 = F_31 ( F_161 ( V_228 -> V_57 ) ) ;
if ( V_262 & V_315 )
V_39 |= V_256 ;
else
V_39 |= V_316 ;
if ( V_262 & V_317 )
V_39 |= V_258 ;
else
V_39 |= V_318 ;
} else {
if ( V_82 & V_257 )
V_39 |= V_256 ;
else
V_39 |= V_316 ;
if ( V_82 & V_259 )
V_39 |= V_258 ;
else
V_39 |= V_318 ;
}
V_199 -> V_4 . V_226 . V_39 |= V_39 ;
if ( ! F_67 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_36 ( V_7 ) && V_82 & V_264 )
V_199 -> V_248 = true ;
V_199 -> V_237 = true ;
V_199 -> V_10 =
( ( V_82 & V_319 ) >> V_320 ) + 1 ;
F_217 ( V_228 , V_199 ) ;
if ( V_68 == V_111 ) {
if ( ( F_31 ( V_303 ) & V_305 ) == V_306 )
V_199 -> V_205 = 162000 ;
else
V_199 -> V_205 = 270000 ;
}
V_199 -> V_4 . V_226 . V_241 =
F_218 ( V_199 -> V_205 ,
& V_199 -> V_249 ) ;
if ( F_1 ( V_1 ) && V_52 -> V_175 . V_245 . V_21 &&
V_199 -> V_242 > V_52 -> V_175 . V_245 . V_21 ) {
F_34 ( L_56 ,
V_199 -> V_242 , V_52 -> V_175 . V_245 . V_21 ) ;
V_52 -> V_175 . V_245 . V_21 = V_199 -> V_242 ;
}
}
static void F_219 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
if ( V_228 -> V_255 -> V_239 )
F_220 ( V_50 ) ;
if ( F_221 ( V_7 ) && ! F_148 ( V_7 ) )
F_222 ( V_1 ) ;
F_174 ( V_1 ) ;
F_191 ( V_1 ) ;
F_205 ( V_1 , V_321 ) ;
F_186 ( V_1 ) ;
if ( F_116 ( V_7 ) -> V_183 < 5 )
F_223 ( V_1 ) ;
}
static void F_224 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
F_223 ( V_1 ) ;
if ( V_68 == V_111 )
F_203 ( V_1 ) ;
}
static void F_225 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_223 ( V_1 ) ;
}
static void F_226 ( struct V_49 * V_50 ,
bool V_322 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_4 . V_7 ) ;
enum V_63 V_64 = F_227 ( F_228 ( & V_50 -> V_4 ) ) ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
enum V_57 V_57 = V_228 -> V_57 ;
T_2 V_323 ;
V_323 = F_229 ( V_52 , V_57 , F_230 ( V_64 ) ) ;
if ( V_322 )
V_323 &= ~ ( V_324 | V_325 ) ;
else
V_323 |= V_324 | V_325 ;
F_231 ( V_52 , V_57 , F_230 ( V_64 ) , V_323 ) ;
if ( V_228 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_232 ( V_64 ) ) ;
if ( V_322 )
V_323 &= ~ ( V_324 | V_325 ) ;
else
V_323 |= V_324 | V_325 ;
F_231 ( V_52 , V_57 , F_232 ( V_64 ) , V_323 ) ;
}
V_323 = F_229 ( V_52 , V_57 , F_233 ( V_64 ) ) ;
V_323 |= V_326 ;
if ( V_322 )
V_323 &= ~ V_327 ;
else
V_323 |= V_327 ;
F_231 ( V_52 , V_57 , F_233 ( V_64 ) , V_323 ) ;
if ( V_228 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_234 ( V_64 ) ) ;
V_323 |= V_326 ;
if ( V_322 )
V_323 &= ~ V_327 ;
else
V_323 |= V_327 ;
F_231 ( V_52 , V_57 , F_234 ( V_64 ) , V_323 ) ;
}
}
static void F_235 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_223 ( V_1 ) ;
F_24 ( & V_52 -> V_328 ) ;
F_226 ( V_50 , true ) ;
F_26 ( & V_52 -> V_328 ) ;
}
static void
F_236 ( struct V_1 * V_1 ,
T_2 * V_65 ,
T_3 V_329 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
if ( F_148 ( V_7 ) ) {
T_2 V_330 = F_31 ( F_237 ( V_68 ) ) ;
if ( V_329 & V_331 )
V_330 |= V_332 ;
else
V_330 &= ~ V_332 ;
V_330 &= ~ V_333 ;
switch ( V_329 & V_334 ) {
case V_335 :
V_330 |= V_336 ;
break;
case V_337 :
V_330 |= V_338 ;
break;
case V_339 :
V_330 |= V_340 ;
break;
case V_341 :
V_330 |= V_342 ;
break;
}
F_42 ( F_237 ( V_68 ) , V_330 ) ;
} else if ( ( F_158 ( V_7 ) && V_68 == V_111 ) ||
( F_160 ( V_7 ) && V_68 != V_111 ) ) {
* V_65 &= ~ V_343 ;
switch ( V_329 & V_334 ) {
case V_335 :
* V_65 |= V_260 ;
break;
case V_337 :
* V_65 |= V_344 ;
break;
case V_339 :
* V_65 |= V_345 ;
break;
case V_341 :
F_41 ( L_57 ) ;
* V_65 |= V_345 ;
break;
}
} else {
if ( F_36 ( V_7 ) )
* V_65 &= ~ V_346 ;
else
* V_65 &= ~ V_347 ;
switch ( V_329 & V_334 ) {
case V_335 :
* V_65 |= V_265 ;
break;
case V_337 :
* V_65 |= V_72 ;
break;
case V_339 :
* V_65 |= V_348 ;
break;
case V_341 :
if ( F_36 ( V_7 ) ) {
* V_65 |= V_349 ;
} else {
F_41 ( L_57 ) ;
* V_65 |= V_348 ;
}
break;
}
}
}
static void F_238 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_228 =
F_147 ( F_2 ( V_1 ) -> V_4 . V_4 . V_228 ) ;
F_236 ( V_1 , & V_1 -> V_65 ,
V_337 ) ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_1 -> V_65 |= V_67 ;
if ( V_228 -> V_255 -> V_239 )
V_1 -> V_65 |= V_314 ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
static void F_239 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
T_2 V_350 = F_31 ( V_1 -> V_66 ) ;
enum V_57 V_57 = V_228 -> V_57 ;
if ( F_47 ( V_350 & V_67 ) )
return;
F_21 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
F_240 ( V_1 ) ;
F_238 ( V_1 ) ;
F_96 ( V_1 ) ;
F_182 ( V_1 ) ;
F_100 ( V_1 , true ) ;
F_25 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
unsigned int V_351 = 0x0 ;
if ( F_36 ( V_7 ) )
V_351 = F_7 ( V_228 -> V_255 -> V_10 ) ;
F_241 ( V_52 , F_2 ( V_1 ) ,
V_351 ) ;
}
F_205 ( V_1 , V_309 ) ;
F_242 ( V_1 ) ;
F_243 ( V_1 ) ;
if ( V_228 -> V_255 -> V_239 ) {
F_244 ( L_58 ,
F_32 ( V_57 ) ) ;
F_245 ( V_50 ) ;
}
}
static void F_246 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_239 ( V_50 ) ;
F_188 ( V_1 ) ;
}
static void F_247 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_188 ( V_1 ) ;
F_248 ( V_1 ) ;
}
static void F_249 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
F_157 ( V_50 ) ;
if ( V_68 == V_111 )
F_197 ( V_1 ) ;
}
static void F_250 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = V_3 -> V_4 . V_4 . V_7 -> V_53 ;
enum V_57 V_57 = V_1 -> V_58 ;
T_6 V_352 = F_59 ( V_57 ) ;
F_176 ( V_1 ) ;
F_34 ( L_59 ,
F_32 ( V_57 ) , F_33 ( V_3 -> V_68 ) ) ;
F_42 ( V_352 , 0 ) ;
F_43 ( V_352 ) ;
V_1 -> V_58 = V_81 ;
}
static void F_50 ( struct V_6 * V_7 ,
enum V_57 V_57 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_49 * V_50 ;
F_46 ( & V_52 -> V_56 ) ;
if ( F_47 ( V_57 != V_80 && V_57 != V_73 ) )
return;
F_48 (dev, encoder) {
struct V_1 * V_1 ;
enum V_68 V_68 ;
if ( V_50 -> type != V_5 )
continue;
V_1 = F_5 ( & V_50 -> V_4 ) ;
V_68 = F_2 ( V_1 ) -> V_68 ;
if ( V_1 -> V_58 != V_57 )
continue;
F_34 ( L_60 ,
F_32 ( V_57 ) , F_33 ( V_68 ) ) ;
F_9 ( V_50 -> V_4 . V_228 ,
L_61 ,
F_32 ( V_57 ) , F_33 ( V_68 ) ) ;
F_250 ( V_1 ) ;
}
}
static void F_240 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_50 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_228 = F_147 ( V_50 -> V_4 . V_228 ) ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_58 == V_228 -> V_57 )
return;
if ( V_1 -> V_58 != V_81 )
F_250 ( V_1 ) ;
F_50 ( V_7 , V_228 -> V_57 ) ;
V_1 -> V_58 = V_228 -> V_57 ;
F_34 ( L_62 ,
F_32 ( V_1 -> V_58 ) , F_33 ( V_3 -> V_68 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
static void F_251 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_227 = F_147 ( V_50 -> V_4 . V_228 ) ;
enum V_63 V_68 = F_227 ( V_353 ) ;
int V_57 = V_227 -> V_57 ;
T_5 V_323 ;
F_24 ( & V_52 -> V_328 ) ;
V_323 = F_229 ( V_52 , V_57 , F_252 ( V_68 ) ) ;
V_323 = 0 ;
if ( V_57 )
V_323 |= ( 1 << 21 ) ;
else
V_323 &= ~ ( 1 << 21 ) ;
V_323 |= 0x001000c4 ;
F_231 ( V_52 , V_57 , F_253 ( V_68 ) , V_323 ) ;
F_231 ( V_52 , V_57 , F_254 ( V_68 ) , 0x00760018 ) ;
F_231 ( V_52 , V_57 , F_255 ( V_68 ) , 0x00400888 ) ;
F_26 ( & V_52 -> V_328 ) ;
F_239 ( V_50 ) ;
}
static void F_256 ( struct V_49 * V_50 )
{
struct V_2 * V_353 = F_228 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_227 =
F_147 ( V_50 -> V_4 . V_228 ) ;
enum V_63 V_68 = F_227 ( V_353 ) ;
int V_57 = V_227 -> V_57 ;
F_157 ( V_50 ) ;
F_24 ( & V_52 -> V_328 ) ;
F_231 ( V_52 , V_57 , F_257 ( V_68 ) ,
V_324 |
V_325 ) ;
F_231 ( V_52 , V_57 , F_258 ( V_68 ) ,
V_354 |
V_355 |
( 1 << V_356 ) |
V_327 ) ;
F_231 ( V_52 , V_57 , F_259 ( V_68 ) , 0x00750f00 ) ;
F_231 ( V_52 , V_57 , F_260 ( V_68 ) , 0x00001500 ) ;
F_231 ( V_52 , V_57 , F_261 ( V_68 ) , 0x40400000 ) ;
F_26 ( & V_52 -> V_328 ) ;
}
static void F_262 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_227 =
F_147 ( V_50 -> V_4 . V_228 ) ;
enum V_63 V_64 = F_227 ( V_353 ) ;
int V_57 = V_227 -> V_57 ;
int V_357 , V_45 , V_358 ;
T_5 V_323 ;
F_24 ( & V_52 -> V_328 ) ;
V_323 = F_229 ( V_52 , V_57 , F_263 ( V_64 ) ) ;
V_323 &= ~ V_359 ;
F_231 ( V_52 , V_57 , F_263 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_264 ( V_64 ) ) ;
V_323 &= ~ V_359 ;
F_231 ( V_52 , V_57 , F_264 ( V_64 ) , V_323 ) ;
}
for ( V_45 = 0 ; V_45 < V_227 -> V_255 -> V_10 ; V_45 ++ ) {
if ( V_227 -> V_255 -> V_10 == 1 )
V_357 = 0x0 ;
else
V_357 = ( V_45 == 1 ) ? 0x0 : 0x1 ;
F_231 ( V_52 , V_57 , F_265 ( V_64 , V_45 ) ,
V_357 << V_360 ) ;
}
if ( V_227 -> V_255 -> V_205 > 270000 )
V_358 = 0x18 ;
else if ( V_227 -> V_255 -> V_205 > 135000 )
V_358 = 0xd ;
else if ( V_227 -> V_255 -> V_205 > 67500 )
V_358 = 0x7 ;
else if ( V_227 -> V_255 -> V_205 > 33750 )
V_358 = 0x4 ;
else
V_358 = 0x2 ;
V_323 = F_229 ( V_52 , V_57 , F_263 ( V_64 ) ) ;
V_323 |= F_266 ( 0x1f ) ;
F_231 ( V_52 , V_57 , F_263 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_264 ( V_64 ) ) ;
V_323 |= F_266 ( 0x1f ) ;
F_231 ( V_52 , V_57 , F_264 ( V_64 ) , V_323 ) ;
}
F_231 ( V_52 , V_57 , F_267 ( V_64 ) ,
F_268 ( V_358 ) |
V_361 |
F_269 ( 0x1f ) |
F_270 ( 6 ) |
F_271 ( 0 ) ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
F_231 ( V_52 , V_57 , F_272 ( V_64 ) ,
F_268 ( V_358 ) |
V_361 |
F_269 ( 0x1f ) |
F_270 ( 7 ) |
F_271 ( 5 ) ) ;
}
F_226 ( V_50 , false ) ;
F_26 ( & V_52 -> V_328 ) ;
F_239 ( V_50 ) ;
if ( V_353 -> V_362 ) {
F_39 ( V_52 , V_363 , V_364 , false ) ;
V_353 -> V_362 = false ;
}
}
static void F_273 ( struct V_49 * V_50 )
{
struct V_2 * V_353 = F_228 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_227 * V_227 =
F_147 ( V_50 -> V_4 . V_228 ) ;
enum V_63 V_64 = F_227 ( V_353 ) ;
enum V_57 V_57 = V_227 -> V_57 ;
unsigned int V_351 =
F_7 ( V_227 -> V_255 -> V_10 ) ;
T_5 V_323 ;
F_157 ( V_50 ) ;
if ( V_64 == V_365 && V_57 == V_73 )
V_353 -> V_362 =
! F_39 ( V_52 , V_363 , V_364 , true ) ;
F_274 ( V_50 , true , V_351 ) ;
F_24 ( & V_52 -> V_328 ) ;
F_226 ( V_50 , true ) ;
if ( V_57 != V_73 ) {
V_323 = F_229 ( V_52 , V_57 , V_366 ) ;
V_323 &= ~ ( V_367 | V_368 ) ;
if ( V_64 == V_365 )
V_323 |= V_369 ;
if ( V_64 == V_364 )
V_323 |= V_370 ;
F_231 ( V_52 , V_57 , V_366 , V_323 ) ;
} else {
V_323 = F_229 ( V_52 , V_57 , V_371 ) ;
V_323 &= ~ ( V_372 | V_373 ) ;
if ( V_64 == V_365 )
V_323 |= V_374 ;
if ( V_64 == V_364 )
V_323 |= V_375 ;
F_231 ( V_52 , V_57 , V_371 , V_323 ) ;
}
V_323 = F_229 ( V_52 , V_57 , F_252 ( V_64 ) ) ;
V_323 |= V_376 ;
if ( V_57 != V_73 )
V_323 &= ~ V_377 ;
else
V_323 |= V_377 ;
F_231 ( V_52 , V_57 , F_252 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_275 ( V_64 ) ) ;
V_323 |= V_376 ;
if ( V_57 != V_73 )
V_323 &= ~ V_377 ;
else
V_323 |= V_377 ;
F_231 ( V_52 , V_57 , F_275 ( V_64 ) , V_323 ) ;
}
V_323 = F_229 ( V_52 , V_57 , F_276 ( V_64 ) ) ;
if ( V_57 != V_73 )
V_323 &= ~ V_378 ;
else
V_323 |= V_378 ;
F_231 ( V_52 , V_57 , F_276 ( V_64 ) , V_323 ) ;
F_26 ( & V_52 -> V_328 ) ;
}
static void F_277 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_4 . V_7 ) ;
enum V_57 V_57 = F_147 ( V_50 -> V_4 . V_228 ) -> V_57 ;
T_5 V_323 ;
F_24 ( & V_52 -> V_328 ) ;
if ( V_57 != V_73 ) {
V_323 = F_229 ( V_52 , V_57 , V_366 ) ;
V_323 &= ~ ( V_367 | V_368 ) ;
F_231 ( V_52 , V_57 , V_366 , V_323 ) ;
} else {
V_323 = F_229 ( V_52 , V_57 , V_371 ) ;
V_323 &= ~ ( V_372 | V_373 ) ;
F_231 ( V_52 , V_57 , V_371 , V_323 ) ;
}
F_26 ( & V_52 -> V_328 ) ;
F_274 ( V_50 , false , 0x0 ) ;
}
bool
F_278 ( struct V_1 * V_1 , T_3 V_379 [ V_380 ] )
{
return F_279 ( & V_1 -> V_149 , V_381 , V_379 ,
V_380 ) == V_380 ;
}
T_3
F_280 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
if ( F_65 ( V_7 ) )
return V_382 ;
else if ( F_116 ( V_7 ) -> V_183 >= 9 ) {
if ( V_52 -> V_175 . V_245 . V_383 && V_68 == V_111 )
return V_382 ;
return V_384 ;
} else if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
return V_382 ;
else if ( F_158 ( V_7 ) && V_68 == V_111 )
return V_384 ;
else if ( F_160 ( V_7 ) && V_68 != V_111 )
return V_382 ;
else
return V_384 ;
}
T_3
F_281 ( struct V_1 * V_1 , T_3 V_385 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
if ( F_116 ( V_7 ) -> V_183 >= 9 ) {
switch ( V_385 & V_386 ) {
case V_387 :
return V_388 ;
case V_389 :
return V_390 ;
case V_384 :
return V_391 ;
case V_382 :
return V_392 ;
default:
return V_392 ;
}
} else if ( F_131 ( V_7 ) || F_91 ( V_7 ) ) {
switch ( V_385 & V_386 ) {
case V_387 :
return V_388 ;
case V_389 :
return V_390 ;
case V_384 :
return V_391 ;
case V_382 :
default:
return V_392 ;
}
} else if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
switch ( V_385 & V_386 ) {
case V_387 :
return V_388 ;
case V_389 :
return V_390 ;
case V_384 :
return V_391 ;
case V_382 :
default:
return V_392 ;
}
} else if ( F_158 ( V_7 ) && V_68 == V_111 ) {
switch ( V_385 & V_386 ) {
case V_387 :
return V_390 ;
case V_389 :
case V_384 :
return V_391 ;
default:
return V_392 ;
}
} else {
switch ( V_385 & V_386 ) {
case V_387 :
return V_390 ;
case V_389 :
return V_390 ;
case V_384 :
return V_391 ;
case V_382 :
default:
return V_392 ;
}
}
}
static T_2 F_282 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_227 * V_227 =
F_147 ( V_353 -> V_4 . V_4 . V_228 ) ;
unsigned long V_393 , V_394 ,
V_395 ;
T_3 V_396 = V_1 -> V_396 [ 0 ] ;
enum V_63 V_68 = F_227 ( V_353 ) ;
int V_57 = V_227 -> V_57 ;
switch ( V_396 & V_397 ) {
case V_392 :
V_394 = 0x0004000 ;
switch ( V_396 & V_386 ) {
case V_387 :
V_393 = 0x2B405555 ;
V_395 = 0x552AB83A ;
break;
case V_389 :
V_393 = 0x2B404040 ;
V_395 = 0x5548B83A ;
break;
case V_384 :
V_393 = 0x2B245555 ;
V_395 = 0x5560B83A ;
break;
case V_382 :
V_393 = 0x2B405555 ;
V_395 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_391 :
V_394 = 0x0002000 ;
switch ( V_396 & V_386 ) {
case V_387 :
V_393 = 0x2B404040 ;
V_395 = 0x5552B83A ;
break;
case V_389 :
V_393 = 0x2B404848 ;
V_395 = 0x5580B83A ;
break;
case V_384 :
V_393 = 0x2B404040 ;
V_395 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_390 :
V_394 = 0x0000000 ;
switch ( V_396 & V_386 ) {
case V_387 :
V_393 = 0x2B305555 ;
V_395 = 0x5570B83A ;
break;
case V_389 :
V_393 = 0x2B2B4040 ;
V_395 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_388 :
V_394 = 0x0006000 ;
switch ( V_396 & V_386 ) {
case V_387 :
V_393 = 0x1B405555 ;
V_395 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_52 -> V_328 ) ;
F_231 ( V_52 , V_57 , F_283 ( V_68 ) , 0x00000000 ) ;
F_231 ( V_52 , V_57 , F_284 ( V_68 ) , V_393 ) ;
F_231 ( V_52 , V_57 , F_285 ( V_68 ) ,
V_395 ) ;
F_231 ( V_52 , V_57 , F_286 ( V_68 ) , 0x0C782040 ) ;
F_231 ( V_52 , V_57 , F_287 ( V_68 ) , 0x00030000 ) ;
F_231 ( V_52 , V_57 , F_288 ( V_68 ) , V_394 ) ;
F_231 ( V_52 , V_57 , F_283 ( V_68 ) , 0x80000000 ) ;
F_26 ( & V_52 -> V_328 ) ;
return 0 ;
}
static bool F_289 ( T_3 V_396 )
{
return ( V_396 & V_397 ) == V_392 &&
( V_396 & V_386 ) == V_382 ;
}
static T_2 F_290 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_353 = F_2 ( V_1 ) ;
struct V_227 * V_227 = F_147 ( V_353 -> V_4 . V_4 . V_228 ) ;
T_5 V_398 , V_399 , V_323 ;
T_3 V_396 = V_1 -> V_396 [ 0 ] ;
enum V_63 V_64 = F_227 ( V_353 ) ;
enum V_57 V_57 = V_227 -> V_57 ;
int V_45 ;
switch ( V_396 & V_397 ) {
case V_392 :
switch ( V_396 & V_386 ) {
case V_387 :
V_398 = 128 ;
V_399 = 52 ;
break;
case V_389 :
V_398 = 128 ;
V_399 = 77 ;
break;
case V_384 :
V_398 = 128 ;
V_399 = 102 ;
break;
case V_382 :
V_398 = 128 ;
V_399 = 154 ;
break;
default:
return 0 ;
}
break;
case V_391 :
switch ( V_396 & V_386 ) {
case V_387 :
V_398 = 85 ;
V_399 = 78 ;
break;
case V_389 :
V_398 = 85 ;
V_399 = 116 ;
break;
case V_384 :
V_398 = 85 ;
V_399 = 154 ;
break;
default:
return 0 ;
}
break;
case V_390 :
switch ( V_396 & V_386 ) {
case V_387 :
V_398 = 64 ;
V_399 = 104 ;
break;
case V_389 :
V_398 = 64 ;
V_399 = 154 ;
break;
default:
return 0 ;
}
break;
case V_388 :
switch ( V_396 & V_386 ) {
case V_387 :
V_398 = 43 ;
V_399 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_52 -> V_328 ) ;
V_323 = F_229 ( V_52 , V_57 , F_291 ( V_64 ) ) ;
V_323 &= ~ ( V_400 | V_401 ) ;
V_323 &= ~ ( V_402 | V_403 ) ;
V_323 |= V_404 | V_405 ;
F_231 ( V_52 , V_57 , F_291 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_292 ( V_64 ) ) ;
V_323 &= ~ ( V_400 | V_401 ) ;
V_323 &= ~ ( V_402 | V_403 ) ;
V_323 |= V_404 | V_405 ;
F_231 ( V_52 , V_57 , F_292 ( V_64 ) , V_323 ) ;
}
V_323 = F_229 ( V_52 , V_57 , F_293 ( V_64 ) ) ;
V_323 &= ~ ( V_406 | V_407 ) ;
V_323 |= V_408 | V_409 ;
F_231 ( V_52 , V_57 , F_293 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_294 ( V_64 ) ) ;
V_323 &= ~ ( V_406 | V_407 ) ;
V_323 |= V_408 | V_409 ;
F_231 ( V_52 , V_57 , F_294 ( V_64 ) , V_323 ) ;
}
for ( V_45 = 0 ; V_45 < V_227 -> V_255 -> V_10 ; V_45 ++ ) {
V_323 = F_229 ( V_52 , V_57 , F_295 ( V_64 , V_45 ) ) ;
V_323 &= ~ V_410 ;
V_323 |= V_398 << V_411 ;
F_231 ( V_52 , V_57 , F_295 ( V_64 , V_45 ) , V_323 ) ;
}
for ( V_45 = 0 ; V_45 < V_227 -> V_255 -> V_10 ; V_45 ++ ) {
V_323 = F_229 ( V_52 , V_57 , F_296 ( V_64 , V_45 ) ) ;
V_323 &= ~ V_412 ;
V_323 |= V_399 << V_413 ;
V_323 &= ~ ( 0xff << V_414 ) ;
V_323 |= 0x9a << V_414 ;
F_231 ( V_52 , V_57 , F_296 ( V_64 , V_45 ) , V_323 ) ;
}
for ( V_45 = 0 ; V_45 < V_227 -> V_255 -> V_10 ; V_45 ++ ) {
V_323 = F_229 ( V_52 , V_57 , F_297 ( V_64 , V_45 ) ) ;
if ( F_289 ( V_396 ) )
V_323 |= V_415 ;
else
V_323 &= ~ V_415 ;
F_231 ( V_52 , V_57 , F_297 ( V_64 , V_45 ) , V_323 ) ;
}
V_323 = F_229 ( V_52 , V_57 , F_291 ( V_64 ) ) ;
V_323 |= V_400 | V_401 ;
F_231 ( V_52 , V_57 , F_291 ( V_64 ) , V_323 ) ;
if ( V_227 -> V_255 -> V_10 > 2 ) {
V_323 = F_229 ( V_52 , V_57 , F_292 ( V_64 ) ) ;
V_323 |= V_400 | V_401 ;
F_231 ( V_52 , V_57 , F_292 ( V_64 ) , V_323 ) ;
}
F_26 ( & V_52 -> V_328 ) ;
return 0 ;
}
static T_2
F_298 ( T_3 V_396 )
{
T_2 V_416 = 0 ;
switch ( V_396 & V_386 ) {
case V_387 :
default:
V_416 |= V_70 ;
break;
case V_389 :
V_416 |= V_417 ;
break;
case V_384 :
V_416 |= V_418 ;
break;
case V_382 :
V_416 |= V_419 ;
break;
}
switch ( V_396 & V_397 ) {
case V_392 :
default:
V_416 |= V_71 ;
break;
case V_391 :
V_416 |= V_420 ;
break;
case V_390 :
V_416 |= V_421 ;
break;
case V_388 :
V_416 |= V_422 ;
break;
}
return V_416 ;
}
static T_2
F_299 ( T_3 V_396 )
{
int V_416 = V_396 & ( V_386 |
V_397 ) ;
switch ( V_416 ) {
case V_387 | V_392 :
case V_389 | V_392 :
return V_423 ;
case V_387 | V_391 :
return V_424 ;
case V_387 | V_390 :
case V_389 | V_390 :
return V_425 ;
case V_389 | V_391 :
case V_384 | V_391 :
return V_426 ;
case V_384 | V_392 :
case V_382 | V_392 :
return V_427 ;
default:
F_34 ( L_63
L_64 , V_416 ) ;
return V_423 ;
}
}
static T_2
F_300 ( T_3 V_396 )
{
int V_416 = V_396 & ( V_386 |
V_397 ) ;
switch ( V_416 ) {
case V_387 | V_392 :
return V_428 ;
case V_387 | V_391 :
return V_429 ;
case V_387 | V_390 :
return V_430 ;
case V_389 | V_392 :
return V_431 ;
case V_389 | V_391 :
return V_432 ;
case V_384 | V_392 :
return V_433 ;
case V_384 | V_391 :
return V_434 ;
default:
F_34 ( L_63
L_64 , V_416 ) ;
return V_435 ;
}
}
void
F_301 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = F_17 ( V_7 ) ;
T_2 V_416 , V_266 = 0 ;
T_3 V_396 = V_1 -> V_396 [ 0 ] ;
if ( F_148 ( V_7 ) ) {
V_416 = F_302 ( V_1 ) ;
if ( F_65 ( V_7 ) )
V_416 = 0 ;
else
V_266 = V_436 ;
} else if ( F_36 ( V_7 ) ) {
V_416 = F_290 ( V_1 ) ;
} else if ( F_63 ( V_7 ) ) {
V_416 = F_282 ( V_1 ) ;
} else if ( F_158 ( V_7 ) && V_68 == V_111 ) {
V_416 = F_300 ( V_396 ) ;
V_266 = V_437 ;
} else if ( F_90 ( V_7 ) && V_68 == V_111 ) {
V_416 = F_299 ( V_396 ) ;
V_266 = V_438 ;
} else {
V_416 = F_298 ( V_396 ) ;
V_266 = V_439 | V_440 ;
}
if ( V_266 )
F_34 ( L_65 , V_416 ) ;
F_34 ( L_66 ,
V_396 & V_386 ) ;
F_34 ( L_67 ,
( V_396 & V_397 ) >>
V_441 ) ;
V_1 -> V_65 = ( V_1 -> V_65 & ~ V_266 ) | V_416 ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
void
F_303 ( struct V_1 * V_1 ,
T_3 V_329 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 =
F_17 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_236 ( V_1 , & V_1 -> V_65 , V_329 ) ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
void F_304 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
T_2 V_323 ;
if ( ! F_148 ( V_7 ) )
return;
V_323 = F_31 ( F_237 ( V_68 ) ) ;
V_323 &= ~ V_333 ;
V_323 |= V_442 ;
F_42 ( F_237 ( V_68 ) , V_323 ) ;
if ( V_68 == V_111 )
return;
if ( F_82 ( ( F_31 ( F_305 ( V_68 ) ) & V_443 ) ,
1 ) )
F_41 ( L_68 ) ;
}
static void
F_223 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_227 * V_228 = F_147 ( V_3 -> V_4 . V_4 . V_228 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_65 = V_1 -> V_65 ;
if ( F_47 ( F_148 ( V_7 ) ) )
return;
if ( F_47 ( ( F_31 ( V_1 -> V_66 ) & V_67 ) == 0 ) )
return;
F_34 ( L_46 ) ;
if ( ( F_158 ( V_7 ) && V_68 == V_111 ) ||
( F_160 ( V_7 ) && V_68 != V_111 ) ) {
V_65 &= ~ V_343 ;
V_65 |= V_444 ;
} else {
if ( F_36 ( V_7 ) )
V_65 &= ~ V_346 ;
else
V_65 &= ~ V_347 ;
V_65 |= V_445 ;
}
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_65 &= ~ ( V_67 | V_314 ) ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
if ( F_306 ( V_7 ) && V_228 -> V_57 == V_73 && V_68 != V_111 ) {
F_307 ( V_52 , V_80 , false ) ;
F_308 ( V_52 , V_80 , false ) ;
V_65 &= ~ ( V_74 | V_347 ) ;
V_65 |= V_67 | V_72 ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_65 &= ~ V_67 ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
F_202 ( V_52 -> V_7 , V_80 ) ;
F_307 ( V_52 , V_80 , true ) ;
F_308 ( V_52 , V_80 , true ) ;
}
F_74 ( V_1 -> V_446 ) ;
V_1 -> V_65 = V_65 ;
}
static bool
F_309 ( struct V_1 * V_1 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_3 V_447 ;
if ( F_279 ( & V_1 -> V_149 , 0x000 , V_1 -> V_12 ,
sizeof( V_1 -> V_12 ) ) < 0 )
return false ;
F_34 ( L_69 , ( int ) sizeof( V_1 -> V_12 ) , V_1 -> V_12 ) ;
if ( V_1 -> V_12 [ V_308 ] == 0 )
return false ;
if ( F_279 ( & V_1 -> V_149 , V_448 ,
& V_1 -> V_449 , 1 ) < 0 )
return false ;
V_1 -> V_449 = F_310 ( V_1 -> V_449 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_449 )
return false ;
memset ( V_1 -> V_450 , 0 , sizeof( V_1 -> V_450 ) ) ;
if ( F_1 ( V_1 ) ) {
F_279 ( & V_1 -> V_149 , V_451 ,
V_1 -> V_450 ,
sizeof( V_1 -> V_450 ) ) ;
if ( V_1 -> V_450 [ 0 ] & V_452 ) {
V_52 -> V_453 . V_454 = true ;
F_34 ( L_70 ) ;
}
if ( F_116 ( V_7 ) -> V_183 >= 9 &&
( V_1 -> V_450 [ 0 ] & V_455 ) ) {
T_3 V_456 ;
V_52 -> V_453 . V_454 = true ;
F_279 ( & V_1 -> V_149 ,
V_457 ,
& V_456 , 1 ) ;
V_52 -> V_453 . V_458 = V_456 ? true : false ;
V_52 -> V_453 . V_459 = V_52 -> V_453 . V_458 ;
F_34 ( L_71 ,
V_52 -> V_453 . V_459 ? L_72 : L_73 ) ;
}
}
F_34 ( L_74 ,
F_311 ( F_129 ( V_1 ) ) ,
F_311 ( F_312 ( V_1 -> V_12 ) ) ) ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_12 [ V_460 ] & V_461 ) &&
( F_279 ( & V_1 -> V_149 , V_462 , & V_447 , 1 ) == 1 ) &&
( V_447 >= 0x03 ) ) {
T_11 V_190 [ V_212 ] ;
int V_45 ;
F_279 ( & V_1 -> V_149 , V_463 ,
V_190 , sizeof( V_190 ) ) ;
for ( V_45 = 0 ; V_45 < F_119 ( V_190 ) ; V_45 ++ ) {
int V_323 = F_313 ( V_190 [ V_45 ] ) ;
if ( V_323 == 0 )
break;
V_1 -> V_190 [ V_45 ] = ( V_323 * 200 ) / 10 ;
}
V_1 -> V_191 = V_45 ;
}
F_141 ( V_1 ) ;
if ( ! ( V_1 -> V_12 [ V_464 ] &
V_465 ) )
return true ;
if ( V_1 -> V_12 [ V_308 ] == 0x10 )
return true ;
if ( F_279 ( & V_1 -> V_149 , V_466 ,
V_1 -> V_467 ,
V_468 ) < 0 )
return false ;
return true ;
}
static void
F_314 ( struct V_1 * V_1 )
{
T_1 V_469 [ 3 ] ;
if ( ! ( V_1 -> V_12 [ V_470 ] & V_471 ) )
return;
if ( F_279 ( & V_1 -> V_149 , V_472 , V_469 , 3 ) == 3 )
F_34 ( L_75 ,
V_469 [ 0 ] , V_469 [ 1 ] , V_469 [ 2 ] ) ;
if ( F_279 ( & V_1 -> V_149 , V_473 , V_469 , 3 ) == 3 )
F_34 ( L_76 ,
V_469 [ 0 ] , V_469 [ 1 ] , V_469 [ 2 ] ) ;
}
static bool
F_315 ( struct V_1 * V_1 )
{
T_1 V_469 [ 1 ] ;
if ( ! V_474 . V_475 )
return false ;
if ( ! V_1 -> V_476 )
return false ;
if ( V_1 -> V_12 [ V_308 ] < 0x12 )
return false ;
if ( F_279 ( & V_1 -> V_149 , V_477 , V_469 , 1 ) ) {
if ( V_469 [ 0 ] & V_478 ) {
F_34 ( L_77 ) ;
V_1 -> V_479 = true ;
} else {
F_34 ( L_78 ) ;
V_1 -> V_479 = false ;
}
}
F_316 ( & V_1 -> V_480 , V_1 -> V_479 ) ;
return V_1 -> V_479 ;
}
static int F_317 ( struct V_1 * V_1 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
struct V_227 * V_227 = F_147 ( V_193 -> V_4 . V_4 . V_228 ) ;
T_1 V_469 ;
int V_131 = 0 ;
int V_202 = 0 ;
int V_481 = 10 ;
if ( F_318 ( & V_1 -> V_149 , V_482 , & V_469 ) < 0 ) {
F_34 ( L_79 ) ;
V_131 = - V_144 ;
goto V_138;
}
if ( F_206 ( & V_1 -> V_149 , V_482 ,
V_469 & ~ V_483 ) < 0 ) {
F_34 ( L_79 ) ;
V_131 = - V_144 ;
goto V_138;
}
do {
F_319 ( V_7 , V_227 -> V_57 ) ;
if ( F_318 ( & V_1 -> V_149 ,
V_484 , & V_469 ) < 0 ) {
V_131 = - V_144 ;
goto V_138;
}
V_202 = V_469 & V_485 ;
} while ( -- V_481 && V_202 );
if ( V_481 == 0 ) {
F_34 ( L_80 ) ;
V_131 = - V_145 ;
}
V_138:
F_320 ( V_227 ) ;
return V_131 ;
}
static int F_321 ( struct V_1 * V_1 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
struct V_227 * V_227 = F_147 ( V_193 -> V_4 . V_4 . V_228 ) ;
T_1 V_469 ;
int V_131 ;
if ( F_318 ( & V_1 -> V_149 , V_484 , & V_469 ) < 0 )
return - V_144 ;
if ( ! ( V_469 & V_486 ) )
return - V_487 ;
if ( F_318 ( & V_1 -> V_149 , V_482 , & V_469 ) < 0 )
return - V_144 ;
if ( V_469 & V_483 ) {
V_131 = F_317 ( V_1 ) ;
if ( V_131 )
return V_131 ;
}
F_322 ( V_227 ) ;
if ( F_206 ( & V_1 -> V_149 , V_482 ,
V_469 | V_483 ) < 0 ) {
F_320 ( V_227 ) ;
return - V_144 ;
}
F_319 ( V_7 , V_227 -> V_57 ) ;
return 0 ;
}
int F_323 ( struct V_1 * V_1 , T_1 * V_488 )
{
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_193 -> V_4 . V_4 . V_7 ;
struct V_227 * V_227 = F_147 ( V_193 -> V_4 . V_4 . V_228 ) ;
T_1 V_469 ;
int V_202 , V_131 ;
int V_481 = 6 ;
V_131 = F_321 ( V_1 ) ;
if ( V_131 )
return V_131 ;
do {
F_319 ( V_7 , V_227 -> V_57 ) ;
if ( F_318 ( & V_1 -> V_149 ,
V_484 , & V_469 ) < 0 ) {
V_131 = - V_144 ;
goto V_489;
}
V_202 = V_469 & V_485 ;
} while ( -- V_481 && V_202 == 0 );
if ( V_481 == 0 ) {
F_41 ( L_81 ) ;
V_131 = - V_145 ;
goto V_489;
}
if ( F_279 ( & V_1 -> V_149 , V_490 , V_488 , 6 ) < 0 ) {
V_131 = - V_144 ;
goto V_489;
}
V_489:
F_317 ( V_1 ) ;
return V_131 ;
}
static bool
F_324 ( struct V_1 * V_1 , T_1 * V_491 )
{
return F_279 ( & V_1 -> V_149 ,
V_492 ,
V_491 , 1 ) == 1 ;
}
static bool
F_325 ( struct V_1 * V_1 , T_1 * V_491 )
{
int V_131 ;
V_131 = F_279 ( & V_1 -> V_149 ,
V_493 ,
V_491 , 14 ) ;
if ( V_131 != 14 )
return false ;
return true ;
}
static T_3 F_326 ( struct V_1 * V_1 )
{
T_3 V_494 = V_495 ;
return V_494 ;
}
static T_3 F_327 ( struct V_1 * V_1 )
{
T_3 V_494 = V_496 ;
return V_494 ;
}
static T_3 F_328 ( struct V_1 * V_1 )
{
T_3 V_494 = V_496 ;
struct V_26 * V_26 = V_1 -> V_229 ;
struct V_8 * V_9 = & V_26 -> V_4 ;
if ( V_26 -> V_497 == NULL ||
V_9 -> V_498 ||
V_1 -> V_149 . V_499 > 6 ) {
if ( V_1 -> V_149 . V_500 > 0 ||
V_1 -> V_149 . V_499 > 0 )
F_34 ( L_82 ,
V_1 -> V_149 . V_500 ,
V_1 -> V_149 . V_499 ) ;
V_1 -> V_501 = V_502 ;
} else {
struct V_503 * V_504 = V_26 -> V_497 ;
V_504 += V_26 -> V_497 -> V_505 ;
if ( ! F_329 ( & V_1 -> V_149 ,
V_506 ,
& V_504 -> V_507 ,
1 ) )
F_34 ( L_83 ) ;
V_494 = V_495 | V_508 ;
V_1 -> V_501 = V_509 ;
}
V_1 -> V_510 = 1 ;
return V_494 ;
}
static T_3 F_330 ( struct V_1 * V_1 )
{
T_3 V_494 = V_496 ;
return V_494 ;
}
static void F_331 ( struct V_1 * V_1 )
{
T_3 V_511 = V_496 ;
T_3 V_512 = 0 ;
int V_106 = 0 ;
V_106 = F_279 ( & V_1 -> V_149 , V_513 , & V_512 , 1 ) ;
if ( V_106 <= 0 ) {
F_34 ( L_84 ) ;
goto V_514;
}
switch ( V_512 ) {
case V_515 :
F_34 ( L_85 ) ;
V_1 -> V_516 = V_515 ;
V_511 = F_326 ( V_1 ) ;
break;
case V_517 :
F_34 ( L_86 ) ;
V_1 -> V_516 = V_517 ;
V_511 = F_327 ( V_1 ) ;
break;
case V_518 :
F_34 ( L_87 ) ;
V_1 -> V_516 = V_518 ;
V_511 = F_328 ( V_1 ) ;
break;
case V_519 :
F_34 ( L_88 ) ;
V_1 -> V_516 = V_519 ;
V_511 = F_330 ( V_1 ) ;
break;
default:
F_34 ( L_89 , V_512 ) ;
break;
}
V_514:
V_106 = F_329 ( & V_1 -> V_149 ,
V_520 ,
& V_511 , 1 ) ;
if ( V_106 <= 0 )
F_34 ( L_90 ) ;
}
static int
F_332 ( struct V_1 * V_1 )
{
bool V_521 ;
if ( V_1 -> V_479 ) {
T_1 V_522 [ 16 ] = { 0 } ;
int V_131 = 0 ;
int V_523 ;
bool V_524 ;
V_521 = F_325 ( V_1 , V_522 ) ;
V_525:
if ( V_521 == true ) {
if ( V_1 -> V_526 &&
! F_333 ( & V_522 [ 10 ] , V_1 -> V_10 ) ) {
F_34 ( L_91 ) ;
F_242 ( V_1 ) ;
F_243 ( V_1 ) ;
}
F_34 ( L_92 , V_522 ) ;
V_131 = F_334 ( & V_1 -> V_480 , V_522 , & V_524 ) ;
if ( V_524 ) {
for ( V_523 = 0 ; V_523 < 3 ; V_523 ++ ) {
int V_527 ;
V_527 = F_329 ( & V_1 -> V_149 ,
V_493 + 1 ,
& V_522 [ 1 ] , 3 ) ;
if ( V_527 == 3 ) {
break;
}
}
V_521 = F_325 ( V_1 , V_522 ) ;
if ( V_521 == true ) {
F_34 ( L_93 , V_522 ) ;
goto V_525;
}
} else
V_131 = 0 ;
return V_131 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_34 ( L_94 ) ;
V_1 -> V_479 = false ;
F_316 ( & V_1 -> V_480 , V_1 -> V_479 ) ;
F_335 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_169 ;
}
static void
F_336 ( struct V_1 * V_1 )
{
struct V_49 * V_49 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_379 [ V_380 ] ;
F_47 ( ! F_337 ( & V_7 -> V_528 . V_529 ) ) ;
if ( ! F_278 ( V_1 , V_379 ) ) {
F_41 ( L_95 ) ;
return;
}
if ( ! V_49 -> V_4 . V_228 )
return;
if ( ! F_147 ( V_49 -> V_4 . V_228 ) -> V_530 )
return;
if ( ( V_1 -> V_516 == V_515 ) ||
( ! F_333 ( V_379 , V_1 -> V_10 ) ) ) {
F_34 ( L_96 ,
V_49 -> V_4 . V_184 ) ;
F_242 ( V_1 ) ;
F_243 ( V_1 ) ;
}
}
static bool
F_338 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_491 ;
T_1 V_531 = V_1 -> V_449 ;
bool V_131 ;
V_1 -> V_510 = 0 ;
V_1 -> V_516 = 0 ;
V_1 -> V_501 = 0 ;
V_131 = F_309 ( V_1 ) ;
if ( ( V_531 != V_1 -> V_449 ) || ! V_131 ) {
return false ;
}
if ( V_1 -> V_12 [ V_308 ] >= 0x11 &&
F_324 ( V_1 , & V_491 ) ) {
F_206 ( & V_1 -> V_149 ,
V_492 ,
V_491 ) ;
if ( V_491 & V_532 )
F_244 ( L_97 ) ;
if ( V_491 & ( V_533 | V_534 ) )
F_244 ( L_98 ) ;
}
F_339 ( & V_7 -> V_528 . V_529 , NULL ) ;
F_336 ( V_1 ) ;
F_340 ( & V_7 -> V_528 . V_529 ) ;
return true ;
}
static enum V_535
F_341 ( struct V_1 * V_1 )
{
T_3 * V_12 = V_1 -> V_12 ;
T_3 type ;
if ( ! F_309 ( V_1 ) )
return V_536 ;
if ( F_1 ( V_1 ) )
return V_537 ;
if ( ! ( V_12 [ V_464 ] & V_465 ) )
return V_537 ;
if ( V_1 -> V_12 [ V_308 ] >= 0x11 &&
V_1 -> V_467 [ 0 ] & V_538 ) {
return V_1 -> V_449 ?
V_537 : V_536 ;
}
if ( F_342 ( & V_1 -> V_149 . V_539 ) )
return V_537 ;
if ( V_1 -> V_12 [ V_308 ] >= 0x11 ) {
type = V_1 -> V_467 [ 0 ] & V_540 ;
if ( type == V_541 ||
type == V_542 )
return V_543 ;
} else {
type = V_1 -> V_12 [ V_464 ] &
V_544 ;
if ( type == V_545 ||
type == V_546 )
return V_543 ;
}
F_34 ( L_99 ) ;
return V_536 ;
}
static enum V_535
F_343 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_535 V_106 ;
V_106 = F_344 ( V_7 ) ;
if ( V_106 == V_543 )
V_106 = V_537 ;
return V_106 ;
}
static bool F_345 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_547 ;
switch ( V_68 -> V_68 ) {
case V_111 :
return true ;
case V_170 :
V_547 = V_548 ;
break;
case V_171 :
V_547 = V_549 ;
break;
case V_172 :
V_547 = V_550 ;
break;
default:
F_105 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_551 ) & V_547 ;
}
static bool F_346 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_547 ;
switch ( V_68 -> V_68 ) {
case V_111 :
return true ;
case V_170 :
V_547 = V_552 ;
break;
case V_171 :
V_547 = V_553 ;
break;
case V_172 :
V_547 = V_554 ;
break;
case V_177 :
V_547 = V_555 ;
break;
default:
F_105 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_551 ) & V_547 ;
}
static bool F_347 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_547 ;
switch ( V_68 -> V_68 ) {
case V_170 :
V_547 = V_556 ;
break;
case V_171 :
V_547 = V_557 ;
break;
case V_172 :
V_547 = V_558 ;
break;
default:
F_105 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_559 ) & V_547 ;
}
static bool F_348 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_547 ;
switch ( V_68 -> V_68 ) {
case V_170 :
V_547 = V_560 ;
break;
case V_171 :
V_547 = V_561 ;
break;
case V_172 :
V_547 = V_562 ;
break;
default:
F_105 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_559 ) & V_547 ;
}
static bool F_349 ( struct V_51 * V_52 ,
struct V_2 * V_3 )
{
struct V_49 * V_49 = & V_3 -> V_4 ;
enum V_68 V_68 ;
T_5 V_547 ;
F_350 ( V_49 -> V_563 , & V_68 ) ;
switch ( V_68 ) {
case V_111 :
V_547 = V_564 ;
break;
case V_170 :
V_547 = V_565 ;
break;
case V_171 :
V_547 = V_566 ;
break;
default:
F_105 ( V_68 ) ;
return false ;
}
return F_31 ( V_567 ) & V_547 ;
}
bool F_351 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
if ( F_306 ( V_52 ) )
return F_345 ( V_52 , V_68 ) ;
else if ( F_67 ( V_52 ) )
return F_346 ( V_52 , V_68 ) ;
else if ( F_65 ( V_52 ) )
return F_349 ( V_52 , V_68 ) ;
else if ( F_352 ( V_52 ) )
return F_348 ( V_52 , V_68 ) ;
else
return F_347 ( V_52 , V_68 ) ;
}
static struct V_503 *
F_353 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_229 ;
if ( V_26 -> V_503 ) {
if ( F_354 ( V_26 -> V_503 ) )
return NULL ;
return F_355 ( V_26 -> V_503 ) ;
} else
return F_356 ( & V_26 -> V_4 ,
& V_1 -> V_149 . V_539 ) ;
}
static void
F_357 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_229 ;
struct V_503 * V_503 ;
F_358 ( V_1 ) ;
V_503 = F_353 ( V_1 ) ;
V_26 -> V_497 = V_503 ;
if ( V_1 -> V_568 != V_569 )
V_1 -> V_239 = V_1 -> V_568 == V_570 ;
else
V_1 -> V_239 = F_359 ( V_503 ) ;
}
static void
F_358 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_229 ;
F_122 ( V_26 -> V_497 ) ;
V_26 -> V_497 = NULL ;
V_1 -> V_239 = false ;
}
static void
F_360 ( struct V_26 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_535 V_106 ;
enum V_54 V_55 ;
bool V_131 ;
T_1 V_491 ;
V_55 = F_22 ( V_49 ) ;
F_23 ( F_17 ( V_7 ) , V_55 ) ;
if ( F_1 ( V_1 ) )
V_106 = F_343 ( V_1 ) ;
else if ( F_351 ( F_17 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_106 = F_341 ( V_1 ) ;
else
V_106 = V_536 ;
if ( V_106 != V_537 ) {
V_1 -> V_510 = 0 ;
V_1 -> V_516 = 0 ;
V_1 -> V_501 = 0 ;
if ( V_1 -> V_479 ) {
F_34 ( L_100 ,
V_1 -> V_479 ,
V_1 -> V_480 . V_571 ) ;
V_1 -> V_479 = false ;
F_316 ( & V_1 -> V_480 ,
V_1 -> V_479 ) ;
}
goto V_138;
}
if ( V_49 -> type != V_5 )
V_49 -> type = V_572 ;
F_314 ( V_1 ) ;
V_131 = F_315 ( V_1 ) ;
if ( V_131 ) {
V_106 = V_536 ;
goto V_138;
} else if ( V_9 -> V_106 == V_537 ) {
F_339 ( & V_7 -> V_528 . V_529 , NULL ) ;
F_336 ( V_1 ) ;
F_340 ( & V_7 -> V_528 . V_529 ) ;
goto V_138;
}
V_1 -> V_149 . V_500 = 0 ;
V_1 -> V_149 . V_499 = 0 ;
F_357 ( V_1 ) ;
V_106 = V_537 ;
V_1 -> V_573 = true ;
if ( V_1 -> V_12 [ V_308 ] >= 0x11 &&
F_324 ( V_1 , & V_491 ) ) {
F_206 ( & V_1 -> V_149 ,
V_492 ,
V_491 ) ;
if ( V_491 & V_532 )
F_331 ( V_1 ) ;
if ( V_491 & ( V_533 | V_534 ) )
F_244 ( L_98 ) ;
}
V_138:
if ( ( V_106 != V_537 ) &&
( V_1 -> V_479 == false ) )
F_358 ( V_1 ) ;
F_27 ( F_17 ( V_7 ) , V_55 ) ;
return;
}
static enum V_535
F_361 ( struct V_8 * V_9 , bool V_574 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_26 * V_26 = F_16 ( V_9 ) ;
F_34 ( L_101 ,
V_9 -> V_4 . V_575 , V_9 -> V_184 ) ;
if ( V_1 -> V_479 ) {
F_358 ( V_1 ) ;
if ( V_49 -> type != V_5 )
V_49 -> type = V_572 ;
return V_536 ;
}
if ( ! V_1 -> V_573 )
F_360 ( V_1 -> V_229 ) ;
V_1 -> V_573 = false ;
if ( F_1 ( V_1 ) || V_26 -> V_497 )
return V_537 ;
else
return V_536 ;
}
static void
F_362 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_49 * V_49 = & F_2 ( V_1 ) -> V_4 ;
struct V_51 * V_52 = F_17 ( V_49 -> V_4 . V_7 ) ;
enum V_54 V_55 ;
F_34 ( L_101 ,
V_9 -> V_4 . V_575 , V_9 -> V_184 ) ;
F_358 ( V_1 ) ;
if ( V_9 -> V_106 != V_537 )
return;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
F_357 ( V_1 ) ;
F_27 ( V_52 , V_55 ) ;
if ( V_49 -> type != V_5 )
V_49 -> type = V_572 ;
}
static int F_363 ( struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
struct V_503 * V_503 ;
V_503 = V_26 -> V_497 ;
if ( V_503 ) {
int V_131 = F_364 ( V_9 , V_503 ) ;
if ( V_131 )
return V_131 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_26 -> V_28 . V_27 ) {
struct V_24 * V_25 ;
V_25 = F_365 ( V_9 -> V_7 ,
V_26 -> V_28 . V_27 ) ;
if ( V_25 ) {
F_366 ( V_9 , V_25 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_367 ( struct V_8 * V_9 )
{
bool V_239 = false ;
struct V_503 * V_503 ;
V_503 = F_16 ( V_9 ) -> V_497 ;
if ( V_503 )
V_239 = F_359 ( V_503 ) ;
return V_239 ;
}
static int
F_368 ( struct V_8 * V_9 ,
struct V_576 * V_577 ,
T_12 V_323 )
{
struct V_51 * V_52 = V_9 -> V_7 -> V_53 ;
struct V_26 * V_26 = F_16 ( V_9 ) ;
struct V_49 * V_49 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
int V_131 ;
V_131 = F_369 ( & V_9 -> V_4 , V_577 , V_323 ) ;
if ( V_131 )
return V_131 ;
if ( V_577 == V_52 -> V_578 ) {
int V_45 = V_323 ;
bool V_239 ;
if ( V_45 == V_1 -> V_568 )
return 0 ;
V_1 -> V_568 = V_45 ;
if ( V_45 == V_569 )
V_239 = F_367 ( V_9 ) ;
else
V_239 = ( V_45 == V_570 ) ;
if ( V_239 == V_1 -> V_239 )
return 0 ;
V_1 -> V_239 = V_239 ;
goto V_107;
}
if ( V_577 == V_52 -> V_579 ) {
bool V_580 = V_1 -> V_247 ;
bool V_581 = V_1 -> V_248 ;
switch ( V_323 ) {
case V_582 :
V_1 -> V_247 = true ;
break;
case V_583 :
V_1 -> V_247 = false ;
V_1 -> V_248 = false ;
break;
case V_584 :
V_1 -> V_247 = false ;
V_1 -> V_248 = true ;
break;
default:
return - V_169 ;
}
if ( V_580 == V_1 -> V_247 &&
V_581 == V_1 -> V_248 )
return 0 ;
goto V_107;
}
if ( F_1 ( V_1 ) &&
V_577 == V_9 -> V_7 -> V_528 . V_585 ) {
if ( V_323 == V_586 ) {
F_34 ( L_102 ) ;
return - V_169 ;
}
if ( F_151 ( V_52 ) &&
V_323 == V_587 ) {
F_34 ( L_103 ) ;
return - V_169 ;
}
if ( V_26 -> V_28 . V_240 == V_323 ) {
return 0 ;
}
V_26 -> V_28 . V_240 = V_323 ;
goto V_107;
}
return - V_169 ;
V_107:
if ( V_49 -> V_4 . V_228 )
F_370 ( V_49 -> V_4 . V_228 ) ;
return 0 ;
}
static void
F_371 ( struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
F_122 ( V_26 -> V_497 ) ;
if ( ! F_372 ( V_26 -> V_503 ) )
F_122 ( V_26 -> V_503 ) ;
if ( V_9 -> V_588 == V_589 )
F_373 ( & V_26 -> V_28 ) ;
F_374 ( V_9 ) ;
F_122 ( V_9 ) ;
}
void F_375 ( struct V_590 * V_50 )
{
struct V_2 * V_3 = F_228 ( V_50 ) ;
struct V_1 * V_1 = & V_3 -> V_591 ;
F_376 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_377 ( & V_1 -> V_290 ) ;
F_21 ( V_1 ) ;
F_176 ( V_1 ) ;
F_25 ( V_1 ) ;
if ( V_1 -> V_94 . V_592 ) {
F_378 ( & V_1 -> V_94 ) ;
V_1 -> V_94 . V_592 = NULL ;
}
}
F_379 ( V_50 ) ;
F_122 ( V_3 ) ;
}
void F_380 ( struct V_49 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_377 ( & V_1 -> V_290 ) ;
F_21 ( V_1 ) ;
F_176 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_381 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_76 ( V_1 ) )
return;
F_34 ( L_104 ) ;
V_55 = F_22 ( & V_3 -> V_4 ) ;
F_23 ( V_52 , V_55 ) ;
F_179 ( V_1 ) ;
}
void F_382 ( struct V_590 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_50 ) ;
if ( ! F_148 ( V_52 ) )
V_1 -> V_65 = F_31 ( V_1 -> V_66 ) ;
if ( F_383 ( V_50 ) -> type != V_5 )
return;
F_21 ( V_1 ) ;
if ( F_63 ( V_50 -> V_7 ) || F_36 ( V_50 -> V_7 ) )
F_61 ( V_1 ) ;
F_381 ( V_1 ) ;
F_25 ( V_1 ) ;
}
enum V_593
F_384 ( struct V_2 * V_3 , bool V_594 )
{
struct V_1 * V_1 = & V_3 -> V_591 ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
enum V_593 V_131 = V_595 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_596 )
V_3 -> V_4 . type = V_572 ;
if ( V_594 && V_3 -> V_4 . type == V_5 ) {
F_34 ( L_105 ,
F_33 ( V_3 -> V_68 ) ) ;
return V_597 ;
}
F_34 ( L_106 ,
F_33 ( V_3 -> V_68 ) ,
V_594 ? L_107 : L_108 ) ;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
if ( V_594 ) {
F_360 ( V_1 -> V_229 ) ;
if ( V_1 -> V_479 )
V_131 = V_597 ;
goto V_598;
} else {
if ( V_1 -> V_479 ) {
if ( F_332 ( V_1 ) == - V_169 ) {
F_34 ( L_100 ,
V_1 -> V_479 , V_1 -> V_480 . V_571 ) ;
V_1 -> V_479 = false ;
F_316 ( & V_1 -> V_480 ,
V_1 -> V_479 ) ;
goto V_598;
}
}
if ( ! V_1 -> V_479 ) {
if ( ! F_338 ( V_1 ) ) {
F_360 ( V_1 -> V_229 ) ;
goto V_598;
}
}
}
V_131 = V_597 ;
V_598:
F_27 ( V_52 , V_55 ) ;
return V_131 ;
}
bool F_385 ( struct V_6 * V_7 , enum V_68 V_68 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
if ( F_116 ( V_7 ) -> V_183 < 5 )
return false ;
if ( V_68 == V_111 )
return true ;
return F_386 ( V_52 , V_68 ) ;
}
void
F_387 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
F_388 ( V_9 ) ;
F_389 ( V_9 ) ;
V_1 -> V_247 = true ;
if ( F_1 ( V_1 ) ) {
F_390 ( V_9 -> V_7 ) ;
F_391 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_528 . V_585 ,
V_599 ) ;
V_26 -> V_28 . V_240 = V_599 ;
}
}
static void F_392 ( struct V_1 * V_1 )
{
V_1 -> V_277 = F_167 () ;
V_1 -> V_281 = V_278 ;
V_1 -> V_283 = V_278 ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_600 V_601 , V_175 , V_602 ,
* V_603 = & V_1 -> V_604 ;
T_5 V_605 , V_606 , V_98 = 0 , V_607 = 0 ;
T_6 V_96 , V_352 , V_608 , V_97 ;
F_46 ( & V_52 -> V_56 ) ;
if ( V_603 -> V_609 != 0 )
return;
if ( F_65 ( V_7 ) ) {
V_96 = F_66 ( 0 ) ;
V_352 = F_393 ( 0 ) ;
V_608 = F_394 ( 0 ) ;
} else if ( F_67 ( V_7 ) ) {
V_96 = V_88 ;
V_352 = V_610 ;
V_608 = V_611 ;
V_97 = V_612 ;
} else {
enum V_57 V_57 = F_45 ( V_1 ) ;
V_96 = F_56 ( V_57 ) ;
V_352 = F_59 ( V_57 ) ;
V_608 = F_395 ( V_57 ) ;
V_97 = F_73 ( V_57 ) ;
}
V_607 = F_172 ( V_1 ) ;
V_605 = F_31 ( V_352 ) ;
V_606 = F_31 ( V_608 ) ;
if ( ! F_65 ( V_7 ) ) {
F_42 ( V_96 , V_607 ) ;
V_98 = F_31 ( V_97 ) ;
}
V_601 . V_613 = ( V_605 & V_614 ) >>
V_615 ;
V_601 . V_616 = ( V_605 & V_617 ) >>
V_618 ;
V_601 . V_619 = ( V_606 & V_620 ) >>
V_621 ;
V_601 . V_622 = ( V_606 & V_623 ) >>
V_624 ;
if ( F_65 ( V_7 ) ) {
T_13 V_82 = ( V_607 & V_625 ) >>
V_626 ;
if ( V_82 > 0 )
V_601 . V_609 = ( V_82 - 1 ) * 1000 ;
else
V_601 . V_609 = 0 ;
} else {
V_601 . V_609 = ( ( V_98 & V_627 ) >>
V_628 ) * 1000 ;
}
F_34 ( L_109 ,
V_601 . V_613 , V_601 . V_616 , V_601 . V_619 , V_601 . V_622 , V_601 . V_609 ) ;
V_175 = V_52 -> V_175 . V_245 . V_629 ;
V_602 . V_613 = 210 * 10 ;
V_602 . V_616 = 50 * 10 ;
V_602 . V_619 = 50 * 10 ;
V_602 . V_622 = 500 * 10 ;
V_602 . V_609 = ( 510 + 100 ) * 10 ;
F_34 ( L_110 ,
V_175 . V_613 , V_175 . V_616 , V_175 . V_619 , V_175 . V_622 , V_175 . V_609 ) ;
#define F_396 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_396 ( V_613 ) ;
F_396 ( V_616 ) ;
F_396 ( V_619 ) ;
F_396 ( V_622 ) ;
F_396 ( V_609 ) ;
#undef F_396
#define F_397 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_291 = F_397 ( V_613 ) ;
V_1 -> V_282 = F_397 ( V_616 ) ;
V_1 -> V_284 = F_397 ( V_619 ) ;
V_1 -> V_446 = F_397 ( V_622 ) ;
V_1 -> V_102 = F_397 ( V_609 ) ;
#undef F_397
F_34 ( L_111 ,
V_1 -> V_291 , V_1 -> V_446 ,
V_1 -> V_102 ) ;
F_34 ( L_112 ,
V_1 -> V_282 , V_1 -> V_284 ) ;
}
static void
F_52 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_605 , V_606 , V_98 , V_86 = 0 ;
int div = V_52 -> V_110 / 1000 ;
T_6 V_352 , V_608 , V_97 , V_96 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
const struct V_600 * V_630 = & V_1 -> V_604 ;
F_46 ( & V_52 -> V_56 ) ;
if ( F_65 ( V_7 ) ) {
V_96 = F_66 ( 0 ) ;
V_352 = F_393 ( 0 ) ;
V_608 = F_394 ( 0 ) ;
} else if ( F_67 ( V_7 ) ) {
V_352 = V_610 ;
V_608 = V_611 ;
V_97 = V_612 ;
} else {
enum V_57 V_57 = F_45 ( V_1 ) ;
V_352 = F_59 ( V_57 ) ;
V_608 = F_395 ( V_57 ) ;
V_97 = F_73 ( V_57 ) ;
}
V_605 = ( V_630 -> V_613 << V_615 ) |
( 1 << V_618 ) ;
V_606 = ( 1 << V_621 ) |
( V_630 -> V_622 << V_624 ) ;
if ( F_65 ( V_7 ) ) {
V_98 = F_31 ( V_96 ) ;
V_98 &= ~ V_625 ;
V_98 |= ( F_398 ( ( V_630 -> V_609 + 1 ) , 1000 )
<< V_626 ) ;
} else {
V_98 = ( ( 100 * div ) / 2 - 1 ) << V_631 ;
V_98 |= ( F_398 ( V_630 -> V_609 , 1000 )
<< V_628 ) ;
}
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
V_86 = F_60 ( V_68 ) ;
} else if ( F_306 ( V_7 ) || F_160 ( V_7 ) ) {
if ( V_68 == V_111 )
V_86 = V_632 ;
else
V_86 = V_633 ;
}
V_605 |= V_86 ;
F_42 ( V_352 , V_605 ) ;
F_42 ( V_608 , V_606 ) ;
if ( F_65 ( V_7 ) )
F_42 ( V_96 , V_98 ) ;
else
F_42 ( V_97 , V_98 ) ;
F_34 ( L_113 ,
F_31 ( V_352 ) ,
F_31 ( V_608 ) ,
F_65 ( V_7 ) ?
( F_31 ( V_96 ) & V_625 ) :
F_31 ( V_97 ) ) ;
}
static void F_399 ( struct V_6 * V_7 , int V_634 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_49 * V_50 ;
struct V_2 * V_193 = NULL ;
struct V_1 * V_1 = V_52 -> V_251 . V_591 ;
struct V_198 * V_255 = NULL ;
struct V_227 * V_227 = NULL ;
enum V_635 V_109 = V_636 ;
if ( V_634 <= 0 ) {
F_34 ( L_114 ) ;
return;
}
if ( V_1 == NULL ) {
F_34 ( L_115 ) ;
return;
}
V_193 = F_2 ( V_1 ) ;
V_50 = & V_193 -> V_4 ;
V_227 = F_147 ( V_50 -> V_4 . V_228 ) ;
if ( ! V_227 ) {
F_34 ( L_116 ) ;
return;
}
V_255 = V_227 -> V_255 ;
if ( V_52 -> V_251 . type < V_252 ) {
F_34 ( L_117 ) ;
return;
}
if ( V_1 -> V_229 -> V_28 . V_250 -> V_637 ==
V_634 )
V_109 = V_638 ;
if ( V_109 == V_52 -> V_251 . V_639 ) {
F_34 (
L_118 ) ;
return;
}
if ( ! V_227 -> V_530 ) {
F_34 ( L_119 ) ;
return;
}
if ( F_116 ( V_7 ) -> V_183 >= 8 && ! F_36 ( V_7 ) ) {
switch ( V_109 ) {
case V_636 :
F_400 ( V_227 , V_640 ) ;
break;
case V_638 :
F_400 ( V_227 , V_641 ) ;
break;
case V_642 :
default:
F_41 ( L_120 ) ;
}
} else if ( F_116 ( V_7 ) -> V_183 > 6 ) {
T_6 V_643 = F_401 ( V_227 -> V_255 -> V_644 ) ;
T_5 V_323 ;
V_323 = F_31 ( V_643 ) ;
if ( V_109 > V_636 ) {
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
V_323 |= V_645 ;
else
V_323 |= V_646 ;
} else {
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
V_323 &= ~ V_645 ;
else
V_323 &= ~ V_646 ;
}
F_42 ( V_643 , V_323 ) ;
}
V_52 -> V_251 . V_639 = V_109 ;
F_34 ( L_121 , V_634 ) ;
}
void F_402 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_647 * V_228 = V_193 -> V_4 . V_4 . V_228 ;
struct V_227 * V_227 = F_147 ( V_228 ) ;
if ( ! V_227 -> V_255 -> V_238 ) {
F_34 ( L_122 ) ;
return;
}
F_24 ( & V_52 -> V_251 . V_648 ) ;
if ( F_47 ( V_52 -> V_251 . V_591 ) ) {
F_41 ( L_123 ) ;
goto V_649;
}
V_52 -> V_251 . V_650 = 0 ;
V_52 -> V_251 . V_591 = V_1 ;
V_649:
F_26 ( & V_52 -> V_251 . V_648 ) ;
}
void F_403 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_193 = F_2 ( V_1 ) ;
struct V_647 * V_228 = V_193 -> V_4 . V_4 . V_228 ;
struct V_227 * V_227 = F_147 ( V_228 ) ;
if ( ! V_227 -> V_255 -> V_238 )
return;
F_24 ( & V_52 -> V_251 . V_648 ) ;
if ( ! V_52 -> V_251 . V_591 ) {
F_26 ( & V_52 -> V_251 . V_648 ) ;
return;
}
if ( V_52 -> V_251 . V_639 == V_638 )
F_399 ( V_52 -> V_7 ,
V_1 -> V_229 -> V_28 .
V_27 -> V_637 ) ;
V_52 -> V_251 . V_591 = NULL ;
F_26 ( & V_52 -> V_251 . V_648 ) ;
F_377 ( & V_52 -> V_251 . V_651 ) ;
}
static void F_404 ( struct V_293 * V_651 )
{
struct V_51 * V_52 =
F_71 ( V_651 , F_72 ( * V_52 ) , V_251 . V_651 . V_651 ) ;
struct V_1 * V_1 ;
F_24 ( & V_52 -> V_251 . V_648 ) ;
V_1 = V_52 -> V_251 . V_591 ;
if ( ! V_1 )
goto V_649;
if ( V_52 -> V_251 . V_650 )
goto V_649;
if ( V_52 -> V_251 . V_639 != V_638 )
F_399 ( V_52 -> V_7 ,
V_1 -> V_229 -> V_28 .
V_250 -> V_637 ) ;
V_649:
F_26 ( & V_52 -> V_251 . V_648 ) ;
}
void F_405 ( struct V_6 * V_7 ,
unsigned V_652 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_647 * V_228 ;
enum V_57 V_57 ;
if ( V_52 -> V_251 . type == V_653 )
return;
F_173 ( & V_52 -> V_251 . V_651 ) ;
F_24 ( & V_52 -> V_251 . V_648 ) ;
if ( ! V_52 -> V_251 . V_591 ) {
F_26 ( & V_52 -> V_251 . V_648 ) ;
return;
}
V_228 = F_2 ( V_52 -> V_251 . V_591 ) -> V_4 . V_4 . V_228 ;
V_57 = F_147 ( V_228 ) -> V_57 ;
V_652 &= F_406 ( V_57 ) ;
V_52 -> V_251 . V_650 |= V_652 ;
if ( V_652 && V_52 -> V_251 . V_639 == V_638 )
F_399 ( V_52 -> V_7 ,
V_52 -> V_251 . V_591 -> V_229 -> V_28 .
V_27 -> V_637 ) ;
F_26 ( & V_52 -> V_251 . V_648 ) ;
}
void F_407 ( struct V_6 * V_7 ,
unsigned V_652 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_647 * V_228 ;
enum V_57 V_57 ;
if ( V_52 -> V_251 . type == V_653 )
return;
F_173 ( & V_52 -> V_251 . V_651 ) ;
F_24 ( & V_52 -> V_251 . V_648 ) ;
if ( ! V_52 -> V_251 . V_591 ) {
F_26 ( & V_52 -> V_251 . V_648 ) ;
return;
}
V_228 = F_2 ( V_52 -> V_251 . V_591 ) -> V_4 . V_4 . V_228 ;
V_57 = F_147 ( V_228 ) -> V_57 ;
V_652 &= F_406 ( V_57 ) ;
V_52 -> V_251 . V_650 &= ~ V_652 ;
if ( V_652 && V_52 -> V_251 . V_639 == V_638 )
F_399 ( V_52 -> V_7 ,
V_52 -> V_251 . V_591 -> V_229 -> V_28 .
V_27 -> V_637 ) ;
if ( ! V_52 -> V_251 . V_650 )
F_181 ( & V_52 -> V_251 . V_651 ,
F_180 ( 1000 ) ) ;
F_26 ( & V_52 -> V_251 . V_648 ) ;
}
static struct V_24 *
F_408 ( struct V_26 * V_26 ,
struct V_24 * V_27 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_250 = NULL ;
F_409 ( & V_52 -> V_251 . V_651 , F_404 ) ;
F_410 ( & V_52 -> V_251 . V_648 ) ;
if ( F_116 ( V_7 ) -> V_183 <= 6 ) {
F_34 ( L_124 ) ;
return NULL ;
}
if ( V_52 -> V_175 . V_654 != V_252 ) {
F_34 ( L_125 ) ;
return NULL ;
}
V_250 = F_411
( V_7 , V_27 , V_9 ) ;
if ( ! V_250 ) {
F_34 ( L_126 ) ;
return NULL ;
}
V_52 -> V_251 . type = V_52 -> V_175 . V_654 ;
V_52 -> V_251 . V_639 = V_636 ;
F_34 ( L_127 ) ;
return V_250 ;
}
static bool F_412 ( struct V_1 * V_1 ,
struct V_26 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_27 = NULL ;
struct V_24 * V_250 = NULL ;
bool V_655 ;
struct V_24 * V_656 ;
struct V_503 * V_503 ;
enum V_57 V_57 = V_81 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_21 ( V_1 ) ;
F_381 ( V_1 ) ;
F_25 ( V_1 ) ;
V_655 = F_309 ( V_1 ) ;
if ( V_655 ) {
if ( V_1 -> V_12 [ V_308 ] >= 0x11 )
V_52 -> V_657 =
V_1 -> V_12 [ V_658 ] &
V_659 ;
} else {
F_413 ( L_128 ) ;
return false ;
}
F_21 ( V_1 ) ;
F_52 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
F_24 ( & V_7 -> V_528 . V_648 ) ;
V_503 = F_356 ( V_9 , & V_1 -> V_149 . V_539 ) ;
if ( V_503 ) {
if ( F_414 ( V_9 , V_503 ) ) {
F_415 ( V_9 ,
V_503 ) ;
F_416 ( V_9 , V_503 ) ;
} else {
F_122 ( V_503 ) ;
V_503 = F_417 ( - V_169 ) ;
}
} else {
V_503 = F_417 ( - V_660 ) ;
}
V_26 -> V_503 = V_503 ;
F_418 (scan, &connector->probed_modes, head) {
if ( ( V_656 -> type & V_661 ) ) {
V_27 = F_365 ( V_7 , V_656 ) ;
V_250 = F_408 (
V_26 , V_27 ) ;
break;
}
}
if ( ! V_27 && V_52 -> V_175 . V_662 ) {
V_27 = F_365 ( V_7 ,
V_52 -> V_175 . V_662 ) ;
if ( V_27 ) {
V_27 -> type |= V_661 ;
V_9 -> V_243 . V_663 = V_27 -> V_663 ;
V_9 -> V_243 . V_664 = V_27 -> V_664 ;
}
}
F_26 ( & V_7 -> V_528 . V_648 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
V_1 -> V_94 . V_592 = F_70 ;
F_419 ( & V_1 -> V_94 ) ;
if ( F_36 ( V_7 ) )
V_57 = F_214 ( V_1 -> V_65 ) ;
else
V_57 = F_215 ( V_1 -> V_65 ) ;
if ( V_57 != V_80 && V_57 != V_73 )
V_57 = V_1 -> V_58 ;
if ( V_57 != V_80 && V_57 != V_73 )
V_57 = V_80 ;
F_34 ( L_129 ,
F_32 ( V_57 ) ) ;
}
F_420 ( & V_26 -> V_28 , V_27 , V_250 ) ;
V_26 -> V_28 . V_665 . V_666 = F_193 ;
F_421 ( V_9 , V_57 ) ;
return true ;
}
bool
F_422 ( struct V_2 * V_3 ,
struct V_26 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_591 ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
int type , V_131 ;
if ( F_9 ( V_3 -> V_19 < 1 ,
L_130 ,
V_3 -> V_19 , F_33 ( V_68 ) ) )
return false ;
V_1 -> V_58 = V_81 ;
if ( F_116 ( V_7 ) -> V_183 >= 9 )
V_1 -> V_140 = F_88 ;
else if ( F_131 ( V_7 ) || F_91 ( V_7 ) )
V_1 -> V_140 = F_86 ;
else if ( F_67 ( V_7 ) )
V_1 -> V_140 = F_85 ;
else
V_1 -> V_140 = F_83 ;
if ( F_116 ( V_7 ) -> V_183 >= 9 )
V_1 -> V_142 = F_92 ;
else
V_1 -> V_142 = F_89 ;
if ( F_148 ( V_7 ) )
V_1 -> V_667 = V_668 ;
V_1 -> V_65 = F_31 ( V_1 -> V_66 ) ;
V_1 -> V_229 = V_26 ;
if ( F_385 ( V_7 , V_68 ) )
type = V_589 ;
else
type = V_669 ;
if ( type == V_589 )
V_49 -> type = V_5 ;
if ( F_47 ( ( F_63 ( V_7 ) || F_36 ( V_7 ) ) &&
F_1 ( V_1 ) && V_68 != V_170 && V_68 != V_171 ) )
return false ;
F_34 ( L_131 ,
type == V_589 ? L_132 : L_133 ,
F_33 ( V_68 ) ) ;
F_423 ( V_7 , V_9 , & V_670 , type ) ;
F_424 ( V_9 , & V_671 ) ;
V_9 -> V_672 = true ;
V_9 -> V_673 = 0 ;
F_409 ( & V_1 -> V_290 ,
F_177 ) ;
F_425 ( V_26 , V_49 ) ;
F_426 ( V_9 ) ;
if ( F_148 ( V_7 ) )
V_26 -> V_674 = V_675 ;
else
V_26 -> V_674 = V_676 ;
V_26 -> V_677 = F_126 ;
switch ( V_68 ) {
case V_111 :
V_49 -> V_563 = V_678 ;
break;
case V_170 :
V_49 -> V_563 = V_679 ;
if ( F_427 ( V_7 , 0 , V_680 ) )
V_49 -> V_563 = V_678 ;
break;
case V_171 :
V_49 -> V_563 = V_681 ;
break;
case V_172 :
V_49 -> V_563 = V_682 ;
break;
case V_177 :
V_49 -> V_563 = V_683 ;
break;
default:
F_428 () ;
}
if ( F_1 ( V_1 ) ) {
F_21 ( V_1 ) ;
F_392 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
F_61 ( V_1 ) ;
else
F_51 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
}
V_131 = F_123 ( V_1 , V_26 ) ;
if ( V_131 )
goto V_684;
if ( F_429 ( V_7 ) &&
( V_68 == V_170 || V_68 == V_171 || V_68 == V_172 ) )
F_430 ( V_3 ,
V_26 -> V_4 . V_4 . V_575 ) ;
if ( ! F_412 ( V_1 , V_26 ) ) {
F_120 ( V_1 ) ;
F_376 ( V_3 ) ;
goto V_684;
}
F_387 ( V_1 , V_9 ) ;
if ( F_137 ( V_7 ) && ! F_352 ( V_7 ) ) {
T_5 V_330 = F_31 ( V_685 ) ;
F_42 ( V_685 , ( V_330 & ~ 0xf ) | 0xd ) ;
}
F_431 ( V_9 ) ;
return true ;
V_684:
if ( F_1 ( V_1 ) ) {
F_377 ( & V_1 -> V_290 ) ;
F_21 ( V_1 ) ;
F_176 ( V_1 ) ;
F_25 ( V_1 ) ;
}
F_432 ( V_9 ) ;
F_374 ( V_9 ) ;
return false ;
}
bool F_433 ( struct V_6 * V_7 ,
T_6 V_66 ,
enum V_68 V_68 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 ;
struct V_49 * V_49 ;
struct V_590 * V_50 ;
struct V_26 * V_26 ;
V_3 = F_434 ( sizeof( * V_3 ) , V_185 ) ;
if ( ! V_3 )
return false ;
V_26 = F_435 () ;
if ( ! V_26 )
goto V_686;
V_49 = & V_3 -> V_4 ;
V_50 = & V_49 -> V_4 ;
if ( F_436 ( V_7 , & V_49 -> V_4 , & V_687 ,
V_688 , NULL ) )
goto V_689;
V_49 -> V_690 = F_146 ;
V_49 -> V_691 = F_219 ;
V_49 -> V_674 = F_207 ;
V_49 -> V_692 = F_216 ;
V_49 -> V_693 = F_380 ;
if ( F_36 ( V_7 ) ) {
V_49 -> V_694 = F_273 ;
V_49 -> V_695 = F_262 ;
V_49 -> V_299 = F_247 ;
V_49 -> V_696 = F_235 ;
V_49 -> V_697 = F_277 ;
} else if ( F_63 ( V_7 ) ) {
V_49 -> V_694 = F_256 ;
V_49 -> V_695 = F_251 ;
V_49 -> V_299 = F_247 ;
V_49 -> V_696 = F_225 ;
} else {
V_49 -> V_695 = F_249 ;
V_49 -> V_299 = F_246 ;
if ( F_116 ( V_7 ) -> V_183 >= 5 )
V_49 -> V_696 = F_224 ;
}
V_3 -> V_68 = V_68 ;
V_3 -> V_591 . V_66 = V_66 ;
V_3 -> V_19 = 4 ;
V_49 -> type = V_572 ;
if ( F_36 ( V_7 ) ) {
if ( V_68 == V_172 )
V_49 -> V_698 = 1 << 2 ;
else
V_49 -> V_698 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_49 -> V_698 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_49 -> V_699 = 0 ;
V_3 -> V_700 = F_384 ;
V_52 -> V_701 . V_702 [ V_68 ] = V_3 ;
if ( ! F_422 ( V_3 , V_26 ) )
goto V_703;
return true ;
V_703:
F_379 ( V_50 ) ;
V_689:
F_122 ( V_26 ) ;
V_686:
F_122 ( V_3 ) ;
return false ;
}
void F_437 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_704 ; V_45 ++ ) {
struct V_2 * V_3 = V_52 -> V_701 . V_702 [ V_45 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_572 ) {
if ( ! V_3 -> V_591 . V_476 )
continue;
if ( V_3 -> V_591 . V_479 )
F_438 ( & V_3 -> V_591 . V_480 ) ;
}
}
}
void F_439 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_704 ; V_45 ++ ) {
struct V_2 * V_3 = V_52 -> V_701 . V_702 [ V_45 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_572 ) {
int V_131 ;
if ( ! V_3 -> V_591 . V_476 )
continue;
V_131 = F_440 ( & V_3 -> V_591 . V_480 ) ;
if ( V_131 != 0 ) {
F_332 ( & V_3 -> V_591 ) ;
}
}
}
}
