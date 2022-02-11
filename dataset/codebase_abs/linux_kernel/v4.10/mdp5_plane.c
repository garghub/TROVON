static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static bool F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_11 && V_10 -> V_12 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_13 ) ;
}
static void F_10 ( struct V_14 * V_6 ,
struct V_2 * V_3 )
{
F_11 ( V_3 ,
V_15 ,
V_15 |
V_16 |
V_17 |
V_18 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_21 = V_6 -> V_7 ;
struct V_22 * V_23 ;
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
F_14 ( V_24 , V_25 , 1 , 255 , 1 ) ;
F_10 ( V_6 , V_3 ) ;
#undef F_14
#undef F_15
#undef F_13
}
static int F_16 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_22 * V_26 ,
T_7 V_27 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 ;
struct V_4 * V_21 = V_6 -> V_7 ;
int V_30 = 0 ;
V_29 = F_17 ( V_10 ) ;
#define F_18 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
pstate->name = (type)val; \
DBG("Set property %s %d", #name, (type)val); \
goto done; \
} \
} while (0)
F_18 ( V_24 , V_25 , V_31 ) ;
F_19 ( V_6 -> V_6 , L_1 ) ;
V_30 = - V_32 ;
V_33:
return V_30 ;
#undef F_18
}
static int F_20 ( struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_22 * V_26 , T_7 * V_27 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 ;
struct V_4 * V_21 = V_6 -> V_7 ;
int V_30 = 0 ;
V_29 = F_17 ( V_10 ) ;
#define F_21 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
*val = pstate->name; \
DBG("Get property %s %lld", #name, *val); \
goto done; \
} \
} while (0)
F_21 ( V_24 , V_25 , V_31 ) ;
F_19 ( V_6 -> V_6 , L_1 ) ;
V_30 = - V_32 ;
V_33:
return V_30 ;
#undef F_18
}
static void
F_22 ( struct V_34 * V_35 ,
const struct V_9 * V_10 )
{
struct V_28 * V_29 = F_17 ( V_10 ) ;
F_23 ( V_35 , L_2 , V_29 -> V_36 ?
V_29 -> V_36 -> T_1 : L_3 ) ;
F_23 ( V_35 , L_4 , V_29 -> V_37 ) ;
F_23 ( V_35 , L_5 , V_29 -> V_24 ) ;
F_23 ( V_35 , L_6 , V_29 -> V_38 ) ;
F_23 ( V_35 , L_7 , F_24 ( V_29 -> V_39 ) ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_28 * V_40 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_26 ( V_3 -> V_10 -> V_11 ) ;
F_9 ( F_17 ( V_3 -> V_10 ) ) ;
V_40 = F_27 ( sizeof( * V_40 ) , V_41 ) ;
V_40 -> V_38 = 255 ;
V_40 -> V_37 = 0 ;
if ( V_3 -> type == V_42 )
V_40 -> V_24 = V_43 ;
else
V_40 -> V_24 = V_44 + F_28 ( V_3 ) ;
V_40 -> V_45 . V_3 = V_3 ;
V_3 -> V_10 = & V_40 -> V_45 ;
}
static struct V_9 *
F_29 ( struct V_2 * V_3 )
{
struct V_28 * V_40 ;
if ( F_30 ( ! V_3 -> V_10 ) )
return NULL ;
V_40 = F_31 ( F_17 ( V_3 -> V_10 ) ,
sizeof( * V_40 ) , V_41 ) ;
if ( V_40 && V_40 -> V_45 . V_11 )
F_32 ( V_40 -> V_45 . V_11 ) ;
return & V_40 -> V_45 ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_28 * V_29 = F_17 ( V_10 ) ;
if ( V_10 -> V_11 )
F_26 ( V_10 -> V_11 ) ;
F_9 ( V_29 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_9 * V_46 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_47 * V_11 = V_46 -> V_11 ;
if ( ! V_46 -> V_11 )
return 0 ;
F_35 ( L_8 , V_3 -> T_1 , V_11 -> V_45 . V_48 ) ;
return F_36 ( V_11 , V_1 -> V_48 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_9 * V_49 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_47 * V_11 = V_49 -> V_11 ;
if ( ! V_11 )
return;
F_35 ( L_9 , V_3 -> T_1 , V_11 -> V_45 . V_48 ) ;
F_38 ( V_11 , V_1 -> V_48 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_28 * V_40 = F_17 ( V_10 ) ;
struct V_9 * V_49 = V_3 -> V_10 ;
struct V_50 * V_51 = F_40 ( F_1 ( V_3 ) -> V_52 ) ;
bool V_53 = false ;
T_8 V_54 , V_55 ;
T_8 V_56 = 0 ;
F_35 ( L_10 , V_3 -> T_1 ,
F_4 ( V_49 ) , F_4 ( V_10 ) ) ;
V_54 = V_51 -> V_57 -> V_58 . V_54 << 16 ;
V_55 = V_51 -> V_57 -> V_58 . V_55 << 16 ;
if ( ( V_10 -> V_59 > V_54 ) || ( V_10 -> V_60 > V_55 ) ) {
struct V_61 V_62 = F_41 ( V_10 ) ;
F_35 ( L_11 V_63 ,
F_42 ( & V_62 ) ) ;
return - V_64 ;
}
if ( F_4 ( V_10 ) ) {
unsigned int V_65 ;
const struct V_66 * V_67 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_8 V_68 = 0 ;
V_67 = F_43 ( F_44 ( V_10 -> V_11 ) ) ;
if ( F_45 ( V_67 ) )
V_56 |= V_69 | V_70 ;
if ( ( ( V_10 -> V_59 >> 16 ) != V_10 -> V_71 ) ||
( ( V_10 -> V_60 >> 16 ) != V_10 -> V_72 ) )
V_56 |= V_69 ;
V_65 = F_46 ( V_10 -> V_65 ,
V_15 |
V_17 |
V_18 ) ;
if ( V_65 & V_17 )
V_56 |= V_73 ;
if ( V_65 & V_18 )
V_56 |= V_74 ;
if ( ! V_40 -> V_36 || ( V_56 & ~ V_40 -> V_36 -> V_56 ) )
V_53 = true ;
if ( V_1 -> V_75 ) {
const struct V_66 * V_67 =
F_43 ( F_44 ( V_10 -> V_11 ) ) ;
V_68 = F_47 ( V_1 -> V_75 , V_67 ,
V_10 -> V_59 >> 16 , false ) ;
if ( V_40 -> V_36 && ( V_40 -> V_36 -> V_68 != V_68 ) )
V_53 = true ;
}
if ( V_53 ) {
struct V_76 * V_77 = V_40 -> V_36 ;
V_40 -> V_36 = F_48 ( V_10 -> V_10 ,
V_3 , V_56 , V_68 ) ;
if ( F_49 ( V_40 -> V_36 ) ) {
F_35 ( L_12 , V_3 -> T_1 ) ;
return F_50 ( V_40 -> V_36 ) ;
}
F_51 ( V_10 -> V_10 , V_77 ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_9 * V_49 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
F_35 ( L_13 , V_3 -> T_1 ) ;
if ( F_4 ( V_10 ) ) {
int V_30 ;
V_30 = F_53 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_78 , V_10 -> V_79 ,
V_10 -> V_71 , V_10 -> V_72 ,
V_10 -> V_80 , V_10 -> V_81 ,
V_10 -> V_59 , V_10 -> V_60 ) ;
F_30 ( V_30 < 0 ) ;
}
}
static void F_54 ( struct V_2 * V_3 ,
struct V_47 * V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_76 * V_36 = F_17 ( V_3 -> V_10 ) -> V_36 ;
enum V_82 V_83 = V_36 -> V_83 ;
F_55 ( V_1 , F_56 ( V_83 ) ,
F_57 ( V_11 -> V_84 [ 0 ] ) |
F_58 ( V_11 -> V_84 [ 1 ] ) ) ;
F_55 ( V_1 , F_59 ( V_83 ) ,
F_60 ( V_11 -> V_84 [ 2 ] ) |
F_61 ( V_11 -> V_84 [ 3 ] ) ) ;
F_55 ( V_1 , F_62 ( V_83 ) ,
F_63 ( V_11 , V_1 -> V_48 , 0 ) ) ;
F_55 ( V_1 , F_64 ( V_83 ) ,
F_63 ( V_11 , V_1 -> V_48 , 1 ) ) ;
F_55 ( V_1 , F_65 ( V_83 ) ,
F_63 ( V_11 , V_1 -> V_48 , 2 ) ) ;
F_55 ( V_1 , F_66 ( V_83 ) ,
F_63 ( V_11 , V_1 -> V_48 , 3 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_67 ( struct V_1 * V_1 , enum V_82 V_83 )
{
T_8 V_85 = F_68 ( V_1 , F_69 ( V_83 ) ) &
~ V_86 ;
F_55 ( V_1 , F_69 ( V_83 ) , V_85 ) ;
}
static void F_70 ( struct V_1 * V_1 , enum V_82 V_83 ,
struct V_87 * V_88 )
{
T_8 V_89 , V_90 = 0 ;
T_8 * V_91 ;
if ( F_71 ( ! V_88 ) )
return;
if ( ( V_88 -> type == V_92 ) || ( V_93 == V_88 -> type ) )
V_90 |= F_72 ( V_94 ) ;
if ( ( V_88 -> type == V_95 ) || ( V_93 == V_88 -> type ) )
V_90 |= F_73 ( V_94 ) ;
V_90 |= V_86 ;
F_55 ( V_1 , F_69 ( V_83 ) , V_90 ) ;
V_91 = V_88 -> V_91 ;
F_55 ( V_1 , F_74 ( V_83 ) ,
F_75 ( V_91 [ 0 ] ) |
F_76 ( V_91 [ 1 ] ) ) ;
F_55 ( V_1 , F_77 ( V_83 ) ,
F_78 ( V_91 [ 2 ] ) |
F_79 ( V_91 [ 3 ] ) ) ;
F_55 ( V_1 , F_80 ( V_83 ) ,
F_81 ( V_91 [ 4 ] ) |
F_82 ( V_91 [ 5 ] ) ) ;
F_55 ( V_1 , F_83 ( V_83 ) ,
F_84 ( V_91 [ 6 ] ) |
F_85 ( V_91 [ 7 ] ) ) ;
F_55 ( V_1 , F_86 ( V_83 ) ,
F_87 ( V_91 [ 8 ] ) ) ;
for ( V_89 = 0 ; V_89 < F_88 ( V_88 -> V_96 ) ; V_89 ++ ) {
T_8 * V_97 = V_88 -> V_97 ;
T_8 * V_98 = V_88 -> V_98 ;
F_55 ( V_1 , F_89 ( V_83 , V_89 ) ,
F_90 ( V_97 [ 2 * V_89 + 1 ] ) |
F_91 ( V_97 [ 2 * V_89 ] ) ) ;
F_55 ( V_1 , F_92 ( V_83 , V_89 ) ,
F_93 ( V_98 [ 2 * V_89 + 1 ] ) |
F_94 ( V_98 [ 2 * V_89 ] ) ) ;
F_55 ( V_1 , F_95 ( V_83 , V_89 ) ,
F_96 ( V_88 -> V_96 [ V_89 ] ) ) ;
F_55 ( V_1 , F_97 ( V_83 , V_89 ) ,
F_98 ( V_88 -> V_99 [ V_89 ] ) ) ;
}
}
static int F_99 ( T_8 V_62 , T_8 V_100 , T_8 * V_101 )
{
T_8 V_102 ;
if ( V_62 == 0 || V_100 == 0 )
return - V_32 ;
if ( V_62 > ( V_100 * V_103 ) )
return - V_104 ;
V_102 = 1 << V_105 ;
* V_101 = F_100 ( V_102 , V_62 , V_100 ) ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 ,
T_8 V_106 , T_8 V_62 , T_8 V_107 ,
T_8 V_108 [ V_109 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_110 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_111 ;
unsigned int V_112 ;
int V_30 ;
V_30 = F_99 ( V_62 , V_107 , & V_111 ) ;
if ( V_30 ) {
F_19 ( V_6 , L_14 , V_62 , V_107 , V_30 ) ;
return V_30 ;
}
V_112 = F_102 ( V_106 ) ;
V_108 [ V_113 ] = V_111 ;
V_108 [ V_114 ] = V_111 ;
V_108 [ V_115 ] = V_111 / V_112 ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 ,
T_8 V_106 , T_8 V_62 , T_8 V_107 ,
T_8 V_116 [ V_109 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_110 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_117 ;
unsigned int V_118 ;
int V_30 ;
V_30 = F_99 ( V_62 , V_107 , & V_117 ) ;
if ( V_30 ) {
F_19 ( V_6 , L_15 , V_62 , V_107 , V_30 ) ;
return V_30 ;
}
V_118 = F_104 ( V_106 ) ;
V_116 [ V_113 ] = V_117 ;
V_116 [ V_114 ] = V_117 ;
V_116 [ V_115 ] = V_117 / V_118 ;
return 0 ;
}
static T_8 F_105 ( const struct V_66 * V_67 ,
T_8 V_62 , T_8 V_100 , bool V_119 )
{
bool V_120 = V_67 -> V_121 ? true : ( V_62 != V_100 ) ;
T_8 V_122 , V_123 = V_67 -> V_45 . V_106 ;
T_8 V_124 , V_125 ;
bool V_126 = V_67 -> V_121 ;
if ( ! V_120 )
return 0 ;
if ( V_126 ) {
V_122 = V_119 ? F_102 ( V_123 ) :
F_104 ( V_123 ) ;
V_125 = ( ( V_62 / V_122 ) <= V_100 ) ?
V_127 : V_128 ;
}
V_124 = ( V_62 <= V_100 ) ? V_127 : V_128 ;
if ( V_119 )
return V_129 |
F_106 ( V_124 ) |
F_107 ( V_124 ) |
F_108 ( V_126 , F_109 ( V_125 ) ) ;
else
return V_130 |
F_110 ( V_124 ) |
F_111 ( V_124 ) |
F_108 ( V_126 , F_112 ( V_125 ) ) ;
}
static void F_113 ( const struct V_66 * V_67 ,
T_8 V_62 , T_8 V_100 , T_8 V_131 [ 2 ] ,
int V_132 [ V_109 ] , int V_133 [ V_109 ] ,
bool V_119 )
{
bool V_120 = V_67 -> V_121 ? true : ( V_62 != V_100 ) ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_109 ; V_89 ++ ) {
V_132 [ V_89 ] = 0 ;
V_133 [ V_89 ] = V_120 ? 1 : 0 ;
}
}
static void F_114 ( struct V_1 * V_1 , enum V_82 V_83 ,
const struct V_66 * V_67 ,
T_8 V_59 , int V_134 [ V_109 ] , int V_135 [ V_109 ] ,
T_8 V_60 , int V_136 [ V_109 ] , int V_137 [ V_109 ] )
{
T_8 V_123 = V_67 -> V_45 . V_106 ;
T_8 V_138 , V_139 , V_140 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_109 ; V_89 ++ ) {
T_8 V_141 = V_59 ;
T_8 V_142 = V_60 ;
if ( V_67 -> V_121 && V_89 == V_115 ) {
V_141 /= F_102 ( V_123 ) ;
V_142 /= F_104 ( V_123 ) ;
}
V_138 = ( V_134 [ V_89 ] >= 0 ) ?
F_115 ( V_134 [ V_89 ] ) :
F_116 ( V_134 [ V_89 ] ) ;
V_138 |= ( V_135 [ V_89 ] >= 0 ) ?
F_117 ( V_135 [ V_89 ] ) :
F_118 ( V_135 [ V_89 ] ) ;
V_139 = ( V_136 [ V_89 ] >= 0 ) ?
F_119 ( V_136 [ V_89 ] ) :
F_120 ( V_136 [ V_89 ] ) ;
V_139 |= ( V_137 [ V_89 ] >= 0 ) ?
F_121 ( V_137 [ V_89 ] ) :
F_122 ( V_137 [ V_89 ] ) ;
V_140 = F_123 ( V_141 +
V_134 [ V_89 ] + V_135 [ V_89 ] ) ;
V_140 |= F_124 ( V_142 +
V_136 [ V_89 ] + V_137 [ V_89 ] ) ;
F_55 ( V_1 , F_125 ( V_83 , V_89 ) , V_138 ) ;
F_55 ( V_1 , F_126 ( V_83 , V_89 ) , V_139 ) ;
F_55 ( V_1 , F_127 ( V_83 , V_89 ) , V_140 ) ;
F_35 ( L_16 , V_89 ,
F_128 ( V_138 , F_115 ) ,
F_128 ( V_138 , F_117 ) ,
F_128 ( V_138 , F_116 ) ,
F_128 ( V_138 , F_118 ) ,
F_128 ( V_140 , F_123 ) ) ;
F_35 ( L_17 , V_89 ,
F_128 ( V_139 , F_119 ) ,
F_128 ( V_139 , F_121 ) ,
F_128 ( V_139 , F_120 ) ,
F_128 ( V_139 , F_122 ) ,
F_128 ( V_140 , F_124 ) ) ;
}
}
static int F_53 ( struct V_2 * V_3 ,
struct V_143 * V_12 , struct V_47 * V_11 ,
int V_78 , int V_79 ,
unsigned int V_71 , unsigned int V_72 ,
T_8 V_80 , T_8 V_81 ,
T_8 V_59 , T_8 V_60 )
{
struct V_9 * V_29 = V_3 -> V_10 ;
struct V_76 * V_36 = F_17 ( V_29 ) -> V_36 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_82 V_83 = V_36 -> V_83 ;
const struct V_66 * V_67 ;
T_8 V_144 , V_51 = 0 ;
T_8 V_111 [ V_109 ] = { 0 ,} , V_117 [ V_109 ] = { 0 ,} ;
bool V_145 = V_36 -> V_56 & V_146 ;
int V_134 [ V_109 ] , V_135 [ V_109 ] ;
int V_136 [ V_109 ] , V_137 [ V_109 ] ;
T_8 V_147 = 0 , V_148 = 0 ;
T_8 V_149 ;
unsigned int V_65 ;
bool V_150 , V_151 ;
unsigned long V_152 ;
int V_30 ;
V_144 = F_129 ( V_11 -> V_106 ) ;
if ( F_30 ( V_144 > F_130 ( V_83 ) ) )
return - V_32 ;
V_67 = F_43 ( F_44 ( V_11 ) ) ;
V_149 = V_67 -> V_45 . V_106 ;
V_80 = V_80 >> 16 ;
V_81 = V_81 >> 16 ;
V_59 = V_59 >> 16 ;
V_60 = V_60 >> 16 ;
F_35 ( L_18 , V_3 -> T_1 ,
V_11 -> V_45 . V_48 , V_80 , V_81 , V_59 , V_60 ,
V_12 -> V_45 . V_48 , V_78 , V_79 , V_71 , V_72 ) ;
V_30 = F_101 ( V_3 , V_149 , V_59 , V_71 , V_111 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_103 ( V_3 , V_149 , V_60 , V_72 , V_117 ) ;
if ( V_30 )
return V_30 ;
if ( V_36 -> V_56 & V_146 ) {
F_113 ( V_67 , V_59 , V_71 , V_111 ,
V_134 , V_135 , true ) ;
F_113 ( V_67 , V_60 , V_72 , V_117 ,
V_136 , V_137 , false ) ;
}
V_51 |= F_105 ( V_67 , V_59 , V_71 , true ) ;
V_51 |= F_105 ( V_67 , V_60 , V_72 , false ) ;
F_35 ( L_19 , V_51 ) ;
V_65 = F_46 ( V_29 -> V_65 ,
V_15 |
V_17 |
V_18 ) ;
V_151 = ! ! ( V_65 & V_17 ) ;
V_150 = ! ! ( V_65 & V_18 ) ;
F_131 ( & V_36 -> V_153 , V_152 ) ;
F_55 ( V_1 , F_132 ( V_83 ) ,
F_133 ( T_5 ( V_11 -> V_154 , V_59 ) ) |
F_134 ( T_5 ( V_11 -> V_155 , V_60 ) ) ) ;
F_55 ( V_1 , F_135 ( V_83 ) ,
F_136 ( V_59 ) |
F_137 ( V_60 ) ) ;
F_55 ( V_1 , F_138 ( V_83 ) ,
F_139 ( V_80 ) |
F_140 ( V_81 ) ) ;
F_55 ( V_1 , F_141 ( V_83 ) ,
F_142 ( V_71 ) |
F_143 ( V_72 ) ) ;
F_55 ( V_1 , F_144 ( V_83 ) ,
F_145 ( V_78 ) |
F_146 ( V_79 ) ) ;
F_55 ( V_1 , F_147 ( V_83 ) ,
F_148 ( V_67 -> V_156 ) |
F_149 ( V_67 -> V_157 ) |
F_150 ( V_67 -> V_158 ) |
F_151 ( V_67 -> V_159 ) |
F_108 ( V_67 -> V_160 , V_161 ) |
F_152 ( V_67 -> V_162 - 1 ) |
F_153 ( V_67 -> V_163 - 1 ) |
F_108 ( V_67 -> V_164 , V_165 ) |
F_154 ( V_67 -> V_166 ) |
F_155 ( V_67 -> V_167 ) ) ;
F_55 ( V_1 , F_156 ( V_83 ) ,
F_157 ( V_67 -> V_168 [ 0 ] ) |
F_158 ( V_67 -> V_168 [ 1 ] ) |
F_159 ( V_67 -> V_168 [ 2 ] ) |
F_160 ( V_67 -> V_168 [ 3 ] ) ) ;
F_55 ( V_1 , F_161 ( V_83 ) ,
( V_151 ? V_169 : 0 ) |
( V_150 ? V_170 : 0 ) |
F_108 ( V_145 , V_171 ) |
F_162 ( V_172 ) ) ;
F_55 ( V_1 , F_163 ( V_83 ) , 0 ) ;
if ( V_36 -> V_56 & V_146 )
F_114 ( V_1 , V_83 , V_67 ,
V_59 , V_134 , V_135 ,
V_60 , V_136 , V_137 ) ;
if ( V_36 -> V_56 & V_69 ) {
F_55 ( V_1 , F_164 ( V_83 ) ,
V_111 [ V_113 ] ) ;
F_55 ( V_1 , F_165 ( V_83 ) ,
V_117 [ V_113 ] ) ;
F_55 ( V_1 , F_166 ( V_83 ) ,
V_111 [ V_115 ] ) ;
F_55 ( V_1 , F_167 ( V_83 ) ,
V_117 [ V_115 ] ) ;
F_55 ( V_1 , F_168 ( V_83 ) ,
F_169 ( V_148 ) |
F_170 ( V_147 ) ) ;
F_55 ( V_1 , F_171 ( V_83 ) , V_51 ) ;
}
if ( V_36 -> V_56 & V_70 ) {
if ( F_45 ( V_67 ) )
F_70 ( V_1 , V_83 ,
F_172 ( V_92 ) ) ;
else
F_67 ( V_1 , V_83 ) ;
}
F_54 ( V_3 , V_11 ) ;
F_173 ( & V_36 -> V_153 , V_152 ) ;
return V_30 ;
}
enum V_82 F_174 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_29 -> V_36 ) )
return 0 ;
return V_29 -> V_36 -> V_83 ;
}
T_8 F_175 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_17 ( V_3 -> V_10 ) ;
if ( F_30 ( ! V_29 -> V_36 ) )
return 0 ;
return V_29 -> V_36 -> V_173 ;
}
struct V_2 * F_176 ( struct V_14 * V_6 , bool V_174 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_30 ;
enum V_175 type ;
V_13 = F_27 ( sizeof( * V_13 ) , V_41 ) ;
if ( ! V_13 ) {
V_30 = - V_176 ;
goto V_177;
}
V_3 = & V_13 -> V_45 ;
V_13 -> V_178 = F_177 ( V_13 -> V_179 ,
F_88 ( V_13 -> V_179 ) , false ) ;
type = V_174 ? V_42 : V_180 ;
V_30 = F_178 ( V_6 , V_3 , 0xff , & V_181 ,
V_13 -> V_179 , V_13 -> V_178 ,
type , NULL ) ;
if ( V_30 )
goto V_177;
F_179 ( V_3 , & V_182 ) ;
F_12 ( V_3 , & V_3 -> V_45 ) ;
return V_3 ;
V_177:
if ( V_3 )
F_5 ( V_3 ) ;
return F_180 ( V_30 ) ;
}
