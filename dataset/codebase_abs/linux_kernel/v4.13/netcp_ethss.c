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
if ( ! V_58 )
return - V_27 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return - V_27 ;
if ( ! V_13 -> V_60 )
return - V_27 ;
F_22 ( V_58 , V_56 ) ;
V_56 -> V_29 . V_61 = V_13 -> V_60 -> V_62 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_57 * V_58 = V_2 -> V_59 ;
struct V_13 * V_13 ;
T_6 V_61 = V_56 -> V_29 . V_61 ;
T_1 V_63 , V_64 ;
T_1 V_65 ;
F_24 ( & V_63 ,
V_56 -> V_66 . V_63 ) ;
F_24 ( & V_64 ,
V_56 -> V_66 . V_64 ) ;
V_65 = V_63 & V_64 ;
if ( ! V_58 )
return - V_27 ;
V_13 = F_5 ( V_10 ) ;
if ( ! V_13 )
return - V_27 ;
if ( ! V_13 -> V_60 )
return - V_27 ;
if ( V_61 != V_13 -> V_60 -> V_62 ) {
if ( ( V_61 == V_67 ) && ! ( V_65 & V_68 ) )
return - V_27 ;
if ( ( V_61 == V_69 ) && ! ( V_65 & V_70 ) )
return - V_27 ;
if ( ( V_61 == V_71 ) && ! ( V_65 & V_72 ) )
return - V_27 ;
if ( ( V_61 == V_73 ) && ! ( V_65 & V_74 ) )
return - V_27 ;
if ( ( V_61 == V_75 ) && ! ( V_65 & V_76 ) )
return - V_27 ;
}
V_13 -> V_60 -> V_62 = V_61 ;
return F_25 ( V_58 , V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_77 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_14 , V_10 ) ;
if ( ! V_13 || ! V_13 -> V_19 -> V_78 )
return - V_27 ;
V_4 -> V_79 =
V_80 |
V_81 |
V_82 |
V_83 |
V_84 |
V_85 ;
V_4 -> V_86 = V_13 -> V_19 -> V_78 -> V_86 ;
V_4 -> V_87 =
( 1 << V_88 ) |
( 1 << V_89 ) ;
V_4 -> V_90 =
( 1 << V_91 ) |
( 1 << V_92 ) |
( 1 << V_93 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_77 * V_4 )
{
V_4 -> V_79 =
V_81 |
V_83 |
V_84 ;
V_4 -> V_86 = - 1 ;
V_4 -> V_87 = 0 ;
V_4 -> V_90 = 0 ;
return 0 ;
}
static void F_27 ( struct V_94 * V_60 ,
struct V_13 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_15 ( F_28 ( V_2 -> V_95 ) , F_14 ( V_60 , V_96 , V_97 ) ) ;
F_15 ( F_29 ( V_2 -> V_95 ) , F_14 ( V_60 , V_96 , V_98 ) ) ;
}
static int F_30 ( struct V_18 * V_99 , T_1 V_100 )
{
if ( V_99 -> V_101 == 0 )
return V_100 + 1 ;
return V_100 ;
}
static void F_31 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_94 * V_60 ,
int V_102 )
{
struct V_57 * V_58 = V_60 -> V_58 ;
T_1 V_103 = 0 ;
if ( V_102 ) {
V_103 = V_60 -> V_103 ;
if ( V_58 && ( V_58 -> V_104 == V_105 ) ) {
V_103 |= V_106 ;
V_103 &= ~ V_107 ;
} else if ( V_58 && ( V_58 -> V_104 == V_108 ) ) {
V_103 |= V_107 ;
V_103 &= ~ V_106 ;
}
F_15 ( V_103 , F_14 ( V_60 , V_109 ,
V_103 ) ) ;
F_32 ( V_19 -> V_110 , V_60 -> V_111 ,
V_112 ,
V_113 ) ;
if ( V_2 && V_60 -> V_114 &&
V_60 -> V_115 != V_116 &&
V_60 -> V_115 != V_117 )
F_33 ( V_2 ) ;
} else {
F_15 ( V_103 , F_14 ( V_60 , V_109 ,
V_103 ) ) ;
F_32 ( V_19 -> V_110 , V_60 -> V_111 ,
V_112 ,
V_118 ) ;
if ( V_2 &&
V_60 -> V_115 != V_116 &&
V_60 -> V_115 != V_117 )
F_34 ( V_2 ) ;
}
if ( V_58 )
F_35 ( V_58 ) ;
}
static bool F_36 ( struct V_94 * V_60 )
{
return ! V_60 -> V_58 || V_60 -> V_58 -> V_119 ;
}
static void F_37 ( struct V_18 * V_19 ,
struct V_94 * V_60 ,
struct V_1 * V_2 )
{
int V_120 = V_60 -> V_100 ;
int V_121 , V_122 = 1 , V_123 ;
if ( ! V_60 -> V_114 )
return;
if ( ! F_38 ( V_60 ) ) {
V_122 =
F_39 ( F_40 ( V_19 , V_120 ) , V_120 ) ;
}
V_121 = F_36 ( V_60 ) ;
V_123 = V_121 & V_122 ;
if ( F_41 ( & V_60 -> V_123 , V_123 ) != V_123 )
F_31 ( V_19 , V_2 , V_60 ,
V_123 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_15 , V_10 ) ;
if ( ! V_13 )
return;
F_37 ( V_13 -> V_19 , V_13 -> V_60 ,
V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_13 * V_13 ;
V_13 = F_6 ( & V_14 , V_10 ) ;
if ( ! V_13 )
return;
F_37 ( V_13 -> V_19 , V_13 -> V_60 ,
V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_3 ( V_2 ) ;
struct V_94 * V_60 ;
F_45 (slave, gbe_dev)
F_37 ( V_19 , V_60 , NULL ) ;
}
static int F_46 ( struct V_94 * V_60 )
{
T_1 V_20 , V_124 ;
F_15 ( V_125 , F_14 ( V_60 , V_109 , V_126 ) ) ;
for ( V_20 = 0 ; V_20 < V_127 ; V_20 ++ ) {
V_124 = F_10 ( F_14 ( V_60 , V_109 , V_126 ) ) ;
if ( ( V_124 & V_128 ) != V_125 )
return 0 ;
}
return V_129 ;
}
static void F_47 ( struct V_18 * V_19 , struct V_94 * V_60 ,
int V_130 )
{
void T_4 * V_131 ;
T_1 V_132 ;
if ( V_130 > V_133 )
V_130 = V_133 ;
if ( ( V_19 -> V_53 == V_134 ) &&
( V_60 -> V_115 >= V_117 ) ) {
V_132 = F_10 ( F_14 ( V_19 , V_135 , V_136 ) ) ;
V_132 |= ( 1 << V_60 -> V_100 ) ;
F_15 ( V_132 , F_14 ( V_19 , V_135 , V_136 ) ) ;
}
if ( F_48 ( V_19 ) )
V_131 = F_14 ( V_60 , V_96 , V_137 ) ;
else
V_131 = F_14 ( V_60 , V_109 , V_137 ) ;
F_15 ( V_130 , V_131 ) ;
F_15 ( V_60 -> V_103 , F_14 ( V_60 , V_109 , V_103 ) ) ;
}
static void F_49 ( struct V_18 * V_99 ,
struct V_94 * V_60 , bool V_138 )
{
if ( F_38 ( V_60 ) )
return;
F_50 ( F_40 ( V_99 , V_60 -> V_100 ) ,
V_60 -> V_100 , V_138 ) ;
}
static void F_51 ( struct V_13 * V_139 )
{
struct V_18 * V_19 = V_139 -> V_19 ;
struct V_94 * V_60 = V_139 -> V_60 ;
F_49 ( V_19 , V_60 , true ) ;
F_46 ( V_60 ) ;
F_32 ( V_19 -> V_110 , V_60 -> V_111 ,
V_112 , V_118 ) ;
F_52 ( V_19 -> V_110 , V_139 -> V_2 -> V_140 ,
1 << V_60 -> V_111 , 0 , 0 ) ;
if ( ! V_60 -> V_58 )
return;
F_53 ( V_60 -> V_58 ) ;
F_54 ( V_60 -> V_58 ) ;
V_60 -> V_58 = NULL ;
}
static void F_55 ( struct V_18 * V_99 , struct V_94 * V_60 )
{
if ( F_38 ( V_60 ) )
return;
F_56 ( F_40 ( V_99 , V_60 -> V_100 ) , V_60 -> V_100 ) ;
F_57 ( F_40 ( V_99 , V_60 -> V_100 ) , V_60 -> V_100 ,
V_60 -> V_115 ) ;
}
static int F_58 ( struct V_13 * V_13 )
{
struct V_18 * V_99 = V_13 -> V_19 ;
struct V_94 * V_60 = V_13 -> V_60 ;
T_7 V_141 ;
bool V_142 = false ;
void (* F_59)( struct V_1 * ) = F_43 ;
F_55 ( V_99 , V_60 ) ;
F_46 ( V_60 ) ;
F_49 ( V_99 , V_60 , false ) ;
F_47 ( V_99 , V_60 , V_99 -> V_143 ) ;
F_27 ( V_60 , V_13 ) ;
F_32 ( V_99 -> V_110 , V_60 -> V_111 ,
V_112 , V_113 ) ;
F_60 ( V_99 -> V_110 , V_13 -> V_2 -> V_140 ,
1 << V_60 -> V_111 , 0 , 0 , V_144 ) ;
if ( V_60 -> V_115 == V_116 ) {
V_142 = true ;
V_141 = V_145 ;
V_60 -> V_62 = V_73 ;
} else if ( V_60 -> V_115 == V_117 ) {
V_142 = true ;
V_141 = V_146 ;
V_60 -> V_62 = V_75 ;
}
if ( V_142 ) {
if ( V_99 -> V_53 == V_134 )
F_59 = F_42 ;
V_60 -> V_58 = F_61 ( V_13 -> V_2 ,
V_60 -> V_147 ,
F_59 , 0 ,
V_141 ) ;
if ( ! V_60 -> V_58 ) {
F_62 ( V_99 -> V_148 , L_1 ,
V_60 -> V_100 ) ;
return - V_149 ;
}
F_63 ( V_99 -> V_148 , L_2 ,
F_64 ( V_60 -> V_58 ) ) ;
F_65 ( V_60 -> V_58 ) ;
}
return 0 ;
}
static void F_66 ( struct V_18 * V_99 )
{
int V_150 = 1 ;
if ( F_67 ( V_99 ) || F_68 ( V_99 ) )
F_15 ( V_151 ,
F_14 ( V_99 , V_152 , V_153 ) ) ;
F_15 ( V_133 , F_14 ( V_99 , V_152 ,
V_137 ) ) ;
F_69 ( V_99 -> V_110 ) ;
if ( V_99 -> V_154 )
V_150 = 0 ;
F_32 ( V_99 -> V_110 , 0 , V_155 , V_150 ) ;
F_32 ( V_99 -> V_110 , 0 , V_156 , 1 ) ;
F_32 ( V_99 -> V_110 , V_99 -> V_101 ,
V_112 , V_113 ) ;
F_32 ( V_99 -> V_110 , 0 ,
V_157 ,
F_70 ( V_99 -> V_158 ) ) ;
F_32 ( V_99 -> V_110 , 0 ,
V_159 ,
F_70 ( V_99 -> V_158 - 1 ) ) ;
F_32 ( V_99 -> V_110 , 0 ,
V_160 ,
F_70 ( V_99 -> V_158 ) ) ;
F_32 ( V_99 -> V_110 , 0 ,
V_161 ,
F_70 ( V_99 -> V_158 ) ) ;
}
static void F_71 ( struct V_13 * V_13 , T_6 * V_162 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_163 ;
F_60 ( V_19 -> V_110 , V_162 ,
F_70 ( V_19 -> V_158 ) , 0 , 0 ,
V_144 ) ;
F_72 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_60 ( V_19 -> V_110 , V_162 ,
F_70 ( V_19 -> V_158 ) ,
V_164 , V_163 , V_144 ) ;
}
}
static void F_73 ( struct V_13 * V_13 , T_6 * V_162 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_163 ;
F_74 ( V_19 -> V_110 , V_162 , V_19 -> V_101 , 0 , 0 ) ;
F_72 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID)
F_74 ( V_19 -> V_110 , V_162 , V_19 -> V_101 ,
V_164 , V_163 ) ;
}
static void F_75 ( struct V_13 * V_13 , T_6 * V_162 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_163 ;
F_52 ( V_19 -> V_110 , V_162 , 0 , 0 , 0 ) ;
F_72 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_52 ( V_19 -> V_110 , V_162 , 0 , V_164 , V_163 ) ;
}
}
static void F_76 ( struct V_13 * V_13 , T_6 * V_162 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
T_8 V_163 ;
F_77 ( V_19 -> V_110 , V_162 , V_19 -> V_101 , 0 , 0 ) ;
F_72 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_77 ( V_19 -> V_110 , V_162 , V_19 -> V_101 ,
V_164 , V_163 ) ;
}
}
static int F_78 ( void * V_165 , struct V_166 * V_167 )
{
struct V_13 * V_13 = V_165 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_63 ( V_19 -> V_148 , L_3 ,
V_167 -> V_162 , V_167 -> type ) ;
switch ( V_167 -> type ) {
case V_168 :
case V_169 :
F_71 ( V_13 , V_167 -> V_162 ) ;
break;
case V_170 :
case V_171 :
F_73 ( V_13 , V_167 -> V_162 ) ;
break;
case V_172 :
default:
break;
}
return 0 ;
}
static int F_79 ( void * V_165 , struct V_166 * V_167 )
{
struct V_13 * V_13 = V_165 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_63 ( V_19 -> V_148 , L_4 ,
V_167 -> V_162 , V_167 -> type ) ;
switch ( V_167 -> type ) {
case V_168 :
case V_169 :
F_75 ( V_13 , V_167 -> V_162 ) ;
break;
case V_170 :
case V_171 :
F_76 ( V_13 , V_167 -> V_162 ) ;
break;
case V_172 :
default:
break;
}
return 0 ;
}
static int F_80 ( void * V_165 , int V_173 )
{
struct V_13 * V_13 = V_165 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_81 ( V_173 , V_13 -> V_174 ) ;
F_82 ( V_19 -> V_110 , V_173 ,
F_70 ( V_19 -> V_158 ) ,
V_175 ,
F_70 ( V_19 -> V_158 ) ,
F_70 ( V_19 -> V_158 - 1 ) ) ;
return 0 ;
}
static int F_83 ( void * V_165 , int V_173 )
{
struct V_13 * V_13 = V_165 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_84 ( V_19 -> V_110 , V_173 , 0 ) ;
F_85 ( V_173 , V_13 -> V_174 ) ;
return 0 ;
}
static void F_86 ( void * V_176 , struct V_177 * V_178 )
{
struct V_13 * V_13 = V_176 ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_87 ( V_19 -> V_78 , V_178 ) ;
}
static bool F_88 ( struct V_13 * V_13 ,
const struct V_179 * V_180 )
{
struct V_177 * V_178 = V_180 -> V_178 ;
return F_89 ( V_13 -> V_19 -> V_78 , V_178 ) ;
}
static int F_90 ( struct V_13 * V_13 ,
struct V_179 * V_180 )
{
struct V_57 * V_59 = V_180 -> V_178 -> V_148 -> V_59 ;
struct V_18 * V_19 = V_13 -> V_19 ;
if ( ! ( F_91 ( V_180 -> V_178 ) -> V_181 & V_182 ) ||
! F_92 ( V_19 -> V_78 ) )
return 0 ;
if ( V_59 && F_93 ( V_59 ) ) {
F_91 ( V_180 -> V_178 ) -> V_181 |= V_183 ;
return 0 ;
}
if ( F_88 ( V_13 , V_180 ) ) {
V_180 -> V_184 = F_86 ;
V_180 -> V_185 = ( void * ) V_13 ;
F_91 ( V_180 -> V_178 ) -> V_181 |= V_183 ;
}
return 0 ;
}
static int F_94 ( struct V_13 * V_13 , struct V_179 * V_180 )
{
struct V_57 * V_59 = V_180 -> V_178 -> V_148 -> V_59 ;
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_180 -> V_186 )
return 0 ;
if ( V_59 && F_95 ( V_59 ) ) {
V_180 -> V_186 = true ;
return 0 ;
}
F_96 ( V_19 -> V_78 , V_180 -> V_178 ) ;
V_180 -> V_186 = true ;
return 0 ;
}
static int F_97 ( struct V_13 * V_13 , struct V_187 * V_188 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_78 * V_78 = V_19 -> V_78 ;
struct V_189 V_190 ;
if ( ! V_78 )
return - V_191 ;
V_190 . V_192 = 0 ;
V_190 . V_193 = F_92 ( V_78 ) ?
V_89 : V_88 ;
V_190 . V_194 = ( F_98 ( V_78 ) ?
V_78 -> V_195 : V_91 ) ;
return F_99 ( V_188 -> V_196 , & V_190 , sizeof( V_190 ) ) ? - V_197 : 0 ;
}
static void F_100 ( struct V_13 * V_13 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_94 * V_60 = V_13 -> V_60 ;
T_1 V_198 , V_199 , V_200 ;
if ( ! F_98 ( V_19 -> V_78 ) &&
! F_92 ( V_19 -> V_78 ) ) {
F_15 ( 0 , F_14 ( V_60 , V_96 , V_201 ) ) ;
return;
}
V_199 = ( 30 << V_202 ) | V_203 ;
V_198 = V_204 << V_205 ;
V_200 = V_203 | V_206 |
( V_60 -> V_201 . V_207 << V_208 ) |
( V_60 -> V_201 . V_209 ? V_210 :
V_60 -> V_201 . V_211 << V_212 ) ;
if ( F_92 ( V_19 -> V_78 ) )
V_198 |= ( V_213 | V_214 ) ;
if ( F_98 ( V_19 -> V_78 ) )
V_198 |= ( V_215 | V_216 ) ;
F_15 ( V_198 , F_14 ( V_60 , V_96 , V_201 ) ) ;
F_15 ( V_199 , F_14 ( V_60 , V_96 , V_217 ) ) ;
F_15 ( V_200 , F_14 ( V_60 , V_96 , V_218 ) ) ;
}
static int F_101 ( struct V_13 * V_13 , struct V_187 * V_188 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_78 * V_78 = V_19 -> V_78 ;
struct V_189 V_190 ;
if ( ! V_78 )
return - V_191 ;
if ( F_102 ( & V_190 , V_188 -> V_196 , sizeof( V_190 ) ) )
return - V_197 ;
if ( V_190 . V_192 )
return - V_27 ;
switch ( V_190 . V_193 ) {
case V_88 :
F_103 ( V_78 , 0 ) ;
break;
case V_89 :
F_103 ( V_78 , 1 ) ;
break;
default:
return - V_219 ;
}
switch ( V_190 . V_194 ) {
case V_91 :
F_104 ( V_78 , 0 ) ;
break;
case V_92 :
case V_220 :
case V_221 :
F_104 ( V_78 , V_92 ) ;
V_190 . V_194 = V_92 ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_93 :
case V_228 :
case V_229 :
F_104 ( V_78 , V_93 ) ;
V_190 . V_194 = V_93 ;
break;
default:
return - V_219 ;
}
F_100 ( V_13 ) ;
return F_99 ( V_188 -> V_196 , & V_190 , sizeof( V_190 ) ) ? - V_197 : 0 ;
}
static void F_105 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_78 )
return;
if ( V_19 -> V_230 > 0 )
goto V_231;
if ( F_106 ( V_19 -> V_78 ) ) {
F_62 ( V_19 -> V_148 , L_5 ) ;
return;
}
V_231:
++ V_19 -> V_230 ;
}
static void F_107 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_78 || ( V_19 -> V_230 <= 0 ) )
return;
if ( -- V_19 -> V_230 )
return;
F_108 ( V_19 -> V_78 ) ;
}
static inline int F_90 ( struct V_13 * V_13 ,
struct V_179 * V_180 )
{
return 0 ;
}
static inline int F_94 ( struct V_13 * V_13 ,
struct V_179 * V_180 )
{
return 0 ;
}
static inline int F_100 ( struct V_13 * V_13 ,
struct V_187 * V_188 , int V_56 )
{
return - V_191 ;
}
static inline void F_105 ( struct V_18 * V_19 )
{
}
static inline void F_107 ( struct V_18 * V_19 )
{
}
static inline int F_97 ( struct V_13 * V_13 , struct V_187 * V_232 )
{
return - V_191 ;
}
static inline int F_101 ( struct V_13 * V_13 , struct V_187 * V_232 )
{
return - V_191 ;
}
static int F_109 ( void * V_165 , struct V_187 * V_232 , int V_56 )
{
struct V_13 * V_13 = V_165 ;
struct V_57 * V_58 = V_13 -> V_60 -> V_58 ;
if ( ! V_58 || ! V_58 -> V_233 -> V_234 ) {
switch ( V_56 ) {
case V_235 :
return F_97 ( V_13 , V_232 ) ;
case V_236 :
return F_101 ( V_13 , V_232 ) ;
}
}
if ( V_58 )
return F_110 ( V_58 , V_232 , V_56 ) ;
return - V_191 ;
}
static void F_111 ( unsigned long V_237 )
{
struct V_18 * V_19 = (struct V_18 * ) V_237 ;
struct V_13 * V_13 ;
struct V_94 * V_60 ;
F_112 (gbe_intf, gbe_dev) {
if ( ! V_13 -> V_60 -> V_114 )
continue;
F_37 ( V_19 , V_13 -> V_60 ,
V_13 -> V_2 ) ;
}
F_45 (slave, gbe_dev) {
F_37 ( V_19 , V_60 , NULL ) ;
}
F_113 ( & V_19 -> V_52 ) ;
if ( V_19 -> V_53 == V_54 )
F_17 ( V_19 , NULL ) ;
else
F_12 ( V_19 , NULL ) ;
F_114 ( & V_19 -> V_52 ) ;
V_19 -> V_238 . V_239 = V_240 + V_241 ;
F_115 ( & V_19 -> V_238 ) ;
}
static int F_116 ( int V_242 , void * V_17 , struct V_179 * V_180 )
{
struct V_13 * V_13 = V_17 ;
V_180 -> V_243 = & V_13 -> V_243 ;
return F_90 ( V_13 , V_180 ) ;
}
static int F_117 ( int V_242 , void * V_17 , struct V_179 * V_180 )
{
struct V_13 * V_13 = V_17 ;
return F_94 ( V_13 , V_180 ) ;
}
static int F_118 ( void * V_165 , struct V_1 * V_2 )
{
struct V_13 * V_13 = V_165 ;
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_94 * V_60 = V_13 -> V_60 ;
int V_111 = V_60 -> V_111 ;
T_1 V_244 , V_38 ;
int V_245 ;
V_244 = F_10 ( F_14 ( V_19 , V_39 , V_246 ) ) ;
F_63 ( V_19 -> V_148 , L_6 ,
F_119 ( V_244 ) , F_120 ( V_244 ) ,
F_121 ( V_244 ) , F_122 ( V_244 ) ) ;
if ( ( V_19 -> V_53 == V_134 ) || F_48 ( V_19 ) )
V_13 -> V_243 . V_192 = V_247 ;
if ( V_19 -> V_154 )
V_13 -> V_243 . V_248 = 0 ;
else
V_13 -> V_243 . V_248 = V_111 ;
F_63 ( V_19 -> V_148 ,
L_7 ,
V_13 -> V_243 . V_249 ,
V_13 -> V_243 . V_250 ,
V_13 -> V_243 . V_248 ,
V_13 -> V_243 . V_192 ) ;
F_51 ( V_13 ) ;
F_15 ( 0 , F_14 ( V_19 , V_39 , V_251 ) ) ;
V_38 = V_252 ;
if ( F_48 ( V_19 ) ) {
V_38 |= V_253 ;
V_10 -> V_254 = V_255 ;
}
F_15 ( V_38 , F_14 ( V_19 , V_39 , V_136 ) ) ;
F_15 ( V_19 -> V_256 , F_14 ( V_19 , V_39 ,
V_40 ) ) ;
V_245 = F_58 ( V_13 ) ;
if ( V_245 )
goto V_257;
F_123 ( V_10 , V_258 , F_116 , V_13 ) ;
F_124 ( V_10 , V_259 , F_117 , V_13 ) ;
V_60 -> V_114 = true ;
F_37 ( V_19 , V_60 , V_2 ) ;
F_105 ( V_19 ) ;
return 0 ;
V_257:
F_51 ( V_13 ) ;
return V_245 ;
}
static int F_125 ( void * V_165 , struct V_1 * V_2 )
{
struct V_13 * V_13 = V_165 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_18 * V_19 = V_13 -> V_19 ;
F_107 ( V_19 ) ;
F_51 ( V_13 ) ;
F_126 ( V_10 , V_259 , F_117 , V_13 ) ;
F_127 ( V_10 , V_258 , F_116 , V_13 ) ;
V_13 -> V_60 -> V_114 = false ;
F_128 ( & V_13 -> V_60 -> V_123 , V_260 ) ;
return 0 ;
}
static void F_129 ( struct V_94 * V_60 )
{
V_60 -> V_201 . V_209 = 1 ;
V_60 -> V_201 . V_207 =
( V_261 >> V_208 ) & 0x3 ;
V_60 -> V_201 . V_211 =
( V_262 >> V_212 ) & 0x1f ;
}
static void F_129 ( struct V_94 * V_60 )
{
}
static int F_130 ( struct V_18 * V_19 , struct V_94 * V_60 ,
struct V_263 * V_264 )
{
int V_265 ;
T_1 V_266 , V_267 ;
T_1 V_268 , V_269 ;
if ( F_131 ( V_264 , L_8 , & V_60 -> V_100 ) ) {
F_62 ( V_19 -> V_148 , L_9 ) ;
return - V_27 ;
}
if ( F_131 ( V_264 , L_10 ,
& V_60 -> V_115 ) ) {
F_132 ( V_19 -> V_148 ,
L_11 ) ;
V_60 -> V_115 = V_116 ;
}
V_60 -> V_114 = false ;
if ( ( V_60 -> V_115 == V_116 ) ||
( V_60 -> V_115 == V_117 ) )
V_60 -> V_147 = F_133 ( V_264 , L_12 , 0 ) ;
V_60 -> V_111 = F_30 ( V_19 , V_60 -> V_100 ) ;
if ( V_60 -> V_115 >= V_117 )
V_60 -> V_103 = V_270 ;
else
V_60 -> V_103 = V_271 ;
V_265 = V_60 -> V_100 ;
if ( V_19 -> V_53 == V_54 ) {
if ( V_60 -> V_100 > 1 ) {
V_266 = V_272 ;
V_265 -= 2 ;
} else {
V_266 = V_273 ;
}
V_267 = V_274 ;
V_268 = 0x30 ;
V_269 = 0x40 ;
} else if ( F_48 ( V_19 ) ) {
V_266 = V_275 ;
V_267 = V_276 ;
V_268 = 0x1000 ;
V_269 = 0x1000 ;
} else if ( V_19 -> V_53 == V_134 ) {
V_266 = V_277 ;
V_267 = V_278 ;
V_268 = 0x30 ;
V_269 = 0x40 ;
} else {
F_62 ( V_19 -> V_148 , L_13 ,
V_19 -> V_53 ) ;
return - V_27 ;
}
V_60 -> V_96 = V_19 -> V_39 + V_266 +
( V_268 * V_265 ) ;
V_60 -> V_109 = V_19 -> V_39 + V_267 +
( V_269 * V_60 -> V_100 ) ;
if ( V_19 -> V_53 == V_54 ) {
F_134 ( V_60 , V_96 , V_279 ) ;
F_134 ( V_60 , V_96 , V_153 ) ;
F_134 ( V_60 , V_96 , V_98 ) ;
F_134 ( V_60 , V_96 , V_97 ) ;
F_134 ( V_60 , V_96 , V_201 ) ;
F_134 ( V_60 , V_96 , V_217 ) ;
F_134 ( V_60 , V_96 , V_280 ) ;
F_134 ( V_60 , V_96 , V_218 ) ;
F_134 ( V_60 , V_96 , V_281 ) ;
F_134 ( V_60 , V_109 , V_103 ) ;
F_134 ( V_60 , V_109 , V_126 ) ;
F_134 ( V_60 , V_109 , V_137 ) ;
} else if ( F_48 ( V_19 ) ) {
F_135 ( V_60 , V_96 , V_279 ) ;
F_135 ( V_60 , V_96 , V_153 ) ;
F_135 ( V_60 , V_96 , V_98 ) ;
F_135 ( V_60 , V_96 , V_97 ) ;
F_135 ( V_60 , V_96 , V_201 ) ;
F_135 ( V_60 , V_96 , V_217 ) ;
F_135 ( V_60 , V_96 , V_280 ) ;
F_135 ( V_60 , V_96 , V_218 ) ;
F_135 ( V_60 , V_96 , V_281 ) ;
F_135 ( V_60 , V_96 , V_137 ) ;
F_135 ( V_60 , V_109 , V_103 ) ;
F_135 ( V_60 , V_109 , V_126 ) ;
} else if ( V_19 -> V_53 == V_134 ) {
F_136 ( V_60 , V_96 , V_279 ) ;
F_136 ( V_60 , V_96 , V_153 ) ;
F_136 ( V_60 , V_96 , V_98 ) ;
F_136 ( V_60 , V_96 , V_97 ) ;
F_136 ( V_60 , V_96 , V_201 ) ;
F_136 ( V_60 , V_96 , V_217 ) ;
F_136 ( V_60 , V_96 , V_280 ) ;
F_136 ( V_60 , V_96 , V_218 ) ;
F_136 ( V_60 , V_96 , V_281 ) ;
F_136 ( V_60 , V_109 , V_103 ) ;
F_136 ( V_60 , V_109 , V_126 ) ;
F_136 ( V_60 , V_109 , V_137 ) ;
}
F_128 ( & V_60 -> V_123 , V_260 ) ;
F_129 ( V_60 ) ;
return 0 ;
}
static void F_137 ( struct V_18 * V_19 ,
struct V_263 * V_264 )
{
struct V_282 * V_148 = V_19 -> V_148 ;
T_7 V_141 ;
struct V_18 * * V_99 ;
struct V_263 * V_61 ;
struct V_94 * V_60 ;
bool V_283 = false ;
F_138 (node, port) {
V_60 = F_139 ( V_148 , sizeof( * V_60 ) , V_284 ) ;
if ( ! V_60 ) {
F_62 ( V_148 , L_14 ,
V_61 -> V_285 ) ;
continue;
}
if ( F_130 ( V_19 , V_60 , V_61 ) ) {
F_62 ( V_148 ,
L_15 ,
V_61 -> V_285 ) ;
F_140 ( V_148 , V_60 ) ;
continue;
}
F_55 ( V_19 , V_60 ) ;
F_46 ( V_60 ) ;
F_47 ( V_19 , V_60 , V_19 -> V_143 ) ;
F_141 ( & V_60 -> V_286 , & V_19 -> V_287 ) ;
V_19 -> V_288 ++ ;
if ( ( V_60 -> V_115 == V_116 ) ||
( V_60 -> V_115 == V_117 ) )
V_283 = true ;
V_60 -> V_114 = true ;
if ( V_19 -> V_288 >= V_19 -> V_289 ) {
F_142 ( V_61 ) ;
break;
}
}
if ( ! V_283 )
return;
V_19 -> V_290 = F_143 ( sizeof( V_19 ) , L_16 ,
V_291 , V_292 ) ;
if ( ! V_19 -> V_290 ) {
F_62 ( V_148 ,
L_17 ) ;
return;
}
V_99 = F_3 ( V_19 -> V_290 ) ;
* V_99 = V_19 ;
if ( V_60 -> V_115 == V_116 ) {
V_141 = V_145 ;
V_60 -> V_62 = V_73 ;
} else {
V_141 = V_146 ;
V_60 -> V_62 = V_75 ;
}
F_45 (slave, gbe_dev) {
if ( ( V_60 -> V_115 != V_116 ) &&
( V_60 -> V_115 != V_117 ) )
continue;
V_60 -> V_58 =
F_61 ( V_19 -> V_290 ,
V_60 -> V_147 ,
F_44 ,
0 , V_141 ) ;
if ( ! V_60 -> V_58 ) {
F_62 ( V_148 , L_18 ,
V_60 -> V_100 ) ;
V_60 -> V_58 = NULL ;
} else {
F_63 ( V_148 , L_2 ,
F_64 ( V_60 -> V_58 ) ) ;
F_65 ( V_60 -> V_58 ) ;
}
}
}
static void F_144 ( struct V_18 * V_19 )
{
struct V_94 * V_60 ;
while ( ! F_145 ( & V_19 -> V_287 ) ) {
V_60 = F_146 ( V_19 ) ;
if ( V_60 -> V_58 )
F_54 ( V_60 -> V_58 ) ;
F_147 ( & V_60 -> V_286 ) ;
}
if ( V_19 -> V_290 )
F_148 ( V_19 -> V_290 ) ;
}
static int F_149 ( struct V_18 * V_19 ,
struct V_263 * V_264 )
{
struct V_293 V_294 ;
void T_4 * V_295 ;
int V_245 , V_20 ;
V_245 = F_150 ( V_264 , V_296 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_19 ,
V_264 -> V_285 , V_296 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 , L_20 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_135 = V_295 ;
V_245 = F_150 ( V_264 , V_297 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_21 ,
V_264 -> V_285 , V_297 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 , L_22 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_39 = V_295 ;
V_245 = F_150 ( V_264 , V_298 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_23 ,
V_264 -> V_285 , V_298 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 , L_24 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_299 = V_295 ;
V_19 -> V_300 = V_19 -> V_301 ;
V_19 -> V_23 = V_302 ;
V_19 -> V_22 = F_154 ( V_302 ) ;
V_19 -> V_33 = F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( V_303 ) ,
V_284 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_148 , L_25 ) ;
return - V_304 ;
}
V_19 -> V_34 =
F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_284 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_148 ,
L_26 ) ;
return - V_304 ;
}
V_19 -> V_53 = V_134 ;
V_19 -> V_305 = V_19 -> V_135 +
V_306 ;
V_19 -> V_152 = V_19 -> V_135 + V_307 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_301 ; V_20 ++ )
V_19 -> V_30 [ V_20 ] = V_19 -> V_39 +
V_308 + ( V_309 * V_20 ) ;
V_19 -> V_310 = V_19 -> V_39 + V_311 ;
V_19 -> V_312 = V_19 -> V_39 + V_313 ;
V_19 -> V_158 = V_19 -> V_301 ;
V_19 -> V_101 = V_314 ;
V_19 -> V_315 = V_316 ;
V_19 -> V_256 = ( 1 << ( V_19 -> V_301 ) ) - 1 ;
F_136 ( V_19 , V_135 , V_246 ) ;
F_136 ( V_19 , V_135 , V_136 ) ;
F_136 ( V_19 , V_39 , V_246 ) ;
F_136 ( V_19 , V_39 , V_136 ) ;
F_136 ( V_19 , V_39 , V_251 ) ;
F_136 ( V_19 , V_39 , V_40 ) ;
F_136 ( V_19 , V_39 , V_317 ) ;
F_136 ( V_19 , V_152 , V_279 ) ;
F_136 ( V_19 , V_152 , V_153 ) ;
F_136 ( V_19 , V_152 , V_137 ) ;
return 0 ;
}
static int F_155 ( struct V_18 * V_19 ,
struct V_263 * V_264 )
{
struct V_293 V_294 ;
void T_4 * V_295 ;
int V_245 ;
V_245 = F_150 ( V_264 , V_318 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_27 ,
V_264 -> V_285 , V_318 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 , L_28 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_135 = V_295 ;
V_19 -> V_53 = F_10 ( V_19 -> V_135 ) ;
return 0 ;
}
static int F_156 ( struct V_18 * V_19 ,
struct V_263 * V_264 )
{
struct V_293 V_294 ;
void T_4 * V_295 ;
int V_20 , V_245 ;
V_245 = F_150 ( V_264 , V_319 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_29 ,
V_264 -> V_285 , V_319 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 ,
L_30 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_320 = V_295 ;
V_245 = F_150 ( V_264 , V_321 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_29 ,
V_264 -> V_285 , V_321 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 ,
L_31 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_39 = V_295 ;
V_19 -> V_300 = V_19 -> V_289 ;
V_19 -> V_23 = V_322 ;
V_19 -> V_22 = F_154 ( V_322 ) ;
V_19 -> V_33 = F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( V_303 ) ,
V_284 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_148 , L_25 ) ;
return - V_304 ;
}
V_19 -> V_34 =
F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_284 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_148 ,
L_26 ) ;
return - V_304 ;
}
V_19 -> V_305 = V_19 -> V_135 + V_323 ;
V_19 -> V_152 = V_19 -> V_39 + V_324 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_289 ; V_20 ++ ) {
V_19 -> V_30 [ V_20 ] =
V_19 -> V_39 + V_325 +
( V_309 * ( V_20 & 0x1 ) ) ;
}
V_19 -> V_312 = V_19 -> V_39 + V_326 ;
V_19 -> V_310 = V_19 -> V_39 + V_327 ;
V_19 -> V_158 = V_19 -> V_301 ;
V_19 -> V_101 = V_328 ;
V_19 -> V_315 = V_329 ;
V_19 -> V_256 = V_330 ;
F_134 ( V_19 , V_135 , V_246 ) ;
F_134 ( V_19 , V_39 , V_246 ) ;
F_134 ( V_19 , V_39 , V_136 ) ;
F_134 ( V_19 , V_39 , V_126 ) ;
F_134 ( V_19 , V_39 , V_40 ) ;
F_134 ( V_19 , V_39 , V_251 ) ;
F_134 ( V_19 , V_39 , V_317 ) ;
F_134 ( V_19 , V_152 , V_279 ) ;
F_134 ( V_19 , V_152 , V_137 ) ;
return 0 ;
}
static int F_157 ( struct V_18 * V_19 ,
struct V_263 * V_264 )
{
struct V_293 V_294 ;
void T_4 * V_295 ;
int V_20 , V_245 ;
V_19 -> V_300 = V_19 -> V_301 ;
V_19 -> V_23 = V_331 ;
if ( F_67 ( V_19 ) )
V_19 -> V_22 = V_332 +
( V_19 -> V_289 * V_333 ) ;
else
V_19 -> V_22 = V_332 +
V_333 ;
V_19 -> V_33 = F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( V_303 ) ,
V_284 ) ;
if ( ! V_19 -> V_33 ) {
F_62 ( V_19 -> V_148 , L_25 ) ;
return - V_304 ;
}
V_19 -> V_34 =
F_139 ( V_19 -> V_148 ,
V_19 -> V_22 * sizeof( T_1 ) ,
V_284 ) ;
if ( ! V_19 -> V_34 ) {
F_62 ( V_19 -> V_148 ,
L_26 ) ;
return - V_304 ;
}
V_245 = F_150 ( V_264 , V_334 , & V_294 ) ;
if ( V_245 ) {
F_62 ( V_19 -> V_148 ,
L_32 ,
V_264 -> V_285 , V_334 ) ;
return V_245 ;
}
V_295 = F_151 ( V_19 -> V_148 , & V_294 ) ;
if ( F_152 ( V_295 ) ) {
F_62 ( V_19 -> V_148 ,
L_33 ) ;
return F_153 ( V_295 ) ;
}
V_19 -> V_39 = V_295 ;
V_19 -> V_305 = V_19 -> V_135 + V_335 ;
V_19 -> V_320 = V_19 -> V_305 +
( 2 * V_336 ) ;
V_19 -> V_152 = V_19 -> V_39 + V_337 ;
for ( V_20 = 0 ; V_20 < ( V_19 -> V_301 ) ; V_20 ++ )
V_19 -> V_30 [ V_20 ] = V_19 -> V_39 +
V_338 + ( V_339 * V_20 ) ;
V_19 -> V_312 = V_19 -> V_39 + V_340 ;
V_19 -> V_310 = V_19 -> V_39 + V_341 ;
V_19 -> V_158 = V_19 -> V_301 ;
V_19 -> V_101 = V_342 ;
V_19 -> V_256 = ( 1 << ( V_19 -> V_301 ) ) - 1 ;
F_135 ( V_19 , V_135 , V_246 ) ;
F_135 ( V_19 , V_39 , V_246 ) ;
F_135 ( V_19 , V_39 , V_136 ) ;
F_135 ( V_19 , V_39 , V_40 ) ;
F_135 ( V_19 , V_39 , V_251 ) ;
F_135 ( V_19 , V_152 , V_279 ) ;
F_135 ( V_19 , V_152 , V_137 ) ;
F_135 ( V_19 , V_152 , V_153 ) ;
return 0 ;
}
static int F_158 ( struct V_343 * V_343 , struct V_282 * V_148 ,
struct V_263 * V_264 , void * * V_344 )
{
struct V_263 * V_345 , * V_346 ;
struct V_263 * V_347 ;
struct V_348 V_349 ;
struct V_18 * V_19 ;
T_1 V_100 ;
int V_20 , V_245 = 0 ;
if ( ! V_264 ) {
F_62 ( V_148 , L_34 ) ;
return - V_149 ;
}
V_19 = F_139 ( V_148 , sizeof( struct V_18 ) , V_284 ) ;
if ( ! V_19 )
return - V_304 ;
if ( F_159 ( V_264 , L_35 ) ||
F_159 ( V_264 , L_36 ) ) {
V_19 -> V_289 = 4 ;
} else if ( F_159 ( V_264 , L_37 ) ) {
V_19 -> V_289 = 8 ;
} else if ( F_159 ( V_264 , L_38 ) ) {
V_19 -> V_289 = 1 ;
} else if ( F_159 ( V_264 , L_39 ) ) {
V_19 -> V_289 = 2 ;
} else {
F_62 ( V_148 , L_40 ) ;
return - V_27 ;
}
V_19 -> V_301 = V_19 -> V_289 + 1 ;
V_19 -> V_148 = V_148 ;
V_19 -> V_343 = V_343 ;
V_19 -> V_143 = V_133 ;
F_160 ( & V_19 -> V_52 ) ;
if ( F_161 ( V_264 , L_41 , NULL ) ) {
V_19 -> V_154 = true ;
F_162 ( V_148 , L_42 ) ;
} else {
V_19 -> V_154 = false ;
F_63 ( V_148 , L_43 ) ;
}
V_245 = F_131 ( V_264 , L_44 ,
& V_19 -> V_350 ) ;
if ( V_245 < 0 ) {
F_62 ( V_148 , L_45 ) ;
V_19 -> V_350 = V_351 ;
}
V_245 = F_163 ( V_264 , L_46 ,
& V_19 -> V_249 ) ;
if ( V_245 < 0 ) {
F_62 ( V_148 , L_47 ) ;
return - V_27 ;
}
if ( ! strcmp ( V_264 -> V_285 , L_48 ) ) {
V_245 = F_155 ( V_19 , V_264 ) ;
if ( V_245 )
return V_245 ;
F_63 ( V_148 , L_49 , V_19 -> V_53 ) ;
if ( V_19 -> V_53 == V_54 )
V_245 = F_156 ( V_19 , V_264 ) ;
else if ( F_48 ( V_19 ) )
V_245 = F_157 ( V_19 , V_264 ) ;
else
V_245 = - V_149 ;
} else if ( ! strcmp ( V_264 -> V_285 , L_50 ) ) {
V_245 = F_149 ( V_19 , V_264 ) ;
if ( V_245 )
return V_245 ;
V_245 = F_164 ( V_19 -> V_299 ,
V_19 -> V_135 ) ;
} else {
F_62 ( V_148 , L_51 , V_264 -> V_285 ) ;
V_245 = - V_149 ;
}
if ( V_245 )
return V_245 ;
V_345 = F_165 ( V_264 , L_52 ) ;
if ( ! V_345 )
F_62 ( V_148 , L_53 ) ;
V_245 = F_166 ( & V_19 -> V_243 , V_343 ,
V_19 -> V_249 , V_19 -> V_350 ) ;
if ( V_245 )
return V_245 ;
V_245 = F_167 ( & V_19 -> V_243 ) ;
if ( V_245 )
return V_245 ;
F_168 ( & V_19 -> V_352 ) ;
F_138 (interfaces, interface) {
V_245 = F_131 ( V_346 , L_8 , & V_100 ) ;
if ( V_245 ) {
F_62 ( V_148 , L_54 ,
V_346 -> V_285 ) ;
continue;
}
V_19 -> V_288 ++ ;
if ( V_19 -> V_288 >= V_19 -> V_289 ) {
F_142 ( V_346 ) ;
break;
}
}
F_142 ( V_345 ) ;
if ( ! V_19 -> V_288 )
F_132 ( V_148 , L_55 ) ;
V_347 = F_165 ( V_264 , L_56 ) ;
F_168 ( & V_19 -> V_287 ) ;
if ( V_347 && ( V_19 -> V_288 < V_19 -> V_289 ) )
F_137 ( V_19 , V_347 ) ;
F_142 ( V_347 ) ;
if ( ! V_19 -> V_288 ) {
F_62 ( V_148 ,
L_57 ) ;
V_245 = - V_149 ;
goto V_353;
}
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_349 . V_148 = V_19 -> V_148 ;
V_349 . V_354 = V_19 -> V_310 ;
V_349 . V_355 = V_356 ;
V_349 . V_315 = V_19 -> V_315 ;
V_349 . V_158 = V_19 -> V_158 ;
if ( F_48 ( V_19 ) ) {
V_349 . V_357 = 0x7 ;
V_349 . V_358 = true ;
}
V_19 -> V_110 = F_169 ( & V_349 ) ;
if ( ! V_19 -> V_110 ) {
F_62 ( V_19 -> V_148 , L_58 ) ;
V_245 = - V_149 ;
goto V_353;
} else {
F_63 ( V_19 -> V_148 , L_59 ) ;
}
V_19 -> V_78 = F_170 ( V_19 -> V_148 , V_19 -> V_312 , V_264 ) ;
if ( F_171 ( V_359 ) && F_152 ( V_19 -> V_78 ) ) {
V_245 = F_153 ( V_19 -> V_78 ) ;
goto V_353;
}
F_66 ( V_19 ) ;
F_19 ( & V_19 -> V_52 ) ;
for ( V_20 = 0 ; V_20 < V_19 -> V_300 ; V_20 ++ ) {
if ( V_19 -> V_53 == V_54 )
F_16 ( V_19 , V_20 ) ;
else
F_9 ( V_19 , V_20 ) ;
}
F_20 ( & V_19 -> V_52 ) ;
F_172 ( & V_19 -> V_238 ) ;
V_19 -> V_238 . V_17 = ( unsigned long ) V_19 ;
V_19 -> V_238 . V_360 = F_111 ;
V_19 -> V_238 . V_239 = V_240 + V_241 ;
F_115 ( & V_19 -> V_238 ) ;
* V_344 = V_19 ;
return 0 ;
V_353:
F_144 ( V_19 ) ;
return V_245 ;
}
static int F_173 ( void * V_344 , struct V_1 * V_2 ,
struct V_263 * V_264 , void * * V_165 )
{
struct V_18 * V_19 = V_344 ;
struct V_13 * V_13 ;
int V_245 ;
if ( ! V_264 ) {
F_62 ( V_19 -> V_148 , L_60 ) ;
return - V_149 ;
}
V_13 = F_139 ( V_19 -> V_148 , sizeof( * V_13 ) , V_284 ) ;
if ( ! V_13 )
return - V_304 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_148 = V_19 -> V_148 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_60 = F_139 ( V_19 -> V_148 ,
sizeof( * V_13 -> V_60 ) ,
V_284 ) ;
if ( ! V_13 -> V_60 ) {
V_245 = - V_304 ;
goto V_257;
}
if ( F_130 ( V_19 , V_13 -> V_60 , V_264 ) ) {
V_245 = - V_149 ;
goto V_257;
}
V_13 -> V_243 = V_19 -> V_243 ;
V_2 -> V_361 = & V_362 ;
F_141 ( & V_13 -> V_363 , & V_19 -> V_352 ) ;
* V_165 = V_13 ;
return 0 ;
V_257:
if ( V_13 -> V_60 )
F_140 ( V_19 -> V_148 , V_13 -> V_60 ) ;
if ( V_13 )
F_140 ( V_19 -> V_148 , V_13 ) ;
return V_245 ;
}
static int F_174 ( void * V_165 )
{
struct V_13 * V_13 = V_165 ;
V_13 -> V_2 -> V_361 = NULL ;
F_147 ( & V_13 -> V_363 ) ;
F_140 ( V_13 -> V_148 , V_13 -> V_60 ) ;
F_140 ( V_13 -> V_148 , V_13 ) ;
return 0 ;
}
static int F_175 ( struct V_343 * V_343 , void * V_344 )
{
struct V_18 * V_19 = V_344 ;
F_176 ( & V_19 -> V_238 ) ;
F_177 ( V_19 -> V_78 ) ;
F_178 ( V_19 -> V_110 ) ;
F_179 ( V_19 -> V_110 ) ;
F_180 ( & V_19 -> V_243 ) ;
F_144 ( V_19 ) ;
if ( ! F_145 ( & V_19 -> V_352 ) )
F_181 ( V_19 -> V_148 ,
L_61 ) ;
return 0 ;
}
static int T_9 F_182 ( void )
{
int V_245 ;
V_245 = F_183 ( & V_14 ) ;
if ( V_245 )
return V_245 ;
V_245 = F_183 ( & V_15 ) ;
if ( V_245 )
return V_245 ;
return 0 ;
}
static void T_10 F_184 ( void )
{
F_185 ( & V_14 ) ;
F_185 ( & V_15 ) ;
}
