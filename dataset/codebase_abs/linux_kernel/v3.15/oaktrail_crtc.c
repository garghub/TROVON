static const struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
const struct V_1 * V_5 = NULL ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_2 ( V_3 , V_11 )
|| F_2 ( V_3 , V_12 ) ) {
switch ( V_9 -> V_13 ) {
case 100 :
V_5 = & V_14 [ V_15 ] ;
break;
case 166 :
V_5 = & V_14 [ V_16 ] ;
break;
case 200 :
V_5 = & V_14 [ V_17 ] ;
break;
}
} else if ( F_2 ( V_3 , V_18 ) ) {
V_5 = & V_14 [ V_19 ] ;
} else {
V_5 = NULL ;
F_3 ( V_7 -> V_7 , L_1 ) ;
}
return V_5 ;
}
static void F_4 ( int V_4 , struct V_20 * clock )
{
clock -> V_21 = ( V_4 * clock -> V_22 ) / ( 14 * clock -> V_23 ) ;
}
static void F_5 ( struct V_20 * clock )
{
F_6 ( L_2 ,
clock -> V_21 , clock -> V_22 , clock -> V_24 , clock -> V_25 , clock -> V_26 ,
clock -> V_23 , clock -> V_27 ) ;
}
static bool F_7 ( const struct V_1 * V_5 ,
struct V_2 * V_3 , int V_28 ,
int V_4 , struct V_20 * V_29 )
{
struct V_20 clock ;
T_1 V_30 , V_31 ;
T_2 V_32 , V_33 = 100000 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
for ( clock . V_22 = V_5 -> V_22 . V_34 ; clock . V_22 <= V_5 -> V_22 . V_35 ; clock . V_22 ++ ) {
for ( clock . V_26 = V_5 -> V_26 . V_34 ; clock . V_26 <= V_5 -> V_26 . V_35 ;
clock . V_26 ++ ) {
for ( clock . V_23 = V_5 -> V_23 . V_34 ;
clock . V_23 <= V_5 -> V_23 . V_35 ; clock . V_23 ++ ) {
clock . V_36 = clock . V_23 * V_5 -> V_27 . V_37 ;
V_30 = V_28 * clock . V_36 ;
if ( V_30 > V_5 -> V_38 . V_35 )
break;
if ( V_30 < V_5 -> V_38 . V_34 )
continue;
V_31 = ( V_4 * clock . V_22 ) /
( clock . V_26 * clock . V_36 ) ;
V_32 = 10000 -
( ( V_28 * 10000 ) / V_31 ) ;
if ( V_32 < - V_33 ) {
break;
}
if ( V_32 < 0 )
V_32 = - V_32 ;
if ( V_32 < V_33 ) {
V_33 = V_32 ;
* V_29 = clock ;
}
}
}
if ( V_33 == 0 )
break;
}
return V_33 == 0 ;
}
static bool F_8 ( const struct V_1 * V_5 ,
struct V_2 * V_3 , int V_28 ,
int V_4 , struct V_20 * V_29 )
{
struct V_20 clock ;
int V_39 = V_28 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
for ( clock . V_22 = V_5 -> V_22 . V_34 ; clock . V_22 <= V_5 -> V_22 . V_35 ; clock . V_22 ++ ) {
for ( clock . V_23 = V_5 -> V_23 . V_34 ; clock . V_23 <= V_5 -> V_23 . V_35 ;
clock . V_23 ++ ) {
int V_40 ;
F_4 ( V_4 , & clock ) ;
V_40 = abs ( clock . V_21 - V_28 ) ;
if ( V_40 < V_39 ) {
* V_29 = clock ;
V_39 = V_40 ;
}
}
}
return V_39 != V_28 ;
}
static void F_9 ( struct V_2 * V_3 , int V_41 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_42 * V_42 = F_10 ( V_3 ) ;
int V_43 = V_42 -> V_43 ;
const struct V_44 * V_45 = & V_9 -> V_46 [ V_43 ] ;
T_1 V_47 ;
int V_48 ;
int V_49 = F_2 ( V_3 , V_18 ) ? 1 : 0 ;
if ( F_2 ( V_3 , V_50 ) ) {
F_11 ( V_3 , V_41 ) ;
return;
}
if ( ! F_12 ( V_7 , true ) )
return;
switch ( V_41 ) {
case V_51 :
case V_52 :
case V_53 :
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
V_47 = F_13 ( V_45 -> V_54 , V_48 ) ;
if ( ( V_47 & V_55 ) == 0 ) {
F_14 ( V_45 -> V_54 , V_47 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
F_14 ( V_45 -> V_54 ,
V_47 | V_55 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
F_14 ( V_45 -> V_54 ,
V_47 | V_55 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
}
V_47 = F_13 ( V_45 -> V_56 , V_48 ) ;
if ( ( V_47 & V_57 ) == 0 ) {
F_14 ( V_45 -> V_56 ,
V_47 | V_57 , V_48 ) ;
}
V_47 = F_13 ( V_45 -> V_58 , V_48 ) ;
if ( ( V_47 & V_59 ) == 0 ) {
F_14 ( V_45 -> V_58 ,
V_47 | V_59 ,
V_48 ) ;
F_14 ( V_45 -> V_60 ,
F_13 ( V_45 -> V_60 , V_48 ) , V_48 ) ;
}
}
F_16 ( V_3 ) ;
break;
case V_61 :
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_62 , V_63 , V_48 ) ;
V_47 = F_13 ( V_45 -> V_58 , V_48 ) ;
if ( ( V_47 & V_59 ) != 0 ) {
F_14 ( V_45 -> V_58 ,
V_47 & ~ V_59 , V_48 ) ;
F_14 ( V_45 -> V_60 ,
F_17 ( V_45 -> V_60 ) , V_48 ) ;
F_13 ( V_45 -> V_60 , V_48 ) ;
}
V_47 = F_13 ( V_45 -> V_56 , V_48 ) ;
if ( ( V_47 & V_57 ) != 0 ) {
F_14 ( V_45 -> V_56 ,
V_47 & ~ V_57 , V_48 ) ;
F_13 ( V_45 -> V_56 , V_48 ) ;
}
F_18 ( V_7 ) ;
V_47 = F_13 ( V_45 -> V_54 , V_48 ) ;
if ( ( V_47 & V_55 ) != 0 ) {
F_14 ( V_45 -> V_54 ,
V_47 & ~ V_55 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
}
F_15 ( 150 ) ;
}
break;
}
F_19 ( V_64 , 0x3f80 ) ;
F_19 ( V_65 , 0x3f8f0404 ) ;
F_19 ( V_66 , 0x04040f04 ) ;
F_19 ( V_67 , 0x0 ) ;
F_19 ( V_68 , 0x04040404 ) ;
F_19 ( V_69 , 0x04040404 ) ;
F_19 ( V_70 , 0x78 ) ;
F_19 ( V_71 , F_17 ( V_71 ) | 0xc040 ) ;
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
T_1 V_72 ;
V_72 = F_17 ( V_73 ) ;
if ( ( V_72 & V_74 ) == 0 )
return - 1 ;
return ( V_72 >> 29 ) & 3 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_75 * V_41 ,
struct V_75 * V_76 ,
int V_77 , int V_78 ,
struct V_79 * V_80 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_42 * V_42 = F_10 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_43 = V_42 -> V_43 ;
const struct V_44 * V_45 = & V_9 -> V_46 [ V_43 ] ;
int V_4 = 0 ;
struct V_20 clock ;
const struct V_1 * V_5 ;
T_1 V_54 = 0 , V_81 = 0 , V_82 , V_83 ;
bool V_84 , V_85 = false ;
bool V_86 = false ;
bool V_87 = false ;
struct V_88 * V_89 = & V_7 -> V_89 ;
struct V_90 * V_90 = NULL ;
T_3 V_91 = V_92 ;
struct V_93 * V_94 ;
int V_48 ;
int V_49 = F_2 ( V_3 , V_18 ) ? 1 : 0 ;
if ( F_2 ( V_3 , V_50 ) )
return F_23 ( V_3 , V_41 , V_76 , V_77 , V_78 , V_80 ) ;
if ( ! F_12 ( V_7 , true ) )
return 0 ;
memcpy ( & V_42 -> V_95 ,
V_41 ,
sizeof( struct V_75 ) ) ;
memcpy ( & V_42 -> V_96 ,
V_76 ,
sizeof( struct V_75 ) ) ;
F_24 (connector, &mode_config->connector_list, head) {
if ( ! V_94 -> V_97 || V_94 -> V_97 -> V_3 != V_3 )
continue;
V_90 = F_25 ( V_94 ) ;
switch ( V_90 -> type ) {
case V_11 :
V_86 = true ;
break;
case V_18 :
V_85 = true ;
break;
case V_12 :
V_87 = true ;
break;
}
}
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ )
F_14 ( V_62 , V_63 , V_48 ) ;
if ( F_21 ( V_7 ) == V_43 )
F_19 ( V_73 , 0 ) ;
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_45 -> V_98 , ( ( V_41 -> V_99 - 1 ) << 16 ) |
( V_41 -> V_100 - 1 ) , V_48 ) ;
}
if ( V_90 )
F_26 ( & V_94 -> V_60 ,
V_7 -> V_89 . V_101 , & V_91 ) ;
if ( V_91 == V_102 ) {
int V_103 = 0 , V_104 = 0 ;
V_103 = ( V_76 -> V_99 -
V_41 -> V_99 ) / 2 ;
V_104 = ( V_76 -> V_100 -
V_41 -> V_100 ) / 2 ;
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_45 -> V_105 , ( V_41 -> V_99 - 1 ) |
( ( V_76 -> V_106 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_107 , ( V_41 -> V_100 - 1 ) |
( ( V_76 -> V_108 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_109 ,
( V_76 -> V_110 - V_103 - 1 ) |
( ( V_76 -> V_111 - V_103 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_112 ,
( V_76 -> V_113 - V_103 - 1 ) |
( ( V_76 -> V_114 - V_103 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_115 ,
( V_76 -> V_116 - V_104 - 1 ) |
( ( V_76 -> V_117 - V_104 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_118 ,
( V_76 -> V_119 - V_104 - 1 ) |
( ( V_76 -> V_120 - V_104 - 1 ) << 16 ) , V_48 ) ;
}
} else {
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_45 -> V_105 , ( V_76 -> V_99 - 1 ) |
( ( V_76 -> V_106 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_107 , ( V_76 -> V_100 - 1 ) |
( ( V_76 -> V_108 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_109 , ( V_76 -> V_110 - 1 ) |
( ( V_76 -> V_111 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_112 , ( V_76 -> V_113 - 1 ) |
( ( V_76 -> V_114 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_115 , ( V_76 -> V_116 - 1 ) |
( ( V_76 -> V_117 - 1 ) << 16 ) , V_48 ) ;
F_14 ( V_45 -> V_118 , ( V_76 -> V_119 - 1 ) |
( ( V_76 -> V_120 - 1 ) << 16 ) , V_48 ) ;
}
}
{
struct V_121 * V_122 =
V_3 -> V_123 ;
V_122 -> V_124 ( V_3 , V_77 , V_78 , V_80 ) ;
}
V_83 = F_17 ( V_45 -> V_56 ) ;
V_82 = F_17 ( V_45 -> V_58 ) ;
V_82 |= V_125 ;
if ( V_43 == 0 )
V_82 |= V_126 ;
else
V_82 |= V_127 ;
if ( V_87 )
goto V_128;
V_54 = 0 ;
V_4 = V_85 ? 96000 : V_9 -> V_13 * 1000 ;
V_5 = F_1 ( V_3 , V_4 ) ;
V_84 = V_5 -> V_129 ( V_5 , V_3 , V_76 -> clock ,
V_4 , & clock ) ;
if ( V_85 ) {
clock . V_23 = ( 1L << ( clock . V_23 - 1 ) ) ;
clock . V_22 -= 2 ;
clock . V_26 = ( 1L << ( clock . V_26 - 1 ) ) ;
}
if ( ! V_84 )
F_27 ( L_3 ) ;
F_5 ( & clock ) ;
if ( V_85 )
V_81 = clock . V_26 << 16 | clock . V_22 ;
else
V_81 = V_130 [ ( clock . V_22 - V_131 ) ] << 8 ;
V_54 |= V_132 ;
V_54 |= V_55 ;
if ( V_86 )
V_54 |= V_133 ;
else
V_54 |= V_134 ;
if ( V_85 ) {
int V_135 =
V_76 -> clock / V_41 -> clock ;
V_54 |= V_136 ;
V_54 |=
( V_135 -
1 ) << V_137 ;
}
if ( V_85 )
V_54 |= clock . V_23 << 16 ;
else
V_54 |= ( 1 << ( clock . V_23 - 2 ) ) << 17 ;
V_54 |= V_55 ;
if ( V_54 & V_55 ) {
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_45 -> V_138 , V_81 , V_48 ) ;
F_14 ( V_45 -> V_54 , V_54 & ~ V_55 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
}
}
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
F_14 ( V_45 -> V_138 , V_81 , V_48 ) ;
F_14 ( V_45 -> V_54 , V_54 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
F_14 ( V_45 -> V_54 , V_54 , V_48 ) ;
F_13 ( V_45 -> V_54 , V_48 ) ;
F_15 ( 150 ) ;
F_14 ( V_45 -> V_56 , V_83 , V_48 ) ;
F_13 ( V_45 -> V_56 , V_48 ) ;
F_18 ( V_7 ) ;
F_14 ( V_45 -> V_58 , V_82 , V_48 ) ;
F_18 ( V_7 ) ;
}
V_128:
F_20 ( V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
int V_77 , int V_78 , struct V_79 * V_80 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_42 * V_42 = F_10 ( V_3 ) ;
struct V_139 * V_140 = F_29 ( V_3 -> V_141 -> V_142 ) ;
int V_43 = V_42 -> V_43 ;
const struct V_44 * V_45 = & V_9 -> V_46 [ V_43 ] ;
unsigned long V_143 , V_144 ;
T_1 V_82 ;
int V_145 = 0 ;
if ( ! V_3 -> V_141 -> V_142 ) {
F_30 ( V_7 -> V_7 , L_4 ) ;
return 0 ;
}
if ( ! F_12 ( V_7 , true ) )
return 0 ;
V_143 = V_140 -> V_146 -> V_144 ;
V_144 = V_78 * V_3 -> V_141 -> V_142 -> V_147 [ 0 ] + V_77 * ( V_3 -> V_141 -> V_142 -> V_148 / 8 ) ;
F_19 ( V_45 -> V_149 , V_3 -> V_141 -> V_142 -> V_147 [ 0 ] ) ;
V_82 = F_17 ( V_45 -> V_58 ) ;
V_82 &= ~ V_150 ;
switch ( V_3 -> V_141 -> V_142 -> V_148 ) {
case 8 :
V_82 |= V_151 ;
break;
case 16 :
if ( V_3 -> V_141 -> V_142 -> V_152 == 15 )
V_82 |= V_153 ;
else
V_82 |= V_154 ;
break;
case 24 :
case 32 :
V_82 |= V_155 ;
break;
default:
F_3 ( V_7 -> V_7 , L_5 ) ;
V_145 = - V_156 ;
goto V_157;
}
F_19 ( V_45 -> V_58 , V_82 ) ;
F_19 ( V_45 -> V_60 , V_144 ) ;
F_17 ( V_45 -> V_60 ) ;
F_19 ( V_45 -> V_158 , V_143 ) ;
F_17 ( V_45 -> V_158 ) ;
V_157:
F_20 ( V_7 ) ;
return V_145 ;
}
