static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( F_2 ( V_3 , V_10 )
|| F_2 ( V_3 , V_11 ) ) {
switch ( V_8 -> V_12 ) {
case 100 :
V_4 = & V_13 [ V_14 ] ;
break;
case 166 :
V_4 = & V_13 [ V_15 ] ;
break;
case 200 :
V_4 = & V_13 [ V_16 ] ;
break;
}
} else {
V_4 = NULL ;
F_3 ( V_6 -> V_6 , L_1 ) ;
}
return V_4 ;
}
static void F_4 ( int V_17 , struct V_18 * clock )
{
clock -> V_19 = ( V_17 * clock -> V_20 ) / ( 14 * clock -> V_21 ) ;
}
static void F_5 ( char * V_22 , struct V_18 * clock )
{
F_6 ( L_2 ,
V_22 , clock -> V_19 , clock -> V_20 , clock -> V_21 ) ;
}
static bool
F_7 ( struct V_2 * V_3 , int V_23 , int V_17 ,
struct V_18 * V_24 )
{
struct V_18 clock ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_25 = V_23 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
for ( clock . V_20 = V_4 -> V_20 . V_26 ; clock . V_20 <= V_4 -> V_20 . V_27 ; clock . V_20 ++ ) {
for ( clock . V_21 = V_4 -> V_21 . V_26 ; clock . V_21 <= V_4 -> V_21 . V_27 ;
clock . V_21 ++ ) {
int V_28 ;
F_4 ( V_17 , & clock ) ;
V_28 = abs ( clock . V_19 - V_23 ) ;
if ( V_28 < V_25 ) {
* V_24 = clock ;
V_25 = V_28 ;
}
}
}
F_8 ( V_3 -> V_6 -> V_6 , L_3 , V_25 ) ;
return V_25 != V_23 ;
}
static void F_9 ( struct V_2 * V_3 , int V_29 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
int V_31 = V_30 -> V_31 ;
const struct V_32 * V_33 = & V_8 -> V_34 [ V_31 ] ;
T_1 V_35 ;
if ( V_31 == 1 ) {
F_11 ( V_3 , V_29 ) ;
return;
}
if ( ! F_12 ( V_6 , true ) )
return;
switch ( V_29 ) {
case V_36 :
case V_37 :
case V_38 :
V_35 = F_13 ( V_33 -> V_39 ) ;
if ( ( V_35 & V_40 ) == 0 ) {
F_14 ( V_33 -> V_39 , V_35 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
F_14 ( V_33 -> V_39 , V_35 | V_40 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
F_14 ( V_33 -> V_39 , V_35 | V_40 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
}
V_35 = F_13 ( V_33 -> V_41 ) ;
if ( ( V_35 & V_42 ) == 0 )
F_14 ( V_33 -> V_41 , V_35 | V_42 ) ;
V_35 = F_13 ( V_33 -> V_43 ) ;
if ( ( V_35 & V_44 ) == 0 ) {
F_14 ( V_33 -> V_43 ,
V_35 | V_44 ) ;
F_14 ( V_33 -> V_45 , F_13 ( V_33 -> V_45 ) ) ;
}
F_16 ( V_3 ) ;
break;
case V_46 :
F_14 ( V_47 , V_48 ) ;
V_35 = F_13 ( V_33 -> V_43 ) ;
if ( ( V_35 & V_44 ) != 0 ) {
F_14 ( V_33 -> V_43 ,
V_35 & ~ V_44 ) ;
F_14 ( V_33 -> V_45 , F_13 ( V_33 -> V_45 ) ) ;
F_13 ( V_33 -> V_45 ) ;
}
V_35 = F_13 ( V_33 -> V_41 ) ;
if ( ( V_35 & V_42 ) != 0 ) {
F_14 ( V_33 -> V_41 , V_35 & ~ V_42 ) ;
F_13 ( V_33 -> V_41 ) ;
}
F_17 ( V_6 ) ;
V_35 = F_13 ( V_33 -> V_39 ) ;
if ( ( V_35 & V_40 ) != 0 ) {
F_14 ( V_33 -> V_39 , V_35 & ~ V_40 ) ;
F_13 ( V_33 -> V_39 ) ;
}
F_15 ( 150 ) ;
break;
}
F_14 ( V_49 , 0x3FFF ) ;
F_14 ( V_50 , 0x3F88080A ) ;
F_14 ( V_51 , 0x0b060808 ) ;
F_14 ( V_52 , 0x0 ) ;
F_14 ( V_53 , 0x08030404 ) ;
F_14 ( V_54 , 0x04040404 ) ;
F_14 ( V_55 , 0x78 ) ;
F_14 ( 0x70400 , F_13 ( 0x70400 ) | 0x4000 ) ;
F_18 ( V_6 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
T_1 V_56 ;
V_56 = F_13 ( V_57 ) ;
if ( ( V_56 & V_58 ) == 0 )
return - 1 ;
return ( V_56 >> 29 ) & 3 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_59 * V_29 ,
struct V_59 * V_60 ,
int V_61 , int V_62 ,
struct V_63 * V_64 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_31 = V_30 -> V_31 ;
const struct V_32 * V_33 = & V_8 -> V_34 [ V_31 ] ;
int V_17 = 0 ;
struct V_18 clock ;
T_1 V_39 = 0 , V_65 = 0 , V_66 , V_67 ;
bool V_68 , V_69 = false ;
bool V_70 = false ;
bool V_71 = false ;
struct V_72 * V_73 = & V_6 -> V_73 ;
struct V_74 * V_74 = NULL ;
T_2 V_75 = V_76 ;
struct V_77 * V_78 ;
if ( V_31 == 1 )
return F_21 ( V_3 , V_29 , V_60 , V_61 , V_62 , V_64 ) ;
if ( ! F_12 ( V_6 , true ) )
return 0 ;
memcpy ( & V_30 -> V_79 ,
V_29 ,
sizeof( struct V_59 ) ) ;
memcpy ( & V_30 -> V_80 ,
V_60 ,
sizeof( struct V_59 ) ) ;
F_22 (connector, &mode_config->connector_list, head) {
if ( ! V_78 -> V_81 || V_78 -> V_81 -> V_3 != V_3 )
continue;
V_74 = F_23 ( V_78 ) ;
switch ( V_74 -> type ) {
case V_10 :
V_70 = true ;
break;
case V_82 :
V_69 = true ;
break;
case V_11 :
V_71 = true ;
break;
}
}
F_14 ( V_47 , V_48 ) ;
if ( F_19 ( V_6 ) == V_31 )
F_14 ( V_57 , 0 ) ;
F_14 ( V_33 -> V_83 ,
( ( V_29 -> V_84 - 1 ) << 16 ) |
( V_29 -> V_85 - 1 ) ) ;
if ( V_74 )
F_24 ( & V_78 -> V_45 ,
V_6 -> V_73 . V_86 , & V_75 ) ;
if ( V_75 == V_87 ) {
int V_88 = 0 , V_89 = 0 ;
V_88 = ( V_60 -> V_84 -
V_29 -> V_84 ) / 2 ;
V_89 = ( V_60 -> V_85 -
V_29 -> V_85 ) / 2 ;
F_14 ( V_33 -> V_90 , ( V_29 -> V_84 - 1 ) |
( ( V_60 -> V_91 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_92 , ( V_29 -> V_85 - 1 ) |
( ( V_60 -> V_93 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_94 ,
( V_60 -> V_95 - V_88 - 1 ) |
( ( V_60 -> V_96 - V_88 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_97 ,
( V_60 -> V_98 - V_88 - 1 ) |
( ( V_60 -> V_99 - V_88 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_100 ,
( V_60 -> V_101 - V_89 - 1 ) |
( ( V_60 -> V_102 - V_89 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_103 ,
( V_60 -> V_104 - V_89 - 1 ) |
( ( V_60 -> V_105 - V_89 - 1 ) << 16 ) ) ;
} else {
F_14 ( V_33 -> V_90 , ( V_60 -> V_84 - 1 ) |
( ( V_60 -> V_91 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_92 , ( V_60 -> V_85 - 1 ) |
( ( V_60 -> V_93 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_94 , ( V_60 -> V_95 - 1 ) |
( ( V_60 -> V_96 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_97 , ( V_60 -> V_98 - 1 ) |
( ( V_60 -> V_99 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_100 , ( V_60 -> V_101 - 1 ) |
( ( V_60 -> V_102 - 1 ) << 16 ) ) ;
F_14 ( V_33 -> V_103 , ( V_60 -> V_104 - 1 ) |
( ( V_60 -> V_105 - 1 ) << 16 ) ) ;
}
{
struct V_106 * V_107 =
V_3 -> V_108 ;
V_107 -> V_109 ( V_3 , V_61 , V_62 , V_64 ) ;
}
V_67 = F_13 ( V_33 -> V_41 ) ;
V_66 = F_13 ( V_33 -> V_43 ) ;
V_66 |= V_110 ;
if ( V_31 == 0 )
V_66 |= V_111 ;
else
V_66 |= V_112 ;
if ( V_71 )
goto V_113;
V_17 = V_8 -> V_12 * 1000 ;
V_39 = 0 ;
V_68 = F_7 ( V_3 , V_60 -> clock , V_17 , & clock ) ;
if ( ! V_68 ) {
F_8 ( V_6 -> V_6 , L_4 ) ;
} else {
F_8 ( V_6 -> V_6 , L_5
L_6 , clock . V_19 , clock . V_20 ,
clock . V_21 ) ;
}
V_65 = V_114 [ ( clock . V_20 - V_115 ) ] << 8 ;
V_39 |= V_116 ;
V_39 |= V_40 ;
if ( V_70 )
V_39 |= V_117 ;
else
V_39 |= V_118 ;
if ( V_69 ) {
int V_119 =
V_60 -> clock / V_29 -> clock ;
V_39 |= V_120 ;
V_39 |=
( V_119 -
1 ) << V_121 ;
}
V_39 |= ( 1 << ( clock . V_21 - 2 ) ) << 17 ;
V_39 |= V_40 ;
F_5 ( L_7 , & clock ) ;
if ( V_39 & V_40 ) {
F_14 ( V_33 -> V_122 , V_65 ) ;
F_14 ( V_33 -> V_39 , V_39 & ~ V_40 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
}
F_14 ( V_33 -> V_122 , V_65 ) ;
F_14 ( V_33 -> V_39 , V_39 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
F_14 ( V_33 -> V_39 , V_39 ) ;
F_13 ( V_33 -> V_39 ) ;
F_15 ( 150 ) ;
F_14 ( V_33 -> V_41 , V_67 ) ;
F_13 ( V_33 -> V_41 ) ;
F_17 ( V_6 ) ;
F_14 ( V_33 -> V_43 , V_66 ) ;
F_17 ( V_6 ) ;
V_113:
F_18 ( V_6 ) ;
return 0 ;
}
static bool F_25 ( struct V_2 * V_3 ,
const struct V_59 * V_29 ,
struct V_59 * V_60 )
{
return true ;
}
static int F_26 ( struct V_2 * V_3 ,
int V_61 , int V_62 , struct V_63 * V_64 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_123 * V_124 = F_27 ( V_3 -> V_125 ) ;
int V_31 = V_30 -> V_31 ;
const struct V_32 * V_33 = & V_8 -> V_34 [ V_31 ] ;
unsigned long V_126 , V_127 ;
T_1 V_66 ;
int V_128 = 0 ;
if ( ! V_3 -> V_125 ) {
F_8 ( V_6 -> V_6 , L_8 ) ;
return 0 ;
}
if ( ! F_12 ( V_6 , true ) )
return 0 ;
V_126 = V_124 -> V_129 -> V_127 ;
V_127 = V_62 * V_3 -> V_125 -> V_130 [ 0 ] + V_61 * ( V_3 -> V_125 -> V_131 / 8 ) ;
F_14 ( V_33 -> V_132 , V_3 -> V_125 -> V_130 [ 0 ] ) ;
V_66 = F_13 ( V_33 -> V_43 ) ;
V_66 &= ~ V_133 ;
switch ( V_3 -> V_125 -> V_131 ) {
case 8 :
V_66 |= V_134 ;
break;
case 16 :
if ( V_3 -> V_125 -> V_135 == 15 )
V_66 |= V_136 ;
else
V_66 |= V_137 ;
break;
case 24 :
case 32 :
V_66 |= V_138 ;
break;
default:
F_3 ( V_6 -> V_6 , L_9 ) ;
V_128 = - V_139 ;
goto V_140;
}
F_14 ( V_33 -> V_43 , V_66 ) ;
F_14 ( V_33 -> V_45 , V_127 ) ;
F_13 ( V_33 -> V_45 ) ;
F_14 ( V_33 -> V_141 , V_126 ) ;
F_13 ( V_33 -> V_141 ) ;
V_140:
F_18 ( V_6 ) ;
return V_128 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_106 * V_107 = V_3 -> V_108 ;
V_107 -> V_142 ( V_3 , V_46 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_106 * V_107 = V_3 -> V_108 ;
V_107 -> V_142 ( V_3 , V_36 ) ;
}
