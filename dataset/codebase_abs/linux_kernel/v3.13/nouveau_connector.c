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
if ( V_65 < 0 )
return V_66 ;
V_35 = F_12 ( V_3 , & V_6 ) ;
if ( V_35 ) {
V_18 -> V_20 = F_28 ( V_3 , & V_35 -> V_68 ) ;
F_26 ( V_3 ,
V_18 -> V_20 ) ;
if ( ! V_18 -> V_20 ) {
F_29 ( V_24 , L_3 ,
F_30 ( V_3 ) ) ;
goto V_69;
}
if ( V_6 -> V_15 -> type == V_70 &&
! F_31 ( F_5 ( V_6 ) ) ) {
F_29 ( V_24 , L_4 ,
F_30 ( V_3 ) ) ;
V_66 = V_67 ;
goto V_71;
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
if ( V_18 -> V_20 -> V_72 & V_73 )
type = V_40 ;
else
type = V_41 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_22 ( V_3 , V_6 ) ;
V_66 = V_74 ;
goto V_71;
}
V_6 = F_15 ( V_3 ) ;
if ( V_6 ) {
F_22 ( V_3 , V_6 ) ;
V_66 = V_74 ;
goto V_71;
}
V_69:
V_6 = F_1 ( V_3 , V_41 ) ;
if ( ! V_6 && ! V_75 )
V_6 = F_1 ( V_3 , V_76 ) ;
if ( V_6 && V_63 ) {
struct V_77 * V_17 = F_5 ( V_6 ) ;
struct V_78 * V_79 =
V_17 -> V_80 ;
if ( V_79 -> V_81 ( V_17 , V_3 ) ==
V_74 ) {
F_22 ( V_3 , V_6 ) ;
V_66 = V_74 ;
goto V_71;
}
}
V_71:
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
enum V_62 V_82 = V_67 ;
if ( V_18 -> V_20 ) {
F_26 ( V_3 , NULL ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
V_6 = F_1 ( V_3 , V_52 ) ;
if ( ! V_6 )
return V_67 ;
if ( ! V_24 -> V_83 . V_84 ) {
V_82 = F_25 ( V_3 , V_63 ) ;
if ( V_82 == V_74 )
goto V_71;
}
if ( V_6 -> V_15 -> V_85 . V_86 ) {
if ( ( V_18 -> V_20 = F_35 ( V_5 , V_3 ) ) ) {
V_82 = V_74 ;
goto V_71;
}
}
if ( F_36 ( V_5 , NULL ) && ( V_24 -> V_83 . V_84 ||
V_6 -> V_15 -> V_85 . V_87 ) ) {
V_82 = V_74 ;
goto V_71;
}
if ( ! V_24 -> V_83 . V_84 ) {
struct V_20 * V_20 =
(struct V_20 * ) F_37 ( V_5 ) ;
if ( V_20 ) {
V_18 -> V_20 =
F_20 ( V_20 , V_45 , V_46 ) ;
if ( V_18 -> V_20 )
V_82 = V_74 ;
}
}
V_71:
#if F_38 ( V_88 ) || \
( F_38 ( V_89 ) && F_38 ( V_90 ) )
if ( V_82 == V_74 &&
! V_91 && ! F_39 () )
V_82 = V_92 ;
#endif
F_26 ( V_3 , V_18 -> V_20 ) ;
F_22 ( V_3 , V_6 ) ;
return V_82 ;
}
static void
F_40 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_18 -> type == V_56 ) {
if ( V_3 -> V_63 == V_93 )
type = V_40 ;
else
type = V_41 ;
} else
type = V_14 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_29 ( V_24 , L_5 ,
F_30 ( V_3 ) ) ;
V_3 -> V_82 = V_67 ;
return;
}
F_22 ( V_3 , V_6 ) ;
}
static int
F_41 ( struct V_2 * V_3 ,
struct V_94 * V_95 , T_1 V_96 )
{
struct V_97 * V_98 = V_97 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_77 * V_17 = F_5 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_99 * V_100 ;
int V_65 ;
V_100 = NULL ;
if ( V_3 -> V_17 && V_3 -> V_17 -> V_101 )
V_100 = V_99 ( V_3 -> V_17 -> V_101 ) ;
if ( V_95 == V_5 -> V_58 . V_102 ) {
bool V_103 = false ;
switch ( V_96 ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
break;
default:
return - V_108 ;
}
if ( V_3 -> V_109 == V_110 &&
V_96 == V_104 )
return - V_108 ;
if ( ( V_18 -> V_111 == V_104 ) ||
( V_96 == V_104 ) )
V_103 = true ;
V_18 -> V_111 = V_96 ;
if ( ! V_100 )
return 0 ;
if ( V_103 || ! V_100 -> V_112 ) {
V_65 = F_42 ( & V_100 -> V_57 ,
& V_100 -> V_57 . V_113 ,
V_100 -> V_57 . V_114 ,
V_100 -> V_57 . V_115 , NULL ) ;
if ( ! V_65 )
return - V_108 ;
} else {
V_65 = V_100 -> V_112 ( V_100 , true ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
if ( V_95 == V_98 -> V_116 ) {
if ( V_18 -> V_117 != V_96 ) {
V_18 -> V_117 = V_96 ;
if ( ! V_100 || ! V_100 -> V_112 )
return 0 ;
return V_100 -> V_112 ( V_100 , true ) ;
}
return 0 ;
}
if ( V_95 == V_98 -> V_118 ) {
if ( V_18 -> V_119 != V_96 ) {
V_18 -> V_119 = V_96 ;
if ( ! V_100 || ! V_100 -> V_112 )
return 0 ;
return V_100 -> V_112 ( V_100 , true ) ;
}
return 0 ;
}
if ( V_95 == V_98 -> V_120 ) {
if ( V_18 -> V_121 != V_96 ) {
V_18 -> V_121 = V_96 ;
if ( ! V_100 || ! V_100 -> V_112 )
return 0 ;
return V_100 -> V_112 ( V_100 , true ) ;
}
return 0 ;
}
if ( V_95 == V_98 -> V_122 ) {
V_18 -> V_122 = V_96 ;
if ( ! V_100 || ! V_100 -> V_123 )
return 0 ;
return V_100 -> V_123 ( V_100 , true ) ;
}
if ( V_95 == V_98 -> V_124 ) {
V_18 -> V_124 = V_96 ;
if ( ! V_100 || ! V_100 -> V_123 )
return 0 ;
return V_100 -> V_123 ( V_100 , true ) ;
}
if ( V_100 && V_100 -> V_125 ) {
if ( V_95 == V_98 -> V_126 ) {
V_100 -> V_127 = V_96 - 90 ;
return V_100 -> V_125 ( V_100 , true ) ;
}
if ( V_95 == V_98 -> V_128 ) {
V_100 -> V_129 = V_96 - 100 ;
return V_100 -> V_125 ( V_100 , true ) ;
}
}
if ( V_6 && V_6 -> V_15 -> type == V_76 )
return F_43 ( V_17 ) -> F_44 (
V_17 , V_3 , V_95 , V_96 ) ;
return - V_108 ;
}
static struct V_130 *
F_45 ( struct V_2 * V_3 )
{
struct V_131 * V_79 = V_3 -> V_80 ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_130 * V_113 , * V_132 = NULL ;
int V_133 = 0 , V_134 = 0 , V_135 = 0 ;
F_6 (mode, &nv_connector->base.probed_modes, head) {
V_113 -> V_136 = F_46 ( V_113 ) ;
if ( V_79 -> V_137 ( V_3 , V_113 ) != V_138 ||
( V_113 -> V_139 & V_140 ) )
continue;
if ( V_113 -> type & V_141 ) {
F_47 ( V_24 , L_6 ) ;
return F_48 ( V_5 , V_113 ) ;
}
if ( V_113 -> V_142 < V_133 )
continue;
if ( V_113 -> V_142 == V_133 && V_113 -> V_143 < V_134 )
continue;
if ( V_113 -> V_142 == V_133 && V_113 -> V_143 == V_134 &&
V_113 -> V_136 < V_135 )
continue;
V_133 = V_113 -> V_142 ;
V_134 = V_113 -> V_143 ;
V_135 = V_113 -> V_136 ;
V_132 = V_113 ;
}
F_47 ( V_24 , L_7 ,
V_133 , V_134 , V_135 ) ;
return V_132 ? F_48 ( V_5 , V_132 ) : NULL ;
}
static int
F_49 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_130 * V_144 = V_18 -> V_145 , * V_146 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_147 * V_113 = & V_148 [ 0 ] ;
int V_149 = 0 ;
if ( ! V_144 )
return 0 ;
while ( V_113 -> V_142 ) {
if ( V_113 -> V_142 <= V_144 -> V_142 &&
V_113 -> V_143 <= V_144 -> V_143 ) {
V_146 = F_50 ( V_5 , V_113 -> V_142 , V_113 -> V_143 ,
F_46 ( V_144 ) , false ,
false , false ) ;
if ( ! V_146 )
continue;
V_146 -> type |= V_150 ;
F_51 ( V_3 , V_146 ) ;
V_149 ++ ;
}
V_113 ++ ;
}
return V_149 ;
}
static void
F_52 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_151 * V_152 = & V_24 -> V_83 ;
struct V_130 * V_113 = V_18 -> V_145 ;
bool V_153 ;
if ( V_18 -> V_20 && V_3 -> V_154 . V_155 )
return;
if ( V_18 -> type == V_31 ) {
V_3 -> V_154 . V_155 = 6 ;
return;
}
if ( V_6 -> V_15 -> type != V_52 ) {
V_3 -> V_154 . V_155 = 8 ;
return;
}
V_3 -> V_154 . V_155 = 6 ;
if ( V_152 -> V_84 ) {
if ( V_152 -> V_156 . V_157 )
V_3 -> V_154 . V_155 = 8 ;
return;
}
if ( V_18 -> V_20 &&
V_18 -> type == V_158 )
V_153 = ( ( V_159 * ) V_18 -> V_20 ) [ 121 ] == 2 ;
else
V_153 = V_113 -> clock >= V_152 -> V_156 . V_160 ;
if ( ( ! V_153 && ( V_152 -> V_156 . V_161 & 1 ) ) ||
( V_153 && ( V_152 -> V_156 . V_161 & 2 ) ) )
V_3 -> V_154 . V_155 = 8 ;
}
static int
F_53 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_77 * V_17 = F_5 ( V_6 ) ;
int V_65 = 0 ;
if ( V_18 -> V_145 ) {
F_54 ( V_5 , V_18 -> V_145 ) ;
V_18 -> V_145 = NULL ;
}
if ( V_18 -> V_20 )
V_65 = F_55 ( V_3 , V_18 -> V_20 ) ;
else
if ( V_6 -> V_15 -> type == V_52 &&
( V_6 -> V_15 -> V_85 . V_87 ||
V_24 -> V_83 . V_84 ) && F_36 ( V_5 , NULL ) ) {
struct V_130 V_113 ;
F_36 ( V_5 , & V_113 ) ;
V_18 -> V_145 = F_48 ( V_5 , & V_113 ) ;
}
if ( V_3 -> V_109 != V_110 )
F_52 ( V_3 ) ;
if ( ! V_18 -> V_145 )
V_18 -> V_145 =
F_45 ( V_3 ) ;
if ( V_65 == 0 && V_18 -> V_145 ) {
struct V_130 * V_113 ;
V_113 = F_48 ( V_5 , V_18 -> V_145 ) ;
F_51 ( V_3 , V_113 ) ;
V_65 = 1 ;
}
if ( V_3 -> V_109 == V_110 )
F_52 ( V_3 ) ;
if ( V_6 -> V_15 -> type == V_76 )
V_65 = F_43 ( V_17 ) -> F_56 ( V_17 , V_3 ) ;
if ( V_18 -> type == V_162 ||
V_18 -> type == V_158 ||
V_18 -> type == V_31 )
V_65 += F_49 ( V_3 ) ;
return V_65 ;
}
static unsigned
F_57 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_23 * V_24 = V_23 ( V_3 -> V_5 ) ;
struct V_163 * V_15 = V_18 -> V_47 -> V_15 ;
if ( V_15 -> V_164 != V_165 ||
F_23 ( V_24 -> V_27 ) -> V_166 >= 0x46 )
return 165000 ;
else if ( F_23 ( V_24 -> V_27 ) -> V_166 >= 0x40 )
return 155000 ;
else if ( F_23 ( V_24 -> V_27 ) -> V_166 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_58 ( struct V_2 * V_3 ,
struct V_130 * V_113 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
struct V_1 * V_6 = V_18 -> V_47 ;
struct V_77 * V_17 = F_5 ( V_6 ) ;
unsigned V_167 = 25000 , V_168 = V_167 ;
unsigned clock = V_113 -> clock ;
switch ( V_6 -> V_15 -> type ) {
case V_52 :
if ( V_18 -> V_145 &&
( V_113 -> V_142 > V_18 -> V_145 -> V_142 ||
V_113 -> V_143 > V_18 -> V_145 -> V_143 ) )
return V_169 ;
V_167 = 0 ;
V_168 = 400000 ;
break;
case V_40 :
V_168 = F_57 ( V_3 ) ;
if ( V_170 && V_6 -> V_15 -> V_171 )
V_168 *= 2 ;
break;
case V_41 :
V_168 = V_6 -> V_15 -> V_172 . V_173 ;
if ( ! V_168 )
V_168 = 350000 ;
break;
case V_76 :
return F_43 ( V_17 ) -> V_137 ( V_17 , V_113 ) ;
case V_70 :
V_168 = V_6 -> V_174 . V_175 ;
V_168 *= V_6 -> V_174 . V_176 ;
clock = clock * ( V_3 -> V_154 . V_155 * 3 ) / 10 ;
break;
default:
F_59 ( 1 ) ;
return V_177 ;
}
if ( clock < V_167 )
return V_178 ;
if ( clock > V_168 )
return V_179 ;
return V_138 ;
}
static struct V_77 *
F_60 ( struct V_2 * V_3 )
{
struct V_16 * V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_47 )
return F_5 ( V_18 -> V_47 ) ;
return NULL ;
}
static void
F_61 ( struct V_180 * V_181 )
{
struct V_16 * V_18 =
F_62 ( V_181 , struct V_16 , V_182 ) ;
struct V_2 * V_3 = & V_18 -> V_57 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
bool V_183 = V_26 -> V_32 ( V_26 , 0 , V_18 -> V_184 . V_185 , 0xff ) ;
F_47 ( V_24 , L_8 , V_183 ? L_9 : L_10 ,
F_30 ( V_3 ) ) ;
if ( V_183 )
F_63 ( V_3 , V_186 ) ;
else
F_63 ( V_3 , V_187 ) ;
F_64 ( V_5 ) ;
}
static int
F_65 ( void * V_188 , int V_189 )
{
struct V_16 * V_18 = V_188 ;
F_66 ( & V_18 -> V_182 ) ;
return V_190 ;
}
static int
F_67 ( enum V_191 V_15 )
{
switch ( V_15 ) {
case V_192 : return V_193 ;
case V_194 :
case V_195 :
case V_196 : return V_197 ;
case V_198 :
case V_199 :
case V_56 : return V_200 ;
case V_201 : return V_202 ;
case V_162 :
case V_158 : return V_110 ;
case V_203 :
case V_204 :
case V_205 : return V_206 ;
case V_31 : return V_207 ;
case V_208 :
case V_209 : return V_210 ;
default:
break;
}
return V_211 ;
}
struct V_2 *
F_68 ( struct V_4 * V_5 , int V_189 )
{
const struct V_212 * V_213 = & V_214 ;
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_25 * V_26 = V_25 ( V_24 -> V_27 ) ;
struct V_97 * V_98 = V_97 ( V_5 ) ;
struct V_16 * V_18 = NULL ;
struct V_2 * V_3 ;
int type , V_65 = 0 ;
bool V_215 ;
F_6 (connector, &dev->mode_config.connector_list, head) {
V_18 = V_16 ( V_3 ) ;
if ( V_18 -> V_189 == V_189 )
return V_3 ;
}
V_18 = F_69 ( sizeof( * V_18 ) , V_46 ) ;
if ( ! V_18 )
return F_70 ( - V_216 ) ;
V_3 = & V_18 -> V_57 ;
F_71 ( & V_18 -> V_182 , F_61 ) ;
V_18 -> V_189 = V_189 ;
V_18 -> V_15 = F_72 ( V_5 , V_189 ) ;
if ( V_18 -> V_15 ) {
static const V_159 V_184 [ 16 ] = {
0xff , 0x07 , 0x08 , 0xff , 0xff , 0x51 , 0x52 , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0x5e , 0x5f , 0x60 ,
} ;
T_2 V_217 = F_73 ( V_18 -> V_15 [ 0 ] ) ;
if ( F_74 ( V_5 ) [ 3 ] >= 4 )
V_217 |= ( T_2 ) F_73 ( V_18 -> V_15 [ 2 ] ) << 16 ;
V_65 = V_26 -> V_218 ( V_26 , 0 , V_184 [ F_75 ( ( V_217 & 0x07033000 ) >> 12 ) ] ,
V_219 , & V_18 -> V_184 ) ;
if ( V_65 )
V_18 -> V_184 . V_185 = V_219 ;
if ( V_18 -> V_184 . V_185 != V_219 ) {
F_76 ( V_26 -> V_220 , V_18 -> V_184 . line ,
F_65 ,
V_18 ,
& V_18 -> V_19 ) ;
}
V_18 -> type = V_18 -> V_15 [ 0 ] ;
if ( F_67 ( V_18 -> type ) ==
V_211 ) {
F_77 ( V_24 , L_11 ,
V_18 -> type ) ;
V_18 -> type = V_221 ;
}
if ( F_78 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_18 -> type == V_209 )
V_18 -> type = V_56 ;
}
if ( F_78 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_18 -> type == V_209 )
V_18 -> type = V_56 ;
}
} else {
V_18 -> type = V_221 ;
V_18 -> V_184 . V_185 = V_219 ;
}
if ( V_18 -> type == V_221 ) {
struct V_23 * V_24 = V_23 ( V_5 ) ;
struct V_222 * V_223 = & V_24 -> V_83 . V_15 ;
T_2 V_224 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_223 -> V_225 ; V_9 ++ ) {
if ( V_223 -> V_217 [ V_9 ] . V_3 == V_18 -> V_189 )
V_224 |= ( 1 << V_223 -> V_217 [ V_9 ] . type ) ;
}
if ( V_224 & ( 1 << V_70 ) ) {
if ( V_224 & ( 1 << V_40 ) )
V_18 -> type = V_205 ;
else
V_18 -> type = V_31 ;
} else
if ( V_224 & ( 1 << V_40 ) ) {
if ( V_224 & ( 1 << V_41 ) )
V_18 -> type = V_56 ;
else
V_18 -> type = V_201 ;
} else
if ( V_224 & ( 1 << V_41 ) ) {
V_18 -> type = V_192 ;
} else
if ( V_224 & ( 1 << V_52 ) ) {
V_18 -> type = V_162 ;
} else
if ( V_224 & ( 1 << V_76 ) ) {
V_18 -> type = V_194 ;
}
}
type = F_67 ( V_18 -> type ) ;
if ( type == V_110 ) {
V_65 = F_79 ( V_5 , 0 , & V_215 , & V_215 ) ;
if ( V_65 ) {
F_29 ( V_24 , L_12 ) ;
F_9 ( V_18 ) ;
return F_70 ( V_65 ) ;
}
V_213 = & V_226 ;
} else {
V_213 = & V_214 ;
}
V_3 -> V_50 = false ;
V_3 -> V_51 = false ;
F_80 ( V_5 , V_3 , V_213 , type ) ;
F_81 ( V_3 , & V_227 ) ;
if ( V_18 -> type == V_56 )
F_82 ( & V_3 -> V_57 , V_5 -> V_58 . V_59 , 0 ) ;
if ( V_98 -> V_116 &&
( type == V_202 ||
type == V_200 ||
type == V_210 ||
type == V_206 ) ) {
F_82 ( & V_3 -> V_57 ,
V_98 -> V_116 ,
V_228 ) ;
F_82 ( & V_3 -> V_57 ,
V_98 -> V_118 ,
0 ) ;
F_82 ( & V_3 -> V_57 ,
V_98 -> V_120 ,
0 ) ;
}
if ( V_98 -> V_126 )
F_82 ( & V_3 -> V_57 ,
V_98 -> V_126 ,
90 ) ;
if ( V_98 -> V_128 )
F_82 ( & V_3 -> V_57 ,
V_98 -> V_128 ,
150 ) ;
switch ( V_18 -> type ) {
case V_192 :
if ( F_23 ( V_24 -> V_27 ) -> V_48 >= V_49 ) {
F_82 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_102 ,
V_18 -> V_111 ) ;
}
case V_194 :
case V_195 :
case V_196 :
V_18 -> V_111 = V_104 ;
break;
default:
V_18 -> V_111 = V_105 ;
F_82 ( & V_3 -> V_57 ,
V_5 -> V_58 . V_102 ,
V_18 -> V_111 ) ;
if ( V_98 -> V_122 ) {
V_18 -> V_122 = V_229 ;
F_82 ( & V_3 -> V_57 ,
V_98 -> V_122 ,
V_18 -> V_122 ) ;
}
if ( V_98 -> V_124 ) {
V_18 -> V_124 = V_230 ;
F_82 ( & V_3 -> V_57 ,
V_98 -> V_124 ,
V_18 -> V_124 ) ;
}
break;
}
V_3 -> V_231 = V_232 ;
if ( V_18 -> V_184 . V_185 != V_219 )
V_3 -> V_231 = V_233 ;
F_83 ( V_3 ) ;
return V_3 ;
}
