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
F_10 ( V_18 -> V_19 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
F_10 ( V_3 ) ;
}
static struct V_34 *
F_13 ( struct V_2 * V_3 ,
struct V_1 * * V_35 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_34 * V_36 = NULL ;
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
if ( V_6 -> V_15 -> V_37 < 0xf )
V_36 = F_14 ( V_5 , V_6 -> V_15 -> V_37 ) ;
if ( V_36 && F_15 ( V_36 , 0x50 ) ) {
* V_35 = V_6 ;
return V_36 ;
}
}
return NULL ;
}
static struct V_1 *
F_16 ( struct V_2 * V_3 )
{
#ifdef F_17
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_38 * V_39 , * V_40 = F_18 ( V_5 -> V_41 ) ;
if ( ! V_40 ||
! ( ( V_6 = F_1 ( V_3 , V_42 ) ) ||
( V_6 = F_1 ( V_3 , V_43 ) ) ) )
return NULL ;
F_19 (dn, cn) {
const char * V_44 = F_20 ( V_39 , L_2 , NULL ) ;
const void * V_19 = F_20 ( V_39 , L_3 , NULL ) ;
int V_45 = V_44 ? V_44 [ strlen ( V_44 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_37 == V_45 && V_19 ) {
V_18 -> V_19 =
F_21 ( V_19 , V_46 , V_47 ) ;
F_22 ( V_39 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_23 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_3 -> V_5 -> V_28 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_48 == V_6 )
return;
V_18 -> V_48 = V_6 ;
if ( V_6 -> V_15 -> type == V_49 ||
V_6 -> V_15 -> type == V_42 ) {
V_3 -> V_50 = false ;
V_3 -> V_51 = false ;
} else {
V_3 -> V_50 = true ;
if ( V_24 -> V_52 == V_53 ||
( V_24 -> V_52 == V_54 &&
( V_5 -> V_55 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_55 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_51 = false ;
else
V_3 -> V_51 = true ;
}
if ( V_18 -> V_15 -> type == V_56 ) {
F_24 ( V_3 ,
V_5 -> V_57 . V_58 ,
V_6 -> V_15 -> type == V_42 ?
V_59 :
V_60 ) ;
}
}
static enum V_61
F_25 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_63 ;
struct V_34 * V_36 ;
int type ;
if ( V_18 -> V_19 ) {
F_26 ( V_3 , NULL ) ;
F_10 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_36 = F_13 ( V_3 , & V_6 ) ;
if ( V_36 ) {
V_18 -> V_19 = F_27 ( V_3 , & V_36 -> V_64 ) ;
F_26 ( V_3 ,
V_18 -> V_19 ) ;
if ( ! V_18 -> V_19 ) {
F_28 ( V_5 , L_4 ,
F_29 ( V_3 ) ) ;
goto V_65;
}
if ( V_6 -> V_15 -> type == V_66 &&
! F_30 ( F_5 ( V_6 ) ) ) {
F_28 ( V_5 , L_5 ,
F_29 ( V_3 ) ) ;
return V_67 ;
}
V_63 = NULL ;
if ( V_6 -> V_15 -> type == V_42 )
V_63 = F_1 ( V_3 , V_43 ) ;
if ( V_6 -> V_15 -> type == V_43 )
V_63 = F_1 ( V_3 , V_42 ) ;
if ( V_63 && ( ( V_6 -> V_15 -> type == V_43 &&
V_63 -> V_15 -> type == V_42 ) ||
( V_6 -> V_15 -> type == V_42 &&
V_63 -> V_15 -> type == V_43 ) ) ) {
if ( V_18 -> V_19 -> V_22 & V_68 )
type = V_42 ;
else
type = V_43 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_23 ( V_3 , V_6 ) ;
return V_69 ;
}
V_6 = F_16 ( V_3 ) ;
if ( V_6 ) {
F_23 ( V_3 , V_6 ) ;
return V_69 ;
}
V_65:
V_6 = F_1 ( V_3 , V_43 ) ;
if ( ! V_6 && ! V_70 )
V_6 = F_1 ( V_3 , V_71 ) ;
if ( V_6 && V_62 ) {
struct V_72 * V_17 = F_5 ( V_6 ) ;
struct V_73 * V_74 =
V_17 -> V_75 ;
if ( V_74 -> V_76 ( V_17 , V_3 ) ==
V_69 ) {
F_23 ( V_3 , V_6 ) ;
return V_69 ;
}
}
return V_67 ;
}
static enum V_61
F_31 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_61 V_77 = V_67 ;
if ( V_18 -> V_19 ) {
F_26 ( V_3 , NULL ) ;
F_10 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_49 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_24 -> V_78 . V_79 ) {
V_77 = F_25 ( V_3 , V_62 ) ;
if ( V_77 == V_69 )
goto V_80;
}
if ( V_6 -> V_15 -> V_81 . V_82 ) {
if ( ! F_32 ( V_5 , V_3 ) ) {
V_77 = V_69 ;
goto V_80;
}
}
if ( F_33 ( V_5 , NULL ) && ( V_24 -> V_78 . V_79 ||
V_6 -> V_15 -> V_81 . V_83 ) ) {
V_77 = V_69 ;
goto V_80;
}
if ( ! V_24 -> V_78 . V_79 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_34 ( V_5 ) ;
if ( V_19 ) {
V_18 -> V_19 = F_35 ( V_46 , V_47 ) ;
* ( V_18 -> V_19 ) = * V_19 ;
V_77 = V_69 ;
}
}
V_80:
#if F_36 ( V_84 ) || \
( F_36 ( V_85 ) && F_36 ( V_86 ) )
if ( V_77 == V_69 &&
! V_87 && ! F_37 () )
V_77 = V_88 ;
#endif
F_26 ( V_3 , V_18 -> V_19 ) ;
F_23 ( V_3 , V_6 ) ;
return V_77 ;
}
static void
F_38 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> V_15 -> type == V_56 ) {
if ( V_3 -> V_62 == V_89 )
type = V_42 ;
else
type = V_43 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_28 ( V_3 -> V_5 , L_6 ,
F_29 ( V_3 ) ) ;
V_3 -> V_77 = V_67 ;
return;
}
F_23 ( V_3 , V_6 ) ;
}
static int
F_39 ( struct V_2 * V_3 ,
struct V_90 * V_91 , T_2 V_92 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_72 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_93 ;
if ( V_91 == V_5 -> V_57 . V_94 ) {
struct V_95 * V_96 = NULL ;
bool V_97 = false ;
switch ( V_92 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
break;
default:
return - V_102 ;
}
if ( V_3 -> V_103 == V_104 &&
V_92 == V_98 )
return - V_102 ;
if ( ( V_18 -> V_105 == V_98 ) ||
( V_92 == V_98 ) )
V_97 = true ;
V_18 -> V_105 = V_92 ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_106 )
V_96 = V_95 ( V_3 -> V_17 -> V_106 ) ;
if ( ! V_96 )
return 0 ;
if ( V_97 || ! V_96 -> V_107 ) {
V_93 = F_40 ( & V_96 -> V_27 ,
& V_96 -> V_27 . V_108 ,
V_96 -> V_27 . V_109 ,
V_96 -> V_27 . V_110 , NULL ) ;
if ( ! V_93 )
return - V_102 ;
} else {
V_93 = V_96 -> V_107 ( V_96 , V_92 , true ) ;
if ( V_93 )
return V_93 ;
}
return 0 ;
}
if ( V_91 == V_5 -> V_57 . V_111 ) {
struct V_95 * V_96 = NULL ;
if ( V_92 == V_112 )
V_18 -> V_113 = true ;
else
V_18 -> V_113 = false ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_106 )
V_96 = V_95 ( V_3 -> V_17 -> V_106 ) ;
if ( ! V_96 || ! V_96 -> V_114 )
return 0 ;
return V_96 -> V_114 ( V_96 , V_18 -> V_113 ,
true ) ;
}
if ( V_6 && V_6 -> V_15 -> type == V_71 )
return F_41 ( V_17 ) -> F_42 (
V_17 , V_3 , V_91 , V_92 ) ;
return - V_102 ;
}
static struct V_115 *
F_43 ( struct V_2 * V_3 )
{
struct V_116 * V_74 = V_3 -> V_75 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_115 * V_108 , * V_117 = NULL ;
int V_118 = 0 , V_119 = 0 , V_120 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_108 -> V_121 = F_44 ( V_108 ) ;
if ( V_74 -> V_122 ( V_3 , V_108 ) != V_123 ||
( V_108 -> V_124 & V_125 ) )
continue;
if ( V_108 -> type & V_126 ) {
F_9 ( V_5 , L_7 ) ;
return F_45 ( V_5 , V_108 ) ;
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
F_9 ( V_5 , L_8 ,
V_118 , V_119 , V_120 ) ;
return V_117 ? F_45 ( V_5 , V_117 ) : NULL ;
}
static int
F_46 ( struct V_2 * V_3 )
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
V_131 = F_47 ( V_5 , V_108 -> V_127 , V_108 -> V_128 ,
F_44 ( V_129 ) , false ,
false , false ) ;
if ( ! V_131 )
continue;
V_131 -> type |= V_135 ;
F_48 ( V_3 , V_131 ) ;
V_134 ++ ;
}
V_108 ++ ;
}
return V_134 ;
}
static int
F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_72 * V_17 = F_5 ( V_6 ) ;
int V_93 = 0 ;
if ( V_18 -> V_130 ) {
F_50 ( V_5 , V_18 -> V_130 ) ;
V_18 -> V_130 = NULL ;
}
if ( V_18 -> V_19 )
V_93 = F_51 ( V_3 , V_18 -> V_19 ) ;
else
if ( V_6 -> V_15 -> type == V_49 &&
( V_6 -> V_15 -> V_81 . V_83 ||
V_24 -> V_78 . V_79 ) && F_33 ( V_5 , NULL ) ) {
struct V_115 V_108 ;
F_33 ( V_5 , & V_108 ) ;
V_18 -> V_130 = F_45 ( V_5 , & V_108 ) ;
}
if ( ! V_18 -> V_130 )
V_18 -> V_130 =
F_43 ( V_3 ) ;
if ( V_93 == 0 && V_18 -> V_130 ) {
struct V_115 * V_108 ;
V_108 = F_45 ( V_5 , V_18 -> V_130 ) ;
F_48 ( V_3 , V_108 ) ;
V_93 = 1 ;
}
if ( V_6 -> V_15 -> type == V_71 )
V_93 = F_41 ( V_17 ) -> F_52 ( V_17 , V_3 ) ;
if ( V_18 -> V_15 -> type == V_136 ||
V_18 -> V_15 -> type == V_137 ||
V_18 -> V_15 -> type == V_138 )
V_93 += F_46 ( V_3 ) ;
return V_93 ;
}
static unsigned
F_53 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_3 -> V_5 -> V_28 ;
struct V_139 * V_15 = V_18 -> V_48 -> V_15 ;
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
F_54 ( struct V_2 * V_3 ,
struct V_115 * V_108 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_72 * V_17 = F_5 ( V_6 ) ;
unsigned V_143 = 25000 , V_144 = V_143 ;
unsigned clock = V_108 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_49 :
if ( V_18 -> V_130 &&
( V_108 -> V_127 > V_18 -> V_130 -> V_127 ||
V_108 -> V_128 > V_18 -> V_130 -> V_128 ) )
return V_145 ;
V_143 = 0 ;
V_144 = 400000 ;
break;
case V_42 :
V_144 = F_53 ( V_3 ) ;
if ( V_146 && V_6 -> V_15 -> V_147 )
V_144 *= 2 ;
break;
case V_43 :
V_144 = V_6 -> V_15 -> V_148 . V_149 ;
if ( ! V_144 )
V_144 = 350000 ;
break;
case V_71 :
return F_41 ( V_17 ) -> V_122 ( V_17 , V_108 ) ;
case V_66 :
V_144 = V_6 -> V_150 . V_151 ;
V_144 *= V_6 -> V_150 . V_152 ;
clock = clock * F_7 ( V_3 ) / 10 ;
break;
default:
F_55 ( 1 ) ;
return V_153 ;
}
if ( clock < V_143 )
return V_154 ;
if ( clock > V_144 )
return V_155 ;
return V_123 ;
}
static struct V_72 *
F_56 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_48 )
return F_5 ( V_18 -> V_48 ) ;
return NULL ;
}
struct V_2 *
F_57 ( struct V_4 * V_5 , int V_156 )
{
const struct V_157 * V_158 = & V_159 ;
struct V_23 * V_24 = V_5 -> V_28 ;
struct V_25 * V_26 = & V_24 -> V_29 . V_30 ;
struct V_16 * V_18 = NULL ;
struct V_160 * V_15 = NULL ;
struct V_2 * V_3 ;
int type , V_93 = 0 ;
F_9 ( V_5 , L_1 ) ;
if ( V_156 >= V_24 -> V_78 . V_15 . V_3 . V_161 )
return F_58 ( - V_102 ) ;
V_15 = & V_24 -> V_78 . V_15 . V_3 . V_162 [ V_156 ] ;
if ( V_15 -> V_163 )
return V_15 -> V_163 ;
switch ( V_15 -> type ) {
case V_164 :
type = V_165 ;
break;
case V_166 :
case V_167 :
case V_168 :
type = V_169 ;
break;
case V_56 :
type = V_170 ;
break;
case V_171 :
type = V_172 ;
break;
case V_173 :
case V_174 :
type = V_175 ;
break;
case V_136 :
case V_137 :
type = V_104 ;
V_158 = & V_176 ;
break;
case V_177 :
type = V_178 ;
break;
case V_138 :
type = V_179 ;
break;
default:
F_28 ( V_5 , L_9 , V_15 -> type ) ;
return F_58 ( - V_102 ) ;
}
V_18 = F_59 ( sizeof( * V_18 ) , V_47 ) ;
if ( ! V_18 )
return F_58 ( - V_180 ) ;
V_18 -> V_15 = V_15 ;
V_3 = & V_18 -> V_27 ;
V_3 -> V_51 = false ;
V_3 -> V_50 = false ;
F_60 ( V_5 , V_3 , V_158 , type ) ;
F_61 ( V_3 , & V_181 ) ;
if ( V_3 -> V_103 == V_104 ) {
bool V_182 , V_183 = false ;
V_93 = F_62 ( V_5 , 0 , & V_182 , & V_183 ) ;
if ( V_93 ) {
F_28 ( V_5 , L_10
L_11 ) ;
goto V_184;
}
V_18 -> V_113 = ! V_183 ;
}
if ( V_15 -> type == V_56 ) {
F_63 ( V_5 ) ;
F_64 ( V_3 , V_5 -> V_57 . V_58 , 0 ) ;
F_64 ( V_3 , V_5 -> V_57 . V_185 , 0 ) ;
}
switch ( V_15 -> type ) {
case V_164 :
if ( V_24 -> V_52 >= V_186 ) {
F_64 ( V_3 ,
V_5 -> V_57 . V_94 ,
V_18 -> V_105 ) ;
}
case V_166 :
case V_167 :
case V_168 :
V_18 -> V_105 = V_98 ;
break;
default:
V_18 -> V_105 = V_99 ;
F_64 ( V_3 ,
V_5 -> V_57 . V_94 ,
V_18 -> V_105 ) ;
F_64 ( V_3 ,
V_5 -> V_57 . V_111 ,
V_18 -> V_113 ?
V_112 : V_187 ) ;
break;
}
if ( V_18 -> V_15 -> V_32 != 0xff && V_26 -> V_188 ) {
V_26 -> V_188 ( V_5 , V_18 -> V_15 -> V_32 ,
V_33 , V_3 ) ;
V_3 -> V_189 = V_190 ;
} else {
V_3 -> V_189 = V_191 ;
}
F_65 ( V_3 ) ;
V_15 -> V_163 = V_3 ;
return V_15 -> V_163 ;
V_184:
F_12 ( V_3 ) ;
F_10 ( V_3 ) ;
return F_58 ( V_93 ) ;
}
static void
V_33 ( void * V_192 , int V_193 )
{
struct V_2 * V_3 = V_192 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_66 ( V_5 , L_12 , V_193 ? L_13 : L_14 ,
F_29 ( V_3 ) ) ;
if ( V_193 )
F_67 ( V_3 , V_194 ) ;
else
F_67 ( V_3 , V_195 ) ;
F_68 ( V_5 ) ;
}
