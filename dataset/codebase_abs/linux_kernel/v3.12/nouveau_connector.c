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
int V_64 ;
enum V_61 V_65 = V_66 ;
if ( V_18 -> V_19 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_64 = F_26 ( V_3 -> V_5 -> V_5 ) ;
if ( V_64 < 0 )
return V_65 ;
V_34 = F_11 ( V_3 , & V_6 ) ;
if ( V_34 ) {
V_18 -> V_19 = F_27 ( V_3 , & V_34 -> V_67 ) ;
F_25 ( V_3 ,
V_18 -> V_19 ) ;
if ( ! V_18 -> V_19 ) {
F_28 ( V_23 , L_3 ,
F_29 ( V_3 ) ) ;
goto V_68;
}
if ( V_6 -> V_15 -> type == V_69 &&
! F_30 ( F_5 ( V_6 ) ) ) {
F_28 ( V_23 , L_4 ,
F_29 ( V_3 ) ) ;
V_65 = V_66 ;
goto V_70;
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
if ( V_18 -> V_19 -> V_71 & V_72 )
type = V_39 ;
else
type = V_40 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_21 ( V_3 , V_6 ) ;
V_65 = V_73 ;
goto V_70;
}
V_6 = F_14 ( V_3 ) ;
if ( V_6 ) {
F_21 ( V_3 , V_6 ) ;
V_65 = V_73 ;
goto V_70;
}
V_68:
V_6 = F_1 ( V_3 , V_40 ) ;
if ( ! V_6 && ! V_74 )
V_6 = F_1 ( V_3 , V_75 ) ;
if ( V_6 && V_62 ) {
struct V_76 * V_17 = F_5 ( V_6 ) ;
struct V_77 * V_78 =
V_17 -> V_79 ;
if ( V_78 -> V_80 ( V_17 , V_3 ) ==
V_73 ) {
F_21 ( V_3 , V_6 ) ;
V_65 = V_73 ;
goto V_70;
}
}
V_70:
F_31 ( V_3 -> V_5 -> V_5 ) ;
F_32 ( V_3 -> V_5 -> V_5 ) ;
return V_65 ;
}
static enum V_61
F_33 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_61 V_81 = V_66 ;
if ( V_18 -> V_19 ) {
F_25 ( V_3 , NULL ) ;
F_8 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_51 ) ;
if ( ! V_6 )
return V_66 ;
if ( ! V_23 -> V_82 . V_83 ) {
V_81 = F_24 ( V_3 , V_62 ) ;
if ( V_81 == V_73 )
goto V_70;
}
if ( V_6 -> V_15 -> V_84 . V_85 ) {
if ( ( V_18 -> V_19 = F_34 ( V_5 , V_3 ) ) ) {
V_81 = V_73 ;
goto V_70;
}
}
if ( F_35 ( V_5 , NULL ) && ( V_23 -> V_82 . V_83 ||
V_6 -> V_15 -> V_84 . V_86 ) ) {
V_81 = V_73 ;
goto V_70;
}
if ( ! V_23 -> V_82 . V_83 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_36 ( V_5 ) ;
if ( V_19 ) {
V_18 -> V_19 =
F_19 ( V_19 , V_44 , V_45 ) ;
if ( V_18 -> V_19 )
V_81 = V_73 ;
}
}
V_70:
#if F_37 ( V_87 ) || \
( F_37 ( V_88 ) && F_37 ( V_89 ) )
if ( V_81 == V_73 &&
! V_90 && ! F_38 () )
V_81 = V_91 ;
#endif
F_25 ( V_3 , V_18 -> V_19 ) ;
F_21 ( V_3 , V_6 ) ;
return V_81 ;
}
static void
F_39 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_55 ) {
if ( V_3 -> V_62 == V_92 )
type = V_39 ;
else
type = V_40 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_28 ( V_23 , L_5 ,
F_29 ( V_3 ) ) ;
V_3 -> V_81 = V_66 ;
return;
}
F_21 ( V_3 , V_6 ) ;
}
static int
F_40 ( struct V_2 * V_3 ,
struct V_93 * V_94 , T_1 V_95 )
{
struct V_96 * V_97 = V_96 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_76 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_98 * V_99 ;
int V_64 ;
V_99 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_100 )
V_99 = V_98 ( V_3 -> V_17 -> V_100 ) ;
if ( V_94 == V_5 -> V_57 . V_101 ) {
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
if ( ( V_18 -> V_110 == V_103 ) ||
( V_95 == V_103 ) )
V_102 = true ;
V_18 -> V_110 = V_95 ;
if ( ! V_99 )
return 0 ;
if ( V_102 || ! V_99 -> V_111 ) {
V_64 = F_41 ( & V_99 -> V_56 ,
& V_99 -> V_56 . V_112 ,
V_99 -> V_56 . V_113 ,
V_99 -> V_56 . V_114 , NULL ) ;
if ( ! V_64 )
return - V_107 ;
} else {
V_64 = V_99 -> V_111 ( V_99 , true ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_115 ) {
if ( V_18 -> V_116 != V_95 ) {
V_18 -> V_116 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_117 ) {
if ( V_18 -> V_118 != V_95 ) {
V_18 -> V_118 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_119 ) {
if ( V_18 -> V_120 != V_95 ) {
V_18 -> V_120 = V_95 ;
if ( ! V_99 || ! V_99 -> V_111 )
return 0 ;
return V_99 -> V_111 ( V_99 , true ) ;
}
return 0 ;
}
if ( V_94 == V_97 -> V_121 ) {
V_18 -> V_121 = V_95 ;
if ( ! V_99 || ! V_99 -> V_122 )
return 0 ;
return V_99 -> V_122 ( V_99 , true ) ;
}
if ( V_94 == V_97 -> V_123 ) {
V_18 -> V_123 = V_95 ;
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
if ( V_6 && V_6 -> V_15 -> type == V_75 )
return F_42 ( V_17 ) -> F_43 (
V_17 , V_3 , V_94 , V_95 ) ;
return - V_107 ;
}
static struct V_129 *
F_44 ( struct V_2 * V_3 )
{
struct V_130 * V_78 = V_3 -> V_79 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_129 * V_112 , * V_131 = NULL ;
int V_132 = 0 , V_133 = 0 , V_134 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_112 -> V_135 = F_45 ( V_112 ) ;
if ( V_78 -> V_136 ( V_3 , V_112 ) != V_137 ||
( V_112 -> V_138 & V_139 ) )
continue;
if ( V_112 -> type & V_140 ) {
F_46 ( V_23 , L_6 ) ;
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
F_46 ( V_23 , L_7 ,
V_132 , V_133 , V_134 ) ;
return V_131 ? F_47 ( V_5 , V_131 ) : NULL ;
}
static int
F_48 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_129 * V_143 = V_18 -> V_144 , * V_145 ;
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
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_150 * V_151 = & V_23 -> V_82 ;
struct V_129 * V_112 = V_18 -> V_144 ;
bool V_152 ;
if ( V_18 -> V_19 && V_3 -> V_153 . V_154 )
return;
if ( V_18 -> type == V_30 ) {
V_3 -> V_153 . V_154 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_51 ) {
V_3 -> V_153 . V_154 = 8 ;
return;
}
V_3 -> V_153 . V_154 = 6 ;
if ( V_151 -> V_83 ) {
if ( V_151 -> V_155 . V_156 )
V_3 -> V_153 . V_154 = 8 ;
return;
}
if ( V_18 -> V_19 &&
V_18 -> type == V_157 )
V_152 = ( ( V_158 * ) V_18 -> V_19 ) [ 121 ] == 2 ;
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
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_76 * V_17 = F_5 ( V_6 ) ;
int V_64 = 0 ;
if ( V_18 -> V_144 ) {
F_53 ( V_5 , V_18 -> V_144 ) ;
V_18 -> V_144 = NULL ;
}
if ( V_18 -> V_19 )
V_64 = F_54 ( V_3 , V_18 -> V_19 ) ;
else
if ( V_6 -> V_15 -> type == V_51 &&
( V_6 -> V_15 -> V_84 . V_86 ||
V_23 -> V_82 . V_83 ) && F_35 ( V_5 , NULL ) ) {
struct V_129 V_112 ;
F_35 ( V_5 , & V_112 ) ;
V_18 -> V_144 = F_47 ( V_5 , & V_112 ) ;
}
if ( V_3 -> V_108 != V_109 )
F_51 ( V_3 ) ;
if ( ! V_18 -> V_144 )
V_18 -> V_144 =
F_44 ( V_3 ) ;
if ( V_64 == 0 && V_18 -> V_144 ) {
struct V_129 * V_112 ;
V_112 = F_47 ( V_5 , V_18 -> V_144 ) ;
F_50 ( V_3 , V_112 ) ;
V_64 = 1 ;
}
if ( V_3 -> V_108 == V_109 )
F_51 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_75 )
V_64 = F_42 ( V_17 ) -> F_55 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_161 ||
V_18 -> type == V_157 ||
V_18 -> type == V_30 )
V_64 += F_48 ( V_3 ) ;
return V_64 ;
}
static unsigned
F_56 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_162 * V_15 = V_18 -> V_46 -> V_15 ;
if ( V_15 -> V_163 != V_164 ||
F_22 ( V_23 -> V_26 ) -> V_165 >= 0x46 )
return 165000 ;
else if ( F_22 ( V_23 -> V_26 ) -> V_165 >= 0x40 )
return 155000 ;
else if ( F_22 ( V_23 -> V_26 ) -> V_165 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_57 ( struct V_2 * V_3 ,
struct V_129 * V_112 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_46 ;
struct V_76 * V_17 = F_5 ( V_6 ) ;
unsigned V_166 = 25000 , V_167 = V_166 ;
unsigned clock = V_112 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_51 :
if ( V_18 -> V_144 &&
( V_112 -> V_141 > V_18 -> V_144 -> V_141 ||
V_112 -> V_142 > V_18 -> V_144 -> V_142 ) )
return V_168 ;
V_166 = 0 ;
V_167 = 400000 ;
break;
case V_39 :
V_167 = F_56 ( V_3 ) ;
if ( V_169 && V_6 -> V_15 -> V_170 )
V_167 *= 2 ;
break;
case V_40 :
V_167 = V_6 -> V_15 -> V_171 . V_172 ;
if ( ! V_167 )
V_167 = 350000 ;
break;
case V_75 :
return F_42 ( V_17 ) -> V_136 ( V_17 , V_112 ) ;
case V_69 :
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
static struct V_76 *
F_59 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_46 )
return F_5 ( V_18 -> V_46 ) ;
return NULL ;
}
static void
F_60 ( struct V_179 * V_180 )
{
struct V_16 * V_18 =
F_61 ( V_180 , struct V_16 , V_181 ) ;
struct V_2 * V_3 = & V_18 -> V_56 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
bool V_182 = V_25 -> V_31 ( V_25 , 0 , V_18 -> V_183 . V_184 , 0xff ) ;
F_46 ( V_23 , L_8 , V_182 ? L_9 : L_10 ,
F_29 ( V_3 ) ) ;
if ( V_182 )
F_62 ( V_3 , V_185 ) ;
else
F_62 ( V_3 , V_186 ) ;
F_63 ( V_5 ) ;
}
static int
F_64 ( struct V_187 * V_188 , int V_189 )
{
struct V_16 * V_18 =
F_61 ( V_188 , struct V_16 , V_190 ) ;
F_65 ( & V_18 -> V_181 ) ;
return V_191 ;
}
static int
F_66 ( enum V_192 V_15 )
{
switch ( V_15 ) {
case V_193 : return V_194 ;
case V_195 :
case V_196 :
case V_197 : return V_198 ;
case V_199 :
case V_200 :
case V_55 : return V_201 ;
case V_202 : return V_203 ;
case V_161 :
case V_157 : return V_109 ;
case V_204 :
case V_205 :
case V_206 : return V_207 ;
case V_30 : return V_208 ;
case V_209 :
case V_210 : return V_211 ;
default:
break;
}
return V_212 ;
}
struct V_2 *
F_67 ( struct V_4 * V_5 , int V_189 )
{
const struct V_213 * V_214 = & V_215 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
struct V_96 * V_97 = V_96 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_64 = 0 ;
bool V_216 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_189 == V_189 )
return V_3 ;
}
V_18 = F_68 ( sizeof( * V_18 ) , V_45 ) ;
if ( ! V_18 )
return F_69 ( - V_217 ) ;
V_3 = & V_18 -> V_56 ;
F_70 ( & V_18 -> V_181 , F_60 ) ;
V_18 -> V_189 = V_189 ;
V_18 -> V_15 = F_71 ( V_5 , V_189 ) ;
if ( V_18 -> V_15 ) {
static const V_158 V_183 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_218 = F_72 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_73 ( V_5 ) [ 3 ] >= 4 )
V_218 |= ( T_2 ) F_72 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_64 = V_25 -> V_219 ( V_25 , 0 , V_183 [ F_74 ( ( V_218 & 0x07033000 ) >> 12 ) ] ,
V_220 , & V_18 -> V_183 ) ;
V_18 -> V_190 . V_184 = F_64 ;
if ( V_64 )
V_18 -> V_183 . V_184 = V_220 ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_66 ( V_18 -> type ) ==
V_212 ) {
F_75 ( V_23 , L_11 ,
V_18 -> type ) ;
V_18 -> type = V_221 ;
}
if ( F_76 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_210 )
V_18 -> type = V_55 ;
}
if ( F_76 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_210 )
V_18 -> type = V_55 ;
}
} else {
V_18 -> type = V_221 ;
V_18 -> V_183 . V_184 = V_220 ;
}
if ( V_18 -> type == V_221 ) {
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_222 * V_223 = & V_23 -> V_82 . V_15 ;
T_2 V_224 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_223 -> V_225 ; V_9 ++ ) {
if ( V_223 -> V_218 [ V_9 ] . V_3 == V_18 -> V_189 )
V_224 |= ( 1 << V_223 -> V_218 [ V_9 ] . type ) ;
}
if ( V_224 & ( 1 << V_69 ) ) {
if ( V_224 & ( 1 << V_39 ) )
V_18 -> type = V_206 ;
else
V_18 -> type = V_30 ;
} else
if ( V_224 & ( 1 << V_39 ) ) {
if ( V_224 & ( 1 << V_40 ) )
V_18 -> type = V_55 ;
else
V_18 -> type = V_202 ;
} else
if ( V_224 & ( 1 << V_40 ) ) {
V_18 -> type = V_193 ;
} else
if ( V_224 & ( 1 << V_51 ) ) {
V_18 -> type = V_161 ;
} else
if ( V_224 & ( 1 << V_75 ) ) {
V_18 -> type = V_195 ;
}
}
type = F_66 ( V_18 -> type ) ;
if ( type == V_109 ) {
V_64 = F_77 ( V_5 , 0 , & V_216 , & V_216 ) ;
if ( V_64 ) {
F_28 ( V_23 , L_12 ) ;
F_8 ( V_18 ) ;
return F_69 ( V_64 ) ;
}
V_214 = & V_226 ;
} else {
V_214 = & V_215 ;
}
V_3 -> V_49 = false ;
V_3 -> V_50 = false ;
F_78 ( V_5 , V_3 , V_214 , type ) ;
F_79 ( V_3 , & V_227 ) ;
if ( V_18 -> type == V_55 )
F_80 ( & V_3 -> V_56 , V_5 -> V_57 . V_58 , 0 ) ;
if ( V_97 -> V_115 &&
( type == V_203 ||
type == V_201 ||
type == V_211 ||
type == V_207 ) ) {
F_80 ( & V_3 -> V_56 ,
V_97 -> V_115 ,
V_228 ) ;
F_80 ( & V_3 -> V_56 ,
V_97 -> V_117 ,
0 ) ;
F_80 ( & V_3 -> V_56 ,
V_97 -> V_119 ,
0 ) ;
}
if ( V_97 -> V_125 )
F_80 ( & V_3 -> V_56 ,
V_97 -> V_125 ,
90 ) ;
if ( V_97 -> V_127 )
F_80 ( & V_3 -> V_56 ,
V_97 -> V_127 ,
150 ) ;
switch ( V_18 -> type ) {
case V_193 :
if ( F_22 ( V_23 -> V_26 ) -> V_47 >= V_48 ) {
F_80 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_101 ,
V_18 -> V_110 ) ;
}
case V_195 :
case V_196 :
case V_197 :
V_18 -> V_110 = V_103 ;
break;
default:
V_18 -> V_110 = V_104 ;
F_80 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_101 ,
V_18 -> V_110 ) ;
if ( V_97 -> V_121 ) {
V_18 -> V_121 = V_229 ;
F_80 ( & V_3 -> V_56 ,
V_97 -> V_121 ,
V_18 -> V_121 ) ;
}
if ( V_97 -> V_123 ) {
V_18 -> V_123 = V_230 ;
F_80 ( & V_3 -> V_56 ,
V_97 -> V_123 ,
V_18 -> V_123 ) ;
}
break;
}
V_3 -> V_231 = V_232 ;
if ( V_18 -> V_183 . V_184 != V_220 )
V_3 -> V_231 = V_233 ;
F_81 ( V_3 ) ;
return V_3 ;
}
