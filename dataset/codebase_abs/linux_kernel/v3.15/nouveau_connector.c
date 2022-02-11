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
F_8 ( NULL , & V_18 -> V_19 ) ;
F_9 ( V_18 -> V_20 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static struct V_21 *
F_12 ( struct V_2 * V_3 ,
struct V_1 * * V_22 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
struct V_21 * V_28 = NULL ;
int V_9 , V_29 = - V_30 ;
if ( V_18 -> type == V_31 ) {
V_29 = V_26 -> V_32 ( V_26 , 0 , V_33 , 0xff ) ;
if ( V_29 == 0 ) {
V_26 -> V_34 ( V_26 , 0 , V_33 , 0xff , 1 ) ;
F_13 ( 300 ) ;
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
V_28 = V_6 -> V_35 ;
if ( V_28 && F_14 ( V_28 , 0x50 ) ) {
* V_22 = V_6 ;
break;
}
V_28 = NULL ;
}
if ( ! V_28 && V_29 == 0 )
V_26 -> V_34 ( V_26 , 0 , V_33 , 0xff , V_29 ) ;
return V_28 ;
}
static struct V_1 *
F_15 ( struct V_2 * V_3 )
{
#ifdef F_16
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_36 * V_37 , * V_38 = F_17 ( V_5 -> V_39 ) ;
if ( ! V_38 ||
! ( ( V_6 = F_1 ( V_3 , V_40 ) ) ||
( V_6 = F_1 ( V_3 , V_41 ) ) ) )
return NULL ;
F_18 (dn, cn) {
const char * V_42 = F_19 ( V_37 , L_1 , NULL ) ;
const void * V_20 = F_19 ( V_37 , L_2 , NULL ) ;
int V_43 = V_42 ? V_42 [ strlen ( V_42 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_15 -> V_44 == V_43 && V_20 ) {
V_18 -> V_20 =
F_20 ( V_20 , V_45 , V_46 ) ;
F_21 ( V_37 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_22 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_18 -> V_47 == V_6 )
return;
V_18 -> V_47 = V_6 ;
if ( F_23 ( V_24 -> V_27 ) -> V_48 >= V_49 ) {
V_3 -> V_50 = true ;
V_3 -> V_51 = true ;
} else
if ( V_6 -> V_15 -> type == V_52 ||
V_6 -> V_15 -> type == V_40 ) {
V_3 -> V_51 = false ;
V_3 -> V_50 = false ;
} else {
V_3 -> V_51 = true ;
if ( F_23 ( V_24 -> V_27 ) -> V_48 == V_53 ||
( ( F_23 ( V_24 -> V_27 ) -> V_48 == V_54 ||
F_23 ( V_24 -> V_27 ) -> V_48 == V_55 ) &&
( V_5 -> V_39 -> V_27 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_39 -> V_27 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_50 = false ;
else
V_3 -> V_50 = true ;
}
if ( V_18 -> type == V_56 ) {
F_24 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_59 ,
V_6 -> V_15 -> type == V_40 ?
V_60 :
V_61 ) ;
}
}
static enum V_62
F_25 ( struct V_2 * V_3 , bool V_63 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_64 ;
struct V_21 * V_35 ;
int type ;
int V_65 ;
enum V_62 V_66 = V_67 ;
if ( V_18 -> V_20 ) {
F_26 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
V_65 = F_27 ( V_3 -> V_5 -> V_5 ) ;
if ( V_65 < 0 && V_65 != - V_68 )
return V_66 ;
V_35 = F_12 ( V_3 , & V_6 ) ;
if ( V_35 ) {
V_18 -> V_20 = F_28 ( V_3 , & V_35 -> V_69 ) ;
F_26 ( V_3 ,
V_18 -> V_20 ) ;
if ( ! V_18 -> V_20 ) {
F_29 ( V_24 , L_3 ,
F_30 ( V_3 ) ) ;
goto V_70;
}
if ( V_6 -> V_15 -> type == V_71 &&
! F_31 ( F_5 ( V_6 ) ) ) {
F_29 ( V_24 , L_4 ,
F_30 ( V_3 ) ) ;
V_66 = V_67 ;
goto V_72;
}
V_64 = NULL ;
if ( V_6 -> V_15 -> type == V_40 )
V_64 = F_1 ( V_3 , V_41 ) ;
if ( V_6 -> V_15 -> type == V_41 )
V_64 = F_1 ( V_3 , V_40 ) ;
if ( V_64 && ( ( V_6 -> V_15 -> type == V_41 &&
V_64 -> V_15 -> type == V_40 ) ||
( V_6 -> V_15 -> type == V_40 &&
V_64 -> V_15 -> type == V_41 ) ) ) {
if ( V_18 -> V_20 -> V_73 & V_74 )
type = V_40 ;
else
type = V_41 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_22 ( V_3 , V_6 ) ;
V_66 = V_75 ;
goto V_72;
}
V_6 = F_15 ( V_3 ) ;
if ( V_6 ) {
F_22 ( V_3 , V_6 ) ;
V_66 = V_75 ;
goto V_72;
}
V_70:
V_6 = F_1 ( V_3 , V_41 ) ;
if ( ! V_6 && ! V_76 )
V_6 = F_1 ( V_3 , V_77 ) ;
if ( V_6 && V_63 ) {
struct V_78 * V_17 = F_5 ( V_6 ) ;
struct V_79 * V_80 =
V_17 -> V_81 ;
if ( V_80 -> V_82 ( V_17 , V_3 ) ==
V_75 ) {
F_22 ( V_3 , V_6 ) ;
V_66 = V_75 ;
goto V_72;
}
}
V_72:
F_32 ( V_3 -> V_5 -> V_5 ) ;
F_33 ( V_3 -> V_5 -> V_5 ) ;
return V_66 ;
}
static enum V_62
F_34 ( struct V_2 * V_3 , bool V_63 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_62 V_83 = V_67 ;
if ( V_18 -> V_20 ) {
F_26 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
V_6 = F_1 ( V_3 , V_52 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_24 -> V_84 . V_85 ) {
V_83 = F_25 ( V_3 , V_63 ) ;
if ( V_83 == V_75 )
goto V_72;
}
if ( V_6 -> V_15 -> V_86 . V_87 ) {
if ( ( V_18 -> V_20 = F_35 ( V_5 , V_3 ) ) ) {
V_83 = V_75 ;
goto V_72;
}
}
if ( F_36 ( V_5 , NULL ) && ( V_24 -> V_84 . V_85 ||
V_6 -> V_15 -> V_86 . V_88 ) ) {
V_83 = V_75 ;
goto V_72;
}
if ( ! V_24 -> V_84 . V_85 ) {
struct V_20 * V_20 =
(struct V_20 * ) F_37 ( V_5 ) ;
if ( V_20 ) {
V_18 -> V_20 =
F_20 ( V_20 , V_45 , V_46 ) ;
if ( V_18 -> V_20 )
V_83 = V_75 ;
}
}
V_72:
#if F_38 ( V_89 ) || \
( F_38 ( V_90 ) && F_38 ( V_91 ) )
if ( V_83 == V_75 &&
! V_92 && ! F_39 () )
V_83 = V_93 ;
#endif
F_26 ( V_3 , V_18 -> V_20 ) ;
F_22 ( V_3 , V_6 ) ;
return V_83 ;
}
static void
F_40 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_56 ) {
if ( V_3 -> V_63 == V_94 )
type = V_40 ;
else
type = V_41 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_29 ( V_24 , L_5 ,
F_30 ( V_3 ) ) ;
V_3 -> V_83 = V_67 ;
return;
}
F_22 ( V_3 , V_6 ) ;
}
static int
F_41 ( struct V_2 * V_3 ,
struct V_95 * V_96 , T_1 V_97 )
{
struct V_98 * V_99 = V_98 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_100 * V_101 ;
int V_65 ;
V_101 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_102 )
V_101 = V_100 ( V_3 -> V_17 -> V_102 ) ;
if ( V_96 == V_5 -> V_58 . V_103 ) {
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
V_65 = F_42 ( & V_101 -> V_57 ,
& V_101 -> V_57 . V_114 ,
V_101 -> V_57 . V_115 ,
V_101 -> V_57 . V_116 , NULL ) ;
if ( ! V_65 )
return - V_109 ;
} else {
V_65 = V_101 -> V_113 ( V_101 , true ) ;
if ( V_65 )
return V_65 ;
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
F_47 ( V_24 , L_6 ) ;
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
F_47 ( V_24 , L_7 ,
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
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_152 * V_153 = & V_24 -> V_84 ;
struct V_131 * V_114 = V_18 -> V_146 ;
bool V_154 ;
if ( V_18 -> V_20 && V_3 -> V_155 . V_156 )
return;
if ( V_18 -> type == V_31 ) {
V_3 -> V_155 . V_156 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_52 ) {
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
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
int V_65 = 0 ;
if ( V_18 -> V_146 ) {
F_54 ( V_5 , V_18 -> V_146 ) ;
V_18 -> V_146 = NULL ;
}
if ( V_18 -> V_20 )
V_65 = F_55 ( V_3 , V_18 -> V_20 ) ;
else
if ( V_6 -> V_15 -> type == V_52 &&
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
if ( V_65 == 0 && V_18 -> V_146 ) {
struct V_131 * V_114 ;
V_114 = F_48 ( V_5 , V_18 -> V_146 ) ;
F_51 ( V_3 , V_114 ) ;
V_65 = 1 ;
}
if ( V_3 -> V_110 == V_111 )
F_52 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_77 )
V_65 = F_43 ( V_17 ) -> F_56 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_163 ||
V_18 -> type == V_159 ||
V_18 -> type == V_31 )
V_65 += F_49 ( V_3 ) ;
return V_65 ;
}
static unsigned
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_164 * V_15 = V_18 -> V_47 -> V_15 ;
if ( V_15 -> V_165 != V_166 ||
F_23 ( V_24 -> V_27 ) -> V_167 >= 0x46 )
return 165000 ;
else if ( F_23 ( V_24 -> V_27 ) -> V_167 >= 0x40 )
return 155000 ;
else if ( F_23 ( V_24 -> V_27 ) -> V_167 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_58 ( struct V_2 * V_3 ,
struct V_131 * V_114 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_78 * V_17 = F_5 ( V_6 ) ;
unsigned V_168 = 25000 , V_169 = V_168 ;
unsigned clock = V_114 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_52 :
if ( V_18 -> V_146 &&
( V_114 -> V_143 > V_18 -> V_146 -> V_143 ||
V_114 -> V_144 > V_18 -> V_146 -> V_144 ) )
return V_170 ;
V_168 = 0 ;
V_169 = 400000 ;
break;
case V_40 :
V_169 = F_57 ( V_3 ) ;
if ( V_171 && V_6 -> V_15 -> V_172 )
V_169 *= 2 ;
break;
case V_41 :
V_169 = V_6 -> V_15 -> V_173 . V_174 ;
if ( ! V_169 )
V_169 = 350000 ;
break;
case V_77 :
return F_43 ( V_17 ) -> V_138 ( V_17 , V_114 ) ;
case V_71 :
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
if ( V_18 -> V_47 )
return F_5 ( V_18 -> V_47 ) ;
return NULL ;
}
static void
F_61 ( struct V_181 * V_182 )
{
struct V_16 * V_18 =
F_62 ( V_182 , struct V_16 , V_183 ) ;
struct V_2 * V_3 = & V_18 -> V_57 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
bool V_184 = V_26 -> V_32 ( V_26 , 0 , V_18 -> V_185 . V_186 , 0xff ) ;
F_47 ( V_24 , L_8 , V_184 ? L_9 : L_10 ,
F_30 ( V_3 ) ) ;
if ( V_184 )
F_63 ( V_3 , V_187 ) ;
else
F_63 ( V_3 , V_188 ) ;
F_64 ( V_5 ) ;
}
static int
F_65 ( void * V_189 , int V_190 )
{
struct V_16 * V_18 = V_189 ;
F_66 ( & V_18 -> V_183 ) ;
return V_191 ;
}
static int
F_67 ( enum V_192 V_15 )
{
switch ( V_15 ) {
case V_193 : return V_194 ;
case V_195 :
case V_196 :
case V_197 : return V_198 ;
case V_199 :
case V_200 :
case V_56 : return V_201 ;
case V_202 : return V_203 ;
case V_163 :
case V_159 : return V_111 ;
case V_204 :
case V_205 :
case V_206 : return V_207 ;
case V_31 : return V_208 ;
case V_209 :
case V_210 :
case V_211 : return V_212 ;
default:
break;
}
return V_213 ;
}
struct V_2 *
F_68 ( struct V_4 * V_5 , int V_190 )
{
const struct V_214 * V_215 = & V_216 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
struct V_98 * V_99 = V_98 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_65 = 0 ;
bool V_217 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_190 == V_190 )
return V_3 ;
}
V_18 = F_69 ( sizeof( * V_18 ) , V_46 ) ;
if ( ! V_18 )
return F_70 ( - V_218 ) ;
V_3 = & V_18 -> V_57 ;
F_71 ( & V_18 -> V_183 , F_61 ) ;
V_18 -> V_190 = V_190 ;
V_18 -> V_15 = F_72 ( V_5 , V_190 ) ;
if ( V_18 -> V_15 ) {
static const V_160 V_185 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_219 = F_73 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_74 ( V_5 ) [ 3 ] >= 4 )
V_219 |= ( T_2 ) F_73 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_65 = V_26 -> V_220 ( V_26 , 0 , V_185 [ F_75 ( ( V_219 & 0x07033000 ) >> 12 ) ] ,
V_221 , & V_18 -> V_185 ) ;
if ( V_65 )
V_18 -> V_185 . V_186 = V_221 ;
if ( V_18 -> V_185 . V_186 != V_221 ) {
F_76 ( V_26 -> V_222 , V_18 -> V_185 . line ,
F_65 ,
V_18 ,
& V_18 -> V_19 ) ;
}
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_67 ( V_18 -> type ) ==
V_213 ) {
F_77 ( V_24 , L_11 ,
V_18 -> type ) ;
V_18 -> type = V_223 ;
}
if ( F_78 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_210 )
V_18 -> type = V_56 ;
}
if ( F_78 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_210 )
V_18 -> type = V_56 ;
}
} else {
V_18 -> type = V_223 ;
V_18 -> V_185 . V_186 = V_221 ;
}
if ( V_18 -> type == V_223 ) {
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_224 * V_225 = & V_24 -> V_84 . V_15 ;
T_2 V_226 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_225 -> V_227 ; V_9 ++ ) {
if ( V_225 -> V_219 [ V_9 ] . V_3 == V_18 -> V_190 )
V_226 |= ( 1 << V_225 -> V_219 [ V_9 ] . type ) ;
}
if ( V_226 & ( 1 << V_71 ) ) {
if ( V_226 & ( 1 << V_40 ) )
V_18 -> type = V_206 ;
else
V_18 -> type = V_31 ;
} else
if ( V_226 & ( 1 << V_40 ) ) {
if ( V_226 & ( 1 << V_41 ) )
V_18 -> type = V_56 ;
else
V_18 -> type = V_202 ;
} else
if ( V_226 & ( 1 << V_41 ) ) {
V_18 -> type = V_193 ;
} else
if ( V_226 & ( 1 << V_52 ) ) {
V_18 -> type = V_163 ;
} else
if ( V_226 & ( 1 << V_77 ) ) {
V_18 -> type = V_195 ;
}
}
type = F_67 ( V_18 -> type ) ;
if ( type == V_111 ) {
V_65 = F_79 ( V_5 , 0 , & V_217 , & V_217 ) ;
if ( V_65 ) {
F_29 ( V_24 , L_12 ) ;
F_9 ( V_18 ) ;
return F_70 ( V_65 ) ;
}
V_215 = & V_228 ;
} else {
V_215 = & V_216 ;
}
V_3 -> V_50 = false ;
V_3 -> V_51 = false ;
F_80 ( V_5 , V_3 , V_215 , type ) ;
F_81 ( V_3 , & V_229 ) ;
if ( V_18 -> type == V_56 )
F_82 ( & V_3 -> V_57 , V_5 -> V_58 . V_59 , 0 ) ;
if ( V_99 -> V_117 &&
( type == V_203 ||
type == V_201 ||
type == V_212 ||
type == V_207 ) ) {
F_82 ( & V_3 -> V_57 ,
V_99 -> V_117 ,
V_230 ) ;
F_82 ( & V_3 -> V_57 ,
V_99 -> V_119 ,
0 ) ;
F_82 ( & V_3 -> V_57 ,
V_99 -> V_121 ,
0 ) ;
}
if ( V_99 -> V_127 )
F_82 ( & V_3 -> V_57 ,
V_99 -> V_127 ,
90 ) ;
if ( V_99 -> V_129 )
F_82 ( & V_3 -> V_57 ,
V_99 -> V_129 ,
150 ) ;
switch ( V_18 -> type ) {
case V_193 :
if ( F_23 ( V_24 -> V_27 ) -> V_48 >= V_49 ) {
F_82 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_103 ,
V_18 -> V_112 ) ;
}
case V_195 :
case V_196 :
case V_197 :
V_18 -> V_112 = V_105 ;
break;
default:
V_18 -> V_112 = V_106 ;
F_82 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_103 ,
V_18 -> V_112 ) ;
if ( V_99 -> V_123 ) {
V_18 -> V_123 = V_231 ;
F_82 ( & V_3 -> V_57 ,
V_99 -> V_123 ,
V_18 -> V_123 ) ;
}
if ( V_99 -> V_125 ) {
V_18 -> V_125 = V_232 ;
F_82 ( & V_3 -> V_57 ,
V_99 -> V_125 ,
V_18 -> V_125 ) ;
}
break;
}
V_3 -> V_233 = V_234 ;
if ( V_18 -> V_185 . V_186 != V_221 )
V_3 -> V_233 = V_235 ;
F_83 ( V_3 ) ;
return V_3 ;
}
