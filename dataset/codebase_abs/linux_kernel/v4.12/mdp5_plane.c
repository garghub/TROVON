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
struct V_50 * V_43 = V_49 -> V_43 ;
if ( ! V_49 -> V_43 )
return 0 ;
F_35 ( L_9 , V_3 -> T_1 , V_43 -> V_48 . V_51 ) ;
return F_36 ( V_43 , V_1 -> V_51 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_9 * V_52 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_43 = V_52 -> V_43 ;
if ( ! V_43 )
return;
F_35 ( L_10 , V_3 -> T_1 , V_43 -> V_48 . V_51 ) ;
F_38 ( V_43 , V_1 -> V_51 ) ;
}
static int F_39 ( struct V_53 * V_54 ,
struct V_9 * V_10 )
{
struct V_27 * V_42 = F_17 ( V_10 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_9 * V_52 = V_3 -> V_10 ;
struct V_55 * V_56 = F_40 ( F_1 ( V_3 ) -> V_57 ) ;
bool V_58 = false ;
bool V_59 = false ;
T_8 V_60 , V_61 ;
bool V_62 = false ;
T_8 V_36 = 0 ;
struct V_63 V_64 ;
int V_65 , V_66 ;
int V_29 ;
F_35 ( L_11 , V_3 -> T_1 ,
F_4 ( V_52 ) , F_4 ( V_10 ) ) ;
V_60 = V_56 -> V_67 -> V_68 . V_60 << 16 ;
V_61 = V_56 -> V_67 -> V_68 . V_61 << 16 ;
if ( V_10 -> V_69 > V_61 )
V_62 = true ;
if ( V_10 -> V_70 > V_60 ) {
if ( V_56 -> V_67 -> V_71 . V_36 & V_37 &&
( V_10 -> V_70 <= 2 * V_60 ) )
V_59 = true ;
else
V_62 = true ;
}
if ( V_62 ) {
struct V_63 V_72 = F_41 ( V_10 ) ;
F_35 ( L_12 V_73 ,
F_42 ( & V_72 ) ) ;
return - V_74 ;
}
V_64 . V_75 = 0 ;
V_64 . y1 = 0 ;
V_64 . V_76 = V_54 -> V_77 . V_78 ;
V_64 . V_79 = V_54 -> V_77 . V_80 ;
V_65 = F_43 ( 1 , 8 ) ;
V_66 = F_43 ( 8 , 1 ) ;
V_29 = F_44 ( V_10 , & V_64 , V_65 ,
V_66 , true , true ) ;
if ( V_29 )
return V_29 ;
if ( F_4 ( V_10 ) ) {
unsigned int V_81 ;
const struct V_82 * V_83 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_8 V_84 = 0 ;
V_83 = F_45 ( F_46 ( V_10 -> V_43 ) ) ;
if ( F_47 ( V_83 ) )
V_36 |= V_85 | V_86 ;
if ( ( ( V_10 -> V_70 >> 16 ) != V_10 -> V_87 ) ||
( ( V_10 -> V_69 >> 16 ) != V_10 -> V_88 ) )
V_36 |= V_85 ;
V_81 = F_48 ( V_10 -> V_81 ,
V_14 |
V_16 |
V_17 ) ;
if ( V_81 & V_16 )
V_36 |= V_89 ;
if ( V_81 & V_17 )
V_36 |= V_90 ;
if ( V_3 -> type == V_91 )
V_36 |= V_92 ;
if ( ! V_42 -> V_35 || ( V_36 & ~ V_42 -> V_35 -> V_36 ) )
V_58 = true ;
if ( ( V_59 && ! V_42 -> V_38 ) ||
( ! V_59 && V_42 -> V_38 ) )
V_58 = true ;
if ( V_1 -> V_93 ) {
const struct V_82 * V_83 =
F_45 ( F_46 ( V_10 -> V_43 ) ) ;
V_84 = F_49 ( V_1 -> V_93 , V_83 ,
V_10 -> V_70 >> 16 , false ) ;
if ( V_42 -> V_35 && ( V_42 -> V_35 -> V_84 != V_84 ) )
V_58 = true ;
}
if ( V_58 ) {
struct V_94 * V_95 = V_42 -> V_35 ;
struct V_94 * V_96 =
V_42 -> V_38 ;
V_42 -> V_35 = F_50 ( V_10 -> V_10 ,
V_3 , V_36 , V_84 ) ;
if ( F_51 ( V_42 -> V_35 ) ) {
F_35 ( L_13 , V_3 -> T_1 ) ;
return F_52 ( V_42 -> V_35 ) ;
}
if ( V_59 ) {
V_42 -> V_38 =
F_50 ( V_10 -> V_10 , V_3 ,
V_36 , V_84 ) ;
if ( F_51 ( V_42 -> V_38 ) ) {
F_35 ( L_14 ,
V_3 -> T_1 ) ;
return F_52 ( V_42 -> V_38 ) ;
}
} else {
V_42 -> V_38 = NULL ;
}
F_53 ( V_10 -> V_10 , V_95 ) ;
F_53 ( V_10 -> V_10 , V_96 ) ;
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
struct V_97 * V_98 ;
struct V_53 * V_54 ;
V_98 = V_10 -> V_98 ? V_10 -> V_98 : V_3 -> V_10 -> V_98 ;
if ( ! V_98 )
return 0 ;
V_54 = F_55 ( V_10 -> V_10 , V_98 ) ;
if ( F_30 ( ! V_54 ) )
return - V_31 ;
return F_39 ( V_54 , V_10 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_9 * V_52 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
F_35 ( L_15 , V_3 -> T_1 ) ;
if ( F_4 ( V_10 ) ) {
int V_29 ;
V_29 = F_57 ( V_3 ,
V_10 -> V_98 , V_10 -> V_43 ,
& V_10 -> V_72 , & V_10 -> V_99 ) ;
F_30 ( V_29 < 0 ) ;
}
}
static void F_58 ( struct V_1 * V_1 ,
enum V_100 V_101 ,
struct V_50 * V_43 )
{
F_59 ( V_1 , F_60 ( V_101 ) ,
F_61 ( V_43 -> V_102 [ 0 ] ) |
F_62 ( V_43 -> V_102 [ 1 ] ) ) ;
F_59 ( V_1 , F_63 ( V_101 ) ,
F_64 ( V_43 -> V_102 [ 2 ] ) |
F_65 ( V_43 -> V_102 [ 3 ] ) ) ;
F_59 ( V_1 , F_66 ( V_101 ) ,
F_67 ( V_43 , V_1 -> V_51 , 0 ) ) ;
F_59 ( V_1 , F_68 ( V_101 ) ,
F_67 ( V_43 , V_1 -> V_51 , 1 ) ) ;
F_59 ( V_1 , F_69 ( V_101 ) ,
F_67 ( V_43 , V_1 -> V_51 , 2 ) ) ;
F_59 ( V_1 , F_70 ( V_101 ) ,
F_67 ( V_43 , V_1 -> V_51 , 3 ) ) ;
}
static void F_71 ( struct V_1 * V_1 , enum V_100 V_101 )
{
T_8 V_103 = F_72 ( V_1 , F_73 ( V_101 ) ) &
~ V_104 ;
F_59 ( V_1 , F_73 ( V_101 ) , V_103 ) ;
}
static void F_74 ( struct V_1 * V_1 , enum V_100 V_101 ,
struct V_105 * V_106 )
{
T_8 V_107 , V_108 = 0 ;
T_8 * V_109 ;
if ( F_75 ( ! V_106 ) )
return;
if ( ( V_106 -> type == V_110 ) || ( V_111 == V_106 -> type ) )
V_108 |= F_76 ( V_112 ) ;
if ( ( V_106 -> type == V_113 ) || ( V_111 == V_106 -> type ) )
V_108 |= F_77 ( V_112 ) ;
V_108 |= V_104 ;
F_59 ( V_1 , F_73 ( V_101 ) , V_108 ) ;
V_109 = V_106 -> V_109 ;
F_59 ( V_1 , F_78 ( V_101 ) ,
F_79 ( V_109 [ 0 ] ) |
F_80 ( V_109 [ 1 ] ) ) ;
F_59 ( V_1 , F_81 ( V_101 ) ,
F_82 ( V_109 [ 2 ] ) |
F_83 ( V_109 [ 3 ] ) ) ;
F_59 ( V_1 , F_84 ( V_101 ) ,
F_85 ( V_109 [ 4 ] ) |
F_86 ( V_109 [ 5 ] ) ) ;
F_59 ( V_1 , F_87 ( V_101 ) ,
F_88 ( V_109 [ 6 ] ) |
F_89 ( V_109 [ 7 ] ) ) ;
F_59 ( V_1 , F_90 ( V_101 ) ,
F_91 ( V_109 [ 8 ] ) ) ;
for ( V_107 = 0 ; V_107 < F_92 ( V_106 -> V_114 ) ; V_107 ++ ) {
T_8 * V_115 = V_106 -> V_115 ;
T_8 * V_116 = V_106 -> V_116 ;
F_59 ( V_1 , F_93 ( V_101 , V_107 ) ,
F_94 ( V_115 [ 2 * V_107 + 1 ] ) |
F_95 ( V_115 [ 2 * V_107 ] ) ) ;
F_59 ( V_1 , F_96 ( V_101 , V_107 ) ,
F_97 ( V_116 [ 2 * V_107 + 1 ] ) |
F_98 ( V_116 [ 2 * V_107 ] ) ) ;
F_59 ( V_1 , F_99 ( V_101 , V_107 ) ,
F_100 ( V_106 -> V_114 [ V_107 ] ) ) ;
F_59 ( V_1 , F_101 ( V_101 , V_107 ) ,
F_102 ( V_106 -> V_117 [ V_107 ] ) ) ;
}
}
static int F_103 ( T_8 V_72 , T_8 V_99 , T_8 * V_118 )
{
T_8 V_119 ;
if ( V_72 == 0 || V_99 == 0 )
return - V_31 ;
if ( V_72 > ( V_99 * V_120 ) )
return - V_121 ;
V_119 = 1 << V_122 ;
* V_118 = F_104 ( V_119 , V_72 , V_99 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 ,
T_8 V_123 , T_8 V_72 , T_8 V_124 ,
T_8 V_125 [ V_126 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_127 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_128 ;
unsigned int V_129 ;
int V_29 ;
V_29 = F_103 ( V_72 , V_124 , & V_128 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_16 , V_72 , V_124 , V_29 ) ;
return V_29 ;
}
V_129 = F_106 ( V_123 ) ;
V_125 [ V_130 ] = V_128 ;
V_125 [ V_131 ] = V_128 ;
V_125 [ V_132 ] = V_128 / V_129 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_8 V_123 , T_8 V_72 , T_8 V_124 ,
T_8 V_133 [ V_126 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_127 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_134 ;
unsigned int V_135 ;
int V_29 ;
V_29 = F_103 ( V_72 , V_124 , & V_134 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_17 , V_72 , V_124 , V_29 ) ;
return V_29 ;
}
V_135 = F_108 ( V_123 ) ;
V_133 [ V_130 ] = V_134 ;
V_133 [ V_131 ] = V_134 ;
V_133 [ V_132 ] = V_134 / V_135 ;
return 0 ;
}
static T_8 F_109 ( const struct V_82 * V_83 ,
T_8 V_72 , T_8 V_99 , bool V_136 )
{
bool V_137 = V_83 -> V_138 ? true : ( V_72 != V_99 ) ;
T_8 V_139 , V_140 = V_83 -> V_48 . V_123 ;
T_8 V_141 , V_142 ;
bool V_143 = V_83 -> V_138 ;
if ( ! V_137 )
return 0 ;
if ( V_143 ) {
V_139 = V_136 ? F_106 ( V_140 ) :
F_108 ( V_140 ) ;
V_142 = ( ( V_72 / V_139 ) <= V_99 ) ?
V_144 : V_145 ;
}
V_141 = ( V_72 <= V_99 ) ? V_144 : V_145 ;
if ( V_136 )
return V_146 |
F_110 ( V_141 ) |
F_111 ( V_141 ) |
F_112 ( V_143 , F_113 ( V_142 ) ) ;
else
return V_147 |
F_114 ( V_141 ) |
F_115 ( V_141 ) |
F_112 ( V_143 , F_116 ( V_142 ) ) ;
}
static void F_117 ( const struct V_82 * V_83 ,
T_8 V_72 , T_8 V_99 , T_8 V_148 [ 2 ] ,
int V_149 [ V_126 ] , int V_150 [ V_126 ] ,
bool V_136 )
{
bool V_137 = V_83 -> V_138 ? true : ( V_72 != V_99 ) ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_126 ; V_107 ++ ) {
V_149 [ V_107 ] = 0 ;
V_150 [ V_107 ] = V_137 ? 1 : 0 ;
}
}
static void F_118 ( struct V_1 * V_1 , enum V_100 V_101 ,
const struct V_82 * V_83 ,
T_8 V_70 , int V_151 [ V_126 ] , int V_152 [ V_126 ] ,
T_8 V_69 , int V_153 [ V_126 ] , int V_154 [ V_126 ] )
{
T_8 V_140 = V_83 -> V_48 . V_123 ;
T_8 V_155 , V_156 , V_157 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_126 ; V_107 ++ ) {
T_8 V_158 = V_70 ;
T_8 V_159 = V_69 ;
if ( V_83 -> V_138 && V_107 == V_132 ) {
V_158 /= F_106 ( V_140 ) ;
V_159 /= F_108 ( V_140 ) ;
}
V_155 = ( V_151 [ V_107 ] >= 0 ) ?
F_119 ( V_151 [ V_107 ] ) :
F_120 ( V_151 [ V_107 ] ) ;
V_155 |= ( V_152 [ V_107 ] >= 0 ) ?
F_121 ( V_152 [ V_107 ] ) :
F_122 ( V_152 [ V_107 ] ) ;
V_156 = ( V_153 [ V_107 ] >= 0 ) ?
F_123 ( V_153 [ V_107 ] ) :
F_124 ( V_153 [ V_107 ] ) ;
V_156 |= ( V_154 [ V_107 ] >= 0 ) ?
F_125 ( V_154 [ V_107 ] ) :
F_126 ( V_154 [ V_107 ] ) ;
V_157 = F_127 ( V_158 +
V_151 [ V_107 ] + V_152 [ V_107 ] ) ;
V_157 |= F_128 ( V_159 +
V_153 [ V_107 ] + V_154 [ V_107 ] ) ;
F_59 ( V_1 , F_129 ( V_101 , V_107 ) , V_155 ) ;
F_59 ( V_1 , F_130 ( V_101 , V_107 ) , V_156 ) ;
F_59 ( V_1 , F_131 ( V_101 , V_107 ) , V_157 ) ;
F_35 ( L_18 , V_107 ,
F_132 ( V_155 , F_119 ) ,
F_132 ( V_155 , F_121 ) ,
F_132 ( V_155 , F_120 ) ,
F_132 ( V_155 , F_122 ) ,
F_132 ( V_157 , F_127 ) ) ;
F_35 ( L_19 , V_107 ,
F_132 ( V_156 , F_123 ) ,
F_132 ( V_156 , F_125 ) ,
F_132 ( V_156 , F_124 ) ,
F_132 ( V_156 , F_126 ) ,
F_132 ( V_157 , F_128 ) ) ;
}
}
static void F_133 ( struct V_1 * V_1 ,
struct V_94 * V_35 ,
struct V_50 * V_43 ,
struct V_148 * V_160 ,
struct V_161 * V_162 ,
T_9 V_163 , T_9 V_164 , T_9 V_165 ,
bool V_166 , bool V_167 ,
int V_168 , int V_169 ,
unsigned int V_87 , unsigned int V_88 ,
T_9 V_170 , T_9 V_171 ,
T_9 V_172 , T_9 V_173 ,
T_9 V_70 , T_9 V_69 )
{
enum V_100 V_101 = V_35 -> V_101 ;
bool V_174 = V_35 -> V_36 & V_175 ;
const struct V_82 * V_83 =
F_45 ( F_46 ( V_43 ) ) ;
F_59 ( V_1 , F_134 ( V_101 ) ,
F_135 ( V_170 ) |
F_136 ( V_171 ) ) ;
F_59 ( V_1 , F_137 ( V_101 ) ,
F_138 ( V_70 ) |
F_139 ( V_69 ) ) ;
F_59 ( V_1 , F_140 ( V_101 ) ,
F_141 ( V_172 ) |
F_142 ( V_173 ) ) ;
F_59 ( V_1 , F_143 ( V_101 ) ,
F_144 ( V_87 ) |
F_145 ( V_88 ) ) ;
F_59 ( V_1 , F_146 ( V_101 ) ,
F_147 ( V_168 ) |
F_148 ( V_169 ) ) ;
F_59 ( V_1 , F_149 ( V_101 ) ,
F_150 ( V_83 -> V_176 ) |
F_151 ( V_83 -> V_177 ) |
F_152 ( V_83 -> V_178 ) |
F_153 ( V_83 -> V_179 ) |
F_112 ( V_83 -> V_180 , V_181 ) |
F_154 ( V_83 -> V_182 - 1 ) |
F_155 ( V_83 -> V_183 - 1 ) |
F_112 ( V_83 -> V_184 , V_185 ) |
F_156 ( V_83 -> V_186 ) |
F_157 ( V_83 -> V_187 ) ) ;
F_59 ( V_1 , F_158 ( V_101 ) ,
F_159 ( V_83 -> V_188 [ 0 ] ) |
F_160 ( V_83 -> V_188 [ 1 ] ) |
F_161 ( V_83 -> V_188 [ 2 ] ) |
F_162 ( V_83 -> V_188 [ 3 ] ) ) ;
F_59 ( V_1 , F_163 ( V_101 ) ,
( V_166 ? V_189 : 0 ) |
( V_167 ? V_190 : 0 ) |
F_112 ( V_174 , V_191 ) |
F_164 ( V_192 ) ) ;
F_59 ( V_1 , F_165 ( V_101 ) , 0 ) ;
if ( V_35 -> V_36 & V_175 )
F_118 ( V_1 , V_101 , V_83 ,
V_70 , V_162 -> V_193 , V_162 -> V_194 ,
V_69 , V_162 -> V_195 , V_162 -> V_196 ) ;
if ( V_35 -> V_36 & V_85 ) {
F_59 ( V_1 , F_166 ( V_101 ) ,
V_160 -> V_197 [ V_130 ] ) ;
F_59 ( V_1 , F_167 ( V_101 ) ,
V_160 -> V_198 [ V_130 ] ) ;
F_59 ( V_1 , F_168 ( V_101 ) ,
V_160 -> V_197 [ V_132 ] ) ;
F_59 ( V_1 , F_169 ( V_101 ) ,
V_160 -> V_198 [ V_132 ] ) ;
F_59 ( V_1 , F_170 ( V_101 ) ,
F_171 ( V_165 ) |
F_172 ( V_164 ) ) ;
F_59 ( V_1 , F_173 ( V_101 ) ,
V_163 ) ;
}
if ( V_35 -> V_36 & V_86 ) {
if ( F_47 ( V_83 ) )
F_74 ( V_1 , V_101 ,
F_174 ( V_110 ) ) ;
else
F_71 ( V_1 , V_101 ) ;
}
F_58 ( V_1 , V_101 , V_43 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_97 * V_98 , struct V_50 * V_43 ,
struct V_63 * V_72 , struct V_63 * V_124 )
{
struct V_12 * V_12 = F_6 ( V_3 ) ;
struct V_9 * V_28 = V_3 -> V_10 ;
struct V_94 * V_35 = F_17 ( V_28 ) -> V_35 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_100 V_101 = V_35 -> V_101 ;
struct V_94 * V_199 ;
const struct V_82 * V_83 ;
T_8 V_200 , V_56 = 0 ;
struct V_148 V_160 = { 0 } ;
struct V_161 V_162 = { 0 } ;
T_8 V_164 = 0 , V_165 = 0 ;
T_8 V_201 ;
unsigned int V_81 ;
bool V_167 , V_166 ;
int V_168 , V_169 ;
unsigned int V_87 , V_88 ;
T_8 V_172 , V_173 ;
T_8 V_70 , V_69 ;
T_8 V_170 , V_171 ;
T_8 V_202 ;
int V_203 ;
unsigned long V_204 ;
int V_29 ;
V_200 = V_43 -> V_83 -> V_205 ;
if ( F_30 ( V_200 > F_175 ( V_101 ) ) )
return - V_31 ;
V_83 = F_45 ( F_46 ( V_43 ) ) ;
V_201 = V_83 -> V_48 . V_123 ;
V_172 = V_72 -> V_75 ;
V_173 = V_72 -> y1 ;
V_70 = F_176 ( V_72 ) ;
V_69 = F_177 ( V_72 ) ;
V_168 = V_124 -> V_75 ;
V_169 = V_124 -> y1 ;
V_87 = F_176 ( V_124 ) ;
V_88 = F_177 ( V_124 ) ;
V_172 = V_172 >> 16 ;
V_173 = V_173 >> 16 ;
V_70 = V_70 >> 16 ;
V_69 = V_69 >> 16 ;
V_170 = T_5 ( V_43 -> V_206 , V_70 ) ;
V_171 = T_5 ( V_43 -> V_207 , V_69 ) ;
F_35 ( L_20 , V_3 -> T_1 ,
V_43 -> V_48 . V_51 , V_172 , V_173 , V_70 , V_69 ,
V_98 -> V_48 . V_51 , V_168 , V_169 , V_87 , V_88 ) ;
V_199 = F_17 ( V_28 ) -> V_38 ;
if ( V_199 ) {
V_87 /= 2 ;
V_70 /= 2 ;
V_170 /= 2 ;
V_203 = V_168 + V_87 ;
V_202 = V_172 + V_70 ;
}
V_29 = F_105 ( V_3 , V_201 , V_70 , V_87 , V_160 . V_197 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_107 ( V_3 , V_201 , V_69 , V_88 , V_160 . V_198 ) ;
if ( V_29 )
return V_29 ;
if ( V_35 -> V_36 & V_175 ) {
F_117 ( V_83 , V_70 , V_87 , V_160 . V_197 ,
V_162 . V_193 , V_162 . V_194 , true ) ;
F_117 ( V_83 , V_69 , V_88 , V_160 . V_198 ,
V_162 . V_195 , V_162 . V_196 , false ) ;
}
V_56 |= F_109 ( V_83 , V_70 , V_87 , true ) ;
V_56 |= F_109 ( V_83 , V_69 , V_88 , false ) ;
F_35 ( L_21 , V_56 ) ;
V_81 = F_48 ( V_28 -> V_81 ,
V_14 |
V_16 |
V_17 ) ;
V_166 = ! ! ( V_81 & V_16 ) ;
V_167 = ! ! ( V_81 & V_17 ) ;
F_178 ( & V_12 -> V_208 , V_204 ) ;
F_133 ( V_1 , V_35 , V_43 , & V_160 , & V_162 ,
V_56 , V_164 , V_165 , V_166 , V_167 ,
V_168 , V_169 , V_87 , V_88 ,
V_170 , V_171 ,
V_172 , V_173 , V_70 , V_69 ) ;
if ( V_199 )
F_133 ( V_1 , V_199 , V_43 , & V_160 , & V_162 ,
V_56 , V_164 , V_165 , V_166 , V_167 ,
V_203 , V_169 , V_87 , V_88 ,
V_170 , V_171 ,
V_202 , V_173 , V_70 , V_69 ) ;
F_179 ( & V_12 -> V_208 , V_204 ) ;
V_3 -> V_43 = V_43 ;
return V_29 ;
}
static int F_180 ( struct V_2 * V_3 ,
struct V_97 * V_98 , struct V_50 * V_43 ,
int V_168 , int V_169 ,
unsigned int V_87 , unsigned int V_88 ,
T_8 V_172 , T_8 V_173 ,
T_8 V_70 , T_8 V_69 ,
struct V_209 * V_210 )
{
struct V_9 * V_211 , * V_212 ;
struct V_27 * V_213 ;
struct V_53 * V_54 = V_98 -> V_10 ;
int V_29 ;
if ( ! V_54 -> V_214 || F_181 ( V_54 ) )
goto V_215;
V_211 = V_3 -> V_10 ;
V_213 = F_17 ( V_211 ) ;
if ( ! V_213 -> V_35 )
goto V_215;
if ( V_211 -> V_98 != V_98 ||
V_211 -> V_70 != V_70 ||
V_211 -> V_69 != V_69 ||
V_211 -> V_87 != V_87 ||
V_211 -> V_88 != V_88 ||
! V_211 -> V_43 ||
V_211 -> V_43 != V_43 )
goto V_215;
V_212 = F_29 ( V_3 ) ;
if ( ! V_212 )
return - V_216 ;
V_212 -> V_172 = V_172 ;
V_212 -> V_173 = V_173 ;
V_212 -> V_70 = V_70 ;
V_212 -> V_69 = V_69 ;
V_212 -> V_168 = V_168 ;
V_212 -> V_169 = V_169 ;
V_212 -> V_87 = V_87 ;
V_212 -> V_88 = V_88 ;
V_29 = F_39 ( V_54 , V_212 ) ;
if ( V_29 )
goto V_217;
if ( V_212 -> V_11 ) {
struct V_218 * V_219 ;
struct V_220 * V_221 = F_182 ( V_98 ) ;
V_29 = F_57 ( V_3 , V_98 , V_43 ,
& V_212 -> V_72 ,
& V_212 -> V_99 ) ;
F_30 ( V_29 < 0 ) ;
V_219 = F_183 ( V_98 ) ;
F_184 ( V_219 , V_221 , F_185 ( V_3 ) ) ;
}
* F_17 ( V_211 ) =
* F_17 ( V_212 ) ;
F_33 ( V_3 , V_212 ) ;
return 0 ;
V_217:
F_33 ( V_3 , V_212 ) ;
V_215:
return F_186 ( V_3 , V_98 , V_43 ,
V_168 , V_169 , V_87 , V_88 ,
V_172 , V_173 , V_70 , V_69 , V_210 ) ;
}
enum V_100 F_187 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_28 -> V_35 ) )
return V_222 ;
return V_28 -> V_35 -> V_101 ;
}
enum V_100 F_188 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( ! V_28 -> V_38 )
return V_222 ;
return V_28 -> V_38 -> V_101 ;
}
T_8 F_185 ( struct V_2 * V_3 )
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
struct V_2 * F_189 ( struct V_13 * V_6 ,
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
V_12 -> V_227 = F_190 ( V_12 -> V_228 ,
F_92 ( V_12 -> V_228 ) , false ) ;
F_191 ( & V_12 -> V_208 ) ;
if ( type == V_91 )
V_29 = F_192 ( V_6 , V_3 , 0xff ,
& V_229 ,
V_12 -> V_228 , V_12 -> V_227 ,
type , NULL ) ;
else
V_29 = F_192 ( V_6 , V_3 , 0xff ,
& V_230 ,
V_12 -> V_228 , V_12 -> V_227 ,
type , NULL ) ;
if ( V_29 )
goto V_226;
F_193 ( V_3 , & V_231 ) ;
F_12 ( V_3 , & V_3 -> V_48 ) ;
return V_3 ;
V_226:
if ( V_3 )
F_5 ( V_3 ) ;
return F_194 ( V_29 ) ;
}
