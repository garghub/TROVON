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
struct V_4 * V_5 ;
if ( ! V_18 )
return;
V_5 = V_18 -> V_21 . V_5 ;
V_20 = V_5 -> V_22 ;
F_8 ( V_5 , L_1 ) ;
if ( V_18 -> V_23 != V_24 ) {
F_9 ( V_5 , 0 , V_18 -> V_23 , 0xff ,
V_25 , V_3 ) ;
}
F_10 ( V_18 -> V_26 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
F_10 ( V_3 ) ;
}
static struct V_27 *
F_13 ( struct V_2 * V_3 ,
struct V_1 * * V_28 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_27 * V_29 = NULL ;
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
if ( V_6 -> V_15 -> V_30 < 0xf )
V_29 = F_14 ( V_5 , V_6 -> V_15 -> V_30 ) ;
if ( V_29 && F_15 ( V_29 , 0x50 ) ) {
* V_28 = V_6 ;
return V_29 ;
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
struct V_31 * V_32 , * V_33 = F_18 ( V_5 -> V_34 ) ;
if ( ! V_33 ||
! ( ( V_6 = F_1 ( V_3 , V_35 ) ) ||
( V_6 = F_1 ( V_3 , V_36 ) ) ) )
return NULL ;
F_19 (dn, cn) {
const char * V_37 = F_20 ( V_32 , L_2 , NULL ) ;
const void * V_26 = F_20 ( V_32 , L_3 , NULL ) ;
int V_38 = V_37 ? V_37 [ strlen ( V_37 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_30 == V_38 && V_26 ) {
V_18 -> V_26 =
F_21 ( V_26 , V_39 , V_40 ) ;
F_22 ( V_32 ) ;
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
struct V_19 * V_20 = V_3 -> V_5 -> V_22 ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_41 == V_6 )
return;
V_18 -> V_41 = V_6 ;
if ( V_20 -> V_42 >= V_43 ) {
V_3 -> V_44 = true ;
V_3 -> V_45 = true ;
} else
if ( V_6 -> V_15 -> type == V_46 ||
V_6 -> V_15 -> type == V_35 ) {
V_3 -> V_45 = false ;
V_3 -> V_44 = false ;
} else {
V_3 -> V_45 = true ;
if ( V_20 -> V_42 == V_47 ||
( V_20 -> V_42 == V_48 &&
( V_5 -> V_49 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_49 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_44 = false ;
else
V_3 -> V_44 = true ;
}
if ( V_18 -> type == V_50 ) {
F_24 ( V_3 ,
V_5 -> V_51 . V_52 ,
V_6 -> V_15 -> type == V_35 ?
V_53 :
V_54 ) ;
}
}
static enum V_55
F_25 ( struct V_2 * V_3 , bool V_56 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_57 ;
struct V_27 * V_29 ;
int type ;
if ( V_18 -> V_26 ) {
F_26 ( V_3 , NULL ) ;
F_10 ( V_18 -> V_26 ) ;
V_18 -> V_26 = NULL ;
}
V_29 = F_13 ( V_3 , & V_6 ) ;
if ( V_29 ) {
V_18 -> V_26 = F_27 ( V_3 , & V_29 -> V_58 ) ;
F_26 ( V_3 ,
V_18 -> V_26 ) ;
if ( ! V_18 -> V_26 ) {
F_28 ( V_5 , L_4 ,
F_29 ( V_3 ) ) ;
goto V_59;
}
if ( V_6 -> V_15 -> type == V_60 &&
! F_30 ( F_5 ( V_6 ) ) ) {
F_28 ( V_5 , L_5 ,
F_29 ( V_3 ) ) ;
return V_61 ;
}
V_57 = NULL ;
if ( V_6 -> V_15 -> type == V_35 )
V_57 = F_1 ( V_3 , V_36 ) ;
if ( V_6 -> V_15 -> type == V_36 )
V_57 = F_1 ( V_3 , V_35 ) ;
if ( V_57 && ( ( V_6 -> V_15 -> type == V_36 &&
V_57 -> V_15 -> type == V_35 ) ||
( V_6 -> V_15 -> type == V_35 &&
V_57 -> V_15 -> type == V_36 ) ) ) {
if ( V_18 -> V_26 -> V_62 & V_63 )
type = V_35 ;
else
type = V_36 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_23 ( V_3 , V_6 ) ;
return V_64 ;
}
V_6 = F_16 ( V_3 ) ;
if ( V_6 ) {
F_23 ( V_3 , V_6 ) ;
return V_64 ;
}
V_59:
V_6 = F_1 ( V_3 , V_36 ) ;
if ( ! V_6 && ! V_65 )
V_6 = F_1 ( V_3 , V_66 ) ;
if ( V_6 && V_56 ) {
struct V_67 * V_17 = F_5 ( V_6 ) ;
struct V_68 * V_69 =
V_17 -> V_70 ;
if ( V_69 -> V_71 ( V_17 , V_3 ) ==
V_64 ) {
F_23 ( V_3 , V_6 ) ;
return V_64 ;
}
}
return V_61 ;
}
static enum V_55
F_31 ( struct V_2 * V_3 , bool V_56 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_19 * V_20 = V_5 -> V_22 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_55 V_72 = V_61 ;
if ( V_18 -> V_26 ) {
F_26 ( V_3 , NULL ) ;
F_10 ( V_18 -> V_26 ) ;
V_18 -> V_26 = NULL ;
}
V_6 = F_1 ( V_3 , V_46 ) ;
if ( ! V_6 )
return V_61 ;
if ( ! V_20 -> V_73 . V_74 ) {
V_72 = F_25 ( V_3 , V_56 ) ;
if ( V_72 == V_64 )
goto V_75;
}
if ( V_6 -> V_15 -> V_76 . V_77 ) {
if ( ! F_32 ( V_5 , V_3 ) ) {
V_72 = V_64 ;
goto V_75;
}
}
if ( F_33 ( V_5 , NULL ) && ( V_20 -> V_73 . V_74 ||
V_6 -> V_15 -> V_76 . V_78 ) ) {
V_72 = V_64 ;
goto V_75;
}
if ( ! V_20 -> V_73 . V_74 ) {
struct V_26 * V_26 =
(struct V_26 * ) F_34 ( V_5 ) ;
if ( V_26 ) {
V_18 -> V_26 = F_35 ( V_39 , V_40 ) ;
* ( V_18 -> V_26 ) = * V_26 ;
V_72 = V_64 ;
}
}
V_75:
#if F_36 ( V_79 ) || \
( F_36 ( V_80 ) && F_36 ( V_81 ) )
if ( V_72 == V_64 &&
! V_82 && ! F_37 () )
V_72 = V_83 ;
#endif
F_26 ( V_3 , V_18 -> V_26 ) ;
F_23 ( V_3 , V_6 ) ;
return V_72 ;
}
static void
F_38 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_50 ) {
if ( V_3 -> V_56 == V_84 )
type = V_35 ;
else
type = V_36 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_28 ( V_3 -> V_5 , L_6 ,
F_29 ( V_3 ) ) ;
V_3 -> V_72 = V_61 ;
return;
}
F_23 ( V_3 , V_6 ) ;
}
static int
F_39 ( struct V_2 * V_3 ,
struct V_85 * V_86 , T_1 V_87 )
{
struct V_19 * V_20 = V_3 -> V_5 -> V_22 ;
struct V_88 * V_89 = & V_20 -> V_90 . V_91 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_41 ;
struct V_67 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_92 * V_93 ;
int V_94 ;
V_93 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_95 )
V_93 = V_92 ( V_3 -> V_17 -> V_95 ) ;
if ( V_86 == V_5 -> V_51 . V_96 ) {
bool V_97 = false ;
switch ( V_87 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
break;
default:
return - V_102 ;
}
if ( V_3 -> V_103 == V_104 &&
V_87 == V_98 )
return - V_102 ;
if ( ( V_18 -> V_105 == V_98 ) ||
( V_87 == V_98 ) )
V_97 = true ;
V_18 -> V_105 = V_87 ;
if ( ! V_93 )
return 0 ;
if ( V_97 || ! V_93 -> V_106 ) {
V_94 = F_40 ( & V_93 -> V_21 ,
& V_93 -> V_21 . V_107 ,
V_93 -> V_21 . V_108 ,
V_93 -> V_21 . V_109 , NULL ) ;
if ( ! V_94 )
return - V_102 ;
} else {
V_94 = V_93 -> V_106 ( V_93 , true ) ;
if ( V_94 )
return V_94 ;
}
return 0 ;
}
if ( V_86 == V_89 -> V_110 ) {
if ( V_18 -> V_111 != V_87 ) {
V_18 -> V_111 = V_87 ;
if ( ! V_93 || ! V_93 -> V_106 )
return 0 ;
return V_93 -> V_106 ( V_93 , true ) ;
}
return 0 ;
}
if ( V_86 == V_89 -> V_112 ) {
if ( V_18 -> V_113 != V_87 ) {
V_18 -> V_113 = V_87 ;
if ( ! V_93 || ! V_93 -> V_106 )
return 0 ;
return V_93 -> V_106 ( V_93 , true ) ;
}
return 0 ;
}
if ( V_86 == V_89 -> V_114 ) {
if ( V_18 -> V_115 != V_87 ) {
V_18 -> V_115 = V_87 ;
if ( ! V_93 || ! V_93 -> V_106 )
return 0 ;
return V_93 -> V_106 ( V_93 , true ) ;
}
return 0 ;
}
if ( V_86 == V_89 -> V_116 ) {
V_18 -> V_116 = V_87 ;
if ( ! V_93 || ! V_93 -> V_117 )
return 0 ;
return V_93 -> V_117 ( V_93 , true ) ;
}
if ( V_86 == V_89 -> V_118 ) {
V_18 -> V_118 = V_87 ;
if ( ! V_93 || ! V_93 -> V_117 )
return 0 ;
return V_93 -> V_117 ( V_93 , true ) ;
}
if ( V_93 && V_93 -> V_119 ) {
if ( V_86 == V_89 -> V_120 ) {
V_93 -> V_121 = V_87 - 90 ;
return V_93 -> V_119 ( V_93 , true ) ;
}
if ( V_86 == V_89 -> V_122 ) {
V_93 -> V_123 = V_87 - 100 ;
return V_93 -> V_119 ( V_93 , true ) ;
}
}
if ( V_6 && V_6 -> V_15 -> type == V_66 )
return F_41 ( V_17 ) -> F_42 (
V_17 , V_3 , V_86 , V_87 ) ;
return - V_102 ;
}
static struct V_124 *
F_43 ( struct V_2 * V_3 )
{
struct V_125 * V_69 = V_3 -> V_70 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_124 * V_107 , * V_126 = NULL ;
int V_127 = 0 , V_128 = 0 , V_129 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_107 -> V_130 = F_44 ( V_107 ) ;
if ( V_69 -> V_131 ( V_3 , V_107 ) != V_132 ||
( V_107 -> V_133 & V_134 ) )
continue;
if ( V_107 -> type & V_135 ) {
F_8 ( V_5 , L_7 ) ;
return F_45 ( V_5 , V_107 ) ;
}
if ( V_107 -> V_136 < V_127 )
continue;
if ( V_107 -> V_136 == V_127 && V_107 -> V_137 < V_128 )
continue;
if ( V_107 -> V_136 == V_127 && V_107 -> V_137 == V_128 &&
V_107 -> V_130 < V_129 )
continue;
V_127 = V_107 -> V_136 ;
V_128 = V_107 -> V_137 ;
V_129 = V_107 -> V_130 ;
V_126 = V_107 ;
}
F_8 ( V_5 , L_8 ,
V_127 , V_128 , V_129 ) ;
return V_126 ? F_45 ( V_5 , V_126 ) : NULL ;
}
static int
F_46 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_124 * V_138 = V_18 -> V_139 , * V_140 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_141 * V_107 = & V_142 [ 0 ] ;
int V_143 = 0 ;
if ( ! V_138 )
return 0 ;
while ( V_107 -> V_136 ) {
if ( V_107 -> V_136 <= V_138 -> V_136 &&
V_107 -> V_137 <= V_138 -> V_137 ) {
V_140 = F_47 ( V_5 , V_107 -> V_136 , V_107 -> V_137 ,
F_44 ( V_138 ) , false ,
false , false ) ;
if ( ! V_140 )
continue;
V_140 -> type |= V_144 ;
F_48 ( V_3 , V_140 ) ;
V_143 ++ ;
}
V_107 ++ ;
}
return V_143 ;
}
static void
F_49 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = V_3 -> V_5 -> V_22 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_41 ;
struct V_145 * V_146 = & V_20 -> V_73 ;
struct V_124 * V_107 = V_18 -> V_139 ;
bool V_147 ;
if ( V_18 -> V_26 && V_3 -> V_148 . V_149 )
return;
if ( V_6 -> V_15 -> type != V_46 ) {
V_3 -> V_148 . V_149 = 8 ;
return;
}
V_3 -> V_148 . V_149 = 6 ;
if ( V_146 -> V_74 ) {
if ( V_146 -> V_150 . V_151 )
V_3 -> V_148 . V_149 = 8 ;
return;
}
if ( V_18 -> V_26 &&
V_18 -> type == V_152 )
V_147 = ( ( V_153 * ) V_18 -> V_26 ) [ 121 ] == 2 ;
else
V_147 = V_107 -> clock >= V_146 -> V_150 . V_154 ;
if ( ( ! V_147 && ( V_146 -> V_150 . V_155 & 1 ) ) ||
( V_147 && ( V_146 -> V_150 . V_155 & 2 ) ) )
V_3 -> V_148 . V_149 = 8 ;
}
static int
F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_19 * V_20 = V_5 -> V_22 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_41 ;
struct V_67 * V_17 = F_5 ( V_6 ) ;
int V_94 = 0 ;
if ( V_18 -> V_139 ) {
F_51 ( V_5 , V_18 -> V_139 ) ;
V_18 -> V_139 = NULL ;
}
if ( V_18 -> V_26 )
V_94 = F_52 ( V_3 , V_18 -> V_26 ) ;
else
if ( V_6 -> V_15 -> type == V_46 &&
( V_6 -> V_15 -> V_76 . V_78 ||
V_20 -> V_73 . V_74 ) && F_33 ( V_5 , NULL ) ) {
struct V_124 V_107 ;
F_33 ( V_5 , & V_107 ) ;
V_18 -> V_139 = F_45 ( V_5 , & V_107 ) ;
}
if ( V_3 -> V_103 != V_104 )
F_49 ( V_3 ) ;
if ( ! V_18 -> V_139 )
V_18 -> V_139 =
F_43 ( V_3 ) ;
if ( V_94 == 0 && V_18 -> V_139 ) {
struct V_124 * V_107 ;
V_107 = F_45 ( V_5 , V_18 -> V_139 ) ;
F_48 ( V_3 , V_107 ) ;
V_94 = 1 ;
}
if ( V_3 -> V_103 == V_104 )
F_49 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_66 )
V_94 = F_41 ( V_17 ) -> F_53 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_156 ||
V_18 -> type == V_152 ||
V_18 -> type == V_157 )
V_94 += F_46 ( V_3 ) ;
return V_94 ;
}
static unsigned
F_54 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_19 * V_20 = V_3 -> V_5 -> V_22 ;
struct V_158 * V_15 = V_18 -> V_41 -> V_15 ;
if ( V_15 -> V_159 != V_160 ||
V_20 -> V_161 >= 0x46 )
return 165000 ;
else if ( V_20 -> V_161 >= 0x40 )
return 155000 ;
else if ( V_20 -> V_161 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_55 ( struct V_2 * V_3 ,
struct V_124 * V_107 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_41 ;
struct V_67 * V_17 = F_5 ( V_6 ) ;
unsigned V_162 = 25000 , V_163 = V_162 ;
unsigned clock = V_107 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_46 :
if ( V_18 -> V_139 &&
( V_107 -> V_136 > V_18 -> V_139 -> V_136 ||
V_107 -> V_137 > V_18 -> V_139 -> V_137 ) )
return V_164 ;
V_162 = 0 ;
V_163 = 400000 ;
break;
case V_35 :
V_163 = F_54 ( V_3 ) ;
if ( V_165 && V_6 -> V_15 -> V_166 )
V_163 *= 2 ;
break;
case V_36 :
V_163 = V_6 -> V_15 -> V_167 . V_168 ;
if ( ! V_163 )
V_163 = 350000 ;
break;
case V_66 :
return F_41 ( V_17 ) -> V_131 ( V_17 , V_107 ) ;
case V_60 :
V_163 = V_6 -> V_169 . V_170 ;
V_163 *= V_6 -> V_169 . V_171 ;
clock = clock * ( V_3 -> V_148 . V_149 * 3 ) / 10 ;
break;
default:
F_56 ( 1 ) ;
return V_172 ;
}
if ( clock < V_162 )
return V_173 ;
if ( clock > V_163 )
return V_174 ;
return V_132 ;
}
static struct V_67 *
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_41 )
return F_5 ( V_18 -> V_41 ) ;
return NULL ;
}
static int
F_58 ( enum V_175 V_15 )
{
switch ( V_15 ) {
case V_176 : return V_177 ;
case V_178 :
case V_179 :
case V_180 : return V_181 ;
case V_182 :
case V_183 :
case V_50 : return V_184 ;
case V_185 : return V_186 ;
case V_156 :
case V_152 : return V_104 ;
case V_187 :
case V_188 :
case V_189 : return V_190 ;
case V_157 : return V_191 ;
case V_192 :
case V_193 : return V_194 ;
default:
break;
}
return V_195 ;
}
struct V_2 *
F_59 ( struct V_4 * V_5 , int V_196 )
{
const struct V_197 * V_198 = & V_199 ;
struct V_19 * V_20 = V_5 -> V_22 ;
struct V_88 * V_89 = & V_20 -> V_90 . V_91 ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_94 = 0 ;
bool V_200 ;
F_8 ( V_5 , L_1 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_196 == V_196 )
return V_3 ;
}
V_18 = F_60 ( sizeof( * V_18 ) , V_40 ) ;
if ( ! V_18 )
return F_61 ( - V_201 ) ;
V_3 = & V_18 -> V_21 ;
V_18 -> V_196 = V_196 ;
V_18 -> V_15 = F_62 ( V_5 , V_196 ) ;
if ( V_18 -> V_15 ) {
static const V_153 V_23 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_202 = F_63 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_64 ( V_5 ) [ 3 ] >= 4 )
V_202 |= ( T_2 ) F_63 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_18 -> V_23 = F_65 ( ( V_202 & 0x07033000 ) >> 12 ) ;
V_18 -> V_23 = V_23 [ V_18 -> V_23 ] ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_58 ( V_18 -> type ) ==
V_195 ) {
F_66 ( V_5 , L_9 ,
V_18 -> type ) ;
V_18 -> type = V_203 ;
}
if ( F_67 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_193 )
V_18 -> type = V_50 ;
}
if ( F_67 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_193 )
V_18 -> type = V_50 ;
}
} else {
V_18 -> type = V_203 ;
V_18 -> V_23 = V_24 ;
}
if ( V_18 -> type == V_203 ) {
struct V_19 * V_20 = V_5 -> V_22 ;
struct V_204 * V_205 = & V_20 -> V_73 . V_15 ;
T_2 V_206 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_205 -> V_207 ; V_9 ++ ) {
if ( V_205 -> V_202 [ V_9 ] . V_3 == V_18 -> V_196 )
V_206 |= ( 1 << V_205 -> V_202 [ V_9 ] . type ) ;
}
if ( V_206 & ( 1 << V_60 ) ) {
if ( V_206 & ( 1 << V_35 ) )
V_18 -> type = V_189 ;
else
V_18 -> type = V_157 ;
} else
if ( V_206 & ( 1 << V_35 ) ) {
if ( V_206 & ( 1 << V_36 ) )
V_18 -> type = V_50 ;
else
V_18 -> type = V_185 ;
} else
if ( V_206 & ( 1 << V_36 ) ) {
V_18 -> type = V_176 ;
} else
if ( V_206 & ( 1 << V_46 ) ) {
V_18 -> type = V_156 ;
} else
if ( V_206 & ( 1 << V_66 ) ) {
V_18 -> type = V_178 ;
}
}
type = F_58 ( V_18 -> type ) ;
if ( type == V_104 ) {
V_94 = F_68 ( V_5 , 0 , & V_200 , & V_200 ) ;
if ( V_94 ) {
F_28 ( V_5 , L_10 ) ;
F_10 ( V_18 ) ;
return F_61 ( V_94 ) ;
}
V_198 = & V_208 ;
} else {
V_198 = & V_199 ;
}
V_3 -> V_44 = false ;
V_3 -> V_45 = false ;
F_69 ( V_5 , V_3 , V_198 , type ) ;
F_70 ( V_3 , & V_209 ) ;
if ( V_18 -> type == V_50 )
F_71 ( V_3 , V_5 -> V_51 . V_52 , 0 ) ;
if ( V_89 -> V_110 &&
( type == V_186 ||
type == V_184 ||
type == V_194 ||
type == V_190 ) ) {
F_71 ( V_3 ,
V_89 -> V_110 ,
V_210 ) ;
F_71 ( V_3 ,
V_89 -> V_112 ,
0 ) ;
F_71 ( V_3 ,
V_89 -> V_114 ,
0 ) ;
}
if ( V_89 -> V_120 )
F_71 ( V_3 ,
V_89 -> V_120 ,
90 ) ;
if ( V_89 -> V_122 )
F_71 ( V_3 ,
V_89 -> V_122 ,
150 ) ;
switch ( V_18 -> type ) {
case V_176 :
if ( V_20 -> V_42 >= V_43 ) {
F_71 ( V_3 ,
V_5 -> V_51 . V_96 ,
V_18 -> V_105 ) ;
}
case V_178 :
case V_179 :
case V_180 :
V_18 -> V_105 = V_98 ;
break;
default:
V_18 -> V_105 = V_99 ;
F_71 ( V_3 ,
V_5 -> V_51 . V_96 ,
V_18 -> V_105 ) ;
if ( V_89 -> V_116 ) {
V_18 -> V_116 = V_211 ;
F_71 ( V_3 ,
V_89 -> V_116 ,
V_18 -> V_116 ) ;
}
if ( V_89 -> V_118 ) {
V_18 -> V_118 = V_212 ;
F_71 ( V_3 ,
V_89 -> V_118 ,
V_18 -> V_118 ) ;
}
break;
}
V_3 -> V_213 = V_214 ;
if ( V_18 -> V_23 != V_24 ) {
V_94 = F_72 ( V_5 , 0 , V_18 -> V_23 , 0xff ,
V_25 ,
V_3 ) ;
if ( V_94 == 0 )
V_3 -> V_213 = V_215 ;
}
F_73 ( V_3 ) ;
return V_3 ;
}
static void
V_25 ( void * V_216 , int V_217 )
{
struct V_2 * V_3 = V_216 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_74 ( V_5 , L_11 , V_217 ? L_12 : L_13 ,
F_29 ( V_3 ) ) ;
if ( V_217 )
F_75 ( V_3 , V_218 ) ;
else
F_75 ( V_3 , V_219 ) ;
F_76 ( V_5 ) ;
}
