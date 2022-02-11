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
T_3 V_9 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = F_6 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
V_9 = F_7 ( V_8 , & V_25 , NULL ) ;
if ( V_9 == V_32 )
goto V_33;
V_9 = ( T_3 ) F_8 ( V_25 . V_34 . V_35 ) ;
if ( V_9 ) {
V_9 = - V_36 ;
goto V_33;
}
if ( (enum V_3 ) F_8 ( V_25 . V_34 . V_37 ) !=
V_22 ) {
V_9 = - V_36 ;
goto V_33;
}
V_23 = (struct V_16 * ) V_25 . V_28 ;
if ( ( V_23 -> V_18 != V_19 ) ||
( V_23 -> V_20 != V_21 ) )
V_9 = - V_36 ;
V_33:
F_9 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_38 ,
NULL , 0 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_24 V_25 ;
T_2 V_6 ;
T_3 V_9 ;
V_6 = sizeof( struct V_39 ) +
V_40 * sizeof( struct V_41 ) ;
V_25 . V_26 = V_6 ;
V_25 . V_28 = F_6 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
V_9 = F_7 ( V_8 , & V_25 , NULL ) ;
if ( V_9 == V_32 )
goto V_33;
V_9 = ( T_3 ) F_8 ( V_25 . V_34 . V_35 ) ;
if ( V_9 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_2 , V_42 ,
F_8 ( V_25 . V_34 . V_37 ) ,
F_8 ( V_25 . V_34 . V_35 ) ) ;
V_9 = - V_36 ;
goto V_33;
}
if ( (enum V_3 ) F_8 ( V_25 . V_34 . V_37 ) !=
V_38 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_3 , V_42 ,
F_8 ( V_25 . V_34 . V_37 ) ,
F_8 ( V_25 . V_34 . V_35 ) ) ;
V_9 = - V_36 ;
goto V_33;
}
memcpy ( V_2 -> V_43 , V_25 . V_28 , F_12 ( V_25 . V_26 , V_6 ) ) ;
F_13 ( V_8 , V_2 -> V_43 ) ;
V_33:
F_9 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_48 = V_2 -> V_49 -> V_50 ;
int V_51 , V_6 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
V_2 -> V_52 = V_54 ;
V_6 = sizeof( struct V_44 ) +
( sizeof( struct V_46 ) * V_48 ) ;
V_45 = F_6 ( V_6 , V_55 ) ;
if ( ! V_45 )
return;
V_45 -> V_56 = V_2 -> V_49 -> V_56 ;
V_45 -> V_50 = V_48 ;
V_47 = V_45 -> V_57 ;
for ( V_51 = 0 ; V_51 < V_48 ; V_51 ++ ) {
V_47 -> V_58 . V_56 = V_45 -> V_56 ;
V_47 -> V_58 . V_59 = V_51 ;
V_47 -> V_58 . V_60 = V_2 -> V_61 [ V_51 ] -> V_62 ;
V_47 -> V_58 . V_63 = V_2 -> V_61 [ V_51 ] -> V_64 ;
V_47 -> V_58 . V_65 = 1 ;
V_47 -> V_58 . V_66 = V_47 -> V_58 . V_63 +
( V_47 -> V_58 . V_60 * sizeof( struct V_67 ) ) ;
V_47 -> V_68 . V_56 = V_45 -> V_56 ;
V_47 -> V_68 . V_59 = V_51 ;
V_47 -> V_68 . V_60 = V_2 -> V_69 [ V_51 ] -> V_62 ;
V_47 -> V_68 . V_63 = V_2 -> V_69 [ V_51 ] -> V_64 ;
V_47 -> V_68 . V_70 = V_2 -> V_71 -> V_72
+ V_73 + V_74 + V_75 ;
V_47 -> V_68 . V_76 = V_2 -> V_69 [ V_51 ] -> V_77 ;
V_47 ++ ;
}
F_1 ( V_2 , V_54 ,
( T_1 * ) V_45 , V_6 ) ;
F_9 ( V_45 ) ;
V_2 -> V_78 |= V_79 ;
V_2 -> V_80 &= ~ V_79 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
V_2 -> V_52 = V_83 ;
V_82 . V_56 = V_2 -> V_49 -> V_56 ;
V_82 . V_84 = ( 1 << V_2 -> V_49 -> V_50 ) - 1 ;
V_82 . V_85 = V_82 . V_84 ;
F_1 ( V_2 , V_83 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) ;
V_2 -> V_78 |= V_86 ;
V_2 -> V_80 &= ~ V_86 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
V_2 -> V_52 = V_87 ;
V_82 . V_56 = V_2 -> V_49 -> V_56 ;
V_82 . V_84 = ( 1 << V_2 -> V_49 -> V_50 ) - 1 ;
V_82 . V_85 = V_82 . V_84 ;
F_1 ( V_2 , V_87 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) ;
V_2 -> V_78 |= V_88 ;
V_2 -> V_80 &= ~ V_88 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
int V_91 , V_92 , V_6 ;
struct V_93 * V_94 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
V_2 -> V_52 = V_95 ;
V_92 = V_2 -> V_96 - V_97 ;
V_6 = sizeof( struct V_89 ) +
( V_2 -> V_96 *
sizeof( struct V_98 ) ) ;
V_90 = F_6 ( V_6 , V_55 ) ;
if ( ! V_90 )
return;
V_90 -> V_99 = V_2 -> V_96 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
V_94 = V_2 -> V_94 [ V_91 ] ;
V_90 -> V_100 [ V_91 ] . V_56 = V_2 -> V_49 -> V_56 ;
V_90 -> V_100 [ V_91 ] . V_101 = V_91 + V_97 ;
V_90 -> V_100 [ V_91 ] . V_102 = V_94 -> V_103 ;
V_90 -> V_100 [ V_91 ] . V_104 = V_94 -> V_103 ;
}
V_90 -> V_100 [ V_91 ] . V_56 = V_2 -> V_49 -> V_56 ;
V_90 -> V_100 [ V_91 ] . V_101 = 0 ;
V_90 -> V_100 [ V_91 ] . V_102 = 0 ;
V_90 -> V_100 [ V_91 ] . V_104 = 0 ;
F_1 ( V_2 , V_95 ,
( T_1 * ) V_90 , V_6 ) ;
F_9 ( V_90 ) ;
V_2 -> V_78 |= V_105 ;
V_2 -> V_80 &= ~ V_105 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
int V_6 , V_51 = 0 , V_62 = 0 ;
struct V_108 * V_109 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
F_19 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> V_110 )
V_62 ++ ;
}
if ( ! V_62 ) {
V_2 -> V_80 &= ~ V_111 ;
return;
}
V_2 -> V_52 = V_112 ;
V_6 = sizeof( struct V_106 ) +
( V_62 * sizeof( struct V_113 ) ) ;
if ( V_6 > V_27 ) {
F_20 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_42 ) ;
V_62 = ( V_27 -
sizeof( struct V_106 ) ) /
sizeof( struct V_113 ) ;
V_6 = V_27 ;
}
V_107 = F_6 ( V_6 , V_55 ) ;
if ( ! V_107 )
return;
V_107 -> V_56 = V_2 -> V_49 -> V_56 ;
V_107 -> V_114 = V_62 ;
F_19 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> V_110 ) {
F_21 ( V_107 -> V_115 [ V_51 ] . V_116 , V_109 -> V_117 ) ;
V_51 ++ ;
V_109 -> V_110 = false ;
}
}
F_1 ( V_2 , V_112 ,
( T_1 * ) V_107 , V_6 ) ;
F_9 ( V_107 ) ;
V_2 -> V_78 |= V_111 ;
V_2 -> V_80 &= ~ V_111 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 , * V_118 ;
int V_6 , V_51 = 0 , V_62 = 0 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
F_19 (f, &adapter->mac_filter_list, list) {
if ( V_109 -> remove )
V_62 ++ ;
}
if ( ! V_62 ) {
V_2 -> V_80 &= ~ V_119 ;
return;
}
V_2 -> V_52 = V_120 ;
V_6 = sizeof( struct V_106 ) +
( V_62 * sizeof( struct V_113 ) ) ;
if ( V_6 > V_27 ) {
F_20 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_42 ) ;
V_62 = ( V_27 -
sizeof( struct V_106 ) ) /
sizeof( struct V_113 ) ;
V_6 = V_27 ;
}
V_107 = F_6 ( V_6 , V_55 ) ;
if ( ! V_107 )
return;
V_107 -> V_56 = V_2 -> V_49 -> V_56 ;
V_107 -> V_114 = V_62 ;
F_23 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_109 -> remove ) {
F_21 ( V_107 -> V_115 [ V_51 ] . V_116 , V_109 -> V_117 ) ;
V_51 ++ ;
F_24 ( & V_109 -> V_115 ) ;
F_9 ( V_109 ) ;
}
}
F_1 ( V_2 , V_120 ,
( T_1 * ) V_107 , V_6 ) ;
F_9 ( V_107 ) ;
V_2 -> V_78 |= V_119 ;
V_2 -> V_80 &= ~ V_119 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
int V_6 , V_51 = 0 , V_62 = 0 ;
struct V_123 * V_109 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
F_19 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> V_110 )
V_62 ++ ;
}
if ( ! V_62 ) {
V_2 -> V_80 &= ~ V_124 ;
return;
}
V_2 -> V_52 = V_125 ;
V_6 = sizeof( struct V_121 ) +
( V_62 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_20 ( & V_2 -> V_12 -> V_13 , L_6 ,
V_42 ) ;
V_62 = ( V_27 -
sizeof( struct V_121 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_122 = F_6 ( V_6 , V_55 ) ;
if ( ! V_122 )
return;
V_122 -> V_56 = V_2 -> V_49 -> V_56 ;
V_122 -> V_114 = V_62 ;
F_19 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> V_110 ) {
V_122 -> V_126 [ V_51 ] = V_109 -> V_127 ;
V_51 ++ ;
V_109 -> V_110 = false ;
}
}
F_1 ( V_2 , V_125 , ( T_1 * ) V_122 , V_6 ) ;
F_9 ( V_122 ) ;
V_2 -> V_78 |= V_124 ;
V_2 -> V_80 &= ~ V_124 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
struct V_123 * V_109 , * V_118 ;
int V_6 , V_51 = 0 , V_62 = 0 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
F_19 (f, &adapter->vlan_filter_list, list) {
if ( V_109 -> remove )
V_62 ++ ;
}
if ( ! V_62 ) {
V_2 -> V_80 &= ~ V_128 ;
return;
}
V_2 -> V_52 = V_129 ;
V_6 = sizeof( struct V_121 ) +
( V_62 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_20 ( & V_2 -> V_12 -> V_13 , L_6 ,
V_42 ) ;
V_62 = ( V_27 -
sizeof( struct V_121 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_122 = F_6 ( V_6 , V_55 ) ;
if ( ! V_122 )
return;
V_122 -> V_56 = V_2 -> V_49 -> V_56 ;
V_122 -> V_114 = V_62 ;
F_23 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_109 -> remove ) {
V_122 -> V_126 [ V_51 ] = V_109 -> V_127 ;
V_51 ++ ;
F_24 ( & V_109 -> V_115 ) ;
F_9 ( V_109 ) ;
}
}
F_1 ( V_2 , V_129 , ( T_1 * ) V_122 , V_6 ) ;
F_9 ( V_122 ) ;
V_2 -> V_78 |= V_128 ;
V_2 -> V_80 &= ~ V_128 ;
}
void F_27 ( struct V_1 * V_2 , int V_10 )
{
struct V_130 V_131 ;
if ( V_2 -> V_52 != V_53 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_42 , V_2 -> V_52 ) ;
return;
}
V_2 -> V_52 = V_132 ;
V_131 . V_56 = V_2 -> V_49 -> V_56 ;
V_131 . V_10 = V_10 ;
F_1 ( V_2 , V_132 ,
( T_1 * ) & V_131 , sizeof( V_131 ) ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
if ( V_2 -> V_52 != V_53 ) {
return;
}
V_2 -> V_52 = V_133 ;
V_82 . V_56 = V_2 -> V_49 -> V_56 ;
if ( F_1 ( V_2 , V_133 ,
( T_1 * ) & V_82 , sizeof( V_82 ) ) )
V_2 -> V_52 = V_53 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_134 , NULL , 0 ) ;
V_2 -> V_52 = V_53 ;
}
void F_30 ( struct V_1 * V_2 ,
enum V_3 V_135 ,
T_3 V_136 ,
T_1 * V_5 , T_2 V_137 )
{
struct V_138 * V_71 = V_2 -> V_71 ;
if ( V_135 == V_139 ) {
struct V_140 * V_141 =
(struct V_140 * ) V_5 ;
switch ( V_141 -> V_25 ) {
case V_142 :
V_2 -> V_143 =
V_141 -> V_144 . V_145 . V_146 ;
if ( V_2 -> V_143 && ! F_31 ( V_71 ) ) {
F_32 ( & V_2 -> V_12 -> V_13 , L_7 ) ;
F_33 ( V_71 ) ;
F_34 ( V_71 ) ;
} else if ( ! V_2 -> V_143 ) {
F_32 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
F_35 ( V_71 ) ;
F_36 ( V_71 ) ;
}
break;
case V_147 :
F_32 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
if ( ! ( V_2 -> V_10 & V_148 ) ) {
V_2 -> V_10 |= V_148 ;
F_32 ( & V_2 -> V_12 -> V_13 , L_10 ) ;
F_37 ( & V_2 -> V_149 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 ,
L_11 ,
V_42 , V_141 -> V_25 ) ;
break;
}
return;
}
if ( V_135 != V_2 -> V_52 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_42 , V_2 -> V_52 , V_135 ) ;
V_2 -> V_52 = V_53 ;
return;
}
if ( V_136 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_42 , V_136 , V_135 ) ;
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
case V_112 :
V_2 -> V_78 &= ~ ( V_111 ) ;
break;
case V_120 :
V_2 -> V_78 &= ~ ( V_119 ) ;
break;
case V_125 :
V_2 -> V_78 &= ~ ( V_124 ) ;
break;
case V_129 :
V_2 -> V_78 &= ~ ( V_128 ) ;
break;
case V_83 :
V_2 -> V_78 &= ~ ( V_86 ) ;
F_38 ( V_2 , true ) ;
F_39 ( V_2 -> V_71 ) ;
F_33 ( V_2 -> V_71 ) ;
break;
case V_87 :
V_2 -> V_78 &= ~ ( V_88 ) ;
break;
case V_54 :
V_2 -> V_78 &= ~ ( V_79 ) ;
break;
case V_95 :
V_2 -> V_78 &= ~ ( V_105 ) ;
break;
default:
F_20 ( & V_2 -> V_12 -> V_13 , L_14 ,
V_42 , V_135 ) ;
break;
}
V_2 -> V_52 = V_53 ;
}
