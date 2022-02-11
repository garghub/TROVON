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
V_4 -> V_6 . V_15 = V_16 ;
return V_4 ;
}
static enum V_17 F_4 ( struct V_2 * V_3 )
{
T_1 V_18 = V_3 -> V_18 ;
T_2 V_19 = V_18 >> 16 ;
T_2 V_20 = V_18 & 0xffff ;
enum V_17 V_7 ;
if ( V_19 != 0x1106 )
V_7 = V_21 ;
else if ( V_20 >= 0x1708 && V_20 <= 0x170b )
V_7 = V_22 ;
else if ( V_20 >= 0xe710 && V_20 <= 0xe713 )
V_7 = V_23 ;
else if ( V_20 >= 0xe714 && V_20 <= 0xe717 )
V_7 = V_24 ;
else if ( V_20 >= 0xe720 && V_20 <= 0xe723 ) {
V_7 = V_25 ;
if ( F_5 ( V_3 , 0x16 , V_26 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_20 >= 0xe724 && V_20 <= 0xe727 )
V_7 = V_27 ;
else if ( ( V_20 & 0xfff ) == 0x397
&& ( V_20 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_20 & 0xfff ) == 0x398
&& ( V_20 >> 12 ) < 8 )
V_7 = V_28 ;
else if ( ( V_20 & 0xfff ) == 0x428
&& ( V_20 >> 12 ) < 8 )
V_7 = V_29 ;
else if ( V_20 == 0x0433 || V_20 == 0xa721 )
V_7 = V_30 ;
else if ( V_20 == 0x0441 || V_20 == 0x4441 )
V_7 = V_29 ;
else if ( V_20 == 0x0438 || V_20 == 0x4438 )
V_7 = V_31 ;
else if ( V_20 == 0x0448 )
V_7 = V_32 ;
else if ( V_20 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_20 & 0xfff ) == 0x446 )
V_7 = V_33 ;
else if ( V_20 == 0x4760 )
V_7 = V_34 ;
else if ( V_20 == 0x4761 || V_20 == 0x4762 )
V_7 = V_35 ;
else
V_7 = V_21 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_22 || ! V_4 -> V_6 . V_36 . V_37 )
return;
if ( V_4 -> V_38 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
V_3 -> V_39 = 0 ;
F_8 ( & V_3 -> V_40 ) ;
V_4 -> V_38 = false ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_22 || ! V_4 -> V_6 . V_36 . V_37 )
return;
if ( V_4 -> V_41 ) {
if ( ! V_4 -> V_38 ) {
V_3 -> V_39 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( V_3 -> V_42 -> V_43 ,
& V_3 -> V_40 , 0 ) ;
V_4 -> V_38 = true ;
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
static void F_14 ( struct V_2 * V_3 , T_3 V_44 ,
unsigned int V_45 )
{
if ( F_15 ( V_3 , V_44 , V_45 ) )
return;
F_7 ( V_3 , V_44 , 0 , V_46 , V_45 ) ;
}
static void F_16 ( struct V_2 * V_3 , T_3 V_44 ,
unsigned int V_45 , unsigned int V_47 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_48 ;
if ( F_15 ( V_3 , V_44 , V_45 ) )
return;
V_48 = F_17 ( V_3 , V_44 , 0 , V_49 , 0 ) ;
if ( V_48 && ( V_4 -> V_50 [ V_47 ] != V_48 ) )
V_4 -> V_50 [ V_47 ] = V_48 ;
F_7 ( V_3 , V_44 , 0 , V_46 , V_45 ) ;
if ( V_45 == V_51 ) {
V_48 = F_17 ( V_3 , V_44 , 0 , V_49 , 0 ) ;
if ( ! V_48 && ( V_4 -> V_50 [ V_47 ] != V_48 ) )
F_7 ( V_3 , V_44 , 0 ,
V_52 ,
V_4 -> V_50 [ V_47 ] ) ;
}
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return V_4 -> V_6 . V_53 > 2 ;
}
static bool F_19 ( struct V_2 * V_3 , T_3 V_54 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_4 -> V_6 . V_56 ; V_55 ++ )
if ( V_4 -> V_6 . V_57 [ V_55 ] . V_54 == V_54 )
return true ;
return false ;
}
static void F_20 ( struct V_2 * V_3 , T_3 V_44 ,
unsigned int * V_58 )
{
unsigned V_45 ;
unsigned V_59 = F_21 ( V_3 , V_44 ) ;
unsigned V_60 = ( V_59 & V_61 )
>> V_62
& V_63 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_64 = 0 ;
V_60 |= V_4 -> V_10 ;
if ( ! V_60 )
V_64 = F_22 ( V_3 , V_44 ) ;
if ( ( F_18 ( V_3 ) && F_19 ( V_3 , V_44 ) )
|| ( ( V_60 || V_64 )
&& F_23 ( V_59 ) != V_65 ) ) {
* V_58 = V_51 ;
V_45 = V_51 ;
} else
V_45 = V_66 ;
F_14 ( V_3 , V_44 , V_45 ) ;
}
static int F_24 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
return F_25 ( V_68 , V_70 ) ;
}
static int F_26 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_72 -> V_73 . V_74 . V_75 [ 0 ] = ! V_4 -> V_10 ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_76 = ! V_72 -> V_73 . V_74 . V_75 [ 0 ] ;
if ( V_76 == V_4 -> V_10 )
return 0 ;
V_4 -> V_10 = V_76 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
return 1 ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_77 * V_78 ;
int V_79 , V_80 ;
V_78 = V_4 -> V_6 . V_81 . V_82 ;
if ( ! V_78 )
return true ;
for (; V_78 -> V_44 ; V_78 ++ ) {
for ( V_79 = 0 ; V_79 < 2 ; V_79 ++ ) {
V_80 = F_31 ( V_3 , V_78 -> V_44 , V_79 , V_78 -> V_83 ,
V_78 -> V_84 ) ;
if ( ! ( V_80 & V_85 ) && V_80 > 0 )
return false ;
}
}
return true ;
}
static void F_32 ( struct V_2 * V_3 , bool V_86 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_87 ;
unsigned int V_88 , V_45 ;
if ( V_4 -> V_10 )
V_87 = false ;
else
V_87 = F_30 ( V_3 ) && ! V_4 -> V_6 . V_89 ;
if ( V_87 == V_4 -> V_90 && ! V_86 )
return;
V_4 -> V_90 = V_87 ;
switch ( V_4 -> V_7 ) {
case V_25 :
case V_27 :
V_88 = 0xf70 ;
V_45 = V_87 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_29 :
case V_30 :
V_88 = 0xf73 ;
V_45 = V_87 ? 0x51 : 0xe1 ;
break;
case V_28 :
V_88 = 0xf73 ;
V_45 = V_87 ? 0x01 : 0x1d ;
break;
case V_31 :
case V_32 :
case V_33 :
V_88 = 0xf93 ;
V_45 = V_87 ? 0x00 : 0xe0 ;
break;
case V_34 :
case V_35 :
V_88 = 0xf82 ;
V_45 = V_87 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_91 , 0 , V_88 , V_45 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , false ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_92 , V_55 ;
V_92 = F_34 ( V_3 ) ;
if ( V_92 < 0 )
return V_92 ;
if ( V_4 -> F_13 )
V_4 -> V_93 [ V_4 -> V_94 ++ ] = V_95 ;
for ( V_55 = 0 ; V_55 < V_4 -> V_94 ; V_55 ++ ) {
V_92 = F_35 ( V_3 , V_4 -> V_93 [ V_55 ] ) ;
if ( V_92 < 0 )
return V_92 ;
}
return 0 ;
}
static void V_14 ( struct V_96 * V_97 ,
struct V_2 * V_3 ,
struct V_98 * V_99 ,
int V_100 )
{
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_6 ( V_3 ) ;
F_37 ( V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_3 ) ;
if ( V_4 -> V_7 == V_33 )
F_39 ( V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , T_3 V_44 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_41 ( V_3 , & V_4 -> V_6 . V_81 , V_44 ) ;
}
static void F_42 ( struct V_2 * V_3 , T_3 V_44 )
{
unsigned int V_59 ;
unsigned char V_101 ;
V_59 = F_21 ( V_3 , V_44 ) ;
V_101 = ( unsigned char ) F_43 ( V_59 ) ;
V_101 = ( V_101 << 4 ) | F_44 ( V_59 ) ;
if ( F_23 ( V_59 ) == V_65
&& ( V_101 == 0xf0 || V_101 == 0xff ) ) {
V_59 = V_59 & ( ~ ( V_102 << 30 ) ) ;
F_45 ( V_3 , V_44 , V_59 ) ;
}
return;
}
static int F_46 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_22 )
return 0 ;
V_72 -> V_73 . integer . V_73 [ 0 ] = V_4 -> V_41 ;
return 0 ;
}
static int F_47 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_76 ;
if ( V_4 -> V_7 != V_22 )
return 0 ;
V_76 = ! ! V_72 -> V_73 . integer . V_73 [ 0 ] ;
if ( V_4 -> V_41 == V_76 )
return 0 ;
V_4 -> V_41 = V_76 ;
F_9 ( V_3 ) ;
return 1 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_103 * V_104 )
{
F_13 ( V_3 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_105 * V_106 = & V_4 -> V_6 . V_36 ;
T_3 V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_106 -> V_107 ; V_55 ++ ) {
V_54 = V_106 -> V_108 [ V_55 ] ;
if ( V_54 && F_50 ( V_3 , V_54 ) )
F_51 ( V_3 , V_54 ,
F_48 ) ;
}
for ( V_55 = 0 ; V_55 < V_106 -> V_109 ; V_55 ++ ) {
V_54 = V_106 -> V_108 [ V_55 ] ;
if ( V_54 && F_50 ( V_3 , V_54 ) )
F_51 ( V_3 , V_54 ,
F_48 ) ;
}
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_92 ;
V_4 -> V_6 . V_110 = & V_111 ;
V_4 -> V_6 . V_112 = & V_113 ;
V_92 = F_53 ( V_3 , & V_4 -> V_6 . V_36 , NULL , 0 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_54 ( V_3 , & V_4 -> V_6 . V_36 ) ;
if ( V_92 < 0 )
return V_92 ;
F_49 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_4 -> V_114 ; V_55 ++ )
F_56 ( V_3 , V_4 -> V_115 [ V_55 ] ) ;
F_13 ( V_3 ) ;
F_32 ( V_3 , true ) ;
F_57 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
int V_92 ;
int V_116 = V_3 -> V_39 ;
V_3 -> V_39 = F_10 ( 100 ) ;
V_92 = F_33 ( V_3 ) ;
V_3 -> V_39 = V_116 ;
return V_92 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_55 , V_92 ;
V_92 = F_60 ( V_3 ) ;
if ( V_92 < 0 || V_3 -> V_18 != 0x11061708 )
return V_92 ;
for ( V_55 = 0 ; V_55 < V_3 -> V_117 ; V_55 ++ ) {
struct V_118 * V_119 = & V_4 -> V_6 . V_120 [ V_55 ] ;
if ( ! V_119 -> V_121 [ V_122 ] . V_123 ||
V_119 -> V_124 != V_125 )
continue;
V_119 -> V_121 [ V_122 ] . V_126 =
V_127 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x17 ;
V_3 -> V_39 = F_10 ( 100 ) ;
V_4 -> V_41 = 1 ;
V_4 -> V_6 . V_130 = 1 ;
V_4 -> V_6 . V_131 = 1 ;
F_42 ( V_3 , V_132 ) ;
F_42 ( V_3 , V_133 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_93 [ V_4 -> V_94 ++ ] = V_134 ;
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_135 ;
V_3 -> V_136 = V_137 ;
V_3 -> V_136 . V_138 = F_58 ;
V_3 -> V_136 . V_139 = F_59 ;
V_3 -> V_39 = 0 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x18 ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_3 -> V_136 = V_137 ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_140 ;
unsigned int V_45 ;
int V_141 = 0 ;
if ( ( V_4 -> V_7 != V_27 ) &&
( V_3 -> V_18 != 0x11064397 ) )
V_141 = 1 ;
V_140 =
( F_17 ( V_3 , 0x17 , 0 , V_142 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x1a , & V_45 ) ;
F_20 ( V_3 , 0x1b , & V_45 ) ;
F_20 ( V_3 , 0x1e , & V_45 ) ;
if ( V_140 )
V_45 = V_51 ;
F_14 ( V_3 , 0x17 , V_45 ) ;
F_14 ( V_3 , 0x13 , V_45 ) ;
F_14 ( V_3 , 0x14 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x19 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_45 ) ;
F_14 ( V_3 , 0x18 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
if ( V_141 ) {
V_45 = V_66 ;
F_20 ( V_3 , 0x22 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_45 ) ;
F_14 ( V_3 , 0x26 , V_45 ) ;
F_14 ( V_3 , 0x24 , V_45 ) ;
} else if ( V_3 -> V_18 == 0x11064397 ) {
V_45 = V_66 ;
F_20 ( V_3 , 0x23 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_45 ) ;
F_14 ( V_3 , 0x27 , V_45 ) ;
F_14 ( V_3 , 0x25 , V_45 ) ;
}
V_45 = V_66 ;
F_20 ( V_3 , 0x1c , & V_45 ) ;
F_20 ( V_3 , 0x1d , & V_45 ) ;
if ( V_141 )
F_20 ( V_3 , 0x23 , & V_45 ) ;
F_14 ( V_3 , 0x16 , V_140 ? V_51 : V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
if ( V_141 ) {
F_14 ( V_3 , 0x25 , V_45 ) ;
F_14 ( V_3 , 0x27 , V_45 ) ;
} else if ( V_3 -> V_18 == 0x11064397 && V_4 -> V_6 . V_143 )
F_14 ( V_3 , 0x25 , V_45 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
if ( F_4 ( V_3 ) == V_8 )
return F_65 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x16 ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_63 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 , T_3 V_54 ,
int V_144 , int V_145 , int V_146 )
{
F_67 ( V_3 , V_54 ,
F_68 ( V_3 , V_54 ) | V_147 ) ;
F_69 ( V_3 , V_54 , V_148 ,
( V_144 << V_149 ) |
( V_145 << V_150 ) |
( V_146 << V_151 ) |
( 0 << V_152 ) ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x16 ;
F_66 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 ) {
F_70 ( V_3 -> V_153 ) ;
V_3 -> V_153 = F_71 ( L_1 , V_5 ) ;
snprintf ( V_3 -> V_42 -> V_154 -> V_155 ,
sizeof( V_3 -> V_42 -> V_154 -> V_155 ) ,
L_2 , V_3 -> V_156 , V_3 -> V_153 ) ;
}
if ( V_3 -> V_18 == 0x11064397 ) {
F_70 ( V_3 -> V_153 ) ;
V_3 -> V_153 = F_71 ( L_3 , V_5 ) ;
snprintf ( V_3 -> V_42 -> V_154 -> V_155 ,
sizeof( V_3 -> V_42 -> V_154 -> V_155 ) ,
L_2 , V_3 -> V_156 , V_3 -> V_153 ) ;
}
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_157 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_63 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_140 =
F_17 ( V_3 , 0x13 , 0 , V_142 , 0x00 ) == 3 ;
unsigned int V_45 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x14 , & V_45 ) ;
F_20 ( V_3 , 0x15 , & V_45 ) ;
F_20 ( V_3 , 0x18 , & V_45 ) ;
if ( V_140 )
V_45 = V_51 ;
F_14 ( V_3 , 0x13 , V_45 ) ;
F_14 ( V_3 , 0x12 , V_45 ) ;
F_14 ( V_3 , 0x1f , V_45 ) ;
F_14 ( V_3 , 0x20 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x17 , & V_45 ) ;
F_20 ( V_3 , 0x16 , & V_45 ) ;
F_14 ( V_3 , 0x1a , V_140 ? V_51 : V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
F_14 ( V_3 , 0x1d , V_45 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x1a ;
F_69 ( V_3 , 0x1A , V_148 ,
( 0x17 << V_149 ) |
( 0x17 << V_150 ) |
( 0x5 << V_151 ) |
( 1 << V_152 ) ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_158 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_72 ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_140 ;
unsigned int V_45 , V_159 ;
V_140 =
F_17 ( V_3 , 0x1e , 0 , V_142 , 0x00 ) == 5 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x29 , & V_45 ) ;
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_20 ( V_3 , 0x2b , & V_45 ) ;
if ( V_140 )
V_45 = V_51 ;
F_14 ( V_3 , 0x1e , V_45 ) ;
F_14 ( V_3 , 0x1f , V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x27 , & V_45 ) ;
F_14 ( V_3 , 0x1a , V_45 ) ;
V_159 = V_45 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x26 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2b , & V_45 ) ;
F_14 ( V_3 , 0xa , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x24 , & V_45 ) ;
if ( ! V_4 -> V_6 . V_143 )
F_20 ( V_3 , 0x28 , & V_45 ) ;
F_14 ( V_3 , 0x8 , V_45 ) ;
if ( ! V_4 -> V_6 . V_143 && V_159 != V_66 )
V_45 = V_159 ;
F_14 ( V_3 , 0xb , V_45 ) ;
F_14 ( V_3 , 0x21 , V_140 ? V_51 : V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x25 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_14 ( V_3 , 0x9 , V_45 ) ;
if ( V_4 -> V_6 . V_143 ) {
V_45 = V_66 ;
F_20 ( V_3 , 0x28 , & V_45 ) ;
F_14 ( V_3 , 0x1b , V_45 ) ;
F_14 ( V_3 , 0x34 , V_45 ) ;
F_14 ( V_3 , 0xc , V_45 ) ;
}
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_55 , V_160 ;
T_3 V_161 [ 8 ] ;
T_3 V_44 ;
if ( ! V_4 -> V_6 . V_129 )
return 0 ;
V_160 = F_76 ( V_3 , V_4 -> V_6 . V_129 , V_161 ,
F_77 ( V_161 ) - 1 ) ;
for ( V_55 = 0 ; V_55 < V_160 ; V_55 ++ ) {
if ( F_78 ( F_68 ( V_3 , V_161 [ V_55 ] ) ) == V_162 )
return 0 ;
}
V_44 = V_3 -> V_163 ;
for ( V_55 = 0 ; V_55 < V_3 -> V_164 ; V_55 ++ , V_44 ++ ) {
unsigned int V_165 = F_68 ( V_3 , V_44 ) ;
if ( F_78 ( V_165 ) == V_162 &&
! ( V_165 & V_166 ) ) {
V_161 [ V_160 ++ ] = V_44 ;
return F_79 ( V_3 ,
V_4 -> V_6 . V_129 ,
V_160 , V_161 ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_75 ( V_3 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_167 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_74 ;
return 0 ;
}
static int F_81 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
V_70 -> type = V_168 ;
V_70 -> V_169 = 1 ;
V_70 -> V_73 . integer . V_170 = 0 ;
V_70 -> V_73 . integer . V_171 = 1 ;
return 0 ;
}
static int F_82 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
int V_47 = 0 ;
V_47 = F_17 ( V_3 , 0x26 , 0 ,
V_142 , 0 ) ;
if ( V_47 != - 1 )
* V_72 -> V_73 . integer . V_73 = V_47 ;
return 0 ;
}
static int F_83 ( struct V_67 * V_68 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_27 ( V_68 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 = * V_72 -> V_73 . integer . V_73 ;
F_7 ( V_3 , 0x26 , 0 ,
V_172 , V_47 ) ;
V_4 -> V_173 = V_47 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_140 ;
unsigned int V_45 ;
unsigned int V_174 , V_64 ;
V_140 =
( F_17 ( V_3 , 0x17 , 0 ,
V_142 , 0x00 ) == 5 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x1a , & V_45 ) ;
F_20 ( V_3 , 0x1b , & V_45 ) ;
F_20 ( V_3 , 0x1e , & V_45 ) ;
if ( V_140 )
V_45 = V_51 ;
F_14 ( V_3 , 0x17 , V_45 ) ;
F_14 ( V_3 , 0x13 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x1e , & V_45 ) ;
if ( V_4 -> V_173 )
F_20 ( V_3 , 0x22 , & V_45 ) ;
else
F_14 ( V_3 , 0x22 , V_66 ) ;
F_14 ( V_3 , 0x26 , V_45 ) ;
F_14 ( V_3 , 0x14 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x19 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_45 ) ;
F_14 ( V_3 , 0x18 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x23 , & V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_45 ) ;
F_14 ( V_3 , 0x27 , V_45 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1e , & V_45 ) ;
F_14 ( V_3 , 0x25 , V_45 ) ;
V_64 = F_22 ( V_3 , 0x1c ) ;
if ( V_64 )
V_174 = 0 ;
else {
V_64 = F_22 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_6 . V_143 && V_64 )
V_174 = 0 ;
else
V_174 = 1 ;
}
V_45 = V_174 ? V_51 : V_66 ;
F_14 ( V_3 , 0x28 , V_45 ) ;
F_14 ( V_3 , 0x29 , V_45 ) ;
F_14 ( V_3 , 0x2a , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x1c , & V_45 ) ;
F_20 ( V_3 , 0x1d , & V_45 ) ;
if ( V_4 -> V_6 . V_143 )
F_14 ( V_3 , 0x25 , V_45 ) ;
F_14 ( V_3 , 0x16 , V_140 ? V_51 : V_45 ) ;
F_14 ( V_3 , 0x10 , V_174 ? V_51 : V_45 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x16 ;
F_66 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_175 ;
V_4 -> V_93 [ V_4 -> V_94 ++ ] = V_176 ;
V_4 -> V_93 [ V_4 -> V_94 ++ ] = V_177 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_84 ;
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_140 ;
unsigned int V_45 ;
unsigned int V_64 ;
V_140 =
F_17 ( V_3 , 0x1e , 0 , V_142 , 0x00 ) == 3 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x29 , & V_45 ) ;
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_20 ( V_3 , 0x2b , & V_45 ) ;
V_45 = V_51 ;
F_14 ( V_3 , 0x1e , V_45 ) ;
F_14 ( V_3 , 0x1f , V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
F_14 ( V_3 , 0x8 , V_45 ) ;
if ( V_4 -> V_7 == V_33 ) {
V_45 = V_66 ;
F_20 ( V_3 , 0x28 , & V_45 ) ;
F_14 ( V_3 , 0x18 , V_45 ) ;
F_14 ( V_3 , 0x38 , V_45 ) ;
} else {
V_45 = V_66 ;
F_20 ( V_3 , 0x26 , & V_45 ) ;
F_14 ( V_3 , 0x1c , V_45 ) ;
F_14 ( V_3 , 0x37 , V_45 ) ;
}
if ( V_4 -> V_7 == V_33 ) {
V_45 = V_66 ;
F_20 ( V_3 , 0x25 , & V_45 ) ;
F_14 ( V_3 , 0x15 , V_45 ) ;
F_14 ( V_3 , 0x35 , V_45 ) ;
} else {
V_45 = V_66 ;
F_20 ( V_3 , 0x25 , & V_45 ) ;
F_14 ( V_3 , 0x19 , V_45 ) ;
F_14 ( V_3 , 0x35 , V_45 ) ;
}
if ( V_4 -> V_6 . V_143 )
F_14 ( V_3 , 0x9 , V_51 ) ;
V_64 = F_22 ( V_3 , 0x25 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x24 , & V_45 ) ;
V_45 = V_64 ? V_66 : V_51 ;
if ( V_4 -> V_7 == V_33 )
F_14 ( V_3 , 0x14 , V_45 ) ;
else
F_14 ( V_3 , 0x18 , V_45 ) ;
F_14 ( V_3 , 0x34 , V_45 ) ;
V_64 = F_22 ( V_3 , 0x26 ) ;
V_45 = V_64 ? V_66 : V_51 ;
if ( V_4 -> V_7 == V_33 ) {
F_14 ( V_3 , 0x33 , V_45 ) ;
F_14 ( V_3 , 0x1c , V_45 ) ;
F_14 ( V_3 , 0x3c , V_45 ) ;
} else {
F_14 ( V_3 , 0x31 , V_45 ) ;
F_14 ( V_3 , 0x17 , V_45 ) ;
F_14 ( V_3 , 0x3b , V_45 ) ;
}
if ( V_140 || ! F_30 ( V_3 ) )
F_14 ( V_3 , 0x21 , V_51 ) ;
else
F_14 ( V_3 , 0x21 , V_66 ) ;
}
static void F_87 ( struct V_2 * V_3 ,
const struct V_178 * V_179 , int V_100 )
{
if ( V_100 == V_180 )
F_66 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_88 ( struct V_2 * V_3 )
{
static T_3 V_181 [] = { 0x14 , 0x1c } ;
static T_3 V_182 [] = { 0x1c } ;
F_79 ( V_3 , 0x24 , F_77 ( V_181 ) , V_181 ) ;
F_79 ( V_3 , 0x33 , F_77 ( V_182 ) , V_182 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_33 )
F_88 ( V_3 ) ;
F_75 ( V_3 ) ;
F_90 ( V_3 , NULL , V_183 , V_184 ) ;
F_91 ( V_3 , V_180 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
if ( V_4 -> V_7 == V_33 )
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_185 ;
else
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_186 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_86 ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_45 ;
unsigned int V_64 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x29 , & V_45 ) ;
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_20 ( V_3 , 0x2b , & V_45 ) ;
V_45 = V_51 ;
F_14 ( V_3 , 0x1e , V_45 ) ;
F_14 ( V_3 , 0x1f , V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
F_14 ( V_3 , 0x8 , V_51 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x28 , & V_45 ) ;
F_14 ( V_3 , 0x18 , V_45 ) ;
F_14 ( V_3 , 0x38 , V_45 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x25 , & V_45 ) ;
F_14 ( V_3 , 0x15 , V_45 ) ;
F_14 ( V_3 , 0x35 , V_45 ) ;
if ( V_4 -> V_6 . V_143 )
F_14 ( V_3 , 0x9 , V_51 ) ;
V_64 = F_22 ( V_3 , 0x25 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x24 , & V_45 ) ;
if ( V_64 ) {
F_14 ( V_3 , 0x14 , V_66 ) ;
F_14 ( V_3 , 0x34 , V_66 ) ;
} else {
F_14 ( V_3 , 0x14 , V_51 ) ;
F_14 ( V_3 , 0x34 , V_51 ) ;
}
V_64 = F_22 ( V_3 , 0x28 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x31 , & V_45 ) ;
if ( V_64 ) {
F_14 ( V_3 , 0x1c , V_66 ) ;
F_14 ( V_3 , 0x3c , V_66 ) ;
F_14 ( V_3 , 0x3e , V_66 ) ;
} else {
F_14 ( V_3 , 0x1c , V_51 ) ;
F_14 ( V_3 , 0x3c , V_51 ) ;
F_14 ( V_3 , 0x3e , V_51 ) ;
}
V_45 = V_66 ;
F_20 ( V_3 , 0x33 , & V_45 ) ;
F_14 ( V_3 , 0x1d , V_45 ) ;
F_14 ( V_3 , 0x3d , V_45 ) ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_75 ( V_3 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_187 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_92 ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_140 ;
unsigned int V_45 , V_159 ;
V_140 =
F_17 ( V_3 , 0x1e , 0 , V_142 , 0x00 ) == 4 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x29 , & V_45 ) ;
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_20 ( V_3 , 0x2b , & V_45 ) ;
if ( V_140 )
V_45 = V_51 ;
F_14 ( V_3 , 0x1e , V_45 ) ;
F_14 ( V_3 , 0x1f , V_45 ) ;
F_14 ( V_3 , 0x10 , V_45 ) ;
F_14 ( V_3 , 0x11 , V_45 ) ;
if ( V_4 -> V_7 == V_34 ) {
V_45 = V_66 ;
F_14 ( V_3 , 0x27 , V_45 ) ;
F_14 ( V_3 , 0x37 , V_45 ) ;
} else {
V_45 = V_66 ;
F_20 ( V_3 , 0x27 , & V_45 ) ;
F_14 ( V_3 , 0x37 , V_45 ) ;
}
V_45 = V_66 ;
F_20 ( V_3 , 0x26 , & V_45 ) ;
F_14 ( V_3 , 0x36 , V_45 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2b , & V_45 ) ;
F_14 ( V_3 , 0x3b , V_45 ) ;
F_14 ( V_3 , 0x1b , V_45 ) ;
}
F_16 ( V_3 , 0xa , V_45 , 2 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x25 , & V_45 ) ;
F_14 ( V_3 , 0x35 , V_45 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2a , & V_45 ) ;
F_14 ( V_3 , 0x3a , V_45 ) ;
F_14 ( V_3 , 0x1a , V_45 ) ;
}
F_16 ( V_3 , 0x9 , V_45 , 1 ) ;
V_45 = V_66 ;
F_20 ( V_3 , 0x28 , & V_45 ) ;
F_14 ( V_3 , 0x38 , V_45 ) ;
F_14 ( V_3 , 0x18 , V_45 ) ;
if ( V_4 -> V_6 . V_143 )
F_16 ( V_3 , 0xb , V_45 , 3 ) ;
V_159 = V_45 ;
V_45 = V_66 ;
F_20 ( V_3 , 0x24 , & V_45 ) ;
F_14 ( V_3 , 0x34 , V_45 ) ;
if ( ! V_4 -> V_6 . V_143 && V_159 != V_66 )
V_45 = V_159 ;
F_16 ( V_3 , 0x8 , V_45 , 0 ) ;
F_14 ( V_3 , 0x3f , V_140 ? V_51 : V_45 ) ;
}
static int F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_92 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_128 ;
V_4 -> V_6 . V_129 = 0x3f ;
F_75 ( V_3 ) ;
V_92 = F_52 ( V_3 ) ;
if ( V_92 < 0 ) {
F_36 ( V_3 ) ;
return V_92 ;
}
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_188 ;
V_3 -> V_136 = V_137 ;
V_4 -> F_13 = F_94 ;
return 0 ;
}
static int T_4 F_96 ( void )
{
return F_97 ( & V_189 ) ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_189 ) ;
}
