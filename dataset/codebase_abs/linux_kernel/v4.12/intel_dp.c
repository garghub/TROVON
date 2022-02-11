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
V_17 = V_1 -> V_19 ;
return F_10 ( V_16 , V_17 ) ;
}
int
F_11 ( int V_20 , int V_21 )
{
return F_12 ( V_20 * V_21 , 8 ) ;
}
int
F_13 ( int V_22 , int V_18 )
{
return V_22 * V_18 ;
}
static int
F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
int V_27 = V_26 -> V_28 ;
int V_29 ;
int type = V_1 -> V_30 [ 0 ] & V_31 ;
if ( type != V_32 )
return V_27 ;
V_29 = F_16 ( V_1 -> V_11 ,
V_1 -> V_30 ) ;
if ( V_29 != 0 )
V_27 = F_10 ( V_27 , V_29 ) ;
return V_27 ;
}
static int
F_17 ( struct V_1 * V_1 , const int * * V_33 )
{
if ( V_1 -> V_34 ) {
* V_33 = V_1 -> V_33 ;
return V_1 -> V_34 ;
}
* V_33 = V_35 ;
return ( V_1 -> V_36 >> 3 ) + 1 ;
}
static int
F_18 ( struct V_1 * V_1 , const int * * V_37 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
int V_39 ;
if ( F_19 ( V_26 ) ) {
* V_37 = V_40 ;
V_39 = F_20 ( V_40 ) ;
} else if ( F_21 ( V_26 ) ) {
* V_37 = V_41 ;
V_39 = F_20 ( V_41 ) ;
} else {
* V_37 = V_35 ;
V_39 = F_20 ( V_35 ) ;
}
if ( ! F_22 ( V_1 ) )
V_39 -- ;
return V_39 ;
}
static int F_23 ( const int * V_37 , int V_42 ,
const int * V_33 , int V_43 ,
int * V_44 )
{
int V_45 = 0 , V_46 = 0 , V_47 = 0 ;
while ( V_45 < V_42 && V_46 < V_43 ) {
if ( V_37 [ V_45 ] == V_33 [ V_46 ] ) {
if ( F_24 ( V_47 >= V_48 ) )
return V_47 ;
V_44 [ V_47 ] = V_37 [ V_45 ] ;
++ V_47 ;
++ V_45 ;
++ V_46 ;
} else if ( V_37 [ V_45 ] < V_33 [ V_46 ] ) {
++ V_45 ;
} else {
++ V_46 ;
}
}
return V_47 ;
}
static int F_25 ( struct V_1 * V_1 ,
int * V_44 )
{
const int * V_37 , * V_33 ;
int V_42 , V_43 ;
V_43 = F_17 ( V_1 , & V_33 ) ;
V_42 = F_18 ( V_1 , & V_37 ) ;
return F_23 ( V_37 , V_42 ,
V_33 , V_43 ,
V_44 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
int * V_44 , int V_49 )
{
int V_50 ;
int V_51 ;
V_50 = F_25 ( V_1 , V_44 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
if ( V_49 == V_44 [ V_50 - V_51 - 1 ] )
return V_50 - V_51 - 1 ;
}
return - 1 ;
}
int F_27 ( struct V_1 * V_1 ,
int V_49 , T_2 V_52 )
{
int V_44 [ V_48 ] ;
int V_53 ;
V_53 = F_26 ( V_1 ,
V_44 ,
V_49 ) ;
if ( V_53 > 0 ) {
V_1 -> V_36 = F_28 ( V_44 [ V_53 - 1 ] ) ;
V_1 -> V_19 = V_52 ;
} else if ( V_52 > 1 ) {
V_1 -> V_36 = F_7 ( V_1 ) ;
V_1 -> V_19 = V_52 >> 1 ;
} else {
F_29 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static enum V_54
F_30 ( struct V_8 * V_9 ,
struct V_55 * V_56 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_57 * V_57 = F_31 ( V_9 ) ;
struct V_55 * V_58 = V_57 -> V_59 . V_58 ;
int V_60 = V_56 -> clock ;
int V_61 , V_62 , V_18 , V_22 ;
int V_27 ;
V_27 = F_14 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_58 ) {
if ( V_56 -> V_63 > V_58 -> V_63 )
return V_64 ;
if ( V_56 -> V_65 > V_58 -> V_65 )
return V_64 ;
V_60 = V_58 -> clock ;
}
V_22 = F_32 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
V_61 = F_13 ( V_22 , V_18 ) ;
V_62 = F_11 ( V_60 , 18 ) ;
if ( V_62 > V_61 || V_60 > V_27 )
return V_66 ;
if ( V_56 -> clock < 10000 )
return V_67 ;
if ( V_56 -> V_68 & V_69 )
return V_70 ;
return V_71 ;
}
T_3 F_33 ( const T_2 * V_72 , int V_73 )
{
int V_45 ;
T_3 V_74 = 0 ;
if ( V_73 > 4 )
V_73 = 4 ;
for ( V_45 = 0 ; V_45 < V_73 ; V_45 ++ )
V_74 |= ( ( T_3 ) V_72 [ V_45 ] ) << ( ( 3 - V_45 ) * 8 ) ;
return V_74 ;
}
static void F_34 ( T_3 V_72 , T_2 * V_75 , int V_76 )
{
int V_45 ;
if ( V_76 > 4 )
V_76 = 4 ;
for ( V_45 = 0 ; V_45 < V_76 ; V_45 ++ )
V_75 [ V_45 ] = V_72 >> ( ( 3 - V_45 ) * 8 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_36 ( V_26 , V_1 -> V_77 ) ;
F_37 ( & V_26 -> V_78 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_39 ( & V_26 -> V_78 ) ;
F_40 ( V_26 , V_1 -> V_77 ) ;
}
static void
F_41 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_79 V_79 = V_1 -> V_80 ;
bool V_81 , V_82 = false ;
enum V_83 V_84 = F_42 ( V_79 ) ;
enum V_85 V_86 = F_43 ( V_79 ) ;
T_3 V_87 ;
if ( F_8 ( F_44 ( V_1 -> V_88 ) & V_89 ,
L_3 ,
F_45 ( V_79 ) , F_46 ( V_3 -> V_90 ) ) )
return;
F_47 ( L_4 ,
F_45 ( V_79 ) , F_46 ( V_3 -> V_90 ) ) ;
V_87 = F_44 ( V_1 -> V_88 ) & V_91 ;
V_87 |= V_92 | V_93 ;
V_87 |= F_48 ( 1 ) ;
V_87 |= V_94 ;
if ( F_49 ( V_26 ) )
V_87 |= F_50 ( V_79 ) ;
else if ( V_79 == V_95 )
V_87 |= V_96 ;
V_81 = F_44 ( F_51 ( V_79 ) ) & V_97 ;
if ( ! V_81 ) {
V_82 = F_49 ( V_26 ) &&
! F_52 ( V_26 , V_84 , V_86 , true ) ;
if ( F_53 ( V_26 , V_79 , F_49 ( V_26 ) ?
& V_98 [ 0 ] . V_99 : & V_100 [ 0 ] . V_99 ) ) {
F_29 ( L_5 ,
F_45 ( V_79 ) ) ;
return;
}
}
F_54 ( V_1 -> V_88 , V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
F_54 ( V_1 -> V_88 , V_87 | V_89 ) ;
F_55 ( V_1 -> V_88 ) ;
F_54 ( V_1 -> V_88 , V_87 & ~ V_89 ) ;
F_55 ( V_1 -> V_88 ) ;
if ( ! V_81 ) {
F_56 ( V_26 , V_79 ) ;
if ( V_82 )
F_52 ( V_26 , V_84 , V_86 , false ) ;
}
}
static enum V_79 F_57 ( struct V_25 * V_26 )
{
struct V_23 * V_24 ;
unsigned int V_101 = ( 1 << V_102 ) | ( 1 << V_95 ) ;
F_58 (&dev_priv->drm, encoder) {
struct V_1 * V_1 ;
if ( V_24 -> type != V_103 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
if ( V_24 -> type == V_5 ) {
F_24 ( V_1 -> V_104 != V_105 &&
V_1 -> V_104 != V_1 -> V_80 ) ;
if ( V_1 -> V_80 != V_105 )
V_101 &= ~ ( 1 << V_1 -> V_80 ) ;
} else {
F_24 ( V_1 -> V_80 != V_105 ) ;
if ( V_1 -> V_104 != V_105 )
V_101 &= ~ ( 1 << V_1 -> V_104 ) ;
}
}
if ( V_101 == 0 )
return V_105 ;
return F_59 ( V_101 ) - 1 ;
}
static enum V_79
F_60 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_79 V_79 ;
F_61 ( & V_26 -> V_78 ) ;
F_24 ( ! F_1 ( V_1 ) ) ;
F_24 ( V_1 -> V_104 != V_105 &&
V_1 -> V_104 != V_1 -> V_80 ) ;
if ( V_1 -> V_80 != V_105 )
return V_1 -> V_80 ;
V_79 = F_57 ( V_26 ) ;
if ( F_24 ( V_79 == V_105 ) )
V_79 = V_102 ;
F_62 ( V_7 , V_79 ) ;
V_1 -> V_80 = V_79 ;
F_47 ( L_6 ,
F_45 ( V_1 -> V_80 ) ,
F_46 ( V_3 -> V_90 ) ) ;
F_63 ( V_7 , V_1 ) ;
F_64 ( V_7 , V_1 , true ) ;
F_41 ( V_1 ) ;
return V_1 -> V_80 ;
}
static int
F_65 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_61 ( & V_26 -> V_78 ) ;
F_24 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_106 )
return 0 ;
V_1 -> V_106 = false ;
F_64 ( V_7 , V_1 , false ) ;
return 0 ;
}
static bool F_66 ( struct V_25 * V_26 ,
enum V_79 V_79 )
{
return F_44 ( F_67 ( V_79 ) ) & V_107 ;
}
static bool F_68 ( struct V_25 * V_26 ,
enum V_79 V_79 )
{
return F_44 ( F_69 ( V_79 ) ) & V_108 ;
}
static bool F_70 ( struct V_25 * V_26 ,
enum V_79 V_79 )
{
return true ;
}
static enum V_79
F_71 ( struct V_25 * V_26 ,
enum V_90 V_90 ,
T_4 V_109 )
{
enum V_79 V_79 ;
for ( V_79 = V_102 ; V_79 <= V_95 ; V_79 ++ ) {
T_5 V_110 = F_44 ( F_72 ( V_79 ) ) &
V_111 ;
if ( V_110 != F_73 ( V_90 ) )
continue;
if ( ! V_109 ( V_26 , V_79 ) )
continue;
return V_79 ;
}
return V_105 ;
}
static void
F_74 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
F_61 ( & V_26 -> V_78 ) ;
V_1 -> V_80 = F_71 ( V_26 , V_90 ,
F_66 ) ;
if ( V_1 -> V_80 == V_105 )
V_1 -> V_80 = F_71 ( V_26 , V_90 ,
F_68 ) ;
if ( V_1 -> V_80 == V_105 )
V_1 -> V_80 = F_71 ( V_26 , V_90 ,
F_70 ) ;
if ( V_1 -> V_80 == V_105 ) {
F_47 ( L_7 ,
F_46 ( V_90 ) ) ;
return;
}
F_47 ( L_8 ,
F_46 ( V_90 ) , F_45 ( V_1 -> V_80 ) ) ;
F_63 ( V_7 , V_1 ) ;
F_64 ( V_7 , V_1 , false ) ;
}
void F_75 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = & V_26 -> V_112 ;
struct V_23 * V_24 ;
if ( F_24 ( ! F_76 ( V_26 ) && ! F_49 ( V_26 ) &&
! F_19 ( V_26 ) ) )
return;
F_58 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_24 -> type != V_103 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
F_24 ( V_1 -> V_104 != V_105 ) ;
if ( V_24 -> type != V_5 )
continue;
if ( F_19 ( V_26 ) )
V_1 -> V_106 = true ;
else
V_1 -> V_80 = V_105 ;
}
}
static void F_77 ( struct V_25 * V_26 ,
struct V_1 * V_1 ,
struct V_113 * V_114 )
{
int V_115 = 0 ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( F_19 ( V_26 ) )
V_115 = F_65 ( V_1 ) ;
else if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
V_115 = F_60 ( V_1 ) ;
V_114 -> V_116 = F_69 ( V_115 ) ;
V_114 -> V_117 = F_67 ( V_115 ) ;
V_114 -> V_118 = F_72 ( V_115 ) ;
V_114 -> V_119 = F_78 ( V_115 ) ;
if ( ! F_19 ( V_26 ) )
V_114 -> V_120 = F_79 ( V_115 ) ;
}
static T_6
F_80 ( struct V_1 * V_1 )
{
struct V_113 V_114 ;
F_77 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_114 ) ;
return V_114 . V_116 ;
}
static T_6
F_81 ( struct V_1 * V_1 )
{
struct V_113 V_114 ;
F_77 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_114 ) ;
return V_114 . V_117 ;
}
static int F_82 ( struct V_121 * V_122 , unsigned long V_123 ,
void * V_124 )
{
struct V_1 * V_1 = F_83 ( V_122 , F_84 ( * V_1 ) ,
V_125 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_123 != V_126 )
return 0 ;
F_35 ( V_1 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
enum V_79 V_79 = F_60 ( V_1 ) ;
T_6 V_127 , V_128 ;
T_5 V_120 ;
V_127 = F_69 ( V_79 ) ;
V_128 = F_79 ( V_79 ) ;
V_120 = F_44 ( V_128 ) ;
V_120 &= V_129 ;
F_54 ( V_128 , V_120 | 0x1F ) ;
F_54 ( V_127 , V_130 | V_131 ) ;
F_85 ( V_1 -> V_132 ) ;
}
F_38 ( V_1 ) ;
return 0 ;
}
static bool F_86 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_61 ( & V_26 -> V_78 ) ;
if ( ( F_76 ( V_26 ) || F_49 ( V_26 ) ) &&
V_1 -> V_80 == V_105 )
return false ;
return ( F_44 ( F_81 ( V_1 ) ) & V_107 ) != 0 ;
}
static bool F_87 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_61 ( & V_26 -> V_78 ) ;
if ( ( F_76 ( V_26 ) || F_49 ( V_26 ) ) &&
V_1 -> V_80 == V_105 )
return false ;
return F_44 ( F_80 ( V_1 ) ) & V_108 ;
}
static void
F_88 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_86 ( V_1 ) && ! F_87 ( V_1 ) ) {
F_8 ( 1 , L_9 ) ;
F_47 ( L_10 ,
F_44 ( F_81 ( V_1 ) ) ,
F_44 ( F_80 ( V_1 ) ) ) ;
}
}
static T_3
F_89 ( struct V_1 * V_1 , bool V_133 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_6 V_134 = V_1 -> V_135 ;
T_3 V_136 ;
bool V_137 ;
#define F_90 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_133 )
V_137 = F_91 ( V_26 -> V_138 , F_90 ,
F_92 ( 10 ) ) ;
else
V_137 = F_93 ( F_90 , 10 ) == 0 ;
if ( ! V_137 )
F_29 ( L_11 ,
V_133 ) ;
#undef F_90
return V_136 ;
}
static T_3 F_94 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_51 )
return 0 ;
return F_95 ( V_26 -> V_139 , 2000 ) ;
}
static T_3 F_96 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_51 )
return 0 ;
if ( V_3 -> V_90 == V_140 )
return F_95 ( V_26 -> V_141 . V_142 . V_141 , 2000 ) ;
else
return F_95 ( V_26 -> V_139 , 2000 ) ;
}
static T_3 F_97 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_90 != V_140 && F_98 ( V_26 ) ) {
switch ( V_51 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_96 ( V_1 , V_51 ) ;
}
static T_3 F_99 ( struct V_1 * V_1 , int V_51 )
{
return V_51 ? 0 : 1 ;
}
static T_3 F_100 ( struct V_1 * V_1 ,
bool V_133 ,
int V_143 ,
T_3 V_144 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_3 V_145 , V_146 ;
if ( F_101 ( V_26 ) )
V_145 = 3 ;
else
V_145 = 5 ;
if ( F_102 ( V_26 ) && V_3 -> V_90 == V_140 )
V_146 = V_147 ;
else
V_146 = V_148 ;
return V_149 |
V_150 |
( V_133 ? V_151 : 0 ) |
V_152 |
V_146 |
V_153 |
( V_143 << V_154 ) |
( V_145 << V_155 ) |
( V_144 << V_156 ) ;
}
static T_3 F_103 ( struct V_1 * V_1 ,
bool V_133 ,
int V_143 ,
T_3 V_124 )
{
return V_149 |
V_150 |
( V_133 ? V_151 : 0 ) |
V_152 |
V_157 |
V_153 |
( V_143 << V_154 ) |
F_104 ( 32 ) |
F_105 ( 32 ) ;
}
static int
F_106 ( struct V_1 * V_1 ,
const T_2 * V_158 , int V_143 ,
T_2 * V_159 , int V_160 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_6 V_134 = V_1 -> V_135 ;
T_3 V_144 ;
int V_45 , V_161 , V_162 ;
T_3 V_136 ;
int V_163 , clock = 0 ;
bool V_133 = F_107 ( V_26 ) ;
bool V_164 ;
F_35 ( V_1 ) ;
V_164 = F_108 ( V_1 ) ;
F_109 ( & V_26 -> V_165 , 0 ) ;
F_88 ( V_1 ) ;
for ( V_163 = 0 ; V_163 < 3 ; V_163 ++ ) {
V_136 = F_110 ( V_134 ) ;
if ( ( V_136 & V_149 ) == 0 )
break;
F_85 ( 1 ) ;
}
if ( V_163 == 3 ) {
static T_5 V_166 = - 1 ;
const T_5 V_136 = F_44 ( V_134 ) ;
if ( V_136 != V_166 ) {
F_8 ( 1 , L_12 ,
V_136 ) ;
V_166 = V_136 ;
}
V_161 = - V_167 ;
goto V_168;
}
if ( F_24 ( V_143 > 20 || V_160 > 20 ) ) {
V_161 = - V_169 ;
goto V_168;
}
while ( ( V_144 = V_1 -> V_170 ( V_1 , clock ++ ) ) ) {
T_5 V_171 = V_1 -> V_172 ( V_1 ,
V_133 ,
V_143 ,
V_144 ) ;
for ( V_163 = 0 ; V_163 < 5 ; V_163 ++ ) {
for ( V_45 = 0 ; V_45 < V_143 ; V_45 += 4 )
F_54 ( V_1 -> V_173 [ V_45 >> 2 ] ,
F_33 ( V_158 + V_45 ,
V_143 - V_45 ) ) ;
F_54 ( V_134 , V_171 ) ;
V_136 = F_89 ( V_1 , V_133 ) ;
F_54 ( V_134 ,
V_136 |
V_150 |
V_152 |
V_153 ) ;
if ( V_136 & V_152 )
continue;
if ( V_136 & V_153 ) {
F_111 ( 400 , 500 ) ;
continue;
}
if ( V_136 & V_150 )
goto V_137;
}
}
if ( ( V_136 & V_150 ) == 0 ) {
F_29 ( L_13 , V_136 ) ;
V_161 = - V_167 ;
goto V_168;
}
V_137:
if ( V_136 & V_153 ) {
F_29 ( L_14 , V_136 ) ;
V_161 = - V_174 ;
goto V_168;
}
if ( V_136 & V_152 ) {
F_47 ( L_15 , V_136 ) ;
V_161 = - V_175 ;
goto V_168;
}
V_162 = ( ( V_136 & V_176 ) >>
V_154 ) ;
if ( V_162 == 0 || V_162 > 20 ) {
F_47 ( L_16 ,
V_162 ) ;
F_111 ( 1000 , 1500 ) ;
V_161 = - V_167 ;
goto V_168;
}
if ( V_162 > V_160 )
V_162 = V_160 ;
for ( V_45 = 0 ; V_45 < V_162 ; V_45 += 4 )
F_34 ( F_44 ( V_1 -> V_173 [ V_45 >> 2 ] ) ,
V_159 + V_45 , V_162 - V_45 ) ;
V_161 = V_162 ;
V_168:
F_109 ( & V_26 -> V_165 , V_177 ) ;
if ( V_164 )
F_112 ( V_1 , false ) ;
F_38 ( V_1 ) ;
return V_161 ;
}
static T_7
F_113 ( struct V_178 * V_179 , struct V_180 * V_181 )
{
struct V_1 * V_1 = F_83 ( V_179 , struct V_1 , V_179 ) ;
T_2 V_182 [ 20 ] , V_183 [ 20 ] ;
T_8 V_184 , V_185 ;
int V_161 ;
V_182 [ 0 ] = ( V_181 -> V_186 << 4 ) |
( ( V_181 -> V_187 >> 16 ) & 0xf ) ;
V_182 [ 1 ] = ( V_181 -> V_187 >> 8 ) & 0xff ;
V_182 [ 2 ] = V_181 -> V_187 & 0xff ;
V_182 [ 3 ] = V_181 -> V_39 - 1 ;
switch ( V_181 -> V_186 & ~ V_188 ) {
case V_189 :
case V_190 :
case V_191 :
V_184 = V_181 -> V_39 ? V_192 + V_181 -> V_39 : V_193 ;
V_185 = 2 ;
if ( F_24 ( V_184 > 20 ) )
return - V_169 ;
F_24 ( ! V_181 -> V_194 != ! V_181 -> V_39 ) ;
if ( V_181 -> V_194 )
memcpy ( V_182 + V_192 , V_181 -> V_194 , V_181 -> V_39 ) ;
V_161 = F_106 ( V_1 , V_182 , V_184 , V_183 , V_185 ) ;
if ( V_161 > 0 ) {
V_181 -> V_195 = V_183 [ 0 ] >> 4 ;
if ( V_161 > 1 ) {
V_161 = F_114 ( int , V_183 [ 1 ] , 0 , V_181 -> V_39 ) ;
} else {
V_161 = V_181 -> V_39 ;
}
}
break;
case V_196 :
case V_197 :
V_184 = V_181 -> V_39 ? V_192 : V_193 ;
V_185 = V_181 -> V_39 + 1 ;
if ( F_24 ( V_185 > 20 ) )
return - V_169 ;
V_161 = F_106 ( V_1 , V_182 , V_184 , V_183 , V_185 ) ;
if ( V_161 > 0 ) {
V_181 -> V_195 = V_183 [ 0 ] >> 4 ;
V_161 -- ;
memcpy ( V_181 -> V_194 , V_183 + 1 , V_161 ) ;
}
break;
default:
V_161 = - V_198 ;
break;
}
return V_161 ;
}
static enum V_90 F_115 ( struct V_25 * V_26 ,
enum V_90 V_90 )
{
const struct V_199 * V_200 =
& V_26 -> V_201 . V_202 [ V_90 ] ;
enum V_90 V_203 ;
if ( ! V_200 -> V_204 ) {
F_47 ( L_17 ,
F_46 ( V_90 ) , F_46 ( V_90 ) ) ;
return V_90 ;
}
switch ( V_200 -> V_204 ) {
case V_205 :
V_203 = V_140 ;
break;
case V_206 :
V_203 = V_207 ;
break;
case V_208 :
V_203 = V_209 ;
break;
case V_210 :
V_203 = V_211 ;
break;
default:
F_116 ( V_200 -> V_204 ) ;
V_203 = V_140 ;
break;
}
F_47 ( L_18 ,
F_46 ( V_203 ) , F_46 ( V_90 ) ) ;
return V_203 ;
}
static T_6 F_117 ( struct V_25 * V_26 ,
enum V_90 V_90 )
{
switch ( V_90 ) {
case V_207 :
case V_209 :
case V_211 :
return F_118 ( V_90 ) ;
default:
F_116 ( V_90 ) ;
return F_118 ( V_207 ) ;
}
}
static T_6 F_119 ( struct V_25 * V_26 ,
enum V_90 V_90 , int V_51 )
{
switch ( V_90 ) {
case V_207 :
case V_209 :
case V_211 :
return F_120 ( V_90 , V_51 ) ;
default:
F_116 ( V_90 ) ;
return F_120 ( V_207 , V_51 ) ;
}
}
static T_6 F_121 ( struct V_25 * V_26 ,
enum V_90 V_90 )
{
switch ( V_90 ) {
case V_140 :
return F_118 ( V_90 ) ;
case V_207 :
case V_209 :
case V_211 :
return F_122 ( V_90 ) ;
default:
F_116 ( V_90 ) ;
return F_118 ( V_140 ) ;
}
}
static T_6 F_123 ( struct V_25 * V_26 ,
enum V_90 V_90 , int V_51 )
{
switch ( V_90 ) {
case V_140 :
return F_120 ( V_90 , V_51 ) ;
case V_207 :
case V_209 :
case V_211 :
return F_124 ( V_90 , V_51 ) ;
default:
F_116 ( V_90 ) ;
return F_120 ( V_140 , V_51 ) ;
}
}
static T_6 F_125 ( struct V_25 * V_26 ,
enum V_90 V_90 )
{
switch ( V_90 ) {
case V_140 :
case V_207 :
case V_209 :
case V_211 :
return F_118 ( V_90 ) ;
default:
F_116 ( V_90 ) ;
return F_118 ( V_140 ) ;
}
}
static T_6 F_126 ( struct V_25 * V_26 ,
enum V_90 V_90 , int V_51 )
{
switch ( V_90 ) {
case V_140 :
case V_207 :
case V_209 :
case V_211 :
return F_120 ( V_90 , V_51 ) ;
default:
F_116 ( V_90 ) ;
return F_120 ( V_140 , V_51 ) ;
}
}
static T_6 F_127 ( struct V_25 * V_26 ,
enum V_90 V_90 )
{
if ( F_128 ( V_26 ) -> V_212 >= 9 )
return F_125 ( V_26 , V_90 ) ;
else if ( F_129 ( V_26 ) )
return F_121 ( V_26 , V_90 ) ;
else
return F_117 ( V_26 , V_90 ) ;
}
static T_6 F_130 ( struct V_25 * V_26 ,
enum V_90 V_90 , int V_51 )
{
if ( F_128 ( V_26 ) -> V_212 >= 9 )
return F_126 ( V_26 , V_90 , V_51 ) ;
else if ( F_129 ( V_26 ) )
return F_123 ( V_26 , V_90 , V_51 ) ;
else
return F_119 ( V_26 , V_90 , V_51 ) ;
}
static void F_131 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_90 V_90 = F_115 ( V_26 ,
F_2 ( V_1 ) -> V_90 ) ;
int V_45 ;
V_1 -> V_135 = F_127 ( V_26 , V_90 ) ;
for ( V_45 = 0 ; V_45 < F_20 ( V_1 -> V_173 ) ; V_45 ++ )
V_1 -> V_173 [ V_45 ] = F_130 ( V_26 , V_90 , V_45 ) ;
}
static void
F_132 ( struct V_1 * V_1 )
{
F_133 ( V_1 -> V_179 . V_213 ) ;
}
static void
F_134 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
F_131 ( V_1 ) ;
F_135 ( & V_1 -> V_179 ) ;
V_1 -> V_179 . V_213 = F_136 ( V_214 , L_19 , F_46 ( V_90 ) ) ;
V_1 -> V_179 . V_215 = F_113 ;
}
bool F_22 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
if ( ( F_137 ( V_26 ) && ! F_138 ( V_26 ) ) ||
F_102 ( V_26 ) || ( F_139 ( V_26 ) >= 9 ) )
return true ;
else
return false ;
}
static void
F_140 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
const struct V_218 * V_219 = NULL ;
int V_45 , V_220 = 0 ;
if ( F_141 ( V_26 ) ) {
V_219 = V_221 ;
V_220 = F_20 ( V_221 ) ;
} else if ( F_129 ( V_26 ) ) {
V_219 = V_222 ;
V_220 = F_20 ( V_222 ) ;
} else if ( F_49 ( V_26 ) ) {
V_219 = V_98 ;
V_220 = F_20 ( V_98 ) ;
} else if ( F_76 ( V_26 ) ) {
V_219 = V_100 ;
V_220 = F_20 ( V_100 ) ;
}
if ( V_219 && V_220 ) {
for ( V_45 = 0 ; V_45 < V_220 ; V_45 ++ ) {
if ( V_217 -> V_223 == V_219 [ V_45 ] . clock ) {
V_217 -> V_99 = V_219 [ V_45 ] . V_99 ;
V_217 -> V_224 = true ;
break;
}
}
}
}
static void F_142 ( char * V_225 , T_8 V_226 ,
const int * V_227 , int V_228 )
{
int V_45 ;
V_225 [ 0 ] = '\0' ;
for ( V_45 = 0 ; V_45 < V_228 ; V_45 ++ ) {
int V_229 = snprintf ( V_225 , V_226 , L_20 , V_45 ? L_21 : L_22 , V_227 [ V_45 ] ) ;
if ( V_229 >= V_226 )
return;
V_225 += V_229 ;
V_226 -= V_229 ;
}
}
static void F_143 ( struct V_1 * V_1 )
{
const int * V_37 , * V_33 ;
int V_42 , V_43 , V_50 ;
int V_44 [ V_48 ] ;
char V_225 [ 128 ] ;
if ( ( V_230 & V_231 ) == 0 )
return;
V_42 = F_18 ( V_1 , & V_37 ) ;
F_142 ( V_225 , sizeof( V_225 ) , V_37 , V_42 ) ;
F_47 ( L_23 , V_225 ) ;
V_43 = F_17 ( V_1 , & V_33 ) ;
F_142 ( V_225 , sizeof( V_225 ) , V_33 , V_43 ) ;
F_47 ( L_24 , V_225 ) ;
V_50 = F_25 ( V_1 , V_44 ) ;
F_142 ( V_225 , sizeof( V_225 ) , V_44 , V_50 ) ;
F_47 ( L_25 , V_225 ) ;
}
static int F_144 ( int V_232 , const int * V_233 )
{
int V_45 = 0 ;
for ( V_45 = 0 ; V_45 < V_48 ; ++ V_45 )
if ( V_232 == V_233 [ V_45 ] )
break;
return V_45 ;
}
int
F_32 ( struct V_1 * V_1 )
{
int V_233 [ V_48 ] = {} ;
int V_226 ;
V_226 = F_25 ( V_1 , V_233 ) ;
if ( F_24 ( V_226 <= 0 ) )
return 162000 ;
return V_233 [ V_226 - 1 ] ;
}
int F_145 ( struct V_1 * V_1 , int V_234 )
{
return F_144 ( V_234 , V_1 -> V_33 ) ;
}
void F_146 ( struct V_1 * V_1 , int V_223 ,
T_2 * V_235 , T_2 * V_236 )
{
if ( V_1 -> V_34 ) {
* V_235 = 0 ;
* V_236 =
F_145 ( V_1 , V_223 ) ;
} else {
* V_235 = F_28 ( V_223 ) ;
* V_236 = 0 ;
}
}
static int F_147 ( struct V_1 * V_1 ,
struct V_216 * V_217 )
{
int V_21 , V_237 ;
V_21 = V_217 -> V_238 ;
V_237 = F_148 ( V_1 -> V_11 , V_1 -> V_30 ) ;
if ( V_237 > 0 )
V_21 = F_10 ( V_21 , 3 * V_237 ) ;
if ( V_1 -> V_239 . V_240 . V_237 != 0 ) {
V_217 -> V_238 = 3 * V_1 -> V_239 . V_240 . V_237 ;
V_217 -> V_241 = V_217 -> V_238 == 6 * 3 ;
F_47 ( L_26 ,
V_217 -> V_238 ) ;
}
return V_21 ;
}
bool
F_149 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
struct V_55 * V_244 = & V_217 -> V_4 . V_244 ;
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
struct V_245 * V_245 = F_150 ( V_217 -> V_4 . V_246 ) ;
struct V_57 * V_57 = V_1 -> V_247 ;
int V_52 , clock ;
int V_248 = 1 ;
int V_249 = F_9 ( V_1 ) ;
int V_250 = 0 ;
int V_251 ;
int V_53 ;
int V_21 , V_62 ;
int V_252 , V_253 ;
int V_44 [ V_48 ] = {} ;
int V_50 ;
T_2 V_235 , V_236 ;
bool V_254 = F_151 ( & V_1 -> V_255 ,
V_256 ) ;
V_50 = F_25 ( V_1 , V_44 ) ;
F_24 ( V_50 <= 0 ) ;
V_251 = V_50 - 1 ;
if ( F_129 ( V_26 ) && ! F_152 ( V_26 ) && V_90 != V_140 )
V_217 -> V_257 = true ;
V_217 -> V_258 = false ;
V_217 -> V_259 = V_1 -> V_259 && V_90 != V_140 ;
if ( F_1 ( V_1 ) && V_57 -> V_59 . V_58 ) {
F_153 ( V_57 -> V_59 . V_58 ,
V_244 ) ;
if ( F_139 ( V_26 ) >= 9 ) {
int V_161 ;
V_161 = F_154 ( V_217 ) ;
if ( V_161 )
return V_161 ;
}
if ( F_155 ( V_26 ) )
F_156 ( V_245 , V_217 ,
V_57 -> V_59 . V_260 ) ;
else
F_157 ( V_245 , V_217 ,
V_57 -> V_59 . V_260 ) ;
}
if ( V_244 -> V_68 & V_69 )
return false ;
if ( V_1 -> V_239 . V_261 == V_262 ) {
V_53 = F_26 ( V_1 ,
V_44 ,
V_1 -> V_239 . V_263 ) ;
if ( V_53 >= 0 )
V_250 = V_251 = V_53 ;
V_248 = V_249 = V_1 -> V_239 . V_264 ;
}
F_47 ( L_27
L_28 ,
V_249 , V_44 [ V_251 ] ,
V_244 -> V_265 ) ;
V_21 = F_147 ( V_1 , V_217 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_57 -> V_4 . V_266 . V_237 == 0 &&
( V_26 -> V_201 . V_267 . V_21 && V_26 -> V_201 . V_267 . V_21 < V_21 ) ) {
F_47 ( L_29 ,
V_26 -> V_201 . V_267 . V_21 ) ;
V_21 = V_26 -> V_201 . V_267 . V_21 ;
}
V_248 = V_249 ;
V_250 = V_251 ;
}
for (; V_21 >= 6 * 3 ; V_21 -= 2 * 3 ) {
V_62 = F_11 ( V_244 -> V_265 ,
V_21 ) ;
for ( clock = V_250 ; clock <= V_251 ; clock ++ ) {
for ( V_52 = V_248 ;
V_52 <= V_249 ;
V_52 <<= 1 ) {
V_253 = V_44 [ clock ] ;
V_252 = F_13 ( V_253 ,
V_52 ) ;
if ( V_62 <= V_252 ) {
goto V_268;
}
}
}
}
return false ;
V_268:
if ( V_1 -> V_269 ) {
V_217 -> V_270 =
V_21 != 18 &&
F_158 ( V_244 ) ==
V_271 ;
} else {
V_217 -> V_270 =
V_1 -> V_270 ;
}
V_217 -> V_52 = V_52 ;
V_217 -> V_238 = V_21 ;
V_217 -> V_223 = V_44 [ clock ] ;
F_146 ( V_1 , V_217 -> V_223 ,
& V_235 , & V_236 ) ;
F_47 ( L_30 ,
V_235 , V_236 , V_217 -> V_52 ,
V_217 -> V_223 , V_21 ) ;
F_47 ( L_31 ,
V_62 , V_252 ) ;
F_159 ( V_21 , V_52 ,
V_244 -> V_265 ,
V_217 -> V_223 ,
& V_217 -> V_272 ,
V_254 ) ;
if ( V_57 -> V_59 . V_273 != NULL &&
V_26 -> V_274 . type == V_275 ) {
V_217 -> V_258 = true ;
F_159 ( V_21 , V_52 ,
V_57 -> V_59 . V_273 -> clock ,
V_217 -> V_223 ,
& V_217 -> V_276 ,
V_254 ) ;
}
if ( F_1 ( V_1 ) && F_21 ( V_26 ) ) {
int V_277 ;
switch ( V_217 -> V_223 / 2 ) {
case 108000 :
case 216000 :
V_277 = 8640000 ;
break;
default:
V_277 = 8100000 ;
break;
}
F_160 ( V_217 -> V_4 . V_278 ) -> V_141 . V_279 . V_277 = V_277 ;
}
if ( ! F_152 ( V_26 ) )
F_140 ( V_24 , V_217 ) ;
return true ;
}
void F_161 ( struct V_1 * V_1 ,
int V_49 , T_2 V_52 ,
bool V_280 )
{
V_1 -> V_49 = V_49 ;
V_1 -> V_52 = V_52 ;
V_1 -> V_280 = V_280 ;
}
static void F_162 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
struct V_245 * V_246 = F_150 ( V_24 -> V_4 . V_246 ) ;
const struct V_55 * V_244 = & V_217 -> V_4 . V_244 ;
F_161 ( V_1 , V_217 -> V_223 ,
V_217 -> V_52 ,
F_163 ( V_217 ,
V_281 ) ) ;
V_1 -> V_87 = F_44 ( V_1 -> V_88 ) & V_91 ;
V_1 -> V_87 |= V_92 | V_93 ;
V_1 -> V_87 |= F_48 ( V_217 -> V_52 ) ;
if ( F_164 ( V_26 ) && V_90 == V_140 ) {
if ( V_244 -> V_68 & V_282 )
V_1 -> V_87 |= V_283 ;
if ( V_244 -> V_68 & V_284 )
V_1 -> V_87 |= V_285 ;
V_1 -> V_87 |= V_286 ;
if ( F_165 ( V_1 -> V_11 ) )
V_1 -> V_87 |= V_287 ;
V_1 -> V_87 |= V_246 -> V_79 << 29 ;
} else if ( F_166 ( V_26 ) && V_90 != V_140 ) {
T_5 V_288 ;
V_1 -> V_87 |= V_286 ;
V_288 = F_44 ( F_167 ( V_246 -> V_79 ) ) ;
if ( F_165 ( V_1 -> V_11 ) )
V_288 |= V_289 ;
else
V_288 &= ~ V_289 ;
F_54 ( F_167 ( V_246 -> V_79 ) , V_288 ) ;
} else {
if ( F_141 ( V_26 ) && V_217 -> V_270 )
V_1 -> V_87 |= V_290 ;
if ( V_244 -> V_68 & V_282 )
V_1 -> V_87 |= V_283 ;
if ( V_244 -> V_68 & V_284 )
V_1 -> V_87 |= V_285 ;
V_1 -> V_87 |= V_291 ;
if ( F_165 ( V_1 -> V_11 ) )
V_1 -> V_87 |= V_287 ;
if ( F_49 ( V_26 ) )
V_1 -> V_87 |= F_50 ( V_246 -> V_79 ) ;
else if ( V_246 -> V_79 == V_95 )
V_1 -> V_87 |= V_96 ;
}
}
static void F_168 ( struct V_1 * V_1 ,
T_5 V_292 ,
T_5 V_293 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_6 V_294 , V_127 ;
F_61 ( & V_26 -> V_78 ) ;
F_169 ( V_26 , V_1 ) ;
V_294 = F_81 ( V_1 ) ;
V_127 = F_80 ( V_1 ) ;
F_47 ( L_32 ,
V_292 , V_293 ,
F_44 ( V_294 ) ,
F_44 ( V_127 ) ) ;
if ( F_170 ( V_26 ,
V_294 , V_292 , V_293 ,
5000 ) )
F_29 ( L_33 ,
F_44 ( V_294 ) ,
F_44 ( V_127 ) ) ;
F_47 ( L_34 ) ;
}
static void F_171 ( struct V_1 * V_1 )
{
F_47 ( L_35 ) ;
F_168 ( V_1 , V_295 , V_296 ) ;
}
static void F_172 ( struct V_1 * V_1 )
{
F_47 ( L_36 ) ;
F_168 ( V_1 , V_297 , V_298 ) ;
}
static void F_173 ( struct V_1 * V_1 )
{
T_9 V_299 ;
T_10 V_300 ;
F_47 ( L_37 ) ;
V_299 = F_174 () ;
V_300 = F_175 ( V_299 , V_1 -> V_301 ) ;
if ( V_300 < ( T_10 ) V_1 -> V_132 )
F_176 ( V_302 ,
V_1 -> V_132 - V_300 ) ;
F_168 ( V_1 , V_303 , V_304 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_305 ,
V_1 -> V_306 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_176 ( V_1 -> V_307 ,
V_1 -> V_308 ) ;
}
static T_5 F_179 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_309 ;
F_61 ( & V_26 -> V_78 ) ;
V_309 = F_44 ( F_80 ( V_1 ) ) ;
if ( F_24 ( ! F_152 ( V_26 ) &&
( V_309 & V_310 ) != V_130 ) ) {
V_309 &= ~ V_310 ;
V_309 |= V_130 ;
}
return V_309 ;
}
static bool F_108 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_311 ;
T_6 V_294 , V_127 ;
bool V_312 = ! V_1 -> V_313 ;
F_61 ( & V_26 -> V_78 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_180 ( & V_1 -> V_314 ) ;
V_1 -> V_313 = true ;
if ( F_87 ( V_1 ) )
return V_312 ;
F_36 ( V_26 , V_1 -> V_77 ) ;
F_47 ( L_38 ,
F_46 ( V_3 -> V_90 ) ) ;
if ( ! F_86 ( V_1 ) )
F_173 ( V_1 ) ;
V_311 = F_179 ( V_1 ) ;
V_311 |= V_108 ;
V_294 = F_81 ( V_1 ) ;
V_127 = F_80 ( V_1 ) ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
F_47 ( L_39 ,
F_44 ( V_294 ) , F_44 ( V_127 ) ) ;
if ( ! F_86 ( V_1 ) ) {
F_47 ( L_40 ,
F_46 ( V_3 -> V_90 ) ) ;
F_85 ( V_1 -> V_315 ) ;
}
return V_312 ;
}
void F_181 ( struct V_1 * V_1 )
{
bool V_164 ;
if ( ! F_1 ( V_1 ) )
return;
F_35 ( V_1 ) ;
V_164 = F_108 ( V_1 ) ;
F_38 ( V_1 ) ;
F_182 ( ! V_164 , L_41 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
T_5 V_311 ;
T_6 V_294 , V_127 ;
F_61 ( & V_26 -> V_78 ) ;
F_24 ( V_1 -> V_313 ) ;
if ( ! F_87 ( V_1 ) )
return;
F_47 ( L_42 ,
F_46 ( V_3 -> V_90 ) ) ;
V_311 = F_179 ( V_1 ) ;
V_311 &= ~ V_108 ;
V_127 = F_80 ( V_1 ) ;
V_294 = F_81 ( V_1 ) ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
F_47 ( L_39 ,
F_44 ( V_294 ) , F_44 ( V_127 ) ) ;
if ( ( V_311 & V_316 ) == 0 )
V_1 -> V_301 = F_174 () ;
F_40 ( V_26 , V_1 -> V_77 ) ;
}
static void F_184 ( struct V_317 * V_318 )
{
struct V_1 * V_1 = F_83 ( F_185 ( V_318 ) ,
struct V_1 , V_314 ) ;
F_35 ( V_1 ) ;
if ( ! V_1 -> V_313 )
F_183 ( V_1 ) ;
F_38 ( V_1 ) ;
}
static void F_186 ( struct V_1 * V_1 )
{
unsigned long V_319 ;
V_319 = F_187 ( V_1 -> V_132 * 5 ) ;
F_188 ( & V_1 -> V_314 , V_319 ) ;
}
static void F_112 ( struct V_1 * V_1 , bool V_320 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
F_61 ( & V_26 -> V_78 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_182 ( ! V_1 -> V_313 , L_43 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) ;
V_1 -> V_313 = false ;
if ( V_320 )
F_183 ( V_1 ) ;
else
F_186 ( V_1 ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_311 ;
T_6 V_127 ;
F_61 ( & V_26 -> V_78 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_47 ( L_44 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) ;
if ( F_8 ( F_86 ( V_1 ) ,
L_45 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) )
return;
F_173 ( V_1 ) ;
V_127 = F_80 ( V_1 ) ;
V_311 = F_179 ( V_1 ) ;
if ( F_190 ( V_26 ) ) {
V_311 &= ~ V_321 ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
}
V_311 |= V_316 ;
if ( ! F_190 ( V_26 ) )
V_311 |= V_321 ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
F_171 ( V_1 ) ;
V_1 -> V_305 = V_302 ;
if ( F_190 ( V_26 ) ) {
V_311 |= V_321 ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
}
}
void F_191 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_35 ( V_1 ) ;
F_189 ( V_1 ) ;
F_38 ( V_1 ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_311 ;
T_6 V_127 ;
F_61 ( & V_26 -> V_78 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_47 ( L_46 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) ;
F_8 ( ! V_1 -> V_313 , L_47 ,
F_46 ( F_2 ( V_1 ) -> V_90 ) ) ;
V_311 = F_179 ( V_1 ) ;
V_311 &= ~ ( V_316 | V_321 | V_108 |
V_322 ) ;
V_127 = F_80 ( V_1 ) ;
V_1 -> V_313 = false ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
V_1 -> V_301 = F_174 () ;
F_172 ( V_1 ) ;
F_40 ( V_26 , V_1 -> V_77 ) ;
}
void F_193 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_35 ( V_1 ) ;
F_192 ( V_1 ) ;
F_38 ( V_1 ) ;
}
static void F_194 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_311 ;
T_6 V_127 ;
F_177 ( V_1 ) ;
F_35 ( V_1 ) ;
V_311 = F_179 ( V_1 ) ;
V_311 |= V_322 ;
V_127 = F_80 ( V_1 ) ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
F_38 ( V_1 ) ;
}
void F_195 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_47 ( L_48 ) ;
F_196 ( V_1 -> V_247 ) ;
F_194 ( V_1 ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_311 ;
T_6 V_127 ;
if ( ! F_1 ( V_1 ) )
return;
F_35 ( V_1 ) ;
V_311 = F_179 ( V_1 ) ;
V_311 &= ~ V_322 ;
V_127 = F_80 ( V_1 ) ;
F_54 ( V_127 , V_311 ) ;
F_55 ( V_127 ) ;
F_38 ( V_1 ) ;
V_1 -> V_307 = V_302 ;
F_178 ( V_1 ) ;
}
void F_198 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_47 ( L_48 ) ;
F_197 ( V_1 ) ;
F_199 ( V_1 -> V_247 ) ;
}
static void F_200 ( struct V_57 * V_9 ,
bool V_323 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_324 ;
F_35 ( V_1 ) ;
V_324 = F_179 ( V_1 ) & V_322 ;
F_38 ( V_1 ) ;
if ( V_324 == V_323 )
return;
F_47 ( L_49 ,
V_323 ? L_50 : L_51 ) ;
if ( V_323 )
F_194 ( V_1 ) ;
else
F_197 ( V_1 ) ;
}
static void F_201 ( struct V_1 * V_1 , bool V_278 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
bool V_325 = F_44 ( V_1 -> V_88 ) & V_89 ;
F_182 ( V_325 != V_278 ,
L_52 ,
F_46 ( V_38 -> V_90 ) ,
F_202 ( V_278 ) , F_202 ( V_325 ) ) ;
}
static void F_203 ( struct V_25 * V_26 , bool V_278 )
{
bool V_325 = F_44 ( V_326 ) & V_327 ;
F_182 ( V_325 != V_278 ,
L_53 ,
F_202 ( V_278 ) , F_202 ( V_325 ) ) ;
}
static void F_204 ( struct V_1 * V_1 ,
struct V_216 * V_217 )
{
struct V_245 * V_246 = F_150 ( V_217 -> V_4 . V_246 ) ;
struct V_25 * V_26 = F_15 ( V_246 -> V_4 . V_7 ) ;
F_205 ( V_26 , V_246 -> V_79 ) ;
F_206 ( V_1 ) ;
F_207 ( V_26 ) ;
F_47 ( L_54 ,
V_217 -> V_223 ) ;
V_1 -> V_87 &= ~ V_328 ;
if ( V_217 -> V_223 == 162000 )
V_1 -> V_87 |= V_329 ;
else
V_1 -> V_87 |= V_330 ;
F_54 ( V_326 , V_1 -> V_87 ) ;
F_55 ( V_326 ) ;
F_208 ( 500 ) ;
if ( F_190 ( V_26 ) )
F_209 ( V_26 , ! V_246 -> V_79 ) ;
V_1 -> V_87 |= V_327 ;
F_54 ( V_326 , V_1 -> V_87 ) ;
F_55 ( V_326 ) ;
F_208 ( 200 ) ;
}
static void F_210 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_245 * V_246 = F_150 ( V_3 -> V_4 . V_4 . V_246 ) ;
struct V_25 * V_26 = F_15 ( V_246 -> V_4 . V_7 ) ;
F_205 ( V_26 , V_246 -> V_79 ) ;
F_206 ( V_1 ) ;
F_211 ( V_26 ) ;
F_47 ( L_55 ) ;
V_1 -> V_87 &= ~ V_327 ;
F_54 ( V_326 , V_1 -> V_87 ) ;
F_55 ( V_326 ) ;
F_208 ( 200 ) ;
}
void F_212 ( struct V_1 * V_1 , int V_56 )
{
int V_161 , V_45 ;
if ( V_1 -> V_11 [ V_331 ] < 0x11 )
return;
if ( V_56 != V_332 ) {
V_161 = F_213 ( & V_1 -> V_179 , V_333 ,
V_334 ) ;
} else {
struct V_335 * V_336 = F_214 ( V_1 ) ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_161 = F_213 ( & V_1 -> V_179 , V_333 ,
V_337 ) ;
if ( V_161 == 1 )
break;
F_85 ( 1 ) ;
}
if ( V_161 == 1 && V_336 -> V_338 )
F_215 ( V_336 ) ;
}
if ( V_161 != 1 )
F_47 ( L_56 ,
V_56 == V_332 ? L_50 : L_51 ) ;
}
static bool F_216 ( struct V_23 * V_24 ,
enum V_79 * V_79 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_339 ;
bool V_161 ;
if ( ! F_217 ( V_26 ,
V_24 -> V_340 ) )
return false ;
V_161 = false ;
V_339 = F_44 ( V_1 -> V_88 ) ;
if ( ! ( V_339 & V_89 ) )
goto V_168;
if ( F_164 ( V_26 ) && V_90 == V_140 ) {
* V_79 = F_218 ( V_339 ) ;
} else if ( F_166 ( V_26 ) && V_90 != V_140 ) {
enum V_79 V_341 ;
F_219 (dev_priv, p) {
T_5 V_288 = F_44 ( F_167 ( V_341 ) ) ;
if ( F_220 ( V_288 ) == V_90 ) {
* V_79 = V_341 ;
V_161 = true ;
goto V_168;
}
}
F_47 ( L_57 ,
F_221 ( V_1 -> V_88 ) ) ;
} else if ( F_49 ( V_26 ) ) {
* V_79 = F_222 ( V_339 ) ;
} else {
* V_79 = F_223 ( V_339 ) ;
}
V_161 = true ;
V_168:
F_40 ( V_26 , V_24 -> V_340 ) ;
return V_161 ;
}
static void F_224 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
T_5 V_339 , V_68 = 0 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
struct V_245 * V_246 = F_150 ( V_24 -> V_4 . V_246 ) ;
V_339 = F_44 ( V_1 -> V_88 ) ;
V_217 -> V_259 = V_339 & V_342 && V_90 != V_140 ;
if ( F_166 ( V_26 ) && V_90 != V_140 ) {
T_5 V_288 = F_44 ( F_167 ( V_246 -> V_79 ) ) ;
if ( V_288 & V_343 )
V_68 |= V_282 ;
else
V_68 |= V_344 ;
if ( V_288 & V_345 )
V_68 |= V_284 ;
else
V_68 |= V_346 ;
} else {
if ( V_339 & V_283 )
V_68 |= V_282 ;
else
V_68 |= V_344 ;
if ( V_339 & V_285 )
V_68 |= V_284 ;
else
V_68 |= V_346 ;
}
V_217 -> V_4 . V_244 . V_68 |= V_68 ;
if ( F_141 ( V_26 ) && V_339 & V_290 )
V_217 -> V_270 = true ;
V_217 -> V_52 =
( ( V_339 & V_347 ) >> V_348 ) + 1 ;
F_225 ( V_246 , V_217 ) ;
if ( V_90 == V_140 ) {
if ( ( F_44 ( V_326 ) & V_328 ) == V_329 )
V_217 -> V_223 = 162000 ;
else
V_217 -> V_223 = 270000 ;
}
V_217 -> V_4 . V_244 . V_265 =
F_226 ( V_217 -> V_223 ,
& V_217 -> V_272 ) ;
if ( F_1 ( V_1 ) && V_26 -> V_201 . V_267 . V_21 &&
V_217 -> V_238 > V_26 -> V_201 . V_267 . V_21 ) {
F_47 ( L_58 ,
V_217 -> V_238 , V_26 -> V_201 . V_267 . V_21 ) ;
V_26 -> V_201 . V_267 . V_21 = V_217 -> V_238 ;
}
}
static void F_227 ( struct V_23 * V_24 ,
struct V_216 * V_349 ,
struct V_242 * V_350 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
if ( V_349 -> V_259 )
F_228 ( V_24 ) ;
if ( F_229 ( V_26 ) && ! F_152 ( V_26 ) )
F_230 ( V_1 ) ;
F_181 ( V_1 ) ;
F_198 ( V_1 ) ;
F_212 ( V_1 , V_351 ) ;
F_193 ( V_1 ) ;
if ( F_139 ( V_26 ) < 5 )
F_231 ( V_1 ) ;
}
static void F_232 ( struct V_23 * V_24 ,
struct V_216 * V_349 ,
struct V_242 * V_350 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
F_231 ( V_1 ) ;
if ( V_90 == V_140 )
F_210 ( V_1 ) ;
}
static void F_233 ( struct V_23 * V_24 ,
struct V_216 * V_349 ,
struct V_242 * V_350 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_231 ( V_1 ) ;
}
static void F_234 ( struct V_23 * V_24 ,
struct V_216 * V_349 ,
struct V_242 * V_350 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_231 ( V_1 ) ;
F_37 ( & V_26 -> V_352 ) ;
F_235 ( V_24 , true ) ;
F_39 ( & V_26 -> V_352 ) ;
}
static void
F_236 ( struct V_1 * V_1 ,
T_3 * V_87 ,
T_2 V_353 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
if ( V_353 & V_354 )
F_47 ( L_59 ,
V_353 & V_354 ) ;
if ( F_152 ( V_26 ) ) {
T_3 V_355 = F_44 ( F_237 ( V_90 ) ) ;
if ( V_353 & V_356 )
V_355 |= V_357 ;
else
V_355 &= ~ V_357 ;
V_355 &= ~ V_358 ;
switch ( V_353 & V_354 ) {
case V_359 :
V_355 |= V_360 ;
break;
case V_361 :
V_355 |= V_362 ;
break;
case V_363 :
V_355 |= V_364 ;
break;
case V_365 :
V_355 |= V_366 ;
break;
}
F_54 ( F_237 ( V_90 ) , V_355 ) ;
} else if ( ( F_164 ( V_26 ) && V_90 == V_140 ) ||
( F_166 ( V_26 ) && V_90 != V_140 ) ) {
* V_87 &= ~ V_367 ;
switch ( V_353 & V_354 ) {
case V_359 :
* V_87 |= V_286 ;
break;
case V_361 :
* V_87 |= V_368 ;
break;
case V_363 :
* V_87 |= V_369 ;
break;
case V_365 :
F_47 ( L_60 ) ;
* V_87 |= V_369 ;
break;
}
} else {
if ( F_49 ( V_26 ) )
* V_87 &= ~ V_370 ;
else
* V_87 &= ~ V_371 ;
switch ( V_353 & V_354 ) {
case V_359 :
* V_87 |= V_291 ;
break;
case V_361 :
* V_87 |= V_94 ;
break;
case V_363 :
* V_87 |= V_372 ;
break;
case V_365 :
if ( F_49 ( V_26 ) ) {
* V_87 |= V_373 ;
} else {
F_47 ( L_60 ) ;
* V_87 |= V_372 ;
}
break;
}
}
}
static void F_238 ( struct V_1 * V_1 ,
struct V_216 * V_349 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_239 ( V_1 , V_361 ) ;
V_1 -> V_87 |= V_89 ;
if ( V_349 -> V_259 )
V_1 -> V_87 |= V_342 ;
F_54 ( V_1 -> V_88 , V_1 -> V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
}
static void F_240 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_245 * V_246 = F_150 ( V_24 -> V_4 . V_246 ) ;
T_3 V_374 = F_44 ( V_1 -> V_88 ) ;
enum V_79 V_79 = V_246 -> V_79 ;
if ( F_24 ( V_374 & V_89 ) )
return;
F_35 ( V_1 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
F_241 ( V_1 ) ;
F_238 ( V_1 , V_217 ) ;
F_108 ( V_1 ) ;
F_189 ( V_1 ) ;
F_112 ( V_1 , true ) ;
F_38 ( V_1 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
unsigned int V_375 = 0x0 ;
if ( F_49 ( V_26 ) )
V_375 = F_242 ( V_217 -> V_52 ) ;
F_243 ( V_26 , F_2 ( V_1 ) ,
V_375 ) ;
}
F_212 ( V_1 , V_332 ) ;
F_244 ( V_1 ) ;
F_245 ( V_1 ) ;
if ( V_217 -> V_259 ) {
F_246 ( L_61 ,
F_45 ( V_79 ) ) ;
F_247 ( V_24 , V_217 , V_243 ) ;
}
}
static void F_248 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_240 ( V_24 , V_217 , V_243 ) ;
F_195 ( V_1 ) ;
}
static void F_249 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_195 ( V_1 ) ;
F_250 ( V_1 ) ;
}
static void F_251 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
F_162 ( V_24 , V_217 ) ;
if ( V_90 == V_140 )
F_204 ( V_1 , V_217 ) ;
}
static void F_252 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_79 V_79 = V_1 -> V_80 ;
T_6 V_376 = F_72 ( V_79 ) ;
F_24 ( V_1 -> V_104 != V_105 ) ;
if ( F_24 ( V_79 != V_102 && V_79 != V_95 ) )
return;
F_183 ( V_1 ) ;
F_47 ( L_62 ,
F_45 ( V_79 ) , F_46 ( V_3 -> V_90 ) ) ;
F_54 ( V_376 , 0 ) ;
F_55 ( V_376 ) ;
V_1 -> V_80 = V_105 ;
}
static void F_62 ( struct V_6 * V_7 ,
enum V_79 V_79 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_23 * V_24 ;
F_61 ( & V_26 -> V_78 ) ;
F_58 (dev, encoder) {
struct V_1 * V_1 ;
enum V_90 V_90 ;
if ( V_24 -> type != V_103 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
V_90 = F_2 ( V_1 ) -> V_90 ;
F_8 ( V_1 -> V_104 == V_79 ,
L_63 ,
F_45 ( V_79 ) , F_46 ( V_90 ) ) ;
if ( V_1 -> V_80 != V_79 )
continue;
F_47 ( L_64 ,
F_45 ( V_79 ) , F_46 ( V_90 ) ) ;
F_252 ( V_1 ) ;
}
}
static void F_241 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_245 * V_246 = F_150 ( V_24 -> V_4 . V_246 ) ;
F_61 ( & V_26 -> V_78 ) ;
F_24 ( V_1 -> V_104 != V_105 ) ;
if ( V_1 -> V_80 != V_105 &&
V_1 -> V_80 != V_246 -> V_79 ) {
F_252 ( V_1 ) ;
}
F_62 ( V_7 , V_246 -> V_79 ) ;
V_1 -> V_104 = V_246 -> V_79 ;
if ( ! F_1 ( V_1 ) )
return;
V_1 -> V_80 = V_246 -> V_79 ;
F_47 ( L_65 ,
F_45 ( V_1 -> V_80 ) , F_46 ( V_3 -> V_90 ) ) ;
F_63 ( V_7 , V_1 ) ;
F_64 ( V_7 , V_1 , true ) ;
}
static void F_253 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
F_254 ( V_24 ) ;
F_240 ( V_24 , V_217 , V_243 ) ;
}
static void F_255 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
F_162 ( V_24 , V_217 ) ;
F_256 ( V_24 ) ;
}
static void F_257 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
F_258 ( V_24 ) ;
F_240 ( V_24 , V_217 , V_243 ) ;
F_259 ( V_24 ) ;
}
static void F_260 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
F_162 ( V_24 , V_217 ) ;
F_261 ( V_24 ) ;
}
static void F_262 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_242 * V_243 )
{
F_263 ( V_24 ) ;
}
bool
F_264 ( struct V_1 * V_1 , T_2 V_377 [ V_378 ] )
{
return F_265 ( & V_1 -> V_179 , V_379 , V_377 ,
V_378 ) == V_378 ;
}
static bool F_266 ( struct V_1 * V_1 )
{
T_2 V_380 = 0 ;
F_267 ( & V_1 -> V_179 , V_381 , & V_380 ) ;
return V_380 & V_382 ;
}
static bool F_268 ( struct V_1 * V_1 )
{
T_2 V_383 = 0 ;
F_267 ( & V_1 -> V_179 ,
V_384 ,
& V_383 ) ;
return V_383 & V_385 ;
}
static bool F_269 ( struct V_1 * V_1 )
{
T_2 V_386 = 0 ;
F_267 ( & V_1 -> V_179 , V_387 , & V_386 ) ;
return V_386 & V_388 ;
}
T_2
F_270 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
if ( F_19 ( V_26 ) )
return V_389 ;
else if ( F_139 ( V_26 ) >= 9 ) {
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
return F_271 ( V_24 ) ;
} else if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
return V_389 ;
else if ( F_164 ( V_26 ) && V_90 == V_140 )
return V_390 ;
else if ( F_166 ( V_26 ) && V_90 != V_140 )
return V_389 ;
else
return V_390 ;
}
T_2
F_272 ( struct V_1 * V_1 , T_2 V_391 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
if ( F_139 ( V_26 ) >= 9 ) {
switch ( V_391 & V_392 ) {
case V_393 :
return V_394 ;
case V_395 :
return V_396 ;
case V_390 :
return V_397 ;
case V_389 :
return V_398 ;
default:
return V_398 ;
}
} else if ( F_137 ( V_26 ) || F_102 ( V_26 ) ) {
switch ( V_391 & V_392 ) {
case V_393 :
return V_394 ;
case V_395 :
return V_396 ;
case V_390 :
return V_397 ;
case V_389 :
default:
return V_398 ;
}
} else if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
switch ( V_391 & V_392 ) {
case V_393 :
return V_394 ;
case V_395 :
return V_396 ;
case V_390 :
return V_397 ;
case V_389 :
default:
return V_398 ;
}
} else if ( F_164 ( V_26 ) && V_90 == V_140 ) {
switch ( V_391 & V_392 ) {
case V_393 :
return V_396 ;
case V_395 :
case V_390 :
return V_397 ;
default:
return V_398 ;
}
} else {
switch ( V_391 & V_392 ) {
case V_393 :
return V_396 ;
case V_395 :
return V_396 ;
case V_390 :
return V_397 ;
case V_389 :
default:
return V_398 ;
}
}
}
static T_3 F_273 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_399 , V_400 ,
V_401 ;
T_2 V_402 = V_1 -> V_402 [ 0 ] ;
switch ( V_402 & V_403 ) {
case V_398 :
V_400 = 0x0004000 ;
switch ( V_402 & V_392 ) {
case V_393 :
V_399 = 0x2B405555 ;
V_401 = 0x552AB83A ;
break;
case V_395 :
V_399 = 0x2B404040 ;
V_401 = 0x5548B83A ;
break;
case V_390 :
V_399 = 0x2B245555 ;
V_401 = 0x5560B83A ;
break;
case V_389 :
V_399 = 0x2B405555 ;
V_401 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_397 :
V_400 = 0x0002000 ;
switch ( V_402 & V_392 ) {
case V_393 :
V_399 = 0x2B404040 ;
V_401 = 0x5552B83A ;
break;
case V_395 :
V_399 = 0x2B404848 ;
V_401 = 0x5580B83A ;
break;
case V_390 :
V_399 = 0x2B404040 ;
V_401 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_396 :
V_400 = 0x0000000 ;
switch ( V_402 & V_392 ) {
case V_393 :
V_399 = 0x2B305555 ;
V_401 = 0x5570B83A ;
break;
case V_395 :
V_399 = 0x2B2B4040 ;
V_401 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_394 :
V_400 = 0x0006000 ;
switch ( V_402 & V_392 ) {
case V_393 :
V_399 = 0x1B405555 ;
V_401 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_274 ( V_24 , V_399 , V_400 ,
V_401 , 0 ) ;
return 0 ;
}
static T_3 F_275 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_404 , V_405 ;
bool V_406 = false ;
T_2 V_402 = V_1 -> V_402 [ 0 ] ;
switch ( V_402 & V_403 ) {
case V_398 :
switch ( V_402 & V_392 ) {
case V_393 :
V_404 = 128 ;
V_405 = 52 ;
break;
case V_395 :
V_404 = 128 ;
V_405 = 77 ;
break;
case V_390 :
V_404 = 128 ;
V_405 = 102 ;
break;
case V_389 :
V_404 = 128 ;
V_405 = 154 ;
V_406 = true ;
break;
default:
return 0 ;
}
break;
case V_397 :
switch ( V_402 & V_392 ) {
case V_393 :
V_404 = 85 ;
V_405 = 78 ;
break;
case V_395 :
V_404 = 85 ;
V_405 = 116 ;
break;
case V_390 :
V_404 = 85 ;
V_405 = 154 ;
break;
default:
return 0 ;
}
break;
case V_396 :
switch ( V_402 & V_392 ) {
case V_393 :
V_404 = 64 ;
V_405 = 104 ;
break;
case V_395 :
V_404 = 64 ;
V_405 = 154 ;
break;
default:
return 0 ;
}
break;
case V_394 :
switch ( V_402 & V_392 ) {
case V_393 :
V_404 = 43 ;
V_405 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_276 ( V_24 , V_404 ,
V_405 , V_406 ) ;
return 0 ;
}
static T_3
F_277 ( T_2 V_402 )
{
T_3 V_407 = 0 ;
switch ( V_402 & V_392 ) {
case V_393 :
default:
V_407 |= V_92 ;
break;
case V_395 :
V_407 |= V_408 ;
break;
case V_390 :
V_407 |= V_409 ;
break;
case V_389 :
V_407 |= V_410 ;
break;
}
switch ( V_402 & V_403 ) {
case V_398 :
default:
V_407 |= V_93 ;
break;
case V_397 :
V_407 |= V_411 ;
break;
case V_396 :
V_407 |= V_412 ;
break;
case V_394 :
V_407 |= V_413 ;
break;
}
return V_407 ;
}
static T_3
F_278 ( T_2 V_402 )
{
int V_407 = V_402 & ( V_392 |
V_403 ) ;
switch ( V_407 ) {
case V_393 | V_398 :
case V_395 | V_398 :
return V_414 ;
case V_393 | V_397 :
return V_415 ;
case V_393 | V_396 :
case V_395 | V_396 :
return V_416 ;
case V_395 | V_397 :
case V_390 | V_397 :
return V_417 ;
case V_390 | V_398 :
case V_389 | V_398 :
return V_418 ;
default:
F_47 ( L_66
L_67 , V_407 ) ;
return V_414 ;
}
}
static T_3
F_279 ( T_2 V_402 )
{
int V_407 = V_402 & ( V_392 |
V_403 ) ;
switch ( V_407 ) {
case V_393 | V_398 :
return V_419 ;
case V_393 | V_397 :
return V_420 ;
case V_393 | V_396 :
return V_421 ;
case V_395 | V_398 :
return V_422 ;
case V_395 | V_397 :
return V_423 ;
case V_390 | V_398 :
return V_424 ;
case V_390 | V_397 :
return V_425 ;
default:
F_47 ( L_66
L_67 , V_407 ) ;
return V_426 ;
}
}
void
F_280 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_3 V_407 , V_292 = 0 ;
T_2 V_402 = V_1 -> V_402 [ 0 ] ;
if ( F_152 ( V_26 ) ) {
V_407 = F_281 ( V_1 ) ;
if ( F_19 ( V_26 ) )
V_407 = 0 ;
else
V_292 = V_427 ;
} else if ( F_49 ( V_26 ) ) {
V_407 = F_275 ( V_1 ) ;
} else if ( F_76 ( V_26 ) ) {
V_407 = F_273 ( V_1 ) ;
} else if ( F_164 ( V_26 ) && V_90 == V_140 ) {
V_407 = F_279 ( V_402 ) ;
V_292 = V_428 ;
} else if ( F_101 ( V_26 ) && V_90 == V_140 ) {
V_407 = F_278 ( V_402 ) ;
V_292 = V_429 ;
} else {
V_407 = F_277 ( V_402 ) ;
V_292 = V_430 | V_431 ;
}
if ( V_292 )
F_47 ( L_68 , V_407 ) ;
F_47 ( L_69 ,
V_402 & V_392 ) ;
F_47 ( L_70 ,
( V_402 & V_403 ) >>
V_432 ) ;
V_1 -> V_87 = ( V_1 -> V_87 & ~ V_292 ) | V_407 ;
F_54 ( V_1 -> V_88 , V_1 -> V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
}
void
F_239 ( struct V_1 * V_1 ,
T_2 V_353 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_236 ( V_1 , & V_1 -> V_87 , V_353 ) ;
F_54 ( V_1 -> V_88 , V_1 -> V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
}
void F_282 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
T_3 V_433 ;
if ( ! F_152 ( V_26 ) )
return;
V_433 = F_44 ( F_237 ( V_90 ) ) ;
V_433 &= ~ V_358 ;
V_433 |= V_434 ;
F_54 ( F_237 ( V_90 ) , V_433 ) ;
if ( V_90 == V_140 )
return;
if ( F_170 ( V_26 , F_283 ( V_90 ) ,
V_435 ,
V_435 ,
1 ) )
F_29 ( L_71 ) ;
}
static void
F_231 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_245 * V_246 = F_150 ( V_3 -> V_4 . V_4 . V_246 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_3 V_87 = V_1 -> V_87 ;
if ( F_24 ( F_152 ( V_26 ) ) )
return;
if ( F_24 ( ( F_44 ( V_1 -> V_88 ) & V_89 ) == 0 ) )
return;
F_47 ( L_48 ) ;
if ( ( F_164 ( V_26 ) && V_90 == V_140 ) ||
( F_166 ( V_26 ) && V_90 != V_140 ) ) {
V_87 &= ~ V_367 ;
V_87 |= V_436 ;
} else {
if ( F_49 ( V_26 ) )
V_87 &= ~ V_370 ;
else
V_87 &= ~ V_371 ;
V_87 |= V_437 ;
}
F_54 ( V_1 -> V_88 , V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
V_87 &= ~ ( V_89 | V_342 ) ;
F_54 ( V_1 -> V_88 , V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
if ( F_284 ( V_26 ) && V_246 -> V_79 == V_95 && V_90 != V_140 ) {
F_285 ( V_26 , V_102 , false ) ;
F_286 ( V_26 , V_102 , false ) ;
V_87 &= ~ ( V_96 | V_371 ) ;
V_87 |= V_89 | V_94 ;
F_54 ( V_1 -> V_88 , V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
V_87 &= ~ V_89 ;
F_54 ( V_1 -> V_88 , V_87 ) ;
F_55 ( V_1 -> V_88 ) ;
F_209 ( V_26 , V_102 ) ;
F_285 ( V_26 , V_102 , true ) ;
F_286 ( V_26 , V_102 , true ) ;
}
F_85 ( V_1 -> V_438 ) ;
V_1 -> V_87 = V_87 ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
F_35 ( V_1 ) ;
V_1 -> V_104 = V_105 ;
F_38 ( V_1 ) ;
}
}
bool
F_287 ( struct V_1 * V_1 )
{
if ( F_265 ( & V_1 -> V_179 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_47 ( L_72 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
return V_1 -> V_11 [ V_331 ] != 0 ;
}
static bool
F_288 ( struct V_1 * V_1 )
{
struct V_25 * V_26 =
F_15 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_24 ( V_1 -> V_11 [ V_331 ] != 0 ) ;
if ( ! F_287 ( V_1 ) )
return false ;
F_289 ( & V_1 -> V_179 , & V_1 -> V_255 ,
F_290 ( V_1 -> V_11 ) ) ;
if ( V_1 -> V_11 [ V_331 ] >= 0x11 )
V_26 -> V_439 = V_1 -> V_11 [ V_440 ] &
V_441 ;
F_265 ( & V_1 -> V_179 , V_442 ,
V_1 -> V_443 ,
sizeof( V_1 -> V_443 ) ) ;
if ( V_1 -> V_443 [ 0 ] & V_444 ) {
V_26 -> V_445 . V_446 = true ;
F_47 ( L_73 ) ;
}
if ( F_139 ( V_26 ) >= 9 &&
( V_1 -> V_443 [ 0 ] & V_447 ) ) {
T_2 V_448 ;
V_26 -> V_445 . V_446 = true ;
F_265 ( & V_1 -> V_179 ,
V_449 ,
& V_448 , 1 ) ;
V_26 -> V_445 . V_450 = V_448 ? true : false ;
V_26 -> V_445 . V_451 = V_26 -> V_445 . V_450 ;
F_47 ( L_74 ,
V_26 -> V_445 . V_451 ? L_75 : L_76 ) ;
if ( V_26 -> V_445 . V_451 ) {
V_26 -> V_445 . V_452 =
F_266 ( V_1 ) ;
V_26 -> V_445 . V_453 =
F_268 ( V_1 ) ;
V_26 -> V_445 . V_454 =
F_269 ( V_1 ) ;
}
}
if ( ( V_1 -> V_11 [ V_455 ] & V_456 ) &&
F_265 ( & V_1 -> V_179 , V_457 ,
V_1 -> V_458 , sizeof( V_1 -> V_458 ) ) ==
sizeof( V_1 -> V_458 ) )
F_47 ( L_77 , ( int ) sizeof( V_1 -> V_458 ) ,
V_1 -> V_458 ) ;
if ( V_1 -> V_458 [ 0 ] >= 0x03 ) {
T_11 V_33 [ V_48 ] ;
int V_45 ;
F_265 ( & V_1 -> V_179 , V_459 ,
V_33 , sizeof( V_33 ) ) ;
for ( V_45 = 0 ; V_45 < F_20 ( V_33 ) ; V_45 ++ ) {
int V_433 = F_291 ( V_33 [ V_45 ] ) ;
if ( V_433 == 0 )
break;
V_1 -> V_33 [ V_45 ] = ( V_433 * 200 ) / 10 ;
}
V_1 -> V_34 = V_45 ;
}
return true ;
}
static bool
F_292 ( struct V_1 * V_1 )
{
if ( ! F_287 ( V_1 ) )
return false ;
if ( F_265 ( & V_1 -> V_179 , V_460 ,
& V_1 -> V_461 , 1 ) < 0 )
return false ;
V_1 -> V_461 = F_293 ( V_1 -> V_461 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_461 )
return false ;
if ( ! F_290 ( V_1 -> V_11 ) )
return true ;
if ( V_1 -> V_11 [ V_331 ] == 0x10 )
return true ;
if ( F_265 ( & V_1 -> V_179 , V_462 ,
V_1 -> V_30 ,
V_463 ) < 0 )
return false ;
return true ;
}
static bool
F_294 ( struct V_1 * V_1 )
{
T_1 V_464 [ 1 ] ;
if ( ! V_465 . V_466 )
return false ;
if ( ! V_1 -> V_467 )
return false ;
if ( V_1 -> V_11 [ V_331 ] < 0x12 )
return false ;
if ( F_265 ( & V_1 -> V_179 , V_468 , V_464 , 1 ) != 1 )
return false ;
return V_464 [ 0 ] & V_469 ;
}
static void
F_295 ( struct V_1 * V_1 )
{
if ( ! V_465 . V_466 )
return;
if ( ! V_1 -> V_467 )
return;
V_1 -> V_470 = F_294 ( V_1 ) ;
if ( V_1 -> V_470 )
F_47 ( L_78 ) ;
else
F_47 ( L_79 ) ;
F_296 ( & V_1 -> V_471 ,
V_1 -> V_470 ) ;
}
static int F_297 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_245 * V_245 = F_150 ( V_38 -> V_4 . V_4 . V_246 ) ;
T_1 V_464 ;
int V_161 = 0 ;
int V_220 = 0 ;
int V_472 = 10 ;
if ( F_267 ( & V_1 -> V_179 , V_473 , & V_464 ) < 0 ) {
F_47 ( L_80 ) ;
V_161 = - V_174 ;
goto V_168;
}
if ( F_213 ( & V_1 -> V_179 , V_473 ,
V_464 & ~ V_474 ) < 0 ) {
F_47 ( L_80 ) ;
V_161 = - V_174 ;
goto V_168;
}
do {
F_298 ( V_26 , V_245 -> V_79 ) ;
if ( F_267 ( & V_1 -> V_179 ,
V_475 , & V_464 ) < 0 ) {
V_161 = - V_174 ;
goto V_168;
}
V_220 = V_464 & V_476 ;
} while ( -- V_472 && V_220 );
if ( V_472 == 0 ) {
F_47 ( L_81 ) ;
V_161 = - V_175 ;
}
V_168:
F_299 ( V_245 ) ;
return V_161 ;
}
static int F_300 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_245 * V_245 = F_150 ( V_38 -> V_4 . V_4 . V_246 ) ;
T_1 V_464 ;
int V_161 ;
if ( F_267 ( & V_1 -> V_179 , V_475 , & V_464 ) < 0 )
return - V_174 ;
if ( ! ( V_464 & V_477 ) )
return - V_478 ;
if ( F_267 ( & V_1 -> V_179 , V_473 , & V_464 ) < 0 )
return - V_174 ;
if ( V_464 & V_474 ) {
V_161 = F_297 ( V_1 ) ;
if ( V_161 )
return V_161 ;
}
F_301 ( V_245 ) ;
if ( F_213 ( & V_1 -> V_179 , V_473 ,
V_464 | V_474 ) < 0 ) {
F_299 ( V_245 ) ;
return - V_174 ;
}
F_298 ( V_26 , V_245 -> V_79 ) ;
return 0 ;
}
int F_302 ( struct V_1 * V_1 , T_1 * V_479 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_245 * V_245 = F_150 ( V_38 -> V_4 . V_4 . V_246 ) ;
T_1 V_464 ;
int V_220 , V_161 ;
int V_472 = 6 ;
V_161 = F_300 ( V_1 ) ;
if ( V_161 )
return V_161 ;
do {
F_298 ( V_26 , V_245 -> V_79 ) ;
if ( F_267 ( & V_1 -> V_179 ,
V_475 , & V_464 ) < 0 ) {
V_161 = - V_174 ;
goto V_480;
}
V_220 = V_464 & V_476 ;
} while ( -- V_472 && V_220 == 0 );
if ( V_472 == 0 ) {
F_29 ( L_82 ) ;
V_161 = - V_175 ;
goto V_480;
}
if ( F_265 ( & V_1 -> V_179 , V_481 , V_479 , 6 ) < 0 ) {
V_161 = - V_174 ;
goto V_480;
}
V_480:
F_297 ( V_1 ) ;
return V_161 ;
}
static bool
F_303 ( struct V_1 * V_1 , T_1 * V_482 )
{
return F_265 ( & V_1 -> V_179 ,
V_483 ,
V_482 , 1 ) == 1 ;
}
static bool
F_304 ( struct V_1 * V_1 , T_1 * V_482 )
{
int V_161 ;
V_161 = F_265 ( & V_1 -> V_179 ,
V_484 ,
V_482 , 14 ) ;
if ( V_161 != 14 )
return false ;
return true ;
}
static T_2 F_305 ( struct V_1 * V_1 )
{
int V_136 = 0 ;
int V_248 = 1 ;
int V_44 [ V_48 ] = {} ;
int V_53 , V_263 ;
T_2 V_264 , V_485 ;
V_136 = F_267 ( & V_1 -> V_179 , V_486 ,
& V_264 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_83 ) ;
return V_487 ;
}
V_264 &= V_488 ;
if ( V_264 < V_248 ||
V_264 > V_1 -> V_19 )
return V_487 ;
V_136 = F_267 ( & V_1 -> V_179 , V_489 ,
& V_485 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_84 ) ;
return V_487 ;
}
V_263 = F_306 ( V_485 ) ;
V_53 = F_26 ( V_1 ,
V_44 ,
V_263 ) ;
if ( V_53 < 0 )
return V_487 ;
V_1 -> V_239 . V_264 = V_264 ;
V_1 -> V_239 . V_263 = V_263 ;
return V_490 ;
}
static T_2 F_307 ( struct V_1 * V_1 )
{
T_2 V_491 ;
T_12 V_492 ;
T_13 V_493 , V_494 ;
int V_136 = 0 ;
V_136 = F_265 ( & V_1 -> V_179 , V_495 ,
& V_491 , 1 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_85 ) ;
return V_487 ;
}
if ( V_491 != V_496 )
return V_487 ;
V_136 = F_265 ( & V_1 -> V_179 , V_497 ,
& V_493 , 2 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_86 ) ;
return V_487 ;
}
V_136 = F_265 ( & V_1 -> V_179 , V_498 ,
& V_494 , 2 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_87 ) ;
return V_487 ;
}
V_136 = F_265 ( & V_1 -> V_179 , V_499 ,
& V_492 , 1 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_88 ) ;
return V_487 ;
}
if ( ( V_492 & V_500 ) != V_501 )
return V_487 ;
if ( V_492 & V_502 )
return V_487 ;
switch ( V_492 & V_503 ) {
case V_504 :
V_1 -> V_239 . V_240 . V_237 = 6 ;
break;
case V_505 :
V_1 -> V_239 . V_240 . V_237 = 8 ;
break;
default:
return V_487 ;
}
V_1 -> V_239 . V_240 . V_506 = V_491 ;
V_1 -> V_239 . V_240 . V_63 = F_308 ( V_493 ) ;
V_1 -> V_239 . V_240 . V_65 = F_308 ( V_494 ) ;
V_1 -> V_239 . V_507 = 1 ;
return V_490 ;
}
static T_2 F_309 ( struct V_1 * V_1 )
{
T_2 V_508 = V_490 ;
struct V_57 * V_57 = V_1 -> V_247 ;
struct V_8 * V_9 = & V_57 -> V_4 ;
if ( V_57 -> V_509 == NULL ||
V_9 -> V_510 ||
V_1 -> V_179 . V_511 > 6 ) {
if ( V_1 -> V_179 . V_512 > 0 ||
V_1 -> V_179 . V_511 > 0 )
F_47 ( L_89 ,
V_1 -> V_179 . V_512 ,
V_1 -> V_179 . V_511 ) ;
V_1 -> V_239 . V_240 . V_513 = V_514 ;
} else {
struct V_513 * V_515 = V_57 -> V_509 ;
V_515 += V_57 -> V_509 -> V_516 ;
if ( ! F_310 ( & V_1 -> V_179 ,
V_517 ,
& V_515 -> V_518 ,
1 ) )
F_47 ( L_90 ) ;
V_508 = V_490 | V_519 ;
V_1 -> V_239 . V_240 . V_513 = V_520 ;
}
V_1 -> V_239 . V_507 = 1 ;
return V_508 ;
}
static T_2 F_311 ( struct V_1 * V_1 )
{
T_2 V_508 = V_487 ;
return V_508 ;
}
static void F_312 ( struct V_1 * V_1 )
{
T_2 V_521 = V_487 ;
T_2 V_186 = 0 ;
int V_136 ;
V_136 = F_267 ( & V_1 -> V_179 , V_522 , & V_186 ) ;
if ( V_136 <= 0 ) {
F_47 ( L_91 ) ;
goto V_523;
}
switch ( V_186 ) {
case V_262 :
F_47 ( L_92 ) ;
V_521 = F_305 ( V_1 ) ;
break;
case V_524 :
F_47 ( L_93 ) ;
V_521 = F_307 ( V_1 ) ;
break;
case V_525 :
F_47 ( L_94 ) ;
V_521 = F_309 ( V_1 ) ;
break;
case V_526 :
F_47 ( L_95 ) ;
V_521 = F_311 ( V_1 ) ;
break;
default:
F_47 ( L_96 , V_186 ) ;
break;
}
if ( V_521 & V_490 )
V_1 -> V_239 . V_261 = V_186 ;
V_523:
V_136 = F_213 ( & V_1 -> V_179 , V_527 , V_521 ) ;
if ( V_136 <= 0 )
F_47 ( L_97 ) ;
}
static int
F_313 ( struct V_1 * V_1 )
{
bool V_528 ;
if ( V_1 -> V_470 ) {
T_1 V_529 [ 16 ] = { 0 } ;
int V_161 = 0 ;
int V_530 ;
bool V_531 ;
V_528 = F_304 ( V_1 , V_529 ) ;
V_532:
if ( V_528 == true ) {
if ( V_1 -> V_533 &&
! F_314 ( & V_529 [ 10 ] , V_1 -> V_52 ) ) {
F_47 ( L_98 ) ;
F_244 ( V_1 ) ;
F_245 ( V_1 ) ;
}
F_47 ( L_99 , V_529 ) ;
V_161 = F_315 ( & V_1 -> V_471 , V_529 , & V_531 ) ;
if ( V_531 ) {
for ( V_530 = 0 ; V_530 < 3 ; V_530 ++ ) {
int V_534 ;
V_534 = F_310 ( & V_1 -> V_179 ,
V_484 + 1 ,
& V_529 [ 1 ] , 3 ) ;
if ( V_534 == 3 ) {
break;
}
}
V_528 = F_304 ( V_1 , V_529 ) ;
if ( V_528 == true ) {
F_47 ( L_100 , V_529 ) ;
goto V_532;
}
} else
V_161 = 0 ;
return V_161 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_47 ( L_101 ) ;
V_1 -> V_470 = false ;
F_296 ( & V_1 -> V_471 , V_1 -> V_470 ) ;
F_316 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_198 ;
}
static void
F_317 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
struct V_245 * V_246 = F_150 ( V_24 -> V_4 . V_246 ) ;
F_285 ( V_26 , V_246 -> V_79 , false ) ;
if ( V_246 -> V_535 -> V_257 )
F_286 ( V_26 ,
F_318 ( V_246 ) , false ) ;
F_244 ( V_1 ) ;
F_245 ( V_1 ) ;
F_298 ( V_26 , V_246 -> V_79 ) ;
F_285 ( V_26 , V_246 -> V_79 , true ) ;
if ( V_246 -> V_535 -> V_257 )
F_286 ( V_26 ,
F_318 ( V_246 ) , true ) ;
}
static void
F_319 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_377 [ V_378 ] ;
F_24 ( ! F_320 ( & V_7 -> V_536 . V_537 ) ) ;
if ( ! F_264 ( V_1 , V_377 ) ) {
F_29 ( L_102 ) ;
return;
}
if ( ! V_23 -> V_4 . V_246 )
return;
if ( ! F_150 ( V_23 -> V_4 . V_246 ) -> V_338 )
return;
if ( ! V_1 -> V_52 )
return;
if ( ! F_314 ( V_377 , V_1 -> V_52 ) ) {
F_47 ( L_103 ,
V_23 -> V_4 . V_213 ) ;
F_317 ( V_1 ) ;
}
}
static bool
F_321 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_23 * V_23 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_482 = 0 ;
T_1 V_538 = V_1 -> V_461 ;
bool V_161 ;
memset ( & V_1 -> V_239 , 0 , sizeof( V_1 -> V_239 ) ) ;
V_161 = F_292 ( V_1 ) ;
if ( ( V_538 != V_1 -> V_461 ) || ! V_161 ) {
return false ;
}
if ( V_1 -> V_11 [ V_331 ] >= 0x11 &&
F_303 ( V_1 , & V_482 ) &&
V_482 != 0 ) {
F_213 ( & V_1 -> V_179 ,
V_483 ,
V_482 ) ;
if ( V_482 & V_539 )
F_312 ( V_1 ) ;
if ( V_482 & ( V_540 | V_541 ) )
F_246 ( L_104 ) ;
}
F_322 ( & V_7 -> V_536 . V_537 , NULL ) ;
F_319 ( V_1 ) ;
F_323 ( & V_7 -> V_536 . V_537 ) ;
if ( V_1 -> V_239 . V_261 == V_262 ) {
F_47 ( L_105 ) ;
F_316 ( V_23 -> V_4 . V_7 ) ;
}
return true ;
}
static enum V_542
F_324 ( struct V_1 * V_1 )
{
struct V_335 * V_336 = F_214 ( V_1 ) ;
T_2 * V_11 = V_1 -> V_11 ;
T_2 type ;
if ( V_336 -> V_338 )
F_325 ( V_336 ) ;
if ( ! F_292 ( V_1 ) )
return V_543 ;
if ( F_1 ( V_1 ) )
return V_544 ;
if ( ! F_290 ( V_11 ) )
return V_544 ;
if ( V_1 -> V_11 [ V_331 ] >= 0x11 &&
V_1 -> V_30 [ 0 ] & V_545 ) {
return V_1 -> V_461 ?
V_544 : V_543 ;
}
if ( F_294 ( V_1 ) )
return V_544 ;
if ( F_326 ( & V_1 -> V_179 . V_546 ) )
return V_544 ;
if ( V_1 -> V_11 [ V_331 ] >= 0x11 ) {
type = V_1 -> V_30 [ 0 ] & V_31 ;
if ( type == V_32 ||
type == V_547 )
return V_548 ;
} else {
type = V_1 -> V_11 [ V_549 ] &
V_550 ;
if ( type == V_551 ||
type == V_552 )
return V_548 ;
}
F_47 ( L_106 ) ;
return V_543 ;
}
static enum V_542
F_327 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_542 V_136 ;
V_136 = F_328 ( V_26 ) ;
if ( V_136 == V_548 )
V_136 = V_544 ;
return V_136 ;
}
static bool F_329 ( struct V_25 * V_26 ,
struct V_2 * V_90 )
{
T_5 V_553 ;
switch ( V_90 -> V_90 ) {
case V_140 :
return true ;
case V_207 :
V_553 = V_554 ;
break;
case V_209 :
V_553 = V_555 ;
break;
case V_211 :
V_553 = V_556 ;
break;
default:
F_116 ( V_90 -> V_90 ) ;
return false ;
}
return F_44 ( V_557 ) & V_553 ;
}
static bool F_330 ( struct V_25 * V_26 ,
struct V_2 * V_90 )
{
T_5 V_553 ;
switch ( V_90 -> V_90 ) {
case V_140 :
return true ;
case V_207 :
V_553 = V_558 ;
break;
case V_209 :
V_553 = V_559 ;
break;
case V_211 :
V_553 = V_560 ;
break;
case V_561 :
V_553 = V_562 ;
break;
default:
F_116 ( V_90 -> V_90 ) ;
return false ;
}
return F_44 ( V_557 ) & V_553 ;
}
static bool F_331 ( struct V_25 * V_26 ,
struct V_2 * V_90 )
{
T_5 V_553 ;
switch ( V_90 -> V_90 ) {
case V_207 :
V_553 = V_563 ;
break;
case V_209 :
V_553 = V_564 ;
break;
case V_211 :
V_553 = V_565 ;
break;
default:
F_116 ( V_90 -> V_90 ) ;
return false ;
}
return F_44 ( V_566 ) & V_553 ;
}
static bool F_332 ( struct V_25 * V_26 ,
struct V_2 * V_90 )
{
T_5 V_553 ;
switch ( V_90 -> V_90 ) {
case V_207 :
V_553 = V_567 ;
break;
case V_209 :
V_553 = V_568 ;
break;
case V_211 :
V_553 = V_569 ;
break;
default:
F_116 ( V_90 -> V_90 ) ;
return false ;
}
return F_44 ( V_566 ) & V_553 ;
}
static bool F_333 ( struct V_25 * V_26 ,
struct V_2 * V_3 )
{
struct V_23 * V_23 = & V_3 -> V_4 ;
enum V_90 V_90 ;
T_5 V_553 ;
F_334 ( V_23 -> V_570 , & V_90 ) ;
switch ( V_90 ) {
case V_140 :
V_553 = V_571 ;
break;
case V_207 :
V_553 = V_572 ;
break;
case V_209 :
V_553 = V_573 ;
break;
default:
F_116 ( V_90 ) ;
return false ;
}
return F_44 ( V_574 ) & V_553 ;
}
bool F_335 ( struct V_25 * V_26 ,
struct V_2 * V_90 )
{
if ( F_284 ( V_26 ) )
return F_329 ( V_26 , V_90 ) ;
else if ( F_129 ( V_26 ) )
return F_330 ( V_26 , V_90 ) ;
else if ( F_19 ( V_26 ) )
return F_333 ( V_26 , V_90 ) ;
else if ( F_336 ( V_26 ) )
return F_332 ( V_26 , V_90 ) ;
else
return F_331 ( V_26 , V_90 ) ;
}
static struct V_513 *
F_337 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_247 ;
if ( V_57 -> V_513 ) {
if ( F_338 ( V_57 -> V_513 ) )
return NULL ;
return F_339 ( V_57 -> V_513 ) ;
} else
return F_340 ( & V_57 -> V_4 ,
& V_1 -> V_179 . V_546 ) ;
}
static void
F_341 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_247 ;
struct V_513 * V_513 ;
F_342 ( V_1 ) ;
V_513 = F_337 ( V_1 ) ;
V_57 -> V_509 = V_513 ;
if ( V_1 -> V_575 != V_576 )
V_1 -> V_259 = V_1 -> V_575 == V_577 ;
else
V_1 -> V_259 = F_343 ( V_513 ) ;
}
static void
F_342 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_247 ;
F_133 ( V_57 -> V_509 ) ;
V_57 -> V_509 = NULL ;
V_1 -> V_259 = false ;
}
static int
F_344 ( struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_542 V_136 ;
T_1 V_482 = 0 ;
F_24 ( ! F_320 ( & V_9 -> V_7 -> V_536 . V_537 ) ) ;
F_36 ( F_15 ( V_7 ) , V_1 -> V_77 ) ;
if ( F_1 ( V_1 ) )
V_136 = F_327 ( V_1 ) ;
else if ( F_335 ( F_15 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_136 = F_324 ( V_1 ) ;
else
V_136 = V_543 ;
if ( V_136 == V_543 ) {
memset ( & V_1 -> V_239 , 0 , sizeof( V_1 -> V_239 ) ) ;
if ( V_1 -> V_470 ) {
F_47 ( L_107 ,
V_1 -> V_470 ,
V_1 -> V_471 . V_578 ) ;
V_1 -> V_470 = false ;
F_296 ( & V_1 -> V_471 ,
V_1 -> V_470 ) ;
}
goto V_168;
}
if ( V_23 -> type != V_5 )
V_23 -> type = V_103 ;
F_47 ( L_108 ,
F_345 ( F_22 ( V_1 ) ) ,
F_345 ( F_346 ( V_1 -> V_11 ) ) ) ;
if ( V_1 -> V_579 ) {
V_1 -> V_19 = F_347 ( V_1 -> V_11 ) ;
V_1 -> V_36 = F_7 ( V_1 ) ;
V_1 -> V_579 = false ;
}
F_143 ( V_1 ) ;
F_289 ( & V_1 -> V_179 , & V_1 -> V_255 ,
F_290 ( V_1 -> V_11 ) ) ;
F_295 ( V_1 ) ;
if ( V_1 -> V_470 ) {
V_136 = V_543 ;
goto V_168;
} else {
F_319 ( V_1 ) ;
}
V_1 -> V_179 . V_512 = 0 ;
V_1 -> V_179 . V_511 = 0 ;
F_341 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_57 -> V_509 )
V_136 = V_544 ;
V_1 -> V_580 = true ;
if ( V_1 -> V_11 [ V_331 ] >= 0x11 &&
F_303 ( V_1 , & V_482 ) &&
V_482 != 0 ) {
F_213 ( & V_1 -> V_179 ,
V_483 ,
V_482 ) ;
if ( V_482 & V_539 )
F_312 ( V_1 ) ;
if ( V_482 & ( V_540 | V_541 ) )
F_246 ( L_104 ) ;
}
V_168:
if ( V_136 != V_544 && ! V_1 -> V_470 )
F_342 ( V_1 ) ;
F_40 ( F_15 ( V_7 ) , V_1 -> V_77 ) ;
return V_136 ;
}
static int
F_348 ( struct V_8 * V_9 ,
struct V_581 * V_582 ,
bool V_583 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_136 = V_9 -> V_136 ;
F_47 ( L_109 ,
V_9 -> V_4 . V_584 , V_9 -> V_213 ) ;
if ( ! V_1 -> V_580 )
V_136 = F_344 ( V_1 -> V_247 ) ;
V_1 -> V_580 = false ;
return V_136 ;
}
static void
F_349 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_23 * V_23 = & F_2 ( V_1 ) -> V_4 ;
struct V_25 * V_26 = F_15 ( V_23 -> V_4 . V_7 ) ;
F_47 ( L_109 ,
V_9 -> V_4 . V_584 , V_9 -> V_213 ) ;
F_342 ( V_1 ) ;
if ( V_9 -> V_136 != V_544 )
return;
F_36 ( V_26 , V_1 -> V_77 ) ;
F_341 ( V_1 ) ;
F_40 ( V_26 , V_1 -> V_77 ) ;
if ( V_23 -> type != V_5 )
V_23 -> type = V_103 ;
}
static int F_350 ( struct V_8 * V_9 )
{
struct V_57 * V_57 = F_31 ( V_9 ) ;
struct V_513 * V_513 ;
V_513 = V_57 -> V_509 ;
if ( V_513 ) {
int V_161 = F_351 ( V_9 , V_513 ) ;
if ( V_161 )
return V_161 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_57 -> V_59 . V_58 ) {
struct V_55 * V_56 ;
V_56 = F_352 ( V_9 -> V_7 ,
V_57 -> V_59 . V_58 ) ;
if ( V_56 ) {
F_353 ( V_9 , V_56 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_354 ( struct V_8 * V_9 )
{
bool V_259 = false ;
struct V_513 * V_513 ;
V_513 = F_31 ( V_9 ) -> V_509 ;
if ( V_513 )
V_259 = F_343 ( V_513 ) ;
return V_259 ;
}
static int
F_355 ( struct V_8 * V_9 ,
struct V_585 * V_586 ,
T_14 V_433 )
{
struct V_25 * V_26 = F_15 ( V_9 -> V_7 ) ;
struct V_57 * V_57 = F_31 ( V_9 ) ;
struct V_23 * V_23 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
int V_161 ;
V_161 = F_356 ( & V_9 -> V_4 , V_586 , V_433 ) ;
if ( V_161 )
return V_161 ;
if ( V_586 == V_26 -> V_587 ) {
int V_45 = V_433 ;
bool V_259 ;
if ( V_45 == V_1 -> V_575 )
return 0 ;
V_1 -> V_575 = V_45 ;
if ( V_45 == V_576 )
V_259 = F_354 ( V_9 ) ;
else
V_259 = ( V_45 == V_577 ) ;
if ( V_259 == V_1 -> V_259 )
return 0 ;
V_1 -> V_259 = V_259 ;
goto V_137;
}
if ( V_586 == V_26 -> V_588 ) {
bool V_589 = V_1 -> V_269 ;
bool V_590 = V_1 -> V_270 ;
switch ( V_433 ) {
case V_591 :
V_1 -> V_269 = true ;
break;
case V_592 :
V_1 -> V_269 = false ;
V_1 -> V_270 = false ;
break;
case V_593 :
V_1 -> V_269 = false ;
V_1 -> V_270 = true ;
break;
default:
return - V_198 ;
}
if ( V_589 == V_1 -> V_269 &&
V_590 == V_1 -> V_270 )
return 0 ;
goto V_137;
}
if ( F_1 ( V_1 ) &&
V_586 == V_9 -> V_7 -> V_536 . V_594 ) {
if ( V_433 == V_595 ) {
F_47 ( L_110 ) ;
return - V_198 ;
}
if ( F_155 ( V_26 ) &&
V_433 == V_596 ) {
F_47 ( L_111 ) ;
return - V_198 ;
}
if ( V_57 -> V_59 . V_260 == V_433 ) {
return 0 ;
}
V_57 -> V_59 . V_260 = V_433 ;
goto V_137;
}
return - V_198 ;
V_137:
if ( V_23 -> V_4 . V_246 )
F_357 ( V_23 -> V_4 . V_246 ) ;
return 0 ;
}
static int
F_358 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
int V_161 ;
V_161 = F_359 ( V_9 ) ;
if ( V_161 )
return V_161 ;
F_360 ( V_9 ) ;
F_47 ( L_112 ,
V_1 -> V_179 . V_213 , V_9 -> V_597 -> V_598 . V_213 ) ;
V_1 -> V_179 . V_7 = V_9 -> V_597 ;
return F_361 ( & V_1 -> V_179 ) ;
}
static void
F_362 ( struct V_8 * V_9 )
{
F_363 ( & F_4 ( V_9 ) -> V_179 ) ;
F_364 ( V_9 ) ;
}
static void
F_365 ( struct V_8 * V_9 )
{
struct V_57 * V_57 = F_31 ( V_9 ) ;
F_133 ( V_57 -> V_509 ) ;
if ( ! F_366 ( V_57 -> V_513 ) )
F_133 ( V_57 -> V_513 ) ;
if ( V_9 -> V_599 == V_600 )
F_367 ( & V_57 -> V_59 ) ;
F_368 ( V_9 ) ;
F_133 ( V_9 ) ;
}
void F_369 ( struct V_601 * V_24 )
{
struct V_2 * V_3 = F_370 ( V_24 ) ;
struct V_1 * V_1 = & V_3 -> V_602 ;
F_371 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_372 ( & V_1 -> V_314 ) ;
F_35 ( V_1 ) ;
F_183 ( V_1 ) ;
F_38 ( V_1 ) ;
if ( V_1 -> V_125 . V_603 ) {
F_373 ( & V_1 -> V_125 ) ;
V_1 -> V_125 . V_603 = NULL ;
}
}
F_132 ( V_1 ) ;
F_374 ( V_24 ) ;
F_133 ( V_3 ) ;
}
void F_375 ( struct V_23 * V_23 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_372 ( & V_1 -> V_314 ) ;
F_35 ( V_1 ) ;
F_183 ( V_1 ) ;
F_38 ( V_1 ) ;
}
static void F_376 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_61 ( & V_26 -> V_78 ) ;
if ( ! F_87 ( V_1 ) )
return;
F_47 ( L_113 ) ;
F_36 ( V_26 , V_1 -> V_77 ) ;
F_186 ( V_1 ) ;
}
static enum V_79 F_377 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
if ( ( V_1 -> V_87 & V_89 ) == 0 )
return V_105 ;
if ( F_49 ( V_26 ) )
return F_222 ( V_1 -> V_87 ) ;
else
return F_223 ( V_1 -> V_87 ) ;
}
void F_378 ( struct V_601 * V_24 )
{
struct V_25 * V_26 = F_15 ( V_24 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_24 ) ;
struct V_335 * V_336 = F_214 ( V_1 ) ;
if ( ! F_152 ( V_26 ) )
V_1 -> V_87 = F_44 ( V_1 -> V_88 ) ;
if ( V_336 -> V_338 )
F_325 ( V_336 ) ;
V_1 -> V_579 = true ;
F_35 ( V_1 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
V_1 -> V_104 = F_377 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_379 ( V_24 -> V_7 , V_1 ) ;
F_376 ( V_1 ) ;
}
F_38 ( V_1 ) ;
}
enum V_604
F_380 ( struct V_2 * V_3 , bool V_605 )
{
struct V_1 * V_1 = & V_3 -> V_602 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_604 V_161 = V_606 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_607 )
V_3 -> V_4 . type = V_103 ;
if ( V_605 && V_3 -> V_4 . type == V_5 ) {
F_47 ( L_114 ,
F_46 ( V_3 -> V_90 ) ) ;
return V_608 ;
}
F_47 ( L_115 ,
F_46 ( V_3 -> V_90 ) ,
V_605 ? L_116 : L_117 ) ;
if ( V_605 ) {
V_1 -> V_579 = true ;
V_1 -> V_580 = false ;
return V_606 ;
}
F_36 ( V_26 , V_1 -> V_77 ) ;
if ( V_1 -> V_470 ) {
if ( F_313 ( V_1 ) == - V_198 ) {
F_47 ( L_107 ,
V_1 -> V_470 , V_1 -> V_471 . V_578 ) ;
V_1 -> V_470 = false ;
F_296 ( & V_1 -> V_471 ,
V_1 -> V_470 ) ;
V_1 -> V_580 = false ;
goto V_609;
}
}
if ( ! V_1 -> V_470 ) {
if ( ! F_321 ( V_1 ) ) {
V_1 -> V_580 = false ;
goto V_609;
}
}
V_161 = V_608 ;
V_609:
F_40 ( V_26 , V_1 -> V_77 ) ;
return V_161 ;
}
bool F_381 ( struct V_25 * V_26 , enum V_90 V_90 )
{
if ( F_139 ( V_26 ) < 5 )
return false ;
if ( F_139 ( V_26 ) < 9 && V_90 == V_140 )
return true ;
return F_382 ( V_26 , V_90 ) ;
}
void
F_383 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_57 * V_57 = F_31 ( V_9 ) ;
F_384 ( V_9 ) ;
F_385 ( V_9 ) ;
V_1 -> V_269 = true ;
if ( F_1 ( V_1 ) ) {
F_386 ( V_9 -> V_7 ) ;
F_387 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_536 . V_594 ,
V_610 ) ;
V_57 -> V_59 . V_260 = V_610 ;
}
}
static void F_388 ( struct V_1 * V_1 )
{
V_1 -> V_301 = F_174 () ;
V_1 -> V_305 = V_302 ;
V_1 -> V_307 = V_302 ;
}
static void
F_389 ( struct V_25 * V_26 ,
struct V_1 * V_1 , struct V_611 * V_612 )
{
T_5 V_118 , V_119 , V_120 = 0 , V_613 = 0 ;
struct V_113 V_114 ;
F_77 ( V_26 , V_1 , & V_114 ) ;
V_613 = F_179 ( V_1 ) ;
V_118 = F_44 ( V_114 . V_118 ) ;
V_119 = F_44 ( V_114 . V_119 ) ;
if ( ! F_19 ( V_26 ) ) {
F_54 ( V_114 . V_116 , V_613 ) ;
V_120 = F_44 ( V_114 . V_120 ) ;
}
V_612 -> V_614 = ( V_118 & V_615 ) >>
V_616 ;
V_612 -> V_617 = ( V_118 & V_618 ) >>
V_619 ;
V_612 -> V_620 = ( V_119 & V_621 ) >>
V_622 ;
V_612 -> V_623 = ( V_119 & V_624 ) >>
V_625 ;
if ( F_19 ( V_26 ) ) {
T_15 V_339 = ( V_613 & V_626 ) >>
V_627 ;
if ( V_339 > 0 )
V_612 -> V_628 = ( V_339 - 1 ) * 1000 ;
else
V_612 -> V_628 = 0 ;
} else {
V_612 -> V_628 = ( ( V_120 & V_629 ) >>
V_630 ) * 1000 ;
}
}
static void
F_390 ( const char * V_631 , const struct V_611 * V_612 )
{
F_47 ( L_118 ,
V_631 ,
V_612 -> V_614 , V_612 -> V_617 , V_612 -> V_620 , V_612 -> V_623 , V_612 -> V_628 ) ;
}
static void
F_169 ( struct V_25 * V_26 ,
struct V_1 * V_1 )
{
struct V_611 V_142 ;
struct V_611 * V_632 = & V_1 -> V_633 ;
F_389 ( V_26 , V_1 , & V_142 ) ;
if ( V_142 . V_614 != V_632 -> V_614 || V_142 . V_617 != V_632 -> V_617 || V_142 . V_620 != V_632 -> V_620 ||
V_142 . V_623 != V_632 -> V_623 || V_142 . V_628 != V_632 -> V_628 ) {
F_29 ( L_119 ) ;
F_390 ( L_120 , V_632 ) ;
F_390 ( L_121 , & V_142 ) ;
}
}
static void
F_63 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_611 V_634 , V_201 , V_635 ,
* V_636 = & V_1 -> V_633 ;
F_61 ( & V_26 -> V_78 ) ;
if ( V_636 -> V_628 != 0 )
return;
F_389 ( V_26 , V_1 , & V_634 ) ;
F_390 ( L_122 , & V_634 ) ;
V_201 = V_26 -> V_201 . V_267 . V_637 ;
V_635 . V_614 = 210 * 10 ;
V_635 . V_617 = 50 * 10 ;
V_635 . V_620 = 50 * 10 ;
V_635 . V_623 = 500 * 10 ;
V_635 . V_628 = ( 510 + 100 ) * 10 ;
F_390 ( L_123 , & V_201 ) ;
#define F_391 ( T_16 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_391 ( V_614 ) ;
F_391 ( V_617 ) ;
F_391 ( V_620 ) ;
F_391 ( V_623 ) ;
F_391 ( V_628 ) ;
#undef F_391
#define F_392 ( T_16 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_315 = F_392 ( V_614 ) ;
V_1 -> V_306 = F_392 ( V_617 ) ;
V_1 -> V_308 = F_392 ( V_620 ) ;
V_1 -> V_438 = F_392 ( V_623 ) ;
V_1 -> V_132 = F_392 ( V_628 ) ;
#undef F_392
F_47 ( L_124 ,
V_1 -> V_315 , V_1 -> V_438 ,
V_1 -> V_132 ) ;
F_47 ( L_125 ,
V_1 -> V_306 , V_1 -> V_308 ) ;
V_636 -> V_617 = 1 ;
V_636 -> V_620 = 1 ;
}
static void
F_64 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
bool V_638 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_118 , V_119 , V_120 , V_110 = 0 ;
int div = V_26 -> V_139 / 1000 ;
struct V_113 V_114 ;
enum V_90 V_90 = F_2 ( V_1 ) -> V_90 ;
const struct V_611 * V_612 = & V_1 -> V_633 ;
F_61 ( & V_26 -> V_78 ) ;
F_77 ( V_26 , V_1 , & V_114 ) ;
if ( V_638 ) {
T_5 V_311 = F_179 ( V_1 ) ;
F_8 ( V_311 & V_316 , L_126 ) ;
if ( V_311 & V_108 )
F_47 ( L_127 ) ;
V_311 &= ~ V_108 ;
F_54 ( V_114 . V_116 , V_311 ) ;
}
V_118 = ( V_612 -> V_614 << V_616 ) |
( V_612 -> V_617 << V_619 ) ;
V_119 = ( V_612 -> V_620 << V_622 ) |
( V_612 -> V_623 << V_625 ) ;
if ( F_19 ( V_26 ) ) {
V_120 = F_44 ( V_114 . V_116 ) ;
V_120 &= ~ V_626 ;
V_120 |= ( F_12 ( ( V_612 -> V_628 + 1 ) , 1000 )
<< V_627 ) ;
} else {
V_120 = ( ( 100 * div ) / 2 - 1 ) << V_639 ;
V_120 |= ( F_12 ( V_612 -> V_628 , 1000 )
<< V_630 ) ;
}
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
V_110 = F_73 ( V_90 ) ;
} else if ( F_284 ( V_26 ) || F_166 ( V_26 ) ) {
if ( V_90 == V_140 )
V_110 = V_640 ;
else
V_110 = V_641 ;
}
V_118 |= V_110 ;
F_54 ( V_114 . V_118 , V_118 ) ;
F_54 ( V_114 . V_119 , V_119 ) ;
if ( F_19 ( V_26 ) )
F_54 ( V_114 . V_116 , V_120 ) ;
else
F_54 ( V_114 . V_120 , V_120 ) ;
F_47 ( L_128 ,
F_44 ( V_114 . V_118 ) ,
F_44 ( V_114 . V_119 ) ,
F_19 ( V_26 ) ?
( F_44 ( V_114 . V_116 ) & V_626 ) :
F_44 ( V_114 . V_120 ) ) ;
}
static void F_379 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
F_74 ( V_1 ) ;
} else {
F_63 ( V_7 , V_1 ) ;
F_64 ( V_7 , V_1 , false ) ;
}
}
static void F_393 ( struct V_25 * V_26 ,
struct V_216 * V_642 ,
int V_643 )
{
struct V_23 * V_24 ;
struct V_2 * V_38 = NULL ;
struct V_1 * V_1 = V_26 -> V_274 . V_602 ;
struct V_245 * V_245 = F_150 ( V_642 -> V_4 . V_246 ) ;
enum V_644 V_51 = V_645 ;
if ( V_643 <= 0 ) {
F_47 ( L_129 ) ;
return;
}
if ( V_1 == NULL ) {
F_47 ( L_130 ) ;
return;
}
V_38 = F_2 ( V_1 ) ;
V_24 = & V_38 -> V_4 ;
V_245 = F_150 ( V_24 -> V_4 . V_246 ) ;
if ( ! V_245 ) {
F_47 ( L_131 ) ;
return;
}
if ( V_26 -> V_274 . type < V_275 ) {
F_47 ( L_132 ) ;
return;
}
if ( V_1 -> V_247 -> V_59 . V_273 -> V_646 ==
V_643 )
V_51 = V_647 ;
if ( V_51 == V_26 -> V_274 . V_648 ) {
F_47 (
L_133 ) ;
return;
}
if ( ! V_642 -> V_4 . V_338 ) {
F_47 ( L_134 ) ;
return;
}
if ( F_139 ( V_26 ) >= 8 && ! F_49 ( V_26 ) ) {
switch ( V_51 ) {
case V_645 :
F_394 ( V_245 , V_649 ) ;
break;
case V_647 :
F_394 ( V_245 , V_650 ) ;
break;
case V_651 :
default:
F_29 ( L_135 ) ;
}
} else if ( F_139 ( V_26 ) > 6 ) {
T_6 V_652 = F_395 ( V_642 -> V_653 ) ;
T_5 V_433 ;
V_433 = F_44 ( V_652 ) ;
if ( V_51 > V_645 ) {
if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
V_433 |= V_654 ;
else
V_433 |= V_655 ;
} else {
if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
V_433 &= ~ V_654 ;
else
V_433 &= ~ V_655 ;
}
F_54 ( V_652 , V_433 ) ;
}
V_26 -> V_274 . V_648 = V_51 ;
F_47 ( L_136 , V_643 ) ;
}
void F_396 ( struct V_1 * V_1 ,
struct V_216 * V_642 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! V_642 -> V_258 ) {
F_47 ( L_137 ) ;
return;
}
F_37 ( & V_26 -> V_274 . V_656 ) ;
if ( F_24 ( V_26 -> V_274 . V_602 ) ) {
F_29 ( L_138 ) ;
goto V_657;
}
V_26 -> V_274 . V_658 = 0 ;
V_26 -> V_274 . V_602 = V_1 ;
V_657:
F_39 ( & V_26 -> V_274 . V_656 ) ;
}
void F_397 ( struct V_1 * V_1 ,
struct V_216 * V_349 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! V_349 -> V_258 )
return;
F_37 ( & V_26 -> V_274 . V_656 ) ;
if ( ! V_26 -> V_274 . V_602 ) {
F_39 ( & V_26 -> V_274 . V_656 ) ;
return;
}
if ( V_26 -> V_274 . V_648 == V_647 )
F_393 ( V_26 , V_349 ,
V_1 -> V_247 -> V_59 . V_58 -> V_646 ) ;
V_26 -> V_274 . V_602 = NULL ;
F_39 ( & V_26 -> V_274 . V_656 ) ;
F_372 ( & V_26 -> V_274 . V_659 ) ;
}
static void F_398 ( struct V_317 * V_659 )
{
struct V_25 * V_26 =
F_83 ( V_659 , F_84 ( * V_26 ) , V_274 . V_659 . V_659 ) ;
struct V_1 * V_1 ;
F_37 ( & V_26 -> V_274 . V_656 ) ;
V_1 = V_26 -> V_274 . V_602 ;
if ( ! V_1 )
goto V_657;
if ( V_26 -> V_274 . V_658 )
goto V_657;
if ( V_26 -> V_274 . V_648 != V_647 ) {
struct V_660 * V_246 = F_2 ( V_1 ) -> V_4 . V_4 . V_246 ;
F_393 ( V_26 , F_150 ( V_246 ) -> V_535 ,
V_1 -> V_247 -> V_59 . V_273 -> V_646 ) ;
}
V_657:
F_39 ( & V_26 -> V_274 . V_656 ) ;
}
void F_399 ( struct V_25 * V_26 ,
unsigned int V_661 )
{
struct V_660 * V_246 ;
enum V_79 V_79 ;
if ( V_26 -> V_274 . type == V_662 )
return;
F_180 ( & V_26 -> V_274 . V_659 ) ;
F_37 ( & V_26 -> V_274 . V_656 ) ;
if ( ! V_26 -> V_274 . V_602 ) {
F_39 ( & V_26 -> V_274 . V_656 ) ;
return;
}
V_246 = F_2 ( V_26 -> V_274 . V_602 ) -> V_4 . V_4 . V_246 ;
V_79 = F_150 ( V_246 ) -> V_79 ;
V_661 &= F_400 ( V_79 ) ;
V_26 -> V_274 . V_658 |= V_661 ;
if ( V_661 && V_26 -> V_274 . V_648 == V_647 )
F_393 ( V_26 , F_150 ( V_246 ) -> V_535 ,
V_26 -> V_274 . V_602 -> V_247 -> V_59 . V_58 -> V_646 ) ;
F_39 ( & V_26 -> V_274 . V_656 ) ;
}
void F_401 ( struct V_25 * V_26 ,
unsigned int V_661 )
{
struct V_660 * V_246 ;
enum V_79 V_79 ;
if ( V_26 -> V_274 . type == V_662 )
return;
F_180 ( & V_26 -> V_274 . V_659 ) ;
F_37 ( & V_26 -> V_274 . V_656 ) ;
if ( ! V_26 -> V_274 . V_602 ) {
F_39 ( & V_26 -> V_274 . V_656 ) ;
return;
}
V_246 = F_2 ( V_26 -> V_274 . V_602 ) -> V_4 . V_4 . V_246 ;
V_79 = F_150 ( V_246 ) -> V_79 ;
V_661 &= F_400 ( V_79 ) ;
V_26 -> V_274 . V_658 &= ~ V_661 ;
if ( V_661 && V_26 -> V_274 . V_648 == V_647 )
F_393 ( V_26 , F_150 ( V_246 ) -> V_535 ,
V_26 -> V_274 . V_602 -> V_247 -> V_59 . V_58 -> V_646 ) ;
if ( ! V_26 -> V_274 . V_658 )
F_188 ( & V_26 -> V_274 . V_659 ,
F_187 ( 1000 ) ) ;
F_39 ( & V_26 -> V_274 . V_656 ) ;
}
static struct V_55 *
F_402 ( struct V_57 * V_57 ,
struct V_55 * V_58 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_55 * V_273 = NULL ;
F_403 ( & V_26 -> V_274 . V_659 , F_398 ) ;
F_404 ( & V_26 -> V_274 . V_656 ) ;
if ( F_139 ( V_26 ) <= 6 ) {
F_47 ( L_139 ) ;
return NULL ;
}
if ( V_26 -> V_201 . V_663 != V_275 ) {
F_47 ( L_140 ) ;
return NULL ;
}
V_273 = F_405
( V_26 , V_58 , V_9 ) ;
if ( ! V_273 ) {
F_47 ( L_141 ) ;
return NULL ;
}
V_26 -> V_274 . type = V_26 -> V_201 . V_663 ;
V_26 -> V_274 . V_648 = V_645 ;
F_47 ( L_142 ) ;
return V_273 ;
}
static bool F_406 ( struct V_1 * V_1 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_55 * V_58 = NULL ;
struct V_55 * V_273 = NULL ;
bool V_664 ;
struct V_55 * V_665 ;
struct V_513 * V_513 ;
enum V_79 V_79 = V_105 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_407 ( V_7 ) ) {
F_24 ( ! ( F_284 ( V_26 ) || F_166 ( V_26 ) ) ) ;
F_408 ( L_143 ) ;
return false ;
}
F_35 ( V_1 ) ;
F_388 ( V_1 ) ;
F_379 ( V_7 , V_1 ) ;
F_376 ( V_1 ) ;
F_38 ( V_1 ) ;
V_664 = F_288 ( V_1 ) ;
if ( ! V_664 ) {
F_408 ( L_144 ) ;
goto V_666;
}
F_37 ( & V_7 -> V_536 . V_656 ) ;
V_513 = F_340 ( V_9 , & V_1 -> V_179 . V_546 ) ;
if ( V_513 ) {
if ( F_409 ( V_9 , V_513 ) ) {
F_410 ( V_9 ,
V_513 ) ;
F_411 ( V_9 , V_513 ) ;
} else {
F_133 ( V_513 ) ;
V_513 = F_412 ( - V_198 ) ;
}
} else {
V_513 = F_412 ( - V_667 ) ;
}
V_57 -> V_513 = V_513 ;
F_413 (scan, &connector->probed_modes, head) {
if ( ( V_665 -> type & V_668 ) ) {
V_58 = F_352 ( V_7 , V_665 ) ;
V_273 = F_402 (
V_57 , V_58 ) ;
break;
}
}
if ( ! V_58 && V_26 -> V_201 . V_669 ) {
V_58 = F_352 ( V_7 ,
V_26 -> V_201 . V_669 ) ;
if ( V_58 ) {
V_58 -> type |= V_668 ;
V_9 -> V_266 . V_670 = V_58 -> V_670 ;
V_9 -> V_266 . V_671 = V_58 -> V_671 ;
}
}
F_39 ( & V_7 -> V_536 . V_656 ) ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) ) {
V_1 -> V_125 . V_603 = F_82 ;
F_414 ( & V_1 -> V_125 ) ;
V_79 = F_377 ( V_1 ) ;
if ( V_79 != V_102 && V_79 != V_95 )
V_79 = V_1 -> V_80 ;
if ( V_79 != V_102 && V_79 != V_95 )
V_79 = V_102 ;
F_47 ( L_145 ,
F_45 ( V_79 ) ) ;
}
F_415 ( & V_57 -> V_59 , V_58 , V_273 ) ;
V_57 -> V_59 . V_672 . V_673 = F_200 ;
F_416 ( V_9 , V_79 ) ;
return true ;
V_666:
F_372 ( & V_1 -> V_314 ) ;
F_35 ( V_1 ) ;
F_183 ( V_1 ) ;
F_38 ( V_1 ) ;
return false ;
}
static void
F_417 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_602 ;
switch ( V_3 -> V_90 ) {
case V_140 :
V_24 -> V_570 = V_674 ;
V_1 -> V_77 = V_675 ;
break;
case V_207 :
V_24 -> V_570 = V_676 ;
V_1 -> V_77 = V_677 ;
break;
case V_209 :
V_24 -> V_570 = V_678 ;
V_1 -> V_77 = V_679 ;
break;
case V_211 :
V_24 -> V_570 = V_680 ;
V_1 -> V_77 = V_681 ;
break;
case V_561 :
V_24 -> V_570 = V_682 ;
V_1 -> V_77 = V_681 ;
break;
default:
F_116 ( V_3 -> V_90 ) ;
}
}
bool
F_418 ( struct V_2 * V_3 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_602 ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_90 V_90 = V_3 -> V_90 ;
int type ;
if ( F_8 ( V_3 -> V_18 < 1 ,
L_146 ,
V_3 -> V_18 , F_46 ( V_90 ) ) )
return false ;
V_1 -> V_579 = true ;
V_1 -> V_80 = V_105 ;
V_1 -> V_104 = V_105 ;
if ( F_139 ( V_26 ) >= 9 )
V_1 -> V_170 = F_99 ;
else if ( F_137 ( V_26 ) || F_102 ( V_26 ) )
V_1 -> V_170 = F_97 ;
else if ( F_129 ( V_26 ) )
V_1 -> V_170 = F_96 ;
else
V_1 -> V_170 = F_94 ;
if ( F_139 ( V_26 ) >= 9 )
V_1 -> V_172 = F_103 ;
else
V_1 -> V_172 = F_100 ;
if ( F_152 ( V_26 ) )
V_1 -> V_683 = V_684 ;
V_1 -> V_87 = F_44 ( V_1 -> V_88 ) ;
V_1 -> V_247 = V_57 ;
if ( F_381 ( V_26 , V_90 ) )
type = V_600 ;
else
type = V_685 ;
if ( F_76 ( V_26 ) || F_49 ( V_26 ) )
V_1 -> V_104 = F_377 ( V_1 ) ;
if ( type == V_600 )
V_23 -> type = V_5 ;
if ( F_24 ( ( F_76 ( V_26 ) || F_49 ( V_26 ) ) &&
F_1 ( V_1 ) && V_90 != V_207 && V_90 != V_209 ) )
return false ;
F_47 ( L_147 ,
type == V_600 ? L_148 : L_149 ,
F_46 ( V_90 ) ) ;
F_419 ( V_7 , V_9 , & V_686 , type ) ;
F_420 ( V_9 , & V_687 ) ;
V_9 -> V_688 = true ;
V_9 -> V_689 = 0 ;
F_417 ( V_3 ) ;
F_134 ( V_1 ) ;
F_403 ( & V_1 -> V_314 ,
F_184 ) ;
F_421 ( V_57 , V_23 ) ;
if ( F_152 ( V_26 ) )
V_57 -> V_690 = V_691 ;
else
V_57 -> V_690 = V_692 ;
if ( F_422 ( V_26 ) && ! F_1 ( V_1 ) &&
( V_90 == V_207 || V_90 == V_209 || V_90 == V_211 ) )
F_423 ( V_3 ,
V_57 -> V_4 . V_4 . V_584 ) ;
if ( ! F_406 ( V_1 , V_57 ) ) {
F_132 ( V_1 ) ;
F_371 ( V_3 ) ;
goto V_693;
}
F_383 ( V_1 , V_9 ) ;
if ( F_141 ( V_26 ) && ! F_336 ( V_26 ) ) {
T_5 V_355 = F_44 ( V_694 ) ;
F_54 ( V_694 , ( V_355 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_693:
F_368 ( V_9 ) ;
return false ;
}
bool F_424 ( struct V_25 * V_26 ,
T_6 V_88 ,
enum V_90 V_90 )
{
struct V_2 * V_3 ;
struct V_23 * V_23 ;
struct V_601 * V_24 ;
struct V_57 * V_57 ;
V_3 = F_425 ( sizeof( * V_3 ) , V_214 ) ;
if ( ! V_3 )
return false ;
V_57 = F_426 () ;
if ( ! V_57 )
goto V_695;
V_23 = & V_3 -> V_4 ;
V_24 = & V_23 -> V_4 ;
if ( F_427 ( & V_26 -> V_112 , & V_23 -> V_4 ,
& V_696 , V_697 ,
L_150 , F_46 ( V_90 ) ) )
goto V_698;
V_23 -> V_699 = F_149 ;
V_23 -> V_700 = F_227 ;
V_23 -> V_690 = F_216 ;
V_23 -> V_701 = F_224 ;
V_23 -> V_702 = F_375 ;
if ( F_49 ( V_26 ) ) {
V_23 -> V_703 = F_260 ;
V_23 -> V_704 = F_257 ;
V_23 -> V_323 = F_249 ;
V_23 -> V_705 = F_234 ;
V_23 -> V_706 = F_262 ;
} else if ( F_76 ( V_26 ) ) {
V_23 -> V_703 = F_255 ;
V_23 -> V_704 = F_253 ;
V_23 -> V_323 = F_249 ;
V_23 -> V_705 = F_233 ;
} else {
V_23 -> V_704 = F_251 ;
V_23 -> V_323 = F_248 ;
if ( F_139 ( V_26 ) >= 5 )
V_23 -> V_705 = F_232 ;
}
V_3 -> V_90 = V_90 ;
V_3 -> V_602 . V_88 = V_88 ;
V_3 -> V_18 = 4 ;
V_23 -> type = V_103 ;
V_23 -> V_340 = F_428 ( V_90 ) ;
if ( F_49 ( V_26 ) ) {
if ( V_90 == V_211 )
V_23 -> V_707 = 1 << 2 ;
else
V_23 -> V_707 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_23 -> V_707 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_23 -> V_708 = 0 ;
V_23 -> V_90 = V_90 ;
V_3 -> V_709 = F_380 ;
V_26 -> V_710 . V_711 [ V_90 ] = V_3 ;
if ( ! F_418 ( V_3 , V_57 ) )
goto V_712;
return true ;
V_712:
F_374 ( V_24 ) ;
V_698:
F_133 ( V_57 ) ;
V_695:
F_133 ( V_3 ) ;
return false ;
}
void F_429 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_713 ; V_45 ++ ) {
struct V_2 * V_3 = V_26 -> V_710 . V_711 [ V_45 ] ;
if ( ! V_3 || ! V_3 -> V_602 . V_467 )
continue;
if ( V_3 -> V_602 . V_470 )
F_430 ( & V_3 -> V_602 . V_471 ) ;
}
}
void F_431 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_713 ; V_45 ++ ) {
struct V_2 * V_3 = V_26 -> V_710 . V_711 [ V_45 ] ;
int V_161 ;
if ( ! V_3 || ! V_3 -> V_602 . V_467 )
continue;
V_161 = F_432 ( & V_3 -> V_602 . V_471 ) ;
if ( V_161 )
F_313 ( & V_3 -> V_602 ) ;
}
}
