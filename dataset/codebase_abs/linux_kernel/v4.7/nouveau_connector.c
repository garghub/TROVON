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
if ( ( F_18 () &
V_33 ) &&
V_6 -> V_14 -> type == V_34 &&
V_6 -> V_35 ) {
int V_32 ;
F_19 ( V_5 -> V_36 ) ;
V_32 = F_20 ( V_6 -> V_35 , 0x50 ) ;
F_21 ( V_5 -> V_36 ) ;
if ( V_32 )
break;
} else
if ( V_6 -> V_35 ) {
if ( F_20 ( V_6 -> V_35 , 0x50 ) )
break;
}
}
if ( ! V_6 && V_27 == 0 )
F_15 ( V_25 , 0 , V_30 , 0xff , V_27 ) ;
return V_6 ;
}
static struct V_1 *
F_22 ( struct V_2 * V_3 )
{
#ifdef F_23
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_37 * V_38 , * V_39 = F_24 ( V_5 -> V_36 ) ;
if ( ! V_39 ||
! ( ( V_6 = F_1 ( V_3 , V_40 ) ) ||
( V_6 = F_1 ( V_3 , V_41 ) ) ) )
return NULL ;
F_25 (dn, cn) {
const char * V_42 = F_26 ( V_38 , L_1 , NULL ) ;
const void * V_19 = F_26 ( V_38 , L_2 , NULL ) ;
int V_43 = V_42 ? V_42 [ strlen ( V_42 ) - 1 ] - 'A' : 0 ;
if ( V_6 -> V_14 -> V_44 == V_43 && V_19 ) {
V_17 -> V_19 =
F_27 ( V_19 , V_45 , V_46 ) ;
F_28 ( V_38 ) ;
return V_6 ;
}
}
#endif
return NULL ;
}
static void
F_29 ( struct V_2 * V_3 ,
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
if ( V_6 -> V_14 -> type == V_34 ||
V_6 -> V_14 -> type == V_40 ) {
V_3 -> V_52 = false ;
V_3 -> V_51 = false ;
} else {
V_3 -> V_52 = true ;
if ( V_23 -> V_26 . V_48 . V_49 == V_53 ||
( V_23 -> V_26 . V_48 . V_49 == V_54 &&
( V_5 -> V_36 -> V_26 & 0x0ff0 ) != 0x0100 &&
( V_5 -> V_36 -> V_26 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_51 = false ;
else
V_3 -> V_51 = true ;
}
if ( V_17 -> type == V_55 ) {
F_30 ( & V_3 -> V_56 ,
V_5 -> V_57 . V_58 ,
V_6 -> V_14 -> type == V_40 ?
V_59 :
V_60 ) ;
}
}
static enum V_61
F_31 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_63 ;
struct V_64 * V_35 ;
int type ;
int V_32 ;
enum V_61 V_65 = V_66 ;
if ( V_17 -> V_19 ) {
F_32 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_32 = F_33 ( V_3 -> V_5 -> V_5 ) ;
if ( V_32 < 0 && V_32 != - V_67 )
return V_65 ;
V_6 = F_12 ( V_3 ) ;
if ( V_6 && ( V_35 = V_6 -> V_35 ) != NULL ) {
if ( ( F_18 () &
V_33 ) &&
V_17 -> type == V_68 )
V_17 -> V_19 = F_34 ( V_3 ,
V_35 ) ;
else
V_17 -> V_19 = F_35 ( V_3 , V_35 ) ;
F_32 ( V_3 ,
V_17 -> V_19 ) ;
if ( ! V_17 -> V_19 ) {
F_36 ( V_23 , L_3 ,
V_3 -> V_42 ) ;
goto V_69;
}
V_63 = NULL ;
if ( V_6 -> V_14 -> type == V_40 )
V_63 = F_1 ( V_3 , V_41 ) ;
if ( V_6 -> V_14 -> type == V_41 )
V_63 = F_1 ( V_3 , V_40 ) ;
if ( V_63 && ( ( V_6 -> V_14 -> type == V_41 &&
V_63 -> V_14 -> type == V_40 ) ||
( V_6 -> V_14 -> type == V_40 &&
V_63 -> V_14 -> type == V_41 ) ) ) {
if ( V_17 -> V_19 -> V_70 & V_71 )
type = V_40 ;
else
type = V_41 ;
V_6 = F_1 ( V_3 , type ) ;
}
F_29 ( V_3 , V_6 ) ;
V_65 = V_72 ;
goto V_73;
}
V_6 = F_22 ( V_3 ) ;
if ( V_6 ) {
F_29 ( V_3 , V_6 ) ;
V_65 = V_72 ;
goto V_73;
}
V_69:
V_6 = F_1 ( V_3 , V_41 ) ;
if ( ! V_6 && ! V_74 )
V_6 = F_1 ( V_3 , V_75 ) ;
if ( V_6 && V_62 ) {
struct V_7 * V_16 = F_4 ( V_6 ) ;
const struct V_76 * V_77 =
V_16 -> V_78 ;
if ( V_77 -> V_79 ( V_16 , V_3 ) ==
V_72 ) {
F_29 ( V_3 , V_6 ) ;
V_65 = V_72 ;
goto V_73;
}
}
V_73:
F_37 ( V_3 -> V_5 -> V_5 ) ;
F_38 ( V_3 -> V_5 -> V_5 ) ;
return V_65 ;
}
static enum V_61
F_39 ( struct V_2 * V_3 , bool V_62 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = NULL ;
enum V_61 V_80 = V_66 ;
if ( V_17 -> V_19 ) {
F_32 ( V_3 , NULL ) ;
F_8 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
V_6 = F_1 ( V_3 , V_34 ) ;
if ( ! V_6 )
return V_66 ;
if ( ! V_23 -> V_81 . V_82 ) {
V_80 = F_31 ( V_3 , V_62 ) ;
if ( V_80 == V_72 )
goto V_73;
}
if ( V_6 -> V_14 -> V_83 . V_84 ) {
if ( ( V_17 -> V_19 = F_40 ( V_5 , V_3 ) ) ) {
V_80 = V_72 ;
goto V_73;
}
}
if ( F_41 ( V_5 , NULL ) && ( V_23 -> V_81 . V_82 ||
V_6 -> V_14 -> V_83 . V_85 ) ) {
V_80 = V_72 ;
goto V_73;
}
if ( ! V_23 -> V_81 . V_82 ) {
struct V_19 * V_19 =
(struct V_19 * ) F_42 ( V_5 ) ;
if ( V_19 ) {
V_17 -> V_19 =
F_27 ( V_19 , V_45 , V_46 ) ;
if ( V_17 -> V_19 )
V_80 = V_72 ;
}
}
V_73:
#if F_43 ( V_86 ) || \
( F_43 ( V_87 ) && F_43 ( V_88 ) )
if ( V_80 == V_72 &&
! V_89 && ! F_44 () )
V_80 = V_90 ;
#endif
F_32 ( V_3 , V_17 -> V_19 ) ;
F_29 ( V_3 , V_6 ) ;
return V_80 ;
}
static void
F_45 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 ;
int type ;
if ( V_17 -> type == V_55 ) {
if ( V_3 -> V_62 == V_91 )
type = V_40 ;
else
type = V_41 ;
} else
type = V_13 ;
V_6 = F_1 ( V_3 , type ) ;
if ( ! V_6 ) {
F_36 ( V_23 , L_4 ,
V_3 -> V_42 ) ;
V_3 -> V_80 = V_66 ;
return;
}
F_29 ( V_3 , V_6 ) ;
}
static int
F_46 ( struct V_2 * V_3 ,
struct V_92 * V_93 , T_1 V_94 )
{
struct V_95 * V_96 = V_95 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_97 * V_98 ;
int V_32 ;
V_98 = NULL ;
if ( V_3 -> V_16 && V_3 -> V_16 -> V_99 )
V_98 = V_97 ( V_3 -> V_16 -> V_99 ) ;
if ( V_93 == V_5 -> V_57 . V_100 ) {
bool V_101 = false ;
switch ( V_94 ) {
case V_102 :
switch ( V_17 -> type ) {
case V_68 :
case V_103 :
case V_29 :
if ( V_96 -> V_96 . V_104 < V_105 )
return - V_106 ;
break;
default:
break;
}
break;
case V_107 :
case V_108 :
case V_109 :
break;
default:
return - V_106 ;
}
if ( ( V_17 -> V_110 == V_102 ) ||
( V_94 == V_102 ) )
V_101 = true ;
V_17 -> V_110 = V_94 ;
if ( ! V_98 )
return 0 ;
if ( V_101 || ! V_98 -> V_111 ) {
V_32 = F_47 ( & V_98 -> V_56 ,
& V_98 -> V_56 . V_112 ,
V_98 -> V_56 . V_113 ,
V_98 -> V_56 . V_114 , NULL ) ;
if ( ! V_32 )
return - V_106 ;
} else {
V_32 = V_98 -> V_111 ( V_98 , true ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
if ( V_93 == V_96 -> V_115 ) {
if ( V_17 -> V_116 != V_94 ) {
V_17 -> V_116 = V_94 ;
if ( ! V_98 || ! V_98 -> V_111 )
return 0 ;
return V_98 -> V_111 ( V_98 , true ) ;
}
return 0 ;
}
if ( V_93 == V_96 -> V_117 ) {
if ( V_17 -> V_118 != V_94 ) {
V_17 -> V_118 = V_94 ;
if ( ! V_98 || ! V_98 -> V_111 )
return 0 ;
return V_98 -> V_111 ( V_98 , true ) ;
}
return 0 ;
}
if ( V_93 == V_96 -> V_119 ) {
if ( V_17 -> V_120 != V_94 ) {
V_17 -> V_120 = V_94 ;
if ( ! V_98 || ! V_98 -> V_111 )
return 0 ;
return V_98 -> V_111 ( V_98 , true ) ;
}
return 0 ;
}
if ( V_93 == V_96 -> V_121 ) {
V_17 -> V_121 = V_94 ;
if ( ! V_98 || ! V_98 -> V_122 )
return 0 ;
return V_98 -> V_122 ( V_98 , true ) ;
}
if ( V_93 == V_96 -> V_123 ) {
V_17 -> V_123 = V_94 ;
if ( ! V_98 || ! V_98 -> V_122 )
return 0 ;
return V_98 -> V_122 ( V_98 , true ) ;
}
if ( V_98 && V_98 -> V_124 ) {
if ( V_93 == V_96 -> V_125 ) {
V_98 -> V_126 = V_94 - 90 ;
return V_98 -> V_124 ( V_98 , true ) ;
}
if ( V_93 == V_96 -> V_127 ) {
V_98 -> V_128 = V_94 - 100 ;
return V_98 -> V_124 ( V_98 , true ) ;
}
}
if ( V_6 && V_6 -> V_14 -> type == V_75 )
return F_48 ( V_16 ) -> F_49 (
V_16 , V_3 , V_93 , V_94 ) ;
return - V_106 ;
}
static struct V_129 *
F_50 ( struct V_2 * V_3 )
{
const struct V_130 * V_77 = V_3 -> V_78 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_129 * V_112 , * V_131 = NULL ;
int V_132 = 0 , V_133 = 0 , V_134 = 0 ;
F_5 (mode, &nv_connector->base.probed_modes, head) {
V_112 -> V_135 = F_51 ( V_112 ) ;
if ( V_77 -> V_136 ( V_3 , V_112 ) != V_137 ||
( V_112 -> V_138 & V_139 ) )
continue;
if ( V_112 -> type & V_140 ) {
F_52 ( V_23 , L_5 ) ;
return F_53 ( V_5 , V_112 ) ;
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
F_52 ( V_23 , L_6 ,
V_132 , V_133 , V_134 ) ;
return V_131 ? F_53 ( V_5 , V_131 ) : NULL ;
}
static int
F_54 ( struct V_2 * V_3 )
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
V_112 -> V_142 <= V_143 -> V_142 &&
( V_112 -> V_141 != V_143 -> V_141 ||
V_112 -> V_142 != V_143 -> V_142 ) ) {
V_145 = F_55 ( V_5 , V_112 -> V_141 , V_112 -> V_142 ,
F_51 ( V_143 ) , false ,
false , false ) ;
if ( ! V_145 )
continue;
F_56 ( V_3 , V_145 ) ;
V_148 ++ ;
}
V_112 ++ ;
}
return V_148 ;
}
static void
F_57 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_149 * V_150 = & V_23 -> V_81 ;
struct V_129 * V_112 = V_17 -> V_144 ;
bool V_151 ;
if ( V_17 -> V_19 && V_3 -> V_152 . V_153 )
return;
if ( V_17 -> type == V_29 ) {
V_3 -> V_152 . V_153 = 6 ;
return;
}
if ( V_6 -> V_14 -> type != V_34 ) {
V_3 -> V_152 . V_153 = 8 ;
return;
}
V_3 -> V_152 . V_153 = 6 ;
if ( V_150 -> V_82 ) {
if ( V_150 -> V_154 . V_155 )
V_3 -> V_152 . V_153 = 8 ;
return;
}
if ( V_17 -> V_19 &&
V_17 -> type == V_103 )
V_151 = ( ( V_156 * ) V_17 -> V_19 ) [ 121 ] == 2 ;
else
V_151 = V_112 -> clock >= V_150 -> V_154 . V_157 ;
if ( ( ! V_151 && ( V_150 -> V_154 . V_158 & 1 ) ) ||
( V_151 && ( V_150 -> V_154 . V_158 & 2 ) ) )
V_3 -> V_152 . V_153 = 8 ;
}
static int
F_58 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
int V_32 = 0 ;
if ( V_17 -> V_144 ) {
F_59 ( V_5 , V_17 -> V_144 ) ;
V_17 -> V_144 = NULL ;
}
if ( V_17 -> V_19 )
V_32 = F_60 ( V_3 , V_17 -> V_19 ) ;
else
if ( V_6 -> V_14 -> type == V_34 &&
( V_6 -> V_14 -> V_83 . V_85 ||
V_23 -> V_81 . V_82 ) && F_41 ( V_5 , NULL ) ) {
struct V_129 V_112 ;
F_41 ( V_5 , & V_112 ) ;
V_17 -> V_144 = F_53 ( V_5 , & V_112 ) ;
}
if ( V_3 -> V_159 != V_160 )
F_57 ( V_3 ) ;
if ( ! V_17 -> V_144 )
V_17 -> V_144 =
F_50 ( V_3 ) ;
if ( V_32 == 0 && V_17 -> V_144 ) {
struct V_129 * V_112 ;
V_112 = F_53 ( V_5 , V_17 -> V_144 ) ;
F_56 ( V_3 , V_112 ) ;
V_32 = 1 ;
}
if ( V_3 -> V_159 == V_160 )
F_57 ( V_3 ) ;
if ( V_6 -> V_14 -> type == V_75 )
V_32 = F_48 ( V_16 ) -> F_61 ( V_16 , V_3 ) ;
if ( V_17 -> type == V_68 ||
V_17 -> type == V_103 ||
V_17 -> type == V_29 )
V_32 += F_54 ( V_3 ) ;
return V_32 ;
}
static unsigned
F_62 ( struct V_2 * V_3 , bool V_161 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
struct V_162 * V_14 = V_17 -> V_47 -> V_14 ;
if ( V_161 ) {
if ( V_163 > 0 )
return V_163 * 1000 ;
if ( V_23 -> V_26 . V_48 . V_49 >= V_164 )
return 297000 ;
if ( V_23 -> V_26 . V_48 . V_49 >= V_165 )
return 225000 ;
}
if ( V_14 -> V_166 != V_167 ||
V_23 -> V_26 . V_48 . V_168 >= 0x46 )
return 165000 ;
else if ( V_23 -> V_26 . V_48 . V_168 >= 0x40 )
return 155000 ;
else if ( V_23 -> V_26 . V_48 . V_168 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_63 ( struct V_2 * V_3 ,
struct V_129 * V_112 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
struct V_1 * V_6 = V_17 -> V_47 ;
struct V_7 * V_16 = F_4 ( V_6 ) ;
unsigned V_169 = 25000 , V_170 = V_169 ;
unsigned clock = V_112 -> clock ;
bool V_161 ;
switch ( V_6 -> V_14 -> type ) {
case V_34 :
if ( V_17 -> V_144 &&
( V_112 -> V_141 > V_17 -> V_144 -> V_141 ||
V_112 -> V_142 > V_17 -> V_144 -> V_142 ) )
return V_171 ;
V_169 = 0 ;
V_170 = 400000 ;
break;
case V_40 :
V_161 = F_64 ( V_17 -> V_19 ) ;
V_170 = F_62 ( V_3 , V_161 ) ;
if ( ! V_161 && V_172 &&
V_6 -> V_14 -> V_173 )
V_170 *= 2 ;
break;
case V_41 :
V_170 = V_6 -> V_14 -> V_174 . V_175 ;
if ( ! V_170 )
V_170 = 350000 ;
break;
case V_75 :
return F_48 ( V_16 ) -> V_136 ( V_16 , V_112 ) ;
case V_31 :
V_170 = V_6 -> V_176 . V_177 ;
V_170 *= V_6 -> V_176 . V_178 ;
clock = clock * ( V_3 -> V_152 . V_153 * 3 ) / 10 ;
break;
default:
F_65 ( 1 ) ;
return V_179 ;
}
if ( clock < V_169 )
return V_180 ;
if ( clock > V_170 )
return V_181 ;
return V_137 ;
}
static struct V_7 *
F_66 ( struct V_2 * V_3 )
{
struct V_15 * V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_47 )
return F_4 ( V_17 -> V_47 ) ;
return NULL ;
}
static int
F_67 ( struct V_2 * V_3 , int V_112 )
{
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_16 )
V_6 = V_1 ( V_3 -> V_16 ) ;
if ( V_6 && V_6 -> V_14 &&
V_6 -> V_14 -> type == V_31 ) {
if ( V_112 == V_182 ) {
V_156 V_183 = V_184 ;
F_68 ( V_6 -> V_20 , V_185 , & V_183 , 1 ) ;
F_69 ( 1000 , 2000 ) ;
} else {
V_156 V_183 = V_186 ;
F_68 ( V_6 -> V_20 , V_185 , & V_183 , 1 ) ;
}
}
return F_70 ( V_3 , V_112 ) ;
}
static int
F_71 ( struct V_187 * V_188 )
{
struct V_15 * V_17 =
F_72 ( V_188 , F_73 ( * V_17 ) , V_18 ) ;
struct V_2 * V_3 = & V_17 -> V_56 ;
struct V_22 * V_23 = V_22 ( V_3 -> V_5 ) ;
const struct V_189 * V_190 = V_188 -> V_183 ;
const char * V_42 = V_3 -> V_42 ;
if ( V_190 -> V_191 & V_192 ) {
} else {
bool V_193 = ( V_190 -> V_191 != V_194 ) ;
F_52 ( V_23 , L_7 , V_193 ? L_8 : L_9 , V_42 ) ;
F_74 ( & V_23 -> V_5 -> V_57 . V_195 ) ;
if ( V_193 )
F_70 ( V_3 , V_182 ) ;
else
F_70 ( V_3 , V_196 ) ;
F_75 ( & V_23 -> V_5 -> V_57 . V_195 ) ;
F_76 ( V_3 -> V_5 ) ;
}
return V_197 ;
}
static T_2
F_77 ( struct V_198 * V_199 , struct V_200 * V_201 )
{
struct V_15 * V_17 =
F_72 ( V_199 , F_73 ( * V_17 ) , V_20 ) ;
struct V_1 * V_6 ;
struct V_202 * V_20 ;
int V_32 ;
V_6 = F_1 ( & V_17 -> V_56 , V_31 ) ;
if ( ! V_6 || ! ( V_20 = V_6 -> V_20 ) )
return - V_28 ;
if ( F_78 ( V_201 -> V_203 > 16 ) )
return - V_204 ;
if ( V_201 -> V_203 == 0 )
return V_201 -> V_203 ;
V_32 = F_79 ( V_20 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_80 ( V_20 , false , V_201 -> V_205 , V_201 -> V_206 ,
V_201 -> V_207 , V_201 -> V_203 ) ;
F_81 ( V_20 ) ;
if ( V_32 >= 0 ) {
V_201 -> V_208 = V_32 ;
return V_201 -> V_203 ;
}
return V_32 ;
}
static int
F_82 ( enum V_209 V_14 )
{
switch ( V_14 ) {
case V_210 : return V_211 ;
case V_212 :
case V_213 :
case V_214 : return V_215 ;
case V_216 :
case V_217 :
case V_55 : return V_218 ;
case V_219 : return V_220 ;
case V_68 :
case V_103 : return V_160 ;
case V_221 :
case V_222 :
case V_223 : return V_224 ;
case V_29 : return V_225 ;
case V_226 :
case V_227 :
case V_228 : return V_229 ;
default:
break;
}
return V_230 ;
}
struct V_2 *
F_83 ( struct V_4 * V_5 , int V_231 )
{
const struct V_232 * V_233 = & V_234 ;
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_95 * V_96 = V_95 ( V_5 ) ;
struct V_15 * V_17 = NULL ;
struct V_2 * V_3 ;
int type , V_32 = 0 ;
bool V_235 ;
F_5 (connector, &dev->mode_config.connector_list, head) {
V_17 = V_15 ( V_3 ) ;
if ( V_17 -> V_231 == V_231 )
return V_3 ;
}
V_17 = F_84 ( sizeof( * V_17 ) , V_46 ) ;
if ( ! V_17 )
return F_85 ( - V_236 ) ;
V_3 = & V_17 -> V_56 ;
V_17 -> V_231 = V_231 ;
V_17 -> V_14 = F_86 ( V_5 , V_231 ) ;
if ( V_17 -> V_14 ) {
T_3 V_237 = F_87 ( V_17 -> V_14 [ 0 ] ) ;
if ( F_88 ( V_5 ) [ 3 ] >= 4 )
V_237 |= ( T_3 ) F_87 ( V_17 -> V_14 [ 2 ] ) << 16 ;
V_17 -> type = V_17 -> V_14 [ 0 ] ;
if ( F_82 ( V_17 -> type ) ==
V_230 ) {
F_89 ( V_23 , L_10 ,
V_17 -> type ) ;
V_17 -> type = V_238 ;
}
if ( F_90 ( V_5 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_17 -> type == V_227 )
V_17 -> type = V_55 ;
}
if ( F_90 ( V_5 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_17 -> type == V_227 )
V_17 -> type = V_55 ;
}
} else {
V_17 -> type = V_238 ;
}
if ( V_17 -> type == V_238 ) {
struct V_22 * V_23 = V_22 ( V_5 ) ;
struct V_239 * V_240 = & V_23 -> V_81 . V_14 ;
T_3 V_241 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_240 -> V_242 ; V_9 ++ ) {
if ( V_240 -> V_237 [ V_9 ] . V_3 == V_17 -> V_231 )
V_241 |= ( 1 << V_240 -> V_237 [ V_9 ] . type ) ;
}
if ( V_241 & ( 1 << V_31 ) ) {
if ( V_241 & ( 1 << V_40 ) )
V_17 -> type = V_223 ;
else
V_17 -> type = V_29 ;
} else
if ( V_241 & ( 1 << V_40 ) ) {
if ( V_241 & ( 1 << V_41 ) )
V_17 -> type = V_55 ;
else
V_17 -> type = V_219 ;
} else
if ( V_241 & ( 1 << V_41 ) ) {
V_17 -> type = V_210 ;
} else
if ( V_241 & ( 1 << V_34 ) ) {
V_17 -> type = V_68 ;
} else
if ( V_241 & ( 1 << V_75 ) ) {
V_17 -> type = V_212 ;
}
}
switch ( ( type = F_82 ( V_17 -> type ) ) ) {
case V_160 :
V_32 = F_91 ( V_5 , 0 , & V_235 , & V_235 ) ;
if ( V_32 ) {
F_36 ( V_23 , L_11 ) ;
F_8 ( V_17 ) ;
return F_85 ( V_32 ) ;
}
V_233 = & V_243 ;
break;
case V_224 :
case V_225 :
V_17 -> V_20 . V_5 = V_5 -> V_5 ;
V_17 -> V_20 . V_21 = F_77 ;
V_32 = F_92 ( & V_17 -> V_20 ) ;
if ( V_32 ) {
F_36 ( V_23 , L_12 ) ;
F_8 ( V_17 ) ;
return F_85 ( V_32 ) ;
}
V_233 = & V_244 ;
break;
default:
V_233 = & V_234 ;
break;
}
V_3 -> V_51 = false ;
V_3 -> V_52 = false ;
F_93 ( V_5 , V_3 , V_233 , type ) ;
F_94 ( V_3 , & V_245 ) ;
if ( V_17 -> type == V_55 )
F_95 ( & V_3 -> V_56 , V_5 -> V_57 . V_58 , 0 ) ;
if ( V_96 -> V_115 &&
( type == V_220 ||
type == V_218 ||
type == V_229 ||
type == V_224 ) ) {
F_95 ( & V_3 -> V_56 ,
V_96 -> V_115 ,
V_246 ) ;
F_95 ( & V_3 -> V_56 ,
V_96 -> V_117 ,
0 ) ;
F_95 ( & V_3 -> V_56 ,
V_96 -> V_119 ,
0 ) ;
}
if ( V_96 -> V_125 )
F_95 ( & V_3 -> V_56 ,
V_96 -> V_125 ,
90 ) ;
if ( V_96 -> V_127 )
F_95 ( & V_3 -> V_56 ,
V_96 -> V_127 ,
150 ) ;
switch ( V_17 -> type ) {
case V_68 :
case V_103 :
case V_29 :
if ( V_96 -> V_96 . V_104 < V_105 ) {
V_17 -> V_110 = V_107 ;
break;
}
V_17 -> V_110 = V_102 ;
break;
default:
V_17 -> V_110 = V_102 ;
break;
}
switch ( V_17 -> type ) {
case V_212 :
case V_213 :
case V_214 :
break;
case V_210 :
if ( V_96 -> V_96 . V_104 < V_105 )
break;
default:
F_95 ( & V_3 -> V_56 , V_5 -> V_57 .
V_100 ,
V_17 -> V_110 ) ;
break;
}
switch ( V_17 -> type ) {
case V_212 :
case V_213 :
case V_214 :
case V_210 :
break;
default:
if ( V_96 -> V_121 ) {
V_17 -> V_121 = V_247 ;
F_95 ( & V_3 -> V_56 ,
V_96 -> V_121 ,
V_17 ->
V_121 ) ;
}
if ( V_96 -> V_123 ) {
V_17 -> V_123 = V_248 ;
F_95 ( & V_3 -> V_56 ,
V_96 -> V_123 ,
V_17 ->
V_123 ) ;
}
break;
}
V_32 = F_96 (&disp->disp, nouveau_connector_hotplug, true,
NV04_DISP_NTFY_CONN,
&(struct nvif_notify_conn_req_v0) {
.mask = NVIF_NOTIFY_CONN_V0_ANY,
.conn = index,
},
sizeof(struct nvif_notify_conn_req_v0),
sizeof(struct nvif_notify_conn_rep_v0),
&nv_connector->hpd) ;
if ( V_32 )
V_3 -> V_249 = V_250 ;
else
V_3 -> V_249 = V_251 ;
F_97 ( V_3 ) ;
return V_3 ;
}
