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
if ( V_2 -> V_10 & V_87 ) {
V_57 -> V_77 . V_88 = true ;
V_57 -> V_77 . V_89 = V_90 ;
}
V_57 ++ ;
}
V_2 -> V_41 &= ~ V_91 ;
F_1 ( V_2 , V_62 ,
( T_1 * ) V_55 , V_6 ) ;
F_12 ( V_55 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_92 V_93 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_94 ;
V_93 . V_63 = V_2 -> V_64 -> V_63 ;
V_93 . V_95 = F_20 ( V_2 -> V_59 ) - 1 ;
V_93 . V_96 = V_93 . V_95 ;
V_2 -> V_41 &= ~ V_97 ;
F_1 ( V_2 , V_94 ,
( T_1 * ) & V_93 , sizeof( V_93 ) ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_92 V_93 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_5 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_98 ;
V_93 . V_63 = V_2 -> V_64 -> V_63 ;
V_93 . V_95 = F_20 ( V_2 -> V_59 ) - 1 ;
V_93 . V_96 = V_93 . V_95 ;
V_2 -> V_41 &= ~ V_99 ;
F_1 ( V_2 , V_98 ,
( T_1 * ) & V_93 , sizeof( V_93 ) ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
int V_102 , V_103 , V_6 ;
struct V_104 * V_105 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_6 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_106 ;
V_103 = V_2 -> V_107 - V_108 ;
V_6 = sizeof( struct V_100 ) +
( V_2 -> V_107 *
sizeof( struct V_109 ) ) ;
V_101 = F_8 ( V_6 , V_29 ) ;
if ( ! V_101 )
return;
V_101 -> V_110 = V_2 -> V_107 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
V_105 = V_2 -> V_103 + V_102 ;
V_101 -> V_111 [ V_102 ] . V_63 = V_2 -> V_64 -> V_63 ;
V_101 -> V_111 [ V_102 ] . V_112 = V_102 + V_108 ;
V_101 -> V_111 [ V_102 ] . V_113 = V_105 -> V_114 ;
V_101 -> V_111 [ V_102 ] . V_115 = V_105 -> V_114 ;
}
V_101 -> V_111 [ V_102 ] . V_63 = V_2 -> V_64 -> V_63 ;
V_101 -> V_111 [ V_102 ] . V_112 = 0 ;
V_101 -> V_111 [ V_102 ] . V_113 = 0 ;
V_101 -> V_111 [ V_102 ] . V_115 = 0 ;
V_2 -> V_41 &= ~ V_116 ;
F_1 ( V_2 , V_106 ,
( T_1 * ) V_101 , V_6 ) ;
F_12 ( V_101 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
struct V_119 * V_120 ;
bool V_121 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_7 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_120 -> V_122 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_123 ;
return;
}
V_2 -> V_39 = V_124 ;
V_6 = sizeof( struct V_117 ) +
( V_71 * sizeof( struct V_125 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_8 ) ;
V_71 = ( V_27 -
sizeof( struct V_117 ) ) /
sizeof( struct V_125 ) ;
V_6 = sizeof( struct V_117 ) +
( V_71 * sizeof( struct V_125 ) ) ;
V_121 = true ;
}
V_118 = F_8 ( V_6 , V_29 ) ;
if ( ! V_118 )
return;
V_118 -> V_63 = V_2 -> V_64 -> V_63 ;
V_118 -> V_126 = V_71 ;
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_120 -> V_122 ) {
F_26 ( V_118 -> V_127 [ V_60 ] . V_128 , V_120 -> V_129 ) ;
V_60 ++ ;
V_120 -> V_122 = false ;
}
}
if ( ! V_121 )
V_2 -> V_41 &= ~ V_123 ;
F_1 ( V_2 , V_124 ,
( T_1 * ) V_118 , V_6 ) ;
F_12 ( V_118 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 , * V_130 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
bool V_121 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_9 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->mac_filter_list, list) {
if ( V_120 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_131 ;
return;
}
V_2 -> V_39 = V_132 ;
V_6 = sizeof( struct V_117 ) +
( V_71 * sizeof( struct V_125 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_10 ) ;
V_71 = ( V_27 -
sizeof( struct V_117 ) ) /
sizeof( struct V_125 ) ;
V_6 = sizeof( struct V_117 ) +
( V_71 * sizeof( struct V_125 ) ) ;
V_121 = true ;
}
V_118 = F_8 ( V_6 , V_29 ) ;
if ( ! V_118 )
return;
V_118 -> V_63 = V_2 -> V_64 -> V_63 ;
V_118 -> V_126 = V_71 ;
F_28 (f, ftmp, &adapter->mac_filter_list, list) {
if ( V_120 -> remove ) {
F_26 ( V_118 -> V_127 [ V_60 ] . V_128 , V_120 -> V_129 ) ;
V_60 ++ ;
F_29 ( & V_120 -> V_127 ) ;
F_12 ( V_120 ) ;
}
}
if ( ! V_121 )
V_2 -> V_41 &= ~ V_131 ;
F_1 ( V_2 , V_132 ,
( T_1 * ) V_118 , V_6 ) ;
F_12 ( V_118 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_133 * V_134 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
struct V_135 * V_120 ;
bool V_121 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_120 -> V_122 )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_136 ;
return;
}
V_2 -> V_39 = V_137 ;
V_6 = sizeof( struct V_133 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_12 ) ;
V_71 = ( V_27 -
sizeof( struct V_133 ) ) /
sizeof( T_2 ) ;
V_6 = sizeof( struct V_133 ) +
( V_71 * sizeof( T_2 ) ) ;
V_121 = true ;
}
V_134 = F_8 ( V_6 , V_29 ) ;
if ( ! V_134 )
return;
V_134 -> V_63 = V_2 -> V_64 -> V_63 ;
V_134 -> V_126 = V_71 ;
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_120 -> V_122 ) {
V_134 -> V_138 [ V_60 ] = V_120 -> V_139 ;
V_60 ++ ;
V_120 -> V_122 = false ;
}
}
if ( ! V_121 )
V_2 -> V_41 &= ~ V_136 ;
F_1 ( V_2 , V_137 , ( T_1 * ) V_134 , V_6 ) ;
F_12 ( V_134 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_133 * V_134 ;
struct V_135 * V_120 , * V_130 ;
int V_6 , V_60 = 0 , V_71 = 0 ;
bool V_121 = false ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_2 -> V_39 ) ;
return;
}
F_24 (f, &adapter->vlan_filter_list, list) {
if ( V_120 -> remove )
V_71 ++ ;
}
if ( ! V_71 ) {
V_2 -> V_41 &= ~ V_140 ;
return;
}
V_2 -> V_39 = V_141 ;
V_6 = sizeof( struct V_133 ) +
( V_71 * sizeof( T_2 ) ) ;
if ( V_6 > V_27 ) {
F_25 ( & V_2 -> V_12 -> V_13 , L_14 ) ;
V_71 = ( V_27 -
sizeof( struct V_133 ) ) /
sizeof( T_2 ) ;
V_6 = sizeof( struct V_133 ) +
( V_71 * sizeof( T_2 ) ) ;
V_121 = true ;
}
V_134 = F_8 ( V_6 , V_29 ) ;
if ( ! V_134 )
return;
V_134 -> V_63 = V_2 -> V_64 -> V_63 ;
V_134 -> V_126 = V_71 ;
F_28 (f, ftmp, &adapter->vlan_filter_list, list) {
if ( V_120 -> remove ) {
V_134 -> V_138 [ V_60 ] = V_120 -> V_139 ;
V_60 ++ ;
F_29 ( & V_120 -> V_127 ) ;
F_12 ( V_120 ) ;
}
}
if ( ! V_121 )
V_2 -> V_41 &= ~ V_140 ;
F_1 ( V_2 , V_141 , ( T_1 * ) V_134 , V_6 ) ;
F_12 ( V_134 ) ;
}
void F_32 ( struct V_1 * V_2 , int V_10 )
{
struct V_142 V_143 ;
if ( V_2 -> V_39 != V_61 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_15 ,
V_2 -> V_39 ) ;
return;
}
V_2 -> V_39 = V_144 ;
V_143 . V_63 = V_2 -> V_64 -> V_63 ;
V_143 . V_10 = V_10 ;
F_1 ( V_2 , V_144 ,
( T_1 * ) & V_143 , sizeof( V_143 ) ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_92 V_93 ;
if ( V_2 -> V_39 != V_61 ) {
return;
}
V_2 -> V_39 = V_145 ;
V_93 . V_63 = V_2 -> V_64 -> V_63 ;
if ( F_1 ( V_2 , V_145 ,
( T_1 * ) & V_93 , sizeof( V_93 ) ) )
V_2 -> V_39 = V_61 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_146 , NULL , 0 ) ;
V_2 -> V_39 = V_61 ;
}
void F_35 ( struct V_1 * V_2 ,
enum V_3 V_147 ,
T_3 V_148 ,
T_1 * V_5 , T_2 V_149 )
{
struct V_150 * V_80 = V_2 -> V_80 ;
if ( V_147 == V_151 ) {
struct V_152 * V_153 =
(struct V_152 * ) V_5 ;
switch ( V_153 -> V_25 ) {
case V_154 :
V_2 -> V_155 =
V_153 -> V_156 . V_157 . V_158 ;
if ( V_2 -> V_155 && ! F_36 ( V_80 ) ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_16 ) ;
F_37 ( V_80 ) ;
F_38 ( V_80 ) ;
} else if ( ! V_2 -> V_155 ) {
F_11 ( & V_2 -> V_12 -> V_13 , L_17 ) ;
F_39 ( V_80 ) ;
F_40 ( V_80 ) ;
}
break;
case V_159 :
F_11 ( & V_2 -> V_12 -> V_13 , L_18 ) ;
if ( ! ( V_2 -> V_10 & V_160 ) ) {
V_2 -> V_10 |= V_160 ;
F_11 ( & V_2 -> V_12 -> V_13 , L_19 ) ;
F_41 ( & V_2 -> V_161 ) ;
}
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 , L_20 ,
V_153 -> V_25 ) ;
break;
}
return;
}
if ( V_148 ) {
switch ( V_147 ) {
case V_137 :
F_3 ( & V_2 -> V_12 -> V_13 , L_21 ,
F_4 ( & V_2 -> V_8 , V_148 ) ) ;
break;
case V_124 :
F_3 ( & V_2 -> V_12 -> V_13 , L_22 ,
F_4 ( & V_2 -> V_8 , V_148 ) ) ;
break;
case V_141 :
F_3 ( & V_2 -> V_12 -> V_13 , L_23 ,
F_4 ( & V_2 -> V_8 , V_148 ) ) ;
break;
case V_132 :
F_3 ( & V_2 -> V_12 -> V_13 , L_24 ,
F_4 ( & V_2 -> V_8 , V_148 ) ) ;
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 , L_25 ,
V_148 ,
F_4 ( & V_2 -> V_8 , V_148 ) ,
V_147 ) ;
}
}
switch ( V_147 ) {
case V_145 : {
struct V_162 * V_163 =
(struct V_162 * ) V_5 ;
V_2 -> V_164 . V_165 = V_163 -> V_166 +
V_163 -> V_167 +
V_163 -> V_168 ;
V_2 -> V_164 . V_169 = V_163 -> V_170 +
V_163 -> V_171 +
V_163 -> V_172 ;
V_2 -> V_164 . V_173 = V_163 -> V_173 ;
V_2 -> V_164 . V_174 = V_163 -> V_174 ;
V_2 -> V_164 . V_175 = V_163 -> V_175 ;
V_2 -> V_164 . V_176 = V_163 -> V_177 ;
V_2 -> V_164 . V_178 = V_163 -> V_179 ;
V_2 -> V_180 = * V_163 ;
}
break;
case V_40 : {
T_2 V_6 = sizeof( struct V_49 ) +
V_50 *
sizeof( struct V_51 ) ;
memcpy ( V_2 -> V_52 , V_5 , F_16 ( V_149 , V_6 ) ) ;
F_17 ( & V_2 -> V_8 , V_2 -> V_52 ) ;
F_26 ( V_2 -> V_8 . V_181 . V_128 , V_80 -> V_182 ) ;
F_42 ( V_2 ) ;
}
break;
case V_94 :
F_43 ( V_2 , true ) ;
F_44 ( V_2 -> V_80 ) ;
F_37 ( V_2 -> V_80 ) ;
break;
case V_98 :
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_2 -> V_183 == V_184 )
V_2 -> V_183 = V_185 ;
break;
case V_22 :
case V_106 :
if ( V_147 != V_2 -> V_39 )
return;
break;
default:
if ( V_147 != V_2 -> V_39 )
F_25 ( & V_2 -> V_12 -> V_13 , L_26 ,
V_2 -> V_39 , V_147 ) ;
break;
}
V_2 -> V_39 = V_61 ;
}
