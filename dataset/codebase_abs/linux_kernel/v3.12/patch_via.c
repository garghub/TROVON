static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
V_3 -> V_4 = V_4 ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = F_4 ( V_3 ) ;
if ( V_4 -> V_7 == V_8 )
V_4 -> V_7 = V_9 ;
V_4 -> V_10 = 1 ;
V_4 -> V_6 . V_11 = 1 ;
V_4 -> V_6 . V_12 = 1 ;
V_4 -> V_6 . V_13 = V_14 ;
return V_4 ;
}
static enum V_15 F_4 ( struct V_2 * V_3 )
{
T_1 V_16 = V_3 -> V_16 ;
T_2 V_17 = V_16 >> 16 ;
T_2 V_18 = V_16 & 0xffff ;
enum V_15 V_7 ;
if ( V_17 != 0x1106 )
V_7 = V_19 ;
else if ( V_18 >= 0x1708 && V_18 <= 0x170b )
V_7 = V_20 ;
else if ( V_18 >= 0xe710 && V_18 <= 0xe713 )
V_7 = V_21 ;
else if ( V_18 >= 0xe714 && V_18 <= 0xe717 )
V_7 = V_22 ;
else if ( V_18 >= 0xe720 && V_18 <= 0xe723 ) {
V_7 = V_23 ;
if ( F_5 ( V_3 , 0x16 , V_24 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_18 >= 0xe724 && V_18 <= 0xe727 )
V_7 = V_25 ;
else if ( ( V_18 & 0xfff ) == 0x397
&& ( V_18 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_18 & 0xfff ) == 0x398
&& ( V_18 >> 12 ) < 8 )
V_7 = V_26 ;
else if ( ( V_18 & 0xfff ) == 0x428
&& ( V_18 >> 12 ) < 8 )
V_7 = V_27 ;
else if ( V_18 == 0x0433 || V_18 == 0xa721 )
V_7 = V_28 ;
else if ( V_18 == 0x0441 || V_18 == 0x4441 )
V_7 = V_27 ;
else if ( V_18 == 0x0438 || V_18 == 0x4438 )
V_7 = V_29 ;
else if ( V_18 == 0x0448 )
V_7 = V_30 ;
else if ( V_18 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_18 & 0xfff ) == 0x446 )
V_7 = V_31 ;
else if ( V_18 == 0x4760 )
V_7 = V_32 ;
else if ( V_18 == 0x4761 || V_18 == 0x4762 )
V_7 = V_33 ;
else
V_7 = V_19 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_20 || ! V_4 -> V_6 . V_34 . V_35 )
return;
if ( V_4 -> V_36 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
V_3 -> V_37 = 0 ;
F_8 ( & V_3 -> V_38 ) ;
V_4 -> V_36 = false ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_20 || ! V_4 -> V_6 . V_34 . V_35 )
return;
if ( V_4 -> V_39 ) {
if ( ! V_4 -> V_36 ) {
V_3 -> V_37 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( V_3 -> V_40 -> V_41 ,
& V_3 -> V_38 , 0 ) ;
V_4 -> V_36 = true ;
}
} else if ( ! F_12 ( V_3 ) )
F_6 ( V_3 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
#if 0
struct via_spec *spec = codec->spec;
if (spec->set_widgets_power_state)
spec->set_widgets_power_state(codec);
#endif
}
static void F_14 ( struct V_2 * V_3 , T_3 V_42 ,
unsigned int V_43 )
{
if ( F_15 ( V_3 , V_42 , V_43 ) )
return;
F_7 ( V_3 , V_42 , 0 , V_44 , V_43 ) ;
}
static void F_16 ( struct V_2 * V_3 , T_3 V_42 ,
unsigned int V_43 , unsigned int V_45 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_46 ;
if ( F_15 ( V_3 , V_42 , V_43 ) )
return;
V_46 = F_17 ( V_3 , V_42 , 0 , V_47 , 0 ) ;
if ( V_46 && ( V_4 -> V_48 [ V_45 ] != V_46 ) )
V_4 -> V_48 [ V_45 ] = V_46 ;
F_7 ( V_3 , V_42 , 0 , V_44 , V_43 ) ;
if ( V_43 == V_49 ) {
V_46 = F_17 ( V_3 , V_42 , 0 , V_47 , 0 ) ;
if ( ! V_46 && ( V_4 -> V_48 [ V_45 ] != V_46 ) )
F_7 ( V_3 , V_42 , 0 ,
V_50 ,
V_4 -> V_48 [ V_45 ] ) ;
}
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return V_4 -> V_6 . V_51 > 2 ;
}
static bool F_19 ( struct V_2 * V_3 , T_3 V_52 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_6 . V_54 ; V_53 ++ )
if ( V_4 -> V_6 . V_55 [ V_53 ] . V_52 == V_52 )
return true ;
return false ;
}
static void F_20 ( struct V_2 * V_3 , T_3 V_42 ,
unsigned int * V_56 )
{
unsigned V_43 ;
unsigned V_57 = F_21 ( V_3 , V_42 ) ;
unsigned V_58 = ( V_57 & V_59 )
>> V_60
& V_61 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_62 = 0 ;
V_58 |= V_4 -> V_10 ;
if ( ! V_58 )
V_62 = F_22 ( V_3 , V_42 ) ;
if ( ( F_18 ( V_3 ) && F_19 ( V_3 , V_42 ) )
|| ( ( V_58 || V_62 )
&& F_23 ( V_57 ) != V_63 ) ) {
* V_56 = V_49 ;
V_43 = V_49 ;
} else
V_43 = V_64 ;
F_14 ( V_3 , V_42 , V_43 ) ;
}
static int F_24 ( struct V_65 * V_66 ,
struct V_67 * V_68 )
{
return F_25 ( V_66 , V_68 ) ;
}
static int F_26 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_70 -> V_71 . V_72 . V_73 [ 0 ] = ! V_4 -> V_10 ;
return 0 ;
}
static int F_28 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_74 = ! V_70 -> V_71 . V_72 . V_73 [ 0 ] ;
if ( V_74 == V_4 -> V_10 )
return 0 ;
V_4 -> V_10 = V_74 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
return 1 ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_75 * V_76 ;
int V_77 , V_78 ;
V_76 = V_4 -> V_6 . V_79 . V_80 ;
if ( ! V_76 )
return true ;
for (; V_76 -> V_42 ; V_76 ++ ) {
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
V_78 = F_31 ( V_3 , V_76 -> V_42 , V_77 , V_76 -> V_81 ,
V_76 -> V_82 ) ;
if ( ! ( V_78 & V_83 ) && V_78 > 0 )
return false ;
}
}
return true ;
}
static void F_32 ( struct V_2 * V_3 , bool V_84 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_85 ;
unsigned int V_86 , V_43 ;
if ( V_4 -> V_10 )
V_85 = false ;
else
V_85 = F_30 ( V_3 ) && ! V_4 -> V_6 . V_87 ;
if ( V_85 == V_4 -> V_88 && ! V_84 )
return;
V_4 -> V_88 = V_85 ;
switch ( V_4 -> V_7 ) {
case V_23 :
case V_25 :
V_86 = 0xf70 ;
V_43 = V_85 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_27 :
case V_28 :
V_86 = 0xf73 ;
V_43 = V_85 ? 0x51 : 0xe1 ;
break;
case V_26 :
V_86 = 0xf73 ;
V_43 = V_85 ? 0x01 : 0x1d ;
break;
case V_29 :
case V_30 :
case V_31 :
V_86 = 0xf93 ;
V_43 = V_85 ? 0x00 : 0xe0 ;
break;
case V_32 :
case V_33 :
V_86 = 0xf82 ;
V_43 = V_85 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_89 , 0 , V_86 , V_43 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , false ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_90 , V_53 ;
V_90 = F_34 ( V_3 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( V_4 -> F_13 )
V_4 -> V_91 [ V_4 -> V_92 ++ ] = V_93 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_92 ; V_53 ++ ) {
V_90 = F_35 ( V_3 , V_4 -> V_91 [ V_53 ] ) ;
if ( V_90 < 0 )
return V_90 ;
}
return 0 ;
}
static void V_14 ( struct V_94 * V_95 ,
struct V_2 * V_3 ,
struct V_96 * V_97 ,
int V_98 )
{
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_6 ( V_3 ) ;
F_37 ( & V_4 -> V_6 ) ;
F_38 ( V_4 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_3 ) ;
if ( V_4 -> V_7 == V_31 )
F_40 ( V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_3 V_42 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_42 ( V_3 , & V_4 -> V_6 . V_79 , V_42 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_3 V_42 )
{
unsigned int V_57 ;
unsigned char V_99 ;
V_57 = F_21 ( V_3 , V_42 ) ;
V_99 = ( unsigned char ) F_44 ( V_57 ) ;
V_99 = ( V_99 << 4 ) | F_45 ( V_57 ) ;
if ( F_23 ( V_57 ) == V_63
&& ( V_99 == 0xf0 || V_99 == 0xff ) ) {
V_57 = V_57 & ( ~ ( V_100 << 30 ) ) ;
F_46 ( V_3 , V_42 , V_57 ) ;
}
return;
}
static int F_47 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_20 )
return 0 ;
V_70 -> V_71 . integer . V_71 [ 0 ] = V_4 -> V_39 ;
return 0 ;
}
static int F_48 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_74 ;
if ( V_4 -> V_7 != V_20 )
return 0 ;
V_74 = ! ! V_70 -> V_71 . integer . V_71 [ 0 ] ;
if ( V_4 -> V_39 == V_74 )
return 0 ;
V_4 -> V_39 = V_74 ;
F_9 ( V_3 ) ;
return 1 ;
}
static void F_49 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
F_13 ( V_3 ) ;
F_50 ( V_3 , V_102 ) ;
}
static void F_51 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
F_13 ( V_3 ) ;
F_52 ( V_3 , V_102 ) ;
}
static void F_53 ( struct V_2 * V_3 , struct V_101 * V_102 )
{
F_13 ( V_3 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_103 * V_104 = & V_4 -> V_6 . V_34 ;
T_3 V_52 ;
int V_53 ;
V_4 -> V_6 . V_105 = F_49 ;
if ( V_104 -> V_106 [ 0 ] )
V_4 -> V_6 . V_107 = F_51 ;
for ( V_53 = 0 ; V_53 < V_104 -> V_108 ; V_53 ++ ) {
V_52 = V_104 -> V_109 [ V_53 ] ;
if ( V_52 && ! F_55 ( V_3 , V_52 ) &&
F_56 ( V_3 , V_52 ) )
F_57 ( V_3 , V_52 ,
V_110 ,
F_53 ) ;
}
for ( V_53 = 0 ; V_53 < V_104 -> V_111 ; V_53 ++ ) {
V_52 = V_104 -> V_109 [ V_53 ] ;
if ( V_52 && ! F_55 ( V_3 , V_52 ) &&
F_56 ( V_3 , V_52 ) )
F_57 ( V_3 , V_52 ,
V_110 ,
F_53 ) ;
}
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_90 ;
V_4 -> V_6 . V_112 = & V_113 ;
V_4 -> V_6 . V_114 = & V_115 ;
V_90 = F_59 ( V_3 , & V_4 -> V_6 . V_34 , NULL , 0 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_60 ( V_3 , & V_4 -> V_6 . V_34 ) ;
if ( V_90 < 0 )
return V_90 ;
F_54 ( V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_116 ; V_53 ++ )
F_62 ( V_3 , V_4 -> V_117 [ V_53 ] ) ;
F_13 ( V_3 ) ;
F_32 ( V_3 , true ) ;
F_63 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
int V_90 ;
int V_118 = V_3 -> V_37 ;
V_3 -> V_37 = F_10 ( 100 ) ;
V_90 = F_33 ( V_3 ) ;
V_3 -> V_37 = V_118 ;
return V_90 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_90 ;
V_90 = F_66 ( V_3 ) ;
if ( V_90 < 0 || V_3 -> V_16 != 0x11061708 )
return V_90 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_119 ; V_53 ++ ) {
struct V_120 * V_121 = & V_4 -> V_6 . V_122 [ V_53 ] ;
if ( ! V_121 -> V_123 [ V_124 ] . V_125 ||
V_121 -> V_126 != V_127 )
continue;
V_121 -> V_123 [ V_124 ] . V_128 =
V_129 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x17 ;
V_3 -> V_37 = F_10 ( 100 ) ;
V_4 -> V_39 = 1 ;
V_4 -> V_6 . V_132 = 1 ;
V_4 -> V_6 . V_133 = 1 ;
F_43 ( V_3 , V_134 ) ;
F_43 ( V_3 , V_135 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_91 [ V_4 -> V_92 ++ ] = V_136 ;
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_137 ;
V_3 -> V_138 = V_139 ;
V_3 -> V_138 . V_140 = F_64 ;
V_3 -> V_138 . V_141 = F_65 ;
V_3 -> V_37 = 0 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x18 ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_3 -> V_138 = V_139 ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_142 ;
unsigned int V_43 ;
int V_143 = 0 ;
if ( ( V_4 -> V_7 != V_25 ) &&
( V_3 -> V_16 != 0x11064397 ) )
V_143 = 1 ;
V_142 =
( F_17 ( V_3 , 0x17 , 0 , V_144 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x1a , & V_43 ) ;
F_20 ( V_3 , 0x1b , & V_43 ) ;
F_20 ( V_3 , 0x1e , & V_43 ) ;
if ( V_142 )
V_43 = V_49 ;
F_14 ( V_3 , 0x17 , V_43 ) ;
F_14 ( V_3 , 0x13 , V_43 ) ;
F_14 ( V_3 , 0x14 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x19 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_43 ) ;
F_14 ( V_3 , 0x18 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
if ( V_143 ) {
V_43 = V_64 ;
F_20 ( V_3 , 0x22 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_43 ) ;
F_14 ( V_3 , 0x26 , V_43 ) ;
F_14 ( V_3 , 0x24 , V_43 ) ;
} else if ( V_3 -> V_16 == 0x11064397 ) {
V_43 = V_64 ;
F_20 ( V_3 , 0x23 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_43 ) ;
F_14 ( V_3 , 0x27 , V_43 ) ;
F_14 ( V_3 , 0x25 , V_43 ) ;
}
V_43 = V_64 ;
F_20 ( V_3 , 0x1c , & V_43 ) ;
F_20 ( V_3 , 0x1d , & V_43 ) ;
if ( V_143 )
F_20 ( V_3 , 0x23 , & V_43 ) ;
F_14 ( V_3 , 0x16 , V_142 ? V_49 : V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
if ( V_143 ) {
F_14 ( V_3 , 0x25 , V_43 ) ;
F_14 ( V_3 , 0x27 , V_43 ) ;
} else if ( V_3 -> V_16 == 0x11064397 && V_4 -> V_6 . V_145 )
F_14 ( V_3 , 0x25 , V_43 ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
if ( F_4 ( V_3 ) == V_8 )
return F_71 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x16 ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_69 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 , T_3 V_52 ,
int V_146 , int V_147 , int V_148 )
{
F_73 ( V_3 , V_52 ,
F_74 ( V_3 , V_52 ) | V_149 ) ;
F_75 ( V_3 , V_52 , V_150 ,
( V_146 << V_151 ) |
( V_147 << V_152 ) |
( V_148 << V_153 ) |
( 0 << V_154 ) ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x16 ;
F_72 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 ) {
F_38 ( V_3 -> V_155 ) ;
V_3 -> V_155 = F_76 ( L_1 , V_5 ) ;
snprintf ( V_3 -> V_40 -> V_156 -> V_157 ,
sizeof( V_3 -> V_40 -> V_156 -> V_157 ) ,
L_2 , V_3 -> V_158 , V_3 -> V_155 ) ;
}
if ( V_3 -> V_16 == 0x11064397 ) {
F_38 ( V_3 -> V_155 ) ;
V_3 -> V_155 = F_76 ( L_3 , V_5 ) ;
snprintf ( V_3 -> V_40 -> V_156 -> V_157 ,
sizeof( V_3 -> V_40 -> V_156 -> V_157 ) ,
L_2 , V_3 -> V_158 , V_3 -> V_155 ) ;
}
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_159 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_69 ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
int V_142 =
F_17 ( V_3 , 0x13 , 0 , V_144 , 0x00 ) == 3 ;
unsigned int V_43 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x14 , & V_43 ) ;
F_20 ( V_3 , 0x15 , & V_43 ) ;
F_20 ( V_3 , 0x18 , & V_43 ) ;
if ( V_142 )
V_43 = V_49 ;
F_14 ( V_3 , 0x13 , V_43 ) ;
F_14 ( V_3 , 0x12 , V_43 ) ;
F_14 ( V_3 , 0x1f , V_43 ) ;
F_14 ( V_3 , 0x20 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x17 , & V_43 ) ;
F_20 ( V_3 , 0x16 , & V_43 ) ;
F_14 ( V_3 , 0x1a , V_142 ? V_49 : V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
F_14 ( V_3 , 0x1d , V_43 ) ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x1a ;
F_75 ( V_3 , 0x1A , V_150 ,
( 0x17 << V_151 ) |
( 0x17 << V_152 ) |
( 0x5 << V_153 ) |
( 1 << V_154 ) ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_160 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_77 ;
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_142 ;
unsigned int V_43 , V_161 ;
V_142 =
F_17 ( V_3 , 0x1e , 0 , V_144 , 0x00 ) == 5 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x29 , & V_43 ) ;
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_20 ( V_3 , 0x2b , & V_43 ) ;
if ( V_142 )
V_43 = V_49 ;
F_14 ( V_3 , 0x1e , V_43 ) ;
F_14 ( V_3 , 0x1f , V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x27 , & V_43 ) ;
F_14 ( V_3 , 0x1a , V_43 ) ;
V_161 = V_43 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x26 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2b , & V_43 ) ;
F_14 ( V_3 , 0xa , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x24 , & V_43 ) ;
if ( ! V_4 -> V_6 . V_145 )
F_20 ( V_3 , 0x28 , & V_43 ) ;
F_14 ( V_3 , 0x8 , V_43 ) ;
if ( ! V_4 -> V_6 . V_145 && V_161 != V_64 )
V_43 = V_161 ;
F_14 ( V_3 , 0xb , V_43 ) ;
F_14 ( V_3 , 0x21 , V_142 ? V_49 : V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x25 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_14 ( V_3 , 0x9 , V_43 ) ;
if ( V_4 -> V_6 . V_145 ) {
V_43 = V_64 ;
F_20 ( V_3 , 0x28 , & V_43 ) ;
F_14 ( V_3 , 0x1b , V_43 ) ;
F_14 ( V_3 , 0x34 , V_43 ) ;
F_14 ( V_3 , 0xc , V_43 ) ;
}
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_162 ;
T_3 V_163 [ 8 ] ;
T_3 V_42 ;
if ( ! V_4 -> V_6 . V_131 )
return 0 ;
V_162 = F_81 ( V_3 , V_4 -> V_6 . V_131 , V_163 ,
F_82 ( V_163 ) - 1 ) ;
for ( V_53 = 0 ; V_53 < V_162 ; V_53 ++ ) {
if ( F_83 ( F_74 ( V_3 , V_163 [ V_53 ] ) ) == V_164 )
return 0 ;
}
V_42 = V_3 -> V_165 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_166 ; V_53 ++ , V_42 ++ ) {
unsigned int V_167 = F_74 ( V_3 , V_42 ) ;
if ( F_83 ( V_167 ) == V_164 &&
! ( V_167 & V_168 ) ) {
V_163 [ V_162 ++ ] = V_42 ;
return F_84 ( V_3 ,
V_4 -> V_6 . V_131 ,
V_162 , V_163 ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_80 ( V_3 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_169 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_79 ;
return 0 ;
}
static int F_86 ( struct V_65 * V_66 ,
struct V_67 * V_68 )
{
V_68 -> type = V_170 ;
V_68 -> V_171 = 1 ;
V_68 -> V_71 . integer . V_172 = 0 ;
V_68 -> V_71 . integer . V_173 = 1 ;
return 0 ;
}
static int F_87 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
int V_45 = 0 ;
V_45 = F_17 ( V_3 , 0x26 , 0 ,
V_144 , 0 ) ;
if ( V_45 != - 1 )
* V_70 -> V_71 . integer . V_71 = V_45 ;
return 0 ;
}
static int F_88 ( struct V_65 * V_66 ,
struct V_69 * V_70 )
{
struct V_2 * V_3 = F_27 ( V_66 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_45 = * V_70 -> V_71 . integer . V_71 ;
F_7 ( V_3 , 0x26 , 0 ,
V_174 , V_45 ) ;
V_4 -> V_175 = V_45 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_142 ;
unsigned int V_43 ;
unsigned int V_176 , V_62 ;
V_142 =
( F_17 ( V_3 , 0x17 , 0 ,
V_144 , 0x00 ) == 5 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x1a , & V_43 ) ;
F_20 ( V_3 , 0x1b , & V_43 ) ;
F_20 ( V_3 , 0x1e , & V_43 ) ;
if ( V_142 )
V_43 = V_49 ;
F_14 ( V_3 , 0x17 , V_43 ) ;
F_14 ( V_3 , 0x13 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x1e , & V_43 ) ;
if ( V_4 -> V_175 )
F_20 ( V_3 , 0x22 , & V_43 ) ;
else
F_14 ( V_3 , 0x22 , V_64 ) ;
F_14 ( V_3 , 0x26 , V_43 ) ;
F_14 ( V_3 , 0x14 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x19 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_43 ) ;
F_14 ( V_3 , 0x18 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x23 , & V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_43 ) ;
F_14 ( V_3 , 0x27 , V_43 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1e , & V_43 ) ;
F_14 ( V_3 , 0x25 , V_43 ) ;
V_62 = F_22 ( V_3 , 0x1c ) ;
if ( V_62 )
V_176 = 0 ;
else {
V_62 = F_22 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_6 . V_145 && V_62 )
V_176 = 0 ;
else
V_176 = 1 ;
}
V_43 = V_176 ? V_49 : V_64 ;
F_14 ( V_3 , 0x28 , V_43 ) ;
F_14 ( V_3 , 0x29 , V_43 ) ;
F_14 ( V_3 , 0x2a , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x1c , & V_43 ) ;
F_20 ( V_3 , 0x1d , & V_43 ) ;
if ( V_4 -> V_6 . V_145 )
F_14 ( V_3 , 0x25 , V_43 ) ;
F_14 ( V_3 , 0x16 , V_142 ? V_49 : V_43 ) ;
F_14 ( V_3 , 0x10 , V_176 ? V_49 : V_43 ) ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x16 ;
F_72 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_177 ;
V_4 -> V_91 [ V_4 -> V_92 ++ ] = V_178 ;
V_4 -> V_91 [ V_4 -> V_92 ++ ] = V_179 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_89 ;
return 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_142 ;
unsigned int V_43 ;
unsigned int V_62 ;
V_142 =
F_17 ( V_3 , 0x1e , 0 , V_144 , 0x00 ) == 3 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x29 , & V_43 ) ;
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_20 ( V_3 , 0x2b , & V_43 ) ;
V_43 = V_49 ;
F_14 ( V_3 , 0x1e , V_43 ) ;
F_14 ( V_3 , 0x1f , V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
F_14 ( V_3 , 0x8 , V_43 ) ;
if ( V_4 -> V_7 == V_31 ) {
V_43 = V_64 ;
F_20 ( V_3 , 0x28 , & V_43 ) ;
F_14 ( V_3 , 0x18 , V_43 ) ;
F_14 ( V_3 , 0x38 , V_43 ) ;
} else {
V_43 = V_64 ;
F_20 ( V_3 , 0x26 , & V_43 ) ;
F_14 ( V_3 , 0x1c , V_43 ) ;
F_14 ( V_3 , 0x37 , V_43 ) ;
}
if ( V_4 -> V_7 == V_31 ) {
V_43 = V_64 ;
F_20 ( V_3 , 0x25 , & V_43 ) ;
F_14 ( V_3 , 0x15 , V_43 ) ;
F_14 ( V_3 , 0x35 , V_43 ) ;
} else {
V_43 = V_64 ;
F_20 ( V_3 , 0x25 , & V_43 ) ;
F_14 ( V_3 , 0x19 , V_43 ) ;
F_14 ( V_3 , 0x35 , V_43 ) ;
}
if ( V_4 -> V_6 . V_145 )
F_14 ( V_3 , 0x9 , V_49 ) ;
V_62 = F_22 ( V_3 , 0x25 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x24 , & V_43 ) ;
V_43 = V_62 ? V_64 : V_49 ;
if ( V_4 -> V_7 == V_31 )
F_14 ( V_3 , 0x14 , V_43 ) ;
else
F_14 ( V_3 , 0x18 , V_43 ) ;
F_14 ( V_3 , 0x34 , V_43 ) ;
V_62 = F_22 ( V_3 , 0x26 ) ;
V_43 = V_62 ? V_64 : V_49 ;
if ( V_4 -> V_7 == V_31 ) {
F_14 ( V_3 , 0x33 , V_43 ) ;
F_14 ( V_3 , 0x1c , V_43 ) ;
F_14 ( V_3 , 0x3c , V_43 ) ;
} else {
F_14 ( V_3 , 0x31 , V_43 ) ;
F_14 ( V_3 , 0x17 , V_43 ) ;
F_14 ( V_3 , 0x3b , V_43 ) ;
}
if ( V_142 || ! F_30 ( V_3 ) )
F_14 ( V_3 , 0x21 , V_49 ) ;
else
F_14 ( V_3 , 0x21 , V_64 ) ;
}
static void F_92 ( struct V_2 * V_3 ,
const struct V_180 * V_181 , int V_98 )
{
if ( V_98 == V_182 )
F_72 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
static T_3 V_183 [] = { 0x14 , 0x1c } ;
static T_3 V_184 [] = { 0x1c } ;
F_84 ( V_3 , 0x24 , F_82 ( V_183 ) , V_183 ) ;
F_84 ( V_3 , 0x33 , F_82 ( V_184 ) , V_184 ) ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_31 )
F_93 ( V_3 ) ;
F_80 ( V_3 ) ;
F_95 ( V_3 , NULL , V_185 , V_186 ) ;
F_96 ( V_3 , V_182 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
if ( V_4 -> V_7 == V_31 )
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_187 ;
else
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_188 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_91 ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 ;
unsigned int V_62 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x29 , & V_43 ) ;
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_20 ( V_3 , 0x2b , & V_43 ) ;
V_43 = V_49 ;
F_14 ( V_3 , 0x1e , V_43 ) ;
F_14 ( V_3 , 0x1f , V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
F_14 ( V_3 , 0x8 , V_49 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x28 , & V_43 ) ;
F_14 ( V_3 , 0x18 , V_43 ) ;
F_14 ( V_3 , 0x38 , V_43 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x25 , & V_43 ) ;
F_14 ( V_3 , 0x15 , V_43 ) ;
F_14 ( V_3 , 0x35 , V_43 ) ;
if ( V_4 -> V_6 . V_145 )
F_14 ( V_3 , 0x9 , V_49 ) ;
V_62 = F_22 ( V_3 , 0x25 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x24 , & V_43 ) ;
if ( V_62 ) {
F_14 ( V_3 , 0x14 , V_64 ) ;
F_14 ( V_3 , 0x34 , V_64 ) ;
} else {
F_14 ( V_3 , 0x14 , V_49 ) ;
F_14 ( V_3 , 0x34 , V_49 ) ;
}
V_62 = F_22 ( V_3 , 0x28 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x31 , & V_43 ) ;
if ( V_62 ) {
F_14 ( V_3 , 0x1c , V_64 ) ;
F_14 ( V_3 , 0x3c , V_64 ) ;
F_14 ( V_3 , 0x3e , V_64 ) ;
} else {
F_14 ( V_3 , 0x1c , V_49 ) ;
F_14 ( V_3 , 0x3c , V_49 ) ;
F_14 ( V_3 , 0x3e , V_49 ) ;
}
V_43 = V_64 ;
F_20 ( V_3 , 0x33 , & V_43 ) ;
F_14 ( V_3 , 0x1d , V_43 ) ;
F_14 ( V_3 , 0x3d , V_43 ) ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_80 ( V_3 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_189 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_97 ;
return 0 ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_142 ;
unsigned int V_43 , V_161 ;
V_142 =
F_17 ( V_3 , 0x1e , 0 , V_144 , 0x00 ) == 4 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x29 , & V_43 ) ;
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_20 ( V_3 , 0x2b , & V_43 ) ;
if ( V_142 )
V_43 = V_49 ;
F_14 ( V_3 , 0x1e , V_43 ) ;
F_14 ( V_3 , 0x1f , V_43 ) ;
F_14 ( V_3 , 0x10 , V_43 ) ;
F_14 ( V_3 , 0x11 , V_43 ) ;
if ( V_4 -> V_7 == V_32 ) {
V_43 = V_64 ;
F_14 ( V_3 , 0x27 , V_43 ) ;
F_14 ( V_3 , 0x37 , V_43 ) ;
} else {
V_43 = V_64 ;
F_20 ( V_3 , 0x27 , & V_43 ) ;
F_14 ( V_3 , 0x37 , V_43 ) ;
}
V_43 = V_64 ;
F_20 ( V_3 , 0x26 , & V_43 ) ;
F_14 ( V_3 , 0x36 , V_43 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2b , & V_43 ) ;
F_14 ( V_3 , 0x3b , V_43 ) ;
F_14 ( V_3 , 0x1b , V_43 ) ;
}
F_16 ( V_3 , 0xa , V_43 , 2 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x25 , & V_43 ) ;
F_14 ( V_3 , 0x35 , V_43 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2a , & V_43 ) ;
F_14 ( V_3 , 0x3a , V_43 ) ;
F_14 ( V_3 , 0x1a , V_43 ) ;
}
F_16 ( V_3 , 0x9 , V_43 , 1 ) ;
V_43 = V_64 ;
F_20 ( V_3 , 0x28 , & V_43 ) ;
F_14 ( V_3 , 0x38 , V_43 ) ;
F_14 ( V_3 , 0x18 , V_43 ) ;
if ( V_4 -> V_6 . V_145 )
F_16 ( V_3 , 0xb , V_43 , 3 ) ;
V_161 = V_43 ;
V_43 = V_64 ;
F_20 ( V_3 , 0x24 , & V_43 ) ;
F_14 ( V_3 , 0x34 , V_43 ) ;
if ( ! V_4 -> V_6 . V_145 && V_161 != V_64 )
V_43 = V_161 ;
F_16 ( V_3 , 0x8 , V_43 , 0 ) ;
F_14 ( V_3 , 0x3f , V_142 ? V_49 : V_43 ) ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_130 ;
V_4 -> V_6 . V_131 = 0x3f ;
F_80 ( V_3 ) ;
V_90 = F_58 ( V_3 ) ;
if ( V_90 < 0 ) {
F_36 ( V_3 ) ;
return V_90 ;
}
V_4 -> V_117 [ V_4 -> V_116 ++ ] = V_190 ;
V_3 -> V_138 = V_139 ;
V_4 -> F_13 = F_99 ;
return 0 ;
}
static int T_4 F_101 ( void )
{
return F_102 ( & V_191 ) ;
}
static void T_5 F_103 ( void )
{
F_104 ( & V_191 ) ;
}
