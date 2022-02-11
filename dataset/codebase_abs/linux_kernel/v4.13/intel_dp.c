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
const int * V_41 ;
int V_42 ;
F_22 ( V_1 -> V_41 || V_1 -> V_43 ) ;
if ( F_23 ( V_33 ) ) {
V_41 = V_44 ;
V_42 = F_24 ( V_44 ) ;
} else if ( F_25 ( V_33 ) ) {
V_41 = V_45 ;
V_42 = F_24 ( V_45 ) ;
} else {
V_41 = V_19 ;
V_42 = F_24 ( V_19 ) ;
}
if ( ! F_26 ( V_1 ) )
V_42 -- ;
V_1 -> V_41 = V_41 ;
V_1 -> V_43 = V_42 ;
}
static int F_27 ( const int * V_41 , int V_46 ,
const int * V_18 , int V_47 ,
int * V_21 )
{
int V_14 = 0 , V_48 = 0 , V_49 = 0 ;
while ( V_14 < V_46 && V_48 < V_47 ) {
if ( V_41 [ V_14 ] == V_18 [ V_48 ] ) {
if ( F_22 ( V_49 >= V_50 ) )
return V_49 ;
V_21 [ V_49 ] = V_41 [ V_14 ] ;
++ V_49 ;
++ V_14 ;
++ V_48 ;
} else if ( V_41 [ V_14 ] < V_18 [ V_48 ] ) {
++ V_14 ;
} else {
++ V_48 ;
}
}
return V_49 ;
}
static int F_28 ( const int * V_51 , int V_52 , int V_53 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_52 ; V_14 ++ )
if ( V_53 == V_51 [ V_14 ] )
return V_14 ;
return - 1 ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_22 ( ! V_1 -> V_43 || ! V_1 -> V_20 ) ;
V_1 -> V_22 = F_27 ( V_1 -> V_41 ,
V_1 -> V_43 ,
V_1 -> V_18 ,
V_1 -> V_20 ,
V_1 -> V_21 ) ;
if ( F_22 ( V_1 -> V_22 == 0 ) ) {
V_1 -> V_21 [ 0 ] = V_19 [ 0 ] ;
V_1 -> V_22 = 1 ;
}
}
static int F_30 ( struct V_1 * V_1 ,
int V_54 )
{
const int * V_21 = V_1 -> V_21 ;
int V_14 , V_55 = V_1 -> V_22 ;
for ( V_14 = 0 ; V_14 < V_55 ; V_14 ++ ) {
if ( V_21 [ V_55 - V_14 - 1 ] <= V_54 )
return V_55 - V_14 ;
}
return 0 ;
}
static bool F_31 ( struct V_1 * V_1 )
{
if ( V_1 -> V_56 == 0 ||
V_1 -> V_56 > V_1 -> V_57 )
return false ;
if ( V_1 -> V_58 == 0 ||
V_1 -> V_58 > F_14 ( V_1 ) )
return false ;
return true ;
}
int F_32 ( struct V_1 * V_1 ,
int V_56 , T_2 V_58 )
{
int V_59 ;
V_59 = F_28 ( V_1 -> V_21 ,
V_1 -> V_22 ,
V_56 ) ;
if ( V_59 > 0 ) {
V_1 -> V_57 = V_1 -> V_21 [ V_59 - 1 ] ;
V_1 -> V_26 = V_58 ;
} else if ( V_58 > 1 ) {
V_1 -> V_57 = F_10 ( V_1 ) ;
V_1 -> V_26 = V_58 >> 1 ;
} else {
F_33 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static enum V_60
F_34 ( struct V_8 * V_9 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_63 * V_63 = F_35 ( V_9 ) ;
struct V_61 * V_64 = V_63 -> V_65 . V_64 ;
int V_66 = V_62 -> clock ;
int V_54 , V_67 , V_24 , V_29 ;
int V_34 ;
V_34 = F_18 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_64 ) {
if ( V_62 -> V_68 > V_64 -> V_68 )
return V_69 ;
if ( V_62 -> V_70 > V_64 -> V_70 )
return V_69 ;
V_66 = V_64 -> clock ;
}
V_29 = F_36 ( V_1 ) ;
V_24 = F_14 ( V_1 ) ;
V_54 = F_17 ( V_29 , V_24 ) ;
V_67 = F_15 ( V_66 , 18 ) ;
if ( V_67 > V_54 || V_66 > V_34 )
return V_71 ;
if ( V_62 -> clock < 10000 )
return V_72 ;
if ( V_62 -> V_73 & V_74 )
return V_75 ;
return V_76 ;
}
T_3 F_37 ( const T_2 * V_77 , int V_78 )
{
int V_14 ;
T_3 V_79 = 0 ;
if ( V_78 > 4 )
V_78 = 4 ;
for ( V_14 = 0 ; V_14 < V_78 ; V_14 ++ )
V_79 |= ( ( T_3 ) V_77 [ V_14 ] ) << ( ( 3 - V_14 ) * 8 ) ;
return V_79 ;
}
static void F_38 ( T_3 V_77 , T_2 * V_80 , int V_81 )
{
int V_14 ;
if ( V_81 > 4 )
V_81 = 4 ;
for ( V_14 = 0 ; V_14 < V_81 ; V_14 ++ )
V_80 [ V_14 ] = V_77 >> ( ( 3 - V_14 ) * 8 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_40 ( V_33 , V_1 -> V_82 ) ;
F_41 ( & V_33 -> V_83 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_43 ( & V_33 -> V_83 ) ;
F_44 ( V_33 , V_1 -> V_82 ) ;
}
static void
F_45 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_84 V_84 = V_1 -> V_85 ;
bool V_86 , V_87 = false ;
enum V_88 V_89 = F_46 ( V_84 ) ;
enum V_90 V_91 = F_47 ( V_84 ) ;
T_3 V_92 ;
if ( F_8 ( F_48 ( V_1 -> V_93 ) & V_94 ,
L_3 ,
F_49 ( V_84 ) , F_50 ( V_3 -> V_95 ) ) )
return;
F_51 ( L_4 ,
F_49 ( V_84 ) , F_50 ( V_3 -> V_95 ) ) ;
V_92 = F_48 ( V_1 -> V_93 ) & V_96 ;
V_92 |= V_97 | V_98 ;
V_92 |= F_52 ( 1 ) ;
V_92 |= V_99 ;
if ( F_53 ( V_33 ) )
V_92 |= F_54 ( V_84 ) ;
else if ( V_84 == V_100 )
V_92 |= V_101 ;
V_86 = F_48 ( F_55 ( V_84 ) ) & V_102 ;
if ( ! V_86 ) {
V_87 = F_53 ( V_33 ) &&
! F_56 ( V_33 , V_89 , V_91 , true ) ;
if ( F_57 ( V_33 , V_84 , F_53 ( V_33 ) ?
& V_103 [ 0 ] . V_104 : & V_105 [ 0 ] . V_104 ) ) {
F_33 ( L_5 ,
F_49 ( V_84 ) ) ;
return;
}
}
F_58 ( V_1 -> V_93 , V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
F_58 ( V_1 -> V_93 , V_92 | V_94 ) ;
F_59 ( V_1 -> V_93 ) ;
F_58 ( V_1 -> V_93 , V_92 & ~ V_94 ) ;
F_59 ( V_1 -> V_93 ) ;
if ( ! V_86 ) {
F_60 ( V_33 , V_84 ) ;
if ( V_87 )
F_56 ( V_33 , V_89 , V_91 , false ) ;
}
}
static enum V_84 F_61 ( struct V_32 * V_33 )
{
struct V_30 * V_31 ;
unsigned int V_106 = ( 1 << V_107 ) | ( 1 << V_100 ) ;
F_62 (&dev_priv->drm, encoder) {
struct V_1 * V_1 ;
if ( V_31 -> type != V_108 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
if ( V_31 -> type == V_5 ) {
F_22 ( V_1 -> V_109 != V_110 &&
V_1 -> V_109 != V_1 -> V_85 ) ;
if ( V_1 -> V_85 != V_110 )
V_106 &= ~ ( 1 << V_1 -> V_85 ) ;
} else {
F_22 ( V_1 -> V_85 != V_110 ) ;
if ( V_1 -> V_109 != V_110 )
V_106 &= ~ ( 1 << V_1 -> V_109 ) ;
}
}
if ( V_106 == 0 )
return V_110 ;
return F_63 ( V_106 ) - 1 ;
}
static enum V_84
F_64 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_84 V_84 ;
F_65 ( & V_33 -> V_83 ) ;
F_22 ( ! F_1 ( V_1 ) ) ;
F_22 ( V_1 -> V_109 != V_110 &&
V_1 -> V_109 != V_1 -> V_85 ) ;
if ( V_1 -> V_85 != V_110 )
return V_1 -> V_85 ;
V_84 = F_61 ( V_33 ) ;
if ( F_22 ( V_84 == V_110 ) )
V_84 = V_107 ;
F_66 ( V_7 , V_84 ) ;
V_1 -> V_85 = V_84 ;
F_51 ( L_6 ,
F_49 ( V_1 -> V_85 ) ,
F_50 ( V_3 -> V_95 ) ) ;
F_67 ( V_7 , V_1 ) ;
F_68 ( V_7 , V_1 , true ) ;
F_45 ( V_1 ) ;
return V_1 -> V_85 ;
}
static int
F_69 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_65 ( & V_33 -> V_83 ) ;
F_22 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_111 )
return 0 ;
V_1 -> V_111 = false ;
F_68 ( V_7 , V_1 , false ) ;
return 0 ;
}
static bool F_70 ( struct V_32 * V_33 ,
enum V_84 V_84 )
{
return F_48 ( F_71 ( V_84 ) ) & V_112 ;
}
static bool F_72 ( struct V_32 * V_33 ,
enum V_84 V_84 )
{
return F_48 ( F_73 ( V_84 ) ) & V_113 ;
}
static bool F_74 ( struct V_32 * V_33 ,
enum V_84 V_84 )
{
return true ;
}
static enum V_84
F_75 ( struct V_32 * V_33 ,
enum V_95 V_95 ,
T_4 V_114 )
{
enum V_84 V_84 ;
for ( V_84 = V_107 ; V_84 <= V_100 ; V_84 ++ ) {
T_5 V_115 = F_48 ( F_76 ( V_84 ) ) &
V_116 ;
if ( V_115 != F_77 ( V_95 ) )
continue;
if ( ! V_114 ( V_33 , V_84 ) )
continue;
return V_84 ;
}
return V_110 ;
}
static void
F_78 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
F_65 ( & V_33 -> V_83 ) ;
V_1 -> V_85 = F_75 ( V_33 , V_95 ,
F_70 ) ;
if ( V_1 -> V_85 == V_110 )
V_1 -> V_85 = F_75 ( V_33 , V_95 ,
F_72 ) ;
if ( V_1 -> V_85 == V_110 )
V_1 -> V_85 = F_75 ( V_33 , V_95 ,
F_74 ) ;
if ( V_1 -> V_85 == V_110 ) {
F_51 ( L_7 ,
F_50 ( V_95 ) ) ;
return;
}
F_51 ( L_8 ,
F_50 ( V_95 ) , F_49 ( V_1 -> V_85 ) ) ;
F_67 ( V_7 , V_1 ) ;
F_68 ( V_7 , V_1 , false ) ;
}
void F_79 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = & V_33 -> V_117 ;
struct V_30 * V_31 ;
if ( F_22 ( ! F_80 ( V_33 ) && ! F_53 ( V_33 ) &&
! F_23 ( V_33 ) ) )
return;
F_62 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_31 -> type != V_108 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
F_22 ( V_1 -> V_109 != V_110 ) ;
if ( V_31 -> type != V_5 )
continue;
if ( F_23 ( V_33 ) )
V_1 -> V_111 = true ;
else
V_1 -> V_85 = V_110 ;
}
}
static void F_81 ( struct V_32 * V_33 ,
struct V_1 * V_1 ,
struct V_118 * V_119 )
{
int V_120 = 0 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
if ( F_23 ( V_33 ) )
V_120 = F_69 ( V_1 ) ;
else if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
V_120 = F_64 ( V_1 ) ;
V_119 -> V_121 = F_73 ( V_120 ) ;
V_119 -> V_122 = F_71 ( V_120 ) ;
V_119 -> V_123 = F_76 ( V_120 ) ;
V_119 -> V_124 = F_82 ( V_120 ) ;
if ( ! F_23 ( V_33 ) && ! F_83 ( V_33 ) )
V_119 -> V_125 = F_84 ( V_120 ) ;
}
static T_6
F_85 ( struct V_1 * V_1 )
{
struct V_118 V_119 ;
F_81 ( F_19 ( F_3 ( V_1 ) ) , V_1 ,
& V_119 ) ;
return V_119 . V_121 ;
}
static T_6
F_86 ( struct V_1 * V_1 )
{
struct V_118 V_119 ;
F_81 ( F_19 ( F_3 ( V_1 ) ) , V_1 ,
& V_119 ) ;
return V_119 . V_122 ;
}
static int F_87 ( struct V_126 * V_127 , unsigned long V_128 ,
void * V_129 )
{
struct V_1 * V_1 = F_88 ( V_127 , F_89 ( * V_1 ) ,
V_130 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_128 != V_131 )
return 0 ;
F_39 ( V_1 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
enum V_84 V_84 = F_64 ( V_1 ) ;
T_6 V_132 , V_133 ;
T_5 V_125 ;
V_132 = F_73 ( V_84 ) ;
V_133 = F_84 ( V_84 ) ;
V_125 = F_48 ( V_133 ) ;
V_125 &= V_134 ;
F_58 ( V_133 , V_125 | 0x1F ) ;
F_58 ( V_132 , V_135 | V_136 ) ;
F_90 ( V_1 -> V_137 ) ;
}
F_42 ( V_1 ) ;
return 0 ;
}
static bool F_91 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_65 ( & V_33 -> V_83 ) ;
if ( ( F_80 ( V_33 ) || F_53 ( V_33 ) ) &&
V_1 -> V_85 == V_110 )
return false ;
return ( F_48 ( F_86 ( V_1 ) ) & V_112 ) != 0 ;
}
static bool F_92 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_65 ( & V_33 -> V_83 ) ;
if ( ( F_80 ( V_33 ) || F_53 ( V_33 ) ) &&
V_1 -> V_85 == V_110 )
return false ;
return F_48 ( F_85 ( V_1 ) ) & V_113 ;
}
static void
F_93 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_91 ( V_1 ) && ! F_92 ( V_1 ) ) {
F_8 ( 1 , L_9 ) ;
F_51 ( L_10 ,
F_48 ( F_86 ( V_1 ) ) ,
F_48 ( F_85 ( V_1 ) ) ) ;
}
}
static T_3
F_94 ( struct V_1 * V_1 , bool V_138 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_6 V_139 = V_1 -> V_140 ;
T_3 V_141 ;
bool V_142 ;
#define F_95 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_138 )
V_142 = F_96 ( V_33 -> V_143 , F_95 ,
F_97 ( 10 ) ) ;
else
V_142 = F_98 ( F_95 , 10 ) == 0 ;
if ( ! V_142 )
F_33 ( L_11 ,
V_138 ) ;
#undef F_95
return V_141 ;
}
static T_3 F_99 ( struct V_1 * V_1 , int V_59 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_59 )
return 0 ;
return F_100 ( V_33 -> V_144 , 2000 ) ;
}
static T_3 F_101 ( struct V_1 * V_1 , int V_59 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_59 )
return 0 ;
if ( V_3 -> V_95 == V_145 )
return F_100 ( V_33 -> V_146 . V_147 . V_146 , 2000 ) ;
else
return F_100 ( V_33 -> V_144 , 2000 ) ;
}
static T_3 F_102 ( struct V_1 * V_1 , int V_59 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_95 != V_145 && F_103 ( V_33 ) ) {
switch ( V_59 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_101 ( V_1 , V_59 ) ;
}
static T_3 F_104 ( struct V_1 * V_1 , int V_59 )
{
return V_59 ? 0 : 1 ;
}
static T_3 F_105 ( struct V_1 * V_1 ,
bool V_138 ,
int V_148 ,
T_3 V_149 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_3 V_150 , V_151 ;
if ( F_106 ( V_33 ) )
V_150 = 3 ;
else
V_150 = 5 ;
if ( F_107 ( V_33 ) && V_3 -> V_95 == V_145 )
V_151 = V_152 ;
else
V_151 = V_153 ;
return V_154 |
V_155 |
( V_138 ? V_156 : 0 ) |
V_157 |
V_151 |
V_158 |
( V_148 << V_159 ) |
( V_150 << V_160 ) |
( V_149 << V_161 ) ;
}
static T_3 F_108 ( struct V_1 * V_1 ,
bool V_138 ,
int V_148 ,
T_3 V_129 )
{
return V_154 |
V_155 |
( V_138 ? V_156 : 0 ) |
V_157 |
V_162 |
V_158 |
( V_148 << V_159 ) |
F_109 ( 32 ) |
F_110 ( 32 ) ;
}
static int
F_111 ( struct V_1 * V_1 ,
const T_2 * V_163 , int V_148 ,
T_2 * V_164 , int V_165 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_6 V_139 = V_1 -> V_140 ;
T_3 V_149 ;
int V_14 , V_166 , V_167 ;
T_3 V_141 ;
int V_168 , clock = 0 ;
bool V_138 = F_112 ( V_33 ) ;
bool V_169 ;
F_39 ( V_1 ) ;
V_169 = F_113 ( V_1 ) ;
F_114 ( & V_33 -> V_170 , 0 ) ;
F_93 ( V_1 ) ;
for ( V_168 = 0 ; V_168 < 3 ; V_168 ++ ) {
V_141 = F_115 ( V_139 ) ;
if ( ( V_141 & V_154 ) == 0 )
break;
F_90 ( 1 ) ;
}
if ( V_168 == 3 ) {
static T_5 V_171 = - 1 ;
const T_5 V_141 = F_48 ( V_139 ) ;
if ( V_141 != V_171 ) {
F_8 ( 1 , L_12 ,
V_141 ) ;
V_171 = V_141 ;
}
V_166 = - V_172 ;
goto V_173;
}
if ( F_22 ( V_148 > 20 || V_165 > 20 ) ) {
V_166 = - V_174 ;
goto V_173;
}
while ( ( V_149 = V_1 -> V_175 ( V_1 , clock ++ ) ) ) {
T_5 V_176 = V_1 -> V_177 ( V_1 ,
V_138 ,
V_148 ,
V_149 ) ;
for ( V_168 = 0 ; V_168 < 5 ; V_168 ++ ) {
for ( V_14 = 0 ; V_14 < V_148 ; V_14 += 4 )
F_58 ( V_1 -> V_178 [ V_14 >> 2 ] ,
F_37 ( V_163 + V_14 ,
V_148 - V_14 ) ) ;
F_58 ( V_139 , V_176 ) ;
V_141 = F_94 ( V_1 , V_138 ) ;
F_58 ( V_139 ,
V_141 |
V_155 |
V_157 |
V_158 ) ;
if ( V_141 & V_157 )
continue;
if ( V_141 & V_158 ) {
F_116 ( 400 , 500 ) ;
continue;
}
if ( V_141 & V_155 )
goto V_142;
}
}
if ( ( V_141 & V_155 ) == 0 ) {
F_33 ( L_13 , V_141 ) ;
V_166 = - V_172 ;
goto V_173;
}
V_142:
if ( V_141 & V_158 ) {
F_33 ( L_14 , V_141 ) ;
V_166 = - V_179 ;
goto V_173;
}
if ( V_141 & V_157 ) {
F_51 ( L_15 , V_141 ) ;
V_166 = - V_180 ;
goto V_173;
}
V_167 = ( ( V_141 & V_181 ) >>
V_159 ) ;
if ( V_167 == 0 || V_167 > 20 ) {
F_51 ( L_16 ,
V_167 ) ;
F_116 ( 1000 , 1500 ) ;
V_166 = - V_172 ;
goto V_173;
}
if ( V_167 > V_165 )
V_167 = V_165 ;
for ( V_14 = 0 ; V_14 < V_167 ; V_14 += 4 )
F_38 ( F_48 ( V_1 -> V_178 [ V_14 >> 2 ] ) ,
V_164 + V_14 , V_167 - V_14 ) ;
V_166 = V_167 ;
V_173:
F_114 ( & V_33 -> V_170 , V_182 ) ;
if ( V_169 )
F_117 ( V_1 , false ) ;
F_42 ( V_1 ) ;
return V_166 ;
}
static T_7
F_118 ( struct V_183 * V_184 , struct V_185 * V_186 )
{
struct V_1 * V_1 = F_88 ( V_184 , struct V_1 , V_184 ) ;
T_2 V_187 [ 20 ] , V_188 [ 20 ] ;
T_8 V_189 , V_190 ;
int V_166 ;
V_187 [ 0 ] = ( V_186 -> V_191 << 4 ) |
( ( V_186 -> V_192 >> 16 ) & 0xf ) ;
V_187 [ 1 ] = ( V_186 -> V_192 >> 8 ) & 0xff ;
V_187 [ 2 ] = V_186 -> V_192 & 0xff ;
V_187 [ 3 ] = V_186 -> V_42 - 1 ;
switch ( V_186 -> V_191 & ~ V_193 ) {
case V_194 :
case V_195 :
case V_196 :
V_189 = V_186 -> V_42 ? V_197 + V_186 -> V_42 : V_198 ;
V_190 = 2 ;
if ( F_22 ( V_189 > 20 ) )
return - V_174 ;
F_22 ( ! V_186 -> V_199 != ! V_186 -> V_42 ) ;
if ( V_186 -> V_199 )
memcpy ( V_187 + V_197 , V_186 -> V_199 , V_186 -> V_42 ) ;
V_166 = F_111 ( V_1 , V_187 , V_189 , V_188 , V_190 ) ;
if ( V_166 > 0 ) {
V_186 -> V_200 = V_188 [ 0 ] >> 4 ;
if ( V_166 > 1 ) {
V_166 = F_119 ( int , V_188 [ 1 ] , 0 , V_186 -> V_42 ) ;
} else {
V_166 = V_186 -> V_42 ;
}
}
break;
case V_201 :
case V_202 :
V_189 = V_186 -> V_42 ? V_197 : V_198 ;
V_190 = V_186 -> V_42 + 1 ;
if ( F_22 ( V_190 > 20 ) )
return - V_174 ;
V_166 = F_111 ( V_1 , V_187 , V_189 , V_188 , V_190 ) ;
if ( V_166 > 0 ) {
V_186 -> V_200 = V_188 [ 0 ] >> 4 ;
V_166 -- ;
memcpy ( V_186 -> V_199 , V_188 + 1 , V_166 ) ;
}
break;
default:
V_166 = - V_203 ;
break;
}
return V_166 ;
}
static enum V_95 F_120 ( struct V_32 * V_33 ,
enum V_95 V_95 )
{
const struct V_204 * V_205 =
& V_33 -> V_206 . V_207 [ V_95 ] ;
enum V_95 V_208 ;
if ( ! V_205 -> V_209 ) {
F_51 ( L_17 ,
F_50 ( V_95 ) , F_50 ( V_95 ) ) ;
return V_95 ;
}
switch ( V_205 -> V_209 ) {
case V_210 :
V_208 = V_145 ;
break;
case V_211 :
V_208 = V_212 ;
break;
case V_213 :
V_208 = V_214 ;
break;
case V_215 :
V_208 = V_216 ;
break;
default:
F_121 ( V_205 -> V_209 ) ;
V_208 = V_145 ;
break;
}
F_51 ( L_18 ,
F_50 ( V_208 ) , F_50 ( V_95 ) ) ;
return V_208 ;
}
static T_6 F_122 ( struct V_32 * V_33 ,
enum V_95 V_95 )
{
switch ( V_95 ) {
case V_212 :
case V_214 :
case V_216 :
return F_123 ( V_95 ) ;
default:
F_121 ( V_95 ) ;
return F_123 ( V_212 ) ;
}
}
static T_6 F_124 ( struct V_32 * V_33 ,
enum V_95 V_95 , int V_59 )
{
switch ( V_95 ) {
case V_212 :
case V_214 :
case V_216 :
return F_125 ( V_95 , V_59 ) ;
default:
F_121 ( V_95 ) ;
return F_125 ( V_212 , V_59 ) ;
}
}
static T_6 F_126 ( struct V_32 * V_33 ,
enum V_95 V_95 )
{
switch ( V_95 ) {
case V_145 :
return F_123 ( V_95 ) ;
case V_212 :
case V_214 :
case V_216 :
return F_127 ( V_95 ) ;
default:
F_121 ( V_95 ) ;
return F_123 ( V_145 ) ;
}
}
static T_6 F_128 ( struct V_32 * V_33 ,
enum V_95 V_95 , int V_59 )
{
switch ( V_95 ) {
case V_145 :
return F_125 ( V_95 , V_59 ) ;
case V_212 :
case V_214 :
case V_216 :
return F_129 ( V_95 , V_59 ) ;
default:
F_121 ( V_95 ) ;
return F_125 ( V_145 , V_59 ) ;
}
}
static T_6 F_130 ( struct V_32 * V_33 ,
enum V_95 V_95 )
{
switch ( V_95 ) {
case V_145 :
case V_212 :
case V_214 :
case V_216 :
return F_123 ( V_95 ) ;
default:
F_121 ( V_95 ) ;
return F_123 ( V_145 ) ;
}
}
static T_6 F_131 ( struct V_32 * V_33 ,
enum V_95 V_95 , int V_59 )
{
switch ( V_95 ) {
case V_145 :
case V_212 :
case V_214 :
case V_216 :
return F_125 ( V_95 , V_59 ) ;
default:
F_121 ( V_95 ) ;
return F_125 ( V_145 , V_59 ) ;
}
}
static T_6 F_132 ( struct V_32 * V_33 ,
enum V_95 V_95 )
{
if ( F_133 ( V_33 ) -> V_217 >= 9 )
return F_130 ( V_33 , V_95 ) ;
else if ( F_134 ( V_33 ) )
return F_126 ( V_33 , V_95 ) ;
else
return F_122 ( V_33 , V_95 ) ;
}
static T_6 F_135 ( struct V_32 * V_33 ,
enum V_95 V_95 , int V_59 )
{
if ( F_133 ( V_33 ) -> V_217 >= 9 )
return F_131 ( V_33 , V_95 , V_59 ) ;
else if ( F_134 ( V_33 ) )
return F_128 ( V_33 , V_95 , V_59 ) ;
else
return F_124 ( V_33 , V_95 , V_59 ) ;
}
static void F_136 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_95 V_95 = F_120 ( V_33 ,
F_2 ( V_1 ) -> V_95 ) ;
int V_14 ;
V_1 -> V_140 = F_132 ( V_33 , V_95 ) ;
for ( V_14 = 0 ; V_14 < F_24 ( V_1 -> V_178 ) ; V_14 ++ )
V_1 -> V_178 [ V_14 ] = F_135 ( V_33 , V_95 , V_14 ) ;
}
static void
F_137 ( struct V_1 * V_1 )
{
F_138 ( V_1 -> V_184 . V_218 ) ;
}
static void
F_139 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
F_136 ( V_1 ) ;
F_140 ( & V_1 -> V_184 ) ;
V_1 -> V_184 . V_218 = F_141 ( V_219 , L_19 , F_50 ( V_95 ) ) ;
V_1 -> V_184 . V_220 = F_118 ;
}
bool F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
if ( ( F_142 ( V_33 ) && ! F_143 ( V_33 ) ) ||
F_107 ( V_33 ) || ( F_144 ( V_33 ) >= 9 ) )
return true ;
else
return false ;
}
static void
F_145 ( struct V_30 * V_31 ,
struct V_221 * V_222 )
{
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
const struct V_223 * V_224 = NULL ;
int V_14 , V_225 = 0 ;
if ( F_146 ( V_33 ) ) {
V_224 = V_226 ;
V_225 = F_24 ( V_226 ) ;
} else if ( F_134 ( V_33 ) ) {
V_224 = V_227 ;
V_225 = F_24 ( V_227 ) ;
} else if ( F_53 ( V_33 ) ) {
V_224 = V_103 ;
V_225 = F_24 ( V_103 ) ;
} else if ( F_80 ( V_33 ) ) {
V_224 = V_105 ;
V_225 = F_24 ( V_105 ) ;
}
if ( V_224 && V_225 ) {
for ( V_14 = 0 ; V_14 < V_225 ; V_14 ++ ) {
if ( V_222 -> V_228 == V_224 [ V_14 ] . clock ) {
V_222 -> V_104 = V_224 [ V_14 ] . V_104 ;
V_222 -> V_229 = true ;
break;
}
}
}
}
static void F_147 ( char * V_230 , T_8 V_52 ,
const int * V_231 , int V_232 )
{
int V_14 ;
V_230 [ 0 ] = '\0' ;
for ( V_14 = 0 ; V_14 < V_232 ; V_14 ++ ) {
int V_233 = snprintf ( V_230 , V_52 , L_20 , V_14 ? L_21 : L_22 , V_231 [ V_14 ] ) ;
if ( V_233 >= V_52 )
return;
V_230 += V_233 ;
V_52 -= V_233 ;
}
}
static void F_148 ( struct V_1 * V_1 )
{
char V_230 [ 128 ] ;
if ( ( V_234 & V_235 ) == 0 )
return;
F_147 ( V_230 , sizeof( V_230 ) ,
V_1 -> V_41 , V_1 -> V_43 ) ;
F_51 ( L_23 , V_230 ) ;
F_147 ( V_230 , sizeof( V_230 ) ,
V_1 -> V_18 , V_1 -> V_20 ) ;
F_51 ( L_24 , V_230 ) ;
F_147 ( V_230 , sizeof( V_230 ) ,
V_1 -> V_21 , V_1 -> V_22 ) ;
F_51 ( L_25 , V_230 ) ;
}
int
F_36 ( struct V_1 * V_1 )
{
int V_52 ;
V_52 = F_30 ( V_1 , V_1 -> V_57 ) ;
if ( F_22 ( V_52 <= 0 ) )
return 162000 ;
return V_1 -> V_21 [ V_52 - 1 ] ;
}
int F_149 ( struct V_1 * V_1 , int V_53 )
{
int V_14 = F_28 ( V_1 -> V_18 ,
V_1 -> V_20 , V_53 ) ;
if ( F_22 ( V_14 < 0 ) )
V_14 = 0 ;
return V_14 ;
}
void F_150 ( struct V_1 * V_1 , int V_228 ,
T_2 * V_236 , T_2 * V_237 )
{
if ( V_1 -> V_238 ) {
* V_236 = 0 ;
* V_237 =
F_149 ( V_1 , V_228 ) ;
} else {
* V_236 = F_151 ( V_228 ) ;
* V_237 = 0 ;
}
}
static int F_152 ( struct V_1 * V_1 ,
struct V_221 * V_222 )
{
int V_28 , V_239 ;
V_28 = V_222 -> V_240 ;
V_239 = F_153 ( V_1 -> V_16 , V_1 -> V_37 ) ;
if ( V_239 > 0 )
V_28 = F_13 ( V_28 , 3 * V_239 ) ;
if ( V_1 -> V_241 . V_242 . V_239 != 0 ) {
V_222 -> V_240 = 3 * V_1 -> V_241 . V_242 . V_239 ;
V_222 -> V_243 = V_222 -> V_240 == 6 * 3 ;
F_51 ( L_26 ,
V_222 -> V_240 ) ;
}
return V_28 ;
}
bool
F_154 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
struct V_61 * V_246 = & V_222 -> V_4 . V_246 ;
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
struct V_247 * V_247 = F_155 ( V_222 -> V_4 . V_248 ) ;
struct V_63 * V_63 = V_1 -> V_249 ;
struct V_250 * V_251 =
F_156 ( V_245 ) ;
int V_58 , clock ;
int V_252 = 1 ;
int V_253 = F_14 ( V_1 ) ;
int V_254 = 0 ;
int V_255 ;
int V_28 , V_67 ;
int V_256 , V_257 ;
int V_55 ;
T_2 V_236 , V_237 ;
bool V_258 = F_157 ( & V_1 -> V_259 ,
V_260 ) ;
V_55 = F_30 ( V_1 ,
V_1 -> V_57 ) ;
F_22 ( V_55 <= 0 ) ;
V_255 = V_55 - 1 ;
if ( F_134 ( V_33 ) && ! F_158 ( V_33 ) && V_95 != V_145 )
V_222 -> V_261 = true ;
V_222 -> V_262 = false ;
if ( V_95 == V_145 )
V_222 -> V_263 = false ;
else if ( V_251 -> V_264 == V_265 )
V_222 -> V_263 = V_1 -> V_263 ;
else
V_222 -> V_263 = V_251 -> V_264 == V_266 ;
if ( F_1 ( V_1 ) && V_63 -> V_65 . V_64 ) {
F_159 ( V_63 -> V_65 . V_64 ,
V_246 ) ;
if ( F_144 ( V_33 ) >= 9 ) {
int V_166 ;
V_166 = F_160 ( V_222 ) ;
if ( V_166 )
return V_166 ;
}
if ( F_161 ( V_33 ) )
F_162 ( V_247 , V_222 ,
V_245 -> V_267 ) ;
else
F_163 ( V_247 , V_222 ,
V_245 -> V_267 ) ;
}
if ( V_246 -> V_73 & V_74 )
return false ;
if ( V_1 -> V_241 . V_268 == V_269 ) {
int V_59 ;
V_59 = F_28 ( V_1 -> V_21 ,
V_1 -> V_22 ,
V_1 -> V_241 . V_270 ) ;
if ( V_59 >= 0 )
V_254 = V_255 = V_59 ;
V_252 = V_253 = V_1 -> V_241 . V_271 ;
}
F_51 ( L_27
L_28 ,
V_253 , V_1 -> V_21 [ V_255 ] ,
V_246 -> V_272 ) ;
V_28 = F_152 ( V_1 , V_222 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_63 -> V_4 . V_273 . V_239 == 0 &&
( V_33 -> V_206 . V_274 . V_28 && V_33 -> V_206 . V_274 . V_28 < V_28 ) ) {
F_51 ( L_29 ,
V_33 -> V_206 . V_274 . V_28 ) ;
V_28 = V_33 -> V_206 . V_274 . V_28 ;
}
V_252 = V_253 ;
V_254 = V_255 ;
}
for (; V_28 >= 6 * 3 ; V_28 -= 2 * 3 ) {
V_67 = F_15 ( V_246 -> V_272 ,
V_28 ) ;
for ( clock = V_254 ; clock <= V_255 ; clock ++ ) {
for ( V_58 = V_252 ;
V_58 <= V_253 ;
V_58 <<= 1 ) {
V_257 = V_1 -> V_21 [ clock ] ;
V_256 = F_17 ( V_257 ,
V_58 ) ;
if ( V_67 <= V_256 ) {
goto V_275;
}
}
}
}
return false ;
V_275:
if ( V_251 -> V_276 == V_277 ) {
V_222 -> V_278 =
V_28 != 18 &&
F_164 ( V_246 ) ==
V_279 ;
} else {
V_222 -> V_278 =
V_251 -> V_276 == V_280 ;
}
V_222 -> V_58 = V_58 ;
V_222 -> V_240 = V_28 ;
V_222 -> V_228 = V_1 -> V_21 [ clock ] ;
F_150 ( V_1 , V_222 -> V_228 ,
& V_236 , & V_237 ) ;
F_51 ( L_30 ,
V_236 , V_237 , V_222 -> V_58 ,
V_222 -> V_228 , V_28 ) ;
F_51 ( L_31 ,
V_67 , V_256 ) ;
F_165 ( V_28 , V_58 ,
V_246 -> V_272 ,
V_222 -> V_228 ,
& V_222 -> V_281 ,
V_258 ) ;
if ( V_63 -> V_65 . V_282 != NULL &&
V_33 -> V_283 . type == V_284 ) {
V_222 -> V_262 = true ;
F_165 ( V_28 , V_58 ,
V_63 -> V_65 . V_282 -> clock ,
V_222 -> V_228 ,
& V_222 -> V_285 ,
V_258 ) ;
}
if ( F_1 ( V_1 ) && F_25 ( V_33 ) ) {
int V_286 ;
switch ( V_222 -> V_228 / 2 ) {
case 108000 :
case 216000 :
V_286 = 8640000 ;
break;
default:
V_286 = 8100000 ;
break;
}
F_166 ( V_222 -> V_4 . V_287 ) -> V_146 . V_288 . V_286 = V_286 ;
}
if ( ! F_158 ( V_33 ) )
F_145 ( V_31 , V_222 ) ;
return true ;
}
void F_167 ( struct V_1 * V_1 ,
int V_56 , T_2 V_58 ,
bool V_289 )
{
V_1 -> V_56 = V_56 ;
V_1 -> V_58 = V_58 ;
V_1 -> V_289 = V_289 ;
}
static void F_168 ( struct V_30 * V_31 ,
struct V_221 * V_222 )
{
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
struct V_247 * V_248 = F_155 ( V_31 -> V_4 . V_248 ) ;
const struct V_61 * V_246 = & V_222 -> V_4 . V_246 ;
F_167 ( V_1 , V_222 -> V_228 ,
V_222 -> V_58 ,
F_169 ( V_222 ,
V_290 ) ) ;
V_1 -> V_92 = F_48 ( V_1 -> V_93 ) & V_96 ;
V_1 -> V_92 |= V_97 | V_98 ;
V_1 -> V_92 |= F_52 ( V_222 -> V_58 ) ;
if ( F_170 ( V_33 ) && V_95 == V_145 ) {
if ( V_246 -> V_73 & V_291 )
V_1 -> V_92 |= V_292 ;
if ( V_246 -> V_73 & V_293 )
V_1 -> V_92 |= V_294 ;
V_1 -> V_92 |= V_295 ;
if ( F_171 ( V_1 -> V_16 ) )
V_1 -> V_92 |= V_296 ;
V_1 -> V_92 |= V_248 -> V_84 << 29 ;
} else if ( F_172 ( V_33 ) && V_95 != V_145 ) {
T_5 V_297 ;
V_1 -> V_92 |= V_295 ;
V_297 = F_48 ( F_173 ( V_248 -> V_84 ) ) ;
if ( F_171 ( V_1 -> V_16 ) )
V_297 |= V_298 ;
else
V_297 &= ~ V_298 ;
F_58 ( F_173 ( V_248 -> V_84 ) , V_297 ) ;
} else {
if ( F_146 ( V_33 ) && V_222 -> V_278 )
V_1 -> V_92 |= V_299 ;
if ( V_246 -> V_73 & V_291 )
V_1 -> V_92 |= V_292 ;
if ( V_246 -> V_73 & V_293 )
V_1 -> V_92 |= V_294 ;
V_1 -> V_92 |= V_300 ;
if ( F_171 ( V_1 -> V_16 ) )
V_1 -> V_92 |= V_296 ;
if ( F_53 ( V_33 ) )
V_1 -> V_92 |= F_54 ( V_248 -> V_84 ) ;
else if ( V_248 -> V_84 == V_100 )
V_1 -> V_92 |= V_101 ;
}
}
static void F_174 ( struct V_1 * V_1 ,
T_5 V_301 ,
T_5 V_302 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_6 V_303 , V_132 ;
F_65 ( & V_33 -> V_83 ) ;
F_175 ( V_33 , V_1 ) ;
V_303 = F_86 ( V_1 ) ;
V_132 = F_85 ( V_1 ) ;
F_51 ( L_32 ,
V_301 , V_302 ,
F_48 ( V_303 ) ,
F_48 ( V_132 ) ) ;
if ( F_176 ( V_33 ,
V_303 , V_301 , V_302 ,
5000 ) )
F_33 ( L_33 ,
F_48 ( V_303 ) ,
F_48 ( V_132 ) ) ;
F_51 ( L_34 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
F_51 ( L_35 ) ;
F_174 ( V_1 , V_304 , V_305 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_51 ( L_36 ) ;
F_174 ( V_1 , V_306 , V_307 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
T_9 V_308 ;
T_10 V_309 ;
F_51 ( L_37 ) ;
V_308 = F_180 () ;
V_309 = F_181 ( V_308 , V_1 -> V_310 ) ;
if ( V_309 < ( T_10 ) V_1 -> V_137 )
F_182 ( V_311 ,
V_1 -> V_137 - V_309 ) ;
F_174 ( V_1 , V_312 , V_313 ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
F_182 ( V_1 -> V_314 ,
V_1 -> V_315 ) ;
}
static void F_184 ( struct V_1 * V_1 )
{
F_182 ( V_1 -> V_316 ,
V_1 -> V_317 ) ;
}
static T_5 F_185 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_318 ;
F_65 ( & V_33 -> V_83 ) ;
V_318 = F_48 ( F_85 ( V_1 ) ) ;
if ( F_22 ( ! F_158 ( V_33 ) &&
( V_318 & V_319 ) != V_135 ) ) {
V_318 &= ~ V_319 ;
V_318 |= V_135 ;
}
return V_318 ;
}
static bool F_113 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_320 ;
T_6 V_303 , V_132 ;
bool V_321 = ! V_1 -> V_322 ;
F_65 ( & V_33 -> V_83 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_186 ( & V_1 -> V_323 ) ;
V_1 -> V_322 = true ;
if ( F_92 ( V_1 ) )
return V_321 ;
F_40 ( V_33 , V_1 -> V_82 ) ;
F_51 ( L_38 ,
F_50 ( V_3 -> V_95 ) ) ;
if ( ! F_91 ( V_1 ) )
F_179 ( V_1 ) ;
V_320 = F_185 ( V_1 ) ;
V_320 |= V_113 ;
V_303 = F_86 ( V_1 ) ;
V_132 = F_85 ( V_1 ) ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
F_51 ( L_39 ,
F_48 ( V_303 ) , F_48 ( V_132 ) ) ;
if ( ! F_91 ( V_1 ) ) {
F_51 ( L_40 ,
F_50 ( V_3 -> V_95 ) ) ;
F_90 ( V_1 -> V_324 ) ;
}
return V_321 ;
}
void F_187 ( struct V_1 * V_1 )
{
bool V_169 ;
if ( ! F_1 ( V_1 ) )
return;
F_39 ( V_1 ) ;
V_169 = F_113 ( V_1 ) ;
F_42 ( V_1 ) ;
F_188 ( ! V_169 , L_41 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
T_5 V_320 ;
T_6 V_303 , V_132 ;
F_65 ( & V_33 -> V_83 ) ;
F_22 ( V_1 -> V_322 ) ;
if ( ! F_92 ( V_1 ) )
return;
F_51 ( L_42 ,
F_50 ( V_3 -> V_95 ) ) ;
V_320 = F_185 ( V_1 ) ;
V_320 &= ~ V_113 ;
V_132 = F_85 ( V_1 ) ;
V_303 = F_86 ( V_1 ) ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
F_51 ( L_39 ,
F_48 ( V_303 ) , F_48 ( V_132 ) ) ;
if ( ( V_320 & V_325 ) == 0 )
V_1 -> V_310 = F_180 () ;
F_44 ( V_33 , V_1 -> V_82 ) ;
}
static void F_190 ( struct V_326 * V_327 )
{
struct V_1 * V_1 = F_88 ( F_191 ( V_327 ) ,
struct V_1 , V_323 ) ;
F_39 ( V_1 ) ;
if ( ! V_1 -> V_322 )
F_189 ( V_1 ) ;
F_42 ( V_1 ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
unsigned long V_328 ;
V_328 = F_193 ( V_1 -> V_137 * 5 ) ;
F_194 ( & V_1 -> V_323 , V_328 ) ;
}
static void F_117 ( struct V_1 * V_1 , bool V_329 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
F_65 ( & V_33 -> V_83 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_188 ( ! V_1 -> V_322 , L_43 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) ;
V_1 -> V_322 = false ;
if ( V_329 )
F_189 ( V_1 ) ;
else
F_192 ( V_1 ) ;
}
static void F_195 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_320 ;
T_6 V_132 ;
F_65 ( & V_33 -> V_83 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_51 ( L_44 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) ;
if ( F_8 ( F_91 ( V_1 ) ,
L_45 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) )
return;
F_179 ( V_1 ) ;
V_132 = F_85 ( V_1 ) ;
V_320 = F_185 ( V_1 ) ;
if ( F_196 ( V_33 ) ) {
V_320 &= ~ V_330 ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
}
V_320 |= V_325 ;
if ( ! F_196 ( V_33 ) )
V_320 |= V_330 ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
F_177 ( V_1 ) ;
V_1 -> V_314 = V_311 ;
if ( F_196 ( V_33 ) ) {
V_320 |= V_330 ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
}
}
void F_197 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_39 ( V_1 ) ;
F_195 ( V_1 ) ;
F_42 ( V_1 ) ;
}
static void F_198 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_320 ;
T_6 V_132 ;
F_65 ( & V_33 -> V_83 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_51 ( L_46 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) ;
F_8 ( ! V_1 -> V_322 , L_47 ,
F_50 ( F_2 ( V_1 ) -> V_95 ) ) ;
V_320 = F_185 ( V_1 ) ;
V_320 &= ~ ( V_325 | V_330 | V_113 |
V_331 ) ;
V_132 = F_85 ( V_1 ) ;
V_1 -> V_322 = false ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
V_1 -> V_310 = F_180 () ;
F_178 ( V_1 ) ;
F_44 ( V_33 , V_1 -> V_82 ) ;
}
void F_199 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_39 ( V_1 ) ;
F_198 ( V_1 ) ;
F_42 ( V_1 ) ;
}
static void F_200 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_320 ;
T_6 V_132 ;
F_183 ( V_1 ) ;
F_39 ( V_1 ) ;
V_320 = F_185 ( V_1 ) ;
V_320 |= V_331 ;
V_132 = F_85 ( V_1 ) ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
F_42 ( V_1 ) ;
}
void F_201 ( const struct V_221 * V_332 ,
const struct V_244 * V_245 )
{
struct V_1 * V_1 = F_5 ( V_245 -> V_333 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_51 ( L_48 ) ;
F_202 ( V_332 , V_245 ) ;
F_200 ( V_1 ) ;
}
static void F_203 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_320 ;
T_6 V_132 ;
if ( ! F_1 ( V_1 ) )
return;
F_39 ( V_1 ) ;
V_320 = F_185 ( V_1 ) ;
V_320 &= ~ V_331 ;
V_132 = F_85 ( V_1 ) ;
F_58 ( V_132 , V_320 ) ;
F_59 ( V_132 ) ;
F_42 ( V_1 ) ;
V_1 -> V_316 = V_311 ;
F_184 ( V_1 ) ;
}
void F_204 ( const struct V_244 * V_334 )
{
struct V_1 * V_1 = F_5 ( V_334 -> V_333 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_51 ( L_48 ) ;
F_203 ( V_1 ) ;
F_205 ( V_334 ) ;
}
static void F_206 ( struct V_63 * V_9 ,
bool V_335 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_336 ;
F_39 ( V_1 ) ;
V_336 = F_185 ( V_1 ) & V_331 ;
F_42 ( V_1 ) ;
if ( V_336 == V_335 )
return;
F_51 ( L_49 ,
V_335 ? L_50 : L_51 ) ;
if ( V_335 )
F_200 ( V_1 ) ;
else
F_203 ( V_1 ) ;
}
static void F_207 ( struct V_1 * V_1 , bool V_287 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
bool V_337 = F_48 ( V_1 -> V_93 ) & V_94 ;
F_188 ( V_337 != V_287 ,
L_52 ,
F_50 ( V_40 -> V_95 ) ,
F_208 ( V_287 ) , F_208 ( V_337 ) ) ;
}
static void F_209 ( struct V_32 * V_33 , bool V_287 )
{
bool V_337 = F_48 ( V_338 ) & V_339 ;
F_188 ( V_337 != V_287 ,
L_53 ,
F_208 ( V_287 ) , F_208 ( V_337 ) ) ;
}
static void F_210 ( struct V_1 * V_1 ,
struct V_221 * V_222 )
{
struct V_247 * V_248 = F_155 ( V_222 -> V_4 . V_248 ) ;
struct V_32 * V_33 = F_19 ( V_248 -> V_4 . V_7 ) ;
F_211 ( V_33 , V_248 -> V_84 ) ;
F_212 ( V_1 ) ;
F_213 ( V_33 ) ;
F_51 ( L_54 ,
V_222 -> V_228 ) ;
V_1 -> V_92 &= ~ V_340 ;
if ( V_222 -> V_228 == 162000 )
V_1 -> V_92 |= V_341 ;
else
V_1 -> V_92 |= V_342 ;
F_58 ( V_338 , V_1 -> V_92 ) ;
F_59 ( V_338 ) ;
F_214 ( 500 ) ;
if ( F_196 ( V_33 ) )
F_215 ( V_33 , ! V_248 -> V_84 ) ;
V_1 -> V_92 |= V_339 ;
F_58 ( V_338 , V_1 -> V_92 ) ;
F_59 ( V_338 ) ;
F_214 ( 200 ) ;
}
static void F_216 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_247 * V_248 = F_155 ( V_3 -> V_4 . V_4 . V_248 ) ;
struct V_32 * V_33 = F_19 ( V_248 -> V_4 . V_7 ) ;
F_211 ( V_33 , V_248 -> V_84 ) ;
F_212 ( V_1 ) ;
F_217 ( V_33 ) ;
F_51 ( L_55 ) ;
V_1 -> V_92 &= ~ V_339 ;
F_58 ( V_338 , V_1 -> V_92 ) ;
F_59 ( V_338 ) ;
F_214 ( 200 ) ;
}
void F_218 ( struct V_1 * V_1 , int V_62 )
{
int V_166 , V_14 ;
if ( V_1 -> V_16 [ V_343 ] < 0x11 )
return;
if ( V_62 != V_344 ) {
V_166 = F_219 ( & V_1 -> V_184 , V_345 ,
V_346 ) ;
} else {
struct V_347 * V_348 = F_220 ( V_1 ) ;
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
V_166 = F_219 ( & V_1 -> V_184 , V_345 ,
V_349 ) ;
if ( V_166 == 1 )
break;
F_90 ( 1 ) ;
}
if ( V_166 == 1 && V_348 -> V_350 )
F_221 ( V_348 ) ;
}
if ( V_166 != 1 )
F_51 ( L_56 ,
V_62 == V_344 ? L_50 : L_51 ) ;
}
static bool F_222 ( struct V_30 * V_31 ,
enum V_84 * V_84 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_351 ;
bool V_166 ;
if ( ! F_223 ( V_33 ,
V_31 -> V_352 ) )
return false ;
V_166 = false ;
V_351 = F_48 ( V_1 -> V_93 ) ;
if ( ! ( V_351 & V_94 ) )
goto V_173;
if ( F_170 ( V_33 ) && V_95 == V_145 ) {
* V_84 = F_224 ( V_351 ) ;
} else if ( F_172 ( V_33 ) && V_95 != V_145 ) {
enum V_84 V_353 ;
F_225 (dev_priv, p) {
T_5 V_297 = F_48 ( F_173 ( V_353 ) ) ;
if ( F_226 ( V_297 ) == V_95 ) {
* V_84 = V_353 ;
V_166 = true ;
goto V_173;
}
}
F_51 ( L_57 ,
F_227 ( V_1 -> V_93 ) ) ;
} else if ( F_53 ( V_33 ) ) {
* V_84 = F_228 ( V_351 ) ;
} else {
* V_84 = F_229 ( V_351 ) ;
}
V_166 = true ;
V_173:
F_44 ( V_33 , V_31 -> V_352 ) ;
return V_166 ;
}
static void F_230 ( struct V_30 * V_31 ,
struct V_221 * V_222 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
T_5 V_351 , V_73 = 0 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
struct V_247 * V_248 = F_155 ( V_31 -> V_4 . V_248 ) ;
V_351 = F_48 ( V_1 -> V_93 ) ;
V_222 -> V_263 = V_351 & V_354 && V_95 != V_145 ;
if ( F_172 ( V_33 ) && V_95 != V_145 ) {
T_5 V_297 = F_48 ( F_173 ( V_248 -> V_84 ) ) ;
if ( V_297 & V_355 )
V_73 |= V_291 ;
else
V_73 |= V_356 ;
if ( V_297 & V_357 )
V_73 |= V_293 ;
else
V_73 |= V_358 ;
} else {
if ( V_351 & V_292 )
V_73 |= V_291 ;
else
V_73 |= V_356 ;
if ( V_351 & V_294 )
V_73 |= V_293 ;
else
V_73 |= V_358 ;
}
V_222 -> V_4 . V_246 . V_73 |= V_73 ;
if ( F_146 ( V_33 ) && V_351 & V_299 )
V_222 -> V_278 = true ;
V_222 -> V_58 =
( ( V_351 & V_359 ) >> V_360 ) + 1 ;
F_231 ( V_248 , V_222 ) ;
if ( V_95 == V_145 ) {
if ( ( F_48 ( V_338 ) & V_340 ) == V_341 )
V_222 -> V_228 = 162000 ;
else
V_222 -> V_228 = 270000 ;
}
V_222 -> V_4 . V_246 . V_272 =
F_232 ( V_222 -> V_228 ,
& V_222 -> V_281 ) ;
if ( F_1 ( V_1 ) && V_33 -> V_206 . V_274 . V_28 &&
V_222 -> V_240 > V_33 -> V_206 . V_274 . V_28 ) {
F_51 ( L_58 ,
V_222 -> V_240 , V_33 -> V_206 . V_274 . V_28 ) ;
V_33 -> V_206 . V_274 . V_28 = V_222 -> V_240 ;
}
}
static void F_233 ( struct V_30 * V_31 ,
struct V_221 * V_361 ,
struct V_244 * V_334 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
if ( V_361 -> V_263 )
F_234 ( V_31 ) ;
if ( F_235 ( V_33 ) && ! F_158 ( V_33 ) )
F_236 ( V_1 ) ;
F_187 ( V_1 ) ;
F_204 ( V_334 ) ;
F_218 ( V_1 , V_362 ) ;
F_199 ( V_1 ) ;
if ( F_144 ( V_33 ) < 5 )
F_237 ( V_1 ) ;
}
static void F_238 ( struct V_30 * V_31 ,
struct V_221 * V_361 ,
struct V_244 * V_334 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
F_237 ( V_1 ) ;
if ( V_95 == V_145 )
F_216 ( V_1 ) ;
}
static void F_239 ( struct V_30 * V_31 ,
struct V_221 * V_361 ,
struct V_244 * V_334 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
F_237 ( V_1 ) ;
}
static void F_240 ( struct V_30 * V_31 ,
struct V_221 * V_361 ,
struct V_244 * V_334 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_237 ( V_1 ) ;
F_41 ( & V_33 -> V_363 ) ;
F_241 ( V_31 , true ) ;
F_43 ( & V_33 -> V_363 ) ;
}
static void
F_242 ( struct V_1 * V_1 ,
T_3 * V_92 ,
T_2 V_364 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
if ( V_364 & V_365 )
F_51 ( L_59 ,
V_364 & V_365 ) ;
if ( F_158 ( V_33 ) ) {
T_3 V_366 = F_48 ( F_243 ( V_95 ) ) ;
if ( V_364 & V_367 )
V_366 |= V_368 ;
else
V_366 &= ~ V_368 ;
V_366 &= ~ V_369 ;
switch ( V_364 & V_365 ) {
case V_370 :
V_366 |= V_371 ;
break;
case V_372 :
V_366 |= V_373 ;
break;
case V_374 :
V_366 |= V_375 ;
break;
case V_376 :
V_366 |= V_377 ;
break;
}
F_58 ( F_243 ( V_95 ) , V_366 ) ;
} else if ( ( F_170 ( V_33 ) && V_95 == V_145 ) ||
( F_172 ( V_33 ) && V_95 != V_145 ) ) {
* V_92 &= ~ V_378 ;
switch ( V_364 & V_365 ) {
case V_370 :
* V_92 |= V_295 ;
break;
case V_372 :
* V_92 |= V_379 ;
break;
case V_374 :
* V_92 |= V_380 ;
break;
case V_376 :
F_51 ( L_60 ) ;
* V_92 |= V_380 ;
break;
}
} else {
if ( F_53 ( V_33 ) )
* V_92 &= ~ V_381 ;
else
* V_92 &= ~ V_382 ;
switch ( V_364 & V_365 ) {
case V_370 :
* V_92 |= V_300 ;
break;
case V_372 :
* V_92 |= V_99 ;
break;
case V_374 :
* V_92 |= V_383 ;
break;
case V_376 :
if ( F_53 ( V_33 ) ) {
* V_92 |= V_384 ;
} else {
F_51 ( L_60 ) ;
* V_92 |= V_383 ;
}
break;
}
}
}
static void F_244 ( struct V_1 * V_1 ,
struct V_221 * V_361 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_245 ( V_1 , V_372 ) ;
V_1 -> V_92 |= V_94 ;
if ( V_361 -> V_263 )
V_1 -> V_92 |= V_354 ;
F_58 ( V_1 -> V_93 , V_1 -> V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
}
static void F_246 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_247 * V_248 = F_155 ( V_31 -> V_4 . V_248 ) ;
T_3 V_385 = F_48 ( V_1 -> V_93 ) ;
enum V_84 V_84 = V_248 -> V_84 ;
if ( F_22 ( V_385 & V_94 ) )
return;
F_39 ( V_1 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
F_247 ( V_1 ) ;
F_244 ( V_1 , V_222 ) ;
F_113 ( V_1 ) ;
F_195 ( V_1 ) ;
F_117 ( V_1 , true ) ;
F_42 ( V_1 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
unsigned int V_386 = 0x0 ;
if ( F_53 ( V_33 ) )
V_386 = F_248 ( V_222 -> V_58 ) ;
F_249 ( V_33 , F_2 ( V_1 ) ,
V_386 ) ;
}
F_218 ( V_1 , V_344 ) ;
F_250 ( V_1 ) ;
F_251 ( V_1 ) ;
if ( V_222 -> V_263 ) {
F_252 ( L_61 ,
F_49 ( V_84 ) ) ;
F_253 ( V_31 , V_222 , V_245 ) ;
}
}
static void F_254 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_246 ( V_31 , V_222 , V_245 ) ;
F_201 ( V_222 , V_245 ) ;
}
static void F_255 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
F_201 ( V_222 , V_245 ) ;
F_256 ( V_1 ) ;
}
static void F_257 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
struct V_1 * V_1 = F_5 ( & V_31 -> V_4 ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
F_168 ( V_31 , V_222 ) ;
if ( V_95 == V_145 )
F_210 ( V_1 , V_222 ) ;
}
static void F_258 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_84 V_84 = V_1 -> V_85 ;
T_6 V_387 = F_76 ( V_84 ) ;
F_22 ( V_1 -> V_109 != V_110 ) ;
if ( F_22 ( V_84 != V_107 && V_84 != V_100 ) )
return;
F_189 ( V_1 ) ;
F_51 ( L_62 ,
F_49 ( V_84 ) , F_50 ( V_3 -> V_95 ) ) ;
F_58 ( V_387 , 0 ) ;
F_59 ( V_387 ) ;
V_1 -> V_85 = V_110 ;
}
static void F_66 ( struct V_6 * V_7 ,
enum V_84 V_84 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_30 * V_31 ;
F_65 ( & V_33 -> V_83 ) ;
F_62 (dev, encoder) {
struct V_1 * V_1 ;
enum V_95 V_95 ;
if ( V_31 -> type != V_108 &&
V_31 -> type != V_5 )
continue;
V_1 = F_5 ( & V_31 -> V_4 ) ;
V_95 = F_2 ( V_1 ) -> V_95 ;
F_8 ( V_1 -> V_109 == V_84 ,
L_63 ,
F_49 ( V_84 ) , F_50 ( V_95 ) ) ;
if ( V_1 -> V_85 != V_84 )
continue;
F_51 ( L_64 ,
F_49 ( V_84 ) , F_50 ( V_95 ) ) ;
F_258 ( V_1 ) ;
}
}
static void F_247 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_31 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_247 * V_248 = F_155 ( V_31 -> V_4 . V_248 ) ;
F_65 ( & V_33 -> V_83 ) ;
F_22 ( V_1 -> V_109 != V_110 ) ;
if ( V_1 -> V_85 != V_110 &&
V_1 -> V_85 != V_248 -> V_84 ) {
F_258 ( V_1 ) ;
}
F_66 ( V_7 , V_248 -> V_84 ) ;
V_1 -> V_109 = V_248 -> V_84 ;
if ( ! F_1 ( V_1 ) )
return;
V_1 -> V_85 = V_248 -> V_84 ;
F_51 ( L_65 ,
F_49 ( V_1 -> V_85 ) , F_50 ( V_3 -> V_95 ) ) ;
F_67 ( V_7 , V_1 ) ;
F_68 ( V_7 , V_1 , true ) ;
}
static void F_259 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_260 ( V_31 ) ;
F_246 ( V_31 , V_222 , V_245 ) ;
}
static void F_261 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_168 ( V_31 , V_222 ) ;
F_262 ( V_31 ) ;
}
static void F_263 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_264 ( V_31 ) ;
F_246 ( V_31 , V_222 , V_245 ) ;
F_265 ( V_31 ) ;
}
static void F_266 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_168 ( V_31 , V_222 ) ;
F_267 ( V_31 ) ;
}
static void F_268 ( struct V_30 * V_31 ,
struct V_221 * V_222 ,
struct V_244 * V_245 )
{
F_269 ( V_31 ) ;
}
bool
F_270 ( struct V_1 * V_1 , T_2 V_388 [ V_389 ] )
{
return F_271 ( & V_1 -> V_184 , V_390 , V_388 ,
V_389 ) == V_389 ;
}
static bool F_272 ( struct V_1 * V_1 )
{
T_2 V_391 = 0 ;
if ( F_273 ( & V_1 -> V_184 , V_392 , & V_391 ) != 1 )
return false ;
return V_391 & V_393 ;
}
static bool F_274 ( struct V_1 * V_1 )
{
T_2 V_394 = 0 ;
if ( F_273 ( & V_1 -> V_184 , V_395 ,
& V_394 ) != 1 )
return false ;
return V_394 & V_396 ;
}
static bool F_275 ( struct V_1 * V_1 )
{
T_2 V_397 = 0 ;
if ( F_273 ( & V_1 -> V_184 , V_398 ,
& V_397 ) != 1 )
return false ;
return V_397 & V_399 ;
}
T_2
F_276 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
if ( F_23 ( V_33 ) )
return V_400 ;
else if ( F_144 ( V_33 ) >= 9 ) {
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
return F_277 ( V_31 ) ;
} else if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
return V_400 ;
else if ( F_170 ( V_33 ) && V_95 == V_145 )
return V_401 ;
else if ( F_172 ( V_33 ) && V_95 != V_145 )
return V_400 ;
else
return V_401 ;
}
T_2
F_278 ( struct V_1 * V_1 , T_2 V_402 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
if ( F_144 ( V_33 ) >= 9 ) {
switch ( V_402 & V_403 ) {
case V_404 :
return V_405 ;
case V_406 :
return V_407 ;
case V_401 :
return V_408 ;
case V_400 :
return V_409 ;
default:
return V_409 ;
}
} else if ( F_142 ( V_33 ) || F_107 ( V_33 ) ) {
switch ( V_402 & V_403 ) {
case V_404 :
return V_405 ;
case V_406 :
return V_407 ;
case V_401 :
return V_408 ;
case V_400 :
default:
return V_409 ;
}
} else if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
switch ( V_402 & V_403 ) {
case V_404 :
return V_405 ;
case V_406 :
return V_407 ;
case V_401 :
return V_408 ;
case V_400 :
default:
return V_409 ;
}
} else if ( F_170 ( V_33 ) && V_95 == V_145 ) {
switch ( V_402 & V_403 ) {
case V_404 :
return V_407 ;
case V_406 :
case V_401 :
return V_408 ;
default:
return V_409 ;
}
} else {
switch ( V_402 & V_403 ) {
case V_404 :
return V_407 ;
case V_406 :
return V_407 ;
case V_401 :
return V_408 ;
case V_400 :
default:
return V_409 ;
}
}
}
static T_3 F_279 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_410 , V_411 ,
V_412 ;
T_2 V_413 = V_1 -> V_413 [ 0 ] ;
switch ( V_413 & V_414 ) {
case V_409 :
V_411 = 0x0004000 ;
switch ( V_413 & V_403 ) {
case V_404 :
V_410 = 0x2B405555 ;
V_412 = 0x552AB83A ;
break;
case V_406 :
V_410 = 0x2B404040 ;
V_412 = 0x5548B83A ;
break;
case V_401 :
V_410 = 0x2B245555 ;
V_412 = 0x5560B83A ;
break;
case V_400 :
V_410 = 0x2B405555 ;
V_412 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_408 :
V_411 = 0x0002000 ;
switch ( V_413 & V_403 ) {
case V_404 :
V_410 = 0x2B404040 ;
V_412 = 0x5552B83A ;
break;
case V_406 :
V_410 = 0x2B404848 ;
V_412 = 0x5580B83A ;
break;
case V_401 :
V_410 = 0x2B404040 ;
V_412 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_407 :
V_411 = 0x0000000 ;
switch ( V_413 & V_403 ) {
case V_404 :
V_410 = 0x2B305555 ;
V_412 = 0x5570B83A ;
break;
case V_406 :
V_410 = 0x2B2B4040 ;
V_412 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_405 :
V_411 = 0x0006000 ;
switch ( V_413 & V_403 ) {
case V_404 :
V_410 = 0x1B405555 ;
V_412 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_280 ( V_31 , V_410 , V_411 ,
V_412 , 0 ) ;
return 0 ;
}
static T_3 F_281 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_415 , V_416 ;
bool V_417 = false ;
T_2 V_413 = V_1 -> V_413 [ 0 ] ;
switch ( V_413 & V_414 ) {
case V_409 :
switch ( V_413 & V_403 ) {
case V_404 :
V_415 = 128 ;
V_416 = 52 ;
break;
case V_406 :
V_415 = 128 ;
V_416 = 77 ;
break;
case V_401 :
V_415 = 128 ;
V_416 = 102 ;
break;
case V_400 :
V_415 = 128 ;
V_416 = 154 ;
V_417 = true ;
break;
default:
return 0 ;
}
break;
case V_408 :
switch ( V_413 & V_403 ) {
case V_404 :
V_415 = 85 ;
V_416 = 78 ;
break;
case V_406 :
V_415 = 85 ;
V_416 = 116 ;
break;
case V_401 :
V_415 = 85 ;
V_416 = 154 ;
break;
default:
return 0 ;
}
break;
case V_407 :
switch ( V_413 & V_403 ) {
case V_404 :
V_415 = 64 ;
V_416 = 104 ;
break;
case V_406 :
V_415 = 64 ;
V_416 = 154 ;
break;
default:
return 0 ;
}
break;
case V_405 :
switch ( V_413 & V_403 ) {
case V_404 :
V_415 = 43 ;
V_416 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_282 ( V_31 , V_415 ,
V_416 , V_417 ) ;
return 0 ;
}
static T_3
F_283 ( T_2 V_413 )
{
T_3 V_418 = 0 ;
switch ( V_413 & V_403 ) {
case V_404 :
default:
V_418 |= V_97 ;
break;
case V_406 :
V_418 |= V_419 ;
break;
case V_401 :
V_418 |= V_420 ;
break;
case V_400 :
V_418 |= V_421 ;
break;
}
switch ( V_413 & V_414 ) {
case V_409 :
default:
V_418 |= V_98 ;
break;
case V_408 :
V_418 |= V_422 ;
break;
case V_407 :
V_418 |= V_423 ;
break;
case V_405 :
V_418 |= V_424 ;
break;
}
return V_418 ;
}
static T_3
F_284 ( T_2 V_413 )
{
int V_418 = V_413 & ( V_403 |
V_414 ) ;
switch ( V_418 ) {
case V_404 | V_409 :
case V_406 | V_409 :
return V_425 ;
case V_404 | V_408 :
return V_426 ;
case V_404 | V_407 :
case V_406 | V_407 :
return V_427 ;
case V_406 | V_408 :
case V_401 | V_408 :
return V_428 ;
case V_401 | V_409 :
case V_400 | V_409 :
return V_429 ;
default:
F_51 ( L_66
L_67 , V_418 ) ;
return V_425 ;
}
}
static T_3
F_285 ( T_2 V_413 )
{
int V_418 = V_413 & ( V_403 |
V_414 ) ;
switch ( V_418 ) {
case V_404 | V_409 :
return V_430 ;
case V_404 | V_408 :
return V_431 ;
case V_404 | V_407 :
return V_432 ;
case V_406 | V_409 :
return V_433 ;
case V_406 | V_408 :
return V_434 ;
case V_401 | V_409 :
return V_435 ;
case V_401 | V_408 :
return V_436 ;
default:
F_51 ( L_66
L_67 , V_418 ) ;
return V_437 ;
}
}
void
F_286 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_3 V_418 , V_301 = 0 ;
T_2 V_413 = V_1 -> V_413 [ 0 ] ;
if ( F_158 ( V_33 ) ) {
V_418 = F_287 ( V_1 ) ;
if ( F_23 ( V_33 ) || F_288 ( V_33 ) )
V_418 = 0 ;
else
V_301 = V_438 ;
} else if ( F_53 ( V_33 ) ) {
V_418 = F_281 ( V_1 ) ;
} else if ( F_80 ( V_33 ) ) {
V_418 = F_279 ( V_1 ) ;
} else if ( F_170 ( V_33 ) && V_95 == V_145 ) {
V_418 = F_285 ( V_413 ) ;
V_301 = V_439 ;
} else if ( F_106 ( V_33 ) && V_95 == V_145 ) {
V_418 = F_284 ( V_413 ) ;
V_301 = V_440 ;
} else {
V_418 = F_283 ( V_413 ) ;
V_301 = V_441 | V_442 ;
}
if ( V_301 )
F_51 ( L_68 , V_418 ) ;
F_51 ( L_69 ,
V_413 & V_403 ) ;
F_51 ( L_70 ,
( V_413 & V_414 ) >>
V_443 ) ;
V_1 -> V_92 = ( V_1 -> V_92 & ~ V_301 ) | V_418 ;
F_58 ( V_1 -> V_93 , V_1 -> V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
}
void
F_245 ( struct V_1 * V_1 ,
T_2 V_364 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_32 * V_33 =
F_19 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_242 ( V_1 , & V_1 -> V_92 , V_364 ) ;
F_58 ( V_1 -> V_93 , V_1 -> V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
}
void F_289 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
T_3 V_444 ;
if ( ! F_158 ( V_33 ) )
return;
V_444 = F_48 ( F_243 ( V_95 ) ) ;
V_444 &= ~ V_369 ;
V_444 |= V_445 ;
F_58 ( F_243 ( V_95 ) , V_444 ) ;
if ( V_95 == V_145 )
return;
if ( F_176 ( V_33 , F_290 ( V_95 ) ,
V_446 ,
V_446 ,
1 ) )
F_33 ( L_71 ) ;
}
static void
F_237 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_247 * V_248 = F_155 ( V_3 -> V_4 . V_4 . V_248 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_3 V_92 = V_1 -> V_92 ;
if ( F_22 ( F_158 ( V_33 ) ) )
return;
if ( F_22 ( ( F_48 ( V_1 -> V_93 ) & V_94 ) == 0 ) )
return;
F_51 ( L_48 ) ;
if ( ( F_170 ( V_33 ) && V_95 == V_145 ) ||
( F_172 ( V_33 ) && V_95 != V_145 ) ) {
V_92 &= ~ V_378 ;
V_92 |= V_447 ;
} else {
if ( F_53 ( V_33 ) )
V_92 &= ~ V_381 ;
else
V_92 &= ~ V_382 ;
V_92 |= V_448 ;
}
F_58 ( V_1 -> V_93 , V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
V_92 &= ~ ( V_94 | V_354 ) ;
F_58 ( V_1 -> V_93 , V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
if ( F_291 ( V_33 ) && V_248 -> V_84 == V_100 && V_95 != V_145 ) {
F_292 ( V_33 , V_107 , false ) ;
F_293 ( V_33 , V_107 , false ) ;
V_92 &= ~ ( V_101 | V_382 ) ;
V_92 |= V_94 | V_99 ;
F_58 ( V_1 -> V_93 , V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
V_92 &= ~ V_94 ;
F_58 ( V_1 -> V_93 , V_92 ) ;
F_59 ( V_1 -> V_93 ) ;
F_215 ( V_33 , V_107 ) ;
F_292 ( V_33 , V_107 , true ) ;
F_293 ( V_33 , V_107 , true ) ;
}
F_90 ( V_1 -> V_449 ) ;
V_1 -> V_92 = V_92 ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
F_39 ( V_1 ) ;
V_1 -> V_109 = V_110 ;
F_42 ( V_1 ) ;
}
}
bool
F_294 ( struct V_1 * V_1 )
{
if ( F_271 ( & V_1 -> V_184 , 0x000 , V_1 -> V_16 ,
sizeof( V_1 -> V_16 ) ) < 0 )
return false ;
F_51 ( L_72 , ( int ) sizeof( V_1 -> V_16 ) , V_1 -> V_16 ) ;
return V_1 -> V_16 [ V_343 ] != 0 ;
}
static bool
F_295 ( struct V_1 * V_1 )
{
struct V_32 * V_33 =
F_19 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_22 ( V_1 -> V_16 [ V_343 ] != 0 ) ;
if ( ! F_294 ( V_1 ) )
return false ;
F_296 ( & V_1 -> V_184 , & V_1 -> V_259 ,
F_297 ( V_1 -> V_16 ) ) ;
if ( V_1 -> V_16 [ V_343 ] >= 0x11 )
V_33 -> V_450 = V_1 -> V_16 [ V_451 ] &
V_452 ;
F_271 ( & V_1 -> V_184 , V_453 ,
V_1 -> V_454 ,
sizeof( V_1 -> V_454 ) ) ;
if ( V_1 -> V_454 [ 0 ] & V_455 ) {
V_33 -> V_456 . V_457 = true ;
F_51 ( L_73 ) ;
}
if ( F_144 ( V_33 ) >= 9 &&
( V_1 -> V_454 [ 0 ] & V_458 ) ) {
T_2 V_459 ;
V_33 -> V_456 . V_457 = true ;
if ( F_273 ( & V_1 -> V_184 ,
V_460 ,
& V_459 ) != 1 )
V_459 = 0 ;
V_33 -> V_456 . V_461 = V_459 ? true : false ;
V_33 -> V_456 . V_462 = V_33 -> V_456 . V_461 ;
F_51 ( L_74 ,
V_33 -> V_456 . V_462 ? L_75 : L_76 ) ;
if ( V_33 -> V_456 . V_462 ) {
V_33 -> V_456 . V_463 =
F_272 ( V_1 ) ;
V_33 -> V_456 . V_464 =
F_274 ( V_1 ) ;
V_33 -> V_456 . V_465 =
F_275 ( V_1 ) ;
}
}
if ( ( V_1 -> V_16 [ V_466 ] & V_467 ) &&
F_271 ( & V_1 -> V_184 , V_468 ,
V_1 -> V_469 , sizeof( V_1 -> V_469 ) ) ==
sizeof( V_1 -> V_469 ) )
F_51 ( L_77 , ( int ) sizeof( V_1 -> V_469 ) ,
V_1 -> V_469 ) ;
if ( V_1 -> V_469 [ 0 ] >= 0x03 ) {
T_11 V_18 [ V_50 ] ;
int V_14 ;
F_271 ( & V_1 -> V_184 , V_470 ,
V_18 , sizeof( V_18 ) ) ;
for ( V_14 = 0 ; V_14 < F_24 ( V_18 ) ; V_14 ++ ) {
int V_444 = F_298 ( V_18 [ V_14 ] ) ;
if ( V_444 == 0 )
break;
V_1 -> V_18 [ V_14 ] = ( V_444 * 200 ) / 10 ;
}
V_1 -> V_20 = V_14 ;
}
if ( V_1 -> V_20 )
V_1 -> V_238 = true ;
else
F_9 ( V_1 ) ;
F_29 ( V_1 ) ;
return true ;
}
static bool
F_299 ( struct V_1 * V_1 )
{
T_1 V_471 ;
if ( ! F_294 ( V_1 ) )
return false ;
if ( ! F_1 ( V_1 ) ) {
F_9 ( V_1 ) ;
F_29 ( V_1 ) ;
}
if ( F_273 ( & V_1 -> V_184 , V_472 , & V_471 ) <= 0 )
return false ;
V_1 -> V_471 = F_300 ( V_471 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_471 )
return false ;
if ( ! F_297 ( V_1 -> V_16 ) )
return true ;
if ( V_1 -> V_16 [ V_343 ] == 0x10 )
return true ;
if ( F_271 ( & V_1 -> V_184 , V_473 ,
V_1 -> V_37 ,
V_474 ) < 0 )
return false ;
return true ;
}
static bool
F_301 ( struct V_1 * V_1 )
{
T_1 V_475 ;
if ( ! V_476 . V_477 )
return false ;
if ( ! V_1 -> V_478 )
return false ;
if ( V_1 -> V_16 [ V_343 ] < 0x12 )
return false ;
if ( F_273 ( & V_1 -> V_184 , V_479 , & V_475 ) != 1 )
return false ;
return V_475 & V_480 ;
}
static void
F_302 ( struct V_1 * V_1 )
{
if ( ! V_476 . V_477 )
return;
if ( ! V_1 -> V_478 )
return;
V_1 -> V_481 = F_301 ( V_1 ) ;
if ( V_1 -> V_481 )
F_51 ( L_78 ) ;
else
F_51 ( L_79 ) ;
F_303 ( & V_1 -> V_482 ,
V_1 -> V_481 ) ;
}
static int F_304 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_247 * V_247 = F_155 ( V_40 -> V_4 . V_4 . V_248 ) ;
T_1 V_483 ;
int V_166 = 0 ;
int V_225 = 0 ;
int V_484 = 10 ;
if ( F_273 ( & V_1 -> V_184 , V_485 , & V_483 ) < 0 ) {
F_51 ( L_80 ) ;
V_166 = - V_179 ;
goto V_173;
}
if ( F_219 ( & V_1 -> V_184 , V_485 ,
V_483 & ~ V_486 ) < 0 ) {
F_51 ( L_80 ) ;
V_166 = - V_179 ;
goto V_173;
}
do {
F_305 ( V_33 , V_247 -> V_84 ) ;
if ( F_273 ( & V_1 -> V_184 ,
V_487 , & V_483 ) < 0 ) {
V_166 = - V_179 ;
goto V_173;
}
V_225 = V_483 & V_488 ;
} while ( -- V_484 && V_225 );
if ( V_484 == 0 ) {
F_51 ( L_81 ) ;
V_166 = - V_180 ;
}
V_173:
F_306 ( V_247 ) ;
return V_166 ;
}
static int F_307 ( struct V_1 * V_1 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_247 * V_247 = F_155 ( V_40 -> V_4 . V_4 . V_248 ) ;
T_1 V_483 ;
int V_166 ;
if ( F_273 ( & V_1 -> V_184 , V_487 , & V_483 ) < 0 )
return - V_179 ;
if ( ! ( V_483 & V_489 ) )
return - V_490 ;
if ( F_273 ( & V_1 -> V_184 , V_485 , & V_483 ) < 0 )
return - V_179 ;
if ( V_483 & V_486 ) {
V_166 = F_304 ( V_1 ) ;
if ( V_166 )
return V_166 ;
}
F_308 ( V_247 ) ;
if ( F_219 ( & V_1 -> V_184 , V_485 ,
V_483 | V_486 ) < 0 ) {
F_306 ( V_247 ) ;
return - V_179 ;
}
F_305 ( V_33 , V_247 -> V_84 ) ;
return 0 ;
}
int F_309 ( struct V_1 * V_1 , T_1 * V_491 )
{
struct V_2 * V_40 = F_2 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_40 -> V_4 . V_4 . V_7 ) ;
struct V_247 * V_247 = F_155 ( V_40 -> V_4 . V_4 . V_248 ) ;
T_1 V_483 ;
int V_225 , V_166 ;
int V_484 = 6 ;
V_166 = F_307 ( V_1 ) ;
if ( V_166 )
return V_166 ;
do {
F_305 ( V_33 , V_247 -> V_84 ) ;
if ( F_273 ( & V_1 -> V_184 ,
V_487 , & V_483 ) < 0 ) {
V_166 = - V_179 ;
goto V_492;
}
V_225 = V_483 & V_488 ;
} while ( -- V_484 && V_225 == 0 );
if ( V_484 == 0 ) {
F_33 ( L_82 ) ;
V_166 = - V_180 ;
goto V_492;
}
if ( F_271 ( & V_1 -> V_184 , V_493 , V_491 , 6 ) < 0 ) {
V_166 = - V_179 ;
goto V_492;
}
V_492:
F_304 ( V_1 ) ;
return V_166 ;
}
static bool
F_310 ( struct V_1 * V_1 , T_1 * V_494 )
{
return F_273 ( & V_1 -> V_184 , V_495 ,
V_494 ) == 1 ;
}
static bool
F_311 ( struct V_1 * V_1 , T_1 * V_494 )
{
int V_166 ;
V_166 = F_271 ( & V_1 -> V_184 ,
V_496 ,
V_494 , 14 ) ;
if ( V_166 != 14 )
return false ;
return true ;
}
static T_2 F_312 ( struct V_1 * V_1 )
{
int V_141 = 0 ;
int V_252 = 1 ;
int V_497 , V_270 ;
T_2 V_271 , V_498 ;
V_141 = F_273 ( & V_1 -> V_184 , V_499 ,
& V_271 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_83 ) ;
return V_500 ;
}
V_271 &= V_501 ;
if ( V_271 < V_252 ||
V_271 > V_1 -> V_26 )
return V_500 ;
V_141 = F_273 ( & V_1 -> V_184 , V_502 ,
& V_498 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_84 ) ;
return V_500 ;
}
V_270 = F_313 ( V_498 ) ;
V_497 = F_28 ( V_1 -> V_21 ,
V_1 -> V_22 ,
V_270 ) ;
if ( V_497 < 0 )
return V_500 ;
V_1 -> V_241 . V_271 = V_271 ;
V_1 -> V_241 . V_270 = V_270 ;
return V_503 ;
}
static T_2 F_314 ( struct V_1 * V_1 )
{
T_2 V_504 ;
T_2 V_505 ;
T_12 V_506 , V_507 ;
int V_141 = 0 ;
V_141 = F_273 ( & V_1 -> V_184 , V_508 ,
& V_504 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_85 ) ;
return V_500 ;
}
if ( V_504 != V_509 )
return V_500 ;
V_141 = F_271 ( & V_1 -> V_184 , V_510 ,
& V_506 , 2 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_86 ) ;
return V_500 ;
}
V_141 = F_271 ( & V_1 -> V_184 , V_511 ,
& V_507 , 2 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_87 ) ;
return V_500 ;
}
V_141 = F_273 ( & V_1 -> V_184 , V_512 ,
& V_505 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_88 ) ;
return V_500 ;
}
if ( ( V_505 & V_513 ) != V_514 )
return V_500 ;
if ( V_505 & V_515 )
return V_500 ;
switch ( V_505 & V_516 ) {
case V_517 :
V_1 -> V_241 . V_242 . V_239 = 6 ;
break;
case V_518 :
V_1 -> V_241 . V_242 . V_239 = 8 ;
break;
default:
return V_500 ;
}
V_1 -> V_241 . V_242 . V_519 = V_504 ;
V_1 -> V_241 . V_242 . V_68 = F_315 ( V_506 ) ;
V_1 -> V_241 . V_242 . V_70 = F_315 ( V_507 ) ;
V_1 -> V_241 . V_520 = 1 ;
return V_503 ;
}
static T_2 F_316 ( struct V_1 * V_1 )
{
T_2 V_521 = V_503 ;
struct V_63 * V_63 = V_1 -> V_249 ;
struct V_8 * V_9 = & V_63 -> V_4 ;
if ( V_63 -> V_522 == NULL ||
V_9 -> V_523 ||
V_1 -> V_184 . V_524 > 6 ) {
if ( V_1 -> V_184 . V_525 > 0 ||
V_1 -> V_184 . V_524 > 0 )
F_51 ( L_89 ,
V_1 -> V_184 . V_525 ,
V_1 -> V_184 . V_524 ) ;
V_1 -> V_241 . V_242 . V_526 = V_527 ;
} else {
struct V_526 * V_528 = V_63 -> V_522 ;
V_528 += V_63 -> V_522 -> V_529 ;
if ( F_219 ( & V_1 -> V_184 , V_530 ,
V_528 -> V_531 ) <= 0 )
F_51 ( L_90 ) ;
V_521 = V_503 | V_532 ;
V_1 -> V_241 . V_242 . V_526 = V_533 ;
}
V_1 -> V_241 . V_520 = 1 ;
return V_521 ;
}
static T_2 F_317 ( struct V_1 * V_1 )
{
T_2 V_521 = V_500 ;
return V_521 ;
}
static void F_318 ( struct V_1 * V_1 )
{
T_2 V_534 = V_500 ;
T_2 V_191 = 0 ;
int V_141 ;
V_141 = F_273 ( & V_1 -> V_184 , V_535 , & V_191 ) ;
if ( V_141 <= 0 ) {
F_51 ( L_91 ) ;
goto V_536;
}
switch ( V_191 ) {
case V_269 :
F_51 ( L_92 ) ;
V_534 = F_312 ( V_1 ) ;
break;
case V_537 :
F_51 ( L_93 ) ;
V_534 = F_314 ( V_1 ) ;
break;
case V_538 :
F_51 ( L_94 ) ;
V_534 = F_316 ( V_1 ) ;
break;
case V_539 :
F_51 ( L_95 ) ;
V_534 = F_317 ( V_1 ) ;
break;
default:
F_51 ( L_96 , V_191 ) ;
break;
}
if ( V_534 & V_503 )
V_1 -> V_241 . V_268 = V_191 ;
V_536:
V_141 = F_219 ( & V_1 -> V_184 , V_540 , V_534 ) ;
if ( V_141 <= 0 )
F_51 ( L_97 ) ;
}
static int
F_319 ( struct V_1 * V_1 )
{
bool V_541 ;
if ( V_1 -> V_481 ) {
T_1 V_542 [ 16 ] = { 0 } ;
int V_166 = 0 ;
int V_543 ;
bool V_544 ;
V_541 = F_311 ( V_1 , V_542 ) ;
V_545:
if ( V_541 == true ) {
if ( V_1 -> V_546 &&
! F_320 ( & V_542 [ 10 ] , V_1 -> V_58 ) ) {
F_51 ( L_98 ) ;
F_250 ( V_1 ) ;
F_251 ( V_1 ) ;
}
F_51 ( L_99 , V_542 ) ;
V_166 = F_321 ( & V_1 -> V_482 , V_542 , & V_544 ) ;
if ( V_544 ) {
for ( V_543 = 0 ; V_543 < 3 ; V_543 ++ ) {
int V_547 ;
V_547 = F_322 ( & V_1 -> V_184 ,
V_496 + 1 ,
& V_542 [ 1 ] , 3 ) ;
if ( V_547 == 3 ) {
break;
}
}
V_541 = F_311 ( V_1 , V_542 ) ;
if ( V_541 == true ) {
F_51 ( L_100 , V_542 ) ;
goto V_545;
}
} else
V_166 = 0 ;
return V_166 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_51 ( L_101 ) ;
V_1 -> V_481 = false ;
F_303 ( & V_1 -> V_482 , V_1 -> V_481 ) ;
F_323 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_203 ;
}
static void
F_324 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = & F_2 ( V_1 ) -> V_4 ;
struct V_32 * V_33 = F_19 ( V_31 -> V_4 . V_7 ) ;
struct V_247 * V_248 = F_155 ( V_31 -> V_4 . V_248 ) ;
F_292 ( V_33 , V_248 -> V_84 , false ) ;
if ( V_248 -> V_548 -> V_261 )
F_293 ( V_33 ,
F_325 ( V_248 ) , false ) ;
F_250 ( V_1 ) ;
F_251 ( V_1 ) ;
F_305 ( V_33 , V_248 -> V_84 ) ;
F_292 ( V_33 , V_248 -> V_84 , true ) ;
if ( V_248 -> V_548 -> V_261 )
F_293 ( V_33 ,
F_325 ( V_248 ) , true ) ;
}
static void
F_326 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_388 [ V_389 ] ;
F_22 ( ! F_327 ( & V_7 -> V_549 . V_550 ) ) ;
if ( ! F_270 ( V_1 , V_388 ) ) {
F_33 ( L_102 ) ;
return;
}
if ( ! V_30 -> V_4 . V_248 )
return;
if ( ! F_155 ( V_30 -> V_4 . V_248 ) -> V_350 )
return;
if ( ! F_31 ( V_1 ) )
return;
if ( ! F_320 ( V_388 , V_1 -> V_58 ) ) {
F_51 ( L_103 ,
V_30 -> V_4 . V_218 ) ;
F_324 ( V_1 ) ;
}
}
static bool
F_328 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_494 = 0 ;
T_1 V_551 = V_1 -> V_471 ;
bool V_166 ;
memset ( & V_1 -> V_241 , 0 , sizeof( V_1 -> V_241 ) ) ;
V_166 = F_299 ( V_1 ) ;
if ( ( V_551 != V_1 -> V_471 ) || ! V_166 ) {
return false ;
}
if ( V_1 -> V_16 [ V_343 ] >= 0x11 &&
F_310 ( V_1 , & V_494 ) &&
V_494 != 0 ) {
F_219 ( & V_1 -> V_184 ,
V_495 ,
V_494 ) ;
if ( V_494 & V_552 )
F_318 ( V_1 ) ;
if ( V_494 & ( V_553 | V_554 ) )
F_252 ( L_104 ) ;
}
F_329 ( & V_7 -> V_549 . V_550 , NULL ) ;
F_326 ( V_1 ) ;
F_330 ( & V_7 -> V_549 . V_550 ) ;
if ( V_1 -> V_241 . V_268 == V_269 ) {
F_51 ( L_105 ) ;
F_323 ( V_30 -> V_4 . V_7 ) ;
}
return true ;
}
static enum V_555
F_331 ( struct V_1 * V_1 )
{
struct V_347 * V_348 = F_220 ( V_1 ) ;
T_2 * V_16 = V_1 -> V_16 ;
T_2 type ;
if ( V_348 -> V_350 )
F_332 ( V_348 ) ;
if ( ! F_299 ( V_1 ) )
return V_556 ;
if ( F_1 ( V_1 ) )
return V_557 ;
if ( ! F_297 ( V_16 ) )
return V_557 ;
if ( V_1 -> V_16 [ V_343 ] >= 0x11 &&
V_1 -> V_37 [ 0 ] & V_558 ) {
return V_1 -> V_471 ?
V_557 : V_556 ;
}
if ( F_301 ( V_1 ) )
return V_557 ;
if ( F_333 ( & V_1 -> V_184 . V_559 ) )
return V_557 ;
if ( V_1 -> V_16 [ V_343 ] >= 0x11 ) {
type = V_1 -> V_37 [ 0 ] & V_38 ;
if ( type == V_39 ||
type == V_560 )
return V_561 ;
} else {
type = V_1 -> V_16 [ V_562 ] &
V_563 ;
if ( type == V_564 ||
type == V_565 )
return V_561 ;
}
F_51 ( L_106 ) ;
return V_556 ;
}
static enum V_555
F_334 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_555 V_141 ;
V_141 = F_335 ( V_33 ) ;
if ( V_141 == V_561 )
V_141 = V_557 ;
return V_141 ;
}
static bool F_336 ( struct V_32 * V_33 ,
struct V_2 * V_95 )
{
T_5 V_566 ;
switch ( V_95 -> V_95 ) {
case V_145 :
return true ;
case V_212 :
V_566 = V_567 ;
break;
case V_214 :
V_566 = V_568 ;
break;
case V_216 :
V_566 = V_569 ;
break;
default:
F_121 ( V_95 -> V_95 ) ;
return false ;
}
return F_48 ( V_570 ) & V_566 ;
}
static bool F_337 ( struct V_32 * V_33 ,
struct V_2 * V_95 )
{
T_5 V_566 ;
switch ( V_95 -> V_95 ) {
case V_145 :
return true ;
case V_212 :
V_566 = V_571 ;
break;
case V_214 :
V_566 = V_572 ;
break;
case V_216 :
V_566 = V_573 ;
break;
case V_574 :
V_566 = V_575 ;
break;
default:
F_121 ( V_95 -> V_95 ) ;
return false ;
}
return F_48 ( V_570 ) & V_566 ;
}
static bool F_338 ( struct V_32 * V_33 ,
struct V_2 * V_95 )
{
T_5 V_566 ;
switch ( V_95 -> V_95 ) {
case V_212 :
V_566 = V_576 ;
break;
case V_214 :
V_566 = V_577 ;
break;
case V_216 :
V_566 = V_578 ;
break;
default:
F_121 ( V_95 -> V_95 ) ;
return false ;
}
return F_48 ( V_579 ) & V_566 ;
}
static bool F_339 ( struct V_32 * V_33 ,
struct V_2 * V_95 )
{
T_5 V_566 ;
switch ( V_95 -> V_95 ) {
case V_212 :
V_566 = V_580 ;
break;
case V_214 :
V_566 = V_581 ;
break;
case V_216 :
V_566 = V_582 ;
break;
default:
F_121 ( V_95 -> V_95 ) ;
return false ;
}
return F_48 ( V_579 ) & V_566 ;
}
static bool F_340 ( struct V_32 * V_33 ,
struct V_2 * V_3 )
{
struct V_30 * V_30 = & V_3 -> V_4 ;
enum V_95 V_95 ;
T_5 V_566 ;
F_341 ( V_30 -> V_583 , & V_95 ) ;
switch ( V_95 ) {
case V_145 :
V_566 = V_584 ;
break;
case V_212 :
V_566 = V_585 ;
break;
case V_214 :
V_566 = V_586 ;
break;
default:
F_121 ( V_95 ) ;
return false ;
}
return F_48 ( V_587 ) & V_566 ;
}
bool F_342 ( struct V_32 * V_33 ,
struct V_2 * V_95 )
{
if ( F_291 ( V_33 ) )
return F_336 ( V_33 , V_95 ) ;
else if ( F_134 ( V_33 ) )
return F_337 ( V_33 , V_95 ) ;
else if ( F_23 ( V_33 ) )
return F_340 ( V_33 , V_95 ) ;
else if ( F_343 ( V_33 ) )
return F_339 ( V_33 , V_95 ) ;
else
return F_338 ( V_33 , V_95 ) ;
}
static struct V_526 *
F_344 ( struct V_1 * V_1 )
{
struct V_63 * V_63 = V_1 -> V_249 ;
if ( V_63 -> V_526 ) {
if ( F_345 ( V_63 -> V_526 ) )
return NULL ;
return F_346 ( V_63 -> V_526 ) ;
} else
return F_347 ( & V_63 -> V_4 ,
& V_1 -> V_184 . V_559 ) ;
}
static void
F_348 ( struct V_1 * V_1 )
{
struct V_63 * V_63 = V_1 -> V_249 ;
struct V_526 * V_526 ;
F_349 ( V_1 ) ;
V_526 = F_344 ( V_1 ) ;
V_63 -> V_522 = V_526 ;
V_1 -> V_263 = F_350 ( V_526 ) ;
}
static void
F_349 ( struct V_1 * V_1 )
{
struct V_63 * V_63 = V_1 -> V_249 ;
F_138 ( V_63 -> V_522 ) ;
V_63 -> V_522 = NULL ;
V_1 -> V_263 = false ;
}
static int
F_351 ( struct V_63 * V_63 )
{
struct V_8 * V_9 = & V_63 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_555 V_141 ;
T_1 V_494 = 0 ;
F_22 ( ! F_327 ( & V_9 -> V_7 -> V_549 . V_550 ) ) ;
F_40 ( F_19 ( V_7 ) , V_1 -> V_82 ) ;
if ( F_1 ( V_1 ) )
V_141 = F_334 ( V_1 ) ;
else if ( F_342 ( F_19 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_141 = F_331 ( V_1 ) ;
else
V_141 = V_556 ;
if ( V_141 == V_556 ) {
memset ( & V_1 -> V_241 , 0 , sizeof( V_1 -> V_241 ) ) ;
if ( V_1 -> V_481 ) {
F_51 ( L_107 ,
V_1 -> V_481 ,
V_1 -> V_482 . V_588 ) ;
V_1 -> V_481 = false ;
F_303 ( & V_1 -> V_482 ,
V_1 -> V_481 ) ;
}
goto V_173;
}
if ( V_30 -> type != V_5 )
V_30 -> type = V_108 ;
F_51 ( L_108 ,
F_352 ( F_26 ( V_1 ) ) ,
F_352 ( F_353 ( V_1 -> V_16 ) ) ) ;
if ( V_1 -> V_589 ) {
V_1 -> V_26 = F_11 ( V_1 ) ;
V_1 -> V_57 = F_10 ( V_1 ) ;
V_1 -> V_589 = false ;
}
F_148 ( V_1 ) ;
F_296 ( & V_1 -> V_184 , & V_1 -> V_259 ,
F_297 ( V_1 -> V_16 ) ) ;
F_302 ( V_1 ) ;
if ( V_1 -> V_481 ) {
V_141 = V_556 ;
goto V_173;
} else {
F_326 ( V_1 ) ;
}
V_1 -> V_184 . V_525 = 0 ;
V_1 -> V_184 . V_524 = 0 ;
F_348 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_63 -> V_522 )
V_141 = V_557 ;
V_1 -> V_590 = true ;
if ( V_1 -> V_16 [ V_343 ] >= 0x11 &&
F_310 ( V_1 , & V_494 ) &&
V_494 != 0 ) {
F_219 ( & V_1 -> V_184 ,
V_495 ,
V_494 ) ;
if ( V_494 & V_552 )
F_318 ( V_1 ) ;
if ( V_494 & ( V_553 | V_554 ) )
F_252 ( L_104 ) ;
}
V_173:
if ( V_141 != V_557 && ! V_1 -> V_481 )
F_349 ( V_1 ) ;
F_44 ( F_19 ( V_7 ) , V_1 -> V_82 ) ;
return V_141 ;
}
static int
F_354 ( struct V_8 * V_9 ,
struct V_591 * V_592 ,
bool V_593 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_141 = V_9 -> V_141 ;
F_51 ( L_109 ,
V_9 -> V_4 . V_594 , V_9 -> V_218 ) ;
if ( ! V_1 -> V_590 )
V_141 = F_351 ( V_1 -> V_249 ) ;
V_1 -> V_590 = false ;
return V_141 ;
}
static void
F_355 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_30 * V_30 = & F_2 ( V_1 ) -> V_4 ;
struct V_32 * V_33 = F_19 ( V_30 -> V_4 . V_7 ) ;
F_51 ( L_109 ,
V_9 -> V_4 . V_594 , V_9 -> V_218 ) ;
F_349 ( V_1 ) ;
if ( V_9 -> V_141 != V_557 )
return;
F_40 ( V_33 , V_1 -> V_82 ) ;
F_348 ( V_1 ) ;
F_44 ( V_33 , V_1 -> V_82 ) ;
if ( V_30 -> type != V_5 )
V_30 -> type = V_108 ;
}
static int F_356 ( struct V_8 * V_9 )
{
struct V_63 * V_63 = F_35 ( V_9 ) ;
struct V_526 * V_526 ;
V_526 = V_63 -> V_522 ;
if ( V_526 ) {
int V_166 = F_357 ( V_9 , V_526 ) ;
if ( V_166 )
return V_166 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_63 -> V_65 . V_64 ) {
struct V_61 * V_62 ;
V_62 = F_358 ( V_9 -> V_7 ,
V_63 -> V_65 . V_64 ) ;
if ( V_62 ) {
F_359 ( V_9 , V_62 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_360 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_166 ;
V_166 = F_361 ( V_9 ) ;
if ( V_166 )
return V_166 ;
F_362 ( V_9 ) ;
F_51 ( L_110 ,
V_1 -> V_184 . V_218 , V_9 -> V_595 -> V_596 . V_218 ) ;
V_1 -> V_184 . V_7 = V_9 -> V_595 ;
return F_363 ( & V_1 -> V_184 ) ;
}
static void
F_364 ( struct V_8 * V_9 )
{
F_365 ( & F_4 ( V_9 ) -> V_184 ) ;
F_366 ( V_9 ) ;
}
static void
F_367 ( struct V_8 * V_9 )
{
struct V_63 * V_63 = F_35 ( V_9 ) ;
F_138 ( V_63 -> V_522 ) ;
if ( ! F_368 ( V_63 -> V_526 ) )
F_138 ( V_63 -> V_526 ) ;
if ( V_9 -> V_597 == V_598 )
F_369 ( & V_63 -> V_65 ) ;
F_370 ( V_9 ) ;
F_138 ( V_9 ) ;
}
void F_371 ( struct V_599 * V_31 )
{
struct V_2 * V_3 = F_372 ( V_31 ) ;
struct V_1 * V_1 = & V_3 -> V_600 ;
F_373 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_374 ( & V_1 -> V_323 ) ;
F_39 ( V_1 ) ;
F_189 ( V_1 ) ;
F_42 ( V_1 ) ;
if ( V_1 -> V_130 . V_601 ) {
F_375 ( & V_1 -> V_130 ) ;
V_1 -> V_130 . V_601 = NULL ;
}
}
F_137 ( V_1 ) ;
F_376 ( V_31 ) ;
F_138 ( V_3 ) ;
}
void F_377 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = F_5 ( & V_30 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_374 ( & V_1 -> V_323 ) ;
F_39 ( V_1 ) ;
F_189 ( V_1 ) ;
F_42 ( V_1 ) ;
}
static void F_378 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
F_65 ( & V_33 -> V_83 ) ;
if ( ! F_92 ( V_1 ) )
return;
F_51 ( L_111 ) ;
F_40 ( V_33 , V_1 -> V_82 ) ;
F_192 ( V_1 ) ;
}
static enum V_84 F_379 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( F_3 ( V_1 ) ) ;
if ( ( V_1 -> V_92 & V_94 ) == 0 )
return V_110 ;
if ( F_53 ( V_33 ) )
return F_228 ( V_1 -> V_92 ) ;
else
return F_229 ( V_1 -> V_92 ) ;
}
void F_380 ( struct V_599 * V_31 )
{
struct V_32 * V_33 = F_19 ( V_31 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_31 ) ;
struct V_347 * V_348 = F_220 ( V_1 ) ;
if ( ! F_158 ( V_33 ) )
V_1 -> V_92 = F_48 ( V_1 -> V_93 ) ;
if ( V_348 -> V_350 )
F_332 ( V_348 ) ;
V_1 -> V_589 = true ;
F_39 ( V_1 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
V_1 -> V_109 = F_379 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_381 ( V_31 -> V_7 , V_1 ) ;
F_378 ( V_1 ) ;
}
F_42 ( V_1 ) ;
}
enum V_602
F_382 ( struct V_2 * V_3 , bool V_603 )
{
struct V_1 * V_1 = & V_3 -> V_600 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_602 V_166 = V_604 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_605 )
V_3 -> V_4 . type = V_108 ;
if ( V_603 && V_3 -> V_4 . type == V_5 ) {
F_51 ( L_112 ,
F_50 ( V_3 -> V_95 ) ) ;
return V_606 ;
}
F_51 ( L_113 ,
F_50 ( V_3 -> V_95 ) ,
V_603 ? L_114 : L_115 ) ;
if ( V_603 ) {
V_1 -> V_589 = true ;
V_1 -> V_590 = false ;
return V_604 ;
}
F_40 ( V_33 , V_1 -> V_82 ) ;
if ( V_1 -> V_481 ) {
if ( F_319 ( V_1 ) == - V_203 ) {
F_51 ( L_107 ,
V_1 -> V_481 , V_1 -> V_482 . V_588 ) ;
V_1 -> V_481 = false ;
F_303 ( & V_1 -> V_482 ,
V_1 -> V_481 ) ;
V_1 -> V_590 = false ;
goto V_607;
}
}
if ( ! V_1 -> V_481 ) {
if ( ! F_328 ( V_1 ) ) {
V_1 -> V_590 = false ;
goto V_607;
}
}
V_166 = V_606 ;
V_607:
F_44 ( V_33 , V_1 -> V_82 ) ;
return V_166 ;
}
bool F_383 ( struct V_32 * V_33 , enum V_95 V_95 )
{
if ( F_144 ( V_33 ) < 5 )
return false ;
if ( F_144 ( V_33 ) < 9 && V_95 == V_145 )
return true ;
return F_384 ( V_33 , V_95 ) ;
}
static void
F_385 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_33 = F_19 ( V_9 -> V_7 ) ;
F_386 ( V_9 ) ;
F_387 ( V_9 ) ;
if ( F_1 ( V_1 ) ) {
T_5 V_608 ;
V_608 = F_388 ( V_609 ) | F_388 ( V_610 ) ;
if ( ! F_161 ( V_33 ) )
V_608 |= F_388 ( V_611 ) ;
F_389 ( V_9 , V_608 ) ;
V_9 -> V_287 -> V_267 = V_609 ;
}
}
static void F_390 ( struct V_1 * V_1 )
{
V_1 -> V_310 = F_180 () ;
V_1 -> V_314 = V_311 ;
V_1 -> V_316 = V_311 ;
}
static void
F_391 ( struct V_32 * V_33 ,
struct V_1 * V_1 , struct V_612 * V_613 )
{
T_5 V_123 , V_124 , V_125 = 0 , V_614 = 0 ;
struct V_118 V_119 ;
F_81 ( V_33 , V_1 , & V_119 ) ;
V_614 = F_185 ( V_1 ) ;
V_123 = F_48 ( V_119 . V_123 ) ;
V_124 = F_48 ( V_119 . V_124 ) ;
if ( ! F_23 ( V_33 ) && ! F_83 ( V_33 ) ) {
F_58 ( V_119 . V_121 , V_614 ) ;
V_125 = F_48 ( V_119 . V_125 ) ;
}
V_613 -> V_615 = ( V_123 & V_616 ) >>
V_617 ;
V_613 -> V_618 = ( V_123 & V_619 ) >>
V_620 ;
V_613 -> V_621 = ( V_124 & V_622 ) >>
V_623 ;
V_613 -> V_624 = ( V_124 & V_625 ) >>
V_626 ;
if ( F_23 ( V_33 ) || F_83 ( V_33 ) ) {
T_13 V_351 = ( V_614 & V_627 ) >>
V_628 ;
if ( V_351 > 0 )
V_613 -> V_629 = ( V_351 - 1 ) * 1000 ;
else
V_613 -> V_629 = 0 ;
} else {
V_613 -> V_629 = ( ( V_125 & V_630 ) >>
V_631 ) * 1000 ;
}
}
static void
F_392 ( const char * V_632 , const struct V_612 * V_613 )
{
F_51 ( L_116 ,
V_632 ,
V_613 -> V_615 , V_613 -> V_618 , V_613 -> V_621 , V_613 -> V_624 , V_613 -> V_629 ) ;
}
static void
F_175 ( struct V_32 * V_33 ,
struct V_1 * V_1 )
{
struct V_612 V_147 ;
struct V_612 * V_633 = & V_1 -> V_634 ;
F_391 ( V_33 , V_1 , & V_147 ) ;
if ( V_147 . V_615 != V_633 -> V_615 || V_147 . V_618 != V_633 -> V_618 || V_147 . V_621 != V_633 -> V_621 ||
V_147 . V_624 != V_633 -> V_624 || V_147 . V_629 != V_633 -> V_629 ) {
F_33 ( L_117 ) ;
F_392 ( L_118 , V_633 ) ;
F_392 ( L_119 , & V_147 ) ;
}
}
static void
F_67 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_612 V_635 , V_206 , V_636 ,
* V_637 = & V_1 -> V_634 ;
F_65 ( & V_33 -> V_83 ) ;
if ( V_637 -> V_629 != 0 )
return;
F_391 ( V_33 , V_1 , & V_635 ) ;
F_392 ( L_120 , & V_635 ) ;
V_206 = V_33 -> V_206 . V_274 . V_638 ;
V_636 . V_615 = 210 * 10 ;
V_636 . V_618 = 50 * 10 ;
V_636 . V_621 = 50 * 10 ;
V_636 . V_624 = 500 * 10 ;
V_636 . V_629 = ( 510 + 100 ) * 10 ;
F_392 ( L_121 , & V_206 ) ;
#define F_393 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_393 ( V_615 ) ;
F_393 ( V_618 ) ;
F_393 ( V_621 ) ;
F_393 ( V_624 ) ;
F_393 ( V_629 ) ;
#undef F_393
#define F_394 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_324 = F_394 ( V_615 ) ;
V_1 -> V_315 = F_394 ( V_618 ) ;
V_1 -> V_317 = F_394 ( V_621 ) ;
V_1 -> V_449 = F_394 ( V_624 ) ;
V_1 -> V_137 = F_394 ( V_629 ) ;
#undef F_394
F_51 ( L_122 ,
V_1 -> V_324 , V_1 -> V_449 ,
V_1 -> V_137 ) ;
F_51 ( L_123 ,
V_1 -> V_315 , V_1 -> V_317 ) ;
V_637 -> V_618 = 1 ;
V_637 -> V_621 = 1 ;
}
static void
F_68 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
bool V_639 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
T_5 V_123 , V_124 , V_125 , V_115 = 0 ;
int div = V_33 -> V_144 / 1000 ;
struct V_118 V_119 ;
enum V_95 V_95 = F_2 ( V_1 ) -> V_95 ;
const struct V_612 * V_613 = & V_1 -> V_634 ;
F_65 ( & V_33 -> V_83 ) ;
F_81 ( V_33 , V_1 , & V_119 ) ;
if ( V_639 ) {
T_5 V_320 = F_185 ( V_1 ) ;
F_8 ( V_320 & V_325 , L_124 ) ;
if ( V_320 & V_113 )
F_51 ( L_125 ) ;
V_320 &= ~ V_113 ;
F_58 ( V_119 . V_121 , V_320 ) ;
}
V_123 = ( V_613 -> V_615 << V_617 ) |
( V_613 -> V_618 << V_620 ) ;
V_124 = ( V_613 -> V_621 << V_623 ) |
( V_613 -> V_624 << V_626 ) ;
if ( F_23 ( V_33 ) || F_83 ( V_33 ) ) {
V_125 = F_48 ( V_119 . V_121 ) ;
V_125 &= ~ V_627 ;
V_125 |= ( F_16 ( ( V_613 -> V_629 + 1 ) , 1000 )
<< V_628 ) ;
} else {
V_125 = ( ( 100 * div ) / 2 - 1 ) << V_640 ;
V_125 |= ( F_16 ( V_613 -> V_629 , 1000 )
<< V_631 ) ;
}
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
V_115 = F_77 ( V_95 ) ;
} else if ( F_291 ( V_33 ) || F_172 ( V_33 ) ) {
if ( V_95 == V_145 )
V_115 = V_641 ;
else
V_115 = V_642 ;
}
V_123 |= V_115 ;
F_58 ( V_119 . V_123 , V_123 ) ;
F_58 ( V_119 . V_124 , V_124 ) ;
if ( F_23 ( V_33 ) || F_83 ( V_33 ) )
F_58 ( V_119 . V_121 , V_125 ) ;
else
F_58 ( V_119 . V_125 , V_125 ) ;
F_51 ( L_126 ,
F_48 ( V_119 . V_123 ) ,
F_48 ( V_119 . V_124 ) ,
( F_23 ( V_33 ) || F_83 ( V_33 ) ) ?
( F_48 ( V_119 . V_121 ) & V_627 ) :
F_48 ( V_119 . V_125 ) ) ;
}
static void F_381 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
F_78 ( V_1 ) ;
} else {
F_67 ( V_7 , V_1 ) ;
F_68 ( V_7 , V_1 , false ) ;
}
}
static void F_395 ( struct V_32 * V_33 ,
struct V_221 * V_332 ,
int V_643 )
{
struct V_30 * V_31 ;
struct V_2 * V_40 = NULL ;
struct V_1 * V_1 = V_33 -> V_283 . V_600 ;
struct V_247 * V_247 = F_155 ( V_332 -> V_4 . V_248 ) ;
enum V_644 V_59 = V_645 ;
if ( V_643 <= 0 ) {
F_51 ( L_127 ) ;
return;
}
if ( V_1 == NULL ) {
F_51 ( L_128 ) ;
return;
}
V_40 = F_2 ( V_1 ) ;
V_31 = & V_40 -> V_4 ;
V_247 = F_155 ( V_31 -> V_4 . V_248 ) ;
if ( ! V_247 ) {
F_51 ( L_129 ) ;
return;
}
if ( V_33 -> V_283 . type < V_284 ) {
F_51 ( L_130 ) ;
return;
}
if ( V_1 -> V_249 -> V_65 . V_282 -> V_646 ==
V_643 )
V_59 = V_647 ;
if ( V_59 == V_33 -> V_283 . V_648 ) {
F_51 (
L_131 ) ;
return;
}
if ( ! V_332 -> V_4 . V_350 ) {
F_51 ( L_132 ) ;
return;
}
if ( F_144 ( V_33 ) >= 8 && ! F_53 ( V_33 ) ) {
switch ( V_59 ) {
case V_645 :
F_396 ( V_247 , V_649 ) ;
break;
case V_647 :
F_396 ( V_247 , V_650 ) ;
break;
case V_651 :
default:
F_33 ( L_133 ) ;
}
} else if ( F_144 ( V_33 ) > 6 ) {
T_6 V_652 = F_397 ( V_332 -> V_653 ) ;
T_5 V_444 ;
V_444 = F_48 ( V_652 ) ;
if ( V_59 > V_645 ) {
if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
V_444 |= V_654 ;
else
V_444 |= V_655 ;
} else {
if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
V_444 &= ~ V_654 ;
else
V_444 &= ~ V_655 ;
}
F_58 ( V_652 , V_444 ) ;
}
V_33 -> V_283 . V_648 = V_59 ;
F_51 ( L_134 , V_643 ) ;
}
void F_398 ( struct V_1 * V_1 ,
struct V_221 * V_332 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! V_332 -> V_262 ) {
F_51 ( L_135 ) ;
return;
}
F_41 ( & V_33 -> V_283 . V_656 ) ;
if ( F_22 ( V_33 -> V_283 . V_600 ) ) {
F_33 ( L_136 ) ;
goto V_657;
}
V_33 -> V_283 . V_658 = 0 ;
V_33 -> V_283 . V_600 = V_1 ;
V_657:
F_43 ( & V_33 -> V_283 . V_656 ) ;
}
void F_399 ( struct V_1 * V_1 ,
struct V_221 * V_361 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
if ( ! V_361 -> V_262 )
return;
F_41 ( & V_33 -> V_283 . V_656 ) ;
if ( ! V_33 -> V_283 . V_600 ) {
F_43 ( & V_33 -> V_283 . V_656 ) ;
return;
}
if ( V_33 -> V_283 . V_648 == V_647 )
F_395 ( V_33 , V_361 ,
V_1 -> V_249 -> V_65 . V_64 -> V_646 ) ;
V_33 -> V_283 . V_600 = NULL ;
F_43 ( & V_33 -> V_283 . V_656 ) ;
F_374 ( & V_33 -> V_283 . V_659 ) ;
}
static void F_400 ( struct V_326 * V_659 )
{
struct V_32 * V_33 =
F_88 ( V_659 , F_89 ( * V_33 ) , V_283 . V_659 . V_659 ) ;
struct V_1 * V_1 ;
F_41 ( & V_33 -> V_283 . V_656 ) ;
V_1 = V_33 -> V_283 . V_600 ;
if ( ! V_1 )
goto V_657;
if ( V_33 -> V_283 . V_658 )
goto V_657;
if ( V_33 -> V_283 . V_648 != V_647 ) {
struct V_660 * V_248 = F_2 ( V_1 ) -> V_4 . V_4 . V_248 ;
F_395 ( V_33 , F_155 ( V_248 ) -> V_548 ,
V_1 -> V_249 -> V_65 . V_282 -> V_646 ) ;
}
V_657:
F_43 ( & V_33 -> V_283 . V_656 ) ;
}
void F_401 ( struct V_32 * V_33 ,
unsigned int V_661 )
{
struct V_660 * V_248 ;
enum V_84 V_84 ;
if ( V_33 -> V_283 . type == V_662 )
return;
F_186 ( & V_33 -> V_283 . V_659 ) ;
F_41 ( & V_33 -> V_283 . V_656 ) ;
if ( ! V_33 -> V_283 . V_600 ) {
F_43 ( & V_33 -> V_283 . V_656 ) ;
return;
}
V_248 = F_2 ( V_33 -> V_283 . V_600 ) -> V_4 . V_4 . V_248 ;
V_84 = F_155 ( V_248 ) -> V_84 ;
V_661 &= F_402 ( V_84 ) ;
V_33 -> V_283 . V_658 |= V_661 ;
if ( V_661 && V_33 -> V_283 . V_648 == V_647 )
F_395 ( V_33 , F_155 ( V_248 ) -> V_548 ,
V_33 -> V_283 . V_600 -> V_249 -> V_65 . V_64 -> V_646 ) ;
F_43 ( & V_33 -> V_283 . V_656 ) ;
}
void F_403 ( struct V_32 * V_33 ,
unsigned int V_661 )
{
struct V_660 * V_248 ;
enum V_84 V_84 ;
if ( V_33 -> V_283 . type == V_662 )
return;
F_186 ( & V_33 -> V_283 . V_659 ) ;
F_41 ( & V_33 -> V_283 . V_656 ) ;
if ( ! V_33 -> V_283 . V_600 ) {
F_43 ( & V_33 -> V_283 . V_656 ) ;
return;
}
V_248 = F_2 ( V_33 -> V_283 . V_600 ) -> V_4 . V_4 . V_248 ;
V_84 = F_155 ( V_248 ) -> V_84 ;
V_661 &= F_402 ( V_84 ) ;
V_33 -> V_283 . V_658 &= ~ V_661 ;
if ( V_661 && V_33 -> V_283 . V_648 == V_647 )
F_395 ( V_33 , F_155 ( V_248 ) -> V_548 ,
V_33 -> V_283 . V_600 -> V_249 -> V_65 . V_64 -> V_646 ) ;
if ( ! V_33 -> V_283 . V_658 )
F_194 ( & V_33 -> V_283 . V_659 ,
F_193 ( 1000 ) ) ;
F_43 ( & V_33 -> V_283 . V_656 ) ;
}
static struct V_61 *
F_404 ( struct V_63 * V_63 ,
struct V_61 * V_64 )
{
struct V_8 * V_9 = & V_63 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_61 * V_282 = NULL ;
F_405 ( & V_33 -> V_283 . V_659 , F_400 ) ;
F_406 ( & V_33 -> V_283 . V_656 ) ;
if ( F_144 ( V_33 ) <= 6 ) {
F_51 ( L_137 ) ;
return NULL ;
}
if ( V_33 -> V_206 . V_663 != V_284 ) {
F_51 ( L_138 ) ;
return NULL ;
}
V_282 = F_407
( V_33 , V_64 , V_9 ) ;
if ( ! V_282 ) {
F_51 ( L_139 ) ;
return NULL ;
}
V_33 -> V_283 . type = V_33 -> V_206 . V_663 ;
V_33 -> V_283 . V_648 = V_645 ;
F_51 ( L_140 ) ;
return V_282 ;
}
static bool F_408 ( struct V_1 * V_1 ,
struct V_63 * V_63 )
{
struct V_8 * V_9 = & V_63 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_30 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
struct V_61 * V_64 = NULL ;
struct V_61 * V_282 = NULL ;
bool V_664 ;
struct V_61 * V_665 ;
struct V_526 * V_526 ;
enum V_84 V_84 = V_110 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_409 ( V_7 ) ) {
F_22 ( ! ( F_291 ( V_33 ) || F_172 ( V_33 ) ) ) ;
F_410 ( L_141 ) ;
return false ;
}
F_39 ( V_1 ) ;
F_390 ( V_1 ) ;
F_381 ( V_7 , V_1 ) ;
F_378 ( V_1 ) ;
F_42 ( V_1 ) ;
V_664 = F_295 ( V_1 ) ;
if ( ! V_664 ) {
F_410 ( L_142 ) ;
goto V_666;
}
F_41 ( & V_7 -> V_549 . V_656 ) ;
V_526 = F_347 ( V_9 , & V_1 -> V_184 . V_559 ) ;
if ( V_526 ) {
if ( F_411 ( V_9 , V_526 ) ) {
F_412 ( V_9 ,
V_526 ) ;
F_413 ( V_9 , V_526 ) ;
} else {
F_138 ( V_526 ) ;
V_526 = F_414 ( - V_203 ) ;
}
} else {
V_526 = F_414 ( - V_667 ) ;
}
V_63 -> V_526 = V_526 ;
F_415 (scan, &connector->probed_modes, head) {
if ( ( V_665 -> type & V_668 ) ) {
V_64 = F_358 ( V_7 , V_665 ) ;
V_282 = F_404 (
V_63 , V_64 ) ;
break;
}
}
if ( ! V_64 && V_33 -> V_206 . V_669 ) {
V_64 = F_358 ( V_7 ,
V_33 -> V_206 . V_669 ) ;
if ( V_64 ) {
V_64 -> type |= V_668 ;
V_9 -> V_273 . V_670 = V_64 -> V_670 ;
V_9 -> V_273 . V_671 = V_64 -> V_671 ;
}
}
F_43 ( & V_7 -> V_549 . V_656 ) ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) ) {
V_1 -> V_130 . V_601 = F_87 ;
F_416 ( & V_1 -> V_130 ) ;
V_84 = F_379 ( V_1 ) ;
if ( V_84 != V_107 && V_84 != V_100 )
V_84 = V_1 -> V_85 ;
if ( V_84 != V_107 && V_84 != V_100 )
V_84 = V_107 ;
F_51 ( L_143 ,
F_49 ( V_84 ) ) ;
}
F_417 ( & V_63 -> V_65 , V_64 , V_282 ) ;
V_63 -> V_65 . V_672 . V_673 = F_206 ;
F_418 ( V_9 , V_84 ) ;
return true ;
V_666:
F_374 ( & V_1 -> V_323 ) ;
F_39 ( V_1 ) ;
F_189 ( V_1 ) ;
F_42 ( V_1 ) ;
return false ;
}
static void
F_419 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = & V_3 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_600 ;
switch ( V_3 -> V_95 ) {
case V_145 :
V_31 -> V_583 = V_674 ;
V_1 -> V_82 = V_675 ;
break;
case V_212 :
V_31 -> V_583 = V_676 ;
V_1 -> V_82 = V_677 ;
break;
case V_214 :
V_31 -> V_583 = V_678 ;
V_1 -> V_82 = V_679 ;
break;
case V_216 :
V_31 -> V_583 = V_680 ;
V_1 -> V_82 = V_681 ;
break;
case V_574 :
V_31 -> V_583 = V_682 ;
V_1 -> V_82 = V_681 ;
break;
default:
F_121 ( V_3 -> V_95 ) ;
}
}
static void F_420 ( struct V_326 * V_659 )
{
struct V_63 * V_63 ;
struct V_8 * V_9 ;
V_63 = F_88 ( V_659 , F_89 ( * V_63 ) ,
V_683 ) ;
V_9 = & V_63 -> V_4 ;
F_51 ( L_109 , V_9 -> V_4 . V_594 ,
V_9 -> V_218 ) ;
F_41 ( & V_9 -> V_7 -> V_549 . V_656 ) ;
F_421 ( V_9 ,
V_684 ) ;
F_43 ( & V_9 -> V_7 -> V_549 . V_656 ) ;
F_323 ( V_9 -> V_7 ) ;
}
bool
F_422 ( struct V_2 * V_3 ,
struct V_63 * V_63 )
{
struct V_8 * V_9 = & V_63 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_600 ;
struct V_30 * V_30 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_30 -> V_4 . V_7 ;
struct V_32 * V_33 = F_19 ( V_7 ) ;
enum V_95 V_95 = V_3 -> V_95 ;
int type ;
F_423 ( & V_63 -> V_683 ,
F_420 ) ;
if ( F_8 ( V_3 -> V_24 < 1 ,
L_144 ,
V_3 -> V_24 , F_50 ( V_95 ) ) )
return false ;
F_21 ( V_1 ) ;
V_1 -> V_589 = true ;
V_1 -> V_85 = V_110 ;
V_1 -> V_109 = V_110 ;
if ( F_144 ( V_33 ) >= 9 )
V_1 -> V_175 = F_104 ;
else if ( F_142 ( V_33 ) || F_107 ( V_33 ) )
V_1 -> V_175 = F_102 ;
else if ( F_134 ( V_33 ) )
V_1 -> V_175 = F_101 ;
else
V_1 -> V_175 = F_99 ;
if ( F_144 ( V_33 ) >= 9 )
V_1 -> V_177 = F_108 ;
else
V_1 -> V_177 = F_105 ;
if ( F_158 ( V_33 ) )
V_1 -> V_685 = V_686 ;
V_1 -> V_92 = F_48 ( V_1 -> V_93 ) ;
V_1 -> V_249 = V_63 ;
if ( F_383 ( V_33 , V_95 ) )
type = V_598 ;
else
type = V_687 ;
if ( F_80 ( V_33 ) || F_53 ( V_33 ) )
V_1 -> V_109 = F_379 ( V_1 ) ;
if ( type == V_598 )
V_30 -> type = V_5 ;
if ( F_22 ( ( F_80 ( V_33 ) || F_53 ( V_33 ) ) &&
F_1 ( V_1 ) && V_95 != V_212 && V_95 != V_214 ) )
return false ;
F_51 ( L_145 ,
type == V_598 ? L_146 : L_147 ,
F_50 ( V_95 ) ) ;
F_424 ( V_7 , V_9 , & V_688 , type ) ;
F_425 ( V_9 , & V_689 ) ;
V_9 -> V_690 = true ;
V_9 -> V_691 = 0 ;
F_419 ( V_3 ) ;
F_139 ( V_1 ) ;
F_405 ( & V_1 -> V_323 ,
F_190 ) ;
F_426 ( V_63 , V_30 ) ;
if ( F_158 ( V_33 ) )
V_63 -> V_692 = V_693 ;
else
V_63 -> V_692 = V_694 ;
if ( F_427 ( V_33 ) && ! F_1 ( V_1 ) &&
( V_95 == V_212 || V_95 == V_214 || V_95 == V_216 ) )
F_428 ( V_3 ,
V_63 -> V_4 . V_4 . V_594 ) ;
if ( ! F_408 ( V_1 , V_63 ) ) {
F_137 ( V_1 ) ;
F_373 ( V_3 ) ;
goto V_695;
}
F_385 ( V_1 , V_9 ) ;
if ( F_146 ( V_33 ) && ! F_343 ( V_33 ) ) {
T_5 V_366 = F_48 ( V_696 ) ;
F_58 ( V_696 , ( V_366 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_695:
F_370 ( V_9 ) ;
return false ;
}
bool F_429 ( struct V_32 * V_33 ,
T_6 V_93 ,
enum V_95 V_95 )
{
struct V_2 * V_3 ;
struct V_30 * V_30 ;
struct V_599 * V_31 ;
struct V_63 * V_63 ;
V_3 = F_430 ( sizeof( * V_3 ) , V_219 ) ;
if ( ! V_3 )
return false ;
V_63 = F_431 () ;
if ( ! V_63 )
goto V_697;
V_30 = & V_3 -> V_4 ;
V_31 = & V_30 -> V_4 ;
if ( F_432 ( & V_33 -> V_117 , & V_30 -> V_4 ,
& V_698 , V_699 ,
L_148 , F_50 ( V_95 ) ) )
goto V_700;
V_30 -> V_701 = F_154 ;
V_30 -> V_702 = F_233 ;
V_30 -> V_692 = F_222 ;
V_30 -> V_703 = F_230 ;
V_30 -> V_704 = F_377 ;
if ( F_53 ( V_33 ) ) {
V_30 -> V_705 = F_266 ;
V_30 -> V_706 = F_263 ;
V_30 -> V_335 = F_255 ;
V_30 -> V_707 = F_240 ;
V_30 -> V_708 = F_268 ;
} else if ( F_80 ( V_33 ) ) {
V_30 -> V_705 = F_261 ;
V_30 -> V_706 = F_259 ;
V_30 -> V_335 = F_255 ;
V_30 -> V_707 = F_239 ;
} else {
V_30 -> V_706 = F_257 ;
V_30 -> V_335 = F_254 ;
if ( F_144 ( V_33 ) >= 5 )
V_30 -> V_707 = F_238 ;
}
V_3 -> V_95 = V_95 ;
V_3 -> V_600 . V_93 = V_93 ;
V_3 -> V_24 = 4 ;
V_30 -> type = V_108 ;
V_30 -> V_352 = F_433 ( V_95 ) ;
if ( F_53 ( V_33 ) ) {
if ( V_95 == V_216 )
V_30 -> V_709 = 1 << 2 ;
else
V_30 -> V_709 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_30 -> V_709 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_30 -> V_710 = 0 ;
V_30 -> V_95 = V_95 ;
V_3 -> V_711 = F_382 ;
V_33 -> V_712 . V_713 [ V_95 ] = V_3 ;
if ( ! F_422 ( V_3 , V_63 ) )
goto V_714;
return true ;
V_714:
F_376 ( V_31 ) ;
V_700:
F_138 ( V_63 ) ;
V_697:
F_138 ( V_3 ) ;
return false ;
}
void F_434 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_715 ; V_14 ++ ) {
struct V_2 * V_3 = V_33 -> V_712 . V_713 [ V_14 ] ;
if ( ! V_3 || ! V_3 -> V_600 . V_478 )
continue;
if ( V_3 -> V_600 . V_481 )
F_435 ( & V_3 -> V_600 . V_482 ) ;
}
}
void F_436 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_19 ( V_7 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_715 ; V_14 ++ ) {
struct V_2 * V_3 = V_33 -> V_712 . V_713 [ V_14 ] ;
int V_166 ;
if ( ! V_3 || ! V_3 -> V_600 . V_478 )
continue;
V_166 = F_437 ( & V_3 -> V_600 . V_482 ) ;
if ( V_166 )
F_319 ( & V_3 -> V_600 ) ;
}
}
