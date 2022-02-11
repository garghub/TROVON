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
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_109 ? 0 : F_84 ( F_85 ( V_7 ) , 2 ) ;
}
static T_2 F_86 ( struct V_1 * V_1 , int V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( V_109 )
return 0 ;
if ( V_3 -> V_68 == V_110 ) {
return F_84 ( V_52 -> V_111 , 2000 ) ;
} else {
return F_84 ( F_87 ( V_7 ) , 2 ) ;
}
}
static T_2 F_88 ( struct V_1 * V_1 , int V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( V_3 -> V_68 == V_110 ) {
if ( V_109 )
return 0 ;
return F_84 ( V_52 -> V_111 , 2000 ) ;
} else if ( F_89 ( V_52 ) ) {
switch ( V_109 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_109 ? 0 : F_84 ( F_87 ( V_7 ) , 2 ) ;
}
}
static T_2 F_90 ( struct V_1 * V_1 , int V_109 )
{
return V_109 ? 0 : 100 ;
}
static T_2 F_91 ( struct V_1 * V_1 , int V_109 )
{
return V_109 ? 0 : 1 ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
bool V_103 ,
int V_112 ,
T_2 V_113 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_114 , V_115 ;
if ( F_93 ( V_7 ) )
V_114 = 3 ;
else
V_114 = 5 ;
if ( F_94 ( V_7 ) && V_3 -> V_68 == V_110 )
V_115 = V_116 ;
else
V_115 = V_117 ;
return V_118 |
V_119 |
( V_103 ? V_120 : 0 ) |
V_121 |
V_115 |
V_122 |
( V_112 << V_123 ) |
( V_114 << V_124 ) |
( V_113 << V_125 ) ;
}
static T_2 F_95 ( struct V_1 * V_1 ,
bool V_103 ,
int V_112 ,
T_2 V_93 )
{
return V_118 |
V_119 |
( V_103 ? V_120 : 0 ) |
V_121 |
V_126 |
V_122 |
( V_112 << V_123 ) |
F_96 ( 32 ) ;
}
static int
F_97 ( struct V_1 * V_1 ,
const T_3 * V_127 , int V_112 ,
T_3 * V_128 , int V_129 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_6 V_104 = V_1 -> V_105 ;
T_2 V_113 ;
int V_45 , V_130 , V_131 ;
T_2 V_106 ;
int V_132 , clock = 0 ;
bool V_103 = F_98 ( V_7 ) ;
bool V_133 ;
F_21 ( V_1 ) ;
V_133 = F_99 ( V_1 ) ;
F_100 ( & V_52 -> V_134 , 0 ) ;
F_77 ( V_1 ) ;
for ( V_132 = 0 ; V_132 < 3 ; V_132 ++ ) {
V_106 = F_101 ( V_104 ) ;
if ( ( V_106 & V_118 ) == 0 )
break;
F_74 ( 1 ) ;
}
if ( V_132 == 3 ) {
static T_5 V_135 = - 1 ;
const T_5 V_106 = F_31 ( V_104 ) ;
if ( V_106 != V_135 ) {
F_9 ( 1 , L_11 ,
V_106 ) ;
V_135 = V_106 ;
}
V_130 = - V_136 ;
goto V_137;
}
if ( F_47 ( V_112 > 20 || V_129 > 20 ) ) {
V_130 = - V_138 ;
goto V_137;
}
while ( ( V_113 = V_1 -> V_139 ( V_1 , clock ++ ) ) ) {
T_5 V_140 = V_1 -> V_141 ( V_1 ,
V_103 ,
V_112 ,
V_113 ) ;
for ( V_132 = 0 ; V_132 < 5 ; V_132 ++ ) {
for ( V_45 = 0 ; V_45 < V_112 ; V_45 += 4 )
F_42 ( V_1 -> V_142 [ V_45 >> 2 ] ,
F_19 ( V_127 + V_45 ,
V_112 - V_45 ) ) ;
F_42 ( V_104 , V_140 ) ;
V_106 = F_78 ( V_1 , V_103 ) ;
F_42 ( V_104 ,
V_106 |
V_119 |
V_121 |
V_122 ) ;
if ( V_106 & V_121 )
continue;
if ( V_106 & V_122 ) {
F_102 ( 400 , 500 ) ;
continue;
}
if ( V_106 & V_119 )
goto V_107;
}
}
if ( ( V_106 & V_119 ) == 0 ) {
F_41 ( L_12 , V_106 ) ;
V_130 = - V_136 ;
goto V_137;
}
V_107:
if ( V_106 & V_122 ) {
F_41 ( L_13 , V_106 ) ;
V_130 = - V_143 ;
goto V_137;
}
if ( V_106 & V_121 ) {
F_34 ( L_14 , V_106 ) ;
V_130 = - V_144 ;
goto V_137;
}
V_131 = ( ( V_106 & V_145 ) >>
V_123 ) ;
if ( V_131 == 0 || V_131 > 20 ) {
F_34 ( L_15 ,
V_131 ) ;
F_102 ( 1000 , 1500 ) ;
V_130 = - V_136 ;
goto V_137;
}
if ( V_131 > V_129 )
V_131 = V_129 ;
for ( V_45 = 0 ; V_45 < V_131 ; V_45 += 4 )
F_20 ( F_31 ( V_1 -> V_142 [ V_45 >> 2 ] ) ,
V_128 + V_45 , V_131 - V_45 ) ;
V_130 = V_131 ;
V_137:
F_100 ( & V_52 -> V_134 , V_146 ) ;
if ( V_133 )
F_103 ( V_1 , false ) ;
F_25 ( V_1 ) ;
return V_130 ;
}
static T_7
F_104 ( struct V_147 * V_148 , struct V_149 * V_150 )
{
struct V_1 * V_1 = F_71 ( V_148 , struct V_1 , V_148 ) ;
T_3 V_151 [ 20 ] , V_152 [ 20 ] ;
T_8 V_153 , V_154 ;
int V_130 ;
V_151 [ 0 ] = ( V_150 -> V_155 << 4 ) |
( ( V_150 -> V_156 >> 16 ) & 0xf ) ;
V_151 [ 1 ] = ( V_150 -> V_156 >> 8 ) & 0xff ;
V_151 [ 2 ] = V_150 -> V_156 & 0xff ;
V_151 [ 3 ] = V_150 -> V_157 - 1 ;
switch ( V_150 -> V_155 & ~ V_158 ) {
case V_159 :
case V_160 :
case V_161 :
V_153 = V_150 -> V_157 ? V_162 + V_150 -> V_157 : V_163 ;
V_154 = 2 ;
if ( F_47 ( V_153 > 20 ) )
return - V_138 ;
if ( V_150 -> V_164 )
memcpy ( V_151 + V_162 , V_150 -> V_164 , V_150 -> V_157 ) ;
else
F_47 ( V_150 -> V_157 ) ;
V_130 = F_97 ( V_1 , V_151 , V_153 , V_152 , V_154 ) ;
if ( V_130 > 0 ) {
V_150 -> V_165 = V_152 [ 0 ] >> 4 ;
if ( V_130 > 1 ) {
V_130 = F_105 ( int , V_152 [ 1 ] , 0 , V_150 -> V_157 ) ;
} else {
V_130 = V_150 -> V_157 ;
}
}
break;
case V_166 :
case V_167 :
V_153 = V_150 -> V_157 ? V_162 : V_163 ;
V_154 = V_150 -> V_157 + 1 ;
if ( F_47 ( V_154 > 20 ) )
return - V_138 ;
V_130 = F_97 ( V_1 , V_151 , V_153 , V_152 , V_154 ) ;
if ( V_130 > 0 ) {
V_150 -> V_165 = V_152 [ 0 ] >> 4 ;
V_130 -- ;
memcpy ( V_150 -> V_164 , V_152 + 1 , V_130 ) ;
}
break;
default:
V_130 = - V_168 ;
break;
}
return V_130 ;
}
static T_6 F_106 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
switch ( V_68 ) {
case V_169 :
case V_170 :
case V_171 :
return F_107 ( V_68 ) ;
default:
F_108 ( V_68 ) ;
return F_107 ( V_169 ) ;
}
}
static T_6 F_109 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
switch ( V_68 ) {
case V_169 :
case V_170 :
case V_171 :
return F_110 ( V_68 , V_109 ) ;
default:
F_108 ( V_68 ) ;
return F_110 ( V_169 , V_109 ) ;
}
}
static T_6 F_111 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
switch ( V_68 ) {
case V_110 :
return F_107 ( V_68 ) ;
case V_169 :
case V_170 :
case V_171 :
return F_112 ( V_68 ) ;
default:
F_108 ( V_68 ) ;
return F_107 ( V_110 ) ;
}
}
static T_6 F_113 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
switch ( V_68 ) {
case V_110 :
return F_110 ( V_68 , V_109 ) ;
case V_169 :
case V_170 :
case V_171 :
return F_114 ( V_68 , V_109 ) ;
default:
F_108 ( V_68 ) ;
return F_110 ( V_110 , V_109 ) ;
}
}
static enum V_68 F_115 ( struct V_51 * V_52 )
{
const struct V_172 * V_173 =
& V_52 -> V_174 . V_175 [ V_176 ] ;
switch ( V_173 -> V_177 ) {
case V_178 :
return V_110 ;
case V_179 :
return V_169 ;
case V_180 :
return V_170 ;
case V_181 :
return V_171 ;
default:
F_108 ( V_173 -> V_177 ) ;
return V_110 ;
}
}
static T_6 F_116 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
if ( V_68 == V_176 )
V_68 = F_115 ( V_52 ) ;
switch ( V_68 ) {
case V_110 :
case V_169 :
case V_170 :
case V_171 :
return F_107 ( V_68 ) ;
default:
F_108 ( V_68 ) ;
return F_107 ( V_110 ) ;
}
}
static T_6 F_117 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
if ( V_68 == V_176 )
V_68 = F_115 ( V_52 ) ;
switch ( V_68 ) {
case V_110 :
case V_169 :
case V_170 :
case V_171 :
return F_110 ( V_68 , V_109 ) ;
default:
F_108 ( V_68 ) ;
return F_110 ( V_110 , V_109 ) ;
}
}
static T_6 F_118 ( struct V_51 * V_52 ,
enum V_68 V_68 )
{
if ( F_119 ( V_52 ) -> V_182 >= 9 )
return F_116 ( V_52 , V_68 ) ;
else if ( F_67 ( V_52 ) )
return F_111 ( V_52 , V_68 ) ;
else
return F_106 ( V_52 , V_68 ) ;
}
static T_6 F_120 ( struct V_51 * V_52 ,
enum V_68 V_68 , int V_109 )
{
if ( F_119 ( V_52 ) -> V_182 >= 9 )
return F_117 ( V_52 , V_68 , V_109 ) ;
else if ( F_67 ( V_52 ) )
return F_113 ( V_52 , V_68 , V_109 ) ;
else
return F_109 ( V_52 , V_68 , V_109 ) ;
}
static void F_121 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = F_17 ( F_3 ( V_1 ) ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
int V_45 ;
V_1 -> V_105 = F_118 ( V_52 , V_68 ) ;
for ( V_45 = 0 ; V_45 < F_122 ( V_1 -> V_142 ) ; V_45 ++ )
V_1 -> V_142 [ V_45 ] = F_120 ( V_52 , V_68 , V_45 ) ;
}
static void
F_123 ( struct V_1 * V_1 )
{
F_124 ( & V_1 -> V_148 ) ;
F_125 ( V_1 -> V_148 . V_183 ) ;
}
static int
F_126 ( struct V_1 * V_1 , struct V_26 * V_9 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
int V_130 ;
F_121 ( V_1 ) ;
V_1 -> V_148 . V_183 = F_127 ( V_184 , L_16 , F_33 ( V_68 ) ) ;
if ( ! V_1 -> V_148 . V_183 )
return - V_185 ;
V_1 -> V_148 . V_7 = V_9 -> V_4 . V_186 ;
V_1 -> V_148 . V_187 = F_104 ;
F_34 ( L_17 ,
V_1 -> V_148 . V_183 ,
V_9 -> V_4 . V_186 -> V_188 . V_183 ) ;
V_130 = F_128 ( & V_1 -> V_148 ) ;
if ( V_130 < 0 ) {
F_41 ( L_18 ,
V_1 -> V_148 . V_183 , V_130 ) ;
F_125 ( V_1 -> V_148 . V_183 ) ;
return V_130 ;
}
return 0 ;
}
static void
F_129 ( struct V_26 * V_26 )
{
struct V_1 * V_1 = F_4 ( & V_26 -> V_4 ) ;
F_123 ( V_1 ) ;
F_130 ( V_26 ) ;
}
static void
F_131 ( struct V_189 * V_190 )
{
T_5 V_191 ;
memset ( & V_190 -> V_192 , 0 ,
sizeof( V_190 -> V_192 ) ) ;
V_190 -> V_193 = V_194 ;
V_190 -> V_192 . V_195 = 0 ;
V_190 -> V_192 . V_196 = 0 ;
V_191 = F_132 ( V_194 ) ;
switch ( V_190 -> V_197 / 2 ) {
case 81000 :
V_191 |= F_133 ( V_198 ,
V_194 ) ;
break;
case 135000 :
V_191 |= F_133 ( V_199 ,
V_194 ) ;
break;
case 270000 :
V_191 |= F_133 ( V_200 ,
V_194 ) ;
break;
case 162000 :
V_191 |= F_133 ( V_201 ,
V_194 ) ;
break;
case 108000 :
V_191 |= F_133 ( V_202 ,
V_194 ) ;
break;
case 216000 :
V_191 |= F_133 ( V_203 ,
V_194 ) ;
break;
}
V_190 -> V_192 . V_191 = V_191 ;
}
void
F_134 ( struct V_189 * V_190 )
{
memset ( & V_190 -> V_192 , 0 ,
sizeof( V_190 -> V_192 ) ) ;
switch ( V_190 -> V_197 / 2 ) {
case 81000 :
V_190 -> V_193 = V_204 ;
break;
case 135000 :
V_190 -> V_193 = V_205 ;
break;
case 270000 :
V_190 -> V_193 = V_206 ;
break;
}
}
static int
F_135 ( struct V_1 * V_1 , const int * * V_207 )
{
if ( V_1 -> V_208 ) {
* V_207 = V_1 -> V_207 ;
return V_1 -> V_208 ;
}
* V_207 = V_209 ;
return ( F_8 ( V_1 ) >> 3 ) + 1 ;
}
bool F_136 ( struct V_1 * V_1 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
if ( F_137 ( V_7 , 0 , V_211 ) )
return false ;
if ( ( F_138 ( V_7 ) && ! F_139 ( V_7 ) ) || F_94 ( V_7 ) ||
( F_119 ( V_7 ) -> V_182 >= 9 ) )
return true ;
else
return false ;
}
static int
F_140 ( struct V_1 * V_1 , const int * * V_212 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
int V_157 ;
if ( F_65 ( V_7 ) ) {
* V_212 = V_213 ;
V_157 = F_122 ( V_213 ) ;
} else if ( F_141 ( V_7 ) || F_142 ( V_7 ) ) {
* V_212 = V_214 ;
V_157 = F_122 ( V_214 ) ;
} else {
* V_212 = V_209 ;
V_157 = F_122 ( V_209 ) ;
}
if ( ! F_136 ( V_1 ) )
V_157 -- ;
return V_157 ;
}
static void
F_143 ( struct V_49 * V_50 ,
struct V_189 * V_190 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
const struct V_215 * V_216 = NULL ;
int V_45 , V_217 = 0 ;
if ( F_144 ( V_7 ) ) {
V_216 = V_218 ;
V_217 = F_122 ( V_218 ) ;
} else if ( F_67 ( V_7 ) ) {
V_216 = V_219 ;
V_217 = F_122 ( V_219 ) ;
} else if ( F_36 ( V_7 ) ) {
V_216 = V_76 ;
V_217 = F_122 ( V_76 ) ;
} else if ( F_63 ( V_7 ) ) {
V_216 = V_78 ;
V_217 = F_122 ( V_78 ) ;
}
if ( V_216 && V_217 ) {
for ( V_45 = 0 ; V_45 < V_217 ; V_45 ++ ) {
if ( V_190 -> V_197 == V_216 [ V_45 ] . clock ) {
V_190 -> V_77 = V_216 [ V_45 ] . V_77 ;
V_190 -> V_220 = true ;
break;
}
}
}
}
static int F_145 ( const int * V_212 , int V_221 ,
const int * V_207 , int V_222 ,
int * V_223 )
{
int V_45 = 0 , V_224 = 0 , V_225 = 0 ;
while ( V_45 < V_221 && V_224 < V_222 ) {
if ( V_212 [ V_45 ] == V_207 [ V_224 ] ) {
if ( F_47 ( V_225 >= V_226 ) )
return V_225 ;
V_223 [ V_225 ] = V_212 [ V_45 ] ;
++ V_225 ;
++ V_45 ;
++ V_224 ;
} else if ( V_212 [ V_45 ] < V_207 [ V_224 ] ) {
++ V_45 ;
} else {
++ V_224 ;
}
}
return V_225 ;
}
static int F_146 ( struct V_1 * V_1 ,
int * V_223 )
{
const int * V_212 , * V_207 ;
int V_221 , V_222 ;
V_222 = F_135 ( V_1 , & V_207 ) ;
V_221 = F_140 ( V_1 , & V_212 ) ;
return F_145 ( V_212 , V_221 ,
V_207 , V_222 ,
V_223 ) ;
}
static void F_147 ( char * V_227 , T_8 V_228 ,
const int * V_229 , int V_230 )
{
int V_45 ;
V_227 [ 0 ] = '\0' ;
for ( V_45 = 0 ; V_45 < V_230 ; V_45 ++ ) {
int V_231 = snprintf ( V_227 , V_228 , L_19 , V_45 ? L_20 : L_21 , V_229 [ V_45 ] ) ;
if ( V_231 >= V_228 )
return;
V_227 += V_231 ;
V_228 -= V_231 ;
}
}
static void F_148 ( struct V_1 * V_1 )
{
const int * V_212 , * V_207 ;
int V_221 , V_222 , V_232 ;
int V_223 [ V_226 ] ;
char V_227 [ 128 ] ;
if ( ( V_233 & V_234 ) == 0 )
return;
V_221 = F_140 ( V_1 , & V_212 ) ;
F_147 ( V_227 , sizeof( V_227 ) , V_212 , V_221 ) ;
F_34 ( L_22 , V_227 ) ;
V_222 = F_135 ( V_1 , & V_207 ) ;
F_147 ( V_227 , sizeof( V_227 ) , V_207 , V_222 ) ;
F_34 ( L_23 , V_227 ) ;
V_232 = F_146 ( V_1 , V_223 ) ;
F_147 ( V_227 , sizeof( V_227 ) , V_223 , V_232 ) ;
F_34 ( L_24 , V_227 ) ;
}
static int F_149 ( int V_235 , const int * V_236 )
{
int V_45 = 0 ;
for ( V_45 = 0 ; V_45 < V_226 ; ++ V_45 )
if ( V_235 == V_236 [ V_45 ] )
break;
return V_45 ;
}
int
F_18 ( struct V_1 * V_1 )
{
int V_236 [ V_226 ] = {} ;
int V_228 ;
V_228 = F_146 ( V_1 , V_236 ) ;
if ( F_47 ( V_228 <= 0 ) )
return 162000 ;
return V_236 [ F_149 ( 0 , V_236 ) - 1 ] ;
}
int F_150 ( struct V_1 * V_1 , int V_237 )
{
return F_149 ( V_237 , V_1 -> V_207 ) ;
}
void F_151 ( struct V_1 * V_1 , int V_197 ,
T_3 * V_238 , T_3 * V_239 )
{
if ( V_1 -> V_208 ) {
* V_238 = 0 ;
* V_239 =
F_150 ( V_1 , V_197 ) ;
} else {
* V_238 = F_152 ( V_197 ) ;
* V_239 = 0 ;
}
}
bool
F_153 ( struct V_49 * V_50 ,
struct V_189 * V_190 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_240 = & V_190 -> V_4 . V_240 ;
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_241 * V_241 = F_154 ( V_190 -> V_4 . V_242 ) ;
struct V_26 * V_26 = V_1 -> V_243 ;
int V_10 , clock ;
int V_244 = 1 ;
int V_245 = F_10 ( V_1 ) ;
int V_246 = 0 ;
int V_247 ;
int V_21 , V_31 ;
int V_248 , V_249 ;
int V_223 [ V_226 ] = {} ;
int V_232 ;
T_3 V_238 , V_239 ;
V_232 = F_146 ( V_1 , V_223 ) ;
F_47 ( V_232 <= 0 ) ;
V_247 = V_232 - 1 ;
if ( F_67 ( V_7 ) && ! F_155 ( V_7 ) && V_68 != V_110 )
V_190 -> V_250 = true ;
V_190 -> V_251 = true ;
V_190 -> V_252 = false ;
V_190 -> V_253 = V_1 -> V_253 && V_68 != V_110 ;
if ( F_1 ( V_1 ) && V_26 -> V_28 . V_27 ) {
F_156 ( V_26 -> V_28 . V_27 ,
V_240 ) ;
if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
int V_130 ;
V_130 = F_157 ( V_190 ) ;
if ( V_130 )
return V_130 ;
}
if ( F_158 ( V_7 ) )
F_159 ( V_241 , V_190 ,
V_26 -> V_28 . V_254 ) ;
else
F_160 ( V_241 , V_190 ,
V_26 -> V_28 . V_254 ) ;
}
if ( V_240 -> V_39 & V_40 )
return false ;
F_34 ( L_25
L_26 ,
V_245 , V_223 [ V_247 ] ,
V_240 -> V_255 ) ;
V_21 = V_190 -> V_256 ;
if ( F_1 ( V_1 ) ) {
if ( V_26 -> V_4 . V_257 . V_258 == 0 &&
( V_52 -> V_174 . V_259 && V_52 -> V_174 . V_259 < V_21 ) ) {
F_34 ( L_27 ,
V_52 -> V_174 . V_259 ) ;
V_21 = V_52 -> V_174 . V_259 ;
}
V_244 = V_245 ;
V_246 = V_247 ;
}
for (; V_21 >= 6 * 3 ; V_21 -= 2 * 3 ) {
V_31 = F_13 ( V_240 -> V_255 ,
V_21 ) ;
for ( clock = V_246 ; clock <= V_247 ; clock ++ ) {
for ( V_10 = V_244 ;
V_10 <= V_245 ;
V_10 <<= 1 ) {
V_249 = V_223 [ clock ] ;
V_248 = F_14 ( V_249 ,
V_10 ) ;
if ( V_31 <= V_248 ) {
goto V_260;
}
}
}
}
return false ;
V_260:
if ( V_1 -> V_261 ) {
V_190 -> V_262 =
V_21 != 18 && F_161 ( V_240 ) > 1 ;
} else {
V_190 -> V_262 =
V_1 -> V_262 ;
}
V_190 -> V_10 = V_10 ;
V_190 -> V_256 = V_21 ;
V_190 -> V_197 = V_223 [ clock ] ;
F_151 ( V_1 , V_190 -> V_197 ,
& V_238 , & V_239 ) ;
F_34 ( L_28 ,
V_238 , V_239 , V_190 -> V_10 ,
V_190 -> V_197 , V_21 ) ;
F_34 ( L_29 ,
V_31 , V_248 ) ;
F_162 ( V_21 , V_10 ,
V_240 -> V_255 ,
V_190 -> V_197 ,
& V_190 -> V_263 ) ;
if ( V_26 -> V_28 . V_264 != NULL &&
V_52 -> V_265 . type == V_266 ) {
V_190 -> V_252 = true ;
F_162 ( V_21 , V_10 ,
V_26 -> V_28 . V_264 -> clock ,
V_190 -> V_197 ,
& V_190 -> V_267 ) ;
}
if ( ( F_141 ( V_7 ) || F_142 ( V_7 ) ) && F_1 ( V_1 ) )
F_131 ( V_190 ) ;
else if ( F_65 ( V_7 ) )
;
else if ( F_138 ( V_7 ) || F_94 ( V_7 ) )
F_134 ( V_190 ) ;
else
F_143 ( V_50 , V_190 ) ;
return true ;
}
void F_163 ( struct V_1 * V_1 ,
const struct V_189 * V_190 )
{
V_1 -> V_268 = V_190 -> V_197 ;
V_1 -> V_10 = V_190 -> V_10 ;
}
static void F_164 ( struct V_49 * V_50 )
{
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
const struct V_24 * V_240 = & V_242 -> V_269 -> V_4 . V_240 ;
F_163 ( V_1 , V_242 -> V_269 ) ;
V_1 -> V_65 = F_31 ( V_1 -> V_66 ) & V_69 ;
V_1 -> V_65 |= V_70 | V_71 ;
V_1 -> V_65 |= F_35 ( V_242 -> V_269 -> V_10 ) ;
if ( F_165 ( V_7 ) && V_68 == V_110 ) {
if ( V_240 -> V_39 & V_270 )
V_1 -> V_65 |= V_271 ;
if ( V_240 -> V_39 & V_272 )
V_1 -> V_65 |= V_273 ;
V_1 -> V_65 |= V_274 ;
if ( F_166 ( V_1 -> V_12 ) )
V_1 -> V_65 |= V_275 ;
V_1 -> V_65 |= V_242 -> V_57 << 29 ;
} else if ( F_167 ( V_7 ) && V_68 != V_110 ) {
T_5 V_276 ;
V_1 -> V_65 |= V_274 ;
V_276 = F_31 ( F_168 ( V_242 -> V_57 ) ) ;
if ( F_166 ( V_1 -> V_12 ) )
V_276 |= V_277 ;
else
V_276 &= ~ V_277 ;
F_42 ( F_168 ( V_242 -> V_57 ) , V_276 ) ;
} else {
if ( ! F_67 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_36 ( V_7 ) && V_242 -> V_269 -> V_262 )
V_1 -> V_65 |= V_278 ;
if ( V_240 -> V_39 & V_270 )
V_1 -> V_65 |= V_271 ;
if ( V_240 -> V_39 & V_272 )
V_1 -> V_65 |= V_273 ;
V_1 -> V_65 |= V_279 ;
if ( F_166 ( V_1 -> V_12 ) )
V_1 -> V_65 |= V_275 ;
if ( F_36 ( V_7 ) )
V_1 -> V_65 |= F_37 ( V_242 -> V_57 ) ;
else if ( V_242 -> V_57 == V_73 )
V_1 -> V_65 |= V_74 ;
}
}
static void F_169 ( struct V_1 * V_1 ,
T_5 V_280 ,
T_5 V_281 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_6 V_282 , V_96 ;
F_46 ( & V_52 -> V_56 ) ;
V_282 = F_68 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
F_34 ( L_30 ,
V_280 , V_281 ,
F_31 ( V_282 ) ,
F_31 ( V_96 ) ) ;
if ( F_170 ( ( F_31 ( V_282 ) & V_280 ) == V_281 , 5000 , 10 ) ) {
F_41 ( L_31 ,
F_31 ( V_282 ) ,
F_31 ( V_96 ) ) ;
}
F_34 ( L_32 ) ;
}
static void F_171 ( struct V_1 * V_1 )
{
F_34 ( L_33 ) ;
F_169 ( V_1 , V_283 , V_284 ) ;
}
static void F_172 ( struct V_1 * V_1 )
{
F_34 ( L_34 ) ;
F_169 ( V_1 , V_285 , V_286 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
T_9 V_287 ;
T_10 V_288 ;
F_34 ( L_35 ) ;
V_287 = F_174 () ;
V_288 = F_175 ( V_287 , V_1 -> V_289 ) ;
if ( V_288 < ( T_10 ) V_1 -> V_102 )
F_176 ( V_290 ,
V_1 -> V_102 - V_288 ) ;
F_169 ( V_1 , V_291 , V_292 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_293 ,
V_1 -> V_294 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_295 ,
V_1 -> V_296 ) ;
}
static T_5 F_179 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_297 ;
F_46 ( & V_52 -> V_56 ) ;
V_297 = F_31 ( F_64 ( V_1 ) ) ;
if ( ! F_65 ( V_7 ) ) {
V_297 &= ~ V_298 ;
V_297 |= V_100 ;
}
return V_297 ;
}
static bool F_99 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_299 ;
T_6 V_282 , V_96 ;
bool V_300 = ! V_1 -> V_301 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_180 ( & V_1 -> V_302 ) ;
V_1 -> V_301 = true ;
if ( F_76 ( V_1 ) )
return V_300 ;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
F_34 ( L_36 ,
F_33 ( V_3 -> V_68 ) ) ;
if ( ! F_75 ( V_1 ) )
F_173 ( V_1 ) ;
V_299 = F_179 ( V_1 ) ;
V_299 |= V_84 ;
V_282 = F_68 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
F_34 ( L_37 ,
F_31 ( V_282 ) , F_31 ( V_96 ) ) ;
if ( ! F_75 ( V_1 ) ) {
F_34 ( L_38 ,
F_33 ( V_3 -> V_68 ) ) ;
F_74 ( V_1 -> V_303 ) ;
}
return V_300 ;
}
void F_181 ( struct V_1 * V_1 )
{
bool V_133 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_133 = F_99 ( V_1 ) ;
F_25 ( V_1 ) ;
F_182 ( ! V_133 , L_39 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
enum V_54 V_55 ;
T_5 V_299 ;
T_6 V_282 , V_96 ;
F_46 ( & V_52 -> V_56 ) ;
F_47 ( V_1 -> V_301 ) ;
if ( ! F_76 ( V_1 ) )
return;
F_34 ( L_40 ,
F_33 ( V_3 -> V_68 ) ) ;
V_299 = F_179 ( V_1 ) ;
V_299 &= ~ V_84 ;
V_96 = F_64 ( V_1 ) ;
V_282 = F_68 ( V_1 ) ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
F_34 ( L_37 ,
F_31 ( V_282 ) , F_31 ( V_96 ) ) ;
if ( ( V_299 & V_304 ) == 0 )
V_1 -> V_289 = F_174 () ;
V_55 = F_22 ( V_49 ) ;
F_27 ( V_52 , V_55 ) ;
}
static void F_184 ( struct V_305 * V_306 )
{
struct V_1 * V_1 = F_71 ( F_185 ( V_306 ) ,
struct V_1 , V_302 ) ;
F_21 ( V_1 ) ;
if ( ! V_1 -> V_301 )
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
unsigned long V_307 ;
V_307 = F_187 ( V_1 -> V_102 * 5 ) ;
F_188 ( & V_1 -> V_302 , V_307 ) ;
}
static void F_103 ( struct V_1 * V_1 , bool V_308 )
{
struct V_51 * V_52 =
F_3 ( V_1 ) -> V_53 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_182 ( ! V_1 -> V_301 , L_41 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
V_1 -> V_301 = false ;
if ( V_308 )
F_183 ( V_1 ) ;
else
F_186 ( V_1 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_299 ;
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
F_173 ( V_1 ) ;
V_96 = F_64 ( V_1 ) ;
V_299 = F_179 ( V_1 ) ;
if ( F_190 ( V_7 ) ) {
V_299 &= ~ V_309 ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
}
V_299 |= V_304 ;
if ( ! F_190 ( V_7 ) )
V_299 |= V_309 ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
F_171 ( V_1 ) ;
V_1 -> V_293 = V_290 ;
if ( F_190 ( V_7 ) ) {
V_299 |= V_309 ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
}
}
void F_191 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_189 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_299 ;
T_6 V_96 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_44 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
F_9 ( ! V_1 -> V_301 , L_45 ,
F_33 ( F_2 ( V_1 ) -> V_68 ) ) ;
V_299 = F_179 ( V_1 ) ;
V_299 &= ~ ( V_304 | V_309 | V_84 |
V_310 ) ;
V_96 = F_64 ( V_1 ) ;
V_1 -> V_301 = false ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
V_1 -> V_289 = F_174 () ;
F_172 ( V_1 ) ;
V_55 = F_22 ( V_49 ) ;
F_27 ( V_52 , V_55 ) ;
}
void F_193 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
F_192 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_194 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_299 ;
T_6 V_96 ;
F_177 ( V_1 ) ;
F_21 ( V_1 ) ;
V_299 = F_179 ( V_1 ) ;
V_299 |= V_310 ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
F_25 ( V_1 ) ;
}
void F_195 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_196 ( V_1 -> V_243 ) ;
F_194 ( V_1 ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_299 ;
T_6 V_96 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_299 = F_179 ( V_1 ) ;
V_299 &= ~ V_310 ;
V_96 = F_64 ( V_1 ) ;
F_42 ( V_96 , V_299 ) ;
F_43 ( V_96 ) ;
F_25 ( V_1 ) ;
V_1 -> V_295 = V_290 ;
F_178 ( V_1 ) ;
}
void F_198 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_197 ( V_1 ) ;
F_199 ( V_1 -> V_243 ) ;
}
static void F_200 ( struct V_26 * V_9 ,
bool V_311 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_312 ;
F_21 ( V_1 ) ;
V_312 = F_179 ( V_1 ) & V_310 ;
F_25 ( V_1 ) ;
if ( V_312 == V_311 )
return;
F_34 ( L_47 ,
V_311 ? L_48 : L_49 ) ;
if ( V_311 )
F_194 ( V_1 ) ;
else
F_197 ( V_1 ) ;
}
static void F_201 ( struct V_1 * V_1 , bool V_313 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_51 * V_52 = F_17 ( V_210 -> V_4 . V_4 . V_7 ) ;
bool V_314 = F_31 ( V_1 -> V_66 ) & V_67 ;
F_182 ( V_314 != V_313 ,
L_50 ,
F_33 ( V_210 -> V_68 ) ,
F_202 ( V_313 ) , F_202 ( V_314 ) ) ;
}
static void F_203 ( struct V_51 * V_52 , bool V_313 )
{
bool V_314 = F_31 ( V_315 ) & V_316 ;
F_182 ( V_314 != V_313 ,
L_51 ,
F_202 ( V_313 ) , F_202 ( V_314 ) ) ;
}
static void F_204 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_241 * V_242 = F_154 ( V_3 -> V_4 . V_4 . V_242 ) ;
struct V_51 * V_52 = F_17 ( V_242 -> V_4 . V_7 ) ;
F_205 ( V_52 , V_242 -> V_57 ) ;
F_206 ( V_1 ) ;
F_207 ( V_52 ) ;
F_34 ( L_52 ,
V_242 -> V_269 -> V_197 ) ;
V_1 -> V_65 &= ~ V_317 ;
if ( V_242 -> V_269 -> V_197 == 162000 )
V_1 -> V_65 |= V_318 ;
else
V_1 -> V_65 |= V_319 ;
F_42 ( V_315 , V_1 -> V_65 ) ;
F_43 ( V_315 ) ;
F_208 ( 500 ) ;
V_1 -> V_65 |= V_316 ;
F_42 ( V_315 , V_1 -> V_65 ) ;
F_43 ( V_315 ) ;
F_208 ( 200 ) ;
}
static void F_209 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_241 * V_242 = F_154 ( V_3 -> V_4 . V_4 . V_242 ) ;
struct V_51 * V_52 = F_17 ( V_242 -> V_4 . V_7 ) ;
F_205 ( V_52 , V_242 -> V_57 ) ;
F_206 ( V_1 ) ;
F_210 ( V_52 ) ;
F_34 ( L_53 ) ;
V_1 -> V_65 &= ~ V_316 ;
F_42 ( V_315 , V_1 -> V_65 ) ;
F_43 ( V_315 ) ;
F_208 ( 200 ) ;
}
void F_211 ( struct V_1 * V_1 , int V_25 )
{
int V_130 , V_45 ;
if ( V_1 -> V_12 [ V_320 ] < 0x11 )
return;
if ( V_25 != V_321 ) {
V_130 = F_212 ( & V_1 -> V_148 , V_322 ,
V_323 ) ;
} else {
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_130 = F_212 ( & V_1 -> V_148 , V_322 ,
V_324 ) ;
if ( V_130 == 1 )
break;
F_74 ( 1 ) ;
}
}
if ( V_130 != 1 )
F_34 ( L_54 ,
V_25 == V_321 ? L_48 : L_49 ) ;
}
static bool F_213 ( struct V_49 * V_50 ,
enum V_57 * V_57 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
T_5 V_82 ;
bool V_130 ;
V_55 = F_214 ( V_50 ) ;
if ( ! F_215 ( V_52 , V_55 ) )
return false ;
V_130 = false ;
V_82 = F_31 ( V_1 -> V_66 ) ;
if ( ! ( V_82 & V_67 ) )
goto V_137;
if ( F_165 ( V_7 ) && V_68 == V_110 ) {
* V_57 = F_216 ( V_82 ) ;
} else if ( F_167 ( V_7 ) && V_68 != V_110 ) {
enum V_57 V_325 ;
F_217 (dev_priv, p) {
T_5 V_276 = F_31 ( F_168 ( V_325 ) ) ;
if ( F_218 ( V_276 ) == V_68 ) {
* V_57 = V_325 ;
V_130 = true ;
goto V_137;
}
}
F_34 ( L_55 ,
F_219 ( V_1 -> V_66 ) ) ;
} else if ( F_36 ( V_7 ) ) {
* V_57 = F_220 ( V_82 ) ;
} else {
* V_57 = F_221 ( V_82 ) ;
}
V_130 = true ;
V_137:
F_27 ( V_52 , V_55 ) ;
return V_130 ;
}
static void F_222 ( struct V_49 * V_50 ,
struct V_189 * V_190 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
T_5 V_82 , V_39 = 0 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
int V_326 ;
V_82 = F_31 ( V_1 -> V_66 ) ;
V_190 -> V_253 = V_82 & V_327 && V_68 != V_110 ;
if ( F_167 ( V_7 ) && V_68 != V_110 ) {
T_5 V_276 = F_31 ( F_168 ( V_242 -> V_57 ) ) ;
if ( V_276 & V_328 )
V_39 |= V_270 ;
else
V_39 |= V_329 ;
if ( V_276 & V_330 )
V_39 |= V_272 ;
else
V_39 |= V_331 ;
} else {
if ( V_82 & V_271 )
V_39 |= V_270 ;
else
V_39 |= V_329 ;
if ( V_82 & V_273 )
V_39 |= V_272 ;
else
V_39 |= V_331 ;
}
V_190 -> V_4 . V_240 . V_39 |= V_39 ;
if ( ! F_67 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_36 ( V_7 ) && V_82 & V_278 )
V_190 -> V_262 = true ;
V_190 -> V_251 = true ;
V_190 -> V_10 =
( ( V_82 & V_332 ) >> V_333 ) + 1 ;
F_223 ( V_242 , V_190 ) ;
if ( V_68 == V_110 ) {
if ( ( F_31 ( V_315 ) & V_317 ) == V_318 )
V_190 -> V_197 = 162000 ;
else
V_190 -> V_197 = 270000 ;
}
V_326 = F_224 ( V_190 -> V_197 ,
& V_190 -> V_263 ) ;
if ( F_67 ( V_52 -> V_7 ) && V_68 != V_110 )
F_225 ( V_190 , V_326 ) ;
V_190 -> V_4 . V_240 . V_255 = V_326 ;
if ( F_1 ( V_1 ) && V_52 -> V_174 . V_259 &&
V_190 -> V_256 > V_52 -> V_174 . V_259 ) {
F_34 ( L_56 ,
V_190 -> V_256 , V_52 -> V_174 . V_259 ) ;
V_52 -> V_174 . V_259 = V_190 -> V_256 ;
}
}
static void F_226 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
if ( V_242 -> V_269 -> V_253 )
F_227 ( V_50 ) ;
if ( F_228 ( V_7 ) && ! F_155 ( V_7 ) )
F_229 ( V_1 ) ;
F_181 ( V_1 ) ;
F_198 ( V_1 ) ;
F_211 ( V_1 , V_334 ) ;
F_193 ( V_1 ) ;
if ( F_119 ( V_7 ) -> V_182 < 5 )
F_230 ( V_1 ) ;
}
static void F_231 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
F_230 ( V_1 ) ;
if ( V_68 == V_110 )
F_209 ( V_1 ) ;
}
static void F_232 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_230 ( V_1 ) ;
}
static void F_233 ( struct V_49 * V_50 ,
bool V_335 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_4 . V_7 ) ;
enum V_63 V_64 = F_234 ( F_235 ( & V_50 -> V_4 ) ) ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
enum V_57 V_57 = V_242 -> V_57 ;
T_2 V_336 ;
V_336 = F_236 ( V_52 , V_57 , F_237 ( V_64 ) ) ;
if ( V_335 )
V_336 &= ~ ( V_337 | V_338 ) ;
else
V_336 |= V_337 | V_338 ;
F_238 ( V_52 , V_57 , F_237 ( V_64 ) , V_336 ) ;
if ( V_242 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_239 ( V_64 ) ) ;
if ( V_335 )
V_336 &= ~ ( V_337 | V_338 ) ;
else
V_336 |= V_337 | V_338 ;
F_238 ( V_52 , V_57 , F_239 ( V_64 ) , V_336 ) ;
}
V_336 = F_236 ( V_52 , V_57 , F_240 ( V_64 ) ) ;
V_336 |= V_339 ;
if ( V_335 )
V_336 &= ~ V_340 ;
else
V_336 |= V_340 ;
F_238 ( V_52 , V_57 , F_240 ( V_64 ) , V_336 ) ;
if ( V_242 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_241 ( V_64 ) ) ;
V_336 |= V_339 ;
if ( V_335 )
V_336 &= ~ V_340 ;
else
V_336 |= V_340 ;
F_238 ( V_52 , V_57 , F_241 ( V_64 ) , V_336 ) ;
}
}
static void F_242 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_230 ( V_1 ) ;
F_24 ( & V_52 -> V_341 ) ;
F_233 ( V_50 , true ) ;
F_26 ( & V_52 -> V_341 ) ;
}
static void
F_243 ( struct V_1 * V_1 ,
T_2 * V_65 ,
T_3 V_342 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
if ( F_155 ( V_7 ) ) {
T_2 V_343 = F_31 ( F_244 ( V_68 ) ) ;
if ( V_342 & V_344 )
V_343 |= V_345 ;
else
V_343 &= ~ V_345 ;
V_343 &= ~ V_346 ;
switch ( V_342 & V_347 ) {
case V_348 :
V_343 |= V_349 ;
break;
case V_350 :
V_343 |= V_351 ;
break;
case V_352 :
V_343 |= V_353 ;
break;
case V_354 :
V_343 |= V_355 ;
break;
}
F_42 ( F_244 ( V_68 ) , V_343 ) ;
} else if ( ( F_165 ( V_7 ) && V_68 == V_110 ) ||
( F_167 ( V_7 ) && V_68 != V_110 ) ) {
* V_65 &= ~ V_356 ;
switch ( V_342 & V_347 ) {
case V_348 :
* V_65 |= V_274 ;
break;
case V_350 :
* V_65 |= V_357 ;
break;
case V_352 :
* V_65 |= V_358 ;
break;
case V_354 :
F_41 ( L_57 ) ;
* V_65 |= V_358 ;
break;
}
} else {
if ( F_36 ( V_7 ) )
* V_65 &= ~ V_359 ;
else
* V_65 &= ~ V_360 ;
switch ( V_342 & V_347 ) {
case V_348 :
* V_65 |= V_279 ;
break;
case V_350 :
* V_65 |= V_72 ;
break;
case V_352 :
* V_65 |= V_361 ;
break;
case V_354 :
if ( F_36 ( V_7 ) ) {
* V_65 |= V_362 ;
} else {
F_41 ( L_57 ) ;
* V_65 |= V_361 ;
}
break;
}
}
}
static void F_245 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_242 =
F_154 ( F_2 ( V_1 ) -> V_4 . V_4 . V_242 ) ;
F_243 ( V_1 , & V_1 -> V_65 ,
V_350 ) ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_1 -> V_65 |= V_67 ;
if ( V_242 -> V_269 -> V_253 )
V_1 -> V_65 |= V_327 ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
static void F_246 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
T_2 V_363 = F_31 ( V_1 -> V_66 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
enum V_57 V_57 = V_242 -> V_57 ;
if ( F_47 ( V_363 & V_67 ) )
return;
F_21 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
F_247 ( V_1 ) ;
if ( V_68 == V_110 )
F_248 ( V_52 , V_57 , false ) ;
F_245 ( V_1 ) ;
if ( V_68 == V_110 && F_190 ( V_52 ) ) {
F_249 ( V_52 -> V_7 , ! V_57 ) ;
F_248 ( V_52 , ! V_57 , true ) ;
F_250 ( V_52 , ! V_57 , true ) ;
}
F_99 ( V_1 ) ;
F_189 ( V_1 ) ;
F_103 ( V_1 , true ) ;
if ( V_68 == V_110 )
F_248 ( V_52 , V_57 , true ) ;
F_25 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
unsigned int V_364 = 0x0 ;
if ( F_36 ( V_7 ) )
V_364 = F_7 ( V_242 -> V_269 -> V_10 ) ;
F_251 ( V_52 , F_2 ( V_1 ) ,
V_364 ) ;
}
F_211 ( V_1 , V_321 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
if ( V_242 -> V_269 -> V_253 ) {
F_254 ( L_58 ,
F_32 ( V_57 ) ) ;
F_255 ( V_50 ) ;
}
}
static void F_256 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_246 ( V_50 ) ;
F_195 ( V_1 ) ;
}
static void F_257 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
F_195 ( V_1 ) ;
F_258 ( V_1 ) ;
}
static void F_259 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_4 . V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
enum V_57 V_57 = F_154 ( V_50 -> V_4 . V_242 ) -> V_57 ;
F_164 ( V_50 ) ;
if ( V_68 == V_110 && F_190 ( V_52 ) ) {
F_248 ( V_52 , ! V_57 , false ) ;
F_250 ( V_52 , ! V_57 , false ) ;
}
if ( V_68 == V_110 )
F_204 ( V_1 ) ;
}
static void F_260 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = V_3 -> V_4 . V_4 . V_7 -> V_53 ;
enum V_57 V_57 = V_1 -> V_58 ;
T_6 V_365 = F_59 ( V_57 ) ;
F_183 ( V_1 ) ;
F_34 ( L_59 ,
F_32 ( V_57 ) , F_33 ( V_3 -> V_68 ) ) ;
F_42 ( V_365 , 0 ) ;
F_43 ( V_365 ) ;
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
F_9 ( V_50 -> V_4 . V_242 ,
L_61 ,
F_32 ( V_57 ) , F_33 ( V_68 ) ) ;
F_260 ( V_1 ) ;
}
}
static void F_247 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_50 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_242 = F_154 ( V_50 -> V_4 . V_242 ) ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_58 == V_242 -> V_57 )
return;
if ( V_1 -> V_58 != V_81 )
F_260 ( V_1 ) ;
F_50 ( V_7 , V_242 -> V_57 ) ;
V_1 -> V_58 = V_242 -> V_57 ;
F_34 ( L_62 ,
F_32 ( V_1 -> V_58 ) , F_33 ( V_3 -> V_68 ) ) ;
F_51 ( V_7 , V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
static void F_261 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_2 * V_366 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_241 = F_154 ( V_50 -> V_4 . V_242 ) ;
enum V_63 V_68 = F_234 ( V_366 ) ;
int V_57 = V_241 -> V_57 ;
T_5 V_336 ;
F_24 ( & V_52 -> V_341 ) ;
V_336 = F_236 ( V_52 , V_57 , F_262 ( V_68 ) ) ;
V_336 = 0 ;
if ( V_57 )
V_336 |= ( 1 << 21 ) ;
else
V_336 &= ~ ( 1 << 21 ) ;
V_336 |= 0x001000c4 ;
F_238 ( V_52 , V_57 , F_263 ( V_68 ) , V_336 ) ;
F_238 ( V_52 , V_57 , F_264 ( V_68 ) , 0x00760018 ) ;
F_238 ( V_52 , V_57 , F_265 ( V_68 ) , 0x00400888 ) ;
F_26 ( & V_52 -> V_341 ) ;
F_246 ( V_50 ) ;
}
static void F_266 ( struct V_49 * V_50 )
{
struct V_2 * V_366 = F_235 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_241 =
F_154 ( V_50 -> V_4 . V_242 ) ;
enum V_63 V_68 = F_234 ( V_366 ) ;
int V_57 = V_241 -> V_57 ;
F_164 ( V_50 ) ;
F_24 ( & V_52 -> V_341 ) ;
F_238 ( V_52 , V_57 , F_267 ( V_68 ) ,
V_337 |
V_338 ) ;
F_238 ( V_52 , V_57 , F_268 ( V_68 ) ,
V_367 |
V_368 |
( 1 << V_369 ) |
V_340 ) ;
F_238 ( V_52 , V_57 , F_269 ( V_68 ) , 0x00750f00 ) ;
F_238 ( V_52 , V_57 , F_270 ( V_68 ) , 0x00001500 ) ;
F_238 ( V_52 , V_57 , F_271 ( V_68 ) , 0x40400000 ) ;
F_26 ( & V_52 -> V_341 ) ;
}
static void F_272 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_5 ( & V_50 -> V_4 ) ;
struct V_2 * V_366 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_241 =
F_154 ( V_50 -> V_4 . V_242 ) ;
enum V_63 V_64 = F_234 ( V_366 ) ;
int V_57 = V_241 -> V_57 ;
int V_370 , V_45 , V_371 ;
T_5 V_336 ;
F_24 ( & V_52 -> V_341 ) ;
V_336 = F_236 ( V_52 , V_57 , F_273 ( V_64 ) ) ;
V_336 &= ~ V_372 ;
F_238 ( V_52 , V_57 , F_273 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_274 ( V_64 ) ) ;
V_336 &= ~ V_372 ;
F_238 ( V_52 , V_57 , F_274 ( V_64 ) , V_336 ) ;
}
for ( V_45 = 0 ; V_45 < V_241 -> V_269 -> V_10 ; V_45 ++ ) {
if ( V_241 -> V_269 -> V_10 == 1 )
V_370 = 0x0 ;
else
V_370 = ( V_45 == 1 ) ? 0x0 : 0x1 ;
F_238 ( V_52 , V_57 , F_275 ( V_64 , V_45 ) ,
V_370 << V_373 ) ;
}
if ( V_241 -> V_269 -> V_197 > 270000 )
V_371 = 0x18 ;
else if ( V_241 -> V_269 -> V_197 > 135000 )
V_371 = 0xd ;
else if ( V_241 -> V_269 -> V_197 > 67500 )
V_371 = 0x7 ;
else if ( V_241 -> V_269 -> V_197 > 33750 )
V_371 = 0x4 ;
else
V_371 = 0x2 ;
V_336 = F_236 ( V_52 , V_57 , F_273 ( V_64 ) ) ;
V_336 |= F_276 ( 0x1f ) ;
F_238 ( V_52 , V_57 , F_273 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_274 ( V_64 ) ) ;
V_336 |= F_276 ( 0x1f ) ;
F_238 ( V_52 , V_57 , F_274 ( V_64 ) , V_336 ) ;
}
F_238 ( V_52 , V_57 , F_277 ( V_64 ) ,
F_278 ( V_371 ) |
V_374 |
F_279 ( 0x1f ) |
F_280 ( 6 ) |
F_281 ( 0 ) ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
F_238 ( V_52 , V_57 , F_282 ( V_64 ) ,
F_278 ( V_371 ) |
V_374 |
F_279 ( 0x1f ) |
F_280 ( 7 ) |
F_281 ( 5 ) ) ;
}
F_233 ( V_50 , false ) ;
F_26 ( & V_52 -> V_341 ) ;
F_246 ( V_50 ) ;
if ( V_366 -> V_375 ) {
F_39 ( V_52 , V_376 , V_377 , false ) ;
V_366 -> V_375 = false ;
}
}
static void F_283 ( struct V_49 * V_50 )
{
struct V_2 * V_366 = F_235 ( & V_50 -> V_4 ) ;
struct V_6 * V_7 = V_50 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_241 * V_241 =
F_154 ( V_50 -> V_4 . V_242 ) ;
enum V_63 V_64 = F_234 ( V_366 ) ;
enum V_57 V_57 = V_241 -> V_57 ;
unsigned int V_364 =
F_7 ( V_241 -> V_269 -> V_10 ) ;
T_5 V_336 ;
F_164 ( V_50 ) ;
if ( V_64 == V_378 && V_57 == V_73 )
V_366 -> V_375 =
! F_39 ( V_52 , V_376 , V_377 , true ) ;
F_284 ( V_50 , true , V_364 ) ;
F_24 ( & V_52 -> V_341 ) ;
F_233 ( V_50 , true ) ;
if ( V_57 != V_73 ) {
V_336 = F_236 ( V_52 , V_57 , V_379 ) ;
V_336 &= ~ ( V_380 | V_381 ) ;
if ( V_64 == V_378 )
V_336 |= V_382 ;
if ( V_64 == V_377 )
V_336 |= V_383 ;
F_238 ( V_52 , V_57 , V_379 , V_336 ) ;
} else {
V_336 = F_236 ( V_52 , V_57 , V_384 ) ;
V_336 &= ~ ( V_385 | V_386 ) ;
if ( V_64 == V_378 )
V_336 |= V_387 ;
if ( V_64 == V_377 )
V_336 |= V_388 ;
F_238 ( V_52 , V_57 , V_384 , V_336 ) ;
}
V_336 = F_236 ( V_52 , V_57 , F_262 ( V_64 ) ) ;
V_336 |= V_389 ;
if ( V_57 != V_73 )
V_336 &= ~ V_390 ;
else
V_336 |= V_390 ;
F_238 ( V_52 , V_57 , F_262 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_285 ( V_64 ) ) ;
V_336 |= V_389 ;
if ( V_57 != V_73 )
V_336 &= ~ V_390 ;
else
V_336 |= V_390 ;
F_238 ( V_52 , V_57 , F_285 ( V_64 ) , V_336 ) ;
}
V_336 = F_236 ( V_52 , V_57 , F_286 ( V_64 ) ) ;
if ( V_57 != V_73 )
V_336 &= ~ V_391 ;
else
V_336 |= V_391 ;
F_238 ( V_52 , V_57 , F_286 ( V_64 ) , V_336 ) ;
F_26 ( & V_52 -> V_341 ) ;
}
static void F_287 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 -> V_4 . V_7 ) ;
enum V_57 V_57 = F_154 ( V_50 -> V_4 . V_242 ) -> V_57 ;
T_5 V_336 ;
F_24 ( & V_52 -> V_341 ) ;
if ( V_57 != V_73 ) {
V_336 = F_236 ( V_52 , V_57 , V_379 ) ;
V_336 &= ~ ( V_380 | V_381 ) ;
F_238 ( V_52 , V_57 , V_379 , V_336 ) ;
} else {
V_336 = F_236 ( V_52 , V_57 , V_384 ) ;
V_336 &= ~ ( V_385 | V_386 ) ;
F_238 ( V_52 , V_57 , V_384 , V_336 ) ;
}
F_26 ( & V_52 -> V_341 ) ;
F_284 ( V_50 , false , 0x0 ) ;
}
static T_7
F_288 ( struct V_147 * V_148 , unsigned int V_392 ,
void * V_164 , T_8 V_157 )
{
T_7 V_130 ;
int V_45 ;
F_289 ( V_148 , V_320 , V_164 , 1 ) ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_130 = F_289 ( V_148 , V_392 , V_164 , V_157 ) ;
if ( V_130 == V_157 )
return V_130 ;
F_74 ( 1 ) ;
}
return V_130 ;
}
bool
F_290 ( struct V_1 * V_1 , T_3 V_393 [ V_394 ] )
{
return F_288 ( & V_1 -> V_148 ,
V_395 ,
V_393 ,
V_394 ) == V_394 ;
}
T_3
F_291 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
if ( F_65 ( V_7 ) )
return V_396 ;
else if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
if ( V_52 -> V_397 && V_68 == V_110 )
return V_396 ;
return V_398 ;
} else if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
return V_396 ;
else if ( F_165 ( V_7 ) && V_68 == V_110 )
return V_398 ;
else if ( F_167 ( V_7 ) && V_68 != V_110 )
return V_396 ;
else
return V_398 ;
}
T_3
F_292 ( struct V_1 * V_1 , T_3 V_399 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
switch ( V_399 & V_400 ) {
case V_401 :
return V_402 ;
case V_403 :
return V_404 ;
case V_398 :
return V_405 ;
case V_396 :
return V_406 ;
default:
return V_406 ;
}
} else if ( F_138 ( V_7 ) || F_94 ( V_7 ) ) {
switch ( V_399 & V_400 ) {
case V_401 :
return V_402 ;
case V_403 :
return V_404 ;
case V_398 :
return V_405 ;
case V_396 :
default:
return V_406 ;
}
} else if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
switch ( V_399 & V_400 ) {
case V_401 :
return V_402 ;
case V_403 :
return V_404 ;
case V_398 :
return V_405 ;
case V_396 :
default:
return V_406 ;
}
} else if ( F_165 ( V_7 ) && V_68 == V_110 ) {
switch ( V_399 & V_400 ) {
case V_401 :
return V_404 ;
case V_403 :
case V_398 :
return V_405 ;
default:
return V_406 ;
}
} else {
switch ( V_399 & V_400 ) {
case V_401 :
return V_404 ;
case V_403 :
return V_404 ;
case V_398 :
return V_405 ;
case V_396 :
default:
return V_406 ;
}
}
}
static T_2 F_293 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_366 = F_2 ( V_1 ) ;
struct V_241 * V_241 =
F_154 ( V_366 -> V_4 . V_4 . V_242 ) ;
unsigned long V_407 , V_408 ,
V_409 ;
T_3 V_410 = V_1 -> V_410 [ 0 ] ;
enum V_63 V_68 = F_234 ( V_366 ) ;
int V_57 = V_241 -> V_57 ;
switch ( V_410 & V_411 ) {
case V_406 :
V_408 = 0x0004000 ;
switch ( V_410 & V_400 ) {
case V_401 :
V_407 = 0x2B405555 ;
V_409 = 0x552AB83A ;
break;
case V_403 :
V_407 = 0x2B404040 ;
V_409 = 0x5548B83A ;
break;
case V_398 :
V_407 = 0x2B245555 ;
V_409 = 0x5560B83A ;
break;
case V_396 :
V_407 = 0x2B405555 ;
V_409 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_405 :
V_408 = 0x0002000 ;
switch ( V_410 & V_400 ) {
case V_401 :
V_407 = 0x2B404040 ;
V_409 = 0x5552B83A ;
break;
case V_403 :
V_407 = 0x2B404848 ;
V_409 = 0x5580B83A ;
break;
case V_398 :
V_407 = 0x2B404040 ;
V_409 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_404 :
V_408 = 0x0000000 ;
switch ( V_410 & V_400 ) {
case V_401 :
V_407 = 0x2B305555 ;
V_409 = 0x5570B83A ;
break;
case V_403 :
V_407 = 0x2B2B4040 ;
V_409 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_402 :
V_408 = 0x0006000 ;
switch ( V_410 & V_400 ) {
case V_401 :
V_407 = 0x1B405555 ;
V_409 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_52 -> V_341 ) ;
F_238 ( V_52 , V_57 , F_294 ( V_68 ) , 0x00000000 ) ;
F_238 ( V_52 , V_57 , F_295 ( V_68 ) , V_407 ) ;
F_238 ( V_52 , V_57 , F_296 ( V_68 ) ,
V_409 ) ;
F_238 ( V_52 , V_57 , F_297 ( V_68 ) , 0x0C782040 ) ;
F_238 ( V_52 , V_57 , F_298 ( V_68 ) , 0x00030000 ) ;
F_238 ( V_52 , V_57 , F_299 ( V_68 ) , V_408 ) ;
F_238 ( V_52 , V_57 , F_294 ( V_68 ) , 0x80000000 ) ;
F_26 ( & V_52 -> V_341 ) ;
return 0 ;
}
static bool F_300 ( T_3 V_410 )
{
return ( V_410 & V_411 ) == V_406 &&
( V_410 & V_400 ) == V_396 ;
}
static T_2 F_301 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_366 = F_2 ( V_1 ) ;
struct V_241 * V_241 = F_154 ( V_366 -> V_4 . V_4 . V_242 ) ;
T_5 V_412 , V_413 , V_336 ;
T_3 V_410 = V_1 -> V_410 [ 0 ] ;
enum V_63 V_64 = F_234 ( V_366 ) ;
enum V_57 V_57 = V_241 -> V_57 ;
int V_45 ;
switch ( V_410 & V_411 ) {
case V_406 :
switch ( V_410 & V_400 ) {
case V_401 :
V_412 = 128 ;
V_413 = 52 ;
break;
case V_403 :
V_412 = 128 ;
V_413 = 77 ;
break;
case V_398 :
V_412 = 128 ;
V_413 = 102 ;
break;
case V_396 :
V_412 = 128 ;
V_413 = 154 ;
break;
default:
return 0 ;
}
break;
case V_405 :
switch ( V_410 & V_400 ) {
case V_401 :
V_412 = 85 ;
V_413 = 78 ;
break;
case V_403 :
V_412 = 85 ;
V_413 = 116 ;
break;
case V_398 :
V_412 = 85 ;
V_413 = 154 ;
break;
default:
return 0 ;
}
break;
case V_404 :
switch ( V_410 & V_400 ) {
case V_401 :
V_412 = 64 ;
V_413 = 104 ;
break;
case V_403 :
V_412 = 64 ;
V_413 = 154 ;
break;
default:
return 0 ;
}
break;
case V_402 :
switch ( V_410 & V_400 ) {
case V_401 :
V_412 = 43 ;
V_413 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_52 -> V_341 ) ;
V_336 = F_236 ( V_52 , V_57 , F_302 ( V_64 ) ) ;
V_336 &= ~ ( V_414 | V_415 ) ;
V_336 &= ~ ( V_416 | V_417 ) ;
V_336 |= V_418 | V_419 ;
F_238 ( V_52 , V_57 , F_302 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_303 ( V_64 ) ) ;
V_336 &= ~ ( V_414 | V_415 ) ;
V_336 &= ~ ( V_416 | V_417 ) ;
V_336 |= V_418 | V_419 ;
F_238 ( V_52 , V_57 , F_303 ( V_64 ) , V_336 ) ;
}
V_336 = F_236 ( V_52 , V_57 , F_304 ( V_64 ) ) ;
V_336 &= ~ ( V_420 | V_421 ) ;
V_336 |= V_422 | V_423 ;
F_238 ( V_52 , V_57 , F_304 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_305 ( V_64 ) ) ;
V_336 &= ~ ( V_420 | V_421 ) ;
V_336 |= V_422 | V_423 ;
F_238 ( V_52 , V_57 , F_305 ( V_64 ) , V_336 ) ;
}
for ( V_45 = 0 ; V_45 < V_241 -> V_269 -> V_10 ; V_45 ++ ) {
V_336 = F_236 ( V_52 , V_57 , F_306 ( V_64 , V_45 ) ) ;
V_336 &= ~ V_424 ;
V_336 |= V_412 << V_425 ;
F_238 ( V_52 , V_57 , F_306 ( V_64 , V_45 ) , V_336 ) ;
}
for ( V_45 = 0 ; V_45 < V_241 -> V_269 -> V_10 ; V_45 ++ ) {
V_336 = F_236 ( V_52 , V_57 , F_307 ( V_64 , V_45 ) ) ;
V_336 &= ~ V_426 ;
V_336 |= V_413 << V_427 ;
V_336 &= ~ ( 0xff << V_428 ) ;
V_336 |= 0x9a << V_428 ;
F_238 ( V_52 , V_57 , F_307 ( V_64 , V_45 ) , V_336 ) ;
}
for ( V_45 = 0 ; V_45 < V_241 -> V_269 -> V_10 ; V_45 ++ ) {
V_336 = F_236 ( V_52 , V_57 , F_308 ( V_64 , V_45 ) ) ;
if ( F_300 ( V_410 ) )
V_336 |= V_429 ;
else
V_336 &= ~ V_429 ;
F_238 ( V_52 , V_57 , F_308 ( V_64 , V_45 ) , V_336 ) ;
}
V_336 = F_236 ( V_52 , V_57 , F_302 ( V_64 ) ) ;
V_336 |= V_414 | V_415 ;
F_238 ( V_52 , V_57 , F_302 ( V_64 ) , V_336 ) ;
if ( V_241 -> V_269 -> V_10 > 2 ) {
V_336 = F_236 ( V_52 , V_57 , F_303 ( V_64 ) ) ;
V_336 |= V_414 | V_415 ;
F_238 ( V_52 , V_57 , F_303 ( V_64 ) , V_336 ) ;
}
F_26 ( & V_52 -> V_341 ) ;
return 0 ;
}
static T_2
F_309 ( T_3 V_410 )
{
T_2 V_430 = 0 ;
switch ( V_410 & V_400 ) {
case V_401 :
default:
V_430 |= V_70 ;
break;
case V_403 :
V_430 |= V_431 ;
break;
case V_398 :
V_430 |= V_432 ;
break;
case V_396 :
V_430 |= V_433 ;
break;
}
switch ( V_410 & V_411 ) {
case V_406 :
default:
V_430 |= V_71 ;
break;
case V_405 :
V_430 |= V_434 ;
break;
case V_404 :
V_430 |= V_435 ;
break;
case V_402 :
V_430 |= V_436 ;
break;
}
return V_430 ;
}
static T_2
F_310 ( T_3 V_410 )
{
int V_430 = V_410 & ( V_400 |
V_411 ) ;
switch ( V_430 ) {
case V_401 | V_406 :
case V_403 | V_406 :
return V_437 ;
case V_401 | V_405 :
return V_438 ;
case V_401 | V_404 :
case V_403 | V_404 :
return V_439 ;
case V_403 | V_405 :
case V_398 | V_405 :
return V_440 ;
case V_398 | V_406 :
case V_396 | V_406 :
return V_441 ;
default:
F_34 ( L_63
L_64 , V_430 ) ;
return V_437 ;
}
}
static T_2
F_311 ( T_3 V_410 )
{
int V_430 = V_410 & ( V_400 |
V_411 ) ;
switch ( V_430 ) {
case V_401 | V_406 :
return V_442 ;
case V_401 | V_405 :
return V_443 ;
case V_401 | V_404 :
return V_444 ;
case V_403 | V_406 :
return V_445 ;
case V_403 | V_405 :
return V_446 ;
case V_398 | V_406 :
return V_447 ;
case V_398 | V_405 :
return V_448 ;
default:
F_34 ( L_63
L_64 , V_430 ) ;
return V_449 ;
}
}
void
F_312 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = F_17 ( V_7 ) ;
T_2 V_430 , V_280 = 0 ;
T_3 V_410 = V_1 -> V_410 [ 0 ] ;
if ( F_155 ( V_7 ) ) {
V_430 = F_313 ( V_1 ) ;
if ( F_65 ( V_7 ) )
V_430 = 0 ;
else
V_280 = V_450 ;
} else if ( F_36 ( V_7 ) ) {
V_430 = F_301 ( V_1 ) ;
} else if ( F_63 ( V_7 ) ) {
V_430 = F_293 ( V_1 ) ;
} else if ( F_165 ( V_7 ) && V_68 == V_110 ) {
V_430 = F_311 ( V_410 ) ;
V_280 = V_451 ;
} else if ( F_93 ( V_7 ) && V_68 == V_110 ) {
V_430 = F_310 ( V_410 ) ;
V_280 = V_452 ;
} else {
V_430 = F_309 ( V_410 ) ;
V_280 = V_453 | V_454 ;
}
if ( V_280 )
F_34 ( L_65 , V_430 ) ;
F_34 ( L_66 ,
V_410 & V_400 ) ;
F_34 ( L_67 ,
( V_410 & V_411 ) >>
V_455 ) ;
V_1 -> V_65 = ( V_1 -> V_65 & ~ V_280 ) | V_430 ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
void
F_314 ( struct V_1 * V_1 ,
T_3 V_342 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 =
F_17 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_243 ( V_1 , & V_1 -> V_65 , V_342 ) ;
F_42 ( V_1 -> V_66 , V_1 -> V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
}
void F_315 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
T_2 V_336 ;
if ( ! F_155 ( V_7 ) )
return;
V_336 = F_31 ( F_244 ( V_68 ) ) ;
V_336 &= ~ V_346 ;
V_336 |= V_456 ;
F_42 ( F_244 ( V_68 ) , V_336 ) ;
if ( V_68 == V_110 )
return;
if ( F_316 ( ( F_31 ( F_317 ( V_68 ) ) & V_457 ) ,
1 ) )
F_41 ( L_68 ) ;
}
static void
F_230 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_241 * V_242 = F_154 ( V_3 -> V_4 . V_4 . V_242 ) ;
enum V_68 V_68 = V_3 -> V_68 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_2 V_65 = V_1 -> V_65 ;
if ( F_47 ( F_155 ( V_7 ) ) )
return;
if ( F_47 ( ( F_31 ( V_1 -> V_66 ) & V_67 ) == 0 ) )
return;
F_34 ( L_46 ) ;
if ( ( F_165 ( V_7 ) && V_68 == V_110 ) ||
( F_167 ( V_7 ) && V_68 != V_110 ) ) {
V_65 &= ~ V_356 ;
V_65 |= V_458 ;
} else {
if ( F_36 ( V_7 ) )
V_65 &= ~ V_359 ;
else
V_65 &= ~ V_360 ;
V_65 |= V_459 ;
}
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_65 &= ~ ( V_67 | V_327 ) ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
if ( F_318 ( V_7 ) && V_242 -> V_57 == V_73 && V_68 != V_110 ) {
F_248 ( V_52 , V_80 , false ) ;
F_250 ( V_52 , V_80 , false ) ;
V_65 &= ~ ( V_74 | V_360 ) ;
V_65 |= V_67 | V_72 ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
V_65 &= ~ V_67 ;
F_42 ( V_1 -> V_66 , V_65 ) ;
F_43 ( V_1 -> V_66 ) ;
F_249 ( V_52 -> V_7 , V_80 ) ;
F_248 ( V_52 , V_80 , true ) ;
F_250 ( V_52 , V_80 , true ) ;
}
F_74 ( V_1 -> V_460 ) ;
V_1 -> V_65 = V_65 ;
}
static bool
F_319 ( struct V_1 * V_1 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_3 V_461 ;
if ( F_288 ( & V_1 -> V_148 , 0x000 , V_1 -> V_12 ,
sizeof( V_1 -> V_12 ) ) < 0 )
return false ;
F_34 ( L_69 , ( int ) sizeof( V_1 -> V_12 ) , V_1 -> V_12 ) ;
if ( V_1 -> V_12 [ V_320 ] == 0 )
return false ;
memset ( V_1 -> V_462 , 0 , sizeof( V_1 -> V_462 ) ) ;
if ( F_1 ( V_1 ) ) {
F_288 ( & V_1 -> V_148 , V_463 ,
V_1 -> V_462 ,
sizeof( V_1 -> V_462 ) ) ;
if ( V_1 -> V_462 [ 0 ] & V_464 ) {
V_52 -> V_465 . V_466 = true ;
F_34 ( L_70 ) ;
}
if ( F_119 ( V_7 ) -> V_182 >= 9 &&
( V_1 -> V_462 [ 0 ] & V_467 ) ) {
T_3 V_468 ;
V_52 -> V_465 . V_466 = true ;
F_288 ( & V_1 -> V_148 ,
V_469 ,
& V_468 , 1 ) ;
V_52 -> V_465 . V_470 = V_468 ? true : false ;
V_52 -> V_465 . V_471 = V_52 -> V_465 . V_470 ;
F_34 ( L_71 ,
V_52 -> V_465 . V_471 ? L_72 : L_73 ) ;
}
}
F_34 ( L_74 ,
F_320 ( F_136 ( V_1 ) ) ,
F_320 ( F_321 ( V_1 -> V_12 ) ) ) ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_12 [ V_472 ] & V_473 ) &&
( F_288 ( & V_1 -> V_148 , V_474 , & V_461 , 1 ) == 1 ) &&
( V_461 >= 0x03 ) ) {
T_11 V_207 [ V_226 ] ;
int V_45 ;
F_288 ( & V_1 -> V_148 ,
V_475 ,
V_207 ,
sizeof( V_207 ) ) ;
for ( V_45 = 0 ; V_45 < F_122 ( V_207 ) ; V_45 ++ ) {
int V_336 = F_322 ( V_207 [ V_45 ] ) ;
if ( V_336 == 0 )
break;
V_1 -> V_207 [ V_45 ] = ( V_336 * 200 ) / 10 ;
}
V_1 -> V_208 = V_45 ;
}
F_148 ( V_1 ) ;
if ( ! ( V_1 -> V_12 [ V_476 ] &
V_477 ) )
return true ;
if ( V_1 -> V_12 [ V_320 ] == 0x10 )
return true ;
if ( F_288 ( & V_1 -> V_148 , V_478 ,
V_1 -> V_479 ,
V_480 ) < 0 )
return false ;
return true ;
}
static void
F_323 ( struct V_1 * V_1 )
{
T_1 V_481 [ 3 ] ;
if ( ! ( V_1 -> V_12 [ V_482 ] & V_483 ) )
return;
if ( F_288 ( & V_1 -> V_148 , V_484 , V_481 , 3 ) == 3 )
F_34 ( L_75 ,
V_481 [ 0 ] , V_481 [ 1 ] , V_481 [ 2 ] ) ;
if ( F_288 ( & V_1 -> V_148 , V_485 , V_481 , 3 ) == 3 )
F_34 ( L_76 ,
V_481 [ 0 ] , V_481 [ 1 ] , V_481 [ 2 ] ) ;
}
static bool
F_324 ( struct V_1 * V_1 )
{
T_1 V_481 [ 1 ] ;
if ( ! V_1 -> V_486 )
return false ;
if ( V_1 -> V_12 [ V_320 ] < 0x12 )
return false ;
if ( F_288 ( & V_1 -> V_148 , V_487 , V_481 , 1 ) ) {
if ( V_481 [ 0 ] & V_488 ) {
F_34 ( L_77 ) ;
V_1 -> V_489 = true ;
} else {
F_34 ( L_78 ) ;
V_1 -> V_489 = false ;
}
}
F_325 ( & V_1 -> V_490 , V_1 -> V_489 ) ;
return V_1 -> V_489 ;
}
static int F_326 ( struct V_1 * V_1 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
struct V_241 * V_241 = F_154 ( V_210 -> V_4 . V_4 . V_242 ) ;
T_1 V_481 ;
int V_130 = 0 ;
int V_217 = 0 ;
int V_491 = 10 ;
if ( F_327 ( & V_1 -> V_148 , V_492 , & V_481 ) < 0 ) {
F_34 ( L_79 ) ;
V_130 = - V_143 ;
goto V_137;
}
if ( F_212 ( & V_1 -> V_148 , V_492 ,
V_481 & ~ V_493 ) < 0 ) {
F_34 ( L_79 ) ;
V_130 = - V_143 ;
goto V_137;
}
do {
F_328 ( V_7 , V_241 -> V_57 ) ;
if ( F_327 ( & V_1 -> V_148 ,
V_494 , & V_481 ) < 0 ) {
V_130 = - V_143 ;
goto V_137;
}
V_217 = V_481 & V_495 ;
} while ( -- V_491 && V_217 );
if ( V_491 == 0 ) {
F_34 ( L_80 ) ;
V_130 = - V_144 ;
}
V_137:
F_329 ( V_241 ) ;
return V_130 ;
}
static int F_330 ( struct V_1 * V_1 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
struct V_241 * V_241 = F_154 ( V_210 -> V_4 . V_4 . V_242 ) ;
T_1 V_481 ;
int V_130 ;
if ( F_327 ( & V_1 -> V_148 , V_494 , & V_481 ) < 0 )
return - V_143 ;
if ( ! ( V_481 & V_496 ) )
return - V_497 ;
if ( F_327 ( & V_1 -> V_148 , V_492 , & V_481 ) < 0 )
return - V_143 ;
if ( V_481 & V_493 ) {
V_130 = F_326 ( V_1 ) ;
if ( V_130 )
return V_130 ;
}
F_331 ( V_241 ) ;
if ( F_212 ( & V_1 -> V_148 , V_492 ,
V_481 | V_493 ) < 0 ) {
F_329 ( V_241 ) ;
return - V_143 ;
}
F_328 ( V_7 , V_241 -> V_57 ) ;
return 0 ;
}
int F_332 ( struct V_1 * V_1 , T_1 * V_498 )
{
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_210 -> V_4 . V_4 . V_7 ;
struct V_241 * V_241 = F_154 ( V_210 -> V_4 . V_4 . V_242 ) ;
T_1 V_481 ;
int V_217 , V_130 ;
int V_491 = 6 ;
V_130 = F_330 ( V_1 ) ;
if ( V_130 )
return V_130 ;
do {
F_328 ( V_7 , V_241 -> V_57 ) ;
if ( F_327 ( & V_1 -> V_148 ,
V_494 , & V_481 ) < 0 ) {
V_130 = - V_143 ;
goto V_499;
}
V_217 = V_481 & V_495 ;
} while ( -- V_491 && V_217 == 0 );
if ( V_491 == 0 ) {
F_41 ( L_81 ) ;
V_130 = - V_144 ;
goto V_499;
}
if ( F_289 ( & V_1 -> V_148 , V_500 , V_498 , 6 ) < 0 ) {
V_130 = - V_143 ;
goto V_499;
}
V_499:
F_326 ( V_1 ) ;
return V_130 ;
}
static bool
F_333 ( struct V_1 * V_1 , T_1 * V_501 )
{
return F_288 ( & V_1 -> V_148 ,
V_502 ,
V_501 , 1 ) == 1 ;
}
static bool
F_334 ( struct V_1 * V_1 , T_1 * V_501 )
{
int V_130 ;
V_130 = F_288 ( & V_1 -> V_148 ,
V_503 ,
V_501 , 14 ) ;
if ( V_130 != 14 )
return false ;
return true ;
}
static T_3 F_335 ( struct V_1 * V_1 )
{
T_3 V_504 = V_505 ;
return V_504 ;
}
static T_3 F_336 ( struct V_1 * V_1 )
{
T_3 V_504 = V_506 ;
return V_504 ;
}
static T_3 F_337 ( struct V_1 * V_1 )
{
T_3 V_504 = V_506 ;
struct V_26 * V_26 = V_1 -> V_243 ;
struct V_8 * V_9 = & V_26 -> V_4 ;
if ( V_26 -> V_507 == NULL ||
V_9 -> V_508 ||
V_1 -> V_148 . V_509 > 6 ) {
if ( V_1 -> V_148 . V_510 > 0 ||
V_1 -> V_148 . V_509 > 0 )
F_34 ( L_82 ,
V_1 -> V_148 . V_510 ,
V_1 -> V_148 . V_509 ) ;
V_1 -> V_511 = V_512 ;
} else {
struct V_513 * V_514 = V_26 -> V_507 ;
V_514 += V_26 -> V_507 -> V_515 ;
if ( ! F_338 ( & V_1 -> V_148 ,
V_516 ,
& V_514 -> V_517 ,
1 ) )
F_34 ( L_83 ) ;
V_504 = V_505 | V_518 ;
V_1 -> V_511 = V_519 ;
}
V_1 -> V_520 = 1 ;
return V_504 ;
}
static T_3 F_339 ( struct V_1 * V_1 )
{
T_3 V_504 = V_506 ;
return V_504 ;
}
static void F_340 ( struct V_1 * V_1 )
{
T_3 V_521 = V_506 ;
T_3 V_522 = 0 ;
int V_106 = 0 ;
V_106 = F_289 ( & V_1 -> V_148 , V_523 , & V_522 , 1 ) ;
if ( V_106 <= 0 ) {
F_34 ( L_84 ) ;
goto V_524;
}
switch ( V_522 ) {
case V_525 :
F_34 ( L_85 ) ;
V_1 -> V_526 = V_525 ;
V_521 = F_335 ( V_1 ) ;
break;
case V_527 :
F_34 ( L_86 ) ;
V_1 -> V_526 = V_527 ;
V_521 = F_336 ( V_1 ) ;
break;
case V_528 :
F_34 ( L_87 ) ;
V_1 -> V_526 = V_528 ;
V_521 = F_337 ( V_1 ) ;
break;
case V_529 :
F_34 ( L_88 ) ;
V_1 -> V_526 = V_529 ;
V_521 = F_339 ( V_1 ) ;
break;
default:
F_34 ( L_89 , V_522 ) ;
break;
}
V_524:
V_106 = F_338 ( & V_1 -> V_148 ,
V_530 ,
& V_521 , 1 ) ;
if ( V_106 <= 0 )
F_34 ( L_90 ) ;
}
static int
F_341 ( struct V_1 * V_1 )
{
bool V_531 ;
if ( V_1 -> V_489 ) {
T_1 V_532 [ 16 ] = { 0 } ;
int V_130 = 0 ;
int V_533 ;
bool V_534 ;
V_531 = F_334 ( V_1 , V_532 ) ;
V_535:
if ( V_531 == true ) {
if ( V_1 -> V_536 &&
! F_342 ( & V_532 [ 10 ] , V_1 -> V_10 ) ) {
F_34 ( L_91 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
}
F_34 ( L_92 , V_532 ) ;
V_130 = F_343 ( & V_1 -> V_490 , V_532 , & V_534 ) ;
if ( V_534 ) {
for ( V_533 = 0 ; V_533 < 3 ; V_533 ++ ) {
int V_537 ;
V_537 = F_338 ( & V_1 -> V_148 ,
V_503 + 1 ,
& V_532 [ 1 ] , 3 ) ;
if ( V_537 == 3 ) {
break;
}
}
V_531 = F_334 ( V_1 , V_532 ) ;
if ( V_531 == true ) {
F_34 ( L_93 , V_532 ) ;
goto V_535;
}
} else
V_130 = 0 ;
return V_130 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_34 ( L_94 ) ;
V_1 -> V_489 = false ;
F_325 ( & V_1 -> V_490 , V_1 -> V_489 ) ;
F_344 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_168 ;
}
static void
F_345 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_49 * V_49 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_501 ;
T_1 V_393 [ V_394 ] ;
F_47 ( ! F_346 ( & V_7 -> V_538 . V_539 ) ) ;
V_1 -> V_520 = 0 ;
V_1 -> V_526 = 0 ;
V_1 -> V_511 = 0 ;
if ( ! V_49 -> V_4 . V_242 )
return;
if ( ! F_154 ( V_49 -> V_4 . V_242 ) -> V_540 )
return;
if ( ! F_290 ( V_1 , V_393 ) ) {
return;
}
if ( ! F_319 ( V_1 ) ) {
return;
}
if ( V_1 -> V_12 [ V_320 ] >= 0x11 &&
F_333 ( V_1 , & V_501 ) ) {
F_212 ( & V_1 -> V_148 ,
V_502 ,
V_501 ) ;
if ( V_501 & V_541 )
F_254 ( L_95 ) ;
if ( V_501 & ( V_542 | V_543 ) )
F_254 ( L_96 ) ;
}
if ( ( V_1 -> V_526 == V_525 ) ||
( ! F_342 ( V_393 , V_1 -> V_10 ) ) ) {
F_34 ( L_97 ,
V_49 -> V_4 . V_183 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
}
}
static enum V_544
F_347 ( struct V_1 * V_1 )
{
T_3 * V_12 = V_1 -> V_12 ;
T_3 type ;
if ( ! F_319 ( V_1 ) )
return V_545 ;
if ( ! ( V_12 [ V_476 ] & V_477 ) )
return V_546 ;
if ( V_1 -> V_12 [ V_320 ] >= 0x11 &&
V_1 -> V_479 [ 0 ] & V_547 ) {
T_3 V_548 ;
if ( F_288 ( & V_1 -> V_148 , V_549 ,
& V_548 , 1 ) < 0 )
return V_550 ;
return F_348 ( V_548 ) ? V_546
: V_545 ;
}
if ( F_349 ( & V_1 -> V_148 . V_551 ) )
return V_546 ;
if ( V_1 -> V_12 [ V_320 ] >= 0x11 ) {
type = V_1 -> V_479 [ 0 ] & V_552 ;
if ( type == V_553 ||
type == V_554 )
return V_550 ;
} else {
type = V_1 -> V_12 [ V_476 ] &
V_555 ;
if ( type == V_556 ||
type == V_557 )
return V_550 ;
}
F_34 ( L_98 ) ;
return V_545 ;
}
static enum V_544
F_350 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_544 V_106 ;
V_106 = F_351 ( V_7 ) ;
if ( V_106 == V_550 )
V_106 = V_546 ;
return V_106 ;
}
static bool F_352 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_558 ;
switch ( V_68 -> V_68 ) {
case V_110 :
return true ;
case V_169 :
V_558 = V_559 ;
break;
case V_170 :
V_558 = V_560 ;
break;
case V_171 :
V_558 = V_561 ;
break;
default:
F_108 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_562 ) & V_558 ;
}
static bool F_353 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_558 ;
switch ( V_68 -> V_68 ) {
case V_110 :
return true ;
case V_169 :
V_558 = V_563 ;
break;
case V_170 :
V_558 = V_564 ;
break;
case V_171 :
V_558 = V_565 ;
break;
case V_176 :
V_558 = V_566 ;
break;
default:
F_108 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_562 ) & V_558 ;
}
static bool F_354 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_558 ;
switch ( V_68 -> V_68 ) {
case V_169 :
V_558 = V_567 ;
break;
case V_170 :
V_558 = V_568 ;
break;
case V_171 :
V_558 = V_569 ;
break;
default:
F_108 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_570 ) & V_558 ;
}
static bool F_355 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
T_5 V_558 ;
switch ( V_68 -> V_68 ) {
case V_169 :
V_558 = V_571 ;
break;
case V_170 :
V_558 = V_572 ;
break;
case V_171 :
V_558 = V_573 ;
break;
default:
F_108 ( V_68 -> V_68 ) ;
return false ;
}
return F_31 ( V_570 ) & V_558 ;
}
static bool F_356 ( struct V_51 * V_52 ,
struct V_2 * V_3 )
{
struct V_49 * V_49 = & V_3 -> V_4 ;
enum V_68 V_68 ;
T_5 V_558 ;
F_357 ( V_49 -> V_574 , & V_68 ) ;
switch ( V_68 ) {
case V_110 :
V_558 = V_575 ;
break;
case V_169 :
V_558 = V_576 ;
break;
case V_170 :
V_558 = V_577 ;
break;
default:
F_108 ( V_68 ) ;
return false ;
}
return F_31 ( V_578 ) & V_558 ;
}
bool F_358 ( struct V_51 * V_52 ,
struct V_2 * V_68 )
{
if ( F_318 ( V_52 ) )
return F_352 ( V_52 , V_68 ) ;
else if ( F_67 ( V_52 ) )
return F_353 ( V_52 , V_68 ) ;
else if ( F_65 ( V_52 ) )
return F_356 ( V_52 , V_68 ) ;
else if ( F_359 ( V_52 ) )
return F_355 ( V_52 , V_68 ) ;
else
return F_354 ( V_52 , V_68 ) ;
}
static struct V_513 *
F_360 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_243 ;
if ( V_26 -> V_513 ) {
if ( F_361 ( V_26 -> V_513 ) )
return NULL ;
return F_362 ( V_26 -> V_513 ) ;
} else
return F_363 ( & V_26 -> V_4 ,
& V_1 -> V_148 . V_551 ) ;
}
static void
F_364 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_243 ;
struct V_513 * V_513 ;
V_513 = F_360 ( V_1 ) ;
V_26 -> V_507 = V_513 ;
if ( V_1 -> V_579 != V_580 )
V_1 -> V_253 = V_1 -> V_579 == V_581 ;
else
V_1 -> V_253 = F_365 ( V_513 ) ;
}
static void
F_366 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = V_1 -> V_243 ;
F_125 ( V_26 -> V_507 ) ;
V_26 -> V_507 = NULL ;
V_1 -> V_253 = false ;
}
static enum V_544
F_367 ( struct V_8 * V_9 , bool V_582 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_544 V_106 ;
enum V_54 V_55 ;
bool V_130 ;
T_1 V_501 ;
F_34 ( L_99 ,
V_9 -> V_4 . V_583 , V_9 -> V_183 ) ;
F_366 ( V_1 ) ;
if ( V_1 -> V_489 ) {
if ( V_49 -> type != V_5 )
V_49 -> type = V_584 ;
return V_545 ;
}
V_55 = F_22 ( V_49 ) ;
F_23 ( F_17 ( V_7 ) , V_55 ) ;
if ( F_1 ( V_1 ) )
V_106 = F_350 ( V_1 ) ;
else if ( F_358 ( F_17 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_106 = F_347 ( V_1 ) ;
else
V_106 = V_545 ;
if ( V_106 != V_546 ) {
V_1 -> V_520 = 0 ;
V_1 -> V_526 = 0 ;
V_1 -> V_511 = 0 ;
goto V_137;
}
F_323 ( V_1 ) ;
V_130 = F_324 ( V_1 ) ;
if ( V_130 ) {
if ( V_49 -> type != V_5 )
V_49 -> type = V_584 ;
V_106 = V_545 ;
goto V_137;
}
V_1 -> V_148 . V_510 = 0 ;
V_1 -> V_148 . V_509 = 0 ;
F_364 ( V_1 ) ;
if ( V_49 -> type != V_5 )
V_49 -> type = V_584 ;
V_106 = V_546 ;
if ( V_1 -> V_12 [ V_320 ] >= 0x11 &&
F_333 ( V_1 , & V_501 ) ) {
F_212 ( & V_1 -> V_148 ,
V_502 ,
V_501 ) ;
if ( V_501 & V_541 )
F_340 ( V_1 ) ;
if ( V_501 & ( V_542 | V_543 ) )
F_254 ( L_96 ) ;
}
V_137:
F_27 ( F_17 ( V_7 ) , V_55 ) ;
return V_106 ;
}
static void
F_368 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_49 * V_49 = & F_2 ( V_1 ) -> V_4 ;
struct V_51 * V_52 = F_17 ( V_49 -> V_4 . V_7 ) ;
enum V_54 V_55 ;
F_34 ( L_99 ,
V_9 -> V_4 . V_583 , V_9 -> V_183 ) ;
F_366 ( V_1 ) ;
if ( V_9 -> V_106 != V_546 )
return;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
F_364 ( V_1 ) ;
F_27 ( V_52 , V_55 ) ;
if ( V_49 -> type != V_5 )
V_49 -> type = V_584 ;
}
static int F_369 ( struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
struct V_513 * V_513 ;
V_513 = V_26 -> V_507 ;
if ( V_513 ) {
int V_130 = F_370 ( V_9 , V_513 ) ;
if ( V_130 )
return V_130 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_26 -> V_28 . V_27 ) {
struct V_24 * V_25 ;
V_25 = F_371 ( V_9 -> V_7 ,
V_26 -> V_28 . V_27 ) ;
if ( V_25 ) {
F_372 ( V_9 , V_25 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_373 ( struct V_8 * V_9 )
{
bool V_253 = false ;
struct V_513 * V_513 ;
V_513 = F_16 ( V_9 ) -> V_507 ;
if ( V_513 )
V_253 = F_365 ( V_513 ) ;
return V_253 ;
}
static int
F_374 ( struct V_8 * V_9 ,
struct V_585 * V_586 ,
T_12 V_336 )
{
struct V_51 * V_52 = V_9 -> V_7 -> V_53 ;
struct V_26 * V_26 = F_16 ( V_9 ) ;
struct V_49 * V_49 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
int V_130 ;
V_130 = F_375 ( & V_9 -> V_4 , V_586 , V_336 ) ;
if ( V_130 )
return V_130 ;
if ( V_586 == V_52 -> V_587 ) {
int V_45 = V_336 ;
bool V_253 ;
if ( V_45 == V_1 -> V_579 )
return 0 ;
V_1 -> V_579 = V_45 ;
if ( V_45 == V_580 )
V_253 = F_373 ( V_9 ) ;
else
V_253 = ( V_45 == V_581 ) ;
if ( V_253 == V_1 -> V_253 )
return 0 ;
V_1 -> V_253 = V_253 ;
goto V_107;
}
if ( V_586 == V_52 -> V_588 ) {
bool V_589 = V_1 -> V_261 ;
bool V_590 = V_1 -> V_262 ;
switch ( V_336 ) {
case V_591 :
V_1 -> V_261 = true ;
break;
case V_592 :
V_1 -> V_261 = false ;
V_1 -> V_262 = false ;
break;
case V_593 :
V_1 -> V_261 = false ;
V_1 -> V_262 = true ;
break;
default:
return - V_168 ;
}
if ( V_589 == V_1 -> V_261 &&
V_590 == V_1 -> V_262 )
return 0 ;
goto V_107;
}
if ( F_1 ( V_1 ) &&
V_586 == V_9 -> V_7 -> V_538 . V_594 ) {
if ( V_336 == V_595 ) {
F_34 ( L_100 ) ;
return - V_168 ;
}
if ( V_26 -> V_28 . V_254 == V_336 ) {
return 0 ;
}
V_26 -> V_28 . V_254 = V_336 ;
goto V_107;
}
return - V_168 ;
V_107:
if ( V_49 -> V_4 . V_242 )
F_376 ( V_49 -> V_4 . V_242 ) ;
return 0 ;
}
static void
F_377 ( struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
F_125 ( V_26 -> V_507 ) ;
if ( ! F_378 ( V_26 -> V_513 ) )
F_125 ( V_26 -> V_513 ) ;
if ( V_9 -> V_596 == V_597 )
F_379 ( & V_26 -> V_28 ) ;
F_380 ( V_9 ) ;
F_125 ( V_9 ) ;
}
void F_381 ( struct V_598 * V_50 )
{
struct V_2 * V_3 = F_235 ( V_50 ) ;
struct V_1 * V_1 = & V_3 -> V_599 ;
F_382 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_383 ( & V_1 -> V_302 ) ;
F_21 ( V_1 ) ;
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
if ( V_1 -> V_94 . V_600 ) {
F_384 ( & V_1 -> V_94 ) ;
V_1 -> V_94 . V_600 = NULL ;
}
}
F_385 ( V_50 ) ;
F_125 ( V_3 ) ;
}
void F_386 ( struct V_49 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_383 ( & V_1 -> V_302 ) ;
F_21 ( V_1 ) ;
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_387 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
F_46 ( & V_52 -> V_56 ) ;
if ( ! F_76 ( V_1 ) )
return;
F_34 ( L_101 ) ;
V_55 = F_22 ( & V_3 -> V_4 ) ;
F_23 ( V_52 , V_55 ) ;
F_186 ( V_1 ) ;
}
void F_388 ( struct V_598 * V_50 )
{
struct V_1 * V_1 ;
if ( F_389 ( V_50 ) -> type != V_5 )
return;
V_1 = F_5 ( V_50 ) ;
F_21 ( V_1 ) ;
if ( F_63 ( V_50 -> V_7 ) || F_36 ( V_50 -> V_7 ) )
F_61 ( V_1 ) ;
F_387 ( V_1 ) ;
F_25 ( V_1 ) ;
}
enum V_601
F_390 ( struct V_2 * V_3 , bool V_602 )
{
struct V_1 * V_1 = & V_3 -> V_599 ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_54 V_55 ;
enum V_601 V_130 = V_603 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_604 )
V_3 -> V_4 . type = V_584 ;
if ( V_602 && V_3 -> V_4 . type == V_5 ) {
F_34 ( L_102 ,
F_33 ( V_3 -> V_68 ) ) ;
return V_605 ;
}
F_34 ( L_103 ,
F_33 ( V_3 -> V_68 ) ,
V_602 ? L_104 : L_105 ) ;
V_55 = F_22 ( V_49 ) ;
F_23 ( V_52 , V_55 ) ;
if ( V_602 ) {
V_1 -> V_606 = false ;
if ( ! F_358 ( V_52 , V_3 ) )
goto V_607;
if ( ! F_319 ( V_1 ) ) {
goto V_607;
}
F_323 ( V_1 ) ;
if ( ! F_324 ( V_1 ) ) {
F_391 ( & V_7 -> V_538 . V_539 , NULL ) ;
F_345 ( V_1 ) ;
F_392 ( & V_7 -> V_538 . V_539 ) ;
goto V_607;
}
} else {
if ( V_1 -> V_489 ) {
if ( F_341 ( V_1 ) == - V_168 )
goto V_607;
}
if ( ! V_1 -> V_489 ) {
F_391 ( & V_7 -> V_538 . V_539 , NULL ) ;
F_345 ( V_1 ) ;
F_392 ( & V_7 -> V_538 . V_539 ) ;
}
}
V_130 = V_605 ;
goto V_608;
V_607:
if ( V_1 -> V_489 ) {
F_34 ( L_106 , V_1 -> V_489 , V_1 -> V_490 . V_609 ) ;
V_1 -> V_489 = false ;
F_325 ( & V_1 -> V_490 , V_1 -> V_489 ) ;
}
V_608:
F_27 ( V_52 , V_55 ) ;
return V_130 ;
}
bool F_393 ( struct V_6 * V_7 , enum V_68 V_68 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
union V_610 * V_611 ;
int V_45 ;
static const short V_612 [] = {
[ V_169 ] = V_613 ,
[ V_170 ] = V_614 ,
[ V_171 ] = V_615 ,
[ V_176 ] = V_616 ,
} ;
if ( F_119 ( V_7 ) -> V_182 < 5 )
return false ;
if ( V_68 == V_110 )
return true ;
if ( ! V_52 -> V_174 . V_617 )
return false ;
for ( V_45 = 0 ; V_45 < V_52 -> V_174 . V_617 ; V_45 ++ ) {
V_611 = V_52 -> V_174 . V_618 + V_45 ;
if ( V_611 -> V_619 . V_620 == V_612 [ V_68 ] &&
( V_611 -> V_619 . V_621 & V_622 ) ==
( V_623 & V_622 ) )
return true ;
}
return false ;
}
void
F_394 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_26 * V_26 = F_16 ( V_9 ) ;
F_395 ( V_9 ) ;
F_396 ( V_9 ) ;
V_1 -> V_261 = true ;
if ( F_1 ( V_1 ) ) {
F_397 ( V_9 -> V_7 ) ;
F_398 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_538 . V_594 ,
V_624 ) ;
V_26 -> V_28 . V_254 = V_624 ;
}
}
static void F_399 ( struct V_1 * V_1 )
{
V_1 -> V_289 = F_174 () ;
V_1 -> V_293 = V_290 ;
V_1 -> V_295 = V_290 ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_625 V_626 , V_174 , V_627 ,
* V_628 = & V_1 -> V_629 ;
T_5 V_630 , V_631 , V_98 = 0 , V_632 = 0 ;
T_6 V_96 , V_365 , V_633 , V_97 ;
F_46 ( & V_52 -> V_56 ) ;
if ( V_628 -> V_634 != 0 )
return;
if ( F_65 ( V_7 ) ) {
V_96 = F_66 ( 0 ) ;
V_365 = F_400 ( 0 ) ;
V_633 = F_401 ( 0 ) ;
} else if ( F_67 ( V_7 ) ) {
V_96 = V_88 ;
V_365 = V_635 ;
V_633 = V_636 ;
V_97 = V_637 ;
} else {
enum V_57 V_57 = F_45 ( V_1 ) ;
V_96 = F_56 ( V_57 ) ;
V_365 = F_59 ( V_57 ) ;
V_633 = F_402 ( V_57 ) ;
V_97 = F_73 ( V_57 ) ;
}
V_632 = F_179 ( V_1 ) ;
V_630 = F_31 ( V_365 ) ;
V_631 = F_31 ( V_633 ) ;
if ( ! F_65 ( V_7 ) ) {
F_42 ( V_96 , V_632 ) ;
V_98 = F_31 ( V_97 ) ;
}
V_626 . V_638 = ( V_630 & V_639 ) >>
V_640 ;
V_626 . V_641 = ( V_630 & V_642 ) >>
V_643 ;
V_626 . V_644 = ( V_631 & V_645 ) >>
V_646 ;
V_626 . V_647 = ( V_631 & V_648 ) >>
V_649 ;
if ( F_65 ( V_7 ) ) {
T_13 V_82 = ( V_632 & V_650 ) >>
V_651 ;
if ( V_82 > 0 )
V_626 . V_634 = ( V_82 - 1 ) * 1000 ;
else
V_626 . V_634 = 0 ;
} else {
V_626 . V_634 = ( ( V_98 & V_652 ) >>
V_653 ) * 1000 ;
}
F_34 ( L_107 ,
V_626 . V_638 , V_626 . V_641 , V_626 . V_644 , V_626 . V_647 , V_626 . V_634 ) ;
V_174 = V_52 -> V_174 . V_654 ;
V_627 . V_638 = 210 * 10 ;
V_627 . V_641 = 50 * 10 ;
V_627 . V_644 = 50 * 10 ;
V_627 . V_647 = 500 * 10 ;
V_627 . V_634 = ( 510 + 100 ) * 10 ;
F_34 ( L_108 ,
V_174 . V_638 , V_174 . V_641 , V_174 . V_644 , V_174 . V_647 , V_174 . V_634 ) ;
#define F_403 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_403 ( V_638 ) ;
F_403 ( V_641 ) ;
F_403 ( V_644 ) ;
F_403 ( V_647 ) ;
F_403 ( V_634 ) ;
#undef F_403
#define F_404 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_303 = F_404 ( V_638 ) ;
V_1 -> V_294 = F_404 ( V_641 ) ;
V_1 -> V_296 = F_404 ( V_644 ) ;
V_1 -> V_460 = F_404 ( V_647 ) ;
V_1 -> V_102 = F_404 ( V_634 ) ;
#undef F_404
F_34 ( L_109 ,
V_1 -> V_303 , V_1 -> V_460 ,
V_1 -> V_102 ) ;
F_34 ( L_110 ,
V_1 -> V_294 , V_1 -> V_296 ) ;
}
static void
F_52 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_5 V_630 , V_631 , V_98 , V_86 = 0 ;
int div = F_67 ( V_7 ) ? F_87 ( V_7 ) : F_85 ( V_7 ) ;
T_6 V_365 , V_633 , V_97 , V_96 ;
enum V_68 V_68 = F_2 ( V_1 ) -> V_68 ;
const struct V_625 * V_655 = & V_1 -> V_629 ;
F_46 ( & V_52 -> V_56 ) ;
if ( F_65 ( V_7 ) ) {
V_96 = F_66 ( 0 ) ;
V_365 = F_400 ( 0 ) ;
V_633 = F_401 ( 0 ) ;
} else if ( F_67 ( V_7 ) ) {
V_365 = V_635 ;
V_633 = V_636 ;
V_97 = V_637 ;
} else {
enum V_57 V_57 = F_45 ( V_1 ) ;
V_365 = F_59 ( V_57 ) ;
V_633 = F_402 ( V_57 ) ;
V_97 = F_73 ( V_57 ) ;
}
V_630 = ( V_655 -> V_638 << V_640 ) |
( 1 << V_643 ) ;
V_631 = ( 1 << V_646 ) |
( V_655 -> V_647 << V_649 ) ;
if ( F_65 ( V_7 ) ) {
V_98 = F_31 ( V_96 ) ;
V_98 &= ~ V_650 ;
V_98 |= ( F_405 ( ( V_655 -> V_634 + 1 ) , 1000 )
<< V_651 ) ;
} else {
V_98 = ( ( 100 * div ) / 2 - 1 ) << V_656 ;
V_98 |= ( F_405 ( V_655 -> V_634 , 1000 )
<< V_653 ) ;
}
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
V_86 = F_60 ( V_68 ) ;
} else if ( F_318 ( V_7 ) || F_167 ( V_7 ) ) {
if ( V_68 == V_110 )
V_86 = V_657 ;
else
V_86 = V_658 ;
}
V_630 |= V_86 ;
F_42 ( V_365 , V_630 ) ;
F_42 ( V_633 , V_631 ) ;
if ( F_65 ( V_7 ) )
F_42 ( V_96 , V_98 ) ;
else
F_42 ( V_97 , V_98 ) ;
F_34 ( L_111 ,
F_31 ( V_365 ) ,
F_31 ( V_633 ) ,
F_65 ( V_7 ) ?
( F_31 ( V_96 ) & V_650 ) :
F_31 ( V_97 ) ) ;
}
static void F_406 ( struct V_6 * V_7 , int V_659 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_49 * V_50 ;
struct V_2 * V_210 = NULL ;
struct V_1 * V_1 = V_52 -> V_265 . V_599 ;
struct V_189 * V_269 = NULL ;
struct V_241 * V_241 = NULL ;
enum V_660 V_109 = V_661 ;
if ( V_659 <= 0 ) {
F_34 ( L_112 ) ;
return;
}
if ( V_1 == NULL ) {
F_34 ( L_113 ) ;
return;
}
V_210 = F_2 ( V_1 ) ;
V_50 = & V_210 -> V_4 ;
V_241 = F_154 ( V_50 -> V_4 . V_242 ) ;
if ( ! V_241 ) {
F_34 ( L_114 ) ;
return;
}
V_269 = V_241 -> V_269 ;
if ( V_52 -> V_265 . type < V_266 ) {
F_34 ( L_115 ) ;
return;
}
if ( V_1 -> V_243 -> V_28 . V_264 -> V_662 ==
V_659 )
V_109 = V_663 ;
if ( V_109 == V_52 -> V_265 . V_664 ) {
F_34 (
L_116 ) ;
return;
}
if ( ! V_241 -> V_540 ) {
F_34 ( L_117 ) ;
return;
}
if ( F_119 ( V_7 ) -> V_182 >= 8 && ! F_36 ( V_7 ) ) {
switch ( V_109 ) {
case V_661 :
F_407 ( V_241 , V_665 ) ;
break;
case V_663 :
F_407 ( V_241 , V_666 ) ;
break;
case V_667 :
default:
F_41 ( L_118 ) ;
}
} else if ( F_119 ( V_7 ) -> V_182 > 6 ) {
T_6 V_548 = F_408 ( V_241 -> V_269 -> V_668 ) ;
T_5 V_336 ;
V_336 = F_31 ( V_548 ) ;
if ( V_109 > V_661 ) {
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
V_336 |= V_669 ;
else
V_336 |= V_670 ;
} else {
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
V_336 &= ~ V_669 ;
else
V_336 &= ~ V_670 ;
}
F_42 ( V_548 , V_336 ) ;
}
V_52 -> V_265 . V_664 = V_109 ;
F_34 ( L_119 , V_659 ) ;
}
void F_409 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_671 * V_242 = V_210 -> V_4 . V_4 . V_242 ;
struct V_241 * V_241 = F_154 ( V_242 ) ;
if ( ! V_241 -> V_269 -> V_252 ) {
F_34 ( L_120 ) ;
return;
}
F_24 ( & V_52 -> V_265 . V_672 ) ;
if ( F_47 ( V_52 -> V_265 . V_599 ) ) {
F_41 ( L_121 ) ;
goto V_673;
}
V_52 -> V_265 . V_674 = 0 ;
V_52 -> V_265 . V_599 = V_1 ;
V_673:
F_26 ( & V_52 -> V_265 . V_672 ) ;
}
void F_410 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_210 = F_2 ( V_1 ) ;
struct V_671 * V_242 = V_210 -> V_4 . V_4 . V_242 ;
struct V_241 * V_241 = F_154 ( V_242 ) ;
if ( ! V_241 -> V_269 -> V_252 )
return;
F_24 ( & V_52 -> V_265 . V_672 ) ;
if ( ! V_52 -> V_265 . V_599 ) {
F_26 ( & V_52 -> V_265 . V_672 ) ;
return;
}
if ( V_52 -> V_265 . V_664 == V_663 )
F_406 ( V_52 -> V_7 ,
V_1 -> V_243 -> V_28 .
V_27 -> V_662 ) ;
V_52 -> V_265 . V_599 = NULL ;
F_26 ( & V_52 -> V_265 . V_672 ) ;
F_383 ( & V_52 -> V_265 . V_675 ) ;
}
static void F_411 ( struct V_305 * V_675 )
{
struct V_51 * V_52 =
F_71 ( V_675 , F_72 ( * V_52 ) , V_265 . V_675 . V_675 ) ;
struct V_1 * V_1 ;
F_24 ( & V_52 -> V_265 . V_672 ) ;
V_1 = V_52 -> V_265 . V_599 ;
if ( ! V_1 )
goto V_673;
if ( V_52 -> V_265 . V_674 )
goto V_673;
if ( V_52 -> V_265 . V_664 != V_663 )
F_406 ( V_52 -> V_7 ,
V_1 -> V_243 -> V_28 .
V_264 -> V_662 ) ;
V_673:
F_26 ( & V_52 -> V_265 . V_672 ) ;
}
void F_412 ( struct V_6 * V_7 ,
unsigned V_676 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_671 * V_242 ;
enum V_57 V_57 ;
if ( V_52 -> V_265 . type == V_677 )
return;
F_180 ( & V_52 -> V_265 . V_675 ) ;
F_24 ( & V_52 -> V_265 . V_672 ) ;
if ( ! V_52 -> V_265 . V_599 ) {
F_26 ( & V_52 -> V_265 . V_672 ) ;
return;
}
V_242 = F_2 ( V_52 -> V_265 . V_599 ) -> V_4 . V_4 . V_242 ;
V_57 = F_154 ( V_242 ) -> V_57 ;
V_676 &= F_413 ( V_57 ) ;
V_52 -> V_265 . V_674 |= V_676 ;
if ( V_676 && V_52 -> V_265 . V_664 == V_663 )
F_406 ( V_52 -> V_7 ,
V_52 -> V_265 . V_599 -> V_243 -> V_28 .
V_27 -> V_662 ) ;
F_26 ( & V_52 -> V_265 . V_672 ) ;
}
void F_414 ( struct V_6 * V_7 ,
unsigned V_676 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_671 * V_242 ;
enum V_57 V_57 ;
if ( V_52 -> V_265 . type == V_677 )
return;
F_180 ( & V_52 -> V_265 . V_675 ) ;
F_24 ( & V_52 -> V_265 . V_672 ) ;
if ( ! V_52 -> V_265 . V_599 ) {
F_26 ( & V_52 -> V_265 . V_672 ) ;
return;
}
V_242 = F_2 ( V_52 -> V_265 . V_599 ) -> V_4 . V_4 . V_242 ;
V_57 = F_154 ( V_242 ) -> V_57 ;
V_676 &= F_413 ( V_57 ) ;
V_52 -> V_265 . V_674 &= ~ V_676 ;
if ( V_676 && V_52 -> V_265 . V_664 == V_663 )
F_406 ( V_52 -> V_7 ,
V_52 -> V_265 . V_599 -> V_243 -> V_28 .
V_27 -> V_662 ) ;
if ( ! V_52 -> V_265 . V_674 )
F_188 ( & V_52 -> V_265 . V_675 ,
F_187 ( 1000 ) ) ;
F_26 ( & V_52 -> V_265 . V_672 ) ;
}
static struct V_24 *
F_415 ( struct V_26 * V_26 ,
struct V_24 * V_27 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_264 = NULL ;
F_416 ( & V_52 -> V_265 . V_675 , F_411 ) ;
F_417 ( & V_52 -> V_265 . V_672 ) ;
if ( F_119 ( V_7 ) -> V_182 <= 6 ) {
F_34 ( L_122 ) ;
return NULL ;
}
if ( V_52 -> V_174 . V_678 != V_266 ) {
F_34 ( L_123 ) ;
return NULL ;
}
V_264 = F_418
( V_7 , V_27 , V_9 ) ;
if ( ! V_264 ) {
F_34 ( L_124 ) ;
return NULL ;
}
V_52 -> V_265 . type = V_52 -> V_174 . V_678 ;
V_52 -> V_265 . V_664 = V_661 ;
F_34 ( L_125 ) ;
return V_264 ;
}
static bool F_419 ( struct V_1 * V_1 ,
struct V_26 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_24 * V_27 = NULL ;
struct V_24 * V_264 = NULL ;
bool V_679 ;
struct V_24 * V_680 ;
struct V_513 * V_513 ;
enum V_57 V_57 = V_81 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_21 ( V_1 ) ;
F_387 ( V_1 ) ;
F_25 ( V_1 ) ;
V_679 = F_319 ( V_1 ) ;
if ( V_679 ) {
if ( V_1 -> V_12 [ V_320 ] >= 0x11 )
V_52 -> V_681 =
V_1 -> V_12 [ V_682 ] &
V_683 ;
} else {
F_420 ( L_126 ) ;
return false ;
}
F_21 ( V_1 ) ;
F_52 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
F_24 ( & V_7 -> V_538 . V_672 ) ;
V_513 = F_363 ( V_9 , & V_1 -> V_148 . V_551 ) ;
if ( V_513 ) {
if ( F_421 ( V_9 , V_513 ) ) {
F_422 ( V_9 ,
V_513 ) ;
F_423 ( V_9 , V_513 ) ;
} else {
F_125 ( V_513 ) ;
V_513 = F_424 ( - V_168 ) ;
}
} else {
V_513 = F_424 ( - V_684 ) ;
}
V_26 -> V_513 = V_513 ;
F_425 (scan, &connector->probed_modes, head) {
if ( ( V_680 -> type & V_685 ) ) {
V_27 = F_371 ( V_7 , V_680 ) ;
V_264 = F_415 (
V_26 , V_27 ) ;
break;
}
}
if ( ! V_27 && V_52 -> V_174 . V_686 ) {
V_27 = F_371 ( V_7 ,
V_52 -> V_174 . V_686 ) ;
if ( V_27 )
V_27 -> type |= V_685 ;
}
F_26 ( & V_7 -> V_538 . V_672 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) ) {
V_1 -> V_94 . V_600 = F_70 ;
F_426 ( & V_1 -> V_94 ) ;
if ( F_36 ( V_7 ) )
V_57 = F_220 ( V_1 -> V_65 ) ;
else
V_57 = F_221 ( V_1 -> V_65 ) ;
if ( V_57 != V_80 && V_57 != V_73 )
V_57 = V_1 -> V_58 ;
if ( V_57 != V_80 && V_57 != V_73 )
V_57 = V_80 ;
F_34 ( L_127 ,
F_32 ( V_57 ) ) ;
}
F_427 ( & V_26 -> V_28 , V_27 , V_264 ) ;
V_26 -> V_28 . V_687 . V_688 = F_200 ;
F_428 ( V_9 , V_57 ) ;
return true ;
}
bool
F_429 ( struct V_2 * V_3 ,
struct V_26 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_599 ;
struct V_49 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_68 V_68 = V_3 -> V_68 ;
int type , V_130 ;
if ( F_9 ( V_3 -> V_19 < 1 ,
L_128 ,
V_3 -> V_19 , F_33 ( V_68 ) ) )
return false ;
V_1 -> V_58 = V_81 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 )
V_1 -> V_139 = F_91 ;
else if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
V_1 -> V_139 = F_90 ;
else if ( F_138 ( V_7 ) || F_94 ( V_7 ) )
V_1 -> V_139 = F_88 ;
else if ( F_67 ( V_7 ) )
V_1 -> V_139 = F_86 ;
else
V_1 -> V_139 = F_83 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 )
V_1 -> V_141 = F_95 ;
else
V_1 -> V_141 = F_92 ;
if ( F_155 ( V_7 ) )
V_1 -> V_689 = V_690 ;
V_1 -> V_65 = F_31 ( V_1 -> V_66 ) ;
V_1 -> V_243 = V_26 ;
if ( F_393 ( V_7 , V_68 ) )
type = V_597 ;
else
type = V_691 ;
if ( type == V_597 )
V_49 -> type = V_5 ;
if ( F_47 ( ( F_63 ( V_7 ) || F_36 ( V_7 ) ) &&
F_1 ( V_1 ) && V_68 != V_169 && V_68 != V_170 ) )
return false ;
F_34 ( L_129 ,
type == V_597 ? L_130 : L_131 ,
F_33 ( V_68 ) ) ;
F_430 ( V_7 , V_9 , & V_692 , type ) ;
F_431 ( V_9 , & V_693 ) ;
V_9 -> V_694 = true ;
V_9 -> V_695 = 0 ;
F_416 ( & V_1 -> V_302 ,
F_184 ) ;
F_432 ( V_26 , V_49 ) ;
F_433 ( V_9 ) ;
if ( F_155 ( V_7 ) )
V_26 -> V_696 = V_697 ;
else
V_26 -> V_696 = V_698 ;
V_26 -> V_699 = F_129 ;
switch ( V_68 ) {
case V_110 :
V_49 -> V_574 = V_700 ;
break;
case V_169 :
V_49 -> V_574 = V_701 ;
if ( F_434 ( V_7 , 0 , V_702 ) )
V_49 -> V_574 = V_700 ;
break;
case V_170 :
V_49 -> V_574 = V_703 ;
break;
case V_171 :
V_49 -> V_574 = V_704 ;
break;
case V_176 :
V_49 -> V_574 = V_705 ;
break;
default:
F_435 () ;
}
if ( F_1 ( V_1 ) ) {
F_21 ( V_1 ) ;
F_399 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_36 ( V_7 ) )
F_61 ( V_1 ) ;
else
F_51 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
}
V_130 = F_126 ( V_1 , V_26 ) ;
if ( V_130 )
goto V_706;
if ( F_436 ( V_7 ) &&
( V_68 == V_169 || V_68 == V_170 || V_68 == V_171 ) )
F_437 ( V_3 ,
V_26 -> V_4 . V_4 . V_583 ) ;
if ( ! F_419 ( V_1 , V_26 ) ) {
F_123 ( V_1 ) ;
F_382 ( V_3 ) ;
goto V_706;
}
F_394 ( V_1 , V_9 ) ;
if ( F_144 ( V_7 ) && ! F_359 ( V_7 ) ) {
T_5 V_343 = F_31 ( V_707 ) ;
F_42 ( V_707 , ( V_343 & ~ 0xf ) | 0xd ) ;
}
F_438 ( V_9 ) ;
return true ;
V_706:
if ( F_1 ( V_1 ) ) {
F_383 ( & V_1 -> V_302 ) ;
F_21 ( V_1 ) ;
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
}
F_439 ( V_9 ) ;
F_380 ( V_9 ) ;
return false ;
}
void
F_440 ( struct V_6 * V_7 ,
T_6 V_66 , enum V_68 V_68 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 ;
struct V_49 * V_49 ;
struct V_598 * V_50 ;
struct V_26 * V_26 ;
V_3 = F_441 ( sizeof( * V_3 ) , V_184 ) ;
if ( ! V_3 )
return;
V_26 = F_442 () ;
if ( ! V_26 )
goto V_708;
V_49 = & V_3 -> V_4 ;
V_50 = & V_49 -> V_4 ;
if ( F_443 ( V_7 , & V_49 -> V_4 , & V_709 ,
V_710 , NULL ) )
goto V_711;
V_49 -> V_712 = F_153 ;
V_49 -> V_713 = F_226 ;
V_49 -> V_696 = F_213 ;
V_49 -> V_714 = F_222 ;
V_49 -> V_715 = F_386 ;
if ( F_36 ( V_7 ) ) {
V_49 -> V_716 = F_283 ;
V_49 -> V_717 = F_272 ;
V_49 -> V_311 = F_257 ;
V_49 -> V_718 = F_242 ;
V_49 -> V_719 = F_287 ;
} else if ( F_63 ( V_7 ) ) {
V_49 -> V_716 = F_266 ;
V_49 -> V_717 = F_261 ;
V_49 -> V_311 = F_257 ;
V_49 -> V_718 = F_232 ;
} else {
V_49 -> V_717 = F_259 ;
V_49 -> V_311 = F_256 ;
if ( F_119 ( V_7 ) -> V_182 >= 5 )
V_49 -> V_718 = F_231 ;
}
V_3 -> V_68 = V_68 ;
V_3 -> V_599 . V_66 = V_66 ;
V_3 -> V_19 = 4 ;
V_49 -> type = V_584 ;
if ( F_36 ( V_7 ) ) {
if ( V_68 == V_171 )
V_49 -> V_720 = 1 << 2 ;
else
V_49 -> V_720 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_49 -> V_720 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_49 -> V_721 = 0 ;
V_3 -> V_722 = F_390 ;
V_52 -> V_723 . V_724 [ V_68 ] = V_3 ;
if ( ! F_429 ( V_3 , V_26 ) )
goto V_725;
return;
V_725:
F_385 ( V_50 ) ;
V_711:
F_125 ( V_26 ) ;
V_708:
F_125 ( V_3 ) ;
return;
}
void F_444 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_726 ; V_45 ++ ) {
struct V_2 * V_3 = V_52 -> V_723 . V_724 [ V_45 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_584 ) {
if ( ! V_3 -> V_599 . V_486 )
continue;
if ( V_3 -> V_599 . V_489 )
F_445 ( & V_3 -> V_599 . V_490 ) ;
}
}
}
void F_446 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_726 ; V_45 ++ ) {
struct V_2 * V_3 = V_52 -> V_723 . V_724 [ V_45 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_584 ) {
int V_130 ;
if ( ! V_3 -> V_599 . V_486 )
continue;
V_130 = F_447 ( & V_3 -> V_599 . V_490 ) ;
if ( V_130 != 0 ) {
F_341 ( & V_3 -> V_599 ) ;
}
}
}
}
