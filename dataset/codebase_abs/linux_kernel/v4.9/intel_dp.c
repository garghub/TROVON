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
static int
F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_24 * V_25 = F_15 ( V_23 -> V_4 . V_7 ) ;
int V_26 = V_25 -> V_27 ;
int V_28 ;
int type = V_1 -> V_29 [ 0 ] & V_30 ;
if ( type != V_31 )
return V_26 ;
V_28 = F_16 ( V_1 -> V_11 ,
V_1 -> V_29 ) ;
if ( V_28 != 0 )
V_26 = F_11 ( V_26 , V_28 ) ;
return V_26 ;
}
static enum V_32
F_17 ( struct V_8 * V_9 ,
struct V_33 * V_34 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_35 * V_35 = F_18 ( V_9 ) ;
struct V_33 * V_36 = V_35 -> V_37 . V_36 ;
int V_38 = V_34 -> clock ;
int V_39 , V_40 , V_18 , V_21 ;
int V_26 ;
V_26 = F_14 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_36 ) {
if ( V_34 -> V_41 > V_36 -> V_41 )
return V_42 ;
if ( V_34 -> V_43 > V_36 -> V_43 )
return V_42 ;
V_38 = V_36 -> clock ;
}
V_21 = F_19 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
V_39 = F_13 ( V_21 , V_18 ) ;
V_40 = F_12 ( V_38 , 18 ) ;
if ( V_40 > V_39 || V_38 > V_26 )
return V_44 ;
if ( V_34 -> clock < 10000 )
return V_45 ;
if ( V_34 -> V_46 & V_47 )
return V_48 ;
return V_49 ;
}
T_2 F_20 ( const T_3 * V_50 , int V_51 )
{
int V_52 ;
T_2 V_53 = 0 ;
if ( V_51 > 4 )
V_51 = 4 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
V_53 |= ( ( T_2 ) V_50 [ V_52 ] ) << ( ( 3 - V_52 ) * 8 ) ;
return V_53 ;
}
static void F_21 ( T_2 V_50 , T_3 * V_54 , int V_55 )
{
int V_52 ;
if ( V_55 > 4 )
V_55 = 4 ;
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ )
V_54 [ V_52 ] = V_50 >> ( ( 3 - V_52 ) * 8 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
V_57 = F_23 ( V_23 ) ;
F_24 ( V_25 , V_57 ) ;
F_25 ( & V_25 -> V_58 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
F_27 ( & V_25 -> V_58 ) ;
V_57 = F_23 ( V_23 ) ;
F_28 ( V_25 , V_57 ) ;
}
static void
F_29 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_59 V_59 = V_1 -> V_60 ;
bool V_61 , V_62 = false ;
enum V_63 V_64 = F_30 ( V_59 ) ;
enum V_65 V_66 = F_31 ( V_59 ) ;
T_2 V_67 ;
if ( F_8 ( F_32 ( V_1 -> V_68 ) & V_69 ,
L_2 ,
F_33 ( V_59 ) , F_34 ( V_3 -> V_70 ) ) )
return;
F_35 ( L_3 ,
F_33 ( V_59 ) , F_34 ( V_3 -> V_70 ) ) ;
V_67 = F_32 ( V_1 -> V_68 ) & V_71 ;
V_67 |= V_72 | V_73 ;
V_67 |= F_36 ( 1 ) ;
V_67 |= V_74 ;
if ( F_37 ( V_7 ) )
V_67 |= F_38 ( V_59 ) ;
else if ( V_59 == V_75 )
V_67 |= V_76 ;
V_61 = F_32 ( F_39 ( V_59 ) ) & V_77 ;
if ( ! V_61 ) {
V_62 = F_37 ( V_7 ) &&
! F_40 ( V_25 , V_64 , V_66 , true ) ;
if ( F_41 ( V_7 , V_59 , F_37 ( V_7 ) ?
& V_78 [ 0 ] . V_79 : & V_80 [ 0 ] . V_79 ) ) {
F_42 ( L_4 ,
F_33 ( V_59 ) ) ;
return;
}
}
F_43 ( V_1 -> V_68 , V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
F_43 ( V_1 -> V_68 , V_67 | V_69 ) ;
F_44 ( V_1 -> V_68 ) ;
F_43 ( V_1 -> V_68 , V_67 & ~ V_69 ) ;
F_44 ( V_1 -> V_68 ) ;
if ( ! V_61 ) {
F_45 ( V_7 , V_59 ) ;
if ( V_62 )
F_40 ( V_25 , V_64 , V_66 , false ) ;
}
}
static enum V_59
F_46 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_22 * V_23 ;
unsigned int V_81 = ( 1 << V_82 ) | ( 1 << V_75 ) ;
enum V_59 V_59 ;
F_47 ( & V_25 -> V_58 ) ;
F_48 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_60 != V_83 )
return V_1 -> V_60 ;
F_49 (dev, encoder) {
struct V_1 * V_84 ;
if ( V_23 -> type != V_5 )
continue;
V_84 = F_5 ( & V_23 -> V_4 ) ;
if ( V_84 -> V_60 != V_83 )
V_81 &= ~ ( 1 << V_84 -> V_60 ) ;
}
if ( F_48 ( V_81 == 0 ) )
V_59 = V_82 ;
else
V_59 = F_50 ( V_81 ) - 1 ;
F_51 ( V_7 , V_59 ) ;
V_1 -> V_60 = V_59 ;
F_35 ( L_5 ,
F_33 ( V_1 -> V_60 ) ,
F_34 ( V_3 -> V_70 ) ) ;
F_52 ( V_7 , V_1 ) ;
F_53 ( V_7 , V_1 ) ;
F_29 ( V_1 ) ;
return V_1 -> V_60 ;
}
static int
F_54 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_47 ( & V_25 -> V_58 ) ;
F_48 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_85 )
return 0 ;
V_1 -> V_85 = false ;
F_53 ( V_7 , V_1 ) ;
return 0 ;
}
static bool F_55 ( struct V_24 * V_25 ,
enum V_59 V_59 )
{
return F_32 ( F_56 ( V_59 ) ) & V_86 ;
}
static bool F_57 ( struct V_24 * V_25 ,
enum V_59 V_59 )
{
return F_32 ( F_58 ( V_59 ) ) & V_87 ;
}
static bool F_59 ( struct V_24 * V_25 ,
enum V_59 V_59 )
{
return true ;
}
static enum V_59
F_60 ( struct V_24 * V_25 ,
enum V_70 V_70 ,
T_4 V_88 )
{
enum V_59 V_59 ;
for ( V_59 = V_82 ; V_59 <= V_75 ; V_59 ++ ) {
T_5 V_89 = F_32 ( F_61 ( V_59 ) ) &
V_90 ;
if ( V_89 != F_62 ( V_70 ) )
continue;
if ( ! V_88 ( V_25 , V_59 ) )
continue;
return V_59 ;
}
return V_83 ;
}
static void
F_63 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
F_47 ( & V_25 -> V_58 ) ;
V_1 -> V_60 = F_60 ( V_25 , V_70 ,
F_55 ) ;
if ( V_1 -> V_60 == V_83 )
V_1 -> V_60 = F_60 ( V_25 , V_70 ,
F_57 ) ;
if ( V_1 -> V_60 == V_83 )
V_1 -> V_60 = F_60 ( V_25 , V_70 ,
F_59 ) ;
if ( V_1 -> V_60 == V_83 ) {
F_35 ( L_6 ,
F_34 ( V_70 ) ) ;
return;
}
F_35 ( L_7 ,
F_34 ( V_70 ) , F_33 ( V_1 -> V_60 ) ) ;
F_52 ( V_7 , V_1 ) ;
F_53 ( V_7 , V_1 ) ;
}
void F_64 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = & V_25 -> V_91 ;
struct V_22 * V_23 ;
if ( F_48 ( ! F_65 ( V_7 ) && ! F_37 ( V_7 ) &&
! F_66 ( V_7 ) ) )
return;
F_49 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_23 -> type != V_5 )
continue;
V_1 = F_5 ( & V_23 -> V_4 ) ;
if ( F_66 ( V_7 ) )
V_1 -> V_85 = true ;
else
V_1 -> V_60 = V_83 ;
}
}
static void F_67 ( struct V_24 * V_25 ,
struct V_1 * V_1 ,
struct V_92 * V_93 )
{
int V_94 = 0 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
if ( F_66 ( V_25 ) )
V_94 = F_54 ( V_1 ) ;
else if ( F_65 ( V_25 ) || F_37 ( V_25 ) )
V_94 = F_46 ( V_1 ) ;
V_93 -> V_95 = F_58 ( V_94 ) ;
V_93 -> V_96 = F_56 ( V_94 ) ;
V_93 -> V_97 = F_61 ( V_94 ) ;
V_93 -> V_98 = F_68 ( V_94 ) ;
if ( ! F_66 ( V_25 ) )
V_93 -> V_99 = F_69 ( V_94 ) ;
}
static T_6
F_70 ( struct V_1 * V_1 )
{
struct V_92 V_93 ;
F_67 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_93 ) ;
return V_93 . V_95 ;
}
static T_6
F_71 ( struct V_1 * V_1 )
{
struct V_92 V_93 ;
F_67 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_93 ) ;
return V_93 . V_96 ;
}
static int F_72 ( struct V_100 * V_101 , unsigned long V_102 ,
void * V_103 )
{
struct V_1 * V_1 = F_73 ( V_101 , F_74 ( * V_1 ) ,
V_104 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_102 != V_105 )
return 0 ;
F_22 ( V_1 ) ;
if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
enum V_59 V_59 = F_46 ( V_1 ) ;
T_6 V_106 , V_107 ;
T_5 V_99 ;
V_106 = F_58 ( V_59 ) ;
V_107 = F_69 ( V_59 ) ;
V_99 = F_32 ( V_107 ) ;
V_99 &= V_108 ;
F_43 ( V_107 , V_99 | 0x1F ) ;
F_43 ( V_106 , V_109 | V_110 ) ;
F_75 ( V_1 -> V_111 ) ;
}
F_26 ( V_1 ) ;
return 0 ;
}
static bool F_76 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_47 ( & V_25 -> V_58 ) ;
if ( ( F_65 ( V_7 ) || F_37 ( V_7 ) ) &&
V_1 -> V_60 == V_83 )
return false ;
return ( F_32 ( F_71 ( V_1 ) ) & V_86 ) != 0 ;
}
static bool F_77 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_47 ( & V_25 -> V_58 ) ;
if ( ( F_65 ( V_7 ) || F_37 ( V_7 ) ) &&
V_1 -> V_60 == V_83 )
return false ;
return F_32 ( F_70 ( V_1 ) ) & V_87 ;
}
static void
F_78 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_76 ( V_1 ) && ! F_77 ( V_1 ) ) {
F_8 ( 1 , L_8 ) ;
F_35 ( L_9 ,
F_32 ( F_71 ( V_1 ) ) ,
F_32 ( F_70 ( V_1 ) ) ) ;
}
}
static T_2
F_79 ( struct V_1 * V_1 , bool V_112 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_6 V_113 = V_1 -> V_114 ;
T_2 V_115 ;
bool V_116 ;
#define F_80 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_112 )
V_116 = F_81 ( V_25 -> V_117 , F_80 ,
F_82 ( 10 ) ) ;
else
V_116 = F_83 ( F_80 , 10 ) == 0 ;
if ( ! V_116 )
F_42 ( L_10 ,
V_112 ) ;
#undef F_80
return V_115 ;
}
static T_2 F_84 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_118 )
return 0 ;
return F_85 ( V_25 -> V_119 , 2000 ) ;
}
static T_2 F_86 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_118 )
return 0 ;
if ( V_3 -> V_70 == V_120 )
return F_85 ( V_25 -> V_121 , 2000 ) ;
else
return F_85 ( V_25 -> V_119 , 2000 ) ;
}
static T_2 F_87 ( struct V_1 * V_1 , int V_118 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_70 != V_120 && F_88 ( V_25 ) ) {
switch ( V_118 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_86 ( V_1 , V_118 ) ;
}
static T_2 F_89 ( struct V_1 * V_1 , int V_118 )
{
return V_118 ? 0 : 1 ;
}
static T_2 F_90 ( struct V_1 * V_1 ,
bool V_112 ,
int V_122 ,
T_2 V_123 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_124 , V_125 ;
if ( F_91 ( V_7 ) )
V_124 = 3 ;
else
V_124 = 5 ;
if ( F_92 ( V_7 ) && V_3 -> V_70 == V_120 )
V_125 = V_126 ;
else
V_125 = V_127 ;
return V_128 |
V_129 |
( V_112 ? V_130 : 0 ) |
V_131 |
V_125 |
V_132 |
( V_122 << V_133 ) |
( V_124 << V_134 ) |
( V_123 << V_135 ) ;
}
static T_2 F_93 ( struct V_1 * V_1 ,
bool V_112 ,
int V_122 ,
T_2 V_103 )
{
return V_128 |
V_129 |
( V_112 ? V_130 : 0 ) |
V_131 |
V_136 |
V_132 |
( V_122 << V_133 ) |
F_94 ( 32 ) |
F_95 ( 32 ) ;
}
static int
F_96 ( struct V_1 * V_1 ,
const T_3 * V_137 , int V_122 ,
T_3 * V_138 , int V_139 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_6 V_113 = V_1 -> V_114 ;
T_2 V_123 ;
int V_52 , V_140 , V_141 ;
T_2 V_115 ;
int V_142 , clock = 0 ;
bool V_112 = F_97 ( V_7 ) ;
bool V_143 ;
F_22 ( V_1 ) ;
V_143 = F_98 ( V_1 ) ;
F_99 ( & V_25 -> V_144 , 0 ) ;
F_78 ( V_1 ) ;
for ( V_142 = 0 ; V_142 < 3 ; V_142 ++ ) {
V_115 = F_100 ( V_113 ) ;
if ( ( V_115 & V_128 ) == 0 )
break;
F_75 ( 1 ) ;
}
if ( V_142 == 3 ) {
static T_5 V_145 = - 1 ;
const T_5 V_115 = F_32 ( V_113 ) ;
if ( V_115 != V_145 ) {
F_8 ( 1 , L_11 ,
V_115 ) ;
V_145 = V_115 ;
}
V_140 = - V_146 ;
goto V_147;
}
if ( F_48 ( V_122 > 20 || V_139 > 20 ) ) {
V_140 = - V_148 ;
goto V_147;
}
while ( ( V_123 = V_1 -> V_149 ( V_1 , clock ++ ) ) ) {
T_5 V_150 = V_1 -> V_151 ( V_1 ,
V_112 ,
V_122 ,
V_123 ) ;
for ( V_142 = 0 ; V_142 < 5 ; V_142 ++ ) {
for ( V_52 = 0 ; V_52 < V_122 ; V_52 += 4 )
F_43 ( V_1 -> V_152 [ V_52 >> 2 ] ,
F_20 ( V_137 + V_52 ,
V_122 - V_52 ) ) ;
F_43 ( V_113 , V_150 ) ;
V_115 = F_79 ( V_1 , V_112 ) ;
F_43 ( V_113 ,
V_115 |
V_129 |
V_131 |
V_132 ) ;
if ( V_115 & V_131 )
continue;
if ( V_115 & V_132 ) {
F_101 ( 400 , 500 ) ;
continue;
}
if ( V_115 & V_129 )
goto V_116;
}
}
if ( ( V_115 & V_129 ) == 0 ) {
F_42 ( L_12 , V_115 ) ;
V_140 = - V_146 ;
goto V_147;
}
V_116:
if ( V_115 & V_132 ) {
F_42 ( L_13 , V_115 ) ;
V_140 = - V_153 ;
goto V_147;
}
if ( V_115 & V_131 ) {
F_35 ( L_14 , V_115 ) ;
V_140 = - V_154 ;
goto V_147;
}
V_141 = ( ( V_115 & V_155 ) >>
V_133 ) ;
if ( V_141 == 0 || V_141 > 20 ) {
F_35 ( L_15 ,
V_141 ) ;
F_101 ( 1000 , 1500 ) ;
V_140 = - V_146 ;
goto V_147;
}
if ( V_141 > V_139 )
V_141 = V_139 ;
for ( V_52 = 0 ; V_52 < V_141 ; V_52 += 4 )
F_21 ( F_32 ( V_1 -> V_152 [ V_52 >> 2 ] ) ,
V_138 + V_52 , V_141 - V_52 ) ;
V_140 = V_141 ;
V_147:
F_99 ( & V_25 -> V_144 , V_156 ) ;
if ( V_143 )
F_102 ( V_1 , false ) ;
F_26 ( V_1 ) ;
return V_140 ;
}
static T_7
F_103 ( struct V_157 * V_158 , struct V_159 * V_160 )
{
struct V_1 * V_1 = F_73 ( V_158 , struct V_1 , V_158 ) ;
T_3 V_161 [ 20 ] , V_162 [ 20 ] ;
T_8 V_163 , V_164 ;
int V_140 ;
V_161 [ 0 ] = ( V_160 -> V_165 << 4 ) |
( ( V_160 -> V_166 >> 16 ) & 0xf ) ;
V_161 [ 1 ] = ( V_160 -> V_166 >> 8 ) & 0xff ;
V_161 [ 2 ] = V_160 -> V_166 & 0xff ;
V_161 [ 3 ] = V_160 -> V_167 - 1 ;
switch ( V_160 -> V_165 & ~ V_168 ) {
case V_169 :
case V_170 :
case V_171 :
V_163 = V_160 -> V_167 ? V_172 + V_160 -> V_167 : V_173 ;
V_164 = 2 ;
if ( F_48 ( V_163 > 20 ) )
return - V_148 ;
F_48 ( ! V_160 -> V_174 != ! V_160 -> V_167 ) ;
if ( V_160 -> V_174 )
memcpy ( V_161 + V_172 , V_160 -> V_174 , V_160 -> V_167 ) ;
V_140 = F_96 ( V_1 , V_161 , V_163 , V_162 , V_164 ) ;
if ( V_140 > 0 ) {
V_160 -> V_175 = V_162 [ 0 ] >> 4 ;
if ( V_140 > 1 ) {
V_140 = F_104 ( int , V_162 [ 1 ] , 0 , V_160 -> V_167 ) ;
} else {
V_140 = V_160 -> V_167 ;
}
}
break;
case V_176 :
case V_177 :
V_163 = V_160 -> V_167 ? V_172 : V_173 ;
V_164 = V_160 -> V_167 + 1 ;
if ( F_48 ( V_164 > 20 ) )
return - V_148 ;
V_140 = F_96 ( V_1 , V_161 , V_163 , V_162 , V_164 ) ;
if ( V_140 > 0 ) {
V_160 -> V_175 = V_162 [ 0 ] >> 4 ;
V_140 -- ;
memcpy ( V_160 -> V_174 , V_162 + 1 , V_140 ) ;
}
break;
default:
V_140 = - V_178 ;
break;
}
return V_140 ;
}
static enum V_70 F_105 ( struct V_24 * V_25 ,
enum V_70 V_70 )
{
const struct V_179 * V_180 =
& V_25 -> V_181 . V_182 [ V_70 ] ;
enum V_70 V_183 ;
if ( ! V_180 -> V_184 ) {
F_35 ( L_16 ,
F_34 ( V_70 ) , F_34 ( V_70 ) ) ;
return V_70 ;
}
switch ( V_180 -> V_184 ) {
case V_185 :
V_183 = V_120 ;
break;
case V_186 :
V_183 = V_187 ;
break;
case V_188 :
V_183 = V_189 ;
break;
case V_190 :
V_183 = V_191 ;
break;
default:
F_106 ( V_180 -> V_184 ) ;
V_183 = V_120 ;
break;
}
F_35 ( L_17 ,
F_34 ( V_183 ) , F_34 ( V_70 ) ) ;
return V_183 ;
}
static T_6 F_107 ( struct V_24 * V_25 ,
enum V_70 V_70 )
{
switch ( V_70 ) {
case V_187 :
case V_189 :
case V_191 :
return F_108 ( V_70 ) ;
default:
F_106 ( V_70 ) ;
return F_108 ( V_187 ) ;
}
}
static T_6 F_109 ( struct V_24 * V_25 ,
enum V_70 V_70 , int V_118 )
{
switch ( V_70 ) {
case V_187 :
case V_189 :
case V_191 :
return F_110 ( V_70 , V_118 ) ;
default:
F_106 ( V_70 ) ;
return F_110 ( V_187 , V_118 ) ;
}
}
static T_6 F_111 ( struct V_24 * V_25 ,
enum V_70 V_70 )
{
switch ( V_70 ) {
case V_120 :
return F_108 ( V_70 ) ;
case V_187 :
case V_189 :
case V_191 :
return F_112 ( V_70 ) ;
default:
F_106 ( V_70 ) ;
return F_108 ( V_120 ) ;
}
}
static T_6 F_113 ( struct V_24 * V_25 ,
enum V_70 V_70 , int V_118 )
{
switch ( V_70 ) {
case V_120 :
return F_110 ( V_70 , V_118 ) ;
case V_187 :
case V_189 :
case V_191 :
return F_114 ( V_70 , V_118 ) ;
default:
F_106 ( V_70 ) ;
return F_110 ( V_120 , V_118 ) ;
}
}
static T_6 F_115 ( struct V_24 * V_25 ,
enum V_70 V_70 )
{
switch ( V_70 ) {
case V_120 :
case V_187 :
case V_189 :
case V_191 :
return F_108 ( V_70 ) ;
default:
F_106 ( V_70 ) ;
return F_108 ( V_120 ) ;
}
}
static T_6 F_116 ( struct V_24 * V_25 ,
enum V_70 V_70 , int V_118 )
{
switch ( V_70 ) {
case V_120 :
case V_187 :
case V_189 :
case V_191 :
return F_110 ( V_70 , V_118 ) ;
default:
F_106 ( V_70 ) ;
return F_110 ( V_120 , V_118 ) ;
}
}
static T_6 F_117 ( struct V_24 * V_25 ,
enum V_70 V_70 )
{
if ( F_118 ( V_25 ) -> V_192 >= 9 )
return F_115 ( V_25 , V_70 ) ;
else if ( F_119 ( V_25 ) )
return F_111 ( V_25 , V_70 ) ;
else
return F_107 ( V_25 , V_70 ) ;
}
static T_6 F_120 ( struct V_24 * V_25 ,
enum V_70 V_70 , int V_118 )
{
if ( F_118 ( V_25 ) -> V_192 >= 9 )
return F_116 ( V_25 , V_70 , V_118 ) ;
else if ( F_119 ( V_25 ) )
return F_113 ( V_25 , V_70 , V_118 ) ;
else
return F_109 ( V_25 , V_70 , V_118 ) ;
}
static void F_121 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
enum V_70 V_70 = F_105 ( V_25 ,
F_2 ( V_1 ) -> V_70 ) ;
int V_52 ;
V_1 -> V_114 = F_117 ( V_25 , V_70 ) ;
for ( V_52 = 0 ; V_52 < F_122 ( V_1 -> V_152 ) ; V_52 ++ )
V_1 -> V_152 [ V_52 ] = F_120 ( V_25 , V_70 , V_52 ) ;
}
static void
F_123 ( struct V_1 * V_1 )
{
F_124 ( V_1 -> V_158 . V_193 ) ;
}
static void
F_125 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
F_121 ( V_1 ) ;
F_126 ( & V_1 -> V_158 ) ;
V_1 -> V_158 . V_193 = F_127 ( V_194 , L_18 , F_34 ( V_70 ) ) ;
V_1 -> V_158 . V_195 = F_103 ;
}
static int
F_128 ( struct V_1 * V_1 , const int * * V_196 )
{
if ( V_1 -> V_197 ) {
* V_196 = V_1 -> V_196 ;
return V_1 -> V_197 ;
}
* V_196 = V_198 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
bool F_129 ( struct V_1 * V_1 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_199 -> V_4 . V_4 . V_7 ;
if ( F_130 ( V_7 , 0 , V_200 ) )
return false ;
if ( ( F_131 ( V_7 ) && ! F_132 ( V_7 ) ) || F_92 ( V_7 ) ||
( F_118 ( V_7 ) -> V_192 >= 9 ) )
return true ;
else
return false ;
}
static int
F_133 ( struct V_1 * V_1 , const int * * V_201 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_199 -> V_4 . V_4 . V_7 ;
int V_167 ;
if ( F_66 ( V_7 ) ) {
* V_201 = V_202 ;
V_167 = F_122 ( V_202 ) ;
} else if ( F_134 ( V_7 ) || F_135 ( V_7 ) ) {
* V_201 = V_203 ;
V_167 = F_122 ( V_203 ) ;
} else {
* V_201 = V_198 ;
V_167 = F_122 ( V_198 ) ;
}
if ( ! F_129 ( V_1 ) )
V_167 -- ;
return V_167 ;
}
static void
F_136 ( struct V_22 * V_23 ,
struct V_204 * V_205 )
{
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
const struct V_206 * V_207 = NULL ;
int V_52 , V_208 = 0 ;
if ( F_137 ( V_7 ) ) {
V_207 = V_209 ;
V_208 = F_122 ( V_209 ) ;
} else if ( F_119 ( V_7 ) ) {
V_207 = V_210 ;
V_208 = F_122 ( V_210 ) ;
} else if ( F_37 ( V_7 ) ) {
V_207 = V_78 ;
V_208 = F_122 ( V_78 ) ;
} else if ( F_65 ( V_7 ) ) {
V_207 = V_80 ;
V_208 = F_122 ( V_80 ) ;
}
if ( V_207 && V_208 ) {
for ( V_52 = 0 ; V_52 < V_208 ; V_52 ++ ) {
if ( V_205 -> V_211 == V_207 [ V_52 ] . clock ) {
V_205 -> V_79 = V_207 [ V_52 ] . V_79 ;
V_205 -> V_212 = true ;
break;
}
}
}
}
static int F_138 ( const int * V_201 , int V_213 ,
const int * V_196 , int V_214 ,
int * V_215 )
{
int V_52 = 0 , V_216 = 0 , V_217 = 0 ;
while ( V_52 < V_213 && V_216 < V_214 ) {
if ( V_201 [ V_52 ] == V_196 [ V_216 ] ) {
if ( F_48 ( V_217 >= V_218 ) )
return V_217 ;
V_215 [ V_217 ] = V_201 [ V_52 ] ;
++ V_217 ;
++ V_52 ;
++ V_216 ;
} else if ( V_201 [ V_52 ] < V_196 [ V_216 ] ) {
++ V_52 ;
} else {
++ V_216 ;
}
}
return V_217 ;
}
static int F_139 ( struct V_1 * V_1 ,
int * V_215 )
{
const int * V_201 , * V_196 ;
int V_213 , V_214 ;
V_214 = F_128 ( V_1 , & V_196 ) ;
V_213 = F_133 ( V_1 , & V_201 ) ;
return F_138 ( V_201 , V_213 ,
V_196 , V_214 ,
V_215 ) ;
}
static void F_140 ( char * V_219 , T_8 V_220 ,
const int * V_221 , int V_222 )
{
int V_52 ;
V_219 [ 0 ] = '\0' ;
for ( V_52 = 0 ; V_52 < V_222 ; V_52 ++ ) {
int V_223 = snprintf ( V_219 , V_220 , L_19 , V_52 ? L_20 : L_21 , V_221 [ V_52 ] ) ;
if ( V_223 >= V_220 )
return;
V_219 += V_223 ;
V_220 -= V_223 ;
}
}
static void F_141 ( struct V_1 * V_1 )
{
const int * V_201 , * V_196 ;
int V_213 , V_214 , V_224 ;
int V_215 [ V_218 ] ;
char V_219 [ 128 ] ;
if ( ( V_225 & V_226 ) == 0 )
return;
V_213 = F_133 ( V_1 , & V_201 ) ;
F_140 ( V_219 , sizeof( V_219 ) , V_201 , V_213 ) ;
F_35 ( L_22 , V_219 ) ;
V_214 = F_128 ( V_1 , & V_196 ) ;
F_140 ( V_219 , sizeof( V_219 ) , V_196 , V_214 ) ;
F_35 ( L_23 , V_219 ) ;
V_224 = F_139 ( V_1 , V_215 ) ;
F_140 ( V_219 , sizeof( V_219 ) , V_215 , V_224 ) ;
F_35 ( L_24 , V_219 ) ;
}
static void F_142 ( struct V_1 * V_1 )
{
T_3 V_227 ;
int V_220 ;
if ( ( V_225 & V_226 ) == 0 )
return;
if ( ! ( V_1 -> V_11 [ V_228 ] &
V_229 ) )
return;
V_220 = F_143 ( & V_1 -> V_158 , V_230 , & V_227 , 1 ) ;
if ( V_220 < 0 )
return;
F_35 ( L_25 , ( V_227 & 0xf0 ) >> 4 , V_227 & 0xf ) ;
}
static void F_144 ( struct V_1 * V_1 )
{
T_3 V_227 [ 2 ] ;
int V_220 ;
if ( ( V_225 & V_226 ) == 0 )
return;
if ( ! ( V_1 -> V_11 [ V_228 ] &
V_229 ) )
return;
V_220 = F_143 ( & V_1 -> V_158 , V_231 , & V_227 , 2 ) ;
if ( V_220 < 0 )
return;
F_35 ( L_26 , V_227 [ 0 ] , V_227 [ 1 ] ) ;
}
static int F_145 ( int V_232 , const int * V_233 )
{
int V_52 = 0 ;
for ( V_52 = 0 ; V_52 < V_218 ; ++ V_52 )
if ( V_232 == V_233 [ V_52 ] )
break;
return V_52 ;
}
int
F_19 ( struct V_1 * V_1 )
{
int V_233 [ V_218 ] = {} ;
int V_220 ;
V_220 = F_139 ( V_1 , V_233 ) ;
if ( F_48 ( V_220 <= 0 ) )
return 162000 ;
return V_233 [ V_220 - 1 ] ;
}
int F_146 ( struct V_1 * V_1 , int V_234 )
{
return F_145 ( V_234 , V_1 -> V_196 ) ;
}
void F_147 ( struct V_1 * V_1 , int V_211 ,
T_3 * V_235 , T_3 * V_236 )
{
if ( V_1 -> V_197 ) {
* V_235 = 0 ;
* V_236 =
F_146 ( V_1 , V_211 ) ;
} else {
* V_235 = F_148 ( V_211 ) ;
* V_236 = 0 ;
}
}
static int F_149 ( struct V_1 * V_1 ,
struct V_204 * V_205 )
{
int V_20 , V_237 ;
V_20 = V_205 -> V_238 ;
V_237 = F_150 ( V_1 -> V_11 , V_1 -> V_29 ) ;
if ( V_237 > 0 )
V_20 = F_11 ( V_20 , 3 * V_237 ) ;
return V_20 ;
}
bool
F_151 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_33 * V_241 = & V_205 -> V_4 . V_241 ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
struct V_242 * V_242 = F_152 ( V_205 -> V_4 . V_243 ) ;
struct V_35 * V_35 = V_1 -> V_244 ;
int V_245 , clock ;
int V_246 = 1 ;
int V_247 = F_9 ( V_1 ) ;
int V_248 = 0 ;
int V_249 ;
int V_20 , V_40 ;
int V_250 , V_251 ;
int V_215 [ V_218 ] = {} ;
int V_224 ;
T_3 V_235 , V_236 ;
V_224 = F_139 ( V_1 , V_215 ) ;
F_48 ( V_224 <= 0 ) ;
V_249 = V_224 - 1 ;
if ( F_119 ( V_7 ) && ! F_153 ( V_7 ) && V_70 != V_120 )
V_205 -> V_252 = true ;
V_205 -> V_253 = false ;
V_205 -> V_254 = V_1 -> V_254 && V_70 != V_120 ;
if ( F_1 ( V_1 ) && V_35 -> V_37 . V_36 ) {
F_154 ( V_35 -> V_37 . V_36 ,
V_241 ) ;
if ( F_118 ( V_7 ) -> V_192 >= 9 ) {
int V_140 ;
V_140 = F_155 ( V_205 ) ;
if ( V_140 )
return V_140 ;
}
if ( F_156 ( V_7 ) )
F_157 ( V_242 , V_205 ,
V_35 -> V_37 . V_255 ) ;
else
F_158 ( V_242 , V_205 ,
V_35 -> V_37 . V_255 ) ;
}
if ( V_241 -> V_46 & V_47 )
return false ;
F_35 ( L_27
L_28 ,
V_247 , V_215 [ V_249 ] ,
V_241 -> V_256 ) ;
V_20 = F_149 ( V_1 , V_205 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_35 -> V_4 . V_257 . V_237 == 0 &&
( V_25 -> V_181 . V_258 . V_20 && V_25 -> V_181 . V_258 . V_20 < V_20 ) ) {
F_35 ( L_29 ,
V_25 -> V_181 . V_258 . V_20 ) ;
V_20 = V_25 -> V_181 . V_258 . V_20 ;
}
V_246 = V_247 ;
V_248 = V_249 ;
}
for (; V_20 >= 6 * 3 ; V_20 -= 2 * 3 ) {
V_40 = F_12 ( V_241 -> V_256 ,
V_20 ) ;
for ( clock = V_248 ; clock <= V_249 ; clock ++ ) {
for ( V_245 = V_246 ;
V_245 <= V_247 ;
V_245 <<= 1 ) {
V_251 = V_215 [ clock ] ;
V_250 = F_13 ( V_251 ,
V_245 ) ;
if ( V_40 <= V_250 ) {
goto V_259;
}
}
}
}
return false ;
V_259:
if ( V_1 -> V_260 ) {
V_205 -> V_261 =
V_20 != 18 && F_159 ( V_241 ) > 1 ;
} else {
V_205 -> V_261 =
V_1 -> V_261 ;
}
V_205 -> V_245 = V_245 ;
V_205 -> V_238 = V_20 ;
V_205 -> V_211 = V_215 [ clock ] ;
F_147 ( V_1 , V_205 -> V_211 ,
& V_235 , & V_236 ) ;
F_35 ( L_30 ,
V_235 , V_236 , V_205 -> V_245 ,
V_205 -> V_211 , V_20 ) ;
F_35 ( L_31 ,
V_40 , V_250 ) ;
F_160 ( V_20 , V_245 ,
V_241 -> V_256 ,
V_205 -> V_211 ,
& V_205 -> V_262 ) ;
if ( V_35 -> V_37 . V_263 != NULL &&
V_25 -> V_264 . type == V_265 ) {
V_205 -> V_253 = true ;
F_160 ( V_20 , V_245 ,
V_35 -> V_37 . V_263 -> clock ,
V_205 -> V_211 ,
& V_205 -> V_266 ) ;
}
if ( F_1 ( V_1 ) &&
( F_134 ( V_25 ) || F_135 ( V_25 ) ) ) {
int V_267 ;
switch ( V_205 -> V_211 / 2 ) {
case 108000 :
case 216000 :
V_267 = 8640000 ;
break;
default:
V_267 = 8100000 ;
break;
}
F_161 ( V_205 -> V_4 . V_268 ) -> V_269 = V_267 ;
}
if ( ! F_153 ( V_7 ) )
F_136 ( V_23 , V_205 ) ;
return true ;
}
void F_162 ( struct V_1 * V_1 ,
int V_270 , T_3 V_245 ,
bool V_271 )
{
V_1 -> V_270 = V_270 ;
V_1 -> V_245 = V_245 ;
V_1 -> V_271 = V_271 ;
}
static void F_163 ( struct V_22 * V_23 ,
struct V_204 * V_205 )
{
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
struct V_242 * V_243 = F_152 ( V_23 -> V_4 . V_243 ) ;
const struct V_33 * V_241 = & V_205 -> V_4 . V_241 ;
F_162 ( V_1 , V_205 -> V_211 ,
V_205 -> V_245 ,
F_164 ( V_205 ,
V_272 ) ) ;
V_1 -> V_67 = F_32 ( V_1 -> V_68 ) & V_71 ;
V_1 -> V_67 |= V_72 | V_73 ;
V_1 -> V_67 |= F_36 ( V_205 -> V_245 ) ;
if ( F_165 ( V_7 ) && V_70 == V_120 ) {
if ( V_241 -> V_46 & V_273 )
V_1 -> V_67 |= V_274 ;
if ( V_241 -> V_46 & V_275 )
V_1 -> V_67 |= V_276 ;
V_1 -> V_67 |= V_277 ;
if ( F_166 ( V_1 -> V_11 ) )
V_1 -> V_67 |= V_278 ;
V_1 -> V_67 |= V_243 -> V_59 << 29 ;
} else if ( F_167 ( V_7 ) && V_70 != V_120 ) {
T_5 V_279 ;
V_1 -> V_67 |= V_277 ;
V_279 = F_32 ( F_168 ( V_243 -> V_59 ) ) ;
if ( F_166 ( V_1 -> V_11 ) )
V_279 |= V_280 ;
else
V_279 &= ~ V_280 ;
F_43 ( F_168 ( V_243 -> V_59 ) , V_279 ) ;
} else {
if ( ! F_119 ( V_7 ) && ! F_65 ( V_7 ) &&
! F_37 ( V_7 ) && V_205 -> V_261 )
V_1 -> V_67 |= V_281 ;
if ( V_241 -> V_46 & V_273 )
V_1 -> V_67 |= V_274 ;
if ( V_241 -> V_46 & V_275 )
V_1 -> V_67 |= V_276 ;
V_1 -> V_67 |= V_282 ;
if ( F_166 ( V_1 -> V_11 ) )
V_1 -> V_67 |= V_278 ;
if ( F_37 ( V_7 ) )
V_1 -> V_67 |= F_38 ( V_243 -> V_59 ) ;
else if ( V_243 -> V_59 == V_75 )
V_1 -> V_67 |= V_76 ;
}
}
static void F_169 ( struct V_1 * V_1 ,
T_5 V_283 ,
T_5 V_284 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_6 V_285 , V_106 ;
F_47 ( & V_25 -> V_58 ) ;
F_170 ( V_25 , V_1 ) ;
V_285 = F_71 ( V_1 ) ;
V_106 = F_70 ( V_1 ) ;
F_35 ( L_32 ,
V_283 , V_284 ,
F_32 ( V_285 ) ,
F_32 ( V_106 ) ) ;
if ( F_171 ( V_25 ,
V_285 , V_283 , V_284 ,
5000 ) )
F_42 ( L_33 ,
F_32 ( V_285 ) ,
F_32 ( V_106 ) ) ;
F_35 ( L_34 ) ;
}
static void F_172 ( struct V_1 * V_1 )
{
F_35 ( L_35 ) ;
F_169 ( V_1 , V_286 , V_287 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
F_35 ( L_36 ) ;
F_169 ( V_1 , V_288 , V_289 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
T_9 V_290 ;
T_10 V_291 ;
F_35 ( L_37 ) ;
V_290 = F_175 () ;
V_291 = F_176 ( V_290 , V_1 -> V_292 ) ;
if ( V_291 < ( T_10 ) V_1 -> V_111 )
F_177 ( V_293 ,
V_1 -> V_111 - V_291 ) ;
F_169 ( V_1 , V_294 , V_295 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_177 ( V_1 -> V_296 ,
V_1 -> V_297 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
F_177 ( V_1 -> V_298 ,
V_1 -> V_299 ) ;
}
static T_5 F_180 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_300 ;
F_47 ( & V_25 -> V_58 ) ;
V_300 = F_32 ( F_70 ( V_1 ) ) ;
if ( F_48 ( ! F_153 ( V_25 ) &&
( V_300 & V_301 ) != V_109 ) ) {
V_300 &= ~ V_301 ;
V_300 |= V_109 ;
}
return V_300 ;
}
static bool F_98 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
T_5 V_302 ;
T_6 V_285 , V_106 ;
bool V_303 = ! V_1 -> V_304 ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_181 ( & V_1 -> V_305 ) ;
V_1 -> V_304 = true ;
if ( F_77 ( V_1 ) )
return V_303 ;
V_57 = F_23 ( V_22 ) ;
F_24 ( V_25 , V_57 ) ;
F_35 ( L_38 ,
F_34 ( V_3 -> V_70 ) ) ;
if ( ! F_76 ( V_1 ) )
F_174 ( V_1 ) ;
V_302 = F_180 ( V_1 ) ;
V_302 |= V_87 ;
V_285 = F_71 ( V_1 ) ;
V_106 = F_70 ( V_1 ) ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
F_35 ( L_39 ,
F_32 ( V_285 ) , F_32 ( V_106 ) ) ;
if ( ! F_76 ( V_1 ) ) {
F_35 ( L_40 ,
F_34 ( V_3 -> V_70 ) ) ;
F_75 ( V_1 -> V_306 ) ;
}
return V_303 ;
}
void F_182 ( struct V_1 * V_1 )
{
bool V_143 ;
if ( ! F_1 ( V_1 ) )
return;
F_22 ( V_1 ) ;
V_143 = F_98 ( V_1 ) ;
F_26 ( V_1 ) ;
F_183 ( ! V_143 , L_41 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) ;
}
static void F_184 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
enum V_56 V_57 ;
T_5 V_302 ;
T_6 V_285 , V_106 ;
F_47 ( & V_25 -> V_58 ) ;
F_48 ( V_1 -> V_304 ) ;
if ( ! F_77 ( V_1 ) )
return;
F_35 ( L_42 ,
F_34 ( V_3 -> V_70 ) ) ;
V_302 = F_180 ( V_1 ) ;
V_302 &= ~ V_87 ;
V_106 = F_70 ( V_1 ) ;
V_285 = F_71 ( V_1 ) ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
F_35 ( L_39 ,
F_32 ( V_285 ) , F_32 ( V_106 ) ) ;
if ( ( V_302 & V_307 ) == 0 )
V_1 -> V_292 = F_175 () ;
V_57 = F_23 ( V_22 ) ;
F_28 ( V_25 , V_57 ) ;
}
static void F_185 ( struct V_308 * V_309 )
{
struct V_1 * V_1 = F_73 ( F_186 ( V_309 ) ,
struct V_1 , V_305 ) ;
F_22 ( V_1 ) ;
if ( ! V_1 -> V_304 )
F_184 ( V_1 ) ;
F_26 ( V_1 ) ;
}
static void F_187 ( struct V_1 * V_1 )
{
unsigned long V_310 ;
V_310 = F_188 ( V_1 -> V_111 * 5 ) ;
F_189 ( & V_1 -> V_305 , V_310 ) ;
}
static void F_102 ( struct V_1 * V_1 , bool V_311 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_183 ( ! V_1 -> V_304 , L_43 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) ;
V_1 -> V_304 = false ;
if ( V_311 )
F_184 ( V_1 ) ;
else
F_187 ( V_1 ) ;
}
static void F_190 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_302 ;
T_6 V_106 ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_35 ( L_44 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) ;
if ( F_8 ( F_76 ( V_1 ) ,
L_45 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) )
return;
F_174 ( V_1 ) ;
V_106 = F_70 ( V_1 ) ;
V_302 = F_180 ( V_1 ) ;
if ( F_191 ( V_7 ) ) {
V_302 &= ~ V_312 ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
}
V_302 |= V_307 ;
if ( ! F_191 ( V_7 ) )
V_302 |= V_312 ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
F_172 ( V_1 ) ;
V_1 -> V_296 = V_293 ;
if ( F_191 ( V_7 ) ) {
V_302 |= V_312 ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
}
}
void F_192 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_22 ( V_1 ) ;
F_190 ( V_1 ) ;
F_26 ( V_1 ) ;
}
static void F_193 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
T_5 V_302 ;
T_6 V_106 ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_35 ( L_46 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) ;
F_8 ( ! V_1 -> V_304 , L_47 ,
F_34 ( F_2 ( V_1 ) -> V_70 ) ) ;
V_302 = F_180 ( V_1 ) ;
V_302 &= ~ ( V_307 | V_312 | V_87 |
V_313 ) ;
V_106 = F_70 ( V_1 ) ;
V_1 -> V_304 = false ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
V_1 -> V_292 = F_175 () ;
F_173 ( V_1 ) ;
V_57 = F_23 ( V_22 ) ;
F_28 ( V_25 , V_57 ) ;
}
void F_194 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_22 ( V_1 ) ;
F_193 ( V_1 ) ;
F_26 ( V_1 ) ;
}
static void F_195 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_302 ;
T_6 V_106 ;
F_178 ( V_1 ) ;
F_22 ( V_1 ) ;
V_302 = F_180 ( V_1 ) ;
V_302 |= V_313 ;
V_106 = F_70 ( V_1 ) ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
F_26 ( V_1 ) ;
}
void F_196 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_35 ( L_48 ) ;
F_197 ( V_1 -> V_244 ) ;
F_195 ( V_1 ) ;
}
static void F_198 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_302 ;
T_6 V_106 ;
if ( ! F_1 ( V_1 ) )
return;
F_22 ( V_1 ) ;
V_302 = F_180 ( V_1 ) ;
V_302 &= ~ V_313 ;
V_106 = F_70 ( V_1 ) ;
F_43 ( V_106 , V_302 ) ;
F_44 ( V_106 ) ;
F_26 ( V_1 ) ;
V_1 -> V_298 = V_293 ;
F_179 ( V_1 ) ;
}
void F_199 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_35 ( L_48 ) ;
F_198 ( V_1 ) ;
F_200 ( V_1 -> V_244 ) ;
}
static void F_201 ( struct V_35 * V_9 ,
bool V_314 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_315 ;
F_22 ( V_1 ) ;
V_315 = F_180 ( V_1 ) & V_313 ;
F_26 ( V_1 ) ;
if ( V_315 == V_314 )
return;
F_35 ( L_49 ,
V_314 ? L_50 : L_51 ) ;
if ( V_314 )
F_195 ( V_1 ) ;
else
F_198 ( V_1 ) ;
}
static void F_202 ( struct V_1 * V_1 , bool V_268 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_199 -> V_4 . V_4 . V_7 ) ;
bool V_316 = F_32 ( V_1 -> V_68 ) & V_69 ;
F_183 ( V_316 != V_268 ,
L_52 ,
F_34 ( V_199 -> V_70 ) ,
F_203 ( V_268 ) , F_203 ( V_316 ) ) ;
}
static void F_204 ( struct V_24 * V_25 , bool V_268 )
{
bool V_316 = F_32 ( V_317 ) & V_318 ;
F_183 ( V_316 != V_268 ,
L_53 ,
F_203 ( V_268 ) , F_203 ( V_316 ) ) ;
}
static void F_205 ( struct V_1 * V_1 ,
struct V_204 * V_205 )
{
struct V_242 * V_243 = F_152 ( V_205 -> V_4 . V_243 ) ;
struct V_24 * V_25 = F_15 ( V_243 -> V_4 . V_7 ) ;
F_206 ( V_25 , V_243 -> V_59 ) ;
F_207 ( V_1 ) ;
F_208 ( V_25 ) ;
F_35 ( L_54 ,
V_205 -> V_211 ) ;
V_1 -> V_67 &= ~ V_319 ;
if ( V_205 -> V_211 == 162000 )
V_1 -> V_67 |= V_320 ;
else
V_1 -> V_67 |= V_321 ;
F_43 ( V_317 , V_1 -> V_67 ) ;
F_44 ( V_317 ) ;
F_209 ( 500 ) ;
if ( F_191 ( V_25 ) )
F_210 ( & V_25 -> V_91 , ! V_243 -> V_59 ) ;
V_1 -> V_67 |= V_318 ;
F_43 ( V_317 , V_1 -> V_67 ) ;
F_44 ( V_317 ) ;
F_209 ( 200 ) ;
}
static void F_211 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_242 * V_243 = F_152 ( V_3 -> V_4 . V_4 . V_243 ) ;
struct V_24 * V_25 = F_15 ( V_243 -> V_4 . V_7 ) ;
F_206 ( V_25 , V_243 -> V_59 ) ;
F_207 ( V_1 ) ;
F_212 ( V_25 ) ;
F_35 ( L_55 ) ;
V_1 -> V_67 &= ~ V_318 ;
F_43 ( V_317 , V_1 -> V_67 ) ;
F_44 ( V_317 ) ;
F_209 ( 200 ) ;
}
void F_213 ( struct V_1 * V_1 , int V_34 )
{
int V_140 , V_52 ;
if ( V_1 -> V_11 [ V_322 ] < 0x11 )
return;
if ( V_34 != V_323 ) {
V_140 = F_214 ( & V_1 -> V_158 , V_324 ,
V_325 ) ;
} else {
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
V_140 = F_214 ( & V_1 -> V_158 , V_324 ,
V_326 ) ;
if ( V_140 == 1 )
break;
F_75 ( 1 ) ;
}
}
if ( V_140 != 1 )
F_35 ( L_56 ,
V_34 == V_323 ? L_50 : L_51 ) ;
}
static bool F_215 ( struct V_22 * V_23 ,
enum V_59 * V_59 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
T_5 V_84 ;
bool V_140 ;
V_57 = F_216 ( V_23 ) ;
if ( ! F_217 ( V_25 , V_57 ) )
return false ;
V_140 = false ;
V_84 = F_32 ( V_1 -> V_68 ) ;
if ( ! ( V_84 & V_69 ) )
goto V_147;
if ( F_165 ( V_7 ) && V_70 == V_120 ) {
* V_59 = F_218 ( V_84 ) ;
} else if ( F_167 ( V_7 ) && V_70 != V_120 ) {
enum V_59 V_327 ;
F_219 (dev_priv, p) {
T_5 V_279 = F_32 ( F_168 ( V_327 ) ) ;
if ( F_220 ( V_279 ) == V_70 ) {
* V_59 = V_327 ;
V_140 = true ;
goto V_147;
}
}
F_35 ( L_57 ,
F_221 ( V_1 -> V_68 ) ) ;
} else if ( F_37 ( V_7 ) ) {
* V_59 = F_222 ( V_84 ) ;
} else {
* V_59 = F_223 ( V_84 ) ;
}
V_140 = true ;
V_147:
F_28 ( V_25 , V_57 ) ;
return V_140 ;
}
static void F_224 ( struct V_22 * V_23 ,
struct V_204 * V_205 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
T_5 V_84 , V_46 = 0 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
struct V_242 * V_243 = F_152 ( V_23 -> V_4 . V_243 ) ;
V_84 = F_32 ( V_1 -> V_68 ) ;
V_205 -> V_254 = V_84 & V_328 && V_70 != V_120 ;
if ( F_167 ( V_7 ) && V_70 != V_120 ) {
T_5 V_279 = F_32 ( F_168 ( V_243 -> V_59 ) ) ;
if ( V_279 & V_329 )
V_46 |= V_273 ;
else
V_46 |= V_330 ;
if ( V_279 & V_331 )
V_46 |= V_275 ;
else
V_46 |= V_332 ;
} else {
if ( V_84 & V_274 )
V_46 |= V_273 ;
else
V_46 |= V_330 ;
if ( V_84 & V_276 )
V_46 |= V_275 ;
else
V_46 |= V_332 ;
}
V_205 -> V_4 . V_241 . V_46 |= V_46 ;
if ( ! F_119 ( V_7 ) && ! F_65 ( V_7 ) &&
! F_37 ( V_7 ) && V_84 & V_281 )
V_205 -> V_261 = true ;
V_205 -> V_245 =
( ( V_84 & V_333 ) >> V_334 ) + 1 ;
F_225 ( V_243 , V_205 ) ;
if ( V_70 == V_120 ) {
if ( ( F_32 ( V_317 ) & V_319 ) == V_320 )
V_205 -> V_211 = 162000 ;
else
V_205 -> V_211 = 270000 ;
}
V_205 -> V_4 . V_241 . V_256 =
F_226 ( V_205 -> V_211 ,
& V_205 -> V_262 ) ;
if ( F_1 ( V_1 ) && V_25 -> V_181 . V_258 . V_20 &&
V_205 -> V_238 > V_25 -> V_181 . V_258 . V_20 ) {
F_35 ( L_58 ,
V_205 -> V_238 , V_25 -> V_181 . V_258 . V_20 ) ;
V_25 -> V_181 . V_258 . V_20 = V_205 -> V_238 ;
}
}
static void F_227 ( struct V_22 * V_23 ,
struct V_204 * V_335 ,
struct V_239 * V_336 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_24 * V_25 = F_15 ( V_23 -> V_4 . V_7 ) ;
if ( V_335 -> V_254 )
F_228 ( V_23 ) ;
if ( F_229 ( V_25 ) && ! F_153 ( V_25 ) )
F_230 ( V_1 ) ;
F_182 ( V_1 ) ;
F_199 ( V_1 ) ;
F_213 ( V_1 , V_337 ) ;
F_194 ( V_1 ) ;
if ( F_231 ( V_25 ) < 5 )
F_232 ( V_1 ) ;
}
static void F_233 ( struct V_22 * V_23 ,
struct V_204 * V_335 ,
struct V_239 * V_336 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
F_232 ( V_1 ) ;
if ( V_70 == V_120 )
F_211 ( V_1 ) ;
}
static void F_234 ( struct V_22 * V_23 ,
struct V_204 * V_335 ,
struct V_239 * V_336 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_232 ( V_1 ) ;
}
static void F_235 ( struct V_22 * V_23 ,
struct V_204 * V_335 ,
struct V_239 * V_336 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_232 ( V_1 ) ;
F_25 ( & V_25 -> V_338 ) ;
F_236 ( V_23 , true ) ;
F_27 ( & V_25 -> V_338 ) ;
}
static void
F_237 ( struct V_1 * V_1 ,
T_2 * V_67 ,
T_3 V_339 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
if ( V_339 & V_340 )
F_35 ( L_59 ,
V_339 & V_340 ) ;
if ( F_153 ( V_7 ) ) {
T_2 V_341 = F_32 ( F_238 ( V_70 ) ) ;
if ( V_339 & V_342 )
V_341 |= V_343 ;
else
V_341 &= ~ V_343 ;
V_341 &= ~ V_344 ;
switch ( V_339 & V_340 ) {
case V_345 :
V_341 |= V_346 ;
break;
case V_347 :
V_341 |= V_348 ;
break;
case V_349 :
V_341 |= V_350 ;
break;
case V_351 :
V_341 |= V_352 ;
break;
}
F_43 ( F_238 ( V_70 ) , V_341 ) ;
} else if ( ( F_165 ( V_7 ) && V_70 == V_120 ) ||
( F_167 ( V_7 ) && V_70 != V_120 ) ) {
* V_67 &= ~ V_353 ;
switch ( V_339 & V_340 ) {
case V_345 :
* V_67 |= V_277 ;
break;
case V_347 :
* V_67 |= V_354 ;
break;
case V_349 :
* V_67 |= V_355 ;
break;
case V_351 :
F_35 ( L_60 ) ;
* V_67 |= V_355 ;
break;
}
} else {
if ( F_37 ( V_7 ) )
* V_67 &= ~ V_356 ;
else
* V_67 &= ~ V_357 ;
switch ( V_339 & V_340 ) {
case V_345 :
* V_67 |= V_282 ;
break;
case V_347 :
* V_67 |= V_74 ;
break;
case V_349 :
* V_67 |= V_358 ;
break;
case V_351 :
if ( F_37 ( V_7 ) ) {
* V_67 |= V_359 ;
} else {
F_35 ( L_60 ) ;
* V_67 |= V_358 ;
}
break;
}
}
}
static void F_239 ( struct V_1 * V_1 ,
struct V_204 * V_335 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_240 ( V_1 , V_347 ) ;
V_1 -> V_67 |= V_69 ;
if ( V_335 -> V_254 )
V_1 -> V_67 |= V_328 ;
F_43 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
}
static void F_241 ( struct V_22 * V_23 ,
struct V_204 * V_205 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_242 * V_243 = F_152 ( V_23 -> V_4 . V_243 ) ;
T_2 V_360 = F_32 ( V_1 -> V_68 ) ;
enum V_59 V_59 = V_243 -> V_59 ;
if ( F_48 ( V_360 & V_69 ) )
return;
F_22 ( V_1 ) ;
if ( F_65 ( V_7 ) || F_37 ( V_7 ) )
F_242 ( V_1 ) ;
F_239 ( V_1 , V_205 ) ;
F_98 ( V_1 ) ;
F_190 ( V_1 ) ;
F_102 ( V_1 , true ) ;
F_26 ( V_1 ) ;
if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
unsigned int V_361 = 0x0 ;
if ( F_37 ( V_7 ) )
V_361 = F_243 ( V_205 -> V_245 ) ;
F_244 ( V_25 , F_2 ( V_1 ) ,
V_361 ) ;
}
F_213 ( V_1 , V_323 ) ;
F_245 ( V_1 ) ;
F_246 ( V_1 ) ;
if ( V_205 -> V_254 ) {
F_247 ( L_61 ,
F_33 ( V_59 ) ) ;
F_248 ( V_23 ) ;
}
}
static void F_249 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_241 ( V_23 , V_205 ) ;
F_196 ( V_1 ) ;
}
static void F_250 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_196 ( V_1 ) ;
F_251 ( V_1 ) ;
}
static void F_252 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
F_163 ( V_23 , V_205 ) ;
if ( V_70 == V_120 )
F_205 ( V_1 , V_205 ) ;
}
static void F_253 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_59 V_59 = V_1 -> V_60 ;
T_6 V_362 = F_61 ( V_59 ) ;
F_184 ( V_1 ) ;
F_35 ( L_62 ,
F_33 ( V_59 ) , F_34 ( V_3 -> V_70 ) ) ;
F_43 ( V_362 , 0 ) ;
F_44 ( V_362 ) ;
V_1 -> V_60 = V_83 ;
}
static void F_51 ( struct V_6 * V_7 ,
enum V_59 V_59 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_22 * V_23 ;
F_47 ( & V_25 -> V_58 ) ;
if ( F_48 ( V_59 != V_82 && V_59 != V_75 ) )
return;
F_49 (dev, encoder) {
struct V_1 * V_1 ;
enum V_70 V_70 ;
if ( V_23 -> type != V_5 )
continue;
V_1 = F_5 ( & V_23 -> V_4 ) ;
V_70 = F_2 ( V_1 ) -> V_70 ;
if ( V_1 -> V_60 != V_59 )
continue;
F_35 ( L_63 ,
F_33 ( V_59 ) , F_34 ( V_70 ) ) ;
F_8 ( V_23 -> V_4 . V_243 ,
L_64 ,
F_33 ( V_59 ) , F_34 ( V_70 ) ) ;
F_253 ( V_1 ) ;
}
}
static void F_242 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_242 * V_243 = F_152 ( V_23 -> V_4 . V_243 ) ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_60 == V_243 -> V_59 )
return;
if ( V_1 -> V_60 != V_83 )
F_253 ( V_1 ) ;
F_51 ( V_7 , V_243 -> V_59 ) ;
V_1 -> V_60 = V_243 -> V_59 ;
F_35 ( L_65 ,
F_33 ( V_1 -> V_60 ) , F_34 ( V_3 -> V_70 ) ) ;
F_52 ( V_7 , V_1 ) ;
F_53 ( V_7 , V_1 ) ;
}
static void F_254 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
F_255 ( V_23 ) ;
F_241 ( V_23 , V_205 ) ;
}
static void F_256 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
F_163 ( V_23 , V_205 ) ;
F_257 ( V_23 ) ;
}
static void F_258 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
F_259 ( V_23 ) ;
F_241 ( V_23 , V_205 ) ;
F_260 ( V_23 ) ;
}
static void F_261 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
F_163 ( V_23 , V_205 ) ;
F_262 ( V_23 ) ;
}
static void F_263 ( struct V_22 * V_23 ,
struct V_204 * V_205 ,
struct V_239 * V_240 )
{
F_264 ( V_23 ) ;
}
bool
F_265 ( struct V_1 * V_1 , T_3 V_363 [ V_364 ] )
{
return F_143 ( & V_1 -> V_158 , V_365 , V_363 ,
V_364 ) == V_364 ;
}
T_3
F_266 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
if ( F_66 ( V_7 ) )
return V_366 ;
else if ( F_118 ( V_7 ) -> V_192 >= 9 ) {
if ( V_25 -> V_181 . V_258 . V_367 && V_70 == V_120 )
return V_366 ;
return V_368 ;
} else if ( F_65 ( V_7 ) || F_37 ( V_7 ) )
return V_366 ;
else if ( F_165 ( V_7 ) && V_70 == V_120 )
return V_368 ;
else if ( F_167 ( V_7 ) && V_70 != V_120 )
return V_366 ;
else
return V_368 ;
}
T_3
F_267 ( struct V_1 * V_1 , T_3 V_369 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
if ( F_118 ( V_7 ) -> V_192 >= 9 ) {
switch ( V_369 & V_370 ) {
case V_371 :
return V_372 ;
case V_373 :
return V_374 ;
case V_368 :
return V_375 ;
case V_366 :
return V_376 ;
default:
return V_376 ;
}
} else if ( F_131 ( V_7 ) || F_92 ( V_7 ) ) {
switch ( V_369 & V_370 ) {
case V_371 :
return V_372 ;
case V_373 :
return V_374 ;
case V_368 :
return V_375 ;
case V_366 :
default:
return V_376 ;
}
} else if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
switch ( V_369 & V_370 ) {
case V_371 :
return V_372 ;
case V_373 :
return V_374 ;
case V_368 :
return V_375 ;
case V_366 :
default:
return V_376 ;
}
} else if ( F_165 ( V_7 ) && V_70 == V_120 ) {
switch ( V_369 & V_370 ) {
case V_371 :
return V_374 ;
case V_373 :
case V_368 :
return V_375 ;
default:
return V_376 ;
}
} else {
switch ( V_369 & V_370 ) {
case V_371 :
return V_374 ;
case V_373 :
return V_374 ;
case V_368 :
return V_375 ;
case V_366 :
default:
return V_376 ;
}
}
}
static T_2 F_268 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_377 , V_378 ,
V_379 ;
T_3 V_380 = V_1 -> V_380 [ 0 ] ;
switch ( V_380 & V_381 ) {
case V_376 :
V_378 = 0x0004000 ;
switch ( V_380 & V_370 ) {
case V_371 :
V_377 = 0x2B405555 ;
V_379 = 0x552AB83A ;
break;
case V_373 :
V_377 = 0x2B404040 ;
V_379 = 0x5548B83A ;
break;
case V_368 :
V_377 = 0x2B245555 ;
V_379 = 0x5560B83A ;
break;
case V_366 :
V_377 = 0x2B405555 ;
V_379 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_375 :
V_378 = 0x0002000 ;
switch ( V_380 & V_370 ) {
case V_371 :
V_377 = 0x2B404040 ;
V_379 = 0x5552B83A ;
break;
case V_373 :
V_377 = 0x2B404848 ;
V_379 = 0x5580B83A ;
break;
case V_368 :
V_377 = 0x2B404040 ;
V_379 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_374 :
V_378 = 0x0000000 ;
switch ( V_380 & V_370 ) {
case V_371 :
V_377 = 0x2B305555 ;
V_379 = 0x5570B83A ;
break;
case V_373 :
V_377 = 0x2B2B4040 ;
V_379 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_372 :
V_378 = 0x0006000 ;
switch ( V_380 & V_370 ) {
case V_371 :
V_377 = 0x1B405555 ;
V_379 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_269 ( V_23 , V_377 , V_378 ,
V_379 , 0 ) ;
return 0 ;
}
static T_2 F_270 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_382 , V_383 ;
bool V_384 = false ;
T_3 V_380 = V_1 -> V_380 [ 0 ] ;
switch ( V_380 & V_381 ) {
case V_376 :
switch ( V_380 & V_370 ) {
case V_371 :
V_382 = 128 ;
V_383 = 52 ;
break;
case V_373 :
V_382 = 128 ;
V_383 = 77 ;
break;
case V_368 :
V_382 = 128 ;
V_383 = 102 ;
break;
case V_366 :
V_382 = 128 ;
V_383 = 154 ;
V_384 = true ;
break;
default:
return 0 ;
}
break;
case V_375 :
switch ( V_380 & V_370 ) {
case V_371 :
V_382 = 85 ;
V_383 = 78 ;
break;
case V_373 :
V_382 = 85 ;
V_383 = 116 ;
break;
case V_368 :
V_382 = 85 ;
V_383 = 154 ;
break;
default:
return 0 ;
}
break;
case V_374 :
switch ( V_380 & V_370 ) {
case V_371 :
V_382 = 64 ;
V_383 = 104 ;
break;
case V_373 :
V_382 = 64 ;
V_383 = 154 ;
break;
default:
return 0 ;
}
break;
case V_372 :
switch ( V_380 & V_370 ) {
case V_371 :
V_382 = 43 ;
V_383 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_271 ( V_23 , V_382 ,
V_383 , V_384 ) ;
return 0 ;
}
static T_2
F_272 ( T_3 V_380 )
{
T_2 V_385 = 0 ;
switch ( V_380 & V_370 ) {
case V_371 :
default:
V_385 |= V_72 ;
break;
case V_373 :
V_385 |= V_386 ;
break;
case V_368 :
V_385 |= V_387 ;
break;
case V_366 :
V_385 |= V_388 ;
break;
}
switch ( V_380 & V_381 ) {
case V_376 :
default:
V_385 |= V_73 ;
break;
case V_375 :
V_385 |= V_389 ;
break;
case V_374 :
V_385 |= V_390 ;
break;
case V_372 :
V_385 |= V_391 ;
break;
}
return V_385 ;
}
static T_2
F_273 ( T_3 V_380 )
{
int V_385 = V_380 & ( V_370 |
V_381 ) ;
switch ( V_385 ) {
case V_371 | V_376 :
case V_373 | V_376 :
return V_392 ;
case V_371 | V_375 :
return V_393 ;
case V_371 | V_374 :
case V_373 | V_374 :
return V_394 ;
case V_373 | V_375 :
case V_368 | V_375 :
return V_395 ;
case V_368 | V_376 :
case V_366 | V_376 :
return V_396 ;
default:
F_35 ( L_66
L_67 , V_385 ) ;
return V_392 ;
}
}
static T_2
F_274 ( T_3 V_380 )
{
int V_385 = V_380 & ( V_370 |
V_381 ) ;
switch ( V_385 ) {
case V_371 | V_376 :
return V_397 ;
case V_371 | V_375 :
return V_398 ;
case V_371 | V_374 :
return V_399 ;
case V_373 | V_376 :
return V_400 ;
case V_373 | V_375 :
return V_401 ;
case V_368 | V_376 :
return V_402 ;
case V_368 | V_375 :
return V_403 ;
default:
F_35 ( L_66
L_67 , V_385 ) ;
return V_404 ;
}
}
void
F_275 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_2 V_385 , V_283 = 0 ;
T_3 V_380 = V_1 -> V_380 [ 0 ] ;
if ( F_153 ( V_7 ) ) {
V_385 = F_276 ( V_1 ) ;
if ( F_66 ( V_7 ) )
V_385 = 0 ;
else
V_283 = V_405 ;
} else if ( F_37 ( V_7 ) ) {
V_385 = F_270 ( V_1 ) ;
} else if ( F_65 ( V_7 ) ) {
V_385 = F_268 ( V_1 ) ;
} else if ( F_165 ( V_7 ) && V_70 == V_120 ) {
V_385 = F_274 ( V_380 ) ;
V_283 = V_406 ;
} else if ( F_91 ( V_7 ) && V_70 == V_120 ) {
V_385 = F_273 ( V_380 ) ;
V_283 = V_407 ;
} else {
V_385 = F_272 ( V_380 ) ;
V_283 = V_408 | V_409 ;
}
if ( V_283 )
F_35 ( L_68 , V_385 ) ;
F_35 ( L_69 ,
V_380 & V_370 ) ;
F_35 ( L_70 ,
( V_380 & V_381 ) >>
V_410 ) ;
V_1 -> V_67 = ( V_1 -> V_67 & ~ V_283 ) | V_385 ;
F_43 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
}
void
F_240 ( struct V_1 * V_1 ,
T_3 V_339 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_237 ( V_1 , & V_1 -> V_67 , V_339 ) ;
F_43 ( V_1 -> V_68 , V_1 -> V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
}
void F_277 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
T_2 V_411 ;
if ( ! F_153 ( V_7 ) )
return;
V_411 = F_32 ( F_238 ( V_70 ) ) ;
V_411 &= ~ V_344 ;
V_411 |= V_412 ;
F_43 ( F_238 ( V_70 ) , V_411 ) ;
if ( V_70 == V_120 )
return;
if ( F_171 ( V_25 , F_278 ( V_70 ) ,
V_413 ,
V_413 ,
1 ) )
F_42 ( L_71 ) ;
}
static void
F_232 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_242 * V_243 = F_152 ( V_3 -> V_4 . V_4 . V_243 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_2 V_67 = V_1 -> V_67 ;
if ( F_48 ( F_153 ( V_7 ) ) )
return;
if ( F_48 ( ( F_32 ( V_1 -> V_68 ) & V_69 ) == 0 ) )
return;
F_35 ( L_48 ) ;
if ( ( F_165 ( V_7 ) && V_70 == V_120 ) ||
( F_167 ( V_7 ) && V_70 != V_120 ) ) {
V_67 &= ~ V_353 ;
V_67 |= V_414 ;
} else {
if ( F_37 ( V_7 ) )
V_67 &= ~ V_356 ;
else
V_67 &= ~ V_357 ;
V_67 |= V_415 ;
}
F_43 ( V_1 -> V_68 , V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
V_67 &= ~ ( V_69 | V_328 ) ;
F_43 ( V_1 -> V_68 , V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
if ( F_279 ( V_7 ) && V_243 -> V_59 == V_75 && V_70 != V_120 ) {
F_280 ( V_25 , V_82 , false ) ;
F_281 ( V_25 , V_82 , false ) ;
V_67 &= ~ ( V_76 | V_357 ) ;
V_67 |= V_69 | V_74 ;
F_43 ( V_1 -> V_68 , V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
V_67 &= ~ V_69 ;
F_43 ( V_1 -> V_68 , V_67 ) ;
F_44 ( V_1 -> V_68 ) ;
F_210 ( & V_25 -> V_91 , V_82 ) ;
F_280 ( V_25 , V_82 , true ) ;
F_281 ( V_25 , V_82 , true ) ;
}
F_75 ( V_1 -> V_416 ) ;
V_1 -> V_67 = V_67 ;
}
static bool
F_282 ( struct V_1 * V_1 )
{
if ( F_143 ( & V_1 -> V_158 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_35 ( L_72 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
return V_1 -> V_11 [ V_322 ] != 0 ;
}
static bool
F_283 ( struct V_1 * V_1 )
{
struct V_24 * V_25 =
F_15 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_48 ( V_1 -> V_11 [ V_322 ] != 0 ) ;
if ( ! F_282 ( V_1 ) )
return false ;
if ( V_1 -> V_11 [ V_322 ] >= 0x11 )
V_25 -> V_417 = V_1 -> V_11 [ V_418 ] &
V_419 ;
F_143 ( & V_1 -> V_158 , V_420 ,
V_1 -> V_421 ,
sizeof( V_1 -> V_421 ) ) ;
if ( V_1 -> V_421 [ 0 ] & V_422 ) {
V_25 -> V_423 . V_424 = true ;
F_35 ( L_73 ) ;
}
if ( F_231 ( V_25 ) >= 9 &&
( V_1 -> V_421 [ 0 ] & V_425 ) ) {
T_3 V_426 ;
V_25 -> V_423 . V_424 = true ;
F_143 ( & V_1 -> V_158 ,
V_427 ,
& V_426 , 1 ) ;
V_25 -> V_423 . V_428 = V_426 ? true : false ;
V_25 -> V_423 . V_429 = V_25 -> V_423 . V_428 ;
F_35 ( L_74 ,
V_25 -> V_423 . V_429 ? L_75 : L_76 ) ;
}
if ( ( V_1 -> V_11 [ V_430 ] & V_431 ) &&
F_143 ( & V_1 -> V_158 , V_432 ,
V_1 -> V_433 , sizeof( V_1 -> V_433 ) ) ==
sizeof( V_1 -> V_433 ) )
F_35 ( L_77 , ( int ) sizeof( V_1 -> V_433 ) ,
V_1 -> V_433 ) ;
if ( V_1 -> V_433 [ 0 ] >= 0x03 ) {
T_11 V_196 [ V_218 ] ;
int V_52 ;
F_143 ( & V_1 -> V_158 , V_434 ,
V_196 , sizeof( V_196 ) ) ;
for ( V_52 = 0 ; V_52 < F_122 ( V_196 ) ; V_52 ++ ) {
int V_411 = F_284 ( V_196 [ V_52 ] ) ;
if ( V_411 == 0 )
break;
V_1 -> V_196 [ V_52 ] = ( V_411 * 200 ) / 10 ;
}
V_1 -> V_197 = V_52 ;
}
return true ;
}
static bool
F_285 ( struct V_1 * V_1 )
{
if ( ! F_282 ( V_1 ) )
return false ;
if ( F_143 ( & V_1 -> V_158 , V_435 ,
& V_1 -> V_436 , 1 ) < 0 )
return false ;
V_1 -> V_436 = F_286 ( V_1 -> V_436 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_436 )
return false ;
if ( ! ( V_1 -> V_11 [ V_228 ] &
V_229 ) )
return true ;
if ( V_1 -> V_11 [ V_322 ] == 0x10 )
return true ;
if ( F_143 ( & V_1 -> V_158 , V_437 ,
V_1 -> V_29 ,
V_438 ) < 0 )
return false ;
return true ;
}
static void
F_287 ( struct V_1 * V_1 )
{
T_1 V_439 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_440 ] & V_441 ) )
return;
if ( F_143 ( & V_1 -> V_158 , V_442 , V_439 , 3 ) == 3 )
F_35 ( L_78 ,
V_439 [ 0 ] , V_439 [ 1 ] , V_439 [ 2 ] ) ;
if ( F_143 ( & V_1 -> V_158 , V_443 , V_439 , 3 ) == 3 )
F_35 ( L_79 ,
V_439 [ 0 ] , V_439 [ 1 ] , V_439 [ 2 ] ) ;
}
static bool
F_288 ( struct V_1 * V_1 )
{
T_1 V_439 [ 1 ] ;
if ( ! V_444 . V_445 )
return false ;
if ( ! V_1 -> V_446 )
return false ;
if ( V_1 -> V_11 [ V_322 ] < 0x12 )
return false ;
if ( F_143 ( & V_1 -> V_158 , V_447 , V_439 , 1 ) != 1 )
return false ;
return V_439 [ 0 ] & V_448 ;
}
static void
F_289 ( struct V_1 * V_1 )
{
if ( ! V_444 . V_445 )
return;
if ( ! V_1 -> V_446 )
return;
V_1 -> V_449 = F_288 ( V_1 ) ;
if ( V_1 -> V_449 )
F_35 ( L_80 ) ;
else
F_35 ( L_81 ) ;
F_290 ( & V_1 -> V_450 ,
V_1 -> V_449 ) ;
}
static int F_291 ( struct V_1 * V_1 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_199 -> V_4 . V_4 . V_7 ;
struct V_242 * V_242 = F_152 ( V_199 -> V_4 . V_4 . V_243 ) ;
T_1 V_439 ;
int V_140 = 0 ;
int V_208 = 0 ;
int V_451 = 10 ;
if ( F_292 ( & V_1 -> V_158 , V_452 , & V_439 ) < 0 ) {
F_35 ( L_82 ) ;
V_140 = - V_153 ;
goto V_147;
}
if ( F_214 ( & V_1 -> V_158 , V_452 ,
V_439 & ~ V_453 ) < 0 ) {
F_35 ( L_82 ) ;
V_140 = - V_153 ;
goto V_147;
}
do {
F_293 ( V_7 , V_242 -> V_59 ) ;
if ( F_292 ( & V_1 -> V_158 ,
V_454 , & V_439 ) < 0 ) {
V_140 = - V_153 ;
goto V_147;
}
V_208 = V_439 & V_455 ;
} while ( -- V_451 && V_208 );
if ( V_451 == 0 ) {
F_35 ( L_83 ) ;
V_140 = - V_154 ;
}
V_147:
F_294 ( V_242 ) ;
return V_140 ;
}
static int F_295 ( struct V_1 * V_1 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_199 -> V_4 . V_4 . V_7 ;
struct V_242 * V_242 = F_152 ( V_199 -> V_4 . V_4 . V_243 ) ;
T_1 V_439 ;
int V_140 ;
if ( F_292 ( & V_1 -> V_158 , V_454 , & V_439 ) < 0 )
return - V_153 ;
if ( ! ( V_439 & V_456 ) )
return - V_457 ;
if ( F_292 ( & V_1 -> V_158 , V_452 , & V_439 ) < 0 )
return - V_153 ;
if ( V_439 & V_453 ) {
V_140 = F_291 ( V_1 ) ;
if ( V_140 )
return V_140 ;
}
F_296 ( V_242 ) ;
if ( F_214 ( & V_1 -> V_158 , V_452 ,
V_439 | V_453 ) < 0 ) {
F_294 ( V_242 ) ;
return - V_153 ;
}
F_293 ( V_7 , V_242 -> V_59 ) ;
return 0 ;
}
int F_297 ( struct V_1 * V_1 , T_1 * V_458 )
{
struct V_2 * V_199 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_199 -> V_4 . V_4 . V_7 ;
struct V_242 * V_242 = F_152 ( V_199 -> V_4 . V_4 . V_243 ) ;
T_1 V_439 ;
int V_208 , V_140 ;
int V_451 = 6 ;
V_140 = F_295 ( V_1 ) ;
if ( V_140 )
return V_140 ;
do {
F_293 ( V_7 , V_242 -> V_59 ) ;
if ( F_292 ( & V_1 -> V_158 ,
V_454 , & V_439 ) < 0 ) {
V_140 = - V_153 ;
goto V_459;
}
V_208 = V_439 & V_455 ;
} while ( -- V_451 && V_208 == 0 );
if ( V_451 == 0 ) {
F_42 ( L_84 ) ;
V_140 = - V_154 ;
goto V_459;
}
if ( F_143 ( & V_1 -> V_158 , V_460 , V_458 , 6 ) < 0 ) {
V_140 = - V_153 ;
goto V_459;
}
V_459:
F_291 ( V_1 ) ;
return V_140 ;
}
static bool
F_298 ( struct V_1 * V_1 , T_1 * V_461 )
{
return F_143 ( & V_1 -> V_158 ,
V_462 ,
V_461 , 1 ) == 1 ;
}
static bool
F_299 ( struct V_1 * V_1 , T_1 * V_461 )
{
int V_140 ;
V_140 = F_143 ( & V_1 -> V_158 ,
V_463 ,
V_461 , 14 ) ;
if ( V_140 != 14 )
return false ;
return true ;
}
static T_3 F_300 ( struct V_1 * V_1 )
{
T_3 V_464 = V_465 ;
return V_464 ;
}
static T_3 F_301 ( struct V_1 * V_1 )
{
T_3 V_464 = V_466 ;
return V_464 ;
}
static T_3 F_302 ( struct V_1 * V_1 )
{
T_3 V_464 = V_466 ;
struct V_35 * V_35 = V_1 -> V_244 ;
struct V_8 * V_9 = & V_35 -> V_4 ;
if ( V_35 -> V_467 == NULL ||
V_9 -> V_468 ||
V_1 -> V_158 . V_469 > 6 ) {
if ( V_1 -> V_158 . V_470 > 0 ||
V_1 -> V_158 . V_469 > 0 )
F_35 ( L_85 ,
V_1 -> V_158 . V_470 ,
V_1 -> V_158 . V_469 ) ;
V_1 -> V_471 = V_472 ;
} else {
struct V_473 * V_474 = V_35 -> V_467 ;
V_474 += V_35 -> V_467 -> V_475 ;
if ( ! F_303 ( & V_1 -> V_158 ,
V_476 ,
& V_474 -> V_477 ,
1 ) )
F_35 ( L_86 ) ;
V_464 = V_465 | V_478 ;
V_1 -> V_471 = V_479 ;
}
V_1 -> V_480 = 1 ;
return V_464 ;
}
static T_3 F_304 ( struct V_1 * V_1 )
{
T_3 V_464 = V_466 ;
return V_464 ;
}
static void F_305 ( struct V_1 * V_1 )
{
T_3 V_481 = V_466 ;
T_3 V_482 = 0 ;
int V_115 = 0 ;
V_115 = F_143 ( & V_1 -> V_158 , V_483 , & V_482 , 1 ) ;
if ( V_115 <= 0 ) {
F_35 ( L_87 ) ;
goto V_484;
}
switch ( V_482 ) {
case V_485 :
F_35 ( L_88 ) ;
V_1 -> V_486 = V_485 ;
V_481 = F_300 ( V_1 ) ;
break;
case V_487 :
F_35 ( L_89 ) ;
V_1 -> V_486 = V_487 ;
V_481 = F_301 ( V_1 ) ;
break;
case V_488 :
F_35 ( L_90 ) ;
V_1 -> V_486 = V_488 ;
V_481 = F_302 ( V_1 ) ;
break;
case V_489 :
F_35 ( L_91 ) ;
V_1 -> V_486 = V_489 ;
V_481 = F_304 ( V_1 ) ;
break;
default:
F_35 ( L_92 , V_482 ) ;
break;
}
V_484:
V_115 = F_303 ( & V_1 -> V_158 ,
V_490 ,
& V_481 , 1 ) ;
if ( V_115 <= 0 )
F_35 ( L_93 ) ;
}
static int
F_306 ( struct V_1 * V_1 )
{
bool V_491 ;
if ( V_1 -> V_449 ) {
T_1 V_492 [ 16 ] = { 0 } ;
int V_140 = 0 ;
int V_493 ;
bool V_494 ;
V_491 = F_299 ( V_1 , V_492 ) ;
V_495:
if ( V_491 == true ) {
if ( V_1 -> V_496 &&
! F_307 ( & V_492 [ 10 ] , V_1 -> V_245 ) ) {
F_35 ( L_94 ) ;
F_245 ( V_1 ) ;
F_246 ( V_1 ) ;
}
F_35 ( L_95 , V_492 ) ;
V_140 = F_308 ( & V_1 -> V_450 , V_492 , & V_494 ) ;
if ( V_494 ) {
for ( V_493 = 0 ; V_493 < 3 ; V_493 ++ ) {
int V_497 ;
V_497 = F_303 ( & V_1 -> V_158 ,
V_463 + 1 ,
& V_492 [ 1 ] , 3 ) ;
if ( V_497 == 3 ) {
break;
}
}
V_491 = F_299 ( V_1 , V_492 ) ;
if ( V_491 == true ) {
F_35 ( L_96 , V_492 ) ;
goto V_495;
}
} else
V_140 = 0 ;
return V_140 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_35 ( L_97 ) ;
V_1 -> V_449 = false ;
F_290 ( & V_1 -> V_450 , V_1 -> V_449 ) ;
F_309 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_178 ;
}
static void
F_310 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_363 [ V_364 ] ;
F_48 ( ! F_311 ( & V_7 -> V_498 . V_499 ) ) ;
if ( ! F_265 ( V_1 , V_363 ) ) {
F_42 ( L_98 ) ;
return;
}
if ( ! V_22 -> V_4 . V_243 )
return;
if ( ! F_152 ( V_22 -> V_4 . V_243 ) -> V_500 )
return;
if ( ( V_1 -> V_486 == V_485 ) ||
( ! F_307 ( V_363 , V_1 -> V_245 ) ) ) {
F_35 ( L_99 ,
V_22 -> V_4 . V_193 ) ;
F_245 ( V_1 ) ;
F_246 ( V_1 ) ;
}
}
static bool
F_312 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_461 = 0 ;
T_1 V_501 = V_1 -> V_436 ;
bool V_140 ;
V_1 -> V_480 = 0 ;
V_1 -> V_486 = 0 ;
V_1 -> V_471 = 0 ;
V_140 = F_285 ( V_1 ) ;
if ( ( V_501 != V_1 -> V_436 ) || ! V_140 ) {
return false ;
}
if ( V_1 -> V_11 [ V_322 ] >= 0x11 &&
F_298 ( V_1 , & V_461 ) &&
V_461 != 0 ) {
F_214 ( & V_1 -> V_158 ,
V_462 ,
V_461 ) ;
if ( V_461 & V_502 )
F_247 ( L_100 ) ;
if ( V_461 & ( V_503 | V_504 ) )
F_247 ( L_101 ) ;
}
F_313 ( & V_7 -> V_498 . V_499 , NULL ) ;
F_310 ( V_1 ) ;
F_314 ( & V_7 -> V_498 . V_499 ) ;
return true ;
}
static enum V_505
F_315 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_285 ( V_1 ) )
return V_506 ;
if ( F_1 ( V_1 ) )
return V_507 ;
if ( ! ( V_11 [ V_228 ] & V_229 ) )
return V_507 ;
if ( V_1 -> V_11 [ V_322 ] >= 0x11 &&
V_1 -> V_29 [ 0 ] & V_508 ) {
return V_1 -> V_436 ?
V_507 : V_506 ;
}
if ( F_288 ( V_1 ) )
return V_507 ;
if ( F_316 ( & V_1 -> V_158 . V_509 ) )
return V_507 ;
if ( V_1 -> V_11 [ V_322 ] >= 0x11 ) {
type = V_1 -> V_29 [ 0 ] & V_30 ;
if ( type == V_31 ||
type == V_510 )
return V_511 ;
} else {
type = V_1 -> V_11 [ V_228 ] &
V_512 ;
if ( type == V_513 ||
type == V_514 )
return V_511 ;
}
F_35 ( L_102 ) ;
return V_506 ;
}
static enum V_505
F_317 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_505 V_115 ;
V_115 = F_318 ( V_7 ) ;
if ( V_115 == V_511 )
V_115 = V_507 ;
return V_115 ;
}
static bool F_319 ( struct V_24 * V_25 ,
struct V_2 * V_70 )
{
T_5 V_515 ;
switch ( V_70 -> V_70 ) {
case V_120 :
return true ;
case V_187 :
V_515 = V_516 ;
break;
case V_189 :
V_515 = V_517 ;
break;
case V_191 :
V_515 = V_518 ;
break;
default:
F_106 ( V_70 -> V_70 ) ;
return false ;
}
return F_32 ( V_519 ) & V_515 ;
}
static bool F_320 ( struct V_24 * V_25 ,
struct V_2 * V_70 )
{
T_5 V_515 ;
switch ( V_70 -> V_70 ) {
case V_120 :
return true ;
case V_187 :
V_515 = V_520 ;
break;
case V_189 :
V_515 = V_521 ;
break;
case V_191 :
V_515 = V_522 ;
break;
case V_523 :
V_515 = V_524 ;
break;
default:
F_106 ( V_70 -> V_70 ) ;
return false ;
}
return F_32 ( V_519 ) & V_515 ;
}
static bool F_321 ( struct V_24 * V_25 ,
struct V_2 * V_70 )
{
T_5 V_515 ;
switch ( V_70 -> V_70 ) {
case V_187 :
V_515 = V_525 ;
break;
case V_189 :
V_515 = V_526 ;
break;
case V_191 :
V_515 = V_527 ;
break;
default:
F_106 ( V_70 -> V_70 ) ;
return false ;
}
return F_32 ( V_528 ) & V_515 ;
}
static bool F_322 ( struct V_24 * V_25 ,
struct V_2 * V_70 )
{
T_5 V_515 ;
switch ( V_70 -> V_70 ) {
case V_187 :
V_515 = V_529 ;
break;
case V_189 :
V_515 = V_530 ;
break;
case V_191 :
V_515 = V_531 ;
break;
default:
F_106 ( V_70 -> V_70 ) ;
return false ;
}
return F_32 ( V_528 ) & V_515 ;
}
static bool F_323 ( struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_22 * V_22 = & V_3 -> V_4 ;
enum V_70 V_70 ;
T_5 V_515 ;
F_324 ( V_22 -> V_532 , & V_70 ) ;
switch ( V_70 ) {
case V_120 :
V_515 = V_533 ;
break;
case V_187 :
V_515 = V_534 ;
break;
case V_189 :
V_515 = V_535 ;
break;
default:
F_106 ( V_70 ) ;
return false ;
}
return F_32 ( V_536 ) & V_515 ;
}
static bool F_325 ( struct V_24 * V_25 ,
struct V_2 * V_70 )
{
if ( F_279 ( V_25 ) )
return F_319 ( V_25 , V_70 ) ;
else if ( F_119 ( V_25 ) )
return F_320 ( V_25 , V_70 ) ;
else if ( F_66 ( V_25 ) )
return F_323 ( V_25 , V_70 ) ;
else if ( F_326 ( V_25 ) )
return F_322 ( V_25 , V_70 ) ;
else
return F_321 ( V_25 , V_70 ) ;
}
static struct V_473 *
F_327 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = V_1 -> V_244 ;
if ( V_35 -> V_473 ) {
if ( F_328 ( V_35 -> V_473 ) )
return NULL ;
return F_329 ( V_35 -> V_473 ) ;
} else
return F_330 ( & V_35 -> V_4 ,
& V_1 -> V_158 . V_509 ) ;
}
static void
F_331 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = V_1 -> V_244 ;
struct V_473 * V_473 ;
F_332 ( V_1 ) ;
V_473 = F_327 ( V_1 ) ;
V_35 -> V_467 = V_473 ;
if ( V_1 -> V_537 != V_538 )
V_1 -> V_254 = V_1 -> V_537 == V_539 ;
else
V_1 -> V_254 = F_333 ( V_473 ) ;
}
static void
F_332 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = V_1 -> V_244 ;
F_124 ( V_35 -> V_467 ) ;
V_35 -> V_467 = NULL ;
V_1 -> V_254 = false ;
}
static enum V_505
F_334 ( struct V_35 * V_35 )
{
struct V_8 * V_9 = & V_35 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_505 V_115 ;
enum V_56 V_57 ;
T_1 V_461 = 0 ;
V_57 = F_23 ( V_22 ) ;
F_24 ( F_15 ( V_7 ) , V_57 ) ;
if ( F_1 ( V_1 ) )
V_115 = F_317 ( V_1 ) ;
else if ( F_325 ( F_15 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_115 = F_315 ( V_1 ) ;
else
V_115 = V_506 ;
if ( V_115 == V_506 ) {
V_1 -> V_480 = 0 ;
V_1 -> V_486 = 0 ;
V_1 -> V_471 = 0 ;
if ( V_1 -> V_449 ) {
F_35 ( L_103 ,
V_1 -> V_449 ,
V_1 -> V_450 . V_540 ) ;
V_1 -> V_449 = false ;
F_290 ( & V_1 -> V_450 ,
V_1 -> V_449 ) ;
}
goto V_147;
}
if ( V_22 -> type != V_5 )
V_22 -> type = V_541 ;
F_35 ( L_104 ,
F_335 ( F_129 ( V_1 ) ) ,
F_335 ( F_336 ( V_1 -> V_11 ) ) ) ;
F_141 ( V_1 ) ;
F_287 ( V_1 ) ;
F_142 ( V_1 ) ;
F_144 ( V_1 ) ;
F_289 ( V_1 ) ;
if ( V_1 -> V_449 ) {
V_115 = V_506 ;
goto V_147;
} else if ( V_9 -> V_115 == V_507 ) {
F_313 ( & V_7 -> V_498 . V_499 , NULL ) ;
F_310 ( V_1 ) ;
F_314 ( & V_7 -> V_498 . V_499 ) ;
goto V_147;
}
V_1 -> V_158 . V_470 = 0 ;
V_1 -> V_158 . V_469 = 0 ;
F_331 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_35 -> V_467 )
V_115 = V_507 ;
V_1 -> V_542 = true ;
if ( V_1 -> V_11 [ V_322 ] >= 0x11 &&
F_298 ( V_1 , & V_461 ) &&
V_461 != 0 ) {
F_214 ( & V_1 -> V_158 ,
V_462 ,
V_461 ) ;
if ( V_461 & V_502 )
F_305 ( V_1 ) ;
if ( V_461 & ( V_503 | V_504 ) )
F_247 ( L_101 ) ;
}
V_147:
if ( V_115 != V_507 && ! V_1 -> V_449 )
F_332 ( V_1 ) ;
F_28 ( F_15 ( V_7 ) , V_57 ) ;
return V_115 ;
}
static enum V_505
F_337 ( struct V_8 * V_9 , bool V_543 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
enum V_505 V_115 = V_9 -> V_115 ;
F_35 ( L_105 ,
V_9 -> V_4 . V_544 , V_9 -> V_193 ) ;
if ( ! V_1 -> V_542 )
V_115 = F_334 ( V_1 -> V_244 ) ;
V_1 -> V_542 = false ;
return V_115 ;
}
static void
F_338 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = & F_2 ( V_1 ) -> V_4 ;
struct V_24 * V_25 = F_15 ( V_22 -> V_4 . V_7 ) ;
enum V_56 V_57 ;
F_35 ( L_105 ,
V_9 -> V_4 . V_544 , V_9 -> V_193 ) ;
F_332 ( V_1 ) ;
if ( V_9 -> V_115 != V_507 )
return;
V_57 = F_23 ( V_22 ) ;
F_24 ( V_25 , V_57 ) ;
F_331 ( V_1 ) ;
F_28 ( V_25 , V_57 ) ;
if ( V_22 -> type != V_5 )
V_22 -> type = V_541 ;
}
static int F_339 ( struct V_8 * V_9 )
{
struct V_35 * V_35 = F_18 ( V_9 ) ;
struct V_473 * V_473 ;
V_473 = V_35 -> V_467 ;
if ( V_473 ) {
int V_140 = F_340 ( V_9 , V_473 ) ;
if ( V_140 )
return V_140 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_35 -> V_37 . V_36 ) {
struct V_33 * V_34 ;
V_34 = F_341 ( V_9 -> V_7 ,
V_35 -> V_37 . V_36 ) ;
if ( V_34 ) {
F_342 ( V_9 , V_34 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_343 ( struct V_8 * V_9 )
{
bool V_254 = false ;
struct V_473 * V_473 ;
V_473 = F_18 ( V_9 ) -> V_467 ;
if ( V_473 )
V_254 = F_333 ( V_473 ) ;
return V_254 ;
}
static int
F_344 ( struct V_8 * V_9 ,
struct V_545 * V_546 ,
T_12 V_411 )
{
struct V_24 * V_25 = F_15 ( V_9 -> V_7 ) ;
struct V_35 * V_35 = F_18 ( V_9 ) ;
struct V_22 * V_22 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_22 -> V_4 ) ;
int V_140 ;
V_140 = F_345 ( & V_9 -> V_4 , V_546 , V_411 ) ;
if ( V_140 )
return V_140 ;
if ( V_546 == V_25 -> V_547 ) {
int V_52 = V_411 ;
bool V_254 ;
if ( V_52 == V_1 -> V_537 )
return 0 ;
V_1 -> V_537 = V_52 ;
if ( V_52 == V_538 )
V_254 = F_343 ( V_9 ) ;
else
V_254 = ( V_52 == V_539 ) ;
if ( V_254 == V_1 -> V_254 )
return 0 ;
V_1 -> V_254 = V_254 ;
goto V_116;
}
if ( V_546 == V_25 -> V_548 ) {
bool V_549 = V_1 -> V_260 ;
bool V_550 = V_1 -> V_261 ;
switch ( V_411 ) {
case V_551 :
V_1 -> V_260 = true ;
break;
case V_552 :
V_1 -> V_260 = false ;
V_1 -> V_261 = false ;
break;
case V_553 :
V_1 -> V_260 = false ;
V_1 -> V_261 = true ;
break;
default:
return - V_178 ;
}
if ( V_549 == V_1 -> V_260 &&
V_550 == V_1 -> V_261 )
return 0 ;
goto V_116;
}
if ( F_1 ( V_1 ) &&
V_546 == V_9 -> V_7 -> V_498 . V_554 ) {
if ( V_411 == V_555 ) {
F_35 ( L_106 ) ;
return - V_178 ;
}
if ( F_156 ( V_25 ) &&
V_411 == V_556 ) {
F_35 ( L_107 ) ;
return - V_178 ;
}
if ( V_35 -> V_37 . V_255 == V_411 ) {
return 0 ;
}
V_35 -> V_37 . V_255 = V_411 ;
goto V_116;
}
return - V_178 ;
V_116:
if ( V_22 -> V_4 . V_243 )
F_346 ( V_22 -> V_4 . V_243 ) ;
return 0 ;
}
static int
F_347 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_140 ;
V_140 = F_348 ( V_9 ) ;
if ( V_140 )
return V_140 ;
F_349 ( V_9 ) ;
F_35 ( L_108 ,
V_1 -> V_158 . V_193 , V_9 -> V_557 -> V_558 . V_193 ) ;
V_1 -> V_158 . V_7 = V_9 -> V_557 ;
return F_350 ( & V_1 -> V_158 ) ;
}
static void
F_351 ( struct V_8 * V_9 )
{
F_352 ( & F_4 ( V_9 ) -> V_158 ) ;
F_353 ( V_9 ) ;
}
static void
F_354 ( struct V_8 * V_9 )
{
struct V_35 * V_35 = F_18 ( V_9 ) ;
F_124 ( V_35 -> V_467 ) ;
if ( ! F_355 ( V_35 -> V_473 ) )
F_124 ( V_35 -> V_473 ) ;
if ( V_9 -> V_559 == V_560 )
F_356 ( & V_35 -> V_37 ) ;
F_357 ( V_9 ) ;
F_124 ( V_9 ) ;
}
void F_358 ( struct V_561 * V_23 )
{
struct V_2 * V_3 = F_359 ( V_23 ) ;
struct V_1 * V_1 = & V_3 -> V_562 ;
F_360 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_361 ( & V_1 -> V_305 ) ;
F_22 ( V_1 ) ;
F_184 ( V_1 ) ;
F_26 ( V_1 ) ;
if ( V_1 -> V_104 . V_563 ) {
F_362 ( & V_1 -> V_104 ) ;
V_1 -> V_104 . V_563 = NULL ;
}
}
F_123 ( V_1 ) ;
F_363 ( V_23 ) ;
F_124 ( V_3 ) ;
}
void F_364 ( struct V_22 * V_22 )
{
struct V_1 * V_1 = F_5 ( & V_22 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_361 ( & V_1 -> V_305 ) ;
F_22 ( V_1 ) ;
F_184 ( V_1 ) ;
F_26 ( V_1 ) ;
}
static void F_365 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
F_47 ( & V_25 -> V_58 ) ;
if ( ! F_77 ( V_1 ) )
return;
F_35 ( L_109 ) ;
V_57 = F_23 ( & V_3 -> V_4 ) ;
F_24 ( V_25 , V_57 ) ;
F_187 ( V_1 ) ;
}
void F_366 ( struct V_561 * V_23 )
{
struct V_24 * V_25 = F_15 ( V_23 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_23 ) ;
if ( ! F_153 ( V_25 ) )
V_1 -> V_67 = F_32 ( V_1 -> V_68 ) ;
if ( F_367 ( V_23 ) -> type != V_5 )
return;
F_22 ( V_1 ) ;
F_368 ( V_23 -> V_7 , V_1 ) ;
F_365 ( V_1 ) ;
F_26 ( V_1 ) ;
}
enum V_564
F_369 ( struct V_2 * V_3 , bool V_565 )
{
struct V_1 * V_1 = & V_3 -> V_562 ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_56 V_57 ;
enum V_564 V_140 = V_566 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_567 )
V_3 -> V_4 . type = V_541 ;
if ( V_565 && V_3 -> V_4 . type == V_5 ) {
F_35 ( L_110 ,
F_34 ( V_3 -> V_70 ) ) ;
return V_568 ;
}
F_35 ( L_111 ,
F_34 ( V_3 -> V_70 ) ,
V_565 ? L_112 : L_113 ) ;
if ( V_565 ) {
V_1 -> V_542 = false ;
return V_566 ;
}
V_57 = F_23 ( V_22 ) ;
F_24 ( V_25 , V_57 ) ;
if ( V_1 -> V_449 ) {
if ( F_306 ( V_1 ) == - V_178 ) {
F_35 ( L_103 ,
V_1 -> V_449 , V_1 -> V_450 . V_540 ) ;
V_1 -> V_449 = false ;
F_290 ( & V_1 -> V_450 ,
V_1 -> V_449 ) ;
V_1 -> V_542 = false ;
goto V_569;
}
}
if ( ! V_1 -> V_449 ) {
if ( ! F_312 ( V_1 ) ) {
V_1 -> V_542 = false ;
goto V_569;
}
}
V_140 = V_568 ;
V_569:
F_28 ( V_25 , V_57 ) ;
return V_140 ;
}
bool F_370 ( struct V_6 * V_7 , enum V_70 V_70 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( F_118 ( V_7 ) -> V_192 < 5 )
return false ;
if ( V_70 == V_120 )
return true ;
return F_371 ( V_25 , V_70 ) ;
}
void
F_372 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_35 * V_35 = F_18 ( V_9 ) ;
F_373 ( V_9 ) ;
F_374 ( V_9 ) ;
V_1 -> V_260 = true ;
if ( F_1 ( V_1 ) ) {
F_375 ( V_9 -> V_7 ) ;
F_376 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_498 . V_554 ,
V_570 ) ;
V_35 -> V_37 . V_255 = V_570 ;
}
}
static void F_377 ( struct V_1 * V_1 )
{
V_1 -> V_292 = F_175 () ;
V_1 -> V_296 = V_293 ;
V_1 -> V_298 = V_293 ;
}
static void
F_378 ( struct V_24 * V_25 ,
struct V_1 * V_1 , struct V_571 * V_572 )
{
T_5 V_97 , V_98 , V_99 = 0 , V_573 = 0 ;
struct V_92 V_93 ;
F_67 ( V_25 , V_1 , & V_93 ) ;
V_573 = F_180 ( V_1 ) ;
V_97 = F_32 ( V_93 . V_97 ) ;
V_98 = F_32 ( V_93 . V_98 ) ;
if ( ! F_66 ( V_25 ) ) {
F_43 ( V_93 . V_95 , V_573 ) ;
V_99 = F_32 ( V_93 . V_99 ) ;
}
V_572 -> V_574 = ( V_97 & V_575 ) >>
V_576 ;
V_572 -> V_577 = ( V_97 & V_578 ) >>
V_579 ;
V_572 -> V_580 = ( V_98 & V_581 ) >>
V_582 ;
V_572 -> V_583 = ( V_98 & V_584 ) >>
V_585 ;
if ( F_66 ( V_25 ) ) {
T_13 V_84 = ( V_573 & V_586 ) >>
V_587 ;
if ( V_84 > 0 )
V_572 -> V_588 = ( V_84 - 1 ) * 1000 ;
else
V_572 -> V_588 = 0 ;
} else {
V_572 -> V_588 = ( ( V_99 & V_589 ) >>
V_590 ) * 1000 ;
}
}
static void
F_379 ( const char * V_591 , const struct V_571 * V_572 )
{
F_35 ( L_114 ,
V_591 ,
V_572 -> V_574 , V_572 -> V_577 , V_572 -> V_580 , V_572 -> V_583 , V_572 -> V_588 ) ;
}
static void
F_170 ( struct V_24 * V_25 ,
struct V_1 * V_1 )
{
struct V_571 V_592 ;
struct V_571 * V_593 = & V_1 -> V_594 ;
F_378 ( V_25 , V_1 , & V_592 ) ;
if ( V_592 . V_574 != V_593 -> V_574 || V_592 . V_577 != V_593 -> V_577 || V_592 . V_580 != V_593 -> V_580 ||
V_592 . V_583 != V_593 -> V_583 || V_592 . V_588 != V_593 -> V_588 ) {
F_42 ( L_115 ) ;
F_379 ( L_116 , V_593 ) ;
F_379 ( L_117 , & V_592 ) ;
}
}
static void
F_52 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_571 V_595 , V_181 , V_596 ,
* V_597 = & V_1 -> V_594 ;
F_47 ( & V_25 -> V_58 ) ;
if ( V_597 -> V_588 != 0 )
return;
F_378 ( V_25 , V_1 , & V_595 ) ;
F_379 ( L_118 , & V_595 ) ;
V_181 = V_25 -> V_181 . V_258 . V_598 ;
V_596 . V_574 = 210 * 10 ;
V_596 . V_577 = 50 * 10 ;
V_596 . V_580 = 50 * 10 ;
V_596 . V_583 = 500 * 10 ;
V_596 . V_588 = ( 510 + 100 ) * 10 ;
F_379 ( L_119 , & V_181 ) ;
#define F_380 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_380 ( V_574 ) ;
F_380 ( V_577 ) ;
F_380 ( V_580 ) ;
F_380 ( V_583 ) ;
F_380 ( V_588 ) ;
#undef F_380
#define F_381 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_306 = F_381 ( V_574 ) ;
V_1 -> V_297 = F_381 ( V_577 ) ;
V_1 -> V_299 = F_381 ( V_580 ) ;
V_1 -> V_416 = F_381 ( V_583 ) ;
V_1 -> V_111 = F_381 ( V_588 ) ;
#undef F_381
F_35 ( L_120 ,
V_1 -> V_306 , V_1 -> V_416 ,
V_1 -> V_111 ) ;
F_35 ( L_121 ,
V_1 -> V_297 , V_1 -> V_299 ) ;
V_597 -> V_577 = 1 ;
V_597 -> V_580 = 1 ;
}
static void
F_53 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_97 , V_98 , V_99 , V_89 = 0 ;
int div = V_25 -> V_119 / 1000 ;
struct V_92 V_93 ;
enum V_70 V_70 = F_2 ( V_1 ) -> V_70 ;
const struct V_571 * V_572 = & V_1 -> V_594 ;
F_47 ( & V_25 -> V_58 ) ;
F_67 ( V_25 , V_1 , & V_93 ) ;
V_97 = ( V_572 -> V_574 << V_576 ) |
( V_572 -> V_577 << V_579 ) ;
V_98 = ( V_572 -> V_580 << V_582 ) |
( V_572 -> V_583 << V_585 ) ;
if ( F_66 ( V_7 ) ) {
V_99 = F_32 ( V_93 . V_95 ) ;
V_99 &= ~ V_586 ;
V_99 |= ( F_382 ( ( V_572 -> V_588 + 1 ) , 1000 )
<< V_587 ) ;
} else {
V_99 = ( ( 100 * div ) / 2 - 1 ) << V_599 ;
V_99 |= ( F_382 ( V_572 -> V_588 , 1000 )
<< V_590 ) ;
}
if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
V_89 = F_62 ( V_70 ) ;
} else if ( F_279 ( V_7 ) || F_167 ( V_7 ) ) {
if ( V_70 == V_120 )
V_89 = V_600 ;
else
V_89 = V_601 ;
}
V_97 |= V_89 ;
F_43 ( V_93 . V_97 , V_97 ) ;
F_43 ( V_93 . V_98 , V_98 ) ;
if ( F_66 ( V_7 ) )
F_43 ( V_93 . V_95 , V_99 ) ;
else
F_43 ( V_93 . V_99 , V_99 ) ;
F_35 ( L_122 ,
F_32 ( V_93 . V_97 ) ,
F_32 ( V_93 . V_98 ) ,
F_66 ( V_7 ) ?
( F_32 ( V_93 . V_95 ) & V_586 ) :
F_32 ( V_93 . V_99 ) ) ;
}
static void F_368 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
F_63 ( V_1 ) ;
} else {
F_52 ( V_7 , V_1 ) ;
F_53 ( V_7 , V_1 ) ;
}
}
static void F_383 ( struct V_24 * V_25 ,
struct V_204 * V_602 ,
int V_603 )
{
struct V_22 * V_23 ;
struct V_2 * V_199 = NULL ;
struct V_1 * V_1 = V_25 -> V_264 . V_562 ;
struct V_242 * V_242 = F_152 ( V_602 -> V_4 . V_243 ) ;
enum V_604 V_118 = V_605 ;
if ( V_603 <= 0 ) {
F_35 ( L_123 ) ;
return;
}
if ( V_1 == NULL ) {
F_35 ( L_124 ) ;
return;
}
V_199 = F_2 ( V_1 ) ;
V_23 = & V_199 -> V_4 ;
V_242 = F_152 ( V_23 -> V_4 . V_243 ) ;
if ( ! V_242 ) {
F_35 ( L_125 ) ;
return;
}
if ( V_25 -> V_264 . type < V_265 ) {
F_35 ( L_126 ) ;
return;
}
if ( V_1 -> V_244 -> V_37 . V_263 -> V_606 ==
V_603 )
V_118 = V_607 ;
if ( V_118 == V_25 -> V_264 . V_608 ) {
F_35 (
L_127 ) ;
return;
}
if ( ! V_602 -> V_4 . V_500 ) {
F_35 ( L_128 ) ;
return;
}
if ( F_231 ( V_25 ) >= 8 && ! F_37 ( V_25 ) ) {
switch ( V_118 ) {
case V_605 :
F_384 ( V_242 , V_609 ) ;
break;
case V_607 :
F_384 ( V_242 , V_610 ) ;
break;
case V_611 :
default:
F_42 ( L_129 ) ;
}
} else if ( F_231 ( V_25 ) > 6 ) {
T_6 V_612 = F_385 ( V_602 -> V_613 ) ;
T_5 V_411 ;
V_411 = F_32 ( V_612 ) ;
if ( V_118 > V_605 ) {
if ( F_65 ( V_25 ) || F_37 ( V_25 ) )
V_411 |= V_614 ;
else
V_411 |= V_615 ;
} else {
if ( F_65 ( V_25 ) || F_37 ( V_25 ) )
V_411 &= ~ V_614 ;
else
V_411 &= ~ V_615 ;
}
F_43 ( V_612 , V_411 ) ;
}
V_25 -> V_264 . V_608 = V_118 ;
F_35 ( L_130 , V_603 ) ;
}
void F_386 ( struct V_1 * V_1 ,
struct V_204 * V_602 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! V_602 -> V_253 ) {
F_35 ( L_131 ) ;
return;
}
F_25 ( & V_25 -> V_264 . V_616 ) ;
if ( F_48 ( V_25 -> V_264 . V_562 ) ) {
F_42 ( L_132 ) ;
goto V_617;
}
V_25 -> V_264 . V_618 = 0 ;
V_25 -> V_264 . V_562 = V_1 ;
V_617:
F_27 ( & V_25 -> V_264 . V_616 ) ;
}
void F_387 ( struct V_1 * V_1 ,
struct V_204 * V_335 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! V_335 -> V_253 )
return;
F_25 ( & V_25 -> V_264 . V_616 ) ;
if ( ! V_25 -> V_264 . V_562 ) {
F_27 ( & V_25 -> V_264 . V_616 ) ;
return;
}
if ( V_25 -> V_264 . V_608 == V_607 )
F_383 ( V_25 , V_335 ,
V_1 -> V_244 -> V_37 . V_36 -> V_606 ) ;
V_25 -> V_264 . V_562 = NULL ;
F_27 ( & V_25 -> V_264 . V_616 ) ;
F_361 ( & V_25 -> V_264 . V_619 ) ;
}
static void F_388 ( struct V_308 * V_619 )
{
struct V_24 * V_25 =
F_73 ( V_619 , F_74 ( * V_25 ) , V_264 . V_619 . V_619 ) ;
struct V_1 * V_1 ;
F_25 ( & V_25 -> V_264 . V_616 ) ;
V_1 = V_25 -> V_264 . V_562 ;
if ( ! V_1 )
goto V_617;
if ( V_25 -> V_264 . V_618 )
goto V_617;
if ( V_25 -> V_264 . V_608 != V_607 ) {
struct V_620 * V_243 = F_2 ( V_1 ) -> V_4 . V_4 . V_243 ;
F_383 ( V_25 , F_152 ( V_243 ) -> V_621 ,
V_1 -> V_244 -> V_37 . V_263 -> V_606 ) ;
}
V_617:
F_27 ( & V_25 -> V_264 . V_616 ) ;
}
void F_389 ( struct V_24 * V_25 ,
unsigned int V_622 )
{
struct V_620 * V_243 ;
enum V_59 V_59 ;
if ( V_25 -> V_264 . type == V_623 )
return;
F_181 ( & V_25 -> V_264 . V_619 ) ;
F_25 ( & V_25 -> V_264 . V_616 ) ;
if ( ! V_25 -> V_264 . V_562 ) {
F_27 ( & V_25 -> V_264 . V_616 ) ;
return;
}
V_243 = F_2 ( V_25 -> V_264 . V_562 ) -> V_4 . V_4 . V_243 ;
V_59 = F_152 ( V_243 ) -> V_59 ;
V_622 &= F_390 ( V_59 ) ;
V_25 -> V_264 . V_618 |= V_622 ;
if ( V_622 && V_25 -> V_264 . V_608 == V_607 )
F_383 ( V_25 , F_152 ( V_243 ) -> V_621 ,
V_25 -> V_264 . V_562 -> V_244 -> V_37 . V_36 -> V_606 ) ;
F_27 ( & V_25 -> V_264 . V_616 ) ;
}
void F_391 ( struct V_24 * V_25 ,
unsigned int V_622 )
{
struct V_620 * V_243 ;
enum V_59 V_59 ;
if ( V_25 -> V_264 . type == V_623 )
return;
F_181 ( & V_25 -> V_264 . V_619 ) ;
F_25 ( & V_25 -> V_264 . V_616 ) ;
if ( ! V_25 -> V_264 . V_562 ) {
F_27 ( & V_25 -> V_264 . V_616 ) ;
return;
}
V_243 = F_2 ( V_25 -> V_264 . V_562 ) -> V_4 . V_4 . V_243 ;
V_59 = F_152 ( V_243 ) -> V_59 ;
V_622 &= F_390 ( V_59 ) ;
V_25 -> V_264 . V_618 &= ~ V_622 ;
if ( V_622 && V_25 -> V_264 . V_608 == V_607 )
F_383 ( V_25 , F_152 ( V_243 ) -> V_621 ,
V_25 -> V_264 . V_562 -> V_244 -> V_37 . V_36 -> V_606 ) ;
if ( ! V_25 -> V_264 . V_618 )
F_189 ( & V_25 -> V_264 . V_619 ,
F_188 ( 1000 ) ) ;
F_27 ( & V_25 -> V_264 . V_616 ) ;
}
static struct V_33 *
F_392 ( struct V_35 * V_35 ,
struct V_33 * V_36 )
{
struct V_8 * V_9 = & V_35 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_33 * V_263 = NULL ;
F_393 ( & V_25 -> V_264 . V_619 , F_388 ) ;
F_394 ( & V_25 -> V_264 . V_616 ) ;
if ( F_118 ( V_7 ) -> V_192 <= 6 ) {
F_35 ( L_133 ) ;
return NULL ;
}
if ( V_25 -> V_181 . V_624 != V_265 ) {
F_35 ( L_134 ) ;
return NULL ;
}
V_263 = F_395
( V_7 , V_36 , V_9 ) ;
if ( ! V_263 ) {
F_35 ( L_135 ) ;
return NULL ;
}
V_25 -> V_264 . type = V_25 -> V_181 . V_624 ;
V_25 -> V_264 . V_608 = V_605 ;
F_35 ( L_136 ) ;
return V_263 ;
}
static bool F_396 ( struct V_1 * V_1 ,
struct V_35 * V_35 )
{
struct V_8 * V_9 = & V_35 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_22 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_33 * V_36 = NULL ;
struct V_33 * V_263 = NULL ;
bool V_625 ;
struct V_33 * V_626 ;
struct V_473 * V_473 ;
enum V_59 V_59 = V_83 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_397 ( V_7 ) ) {
F_48 ( ! ( F_279 ( V_25 ) || F_167 ( V_25 ) ) ) ;
F_398 ( L_137 ) ;
return false ;
}
F_22 ( V_1 ) ;
F_377 ( V_1 ) ;
F_368 ( V_7 , V_1 ) ;
F_365 ( V_1 ) ;
F_26 ( V_1 ) ;
V_625 = F_283 ( V_1 ) ;
if ( ! V_625 ) {
F_398 ( L_138 ) ;
goto V_627;
}
F_25 ( & V_7 -> V_498 . V_616 ) ;
V_473 = F_330 ( V_9 , & V_1 -> V_158 . V_509 ) ;
if ( V_473 ) {
if ( F_399 ( V_9 , V_473 ) ) {
F_400 ( V_9 ,
V_473 ) ;
F_401 ( V_9 , V_473 ) ;
} else {
F_124 ( V_473 ) ;
V_473 = F_402 ( - V_178 ) ;
}
} else {
V_473 = F_402 ( - V_628 ) ;
}
V_35 -> V_473 = V_473 ;
F_403 (scan, &connector->probed_modes, head) {
if ( ( V_626 -> type & V_629 ) ) {
V_36 = F_341 ( V_7 , V_626 ) ;
V_263 = F_392 (
V_35 , V_36 ) ;
break;
}
}
if ( ! V_36 && V_25 -> V_181 . V_630 ) {
V_36 = F_341 ( V_7 ,
V_25 -> V_181 . V_630 ) ;
if ( V_36 ) {
V_36 -> type |= V_629 ;
V_9 -> V_257 . V_631 = V_36 -> V_631 ;
V_9 -> V_257 . V_632 = V_36 -> V_632 ;
}
}
F_27 ( & V_7 -> V_498 . V_616 ) ;
if ( F_65 ( V_7 ) || F_37 ( V_7 ) ) {
V_1 -> V_104 . V_563 = F_72 ;
F_404 ( & V_1 -> V_104 ) ;
if ( F_37 ( V_7 ) )
V_59 = F_222 ( V_1 -> V_67 ) ;
else
V_59 = F_223 ( V_1 -> V_67 ) ;
if ( V_59 != V_82 && V_59 != V_75 )
V_59 = V_1 -> V_60 ;
if ( V_59 != V_82 && V_59 != V_75 )
V_59 = V_82 ;
F_35 ( L_139 ,
F_33 ( V_59 ) ) ;
}
F_405 ( & V_35 -> V_37 , V_36 , V_263 ) ;
V_35 -> V_37 . V_633 . V_634 = F_201 ;
F_406 ( V_9 , V_59 ) ;
return true ;
V_627:
F_361 ( & V_1 -> V_305 ) ;
F_22 ( V_1 ) ;
F_184 ( V_1 ) ;
F_26 ( V_1 ) ;
return false ;
}
bool
F_407 ( struct V_2 * V_3 ,
struct V_35 * V_35 )
{
struct V_8 * V_9 = & V_35 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_562 ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_22 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_70 = V_3 -> V_70 ;
int type ;
if ( F_8 ( V_3 -> V_18 < 1 ,
L_140 ,
V_3 -> V_18 , F_34 ( V_70 ) ) )
return false ;
V_1 -> V_60 = V_83 ;
if ( F_118 ( V_7 ) -> V_192 >= 9 )
V_1 -> V_149 = F_89 ;
else if ( F_131 ( V_7 ) || F_92 ( V_7 ) )
V_1 -> V_149 = F_87 ;
else if ( F_119 ( V_7 ) )
V_1 -> V_149 = F_86 ;
else
V_1 -> V_149 = F_84 ;
if ( F_118 ( V_7 ) -> V_192 >= 9 )
V_1 -> V_151 = F_93 ;
else
V_1 -> V_151 = F_90 ;
if ( F_153 ( V_7 ) )
V_1 -> V_635 = V_636 ;
V_1 -> V_67 = F_32 ( V_1 -> V_68 ) ;
V_1 -> V_244 = V_35 ;
if ( F_370 ( V_7 , V_70 ) )
type = V_560 ;
else
type = V_637 ;
if ( type == V_560 )
V_22 -> type = V_5 ;
if ( F_48 ( ( F_65 ( V_7 ) || F_37 ( V_7 ) ) &&
F_1 ( V_1 ) && V_70 != V_187 && V_70 != V_189 ) )
return false ;
F_35 ( L_141 ,
type == V_560 ? L_142 : L_143 ,
F_34 ( V_70 ) ) ;
F_408 ( V_7 , V_9 , & V_638 , type ) ;
F_409 ( V_9 , & V_639 ) ;
V_9 -> V_640 = true ;
V_9 -> V_641 = 0 ;
F_125 ( V_1 ) ;
F_393 ( & V_1 -> V_305 ,
F_185 ) ;
F_410 ( V_35 , V_22 ) ;
if ( F_153 ( V_7 ) )
V_35 -> V_642 = V_643 ;
else
V_35 -> V_642 = V_644 ;
switch ( V_70 ) {
case V_120 :
V_22 -> V_532 = V_645 ;
break;
case V_187 :
V_22 -> V_532 = V_646 ;
if ( F_411 ( V_7 , 0 , V_647 ) )
V_22 -> V_532 = V_645 ;
break;
case V_189 :
V_22 -> V_532 = V_648 ;
break;
case V_191 :
V_22 -> V_532 = V_649 ;
break;
case V_523 :
V_22 -> V_532 = V_650 ;
break;
default:
F_412 () ;
}
if ( F_413 ( V_7 ) && ! F_1 ( V_1 ) &&
( V_70 == V_187 || V_70 == V_189 || V_70 == V_191 ) )
F_414 ( V_3 ,
V_35 -> V_4 . V_4 . V_544 ) ;
if ( ! F_396 ( V_1 , V_35 ) ) {
F_123 ( V_1 ) ;
F_360 ( V_3 ) ;
goto V_651;
}
F_372 ( V_1 , V_9 ) ;
if ( F_137 ( V_7 ) && ! F_326 ( V_7 ) ) {
T_5 V_341 = F_32 ( V_652 ) ;
F_43 ( V_652 , ( V_341 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_651:
F_357 ( V_9 ) ;
return false ;
}
bool F_415 ( struct V_6 * V_7 ,
T_6 V_68 ,
enum V_70 V_70 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_2 * V_3 ;
struct V_22 * V_22 ;
struct V_561 * V_23 ;
struct V_35 * V_35 ;
V_3 = F_416 ( sizeof( * V_3 ) , V_194 ) ;
if ( ! V_3 )
return false ;
V_35 = F_417 () ;
if ( ! V_35 )
goto V_653;
V_22 = & V_3 -> V_4 ;
V_23 = & V_22 -> V_4 ;
if ( F_418 ( V_7 , & V_22 -> V_4 , & V_654 ,
V_655 , L_144 , F_34 ( V_70 ) ) )
goto V_656;
V_22 -> V_657 = F_151 ;
V_22 -> V_658 = F_227 ;
V_22 -> V_642 = F_215 ;
V_22 -> V_659 = F_224 ;
V_22 -> V_660 = F_364 ;
if ( F_37 ( V_7 ) ) {
V_22 -> V_661 = F_261 ;
V_22 -> V_662 = F_258 ;
V_22 -> V_314 = F_250 ;
V_22 -> V_663 = F_235 ;
V_22 -> V_664 = F_263 ;
} else if ( F_65 ( V_7 ) ) {
V_22 -> V_661 = F_256 ;
V_22 -> V_662 = F_254 ;
V_22 -> V_314 = F_250 ;
V_22 -> V_663 = F_234 ;
} else {
V_22 -> V_662 = F_252 ;
V_22 -> V_314 = F_249 ;
if ( F_118 ( V_7 ) -> V_192 >= 5 )
V_22 -> V_663 = F_233 ;
}
V_3 -> V_70 = V_70 ;
V_3 -> V_562 . V_68 = V_68 ;
V_3 -> V_18 = 4 ;
V_22 -> type = V_541 ;
if ( F_37 ( V_7 ) ) {
if ( V_70 == V_191 )
V_22 -> V_665 = 1 << 2 ;
else
V_22 -> V_665 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_22 -> V_665 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_22 -> V_666 = 0 ;
V_3 -> V_667 = F_369 ;
V_25 -> V_668 . V_669 [ V_70 ] = V_3 ;
if ( ! F_407 ( V_3 , V_35 ) )
goto V_670;
return true ;
V_670:
F_363 ( V_23 ) ;
V_656:
F_124 ( V_35 ) ;
V_653:
F_124 ( V_3 ) ;
return false ;
}
void F_419 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_671 ; V_52 ++ ) {
struct V_2 * V_3 = V_25 -> V_668 . V_669 [ V_52 ] ;
if ( ! V_3 || ! V_3 -> V_562 . V_446 )
continue;
if ( V_3 -> V_562 . V_449 )
F_420 ( & V_3 -> V_562 . V_450 ) ;
}
}
void F_421 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_671 ; V_52 ++ ) {
struct V_2 * V_3 = V_25 -> V_668 . V_669 [ V_52 ] ;
int V_140 ;
if ( ! V_3 || ! V_3 -> V_562 . V_446 )
continue;
V_140 = F_422 ( & V_3 -> V_562 . V_450 ) ;
if ( V_140 )
F_306 ( & V_3 -> V_562 ) ;
}
}
