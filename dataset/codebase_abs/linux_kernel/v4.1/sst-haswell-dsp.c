static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
int V_13 , V_14 ;
void T_1 * V_15 ;
if ( V_6 -> type != V_16
&& V_6 -> type != V_17
&& V_6 -> type != V_18
&& V_6 -> type != V_19
&& V_6 -> type != V_20
&& V_6 -> type != V_21
&& V_6 -> type != V_22 )
return 0 ;
F_2 ( V_2 -> V_23 , L_1 ,
V_6 -> V_24 , V_6 -> V_25 ,
V_6 -> V_26 , V_6 -> type ) ;
F_2 ( V_2 -> V_23 , L_2 , V_6 -> V_27 ) ;
F_2 ( V_2 -> V_23 , L_3 ,
V_6 -> V_28 . V_29 , V_6 -> V_28 . V_30 ) ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_31 = V_6 -> type ;
V_12 . V_32 = V_6 -> V_27 - 4 ;
V_12 . V_29 = V_6 -> V_28 . V_29 ;
V_12 . V_30 = V_6 -> V_28 . V_30 ;
V_10 = F_3 ( V_4 , & V_12 , NULL ) ;
if ( V_10 == NULL )
return - V_33 ;
V_8 = ( void * ) V_6 + sizeof( * V_6 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_26 ; V_13 ++ ) {
if ( V_8 -> V_34 <= 0 ) {
F_4 ( V_2 -> V_23 ,
L_4 , V_13 ) ;
F_5 ( V_10 ) ;
return - V_35 ;
}
switch ( V_8 -> type ) {
case V_36 :
V_15 = V_2 -> V_37 . V_38 ;
V_10 -> V_39 =
V_8 -> V_40 + V_2 -> V_37 . V_41 ;
V_10 -> type = V_42 ;
break;
case V_43 :
case V_44 :
V_15 = V_2 -> V_37 . V_38 ;
V_10 -> V_39 = V_8 -> V_40 ;
V_10 -> type = V_45 ;
break;
default:
F_4 ( V_2 -> V_23 , L_5 ,
V_8 -> type , V_13 ) ;
F_5 ( V_10 ) ;
return - V_35 ;
}
V_10 -> V_34 = V_8 -> V_34 ;
V_10 -> V_46 = ( void * ) V_8 + sizeof( * V_8 ) ;
V_10 -> V_47 = V_10 -> V_46 - V_4 -> V_48 ;
F_2 ( V_2 -> V_23 , L_6
L_7 ,
V_13 , V_10 -> type , V_8 -> V_34 , V_15 ,
V_8 -> V_40 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 < 0 ) {
F_4 ( V_2 -> V_23 , L_8 ,
V_13 ) ;
F_5 ( V_10 ) ;
return V_14 ;
}
V_8 = ( void * ) V_8 + sizeof( * V_8 ) + V_8 -> V_34 ;
}
V_10 -> V_49 = V_50 ;
return 0 ;
}
static int F_7 ( struct V_3 * V_3 )
{
struct V_51 * V_52 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_3 -> V_2 ;
int V_14 , V_13 ;
V_52 = (struct V_51 * ) V_3 -> V_48 ;
if ( ( strncmp ( V_52 -> V_24 , V_53 , 4 ) != 0 ) ||
( V_3 -> V_34 != V_52 -> V_54 + sizeof( * V_52 ) ) ) {
F_4 ( V_2 -> V_23 , L_9 ) ;
return - V_35 ;
}
F_2 ( V_2 -> V_23 , L_10 ,
V_52 -> V_54 , V_52 -> V_55 ,
V_52 -> V_56 , sizeof( * V_52 ) ) ;
V_6 = ( void * ) V_3 -> V_48 + sizeof( * V_52 ) ;
for ( V_13 = 0 ; V_13 < V_52 -> V_55 ; V_13 ++ ) {
V_14 = F_1 ( V_2 , V_3 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_2 -> V_23 , L_11 , V_13 ) ;
return V_14 ;
}
V_6 = ( void * ) V_6 + sizeof( * V_6 ) + V_6 -> V_25 ;
}
return 0 ;
}
static T_2 F_8 ( int V_57 , void * V_58 )
{
struct V_1 * V_59 = (struct V_1 * ) V_58 ;
T_3 V_60 ;
int V_14 = V_61 ;
F_9 ( & V_59 -> V_62 ) ;
V_60 = F_10 ( V_59 , V_63 ) ;
if ( V_60 & V_64 ) {
F_11 ( V_60 ,
F_10 ( V_59 , V_65 ) ) ;
F_12 ( V_59 , V_65 ,
V_66 , V_66 ) ;
V_14 = V_67 ;
}
if ( V_60 & V_68 ) {
F_13 ( V_60 ,
F_10 ( V_59 , V_65 ) ) ;
F_12 ( V_59 , V_65 ,
V_69 , V_69 ) ;
V_14 = V_67 ;
}
F_14 ( & V_59 -> V_62 ) ;
return V_14 ;
}
static void F_15 ( struct V_1 * V_59 )
{
T_3 V_70 ;
T_3 V_71 ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_71 &= ~ ( V_74 | V_75 ) ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_73 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_76 ) ;
V_70 |= V_77 |
V_78 ;
V_70 &= ~ ( V_79 | V_80 ) ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_76 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_70 |= V_81 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_73 ) ;
F_12 ( V_59 , V_82 ,
V_83 , 0 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_84 ) ;
V_70 |= V_85 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_84 ) ;
F_18 ( 50 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_71 |= V_74 | V_75 ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_73 ) ;
F_18 ( 50 ) ;
}
static void F_19 ( struct V_1 * V_59 )
{
F_12 ( V_59 , V_86 ,
V_87 | V_88 ,
V_87 | V_88 ) ;
F_20 ( 10 ) ;
F_12 ( V_59 , V_86 ,
V_87 | V_88 , V_88 ) ;
}
static int F_21 ( struct V_1 * V_59 )
{
int V_89 = 10 ;
T_3 V_71 , V_90 ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_71 &= ~ ( V_74 | V_75 ) ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_73 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_76 ) ;
V_71 |= V_79 ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_76 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_84 ) ;
V_71 &= ~ V_85 ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_84 ) ;
while ( V_89 -- ) {
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_84 ) & V_85 ;
if ( V_71 == 0 )
goto V_91;
F_22 ( 1 ) ;
}
return - V_92 ;
V_91:
F_12 ( V_59 , V_86 ,
V_93 | V_94 | V_95 , 0x0 ) ;
F_12 ( V_59 ,
V_86 , V_88 | V_96 ,
V_88 | F_23 ( 4 ) ) ;
F_12 ( V_59 , V_82 ,
V_83 | V_97 | V_98 ,
V_83 | V_97 | V_98 ) ;
F_19 ( V_59 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_71 |= V_74 | V_75 ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_73 ) ;
F_18 ( 50 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_71 &= ~ V_81 ;
F_17 ( V_71 , V_59 -> V_37 . V_72 + V_73 ) ;
V_71 = F_16 ( V_59 -> V_37 . V_72 + V_76 ) ;
V_71 |= V_77 | V_78 ;
V_90 = 1 << V_99 ;
F_17 ( V_71 & ~ V_90 , V_59 -> V_37 . V_72 + V_76 ) ;
F_12 ( V_59 , V_100 , V_101 ,
V_101 ) ;
F_24 ( V_59 , V_102 ,
V_103 | V_104 ,
V_103 | V_104 ) ;
F_24 ( V_59 , V_65 , ( V_69 | V_66 ) ,
0x0 ) ;
F_24 ( V_59 , V_105 , ( V_106 | V_107 |
V_108 | V_109 ) , 0x0 ) ;
F_25 ( V_59 , V_110 , 0x0 ) ;
F_25 ( V_59 , V_111 , 0x0 ) ;
F_25 ( V_59 , 0x80 , 0x6 ) ;
F_25 ( V_59 , 0xe0 , 0x300a ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_59 )
{
F_24 ( V_59 , V_102 ,
V_103 | V_104 , 0 ) ;
F_12 ( V_59 , V_86 , V_88 , 0x0 ) ;
}
static void F_27 ( struct V_1 * V_59 )
{
F_24 ( V_59 , V_86 ,
V_112 | V_88 ,
V_88 | V_112 ) ;
}
static void F_28 ( struct V_1 * V_59 )
{
F_2 ( V_59 -> V_23 , L_12 ) ;
F_24 ( V_59 , V_86 ,
V_112 | V_87 | V_88 ,
V_87 | V_88 | V_112 ) ;
F_15 ( V_59 ) ;
F_2 ( V_59 -> V_23 , L_13 ) ;
}
static int F_29 ( struct V_1 * V_59 )
{
int V_14 ;
F_2 ( V_59 -> V_23 , L_14 ) ;
V_14 = F_21 ( V_59 ) ;
if ( V_14 < 0 )
return V_14 ;
F_2 ( V_59 -> V_23 , L_15 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_59 , struct V_113 * V_114 )
{
V_59 -> V_37 . V_115 = V_114 -> V_115 ;
V_59 -> V_37 . V_38 = F_31 ( V_114 -> V_115 , V_114 -> V_116 ) ;
if ( ! V_59 -> V_37 . V_38 )
return - V_92 ;
V_59 -> V_37 . V_72 = F_31 ( V_114 -> V_117 , V_114 -> V_118 ) ;
if ( ! V_59 -> V_37 . V_72 ) {
F_32 ( V_59 -> V_37 . V_38 ) ;
return - V_92 ;
}
V_59 -> V_37 . V_119 = V_59 -> V_37 . V_38 + V_59 -> V_37 . V_120 ;
return 0 ;
}
static T_3 F_33 ( struct V_121 * V_8 )
{
T_3 V_122 = 0 , V_123 = 0 , V_124 ;
struct V_1 * V_59 = V_8 -> V_2 ;
for ( V_124 = 0 ; V_124 < F_34 ( V_125 ) ; V_124 ++ ) {
if ( V_125 [ V_124 ] . V_126 == V_59 -> V_31 )
break;
}
if ( V_124 < F_34 ( V_125 ) ) {
switch ( V_8 -> type ) {
case V_45 :
V_123 = V_125 [ V_124 ] . V_127 ;
break;
case V_42 :
V_123 = V_125 [ V_124 ] . V_128 ;
break;
default:
V_123 = 0 ;
}
} else
V_123 = 0 ;
V_122 = 1 << ( V_8 -> V_124 + V_123 ) ;
return V_122 ;
}
static void F_35 ( struct V_121 * V_8 )
{
T_3 V_34 ;
T_4 V_129 [ 4 ] ;
struct V_1 * V_59 = V_8 -> V_2 ;
V_34 = V_8 -> V_34 > 4 ? 4 : V_8 -> V_34 ;
F_36 ( V_129 , V_59 -> V_37 . V_38 + V_8 -> V_39 , V_34 ) ;
}
static int F_37 ( struct V_121 * V_8 )
{
struct V_1 * V_59 = V_8 -> V_2 ;
T_3 V_122 , V_70 ;
if ( V_8 -> V_130 ++ > 0 )
return 0 ;
F_2 ( V_8 -> V_2 -> V_23 , L_16 ,
V_8 -> type , V_8 -> V_124 , V_8 -> V_39 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_70 &= ~ V_74 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_73 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_76 ) ;
V_122 = F_33 ( V_8 ) ;
F_17 ( V_70 & ~ V_122 , V_59 -> V_37 . V_72 + V_76 ) ;
F_18 ( 10 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_70 |= V_74 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_73 ) ;
F_18 ( 50 ) ;
F_35 ( V_8 ) ;
return 0 ;
}
static int F_38 ( struct V_121 * V_8 )
{
struct V_1 * V_59 = V_8 -> V_2 ;
T_3 V_122 , V_70 ;
if ( -- V_8 -> V_130 > 0 )
return 0 ;
F_2 ( V_8 -> V_2 -> V_23 , L_17 ,
V_8 -> type , V_8 -> V_124 , V_8 -> V_39 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_70 &= ~ V_74 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_73 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_76 ) ;
V_122 = F_33 ( V_8 ) ;
if ( V_122 != ( 1 << V_99 ) )
F_17 ( V_70 | V_122 , V_59 -> V_37 . V_72 + V_76 ) ;
F_18 ( 10 ) ;
V_70 = F_16 ( V_59 -> V_37 . V_72 + V_73 ) ;
V_70 |= V_74 ;
F_17 ( V_70 , V_59 -> V_37 . V_72 + V_73 ) ;
F_18 ( 50 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_59 , struct V_113 * V_114 )
{
const struct V_131 * V_132 ;
struct V_133 * V_23 ;
int V_14 = - V_92 , V_134 , V_135 , V_136 ;
T_3 V_39 , V_34 , V_90 ;
V_23 = V_59 -> V_137 ;
switch ( V_59 -> V_31 ) {
case V_138 :
V_132 = V_139 ;
V_136 = F_34 ( V_139 ) ;
V_59 -> V_37 . V_41 = V_140 ;
V_59 -> V_37 . V_141 = V_142 ;
V_59 -> V_37 . V_143 = V_144 ;
V_59 -> V_37 . V_120 = V_145 ;
break;
case V_146 :
V_132 = V_147 ;
V_136 = F_34 ( V_147 ) ;
V_59 -> V_37 . V_41 = V_148 ;
V_59 -> V_37 . V_141 = V_149 ;
V_59 -> V_37 . V_143 = V_150 ;
V_59 -> V_37 . V_120 = V_151 ;
break;
default:
F_4 ( V_23 , L_18 ) ;
return V_14 ;
}
V_14 = F_30 ( V_59 , V_114 ) ;
if ( V_14 < 0 ) {
F_4 ( V_23 , L_19 ) ;
return V_14 ;
}
V_14 = F_21 ( V_59 ) ;
if ( V_14 < 0 ) {
F_4 ( V_23 , L_20 ) ;
return V_14 ;
}
V_14 = F_40 ( V_23 , F_41 ( 31 ) ) ;
if ( V_14 )
return V_14 ;
for ( V_134 = 0 ; V_134 < V_136 ; V_134 ++ ) {
V_39 = V_132 [ V_134 ] . V_152 ;
V_34 = ( V_132 [ V_134 ] . V_153 - V_132 [ V_134 ] . V_152 ) / V_132 [ V_134 ] . V_26 ;
for ( V_135 = 0 ; V_135 < V_132 [ V_134 ] . V_26 ; V_135 ++ ) {
F_42 ( V_59 , V_39 , V_34 ,
V_132 [ V_134 ] . type , & V_154 , V_135 , V_59 ) ;
V_39 += V_34 ;
}
}
V_90 = 1 << V_99 ;
F_17 ( 0xffffffff & ~ V_90 , V_59 -> V_37 . V_72 + V_76 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_59 )
{
F_44 ( V_59 ) ;
F_32 ( V_59 -> V_37 . V_38 ) ;
F_32 ( V_59 -> V_37 . V_72 ) ;
}
