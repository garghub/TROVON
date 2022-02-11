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
if ( type == V_14 ||
( V_6 -> V_15 && V_6 -> V_15 -> type == type ) )
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
F_8 ( NULL , & V_18 -> V_19 ) ;
F_9 ( V_18 -> V_20 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
if ( V_18 -> V_21 . V_22 )
F_12 ( & V_18 -> V_21 ) ;
F_9 ( V_3 ) ;
}
static struct V_1 *
F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_28 = - V_29 ;
if ( V_18 -> type == V_30 ) {
V_28 = V_26 -> V_31 ( V_26 , 0 , V_32 , 0xff ) ;
if ( V_28 == 0 ) {
V_26 -> V_33 ( V_26 , 0 , V_32 , 0xff , 1 ) ;
F_14 ( 300 ) ;
}
}
for ( V_9 = 0 ; V_6 = NULL , V_9 < V_11 ; V_9 ++ ) {
int V_10 = V_3 -> V_12 [ V_9 ] ;
if ( V_10 == 0 )
break;
V_8 = F_2 ( V_5 , V_10 , V_13 ) ;
if ( ! V_8 )
continue;
V_6 = V_1 ( F_3 ( V_8 ) ) ;
if ( V_6 -> V_15 -> type == V_34 ) {
int V_35 = F_15 ( V_6 ) ;
if ( V_35 == 0 )
break;
} else
if ( V_6 -> V_36 ) {
if ( F_16 ( V_6 -> V_36 , 0x50 ) )
break;
}
}
if ( ! V_6 && V_28 == 0 )
V_26 -> V_33 ( V_26 , 0 , V_32 , 0xff , V_28 ) ;
return V_6 ;
}
static struct V_1 *
F_17 ( struct V_2 * V_3 )
{
#ifdef F_18
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_37 * V_38 , * V_39 = F_19 ( V_5 -> V_40 ) ;
if ( ! V_39 ||
! ( ( V_6 = F_1 ( V_3 , V_41 ) ) ||
( V_6 = F_1 ( V_3 , V_42 ) ) ) )
return NULL ;
F_20 (dn, cn) {
const char * V_43 = F_21 ( V_38 , L_1 , NULL ) ;
const void * V_20 = F_21 ( V_38 , L_2 , NULL ) ;
int V_44 = V_43 ? V_43 [ strlen ( V_43 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_45 == V_44 && V_20 ) {
V_18 -> V_20 =
F_22 ( V_20 , V_46 , V_47 ) ;
F_23 ( V_38 ) ;
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
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_48 == V_6 )
return;
V_18 -> V_48 = V_6 ;
if ( F_25 ( V_24 -> V_27 ) -> V_49 >= V_50 ) {
V_3 -> V_51 = true ;
V_3 -> V_52 = true ;
} else
if ( V_6 -> V_15 -> type == V_53 ||
V_6 -> V_15 -> type == V_41 ) {
V_3 -> V_52 = false ;
V_3 -> V_51 = false ;
} else {
V_3 -> V_52 = true ;
if ( F_25 ( V_24 -> V_27 ) -> V_49 == V_54 ||
( ( F_25 ( V_24 -> V_27 ) -> V_49 == V_55 ||
F_25 ( V_24 -> V_27 ) -> V_49 == V_56 ) &&
( V_5 -> V_40 -> V_27 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_40 -> V_27 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_51 = false ;
else
V_3 -> V_51 = true ;
}
if ( V_18 -> type == V_57 ) {
F_26 ( & V_3 -> V_58 ,
V_5 -> V_59 . V_60 ,
V_6 -> V_15 -> type == V_41 ?
V_61 :
V_62 ) ;
}
}
static enum V_63
F_27 ( struct V_2 * V_3 , bool V_64 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_65 ;
struct V_66 * V_36 ;
int type ;
int V_35 ;
enum V_63 V_67 = V_68 ;
if ( V_18 -> V_20 ) {
F_28 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
V_35 = F_29 ( V_3 -> V_5 -> V_5 ) ;
if ( V_35 < 0 && V_35 != - V_69 )
return V_67 ;
V_6 = F_13 ( V_3 ) ;
if ( V_6 && ( V_36 = V_6 -> V_36 ) != NULL ) {
V_18 -> V_20 = F_30 ( V_3 , & V_36 -> V_70 ) ;
F_28 ( V_3 ,
V_18 -> V_20 ) ;
if ( ! V_18 -> V_20 ) {
F_31 ( V_24 , L_3 ,
V_3 -> V_43 ) ;
goto V_71;
}
V_65 = NULL ;
if ( V_6 -> V_15 -> type == V_41 )
V_65 = F_1 ( V_3 , V_42 ) ;
if ( V_6 -> V_15 -> type == V_42 )
V_65 = F_1 ( V_3 , V_41 ) ;
if ( V_65 && ( ( V_6 -> V_15 -> type == V_42 &&
V_65 -> V_15 -> type == V_41 ) ||
( V_6 -> V_15 -> type == V_41 &&
V_65 -> V_15 -> type == V_42 ) ) ) {
if ( V_18 -> V_20 -> V_72 & V_73 )
type = V_41 ;
else
type = V_42 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_24 ( V_3 , V_6 ) ;
V_67 = V_74 ;
goto V_75;
}
V_6 = F_17 ( V_3 ) ;
if ( V_6 ) {
F_24 ( V_3 , V_6 ) ;
V_67 = V_74 ;
goto V_75;
}
V_71:
V_6 = F_1 ( V_3 , V_42 ) ;
if ( ! V_6 && ! V_76 )
V_6 = F_1 ( V_3 , V_77 ) ;
if ( V_6 && V_64 ) {
struct V_78 * V_17 = F_5 ( V_6 ) ;
struct V_79 * V_80 =
V_17 -> V_81 ;
if ( V_80 -> V_82 ( V_17 , V_3 ) ==
V_74 ) {
F_24 ( V_3 , V_6 ) ;
V_67 = V_74 ;
goto V_75;
}
}
V_75:
F_32 ( V_3 -> V_5 -> V_5 ) ;
F_33 ( V_3 -> V_5 -> V_5 ) ;
return V_67 ;
}
static enum V_63
F_34 ( struct V_2 * V_3 , bool V_64 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_63 V_83 = V_68 ;
if ( V_18 -> V_20 ) {
F_28 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
V_6 = F_1 ( V_3 , V_53 ) ;
if ( ! V_6 )
return V_68 ;
if ( ! V_24 -> V_84 . V_85 ) {
V_83 = F_27 ( V_3 , V_64 ) ;
if ( V_83 == V_74 )
goto V_75;
}
if ( V_6 -> V_15 -> V_86 . V_87 ) {
if ( ( V_18 -> V_20 = F_35 ( V_5 , V_3 ) ) ) {
V_83 = V_74 ;
goto V_75;
}
}
if ( F_36 ( V_5 , NULL ) && ( V_24 -> V_84 . V_85 ||
V_6 -> V_15 -> V_86 . V_88 ) ) {
V_83 = V_74 ;
goto V_75;
}
if ( ! V_24 -> V_84 . V_85 ) {
struct V_20 * V_20 =
(struct V_20 * ) F_37 ( V_5 ) ;
if ( V_20 ) {
V_18 -> V_20 =
F_22 ( V_20 , V_46 , V_47 ) ;
if ( V_18 -> V_20 )
V_83 = V_74 ;
}
}
V_75:
#if F_38 ( V_89 ) || \
( F_38 ( V_90 ) && F_38 ( V_91 ) )
if ( V_83 == V_74 &&
! V_92 && ! F_39 () )
V_83 = V_93 ;
#endif
F_28 ( V_3 , V_18 -> V_20 ) ;
F_24 ( V_3 , V_6 ) ;
return V_83 ;
}
static void
F_40 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_57 ) {
if ( V_3 -> V_64 == V_94 )
type = V_41 ;
else
type = V_42 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_31 ( V_24 , L_4 ,
V_3 -> V_43 ) ;
V_3 -> V_83 = V_68 ;
return;
}
F_24 ( V_3 , V_6 ) ;
}
static int
F_41 ( struct V_2 * V_3 ,
struct V_95 * V_96 , T_1 V_97 )
{
struct V_98 * V_99 = V_98 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_100 * V_101 ;
int V_35 ;
V_101 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_102 )
V_101 = V_100 ( V_3 -> V_17 -> V_102 ) ;
if ( V_96 == V_5 -> V_59 . V_103 ) {
bool V_104 = false ;
switch ( V_97 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
break;
default:
return - V_109 ;
}
if ( V_3 -> V_110 == V_111 &&
V_97 == V_105 )
return - V_109 ;
if ( ( V_18 -> V_112 == V_105 ) ||
( V_97 == V_105 ) )
V_104 = true ;
V_18 -> V_112 = V_97 ;
if ( ! V_101 )
return 0 ;
if ( V_104 || ! V_101 -> V_113 ) {
V_35 = F_42 ( & V_101 -> V_58 ,
& V_101 -> V_58 . V_114 ,
V_101 -> V_58 . V_115 ,
V_101 -> V_58 . V_116 , NULL ) ;
if ( ! V_35 )
return - V_109 ;
} else {
V_35 = V_101 -> V_113 ( V_101 , true ) ;
if ( V_35 )
return V_35 ;
}
return 0 ;
}
if ( V_96 == V_99 -> V_117 ) {
if ( V_18 -> V_118 != V_97 ) {
V_18 -> V_118 = V_97 ;
if ( ! V_101 || ! V_101 -> V_113 )
return 0 ;
return V_101 -> V_113 ( V_101 , true ) ;
}
return 0 ;
}
if ( V_96 == V_99 -> V_119 ) {
if ( V_18 -> V_120 != V_97 ) {
V_18 -> V_120 = V_97 ;
if ( ! V_101 || ! V_101 -> V_113 )
return 0 ;
return V_101 -> V_113 ( V_101 , true ) ;
}
return 0 ;
}
if ( V_96 == V_99 -> V_121 ) {
if ( V_18 -> V_122 != V_97 ) {
V_18 -> V_122 = V_97 ;
if ( ! V_101 || ! V_101 -> V_113 )
return 0 ;
return V_101 -> V_113 ( V_101 , true ) ;
}
return 0 ;
}
if ( V_96 == V_99 -> V_123 ) {
V_18 -> V_123 = V_97 ;
if ( ! V_101 || ! V_101 -> V_124 )
return 0 ;
return V_101 -> V_124 ( V_101 , true ) ;
}
if ( V_96 == V_99 -> V_125 ) {
V_18 -> V_125 = V_97 ;
if ( ! V_101 || ! V_101 -> V_124 )
return 0 ;
return V_101 -> V_124 ( V_101 , true ) ;
}
if ( V_101 && V_101 -> V_126 ) {
if ( V_96 == V_99 -> V_127 ) {
V_101 -> V_128 = V_97 - 90 ;
return V_101 -> V_126 ( V_101 , true ) ;
}
if ( V_96 == V_99 -> V_129 ) {
V_101 -> V_130 = V_97 - 100 ;
return V_101 -> V_126 ( V_101 , true ) ;
}
}
if ( V_6 && V_6 -> V_15 -> type == V_77 )
return F_43 ( V_17 ) -> F_44 (
V_17 , V_3 , V_96 , V_97 ) ;
return - V_109 ;
}
static struct V_131 *
F_45 ( struct V_2 * V_3 )
{
struct V_132 * V_80 = V_3 -> V_81 ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_131 * V_114 , * V_133 = NULL ;
int V_134 = 0 , V_135 = 0 , V_136 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_114 -> V_137 = F_46 ( V_114 ) ;
if ( V_80 -> V_138 ( V_3 , V_114 ) != V_139 ||
( V_114 -> V_140 & V_141 ) )
continue;
if ( V_114 -> type & V_142 ) {
F_47 ( V_24 , L_5 ) ;
return F_48 ( V_5 , V_114 ) ;
}
if ( V_114 -> V_143 < V_134 )
continue;
if ( V_114 -> V_143 == V_134 && V_114 -> V_144 < V_135 )
continue;
if ( V_114 -> V_143 == V_134 && V_114 -> V_144 == V_135 &&
V_114 -> V_137 < V_136 )
continue;
V_134 = V_114 -> V_143 ;
V_135 = V_114 -> V_144 ;
V_136 = V_114 -> V_137 ;
V_133 = V_114 ;
}
F_47 ( V_24 , L_6 ,
V_134 , V_135 , V_136 ) ;
return V_133 ? F_48 ( V_5 , V_133 ) : NULL ;
}
static int
F_49 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_131 * V_145 = V_18 -> V_146 , * V_147 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_148 * V_114 = & V_149 [ 0 ] ;
int V_150 = 0 ;
if ( ! V_145 )
return 0 ;
while ( V_114 -> V_143 ) {
if ( V_114 -> V_143 <= V_145 -> V_143 &&
V_114 -> V_144 <= V_145 -> V_144 ) {
V_147 = F_50 ( V_5 , V_114 -> V_143 , V_114 -> V_144 ,
F_46 ( V_145 ) , false ,
false , false ) ;
if ( ! V_147 )
continue;
V_147 -> type |= V_151 ;
F_51 ( V_3 , V_147 ) ;
V_150 ++ ;
}
V_114 ++ ;
}
return V_150 ;
}
static void
F_52 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_152 * V_153 = & V_24 -> V_84 ;
struct V_131 * V_114 = V_18 -> V_146 ;
bool V_154 ;
if ( V_18 -> V_20 && V_3 -> V_155 . V_156 )
return;
if ( V_18 -> type == V_30 ) {
V_3 -> V_155 . V_156 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_53 ) {
V_3 -> V_155 . V_156 = 8 ;
return;
}
V_3 -> V_155 . V_156 = 6 ;
if ( V_153 -> V_85 ) {
if ( V_153 -> V_157 . V_158 )
V_3 -> V_155 . V_156 = 8 ;
return;
}
if ( V_18 -> V_20 &&
V_18 -> type == V_159 )
V_154 = ( ( V_160 * ) V_18 -> V_20 ) [ 121 ] == 2 ;
else
V_154 = V_114 -> clock >= V_153 -> V_157 . V_161 ;
if ( ( ! V_154 && ( V_153 -> V_157 . V_162 & 1 ) ) ||
( V_154 && ( V_153 -> V_157 . V_162 & 2 ) ) )
V_3 -> V_155 . V_156 = 8 ;
}
static int
F_53 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
int V_35 = 0 ;
if ( V_18 -> V_146 ) {
F_54 ( V_5 , V_18 -> V_146 ) ;
V_18 -> V_146 = NULL ;
}
if ( V_18 -> V_20 )
V_35 = F_55 ( V_3 , V_18 -> V_20 ) ;
else
if ( V_6 -> V_15 -> type == V_53 &&
( V_6 -> V_15 -> V_86 . V_88 ||
V_24 -> V_84 . V_85 ) && F_36 ( V_5 , NULL ) ) {
struct V_131 V_114 ;
F_36 ( V_5 , & V_114 ) ;
V_18 -> V_146 = F_48 ( V_5 , & V_114 ) ;
}
if ( V_3 -> V_110 != V_111 )
F_52 ( V_3 ) ;
if ( ! V_18 -> V_146 )
V_18 -> V_146 =
F_45 ( V_3 ) ;
if ( V_35 == 0 && V_18 -> V_146 ) {
struct V_131 * V_114 ;
V_114 = F_48 ( V_5 , V_18 -> V_146 ) ;
F_51 ( V_3 , V_114 ) ;
V_35 = 1 ;
}
if ( V_3 -> V_110 == V_111 )
F_52 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_77 )
V_35 = F_43 ( V_17 ) -> F_56 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_163 ||
V_18 -> type == V_159 ||
V_18 -> type == V_30 )
V_35 += F_49 ( V_3 ) ;
return V_35 ;
}
static unsigned
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_164 * V_15 = V_18 -> V_48 -> V_15 ;
if ( V_15 -> V_165 != V_166 ||
F_25 ( V_24 -> V_27 ) -> V_167 >= 0x46 )
return 165000 ;
else if ( F_25 ( V_24 -> V_27 ) -> V_167 >= 0x40 )
return 155000 ;
else if ( F_25 ( V_24 -> V_27 ) -> V_167 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_58 ( struct V_2 * V_3 ,
struct V_131 * V_114 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_48 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
unsigned V_168 = 25000 , V_169 = V_168 ;
unsigned clock = V_114 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_53 :
if ( V_18 -> V_146 &&
( V_114 -> V_143 > V_18 -> V_146 -> V_143 ||
V_114 -> V_144 > V_18 -> V_146 -> V_144 ) )
return V_170 ;
V_168 = 0 ;
V_169 = 400000 ;
break;
case V_41 :
V_169 = F_57 ( V_3 ) ;
if ( V_171 && V_6 -> V_15 -> V_172 )
V_169 *= 2 ;
break;
case V_42 :
V_169 = V_6 -> V_15 -> V_173 . V_174 ;
if ( ! V_169 )
V_169 = 350000 ;
break;
case V_77 :
return F_43 ( V_17 ) -> V_138 ( V_17 , V_114 ) ;
case V_34 :
V_169 = V_6 -> V_175 . V_176 ;
V_169 *= V_6 -> V_175 . V_177 ;
clock = clock * ( V_3 -> V_155 . V_156 * 3 ) / 10 ;
break;
default:
F_59 ( 1 ) ;
return V_178 ;
}
if ( clock < V_168 )
return V_179 ;
if ( clock > V_169 )
return V_180 ;
return V_139 ;
}
static struct V_78 *
F_60 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_48 )
return F_5 ( V_18 -> V_48 ) ;
return NULL ;
}
static void
F_61 ( struct V_2 * V_3 , int V_114 )
{
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_17 )
V_6 = V_1 ( V_3 -> V_17 ) ;
if ( V_6 && V_6 -> V_15 &&
V_6 -> V_15 -> type == V_34 ) {
if ( V_114 == V_181 ) {
V_160 V_182 = V_183 ;
F_62 ( V_6 -> V_36 , V_184 , & V_182 , 1 ) ;
F_63 ( 1000 , 2000 ) ;
} else {
V_160 V_182 = V_185 ;
F_62 ( V_6 -> V_36 , V_184 , & V_182 , 1 ) ;
}
}
F_64 ( V_3 , V_114 ) ;
}
static void
F_65 ( struct V_186 * V_187 )
{
struct V_16 * V_18 =
F_66 ( V_187 , F_67 ( * V_18 ) , V_187 ) ;
struct V_2 * V_3 = & V_18 -> V_58 ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
const char * V_43 = V_3 -> V_43 ;
if ( V_18 -> V_83 & V_188 ) {
} else {
bool V_189 = ( V_18 -> V_83 != V_190 ) ;
F_47 ( V_24 , L_7 , V_189 ? L_8 : L_9 , V_43 ) ;
if ( V_189 )
F_64 ( V_3 , V_181 ) ;
else
F_64 ( V_3 , V_191 ) ;
F_68 ( V_3 -> V_5 ) ;
}
F_69 ( V_18 -> V_19 ) ;
}
static int
F_70 ( void * V_182 , T_2 type , int V_192 )
{
struct V_16 * V_18 = V_182 ;
V_18 -> V_83 = type ;
F_71 ( & V_18 -> V_187 ) ;
return V_193 ;
}
static T_3
F_72 ( struct V_194 * V_21 , struct V_195 * V_196 )
{
struct V_16 * V_18 =
F_66 ( V_21 , F_67 ( * V_18 ) , V_21 ) ;
struct V_1 * V_6 ;
struct V_66 * V_197 ;
int V_35 ;
V_6 = F_1 ( & V_18 -> V_58 , V_34 ) ;
if ( ! V_6 || ! ( V_197 = V_6 -> V_36 ) )
return - V_29 ;
if ( F_73 ( V_196 -> V_198 > 16 ) )
return - V_199 ;
if ( V_196 -> V_198 == 0 )
return V_196 -> V_198 ;
V_35 = F_74 ( V_197 ) -> F_75 ( V_197 , 0 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_197 -> V_200 -> V_21 ( V_197 , false , V_196 -> V_201 , V_196 -> V_202 ,
V_196 -> V_203 , V_196 -> V_198 ) ;
F_74 ( V_197 ) -> F_76 ( V_197 ) ;
if ( V_35 >= 0 ) {
V_196 -> V_204 = V_35 ;
return V_196 -> V_198 ;
}
return V_35 ;
}
static int
F_77 ( enum V_205 V_15 )
{
switch ( V_15 ) {
case V_206 : return V_207 ;
case V_208 :
case V_209 :
case V_210 : return V_211 ;
case V_212 :
case V_213 :
case V_57 : return V_214 ;
case V_215 : return V_216 ;
case V_163 :
case V_159 : return V_111 ;
case V_217 :
case V_218 :
case V_219 : return V_220 ;
case V_30 : return V_221 ;
case V_222 :
case V_223 :
case V_224 : return V_225 ;
default:
break;
}
return V_226 ;
}
struct V_2 *
F_78 ( struct V_4 * V_5 , int V_192 )
{
const struct V_227 * V_228 = & V_229 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_98 * V_99 = V_98 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_230 * V_231 = V_230 ( V_24 -> V_27 ) ;
struct V_2 * V_3 ;
int type , V_35 = 0 ;
bool V_232 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_192 == V_192 )
return V_3 ;
}
V_18 = F_79 ( sizeof( * V_18 ) , V_47 ) ;
if ( ! V_18 )
return F_80 ( - V_233 ) ;
V_3 = & V_18 -> V_58 ;
V_18 -> V_192 = V_192 ;
V_18 -> V_15 = F_81 ( V_5 , V_192 ) ;
if ( V_18 -> V_15 ) {
T_2 V_234 = F_82 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_83 ( V_5 ) [ 3 ] >= 4 )
V_234 |= ( T_2 ) F_82 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_77 ( V_18 -> type ) ==
V_226 ) {
F_84 ( V_24 , L_10 ,
V_18 -> type ) ;
V_18 -> type = V_235 ;
}
if ( F_85 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_223 )
V_18 -> type = V_57 ;
}
if ( F_85 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_223 )
V_18 -> type = V_57 ;
}
} else {
V_18 -> type = V_235 ;
}
if ( V_18 -> type == V_235 ) {
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_236 * V_237 = & V_24 -> V_84 . V_15 ;
T_2 V_238 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_237 -> V_239 ; V_9 ++ ) {
if ( V_237 -> V_234 [ V_9 ] . V_3 == V_18 -> V_192 )
V_238 |= ( 1 << V_237 -> V_234 [ V_9 ] . type ) ;
}
if ( V_238 & ( 1 << V_34 ) ) {
if ( V_238 & ( 1 << V_41 ) )
V_18 -> type = V_219 ;
else
V_18 -> type = V_30 ;
} else
if ( V_238 & ( 1 << V_41 ) ) {
if ( V_238 & ( 1 << V_42 ) )
V_18 -> type = V_57 ;
else
V_18 -> type = V_215 ;
} else
if ( V_238 & ( 1 << V_42 ) ) {
V_18 -> type = V_206 ;
} else
if ( V_238 & ( 1 << V_53 ) ) {
V_18 -> type = V_163 ;
} else
if ( V_238 & ( 1 << V_77 ) ) {
V_18 -> type = V_208 ;
}
}
switch ( ( type = F_77 ( V_18 -> type ) ) ) {
case V_111 :
V_35 = F_86 ( V_5 , 0 , & V_232 , & V_232 ) ;
if ( V_35 ) {
F_31 ( V_24 , L_11 ) ;
F_9 ( V_18 ) ;
return F_80 ( V_35 ) ;
}
V_228 = & V_240 ;
break;
case V_220 :
case V_221 :
V_18 -> V_21 . V_5 = V_5 -> V_5 ;
V_18 -> V_21 . V_22 = F_72 ;
V_35 = F_87 ( & V_18 -> V_21 ) ;
if ( V_35 ) {
F_31 ( V_24 , L_12 ) ;
F_9 ( V_18 ) ;
return F_80 ( V_35 ) ;
}
V_228 = & V_241 ;
break;
default:
V_228 = & V_229 ;
break;
}
V_3 -> V_51 = false ;
V_3 -> V_52 = false ;
F_88 ( V_5 , V_3 , V_228 , type ) ;
F_89 ( V_3 , & V_242 ) ;
if ( V_18 -> type == V_57 )
F_90 ( & V_3 -> V_58 , V_5 -> V_59 . V_60 , 0 ) ;
if ( V_99 -> V_117 &&
( type == V_216 ||
type == V_214 ||
type == V_225 ||
type == V_220 ) ) {
F_90 ( & V_3 -> V_58 ,
V_99 -> V_117 ,
V_243 ) ;
F_90 ( & V_3 -> V_58 ,
V_99 -> V_119 ,
0 ) ;
F_90 ( & V_3 -> V_58 ,
V_99 -> V_121 ,
0 ) ;
}
if ( V_99 -> V_127 )
F_90 ( & V_3 -> V_58 ,
V_99 -> V_127 ,
90 ) ;
if ( V_99 -> V_129 )
F_90 ( & V_3 -> V_58 ,
V_99 -> V_129 ,
150 ) ;
switch ( V_18 -> type ) {
case V_206 :
if ( F_25 ( V_24 -> V_27 ) -> V_49 >= V_50 ) {
F_90 ( & V_3 -> V_58 ,
V_5 -> V_59 . V_103 ,
V_18 -> V_112 ) ;
}
case V_208 :
case V_209 :
case V_210 :
V_18 -> V_112 = V_105 ;
break;
default:
V_18 -> V_112 = V_106 ;
F_90 ( & V_3 -> V_58 ,
V_5 -> V_59 . V_103 ,
V_18 -> V_112 ) ;
if ( V_99 -> V_123 ) {
V_18 -> V_123 = V_244 ;
F_90 ( & V_3 -> V_58 ,
V_99 -> V_123 ,
V_18 -> V_123 ) ;
}
if ( V_99 -> V_125 ) {
V_18 -> V_125 = V_245 ;
F_90 ( & V_3 -> V_58 ,
V_99 -> V_125 ,
V_18 -> V_125 ) ;
}
break;
}
V_35 = F_91 ( V_231 -> V_19 , V_246 , V_192 ,
F_70 ,
V_18 , & V_18 -> V_19 ) ;
if ( V_35 )
V_3 -> V_247 = V_248 ;
else
V_3 -> V_247 = V_249 ;
F_92 ( & V_18 -> V_187 , F_65 ) ;
F_93 ( V_3 ) ;
return V_3 ;
}
