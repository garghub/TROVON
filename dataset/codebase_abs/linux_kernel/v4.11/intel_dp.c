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
} else if ( F_21 ( V_26 ) || F_22 ( V_26 ) ) {
* V_37 = V_41 ;
V_39 = F_20 ( V_41 ) ;
} else {
* V_37 = V_35 ;
V_39 = F_20 ( V_35 ) ;
}
if ( ! F_23 ( V_1 ) )
V_39 -- ;
return V_39 ;
}
static int F_24 ( const int * V_37 , int V_42 ,
const int * V_33 , int V_43 ,
int * V_44 )
{
int V_45 = 0 , V_46 = 0 , V_47 = 0 ;
while ( V_45 < V_42 && V_46 < V_43 ) {
if ( V_37 [ V_45 ] == V_33 [ V_46 ] ) {
if ( F_25 ( V_47 >= V_48 ) )
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
static int F_26 ( struct V_1 * V_1 ,
int * V_44 )
{
const int * V_37 , * V_33 ;
int V_42 , V_43 ;
V_43 = F_17 ( V_1 , & V_33 ) ;
V_42 = F_18 ( V_1 , & V_37 ) ;
return F_24 ( V_37 , V_42 ,
V_33 , V_43 ,
V_44 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
int * V_44 , int V_49 )
{
int V_50 ;
int V_51 ;
V_50 = F_26 ( V_1 , V_44 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
if ( V_49 == V_44 [ V_50 - V_51 - 1 ] )
return V_50 - V_51 - 1 ;
}
return - 1 ;
}
int F_28 ( struct V_1 * V_1 ,
int V_49 , T_2 V_52 )
{
int V_44 [ V_48 ] ;
int V_53 ;
V_53 = F_27 ( V_1 ,
V_44 ,
V_49 ) ;
if ( V_53 > 0 ) {
V_1 -> V_36 = F_29 ( V_44 [ V_53 - 1 ] ) ;
V_1 -> V_19 = V_52 ;
} else if ( V_52 > 1 ) {
V_1 -> V_36 = F_7 ( V_1 ) ;
V_1 -> V_19 = V_52 >> 1 ;
} else {
F_30 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static enum V_54
F_31 ( struct V_8 * V_9 ,
struct V_55 * V_56 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_57 * V_57 = F_32 ( V_9 ) ;
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
V_22 = F_33 ( V_1 ) ;
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
T_3 F_34 ( const T_2 * V_72 , int V_73 )
{
int V_45 ;
T_3 V_74 = 0 ;
if ( V_73 > 4 )
V_73 = 4 ;
for ( V_45 = 0 ; V_45 < V_73 ; V_45 ++ )
V_74 |= ( ( T_3 ) V_72 [ V_45 ] ) << ( ( 3 - V_45 ) * 8 ) ;
return V_74 ;
}
static void F_35 ( T_3 V_72 , T_2 * V_75 , int V_76 )
{
int V_45 ;
if ( V_76 > 4 )
V_76 = 4 ;
for ( V_45 = 0 ; V_45 < V_76 ; V_45 ++ )
V_75 [ V_45 ] = V_72 >> ( ( 3 - V_45 ) * 8 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
V_78 = F_37 ( V_24 ) ;
F_38 ( V_26 , V_78 ) ;
F_39 ( & V_26 -> V_79 ) ;
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
F_41 ( & V_26 -> V_79 ) ;
V_78 = F_37 ( V_24 ) ;
F_42 ( V_26 , V_78 ) ;
}
static void
F_43 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_80 V_80 = V_1 -> V_81 ;
bool V_82 , V_83 = false ;
enum V_84 V_85 = F_44 ( V_80 ) ;
enum V_86 V_87 = F_45 ( V_80 ) ;
T_3 V_88 ;
if ( F_8 ( F_46 ( V_1 -> V_89 ) & V_90 ,
L_3 ,
F_47 ( V_80 ) , F_48 ( V_3 -> V_91 ) ) )
return;
F_49 ( L_4 ,
F_47 ( V_80 ) , F_48 ( V_3 -> V_91 ) ) ;
V_88 = F_46 ( V_1 -> V_89 ) & V_92 ;
V_88 |= V_93 | V_94 ;
V_88 |= F_50 ( 1 ) ;
V_88 |= V_95 ;
if ( F_51 ( V_26 ) )
V_88 |= F_52 ( V_80 ) ;
else if ( V_80 == V_96 )
V_88 |= V_97 ;
V_82 = F_46 ( F_53 ( V_80 ) ) & V_98 ;
if ( ! V_82 ) {
V_83 = F_51 ( V_26 ) &&
! F_54 ( V_26 , V_85 , V_87 , true ) ;
if ( F_55 ( V_26 , V_80 , F_51 ( V_26 ) ?
& V_99 [ 0 ] . V_100 : & V_101 [ 0 ] . V_100 ) ) {
F_30 ( L_5 ,
F_47 ( V_80 ) ) ;
return;
}
}
F_56 ( V_1 -> V_89 , V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
F_56 ( V_1 -> V_89 , V_88 | V_90 ) ;
F_57 ( V_1 -> V_89 ) ;
F_56 ( V_1 -> V_89 , V_88 & ~ V_90 ) ;
F_57 ( V_1 -> V_89 ) ;
if ( ! V_82 ) {
F_58 ( V_26 , V_80 ) ;
if ( V_83 )
F_54 ( V_26 , V_85 , V_87 , false ) ;
}
}
static enum V_80 F_59 ( struct V_25 * V_26 )
{
struct V_23 * V_24 ;
unsigned int V_102 = ( 1 << V_103 ) | ( 1 << V_96 ) ;
F_60 (&dev_priv->drm, encoder) {
struct V_1 * V_1 ;
if ( V_24 -> type != V_104 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
if ( V_24 -> type == V_5 ) {
F_25 ( V_1 -> V_105 != V_106 &&
V_1 -> V_105 != V_1 -> V_81 ) ;
if ( V_1 -> V_81 != V_106 )
V_102 &= ~ ( 1 << V_1 -> V_81 ) ;
} else {
F_25 ( V_1 -> V_81 != V_106 ) ;
if ( V_1 -> V_105 != V_106 )
V_102 &= ~ ( 1 << V_1 -> V_105 ) ;
}
}
if ( V_102 == 0 )
return V_106 ;
return F_61 ( V_102 ) - 1 ;
}
static enum V_80
F_62 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_80 V_80 ;
F_63 ( & V_26 -> V_79 ) ;
F_25 ( ! F_1 ( V_1 ) ) ;
F_25 ( V_1 -> V_105 != V_106 &&
V_1 -> V_105 != V_1 -> V_81 ) ;
if ( V_1 -> V_81 != V_106 )
return V_1 -> V_81 ;
V_80 = F_59 ( V_26 ) ;
if ( F_25 ( V_80 == V_106 ) )
V_80 = V_103 ;
F_64 ( V_7 , V_80 ) ;
V_1 -> V_81 = V_80 ;
F_49 ( L_6 ,
F_47 ( V_1 -> V_81 ) ,
F_48 ( V_3 -> V_91 ) ) ;
F_65 ( V_7 , V_1 ) ;
F_66 ( V_7 , V_1 , true ) ;
F_43 ( V_1 ) ;
return V_1 -> V_81 ;
}
static int
F_67 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_63 ( & V_26 -> V_79 ) ;
F_25 ( ! F_1 ( V_1 ) ) ;
if ( ! V_1 -> V_107 )
return 0 ;
V_1 -> V_107 = false ;
F_66 ( V_7 , V_1 , false ) ;
return 0 ;
}
static bool F_68 ( struct V_25 * V_26 ,
enum V_80 V_80 )
{
return F_46 ( F_69 ( V_80 ) ) & V_108 ;
}
static bool F_70 ( struct V_25 * V_26 ,
enum V_80 V_80 )
{
return F_46 ( F_71 ( V_80 ) ) & V_109 ;
}
static bool F_72 ( struct V_25 * V_26 ,
enum V_80 V_80 )
{
return true ;
}
static enum V_80
F_73 ( struct V_25 * V_26 ,
enum V_91 V_91 ,
T_4 V_110 )
{
enum V_80 V_80 ;
for ( V_80 = V_103 ; V_80 <= V_96 ; V_80 ++ ) {
T_5 V_111 = F_46 ( F_74 ( V_80 ) ) &
V_112 ;
if ( V_111 != F_75 ( V_91 ) )
continue;
if ( ! V_110 ( V_26 , V_80 ) )
continue;
return V_80 ;
}
return V_106 ;
}
static void
F_76 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
F_63 ( & V_26 -> V_79 ) ;
V_1 -> V_81 = F_73 ( V_26 , V_91 ,
F_68 ) ;
if ( V_1 -> V_81 == V_106 )
V_1 -> V_81 = F_73 ( V_26 , V_91 ,
F_70 ) ;
if ( V_1 -> V_81 == V_106 )
V_1 -> V_81 = F_73 ( V_26 , V_91 ,
F_72 ) ;
if ( V_1 -> V_81 == V_106 ) {
F_49 ( L_7 ,
F_48 ( V_91 ) ) ;
return;
}
F_49 ( L_8 ,
F_48 ( V_91 ) , F_47 ( V_1 -> V_81 ) ) ;
F_65 ( V_7 , V_1 ) ;
F_66 ( V_7 , V_1 , false ) ;
}
void F_77 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = & V_26 -> V_113 ;
struct V_23 * V_24 ;
if ( F_25 ( ! F_78 ( V_26 ) && ! F_51 ( V_26 ) &&
! F_19 ( V_26 ) ) )
return;
F_60 (dev, encoder) {
struct V_1 * V_1 ;
if ( V_24 -> type != V_104 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
F_25 ( V_1 -> V_105 != V_106 ) ;
if ( V_24 -> type != V_5 )
continue;
if ( F_19 ( V_26 ) )
V_1 -> V_107 = true ;
else
V_1 -> V_81 = V_106 ;
}
}
static void F_79 ( struct V_25 * V_26 ,
struct V_1 * V_1 ,
struct V_114 * V_115 )
{
int V_116 = 0 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
if ( F_19 ( V_26 ) )
V_116 = F_67 ( V_1 ) ;
else if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
V_116 = F_62 ( V_1 ) ;
V_115 -> V_117 = F_71 ( V_116 ) ;
V_115 -> V_118 = F_69 ( V_116 ) ;
V_115 -> V_119 = F_74 ( V_116 ) ;
V_115 -> V_120 = F_80 ( V_116 ) ;
if ( ! F_19 ( V_26 ) )
V_115 -> V_121 = F_81 ( V_116 ) ;
}
static T_6
F_82 ( struct V_1 * V_1 )
{
struct V_114 V_115 ;
F_79 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_115 ) ;
return V_115 . V_117 ;
}
static T_6
F_83 ( struct V_1 * V_1 )
{
struct V_114 V_115 ;
F_79 ( F_15 ( F_3 ( V_1 ) ) , V_1 ,
& V_115 ) ;
return V_115 . V_118 ;
}
static int F_84 ( struct V_122 * V_123 , unsigned long V_124 ,
void * V_125 )
{
struct V_1 * V_1 = F_85 ( V_123 , F_86 ( * V_1 ) ,
V_126 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) || V_124 != V_127 )
return 0 ;
F_36 ( V_1 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
enum V_80 V_80 = F_62 ( V_1 ) ;
T_6 V_128 , V_129 ;
T_5 V_121 ;
V_128 = F_71 ( V_80 ) ;
V_129 = F_81 ( V_80 ) ;
V_121 = F_46 ( V_129 ) ;
V_121 &= V_130 ;
F_56 ( V_129 , V_121 | 0x1F ) ;
F_56 ( V_128 , V_131 | V_132 ) ;
F_87 ( V_1 -> V_133 ) ;
}
F_40 ( V_1 ) ;
return 0 ;
}
static bool F_88 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_63 ( & V_26 -> V_79 ) ;
if ( ( F_78 ( V_26 ) || F_51 ( V_26 ) ) &&
V_1 -> V_81 == V_106 )
return false ;
return ( F_46 ( F_83 ( V_1 ) ) & V_108 ) != 0 ;
}
static bool F_89 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_63 ( & V_26 -> V_79 ) ;
if ( ( F_78 ( V_26 ) || F_51 ( V_26 ) ) &&
V_1 -> V_81 == V_106 )
return false ;
return F_46 ( F_82 ( V_1 ) ) & V_109 ;
}
static void
F_90 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_88 ( V_1 ) && ! F_89 ( V_1 ) ) {
F_8 ( 1 , L_9 ) ;
F_49 ( L_10 ,
F_46 ( F_83 ( V_1 ) ) ,
F_46 ( F_82 ( V_1 ) ) ) ;
}
}
static T_3
F_91 ( struct V_1 * V_1 , bool V_134 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_6 V_135 = V_1 -> V_136 ;
T_3 V_137 ;
bool V_138 ;
#define F_92 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_134 )
V_138 = F_93 ( V_26 -> V_139 , F_92 ,
F_94 ( 10 ) ) ;
else
V_138 = F_95 ( F_92 , 10 ) == 0 ;
if ( ! V_138 )
F_30 ( L_11 ,
V_134 ) ;
#undef F_92
return V_137 ;
}
static T_3 F_96 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_51 )
return 0 ;
return F_97 ( V_26 -> V_140 , 2000 ) ;
}
static T_3 F_98 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_51 )
return 0 ;
if ( V_3 -> V_91 == V_141 )
return F_97 ( V_26 -> V_142 , 2000 ) ;
else
return F_97 ( V_26 -> V_140 , 2000 ) ;
}
static T_3 F_99 ( struct V_1 * V_1 , int V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
if ( V_3 -> V_91 != V_141 && F_100 ( V_26 ) ) {
switch ( V_51 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
}
return F_98 ( V_1 , V_51 ) ;
}
static T_3 F_101 ( struct V_1 * V_1 , int V_51 )
{
return V_51 ? 0 : 1 ;
}
static T_3 F_102 ( struct V_1 * V_1 ,
bool V_134 ,
int V_143 ,
T_3 V_144 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_3 V_145 , V_146 ;
if ( F_103 ( V_26 ) )
V_145 = 3 ;
else
V_145 = 5 ;
if ( F_104 ( V_26 ) && V_3 -> V_91 == V_141 )
V_146 = V_147 ;
else
V_146 = V_148 ;
return V_149 |
V_150 |
( V_134 ? V_151 : 0 ) |
V_152 |
V_146 |
V_153 |
( V_143 << V_154 ) |
( V_145 << V_155 ) |
( V_144 << V_156 ) ;
}
static T_3 F_105 ( struct V_1 * V_1 ,
bool V_134 ,
int V_143 ,
T_3 V_125 )
{
return V_149 |
V_150 |
( V_134 ? V_151 : 0 ) |
V_152 |
V_157 |
V_153 |
( V_143 << V_154 ) |
F_106 ( 32 ) |
F_107 ( 32 ) ;
}
static int
F_108 ( struct V_1 * V_1 ,
const T_2 * V_158 , int V_143 ,
T_2 * V_159 , int V_160 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
T_6 V_135 = V_1 -> V_136 ;
T_3 V_144 ;
int V_45 , V_161 , V_162 ;
T_3 V_137 ;
int V_163 , clock = 0 ;
bool V_134 = F_109 ( V_26 ) ;
bool V_164 ;
F_36 ( V_1 ) ;
V_164 = F_110 ( V_1 ) ;
F_111 ( & V_26 -> V_165 , 0 ) ;
F_90 ( V_1 ) ;
for ( V_163 = 0 ; V_163 < 3 ; V_163 ++ ) {
V_137 = F_112 ( V_135 ) ;
if ( ( V_137 & V_149 ) == 0 )
break;
F_87 ( 1 ) ;
}
if ( V_163 == 3 ) {
static T_5 V_166 = - 1 ;
const T_5 V_137 = F_46 ( V_135 ) ;
if ( V_137 != V_166 ) {
F_8 ( 1 , L_12 ,
V_137 ) ;
V_166 = V_137 ;
}
V_161 = - V_167 ;
goto V_168;
}
if ( F_25 ( V_143 > 20 || V_160 > 20 ) ) {
V_161 = - V_169 ;
goto V_168;
}
while ( ( V_144 = V_1 -> V_170 ( V_1 , clock ++ ) ) ) {
T_5 V_171 = V_1 -> V_172 ( V_1 ,
V_134 ,
V_143 ,
V_144 ) ;
for ( V_163 = 0 ; V_163 < 5 ; V_163 ++ ) {
for ( V_45 = 0 ; V_45 < V_143 ; V_45 += 4 )
F_56 ( V_1 -> V_173 [ V_45 >> 2 ] ,
F_34 ( V_158 + V_45 ,
V_143 - V_45 ) ) ;
F_56 ( V_135 , V_171 ) ;
V_137 = F_91 ( V_1 , V_134 ) ;
F_56 ( V_135 ,
V_137 |
V_150 |
V_152 |
V_153 ) ;
if ( V_137 & V_152 )
continue;
if ( V_137 & V_153 ) {
F_113 ( 400 , 500 ) ;
continue;
}
if ( V_137 & V_150 )
goto V_138;
}
}
if ( ( V_137 & V_150 ) == 0 ) {
F_30 ( L_13 , V_137 ) ;
V_161 = - V_167 ;
goto V_168;
}
V_138:
if ( V_137 & V_153 ) {
F_30 ( L_14 , V_137 ) ;
V_161 = - V_174 ;
goto V_168;
}
if ( V_137 & V_152 ) {
F_49 ( L_15 , V_137 ) ;
V_161 = - V_175 ;
goto V_168;
}
V_162 = ( ( V_137 & V_176 ) >>
V_154 ) ;
if ( V_162 == 0 || V_162 > 20 ) {
F_49 ( L_16 ,
V_162 ) ;
F_113 ( 1000 , 1500 ) ;
V_161 = - V_167 ;
goto V_168;
}
if ( V_162 > V_160 )
V_162 = V_160 ;
for ( V_45 = 0 ; V_45 < V_162 ; V_45 += 4 )
F_35 ( F_46 ( V_1 -> V_173 [ V_45 >> 2 ] ) ,
V_159 + V_45 , V_162 - V_45 ) ;
V_161 = V_162 ;
V_168:
F_111 ( & V_26 -> V_165 , V_177 ) ;
if ( V_164 )
F_114 ( V_1 , false ) ;
F_40 ( V_1 ) ;
return V_161 ;
}
static T_7
F_115 ( struct V_178 * V_179 , struct V_180 * V_181 )
{
struct V_1 * V_1 = F_85 ( V_179 , struct V_1 , V_179 ) ;
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
if ( F_25 ( V_184 > 20 ) )
return - V_169 ;
F_25 ( ! V_181 -> V_194 != ! V_181 -> V_39 ) ;
if ( V_181 -> V_194 )
memcpy ( V_182 + V_192 , V_181 -> V_194 , V_181 -> V_39 ) ;
V_161 = F_108 ( V_1 , V_182 , V_184 , V_183 , V_185 ) ;
if ( V_161 > 0 ) {
V_181 -> V_195 = V_183 [ 0 ] >> 4 ;
if ( V_161 > 1 ) {
V_161 = F_116 ( int , V_183 [ 1 ] , 0 , V_181 -> V_39 ) ;
} else {
V_161 = V_181 -> V_39 ;
}
}
break;
case V_196 :
case V_197 :
V_184 = V_181 -> V_39 ? V_192 : V_193 ;
V_185 = V_181 -> V_39 + 1 ;
if ( F_25 ( V_185 > 20 ) )
return - V_169 ;
V_161 = F_108 ( V_1 , V_182 , V_184 , V_183 , V_185 ) ;
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
static enum V_91 F_117 ( struct V_25 * V_26 ,
enum V_91 V_91 )
{
const struct V_199 * V_200 =
& V_26 -> V_201 . V_202 [ V_91 ] ;
enum V_91 V_203 ;
if ( ! V_200 -> V_204 ) {
F_49 ( L_17 ,
F_48 ( V_91 ) , F_48 ( V_91 ) ) ;
return V_91 ;
}
switch ( V_200 -> V_204 ) {
case V_205 :
V_203 = V_141 ;
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
F_118 ( V_200 -> V_204 ) ;
V_203 = V_141 ;
break;
}
F_49 ( L_18 ,
F_48 ( V_203 ) , F_48 ( V_91 ) ) ;
return V_203 ;
}
static T_6 F_119 ( struct V_25 * V_26 ,
enum V_91 V_91 )
{
switch ( V_91 ) {
case V_207 :
case V_209 :
case V_211 :
return F_120 ( V_91 ) ;
default:
F_118 ( V_91 ) ;
return F_120 ( V_207 ) ;
}
}
static T_6 F_121 ( struct V_25 * V_26 ,
enum V_91 V_91 , int V_51 )
{
switch ( V_91 ) {
case V_207 :
case V_209 :
case V_211 :
return F_122 ( V_91 , V_51 ) ;
default:
F_118 ( V_91 ) ;
return F_122 ( V_207 , V_51 ) ;
}
}
static T_6 F_123 ( struct V_25 * V_26 ,
enum V_91 V_91 )
{
switch ( V_91 ) {
case V_141 :
return F_120 ( V_91 ) ;
case V_207 :
case V_209 :
case V_211 :
return F_124 ( V_91 ) ;
default:
F_118 ( V_91 ) ;
return F_120 ( V_141 ) ;
}
}
static T_6 F_125 ( struct V_25 * V_26 ,
enum V_91 V_91 , int V_51 )
{
switch ( V_91 ) {
case V_141 :
return F_122 ( V_91 , V_51 ) ;
case V_207 :
case V_209 :
case V_211 :
return F_126 ( V_91 , V_51 ) ;
default:
F_118 ( V_91 ) ;
return F_122 ( V_141 , V_51 ) ;
}
}
static T_6 F_127 ( struct V_25 * V_26 ,
enum V_91 V_91 )
{
switch ( V_91 ) {
case V_141 :
case V_207 :
case V_209 :
case V_211 :
return F_120 ( V_91 ) ;
default:
F_118 ( V_91 ) ;
return F_120 ( V_141 ) ;
}
}
static T_6 F_128 ( struct V_25 * V_26 ,
enum V_91 V_91 , int V_51 )
{
switch ( V_91 ) {
case V_141 :
case V_207 :
case V_209 :
case V_211 :
return F_122 ( V_91 , V_51 ) ;
default:
F_118 ( V_91 ) ;
return F_122 ( V_141 , V_51 ) ;
}
}
static T_6 F_129 ( struct V_25 * V_26 ,
enum V_91 V_91 )
{
if ( F_130 ( V_26 ) -> V_212 >= 9 )
return F_127 ( V_26 , V_91 ) ;
else if ( F_131 ( V_26 ) )
return F_123 ( V_26 , V_91 ) ;
else
return F_119 ( V_26 , V_91 ) ;
}
static T_6 F_132 ( struct V_25 * V_26 ,
enum V_91 V_91 , int V_51 )
{
if ( F_130 ( V_26 ) -> V_212 >= 9 )
return F_128 ( V_26 , V_91 , V_51 ) ;
else if ( F_131 ( V_26 ) )
return F_125 ( V_26 , V_91 , V_51 ) ;
else
return F_121 ( V_26 , V_91 , V_51 ) ;
}
static void F_133 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_91 V_91 = F_117 ( V_26 ,
F_2 ( V_1 ) -> V_91 ) ;
int V_45 ;
V_1 -> V_136 = F_129 ( V_26 , V_91 ) ;
for ( V_45 = 0 ; V_45 < F_20 ( V_1 -> V_173 ) ; V_45 ++ )
V_1 -> V_173 [ V_45 ] = F_132 ( V_26 , V_91 , V_45 ) ;
}
static void
F_134 ( struct V_1 * V_1 )
{
F_135 ( V_1 -> V_179 . V_213 ) ;
}
static void
F_136 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
F_133 ( V_1 ) ;
F_137 ( & V_1 -> V_179 ) ;
V_1 -> V_179 . V_213 = F_138 ( V_214 , L_19 , F_48 ( V_91 ) ) ;
V_1 -> V_179 . V_215 = F_115 ;
}
bool F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
if ( ( F_139 ( V_26 ) && ! F_140 ( V_26 ) ) ||
F_104 ( V_26 ) || ( F_141 ( V_26 ) >= 9 ) )
return true ;
else
return false ;
}
static void
F_142 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
const struct V_218 * V_219 = NULL ;
int V_45 , V_220 = 0 ;
if ( F_143 ( V_26 ) ) {
V_219 = V_221 ;
V_220 = F_20 ( V_221 ) ;
} else if ( F_131 ( V_26 ) ) {
V_219 = V_222 ;
V_220 = F_20 ( V_222 ) ;
} else if ( F_51 ( V_26 ) ) {
V_219 = V_99 ;
V_220 = F_20 ( V_99 ) ;
} else if ( F_78 ( V_26 ) ) {
V_219 = V_101 ;
V_220 = F_20 ( V_101 ) ;
}
if ( V_219 && V_220 ) {
for ( V_45 = 0 ; V_45 < V_220 ; V_45 ++ ) {
if ( V_217 -> V_223 == V_219 [ V_45 ] . clock ) {
V_217 -> V_100 = V_219 [ V_45 ] . V_100 ;
V_217 -> V_224 = true ;
break;
}
}
}
}
static void F_144 ( char * V_225 , T_8 V_226 ,
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
static void F_145 ( struct V_1 * V_1 )
{
const int * V_37 , * V_33 ;
int V_42 , V_43 , V_50 ;
int V_44 [ V_48 ] ;
char V_225 [ 128 ] ;
if ( ( V_230 & V_231 ) == 0 )
return;
V_42 = F_18 ( V_1 , & V_37 ) ;
F_144 ( V_225 , sizeof( V_225 ) , V_37 , V_42 ) ;
F_49 ( L_23 , V_225 ) ;
V_43 = F_17 ( V_1 , & V_33 ) ;
F_144 ( V_225 , sizeof( V_225 ) , V_33 , V_43 ) ;
F_49 ( L_24 , V_225 ) ;
V_50 = F_26 ( V_1 , V_44 ) ;
F_144 ( V_225 , sizeof( V_225 ) , V_44 , V_50 ) ;
F_49 ( L_25 , V_225 ) ;
}
bool
F_146 ( struct V_1 * V_1 , struct V_232 * V_233 )
{
T_5 V_4 = F_147 ( V_1 -> V_11 ) ? V_234 :
V_235 ;
return F_148 ( & V_1 -> V_179 , V_4 , V_233 , sizeof( * V_233 ) ) ==
sizeof( * V_233 ) ;
}
bool F_149 ( struct V_1 * V_1 )
{
struct V_232 * V_233 = & V_1 -> V_233 ;
bool V_236 = V_1 -> V_11 [ V_237 ] &
V_238 ;
int V_239 ;
if ( ! F_146 ( V_1 , V_233 ) )
return false ;
V_239 = F_150 ( V_233 -> V_240 , sizeof( V_233 -> V_240 ) ) ;
F_49 ( L_26 ,
F_147 ( V_1 -> V_11 ) ? L_27 : L_28 ,
( int ) sizeof( V_233 -> V_241 ) , V_233 -> V_241 , V_236 ? L_22 : L_29 ,
V_239 , V_233 -> V_240 ,
V_233 -> V_242 >> 4 , V_233 -> V_242 & 0xf ,
V_233 -> V_243 , V_233 -> V_244 ) ;
return true ;
}
static int F_151 ( int V_245 , const int * V_246 )
{
int V_45 = 0 ;
for ( V_45 = 0 ; V_45 < V_48 ; ++ V_45 )
if ( V_245 == V_246 [ V_45 ] )
break;
return V_45 ;
}
int
F_33 ( struct V_1 * V_1 )
{
int V_246 [ V_48 ] = {} ;
int V_226 ;
V_226 = F_26 ( V_1 , V_246 ) ;
if ( F_25 ( V_226 <= 0 ) )
return 162000 ;
return V_246 [ V_226 - 1 ] ;
}
int F_152 ( struct V_1 * V_1 , int V_247 )
{
return F_151 ( V_247 , V_1 -> V_33 ) ;
}
void F_153 ( struct V_1 * V_1 , int V_223 ,
T_2 * V_248 , T_2 * V_249 )
{
if ( V_1 -> V_34 ) {
* V_248 = 0 ;
* V_249 =
F_152 ( V_1 , V_223 ) ;
} else {
* V_248 = F_29 ( V_223 ) ;
* V_249 = 0 ;
}
}
static int F_154 ( struct V_1 * V_1 ,
struct V_216 * V_217 )
{
int V_21 , V_250 ;
V_21 = V_217 -> V_251 ;
V_250 = F_155 ( V_1 -> V_11 , V_1 -> V_30 ) ;
if ( V_250 > 0 )
V_21 = F_10 ( V_21 , 3 * V_250 ) ;
return V_21 ;
}
bool
F_156 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
struct V_55 * V_254 = & V_217 -> V_4 . V_254 ;
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
struct V_255 * V_255 = F_157 ( V_217 -> V_4 . V_256 ) ;
struct V_57 * V_57 = V_1 -> V_257 ;
int V_52 , clock ;
int V_258 = 1 ;
int V_259 = F_9 ( V_1 ) ;
int V_260 = 0 ;
int V_261 ;
int V_21 , V_62 ;
int V_262 , V_263 ;
int V_44 [ V_48 ] = {} ;
int V_50 ;
T_2 V_248 , V_249 ;
V_50 = F_26 ( V_1 , V_44 ) ;
F_25 ( V_50 <= 0 ) ;
V_261 = V_50 - 1 ;
if ( F_131 ( V_26 ) && ! F_158 ( V_26 ) && V_91 != V_141 )
V_217 -> V_264 = true ;
V_217 -> V_265 = false ;
V_217 -> V_266 = V_1 -> V_266 && V_91 != V_141 ;
if ( F_1 ( V_1 ) && V_57 -> V_59 . V_58 ) {
F_159 ( V_57 -> V_59 . V_58 ,
V_254 ) ;
if ( F_141 ( V_26 ) >= 9 ) {
int V_161 ;
V_161 = F_160 ( V_217 ) ;
if ( V_161 )
return V_161 ;
}
if ( F_161 ( V_26 ) )
F_162 ( V_255 , V_217 ,
V_57 -> V_59 . V_267 ) ;
else
F_163 ( V_255 , V_217 ,
V_57 -> V_59 . V_267 ) ;
}
if ( V_254 -> V_68 & V_69 )
return false ;
F_49 ( L_30
L_31 ,
V_259 , V_44 [ V_261 ] ,
V_254 -> V_268 ) ;
V_21 = F_154 ( V_1 , V_217 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_57 -> V_4 . V_269 . V_250 == 0 &&
( V_26 -> V_201 . V_270 . V_21 && V_26 -> V_201 . V_270 . V_21 < V_21 ) ) {
F_49 ( L_32 ,
V_26 -> V_201 . V_270 . V_21 ) ;
V_21 = V_26 -> V_201 . V_270 . V_21 ;
}
V_258 = V_259 ;
V_260 = V_261 ;
}
for (; V_21 >= 6 * 3 ; V_21 -= 2 * 3 ) {
V_62 = F_11 ( V_254 -> V_268 ,
V_21 ) ;
for ( clock = V_260 ; clock <= V_261 ; clock ++ ) {
for ( V_52 = V_258 ;
V_52 <= V_259 ;
V_52 <<= 1 ) {
V_263 = V_44 [ clock ] ;
V_262 = F_13 ( V_263 ,
V_52 ) ;
if ( V_62 <= V_262 ) {
goto V_271;
}
}
}
}
return false ;
V_271:
if ( V_1 -> V_272 ) {
V_217 -> V_273 =
V_21 != 18 &&
F_164 ( V_254 ) ==
V_274 ;
} else {
V_217 -> V_273 =
V_1 -> V_273 ;
}
V_217 -> V_52 = V_52 ;
V_217 -> V_251 = V_21 ;
V_217 -> V_223 = V_44 [ clock ] ;
F_153 ( V_1 , V_217 -> V_223 ,
& V_248 , & V_249 ) ;
F_49 ( L_33 ,
V_248 , V_249 , V_217 -> V_52 ,
V_217 -> V_223 , V_21 ) ;
F_49 ( L_34 ,
V_62 , V_262 ) ;
F_165 ( V_21 , V_52 ,
V_254 -> V_268 ,
V_217 -> V_223 ,
& V_217 -> V_275 ) ;
if ( V_57 -> V_59 . V_276 != NULL &&
V_26 -> V_277 . type == V_278 ) {
V_217 -> V_265 = true ;
F_165 ( V_21 , V_52 ,
V_57 -> V_59 . V_276 -> clock ,
V_217 -> V_223 ,
& V_217 -> V_279 ) ;
}
if ( F_1 ( V_1 ) &&
( F_21 ( V_26 ) || F_22 ( V_26 ) ) ) {
int V_280 ;
switch ( V_217 -> V_223 / 2 ) {
case 108000 :
case 216000 :
V_280 = 8640000 ;
break;
default:
V_280 = 8100000 ;
break;
}
F_166 ( V_217 -> V_4 . V_281 ) -> V_282 = V_280 ;
}
if ( ! F_158 ( V_26 ) )
F_142 ( V_24 , V_217 ) ;
return true ;
}
void F_167 ( struct V_1 * V_1 ,
int V_49 , T_2 V_52 ,
bool V_283 )
{
V_1 -> V_49 = V_49 ;
V_1 -> V_52 = V_52 ;
V_1 -> V_283 = V_283 ;
}
static void F_168 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
struct V_255 * V_256 = F_157 ( V_24 -> V_4 . V_256 ) ;
const struct V_55 * V_254 = & V_217 -> V_4 . V_254 ;
F_167 ( V_1 , V_217 -> V_223 ,
V_217 -> V_52 ,
F_169 ( V_217 ,
V_284 ) ) ;
V_1 -> V_88 = F_46 ( V_1 -> V_89 ) & V_92 ;
V_1 -> V_88 |= V_93 | V_94 ;
V_1 -> V_88 |= F_50 ( V_217 -> V_52 ) ;
if ( F_170 ( V_26 ) && V_91 == V_141 ) {
if ( V_254 -> V_68 & V_285 )
V_1 -> V_88 |= V_286 ;
if ( V_254 -> V_68 & V_287 )
V_1 -> V_88 |= V_288 ;
V_1 -> V_88 |= V_289 ;
if ( F_171 ( V_1 -> V_11 ) )
V_1 -> V_88 |= V_290 ;
V_1 -> V_88 |= V_256 -> V_80 << 29 ;
} else if ( F_172 ( V_26 ) && V_91 != V_141 ) {
T_5 V_291 ;
V_1 -> V_88 |= V_289 ;
V_291 = F_46 ( F_173 ( V_256 -> V_80 ) ) ;
if ( F_171 ( V_1 -> V_11 ) )
V_291 |= V_292 ;
else
V_291 &= ~ V_292 ;
F_56 ( F_173 ( V_256 -> V_80 ) , V_291 ) ;
} else {
if ( F_143 ( V_26 ) && V_217 -> V_273 )
V_1 -> V_88 |= V_293 ;
if ( V_254 -> V_68 & V_285 )
V_1 -> V_88 |= V_286 ;
if ( V_254 -> V_68 & V_287 )
V_1 -> V_88 |= V_288 ;
V_1 -> V_88 |= V_294 ;
if ( F_171 ( V_1 -> V_11 ) )
V_1 -> V_88 |= V_290 ;
if ( F_51 ( V_26 ) )
V_1 -> V_88 |= F_52 ( V_256 -> V_80 ) ;
else if ( V_256 -> V_80 == V_96 )
V_1 -> V_88 |= V_97 ;
}
}
static void F_174 ( struct V_1 * V_1 ,
T_5 V_295 ,
T_5 V_296 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_6 V_297 , V_128 ;
F_63 ( & V_26 -> V_79 ) ;
F_175 ( V_26 , V_1 ) ;
V_297 = F_83 ( V_1 ) ;
V_128 = F_82 ( V_1 ) ;
F_49 ( L_35 ,
V_295 , V_296 ,
F_46 ( V_297 ) ,
F_46 ( V_128 ) ) ;
if ( F_176 ( V_26 ,
V_297 , V_295 , V_296 ,
5000 ) )
F_30 ( L_36 ,
F_46 ( V_297 ) ,
F_46 ( V_128 ) ) ;
F_49 ( L_37 ) ;
}
static void F_177 ( struct V_1 * V_1 )
{
F_49 ( L_38 ) ;
F_174 ( V_1 , V_298 , V_299 ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_49 ( L_39 ) ;
F_174 ( V_1 , V_300 , V_301 ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
T_9 V_302 ;
T_10 V_303 ;
F_49 ( L_40 ) ;
V_302 = F_180 () ;
V_303 = F_181 ( V_302 , V_1 -> V_304 ) ;
if ( V_303 < ( T_10 ) V_1 -> V_133 )
F_182 ( V_305 ,
V_1 -> V_133 - V_303 ) ;
F_174 ( V_1 , V_306 , V_307 ) ;
}
static void F_183 ( struct V_1 * V_1 )
{
F_182 ( V_1 -> V_308 ,
V_1 -> V_309 ) ;
}
static void F_184 ( struct V_1 * V_1 )
{
F_182 ( V_1 -> V_310 ,
V_1 -> V_311 ) ;
}
static T_5 F_185 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_312 ;
F_63 ( & V_26 -> V_79 ) ;
V_312 = F_46 ( F_82 ( V_1 ) ) ;
if ( F_25 ( ! F_158 ( V_26 ) &&
( V_312 & V_313 ) != V_131 ) ) {
V_312 &= ~ V_313 ;
V_312 |= V_131 ;
}
return V_312 ;
}
static bool F_110 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
T_5 V_314 ;
T_6 V_297 , V_128 ;
bool V_315 = ! V_1 -> V_316 ;
F_63 ( & V_26 -> V_79 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
F_186 ( & V_1 -> V_317 ) ;
V_1 -> V_316 = true ;
if ( F_89 ( V_1 ) )
return V_315 ;
V_78 = F_37 ( V_23 ) ;
F_38 ( V_26 , V_78 ) ;
F_49 ( L_41 ,
F_48 ( V_3 -> V_91 ) ) ;
if ( ! F_88 ( V_1 ) )
F_179 ( V_1 ) ;
V_314 = F_185 ( V_1 ) ;
V_314 |= V_109 ;
V_297 = F_83 ( V_1 ) ;
V_128 = F_82 ( V_1 ) ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
F_49 ( L_42 ,
F_46 ( V_297 ) , F_46 ( V_128 ) ) ;
if ( ! F_88 ( V_1 ) ) {
F_49 ( L_43 ,
F_48 ( V_3 -> V_91 ) ) ;
F_87 ( V_1 -> V_318 ) ;
}
return V_315 ;
}
void F_187 ( struct V_1 * V_1 )
{
bool V_164 ;
if ( ! F_1 ( V_1 ) )
return;
F_36 ( V_1 ) ;
V_164 = F_110 ( V_1 ) ;
F_40 ( V_1 ) ;
F_188 ( ! V_164 , L_44 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) ;
}
static void F_189 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
enum V_77 V_78 ;
T_5 V_314 ;
T_6 V_297 , V_128 ;
F_63 ( & V_26 -> V_79 ) ;
F_25 ( V_1 -> V_316 ) ;
if ( ! F_89 ( V_1 ) )
return;
F_49 ( L_45 ,
F_48 ( V_3 -> V_91 ) ) ;
V_314 = F_185 ( V_1 ) ;
V_314 &= ~ V_109 ;
V_128 = F_82 ( V_1 ) ;
V_297 = F_83 ( V_1 ) ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
F_49 ( L_42 ,
F_46 ( V_297 ) , F_46 ( V_128 ) ) ;
if ( ( V_314 & V_319 ) == 0 )
V_1 -> V_304 = F_180 () ;
V_78 = F_37 ( V_23 ) ;
F_42 ( V_26 , V_78 ) ;
}
static void F_190 ( struct V_320 * V_321 )
{
struct V_1 * V_1 = F_85 ( F_191 ( V_321 ) ,
struct V_1 , V_317 ) ;
F_36 ( V_1 ) ;
if ( ! V_1 -> V_316 )
F_189 ( V_1 ) ;
F_40 ( V_1 ) ;
}
static void F_192 ( struct V_1 * V_1 )
{
unsigned long V_322 ;
V_322 = F_193 ( V_1 -> V_133 * 5 ) ;
F_194 ( & V_1 -> V_317 , V_322 ) ;
}
static void F_114 ( struct V_1 * V_1 , bool V_323 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
F_63 ( & V_26 -> V_79 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_188 ( ! V_1 -> V_316 , L_46 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) ;
V_1 -> V_316 = false ;
if ( V_323 )
F_189 ( V_1 ) ;
else
F_192 ( V_1 ) ;
}
static void F_195 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_314 ;
T_6 V_128 ;
F_63 ( & V_26 -> V_79 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_49 ( L_47 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) ;
if ( F_8 ( F_88 ( V_1 ) ,
L_48 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) )
return;
F_179 ( V_1 ) ;
V_128 = F_82 ( V_1 ) ;
V_314 = F_185 ( V_1 ) ;
if ( F_196 ( V_26 ) ) {
V_314 &= ~ V_324 ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
}
V_314 |= V_319 ;
if ( ! F_196 ( V_26 ) )
V_314 |= V_324 ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
F_177 ( V_1 ) ;
V_1 -> V_308 = V_305 ;
if ( F_196 ( V_26 ) ) {
V_314 |= V_324 ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
}
}
void F_197 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_36 ( V_1 ) ;
F_195 ( V_1 ) ;
F_40 ( V_1 ) ;
}
static void F_198 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
T_5 V_314 ;
T_6 V_128 ;
F_63 ( & V_26 -> V_79 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_49 ( L_49 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) ;
F_8 ( ! V_1 -> V_316 , L_50 ,
F_48 ( F_2 ( V_1 ) -> V_91 ) ) ;
V_314 = F_185 ( V_1 ) ;
V_314 &= ~ ( V_319 | V_324 | V_109 |
V_325 ) ;
V_128 = F_82 ( V_1 ) ;
V_1 -> V_316 = false ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
V_1 -> V_304 = F_180 () ;
F_178 ( V_1 ) ;
V_78 = F_37 ( V_23 ) ;
F_42 ( V_26 , V_78 ) ;
}
void F_199 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_36 ( V_1 ) ;
F_198 ( V_1 ) ;
F_40 ( V_1 ) ;
}
static void F_200 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_314 ;
T_6 V_128 ;
F_183 ( V_1 ) ;
F_36 ( V_1 ) ;
V_314 = F_185 ( V_1 ) ;
V_314 |= V_325 ;
V_128 = F_82 ( V_1 ) ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
F_40 ( V_1 ) ;
}
void F_201 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_49 ( L_51 ) ;
F_202 ( V_1 -> V_257 ) ;
F_200 ( V_1 ) ;
}
static void F_203 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_314 ;
T_6 V_128 ;
if ( ! F_1 ( V_1 ) )
return;
F_36 ( V_1 ) ;
V_314 = F_185 ( V_1 ) ;
V_314 &= ~ V_325 ;
V_128 = F_82 ( V_1 ) ;
F_56 ( V_128 , V_314 ) ;
F_57 ( V_128 ) ;
F_40 ( V_1 ) ;
V_1 -> V_310 = V_305 ;
F_184 ( V_1 ) ;
}
void F_204 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_49 ( L_51 ) ;
F_203 ( V_1 ) ;
F_205 ( V_1 -> V_257 ) ;
}
static void F_206 ( struct V_57 * V_9 ,
bool V_326 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_327 ;
F_36 ( V_1 ) ;
V_327 = F_185 ( V_1 ) & V_325 ;
F_40 ( V_1 ) ;
if ( V_327 == V_326 )
return;
F_49 ( L_52 ,
V_326 ? L_53 : L_54 ) ;
if ( V_326 )
F_200 ( V_1 ) ;
else
F_203 ( V_1 ) ;
}
static void F_207 ( struct V_1 * V_1 , bool V_281 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
bool V_328 = F_46 ( V_1 -> V_89 ) & V_90 ;
F_188 ( V_328 != V_281 ,
L_55 ,
F_48 ( V_38 -> V_91 ) ,
F_208 ( V_281 ) , F_208 ( V_328 ) ) ;
}
static void F_209 ( struct V_25 * V_26 , bool V_281 )
{
bool V_328 = F_46 ( V_329 ) & V_330 ;
F_188 ( V_328 != V_281 ,
L_56 ,
F_208 ( V_281 ) , F_208 ( V_328 ) ) ;
}
static void F_210 ( struct V_1 * V_1 ,
struct V_216 * V_217 )
{
struct V_255 * V_256 = F_157 ( V_217 -> V_4 . V_256 ) ;
struct V_25 * V_26 = F_15 ( V_256 -> V_4 . V_7 ) ;
F_211 ( V_26 , V_256 -> V_80 ) ;
F_212 ( V_1 ) ;
F_213 ( V_26 ) ;
F_49 ( L_57 ,
V_217 -> V_223 ) ;
V_1 -> V_88 &= ~ V_331 ;
if ( V_217 -> V_223 == 162000 )
V_1 -> V_88 |= V_332 ;
else
V_1 -> V_88 |= V_333 ;
F_56 ( V_329 , V_1 -> V_88 ) ;
F_57 ( V_329 ) ;
F_214 ( 500 ) ;
if ( F_196 ( V_26 ) )
F_215 ( V_26 , ! V_256 -> V_80 ) ;
V_1 -> V_88 |= V_330 ;
F_56 ( V_329 , V_1 -> V_88 ) ;
F_57 ( V_329 ) ;
F_214 ( 200 ) ;
}
static void F_216 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_255 * V_256 = F_157 ( V_3 -> V_4 . V_4 . V_256 ) ;
struct V_25 * V_26 = F_15 ( V_256 -> V_4 . V_7 ) ;
F_211 ( V_26 , V_256 -> V_80 ) ;
F_212 ( V_1 ) ;
F_217 ( V_26 ) ;
F_49 ( L_58 ) ;
V_1 -> V_88 &= ~ V_330 ;
F_56 ( V_329 , V_1 -> V_88 ) ;
F_57 ( V_329 ) ;
F_214 ( 200 ) ;
}
void F_218 ( struct V_1 * V_1 , int V_56 )
{
int V_161 , V_45 ;
if ( V_1 -> V_11 [ V_334 ] < 0x11 )
return;
if ( V_56 != V_335 ) {
V_161 = F_219 ( & V_1 -> V_179 , V_336 ,
V_337 ) ;
} else {
struct V_338 * V_339 = F_220 ( V_1 ) ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_161 = F_219 ( & V_1 -> V_179 , V_336 ,
V_340 ) ;
if ( V_161 == 1 )
break;
F_87 ( 1 ) ;
}
if ( V_161 == 1 && V_339 -> V_341 )
F_221 ( V_339 ) ;
}
if ( V_161 != 1 )
F_49 ( L_59 ,
V_56 == V_335 ? L_53 : L_54 ) ;
}
static bool F_222 ( struct V_23 * V_24 ,
enum V_80 * V_80 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
T_5 V_342 ;
bool V_161 ;
V_78 = F_223 ( V_24 ) ;
if ( ! F_224 ( V_26 , V_78 ) )
return false ;
V_161 = false ;
V_342 = F_46 ( V_1 -> V_89 ) ;
if ( ! ( V_342 & V_90 ) )
goto V_168;
if ( F_170 ( V_26 ) && V_91 == V_141 ) {
* V_80 = F_225 ( V_342 ) ;
} else if ( F_172 ( V_26 ) && V_91 != V_141 ) {
enum V_80 V_343 ;
F_226 (dev_priv, p) {
T_5 V_291 = F_46 ( F_173 ( V_343 ) ) ;
if ( F_227 ( V_291 ) == V_91 ) {
* V_80 = V_343 ;
V_161 = true ;
goto V_168;
}
}
F_49 ( L_60 ,
F_228 ( V_1 -> V_89 ) ) ;
} else if ( F_51 ( V_26 ) ) {
* V_80 = F_229 ( V_342 ) ;
} else {
* V_80 = F_230 ( V_342 ) ;
}
V_161 = true ;
V_168:
F_42 ( V_26 , V_78 ) ;
return V_161 ;
}
static void F_231 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
T_5 V_342 , V_68 = 0 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
struct V_255 * V_256 = F_157 ( V_24 -> V_4 . V_256 ) ;
V_342 = F_46 ( V_1 -> V_89 ) ;
V_217 -> V_266 = V_342 & V_344 && V_91 != V_141 ;
if ( F_172 ( V_26 ) && V_91 != V_141 ) {
T_5 V_291 = F_46 ( F_173 ( V_256 -> V_80 ) ) ;
if ( V_291 & V_345 )
V_68 |= V_285 ;
else
V_68 |= V_346 ;
if ( V_291 & V_347 )
V_68 |= V_287 ;
else
V_68 |= V_348 ;
} else {
if ( V_342 & V_286 )
V_68 |= V_285 ;
else
V_68 |= V_346 ;
if ( V_342 & V_288 )
V_68 |= V_287 ;
else
V_68 |= V_348 ;
}
V_217 -> V_4 . V_254 . V_68 |= V_68 ;
if ( F_143 ( V_26 ) && V_342 & V_293 )
V_217 -> V_273 = true ;
V_217 -> V_52 =
( ( V_342 & V_349 ) >> V_350 ) + 1 ;
F_232 ( V_256 , V_217 ) ;
if ( V_91 == V_141 ) {
if ( ( F_46 ( V_329 ) & V_331 ) == V_332 )
V_217 -> V_223 = 162000 ;
else
V_217 -> V_223 = 270000 ;
}
V_217 -> V_4 . V_254 . V_268 =
F_233 ( V_217 -> V_223 ,
& V_217 -> V_275 ) ;
if ( F_1 ( V_1 ) && V_26 -> V_201 . V_270 . V_21 &&
V_217 -> V_251 > V_26 -> V_201 . V_270 . V_21 ) {
F_49 ( L_61 ,
V_217 -> V_251 , V_26 -> V_201 . V_270 . V_21 ) ;
V_26 -> V_201 . V_270 . V_21 = V_217 -> V_251 ;
}
}
static void F_234 ( struct V_23 * V_24 ,
struct V_216 * V_351 ,
struct V_252 * V_352 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
if ( V_351 -> V_266 )
F_235 ( V_24 ) ;
if ( F_236 ( V_26 ) && ! F_158 ( V_26 ) )
F_237 ( V_1 ) ;
F_187 ( V_1 ) ;
F_204 ( V_1 ) ;
F_218 ( V_1 , V_353 ) ;
F_199 ( V_1 ) ;
if ( F_141 ( V_26 ) < 5 )
F_238 ( V_1 ) ;
}
static void F_239 ( struct V_23 * V_24 ,
struct V_216 * V_351 ,
struct V_252 * V_352 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
F_238 ( V_1 ) ;
if ( V_91 == V_141 )
F_216 ( V_1 ) ;
}
static void F_240 ( struct V_23 * V_24 ,
struct V_216 * V_351 ,
struct V_252 * V_352 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_238 ( V_1 ) ;
}
static void F_241 ( struct V_23 * V_24 ,
struct V_216 * V_351 ,
struct V_252 * V_352 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_238 ( V_1 ) ;
F_39 ( & V_26 -> V_354 ) ;
F_242 ( V_24 , true ) ;
F_41 ( & V_26 -> V_354 ) ;
}
static void
F_243 ( struct V_1 * V_1 ,
T_3 * V_88 ,
T_2 V_355 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
if ( V_355 & V_356 )
F_49 ( L_62 ,
V_355 & V_356 ) ;
if ( F_158 ( V_26 ) ) {
T_3 V_357 = F_46 ( F_244 ( V_91 ) ) ;
if ( V_355 & V_358 )
V_357 |= V_359 ;
else
V_357 &= ~ V_359 ;
V_357 &= ~ V_360 ;
switch ( V_355 & V_356 ) {
case V_361 :
V_357 |= V_362 ;
break;
case V_363 :
V_357 |= V_364 ;
break;
case V_365 :
V_357 |= V_366 ;
break;
case V_367 :
V_357 |= V_368 ;
break;
}
F_56 ( F_244 ( V_91 ) , V_357 ) ;
} else if ( ( F_170 ( V_26 ) && V_91 == V_141 ) ||
( F_172 ( V_26 ) && V_91 != V_141 ) ) {
* V_88 &= ~ V_369 ;
switch ( V_355 & V_356 ) {
case V_361 :
* V_88 |= V_289 ;
break;
case V_363 :
* V_88 |= V_370 ;
break;
case V_365 :
* V_88 |= V_371 ;
break;
case V_367 :
F_49 ( L_63 ) ;
* V_88 |= V_371 ;
break;
}
} else {
if ( F_51 ( V_26 ) )
* V_88 &= ~ V_372 ;
else
* V_88 &= ~ V_373 ;
switch ( V_355 & V_356 ) {
case V_361 :
* V_88 |= V_294 ;
break;
case V_363 :
* V_88 |= V_95 ;
break;
case V_365 :
* V_88 |= V_374 ;
break;
case V_367 :
if ( F_51 ( V_26 ) ) {
* V_88 |= V_375 ;
} else {
F_49 ( L_63 ) ;
* V_88 |= V_374 ;
}
break;
}
}
}
static void F_245 ( struct V_1 * V_1 ,
struct V_216 * V_351 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
F_246 ( V_1 , V_363 ) ;
V_1 -> V_88 |= V_90 ;
if ( V_351 -> V_266 )
V_1 -> V_88 |= V_344 ;
F_56 ( V_1 -> V_89 , V_1 -> V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
}
static void F_247 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_255 * V_256 = F_157 ( V_24 -> V_4 . V_256 ) ;
T_3 V_376 = F_46 ( V_1 -> V_89 ) ;
enum V_80 V_80 = V_256 -> V_80 ;
if ( F_25 ( V_376 & V_90 ) )
return;
F_36 ( V_1 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
F_248 ( V_1 ) ;
F_245 ( V_1 , V_217 ) ;
F_110 ( V_1 ) ;
F_195 ( V_1 ) ;
F_114 ( V_1 , true ) ;
F_40 ( V_1 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
unsigned int V_377 = 0x0 ;
if ( F_51 ( V_26 ) )
V_377 = F_249 ( V_217 -> V_52 ) ;
F_250 ( V_26 , F_2 ( V_1 ) ,
V_377 ) ;
}
F_218 ( V_1 , V_335 ) ;
F_251 ( V_1 ) ;
F_252 ( V_1 ) ;
if ( V_217 -> V_266 ) {
F_253 ( L_64 ,
F_47 ( V_80 ) ) ;
F_254 ( V_24 , V_217 , V_253 ) ;
}
}
static void F_255 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_247 ( V_24 , V_217 , V_253 ) ;
F_201 ( V_1 ) ;
}
static void F_256 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
F_201 ( V_1 ) ;
F_257 ( V_1 ) ;
}
static void F_258 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
struct V_1 * V_1 = F_5 ( & V_24 -> V_4 ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
F_168 ( V_24 , V_217 ) ;
if ( V_91 == V_141 )
F_210 ( V_1 , V_217 ) ;
}
static void F_259 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
enum V_80 V_80 = V_1 -> V_81 ;
T_6 V_378 = F_74 ( V_80 ) ;
F_25 ( V_1 -> V_105 != V_106 ) ;
if ( F_25 ( V_80 != V_103 && V_80 != V_96 ) )
return;
F_189 ( V_1 ) ;
F_49 ( L_65 ,
F_47 ( V_80 ) , F_48 ( V_3 -> V_91 ) ) ;
F_56 ( V_378 , 0 ) ;
F_57 ( V_378 ) ;
V_1 -> V_81 = V_106 ;
}
static void F_64 ( struct V_6 * V_7 ,
enum V_80 V_80 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_23 * V_24 ;
F_63 ( & V_26 -> V_79 ) ;
F_60 (dev, encoder) {
struct V_1 * V_1 ;
enum V_91 V_91 ;
if ( V_24 -> type != V_104 &&
V_24 -> type != V_5 )
continue;
V_1 = F_5 ( & V_24 -> V_4 ) ;
V_91 = F_2 ( V_1 ) -> V_91 ;
F_8 ( V_1 -> V_105 == V_80 ,
L_66 ,
F_47 ( V_80 ) , F_48 ( V_91 ) ) ;
if ( V_1 -> V_81 != V_80 )
continue;
F_49 ( L_67 ,
F_47 ( V_80 ) , F_48 ( V_91 ) ) ;
F_259 ( V_1 ) ;
}
}
static void F_248 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_24 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_24 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_255 * V_256 = F_157 ( V_24 -> V_4 . V_256 ) ;
F_63 ( & V_26 -> V_79 ) ;
F_25 ( V_1 -> V_105 != V_106 ) ;
if ( V_1 -> V_81 != V_106 &&
V_1 -> V_81 != V_256 -> V_80 ) {
F_259 ( V_1 ) ;
}
F_64 ( V_7 , V_256 -> V_80 ) ;
V_1 -> V_105 = V_256 -> V_80 ;
if ( ! F_1 ( V_1 ) )
return;
V_1 -> V_81 = V_256 -> V_80 ;
F_49 ( L_68 ,
F_47 ( V_1 -> V_81 ) , F_48 ( V_3 -> V_91 ) ) ;
F_65 ( V_7 , V_1 ) ;
F_66 ( V_7 , V_1 , true ) ;
}
static void F_260 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
F_261 ( V_24 ) ;
F_247 ( V_24 , V_217 , V_253 ) ;
}
static void F_262 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
F_168 ( V_24 , V_217 ) ;
F_263 ( V_24 ) ;
}
static void F_264 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
F_265 ( V_24 ) ;
F_247 ( V_24 , V_217 , V_253 ) ;
F_266 ( V_24 ) ;
}
static void F_267 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
F_168 ( V_24 , V_217 ) ;
F_268 ( V_24 ) ;
}
static void F_269 ( struct V_23 * V_24 ,
struct V_216 * V_217 ,
struct V_252 * V_253 )
{
F_270 ( V_24 ) ;
}
bool
F_271 ( struct V_1 * V_1 , T_2 V_379 [ V_380 ] )
{
return F_148 ( & V_1 -> V_179 , V_381 , V_379 ,
V_380 ) == V_380 ;
}
static bool F_272 ( struct V_1 * V_1 )
{
T_2 V_382 = 0 ;
F_273 ( & V_1 -> V_179 , V_383 , & V_382 ) ;
return V_382 & V_384 ;
}
static bool F_274 ( struct V_1 * V_1 )
{
T_2 V_385 = 0 ;
F_273 ( & V_1 -> V_179 ,
V_386 ,
& V_385 ) ;
return V_385 & V_387 ;
}
static bool F_275 ( struct V_1 * V_1 )
{
T_2 V_388 = 0 ;
F_273 ( & V_1 -> V_179 , V_389 , & V_388 ) ;
return V_388 & V_390 ;
}
T_2
F_276 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
if ( F_19 ( V_26 ) )
return V_391 ;
else if ( F_141 ( V_26 ) >= 9 ) {
if ( V_26 -> V_201 . V_270 . V_392 && V_91 == V_141 )
return V_391 ;
return V_393 ;
} else if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
return V_391 ;
else if ( F_170 ( V_26 ) && V_91 == V_141 )
return V_393 ;
else if ( F_172 ( V_26 ) && V_91 != V_141 )
return V_391 ;
else
return V_393 ;
}
T_2
F_277 ( struct V_1 * V_1 , T_2 V_394 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
if ( F_141 ( V_26 ) >= 9 ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
return V_401 ;
default:
return V_401 ;
}
} else if ( F_139 ( V_26 ) || F_104 ( V_26 ) ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
} else if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_397 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
} else if ( F_170 ( V_26 ) && V_91 == V_141 ) {
switch ( V_394 & V_395 ) {
case V_396 :
return V_399 ;
case V_398 :
case V_393 :
return V_400 ;
default:
return V_401 ;
}
} else {
switch ( V_394 & V_395 ) {
case V_396 :
return V_399 ;
case V_398 :
return V_399 ;
case V_393 :
return V_400 ;
case V_391 :
default:
return V_401 ;
}
}
}
static T_3 F_278 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
unsigned long V_402 , V_403 ,
V_404 ;
T_2 V_405 = V_1 -> V_405 [ 0 ] ;
switch ( V_405 & V_406 ) {
case V_401 :
V_403 = 0x0004000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B405555 ;
V_404 = 0x552AB83A ;
break;
case V_398 :
V_402 = 0x2B404040 ;
V_404 = 0x5548B83A ;
break;
case V_393 :
V_402 = 0x2B245555 ;
V_404 = 0x5560B83A ;
break;
case V_391 :
V_402 = 0x2B405555 ;
V_404 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_400 :
V_403 = 0x0002000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B404040 ;
V_404 = 0x5552B83A ;
break;
case V_398 :
V_402 = 0x2B404848 ;
V_404 = 0x5580B83A ;
break;
case V_393 :
V_402 = 0x2B404040 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_399 :
V_403 = 0x0000000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x2B305555 ;
V_404 = 0x5570B83A ;
break;
case V_398 :
V_402 = 0x2B2B4040 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_397 :
V_403 = 0x0006000 ;
switch ( V_405 & V_395 ) {
case V_396 :
V_402 = 0x1B405555 ;
V_404 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_279 ( V_24 , V_402 , V_403 ,
V_404 , 0 ) ;
return 0 ;
}
static T_3 F_280 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_407 , V_408 ;
bool V_409 = false ;
T_2 V_405 = V_1 -> V_405 [ 0 ] ;
switch ( V_405 & V_406 ) {
case V_401 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 128 ;
V_408 = 52 ;
break;
case V_398 :
V_407 = 128 ;
V_408 = 77 ;
break;
case V_393 :
V_407 = 128 ;
V_408 = 102 ;
break;
case V_391 :
V_407 = 128 ;
V_408 = 154 ;
V_409 = true ;
break;
default:
return 0 ;
}
break;
case V_400 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 85 ;
V_408 = 78 ;
break;
case V_398 :
V_407 = 85 ;
V_408 = 116 ;
break;
case V_393 :
V_407 = 85 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
case V_399 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 64 ;
V_408 = 104 ;
break;
case V_398 :
V_407 = 64 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
case V_397 :
switch ( V_405 & V_395 ) {
case V_396 :
V_407 = 43 ;
V_408 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_281 ( V_24 , V_407 ,
V_408 , V_409 ) ;
return 0 ;
}
static T_3
F_282 ( T_2 V_405 )
{
T_3 V_410 = 0 ;
switch ( V_405 & V_395 ) {
case V_396 :
default:
V_410 |= V_93 ;
break;
case V_398 :
V_410 |= V_411 ;
break;
case V_393 :
V_410 |= V_412 ;
break;
case V_391 :
V_410 |= V_413 ;
break;
}
switch ( V_405 & V_406 ) {
case V_401 :
default:
V_410 |= V_94 ;
break;
case V_400 :
V_410 |= V_414 ;
break;
case V_399 :
V_410 |= V_415 ;
break;
case V_397 :
V_410 |= V_416 ;
break;
}
return V_410 ;
}
static T_3
F_283 ( T_2 V_405 )
{
int V_410 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_410 ) {
case V_396 | V_401 :
case V_398 | V_401 :
return V_417 ;
case V_396 | V_400 :
return V_418 ;
case V_396 | V_399 :
case V_398 | V_399 :
return V_419 ;
case V_398 | V_400 :
case V_393 | V_400 :
return V_420 ;
case V_393 | V_401 :
case V_391 | V_401 :
return V_421 ;
default:
F_49 ( L_69
L_70 , V_410 ) ;
return V_417 ;
}
}
static T_3
F_284 ( T_2 V_405 )
{
int V_410 = V_405 & ( V_395 |
V_406 ) ;
switch ( V_410 ) {
case V_396 | V_401 :
return V_422 ;
case V_396 | V_400 :
return V_423 ;
case V_396 | V_399 :
return V_424 ;
case V_398 | V_401 :
return V_425 ;
case V_398 | V_400 :
return V_426 ;
case V_393 | V_401 :
return V_427 ;
case V_393 | V_400 :
return V_428 ;
default:
F_49 ( L_69
L_70 , V_410 ) ;
return V_429 ;
}
}
void
F_285 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_3 V_410 , V_295 = 0 ;
T_2 V_405 = V_1 -> V_405 [ 0 ] ;
if ( F_158 ( V_26 ) ) {
V_410 = F_286 ( V_1 ) ;
if ( F_19 ( V_26 ) )
V_410 = 0 ;
else
V_295 = V_430 ;
} else if ( F_51 ( V_26 ) ) {
V_410 = F_280 ( V_1 ) ;
} else if ( F_78 ( V_26 ) ) {
V_410 = F_278 ( V_1 ) ;
} else if ( F_170 ( V_26 ) && V_91 == V_141 ) {
V_410 = F_284 ( V_405 ) ;
V_295 = V_431 ;
} else if ( F_103 ( V_26 ) && V_91 == V_141 ) {
V_410 = F_283 ( V_405 ) ;
V_295 = V_432 ;
} else {
V_410 = F_282 ( V_405 ) ;
V_295 = V_433 | V_434 ;
}
if ( V_295 )
F_49 ( L_71 , V_410 ) ;
F_49 ( L_72 ,
V_405 & V_395 ) ;
F_49 ( L_73 ,
( V_405 & V_406 ) >>
V_435 ) ;
V_1 -> V_88 = ( V_1 -> V_88 & ~ V_295 ) | V_410 ;
F_56 ( V_1 -> V_89 , V_1 -> V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
}
void
F_246 ( struct V_1 * V_1 ,
T_2 V_355 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_25 * V_26 =
F_15 ( V_3 -> V_4 . V_4 . V_7 ) ;
F_243 ( V_1 , & V_1 -> V_88 , V_355 ) ;
F_56 ( V_1 -> V_89 , V_1 -> V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
}
void F_287 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
T_3 V_436 ;
if ( ! F_158 ( V_26 ) )
return;
V_436 = F_46 ( F_244 ( V_91 ) ) ;
V_436 &= ~ V_360 ;
V_436 |= V_437 ;
F_56 ( F_244 ( V_91 ) , V_436 ) ;
if ( V_91 == V_141 )
return;
if ( F_176 ( V_26 , F_288 ( V_91 ) ,
V_438 ,
V_438 ,
1 ) )
F_30 ( L_74 ) ;
}
static void
F_238 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_255 * V_256 = F_157 ( V_3 -> V_4 . V_4 . V_256 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_3 V_88 = V_1 -> V_88 ;
if ( F_25 ( F_158 ( V_26 ) ) )
return;
if ( F_25 ( ( F_46 ( V_1 -> V_89 ) & V_90 ) == 0 ) )
return;
F_49 ( L_51 ) ;
if ( ( F_170 ( V_26 ) && V_91 == V_141 ) ||
( F_172 ( V_26 ) && V_91 != V_141 ) ) {
V_88 &= ~ V_369 ;
V_88 |= V_439 ;
} else {
if ( F_51 ( V_26 ) )
V_88 &= ~ V_372 ;
else
V_88 &= ~ V_373 ;
V_88 |= V_440 ;
}
F_56 ( V_1 -> V_89 , V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
V_88 &= ~ ( V_90 | V_344 ) ;
F_56 ( V_1 -> V_89 , V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
if ( F_289 ( V_26 ) && V_256 -> V_80 == V_96 && V_91 != V_141 ) {
F_290 ( V_26 , V_103 , false ) ;
F_291 ( V_26 , V_103 , false ) ;
V_88 &= ~ ( V_97 | V_373 ) ;
V_88 |= V_90 | V_95 ;
F_56 ( V_1 -> V_89 , V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
V_88 &= ~ V_90 ;
F_56 ( V_1 -> V_89 , V_88 ) ;
F_57 ( V_1 -> V_89 ) ;
F_215 ( V_26 , V_103 ) ;
F_290 ( V_26 , V_103 , true ) ;
F_291 ( V_26 , V_103 , true ) ;
}
F_87 ( V_1 -> V_441 ) ;
V_1 -> V_88 = V_88 ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
F_36 ( V_1 ) ;
V_1 -> V_105 = V_106 ;
F_40 ( V_1 ) ;
}
}
bool
F_292 ( struct V_1 * V_1 )
{
if ( F_148 ( & V_1 -> V_179 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_49 ( L_75 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
return V_1 -> V_11 [ V_334 ] != 0 ;
}
static bool
F_293 ( struct V_1 * V_1 )
{
struct V_25 * V_26 =
F_15 ( F_2 ( V_1 ) -> V_4 . V_4 . V_7 ) ;
F_25 ( V_1 -> V_11 [ V_334 ] != 0 ) ;
if ( ! F_292 ( V_1 ) )
return false ;
F_149 ( V_1 ) ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 )
V_26 -> V_442 = V_1 -> V_11 [ V_443 ] &
V_444 ;
F_148 ( & V_1 -> V_179 , V_445 ,
V_1 -> V_446 ,
sizeof( V_1 -> V_446 ) ) ;
if ( V_1 -> V_446 [ 0 ] & V_447 ) {
V_26 -> V_448 . V_449 = true ;
F_49 ( L_76 ) ;
}
if ( F_141 ( V_26 ) >= 9 &&
( V_1 -> V_446 [ 0 ] & V_450 ) ) {
T_2 V_451 ;
V_26 -> V_448 . V_449 = true ;
F_148 ( & V_1 -> V_179 ,
V_452 ,
& V_451 , 1 ) ;
V_26 -> V_448 . V_453 = V_451 ? true : false ;
V_26 -> V_448 . V_454 = V_26 -> V_448 . V_453 ;
F_49 ( L_77 ,
V_26 -> V_448 . V_454 ? L_78 : L_79 ) ;
if ( V_26 -> V_448 . V_454 ) {
V_26 -> V_448 . V_455 =
F_272 ( V_1 ) ;
V_26 -> V_448 . V_456 =
F_274 ( V_1 ) ;
V_26 -> V_448 . V_457 =
F_275 ( V_1 ) ;
}
}
if ( ( V_1 -> V_11 [ V_458 ] & V_459 ) &&
F_148 ( & V_1 -> V_179 , V_460 ,
V_1 -> V_461 , sizeof( V_1 -> V_461 ) ) ==
sizeof( V_1 -> V_461 ) )
F_49 ( L_80 , ( int ) sizeof( V_1 -> V_461 ) ,
V_1 -> V_461 ) ;
if ( V_1 -> V_461 [ 0 ] >= 0x03 ) {
T_11 V_33 [ V_48 ] ;
int V_45 ;
F_148 ( & V_1 -> V_179 , V_462 ,
V_33 , sizeof( V_33 ) ) ;
for ( V_45 = 0 ; V_45 < F_20 ( V_33 ) ; V_45 ++ ) {
int V_436 = F_294 ( V_33 [ V_45 ] ) ;
if ( V_436 == 0 )
break;
V_1 -> V_33 [ V_45 ] = ( V_436 * 200 ) / 10 ;
}
V_1 -> V_34 = V_45 ;
}
return true ;
}
static bool
F_295 ( struct V_1 * V_1 )
{
if ( ! F_292 ( V_1 ) )
return false ;
if ( F_148 ( & V_1 -> V_179 , V_463 ,
& V_1 -> V_464 , 1 ) < 0 )
return false ;
V_1 -> V_464 = F_296 ( V_1 -> V_464 ) ;
if ( ! F_1 ( V_1 ) && ! V_1 -> V_464 )
return false ;
if ( ! F_147 ( V_1 -> V_11 ) )
return true ;
if ( V_1 -> V_11 [ V_334 ] == 0x10 )
return true ;
if ( F_148 ( & V_1 -> V_179 , V_465 ,
V_1 -> V_30 ,
V_466 ) < 0 )
return false ;
return true ;
}
static bool
F_297 ( struct V_1 * V_1 )
{
T_1 V_467 [ 1 ] ;
if ( ! V_468 . V_469 )
return false ;
if ( ! V_1 -> V_470 )
return false ;
if ( V_1 -> V_11 [ V_334 ] < 0x12 )
return false ;
if ( F_148 ( & V_1 -> V_179 , V_471 , V_467 , 1 ) != 1 )
return false ;
return V_467 [ 0 ] & V_472 ;
}
static void
F_298 ( struct V_1 * V_1 )
{
if ( ! V_468 . V_469 )
return;
if ( ! V_1 -> V_470 )
return;
V_1 -> V_473 = F_297 ( V_1 ) ;
if ( V_1 -> V_473 )
F_49 ( L_81 ) ;
else
F_49 ( L_82 ) ;
F_299 ( & V_1 -> V_474 ,
V_1 -> V_473 ) ;
}
static int F_300 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_255 * V_255 = F_157 ( V_38 -> V_4 . V_4 . V_256 ) ;
T_1 V_467 ;
int V_161 = 0 ;
int V_220 = 0 ;
int V_475 = 10 ;
if ( F_273 ( & V_1 -> V_179 , V_476 , & V_467 ) < 0 ) {
F_49 ( L_83 ) ;
V_161 = - V_174 ;
goto V_168;
}
if ( F_219 ( & V_1 -> V_179 , V_476 ,
V_467 & ~ V_477 ) < 0 ) {
F_49 ( L_83 ) ;
V_161 = - V_174 ;
goto V_168;
}
do {
F_301 ( V_26 , V_255 -> V_80 ) ;
if ( F_273 ( & V_1 -> V_179 ,
V_478 , & V_467 ) < 0 ) {
V_161 = - V_174 ;
goto V_168;
}
V_220 = V_467 & V_479 ;
} while ( -- V_475 && V_220 );
if ( V_475 == 0 ) {
F_49 ( L_84 ) ;
V_161 = - V_175 ;
}
V_168:
F_302 ( V_255 ) ;
return V_161 ;
}
static int F_303 ( struct V_1 * V_1 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_255 * V_255 = F_157 ( V_38 -> V_4 . V_4 . V_256 ) ;
T_1 V_467 ;
int V_161 ;
if ( F_273 ( & V_1 -> V_179 , V_478 , & V_467 ) < 0 )
return - V_174 ;
if ( ! ( V_467 & V_480 ) )
return - V_481 ;
if ( F_273 ( & V_1 -> V_179 , V_476 , & V_467 ) < 0 )
return - V_174 ;
if ( V_467 & V_477 ) {
V_161 = F_300 ( V_1 ) ;
if ( V_161 )
return V_161 ;
}
F_304 ( V_255 ) ;
if ( F_219 ( & V_1 -> V_179 , V_476 ,
V_467 | V_477 ) < 0 ) {
F_302 ( V_255 ) ;
return - V_174 ;
}
F_301 ( V_26 , V_255 -> V_80 ) ;
return 0 ;
}
int F_305 ( struct V_1 * V_1 , T_1 * V_482 )
{
struct V_2 * V_38 = F_2 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_38 -> V_4 . V_4 . V_7 ) ;
struct V_255 * V_255 = F_157 ( V_38 -> V_4 . V_4 . V_256 ) ;
T_1 V_467 ;
int V_220 , V_161 ;
int V_475 = 6 ;
V_161 = F_303 ( V_1 ) ;
if ( V_161 )
return V_161 ;
do {
F_301 ( V_26 , V_255 -> V_80 ) ;
if ( F_273 ( & V_1 -> V_179 ,
V_478 , & V_467 ) < 0 ) {
V_161 = - V_174 ;
goto V_483;
}
V_220 = V_467 & V_479 ;
} while ( -- V_475 && V_220 == 0 );
if ( V_475 == 0 ) {
F_30 ( L_85 ) ;
V_161 = - V_175 ;
goto V_483;
}
if ( F_148 ( & V_1 -> V_179 , V_484 , V_482 , 6 ) < 0 ) {
V_161 = - V_174 ;
goto V_483;
}
V_483:
F_300 ( V_1 ) ;
return V_161 ;
}
static bool
F_306 ( struct V_1 * V_1 , T_1 * V_485 )
{
return F_148 ( & V_1 -> V_179 ,
V_486 ,
V_485 , 1 ) == 1 ;
}
static bool
F_307 ( struct V_1 * V_1 , T_1 * V_485 )
{
int V_161 ;
V_161 = F_148 ( & V_1 -> V_179 ,
V_487 ,
V_485 , 14 ) ;
if ( V_161 != 14 )
return false ;
return true ;
}
static T_2 F_308 ( struct V_1 * V_1 )
{
T_2 V_488 = V_489 ;
return V_488 ;
}
static T_2 F_309 ( struct V_1 * V_1 )
{
T_2 V_488 = V_490 ;
return V_488 ;
}
static T_2 F_310 ( struct V_1 * V_1 )
{
T_2 V_488 = V_490 ;
struct V_57 * V_57 = V_1 -> V_257 ;
struct V_8 * V_9 = & V_57 -> V_4 ;
if ( V_57 -> V_491 == NULL ||
V_9 -> V_492 ||
V_1 -> V_179 . V_493 > 6 ) {
if ( V_1 -> V_179 . V_494 > 0 ||
V_1 -> V_179 . V_493 > 0 )
F_49 ( L_86 ,
V_1 -> V_179 . V_494 ,
V_1 -> V_179 . V_493 ) ;
V_1 -> V_495 . V_496 . V_497 = V_498 ;
} else {
struct V_497 * V_499 = V_57 -> V_491 ;
V_499 += V_57 -> V_491 -> V_500 ;
if ( ! F_311 ( & V_1 -> V_179 ,
V_501 ,
& V_499 -> V_502 ,
1 ) )
F_49 ( L_87 ) ;
V_488 = V_489 | V_503 ;
V_1 -> V_495 . V_496 . V_497 = V_504 ;
}
V_1 -> V_495 . V_505 = 1 ;
return V_488 ;
}
static T_2 F_312 ( struct V_1 * V_1 )
{
T_2 V_488 = V_490 ;
return V_488 ;
}
static void F_313 ( struct V_1 * V_1 )
{
T_2 V_506 = V_490 ;
T_2 V_507 = 0 ;
int V_137 = 0 ;
V_137 = F_148 ( & V_1 -> V_179 , V_508 , & V_507 , 1 ) ;
if ( V_137 <= 0 ) {
F_49 ( L_88 ) ;
goto V_509;
}
switch ( V_507 ) {
case V_510 :
F_49 ( L_89 ) ;
V_1 -> V_495 . V_511 = V_510 ;
V_506 = F_308 ( V_1 ) ;
break;
case V_512 :
F_49 ( L_90 ) ;
V_1 -> V_495 . V_511 = V_512 ;
V_506 = F_309 ( V_1 ) ;
break;
case V_513 :
F_49 ( L_91 ) ;
V_1 -> V_495 . V_511 = V_513 ;
V_506 = F_310 ( V_1 ) ;
break;
case V_514 :
F_49 ( L_92 ) ;
V_1 -> V_495 . V_511 = V_514 ;
V_506 = F_312 ( V_1 ) ;
break;
default:
F_49 ( L_93 , V_507 ) ;
break;
}
V_509:
V_137 = F_311 ( & V_1 -> V_179 ,
V_515 ,
& V_506 , 1 ) ;
if ( V_137 <= 0 )
F_49 ( L_94 ) ;
}
static int
F_314 ( struct V_1 * V_1 )
{
bool V_516 ;
if ( V_1 -> V_473 ) {
T_1 V_517 [ 16 ] = { 0 } ;
int V_161 = 0 ;
int V_518 ;
bool V_519 ;
V_516 = F_307 ( V_1 , V_517 ) ;
V_520:
if ( V_516 == true ) {
if ( V_1 -> V_521 &&
! F_315 ( & V_517 [ 10 ] , V_1 -> V_52 ) ) {
F_49 ( L_95 ) ;
F_251 ( V_1 ) ;
F_252 ( V_1 ) ;
}
F_49 ( L_96 , V_517 ) ;
V_161 = F_316 ( & V_1 -> V_474 , V_517 , & V_519 ) ;
if ( V_519 ) {
for ( V_518 = 0 ; V_518 < 3 ; V_518 ++ ) {
int V_522 ;
V_522 = F_311 ( & V_1 -> V_179 ,
V_487 + 1 ,
& V_517 [ 1 ] , 3 ) ;
if ( V_522 == 3 ) {
break;
}
}
V_516 = F_307 ( V_1 , V_517 ) ;
if ( V_516 == true ) {
F_49 ( L_97 , V_517 ) ;
goto V_520;
}
} else
V_161 = 0 ;
return V_161 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_49 ( L_98 ) ;
V_1 -> V_473 = false ;
F_299 ( & V_1 -> V_474 , V_1 -> V_473 ) ;
F_317 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_198 ;
}
static void
F_318 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = & F_2 ( V_1 ) -> V_4 ;
struct V_25 * V_26 = F_15 ( V_24 -> V_4 . V_7 ) ;
struct V_255 * V_256 = F_157 ( V_24 -> V_4 . V_256 ) ;
F_290 ( V_26 , V_256 -> V_80 , false ) ;
if ( V_256 -> V_523 -> V_264 )
F_291 ( V_26 ,
F_319 ( V_256 ) , false ) ;
F_251 ( V_1 ) ;
F_252 ( V_1 ) ;
F_301 ( V_26 , V_256 -> V_80 ) ;
F_290 ( V_26 , V_256 -> V_80 , true ) ;
if ( V_256 -> V_523 -> V_264 )
F_291 ( V_26 ,
F_319 ( V_256 ) , true ) ;
}
static void
F_320 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = & F_2 ( V_1 ) -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_379 [ V_380 ] ;
F_25 ( ! F_321 ( & V_7 -> V_524 . V_525 ) ) ;
if ( ! F_271 ( V_1 , V_379 ) ) {
F_30 ( L_99 ) ;
return;
}
if ( ! V_23 -> V_4 . V_256 )
return;
if ( ! F_157 ( V_23 -> V_4 . V_256 ) -> V_341 )
return;
if ( ! V_1 -> V_52 )
return;
if ( ( V_1 -> V_495 . V_511 == V_510 ) ||
( ! F_315 ( V_379 , V_1 -> V_52 ) ) ) {
F_49 ( L_100 ,
V_23 -> V_4 . V_213 ) ;
F_318 ( V_1 ) ;
}
}
static bool
F_322 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_485 = 0 ;
T_1 V_526 = V_1 -> V_464 ;
bool V_161 ;
memset ( & V_1 -> V_495 , 0 , sizeof( V_1 -> V_495 ) ) ;
V_161 = F_295 ( V_1 ) ;
if ( ( V_526 != V_1 -> V_464 ) || ! V_161 ) {
return false ;
}
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
F_306 ( V_1 , & V_485 ) &&
V_485 != 0 ) {
F_219 ( & V_1 -> V_179 ,
V_486 ,
V_485 ) ;
if ( V_485 & V_527 )
F_253 ( L_101 ) ;
if ( V_485 & ( V_528 | V_529 ) )
F_253 ( L_102 ) ;
}
F_323 ( & V_7 -> V_524 . V_525 , NULL ) ;
F_320 ( V_1 ) ;
F_324 ( & V_7 -> V_524 . V_525 ) ;
return true ;
}
static enum V_530
F_325 ( struct V_1 * V_1 )
{
T_2 * V_11 = V_1 -> V_11 ;
T_2 type ;
if ( ! F_295 ( V_1 ) )
return V_531 ;
if ( F_1 ( V_1 ) )
return V_532 ;
if ( ! F_147 ( V_11 ) )
return V_532 ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
V_1 -> V_30 [ 0 ] & V_533 ) {
return V_1 -> V_464 ?
V_532 : V_531 ;
}
if ( F_297 ( V_1 ) )
return V_532 ;
if ( F_326 ( & V_1 -> V_179 . V_534 ) )
return V_532 ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 ) {
type = V_1 -> V_30 [ 0 ] & V_31 ;
if ( type == V_32 ||
type == V_535 )
return V_536 ;
} else {
type = V_1 -> V_11 [ V_537 ] &
V_538 ;
if ( type == V_539 ||
type == V_540 )
return V_536 ;
}
F_49 ( L_103 ) ;
return V_531 ;
}
static enum V_530
F_327 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_530 V_137 ;
V_137 = F_328 ( V_26 ) ;
if ( V_137 == V_536 )
V_137 = V_532 ;
return V_137 ;
}
static bool F_329 ( struct V_25 * V_26 ,
struct V_2 * V_91 )
{
T_5 V_541 ;
switch ( V_91 -> V_91 ) {
case V_141 :
return true ;
case V_207 :
V_541 = V_542 ;
break;
case V_209 :
V_541 = V_543 ;
break;
case V_211 :
V_541 = V_544 ;
break;
default:
F_118 ( V_91 -> V_91 ) ;
return false ;
}
return F_46 ( V_545 ) & V_541 ;
}
static bool F_330 ( struct V_25 * V_26 ,
struct V_2 * V_91 )
{
T_5 V_541 ;
switch ( V_91 -> V_91 ) {
case V_141 :
return true ;
case V_207 :
V_541 = V_546 ;
break;
case V_209 :
V_541 = V_547 ;
break;
case V_211 :
V_541 = V_548 ;
break;
case V_549 :
V_541 = V_550 ;
break;
default:
F_118 ( V_91 -> V_91 ) ;
return false ;
}
return F_46 ( V_545 ) & V_541 ;
}
static bool F_331 ( struct V_25 * V_26 ,
struct V_2 * V_91 )
{
T_5 V_541 ;
switch ( V_91 -> V_91 ) {
case V_207 :
V_541 = V_551 ;
break;
case V_209 :
V_541 = V_552 ;
break;
case V_211 :
V_541 = V_553 ;
break;
default:
F_118 ( V_91 -> V_91 ) ;
return false ;
}
return F_46 ( V_554 ) & V_541 ;
}
static bool F_332 ( struct V_25 * V_26 ,
struct V_2 * V_91 )
{
T_5 V_541 ;
switch ( V_91 -> V_91 ) {
case V_207 :
V_541 = V_555 ;
break;
case V_209 :
V_541 = V_556 ;
break;
case V_211 :
V_541 = V_557 ;
break;
default:
F_118 ( V_91 -> V_91 ) ;
return false ;
}
return F_46 ( V_554 ) & V_541 ;
}
static bool F_333 ( struct V_25 * V_26 ,
struct V_2 * V_3 )
{
struct V_23 * V_23 = & V_3 -> V_4 ;
enum V_91 V_91 ;
T_5 V_541 ;
F_334 ( V_23 -> V_558 , & V_91 ) ;
switch ( V_91 ) {
case V_141 :
V_541 = V_559 ;
break;
case V_207 :
V_541 = V_560 ;
break;
case V_209 :
V_541 = V_561 ;
break;
default:
F_118 ( V_91 ) ;
return false ;
}
return F_46 ( V_562 ) & V_541 ;
}
bool F_335 ( struct V_25 * V_26 ,
struct V_2 * V_91 )
{
if ( F_289 ( V_26 ) )
return F_329 ( V_26 , V_91 ) ;
else if ( F_131 ( V_26 ) )
return F_330 ( V_26 , V_91 ) ;
else if ( F_19 ( V_26 ) )
return F_333 ( V_26 , V_91 ) ;
else if ( F_336 ( V_26 ) )
return F_332 ( V_26 , V_91 ) ;
else
return F_331 ( V_26 , V_91 ) ;
}
static struct V_497 *
F_337 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_257 ;
if ( V_57 -> V_497 ) {
if ( F_338 ( V_57 -> V_497 ) )
return NULL ;
return F_339 ( V_57 -> V_497 ) ;
} else
return F_340 ( & V_57 -> V_4 ,
& V_1 -> V_179 . V_534 ) ;
}
static void
F_341 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_257 ;
struct V_497 * V_497 ;
F_342 ( V_1 ) ;
V_497 = F_337 ( V_1 ) ;
V_57 -> V_491 = V_497 ;
if ( V_1 -> V_563 != V_564 )
V_1 -> V_266 = V_1 -> V_563 == V_565 ;
else
V_1 -> V_266 = F_343 ( V_497 ) ;
}
static void
F_342 ( struct V_1 * V_1 )
{
struct V_57 * V_57 = V_1 -> V_257 ;
F_135 ( V_57 -> V_491 ) ;
V_57 -> V_491 = NULL ;
V_1 -> V_266 = false ;
}
static enum V_530
F_344 ( struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_530 V_137 ;
enum V_77 V_78 ;
T_1 V_485 = 0 ;
V_78 = F_37 ( V_23 ) ;
F_38 ( F_15 ( V_7 ) , V_78 ) ;
if ( F_1 ( V_1 ) )
V_137 = F_327 ( V_1 ) ;
else if ( F_335 ( F_15 ( V_7 ) ,
F_2 ( V_1 ) ) )
V_137 = F_325 ( V_1 ) ;
else
V_137 = V_531 ;
if ( V_137 == V_531 ) {
memset ( & V_1 -> V_495 , 0 , sizeof( V_1 -> V_495 ) ) ;
if ( V_1 -> V_473 ) {
F_49 ( L_104 ,
V_1 -> V_473 ,
V_1 -> V_474 . V_566 ) ;
V_1 -> V_473 = false ;
F_299 ( & V_1 -> V_474 ,
V_1 -> V_473 ) ;
}
goto V_168;
}
if ( V_23 -> type != V_5 )
V_23 -> type = V_104 ;
F_49 ( L_105 ,
F_345 ( F_23 ( V_1 ) ) ,
F_345 ( F_346 ( V_1 -> V_11 ) ) ) ;
V_1 -> V_19 = F_347 ( V_1 -> V_11 ) ;
V_1 -> V_36 = F_7 ( V_1 ) ;
F_145 ( V_1 ) ;
F_149 ( V_1 ) ;
F_298 ( V_1 ) ;
if ( V_1 -> V_473 ) {
V_137 = V_531 ;
goto V_168;
} else if ( V_9 -> V_137 == V_532 ) {
F_323 ( & V_7 -> V_524 . V_525 , NULL ) ;
F_320 ( V_1 ) ;
F_324 ( & V_7 -> V_524 . V_525 ) ;
goto V_168;
}
V_1 -> V_179 . V_494 = 0 ;
V_1 -> V_179 . V_493 = 0 ;
F_341 ( V_1 ) ;
if ( F_1 ( V_1 ) || V_57 -> V_491 )
V_137 = V_532 ;
V_1 -> V_567 = true ;
if ( V_1 -> V_11 [ V_334 ] >= 0x11 &&
F_306 ( V_1 , & V_485 ) &&
V_485 != 0 ) {
F_219 ( & V_1 -> V_179 ,
V_486 ,
V_485 ) ;
if ( V_485 & V_527 )
F_313 ( V_1 ) ;
if ( V_485 & ( V_528 | V_529 ) )
F_253 ( L_102 ) ;
}
V_168:
if ( V_137 != V_532 && ! V_1 -> V_473 )
F_342 ( V_1 ) ;
F_42 ( F_15 ( V_7 ) , V_78 ) ;
return V_137 ;
}
static enum V_530
F_348 ( struct V_8 * V_9 , bool V_568 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
enum V_530 V_137 = V_9 -> V_137 ;
F_49 ( L_106 ,
V_9 -> V_4 . V_569 , V_9 -> V_213 ) ;
if ( ! V_1 -> V_567 )
V_137 = F_344 ( V_1 -> V_257 ) ;
V_1 -> V_567 = false ;
return V_137 ;
}
static void
F_349 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_23 * V_23 = & F_2 ( V_1 ) -> V_4 ;
struct V_25 * V_26 = F_15 ( V_23 -> V_4 . V_7 ) ;
enum V_77 V_78 ;
F_49 ( L_106 ,
V_9 -> V_4 . V_569 , V_9 -> V_213 ) ;
F_342 ( V_1 ) ;
if ( V_9 -> V_137 != V_532 )
return;
V_78 = F_37 ( V_23 ) ;
F_38 ( V_26 , V_78 ) ;
F_341 ( V_1 ) ;
F_42 ( V_26 , V_78 ) ;
if ( V_23 -> type != V_5 )
V_23 -> type = V_104 ;
}
static int F_350 ( struct V_8 * V_9 )
{
struct V_57 * V_57 = F_32 ( V_9 ) ;
struct V_497 * V_497 ;
V_497 = V_57 -> V_491 ;
if ( V_497 ) {
int V_161 = F_351 ( V_9 , V_497 ) ;
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
bool V_266 = false ;
struct V_497 * V_497 ;
V_497 = F_32 ( V_9 ) -> V_491 ;
if ( V_497 )
V_266 = F_343 ( V_497 ) ;
return V_266 ;
}
static int
F_355 ( struct V_8 * V_9 ,
struct V_570 * V_571 ,
T_12 V_436 )
{
struct V_25 * V_26 = F_15 ( V_9 -> V_7 ) ;
struct V_57 * V_57 = F_32 ( V_9 ) ;
struct V_23 * V_23 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
int V_161 ;
V_161 = F_356 ( & V_9 -> V_4 , V_571 , V_436 ) ;
if ( V_161 )
return V_161 ;
if ( V_571 == V_26 -> V_572 ) {
int V_45 = V_436 ;
bool V_266 ;
if ( V_45 == V_1 -> V_563 )
return 0 ;
V_1 -> V_563 = V_45 ;
if ( V_45 == V_564 )
V_266 = F_354 ( V_9 ) ;
else
V_266 = ( V_45 == V_565 ) ;
if ( V_266 == V_1 -> V_266 )
return 0 ;
V_1 -> V_266 = V_266 ;
goto V_138;
}
if ( V_571 == V_26 -> V_573 ) {
bool V_574 = V_1 -> V_272 ;
bool V_575 = V_1 -> V_273 ;
switch ( V_436 ) {
case V_576 :
V_1 -> V_272 = true ;
break;
case V_577 :
V_1 -> V_272 = false ;
V_1 -> V_273 = false ;
break;
case V_578 :
V_1 -> V_272 = false ;
V_1 -> V_273 = true ;
break;
default:
return - V_198 ;
}
if ( V_574 == V_1 -> V_272 &&
V_575 == V_1 -> V_273 )
return 0 ;
goto V_138;
}
if ( F_1 ( V_1 ) &&
V_571 == V_9 -> V_7 -> V_524 . V_579 ) {
if ( V_436 == V_580 ) {
F_49 ( L_107 ) ;
return - V_198 ;
}
if ( F_161 ( V_26 ) &&
V_436 == V_581 ) {
F_49 ( L_108 ) ;
return - V_198 ;
}
if ( V_57 -> V_59 . V_267 == V_436 ) {
return 0 ;
}
V_57 -> V_59 . V_267 = V_436 ;
goto V_138;
}
return - V_198 ;
V_138:
if ( V_23 -> V_4 . V_256 )
F_357 ( V_23 -> V_4 . V_256 ) ;
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
F_49 ( L_109 ,
V_1 -> V_179 . V_213 , V_9 -> V_582 -> V_583 . V_213 ) ;
V_1 -> V_179 . V_7 = V_9 -> V_582 ;
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
struct V_57 * V_57 = F_32 ( V_9 ) ;
F_135 ( V_57 -> V_491 ) ;
if ( ! F_366 ( V_57 -> V_497 ) )
F_135 ( V_57 -> V_497 ) ;
if ( V_9 -> V_584 == V_585 )
F_367 ( & V_57 -> V_59 ) ;
F_368 ( V_9 ) ;
F_135 ( V_9 ) ;
}
void F_369 ( struct V_586 * V_24 )
{
struct V_2 * V_3 = F_370 ( V_24 ) ;
struct V_1 * V_1 = & V_3 -> V_587 ;
F_371 ( V_3 ) ;
if ( F_1 ( V_1 ) ) {
F_372 ( & V_1 -> V_317 ) ;
F_36 ( V_1 ) ;
F_189 ( V_1 ) ;
F_40 ( V_1 ) ;
if ( V_1 -> V_126 . V_588 ) {
F_373 ( & V_1 -> V_126 ) ;
V_1 -> V_126 . V_588 = NULL ;
}
}
F_134 ( V_1 ) ;
F_374 ( V_24 ) ;
F_135 ( V_3 ) ;
}
void F_375 ( struct V_23 * V_23 )
{
struct V_1 * V_1 = F_5 ( & V_23 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_372 ( & V_1 -> V_317 ) ;
F_36 ( V_1 ) ;
F_189 ( V_1 ) ;
F_40 ( V_1 ) ;
}
static void F_376 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
F_63 ( & V_26 -> V_79 ) ;
if ( ! F_89 ( V_1 ) )
return;
F_49 ( L_110 ) ;
V_78 = F_37 ( & V_3 -> V_4 ) ;
F_38 ( V_26 , V_78 ) ;
F_192 ( V_1 ) ;
}
static enum V_80 F_377 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( F_3 ( V_1 ) ) ;
if ( ( V_1 -> V_88 & V_90 ) == 0 )
return V_106 ;
if ( F_51 ( V_26 ) )
return F_229 ( V_1 -> V_88 ) ;
else
return F_230 ( V_1 -> V_88 ) ;
}
void F_378 ( struct V_586 * V_24 )
{
struct V_25 * V_26 = F_15 ( V_24 -> V_7 ) ;
struct V_1 * V_1 = F_5 ( V_24 ) ;
struct V_338 * V_339 = F_220 ( V_1 ) ;
if ( ! F_158 ( V_26 ) )
V_1 -> V_88 = F_46 ( V_1 -> V_89 ) ;
if ( V_339 -> V_341 )
F_379 ( V_339 ) ;
F_36 ( V_1 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
V_1 -> V_105 = F_377 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_380 ( V_24 -> V_7 , V_1 ) ;
F_376 ( V_1 ) ;
}
F_40 ( V_1 ) ;
}
enum V_589
F_381 ( struct V_2 * V_3 , bool V_590 )
{
struct V_1 * V_1 = & V_3 -> V_587 ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_77 V_78 ;
enum V_589 V_161 = V_591 ;
if ( V_3 -> V_4 . type != V_5 &&
V_3 -> V_4 . type != V_592 )
V_3 -> V_4 . type = V_104 ;
if ( V_590 && V_3 -> V_4 . type == V_5 ) {
F_49 ( L_111 ,
F_48 ( V_3 -> V_91 ) ) ;
return V_593 ;
}
F_49 ( L_112 ,
F_48 ( V_3 -> V_91 ) ,
V_590 ? L_113 : L_114 ) ;
if ( V_590 ) {
V_1 -> V_567 = false ;
return V_591 ;
}
V_78 = F_37 ( V_23 ) ;
F_38 ( V_26 , V_78 ) ;
if ( V_1 -> V_473 ) {
if ( F_314 ( V_1 ) == - V_198 ) {
F_49 ( L_104 ,
V_1 -> V_473 , V_1 -> V_474 . V_566 ) ;
V_1 -> V_473 = false ;
F_299 ( & V_1 -> V_474 ,
V_1 -> V_473 ) ;
V_1 -> V_567 = false ;
goto V_594;
}
}
if ( ! V_1 -> V_473 ) {
if ( ! F_322 ( V_1 ) ) {
V_1 -> V_567 = false ;
goto V_594;
}
}
V_161 = V_593 ;
V_594:
F_42 ( V_26 , V_78 ) ;
return V_161 ;
}
bool F_382 ( struct V_25 * V_26 , enum V_91 V_91 )
{
if ( F_141 ( V_26 ) < 5 )
return false ;
if ( F_141 ( V_26 ) < 9 && V_91 == V_141 )
return true ;
return F_383 ( V_26 , V_91 ) ;
}
void
F_384 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_57 * V_57 = F_32 ( V_9 ) ;
F_385 ( V_9 ) ;
F_386 ( V_9 ) ;
V_1 -> V_272 = true ;
if ( F_1 ( V_1 ) ) {
F_387 ( V_9 -> V_7 ) ;
F_388 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_524 . V_579 ,
V_595 ) ;
V_57 -> V_59 . V_267 = V_595 ;
}
}
static void F_389 ( struct V_1 * V_1 )
{
V_1 -> V_304 = F_180 () ;
V_1 -> V_308 = V_305 ;
V_1 -> V_310 = V_305 ;
}
static void
F_390 ( struct V_25 * V_26 ,
struct V_1 * V_1 , struct V_596 * V_597 )
{
T_5 V_119 , V_120 , V_121 = 0 , V_598 = 0 ;
struct V_114 V_115 ;
F_79 ( V_26 , V_1 , & V_115 ) ;
V_598 = F_185 ( V_1 ) ;
V_119 = F_46 ( V_115 . V_119 ) ;
V_120 = F_46 ( V_115 . V_120 ) ;
if ( ! F_19 ( V_26 ) ) {
F_56 ( V_115 . V_117 , V_598 ) ;
V_121 = F_46 ( V_115 . V_121 ) ;
}
V_597 -> V_599 = ( V_119 & V_600 ) >>
V_601 ;
V_597 -> V_602 = ( V_119 & V_603 ) >>
V_604 ;
V_597 -> V_605 = ( V_120 & V_606 ) >>
V_607 ;
V_597 -> V_608 = ( V_120 & V_609 ) >>
V_610 ;
if ( F_19 ( V_26 ) ) {
T_13 V_342 = ( V_598 & V_611 ) >>
V_612 ;
if ( V_342 > 0 )
V_597 -> V_613 = ( V_342 - 1 ) * 1000 ;
else
V_597 -> V_613 = 0 ;
} else {
V_597 -> V_613 = ( ( V_121 & V_614 ) >>
V_615 ) * 1000 ;
}
}
static void
F_391 ( const char * V_616 , const struct V_596 * V_597 )
{
F_49 ( L_115 ,
V_616 ,
V_597 -> V_599 , V_597 -> V_602 , V_597 -> V_605 , V_597 -> V_608 , V_597 -> V_613 ) ;
}
static void
F_175 ( struct V_25 * V_26 ,
struct V_1 * V_1 )
{
struct V_596 V_617 ;
struct V_596 * V_618 = & V_1 -> V_619 ;
F_390 ( V_26 , V_1 , & V_617 ) ;
if ( V_617 . V_599 != V_618 -> V_599 || V_617 . V_602 != V_618 -> V_602 || V_617 . V_605 != V_618 -> V_605 ||
V_617 . V_608 != V_618 -> V_608 || V_617 . V_613 != V_618 -> V_613 ) {
F_30 ( L_116 ) ;
F_391 ( L_117 , V_618 ) ;
F_391 ( L_118 , & V_617 ) ;
}
}
static void
F_65 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_596 V_620 , V_201 , V_621 ,
* V_622 = & V_1 -> V_619 ;
F_63 ( & V_26 -> V_79 ) ;
if ( V_622 -> V_613 != 0 )
return;
F_390 ( V_26 , V_1 , & V_620 ) ;
F_391 ( L_119 , & V_620 ) ;
V_201 = V_26 -> V_201 . V_270 . V_623 ;
V_621 . V_599 = 210 * 10 ;
V_621 . V_602 = 50 * 10 ;
V_621 . V_605 = 50 * 10 ;
V_621 . V_608 = 500 * 10 ;
V_621 . V_613 = ( 510 + 100 ) * 10 ;
F_391 ( L_120 , & V_201 ) ;
#define F_392 ( T_14 ) final->field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_392 ( V_599 ) ;
F_392 ( V_602 ) ;
F_392 ( V_605 ) ;
F_392 ( V_608 ) ;
F_392 ( V_613 ) ;
#undef F_392
#define F_393 ( T_14 ) (DIV_ROUND_UP(final->field, 10))
V_1 -> V_318 = F_393 ( V_599 ) ;
V_1 -> V_309 = F_393 ( V_602 ) ;
V_1 -> V_311 = F_393 ( V_605 ) ;
V_1 -> V_441 = F_393 ( V_608 ) ;
V_1 -> V_133 = F_393 ( V_613 ) ;
#undef F_393
F_49 ( L_121 ,
V_1 -> V_318 , V_1 -> V_441 ,
V_1 -> V_133 ) ;
F_49 ( L_122 ,
V_1 -> V_309 , V_1 -> V_311 ) ;
V_622 -> V_602 = 1 ;
V_622 -> V_605 = 1 ;
}
static void
F_66 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
bool V_624 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
T_5 V_119 , V_120 , V_121 , V_111 = 0 ;
int div = V_26 -> V_140 / 1000 ;
struct V_114 V_115 ;
enum V_91 V_91 = F_2 ( V_1 ) -> V_91 ;
const struct V_596 * V_597 = & V_1 -> V_619 ;
F_63 ( & V_26 -> V_79 ) ;
F_79 ( V_26 , V_1 , & V_115 ) ;
if ( V_624 ) {
T_5 V_314 = F_185 ( V_1 ) ;
F_8 ( V_314 & V_319 , L_123 ) ;
if ( V_314 & V_109 )
F_49 ( L_124 ) ;
V_314 &= ~ V_109 ;
F_56 ( V_115 . V_117 , V_314 ) ;
}
V_119 = ( V_597 -> V_599 << V_601 ) |
( V_597 -> V_602 << V_604 ) ;
V_120 = ( V_597 -> V_605 << V_607 ) |
( V_597 -> V_608 << V_610 ) ;
if ( F_19 ( V_26 ) ) {
V_121 = F_46 ( V_115 . V_117 ) ;
V_121 &= ~ V_611 ;
V_121 |= ( F_12 ( ( V_597 -> V_613 + 1 ) , 1000 )
<< V_612 ) ;
} else {
V_121 = ( ( 100 * div ) / 2 - 1 ) << V_625 ;
V_121 |= ( F_12 ( V_597 -> V_613 , 1000 )
<< V_615 ) ;
}
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
V_111 = F_75 ( V_91 ) ;
} else if ( F_289 ( V_26 ) || F_172 ( V_26 ) ) {
if ( V_91 == V_141 )
V_111 = V_626 ;
else
V_111 = V_627 ;
}
V_119 |= V_111 ;
F_56 ( V_115 . V_119 , V_119 ) ;
F_56 ( V_115 . V_120 , V_120 ) ;
if ( F_19 ( V_26 ) )
F_56 ( V_115 . V_117 , V_121 ) ;
else
F_56 ( V_115 . V_121 , V_121 ) ;
F_49 ( L_125 ,
F_46 ( V_115 . V_119 ) ,
F_46 ( V_115 . V_120 ) ,
F_19 ( V_26 ) ?
( F_46 ( V_115 . V_117 ) & V_611 ) :
F_46 ( V_115 . V_121 ) ) ;
}
static void F_380 ( struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
F_76 ( V_1 ) ;
} else {
F_65 ( V_7 , V_1 ) ;
F_66 ( V_7 , V_1 , false ) ;
}
}
static void F_394 ( struct V_25 * V_26 ,
struct V_216 * V_628 ,
int V_629 )
{
struct V_23 * V_24 ;
struct V_2 * V_38 = NULL ;
struct V_1 * V_1 = V_26 -> V_277 . V_587 ;
struct V_255 * V_255 = F_157 ( V_628 -> V_4 . V_256 ) ;
enum V_630 V_51 = V_631 ;
if ( V_629 <= 0 ) {
F_49 ( L_126 ) ;
return;
}
if ( V_1 == NULL ) {
F_49 ( L_127 ) ;
return;
}
V_38 = F_2 ( V_1 ) ;
V_24 = & V_38 -> V_4 ;
V_255 = F_157 ( V_24 -> V_4 . V_256 ) ;
if ( ! V_255 ) {
F_49 ( L_128 ) ;
return;
}
if ( V_26 -> V_277 . type < V_278 ) {
F_49 ( L_129 ) ;
return;
}
if ( V_1 -> V_257 -> V_59 . V_276 -> V_632 ==
V_629 )
V_51 = V_633 ;
if ( V_51 == V_26 -> V_277 . V_634 ) {
F_49 (
L_130 ) ;
return;
}
if ( ! V_628 -> V_4 . V_341 ) {
F_49 ( L_131 ) ;
return;
}
if ( F_141 ( V_26 ) >= 8 && ! F_51 ( V_26 ) ) {
switch ( V_51 ) {
case V_631 :
F_395 ( V_255 , V_635 ) ;
break;
case V_633 :
F_395 ( V_255 , V_636 ) ;
break;
case V_637 :
default:
F_30 ( L_132 ) ;
}
} else if ( F_141 ( V_26 ) > 6 ) {
T_6 V_638 = F_396 ( V_628 -> V_639 ) ;
T_5 V_436 ;
V_436 = F_46 ( V_638 ) ;
if ( V_51 > V_631 ) {
if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
V_436 |= V_640 ;
else
V_436 |= V_641 ;
} else {
if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
V_436 &= ~ V_640 ;
else
V_436 &= ~ V_641 ;
}
F_56 ( V_638 , V_436 ) ;
}
V_26 -> V_277 . V_634 = V_51 ;
F_49 ( L_133 , V_629 ) ;
}
void F_397 ( struct V_1 * V_1 ,
struct V_216 * V_628 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! V_628 -> V_265 ) {
F_49 ( L_134 ) ;
return;
}
F_39 ( & V_26 -> V_277 . V_642 ) ;
if ( F_25 ( V_26 -> V_277 . V_587 ) ) {
F_30 ( L_135 ) ;
goto V_643;
}
V_26 -> V_277 . V_644 = 0 ;
V_26 -> V_277 . V_587 = V_1 ;
V_643:
F_41 ( & V_26 -> V_277 . V_642 ) ;
}
void F_398 ( struct V_1 * V_1 ,
struct V_216 * V_351 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
if ( ! V_351 -> V_265 )
return;
F_39 ( & V_26 -> V_277 . V_642 ) ;
if ( ! V_26 -> V_277 . V_587 ) {
F_41 ( & V_26 -> V_277 . V_642 ) ;
return;
}
if ( V_26 -> V_277 . V_634 == V_633 )
F_394 ( V_26 , V_351 ,
V_1 -> V_257 -> V_59 . V_58 -> V_632 ) ;
V_26 -> V_277 . V_587 = NULL ;
F_41 ( & V_26 -> V_277 . V_642 ) ;
F_372 ( & V_26 -> V_277 . V_645 ) ;
}
static void F_399 ( struct V_320 * V_645 )
{
struct V_25 * V_26 =
F_85 ( V_645 , F_86 ( * V_26 ) , V_277 . V_645 . V_645 ) ;
struct V_1 * V_1 ;
F_39 ( & V_26 -> V_277 . V_642 ) ;
V_1 = V_26 -> V_277 . V_587 ;
if ( ! V_1 )
goto V_643;
if ( V_26 -> V_277 . V_644 )
goto V_643;
if ( V_26 -> V_277 . V_634 != V_633 ) {
struct V_646 * V_256 = F_2 ( V_1 ) -> V_4 . V_4 . V_256 ;
F_394 ( V_26 , F_157 ( V_256 ) -> V_523 ,
V_1 -> V_257 -> V_59 . V_276 -> V_632 ) ;
}
V_643:
F_41 ( & V_26 -> V_277 . V_642 ) ;
}
void F_400 ( struct V_25 * V_26 ,
unsigned int V_647 )
{
struct V_646 * V_256 ;
enum V_80 V_80 ;
if ( V_26 -> V_277 . type == V_648 )
return;
F_186 ( & V_26 -> V_277 . V_645 ) ;
F_39 ( & V_26 -> V_277 . V_642 ) ;
if ( ! V_26 -> V_277 . V_587 ) {
F_41 ( & V_26 -> V_277 . V_642 ) ;
return;
}
V_256 = F_2 ( V_26 -> V_277 . V_587 ) -> V_4 . V_4 . V_256 ;
V_80 = F_157 ( V_256 ) -> V_80 ;
V_647 &= F_401 ( V_80 ) ;
V_26 -> V_277 . V_644 |= V_647 ;
if ( V_647 && V_26 -> V_277 . V_634 == V_633 )
F_394 ( V_26 , F_157 ( V_256 ) -> V_523 ,
V_26 -> V_277 . V_587 -> V_257 -> V_59 . V_58 -> V_632 ) ;
F_41 ( & V_26 -> V_277 . V_642 ) ;
}
void F_402 ( struct V_25 * V_26 ,
unsigned int V_647 )
{
struct V_646 * V_256 ;
enum V_80 V_80 ;
if ( V_26 -> V_277 . type == V_648 )
return;
F_186 ( & V_26 -> V_277 . V_645 ) ;
F_39 ( & V_26 -> V_277 . V_642 ) ;
if ( ! V_26 -> V_277 . V_587 ) {
F_41 ( & V_26 -> V_277 . V_642 ) ;
return;
}
V_256 = F_2 ( V_26 -> V_277 . V_587 ) -> V_4 . V_4 . V_256 ;
V_80 = F_157 ( V_256 ) -> V_80 ;
V_647 &= F_401 ( V_80 ) ;
V_26 -> V_277 . V_644 &= ~ V_647 ;
if ( V_647 && V_26 -> V_277 . V_634 == V_633 )
F_394 ( V_26 , F_157 ( V_256 ) -> V_523 ,
V_26 -> V_277 . V_587 -> V_257 -> V_59 . V_58 -> V_632 ) ;
if ( ! V_26 -> V_277 . V_644 )
F_194 ( & V_26 -> V_277 . V_645 ,
F_193 ( 1000 ) ) ;
F_41 ( & V_26 -> V_277 . V_642 ) ;
}
static struct V_55 *
F_403 ( struct V_57 * V_57 ,
struct V_55 * V_58 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_55 * V_276 = NULL ;
F_404 ( & V_26 -> V_277 . V_645 , F_399 ) ;
F_405 ( & V_26 -> V_277 . V_642 ) ;
if ( F_141 ( V_26 ) <= 6 ) {
F_49 ( L_136 ) ;
return NULL ;
}
if ( V_26 -> V_201 . V_649 != V_278 ) {
F_49 ( L_137 ) ;
return NULL ;
}
V_276 = F_406
( V_26 , V_58 , V_9 ) ;
if ( ! V_276 ) {
F_49 ( L_138 ) ;
return NULL ;
}
V_26 -> V_277 . type = V_26 -> V_201 . V_649 ;
V_26 -> V_277 . V_634 = V_631 ;
F_49 ( L_139 ) ;
return V_276 ;
}
static bool F_407 ( struct V_1 * V_1 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
struct V_55 * V_58 = NULL ;
struct V_55 * V_276 = NULL ;
bool V_650 ;
struct V_55 * V_651 ;
struct V_497 * V_497 ;
enum V_80 V_80 = V_106 ;
if ( ! F_1 ( V_1 ) )
return true ;
if ( F_408 ( V_7 ) ) {
F_25 ( ! ( F_289 ( V_26 ) || F_172 ( V_26 ) ) ) ;
F_409 ( L_140 ) ;
return false ;
}
F_36 ( V_1 ) ;
F_389 ( V_1 ) ;
F_380 ( V_7 , V_1 ) ;
F_376 ( V_1 ) ;
F_40 ( V_1 ) ;
V_650 = F_293 ( V_1 ) ;
if ( ! V_650 ) {
F_409 ( L_141 ) ;
goto V_652;
}
F_39 ( & V_7 -> V_524 . V_642 ) ;
V_497 = F_340 ( V_9 , & V_1 -> V_179 . V_534 ) ;
if ( V_497 ) {
if ( F_410 ( V_9 , V_497 ) ) {
F_411 ( V_9 ,
V_497 ) ;
F_412 ( V_9 , V_497 ) ;
} else {
F_135 ( V_497 ) ;
V_497 = F_413 ( - V_198 ) ;
}
} else {
V_497 = F_413 ( - V_653 ) ;
}
V_57 -> V_497 = V_497 ;
F_414 (scan, &connector->probed_modes, head) {
if ( ( V_651 -> type & V_654 ) ) {
V_58 = F_352 ( V_7 , V_651 ) ;
V_276 = F_403 (
V_57 , V_58 ) ;
break;
}
}
if ( ! V_58 && V_26 -> V_201 . V_655 ) {
V_58 = F_352 ( V_7 ,
V_26 -> V_201 . V_655 ) ;
if ( V_58 ) {
V_58 -> type |= V_654 ;
V_9 -> V_269 . V_656 = V_58 -> V_656 ;
V_9 -> V_269 . V_657 = V_58 -> V_657 ;
}
}
F_41 ( & V_7 -> V_524 . V_642 ) ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) ) {
V_1 -> V_126 . V_588 = F_84 ;
F_415 ( & V_1 -> V_126 ) ;
V_80 = F_377 ( V_1 ) ;
if ( V_80 != V_103 && V_80 != V_96 )
V_80 = V_1 -> V_81 ;
if ( V_80 != V_103 && V_80 != V_96 )
V_80 = V_103 ;
F_49 ( L_142 ,
F_47 ( V_80 ) ) ;
}
F_416 ( & V_57 -> V_59 , V_58 , V_276 ) ;
V_57 -> V_59 . V_658 . V_659 = F_206 ;
F_417 ( V_9 , V_80 ) ;
return true ;
V_652:
F_372 ( & V_1 -> V_317 ) ;
F_36 ( V_1 ) ;
F_189 ( V_1 ) ;
F_40 ( V_1 ) ;
return false ;
}
bool
F_418 ( struct V_2 * V_3 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 = & V_57 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_587 ;
struct V_23 * V_23 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_23 -> V_4 . V_7 ;
struct V_25 * V_26 = F_15 ( V_7 ) ;
enum V_91 V_91 = V_3 -> V_91 ;
int type ;
if ( F_8 ( V_3 -> V_18 < 1 ,
L_143 ,
V_3 -> V_18 , F_48 ( V_91 ) ) )
return false ;
V_1 -> V_81 = V_106 ;
V_1 -> V_105 = V_106 ;
if ( F_141 ( V_26 ) >= 9 )
V_1 -> V_170 = F_101 ;
else if ( F_139 ( V_26 ) || F_104 ( V_26 ) )
V_1 -> V_170 = F_99 ;
else if ( F_131 ( V_26 ) )
V_1 -> V_170 = F_98 ;
else
V_1 -> V_170 = F_96 ;
if ( F_141 ( V_26 ) >= 9 )
V_1 -> V_172 = F_105 ;
else
V_1 -> V_172 = F_102 ;
if ( F_158 ( V_26 ) )
V_1 -> V_660 = V_661 ;
V_1 -> V_88 = F_46 ( V_1 -> V_89 ) ;
V_1 -> V_257 = V_57 ;
if ( F_382 ( V_26 , V_91 ) )
type = V_585 ;
else
type = V_662 ;
if ( F_78 ( V_26 ) || F_51 ( V_26 ) )
V_1 -> V_105 = F_377 ( V_1 ) ;
if ( type == V_585 )
V_23 -> type = V_5 ;
if ( F_25 ( ( F_78 ( V_26 ) || F_51 ( V_26 ) ) &&
F_1 ( V_1 ) && V_91 != V_207 && V_91 != V_209 ) )
return false ;
F_49 ( L_144 ,
type == V_585 ? L_145 : L_146 ,
F_48 ( V_91 ) ) ;
F_419 ( V_7 , V_9 , & V_663 , type ) ;
F_420 ( V_9 , & V_664 ) ;
V_9 -> V_665 = true ;
V_9 -> V_666 = 0 ;
F_136 ( V_1 ) ;
F_404 ( & V_1 -> V_317 ,
F_190 ) ;
F_421 ( V_57 , V_23 ) ;
if ( F_158 ( V_26 ) )
V_57 -> V_667 = V_668 ;
else
V_57 -> V_667 = V_669 ;
switch ( V_91 ) {
case V_141 :
V_23 -> V_558 = V_670 ;
break;
case V_207 :
V_23 -> V_558 = V_671 ;
if ( F_422 ( V_26 , 0 , V_672 ) )
V_23 -> V_558 = V_670 ;
break;
case V_209 :
V_23 -> V_558 = V_673 ;
break;
case V_211 :
V_23 -> V_558 = V_674 ;
break;
case V_549 :
V_23 -> V_558 = V_675 ;
break;
default:
F_423 () ;
}
if ( F_424 ( V_26 ) && ! F_1 ( V_1 ) &&
( V_91 == V_207 || V_91 == V_209 || V_91 == V_211 ) )
F_425 ( V_3 ,
V_57 -> V_4 . V_4 . V_569 ) ;
if ( ! F_407 ( V_1 , V_57 ) ) {
F_134 ( V_1 ) ;
F_371 ( V_3 ) ;
goto V_676;
}
F_384 ( V_1 , V_9 ) ;
if ( F_143 ( V_26 ) && ! F_336 ( V_26 ) ) {
T_5 V_357 = F_46 ( V_677 ) ;
F_56 ( V_677 , ( V_357 & ~ 0xf ) | 0xd ) ;
}
return true ;
V_676:
F_368 ( V_9 ) ;
return false ;
}
bool F_426 ( struct V_25 * V_26 ,
T_6 V_89 ,
enum V_91 V_91 )
{
struct V_2 * V_3 ;
struct V_23 * V_23 ;
struct V_586 * V_24 ;
struct V_57 * V_57 ;
V_3 = F_427 ( sizeof( * V_3 ) , V_214 ) ;
if ( ! V_3 )
return false ;
V_57 = F_428 () ;
if ( ! V_57 )
goto V_678;
V_23 = & V_3 -> V_4 ;
V_24 = & V_23 -> V_4 ;
if ( F_429 ( & V_26 -> V_113 , & V_23 -> V_4 ,
& V_679 , V_680 ,
L_147 , F_48 ( V_91 ) ) )
goto V_681;
V_23 -> V_682 = F_156 ;
V_23 -> V_683 = F_234 ;
V_23 -> V_667 = F_222 ;
V_23 -> V_684 = F_231 ;
V_23 -> V_685 = F_375 ;
if ( F_51 ( V_26 ) ) {
V_23 -> V_686 = F_267 ;
V_23 -> V_687 = F_264 ;
V_23 -> V_326 = F_256 ;
V_23 -> V_688 = F_241 ;
V_23 -> V_689 = F_269 ;
} else if ( F_78 ( V_26 ) ) {
V_23 -> V_686 = F_262 ;
V_23 -> V_687 = F_260 ;
V_23 -> V_326 = F_256 ;
V_23 -> V_688 = F_240 ;
} else {
V_23 -> V_687 = F_258 ;
V_23 -> V_326 = F_255 ;
if ( F_141 ( V_26 ) >= 5 )
V_23 -> V_688 = F_239 ;
}
V_3 -> V_91 = V_91 ;
V_3 -> V_587 . V_89 = V_89 ;
V_3 -> V_18 = 4 ;
V_23 -> type = V_104 ;
if ( F_51 ( V_26 ) ) {
if ( V_91 == V_211 )
V_23 -> V_690 = 1 << 2 ;
else
V_23 -> V_690 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_23 -> V_690 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_23 -> V_691 = 0 ;
V_23 -> V_91 = V_91 ;
V_3 -> V_692 = F_381 ;
V_26 -> V_693 . V_694 [ V_91 ] = V_3 ;
if ( ! F_418 ( V_3 , V_57 ) )
goto V_695;
return true ;
V_695:
F_374 ( V_24 ) ;
V_681:
F_135 ( V_57 ) ;
V_678:
F_135 ( V_3 ) ;
return false ;
}
void F_430 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_696 ; V_45 ++ ) {
struct V_2 * V_3 = V_26 -> V_693 . V_694 [ V_45 ] ;
if ( ! V_3 || ! V_3 -> V_587 . V_470 )
continue;
if ( V_3 -> V_587 . V_473 )
F_431 ( & V_3 -> V_587 . V_474 ) ;
}
}
void F_432 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = F_15 ( V_7 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_696 ; V_45 ++ ) {
struct V_2 * V_3 = V_26 -> V_693 . V_694 [ V_45 ] ;
int V_161 ;
if ( ! V_3 || ! V_3 -> V_587 . V_470 )
continue;
V_161 = F_433 ( & V_3 -> V_587 . V_474 ) ;
if ( V_161 )
F_314 ( & V_3 -> V_587 ) ;
}
}
