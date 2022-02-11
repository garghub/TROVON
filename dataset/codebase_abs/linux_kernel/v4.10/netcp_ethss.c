static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
strncpy ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
strncpy ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_11 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_10 -> V_11 = V_12 ;
}
static struct V_13 * F_5 ( struct V_9 * V_10 )
{
struct V_13 * V_13 ;
V_13 = F_6 ( & V_14 , V_10 ) ;
if ( ! V_13 )
V_13 = F_6 ( & V_15 , V_10 ) ;
return V_13 ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_16 , T_3 * V_17 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
struct V_18 * V_19 ;
int V_20 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return;
V_19 = V_13 -> V_19 ;
switch ( V_16 ) {
case V_21 :
for ( V_20 = 0 ; V_20 < V_19 -> V_22 ; V_20 ++ ) {
memcpy ( V_17 , V_19 -> V_23 [ V_20 ] . V_24 ,
V_25 ) ;
V_17 += V_25 ;
}
break;
case V_26 :
break;
}
}
static int F_8 ( struct V_1 * V_2 , int V_16 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
struct V_18 * V_19 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return - V_27 ;
V_19 = V_13 -> V_19 ;
switch ( V_16 ) {
case V_26 :
return 0 ;
case V_21 :
return V_19 -> V_22 ;
default:
return - V_27 ;
}
}
static void F_9 ( struct V_18 * V_19 , int V_28 )
{
void T_4 * V_29 = V_19 -> V_30 [ V_28 ] ;
T_1 T_4 * V_31 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_22 ; V_20 ++ ) {
if ( V_19 -> V_23 [ V_20 ] . type == V_28 ) {
V_31 = V_29 + V_19 -> V_23 [ V_20 ] . V_32 ;
V_19 -> V_33 [ V_20 ] = 0 ;
V_19 -> V_34 [ V_20 ] = F_10 ( V_31 ) ;
}
}
}
static inline void F_11 ( struct V_18 * V_19 ,
int V_35 )
{
void T_4 * V_29 = NULL ;
T_1 T_4 * V_31 ;
T_1 V_36 , V_37 ;
V_29 = V_19 -> V_30 [ V_19 -> V_23 [ V_35 ] . type ] ;
V_31 = V_29 + V_19 -> V_23 [ V_35 ] . V_32 ;
V_36 = F_10 ( V_31 ) ;
V_37 = V_36 - V_19 -> V_34 [ V_35 ] ;
V_19 -> V_34 [ V_35 ] = V_36 ;
V_19 -> V_33 [ V_35 ] += V_37 ;
}
static void F_12 ( struct V_18 * V_19 , T_5 * V_17 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_22 ; V_20 ++ ) {
F_11 ( V_19 , V_20 ) ;
if ( V_17 )
V_17 [ V_20 ] = V_19 -> V_33 [ V_20 ] ;
}
}
static inline void F_13 ( struct V_18 * V_19 ,
int V_28 )
{
T_1 V_38 ;
V_38 = F_10 ( F_14 ( V_19 , V_39 , V_40 ) ) ;
switch ( V_28 ) {
case V_41 :
case V_42 :
V_38 &= ~ V_43 ;
break;
case V_44 :
case V_45 :
V_38 |= V_43 ;
break;
default:
return;
}
F_15 ( V_38 , F_14 ( V_19 , V_39 , V_40 ) ) ;
}
static void F_16 ( struct V_18 * V_19 , int V_28 )
{
F_13 ( V_19 , V_28 ) ;
F_9 ( V_19 , V_28 ) ;
}
static void F_17 ( struct V_18 * V_19 , T_5 * V_17 )
{
T_1 V_46 = ( V_19 -> V_22 / 2 ) ;
int V_47 , V_48 , V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
F_13 ( V_19 , ( V_49 ?
V_44 :
V_41 ) ) ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ ) {
V_47 = V_49 * V_46 + V_48 ;
F_11 ( V_19 , V_47 ) ;
if ( V_17 )
V_17 [ V_47 ] = V_19 -> V_33 [ V_47 ] ;
}
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_5 * V_17 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
struct V_18 * V_19 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return;
V_19 = V_13 -> V_19 ;
F_19 ( & V_19 -> V_52 ) ;
if ( V_19 -> V_53 == V_54 )
F_17 ( V_19 , V_17 ) ;
else
F_12 ( V_19 , V_17 ) ;
F_20 ( & V_19 -> V_52 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_57 * V_58 = V_2 -> V_59 ;
struct V_13 * V_13 ;
int V_60 ;
if ( ! V_58 )
return - V_27 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return - V_27 ;
if ( ! V_13 -> V_61 )
return - V_27 ;
V_60 = F_22 ( V_58 , V_56 ) ;
if ( ! V_60 )
V_56 -> V_29 . V_62 = V_13 -> V_61 -> V_63 ;
return V_60 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_57 * V_58 = V_2 -> V_59 ;
struct V_13 * V_13 ;
T_6 V_62 = V_56 -> V_29 . V_62 ;
T_1 V_64 , V_65 ;
T_1 V_66 ;
F_24 ( & V_64 ,
V_56 -> V_67 . V_64 ) ;
F_24 ( & V_65 ,
V_56 -> V_67 . V_65 ) ;
V_66 = V_64 & V_65 ;
if ( ! V_58 )
return - V_27 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return - V_27 ;
if ( ! V_13 -> V_61 )
return - V_27 ;
if ( V_62 != V_13 -> V_61 -> V_63 ) {
if ( ( V_62 == V_68 ) && ! ( V_66 & V_69 ) )
return - V_27 ;
if ( ( V_62 == V_70 ) && ! ( V_66 & V_71 ) )
return - V_27 ;
if ( ( V_62 == V_72 ) && ! ( V_66 & V_73 ) )
return - V_27 ;
if ( ( V_62 == V_74 ) && ! ( V_66 & V_75 ) )
return - V_27 ;
if ( ( V_62 == V_76 ) && ! ( V_66 & V_77 ) )
return - V_27 ;
}
V_13 -> V_61 -> V_63 = V_62 ;
return F_25 ( V_58 , V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_78 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_14 , V_10 ) ;
if ( ! V_13 || ! V_13 -> V_19 -> V_79 )
return - V_27 ;
V_4 -> V_80 =
V_81 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ;
V_4 -> V_87 = V_13 -> V_19 -> V_79 -> V_87 ;
V_4 -> V_88 =
( 1 << V_89 ) |
( 1 << V_90 ) ;
V_4 -> V_91 =
( 1 << V_92 ) |
( 1 << V_93 ) |
( 1 << V_94 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_78 * V_4 )
{
V_4 -> V_80 =
V_82 |
V_84 |
V_85 ;
V_4 -> V_87 = - 1 ;
V_4 -> V_88 = 0 ;
V_4 -> V_91 = 0 ;
return 0 ;
}
static void F_27 ( struct V_95 * V_61 ,
struct V_13 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_15 ( F_28 ( V_2 -> V_96 ) , F_14 ( V_61 , V_97 , V_98 ) ) ;
F_15 ( F_29 ( V_2 -> V_96 ) , F_14 ( V_61 , V_97 , V_99 ) ) ;
}
static int F_30 ( struct V_18 * V_100 , T_1 V_101 )
{
if ( V_100 -> V_102 == 0 )
return V_101 + 1 ;
return V_101 ;
}
static void F_31 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_95 * V_61 ,
int V_103 )
{
struct V_57 * V_58 = V_61 -> V_58 ;
T_1 V_104 = 0 ;
if ( V_103 ) {
V_104 = V_61 -> V_104 ;
if ( V_58 && ( V_58 -> V_105 == V_106 ) ) {
V_104 |= V_107 ;
V_104 &= ~ V_108 ;
} else if ( V_58 && ( V_58 -> V_105 == V_109 ) ) {
V_104 |= V_108 ;
V_104 &= ~ V_107 ;
}
F_15 ( V_104 , F_14 ( V_61 , V_110 ,
V_104 ) ) ;
F_32 ( V_19 -> V_111 , V_61 -> V_112 ,
V_113 ,
V_114 ) ;
if ( V_2 && V_61 -> V_115 &&
V_61 -> V_116 != V_117 &&
V_61 -> V_116 != V_118 )
F_33 ( V_2 ) ;
} else {
F_15 ( V_104 , F_14 ( V_61 , V_110 ,
V_104 ) ) ;
F_32 ( V_19 -> V_111 , V_61 -> V_112 ,
V_113 ,
V_119 ) ;
if ( V_2 &&
V_61 -> V_116 != V_117 &&
V_61 -> V_116 != V_118 )
F_34 ( V_2 ) ;
}
if ( V_58 )
F_35 ( V_58 ) ;
}
static bool F_36 ( struct V_95 * V_61 )
{
return ! V_61 -> V_58 || V_61 -> V_58 -> V_120 ;
}
static void F_37 ( struct V_18 * V_19 ,
struct V_95 * V_61 ,
struct V_1 * V_2 )
{
int V_121 = V_61 -> V_101 ;
int V_122 , V_123 = 1 , V_124 ;
if ( ! V_61 -> V_115 )
return;
if ( ! F_38 ( V_61 ) ) {
V_123 =
F_39 ( F_40 ( V_19 , V_121 ) , V_121 ) ;
}
V_122 = F_36 ( V_61 ) ;
V_124 = V_122 & V_123 ;
if ( F_41 ( & V_61 -> V_124 , V_124 ) != V_124 )
F_31 ( V_19 , V_2 , V_61 ,
V_124 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_15 , V_10 ) ;
if ( ! V_13 )
return;
F_37 ( V_13 -> V_19 , V_13 -> V_61 ,
V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_14 , V_10 ) ;
if ( ! V_13 )
return;
F_37 ( V_13 -> V_19 , V_13 -> V_61 ,
V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_3 ( V_2 ) ;
struct V_95 * V_61 ;
F_45 (slave, gbe_dev)
F_37 ( V_19 , V_61 , NULL ) ;
}
static int F_46 ( struct V_95 * V_61 )
{
T_1 V_20 , V_125 ;
F_15 ( V_126 , F_14 ( V_61 , V_110 , V_127 ) ) ;
for ( V_20 = 0 ; V_20 < V_128 ; V_20 ++ ) {
V_125 = F_10 ( F_14 ( V_61 , V_110 , V_127 ) ) ;
if ( ( V_125 & V_129 ) != V_126 )
return 0 ;
}
return V_130 ;
}
static void F_47 ( struct V_18 * V_19 , struct V_95 * V_61 ,
int V_131 )
{
void T_4 * V_132 ;
T_1 V_133 ;
if ( V_131 > V_134 )
V_131 = V_134 ;
if ( ( V_19 -> V_53 == V_135 ) &&
( V_61 -> V_116 >= V_118 ) ) {
V_133 = F_10 ( F_14 ( V_19 , V_136 , V_137 ) ) ;
V_133 |= ( 1 << V_61 -> V_101 ) ;
F_15 ( V_133 , F_14 ( V_19 , V_136 , V_137 ) ) ;
}
if ( F_48 ( V_19 ) )
V_132 = F_14 ( V_61 , V_97 , V_138 ) ;
else
V_132 = F_14 ( V_61 , V_110 , V_138 ) ;
F_15 ( V_131 , V_132 ) ;
F_15 ( V_61 -> V_104 , F_14 ( V_61 , V_110 , V_104 ) ) ;
}
static void F_49 ( struct V_18 * V_100 ,
struct V_95 * V_61 , bool V_139 )
{
if ( F_38 ( V_61 ) )
return;
F_50 ( F_40 ( V_100 , V_61 -> V_101 ) ,
V_61 -> V_101 , V_139 ) ;
}
static void F_51 ( struct V_13 * V_140 )
{
struct V_18 * V_19 = V_140 -> V_19 ;
struct V_95 * V_61 = V_140 -> V_61 ;
F_49 ( V_19 , V_61 , true ) ;
F_46 ( V_61 ) ;
F_32 ( V_19 -> V_111 , V_61 -> V_112 ,
V_113 , V_119 ) ;
F_52 ( V_19 -> V_111 , V_140 -> V_2 -> V_141 ,
1 << V_61 -> V_112 , 0 , 0 ) ;
if ( ! V_61 -> V_58 )
return;
F_53 ( V_61 -> V_58 ) ;
F_54 ( V_61 -> V_58 ) ;
V_61 -> V_58 = NULL ;
}
static void F_55 ( struct V_18 * V_100 , struct V_95 * V_61 )
{
if ( F_38 ( V_61 ) )
return;
F_56 ( F_40 ( V_100 , V_61 -> V_101 ) , V_61 -> V_101 ) ;
F_57 ( F_40 ( V_100 , V_61 -> V_101 ) , V_61 -> V_101 ,
V_61 -> V_116 ) ;
}
static int F_58 ( struct V_13 * V_13 )
{
struct V_18 * V_100 = V_13 -> V_19 ;
struct V_95 * V_61 = V_13 -> V_61 ;
T_7 V_142 ;
bool V_143 = false ;
void (* F_59)( struct V_1 * ) = F_43 ;
F_55 ( V_100 , V_61 ) ;
F_46 ( V_61 ) ;
F_49 ( V_100 , V_61 , false ) ;
F_47 ( V_100 , V_61 , V_100 -> V_144 ) ;
F_27 ( V_61 , V_13 ) ;
F_32 ( V_100 -> V_111 , V_61 -> V_112 ,
V_113 , V_114 ) ;
F_60 ( V_100 -> V_111 , V_13 -> V_2 -> V_141 ,
1 << V_61 -> V_112 , 0 , 0 , V_145 ) ;
if ( V_61 -> V_116 == V_117 ) {
V_143 = true ;
V_142 = V_146 ;
V_61 -> V_63 = V_74 ;
} else if ( V_61 -> V_116 == V_118 ) {
V_143 = true ;
V_142 = V_147 ;
V_61 -> V_63 = V_76 ;
}
if ( V_143 ) {
if ( V_100 -> V_53 == V_135 )
F_59 = F_42 ;
V_61 -> V_58 = F_61 ( V_13 -> V_2 ,
V_61 -> V_148 ,
F_59 , 0 ,
V_142 ) ;
if ( ! V_61 -> V_58 ) {
F_62 ( V_100 -> V_149 , L_1 ,
V_61 -> V_101 ) ;
return - V_150 ;
}
F_63 ( V_100 -> V_149 , L_2 ,
F_64 ( V_61 -> V_58 ) ) ;
F_65 ( V_61 -> V_58 ) ;
F_66 ( V_61 -> V_58 ) ;
}
return 0 ;
}
static void F_67 ( struct V_18 * V_100 )
{
int V_151 = 1 ;
if ( F_68 ( V_100 ) || F_69 ( V_100 ) )
F_15 ( V_152 ,
F_14 ( V_100 , V_153 , V_154 ) ) ;
F_15 ( V_134 , F_14 ( V_100 , V_153 ,
V_138 ) ) ;
F_70 ( V_100 -> V_111 ) ;
if ( V_100 -> V_155 )
V_151 = 0 ;
F_32 ( V_100 -> V_111 , 0 , V_156 , V_151 ) ;
F_32 ( V_100 -> V_111 , 0 , V_157 , 1 ) ;
F_32 ( V_100 -> V_111 , V_100 -> V_102 ,
V_113 , V_114 ) ;
F_32 ( V_100 -> V_111 , 0 ,
V_158 ,
F_71 ( V_100 -> V_159 ) ) ;
F_32 ( V_100 -> V_111 , 0 ,
V_160 ,
F_71 ( V_100 -> V_159 - 1 ) ) ;
F_32 ( V_100 -> V_111 , 0 ,
V_161 ,
F_71 ( V_100 -> V_159 ) ) ;
F_32 ( V_100 -> V_111 , 0 ,
V_162 ,
F_71 ( V_100 -> V_159 ) ) ;
}
static void F_72 ( struct V_13 * V_13 , T_6 * V_163 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_164 ;
F_60 ( V_19 -> V_111 , V_163 ,
F_71 ( V_19 -> V_159 ) , 0 , 0 ,
V_145 ) ;
F_73 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_60 ( V_19 -> V_111 , V_163 ,
F_71 ( V_19 -> V_159 ) ,
V_165 , V_164 , V_145 ) ;
}
}
static void F_74 ( struct V_13 * V_13 , T_6 * V_163 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_164 ;
F_75 ( V_19 -> V_111 , V_163 , V_19 -> V_102 , 0 , 0 ) ;
F_73 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID)
F_75 ( V_19 -> V_111 , V_163 , V_19 -> V_102 ,
V_165 , V_164 ) ;
}
static void F_76 ( struct V_13 * V_13 , T_6 * V_163 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_164 ;
F_52 ( V_19 -> V_111 , V_163 , 0 , 0 , 0 ) ;
F_73 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_52 ( V_19 -> V_111 , V_163 , 0 , V_165 , V_164 ) ;
}
}
static void F_77 ( struct V_13 * V_13 , T_6 * V_163 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_164 ;
F_78 ( V_19 -> V_111 , V_163 , V_19 -> V_102 , 0 , 0 ) ;
F_73 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_78 ( V_19 -> V_111 , V_163 , V_19 -> V_102 ,
V_165 , V_164 ) ;
}
}
static int F_79 ( void * V_166 , struct V_167 * V_168 )
{
struct V_13 * V_13 = V_166 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_63 ( V_19 -> V_149 , L_3 ,
V_168 -> V_163 , V_168 -> type ) ;
switch ( V_168 -> type ) {
case V_169 :
case V_170 :
F_72 ( V_13 , V_168 -> V_163 ) ;
break;
case V_171 :
case V_172 :
F_74 ( V_13 , V_168 -> V_163 ) ;
break;
case V_173 :
default:
break;
}
return 0 ;
}
static int F_80 ( void * V_166 , struct V_167 * V_168 )
{
struct V_13 * V_13 = V_166 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_63 ( V_19 -> V_149 , L_4 ,
V_168 -> V_163 , V_168 -> type ) ;
switch ( V_168 -> type ) {
case V_169 :
case V_170 :
F_76 ( V_13 , V_168 -> V_163 ) ;
break;
case V_171 :
case V_172 :
F_77 ( V_13 , V_168 -> V_163 ) ;
break;
case V_173 :
default:
break;
}
return 0 ;
}
static int F_81 ( void * V_166 , int V_174 )
{
struct V_13 * V_13 = V_166 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_82 ( V_174 , V_13 -> V_175 ) ;
F_83 ( V_19 -> V_111 , V_174 ,
F_71 ( V_19 -> V_159 ) ,
V_176 ,
F_71 ( V_19 -> V_159 ) ,
F_71 ( V_19 -> V_159 - 1 ) ) ;
return 0 ;
}
static int F_84 ( void * V_166 , int V_174 )
{
struct V_13 * V_13 = V_166 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_85 ( V_19 -> V_111 , V_174 , 0 ) ;
F_86 ( V_174 , V_13 -> V_175 ) ;
return 0 ;
}
static void F_87 ( void * V_177 , struct V_178 * V_179 )
{
struct V_13 * V_13 = V_177 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_88 ( V_19 -> V_79 , V_179 ) ;
}
static bool F_89 ( struct V_13 * V_13 ,
const struct V_180 * V_181 )
{
struct V_178 * V_179 = V_181 -> V_179 ;
unsigned int V_182 = F_90 ( V_179 ) ;
if ( V_182 == V_183 )
return false ;
switch ( V_182 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case ( V_189 | V_190 ) :
case ( V_189 | V_191 ) :
case ( V_189 | V_192 ) :
return true ;
}
return false ;
}
static int F_91 ( struct V_13 * V_13 ,
struct V_180 * V_181 )
{
struct V_57 * V_59 = V_181 -> V_179 -> V_149 -> V_59 ;
struct V_18 * V_19 = V_13 -> V_19 ;
if ( ! ( F_92 ( V_181 -> V_179 ) -> V_193 & V_194 ) ||
! F_93 ( V_19 -> V_79 ) )
return 0 ;
if ( V_59 && F_94 ( V_59 ) ) {
F_92 ( V_181 -> V_179 ) -> V_193 |= V_195 ;
return 0 ;
}
if ( F_89 ( V_13 , V_181 ) ) {
V_181 -> V_196 = F_87 ;
V_181 -> V_197 = ( void * ) V_13 ;
F_92 ( V_181 -> V_179 ) -> V_193 |= V_195 ;
}
return 0 ;
}
static int F_95 ( struct V_13 * V_13 , struct V_180 * V_181 )
{
struct V_57 * V_59 = V_181 -> V_179 -> V_149 -> V_59 ;
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_181 -> V_198 )
return 0 ;
if ( V_59 && F_96 ( V_59 ) ) {
V_181 -> V_198 = true ;
return 0 ;
}
F_97 ( V_19 -> V_79 , V_181 -> V_179 ) ;
V_181 -> V_198 = true ;
return 0 ;
}
static int F_98 ( struct V_13 * V_13 , struct V_199 * V_200 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_79 * V_79 = V_19 -> V_79 ;
struct V_201 V_202 ;
if ( ! V_79 )
return - V_203 ;
V_202 . V_204 = 0 ;
V_202 . V_205 = F_93 ( V_79 ) ?
V_90 : V_89 ;
V_202 . V_206 = ( F_99 ( V_79 ) ?
V_79 -> V_207 : V_92 ) ;
return F_100 ( V_200 -> V_208 , & V_202 , sizeof( V_202 ) ) ? - V_209 : 0 ;
}
static void F_101 ( struct V_13 * V_13 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_95 * V_61 = V_13 -> V_61 ;
T_1 V_210 , V_211 , V_212 ;
if ( ! F_99 ( V_19 -> V_79 ) &&
! F_93 ( V_19 -> V_79 ) ) {
F_15 ( 0 , F_14 ( V_61 , V_97 , V_213 ) ) ;
return;
}
V_211 = ( 30 << V_214 ) | V_215 ;
V_210 = V_216 << V_217 ;
V_212 = V_215 | V_218 |
( V_61 -> V_213 . V_219 << V_220 ) |
( V_61 -> V_213 . V_221 ? V_222 :
V_61 -> V_213 . V_223 << V_224 ) ;
if ( F_93 ( V_19 -> V_79 ) )
V_210 |= ( V_225 | V_226 ) ;
if ( F_99 ( V_19 -> V_79 ) )
V_210 |= ( V_227 | V_228 ) ;
F_15 ( V_210 , F_14 ( V_61 , V_97 , V_213 ) ) ;
F_15 ( V_211 , F_14 ( V_61 , V_97 , V_229 ) ) ;
F_15 ( V_212 , F_14 ( V_61 , V_97 , V_230 ) ) ;
}
static int F_102 ( struct V_13 * V_13 , struct V_199 * V_200 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_79 * V_79 = V_19 -> V_79 ;
struct V_201 V_202 ;
if ( ! V_79 )
return - V_203 ;
if ( F_103 ( & V_202 , V_200 -> V_208 , sizeof( V_202 ) ) )
return - V_209 ;
if ( V_202 . V_204 )
return - V_27 ;
switch ( V_202 . V_205 ) {
case V_89 :
F_104 ( V_79 , 0 ) ;
break;
case V_90 :
F_104 ( V_79 , 1 ) ;
break;
default:
return - V_231 ;
}
switch ( V_202 . V_206 ) {
case V_92 :
F_105 ( V_79 , 0 ) ;
break;
case V_232 :
case V_93 :
case V_233 :
case V_234 :
F_105 ( V_79 , V_93 ) ;
V_202 . V_206 = V_93 ;
break;
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_94 :
case V_241 :
case V_242 :
F_105 ( V_79 , V_94 ) ;
V_202 . V_206 = V_94 ;
break;
default:
return - V_231 ;
}
F_101 ( V_13 ) ;
return F_100 ( V_200 -> V_208 , & V_202 , sizeof( V_202 ) ) ? - V_209 : 0 ;
}
static void F_106 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_79 )
return;
if ( V_19 -> V_243 > 0 )
goto V_244;
if ( F_107 ( V_19 -> V_79 ) ) {
F_62 ( V_19 -> V_149 , L_5 ) ;
return;
}
V_244:
++ V_19 -> V_243 ;
}
static void F_108 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_79 || ( V_19 -> V_243 <= 0 ) )
return;
if ( -- V_19 -> V_243 )
return;
F_109 ( V_19 -> V_79 ) ;
}
static inline int F_91 ( struct V_13 * V_13 ,
struct V_180 * V_181 )
{
return 0 ;
}
static inline int F_95 ( struct V_13 * V_13 ,
struct V_180 * V_181 )
{
return 0 ;
}
static inline int F_101 ( struct V_13 * V_13 ,
struct V_199 * V_200 , int V_56 )
{
return - V_203 ;
}
static inline void F_106 ( struct V_18 * V_19 )
{
}
static inline void F_108 ( struct V_18 * V_19 )
{
}
static inline int F_98 ( struct V_13 * V_13 , struct V_199 * V_245 )
{
return - V_203 ;
}
static inline int F_102 ( struct V_13 * V_13 , struct V_199 * V_245 )
{
return - V_203 ;
}
static int F_110 ( void * V_166 , struct V_199 * V_245 , int V_56 )
{
struct V_13 * V_13 = V_166 ;
struct V_57 * V_58 = V_13 -> V_61 -> V_58 ;
if ( ! V_58 || ! V_58 -> V_246 -> V_247 ) {
switch ( V_56 ) {
case V_248 :
return F_98 ( V_13 , V_245 ) ;
case V_249 :
return F_102 ( V_13 , V_245 ) ;
}
}
if ( V_58 )
return F_111 ( V_58 , V_245 , V_56 ) ;
return - V_203 ;
}
static void F_112 ( unsigned long V_250 )
{
struct V_18 * V_19 = (struct V_18 * ) V_250 ;
struct V_13 * V_13 ;
struct V_95 * V_61 ;
F_113 (gbe_intf, gbe_dev) {
if ( ! V_13 -> V_61 -> V_115 )
continue;
F_37 ( V_19 , V_13 -> V_61 ,
V_13 -> V_2 ) ;
}
F_45 (slave, gbe_dev) {
F_37 ( V_19 , V_61 , NULL ) ;
}
F_114 ( & V_19 -> V_52 ) ;
if ( V_19 -> V_53 == V_54 )
F_17 ( V_19 , NULL ) ;
else
F_12 ( V_19 , NULL ) ;
F_115 ( & V_19 -> V_52 ) ;
V_19 -> V_251 . V_252 = V_253 + V_254 ;
F_116 ( & V_19 -> V_251 ) ;
}
static int F_117 ( int V_255 , void * V_17 , struct V_180 * V_181 )
{
struct V_13 * V_13 = V_17 ;
V_181 -> V_256 = & V_13 -> V_256 ;
return F_91 ( V_13 , V_181 ) ;
}
static int F_118 ( int V_255 , void * V_17 , struct V_180 * V_181 )
{
struct V_13 * V_13 = V_17 ;
return F_95 ( V_13 , V_181 ) ;
}
static int F_119 ( void * V_166 , struct V_1 * V_2 )
{
struct V_13 * V_13 = V_166 ;
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_95 * V_61 = V_13 -> V_61 ;
int V_112 = V_61 -> V_112 ;
T_1 V_257 ;
int V_60 ;
V_257 = F_10 ( F_14 ( V_19 , V_39 , V_258 ) ) ;
F_63 ( V_19 -> V_149 , L_6 ,
F_120 ( V_257 ) , F_121 ( V_257 ) ,
F_122 ( V_257 ) , F_123 ( V_257 ) ) ;
if ( ( V_19 -> V_53 == V_135 ) || F_48 ( V_19 ) )
V_13 -> V_256 . V_204 = V_259 ;
if ( V_19 -> V_155 )
V_13 -> V_256 . V_260 = 0 ;
else
V_13 -> V_256 . V_260 = V_112 ;
F_63 ( V_19 -> V_149 ,
L_7 ,
V_13 -> V_256 . V_261 ,
V_13 -> V_256 . V_262 ,
V_13 -> V_256 . V_260 ,
V_13 -> V_256 . V_204 ) ;
F_51 ( V_13 ) ;
F_15 ( 0 , F_14 ( V_19 , V_39 , V_263 ) ) ;
F_15 ( V_264 , F_14 ( V_19 , V_39 , V_137 ) ) ;
F_15 ( V_19 -> V_265 , F_14 ( V_19 , V_39 ,
V_40 ) ) ;
V_60 = F_58 ( V_13 ) ;
if ( V_60 )
goto V_266;
F_124 ( V_10 , V_267 , F_117 , V_13 ) ;
F_125 ( V_10 , V_268 , F_118 , V_13 ) ;
V_61 -> V_115 = true ;
F_37 ( V_19 , V_61 , V_2 ) ;
F_106 ( V_19 ) ;
return 0 ;
V_266:
F_51 ( V_13 ) ;
return V_60 ;
}
static int F_126 ( void * V_166 , struct V_1 * V_2 )
{
struct V_13 * V_13 = V_166 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_108 ( V_19 ) ;
F_51 ( V_13 ) ;
F_127 ( V_10 , V_268 , F_118 , V_13 ) ;
F_128 ( V_10 , V_267 , F_117 , V_13 ) ;
V_13 -> V_61 -> V_115 = false ;
F_129 ( & V_13 -> V_61 -> V_124 , V_269 ) ;
return 0 ;
}
static void F_130 ( struct V_95 * V_61 )
{
V_61 -> V_213 . V_221 = 1 ;
V_61 -> V_213 . V_219 =
( V_270 >> V_220 ) & 0x3 ;
V_61 -> V_213 . V_223 =
( V_271 >> V_224 ) & 0x1f ;
}
static void F_130 ( struct V_95 * V_61 )
{
}
static int F_131 ( struct V_18 * V_19 , struct V_95 * V_61 ,
struct V_272 * V_273 )
{
int V_274 ;
T_1 V_275 , V_276 ;
T_1 V_277 , V_278 ;
if ( F_132 ( V_273 , L_8 , & V_61 -> V_101 ) ) {
F_62 ( V_19 -> V_149 , L_9 ) ;
return - V_27 ;
}
if ( F_132 ( V_273 , L_10 ,
& V_61 -> V_116 ) ) {
F_133 ( V_19 -> V_149 ,
L_11 ) ;
V_61 -> V_116 = V_117 ;
}
V_61 -> V_115 = false ;
V_61 -> V_148 = F_134 ( V_273 , L_12 , 0 ) ;
V_61 -> V_112 = F_30 ( V_19 , V_61 -> V_101 ) ;
if ( V_61 -> V_116 >= V_118 )
V_61 -> V_104 = V_279 ;
else
V_61 -> V_104 = V_280 ;
V_274 = V_61 -> V_101 ;
if ( V_19 -> V_53 == V_54 ) {
if ( V_61 -> V_101 > 1 ) {
V_275 = V_281 ;
V_274 -= 2 ;
} else {
V_275 = V_282 ;
}
V_276 = V_283 ;
V_277 = 0x30 ;
V_278 = 0x40 ;
} else if ( F_48 ( V_19 ) ) {
V_275 = V_284 ;
V_276 = V_285 ;
V_277 = 0x1000 ;
V_278 = 0x1000 ;
} else if ( V_19 -> V_53 == V_135 ) {
V_275 = V_286 ;
V_276 = V_287 ;
V_277 = 0x30 ;
V_278 = 0x40 ;
} else {
F_62 ( V_19 -> V_149 , L_13 ,
V_19 -> V_53 ) ;
return - V_27 ;
}
V_61 -> V_97 = V_19 -> V_39 + V_275 +
( V_277 * V_274 ) ;
V_61 -> V_110 = V_19 -> V_39 + V_276 +
( V_278 * V_61 -> V_101 ) ;
if ( V_19 -> V_53 == V_54 ) {
F_135 ( V_61 , V_97 , V_288 ) ;
F_135 ( V_61 , V_97 , V_154 ) ;
F_135 ( V_61 , V_97 , V_99 ) ;
F_135 ( V_61 , V_97 , V_98 ) ;
F_135 ( V_61 , V_97 , V_213 ) ;
F_135 ( V_61 , V_97 , V_229 ) ;
F_135 ( V_61 , V_97 , V_289 ) ;
F_135 ( V_61 , V_97 , V_230 ) ;
F_135 ( V_61 , V_97 , V_290 ) ;
F_135 ( V_61 , V_110 , V_104 ) ;
F_135 ( V_61 , V_110 , V_127 ) ;
F_135 ( V_61 , V_110 , V_138 ) ;
} else if ( F_48 ( V_19 ) ) {
F_136 ( V_61 , V_97 , V_288 ) ;
F_136 ( V_61 , V_97 , V_154 ) ;
F_136 ( V_61 , V_97 , V_99 ) ;
F_136 ( V_61 , V_97 , V_98 ) ;
F_136 ( V_61 , V_97 , V_213 ) ;
F_136 ( V_61 , V_97 , V_229 ) ;
F_136 ( V_61 , V_97 , V_289 ) ;
F_136 ( V_61 , V_97 , V_230 ) ;
F_136 ( V_61 , V_97 , V_290 ) ;
F_136 ( V_61 , V_97 , V_138 ) ;
F_136 ( V_61 , V_110 , V_104 ) ;
F_136 ( V_61 , V_110 , V_127 ) ;
} else if ( V_19 -> V_53 == V_135 ) {
F_137 ( V_61 , V_97 , V_288 ) ;
F_137 ( V_61 , V_97 , V_154 ) ;
F_137 ( V_61 , V_97 , V_99 ) ;
F_137 ( V_61 , V_97 , V_98 ) ;
F_137 ( V_61 , V_97 , V_213 ) ;
F_137 ( V_61 , V_97 , V_229 ) ;
F_137 ( V_61 , V_97 , V_289 ) ;
F_137 ( V_61 , V_97 , V_230 ) ;
F_137 ( V_61 , V_97 , V_290 ) ;
F_137 ( V_61 , V_110 , V_104 ) ;
F_137 ( V_61 , V_110 , V_127 ) ;
F_137 ( V_61 , V_110 , V_138 ) ;
}
F_129 ( & V_61 -> V_124 , V_269 ) ;
F_130 ( V_61 ) ;
return 0 ;
}
static void F_138 ( struct V_18 * V_19 ,
struct V_272 * V_273 )
{
struct V_291 * V_149 = V_19 -> V_149 ;
T_7 V_142 ;
struct V_18 * * V_100 ;
struct V_272 * V_62 ;
struct V_95 * V_61 ;
bool V_292 = false ;
F_139 (node, port) {
V_61 = F_140 ( V_149 , sizeof( * V_61 ) , V_293 ) ;
if ( ! V_61 ) {
F_62 ( V_149 ,
L_14 ,
V_62 -> V_294 ) ;
continue;
}
if ( F_131 ( V_19 , V_61 , V_62 ) ) {
F_62 ( V_149 ,
L_15 ,
V_62 -> V_294 ) ;
F_141 ( V_149 , V_61 ) ;
continue;
}
F_55 ( V_19 , V_61 ) ;
F_46 ( V_61 ) ;
F_47 ( V_19 , V_61 , V_19 -> V_144 ) ;
F_142 ( & V_61 -> V_295 , & V_19 -> V_296 ) ;
V_19 -> V_297 ++ ;
if ( ( V_61 -> V_116 == V_117 ) ||
( V_61 -> V_116 == V_118 ) )
V_292 = true ;
V_61 -> V_115 = true ;
if ( V_19 -> V_297 >= V_19 -> V_298 ) {
F_143 ( V_62 ) ;
break;
}
}
if ( ! V_292 )
return;
V_19 -> V_299 = F_144 ( sizeof( V_19 ) , L_16 ,
V_300 , V_301 ) ;
if ( ! V_19 -> V_299 ) {
F_62 ( V_149 ,
L_17 ) ;
return;
}
V_100 = F_3 ( V_19 -> V_299 ) ;
* V_100 = V_19 ;
if ( V_61 -> V_116 == V_117 ) {
V_142 = V_146 ;
V_61 -> V_63 = V_74 ;
} else {
V_142 = V_147 ;
V_61 -> V_63 = V_76 ;
}
F_45 (slave, gbe_dev) {
if ( ( V_61 -> V_116 != V_117 ) &&
( V_61 -> V_116 != V_118 ) )
continue;
V_61 -> V_58 =
F_61 ( V_19 -> V_299 ,
V_61 -> V_148 ,
F_44 ,
0 , V_142 ) ;
if ( ! V_61 -> V_58 ) {
F_62 ( V_149 , L_18 ,
V_61 -> V_101 ) ;
V_61 -> V_58 = NULL ;
} else {
F_63 ( V_149 , L_2 ,
F_64 ( V_61 -> V_58 ) ) ;
F_65 ( V_61 -> V_58 ) ;
F_66 ( V_61 -> V_58 ) ;
}
}
}
static void F_145 ( struct V_18 * V_19 )
{
struct V_95 * V_61 ;
while ( ! F_146 ( & V_19 -> V_296 ) ) {
V_61 = F_147 ( V_19 ) ;
if ( V_61 -> V_58 )
F_54 ( V_61 -> V_58 ) ;
F_148 ( & V_61 -> V_295 ) ;
}
if ( V_19 -> V_299 )
F_149 ( V_19 -> V_299 ) ;
}
static int F_150 ( struct V_18 * V_19 ,
struct V_272 * V_273 )
{
struct V_302 V_303 ;
void T_4 * V_304 ;
int V_60 , V_20 ;
V_60 = F_151 ( V_273 , V_305 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_19 ,
V_273 -> V_294 , V_305 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 , L_20 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_136 = V_304 ;
V_60 = F_151 ( V_273 , V_306 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_21 ,
V_273 -> V_294 , V_306 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 , L_22 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_39 = V_304 ;
V_60 = F_151 ( V_273 , V_307 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_23 ,
V_273 -> V_294 , V_307 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 , L_24 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_308 = V_304 ;
V_19 -> V_309 = V_19 -> V_310 ;
V_19 -> V_23 = V_311 ;
V_19 -> V_22 = F_155 ( V_311 ) ;
V_19 -> V_33 = F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( V_312 ) ,
V_293 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_149 , L_25 ) ;
return - V_313 ;
}
V_19 -> V_34 =
F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_293 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_149 ,
L_26 ) ;
return - V_313 ;
}
V_19 -> V_53 = V_135 ;
V_19 -> V_314 = V_19 -> V_136 +
V_315 ;
V_19 -> V_153 = V_19 -> V_136 + V_316 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_310 ; V_20 ++ )
V_19 -> V_30 [ V_20 ] = V_19 -> V_39 +
V_317 + ( V_318 * V_20 ) ;
V_19 -> V_319 = V_19 -> V_39 + V_320 ;
V_19 -> V_321 = V_19 -> V_39 + V_322 ;
V_19 -> V_159 = V_19 -> V_310 ;
V_19 -> V_102 = V_323 ;
V_19 -> V_324 = V_325 ;
V_19 -> V_265 = ( 1 << ( V_19 -> V_310 ) ) - 1 ;
F_137 ( V_19 , V_136 , V_258 ) ;
F_137 ( V_19 , V_136 , V_137 ) ;
F_137 ( V_19 , V_39 , V_258 ) ;
F_137 ( V_19 , V_39 , V_137 ) ;
F_137 ( V_19 , V_39 , V_263 ) ;
F_137 ( V_19 , V_39 , V_40 ) ;
F_137 ( V_19 , V_39 , V_326 ) ;
F_137 ( V_19 , V_153 , V_288 ) ;
F_137 ( V_19 , V_153 , V_154 ) ;
F_137 ( V_19 , V_153 , V_138 ) ;
return 0 ;
}
static int F_156 ( struct V_18 * V_19 ,
struct V_272 * V_273 )
{
struct V_302 V_303 ;
void T_4 * V_304 ;
int V_60 ;
V_60 = F_151 ( V_273 , V_327 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_27 ,
V_273 -> V_294 , V_327 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 , L_28 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_136 = V_304 ;
V_19 -> V_53 = F_10 ( V_19 -> V_136 ) ;
return 0 ;
}
static int F_157 ( struct V_18 * V_19 ,
struct V_272 * V_273 )
{
struct V_302 V_303 ;
void T_4 * V_304 ;
int V_20 , V_60 ;
V_60 = F_151 ( V_273 , V_328 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_29 ,
V_273 -> V_294 , V_328 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 ,
L_30 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_329 = V_304 ;
V_60 = F_151 ( V_273 , V_330 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_29 ,
V_273 -> V_294 , V_330 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 ,
L_31 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_39 = V_304 ;
V_19 -> V_309 = V_19 -> V_298 ;
V_19 -> V_23 = V_331 ;
V_19 -> V_22 = F_155 ( V_331 ) ;
V_19 -> V_33 = F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( V_312 ) ,
V_293 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_149 , L_25 ) ;
return - V_313 ;
}
V_19 -> V_34 =
F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_293 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_149 ,
L_26 ) ;
return - V_313 ;
}
V_19 -> V_314 = V_19 -> V_136 + V_332 ;
V_19 -> V_153 = V_19 -> V_39 + V_333 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_298 ; V_20 ++ ) {
V_19 -> V_30 [ V_20 ] =
V_19 -> V_39 + V_334 +
( V_318 * ( V_20 & 0x1 ) ) ;
}
V_19 -> V_321 = V_19 -> V_39 + V_335 ;
V_19 -> V_319 = V_19 -> V_39 + V_336 ;
V_19 -> V_159 = V_19 -> V_310 ;
V_19 -> V_102 = V_337 ;
V_19 -> V_324 = V_338 ;
V_19 -> V_265 = V_339 ;
F_135 ( V_19 , V_136 , V_258 ) ;
F_135 ( V_19 , V_39 , V_258 ) ;
F_135 ( V_19 , V_39 , V_137 ) ;
F_135 ( V_19 , V_39 , V_127 ) ;
F_135 ( V_19 , V_39 , V_40 ) ;
F_135 ( V_19 , V_39 , V_263 ) ;
F_135 ( V_19 , V_39 , V_326 ) ;
F_135 ( V_19 , V_153 , V_288 ) ;
F_135 ( V_19 , V_153 , V_138 ) ;
return 0 ;
}
static int F_158 ( struct V_18 * V_19 ,
struct V_272 * V_273 )
{
struct V_302 V_303 ;
void T_4 * V_304 ;
int V_20 , V_60 ;
V_19 -> V_309 = V_19 -> V_310 ;
V_19 -> V_23 = V_340 ;
if ( F_68 ( V_19 ) )
V_19 -> V_22 = V_341 +
( V_19 -> V_298 * V_342 ) ;
else
V_19 -> V_22 = V_341 +
V_342 ;
V_19 -> V_33 = F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( V_312 ) ,
V_293 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_149 , L_25 ) ;
return - V_313 ;
}
V_19 -> V_34 =
F_140 ( V_19 -> V_149 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_293 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_149 ,
L_26 ) ;
return - V_313 ;
}
V_60 = F_151 ( V_273 , V_343 , & V_303 ) ;
if ( V_60 ) {
F_62 ( V_19 -> V_149 ,
L_32 ,
V_273 -> V_294 , V_343 ) ;
return V_60 ;
}
V_304 = F_152 ( V_19 -> V_149 , & V_303 ) ;
if ( F_153 ( V_304 ) ) {
F_62 ( V_19 -> V_149 ,
L_33 ) ;
return F_154 ( V_304 ) ;
}
V_19 -> V_39 = V_304 ;
V_19 -> V_314 = V_19 -> V_136 + V_344 ;
V_19 -> V_329 = V_19 -> V_314 +
( 2 * V_345 ) ;
V_19 -> V_153 = V_19 -> V_39 + V_346 ;
for ( V_20 = 0 ; V_20 < ( V_19 -> V_310 ) ; V_20 ++ )
V_19 -> V_30 [ V_20 ] = V_19 -> V_39 +
V_347 + ( V_348 * V_20 ) ;
V_19 -> V_321 = V_19 -> V_39 + V_349 ;
V_19 -> V_319 = V_19 -> V_39 + V_350 ;
V_19 -> V_159 = V_19 -> V_310 ;
V_19 -> V_102 = V_351 ;
V_19 -> V_324 = V_338 ;
V_19 -> V_265 = ( 1 << ( V_19 -> V_310 ) ) - 1 ;
F_136 ( V_19 , V_136 , V_258 ) ;
F_136 ( V_19 , V_39 , V_258 ) ;
F_136 ( V_19 , V_39 , V_137 ) ;
F_136 ( V_19 , V_39 , V_40 ) ;
F_136 ( V_19 , V_39 , V_263 ) ;
F_136 ( V_19 , V_153 , V_288 ) ;
F_136 ( V_19 , V_153 , V_138 ) ;
F_136 ( V_19 , V_153 , V_154 ) ;
return 0 ;
}
static int F_159 ( struct V_352 * V_352 , struct V_291 * V_149 ,
struct V_272 * V_273 , void * * V_353 )
{
struct V_272 * V_354 , * V_355 ;
struct V_272 * V_356 ;
struct V_357 V_358 ;
struct V_18 * V_19 ;
T_1 V_101 ;
int V_20 , V_60 = 0 ;
if ( ! V_273 ) {
F_62 ( V_149 , L_34 ) ;
return - V_150 ;
}
V_19 = F_140 ( V_149 , sizeof( struct V_18 ) , V_293 ) ;
if ( ! V_19 )
return - V_313 ;
if ( F_160 ( V_273 , L_35 ) ||
F_160 ( V_273 , L_36 ) ) {
V_19 -> V_298 = 4 ;
} else if ( F_160 ( V_273 , L_37 ) ) {
V_19 -> V_298 = 8 ;
} else if ( F_160 ( V_273 , L_38 ) ) {
V_19 -> V_298 = 1 ;
} else if ( F_160 ( V_273 , L_39 ) ) {
V_19 -> V_298 = 2 ;
} else {
F_62 ( V_149 , L_40 ) ;
return - V_27 ;
}
V_19 -> V_310 = V_19 -> V_298 + 1 ;
V_19 -> V_149 = V_149 ;
V_19 -> V_352 = V_352 ;
V_19 -> V_144 = V_134 ;
F_161 ( & V_19 -> V_52 ) ;
if ( F_162 ( V_273 , L_41 , NULL ) ) {
V_19 -> V_155 = true ;
F_163 ( V_149 , L_42 ) ;
} else {
V_19 -> V_155 = false ;
F_63 ( V_149 , L_43 ) ;
}
V_60 = F_132 ( V_273 , L_44 ,
& V_19 -> V_359 ) ;
if ( V_60 < 0 ) {
F_62 ( V_149 , L_45 ) ;
V_19 -> V_359 = V_360 ;
}
V_60 = F_164 ( V_273 , L_46 ,
& V_19 -> V_261 ) ;
if ( V_60 < 0 ) {
F_62 ( V_149 , L_47 ) ;
return - V_27 ;
}
if ( ! strcmp ( V_273 -> V_294 , L_48 ) ) {
V_60 = F_156 ( V_19 , V_273 ) ;
if ( V_60 )
return V_60 ;
F_63 ( V_149 , L_49 , V_19 -> V_53 ) ;
if ( V_19 -> V_53 == V_54 )
V_60 = F_157 ( V_19 , V_273 ) ;
else if ( F_48 ( V_19 ) )
V_60 = F_158 ( V_19 , V_273 ) ;
else
V_60 = - V_150 ;
} else if ( ! strcmp ( V_273 -> V_294 , L_50 ) ) {
V_60 = F_150 ( V_19 , V_273 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_165 ( V_19 -> V_308 ,
V_19 -> V_136 ) ;
} else {
F_62 ( V_149 , L_51 , V_273 -> V_294 ) ;
V_60 = - V_150 ;
}
if ( V_60 )
return V_60 ;
V_354 = F_166 ( V_273 , L_52 ) ;
if ( ! V_354 )
F_62 ( V_149 , L_53 ) ;
V_60 = F_167 ( & V_19 -> V_256 , V_352 ,
V_19 -> V_261 , V_19 -> V_359 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_168 ( & V_19 -> V_256 ) ;
if ( V_60 )
return V_60 ;
F_169 ( & V_19 -> V_361 ) ;
F_139 (interfaces, interface) {
V_60 = F_132 ( V_355 , L_8 , & V_101 ) ;
if ( V_60 ) {
F_62 ( V_149 , L_54 ,
V_355 -> V_294 ) ;
continue;
}
V_19 -> V_297 ++ ;
if ( V_19 -> V_297 >= V_19 -> V_298 ) {
F_143 ( V_355 ) ;
break;
}
}
F_143 ( V_354 ) ;
if ( ! V_19 -> V_297 )
F_133 ( V_149 , L_55 ) ;
V_356 = F_166 ( V_273 , L_56 ) ;
F_169 ( & V_19 -> V_296 ) ;
if ( V_356 && ( V_19 -> V_297 < V_19 -> V_298 ) )
F_138 ( V_19 , V_356 ) ;
F_143 ( V_356 ) ;
if ( ! V_19 -> V_297 ) {
F_62 ( V_149 ,
L_57 ) ;
V_60 = - V_150 ;
goto V_362;
}
memset ( & V_358 , 0 , sizeof( V_358 ) ) ;
V_358 . V_149 = V_19 -> V_149 ;
V_358 . V_363 = V_19 -> V_319 ;
V_358 . V_364 = V_365 ;
V_358 . V_324 = V_19 -> V_324 ;
V_358 . V_159 = V_19 -> V_159 ;
V_19 -> V_111 = F_170 ( & V_358 ) ;
if ( ! V_19 -> V_111 ) {
F_62 ( V_19 -> V_149 , L_58 ) ;
V_60 = - V_150 ;
goto V_362;
} else {
F_63 ( V_19 -> V_149 , L_59 ) ;
}
V_19 -> V_79 = F_171 ( V_19 -> V_149 , V_19 -> V_321 , V_273 ) ;
if ( F_172 ( V_366 ) && F_153 ( V_19 -> V_79 ) ) {
V_60 = F_154 ( V_19 -> V_79 ) ;
goto V_362;
}
F_67 ( V_19 ) ;
F_19 ( & V_19 -> V_52 ) ;
for ( V_20 = 0 ; V_20 < V_19 -> V_309 ; V_20 ++ ) {
if ( V_19 -> V_53 == V_54 )
F_16 ( V_19 , V_20 ) ;
else
F_9 ( V_19 , V_20 ) ;
}
F_20 ( & V_19 -> V_52 ) ;
F_173 ( & V_19 -> V_251 ) ;
V_19 -> V_251 . V_17 = ( unsigned long ) V_19 ;
V_19 -> V_251 . V_367 = F_112 ;
V_19 -> V_251 . V_252 = V_253 + V_254 ;
F_116 ( & V_19 -> V_251 ) ;
* V_353 = V_19 ;
return 0 ;
V_362:
F_145 ( V_19 ) ;
return V_60 ;
}
static int F_174 ( void * V_353 , struct V_1 * V_2 ,
struct V_272 * V_273 , void * * V_166 )
{
struct V_18 * V_19 = V_353 ;
struct V_13 * V_13 ;
int V_60 ;
if ( ! V_273 ) {
F_62 ( V_19 -> V_149 , L_60 ) ;
return - V_150 ;
}
V_13 = F_140 ( V_19 -> V_149 , sizeof( * V_13 ) , V_293 ) ;
if ( ! V_13 )
return - V_313 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_149 = V_19 -> V_149 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_61 = F_140 ( V_19 -> V_149 ,
sizeof( * V_13 -> V_61 ) ,
V_293 ) ;
if ( ! V_13 -> V_61 ) {
V_60 = - V_313 ;
goto V_266;
}
if ( F_131 ( V_19 , V_13 -> V_61 , V_273 ) ) {
V_60 = - V_150 ;
goto V_266;
}
V_13 -> V_256 = V_19 -> V_256 ;
V_2 -> V_368 = & V_369 ;
F_142 ( & V_13 -> V_370 , & V_19 -> V_361 ) ;
* V_166 = V_13 ;
return 0 ;
V_266:
if ( V_13 -> V_61 )
F_141 ( V_19 -> V_149 , V_13 -> V_61 ) ;
if ( V_13 )
F_141 ( V_19 -> V_149 , V_13 ) ;
return V_60 ;
}
static int F_175 ( void * V_166 )
{
struct V_13 * V_13 = V_166 ;
V_13 -> V_2 -> V_368 = NULL ;
F_148 ( & V_13 -> V_370 ) ;
F_141 ( V_13 -> V_149 , V_13 -> V_61 ) ;
F_141 ( V_13 -> V_149 , V_13 ) ;
return 0 ;
}
static int F_176 ( struct V_352 * V_352 , void * V_353 )
{
struct V_18 * V_19 = V_353 ;
F_177 ( & V_19 -> V_251 ) ;
F_178 ( V_19 -> V_79 ) ;
F_179 ( V_19 -> V_111 ) ;
F_180 ( V_19 -> V_111 ) ;
F_181 ( & V_19 -> V_256 ) ;
F_145 ( V_19 ) ;
if ( ! F_146 ( & V_19 -> V_361 ) )
F_182 ( V_19 -> V_149 ,
L_61 ) ;
return 0 ;
}
static int T_9 F_183 ( void )
{
int V_60 ;
V_60 = F_184 ( & V_14 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_184 ( & V_15 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static void T_10 F_185 ( void )
{
F_186 ( & V_14 ) ;
F_186 ( & V_15 ) ;
}
