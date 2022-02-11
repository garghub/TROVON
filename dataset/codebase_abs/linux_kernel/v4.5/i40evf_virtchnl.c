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
V_46 |
V_47 |
V_48 ;
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
V_6 = sizeof( struct V_49 ) +
V_50 * sizeof( struct V_51 ) ;
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
memcpy ( V_2 -> V_52 , V_25 . V_28 , F_16 ( V_25 . V_53 , V_6 ) ) ;
F_17 ( V_8 , V_2 -> V_52 ) ;
V_32:
F_12 ( V_25 . V_28 ) ;
V_31:
return V_9 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_58 = V_2 -> V_59 ;
int V_60 , V_6 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_62 ;
V_6 = sizeof( struct V_54 ) +
( sizeof( struct V_56 ) * V_58 ) ;
V_55 = F_8 ( V_6 , V_29 ) ;
if ( ! V_55 )
return;
V_55 -> V_63 = V_2 -> V_64 -> V_63 ;
V_55 -> V_65 = V_58 ;
V_57 = V_55 -> V_66 ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ ) {
V_57 -> V_67 . V_63 = V_55 -> V_63 ;
V_57 -> V_67 . V_68 = V_60 ;
V_57 -> V_67 . V_69 = V_2 -> V_70 [ V_60 ] . V_71 ;
V_57 -> V_67 . V_72 = V_2 -> V_70 [ V_60 ] . V_73 ;
V_57 -> V_67 . V_74 = 1 ;
V_57 -> V_67 . V_75 = V_57 -> V_67 . V_72 +
( V_57 -> V_67 . V_69 * sizeof( struct V_76 ) ) ;
V_57 -> V_77 . V_63 = V_55 -> V_63 ;
V_57 -> V_77 . V_68 = V_60 ;
V_57 -> V_77 . V_69 = V_2 -> V_78 [ V_60 ] . V_71 ;
V_57 -> V_77 . V_72 = V_2 -> V_78 [ V_60 ] . V_73 ;
V_57 -> V_77 . V_79 = V_2 -> V_80 -> V_81
+ V_82 + V_83 + V_84 ;
V_57 -> V_77 . V_85 = V_2 -> V_78 [ V_60 ] . V_86 ;
V_57 ++ ;
}
V_2 -> V_41 &= ~ V_87 ;
F_1 ( V_2 , V_62 ,
( T_1 * ) V_55 , V_6 ) ;
F_12 ( V_55 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_90 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
V_89 . V_91 = F_20 ( V_2 -> V_59 ) - 1 ;
V_89 . V_92 = V_89 . V_91 ;
V_2 -> V_41 &= ~ V_93 ;
F_1 ( V_2 , V_90 ,
( T_1 * ) & V_89 , sizeof( V_89 ) ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_94 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
V_89 . V_91 = F_20 ( V_2 -> V_59 ) - 1 ;
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
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_6 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_102 ;
V_99 = V_2 -> V_103 - V_104 ;
V_6 = sizeof( struct V_96 ) +
( V_2 -> V_103 *
sizeof( struct V_105 ) ) ;
V_97 = F_8 ( V_6 , V_29 ) ;
if ( ! V_97 )
return;
V_97 -> V_106 = V_2 -> V_103 ;
for ( V_98 = 0 ; V_98 < V_99 ; V_98 ++ ) {
V_101 = V_2 -> V_99 + V_98 ;
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
int V_6 , V_60 = 0 , V_71 = 0 ;
struct V_115 * V_116 ;
bool V_117 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_7 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> V_118 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_119 ;
return;
}
V_2 -> V_39 = V_120 ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_121 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
V_71 = ( V_27 -
sizeof( struct V_113 ) ) /
sizeof( struct V_121 ) ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_121 ) ) ;
V_117 = true ;
}
V_114 = F_8 ( V_6 , V_29 ) ;
if ( ! V_114 )
return;
V_114 -> V_63 = V_2 -> V_64 -> V_63 ;
V_114 -> V_122 = V_71 ;
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> V_118 ) {
F_26 ( V_114 -> V_123 [ V_60 ] . V_124 , V_116 -> V_125 ) ;
V_60 ++ ;
V_116 -> V_118 = false ;
}
}
if ( ! V_117 )
V_2 -> V_41 &= ~ V_119 ;
F_1 ( V_2 , V_120 ,
( T_1 * ) V_114 , V_6 ) ;
F_12 ( V_114 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 , * V_126 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
bool V_117 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_9 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_116 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_127 ;
return;
}
V_2 -> V_39 = V_128 ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_121 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_10 ) ;
V_71 = ( V_27 -
sizeof( struct V_113 ) ) /
sizeof( struct V_121 ) ;
V_6 = sizeof( struct V_113 ) +
( V_71 * sizeof( struct V_121 ) ) ;
V_117 = true ;
}
V_114 = F_8 ( V_6 , V_29 ) ;
if ( ! V_114 )
return;
V_114 -> V_63 = V_2 -> V_64 -> V_63 ;
V_114 -> V_122 = V_71 ;
F_28 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_116 -> remove ) {
F_26 ( V_114 -> V_123 [ V_60 ] . V_124 , V_116 -> V_125 ) ;
V_60 ++ ;
F_29 ( & V_116 -> V_123 ) ;
F_12 ( V_116 ) ;
}
}
if ( ! V_117 )
V_2 -> V_41 &= ~ V_127 ;
F_1 ( V_2 , V_128 ,
( T_1 * ) V_114 , V_6 ) ;
F_12 ( V_114 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
struct V_131 * V_116 ;
bool V_117 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> V_118 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_132 ;
return;
}
V_2 -> V_39 = V_133 ;
V_6 = sizeof( struct V_129 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_12 ) ;
V_71 = ( V_27 -
sizeof( struct V_129 ) ) /
sizeof( T_2 ) ;
V_6 = sizeof( struct V_129 ) +
( V_71 * sizeof( T_2 ) ) ;
V_117 = true ;
}
V_130 = F_8 ( V_6 , V_29 ) ;
if ( ! V_130 )
return;
V_130 -> V_63 = V_2 -> V_64 -> V_63 ;
V_130 -> V_122 = V_71 ;
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> V_118 ) {
V_130 -> V_134 [ V_60 ] = V_116 -> V_135 ;
V_60 ++ ;
V_116 -> V_118 = false ;
}
}
if ( ! V_117 )
V_2 -> V_41 &= ~ V_132 ;
F_1 ( V_2 , V_133 , ( T_1 * ) V_130 , V_6 ) ;
F_12 ( V_130 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
struct V_131 * V_116 , * V_126 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
bool V_117 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_116 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_136 ;
return;
}
V_2 -> V_39 = V_137 ;
V_6 = sizeof( struct V_129 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_14 ) ;
V_71 = ( V_27 -
sizeof( struct V_129 ) ) /
sizeof( T_2 ) ;
V_6 = sizeof( struct V_129 ) +
( V_71 * sizeof( T_2 ) ) ;
V_117 = true ;
}
V_130 = F_8 ( V_6 , V_29 ) ;
if ( ! V_130 )
return;
V_130 -> V_63 = V_2 -> V_64 -> V_63 ;
V_130 -> V_122 = V_71 ;
F_28 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_116 -> remove ) {
V_130 -> V_134 [ V_60 ] = V_116 -> V_135 ;
V_60 ++ ;
F_29 ( & V_116 -> V_123 ) ;
F_12 ( V_116 ) ;
}
}
if ( ! V_117 )
V_2 -> V_41 &= ~ V_136 ;
F_1 ( V_2 , V_137 , ( T_1 * ) V_130 , V_6 ) ;
F_12 ( V_130 ) ;
}
void F_32 ( struct V_1 * V_2 , int V_10 )
{
struct V_138 V_139 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_15 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_140 ;
V_139 . V_63 = V_2 -> V_64 -> V_63 ;
V_139 . V_10 = V_10 ;
F_1 ( V_2 , V_140 ,
( T_1 * ) & V_139 , sizeof( V_139 ) ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
if ( V_2 -> V_39 != V_61 ) {
return;
}
V_2 -> V_39 = V_141 ;
V_89 . V_63 = V_2 -> V_64 -> V_63 ;
if ( F_1 ( V_2 , V_141 ,
( T_1 * ) & V_89 , sizeof( V_89 ) ) )
V_2 -> V_39 = V_61 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_142 , NULL , 0 ) ;
V_2 -> V_39 = V_61 ;
}
void F_35 ( struct V_1 * V_2 ,
enum V_3 V_143 ,
T_3 V_144 ,
T_1 * V_5 , T_2 V_145 )
{
struct V_146 * V_80 = V_2 -> V_80 ;
if ( V_143 == V_147 ) {
struct V_148 * V_149 =
(struct V_148 * ) V_5 ;
switch ( V_149 -> V_25 ) {
case V_150 :
V_2 -> V_151 =
V_149 -> V_152 . V_153 . V_154 ;
if ( V_2 -> V_151 && ! F_36 ( V_80 ) ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_16 ) ;
F_37 ( V_80 ) ;
F_38 ( V_80 ) ;
} else if ( ! V_2 -> V_151 ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_17 ) ;
F_39 ( V_80 ) ;
F_40 ( V_80 ) ;
}
break;
case V_155 :
F_11 ( & V_2 -> V_12 -> V_13 , L_18 ) ;
if ( ! ( V_2 -> V_10 & V_156 ) ) {
V_2 -> V_10 |= V_156 ;
F_11 ( & V_2 -> V_12 -> V_13 , L_19 ) ;
F_41 ( & V_2 -> V_157 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 , L_20 ,
V_149 -> V_25 ) ;
break;
}
return;
}
if ( V_144 ) {
switch ( V_143 ) {
case V_133 :
F_3 ( & V_2 -> V_12 -> V_13 , L_21 ,
F_4 ( & V_2 -> V_8 , V_144 ) ) ;
break;
case V_120 :
F_3 ( & V_2 -> V_12 -> V_13 , L_22 ,
F_4 ( & V_2 -> V_8 , V_144 ) ) ;
break;
case V_137 :
F_3 ( & V_2 -> V_12 -> V_13 , L_23 ,
F_4 ( & V_2 -> V_8 , V_144 ) ) ;
break;
case V_128 :
F_3 ( & V_2 -> V_12 -> V_13 , L_24 ,
F_4 ( & V_2 -> V_8 , V_144 ) ) ;
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 , L_25 ,
V_144 ,
F_4 ( & V_2 -> V_8 , V_144 ) ,
V_143 ) ;
}
}
switch ( V_143 ) {
case V_141 : {
struct V_158 * V_159 =
(struct V_158 * ) V_5 ;
V_2 -> V_160 . V_161 = V_159 -> V_162 +
V_159 -> V_163 +
V_159 -> V_164 ;
V_2 -> V_160 . V_165 = V_159 -> V_166 +
V_159 -> V_167 +
V_159 -> V_168 ;
V_2 -> V_160 . V_169 = V_159 -> V_169 ;
V_2 -> V_160 . V_170 = V_159 -> V_170 ;
V_2 -> V_160 . V_171 = V_159 -> V_171 ;
V_2 -> V_160 . V_172 = V_159 -> V_173 ;
V_2 -> V_160 . V_174 = V_159 -> V_175 ;
V_2 -> V_176 = * V_159 ;
}
break;
case V_40 : {
T_2 V_6 = sizeof( struct V_49 ) +
V_50 *
sizeof( struct V_51 ) ;
memcpy ( V_2 -> V_52 , V_5 , F_16 ( V_145 , V_6 ) ) ;
F_17 ( & V_2 -> V_8 , V_2 -> V_52 ) ;
F_26 ( V_2 -> V_8 . V_177 . V_124 , V_80 -> V_178 ) ;
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
if ( V_143 != V_2 -> V_39 )
return;
break;
default:
if ( V_143 != V_2 -> V_39 )
F_25 ( & V_2 -> V_12 -> V_13 , L_26 ,
V_2 -> V_39 , V_143 ) ;
break;
}
V_2 -> V_39 = V_61 ;
}
