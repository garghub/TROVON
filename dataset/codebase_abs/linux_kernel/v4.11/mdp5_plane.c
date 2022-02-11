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
F_23 ( V_34 , L_2 , V_28 -> V_35 ?
V_28 -> V_35 -> T_1 : L_3 ) ;
F_23 ( V_34 , L_4 , V_28 -> V_36 ) ;
F_23 ( V_34 , L_5 , V_28 -> V_23 ) ;
F_23 ( V_34 , L_6 , V_28 -> V_37 ) ;
F_23 ( V_34 , L_7 , F_24 ( V_28 -> V_38 ) ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_27 * V_39 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_40 )
F_26 ( V_3 -> V_10 -> V_40 ) ;
F_9 ( F_17 ( V_3 -> V_10 ) ) ;
V_39 = F_27 ( sizeof( * V_39 ) , V_41 ) ;
V_39 -> V_37 = 255 ;
V_39 -> V_36 = 0 ;
if ( V_3 -> type == V_42 )
V_39 -> V_23 = V_43 ;
else
V_39 -> V_23 = V_44 + F_28 ( V_3 ) ;
V_39 -> V_45 . V_3 = V_3 ;
V_3 -> V_10 = & V_39 -> V_45 ;
}
static struct V_9 *
F_29 ( struct V_2 * V_3 )
{
struct V_27 * V_39 ;
if ( F_30 ( ! V_3 -> V_10 ) )
return NULL ;
V_39 = F_31 ( F_17 ( V_3 -> V_10 ) ,
sizeof( * V_39 ) , V_41 ) ;
if ( V_39 && V_39 -> V_45 . V_40 )
F_32 ( V_39 -> V_45 . V_40 ) ;
return & V_39 -> V_45 ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_27 * V_28 = F_17 ( V_10 ) ;
if ( V_10 -> V_40 )
F_26 ( V_10 -> V_40 ) ;
F_9 ( V_28 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_9 * V_46 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_47 * V_40 = V_46 -> V_40 ;
if ( ! V_46 -> V_40 )
return 0 ;
F_35 ( L_8 , V_3 -> T_1 , V_40 -> V_45 . V_48 ) ;
return F_36 ( V_40 , V_1 -> V_48 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_9 * V_49 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_47 * V_40 = V_49 -> V_40 ;
if ( ! V_40 )
return;
F_35 ( L_9 , V_3 -> T_1 , V_40 -> V_45 . V_48 ) ;
F_38 ( V_40 , V_1 -> V_48 ) ;
}
static int F_39 ( struct V_50 * V_51 ,
struct V_9 * V_10 )
{
struct V_27 * V_39 = F_17 ( V_10 ) ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_9 * V_49 = V_3 -> V_10 ;
struct V_52 * V_53 = F_40 ( F_1 ( V_3 ) -> V_54 ) ;
bool V_55 = false ;
T_8 V_56 , V_57 ;
T_8 V_58 = 0 ;
struct V_59 V_60 ;
int V_61 , V_62 ;
int V_29 ;
F_35 ( L_10 , V_3 -> T_1 ,
F_4 ( V_49 ) , F_4 ( V_10 ) ) ;
V_56 = V_53 -> V_63 -> V_64 . V_56 << 16 ;
V_57 = V_53 -> V_63 -> V_64 . V_57 << 16 ;
if ( ( V_10 -> V_65 > V_56 ) || ( V_10 -> V_66 > V_57 ) ) {
struct V_59 V_67 = F_41 ( V_10 ) ;
F_35 ( L_11 V_68 ,
F_42 ( & V_67 ) ) ;
return - V_69 ;
}
V_60 . V_70 = 0 ;
V_60 . y1 = 0 ;
V_60 . V_71 = V_51 -> V_72 . V_73 ;
V_60 . V_74 = V_51 -> V_72 . V_75 ;
V_61 = F_43 ( 1 , 8 ) ;
V_62 = F_43 ( 8 , 1 ) ;
V_29 = F_44 ( V_10 , & V_60 , V_61 ,
V_62 , true , true ) ;
if ( V_29 )
return V_29 ;
if ( F_4 ( V_10 ) ) {
unsigned int V_76 ;
const struct V_77 * V_78 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_8 V_79 = 0 ;
V_78 = F_45 ( F_46 ( V_10 -> V_40 ) ) ;
if ( F_47 ( V_78 ) )
V_58 |= V_80 | V_81 ;
if ( ( ( V_10 -> V_65 >> 16 ) != V_10 -> V_82 ) ||
( ( V_10 -> V_66 >> 16 ) != V_10 -> V_83 ) )
V_58 |= V_80 ;
V_76 = F_48 ( V_10 -> V_76 ,
V_14 |
V_16 |
V_17 ) ;
if ( V_76 & V_16 )
V_58 |= V_84 ;
if ( V_76 & V_17 )
V_58 |= V_85 ;
if ( V_3 -> type == V_86 )
V_58 |= V_87 ;
if ( ! V_39 -> V_35 || ( V_58 & ~ V_39 -> V_35 -> V_58 ) )
V_55 = true ;
if ( V_1 -> V_88 ) {
const struct V_77 * V_78 =
F_45 ( F_46 ( V_10 -> V_40 ) ) ;
V_79 = F_49 ( V_1 -> V_88 , V_78 ,
V_10 -> V_65 >> 16 , false ) ;
if ( V_39 -> V_35 && ( V_39 -> V_35 -> V_79 != V_79 ) )
V_55 = true ;
}
if ( V_55 ) {
struct V_89 * V_90 = V_39 -> V_35 ;
V_39 -> V_35 = F_50 ( V_10 -> V_10 ,
V_3 , V_58 , V_79 ) ;
if ( F_51 ( V_39 -> V_35 ) ) {
F_35 ( L_12 , V_3 -> T_1 ) ;
return F_52 ( V_39 -> V_35 ) ;
}
F_53 ( V_10 -> V_10 , V_90 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_91 * V_92 ;
struct V_50 * V_51 ;
V_92 = V_10 -> V_92 ? V_10 -> V_92 : V_3 -> V_10 -> V_92 ;
if ( ! V_92 )
return 0 ;
V_51 = F_55 ( V_10 -> V_10 , V_92 ) ;
if ( F_30 ( ! V_51 ) )
return - V_31 ;
return F_39 ( V_51 , V_10 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_9 * V_49 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
F_35 ( L_13 , V_3 -> T_1 ) ;
if ( F_4 ( V_10 ) ) {
int V_29 ;
V_29 = F_57 ( V_3 ,
V_10 -> V_92 , V_10 -> V_40 ,
& V_10 -> V_67 , & V_10 -> V_93 ) ;
F_30 ( V_29 < 0 ) ;
}
}
static void F_58 ( struct V_2 * V_3 ,
struct V_47 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_89 * V_35 = F_17 ( V_3 -> V_10 ) -> V_35 ;
enum V_94 V_95 = V_35 -> V_95 ;
F_59 ( V_1 , F_60 ( V_95 ) ,
F_61 ( V_40 -> V_96 [ 0 ] ) |
F_62 ( V_40 -> V_96 [ 1 ] ) ) ;
F_59 ( V_1 , F_63 ( V_95 ) ,
F_64 ( V_40 -> V_96 [ 2 ] ) |
F_65 ( V_40 -> V_96 [ 3 ] ) ) ;
F_59 ( V_1 , F_66 ( V_95 ) ,
F_67 ( V_40 , V_1 -> V_48 , 0 ) ) ;
F_59 ( V_1 , F_68 ( V_95 ) ,
F_67 ( V_40 , V_1 -> V_48 , 1 ) ) ;
F_59 ( V_1 , F_69 ( V_95 ) ,
F_67 ( V_40 , V_1 -> V_48 , 2 ) ) ;
F_59 ( V_1 , F_70 ( V_95 ) ,
F_67 ( V_40 , V_1 -> V_48 , 3 ) ) ;
V_3 -> V_40 = V_40 ;
}
static void F_71 ( struct V_1 * V_1 , enum V_94 V_95 )
{
T_8 V_97 = F_72 ( V_1 , F_73 ( V_95 ) ) &
~ V_98 ;
F_59 ( V_1 , F_73 ( V_95 ) , V_97 ) ;
}
static void F_74 ( struct V_1 * V_1 , enum V_94 V_95 ,
struct V_99 * V_100 )
{
T_8 V_101 , V_102 = 0 ;
T_8 * V_103 ;
if ( F_75 ( ! V_100 ) )
return;
if ( ( V_100 -> type == V_104 ) || ( V_105 == V_100 -> type ) )
V_102 |= F_76 ( V_106 ) ;
if ( ( V_100 -> type == V_107 ) || ( V_105 == V_100 -> type ) )
V_102 |= F_77 ( V_106 ) ;
V_102 |= V_98 ;
F_59 ( V_1 , F_73 ( V_95 ) , V_102 ) ;
V_103 = V_100 -> V_103 ;
F_59 ( V_1 , F_78 ( V_95 ) ,
F_79 ( V_103 [ 0 ] ) |
F_80 ( V_103 [ 1 ] ) ) ;
F_59 ( V_1 , F_81 ( V_95 ) ,
F_82 ( V_103 [ 2 ] ) |
F_83 ( V_103 [ 3 ] ) ) ;
F_59 ( V_1 , F_84 ( V_95 ) ,
F_85 ( V_103 [ 4 ] ) |
F_86 ( V_103 [ 5 ] ) ) ;
F_59 ( V_1 , F_87 ( V_95 ) ,
F_88 ( V_103 [ 6 ] ) |
F_89 ( V_103 [ 7 ] ) ) ;
F_59 ( V_1 , F_90 ( V_95 ) ,
F_91 ( V_103 [ 8 ] ) ) ;
for ( V_101 = 0 ; V_101 < F_92 ( V_100 -> V_108 ) ; V_101 ++ ) {
T_8 * V_109 = V_100 -> V_109 ;
T_8 * V_110 = V_100 -> V_110 ;
F_59 ( V_1 , F_93 ( V_95 , V_101 ) ,
F_94 ( V_109 [ 2 * V_101 + 1 ] ) |
F_95 ( V_109 [ 2 * V_101 ] ) ) ;
F_59 ( V_1 , F_96 ( V_95 , V_101 ) ,
F_97 ( V_110 [ 2 * V_101 + 1 ] ) |
F_98 ( V_110 [ 2 * V_101 ] ) ) ;
F_59 ( V_1 , F_99 ( V_95 , V_101 ) ,
F_100 ( V_100 -> V_108 [ V_101 ] ) ) ;
F_59 ( V_1 , F_101 ( V_95 , V_101 ) ,
F_102 ( V_100 -> V_111 [ V_101 ] ) ) ;
}
}
static int F_103 ( T_8 V_67 , T_8 V_93 , T_8 * V_112 )
{
T_8 V_113 ;
if ( V_67 == 0 || V_93 == 0 )
return - V_31 ;
if ( V_67 > ( V_93 * V_114 ) )
return - V_115 ;
V_113 = 1 << V_116 ;
* V_112 = F_104 ( V_113 , V_67 , V_93 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 ,
T_8 V_117 , T_8 V_67 , T_8 V_118 ,
T_8 V_119 [ V_120 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_121 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_122 ;
unsigned int V_123 ;
int V_29 ;
V_29 = F_103 ( V_67 , V_118 , & V_122 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_14 , V_67 , V_118 , V_29 ) ;
return V_29 ;
}
V_123 = F_106 ( V_117 ) ;
V_119 [ V_124 ] = V_122 ;
V_119 [ V_125 ] = V_122 ;
V_119 [ V_126 ] = V_122 / V_123 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_8 V_117 , T_8 V_67 , T_8 V_118 ,
T_8 V_127 [ V_120 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_121 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_128 ;
unsigned int V_129 ;
int V_29 ;
V_29 = F_103 ( V_67 , V_118 , & V_128 ) ;
if ( V_29 ) {
F_19 ( V_6 , L_15 , V_67 , V_118 , V_29 ) ;
return V_29 ;
}
V_129 = F_108 ( V_117 ) ;
V_127 [ V_124 ] = V_128 ;
V_127 [ V_125 ] = V_128 ;
V_127 [ V_126 ] = V_128 / V_129 ;
return 0 ;
}
static T_8 F_109 ( const struct V_77 * V_78 ,
T_8 V_67 , T_8 V_93 , bool V_130 )
{
bool V_131 = V_78 -> V_132 ? true : ( V_67 != V_93 ) ;
T_8 V_133 , V_134 = V_78 -> V_45 . V_117 ;
T_8 V_135 , V_136 ;
bool V_137 = V_78 -> V_132 ;
if ( ! V_131 )
return 0 ;
if ( V_137 ) {
V_133 = V_130 ? F_106 ( V_134 ) :
F_108 ( V_134 ) ;
V_136 = ( ( V_67 / V_133 ) <= V_93 ) ?
V_138 : V_139 ;
}
V_135 = ( V_67 <= V_93 ) ? V_138 : V_139 ;
if ( V_130 )
return V_140 |
F_110 ( V_135 ) |
F_111 ( V_135 ) |
F_112 ( V_137 , F_113 ( V_136 ) ) ;
else
return V_141 |
F_114 ( V_135 ) |
F_115 ( V_135 ) |
F_112 ( V_137 , F_116 ( V_136 ) ) ;
}
static void F_117 ( const struct V_77 * V_78 ,
T_8 V_67 , T_8 V_93 , T_8 V_142 [ 2 ] ,
int V_143 [ V_120 ] , int V_144 [ V_120 ] ,
bool V_130 )
{
bool V_131 = V_78 -> V_132 ? true : ( V_67 != V_93 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_120 ; V_101 ++ ) {
V_143 [ V_101 ] = 0 ;
V_144 [ V_101 ] = V_131 ? 1 : 0 ;
}
}
static void F_118 ( struct V_1 * V_1 , enum V_94 V_95 ,
const struct V_77 * V_78 ,
T_8 V_65 , int V_145 [ V_120 ] , int V_146 [ V_120 ] ,
T_8 V_66 , int V_147 [ V_120 ] , int V_148 [ V_120 ] )
{
T_8 V_134 = V_78 -> V_45 . V_117 ;
T_8 V_149 , V_150 , V_151 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_120 ; V_101 ++ ) {
T_8 V_152 = V_65 ;
T_8 V_153 = V_66 ;
if ( V_78 -> V_132 && V_101 == V_126 ) {
V_152 /= F_106 ( V_134 ) ;
V_153 /= F_108 ( V_134 ) ;
}
V_149 = ( V_145 [ V_101 ] >= 0 ) ?
F_119 ( V_145 [ V_101 ] ) :
F_120 ( V_145 [ V_101 ] ) ;
V_149 |= ( V_146 [ V_101 ] >= 0 ) ?
F_121 ( V_146 [ V_101 ] ) :
F_122 ( V_146 [ V_101 ] ) ;
V_150 = ( V_147 [ V_101 ] >= 0 ) ?
F_123 ( V_147 [ V_101 ] ) :
F_124 ( V_147 [ V_101 ] ) ;
V_150 |= ( V_148 [ V_101 ] >= 0 ) ?
F_125 ( V_148 [ V_101 ] ) :
F_126 ( V_148 [ V_101 ] ) ;
V_151 = F_127 ( V_152 +
V_145 [ V_101 ] + V_146 [ V_101 ] ) ;
V_151 |= F_128 ( V_153 +
V_147 [ V_101 ] + V_148 [ V_101 ] ) ;
F_59 ( V_1 , F_129 ( V_95 , V_101 ) , V_149 ) ;
F_59 ( V_1 , F_130 ( V_95 , V_101 ) , V_150 ) ;
F_59 ( V_1 , F_131 ( V_95 , V_101 ) , V_151 ) ;
F_35 ( L_16 , V_101 ,
F_132 ( V_149 , F_119 ) ,
F_132 ( V_149 , F_121 ) ,
F_132 ( V_149 , F_120 ) ,
F_132 ( V_149 , F_122 ) ,
F_132 ( V_151 , F_127 ) ) ;
F_35 ( L_17 , V_101 ,
F_132 ( V_150 , F_123 ) ,
F_132 ( V_150 , F_125 ) ,
F_132 ( V_150 , F_124 ) ,
F_132 ( V_150 , F_126 ) ,
F_132 ( V_151 , F_128 ) ) ;
}
}
static int F_57 ( struct V_2 * V_3 ,
struct V_91 * V_92 , struct V_47 * V_40 ,
struct V_59 * V_67 , struct V_59 * V_118 )
{
struct V_9 * V_28 = V_3 -> V_10 ;
struct V_89 * V_35 = F_17 ( V_28 ) -> V_35 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_94 V_95 = V_35 -> V_95 ;
const struct V_77 * V_78 ;
T_8 V_154 , V_53 = 0 ;
T_8 V_122 [ V_120 ] = { 0 ,} , V_128 [ V_120 ] = { 0 ,} ;
bool V_155 = V_35 -> V_58 & V_156 ;
int V_145 [ V_120 ] , V_146 [ V_120 ] ;
int V_147 [ V_120 ] , V_148 [ V_120 ] ;
T_8 V_157 = 0 , V_158 = 0 ;
T_8 V_159 ;
unsigned int V_76 ;
bool V_160 , V_161 ;
int V_162 , V_163 ;
unsigned int V_82 , V_83 ;
T_8 V_164 , V_165 ;
T_8 V_65 , V_66 ;
unsigned long V_166 ;
int V_29 ;
V_154 = V_40 -> V_78 -> V_167 ;
if ( F_30 ( V_154 > F_133 ( V_95 ) ) )
return - V_31 ;
V_78 = F_45 ( F_46 ( V_40 ) ) ;
V_159 = V_78 -> V_45 . V_117 ;
V_164 = V_67 -> V_70 ;
V_165 = V_67 -> y1 ;
V_65 = F_134 ( V_67 ) ;
V_66 = F_135 ( V_67 ) ;
V_162 = V_118 -> V_70 ;
V_163 = V_118 -> y1 ;
V_82 = F_134 ( V_118 ) ;
V_83 = F_135 ( V_118 ) ;
V_164 = V_164 >> 16 ;
V_165 = V_165 >> 16 ;
V_65 = V_65 >> 16 ;
V_66 = V_66 >> 16 ;
F_35 ( L_18 , V_3 -> T_1 ,
V_40 -> V_45 . V_48 , V_164 , V_165 , V_65 , V_66 ,
V_92 -> V_45 . V_48 , V_162 , V_163 , V_82 , V_83 ) ;
V_29 = F_105 ( V_3 , V_159 , V_65 , V_82 , V_122 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_107 ( V_3 , V_159 , V_66 , V_83 , V_128 ) ;
if ( V_29 )
return V_29 ;
if ( V_35 -> V_58 & V_156 ) {
F_117 ( V_78 , V_65 , V_82 , V_122 ,
V_145 , V_146 , true ) ;
F_117 ( V_78 , V_66 , V_83 , V_128 ,
V_147 , V_148 , false ) ;
}
V_53 |= F_109 ( V_78 , V_65 , V_82 , true ) ;
V_53 |= F_109 ( V_78 , V_66 , V_83 , false ) ;
F_35 ( L_19 , V_53 ) ;
V_76 = F_48 ( V_28 -> V_76 ,
V_14 |
V_16 |
V_17 ) ;
V_161 = ! ! ( V_76 & V_16 ) ;
V_160 = ! ! ( V_76 & V_17 ) ;
F_136 ( & V_35 -> V_168 , V_166 ) ;
F_59 ( V_1 , F_137 ( V_95 ) ,
F_138 ( T_5 ( V_40 -> V_169 , V_65 ) ) |
F_139 ( T_5 ( V_40 -> V_170 , V_66 ) ) ) ;
F_59 ( V_1 , F_140 ( V_95 ) ,
F_141 ( V_65 ) |
F_142 ( V_66 ) ) ;
F_59 ( V_1 , F_143 ( V_95 ) ,
F_144 ( V_164 ) |
F_145 ( V_165 ) ) ;
F_59 ( V_1 , F_146 ( V_95 ) ,
F_147 ( V_82 ) |
F_148 ( V_83 ) ) ;
F_59 ( V_1 , F_149 ( V_95 ) ,
F_150 ( V_162 ) |
F_151 ( V_163 ) ) ;
F_59 ( V_1 , F_152 ( V_95 ) ,
F_153 ( V_78 -> V_171 ) |
F_154 ( V_78 -> V_172 ) |
F_155 ( V_78 -> V_173 ) |
F_156 ( V_78 -> V_174 ) |
F_112 ( V_78 -> V_175 , V_176 ) |
F_157 ( V_78 -> V_177 - 1 ) |
F_158 ( V_78 -> V_178 - 1 ) |
F_112 ( V_78 -> V_179 , V_180 ) |
F_159 ( V_78 -> V_181 ) |
F_160 ( V_78 -> V_182 ) ) ;
F_59 ( V_1 , F_161 ( V_95 ) ,
F_162 ( V_78 -> V_183 [ 0 ] ) |
F_163 ( V_78 -> V_183 [ 1 ] ) |
F_164 ( V_78 -> V_183 [ 2 ] ) |
F_165 ( V_78 -> V_183 [ 3 ] ) ) ;
F_59 ( V_1 , F_166 ( V_95 ) ,
( V_161 ? V_184 : 0 ) |
( V_160 ? V_185 : 0 ) |
F_112 ( V_155 , V_186 ) |
F_167 ( V_187 ) ) ;
F_59 ( V_1 , F_168 ( V_95 ) , 0 ) ;
if ( V_35 -> V_58 & V_156 )
F_118 ( V_1 , V_95 , V_78 ,
V_65 , V_145 , V_146 ,
V_66 , V_147 , V_148 ) ;
if ( V_35 -> V_58 & V_80 ) {
F_59 ( V_1 , F_169 ( V_95 ) ,
V_122 [ V_124 ] ) ;
F_59 ( V_1 , F_170 ( V_95 ) ,
V_128 [ V_124 ] ) ;
F_59 ( V_1 , F_171 ( V_95 ) ,
V_122 [ V_126 ] ) ;
F_59 ( V_1 , F_172 ( V_95 ) ,
V_128 [ V_126 ] ) ;
F_59 ( V_1 , F_173 ( V_95 ) ,
F_174 ( V_158 ) |
F_175 ( V_157 ) ) ;
F_59 ( V_1 , F_176 ( V_95 ) , V_53 ) ;
}
if ( V_35 -> V_58 & V_81 ) {
if ( F_47 ( V_78 ) )
F_74 ( V_1 , V_95 ,
F_177 ( V_104 ) ) ;
else
F_71 ( V_1 , V_95 ) ;
}
F_58 ( V_3 , V_40 ) ;
F_178 ( & V_35 -> V_168 , V_166 ) ;
return V_29 ;
}
static int F_179 ( struct V_2 * V_3 ,
struct V_91 * V_92 , struct V_47 * V_40 ,
int V_162 , int V_163 ,
unsigned int V_82 , unsigned int V_83 ,
T_8 V_164 , T_8 V_165 ,
T_8 V_65 , T_8 V_66 )
{
struct V_9 * V_188 , * V_189 ;
struct V_27 * V_190 ;
struct V_50 * V_51 = V_92 -> V_10 ;
int V_29 ;
if ( ! V_51 -> V_191 || F_180 ( V_51 ) )
goto V_192;
V_188 = V_3 -> V_10 ;
V_190 = F_17 ( V_188 ) ;
if ( ! V_190 -> V_35 )
goto V_192;
if ( V_188 -> V_92 != V_92 ||
V_188 -> V_65 != V_65 ||
V_188 -> V_66 != V_66 ||
V_188 -> V_82 != V_82 ||
V_188 -> V_83 != V_83 ||
! V_188 -> V_40 ||
V_188 -> V_40 != V_40 )
goto V_192;
V_189 = F_29 ( V_3 ) ;
if ( ! V_189 )
return - V_193 ;
V_189 -> V_164 = V_164 ;
V_189 -> V_165 = V_165 ;
V_189 -> V_65 = V_65 ;
V_189 -> V_66 = V_66 ;
V_189 -> V_162 = V_162 ;
V_189 -> V_163 = V_163 ;
V_189 -> V_82 = V_82 ;
V_189 -> V_83 = V_83 ;
V_29 = F_39 ( V_51 , V_189 ) ;
if ( V_29 )
goto V_194;
if ( V_189 -> V_11 ) {
struct V_195 * V_196 ;
V_29 = F_57 ( V_3 , V_92 , V_40 ,
& V_189 -> V_67 ,
& V_189 -> V_93 ) ;
F_30 ( V_29 < 0 ) ;
V_196 = F_181 ( V_92 ) ;
F_182 ( V_196 , F_183 ( V_3 ) ) ;
}
* F_17 ( V_188 ) =
* F_17 ( V_189 ) ;
F_33 ( V_3 , V_189 ) ;
return 0 ;
V_194:
F_33 ( V_3 , V_189 ) ;
V_192:
return F_184 ( V_3 , V_92 , V_40 ,
V_162 , V_163 , V_82 , V_83 ,
V_164 , V_165 , V_65 , V_66 ) ;
}
enum V_94 F_185 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_28 -> V_35 ) )
return V_197 ;
return V_28 -> V_35 -> V_95 ;
}
T_8 F_183 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_28 -> V_35 ) )
return 0 ;
return V_28 -> V_35 -> V_198 ;
}
struct V_2 * F_186 ( struct V_13 * V_6 ,
enum V_199 type )
{
struct V_2 * V_3 = NULL ;
struct V_12 * V_12 ;
int V_29 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_41 ) ;
if ( ! V_12 ) {
V_29 = - V_193 ;
goto V_200;
}
V_3 = & V_12 -> V_45 ;
V_12 -> V_201 = F_187 ( V_12 -> V_202 ,
F_92 ( V_12 -> V_202 ) , false ) ;
if ( type == V_86 )
V_29 = F_188 ( V_6 , V_3 , 0xff ,
& V_203 ,
V_12 -> V_202 , V_12 -> V_201 ,
type , NULL ) ;
else
V_29 = F_188 ( V_6 , V_3 , 0xff ,
& V_204 ,
V_12 -> V_202 , V_12 -> V_201 ,
type , NULL ) ;
if ( V_29 )
goto V_200;
F_189 ( V_3 , & V_205 ) ;
F_12 ( V_3 , & V_3 -> V_45 ) ;
return V_3 ;
V_200:
if ( V_3 )
F_5 ( V_3 ) ;
return F_190 ( V_29 ) ;
}
