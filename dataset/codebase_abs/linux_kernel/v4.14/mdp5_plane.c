static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static bool F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_11 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_12 ) ;
}
static void F_10 ( struct V_13 * V_6 ,
struct V_2 * V_3 )
{
F_11 ( V_3 ,
V_14 ,
V_14 |
V_15 |
V_16 |
V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_13 * V_6 = V_3 -> V_6 ;
struct V_4 * V_20 = V_6 -> V_7 ;
struct V_21 * V_22 ;
#define F_13 ( T_1 , T_2 , T_3 , T_4 , ... ) do { \
prop = dev_priv->plane_property[PLANE_PROP_##NAME]; \
if (!prop) { \
prop = drm_property_##fnc(dev, 0, #name, \
##__VA_ARGS__); \
if (!prop) { \
dev_warn(dev->dev, \
"Create property %s failed\n", \
#name); \
return; \
} \
dev_priv->plane_property[PLANE_PROP_##NAME] = prop; \
} \
drm_object_attach_property(&plane->base, prop, init_val); \
} while (0)
#define F_14 ( T_1 , T_2 , T_5 , T_6 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_range, min, max)
#define F_15 ( T_1 , T_2 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_enum, name##_prop_enum_list, \
ARRAY_SIZE(name##_prop_enum_list))
F_14 ( V_23 , V_24 , 1 , 255 , 1 ) ;
F_10 ( V_6 , V_3 ) ;
#undef F_14
#undef F_15
#undef F_13
}
static int F_16 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_21 * V_25 ,
T_7 V_26 )
{
struct V_13 * V_6 = V_3 -> V_6 ;
struct V_27 * V_28 ;
struct V_4 * V_20 = V_6 -> V_7 ;
int V_29 = 0 ;
V_28 = F_17 ( V_10 ) ;
#define F_18 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
pstate->name = (type)val; \
DBG("Set property %s %d", #name, (type)val); \
goto done; \
} \
} while (0)
F_18 ( V_23 , V_24 , V_30 ) ;
F_19 ( V_6 -> V_6 , L_1 ) ;
V_29 = - V_31 ;
V_32:
return V_29 ;
#undef F_18
}
static int F_20 ( struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_21 * V_25 , T_7 * V_26 )
{
struct V_13 * V_6 = V_3 -> V_6 ;
struct V_27 * V_28 ;
struct V_4 * V_20 = V_6 -> V_7 ;
int V_29 = 0 ;
V_28 = F_17 ( V_10 ) ;
#define F_21 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
*val = pstate->name; \
DBG("Get property %s %lld", #name, *val); \
goto done; \
} \
} while (0)
F_21 ( V_23 , V_24 , V_30 ) ;
F_19 ( V_6 -> V_6 , L_1 ) ;
V_29 = - V_31 ;
V_32:
return V_29 ;
#undef F_18
}
static void
F_22 ( struct V_33 * V_34 ,
const struct V_9 * V_10 )
{
struct V_27 * V_28 = F_17 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_10 -> V_3 ) ;
F_23 ( V_34 , L_2 , V_28 -> V_35 ?
V_28 -> V_35 -> T_1 : L_3 ) ;
if ( V_1 -> V_36 & V_37 )
F_23 ( V_34 , L_4 ,
V_28 -> V_38 ? V_28 -> V_38 -> T_1 :
L_3 ) ;
F_23 ( V_34 , L_5 , V_28 -> V_39 ) ;
F_23 ( V_34 , L_6 , V_28 -> V_23 ) ;
F_23 ( V_34 , L_7 , V_28 -> V_40 ) ;
F_23 ( V_34 , L_8 , F_24 ( V_28 -> V_41 ) ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_27 * V_42 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_43 )
F_26 ( V_3 -> V_10 -> V_43 ) ;
F_9 ( F_17 ( V_3 -> V_10 ) ) ;
V_42 = F_27 ( sizeof( * V_42 ) , V_44 ) ;
V_42 -> V_40 = 255 ;
V_42 -> V_39 = 0 ;
if ( V_3 -> type == V_45 )
V_42 -> V_23 = V_46 ;
else
V_42 -> V_23 = V_47 + F_28 ( V_3 ) ;
V_42 -> V_48 . V_3 = V_3 ;
V_3 -> V_10 = & V_42 -> V_48 ;
}
static struct V_9 *
F_29 ( struct V_2 * V_3 )
{
struct V_27 * V_42 ;
if ( F_30 ( ! V_3 -> V_10 ) )
return NULL ;
V_42 = F_31 ( F_17 ( V_3 -> V_10 ) ,
sizeof( * V_42 ) , V_44 ) ;
if ( ! V_42 )
return NULL ;
F_32 ( V_3 , & V_42 -> V_48 ) ;
return & V_42 -> V_48 ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_27 * V_28 = F_17 ( V_10 ) ;
if ( V_10 -> V_43 )
F_26 ( V_10 -> V_43 ) ;
F_9 ( V_28 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_9 * V_49 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_8 = & V_1 -> V_48 . V_48 ;
struct V_51 * V_43 = V_49 -> V_43 ;
if ( ! V_49 -> V_43 )
return 0 ;
F_35 ( L_9 , V_3 -> T_1 , V_43 -> V_48 . V_52 ) ;
return F_36 ( V_43 , V_8 -> V_53 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_9 * V_54 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_8 = & V_1 -> V_48 . V_48 ;
struct V_51 * V_43 = V_54 -> V_43 ;
if ( ! V_43 )
return;
F_35 ( L_10 , V_3 -> T_1 , V_43 -> V_48 . V_52 ) ;
F_38 ( V_43 , V_8 -> V_53 ) ;
}
static int F_39 ( struct V_55 * V_56 ,
struct V_9 * V_10 )
{
struct V_27 * V_42 = F_17 ( V_10 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_9 * V_54 = V_3 -> V_10 ;
struct V_57 * V_58 = F_40 ( F_1 ( V_3 ) -> V_59 ) ;
bool V_60 = false ;
bool V_61 = false ;
T_8 V_62 , V_63 ;
bool V_64 = false ;
T_8 V_36 = 0 ;
struct V_65 V_66 ;
int V_67 , V_68 ;
int V_29 ;
F_35 ( L_11 , V_3 -> T_1 ,
F_4 ( V_54 ) , F_4 ( V_10 ) ) ;
V_62 = V_58 -> V_69 -> V_70 . V_62 << 16 ;
V_63 = V_58 -> V_69 -> V_70 . V_63 << 16 ;
if ( V_10 -> V_71 > V_63 )
V_64 = true ;
if ( V_10 -> V_72 > V_62 ) {
if ( V_58 -> V_69 -> V_73 . V_36 & V_37 &&
( V_10 -> V_72 <= 2 * V_62 ) )
V_61 = true ;
else
V_64 = true ;
}
if ( V_64 ) {
struct V_65 V_74 = F_41 ( V_10 ) ;
F_35 ( L_12 V_75 ,
F_42 ( & V_74 ) ) ;
return - V_76 ;
}
V_66 . V_77 = 0 ;
V_66 . y1 = 0 ;
V_66 . V_78 = V_56 -> V_79 . V_80 ;
V_66 . V_81 = V_56 -> V_79 . V_82 ;
V_67 = F_43 ( 1 , 8 ) ;
V_68 = F_43 ( 8 , 1 ) ;
V_29 = F_44 ( V_10 , & V_66 , V_67 ,
V_68 , true , true ) ;
if ( V_29 )
return V_29 ;
if ( F_4 ( V_10 ) ) {
unsigned int V_83 ;
const struct V_84 * V_85 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_8 V_86 = 0 ;
V_85 = F_45 ( F_46 ( V_10 -> V_43 ) ) ;
if ( F_47 ( V_85 ) )
V_36 |= V_87 | V_88 ;
if ( ( ( V_10 -> V_72 >> 16 ) != V_10 -> V_89 ) ||
( ( V_10 -> V_71 >> 16 ) != V_10 -> V_90 ) )
V_36 |= V_87 ;
V_83 = F_48 ( V_10 -> V_83 ,
V_14 |
V_16 |
V_17 ) ;
if ( V_83 & V_16 )
V_36 |= V_91 ;
if ( V_83 & V_17 )
V_36 |= V_92 ;
if ( V_3 -> type == V_93 )
V_36 |= V_94 ;
if ( ! V_42 -> V_35 || ( V_36 & ~ V_42 -> V_35 -> V_36 ) )
V_60 = true ;
if ( ( V_61 && ! V_42 -> V_38 ) ||
( ! V_61 && V_42 -> V_38 ) )
V_60 = true ;
if ( V_1 -> V_95 ) {
const struct V_84 * V_85 =
F_45 ( F_46 ( V_10 -> V_43 ) ) ;
V_86 = F_49 ( V_1 -> V_95 , V_85 ,
V_10 -> V_72 >> 16 , false ) ;
if ( V_42 -> V_35 && ( V_42 -> V_35 -> V_86 != V_86 ) )
V_60 = true ;
}
if ( V_60 ) {
struct V_96 * V_97 = V_42 -> V_35 ;
struct V_96 * V_98 =
V_42 -> V_38 ;
V_42 -> V_35 = F_50 ( V_10 -> V_10 ,
V_3 , V_36 , V_86 ) ;
if ( F_51 ( V_42 -> V_35 ) ) {
F_35 ( L_13 , V_3 -> T_1 ) ;
return F_52 ( V_42 -> V_35 ) ;
}
if ( V_61 ) {
V_42 -> V_38 =
F_50 ( V_10 -> V_10 , V_3 ,
V_36 , V_86 ) ;
if ( F_51 ( V_42 -> V_38 ) ) {
F_35 ( L_14 ,
V_3 -> T_1 ) ;
return F_52 ( V_42 -> V_38 ) ;
}
} else {
V_42 -> V_38 = NULL ;
}
F_53 ( V_10 -> V_10 , V_97 ) ;
F_53 ( V_10 -> V_10 , V_98 ) ;
}
} else {
F_53 ( V_10 -> V_10 , V_42 -> V_35 ) ;
F_53 ( V_10 -> V_10 , V_42 -> V_38 ) ;
V_42 -> V_35 = V_42 -> V_38 = NULL ;
}
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_99 * V_100 ;
struct V_55 * V_56 ;
V_100 = V_10 -> V_100 ? V_10 -> V_100 : V_3 -> V_10 -> V_100 ;
if ( ! V_100 )
return 0 ;
V_56 = F_55 ( V_10 -> V_10 , V_100 ) ;
if ( F_30 ( ! V_56 ) )
return - V_31 ;
return F_39 ( V_56 , V_10 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_9 * V_54 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
F_35 ( L_15 , V_3 -> T_1 ) ;
if ( F_4 ( V_10 ) ) {
int V_29 ;
V_29 = F_57 ( V_3 ,
V_10 -> V_100 , V_10 -> V_43 ,
& V_10 -> V_74 , & V_10 -> V_101 ) ;
F_30 ( V_29 < 0 ) ;
}
}
static void F_58 ( struct V_1 * V_1 ,
enum V_102 V_103 ,
struct V_51 * V_43 )
{
struct V_50 * V_8 = & V_1 -> V_48 . V_48 ;
F_59 ( V_1 , F_60 ( V_103 ) ,
F_61 ( V_43 -> V_104 [ 0 ] ) |
F_62 ( V_43 -> V_104 [ 1 ] ) ) ;
F_59 ( V_1 , F_63 ( V_103 ) ,
F_64 ( V_43 -> V_104 [ 2 ] ) |
F_65 ( V_43 -> V_104 [ 3 ] ) ) ;
F_59 ( V_1 , F_66 ( V_103 ) ,
F_67 ( V_43 , V_8 -> V_53 , 0 ) ) ;
F_59 ( V_1 , F_68 ( V_103 ) ,
F_67 ( V_43 , V_8 -> V_53 , 1 ) ) ;
F_59 ( V_1 , F_69 ( V_103 ) ,
F_67 ( V_43 , V_8 -> V_53 , 2 ) ) ;
F_59 ( V_1 , F_70 ( V_103 ) ,
F_67 ( V_43 , V_8 -> V_53 , 3 ) ) ;
}
static void F_71 ( struct V_1 * V_1 , enum V_102 V_103 )
{
T_8 V_105 = F_72 ( V_1 , F_73 ( V_103 ) ) &
~ V_106 ;
F_59 ( V_1 , F_73 ( V_103 ) , V_105 ) ;
}
static void F_74 ( struct V_1 * V_1 , enum V_102 V_103 ,
struct V_107 * V_108 )
{
T_8 V_109 , V_110 = 0 ;
T_8 * V_111 ;
if ( F_75 ( ! V_108 ) )
return;
if ( ( V_108 -> type == V_112 ) || ( V_113 == V_108 -> type ) )
V_110 |= F_76 ( V_114 ) ;
if ( ( V_108 -> type == V_115 ) || ( V_113 == V_108 -> type ) )
V_110 |= F_77 ( V_114 ) ;
V_110 |= V_106 ;
F_59 ( V_1 , F_73 ( V_103 ) , V_110 ) ;
V_111 = V_108 -> V_111 ;
F_59 ( V_1 , F_78 ( V_103 ) ,
F_79 ( V_111 [ 0 ] ) |
F_80 ( V_111 [ 1 ] ) ) ;
F_59 ( V_1 , F_81 ( V_103 ) ,
F_82 ( V_111 [ 2 ] ) |
F_83 ( V_111 [ 3 ] ) ) ;
F_59 ( V_1 , F_84 ( V_103 ) ,
F_85 ( V_111 [ 4 ] ) |
F_86 ( V_111 [ 5 ] ) ) ;
F_59 ( V_1 , F_87 ( V_103 ) ,
F_88 ( V_111 [ 6 ] ) |
F_89 ( V_111 [ 7 ] ) ) ;
F_59 ( V_1 , F_90 ( V_103 ) ,
F_91 ( V_111 [ 8 ] ) ) ;
for ( V_109 = 0 ; V_109 < F_92 ( V_108 -> V_116 ) ; V_109 ++ ) {
T_8 * V_117 = V_108 -> V_117 ;
T_8 * V_118 = V_108 -> V_118 ;
F_59 ( V_1 , F_93 ( V_103 , V_109 ) ,
F_94 ( V_117 [ 2 * V_109 + 1 ] ) |
F_95 ( V_117 [ 2 * V_109 ] ) ) ;
F_59 ( V_1 , F_96 ( V_103 , V_109 ) ,
F_97 ( V_118 [ 2 * V_109 + 1 ] ) |
F_98 ( V_118 [ 2 * V_109 ] ) ) ;
F_59 ( V_1 , F_99 ( V_103 , V_109 ) ,
F_100 ( V_108 -> V_116 [ V_109 ] ) ) ;
F_59 ( V_1 , F_101 ( V_103 , V_109 ) ,
F_102 ( V_108 -> V_119 [ V_109 ] ) ) ;
}
}
static int F_103 ( T_8 V_74 , T_8 V_101 , T_8 * V_120 )
{
T_8 V_121 ;
if ( V_74 == 0 || V_101 == 0 )
return - V_31 ;
if ( V_74 > ( V_101 * V_122 ) )
return - V_123 ;
V_121 = 1 << V_124 ;
* V_120 = F_104 ( V_121 , V_74 , V_101 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 ,
T_8 V_125 , T_8 V_74 , T_8 V_126 ,
T_8 V_127 [ V_128 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_129 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_130 ;
unsigned int V_131 ;
int V_29 ;
V_29 = F_103 ( V_74 , V_126 , & V_130 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_16 , V_74 , V_126 , V_29 ) ;
return V_29 ;
}
V_131 = F_106 ( V_125 ) ;
V_127 [ V_132 ] = V_130 ;
V_127 [ V_133 ] = V_130 ;
V_127 [ V_134 ] = V_130 / V_131 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_8 V_125 , T_8 V_74 , T_8 V_126 ,
T_8 V_135 [ V_128 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_129 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_136 ;
unsigned int V_137 ;
int V_29 ;
V_29 = F_103 ( V_74 , V_126 , & V_136 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_17 , V_74 , V_126 , V_29 ) ;
return V_29 ;
}
V_137 = F_108 ( V_125 ) ;
V_135 [ V_132 ] = V_136 ;
V_135 [ V_133 ] = V_136 ;
V_135 [ V_134 ] = V_136 / V_137 ;
return 0 ;
}
static T_8 F_109 ( const struct V_84 * V_85 ,
T_8 V_74 , T_8 V_101 , bool V_138 )
{
bool V_139 = V_85 -> V_140 ? true : ( V_74 != V_101 ) ;
T_8 V_141 , V_142 = V_85 -> V_48 . V_125 ;
T_8 V_143 , V_144 ;
bool V_145 = V_85 -> V_140 ;
if ( ! V_139 )
return 0 ;
if ( V_145 ) {
V_141 = V_138 ? F_106 ( V_142 ) :
F_108 ( V_142 ) ;
V_144 = ( ( V_74 / V_141 ) <= V_101 ) ?
V_146 : V_147 ;
}
V_143 = ( V_74 <= V_101 ) ? V_146 : V_147 ;
if ( V_138 )
return V_148 |
F_110 ( V_143 ) |
F_111 ( V_143 ) |
F_112 ( V_145 , F_113 ( V_144 ) ) ;
else
return V_149 |
F_114 ( V_143 ) |
F_115 ( V_143 ) |
F_112 ( V_145 , F_116 ( V_144 ) ) ;
}
static void F_117 ( const struct V_84 * V_85 ,
T_8 V_74 , T_8 V_101 , T_8 V_150 [ 2 ] ,
int V_151 [ V_128 ] , int V_152 [ V_128 ] ,
bool V_138 )
{
bool V_139 = V_85 -> V_140 ? true : ( V_74 != V_101 ) ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_128 ; V_109 ++ ) {
V_151 [ V_109 ] = 0 ;
V_152 [ V_109 ] = V_139 ? 1 : 0 ;
}
}
static void F_118 ( struct V_1 * V_1 , enum V_102 V_103 ,
const struct V_84 * V_85 ,
T_8 V_72 , int V_153 [ V_128 ] , int V_154 [ V_128 ] ,
T_8 V_71 , int V_155 [ V_128 ] , int V_156 [ V_128 ] )
{
T_8 V_142 = V_85 -> V_48 . V_125 ;
T_8 V_157 , V_158 , V_159 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_128 ; V_109 ++ ) {
T_8 V_160 = V_72 ;
T_8 V_161 = V_71 ;
if ( V_85 -> V_140 && V_109 == V_134 ) {
V_160 /= F_106 ( V_142 ) ;
V_161 /= F_108 ( V_142 ) ;
}
V_157 = ( V_153 [ V_109 ] >= 0 ) ?
F_119 ( V_153 [ V_109 ] ) :
F_120 ( V_153 [ V_109 ] ) ;
V_157 |= ( V_154 [ V_109 ] >= 0 ) ?
F_121 ( V_154 [ V_109 ] ) :
F_122 ( V_154 [ V_109 ] ) ;
V_158 = ( V_155 [ V_109 ] >= 0 ) ?
F_123 ( V_155 [ V_109 ] ) :
F_124 ( V_155 [ V_109 ] ) ;
V_158 |= ( V_156 [ V_109 ] >= 0 ) ?
F_125 ( V_156 [ V_109 ] ) :
F_126 ( V_156 [ V_109 ] ) ;
V_159 = F_127 ( V_160 +
V_153 [ V_109 ] + V_154 [ V_109 ] ) ;
V_159 |= F_128 ( V_161 +
V_155 [ V_109 ] + V_156 [ V_109 ] ) ;
F_59 ( V_1 , F_129 ( V_103 , V_109 ) , V_157 ) ;
F_59 ( V_1 , F_130 ( V_103 , V_109 ) , V_158 ) ;
F_59 ( V_1 , F_131 ( V_103 , V_109 ) , V_159 ) ;
F_35 ( L_18 , V_109 ,
F_132 ( V_157 , F_119 ) ,
F_132 ( V_157 , F_121 ) ,
F_132 ( V_157 , F_120 ) ,
F_132 ( V_157 , F_122 ) ,
F_132 ( V_159 , F_127 ) ) ;
F_35 ( L_19 , V_109 ,
F_132 ( V_158 , F_123 ) ,
F_132 ( V_158 , F_125 ) ,
F_132 ( V_158 , F_124 ) ,
F_132 ( V_158 , F_126 ) ,
F_132 ( V_159 , F_128 ) ) ;
}
}
static void F_133 ( struct V_1 * V_1 ,
struct V_96 * V_35 ,
struct V_51 * V_43 ,
struct V_150 * V_162 ,
struct V_163 * V_164 ,
T_9 V_165 , T_9 V_166 , T_9 V_167 ,
bool V_168 , bool V_169 ,
int V_170 , int V_171 ,
unsigned int V_89 , unsigned int V_90 ,
T_9 V_172 , T_9 V_173 ,
T_9 V_174 , T_9 V_175 ,
T_9 V_72 , T_9 V_71 )
{
enum V_102 V_103 = V_35 -> V_103 ;
bool V_176 = V_35 -> V_36 & V_177 ;
const struct V_84 * V_85 =
F_45 ( F_46 ( V_43 ) ) ;
F_59 ( V_1 , F_134 ( V_103 ) ,
F_135 ( V_172 ) |
F_136 ( V_173 ) ) ;
F_59 ( V_1 , F_137 ( V_103 ) ,
F_138 ( V_72 ) |
F_139 ( V_71 ) ) ;
F_59 ( V_1 , F_140 ( V_103 ) ,
F_141 ( V_174 ) |
F_142 ( V_175 ) ) ;
F_59 ( V_1 , F_143 ( V_103 ) ,
F_144 ( V_89 ) |
F_145 ( V_90 ) ) ;
F_59 ( V_1 , F_146 ( V_103 ) ,
F_147 ( V_170 ) |
F_148 ( V_171 ) ) ;
F_59 ( V_1 , F_149 ( V_103 ) ,
F_150 ( V_85 -> V_178 ) |
F_151 ( V_85 -> V_179 ) |
F_152 ( V_85 -> V_180 ) |
F_153 ( V_85 -> V_181 ) |
F_112 ( V_85 -> V_182 , V_183 ) |
F_154 ( V_85 -> V_184 - 1 ) |
F_155 ( V_85 -> V_185 - 1 ) |
F_112 ( V_85 -> V_186 , V_187 ) |
F_156 ( V_85 -> V_188 ) |
F_157 ( V_85 -> V_189 ) ) ;
F_59 ( V_1 , F_158 ( V_103 ) ,
F_159 ( V_85 -> V_190 [ 0 ] ) |
F_160 ( V_85 -> V_190 [ 1 ] ) |
F_161 ( V_85 -> V_190 [ 2 ] ) |
F_162 ( V_85 -> V_190 [ 3 ] ) ) ;
F_59 ( V_1 , F_163 ( V_103 ) ,
( V_168 ? V_191 : 0 ) |
( V_169 ? V_192 : 0 ) |
F_112 ( V_176 , V_193 ) |
F_164 ( V_194 ) ) ;
F_59 ( V_1 , F_165 ( V_103 ) , 0 ) ;
if ( V_35 -> V_36 & V_177 )
F_118 ( V_1 , V_103 , V_85 ,
V_72 , V_164 -> V_195 , V_164 -> V_196 ,
V_71 , V_164 -> V_197 , V_164 -> V_198 ) ;
if ( V_35 -> V_36 & V_87 ) {
F_59 ( V_1 , F_166 ( V_103 ) ,
V_162 -> V_199 [ V_132 ] ) ;
F_59 ( V_1 , F_167 ( V_103 ) ,
V_162 -> V_200 [ V_132 ] ) ;
F_59 ( V_1 , F_168 ( V_103 ) ,
V_162 -> V_199 [ V_134 ] ) ;
F_59 ( V_1 , F_169 ( V_103 ) ,
V_162 -> V_200 [ V_134 ] ) ;
F_59 ( V_1 , F_170 ( V_103 ) ,
F_171 ( V_167 ) |
F_172 ( V_166 ) ) ;
F_59 ( V_1 , F_173 ( V_103 ) ,
V_165 ) ;
}
if ( V_35 -> V_36 & V_88 ) {
if ( F_47 ( V_85 ) )
F_74 ( V_1 , V_103 ,
F_174 ( V_112 ) ) ;
else
F_71 ( V_1 , V_103 ) ;
}
F_58 ( V_1 , V_103 , V_43 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_99 * V_100 , struct V_51 * V_43 ,
struct V_65 * V_74 , struct V_65 * V_126 )
{
struct V_9 * V_28 = V_3 -> V_10 ;
struct V_96 * V_35 = F_17 ( V_28 ) -> V_35 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_102 V_103 = V_35 -> V_103 ;
struct V_96 * V_201 ;
const struct V_84 * V_85 ;
T_8 V_202 , V_58 = 0 ;
struct V_150 V_162 = { { 0 } } ;
struct V_163 V_164 = { { 0 } } ;
T_8 V_166 = 0 , V_167 = 0 ;
T_8 V_203 ;
unsigned int V_83 ;
bool V_169 , V_168 ;
int V_170 , V_171 ;
unsigned int V_89 , V_90 ;
T_8 V_174 , V_175 ;
T_8 V_72 , V_71 ;
T_8 V_172 , V_173 ;
T_8 V_204 ;
int V_205 ;
int V_29 ;
V_202 = V_43 -> V_85 -> V_206 ;
if ( F_30 ( V_202 > F_175 ( V_103 ) ) )
return - V_31 ;
V_85 = F_45 ( F_46 ( V_43 ) ) ;
V_203 = V_85 -> V_48 . V_125 ;
V_174 = V_74 -> V_77 ;
V_175 = V_74 -> y1 ;
V_72 = F_176 ( V_74 ) ;
V_71 = F_177 ( V_74 ) ;
V_170 = V_126 -> V_77 ;
V_171 = V_126 -> y1 ;
V_89 = F_176 ( V_126 ) ;
V_90 = F_177 ( V_126 ) ;
V_174 = V_174 >> 16 ;
V_175 = V_175 >> 16 ;
V_72 = V_72 >> 16 ;
V_71 = V_71 >> 16 ;
V_172 = T_5 ( V_43 -> V_207 , V_72 ) ;
V_173 = T_5 ( V_43 -> V_208 , V_71 ) ;
F_35 ( L_20 , V_3 -> T_1 ,
V_43 -> V_48 . V_52 , V_174 , V_175 , V_72 , V_71 ,
V_100 -> V_48 . V_52 , V_170 , V_171 , V_89 , V_90 ) ;
V_201 = F_17 ( V_28 ) -> V_38 ;
if ( V_201 ) {
V_89 /= 2 ;
V_72 /= 2 ;
V_172 /= 2 ;
V_205 = V_170 + V_89 ;
V_204 = V_174 + V_72 ;
}
V_29 = F_105 ( V_3 , V_203 , V_72 , V_89 , V_162 . V_199 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_107 ( V_3 , V_203 , V_71 , V_90 , V_162 . V_200 ) ;
if ( V_29 )
return V_29 ;
if ( V_35 -> V_36 & V_177 ) {
F_117 ( V_85 , V_72 , V_89 , V_162 . V_199 ,
V_164 . V_195 , V_164 . V_196 , true ) ;
F_117 ( V_85 , V_71 , V_90 , V_162 . V_200 ,
V_164 . V_197 , V_164 . V_198 , false ) ;
}
V_58 |= F_109 ( V_85 , V_72 , V_89 , true ) ;
V_58 |= F_109 ( V_85 , V_71 , V_90 , false ) ;
F_35 ( L_21 , V_58 ) ;
V_83 = F_48 ( V_28 -> V_83 ,
V_14 |
V_16 |
V_17 ) ;
V_168 = ! ! ( V_83 & V_16 ) ;
V_169 = ! ! ( V_83 & V_17 ) ;
F_133 ( V_1 , V_35 , V_43 , & V_162 , & V_164 ,
V_58 , V_166 , V_167 , V_168 , V_169 ,
V_170 , V_171 , V_89 , V_90 ,
V_172 , V_173 ,
V_174 , V_175 , V_72 , V_71 ) ;
if ( V_201 )
F_133 ( V_1 , V_201 , V_43 , & V_162 , & V_164 ,
V_58 , V_166 , V_167 , V_168 , V_169 ,
V_205 , V_171 , V_89 , V_90 ,
V_172 , V_173 ,
V_204 , V_175 , V_72 , V_71 ) ;
V_3 -> V_43 = V_43 ;
return V_29 ;
}
static int F_178 ( struct V_2 * V_3 ,
struct V_99 * V_100 , struct V_51 * V_43 ,
int V_170 , int V_171 ,
unsigned int V_89 , unsigned int V_90 ,
T_8 V_174 , T_8 V_175 ,
T_8 V_72 , T_8 V_71 ,
struct V_209 * V_210 )
{
struct V_9 * V_211 , * V_212 ;
struct V_27 * V_213 ;
struct V_55 * V_56 = V_100 -> V_10 ;
int V_29 ;
if ( ! V_56 -> V_214 || F_179 ( V_56 ) )
goto V_215;
V_211 = V_3 -> V_10 ;
V_213 = F_17 ( V_211 ) ;
if ( ! V_213 -> V_35 )
goto V_215;
if ( V_211 -> V_100 != V_100 ||
V_211 -> V_72 != V_72 ||
V_211 -> V_71 != V_71 ||
V_211 -> V_89 != V_89 ||
V_211 -> V_90 != V_90 ||
! V_211 -> V_43 ||
V_211 -> V_43 != V_43 )
goto V_215;
V_212 = F_29 ( V_3 ) ;
if ( ! V_212 )
return - V_216 ;
V_212 -> V_174 = V_174 ;
V_212 -> V_175 = V_175 ;
V_212 -> V_72 = V_72 ;
V_212 -> V_71 = V_71 ;
V_212 -> V_170 = V_170 ;
V_212 -> V_171 = V_171 ;
V_212 -> V_89 = V_89 ;
V_212 -> V_90 = V_90 ;
V_29 = F_39 ( V_56 , V_212 ) ;
if ( V_29 )
goto V_217;
if ( V_212 -> V_11 ) {
struct V_218 * V_219 ;
struct V_220 * V_221 = F_180 ( V_100 ) ;
V_29 = F_57 ( V_3 , V_100 , V_43 ,
& V_212 -> V_74 ,
& V_212 -> V_101 ) ;
F_30 ( V_29 < 0 ) ;
V_219 = F_181 ( V_100 ) ;
F_182 ( V_219 , V_221 , F_183 ( V_3 ) ) ;
}
* F_17 ( V_211 ) =
* F_17 ( V_212 ) ;
F_33 ( V_3 , V_212 ) ;
return 0 ;
V_217:
F_33 ( V_3 , V_212 ) ;
V_215:
return F_184 ( V_3 , V_100 , V_43 ,
V_170 , V_171 , V_89 , V_90 ,
V_174 , V_175 , V_72 , V_71 , V_210 ) ;
}
enum V_102 F_185 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_28 -> V_35 ) )
return V_222 ;
return V_28 -> V_35 -> V_103 ;
}
enum V_102 F_186 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( ! V_28 -> V_38 )
return V_222 ;
return V_28 -> V_38 -> V_103 ;
}
T_8 F_183 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
T_9 V_223 ;
if ( F_30 ( ! V_28 -> V_35 ) )
return 0 ;
V_223 = V_28 -> V_35 -> V_224 ;
if ( V_28 -> V_38 )
V_223 |= V_28 -> V_38 -> V_224 ;
return V_223 ;
}
struct V_2 * F_187 ( struct V_13 * V_6 ,
enum V_225 type )
{
struct V_2 * V_3 = NULL ;
struct V_12 * V_12 ;
int V_29 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_44 ) ;
if ( ! V_12 ) {
V_29 = - V_216 ;
goto V_226;
}
V_3 = & V_12 -> V_48 ;
V_12 -> V_227 = F_188 ( V_12 -> V_228 ,
F_92 ( V_12 -> V_228 ) , false ) ;
if ( type == V_93 )
V_29 = F_189 ( V_6 , V_3 , 0xff ,
& V_229 ,
V_12 -> V_228 , V_12 -> V_227 ,
NULL , type , NULL ) ;
else
V_29 = F_189 ( V_6 , V_3 , 0xff ,
& V_230 ,
V_12 -> V_228 , V_12 -> V_227 ,
NULL , type , NULL ) ;
if ( V_29 )
goto V_226;
F_190 ( V_3 , & V_231 ) ;
F_12 ( V_3 , & V_3 -> V_48 ) ;
return V_3 ;
V_226:
if ( V_3 )
F_5 ( V_3 ) ;
return F_191 ( V_29 ) ;
}
