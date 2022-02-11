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
struct V_1 * V_66 ;
struct V_37 * V_39 ;
int type ;
if ( V_18 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_11 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_39 = F_14 ( V_3 , & V_6 ) ;
if ( V_39 ) {
V_18 -> V_19 = F_28 ( V_3 , & V_39 -> V_67 ) ;
F_27 ( V_3 ,
V_18 -> V_19 ) ;
if ( ! V_18 -> V_19 ) {
F_29 ( V_5 , L_4 ,
F_30 ( V_3 ) ) ;
goto V_68;
}
if ( V_6 -> V_15 -> type == V_69 &&
! F_31 ( F_5 ( V_6 ) ) ) {
F_29 ( V_5 , L_5 ,
F_30 ( V_3 ) ) ;
return V_70 ;
}
V_66 = NULL ;
if ( V_6 -> V_15 -> type == V_45 )
V_66 = F_1 ( V_3 , V_46 ) ;
if ( V_6 -> V_15 -> type == V_46 )
V_66 = F_1 ( V_3 , V_45 ) ;
if ( V_66 && ( ( V_6 -> V_15 -> type == V_46 &&
V_66 -> V_15 -> type == V_45 ) ||
( V_6 -> V_15 -> type == V_45 &&
V_66 -> V_15 -> type == V_46 ) ) ) {
if ( V_18 -> V_19 -> V_22 & V_71 )
type = V_45 ;
else
type = V_46 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_24 ( V_3 , V_6 ) ;
return V_72 ;
}
V_6 = F_17 ( V_3 ) ;
if ( V_6 ) {
F_24 ( V_3 , V_6 ) ;
return V_72 ;
}
V_68:
V_6 = F_1 ( V_3 , V_46 ) ;
if ( ! V_6 && ! V_73 )
V_6 = F_1 ( V_3 , V_74 ) ;
if ( V_6 && V_65 ) {
struct V_75 * V_17 = F_5 ( V_6 ) ;
struct V_76 * V_77 =
V_17 -> V_78 ;
if ( V_77 -> V_79 ( V_17 , V_3 ) ==
V_72 ) {
F_24 ( V_3 , V_6 ) ;
return V_72 ;
}
}
return V_70 ;
}
static enum V_64
F_32 ( struct V_2 * V_3 , bool V_65 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_64 V_80 = V_70 ;
if ( V_18 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_11 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_52 ) ;
if ( ! V_6 )
return V_70 ;
if ( ! V_24 -> V_81 . V_82 ) {
V_80 = F_26 ( V_3 , V_65 ) ;
if ( V_80 == V_72 )
goto V_83;
}
if ( V_6 -> V_15 -> V_84 . V_85 ) {
if ( ! F_33 ( V_5 , V_3 ) ) {
V_80 = V_72 ;
goto V_83;
}
}
if ( F_34 ( V_5 , NULL ) && ( V_24 -> V_81 . V_82 ||
V_6 -> V_15 -> V_84 . V_86 ) ) {
V_80 = V_72 ;
goto V_83;
}
if ( ! V_24 -> V_81 . V_82 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_35 ( V_5 ) ;
if ( V_19 ) {
V_18 -> V_19 = F_36 ( V_49 , V_50 ) ;
* ( V_18 -> V_19 ) = * V_19 ;
V_80 = V_72 ;
}
}
V_83:
#if F_37 ( V_87 ) || \
( F_37 ( V_88 ) && F_37 ( V_89 ) )
if ( V_80 == V_72 &&
! V_90 && ! F_38 () )
V_80 = V_91 ;
#endif
F_27 ( V_3 , V_18 -> V_19 ) ;
F_24 ( V_3 , V_6 ) ;
return V_80 ;
}
static void
F_39 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> V_15 -> type == V_59 ) {
if ( V_3 -> V_65 == V_92 )
type = V_45 ;
else
type = V_46 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_29 ( V_3 -> V_5 , L_6 ,
F_30 ( V_3 ) ) ;
V_3 -> V_80 = V_70 ;
return;
}
F_24 ( V_3 , V_6 ) ;
}
static int
F_40 ( struct V_2 * V_3 ,
struct V_93 * V_94 , T_2 V_95 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_75 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_96 ;
if ( V_94 == V_5 -> V_60 . V_97 ) {
struct V_98 * V_99 = NULL ;
bool V_100 = false ;
switch ( V_95 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
break;
default:
return - V_105 ;
}
if ( V_3 -> V_34 == V_35 &&
V_95 == V_101 )
return - V_105 ;
if ( ( V_18 -> V_106 == V_101 ) ||
( V_95 == V_101 ) )
V_100 = true ;
V_18 -> V_106 = V_95 ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_107 )
V_99 = V_98 ( V_3 -> V_17 -> V_107 ) ;
if ( ! V_99 )
return 0 ;
if ( V_100 || ! V_99 -> V_108 ) {
V_96 = F_41 ( & V_99 -> V_27 ,
& V_99 -> V_27 . V_109 ,
V_99 -> V_27 . V_110 ,
V_99 -> V_27 . V_111 , NULL ) ;
if ( ! V_96 )
return - V_105 ;
} else {
V_96 = V_99 -> V_108 ( V_99 , V_95 , true ) ;
if ( V_96 )
return V_96 ;
}
return 0 ;
}
if ( V_94 == V_5 -> V_60 . V_112 ) {
struct V_98 * V_99 = NULL ;
if ( V_95 == V_113 )
V_18 -> V_114 = true ;
else
V_18 -> V_114 = false ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_107 )
V_99 = V_98 ( V_3 -> V_17 -> V_107 ) ;
if ( ! V_99 || ! V_99 -> V_115 )
return 0 ;
return V_99 -> V_115 ( V_99 , V_18 -> V_114 ,
true ) ;
}
if ( V_6 && V_6 -> V_15 -> type == V_74 )
return F_42 ( V_17 ) -> F_43 (
V_17 , V_3 , V_94 , V_95 ) ;
return - V_105 ;
}
static struct V_116 *
F_44 ( struct V_2 * V_3 )
{
struct V_117 * V_77 = V_3 -> V_78 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_116 * V_109 , * V_118 = NULL ;
int V_119 = 0 , V_120 = 0 , V_121 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_109 -> V_122 = F_45 ( V_109 ) ;
if ( V_77 -> V_123 ( V_3 , V_109 ) != V_124 ||
( V_109 -> V_125 & V_126 ) )
continue;
if ( V_109 -> type & V_127 ) {
F_9 ( V_5 , L_7 ) ;
return F_46 ( V_5 , V_109 ) ;
}
if ( V_109 -> V_128 < V_119 )
continue;
if ( V_109 -> V_128 == V_119 && V_109 -> V_129 < V_120 )
continue;
if ( V_109 -> V_128 == V_119 && V_109 -> V_129 == V_120 &&
V_109 -> V_122 < V_121 )
continue;
V_119 = V_109 -> V_128 ;
V_120 = V_109 -> V_129 ;
V_121 = V_109 -> V_122 ;
V_118 = V_109 ;
}
F_9 ( V_5 , L_8 ,
V_119 , V_120 , V_121 ) ;
return V_118 ? F_46 ( V_5 , V_118 ) : NULL ;
}
static int
F_47 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_116 * V_130 = V_18 -> V_131 , * V_132 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_133 * V_109 = & V_134 [ 0 ] ;
int V_135 = 0 ;
if ( ! V_130 )
return 0 ;
while ( V_109 -> V_128 ) {
if ( V_109 -> V_128 <= V_130 -> V_128 &&
V_109 -> V_129 <= V_130 -> V_129 ) {
V_132 = F_48 ( V_5 , V_109 -> V_128 , V_109 -> V_129 ,
F_45 ( V_130 ) , false ,
false , false ) ;
if ( ! V_132 )
continue;
V_132 -> type |= V_136 ;
F_49 ( V_3 , V_132 ) ;
V_135 ++ ;
}
V_109 ++ ;
}
return V_135 ;
}
static int
F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_75 * V_17 = F_5 ( V_6 ) ;
int V_96 = 0 ;
if ( V_18 -> V_131 ) {
F_51 ( V_5 , V_18 -> V_131 ) ;
V_18 -> V_131 = NULL ;
}
if ( V_18 -> V_19 )
V_96 = F_52 ( V_3 , V_18 -> V_19 ) ;
else
if ( V_6 -> V_15 -> type == V_52 &&
( V_6 -> V_15 -> V_84 . V_86 ||
V_24 -> V_81 . V_82 ) && F_34 ( V_5 , NULL ) ) {
struct V_116 V_109 ;
F_34 ( V_5 , & V_109 ) ;
V_18 -> V_131 = F_46 ( V_5 , & V_109 ) ;
}
if ( ! V_18 -> V_131 )
V_18 -> V_131 =
F_44 ( V_3 ) ;
if ( V_96 == 0 && V_18 -> V_131 ) {
struct V_116 * V_109 ;
V_109 = F_46 ( V_5 , V_18 -> V_131 ) ;
F_49 ( V_3 , V_109 ) ;
V_96 = 1 ;
}
if ( V_6 -> V_15 -> type == V_74 )
V_96 = F_42 ( V_17 ) -> F_53 ( V_17 , V_3 ) ;
if ( V_18 -> V_15 -> type == V_137 ||
V_18 -> V_15 -> type == V_138 ||
V_18 -> V_15 -> type == V_139 )
V_96 += F_47 ( V_3 ) ;
return V_96 ;
}
static unsigned
F_54 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_3 -> V_5 -> V_28 ;
struct V_140 * V_15 = V_18 -> V_51 -> V_15 ;
if ( V_15 -> V_141 != V_142 ||
V_24 -> V_143 >= 0x46 )
return 165000 ;
else if ( V_24 -> V_143 >= 0x40 )
return 155000 ;
else if ( V_24 -> V_143 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_55 ( struct V_2 * V_3 ,
struct V_116 * V_109 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_51 ;
struct V_75 * V_17 = F_5 ( V_6 ) ;
unsigned V_144 = 25000 , V_145 = V_144 ;
unsigned clock = V_109 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_52 :
if ( V_18 -> V_131 &&
( V_109 -> V_128 > V_18 -> V_131 -> V_128 ||
V_109 -> V_129 > V_18 -> V_131 -> V_129 ) )
return V_146 ;
V_144 = 0 ;
V_145 = 400000 ;
break;
case V_45 :
V_145 = F_54 ( V_3 ) ;
if ( V_147 && V_6 -> V_15 -> V_148 )
V_145 *= 2 ;
break;
case V_46 :
V_145 = V_6 -> V_15 -> V_149 . V_150 ;
if ( ! V_145 )
V_145 = 350000 ;
break;
case V_74 :
return F_42 ( V_17 ) -> V_123 ( V_17 , V_109 ) ;
case V_69 :
if ( V_6 -> V_151 . V_152 == V_153 )
V_145 = V_6 -> V_151 . V_154 * 270000 ;
else
V_145 = V_6 -> V_151 . V_154 * 162000 ;
clock = clock * F_7 ( V_3 ) / 8 ;
break;
default:
F_56 ( 1 ) ;
return V_155 ;
}
if ( clock < V_144 )
return V_156 ;
if ( clock > V_145 )
return V_157 ;
return V_124 ;
}
static struct V_75 *
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_51 )
return F_5 ( V_18 -> V_51 ) ;
return NULL ;
}
struct V_2 *
F_58 ( struct V_4 * V_5 , int V_158 )
{
const struct V_159 * V_160 = & V_161 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_25 * V_26 = & V_24 -> V_29 . V_30 ;
struct V_16 * V_18 = NULL ;
struct V_162 * V_15 = NULL ;
struct V_2 * V_3 ;
int type , V_96 = 0 ;
F_9 ( V_5 , L_1 ) ;
if ( V_158 >= V_24 -> V_81 . V_15 . V_3 . V_163 )
return F_59 ( - V_105 ) ;
V_15 = & V_24 -> V_81 . V_15 . V_3 . V_164 [ V_158 ] ;
if ( V_15 -> V_165 )
return V_15 -> V_165 ;
switch ( V_15 -> type ) {
case V_166 :
type = V_167 ;
break;
case V_168 :
case V_169 :
case V_170 :
type = V_171 ;
break;
case V_59 :
type = V_172 ;
break;
case V_173 :
type = V_174 ;
break;
case V_175 :
case V_176 :
type = V_177 ;
break;
case V_137 :
case V_138 :
type = V_35 ;
V_160 = & V_178 ;
break;
case V_179 :
type = V_180 ;
break;
case V_139 :
type = V_36 ;
break;
default:
F_29 ( V_5 , L_9 , V_15 -> type ) ;
return F_59 ( - V_105 ) ;
}
V_18 = F_60 ( sizeof( * V_18 ) , V_50 ) ;
if ( ! V_18 )
return F_59 ( - V_181 ) ;
V_18 -> V_15 = V_15 ;
V_3 = & V_18 -> V_27 ;
V_3 -> V_54 = false ;
V_3 -> V_53 = false ;
F_61 ( V_5 , V_3 , V_160 , type ) ;
F_62 ( V_3 , & V_182 ) ;
if ( V_3 -> V_34 == V_35 ) {
bool V_183 , V_184 = false ;
V_96 = F_63 ( V_5 , 0 , & V_183 , & V_184 ) ;
if ( V_96 ) {
F_29 ( V_5 , L_10
L_11 ) ;
goto V_185;
}
V_18 -> V_114 = ! V_184 ;
}
if ( V_15 -> type == V_59 ) {
F_64 ( V_5 ) ;
F_65 ( V_3 , V_5 -> V_60 . V_61 , 0 ) ;
F_65 ( V_3 , V_5 -> V_60 . V_186 , 0 ) ;
}
switch ( V_15 -> type ) {
case V_166 :
if ( V_24 -> V_55 >= V_187 ) {
F_65 ( V_3 ,
V_5 -> V_60 . V_97 ,
V_18 -> V_106 ) ;
}
V_3 -> V_188 = V_189 ;
case V_168 :
case V_169 :
case V_170 :
V_18 -> V_106 = V_101 ;
break;
default:
V_18 -> V_106 = V_102 ;
F_65 ( V_3 ,
V_5 -> V_60 . V_97 ,
V_18 -> V_106 ) ;
F_65 ( V_3 ,
V_5 -> V_60 . V_112 ,
V_18 -> V_114 ?
V_113 : V_190 ) ;
if ( V_3 -> V_34 != V_35 ) {
if ( V_24 -> V_55 >= V_187 )
V_3 -> V_188 = V_191 ;
else
V_3 -> V_188 = V_189 ;
}
break;
}
if ( V_26 -> V_192 ) {
V_26 -> V_192 ( V_5 , V_18 -> V_15 -> V_32 ,
V_33 , V_3 ) ;
}
F_66 ( V_3 ) ;
if ( V_3 -> V_34 == V_35 ||
V_3 -> V_34 == V_36 )
F_67 ( V_3 ) ;
V_15 -> V_165 = V_3 ;
return V_15 -> V_165 ;
V_185:
F_13 ( V_3 ) ;
F_11 ( V_3 ) ;
return F_59 ( V_96 ) ;
}
static void
V_33 ( void * V_193 , int V_194 )
{
struct V_2 * V_3 = V_193 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_68 ( V_5 , L_12 , V_194 ? L_13 : L_14 ,
F_30 ( V_3 ) ) ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_107 &&
V_3 -> V_17 -> V_107 -> V_195 ) {
struct V_1 * V_6 = V_1 ( V_3 -> V_17 ) ;
struct V_76 * V_77 =
V_3 -> V_17 -> V_78 ;
if ( V_6 -> V_15 -> type == V_69 ) {
if ( V_194 )
V_77 -> V_196 ( V_3 -> V_17 , V_197 ) ;
else
V_77 -> V_196 ( V_3 -> V_17 , V_198 ) ;
}
}
F_69 ( V_5 ) ;
}
