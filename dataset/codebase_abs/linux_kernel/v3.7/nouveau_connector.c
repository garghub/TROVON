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
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
if ( ! V_18 )
return;
V_5 = V_18 -> V_23 . V_5 ;
V_22 = V_21 ( V_5 ) ;
V_20 = V_19 ( V_22 -> V_24 ) ;
F_8 ( V_22 , L_1 ) ;
if ( V_20 && V_18 -> V_25 != V_26 ) {
V_20 -> V_27 ( V_20 , 0 , V_18 -> V_25 , 0xff ,
V_28 , V_3 ) ;
}
F_9 ( V_18 -> V_29 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static struct V_30 *
F_12 ( struct V_2 * V_3 ,
struct V_1 * * V_31 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_32 * V_33 = V_32 ( V_22 -> V_24 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_30 * V_34 = NULL ;
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
if ( V_6 -> V_15 -> V_35 < 0xf )
V_34 = V_33 -> V_36 ( V_33 , V_6 -> V_15 -> V_35 ) ;
if ( V_34 && F_13 ( V_34 , 0x50 ) ) {
* V_31 = V_6 ;
return V_34 ;
}
}
return NULL ;
}
static struct V_1 *
F_14 ( struct V_2 * V_3 )
{
#ifdef F_15
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_37 * V_38 , * V_39 = F_16 ( V_5 -> V_40 ) ;
if ( ! V_39 ||
! ( ( V_6 = F_1 ( V_3 , V_41 ) ) ||
( V_6 = F_1 ( V_3 , V_42 ) ) ) )
return NULL ;
F_17 (dn, cn) {
const char * V_43 = F_18 ( V_38 , L_2 , NULL ) ;
const void * V_29 = F_18 ( V_38 , L_3 , NULL ) ;
int V_44 = V_43 ? V_43 [ strlen ( V_43 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_35 == V_44 && V_29 ) {
V_18 -> V_29 =
F_19 ( V_29 , V_45 , V_46 ) ;
F_20 ( V_38 ) ;
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
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_47 == V_6 )
return;
V_18 -> V_47 = V_6 ;
if ( F_22 ( V_22 -> V_24 ) -> V_48 >= V_49 ) {
V_3 -> V_50 = true ;
V_3 -> V_51 = true ;
} else
if ( V_6 -> V_15 -> type == V_52 ||
V_6 -> V_15 -> type == V_41 ) {
V_3 -> V_51 = false ;
V_3 -> V_50 = false ;
} else {
V_3 -> V_51 = true ;
if ( F_22 ( V_22 -> V_24 ) -> V_48 == V_53 ||
( F_22 ( V_22 -> V_24 ) -> V_48 == V_54 &&
( V_5 -> V_55 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_55 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_50 = false ;
else
V_3 -> V_50 = true ;
}
if ( V_18 -> type == V_56 ) {
F_23 ( V_3 ,
V_5 -> V_57 . V_58 ,
V_6 -> V_15 -> type == V_41 ?
V_59 :
V_60 ) ;
}
}
static enum V_61
F_24 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_63 ;
struct V_30 * V_33 ;
int type ;
if ( V_18 -> V_29 ) {
F_25 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_29 ) ;
V_18 -> V_29 = NULL ;
}
V_33 = F_12 ( V_3 , & V_6 ) ;
if ( V_33 ) {
V_18 -> V_29 = F_26 ( V_3 , & V_33 -> V_64 ) ;
F_25 ( V_3 ,
V_18 -> V_29 ) ;
if ( ! V_18 -> V_29 ) {
F_27 ( V_22 , L_4 ,
F_28 ( V_3 ) ) ;
goto V_65;
}
if ( V_6 -> V_15 -> type == V_66 &&
! F_29 ( F_5 ( V_6 ) ) ) {
F_27 ( V_22 , L_5 ,
F_28 ( V_3 ) ) ;
return V_67 ;
}
V_63 = NULL ;
if ( V_6 -> V_15 -> type == V_41 )
V_63 = F_1 ( V_3 , V_42 ) ;
if ( V_6 -> V_15 -> type == V_42 )
V_63 = F_1 ( V_3 , V_41 ) ;
if ( V_63 && ( ( V_6 -> V_15 -> type == V_42 &&
V_63 -> V_15 -> type == V_41 ) ||
( V_6 -> V_15 -> type == V_41 &&
V_63 -> V_15 -> type == V_42 ) ) ) {
if ( V_18 -> V_29 -> V_68 & V_69 )
type = V_41 ;
else
type = V_42 ;
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
V_6 = F_1 ( V_3 , V_42 ) ;
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
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_61 V_78 = V_67 ;
if ( V_18 -> V_29 ) {
F_25 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_29 ) ;
V_18 -> V_29 = NULL ;
}
V_6 = F_1 ( V_3 , V_52 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_22 -> V_79 . V_80 ) {
V_78 = F_24 ( V_3 , V_62 ) ;
if ( V_78 == V_70 )
goto V_81;
}
if ( V_6 -> V_15 -> V_82 . V_83 ) {
if ( ( V_18 -> V_29 = F_31 ( V_5 , V_3 ) ) ) {
V_78 = V_70 ;
goto V_81;
}
}
if ( F_32 ( V_5 , NULL ) && ( V_22 -> V_79 . V_80 ||
V_6 -> V_15 -> V_82 . V_84 ) ) {
V_78 = V_70 ;
goto V_81;
}
if ( ! V_22 -> V_79 . V_80 ) {
struct V_29 * V_29 =
(struct V_29 * ) F_33 ( V_5 ) ;
if ( V_29 ) {
V_18 -> V_29 = F_34 ( V_45 , V_46 ) ;
* ( V_18 -> V_29 ) = * V_29 ;
V_78 = V_70 ;
}
}
V_81:
#if F_35 ( V_85 ) || \
( F_35 ( V_86 ) && F_35 ( V_87 ) )
if ( V_78 == V_70 &&
! V_88 && ! F_36 () )
V_78 = V_89 ;
#endif
F_25 ( V_3 , V_18 -> V_29 ) ;
F_21 ( V_3 , V_6 ) ;
return V_78 ;
}
static void
F_37 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_56 ) {
if ( V_3 -> V_62 == V_90 )
type = V_41 ;
else
type = V_42 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_27 ( V_22 , L_6 ,
F_28 ( V_3 ) ) ;
V_3 -> V_78 = V_67 ;
return;
}
F_21 ( V_3 , V_6 ) ;
}
static int
F_38 ( struct V_2 * V_3 ,
struct V_91 * V_92 , T_1 V_93 )
{
struct V_94 * V_95 = V_94 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
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
V_98 = F_39 ( & V_97 -> V_23 ,
& V_97 -> V_23 . V_111 ,
V_97 -> V_23 . V_112 ,
V_97 -> V_23 . V_113 , NULL ) ;
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
return F_40 ( V_17 ) -> F_41 (
V_17 , V_3 , V_92 , V_93 ) ;
return - V_106 ;
}
static struct V_128 *
F_42 ( struct V_2 * V_3 )
{
struct V_129 * V_75 = V_3 -> V_76 ;
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_128 * V_111 , * V_130 = NULL ;
int V_131 = 0 , V_132 = 0 , V_133 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_111 -> V_134 = F_43 ( V_111 ) ;
if ( V_75 -> V_135 ( V_3 , V_111 ) != V_136 ||
( V_111 -> V_137 & V_138 ) )
continue;
if ( V_111 -> type & V_139 ) {
F_8 ( V_22 , L_7 ) ;
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
F_8 ( V_22 , L_8 ,
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
F_43 ( V_142 ) , false ,
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
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_149 * V_150 = & V_22 -> V_79 ;
struct V_128 * V_111 = V_18 -> V_143 ;
bool V_151 ;
if ( V_18 -> V_29 && V_3 -> V_152 . V_153 )
return;
if ( V_18 -> type == V_154 ) {
V_3 -> V_152 . V_153 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_52 ) {
V_3 -> V_152 . V_153 = 8 ;
return;
}
V_3 -> V_152 . V_153 = 6 ;
if ( V_150 -> V_80 ) {
if ( V_150 -> V_155 . V_156 )
V_3 -> V_152 . V_153 = 8 ;
return;
}
if ( V_18 -> V_29 &&
V_18 -> type == V_157 )
V_151 = ( ( V_158 * ) V_18 -> V_29 ) [ 121 ] == 2 ;
else
V_151 = V_111 -> clock >= V_150 -> V_155 . V_159 ;
if ( ( ! V_151 && ( V_150 -> V_155 . V_160 & 1 ) ) ||
( V_151 && ( V_150 -> V_155 . V_160 & 2 ) ) )
V_3 -> V_152 . V_153 = 8 ;
}
static int
F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_73 * V_17 = F_5 ( V_6 ) ;
int V_98 = 0 ;
if ( V_18 -> V_143 ) {
F_50 ( V_5 , V_18 -> V_143 ) ;
V_18 -> V_143 = NULL ;
}
if ( V_18 -> V_29 )
V_98 = F_51 ( V_3 , V_18 -> V_29 ) ;
else
if ( V_6 -> V_15 -> type == V_52 &&
( V_6 -> V_15 -> V_82 . V_84 ||
V_22 -> V_79 . V_80 ) && F_32 ( V_5 , NULL ) ) {
struct V_128 V_111 ;
F_32 ( V_5 , & V_111 ) ;
V_18 -> V_143 = F_44 ( V_5 , & V_111 ) ;
}
if ( V_3 -> V_107 != V_108 )
F_48 ( V_3 ) ;
if ( ! V_18 -> V_143 )
V_18 -> V_143 =
F_42 ( V_3 ) ;
if ( V_98 == 0 && V_18 -> V_143 ) {
struct V_128 * V_111 ;
V_111 = F_44 ( V_5 , V_18 -> V_143 ) ;
F_47 ( V_3 , V_111 ) ;
V_98 = 1 ;
}
if ( V_3 -> V_107 == V_108 )
F_48 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_72 )
V_98 = F_40 ( V_17 ) -> F_52 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_161 ||
V_18 -> type == V_157 ||
V_18 -> type == V_154 )
V_98 += F_45 ( V_3 ) ;
return V_98 ;
}
static unsigned
F_53 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_162 * V_15 = V_18 -> V_47 -> V_15 ;
if ( V_15 -> V_163 != V_164 ||
F_22 ( V_22 -> V_24 ) -> V_165 >= 0x46 )
return 165000 ;
else if ( F_22 ( V_22 -> V_24 ) -> V_165 >= 0x40 )
return 155000 ;
else if ( F_22 ( V_22 -> V_24 ) -> V_165 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_54 ( struct V_2 * V_3 ,
struct V_128 * V_111 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_73 * V_17 = F_5 ( V_6 ) ;
unsigned V_166 = 25000 , V_167 = V_166 ;
unsigned clock = V_111 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_52 :
if ( V_18 -> V_143 &&
( V_111 -> V_140 > V_18 -> V_143 -> V_140 ||
V_111 -> V_141 > V_18 -> V_143 -> V_141 ) )
return V_168 ;
V_166 = 0 ;
V_167 = 400000 ;
break;
case V_41 :
V_167 = F_53 ( V_3 ) ;
if ( V_169 && V_6 -> V_15 -> V_170 )
V_167 *= 2 ;
break;
case V_42 :
V_167 = V_6 -> V_15 -> V_171 . V_172 ;
if ( ! V_167 )
V_167 = 350000 ;
break;
case V_72 :
return F_40 ( V_17 ) -> V_135 ( V_17 , V_111 ) ;
case V_66 :
V_167 = V_6 -> V_173 . V_174 ;
V_167 *= V_6 -> V_173 . V_175 ;
clock = clock * ( V_3 -> V_152 . V_153 * 3 ) / 10 ;
break;
default:
F_55 ( 1 ) ;
return V_176 ;
}
if ( clock < V_166 )
return V_177 ;
if ( clock > V_167 )
return V_178 ;
return V_136 ;
}
static struct V_73 *
F_56 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_47 )
return F_5 ( V_18 -> V_47 ) ;
return NULL ;
}
static int
F_57 ( enum V_179 V_15 )
{
switch ( V_15 ) {
case V_180 : return V_181 ;
case V_182 :
case V_183 :
case V_184 : return V_185 ;
case V_186 :
case V_187 :
case V_56 : return V_188 ;
case V_189 : return V_190 ;
case V_161 :
case V_157 : return V_108 ;
case V_191 :
case V_192 :
case V_193 : return V_194 ;
case V_154 : return V_195 ;
case V_196 :
case V_197 : return V_198 ;
default:
break;
}
return V_199 ;
}
struct V_2 *
F_58 ( struct V_4 * V_5 , int V_200 )
{
const struct V_201 * V_202 = & V_203 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_19 * V_20 = V_19 ( V_22 -> V_24 ) ;
struct V_94 * V_95 = V_94 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_98 = 0 ;
bool V_204 ;
F_8 ( V_22 , L_1 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_200 == V_200 )
return V_3 ;
}
V_18 = F_59 ( sizeof( * V_18 ) , V_46 ) ;
if ( ! V_18 )
return F_60 ( - V_205 ) ;
V_3 = & V_18 -> V_23 ;
V_18 -> V_200 = V_200 ;
V_18 -> V_15 = F_61 ( V_5 , V_200 ) ;
if ( V_18 -> V_15 ) {
static const V_158 V_25 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_206 = F_62 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_63 ( V_5 ) [ 3 ] >= 4 )
V_206 |= ( T_2 ) F_62 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_18 -> V_25 = F_64 ( ( V_206 & 0x07033000 ) >> 12 ) ;
V_18 -> V_25 = V_25 [ V_18 -> V_25 ] ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_57 ( V_18 -> type ) ==
V_199 ) {
F_65 ( V_22 , L_9 ,
V_18 -> type ) ;
V_18 -> type = V_207 ;
}
if ( F_66 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_197 )
V_18 -> type = V_56 ;
}
if ( F_66 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_197 )
V_18 -> type = V_56 ;
}
} else {
V_18 -> type = V_207 ;
V_18 -> V_25 = V_26 ;
}
if ( V_18 -> type == V_207 ) {
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_208 * V_209 = & V_22 -> V_79 . V_15 ;
T_2 V_210 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_209 -> V_211 ; V_9 ++ ) {
if ( V_209 -> V_206 [ V_9 ] . V_3 == V_18 -> V_200 )
V_210 |= ( 1 << V_209 -> V_206 [ V_9 ] . type ) ;
}
if ( V_210 & ( 1 << V_66 ) ) {
if ( V_210 & ( 1 << V_41 ) )
V_18 -> type = V_193 ;
else
V_18 -> type = V_154 ;
} else
if ( V_210 & ( 1 << V_41 ) ) {
if ( V_210 & ( 1 << V_42 ) )
V_18 -> type = V_56 ;
else
V_18 -> type = V_189 ;
} else
if ( V_210 & ( 1 << V_42 ) ) {
V_18 -> type = V_180 ;
} else
if ( V_210 & ( 1 << V_52 ) ) {
V_18 -> type = V_161 ;
} else
if ( V_210 & ( 1 << V_72 ) ) {
V_18 -> type = V_182 ;
}
}
type = F_57 ( V_18 -> type ) ;
if ( type == V_108 ) {
V_98 = F_67 ( V_5 , 0 , & V_204 , & V_204 ) ;
if ( V_98 ) {
F_27 ( V_22 , L_10 ) ;
F_9 ( V_18 ) ;
return F_60 ( V_98 ) ;
}
V_202 = & V_212 ;
} else {
V_202 = & V_203 ;
}
V_3 -> V_50 = false ;
V_3 -> V_51 = false ;
F_68 ( V_5 , V_3 , V_202 , type ) ;
F_69 ( V_3 , & V_213 ) ;
if ( V_18 -> type == V_56 )
F_70 ( V_3 , V_5 -> V_57 . V_58 , 0 ) ;
if ( V_95 -> V_114 &&
( type == V_190 ||
type == V_188 ||
type == V_198 ||
type == V_194 ) ) {
F_70 ( V_3 ,
V_95 -> V_114 ,
V_214 ) ;
F_70 ( V_3 ,
V_95 -> V_116 ,
0 ) ;
F_70 ( V_3 ,
V_95 -> V_118 ,
0 ) ;
}
if ( V_95 -> V_124 )
F_70 ( V_3 ,
V_95 -> V_124 ,
90 ) ;
if ( V_95 -> V_126 )
F_70 ( V_3 ,
V_95 -> V_126 ,
150 ) ;
switch ( V_18 -> type ) {
case V_180 :
if ( F_22 ( V_22 -> V_24 ) -> V_48 >= V_49 ) {
F_70 ( V_3 ,
V_5 -> V_57 . V_100 ,
V_18 -> V_109 ) ;
}
case V_182 :
case V_183 :
case V_184 :
V_18 -> V_109 = V_102 ;
break;
default:
V_18 -> V_109 = V_103 ;
F_70 ( V_3 ,
V_5 -> V_57 . V_100 ,
V_18 -> V_109 ) ;
if ( V_95 -> V_120 ) {
V_18 -> V_120 = V_215 ;
F_70 ( V_3 ,
V_95 -> V_120 ,
V_18 -> V_120 ) ;
}
if ( V_95 -> V_122 ) {
V_18 -> V_122 = V_216 ;
F_70 ( V_3 ,
V_95 -> V_122 ,
V_18 -> V_122 ) ;
}
break;
}
V_3 -> V_217 = V_218 ;
if ( V_20 && V_18 -> V_25 != V_26 ) {
V_98 = V_20 -> V_219 ( V_20 , 0 , V_18 -> V_25 , 0xff ,
V_28 , V_3 ) ;
if ( V_98 == 0 )
V_3 -> V_217 = V_220 ;
}
F_71 ( V_3 ) ;
return V_3 ;
}
static void
V_28 ( void * V_221 , int V_222 )
{
struct V_2 * V_3 = V_221 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
F_8 ( V_22 , L_11 , V_222 ? L_12 : L_13 ,
F_28 ( V_3 ) ) ;
if ( V_222 )
F_72 ( V_3 , V_223 ) ;
else
F_72 ( V_3 , V_224 ) ;
F_73 ( V_5 ) ;
}
