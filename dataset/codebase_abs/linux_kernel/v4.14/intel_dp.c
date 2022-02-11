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
static int F_7 ( T_1 V_10 )
{
switch ( V_10 ) {
default:
F_8 ( 1 , L_1 ,
V_10 ) ;
case V_11 :
return 1 ;
case V_12 :
return 2 ;
case V_13 :
return 3 ;
}
}
static void F_9 ( struct V_1 * V_1 )
{
int V_14 , V_15 ;
V_15 = F_7 ( V_1 -> V_16 [ V_17 ] ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
V_1 -> V_18 [ V_14 ] = V_19 [ V_14 ] ;
V_1 -> V_20 = V_15 ;
}
static int F_10 ( struct V_1 * V_1 )
{
return V_1 -> V_21 [ V_1 -> V_22 - 1 ] ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_23 = V_3 -> V_24 ;
int V_25 = F_12 ( V_1 -> V_16 ) ;
return F_13 ( V_23 , V_25 ) ;
}
int F_14 ( struct V_1 * V_1 )
{
return V_1 -> V_26 ;
}
int
F_15 ( int V_27 , int V_28 )
{
return F_16 ( V_27 * V_28 , 8 ) ;
}
int
F_17 ( int V_29 , int V_24 )
{
return V_29 * V_24 ;
}
static int
F_18 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
int V_34 = V_33 -> V_35 ;
int V_36 ;
int type = V_1 -> V_37 [ 0 ] & V_38 ;
if ( type != V_39 )
return V_34 ;
V_36 = F_20 ( V_1 -> V_16 ,
V_1 -> V_37 ) ;
if ( V_36 != 0 )
V_34 = F_13 ( V_34 , V_36 ) ;
return V_34 ;
}
static void
F_21 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
enum V_41 V_41 = V_40 -> V_41 ;
const int * V_42 ;
int V_43 ;
T_2 V_44 ;
F_22 ( V_1 -> V_42 || V_1 -> V_45 ) ;
if ( F_23 ( V_33 ) ) {
V_42 = V_46 ;
V_43 = F_24 ( V_46 ) ;
} else if ( F_25 ( V_33 ) ) {
V_42 = V_47 ;
V_43 = F_24 ( V_47 ) ;
V_44 = F_26 ( V_48 ) & V_49 ;
if ( V_41 == V_50 || V_41 == V_51 ||
V_44 == V_52 )
V_43 -= 2 ;
} else if ( F_27 ( V_33 ) ) {
V_42 = V_53 ;
V_43 = F_24 ( V_53 ) ;
} else {
V_42 = V_19 ;
V_43 = F_24 ( V_19 ) ;
}
if ( ! F_28 ( V_1 ) )
V_43 -- ;
V_1 -> V_42 = V_42 ;
V_1 -> V_45 = V_43 ;
}
static int F_29 ( const int * V_42 , int V_54 ,
const int * V_18 , int V_55 ,
int * V_21 )
{
int V_14 = 0 , V_56 = 0 , V_57 = 0 ;
while ( V_14 < V_54 && V_56 < V_55 ) {
if ( V_42 [ V_14 ] == V_18 [ V_56 ] ) {
if ( F_22 ( V_57 >= V_58 ) )
return V_57 ;
V_21 [ V_57 ] = V_42 [ V_14 ] ;
++ V_57 ;
++ V_14 ;
++ V_56 ;
} else if ( V_42 [ V_14 ] < V_18 [ V_56 ] ) {
++ V_14 ;
} else {
++ V_56 ;
}
}
return V_57 ;
}
static int F_30 ( const int * V_59 , int V_60 , int V_61 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_60 ; V_14 ++ )
if ( V_61 == V_59 [ V_14 ] )
return V_14 ;
return - 1 ;
}
static void F_31 ( struct V_1 * V_1 )
{
F_22 ( ! V_1 -> V_45 || ! V_1 -> V_20 ) ;
V_1 -> V_22 = F_29 ( V_1 -> V_42 ,
V_1 -> V_45 ,
V_1 -> V_18 ,
V_1 -> V_20 ,
V_1 -> V_21 ) ;
if ( F_22 ( V_1 -> V_22 == 0 ) ) {
V_1 -> V_21 [ 0 ] = V_19 [ 0 ] ;
V_1 -> V_22 = 1 ;
}
}
static int F_32 ( struct V_1 * V_1 ,
int V_62 )
{
const int * V_21 = V_1 -> V_21 ;
int V_14 , V_63 = V_1 -> V_22 ;
for ( V_14 = 0 ; V_14 < V_63 ; V_14 ++ ) {
if ( V_21 [ V_63 - V_14 - 1 ] <= V_62 )
return V_63 - V_14 ;
}
return 0 ;
}
static bool F_33 ( struct V_1 * V_1 , int V_64 ,
T_3 V_65 )
{
if ( V_64 == 0 ||
V_64 > V_1 -> V_66 )
return false ;
if ( V_65 == 0 ||
V_65 > F_14 ( V_1 ) )
return false ;
return true ;
}
int F_34 ( struct V_1 * V_1 ,
int V_64 , T_3 V_65 )
{
int V_67 ;
V_67 = F_30 ( V_1 -> V_21 ,
V_1 -> V_22 ,
V_64 ) ;
if ( V_67 > 0 ) {
V_1 -> V_66 = V_1 -> V_21 [ V_67 - 1 ] ;
V_1 -> V_26 = V_65 ;
} else if ( V_65 > 1 ) {
V_1 -> V_66 = F_10 ( V_1 ) ;
V_1 -> V_26 = V_65 >> 1 ;
} else {
F_35 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static enum V_68
F_36 ( struct V_8 * V_9 ,
struct V_69 * V_70 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_71 * V_71 = F_37 ( V_9 ) ;
struct V_69 * V_72 = V_71 -> V_73 . V_72 ;
int V_74 = V_70 -> clock ;
int V_62 , V_75 , V_24 , V_29 ;
int V_34 ;
V_34 = F_18 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_72 ) {
if ( V_70 -> V_76 > V_72 -> V_76 )
return V_77 ;
if ( V_70 -> V_78 > V_72 -> V_78 )
return V_77 ;
V_74 = V_72 -> clock ;
}
V_29 = F_38 ( V_1 ) ;
V_24 = F_14 ( V_1 ) ;
V_62 = F_17 ( V_29 , V_24 ) ;
V_75 = F_15 ( V_74 , 18 ) ;
if ( V_75 > V_62 || V_74 > V_34 )
return V_79 ;
if ( V_70 -> clock < 10000 )
return V_80 ;
if ( V_70 -> V_81 & V_82 )
return V_83 ;
return V_84 ;
}
T_4 F_39 ( const T_3 * V_85 , int V_86 )
{
int V_14 ;
T_4 V_87 = 0 ;
if ( V_86 > 4 )
V_86 = 4 ;
for ( V_14 = 0 ; V_14 < V_86 ; V_14 ++ )
V_87 |= ( ( T_4 ) V_85 [ V_14 ] ) << ( ( 3 - V_14 ) * 8 ) ;
return V_87 ;
}
static void F_40 ( T_4 V_85 , T_3 * V_88 , int V_89 )
{
int V_14 ;
if ( V_89 > 4 )
V_89 = 4 ;
for ( V_14 = 0 ; V_14 < V_89 ; V_14 ++ )
V_88 [ V_14 ] = V_85 >> ( ( 3 - V_14 ) * 8 ) ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_42 ( V_33 , V_1 -> V_90 ) ;
F_43 ( & V_33 -> V_91 ) ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_45 ( & V_33 -> V_91 ) ;
F_46 ( V_33 , V_1 -> V_90 ) ;
}
static void
F_47 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_92 V_92 = V_1 -> V_93 ;
bool V_94 , V_95 = false ;
enum V_96 V_97 = F_48 ( V_92 ) ;
enum V_98 V_99 = F_49 ( V_92 ) ;
T_4 V_100 ;
if ( F_8 ( F_26 ( V_1 -> V_101 ) & V_102 ,
L_3 ,
F_50 ( V_92 ) , F_51 ( V_3 -> V_41 ) ) )
return;
F_52 ( L_4 ,
F_50 ( V_92 ) , F_51 ( V_3 -> V_41 ) ) ;
V_100 = F_26 ( V_1 -> V_101 ) & V_103 ;
V_100 |= V_104 | V_105 ;
V_100 |= F_53 ( 1 ) ;
V_100 |= V_106 ;
if ( F_54 ( V_33 ) )
V_100 |= F_55 ( V_92 ) ;
else if ( V_92 == V_107 )
V_100 |= V_108 ;
V_94 = F_26 ( F_56 ( V_92 ) ) & V_109 ;
if ( ! V_94 ) {
V_95 = F_54 ( V_33 ) &&
! F_57 ( V_33 , V_97 , V_99 , true ) ;
if ( F_58 ( V_33 , V_92 , F_54 ( V_33 ) ?
& V_110 [ 0 ] . V_111 : & V_112 [ 0 ] . V_111 ) ) {
F_35 ( L_5 ,
F_50 ( V_92 ) ) ;
return;
}
}
F_59 ( V_1 -> V_101 , V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
F_59 ( V_1 -> V_101 , V_100 | V_102 ) ;
F_60 ( V_1 -> V_101 ) ;
F_59 ( V_1 -> V_101 , V_100 & ~ V_102 ) ;
F_60 ( V_1 -> V_101 ) ;
if ( ! V_94 ) {
F_61 ( V_33 , V_92 ) ;
if ( V_95 )
F_57 ( V_33 , V_97 , V_99 , false ) ;
}
}
static enum V_92 F_62 ( struct V_32 * V_33 )
{
struct V_30 * V_31 ;
unsigned int V_113 = ( 1 << V_114 ) | ( 1 << V_107 ) ;
F_63 (&dev_priv->drm, encoder) {
struct V_1 * V_1 ;
if ( V_31 -> type != V_115 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
if ( V_31 -> type == V_5 ) {
F_22 ( V_1 -> V_116 != V_117 &&
V_1 -> V_116 != V_1 -> V_93 ) ;
if ( V_1 -> V_93 != V_117 )
V_113 &= ~ ( 1 << V_1 -> V_93 ) ;
} else {
F_22 ( V_1 -> V_93 != V_117 ) ;
if ( V_1 -> V_116 != V_117 )
V_113 &= ~ ( 1 << V_1 -> V_116 ) ;
}
}
if ( V_113 == 0 )
return V_117 ;
return F_64 ( V_113 ) - 1 ;
}
static enum V_92
F_65 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_92 V_92 ;
F_66 ( & V_33 -> V_91 ) ;
F_22 ( ! F_1 ( V_1 ) ) ;
F_22 ( V_1 -> V_116 != V_117 &&
V_1 -> V_116 != V_1 -> V_93 ) ;
if ( V_1 -> V_93 != V_117 )
return V_1 -> V_93 ;
V_92 = F_62 ( V_33 ) ;
if ( F_22 ( V_92 == V_117 ) )
V_92 = V_114 ;
F_67 ( V_7 , V_92 ) ;
V_1 -> V_93 = V_92 ;
F_52 ( L_6 ,
F_50 ( V_1 -> V_93 ) ,
F_51 ( V_3 -> V_41 ) ) ;
F_68 ( V_7 , V_1 ) ;
F_69 ( V_7 , V_1 , true ) ;
F_47 ( V_1 ) ;
return V_1 -> V_93 ;
}
static int
F_70 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_66 ( & V_33 -> V_91 ) ;
F_22 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_118 )
return 0 ;
V_1 -> V_118 = false ;
F_69 ( V_7 , V_1 , false ) ;
return 0 ;
}
static bool F_71 ( struct V_32 * V_33 ,
enum V_92 V_92 )
{
return F_26 ( F_72 ( V_92 ) ) & V_119 ;
}
static bool F_73 ( struct V_32 * V_33 ,
enum V_92 V_92 )
{
return F_26 ( F_74 ( V_92 ) ) & V_120 ;
}
static bool F_75 ( struct V_32 * V_33 ,
enum V_92 V_92 )
{
return true ;
}
static enum V_92
F_76 ( struct V_32 * V_33 ,
enum V_41 V_41 ,
T_5 V_121 )
{
enum V_92 V_92 ;
for ( V_92 = V_114 ; V_92 <= V_107 ; V_92 ++ ) {
T_2 V_122 = F_26 ( F_77 ( V_92 ) ) &
V_123 ;
if ( V_122 != F_78 ( V_41 ) )
continue;
if ( ! V_121 ( V_33 , V_92 ) )
continue;
return V_92 ;
}
return V_117 ;
}
static void
F_79 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
F_66 ( & V_33 -> V_91 ) ;
V_1 -> V_93 = F_76 ( V_33 , V_41 ,
F_71 ) ;
if ( V_1 -> V_93 == V_117 )
V_1 -> V_93 = F_76 ( V_33 , V_41 ,
F_73 ) ;
if ( V_1 -> V_93 == V_117 )
V_1 -> V_93 = F_76 ( V_33 , V_41 ,
F_75 ) ;
if ( V_1 -> V_93 == V_117 ) {
F_52 ( L_7 ,
F_51 ( V_41 ) ) ;
return;
}
F_52 ( L_8 ,
F_51 ( V_41 ) , F_50 ( V_1 -> V_93 ) ) ;
F_68 ( V_7 , V_1 ) ;
F_69 ( V_7 , V_1 , false ) ;
}
void F_80 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = & V_33 -> V_124 ;
struct V_30 * V_31 ;
if ( F_22 ( ! F_81 ( V_33 ) && ! F_54 ( V_33 ) &&
! F_23 ( V_33 ) ) )
return;
F_63 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_31 -> type != V_115 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
F_22 ( V_1 -> V_116 != V_117 ) ;
if ( V_31 -> type != V_5 )
continue;
if ( F_23 ( V_33 ) )
V_1 -> V_118 = true ;
else
V_1 -> V_93 = V_117 ;
}
}
static void F_82 ( struct V_32 * V_33 ,
struct V_1 * V_1 ,
struct V_125 * V_126 )
{
int V_127 = 0 ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
if ( F_23 ( V_33 ) )
V_127 = F_70 ( V_1 ) ;
else if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
V_127 = F_65 ( V_1 ) ;
V_126 -> V_128 = F_74 ( V_127 ) ;
V_126 -> V_129 = F_72 ( V_127 ) ;
V_126 -> V_130 = F_77 ( V_127 ) ;
V_126 -> V_131 = F_83 ( V_127 ) ;
if ( ! F_23 ( V_33 ) && ! F_84 ( V_33 ) )
V_126 -> V_132 = F_85 ( V_127 ) ;
}
static T_6
F_86 ( struct V_1 * V_1 )
{
struct V_125 V_126 ;
F_82 ( F_19 ( F_3 ( V_1 ) ) , V_1 ,
& V_126 ) ;
return V_126 . V_128 ;
}
static T_6
F_87 ( struct V_1 * V_1 )
{
struct V_125 V_126 ;
F_82 ( F_19 ( F_3 ( V_1 ) ) , V_1 ,
& V_126 ) ;
return V_126 . V_129 ;
}
static int F_88 ( struct V_133 * V_134 , unsigned long V_135 ,
void * V_136 )
{
struct V_1 * V_1 = F_89 ( V_134 , F_90 ( * V_1 ) ,
V_137 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_135 != V_138 )
return 0 ;
F_41 ( V_1 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
enum V_92 V_92 = F_65 ( V_1 ) ;
T_6 V_139 , V_140 ;
T_2 V_132 ;
V_139 = F_74 ( V_92 ) ;
V_140 = F_85 ( V_92 ) ;
V_132 = F_26 ( V_140 ) ;
V_132 &= V_141 ;
F_59 ( V_140 , V_132 | 0x1F ) ;
F_59 ( V_139 , V_142 | V_143 ) ;
F_91 ( V_1 -> V_144 ) ;
}
F_44 ( V_1 ) ;
return 0 ;
}
static bool F_92 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_66 ( & V_33 -> V_91 ) ;
if ( ( F_81 ( V_33 ) || F_54 ( V_33 ) ) &&
V_1 -> V_93 == V_117 )
return false ;
return ( F_26 ( F_87 ( V_1 ) ) & V_119 ) != 0 ;
}
static bool F_93 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_66 ( & V_33 -> V_91 ) ;
if ( ( F_81 ( V_33 ) || F_54 ( V_33 ) ) &&
V_1 -> V_93 == V_117 )
return false ;
return F_26 ( F_86 ( V_1 ) ) & V_120 ;
}
static void
F_94 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_92 ( V_1 ) && ! F_93 ( V_1 ) ) {
F_8 ( 1 , L_9 ) ;
F_52 ( L_10 ,
F_26 ( F_87 ( V_1 ) ) ,
F_26 ( F_86 ( V_1 ) ) ) ;
}
}
static T_4
F_95 ( struct V_1 * V_1 , bool V_145 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_6 V_146 = V_1 -> V_147 ;
T_4 V_148 ;
bool V_149 ;
#define F_96 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_145 )
V_149 = F_97 ( V_33 -> V_150 , F_96 ,
F_98 ( 10 ) ) ;
else
V_149 = F_99 ( F_96 , 10 ) == 0 ;
if ( ! V_149 )
F_35 ( L_11 ,
V_145 ) ;
#undef F_96
return V_148 ;
}
static T_4 F_100 ( struct V_1 * V_1 , int V_67 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_67 )
return 0 ;
return F_101 ( V_33 -> V_151 , 2000 ) ;
}
static T_4 F_102 ( struct V_1 * V_1 , int V_67 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_67 )
return 0 ;
if ( V_3 -> V_41 == V_50 )
return F_101 ( V_33 -> V_152 . V_153 . V_152 , 2000 ) ;
else
return F_101 ( V_33 -> V_151 , 2000 ) ;
}
static T_4 F_103 ( struct V_1 * V_1 , int V_67 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_41 != V_50 && F_104 ( V_33 ) ) {
switch ( V_67 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_102 ( V_1 , V_67 ) ;
}
static T_4 F_105 ( struct V_1 * V_1 , int V_67 )
{
return V_67 ? 0 : 1 ;
}
static T_4 F_106 ( struct V_1 * V_1 ,
bool V_145 ,
int V_154 ,
T_4 V_155 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_4 V_156 , V_157 ;
if ( F_107 ( V_33 ) )
V_156 = 3 ;
else
V_156 = 5 ;
if ( F_108 ( V_33 ) && V_3 -> V_41 == V_50 )
V_157 = V_158 ;
else
V_157 = V_159 ;
return V_160 |
V_161 |
( V_145 ? V_162 : 0 ) |
V_163 |
V_157 |
V_164 |
( V_154 << V_165 ) |
( V_156 << V_166 ) |
( V_155 << V_167 ) ;
}
static T_4 F_109 ( struct V_1 * V_1 ,
bool V_145 ,
int V_154 ,
T_4 V_136 )
{
return V_160 |
V_161 |
( V_145 ? V_162 : 0 ) |
V_163 |
V_168 |
V_164 |
( V_154 << V_165 ) |
F_110 ( 32 ) |
F_111 ( 32 ) ;
}
static int
F_112 ( struct V_1 * V_1 ,
const T_3 * V_169 , int V_154 ,
T_3 * V_170 , int V_171 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_6 V_146 = V_1 -> V_147 ;
T_4 V_155 ;
int V_14 , V_172 , V_173 ;
T_4 V_148 ;
int V_174 , clock = 0 ;
bool V_145 = F_113 ( V_33 ) ;
bool V_175 ;
F_41 ( V_1 ) ;
V_175 = F_114 ( V_1 ) ;
F_115 ( & V_33 -> V_176 , 0 ) ;
F_94 ( V_1 ) ;
for ( V_174 = 0 ; V_174 < 3 ; V_174 ++ ) {
V_148 = F_116 ( V_146 ) ;
if ( ( V_148 & V_160 ) == 0 )
break;
F_91 ( 1 ) ;
}
if ( V_174 == 3 ) {
static T_2 V_177 = - 1 ;
const T_2 V_148 = F_26 ( V_146 ) ;
if ( V_148 != V_177 ) {
F_8 ( 1 , L_12 ,
V_148 ) ;
V_177 = V_148 ;
}
V_172 = - V_178 ;
goto V_179;
}
if ( F_22 ( V_154 > 20 || V_171 > 20 ) ) {
V_172 = - V_180 ;
goto V_179;
}
while ( ( V_155 = V_1 -> V_181 ( V_1 , clock ++ ) ) ) {
T_2 V_182 = V_1 -> V_183 ( V_1 ,
V_145 ,
V_154 ,
V_155 ) ;
for ( V_174 = 0 ; V_174 < 5 ; V_174 ++ ) {
for ( V_14 = 0 ; V_14 < V_154 ; V_14 += 4 )
F_59 ( V_1 -> V_184 [ V_14 >> 2 ] ,
F_39 ( V_169 + V_14 ,
V_154 - V_14 ) ) ;
F_59 ( V_146 , V_182 ) ;
V_148 = F_95 ( V_1 , V_145 ) ;
F_59 ( V_146 ,
V_148 |
V_161 |
V_163 |
V_164 ) ;
if ( V_148 & V_163 )
continue;
if ( V_148 & V_164 ) {
F_117 ( 400 , 500 ) ;
continue;
}
if ( V_148 & V_161 )
goto V_149;
}
}
if ( ( V_148 & V_161 ) == 0 ) {
F_35 ( L_13 , V_148 ) ;
V_172 = - V_178 ;
goto V_179;
}
V_149:
if ( V_148 & V_164 ) {
F_35 ( L_14 , V_148 ) ;
V_172 = - V_185 ;
goto V_179;
}
if ( V_148 & V_163 ) {
F_52 ( L_15 , V_148 ) ;
V_172 = - V_186 ;
goto V_179;
}
V_173 = ( ( V_148 & V_187 ) >>
V_165 ) ;
if ( V_173 == 0 || V_173 > 20 ) {
F_52 ( L_16 ,
V_173 ) ;
F_117 ( 1000 , 1500 ) ;
V_172 = - V_178 ;
goto V_179;
}
if ( V_173 > V_171 )
V_173 = V_171 ;
for ( V_14 = 0 ; V_14 < V_173 ; V_14 += 4 )
F_40 ( F_26 ( V_1 -> V_184 [ V_14 >> 2 ] ) ,
V_170 + V_14 , V_173 - V_14 ) ;
V_172 = V_173 ;
V_179:
F_115 ( & V_33 -> V_176 , V_188 ) ;
if ( V_175 )
F_118 ( V_1 , false ) ;
F_44 ( V_1 ) ;
return V_172 ;
}
static T_7
F_119 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
struct V_1 * V_1 = F_89 ( V_190 , struct V_1 , V_190 ) ;
T_3 V_193 [ 20 ] , V_194 [ 20 ] ;
T_8 V_195 , V_196 ;
int V_172 ;
V_193 [ 0 ] = ( V_192 -> V_197 << 4 ) |
( ( V_192 -> V_198 >> 16 ) & 0xf ) ;
V_193 [ 1 ] = ( V_192 -> V_198 >> 8 ) & 0xff ;
V_193 [ 2 ] = V_192 -> V_198 & 0xff ;
V_193 [ 3 ] = V_192 -> V_43 - 1 ;
switch ( V_192 -> V_197 & ~ V_199 ) {
case V_200 :
case V_201 :
case V_202 :
V_195 = V_192 -> V_43 ? V_203 + V_192 -> V_43 : V_204 ;
V_196 = 2 ;
if ( F_22 ( V_195 > 20 ) )
return - V_180 ;
F_22 ( ! V_192 -> V_205 != ! V_192 -> V_43 ) ;
if ( V_192 -> V_205 )
memcpy ( V_193 + V_203 , V_192 -> V_205 , V_192 -> V_43 ) ;
V_172 = F_112 ( V_1 , V_193 , V_195 , V_194 , V_196 ) ;
if ( V_172 > 0 ) {
V_192 -> V_206 = V_194 [ 0 ] >> 4 ;
if ( V_172 > 1 ) {
V_172 = F_120 ( int , V_194 [ 1 ] , 0 , V_192 -> V_43 ) ;
} else {
V_172 = V_192 -> V_43 ;
}
}
break;
case V_207 :
case V_208 :
V_195 = V_192 -> V_43 ? V_203 : V_204 ;
V_196 = V_192 -> V_43 + 1 ;
if ( F_22 ( V_196 > 20 ) )
return - V_180 ;
V_172 = F_112 ( V_1 , V_193 , V_195 , V_194 , V_196 ) ;
if ( V_172 > 0 ) {
V_192 -> V_206 = V_194 [ 0 ] >> 4 ;
V_172 -- ;
memcpy ( V_192 -> V_205 , V_194 + 1 , V_172 ) ;
}
break;
default:
V_172 = - V_209 ;
break;
}
return V_172 ;
}
static enum V_41 F_121 ( struct V_32 * V_33 ,
enum V_41 V_41 )
{
const struct V_210 * V_211 =
& V_33 -> V_212 . V_213 [ V_41 ] ;
enum V_41 V_214 ;
if ( ! V_211 -> V_215 ) {
F_52 ( L_17 ,
F_51 ( V_41 ) , F_51 ( V_41 ) ) ;
return V_41 ;
}
switch ( V_211 -> V_215 ) {
case V_216 :
V_214 = V_50 ;
break;
case V_217 :
V_214 = V_218 ;
break;
case V_219 :
V_214 = V_220 ;
break;
case V_221 :
V_214 = V_51 ;
break;
default:
F_122 ( V_211 -> V_215 ) ;
V_214 = V_50 ;
break;
}
F_52 ( L_18 ,
F_51 ( V_214 ) , F_51 ( V_41 ) ) ;
return V_214 ;
}
static T_6 F_123 ( struct V_32 * V_33 ,
enum V_41 V_41 )
{
switch ( V_41 ) {
case V_218 :
case V_220 :
case V_51 :
return F_124 ( V_41 ) ;
default:
F_122 ( V_41 ) ;
return F_124 ( V_218 ) ;
}
}
static T_6 F_125 ( struct V_32 * V_33 ,
enum V_41 V_41 , int V_67 )
{
switch ( V_41 ) {
case V_218 :
case V_220 :
case V_51 :
return F_126 ( V_41 , V_67 ) ;
default:
F_122 ( V_41 ) ;
return F_126 ( V_218 , V_67 ) ;
}
}
static T_6 F_127 ( struct V_32 * V_33 ,
enum V_41 V_41 )
{
switch ( V_41 ) {
case V_50 :
return F_124 ( V_41 ) ;
case V_218 :
case V_220 :
case V_51 :
return F_128 ( V_41 ) ;
default:
F_122 ( V_41 ) ;
return F_124 ( V_50 ) ;
}
}
static T_6 F_129 ( struct V_32 * V_33 ,
enum V_41 V_41 , int V_67 )
{
switch ( V_41 ) {
case V_50 :
return F_126 ( V_41 , V_67 ) ;
case V_218 :
case V_220 :
case V_51 :
return F_130 ( V_41 , V_67 ) ;
default:
F_122 ( V_41 ) ;
return F_126 ( V_50 , V_67 ) ;
}
}
static T_6 F_131 ( struct V_32 * V_33 ,
enum V_41 V_41 )
{
switch ( V_41 ) {
case V_50 :
case V_218 :
case V_220 :
case V_51 :
return F_124 ( V_41 ) ;
default:
F_122 ( V_41 ) ;
return F_124 ( V_50 ) ;
}
}
static T_6 F_132 ( struct V_32 * V_33 ,
enum V_41 V_41 , int V_67 )
{
switch ( V_41 ) {
case V_50 :
case V_218 :
case V_220 :
case V_51 :
return F_126 ( V_41 , V_67 ) ;
default:
F_122 ( V_41 ) ;
return F_126 ( V_50 , V_67 ) ;
}
}
static T_6 F_133 ( struct V_32 * V_33 ,
enum V_41 V_41 )
{
if ( F_134 ( V_33 ) -> V_222 >= 9 )
return F_131 ( V_33 , V_41 ) ;
else if ( F_135 ( V_33 ) )
return F_127 ( V_33 , V_41 ) ;
else
return F_123 ( V_33 , V_41 ) ;
}
static T_6 F_136 ( struct V_32 * V_33 ,
enum V_41 V_41 , int V_67 )
{
if ( F_134 ( V_33 ) -> V_222 >= 9 )
return F_132 ( V_33 , V_41 , V_67 ) ;
else if ( F_135 ( V_33 ) )
return F_129 ( V_33 , V_41 , V_67 ) ;
else
return F_125 ( V_33 , V_41 , V_67 ) ;
}
static void F_137 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_41 V_41 = F_121 ( V_33 ,
F_2 ( V_1 ) -> V_41 ) ;
int V_14 ;
V_1 -> V_147 = F_133 ( V_33 , V_41 ) ;
for ( V_14 = 0 ; V_14 < F_24 ( V_1 -> V_184 ) ; V_14 ++ )
V_1 -> V_184 [ V_14 ] = F_136 ( V_33 , V_41 , V_14 ) ;
}
static void
F_138 ( struct V_1 * V_1 )
{
F_139 ( V_1 -> V_190 . V_223 ) ;
}
static void
F_140 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
F_137 ( V_1 ) ;
F_141 ( & V_1 -> V_190 ) ;
V_1 -> V_190 . V_223 = F_142 ( V_224 , L_19 , F_51 ( V_41 ) ) ;
V_1 -> V_190 . V_225 = F_119 ;
}
bool F_28 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
if ( ( F_143 ( V_33 ) && ! F_144 ( V_33 ) ) ||
F_108 ( V_33 ) || ( F_145 ( V_33 ) >= 9 ) )
return true ;
else
return false ;
}
static void
F_146 ( struct V_30 * V_31 ,
struct V_226 * V_227 )
{
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
const struct V_228 * V_229 = NULL ;
int V_14 , V_230 = 0 ;
if ( F_147 ( V_33 ) ) {
V_229 = V_231 ;
V_230 = F_24 ( V_231 ) ;
} else if ( F_135 ( V_33 ) ) {
V_229 = V_232 ;
V_230 = F_24 ( V_232 ) ;
} else if ( F_54 ( V_33 ) ) {
V_229 = V_110 ;
V_230 = F_24 ( V_110 ) ;
} else if ( F_81 ( V_33 ) ) {
V_229 = V_112 ;
V_230 = F_24 ( V_112 ) ;
}
if ( V_229 && V_230 ) {
for ( V_14 = 0 ; V_14 < V_230 ; V_14 ++ ) {
if ( V_227 -> V_233 == V_229 [ V_14 ] . clock ) {
V_227 -> V_111 = V_229 [ V_14 ] . V_111 ;
V_227 -> V_234 = true ;
break;
}
}
}
}
static void F_148 ( char * V_235 , T_8 V_60 ,
const int * V_236 , int V_237 )
{
int V_14 ;
V_235 [ 0 ] = '\0' ;
for ( V_14 = 0 ; V_14 < V_237 ; V_14 ++ ) {
int V_238 = snprintf ( V_235 , V_60 , L_20 , V_14 ? L_21 : L_22 , V_236 [ V_14 ] ) ;
if ( V_238 >= V_60 )
return;
V_235 += V_238 ;
V_60 -= V_238 ;
}
}
static void F_149 ( struct V_1 * V_1 )
{
char V_235 [ 128 ] ;
if ( ( V_239 & V_240 ) == 0 )
return;
F_148 ( V_235 , sizeof( V_235 ) ,
V_1 -> V_42 , V_1 -> V_45 ) ;
F_52 ( L_23 , V_235 ) ;
F_148 ( V_235 , sizeof( V_235 ) ,
V_1 -> V_18 , V_1 -> V_20 ) ;
F_52 ( L_24 , V_235 ) ;
F_148 ( V_235 , sizeof( V_235 ) ,
V_1 -> V_21 , V_1 -> V_22 ) ;
F_52 ( L_25 , V_235 ) ;
}
int
F_38 ( struct V_1 * V_1 )
{
int V_60 ;
V_60 = F_32 ( V_1 , V_1 -> V_66 ) ;
if ( F_22 ( V_60 <= 0 ) )
return 162000 ;
return V_1 -> V_21 [ V_60 - 1 ] ;
}
int F_150 ( struct V_1 * V_1 , int V_61 )
{
int V_14 = F_30 ( V_1 -> V_18 ,
V_1 -> V_20 , V_61 ) ;
if ( F_22 ( V_14 < 0 ) )
V_14 = 0 ;
return V_14 ;
}
void F_151 ( struct V_1 * V_1 , int V_233 ,
T_3 * V_241 , T_3 * V_242 )
{
if ( V_1 -> V_243 ) {
* V_241 = 0 ;
* V_242 =
F_150 ( V_1 , V_233 ) ;
} else {
* V_241 = F_152 ( V_233 ) ;
* V_242 = 0 ;
}
}
static int F_153 ( struct V_1 * V_1 ,
struct V_226 * V_227 )
{
int V_28 , V_244 ;
V_28 = V_227 -> V_245 ;
V_244 = F_154 ( V_1 -> V_16 , V_1 -> V_37 ) ;
if ( V_244 > 0 )
V_28 = F_13 ( V_28 , 3 * V_244 ) ;
if ( V_1 -> V_246 . V_247 . V_244 != 0 ) {
V_227 -> V_245 = 3 * V_1 -> V_246 . V_247 . V_244 ;
V_227 -> V_248 = V_227 -> V_245 == 6 * 3 ;
F_52 ( L_26 ,
V_227 -> V_245 ) ;
}
return V_28 ;
}
static bool F_155 ( struct V_69 * V_249 ,
struct V_69 * V_250 )
{
bool V_251 = false ;
if ( V_249 && V_250 )
V_251 = ( V_249 -> V_76 == V_250 -> V_76 &&
V_249 -> V_252 == V_250 -> V_252 &&
V_249 -> V_253 == V_250 -> V_253 &&
V_249 -> V_254 == V_250 -> V_254 &&
V_249 -> V_78 == V_250 -> V_78 &&
V_249 -> V_255 == V_250 -> V_255 &&
V_249 -> V_256 == V_250 -> V_256 &&
V_249 -> V_257 == V_250 -> V_257 ) ;
return V_251 ;
}
bool
F_156 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
struct V_69 * V_260 = & V_227 -> V_4 . V_260 ;
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
struct V_261 * V_261 = F_157 ( V_227 -> V_4 . V_262 ) ;
struct V_71 * V_71 = V_1 -> V_263 ;
struct V_264 * V_265 =
F_158 ( V_259 ) ;
int V_65 , clock ;
int V_266 = 1 ;
int V_267 = F_14 ( V_1 ) ;
int V_268 = 0 ;
int V_269 ;
int V_28 , V_75 ;
int V_270 , V_271 ;
int V_63 ;
T_3 V_241 , V_242 ;
bool V_272 = F_159 ( & V_1 -> V_273 ,
V_274 ) ;
V_63 = F_32 ( V_1 ,
V_1 -> V_66 ) ;
F_22 ( V_63 <= 0 ) ;
V_269 = V_63 - 1 ;
if ( F_135 ( V_33 ) && ! F_160 ( V_33 ) && V_41 != V_50 )
V_227 -> V_275 = true ;
V_227 -> V_276 = false ;
if ( V_41 == V_50 )
V_227 -> V_277 = false ;
else if ( V_265 -> V_278 == V_279 )
V_227 -> V_277 = V_1 -> V_277 ;
else
V_227 -> V_277 = V_265 -> V_278 == V_280 ;
if ( F_1 ( V_1 ) && V_71 -> V_73 . V_72 ) {
struct V_69 * V_281 =
V_71 -> V_73 . V_282 ;
struct V_69 * V_283 = & V_227 -> V_4 . V_70 ;
if ( ! F_155 ( V_283 , V_281 ) )
V_281 = V_71 -> V_73 . V_72 ;
F_161 ( V_281 ) ;
F_162 ( V_281 , V_260 ) ;
if ( F_145 ( V_33 ) >= 9 ) {
int V_172 ;
V_172 = F_163 ( V_227 ) ;
if ( V_172 )
return V_172 ;
}
if ( F_164 ( V_33 ) )
F_165 ( V_261 , V_227 ,
V_259 -> V_284 ) ;
else
F_166 ( V_261 , V_227 ,
V_259 -> V_284 ) ;
}
if ( V_260 -> V_81 & V_82 )
return false ;
if ( V_1 -> V_246 . V_285 == V_286 ) {
int V_67 ;
if ( F_33 ( V_1 , V_1 -> V_246 . V_287 ,
V_1 -> V_246 . V_288 ) ) {
V_67 = F_30 ( V_1 -> V_21 ,
V_1 -> V_22 ,
V_1 -> V_246 . V_287 ) ;
if ( V_67 >= 0 )
V_268 = V_269 = V_67 ;
V_266 = V_267 = V_1 -> V_246 . V_288 ;
}
}
F_52 ( L_27
L_28 ,
V_267 , V_1 -> V_21 [ V_269 ] ,
V_260 -> V_289 ) ;
V_28 = F_153 ( V_1 , V_227 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_71 -> V_4 . V_290 . V_244 == 0 &&
( V_33 -> V_212 . V_291 . V_28 && V_33 -> V_212 . V_291 . V_28 < V_28 ) ) {
F_52 ( L_29 ,
V_33 -> V_212 . V_291 . V_28 ) ;
V_28 = V_33 -> V_212 . V_291 . V_28 ;
}
V_266 = V_267 ;
V_268 = V_269 ;
}
for (; V_28 >= 6 * 3 ; V_28 -= 2 * 3 ) {
V_75 = F_15 ( V_260 -> V_289 ,
V_28 ) ;
for ( clock = V_268 ; clock <= V_269 ; clock ++ ) {
for ( V_65 = V_266 ;
V_65 <= V_267 ;
V_65 <<= 1 ) {
V_271 = V_1 -> V_21 [ clock ] ;
V_270 = F_17 ( V_271 ,
V_65 ) ;
if ( V_75 <= V_270 ) {
goto V_292;
}
}
}
}
return false ;
V_292:
if ( V_265 -> V_293 == V_294 ) {
V_227 -> V_295 =
V_28 != 18 &&
F_167 ( V_260 ) ==
V_296 ;
} else {
V_227 -> V_295 =
V_265 -> V_293 == V_297 ;
}
V_227 -> V_65 = V_65 ;
V_227 -> V_245 = V_28 ;
V_227 -> V_233 = V_1 -> V_21 [ clock ] ;
F_151 ( V_1 , V_227 -> V_233 ,
& V_241 , & V_242 ) ;
F_52 ( L_30 ,
V_241 , V_242 , V_227 -> V_65 ,
V_227 -> V_233 , V_28 ) ;
F_52 ( L_31 ,
V_75 , V_270 ) ;
F_168 ( V_28 , V_65 ,
V_260 -> V_289 ,
V_227 -> V_233 ,
& V_227 -> V_298 ,
V_272 ) ;
if ( V_71 -> V_73 . V_299 != NULL &&
V_33 -> V_300 . type == V_301 ) {
V_227 -> V_276 = true ;
F_168 ( V_28 , V_65 ,
V_71 -> V_73 . V_299 -> clock ,
V_227 -> V_233 ,
& V_227 -> V_302 ,
V_272 ) ;
}
if ( F_1 ( V_1 ) && F_27 ( V_33 ) ) {
int V_303 ;
switch ( V_227 -> V_233 / 2 ) {
case 108000 :
case 216000 :
V_303 = 8640000 ;
break;
default:
V_303 = 8100000 ;
break;
}
F_169 ( V_227 -> V_4 . V_304 ) -> V_152 . V_305 . V_303 = V_303 ;
}
if ( ! F_160 ( V_33 ) )
F_146 ( V_31 , V_227 ) ;
return true ;
}
void F_170 ( struct V_1 * V_1 ,
int V_64 , T_3 V_65 ,
bool V_306 )
{
V_1 -> V_64 = V_64 ;
V_1 -> V_65 = V_65 ;
V_1 -> V_306 = V_306 ;
}
static void F_171 ( struct V_30 * V_31 ,
struct V_226 * V_227 )
{
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
struct V_261 * V_262 = F_157 ( V_31 -> V_4 . V_262 ) ;
const struct V_69 * V_260 = & V_227 -> V_4 . V_260 ;
F_170 ( V_1 , V_227 -> V_233 ,
V_227 -> V_65 ,
F_172 ( V_227 ,
V_307 ) ) ;
V_1 -> V_100 = F_26 ( V_1 -> V_101 ) & V_103 ;
V_1 -> V_100 |= V_104 | V_105 ;
V_1 -> V_100 |= F_53 ( V_227 -> V_65 ) ;
if ( F_173 ( V_33 ) && V_41 == V_50 ) {
if ( V_260 -> V_81 & V_308 )
V_1 -> V_100 |= V_309 ;
if ( V_260 -> V_81 & V_310 )
V_1 -> V_100 |= V_311 ;
V_1 -> V_100 |= V_312 ;
if ( F_174 ( V_1 -> V_16 ) )
V_1 -> V_100 |= V_313 ;
V_1 -> V_100 |= V_262 -> V_92 << 29 ;
} else if ( F_175 ( V_33 ) && V_41 != V_50 ) {
T_2 V_314 ;
V_1 -> V_100 |= V_312 ;
V_314 = F_26 ( F_176 ( V_262 -> V_92 ) ) ;
if ( F_174 ( V_1 -> V_16 ) )
V_314 |= V_315 ;
else
V_314 &= ~ V_315 ;
F_59 ( F_176 ( V_262 -> V_92 ) , V_314 ) ;
} else {
if ( F_147 ( V_33 ) && V_227 -> V_295 )
V_1 -> V_100 |= V_316 ;
if ( V_260 -> V_81 & V_308 )
V_1 -> V_100 |= V_309 ;
if ( V_260 -> V_81 & V_310 )
V_1 -> V_100 |= V_311 ;
V_1 -> V_100 |= V_317 ;
if ( F_174 ( V_1 -> V_16 ) )
V_1 -> V_100 |= V_313 ;
if ( F_54 ( V_33 ) )
V_1 -> V_100 |= F_55 ( V_262 -> V_92 ) ;
else if ( V_262 -> V_92 == V_107 )
V_1 -> V_100 |= V_108 ;
}
}
static void F_177 ( struct V_1 * V_1 ,
T_2 V_318 ,
T_2 V_319 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_6 V_320 , V_139 ;
F_66 ( & V_33 -> V_91 ) ;
F_178 ( V_33 , V_1 ) ;
V_320 = F_87 ( V_1 ) ;
V_139 = F_86 ( V_1 ) ;
F_52 ( L_32 ,
V_318 , V_319 ,
F_26 ( V_320 ) ,
F_26 ( V_139 ) ) ;
if ( F_179 ( V_33 ,
V_320 , V_318 , V_319 ,
5000 ) )
F_35 ( L_33 ,
F_26 ( V_320 ) ,
F_26 ( V_139 ) ) ;
F_52 ( L_34 ) ;
}
static void F_180 ( struct V_1 * V_1 )
{
F_52 ( L_35 ) ;
F_177 ( V_1 , V_321 , V_322 ) ;
}
static void F_181 ( struct V_1 * V_1 )
{
F_52 ( L_36 ) ;
F_177 ( V_1 , V_323 , V_324 ) ;
}
static void F_182 ( struct V_1 * V_1 )
{
T_9 V_325 ;
T_10 V_326 ;
F_52 ( L_37 ) ;
V_325 = F_183 () ;
V_326 = F_184 ( V_325 , V_1 -> V_327 ) ;
if ( V_326 < ( T_10 ) V_1 -> V_144 )
F_185 ( V_328 ,
V_1 -> V_144 - V_326 ) ;
F_177 ( V_1 , V_329 , V_330 ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
F_185 ( V_1 -> V_331 ,
V_1 -> V_332 ) ;
}
static void F_187 ( struct V_1 * V_1 )
{
F_185 ( V_1 -> V_333 ,
V_1 -> V_334 ) ;
}
static T_2 F_188 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_335 ;
F_66 ( & V_33 -> V_91 ) ;
V_335 = F_26 ( F_86 ( V_1 ) ) ;
if ( F_22 ( ! F_160 ( V_33 ) &&
( V_335 & V_336 ) != V_142 ) ) {
V_335 &= ~ V_336 ;
V_335 |= V_142 ;
}
return V_335 ;
}
static bool F_114 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_337 ;
T_6 V_320 , V_139 ;
bool V_338 = ! V_1 -> V_339 ;
F_66 ( & V_33 -> V_91 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_189 ( & V_1 -> V_340 ) ;
V_1 -> V_339 = true ;
if ( F_93 ( V_1 ) )
return V_338 ;
F_42 ( V_33 , V_1 -> V_90 ) ;
F_52 ( L_38 ,
F_51 ( V_3 -> V_41 ) ) ;
if ( ! F_92 ( V_1 ) )
F_182 ( V_1 ) ;
V_337 = F_188 ( V_1 ) ;
V_337 |= V_120 ;
V_320 = F_87 ( V_1 ) ;
V_139 = F_86 ( V_1 ) ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_52 ( L_39 ,
F_26 ( V_320 ) , F_26 ( V_139 ) ) ;
if ( ! F_92 ( V_1 ) ) {
F_52 ( L_40 ,
F_51 ( V_3 -> V_41 ) ) ;
F_91 ( V_1 -> V_341 ) ;
}
return V_338 ;
}
void F_190 ( struct V_1 * V_1 )
{
bool V_175 ;
if ( ! F_1 ( V_1 ) )
return;
F_41 ( V_1 ) ;
V_175 = F_114 ( V_1 ) ;
F_44 ( V_1 ) ;
F_191 ( ! V_175 , L_41 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
T_2 V_337 ;
T_6 V_320 , V_139 ;
F_66 ( & V_33 -> V_91 ) ;
F_22 ( V_1 -> V_339 ) ;
if ( ! F_93 ( V_1 ) )
return;
F_52 ( L_42 ,
F_51 ( V_3 -> V_41 ) ) ;
V_337 = F_188 ( V_1 ) ;
V_337 &= ~ V_120 ;
V_139 = F_86 ( V_1 ) ;
V_320 = F_87 ( V_1 ) ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_52 ( L_39 ,
F_26 ( V_320 ) , F_26 ( V_139 ) ) ;
if ( ( V_337 & V_342 ) == 0 )
V_1 -> V_327 = F_183 () ;
F_46 ( V_33 , V_1 -> V_90 ) ;
}
static void F_193 ( struct V_343 * V_344 )
{
struct V_1 * V_1 = F_89 ( F_194 ( V_344 ) ,
struct V_1 , V_340 ) ;
F_41 ( V_1 ) ;
if ( ! V_1 -> V_339 )
F_192 ( V_1 ) ;
F_44 ( V_1 ) ;
}
static void F_195 ( struct V_1 * V_1 )
{
unsigned long V_345 ;
V_345 = F_196 ( V_1 -> V_144 * 5 ) ;
F_197 ( & V_1 -> V_340 , V_345 ) ;
}
static void F_118 ( struct V_1 * V_1 , bool V_346 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
F_66 ( & V_33 -> V_91 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_191 ( ! V_1 -> V_339 , L_43 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) ;
V_1 -> V_339 = false ;
if ( V_346 )
F_192 ( V_1 ) ;
else
F_195 ( V_1 ) ;
}
static void F_198 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_337 ;
T_6 V_139 ;
F_66 ( & V_33 -> V_91 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_52 ( L_44 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) ;
if ( F_8 ( F_92 ( V_1 ) ,
L_45 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) )
return;
F_182 ( V_1 ) ;
V_139 = F_86 ( V_1 ) ;
V_337 = F_188 ( V_1 ) ;
if ( F_199 ( V_33 ) ) {
V_337 &= ~ V_347 ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
}
V_337 |= V_342 ;
if ( ! F_199 ( V_33 ) )
V_337 |= V_347 ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_180 ( V_1 ) ;
V_1 -> V_331 = V_328 ;
if ( F_199 ( V_33 ) ) {
V_337 |= V_347 ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
}
}
void F_200 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_41 ( V_1 ) ;
F_198 ( V_1 ) ;
F_44 ( V_1 ) ;
}
static void F_201 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_337 ;
T_6 V_139 ;
F_66 ( & V_33 -> V_91 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_52 ( L_46 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) ;
F_8 ( ! V_1 -> V_339 , L_47 ,
F_51 ( F_2 ( V_1 ) -> V_41 ) ) ;
V_337 = F_188 ( V_1 ) ;
V_337 &= ~ ( V_342 | V_347 | V_120 |
V_348 ) ;
V_139 = F_86 ( V_1 ) ;
V_1 -> V_339 = false ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_181 ( V_1 ) ;
V_1 -> V_327 = F_183 () ;
F_46 ( V_33 , V_1 -> V_90 ) ;
}
void F_202 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_41 ( V_1 ) ;
F_201 ( V_1 ) ;
F_44 ( V_1 ) ;
}
static void F_203 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_337 ;
T_6 V_139 ;
F_186 ( V_1 ) ;
F_41 ( V_1 ) ;
V_337 = F_188 ( V_1 ) ;
V_337 |= V_348 ;
V_139 = F_86 ( V_1 ) ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_44 ( V_1 ) ;
}
void F_204 ( const struct V_226 * V_349 ,
const struct V_258 * V_259 )
{
struct V_1 * V_1 = F_5 ( V_259 -> V_350 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_52 ( L_48 ) ;
F_205 ( V_349 , V_259 ) ;
F_203 ( V_1 ) ;
}
static void F_206 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_337 ;
T_6 V_139 ;
if ( ! F_1 ( V_1 ) )
return;
F_41 ( V_1 ) ;
V_337 = F_188 ( V_1 ) ;
V_337 &= ~ V_348 ;
V_139 = F_86 ( V_1 ) ;
F_59 ( V_139 , V_337 ) ;
F_60 ( V_139 ) ;
F_44 ( V_1 ) ;
V_1 -> V_333 = V_328 ;
F_187 ( V_1 ) ;
}
void F_207 ( const struct V_258 * V_351 )
{
struct V_1 * V_1 = F_5 ( V_351 -> V_350 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_52 ( L_48 ) ;
F_206 ( V_1 ) ;
F_208 ( V_351 ) ;
}
static void F_209 ( struct V_71 * V_9 ,
bool V_352 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_353 ;
F_41 ( V_1 ) ;
V_353 = F_188 ( V_1 ) & V_348 ;
F_44 ( V_1 ) ;
if ( V_353 == V_352 )
return;
F_52 ( L_49 ,
V_352 ? L_50 : L_51 ) ;
if ( V_352 )
F_203 ( V_1 ) ;
else
F_206 ( V_1 ) ;
}
static void F_210 ( struct V_1 * V_1 , bool V_304 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
bool V_354 = F_26 ( V_1 -> V_101 ) & V_102 ;
F_191 ( V_354 != V_304 ,
L_52 ,
F_51 ( V_40 -> V_41 ) ,
F_211 ( V_304 ) , F_211 ( V_354 ) ) ;
}
static void F_212 ( struct V_32 * V_33 , bool V_304 )
{
bool V_354 = F_26 ( V_355 ) & V_356 ;
F_191 ( V_354 != V_304 ,
L_53 ,
F_211 ( V_304 ) , F_211 ( V_354 ) ) ;
}
static void F_213 ( struct V_1 * V_1 ,
struct V_226 * V_227 )
{
struct V_261 * V_262 = F_157 ( V_227 -> V_4 . V_262 ) ;
struct V_32 * V_33 = F_19 ( V_262 -> V_4 . V_7 ) ;
F_214 ( V_33 , V_262 -> V_92 ) ;
F_215 ( V_1 ) ;
F_216 ( V_33 ) ;
F_52 ( L_54 ,
V_227 -> V_233 ) ;
V_1 -> V_100 &= ~ V_357 ;
if ( V_227 -> V_233 == 162000 )
V_1 -> V_100 |= V_358 ;
else
V_1 -> V_100 |= V_359 ;
F_59 ( V_355 , V_1 -> V_100 ) ;
F_60 ( V_355 ) ;
F_217 ( 500 ) ;
if ( F_199 ( V_33 ) )
F_218 ( V_33 , ! V_262 -> V_92 ) ;
V_1 -> V_100 |= V_356 ;
F_59 ( V_355 , V_1 -> V_100 ) ;
F_60 ( V_355 ) ;
F_217 ( 200 ) ;
}
static void F_219 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_261 * V_262 = F_157 ( V_3 -> V_4 . V_4 . V_262 ) ;
struct V_32 * V_33 = F_19 ( V_262 -> V_4 . V_7 ) ;
F_214 ( V_33 , V_262 -> V_92 ) ;
F_215 ( V_1 ) ;
F_220 ( V_33 ) ;
F_52 ( L_55 ) ;
V_1 -> V_100 &= ~ V_356 ;
F_59 ( V_355 , V_1 -> V_100 ) ;
F_60 ( V_355 ) ;
F_217 ( 200 ) ;
}
void F_221 ( struct V_1 * V_1 , int V_70 )
{
int V_172 , V_14 ;
if ( V_1 -> V_16 [ V_360 ] < 0x11 )
return;
if ( V_70 != V_361 ) {
V_172 = F_222 ( & V_1 -> V_190 , V_362 ,
V_363 ) ;
} else {
struct V_364 * V_365 = F_223 ( V_1 ) ;
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
V_172 = F_222 ( & V_1 -> V_190 , V_362 ,
V_366 ) ;
if ( V_172 == 1 )
break;
F_91 ( 1 ) ;
}
if ( V_172 == 1 && V_365 -> V_367 )
F_224 ( V_365 ) ;
}
if ( V_172 != 1 )
F_52 ( L_56 ,
V_70 == V_361 ? L_50 : L_51 ) ;
}
static bool F_225 ( struct V_30 * V_31 ,
enum V_92 * V_92 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_368 ;
bool V_172 ;
if ( ! F_226 ( V_33 ,
V_31 -> V_369 ) )
return false ;
V_172 = false ;
V_368 = F_26 ( V_1 -> V_101 ) ;
if ( ! ( V_368 & V_102 ) )
goto V_179;
if ( F_173 ( V_33 ) && V_41 == V_50 ) {
* V_92 = F_227 ( V_368 ) ;
} else if ( F_175 ( V_33 ) && V_41 != V_50 ) {
enum V_92 V_370 ;
F_228 (dev_priv, p) {
T_2 V_314 = F_26 ( F_176 ( V_370 ) ) ;
if ( F_229 ( V_314 ) == V_41 ) {
* V_92 = V_370 ;
V_172 = true ;
goto V_179;
}
}
F_52 ( L_57 ,
F_230 ( V_1 -> V_101 ) ) ;
} else if ( F_54 ( V_33 ) ) {
* V_92 = F_231 ( V_368 ) ;
} else {
* V_92 = F_232 ( V_368 ) ;
}
V_172 = true ;
V_179:
F_46 ( V_33 , V_31 -> V_369 ) ;
return V_172 ;
}
static void F_233 ( struct V_30 * V_31 ,
struct V_226 * V_227 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
T_2 V_368 , V_81 = 0 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
struct V_261 * V_262 = F_157 ( V_31 -> V_4 . V_262 ) ;
V_368 = F_26 ( V_1 -> V_101 ) ;
V_227 -> V_277 = V_368 & V_371 && V_41 != V_50 ;
if ( F_175 ( V_33 ) && V_41 != V_50 ) {
T_2 V_314 = F_26 ( F_176 ( V_262 -> V_92 ) ) ;
if ( V_314 & V_372 )
V_81 |= V_308 ;
else
V_81 |= V_373 ;
if ( V_314 & V_374 )
V_81 |= V_310 ;
else
V_81 |= V_375 ;
} else {
if ( V_368 & V_309 )
V_81 |= V_308 ;
else
V_81 |= V_373 ;
if ( V_368 & V_311 )
V_81 |= V_310 ;
else
V_81 |= V_375 ;
}
V_227 -> V_4 . V_260 . V_81 |= V_81 ;
if ( F_147 ( V_33 ) && V_368 & V_316 )
V_227 -> V_295 = true ;
V_227 -> V_65 =
( ( V_368 & V_376 ) >> V_377 ) + 1 ;
F_234 ( V_262 , V_227 ) ;
if ( V_41 == V_50 ) {
if ( ( F_26 ( V_355 ) & V_357 ) == V_358 )
V_227 -> V_233 = 162000 ;
else
V_227 -> V_233 = 270000 ;
}
V_227 -> V_4 . V_260 . V_289 =
F_235 ( V_227 -> V_233 ,
& V_227 -> V_298 ) ;
if ( F_1 ( V_1 ) && V_33 -> V_212 . V_291 . V_28 &&
V_227 -> V_245 > V_33 -> V_212 . V_291 . V_28 ) {
F_52 ( L_58 ,
V_227 -> V_245 , V_33 -> V_212 . V_291 . V_28 ) ;
V_33 -> V_212 . V_291 . V_28 = V_227 -> V_245 ;
}
}
static void F_236 ( struct V_30 * V_31 ,
struct V_226 * V_378 ,
struct V_258 * V_351 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
if ( V_378 -> V_277 )
F_237 ( V_31 ) ;
if ( F_238 ( V_33 ) && ! F_160 ( V_33 ) )
F_239 ( V_1 ) ;
F_190 ( V_1 ) ;
F_207 ( V_351 ) ;
F_221 ( V_1 , V_379 ) ;
F_202 ( V_1 ) ;
if ( F_145 ( V_33 ) < 5 )
F_240 ( V_1 ) ;
}
static void F_241 ( struct V_30 * V_31 ,
struct V_226 * V_378 ,
struct V_258 * V_351 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
F_240 ( V_1 ) ;
if ( V_41 == V_50 )
F_219 ( V_1 ) ;
}
static void F_242 ( struct V_30 * V_31 ,
struct V_226 * V_378 ,
struct V_258 * V_351 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
F_240 ( V_1 ) ;
}
static void F_243 ( struct V_30 * V_31 ,
struct V_226 * V_378 ,
struct V_258 * V_351 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_240 ( V_1 ) ;
F_43 ( & V_33 -> V_380 ) ;
F_244 ( V_31 , true ) ;
F_45 ( & V_33 -> V_380 ) ;
}
static void
F_245 ( struct V_1 * V_1 ,
T_4 * V_100 ,
T_3 V_381 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
if ( V_381 & V_382 )
F_52 ( L_59 ,
V_381 & V_382 ) ;
if ( F_160 ( V_33 ) ) {
T_4 V_383 = F_26 ( F_246 ( V_41 ) ) ;
if ( V_381 & V_384 )
V_383 |= V_385 ;
else
V_383 &= ~ V_385 ;
V_383 &= ~ V_386 ;
switch ( V_381 & V_382 ) {
case V_387 :
V_383 |= V_388 ;
break;
case V_389 :
V_383 |= V_390 ;
break;
case V_391 :
V_383 |= V_392 ;
break;
case V_393 :
V_383 |= V_394 ;
break;
}
F_59 ( F_246 ( V_41 ) , V_383 ) ;
} else if ( ( F_173 ( V_33 ) && V_41 == V_50 ) ||
( F_175 ( V_33 ) && V_41 != V_50 ) ) {
* V_100 &= ~ V_395 ;
switch ( V_381 & V_382 ) {
case V_387 :
* V_100 |= V_312 ;
break;
case V_389 :
* V_100 |= V_396 ;
break;
case V_391 :
* V_100 |= V_397 ;
break;
case V_393 :
F_52 ( L_60 ) ;
* V_100 |= V_397 ;
break;
}
} else {
if ( F_54 ( V_33 ) )
* V_100 &= ~ V_398 ;
else
* V_100 &= ~ V_399 ;
switch ( V_381 & V_382 ) {
case V_387 :
* V_100 |= V_317 ;
break;
case V_389 :
* V_100 |= V_106 ;
break;
case V_391 :
* V_100 |= V_400 ;
break;
case V_393 :
if ( F_54 ( V_33 ) ) {
* V_100 |= V_401 ;
} else {
F_52 ( L_60 ) ;
* V_100 |= V_400 ;
}
break;
}
}
}
static void F_247 ( struct V_1 * V_1 ,
struct V_226 * V_378 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_248 ( V_1 , V_389 ) ;
V_1 -> V_100 |= V_102 ;
if ( V_378 -> V_277 )
V_1 -> V_100 |= V_371 ;
F_59 ( V_1 -> V_101 , V_1 -> V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
}
static void F_249 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_261 * V_262 = F_157 ( V_31 -> V_4 . V_262 ) ;
T_4 V_402 = F_26 ( V_1 -> V_101 ) ;
enum V_92 V_92 = V_262 -> V_92 ;
if ( F_22 ( V_402 & V_102 ) )
return;
F_41 ( V_1 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
F_250 ( V_1 ) ;
F_247 ( V_1 , V_227 ) ;
F_114 ( V_1 ) ;
F_198 ( V_1 ) ;
F_118 ( V_1 , true ) ;
F_44 ( V_1 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
unsigned int V_403 = 0x0 ;
if ( F_54 ( V_33 ) )
V_403 = F_251 ( V_227 -> V_65 ) ;
F_252 ( V_33 , F_2 ( V_1 ) ,
V_403 ) ;
}
F_221 ( V_1 , V_361 ) ;
F_253 ( V_1 ) ;
F_254 ( V_1 ) ;
if ( V_227 -> V_277 ) {
F_255 ( L_61 ,
F_50 ( V_92 ) ) ;
F_256 ( V_31 , V_227 , V_259 ) ;
}
}
static void F_257 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_249 ( V_31 , V_227 , V_259 ) ;
F_204 ( V_227 , V_259 ) ;
}
static void F_258 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
F_204 ( V_227 , V_259 ) ;
F_259 ( V_1 ) ;
}
static void F_260 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
F_171 ( V_31 , V_227 ) ;
if ( V_41 == V_50 )
F_213 ( V_1 , V_227 ) ;
}
static void F_261 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_92 V_92 = V_1 -> V_93 ;
T_6 V_404 = F_77 ( V_92 ) ;
F_22 ( V_1 -> V_116 != V_117 ) ;
if ( F_22 ( V_92 != V_114 && V_92 != V_107 ) )
return;
F_192 ( V_1 ) ;
F_52 ( L_62 ,
F_50 ( V_92 ) , F_51 ( V_3 -> V_41 ) ) ;
F_59 ( V_404 , 0 ) ;
F_60 ( V_404 ) ;
V_1 -> V_93 = V_117 ;
}
static void F_67 ( struct V_6 * V_7 ,
enum V_92 V_92 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_30 * V_31 ;
F_66 ( & V_33 -> V_91 ) ;
F_63 (dev, encoder) {
struct V_1 * V_1 ;
enum V_41 V_41 ;
if ( V_31 -> type != V_115 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
V_41 = F_2 ( V_1 ) -> V_41 ;
F_8 ( V_1 -> V_116 == V_92 ,
L_63 ,
F_50 ( V_92 ) , F_51 ( V_41 ) ) ;
if ( V_1 -> V_93 != V_92 )
continue;
F_52 ( L_64 ,
F_50 ( V_92 ) , F_51 ( V_41 ) ) ;
F_261 ( V_1 ) ;
}
}
static void F_250 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_261 * V_262 = F_157 ( V_31 -> V_4 . V_262 ) ;
F_66 ( & V_33 -> V_91 ) ;
F_22 ( V_1 -> V_116 != V_117 ) ;
if ( V_1 -> V_93 != V_117 &&
V_1 -> V_93 != V_262 -> V_92 ) {
F_261 ( V_1 ) ;
}
F_67 ( V_7 , V_262 -> V_92 ) ;
V_1 -> V_116 = V_262 -> V_92 ;
if ( ! F_1 ( V_1 ) )
return;
V_1 -> V_93 = V_262 -> V_92 ;
F_52 ( L_65 ,
F_50 ( V_1 -> V_93 ) , F_51 ( V_3 -> V_41 ) ) ;
F_68 ( V_7 , V_1 ) ;
F_69 ( V_7 , V_1 , true ) ;
}
static void F_262 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_263 ( V_31 ) ;
F_249 ( V_31 , V_227 , V_259 ) ;
}
static void F_264 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_171 ( V_31 , V_227 ) ;
F_265 ( V_31 ) ;
}
static void F_266 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_267 ( V_31 ) ;
F_249 ( V_31 , V_227 , V_259 ) ;
F_268 ( V_31 ) ;
}
static void F_269 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_171 ( V_31 , V_227 ) ;
F_270 ( V_31 ) ;
}
static void F_271 ( struct V_30 * V_31 ,
struct V_226 * V_227 ,
struct V_258 * V_259 )
{
F_272 ( V_31 ) ;
}
bool
F_273 ( struct V_1 * V_1 , T_3 V_405 [ V_406 ] )
{
return F_274 ( & V_1 -> V_190 , V_407 , V_405 ,
V_406 ) == V_406 ;
}
static bool F_275 ( struct V_1 * V_1 )
{
T_3 V_408 = 0 ;
if ( F_276 ( & V_1 -> V_190 , V_409 , & V_408 ) != 1 )
return false ;
return V_408 & V_410 ;
}
static bool F_277 ( struct V_1 * V_1 )
{
T_3 V_411 = 0 ;
if ( F_276 ( & V_1 -> V_190 , V_412 ,
& V_411 ) != 1 )
return false ;
return V_411 & V_413 ;
}
static bool F_278 ( struct V_1 * V_1 )
{
T_3 V_414 = 0 ;
if ( F_276 ( & V_1 -> V_190 , V_415 ,
& V_414 ) != 1 )
return false ;
return V_414 & V_416 ;
}
T_3
F_279 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
if ( F_23 ( V_33 ) )
return V_417 ;
else if ( F_145 ( V_33 ) >= 9 ) {
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
return F_280 ( V_31 ) ;
} else if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
return V_417 ;
else if ( F_173 ( V_33 ) && V_41 == V_50 )
return V_418 ;
else if ( F_175 ( V_33 ) && V_41 != V_50 )
return V_417 ;
else
return V_418 ;
}
T_3
F_281 ( struct V_1 * V_1 , T_3 V_419 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
if ( F_145 ( V_33 ) >= 9 ) {
switch ( V_419 & V_420 ) {
case V_421 :
return V_422 ;
case V_423 :
return V_424 ;
case V_418 :
return V_425 ;
case V_417 :
return V_426 ;
default:
return V_426 ;
}
} else if ( F_143 ( V_33 ) || F_108 ( V_33 ) ) {
switch ( V_419 & V_420 ) {
case V_421 :
return V_422 ;
case V_423 :
return V_424 ;
case V_418 :
return V_425 ;
case V_417 :
default:
return V_426 ;
}
} else if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
switch ( V_419 & V_420 ) {
case V_421 :
return V_422 ;
case V_423 :
return V_424 ;
case V_418 :
return V_425 ;
case V_417 :
default:
return V_426 ;
}
} else if ( F_173 ( V_33 ) && V_41 == V_50 ) {
switch ( V_419 & V_420 ) {
case V_421 :
return V_424 ;
case V_423 :
case V_418 :
return V_425 ;
default:
return V_426 ;
}
} else {
switch ( V_419 & V_420 ) {
case V_421 :
return V_424 ;
case V_423 :
return V_424 ;
case V_418 :
return V_425 ;
case V_417 :
default:
return V_426 ;
}
}
}
static T_4 F_282 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_427 , V_428 ,
V_429 ;
T_3 V_430 = V_1 -> V_430 [ 0 ] ;
switch ( V_430 & V_431 ) {
case V_426 :
V_428 = 0x0004000 ;
switch ( V_430 & V_420 ) {
case V_421 :
V_427 = 0x2B405555 ;
V_429 = 0x552AB83A ;
break;
case V_423 :
V_427 = 0x2B404040 ;
V_429 = 0x5548B83A ;
break;
case V_418 :
V_427 = 0x2B245555 ;
V_429 = 0x5560B83A ;
break;
case V_417 :
V_427 = 0x2B405555 ;
V_429 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_425 :
V_428 = 0x0002000 ;
switch ( V_430 & V_420 ) {
case V_421 :
V_427 = 0x2B404040 ;
V_429 = 0x5552B83A ;
break;
case V_423 :
V_427 = 0x2B404848 ;
V_429 = 0x5580B83A ;
break;
case V_418 :
V_427 = 0x2B404040 ;
V_429 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_424 :
V_428 = 0x0000000 ;
switch ( V_430 & V_420 ) {
case V_421 :
V_427 = 0x2B305555 ;
V_429 = 0x5570B83A ;
break;
case V_423 :
V_427 = 0x2B2B4040 ;
V_429 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_422 :
V_428 = 0x0006000 ;
switch ( V_430 & V_420 ) {
case V_421 :
V_427 = 0x1B405555 ;
V_429 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_283 ( V_31 , V_427 , V_428 ,
V_429 , 0 ) ;
return 0 ;
}
static T_4 F_284 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
T_2 V_432 , V_433 ;
bool V_434 = false ;
T_3 V_430 = V_1 -> V_430 [ 0 ] ;
switch ( V_430 & V_431 ) {
case V_426 :
switch ( V_430 & V_420 ) {
case V_421 :
V_432 = 128 ;
V_433 = 52 ;
break;
case V_423 :
V_432 = 128 ;
V_433 = 77 ;
break;
case V_418 :
V_432 = 128 ;
V_433 = 102 ;
break;
case V_417 :
V_432 = 128 ;
V_433 = 154 ;
V_434 = true ;
break;
default:
return 0 ;
}
break;
case V_425 :
switch ( V_430 & V_420 ) {
case V_421 :
V_432 = 85 ;
V_433 = 78 ;
break;
case V_423 :
V_432 = 85 ;
V_433 = 116 ;
break;
case V_418 :
V_432 = 85 ;
V_433 = 154 ;
break;
default:
return 0 ;
}
break;
case V_424 :
switch ( V_430 & V_420 ) {
case V_421 :
V_432 = 64 ;
V_433 = 104 ;
break;
case V_423 :
V_432 = 64 ;
V_433 = 154 ;
break;
default:
return 0 ;
}
break;
case V_422 :
switch ( V_430 & V_420 ) {
case V_421 :
V_432 = 43 ;
V_433 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_285 ( V_31 , V_432 ,
V_433 , V_434 ) ;
return 0 ;
}
static T_4
F_286 ( T_3 V_430 )
{
T_4 V_435 = 0 ;
switch ( V_430 & V_420 ) {
case V_421 :
default:
V_435 |= V_104 ;
break;
case V_423 :
V_435 |= V_436 ;
break;
case V_418 :
V_435 |= V_437 ;
break;
case V_417 :
V_435 |= V_438 ;
break;
}
switch ( V_430 & V_431 ) {
case V_426 :
default:
V_435 |= V_105 ;
break;
case V_425 :
V_435 |= V_439 ;
break;
case V_424 :
V_435 |= V_440 ;
break;
case V_422 :
V_435 |= V_441 ;
break;
}
return V_435 ;
}
static T_4
F_287 ( T_3 V_430 )
{
int V_435 = V_430 & ( V_420 |
V_431 ) ;
switch ( V_435 ) {
case V_421 | V_426 :
case V_423 | V_426 :
return V_442 ;
case V_421 | V_425 :
return V_443 ;
case V_421 | V_424 :
case V_423 | V_424 :
return V_444 ;
case V_423 | V_425 :
case V_418 | V_425 :
return V_445 ;
case V_418 | V_426 :
case V_417 | V_426 :
return V_446 ;
default:
F_52 ( L_66
L_67 , V_435 ) ;
return V_442 ;
}
}
static T_4
F_288 ( T_3 V_430 )
{
int V_435 = V_430 & ( V_420 |
V_431 ) ;
switch ( V_435 ) {
case V_421 | V_426 :
return V_447 ;
case V_421 | V_425 :
return V_448 ;
case V_421 | V_424 :
return V_449 ;
case V_423 | V_426 :
return V_450 ;
case V_423 | V_425 :
return V_451 ;
case V_418 | V_426 :
return V_452 ;
case V_418 | V_425 :
return V_453 ;
default:
F_52 ( L_66
L_67 , V_435 ) ;
return V_454 ;
}
}
void
F_289 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_4 V_435 , V_318 = 0 ;
T_3 V_430 = V_1 -> V_430 [ 0 ] ;
if ( F_160 ( V_33 ) ) {
V_435 = F_290 ( V_1 ) ;
if ( F_23 ( V_33 ) || F_25 ( V_33 ) )
V_435 = 0 ;
else
V_318 = V_455 ;
} else if ( F_54 ( V_33 ) ) {
V_435 = F_284 ( V_1 ) ;
} else if ( F_81 ( V_33 ) ) {
V_435 = F_282 ( V_1 ) ;
} else if ( F_173 ( V_33 ) && V_41 == V_50 ) {
V_435 = F_288 ( V_430 ) ;
V_318 = V_456 ;
} else if ( F_107 ( V_33 ) && V_41 == V_50 ) {
V_435 = F_287 ( V_430 ) ;
V_318 = V_457 ;
} else {
V_435 = F_286 ( V_430 ) ;
V_318 = V_458 | V_459 ;
}
if ( V_318 )
F_52 ( L_68 , V_435 ) ;
F_52 ( L_69 ,
V_430 & V_420 ) ;
F_52 ( L_70 ,
( V_430 & V_431 ) >>
V_460 ) ;
V_1 -> V_100 = ( V_1 -> V_100 & ~ V_318 ) | V_435 ;
F_59 ( V_1 -> V_101 , V_1 -> V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
}
void
F_248 ( struct V_1 * V_1 ,
T_3 V_381 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_245 ( V_1 , & V_1 -> V_100 , V_381 ) ;
F_59 ( V_1 -> V_101 , V_1 -> V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
}
void F_291 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
T_4 V_461 ;
if ( ! F_160 ( V_33 ) )
return;
V_461 = F_26 ( F_246 ( V_41 ) ) ;
V_461 &= ~ V_386 ;
V_461 |= V_462 ;
F_59 ( F_246 ( V_41 ) , V_461 ) ;
if ( V_41 == V_50 )
return;
if ( F_179 ( V_33 , F_292 ( V_41 ) ,
V_463 ,
V_463 ,
1 ) )
F_35 ( L_71 ) ;
}
static void
F_240 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_261 * V_262 = F_157 ( V_3 -> V_4 . V_4 . V_262 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_4 V_100 = V_1 -> V_100 ;
if ( F_22 ( F_160 ( V_33 ) ) )
return;
if ( F_22 ( ( F_26 ( V_1 -> V_101 ) & V_102 ) == 0 ) )
return;
F_52 ( L_48 ) ;
if ( ( F_173 ( V_33 ) && V_41 == V_50 ) ||
( F_175 ( V_33 ) && V_41 != V_50 ) ) {
V_100 &= ~ V_395 ;
V_100 |= V_464 ;
} else {
if ( F_54 ( V_33 ) )
V_100 &= ~ V_398 ;
else
V_100 &= ~ V_399 ;
V_100 |= V_465 ;
}
F_59 ( V_1 -> V_101 , V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
V_100 &= ~ ( V_102 | V_371 ) ;
F_59 ( V_1 -> V_101 , V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
if ( F_293 ( V_33 ) && V_262 -> V_92 == V_107 && V_41 != V_50 ) {
F_294 ( V_33 , V_114 , false ) ;
F_295 ( V_33 , V_114 , false ) ;
V_100 &= ~ ( V_108 | V_399 ) ;
V_100 |= V_102 | V_106 ;
F_59 ( V_1 -> V_101 , V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
V_100 &= ~ V_102 ;
F_59 ( V_1 -> V_101 , V_100 ) ;
F_60 ( V_1 -> V_101 ) ;
F_218 ( V_33 , V_114 ) ;
F_294 ( V_33 , V_114 , true ) ;
F_295 ( V_33 , V_114 , true ) ;
}
F_91 ( V_1 -> V_466 ) ;
V_1 -> V_100 = V_100 ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
F_41 ( V_1 ) ;
V_1 -> V_116 = V_117 ;
F_44 ( V_1 ) ;
}
}
bool
F_296 ( struct V_1 * V_1 )
{
if ( F_274 ( & V_1 -> V_190 , 0x000 , V_1 -> V_16 ,
sizeof( V_1 -> V_16 ) ) < 0 )
return false ;
F_52 ( L_72 , ( int ) sizeof( V_1 -> V_16 ) , V_1 -> V_16 ) ;
return V_1 -> V_16 [ V_360 ] != 0 ;
}
static bool
F_297 ( struct V_1 * V_1 )
{
struct V_32 * V_33 =
F_19 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_22 ( V_1 -> V_16 [ V_360 ] != 0 ) ;
if ( ! F_296 ( V_1 ) )
return false ;
F_298 ( & V_1 -> V_190 , & V_1 -> V_273 ,
F_299 ( V_1 -> V_16 ) ) ;
if ( V_1 -> V_16 [ V_360 ] >= 0x11 )
V_33 -> V_467 = V_1 -> V_16 [ V_468 ] &
V_469 ;
F_274 ( & V_1 -> V_190 , V_470 ,
V_1 -> V_471 ,
sizeof( V_1 -> V_471 ) ) ;
if ( V_1 -> V_471 [ 0 ] & V_472 ) {
V_33 -> V_473 . V_474 = true ;
F_52 ( L_73 ) ;
}
if ( F_145 ( V_33 ) >= 9 &&
( V_1 -> V_471 [ 0 ] & V_475 ) ) {
T_3 V_476 ;
V_33 -> V_473 . V_474 = true ;
if ( F_276 ( & V_1 -> V_190 ,
V_477 ,
& V_476 ) != 1 )
V_476 = 0 ;
V_33 -> V_473 . V_478 = V_476 ? true : false ;
V_33 -> V_473 . V_479 = V_33 -> V_473 . V_478 ;
F_52 ( L_74 ,
V_33 -> V_473 . V_479 ? L_75 : L_76 ) ;
if ( V_33 -> V_473 . V_479 ) {
V_33 -> V_473 . V_480 =
F_275 ( V_1 ) ;
V_33 -> V_473 . V_481 =
F_277 ( V_1 ) ;
V_33 -> V_473 . V_482 =
F_278 ( V_1 ) ;
}
}
if ( F_274 ( & V_1 -> V_190 , V_483 ,
V_1 -> V_484 , sizeof( V_1 -> V_484 ) ) ==
sizeof( V_1 -> V_484 ) )
F_52 ( L_77 , ( int ) sizeof( V_1 -> V_484 ) ,
V_1 -> V_484 ) ;
if ( V_1 -> V_484 [ 0 ] >= 0x03 ) {
T_11 V_18 [ V_58 ] ;
int V_14 ;
F_274 ( & V_1 -> V_190 , V_485 ,
V_18 , sizeof( V_18 ) ) ;
for ( V_14 = 0 ; V_14 < F_24 ( V_18 ) ; V_14 ++ ) {
int V_461 = F_300 ( V_18 [ V_14 ] ) ;
if ( V_461 == 0 )
break;
V_1 -> V_18 [ V_14 ] = ( V_461 * 200 ) / 10 ;
}
V_1 -> V_20 = V_14 ;
}
if ( V_1 -> V_20 )
V_1 -> V_243 = true ;
else
F_9 ( V_1 ) ;
F_31 ( V_1 ) ;
return true ;
}
static bool
F_301 ( struct V_1 * V_1 )
{
T_1 V_486 ;
if ( ! F_296 ( V_1 ) )
return false ;
if ( ! F_1 ( V_1 ) ) {
F_9 ( V_1 ) ;
F_31 ( V_1 ) ;
}
if ( F_276 ( & V_1 -> V_190 , V_487 , & V_486 ) <= 0 )
return false ;
V_1 -> V_486 = F_302 ( V_486 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_486 )
return false ;
if ( ! F_299 ( V_1 -> V_16 ) )
return true ;
if ( V_1 -> V_16 [ V_360 ] == 0x10 )
return true ;
if ( F_274 ( & V_1 -> V_190 , V_488 ,
V_1 -> V_37 ,
V_489 ) < 0 )
return false ;
return true ;
}
static bool
F_303 ( struct V_1 * V_1 )
{
T_1 V_490 ;
if ( ! V_491 . V_492 )
return false ;
if ( ! V_1 -> V_493 )
return false ;
if ( V_1 -> V_16 [ V_360 ] < 0x12 )
return false ;
if ( F_276 ( & V_1 -> V_190 , V_494 , & V_490 ) != 1 )
return false ;
return V_490 & V_495 ;
}
static void
F_304 ( struct V_1 * V_1 )
{
if ( ! V_491 . V_492 )
return;
if ( ! V_1 -> V_493 )
return;
V_1 -> V_496 = F_303 ( V_1 ) ;
if ( V_1 -> V_496 )
F_52 ( L_78 ) ;
else
F_52 ( L_79 ) ;
F_305 ( & V_1 -> V_497 ,
V_1 -> V_496 ) ;
}
static int F_306 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_261 * V_261 = F_157 ( V_40 -> V_4 . V_4 . V_262 ) ;
T_1 V_498 ;
int V_172 = 0 ;
int V_230 = 0 ;
int V_499 = 10 ;
if ( F_276 ( & V_1 -> V_190 , V_500 , & V_498 ) < 0 ) {
F_52 ( L_80 ) ;
V_172 = - V_185 ;
goto V_179;
}
if ( F_222 ( & V_1 -> V_190 , V_500 ,
V_498 & ~ V_501 ) < 0 ) {
F_52 ( L_80 ) ;
V_172 = - V_185 ;
goto V_179;
}
do {
F_307 ( V_33 , V_261 -> V_92 ) ;
if ( F_276 ( & V_1 -> V_190 ,
V_502 , & V_498 ) < 0 ) {
V_172 = - V_185 ;
goto V_179;
}
V_230 = V_498 & V_503 ;
} while ( -- V_499 && V_230 );
if ( V_499 == 0 ) {
F_52 ( L_81 ) ;
V_172 = - V_186 ;
}
V_179:
F_308 ( V_261 ) ;
return V_172 ;
}
static int F_309 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_261 * V_261 = F_157 ( V_40 -> V_4 . V_4 . V_262 ) ;
T_1 V_498 ;
int V_172 ;
if ( F_276 ( & V_1 -> V_190 , V_502 , & V_498 ) < 0 )
return - V_185 ;
if ( ! ( V_498 & V_504 ) )
return - V_505 ;
if ( F_276 ( & V_1 -> V_190 , V_500 , & V_498 ) < 0 )
return - V_185 ;
if ( V_498 & V_501 ) {
V_172 = F_306 ( V_1 ) ;
if ( V_172 )
return V_172 ;
}
F_310 ( V_261 ) ;
if ( F_222 ( & V_1 -> V_190 , V_500 ,
V_498 | V_501 ) < 0 ) {
F_308 ( V_261 ) ;
return - V_185 ;
}
F_307 ( V_33 , V_261 -> V_92 ) ;
return 0 ;
}
int F_311 ( struct V_1 * V_1 , T_1 * V_506 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_261 * V_261 = F_157 ( V_40 -> V_4 . V_4 . V_262 ) ;
T_1 V_498 ;
int V_230 , V_172 ;
int V_499 = 6 ;
V_172 = F_309 ( V_1 ) ;
if ( V_172 )
return V_172 ;
do {
F_307 ( V_33 , V_261 -> V_92 ) ;
if ( F_276 ( & V_1 -> V_190 ,
V_502 , & V_498 ) < 0 ) {
V_172 = - V_185 ;
goto V_507;
}
V_230 = V_498 & V_503 ;
} while ( -- V_499 && V_230 == 0 );
if ( V_499 == 0 ) {
F_35 ( L_82 ) ;
V_172 = - V_186 ;
goto V_507;
}
if ( F_274 ( & V_1 -> V_190 , V_508 , V_506 , 6 ) < 0 ) {
V_172 = - V_185 ;
goto V_507;
}
V_507:
F_306 ( V_1 ) ;
return V_172 ;
}
static bool
F_312 ( struct V_1 * V_1 , T_1 * V_509 )
{
return F_276 ( & V_1 -> V_190 , V_510 ,
V_509 ) == 1 ;
}
static bool
F_313 ( struct V_1 * V_1 , T_1 * V_509 )
{
int V_172 ;
V_172 = F_274 ( & V_1 -> V_190 ,
V_511 ,
V_509 , 14 ) ;
if ( V_172 != 14 )
return false ;
return true ;
}
static T_3 F_314 ( struct V_1 * V_1 )
{
int V_148 = 0 ;
int V_287 ;
T_3 V_288 , V_512 ;
V_148 = F_276 ( & V_1 -> V_190 , V_513 ,
& V_288 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_83 ) ;
return V_514 ;
}
V_288 &= V_515 ;
V_148 = F_276 ( & V_1 -> V_190 , V_516 ,
& V_512 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_84 ) ;
return V_514 ;
}
V_287 = F_315 ( V_512 ) ;
if ( ! F_33 ( V_1 , V_287 ,
V_288 ) )
return V_514 ;
V_1 -> V_246 . V_288 = V_288 ;
V_1 -> V_246 . V_287 = V_287 ;
return V_517 ;
}
static T_3 F_316 ( struct V_1 * V_1 )
{
T_3 V_518 ;
T_3 V_519 ;
T_12 V_520 , V_521 ;
int V_148 = 0 ;
V_148 = F_276 ( & V_1 -> V_190 , V_522 ,
& V_518 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_85 ) ;
return V_514 ;
}
if ( V_518 != V_523 )
return V_514 ;
V_148 = F_274 ( & V_1 -> V_190 , V_524 ,
& V_520 , 2 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_86 ) ;
return V_514 ;
}
V_148 = F_274 ( & V_1 -> V_190 , V_525 ,
& V_521 , 2 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_87 ) ;
return V_514 ;
}
V_148 = F_276 ( & V_1 -> V_190 , V_526 ,
& V_519 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_88 ) ;
return V_514 ;
}
if ( ( V_519 & V_527 ) != V_528 )
return V_514 ;
if ( V_519 & V_529 )
return V_514 ;
switch ( V_519 & V_530 ) {
case V_531 :
V_1 -> V_246 . V_247 . V_244 = 6 ;
break;
case V_532 :
V_1 -> V_246 . V_247 . V_244 = 8 ;
break;
default:
return V_514 ;
}
V_1 -> V_246 . V_247 . V_533 = V_518 ;
V_1 -> V_246 . V_247 . V_76 = F_317 ( V_520 ) ;
V_1 -> V_246 . V_247 . V_78 = F_317 ( V_521 ) ;
V_1 -> V_246 . V_534 = 1 ;
return V_517 ;
}
static T_3 F_318 ( struct V_1 * V_1 )
{
T_3 V_535 = V_517 ;
struct V_71 * V_71 = V_1 -> V_263 ;
struct V_8 * V_9 = & V_71 -> V_4 ;
if ( V_71 -> V_536 == NULL ||
V_9 -> V_537 ||
V_1 -> V_190 . V_538 > 6 ) {
if ( V_1 -> V_190 . V_539 > 0 ||
V_1 -> V_190 . V_538 > 0 )
F_52 ( L_89 ,
V_1 -> V_190 . V_539 ,
V_1 -> V_190 . V_538 ) ;
V_1 -> V_246 . V_247 . V_540 = V_541 ;
} else {
struct V_540 * V_542 = V_71 -> V_536 ;
V_542 += V_71 -> V_536 -> V_543 ;
if ( F_222 ( & V_1 -> V_190 , V_544 ,
V_542 -> V_545 ) <= 0 )
F_52 ( L_90 ) ;
V_535 = V_517 | V_546 ;
V_1 -> V_246 . V_247 . V_540 = V_547 ;
}
V_1 -> V_246 . V_534 = 1 ;
return V_535 ;
}
static T_3 F_319 ( struct V_1 * V_1 )
{
T_3 V_535 = V_514 ;
return V_535 ;
}
static void F_320 ( struct V_1 * V_1 )
{
T_3 V_548 = V_514 ;
T_3 V_197 = 0 ;
int V_148 ;
V_148 = F_276 ( & V_1 -> V_190 , V_549 , & V_197 ) ;
if ( V_148 <= 0 ) {
F_52 ( L_91 ) ;
goto V_550;
}
switch ( V_197 ) {
case V_286 :
F_52 ( L_92 ) ;
V_548 = F_314 ( V_1 ) ;
break;
case V_551 :
F_52 ( L_93 ) ;
V_548 = F_316 ( V_1 ) ;
break;
case V_552 :
F_52 ( L_94 ) ;
V_548 = F_318 ( V_1 ) ;
break;
case V_553 :
F_52 ( L_95 ) ;
V_548 = F_319 ( V_1 ) ;
break;
default:
F_52 ( L_96 , V_197 ) ;
break;
}
if ( V_548 & V_517 )
V_1 -> V_246 . V_285 = V_197 ;
V_550:
V_148 = F_222 ( & V_1 -> V_190 , V_554 , V_548 ) ;
if ( V_148 <= 0 )
F_52 ( L_97 ) ;
}
static int
F_321 ( struct V_1 * V_1 )
{
bool V_555 ;
if ( V_1 -> V_496 ) {
T_1 V_556 [ 16 ] = { 0 } ;
int V_172 = 0 ;
int V_557 ;
bool V_558 ;
V_555 = F_313 ( V_1 , V_556 ) ;
V_559:
if ( V_555 == true ) {
if ( V_1 -> V_560 &&
! F_322 ( & V_556 [ 10 ] , V_1 -> V_65 ) ) {
F_52 ( L_98 ) ;
F_253 ( V_1 ) ;
F_254 ( V_1 ) ;
}
F_52 ( L_99 , V_556 ) ;
V_172 = F_323 ( & V_1 -> V_497 , V_556 , & V_558 ) ;
if ( V_558 ) {
for ( V_557 = 0 ; V_557 < 3 ; V_557 ++ ) {
int V_561 ;
V_561 = F_324 ( & V_1 -> V_190 ,
V_511 + 1 ,
& V_556 [ 1 ] , 3 ) ;
if ( V_561 == 3 ) {
break;
}
}
V_555 = F_313 ( V_1 , V_556 ) ;
if ( V_555 == true ) {
F_52 ( L_100 , V_556 ) ;
goto V_559;
}
} else
V_172 = 0 ;
return V_172 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_52 ( L_101 ) ;
V_1 -> V_496 = false ;
F_305 ( & V_1 -> V_497 , V_1 -> V_496 ) ;
F_325 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_209 ;
}
static void
F_326 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
struct V_261 * V_262 = F_157 ( V_31 -> V_4 . V_262 ) ;
F_294 ( V_33 , V_262 -> V_92 , false ) ;
if ( V_262 -> V_562 -> V_275 )
F_295 ( V_33 ,
F_327 ( V_262 ) , false ) ;
F_253 ( V_1 ) ;
F_254 ( V_1 ) ;
F_307 ( V_33 , V_262 -> V_92 ) ;
F_294 ( V_33 , V_262 -> V_92 , true ) ;
if ( V_262 -> V_562 -> V_275 )
F_295 ( V_33 ,
F_327 ( V_262 ) , true ) ;
}
static void
F_328 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_405 [ V_406 ] ;
F_22 ( ! F_329 ( & V_7 -> V_563 . V_564 ) ) ;
if ( ! F_273 ( V_1 , V_405 ) ) {
F_35 ( L_102 ) ;
return;
}
if ( ! V_30 -> V_4 . V_262 )
return;
if ( ! F_157 ( V_30 -> V_4 . V_262 ) -> V_367 )
return;
if ( ! F_33 ( V_1 , V_1 -> V_64 ,
V_1 -> V_65 ) )
return;
if ( ! F_322 ( V_405 , V_1 -> V_65 ) ) {
F_52 ( L_103 ,
V_30 -> V_4 . V_223 ) ;
F_326 ( V_1 ) ;
}
}
static bool
F_330 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_509 = 0 ;
T_1 V_565 = V_1 -> V_486 ;
bool V_172 ;
memset ( & V_1 -> V_246 , 0 , sizeof( V_1 -> V_246 ) ) ;
V_172 = F_301 ( V_1 ) ;
if ( ( V_565 != V_1 -> V_486 ) || ! V_172 ) {
return false ;
}
if ( V_1 -> V_16 [ V_360 ] >= 0x11 &&
F_312 ( V_1 , & V_509 ) &&
V_509 != 0 ) {
F_222 ( & V_1 -> V_190 ,
V_510 ,
V_509 ) ;
if ( V_509 & V_566 )
F_320 ( V_1 ) ;
if ( V_509 & ( V_567 | V_568 ) )
F_255 ( L_104 ) ;
}
F_331 ( & V_7 -> V_563 . V_564 , NULL ) ;
F_328 ( V_1 ) ;
F_332 ( & V_7 -> V_563 . V_564 ) ;
if ( V_1 -> V_246 . V_285 == V_286 ) {
F_52 ( L_105 ) ;
F_325 ( V_30 -> V_4 . V_7 ) ;
}
return true ;
}
static enum V_569
F_333 ( struct V_1 * V_1 )
{
struct V_364 * V_365 = F_223 ( V_1 ) ;
T_3 * V_16 = V_1 -> V_16 ;
T_3 type ;
if ( V_365 -> V_367 )
F_334 ( V_365 ) ;
if ( ! F_301 ( V_1 ) )
return V_570 ;
if ( F_1 ( V_1 ) )
return V_571 ;
if ( ! F_299 ( V_16 ) )
return V_571 ;
if ( V_1 -> V_16 [ V_360 ] >= 0x11 &&
V_1 -> V_37 [ 0 ] & V_572 ) {
return V_1 -> V_486 ?
V_571 : V_570 ;
}
if ( F_303 ( V_1 ) )
return V_571 ;
if ( F_335 ( & V_1 -> V_190 . V_573 ) )
return V_571 ;
if ( V_1 -> V_16 [ V_360 ] >= 0x11 ) {
type = V_1 -> V_37 [ 0 ] & V_38 ;
if ( type == V_39 ||
type == V_574 )
return V_575 ;
} else {
type = V_1 -> V_16 [ V_576 ] &
V_577 ;
if ( type == V_578 ||
type == V_579 )
return V_575 ;
}
F_52 ( L_106 ) ;
return V_570 ;
}
static enum V_569
F_336 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_569 V_148 ;
V_148 = F_337 ( V_33 ) ;
if ( V_148 == V_575 )
V_148 = V_571 ;
return V_148 ;
}
static bool F_338 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
T_2 V_580 ;
switch ( V_41 -> V_41 ) {
case V_218 :
V_580 = V_581 ;
break;
case V_220 :
V_580 = V_582 ;
break;
case V_51 :
V_580 = V_583 ;
break;
default:
F_122 ( V_41 -> V_41 ) ;
return false ;
}
return F_26 ( V_584 ) & V_580 ;
}
static bool F_339 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
T_2 V_580 ;
switch ( V_41 -> V_41 ) {
case V_218 :
V_580 = V_585 ;
break;
case V_220 :
V_580 = V_586 ;
break;
case V_51 :
V_580 = V_587 ;
break;
default:
F_122 ( V_41 -> V_41 ) ;
return false ;
}
return F_26 ( V_584 ) & V_580 ;
}
static bool F_340 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
T_2 V_580 ;
switch ( V_41 -> V_41 ) {
case V_50 :
V_580 = V_588 ;
break;
case V_589 :
V_580 = V_590 ;
break;
default:
return F_339 ( V_33 , V_41 ) ;
}
return F_26 ( V_584 ) & V_580 ;
}
static bool F_341 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
T_2 V_580 ;
switch ( V_41 -> V_41 ) {
case V_218 :
V_580 = V_591 ;
break;
case V_220 :
V_580 = V_592 ;
break;
case V_51 :
V_580 = V_593 ;
break;
default:
F_122 ( V_41 -> V_41 ) ;
return false ;
}
return F_26 ( V_594 ) & V_580 ;
}
static bool F_342 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
T_2 V_580 ;
switch ( V_41 -> V_41 ) {
case V_218 :
V_580 = V_595 ;
break;
case V_220 :
V_580 = V_596 ;
break;
case V_51 :
V_580 = V_597 ;
break;
default:
F_122 ( V_41 -> V_41 ) ;
return false ;
}
return F_26 ( V_594 ) & V_580 ;
}
static bool F_343 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
if ( V_41 -> V_41 == V_50 )
return F_26 ( V_598 ) & V_599 ;
else
return F_338 ( V_33 , V_41 ) ;
}
static bool F_344 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
if ( V_41 -> V_41 == V_50 )
return F_26 ( V_598 ) & V_599 ;
else
return F_339 ( V_33 , V_41 ) ;
}
static bool F_345 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
if ( V_41 -> V_41 == V_50 )
return F_26 ( V_598 ) & V_600 ;
else
return F_339 ( V_33 , V_41 ) ;
}
static bool F_346 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
if ( V_41 -> V_41 == V_50 )
return F_26 ( V_601 ) & V_602 ;
else
return F_339 ( V_33 , V_41 ) ;
}
static bool F_347 ( struct V_32 * V_33 ,
struct V_2 * V_3 )
{
struct V_30 * V_30 = & V_3 -> V_4 ;
enum V_41 V_41 ;
T_2 V_580 ;
V_41 = F_348 ( V_30 -> V_603 ) ;
switch ( V_41 ) {
case V_50 :
V_580 = V_604 ;
break;
case V_218 :
V_580 = V_605 ;
break;
case V_220 :
V_580 = V_606 ;
break;
default:
F_122 ( V_41 ) ;
return false ;
}
return F_26 ( V_601 ) & V_580 ;
}
bool F_349 ( struct V_32 * V_33 ,
struct V_2 * V_41 )
{
if ( F_164 ( V_33 ) ) {
if ( F_350 ( V_33 ) )
return F_342 ( V_33 , V_41 ) ;
else
return F_341 ( V_33 , V_41 ) ;
}
if ( F_199 ( V_33 ) )
return F_343 ( V_33 , V_41 ) ;
else if ( F_107 ( V_33 ) )
return F_344 ( V_33 , V_41 ) ;
else if ( F_173 ( V_33 ) )
return F_345 ( V_33 , V_41 ) ;
else if ( F_351 ( V_33 ) )
return F_346 ( V_33 , V_41 ) ;
else if ( F_23 ( V_33 ) )
return F_347 ( V_33 , V_41 ) ;
else
return F_340 ( V_33 , V_41 ) ;
}
static struct V_540 *
F_352 ( struct V_1 * V_1 )
{
struct V_71 * V_71 = V_1 -> V_263 ;
if ( V_71 -> V_540 ) {
if ( F_353 ( V_71 -> V_540 ) )
return NULL ;
return F_354 ( V_71 -> V_540 ) ;
} else
return F_355 ( & V_71 -> V_4 ,
& V_1 -> V_190 . V_573 ) ;
}
static void
F_356 ( struct V_1 * V_1 )
{
struct V_71 * V_71 = V_1 -> V_263 ;
struct V_540 * V_540 ;
F_357 ( V_1 ) ;
V_540 = F_352 ( V_1 ) ;
V_71 -> V_536 = V_540 ;
V_1 -> V_277 = F_358 ( V_540 ) ;
}
static void
F_357 ( struct V_1 * V_1 )
{
struct V_71 * V_71 = V_1 -> V_263 ;
F_139 ( V_71 -> V_536 ) ;
V_71 -> V_536 = NULL ;
V_1 -> V_277 = false ;
}
static int
F_359 ( struct V_71 * V_71 )
{
struct V_8 * V_9 = & V_71 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_569 V_148 ;
T_1 V_509 = 0 ;
F_22 ( ! F_329 ( & V_9 -> V_7 -> V_563 . V_564 ) ) ;
F_42 ( F_19 ( V_7 ) , V_1 -> V_90 ) ;
if ( F_1 ( V_1 ) )
V_148 = F_336 ( V_1 ) ;
else if ( F_349 ( F_19 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_148 = F_333 ( V_1 ) ;
else
V_148 = V_570 ;
if ( V_148 == V_570 ) {
memset ( & V_1 -> V_246 , 0 , sizeof( V_1 -> V_246 ) ) ;
if ( V_1 -> V_496 ) {
F_52 ( L_107 ,
V_1 -> V_496 ,
V_1 -> V_497 . V_607 ) ;
V_1 -> V_496 = false ;
F_305 ( & V_1 -> V_497 ,
V_1 -> V_496 ) ;
}
goto V_179;
}
if ( V_30 -> type != V_5 )
V_30 -> type = V_115 ;
F_52 ( L_108 ,
F_360 ( F_28 ( V_1 ) ) ,
F_360 ( F_361 ( V_1 -> V_16 ) ) ) ;
if ( V_1 -> V_608 ) {
V_1 -> V_26 = F_11 ( V_1 ) ;
V_1 -> V_66 = F_10 ( V_1 ) ;
V_1 -> V_608 = false ;
}
F_149 ( V_1 ) ;
F_298 ( & V_1 -> V_190 , & V_1 -> V_273 ,
F_299 ( V_1 -> V_16 ) ) ;
F_304 ( V_1 ) ;
if ( V_1 -> V_496 ) {
V_148 = V_570 ;
goto V_179;
} else {
F_328 ( V_1 ) ;
}
V_1 -> V_190 . V_539 = 0 ;
V_1 -> V_190 . V_538 = 0 ;
F_356 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_71 -> V_536 )
V_148 = V_571 ;
V_1 -> V_609 = true ;
if ( V_1 -> V_16 [ V_360 ] >= 0x11 &&
F_312 ( V_1 , & V_509 ) &&
V_509 != 0 ) {
F_222 ( & V_1 -> V_190 ,
V_510 ,
V_509 ) ;
if ( V_509 & V_566 )
F_320 ( V_1 ) ;
if ( V_509 & ( V_567 | V_568 ) )
F_255 ( L_104 ) ;
}
V_179:
if ( V_148 != V_571 && ! V_1 -> V_496 )
F_357 ( V_1 ) ;
F_46 ( F_19 ( V_7 ) , V_1 -> V_90 ) ;
return V_148 ;
}
static int
F_362 ( struct V_8 * V_9 ,
struct V_610 * V_611 ,
bool V_612 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_148 = V_9 -> V_148 ;
F_52 ( L_109 ,
V_9 -> V_4 . V_613 , V_9 -> V_223 ) ;
if ( ! V_1 -> V_609 )
V_148 = F_359 ( V_1 -> V_263 ) ;
V_1 -> V_609 = false ;
return V_148 ;
}
static void
F_363 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
struct V_32 * V_33 = F_19 ( V_30 -> V_4 . V_7 ) ;
F_52 ( L_109 ,
V_9 -> V_4 . V_613 , V_9 -> V_223 ) ;
F_357 ( V_1 ) ;
if ( V_9 -> V_148 != V_571 )
return;
F_42 ( V_33 , V_1 -> V_90 ) ;
F_356 ( V_1 ) ;
F_46 ( V_33 , V_1 -> V_90 ) ;
if ( V_30 -> type != V_5 )
V_30 -> type = V_115 ;
}
static int F_364 ( struct V_8 * V_9 )
{
struct V_71 * V_71 = F_37 ( V_9 ) ;
struct V_540 * V_540 ;
V_540 = V_71 -> V_536 ;
if ( V_540 ) {
int V_172 = F_365 ( V_9 , V_540 ) ;
if ( V_172 )
return V_172 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_71 -> V_73 . V_72 ) {
struct V_69 * V_70 ;
V_70 = F_366 ( V_9 -> V_7 ,
V_71 -> V_73 . V_72 ) ;
if ( V_70 ) {
F_367 ( V_9 , V_70 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_368 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_172 ;
V_172 = F_369 ( V_9 ) ;
if ( V_172 )
return V_172 ;
F_370 ( V_9 ) ;
F_52 ( L_110 ,
V_1 -> V_190 . V_223 , V_9 -> V_614 -> V_615 . V_223 ) ;
V_1 -> V_190 . V_7 = V_9 -> V_614 ;
return F_371 ( & V_1 -> V_190 ) ;
}
static void
F_372 ( struct V_8 * V_9 )
{
F_373 ( & F_4 ( V_9 ) -> V_190 ) ;
F_374 ( V_9 ) ;
}
static void
F_375 ( struct V_8 * V_9 )
{
struct V_71 * V_71 = F_37 ( V_9 ) ;
F_139 ( V_71 -> V_536 ) ;
if ( ! F_376 ( V_71 -> V_540 ) )
F_139 ( V_71 -> V_540 ) ;
if ( V_9 -> V_616 == V_617 )
F_377 ( & V_71 -> V_73 ) ;
F_378 ( V_9 ) ;
F_139 ( V_9 ) ;
}
void F_379 ( struct V_618 * V_31 )
{
struct V_2 * V_3 = F_380 ( V_31 ) ;
struct V_1 * V_1 = & V_3 -> V_619 ;
F_381 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_382 ( & V_1 -> V_340 ) ;
F_41 ( V_1 ) ;
F_192 ( V_1 ) ;
F_44 ( V_1 ) ;
if ( V_1 -> V_137 . V_620 ) {
F_383 ( & V_1 -> V_137 ) ;
V_1 -> V_137 . V_620 = NULL ;
}
}
F_138 ( V_1 ) ;
F_384 ( V_31 ) ;
F_139 ( V_3 ) ;
}
void F_385 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = F_5 ( & V_30 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_382 ( & V_1 -> V_340 ) ;
F_41 ( V_1 ) ;
F_192 ( V_1 ) ;
F_44 ( V_1 ) ;
}
static void F_386 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_66 ( & V_33 -> V_91 ) ;
if ( ! F_93 ( V_1 ) )
return;
F_52 ( L_111 ) ;
F_42 ( V_33 , V_1 -> V_90 ) ;
F_195 ( V_1 ) ;
}
static enum V_92 F_387 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
if ( ( V_1 -> V_100 & V_102 ) == 0 )
return V_117 ;
if ( F_54 ( V_33 ) )
return F_231 ( V_1 -> V_100 ) ;
else
return F_232 ( V_1 -> V_100 ) ;
}
void F_388 ( struct V_618 * V_31 )
{
struct V_32 * V_33 = F_19 ( V_31 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_31 ) ;
struct V_364 * V_365 = F_223 ( V_1 ) ;
if ( ! F_160 ( V_33 ) )
V_1 -> V_100 = F_26 ( V_1 -> V_101 ) ;
if ( V_365 -> V_367 )
F_334 ( V_365 ) ;
V_1 -> V_608 = true ;
F_41 ( V_1 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
V_1 -> V_116 = F_387 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_389 ( V_31 -> V_7 , V_1 ) ;
F_386 ( V_1 ) ;
}
F_44 ( V_1 ) ;
}
enum V_621
F_390 ( struct V_2 * V_3 , bool V_622 )
{
struct V_1 * V_1 = & V_3 -> V_619 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_621 V_172 = V_623 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_624 )
V_3 -> V_4 . type = V_115 ;
if ( V_622 && V_3 -> V_4 . type == V_5 ) {
F_52 ( L_112 ,
F_51 ( V_3 -> V_41 ) ) ;
return V_625 ;
}
F_52 ( L_113 ,
F_51 ( V_3 -> V_41 ) ,
V_622 ? L_114 : L_115 ) ;
if ( V_622 ) {
V_1 -> V_608 = true ;
V_1 -> V_609 = false ;
return V_623 ;
}
F_42 ( V_33 , V_1 -> V_90 ) ;
if ( V_1 -> V_496 ) {
if ( F_321 ( V_1 ) == - V_209 ) {
F_52 ( L_107 ,
V_1 -> V_496 , V_1 -> V_497 . V_607 ) ;
V_1 -> V_496 = false ;
F_305 ( & V_1 -> V_497 ,
V_1 -> V_496 ) ;
V_1 -> V_609 = false ;
goto V_626;
}
}
if ( ! V_1 -> V_496 ) {
if ( ! F_330 ( V_1 ) ) {
V_1 -> V_609 = false ;
goto V_626;
}
}
V_172 = V_625 ;
V_626:
F_46 ( V_33 , V_1 -> V_90 ) ;
return V_172 ;
}
bool F_391 ( struct V_32 * V_33 , enum V_41 V_41 )
{
if ( F_145 ( V_33 ) < 5 )
return false ;
if ( F_145 ( V_33 ) < 9 && V_41 == V_50 )
return true ;
return F_392 ( V_33 , V_41 ) ;
}
static void
F_393 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_33 = F_19 ( V_9 -> V_7 ) ;
F_394 ( V_9 ) ;
F_395 ( V_9 ) ;
if ( F_1 ( V_1 ) ) {
T_2 V_627 ;
V_627 = F_396 ( V_628 ) | F_396 ( V_629 ) ;
if ( ! F_164 ( V_33 ) )
V_627 |= F_396 ( V_630 ) ;
F_397 ( V_9 , V_627 ) ;
V_9 -> V_304 -> V_284 = V_628 ;
}
}
static void F_398 ( struct V_1 * V_1 )
{
V_1 -> V_327 = F_183 () ;
V_1 -> V_331 = V_328 ;
V_1 -> V_333 = V_328 ;
}
static void
F_399 ( struct V_32 * V_33 ,
struct V_1 * V_1 , struct V_631 * V_632 )
{
T_2 V_130 , V_131 , V_132 = 0 , V_633 = 0 ;
struct V_125 V_126 ;
F_82 ( V_33 , V_1 , & V_126 ) ;
V_633 = F_188 ( V_1 ) ;
V_130 = F_26 ( V_126 . V_130 ) ;
V_131 = F_26 ( V_126 . V_131 ) ;
if ( ! F_23 ( V_33 ) && ! F_84 ( V_33 ) ) {
F_59 ( V_126 . V_128 , V_633 ) ;
V_132 = F_26 ( V_126 . V_132 ) ;
}
V_632 -> V_634 = ( V_130 & V_635 ) >>
V_636 ;
V_632 -> V_637 = ( V_130 & V_638 ) >>
V_639 ;
V_632 -> V_640 = ( V_131 & V_641 ) >>
V_642 ;
V_632 -> V_643 = ( V_131 & V_644 ) >>
V_645 ;
if ( F_23 ( V_33 ) || F_84 ( V_33 ) ) {
V_632 -> V_646 = ( ( V_633 & V_647 ) >>
V_648 ) * 1000 ;
} else {
V_632 -> V_646 = ( ( V_132 & V_649 ) >>
V_650 ) * 1000 ;
}
}
static void
F_400 ( const char * V_651 , const struct V_631 * V_632 )
{
F_52 ( L_116 ,
V_651 ,
V_632 -> V_634 , V_632 -> V_637 , V_632 -> V_640 , V_632 -> V_643 , V_632 -> V_646 ) ;
}
static void
F_178 ( struct V_32 * V_33 ,
struct V_1 * V_1 )
{
struct V_631 V_153 ;
struct V_631 * V_652 = & V_1 -> V_653 ;
F_399 ( V_33 , V_1 , & V_153 ) ;
if ( V_153 . V_634 != V_652 -> V_634 || V_153 . V_637 != V_652 -> V_637 || V_153 . V_640 != V_652 -> V_640 ||
V_153 . V_643 != V_652 -> V_643 || V_153 . V_646 != V_652 -> V_646 ) {
F_35 ( L_117 ) ;
F_400 ( L_118 , V_652 ) ;
F_400 ( L_119 , & V_153 ) ;
}
}
static void
F_68 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_631 V_654 , V_212 , V_655 ,
* V_656 = & V_1 -> V_653 ;
F_66 ( & V_33 -> V_91 ) ;
if ( V_656 -> V_646 != 0 )
return;
F_399 ( V_33 , V_1 , & V_654 ) ;
F_400 ( L_120 , & V_654 ) ;
V_212 = V_33 -> V_212 . V_291 . V_657 ;
if ( V_33 -> V_658 & V_659 ) {
V_212 . V_646 = F_401 ( V_660 , V_212 . V_646 , 1300 * 10 ) ;
F_52 ( L_121 ,
V_212 . V_646 ) ;
}
V_212 . V_646 += 100 * 10 ;
V_655 . V_634 = 210 * 10 ;
V_655 . V_637 = 50 * 10 ;
V_655 . V_640 = 50 * 10 ;
V_655 . V_643 = 500 * 10 ;
V_655 . V_646 = ( 510 + 100 ) * 10 ;
F_400 ( L_122 , & V_212 ) ;
#define F_402 ( T_13 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_402 ( V_634 ) ;
F_402 ( V_637 ) ;
F_402 ( V_640 ) ;
F_402 ( V_643 ) ;
F_402 ( V_646 ) ;
#undef F_402
#define F_403 ( T_13 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_341 = F_403 ( V_634 ) ;
V_1 -> V_332 = F_403 ( V_637 ) ;
V_1 -> V_334 = F_403 ( V_640 ) ;
V_1 -> V_466 = F_403 ( V_643 ) ;
V_1 -> V_144 = F_403 ( V_646 ) ;
#undef F_403
F_52 ( L_123 ,
V_1 -> V_341 , V_1 -> V_466 ,
V_1 -> V_144 ) ;
F_52 ( L_124 ,
V_1 -> V_332 , V_1 -> V_334 ) ;
V_656 -> V_637 = 1 ;
V_656 -> V_640 = 1 ;
}
static void
F_69 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
bool V_661 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_2 V_130 , V_131 , V_132 , V_122 = 0 ;
int div = V_33 -> V_151 / 1000 ;
struct V_125 V_126 ;
enum V_41 V_41 = F_2 ( V_1 ) -> V_41 ;
const struct V_631 * V_632 = & V_1 -> V_653 ;
F_66 ( & V_33 -> V_91 ) ;
F_82 ( V_33 , V_1 , & V_126 ) ;
if ( V_661 ) {
T_2 V_337 = F_188 ( V_1 ) ;
F_8 ( V_337 & V_342 , L_125 ) ;
if ( V_337 & V_120 )
F_52 ( L_126 ) ;
V_337 &= ~ V_120 ;
F_59 ( V_126 . V_128 , V_337 ) ;
}
V_130 = ( V_632 -> V_634 << V_636 ) |
( V_632 -> V_637 << V_639 ) ;
V_131 = ( V_632 -> V_640 << V_642 ) |
( V_632 -> V_643 << V_645 ) ;
if ( F_23 ( V_33 ) || F_84 ( V_33 ) ) {
V_132 = F_26 ( V_126 . V_128 ) ;
V_132 &= ~ V_647 ;
V_132 |= ( F_16 ( V_632 -> V_646 , 1000 )
<< V_648 ) ;
} else {
V_132 = ( ( 100 * div ) / 2 - 1 ) << V_662 ;
V_132 |= ( F_16 ( V_632 -> V_646 , 1000 )
<< V_650 ) ;
}
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
V_122 = F_78 ( V_41 ) ;
} else if ( F_293 ( V_33 ) || F_175 ( V_33 ) ) {
if ( V_41 == V_50 )
V_122 = V_663 ;
else
V_122 = V_664 ;
}
V_130 |= V_122 ;
F_59 ( V_126 . V_130 , V_130 ) ;
F_59 ( V_126 . V_131 , V_131 ) ;
if ( F_23 ( V_33 ) || F_84 ( V_33 ) )
F_59 ( V_126 . V_128 , V_132 ) ;
else
F_59 ( V_126 . V_132 , V_132 ) ;
F_52 ( L_127 ,
F_26 ( V_126 . V_130 ) ,
F_26 ( V_126 . V_131 ) ,
( F_23 ( V_33 ) || F_84 ( V_33 ) ) ?
( F_26 ( V_126 . V_128 ) & V_647 ) :
F_26 ( V_126 . V_132 ) ) ;
}
static void F_389 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
F_79 ( V_1 ) ;
} else {
F_68 ( V_7 , V_1 ) ;
F_69 ( V_7 , V_1 , false ) ;
}
}
static void F_404 ( struct V_32 * V_33 ,
struct V_226 * V_349 ,
int V_665 )
{
struct V_30 * V_31 ;
struct V_2 * V_40 = NULL ;
struct V_1 * V_1 = V_33 -> V_300 . V_619 ;
struct V_261 * V_261 = F_157 ( V_349 -> V_4 . V_262 ) ;
enum V_666 V_67 = V_667 ;
if ( V_665 <= 0 ) {
F_52 ( L_128 ) ;
return;
}
if ( V_1 == NULL ) {
F_52 ( L_129 ) ;
return;
}
V_40 = F_2 ( V_1 ) ;
V_31 = & V_40 -> V_4 ;
V_261 = F_157 ( V_31 -> V_4 . V_262 ) ;
if ( ! V_261 ) {
F_52 ( L_130 ) ;
return;
}
if ( V_33 -> V_300 . type < V_301 ) {
F_52 ( L_131 ) ;
return;
}
if ( V_1 -> V_263 -> V_73 . V_299 -> V_668 ==
V_665 )
V_67 = V_669 ;
if ( V_67 == V_33 -> V_300 . V_670 ) {
F_52 (
L_132 ) ;
return;
}
if ( ! V_349 -> V_4 . V_367 ) {
F_52 ( L_133 ) ;
return;
}
if ( F_145 ( V_33 ) >= 8 && ! F_54 ( V_33 ) ) {
switch ( V_67 ) {
case V_667 :
F_405 ( V_261 , V_671 ) ;
break;
case V_669 :
F_405 ( V_261 , V_672 ) ;
break;
case V_673 :
default:
F_35 ( L_134 ) ;
}
} else if ( F_145 ( V_33 ) > 6 ) {
T_6 V_674 = F_406 ( V_349 -> V_675 ) ;
T_2 V_461 ;
V_461 = F_26 ( V_674 ) ;
if ( V_67 > V_667 ) {
if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
V_461 |= V_676 ;
else
V_461 |= V_677 ;
} else {
if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
V_461 &= ~ V_676 ;
else
V_461 &= ~ V_677 ;
}
F_59 ( V_674 , V_461 ) ;
}
V_33 -> V_300 . V_670 = V_67 ;
F_52 ( L_135 , V_665 ) ;
}
void F_407 ( struct V_1 * V_1 ,
struct V_226 * V_349 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! V_349 -> V_276 ) {
F_52 ( L_136 ) ;
return;
}
F_43 ( & V_33 -> V_300 . V_678 ) ;
if ( F_22 ( V_33 -> V_300 . V_619 ) ) {
F_35 ( L_137 ) ;
goto V_679;
}
V_33 -> V_300 . V_680 = 0 ;
V_33 -> V_300 . V_619 = V_1 ;
V_679:
F_45 ( & V_33 -> V_300 . V_678 ) ;
}
void F_408 ( struct V_1 * V_1 ,
struct V_226 * V_378 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! V_378 -> V_276 )
return;
F_43 ( & V_33 -> V_300 . V_678 ) ;
if ( ! V_33 -> V_300 . V_619 ) {
F_45 ( & V_33 -> V_300 . V_678 ) ;
return;
}
if ( V_33 -> V_300 . V_670 == V_669 )
F_404 ( V_33 , V_378 ,
V_1 -> V_263 -> V_73 . V_72 -> V_668 ) ;
V_33 -> V_300 . V_619 = NULL ;
F_45 ( & V_33 -> V_300 . V_678 ) ;
F_382 ( & V_33 -> V_300 . V_681 ) ;
}
static void F_409 ( struct V_343 * V_681 )
{
struct V_32 * V_33 =
F_89 ( V_681 , F_90 ( * V_33 ) , V_300 . V_681 . V_681 ) ;
struct V_1 * V_1 ;
F_43 ( & V_33 -> V_300 . V_678 ) ;
V_1 = V_33 -> V_300 . V_619 ;
if ( ! V_1 )
goto V_679;
if ( V_33 -> V_300 . V_680 )
goto V_679;
if ( V_33 -> V_300 . V_670 != V_669 ) {
struct V_682 * V_262 = F_2 ( V_1 ) -> V_4 . V_4 . V_262 ;
F_404 ( V_33 , F_157 ( V_262 ) -> V_562 ,
V_1 -> V_263 -> V_73 . V_299 -> V_668 ) ;
}
V_679:
F_45 ( & V_33 -> V_300 . V_678 ) ;
}
void F_410 ( struct V_32 * V_33 ,
unsigned int V_683 )
{
struct V_682 * V_262 ;
enum V_92 V_92 ;
if ( V_33 -> V_300 . type == V_684 )
return;
F_189 ( & V_33 -> V_300 . V_681 ) ;
F_43 ( & V_33 -> V_300 . V_678 ) ;
if ( ! V_33 -> V_300 . V_619 ) {
F_45 ( & V_33 -> V_300 . V_678 ) ;
return;
}
V_262 = F_2 ( V_33 -> V_300 . V_619 ) -> V_4 . V_4 . V_262 ;
V_92 = F_157 ( V_262 ) -> V_92 ;
V_683 &= F_411 ( V_92 ) ;
V_33 -> V_300 . V_680 |= V_683 ;
if ( V_683 && V_33 -> V_300 . V_670 == V_669 )
F_404 ( V_33 , F_157 ( V_262 ) -> V_562 ,
V_33 -> V_300 . V_619 -> V_263 -> V_73 . V_72 -> V_668 ) ;
F_45 ( & V_33 -> V_300 . V_678 ) ;
}
void F_412 ( struct V_32 * V_33 ,
unsigned int V_683 )
{
struct V_682 * V_262 ;
enum V_92 V_92 ;
if ( V_33 -> V_300 . type == V_684 )
return;
F_189 ( & V_33 -> V_300 . V_681 ) ;
F_43 ( & V_33 -> V_300 . V_678 ) ;
if ( ! V_33 -> V_300 . V_619 ) {
F_45 ( & V_33 -> V_300 . V_678 ) ;
return;
}
V_262 = F_2 ( V_33 -> V_300 . V_619 ) -> V_4 . V_4 . V_262 ;
V_92 = F_157 ( V_262 ) -> V_92 ;
V_683 &= F_411 ( V_92 ) ;
V_33 -> V_300 . V_680 &= ~ V_683 ;
if ( V_683 && V_33 -> V_300 . V_670 == V_669 )
F_404 ( V_33 , F_157 ( V_262 ) -> V_562 ,
V_33 -> V_300 . V_619 -> V_263 -> V_73 . V_72 -> V_668 ) ;
if ( ! V_33 -> V_300 . V_680 )
F_197 ( & V_33 -> V_300 . V_681 ,
F_196 ( 1000 ) ) ;
F_45 ( & V_33 -> V_300 . V_678 ) ;
}
static struct V_69 *
F_413 ( struct V_71 * V_71 ,
struct V_69 * V_72 )
{
struct V_8 * V_9 = & V_71 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_69 * V_299 = NULL ;
F_414 ( & V_33 -> V_300 . V_681 , F_409 ) ;
F_415 ( & V_33 -> V_300 . V_678 ) ;
if ( F_145 ( V_33 ) <= 6 ) {
F_52 ( L_138 ) ;
return NULL ;
}
if ( V_33 -> V_212 . V_685 != V_301 ) {
F_52 ( L_139 ) ;
return NULL ;
}
V_299 = F_416
( V_33 , V_72 , V_9 ) ;
if ( ! V_299 ) {
F_52 ( L_140 ) ;
return NULL ;
}
V_33 -> V_300 . type = V_33 -> V_212 . V_685 ;
V_33 -> V_300 . V_670 = V_667 ;
F_52 ( L_141 ) ;
return V_299 ;
}
static bool F_417 ( struct V_1 * V_1 ,
struct V_71 * V_71 )
{
struct V_8 * V_9 = & V_71 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_30 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_69 * V_72 = NULL ;
struct V_69 * V_282 = NULL ;
struct V_69 * V_299 = NULL ;
bool V_686 ;
struct V_69 * V_687 ;
struct V_540 * V_540 ;
enum V_92 V_92 = V_117 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_418 ( V_7 ) ) {
F_22 ( ! ( F_293 ( V_33 ) || F_175 ( V_33 ) ) ) ;
F_419 ( L_142 ) ;
return false ;
}
F_41 ( V_1 ) ;
F_398 ( V_1 ) ;
F_389 ( V_7 , V_1 ) ;
F_386 ( V_1 ) ;
F_44 ( V_1 ) ;
V_686 = F_297 ( V_1 ) ;
if ( ! V_686 ) {
F_419 ( L_143 ) ;
goto V_688;
}
F_43 ( & V_7 -> V_563 . V_678 ) ;
V_540 = F_355 ( V_9 , & V_1 -> V_190 . V_573 ) ;
if ( V_540 ) {
if ( F_420 ( V_9 , V_540 ) ) {
F_421 ( V_9 ,
V_540 ) ;
F_422 ( V_9 , V_540 ) ;
} else {
F_139 ( V_540 ) ;
V_540 = F_423 ( - V_209 ) ;
}
} else {
V_540 = F_423 ( - V_689 ) ;
}
V_71 -> V_540 = V_540 ;
F_424 (scan, &connector->probed_modes, head) {
if ( ( V_687 -> type & V_690 ) ) {
V_72 = F_366 ( V_7 , V_687 ) ;
V_299 = F_413 (
V_71 , V_72 ) ;
} else if ( ! V_282 ) {
V_282 = F_366 ( V_7 , V_687 ) ;
}
}
if ( ! V_72 && V_33 -> V_212 . V_691 ) {
V_72 = F_366 ( V_7 ,
V_33 -> V_212 . V_691 ) ;
if ( V_72 ) {
V_72 -> type |= V_690 ;
V_9 -> V_290 . V_692 = V_72 -> V_692 ;
V_9 -> V_290 . V_693 = V_72 -> V_693 ;
}
}
F_45 ( & V_7 -> V_563 . V_678 ) ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) ) {
V_1 -> V_137 . V_620 = F_88 ;
F_425 ( & V_1 -> V_137 ) ;
V_92 = F_387 ( V_1 ) ;
if ( V_92 != V_114 && V_92 != V_107 )
V_92 = V_1 -> V_93 ;
if ( V_92 != V_114 && V_92 != V_107 )
V_92 = V_114 ;
F_52 ( L_144 ,
F_50 ( V_92 ) ) ;
}
F_426 ( & V_71 -> V_73 , V_72 , V_282 ,
V_299 ) ;
V_71 -> V_73 . V_694 . V_695 = F_209 ;
F_427 ( V_9 , V_92 ) ;
return true ;
V_688:
F_382 ( & V_1 -> V_340 ) ;
F_41 ( V_1 ) ;
F_192 ( V_1 ) ;
F_44 ( V_1 ) ;
return false ;
}
static void
F_428 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_619 ;
V_31 -> V_603 = F_429 ( V_3 -> V_41 ) ;
switch ( V_3 -> V_41 ) {
case V_50 :
V_1 -> V_90 = V_696 ;
break;
case V_218 :
V_1 -> V_90 = V_697 ;
break;
case V_220 :
V_1 -> V_90 = V_698 ;
break;
case V_51 :
V_1 -> V_90 = V_699 ;
break;
case V_589 :
V_1 -> V_90 = V_699 ;
break;
default:
F_122 ( V_3 -> V_41 ) ;
}
}
static void F_430 ( struct V_343 * V_681 )
{
struct V_71 * V_71 ;
struct V_8 * V_9 ;
V_71 = F_89 ( V_681 , F_90 ( * V_71 ) ,
V_700 ) ;
V_9 = & V_71 -> V_4 ;
F_52 ( L_109 , V_9 -> V_4 . V_613 ,
V_9 -> V_223 ) ;
F_43 ( & V_9 -> V_7 -> V_563 . V_678 ) ;
F_431 ( V_9 ,
V_701 ) ;
F_45 ( & V_9 -> V_7 -> V_563 . V_678 ) ;
F_325 ( V_9 -> V_7 ) ;
}
bool
F_432 ( struct V_2 * V_3 ,
struct V_71 * V_71 )
{
struct V_8 * V_9 = & V_71 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_619 ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_30 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_41 V_41 = V_3 -> V_41 ;
int type ;
F_433 ( & V_71 -> V_700 ,
F_430 ) ;
if ( F_8 ( V_3 -> V_24 < 1 ,
L_145 ,
V_3 -> V_24 , F_51 ( V_41 ) ) )
return false ;
F_21 ( V_1 ) ;
V_1 -> V_608 = true ;
V_1 -> V_93 = V_117 ;
V_1 -> V_116 = V_117 ;
if ( F_145 ( V_33 ) >= 9 )
V_1 -> V_181 = F_105 ;
else if ( F_143 ( V_33 ) || F_108 ( V_33 ) )
V_1 -> V_181 = F_103 ;
else if ( F_135 ( V_33 ) )
V_1 -> V_181 = F_102 ;
else
V_1 -> V_181 = F_100 ;
if ( F_145 ( V_33 ) >= 9 )
V_1 -> V_183 = F_109 ;
else
V_1 -> V_183 = F_106 ;
if ( F_160 ( V_33 ) )
V_1 -> V_702 = V_703 ;
V_1 -> V_100 = F_26 ( V_1 -> V_101 ) ;
V_1 -> V_263 = V_71 ;
if ( F_391 ( V_33 , V_41 ) )
type = V_617 ;
else
type = V_704 ;
if ( F_81 ( V_33 ) || F_54 ( V_33 ) )
V_1 -> V_116 = F_387 ( V_1 ) ;
if ( type == V_617 )
V_30 -> type = V_5 ;
if ( F_22 ( ( F_81 ( V_33 ) || F_54 ( V_33 ) ) &&
F_1 ( V_1 ) && V_41 != V_218 && V_41 != V_220 ) )
return false ;
F_52 ( L_146 ,
type == V_617 ? L_147 : L_148 ,
F_51 ( V_41 ) ) ;
F_434 ( V_7 , V_9 , & V_705 , type ) ;
F_435 ( V_9 , & V_706 ) ;
V_9 -> V_707 = true ;
V_9 -> V_708 = 0 ;
F_428 ( V_3 ) ;
F_140 ( V_1 ) ;
F_414 ( & V_1 -> V_340 ,
F_193 ) ;
F_436 ( V_71 , V_30 ) ;
if ( F_160 ( V_33 ) )
V_71 -> V_709 = V_710 ;
else
V_71 -> V_709 = V_711 ;
if ( F_437 ( V_33 ) && ! F_1 ( V_1 ) &&
( V_41 == V_218 || V_41 == V_220 || V_41 == V_51 ) )
F_438 ( V_3 ,
V_71 -> V_4 . V_4 . V_613 ) ;
if ( ! F_417 ( V_1 , V_71 ) ) {
F_138 ( V_1 ) ;
F_381 ( V_3 ) ;
goto V_712;
}
F_393 ( V_1 , V_9 ) ;
if ( F_147 ( V_33 ) && ! F_350 ( V_33 ) ) {
T_2 V_383 = F_26 ( V_713 ) ;
F_59 ( V_713 , ( V_383 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_712:
F_378 ( V_9 ) ;
return false ;
}
bool F_439 ( struct V_32 * V_33 ,
T_6 V_101 ,
enum V_41 V_41 )
{
struct V_2 * V_3 ;
struct V_30 * V_30 ;
struct V_618 * V_31 ;
struct V_71 * V_71 ;
V_3 = F_440 ( sizeof( * V_3 ) , V_224 ) ;
if ( ! V_3 )
return false ;
V_71 = F_441 () ;
if ( ! V_71 )
goto V_714;
V_30 = & V_3 -> V_4 ;
V_31 = & V_30 -> V_4 ;
if ( F_442 ( & V_33 -> V_124 , & V_30 -> V_4 ,
& V_715 , V_716 ,
L_149 , F_51 ( V_41 ) ) )
goto V_717;
V_30 -> V_718 = F_156 ;
V_30 -> V_719 = F_236 ;
V_30 -> V_709 = F_225 ;
V_30 -> V_720 = F_233 ;
V_30 -> V_721 = F_385 ;
if ( F_54 ( V_33 ) ) {
V_30 -> V_722 = F_269 ;
V_30 -> V_723 = F_266 ;
V_30 -> V_352 = F_258 ;
V_30 -> V_724 = F_243 ;
V_30 -> V_725 = F_271 ;
} else if ( F_81 ( V_33 ) ) {
V_30 -> V_722 = F_264 ;
V_30 -> V_723 = F_262 ;
V_30 -> V_352 = F_258 ;
V_30 -> V_724 = F_242 ;
} else {
V_30 -> V_723 = F_260 ;
V_30 -> V_352 = F_257 ;
if ( F_145 ( V_33 ) >= 5 )
V_30 -> V_724 = F_241 ;
}
V_3 -> V_41 = V_41 ;
V_3 -> V_619 . V_101 = V_101 ;
V_3 -> V_24 = 4 ;
V_30 -> type = V_115 ;
V_30 -> V_369 = F_443 ( V_41 ) ;
if ( F_54 ( V_33 ) ) {
if ( V_41 == V_51 )
V_30 -> V_726 = 1 << 2 ;
else
V_30 -> V_726 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_30 -> V_726 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_30 -> V_727 = 0 ;
V_30 -> V_41 = V_41 ;
V_3 -> V_728 = F_390 ;
V_33 -> V_729 . V_730 [ V_41 ] = V_3 ;
if ( ! F_432 ( V_3 , V_71 ) )
goto V_731;
return true ;
V_731:
F_384 ( V_31 ) ;
V_717:
F_139 ( V_71 ) ;
V_714:
F_139 ( V_3 ) ;
return false ;
}
void F_444 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_732 ; V_14 ++ ) {
struct V_2 * V_3 = V_33 -> V_729 . V_730 [ V_14 ] ;
if ( ! V_3 || ! V_3 -> V_619 . V_493 )
continue;
if ( V_3 -> V_619 . V_496 )
F_445 ( & V_3 -> V_619 . V_497 ) ;
}
}
void F_446 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_732 ; V_14 ++ ) {
struct V_2 * V_3 = V_33 -> V_729 . V_730 [ V_14 ] ;
int V_172 ;
if ( ! V_3 || ! V_3 -> V_619 . V_493 )
continue;
V_172 = F_447 ( & V_3 -> V_619 . V_497 ) ;
if ( V_172 )
F_321 ( & V_3 -> V_619 ) ;
}
}
