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
V_2 -> V_79 &= ~ V_80 ;
F_1 ( V_2 , V_53 ,
( T_1 * ) V_44 , V_6 ) ;
F_10 ( V_44 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_83 ;
V_82 . V_55 = V_2 -> V_56 -> V_55 ;
V_82 . V_84 = ( 1 << V_2 -> V_48 ) - 1 ;
V_82 . V_85 = V_82 . V_84 ;
V_2 -> V_79 &= ~ V_86 ;
F_1 ( V_2 , V_83 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_87 ;
V_82 . V_55 = V_2 -> V_56 -> V_55 ;
V_82 . V_84 = ( 1 << V_2 -> V_48 ) - 1 ;
V_82 . V_85 = V_82 . V_84 ;
V_2 -> V_79 &= ~ V_88 ;
F_1 ( V_2 , V_87 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
int V_91 , V_92 , V_6 ;
struct V_93 * V_94 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_95 ;
V_92 = V_2 -> V_96 - V_97 ;
V_6 = sizeof( struct V_89 ) +
( V_2 -> V_96 *
sizeof( struct V_98 ) ) ;
V_90 = F_6 ( V_6 , V_54 ) ;
if ( ! V_90 )
return;
V_90 -> V_99 = V_2 -> V_96 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
V_94 = V_2 -> V_94 [ V_91 ] ;
V_90 -> V_100 [ V_91 ] . V_55 = V_2 -> V_56 -> V_55 ;
V_90 -> V_100 [ V_91 ] . V_101 = V_91 + V_97 ;
V_90 -> V_100 [ V_91 ] . V_102 = V_94 -> V_103 ;
V_90 -> V_100 [ V_91 ] . V_104 = V_94 -> V_103 ;
}
V_90 -> V_100 [ V_91 ] . V_55 = V_2 -> V_56 -> V_55 ;
V_90 -> V_100 [ V_91 ] . V_101 = 0 ;
V_90 -> V_100 [ V_91 ] . V_102 = 0 ;
V_90 -> V_100 [ V_91 ] . V_104 = 0 ;
V_2 -> V_79 &= ~ V_105 ;
F_1 ( V_2 , V_95 ,
( T_1 * ) V_90 , V_6 ) ;
F_10 ( V_90 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
struct V_108 * V_109 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> V_110 )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_79 &= ~ V_111 ;
return;
}
V_2 -> V_50 = V_112 ;
V_6 = sizeof( struct V_106 ) +
( V_63 * sizeof( struct V_113 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_106 ) ) /
sizeof( struct V_113 ) ;
V_6 = V_27 ;
}
V_107 = F_6 ( V_6 , V_54 ) ;
if ( ! V_107 )
return;
V_107 -> V_55 = V_2 -> V_56 -> V_55 ;
V_107 -> V_114 = V_63 ;
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> V_110 ) {
F_22 ( V_107 -> V_115 [ V_49 ] . V_116 , V_109 -> V_117 ) ;
V_49 ++ ;
V_109 -> V_110 = false ;
}
}
V_2 -> V_79 &= ~ V_111 ;
F_1 ( V_2 , V_112 ,
( T_1 * ) V_107 , V_6 ) ;
F_10 ( V_107 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 , * V_118 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> remove )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_79 &= ~ V_119 ;
return;
}
V_2 -> V_50 = V_120 ;
V_6 = sizeof( struct V_106 ) +
( V_63 * sizeof( struct V_113 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_106 ) ) /
sizeof( struct V_113 ) ;
V_6 = V_27 ;
}
V_107 = F_6 ( V_6 , V_54 ) ;
if ( ! V_107 )
return;
V_107 -> V_55 = V_2 -> V_56 -> V_55 ;
V_107 -> V_114 = V_63 ;
F_24 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_109 -> remove ) {
F_22 ( V_107 -> V_115 [ V_49 ] . V_116 , V_109 -> V_117 ) ;
V_49 ++ ;
F_25 ( & V_109 -> V_115 ) ;
F_10 ( V_109 ) ;
}
}
V_2 -> V_79 &= ~ V_119 ;
F_1 ( V_2 , V_120 ,
( T_1 * ) V_107 , V_6 ) ;
F_10 ( V_107 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
struct V_123 * V_109 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> V_110 )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_79 &= ~ V_124 ;
return;
}
V_2 -> V_50 = V_125 ;
V_6 = sizeof( struct V_121 ) +
( V_63 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_121 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_122 = F_6 ( V_6 , V_54 ) ;
if ( ! V_122 )
return;
V_122 -> V_55 = V_2 -> V_56 -> V_55 ;
V_122 -> V_114 = V_63 ;
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> V_110 ) {
V_122 -> V_126 [ V_49 ] = V_109 -> V_127 ;
V_49 ++ ;
V_109 -> V_110 = false ;
}
}
V_2 -> V_79 &= ~ V_124 ;
F_1 ( V_2 , V_125 , ( T_1 * ) V_122 , V_6 ) ;
F_10 ( V_122 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
struct V_123 * V_109 , * V_118 ;
int V_6 , V_49 = 0 , V_63 = 0 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
F_20 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> remove )
V_63 ++ ;
}
if ( ! V_63 ) {
V_2 -> V_79 &= ~ V_128 ;
return;
}
V_2 -> V_50 = V_129 ;
V_6 = sizeof( struct V_121 ) +
( V_63 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_21 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_52 ) ;
V_63 = ( V_27 -
sizeof( struct V_121 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_122 = F_6 ( V_6 , V_54 ) ;
if ( ! V_122 )
return;
V_122 -> V_55 = V_2 -> V_56 -> V_55 ;
V_122 -> V_114 = V_63 ;
F_24 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_109 -> remove ) {
V_122 -> V_126 [ V_49 ] = V_109 -> V_127 ;
V_49 ++ ;
F_25 ( & V_109 -> V_115 ) ;
F_10 ( V_109 ) ;
}
}
V_2 -> V_79 &= ~ V_128 ;
F_1 ( V_2 , V_129 , ( T_1 * ) V_122 , V_6 ) ;
F_10 ( V_122 ) ;
}
void F_28 ( struct V_1 * V_2 , int V_10 )
{
struct V_130 V_131 ;
if ( V_2 -> V_50 != V_51 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 , V_2 -> V_50 ) ;
return;
}
V_2 -> V_50 = V_132 ;
V_131 . V_55 = V_2 -> V_56 -> V_55 ;
V_131 . V_10 = V_10 ;
F_1 ( V_2 , V_132 ,
( T_1 * ) & V_131 , sizeof( V_131 ) ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_50 != V_51 ) {
return;
}
V_2 -> V_50 = V_133 ;
V_82 . V_55 = V_2 -> V_56 -> V_55 ;
if ( F_1 ( V_2 , V_133 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) )
V_2 -> V_50 = V_51 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_134 , NULL , 0 ) ;
V_2 -> V_50 = V_51 ;
}
void F_31 ( struct V_1 * V_2 ,
enum V_3 V_135 ,
T_3 V_136 ,
T_1 * V_5 , T_2 V_137 )
{
struct V_138 * V_72 = V_2 -> V_72 ;
if ( V_135 == V_139 ) {
struct V_140 * V_141 =
(struct V_140 * ) V_5 ;
switch ( V_141 -> V_25 ) {
case V_142 :
V_2 -> V_143 =
V_141 -> V_144 . V_145 . V_146 ;
if ( V_2 -> V_143 && ! F_32 ( V_72 ) ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_6 ) ;
F_33 ( V_72 ) ;
F_34 ( V_72 ) ;
} else if ( ! V_2 -> V_143 ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_7 ) ;
F_35 ( V_72 ) ;
F_36 ( V_72 ) ;
}
break;
case V_147 :
F_9 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
if ( ! ( V_2 -> V_10 & V_148 ) ) {
V_2 -> V_10 |= V_148 ;
F_9 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
F_37 ( & V_2 -> V_149 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 ,
L_10 ,
V_52 , V_141 -> V_25 ) ;
break;
}
return;
}
if ( V_136 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_52 , V_136 , V_135 ) ;
}
switch ( V_135 ) {
case V_133 : {
struct V_150 * V_151 =
(struct V_150 * ) V_5 ;
V_2 -> V_152 . V_153 = V_151 -> V_154 +
V_151 -> V_155 +
V_151 -> V_156 ;
V_2 -> V_152 . V_157 = V_151 -> V_158 +
V_151 -> V_159 +
V_151 -> V_160 ;
V_2 -> V_152 . V_161 = V_151 -> V_161 ;
V_2 -> V_152 . V_162 = V_151 -> V_162 ;
V_2 -> V_152 . V_163 = V_151 -> V_163 ;
V_2 -> V_152 . V_164 = V_151 -> V_165 ;
V_2 -> V_152 . V_166 = V_151 -> V_167 ;
V_2 -> V_168 = * V_151 ;
}
break;
case V_83 :
F_38 ( V_2 , true ) ;
F_39 ( V_2 -> V_72 ) ;
F_33 ( V_2 -> V_72 ) ;
break;
case V_87 :
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
break;
case V_22 :
case V_37 :
case V_95 :
if ( V_135 != V_2 -> V_50 )
return;
break;
default:
if ( V_135 != V_2 -> V_50 )
F_21 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_2 -> V_50 , V_135 ) ;
break;
}
V_2 -> V_50 = V_51 ;
}
