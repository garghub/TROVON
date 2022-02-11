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
V_8 = F_2 ( V_5 , V_10 ) ;
if ( ! V_8 )
continue;
V_6 = V_1 ( V_8 ) ;
if ( type == V_13 ||
( V_6 -> V_14 && V_6 -> V_14 -> type == type ) )
return V_6 ;
}
return NULL ;
}
struct V_15 *
F_3 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = F_4 ( V_16 ) -> V_5 ;
struct V_2 * V_2 ;
F_5 (drm_connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_16 == F_4 ( V_16 ) )
return V_15 ( V_2 ) ;
}
return NULL ;
}
static void
F_6 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
F_7 ( & V_17 -> V_18 ) ;
F_8 ( V_17 -> V_19 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_17 -> V_20 . V_21 )
F_11 ( & V_17 -> V_20 ) ;
F_8 ( V_3 ) ;
}
static struct V_1 *
F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = F_13 ( & V_23 -> V_26 ) ;
struct V_1 * V_6 ;
struct V_7 * V_16 ;
int V_9 , V_27 = - V_28 ;
if ( V_17 -> type == V_29 ) {
V_27 = V_25 -> V_30 ( V_25 , 0 , V_31 , 0xff ) ;
if ( V_27 == 0 ) {
V_25 -> V_32 ( V_25 , 0 , V_31 , 0xff , 1 ) ;
F_14 ( 300 ) ;
}
}
for ( V_9 = 0 ; V_6 = NULL , V_9 < V_11 ; V_9 ++ ) {
int V_10 = V_3 -> V_12 [ V_9 ] ;
if ( V_10 == 0 )
break;
V_16 = F_2 ( V_5 , V_10 ) ;
if ( ! V_16 )
continue;
V_6 = V_1 ( V_16 ) ;
if ( V_6 -> V_14 -> type == V_33 ) {
int V_34 = F_15 ( V_6 ) ;
if ( V_34 == 0 )
break;
} else
if ( V_6 -> V_35 ) {
if ( F_16 ( V_6 -> V_35 , 0x50 ) )
break;
}
}
if ( ! V_6 && V_27 == 0 )
V_25 -> V_32 ( V_25 , 0 , V_31 , 0xff , V_27 ) ;
return V_6 ;
}
static struct V_1 *
F_17 ( struct V_2 * V_3 )
{
#ifdef F_18
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_36 * V_37 , * V_38 = F_19 ( V_5 -> V_39 ) ;
if ( ! V_38 ||
! ( ( V_6 = F_1 ( V_3 , V_40 ) ) ||
( V_6 = F_1 ( V_3 , V_41 ) ) ) )
return NULL ;
F_20 (dn, cn) {
const char * V_42 = F_21 ( V_37 , L_1 , NULL ) ;
const void * V_19 = F_21 ( V_37 , L_2 , NULL ) ;
int V_43 = V_42 ? V_42 [ strlen ( V_42 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_14 -> V_44 == V_43 && V_19 ) {
V_17 -> V_19 =
F_22 ( V_19 , V_45 , V_46 ) ;
F_23 ( V_37 ) ;
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
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_17 -> V_47 == V_6 )
return;
V_17 -> V_47 = V_6 ;
if ( V_23 -> V_26 . V_48 . V_49 >= V_50 ) {
V_3 -> V_51 = true ;
V_3 -> V_52 = true ;
} else
if ( V_6 -> V_14 -> type == V_53 ||
V_6 -> V_14 -> type == V_40 ) {
V_3 -> V_52 = false ;
V_3 -> V_51 = false ;
} else {
V_3 -> V_52 = true ;
if ( V_23 -> V_26 . V_48 . V_49 == V_54 ||
( V_23 -> V_26 . V_48 . V_49 == V_55 &&
( V_5 -> V_39 -> V_26 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_39 -> V_26 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_51 = false ;
else
V_3 -> V_51 = true ;
}
if ( V_17 -> type == V_56 ) {
F_25 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_59 ,
V_6 -> V_14 -> type == V_40 ?
V_60 :
V_61 ) ;
}
}
static enum V_62
F_26 ( struct V_2 * V_3 , bool V_63 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_64 ;
struct V_65 * V_35 ;
int type ;
int V_34 ;
enum V_62 V_66 = V_67 ;
if ( V_17 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_34 = F_28 ( V_3 -> V_5 -> V_5 ) ;
if ( V_34 < 0 && V_34 != - V_68 )
return V_66 ;
V_6 = F_12 ( V_3 ) ;
if ( V_6 && ( V_35 = V_6 -> V_35 ) != NULL ) {
V_17 -> V_19 = F_29 ( V_3 , & V_35 -> V_69 ) ;
F_27 ( V_3 ,
V_17 -> V_19 ) ;
if ( ! V_17 -> V_19 ) {
F_30 ( V_23 , L_3 ,
V_3 -> V_42 ) ;
goto V_70;
}
V_64 = NULL ;
if ( V_6 -> V_14 -> type == V_40 )
V_64 = F_1 ( V_3 , V_41 ) ;
if ( V_6 -> V_14 -> type == V_41 )
V_64 = F_1 ( V_3 , V_40 ) ;
if ( V_64 && ( ( V_6 -> V_14 -> type == V_41 &&
V_64 -> V_14 -> type == V_40 ) ||
( V_6 -> V_14 -> type == V_40 &&
V_64 -> V_14 -> type == V_41 ) ) ) {
if ( V_17 -> V_19 -> V_71 & V_72 )
type = V_40 ;
else
type = V_41 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_24 ( V_3 , V_6 ) ;
V_66 = V_73 ;
goto V_74;
}
V_6 = F_17 ( V_3 ) ;
if ( V_6 ) {
F_24 ( V_3 , V_6 ) ;
V_66 = V_73 ;
goto V_74;
}
V_70:
V_6 = F_1 ( V_3 , V_41 ) ;
if ( ! V_6 && ! V_75 )
V_6 = F_1 ( V_3 , V_76 ) ;
if ( V_6 && V_63 ) {
struct V_7 * V_16 = F_4 ( V_6 ) ;
struct V_77 * V_78 =
V_16 -> V_79 ;
if ( V_78 -> V_80 ( V_16 , V_3 ) ==
V_73 ) {
F_24 ( V_3 , V_6 ) ;
V_66 = V_73 ;
goto V_74;
}
}
V_74:
F_31 ( V_3 -> V_5 -> V_5 ) ;
F_32 ( V_3 -> V_5 -> V_5 ) ;
return V_66 ;
}
static enum V_62
F_33 ( struct V_2 * V_3 , bool V_63 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_62 V_81 = V_67 ;
if ( V_17 -> V_19 ) {
F_27 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_53 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_23 -> V_82 . V_83 ) {
V_81 = F_26 ( V_3 , V_63 ) ;
if ( V_81 == V_73 )
goto V_74;
}
if ( V_6 -> V_14 -> V_84 . V_85 ) {
if ( ( V_17 -> V_19 = F_34 ( V_5 , V_3 ) ) ) {
V_81 = V_73 ;
goto V_74;
}
}
if ( F_35 ( V_5 , NULL ) && ( V_23 -> V_82 . V_83 ||
V_6 -> V_14 -> V_84 . V_86 ) ) {
V_81 = V_73 ;
goto V_74;
}
if ( ! V_23 -> V_82 . V_83 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_36 ( V_5 ) ;
if ( V_19 ) {
V_17 -> V_19 =
F_22 ( V_19 , V_45 , V_46 ) ;
if ( V_17 -> V_19 )
V_81 = V_73 ;
}
}
V_74:
#if F_37 ( V_87 ) || \
( F_37 ( V_88 ) && F_37 ( V_89 ) )
if ( V_81 == V_73 &&
! V_90 && ! F_38 () )
V_81 = V_91 ;
#endif
F_27 ( V_3 , V_17 -> V_19 ) ;
F_24 ( V_3 , V_6 ) ;
return V_81 ;
}
static void
F_39 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_17 -> type == V_56 ) {
if ( V_3 -> V_63 == V_92 )
type = V_40 ;
else
type = V_41 ;
} else
type = V_13 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_30 ( V_23 , L_4 ,
V_3 -> V_42 ) ;
V_3 -> V_81 = V_67 ;
return;
}
F_24 ( V_3 , V_6 ) ;
}
static int
F_40 ( struct V_2 * V_3 ,
struct V_93 * V_94 , T_1 V_95 )
{
struct V_96 * V_97 = V_96 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_98 * V_99 ;
int V_34 ;
V_99 = NULL ;
if ( V_3 -> V_16 && V_3 -> V_16 -> V_100 )
V_99 = V_98 ( V_3 -> V_16 -> V_100 ) ;
if ( V_94 == V_5 -> V_58 . V_101 ) {
bool V_102 = false ;
switch ( V_95 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
break;
default:
return - V_107 ;
}
if ( V_3 -> V_108 == V_109 &&
V_95 == V_103 )
return - V_107 ;
if ( ( V_17 -> V_110 == V_103 ) ||
( V_95 == V_103 ) )
V_102 = true ;
V_17 -> V_110 = V_95 ;
if ( ! V_99 )
return 0 ;
if ( V_102 || ! V_99 -> V_111 ) {
V_34 = F_41 ( & V_99 -> V_57 ,
& V_99 -> V_57 . V_112 ,
V_99 -> V_57 . V_113 ,
V_99 -> V_57 . V_114 , NULL ) ;
if ( ! V_34 )
return - V_107 ;
} else {
V_34 = V_99 -> V_111 ( V_99 , true ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_115 ) {
if ( V_17 -> V_116 != V_95 ) {
V_17 -> V_116 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_117 ) {
if ( V_17 -> V_118 != V_95 ) {
V_17 -> V_118 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_119 ) {
if ( V_17 -> V_120 != V_95 ) {
V_17 -> V_120 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_121 ) {
V_17 -> V_121 = V_95 ;
if ( ! V_99 || ! V_99 -> V_122 )
return 0 ;
return V_99 -> V_122 ( V_99 , true ) ;
}
if ( V_94 == V_97 -> V_123 ) {
V_17 -> V_123 = V_95 ;
if ( ! V_99 || ! V_99 -> V_122 )
return 0 ;
return V_99 -> V_122 ( V_99 , true ) ;
}
if ( V_99 && V_99 -> V_124 ) {
if ( V_94 == V_97 -> V_125 ) {
V_99 -> V_126 = V_95 - 90 ;
return V_99 -> V_124 ( V_99 , true ) ;
}
if ( V_94 == V_97 -> V_127 ) {
V_99 -> V_128 = V_95 - 100 ;
return V_99 -> V_124 ( V_99 , true ) ;
}
}
if ( V_6 && V_6 -> V_14 -> type == V_76 )
return F_42 ( V_16 ) -> F_43 (
V_16 , V_3 , V_94 , V_95 ) ;
return - V_107 ;
}
static struct V_129 *
F_44 ( struct V_2 * V_3 )
{
struct V_130 * V_78 = V_3 -> V_79 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_129 * V_112 , * V_131 = NULL ;
int V_132 = 0 , V_133 = 0 , V_134 = 0 ;
F_5 (mode, &nv_connector->base.probed_modes, head) {
V_112 -> V_135 = F_45 ( V_112 ) ;
if ( V_78 -> V_136 ( V_3 , V_112 ) != V_137 ||
( V_112 -> V_138 & V_139 ) )
continue;
if ( V_112 -> type & V_140 ) {
F_46 ( V_23 , L_5 ) ;
return F_47 ( V_5 , V_112 ) ;
}
if ( V_112 -> V_141 < V_132 )
continue;
if ( V_112 -> V_141 == V_132 && V_112 -> V_142 < V_133 )
continue;
if ( V_112 -> V_141 == V_132 && V_112 -> V_142 == V_133 &&
V_112 -> V_135 < V_134 )
continue;
V_132 = V_112 -> V_141 ;
V_133 = V_112 -> V_142 ;
V_134 = V_112 -> V_135 ;
V_131 = V_112 ;
}
F_46 ( V_23 , L_6 ,
V_132 , V_133 , V_134 ) ;
return V_131 ? F_47 ( V_5 , V_131 ) : NULL ;
}
static int
F_48 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_129 * V_143 = V_17 -> V_144 , * V_145 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_146 * V_112 = & V_147 [ 0 ] ;
int V_148 = 0 ;
if ( ! V_143 )
return 0 ;
while ( V_112 -> V_141 ) {
if ( V_112 -> V_141 <= V_143 -> V_141 &&
V_112 -> V_142 <= V_143 -> V_142 ) {
V_145 = F_49 ( V_5 , V_112 -> V_141 , V_112 -> V_142 ,
F_45 ( V_143 ) , false ,
false , false ) ;
if ( ! V_145 )
continue;
V_145 -> type |= V_149 ;
F_50 ( V_3 , V_145 ) ;
V_148 ++ ;
}
V_112 ++ ;
}
return V_148 ;
}
static void
F_51 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_150 * V_151 = & V_23 -> V_82 ;
struct V_129 * V_112 = V_17 -> V_144 ;
bool V_152 ;
if ( V_17 -> V_19 && V_3 -> V_153 . V_154 )
return;
if ( V_17 -> type == V_29 ) {
V_3 -> V_153 . V_154 = 6 ;
return;
}
if ( V_6 -> V_14 -> type != V_53 ) {
V_3 -> V_153 . V_154 = 8 ;
return;
}
V_3 -> V_153 . V_154 = 6 ;
if ( V_151 -> V_83 ) {
if ( V_151 -> V_155 . V_156 )
V_3 -> V_153 . V_154 = 8 ;
return;
}
if ( V_17 -> V_19 &&
V_17 -> type == V_157 )
V_152 = ( ( V_158 * ) V_17 -> V_19 ) [ 121 ] == 2 ;
else
V_152 = V_112 -> clock >= V_151 -> V_155 . V_159 ;
if ( ( ! V_152 && ( V_151 -> V_155 . V_160 & 1 ) ) ||
( V_152 && ( V_151 -> V_155 . V_160 & 2 ) ) )
V_3 -> V_153 . V_154 = 8 ;
}
static int
F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
int V_34 = 0 ;
if ( V_17 -> V_144 ) {
F_53 ( V_5 , V_17 -> V_144 ) ;
V_17 -> V_144 = NULL ;
}
if ( V_17 -> V_19 )
V_34 = F_54 ( V_3 , V_17 -> V_19 ) ;
else
if ( V_6 -> V_14 -> type == V_53 &&
( V_6 -> V_14 -> V_84 . V_86 ||
V_23 -> V_82 . V_83 ) && F_35 ( V_5 , NULL ) ) {
struct V_129 V_112 ;
F_35 ( V_5 , & V_112 ) ;
V_17 -> V_144 = F_47 ( V_5 , & V_112 ) ;
}
if ( V_3 -> V_108 != V_109 )
F_51 ( V_3 ) ;
if ( ! V_17 -> V_144 )
V_17 -> V_144 =
F_44 ( V_3 ) ;
if ( V_34 == 0 && V_17 -> V_144 ) {
struct V_129 * V_112 ;
V_112 = F_47 ( V_5 , V_17 -> V_144 ) ;
F_50 ( V_3 , V_112 ) ;
V_34 = 1 ;
}
if ( V_3 -> V_108 == V_109 )
F_51 ( V_3 ) ;
if ( V_6 -> V_14 -> type == V_76 )
V_34 = F_42 ( V_16 ) -> F_55 ( V_16 , V_3 ) ;
if ( V_17 -> type == V_161 ||
V_17 -> type == V_157 ||
V_17 -> type == V_29 )
V_34 += F_48 ( V_3 ) ;
return V_34 ;
}
static unsigned
F_56 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_162 * V_14 = V_17 -> V_47 -> V_14 ;
if ( V_14 -> V_163 != V_164 ||
V_23 -> V_26 . V_48 . V_165 >= 0x46 )
return 165000 ;
else if ( V_23 -> V_26 . V_48 . V_165 >= 0x40 )
return 155000 ;
else if ( V_23 -> V_26 . V_48 . V_165 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_57 ( struct V_2 * V_3 ,
struct V_129 * V_112 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
unsigned V_166 = 25000 , V_167 = V_166 ;
unsigned clock = V_112 -> clock ;
switch ( V_6 -> V_14 -> type ) {
case V_53 :
if ( V_17 -> V_144 &&
( V_112 -> V_141 > V_17 -> V_144 -> V_141 ||
V_112 -> V_142 > V_17 -> V_144 -> V_142 ) )
return V_168 ;
V_166 = 0 ;
V_167 = 400000 ;
break;
case V_40 :
V_167 = F_56 ( V_3 ) ;
if ( V_169 && V_6 -> V_14 -> V_170 )
V_167 *= 2 ;
break;
case V_41 :
V_167 = V_6 -> V_14 -> V_171 . V_172 ;
if ( ! V_167 )
V_167 = 350000 ;
break;
case V_76 :
return F_42 ( V_16 ) -> V_136 ( V_16 , V_112 ) ;
case V_33 :
V_167 = V_6 -> V_173 . V_174 ;
V_167 *= V_6 -> V_173 . V_175 ;
clock = clock * ( V_3 -> V_153 . V_154 * 3 ) / 10 ;
break;
default:
F_58 ( 1 ) ;
return V_176 ;
}
if ( clock < V_166 )
return V_177 ;
if ( clock > V_167 )
return V_178 ;
return V_137 ;
}
static struct V_7 *
F_59 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_47 )
return F_4 ( V_17 -> V_47 ) ;
return NULL ;
}
static void
F_60 ( struct V_2 * V_3 , int V_112 )
{
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_16 )
V_6 = V_1 ( V_3 -> V_16 ) ;
if ( V_6 && V_6 -> V_14 &&
V_6 -> V_14 -> type == V_33 ) {
if ( V_112 == V_179 ) {
V_158 V_180 = V_181 ;
F_61 ( V_6 -> V_35 , V_182 , & V_180 , 1 ) ;
F_62 ( 1000 , 2000 ) ;
} else {
V_158 V_180 = V_183 ;
F_61 ( V_6 -> V_35 , V_182 , & V_180 , 1 ) ;
}
}
F_63 ( V_3 , V_112 ) ;
}
static int
F_64 ( struct V_184 * V_185 )
{
struct V_15 * V_17 =
F_65 ( V_185 , F_66 ( * V_17 ) , V_18 ) ;
struct V_2 * V_3 = & V_17 -> V_57 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
const struct V_186 * V_187 = V_185 -> V_180 ;
const char * V_42 = V_3 -> V_42 ;
if ( V_187 -> V_188 & V_189 ) {
} else {
bool V_190 = ( V_187 -> V_188 != V_191 ) ;
F_46 ( V_23 , L_7 , V_190 ? L_8 : L_9 , V_42 ) ;
if ( V_190 )
F_63 ( V_3 , V_179 ) ;
else
F_63 ( V_3 , V_192 ) ;
F_67 ( V_3 -> V_5 ) ;
}
return V_193 ;
}
static T_2
F_68 ( struct V_194 * V_20 , struct V_195 * V_196 )
{
struct V_15 * V_17 =
F_65 ( V_20 , F_66 ( * V_17 ) , V_20 ) ;
struct V_1 * V_6 ;
struct V_65 * V_197 ;
int V_34 ;
V_6 = F_1 ( & V_17 -> V_57 , V_33 ) ;
if ( ! V_6 || ! ( V_197 = V_6 -> V_35 ) )
return - V_28 ;
if ( F_69 ( V_196 -> V_198 > 16 ) )
return - V_199 ;
if ( V_196 -> V_198 == 0 )
return V_196 -> V_198 ;
V_34 = F_70 ( V_197 ) -> F_71 ( V_197 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = V_197 -> V_200 -> V_20 ( V_197 , false , V_196 -> V_201 , V_196 -> V_202 ,
V_196 -> V_203 , V_196 -> V_198 ) ;
F_70 ( V_197 ) -> F_72 ( V_197 ) ;
if ( V_34 >= 0 ) {
V_196 -> V_204 = V_34 ;
return V_196 -> V_198 ;
}
return V_34 ;
}
static int
F_73 ( enum V_205 V_14 )
{
switch ( V_14 ) {
case V_206 : return V_207 ;
case V_208 :
case V_209 :
case V_210 : return V_211 ;
case V_212 :
case V_213 :
case V_56 : return V_214 ;
case V_215 : return V_216 ;
case V_161 :
case V_157 : return V_109 ;
case V_217 :
case V_218 :
case V_219 : return V_220 ;
case V_29 : return V_221 ;
case V_222 :
case V_223 :
case V_224 : return V_225 ;
default:
break;
}
return V_226 ;
}
struct V_2 *
F_74 ( struct V_4 * V_5 , int V_227 )
{
const struct V_228 * V_229 = & V_230 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_96 * V_97 = V_96 ( V_5 ) ;
struct V_15 * V_17 = NULL ;
struct V_2 * V_3 ;
int type , V_34 = 0 ;
bool V_231 ;
F_5 (connector, &dev->mode_config.connector_list, head) {
V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_227 == V_227 )
return V_3 ;
}
V_17 = F_75 ( sizeof( * V_17 ) , V_46 ) ;
if ( ! V_17 )
return F_76 ( - V_232 ) ;
V_3 = & V_17 -> V_57 ;
V_17 -> V_227 = V_227 ;
V_17 -> V_14 = F_77 ( V_5 , V_227 ) ;
if ( V_17 -> V_14 ) {
T_3 V_233 = F_78 ( V_17 -> V_14 [ 0 ] ) ;
if ( F_79 ( V_5 ) [ 3 ] >= 4 )
V_233 |= ( T_3 ) F_78 ( V_17 -> V_14 [ 2 ] ) << 16 ;
V_17 -> type = V_17 -> V_14 [ 0 ] ;
if ( F_73 ( V_17 -> type ) ==
V_226 ) {
F_80 ( V_23 , L_10 ,
V_17 -> type ) ;
V_17 -> type = V_234 ;
}
if ( F_81 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_17 -> type == V_223 )
V_17 -> type = V_56 ;
}
if ( F_81 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_17 -> type == V_223 )
V_17 -> type = V_56 ;
}
} else {
V_17 -> type = V_234 ;
}
if ( V_17 -> type == V_234 ) {
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_235 * V_236 = & V_23 -> V_82 . V_14 ;
T_3 V_237 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_236 -> V_238 ; V_9 ++ ) {
if ( V_236 -> V_233 [ V_9 ] . V_3 == V_17 -> V_227 )
V_237 |= ( 1 << V_236 -> V_233 [ V_9 ] . type ) ;
}
if ( V_237 & ( 1 << V_33 ) ) {
if ( V_237 & ( 1 << V_40 ) )
V_17 -> type = V_219 ;
else
V_17 -> type = V_29 ;
} else
if ( V_237 & ( 1 << V_40 ) ) {
if ( V_237 & ( 1 << V_41 ) )
V_17 -> type = V_56 ;
else
V_17 -> type = V_215 ;
} else
if ( V_237 & ( 1 << V_41 ) ) {
V_17 -> type = V_206 ;
} else
if ( V_237 & ( 1 << V_53 ) ) {
V_17 -> type = V_161 ;
} else
if ( V_237 & ( 1 << V_76 ) ) {
V_17 -> type = V_208 ;
}
}
switch ( ( type = F_73 ( V_17 -> type ) ) ) {
case V_109 :
V_34 = F_82 ( V_5 , 0 , & V_231 , & V_231 ) ;
if ( V_34 ) {
F_30 ( V_23 , L_11 ) ;
F_8 ( V_17 ) ;
return F_76 ( V_34 ) ;
}
V_229 = & V_239 ;
break;
case V_220 :
case V_221 :
V_17 -> V_20 . V_5 = V_5 -> V_5 ;
V_17 -> V_20 . V_21 = F_68 ;
V_34 = F_83 ( & V_17 -> V_20 ) ;
if ( V_34 ) {
F_30 ( V_23 , L_12 ) ;
F_8 ( V_17 ) ;
return F_76 ( V_34 ) ;
}
V_229 = & V_240 ;
break;
default:
V_229 = & V_230 ;
break;
}
V_3 -> V_51 = false ;
V_3 -> V_52 = false ;
F_84 ( V_5 , V_3 , V_229 , type ) ;
F_85 ( V_3 , & V_241 ) ;
if ( V_17 -> type == V_56 )
F_86 ( & V_3 -> V_57 , V_5 -> V_58 . V_59 , 0 ) ;
if ( V_97 -> V_115 &&
( type == V_216 ||
type == V_214 ||
type == V_225 ||
type == V_220 ) ) {
F_86 ( & V_3 -> V_57 ,
V_97 -> V_115 ,
V_242 ) ;
F_86 ( & V_3 -> V_57 ,
V_97 -> V_117 ,
0 ) ;
F_86 ( & V_3 -> V_57 ,
V_97 -> V_119 ,
0 ) ;
}
if ( V_97 -> V_125 )
F_86 ( & V_3 -> V_57 ,
V_97 -> V_125 ,
90 ) ;
if ( V_97 -> V_127 )
F_86 ( & V_3 -> V_57 ,
V_97 -> V_127 ,
150 ) ;
switch ( V_17 -> type ) {
case V_206 :
if ( V_23 -> V_26 . V_48 . V_49 >= V_50 ) {
F_86 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_101 ,
V_17 -> V_110 ) ;
}
case V_208 :
case V_209 :
case V_210 :
V_17 -> V_110 = V_103 ;
break;
default:
V_17 -> V_110 = V_104 ;
F_86 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_101 ,
V_17 -> V_110 ) ;
if ( V_97 -> V_121 ) {
V_17 -> V_121 = V_243 ;
F_86 ( & V_3 -> V_57 ,
V_97 -> V_121 ,
V_17 -> V_121 ) ;
}
if ( V_97 -> V_123 ) {
V_17 -> V_123 = V_244 ;
F_86 ( & V_3 -> V_57 ,
V_97 -> V_123 ,
V_17 -> V_123 ) ;
}
break;
}
V_34 = F_87 (&disp->disp, NULL, nouveau_connector_hotplug,
true, NV04_DISP_NTFY_CONN,
&(struct nvif_notify_conn_req_v0) {
.mask = NVIF_NOTIFY_CONN_V0_ANY,
.conn = index,
},
sizeof(struct nvif_notify_conn_req_v0),
sizeof(struct nvif_notify_conn_rep_v0),
&nv_connector->hpd) ;
if ( V_34 )
V_3 -> V_245 = V_246 ;
else
V_3 -> V_245 = V_247 ;
F_88 ( V_3 ) ;
return V_3 ;
}
