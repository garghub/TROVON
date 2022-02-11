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
if ( V_20 && V_18 -> V_25 != V_26 ) {
V_20 -> V_27 ( V_20 , 0 , V_18 -> V_25 , 0xff ,
V_28 , V_3 ) ;
}
F_8 ( V_18 -> V_29 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
F_8 ( V_3 ) ;
}
static struct V_30 *
F_11 ( struct V_2 * V_3 ,
struct V_1 * * V_31 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_19 * V_20 = V_19 ( V_22 -> V_24 ) ;
struct V_32 * V_33 = V_32 ( V_22 -> V_24 ) ;
struct V_30 * V_34 = NULL ;
int V_9 , V_35 = - V_36 ;
if ( V_18 -> type == V_37 ) {
V_35 = V_20 -> V_38 ( V_20 , 0 , V_39 , 0xff ) ;
if ( V_35 == 0 ) {
V_20 -> V_40 ( V_20 , 0 , V_39 , 0xff , 1 ) ;
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
if ( V_6 -> V_15 -> V_41 < 0xf )
V_34 = V_33 -> V_42 ( V_33 , V_6 -> V_15 -> V_41 ) ;
if ( V_34 && F_13 ( V_34 , 0x50 ) ) {
* V_31 = V_6 ;
break;
}
V_34 = NULL ;
}
if ( ! V_34 && V_35 == 0 )
V_20 -> V_40 ( V_20 , 0 , V_39 , 0xff , V_35 ) ;
return V_34 ;
}
static struct V_1 *
F_14 ( struct V_2 * V_3 )
{
#ifdef F_15
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_43 * V_44 , * V_45 = F_16 ( V_5 -> V_46 ) ;
if ( ! V_45 ||
! ( ( V_6 = F_1 ( V_3 , V_47 ) ) ||
( V_6 = F_1 ( V_3 , V_48 ) ) ) )
return NULL ;
F_17 (dn, cn) {
const char * V_49 = F_18 ( V_44 , L_1 , NULL ) ;
const void * V_29 = F_18 ( V_44 , L_2 , NULL ) ;
int V_50 = V_49 ? V_49 [ strlen ( V_49 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_41 == V_50 && V_29 ) {
V_18 -> V_29 =
F_19 ( V_29 , V_51 , V_52 ) ;
F_20 ( V_44 ) ;
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
if ( V_18 -> V_53 == V_6 )
return;
V_18 -> V_53 = V_6 ;
if ( F_22 ( V_22 -> V_24 ) -> V_54 >= V_55 ) {
V_3 -> V_56 = true ;
V_3 -> V_57 = true ;
} else
if ( V_6 -> V_15 -> type == V_58 ||
V_6 -> V_15 -> type == V_47 ) {
V_3 -> V_57 = false ;
V_3 -> V_56 = false ;
} else {
V_3 -> V_57 = true ;
if ( F_22 ( V_22 -> V_24 ) -> V_54 == V_59 ||
( F_22 ( V_22 -> V_24 ) -> V_54 == V_60 &&
( V_5 -> V_61 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_61 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_56 = false ;
else
V_3 -> V_56 = true ;
}
if ( V_18 -> type == V_62 ) {
F_23 ( & V_3 -> V_23 ,
V_5 -> V_63 . V_64 ,
V_6 -> V_15 -> type == V_47 ?
V_65 :
V_66 ) ;
}
}
static enum V_67
F_24 ( struct V_2 * V_3 , bool V_68 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_69 ;
struct V_30 * V_33 ;
int type ;
if ( V_18 -> V_29 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_29 ) ;
V_18 -> V_29 = NULL ;
}
V_33 = F_11 ( V_3 , & V_6 ) ;
if ( V_33 ) {
V_18 -> V_29 = F_26 ( V_3 , & V_33 -> V_70 ) ;
F_25 ( V_3 ,
V_18 -> V_29 ) ;
if ( ! V_18 -> V_29 ) {
F_27 ( V_22 , L_3 ,
F_28 ( V_3 ) ) ;
goto V_71;
}
if ( V_6 -> V_15 -> type == V_72 &&
! F_29 ( F_5 ( V_6 ) ) ) {
F_27 ( V_22 , L_4 ,
F_28 ( V_3 ) ) ;
return V_73 ;
}
V_69 = NULL ;
if ( V_6 -> V_15 -> type == V_47 )
V_69 = F_1 ( V_3 , V_48 ) ;
if ( V_6 -> V_15 -> type == V_48 )
V_69 = F_1 ( V_3 , V_47 ) ;
if ( V_69 && ( ( V_6 -> V_15 -> type == V_48 &&
V_69 -> V_15 -> type == V_47 ) ||
( V_6 -> V_15 -> type == V_47 &&
V_69 -> V_15 -> type == V_48 ) ) ) {
if ( V_18 -> V_29 -> V_74 & V_75 )
type = V_47 ;
else
type = V_48 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_21 ( V_3 , V_6 ) ;
return V_76 ;
}
V_6 = F_14 ( V_3 ) ;
if ( V_6 ) {
F_21 ( V_3 , V_6 ) ;
return V_76 ;
}
V_71:
V_6 = F_1 ( V_3 , V_48 ) ;
if ( ! V_6 && ! V_77 )
V_6 = F_1 ( V_3 , V_78 ) ;
if ( V_6 && V_68 ) {
struct V_79 * V_17 = F_5 ( V_6 ) ;
struct V_80 * V_81 =
V_17 -> V_82 ;
if ( V_81 -> V_83 ( V_17 , V_3 ) ==
V_76 ) {
F_21 ( V_3 , V_6 ) ;
return V_76 ;
}
}
return V_73 ;
}
static enum V_67
F_30 ( struct V_2 * V_3 , bool V_68 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_67 V_84 = V_73 ;
if ( V_18 -> V_29 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_29 ) ;
V_18 -> V_29 = NULL ;
}
V_6 = F_1 ( V_3 , V_58 ) ;
if ( ! V_6 )
return V_73 ;
if ( ! V_22 -> V_85 . V_86 ) {
V_84 = F_24 ( V_3 , V_68 ) ;
if ( V_84 == V_76 )
goto V_87;
}
if ( V_6 -> V_15 -> V_88 . V_89 ) {
if ( ( V_18 -> V_29 = F_31 ( V_5 , V_3 ) ) ) {
V_84 = V_76 ;
goto V_87;
}
}
if ( F_32 ( V_5 , NULL ) && ( V_22 -> V_85 . V_86 ||
V_6 -> V_15 -> V_88 . V_90 ) ) {
V_84 = V_76 ;
goto V_87;
}
if ( ! V_22 -> V_85 . V_86 ) {
struct V_29 * V_29 =
(struct V_29 * ) F_33 ( V_5 ) ;
if ( V_29 ) {
V_18 -> V_29 = F_34 ( V_51 , V_52 ) ;
* ( V_18 -> V_29 ) = * V_29 ;
V_84 = V_76 ;
}
}
V_87:
#if F_35 ( V_91 ) || \
( F_35 ( V_92 ) && F_35 ( V_93 ) )
if ( V_84 == V_76 &&
! V_94 && ! F_36 () )
V_84 = V_95 ;
#endif
F_25 ( V_3 , V_18 -> V_29 ) ;
F_21 ( V_3 , V_6 ) ;
return V_84 ;
}
static void
F_37 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_62 ) {
if ( V_3 -> V_68 == V_96 )
type = V_47 ;
else
type = V_48 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_27 ( V_22 , L_5 ,
F_28 ( V_3 ) ) ;
V_3 -> V_84 = V_73 ;
return;
}
F_21 ( V_3 , V_6 ) ;
}
static int
F_38 ( struct V_2 * V_3 ,
struct V_97 * V_98 , T_1 V_99 )
{
struct V_100 * V_101 = V_100 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_53 ;
struct V_79 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_102 * V_103 ;
int V_104 ;
V_103 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_105 )
V_103 = V_102 ( V_3 -> V_17 -> V_105 ) ;
if ( V_98 == V_5 -> V_63 . V_106 ) {
bool V_107 = false ;
switch ( V_99 ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
break;
default:
return - V_112 ;
}
if ( V_3 -> V_113 == V_114 &&
V_99 == V_108 )
return - V_112 ;
if ( ( V_18 -> V_115 == V_108 ) ||
( V_99 == V_108 ) )
V_107 = true ;
V_18 -> V_115 = V_99 ;
if ( ! V_103 )
return 0 ;
if ( V_107 || ! V_103 -> V_116 ) {
V_104 = F_39 ( & V_103 -> V_23 ,
& V_103 -> V_23 . V_117 ,
V_103 -> V_23 . V_118 ,
V_103 -> V_23 . V_119 , NULL ) ;
if ( ! V_104 )
return - V_112 ;
} else {
V_104 = V_103 -> V_116 ( V_103 , true ) ;
if ( V_104 )
return V_104 ;
}
return 0 ;
}
if ( V_98 == V_101 -> V_120 ) {
if ( V_18 -> V_121 != V_99 ) {
V_18 -> V_121 = V_99 ;
if ( ! V_103 || ! V_103 -> V_116 )
return 0 ;
return V_103 -> V_116 ( V_103 , true ) ;
}
return 0 ;
}
if ( V_98 == V_101 -> V_122 ) {
if ( V_18 -> V_123 != V_99 ) {
V_18 -> V_123 = V_99 ;
if ( ! V_103 || ! V_103 -> V_116 )
return 0 ;
return V_103 -> V_116 ( V_103 , true ) ;
}
return 0 ;
}
if ( V_98 == V_101 -> V_124 ) {
if ( V_18 -> V_125 != V_99 ) {
V_18 -> V_125 = V_99 ;
if ( ! V_103 || ! V_103 -> V_116 )
return 0 ;
return V_103 -> V_116 ( V_103 , true ) ;
}
return 0 ;
}
if ( V_98 == V_101 -> V_126 ) {
V_18 -> V_126 = V_99 ;
if ( ! V_103 || ! V_103 -> V_127 )
return 0 ;
return V_103 -> V_127 ( V_103 , true ) ;
}
if ( V_98 == V_101 -> V_128 ) {
V_18 -> V_128 = V_99 ;
if ( ! V_103 || ! V_103 -> V_127 )
return 0 ;
return V_103 -> V_127 ( V_103 , true ) ;
}
if ( V_103 && V_103 -> V_129 ) {
if ( V_98 == V_101 -> V_130 ) {
V_103 -> V_131 = V_99 - 90 ;
return V_103 -> V_129 ( V_103 , true ) ;
}
if ( V_98 == V_101 -> V_132 ) {
V_103 -> V_133 = V_99 - 100 ;
return V_103 -> V_129 ( V_103 , true ) ;
}
}
if ( V_6 && V_6 -> V_15 -> type == V_78 )
return F_40 ( V_17 ) -> F_41 (
V_17 , V_3 , V_98 , V_99 ) ;
return - V_112 ;
}
static struct V_134 *
F_42 ( struct V_2 * V_3 )
{
struct V_135 * V_81 = V_3 -> V_82 ;
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_134 * V_117 , * V_136 = NULL ;
int V_137 = 0 , V_138 = 0 , V_139 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_117 -> V_140 = F_43 ( V_117 ) ;
if ( V_81 -> V_141 ( V_3 , V_117 ) != V_142 ||
( V_117 -> V_143 & V_144 ) )
continue;
if ( V_117 -> type & V_145 ) {
F_44 ( V_22 , L_6 ) ;
return F_45 ( V_5 , V_117 ) ;
}
if ( V_117 -> V_146 < V_137 )
continue;
if ( V_117 -> V_146 == V_137 && V_117 -> V_147 < V_138 )
continue;
if ( V_117 -> V_146 == V_137 && V_117 -> V_147 == V_138 &&
V_117 -> V_140 < V_139 )
continue;
V_137 = V_117 -> V_146 ;
V_138 = V_117 -> V_147 ;
V_139 = V_117 -> V_140 ;
V_136 = V_117 ;
}
F_44 ( V_22 , L_7 ,
V_137 , V_138 , V_139 ) ;
return V_136 ? F_45 ( V_5 , V_136 ) : NULL ;
}
static int
F_46 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_134 * V_148 = V_18 -> V_149 , * V_150 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_151 * V_117 = & V_152 [ 0 ] ;
int V_153 = 0 ;
if ( ! V_148 )
return 0 ;
while ( V_117 -> V_146 ) {
if ( V_117 -> V_146 <= V_148 -> V_146 &&
V_117 -> V_147 <= V_148 -> V_147 ) {
V_150 = F_47 ( V_5 , V_117 -> V_146 , V_117 -> V_147 ,
F_43 ( V_148 ) , false ,
false , false ) ;
if ( ! V_150 )
continue;
V_150 -> type |= V_154 ;
F_48 ( V_3 , V_150 ) ;
V_153 ++ ;
}
V_117 ++ ;
}
return V_153 ;
}
static void
F_49 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_53 ;
struct V_155 * V_156 = & V_22 -> V_85 ;
struct V_134 * V_117 = V_18 -> V_149 ;
bool V_157 ;
if ( V_18 -> V_29 && V_3 -> V_158 . V_159 )
return;
if ( V_18 -> type == V_37 ) {
V_3 -> V_158 . V_159 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_58 ) {
V_3 -> V_158 . V_159 = 8 ;
return;
}
V_3 -> V_158 . V_159 = 6 ;
if ( V_156 -> V_86 ) {
if ( V_156 -> V_160 . V_161 )
V_3 -> V_158 . V_159 = 8 ;
return;
}
if ( V_18 -> V_29 &&
V_18 -> type == V_162 )
V_157 = ( ( V_163 * ) V_18 -> V_29 ) [ 121 ] == 2 ;
else
V_157 = V_117 -> clock >= V_156 -> V_160 . V_164 ;
if ( ( ! V_157 && ( V_156 -> V_160 . V_165 & 1 ) ) ||
( V_157 && ( V_156 -> V_160 . V_165 & 2 ) ) )
V_3 -> V_158 . V_159 = 8 ;
}
static int
F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_53 ;
struct V_79 * V_17 = F_5 ( V_6 ) ;
int V_104 = 0 ;
if ( V_18 -> V_149 ) {
F_51 ( V_5 , V_18 -> V_149 ) ;
V_18 -> V_149 = NULL ;
}
if ( V_18 -> V_29 )
V_104 = F_52 ( V_3 , V_18 -> V_29 ) ;
else
if ( V_6 -> V_15 -> type == V_58 &&
( V_6 -> V_15 -> V_88 . V_90 ||
V_22 -> V_85 . V_86 ) && F_32 ( V_5 , NULL ) ) {
struct V_134 V_117 ;
F_32 ( V_5 , & V_117 ) ;
V_18 -> V_149 = F_45 ( V_5 , & V_117 ) ;
}
if ( V_3 -> V_113 != V_114 )
F_49 ( V_3 ) ;
if ( ! V_18 -> V_149 )
V_18 -> V_149 =
F_42 ( V_3 ) ;
if ( V_104 == 0 && V_18 -> V_149 ) {
struct V_134 * V_117 ;
V_117 = F_45 ( V_5 , V_18 -> V_149 ) ;
F_48 ( V_3 , V_117 ) ;
V_104 = 1 ;
}
if ( V_3 -> V_113 == V_114 )
F_49 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_78 )
V_104 = F_40 ( V_17 ) -> F_53 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_166 ||
V_18 -> type == V_162 ||
V_18 -> type == V_37 )
V_104 += F_46 ( V_3 ) ;
return V_104 ;
}
static unsigned
F_54 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_21 * V_22 = V_21 ( V_3 -> V_5 ) ;
struct V_167 * V_15 = V_18 -> V_53 -> V_15 ;
if ( V_15 -> V_168 != V_169 ||
F_22 ( V_22 -> V_24 ) -> V_170 >= 0x46 )
return 165000 ;
else if ( F_22 ( V_22 -> V_24 ) -> V_170 >= 0x40 )
return 155000 ;
else if ( F_22 ( V_22 -> V_24 ) -> V_170 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_55 ( struct V_2 * V_3 ,
struct V_134 * V_117 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_53 ;
struct V_79 * V_17 = F_5 ( V_6 ) ;
unsigned V_171 = 25000 , V_172 = V_171 ;
unsigned clock = V_117 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_58 :
if ( V_18 -> V_149 &&
( V_117 -> V_146 > V_18 -> V_149 -> V_146 ||
V_117 -> V_147 > V_18 -> V_149 -> V_147 ) )
return V_173 ;
V_171 = 0 ;
V_172 = 400000 ;
break;
case V_47 :
V_172 = F_54 ( V_3 ) ;
if ( V_174 && V_6 -> V_15 -> V_175 )
V_172 *= 2 ;
break;
case V_48 :
V_172 = V_6 -> V_15 -> V_176 . V_177 ;
if ( ! V_172 )
V_172 = 350000 ;
break;
case V_78 :
return F_40 ( V_17 ) -> V_141 ( V_17 , V_117 ) ;
case V_72 :
V_172 = V_6 -> V_178 . V_179 ;
V_172 *= V_6 -> V_178 . V_180 ;
clock = clock * ( V_3 -> V_158 . V_159 * 3 ) / 10 ;
break;
default:
F_56 ( 1 ) ;
return V_181 ;
}
if ( clock < V_171 )
return V_182 ;
if ( clock > V_172 )
return V_183 ;
return V_142 ;
}
static struct V_79 *
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_53 )
return F_5 ( V_18 -> V_53 ) ;
return NULL ;
}
static int
F_58 ( enum V_184 V_15 )
{
switch ( V_15 ) {
case V_185 : return V_186 ;
case V_187 :
case V_188 :
case V_189 : return V_190 ;
case V_191 :
case V_192 :
case V_62 : return V_193 ;
case V_194 : return V_195 ;
case V_166 :
case V_162 : return V_114 ;
case V_196 :
case V_197 :
case V_198 : return V_199 ;
case V_37 : return V_200 ;
case V_201 :
case V_202 : return V_203 ;
default:
break;
}
return V_204 ;
}
struct V_2 *
F_59 ( struct V_4 * V_5 , int V_205 )
{
const struct V_206 * V_207 = & V_208 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_19 * V_20 = V_19 ( V_22 -> V_24 ) ;
struct V_100 * V_101 = V_100 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_104 = 0 ;
bool V_209 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_205 == V_205 )
return V_3 ;
}
V_18 = F_60 ( sizeof( * V_18 ) , V_52 ) ;
if ( ! V_18 )
return F_61 ( - V_210 ) ;
V_3 = & V_18 -> V_23 ;
V_18 -> V_205 = V_205 ;
V_18 -> V_15 = F_62 ( V_5 , V_205 ) ;
if ( V_18 -> V_15 ) {
static const V_163 V_25 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_211 = F_63 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_64 ( V_5 ) [ 3 ] >= 4 )
V_211 |= ( T_2 ) F_63 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_18 -> V_25 = F_65 ( ( V_211 & 0x07033000 ) >> 12 ) ;
V_18 -> V_25 = V_25 [ V_18 -> V_25 ] ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_58 ( V_18 -> type ) ==
V_204 ) {
F_66 ( V_22 , L_8 ,
V_18 -> type ) ;
V_18 -> type = V_212 ;
}
if ( F_67 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_202 )
V_18 -> type = V_62 ;
}
if ( F_67 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_202 )
V_18 -> type = V_62 ;
}
} else {
V_18 -> type = V_212 ;
V_18 -> V_25 = V_26 ;
}
if ( V_18 -> type == V_212 ) {
struct V_21 * V_22 = V_21 ( V_5 ) ;
struct V_213 * V_214 = & V_22 -> V_85 . V_15 ;
T_2 V_215 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_214 -> V_216 ; V_9 ++ ) {
if ( V_214 -> V_211 [ V_9 ] . V_3 == V_18 -> V_205 )
V_215 |= ( 1 << V_214 -> V_211 [ V_9 ] . type ) ;
}
if ( V_215 & ( 1 << V_72 ) ) {
if ( V_215 & ( 1 << V_47 ) )
V_18 -> type = V_198 ;
else
V_18 -> type = V_37 ;
} else
if ( V_215 & ( 1 << V_47 ) ) {
if ( V_215 & ( 1 << V_48 ) )
V_18 -> type = V_62 ;
else
V_18 -> type = V_194 ;
} else
if ( V_215 & ( 1 << V_48 ) ) {
V_18 -> type = V_185 ;
} else
if ( V_215 & ( 1 << V_58 ) ) {
V_18 -> type = V_166 ;
} else
if ( V_215 & ( 1 << V_78 ) ) {
V_18 -> type = V_187 ;
}
}
type = F_58 ( V_18 -> type ) ;
if ( type == V_114 ) {
V_104 = F_68 ( V_5 , 0 , & V_209 , & V_209 ) ;
if ( V_104 ) {
F_27 ( V_22 , L_9 ) ;
F_8 ( V_18 ) ;
return F_61 ( V_104 ) ;
}
V_207 = & V_217 ;
} else {
V_207 = & V_208 ;
}
V_3 -> V_56 = false ;
V_3 -> V_57 = false ;
F_69 ( V_5 , V_3 , V_207 , type ) ;
F_70 ( V_3 , & V_218 ) ;
if ( V_18 -> type == V_62 )
F_71 ( & V_3 -> V_23 , V_5 -> V_63 . V_64 , 0 ) ;
if ( V_101 -> V_120 &&
( type == V_195 ||
type == V_193 ||
type == V_203 ||
type == V_199 ) ) {
F_71 ( & V_3 -> V_23 ,
V_101 -> V_120 ,
V_219 ) ;
F_71 ( & V_3 -> V_23 ,
V_101 -> V_122 ,
0 ) ;
F_71 ( & V_3 -> V_23 ,
V_101 -> V_124 ,
0 ) ;
}
if ( V_101 -> V_130 )
F_71 ( & V_3 -> V_23 ,
V_101 -> V_130 ,
90 ) ;
if ( V_101 -> V_132 )
F_71 ( & V_3 -> V_23 ,
V_101 -> V_132 ,
150 ) ;
switch ( V_18 -> type ) {
case V_185 :
if ( F_22 ( V_22 -> V_24 ) -> V_54 >= V_55 ) {
F_71 ( & V_3 -> V_23 ,
V_5 -> V_63 . V_106 ,
V_18 -> V_115 ) ;
}
case V_187 :
case V_188 :
case V_189 :
V_18 -> V_115 = V_108 ;
break;
default:
V_18 -> V_115 = V_109 ;
F_71 ( & V_3 -> V_23 ,
V_5 -> V_63 . V_106 ,
V_18 -> V_115 ) ;
if ( V_101 -> V_126 ) {
V_18 -> V_126 = V_220 ;
F_71 ( & V_3 -> V_23 ,
V_101 -> V_126 ,
V_18 -> V_126 ) ;
}
if ( V_101 -> V_128 ) {
V_18 -> V_128 = V_221 ;
F_71 ( & V_3 -> V_23 ,
V_101 -> V_128 ,
V_18 -> V_128 ) ;
}
break;
}
V_3 -> V_222 = V_223 ;
if ( V_20 && V_18 -> V_25 != V_26 ) {
V_104 = V_20 -> V_224 ( V_20 , 0 , V_18 -> V_25 , 0xff ,
V_28 , V_3 ) ;
if ( V_104 == 0 )
V_3 -> V_222 = V_225 ;
}
F_72 ( V_3 ) ;
return V_3 ;
}
static void
V_28 ( void * V_226 , int V_227 )
{
struct V_2 * V_3 = V_226 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_21 * V_22 = V_21 ( V_5 ) ;
F_44 ( V_22 , L_10 , V_227 ? L_11 : L_12 ,
F_28 ( V_3 ) ) ;
if ( V_227 )
F_73 ( V_3 , V_228 ) ;
else
F_73 ( V_3 , V_229 ) ;
F_74 ( V_5 ) ;
}
