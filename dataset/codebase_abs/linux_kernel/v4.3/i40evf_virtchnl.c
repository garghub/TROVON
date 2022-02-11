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
V_4 , F_4 ( V_8 , V_9 ) ,
F_5 ( V_8 , V_8 -> V_14 . V_15 ) ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
V_17 . V_18 = V_19 ;
V_17 . V_20 = V_21 ;
return F_1 ( V_2 , V_22 , ( T_1 * ) & V_17 ,
sizeof( V_17 ) ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_23 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_24 V_25 ;
enum V_3 V_4 ;
T_3 V_9 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = F_8 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
while ( 1 ) {
V_9 = F_9 ( V_8 , & V_25 , NULL ) ;
if ( V_9 )
goto V_32;
V_4 =
(enum V_3 ) F_10 ( V_25 . V_33 . V_34 ) ;
if ( V_4 == V_22 )
break;
}
V_9 = ( T_3 ) F_10 ( V_25 . V_33 . V_35 ) ;
if ( V_9 )
goto V_32;
if ( V_4 != V_22 ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_2 ,
V_4 ) ;
V_9 = - V_36 ;
goto V_32;
}
V_23 = (struct V_16 * ) V_25 . V_28 ;
V_2 -> V_37 = * V_23 ;
if ( ( V_23 -> V_18 > V_19 ) ||
( ( V_23 -> V_18 == V_19 ) &&
( V_23 -> V_20 > V_21 ) ) )
V_9 = - V_36 ;
V_32:
F_12 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
int F_13 ( struct V_1 * V_2 )
{
T_4 V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 &= ~ V_42 ;
V_38 = V_43 |
V_44 |
V_45 |
V_46 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 &= ~ V_42 ;
if ( F_14 ( V_2 ) )
return F_1 ( V_2 ,
V_40 ,
( T_1 * ) & V_38 , sizeof( V_38 ) ) ;
else
return F_1 ( V_2 ,
V_40 ,
NULL , 0 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_24 V_25 ;
enum V_3 V_4 ;
T_3 V_9 ;
T_2 V_6 ;
V_6 = sizeof( struct V_47 ) +
V_48 * sizeof( struct V_49 ) ;
V_25 . V_26 = V_6 ;
V_25 . V_28 = F_8 ( V_25 . V_26 , V_29 ) ;
if ( ! V_25 . V_28 ) {
V_9 = - V_30 ;
goto V_31;
}
while ( 1 ) {
V_9 = F_9 ( V_8 , & V_25 , NULL ) ;
if ( V_9 )
goto V_32;
V_4 =
(enum V_3 ) F_10 ( V_25 . V_33 . V_34 ) ;
if ( V_4 == V_40 )
break;
}
V_9 = ( T_3 ) F_10 ( V_25 . V_33 . V_35 ) ;
memcpy ( V_2 -> V_50 , V_25 . V_28 , F_16 ( V_25 . V_51 , V_6 ) ) ;
F_17 ( V_8 , V_2 -> V_50 ) ;
V_32:
F_12 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 = V_2 -> V_57 ;
int V_58 , V_6 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_61 ;
V_6 = sizeof( struct V_52 ) +
( sizeof( struct V_54 ) * V_56 ) ;
V_53 = F_8 ( V_6 , V_62 ) ;
if ( ! V_53 )
return;
V_53 -> V_63 = V_2 -> V_64 -> V_63 ;
V_53 -> V_65 = V_56 ;
V_55 = V_53 -> V_66 ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
V_55 -> V_67 . V_63 = V_53 -> V_63 ;
V_55 -> V_67 . V_68 = V_58 ;
V_55 -> V_67 . V_69 = V_2 -> V_70 [ V_58 ] -> V_71 ;
V_55 -> V_67 . V_72 = V_2 -> V_70 [ V_58 ] -> V_73 ;
V_55 -> V_67 . V_74 = 1 ;
V_55 -> V_67 . V_75 = V_55 -> V_67 . V_72 +
( V_55 -> V_67 . V_69 * sizeof( struct V_76 ) ) ;
V_55 -> V_77 . V_63 = V_53 -> V_63 ;
V_55 -> V_77 . V_68 = V_58 ;
V_55 -> V_77 . V_69 = V_2 -> V_78 [ V_58 ] -> V_71 ;
V_55 -> V_77 . V_72 = V_2 -> V_78 [ V_58 ] -> V_73 ;
V_55 -> V_77 . V_79 = V_2 -> V_80 -> V_81
+ V_82 + V_83 + V_84 ;
V_55 -> V_77 . V_85 = V_2 -> V_78 [ V_58 ] -> V_86 ;
V_55 ++ ;
}
V_2 -> V_41 &= ~ V_87 ;
F_1 ( V_2 , V_61 ,
( T_1 * ) V_53 , V_6 ) ;
F_12 ( V_53 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_90 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
V_89 . V_91 = F_20 ( V_2 -> V_57 ) - 1 ;
V_89 . V_92 = V_89 . V_91 ;
V_2 -> V_41 &= ~ V_93 ;
F_1 ( V_2 , V_90 ,
( T_1 * ) & V_89 , sizeof( V_89 ) ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_94 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
V_89 . V_91 = F_20 ( V_2 -> V_57 ) - 1 ;
V_89 . V_92 = V_89 . V_91 ;
V_2 -> V_41 &= ~ V_95 ;
F_1 ( V_2 , V_94 ,
( T_1 * ) & V_89 , sizeof( V_89 ) ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_98 , V_99 , V_6 ;
struct V_100 * V_101 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_102 ;
V_99 = V_2 -> V_103 - V_104 ;
V_6 = sizeof( struct V_96 ) +
( V_2 -> V_103 *
sizeof( struct V_105 ) ) ;
V_97 = F_8 ( V_6 , V_62 ) ;
if ( ! V_97 )
return;
V_97 -> V_106 = V_2 -> V_103 ;
for ( V_98 = 0 ; V_98 < V_99 ; V_98 ++ ) {
V_101 = V_2 -> V_101 [ V_98 ] ;
V_97 -> V_107 [ V_98 ] . V_63 = V_2 -> V_64 -> V_63 ;
V_97 -> V_107 [ V_98 ] . V_108 = V_98 + V_104 ;
V_97 -> V_107 [ V_98 ] . V_109 = V_101 -> V_110 ;
V_97 -> V_107 [ V_98 ] . V_111 = V_101 -> V_110 ;
}
V_97 -> V_107 [ V_98 ] . V_63 = V_2 -> V_64 -> V_63 ;
V_97 -> V_107 [ V_98 ] . V_108 = 0 ;
V_97 -> V_107 [ V_98 ] . V_109 = 0 ;
V_97 -> V_107 [ V_98 ] . V_111 = 0 ;
V_2 -> V_41 &= ~ V_112 ;
F_1 ( V_2 , V_102 ,
( T_1 * ) V_97 , V_6 ) ;
F_12 ( V_97 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
int V_6 , V_58 = 0 , V_71 = 0 ;
struct V_115 * V_116 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> V_117 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_118 ;
return;
}
V_2 -> V_39 = V_119 ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_120 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_60 ) ;
V_71 = ( V_27 -
sizeof( struct V_113 ) ) /
sizeof( struct V_120 ) ;
V_6 = V_27 ;
}
V_114 = F_8 ( V_6 , V_62 ) ;
if ( ! V_114 )
return;
V_114 -> V_63 = V_2 -> V_64 -> V_63 ;
V_114 -> V_121 = V_71 ;
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> V_117 ) {
F_26 ( V_114 -> V_122 [ V_58 ] . V_123 , V_116 -> V_124 ) ;
V_58 ++ ;
V_116 -> V_117 = false ;
}
}
V_2 -> V_41 &= ~ V_118 ;
F_1 ( V_2 , V_119 ,
( T_1 * ) V_114 , V_6 ) ;
F_12 ( V_114 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 , * V_125 ;
int V_6 , V_58 = 0 , V_71 = 0 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_126 ;
return;
}
V_2 -> V_39 = V_127 ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_120 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_60 ) ;
V_71 = ( V_27 -
sizeof( struct V_113 ) ) /
sizeof( struct V_120 ) ;
V_6 = V_27 ;
}
V_114 = F_8 ( V_6 , V_62 ) ;
if ( ! V_114 )
return;
V_114 -> V_63 = V_2 -> V_64 -> V_63 ;
V_114 -> V_121 = V_71 ;
F_28 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_116 -> remove ) {
F_26 ( V_114 -> V_122 [ V_58 ] . V_123 , V_116 -> V_124 ) ;
V_58 ++ ;
F_29 ( & V_116 -> V_122 ) ;
F_12 ( V_116 ) ;
}
}
V_2 -> V_41 &= ~ V_126 ;
F_1 ( V_2 , V_127 ,
( T_1 * ) V_114 , V_6 ) ;
F_12 ( V_114 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
int V_6 , V_58 = 0 , V_71 = 0 ;
struct V_130 * V_116 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> V_117 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_131 ;
return;
}
V_2 -> V_39 = V_132 ;
V_6 = sizeof( struct V_128 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_60 ) ;
V_71 = ( V_27 -
sizeof( struct V_128 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_129 = F_8 ( V_6 , V_62 ) ;
if ( ! V_129 )
return;
V_129 -> V_63 = V_2 -> V_64 -> V_63 ;
V_129 -> V_121 = V_71 ;
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> V_117 ) {
V_129 -> V_133 [ V_58 ] = V_116 -> V_134 ;
V_58 ++ ;
V_116 -> V_117 = false ;
}
}
V_2 -> V_41 &= ~ V_131 ;
F_1 ( V_2 , V_132 , ( T_1 * ) V_129 , V_6 ) ;
F_12 ( V_129 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
struct V_130 * V_116 , * V_125 ;
int V_6 , V_58 = 0 , V_71 = 0 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_135 ;
return;
}
V_2 -> V_39 = V_136 ;
V_6 = sizeof( struct V_128 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_60 ) ;
V_71 = ( V_27 -
sizeof( struct V_128 ) ) /
sizeof( T_2 ) ;
V_6 = V_27 ;
}
V_129 = F_8 ( V_6 , V_62 ) ;
if ( ! V_129 )
return;
V_129 -> V_63 = V_2 -> V_64 -> V_63 ;
V_129 -> V_121 = V_71 ;
F_28 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_116 -> remove ) {
V_129 -> V_133 [ V_58 ] = V_116 -> V_134 ;
V_58 ++ ;
F_29 ( & V_116 -> V_122 ) ;
F_12 ( V_116 ) ;
}
}
V_2 -> V_41 &= ~ V_135 ;
F_1 ( V_2 , V_136 , ( T_1 * ) V_129 , V_6 ) ;
F_12 ( V_129 ) ;
}
void F_32 ( struct V_1 * V_2 , int V_10 )
{
struct V_137 V_138 ;
if ( V_2 -> V_39 != V_59 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_60 , V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_139 ;
V_138 . V_63 = V_2 -> V_64 -> V_63 ;
V_138 . V_10 = V_10 ;
F_1 ( V_2 , V_139 ,
( T_1 * ) & V_138 , sizeof( V_138 ) ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_59 ) {
return;
}
V_2 -> V_39 = V_140 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
if ( F_1 ( V_2 , V_140 ,
( T_1 * ) & V_89 , sizeof( V_89 ) ) )
V_2 -> V_39 = V_59 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_141 , NULL , 0 ) ;
V_2 -> V_39 = V_59 ;
}
void F_35 ( struct V_1 * V_2 ,
enum V_3 V_142 ,
T_3 V_143 ,
T_1 * V_5 , T_2 V_144 )
{
struct V_145 * V_80 = V_2 -> V_80 ;
if ( V_142 == V_146 ) {
struct V_147 * V_148 =
(struct V_147 * ) V_5 ;
switch ( V_148 -> V_25 ) {
case V_149 :
V_2 -> V_150 =
V_148 -> V_151 . V_152 . V_153 ;
if ( V_2 -> V_150 && ! F_36 ( V_80 ) ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_6 ) ;
F_37 ( V_80 ) ;
F_38 ( V_80 ) ;
} else if ( ! V_2 -> V_150 ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_7 ) ;
F_39 ( V_80 ) ;
F_40 ( V_80 ) ;
}
break;
case V_154 :
F_11 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
if ( ! ( V_2 -> V_10 & V_155 ) ) {
V_2 -> V_10 |= V_155 ;
F_11 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
F_41 ( & V_2 -> V_156 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 ,
L_10 ,
V_60 , V_148 -> V_25 ) ;
break;
}
return;
}
if ( V_143 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_60 , V_143 ,
F_4 ( & V_2 -> V_8 , V_143 ) , V_142 ) ;
}
switch ( V_142 ) {
case V_140 : {
struct V_157 * V_158 =
(struct V_157 * ) V_5 ;
V_2 -> V_159 . V_160 = V_158 -> V_161 +
V_158 -> V_162 +
V_158 -> V_163 ;
V_2 -> V_159 . V_164 = V_158 -> V_165 +
V_158 -> V_166 +
V_158 -> V_167 ;
V_2 -> V_159 . V_168 = V_158 -> V_168 ;
V_2 -> V_159 . V_169 = V_158 -> V_169 ;
V_2 -> V_159 . V_170 = V_158 -> V_170 ;
V_2 -> V_159 . V_171 = V_158 -> V_172 ;
V_2 -> V_159 . V_173 = V_158 -> V_174 ;
V_2 -> V_175 = * V_158 ;
}
break;
case V_40 : {
T_2 V_6 = sizeof( struct V_47 ) +
V_48 *
sizeof( struct V_49 ) ;
memcpy ( V_2 -> V_50 , V_5 , F_16 ( V_144 , V_6 ) ) ;
F_17 ( & V_2 -> V_8 , V_2 -> V_50 ) ;
F_42 ( V_2 ) ;
}
break;
case V_90 :
F_43 ( V_2 , true ) ;
F_44 ( V_2 -> V_80 ) ;
F_37 ( V_2 -> V_80 ) ;
break;
case V_94 :
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
break;
case V_22 :
case V_102 :
if ( V_142 != V_2 -> V_39 )
return;
break;
default:
if ( V_142 != V_2 -> V_39 )
F_25 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_2 -> V_39 , V_142 ) ;
break;
}
V_2 -> V_39 = V_59 ;
}
