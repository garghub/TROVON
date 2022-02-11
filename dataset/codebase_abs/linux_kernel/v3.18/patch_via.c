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
V_4 -> V_6 . V_15 = 1 ;
return V_4 ;
}
static enum V_16 F_4 ( struct V_2 * V_3 )
{
T_1 V_17 = V_3 -> V_17 ;
T_2 V_18 = V_17 >> 16 ;
T_2 V_19 = V_17 & 0xffff ;
enum V_16 V_7 ;
if ( V_18 != 0x1106 )
V_7 = V_20 ;
else if ( V_19 >= 0x1708 && V_19 <= 0x170b )
V_7 = V_21 ;
else if ( V_19 >= 0xe710 && V_19 <= 0xe713 )
V_7 = V_22 ;
else if ( V_19 >= 0xe714 && V_19 <= 0xe717 )
V_7 = V_23 ;
else if ( V_19 >= 0xe720 && V_19 <= 0xe723 ) {
V_7 = V_24 ;
if ( F_5 ( V_3 , 0x16 , V_25 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_19 >= 0xe724 && V_19 <= 0xe727 )
V_7 = V_26 ;
else if ( ( V_19 & 0xfff ) == 0x397
&& ( V_19 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_19 & 0xfff ) == 0x398
&& ( V_19 >> 12 ) < 8 )
V_7 = V_27 ;
else if ( ( V_19 & 0xfff ) == 0x428
&& ( V_19 >> 12 ) < 8 )
V_7 = V_28 ;
else if ( V_19 == 0x0433 || V_19 == 0xa721 )
V_7 = V_29 ;
else if ( V_19 == 0x0441 || V_19 == 0x4441 )
V_7 = V_28 ;
else if ( V_19 == 0x0438 || V_19 == 0x4438 )
V_7 = V_30 ;
else if ( V_19 == 0x0448 )
V_7 = V_31 ;
else if ( V_19 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_19 & 0xfff ) == 0x446 )
V_7 = V_32 ;
else if ( V_19 == 0x4760 )
V_7 = V_33 ;
else if ( V_19 == 0x4761 || V_19 == 0x4762 )
V_7 = V_34 ;
else
V_7 = V_20 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_21 || ! V_4 -> V_6 . V_35 . V_36 )
return;
if ( V_4 -> V_37 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
V_3 -> V_38 = 0 ;
F_8 ( & V_3 -> V_39 ) ;
V_4 -> V_37 = false ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_21 || ! V_4 -> V_6 . V_35 . V_36 )
return;
if ( V_4 -> V_40 ) {
if ( ! V_4 -> V_37 ) {
V_3 -> V_38 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( V_3 -> V_41 -> V_42 ,
& V_3 -> V_39 , 0 ) ;
V_4 -> V_37 = true ;
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
static void F_14 ( struct V_2 * V_3 , T_3 V_43 ,
unsigned int V_44 )
{
if ( F_15 ( V_3 , V_43 , V_44 ) )
return;
F_7 ( V_3 , V_43 , 0 , V_45 , V_44 ) ;
}
static void F_16 ( struct V_2 * V_3 , T_3 V_43 ,
unsigned int V_44 , unsigned int V_46 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_47 ;
if ( F_15 ( V_3 , V_43 , V_44 ) )
return;
V_47 = F_17 ( V_3 , V_43 , 0 , V_48 , 0 ) ;
if ( V_47 && ( V_4 -> V_49 [ V_46 ] != V_47 ) )
V_4 -> V_49 [ V_46 ] = V_47 ;
F_7 ( V_3 , V_43 , 0 , V_45 , V_44 ) ;
if ( V_44 == V_50 ) {
V_47 = F_17 ( V_3 , V_43 , 0 , V_48 , 0 ) ;
if ( ! V_47 && ( V_4 -> V_49 [ V_46 ] != V_47 ) )
F_7 ( V_3 , V_43 , 0 ,
V_51 ,
V_4 -> V_49 [ V_46 ] ) ;
}
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return V_4 -> V_6 . V_52 > 2 ;
}
static bool F_19 ( struct V_2 * V_3 , T_3 V_53 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_6 . V_55 ; V_54 ++ )
if ( V_4 -> V_6 . V_56 [ V_54 ] . V_53 == V_53 )
return true ;
return false ;
}
static void F_20 ( struct V_2 * V_3 , T_3 V_43 ,
unsigned int * V_57 )
{
unsigned V_44 ;
unsigned V_58 = F_21 ( V_3 , V_43 ) ;
unsigned V_59 = ( V_58 & V_60 )
>> V_61
& V_62 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_63 = 0 ;
V_59 |= V_4 -> V_10 ;
if ( ! V_59 )
V_63 = F_22 ( V_3 , V_43 ) ;
if ( ( F_18 ( V_3 ) && F_19 ( V_3 , V_43 ) )
|| ( ( V_59 || V_63 )
&& F_23 ( V_58 ) != V_64 ) ) {
* V_57 = V_50 ;
V_44 = V_50 ;
} else
V_44 = V_65 ;
F_14 ( V_3 , V_43 , V_44 ) ;
}
static int F_24 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
return F_25 ( V_67 , V_69 ) ;
}
static int F_26 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_71 -> V_72 . V_73 . V_74 [ 0 ] = ! V_4 -> V_10 ;
return 0 ;
}
static int F_28 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_75 = ! V_71 -> V_72 . V_73 . V_74 [ 0 ] ;
if ( V_75 == V_4 -> V_10 )
return 0 ;
V_4 -> V_10 = V_75 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
return 1 ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_76 * V_77 ;
int V_78 , V_79 ;
V_77 = V_4 -> V_6 . V_80 . V_81 ;
if ( ! V_77 )
return true ;
for (; V_77 -> V_43 ; V_77 ++ ) {
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
V_79 = F_31 ( V_3 , V_77 -> V_43 , V_78 , V_77 -> V_82 ,
V_77 -> V_83 ) ;
if ( ! ( V_79 & V_84 ) && V_79 > 0 )
return false ;
}
}
return true ;
}
static void F_32 ( struct V_2 * V_3 , bool V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_86 ;
unsigned int V_87 , V_44 ;
if ( V_4 -> V_10 )
V_86 = false ;
else
V_86 = F_30 ( V_3 ) && ! V_4 -> V_6 . V_88 ;
if ( V_86 == V_4 -> V_89 && ! V_85 )
return;
V_4 -> V_89 = V_86 ;
switch ( V_4 -> V_7 ) {
case V_24 :
case V_26 :
V_87 = 0xf70 ;
V_44 = V_86 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_28 :
case V_29 :
V_87 = 0xf73 ;
V_44 = V_86 ? 0x51 : 0xe1 ;
break;
case V_27 :
V_87 = 0xf73 ;
V_44 = V_86 ? 0x01 : 0x1d ;
break;
case V_30 :
case V_31 :
case V_32 :
V_87 = 0xf93 ;
V_44 = V_86 ? 0x00 : 0xe0 ;
break;
case V_33 :
case V_34 :
V_87 = 0xf82 ;
V_44 = V_86 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_90 , 0 , V_87 , V_44 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , false ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_91 , V_54 ;
V_91 = F_34 ( V_3 ) ;
if ( V_91 < 0 )
return V_91 ;
if ( V_4 -> F_13 )
V_4 -> V_92 [ V_4 -> V_93 ++ ] = V_94 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_93 ; V_54 ++ ) {
V_91 = F_35 ( V_3 , V_4 -> V_92 [ V_54 ] ) ;
if ( V_91 < 0 )
return V_91 ;
}
return 0 ;
}
static void V_14 ( struct V_95 * V_96 ,
struct V_2 * V_3 ,
struct V_97 * V_98 ,
int V_99 )
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
if ( V_4 -> V_7 == V_32 )
F_39 ( V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , T_3 V_43 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_41 ( V_3 , & V_4 -> V_6 . V_80 , V_43 ) ;
}
static void F_42 ( struct V_2 * V_3 , T_3 V_43 )
{
unsigned int V_58 ;
unsigned char V_100 ;
V_58 = F_21 ( V_3 , V_43 ) ;
V_100 = ( unsigned char ) F_43 ( V_58 ) ;
V_100 = ( V_100 << 4 ) | F_44 ( V_58 ) ;
if ( F_23 ( V_58 ) == V_64
&& ( V_100 == 0xf0 || V_100 == 0xff ) ) {
V_58 = V_58 & ( ~ ( V_101 << 30 ) ) ;
F_45 ( V_3 , V_43 , V_58 ) ;
}
return;
}
static int F_46 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_21 )
return 0 ;
V_71 -> V_72 . integer . V_72 [ 0 ] = V_4 -> V_40 ;
return 0 ;
}
static int F_47 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_75 ;
if ( V_4 -> V_7 != V_21 )
return 0 ;
V_75 = ! ! V_71 -> V_72 . integer . V_72 [ 0 ] ;
if ( V_4 -> V_40 == V_75 )
return 0 ;
V_4 -> V_40 = V_75 ;
F_9 ( V_3 ) ;
return 1 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
F_13 ( V_3 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_104 * V_105 = & V_4 -> V_6 . V_35 ;
T_3 V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_105 -> V_106 ; V_54 ++ ) {
V_53 = V_105 -> V_107 [ V_54 ] ;
if ( V_53 && F_50 ( V_3 , V_53 ) )
F_51 ( V_3 , V_53 ,
F_48 ) ;
}
for ( V_54 = 0 ; V_54 < V_105 -> V_108 ; V_54 ++ ) {
V_53 = V_105 -> V_107 [ V_54 ] ;
if ( V_53 && F_50 ( V_3 , V_53 ) )
F_51 ( V_3 , V_53 ,
F_48 ) ;
}
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_91 ;
V_4 -> V_6 . V_109 = & V_110 ;
V_4 -> V_6 . V_111 = & V_112 ;
V_91 = F_53 ( V_3 , & V_4 -> V_6 . V_35 , NULL , 0 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_54 ( V_3 , & V_4 -> V_6 . V_35 ) ;
if ( V_91 < 0 )
return V_91 ;
F_49 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_113 ; V_54 ++ )
F_56 ( V_3 , V_4 -> V_114 [ V_54 ] ) ;
F_13 ( V_3 ) ;
F_32 ( V_3 , true ) ;
F_57 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
int V_91 ;
int V_115 = V_3 -> V_38 ;
V_3 -> V_38 = F_10 ( 100 ) ;
V_91 = F_33 ( V_3 ) ;
V_3 -> V_38 = V_115 ;
return V_91 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 , V_91 ;
V_91 = F_60 ( V_3 ) ;
if ( V_91 < 0 || V_3 -> V_17 != 0x11061708 )
return V_91 ;
for ( V_54 = 0 ; V_54 < V_3 -> V_116 ; V_54 ++ ) {
struct V_117 * V_118 = & V_4 -> V_6 . V_119 [ V_54 ] ;
if ( ! V_118 -> V_120 [ V_121 ] . V_122 ||
V_118 -> V_123 != V_124 )
continue;
V_118 -> V_120 [ V_121 ] . V_125 =
V_126 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x17 ;
V_3 -> V_38 = F_10 ( 100 ) ;
V_4 -> V_40 = 1 ;
V_4 -> V_6 . V_129 = 1 ;
V_4 -> V_6 . V_130 = 1 ;
F_42 ( V_3 , V_131 ) ;
F_42 ( V_3 , V_132 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_92 [ V_4 -> V_93 ++ ] = V_133 ;
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_134 ;
V_3 -> V_135 = V_136 ;
V_3 -> V_135 . V_137 = F_58 ;
V_3 -> V_135 . V_138 = F_59 ;
V_3 -> V_38 = 0 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x18 ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_3 -> V_135 = V_136 ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_139 ;
unsigned int V_44 ;
int V_140 = 0 ;
if ( ( V_4 -> V_7 != V_26 ) &&
( V_3 -> V_17 != 0x11064397 ) )
V_140 = 1 ;
V_139 =
( F_17 ( V_3 , 0x17 , 0 , V_141 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x1a , & V_44 ) ;
F_20 ( V_3 , 0x1b , & V_44 ) ;
F_20 ( V_3 , 0x1e , & V_44 ) ;
if ( V_139 )
V_44 = V_50 ;
F_14 ( V_3 , 0x17 , V_44 ) ;
F_14 ( V_3 , 0x13 , V_44 ) ;
F_14 ( V_3 , 0x14 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x19 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_44 ) ;
F_14 ( V_3 , 0x18 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
if ( V_140 ) {
V_44 = V_65 ;
F_20 ( V_3 , 0x22 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_44 ) ;
F_14 ( V_3 , 0x26 , V_44 ) ;
F_14 ( V_3 , 0x24 , V_44 ) ;
} else if ( V_3 -> V_17 == 0x11064397 ) {
V_44 = V_65 ;
F_20 ( V_3 , 0x23 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_44 ) ;
F_14 ( V_3 , 0x27 , V_44 ) ;
F_14 ( V_3 , 0x25 , V_44 ) ;
}
V_44 = V_65 ;
F_20 ( V_3 , 0x1c , & V_44 ) ;
F_20 ( V_3 , 0x1d , & V_44 ) ;
if ( V_140 )
F_20 ( V_3 , 0x23 , & V_44 ) ;
F_14 ( V_3 , 0x16 , V_139 ? V_50 : V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
if ( V_140 ) {
F_14 ( V_3 , 0x25 , V_44 ) ;
F_14 ( V_3 , 0x27 , V_44 ) ;
} else if ( V_3 -> V_17 == 0x11064397 && V_4 -> V_6 . V_142 )
F_14 ( V_3 , 0x25 , V_44 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
if ( F_4 ( V_3 ) == V_8 )
return F_65 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x16 ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_63 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 , T_3 V_53 ,
int V_143 , int V_144 , int V_145 )
{
F_67 ( V_3 , V_53 ,
F_68 ( V_3 , V_53 ) | V_146 ) ;
F_69 ( V_3 , V_53 , V_147 ,
( V_143 << V_148 ) |
( V_144 << V_149 ) |
( V_145 << V_150 ) |
( 0 << V_151 ) ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x16 ;
F_66 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 ) {
F_70 ( V_3 -> V_152 ) ;
V_3 -> V_152 = F_71 ( L_1 , V_5 ) ;
snprintf ( V_3 -> V_41 -> V_153 -> V_154 ,
sizeof( V_3 -> V_41 -> V_153 -> V_154 ) ,
L_2 , V_3 -> V_155 , V_3 -> V_152 ) ;
}
if ( V_3 -> V_17 == 0x11064397 ) {
F_70 ( V_3 -> V_152 ) ;
V_3 -> V_152 = F_71 ( L_3 , V_5 ) ;
snprintf ( V_3 -> V_41 -> V_153 -> V_154 ,
sizeof( V_3 -> V_41 -> V_153 -> V_154 ) ,
L_2 , V_3 -> V_155 , V_3 -> V_152 ) ;
}
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_156 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_63 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_139 =
F_17 ( V_3 , 0x13 , 0 , V_141 , 0x00 ) == 3 ;
unsigned int V_44 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x14 , & V_44 ) ;
F_20 ( V_3 , 0x15 , & V_44 ) ;
F_20 ( V_3 , 0x18 , & V_44 ) ;
if ( V_139 )
V_44 = V_50 ;
F_14 ( V_3 , 0x13 , V_44 ) ;
F_14 ( V_3 , 0x12 , V_44 ) ;
F_14 ( V_3 , 0x1f , V_44 ) ;
F_14 ( V_3 , 0x20 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x17 , & V_44 ) ;
F_20 ( V_3 , 0x16 , & V_44 ) ;
F_14 ( V_3 , 0x1a , V_139 ? V_50 : V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
F_14 ( V_3 , 0x1d , V_44 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x1a ;
F_69 ( V_3 , 0x1A , V_147 ,
( 0x17 << V_148 ) |
( 0x17 << V_149 ) |
( 0x5 << V_150 ) |
( 1 << V_151 ) ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_157 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_72 ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_139 ;
unsigned int V_44 , V_158 ;
V_139 =
F_17 ( V_3 , 0x1e , 0 , V_141 , 0x00 ) == 5 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x29 , & V_44 ) ;
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_20 ( V_3 , 0x2b , & V_44 ) ;
if ( V_139 )
V_44 = V_50 ;
F_14 ( V_3 , 0x1e , V_44 ) ;
F_14 ( V_3 , 0x1f , V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x27 , & V_44 ) ;
F_14 ( V_3 , 0x1a , V_44 ) ;
V_158 = V_44 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x26 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2b , & V_44 ) ;
F_14 ( V_3 , 0xa , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x24 , & V_44 ) ;
if ( ! V_4 -> V_6 . V_142 )
F_20 ( V_3 , 0x28 , & V_44 ) ;
F_14 ( V_3 , 0x8 , V_44 ) ;
if ( ! V_4 -> V_6 . V_142 && V_158 != V_65 )
V_44 = V_158 ;
F_14 ( V_3 , 0xb , V_44 ) ;
F_14 ( V_3 , 0x21 , V_139 ? V_50 : V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x25 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_14 ( V_3 , 0x9 , V_44 ) ;
if ( V_4 -> V_6 . V_142 ) {
V_44 = V_65 ;
F_20 ( V_3 , 0x28 , & V_44 ) ;
F_14 ( V_3 , 0x1b , V_44 ) ;
F_14 ( V_3 , 0x34 , V_44 ) ;
F_14 ( V_3 , 0xc , V_44 ) ;
}
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 , V_159 ;
T_3 V_160 [ 8 ] ;
T_3 V_43 ;
if ( ! V_4 -> V_6 . V_128 )
return 0 ;
V_159 = F_76 ( V_3 , V_4 -> V_6 . V_128 , V_160 ,
F_77 ( V_160 ) - 1 ) ;
for ( V_54 = 0 ; V_54 < V_159 ; V_54 ++ ) {
if ( F_78 ( F_68 ( V_3 , V_160 [ V_54 ] ) ) == V_161 )
return 0 ;
}
V_43 = V_3 -> V_162 ;
for ( V_54 = 0 ; V_54 < V_3 -> V_163 ; V_54 ++ , V_43 ++ ) {
unsigned int V_164 = F_68 ( V_3 , V_43 ) ;
if ( F_78 ( V_164 ) == V_161 &&
! ( V_164 & V_165 ) ) {
V_160 [ V_159 ++ ] = V_43 ;
return F_79 ( V_3 ,
V_4 -> V_6 . V_128 ,
V_159 , V_160 ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_75 ( V_3 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_166 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_74 ;
return 0 ;
}
static int F_81 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
V_69 -> type = V_167 ;
V_69 -> V_168 = 1 ;
V_69 -> V_72 . integer . V_169 = 0 ;
V_69 -> V_72 . integer . V_170 = 1 ;
return 0 ;
}
static int F_82 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
int V_46 = 0 ;
V_46 = F_17 ( V_3 , 0x26 , 0 ,
V_141 , 0 ) ;
if ( V_46 != - 1 )
* V_71 -> V_72 . integer . V_72 = V_46 ;
return 0 ;
}
static int F_83 ( struct V_66 * V_67 ,
struct V_70 * V_71 )
{
struct V_2 * V_3 = F_27 ( V_67 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_46 = * V_71 -> V_72 . integer . V_72 ;
F_7 ( V_3 , 0x26 , 0 ,
V_171 , V_46 ) ;
V_4 -> V_172 = V_46 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_139 ;
unsigned int V_44 ;
unsigned int V_173 , V_63 ;
V_139 =
( F_17 ( V_3 , 0x17 , 0 ,
V_141 , 0x00 ) == 5 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x1a , & V_44 ) ;
F_20 ( V_3 , 0x1b , & V_44 ) ;
F_20 ( V_3 , 0x1e , & V_44 ) ;
if ( V_139 )
V_44 = V_50 ;
F_14 ( V_3 , 0x17 , V_44 ) ;
F_14 ( V_3 , 0x13 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x1e , & V_44 ) ;
if ( V_4 -> V_172 )
F_20 ( V_3 , 0x22 , & V_44 ) ;
else
F_14 ( V_3 , 0x22 , V_65 ) ;
F_14 ( V_3 , 0x26 , V_44 ) ;
F_14 ( V_3 , 0x14 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x19 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_44 ) ;
F_14 ( V_3 , 0x18 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x23 , & V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_44 ) ;
F_14 ( V_3 , 0x27 , V_44 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1e , & V_44 ) ;
F_14 ( V_3 , 0x25 , V_44 ) ;
V_63 = F_22 ( V_3 , 0x1c ) ;
if ( V_63 )
V_173 = 0 ;
else {
V_63 = F_22 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_6 . V_142 && V_63 )
V_173 = 0 ;
else
V_173 = 1 ;
}
V_44 = V_173 ? V_50 : V_65 ;
F_14 ( V_3 , 0x28 , V_44 ) ;
F_14 ( V_3 , 0x29 , V_44 ) ;
F_14 ( V_3 , 0x2a , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x1c , & V_44 ) ;
F_20 ( V_3 , 0x1d , & V_44 ) ;
if ( V_4 -> V_6 . V_142 )
F_14 ( V_3 , 0x25 , V_44 ) ;
F_14 ( V_3 , 0x16 , V_139 ? V_50 : V_44 ) ;
F_14 ( V_3 , 0x10 , V_173 ? V_50 : V_44 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x16 ;
F_66 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_174 ;
V_4 -> V_92 [ V_4 -> V_93 ++ ] = V_175 ;
V_4 -> V_92 [ V_4 -> V_93 ++ ] = V_176 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_84 ;
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_139 ;
unsigned int V_44 ;
unsigned int V_63 ;
V_139 =
F_17 ( V_3 , 0x1e , 0 , V_141 , 0x00 ) == 3 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x29 , & V_44 ) ;
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_20 ( V_3 , 0x2b , & V_44 ) ;
V_44 = V_50 ;
F_14 ( V_3 , 0x1e , V_44 ) ;
F_14 ( V_3 , 0x1f , V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
F_14 ( V_3 , 0x8 , V_44 ) ;
if ( V_4 -> V_7 == V_32 ) {
V_44 = V_65 ;
F_20 ( V_3 , 0x28 , & V_44 ) ;
F_14 ( V_3 , 0x18 , V_44 ) ;
F_14 ( V_3 , 0x38 , V_44 ) ;
} else {
V_44 = V_65 ;
F_20 ( V_3 , 0x26 , & V_44 ) ;
F_14 ( V_3 , 0x1c , V_44 ) ;
F_14 ( V_3 , 0x37 , V_44 ) ;
}
if ( V_4 -> V_7 == V_32 ) {
V_44 = V_65 ;
F_20 ( V_3 , 0x25 , & V_44 ) ;
F_14 ( V_3 , 0x15 , V_44 ) ;
F_14 ( V_3 , 0x35 , V_44 ) ;
} else {
V_44 = V_65 ;
F_20 ( V_3 , 0x25 , & V_44 ) ;
F_14 ( V_3 , 0x19 , V_44 ) ;
F_14 ( V_3 , 0x35 , V_44 ) ;
}
if ( V_4 -> V_6 . V_142 )
F_14 ( V_3 , 0x9 , V_50 ) ;
V_63 = F_22 ( V_3 , 0x25 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x24 , & V_44 ) ;
V_44 = V_63 ? V_65 : V_50 ;
if ( V_4 -> V_7 == V_32 )
F_14 ( V_3 , 0x14 , V_44 ) ;
else
F_14 ( V_3 , 0x18 , V_44 ) ;
F_14 ( V_3 , 0x34 , V_44 ) ;
V_63 = F_22 ( V_3 , 0x26 ) ;
V_44 = V_63 ? V_65 : V_50 ;
if ( V_4 -> V_7 == V_32 ) {
F_14 ( V_3 , 0x33 , V_44 ) ;
F_14 ( V_3 , 0x1c , V_44 ) ;
F_14 ( V_3 , 0x3c , V_44 ) ;
} else {
F_14 ( V_3 , 0x31 , V_44 ) ;
F_14 ( V_3 , 0x17 , V_44 ) ;
F_14 ( V_3 , 0x3b , V_44 ) ;
}
if ( V_139 || ! F_30 ( V_3 ) )
F_14 ( V_3 , 0x21 , V_50 ) ;
else
F_14 ( V_3 , 0x21 , V_65 ) ;
}
static void F_87 ( struct V_2 * V_3 ,
const struct V_177 * V_178 , int V_99 )
{
if ( V_99 == V_179 )
F_66 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_88 ( struct V_2 * V_3 )
{
static T_3 V_180 [] = { 0x14 , 0x1c } ;
static T_3 V_181 [] = { 0x1c } ;
F_79 ( V_3 , 0x24 , F_77 ( V_180 ) , V_180 ) ;
F_79 ( V_3 , 0x33 , F_77 ( V_181 ) , V_181 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_32 )
F_88 ( V_3 ) ;
F_75 ( V_3 ) ;
F_90 ( V_3 , NULL , V_182 , V_183 ) ;
F_91 ( V_3 , V_179 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
if ( V_4 -> V_7 == V_32 )
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_184 ;
else
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_185 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_86 ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 ;
unsigned int V_63 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x29 , & V_44 ) ;
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_20 ( V_3 , 0x2b , & V_44 ) ;
V_44 = V_50 ;
F_14 ( V_3 , 0x1e , V_44 ) ;
F_14 ( V_3 , 0x1f , V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
F_14 ( V_3 , 0x8 , V_50 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x28 , & V_44 ) ;
F_14 ( V_3 , 0x18 , V_44 ) ;
F_14 ( V_3 , 0x38 , V_44 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x25 , & V_44 ) ;
F_14 ( V_3 , 0x15 , V_44 ) ;
F_14 ( V_3 , 0x35 , V_44 ) ;
if ( V_4 -> V_6 . V_142 )
F_14 ( V_3 , 0x9 , V_50 ) ;
V_63 = F_22 ( V_3 , 0x25 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x24 , & V_44 ) ;
if ( V_63 ) {
F_14 ( V_3 , 0x14 , V_65 ) ;
F_14 ( V_3 , 0x34 , V_65 ) ;
} else {
F_14 ( V_3 , 0x14 , V_50 ) ;
F_14 ( V_3 , 0x34 , V_50 ) ;
}
V_63 = F_22 ( V_3 , 0x28 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x31 , & V_44 ) ;
if ( V_63 ) {
F_14 ( V_3 , 0x1c , V_65 ) ;
F_14 ( V_3 , 0x3c , V_65 ) ;
F_14 ( V_3 , 0x3e , V_65 ) ;
} else {
F_14 ( V_3 , 0x1c , V_50 ) ;
F_14 ( V_3 , 0x3c , V_50 ) ;
F_14 ( V_3 , 0x3e , V_50 ) ;
}
V_44 = V_65 ;
F_20 ( V_3 , 0x33 , & V_44 ) ;
F_14 ( V_3 , 0x1d , V_44 ) ;
F_14 ( V_3 , 0x3d , V_44 ) ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x21 ;
F_66 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_66 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_75 ( V_3 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_186 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_92 ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_139 ;
unsigned int V_44 , V_158 ;
V_139 =
F_17 ( V_3 , 0x1e , 0 , V_141 , 0x00 ) == 4 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x29 , & V_44 ) ;
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_20 ( V_3 , 0x2b , & V_44 ) ;
if ( V_139 )
V_44 = V_50 ;
F_14 ( V_3 , 0x1e , V_44 ) ;
F_14 ( V_3 , 0x1f , V_44 ) ;
F_14 ( V_3 , 0x10 , V_44 ) ;
F_14 ( V_3 , 0x11 , V_44 ) ;
if ( V_4 -> V_7 == V_33 ) {
V_44 = V_65 ;
F_14 ( V_3 , 0x27 , V_44 ) ;
F_14 ( V_3 , 0x37 , V_44 ) ;
} else {
V_44 = V_65 ;
F_20 ( V_3 , 0x27 , & V_44 ) ;
F_14 ( V_3 , 0x37 , V_44 ) ;
}
V_44 = V_65 ;
F_20 ( V_3 , 0x26 , & V_44 ) ;
F_14 ( V_3 , 0x36 , V_44 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2b , & V_44 ) ;
F_14 ( V_3 , 0x3b , V_44 ) ;
F_14 ( V_3 , 0x1b , V_44 ) ;
}
F_16 ( V_3 , 0xa , V_44 , 2 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x25 , & V_44 ) ;
F_14 ( V_3 , 0x35 , V_44 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2a , & V_44 ) ;
F_14 ( V_3 , 0x3a , V_44 ) ;
F_14 ( V_3 , 0x1a , V_44 ) ;
}
F_16 ( V_3 , 0x9 , V_44 , 1 ) ;
V_44 = V_65 ;
F_20 ( V_3 , 0x28 , & V_44 ) ;
F_14 ( V_3 , 0x38 , V_44 ) ;
F_14 ( V_3 , 0x18 , V_44 ) ;
if ( V_4 -> V_6 . V_142 )
F_16 ( V_3 , 0xb , V_44 , 3 ) ;
V_158 = V_44 ;
V_44 = V_65 ;
F_20 ( V_3 , 0x24 , & V_44 ) ;
F_14 ( V_3 , 0x34 , V_44 ) ;
if ( ! V_4 -> V_6 . V_142 && V_158 != V_65 )
V_44 = V_158 ;
F_16 ( V_3 , 0x8 , V_44 , 0 ) ;
F_14 ( V_3 , 0x3f , V_139 ? V_50 : V_44 ) ;
}
static int F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_91 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_127 ;
V_4 -> V_6 . V_128 = 0x3f ;
F_75 ( V_3 ) ;
V_91 = F_52 ( V_3 ) ;
if ( V_91 < 0 ) {
F_36 ( V_3 ) ;
return V_91 ;
}
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_187 ;
V_3 -> V_135 = V_136 ;
V_4 -> F_13 = F_94 ;
return 0 ;
}
static int T_4 F_96 ( void )
{
return F_97 ( & V_188 ) ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_188 ) ;
}
