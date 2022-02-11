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
V_4 -> V_6 . V_12 = V_13 ;
return V_4 ;
}
static enum V_14 F_4 ( struct V_2 * V_3 )
{
T_1 V_15 = V_3 -> V_15 ;
T_2 V_16 = V_15 >> 16 ;
T_2 V_17 = V_15 & 0xffff ;
enum V_14 V_7 ;
if ( V_16 != 0x1106 )
V_7 = V_18 ;
else if ( V_17 >= 0x1708 && V_17 <= 0x170b )
V_7 = V_19 ;
else if ( V_17 >= 0xe710 && V_17 <= 0xe713 )
V_7 = V_20 ;
else if ( V_17 >= 0xe714 && V_17 <= 0xe717 )
V_7 = V_21 ;
else if ( V_17 >= 0xe720 && V_17 <= 0xe723 ) {
V_7 = V_22 ;
if ( F_5 ( V_3 , 0x16 , V_23 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_17 >= 0xe724 && V_17 <= 0xe727 )
V_7 = V_24 ;
else if ( ( V_17 & 0xfff ) == 0x397
&& ( V_17 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_17 & 0xfff ) == 0x398
&& ( V_17 >> 12 ) < 8 )
V_7 = V_25 ;
else if ( ( V_17 & 0xfff ) == 0x428
&& ( V_17 >> 12 ) < 8 )
V_7 = V_26 ;
else if ( V_17 == 0x0433 || V_17 == 0xa721 )
V_7 = V_27 ;
else if ( V_17 == 0x0441 || V_17 == 0x4441 )
V_7 = V_26 ;
else if ( V_17 == 0x0438 || V_17 == 0x4438 )
V_7 = V_28 ;
else if ( V_17 == 0x0448 )
V_7 = V_29 ;
else if ( V_17 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_17 & 0xfff ) == 0x446 )
V_7 = V_30 ;
else if ( V_17 == 0x4760 )
V_7 = V_31 ;
else if ( V_17 == 0x4761 || V_17 == 0x4762 )
V_7 = V_32 ;
else
V_7 = V_18 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_19 || ! V_4 -> V_6 . V_33 . V_34 )
return;
if ( V_4 -> V_35 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
F_8 ( & V_3 -> V_36 ) ;
V_4 -> V_35 = false ;
V_3 -> V_37 = 0 ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_19 || ! V_4 -> V_6 . V_33 . V_34 )
return;
if ( V_4 -> V_38 ) {
if ( ! V_4 -> V_35 ) {
V_3 -> V_37 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( V_3 -> V_39 -> V_40 ,
& V_3 -> V_36 , 0 ) ;
V_4 -> V_35 = true ;
}
} else if ( ! F_12 ( V_3 ) )
F_6 ( V_3 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_13 )
V_4 -> F_13 ( V_3 ) ;
}
static void F_14 ( struct V_2 * V_3 , T_3 V_41 ,
unsigned int V_42 )
{
if ( F_15 ( V_3 , V_41 , V_42 ) )
return;
F_7 ( V_3 , V_41 , 0 , V_43 , V_42 ) ;
}
static void F_16 ( struct V_2 * V_3 , T_3 V_41 ,
unsigned int V_42 , unsigned int V_44 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_45 ;
if ( F_15 ( V_3 , V_41 , V_42 ) )
return;
V_45 = F_17 ( V_3 , V_41 , 0 , V_46 , 0 ) ;
if ( V_45 && ( V_4 -> V_47 [ V_44 ] != V_45 ) )
V_4 -> V_47 [ V_44 ] = V_45 ;
F_7 ( V_3 , V_41 , 0 , V_43 , V_42 ) ;
if ( V_42 == V_48 ) {
V_45 = F_17 ( V_3 , V_41 , 0 , V_46 , 0 ) ;
if ( ! V_45 && ( V_4 -> V_47 [ V_44 ] != V_45 ) )
F_7 ( V_3 , V_41 , 0 ,
V_49 ,
V_4 -> V_47 [ V_44 ] ) ;
}
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return V_4 -> V_6 . V_50 > 2 ;
}
static bool F_19 ( struct V_2 * V_3 , T_3 V_51 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_6 . V_53 ; V_52 ++ )
if ( V_4 -> V_6 . V_54 [ V_52 ] . V_51 == V_51 )
return true ;
return false ;
}
static void F_20 ( struct V_2 * V_3 , T_3 V_41 ,
unsigned int * V_55 )
{
unsigned V_42 ;
unsigned V_56 = F_21 ( V_3 , V_41 ) ;
unsigned V_57 = ( V_56 & V_58 )
>> V_59
& V_60 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_61 = 0 ;
V_57 |= V_4 -> V_10 ;
if ( ! V_57 )
V_61 = F_22 ( V_3 , V_41 ) ;
if ( ( F_18 ( V_3 ) && F_19 ( V_3 , V_41 ) )
|| ( ( V_57 || V_61 )
&& F_23 ( V_56 ) != V_62 ) ) {
* V_55 = V_48 ;
V_42 = V_48 ;
} else
V_42 = V_63 ;
F_14 ( V_3 , V_41 , V_42 ) ;
}
static int F_24 ( struct V_64 * V_65 ,
struct V_66 * V_67 )
{
return F_25 ( V_65 , V_67 ) ;
}
static int F_26 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_69 -> V_70 . V_71 . V_72 [ 0 ] = ! V_4 -> V_10 ;
return 0 ;
}
static int F_28 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_73 = ! V_69 -> V_70 . V_71 . V_72 [ 0 ] ;
if ( V_73 == V_4 -> V_10 )
return 0 ;
V_4 -> V_10 = V_73 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
return 1 ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_74 * V_75 ;
int V_76 , V_77 ;
V_75 = V_4 -> V_6 . V_78 . V_79 ;
if ( ! V_75 )
return true ;
for (; V_75 -> V_41 ; V_75 ++ ) {
for ( V_76 = 0 ; V_76 < 2 ; V_76 ++ ) {
V_77 = F_31 ( V_3 , V_75 -> V_41 , V_76 , V_75 -> V_80 ,
V_75 -> V_81 ) ;
if ( ! ( V_77 & V_82 ) && V_77 > 0 )
return false ;
}
}
return true ;
}
static void F_32 ( struct V_2 * V_3 , bool V_83 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_84 ;
unsigned int V_85 , V_42 ;
if ( V_4 -> V_10 )
V_84 = false ;
else
V_84 = F_30 ( V_3 ) && ! V_4 -> V_6 . V_86 ;
if ( V_84 == V_4 -> V_87 && ! V_83 )
return;
V_4 -> V_87 = V_84 ;
switch ( V_4 -> V_7 ) {
case V_22 :
case V_24 :
V_85 = 0xf70 ;
V_42 = V_84 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_26 :
case V_27 :
V_85 = 0xf73 ;
V_42 = V_84 ? 0x51 : 0xe1 ;
break;
case V_25 :
V_85 = 0xf73 ;
V_42 = V_84 ? 0x01 : 0x1d ;
break;
case V_28 :
case V_29 :
case V_30 :
V_85 = 0xf93 ;
V_42 = V_84 ? 0x00 : 0xe0 ;
break;
case V_31 :
case V_32 :
V_85 = 0xf82 ;
V_42 = V_84 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_88 , 0 , V_85 , V_42 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , false ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_89 , V_52 ;
V_89 = F_34 ( V_3 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_4 -> F_13 )
V_4 -> V_90 [ V_4 -> V_91 ++ ] = V_92 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_91 ; V_52 ++ ) {
V_89 = F_35 ( V_3 , V_4 -> V_90 [ V_52 ] ) ;
if ( V_89 < 0 )
return V_89 ;
}
return 0 ;
}
static void V_13 ( struct V_93 * V_94 ,
struct V_2 * V_3 ,
struct V_95 * V_96 ,
int V_97 )
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
if ( V_4 -> V_7 == V_30 ) {
int V_52 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_6 . V_33 . V_34 ; V_52 ++ )
F_40 ( V_3 , V_4 -> V_6 . V_33 . V_98 [ V_52 ] , 0 ) ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_3 V_41 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_13 ( V_3 ) ;
F_29 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_42 ( V_3 , & V_4 -> V_6 . V_78 , V_41 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_3 V_41 )
{
unsigned int V_56 ;
unsigned char V_99 ;
V_56 = F_21 ( V_3 , V_41 ) ;
V_99 = ( unsigned char ) F_44 ( V_56 ) ;
V_99 = ( V_99 << 4 ) | F_45 ( V_56 ) ;
if ( F_23 ( V_56 ) == V_62
&& ( V_99 == 0xf0 || V_99 == 0xff ) ) {
V_56 = V_56 & ( ~ ( V_100 << 30 ) ) ;
F_46 ( V_3 , V_41 , V_56 ) ;
}
return;
}
static int F_47 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_19 )
return 0 ;
V_69 -> V_70 . integer . V_70 [ 0 ] = V_4 -> V_38 ;
return 0 ;
}
static int F_48 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_73 ;
if ( V_4 -> V_7 != V_19 )
return 0 ;
V_73 = ! ! V_69 -> V_70 . integer . V_70 [ 0 ] ;
if ( V_4 -> V_38 == V_73 )
return 0 ;
V_4 -> V_38 = V_73 ;
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
struct V_103 * V_104 = & V_4 -> V_6 . V_33 ;
T_3 V_51 ;
int V_52 ;
V_4 -> V_6 . V_105 = F_49 ;
if ( V_104 -> V_106 [ 0 ] )
V_4 -> V_6 . V_107 = F_51 ;
for ( V_52 = 0 ; V_52 < V_104 -> V_108 ; V_52 ++ ) {
V_51 = V_104 -> V_109 [ V_52 ] ;
if ( V_51 && ! F_55 ( V_3 , V_51 ) &&
F_56 ( V_3 , V_51 ) )
F_57 ( V_3 , V_51 ,
V_110 ,
F_53 ) ;
}
for ( V_52 = 0 ; V_52 < V_104 -> V_111 ; V_52 ++ ) {
V_51 = V_104 -> V_109 [ V_52 ] ;
if ( V_51 && ! F_55 ( V_3 , V_51 ) &&
F_56 ( V_3 , V_51 ) )
F_57 ( V_3 , V_51 ,
V_110 ,
F_53 ) ;
}
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_89 ;
V_89 = F_59 ( V_3 , & V_4 -> V_6 . V_33 , NULL , 0 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_60 ( V_3 , & V_4 -> V_6 . V_33 ) ;
if ( V_89 < 0 )
return V_89 ;
F_54 ( V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_112 ; V_52 ++ )
F_62 ( V_3 , V_4 -> V_113 [ V_52 ] ) ;
F_13 ( V_3 ) ;
F_32 ( V_3 , true ) ;
F_63 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
int V_89 ;
int V_114 = V_3 -> V_37 ;
V_3 -> V_37 = F_10 ( 100 ) ;
V_89 = F_33 ( V_3 ) ;
V_3 -> V_37 = V_114 ;
return V_89 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_52 , V_89 ;
V_89 = F_66 ( V_3 ) ;
if ( V_89 < 0 || V_3 -> V_15 != 0x11061708 )
return V_89 ;
for ( V_52 = 0 ; V_52 < V_3 -> V_115 ; V_52 ++ ) {
struct V_116 * V_117 = & V_4 -> V_6 . V_118 [ V_52 ] ;
if ( ! V_117 -> V_119 [ V_120 ] . V_121 ||
V_117 -> V_122 != V_123 )
continue;
V_117 -> V_119 [ V_120 ] . V_124 =
V_125 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x17 ;
V_3 -> V_37 = F_10 ( 100 ) ;
V_4 -> V_38 = 1 ;
V_4 -> V_6 . V_128 = 1 ;
F_43 ( V_3 , V_129 ) ;
F_43 ( V_3 , V_130 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_90 [ V_4 -> V_91 ++ ] = V_131 ;
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_132 ;
V_3 -> V_133 = V_134 ;
V_3 -> V_133 . V_135 = F_64 ;
V_3 -> V_133 . V_136 = F_65 ;
V_3 -> V_37 = 0 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x18 ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_3 -> V_133 = V_134 ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_137 ;
unsigned int V_42 ;
int V_138 = 0 ;
if ( ( V_4 -> V_7 != V_24 ) &&
( V_3 -> V_15 != 0x11064397 ) )
V_138 = 1 ;
V_137 =
( F_17 ( V_3 , 0x17 , 0 , V_139 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x1a , & V_42 ) ;
F_20 ( V_3 , 0x1b , & V_42 ) ;
F_20 ( V_3 , 0x1e , & V_42 ) ;
if ( V_137 )
V_42 = V_48 ;
F_14 ( V_3 , 0x17 , V_42 ) ;
F_14 ( V_3 , 0x13 , V_42 ) ;
F_14 ( V_3 , 0x14 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x19 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_42 ) ;
F_14 ( V_3 , 0x18 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
if ( V_138 ) {
V_42 = V_63 ;
F_20 ( V_3 , 0x22 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_42 ) ;
F_14 ( V_3 , 0x26 , V_42 ) ;
F_14 ( V_3 , 0x24 , V_42 ) ;
} else if ( V_3 -> V_15 == 0x11064397 ) {
V_42 = V_63 ;
F_20 ( V_3 , 0x23 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_42 ) ;
F_14 ( V_3 , 0x27 , V_42 ) ;
F_14 ( V_3 , 0x25 , V_42 ) ;
}
V_42 = V_63 ;
F_20 ( V_3 , 0x1c , & V_42 ) ;
F_20 ( V_3 , 0x1d , & V_42 ) ;
if ( V_138 )
F_20 ( V_3 , 0x23 , & V_42 ) ;
F_14 ( V_3 , 0x16 , V_137 ? V_48 : V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
if ( V_138 ) {
F_14 ( V_3 , 0x25 , V_42 ) ;
F_14 ( V_3 , 0x27 , V_42 ) ;
} else if ( V_3 -> V_15 == 0x11064397 && V_4 -> V_6 . V_140 )
F_14 ( V_3 , 0x25 , V_42 ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
if ( F_4 ( V_3 ) == V_8 )
return F_71 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x16 ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_69 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 , T_3 V_51 ,
int V_141 , int V_142 , int V_143 )
{
F_73 ( V_3 , V_51 , V_144 ,
( V_141 << V_145 ) |
( V_142 << V_146 ) |
( V_143 << V_147 ) |
( 0 << V_148 ) ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x16 ;
F_72 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 ) {
F_38 ( V_3 -> V_149 ) ;
V_3 -> V_149 = F_74 ( L_1 , V_5 ) ;
snprintf ( V_3 -> V_39 -> V_150 -> V_151 ,
sizeof( V_3 -> V_39 -> V_150 -> V_151 ) ,
L_2 , V_3 -> V_152 , V_3 -> V_149 ) ;
}
if ( V_3 -> V_15 == 0x11064397 ) {
F_38 ( V_3 -> V_149 ) ;
V_3 -> V_149 = F_74 ( L_3 , V_5 ) ;
snprintf ( V_3 -> V_39 -> V_150 -> V_151 ,
sizeof( V_3 -> V_39 -> V_150 -> V_151 ) ,
L_2 , V_3 -> V_152 , V_3 -> V_149 ) ;
}
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_153 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_69 ;
return 0 ;
}
static void F_75 ( struct V_2 * V_3 )
{
int V_137 =
F_17 ( V_3 , 0x13 , 0 , V_139 , 0x00 ) == 3 ;
unsigned int V_42 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x14 , & V_42 ) ;
F_20 ( V_3 , 0x15 , & V_42 ) ;
F_20 ( V_3 , 0x18 , & V_42 ) ;
if ( V_137 )
V_42 = V_48 ;
F_14 ( V_3 , 0x13 , V_42 ) ;
F_14 ( V_3 , 0x12 , V_42 ) ;
F_14 ( V_3 , 0x1f , V_42 ) ;
F_14 ( V_3 , 0x20 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x17 , & V_42 ) ;
F_20 ( V_3 , 0x16 , & V_42 ) ;
F_14 ( V_3 , 0x1a , V_137 ? V_48 : V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
F_14 ( V_3 , 0x1d , V_42 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x1a ;
F_73 ( V_3 , 0x1A , V_144 ,
( 0x17 << V_145 ) |
( 0x17 << V_146 ) |
( 0x5 << V_147 ) |
( 1 << V_148 ) ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_154 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_75 ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_137 ;
unsigned int V_42 , V_155 ;
V_137 =
F_17 ( V_3 , 0x1e , 0 , V_139 , 0x00 ) == 5 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x29 , & V_42 ) ;
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_20 ( V_3 , 0x2b , & V_42 ) ;
if ( V_137 )
V_42 = V_48 ;
F_14 ( V_3 , 0x1e , V_42 ) ;
F_14 ( V_3 , 0x1f , V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x27 , & V_42 ) ;
F_14 ( V_3 , 0x1a , V_42 ) ;
V_155 = V_42 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x26 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2b , & V_42 ) ;
F_14 ( V_3 , 0xa , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x24 , & V_42 ) ;
if ( ! V_4 -> V_6 . V_140 )
F_20 ( V_3 , 0x28 , & V_42 ) ;
F_14 ( V_3 , 0x8 , V_42 ) ;
if ( ! V_4 -> V_6 . V_140 && V_155 != V_63 )
V_42 = V_155 ;
F_14 ( V_3 , 0xb , V_42 ) ;
F_14 ( V_3 , 0x21 , V_137 ? V_48 : V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x25 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_14 ( V_3 , 0x9 , V_42 ) ;
if ( V_4 -> V_6 . V_140 ) {
V_42 = V_63 ;
F_20 ( V_3 , 0x28 , & V_42 ) ;
F_14 ( V_3 , 0x1b , V_42 ) ;
F_14 ( V_3 , 0x34 , V_42 ) ;
F_14 ( V_3 , 0xc , V_42 ) ;
}
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_52 , V_156 ;
T_3 V_157 [ 8 ] ;
T_3 V_41 ;
if ( ! V_4 -> V_6 . V_127 )
return 0 ;
V_156 = F_79 ( V_3 , V_4 -> V_6 . V_127 , V_157 ,
F_80 ( V_157 ) - 1 ) ;
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ ) {
if ( F_81 ( F_82 ( V_3 , V_157 [ V_52 ] ) ) == V_158 )
return 0 ;
}
V_41 = V_3 -> V_159 ;
for ( V_52 = 0 ; V_52 < V_3 -> V_160 ; V_52 ++ , V_41 ++ ) {
unsigned int V_161 = F_82 ( V_3 , V_41 ) ;
if ( F_81 ( V_161 ) == V_158 &&
! ( V_161 & V_162 ) ) {
V_157 [ V_156 ++ ] = V_41 ;
return F_83 ( V_3 ,
V_4 -> V_6 . V_127 ,
V_156 , V_157 ) ;
}
}
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_78 ( V_3 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_163 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_77 ;
return 0 ;
}
static int F_85 ( struct V_64 * V_65 ,
struct V_66 * V_67 )
{
V_67 -> type = V_164 ;
V_67 -> V_165 = 1 ;
V_67 -> V_70 . integer . V_166 = 0 ;
V_67 -> V_70 . integer . V_167 = 1 ;
return 0 ;
}
static int F_86 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
int V_44 = 0 ;
V_44 = F_17 ( V_3 , 0x26 , 0 ,
V_139 , 0 ) ;
if ( V_44 != - 1 )
* V_69 -> V_70 . integer . V_70 = V_44 ;
return 0 ;
}
static int F_87 ( struct V_64 * V_65 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_27 ( V_65 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 = * V_69 -> V_70 . integer . V_70 ;
F_7 ( V_3 , 0x26 , 0 ,
V_168 , V_44 ) ;
V_4 -> V_169 = V_44 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_137 ;
unsigned int V_42 ;
unsigned int V_170 , V_61 ;
V_137 =
( F_17 ( V_3 , 0x17 , 0 ,
V_139 , 0x00 ) == 5 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x1a , & V_42 ) ;
F_20 ( V_3 , 0x1b , & V_42 ) ;
F_20 ( V_3 , 0x1e , & V_42 ) ;
if ( V_137 )
V_42 = V_48 ;
F_14 ( V_3 , 0x17 , V_42 ) ;
F_14 ( V_3 , 0x13 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x1e , & V_42 ) ;
if ( V_4 -> V_169 )
F_20 ( V_3 , 0x22 , & V_42 ) ;
else
F_14 ( V_3 , 0x22 , V_63 ) ;
F_14 ( V_3 , 0x26 , V_42 ) ;
F_14 ( V_3 , 0x14 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x19 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1b , & V_42 ) ;
F_14 ( V_3 , 0x18 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x23 , & V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1a , & V_42 ) ;
F_14 ( V_3 , 0x27 , V_42 ) ;
if ( F_18 ( V_3 ) )
F_20 ( V_3 , 0x1e , & V_42 ) ;
F_14 ( V_3 , 0x25 , V_42 ) ;
V_61 = F_22 ( V_3 , 0x1c ) ;
if ( V_61 )
V_170 = 0 ;
else {
V_61 = F_22 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_6 . V_140 && V_61 )
V_170 = 0 ;
else
V_170 = 1 ;
}
V_42 = V_170 ? V_48 : V_63 ;
F_14 ( V_3 , 0x28 , V_42 ) ;
F_14 ( V_3 , 0x29 , V_42 ) ;
F_14 ( V_3 , 0x2a , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x1c , & V_42 ) ;
F_20 ( V_3 , 0x1d , & V_42 ) ;
if ( V_4 -> V_6 . V_140 )
F_14 ( V_3 , 0x25 , V_42 ) ;
F_14 ( V_3 , 0x16 , V_137 ? V_48 : V_42 ) ;
F_14 ( V_3 , 0x10 , V_170 ? V_48 : V_42 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x16 ;
F_72 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_171 ;
V_4 -> V_90 [ V_4 -> V_91 ++ ] = V_172 ;
V_4 -> V_90 [ V_4 -> V_91 ++ ] = V_173 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_88 ;
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_137 ;
unsigned int V_42 ;
unsigned int V_61 ;
V_137 =
F_17 ( V_3 , 0x1e , 0 , V_139 , 0x00 ) == 3 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x29 , & V_42 ) ;
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_20 ( V_3 , 0x2b , & V_42 ) ;
V_42 = V_48 ;
F_14 ( V_3 , 0x1e , V_42 ) ;
F_14 ( V_3 , 0x1f , V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
F_14 ( V_3 , 0x8 , V_42 ) ;
if ( V_4 -> V_7 == V_30 ) {
V_42 = V_63 ;
F_20 ( V_3 , 0x28 , & V_42 ) ;
F_14 ( V_3 , 0x18 , V_42 ) ;
F_14 ( V_3 , 0x38 , V_42 ) ;
} else {
V_42 = V_63 ;
F_20 ( V_3 , 0x26 , & V_42 ) ;
F_14 ( V_3 , 0x1c , V_42 ) ;
F_14 ( V_3 , 0x37 , V_42 ) ;
}
if ( V_4 -> V_7 == V_30 ) {
V_42 = V_63 ;
F_20 ( V_3 , 0x25 , & V_42 ) ;
F_14 ( V_3 , 0x15 , V_42 ) ;
F_14 ( V_3 , 0x35 , V_42 ) ;
} else {
V_42 = V_63 ;
F_20 ( V_3 , 0x25 , & V_42 ) ;
F_14 ( V_3 , 0x19 , V_42 ) ;
F_14 ( V_3 , 0x35 , V_42 ) ;
}
if ( V_4 -> V_6 . V_140 )
F_14 ( V_3 , 0x9 , V_48 ) ;
V_61 = F_22 ( V_3 , 0x25 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x24 , & V_42 ) ;
V_42 = V_61 ? V_63 : V_48 ;
if ( V_4 -> V_7 == V_30 )
F_14 ( V_3 , 0x14 , V_42 ) ;
else
F_14 ( V_3 , 0x18 , V_42 ) ;
F_14 ( V_3 , 0x34 , V_42 ) ;
V_61 = F_22 ( V_3 , 0x26 ) ;
V_42 = V_61 ? V_63 : V_48 ;
if ( V_4 -> V_7 == V_30 ) {
F_14 ( V_3 , 0x33 , V_42 ) ;
F_14 ( V_3 , 0x1c , V_42 ) ;
F_14 ( V_3 , 0x3c , V_42 ) ;
} else {
F_14 ( V_3 , 0x31 , V_42 ) ;
F_14 ( V_3 , 0x17 , V_42 ) ;
F_14 ( V_3 , 0x3b , V_42 ) ;
}
if ( V_137 || ! F_30 ( V_3 ) )
F_14 ( V_3 , 0x21 , V_48 ) ;
else
F_14 ( V_3 , 0x21 , V_63 ) ;
}
static void F_91 ( struct V_2 * V_3 ,
const struct V_174 * V_175 , int V_97 )
{
if ( V_97 == V_176 )
F_72 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_92 ( struct V_2 * V_3 )
{
static T_3 V_177 [] = { 0x14 , 0x1c } ;
static T_3 V_178 [] = { 0x1c } ;
F_83 ( V_3 , 0x24 , F_80 ( V_177 ) , V_177 ) ;
F_83 ( V_3 , 0x33 , F_80 ( V_178 ) , V_178 ) ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_30 )
F_92 ( V_3 ) ;
F_78 ( V_3 ) ;
F_94 ( V_3 , NULL , V_179 , V_180 ) ;
F_95 ( V_3 , V_176 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
if ( V_4 -> V_7 == V_30 )
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_181 ;
else
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_182 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_90 ;
return 0 ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_42 ;
unsigned int V_61 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x29 , & V_42 ) ;
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_20 ( V_3 , 0x2b , & V_42 ) ;
V_42 = V_48 ;
F_14 ( V_3 , 0x1e , V_42 ) ;
F_14 ( V_3 , 0x1f , V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
F_14 ( V_3 , 0x8 , V_48 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x28 , & V_42 ) ;
F_14 ( V_3 , 0x18 , V_42 ) ;
F_14 ( V_3 , 0x38 , V_42 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x25 , & V_42 ) ;
F_14 ( V_3 , 0x15 , V_42 ) ;
F_14 ( V_3 , 0x35 , V_42 ) ;
if ( V_4 -> V_6 . V_140 )
F_14 ( V_3 , 0x9 , V_48 ) ;
V_61 = F_22 ( V_3 , 0x25 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x24 , & V_42 ) ;
if ( V_61 ) {
F_14 ( V_3 , 0x14 , V_63 ) ;
F_14 ( V_3 , 0x34 , V_63 ) ;
} else {
F_14 ( V_3 , 0x14 , V_48 ) ;
F_14 ( V_3 , 0x34 , V_48 ) ;
}
V_61 = F_22 ( V_3 , 0x28 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x31 , & V_42 ) ;
if ( V_61 ) {
F_14 ( V_3 , 0x1c , V_63 ) ;
F_14 ( V_3 , 0x3c , V_63 ) ;
F_14 ( V_3 , 0x3e , V_63 ) ;
} else {
F_14 ( V_3 , 0x1c , V_48 ) ;
F_14 ( V_3 , 0x3c , V_48 ) ;
F_14 ( V_3 , 0x3e , V_48 ) ;
}
V_42 = V_63 ;
F_20 ( V_3 , 0x33 , & V_42 ) ;
F_14 ( V_3 , 0x1d , V_42 ) ;
F_14 ( V_3 , 0x3d , V_42 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x21 ;
F_72 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_72 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_78 ( V_3 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_183 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_96 ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_137 ;
unsigned int V_42 , V_155 ;
V_137 =
F_17 ( V_3 , 0x1e , 0 , V_139 , 0x00 ) == 4 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x29 , & V_42 ) ;
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_20 ( V_3 , 0x2b , & V_42 ) ;
if ( V_137 )
V_42 = V_48 ;
F_14 ( V_3 , 0x1e , V_42 ) ;
F_14 ( V_3 , 0x1f , V_42 ) ;
F_14 ( V_3 , 0x10 , V_42 ) ;
F_14 ( V_3 , 0x11 , V_42 ) ;
if ( V_4 -> V_7 == V_31 ) {
V_42 = V_63 ;
F_14 ( V_3 , 0x27 , V_42 ) ;
F_14 ( V_3 , 0x37 , V_42 ) ;
} else {
V_42 = V_63 ;
F_20 ( V_3 , 0x27 , & V_42 ) ;
F_14 ( V_3 , 0x37 , V_42 ) ;
}
V_42 = V_63 ;
F_20 ( V_3 , 0x26 , & V_42 ) ;
F_14 ( V_3 , 0x36 , V_42 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2b , & V_42 ) ;
F_14 ( V_3 , 0x3b , V_42 ) ;
F_14 ( V_3 , 0x1b , V_42 ) ;
}
F_16 ( V_3 , 0xa , V_42 , 2 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x25 , & V_42 ) ;
F_14 ( V_3 , 0x35 , V_42 ) ;
if ( F_18 ( V_3 ) ) {
F_20 ( V_3 , 0x2a , & V_42 ) ;
F_14 ( V_3 , 0x3a , V_42 ) ;
F_14 ( V_3 , 0x1a , V_42 ) ;
}
F_16 ( V_3 , 0x9 , V_42 , 1 ) ;
V_42 = V_63 ;
F_20 ( V_3 , 0x28 , & V_42 ) ;
F_14 ( V_3 , 0x38 , V_42 ) ;
F_14 ( V_3 , 0x18 , V_42 ) ;
if ( V_4 -> V_6 . V_140 )
F_16 ( V_3 , 0xb , V_42 , 3 ) ;
V_155 = V_42 ;
V_42 = V_63 ;
F_20 ( V_3 , 0x24 , & V_42 ) ;
F_14 ( V_3 , 0x34 , V_42 ) ;
if ( ! V_4 -> V_6 . V_140 && V_155 != V_63 )
V_42 = V_155 ;
F_16 ( V_3 , 0x8 , V_42 , 0 ) ;
F_14 ( V_3 , 0x3f , V_137 ? V_48 : V_42 ) ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_89 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_6 . V_127 = 0x3f ;
F_78 ( V_3 ) ;
V_89 = F_58 ( V_3 ) ;
if ( V_89 < 0 ) {
F_36 ( V_3 ) ;
return V_89 ;
}
V_4 -> V_113 [ V_4 -> V_112 ++ ] = V_184 ;
V_3 -> V_133 = V_134 ;
V_4 -> F_13 = F_98 ;
return 0 ;
}
static int T_4 F_100 ( void )
{
return F_101 ( & V_185 ) ;
}
static void T_5 F_102 ( void )
{
F_103 ( & V_185 ) ;
}
