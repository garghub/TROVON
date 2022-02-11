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
V_27 = F_14 ( V_25 , 0 , V_30 , 0xff ) ;
if ( V_27 == 0 ) {
F_15 ( V_25 , 0 , V_30 , 0xff , 1 ) ;
F_16 ( 300 ) ;
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
if ( V_6 -> V_14 -> type == V_31 ) {
int V_32 = F_17 ( V_6 ) ;
if ( V_32 == 0 )
break;
} else
if ( V_6 -> V_33 ) {
if ( F_18 ( V_6 -> V_33 , 0x50 ) )
break;
}
}
if ( ! V_6 && V_27 == 0 )
F_15 ( V_25 , 0 , V_30 , 0xff , V_27 ) ;
return V_6 ;
}
static struct V_1 *
F_19 ( struct V_2 * V_3 )
{
#ifdef F_20
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_34 * V_35 , * V_36 = F_21 ( V_5 -> V_37 ) ;
if ( ! V_36 ||
! ( ( V_6 = F_1 ( V_3 , V_38 ) ) ||
( V_6 = F_1 ( V_3 , V_39 ) ) ) )
return NULL ;
F_22 (dn, cn) {
const char * V_40 = F_23 ( V_35 , L_1 , NULL ) ;
const void * V_19 = F_23 ( V_35 , L_2 , NULL ) ;
int V_41 = V_40 ? V_40 [ strlen ( V_40 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_14 -> V_42 == V_41 && V_19 ) {
V_17 -> V_19 =
F_24 ( V_19 , V_43 , V_44 ) ;
F_25 ( V_35 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_26 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_17 -> V_45 == V_6 )
return;
V_17 -> V_45 = V_6 ;
if ( V_23 -> V_26 . V_46 . V_47 >= V_48 ) {
V_3 -> V_49 = true ;
V_3 -> V_50 = true ;
} else
if ( V_6 -> V_14 -> type == V_51 ||
V_6 -> V_14 -> type == V_38 ) {
V_3 -> V_50 = false ;
V_3 -> V_49 = false ;
} else {
V_3 -> V_50 = true ;
if ( V_23 -> V_26 . V_46 . V_47 == V_52 ||
( V_23 -> V_26 . V_46 . V_47 == V_53 &&
( V_5 -> V_37 -> V_26 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_37 -> V_26 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_49 = false ;
else
V_3 -> V_49 = true ;
}
if ( V_17 -> type == V_54 ) {
F_27 ( & V_3 -> V_55 ,
V_5 -> V_56 . V_57 ,
V_6 -> V_14 -> type == V_38 ?
V_58 :
V_59 ) ;
}
}
static enum V_60
F_28 ( struct V_2 * V_3 , bool V_61 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_62 ;
struct V_63 * V_33 ;
int type ;
int V_32 ;
enum V_60 V_64 = V_65 ;
if ( V_17 -> V_19 ) {
F_29 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_32 = F_30 ( V_3 -> V_5 -> V_5 ) ;
if ( V_32 < 0 && V_32 != - V_66 )
return V_64 ;
V_6 = F_12 ( V_3 ) ;
if ( V_6 && ( V_33 = V_6 -> V_33 ) != NULL ) {
V_17 -> V_19 = F_31 ( V_3 , V_33 ) ;
F_29 ( V_3 ,
V_17 -> V_19 ) ;
if ( ! V_17 -> V_19 ) {
F_32 ( V_23 , L_3 ,
V_3 -> V_40 ) ;
goto V_67;
}
V_62 = NULL ;
if ( V_6 -> V_14 -> type == V_38 )
V_62 = F_1 ( V_3 , V_39 ) ;
if ( V_6 -> V_14 -> type == V_39 )
V_62 = F_1 ( V_3 , V_38 ) ;
if ( V_62 && ( ( V_6 -> V_14 -> type == V_39 &&
V_62 -> V_14 -> type == V_38 ) ||
( V_6 -> V_14 -> type == V_38 &&
V_62 -> V_14 -> type == V_39 ) ) ) {
if ( V_17 -> V_19 -> V_68 & V_69 )
type = V_38 ;
else
type = V_39 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_26 ( V_3 , V_6 ) ;
V_64 = V_70 ;
goto V_71;
}
V_6 = F_19 ( V_3 ) ;
if ( V_6 ) {
F_26 ( V_3 , V_6 ) ;
V_64 = V_70 ;
goto V_71;
}
V_67:
V_6 = F_1 ( V_3 , V_39 ) ;
if ( ! V_6 && ! V_72 )
V_6 = F_1 ( V_3 , V_73 ) ;
if ( V_6 && V_61 ) {
struct V_7 * V_16 = F_4 ( V_6 ) ;
const struct V_74 * V_75 =
V_16 -> V_76 ;
if ( V_75 -> V_77 ( V_16 , V_3 ) ==
V_70 ) {
F_26 ( V_3 , V_6 ) ;
V_64 = V_70 ;
goto V_71;
}
}
V_71:
F_33 ( V_3 -> V_5 -> V_5 ) ;
F_34 ( V_3 -> V_5 -> V_5 ) ;
return V_64 ;
}
static enum V_60
F_35 ( struct V_2 * V_3 , bool V_61 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_60 V_78 = V_65 ;
if ( V_17 -> V_19 ) {
F_29 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_51 ) ;
if ( ! V_6 )
return V_65 ;
if ( ! V_23 -> V_79 . V_80 ) {
V_78 = F_28 ( V_3 , V_61 ) ;
if ( V_78 == V_70 )
goto V_71;
}
if ( V_6 -> V_14 -> V_81 . V_82 ) {
if ( ( V_17 -> V_19 = F_36 ( V_5 , V_3 ) ) ) {
V_78 = V_70 ;
goto V_71;
}
}
if ( F_37 ( V_5 , NULL ) && ( V_23 -> V_79 . V_80 ||
V_6 -> V_14 -> V_81 . V_83 ) ) {
V_78 = V_70 ;
goto V_71;
}
if ( ! V_23 -> V_79 . V_80 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_38 ( V_5 ) ;
if ( V_19 ) {
V_17 -> V_19 =
F_24 ( V_19 , V_43 , V_44 ) ;
if ( V_17 -> V_19 )
V_78 = V_70 ;
}
}
V_71:
#if F_39 ( V_84 ) || \
( F_39 ( V_85 ) && F_39 ( V_86 ) )
if ( V_78 == V_70 &&
! V_87 && ! F_40 () )
V_78 = V_88 ;
#endif
F_29 ( V_3 , V_17 -> V_19 ) ;
F_26 ( V_3 , V_6 ) ;
return V_78 ;
}
static void
F_41 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_17 -> type == V_54 ) {
if ( V_3 -> V_61 == V_89 )
type = V_38 ;
else
type = V_39 ;
} else
type = V_13 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_32 ( V_23 , L_4 ,
V_3 -> V_40 ) ;
V_3 -> V_78 = V_65 ;
return;
}
F_26 ( V_3 , V_6 ) ;
}
static int
F_42 ( struct V_2 * V_3 ,
struct V_90 * V_91 , T_1 V_92 )
{
struct V_93 * V_94 = V_93 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_45 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_95 * V_96 ;
int V_32 ;
V_96 = NULL ;
if ( V_3 -> V_16 && V_3 -> V_16 -> V_97 )
V_96 = V_95 ( V_3 -> V_16 -> V_97 ) ;
if ( V_91 == V_5 -> V_56 . V_98 ) {
bool V_99 = false ;
switch ( V_92 ) {
case V_100 :
switch ( V_17 -> type ) {
case V_101 :
case V_102 :
case V_29 :
if ( V_94 -> V_94 . V_103 < V_104 )
return - V_105 ;
break;
default:
break;
}
break;
case V_106 :
case V_107 :
case V_108 :
break;
default:
return - V_105 ;
}
if ( ( V_17 -> V_109 == V_100 ) ||
( V_92 == V_100 ) )
V_99 = true ;
V_17 -> V_109 = V_92 ;
if ( ! V_96 )
return 0 ;
if ( V_99 || ! V_96 -> V_110 ) {
V_32 = F_43 ( & V_96 -> V_55 ,
& V_96 -> V_55 . V_111 ,
V_96 -> V_55 . V_112 ,
V_96 -> V_55 . V_113 , NULL ) ;
if ( ! V_32 )
return - V_105 ;
} else {
V_32 = V_96 -> V_110 ( V_96 , true ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
if ( V_91 == V_94 -> V_114 ) {
if ( V_17 -> V_115 != V_92 ) {
V_17 -> V_115 = V_92 ;
if ( ! V_96 || ! V_96 -> V_110 )
return 0 ;
return V_96 -> V_110 ( V_96 , true ) ;
}
return 0 ;
}
if ( V_91 == V_94 -> V_116 ) {
if ( V_17 -> V_117 != V_92 ) {
V_17 -> V_117 = V_92 ;
if ( ! V_96 || ! V_96 -> V_110 )
return 0 ;
return V_96 -> V_110 ( V_96 , true ) ;
}
return 0 ;
}
if ( V_91 == V_94 -> V_118 ) {
if ( V_17 -> V_119 != V_92 ) {
V_17 -> V_119 = V_92 ;
if ( ! V_96 || ! V_96 -> V_110 )
return 0 ;
return V_96 -> V_110 ( V_96 , true ) ;
}
return 0 ;
}
if ( V_91 == V_94 -> V_120 ) {
V_17 -> V_120 = V_92 ;
if ( ! V_96 || ! V_96 -> V_121 )
return 0 ;
return V_96 -> V_121 ( V_96 , true ) ;
}
if ( V_91 == V_94 -> V_122 ) {
V_17 -> V_122 = V_92 ;
if ( ! V_96 || ! V_96 -> V_121 )
return 0 ;
return V_96 -> V_121 ( V_96 , true ) ;
}
if ( V_96 && V_96 -> V_123 ) {
if ( V_91 == V_94 -> V_124 ) {
V_96 -> V_125 = V_92 - 90 ;
return V_96 -> V_123 ( V_96 , true ) ;
}
if ( V_91 == V_94 -> V_126 ) {
V_96 -> V_127 = V_92 - 100 ;
return V_96 -> V_123 ( V_96 , true ) ;
}
}
if ( V_6 && V_6 -> V_14 -> type == V_73 )
return F_44 ( V_16 ) -> F_45 (
V_16 , V_3 , V_91 , V_92 ) ;
return - V_105 ;
}
static struct V_128 *
F_46 ( struct V_2 * V_3 )
{
const struct V_129 * V_75 = V_3 -> V_76 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_128 * V_111 , * V_130 = NULL ;
int V_131 = 0 , V_132 = 0 , V_133 = 0 ;
F_5 (mode, &nv_connector->base.probed_modes, head) {
V_111 -> V_134 = F_47 ( V_111 ) ;
if ( V_75 -> V_135 ( V_3 , V_111 ) != V_136 ||
( V_111 -> V_137 & V_138 ) )
continue;
if ( V_111 -> type & V_139 ) {
F_48 ( V_23 , L_5 ) ;
return F_49 ( V_5 , V_111 ) ;
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
F_48 ( V_23 , L_6 ,
V_131 , V_132 , V_133 ) ;
return V_130 ? F_49 ( V_5 , V_130 ) : NULL ;
}
static int
F_50 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_128 * V_142 = V_17 -> V_143 , * V_144 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_145 * V_111 = & V_146 [ 0 ] ;
int V_147 = 0 ;
if ( ! V_142 )
return 0 ;
while ( V_111 -> V_140 ) {
if ( V_111 -> V_140 <= V_142 -> V_140 &&
V_111 -> V_141 <= V_142 -> V_141 &&
( V_111 -> V_140 != V_142 -> V_140 ||
V_111 -> V_141 != V_142 -> V_141 ) ) {
V_144 = F_51 ( V_5 , V_111 -> V_140 , V_111 -> V_141 ,
F_47 ( V_142 ) , false ,
false , false ) ;
if ( ! V_144 )
continue;
F_52 ( V_3 , V_144 ) ;
V_147 ++ ;
}
V_111 ++ ;
}
return V_147 ;
}
static void
F_53 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_45 ;
struct V_148 * V_149 = & V_23 -> V_79 ;
struct V_128 * V_111 = V_17 -> V_143 ;
bool V_150 ;
if ( V_17 -> V_19 && V_3 -> V_151 . V_152 )
return;
if ( V_17 -> type == V_29 ) {
V_3 -> V_151 . V_152 = 6 ;
return;
}
if ( V_6 -> V_14 -> type != V_51 ) {
V_3 -> V_151 . V_152 = 8 ;
return;
}
V_3 -> V_151 . V_152 = 6 ;
if ( V_149 -> V_80 ) {
if ( V_149 -> V_153 . V_154 )
V_3 -> V_151 . V_152 = 8 ;
return;
}
if ( V_17 -> V_19 &&
V_17 -> type == V_102 )
V_150 = ( ( V_155 * ) V_17 -> V_19 ) [ 121 ] == 2 ;
else
V_150 = V_111 -> clock >= V_149 -> V_153 . V_156 ;
if ( ( ! V_150 && ( V_149 -> V_153 . V_157 & 1 ) ) ||
( V_150 && ( V_149 -> V_153 . V_157 & 2 ) ) )
V_3 -> V_151 . V_152 = 8 ;
}
static int
F_54 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_45 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
int V_32 = 0 ;
if ( V_17 -> V_143 ) {
F_55 ( V_5 , V_17 -> V_143 ) ;
V_17 -> V_143 = NULL ;
}
if ( V_17 -> V_19 )
V_32 = F_56 ( V_3 , V_17 -> V_19 ) ;
else
if ( V_6 -> V_14 -> type == V_51 &&
( V_6 -> V_14 -> V_81 . V_83 ||
V_23 -> V_79 . V_80 ) && F_37 ( V_5 , NULL ) ) {
struct V_128 V_111 ;
F_37 ( V_5 , & V_111 ) ;
V_17 -> V_143 = F_49 ( V_5 , & V_111 ) ;
}
if ( V_3 -> V_158 != V_159 )
F_53 ( V_3 ) ;
if ( ! V_17 -> V_143 )
V_17 -> V_143 =
F_46 ( V_3 ) ;
if ( V_32 == 0 && V_17 -> V_143 ) {
struct V_128 * V_111 ;
V_111 = F_49 ( V_5 , V_17 -> V_143 ) ;
F_52 ( V_3 , V_111 ) ;
V_32 = 1 ;
}
if ( V_3 -> V_158 == V_159 )
F_53 ( V_3 ) ;
if ( V_6 -> V_14 -> type == V_73 )
V_32 = F_44 ( V_16 ) -> F_57 ( V_16 , V_3 ) ;
if ( V_17 -> type == V_101 ||
V_17 -> type == V_102 ||
V_17 -> type == V_29 )
V_32 += F_50 ( V_3 ) ;
return V_32 ;
}
static unsigned
F_58 ( struct V_2 * V_3 , bool V_160 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_161 * V_14 = V_17 -> V_45 -> V_14 ;
if ( V_160 ) {
if ( V_162 > 0 )
return V_162 * 1000 ;
if ( V_23 -> V_26 . V_46 . V_47 >= V_163 )
return 297000 ;
if ( V_23 -> V_26 . V_46 . V_47 >= V_164 )
return 225000 ;
}
if ( V_14 -> V_165 != V_166 ||
V_23 -> V_26 . V_46 . V_167 >= 0x46 )
return 165000 ;
else if ( V_23 -> V_26 . V_46 . V_167 >= 0x40 )
return 155000 ;
else if ( V_23 -> V_26 . V_46 . V_167 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_59 ( struct V_2 * V_3 ,
struct V_128 * V_111 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_45 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
unsigned V_168 = 25000 , V_169 = V_168 ;
unsigned clock = V_111 -> clock ;
bool V_160 ;
switch ( V_6 -> V_14 -> type ) {
case V_51 :
if ( V_17 -> V_143 &&
( V_111 -> V_140 > V_17 -> V_143 -> V_140 ||
V_111 -> V_141 > V_17 -> V_143 -> V_141 ) )
return V_170 ;
V_168 = 0 ;
V_169 = 400000 ;
break;
case V_38 :
V_160 = F_60 ( V_17 -> V_19 ) ;
V_169 = F_58 ( V_3 , V_160 ) ;
if ( ! V_160 && V_171 &&
V_6 -> V_14 -> V_172 )
V_169 *= 2 ;
break;
case V_39 :
V_169 = V_6 -> V_14 -> V_173 . V_174 ;
if ( ! V_169 )
V_169 = 350000 ;
break;
case V_73 :
return F_44 ( V_16 ) -> V_135 ( V_16 , V_111 ) ;
case V_31 :
V_169 = V_6 -> V_175 . V_176 ;
V_169 *= V_6 -> V_175 . V_177 ;
clock = clock * ( V_3 -> V_151 . V_152 * 3 ) / 10 ;
break;
default:
F_61 ( 1 ) ;
return V_178 ;
}
if ( clock < V_168 )
return V_179 ;
if ( clock > V_169 )
return V_180 ;
return V_136 ;
}
static struct V_7 *
F_62 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_45 )
return F_4 ( V_17 -> V_45 ) ;
return NULL ;
}
static int
F_63 ( struct V_2 * V_3 , int V_111 )
{
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_16 )
V_6 = V_1 ( V_3 -> V_16 ) ;
if ( V_6 && V_6 -> V_14 &&
V_6 -> V_14 -> type == V_31 ) {
if ( V_111 == V_181 ) {
V_155 V_182 = V_183 ;
F_64 ( V_6 -> V_20 , V_184 , & V_182 , 1 ) ;
F_65 ( 1000 , 2000 ) ;
} else {
V_155 V_182 = V_185 ;
F_64 ( V_6 -> V_20 , V_184 , & V_182 , 1 ) ;
}
}
return F_66 ( V_3 , V_111 ) ;
}
static int
F_67 ( struct V_186 * V_187 )
{
struct V_15 * V_17 =
F_68 ( V_187 , F_69 ( * V_17 ) , V_18 ) ;
struct V_2 * V_3 = & V_17 -> V_55 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
const struct V_188 * V_189 = V_187 -> V_182 ;
const char * V_40 = V_3 -> V_40 ;
if ( V_189 -> V_190 & V_191 ) {
} else {
bool V_192 = ( V_189 -> V_190 != V_193 ) ;
F_48 ( V_23 , L_7 , V_192 ? L_8 : L_9 , V_40 ) ;
F_70 ( & V_23 -> V_5 -> V_56 . V_194 ) ;
if ( V_192 )
F_66 ( V_3 , V_181 ) ;
else
F_66 ( V_3 , V_195 ) ;
F_71 ( & V_23 -> V_5 -> V_56 . V_194 ) ;
F_72 ( V_3 -> V_5 ) ;
}
return V_196 ;
}
static T_2
F_73 ( struct V_197 * V_198 , struct V_199 * V_200 )
{
struct V_15 * V_17 =
F_68 ( V_198 , F_69 ( * V_17 ) , V_20 ) ;
struct V_1 * V_6 ;
struct V_201 * V_20 ;
int V_32 ;
V_6 = F_1 ( & V_17 -> V_55 , V_31 ) ;
if ( ! V_6 || ! ( V_20 = V_6 -> V_20 ) )
return - V_28 ;
if ( F_74 ( V_200 -> V_202 > 16 ) )
return - V_203 ;
if ( V_200 -> V_202 == 0 )
return V_200 -> V_202 ;
V_32 = F_75 ( V_20 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_76 ( V_20 , false , V_200 -> V_204 , V_200 -> V_205 ,
V_200 -> V_206 , V_200 -> V_202 ) ;
F_77 ( V_20 ) ;
if ( V_32 >= 0 ) {
V_200 -> V_207 = V_32 ;
return V_200 -> V_202 ;
}
return V_32 ;
}
static int
F_78 ( enum V_208 V_14 )
{
switch ( V_14 ) {
case V_209 : return V_210 ;
case V_211 :
case V_212 :
case V_213 : return V_214 ;
case V_215 :
case V_216 :
case V_54 : return V_217 ;
case V_218 : return V_219 ;
case V_101 :
case V_102 : return V_159 ;
case V_220 :
case V_221 :
case V_222 : return V_223 ;
case V_29 : return V_224 ;
case V_225 :
case V_226 :
case V_227 : return V_228 ;
default:
break;
}
return V_229 ;
}
struct V_2 *
F_79 ( struct V_4 * V_5 , int V_230 )
{
const struct V_231 * V_232 = & V_233 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_93 * V_94 = V_93 ( V_5 ) ;
struct V_15 * V_17 = NULL ;
struct V_2 * V_3 ;
int type , V_32 = 0 ;
bool V_234 ;
F_5 (connector, &dev->mode_config.connector_list, head) {
V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_230 == V_230 )
return V_3 ;
}
V_17 = F_80 ( sizeof( * V_17 ) , V_44 ) ;
if ( ! V_17 )
return F_81 ( - V_235 ) ;
V_3 = & V_17 -> V_55 ;
V_17 -> V_230 = V_230 ;
V_17 -> V_14 = F_82 ( V_5 , V_230 ) ;
if ( V_17 -> V_14 ) {
T_3 V_236 = F_83 ( V_17 -> V_14 [ 0 ] ) ;
if ( F_84 ( V_5 ) [ 3 ] >= 4 )
V_236 |= ( T_3 ) F_83 ( V_17 -> V_14 [ 2 ] ) << 16 ;
V_17 -> type = V_17 -> V_14 [ 0 ] ;
if ( F_78 ( V_17 -> type ) ==
V_229 ) {
F_85 ( V_23 , L_10 ,
V_17 -> type ) ;
V_17 -> type = V_237 ;
}
if ( F_86 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_17 -> type == V_226 )
V_17 -> type = V_54 ;
}
if ( F_86 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_17 -> type == V_226 )
V_17 -> type = V_54 ;
}
} else {
V_17 -> type = V_237 ;
}
if ( V_17 -> type == V_237 ) {
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_238 * V_239 = & V_23 -> V_79 . V_14 ;
T_3 V_240 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_239 -> V_241 ; V_9 ++ ) {
if ( V_239 -> V_236 [ V_9 ] . V_3 == V_17 -> V_230 )
V_240 |= ( 1 << V_239 -> V_236 [ V_9 ] . type ) ;
}
if ( V_240 & ( 1 << V_31 ) ) {
if ( V_240 & ( 1 << V_38 ) )
V_17 -> type = V_222 ;
else
V_17 -> type = V_29 ;
} else
if ( V_240 & ( 1 << V_38 ) ) {
if ( V_240 & ( 1 << V_39 ) )
V_17 -> type = V_54 ;
else
V_17 -> type = V_218 ;
} else
if ( V_240 & ( 1 << V_39 ) ) {
V_17 -> type = V_209 ;
} else
if ( V_240 & ( 1 << V_51 ) ) {
V_17 -> type = V_101 ;
} else
if ( V_240 & ( 1 << V_73 ) ) {
V_17 -> type = V_211 ;
}
}
switch ( ( type = F_78 ( V_17 -> type ) ) ) {
case V_159 :
V_32 = F_87 ( V_5 , 0 , & V_234 , & V_234 ) ;
if ( V_32 ) {
F_32 ( V_23 , L_11 ) ;
F_8 ( V_17 ) ;
return F_81 ( V_32 ) ;
}
V_232 = & V_242 ;
break;
case V_223 :
case V_224 :
V_17 -> V_20 . V_5 = V_5 -> V_5 ;
V_17 -> V_20 . V_21 = F_73 ;
V_32 = F_88 ( & V_17 -> V_20 ) ;
if ( V_32 ) {
F_32 ( V_23 , L_12 ) ;
F_8 ( V_17 ) ;
return F_81 ( V_32 ) ;
}
V_232 = & V_243 ;
break;
default:
V_232 = & V_233 ;
break;
}
V_3 -> V_49 = false ;
V_3 -> V_50 = false ;
F_89 ( V_5 , V_3 , V_232 , type ) ;
F_90 ( V_3 , & V_244 ) ;
if ( V_17 -> type == V_54 )
F_91 ( & V_3 -> V_55 , V_5 -> V_56 . V_57 , 0 ) ;
if ( V_94 -> V_114 &&
( type == V_219 ||
type == V_217 ||
type == V_228 ||
type == V_223 ) ) {
F_91 ( & V_3 -> V_55 ,
V_94 -> V_114 ,
V_245 ) ;
F_91 ( & V_3 -> V_55 ,
V_94 -> V_116 ,
0 ) ;
F_91 ( & V_3 -> V_55 ,
V_94 -> V_118 ,
0 ) ;
}
if ( V_94 -> V_124 )
F_91 ( & V_3 -> V_55 ,
V_94 -> V_124 ,
90 ) ;
if ( V_94 -> V_126 )
F_91 ( & V_3 -> V_55 ,
V_94 -> V_126 ,
150 ) ;
switch ( V_17 -> type ) {
case V_101 :
case V_102 :
case V_29 :
if ( V_94 -> V_94 . V_103 < V_104 ) {
V_17 -> V_109 = V_106 ;
break;
}
V_17 -> V_109 = V_100 ;
break;
default:
V_17 -> V_109 = V_100 ;
break;
}
switch ( V_17 -> type ) {
case V_211 :
case V_212 :
case V_213 :
break;
case V_209 :
if ( V_94 -> V_94 . V_103 < V_104 )
break;
default:
F_91 ( & V_3 -> V_55 , V_5 -> V_56 .
V_98 ,
V_17 -> V_109 ) ;
break;
}
switch ( V_17 -> type ) {
case V_211 :
case V_212 :
case V_213 :
case V_209 :
break;
default:
if ( V_94 -> V_120 ) {
F_91 ( & V_3 -> V_55 ,
V_94 -> V_120 ,
V_17 ->
V_120 ) ;
V_17 -> V_120 = V_246 ;
}
if ( V_94 -> V_122 ) {
F_91 ( & V_3 -> V_55 ,
V_94 -> V_122 ,
V_17 ->
V_122 ) ;
V_17 -> V_122 = V_247 ;
}
break;
}
V_32 = F_92 (&disp->disp, nouveau_connector_hotplug, true,
NV04_DISP_NTFY_CONN,
&(struct nvif_notify_conn_req_v0) {
.mask = NVIF_NOTIFY_CONN_V0_ANY,
.conn = index,
},
sizeof(struct nvif_notify_conn_req_v0),
sizeof(struct nvif_notify_conn_rep_v0),
&nv_connector->hpd) ;
if ( V_32 )
V_3 -> V_248 = V_249 ;
else
V_3 -> V_248 = V_250 ;
F_93 ( V_3 ) ;
return V_3 ;
}
