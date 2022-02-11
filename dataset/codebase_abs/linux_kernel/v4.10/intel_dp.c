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
static int
F_17 ( struct V_1 * V_1 , const int * * V_32 )
{
if ( V_1 -> V_33 ) {
* V_32 = V_1 -> V_32 ;
return V_1 -> V_33 ;
}
* V_32 = V_34 ;
return ( F_7 ( V_1 ) >> 3 ) + 1 ;
}
static int
F_18 ( struct V_1 * V_1 , const int * * V_35 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
int V_37 ;
if ( F_19 ( V_25 ) ) {
* V_35 = V_38 ;
V_37 = F_20 ( V_38 ) ;
} else if ( F_21 ( V_25 ) || F_22 ( V_25 ) ) {
* V_35 = V_39 ;
V_37 = F_20 ( V_39 ) ;
} else {
* V_35 = V_34 ;
V_37 = F_20 ( V_34 ) ;
}
if ( ! F_23 ( V_1 ) )
V_37 -- ;
return V_37 ;
}
static int F_24 ( const int * V_35 , int V_40 ,
const int * V_32 , int V_41 ,
int * V_42 )
{
int V_43 = 0 , V_44 = 0 , V_45 = 0 ;
while ( V_43 < V_40 && V_44 < V_41 ) {
if ( V_35 [ V_43 ] == V_32 [ V_44 ] ) {
if ( F_25 ( V_45 >= V_46 ) )
return V_45 ;
V_42 [ V_45 ] = V_35 [ V_43 ] ;
++ V_45 ;
++ V_43 ;
++ V_44 ;
} else if ( V_35 [ V_43 ] < V_32 [ V_44 ] ) {
++ V_43 ;
} else {
++ V_44 ;
}
}
return V_45 ;
}
static int F_26 ( struct V_1 * V_1 ,
int * V_42 )
{
const int * V_35 , * V_32 ;
int V_40 , V_41 ;
V_41 = F_17 ( V_1 , & V_32 ) ;
V_40 = F_18 ( V_1 , & V_35 ) ;
return F_24 ( V_35 , V_40 ,
V_32 , V_41 ,
V_42 ) ;
}
static enum V_47
F_27 ( struct V_8 * V_9 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_50 * V_50 = F_28 ( V_9 ) ;
struct V_48 * V_51 = V_50 -> V_52 . V_51 ;
int V_53 = V_49 -> clock ;
int V_54 , V_55 , V_18 , V_21 ;
int V_26 ;
V_26 = F_14 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_51 ) {
if ( V_49 -> V_56 > V_51 -> V_56 )
return V_57 ;
if ( V_49 -> V_58 > V_51 -> V_58 )
return V_57 ;
V_53 = V_51 -> clock ;
}
V_21 = F_29 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
V_54 = F_13 ( V_21 , V_18 ) ;
V_55 = F_12 ( V_53 , 18 ) ;
if ( V_55 > V_54 || V_53 > V_26 )
return V_59 ;
if ( V_49 -> clock < 10000 )
return V_60 ;
if ( V_49 -> V_61 & V_62 )
return V_63 ;
return V_64 ;
}
T_2 F_30 ( const T_3 * V_65 , int V_66 )
{
int V_43 ;
T_2 V_67 = 0 ;
if ( V_66 > 4 )
V_66 = 4 ;
for ( V_43 = 0 ; V_43 < V_66 ; V_43 ++ )
V_67 |= ( ( T_2 ) V_65 [ V_43 ] ) << ( ( 3 - V_43 ) * 8 ) ;
return V_67 ;
}
static void F_31 ( T_2 V_65 , T_3 * V_68 , int V_69 )
{
int V_43 ;
if ( V_69 > 4 )
V_69 = 4 ;
for ( V_43 = 0 ; V_43 < V_69 ; V_43 ++ )
V_68 [ V_43 ] = V_65 >> ( ( 3 - V_43 ) * 8 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
V_71 = F_33 ( V_23 ) ;
F_34 ( V_25 , V_71 ) ;
F_35 ( & V_25 -> V_72 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
F_37 ( & V_25 -> V_72 ) ;
V_71 = F_33 ( V_23 ) ;
F_38 ( V_25 , V_71 ) ;
}
static void
F_39 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_73 V_73 = V_1 -> V_74 ;
bool V_75 , V_76 = false ;
enum V_77 V_78 = F_40 ( V_73 ) ;
enum V_79 V_80 = F_41 ( V_73 ) ;
T_2 V_81 ;
if ( F_8 ( F_42 ( V_1 -> V_82 ) & V_83 ,
L_2 ,
F_43 ( V_73 ) , F_44 ( V_3 -> V_84 ) ) )
return;
F_45 ( L_3 ,
F_43 ( V_73 ) , F_44 ( V_3 -> V_84 ) ) ;
V_81 = F_42 ( V_1 -> V_82 ) & V_85 ;
V_81 |= V_86 | V_87 ;
V_81 |= F_46 ( 1 ) ;
V_81 |= V_88 ;
if ( F_47 ( V_25 ) )
V_81 |= F_48 ( V_73 ) ;
else if ( V_73 == V_89 )
V_81 |= V_90 ;
V_75 = F_42 ( F_49 ( V_73 ) ) & V_91 ;
if ( ! V_75 ) {
V_76 = F_47 ( V_25 ) &&
! F_50 ( V_25 , V_78 , V_80 , true ) ;
if ( F_51 ( V_25 , V_73 , F_47 ( V_25 ) ?
& V_92 [ 0 ] . V_93 : & V_94 [ 0 ] . V_93 ) ) {
F_52 ( L_4 ,
F_43 ( V_73 ) ) ;
return;
}
}
F_53 ( V_1 -> V_82 , V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
F_53 ( V_1 -> V_82 , V_81 | V_83 ) ;
F_54 ( V_1 -> V_82 ) ;
F_53 ( V_1 -> V_82 , V_81 & ~ V_83 ) ;
F_54 ( V_1 -> V_82 ) ;
if ( ! V_75 ) {
F_55 ( V_25 , V_73 ) ;
if ( V_76 )
F_50 ( V_25 , V_78 , V_80 , false ) ;
}
}
static enum V_73
F_56 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_22 * V_23 ;
unsigned int V_95 = ( 1 << V_96 ) | ( 1 << V_89 ) ;
enum V_73 V_73 ;
F_57 ( & V_25 -> V_72 ) ;
F_25 ( ! F_1 ( V_1 ) ) ;
if ( V_1 -> V_74 != V_97 )
return V_1 -> V_74 ;
F_58 (dev, encoder) {
struct V_1 * V_98 ;
if ( V_23 -> type != V_5 )
continue;
V_98 = F_5 ( & V_23 -> V_4 ) ;
if ( V_98 -> V_74 != V_97 )
V_95 &= ~ ( 1 << V_98 -> V_74 ) ;
}
if ( F_25 ( V_95 == 0 ) )
V_73 = V_96 ;
else
V_73 = F_59 ( V_95 ) - 1 ;
F_60 ( V_7 , V_73 ) ;
V_1 -> V_74 = V_73 ;
F_45 ( L_5 ,
F_43 ( V_1 -> V_74 ) ,
F_44 ( V_3 -> V_84 ) ) ;
F_61 ( V_7 , V_1 ) ;
F_62 ( V_7 , V_1 , true ) ;
F_39 ( V_1 ) ;
return V_1 -> V_74 ;
}
static int
F_63 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_57 ( & V_25 -> V_72 ) ;
F_25 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_99 )
return 0 ;
V_1 -> V_99 = false ;
F_62 ( V_7 , V_1 , false ) ;
return 0 ;
}
static bool F_64 ( struct V_24 * V_25 ,
enum V_73 V_73 )
{
return F_42 ( F_65 ( V_73 ) ) & V_100 ;
}
static bool F_66 ( struct V_24 * V_25 ,
enum V_73 V_73 )
{
return F_42 ( F_67 ( V_73 ) ) & V_101 ;
}
static bool F_68 ( struct V_24 * V_25 ,
enum V_73 V_73 )
{
return true ;
}
static enum V_73
F_69 ( struct V_24 * V_25 ,
enum V_84 V_84 ,
T_4 V_102 )
{
enum V_73 V_73 ;
for ( V_73 = V_96 ; V_73 <= V_89 ; V_73 ++ ) {
T_5 V_103 = F_42 ( F_70 ( V_73 ) ) &
V_104 ;
if ( V_103 != F_71 ( V_84 ) )
continue;
if ( ! V_102 ( V_25 , V_73 ) )
continue;
return V_73 ;
}
return V_97 ;
}
static void
F_72 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
F_57 ( & V_25 -> V_72 ) ;
V_1 -> V_74 = F_69 ( V_25 , V_84 ,
F_64 ) ;
if ( V_1 -> V_74 == V_97 )
V_1 -> V_74 = F_69 ( V_25 , V_84 ,
F_66 ) ;
if ( V_1 -> V_74 == V_97 )
V_1 -> V_74 = F_69 ( V_25 , V_84 ,
F_68 ) ;
if ( V_1 -> V_74 == V_97 ) {
F_45 ( L_6 ,
F_44 ( V_84 ) ) ;
return;
}
F_45 ( L_7 ,
F_44 ( V_84 ) , F_43 ( V_1 -> V_74 ) ) ;
F_61 ( V_7 , V_1 ) ;
F_62 ( V_7 , V_1 , false ) ;
}
void F_73 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = & V_25 -> V_105 ;
struct V_22 * V_23 ;
if ( F_25 ( ! F_74 ( V_25 ) && ! F_47 ( V_25 ) &&
! F_19 ( V_25 ) ) )
return;
F_58 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_23 -> type != V_5 )
continue;
V_1 = F_5 ( & V_23 -> V_4 ) ;
if ( F_19 ( V_25 ) )
V_1 -> V_99 = true ;
else
V_1 -> V_74 = V_97 ;
}
}
static void F_75 ( struct V_24 * V_25 ,
struct V_1 * V_1 ,
struct V_106 * V_107 )
{
int V_108 = 0 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
if ( F_19 ( V_25 ) )
V_108 = F_63 ( V_1 ) ;
else if ( F_74 ( V_25 ) || F_47 ( V_25 ) )
V_108 = F_56 ( V_1 ) ;
V_107 -> V_109 = F_67 ( V_108 ) ;
V_107 -> V_110 = F_65 ( V_108 ) ;
V_107 -> V_111 = F_70 ( V_108 ) ;
V_107 -> V_112 = F_76 ( V_108 ) ;
if ( ! F_19 ( V_25 ) )
V_107 -> V_113 = F_77 ( V_108 ) ;
}
static T_6
F_78 ( struct V_1 * V_1 )
{
struct V_106 V_107 ;
F_75 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_107 ) ;
return V_107 . V_109 ;
}
static T_6
F_79 ( struct V_1 * V_1 )
{
struct V_106 V_107 ;
F_75 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_107 ) ;
return V_107 . V_110 ;
}
static int F_80 ( struct V_114 * V_115 , unsigned long V_116 ,
void * V_117 )
{
struct V_1 * V_1 = F_81 ( V_115 , F_82 ( * V_1 ) ,
V_118 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_116 != V_119 )
return 0 ;
F_32 ( V_1 ) ;
if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
enum V_73 V_73 = F_56 ( V_1 ) ;
T_6 V_120 , V_121 ;
T_5 V_113 ;
V_120 = F_67 ( V_73 ) ;
V_121 = F_77 ( V_73 ) ;
V_113 = F_42 ( V_121 ) ;
V_113 &= V_122 ;
F_53 ( V_121 , V_113 | 0x1F ) ;
F_53 ( V_120 , V_123 | V_124 ) ;
F_83 ( V_1 -> V_125 ) ;
}
F_36 ( V_1 ) ;
return 0 ;
}
static bool F_84 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_57 ( & V_25 -> V_72 ) ;
if ( ( F_74 ( V_25 ) || F_47 ( V_25 ) ) &&
V_1 -> V_74 == V_97 )
return false ;
return ( F_42 ( F_79 ( V_1 ) ) & V_100 ) != 0 ;
}
static bool F_85 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_57 ( & V_25 -> V_72 ) ;
if ( ( F_74 ( V_25 ) || F_47 ( V_25 ) ) &&
V_1 -> V_74 == V_97 )
return false ;
return F_42 ( F_78 ( V_1 ) ) & V_101 ;
}
static void
F_86 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_84 ( V_1 ) && ! F_85 ( V_1 ) ) {
F_8 ( 1 , L_8 ) ;
F_45 ( L_9 ,
F_42 ( F_79 ( V_1 ) ) ,
F_42 ( F_78 ( V_1 ) ) ) ;
}
}
static T_2
F_87 ( struct V_1 * V_1 , bool V_126 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_6 V_127 = V_1 -> V_128 ;
T_2 V_129 ;
bool V_130 ;
#define F_88 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_126 )
V_130 = F_89 ( V_25 -> V_131 , F_88 ,
F_90 ( 10 ) ) ;
else
V_130 = F_91 ( F_88 , 10 ) == 0 ;
if ( ! V_130 )
F_52 ( L_10 ,
V_126 ) ;
#undef F_88
return V_129 ;
}
static T_2 F_92 ( struct V_1 * V_1 , int V_132 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_132 )
return 0 ;
return F_93 ( V_25 -> V_133 , 2000 ) ;
}
static T_2 F_94 ( struct V_1 * V_1 , int V_132 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_132 )
return 0 ;
if ( V_3 -> V_84 == V_134 )
return F_93 ( V_25 -> V_135 , 2000 ) ;
else
return F_93 ( V_25 -> V_133 , 2000 ) ;
}
static T_2 F_95 ( struct V_1 * V_1 , int V_132 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_84 != V_134 && F_96 ( V_25 ) ) {
switch ( V_132 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_94 ( V_1 , V_132 ) ;
}
static T_2 F_97 ( struct V_1 * V_1 , int V_132 )
{
return V_132 ? 0 : 1 ;
}
static T_2 F_98 ( struct V_1 * V_1 ,
bool V_126 ,
int V_136 ,
T_2 V_137 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_2 V_138 , V_139 ;
if ( F_99 ( V_25 ) )
V_138 = 3 ;
else
V_138 = 5 ;
if ( F_100 ( V_25 ) && V_3 -> V_84 == V_134 )
V_139 = V_140 ;
else
V_139 = V_141 ;
return V_142 |
V_143 |
( V_126 ? V_144 : 0 ) |
V_145 |
V_139 |
V_146 |
( V_136 << V_147 ) |
( V_138 << V_148 ) |
( V_137 << V_149 ) ;
}
static T_2 F_101 ( struct V_1 * V_1 ,
bool V_126 ,
int V_136 ,
T_2 V_117 )
{
return V_142 |
V_143 |
( V_126 ? V_144 : 0 ) |
V_145 |
V_150 |
V_146 |
( V_136 << V_147 ) |
F_102 ( 32 ) |
F_103 ( 32 ) ;
}
static int
F_104 ( struct V_1 * V_1 ,
const T_3 * V_151 , int V_136 ,
T_3 * V_152 , int V_153 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_6 V_127 = V_1 -> V_128 ;
T_2 V_137 ;
int V_43 , V_154 , V_155 ;
T_2 V_129 ;
int V_156 , clock = 0 ;
bool V_126 = F_105 ( V_25 ) ;
bool V_157 ;
F_32 ( V_1 ) ;
V_157 = F_106 ( V_1 ) ;
F_107 ( & V_25 -> V_158 , 0 ) ;
F_86 ( V_1 ) ;
for ( V_156 = 0 ; V_156 < 3 ; V_156 ++ ) {
V_129 = F_108 ( V_127 ) ;
if ( ( V_129 & V_142 ) == 0 )
break;
F_83 ( 1 ) ;
}
if ( V_156 == 3 ) {
static T_5 V_159 = - 1 ;
const T_5 V_129 = F_42 ( V_127 ) ;
if ( V_129 != V_159 ) {
F_8 ( 1 , L_11 ,
V_129 ) ;
V_159 = V_129 ;
}
V_154 = - V_160 ;
goto V_161;
}
if ( F_25 ( V_136 > 20 || V_153 > 20 ) ) {
V_154 = - V_162 ;
goto V_161;
}
while ( ( V_137 = V_1 -> V_163 ( V_1 , clock ++ ) ) ) {
T_5 V_164 = V_1 -> V_165 ( V_1 ,
V_126 ,
V_136 ,
V_137 ) ;
for ( V_156 = 0 ; V_156 < 5 ; V_156 ++ ) {
for ( V_43 = 0 ; V_43 < V_136 ; V_43 += 4 )
F_53 ( V_1 -> V_166 [ V_43 >> 2 ] ,
F_30 ( V_151 + V_43 ,
V_136 - V_43 ) ) ;
F_53 ( V_127 , V_164 ) ;
V_129 = F_87 ( V_1 , V_126 ) ;
F_53 ( V_127 ,
V_129 |
V_143 |
V_145 |
V_146 ) ;
if ( V_129 & V_145 )
continue;
if ( V_129 & V_146 ) {
F_109 ( 400 , 500 ) ;
continue;
}
if ( V_129 & V_143 )
goto V_130;
}
}
if ( ( V_129 & V_143 ) == 0 ) {
F_52 ( L_12 , V_129 ) ;
V_154 = - V_160 ;
goto V_161;
}
V_130:
if ( V_129 & V_146 ) {
F_52 ( L_13 , V_129 ) ;
V_154 = - V_167 ;
goto V_161;
}
if ( V_129 & V_145 ) {
F_45 ( L_14 , V_129 ) ;
V_154 = - V_168 ;
goto V_161;
}
V_155 = ( ( V_129 & V_169 ) >>
V_147 ) ;
if ( V_155 == 0 || V_155 > 20 ) {
F_45 ( L_15 ,
V_155 ) ;
F_109 ( 1000 , 1500 ) ;
V_154 = - V_160 ;
goto V_161;
}
if ( V_155 > V_153 )
V_155 = V_153 ;
for ( V_43 = 0 ; V_43 < V_155 ; V_43 += 4 )
F_31 ( F_42 ( V_1 -> V_166 [ V_43 >> 2 ] ) ,
V_152 + V_43 , V_155 - V_43 ) ;
V_154 = V_155 ;
V_161:
F_107 ( & V_25 -> V_158 , V_170 ) ;
if ( V_157 )
F_110 ( V_1 , false ) ;
F_36 ( V_1 ) ;
return V_154 ;
}
static T_7
F_111 ( struct V_171 * V_172 , struct V_173 * V_174 )
{
struct V_1 * V_1 = F_81 ( V_172 , struct V_1 , V_172 ) ;
T_3 V_175 [ 20 ] , V_176 [ 20 ] ;
T_8 V_177 , V_178 ;
int V_154 ;
V_175 [ 0 ] = ( V_174 -> V_179 << 4 ) |
( ( V_174 -> V_180 >> 16 ) & 0xf ) ;
V_175 [ 1 ] = ( V_174 -> V_180 >> 8 ) & 0xff ;
V_175 [ 2 ] = V_174 -> V_180 & 0xff ;
V_175 [ 3 ] = V_174 -> V_37 - 1 ;
switch ( V_174 -> V_179 & ~ V_181 ) {
case V_182 :
case V_183 :
case V_184 :
V_177 = V_174 -> V_37 ? V_185 + V_174 -> V_37 : V_186 ;
V_178 = 2 ;
if ( F_25 ( V_177 > 20 ) )
return - V_162 ;
F_25 ( ! V_174 -> V_187 != ! V_174 -> V_37 ) ;
if ( V_174 -> V_187 )
memcpy ( V_175 + V_185 , V_174 -> V_187 , V_174 -> V_37 ) ;
V_154 = F_104 ( V_1 , V_175 , V_177 , V_176 , V_178 ) ;
if ( V_154 > 0 ) {
V_174 -> V_188 = V_176 [ 0 ] >> 4 ;
if ( V_154 > 1 ) {
V_154 = F_112 ( int , V_176 [ 1 ] , 0 , V_174 -> V_37 ) ;
} else {
V_154 = V_174 -> V_37 ;
}
}
break;
case V_189 :
case V_190 :
V_177 = V_174 -> V_37 ? V_185 : V_186 ;
V_178 = V_174 -> V_37 + 1 ;
if ( F_25 ( V_178 > 20 ) )
return - V_162 ;
V_154 = F_104 ( V_1 , V_175 , V_177 , V_176 , V_178 ) ;
if ( V_154 > 0 ) {
V_174 -> V_188 = V_176 [ 0 ] >> 4 ;
V_154 -- ;
memcpy ( V_174 -> V_187 , V_176 + 1 , V_154 ) ;
}
break;
default:
V_154 = - V_191 ;
break;
}
return V_154 ;
}
static enum V_84 F_113 ( struct V_24 * V_25 ,
enum V_84 V_84 )
{
const struct V_192 * V_193 =
& V_25 -> V_194 . V_195 [ V_84 ] ;
enum V_84 V_196 ;
if ( ! V_193 -> V_197 ) {
F_45 ( L_16 ,
F_44 ( V_84 ) , F_44 ( V_84 ) ) ;
return V_84 ;
}
switch ( V_193 -> V_197 ) {
case V_198 :
V_196 = V_134 ;
break;
case V_199 :
V_196 = V_200 ;
break;
case V_201 :
V_196 = V_202 ;
break;
case V_203 :
V_196 = V_204 ;
break;
default:
F_114 ( V_193 -> V_197 ) ;
V_196 = V_134 ;
break;
}
F_45 ( L_17 ,
F_44 ( V_196 ) , F_44 ( V_84 ) ) ;
return V_196 ;
}
static T_6 F_115 ( struct V_24 * V_25 ,
enum V_84 V_84 )
{
switch ( V_84 ) {
case V_200 :
case V_202 :
case V_204 :
return F_116 ( V_84 ) ;
default:
F_114 ( V_84 ) ;
return F_116 ( V_200 ) ;
}
}
static T_6 F_117 ( struct V_24 * V_25 ,
enum V_84 V_84 , int V_132 )
{
switch ( V_84 ) {
case V_200 :
case V_202 :
case V_204 :
return F_118 ( V_84 , V_132 ) ;
default:
F_114 ( V_84 ) ;
return F_118 ( V_200 , V_132 ) ;
}
}
static T_6 F_119 ( struct V_24 * V_25 ,
enum V_84 V_84 )
{
switch ( V_84 ) {
case V_134 :
return F_116 ( V_84 ) ;
case V_200 :
case V_202 :
case V_204 :
return F_120 ( V_84 ) ;
default:
F_114 ( V_84 ) ;
return F_116 ( V_134 ) ;
}
}
static T_6 F_121 ( struct V_24 * V_25 ,
enum V_84 V_84 , int V_132 )
{
switch ( V_84 ) {
case V_134 :
return F_118 ( V_84 , V_132 ) ;
case V_200 :
case V_202 :
case V_204 :
return F_122 ( V_84 , V_132 ) ;
default:
F_114 ( V_84 ) ;
return F_118 ( V_134 , V_132 ) ;
}
}
static T_6 F_123 ( struct V_24 * V_25 ,
enum V_84 V_84 )
{
switch ( V_84 ) {
case V_134 :
case V_200 :
case V_202 :
case V_204 :
return F_116 ( V_84 ) ;
default:
F_114 ( V_84 ) ;
return F_116 ( V_134 ) ;
}
}
static T_6 F_124 ( struct V_24 * V_25 ,
enum V_84 V_84 , int V_132 )
{
switch ( V_84 ) {
case V_134 :
case V_200 :
case V_202 :
case V_204 :
return F_118 ( V_84 , V_132 ) ;
default:
F_114 ( V_84 ) ;
return F_118 ( V_134 , V_132 ) ;
}
}
static T_6 F_125 ( struct V_24 * V_25 ,
enum V_84 V_84 )
{
if ( F_126 ( V_25 ) -> V_205 >= 9 )
return F_123 ( V_25 , V_84 ) ;
else if ( F_127 ( V_25 ) )
return F_119 ( V_25 , V_84 ) ;
else
return F_115 ( V_25 , V_84 ) ;
}
static T_6 F_128 ( struct V_24 * V_25 ,
enum V_84 V_84 , int V_132 )
{
if ( F_126 ( V_25 ) -> V_205 >= 9 )
return F_124 ( V_25 , V_84 , V_132 ) ;
else if ( F_127 ( V_25 ) )
return F_121 ( V_25 , V_84 , V_132 ) ;
else
return F_117 ( V_25 , V_84 , V_132 ) ;
}
static void F_129 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
enum V_84 V_84 = F_113 ( V_25 ,
F_2 ( V_1 ) -> V_84 ) ;
int V_43 ;
V_1 -> V_128 = F_125 ( V_25 , V_84 ) ;
for ( V_43 = 0 ; V_43 < F_20 ( V_1 -> V_166 ) ; V_43 ++ )
V_1 -> V_166 [ V_43 ] = F_128 ( V_25 , V_84 , V_43 ) ;
}
static void
F_130 ( struct V_1 * V_1 )
{
F_131 ( V_1 -> V_172 . V_206 ) ;
}
static void
F_132 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
F_129 ( V_1 ) ;
F_133 ( & V_1 -> V_172 ) ;
V_1 -> V_172 . V_206 = F_134 ( V_207 , L_18 , F_44 ( V_84 ) ) ;
V_1 -> V_172 . V_208 = F_111 ;
}
bool F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
if ( ( F_135 ( V_25 ) && ! F_136 ( V_25 ) ) ||
F_100 ( V_25 ) || ( F_137 ( V_25 ) >= 9 ) )
return true ;
else
return false ;
}
static void
F_138 ( struct V_22 * V_23 ,
struct V_209 * V_210 )
{
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
const struct V_211 * V_212 = NULL ;
int V_43 , V_213 = 0 ;
if ( F_139 ( V_25 ) ) {
V_212 = V_214 ;
V_213 = F_20 ( V_214 ) ;
} else if ( F_127 ( V_25 ) ) {
V_212 = V_215 ;
V_213 = F_20 ( V_215 ) ;
} else if ( F_47 ( V_25 ) ) {
V_212 = V_92 ;
V_213 = F_20 ( V_92 ) ;
} else if ( F_74 ( V_25 ) ) {
V_212 = V_94 ;
V_213 = F_20 ( V_94 ) ;
}
if ( V_212 && V_213 ) {
for ( V_43 = 0 ; V_43 < V_213 ; V_43 ++ ) {
if ( V_210 -> V_216 == V_212 [ V_43 ] . clock ) {
V_210 -> V_93 = V_212 [ V_43 ] . V_93 ;
V_210 -> V_217 = true ;
break;
}
}
}
}
static void F_140 ( char * V_218 , T_8 V_219 ,
const int * V_220 , int V_221 )
{
int V_43 ;
V_218 [ 0 ] = '\0' ;
for ( V_43 = 0 ; V_43 < V_221 ; V_43 ++ ) {
int V_222 = snprintf ( V_218 , V_219 , L_19 , V_43 ? L_20 : L_21 , V_220 [ V_43 ] ) ;
if ( V_222 >= V_219 )
return;
V_218 += V_222 ;
V_219 -= V_222 ;
}
}
static void F_141 ( struct V_1 * V_1 )
{
const int * V_35 , * V_32 ;
int V_40 , V_41 , V_223 ;
int V_42 [ V_46 ] ;
char V_218 [ 128 ] ;
if ( ( V_224 & V_225 ) == 0 )
return;
V_40 = F_18 ( V_1 , & V_35 ) ;
F_140 ( V_218 , sizeof( V_218 ) , V_35 , V_40 ) ;
F_45 ( L_22 , V_218 ) ;
V_41 = F_17 ( V_1 , & V_32 ) ;
F_140 ( V_218 , sizeof( V_218 ) , V_32 , V_41 ) ;
F_45 ( L_23 , V_218 ) ;
V_223 = F_26 ( V_1 , V_42 ) ;
F_140 ( V_218 , sizeof( V_218 ) , V_42 , V_223 ) ;
F_45 ( L_24 , V_218 ) ;
}
bool
F_142 ( struct V_1 * V_1 , struct V_226 * V_227 )
{
T_5 V_4 = F_143 ( V_1 -> V_11 ) ? V_228 :
V_229 ;
return F_144 ( & V_1 -> V_172 , V_4 , V_227 , sizeof( * V_227 ) ) ==
sizeof( * V_227 ) ;
}
bool F_145 ( struct V_1 * V_1 )
{
struct V_226 * V_227 = & V_1 -> V_227 ;
bool V_230 = V_1 -> V_11 [ V_231 ] &
V_232 ;
int V_233 ;
if ( ! F_142 ( V_1 , V_227 ) )
return false ;
V_233 = F_146 ( V_227 -> V_234 , sizeof( V_227 -> V_234 ) ) ;
F_45 ( L_25 ,
F_143 ( V_1 -> V_11 ) ? L_26 : L_27 ,
( int ) sizeof( V_227 -> V_235 ) , V_227 -> V_235 , V_230 ? L_21 : L_28 ,
V_233 , V_227 -> V_234 ,
V_227 -> V_236 >> 4 , V_227 -> V_236 & 0xf ,
V_227 -> V_237 , V_227 -> V_238 ) ;
return true ;
}
static int F_147 ( int V_239 , const int * V_240 )
{
int V_43 = 0 ;
for ( V_43 = 0 ; V_43 < V_46 ; ++ V_43 )
if ( V_239 == V_240 [ V_43 ] )
break;
return V_43 ;
}
int
F_29 ( struct V_1 * V_1 )
{
int V_240 [ V_46 ] = {} ;
int V_219 ;
V_219 = F_26 ( V_1 , V_240 ) ;
if ( F_25 ( V_219 <= 0 ) )
return 162000 ;
return V_240 [ V_219 - 1 ] ;
}
int F_148 ( struct V_1 * V_1 , int V_241 )
{
return F_147 ( V_241 , V_1 -> V_32 ) ;
}
void F_149 ( struct V_1 * V_1 , int V_216 ,
T_3 * V_242 , T_3 * V_243 )
{
if ( V_1 -> V_33 ) {
* V_242 = 0 ;
* V_243 =
F_148 ( V_1 , V_216 ) ;
} else {
* V_242 = F_150 ( V_216 ) ;
* V_243 = 0 ;
}
}
static int F_151 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
int V_20 , V_244 ;
V_20 = V_210 -> V_245 ;
V_244 = F_152 ( V_1 -> V_11 , V_1 -> V_29 ) ;
if ( V_244 > 0 )
V_20 = F_11 ( V_20 , 3 * V_244 ) ;
return V_20 ;
}
bool
F_153 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
struct V_24 * V_25 = F_15 ( V_23 -> V_4 . V_7 ) ;
struct V_48 * V_248 = & V_210 -> V_4 . V_248 ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
struct V_249 * V_249 = F_154 ( V_210 -> V_4 . V_250 ) ;
struct V_50 * V_50 = V_1 -> V_251 ;
int V_252 , clock ;
int V_253 = 1 ;
int V_254 = F_9 ( V_1 ) ;
int V_255 = 0 ;
int V_256 ;
int V_20 , V_55 ;
int V_257 , V_258 ;
int V_42 [ V_46 ] = {} ;
int V_223 ;
T_3 V_242 , V_243 ;
V_223 = F_26 ( V_1 , V_42 ) ;
F_25 ( V_223 <= 0 ) ;
V_256 = V_223 - 1 ;
if ( F_127 ( V_25 ) && ! F_155 ( V_25 ) && V_84 != V_134 )
V_210 -> V_259 = true ;
V_210 -> V_260 = false ;
V_210 -> V_261 = V_1 -> V_261 && V_84 != V_134 ;
if ( F_1 ( V_1 ) && V_50 -> V_52 . V_51 ) {
F_156 ( V_50 -> V_52 . V_51 ,
V_248 ) ;
if ( F_137 ( V_25 ) >= 9 ) {
int V_154 ;
V_154 = F_157 ( V_210 ) ;
if ( V_154 )
return V_154 ;
}
if ( F_158 ( V_25 ) )
F_159 ( V_249 , V_210 ,
V_50 -> V_52 . V_262 ) ;
else
F_160 ( V_249 , V_210 ,
V_50 -> V_52 . V_262 ) ;
}
if ( V_248 -> V_61 & V_62 )
return false ;
F_45 ( L_29
L_30 ,
V_254 , V_42 [ V_256 ] ,
V_248 -> V_263 ) ;
V_20 = F_151 ( V_1 , V_210 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_50 -> V_4 . V_264 . V_244 == 0 &&
( V_25 -> V_194 . V_265 . V_20 && V_25 -> V_194 . V_265 . V_20 < V_20 ) ) {
F_45 ( L_31 ,
V_25 -> V_194 . V_265 . V_20 ) ;
V_20 = V_25 -> V_194 . V_265 . V_20 ;
}
V_253 = V_254 ;
V_255 = V_256 ;
}
for (; V_20 >= 6 * 3 ; V_20 -= 2 * 3 ) {
V_55 = F_12 ( V_248 -> V_263 ,
V_20 ) ;
for ( clock = V_255 ; clock <= V_256 ; clock ++ ) {
for ( V_252 = V_253 ;
V_252 <= V_254 ;
V_252 <<= 1 ) {
V_258 = V_42 [ clock ] ;
V_257 = F_13 ( V_258 ,
V_252 ) ;
if ( V_55 <= V_257 ) {
goto V_266;
}
}
}
}
return false ;
V_266:
if ( V_1 -> V_267 ) {
V_210 -> V_268 =
V_20 != 18 && F_161 ( V_248 ) > 1 ;
} else {
V_210 -> V_268 =
V_1 -> V_268 ;
}
V_210 -> V_252 = V_252 ;
V_210 -> V_245 = V_20 ;
V_210 -> V_216 = V_42 [ clock ] ;
F_149 ( V_1 , V_210 -> V_216 ,
& V_242 , & V_243 ) ;
F_45 ( L_32 ,
V_242 , V_243 , V_210 -> V_252 ,
V_210 -> V_216 , V_20 ) ;
F_45 ( L_33 ,
V_55 , V_257 ) ;
F_162 ( V_20 , V_252 ,
V_248 -> V_263 ,
V_210 -> V_216 ,
& V_210 -> V_269 ) ;
if ( V_50 -> V_52 . V_270 != NULL &&
V_25 -> V_271 . type == V_272 ) {
V_210 -> V_260 = true ;
F_162 ( V_20 , V_252 ,
V_50 -> V_52 . V_270 -> clock ,
V_210 -> V_216 ,
& V_210 -> V_273 ) ;
}
if ( F_1 ( V_1 ) &&
( F_21 ( V_25 ) || F_22 ( V_25 ) ) ) {
int V_274 ;
switch ( V_210 -> V_216 / 2 ) {
case 108000 :
case 216000 :
V_274 = 8640000 ;
break;
default:
V_274 = 8100000 ;
break;
}
F_163 ( V_210 -> V_4 . V_275 ) -> V_276 = V_274 ;
}
if ( ! F_155 ( V_25 ) )
F_138 ( V_23 , V_210 ) ;
return true ;
}
void F_164 ( struct V_1 * V_1 ,
int V_277 , T_3 V_252 ,
bool V_278 )
{
V_1 -> V_277 = V_277 ;
V_1 -> V_252 = V_252 ;
V_1 -> V_278 = V_278 ;
}
static void F_165 ( struct V_22 * V_23 ,
struct V_209 * V_210 )
{
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
struct V_249 * V_250 = F_154 ( V_23 -> V_4 . V_250 ) ;
const struct V_48 * V_248 = & V_210 -> V_4 . V_248 ;
F_164 ( V_1 , V_210 -> V_216 ,
V_210 -> V_252 ,
F_166 ( V_210 ,
V_279 ) ) ;
V_1 -> V_81 = F_42 ( V_1 -> V_82 ) & V_85 ;
V_1 -> V_81 |= V_86 | V_87 ;
V_1 -> V_81 |= F_46 ( V_210 -> V_252 ) ;
if ( F_167 ( V_25 ) && V_84 == V_134 ) {
if ( V_248 -> V_61 & V_280 )
V_1 -> V_81 |= V_281 ;
if ( V_248 -> V_61 & V_282 )
V_1 -> V_81 |= V_283 ;
V_1 -> V_81 |= V_284 ;
if ( F_168 ( V_1 -> V_11 ) )
V_1 -> V_81 |= V_285 ;
V_1 -> V_81 |= V_250 -> V_73 << 29 ;
} else if ( F_169 ( V_25 ) && V_84 != V_134 ) {
T_5 V_286 ;
V_1 -> V_81 |= V_284 ;
V_286 = F_42 ( F_170 ( V_250 -> V_73 ) ) ;
if ( F_168 ( V_1 -> V_11 ) )
V_286 |= V_287 ;
else
V_286 &= ~ V_287 ;
F_53 ( F_170 ( V_250 -> V_73 ) , V_286 ) ;
} else {
if ( F_139 ( V_25 ) && V_210 -> V_268 )
V_1 -> V_81 |= V_288 ;
if ( V_248 -> V_61 & V_280 )
V_1 -> V_81 |= V_281 ;
if ( V_248 -> V_61 & V_282 )
V_1 -> V_81 |= V_283 ;
V_1 -> V_81 |= V_289 ;
if ( F_168 ( V_1 -> V_11 ) )
V_1 -> V_81 |= V_285 ;
if ( F_47 ( V_25 ) )
V_1 -> V_81 |= F_48 ( V_250 -> V_73 ) ;
else if ( V_250 -> V_73 == V_89 )
V_1 -> V_81 |= V_90 ;
}
}
static void F_171 ( struct V_1 * V_1 ,
T_5 V_290 ,
T_5 V_291 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_6 V_292 , V_120 ;
F_57 ( & V_25 -> V_72 ) ;
F_172 ( V_25 , V_1 ) ;
V_292 = F_79 ( V_1 ) ;
V_120 = F_78 ( V_1 ) ;
F_45 ( L_34 ,
V_290 , V_291 ,
F_42 ( V_292 ) ,
F_42 ( V_120 ) ) ;
if ( F_173 ( V_25 ,
V_292 , V_290 , V_291 ,
5000 ) )
F_52 ( L_35 ,
F_42 ( V_292 ) ,
F_42 ( V_120 ) ) ;
F_45 ( L_36 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
F_45 ( L_37 ) ;
F_171 ( V_1 , V_293 , V_294 ) ;
}
static void F_175 ( struct V_1 * V_1 )
{
F_45 ( L_38 ) ;
F_171 ( V_1 , V_295 , V_296 ) ;
}
static void F_176 ( struct V_1 * V_1 )
{
T_9 V_297 ;
T_10 V_298 ;
F_45 ( L_39 ) ;
V_297 = F_177 () ;
V_298 = F_178 ( V_297 , V_1 -> V_299 ) ;
if ( V_298 < ( T_10 ) V_1 -> V_125 )
F_179 ( V_300 ,
V_1 -> V_125 - V_298 ) ;
F_171 ( V_1 , V_301 , V_302 ) ;
}
static void F_180 ( struct V_1 * V_1 )
{
F_179 ( V_1 -> V_303 ,
V_1 -> V_304 ) ;
}
static void F_181 ( struct V_1 * V_1 )
{
F_179 ( V_1 -> V_305 ,
V_1 -> V_306 ) ;
}
static T_5 F_182 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_307 ;
F_57 ( & V_25 -> V_72 ) ;
V_307 = F_42 ( F_78 ( V_1 ) ) ;
if ( F_25 ( ! F_155 ( V_25 ) &&
( V_307 & V_308 ) != V_123 ) ) {
V_307 &= ~ V_308 ;
V_307 |= V_123 ;
}
return V_307 ;
}
static bool F_106 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
T_5 V_309 ;
T_6 V_292 , V_120 ;
bool V_310 = ! V_1 -> V_311 ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_183 ( & V_1 -> V_312 ) ;
V_1 -> V_311 = true ;
if ( F_85 ( V_1 ) )
return V_310 ;
V_71 = F_33 ( V_22 ) ;
F_34 ( V_25 , V_71 ) ;
F_45 ( L_40 ,
F_44 ( V_3 -> V_84 ) ) ;
if ( ! F_84 ( V_1 ) )
F_176 ( V_1 ) ;
V_309 = F_182 ( V_1 ) ;
V_309 |= V_101 ;
V_292 = F_79 ( V_1 ) ;
V_120 = F_78 ( V_1 ) ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
F_45 ( L_41 ,
F_42 ( V_292 ) , F_42 ( V_120 ) ) ;
if ( ! F_84 ( V_1 ) ) {
F_45 ( L_42 ,
F_44 ( V_3 -> V_84 ) ) ;
F_83 ( V_1 -> V_313 ) ;
}
return V_310 ;
}
void F_184 ( struct V_1 * V_1 )
{
bool V_157 ;
if ( ! F_1 ( V_1 ) )
return;
F_32 ( V_1 ) ;
V_157 = F_106 ( V_1 ) ;
F_36 ( V_1 ) ;
F_185 ( ! V_157 , L_43 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
enum V_70 V_71 ;
T_5 V_309 ;
T_6 V_292 , V_120 ;
F_57 ( & V_25 -> V_72 ) ;
F_25 ( V_1 -> V_311 ) ;
if ( ! F_85 ( V_1 ) )
return;
F_45 ( L_44 ,
F_44 ( V_3 -> V_84 ) ) ;
V_309 = F_182 ( V_1 ) ;
V_309 &= ~ V_101 ;
V_120 = F_78 ( V_1 ) ;
V_292 = F_79 ( V_1 ) ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
F_45 ( L_41 ,
F_42 ( V_292 ) , F_42 ( V_120 ) ) ;
if ( ( V_309 & V_314 ) == 0 )
V_1 -> V_299 = F_177 () ;
V_71 = F_33 ( V_22 ) ;
F_38 ( V_25 , V_71 ) ;
}
static void F_187 ( struct V_315 * V_316 )
{
struct V_1 * V_1 = F_81 ( F_188 ( V_316 ) ,
struct V_1 , V_312 ) ;
F_32 ( V_1 ) ;
if ( ! V_1 -> V_311 )
F_186 ( V_1 ) ;
F_36 ( V_1 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
unsigned long V_317 ;
V_317 = F_190 ( V_1 -> V_125 * 5 ) ;
F_191 ( & V_1 -> V_312 , V_317 ) ;
}
static void F_110 ( struct V_1 * V_1 , bool V_318 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_185 ( ! V_1 -> V_311 , L_45 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) ;
V_1 -> V_311 = false ;
if ( V_318 )
F_186 ( V_1 ) ;
else
F_189 ( V_1 ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_309 ;
T_6 V_120 ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_46 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) ;
if ( F_8 ( F_84 ( V_1 ) ,
L_47 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) )
return;
F_176 ( V_1 ) ;
V_120 = F_78 ( V_1 ) ;
V_309 = F_182 ( V_1 ) ;
if ( F_193 ( V_25 ) ) {
V_309 &= ~ V_319 ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
}
V_309 |= V_314 ;
if ( ! F_193 ( V_25 ) )
V_309 |= V_319 ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
F_174 ( V_1 ) ;
V_1 -> V_303 = V_300 ;
if ( F_193 ( V_25 ) ) {
V_309 |= V_319 ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
}
}
void F_194 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_32 ( V_1 ) ;
F_192 ( V_1 ) ;
F_36 ( V_1 ) ;
}
static void F_195 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
T_5 V_309 ;
T_6 V_120 ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_48 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) ;
F_8 ( ! V_1 -> V_311 , L_49 ,
F_44 ( F_2 ( V_1 ) -> V_84 ) ) ;
V_309 = F_182 ( V_1 ) ;
V_309 &= ~ ( V_314 | V_319 | V_101 |
V_320 ) ;
V_120 = F_78 ( V_1 ) ;
V_1 -> V_311 = false ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
V_1 -> V_299 = F_177 () ;
F_175 ( V_1 ) ;
V_71 = F_33 ( V_22 ) ;
F_38 ( V_25 , V_71 ) ;
}
void F_196 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_32 ( V_1 ) ;
F_195 ( V_1 ) ;
F_36 ( V_1 ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_309 ;
T_6 V_120 ;
F_180 ( V_1 ) ;
F_32 ( V_1 ) ;
V_309 = F_182 ( V_1 ) ;
V_309 |= V_320 ;
V_120 = F_78 ( V_1 ) ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
F_36 ( V_1 ) ;
}
void F_198 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_50 ) ;
F_199 ( V_1 -> V_251 ) ;
F_197 ( V_1 ) ;
}
static void F_200 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_309 ;
T_6 V_120 ;
if ( ! F_1 ( V_1 ) )
return;
F_32 ( V_1 ) ;
V_309 = F_182 ( V_1 ) ;
V_309 &= ~ V_320 ;
V_120 = F_78 ( V_1 ) ;
F_53 ( V_120 , V_309 ) ;
F_54 ( V_120 ) ;
F_36 ( V_1 ) ;
V_1 -> V_305 = V_300 ;
F_181 ( V_1 ) ;
}
void F_201 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_45 ( L_50 ) ;
F_200 ( V_1 ) ;
F_202 ( V_1 -> V_251 ) ;
}
static void F_203 ( struct V_50 * V_9 ,
bool V_321 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_322 ;
F_32 ( V_1 ) ;
V_322 = F_182 ( V_1 ) & V_320 ;
F_36 ( V_1 ) ;
if ( V_322 == V_321 )
return;
F_45 ( L_51 ,
V_321 ? L_52 : L_53 ) ;
if ( V_321 )
F_197 ( V_1 ) ;
else
F_200 ( V_1 ) ;
}
static void F_204 ( struct V_1 * V_1 , bool V_275 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
bool V_323 = F_42 ( V_1 -> V_82 ) & V_83 ;
F_185 ( V_323 != V_275 ,
L_54 ,
F_44 ( V_36 -> V_84 ) ,
F_205 ( V_275 ) , F_205 ( V_323 ) ) ;
}
static void F_206 ( struct V_24 * V_25 , bool V_275 )
{
bool V_323 = F_42 ( V_324 ) & V_325 ;
F_185 ( V_323 != V_275 ,
L_55 ,
F_205 ( V_275 ) , F_205 ( V_323 ) ) ;
}
static void F_207 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
struct V_249 * V_250 = F_154 ( V_210 -> V_4 . V_250 ) ;
struct V_24 * V_25 = F_15 ( V_250 -> V_4 . V_7 ) ;
F_208 ( V_25 , V_250 -> V_73 ) ;
F_209 ( V_1 ) ;
F_210 ( V_25 ) ;
F_45 ( L_56 ,
V_210 -> V_216 ) ;
V_1 -> V_81 &= ~ V_326 ;
if ( V_210 -> V_216 == 162000 )
V_1 -> V_81 |= V_327 ;
else
V_1 -> V_81 |= V_328 ;
F_53 ( V_324 , V_1 -> V_81 ) ;
F_54 ( V_324 ) ;
F_211 ( 500 ) ;
if ( F_193 ( V_25 ) )
F_212 ( V_25 , ! V_250 -> V_73 ) ;
V_1 -> V_81 |= V_325 ;
F_53 ( V_324 , V_1 -> V_81 ) ;
F_54 ( V_324 ) ;
F_211 ( 200 ) ;
}
static void F_213 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_249 * V_250 = F_154 ( V_3 -> V_4 . V_4 . V_250 ) ;
struct V_24 * V_25 = F_15 ( V_250 -> V_4 . V_7 ) ;
F_208 ( V_25 , V_250 -> V_73 ) ;
F_209 ( V_1 ) ;
F_214 ( V_25 ) ;
F_45 ( L_57 ) ;
V_1 -> V_81 &= ~ V_325 ;
F_53 ( V_324 , V_1 -> V_81 ) ;
F_54 ( V_324 ) ;
F_211 ( 200 ) ;
}
void F_215 ( struct V_1 * V_1 , int V_49 )
{
int V_154 , V_43 ;
if ( V_1 -> V_11 [ V_329 ] < 0x11 )
return;
if ( V_49 != V_330 ) {
V_154 = F_216 ( & V_1 -> V_172 , V_331 ,
V_332 ) ;
} else {
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_154 = F_216 ( & V_1 -> V_172 , V_331 ,
V_333 ) ;
if ( V_154 == 1 )
break;
F_83 ( 1 ) ;
}
}
if ( V_154 != 1 )
F_45 ( L_58 ,
V_49 == V_330 ? L_52 : L_53 ) ;
}
static bool F_217 ( struct V_22 * V_23 ,
enum V_73 * V_73 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
T_5 V_98 ;
bool V_154 ;
V_71 = F_218 ( V_23 ) ;
if ( ! F_219 ( V_25 , V_71 ) )
return false ;
V_154 = false ;
V_98 = F_42 ( V_1 -> V_82 ) ;
if ( ! ( V_98 & V_83 ) )
goto V_161;
if ( F_167 ( V_25 ) && V_84 == V_134 ) {
* V_73 = F_220 ( V_98 ) ;
} else if ( F_169 ( V_25 ) && V_84 != V_134 ) {
enum V_73 V_334 ;
F_221 (dev_priv, p) {
T_5 V_286 = F_42 ( F_170 ( V_334 ) ) ;
if ( F_222 ( V_286 ) == V_84 ) {
* V_73 = V_334 ;
V_154 = true ;
goto V_161;
}
}
F_45 ( L_59 ,
F_223 ( V_1 -> V_82 ) ) ;
} else if ( F_47 ( V_25 ) ) {
* V_73 = F_224 ( V_98 ) ;
} else {
* V_73 = F_225 ( V_98 ) ;
}
V_154 = true ;
V_161:
F_38 ( V_25 , V_71 ) ;
return V_154 ;
}
static void F_226 ( struct V_22 * V_23 ,
struct V_209 * V_210 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
T_5 V_98 , V_61 = 0 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
struct V_249 * V_250 = F_154 ( V_23 -> V_4 . V_250 ) ;
V_98 = F_42 ( V_1 -> V_82 ) ;
V_210 -> V_261 = V_98 & V_335 && V_84 != V_134 ;
if ( F_169 ( V_25 ) && V_84 != V_134 ) {
T_5 V_286 = F_42 ( F_170 ( V_250 -> V_73 ) ) ;
if ( V_286 & V_336 )
V_61 |= V_280 ;
else
V_61 |= V_337 ;
if ( V_286 & V_338 )
V_61 |= V_282 ;
else
V_61 |= V_339 ;
} else {
if ( V_98 & V_281 )
V_61 |= V_280 ;
else
V_61 |= V_337 ;
if ( V_98 & V_283 )
V_61 |= V_282 ;
else
V_61 |= V_339 ;
}
V_210 -> V_4 . V_248 . V_61 |= V_61 ;
if ( F_139 ( V_25 ) && V_98 & V_288 )
V_210 -> V_268 = true ;
V_210 -> V_252 =
( ( V_98 & V_340 ) >> V_341 ) + 1 ;
F_227 ( V_250 , V_210 ) ;
if ( V_84 == V_134 ) {
if ( ( F_42 ( V_324 ) & V_326 ) == V_327 )
V_210 -> V_216 = 162000 ;
else
V_210 -> V_216 = 270000 ;
}
V_210 -> V_4 . V_248 . V_263 =
F_228 ( V_210 -> V_216 ,
& V_210 -> V_269 ) ;
if ( F_1 ( V_1 ) && V_25 -> V_194 . V_265 . V_20 &&
V_210 -> V_245 > V_25 -> V_194 . V_265 . V_20 ) {
F_45 ( L_60 ,
V_210 -> V_245 , V_25 -> V_194 . V_265 . V_20 ) ;
V_25 -> V_194 . V_265 . V_20 = V_210 -> V_245 ;
}
}
static void F_229 ( struct V_22 * V_23 ,
struct V_209 * V_342 ,
struct V_246 * V_343 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_24 * V_25 = F_15 ( V_23 -> V_4 . V_7 ) ;
if ( V_342 -> V_261 )
F_230 ( V_23 ) ;
if ( F_231 ( V_25 ) && ! F_155 ( V_25 ) )
F_232 ( V_1 ) ;
F_184 ( V_1 ) ;
F_201 ( V_1 ) ;
F_215 ( V_1 , V_344 ) ;
F_196 ( V_1 ) ;
if ( F_137 ( V_25 ) < 5 )
F_233 ( V_1 ) ;
}
static void F_234 ( struct V_22 * V_23 ,
struct V_209 * V_342 ,
struct V_246 * V_343 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
F_233 ( V_1 ) ;
if ( V_84 == V_134 )
F_213 ( V_1 ) ;
}
static void F_235 ( struct V_22 * V_23 ,
struct V_209 * V_342 ,
struct V_246 * V_343 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_233 ( V_1 ) ;
}
static void F_236 ( struct V_22 * V_23 ,
struct V_209 * V_342 ,
struct V_246 * V_343 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_233 ( V_1 ) ;
F_35 ( & V_25 -> V_345 ) ;
F_237 ( V_23 , true ) ;
F_37 ( & V_25 -> V_345 ) ;
}
static void
F_238 ( struct V_1 * V_1 ,
T_2 * V_81 ,
T_3 V_346 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
if ( V_346 & V_347 )
F_45 ( L_61 ,
V_346 & V_347 ) ;
if ( F_155 ( V_25 ) ) {
T_2 V_348 = F_42 ( F_239 ( V_84 ) ) ;
if ( V_346 & V_349 )
V_348 |= V_350 ;
else
V_348 &= ~ V_350 ;
V_348 &= ~ V_351 ;
switch ( V_346 & V_347 ) {
case V_352 :
V_348 |= V_353 ;
break;
case V_354 :
V_348 |= V_355 ;
break;
case V_356 :
V_348 |= V_357 ;
break;
case V_358 :
V_348 |= V_359 ;
break;
}
F_53 ( F_239 ( V_84 ) , V_348 ) ;
} else if ( ( F_167 ( V_25 ) && V_84 == V_134 ) ||
( F_169 ( V_25 ) && V_84 != V_134 ) ) {
* V_81 &= ~ V_360 ;
switch ( V_346 & V_347 ) {
case V_352 :
* V_81 |= V_284 ;
break;
case V_354 :
* V_81 |= V_361 ;
break;
case V_356 :
* V_81 |= V_362 ;
break;
case V_358 :
F_45 ( L_62 ) ;
* V_81 |= V_362 ;
break;
}
} else {
if ( F_47 ( V_25 ) )
* V_81 &= ~ V_363 ;
else
* V_81 &= ~ V_364 ;
switch ( V_346 & V_347 ) {
case V_352 :
* V_81 |= V_289 ;
break;
case V_354 :
* V_81 |= V_88 ;
break;
case V_356 :
* V_81 |= V_365 ;
break;
case V_358 :
if ( F_47 ( V_25 ) ) {
* V_81 |= V_366 ;
} else {
F_45 ( L_62 ) ;
* V_81 |= V_365 ;
}
break;
}
}
}
static void F_240 ( struct V_1 * V_1 ,
struct V_209 * V_342 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
F_241 ( V_1 , V_354 ) ;
V_1 -> V_81 |= V_83 ;
if ( V_342 -> V_261 )
V_1 -> V_81 |= V_335 ;
F_53 ( V_1 -> V_82 , V_1 -> V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
}
static void F_242 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_249 * V_250 = F_154 ( V_23 -> V_4 . V_250 ) ;
T_2 V_367 = F_42 ( V_1 -> V_82 ) ;
enum V_73 V_73 = V_250 -> V_73 ;
if ( F_25 ( V_367 & V_83 ) )
return;
F_32 ( V_1 ) ;
if ( F_74 ( V_25 ) || F_47 ( V_25 ) )
F_243 ( V_1 ) ;
F_240 ( V_1 , V_210 ) ;
F_106 ( V_1 ) ;
F_192 ( V_1 ) ;
F_110 ( V_1 , true ) ;
F_36 ( V_1 ) ;
if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
unsigned int V_368 = 0x0 ;
if ( F_47 ( V_25 ) )
V_368 = F_244 ( V_210 -> V_252 ) ;
F_245 ( V_25 , F_2 ( V_1 ) ,
V_368 ) ;
}
F_215 ( V_1 , V_330 ) ;
F_246 ( V_1 ) ;
F_247 ( V_1 ) ;
if ( V_210 -> V_261 ) {
F_248 ( L_63 ,
F_43 ( V_73 ) ) ;
F_249 ( V_23 , V_210 , V_247 ) ;
}
}
static void F_250 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_242 ( V_23 , V_210 , V_247 ) ;
F_198 ( V_1 ) ;
}
static void F_251 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
F_198 ( V_1 ) ;
F_252 ( V_1 ) ;
}
static void F_253 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
F_165 ( V_23 , V_210 ) ;
if ( V_84 == V_134 )
F_207 ( V_1 , V_210 ) ;
}
static void F_254 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_73 V_73 = V_1 -> V_74 ;
T_6 V_369 = F_70 ( V_73 ) ;
F_186 ( V_1 ) ;
F_45 ( L_64 ,
F_43 ( V_73 ) , F_44 ( V_3 -> V_84 ) ) ;
F_53 ( V_369 , 0 ) ;
F_54 ( V_369 ) ;
V_1 -> V_74 = V_97 ;
}
static void F_60 ( struct V_6 * V_7 ,
enum V_73 V_73 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_22 * V_23 ;
F_57 ( & V_25 -> V_72 ) ;
if ( F_25 ( V_73 != V_96 && V_73 != V_89 ) )
return;
F_58 (dev, encoder) {
struct V_1 * V_1 ;
enum V_84 V_84 ;
if ( V_23 -> type != V_5 )
continue;
V_1 = F_5 ( & V_23 -> V_4 ) ;
V_84 = F_2 ( V_1 ) -> V_84 ;
if ( V_1 -> V_74 != V_73 )
continue;
F_45 ( L_65 ,
F_43 ( V_73 ) , F_44 ( V_84 ) ) ;
F_8 ( V_23 -> V_4 . V_250 ,
L_66 ,
F_43 ( V_73 ) , F_44 ( V_84 ) ) ;
F_254 ( V_1 ) ;
}
}
static void F_243 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_249 * V_250 = F_154 ( V_23 -> V_4 . V_250 ) ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 -> V_74 == V_250 -> V_73 )
return;
if ( V_1 -> V_74 != V_97 )
F_254 ( V_1 ) ;
F_60 ( V_7 , V_250 -> V_73 ) ;
V_1 -> V_74 = V_250 -> V_73 ;
F_45 ( L_67 ,
F_43 ( V_1 -> V_74 ) , F_44 ( V_3 -> V_84 ) ) ;
F_61 ( V_7 , V_1 ) ;
F_62 ( V_7 , V_1 , true ) ;
}
static void F_255 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
F_256 ( V_23 ) ;
F_242 ( V_23 , V_210 , V_247 ) ;
}
static void F_257 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
F_165 ( V_23 , V_210 ) ;
F_258 ( V_23 ) ;
}
static void F_259 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
F_260 ( V_23 ) ;
F_242 ( V_23 , V_210 , V_247 ) ;
F_261 ( V_23 ) ;
}
static void F_262 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
F_165 ( V_23 , V_210 ) ;
F_263 ( V_23 ) ;
}
static void F_264 ( struct V_22 * V_23 ,
struct V_209 * V_210 ,
struct V_246 * V_247 )
{
F_265 ( V_23 ) ;
}
bool
F_266 ( struct V_1 * V_1 , T_3 V_370 [ V_371 ] )
{
return F_144 ( & V_1 -> V_172 , V_372 , V_370 ,
V_371 ) == V_371 ;
}
T_3
F_267 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
if ( F_19 ( V_25 ) )
return V_373 ;
else if ( F_137 ( V_25 ) >= 9 ) {
if ( V_25 -> V_194 . V_265 . V_374 && V_84 == V_134 )
return V_373 ;
return V_375 ;
} else if ( F_74 ( V_25 ) || F_47 ( V_25 ) )
return V_373 ;
else if ( F_167 ( V_25 ) && V_84 == V_134 )
return V_375 ;
else if ( F_169 ( V_25 ) && V_84 != V_134 )
return V_373 ;
else
return V_375 ;
}
T_3
F_268 ( struct V_1 * V_1 , T_3 V_376 )
{
struct V_24 * V_25 = F_15 ( F_3 ( V_1 ) ) ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
if ( F_137 ( V_25 ) >= 9 ) {
switch ( V_376 & V_377 ) {
case V_378 :
return V_379 ;
case V_380 :
return V_381 ;
case V_375 :
return V_382 ;
case V_373 :
return V_383 ;
default:
return V_383 ;
}
} else if ( F_135 ( V_25 ) || F_100 ( V_25 ) ) {
switch ( V_376 & V_377 ) {
case V_378 :
return V_379 ;
case V_380 :
return V_381 ;
case V_375 :
return V_382 ;
case V_373 :
default:
return V_383 ;
}
} else if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
switch ( V_376 & V_377 ) {
case V_378 :
return V_379 ;
case V_380 :
return V_381 ;
case V_375 :
return V_382 ;
case V_373 :
default:
return V_383 ;
}
} else if ( F_167 ( V_25 ) && V_84 == V_134 ) {
switch ( V_376 & V_377 ) {
case V_378 :
return V_381 ;
case V_380 :
case V_375 :
return V_382 ;
default:
return V_383 ;
}
} else {
switch ( V_376 & V_377 ) {
case V_378 :
return V_381 ;
case V_380 :
return V_381 ;
case V_375 :
return V_382 ;
case V_373 :
default:
return V_383 ;
}
}
}
static T_2 F_269 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_384 , V_385 ,
V_386 ;
T_3 V_387 = V_1 -> V_387 [ 0 ] ;
switch ( V_387 & V_388 ) {
case V_383 :
V_385 = 0x0004000 ;
switch ( V_387 & V_377 ) {
case V_378 :
V_384 = 0x2B405555 ;
V_386 = 0x552AB83A ;
break;
case V_380 :
V_384 = 0x2B404040 ;
V_386 = 0x5548B83A ;
break;
case V_375 :
V_384 = 0x2B245555 ;
V_386 = 0x5560B83A ;
break;
case V_373 :
V_384 = 0x2B405555 ;
V_386 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_382 :
V_385 = 0x0002000 ;
switch ( V_387 & V_377 ) {
case V_378 :
V_384 = 0x2B404040 ;
V_386 = 0x5552B83A ;
break;
case V_380 :
V_384 = 0x2B404848 ;
V_386 = 0x5580B83A ;
break;
case V_375 :
V_384 = 0x2B404040 ;
V_386 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_381 :
V_385 = 0x0000000 ;
switch ( V_387 & V_377 ) {
case V_378 :
V_384 = 0x2B305555 ;
V_386 = 0x5570B83A ;
break;
case V_380 :
V_384 = 0x2B2B4040 ;
V_386 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_379 :
V_385 = 0x0006000 ;
switch ( V_387 & V_377 ) {
case V_378 :
V_384 = 0x1B405555 ;
V_386 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_270 ( V_23 , V_384 , V_385 ,
V_386 , 0 ) ;
return 0 ;
}
static T_2 F_271 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_389 , V_390 ;
bool V_391 = false ;
T_3 V_387 = V_1 -> V_387 [ 0 ] ;
switch ( V_387 & V_388 ) {
case V_383 :
switch ( V_387 & V_377 ) {
case V_378 :
V_389 = 128 ;
V_390 = 52 ;
break;
case V_380 :
V_389 = 128 ;
V_390 = 77 ;
break;
case V_375 :
V_389 = 128 ;
V_390 = 102 ;
break;
case V_373 :
V_389 = 128 ;
V_390 = 154 ;
V_391 = true ;
break;
default:
return 0 ;
}
break;
case V_382 :
switch ( V_387 & V_377 ) {
case V_378 :
V_389 = 85 ;
V_390 = 78 ;
break;
case V_380 :
V_389 = 85 ;
V_390 = 116 ;
break;
case V_375 :
V_389 = 85 ;
V_390 = 154 ;
break;
default:
return 0 ;
}
break;
case V_381 :
switch ( V_387 & V_377 ) {
case V_378 :
V_389 = 64 ;
V_390 = 104 ;
break;
case V_380 :
V_389 = 64 ;
V_390 = 154 ;
break;
default:
return 0 ;
}
break;
case V_379 :
switch ( V_387 & V_377 ) {
case V_378 :
V_389 = 43 ;
V_390 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_272 ( V_23 , V_389 ,
V_390 , V_391 ) ;
return 0 ;
}
static T_2
F_273 ( T_3 V_387 )
{
T_2 V_392 = 0 ;
switch ( V_387 & V_377 ) {
case V_378 :
default:
V_392 |= V_86 ;
break;
case V_380 :
V_392 |= V_393 ;
break;
case V_375 :
V_392 |= V_394 ;
break;
case V_373 :
V_392 |= V_395 ;
break;
}
switch ( V_387 & V_388 ) {
case V_383 :
default:
V_392 |= V_87 ;
break;
case V_382 :
V_392 |= V_396 ;
break;
case V_381 :
V_392 |= V_397 ;
break;
case V_379 :
V_392 |= V_398 ;
break;
}
return V_392 ;
}
static T_2
F_274 ( T_3 V_387 )
{
int V_392 = V_387 & ( V_377 |
V_388 ) ;
switch ( V_392 ) {
case V_378 | V_383 :
case V_380 | V_383 :
return V_399 ;
case V_378 | V_382 :
return V_400 ;
case V_378 | V_381 :
case V_380 | V_381 :
return V_401 ;
case V_380 | V_382 :
case V_375 | V_382 :
return V_402 ;
case V_375 | V_383 :
case V_373 | V_383 :
return V_403 ;
default:
F_45 ( L_68
L_69 , V_392 ) ;
return V_399 ;
}
}
static T_2
F_275 ( T_3 V_387 )
{
int V_392 = V_387 & ( V_377 |
V_388 ) ;
switch ( V_392 ) {
case V_378 | V_383 :
return V_404 ;
case V_378 | V_382 :
return V_405 ;
case V_378 | V_381 :
return V_406 ;
case V_380 | V_383 :
return V_407 ;
case V_380 | V_382 :
return V_408 ;
case V_375 | V_383 :
return V_409 ;
case V_375 | V_382 :
return V_410 ;
default:
F_45 ( L_68
L_69 , V_392 ) ;
return V_411 ;
}
}
void
F_276 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_2 V_392 , V_290 = 0 ;
T_3 V_387 = V_1 -> V_387 [ 0 ] ;
if ( F_155 ( V_25 ) ) {
V_392 = F_277 ( V_1 ) ;
if ( F_19 ( V_25 ) )
V_392 = 0 ;
else
V_290 = V_412 ;
} else if ( F_47 ( V_25 ) ) {
V_392 = F_271 ( V_1 ) ;
} else if ( F_74 ( V_25 ) ) {
V_392 = F_269 ( V_1 ) ;
} else if ( F_167 ( V_25 ) && V_84 == V_134 ) {
V_392 = F_275 ( V_387 ) ;
V_290 = V_413 ;
} else if ( F_99 ( V_25 ) && V_84 == V_134 ) {
V_392 = F_274 ( V_387 ) ;
V_290 = V_414 ;
} else {
V_392 = F_273 ( V_387 ) ;
V_290 = V_415 | V_416 ;
}
if ( V_290 )
F_45 ( L_70 , V_392 ) ;
F_45 ( L_71 ,
V_387 & V_377 ) ;
F_45 ( L_72 ,
( V_387 & V_388 ) >>
V_417 ) ;
V_1 -> V_81 = ( V_1 -> V_81 & ~ V_290 ) | V_392 ;
F_53 ( V_1 -> V_82 , V_1 -> V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
}
void
F_241 ( struct V_1 * V_1 ,
T_3 V_346 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_24 * V_25 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_238 ( V_1 , & V_1 -> V_81 , V_346 ) ;
F_53 ( V_1 -> V_82 , V_1 -> V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
}
void F_278 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
T_2 V_418 ;
if ( ! F_155 ( V_25 ) )
return;
V_418 = F_42 ( F_239 ( V_84 ) ) ;
V_418 &= ~ V_351 ;
V_418 |= V_419 ;
F_53 ( F_239 ( V_84 ) , V_418 ) ;
if ( V_84 == V_134 )
return;
if ( F_173 ( V_25 , F_279 ( V_84 ) ,
V_420 ,
V_420 ,
1 ) )
F_52 ( L_73 ) ;
}
static void
F_233 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_249 * V_250 = F_154 ( V_3 -> V_4 . V_4 . V_250 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_2 V_81 = V_1 -> V_81 ;
if ( F_25 ( F_155 ( V_25 ) ) )
return;
if ( F_25 ( ( F_42 ( V_1 -> V_82 ) & V_83 ) == 0 ) )
return;
F_45 ( L_50 ) ;
if ( ( F_167 ( V_25 ) && V_84 == V_134 ) ||
( F_169 ( V_25 ) && V_84 != V_134 ) ) {
V_81 &= ~ V_360 ;
V_81 |= V_421 ;
} else {
if ( F_47 ( V_25 ) )
V_81 &= ~ V_363 ;
else
V_81 &= ~ V_364 ;
V_81 |= V_422 ;
}
F_53 ( V_1 -> V_82 , V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
V_81 &= ~ ( V_83 | V_335 ) ;
F_53 ( V_1 -> V_82 , V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
if ( F_280 ( V_25 ) && V_250 -> V_73 == V_89 && V_84 != V_134 ) {
F_281 ( V_25 , V_96 , false ) ;
F_282 ( V_25 , V_96 , false ) ;
V_81 &= ~ ( V_90 | V_364 ) ;
V_81 |= V_83 | V_88 ;
F_53 ( V_1 -> V_82 , V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
V_81 &= ~ V_83 ;
F_53 ( V_1 -> V_82 , V_81 ) ;
F_54 ( V_1 -> V_82 ) ;
F_212 ( V_25 , V_96 ) ;
F_281 ( V_25 , V_96 , true ) ;
F_282 ( V_25 , V_96 , true ) ;
}
F_83 ( V_1 -> V_423 ) ;
V_1 -> V_81 = V_81 ;
}
bool
F_283 ( struct V_1 * V_1 )
{
if ( F_144 ( & V_1 -> V_172 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_45 ( L_74 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
return V_1 -> V_11 [ V_329 ] != 0 ;
}
static bool
F_284 ( struct V_1 * V_1 )
{
struct V_24 * V_25 =
F_15 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_25 ( V_1 -> V_11 [ V_329 ] != 0 ) ;
if ( ! F_283 ( V_1 ) )
return false ;
F_145 ( V_1 ) ;
if ( V_1 -> V_11 [ V_329 ] >= 0x11 )
V_25 -> V_424 = V_1 -> V_11 [ V_425 ] &
V_426 ;
F_144 ( & V_1 -> V_172 , V_427 ,
V_1 -> V_428 ,
sizeof( V_1 -> V_428 ) ) ;
if ( V_1 -> V_428 [ 0 ] & V_429 ) {
V_25 -> V_430 . V_431 = true ;
F_45 ( L_75 ) ;
}
if ( F_137 ( V_25 ) >= 9 &&
( V_1 -> V_428 [ 0 ] & V_432 ) ) {
T_3 V_433 ;
V_25 -> V_430 . V_431 = true ;
F_144 ( & V_1 -> V_172 ,
V_434 ,
& V_433 , 1 ) ;
V_25 -> V_430 . V_435 = V_433 ? true : false ;
V_25 -> V_430 . V_436 = V_25 -> V_430 . V_435 ;
F_45 ( L_76 ,
V_25 -> V_430 . V_436 ? L_77 : L_78 ) ;
}
if ( ( V_1 -> V_11 [ V_437 ] & V_438 ) &&
F_144 ( & V_1 -> V_172 , V_439 ,
V_1 -> V_440 , sizeof( V_1 -> V_440 ) ) ==
sizeof( V_1 -> V_440 ) )
F_45 ( L_79 , ( int ) sizeof( V_1 -> V_440 ) ,
V_1 -> V_440 ) ;
if ( V_1 -> V_440 [ 0 ] >= 0x03 ) {
T_11 V_32 [ V_46 ] ;
int V_43 ;
F_144 ( & V_1 -> V_172 , V_441 ,
V_32 , sizeof( V_32 ) ) ;
for ( V_43 = 0 ; V_43 < F_20 ( V_32 ) ; V_43 ++ ) {
int V_418 = F_285 ( V_32 [ V_43 ] ) ;
if ( V_418 == 0 )
break;
V_1 -> V_32 [ V_43 ] = ( V_418 * 200 ) / 10 ;
}
V_1 -> V_33 = V_43 ;
}
return true ;
}
static bool
F_286 ( struct V_1 * V_1 )
{
if ( ! F_283 ( V_1 ) )
return false ;
if ( F_144 ( & V_1 -> V_172 , V_442 ,
& V_1 -> V_443 , 1 ) < 0 )
return false ;
V_1 -> V_443 = F_287 ( V_1 -> V_443 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_443 )
return false ;
if ( ! F_143 ( V_1 -> V_11 ) )
return true ;
if ( V_1 -> V_11 [ V_329 ] == 0x10 )
return true ;
if ( F_144 ( & V_1 -> V_172 , V_444 ,
V_1 -> V_29 ,
V_445 ) < 0 )
return false ;
return true ;
}
static bool
F_288 ( struct V_1 * V_1 )
{
T_1 V_446 [ 1 ] ;
if ( ! V_447 . V_448 )
return false ;
if ( ! V_1 -> V_449 )
return false ;
if ( V_1 -> V_11 [ V_329 ] < 0x12 )
return false ;
if ( F_144 ( & V_1 -> V_172 , V_450 , V_446 , 1 ) != 1 )
return false ;
return V_446 [ 0 ] & V_451 ;
}
static void
F_289 ( struct V_1 * V_1 )
{
if ( ! V_447 . V_448 )
return;
if ( ! V_1 -> V_449 )
return;
V_1 -> V_452 = F_288 ( V_1 ) ;
if ( V_1 -> V_452 )
F_45 ( L_80 ) ;
else
F_45 ( L_81 ) ;
F_290 ( & V_1 -> V_453 ,
V_1 -> V_452 ) ;
}
static int F_291 ( struct V_1 * V_1 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
struct V_249 * V_249 = F_154 ( V_36 -> V_4 . V_4 . V_250 ) ;
T_1 V_446 ;
int V_154 = 0 ;
int V_213 = 0 ;
int V_454 = 10 ;
if ( F_292 ( & V_1 -> V_172 , V_455 , & V_446 ) < 0 ) {
F_45 ( L_82 ) ;
V_154 = - V_167 ;
goto V_161;
}
if ( F_216 ( & V_1 -> V_172 , V_455 ,
V_446 & ~ V_456 ) < 0 ) {
F_45 ( L_82 ) ;
V_154 = - V_167 ;
goto V_161;
}
do {
F_293 ( V_25 , V_249 -> V_73 ) ;
if ( F_292 ( & V_1 -> V_172 ,
V_457 , & V_446 ) < 0 ) {
V_154 = - V_167 ;
goto V_161;
}
V_213 = V_446 & V_458 ;
} while ( -- V_454 && V_213 );
if ( V_454 == 0 ) {
F_45 ( L_83 ) ;
V_154 = - V_168 ;
}
V_161:
F_294 ( V_249 ) ;
return V_154 ;
}
static int F_295 ( struct V_1 * V_1 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
struct V_249 * V_249 = F_154 ( V_36 -> V_4 . V_4 . V_250 ) ;
T_1 V_446 ;
int V_154 ;
if ( F_292 ( & V_1 -> V_172 , V_457 , & V_446 ) < 0 )
return - V_167 ;
if ( ! ( V_446 & V_459 ) )
return - V_460 ;
if ( F_292 ( & V_1 -> V_172 , V_455 , & V_446 ) < 0 )
return - V_167 ;
if ( V_446 & V_456 ) {
V_154 = F_291 ( V_1 ) ;
if ( V_154 )
return V_154 ;
}
F_296 ( V_249 ) ;
if ( F_216 ( & V_1 -> V_172 , V_455 ,
V_446 | V_456 ) < 0 ) {
F_294 ( V_249 ) ;
return - V_167 ;
}
F_293 ( V_25 , V_249 -> V_73 ) ;
return 0 ;
}
int F_297 ( struct V_1 * V_1 , T_1 * V_461 )
{
struct V_2 * V_36 = F_2 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_36 -> V_4 . V_4 . V_7 ) ;
struct V_249 * V_249 = F_154 ( V_36 -> V_4 . V_4 . V_250 ) ;
T_1 V_446 ;
int V_213 , V_154 ;
int V_454 = 6 ;
V_154 = F_295 ( V_1 ) ;
if ( V_154 )
return V_154 ;
do {
F_293 ( V_25 , V_249 -> V_73 ) ;
if ( F_292 ( & V_1 -> V_172 ,
V_457 , & V_446 ) < 0 ) {
V_154 = - V_167 ;
goto V_462;
}
V_213 = V_446 & V_458 ;
} while ( -- V_454 && V_213 == 0 );
if ( V_454 == 0 ) {
F_52 ( L_84 ) ;
V_154 = - V_168 ;
goto V_462;
}
if ( F_144 ( & V_1 -> V_172 , V_463 , V_461 , 6 ) < 0 ) {
V_154 = - V_167 ;
goto V_462;
}
V_462:
F_291 ( V_1 ) ;
return V_154 ;
}
static bool
F_298 ( struct V_1 * V_1 , T_1 * V_464 )
{
return F_144 ( & V_1 -> V_172 ,
V_465 ,
V_464 , 1 ) == 1 ;
}
static bool
F_299 ( struct V_1 * V_1 , T_1 * V_464 )
{
int V_154 ;
V_154 = F_144 ( & V_1 -> V_172 ,
V_466 ,
V_464 , 14 ) ;
if ( V_154 != 14 )
return false ;
return true ;
}
static T_3 F_300 ( struct V_1 * V_1 )
{
T_3 V_467 = V_468 ;
return V_467 ;
}
static T_3 F_301 ( struct V_1 * V_1 )
{
T_3 V_467 = V_469 ;
return V_467 ;
}
static T_3 F_302 ( struct V_1 * V_1 )
{
T_3 V_467 = V_469 ;
struct V_50 * V_50 = V_1 -> V_251 ;
struct V_8 * V_9 = & V_50 -> V_4 ;
if ( V_50 -> V_470 == NULL ||
V_9 -> V_471 ||
V_1 -> V_172 . V_472 > 6 ) {
if ( V_1 -> V_172 . V_473 > 0 ||
V_1 -> V_172 . V_472 > 0 )
F_45 ( L_85 ,
V_1 -> V_172 . V_473 ,
V_1 -> V_172 . V_472 ) ;
V_1 -> V_474 = V_475 ;
} else {
struct V_476 * V_477 = V_50 -> V_470 ;
V_477 += V_50 -> V_470 -> V_478 ;
if ( ! F_303 ( & V_1 -> V_172 ,
V_479 ,
& V_477 -> V_480 ,
1 ) )
F_45 ( L_86 ) ;
V_467 = V_468 | V_481 ;
V_1 -> V_474 = V_482 ;
}
V_1 -> V_483 = 1 ;
return V_467 ;
}
static T_3 F_304 ( struct V_1 * V_1 )
{
T_3 V_467 = V_469 ;
return V_467 ;
}
static void F_305 ( struct V_1 * V_1 )
{
T_3 V_484 = V_469 ;
T_3 V_485 = 0 ;
int V_129 = 0 ;
V_129 = F_144 ( & V_1 -> V_172 , V_486 , & V_485 , 1 ) ;
if ( V_129 <= 0 ) {
F_45 ( L_87 ) ;
goto V_487;
}
switch ( V_485 ) {
case V_488 :
F_45 ( L_88 ) ;
V_1 -> V_489 = V_488 ;
V_484 = F_300 ( V_1 ) ;
break;
case V_490 :
F_45 ( L_89 ) ;
V_1 -> V_489 = V_490 ;
V_484 = F_301 ( V_1 ) ;
break;
case V_491 :
F_45 ( L_90 ) ;
V_1 -> V_489 = V_491 ;
V_484 = F_302 ( V_1 ) ;
break;
case V_492 :
F_45 ( L_91 ) ;
V_1 -> V_489 = V_492 ;
V_484 = F_304 ( V_1 ) ;
break;
default:
F_45 ( L_92 , V_485 ) ;
break;
}
V_487:
V_129 = F_303 ( & V_1 -> V_172 ,
V_493 ,
& V_484 , 1 ) ;
if ( V_129 <= 0 )
F_45 ( L_93 ) ;
}
static int
F_306 ( struct V_1 * V_1 )
{
bool V_494 ;
if ( V_1 -> V_452 ) {
T_1 V_495 [ 16 ] = { 0 } ;
int V_154 = 0 ;
int V_496 ;
bool V_497 ;
V_494 = F_299 ( V_1 , V_495 ) ;
V_498:
if ( V_494 == true ) {
if ( V_1 -> V_499 &&
! F_307 ( & V_495 [ 10 ] , V_1 -> V_252 ) ) {
F_45 ( L_94 ) ;
F_246 ( V_1 ) ;
F_247 ( V_1 ) ;
}
F_45 ( L_95 , V_495 ) ;
V_154 = F_308 ( & V_1 -> V_453 , V_495 , & V_497 ) ;
if ( V_497 ) {
for ( V_496 = 0 ; V_496 < 3 ; V_496 ++ ) {
int V_500 ;
V_500 = F_303 ( & V_1 -> V_172 ,
V_466 + 1 ,
& V_495 [ 1 ] , 3 ) ;
if ( V_500 == 3 ) {
break;
}
}
V_494 = F_299 ( V_1 , V_495 ) ;
if ( V_494 == true ) {
F_45 ( L_96 , V_495 ) ;
goto V_498;
}
} else
V_154 = 0 ;
return V_154 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_45 ( L_97 ) ;
V_1 -> V_452 = false ;
F_290 ( & V_1 -> V_453 , V_1 -> V_452 ) ;
F_309 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_191 ;
}
static void
F_310 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & F_2 ( V_1 ) -> V_4 ;
struct V_24 * V_25 = F_15 ( V_23 -> V_4 . V_7 ) ;
struct V_249 * V_250 = F_154 ( V_23 -> V_4 . V_250 ) ;
F_281 ( V_25 , V_250 -> V_73 , false ) ;
if ( V_250 -> V_501 -> V_259 )
F_282 ( V_25 ,
F_311 ( V_250 ) , false ) ;
F_246 ( V_1 ) ;
F_247 ( V_1 ) ;
F_293 ( V_25 , V_250 -> V_73 ) ;
F_281 ( V_25 , V_250 -> V_73 , true ) ;
if ( V_250 -> V_501 -> V_259 )
F_282 ( V_25 ,
F_311 ( V_250 ) , true ) ;
}
static void
F_312 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_370 [ V_371 ] ;
F_25 ( ! F_313 ( & V_7 -> V_502 . V_503 ) ) ;
if ( ! F_266 ( V_1 , V_370 ) ) {
F_52 ( L_98 ) ;
return;
}
if ( ! V_22 -> V_4 . V_250 )
return;
if ( ! F_154 ( V_22 -> V_4 . V_250 ) -> V_504 )
return;
if ( ! V_1 -> V_252 )
return;
if ( ( V_1 -> V_489 == V_488 ) ||
( ! F_307 ( V_370 , V_1 -> V_252 ) ) ) {
F_45 ( L_99 ,
V_22 -> V_4 . V_206 ) ;
F_310 ( V_1 ) ;
}
}
static bool
F_314 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_464 = 0 ;
T_1 V_505 = V_1 -> V_443 ;
bool V_154 ;
V_1 -> V_483 = 0 ;
V_1 -> V_489 = 0 ;
V_1 -> V_474 = 0 ;
V_154 = F_286 ( V_1 ) ;
if ( ( V_505 != V_1 -> V_443 ) || ! V_154 ) {
return false ;
}
if ( V_1 -> V_11 [ V_329 ] >= 0x11 &&
F_298 ( V_1 , & V_464 ) &&
V_464 != 0 ) {
F_216 ( & V_1 -> V_172 ,
V_465 ,
V_464 ) ;
if ( V_464 & V_506 )
F_248 ( L_100 ) ;
if ( V_464 & ( V_507 | V_508 ) )
F_248 ( L_101 ) ;
}
F_315 ( & V_7 -> V_502 . V_503 , NULL ) ;
F_312 ( V_1 ) ;
F_316 ( & V_7 -> V_502 . V_503 ) ;
return true ;
}
static enum V_509
F_317 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_286 ( V_1 ) )
return V_510 ;
if ( F_1 ( V_1 ) )
return V_511 ;
if ( ! F_143 ( V_11 ) )
return V_511 ;
if ( V_1 -> V_11 [ V_329 ] >= 0x11 &&
V_1 -> V_29 [ 0 ] & V_512 ) {
return V_1 -> V_443 ?
V_511 : V_510 ;
}
if ( F_288 ( V_1 ) )
return V_511 ;
if ( F_318 ( & V_1 -> V_172 . V_513 ) )
return V_511 ;
if ( V_1 -> V_11 [ V_329 ] >= 0x11 ) {
type = V_1 -> V_29 [ 0 ] & V_30 ;
if ( type == V_31 ||
type == V_514 )
return V_515 ;
} else {
type = V_1 -> V_11 [ V_516 ] &
V_517 ;
if ( type == V_518 ||
type == V_519 )
return V_515 ;
}
F_45 ( L_102 ) ;
return V_510 ;
}
static enum V_509
F_319 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_509 V_129 ;
V_129 = F_320 ( V_7 ) ;
if ( V_129 == V_515 )
V_129 = V_511 ;
return V_129 ;
}
static bool F_321 ( struct V_24 * V_25 ,
struct V_2 * V_84 )
{
T_5 V_520 ;
switch ( V_84 -> V_84 ) {
case V_134 :
return true ;
case V_200 :
V_520 = V_521 ;
break;
case V_202 :
V_520 = V_522 ;
break;
case V_204 :
V_520 = V_523 ;
break;
default:
F_114 ( V_84 -> V_84 ) ;
return false ;
}
return F_42 ( V_524 ) & V_520 ;
}
static bool F_322 ( struct V_24 * V_25 ,
struct V_2 * V_84 )
{
T_5 V_520 ;
switch ( V_84 -> V_84 ) {
case V_134 :
return true ;
case V_200 :
V_520 = V_525 ;
break;
case V_202 :
V_520 = V_526 ;
break;
case V_204 :
V_520 = V_527 ;
break;
case V_528 :
V_520 = V_529 ;
break;
default:
F_114 ( V_84 -> V_84 ) ;
return false ;
}
return F_42 ( V_524 ) & V_520 ;
}
static bool F_323 ( struct V_24 * V_25 ,
struct V_2 * V_84 )
{
T_5 V_520 ;
switch ( V_84 -> V_84 ) {
case V_200 :
V_520 = V_530 ;
break;
case V_202 :
V_520 = V_531 ;
break;
case V_204 :
V_520 = V_532 ;
break;
default:
F_114 ( V_84 -> V_84 ) ;
return false ;
}
return F_42 ( V_533 ) & V_520 ;
}
static bool F_324 ( struct V_24 * V_25 ,
struct V_2 * V_84 )
{
T_5 V_520 ;
switch ( V_84 -> V_84 ) {
case V_200 :
V_520 = V_534 ;
break;
case V_202 :
V_520 = V_535 ;
break;
case V_204 :
V_520 = V_536 ;
break;
default:
F_114 ( V_84 -> V_84 ) ;
return false ;
}
return F_42 ( V_533 ) & V_520 ;
}
static bool F_325 ( struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_22 * V_22 = & V_3 -> V_4 ;
enum V_84 V_84 ;
T_5 V_520 ;
F_326 ( V_22 -> V_537 , & V_84 ) ;
switch ( V_84 ) {
case V_134 :
V_520 = V_538 ;
break;
case V_200 :
V_520 = V_539 ;
break;
case V_202 :
V_520 = V_540 ;
break;
default:
F_114 ( V_84 ) ;
return false ;
}
return F_42 ( V_541 ) & V_520 ;
}
static bool F_327 ( struct V_24 * V_25 ,
struct V_2 * V_84 )
{
if ( F_280 ( V_25 ) )
return F_321 ( V_25 , V_84 ) ;
else if ( F_127 ( V_25 ) )
return F_322 ( V_25 , V_84 ) ;
else if ( F_19 ( V_25 ) )
return F_325 ( V_25 , V_84 ) ;
else if ( F_328 ( V_25 ) )
return F_324 ( V_25 , V_84 ) ;
else
return F_323 ( V_25 , V_84 ) ;
}
static struct V_476 *
F_329 ( struct V_1 * V_1 )
{
struct V_50 * V_50 = V_1 -> V_251 ;
if ( V_50 -> V_476 ) {
if ( F_330 ( V_50 -> V_476 ) )
return NULL ;
return F_331 ( V_50 -> V_476 ) ;
} else
return F_332 ( & V_50 -> V_4 ,
& V_1 -> V_172 . V_513 ) ;
}
static void
F_333 ( struct V_1 * V_1 )
{
struct V_50 * V_50 = V_1 -> V_251 ;
struct V_476 * V_476 ;
F_334 ( V_1 ) ;
V_476 = F_329 ( V_1 ) ;
V_50 -> V_470 = V_476 ;
if ( V_1 -> V_542 != V_543 )
V_1 -> V_261 = V_1 -> V_542 == V_544 ;
else
V_1 -> V_261 = F_335 ( V_476 ) ;
}
static void
F_334 ( struct V_1 * V_1 )
{
struct V_50 * V_50 = V_1 -> V_251 ;
F_131 ( V_50 -> V_470 ) ;
V_50 -> V_470 = NULL ;
V_1 -> V_261 = false ;
}
static enum V_509
F_336 ( struct V_50 * V_50 )
{
struct V_8 * V_9 = & V_50 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_509 V_129 ;
enum V_70 V_71 ;
T_1 V_464 = 0 ;
V_71 = F_33 ( V_22 ) ;
F_34 ( F_15 ( V_7 ) , V_71 ) ;
if ( F_1 ( V_1 ) )
V_129 = F_319 ( V_1 ) ;
else if ( F_327 ( F_15 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_129 = F_317 ( V_1 ) ;
else
V_129 = V_510 ;
if ( V_129 == V_510 ) {
V_1 -> V_483 = 0 ;
V_1 -> V_489 = 0 ;
V_1 -> V_474 = 0 ;
if ( V_1 -> V_452 ) {
F_45 ( L_103 ,
V_1 -> V_452 ,
V_1 -> V_453 . V_545 ) ;
V_1 -> V_452 = false ;
F_290 ( & V_1 -> V_453 ,
V_1 -> V_452 ) ;
}
goto V_161;
}
if ( V_22 -> type != V_5 )
V_22 -> type = V_546 ;
F_45 ( L_104 ,
F_337 ( F_23 ( V_1 ) ) ,
F_337 ( F_338 ( V_1 -> V_11 ) ) ) ;
F_141 ( V_1 ) ;
F_145 ( V_1 ) ;
F_289 ( V_1 ) ;
if ( V_1 -> V_452 ) {
V_129 = V_510 ;
goto V_161;
} else if ( V_9 -> V_129 == V_511 ) {
F_315 ( & V_7 -> V_502 . V_503 , NULL ) ;
F_312 ( V_1 ) ;
F_316 ( & V_7 -> V_502 . V_503 ) ;
goto V_161;
}
V_1 -> V_172 . V_473 = 0 ;
V_1 -> V_172 . V_472 = 0 ;
F_333 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_50 -> V_470 )
V_129 = V_511 ;
V_1 -> V_547 = true ;
if ( V_1 -> V_11 [ V_329 ] >= 0x11 &&
F_298 ( V_1 , & V_464 ) &&
V_464 != 0 ) {
F_216 ( & V_1 -> V_172 ,
V_465 ,
V_464 ) ;
if ( V_464 & V_506 )
F_305 ( V_1 ) ;
if ( V_464 & ( V_507 | V_508 ) )
F_248 ( L_101 ) ;
}
V_161:
if ( V_129 != V_511 && ! V_1 -> V_452 )
F_334 ( V_1 ) ;
F_38 ( F_15 ( V_7 ) , V_71 ) ;
return V_129 ;
}
static enum V_509
F_339 ( struct V_8 * V_9 , bool V_548 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
enum V_509 V_129 = V_9 -> V_129 ;
F_45 ( L_105 ,
V_9 -> V_4 . V_549 , V_9 -> V_206 ) ;
if ( ! V_1 -> V_547 )
V_129 = F_336 ( V_1 -> V_251 ) ;
V_1 -> V_547 = false ;
return V_129 ;
}
static void
F_340 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = & F_2 ( V_1 ) -> V_4 ;
struct V_24 * V_25 = F_15 ( V_22 -> V_4 . V_7 ) ;
enum V_70 V_71 ;
F_45 ( L_105 ,
V_9 -> V_4 . V_549 , V_9 -> V_206 ) ;
F_334 ( V_1 ) ;
if ( V_9 -> V_129 != V_511 )
return;
V_71 = F_33 ( V_22 ) ;
F_34 ( V_25 , V_71 ) ;
F_333 ( V_1 ) ;
F_38 ( V_25 , V_71 ) ;
if ( V_22 -> type != V_5 )
V_22 -> type = V_546 ;
}
static int F_341 ( struct V_8 * V_9 )
{
struct V_50 * V_50 = F_28 ( V_9 ) ;
struct V_476 * V_476 ;
V_476 = V_50 -> V_470 ;
if ( V_476 ) {
int V_154 = F_342 ( V_9 , V_476 ) ;
if ( V_154 )
return V_154 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_50 -> V_52 . V_51 ) {
struct V_48 * V_49 ;
V_49 = F_343 ( V_9 -> V_7 ,
V_50 -> V_52 . V_51 ) ;
if ( V_49 ) {
F_344 ( V_9 , V_49 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_345 ( struct V_8 * V_9 )
{
bool V_261 = false ;
struct V_476 * V_476 ;
V_476 = F_28 ( V_9 ) -> V_470 ;
if ( V_476 )
V_261 = F_335 ( V_476 ) ;
return V_261 ;
}
static int
F_346 ( struct V_8 * V_9 ,
struct V_550 * V_551 ,
T_12 V_418 )
{
struct V_24 * V_25 = F_15 ( V_9 -> V_7 ) ;
struct V_50 * V_50 = F_28 ( V_9 ) ;
struct V_22 * V_22 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_22 -> V_4 ) ;
int V_154 ;
V_154 = F_347 ( & V_9 -> V_4 , V_551 , V_418 ) ;
if ( V_154 )
return V_154 ;
if ( V_551 == V_25 -> V_552 ) {
int V_43 = V_418 ;
bool V_261 ;
if ( V_43 == V_1 -> V_542 )
return 0 ;
V_1 -> V_542 = V_43 ;
if ( V_43 == V_543 )
V_261 = F_345 ( V_9 ) ;
else
V_261 = ( V_43 == V_544 ) ;
if ( V_261 == V_1 -> V_261 )
return 0 ;
V_1 -> V_261 = V_261 ;
goto V_130;
}
if ( V_551 == V_25 -> V_553 ) {
bool V_554 = V_1 -> V_267 ;
bool V_555 = V_1 -> V_268 ;
switch ( V_418 ) {
case V_556 :
V_1 -> V_267 = true ;
break;
case V_557 :
V_1 -> V_267 = false ;
V_1 -> V_268 = false ;
break;
case V_558 :
V_1 -> V_267 = false ;
V_1 -> V_268 = true ;
break;
default:
return - V_191 ;
}
if ( V_554 == V_1 -> V_267 &&
V_555 == V_1 -> V_268 )
return 0 ;
goto V_130;
}
if ( F_1 ( V_1 ) &&
V_551 == V_9 -> V_7 -> V_502 . V_559 ) {
if ( V_418 == V_560 ) {
F_45 ( L_106 ) ;
return - V_191 ;
}
if ( F_158 ( V_25 ) &&
V_418 == V_561 ) {
F_45 ( L_107 ) ;
return - V_191 ;
}
if ( V_50 -> V_52 . V_262 == V_418 ) {
return 0 ;
}
V_50 -> V_52 . V_262 = V_418 ;
goto V_130;
}
return - V_191 ;
V_130:
if ( V_22 -> V_4 . V_250 )
F_348 ( V_22 -> V_4 . V_250 ) ;
return 0 ;
}
static int
F_349 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_154 ;
V_154 = F_350 ( V_9 ) ;
if ( V_154 )
return V_154 ;
F_351 ( V_9 ) ;
F_45 ( L_108 ,
V_1 -> V_172 . V_206 , V_9 -> V_562 -> V_563 . V_206 ) ;
V_1 -> V_172 . V_7 = V_9 -> V_562 ;
return F_352 ( & V_1 -> V_172 ) ;
}
static void
F_353 ( struct V_8 * V_9 )
{
F_354 ( & F_4 ( V_9 ) -> V_172 ) ;
F_355 ( V_9 ) ;
}
static void
F_356 ( struct V_8 * V_9 )
{
struct V_50 * V_50 = F_28 ( V_9 ) ;
F_131 ( V_50 -> V_470 ) ;
if ( ! F_357 ( V_50 -> V_476 ) )
F_131 ( V_50 -> V_476 ) ;
if ( V_9 -> V_564 == V_565 )
F_358 ( & V_50 -> V_52 ) ;
F_359 ( V_9 ) ;
F_131 ( V_9 ) ;
}
void F_360 ( struct V_566 * V_23 )
{
struct V_2 * V_3 = F_361 ( V_23 ) ;
struct V_1 * V_1 = & V_3 -> V_567 ;
F_362 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_363 ( & V_1 -> V_312 ) ;
F_32 ( V_1 ) ;
F_186 ( V_1 ) ;
F_36 ( V_1 ) ;
if ( V_1 -> V_118 . V_568 ) {
F_364 ( & V_1 -> V_118 ) ;
V_1 -> V_118 . V_568 = NULL ;
}
}
F_130 ( V_1 ) ;
F_365 ( V_23 ) ;
F_131 ( V_3 ) ;
}
void F_366 ( struct V_22 * V_22 )
{
struct V_1 * V_1 = F_5 ( & V_22 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_363 ( & V_1 -> V_312 ) ;
F_32 ( V_1 ) ;
F_186 ( V_1 ) ;
F_36 ( V_1 ) ;
}
static void F_367 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
F_57 ( & V_25 -> V_72 ) ;
if ( ! F_85 ( V_1 ) )
return;
F_45 ( L_109 ) ;
V_71 = F_33 ( & V_3 -> V_4 ) ;
F_34 ( V_25 , V_71 ) ;
F_189 ( V_1 ) ;
}
void F_368 ( struct V_566 * V_23 )
{
struct V_24 * V_25 = F_15 ( V_23 -> V_7 ) ;
struct V_2 * V_3 = F_361 ( V_23 ) ;
struct V_569 * V_570 = & V_3 -> V_570 ;
struct V_1 * V_1 = & V_3 -> V_567 ;
if ( ! F_155 ( V_25 ) )
V_1 -> V_81 = F_42 ( V_1 -> V_82 ) ;
if ( F_369 ( V_25 ) && V_570 -> V_504 )
F_370 ( V_570 ) ;
if ( F_371 ( V_23 ) -> type != V_5 )
return;
F_32 ( V_1 ) ;
F_372 ( V_23 -> V_7 , V_1 ) ;
F_367 ( V_1 ) ;
F_36 ( V_1 ) ;
}
enum V_571
F_373 ( struct V_2 * V_3 , bool V_572 )
{
struct V_1 * V_1 = & V_3 -> V_567 ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_70 V_71 ;
enum V_571 V_154 = V_573 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_574 )
V_3 -> V_4 . type = V_546 ;
if ( V_572 && V_3 -> V_4 . type == V_5 ) {
F_45 ( L_110 ,
F_44 ( V_3 -> V_84 ) ) ;
return V_575 ;
}
F_45 ( L_111 ,
F_44 ( V_3 -> V_84 ) ,
V_572 ? L_112 : L_113 ) ;
if ( V_572 ) {
V_1 -> V_547 = false ;
return V_573 ;
}
V_71 = F_33 ( V_22 ) ;
F_34 ( V_25 , V_71 ) ;
if ( V_1 -> V_452 ) {
if ( F_306 ( V_1 ) == - V_191 ) {
F_45 ( L_103 ,
V_1 -> V_452 , V_1 -> V_453 . V_545 ) ;
V_1 -> V_452 = false ;
F_290 ( & V_1 -> V_453 ,
V_1 -> V_452 ) ;
V_1 -> V_547 = false ;
goto V_576;
}
}
if ( ! V_1 -> V_452 ) {
if ( ! F_314 ( V_1 ) ) {
V_1 -> V_547 = false ;
goto V_576;
}
}
V_154 = V_575 ;
V_576:
F_38 ( V_25 , V_71 ) ;
return V_154 ;
}
bool F_374 ( struct V_24 * V_25 , enum V_84 V_84 )
{
if ( F_137 ( V_25 ) < 5 )
return false ;
if ( V_84 == V_134 )
return true ;
return F_375 ( V_25 , V_84 ) ;
}
void
F_376 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_50 * V_50 = F_28 ( V_9 ) ;
F_377 ( V_9 ) ;
F_378 ( V_9 ) ;
V_1 -> V_267 = true ;
if ( F_1 ( V_1 ) ) {
F_379 ( V_9 -> V_7 ) ;
F_380 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_502 . V_559 ,
V_577 ) ;
V_50 -> V_52 . V_262 = V_577 ;
}
}
static void F_381 ( struct V_1 * V_1 )
{
V_1 -> V_299 = F_177 () ;
V_1 -> V_303 = V_300 ;
V_1 -> V_305 = V_300 ;
}
static void
F_382 ( struct V_24 * V_25 ,
struct V_1 * V_1 , struct V_578 * V_579 )
{
T_5 V_111 , V_112 , V_113 = 0 , V_580 = 0 ;
struct V_106 V_107 ;
F_75 ( V_25 , V_1 , & V_107 ) ;
V_580 = F_182 ( V_1 ) ;
V_111 = F_42 ( V_107 . V_111 ) ;
V_112 = F_42 ( V_107 . V_112 ) ;
if ( ! F_19 ( V_25 ) ) {
F_53 ( V_107 . V_109 , V_580 ) ;
V_113 = F_42 ( V_107 . V_113 ) ;
}
V_579 -> V_581 = ( V_111 & V_582 ) >>
V_583 ;
V_579 -> V_584 = ( V_111 & V_585 ) >>
V_586 ;
V_579 -> V_587 = ( V_112 & V_588 ) >>
V_589 ;
V_579 -> V_590 = ( V_112 & V_591 ) >>
V_592 ;
if ( F_19 ( V_25 ) ) {
T_13 V_98 = ( V_580 & V_593 ) >>
V_594 ;
if ( V_98 > 0 )
V_579 -> V_595 = ( V_98 - 1 ) * 1000 ;
else
V_579 -> V_595 = 0 ;
} else {
V_579 -> V_595 = ( ( V_113 & V_596 ) >>
V_597 ) * 1000 ;
}
}
static void
F_383 ( const char * V_598 , const struct V_578 * V_579 )
{
F_45 ( L_114 ,
V_598 ,
V_579 -> V_581 , V_579 -> V_584 , V_579 -> V_587 , V_579 -> V_590 , V_579 -> V_595 ) ;
}
static void
F_172 ( struct V_24 * V_25 ,
struct V_1 * V_1 )
{
struct V_578 V_599 ;
struct V_578 * V_600 = & V_1 -> V_601 ;
F_382 ( V_25 , V_1 , & V_599 ) ;
if ( V_599 . V_581 != V_600 -> V_581 || V_599 . V_584 != V_600 -> V_584 || V_599 . V_587 != V_600 -> V_587 ||
V_599 . V_590 != V_600 -> V_590 || V_599 . V_595 != V_600 -> V_595 ) {
F_52 ( L_115 ) ;
F_383 ( L_116 , V_600 ) ;
F_383 ( L_117 , & V_599 ) ;
}
}
static void
F_61 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_578 V_602 , V_194 , V_603 ,
* V_604 = & V_1 -> V_601 ;
F_57 ( & V_25 -> V_72 ) ;
if ( V_604 -> V_595 != 0 )
return;
F_382 ( V_25 , V_1 , & V_602 ) ;
F_383 ( L_118 , & V_602 ) ;
V_194 = V_25 -> V_194 . V_265 . V_605 ;
V_603 . V_581 = 210 * 10 ;
V_603 . V_584 = 50 * 10 ;
V_603 . V_587 = 50 * 10 ;
V_603 . V_590 = 500 * 10 ;
V_603 . V_595 = ( 510 + 100 ) * 10 ;
F_383 ( L_119 , & V_194 ) ;
#define F_384 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_384 ( V_581 ) ;
F_384 ( V_584 ) ;
F_384 ( V_587 ) ;
F_384 ( V_590 ) ;
F_384 ( V_595 ) ;
#undef F_384
#define F_385 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_313 = F_385 ( V_581 ) ;
V_1 -> V_304 = F_385 ( V_584 ) ;
V_1 -> V_306 = F_385 ( V_587 ) ;
V_1 -> V_423 = F_385 ( V_590 ) ;
V_1 -> V_125 = F_385 ( V_595 ) ;
#undef F_385
F_45 ( L_120 ,
V_1 -> V_313 , V_1 -> V_423 ,
V_1 -> V_125 ) ;
F_45 ( L_121 ,
V_1 -> V_304 , V_1 -> V_306 ) ;
V_604 -> V_584 = 1 ;
V_604 -> V_587 = 1 ;
}
static void
F_62 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
bool V_606 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
T_5 V_111 , V_112 , V_113 , V_103 = 0 ;
int div = V_25 -> V_133 / 1000 ;
struct V_106 V_107 ;
enum V_84 V_84 = F_2 ( V_1 ) -> V_84 ;
const struct V_578 * V_579 = & V_1 -> V_601 ;
F_57 ( & V_25 -> V_72 ) ;
F_75 ( V_25 , V_1 , & V_107 ) ;
if ( V_606 ) {
T_5 V_309 = F_182 ( V_1 ) ;
F_8 ( V_309 & V_314 , L_122 ) ;
if ( V_309 & V_101 )
F_45 ( L_123 ) ;
V_309 &= ~ V_101 ;
F_53 ( V_107 . V_109 , V_309 ) ;
}
V_111 = ( V_579 -> V_581 << V_583 ) |
( V_579 -> V_584 << V_586 ) ;
V_112 = ( V_579 -> V_587 << V_589 ) |
( V_579 -> V_590 << V_592 ) ;
if ( F_19 ( V_25 ) ) {
V_113 = F_42 ( V_107 . V_109 ) ;
V_113 &= ~ V_593 ;
V_113 |= ( F_386 ( ( V_579 -> V_595 + 1 ) , 1000 )
<< V_594 ) ;
} else {
V_113 = ( ( 100 * div ) / 2 - 1 ) << V_607 ;
V_113 |= ( F_386 ( V_579 -> V_595 , 1000 )
<< V_597 ) ;
}
if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
V_103 = F_71 ( V_84 ) ;
} else if ( F_280 ( V_25 ) || F_169 ( V_25 ) ) {
if ( V_84 == V_134 )
V_103 = V_608 ;
else
V_103 = V_609 ;
}
V_111 |= V_103 ;
F_53 ( V_107 . V_111 , V_111 ) ;
F_53 ( V_107 . V_112 , V_112 ) ;
if ( F_19 ( V_25 ) )
F_53 ( V_107 . V_109 , V_113 ) ;
else
F_53 ( V_107 . V_113 , V_113 ) ;
F_45 ( L_124 ,
F_42 ( V_107 . V_111 ) ,
F_42 ( V_107 . V_112 ) ,
F_19 ( V_25 ) ?
( F_42 ( V_107 . V_109 ) & V_593 ) :
F_42 ( V_107 . V_113 ) ) ;
}
static void F_372 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
F_72 ( V_1 ) ;
} else {
F_61 ( V_7 , V_1 ) ;
F_62 ( V_7 , V_1 , false ) ;
}
}
static void F_387 ( struct V_24 * V_25 ,
struct V_209 * V_610 ,
int V_611 )
{
struct V_22 * V_23 ;
struct V_2 * V_36 = NULL ;
struct V_1 * V_1 = V_25 -> V_271 . V_567 ;
struct V_249 * V_249 = F_154 ( V_610 -> V_4 . V_250 ) ;
enum V_612 V_132 = V_613 ;
if ( V_611 <= 0 ) {
F_45 ( L_125 ) ;
return;
}
if ( V_1 == NULL ) {
F_45 ( L_126 ) ;
return;
}
V_36 = F_2 ( V_1 ) ;
V_23 = & V_36 -> V_4 ;
V_249 = F_154 ( V_23 -> V_4 . V_250 ) ;
if ( ! V_249 ) {
F_45 ( L_127 ) ;
return;
}
if ( V_25 -> V_271 . type < V_272 ) {
F_45 ( L_128 ) ;
return;
}
if ( V_1 -> V_251 -> V_52 . V_270 -> V_614 ==
V_611 )
V_132 = V_615 ;
if ( V_132 == V_25 -> V_271 . V_616 ) {
F_45 (
L_129 ) ;
return;
}
if ( ! V_610 -> V_4 . V_504 ) {
F_45 ( L_130 ) ;
return;
}
if ( F_137 ( V_25 ) >= 8 && ! F_47 ( V_25 ) ) {
switch ( V_132 ) {
case V_613 :
F_388 ( V_249 , V_617 ) ;
break;
case V_615 :
F_388 ( V_249 , V_618 ) ;
break;
case V_619 :
default:
F_52 ( L_131 ) ;
}
} else if ( F_137 ( V_25 ) > 6 ) {
T_6 V_620 = F_389 ( V_610 -> V_621 ) ;
T_5 V_418 ;
V_418 = F_42 ( V_620 ) ;
if ( V_132 > V_613 ) {
if ( F_74 ( V_25 ) || F_47 ( V_25 ) )
V_418 |= V_622 ;
else
V_418 |= V_623 ;
} else {
if ( F_74 ( V_25 ) || F_47 ( V_25 ) )
V_418 &= ~ V_622 ;
else
V_418 &= ~ V_623 ;
}
F_53 ( V_620 , V_418 ) ;
}
V_25 -> V_271 . V_616 = V_132 ;
F_45 ( L_132 , V_611 ) ;
}
void F_390 ( struct V_1 * V_1 ,
struct V_209 * V_610 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! V_610 -> V_260 ) {
F_45 ( L_133 ) ;
return;
}
F_35 ( & V_25 -> V_271 . V_624 ) ;
if ( F_25 ( V_25 -> V_271 . V_567 ) ) {
F_52 ( L_134 ) ;
goto V_625;
}
V_25 -> V_271 . V_626 = 0 ;
V_25 -> V_271 . V_567 = V_1 ;
V_625:
F_37 ( & V_25 -> V_271 . V_624 ) ;
}
void F_391 ( struct V_1 * V_1 ,
struct V_209 * V_342 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
if ( ! V_342 -> V_260 )
return;
F_35 ( & V_25 -> V_271 . V_624 ) ;
if ( ! V_25 -> V_271 . V_567 ) {
F_37 ( & V_25 -> V_271 . V_624 ) ;
return;
}
if ( V_25 -> V_271 . V_616 == V_615 )
F_387 ( V_25 , V_342 ,
V_1 -> V_251 -> V_52 . V_51 -> V_614 ) ;
V_25 -> V_271 . V_567 = NULL ;
F_37 ( & V_25 -> V_271 . V_624 ) ;
F_363 ( & V_25 -> V_271 . V_627 ) ;
}
static void F_392 ( struct V_315 * V_627 )
{
struct V_24 * V_25 =
F_81 ( V_627 , F_82 ( * V_25 ) , V_271 . V_627 . V_627 ) ;
struct V_1 * V_1 ;
F_35 ( & V_25 -> V_271 . V_624 ) ;
V_1 = V_25 -> V_271 . V_567 ;
if ( ! V_1 )
goto V_625;
if ( V_25 -> V_271 . V_626 )
goto V_625;
if ( V_25 -> V_271 . V_616 != V_615 ) {
struct V_628 * V_250 = F_2 ( V_1 ) -> V_4 . V_4 . V_250 ;
F_387 ( V_25 , F_154 ( V_250 ) -> V_501 ,
V_1 -> V_251 -> V_52 . V_270 -> V_614 ) ;
}
V_625:
F_37 ( & V_25 -> V_271 . V_624 ) ;
}
void F_393 ( struct V_24 * V_25 ,
unsigned int V_629 )
{
struct V_628 * V_250 ;
enum V_73 V_73 ;
if ( V_25 -> V_271 . type == V_630 )
return;
F_183 ( & V_25 -> V_271 . V_627 ) ;
F_35 ( & V_25 -> V_271 . V_624 ) ;
if ( ! V_25 -> V_271 . V_567 ) {
F_37 ( & V_25 -> V_271 . V_624 ) ;
return;
}
V_250 = F_2 ( V_25 -> V_271 . V_567 ) -> V_4 . V_4 . V_250 ;
V_73 = F_154 ( V_250 ) -> V_73 ;
V_629 &= F_394 ( V_73 ) ;
V_25 -> V_271 . V_626 |= V_629 ;
if ( V_629 && V_25 -> V_271 . V_616 == V_615 )
F_387 ( V_25 , F_154 ( V_250 ) -> V_501 ,
V_25 -> V_271 . V_567 -> V_251 -> V_52 . V_51 -> V_614 ) ;
F_37 ( & V_25 -> V_271 . V_624 ) ;
}
void F_395 ( struct V_24 * V_25 ,
unsigned int V_629 )
{
struct V_628 * V_250 ;
enum V_73 V_73 ;
if ( V_25 -> V_271 . type == V_630 )
return;
F_183 ( & V_25 -> V_271 . V_627 ) ;
F_35 ( & V_25 -> V_271 . V_624 ) ;
if ( ! V_25 -> V_271 . V_567 ) {
F_37 ( & V_25 -> V_271 . V_624 ) ;
return;
}
V_250 = F_2 ( V_25 -> V_271 . V_567 ) -> V_4 . V_4 . V_250 ;
V_73 = F_154 ( V_250 ) -> V_73 ;
V_629 &= F_394 ( V_73 ) ;
V_25 -> V_271 . V_626 &= ~ V_629 ;
if ( V_629 && V_25 -> V_271 . V_616 == V_615 )
F_387 ( V_25 , F_154 ( V_250 ) -> V_501 ,
V_25 -> V_271 . V_567 -> V_251 -> V_52 . V_51 -> V_614 ) ;
if ( ! V_25 -> V_271 . V_626 )
F_191 ( & V_25 -> V_271 . V_627 ,
F_190 ( 1000 ) ) ;
F_37 ( & V_25 -> V_271 . V_624 ) ;
}
static struct V_48 *
F_396 ( struct V_50 * V_50 ,
struct V_48 * V_51 )
{
struct V_8 * V_9 = & V_50 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_48 * V_270 = NULL ;
F_397 ( & V_25 -> V_271 . V_627 , F_392 ) ;
F_398 ( & V_25 -> V_271 . V_624 ) ;
if ( F_137 ( V_25 ) <= 6 ) {
F_45 ( L_135 ) ;
return NULL ;
}
if ( V_25 -> V_194 . V_631 != V_272 ) {
F_45 ( L_136 ) ;
return NULL ;
}
V_270 = F_399
( V_7 , V_51 , V_9 ) ;
if ( ! V_270 ) {
F_45 ( L_137 ) ;
return NULL ;
}
V_25 -> V_271 . type = V_25 -> V_194 . V_631 ;
V_25 -> V_271 . V_616 = V_613 ;
F_45 ( L_138 ) ;
return V_270 ;
}
static bool F_400 ( struct V_1 * V_1 ,
struct V_50 * V_50 )
{
struct V_8 * V_9 = & V_50 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_22 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_48 * V_51 = NULL ;
struct V_48 * V_270 = NULL ;
bool V_632 ;
struct V_48 * V_633 ;
struct V_476 * V_476 ;
enum V_73 V_73 = V_97 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_401 ( V_7 ) ) {
F_25 ( ! ( F_280 ( V_25 ) || F_169 ( V_25 ) ) ) ;
F_402 ( L_139 ) ;
return false ;
}
F_32 ( V_1 ) ;
F_381 ( V_1 ) ;
F_372 ( V_7 , V_1 ) ;
F_367 ( V_1 ) ;
F_36 ( V_1 ) ;
V_632 = F_284 ( V_1 ) ;
if ( ! V_632 ) {
F_402 ( L_140 ) ;
goto V_634;
}
F_35 ( & V_7 -> V_502 . V_624 ) ;
V_476 = F_332 ( V_9 , & V_1 -> V_172 . V_513 ) ;
if ( V_476 ) {
if ( F_403 ( V_9 , V_476 ) ) {
F_404 ( V_9 ,
V_476 ) ;
F_405 ( V_9 , V_476 ) ;
} else {
F_131 ( V_476 ) ;
V_476 = F_406 ( - V_191 ) ;
}
} else {
V_476 = F_406 ( - V_635 ) ;
}
V_50 -> V_476 = V_476 ;
F_407 (scan, &connector->probed_modes, head) {
if ( ( V_633 -> type & V_636 ) ) {
V_51 = F_343 ( V_7 , V_633 ) ;
V_270 = F_396 (
V_50 , V_51 ) ;
break;
}
}
if ( ! V_51 && V_25 -> V_194 . V_637 ) {
V_51 = F_343 ( V_7 ,
V_25 -> V_194 . V_637 ) ;
if ( V_51 ) {
V_51 -> type |= V_636 ;
V_9 -> V_264 . V_638 = V_51 -> V_638 ;
V_9 -> V_264 . V_639 = V_51 -> V_639 ;
}
}
F_37 ( & V_7 -> V_502 . V_624 ) ;
if ( F_74 ( V_25 ) || F_47 ( V_25 ) ) {
V_1 -> V_118 . V_568 = F_80 ;
F_408 ( & V_1 -> V_118 ) ;
if ( F_47 ( V_25 ) )
V_73 = F_224 ( V_1 -> V_81 ) ;
else
V_73 = F_225 ( V_1 -> V_81 ) ;
if ( V_73 != V_96 && V_73 != V_89 )
V_73 = V_1 -> V_74 ;
if ( V_73 != V_96 && V_73 != V_89 )
V_73 = V_96 ;
F_45 ( L_141 ,
F_43 ( V_73 ) ) ;
}
F_409 ( & V_50 -> V_52 , V_51 , V_270 ) ;
V_50 -> V_52 . V_640 . V_641 = F_203 ;
F_410 ( V_9 , V_73 ) ;
return true ;
V_634:
F_363 ( & V_1 -> V_312 ) ;
F_32 ( V_1 ) ;
F_186 ( V_1 ) ;
F_36 ( V_1 ) ;
return false ;
}
bool
F_411 ( struct V_2 * V_3 ,
struct V_50 * V_50 )
{
struct V_8 * V_9 = & V_50 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_567 ;
struct V_22 * V_22 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_22 -> V_4 . V_7 ;
struct V_24 * V_25 = F_15 ( V_7 ) ;
enum V_84 V_84 = V_3 -> V_84 ;
int type ;
if ( F_8 ( V_3 -> V_18 < 1 ,
L_142 ,
V_3 -> V_18 , F_44 ( V_84 ) ) )
return false ;
V_1 -> V_74 = V_97 ;
if ( F_137 ( V_25 ) >= 9 )
V_1 -> V_163 = F_97 ;
else if ( F_135 ( V_25 ) || F_100 ( V_25 ) )
V_1 -> V_163 = F_95 ;
else if ( F_127 ( V_25 ) )
V_1 -> V_163 = F_94 ;
else
V_1 -> V_163 = F_92 ;
if ( F_137 ( V_25 ) >= 9 )
V_1 -> V_165 = F_101 ;
else
V_1 -> V_165 = F_98 ;
if ( F_155 ( V_25 ) )
V_1 -> V_642 = V_643 ;
V_1 -> V_81 = F_42 ( V_1 -> V_82 ) ;
V_1 -> V_251 = V_50 ;
if ( F_374 ( V_25 , V_84 ) )
type = V_565 ;
else
type = V_644 ;
if ( type == V_565 )
V_22 -> type = V_5 ;
if ( F_25 ( ( F_74 ( V_25 ) || F_47 ( V_25 ) ) &&
F_1 ( V_1 ) && V_84 != V_200 && V_84 != V_202 ) )
return false ;
F_45 ( L_143 ,
type == V_565 ? L_144 : L_145 ,
F_44 ( V_84 ) ) ;
F_412 ( V_7 , V_9 , & V_645 , type ) ;
F_413 ( V_9 , & V_646 ) ;
V_9 -> V_647 = true ;
V_9 -> V_648 = 0 ;
F_132 ( V_1 ) ;
F_397 ( & V_1 -> V_312 ,
F_187 ) ;
F_414 ( V_50 , V_22 ) ;
if ( F_155 ( V_25 ) )
V_50 -> V_649 = V_650 ;
else
V_50 -> V_649 = V_651 ;
switch ( V_84 ) {
case V_134 :
V_22 -> V_537 = V_652 ;
break;
case V_200 :
V_22 -> V_537 = V_653 ;
if ( F_415 ( V_25 , 0 , V_654 ) )
V_22 -> V_537 = V_652 ;
break;
case V_202 :
V_22 -> V_537 = V_655 ;
break;
case V_204 :
V_22 -> V_537 = V_656 ;
break;
case V_528 :
V_22 -> V_537 = V_657 ;
break;
default:
F_416 () ;
}
if ( F_417 ( V_25 ) && ! F_1 ( V_1 ) &&
( V_84 == V_200 || V_84 == V_202 || V_84 == V_204 ) )
F_418 ( V_3 ,
V_50 -> V_4 . V_4 . V_549 ) ;
if ( ! F_400 ( V_1 , V_50 ) ) {
F_130 ( V_1 ) ;
F_362 ( V_3 ) ;
goto V_658;
}
F_376 ( V_1 , V_9 ) ;
if ( F_139 ( V_25 ) && ! F_328 ( V_25 ) ) {
T_5 V_348 = F_42 ( V_659 ) ;
F_53 ( V_659 , ( V_348 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_658:
F_359 ( V_9 ) ;
return false ;
}
bool F_419 ( struct V_6 * V_7 ,
T_6 V_82 ,
enum V_84 V_84 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
struct V_2 * V_3 ;
struct V_22 * V_22 ;
struct V_566 * V_23 ;
struct V_50 * V_50 ;
V_3 = F_420 ( sizeof( * V_3 ) , V_207 ) ;
if ( ! V_3 )
return false ;
V_50 = F_421 () ;
if ( ! V_50 )
goto V_660;
V_22 = & V_3 -> V_4 ;
V_23 = & V_22 -> V_4 ;
if ( F_422 ( V_7 , & V_22 -> V_4 , & V_661 ,
V_662 , L_146 , F_44 ( V_84 ) ) )
goto V_663;
V_22 -> V_664 = F_153 ;
V_22 -> V_665 = F_229 ;
V_22 -> V_649 = F_217 ;
V_22 -> V_666 = F_226 ;
V_22 -> V_667 = F_366 ;
if ( F_47 ( V_25 ) ) {
V_22 -> V_668 = F_262 ;
V_22 -> V_669 = F_259 ;
V_22 -> V_321 = F_251 ;
V_22 -> V_670 = F_236 ;
V_22 -> V_671 = F_264 ;
} else if ( F_74 ( V_25 ) ) {
V_22 -> V_668 = F_257 ;
V_22 -> V_669 = F_255 ;
V_22 -> V_321 = F_251 ;
V_22 -> V_670 = F_235 ;
} else {
V_22 -> V_669 = F_253 ;
V_22 -> V_321 = F_250 ;
if ( F_137 ( V_25 ) >= 5 )
V_22 -> V_670 = F_234 ;
}
V_3 -> V_84 = V_84 ;
V_3 -> V_567 . V_82 = V_82 ;
V_3 -> V_18 = 4 ;
V_22 -> type = V_546 ;
if ( F_47 ( V_25 ) ) {
if ( V_84 == V_204 )
V_22 -> V_672 = 1 << 2 ;
else
V_22 -> V_672 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_22 -> V_672 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_22 -> V_673 = 0 ;
V_22 -> V_84 = V_84 ;
V_3 -> V_674 = F_373 ;
V_25 -> V_675 . V_676 [ V_84 ] = V_3 ;
if ( ! F_411 ( V_3 , V_50 ) )
goto V_677;
return true ;
V_677:
F_365 ( V_23 ) ;
V_663:
F_131 ( V_50 ) ;
V_660:
F_131 ( V_3 ) ;
return false ;
}
void F_423 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_678 ; V_43 ++ ) {
struct V_2 * V_3 = V_25 -> V_675 . V_676 [ V_43 ] ;
if ( ! V_3 || ! V_3 -> V_567 . V_449 )
continue;
if ( V_3 -> V_567 . V_452 )
F_424 ( & V_3 -> V_567 . V_453 ) ;
}
}
void F_425 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = F_15 ( V_7 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_678 ; V_43 ++ ) {
struct V_2 * V_3 = V_25 -> V_675 . V_676 [ V_43 ] ;
int V_154 ;
if ( ! V_3 || ! V_3 -> V_567 . V_449 )
continue;
V_154 = F_426 ( & V_3 -> V_567 . V_453 ) ;
if ( V_154 )
F_306 ( & V_3 -> V_567 ) ;
}
}
