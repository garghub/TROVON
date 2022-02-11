static struct V_1 *
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
int
F_7 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_19 && V_18 -> V_19 -> V_20 >= 4 ) {
T_1 V_21 = ( ( V_18 -> V_19 -> V_22 & 0x70 ) >> 3 ) + 4 ;
if ( V_21 > 4 )
return V_21 ;
}
return 18 ;
}
static void
F_8 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_5 ;
if ( ! V_18 )
return;
V_5 = V_18 -> V_27 . V_5 ;
V_24 = V_5 -> V_28 ;
F_9 ( V_5 , L_1 ) ;
V_26 = & V_24 -> V_29 . V_30 ;
if ( V_26 -> V_31 ) {
V_26 -> V_31 ( V_5 , V_18 -> V_15 -> V_32 ,
V_33 , V_3 ) ;
}
if ( V_3 -> V_34 == V_35 ||
V_3 -> V_34 == V_36 )
F_10 ( V_3 ) ;
F_11 ( V_18 -> V_19 ) ;
F_12 ( V_3 ) ;
F_13 ( V_3 ) ;
F_11 ( V_3 ) ;
}
static struct V_37 *
F_14 ( struct V_2 * V_3 ,
struct V_1 * * V_38 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_37 * V_39 = NULL ;
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
if ( V_6 -> V_15 -> V_40 < 0xf )
V_39 = F_15 ( V_5 , V_6 -> V_15 -> V_40 ) ;
if ( V_39 && F_16 ( V_39 , 0x50 ) ) {
* V_38 = V_6 ;
return V_39 ;
}
}
return NULL ;
}
static struct V_1 *
F_17 ( struct V_2 * V_3 )
{
#ifdef F_18
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_41 * V_42 , * V_43 = F_19 ( V_5 -> V_44 ) ;
if ( ! V_43 ||
! ( ( V_6 = F_1 ( V_3 , V_45 ) ) ||
( V_6 = F_1 ( V_3 , V_46 ) ) ) )
return NULL ;
F_20 (dn, cn) {
const char * V_47 = F_21 ( V_42 , L_2 , NULL ) ;
const void * V_19 = F_21 ( V_42 , L_3 , NULL ) ;
int V_48 = V_47 ? V_47 [ strlen ( V_47 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_40 == V_48 && V_19 ) {
V_18 -> V_19 =
F_22 ( V_19 , V_49 , V_50 ) ;
F_23 ( V_42 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_24 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_3 -> V_5 -> V_28 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_51 == V_6 )
return;
V_18 -> V_51 = V_6 ;
if ( V_6 -> V_15 -> type == V_52 ||
V_6 -> V_15 -> type == V_45 ) {
V_3 -> V_53 = false ;
V_3 -> V_54 = false ;
} else {
V_3 -> V_53 = true ;
if ( V_24 -> V_55 == V_56 ||
( V_24 -> V_55 == V_57 &&
( V_5 -> V_58 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_58 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_54 = false ;
else
V_3 -> V_54 = true ;
}
if ( V_18 -> V_15 -> type == V_59 ) {
F_25 ( V_3 ,
V_5 -> V_60 . V_61 ,
V_6 -> V_15 -> type == V_45 ?
V_62 :
V_63 ) ;
}
}
static enum V_64
F_26 ( struct V_2 * V_3 , bool V_65 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_37 * V_39 ;
int type ;
if ( V_18 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_11 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_39 = F_14 ( V_3 , & V_6 ) ;
if ( V_39 ) {
V_18 -> V_19 = F_28 ( V_3 , & V_39 -> V_66 ) ;
F_27 ( V_3 ,
V_18 -> V_19 ) ;
if ( ! V_18 -> V_19 ) {
F_29 ( V_5 , L_4 ,
F_30 ( V_3 ) ) ;
goto V_67;
}
if ( V_6 -> V_15 -> type == V_68 &&
! F_31 ( F_5 ( V_6 ) ) ) {
F_29 ( V_5 , L_5 ,
F_30 ( V_3 ) ) ;
return V_69 ;
}
if ( V_18 -> V_15 -> type == V_59 ) {
if ( V_18 -> V_19 -> V_22 & V_70 )
type = V_45 ;
else
type = V_46 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_29 ( V_5 , L_6
L_7 , type ,
F_30 ( V_3 ) ) ;
return V_69 ;
}
}
F_24 ( V_3 , V_6 ) ;
return V_71 ;
}
V_6 = F_17 ( V_3 ) ;
if ( V_6 ) {
F_24 ( V_3 , V_6 ) ;
return V_71 ;
}
V_67:
V_6 = F_1 ( V_3 , V_46 ) ;
if ( ! V_6 && ! V_72 )
V_6 = F_1 ( V_3 , V_73 ) ;
if ( V_6 && V_65 ) {
struct V_74 * V_17 = F_5 ( V_6 ) ;
struct V_75 * V_76 =
V_17 -> V_77 ;
if ( V_76 -> V_78 ( V_17 , V_3 ) ==
V_71 ) {
F_24 ( V_3 , V_6 ) ;
return V_71 ;
}
}
return V_69 ;
}
static enum V_64
F_32 ( struct V_2 * V_3 , bool V_65 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_64 V_79 = V_69 ;
if ( V_18 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_11 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_52 ) ;
if ( ! V_6 )
return V_69 ;
if ( ! V_24 -> V_80 . V_81 ) {
V_79 = F_26 ( V_3 , V_65 ) ;
if ( V_79 == V_71 )
goto V_82;
}
if ( V_6 -> V_15 -> V_83 . V_84 ) {
if ( ! F_33 ( V_5 , V_3 ) ) {
V_79 = V_71 ;
goto V_82;
}
}
if ( F_34 ( V_5 , NULL ) && ( V_24 -> V_80 . V_81 ||
V_6 -> V_15 -> V_83 . V_85 ) ) {
V_79 = V_71 ;
goto V_82;
}
if ( ! V_24 -> V_80 . V_81 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_35 ( V_5 ) ;
if ( V_19 ) {
V_18 -> V_19 = F_36 ( V_49 , V_50 ) ;
* ( V_18 -> V_19 ) = * V_19 ;
V_79 = V_71 ;
}
}
V_82:
#if F_37 ( V_86 ) || \
( F_37 ( V_87 ) && F_37 ( V_88 ) )
if ( V_79 == V_71 &&
! V_89 && ! F_38 () )
V_79 = V_90 ;
#endif
F_27 ( V_3 , V_18 -> V_19 ) ;
F_24 ( V_3 , V_6 ) ;
return V_79 ;
}
static void
F_39 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> V_15 -> type == V_59 ) {
if ( V_3 -> V_65 == V_91 )
type = V_45 ;
else
type = V_46 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_29 ( V_3 -> V_5 , L_8 ,
F_30 ( V_3 ) ) ;
V_3 -> V_79 = V_69 ;
return;
}
F_24 ( V_3 , V_6 ) ;
}
static int
F_40 ( struct V_2 * V_3 ,
struct V_92 * V_93 , T_2 V_94 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_74 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_95 ;
if ( V_93 == V_5 -> V_60 . V_96 ) {
struct V_97 * V_98 = NULL ;
bool V_99 = false ;
switch ( V_94 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
break;
default:
return - V_104 ;
}
if ( V_3 -> V_34 == V_35 &&
V_94 == V_100 )
return - V_104 ;
if ( ( V_18 -> V_105 == V_100 ) ||
( V_94 == V_100 ) )
V_99 = true ;
V_18 -> V_105 = V_94 ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_106 )
V_98 = V_97 ( V_3 -> V_17 -> V_106 ) ;
if ( ! V_98 )
return 0 ;
if ( V_99 || ! V_98 -> V_107 ) {
V_95 = F_41 ( & V_98 -> V_27 ,
& V_98 -> V_27 . V_108 ,
V_98 -> V_27 . V_109 ,
V_98 -> V_27 . V_110 , NULL ) ;
if ( ! V_95 )
return - V_104 ;
} else {
V_95 = V_98 -> V_107 ( V_98 , V_94 , true ) ;
if ( V_95 )
return V_95 ;
}
return 0 ;
}
if ( V_93 == V_5 -> V_60 . V_111 ) {
struct V_97 * V_98 = NULL ;
if ( V_94 == V_112 )
V_18 -> V_113 = true ;
else
V_18 -> V_113 = false ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_106 )
V_98 = V_97 ( V_3 -> V_17 -> V_106 ) ;
if ( ! V_98 || ! V_98 -> V_114 )
return 0 ;
return V_98 -> V_114 ( V_98 , V_18 -> V_113 ,
true ) ;
}
if ( V_6 && V_6 -> V_15 -> type == V_73 )
return F_42 ( V_17 ) -> F_43 (
V_17 , V_3 , V_93 , V_94 ) ;
return - V_104 ;
}
static struct V_115 *
F_44 ( struct V_2 * V_3 )
{
struct V_116 * V_76 = V_3 -> V_77 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_115 * V_108 , * V_117 = NULL ;
int V_118 = 0 , V_119 = 0 , V_120 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_108 -> V_121 = F_45 ( V_108 ) ;
if ( V_76 -> V_122 ( V_3 , V_108 ) != V_123 ||
( V_108 -> V_124 & V_125 ) )
continue;
if ( V_108 -> type & V_126 ) {
F_9 ( V_5 , L_9 ) ;
return F_46 ( V_5 , V_108 ) ;
}
if ( V_108 -> V_127 < V_118 )
continue;
if ( V_108 -> V_127 == V_118 && V_108 -> V_128 < V_119 )
continue;
if ( V_108 -> V_127 == V_118 && V_108 -> V_128 == V_119 &&
V_108 -> V_121 < V_120 )
continue;
V_118 = V_108 -> V_127 ;
V_119 = V_108 -> V_128 ;
V_120 = V_108 -> V_121 ;
V_117 = V_108 ;
}
F_9 ( V_5 , L_10 ,
V_118 , V_119 , V_120 ) ;
return V_117 ? F_46 ( V_5 , V_117 ) : NULL ;
}
static int
F_47 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_115 * V_129 = V_18 -> V_130 , * V_131 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_132 * V_108 = & V_133 [ 0 ] ;
int V_134 = 0 ;
if ( ! V_129 )
return 0 ;
while ( V_108 -> V_127 ) {
if ( V_108 -> V_127 <= V_129 -> V_127 &&
V_108 -> V_128 <= V_129 -> V_128 ) {
V_131 = F_48 ( V_5 , V_108 -> V_127 , V_108 -> V_128 ,
F_45 ( V_129 ) , false ,
false , false ) ;
if ( ! V_131 )
continue;
V_131 -> type |= V_135 ;
F_49 ( V_3 , V_131 ) ;
V_134 ++ ;
}
V_108 ++ ;
}
return V_134 ;
}
static int
F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_74 * V_17 = F_5 ( V_6 ) ;
int V_95 = 0 ;
if ( V_18 -> V_130 ) {
F_51 ( V_5 , V_18 -> V_130 ) ;
V_18 -> V_130 = NULL ;
}
if ( V_18 -> V_19 )
V_95 = F_52 ( V_3 , V_18 -> V_19 ) ;
else
if ( V_6 -> V_15 -> type == V_52 &&
( V_6 -> V_15 -> V_83 . V_85 ||
V_24 -> V_80 . V_81 ) && F_34 ( V_5 , NULL ) ) {
struct V_115 V_108 ;
F_34 ( V_5 , & V_108 ) ;
V_18 -> V_130 = F_46 ( V_5 , & V_108 ) ;
}
if ( ! V_18 -> V_130 )
V_18 -> V_130 =
F_44 ( V_3 ) ;
if ( V_95 == 0 && V_18 -> V_130 ) {
struct V_115 * V_108 ;
V_108 = F_46 ( V_5 , V_18 -> V_130 ) ;
F_49 ( V_3 , V_108 ) ;
V_95 = 1 ;
}
if ( V_6 -> V_15 -> type == V_73 )
V_95 = F_42 ( V_17 ) -> F_53 ( V_17 , V_3 ) ;
if ( V_18 -> V_15 -> type == V_136 ||
V_18 -> V_15 -> type == V_137 ||
V_18 -> V_15 -> type == V_138 )
V_95 += F_47 ( V_3 ) ;
return V_95 ;
}
static unsigned
F_54 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_3 -> V_5 -> V_28 ;
struct V_139 * V_15 = V_18 -> V_51 -> V_15 ;
if ( V_15 -> V_140 != V_141 ||
V_24 -> V_142 >= 0x46 )
return 165000 ;
else if ( V_24 -> V_142 >= 0x40 )
return 155000 ;
else if ( V_24 -> V_142 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_55 ( struct V_2 * V_3 ,
struct V_115 * V_108 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_74 * V_17 = F_5 ( V_6 ) ;
unsigned V_143 = 25000 , V_144 = V_143 ;
unsigned clock = V_108 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_52 :
if ( V_18 -> V_130 &&
( V_108 -> V_127 > V_18 -> V_130 -> V_127 ||
V_108 -> V_128 > V_18 -> V_130 -> V_128 ) )
return V_145 ;
V_143 = 0 ;
V_144 = 400000 ;
break;
case V_45 :
V_144 = F_54 ( V_3 ) ;
if ( V_146 && V_6 -> V_15 -> V_147 )
V_144 *= 2 ;
break;
case V_46 :
V_144 = V_6 -> V_15 -> V_148 . V_149 ;
if ( ! V_144 )
V_144 = 350000 ;
break;
case V_73 :
return F_42 ( V_17 ) -> V_122 ( V_17 , V_108 ) ;
case V_68 :
if ( V_6 -> V_150 . V_151 == V_152 )
V_144 = V_6 -> V_150 . V_153 * 270000 ;
else
V_144 = V_6 -> V_150 . V_153 * 162000 ;
clock = clock * F_7 ( V_3 ) / 8 ;
break;
default:
F_56 ( 1 ) ;
return V_154 ;
}
if ( clock < V_143 )
return V_155 ;
if ( clock > V_144 )
return V_156 ;
return V_123 ;
}
static struct V_74 *
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_51 )
return F_5 ( V_18 -> V_51 ) ;
return NULL ;
}
struct V_2 *
F_58 ( struct V_4 * V_5 , int V_157 )
{
const struct V_158 * V_159 = & V_160 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_25 * V_26 = & V_24 -> V_29 . V_30 ;
struct V_16 * V_18 = NULL ;
struct V_161 * V_15 = NULL ;
struct V_2 * V_3 ;
int type , V_95 = 0 ;
F_9 ( V_5 , L_1 ) ;
if ( V_157 >= V_24 -> V_80 . V_15 . V_3 . V_162 )
return F_59 ( - V_104 ) ;
V_15 = & V_24 -> V_80 . V_15 . V_3 . V_163 [ V_157 ] ;
if ( V_15 -> V_164 )
return V_15 -> V_164 ;
switch ( V_15 -> type ) {
case V_165 :
type = V_166 ;
break;
case V_167 :
case V_168 :
case V_169 :
type = V_170 ;
break;
case V_59 :
type = V_171 ;
break;
case V_172 :
type = V_173 ;
break;
case V_174 :
case V_175 :
type = V_176 ;
break;
case V_136 :
case V_137 :
type = V_35 ;
V_159 = & V_177 ;
break;
case V_178 :
type = V_179 ;
break;
case V_138 :
type = V_36 ;
break;
default:
F_29 ( V_5 , L_11 , V_15 -> type ) ;
return F_59 ( - V_104 ) ;
}
V_18 = F_60 ( sizeof( * V_18 ) , V_50 ) ;
if ( ! V_18 )
return F_59 ( - V_180 ) ;
V_18 -> V_15 = V_15 ;
V_3 = & V_18 -> V_27 ;
V_3 -> V_54 = false ;
V_3 -> V_53 = false ;
F_61 ( V_5 , V_3 , V_159 , type ) ;
F_62 ( V_3 , & V_181 ) ;
if ( V_3 -> V_34 == V_35 ) {
bool V_182 , V_183 = false ;
V_95 = F_63 ( V_5 , 0 , & V_182 , & V_183 ) ;
if ( V_95 ) {
F_29 ( V_5 , L_12
L_13 ) ;
goto V_184;
}
V_18 -> V_113 = ! V_183 ;
}
if ( V_15 -> type == V_59 ) {
F_64 ( V_5 ) ;
F_65 ( V_3 , V_5 -> V_60 . V_61 , 0 ) ;
F_65 ( V_3 , V_5 -> V_60 . V_185 , 0 ) ;
}
switch ( V_15 -> type ) {
case V_165 :
if ( V_24 -> V_55 >= V_186 ) {
F_65 ( V_3 ,
V_5 -> V_60 . V_96 ,
V_18 -> V_105 ) ;
}
V_3 -> V_187 = V_188 ;
case V_167 :
case V_168 :
case V_169 :
V_18 -> V_105 = V_100 ;
break;
default:
V_18 -> V_105 = V_101 ;
F_65 ( V_3 ,
V_5 -> V_60 . V_96 ,
V_18 -> V_105 ) ;
F_65 ( V_3 ,
V_5 -> V_60 . V_111 ,
V_18 -> V_113 ?
V_112 : V_189 ) ;
if ( V_3 -> V_34 != V_35 ) {
if ( V_24 -> V_55 >= V_186 )
V_3 -> V_187 = V_190 ;
else
V_3 -> V_187 = V_188 ;
}
break;
}
if ( V_26 -> V_191 ) {
V_26 -> V_191 ( V_5 , V_18 -> V_15 -> V_32 ,
V_33 , V_3 ) ;
}
F_66 ( V_3 ) ;
if ( V_3 -> V_34 == V_35 ||
V_3 -> V_34 == V_36 )
F_67 ( V_3 ) ;
V_15 -> V_164 = V_3 ;
return V_15 -> V_164 ;
V_184:
F_13 ( V_3 ) ;
F_11 ( V_3 ) ;
return F_59 ( V_95 ) ;
}
static void
V_33 ( void * V_192 , int V_193 )
{
struct V_2 * V_3 = V_192 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_68 ( V_5 , L_14 , V_193 ? L_15 : L_16 ,
F_30 ( V_3 ) ) ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_106 &&
V_3 -> V_17 -> V_106 -> V_194 ) {
struct V_1 * V_6 = V_1 ( V_3 -> V_17 ) ;
struct V_75 * V_76 =
V_3 -> V_17 -> V_77 ;
if ( V_6 -> V_15 -> type == V_68 ) {
if ( V_193 )
V_76 -> V_195 ( V_3 -> V_17 , V_196 ) ;
else
V_76 -> V_195 ( V_3 -> V_17 , V_197 ) ;
}
}
F_69 ( V_5 ) ;
}
