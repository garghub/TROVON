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
F_47 (dev, encoder) {
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
if ( F_46 ( ! F_62 ( V_7 ) && ! F_36 ( V_7 ) ) )
return;
F_47 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_52 -> type != V_5 )
continue;
V_1 = F_5 ( & V_52 -> V_4 ) ;
V_1 -> V_60 = V_82 ;
}
}
static T_6
F_63 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_64 ( V_7 ) )
return F_65 ( 0 ) ;
else if ( F_66 ( V_7 ) )
return V_89 ;
else
return F_55 ( F_44 ( V_1 ) ) ;
}
static T_6
F_67 ( struct V_1 * V_1 )
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
if ( F_62 ( V_7 ) || F_36 ( V_7 ) ) {
enum V_59 V_59 = F_44 ( V_1 ) ;
T_6 V_97 , V_98 ;
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
if ( ( F_62 ( V_7 ) || F_36 ( V_7 ) ) &&
V_1 -> V_60 == V_82 )
return false ;
return ( F_31 ( F_67 ( V_1 ) ) & V_84 ) != 0 ;
}
static bool F_75 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ( F_62 ( V_7 ) || F_36 ( V_7 ) ) &&
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
T_6 V_105 = V_1 -> V_106 ;
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
return V_110 ? 0 : F_84 ( F_85 ( V_7 ) , 2 ) ;
}
static T_2 F_86 ( struct V_1 * V_1 , int V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_110 )
return 0 ;
if ( V_3 -> V_19 == V_20 ) {
return F_84 ( V_54 -> V_111 , 2000 ) ;
} else {
return F_84 ( F_87 ( V_7 ) , 2 ) ;
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
return F_84 ( V_54 -> V_111 , 2000 ) ;
} else if ( F_89 ( V_54 ) ) {
switch ( V_110 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_110 ? 0 : F_84 ( F_87 ( V_7 ) , 2 ) ;
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
if ( F_94 ( V_7 ) && V_3 -> V_19 == V_20 )
V_115 = V_116 ;
else
V_115 = V_117 ;
return V_118 |
V_119 |
( V_104 ? V_120 : 0 ) |
V_121 |
V_115 |
V_122 |
( V_112 << V_123 ) |
( V_114 << V_124 ) |
( V_113 << V_125 ) ;
}
static T_2 F_95 ( struct V_1 * V_1 ,
bool V_104 ,
int V_112 ,
T_2 V_94 )
{
return V_118 |
V_119 |
( V_104 ? V_120 : 0 ) |
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
struct V_53 * V_54 = V_7 -> V_55 ;
T_6 V_105 = V_1 -> V_106 ;
T_2 V_113 ;
int V_47 , V_130 , V_131 ;
T_2 V_107 ;
int V_132 , clock = 0 ;
bool V_104 = F_98 ( V_7 ) ;
bool V_133 ;
F_21 ( V_1 ) ;
V_133 = F_99 ( V_1 ) ;
F_100 ( & V_54 -> V_134 , 0 ) ;
F_76 ( V_1 ) ;
for ( V_132 = 0 ; V_132 < 3 ; V_132 ++ ) {
V_107 = F_101 ( V_105 ) ;
if ( ( V_107 & V_118 ) == 0 )
break;
F_73 ( 1 ) ;
}
if ( V_132 == 3 ) {
static T_5 V_135 = - 1 ;
const T_5 V_107 = F_31 ( V_105 ) ;
if ( V_107 != V_135 ) {
F_9 ( 1 , L_10 ,
V_107 ) ;
V_135 = V_107 ;
}
V_130 = - V_136 ;
goto V_137;
}
if ( F_46 ( V_112 > 20 || V_129 > 20 ) ) {
V_130 = - V_138 ;
goto V_137;
}
while ( ( V_113 = V_1 -> V_139 ( V_1 , clock ++ ) ) ) {
T_5 V_140 = V_1 -> V_141 ( V_1 ,
V_104 ,
V_112 ,
V_113 ) ;
for ( V_132 = 0 ; V_132 < 5 ; V_132 ++ ) {
for ( V_47 = 0 ; V_47 < V_112 ; V_47 += 4 )
F_41 ( V_1 -> V_142 [ V_47 >> 2 ] ,
F_19 ( V_127 + V_47 ,
V_112 - V_47 ) ) ;
F_41 ( V_105 , V_140 ) ;
V_107 = F_77 ( V_1 , V_104 ) ;
F_41 ( V_105 ,
V_107 |
V_119 |
V_121 |
V_122 ) ;
if ( V_107 & V_121 )
continue;
if ( V_107 & V_122 ) {
F_102 ( 400 , 500 ) ;
continue;
}
if ( V_107 & V_119 )
goto V_108;
}
}
if ( ( V_107 & V_119 ) == 0 ) {
F_82 ( L_11 , V_107 ) ;
V_130 = - V_136 ;
goto V_137;
}
V_108:
if ( V_107 & V_122 ) {
F_82 ( L_12 , V_107 ) ;
V_130 = - V_143 ;
goto V_137;
}
if ( V_107 & V_121 ) {
F_34 ( L_13 , V_107 ) ;
V_130 = - V_144 ;
goto V_137;
}
V_131 = ( ( V_107 & V_145 ) >>
V_123 ) ;
if ( V_131 == 0 || V_131 > 20 ) {
F_34 ( L_14 ,
V_131 ) ;
F_102 ( 1000 , 1500 ) ;
V_130 = - V_136 ;
goto V_137;
}
if ( V_131 > V_129 )
V_131 = V_129 ;
for ( V_47 = 0 ; V_47 < V_131 ; V_47 += 4 )
F_20 ( F_31 ( V_1 -> V_142 [ V_47 >> 2 ] ) ,
V_128 + V_47 , V_131 - V_47 ) ;
V_130 = V_131 ;
V_137:
F_100 ( & V_54 -> V_134 , V_146 ) ;
if ( V_133 )
F_103 ( V_1 , false ) ;
F_25 ( V_1 ) ;
return V_130 ;
}
static T_7
F_104 ( struct V_147 * V_148 , struct V_149 * V_150 )
{
struct V_1 * V_1 = F_70 ( V_148 , struct V_1 , V_148 ) ;
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
if ( F_46 ( V_153 > 20 ) )
return - V_138 ;
memcpy ( V_151 + V_162 , V_150 -> V_164 , V_150 -> V_157 ) ;
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
if ( F_46 ( V_154 > 20 ) )
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
static T_6 F_106 ( struct V_53 * V_54 ,
enum V_19 V_19 )
{
switch ( V_19 ) {
case V_169 :
case V_170 :
case V_171 :
return F_107 ( V_19 ) ;
default:
F_108 ( V_19 ) ;
return F_107 ( V_169 ) ;
}
}
static T_6 F_109 ( struct V_53 * V_54 ,
enum V_19 V_19 , int V_110 )
{
switch ( V_19 ) {
case V_169 :
case V_170 :
case V_171 :
return F_110 ( V_19 , V_110 ) ;
default:
F_108 ( V_19 ) ;
return F_110 ( V_169 , V_110 ) ;
}
}
static T_6 F_111 ( struct V_53 * V_54 ,
enum V_19 V_19 )
{
switch ( V_19 ) {
case V_20 :
return F_107 ( V_19 ) ;
case V_169 :
case V_170 :
case V_171 :
return F_112 ( V_19 ) ;
default:
F_108 ( V_19 ) ;
return F_107 ( V_20 ) ;
}
}
static T_6 F_113 ( struct V_53 * V_54 ,
enum V_19 V_19 , int V_110 )
{
switch ( V_19 ) {
case V_20 :
return F_110 ( V_19 , V_110 ) ;
case V_169 :
case V_170 :
case V_171 :
return F_114 ( V_19 , V_110 ) ;
default:
F_108 ( V_19 ) ;
return F_110 ( V_20 , V_110 ) ;
}
}
static enum V_19 F_115 ( struct V_53 * V_54 )
{
const struct V_172 * V_173 =
& V_54 -> V_174 . V_175 [ V_176 ] ;
switch ( V_173 -> V_177 ) {
case V_178 :
return V_20 ;
case V_179 :
return V_169 ;
case V_180 :
return V_170 ;
case V_181 :
return V_171 ;
default:
F_108 ( V_173 -> V_177 ) ;
return V_20 ;
}
}
static T_6 F_116 ( struct V_53 * V_54 ,
enum V_19 V_19 )
{
if ( V_19 == V_176 )
V_19 = F_115 ( V_54 ) ;
switch ( V_19 ) {
case V_20 :
case V_169 :
case V_170 :
case V_171 :
return F_107 ( V_19 ) ;
default:
F_108 ( V_19 ) ;
return F_107 ( V_20 ) ;
}
}
static T_6 F_117 ( struct V_53 * V_54 ,
enum V_19 V_19 , int V_110 )
{
if ( V_19 == V_176 )
V_19 = F_115 ( V_54 ) ;
switch ( V_19 ) {
case V_20 :
case V_169 :
case V_170 :
case V_171 :
return F_110 ( V_19 , V_110 ) ;
default:
F_108 ( V_19 ) ;
return F_110 ( V_20 , V_110 ) ;
}
}
static T_6 F_118 ( struct V_53 * V_54 ,
enum V_19 V_19 )
{
if ( F_119 ( V_54 ) -> V_182 >= 9 )
return F_116 ( V_54 , V_19 ) ;
else if ( F_66 ( V_54 ) )
return F_111 ( V_54 , V_19 ) ;
else
return F_106 ( V_54 , V_19 ) ;
}
static T_6 F_120 ( struct V_53 * V_54 ,
enum V_19 V_19 , int V_110 )
{
if ( F_119 ( V_54 ) -> V_182 >= 9 )
return F_117 ( V_54 , V_19 , V_110 ) ;
else if ( F_66 ( V_54 ) )
return F_113 ( V_54 , V_19 , V_110 ) ;
else
return F_109 ( V_54 , V_19 , V_110 ) ;
}
static void F_121 ( struct V_1 * V_1 )
{
struct V_53 * V_54 = F_122 ( F_3 ( V_1 ) ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
int V_47 ;
V_1 -> V_106 = F_118 ( V_54 , V_19 ) ;
for ( V_47 = 0 ; V_47 < F_123 ( V_1 -> V_142 ) ; V_47 ++ )
V_1 -> V_142 [ V_47 ] = F_120 ( V_54 , V_19 , V_47 ) ;
}
static void
F_124 ( struct V_1 * V_1 )
{
F_125 ( & V_1 -> V_148 ) ;
F_126 ( V_1 -> V_148 . V_183 ) ;
}
static int
F_127 ( struct V_1 * V_1 , struct V_30 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
int V_130 ;
F_121 ( V_1 ) ;
V_1 -> V_148 . V_183 = F_128 ( V_184 , L_15 , F_33 ( V_19 ) ) ;
if ( ! V_1 -> V_148 . V_183 )
return - V_185 ;
V_1 -> V_148 . V_7 = V_7 -> V_7 ;
V_1 -> V_148 . V_186 = F_104 ;
F_34 ( L_16 ,
V_1 -> V_148 . V_183 ,
V_9 -> V_4 . V_187 -> V_188 . V_183 ) ;
V_130 = F_129 ( & V_1 -> V_148 ) ;
if ( V_130 < 0 ) {
F_82 ( L_17 ,
V_1 -> V_148 . V_183 , V_130 ) ;
F_126 ( V_1 -> V_148 . V_183 ) ;
return V_130 ;
}
V_130 = F_130 ( & V_9 -> V_4 . V_187 -> V_188 ,
& V_1 -> V_148 . V_189 . V_7 . V_188 ,
V_1 -> V_148 . V_189 . V_7 . V_188 . V_183 ) ;
if ( V_130 < 0 ) {
F_82 ( L_18 ,
V_1 -> V_148 . V_183 , V_130 ) ;
F_124 ( V_1 ) ;
return V_130 ;
}
return 0 ;
}
static void
F_131 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = F_4 ( & V_30 -> V_4 ) ;
if ( ! V_30 -> V_190 )
F_132 ( & V_30 -> V_4 . V_187 -> V_188 ,
V_1 -> V_148 . V_189 . V_7 . V_188 . V_183 ) ;
F_133 ( V_30 ) ;
}
static void
F_134 ( struct V_191 * V_192 )
{
T_5 V_193 ;
memset ( & V_192 -> V_194 , 0 ,
sizeof( V_192 -> V_194 ) ) ;
V_192 -> V_195 = V_196 ;
V_192 -> V_194 . V_197 = 0 ;
V_192 -> V_194 . V_198 = 0 ;
V_193 = F_135 ( V_196 ) ;
switch ( V_192 -> V_199 / 2 ) {
case 81000 :
V_193 |= F_136 ( V_200 ,
V_196 ) ;
break;
case 135000 :
V_193 |= F_136 ( V_201 ,
V_196 ) ;
break;
case 270000 :
V_193 |= F_136 ( V_202 ,
V_196 ) ;
break;
case 162000 :
V_193 |= F_136 ( V_203 ,
V_196 ) ;
break;
case 108000 :
V_193 |= F_136 ( V_204 ,
V_196 ) ;
break;
case 216000 :
V_193 |= F_136 ( V_205 ,
V_196 ) ;
break;
}
V_192 -> V_194 . V_193 = V_193 ;
}
void
F_137 ( struct V_191 * V_192 )
{
memset ( & V_192 -> V_194 , 0 ,
sizeof( V_192 -> V_194 ) ) ;
switch ( V_192 -> V_199 / 2 ) {
case 81000 :
V_192 -> V_195 = V_206 ;
break;
case 135000 :
V_192 -> V_195 = V_207 ;
break;
case 270000 :
V_192 -> V_195 = V_208 ;
break;
}
}
static int
F_138 ( struct V_1 * V_1 , const int * * V_209 )
{
if ( V_1 -> V_210 ) {
* V_209 = V_1 -> V_209 ;
return V_1 -> V_210 ;
}
* V_209 = V_211 ;
return ( F_8 ( V_1 ) >> 3 ) + 1 ;
}
bool F_139 ( struct V_1 * V_1 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
if ( F_140 ( V_7 , 0 , V_213 ) )
return false ;
if ( ( F_141 ( V_7 ) && ! F_142 ( V_7 ) ) || F_94 ( V_7 ) ||
( F_119 ( V_7 ) -> V_182 >= 9 ) )
return true ;
else
return false ;
}
static int
F_143 ( struct V_1 * V_1 , const int * * V_214 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
int V_157 ;
if ( F_64 ( V_7 ) ) {
* V_214 = V_215 ;
V_157 = F_123 ( V_215 ) ;
} else if ( F_144 ( V_7 ) || F_145 ( V_7 ) ) {
* V_214 = V_216 ;
V_157 = F_123 ( V_216 ) ;
} else {
* V_214 = V_211 ;
V_157 = F_123 ( V_211 ) ;
}
if ( ! F_139 ( V_1 ) )
V_157 -- ;
return V_157 ;
}
static void
F_146 ( struct V_51 * V_52 ,
struct V_191 * V_192 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
const struct V_217 * V_218 = NULL ;
int V_47 , V_219 = 0 ;
if ( F_147 ( V_7 ) ) {
V_218 = V_220 ;
V_219 = F_123 ( V_220 ) ;
} else if ( F_66 ( V_7 ) ) {
V_218 = V_221 ;
V_219 = F_123 ( V_221 ) ;
} else if ( F_36 ( V_7 ) ) {
V_218 = V_77 ;
V_219 = F_123 ( V_77 ) ;
} else if ( F_62 ( V_7 ) ) {
V_218 = V_79 ;
V_219 = F_123 ( V_79 ) ;
}
if ( V_218 && V_219 ) {
for ( V_47 = 0 ; V_47 < V_219 ; V_47 ++ ) {
if ( V_192 -> V_199 == V_218 [ V_47 ] . clock ) {
V_192 -> V_78 = V_218 [ V_47 ] . V_78 ;
V_192 -> V_222 = true ;
break;
}
}
}
}
static int F_148 ( const int * V_214 , int V_223 ,
const int * V_209 , int V_224 ,
int * V_225 )
{
int V_47 = 0 , V_226 = 0 , V_227 = 0 ;
while ( V_47 < V_223 && V_226 < V_224 ) {
if ( V_214 [ V_47 ] == V_209 [ V_226 ] ) {
if ( F_46 ( V_227 >= V_228 ) )
return V_227 ;
V_225 [ V_227 ] = V_214 [ V_47 ] ;
++ V_227 ;
++ V_47 ;
++ V_226 ;
} else if ( V_214 [ V_47 ] < V_209 [ V_226 ] ) {
++ V_47 ;
} else {
++ V_226 ;
}
}
return V_227 ;
}
static int F_149 ( struct V_1 * V_1 ,
int * V_225 )
{
const int * V_214 , * V_209 ;
int V_223 , V_224 ;
V_224 = F_138 ( V_1 , & V_209 ) ;
V_223 = F_143 ( V_1 , & V_214 ) ;
return F_148 ( V_214 , V_223 ,
V_209 , V_224 ,
V_225 ) ;
}
static void F_150 ( char * V_229 , T_8 V_230 ,
const int * V_231 , int V_232 )
{
int V_47 ;
V_229 [ 0 ] = '\0' ;
for ( V_47 = 0 ; V_47 < V_232 ; V_47 ++ ) {
int V_233 = snprintf ( V_229 , V_230 , L_19 , V_47 ? L_20 : L_21 , V_231 [ V_47 ] ) ;
if ( V_233 >= V_230 )
return;
V_229 += V_233 ;
V_230 -= V_233 ;
}
}
static void F_151 ( struct V_1 * V_1 )
{
const int * V_214 , * V_209 ;
int V_223 , V_224 , V_234 ;
int V_225 [ V_228 ] ;
char V_229 [ 128 ] ;
if ( ( V_235 & V_236 ) == 0 )
return;
V_223 = F_143 ( V_1 , & V_214 ) ;
F_150 ( V_229 , sizeof( V_229 ) , V_214 , V_223 ) ;
F_34 ( L_22 , V_229 ) ;
V_224 = F_138 ( V_1 , & V_209 ) ;
F_150 ( V_229 , sizeof( V_229 ) , V_209 , V_224 ) ;
F_34 ( L_23 , V_229 ) ;
V_234 = F_149 ( V_1 , V_225 ) ;
F_150 ( V_229 , sizeof( V_229 ) , V_225 , V_234 ) ;
F_34 ( L_24 , V_229 ) ;
}
static int F_152 ( int V_237 , const int * V_238 )
{
int V_47 = 0 ;
for ( V_47 = 0 ; V_47 < V_228 ; ++ V_47 )
if ( V_237 == V_238 [ V_47 ] )
break;
return V_47 ;
}
int
F_18 ( struct V_1 * V_1 )
{
int V_238 [ V_228 ] = {} ;
int V_230 ;
V_230 = F_149 ( V_1 , V_238 ) ;
if ( F_46 ( V_230 <= 0 ) )
return 162000 ;
return V_238 [ F_152 ( 0 , V_238 ) - 1 ] ;
}
int F_153 ( struct V_1 * V_1 , int V_239 )
{
return F_152 ( V_239 , V_1 -> V_209 ) ;
}
void F_154 ( struct V_1 * V_1 , int V_199 ,
T_3 * V_240 , T_3 * V_241 )
{
if ( V_1 -> V_210 ) {
* V_240 = 0 ;
* V_241 =
F_153 ( V_1 , V_199 ) ;
} else {
* V_240 = F_155 ( V_199 ) ;
* V_241 = 0 ;
}
}
bool
F_156 ( struct V_51 * V_52 ,
struct V_191 * V_192 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_242 = & V_192 -> V_4 . V_242 ;
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_243 * V_243 = F_157 ( V_192 -> V_4 . V_244 ) ;
struct V_30 * V_30 = V_1 -> V_245 ;
int V_10 , clock ;
int V_246 = 1 ;
int V_247 = F_10 ( V_1 ) ;
int V_248 = 0 ;
int V_249 ;
int V_24 , V_35 ;
int V_250 , V_251 ;
int V_225 [ V_228 ] = {} ;
int V_234 ;
T_3 V_240 , V_241 ;
V_234 = F_149 ( V_1 , V_225 ) ;
F_46 ( V_234 <= 0 ) ;
V_249 = V_234 - 1 ;
if ( F_66 ( V_7 ) && ! F_11 ( V_7 ) && V_19 != V_20 )
V_192 -> V_252 = true ;
V_192 -> V_253 = true ;
V_192 -> V_254 = false ;
V_192 -> V_255 = V_1 -> V_255 && V_19 != V_20 ;
if ( F_1 ( V_1 ) && V_30 -> V_32 . V_31 ) {
F_158 ( V_30 -> V_32 . V_31 ,
V_242 ) ;
if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
int V_130 ;
V_130 = F_159 ( V_192 ) ;
if ( V_130 )
return V_130 ;
}
if ( F_160 ( V_7 ) )
F_161 ( V_243 , V_192 ,
V_30 -> V_32 . V_256 ) ;
else
F_162 ( V_243 , V_192 ,
V_30 -> V_32 . V_256 ) ;
}
if ( V_242 -> V_41 & V_42 )
return false ;
F_34 ( L_25
L_26 ,
V_247 , V_225 [ V_249 ] ,
V_242 -> V_257 ) ;
V_24 = V_192 -> V_258 ;
if ( F_1 ( V_1 ) ) {
if ( V_30 -> V_4 . V_259 . V_260 == 0 &&
( V_54 -> V_174 . V_261 && V_54 -> V_174 . V_261 < V_24 ) ) {
F_34 ( L_27 ,
V_54 -> V_174 . V_261 ) ;
V_24 = V_54 -> V_174 . V_261 ;
}
V_246 = V_247 ;
V_248 = V_249 ;
}
for (; V_24 >= 6 * 3 ; V_24 -= 2 * 3 ) {
V_35 = F_14 ( V_242 -> V_257 ,
V_24 ) ;
for ( clock = V_248 ; clock <= V_249 ; clock ++ ) {
for ( V_10 = V_246 ;
V_10 <= V_247 ;
V_10 <<= 1 ) {
V_251 = V_225 [ clock ] ;
V_250 = F_15 ( V_251 ,
V_10 ) ;
if ( V_35 <= V_250 ) {
goto V_262;
}
}
}
}
return false ;
V_262:
if ( V_1 -> V_263 ) {
V_192 -> V_264 =
V_24 != 18 && F_163 ( V_242 ) > 1 ;
} else {
V_192 -> V_264 =
V_1 -> V_264 ;
}
V_192 -> V_10 = V_10 ;
V_192 -> V_258 = V_24 ;
V_192 -> V_199 = V_225 [ clock ] ;
F_154 ( V_1 , V_192 -> V_199 ,
& V_240 , & V_241 ) ;
F_34 ( L_28 ,
V_240 , V_241 , V_192 -> V_10 ,
V_192 -> V_199 , V_24 ) ;
F_34 ( L_29 ,
V_35 , V_250 ) ;
F_164 ( V_24 , V_10 ,
V_242 -> V_257 ,
V_192 -> V_199 ,
& V_192 -> V_265 ) ;
if ( V_30 -> V_32 . V_266 != NULL &&
V_54 -> V_267 . type == V_268 ) {
V_192 -> V_254 = true ;
F_164 ( V_24 , V_10 ,
V_30 -> V_32 . V_266 -> clock ,
V_192 -> V_199 ,
& V_192 -> V_269 ) ;
}
if ( ( F_144 ( V_7 ) || F_145 ( V_7 ) ) && F_1 ( V_1 ) )
F_134 ( V_192 ) ;
else if ( F_64 ( V_7 ) )
;
else if ( F_141 ( V_7 ) || F_94 ( V_7 ) )
F_137 ( V_192 ) ;
else
F_146 ( V_52 , V_192 ) ;
return true ;
}
void F_165 ( struct V_1 * V_1 ,
const struct V_191 * V_192 )
{
V_1 -> V_270 = V_192 -> V_199 ;
V_1 -> V_10 = V_192 -> V_10 ;
}
static void F_166 ( struct V_51 * V_52 )
{
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
const struct V_28 * V_242 = & V_244 -> V_271 -> V_4 . V_242 ;
F_165 ( V_1 , V_244 -> V_271 ) ;
V_1 -> V_67 = F_31 ( V_1 -> V_68 ) & V_70 ;
V_1 -> V_67 |= V_71 | V_72 ;
V_1 -> V_67 |= F_35 ( V_244 -> V_271 -> V_10 ) ;
if ( F_167 ( V_7 ) && V_19 == V_20 ) {
if ( V_242 -> V_41 & V_272 )
V_1 -> V_67 |= V_273 ;
if ( V_242 -> V_41 & V_274 )
V_1 -> V_67 |= V_275 ;
V_1 -> V_67 |= V_276 ;
if ( F_168 ( V_1 -> V_12 ) )
V_1 -> V_67 |= V_277 ;
V_1 -> V_67 |= V_244 -> V_59 << 29 ;
} else if ( F_169 ( V_7 ) && V_19 != V_20 ) {
T_5 V_278 ;
V_1 -> V_67 |= V_276 ;
V_278 = F_31 ( F_170 ( V_244 -> V_59 ) ) ;
if ( F_168 ( V_1 -> V_12 ) )
V_278 |= V_279 ;
else
V_278 &= ~ V_279 ;
F_41 ( F_170 ( V_244 -> V_59 ) , V_278 ) ;
} else {
if ( ! F_66 ( V_7 ) && ! F_62 ( V_7 ) &&
! F_36 ( V_7 ) && V_244 -> V_271 -> V_264 )
V_1 -> V_67 |= V_280 ;
if ( V_242 -> V_41 & V_272 )
V_1 -> V_67 |= V_273 ;
if ( V_242 -> V_41 & V_274 )
V_1 -> V_67 |= V_275 ;
V_1 -> V_67 |= V_281 ;
if ( F_168 ( V_1 -> V_12 ) )
V_1 -> V_67 |= V_277 ;
if ( F_36 ( V_7 ) )
V_1 -> V_67 |= F_37 ( V_244 -> V_59 ) ;
else if ( V_244 -> V_59 == V_74 )
V_1 -> V_67 |= V_75 ;
}
}
static void F_171 ( struct V_1 * V_1 ,
T_5 V_282 ,
T_5 V_283 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_6 V_284 , V_97 ;
F_45 ( & V_54 -> V_58 ) ;
V_284 = F_67 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
F_34 ( L_30 ,
V_282 , V_283 ,
F_31 ( V_284 ) ,
F_31 ( V_97 ) ) ;
if ( F_172 ( ( F_31 ( V_284 ) & V_282 ) == V_283 , 5000 , 10 ) ) {
F_82 ( L_31 ,
F_31 ( V_284 ) ,
F_31 ( V_97 ) ) ;
}
F_34 ( L_32 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
F_34 ( L_33 ) ;
F_171 ( V_1 , V_285 , V_286 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
F_34 ( L_34 ) ;
F_171 ( V_1 , V_287 , V_288 ) ;
}
static void F_175 ( struct V_1 * V_1 )
{
F_34 ( L_35 ) ;
F_176 ( V_1 -> V_289 ,
V_1 -> V_103 ) ;
F_171 ( V_1 , V_290 , V_291 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_292 ,
V_1 -> V_293 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_294 ,
V_1 -> V_295 ) ;
}
static T_5 F_179 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_296 ;
F_45 ( & V_54 -> V_58 ) ;
V_296 = F_31 ( F_63 ( V_1 ) ) ;
if ( ! F_64 ( V_7 ) ) {
V_296 &= ~ V_297 ;
V_296 |= V_101 ;
}
return V_296 ;
}
static bool F_99 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_298 ;
T_6 V_284 , V_97 ;
bool V_299 = ! V_1 -> V_300 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_180 ( & V_1 -> V_301 ) ;
V_1 -> V_300 = true ;
if ( F_75 ( V_1 ) )
return V_299 ;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
F_34 ( L_36 ,
F_33 ( V_3 -> V_19 ) ) ;
if ( ! F_74 ( V_1 ) )
F_175 ( V_1 ) ;
V_298 = F_179 ( V_1 ) ;
V_298 |= V_85 ;
V_284 = F_67 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
F_34 ( L_37 ,
F_31 ( V_284 ) , F_31 ( V_97 ) ) ;
if ( ! F_74 ( V_1 ) ) {
F_34 ( L_38 ,
F_33 ( V_3 -> V_19 ) ) ;
F_73 ( V_1 -> V_302 ) ;
}
return V_299 ;
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
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
enum V_56 V_57 ;
T_5 V_298 ;
T_6 V_284 , V_97 ;
F_45 ( & V_54 -> V_58 ) ;
F_46 ( V_1 -> V_300 ) ;
if ( ! F_75 ( V_1 ) )
return;
F_34 ( L_40 ,
F_33 ( V_3 -> V_19 ) ) ;
V_298 = F_179 ( V_1 ) ;
V_298 &= ~ V_85 ;
V_97 = F_63 ( V_1 ) ;
V_284 = F_67 ( V_1 ) ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
F_34 ( L_37 ,
F_31 ( V_284 ) , F_31 ( V_97 ) ) ;
if ( ( V_298 & V_303 ) == 0 )
V_1 -> V_289 = V_304 ;
V_57 = F_22 ( V_51 ) ;
F_27 ( V_54 , V_57 ) ;
}
static void F_184 ( struct V_305 * V_306 )
{
struct V_1 * V_1 = F_70 ( F_185 ( V_306 ) ,
struct V_1 , V_301 ) ;
F_21 ( V_1 ) ;
if ( ! V_1 -> V_300 )
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
unsigned long V_307 ;
V_307 = F_187 ( V_1 -> V_103 * 5 ) ;
F_188 ( & V_1 -> V_301 , V_307 ) ;
}
static void F_103 ( struct V_1 * V_1 , bool V_308 )
{
struct V_53 * V_54 =
F_3 ( V_1 ) -> V_55 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_182 ( ! V_1 -> V_300 , L_41 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
V_1 -> V_300 = false ;
if ( V_308 )
F_183 ( V_1 ) ;
else
F_186 ( V_1 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_298 ;
T_6 V_97 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_42 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
if ( F_9 ( F_74 ( V_1 ) ,
L_43 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) )
return;
F_175 ( V_1 ) ;
V_97 = F_63 ( V_1 ) ;
V_298 = F_179 ( V_1 ) ;
if ( F_190 ( V_7 ) ) {
V_298 &= ~ V_309 ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
}
V_298 |= V_303 ;
if ( ! F_190 ( V_7 ) )
V_298 |= V_309 ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
F_173 ( V_1 ) ;
V_1 -> V_292 = V_304 ;
if ( F_190 ( V_7 ) ) {
V_298 |= V_309 ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
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
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_298 ;
T_6 V_97 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_44 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
F_9 ( ! V_1 -> V_300 , L_45 ,
F_33 ( F_2 ( V_1 ) -> V_19 ) ) ;
V_298 = F_179 ( V_1 ) ;
V_298 &= ~ ( V_303 | V_309 | V_85 |
V_310 ) ;
V_97 = F_63 ( V_1 ) ;
V_1 -> V_300 = false ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
V_1 -> V_289 = V_304 ;
F_174 ( V_1 ) ;
V_57 = F_22 ( V_51 ) ;
F_27 ( V_54 , V_57 ) ;
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
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_298 ;
T_6 V_97 ;
F_177 ( V_1 ) ;
F_21 ( V_1 ) ;
V_298 = F_179 ( V_1 ) ;
V_298 |= V_310 ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
F_25 ( V_1 ) ;
}
void F_195 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_196 ( V_1 -> V_245 ) ;
F_194 ( V_1 ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_298 ;
T_6 V_97 ;
if ( ! F_1 ( V_1 ) )
return;
F_21 ( V_1 ) ;
V_298 = F_179 ( V_1 ) ;
V_298 &= ~ V_310 ;
V_97 = F_63 ( V_1 ) ;
F_41 ( V_97 , V_298 ) ;
F_42 ( V_97 ) ;
F_25 ( V_1 ) ;
V_1 -> V_294 = V_304 ;
F_178 ( V_1 ) ;
}
void F_198 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_34 ( L_46 ) ;
F_197 ( V_1 ) ;
F_199 ( V_1 -> V_245 ) ;
}
static void F_200 ( struct V_30 * V_9 ,
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
static const char * F_201 ( bool V_313 )
{
return V_313 ? L_50 : L_51 ;
}
static void F_202 ( struct V_1 * V_1 , bool V_314 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_53 * V_54 = F_122 ( V_212 -> V_4 . V_4 . V_7 ) ;
bool V_315 = F_31 ( V_1 -> V_68 ) & V_69 ;
F_182 ( V_315 != V_314 ,
L_52 ,
F_33 ( V_212 -> V_19 ) ,
F_201 ( V_314 ) , F_201 ( V_315 ) ) ;
}
static void F_203 ( struct V_53 * V_54 , bool V_314 )
{
bool V_315 = F_31 ( V_316 ) & V_317 ;
F_182 ( V_315 != V_314 ,
L_53 ,
F_201 ( V_314 ) , F_201 ( V_315 ) ) ;
}
static void F_204 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_243 * V_244 = F_157 ( V_3 -> V_4 . V_4 . V_244 ) ;
struct V_53 * V_54 = F_122 ( V_244 -> V_4 . V_7 ) ;
F_205 ( V_54 , V_244 -> V_59 ) ;
F_206 ( V_1 ) ;
F_207 ( V_54 ) ;
F_34 ( L_54 ,
V_244 -> V_271 -> V_199 ) ;
V_1 -> V_67 &= ~ V_318 ;
if ( V_244 -> V_271 -> V_199 == 162000 )
V_1 -> V_67 |= V_319 ;
else
V_1 -> V_67 |= V_320 ;
F_41 ( V_316 , V_1 -> V_67 ) ;
F_42 ( V_316 ) ;
F_208 ( 500 ) ;
V_1 -> V_67 |= V_317 ;
F_41 ( V_316 , V_1 -> V_67 ) ;
F_42 ( V_316 ) ;
F_208 ( 200 ) ;
}
static void F_209 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_243 * V_244 = F_157 ( V_3 -> V_4 . V_4 . V_244 ) ;
struct V_53 * V_54 = F_122 ( V_244 -> V_4 . V_7 ) ;
F_205 ( V_54 , V_244 -> V_59 ) ;
F_206 ( V_1 ) ;
F_210 ( V_54 ) ;
F_34 ( L_55 ) ;
V_1 -> V_67 &= ~ V_317 ;
F_41 ( V_316 , V_1 -> V_67 ) ;
F_42 ( V_316 ) ;
F_208 ( 200 ) ;
}
void F_211 ( struct V_1 * V_1 , int V_29 )
{
int V_130 , V_47 ;
if ( V_1 -> V_12 [ V_321 ] < 0x11 )
return;
if ( V_29 != V_322 ) {
V_130 = F_212 ( & V_1 -> V_148 , V_323 ,
V_324 ) ;
} else {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_130 = F_212 ( & V_1 -> V_148 , V_323 ,
V_325 ) ;
if ( V_130 == 1 )
break;
F_73 ( 1 ) ;
}
}
if ( V_130 != 1 )
F_34 ( L_56 ,
V_29 == V_322 ? L_48 : L_49 ) ;
}
static bool F_213 ( struct V_51 * V_52 ,
enum V_59 * V_59 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
T_5 V_83 ;
bool V_130 ;
V_57 = F_214 ( V_52 ) ;
if ( ! F_215 ( V_54 , V_57 ) )
return false ;
V_130 = false ;
V_83 = F_31 ( V_1 -> V_68 ) ;
if ( ! ( V_83 & V_69 ) )
goto V_137;
if ( F_167 ( V_7 ) && V_19 == V_20 ) {
* V_59 = F_216 ( V_83 ) ;
} else if ( F_169 ( V_7 ) && V_19 != V_20 ) {
enum V_59 V_326 ;
F_217 (dev_priv, p) {
T_5 V_278 = F_31 ( F_170 ( V_326 ) ) ;
if ( F_218 ( V_278 ) == V_19 ) {
* V_59 = V_326 ;
V_130 = true ;
goto V_137;
}
}
F_34 ( L_57 ,
F_219 ( V_1 -> V_68 ) ) ;
} else if ( F_36 ( V_7 ) ) {
* V_59 = F_220 ( V_83 ) ;
} else {
* V_59 = F_221 ( V_83 ) ;
}
V_130 = true ;
V_137:
F_27 ( V_54 , V_57 ) ;
return V_130 ;
}
static void F_222 ( struct V_51 * V_52 ,
struct V_191 * V_192 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
T_5 V_83 , V_41 = 0 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
int V_327 ;
V_83 = F_31 ( V_1 -> V_68 ) ;
V_192 -> V_255 = V_83 & V_328 && V_19 != V_20 ;
if ( F_169 ( V_7 ) && V_19 != V_20 ) {
T_5 V_278 = F_31 ( F_170 ( V_244 -> V_59 ) ) ;
if ( V_278 & V_329 )
V_41 |= V_272 ;
else
V_41 |= V_330 ;
if ( V_278 & V_331 )
V_41 |= V_274 ;
else
V_41 |= V_332 ;
} else {
if ( V_83 & V_273 )
V_41 |= V_272 ;
else
V_41 |= V_330 ;
if ( V_83 & V_275 )
V_41 |= V_274 ;
else
V_41 |= V_332 ;
}
V_192 -> V_4 . V_242 . V_41 |= V_41 ;
if ( ! F_66 ( V_7 ) && ! F_62 ( V_7 ) &&
! F_36 ( V_7 ) && V_83 & V_280 )
V_192 -> V_264 = true ;
V_192 -> V_253 = true ;
V_192 -> V_10 =
( ( V_83 & V_333 ) >> V_334 ) + 1 ;
F_223 ( V_244 , V_192 ) ;
if ( V_19 == V_20 ) {
if ( ( F_31 ( V_316 ) & V_318 ) == V_319 )
V_192 -> V_199 = 162000 ;
else
V_192 -> V_199 = 270000 ;
}
V_327 = F_224 ( V_192 -> V_199 ,
& V_192 -> V_265 ) ;
if ( F_66 ( V_54 -> V_7 ) && V_19 != V_20 )
F_225 ( V_192 , V_327 ) ;
V_192 -> V_4 . V_242 . V_257 = V_327 ;
if ( F_1 ( V_1 ) && V_54 -> V_174 . V_261 &&
V_192 -> V_258 > V_54 -> V_174 . V_261 ) {
F_34 ( L_58 ,
V_192 -> V_258 , V_54 -> V_174 . V_261 ) ;
V_54 -> V_174 . V_261 = V_192 -> V_258 ;
}
}
static void F_226 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
if ( V_244 -> V_271 -> V_255 )
F_227 ( V_52 ) ;
if ( F_228 ( V_7 ) && ! F_11 ( V_7 ) )
F_229 ( V_1 ) ;
F_181 ( V_1 ) ;
F_198 ( V_1 ) ;
F_211 ( V_1 , V_335 ) ;
F_193 ( V_1 ) ;
if ( F_119 ( V_7 ) -> V_182 < 5 )
F_230 ( V_1 ) ;
}
static void F_231 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
F_230 ( V_1 ) ;
if ( V_19 == V_20 )
F_209 ( V_1 ) ;
}
static void F_232 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_230 ( V_1 ) ;
}
static void F_233 ( struct V_51 * V_52 ,
bool V_336 )
{
struct V_53 * V_54 = F_122 ( V_52 -> V_4 . V_7 ) ;
enum V_65 V_66 = F_234 ( F_235 ( & V_52 -> V_4 ) ) ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
enum V_59 V_59 = V_244 -> V_59 ;
T_2 V_337 ;
V_337 = F_236 ( V_54 , V_59 , F_237 ( V_66 ) ) ;
if ( V_336 )
V_337 &= ~ ( V_338 | V_339 ) ;
else
V_337 |= V_338 | V_339 ;
F_238 ( V_54 , V_59 , F_237 ( V_66 ) , V_337 ) ;
if ( V_244 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_239 ( V_66 ) ) ;
if ( V_336 )
V_337 &= ~ ( V_338 | V_339 ) ;
else
V_337 |= V_338 | V_339 ;
F_238 ( V_54 , V_59 , F_239 ( V_66 ) , V_337 ) ;
}
V_337 = F_236 ( V_54 , V_59 , F_240 ( V_66 ) ) ;
V_337 |= V_340 ;
if ( V_336 )
V_337 &= ~ V_341 ;
else
V_337 |= V_341 ;
F_238 ( V_54 , V_59 , F_240 ( V_66 ) , V_337 ) ;
if ( V_244 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_241 ( V_66 ) ) ;
V_337 |= V_340 ;
if ( V_336 )
V_337 &= ~ V_341 ;
else
V_337 |= V_341 ;
F_238 ( V_54 , V_59 , F_241 ( V_66 ) , V_337 ) ;
}
}
static void F_242 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_230 ( V_1 ) ;
F_24 ( & V_54 -> V_342 ) ;
F_233 ( V_52 , true ) ;
F_26 ( & V_54 -> V_342 ) ;
}
static void
F_243 ( struct V_1 * V_1 ,
T_2 * V_67 ,
T_3 V_343 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
if ( F_11 ( V_7 ) ) {
T_2 V_344 = F_31 ( F_244 ( V_19 ) ) ;
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
F_41 ( F_244 ( V_19 ) , V_344 ) ;
} else if ( ( F_167 ( V_7 ) && V_19 == V_20 ) ||
( F_169 ( V_7 ) && V_19 != V_20 ) ) {
* V_67 &= ~ V_357 ;
switch ( V_343 & V_348 ) {
case V_349 :
* V_67 |= V_276 ;
break;
case V_351 :
* V_67 |= V_358 ;
break;
case V_353 :
* V_67 |= V_359 ;
break;
case V_355 :
F_82 ( L_59 ) ;
* V_67 |= V_359 ;
break;
}
} else {
if ( F_36 ( V_7 ) )
* V_67 &= ~ V_360 ;
else
* V_67 &= ~ V_361 ;
switch ( V_343 & V_348 ) {
case V_349 :
* V_67 |= V_281 ;
break;
case V_351 :
* V_67 |= V_73 ;
break;
case V_353 :
* V_67 |= V_362 ;
break;
case V_355 :
if ( F_36 ( V_7 ) ) {
* V_67 |= V_363 ;
} else {
F_82 ( L_59 ) ;
* V_67 |= V_362 ;
}
break;
}
}
}
static void F_245 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_244 =
F_157 ( F_2 ( V_1 ) -> V_4 . V_4 . V_244 ) ;
F_243 ( V_1 , & V_1 -> V_67 ,
V_351 ) ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_1 -> V_67 |= V_69 ;
if ( V_244 -> V_271 -> V_255 )
V_1 -> V_67 |= V_328 ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
}
static void F_246 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
T_2 V_364 = F_31 ( V_1 -> V_68 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
enum V_59 V_59 = V_244 -> V_59 ;
if ( F_46 ( V_364 & V_69 ) )
return;
F_21 ( V_1 ) ;
if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
F_247 ( V_1 ) ;
if ( V_19 == V_20 )
F_248 ( V_54 , V_59 , false ) ;
F_245 ( V_1 ) ;
if ( V_19 == V_20 && F_190 ( V_54 ) ) {
F_249 ( V_54 -> V_7 , ! V_59 ) ;
F_248 ( V_54 , ! V_59 , true ) ;
F_250 ( V_54 , ! V_59 , true ) ;
}
F_99 ( V_1 ) ;
F_189 ( V_1 ) ;
F_103 ( V_1 , true ) ;
if ( V_19 == V_20 )
F_248 ( V_54 , V_59 , true ) ;
F_25 ( V_1 ) ;
if ( F_62 ( V_7 ) || F_36 ( V_7 ) ) {
unsigned int V_365 = 0x0 ;
if ( F_36 ( V_7 ) )
V_365 = F_7 ( V_244 -> V_271 -> V_10 ) ;
F_251 ( V_54 , F_2 ( V_1 ) ,
V_365 ) ;
}
F_211 ( V_1 , V_322 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
if ( V_244 -> V_271 -> V_255 ) {
F_254 ( L_60 ,
F_32 ( V_59 ) ) ;
F_255 ( V_52 ) ;
}
}
static void F_256 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_246 ( V_52 ) ;
F_195 ( V_1 ) ;
}
static void F_257 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
F_195 ( V_1 ) ;
F_258 ( V_1 ) ;
}
static void F_259 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_122 ( V_52 -> V_4 . V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
enum V_59 V_59 = F_157 ( V_52 -> V_4 . V_244 ) -> V_59 ;
F_166 ( V_52 ) ;
if ( V_19 == V_20 && F_190 ( V_54 ) ) {
F_248 ( V_54 , ! V_59 , false ) ;
F_250 ( V_54 , ! V_59 , false ) ;
}
if ( V_19 == V_20 )
F_204 ( V_1 ) ;
}
static void F_260 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 = V_3 -> V_4 . V_4 . V_7 -> V_55 ;
enum V_59 V_59 = V_1 -> V_60 ;
T_6 V_366 = F_58 ( V_59 ) ;
F_183 ( V_1 ) ;
F_34 ( L_61 ,
F_32 ( V_59 ) , F_33 ( V_3 -> V_19 ) ) ;
F_41 ( V_366 , 0 ) ;
F_42 ( V_366 ) ;
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
F_47 (dev, encoder) {
struct V_1 * V_1 ;
enum V_19 V_19 ;
if ( V_52 -> type != V_5 )
continue;
V_1 = F_5 ( & V_52 -> V_4 ) ;
V_19 = F_2 ( V_1 ) -> V_19 ;
if ( V_1 -> V_60 != V_59 )
continue;
F_34 ( L_62 ,
F_32 ( V_59 ) , F_33 ( V_19 ) ) ;
F_9 ( V_52 -> V_4 . V_244 ,
L_63 ,
F_32 ( V_59 ) , F_33 ( V_19 ) ) ;
F_260 ( V_1 ) ;
}
}
static void F_247 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_52 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_244 = F_157 ( V_52 -> V_4 . V_244 ) ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_60 == V_244 -> V_59 )
return;
if ( V_1 -> V_60 != V_82 )
F_260 ( V_1 ) ;
F_49 ( V_7 , V_244 -> V_59 ) ;
V_1 -> V_60 = V_244 -> V_59 ;
F_34 ( L_64 ,
F_32 ( V_1 -> V_60 ) , F_33 ( V_3 -> V_19 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
static void F_261 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_2 * V_367 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_243 = F_157 ( V_52 -> V_4 . V_244 ) ;
enum V_65 V_19 = F_234 ( V_367 ) ;
int V_59 = V_243 -> V_59 ;
T_5 V_337 ;
F_24 ( & V_54 -> V_342 ) ;
V_337 = F_236 ( V_54 , V_59 , F_262 ( V_19 ) ) ;
V_337 = 0 ;
if ( V_59 )
V_337 |= ( 1 << 21 ) ;
else
V_337 &= ~ ( 1 << 21 ) ;
V_337 |= 0x001000c4 ;
F_238 ( V_54 , V_59 , F_263 ( V_19 ) , V_337 ) ;
F_238 ( V_54 , V_59 , F_264 ( V_19 ) , 0x00760018 ) ;
F_238 ( V_54 , V_59 , F_265 ( V_19 ) , 0x00400888 ) ;
F_26 ( & V_54 -> V_342 ) ;
F_246 ( V_52 ) ;
}
static void F_266 ( struct V_51 * V_52 )
{
struct V_2 * V_367 = F_235 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_243 =
F_157 ( V_52 -> V_4 . V_244 ) ;
enum V_65 V_19 = F_234 ( V_367 ) ;
int V_59 = V_243 -> V_59 ;
F_166 ( V_52 ) ;
F_24 ( & V_54 -> V_342 ) ;
F_238 ( V_54 , V_59 , F_267 ( V_19 ) ,
V_338 |
V_339 ) ;
F_238 ( V_54 , V_59 , F_268 ( V_19 ) ,
V_368 |
V_369 |
( 1 << V_370 ) |
V_341 ) ;
F_238 ( V_54 , V_59 , F_269 ( V_19 ) , 0x00750f00 ) ;
F_238 ( V_54 , V_59 , F_270 ( V_19 ) , 0x00001500 ) ;
F_238 ( V_54 , V_59 , F_271 ( V_19 ) , 0x40400000 ) ;
F_26 ( & V_54 -> V_342 ) ;
}
static void F_272 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_5 ( & V_52 -> V_4 ) ;
struct V_2 * V_367 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_243 =
F_157 ( V_52 -> V_4 . V_244 ) ;
enum V_65 V_66 = F_234 ( V_367 ) ;
int V_59 = V_243 -> V_59 ;
int V_371 , V_47 , V_372 ;
T_5 V_337 ;
F_24 ( & V_54 -> V_342 ) ;
V_337 = F_236 ( V_54 , V_59 , F_273 ( V_66 ) ) ;
V_337 &= ~ V_373 ;
F_238 ( V_54 , V_59 , F_273 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_274 ( V_66 ) ) ;
V_337 &= ~ V_373 ;
F_238 ( V_54 , V_59 , F_274 ( V_66 ) , V_337 ) ;
}
for ( V_47 = 0 ; V_47 < V_243 -> V_271 -> V_10 ; V_47 ++ ) {
if ( V_243 -> V_271 -> V_10 == 1 )
V_371 = 0x0 ;
else
V_371 = ( V_47 == 1 ) ? 0x0 : 0x1 ;
F_238 ( V_54 , V_59 , F_275 ( V_66 , V_47 ) ,
V_371 << V_374 ) ;
}
if ( V_243 -> V_271 -> V_199 > 270000 )
V_372 = 0x18 ;
else if ( V_243 -> V_271 -> V_199 > 135000 )
V_372 = 0xd ;
else if ( V_243 -> V_271 -> V_199 > 67500 )
V_372 = 0x7 ;
else if ( V_243 -> V_271 -> V_199 > 33750 )
V_372 = 0x4 ;
else
V_372 = 0x2 ;
V_337 = F_236 ( V_54 , V_59 , F_273 ( V_66 ) ) ;
V_337 |= F_276 ( 0x1f ) ;
F_238 ( V_54 , V_59 , F_273 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_274 ( V_66 ) ) ;
V_337 |= F_276 ( 0x1f ) ;
F_238 ( V_54 , V_59 , F_274 ( V_66 ) , V_337 ) ;
}
F_238 ( V_54 , V_59 , F_277 ( V_66 ) ,
F_278 ( V_372 ) |
V_375 |
F_279 ( 0x1f ) |
F_280 ( 6 ) |
F_281 ( 0 ) ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
F_238 ( V_54 , V_59 , F_282 ( V_66 ) ,
F_278 ( V_372 ) |
V_375 |
F_279 ( 0x1f ) |
F_280 ( 7 ) |
F_281 ( 5 ) ) ;
}
F_233 ( V_52 , false ) ;
F_26 ( & V_54 -> V_342 ) ;
F_246 ( V_52 ) ;
if ( V_367 -> V_376 ) {
F_39 ( V_54 , V_377 , V_378 , false ) ;
V_367 -> V_376 = false ;
}
}
static void F_283 ( struct V_51 * V_52 )
{
struct V_2 * V_367 = F_235 ( & V_52 -> V_4 ) ;
struct V_6 * V_7 = V_52 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_243 * V_243 =
F_157 ( V_52 -> V_4 . V_244 ) ;
enum V_65 V_66 = F_234 ( V_367 ) ;
enum V_59 V_59 = V_243 -> V_59 ;
unsigned int V_365 =
F_7 ( V_243 -> V_271 -> V_10 ) ;
T_5 V_337 ;
F_166 ( V_52 ) ;
if ( V_66 == V_379 && V_59 == V_74 )
V_367 -> V_376 =
! F_39 ( V_54 , V_377 , V_378 , true ) ;
F_284 ( V_52 , true , V_365 ) ;
F_24 ( & V_54 -> V_342 ) ;
F_233 ( V_52 , true ) ;
if ( V_59 != V_74 ) {
V_337 = F_236 ( V_54 , V_59 , V_380 ) ;
V_337 &= ~ ( V_381 | V_382 ) ;
if ( V_66 == V_379 )
V_337 |= V_383 ;
if ( V_66 == V_378 )
V_337 |= V_384 ;
F_238 ( V_54 , V_59 , V_380 , V_337 ) ;
} else {
V_337 = F_236 ( V_54 , V_59 , V_385 ) ;
V_337 &= ~ ( V_386 | V_387 ) ;
if ( V_66 == V_379 )
V_337 |= V_388 ;
if ( V_66 == V_378 )
V_337 |= V_389 ;
F_238 ( V_54 , V_59 , V_385 , V_337 ) ;
}
V_337 = F_236 ( V_54 , V_59 , F_262 ( V_66 ) ) ;
V_337 |= V_390 ;
if ( V_59 != V_74 )
V_337 &= ~ V_391 ;
else
V_337 |= V_391 ;
F_238 ( V_54 , V_59 , F_262 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_285 ( V_66 ) ) ;
V_337 |= V_390 ;
if ( V_59 != V_74 )
V_337 &= ~ V_391 ;
else
V_337 |= V_391 ;
F_238 ( V_54 , V_59 , F_285 ( V_66 ) , V_337 ) ;
}
V_337 = F_236 ( V_54 , V_59 , F_286 ( V_66 ) ) ;
if ( V_59 != V_74 )
V_337 &= ~ V_392 ;
else
V_337 |= V_392 ;
F_238 ( V_54 , V_59 , F_286 ( V_66 ) , V_337 ) ;
F_26 ( & V_54 -> V_342 ) ;
}
static void F_287 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_122 ( V_52 -> V_4 . V_7 ) ;
enum V_59 V_59 = F_157 ( V_52 -> V_4 . V_244 ) -> V_59 ;
T_5 V_337 ;
F_24 ( & V_54 -> V_342 ) ;
if ( V_59 != V_74 ) {
V_337 = F_236 ( V_54 , V_59 , V_380 ) ;
V_337 &= ~ ( V_381 | V_382 ) ;
F_238 ( V_54 , V_59 , V_380 , V_337 ) ;
} else {
V_337 = F_236 ( V_54 , V_59 , V_385 ) ;
V_337 &= ~ ( V_386 | V_387 ) ;
F_238 ( V_54 , V_59 , V_385 , V_337 ) ;
}
F_26 ( & V_54 -> V_342 ) ;
F_284 ( V_52 , false , 0x0 ) ;
}
static T_7
F_288 ( struct V_147 * V_148 , unsigned int V_393 ,
void * V_164 , T_8 V_157 )
{
T_7 V_130 ;
int V_47 ;
F_289 ( V_148 , V_321 , V_164 , 1 ) ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_130 = F_289 ( V_148 , V_393 , V_164 , V_157 ) ;
if ( V_130 == V_157 )
return V_130 ;
F_73 ( 1 ) ;
}
return V_130 ;
}
bool
F_290 ( struct V_1 * V_1 , T_3 V_394 [ V_395 ] )
{
return F_288 ( & V_1 -> V_148 ,
V_396 ,
V_394 ,
V_395 ) == V_395 ;
}
T_3
F_291 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
if ( F_64 ( V_7 ) )
return V_397 ;
else if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
if ( V_54 -> V_398 && V_19 == V_20 )
return V_397 ;
return V_399 ;
} else if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
return V_397 ;
else if ( F_167 ( V_7 ) && V_19 == V_20 )
return V_399 ;
else if ( F_169 ( V_7 ) && V_19 != V_20 )
return V_397 ;
else
return V_399 ;
}
T_3
F_292 ( struct V_1 * V_1 , T_3 V_400 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 ) {
switch ( V_400 & V_401 ) {
case V_402 :
return V_403 ;
case V_404 :
return V_405 ;
case V_399 :
return V_406 ;
case V_397 :
return V_407 ;
default:
return V_407 ;
}
} else if ( F_141 ( V_7 ) || F_94 ( V_7 ) ) {
switch ( V_400 & V_401 ) {
case V_402 :
return V_403 ;
case V_404 :
return V_405 ;
case V_399 :
return V_406 ;
case V_397 :
default:
return V_407 ;
}
} else if ( F_62 ( V_7 ) || F_36 ( V_7 ) ) {
switch ( V_400 & V_401 ) {
case V_402 :
return V_403 ;
case V_404 :
return V_405 ;
case V_399 :
return V_406 ;
case V_397 :
default:
return V_407 ;
}
} else if ( F_167 ( V_7 ) && V_19 == V_20 ) {
switch ( V_400 & V_401 ) {
case V_402 :
return V_405 ;
case V_404 :
case V_399 :
return V_406 ;
default:
return V_407 ;
}
} else {
switch ( V_400 & V_401 ) {
case V_402 :
return V_405 ;
case V_404 :
return V_405 ;
case V_399 :
return V_406 ;
case V_397 :
default:
return V_407 ;
}
}
}
static T_2 F_293 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_367 = F_2 ( V_1 ) ;
struct V_243 * V_243 =
F_157 ( V_367 -> V_4 . V_4 . V_244 ) ;
unsigned long V_408 , V_409 ,
V_410 ;
T_3 V_411 = V_1 -> V_411 [ 0 ] ;
enum V_65 V_19 = F_234 ( V_367 ) ;
int V_59 = V_243 -> V_59 ;
switch ( V_411 & V_412 ) {
case V_407 :
V_409 = 0x0004000 ;
switch ( V_411 & V_401 ) {
case V_402 :
V_408 = 0x2B405555 ;
V_410 = 0x552AB83A ;
break;
case V_404 :
V_408 = 0x2B404040 ;
V_410 = 0x5548B83A ;
break;
case V_399 :
V_408 = 0x2B245555 ;
V_410 = 0x5560B83A ;
break;
case V_397 :
V_408 = 0x2B405555 ;
V_410 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_406 :
V_409 = 0x0002000 ;
switch ( V_411 & V_401 ) {
case V_402 :
V_408 = 0x2B404040 ;
V_410 = 0x5552B83A ;
break;
case V_404 :
V_408 = 0x2B404848 ;
V_410 = 0x5580B83A ;
break;
case V_399 :
V_408 = 0x2B404040 ;
V_410 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_405 :
V_409 = 0x0000000 ;
switch ( V_411 & V_401 ) {
case V_402 :
V_408 = 0x2B305555 ;
V_410 = 0x5570B83A ;
break;
case V_404 :
V_408 = 0x2B2B4040 ;
V_410 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_403 :
V_409 = 0x0006000 ;
switch ( V_411 & V_401 ) {
case V_402 :
V_408 = 0x1B405555 ;
V_410 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_54 -> V_342 ) ;
F_238 ( V_54 , V_59 , F_294 ( V_19 ) , 0x00000000 ) ;
F_238 ( V_54 , V_59 , F_295 ( V_19 ) , V_408 ) ;
F_238 ( V_54 , V_59 , F_296 ( V_19 ) ,
V_410 ) ;
F_238 ( V_54 , V_59 , F_297 ( V_19 ) , 0x0C782040 ) ;
F_238 ( V_54 , V_59 , F_298 ( V_19 ) , 0x00030000 ) ;
F_238 ( V_54 , V_59 , F_299 ( V_19 ) , V_409 ) ;
F_238 ( V_54 , V_59 , F_294 ( V_19 ) , 0x80000000 ) ;
F_26 ( & V_54 -> V_342 ) ;
return 0 ;
}
static bool F_300 ( T_3 V_411 )
{
return ( V_411 & V_412 ) == V_407 &&
( V_411 & V_401 ) == V_397 ;
}
static T_2 F_301 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_367 = F_2 ( V_1 ) ;
struct V_243 * V_243 = F_157 ( V_367 -> V_4 . V_4 . V_244 ) ;
T_5 V_413 , V_414 , V_337 ;
T_3 V_411 = V_1 -> V_411 [ 0 ] ;
enum V_65 V_66 = F_234 ( V_367 ) ;
enum V_59 V_59 = V_243 -> V_59 ;
int V_47 ;
switch ( V_411 & V_412 ) {
case V_407 :
switch ( V_411 & V_401 ) {
case V_402 :
V_413 = 128 ;
V_414 = 52 ;
break;
case V_404 :
V_413 = 128 ;
V_414 = 77 ;
break;
case V_399 :
V_413 = 128 ;
V_414 = 102 ;
break;
case V_397 :
V_413 = 128 ;
V_414 = 154 ;
break;
default:
return 0 ;
}
break;
case V_406 :
switch ( V_411 & V_401 ) {
case V_402 :
V_413 = 85 ;
V_414 = 78 ;
break;
case V_404 :
V_413 = 85 ;
V_414 = 116 ;
break;
case V_399 :
V_413 = 85 ;
V_414 = 154 ;
break;
default:
return 0 ;
}
break;
case V_405 :
switch ( V_411 & V_401 ) {
case V_402 :
V_413 = 64 ;
V_414 = 104 ;
break;
case V_404 :
V_413 = 64 ;
V_414 = 154 ;
break;
default:
return 0 ;
}
break;
case V_403 :
switch ( V_411 & V_401 ) {
case V_402 :
V_413 = 43 ;
V_414 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_24 ( & V_54 -> V_342 ) ;
V_337 = F_236 ( V_54 , V_59 , F_302 ( V_66 ) ) ;
V_337 &= ~ ( V_415 | V_416 ) ;
V_337 &= ~ ( V_417 | V_418 ) ;
V_337 |= V_419 | V_420 ;
F_238 ( V_54 , V_59 , F_302 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_303 ( V_66 ) ) ;
V_337 &= ~ ( V_415 | V_416 ) ;
V_337 &= ~ ( V_417 | V_418 ) ;
V_337 |= V_419 | V_420 ;
F_238 ( V_54 , V_59 , F_303 ( V_66 ) , V_337 ) ;
}
V_337 = F_236 ( V_54 , V_59 , F_304 ( V_66 ) ) ;
V_337 &= ~ ( V_421 | V_422 ) ;
V_337 |= V_423 | V_424 ;
F_238 ( V_54 , V_59 , F_304 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_305 ( V_66 ) ) ;
V_337 &= ~ ( V_421 | V_422 ) ;
V_337 |= V_423 | V_424 ;
F_238 ( V_54 , V_59 , F_305 ( V_66 ) , V_337 ) ;
}
for ( V_47 = 0 ; V_47 < V_243 -> V_271 -> V_10 ; V_47 ++ ) {
V_337 = F_236 ( V_54 , V_59 , F_306 ( V_66 , V_47 ) ) ;
V_337 &= ~ V_425 ;
V_337 |= V_413 << V_426 ;
F_238 ( V_54 , V_59 , F_306 ( V_66 , V_47 ) , V_337 ) ;
}
for ( V_47 = 0 ; V_47 < V_243 -> V_271 -> V_10 ; V_47 ++ ) {
V_337 = F_236 ( V_54 , V_59 , F_307 ( V_66 , V_47 ) ) ;
V_337 &= ~ V_427 ;
V_337 |= V_414 << V_428 ;
V_337 &= ~ ( 0xff << V_429 ) ;
V_337 |= 0x9a << V_429 ;
F_238 ( V_54 , V_59 , F_307 ( V_66 , V_47 ) , V_337 ) ;
}
for ( V_47 = 0 ; V_47 < V_243 -> V_271 -> V_10 ; V_47 ++ ) {
V_337 = F_236 ( V_54 , V_59 , F_308 ( V_66 , V_47 ) ) ;
if ( F_300 ( V_411 ) )
V_337 |= V_430 ;
else
V_337 &= ~ V_430 ;
F_238 ( V_54 , V_59 , F_308 ( V_66 , V_47 ) , V_337 ) ;
}
V_337 = F_236 ( V_54 , V_59 , F_302 ( V_66 ) ) ;
V_337 |= V_415 | V_416 ;
F_238 ( V_54 , V_59 , F_302 ( V_66 ) , V_337 ) ;
if ( V_243 -> V_271 -> V_10 > 2 ) {
V_337 = F_236 ( V_54 , V_59 , F_303 ( V_66 ) ) ;
V_337 |= V_415 | V_416 ;
F_238 ( V_54 , V_59 , F_303 ( V_66 ) , V_337 ) ;
}
F_26 ( & V_54 -> V_342 ) ;
return 0 ;
}
static T_2
F_309 ( T_3 V_411 )
{
T_2 V_431 = 0 ;
switch ( V_411 & V_401 ) {
case V_402 :
default:
V_431 |= V_71 ;
break;
case V_404 :
V_431 |= V_432 ;
break;
case V_399 :
V_431 |= V_433 ;
break;
case V_397 :
V_431 |= V_434 ;
break;
}
switch ( V_411 & V_412 ) {
case V_407 :
default:
V_431 |= V_72 ;
break;
case V_406 :
V_431 |= V_435 ;
break;
case V_405 :
V_431 |= V_436 ;
break;
case V_403 :
V_431 |= V_437 ;
break;
}
return V_431 ;
}
static T_2
F_310 ( T_3 V_411 )
{
int V_431 = V_411 & ( V_401 |
V_412 ) ;
switch ( V_431 ) {
case V_402 | V_407 :
case V_404 | V_407 :
return V_438 ;
case V_402 | V_406 :
return V_439 ;
case V_402 | V_405 :
case V_404 | V_405 :
return V_440 ;
case V_404 | V_406 :
case V_399 | V_406 :
return V_441 ;
case V_399 | V_407 :
case V_397 | V_407 :
return V_442 ;
default:
F_34 ( L_65
L_66 , V_431 ) ;
return V_438 ;
}
}
static T_2
F_311 ( T_3 V_411 )
{
int V_431 = V_411 & ( V_401 |
V_412 ) ;
switch ( V_431 ) {
case V_402 | V_407 :
return V_443 ;
case V_402 | V_406 :
return V_444 ;
case V_402 | V_405 :
return V_445 ;
case V_404 | V_407 :
return V_446 ;
case V_404 | V_406 :
return V_447 ;
case V_399 | V_407 :
return V_448 ;
case V_399 | V_406 :
return V_449 ;
default:
F_34 ( L_65
L_66 , V_431 ) ;
return V_450 ;
}
}
void
F_312 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = F_122 ( V_7 ) ;
T_2 V_431 , V_282 = 0 ;
T_3 V_411 = V_1 -> V_411 [ 0 ] ;
if ( F_11 ( V_7 ) ) {
V_431 = F_313 ( V_1 ) ;
if ( F_64 ( V_7 ) )
V_431 = 0 ;
else
V_282 = V_451 ;
} else if ( F_36 ( V_7 ) ) {
V_431 = F_301 ( V_1 ) ;
} else if ( F_62 ( V_7 ) ) {
V_431 = F_293 ( V_1 ) ;
} else if ( F_167 ( V_7 ) && V_19 == V_20 ) {
V_431 = F_311 ( V_411 ) ;
V_282 = V_452 ;
} else if ( F_93 ( V_7 ) && V_19 == V_20 ) {
V_431 = F_310 ( V_411 ) ;
V_282 = V_453 ;
} else {
V_431 = F_309 ( V_411 ) ;
V_282 = V_454 | V_455 ;
}
if ( V_282 )
F_34 ( L_67 , V_431 ) ;
F_34 ( L_68 ,
V_411 & V_401 ) ;
F_34 ( L_69 ,
( V_411 & V_412 ) >>
V_456 ) ;
V_1 -> V_67 = ( V_1 -> V_67 & ~ V_282 ) | V_431 ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
}
void
F_314 ( struct V_1 * V_1 ,
T_3 V_343 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_53 * V_54 =
F_122 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_243 ( V_1 , & V_1 -> V_67 , V_343 ) ;
F_41 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
}
void F_315 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
T_2 V_337 ;
if ( ! F_11 ( V_7 ) )
return;
V_337 = F_31 ( F_244 ( V_19 ) ) ;
V_337 &= ~ V_347 ;
V_337 |= V_457 ;
F_41 ( F_244 ( V_19 ) , V_337 ) ;
if ( V_19 == V_20 )
return;
if ( F_316 ( ( F_31 ( F_317 ( V_19 ) ) & V_458 ) ,
1 ) )
F_82 ( L_70 ) ;
}
static void
F_230 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_243 * V_244 = F_157 ( V_3 -> V_4 . V_4 . V_244 ) ;
enum V_19 V_19 = V_3 -> V_19 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_67 = V_1 -> V_67 ;
if ( F_46 ( F_11 ( V_7 ) ) )
return;
if ( F_46 ( ( F_31 ( V_1 -> V_68 ) & V_69 ) == 0 ) )
return;
F_34 ( L_46 ) ;
if ( ( F_167 ( V_7 ) && V_19 == V_20 ) ||
( F_169 ( V_7 ) && V_19 != V_20 ) ) {
V_67 &= ~ V_357 ;
V_67 |= V_459 ;
} else {
if ( F_36 ( V_7 ) )
V_67 &= ~ V_360 ;
else
V_67 &= ~ V_361 ;
V_67 |= V_460 ;
}
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_67 &= ~ ( V_69 | V_328 ) ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
if ( F_318 ( V_7 ) && V_244 -> V_59 == V_74 && V_19 != V_20 ) {
F_248 ( V_54 , V_81 , false ) ;
F_250 ( V_54 , V_81 , false ) ;
V_67 &= ~ ( V_75 | V_361 ) ;
V_67 |= V_69 | V_73 ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
V_67 &= ~ V_69 ;
F_41 ( V_1 -> V_68 , V_67 ) ;
F_42 ( V_1 -> V_68 ) ;
F_249 ( V_54 -> V_7 , V_81 ) ;
F_248 ( V_54 , V_81 , true ) ;
F_250 ( V_54 , V_81 , true ) ;
}
F_73 ( V_1 -> V_461 ) ;
V_1 -> V_67 = V_67 ;
}
static bool
F_319 ( struct V_1 * V_1 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_3 V_462 ;
if ( F_288 ( & V_1 -> V_148 , 0x000 , V_1 -> V_12 ,
sizeof( V_1 -> V_12 ) ) < 0 )
return false ;
F_34 ( L_71 , ( int ) sizeof( V_1 -> V_12 ) , V_1 -> V_12 ) ;
if ( V_1 -> V_12 [ V_321 ] == 0 )
return false ;
memset ( V_1 -> V_463 , 0 , sizeof( V_1 -> V_463 ) ) ;
if ( F_1 ( V_1 ) ) {
F_288 ( & V_1 -> V_148 , V_464 ,
V_1 -> V_463 ,
sizeof( V_1 -> V_463 ) ) ;
if ( V_1 -> V_463 [ 0 ] & V_465 ) {
V_54 -> V_466 . V_467 = true ;
F_34 ( L_72 ) ;
}
if ( F_119 ( V_7 ) -> V_182 >= 9 &&
( V_1 -> V_463 [ 0 ] & V_468 ) ) {
T_3 V_469 ;
V_54 -> V_466 . V_467 = true ;
F_288 ( & V_1 -> V_148 ,
V_470 ,
& V_469 , 1 ) ;
V_54 -> V_466 . V_471 = V_469 ? true : false ;
V_54 -> V_466 . V_472 = V_54 -> V_466 . V_471 ;
F_34 ( L_73 ,
V_54 -> V_466 . V_472 ? L_74 : L_75 ) ;
}
}
F_34 ( L_76 ,
F_320 ( F_139 ( V_1 ) ) ,
F_320 ( F_321 ( V_1 -> V_12 ) ) ) ;
if ( F_1 ( V_1 ) &&
( V_1 -> V_12 [ V_473 ] & V_474 ) &&
( F_288 ( & V_1 -> V_148 , V_475 , & V_462 , 1 ) == 1 ) &&
( V_462 >= 0x03 ) ) {
T_9 V_209 [ V_228 ] ;
int V_47 ;
F_288 ( & V_1 -> V_148 ,
V_476 ,
V_209 ,
sizeof( V_209 ) ) ;
for ( V_47 = 0 ; V_47 < F_123 ( V_209 ) ; V_47 ++ ) {
int V_337 = F_322 ( V_209 [ V_47 ] ) ;
if ( V_337 == 0 )
break;
V_1 -> V_209 [ V_47 ] = ( V_337 * 200 ) / 10 ;
}
V_1 -> V_210 = V_47 ;
}
F_151 ( V_1 ) ;
if ( ! ( V_1 -> V_12 [ V_477 ] &
V_478 ) )
return true ;
if ( V_1 -> V_12 [ V_321 ] == 0x10 )
return true ;
if ( F_288 ( & V_1 -> V_148 , V_479 ,
V_1 -> V_480 ,
V_481 ) < 0 )
return false ;
return true ;
}
static void
F_323 ( struct V_1 * V_1 )
{
T_1 V_482 [ 3 ] ;
if ( ! ( V_1 -> V_12 [ V_483 ] & V_484 ) )
return;
if ( F_288 ( & V_1 -> V_148 , V_485 , V_482 , 3 ) == 3 )
F_34 ( L_77 ,
V_482 [ 0 ] , V_482 [ 1 ] , V_482 [ 2 ] ) ;
if ( F_288 ( & V_1 -> V_148 , V_486 , V_482 , 3 ) == 3 )
F_34 ( L_78 ,
V_482 [ 0 ] , V_482 [ 1 ] , V_482 [ 2 ] ) ;
}
static bool
F_324 ( struct V_1 * V_1 )
{
T_1 V_482 [ 1 ] ;
if ( ! V_1 -> V_487 )
return false ;
if ( V_1 -> V_12 [ V_321 ] < 0x12 )
return false ;
if ( F_288 ( & V_1 -> V_148 , V_488 , V_482 , 1 ) ) {
if ( V_482 [ 0 ] & V_489 ) {
F_34 ( L_79 ) ;
V_1 -> V_490 = true ;
} else {
F_34 ( L_80 ) ;
V_1 -> V_490 = false ;
}
}
F_325 ( & V_1 -> V_491 , V_1 -> V_490 ) ;
return V_1 -> V_490 ;
}
static int F_326 ( struct V_1 * V_1 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
struct V_243 * V_243 = F_157 ( V_212 -> V_4 . V_4 . V_244 ) ;
T_1 V_482 ;
int V_130 = 0 ;
int V_219 = 0 ;
int V_492 = 10 ;
if ( F_327 ( & V_1 -> V_148 , V_493 , & V_482 ) < 0 ) {
F_34 ( L_81 ) ;
V_130 = - V_143 ;
goto V_137;
}
if ( F_212 ( & V_1 -> V_148 , V_493 ,
V_482 & ~ V_494 ) < 0 ) {
F_34 ( L_81 ) ;
V_130 = - V_143 ;
goto V_137;
}
do {
F_328 ( V_7 , V_243 -> V_59 ) ;
if ( F_327 ( & V_1 -> V_148 ,
V_495 , & V_482 ) < 0 ) {
V_130 = - V_143 ;
goto V_137;
}
V_219 = V_482 & V_496 ;
} while ( -- V_492 && V_219 );
if ( V_492 == 0 ) {
F_82 ( L_82 ) ;
V_130 = - V_144 ;
}
V_137:
F_329 ( V_243 ) ;
return V_130 ;
}
static int F_330 ( struct V_1 * V_1 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
struct V_243 * V_243 = F_157 ( V_212 -> V_4 . V_4 . V_244 ) ;
T_1 V_482 ;
int V_130 ;
if ( F_327 ( & V_1 -> V_148 , V_495 , & V_482 ) < 0 )
return - V_143 ;
if ( ! ( V_482 & V_497 ) )
return - V_498 ;
if ( F_327 ( & V_1 -> V_148 , V_493 , & V_482 ) < 0 )
return - V_143 ;
if ( V_482 & V_494 ) {
V_130 = F_326 ( V_1 ) ;
if ( V_130 )
return V_130 ;
}
F_331 ( V_243 ) ;
if ( F_212 ( & V_1 -> V_148 , V_493 ,
V_482 | V_494 ) < 0 ) {
F_329 ( V_243 ) ;
return - V_143 ;
}
F_328 ( V_7 , V_243 -> V_59 ) ;
return 0 ;
}
int F_332 ( struct V_1 * V_1 , T_1 * V_499 )
{
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_212 -> V_4 . V_4 . V_7 ;
struct V_243 * V_243 = F_157 ( V_212 -> V_4 . V_4 . V_244 ) ;
T_1 V_482 ;
int V_219 , V_130 ;
int V_492 = 6 ;
V_130 = F_330 ( V_1 ) ;
if ( V_130 )
return V_130 ;
do {
F_328 ( V_7 , V_243 -> V_59 ) ;
if ( F_327 ( & V_1 -> V_148 ,
V_495 , & V_482 ) < 0 ) {
V_130 = - V_143 ;
goto V_500;
}
V_219 = V_482 & V_496 ;
} while ( -- V_492 && V_219 == 0 );
if ( V_492 == 0 ) {
F_82 ( L_83 ) ;
V_130 = - V_144 ;
goto V_500;
}
if ( F_289 ( & V_1 -> V_148 , V_501 , V_499 , 6 ) < 0 ) {
V_130 = - V_143 ;
goto V_500;
}
V_500:
F_326 ( V_1 ) ;
return V_130 ;
}
static bool
F_333 ( struct V_1 * V_1 , T_1 * V_502 )
{
return F_288 ( & V_1 -> V_148 ,
V_503 ,
V_502 , 1 ) == 1 ;
}
static bool
F_334 ( struct V_1 * V_1 , T_1 * V_502 )
{
int V_130 ;
V_130 = F_288 ( & V_1 -> V_148 ,
V_504 ,
V_502 , 14 ) ;
if ( V_130 != 14 )
return false ;
return true ;
}
static T_3 F_335 ( struct V_1 * V_1 )
{
T_3 V_505 = V_506 ;
return V_505 ;
}
static T_3 F_336 ( struct V_1 * V_1 )
{
T_3 V_505 = V_507 ;
return V_505 ;
}
static T_3 F_337 ( struct V_1 * V_1 )
{
T_3 V_505 = V_507 ;
struct V_30 * V_30 = V_1 -> V_245 ;
struct V_8 * V_9 = & V_30 -> V_4 ;
if ( V_30 -> V_508 == NULL ||
V_9 -> V_509 ||
V_1 -> V_148 . V_510 > 6 ) {
if ( V_1 -> V_148 . V_511 > 0 ||
V_1 -> V_148 . V_510 > 0 )
F_34 ( L_84 ,
V_1 -> V_148 . V_511 ,
V_1 -> V_148 . V_510 ) ;
V_1 -> V_512 = V_513 ;
} else {
struct V_514 * V_515 = V_30 -> V_508 ;
V_515 += V_30 -> V_508 -> V_516 ;
if ( ! F_338 ( & V_1 -> V_148 ,
V_517 ,
& V_515 -> V_518 ,
1 ) )
F_34 ( L_85 ) ;
V_505 = V_506 | V_519 ;
V_1 -> V_512 = V_520 ;
}
V_1 -> V_521 = 1 ;
return V_505 ;
}
static T_3 F_339 ( struct V_1 * V_1 )
{
T_3 V_505 = V_507 ;
return V_505 ;
}
static void F_340 ( struct V_1 * V_1 )
{
T_3 V_522 = V_507 ;
T_3 V_523 = 0 ;
int V_107 = 0 ;
V_107 = F_289 ( & V_1 -> V_148 , V_524 , & V_523 , 1 ) ;
if ( V_107 <= 0 ) {
F_34 ( L_86 ) ;
goto V_525;
}
switch ( V_523 ) {
case V_526 :
F_34 ( L_87 ) ;
V_1 -> V_527 = V_526 ;
V_522 = F_335 ( V_1 ) ;
break;
case V_528 :
F_34 ( L_88 ) ;
V_1 -> V_527 = V_528 ;
V_522 = F_336 ( V_1 ) ;
break;
case V_529 :
F_34 ( L_89 ) ;
V_1 -> V_527 = V_529 ;
V_522 = F_337 ( V_1 ) ;
break;
case V_530 :
F_34 ( L_90 ) ;
V_1 -> V_527 = V_530 ;
V_522 = F_339 ( V_1 ) ;
break;
default:
F_34 ( L_91 , V_523 ) ;
break;
}
V_525:
V_107 = F_338 ( & V_1 -> V_148 ,
V_531 ,
& V_522 , 1 ) ;
if ( V_107 <= 0 )
F_34 ( L_92 ) ;
}
static int
F_341 ( struct V_1 * V_1 )
{
bool V_532 ;
if ( V_1 -> V_490 ) {
T_1 V_533 [ 16 ] = { 0 } ;
int V_130 = 0 ;
int V_534 ;
bool V_535 ;
V_532 = F_334 ( V_1 , V_533 ) ;
V_536:
if ( V_532 == true ) {
if ( V_1 -> V_537 &&
! F_342 ( & V_533 [ 10 ] , V_1 -> V_10 ) ) {
F_34 ( L_93 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
}
F_34 ( L_94 , V_533 ) ;
V_130 = F_343 ( & V_1 -> V_491 , V_533 , & V_535 ) ;
if ( V_535 ) {
for ( V_534 = 0 ; V_534 < 3 ; V_534 ++ ) {
int V_538 ;
V_538 = F_338 ( & V_1 -> V_148 ,
V_504 + 1 ,
& V_533 [ 1 ] , 3 ) ;
if ( V_538 == 3 ) {
break;
}
}
V_532 = F_334 ( V_1 , V_533 ) ;
if ( V_532 == true ) {
F_34 ( L_95 , V_533 ) ;
goto V_536;
}
} else
V_130 = 0 ;
return V_130 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_34 ( L_96 ) ;
V_1 -> V_490 = false ;
F_325 ( & V_1 -> V_491 , V_1 -> V_490 ) ;
F_344 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_168 ;
}
static void
F_345 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_51 * V_51 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_502 ;
T_1 V_394 [ V_395 ] ;
F_46 ( ! F_346 ( & V_7 -> V_539 . V_540 ) ) ;
V_1 -> V_521 = 0 ;
V_1 -> V_527 = 0 ;
V_1 -> V_512 = 0 ;
if ( ! V_51 -> V_4 . V_244 )
return;
if ( ! F_157 ( V_51 -> V_4 . V_244 ) -> V_541 )
return;
if ( ! F_290 ( V_1 , V_394 ) ) {
return;
}
if ( ! F_319 ( V_1 ) ) {
return;
}
if ( V_1 -> V_12 [ V_321 ] >= 0x11 &&
F_333 ( V_1 , & V_502 ) ) {
F_212 ( & V_1 -> V_148 ,
V_503 ,
V_502 ) ;
if ( V_502 & V_542 )
F_254 ( L_97 ) ;
if ( V_502 & ( V_543 | V_544 ) )
F_254 ( L_98 ) ;
}
if ( ( V_1 -> V_527 == V_526 ) ||
( ! F_342 ( V_394 , V_1 -> V_10 ) ) ) {
F_34 ( L_99 ,
V_51 -> V_4 . V_183 ) ;
F_252 ( V_1 ) ;
F_253 ( V_1 ) ;
}
}
static enum V_545
F_347 ( struct V_1 * V_1 )
{
T_3 * V_12 = V_1 -> V_12 ;
T_3 type ;
if ( ! F_319 ( V_1 ) )
return V_546 ;
if ( ! ( V_12 [ V_477 ] & V_478 ) )
return V_547 ;
if ( V_1 -> V_12 [ V_321 ] >= 0x11 &&
V_1 -> V_480 [ 0 ] & V_548 ) {
T_3 V_549 ;
if ( F_288 ( & V_1 -> V_148 , V_550 ,
& V_549 , 1 ) < 0 )
return V_551 ;
return F_348 ( V_549 ) ? V_547
: V_546 ;
}
if ( F_349 ( & V_1 -> V_148 . V_189 ) )
return V_547 ;
if ( V_1 -> V_12 [ V_321 ] >= 0x11 ) {
type = V_1 -> V_480 [ 0 ] & V_552 ;
if ( type == V_553 ||
type == V_554 )
return V_551 ;
} else {
type = V_1 -> V_12 [ V_477 ] &
V_555 ;
if ( type == V_556 ||
type == V_557 )
return V_551 ;
}
F_34 ( L_100 ) ;
return V_546 ;
}
static enum V_545
F_350 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_545 V_107 ;
V_107 = F_351 ( V_7 ) ;
if ( V_107 == V_551 )
V_107 = V_547 ;
return V_107 ;
}
static bool F_352 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_558 ;
switch ( V_19 -> V_19 ) {
case V_20 :
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
F_108 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_562 ) & V_558 ;
}
static bool F_353 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_558 ;
switch ( V_19 -> V_19 ) {
case V_20 :
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
F_108 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_562 ) & V_558 ;
}
static bool F_354 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_558 ;
switch ( V_19 -> V_19 ) {
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
F_108 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_570 ) & V_558 ;
}
static bool F_355 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
T_5 V_558 ;
switch ( V_19 -> V_19 ) {
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
F_108 ( V_19 -> V_19 ) ;
return false ;
}
return F_31 ( V_570 ) & V_558 ;
}
static bool F_356 ( struct V_53 * V_54 ,
struct V_2 * V_3 )
{
struct V_51 * V_51 = & V_3 -> V_4 ;
enum V_19 V_19 ;
T_5 V_558 ;
F_357 ( V_51 -> V_574 , & V_19 ) ;
switch ( V_19 ) {
case V_20 :
V_558 = V_575 ;
break;
case V_169 :
V_558 = V_576 ;
break;
case V_170 :
V_558 = V_577 ;
break;
default:
F_108 ( V_19 ) ;
return false ;
}
return F_31 ( V_578 ) & V_558 ;
}
bool F_358 ( struct V_53 * V_54 ,
struct V_2 * V_19 )
{
if ( F_318 ( V_54 ) )
return F_352 ( V_54 , V_19 ) ;
if ( F_66 ( V_54 ) )
return F_353 ( V_54 , V_19 ) ;
else if ( F_64 ( V_54 ) )
return F_356 ( V_54 , V_19 ) ;
else if ( F_359 ( V_54 ) )
return F_355 ( V_54 , V_19 ) ;
else
return F_354 ( V_54 , V_19 ) ;
}
static struct V_514 *
F_360 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_245 ;
if ( V_30 -> V_514 ) {
if ( F_361 ( V_30 -> V_514 ) )
return NULL ;
return F_362 ( V_30 -> V_514 ) ;
} else
return F_363 ( & V_30 -> V_4 ,
& V_1 -> V_148 . V_189 ) ;
}
static void
F_364 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_245 ;
struct V_514 * V_514 ;
V_514 = F_360 ( V_1 ) ;
V_30 -> V_508 = V_514 ;
if ( V_1 -> V_579 != V_580 )
V_1 -> V_255 = V_1 -> V_579 == V_581 ;
else
V_1 -> V_255 = F_365 ( V_514 ) ;
}
static void
F_366 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = V_1 -> V_245 ;
F_126 ( V_30 -> V_508 ) ;
V_30 -> V_508 = NULL ;
V_1 -> V_255 = false ;
}
static enum V_545
F_367 ( struct V_8 * V_9 , bool V_582 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_545 V_107 ;
enum V_56 V_57 ;
bool V_130 ;
T_1 V_502 ;
F_34 ( L_101 ,
V_9 -> V_4 . V_583 , V_9 -> V_183 ) ;
F_366 ( V_1 ) ;
if ( V_1 -> V_490 ) {
if ( V_51 -> type != V_5 )
V_51 -> type = V_584 ;
return V_546 ;
}
V_57 = F_22 ( V_51 ) ;
F_23 ( F_122 ( V_7 ) , V_57 ) ;
if ( F_1 ( V_1 ) )
V_107 = F_350 ( V_1 ) ;
else if ( F_358 ( F_122 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_107 = F_347 ( V_1 ) ;
else
V_107 = V_546 ;
if ( V_107 != V_547 ) {
V_1 -> V_521 = 0 ;
V_1 -> V_527 = 0 ;
V_1 -> V_512 = 0 ;
goto V_137;
}
F_323 ( V_1 ) ;
V_130 = F_324 ( V_1 ) ;
if ( V_130 ) {
if ( V_51 -> type != V_5 )
V_51 -> type = V_584 ;
V_107 = V_546 ;
goto V_137;
}
V_1 -> V_148 . V_511 = 0 ;
V_1 -> V_148 . V_510 = 0 ;
F_364 ( V_1 ) ;
if ( V_51 -> type != V_5 )
V_51 -> type = V_584 ;
V_107 = V_547 ;
if ( V_1 -> V_12 [ V_321 ] >= 0x11 &&
F_333 ( V_1 , & V_502 ) ) {
F_212 ( & V_1 -> V_148 ,
V_503 ,
V_502 ) ;
if ( V_502 & V_542 )
F_340 ( V_1 ) ;
if ( V_502 & ( V_543 | V_544 ) )
F_254 ( L_98 ) ;
}
V_137:
F_27 ( F_122 ( V_7 ) , V_57 ) ;
return V_107 ;
}
static void
F_368 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_51 * V_51 = & F_2 ( V_1 ) -> V_4 ;
struct V_53 * V_54 = F_122 ( V_51 -> V_4 . V_7 ) ;
enum V_56 V_57 ;
F_34 ( L_101 ,
V_9 -> V_4 . V_583 , V_9 -> V_183 ) ;
F_366 ( V_1 ) ;
if ( V_9 -> V_107 != V_547 )
return;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
F_364 ( V_1 ) ;
F_27 ( V_54 , V_57 ) ;
if ( V_51 -> type != V_5 )
V_51 -> type = V_584 ;
}
static int F_369 ( struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
struct V_514 * V_514 ;
V_514 = V_30 -> V_508 ;
if ( V_514 ) {
int V_130 = F_370 ( V_9 , V_514 ) ;
if ( V_130 )
return V_130 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_30 -> V_32 . V_31 ) {
struct V_28 * V_29 ;
V_29 = F_371 ( V_9 -> V_7 ,
V_30 -> V_32 . V_31 ) ;
if ( V_29 ) {
F_372 ( V_9 , V_29 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_373 ( struct V_8 * V_9 )
{
bool V_255 = false ;
struct V_514 * V_514 ;
V_514 = F_17 ( V_9 ) -> V_508 ;
if ( V_514 )
V_255 = F_365 ( V_514 ) ;
return V_255 ;
}
static int
F_374 ( struct V_8 * V_9 ,
struct V_585 * V_586 ,
T_10 V_337 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_30 * V_30 = F_17 ( V_9 ) ;
struct V_51 * V_51 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_51 -> V_4 ) ;
int V_130 ;
V_130 = F_375 ( & V_9 -> V_4 , V_586 , V_337 ) ;
if ( V_130 )
return V_130 ;
if ( V_586 == V_54 -> V_587 ) {
int V_47 = V_337 ;
bool V_255 ;
if ( V_47 == V_1 -> V_579 )
return 0 ;
V_1 -> V_579 = V_47 ;
if ( V_47 == V_580 )
V_255 = F_373 ( V_9 ) ;
else
V_255 = ( V_47 == V_581 ) ;
if ( V_255 == V_1 -> V_255 )
return 0 ;
V_1 -> V_255 = V_255 ;
goto V_108;
}
if ( V_586 == V_54 -> V_588 ) {
bool V_589 = V_1 -> V_263 ;
bool V_590 = V_1 -> V_264 ;
switch ( V_337 ) {
case V_591 :
V_1 -> V_263 = true ;
break;
case V_592 :
V_1 -> V_263 = false ;
V_1 -> V_264 = false ;
break;
case V_593 :
V_1 -> V_263 = false ;
V_1 -> V_264 = true ;
break;
default:
return - V_168 ;
}
if ( V_589 == V_1 -> V_263 &&
V_590 == V_1 -> V_264 )
return 0 ;
goto V_108;
}
if ( F_1 ( V_1 ) &&
V_586 == V_9 -> V_7 -> V_539 . V_594 ) {
if ( V_337 == V_595 ) {
F_34 ( L_102 ) ;
return - V_168 ;
}
if ( V_30 -> V_32 . V_256 == V_337 ) {
return 0 ;
}
V_30 -> V_32 . V_256 = V_337 ;
goto V_108;
}
return - V_168 ;
V_108:
if ( V_51 -> V_4 . V_244 )
F_376 ( V_51 -> V_4 . V_244 ) ;
return 0 ;
}
static void
F_377 ( struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
F_126 ( V_30 -> V_508 ) ;
if ( ! F_378 ( V_30 -> V_514 ) )
F_126 ( V_30 -> V_514 ) ;
if ( V_9 -> V_596 == V_597 )
F_379 ( & V_30 -> V_32 ) ;
F_380 ( V_9 ) ;
F_126 ( V_9 ) ;
}
void F_381 ( struct V_598 * V_52 )
{
struct V_2 * V_3 = F_235 ( V_52 ) ;
struct V_1 * V_1 = & V_3 -> V_599 ;
F_124 ( V_1 ) ;
F_382 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_383 ( & V_1 -> V_301 ) ;
F_21 ( V_1 ) ;
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
if ( V_1 -> V_95 . V_600 ) {
F_384 ( & V_1 -> V_95 ) ;
V_1 -> V_95 . V_600 = NULL ;
}
}
F_385 ( V_52 ) ;
F_126 ( V_3 ) ;
}
static void F_386 ( struct V_51 * V_51 )
{
struct V_1 * V_1 = F_5 ( & V_51 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_383 ( & V_1 -> V_301 ) ;
F_21 ( V_1 ) ;
F_183 ( V_1 ) ;
F_25 ( V_1 ) ;
}
static void F_387 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
F_45 ( & V_54 -> V_58 ) ;
if ( ! F_75 ( V_1 ) )
return;
F_34 ( L_103 ) ;
V_57 = F_22 ( & V_3 -> V_4 ) ;
F_23 ( V_54 , V_57 ) ;
F_186 ( V_1 ) ;
}
static void F_388 ( struct V_598 * V_52 )
{
struct V_1 * V_1 ;
if ( F_389 ( V_52 ) -> type != V_5 )
return;
V_1 = F_5 ( V_52 ) ;
F_21 ( V_1 ) ;
if ( F_62 ( V_52 -> V_7 ) || F_36 ( V_52 -> V_7 ) )
F_60 ( V_1 ) ;
F_387 ( V_1 ) ;
F_25 ( V_1 ) ;
}
enum V_601
F_390 ( struct V_2 * V_3 , bool V_602 )
{
struct V_1 * V_1 = & V_3 -> V_599 ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_56 V_57 ;
enum V_601 V_130 = V_603 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_604 )
V_3 -> V_4 . type = V_584 ;
if ( V_602 && V_3 -> V_4 . type == V_5 ) {
F_34 ( L_104 ,
F_33 ( V_3 -> V_19 ) ) ;
return V_605 ;
}
F_34 ( L_105 ,
F_33 ( V_3 -> V_19 ) ,
V_602 ? L_106 : L_107 ) ;
V_57 = F_22 ( V_51 ) ;
F_23 ( V_54 , V_57 ) ;
if ( V_602 ) {
V_1 -> V_606 = false ;
if ( ! F_358 ( V_54 , V_3 ) )
goto V_607;
if ( ! F_319 ( V_1 ) ) {
goto V_607;
}
F_323 ( V_1 ) ;
if ( ! F_324 ( V_1 ) ) {
F_391 ( & V_7 -> V_539 . V_540 , NULL ) ;
F_345 ( V_1 ) ;
F_392 ( & V_7 -> V_539 . V_540 ) ;
goto V_607;
}
} else {
if ( V_1 -> V_490 ) {
if ( F_341 ( V_1 ) == - V_168 )
goto V_607;
}
if ( ! V_1 -> V_490 ) {
F_391 ( & V_7 -> V_539 . V_540 , NULL ) ;
F_345 ( V_1 ) ;
F_392 ( & V_7 -> V_539 . V_540 ) ;
}
}
V_130 = V_605 ;
goto V_608;
V_607:
if ( V_1 -> V_490 ) {
F_34 ( L_108 , V_1 -> V_490 , V_1 -> V_491 . V_609 ) ;
V_1 -> V_490 = false ;
F_325 ( & V_1 -> V_491 , V_1 -> V_490 ) ;
}
V_608:
F_27 ( V_54 , V_57 ) ;
return V_130 ;
}
bool F_393 ( struct V_6 * V_7 , enum V_19 V_19 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_610 * V_611 ;
int V_47 ;
static const short V_612 [] = {
[ V_169 ] = V_613 ,
[ V_170 ] = V_614 ,
[ V_171 ] = V_615 ,
[ V_176 ] = V_616 ,
} ;
if ( F_119 ( V_7 ) -> V_182 < 5 )
return false ;
if ( V_19 == V_20 )
return true ;
if ( ! V_54 -> V_174 . V_617 )
return false ;
for ( V_47 = 0 ; V_47 < V_54 -> V_174 . V_617 ; V_47 ++ ) {
V_611 = V_54 -> V_174 . V_618 + V_47 ;
if ( V_611 -> V_619 . V_620 == V_612 [ V_19 ] &&
( V_611 -> V_619 . V_621 & V_622 ) ==
( V_623 & V_622 ) )
return true ;
}
return false ;
}
void
F_394 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_30 * V_30 = F_17 ( V_9 ) ;
F_395 ( V_9 ) ;
F_396 ( V_9 ) ;
V_1 -> V_263 = true ;
if ( F_1 ( V_1 ) ) {
F_397 ( V_9 -> V_7 ) ;
F_398 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_539 . V_594 ,
V_624 ) ;
V_30 -> V_32 . V_256 = V_624 ;
}
}
static void F_399 ( struct V_1 * V_1 )
{
V_1 -> V_289 = V_304 ;
V_1 -> V_292 = V_304 ;
V_1 -> V_294 = V_304 ;
}
static void
F_50 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_625 V_626 , V_174 , V_627 ,
* V_628 = & V_1 -> V_629 ;
T_5 V_630 , V_631 , V_99 = 0 , V_632 = 0 ;
T_6 V_97 , V_366 , V_633 , V_98 ;
F_45 ( & V_54 -> V_58 ) ;
if ( V_628 -> V_634 != 0 )
return;
if ( F_64 ( V_7 ) ) {
V_97 = F_65 ( 0 ) ;
V_366 = F_400 ( 0 ) ;
V_633 = F_401 ( 0 ) ;
} else if ( F_66 ( V_7 ) ) {
V_97 = V_89 ;
V_366 = V_635 ;
V_633 = V_636 ;
V_98 = V_637 ;
} else {
enum V_59 V_59 = F_44 ( V_1 ) ;
V_97 = F_55 ( V_59 ) ;
V_366 = F_58 ( V_59 ) ;
V_633 = F_402 ( V_59 ) ;
V_98 = F_72 ( V_59 ) ;
}
V_632 = F_179 ( V_1 ) ;
V_630 = F_31 ( V_366 ) ;
V_631 = F_31 ( V_633 ) ;
if ( ! F_64 ( V_7 ) ) {
F_41 ( V_97 , V_632 ) ;
V_99 = F_31 ( V_98 ) ;
}
V_626 . V_638 = ( V_630 & V_639 ) >>
V_640 ;
V_626 . V_641 = ( V_630 & V_642 ) >>
V_643 ;
V_626 . V_644 = ( V_631 & V_645 ) >>
V_646 ;
V_626 . V_647 = ( V_631 & V_648 ) >>
V_649 ;
if ( F_64 ( V_7 ) ) {
T_11 V_83 = ( V_632 & V_650 ) >>
V_651 ;
if ( V_83 > 0 )
V_626 . V_634 = ( V_83 - 1 ) * 1000 ;
else
V_626 . V_634 = 0 ;
} else {
V_626 . V_634 = ( ( V_99 & V_652 ) >>
V_653 ) * 1000 ;
}
F_34 ( L_109 ,
V_626 . V_638 , V_626 . V_641 , V_626 . V_644 , V_626 . V_647 , V_626 . V_634 ) ;
V_174 = V_54 -> V_174 . V_654 ;
V_627 . V_638 = 210 * 10 ;
V_627 . V_641 = 50 * 10 ;
V_627 . V_644 = 50 * 10 ;
V_627 . V_647 = 500 * 10 ;
V_627 . V_634 = ( 510 + 100 ) * 10 ;
F_34 ( L_110 ,
V_174 . V_638 , V_174 . V_641 , V_174 . V_644 , V_174 . V_647 , V_174 . V_634 ) ;
#define F_403 ( T_12 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_403 ( V_638 ) ;
F_403 ( V_641 ) ;
F_403 ( V_644 ) ;
F_403 ( V_647 ) ;
F_403 ( V_634 ) ;
#undef F_403
#define F_404 ( T_12 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_302 = F_404 ( V_638 ) ;
V_1 -> V_293 = F_404 ( V_641 ) ;
V_1 -> V_295 = F_404 ( V_644 ) ;
V_1 -> V_461 = F_404 ( V_647 ) ;
V_1 -> V_103 = F_404 ( V_634 ) ;
#undef F_404
F_34 ( L_111 ,
V_1 -> V_302 , V_1 -> V_461 ,
V_1 -> V_103 ) ;
F_34 ( L_112 ,
V_1 -> V_293 , V_1 -> V_295 ) ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_630 , V_631 , V_99 , V_87 = 0 ;
int div = F_66 ( V_7 ) ? F_87 ( V_7 ) : F_85 ( V_7 ) ;
T_6 V_366 , V_633 , V_98 , V_97 ;
enum V_19 V_19 = F_2 ( V_1 ) -> V_19 ;
const struct V_625 * V_655 = & V_1 -> V_629 ;
F_45 ( & V_54 -> V_58 ) ;
if ( F_64 ( V_7 ) ) {
V_97 = F_65 ( 0 ) ;
V_366 = F_400 ( 0 ) ;
V_633 = F_401 ( 0 ) ;
} else if ( F_66 ( V_7 ) ) {
V_366 = V_635 ;
V_633 = V_636 ;
V_98 = V_637 ;
} else {
enum V_59 V_59 = F_44 ( V_1 ) ;
V_366 = F_58 ( V_59 ) ;
V_633 = F_402 ( V_59 ) ;
V_98 = F_72 ( V_59 ) ;
}
V_630 = ( V_655 -> V_638 << V_640 ) |
( 1 << V_643 ) ;
V_631 = ( 1 << V_646 ) |
( V_655 -> V_647 << V_649 ) ;
if ( F_64 ( V_7 ) ) {
V_99 = F_31 ( V_97 ) ;
V_99 &= ~ V_650 ;
V_99 |= ( F_405 ( ( V_655 -> V_634 + 1 ) , 1000 )
<< V_651 ) ;
} else {
V_99 = ( ( 100 * div ) / 2 - 1 ) << V_656 ;
V_99 |= ( F_405 ( V_655 -> V_634 , 1000 )
<< V_653 ) ;
}
if ( F_62 ( V_7 ) || F_36 ( V_7 ) ) {
V_87 = F_59 ( V_19 ) ;
} else if ( F_318 ( V_7 ) || F_169 ( V_7 ) ) {
if ( V_19 == V_20 )
V_87 = V_657 ;
else
V_87 = V_658 ;
}
V_630 |= V_87 ;
F_41 ( V_366 , V_630 ) ;
F_41 ( V_633 , V_631 ) ;
if ( F_64 ( V_7 ) )
F_41 ( V_97 , V_99 ) ;
else
F_41 ( V_98 , V_99 ) ;
F_34 ( L_113 ,
F_31 ( V_366 ) ,
F_31 ( V_633 ) ,
F_64 ( V_7 ) ?
( F_31 ( V_97 ) & V_650 ) :
F_31 ( V_98 ) ) ;
}
static void F_406 ( struct V_6 * V_7 , int V_659 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_51 * V_52 ;
struct V_2 * V_212 = NULL ;
struct V_1 * V_1 = V_54 -> V_267 . V_599 ;
struct V_191 * V_271 = NULL ;
struct V_243 * V_243 = NULL ;
enum V_660 V_110 = V_661 ;
if ( V_659 <= 0 ) {
F_34 ( L_114 ) ;
return;
}
if ( V_1 == NULL ) {
F_34 ( L_115 ) ;
return;
}
V_212 = F_2 ( V_1 ) ;
V_52 = & V_212 -> V_4 ;
V_243 = F_157 ( V_52 -> V_4 . V_244 ) ;
if ( ! V_243 ) {
F_34 ( L_116 ) ;
return;
}
V_271 = V_243 -> V_271 ;
if ( V_54 -> V_267 . type < V_268 ) {
F_34 ( L_117 ) ;
return;
}
if ( V_1 -> V_245 -> V_32 . V_266 -> V_662 ==
V_659 )
V_110 = V_663 ;
if ( V_110 == V_54 -> V_267 . V_664 ) {
F_34 (
L_118 ) ;
return;
}
if ( ! V_243 -> V_541 ) {
F_34 ( L_119 ) ;
return;
}
if ( F_119 ( V_7 ) -> V_182 >= 8 && ! F_36 ( V_7 ) ) {
switch ( V_110 ) {
case V_661 :
F_407 ( V_243 , V_665 ) ;
break;
case V_663 :
F_407 ( V_243 , V_666 ) ;
break;
case V_667 :
default:
F_82 ( L_120 ) ;
}
} else if ( F_119 ( V_7 ) -> V_182 > 6 ) {
T_6 V_549 = F_408 ( V_243 -> V_271 -> V_668 ) ;
T_5 V_337 ;
V_337 = F_31 ( V_549 ) ;
if ( V_110 > V_661 ) {
if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
V_337 |= V_669 ;
else
V_337 |= V_670 ;
} else {
if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
V_337 &= ~ V_669 ;
else
V_337 &= ~ V_670 ;
}
F_41 ( V_549 , V_337 ) ;
}
V_54 -> V_267 . V_664 = V_110 ;
F_34 ( L_121 , V_659 ) ;
}
void F_409 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_671 * V_244 = V_212 -> V_4 . V_4 . V_244 ;
struct V_243 * V_243 = F_157 ( V_244 ) ;
if ( ! V_243 -> V_271 -> V_254 ) {
F_34 ( L_122 ) ;
return;
}
F_24 ( & V_54 -> V_267 . V_672 ) ;
if ( F_46 ( V_54 -> V_267 . V_599 ) ) {
F_82 ( L_123 ) ;
goto V_673;
}
V_54 -> V_267 . V_674 = 0 ;
V_54 -> V_267 . V_599 = V_1 ;
V_673:
F_26 ( & V_54 -> V_267 . V_672 ) ;
}
void F_410 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_212 = F_2 ( V_1 ) ;
struct V_671 * V_244 = V_212 -> V_4 . V_4 . V_244 ;
struct V_243 * V_243 = F_157 ( V_244 ) ;
if ( ! V_243 -> V_271 -> V_254 )
return;
F_24 ( & V_54 -> V_267 . V_672 ) ;
if ( ! V_54 -> V_267 . V_599 ) {
F_26 ( & V_54 -> V_267 . V_672 ) ;
return;
}
if ( V_54 -> V_267 . V_664 == V_663 )
F_406 ( V_54 -> V_7 ,
V_1 -> V_245 -> V_32 .
V_31 -> V_662 ) ;
V_54 -> V_267 . V_599 = NULL ;
F_26 ( & V_54 -> V_267 . V_672 ) ;
F_383 ( & V_54 -> V_267 . V_675 ) ;
}
static void F_411 ( struct V_305 * V_675 )
{
struct V_53 * V_54 =
F_70 ( V_675 , F_71 ( * V_54 ) , V_267 . V_675 . V_675 ) ;
struct V_1 * V_1 ;
F_24 ( & V_54 -> V_267 . V_672 ) ;
V_1 = V_54 -> V_267 . V_599 ;
if ( ! V_1 )
goto V_673;
if ( V_54 -> V_267 . V_674 )
goto V_673;
if ( V_54 -> V_267 . V_664 != V_663 )
F_406 ( V_54 -> V_7 ,
V_1 -> V_245 -> V_32 .
V_266 -> V_662 ) ;
V_673:
F_26 ( & V_54 -> V_267 . V_672 ) ;
}
void F_412 ( struct V_6 * V_7 ,
unsigned V_676 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_671 * V_244 ;
enum V_59 V_59 ;
if ( V_54 -> V_267 . type == V_677 )
return;
F_180 ( & V_54 -> V_267 . V_675 ) ;
F_24 ( & V_54 -> V_267 . V_672 ) ;
if ( ! V_54 -> V_267 . V_599 ) {
F_26 ( & V_54 -> V_267 . V_672 ) ;
return;
}
V_244 = F_2 ( V_54 -> V_267 . V_599 ) -> V_4 . V_4 . V_244 ;
V_59 = F_157 ( V_244 ) -> V_59 ;
V_676 &= F_413 ( V_59 ) ;
V_54 -> V_267 . V_674 |= V_676 ;
if ( V_676 && V_54 -> V_267 . V_664 == V_663 )
F_406 ( V_54 -> V_7 ,
V_54 -> V_267 . V_599 -> V_245 -> V_32 .
V_31 -> V_662 ) ;
F_26 ( & V_54 -> V_267 . V_672 ) ;
}
void F_414 ( struct V_6 * V_7 ,
unsigned V_676 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_671 * V_244 ;
enum V_59 V_59 ;
if ( V_54 -> V_267 . type == V_677 )
return;
F_180 ( & V_54 -> V_267 . V_675 ) ;
F_24 ( & V_54 -> V_267 . V_672 ) ;
if ( ! V_54 -> V_267 . V_599 ) {
F_26 ( & V_54 -> V_267 . V_672 ) ;
return;
}
V_244 = F_2 ( V_54 -> V_267 . V_599 ) -> V_4 . V_4 . V_244 ;
V_59 = F_157 ( V_244 ) -> V_59 ;
V_676 &= F_413 ( V_59 ) ;
V_54 -> V_267 . V_674 &= ~ V_676 ;
if ( V_676 && V_54 -> V_267 . V_664 == V_663 )
F_406 ( V_54 -> V_7 ,
V_54 -> V_267 . V_599 -> V_245 -> V_32 .
V_31 -> V_662 ) ;
if ( ! V_54 -> V_267 . V_674 )
F_188 ( & V_54 -> V_267 . V_675 ,
F_187 ( 1000 ) ) ;
F_26 ( & V_54 -> V_267 . V_672 ) ;
}
static struct V_28 *
F_415 ( struct V_30 * V_30 ,
struct V_28 * V_31 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_266 = NULL ;
F_416 ( & V_54 -> V_267 . V_675 , F_411 ) ;
F_417 ( & V_54 -> V_267 . V_672 ) ;
if ( F_119 ( V_7 ) -> V_182 <= 6 ) {
F_34 ( L_124 ) ;
return NULL ;
}
if ( V_54 -> V_174 . V_678 != V_268 ) {
F_34 ( L_125 ) ;
return NULL ;
}
V_266 = F_418
( V_7 , V_31 , V_9 ) ;
if ( ! V_266 ) {
F_34 ( L_126 ) ;
return NULL ;
}
V_54 -> V_267 . type = V_54 -> V_174 . V_678 ;
V_54 -> V_267 . V_664 = V_661 ;
F_34 ( L_127 ) ;
return V_266 ;
}
static bool F_419 ( struct V_1 * V_1 ,
struct V_30 * V_30 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_51 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_28 * V_31 = NULL ;
struct V_28 * V_266 = NULL ;
bool V_679 ;
struct V_28 * V_680 ;
struct V_514 * V_514 ;
enum V_59 V_59 = V_82 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_21 ( V_1 ) ;
F_387 ( V_1 ) ;
F_25 ( V_1 ) ;
V_679 = F_319 ( V_1 ) ;
if ( V_679 ) {
if ( V_1 -> V_12 [ V_321 ] >= 0x11 )
V_54 -> V_681 =
V_1 -> V_12 [ V_682 ] &
V_683 ;
} else {
F_420 ( L_128 ) ;
return false ;
}
F_21 ( V_1 ) ;
F_51 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
F_24 ( & V_7 -> V_539 . V_672 ) ;
V_514 = F_363 ( V_9 , & V_1 -> V_148 . V_189 ) ;
if ( V_514 ) {
if ( F_421 ( V_9 , V_514 ) ) {
F_422 ( V_9 ,
V_514 ) ;
F_423 ( V_9 , V_514 ) ;
} else {
F_126 ( V_514 ) ;
V_514 = F_424 ( - V_168 ) ;
}
} else {
V_514 = F_424 ( - V_684 ) ;
}
V_30 -> V_514 = V_514 ;
F_425 (scan, &connector->probed_modes, head) {
if ( ( V_680 -> type & V_685 ) ) {
V_31 = F_371 ( V_7 , V_680 ) ;
V_266 = F_415 (
V_30 , V_31 ) ;
break;
}
}
if ( ! V_31 && V_54 -> V_174 . V_686 ) {
V_31 = F_371 ( V_7 ,
V_54 -> V_174 . V_686 ) ;
if ( V_31 )
V_31 -> type |= V_685 ;
}
F_26 ( & V_7 -> V_539 . V_672 ) ;
if ( F_62 ( V_7 ) || F_36 ( V_7 ) ) {
V_1 -> V_95 . V_600 = F_69 ;
F_426 ( & V_1 -> V_95 ) ;
if ( F_36 ( V_7 ) )
V_59 = F_220 ( V_1 -> V_67 ) ;
else
V_59 = F_221 ( V_1 -> V_67 ) ;
if ( V_59 != V_81 && V_59 != V_74 )
V_59 = V_1 -> V_60 ;
if ( V_59 != V_81 && V_59 != V_74 )
V_59 = V_81 ;
F_34 ( L_129 ,
F_32 ( V_59 ) ) ;
}
F_427 ( & V_30 -> V_32 , V_31 , V_266 ) ;
V_30 -> V_32 . V_687 . V_688 = F_200 ;
F_428 ( V_9 , V_59 ) ;
return true ;
}
bool
F_429 ( struct V_2 * V_3 ,
struct V_30 * V_30 )
{
struct V_8 * V_9 = & V_30 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_599 ;
struct V_51 * V_51 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_51 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_19 V_19 = V_3 -> V_19 ;
int type , V_130 ;
V_1 -> V_60 = V_82 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 )
V_1 -> V_139 = F_91 ;
else if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
V_1 -> V_139 = F_90 ;
else if ( F_141 ( V_7 ) || F_94 ( V_7 ) )
V_1 -> V_139 = F_88 ;
else if ( F_66 ( V_7 ) )
V_1 -> V_139 = F_86 ;
else
V_1 -> V_139 = F_83 ;
if ( F_119 ( V_7 ) -> V_182 >= 9 )
V_1 -> V_141 = F_95 ;
else
V_1 -> V_141 = F_92 ;
if ( F_11 ( V_7 ) )
V_1 -> V_689 = V_690 ;
V_1 -> V_67 = F_31 ( V_1 -> V_68 ) ;
V_1 -> V_245 = V_30 ;
if ( F_393 ( V_7 , V_19 ) )
type = V_597 ;
else
type = V_691 ;
if ( type == V_597 )
V_51 -> type = V_5 ;
if ( F_46 ( ( F_62 ( V_7 ) || F_36 ( V_7 ) ) &&
F_1 ( V_1 ) && V_19 != V_169 && V_19 != V_170 ) )
return false ;
F_34 ( L_130 ,
type == V_597 ? L_131 : L_132 ,
F_33 ( V_19 ) ) ;
F_430 ( V_7 , V_9 , & V_692 , type ) ;
F_431 ( V_9 , & V_693 ) ;
V_9 -> V_694 = true ;
V_9 -> V_695 = 0 ;
F_416 ( & V_1 -> V_301 ,
F_184 ) ;
F_432 ( V_30 , V_51 ) ;
F_433 ( V_9 ) ;
if ( F_11 ( V_7 ) )
V_30 -> V_696 = V_697 ;
else
V_30 -> V_696 = V_698 ;
V_30 -> V_699 = F_131 ;
switch ( V_19 ) {
case V_20 :
V_51 -> V_574 = V_700 ;
break;
case V_169 :
V_51 -> V_574 = V_701 ;
if ( F_434 ( V_7 , 0 , V_702 ) )
V_51 -> V_574 = V_700 ;
break;
case V_170 :
V_51 -> V_574 = V_703 ;
break;
case V_171 :
V_51 -> V_574 = V_704 ;
break;
case V_176 :
V_51 -> V_574 = V_705 ;
break;
default:
F_435 () ;
}
if ( F_1 ( V_1 ) ) {
F_21 ( V_1 ) ;
F_399 ( V_1 ) ;
if ( F_62 ( V_7 ) || F_36 ( V_7 ) )
F_60 ( V_1 ) ;
else
F_50 ( V_7 , V_1 ) ;
F_25 ( V_1 ) ;
}
V_130 = F_127 ( V_1 , V_30 ) ;
if ( V_130 )
goto V_706;
if ( F_436 ( V_7 ) &&
( V_19 == V_169 || V_19 == V_170 || V_19 == V_171 ) )
F_437 ( V_3 ,
V_30 -> V_4 . V_4 . V_583 ) ;
if ( ! F_419 ( V_1 , V_30 ) ) {
F_124 ( V_1 ) ;
F_382 ( V_3 ) ;
goto V_706;
}
F_394 ( V_1 , V_9 ) ;
if ( F_147 ( V_7 ) && ! F_359 ( V_7 ) ) {
T_5 V_344 = F_31 ( V_707 ) ;
F_41 ( V_707 , ( V_344 & ~ 0xf ) | 0xd ) ;
}
F_438 ( V_9 ) ;
return true ;
V_706:
if ( F_1 ( V_1 ) ) {
F_383 ( & V_1 -> V_301 ) ;
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
T_6 V_68 , enum V_19 V_19 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 ;
struct V_51 * V_51 ;
struct V_598 * V_52 ;
struct V_30 * V_30 ;
V_3 = F_441 ( sizeof( * V_3 ) , V_184 ) ;
if ( ! V_3 )
return;
V_30 = F_442 () ;
if ( ! V_30 )
goto V_708;
V_51 = & V_3 -> V_4 ;
V_52 = & V_51 -> V_4 ;
if ( F_443 ( V_7 , & V_51 -> V_4 , & V_709 ,
V_710 , NULL ) )
goto V_711;
V_51 -> V_712 = F_156 ;
V_51 -> V_713 = F_226 ;
V_51 -> V_696 = F_213 ;
V_51 -> V_714 = F_222 ;
V_51 -> V_715 = F_386 ;
if ( F_36 ( V_7 ) ) {
V_51 -> V_716 = F_283 ;
V_51 -> V_717 = F_272 ;
V_51 -> V_311 = F_257 ;
V_51 -> V_718 = F_242 ;
V_51 -> V_719 = F_287 ;
} else if ( F_62 ( V_7 ) ) {
V_51 -> V_716 = F_266 ;
V_51 -> V_717 = F_261 ;
V_51 -> V_311 = F_257 ;
V_51 -> V_718 = F_232 ;
} else {
V_51 -> V_717 = F_259 ;
V_51 -> V_311 = F_256 ;
if ( F_119 ( V_7 ) -> V_182 >= 5 )
V_51 -> V_718 = F_231 ;
}
V_3 -> V_19 = V_19 ;
V_3 -> V_599 . V_68 = V_68 ;
V_51 -> type = V_584 ;
if ( F_36 ( V_7 ) ) {
if ( V_19 == V_171 )
V_51 -> V_720 = 1 << 2 ;
else
V_51 -> V_720 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_51 -> V_720 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_51 -> V_721 = 0 ;
V_3 -> V_722 = F_390 ;
V_54 -> V_723 . V_724 [ V_19 ] = V_3 ;
if ( ! F_429 ( V_3 , V_30 ) )
goto V_725;
return;
V_725:
F_385 ( V_52 ) ;
V_711:
F_126 ( V_30 ) ;
V_708:
F_126 ( V_3 ) ;
return;
}
void F_444 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_726 ; V_47 ++ ) {
struct V_2 * V_3 = V_54 -> V_723 . V_724 [ V_47 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_584 ) {
if ( ! V_3 -> V_599 . V_487 )
continue;
if ( V_3 -> V_599 . V_490 )
F_445 ( & V_3 -> V_599 . V_491 ) ;
}
}
}
void F_446 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_726 ; V_47 ++ ) {
struct V_2 * V_3 = V_54 -> V_723 . V_724 [ V_47 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_584 ) {
int V_130 ;
if ( ! V_3 -> V_599 . V_487 )
continue;
V_130 = F_447 ( & V_3 -> V_599 . V_491 ) ;
if ( V_130 != 0 ) {
F_341 ( & V_3 -> V_599 ) ;
}
}
}
}
