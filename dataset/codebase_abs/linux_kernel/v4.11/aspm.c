static int F_1 ( struct V_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return ( V_6 | V_7 ) ;
case V_8 :
return V_9 ;
case V_10 :
return V_2 -> V_11 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case V_5 :
case V_8 :
return 1 ;
case V_10 :
return V_2 -> V_12 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
T_1 V_20 = V_13 ? V_21 : 0 ;
F_4 (child, &linkbus->devices, bus_list)
F_5 ( V_15 , V_22 ,
V_21 ,
V_20 ) ;
V_2 -> V_23 = ! ! V_13 ;
}
static void F_6 ( struct V_1 * V_2 , int V_13 )
{
if ( ! V_2 -> V_24 )
V_13 = 0 ;
if ( V_2 -> V_23 == V_13 )
return;
F_3 ( V_2 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_25 )
{
int V_26 = 1 , V_27 = 1 ;
T_1 V_28 ;
T_2 V_29 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
F_4 (child, &linkbus->devices, bus_list) {
F_8 ( V_15 , V_30 , & V_28 ) ;
if ( ! ( V_28 & V_31 ) ) {
V_26 = 0 ;
V_27 = 0 ;
break;
}
F_9 ( V_15 , V_22 , & V_29 ) ;
if ( ! ( V_29 & V_21 ) )
V_27 = 0 ;
}
V_2 -> V_23 = V_27 ;
V_2 -> V_12 = V_27 ;
V_2 -> V_24 = ( V_25 ) ? 0 : V_26 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_32 = 1 ;
T_2 V_29 , V_33 , V_34 [ 8 ] ;
unsigned long V_35 ;
struct V_14 * V_15 , * V_36 = V_2 -> V_18 ;
struct V_16 * V_17 = V_36 -> V_19 ;
V_15 = F_11 ( V_17 -> V_37 . V_38 , struct V_14 , V_39 ) ;
F_12 ( ! F_13 ( V_15 ) ) ;
F_9 ( V_15 , V_40 , & V_29 ) ;
if ( ! ( V_29 & V_41 ) )
V_32 = 0 ;
F_9 ( V_36 , V_40 , & V_29 ) ;
if ( ! ( V_29 & V_41 ) )
V_32 = 0 ;
F_4 (child, &linkbus->devices, bus_list) {
F_9 ( V_15 , V_22 , & V_29 ) ;
V_34 [ F_14 ( V_15 -> V_42 ) ] = V_29 ;
if ( V_32 )
V_29 |= V_43 ;
else
V_29 &= ~ V_43 ;
F_15 ( V_15 , V_22 , V_29 ) ;
}
F_9 ( V_36 , V_22 , & V_29 ) ;
V_33 = V_29 ;
if ( V_32 )
V_29 |= V_43 ;
else
V_29 &= ~ V_43 ;
F_15 ( V_36 , V_22 , V_29 ) ;
V_29 |= V_44 ;
F_15 ( V_36 , V_22 , V_29 ) ;
V_35 = V_45 ;
for (; ; ) {
F_9 ( V_36 , V_40 , & V_29 ) ;
if ( ! ( V_29 & V_46 ) )
break;
if ( F_16 ( V_45 , V_35 + V_47 ) )
break;
F_17 ( 1 ) ;
}
if ( ! ( V_29 & V_46 ) )
return;
F_18 ( & V_36 -> V_48 , L_1 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_15 ( V_15 , V_22 ,
V_34 [ F_14 ( V_15 -> V_42 ) ] ) ;
F_15 ( V_36 , V_22 , V_33 ) ;
}
static T_1 F_19 ( T_1 V_49 )
{
if ( V_49 == 0x7 )
return ( 5 * 1000 ) ;
return ( 64 << V_49 ) ;
}
static T_1 F_20 ( T_1 V_49 )
{
if ( V_49 == 0x7 )
return - 1U ;
return ( 64 << V_49 ) ;
}
static T_1 F_21 ( T_1 V_49 )
{
if ( V_49 == 0x7 )
return ( 65 * 1000 ) ;
return ( 1000 << V_49 ) ;
}
static T_1 F_22 ( T_1 V_49 )
{
if ( V_49 == 0x7 )
return - 1U ;
return ( 1000 << V_49 ) ;
}
static T_1 F_23 ( struct V_14 * V_18 , T_1 V_50 , T_1 V_20 )
{
switch ( V_50 ) {
case 0 :
return V_20 * 2 ;
case 1 :
return V_20 * 10 ;
case 2 :
return V_20 * 100 ;
}
F_18 ( & V_18 -> V_48 , L_2 ,
V_51 , V_50 ) ;
return 0 ;
}
static void F_24 ( struct V_14 * V_18 ,
struct V_52 * V_53 )
{
T_2 V_29 ;
T_1 V_28 ;
F_8 ( V_18 , V_30 , & V_28 ) ;
V_53 -> V_54 = ( V_28 & V_55 ) >> 10 ;
V_53 -> V_56 = ( V_28 & V_57 ) >> 12 ;
V_53 -> V_58 = ( V_28 & V_59 ) >> 15 ;
F_9 ( V_18 , V_22 , & V_29 ) ;
V_53 -> V_27 = V_29 & V_60 ;
V_53 -> V_61 = V_53 -> V_62 = V_53 -> V_63 = 0 ;
V_53 -> V_64 = F_25 ( V_18 , V_65 ) ;
if ( ! V_53 -> V_64 )
return;
F_26 ( V_18 , V_53 -> V_64 + V_66 ,
& V_53 -> V_61 ) ;
if ( ! ( V_53 -> V_61 & V_67 ) ) {
V_53 -> V_61 = 0 ;
return;
}
F_26 ( V_18 , V_53 -> V_64 + V_68 ,
& V_53 -> V_62 ) ;
F_26 ( V_18 , V_53 -> V_64 + V_69 ,
& V_53 -> V_63 ) ;
}
static void F_27 ( struct V_14 * V_70 )
{
T_1 V_71 , V_72 = 0 ;
struct V_73 * V_74 ;
struct V_1 * V_2 ;
if ( ( V_70 -> V_75 != V_76 ) &&
( V_70 -> V_75 != V_77 ) )
return;
V_2 = V_70 -> V_78 -> V_79 -> V_80 ;
V_74 = & V_2 -> V_74 [ F_14 ( V_70 -> V_42 ) ] ;
while ( V_2 ) {
if ( ( V_2 -> V_81 & V_82 ) &&
( V_2 -> V_83 . V_84 > V_74 -> V_84 ) )
V_2 -> V_81 &= ~ V_82 ;
if ( ( V_2 -> V_81 & V_85 ) &&
( V_2 -> V_86 . V_84 > V_74 -> V_84 ) )
V_2 -> V_81 &= ~ V_85 ;
V_71 = F_28 ( T_1 , V_2 -> V_83 . V_87 , V_2 -> V_86 . V_87 ) ;
if ( ( V_2 -> V_81 & V_7 ) &&
( V_71 + V_72 > V_74 -> V_87 ) )
V_2 -> V_81 &= ~ V_7 ;
V_72 += 1000 ;
V_2 = V_2 -> V_36 ;
}
}
static struct V_14 * F_29 ( struct V_16 * V_17 )
{
struct V_14 * V_15 ;
F_4 (child, &linkbus->devices, bus_list)
if ( F_14 ( V_15 -> V_42 ) == 0 )
return V_15 ;
return NULL ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_52 * V_88 ,
struct V_52 * V_89 )
{
T_1 V_90 , V_91 , V_92 , V_93 ;
V_2 -> V_94 . V_95 = V_88 -> V_64 ;
V_2 -> V_94 . V_96 = V_89 -> V_64 ;
V_2 -> V_94 . V_97 = V_2 -> V_94 . V_98 = 0 ;
if ( ! ( V_2 -> V_99 & V_100 ) )
return;
V_90 = ( V_88 -> V_61 >> 8 ) & 0xFF ;
V_91 = ( V_88 -> V_61 >> 8 ) & 0xFF ;
if ( V_90 > V_91 )
V_2 -> V_94 . V_97 |= V_90 << 8 ;
else
V_2 -> V_94 . V_97 |= V_91 << 8 ;
V_2 -> V_94 . V_97 |= V_101 ;
V_90 = ( V_88 -> V_61 >> 19 ) & 0x1F ;
V_92 = ( V_88 -> V_61 >> 16 ) & 0x03 ;
V_91 = ( V_89 -> V_61 >> 19 ) & 0x1F ;
V_93 = ( V_89 -> V_61 >> 16 ) & 0x03 ;
if ( F_23 ( V_2 -> V_18 , V_92 , V_90 ) >
F_23 ( V_2 -> V_102 , V_93 , V_91 ) )
V_2 -> V_94 . V_98 |= V_92 | ( V_90 << 3 ) ;
else
V_2 -> V_94 . V_98 |= V_93 | ( V_91 << 3 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_25 )
{
struct V_14 * V_15 = V_2 -> V_102 , * V_36 = V_2 -> V_18 ;
struct V_16 * V_17 = V_36 -> V_19 ;
struct V_52 V_88 , V_89 ;
if ( V_25 ) {
V_2 -> V_103 = V_9 ;
V_2 -> V_104 = V_9 ;
return;
}
F_24 ( V_36 , & V_88 ) ;
F_24 ( V_15 , & V_89 ) ;
if ( ! ( V_88 . V_54 & V_89 . V_54 ) )
return;
F_10 ( V_2 ) ;
F_24 ( V_36 , & V_88 ) ;
F_24 ( V_15 , & V_89 ) ;
if ( V_89 . V_54 & V_88 . V_54 & V_105 )
V_2 -> V_99 |= V_6 ;
if ( V_89 . V_27 & V_105 )
V_2 -> V_103 |= V_82 ;
if ( V_88 . V_27 & V_105 )
V_2 -> V_103 |= V_85 ;
V_2 -> V_83 . V_84 = F_19 ( V_88 . V_56 ) ;
V_2 -> V_86 . V_84 = F_19 ( V_89 . V_56 ) ;
if ( V_88 . V_54 & V_89 . V_54 & V_106 )
V_2 -> V_99 |= V_7 ;
if ( V_88 . V_27 & V_89 . V_27 & V_106 )
V_2 -> V_103 |= V_7 ;
V_2 -> V_83 . V_87 = F_21 ( V_88 . V_58 ) ;
V_2 -> V_86 . V_87 = F_21 ( V_89 . V_58 ) ;
if ( V_88 . V_61 & V_89 . V_61 & V_107 )
V_2 -> V_99 |= V_108 ;
if ( V_88 . V_61 & V_89 . V_61 & V_109 )
V_2 -> V_99 |= V_110 ;
if ( V_88 . V_61 & V_89 . V_61 & V_111 )
V_2 -> V_99 |= V_112 ;
if ( V_88 . V_61 & V_89 . V_61 & V_113 )
V_2 -> V_99 |= V_114 ;
if ( V_88 . V_62 & V_89 . V_62 & V_115 )
V_2 -> V_103 |= V_108 ;
if ( V_88 . V_62 & V_89 . V_62 & V_116 )
V_2 -> V_103 |= V_110 ;
if ( V_88 . V_62 & V_89 . V_62 & V_117 )
V_2 -> V_103 |= V_112 ;
if ( V_88 . V_62 & V_89 . V_62 & V_118 )
V_2 -> V_103 |= V_114 ;
if ( V_2 -> V_99 & V_119 )
F_30 ( V_2 , & V_88 , & V_89 ) ;
V_2 -> V_11 = V_2 -> V_103 ;
V_2 -> V_81 = V_2 -> V_99 ;
F_4 (child, &linkbus->devices, bus_list) {
if ( F_32 ( V_15 ) == V_120 ) {
V_2 -> V_104 = V_9 ;
break;
}
}
F_4 (child, &linkbus->devices, bus_list) {
T_1 V_28 , V_49 ;
struct V_73 * V_74 =
& V_2 -> V_74 [ F_14 ( V_15 -> V_42 ) ] ;
if ( F_32 ( V_15 ) != V_121 &&
F_32 ( V_15 ) != V_122 )
continue;
F_8 ( V_15 , V_123 , & V_28 ) ;
V_49 = ( V_28 & V_124 ) >> 6 ;
V_74 -> V_84 = F_20 ( V_49 ) ;
V_49 = ( V_28 & V_125 ) >> 9 ;
V_74 -> V_87 = F_22 ( V_49 ) ;
F_27 ( V_15 ) ;
}
}
static void F_33 ( struct V_14 * V_18 , int V_126 ,
T_1 V_127 , T_1 V_128 )
{
T_1 V_20 ;
F_26 ( V_18 , V_126 , & V_20 ) ;
V_20 &= ~ V_127 ;
V_20 |= V_128 ;
F_34 ( V_18 , V_126 , V_20 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_129 )
{
T_1 V_20 , V_130 ;
struct V_14 * V_15 = V_2 -> V_102 , * V_36 = V_2 -> V_18 ;
T_1 V_95 = V_2 -> V_94 . V_95 ;
T_1 V_96 = V_2 -> V_94 . V_96 ;
V_130 = ( V_2 -> V_103 ^ V_129 ) & V_129 ;
F_33 ( V_15 , V_96 + V_68 ,
V_131 , 0 ) ;
F_33 ( V_36 , V_95 + V_68 ,
V_131 , 0 ) ;
if ( V_130 & ( V_108 | V_110 ) ) {
F_5 ( V_15 , V_22 ,
V_132 , 0 ) ;
F_5 ( V_36 , V_22 ,
V_132 , 0 ) ;
}
if ( V_130 & V_100 ) {
F_34 ( V_36 , V_95 + V_69 ,
V_2 -> V_94 . V_98 ) ;
F_34 ( V_15 , V_96 + V_69 ,
V_2 -> V_94 . V_98 ) ;
F_33 ( V_36 , V_95 + V_68 ,
0xFF00 , V_2 -> V_94 . V_97 ) ;
F_33 ( V_36 , V_96 + V_68 ,
0xE3FF0000 , V_2 -> V_94 . V_97 ) ;
F_33 ( V_15 , V_96 + V_68 ,
0xE3FF0000 , V_2 -> V_94 . V_97 ) ;
}
V_20 = 0 ;
if ( V_129 & V_108 )
V_20 |= V_115 ;
if ( V_129 & V_110 )
V_20 |= V_116 ;
if ( V_129 & V_112 )
V_20 |= V_117 ;
if ( V_129 & V_114 )
V_20 |= V_118 ;
F_33 ( V_36 , V_95 + V_68 ,
V_67 , V_20 ) ;
F_33 ( V_15 , V_96 + V_68 ,
V_67 , V_20 ) ;
}
static void F_36 ( struct V_14 * V_18 , T_1 V_20 )
{
F_5 ( V_18 , V_22 ,
V_60 , V_20 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_1 V_129 )
{
T_1 V_133 = 0 , V_134 = 0 ;
struct V_14 * V_15 = V_2 -> V_102 , * V_36 = V_2 -> V_18 ;
struct V_16 * V_17 = V_36 -> V_19 ;
V_129 &= ( V_2 -> V_81 & ~ V_2 -> V_104 ) ;
if ( ! ( V_129 & V_7 ) )
V_129 &= ~ V_119 ;
if ( V_36 -> V_75 != V_76 || V_15 -> V_75 != V_76 ) {
V_129 &= ~ V_135 ;
V_129 |= ( V_2 -> V_103 & V_135 ) ;
}
if ( V_2 -> V_103 == V_129 )
return;
if ( V_129 & V_82 )
V_134 |= V_136 ;
if ( V_129 & V_85 )
V_133 |= V_136 ;
if ( V_129 & V_7 ) {
V_133 |= V_132 ;
V_134 |= V_132 ;
}
if ( V_2 -> V_81 & V_119 )
F_35 ( V_2 , V_129 ) ;
if ( V_129 & V_7 )
F_36 ( V_36 , V_133 ) ;
F_4 (child, &linkbus->devices, bus_list)
F_36 ( V_15 , V_134 ) ;
if ( ! ( V_129 & V_7 ) )
F_36 ( V_36 , V_133 ) ;
V_2 -> V_103 = V_129 ;
}
static void F_38 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_37 ( V_2 , F_1 ( V_2 ) ) ;
V_2 = V_2 -> V_36 ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_80 = NULL ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_14 * V_18 )
{
struct V_14 * V_15 ;
T_1 V_28 ;
F_4 (child, &pdev->subordinate->devices, bus_list) {
if ( ! F_13 ( V_15 ) )
return - V_137 ;
if ( V_138 )
continue;
F_8 ( V_15 , V_123 , & V_28 ) ;
if ( ! ( V_28 & V_139 ) && ! V_140 ) {
F_42 ( & V_15 -> V_48 , L_3 ) ;
return - V_137 ;
}
}
return 0 ;
}
static struct V_1 * F_43 ( struct V_14 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_44 ( sizeof( * V_2 ) , V_141 ) ;
if ( ! V_2 )
return NULL ;
F_45 ( & V_2 -> V_142 ) ;
F_45 ( & V_2 -> V_143 ) ;
F_45 ( & V_2 -> V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_102 = F_29 ( V_18 -> V_19 ) ;
if ( F_32 ( V_18 ) == V_144 ||
F_32 ( V_18 ) == V_145 ) {
V_2 -> V_146 = V_2 ;
} else {
struct V_1 * V_36 ;
V_36 = V_18 -> V_78 -> V_36 -> V_79 -> V_80 ;
if ( ! V_36 ) {
F_40 ( V_2 ) ;
return NULL ;
}
V_2 -> V_36 = V_36 ;
V_2 -> V_146 = V_2 -> V_36 -> V_146 ;
F_46 ( & V_2 -> V_2 , & V_36 -> V_143 ) ;
}
F_46 ( & V_2 -> V_142 , & V_147 ) ;
V_18 -> V_80 = V_2 ;
return V_2 ;
}
void F_47 ( struct V_14 * V_18 )
{
struct V_1 * V_2 ;
int V_25 = ! ! F_41 ( V_18 ) ;
if ( ! V_148 )
return;
if ( V_18 -> V_80 )
return;
if ( ! V_18 -> V_149 )
return;
if ( F_32 ( V_18 ) == V_144 &&
V_18 -> V_78 -> V_79 )
return;
F_48 ( & V_150 ) ;
if ( F_49 ( & V_18 -> V_19 -> V_37 ) )
goto V_151;
F_50 ( & V_152 ) ;
V_2 = F_43 ( V_18 ) ;
if ( ! V_2 )
goto V_153;
F_31 ( V_2 , V_25 ) ;
F_7 ( V_2 , V_25 ) ;
if ( V_3 != V_5 &&
V_3 != V_8 ) {
F_38 ( V_2 ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
}
V_153:
F_51 ( & V_152 ) ;
V_151:
F_52 ( & V_150 ) ;
}
static void F_53 ( struct V_1 * V_146 )
{
struct V_1 * V_2 ;
F_12 ( V_146 -> V_36 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_146 != V_146 )
continue;
V_2 -> V_81 = V_2 -> V_99 ;
}
F_4 (link, &link_list, sibling) {
struct V_14 * V_15 ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
if ( V_2 -> V_146 != V_146 )
continue;
F_4 (child, &linkbus->devices, bus_list) {
if ( ( F_32 ( V_15 ) != V_121 ) &&
( F_32 ( V_15 ) != V_122 ) )
continue;
F_27 ( V_15 ) ;
}
}
}
void F_54 ( struct V_14 * V_18 )
{
struct V_14 * V_36 = V_18 -> V_78 -> V_79 ;
struct V_1 * V_2 , * V_146 , * V_154 ;
if ( ! V_36 || ! V_36 -> V_80 )
return;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
if ( ! F_55 ( & V_18 -> V_39 , & V_36 -> V_19 -> V_37 ) )
goto V_151;
V_2 = V_36 -> V_80 ;
V_146 = V_2 -> V_146 ;
V_154 = V_2 -> V_36 ;
F_37 ( V_2 , 0 ) ;
F_56 ( & V_2 -> V_142 ) ;
F_56 ( & V_2 -> V_2 ) ;
F_39 ( V_2 ) ;
if ( V_154 ) {
F_53 ( V_146 ) ;
F_38 ( V_154 ) ;
}
V_151:
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
}
void F_57 ( struct V_14 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_80 ;
if ( V_138 || ! V_2 )
return;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
F_53 ( V_2 -> V_146 ) ;
F_38 ( V_2 ) ;
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
}
void F_58 ( struct V_14 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_80 ;
if ( V_138 || ! V_2 )
return;
if ( V_3 != V_5 &&
V_3 != V_8 )
return;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
F_38 ( V_2 ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
}
static void F_59 ( struct V_14 * V_18 , int V_129 , bool V_155 )
{
struct V_14 * V_36 = V_18 -> V_78 -> V_79 ;
struct V_1 * V_2 ;
if ( ! F_13 ( V_18 ) )
return;
if ( V_18 -> V_149 )
V_36 = V_18 ;
if ( ! V_36 || ! V_36 -> V_80 )
return;
if ( V_138 ) {
F_60 ( & V_18 -> V_48 , L_4 ) ;
return;
}
if ( V_155 )
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
V_2 = V_36 -> V_80 ;
if ( V_129 & V_105 )
V_2 -> V_104 |= V_6 ;
if ( V_129 & V_106 )
V_2 -> V_104 |= V_7 ;
F_37 ( V_2 , F_1 ( V_2 ) ) ;
if ( V_129 & V_156 ) {
V_2 -> V_24 = 0 ;
F_6 ( V_2 , 0 ) ;
}
F_51 ( & V_152 ) ;
if ( V_155 )
F_52 ( & V_150 ) ;
}
void F_61 ( struct V_14 * V_18 , int V_129 )
{
F_59 ( V_18 , V_129 , false ) ;
}
void F_62 ( struct V_14 * V_18 , int V_129 )
{
F_59 ( V_18 , V_129 , true ) ;
}
static int F_63 ( const char * V_20 , struct V_157 * V_158 )
{
int V_159 ;
struct V_1 * V_2 ;
if ( V_138 )
return - V_160 ;
for ( V_159 = 0 ; V_159 < F_64 ( V_161 ) ; V_159 ++ )
if ( ! strncmp ( V_20 , V_161 [ V_159 ] , strlen ( V_161 [ V_159 ] ) ) )
break;
if ( V_159 >= F_64 ( V_161 ) )
return - V_137 ;
if ( V_159 == V_3 )
return 0 ;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
V_3 = V_159 ;
F_4 (link, &link_list, sibling) {
F_37 ( V_2 , F_1 ( V_2 ) ) ;
F_6 ( V_2 , F_2 ( V_2 ) ) ;
}
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
return 0 ;
}
static int F_65 ( char * V_162 , struct V_157 * V_158 )
{
int V_159 , V_163 = 0 ;
for ( V_159 = 0 ; V_159 < F_64 ( V_161 ) ; V_159 ++ )
if ( V_159 == V_3 )
V_163 += sprintf ( V_162 + V_163 , L_5 , V_161 [ V_159 ] ) ;
else
V_163 += sprintf ( V_162 + V_163 , L_6 , V_161 [ V_159 ] ) ;
return V_163 ;
}
static T_3 F_66 ( struct V_164 * V_48 ,
struct V_165 * V_166 ,
char * V_167 )
{
struct V_14 * V_168 = F_67 ( V_48 ) ;
struct V_1 * V_80 = V_168 -> V_80 ;
return sprintf ( V_167 , L_7 , V_80 -> V_103 ) ;
}
static T_3 F_68 ( struct V_164 * V_48 ,
struct V_165 * V_166 ,
const char * V_167 ,
T_4 V_169 )
{
struct V_14 * V_18 = F_67 ( V_48 ) ;
struct V_1 * V_2 , * V_146 = V_18 -> V_80 -> V_146 ;
T_1 V_129 ;
if ( V_138 )
return - V_160 ;
if ( F_69 ( V_167 , 10 , & V_129 ) )
return - V_137 ;
if ( ( V_129 & ~ V_9 ) != 0 )
return - V_137 ;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
F_4 (link, &link_list, sibling) {
if ( V_2 -> V_146 != V_146 )
continue;
F_37 ( V_2 , V_129 ) ;
}
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
return V_169 ;
}
static T_3 F_70 ( struct V_164 * V_48 ,
struct V_165 * V_166 ,
char * V_167 )
{
struct V_14 * V_168 = F_67 ( V_48 ) ;
struct V_1 * V_80 = V_168 -> V_80 ;
return sprintf ( V_167 , L_7 , V_80 -> V_23 ) ;
}
static T_3 F_71 ( struct V_164 * V_48 ,
struct V_165 * V_166 ,
const char * V_167 ,
T_4 V_169 )
{
struct V_14 * V_18 = F_67 ( V_48 ) ;
bool V_129 ;
if ( F_72 ( V_167 , & V_129 ) )
return - V_137 ;
F_48 ( & V_150 ) ;
F_50 ( & V_152 ) ;
F_3 ( V_18 -> V_80 , V_129 ) ;
F_51 ( & V_152 ) ;
F_52 ( & V_150 ) ;
return V_169 ;
}
void F_73 ( struct V_14 * V_18 )
{
struct V_1 * V_80 = V_18 -> V_80 ;
if ( ! V_80 )
return;
if ( V_80 -> V_99 )
F_74 ( & V_18 -> V_48 . V_170 ,
& V_171 . V_166 , V_172 ) ;
if ( V_80 -> V_24 )
F_74 ( & V_18 -> V_48 . V_170 ,
& V_173 . V_166 , V_172 ) ;
}
void F_75 ( struct V_14 * V_18 )
{
struct V_1 * V_80 = V_18 -> V_80 ;
if ( ! V_80 )
return;
if ( V_80 -> V_99 )
F_76 ( & V_18 -> V_48 . V_170 ,
& V_171 . V_166 , V_172 ) ;
if ( V_80 -> V_24 )
F_76 ( & V_18 -> V_48 . V_170 ,
& V_173 . V_166 , V_172 ) ;
}
static int T_5 F_77 ( char * V_174 )
{
if ( ! strcmp ( V_174 , L_8 ) ) {
V_3 = V_10 ;
V_138 = 1 ;
V_148 = false ;
F_78 ( V_175 L_9 ) ;
} else if ( ! strcmp ( V_174 , L_10 ) ) {
V_140 = 1 ;
F_78 ( V_175 L_11 ) ;
}
return 1 ;
}
void F_79 ( void )
{
if ( ! V_140 ) {
V_3 = V_10 ;
V_138 = 1 ;
}
}
bool F_80 ( void )
{
return V_148 ;
}
