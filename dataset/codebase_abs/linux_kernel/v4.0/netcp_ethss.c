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
static void F_5 ( struct V_1 * V_2 ,
T_2 V_13 , T_3 * V_14 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_15 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return;
V_17 = V_15 -> V_17 ;
switch ( V_13 ) {
case V_20 :
for ( V_18 = 0 ; V_18 < V_17 -> V_21 ; V_18 ++ ) {
memcpy ( V_14 , V_17 -> V_22 [ V_18 ] . V_23 ,
V_24 ) ;
V_14 += V_24 ;
}
break;
case V_25 :
break;
}
}
static int F_7 ( struct V_1 * V_2 , int V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_15 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return - V_26 ;
V_17 = V_15 -> V_17 ;
switch ( V_13 ) {
case V_25 :
return 0 ;
case V_20 :
return V_17 -> V_21 ;
default:
return - V_26 ;
}
}
static void F_8 ( struct V_16 * V_17 , T_4 * V_14 )
{
void T_5 * V_27 = NULL ;
T_1 T_5 * V_28 ;
T_1 V_29 = 0 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_21 ; V_18 ++ ) {
V_27 = V_17 -> V_30 [ V_17 -> V_22 [ V_18 ] . type ] ;
V_28 = V_27 + V_17 -> V_22 [ V_18 ] . V_31 ;
V_29 = F_9 ( V_28 ) ;
V_17 -> V_32 [ V_18 ] = V_17 -> V_32 [ V_18 ] + V_29 ;
if ( V_14 )
V_14 [ V_18 ] = V_17 -> V_32 [ V_18 ] ;
F_10 ( V_29 , V_28 ) ;
}
}
static void F_11 ( struct V_16 * V_17 , T_4 * V_14 )
{
void T_5 * V_33 = V_17 -> V_30 [ 0 ] ;
void T_5 * V_34 = V_17 -> V_30 [ 1 ] ;
T_6 * V_32 = & V_17 -> V_32 [ 0 ] ;
void T_5 * V_27 = NULL ;
T_1 T_5 * V_28 ;
T_1 V_29 = 0 , V_35 , V_36 = ( V_17 -> V_21 / 2 ) ;
int V_18 , V_37 , V_38 ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
V_35 = F_9 ( F_12 ( V_17 , V_39 , V_40 ) ) ;
if ( V_38 == 0 )
V_35 &= ~ V_41 ;
else
V_35 |= V_41 ;
F_10 ( V_35 , F_12 ( V_17 , V_39 , V_40 ) ) ;
for ( V_18 = 0 ; V_18 < V_36 ; V_18 ++ ) {
V_37 = V_38 * V_36 + V_18 ;
switch ( V_17 -> V_22 [ V_37 ] . type ) {
case V_42 :
case V_43 :
V_27 = V_33 ;
break;
case V_44 :
case V_45 :
V_27 = V_34 ;
break;
}
V_28 = V_27 + V_17 -> V_22 [ V_37 ] . V_31 ;
V_29 = F_9 ( V_28 ) ;
V_32 [ V_37 ] += V_29 ;
if ( V_14 )
V_14 [ V_37 ] = V_32 [ V_37 ] ;
F_10 ( V_29 , V_28 ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_4 * V_14 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_15 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return;
V_17 = V_15 -> V_17 ;
F_14 ( & V_17 -> V_48 ) ;
if ( V_17 -> V_49 == V_50 )
F_11 ( V_17 , V_14 ) ;
else
F_8 ( V_17 , V_14 ) ;
F_15 ( & V_17 -> V_48 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_53 * V_54 = V_2 -> V_55 ;
struct V_15 * V_15 ;
int V_56 ;
if ( ! V_54 )
return - V_26 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return - V_26 ;
if ( ! V_15 -> V_57 )
return - V_26 ;
V_56 = F_17 ( V_54 , V_52 ) ;
if ( ! V_56 )
V_52 -> V_58 = V_15 -> V_57 -> V_59 ;
return V_56 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_53 * V_54 = V_2 -> V_55 ;
struct V_15 * V_15 ;
T_1 V_60 = V_52 -> V_61 & V_52 -> V_62 ;
if ( ! V_54 )
return - V_26 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return - V_26 ;
if ( ! V_15 -> V_57 )
return - V_26 ;
if ( V_52 -> V_58 != V_15 -> V_57 -> V_59 ) {
if ( ( V_52 -> V_58 == V_63 ) && ! ( V_60 & V_64 ) )
return - V_26 ;
if ( ( V_52 -> V_58 == V_65 ) && ! ( V_60 & V_66 ) )
return - V_26 ;
if ( ( V_52 -> V_58 == V_67 ) && ! ( V_60 & V_68 ) )
return - V_26 ;
if ( ( V_52 -> V_58 == V_69 ) && ! ( V_60 & V_70 ) )
return - V_26 ;
if ( ( V_52 -> V_58 == V_71 ) && ! ( V_60 & V_72 ) )
return - V_26 ;
}
V_15 -> V_57 -> V_59 = V_52 -> V_58 ;
return F_19 ( V_54 , V_52 ) ;
}
static void F_20 ( struct V_73 * V_57 ,
struct V_15 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_10 ( F_21 ( V_2 -> V_74 ) , F_12 ( V_57 , V_75 , V_76 ) ) ;
F_10 ( F_22 ( V_2 -> V_74 ) , F_12 ( V_57 , V_75 , V_77 ) ) ;
}
static int F_23 ( struct V_16 * V_78 , T_1 V_79 )
{
if ( V_78 -> V_80 == 0 )
return V_79 + 1 ;
return V_79 ;
}
static void F_24 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_73 * V_57 ,
int V_81 )
{
struct V_53 * V_54 = V_57 -> V_54 ;
T_1 V_82 = 0 ;
if ( V_81 ) {
V_82 = V_57 -> V_82 ;
if ( V_54 && ( V_54 -> V_83 == V_84 ) ) {
V_82 |= V_85 ;
V_82 &= ~ V_86 ;
} else if ( V_54 && ( V_54 -> V_83 == V_87 ) ) {
V_82 |= V_86 ;
V_82 &= ~ V_85 ;
}
F_10 ( V_82 , F_12 ( V_57 , V_88 ,
V_82 ) ) ;
F_25 ( V_17 -> V_89 , V_57 -> V_90 ,
V_91 ,
V_92 ) ;
if ( V_2 && V_57 -> V_93 )
F_26 ( V_2 ) ;
} else {
F_10 ( V_82 , F_12 ( V_57 , V_88 ,
V_82 ) ) ;
F_25 ( V_17 -> V_89 , V_57 -> V_90 ,
V_91 ,
V_94 ) ;
if ( V_2 )
F_27 ( V_2 ) ;
}
if ( V_54 )
F_28 ( V_54 ) ;
}
static bool F_29 ( struct V_73 * V_57 )
{
return ! V_57 -> V_54 || V_57 -> V_54 -> V_95 ;
}
static void F_30 ( struct V_16 * V_17 ,
struct V_73 * V_57 ,
struct V_1 * V_2 )
{
int V_96 = V_57 -> V_79 ;
int V_97 , V_98 = 1 , V_99 ;
if ( ! V_57 -> V_93 )
return;
if ( ! F_31 ( V_57 ) )
V_98 = F_32 ( F_33 ( V_96 ) ,
V_96 ) ;
V_97 = F_29 ( V_57 ) ;
V_99 = V_97 & V_98 ;
if ( F_34 ( & V_57 -> V_99 , V_99 ) != V_99 )
F_24 ( V_17 , V_2 , V_57 ,
V_99 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_15 * V_15 ;
V_15 = F_6 ( & V_100 , V_10 ) ;
if ( ! V_15 )
return;
F_30 ( V_15 -> V_17 , V_15 -> V_57 ,
V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_15 * V_15 ;
V_15 = F_6 ( & V_19 , V_10 ) ;
if ( ! V_15 )
return;
F_30 ( V_15 -> V_17 , V_15 -> V_57 ,
V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_3 ( V_2 ) ;
struct V_73 * V_57 ;
F_38 (slave, gbe_dev)
F_30 ( V_17 , V_57 , NULL ) ;
}
static int F_39 ( struct V_73 * V_57 )
{
T_1 V_18 , V_101 ;
F_10 ( V_102 , F_12 ( V_57 , V_88 , V_103 ) ) ;
for ( V_18 = 0 ; V_18 < V_104 ; V_18 ++ ) {
V_101 = F_9 ( F_12 ( V_57 , V_88 , V_103 ) ) ;
if ( ( V_101 & V_105 ) != V_102 )
return 0 ;
}
return V_106 ;
}
static void F_40 ( struct V_16 * V_17 , struct V_73 * V_57 ,
int V_107 )
{
T_1 V_108 ;
if ( V_107 > V_109 )
V_107 = V_109 ;
if ( ( V_17 -> V_49 == V_110 ) &&
( V_57 -> V_111 >= V_112 ) ) {
V_108 = F_9 ( F_12 ( V_17 , V_113 , V_114 ) ) ;
V_108 |= ( 1 << V_57 -> V_79 ) ;
F_10 ( V_108 , F_12 ( V_17 , V_113 , V_114 ) ) ;
}
F_10 ( V_107 , F_12 ( V_57 , V_88 , V_115 ) ) ;
F_10 ( V_57 -> V_82 , F_12 ( V_57 , V_88 , V_82 ) ) ;
}
static void F_41 ( struct V_15 * V_116 )
{
struct V_16 * V_17 = V_116 -> V_17 ;
struct V_73 * V_57 = V_116 -> V_57 ;
F_39 ( V_57 ) ;
F_25 ( V_17 -> V_89 , V_57 -> V_90 ,
V_91 , V_94 ) ;
F_42 ( V_17 -> V_89 , V_116 -> V_2 -> V_117 ,
1 << V_57 -> V_90 , 0 , 0 ) ;
if ( ! V_57 -> V_54 )
return;
F_43 ( V_57 -> V_54 ) ;
F_44 ( V_57 -> V_54 ) ;
V_57 -> V_54 = NULL ;
}
static void F_45 ( struct V_16 * V_78 , struct V_73 * V_57 )
{
void T_5 * V_118 ;
V_118 = V_78 -> V_118 ;
if ( ( V_78 -> V_49 == V_50 ) && ( V_57 -> V_79 >= 2 ) )
V_118 = V_78 -> V_119 ;
if ( ! F_31 ( V_57 ) ) {
F_46 ( V_118 , V_57 -> V_79 ) ;
F_47 ( V_118 , V_57 -> V_79 ,
V_57 -> V_111 ) ;
}
}
static int F_48 ( struct V_15 * V_15 )
{
struct V_16 * V_78 = V_15 -> V_17 ;
struct V_73 * V_57 = V_15 -> V_57 ;
T_7 V_120 ;
bool V_121 = false ;
void (* F_49)( struct V_1 * ) = F_36 ;
F_45 ( V_78 , V_57 ) ;
F_39 ( V_57 ) ;
F_40 ( V_78 , V_57 , V_78 -> V_122 ) ;
F_20 ( V_57 , V_15 ) ;
F_25 ( V_78 -> V_89 , V_57 -> V_90 ,
V_91 , V_92 ) ;
F_50 ( V_78 -> V_89 , V_15 -> V_2 -> V_117 ,
1 << V_57 -> V_90 , 0 , 0 , V_123 ) ;
if ( V_57 -> V_111 == V_124 ) {
V_121 = true ;
V_120 = V_125 ;
V_57 -> V_59 = V_69 ;
} else if ( V_57 -> V_111 == V_112 ) {
V_121 = true ;
V_120 = V_126 ;
V_57 -> V_59 = V_71 ;
}
if ( V_121 ) {
if ( V_78 -> V_49 == V_110 )
F_49 = F_35 ;
V_57 -> V_54 = F_51 ( V_15 -> V_2 ,
V_57 -> V_127 ,
F_49 , 0 ,
V_120 ) ;
if ( ! V_57 -> V_54 ) {
F_52 ( V_78 -> V_128 , L_1 ,
V_57 -> V_79 ) ;
return - V_129 ;
}
F_53 ( V_78 -> V_128 , L_2 ,
F_54 ( & V_57 -> V_54 -> V_128 ) ) ;
F_55 ( V_57 -> V_54 ) ;
F_56 ( V_57 -> V_54 ) ;
}
return 0 ;
}
static void F_57 ( struct V_16 * V_78 )
{
int V_130 = 1 ;
F_10 ( V_109 , F_12 ( V_78 , V_131 ,
V_115 ) ) ;
F_58 ( V_78 -> V_89 ) ;
if ( V_78 -> V_132 )
V_130 = 0 ;
F_25 ( V_78 -> V_89 , 0 , V_133 , V_130 ) ;
F_25 ( V_78 -> V_89 , 0 , V_134 , 1 ) ;
F_25 ( V_78 -> V_89 , V_78 -> V_80 ,
V_91 , V_92 ) ;
F_25 ( V_78 -> V_89 , 0 ,
V_135 ,
F_59 ( V_78 -> V_136 ) ) ;
F_25 ( V_78 -> V_89 , 0 ,
V_137 ,
F_59 ( V_78 -> V_136 - 1 ) ) ;
F_25 ( V_78 -> V_89 , 0 ,
V_138 ,
F_59 ( V_78 -> V_136 ) ) ;
F_25 ( V_78 -> V_89 , 0 ,
V_139 ,
F_59 ( V_78 -> V_136 ) ) ;
}
static void F_60 ( struct V_15 * V_15 , T_8 * V_140 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
T_9 V_141 ;
F_50 ( V_17 -> V_89 , V_140 ,
F_59 ( V_17 -> V_136 ) , 0 , 0 ,
V_123 ) ;
F_61 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_50 ( V_17 -> V_89 , V_140 ,
F_59 ( V_17 -> V_136 ) ,
V_142 , V_141 , V_123 ) ;
}
}
static void F_62 ( struct V_15 * V_15 , T_8 * V_140 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
T_9 V_141 ;
F_63 ( V_17 -> V_89 , V_140 , V_17 -> V_80 , 0 , 0 ) ;
F_61 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID)
F_63 ( V_17 -> V_89 , V_140 , V_17 -> V_80 ,
V_142 , V_141 ) ;
}
static void F_64 ( struct V_15 * V_15 , T_8 * V_140 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
T_9 V_141 ;
F_42 ( V_17 -> V_89 , V_140 , 0 , 0 , 0 ) ;
F_61 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_42 ( V_17 -> V_89 , V_140 , 0 , V_142 , V_141 ) ;
}
}
static void F_65 ( struct V_15 * V_15 , T_8 * V_140 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
T_9 V_141 ;
F_66 ( V_17 -> V_89 , V_140 , V_17 -> V_80 , 0 , 0 ) ;
F_61 (vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
F_66 ( V_17 -> V_89 , V_140 , V_17 -> V_80 ,
V_142 , V_141 ) ;
}
}
static int F_67 ( void * V_143 , struct V_144 * V_145 )
{
struct V_15 * V_15 = V_143 ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_53 ( V_17 -> V_128 , L_3 ,
V_145 -> V_140 , V_145 -> type ) ;
switch ( V_145 -> type ) {
case V_146 :
case V_147 :
F_60 ( V_15 , V_145 -> V_140 ) ;
break;
case V_148 :
case V_149 :
F_62 ( V_15 , V_145 -> V_140 ) ;
break;
case V_150 :
default:
break;
}
return 0 ;
}
static int F_68 ( void * V_143 , struct V_144 * V_145 )
{
struct V_15 * V_15 = V_143 ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_53 ( V_17 -> V_128 , L_4 ,
V_145 -> V_140 , V_145 -> type ) ;
switch ( V_145 -> type ) {
case V_146 :
case V_147 :
F_64 ( V_15 , V_145 -> V_140 ) ;
break;
case V_148 :
case V_149 :
F_65 ( V_15 , V_145 -> V_140 ) ;
break;
case V_150 :
default:
break;
}
return 0 ;
}
static int F_69 ( void * V_143 , int V_151 )
{
struct V_15 * V_15 = V_143 ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_70 ( V_151 , V_15 -> V_152 ) ;
F_71 ( V_17 -> V_89 , V_151 ,
F_59 ( V_17 -> V_136 ) ,
V_153 ,
F_59 ( V_17 -> V_136 ) ,
F_59 ( V_17 -> V_136 - 1 ) ) ;
return 0 ;
}
static int F_72 ( void * V_143 , int V_151 )
{
struct V_15 * V_15 = V_143 ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_73 ( V_17 -> V_89 , V_151 , 0 ) ;
F_74 ( V_151 , V_15 -> V_152 ) ;
return 0 ;
}
static int F_75 ( void * V_143 , struct V_154 * V_155 , int V_52 )
{
struct V_15 * V_15 = V_143 ;
struct V_53 * V_54 = V_15 -> V_57 -> V_54 ;
int V_56 = - V_156 ;
if ( V_54 )
V_56 = F_76 ( V_54 , V_155 , V_52 ) ;
return V_56 ;
}
static void F_77 ( unsigned long V_157 )
{
struct V_16 * V_17 = (struct V_16 * ) V_157 ;
struct V_15 * V_15 ;
struct V_73 * V_57 ;
F_78 (gbe_intf, gbe_dev) {
if ( ! V_15 -> V_57 -> V_93 )
continue;
F_30 ( V_17 , V_15 -> V_57 ,
V_15 -> V_2 ) ;
}
F_38 (slave, gbe_dev) {
F_30 ( V_17 , V_57 , NULL ) ;
}
F_14 ( & V_17 -> V_48 ) ;
if ( V_17 -> V_49 == V_50 )
F_11 ( V_17 , NULL ) ;
else
F_8 ( V_17 , NULL ) ;
F_15 ( & V_17 -> V_48 ) ;
V_17 -> V_158 . V_159 = V_160 + V_161 ;
F_79 ( & V_17 -> V_158 ) ;
}
static int F_80 ( int V_162 , void * V_14 , struct V_163 * V_164 )
{
struct V_15 * V_15 = V_14 ;
V_164 -> V_165 = & V_15 -> V_165 ;
return 0 ;
}
static int F_81 ( void * V_143 , struct V_1 * V_2 )
{
struct V_15 * V_15 = V_143 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_73 * V_57 = V_15 -> V_57 ;
int V_90 = V_57 -> V_90 ;
T_1 V_166 ;
int V_56 ;
V_166 = F_9 ( F_12 ( V_17 , V_39 , V_167 ) ) ;
F_53 ( V_17 -> V_128 , L_5 ,
F_82 ( V_166 ) , F_83 ( V_166 ) ,
F_84 ( V_166 ) , F_85 ( V_166 ) ) ;
if ( V_17 -> V_132 )
V_15 -> V_165 . V_168 = 0 ;
else
V_15 -> V_165 . V_168 = V_90 ;
F_53 ( V_17 -> V_128 , L_6 ,
V_15 -> V_165 . V_169 ,
V_15 -> V_165 . V_170 ,
V_15 -> V_165 . V_168 ) ;
F_41 ( V_15 ) ;
F_10 ( 0 , F_12 ( V_17 , V_39 , V_171 ) ) ;
F_10 ( V_172 , F_12 ( V_17 , V_39 , V_114 ) ) ;
F_10 ( V_173 , F_12 ( V_17 , V_39 ,
V_40 ) ) ;
V_56 = F_48 ( V_15 ) ;
if ( V_56 )
goto V_174;
F_86 ( V_10 , V_175 , F_80 ,
V_15 ) ;
V_57 -> V_93 = true ;
F_30 ( V_17 , V_57 , V_2 ) ;
return 0 ;
V_174:
F_41 ( V_15 ) ;
return V_56 ;
}
static int F_87 ( void * V_143 , struct V_1 * V_2 )
{
struct V_15 * V_15 = V_143 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
F_41 ( V_15 ) ;
F_88 ( V_10 , V_175 , F_80 ,
V_15 ) ;
V_15 -> V_57 -> V_93 = false ;
F_89 ( & V_15 -> V_57 -> V_99 , V_176 ) ;
return 0 ;
}
static int F_90 ( struct V_16 * V_17 , struct V_73 * V_57 ,
struct V_177 * V_178 )
{
int V_179 ;
T_1 V_180 , V_181 ;
if ( F_91 ( V_178 , L_7 , & V_57 -> V_79 ) ) {
F_52 ( V_17 -> V_128 , L_8 ) ;
return - V_26 ;
}
if ( F_91 ( V_178 , L_9 ,
& V_57 -> V_111 ) ) {
F_92 ( V_17 -> V_128 ,
L_10 ) ;
V_57 -> V_111 = V_124 ;
}
V_57 -> V_93 = false ;
V_57 -> V_127 = F_93 ( V_178 , L_11 , 0 ) ;
V_57 -> V_90 = F_23 ( V_17 , V_57 -> V_79 ) ;
if ( V_57 -> V_111 >= V_112 )
V_57 -> V_82 = V_182 ;
else
V_57 -> V_82 = V_183 ;
V_179 = V_57 -> V_79 ;
if ( V_17 -> V_49 == V_50 ) {
if ( V_57 -> V_79 > 1 ) {
V_180 = V_184 ;
V_179 -= 2 ;
} else {
V_180 = V_185 ;
}
} else if ( V_17 -> V_49 == V_110 ) {
V_180 = V_186 ;
} else {
F_52 ( V_17 -> V_128 , L_12 ,
V_17 -> V_49 ) ;
return - V_26 ;
}
if ( V_17 -> V_49 == V_50 )
V_181 = V_187 ;
else if ( V_17 -> V_49 == V_110 )
V_181 = V_188 ;
V_57 -> V_75 = V_17 -> V_113 + V_180 +
( 0x30 * V_179 ) ;
V_57 -> V_88 = V_17 -> V_113 + V_181 +
( 0x40 * V_57 -> V_79 ) ;
if ( V_17 -> V_49 == V_50 ) {
F_94 ( V_57 , V_75 , V_189 ) ;
F_94 ( V_57 , V_75 , V_190 ) ;
F_94 ( V_57 , V_75 , V_77 ) ;
F_94 ( V_57 , V_75 , V_76 ) ;
F_94 ( V_57 , V_75 , V_191 ) ;
F_94 ( V_57 , V_75 , V_192 ) ;
F_94 ( V_57 , V_75 , V_193 ) ;
F_94 ( V_57 , V_75 , V_194 ) ;
F_94 ( V_57 , V_75 , V_195 ) ;
F_94 ( V_57 , V_88 , V_82 ) ;
F_94 ( V_57 , V_88 , V_103 ) ;
F_94 ( V_57 , V_88 , V_115 ) ;
} else if ( V_17 -> V_49 == V_110 ) {
F_95 ( V_57 , V_75 , V_189 ) ;
F_95 ( V_57 , V_75 , V_190 ) ;
F_95 ( V_57 , V_75 , V_77 ) ;
F_95 ( V_57 , V_75 , V_76 ) ;
F_95 ( V_57 , V_75 , V_191 ) ;
F_95 ( V_57 , V_75 , V_192 ) ;
F_95 ( V_57 , V_75 , V_193 ) ;
F_95 ( V_57 , V_75 , V_194 ) ;
F_95 ( V_57 , V_75 , V_195 ) ;
F_95 ( V_57 , V_88 , V_82 ) ;
F_95 ( V_57 , V_88 , V_103 ) ;
F_95 ( V_57 , V_88 , V_115 ) ;
}
F_89 ( & V_57 -> V_99 , V_176 ) ;
return 0 ;
}
static void F_96 ( struct V_16 * V_17 ,
struct V_177 * V_178 )
{
struct V_196 * V_128 = V_17 -> V_128 ;
T_7 V_120 ;
struct V_16 * * V_78 ;
struct V_177 * V_58 ;
struct V_73 * V_57 ;
bool V_197 = false ;
F_97 (node, port) {
V_57 = F_98 ( V_128 , sizeof( * V_57 ) , V_198 ) ;
if ( ! V_57 ) {
F_52 ( V_128 ,
L_13 ,
V_58 -> V_199 ) ;
continue;
}
if ( F_90 ( V_17 , V_57 , V_58 ) ) {
F_52 ( V_128 ,
L_14 ,
V_58 -> V_199 ) ;
F_99 ( V_128 , V_57 ) ;
continue;
}
F_45 ( V_17 , V_57 ) ;
F_39 ( V_57 ) ;
F_40 ( V_17 , V_57 , V_17 -> V_122 ) ;
F_100 ( & V_57 -> V_200 , & V_17 -> V_201 ) ;
V_17 -> V_202 ++ ;
if ( ( V_57 -> V_111 == V_124 ) ||
( V_57 -> V_111 == V_112 ) )
V_197 = true ;
V_57 -> V_93 = true ;
}
if ( ! V_197 )
return;
V_17 -> V_203 = F_101 ( sizeof( V_17 ) , L_15 ,
V_204 , V_205 ) ;
if ( ! V_17 -> V_203 ) {
F_52 ( V_128 ,
L_16 ) ;
return;
}
V_78 = F_3 ( V_17 -> V_203 ) ;
* V_78 = V_17 ;
if ( V_57 -> V_111 == V_124 ) {
V_120 = V_125 ;
V_57 -> V_59 = V_69 ;
} else {
V_120 = V_126 ;
V_57 -> V_59 = V_71 ;
}
F_38 (slave, gbe_dev) {
if ( ( V_57 -> V_111 != V_124 ) &&
( V_57 -> V_111 != V_112 ) )
continue;
V_57 -> V_54 =
F_51 ( V_17 -> V_203 ,
V_57 -> V_127 ,
F_37 ,
0 , V_120 ) ;
if ( ! V_57 -> V_54 ) {
F_52 ( V_128 , L_17 ,
V_57 -> V_79 ) ;
V_57 -> V_54 = NULL ;
} else {
F_53 ( V_128 , L_2 ,
F_54 ( & V_57 -> V_54 -> V_128 ) ) ;
F_55 ( V_57 -> V_54 ) ;
F_56 ( V_57 -> V_54 ) ;
}
}
}
static void F_102 ( struct V_16 * V_17 )
{
struct V_73 * V_57 ;
for (; ; ) {
V_57 = F_103 ( V_17 ) ;
if ( ! V_57 )
break;
if ( V_57 -> V_54 )
F_44 ( V_57 -> V_54 ) ;
F_104 ( & V_57 -> V_200 ) ;
}
if ( V_17 -> V_203 )
F_105 ( V_17 -> V_203 ) ;
}
static int F_106 ( struct V_16 * V_17 ,
struct V_177 * V_178 )
{
struct V_206 V_207 ;
void T_5 * V_208 ;
int V_56 , V_18 ;
V_56 = F_107 ( V_178 , 0 , & V_207 ) ;
if ( V_56 ) {
F_52 ( V_17 -> V_128 , L_18 ,
V_178 -> V_199 ) ;
return V_56 ;
}
V_208 = F_108 ( V_17 -> V_128 , & V_207 ) ;
if ( F_109 ( V_208 ) ) {
F_52 ( V_17 -> V_128 , L_19 ) ;
return F_110 ( V_208 ) ;
}
V_17 -> V_113 = V_208 ;
V_56 = F_107 ( V_178 , V_209 , & V_207 ) ;
if ( V_56 ) {
F_52 ( V_17 -> V_128 , L_20 ,
V_178 -> V_199 ) ;
return V_56 ;
}
V_208 = F_108 ( V_17 -> V_128 , & V_207 ) ;
if ( F_109 ( V_208 ) ) {
F_52 ( V_17 -> V_128 , L_21 ) ;
return F_110 ( V_208 ) ;
}
V_17 -> V_210 = V_208 ;
V_17 -> V_32 = F_98 ( V_17 -> V_128 ,
V_211 *
( V_212 + 1 ) * sizeof( T_6 ) ,
V_198 ) ;
if ( ! V_17 -> V_32 ) {
F_52 ( V_17 -> V_128 , L_22 ) ;
return - V_213 ;
}
V_17 -> V_49 = V_110 ;
V_17 -> V_118 = V_17 -> V_113 +
V_214 ;
V_17 -> V_39 = V_17 -> V_113 + V_215 ;
V_17 -> V_131 = V_17 -> V_113 + V_216 ;
for ( V_18 = 0 ; V_18 < V_217 ; V_18 ++ )
V_17 -> V_30 [ V_18 ] = V_17 -> V_113 +
V_218 + ( V_219 * V_18 ) ;
V_17 -> V_220 = V_17 -> V_113 + V_221 ;
V_17 -> V_136 = V_222 ;
V_17 -> V_80 = V_223 ;
V_17 -> V_224 = V_225 ;
V_17 -> V_22 = V_226 ;
V_17 -> V_21 = F_111 ( V_226 ) ;
F_95 ( V_17 , V_113 , V_167 ) ;
F_95 ( V_17 , V_113 , V_114 ) ;
F_95 ( V_17 , V_39 , V_167 ) ;
F_95 ( V_17 , V_39 , V_114 ) ;
F_95 ( V_17 , V_39 , V_171 ) ;
F_95 ( V_17 , V_39 , V_40 ) ;
F_95 ( V_17 , V_39 , V_227 ) ;
F_95 ( V_17 , V_131 , V_189 ) ;
F_95 ( V_17 , V_131 , V_190 ) ;
F_95 ( V_17 , V_131 , V_115 ) ;
return 0 ;
}
static int F_112 ( struct V_16 * V_17 ,
struct V_177 * V_178 )
{
struct V_206 V_207 ;
void T_5 * V_208 ;
int V_56 ;
V_56 = F_107 ( V_178 , 0 , & V_207 ) ;
if ( V_56 ) {
F_52 ( V_17 -> V_128 , L_23 ,
V_178 -> V_199 ) ;
return V_56 ;
}
V_208 = F_108 ( V_17 -> V_128 , & V_207 ) ;
if ( F_109 ( V_208 ) ) {
F_52 ( V_17 -> V_128 , L_24 ) ;
return F_110 ( V_208 ) ;
}
V_17 -> V_113 = V_208 ;
V_17 -> V_49 = F_9 ( V_17 -> V_113 ) ;
return 0 ;
}
static int F_113 ( struct V_16 * V_17 ,
struct V_177 * V_178 )
{
void T_5 * V_208 ;
int V_18 ;
V_17 -> V_32 = F_98 ( V_17 -> V_128 ,
V_228 *
V_229 * sizeof( T_6 ) ,
V_198 ) ;
if ( ! V_17 -> V_32 ) {
F_52 ( V_17 -> V_128 , L_22 ) ;
return - V_213 ;
}
V_208 = V_17 -> V_113 ;
V_17 -> V_118 = V_208 + V_230 ;
V_17 -> V_119 = V_208 + V_231 ;
V_17 -> V_39 = V_208 + V_232 ;
V_17 -> V_131 = V_208 + V_233 ;
for ( V_18 = 0 ; V_18 < V_234 ; V_18 ++ )
V_17 -> V_30 [ V_18 ] = V_208 + V_235 +
( V_219 * V_18 ) ;
V_17 -> V_220 = V_208 + V_236 ;
V_17 -> V_136 = V_237 ;
V_17 -> V_80 = V_238 ;
V_17 -> V_224 = V_239 ;
V_17 -> V_22 = V_240 ;
V_17 -> V_21 = F_111 ( V_240 ) ;
F_94 ( V_17 , V_113 , V_167 ) ;
F_94 ( V_17 , V_39 , V_167 ) ;
F_94 ( V_17 , V_39 , V_114 ) ;
F_94 ( V_17 , V_39 , V_103 ) ;
F_94 ( V_17 , V_39 , V_40 ) ;
F_94 ( V_17 , V_39 , V_171 ) ;
F_94 ( V_17 , V_39 , V_227 ) ;
F_94 ( V_17 , V_131 , V_189 ) ;
F_94 ( V_17 , V_131 , V_115 ) ;
return 0 ;
}
static int F_114 ( struct V_241 * V_241 , struct V_196 * V_128 ,
struct V_177 * V_178 , void * * V_242 )
{
struct V_177 * V_243 , * V_244 ;
struct V_177 * V_245 ;
struct V_246 V_247 ;
struct V_16 * V_17 ;
T_1 V_79 ;
int V_56 = 0 ;
if ( ! V_178 ) {
F_52 ( V_128 , L_25 ) ;
return - V_129 ;
}
V_17 = F_98 ( V_128 , sizeof( struct V_16 ) , V_198 ) ;
if ( ! V_17 )
return - V_213 ;
V_17 -> V_128 = V_128 ;
V_17 -> V_241 = V_241 ;
V_17 -> V_122 = V_109 ;
F_115 ( & V_17 -> V_48 ) ;
if ( F_116 ( V_178 , L_26 , NULL ) ) {
V_17 -> V_132 = true ;
F_117 ( V_128 , L_27 ) ;
} else {
V_17 -> V_132 = false ;
F_53 ( V_128 , L_28 ) ;
}
V_56 = F_91 ( V_178 , L_29 ,
& V_17 -> V_248 ) ;
if ( V_56 < 0 ) {
F_52 ( V_128 , L_30 ) ;
V_17 -> V_248 = V_249 ;
}
V_56 = F_118 ( V_178 , L_31 ,
& V_17 -> V_169 ) ;
if ( V_56 < 0 ) {
F_52 ( V_128 , L_32 ) ;
V_56 = - V_129 ;
goto V_250;
}
if ( ! strcmp ( V_178 -> V_199 , L_33 ) ) {
V_56 = F_112 ( V_17 , V_178 ) ;
if ( V_56 )
goto V_250;
V_56 = F_113 ( V_17 , V_178 ) ;
if ( V_56 )
goto V_250;
} else if ( ! strcmp ( V_178 -> V_199 , L_34 ) ) {
V_56 = F_106 ( V_17 , V_178 ) ;
if ( V_56 )
goto V_250;
V_56 = F_119 ( V_17 -> V_210 ,
V_17 -> V_113 ) ;
if ( V_56 )
goto V_250;
} else {
F_52 ( V_128 , L_35 , V_178 -> V_199 ) ;
V_56 = - V_129 ;
goto V_250;
}
V_243 = F_120 ( V_178 , L_36 ) ;
if ( ! V_243 )
F_52 ( V_128 , L_37 ) ;
V_56 = F_121 ( & V_17 -> V_165 , V_241 ,
V_17 -> V_169 , V_17 -> V_248 ) ;
if ( V_56 )
goto V_250;
V_56 = F_122 ( & V_17 -> V_165 ) ;
if ( V_56 )
goto V_250;
F_123 ( & V_17 -> V_251 ) ;
F_97 (interfaces, interface) {
V_56 = F_91 ( V_244 , L_7 , & V_79 ) ;
if ( V_56 ) {
F_52 ( V_128 , L_38 ,
V_244 -> V_199 ) ;
continue;
}
V_17 -> V_202 ++ ;
}
if ( ! V_17 -> V_202 )
F_92 ( V_128 , L_39 ) ;
V_245 = F_120 ( V_178 , L_40 ) ;
F_123 ( & V_17 -> V_201 ) ;
if ( V_245 )
F_96 ( V_17 , V_245 ) ;
F_124 ( V_245 ) ;
if ( ! V_17 -> V_202 ) {
F_52 ( V_128 , L_41 ) ;
V_56 = - V_129 ;
goto V_250;
}
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_128 = V_17 -> V_128 ;
V_247 . V_252 = V_17 -> V_220 ;
V_247 . V_253 = V_254 ;
V_247 . V_224 = V_17 -> V_224 ;
V_247 . V_136 = V_17 -> V_136 ;
V_17 -> V_89 = F_125 ( & V_247 ) ;
if ( ! V_17 -> V_89 ) {
F_52 ( V_17 -> V_128 , L_42 ) ;
V_56 = - V_129 ;
goto V_250;
} else {
F_53 ( V_17 -> V_128 , L_43 ) ;
}
F_57 ( V_17 ) ;
F_126 ( & V_17 -> V_158 ) ;
V_17 -> V_158 . V_14 = ( unsigned long ) V_17 ;
V_17 -> V_158 . V_255 = F_77 ;
V_17 -> V_158 . V_159 = V_160 + V_161 ;
F_79 ( & V_17 -> V_158 ) ;
* V_242 = V_17 ;
return 0 ;
V_250:
if ( V_17 -> V_32 )
F_99 ( V_128 , V_17 -> V_32 ) ;
F_127 ( V_17 -> V_89 ) ;
if ( V_17 -> V_113 )
F_128 ( V_128 , V_17 -> V_113 ) ;
F_124 ( V_243 ) ;
F_99 ( V_128 , V_17 ) ;
return V_56 ;
}
static int F_129 ( void * V_242 , struct V_1 * V_2 ,
struct V_177 * V_178 , void * * V_143 )
{
struct V_16 * V_17 = V_242 ;
struct V_15 * V_15 ;
int V_56 ;
if ( ! V_178 ) {
F_52 ( V_17 -> V_128 , L_44 ) ;
return - V_129 ;
}
V_15 = F_98 ( V_17 -> V_128 , sizeof( * V_15 ) , V_198 ) ;
if ( ! V_15 )
return - V_213 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_128 = V_17 -> V_128 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_57 = F_98 ( V_17 -> V_128 ,
sizeof( * V_15 -> V_57 ) ,
V_198 ) ;
if ( ! V_15 -> V_57 ) {
V_56 = - V_213 ;
goto V_174;
}
if ( F_90 ( V_17 , V_15 -> V_57 , V_178 ) ) {
V_56 = - V_129 ;
goto V_174;
}
V_15 -> V_165 = V_17 -> V_165 ;
V_2 -> V_256 = & V_257 ;
F_100 ( & V_15 -> V_258 , & V_17 -> V_251 ) ;
* V_143 = V_15 ;
return 0 ;
V_174:
if ( V_15 -> V_57 )
F_99 ( V_17 -> V_128 , V_15 -> V_57 ) ;
if ( V_15 )
F_99 ( V_17 -> V_128 , V_15 ) ;
return V_56 ;
}
static int F_130 ( void * V_143 )
{
struct V_15 * V_15 = V_143 ;
V_15 -> V_2 -> V_256 = NULL ;
F_104 ( & V_15 -> V_258 ) ;
F_99 ( V_15 -> V_128 , V_15 -> V_57 ) ;
F_99 ( V_15 -> V_128 , V_15 ) ;
return 0 ;
}
static int F_131 ( struct V_241 * V_241 , void * V_242 )
{
struct V_16 * V_17 = V_242 ;
F_132 ( & V_17 -> V_158 ) ;
F_133 ( V_17 -> V_89 ) ;
F_127 ( V_17 -> V_89 ) ;
F_134 ( & V_17 -> V_165 ) ;
F_102 ( V_17 ) ;
if ( ! F_135 ( & V_17 -> V_251 ) )
F_136 ( V_17 -> V_128 , L_45 ) ;
F_99 ( V_17 -> V_128 , V_17 -> V_32 ) ;
F_128 ( V_17 -> V_128 , V_17 -> V_113 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
F_99 ( V_17 -> V_128 , V_17 ) ;
return 0 ;
}
static int T_10 F_137 ( void )
{
int V_56 ;
V_56 = F_138 ( & V_19 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_138 ( & V_100 ) ;
if ( V_56 )
return V_56 ;
return 0 ;
}
static void T_11 F_139 ( void )
{
F_140 ( & V_19 ) ;
F_140 ( & V_100 ) ;
}
