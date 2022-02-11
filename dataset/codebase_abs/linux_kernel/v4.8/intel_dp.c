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
T_1 V_16 , V_17 ;
V_16 = V_3 -> V_18 ;
V_17 = F_10 ( V_1 -> V_11 ) ;
return F_11 ( V_16 , V_17 ) ;
}
static int
F_12 ( int V_19 , int V_20 )
{
return ( V_19 * V_20 + 9 ) / 10 ;
}
static int
F_13 ( int V_21 , int V_18 )
{
return ( V_21 * V_18 * 8 ) / 10 ;
}
static enum V_22
F_14 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_25 * V_25 = F_15 ( V_9 ) ;
struct V_23 * V_26 = V_25 -> V_27 . V_26 ;
int V_28 = V_24 -> clock ;
int V_29 , V_30 , V_18 , V_21 ;
int V_31 = F_16 ( V_9 -> V_7 ) -> V_32 ;
if ( F_1 ( V_1 ) && V_26 ) {
if ( V_24 -> V_33 > V_26 -> V_33 )
return V_34 ;
if ( V_24 -> V_35 > V_26 -> V_35 )
return V_34 ;
V_28 = V_26 -> clock ;
}
V_21 = F_17 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
V_29 = F_13 ( V_21 , V_18 ) ;
V_30 = F_12 ( V_28 , 18 ) ;
if ( V_30 > V_29 || V_28 > V_31 )
return V_36 ;
if ( V_24 -> clock < 10000 )
return V_37 ;
if ( V_24 -> V_38 & V_39 )
return V_40 ;
return V_41 ;
}
T_2 F_18 ( const T_3 * V_42 , int V_43 )
{
int V_44 ;
T_2 V_45 = 0 ;
if ( V_43 > 4 )
V_43 = 4 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
V_45 |= ( ( T_2 ) V_42 [ V_44 ] ) << ( ( 3 - V_44 ) * 8 ) ;
return V_45 ;
}
static void F_19 ( T_2 V_42 , T_3 * V_46 , int V_47 )
{
int V_44 ;
if ( V_47 > 4 )
V_47 = 4 ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ )
V_46 [ V_44 ] = V_42 >> ( ( 3 - V_44 ) * 8 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
V_53 = F_21 ( V_49 ) ;
F_22 ( V_51 , V_53 ) ;
F_23 ( & V_51 -> V_54 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
F_25 ( & V_51 -> V_54 ) ;
V_53 = F_21 ( V_49 ) ;
F_26 ( V_51 , V_53 ) ;
}
static void
F_27 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_55 V_55 = V_1 -> V_56 ;
bool V_57 , V_58 = false ;
enum V_59 V_60 = F_28 ( V_55 ) ;
enum V_61 V_62 = F_29 ( V_55 ) ;
T_2 V_63 ;
if ( F_8 ( F_30 ( V_1 -> V_64 ) & V_65 ,
L_2 ,
F_31 ( V_55 ) , F_32 ( V_3 -> V_66 ) ) )
return;
F_33 ( L_3 ,
F_31 ( V_55 ) , F_32 ( V_3 -> V_66 ) ) ;
V_63 = F_30 ( V_1 -> V_64 ) & V_67 ;
V_63 |= V_68 | V_69 ;
V_63 |= F_34 ( 1 ) ;
V_63 |= V_70 ;
if ( F_35 ( V_7 ) )
V_63 |= F_36 ( V_55 ) ;
else if ( V_55 == V_71 )
V_63 |= V_72 ;
V_57 = F_30 ( F_37 ( V_55 ) ) & V_73 ;
if ( ! V_57 ) {
V_58 = F_35 ( V_7 ) &&
! F_38 ( V_51 , V_60 , V_62 , true ) ;
if ( F_39 ( V_7 , V_55 , F_35 ( V_7 ) ?
& V_74 [ 0 ] . V_75 : & V_76 [ 0 ] . V_75 ) ) {
F_40 ( L_4 ,
F_31 ( V_55 ) ) ;
return;
}
}
F_41 ( V_1 -> V_64 , V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
F_41 ( V_1 -> V_64 , V_63 | V_65 ) ;
F_42 ( V_1 -> V_64 ) ;
F_41 ( V_1 -> V_64 , V_63 & ~ V_65 ) ;
F_42 ( V_1 -> V_64 ) ;
if ( ! V_57 ) {
F_43 ( V_7 , V_55 ) ;
if ( V_58 )
F_38 ( V_51 , V_60 , V_62 , false ) ;
}
}
static enum V_55
F_44 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_48 * V_49 ;
unsigned int V_77 = ( 1 << V_78 ) | ( 1 << V_71 ) ;
enum V_55 V_55 ;
F_45 ( & V_51 -> V_54 ) ;
F_46 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_56 != V_79 )
return V_1 -> V_56 ;
F_47 (dev, encoder) {
struct V_1 * V_80 ;
if ( V_49 -> type != V_5 )
continue;
V_80 = F_5 ( & V_49 -> V_4 ) ;
if ( V_80 -> V_56 != V_79 )
V_77 &= ~ ( 1 << V_80 -> V_56 ) ;
}
if ( F_46 ( V_77 == 0 ) )
V_55 = V_78 ;
else
V_55 = F_48 ( V_77 ) - 1 ;
F_49 ( V_7 , V_55 ) ;
V_1 -> V_56 = V_55 ;
F_33 ( L_5 ,
F_31 ( V_1 -> V_56 ) ,
F_32 ( V_3 -> V_66 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
F_27 ( V_1 ) ;
return V_1 -> V_56 ;
}
static int
F_52 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
F_45 ( & V_51 -> V_54 ) ;
F_46 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_81 )
return 0 ;
V_1 -> V_81 = false ;
F_51 ( V_7 , V_1 ) ;
return 0 ;
}
static bool F_53 ( struct V_50 * V_51 ,
enum V_55 V_55 )
{
return F_30 ( F_54 ( V_55 ) ) & V_82 ;
}
static bool F_55 ( struct V_50 * V_51 ,
enum V_55 V_55 )
{
return F_30 ( F_56 ( V_55 ) ) & V_83 ;
}
static bool F_57 ( struct V_50 * V_51 ,
enum V_55 V_55 )
{
return true ;
}
static enum V_55
F_58 ( struct V_50 * V_51 ,
enum V_66 V_66 ,
T_4 V_84 )
{
enum V_55 V_55 ;
for ( V_55 = V_78 ; V_55 <= V_71 ; V_55 ++ ) {
T_5 V_85 = F_30 ( F_59 ( V_55 ) ) &
V_86 ;
if ( V_85 != F_60 ( V_66 ) )
continue;
if ( ! V_84 ( V_51 , V_55 ) )
continue;
return V_55 ;
}
return V_79 ;
}
static void
F_61 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
F_45 ( & V_51 -> V_54 ) ;
V_1 -> V_56 = F_58 ( V_51 , V_66 ,
F_53 ) ;
if ( V_1 -> V_56 == V_79 )
V_1 -> V_56 = F_58 ( V_51 , V_66 ,
F_55 ) ;
if ( V_1 -> V_56 == V_79 )
V_1 -> V_56 = F_58 ( V_51 , V_66 ,
F_57 ) ;
if ( V_1 -> V_56 == V_79 ) {
F_33 ( L_6 ,
F_32 ( V_66 ) ) ;
return;
}
F_33 ( L_7 ,
F_32 ( V_66 ) , F_31 ( V_1 -> V_56 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
void F_62 ( struct V_50 * V_51 )
{
struct V_6 * V_7 = & V_51 -> V_87 ;
struct V_48 * V_49 ;
if ( F_46 ( ! F_63 ( V_7 ) && ! F_35 ( V_7 ) &&
! F_64 ( V_7 ) ) )
return;
F_47 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_49 -> type != V_5 )
continue;
V_1 = F_5 ( & V_49 -> V_4 ) ;
if ( F_64 ( V_7 ) )
V_1 -> V_81 = true ;
else
V_1 -> V_56 = V_79 ;
}
}
static void F_65 ( struct V_50 * V_51 ,
struct V_1 * V_1 ,
struct V_88 * V_89 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
if ( F_64 ( V_51 ) ) {
int V_90 = F_52 ( V_1 ) ;
V_89 -> V_91 = F_66 ( V_90 ) ;
V_89 -> V_92 = F_67 ( V_90 ) ;
V_89 -> V_93 = F_68 ( V_90 ) ;
V_89 -> V_94 = F_69 ( V_90 ) ;
} else if ( F_70 ( V_51 ) ) {
V_89 -> V_91 = V_95 ;
V_89 -> V_92 = V_96 ;
V_89 -> V_93 = V_97 ;
V_89 -> V_94 = V_98 ;
V_89 -> V_99 = V_100 ;
} else {
enum V_55 V_55 = F_44 ( V_1 ) ;
V_89 -> V_91 = F_56 ( V_55 ) ;
V_89 -> V_92 = F_54 ( V_55 ) ;
V_89 -> V_93 = F_59 ( V_55 ) ;
V_89 -> V_94 = F_71 ( V_55 ) ;
V_89 -> V_99 = F_72 ( V_55 ) ;
}
}
static T_6
F_73 ( struct V_1 * V_1 )
{
struct V_88 V_89 ;
F_65 ( F_16 ( F_3 ( V_1 ) ) , V_1 ,
& V_89 ) ;
return V_89 . V_91 ;
}
static T_6
F_74 ( struct V_1 * V_1 )
{
struct V_88 V_89 ;
F_65 ( F_16 ( F_3 ( V_1 ) ) , V_1 ,
& V_89 ) ;
return V_89 . V_92 ;
}
static int F_75 ( struct V_101 * V_102 , unsigned long V_103 ,
void * V_104 )
{
struct V_1 * V_1 = F_76 ( V_102 , F_77 ( * V_1 ) ,
V_105 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_103 != V_106 )
return 0 ;
F_20 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
enum V_55 V_55 = F_44 ( V_1 ) ;
T_6 V_107 , V_108 ;
T_5 V_99 ;
V_107 = F_56 ( V_55 ) ;
V_108 = F_72 ( V_55 ) ;
V_99 = F_30 ( V_108 ) ;
V_99 &= V_109 ;
F_41 ( V_108 , V_99 | 0x1F ) ;
F_41 ( V_107 , V_110 | V_111 ) ;
F_78 ( V_1 -> V_112 ) ;
}
F_24 ( V_1 ) ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
F_45 ( & V_51 -> V_54 ) ;
if ( ( F_63 ( V_7 ) || F_35 ( V_7 ) ) &&
V_1 -> V_56 == V_79 )
return false ;
return ( F_30 ( F_74 ( V_1 ) ) & V_82 ) != 0 ;
}
static bool F_80 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
F_45 ( & V_51 -> V_54 ) ;
if ( ( F_63 ( V_7 ) || F_35 ( V_7 ) ) &&
V_1 -> V_56 == V_79 )
return false ;
return F_30 ( F_73 ( V_1 ) ) & V_83 ;
}
static void
F_81 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_79 ( V_1 ) && ! F_80 ( V_1 ) ) {
F_8 ( 1 , L_8 ) ;
F_33 ( L_9 ,
F_30 ( F_74 ( V_1 ) ) ,
F_30 ( F_73 ( V_1 ) ) ) ;
}
}
static T_2
F_82 ( struct V_1 * V_1 , bool V_113 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_6 V_114 = V_1 -> V_115 ;
T_2 V_116 ;
bool V_117 ;
#define F_83 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_113 )
V_117 = F_84 ( V_51 -> V_118 , F_83 ,
F_85 ( 10 ) ) ;
else
V_117 = F_86 ( F_83 , 10 ) == 0 ;
if ( ! V_117 )
F_40 ( L_10 ,
V_113 ) ;
#undef F_83
return V_116 ;
}
static T_2 F_87 ( struct V_1 * V_1 , int V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_119 )
return 0 ;
return F_88 ( V_51 -> V_120 , 2000 ) ;
}
static T_2 F_89 ( struct V_1 * V_1 , int V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_119 )
return 0 ;
if ( V_3 -> V_66 == V_121 )
return F_88 ( V_51 -> V_122 , 2000 ) ;
else
return F_88 ( V_51 -> V_120 , 2000 ) ;
}
static T_2 F_90 ( struct V_1 * V_1 , int V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_66 != V_121 && F_91 ( V_51 ) ) {
switch ( V_119 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_89 ( V_1 , V_119 ) ;
}
static T_2 F_92 ( struct V_1 * V_1 , int V_119 )
{
return V_119 ? 0 : 1 ;
}
static T_2 F_93 ( struct V_1 * V_1 ,
bool V_113 ,
int V_123 ,
T_2 V_124 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_125 , V_126 ;
if ( F_94 ( V_7 ) )
V_125 = 3 ;
else
V_125 = 5 ;
if ( F_95 ( V_7 ) && V_3 -> V_66 == V_121 )
V_126 = V_127 ;
else
V_126 = V_128 ;
return V_129 |
V_130 |
( V_113 ? V_131 : 0 ) |
V_132 |
V_126 |
V_133 |
( V_123 << V_134 ) |
( V_125 << V_135 ) |
( V_124 << V_136 ) ;
}
static T_2 F_96 ( struct V_1 * V_1 ,
bool V_113 ,
int V_123 ,
T_2 V_104 )
{
return V_129 |
V_130 |
( V_113 ? V_131 : 0 ) |
V_132 |
V_137 |
V_133 |
( V_123 << V_134 ) |
F_97 ( 32 ) |
F_98 ( 32 ) ;
}
static int
F_99 ( struct V_1 * V_1 ,
const T_3 * V_138 , int V_123 ,
T_3 * V_139 , int V_140 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_6 V_114 = V_1 -> V_115 ;
T_2 V_124 ;
int V_44 , V_141 , V_142 ;
T_2 V_116 ;
int V_143 , clock = 0 ;
bool V_113 = F_100 ( V_7 ) ;
bool V_144 ;
F_20 ( V_1 ) ;
V_144 = F_101 ( V_1 ) ;
F_102 ( & V_51 -> V_145 , 0 ) ;
F_81 ( V_1 ) ;
for ( V_143 = 0 ; V_143 < 3 ; V_143 ++ ) {
V_116 = F_103 ( V_114 ) ;
if ( ( V_116 & V_129 ) == 0 )
break;
F_78 ( 1 ) ;
}
if ( V_143 == 3 ) {
static T_5 V_146 = - 1 ;
const T_5 V_116 = F_30 ( V_114 ) ;
if ( V_116 != V_146 ) {
F_8 ( 1 , L_11 ,
V_116 ) ;
V_146 = V_116 ;
}
V_141 = - V_147 ;
goto V_148;
}
if ( F_46 ( V_123 > 20 || V_140 > 20 ) ) {
V_141 = - V_149 ;
goto V_148;
}
while ( ( V_124 = V_1 -> V_150 ( V_1 , clock ++ ) ) ) {
T_5 V_151 = V_1 -> V_152 ( V_1 ,
V_113 ,
V_123 ,
V_124 ) ;
for ( V_143 = 0 ; V_143 < 5 ; V_143 ++ ) {
for ( V_44 = 0 ; V_44 < V_123 ; V_44 += 4 )
F_41 ( V_1 -> V_153 [ V_44 >> 2 ] ,
F_18 ( V_138 + V_44 ,
V_123 - V_44 ) ) ;
F_41 ( V_114 , V_151 ) ;
V_116 = F_82 ( V_1 , V_113 ) ;
F_41 ( V_114 ,
V_116 |
V_130 |
V_132 |
V_133 ) ;
if ( V_116 & V_132 )
continue;
if ( V_116 & V_133 ) {
F_104 ( 400 , 500 ) ;
continue;
}
if ( V_116 & V_130 )
goto V_117;
}
}
if ( ( V_116 & V_130 ) == 0 ) {
F_40 ( L_12 , V_116 ) ;
V_141 = - V_147 ;
goto V_148;
}
V_117:
if ( V_116 & V_133 ) {
F_40 ( L_13 , V_116 ) ;
V_141 = - V_154 ;
goto V_148;
}
if ( V_116 & V_132 ) {
F_33 ( L_14 , V_116 ) ;
V_141 = - V_155 ;
goto V_148;
}
V_142 = ( ( V_116 & V_156 ) >>
V_134 ) ;
if ( V_142 == 0 || V_142 > 20 ) {
F_33 ( L_15 ,
V_142 ) ;
F_104 ( 1000 , 1500 ) ;
V_141 = - V_147 ;
goto V_148;
}
if ( V_142 > V_140 )
V_142 = V_140 ;
for ( V_44 = 0 ; V_44 < V_142 ; V_44 += 4 )
F_19 ( F_30 ( V_1 -> V_153 [ V_44 >> 2 ] ) ,
V_139 + V_44 , V_142 - V_44 ) ;
V_141 = V_142 ;
V_148:
F_102 ( & V_51 -> V_145 , V_157 ) ;
if ( V_144 )
F_105 ( V_1 , false ) ;
F_24 ( V_1 ) ;
return V_141 ;
}
static T_7
F_106 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
struct V_1 * V_1 = F_76 ( V_159 , struct V_1 , V_159 ) ;
T_3 V_162 [ 20 ] , V_163 [ 20 ] ;
T_8 V_164 , V_165 ;
int V_141 ;
V_162 [ 0 ] = ( V_161 -> V_166 << 4 ) |
( ( V_161 -> V_167 >> 16 ) & 0xf ) ;
V_162 [ 1 ] = ( V_161 -> V_167 >> 8 ) & 0xff ;
V_162 [ 2 ] = V_161 -> V_167 & 0xff ;
V_162 [ 3 ] = V_161 -> V_168 - 1 ;
switch ( V_161 -> V_166 & ~ V_169 ) {
case V_170 :
case V_171 :
case V_172 :
V_164 = V_161 -> V_168 ? V_173 + V_161 -> V_168 : V_174 ;
V_165 = 2 ;
if ( F_46 ( V_164 > 20 ) )
return - V_149 ;
if ( V_161 -> V_175 )
memcpy ( V_162 + V_173 , V_161 -> V_175 , V_161 -> V_168 ) ;
else
F_46 ( V_161 -> V_168 ) ;
V_141 = F_99 ( V_1 , V_162 , V_164 , V_163 , V_165 ) ;
if ( V_141 > 0 ) {
V_161 -> V_176 = V_163 [ 0 ] >> 4 ;
if ( V_141 > 1 ) {
V_141 = F_107 ( int , V_163 [ 1 ] , 0 , V_161 -> V_168 ) ;
} else {
V_141 = V_161 -> V_168 ;
}
}
break;
case V_177 :
case V_178 :
V_164 = V_161 -> V_168 ? V_173 : V_174 ;
V_165 = V_161 -> V_168 + 1 ;
if ( F_46 ( V_165 > 20 ) )
return - V_149 ;
V_141 = F_99 ( V_1 , V_162 , V_164 , V_163 , V_165 ) ;
if ( V_141 > 0 ) {
V_161 -> V_176 = V_163 [ 0 ] >> 4 ;
V_141 -- ;
memcpy ( V_161 -> V_175 , V_163 + 1 , V_141 ) ;
}
break;
default:
V_141 = - V_179 ;
break;
}
return V_141 ;
}
static T_6 F_108 ( struct V_50 * V_51 ,
enum V_66 V_66 )
{
switch ( V_66 ) {
case V_180 :
case V_181 :
case V_182 :
return F_109 ( V_66 ) ;
default:
F_110 ( V_66 ) ;
return F_109 ( V_180 ) ;
}
}
static T_6 F_111 ( struct V_50 * V_51 ,
enum V_66 V_66 , int V_119 )
{
switch ( V_66 ) {
case V_180 :
case V_181 :
case V_182 :
return F_112 ( V_66 , V_119 ) ;
default:
F_110 ( V_66 ) ;
return F_112 ( V_180 , V_119 ) ;
}
}
static T_6 F_113 ( struct V_50 * V_51 ,
enum V_66 V_66 )
{
switch ( V_66 ) {
case V_121 :
return F_109 ( V_66 ) ;
case V_180 :
case V_181 :
case V_182 :
return F_114 ( V_66 ) ;
default:
F_110 ( V_66 ) ;
return F_109 ( V_121 ) ;
}
}
static T_6 F_115 ( struct V_50 * V_51 ,
enum V_66 V_66 , int V_119 )
{
switch ( V_66 ) {
case V_121 :
return F_112 ( V_66 , V_119 ) ;
case V_180 :
case V_181 :
case V_182 :
return F_116 ( V_66 , V_119 ) ;
default:
F_110 ( V_66 ) ;
return F_112 ( V_121 , V_119 ) ;
}
}
static enum V_66 F_117 ( struct V_50 * V_51 )
{
const struct V_183 * V_184 =
& V_51 -> V_185 . V_186 [ V_187 ] ;
switch ( V_184 -> V_188 ) {
case V_189 :
return V_121 ;
case V_190 :
return V_180 ;
case V_191 :
return V_181 ;
case V_192 :
return V_182 ;
default:
F_110 ( V_184 -> V_188 ) ;
return V_121 ;
}
}
static T_6 F_118 ( struct V_50 * V_51 ,
enum V_66 V_66 )
{
if ( V_66 == V_187 )
V_66 = F_117 ( V_51 ) ;
switch ( V_66 ) {
case V_121 :
case V_180 :
case V_181 :
case V_182 :
return F_109 ( V_66 ) ;
default:
F_110 ( V_66 ) ;
return F_109 ( V_121 ) ;
}
}
static T_6 F_119 ( struct V_50 * V_51 ,
enum V_66 V_66 , int V_119 )
{
if ( V_66 == V_187 )
V_66 = F_117 ( V_51 ) ;
switch ( V_66 ) {
case V_121 :
case V_180 :
case V_181 :
case V_182 :
return F_112 ( V_66 , V_119 ) ;
default:
F_110 ( V_66 ) ;
return F_112 ( V_121 , V_119 ) ;
}
}
static T_6 F_120 ( struct V_50 * V_51 ,
enum V_66 V_66 )
{
if ( F_121 ( V_51 ) -> V_193 >= 9 )
return F_118 ( V_51 , V_66 ) ;
else if ( F_70 ( V_51 ) )
return F_113 ( V_51 , V_66 ) ;
else
return F_108 ( V_51 , V_66 ) ;
}
static T_6 F_122 ( struct V_50 * V_51 ,
enum V_66 V_66 , int V_119 )
{
if ( F_121 ( V_51 ) -> V_193 >= 9 )
return F_119 ( V_51 , V_66 , V_119 ) ;
else if ( F_70 ( V_51 ) )
return F_115 ( V_51 , V_66 , V_119 ) ;
else
return F_111 ( V_51 , V_66 , V_119 ) ;
}
static void F_123 ( struct V_1 * V_1 )
{
struct V_50 * V_51 = F_16 ( F_3 ( V_1 ) ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
int V_44 ;
V_1 -> V_115 = F_120 ( V_51 , V_66 ) ;
for ( V_44 = 0 ; V_44 < F_124 ( V_1 -> V_153 ) ; V_44 ++ )
V_1 -> V_153 [ V_44 ] = F_122 ( V_51 , V_66 , V_44 ) ;
}
static void
F_125 ( struct V_1 * V_1 )
{
F_126 ( V_1 -> V_159 . V_194 ) ;
}
static void
F_127 ( struct V_1 * V_1 , struct V_25 * V_9 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
F_123 ( V_1 ) ;
F_128 ( & V_1 -> V_159 ) ;
V_1 -> V_159 . V_194 = F_129 ( V_195 , L_16 , F_32 ( V_66 ) ) ;
V_1 -> V_159 . V_196 = F_106 ;
}
static int
F_130 ( struct V_1 * V_1 , const int * * V_197 )
{
if ( V_1 -> V_198 ) {
* V_197 = V_1 -> V_197 ;
return V_1 -> V_198 ;
}
* V_197 = V_199 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
bool F_131 ( struct V_1 * V_1 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
if ( F_132 ( V_7 , 0 , V_201 ) )
return false ;
if ( ( F_133 ( V_7 ) && ! F_134 ( V_7 ) ) || F_95 ( V_7 ) ||
( F_121 ( V_7 ) -> V_193 >= 9 ) )
return true ;
else
return false ;
}
static int
F_135 ( struct V_1 * V_1 , const int * * V_202 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
int V_168 ;
if ( F_64 ( V_7 ) ) {
* V_202 = V_203 ;
V_168 = F_124 ( V_203 ) ;
} else if ( F_136 ( V_7 ) || F_137 ( V_7 ) ) {
* V_202 = V_204 ;
V_168 = F_124 ( V_204 ) ;
} else {
* V_202 = V_199 ;
V_168 = F_124 ( V_199 ) ;
}
if ( ! F_131 ( V_1 ) )
V_168 -- ;
return V_168 ;
}
static void
F_138 ( struct V_48 * V_49 ,
struct V_205 * V_206 )
{
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
const struct V_207 * V_208 = NULL ;
int V_44 , V_209 = 0 ;
if ( F_139 ( V_7 ) ) {
V_208 = V_210 ;
V_209 = F_124 ( V_210 ) ;
} else if ( F_70 ( V_7 ) ) {
V_208 = V_211 ;
V_209 = F_124 ( V_211 ) ;
} else if ( F_35 ( V_7 ) ) {
V_208 = V_74 ;
V_209 = F_124 ( V_74 ) ;
} else if ( F_63 ( V_7 ) ) {
V_208 = V_76 ;
V_209 = F_124 ( V_76 ) ;
}
if ( V_208 && V_209 ) {
for ( V_44 = 0 ; V_44 < V_209 ; V_44 ++ ) {
if ( V_206 -> V_212 == V_208 [ V_44 ] . clock ) {
V_206 -> V_75 = V_208 [ V_44 ] . V_75 ;
V_206 -> V_213 = true ;
break;
}
}
}
}
static int F_140 ( const int * V_202 , int V_214 ,
const int * V_197 , int V_215 ,
int * V_216 )
{
int V_44 = 0 , V_217 = 0 , V_218 = 0 ;
while ( V_44 < V_214 && V_217 < V_215 ) {
if ( V_202 [ V_44 ] == V_197 [ V_217 ] ) {
if ( F_46 ( V_218 >= V_219 ) )
return V_218 ;
V_216 [ V_218 ] = V_202 [ V_44 ] ;
++ V_218 ;
++ V_44 ;
++ V_217 ;
} else if ( V_202 [ V_44 ] < V_197 [ V_217 ] ) {
++ V_44 ;
} else {
++ V_217 ;
}
}
return V_218 ;
}
static int F_141 ( struct V_1 * V_1 ,
int * V_216 )
{
const int * V_202 , * V_197 ;
int V_214 , V_215 ;
V_215 = F_130 ( V_1 , & V_197 ) ;
V_214 = F_135 ( V_1 , & V_202 ) ;
return F_140 ( V_202 , V_214 ,
V_197 , V_215 ,
V_216 ) ;
}
static void F_142 ( char * V_220 , T_8 V_221 ,
const int * V_222 , int V_223 )
{
int V_44 ;
V_220 [ 0 ] = '\0' ;
for ( V_44 = 0 ; V_44 < V_223 ; V_44 ++ ) {
int V_224 = snprintf ( V_220 , V_221 , L_17 , V_44 ? L_18 : L_19 , V_222 [ V_44 ] ) ;
if ( V_224 >= V_221 )
return;
V_220 += V_224 ;
V_221 -= V_224 ;
}
}
static void F_143 ( struct V_1 * V_1 )
{
const int * V_202 , * V_197 ;
int V_214 , V_215 , V_225 ;
int V_216 [ V_219 ] ;
char V_220 [ 128 ] ;
if ( ( V_226 & V_227 ) == 0 )
return;
V_214 = F_135 ( V_1 , & V_202 ) ;
F_142 ( V_220 , sizeof( V_220 ) , V_202 , V_214 ) ;
F_33 ( L_20 , V_220 ) ;
V_215 = F_130 ( V_1 , & V_197 ) ;
F_142 ( V_220 , sizeof( V_220 ) , V_197 , V_215 ) ;
F_33 ( L_21 , V_220 ) ;
V_225 = F_141 ( V_1 , V_216 ) ;
F_142 ( V_220 , sizeof( V_220 ) , V_216 , V_225 ) ;
F_33 ( L_22 , V_220 ) ;
}
static int F_144 ( int V_228 , const int * V_229 )
{
int V_44 = 0 ;
for ( V_44 = 0 ; V_44 < V_219 ; ++ V_44 )
if ( V_228 == V_229 [ V_44 ] )
break;
return V_44 ;
}
int
F_17 ( struct V_1 * V_1 )
{
int V_229 [ V_219 ] = {} ;
int V_221 ;
V_221 = F_141 ( V_1 , V_229 ) ;
if ( F_46 ( V_221 <= 0 ) )
return 162000 ;
return V_229 [ F_144 ( 0 , V_229 ) - 1 ] ;
}
int F_145 ( struct V_1 * V_1 , int V_230 )
{
return F_144 ( V_230 , V_1 -> V_197 ) ;
}
void F_146 ( struct V_1 * V_1 , int V_212 ,
T_3 * V_231 , T_3 * V_232 )
{
if ( V_1 -> V_198 ) {
* V_231 = 0 ;
* V_232 =
F_145 ( V_1 , V_212 ) ;
} else {
* V_231 = F_147 ( V_212 ) ;
* V_232 = 0 ;
}
}
bool
F_148 ( struct V_48 * V_49 ,
struct V_205 * V_206 )
{
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_23 * V_233 = & V_206 -> V_4 . V_233 ;
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
struct V_234 * V_234 = F_149 ( V_206 -> V_4 . V_235 ) ;
struct V_25 * V_25 = V_1 -> V_236 ;
int V_237 , clock ;
int V_238 = 1 ;
int V_239 = F_9 ( V_1 ) ;
int V_240 = 0 ;
int V_241 ;
int V_20 , V_30 ;
int V_242 , V_243 ;
int V_216 [ V_219 ] = {} ;
int V_225 ;
T_3 V_231 , V_232 ;
V_225 = F_141 ( V_1 , V_216 ) ;
F_46 ( V_225 <= 0 ) ;
V_241 = V_225 - 1 ;
if ( F_70 ( V_7 ) && ! F_150 ( V_7 ) && V_66 != V_121 )
V_206 -> V_244 = true ;
V_206 -> V_245 = false ;
V_206 -> V_246 = V_1 -> V_246 && V_66 != V_121 ;
if ( F_1 ( V_1 ) && V_25 -> V_27 . V_26 ) {
F_151 ( V_25 -> V_27 . V_26 ,
V_233 ) ;
if ( F_121 ( V_7 ) -> V_193 >= 9 ) {
int V_141 ;
V_141 = F_152 ( V_206 ) ;
if ( V_141 )
return V_141 ;
}
if ( F_153 ( V_7 ) )
F_154 ( V_234 , V_206 ,
V_25 -> V_27 . V_247 ) ;
else
F_155 ( V_234 , V_206 ,
V_25 -> V_27 . V_247 ) ;
}
if ( V_233 -> V_38 & V_39 )
return false ;
F_33 ( L_23
L_24 ,
V_239 , V_216 [ V_241 ] ,
V_233 -> V_248 ) ;
V_20 = V_206 -> V_249 ;
if ( F_1 ( V_1 ) ) {
if ( V_25 -> V_4 . V_250 . V_251 == 0 &&
( V_51 -> V_185 . V_252 . V_20 && V_51 -> V_185 . V_252 . V_20 < V_20 ) ) {
F_33 ( L_25 ,
V_51 -> V_185 . V_252 . V_20 ) ;
V_20 = V_51 -> V_185 . V_252 . V_20 ;
}
V_238 = V_239 ;
V_240 = V_241 ;
}
for (; V_20 >= 6 * 3 ; V_20 -= 2 * 3 ) {
V_30 = F_12 ( V_233 -> V_248 ,
V_20 ) ;
for ( clock = V_240 ; clock <= V_241 ; clock ++ ) {
for ( V_237 = V_238 ;
V_237 <= V_239 ;
V_237 <<= 1 ) {
V_243 = V_216 [ clock ] ;
V_242 = F_13 ( V_243 ,
V_237 ) ;
if ( V_30 <= V_242 ) {
goto V_253;
}
}
}
}
return false ;
V_253:
if ( V_1 -> V_254 ) {
V_206 -> V_255 =
V_20 != 18 && F_156 ( V_233 ) > 1 ;
} else {
V_206 -> V_255 =
V_1 -> V_255 ;
}
V_206 -> V_237 = V_237 ;
V_206 -> V_249 = V_20 ;
V_206 -> V_212 = V_216 [ clock ] ;
F_146 ( V_1 , V_206 -> V_212 ,
& V_231 , & V_232 ) ;
F_33 ( L_26 ,
V_231 , V_232 , V_206 -> V_237 ,
V_206 -> V_212 , V_20 ) ;
F_33 ( L_27 ,
V_30 , V_242 ) ;
F_157 ( V_20 , V_237 ,
V_233 -> V_248 ,
V_206 -> V_212 ,
& V_206 -> V_256 ) ;
if ( V_25 -> V_27 . V_257 != NULL &&
V_51 -> V_258 . type == V_259 ) {
V_206 -> V_245 = true ;
F_157 ( V_20 , V_237 ,
V_25 -> V_27 . V_257 -> clock ,
V_206 -> V_212 ,
& V_206 -> V_260 ) ;
}
if ( F_1 ( V_1 ) &&
( F_136 ( V_51 ) || F_137 ( V_51 ) ) ) {
int V_261 ;
switch ( V_206 -> V_212 / 2 ) {
case 108000 :
case 216000 :
V_261 = 8640000 ;
break;
default:
V_261 = 8100000 ;
break;
}
F_158 ( V_206 -> V_4 . V_262 ) -> V_263 = V_261 ;
}
if ( ! F_150 ( V_7 ) )
F_138 ( V_49 , V_206 ) ;
return true ;
}
void F_159 ( struct V_1 * V_1 ,
const struct V_205 * V_206 )
{
V_1 -> V_264 = V_206 -> V_212 ;
V_1 -> V_237 = V_206 -> V_237 ;
}
static void F_160 ( struct V_48 * V_49 )
{
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
struct V_234 * V_235 = F_149 ( V_49 -> V_4 . V_235 ) ;
const struct V_23 * V_233 = & V_235 -> V_265 -> V_4 . V_233 ;
F_159 ( V_1 , V_235 -> V_265 ) ;
V_1 -> V_63 = F_30 ( V_1 -> V_64 ) & V_67 ;
V_1 -> V_63 |= V_68 | V_69 ;
V_1 -> V_63 |= F_34 ( V_235 -> V_265 -> V_237 ) ;
if ( F_161 ( V_7 ) && V_66 == V_121 ) {
if ( V_233 -> V_38 & V_266 )
V_1 -> V_63 |= V_267 ;
if ( V_233 -> V_38 & V_268 )
V_1 -> V_63 |= V_269 ;
V_1 -> V_63 |= V_270 ;
if ( F_162 ( V_1 -> V_11 ) )
V_1 -> V_63 |= V_271 ;
V_1 -> V_63 |= V_235 -> V_55 << 29 ;
} else if ( F_163 ( V_7 ) && V_66 != V_121 ) {
T_5 V_272 ;
V_1 -> V_63 |= V_270 ;
V_272 = F_30 ( F_164 ( V_235 -> V_55 ) ) ;
if ( F_162 ( V_1 -> V_11 ) )
V_272 |= V_273 ;
else
V_272 &= ~ V_273 ;
F_41 ( F_164 ( V_235 -> V_55 ) , V_272 ) ;
} else {
if ( ! F_70 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_35 ( V_7 ) && V_235 -> V_265 -> V_255 )
V_1 -> V_63 |= V_274 ;
if ( V_233 -> V_38 & V_266 )
V_1 -> V_63 |= V_267 ;
if ( V_233 -> V_38 & V_268 )
V_1 -> V_63 |= V_269 ;
V_1 -> V_63 |= V_275 ;
if ( F_162 ( V_1 -> V_11 ) )
V_1 -> V_63 |= V_271 ;
if ( F_35 ( V_7 ) )
V_1 -> V_63 |= F_36 ( V_235 -> V_55 ) ;
else if ( V_235 -> V_55 == V_71 )
V_1 -> V_63 |= V_72 ;
}
}
static void F_165 ( struct V_1 * V_1 ,
T_5 V_276 ,
T_5 V_277 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_6 V_278 , V_107 ;
F_45 ( & V_51 -> V_54 ) ;
F_166 ( V_51 , V_1 ) ;
V_278 = F_74 ( V_1 ) ;
V_107 = F_73 ( V_1 ) ;
F_33 ( L_28 ,
V_276 , V_277 ,
F_30 ( V_278 ) ,
F_30 ( V_107 ) ) ;
if ( F_167 ( V_51 ,
V_278 , V_276 , V_277 ,
5000 ) )
F_40 ( L_29 ,
F_30 ( V_278 ) ,
F_30 ( V_107 ) ) ;
F_33 ( L_30 ) ;
}
static void F_168 ( struct V_1 * V_1 )
{
F_33 ( L_31 ) ;
F_165 ( V_1 , V_279 , V_280 ) ;
}
static void F_169 ( struct V_1 * V_1 )
{
F_33 ( L_32 ) ;
F_165 ( V_1 , V_281 , V_282 ) ;
}
static void F_170 ( struct V_1 * V_1 )
{
T_9 V_283 ;
T_10 V_284 ;
F_33 ( L_33 ) ;
V_283 = F_171 () ;
V_284 = F_172 ( V_283 , V_1 -> V_285 ) ;
if ( V_284 < ( T_10 ) V_1 -> V_112 )
F_173 ( V_286 ,
V_1 -> V_112 - V_284 ) ;
F_165 ( V_1 , V_287 , V_288 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
F_173 ( V_1 -> V_289 ,
V_1 -> V_290 ) ;
}
static void F_175 ( struct V_1 * V_1 )
{
F_173 ( V_1 -> V_291 ,
V_1 -> V_292 ) ;
}
static T_5 F_176 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_5 V_293 ;
F_45 ( & V_51 -> V_54 ) ;
V_293 = F_30 ( F_73 ( V_1 ) ) ;
if ( ! F_64 ( V_7 ) ) {
V_293 &= ~ V_294 ;
V_293 |= V_110 ;
}
return V_293 ;
}
static bool F_101 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
T_5 V_295 ;
T_6 V_278 , V_107 ;
bool V_296 = ! V_1 -> V_297 ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_177 ( & V_1 -> V_298 ) ;
V_1 -> V_297 = true ;
if ( F_80 ( V_1 ) )
return V_296 ;
V_53 = F_21 ( V_48 ) ;
F_22 ( V_51 , V_53 ) ;
F_33 ( L_34 ,
F_32 ( V_3 -> V_66 ) ) ;
if ( ! F_79 ( V_1 ) )
F_170 ( V_1 ) ;
V_295 = F_176 ( V_1 ) ;
V_295 |= V_83 ;
V_278 = F_74 ( V_1 ) ;
V_107 = F_73 ( V_1 ) ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
F_33 ( L_35 ,
F_30 ( V_278 ) , F_30 ( V_107 ) ) ;
if ( ! F_79 ( V_1 ) ) {
F_33 ( L_36 ,
F_32 ( V_3 -> V_66 ) ) ;
F_78 ( V_1 -> V_299 ) ;
}
return V_296 ;
}
void F_178 ( struct V_1 * V_1 )
{
bool V_144 ;
if ( ! F_1 ( V_1 ) )
return;
F_20 ( V_1 ) ;
V_144 = F_101 ( V_1 ) ;
F_24 ( V_1 ) ;
F_179 ( ! V_144 , L_37 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) ;
}
static void F_180 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
enum V_52 V_53 ;
T_5 V_295 ;
T_6 V_278 , V_107 ;
F_45 ( & V_51 -> V_54 ) ;
F_46 ( V_1 -> V_297 ) ;
if ( ! F_80 ( V_1 ) )
return;
F_33 ( L_38 ,
F_32 ( V_3 -> V_66 ) ) ;
V_295 = F_176 ( V_1 ) ;
V_295 &= ~ V_83 ;
V_107 = F_73 ( V_1 ) ;
V_278 = F_74 ( V_1 ) ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
F_33 ( L_35 ,
F_30 ( V_278 ) , F_30 ( V_107 ) ) ;
if ( ( V_295 & V_300 ) == 0 )
V_1 -> V_285 = F_171 () ;
V_53 = F_21 ( V_48 ) ;
F_26 ( V_51 , V_53 ) ;
}
static void F_181 ( struct V_301 * V_302 )
{
struct V_1 * V_1 = F_76 ( F_182 ( V_302 ) ,
struct V_1 , V_298 ) ;
F_20 ( V_1 ) ;
if ( ! V_1 -> V_297 )
F_180 ( V_1 ) ;
F_24 ( V_1 ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
unsigned long V_303 ;
V_303 = F_184 ( V_1 -> V_112 * 5 ) ;
F_185 ( & V_1 -> V_298 , V_303 ) ;
}
static void F_105 ( struct V_1 * V_1 , bool V_304 )
{
struct V_50 * V_51 = F_16 ( F_3 ( V_1 ) ) ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_179 ( ! V_1 -> V_297 , L_39 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) ;
V_1 -> V_297 = false ;
if ( V_304 )
F_180 ( V_1 ) ;
else
F_183 ( V_1 ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_5 V_295 ;
T_6 V_107 ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_40 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) ;
if ( F_8 ( F_79 ( V_1 ) ,
L_41 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) )
return;
F_170 ( V_1 ) ;
V_107 = F_73 ( V_1 ) ;
V_295 = F_176 ( V_1 ) ;
if ( F_187 ( V_7 ) ) {
V_295 &= ~ V_305 ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
}
V_295 |= V_300 ;
if ( ! F_187 ( V_7 ) )
V_295 |= V_305 ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
F_168 ( V_1 ) ;
V_1 -> V_289 = V_286 ;
if ( F_187 ( V_7 ) ) {
V_295 |= V_305 ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
}
}
void F_188 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_20 ( V_1 ) ;
F_186 ( V_1 ) ;
F_24 ( V_1 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
T_5 V_295 ;
T_6 V_107 ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_42 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) ;
F_8 ( ! V_1 -> V_297 , L_43 ,
F_32 ( F_2 ( V_1 ) -> V_66 ) ) ;
V_295 = F_176 ( V_1 ) ;
V_295 &= ~ ( V_300 | V_305 | V_83 |
V_306 ) ;
V_107 = F_73 ( V_1 ) ;
V_1 -> V_297 = false ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
V_1 -> V_285 = F_171 () ;
F_169 ( V_1 ) ;
V_53 = F_21 ( V_48 ) ;
F_26 ( V_51 , V_53 ) ;
}
void F_190 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_20 ( V_1 ) ;
F_189 ( V_1 ) ;
F_24 ( V_1 ) ;
}
static void F_191 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_5 V_295 ;
T_6 V_107 ;
F_174 ( V_1 ) ;
F_20 ( V_1 ) ;
V_295 = F_176 ( V_1 ) ;
V_295 |= V_306 ;
V_107 = F_73 ( V_1 ) ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
F_24 ( V_1 ) ;
}
void F_192 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_44 ) ;
F_193 ( V_1 -> V_236 ) ;
F_191 ( V_1 ) ;
}
static void F_194 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_5 V_295 ;
T_6 V_107 ;
if ( ! F_1 ( V_1 ) )
return;
F_20 ( V_1 ) ;
V_295 = F_176 ( V_1 ) ;
V_295 &= ~ V_306 ;
V_107 = F_73 ( V_1 ) ;
F_41 ( V_107 , V_295 ) ;
F_42 ( V_107 ) ;
F_24 ( V_1 ) ;
V_1 -> V_291 = V_286 ;
F_175 ( V_1 ) ;
}
void F_195 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_33 ( L_44 ) ;
F_194 ( V_1 ) ;
F_196 ( V_1 -> V_236 ) ;
}
static void F_197 ( struct V_25 * V_9 ,
bool V_307 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_308 ;
F_20 ( V_1 ) ;
V_308 = F_176 ( V_1 ) & V_306 ;
F_24 ( V_1 ) ;
if ( V_308 == V_307 )
return;
F_33 ( L_45 ,
V_307 ? L_46 : L_47 ) ;
if ( V_307 )
F_191 ( V_1 ) ;
else
F_194 ( V_1 ) ;
}
static void F_198 ( struct V_1 * V_1 , bool V_262 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_200 -> V_4 . V_4 . V_7 ) ;
bool V_309 = F_30 ( V_1 -> V_64 ) & V_65 ;
F_179 ( V_309 != V_262 ,
L_48 ,
F_32 ( V_200 -> V_66 ) ,
F_199 ( V_262 ) , F_199 ( V_309 ) ) ;
}
static void F_200 ( struct V_50 * V_51 , bool V_262 )
{
bool V_309 = F_30 ( V_310 ) & V_311 ;
F_179 ( V_309 != V_262 ,
L_49 ,
F_199 ( V_262 ) , F_199 ( V_309 ) ) ;
}
static void F_201 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_234 * V_235 = F_149 ( V_3 -> V_4 . V_4 . V_235 ) ;
struct V_50 * V_51 = F_16 ( V_235 -> V_4 . V_7 ) ;
F_202 ( V_51 , V_235 -> V_55 ) ;
F_203 ( V_1 ) ;
F_204 ( V_51 ) ;
F_33 ( L_50 ,
V_235 -> V_265 -> V_212 ) ;
V_1 -> V_63 &= ~ V_312 ;
if ( V_235 -> V_265 -> V_212 == 162000 )
V_1 -> V_63 |= V_313 ;
else
V_1 -> V_63 |= V_314 ;
F_41 ( V_310 , V_1 -> V_63 ) ;
F_42 ( V_310 ) ;
F_205 ( 500 ) ;
if ( F_187 ( V_51 ) )
F_206 ( & V_51 -> V_87 , ! V_235 -> V_55 ) ;
V_1 -> V_63 |= V_311 ;
F_41 ( V_310 , V_1 -> V_63 ) ;
F_42 ( V_310 ) ;
F_205 ( 200 ) ;
}
static void F_207 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_234 * V_235 = F_149 ( V_3 -> V_4 . V_4 . V_235 ) ;
struct V_50 * V_51 = F_16 ( V_235 -> V_4 . V_7 ) ;
F_202 ( V_51 , V_235 -> V_55 ) ;
F_203 ( V_1 ) ;
F_208 ( V_51 ) ;
F_33 ( L_51 ) ;
V_1 -> V_63 &= ~ V_311 ;
F_41 ( V_310 , V_1 -> V_63 ) ;
F_42 ( V_310 ) ;
F_205 ( 200 ) ;
}
void F_209 ( struct V_1 * V_1 , int V_24 )
{
int V_141 , V_44 ;
if ( V_1 -> V_11 [ V_315 ] < 0x11 )
return;
if ( V_24 != V_316 ) {
V_141 = F_210 ( & V_1 -> V_159 , V_317 ,
V_318 ) ;
} else {
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
V_141 = F_210 ( & V_1 -> V_159 , V_317 ,
V_319 ) ;
if ( V_141 == 1 )
break;
F_78 ( 1 ) ;
}
}
if ( V_141 != 1 )
F_33 ( L_52 ,
V_24 == V_316 ? L_46 : L_47 ) ;
}
static bool F_211 ( struct V_48 * V_49 ,
enum V_55 * V_55 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
T_5 V_80 ;
bool V_141 ;
V_53 = F_212 ( V_49 ) ;
if ( ! F_213 ( V_51 , V_53 ) )
return false ;
V_141 = false ;
V_80 = F_30 ( V_1 -> V_64 ) ;
if ( ! ( V_80 & V_65 ) )
goto V_148;
if ( F_161 ( V_7 ) && V_66 == V_121 ) {
* V_55 = F_214 ( V_80 ) ;
} else if ( F_163 ( V_7 ) && V_66 != V_121 ) {
enum V_55 V_320 ;
F_215 (dev_priv, p) {
T_5 V_272 = F_30 ( F_164 ( V_320 ) ) ;
if ( F_216 ( V_272 ) == V_66 ) {
* V_55 = V_320 ;
V_141 = true ;
goto V_148;
}
}
F_33 ( L_53 ,
F_217 ( V_1 -> V_64 ) ) ;
} else if ( F_35 ( V_7 ) ) {
* V_55 = F_218 ( V_80 ) ;
} else {
* V_55 = F_219 ( V_80 ) ;
}
V_141 = true ;
V_148:
F_26 ( V_51 , V_53 ) ;
return V_141 ;
}
static void F_220 ( struct V_48 * V_49 ,
struct V_205 * V_206 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
T_5 V_80 , V_38 = 0 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
struct V_234 * V_235 = F_149 ( V_49 -> V_4 . V_235 ) ;
V_80 = F_30 ( V_1 -> V_64 ) ;
V_206 -> V_246 = V_80 & V_321 && V_66 != V_121 ;
if ( F_163 ( V_7 ) && V_66 != V_121 ) {
T_5 V_272 = F_30 ( F_164 ( V_235 -> V_55 ) ) ;
if ( V_272 & V_322 )
V_38 |= V_266 ;
else
V_38 |= V_323 ;
if ( V_272 & V_324 )
V_38 |= V_268 ;
else
V_38 |= V_325 ;
} else {
if ( V_80 & V_267 )
V_38 |= V_266 ;
else
V_38 |= V_323 ;
if ( V_80 & V_269 )
V_38 |= V_268 ;
else
V_38 |= V_325 ;
}
V_206 -> V_4 . V_233 . V_38 |= V_38 ;
if ( ! F_70 ( V_7 ) && ! F_63 ( V_7 ) &&
! F_35 ( V_7 ) && V_80 & V_274 )
V_206 -> V_255 = true ;
V_206 -> V_237 =
( ( V_80 & V_326 ) >> V_327 ) + 1 ;
F_221 ( V_235 , V_206 ) ;
if ( V_66 == V_121 ) {
if ( ( F_30 ( V_310 ) & V_312 ) == V_313 )
V_206 -> V_212 = 162000 ;
else
V_206 -> V_212 = 270000 ;
}
V_206 -> V_4 . V_233 . V_248 =
F_222 ( V_206 -> V_212 ,
& V_206 -> V_256 ) ;
if ( F_1 ( V_1 ) && V_51 -> V_185 . V_252 . V_20 &&
V_206 -> V_249 > V_51 -> V_185 . V_252 . V_20 ) {
F_33 ( L_54 ,
V_206 -> V_249 , V_51 -> V_185 . V_252 . V_20 ) ;
V_51 -> V_185 . V_252 . V_20 = V_206 -> V_249 ;
}
}
static void F_223 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_234 * V_235 = F_149 ( V_49 -> V_4 . V_235 ) ;
if ( V_235 -> V_265 -> V_246 )
F_224 ( V_49 ) ;
if ( F_225 ( V_7 ) && ! F_150 ( V_7 ) )
F_226 ( V_1 ) ;
F_178 ( V_1 ) ;
F_195 ( V_1 ) ;
F_209 ( V_1 , V_328 ) ;
F_190 ( V_1 ) ;
if ( F_121 ( V_7 ) -> V_193 < 5 )
F_227 ( V_1 ) ;
}
static void F_228 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
F_227 ( V_1 ) ;
if ( V_66 == V_121 )
F_207 ( V_1 ) ;
}
static void F_229 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
F_227 ( V_1 ) ;
}
static void F_230 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
F_227 ( V_1 ) ;
F_23 ( & V_51 -> V_329 ) ;
F_231 ( V_49 , true ) ;
F_25 ( & V_51 -> V_329 ) ;
}
static void
F_232 ( struct V_1 * V_1 ,
T_2 * V_63 ,
T_3 V_330 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
if ( F_150 ( V_7 ) ) {
T_2 V_331 = F_30 ( F_233 ( V_66 ) ) ;
if ( V_330 & V_332 )
V_331 |= V_333 ;
else
V_331 &= ~ V_333 ;
V_331 &= ~ V_334 ;
switch ( V_330 & V_335 ) {
case V_336 :
V_331 |= V_337 ;
break;
case V_338 :
V_331 |= V_339 ;
break;
case V_340 :
V_331 |= V_341 ;
break;
case V_342 :
V_331 |= V_343 ;
break;
}
F_41 ( F_233 ( V_66 ) , V_331 ) ;
} else if ( ( F_161 ( V_7 ) && V_66 == V_121 ) ||
( F_163 ( V_7 ) && V_66 != V_121 ) ) {
* V_63 &= ~ V_344 ;
switch ( V_330 & V_335 ) {
case V_336 :
* V_63 |= V_270 ;
break;
case V_338 :
* V_63 |= V_345 ;
break;
case V_340 :
* V_63 |= V_346 ;
break;
case V_342 :
F_40 ( L_55 ) ;
* V_63 |= V_346 ;
break;
}
} else {
if ( F_35 ( V_7 ) )
* V_63 &= ~ V_347 ;
else
* V_63 &= ~ V_348 ;
switch ( V_330 & V_335 ) {
case V_336 :
* V_63 |= V_275 ;
break;
case V_338 :
* V_63 |= V_70 ;
break;
case V_340 :
* V_63 |= V_349 ;
break;
case V_342 :
if ( F_35 ( V_7 ) ) {
* V_63 |= V_350 ;
} else {
F_40 ( L_55 ) ;
* V_63 |= V_349 ;
}
break;
}
}
}
static void F_234 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_234 * V_235 =
F_149 ( F_2 ( V_1 ) -> V_4 . V_4 . V_235 ) ;
F_232 ( V_1 , & V_1 -> V_63 ,
V_338 ) ;
F_41 ( V_1 -> V_64 , V_1 -> V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
V_1 -> V_63 |= V_65 ;
if ( V_235 -> V_265 -> V_246 )
V_1 -> V_63 |= V_321 ;
F_41 ( V_1 -> V_64 , V_1 -> V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
}
static void F_235 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_234 * V_235 = F_149 ( V_49 -> V_4 . V_235 ) ;
T_2 V_351 = F_30 ( V_1 -> V_64 ) ;
enum V_55 V_55 = V_235 -> V_55 ;
if ( F_46 ( V_351 & V_65 ) )
return;
F_20 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_35 ( V_7 ) )
F_236 ( V_1 ) ;
F_234 ( V_1 ) ;
F_101 ( V_1 ) ;
F_186 ( V_1 ) ;
F_105 ( V_1 , true ) ;
F_24 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
unsigned int V_352 = 0x0 ;
if ( F_35 ( V_7 ) )
V_352 = F_237 ( V_235 -> V_265 -> V_237 ) ;
F_238 ( V_51 , F_2 ( V_1 ) ,
V_352 ) ;
}
F_209 ( V_1 , V_316 ) ;
F_239 ( V_1 ) ;
F_240 ( V_1 ) ;
if ( V_235 -> V_265 -> V_246 ) {
F_241 ( L_56 ,
F_31 ( V_55 ) ) ;
F_242 ( V_49 ) ;
}
}
static void F_243 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
F_235 ( V_49 ) ;
F_192 ( V_1 ) ;
}
static void F_244 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
F_192 ( V_1 ) ;
F_245 ( V_1 ) ;
}
static void F_246 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_5 ( & V_49 -> V_4 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
F_160 ( V_49 ) ;
if ( V_66 == V_121 )
F_201 ( V_1 ) ;
}
static void F_247 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_55 V_55 = V_1 -> V_56 ;
T_6 V_353 = F_59 ( V_55 ) ;
F_180 ( V_1 ) ;
F_33 ( L_57 ,
F_31 ( V_55 ) , F_32 ( V_3 -> V_66 ) ) ;
F_41 ( V_353 , 0 ) ;
F_42 ( V_353 ) ;
V_1 -> V_56 = V_79 ;
}
static void F_49 ( struct V_6 * V_7 ,
enum V_55 V_55 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_48 * V_49 ;
F_45 ( & V_51 -> V_54 ) ;
if ( F_46 ( V_55 != V_78 && V_55 != V_71 ) )
return;
F_47 (dev, encoder) {
struct V_1 * V_1 ;
enum V_66 V_66 ;
if ( V_49 -> type != V_5 )
continue;
V_1 = F_5 ( & V_49 -> V_4 ) ;
V_66 = F_2 ( V_1 ) -> V_66 ;
if ( V_1 -> V_56 != V_55 )
continue;
F_33 ( L_58 ,
F_31 ( V_55 ) , F_32 ( V_66 ) ) ;
F_8 ( V_49 -> V_4 . V_235 ,
L_59 ,
F_31 ( V_55 ) , F_32 ( V_66 ) ) ;
F_247 ( V_1 ) ;
}
}
static void F_236 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_49 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_49 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_234 * V_235 = F_149 ( V_49 -> V_4 . V_235 ) ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_56 == V_235 -> V_55 )
return;
if ( V_1 -> V_56 != V_79 )
F_247 ( V_1 ) ;
F_49 ( V_7 , V_235 -> V_55 ) ;
V_1 -> V_56 = V_235 -> V_55 ;
F_33 ( L_60 ,
F_31 ( V_1 -> V_56 ) , F_32 ( V_3 -> V_66 ) ) ;
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
static void F_248 ( struct V_48 * V_49 )
{
F_249 ( V_49 ) ;
F_235 ( V_49 ) ;
}
static void F_250 ( struct V_48 * V_49 )
{
F_160 ( V_49 ) ;
F_251 ( V_49 ) ;
}
static void F_252 ( struct V_48 * V_49 )
{
F_253 ( V_49 ) ;
F_235 ( V_49 ) ;
F_254 ( V_49 ) ;
}
static void F_255 ( struct V_48 * V_49 )
{
F_160 ( V_49 ) ;
F_256 ( V_49 ) ;
}
static void F_257 ( struct V_48 * V_49 )
{
F_258 ( V_49 ) ;
}
bool
F_259 ( struct V_1 * V_1 , T_3 V_354 [ V_355 ] )
{
return F_260 ( & V_1 -> V_159 , V_356 , V_354 ,
V_355 ) == V_355 ;
}
T_3
F_261 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
if ( F_64 ( V_7 ) )
return V_357 ;
else if ( F_121 ( V_7 ) -> V_193 >= 9 ) {
if ( V_51 -> V_185 . V_252 . V_358 && V_66 == V_121 )
return V_357 ;
return V_359 ;
} else if ( F_63 ( V_7 ) || F_35 ( V_7 ) )
return V_357 ;
else if ( F_161 ( V_7 ) && V_66 == V_121 )
return V_359 ;
else if ( F_163 ( V_7 ) && V_66 != V_121 )
return V_357 ;
else
return V_359 ;
}
T_3
F_262 ( struct V_1 * V_1 , T_3 V_360 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
if ( F_121 ( V_7 ) -> V_193 >= 9 ) {
switch ( V_360 & V_361 ) {
case V_362 :
return V_363 ;
case V_364 :
return V_365 ;
case V_359 :
return V_366 ;
case V_357 :
return V_367 ;
default:
return V_367 ;
}
} else if ( F_133 ( V_7 ) || F_95 ( V_7 ) ) {
switch ( V_360 & V_361 ) {
case V_362 :
return V_363 ;
case V_364 :
return V_365 ;
case V_359 :
return V_366 ;
case V_357 :
default:
return V_367 ;
}
} else if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
switch ( V_360 & V_361 ) {
case V_362 :
return V_363 ;
case V_364 :
return V_365 ;
case V_359 :
return V_366 ;
case V_357 :
default:
return V_367 ;
}
} else if ( F_161 ( V_7 ) && V_66 == V_121 ) {
switch ( V_360 & V_361 ) {
case V_362 :
return V_365 ;
case V_364 :
case V_359 :
return V_366 ;
default:
return V_367 ;
}
} else {
switch ( V_360 & V_361 ) {
case V_362 :
return V_365 ;
case V_364 :
return V_365 ;
case V_359 :
return V_366 ;
case V_357 :
default:
return V_367 ;
}
}
}
static T_2 F_263 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_368 , V_369 ,
V_370 ;
T_3 V_371 = V_1 -> V_371 [ 0 ] ;
switch ( V_371 & V_372 ) {
case V_367 :
V_369 = 0x0004000 ;
switch ( V_371 & V_361 ) {
case V_362 :
V_368 = 0x2B405555 ;
V_370 = 0x552AB83A ;
break;
case V_364 :
V_368 = 0x2B404040 ;
V_370 = 0x5548B83A ;
break;
case V_359 :
V_368 = 0x2B245555 ;
V_370 = 0x5560B83A ;
break;
case V_357 :
V_368 = 0x2B405555 ;
V_370 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_366 :
V_369 = 0x0002000 ;
switch ( V_371 & V_361 ) {
case V_362 :
V_368 = 0x2B404040 ;
V_370 = 0x5552B83A ;
break;
case V_364 :
V_368 = 0x2B404848 ;
V_370 = 0x5580B83A ;
break;
case V_359 :
V_368 = 0x2B404040 ;
V_370 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_365 :
V_369 = 0x0000000 ;
switch ( V_371 & V_361 ) {
case V_362 :
V_368 = 0x2B305555 ;
V_370 = 0x5570B83A ;
break;
case V_364 :
V_368 = 0x2B2B4040 ;
V_370 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_363 :
V_369 = 0x0006000 ;
switch ( V_371 & V_361 ) {
case V_362 :
V_368 = 0x1B405555 ;
V_370 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_264 ( V_49 , V_368 , V_369 ,
V_370 , 0 ) ;
return 0 ;
}
static T_2 F_265 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_373 , V_374 ;
bool V_375 = false ;
T_3 V_371 = V_1 -> V_371 [ 0 ] ;
switch ( V_371 & V_372 ) {
case V_367 :
switch ( V_371 & V_361 ) {
case V_362 :
V_373 = 128 ;
V_374 = 52 ;
break;
case V_364 :
V_373 = 128 ;
V_374 = 77 ;
break;
case V_359 :
V_373 = 128 ;
V_374 = 102 ;
break;
case V_357 :
V_373 = 128 ;
V_374 = 154 ;
V_375 = true ;
break;
default:
return 0 ;
}
break;
case V_366 :
switch ( V_371 & V_361 ) {
case V_362 :
V_373 = 85 ;
V_374 = 78 ;
break;
case V_364 :
V_373 = 85 ;
V_374 = 116 ;
break;
case V_359 :
V_373 = 85 ;
V_374 = 154 ;
break;
default:
return 0 ;
}
break;
case V_365 :
switch ( V_371 & V_361 ) {
case V_362 :
V_373 = 64 ;
V_374 = 104 ;
break;
case V_364 :
V_373 = 64 ;
V_374 = 154 ;
break;
default:
return 0 ;
}
break;
case V_363 :
switch ( V_371 & V_361 ) {
case V_362 :
V_373 = 43 ;
V_374 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_266 ( V_49 , V_373 ,
V_374 , V_375 ) ;
return 0 ;
}
static T_2
F_267 ( T_3 V_371 )
{
T_2 V_376 = 0 ;
switch ( V_371 & V_361 ) {
case V_362 :
default:
V_376 |= V_68 ;
break;
case V_364 :
V_376 |= V_377 ;
break;
case V_359 :
V_376 |= V_378 ;
break;
case V_357 :
V_376 |= V_379 ;
break;
}
switch ( V_371 & V_372 ) {
case V_367 :
default:
V_376 |= V_69 ;
break;
case V_366 :
V_376 |= V_380 ;
break;
case V_365 :
V_376 |= V_381 ;
break;
case V_363 :
V_376 |= V_382 ;
break;
}
return V_376 ;
}
static T_2
F_268 ( T_3 V_371 )
{
int V_376 = V_371 & ( V_361 |
V_372 ) ;
switch ( V_376 ) {
case V_362 | V_367 :
case V_364 | V_367 :
return V_383 ;
case V_362 | V_366 :
return V_384 ;
case V_362 | V_365 :
case V_364 | V_365 :
return V_385 ;
case V_364 | V_366 :
case V_359 | V_366 :
return V_386 ;
case V_359 | V_367 :
case V_357 | V_367 :
return V_387 ;
default:
F_33 ( L_61
L_62 , V_376 ) ;
return V_383 ;
}
}
static T_2
F_269 ( T_3 V_371 )
{
int V_376 = V_371 & ( V_361 |
V_372 ) ;
switch ( V_376 ) {
case V_362 | V_367 :
return V_388 ;
case V_362 | V_366 :
return V_389 ;
case V_362 | V_365 :
return V_390 ;
case V_364 | V_367 :
return V_391 ;
case V_364 | V_366 :
return V_392 ;
case V_359 | V_367 :
return V_393 ;
case V_359 | V_366 :
return V_394 ;
default:
F_33 ( L_61
L_62 , V_376 ) ;
return V_395 ;
}
}
void
F_270 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_2 V_376 , V_276 = 0 ;
T_3 V_371 = V_1 -> V_371 [ 0 ] ;
if ( F_150 ( V_7 ) ) {
V_376 = F_271 ( V_1 ) ;
if ( F_64 ( V_7 ) )
V_376 = 0 ;
else
V_276 = V_396 ;
} else if ( F_35 ( V_7 ) ) {
V_376 = F_265 ( V_1 ) ;
} else if ( F_63 ( V_7 ) ) {
V_376 = F_263 ( V_1 ) ;
} else if ( F_161 ( V_7 ) && V_66 == V_121 ) {
V_376 = F_269 ( V_371 ) ;
V_276 = V_397 ;
} else if ( F_94 ( V_7 ) && V_66 == V_121 ) {
V_376 = F_268 ( V_371 ) ;
V_276 = V_398 ;
} else {
V_376 = F_267 ( V_371 ) ;
V_276 = V_399 | V_400 ;
}
if ( V_276 )
F_33 ( L_63 , V_376 ) ;
F_33 ( L_64 ,
V_371 & V_361 ) ;
F_33 ( L_65 ,
( V_371 & V_372 ) >>
V_401 ) ;
V_1 -> V_63 = ( V_1 -> V_63 & ~ V_276 ) | V_376 ;
F_41 ( V_1 -> V_64 , V_1 -> V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
}
void
F_272 ( struct V_1 * V_1 ,
T_3 V_330 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_50 * V_51 =
F_16 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_232 ( V_1 , & V_1 -> V_63 , V_330 ) ;
F_41 ( V_1 -> V_64 , V_1 -> V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
}
void F_273 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
T_2 V_402 ;
if ( ! F_150 ( V_7 ) )
return;
V_402 = F_30 ( F_233 ( V_66 ) ) ;
V_402 &= ~ V_334 ;
V_402 |= V_403 ;
F_41 ( F_233 ( V_66 ) , V_402 ) ;
if ( V_66 == V_121 )
return;
if ( F_167 ( V_51 , F_274 ( V_66 ) ,
V_404 ,
V_404 ,
1 ) )
F_40 ( L_66 ) ;
}
static void
F_227 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_234 * V_235 = F_149 ( V_3 -> V_4 . V_4 . V_235 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_2 V_63 = V_1 -> V_63 ;
if ( F_46 ( F_150 ( V_7 ) ) )
return;
if ( F_46 ( ( F_30 ( V_1 -> V_64 ) & V_65 ) == 0 ) )
return;
F_33 ( L_44 ) ;
if ( ( F_161 ( V_7 ) && V_66 == V_121 ) ||
( F_163 ( V_7 ) && V_66 != V_121 ) ) {
V_63 &= ~ V_344 ;
V_63 |= V_405 ;
} else {
if ( F_35 ( V_7 ) )
V_63 &= ~ V_347 ;
else
V_63 &= ~ V_348 ;
V_63 |= V_406 ;
}
F_41 ( V_1 -> V_64 , V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
V_63 &= ~ ( V_65 | V_321 ) ;
F_41 ( V_1 -> V_64 , V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
if ( F_275 ( V_7 ) && V_235 -> V_55 == V_71 && V_66 != V_121 ) {
F_276 ( V_51 , V_78 , false ) ;
F_277 ( V_51 , V_78 , false ) ;
V_63 &= ~ ( V_72 | V_348 ) ;
V_63 |= V_65 | V_70 ;
F_41 ( V_1 -> V_64 , V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
V_63 &= ~ V_65 ;
F_41 ( V_1 -> V_64 , V_63 ) ;
F_42 ( V_1 -> V_64 ) ;
F_206 ( & V_51 -> V_87 , V_78 ) ;
F_276 ( V_51 , V_78 , true ) ;
F_277 ( V_51 , V_78 , true ) ;
}
F_78 ( V_1 -> V_407 ) ;
V_1 -> V_63 = V_63 ;
}
static bool
F_278 ( struct V_1 * V_1 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
if ( F_260 ( & V_1 -> V_159 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_33 ( L_67 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_315 ] == 0 )
return false ;
if ( F_260 ( & V_1 -> V_159 , V_408 ,
& V_1 -> V_409 , 1 ) < 0 )
return false ;
V_1 -> V_409 = F_279 ( V_1 -> V_409 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_409 )
return false ;
memset ( V_1 -> V_410 , 0 , sizeof( V_1 -> V_410 ) ) ;
if ( F_1 ( V_1 ) ) {
F_260 ( & V_1 -> V_159 , V_411 ,
V_1 -> V_410 ,
sizeof( V_1 -> V_410 ) ) ;
if ( V_1 -> V_410 [ 0 ] & V_412 ) {
V_51 -> V_413 . V_414 = true ;
F_33 ( L_68 ) ;
}
if ( F_121 ( V_7 ) -> V_193 >= 9 &&
( V_1 -> V_410 [ 0 ] & V_415 ) ) {
T_3 V_416 ;
V_51 -> V_413 . V_414 = true ;
F_260 ( & V_1 -> V_159 ,
V_417 ,
& V_416 , 1 ) ;
V_51 -> V_413 . V_418 = V_416 ? true : false ;
V_51 -> V_413 . V_419 = V_51 -> V_413 . V_418 ;
F_33 ( L_69 ,
V_51 -> V_413 . V_419 ? L_70 : L_71 ) ;
}
memset ( V_1 -> V_420 , 0 , sizeof( V_1 -> V_420 ) ) ;
if ( ( V_1 -> V_11 [ V_421 ] & V_422 ) &&
( F_260 ( & V_1 -> V_159 , V_423 ,
V_1 -> V_420 , sizeof( V_1 -> V_420 ) ) ==
sizeof( V_1 -> V_420 ) ) )
F_33 ( L_72 , ( int ) sizeof( V_1 -> V_420 ) ,
V_1 -> V_420 ) ;
}
F_33 ( L_73 ,
F_280 ( F_131 ( V_1 ) ) ,
F_280 ( F_281 ( V_1 -> V_11 ) ) ) ;
if ( F_1 ( V_1 ) && ( V_1 -> V_420 [ 0 ] >= 0x03 ) ) {
T_11 V_197 [ V_219 ] ;
int V_44 ;
F_260 ( & V_1 -> V_159 , V_424 ,
V_197 , sizeof( V_197 ) ) ;
for ( V_44 = 0 ; V_44 < F_124 ( V_197 ) ; V_44 ++ ) {
int V_402 = F_282 ( V_197 [ V_44 ] ) ;
if ( V_402 == 0 )
break;
V_1 -> V_197 [ V_44 ] = ( V_402 * 200 ) / 10 ;
}
V_1 -> V_198 = V_44 ;
}
F_143 ( V_1 ) ;
if ( ! ( V_1 -> V_11 [ V_425 ] &
V_426 ) )
return true ;
if ( V_1 -> V_11 [ V_315 ] == 0x10 )
return true ;
if ( F_260 ( & V_1 -> V_159 , V_427 ,
V_1 -> V_428 ,
V_429 ) < 0 )
return false ;
return true ;
}
static void
F_283 ( struct V_1 * V_1 )
{
T_1 V_430 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_431 ] & V_432 ) )
return;
if ( F_260 ( & V_1 -> V_159 , V_433 , V_430 , 3 ) == 3 )
F_33 ( L_74 ,
V_430 [ 0 ] , V_430 [ 1 ] , V_430 [ 2 ] ) ;
if ( F_260 ( & V_1 -> V_159 , V_434 , V_430 , 3 ) == 3 )
F_33 ( L_75 ,
V_430 [ 0 ] , V_430 [ 1 ] , V_430 [ 2 ] ) ;
}
static bool
F_284 ( struct V_1 * V_1 )
{
T_1 V_430 [ 1 ] ;
if ( ! V_435 . V_436 )
return false ;
if ( ! V_1 -> V_437 )
return false ;
if ( V_1 -> V_11 [ V_315 ] < 0x12 )
return false ;
if ( F_260 ( & V_1 -> V_159 , V_438 , V_430 , 1 ) ) {
if ( V_430 [ 0 ] & V_439 ) {
F_33 ( L_76 ) ;
V_1 -> V_440 = true ;
} else {
F_33 ( L_77 ) ;
V_1 -> V_440 = false ;
}
}
F_285 ( & V_1 -> V_441 , V_1 -> V_440 ) ;
return V_1 -> V_440 ;
}
static int F_286 ( struct V_1 * V_1 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
struct V_234 * V_234 = F_149 ( V_200 -> V_4 . V_4 . V_235 ) ;
T_1 V_430 ;
int V_141 = 0 ;
int V_209 = 0 ;
int V_442 = 10 ;
if ( F_287 ( & V_1 -> V_159 , V_443 , & V_430 ) < 0 ) {
F_33 ( L_78 ) ;
V_141 = - V_154 ;
goto V_148;
}
if ( F_210 ( & V_1 -> V_159 , V_443 ,
V_430 & ~ V_444 ) < 0 ) {
F_33 ( L_78 ) ;
V_141 = - V_154 ;
goto V_148;
}
do {
F_288 ( V_7 , V_234 -> V_55 ) ;
if ( F_287 ( & V_1 -> V_159 ,
V_445 , & V_430 ) < 0 ) {
V_141 = - V_154 ;
goto V_148;
}
V_209 = V_430 & V_446 ;
} while ( -- V_442 && V_209 );
if ( V_442 == 0 ) {
F_33 ( L_79 ) ;
V_141 = - V_155 ;
}
V_148:
F_289 ( V_234 ) ;
return V_141 ;
}
static int F_290 ( struct V_1 * V_1 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
struct V_234 * V_234 = F_149 ( V_200 -> V_4 . V_4 . V_235 ) ;
T_1 V_430 ;
int V_141 ;
if ( F_287 ( & V_1 -> V_159 , V_445 , & V_430 ) < 0 )
return - V_154 ;
if ( ! ( V_430 & V_447 ) )
return - V_448 ;
if ( F_287 ( & V_1 -> V_159 , V_443 , & V_430 ) < 0 )
return - V_154 ;
if ( V_430 & V_444 ) {
V_141 = F_286 ( V_1 ) ;
if ( V_141 )
return V_141 ;
}
F_291 ( V_234 ) ;
if ( F_210 ( & V_1 -> V_159 , V_443 ,
V_430 | V_444 ) < 0 ) {
F_289 ( V_234 ) ;
return - V_154 ;
}
F_288 ( V_7 , V_234 -> V_55 ) ;
return 0 ;
}
int F_292 ( struct V_1 * V_1 , T_1 * V_449 )
{
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_200 -> V_4 . V_4 . V_7 ;
struct V_234 * V_234 = F_149 ( V_200 -> V_4 . V_4 . V_235 ) ;
T_1 V_430 ;
int V_209 , V_141 ;
int V_442 = 6 ;
V_141 = F_290 ( V_1 ) ;
if ( V_141 )
return V_141 ;
do {
F_288 ( V_7 , V_234 -> V_55 ) ;
if ( F_287 ( & V_1 -> V_159 ,
V_445 , & V_430 ) < 0 ) {
V_141 = - V_154 ;
goto V_450;
}
V_209 = V_430 & V_446 ;
} while ( -- V_442 && V_209 == 0 );
if ( V_442 == 0 ) {
F_40 ( L_80 ) ;
V_141 = - V_155 ;
goto V_450;
}
if ( F_260 ( & V_1 -> V_159 , V_451 , V_449 , 6 ) < 0 ) {
V_141 = - V_154 ;
goto V_450;
}
V_450:
F_286 ( V_1 ) ;
return V_141 ;
}
static bool
F_293 ( struct V_1 * V_1 , T_1 * V_452 )
{
return F_260 ( & V_1 -> V_159 ,
V_453 ,
V_452 , 1 ) == 1 ;
}
static bool
F_294 ( struct V_1 * V_1 , T_1 * V_452 )
{
int V_141 ;
V_141 = F_260 ( & V_1 -> V_159 ,
V_454 ,
V_452 , 14 ) ;
if ( V_141 != 14 )
return false ;
return true ;
}
static T_3 F_295 ( struct V_1 * V_1 )
{
T_3 V_455 = V_456 ;
return V_455 ;
}
static T_3 F_296 ( struct V_1 * V_1 )
{
T_3 V_455 = V_457 ;
return V_455 ;
}
static T_3 F_297 ( struct V_1 * V_1 )
{
T_3 V_455 = V_457 ;
struct V_25 * V_25 = V_1 -> V_236 ;
struct V_8 * V_9 = & V_25 -> V_4 ;
if ( V_25 -> V_458 == NULL ||
V_9 -> V_459 ||
V_1 -> V_159 . V_460 > 6 ) {
if ( V_1 -> V_159 . V_461 > 0 ||
V_1 -> V_159 . V_460 > 0 )
F_33 ( L_81 ,
V_1 -> V_159 . V_461 ,
V_1 -> V_159 . V_460 ) ;
V_1 -> V_462 = V_463 ;
} else {
struct V_464 * V_465 = V_25 -> V_458 ;
V_465 += V_25 -> V_458 -> V_466 ;
if ( ! F_298 ( & V_1 -> V_159 ,
V_467 ,
& V_465 -> V_468 ,
1 ) )
F_33 ( L_82 ) ;
V_455 = V_456 | V_469 ;
V_1 -> V_462 = V_470 ;
}
V_1 -> V_471 = 1 ;
return V_455 ;
}
static T_3 F_299 ( struct V_1 * V_1 )
{
T_3 V_455 = V_457 ;
return V_455 ;
}
static void F_300 ( struct V_1 * V_1 )
{
T_3 V_472 = V_457 ;
T_3 V_473 = 0 ;
int V_116 = 0 ;
V_116 = F_260 ( & V_1 -> V_159 , V_474 , & V_473 , 1 ) ;
if ( V_116 <= 0 ) {
F_33 ( L_83 ) ;
goto V_475;
}
switch ( V_473 ) {
case V_476 :
F_33 ( L_84 ) ;
V_1 -> V_477 = V_476 ;
V_472 = F_295 ( V_1 ) ;
break;
case V_478 :
F_33 ( L_85 ) ;
V_1 -> V_477 = V_478 ;
V_472 = F_296 ( V_1 ) ;
break;
case V_479 :
F_33 ( L_86 ) ;
V_1 -> V_477 = V_479 ;
V_472 = F_297 ( V_1 ) ;
break;
case V_480 :
F_33 ( L_87 ) ;
V_1 -> V_477 = V_480 ;
V_472 = F_299 ( V_1 ) ;
break;
default:
F_33 ( L_88 , V_473 ) ;
break;
}
V_475:
V_116 = F_298 ( & V_1 -> V_159 ,
V_481 ,
& V_472 , 1 ) ;
if ( V_116 <= 0 )
F_33 ( L_89 ) ;
}
static int
F_301 ( struct V_1 * V_1 )
{
bool V_482 ;
if ( V_1 -> V_440 ) {
T_1 V_483 [ 16 ] = { 0 } ;
int V_141 = 0 ;
int V_484 ;
bool V_485 ;
V_482 = F_294 ( V_1 , V_483 ) ;
V_486:
if ( V_482 == true ) {
if ( V_1 -> V_487 &&
! F_302 ( & V_483 [ 10 ] , V_1 -> V_237 ) ) {
F_33 ( L_90 ) ;
F_239 ( V_1 ) ;
F_240 ( V_1 ) ;
}
F_33 ( L_91 , V_483 ) ;
V_141 = F_303 ( & V_1 -> V_441 , V_483 , & V_485 ) ;
if ( V_485 ) {
for ( V_484 = 0 ; V_484 < 3 ; V_484 ++ ) {
int V_488 ;
V_488 = F_298 ( & V_1 -> V_159 ,
V_454 + 1 ,
& V_483 [ 1 ] , 3 ) ;
if ( V_488 == 3 ) {
break;
}
}
V_482 = F_294 ( V_1 , V_483 ) ;
if ( V_482 == true ) {
F_33 ( L_92 , V_483 ) ;
goto V_486;
}
} else
V_141 = 0 ;
return V_141 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_33 ( L_93 ) ;
V_1 -> V_440 = false ;
F_285 ( & V_1 -> V_441 , V_1 -> V_440 ) ;
F_304 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_179 ;
}
static void
F_305 ( struct V_1 * V_1 )
{
struct V_48 * V_48 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_354 [ V_355 ] ;
F_46 ( ! F_306 ( & V_7 -> V_489 . V_490 ) ) ;
if ( ! F_259 ( V_1 , V_354 ) ) {
F_40 ( L_94 ) ;
return;
}
if ( ! V_48 -> V_4 . V_235 )
return;
if ( ! F_149 ( V_48 -> V_4 . V_235 ) -> V_491 )
return;
if ( ( V_1 -> V_477 == V_476 ) ||
( ! F_302 ( V_354 , V_1 -> V_237 ) ) ) {
F_33 ( L_95 ,
V_48 -> V_4 . V_194 ) ;
F_239 ( V_1 ) ;
F_240 ( V_1 ) ;
}
}
static bool
F_307 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_452 ;
T_1 V_492 = V_1 -> V_409 ;
bool V_141 ;
V_1 -> V_471 = 0 ;
V_1 -> V_477 = 0 ;
V_1 -> V_462 = 0 ;
V_141 = F_278 ( V_1 ) ;
if ( ( V_492 != V_1 -> V_409 ) || ! V_141 ) {
return false ;
}
if ( V_1 -> V_11 [ V_315 ] >= 0x11 &&
F_293 ( V_1 , & V_452 ) ) {
F_210 ( & V_1 -> V_159 ,
V_453 ,
V_452 ) ;
if ( V_452 & V_493 )
F_241 ( L_96 ) ;
if ( V_452 & ( V_494 | V_495 ) )
F_241 ( L_97 ) ;
}
F_308 ( & V_7 -> V_489 . V_490 , NULL ) ;
F_305 ( V_1 ) ;
F_309 ( & V_7 -> V_489 . V_490 ) ;
return true ;
}
static enum V_496
F_310 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_278 ( V_1 ) )
return V_497 ;
if ( F_1 ( V_1 ) )
return V_498 ;
if ( ! ( V_11 [ V_425 ] & V_426 ) )
return V_498 ;
if ( V_1 -> V_11 [ V_315 ] >= 0x11 &&
V_1 -> V_428 [ 0 ] & V_499 ) {
return V_1 -> V_409 ?
V_498 : V_497 ;
}
if ( F_311 ( & V_1 -> V_159 . V_500 ) )
return V_498 ;
if ( V_1 -> V_11 [ V_315 ] >= 0x11 ) {
type = V_1 -> V_428 [ 0 ] & V_501 ;
if ( type == V_502 ||
type == V_503 )
return V_504 ;
} else {
type = V_1 -> V_11 [ V_425 ] &
V_505 ;
if ( type == V_506 ||
type == V_507 )
return V_504 ;
}
F_33 ( L_98 ) ;
return V_497 ;
}
static enum V_496
F_312 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_496 V_116 ;
V_116 = F_313 ( V_7 ) ;
if ( V_116 == V_504 )
V_116 = V_498 ;
return V_116 ;
}
static bool F_314 ( struct V_50 * V_51 ,
struct V_2 * V_66 )
{
T_5 V_508 ;
switch ( V_66 -> V_66 ) {
case V_121 :
return true ;
case V_180 :
V_508 = V_509 ;
break;
case V_181 :
V_508 = V_510 ;
break;
case V_182 :
V_508 = V_511 ;
break;
default:
F_110 ( V_66 -> V_66 ) ;
return false ;
}
return F_30 ( V_512 ) & V_508 ;
}
static bool F_315 ( struct V_50 * V_51 ,
struct V_2 * V_66 )
{
T_5 V_508 ;
switch ( V_66 -> V_66 ) {
case V_121 :
return true ;
case V_180 :
V_508 = V_513 ;
break;
case V_181 :
V_508 = V_514 ;
break;
case V_182 :
V_508 = V_515 ;
break;
case V_187 :
V_508 = V_516 ;
break;
default:
F_110 ( V_66 -> V_66 ) ;
return false ;
}
return F_30 ( V_512 ) & V_508 ;
}
static bool F_316 ( struct V_50 * V_51 ,
struct V_2 * V_66 )
{
T_5 V_508 ;
switch ( V_66 -> V_66 ) {
case V_180 :
V_508 = V_517 ;
break;
case V_181 :
V_508 = V_518 ;
break;
case V_182 :
V_508 = V_519 ;
break;
default:
F_110 ( V_66 -> V_66 ) ;
return false ;
}
return F_30 ( V_520 ) & V_508 ;
}
static bool F_317 ( struct V_50 * V_51 ,
struct V_2 * V_66 )
{
T_5 V_508 ;
switch ( V_66 -> V_66 ) {
case V_180 :
V_508 = V_521 ;
break;
case V_181 :
V_508 = V_522 ;
break;
case V_182 :
V_508 = V_523 ;
break;
default:
F_110 ( V_66 -> V_66 ) ;
return false ;
}
return F_30 ( V_520 ) & V_508 ;
}
static bool F_318 ( struct V_50 * V_51 ,
struct V_2 * V_3 )
{
struct V_48 * V_48 = & V_3 -> V_4 ;
enum V_66 V_66 ;
T_5 V_508 ;
F_319 ( V_48 -> V_524 , & V_66 ) ;
switch ( V_66 ) {
case V_121 :
V_508 = V_525 ;
break;
case V_180 :
V_508 = V_526 ;
break;
case V_181 :
V_508 = V_527 ;
break;
default:
F_110 ( V_66 ) ;
return false ;
}
return F_30 ( V_528 ) & V_508 ;
}
bool F_320 ( struct V_50 * V_51 ,
struct V_2 * V_66 )
{
if ( F_275 ( V_51 ) )
return F_314 ( V_51 , V_66 ) ;
else if ( F_70 ( V_51 ) )
return F_315 ( V_51 , V_66 ) ;
else if ( F_64 ( V_51 ) )
return F_318 ( V_51 , V_66 ) ;
else if ( F_321 ( V_51 ) )
return F_317 ( V_51 , V_66 ) ;
else
return F_316 ( V_51 , V_66 ) ;
}
static struct V_464 *
F_322 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = V_1 -> V_236 ;
if ( V_25 -> V_464 ) {
if ( F_323 ( V_25 -> V_464 ) )
return NULL ;
return F_324 ( V_25 -> V_464 ) ;
} else
return F_325 ( & V_25 -> V_4 ,
& V_1 -> V_159 . V_500 ) ;
}
static void
F_326 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = V_1 -> V_236 ;
struct V_464 * V_464 ;
F_327 ( V_1 ) ;
V_464 = F_322 ( V_1 ) ;
V_25 -> V_458 = V_464 ;
if ( V_1 -> V_529 != V_530 )
V_1 -> V_246 = V_1 -> V_529 == V_531 ;
else
V_1 -> V_246 = F_328 ( V_464 ) ;
}
static void
F_327 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = V_1 -> V_236 ;
F_126 ( V_25 -> V_458 ) ;
V_25 -> V_458 = NULL ;
V_1 -> V_246 = false ;
}
static void
F_329 ( struct V_25 * V_25 )
{
struct V_8 * V_9 = & V_25 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_496 V_116 ;
enum V_52 V_53 ;
bool V_141 ;
T_1 V_452 ;
V_53 = F_21 ( V_48 ) ;
F_22 ( F_16 ( V_7 ) , V_53 ) ;
if ( F_1 ( V_1 ) )
V_116 = F_312 ( V_1 ) ;
else if ( F_320 ( F_16 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_116 = F_310 ( V_1 ) ;
else
V_116 = V_497 ;
if ( V_116 != V_498 ) {
V_1 -> V_471 = 0 ;
V_1 -> V_477 = 0 ;
V_1 -> V_462 = 0 ;
if ( V_1 -> V_440 ) {
F_33 ( L_99 ,
V_1 -> V_440 ,
V_1 -> V_441 . V_532 ) ;
V_1 -> V_440 = false ;
F_285 ( & V_1 -> V_441 ,
V_1 -> V_440 ) ;
}
goto V_148;
}
if ( V_48 -> type != V_5 )
V_48 -> type = V_533 ;
F_283 ( V_1 ) ;
V_141 = F_284 ( V_1 ) ;
if ( V_141 ) {
V_116 = V_497 ;
goto V_148;
} else if ( V_9 -> V_116 == V_498 ) {
F_308 ( & V_7 -> V_489 . V_490 , NULL ) ;
F_305 ( V_1 ) ;
F_309 ( & V_7 -> V_489 . V_490 ) ;
goto V_148;
}
V_1 -> V_159 . V_461 = 0 ;
V_1 -> V_159 . V_460 = 0 ;
F_326 ( V_1 ) ;
V_116 = V_498 ;
V_1 -> V_534 = true ;
if ( V_1 -> V_11 [ V_315 ] >= 0x11 &&
F_293 ( V_1 , & V_452 ) ) {
F_210 ( & V_1 -> V_159 ,
V_453 ,
V_452 ) ;
if ( V_452 & V_493 )
F_300 ( V_1 ) ;
if ( V_452 & ( V_494 | V_495 ) )
F_241 ( L_97 ) ;
}
V_148:
if ( ( V_116 != V_498 ) &&
( V_1 -> V_440 == false ) )
F_327 ( V_1 ) ;
F_26 ( F_16 ( V_7 ) , V_53 ) ;
return;
}
static enum V_496
F_330 ( struct V_8 * V_9 , bool V_535 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_25 * V_25 = F_15 ( V_9 ) ;
F_33 ( L_100 ,
V_9 -> V_4 . V_536 , V_9 -> V_194 ) ;
if ( V_1 -> V_440 ) {
F_327 ( V_1 ) ;
if ( V_48 -> type != V_5 )
V_48 -> type = V_533 ;
return V_497 ;
}
if ( ! V_1 -> V_534 )
F_329 ( V_1 -> V_236 ) ;
V_1 -> V_534 = false ;
if ( F_1 ( V_1 ) || V_25 -> V_458 )
return V_498 ;
else
return V_497 ;
}
static void
F_331 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_48 * V_48 = & F_2 ( V_1 ) -> V_4 ;
struct V_50 * V_51 = F_16 ( V_48 -> V_4 . V_7 ) ;
enum V_52 V_53 ;
F_33 ( L_100 ,
V_9 -> V_4 . V_536 , V_9 -> V_194 ) ;
F_327 ( V_1 ) ;
if ( V_9 -> V_116 != V_498 )
return;
V_53 = F_21 ( V_48 ) ;
F_22 ( V_51 , V_53 ) ;
F_326 ( V_1 ) ;
F_26 ( V_51 , V_53 ) ;
if ( V_48 -> type != V_5 )
V_48 -> type = V_533 ;
}
static int F_332 ( struct V_8 * V_9 )
{
struct V_25 * V_25 = F_15 ( V_9 ) ;
struct V_464 * V_464 ;
V_464 = V_25 -> V_458 ;
if ( V_464 ) {
int V_141 = F_333 ( V_9 , V_464 ) ;
if ( V_141 )
return V_141 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_25 -> V_27 . V_26 ) {
struct V_23 * V_24 ;
V_24 = F_334 ( V_9 -> V_7 ,
V_25 -> V_27 . V_26 ) ;
if ( V_24 ) {
F_335 ( V_9 , V_24 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_336 ( struct V_8 * V_9 )
{
bool V_246 = false ;
struct V_464 * V_464 ;
V_464 = F_15 ( V_9 ) -> V_458 ;
if ( V_464 )
V_246 = F_328 ( V_464 ) ;
return V_246 ;
}
static int
F_337 ( struct V_8 * V_9 ,
struct V_537 * V_538 ,
T_12 V_402 )
{
struct V_50 * V_51 = F_16 ( V_9 -> V_7 ) ;
struct V_25 * V_25 = F_15 ( V_9 ) ;
struct V_48 * V_48 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_48 -> V_4 ) ;
int V_141 ;
V_141 = F_338 ( & V_9 -> V_4 , V_538 , V_402 ) ;
if ( V_141 )
return V_141 ;
if ( V_538 == V_51 -> V_539 ) {
int V_44 = V_402 ;
bool V_246 ;
if ( V_44 == V_1 -> V_529 )
return 0 ;
V_1 -> V_529 = V_44 ;
if ( V_44 == V_530 )
V_246 = F_336 ( V_9 ) ;
else
V_246 = ( V_44 == V_531 ) ;
if ( V_246 == V_1 -> V_246 )
return 0 ;
V_1 -> V_246 = V_246 ;
goto V_117;
}
if ( V_538 == V_51 -> V_540 ) {
bool V_541 = V_1 -> V_254 ;
bool V_542 = V_1 -> V_255 ;
switch ( V_402 ) {
case V_543 :
V_1 -> V_254 = true ;
break;
case V_544 :
V_1 -> V_254 = false ;
V_1 -> V_255 = false ;
break;
case V_545 :
V_1 -> V_254 = false ;
V_1 -> V_255 = true ;
break;
default:
return - V_179 ;
}
if ( V_541 == V_1 -> V_254 &&
V_542 == V_1 -> V_255 )
return 0 ;
goto V_117;
}
if ( F_1 ( V_1 ) &&
V_538 == V_9 -> V_7 -> V_489 . V_546 ) {
if ( V_402 == V_547 ) {
F_33 ( L_101 ) ;
return - V_179 ;
}
if ( F_153 ( V_51 ) &&
V_402 == V_548 ) {
F_33 ( L_102 ) ;
return - V_179 ;
}
if ( V_25 -> V_27 . V_247 == V_402 ) {
return 0 ;
}
V_25 -> V_27 . V_247 = V_402 ;
goto V_117;
}
return - V_179 ;
V_117:
if ( V_48 -> V_4 . V_235 )
F_339 ( V_48 -> V_4 . V_235 ) ;
return 0 ;
}
static int
F_340 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_141 ;
V_141 = F_341 ( V_9 ) ;
if ( V_141 )
return V_141 ;
F_342 ( V_9 ) ;
F_33 ( L_103 ,
V_1 -> V_159 . V_194 , V_9 -> V_549 -> V_550 . V_194 ) ;
V_1 -> V_159 . V_7 = V_9 -> V_549 ;
return F_343 ( & V_1 -> V_159 ) ;
}
static void
F_344 ( struct V_8 * V_9 )
{
F_345 ( & F_4 ( V_9 ) -> V_159 ) ;
F_346 ( V_9 ) ;
}
static void
F_347 ( struct V_8 * V_9 )
{
struct V_25 * V_25 = F_15 ( V_9 ) ;
F_126 ( V_25 -> V_458 ) ;
if ( ! F_348 ( V_25 -> V_464 ) )
F_126 ( V_25 -> V_464 ) ;
if ( V_9 -> V_551 == V_552 )
F_349 ( & V_25 -> V_27 ) ;
F_350 ( V_9 ) ;
F_126 ( V_9 ) ;
}
void F_351 ( struct V_553 * V_49 )
{
struct V_2 * V_3 = F_352 ( V_49 ) ;
struct V_1 * V_1 = & V_3 -> V_554 ;
F_353 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_354 ( & V_1 -> V_298 ) ;
F_20 ( V_1 ) ;
F_180 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_1 -> V_105 . V_555 ) {
F_355 ( & V_1 -> V_105 ) ;
V_1 -> V_105 . V_555 = NULL ;
}
}
F_125 ( V_1 ) ;
F_356 ( V_49 ) ;
F_126 ( V_3 ) ;
}
void F_357 ( struct V_48 * V_48 )
{
struct V_1 * V_1 = F_5 ( & V_48 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_354 ( & V_1 -> V_298 ) ;
F_20 ( V_1 ) ;
F_180 ( V_1 ) ;
F_24 ( V_1 ) ;
}
static void F_358 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
F_45 ( & V_51 -> V_54 ) ;
if ( ! F_80 ( V_1 ) )
return;
F_33 ( L_104 ) ;
V_53 = F_21 ( & V_3 -> V_4 ) ;
F_22 ( V_51 , V_53 ) ;
F_183 ( V_1 ) ;
}
void F_359 ( struct V_553 * V_49 )
{
struct V_50 * V_51 = F_16 ( V_49 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_49 ) ;
if ( ! F_150 ( V_51 ) )
V_1 -> V_63 = F_30 ( V_1 -> V_64 ) ;
if ( F_360 ( V_49 ) -> type != V_5 )
return;
F_20 ( V_1 ) ;
if ( F_63 ( V_49 -> V_7 ) || F_35 ( V_49 -> V_7 ) )
F_61 ( V_1 ) ;
F_358 ( V_1 ) ;
F_24 ( V_1 ) ;
}
enum V_556
F_361 ( struct V_2 * V_3 , bool V_557 )
{
struct V_1 * V_1 = & V_3 -> V_554 ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_52 V_53 ;
enum V_556 V_141 = V_558 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_559 )
V_3 -> V_4 . type = V_533 ;
if ( V_557 && V_3 -> V_4 . type == V_5 ) {
F_33 ( L_105 ,
F_32 ( V_3 -> V_66 ) ) ;
return V_560 ;
}
F_33 ( L_106 ,
F_32 ( V_3 -> V_66 ) ,
V_557 ? L_107 : L_108 ) ;
V_53 = F_21 ( V_48 ) ;
F_22 ( V_51 , V_53 ) ;
if ( V_557 ) {
F_329 ( V_1 -> V_236 ) ;
if ( V_1 -> V_440 )
V_141 = V_560 ;
goto V_561;
} else {
if ( V_1 -> V_440 ) {
if ( F_301 ( V_1 ) == - V_179 ) {
F_33 ( L_99 ,
V_1 -> V_440 , V_1 -> V_441 . V_532 ) ;
V_1 -> V_440 = false ;
F_285 ( & V_1 -> V_441 ,
V_1 -> V_440 ) ;
goto V_561;
}
}
if ( ! V_1 -> V_440 ) {
if ( ! F_307 ( V_1 ) ) {
F_329 ( V_1 -> V_236 ) ;
goto V_561;
}
}
}
V_141 = V_560 ;
V_561:
F_26 ( V_51 , V_53 ) ;
return V_141 ;
}
bool F_362 ( struct V_6 * V_7 , enum V_66 V_66 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
if ( F_121 ( V_7 ) -> V_193 < 5 )
return false ;
if ( V_66 == V_121 )
return true ;
return F_363 ( V_51 , V_66 ) ;
}
void
F_364 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_25 * V_25 = F_15 ( V_9 ) ;
F_365 ( V_9 ) ;
F_366 ( V_9 ) ;
V_1 -> V_254 = true ;
if ( F_1 ( V_1 ) ) {
F_367 ( V_9 -> V_7 ) ;
F_368 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_489 . V_546 ,
V_562 ) ;
V_25 -> V_27 . V_247 = V_562 ;
}
}
static void F_369 ( struct V_1 * V_1 )
{
V_1 -> V_285 = F_171 () ;
V_1 -> V_289 = V_286 ;
V_1 -> V_291 = V_286 ;
}
static void
F_370 ( struct V_50 * V_51 ,
struct V_1 * V_1 , struct V_563 * V_564 )
{
T_5 V_93 , V_94 , V_99 = 0 , V_565 = 0 ;
struct V_88 V_89 ;
F_65 ( V_51 , V_1 , & V_89 ) ;
V_565 = F_176 ( V_1 ) ;
V_93 = F_30 ( V_89 . V_93 ) ;
V_94 = F_30 ( V_89 . V_94 ) ;
if ( ! F_64 ( V_51 ) ) {
F_41 ( V_89 . V_91 , V_565 ) ;
V_99 = F_30 ( V_89 . V_99 ) ;
}
V_564 -> V_566 = ( V_93 & V_567 ) >>
V_568 ;
V_564 -> V_569 = ( V_93 & V_570 ) >>
V_571 ;
V_564 -> V_572 = ( V_94 & V_573 ) >>
V_574 ;
V_564 -> V_575 = ( V_94 & V_576 ) >>
V_577 ;
if ( F_64 ( V_51 ) ) {
T_13 V_80 = ( V_565 & V_578 ) >>
V_579 ;
if ( V_80 > 0 )
V_564 -> V_580 = ( V_80 - 1 ) * 1000 ;
else
V_564 -> V_580 = 0 ;
} else {
V_564 -> V_580 = ( ( V_99 & V_581 ) >>
V_582 ) * 1000 ;
}
}
static void
F_371 ( const char * V_583 , const struct V_563 * V_564 )
{
F_33 ( L_109 ,
V_583 ,
V_564 -> V_566 , V_564 -> V_569 , V_564 -> V_572 , V_564 -> V_575 , V_564 -> V_580 ) ;
}
static void
F_166 ( struct V_50 * V_51 ,
struct V_1 * V_1 )
{
struct V_563 V_584 ;
struct V_563 * V_585 = & V_1 -> V_586 ;
F_370 ( V_51 , V_1 , & V_584 ) ;
if ( V_584 . V_566 != V_585 -> V_566 || V_584 . V_569 != V_585 -> V_569 || V_584 . V_572 != V_585 -> V_572 ||
V_584 . V_575 != V_585 -> V_575 || V_584 . V_580 != V_585 -> V_580 ) {
F_40 ( L_110 ) ;
F_371 ( L_111 , V_585 ) ;
F_371 ( L_112 , & V_584 ) ;
}
}
static void
F_50 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_563 V_587 , V_185 , V_588 ,
* V_589 = & V_1 -> V_586 ;
F_45 ( & V_51 -> V_54 ) ;
if ( V_589 -> V_580 != 0 )
return;
F_370 ( V_51 , V_1 , & V_587 ) ;
F_371 ( L_113 , & V_587 ) ;
V_185 = V_51 -> V_185 . V_252 . V_590 ;
V_588 . V_566 = 210 * 10 ;
V_588 . V_569 = 50 * 10 ;
V_588 . V_572 = 50 * 10 ;
V_588 . V_575 = 500 * 10 ;
V_588 . V_580 = ( 510 + 100 ) * 10 ;
F_371 ( L_114 , & V_185 ) ;
#define F_372 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_372 ( V_566 ) ;
F_372 ( V_569 ) ;
F_372 ( V_572 ) ;
F_372 ( V_575 ) ;
F_372 ( V_580 ) ;
#undef F_372
#define F_373 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_299 = F_373 ( V_566 ) ;
V_1 -> V_290 = F_373 ( V_569 ) ;
V_1 -> V_292 = F_373 ( V_572 ) ;
V_1 -> V_407 = F_373 ( V_575 ) ;
V_1 -> V_112 = F_373 ( V_580 ) ;
#undef F_373
F_33 ( L_115 ,
V_1 -> V_299 , V_1 -> V_407 ,
V_1 -> V_112 ) ;
F_33 ( L_116 ,
V_1 -> V_290 , V_1 -> V_292 ) ;
V_589 -> V_569 = 1 ;
V_589 -> V_572 = 1 ;
}
static void
F_51 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
T_5 V_93 , V_94 , V_99 , V_85 = 0 ;
int div = V_51 -> V_120 / 1000 ;
struct V_88 V_89 ;
enum V_66 V_66 = F_2 ( V_1 ) -> V_66 ;
const struct V_563 * V_564 = & V_1 -> V_586 ;
F_45 ( & V_51 -> V_54 ) ;
F_65 ( V_51 , V_1 , & V_89 ) ;
V_93 = ( V_564 -> V_566 << V_568 ) |
( V_564 -> V_569 << V_571 ) ;
V_94 = ( V_564 -> V_572 << V_574 ) |
( V_564 -> V_575 << V_577 ) ;
if ( F_64 ( V_7 ) ) {
V_99 = F_30 ( V_89 . V_91 ) ;
V_99 &= ~ V_578 ;
V_99 |= ( F_374 ( ( V_564 -> V_580 + 1 ) , 1000 )
<< V_579 ) ;
} else {
V_99 = ( ( 100 * div ) / 2 - 1 ) << V_591 ;
V_99 |= ( F_374 ( V_564 -> V_580 , 1000 )
<< V_582 ) ;
}
if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
V_85 = F_60 ( V_66 ) ;
} else if ( F_275 ( V_7 ) || F_163 ( V_7 ) ) {
if ( V_66 == V_121 )
V_85 = V_592 ;
else
V_85 = V_593 ;
}
V_93 |= V_85 ;
F_41 ( V_89 . V_93 , V_93 ) ;
F_41 ( V_89 . V_94 , V_94 ) ;
if ( F_64 ( V_7 ) )
F_41 ( V_89 . V_91 , V_99 ) ;
else
F_41 ( V_89 . V_99 , V_99 ) ;
F_33 ( L_117 ,
F_30 ( V_89 . V_93 ) ,
F_30 ( V_89 . V_94 ) ,
F_64 ( V_7 ) ?
( F_30 ( V_89 . V_91 ) & V_578 ) :
F_30 ( V_89 . V_99 ) ) ;
}
static void F_375 ( struct V_6 * V_7 , int V_594 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_48 * V_49 ;
struct V_2 * V_200 = NULL ;
struct V_1 * V_1 = V_51 -> V_258 . V_554 ;
struct V_205 * V_265 = NULL ;
struct V_234 * V_234 = NULL ;
enum V_595 V_119 = V_596 ;
if ( V_594 <= 0 ) {
F_33 ( L_118 ) ;
return;
}
if ( V_1 == NULL ) {
F_33 ( L_119 ) ;
return;
}
V_200 = F_2 ( V_1 ) ;
V_49 = & V_200 -> V_4 ;
V_234 = F_149 ( V_49 -> V_4 . V_235 ) ;
if ( ! V_234 ) {
F_33 ( L_120 ) ;
return;
}
V_265 = V_234 -> V_265 ;
if ( V_51 -> V_258 . type < V_259 ) {
F_33 ( L_121 ) ;
return;
}
if ( V_1 -> V_236 -> V_27 . V_257 -> V_597 ==
V_594 )
V_119 = V_598 ;
if ( V_119 == V_51 -> V_258 . V_599 ) {
F_33 (
L_122 ) ;
return;
}
if ( ! V_234 -> V_491 ) {
F_33 ( L_123 ) ;
return;
}
if ( F_121 ( V_7 ) -> V_193 >= 8 && ! F_35 ( V_7 ) ) {
switch ( V_119 ) {
case V_596 :
F_376 ( V_234 , V_600 ) ;
break;
case V_598 :
F_376 ( V_234 , V_601 ) ;
break;
case V_602 :
default:
F_40 ( L_124 ) ;
}
} else if ( F_121 ( V_7 ) -> V_193 > 6 ) {
T_6 V_603 = F_377 ( V_234 -> V_265 -> V_604 ) ;
T_5 V_402 ;
V_402 = F_30 ( V_603 ) ;
if ( V_119 > V_596 ) {
if ( F_63 ( V_7 ) || F_35 ( V_7 ) )
V_402 |= V_605 ;
else
V_402 |= V_606 ;
} else {
if ( F_63 ( V_7 ) || F_35 ( V_7 ) )
V_402 &= ~ V_605 ;
else
V_402 &= ~ V_606 ;
}
F_41 ( V_603 , V_402 ) ;
}
V_51 -> V_258 . V_599 = V_119 ;
F_33 ( L_125 , V_594 ) ;
}
void F_378 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_607 * V_235 = V_200 -> V_4 . V_4 . V_235 ;
struct V_234 * V_234 = F_149 ( V_235 ) ;
if ( ! V_234 -> V_265 -> V_245 ) {
F_33 ( L_126 ) ;
return;
}
F_23 ( & V_51 -> V_258 . V_608 ) ;
if ( F_46 ( V_51 -> V_258 . V_554 ) ) {
F_40 ( L_127 ) ;
goto V_609;
}
V_51 -> V_258 . V_610 = 0 ;
V_51 -> V_258 . V_554 = V_1 ;
V_609:
F_25 ( & V_51 -> V_258 . V_608 ) ;
}
void F_379 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_2 * V_200 = F_2 ( V_1 ) ;
struct V_607 * V_235 = V_200 -> V_4 . V_4 . V_235 ;
struct V_234 * V_234 = F_149 ( V_235 ) ;
if ( ! V_234 -> V_265 -> V_245 )
return;
F_23 ( & V_51 -> V_258 . V_608 ) ;
if ( ! V_51 -> V_258 . V_554 ) {
F_25 ( & V_51 -> V_258 . V_608 ) ;
return;
}
if ( V_51 -> V_258 . V_599 == V_598 )
F_375 ( & V_51 -> V_87 ,
V_1 -> V_236 -> V_27 .
V_26 -> V_597 ) ;
V_51 -> V_258 . V_554 = NULL ;
F_25 ( & V_51 -> V_258 . V_608 ) ;
F_354 ( & V_51 -> V_258 . V_611 ) ;
}
static void F_380 ( struct V_301 * V_611 )
{
struct V_50 * V_51 =
F_76 ( V_611 , F_77 ( * V_51 ) , V_258 . V_611 . V_611 ) ;
struct V_1 * V_1 ;
F_23 ( & V_51 -> V_258 . V_608 ) ;
V_1 = V_51 -> V_258 . V_554 ;
if ( ! V_1 )
goto V_609;
if ( V_51 -> V_258 . V_610 )
goto V_609;
if ( V_51 -> V_258 . V_599 != V_598 )
F_375 ( & V_51 -> V_87 ,
V_1 -> V_236 -> V_27 .
V_257 -> V_597 ) ;
V_609:
F_25 ( & V_51 -> V_258 . V_608 ) ;
}
void F_381 ( struct V_6 * V_7 ,
unsigned V_612 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_607 * V_235 ;
enum V_55 V_55 ;
if ( V_51 -> V_258 . type == V_613 )
return;
F_177 ( & V_51 -> V_258 . V_611 ) ;
F_23 ( & V_51 -> V_258 . V_608 ) ;
if ( ! V_51 -> V_258 . V_554 ) {
F_25 ( & V_51 -> V_258 . V_608 ) ;
return;
}
V_235 = F_2 ( V_51 -> V_258 . V_554 ) -> V_4 . V_4 . V_235 ;
V_55 = F_149 ( V_235 ) -> V_55 ;
V_612 &= F_382 ( V_55 ) ;
V_51 -> V_258 . V_610 |= V_612 ;
if ( V_612 && V_51 -> V_258 . V_599 == V_598 )
F_375 ( & V_51 -> V_87 ,
V_51 -> V_258 . V_554 -> V_236 -> V_27 .
V_26 -> V_597 ) ;
F_25 ( & V_51 -> V_258 . V_608 ) ;
}
void F_383 ( struct V_6 * V_7 ,
unsigned V_612 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_607 * V_235 ;
enum V_55 V_55 ;
if ( V_51 -> V_258 . type == V_613 )
return;
F_177 ( & V_51 -> V_258 . V_611 ) ;
F_23 ( & V_51 -> V_258 . V_608 ) ;
if ( ! V_51 -> V_258 . V_554 ) {
F_25 ( & V_51 -> V_258 . V_608 ) ;
return;
}
V_235 = F_2 ( V_51 -> V_258 . V_554 ) -> V_4 . V_4 . V_235 ;
V_55 = F_149 ( V_235 ) -> V_55 ;
V_612 &= F_382 ( V_55 ) ;
V_51 -> V_258 . V_610 &= ~ V_612 ;
if ( V_612 && V_51 -> V_258 . V_599 == V_598 )
F_375 ( & V_51 -> V_87 ,
V_51 -> V_258 . V_554 -> V_236 -> V_27 .
V_26 -> V_597 ) ;
if ( ! V_51 -> V_258 . V_610 )
F_185 ( & V_51 -> V_258 . V_611 ,
F_184 ( 1000 ) ) ;
F_25 ( & V_51 -> V_258 . V_608 ) ;
}
static struct V_23 *
F_384 ( struct V_25 * V_25 ,
struct V_23 * V_26 )
{
struct V_8 * V_9 = & V_25 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_23 * V_257 = NULL ;
F_385 ( & V_51 -> V_258 . V_611 , F_380 ) ;
F_386 ( & V_51 -> V_258 . V_608 ) ;
if ( F_121 ( V_7 ) -> V_193 <= 6 ) {
F_33 ( L_128 ) ;
return NULL ;
}
if ( V_51 -> V_185 . V_614 != V_259 ) {
F_33 ( L_129 ) ;
return NULL ;
}
V_257 = F_387
( V_7 , V_26 , V_9 ) ;
if ( ! V_257 ) {
F_33 ( L_130 ) ;
return NULL ;
}
V_51 -> V_258 . type = V_51 -> V_185 . V_614 ;
V_51 -> V_258 . V_599 = V_596 ;
F_33 ( L_131 ) ;
return V_257 ;
}
static bool F_388 ( struct V_1 * V_1 ,
struct V_25 * V_25 )
{
struct V_8 * V_9 = & V_25 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_48 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_23 * V_26 = NULL ;
struct V_23 * V_257 = NULL ;
bool V_615 ;
struct V_23 * V_616 ;
struct V_464 * V_464 ;
enum V_55 V_55 = V_79 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_389 ( V_7 ) ) {
F_46 ( ! ( F_275 ( V_51 ) || F_163 ( V_51 ) ) ) ;
F_390 ( L_132 ) ;
return false ;
}
F_20 ( V_1 ) ;
F_369 ( V_1 ) ;
if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
F_61 ( V_1 ) ;
} else {
F_50 ( V_7 , V_1 ) ;
F_51 ( V_7 , V_1 ) ;
}
F_358 ( V_1 ) ;
F_24 ( V_1 ) ;
V_615 = F_278 ( V_1 ) ;
if ( V_615 ) {
if ( V_1 -> V_11 [ V_315 ] >= 0x11 )
V_51 -> V_617 =
V_1 -> V_11 [ V_618 ] &
V_619 ;
} else {
F_390 ( L_133 ) ;
goto V_620;
}
F_23 ( & V_7 -> V_489 . V_608 ) ;
V_464 = F_325 ( V_9 , & V_1 -> V_159 . V_500 ) ;
if ( V_464 ) {
if ( F_391 ( V_9 , V_464 ) ) {
F_392 ( V_9 ,
V_464 ) ;
F_393 ( V_9 , V_464 ) ;
} else {
F_126 ( V_464 ) ;
V_464 = F_394 ( - V_179 ) ;
}
} else {
V_464 = F_394 ( - V_621 ) ;
}
V_25 -> V_464 = V_464 ;
F_395 (scan, &connector->probed_modes, head) {
if ( ( V_616 -> type & V_622 ) ) {
V_26 = F_334 ( V_7 , V_616 ) ;
V_257 = F_384 (
V_25 , V_26 ) ;
break;
}
}
if ( ! V_26 && V_51 -> V_185 . V_623 ) {
V_26 = F_334 ( V_7 ,
V_51 -> V_185 . V_623 ) ;
if ( V_26 ) {
V_26 -> type |= V_622 ;
V_9 -> V_250 . V_624 = V_26 -> V_624 ;
V_9 -> V_250 . V_625 = V_26 -> V_625 ;
}
}
F_25 ( & V_7 -> V_489 . V_608 ) ;
if ( F_63 ( V_7 ) || F_35 ( V_7 ) ) {
V_1 -> V_105 . V_555 = F_75 ;
F_396 ( & V_1 -> V_105 ) ;
if ( F_35 ( V_7 ) )
V_55 = F_218 ( V_1 -> V_63 ) ;
else
V_55 = F_219 ( V_1 -> V_63 ) ;
if ( V_55 != V_78 && V_55 != V_71 )
V_55 = V_1 -> V_56 ;
if ( V_55 != V_78 && V_55 != V_71 )
V_55 = V_78 ;
F_33 ( L_134 ,
F_31 ( V_55 ) ) ;
}
F_397 ( & V_25 -> V_27 , V_26 , V_257 ) ;
V_25 -> V_27 . V_626 . V_627 = F_197 ;
F_398 ( V_9 , V_55 ) ;
return true ;
V_620:
F_354 ( & V_1 -> V_298 ) ;
F_20 ( V_1 ) ;
F_180 ( V_1 ) ;
F_24 ( V_1 ) ;
return false ;
}
bool
F_399 ( struct V_2 * V_3 ,
struct V_25 * V_25 )
{
struct V_8 * V_9 = & V_25 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_554 ;
struct V_48 * V_48 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_48 -> V_4 . V_7 ;
struct V_50 * V_51 = F_16 ( V_7 ) ;
enum V_66 V_66 = V_3 -> V_66 ;
int type ;
if ( F_8 ( V_3 -> V_18 < 1 ,
L_135 ,
V_3 -> V_18 , F_32 ( V_66 ) ) )
return false ;
V_1 -> V_56 = V_79 ;
if ( F_121 ( V_7 ) -> V_193 >= 9 )
V_1 -> V_150 = F_92 ;
else if ( F_133 ( V_7 ) || F_95 ( V_7 ) )
V_1 -> V_150 = F_90 ;
else if ( F_70 ( V_7 ) )
V_1 -> V_150 = F_89 ;
else
V_1 -> V_150 = F_87 ;
if ( F_121 ( V_7 ) -> V_193 >= 9 )
V_1 -> V_152 = F_96 ;
else
V_1 -> V_152 = F_93 ;
if ( F_150 ( V_7 ) )
V_1 -> V_628 = V_629 ;
V_1 -> V_63 = F_30 ( V_1 -> V_64 ) ;
V_1 -> V_236 = V_25 ;
if ( F_362 ( V_7 , V_66 ) )
type = V_552 ;
else
type = V_630 ;
if ( type == V_552 )
V_48 -> type = V_5 ;
if ( F_46 ( ( F_63 ( V_7 ) || F_35 ( V_7 ) ) &&
F_1 ( V_1 ) && V_66 != V_180 && V_66 != V_181 ) )
return false ;
F_33 ( L_136 ,
type == V_552 ? L_137 : L_138 ,
F_32 ( V_66 ) ) ;
F_400 ( V_7 , V_9 , & V_631 , type ) ;
F_401 ( V_9 , & V_632 ) ;
V_9 -> V_633 = true ;
V_9 -> V_634 = 0 ;
F_127 ( V_1 , V_25 ) ;
F_385 ( & V_1 -> V_298 ,
F_181 ) ;
F_402 ( V_25 , V_48 ) ;
if ( F_150 ( V_7 ) )
V_25 -> V_635 = V_636 ;
else
V_25 -> V_635 = V_637 ;
switch ( V_66 ) {
case V_121 :
V_48 -> V_524 = V_638 ;
break;
case V_180 :
V_48 -> V_524 = V_639 ;
if ( F_403 ( V_7 , 0 , V_640 ) )
V_48 -> V_524 = V_638 ;
break;
case V_181 :
V_48 -> V_524 = V_641 ;
break;
case V_182 :
V_48 -> V_524 = V_642 ;
break;
case V_187 :
V_48 -> V_524 = V_643 ;
break;
default:
F_404 () ;
}
if ( F_405 ( V_7 ) && ! F_1 ( V_1 ) &&
( V_66 == V_180 || V_66 == V_181 || V_66 == V_182 ) )
F_406 ( V_3 ,
V_25 -> V_4 . V_4 . V_536 ) ;
if ( ! F_388 ( V_1 , V_25 ) ) {
F_125 ( V_1 ) ;
F_353 ( V_3 ) ;
goto V_644;
}
F_364 ( V_1 , V_9 ) ;
if ( F_139 ( V_7 ) && ! F_321 ( V_7 ) ) {
T_5 V_331 = F_30 ( V_645 ) ;
F_41 ( V_645 , ( V_331 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_644:
F_350 ( V_9 ) ;
return false ;
}
bool F_407 ( struct V_6 * V_7 ,
T_6 V_64 ,
enum V_66 V_66 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
struct V_2 * V_3 ;
struct V_48 * V_48 ;
struct V_553 * V_49 ;
struct V_25 * V_25 ;
V_3 = F_408 ( sizeof( * V_3 ) , V_195 ) ;
if ( ! V_3 )
return false ;
V_25 = F_409 () ;
if ( ! V_25 )
goto V_646;
V_48 = & V_3 -> V_4 ;
V_49 = & V_48 -> V_4 ;
if ( F_410 ( V_7 , & V_48 -> V_4 , & V_647 ,
V_648 , L_139 , F_32 ( V_66 ) ) )
goto V_649;
V_48 -> V_650 = F_148 ;
V_48 -> V_651 = F_223 ;
V_48 -> V_635 = F_211 ;
V_48 -> V_652 = F_220 ;
V_48 -> V_653 = F_357 ;
if ( F_35 ( V_7 ) ) {
V_48 -> V_654 = F_255 ;
V_48 -> V_655 = F_252 ;
V_48 -> V_307 = F_244 ;
V_48 -> V_656 = F_230 ;
V_48 -> V_657 = F_257 ;
} else if ( F_63 ( V_7 ) ) {
V_48 -> V_654 = F_250 ;
V_48 -> V_655 = F_248 ;
V_48 -> V_307 = F_244 ;
V_48 -> V_656 = F_229 ;
} else {
V_48 -> V_655 = F_246 ;
V_48 -> V_307 = F_243 ;
if ( F_121 ( V_7 ) -> V_193 >= 5 )
V_48 -> V_656 = F_228 ;
}
V_3 -> V_66 = V_66 ;
V_3 -> V_554 . V_64 = V_64 ;
V_3 -> V_18 = 4 ;
V_48 -> type = V_533 ;
if ( F_35 ( V_7 ) ) {
if ( V_66 == V_182 )
V_48 -> V_658 = 1 << 2 ;
else
V_48 -> V_658 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_48 -> V_658 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_48 -> V_659 = 0 ;
V_3 -> V_660 = F_361 ;
V_51 -> V_661 . V_662 [ V_66 ] = V_3 ;
if ( ! F_399 ( V_3 , V_25 ) )
goto V_663;
return true ;
V_663:
F_356 ( V_49 ) ;
V_649:
F_126 ( V_25 ) ;
V_646:
F_126 ( V_3 ) ;
return false ;
}
void F_411 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_664 ; V_44 ++ ) {
struct V_2 * V_3 = V_51 -> V_661 . V_662 [ V_44 ] ;
if ( ! V_3 || ! V_3 -> V_554 . V_437 )
continue;
if ( V_3 -> V_554 . V_440 )
F_412 ( & V_3 -> V_554 . V_441 ) ;
}
}
void F_413 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = F_16 ( V_7 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_664 ; V_44 ++ ) {
struct V_2 * V_3 = V_51 -> V_661 . V_662 [ V_44 ] ;
int V_141 ;
if ( ! V_3 || ! V_3 -> V_554 . V_437 )
continue;
V_141 = F_414 ( & V_3 -> V_554 . V_441 ) ;
if ( V_141 )
F_301 ( & V_3 -> V_554 ) ;
}
}
