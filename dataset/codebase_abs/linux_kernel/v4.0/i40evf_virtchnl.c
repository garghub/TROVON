static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_3 V_9 ;
if ( V_2 -> V_10 & V_11 )
return 0 ;
V_9 = F_2 ( V_8 , V_4 , 0 , V_5 , V_6 , NULL ) ;
if ( V_9 )
F_3 ( & V_2 -> V_12 -> V_13 , L_1 ,
V_4 , V_9 , V_8 -> V_14 . V_15 ) ;
return V_9 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
V_17 . V_18 = V_19 ;
V_17 . V_20 = V_21 ;
return F_1 ( V_2 , V_22 , ( T_1 * ) & V_17 ,
sizeof( V_17 ) ) ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_16 * V_23 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_24 V_25 ;
enum V_3 V_4 ;
T_3 V_9 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = F_6 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
while ( 1 ) {
V_9 = F_7 ( V_8 , & V_25 , NULL ) ;
if ( V_9 )
goto V_32;
V_4 =
(enum V_3 ) F_8 ( V_25 . V_33 . V_34 ) ;
if ( V_4 == V_22 )
break;
}
V_9 = ( T_3 ) F_8 ( V_25 . V_33 . V_35 ) ;
if ( V_9 )
goto V_32;
if ( V_4 != V_22 ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_2 ,
V_4 ) ;
V_9 = - V_36 ;
goto V_32;
}
V_23 = (struct V_16 * ) V_25 . V_28 ;
if ( ( V_23 -> V_18 != V_19 ) ||
( V_23 -> V_20 != V_21 ) )
V_9 = - V_36 ;
V_32:
F_10 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_37 ,
NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_24 V_25 ;
enum V_3 V_4 ;
T_3 V_9 ;
T_2 V_6 ;
V_6 = sizeof( struct V_38 ) +
V_39 * sizeof( struct V_40 ) ;
V_25 . V_26 = V_6 ;
V_25 . V_28 = F_6 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
while ( 1 ) {
V_9 = F_7 ( V_8 , & V_25 , NULL ) ;
if ( V_9 )
goto V_32;
V_4 =
(enum V_3 ) F_8 ( V_25 . V_33 . V_34 ) ;
if ( V_4 == V_37 )
break;
}
V_9 = ( T_3 ) F_8 ( V_25 . V_33 . V_35 ) ;
memcpy ( V_2 -> V_41 , V_25 . V_28 , F_13 ( V_25 . V_42 , V_6 ) ) ;
F_14 ( V_8 , V_2 -> V_41 ) ;
V_32:
F_10 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_47 = V_2 -> V_48 ;
int V_49 , V_6 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_53 ;
V_6 = sizeof( struct V_43 ) +
( sizeof( struct V_45 ) * V_47 ) ;
V_44 = F_6 ( V_6 , V_54 ) ;
if ( ! V_44 )
return;
V_44 -> V_55 = V_2 -> V_56 -> V_55 ;
V_44 -> V_57 = V_47 ;
V_46 = V_44 -> V_58 ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_46 -> V_59 . V_55 = V_44 -> V_55 ;
V_46 -> V_59 . V_60 = V_49 ;
V_46 -> V_59 . V_61 = V_2 -> V_62 [ V_49 ] -> V_63 ;
V_46 -> V_59 . V_64 = V_2 -> V_62 [ V_49 ] -> V_65 ;
V_46 -> V_59 . V_66 = 1 ;
V_46 -> V_59 . V_67 = V_46 -> V_59 . V_64 +
( V_46 -> V_59 . V_61 * sizeof( struct V_68 ) ) ;
V_46 -> V_69 . V_55 = V_44 -> V_55 ;
V_46 -> V_69 . V_60 = V_49 ;
V_46 -> V_69 . V_61 = V_2 -> V_70 [ V_49 ] -> V_63 ;
V_46 -> V_69 . V_64 = V_2 -> V_70 [ V_49 ] -> V_65 ;
V_46 -> V_69 . V_71 = V_2 -> V_72 -> V_73
+ V_74 + V_75 + V_76 ;
V_46 -> V_69 . V_77 = V_2 -> V_70 [ V_49 ] -> V_78 ;
V_46 ++ ;
}
V_2 -> V_79 |= V_80 ;
V_2 -> V_81 &= ~ V_80 ;
F_1 ( V_2 , V_53 ,
( T_1 * ) V_44 , V_6 ) ;
F_10 ( V_44 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_84 ;
V_83 . V_55 = V_2 -> V_56 -> V_55 ;
V_83 . V_85 = ( 1 << V_2 -> V_48 ) - 1 ;
V_83 . V_86 = V_83 . V_85 ;
V_2 -> V_79 |= V_87 ;
V_2 -> V_81 &= ~ V_87 ;
F_1 ( V_2 , V_84 ,
( T_1 * ) & V_83 , sizeof( V_83 ) ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_88 ;
V_83 . V_55 = V_2 -> V_56 -> V_55 ;
V_83 . V_85 = ( 1 << V_2 -> V_48 ) - 1 ;
V_83 . V_86 = V_83 . V_85 ;
V_2 -> V_79 |= V_89 ;
V_2 -> V_81 &= ~ V_89 ;
F_1 ( V_2 , V_88 ,
( T_1 * ) & V_83 , sizeof( V_83 ) ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
int V_92 , V_93 , V_6 ;
struct V_94 * V_95 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_96 ;
V_93 = V_2 -> V_97 - V_98 ;
V_6 = sizeof( struct V_90 ) +
( V_2 -> V_97 *
sizeof( struct V_99 ) ) ;
V_91 = F_6 ( V_6 , V_54 ) ;
if ( ! V_91 )
return;
V_91 -> V_100 = V_2 -> V_97 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_95 = V_2 -> V_95 [ V_92 ] ;
V_91 -> V_101 [ V_92 ] . V_55 = V_2 -> V_56 -> V_55 ;
V_91 -> V_101 [ V_92 ] . V_102 = V_92 + V_98 ;
V_91 -> V_101 [ V_92 ] . V_103 = V_95 -> V_104 ;
V_91 -> V_101 [ V_92 ] . V_105 = V_95 -> V_104 ;
}
V_91 -> V_101 [ V_92 ] . V_55 = V_2 -> V_56 -> V_55 ;
V_91 -> V_101 [ V_92 ] . V_102 = 0 ;
V_91 -> V_101 [ V_92 ] . V_103 = 0 ;
V_91 -> V_101 [ V_92 ] . V_105 = 0 ;
V_2 -> V_79 |= V_106 ;
V_2 -> V_81 &= ~ V_106 ;
F_1 ( V_2 , V_96 ,
( T_1 * ) V_91 , V_6 ) ;
F_10 ( V_91 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_107 * V_108 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
struct V_109 * V_110 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_110 -> V_111 )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_81 &= ~ V_112 ;
return;
}
V_2 -> V_50 = V_113 ;
V_6 = sizeof( struct V_107 ) +
( V_63 * sizeof( struct V_114 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_107 ) ) /
sizeof( struct V_114 ) ;
V_6 = V_27 ;
}
V_108 = F_6 ( V_6 , V_54 ) ;
if ( ! V_108 )
return;
V_108 -> V_55 = V_2 -> V_56 -> V_55 ;
V_108 -> V_115 = V_63 ;
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_110 -> V_111 ) {
F_22 ( V_108 -> V_116 [ V_49 ] . V_117 , V_110 -> V_118 ) ;
V_49 ++ ;
V_110 -> V_111 = false ;
}
}
V_2 -> V_79 |= V_112 ;
V_2 -> V_81 &= ~ V_112 ;
F_1 ( V_2 , V_113 ,
( T_1 * ) V_108 , V_6 ) ;
F_10 ( V_108 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 , * V_119 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_110 -> remove )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_81 &= ~ V_120 ;
return;
}
V_2 -> V_50 = V_121 ;
V_6 = sizeof( struct V_107 ) +
( V_63 * sizeof( struct V_114 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_107 ) ) /
sizeof( struct V_114 ) ;
V_6 = V_27 ;
}
V_108 = F_6 ( V_6 , V_54 ) ;
if ( ! V_108 )
return;
V_108 -> V_55 = V_2 -> V_56 -> V_55 ;
V_108 -> V_115 = V_63 ;
F_24 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_110 -> remove ) {
F_22 ( V_108 -> V_116 [ V_49 ] . V_117 , V_110 -> V_118 ) ;
V_49 ++ ;
F_25 ( & V_110 -> V_116 ) ;
F_10 ( V_110 ) ;
}
}
V_2 -> V_79 |= V_120 ;
V_2 -> V_81 &= ~ V_120 ;
F_1 ( V_2 , V_121 ,
( T_1 * ) V_108 , V_6 ) ;
F_10 ( V_108 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
struct V_124 * V_110 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_110 -> V_111 )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_81 &= ~ V_125 ;
return;
}
V_2 -> V_50 = V_126 ;
V_6 = sizeof( struct V_122 ) +
( V_63 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_122 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_123 = F_6 ( V_6 , V_54 ) ;
if ( ! V_123 )
return;
V_123 -> V_55 = V_2 -> V_56 -> V_55 ;
V_123 -> V_115 = V_63 ;
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_110 -> V_111 ) {
V_123 -> V_127 [ V_49 ] = V_110 -> V_128 ;
V_49 ++ ;
V_110 -> V_111 = false ;
}
}
V_2 -> V_79 |= V_125 ;
V_2 -> V_81 &= ~ V_125 ;
F_1 ( V_2 , V_126 , ( T_1 * ) V_123 , V_6 ) ;
F_10 ( V_123 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_124 * V_110 , * V_119 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_110 -> remove )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_81 &= ~ V_129 ;
return;
}
V_2 -> V_50 = V_130 ;
V_6 = sizeof( struct V_122 ) +
( V_63 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_122 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_123 = F_6 ( V_6 , V_54 ) ;
if ( ! V_123 )
return;
V_123 -> V_55 = V_2 -> V_56 -> V_55 ;
V_123 -> V_115 = V_63 ;
F_24 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_110 -> remove ) {
V_123 -> V_127 [ V_49 ] = V_110 -> V_128 ;
V_49 ++ ;
F_25 ( & V_110 -> V_116 ) ;
F_10 ( V_110 ) ;
}
}
V_2 -> V_79 |= V_129 ;
V_2 -> V_81 &= ~ V_129 ;
F_1 ( V_2 , V_130 , ( T_1 * ) V_123 , V_6 ) ;
F_10 ( V_123 ) ;
}
void F_28 ( struct V_1 * V_2 , int V_10 )
{
struct V_131 V_132 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_133 ;
V_132 . V_55 = V_2 -> V_56 -> V_55 ;
V_132 . V_10 = V_10 ;
F_1 ( V_2 , V_133 ,
( T_1 * ) & V_132 , sizeof( V_132 ) ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
if ( V_2 -> V_50 != V_51 ) {
return;
}
V_2 -> V_50 = V_134 ;
V_83 . V_55 = V_2 -> V_56 -> V_55 ;
if ( F_1 ( V_2 , V_134 ,
( T_1 * ) & V_83 , sizeof( V_83 ) ) )
V_2 -> V_50 = V_51 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_135 , NULL , 0 ) ;
V_2 -> V_50 = V_51 ;
}
void F_31 ( struct V_1 * V_2 ,
enum V_3 V_136 ,
T_3 V_137 ,
T_1 * V_5 , T_2 V_138 )
{
struct V_139 * V_72 = V_2 -> V_72 ;
if ( V_136 == V_140 ) {
struct V_141 * V_142 =
(struct V_141 * ) V_5 ;
switch ( V_142 -> V_25 ) {
case V_143 :
V_2 -> V_144 =
V_142 -> V_145 . V_146 . V_147 ;
if ( V_2 -> V_144 && ! F_32 ( V_72 ) ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_6 ) ;
F_33 ( V_72 ) ;
F_34 ( V_72 ) ;
} else if ( ! V_2 -> V_144 ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_7 ) ;
F_35 ( V_72 ) ;
F_36 ( V_72 ) ;
}
break;
case V_148 :
F_9 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
if ( ! ( V_2 -> V_10 & V_149 ) ) {
V_2 -> V_10 |= V_149 ;
F_9 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
F_37 ( & V_2 -> V_150 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 ,
L_10 ,
V_52 , V_142 -> V_25 ) ;
break;
}
return;
}
if ( V_137 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_52 , V_137 , V_136 ) ;
}
switch ( V_136 ) {
case V_22 :
break;
case V_134 : {
struct V_151 * V_152 =
(struct V_151 * ) V_5 ;
V_2 -> V_153 . V_154 = V_152 -> V_155 +
V_152 -> V_156 +
V_152 -> V_157 ;
V_2 -> V_153 . V_158 = V_152 -> V_159 +
V_152 -> V_160 +
V_152 -> V_161 ;
V_2 -> V_153 . V_162 = V_152 -> V_162 ;
V_2 -> V_153 . V_163 = V_152 -> V_163 ;
V_2 -> V_153 . V_164 = V_152 -> V_164 ;
V_2 -> V_153 . V_165 = V_152 -> V_166 ;
V_2 -> V_153 . V_167 = V_152 -> V_168 ;
V_2 -> V_169 = * V_152 ;
}
break;
case V_113 :
V_2 -> V_79 &= ~ ( V_112 ) ;
break;
case V_121 :
V_2 -> V_79 &= ~ ( V_120 ) ;
break;
case V_126 :
V_2 -> V_79 &= ~ ( V_125 ) ;
break;
case V_130 :
V_2 -> V_79 &= ~ ( V_129 ) ;
break;
case V_84 :
V_2 -> V_79 &= ~ ( V_87 ) ;
F_38 ( V_2 , true ) ;
F_39 ( V_2 -> V_72 ) ;
F_33 ( V_2 -> V_72 ) ;
break;
case V_88 :
V_2 -> V_79 &= ~ ( V_89 ) ;
break;
case V_53 :
V_2 -> V_79 &= ~ ( V_80 ) ;
break;
case V_96 :
V_2 -> V_79 &= ~ ( V_106 ) ;
break;
default:
F_9 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_136 ) ;
break;
}
V_2 -> V_50 = V_51 ;
}
