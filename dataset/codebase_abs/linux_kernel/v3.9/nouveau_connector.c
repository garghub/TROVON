struct V_1 *
F_1 ( struct V_2 * V_3 , int type )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_10 = V_3 -> V_12 [ V_9 ] ;
if ( ! V_10 )
break;
V_8 = F_2 ( V_5 , V_10 , V_13 ) ;
if ( ! V_8 )
continue;
V_6 = V_1 ( F_3 ( V_8 ) ) ;
if ( type == V_14 || V_6 -> V_15 -> type == type )
return V_6 ;
}
return NULL ;
}
struct V_16 *
F_4 ( struct V_1 * V_17 )
{
struct V_4 * V_5 = F_5 ( V_17 ) -> V_5 ;
struct V_2 * V_2 ;
F_6 (drm_connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_17 == F_5 ( V_17 ) )
return V_16 ( V_2 ) ;
}
return NULL ;
}
static void
F_7 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
F_8 ( V_18 -> V_19 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
F_8 ( V_3 ) ;
}
static struct V_20 *
F_11 ( struct V_2 * V_3 ,
struct V_1 * * V_21 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
struct V_20 * V_27 = NULL ;
int V_9 , V_28 = - V_29 ;
if ( V_18 -> type == V_30 ) {
V_28 = V_25 -> V_31 ( V_25 , 0 , V_32 , 0xff ) ;
if ( V_28 == 0 ) {
V_25 -> V_33 ( V_25 , 0 , V_32 , 0xff , 1 ) ;
F_12 ( 300 ) ;
}
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_10 ;
V_10 = V_3 -> V_12 [ V_9 ] ;
if ( ! V_10 )
break;
V_8 = F_2 ( V_5 , V_10 , V_13 ) ;
if ( ! V_8 )
continue;
V_6 = V_1 ( F_3 ( V_8 ) ) ;
V_27 = V_6 -> V_34 ;
if ( V_27 && F_13 ( V_27 , 0x50 ) ) {
* V_21 = V_6 ;
break;
}
V_27 = NULL ;
}
if ( ! V_27 && V_28 == 0 )
V_25 -> V_33 ( V_25 , 0 , V_32 , 0xff , V_28 ) ;
return V_27 ;
}
static struct V_1 *
F_14 ( struct V_2 * V_3 )
{
#ifdef F_15
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_35 * V_36 , * V_37 = F_16 ( V_5 -> V_38 ) ;
if ( ! V_37 ||
! ( ( V_6 = F_1 ( V_3 , V_39 ) ) ||
( V_6 = F_1 ( V_3 , V_40 ) ) ) )
return NULL ;
F_17 (dn, cn) {
const char * V_41 = F_18 ( V_36 , L_1 , NULL ) ;
const void * V_19 = F_18 ( V_36 , L_2 , NULL ) ;
int V_42 = V_41 ? V_41 [ strlen ( V_41 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_43 == V_42 && V_19 ) {
V_18 -> V_19 =
F_19 ( V_19 , V_44 , V_45 ) ;
F_20 ( V_36 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_21 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_46 == V_6 )
return;
V_18 -> V_46 = V_6 ;
if ( F_22 ( V_23 -> V_26 ) -> V_47 >= V_48 ) {
V_3 -> V_49 = true ;
V_3 -> V_50 = true ;
} else
if ( V_6 -> V_15 -> type == V_51 ||
V_6 -> V_15 -> type == V_39 ) {
V_3 -> V_50 = false ;
V_3 -> V_49 = false ;
} else {
V_3 -> V_50 = true ;
if ( F_22 ( V_23 -> V_26 ) -> V_47 == V_52 ||
( F_22 ( V_23 -> V_26 ) -> V_47 == V_53 &&
( V_5 -> V_54 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_54 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_49 = false ;
else
V_3 -> V_49 = true ;
}
if ( V_18 -> type == V_55 ) {
F_23 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_58 ,
V_6 -> V_15 -> type == V_39 ?
V_59 :
V_60 ) ;
}
}
static enum V_61
F_24 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_63 ;
struct V_20 * V_34 ;
int type ;
if ( V_18 -> V_19 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_34 = F_11 ( V_3 , & V_6 ) ;
if ( V_34 ) {
V_18 -> V_19 = F_26 ( V_3 , & V_34 -> V_64 ) ;
F_25 ( V_3 ,
V_18 -> V_19 ) ;
if ( ! V_18 -> V_19 ) {
F_27 ( V_23 , L_3 ,
F_28 ( V_3 ) ) ;
goto V_65;
}
if ( V_6 -> V_15 -> type == V_66 &&
! F_29 ( F_5 ( V_6 ) ) ) {
F_27 ( V_23 , L_4 ,
F_28 ( V_3 ) ) ;
return V_67 ;
}
V_63 = NULL ;
if ( V_6 -> V_15 -> type == V_39 )
V_63 = F_1 ( V_3 , V_40 ) ;
if ( V_6 -> V_15 -> type == V_40 )
V_63 = F_1 ( V_3 , V_39 ) ;
if ( V_63 && ( ( V_6 -> V_15 -> type == V_40 &&
V_63 -> V_15 -> type == V_39 ) ||
( V_6 -> V_15 -> type == V_39 &&
V_63 -> V_15 -> type == V_40 ) ) ) {
if ( V_18 -> V_19 -> V_68 & V_69 )
type = V_39 ;
else
type = V_40 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_21 ( V_3 , V_6 ) ;
return V_70 ;
}
V_6 = F_14 ( V_3 ) ;
if ( V_6 ) {
F_21 ( V_3 , V_6 ) ;
return V_70 ;
}
V_65:
V_6 = F_1 ( V_3 , V_40 ) ;
if ( ! V_6 && ! V_71 )
V_6 = F_1 ( V_3 , V_72 ) ;
if ( V_6 && V_62 ) {
struct V_73 * V_17 = F_5 ( V_6 ) ;
struct V_74 * V_75 =
V_17 -> V_76 ;
if ( V_75 -> V_77 ( V_17 , V_3 ) ==
V_70 ) {
F_21 ( V_3 , V_6 ) ;
return V_70 ;
}
}
return V_67 ;
}
static enum V_61
F_30 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_61 V_78 = V_67 ;
if ( V_18 -> V_19 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_51 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_23 -> V_79 . V_80 ) {
V_78 = F_24 ( V_3 , V_62 ) ;
if ( V_78 == V_70 )
goto V_81;
}
if ( V_6 -> V_15 -> V_82 . V_83 ) {
if ( ( V_18 -> V_19 = F_31 ( V_5 , V_3 ) ) ) {
V_78 = V_70 ;
goto V_81;
}
}
if ( F_32 ( V_5 , NULL ) && ( V_23 -> V_79 . V_80 ||
V_6 -> V_15 -> V_82 . V_84 ) ) {
V_78 = V_70 ;
goto V_81;
}
if ( ! V_23 -> V_79 . V_80 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_33 ( V_5 ) ;
if ( V_19 ) {
V_18 -> V_19 =
F_19 ( V_19 , V_44 , V_45 ) ;
if ( V_18 -> V_19 )
V_78 = V_70 ;
}
}
V_81:
#if F_34 ( V_85 ) || \
( F_34 ( V_86 ) && F_34 ( V_87 ) )
if ( V_78 == V_70 &&
! V_88 && ! F_35 () )
V_78 = V_89 ;
#endif
F_25 ( V_3 , V_18 -> V_19 ) ;
F_21 ( V_3 , V_6 ) ;
return V_78 ;
}
static void
F_36 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_55 ) {
if ( V_3 -> V_62 == V_90 )
type = V_39 ;
else
type = V_40 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_27 ( V_23 , L_5 ,
F_28 ( V_3 ) ) ;
V_3 -> V_78 = V_67 ;
return;
}
F_21 ( V_3 , V_6 ) ;
}
static int
F_37 ( struct V_2 * V_3 ,
struct V_91 * V_92 , T_1 V_93 )
{
struct V_94 * V_95 = V_94 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_73 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_96 * V_97 ;
int V_98 ;
V_97 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_99 )
V_97 = V_96 ( V_3 -> V_17 -> V_99 ) ;
if ( V_92 == V_5 -> V_57 . V_100 ) {
bool V_101 = false ;
switch ( V_93 ) {
case V_102 :
case V_103 :
case V_104 :
case V_105 :
break;
default:
return - V_106 ;
}
if ( V_3 -> V_107 == V_108 &&
V_93 == V_102 )
return - V_106 ;
if ( ( V_18 -> V_109 == V_102 ) ||
( V_93 == V_102 ) )
V_101 = true ;
V_18 -> V_109 = V_93 ;
if ( ! V_97 )
return 0 ;
if ( V_101 || ! V_97 -> V_110 ) {
V_98 = F_38 ( & V_97 -> V_56 ,
& V_97 -> V_56 . V_111 ,
V_97 -> V_56 . V_112 ,
V_97 -> V_56 . V_113 , NULL ) ;
if ( ! V_98 )
return - V_106 ;
} else {
V_98 = V_97 -> V_110 ( V_97 , true ) ;
if ( V_98 )
return V_98 ;
}
return 0 ;
}
if ( V_92 == V_95 -> V_114 ) {
if ( V_18 -> V_115 != V_93 ) {
V_18 -> V_115 = V_93 ;
if ( ! V_97 || ! V_97 -> V_110 )
return 0 ;
return V_97 -> V_110 ( V_97 , true ) ;
}
return 0 ;
}
if ( V_92 == V_95 -> V_116 ) {
if ( V_18 -> V_117 != V_93 ) {
V_18 -> V_117 = V_93 ;
if ( ! V_97 || ! V_97 -> V_110 )
return 0 ;
return V_97 -> V_110 ( V_97 , true ) ;
}
return 0 ;
}
if ( V_92 == V_95 -> V_118 ) {
if ( V_18 -> V_119 != V_93 ) {
V_18 -> V_119 = V_93 ;
if ( ! V_97 || ! V_97 -> V_110 )
return 0 ;
return V_97 -> V_110 ( V_97 , true ) ;
}
return 0 ;
}
if ( V_92 == V_95 -> V_120 ) {
V_18 -> V_120 = V_93 ;
if ( ! V_97 || ! V_97 -> V_121 )
return 0 ;
return V_97 -> V_121 ( V_97 , true ) ;
}
if ( V_92 == V_95 -> V_122 ) {
V_18 -> V_122 = V_93 ;
if ( ! V_97 || ! V_97 -> V_121 )
return 0 ;
return V_97 -> V_121 ( V_97 , true ) ;
}
if ( V_97 && V_97 -> V_123 ) {
if ( V_92 == V_95 -> V_124 ) {
V_97 -> V_125 = V_93 - 90 ;
return V_97 -> V_123 ( V_97 , true ) ;
}
if ( V_92 == V_95 -> V_126 ) {
V_97 -> V_127 = V_93 - 100 ;
return V_97 -> V_123 ( V_97 , true ) ;
}
}
if ( V_6 && V_6 -> V_15 -> type == V_72 )
return F_39 ( V_17 ) -> F_40 (
V_17 , V_3 , V_92 , V_93 ) ;
return - V_106 ;
}
static struct V_128 *
F_41 ( struct V_2 * V_3 )
{
struct V_129 * V_75 = V_3 -> V_76 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_128 * V_111 , * V_130 = NULL ;
int V_131 = 0 , V_132 = 0 , V_133 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_111 -> V_134 = F_42 ( V_111 ) ;
if ( V_75 -> V_135 ( V_3 , V_111 ) != V_136 ||
( V_111 -> V_137 & V_138 ) )
continue;
if ( V_111 -> type & V_139 ) {
F_43 ( V_23 , L_6 ) ;
return F_44 ( V_5 , V_111 ) ;
}
if ( V_111 -> V_140 < V_131 )
continue;
if ( V_111 -> V_140 == V_131 && V_111 -> V_141 < V_132 )
continue;
if ( V_111 -> V_140 == V_131 && V_111 -> V_141 == V_132 &&
V_111 -> V_134 < V_133 )
continue;
V_131 = V_111 -> V_140 ;
V_132 = V_111 -> V_141 ;
V_133 = V_111 -> V_134 ;
V_130 = V_111 ;
}
F_43 ( V_23 , L_7 ,
V_131 , V_132 , V_133 ) ;
return V_130 ? F_44 ( V_5 , V_130 ) : NULL ;
}
static int
F_45 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_128 * V_142 = V_18 -> V_143 , * V_144 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_145 * V_111 = & V_146 [ 0 ] ;
int V_147 = 0 ;
if ( ! V_142 )
return 0 ;
while ( V_111 -> V_140 ) {
if ( V_111 -> V_140 <= V_142 -> V_140 &&
V_111 -> V_141 <= V_142 -> V_141 ) {
V_144 = F_46 ( V_5 , V_111 -> V_140 , V_111 -> V_141 ,
F_42 ( V_142 ) , false ,
false , false ) ;
if ( ! V_144 )
continue;
V_144 -> type |= V_148 ;
F_47 ( V_3 , V_144 ) ;
V_147 ++ ;
}
V_111 ++ ;
}
return V_147 ;
}
static void
F_48 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_149 * V_150 = & V_23 -> V_79 ;
struct V_128 * V_111 = V_18 -> V_143 ;
bool V_151 ;
if ( V_18 -> V_19 && V_3 -> V_152 . V_153 )
return;
if ( V_18 -> type == V_30 ) {
V_3 -> V_152 . V_153 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_51 ) {
V_3 -> V_152 . V_153 = 8 ;
return;
}
V_3 -> V_152 . V_153 = 6 ;
if ( V_150 -> V_80 ) {
if ( V_150 -> V_154 . V_155 )
V_3 -> V_152 . V_153 = 8 ;
return;
}
if ( V_18 -> V_19 &&
V_18 -> type == V_156 )
V_151 = ( ( V_157 * ) V_18 -> V_19 ) [ 121 ] == 2 ;
else
V_151 = V_111 -> clock >= V_150 -> V_154 . V_158 ;
if ( ( ! V_151 && ( V_150 -> V_154 . V_159 & 1 ) ) ||
( V_151 && ( V_150 -> V_154 . V_159 & 2 ) ) )
V_3 -> V_152 . V_153 = 8 ;
}
static int
F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_73 * V_17 = F_5 ( V_6 ) ;
int V_98 = 0 ;
if ( V_18 -> V_143 ) {
F_50 ( V_5 , V_18 -> V_143 ) ;
V_18 -> V_143 = NULL ;
}
if ( V_18 -> V_19 )
V_98 = F_51 ( V_3 , V_18 -> V_19 ) ;
else
if ( V_6 -> V_15 -> type == V_51 &&
( V_6 -> V_15 -> V_82 . V_84 ||
V_23 -> V_79 . V_80 ) && F_32 ( V_5 , NULL ) ) {
struct V_128 V_111 ;
F_32 ( V_5 , & V_111 ) ;
V_18 -> V_143 = F_44 ( V_5 , & V_111 ) ;
}
if ( V_3 -> V_107 != V_108 )
F_48 ( V_3 ) ;
if ( ! V_18 -> V_143 )
V_18 -> V_143 =
F_41 ( V_3 ) ;
if ( V_98 == 0 && V_18 -> V_143 ) {
struct V_128 * V_111 ;
V_111 = F_44 ( V_5 , V_18 -> V_143 ) ;
F_47 ( V_3 , V_111 ) ;
V_98 = 1 ;
}
if ( V_3 -> V_107 == V_108 )
F_48 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_72 )
V_98 = F_39 ( V_17 ) -> F_52 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_160 ||
V_18 -> type == V_156 ||
V_18 -> type == V_30 )
V_98 += F_45 ( V_3 ) ;
return V_98 ;
}
static unsigned
F_53 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_161 * V_15 = V_18 -> V_46 -> V_15 ;
if ( V_15 -> V_162 != V_163 ||
F_22 ( V_23 -> V_26 ) -> V_164 >= 0x46 )
return 165000 ;
else if ( F_22 ( V_23 -> V_26 ) -> V_164 >= 0x40 )
return 155000 ;
else if ( F_22 ( V_23 -> V_26 ) -> V_164 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_54 ( struct V_2 * V_3 ,
struct V_128 * V_111 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_73 * V_17 = F_5 ( V_6 ) ;
unsigned V_165 = 25000 , V_166 = V_165 ;
unsigned clock = V_111 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_51 :
if ( V_18 -> V_143 &&
( V_111 -> V_140 > V_18 -> V_143 -> V_140 ||
V_111 -> V_141 > V_18 -> V_143 -> V_141 ) )
return V_167 ;
V_165 = 0 ;
V_166 = 400000 ;
break;
case V_39 :
V_166 = F_53 ( V_3 ) ;
if ( V_168 && V_6 -> V_15 -> V_169 )
V_166 *= 2 ;
break;
case V_40 :
V_166 = V_6 -> V_15 -> V_170 . V_171 ;
if ( ! V_166 )
V_166 = 350000 ;
break;
case V_72 :
return F_39 ( V_17 ) -> V_135 ( V_17 , V_111 ) ;
case V_66 :
V_166 = V_6 -> V_172 . V_173 ;
V_166 *= V_6 -> V_172 . V_174 ;
clock = clock * ( V_3 -> V_152 . V_153 * 3 ) / 10 ;
break;
default:
F_55 ( 1 ) ;
return V_175 ;
}
if ( clock < V_165 )
return V_176 ;
if ( clock > V_166 )
return V_177 ;
return V_136 ;
}
static struct V_73 *
F_56 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_46 )
return F_5 ( V_18 -> V_46 ) ;
return NULL ;
}
static void
F_57 ( struct V_178 * V_179 )
{
struct V_16 * V_18 =
F_58 ( V_179 , struct V_16 , V_180 ) ;
struct V_2 * V_3 = & V_18 -> V_56 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
bool V_181 = V_25 -> V_31 ( V_25 , 0 , V_18 -> V_182 . V_183 , 0xff ) ;
F_43 ( V_23 , L_8 , V_181 ? L_9 : L_10 ,
F_28 ( V_3 ) ) ;
if ( V_181 )
F_59 ( V_3 , V_184 ) ;
else
F_59 ( V_3 , V_185 ) ;
F_60 ( V_5 ) ;
}
static int
F_61 ( struct V_186 * V_187 , int V_188 )
{
struct V_16 * V_18 =
F_58 ( V_187 , struct V_16 , V_189 ) ;
F_62 ( & V_18 -> V_180 ) ;
return V_190 ;
}
static int
F_63 ( enum V_191 V_15 )
{
switch ( V_15 ) {
case V_192 : return V_193 ;
case V_194 :
case V_195 :
case V_196 : return V_197 ;
case V_198 :
case V_199 :
case V_55 : return V_200 ;
case V_201 : return V_202 ;
case V_160 :
case V_156 : return V_108 ;
case V_203 :
case V_204 :
case V_205 : return V_206 ;
case V_30 : return V_207 ;
case V_208 :
case V_209 : return V_210 ;
default:
break;
}
return V_211 ;
}
struct V_2 *
F_64 ( struct V_4 * V_5 , int V_188 )
{
const struct V_212 * V_213 = & V_214 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
struct V_94 * V_95 = V_94 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_98 = 0 ;
bool V_215 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_188 == V_188 )
return V_3 ;
}
V_18 = F_65 ( sizeof( * V_18 ) , V_45 ) ;
if ( ! V_18 )
return F_66 ( - V_216 ) ;
V_3 = & V_18 -> V_56 ;
F_67 ( & V_18 -> V_180 , F_57 ) ;
V_18 -> V_188 = V_188 ;
V_18 -> V_15 = F_68 ( V_5 , V_188 ) ;
if ( V_18 -> V_15 ) {
static const V_157 V_182 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_217 = F_69 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_70 ( V_5 ) [ 3 ] >= 4 )
V_217 |= ( T_2 ) F_69 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_98 = V_25 -> V_218 ( V_25 , 0 , V_182 [ F_71 ( ( V_217 & 0x07033000 ) >> 12 ) ] ,
V_219 , & V_18 -> V_182 ) ;
V_18 -> V_189 . V_183 = F_61 ;
if ( V_98 )
V_18 -> V_182 . V_183 = V_219 ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_63 ( V_18 -> type ) ==
V_211 ) {
F_72 ( V_23 , L_11 ,
V_18 -> type ) ;
V_18 -> type = V_220 ;
}
if ( F_73 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_209 )
V_18 -> type = V_55 ;
}
if ( F_73 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_209 )
V_18 -> type = V_55 ;
}
} else {
V_18 -> type = V_220 ;
V_18 -> V_182 . V_183 = V_219 ;
}
if ( V_18 -> type == V_220 ) {
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_221 * V_222 = & V_23 -> V_79 . V_15 ;
T_2 V_223 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_222 -> V_224 ; V_9 ++ ) {
if ( V_222 -> V_217 [ V_9 ] . V_3 == V_18 -> V_188 )
V_223 |= ( 1 << V_222 -> V_217 [ V_9 ] . type ) ;
}
if ( V_223 & ( 1 << V_66 ) ) {
if ( V_223 & ( 1 << V_39 ) )
V_18 -> type = V_205 ;
else
V_18 -> type = V_30 ;
} else
if ( V_223 & ( 1 << V_39 ) ) {
if ( V_223 & ( 1 << V_40 ) )
V_18 -> type = V_55 ;
else
V_18 -> type = V_201 ;
} else
if ( V_223 & ( 1 << V_40 ) ) {
V_18 -> type = V_192 ;
} else
if ( V_223 & ( 1 << V_51 ) ) {
V_18 -> type = V_160 ;
} else
if ( V_223 & ( 1 << V_72 ) ) {
V_18 -> type = V_194 ;
}
}
type = F_63 ( V_18 -> type ) ;
if ( type == V_108 ) {
V_98 = F_74 ( V_5 , 0 , & V_215 , & V_215 ) ;
if ( V_98 ) {
F_27 ( V_23 , L_12 ) ;
F_8 ( V_18 ) ;
return F_66 ( V_98 ) ;
}
V_213 = & V_225 ;
} else {
V_213 = & V_214 ;
}
V_3 -> V_49 = false ;
V_3 -> V_50 = false ;
F_75 ( V_5 , V_3 , V_213 , type ) ;
F_76 ( V_3 , & V_226 ) ;
if ( V_18 -> type == V_55 )
F_77 ( & V_3 -> V_56 , V_5 -> V_57 . V_58 , 0 ) ;
if ( V_95 -> V_114 &&
( type == V_202 ||
type == V_200 ||
type == V_210 ||
type == V_206 ) ) {
F_77 ( & V_3 -> V_56 ,
V_95 -> V_114 ,
V_227 ) ;
F_77 ( & V_3 -> V_56 ,
V_95 -> V_116 ,
0 ) ;
F_77 ( & V_3 -> V_56 ,
V_95 -> V_118 ,
0 ) ;
}
if ( V_95 -> V_124 )
F_77 ( & V_3 -> V_56 ,
V_95 -> V_124 ,
90 ) ;
if ( V_95 -> V_126 )
F_77 ( & V_3 -> V_56 ,
V_95 -> V_126 ,
150 ) ;
switch ( V_18 -> type ) {
case V_192 :
if ( F_22 ( V_23 -> V_26 ) -> V_47 >= V_48 ) {
F_77 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_100 ,
V_18 -> V_109 ) ;
}
case V_194 :
case V_195 :
case V_196 :
V_18 -> V_109 = V_102 ;
break;
default:
V_18 -> V_109 = V_103 ;
F_77 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_100 ,
V_18 -> V_109 ) ;
if ( V_95 -> V_120 ) {
V_18 -> V_120 = V_228 ;
F_77 ( & V_3 -> V_56 ,
V_95 -> V_120 ,
V_18 -> V_120 ) ;
}
if ( V_95 -> V_122 ) {
V_18 -> V_122 = V_229 ;
F_77 ( & V_3 -> V_56 ,
V_95 -> V_122 ,
V_18 -> V_122 ) ;
}
break;
}
V_3 -> V_230 = V_231 ;
if ( V_18 -> V_182 . V_183 != V_219 )
V_3 -> V_230 = V_232 ;
F_78 ( V_3 ) ;
return V_3 ;
}
