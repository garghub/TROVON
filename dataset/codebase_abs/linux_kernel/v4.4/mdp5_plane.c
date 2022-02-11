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
struct V_13 * V_13 = F_6 ( V_3 ) ;
if ( ! ( V_13 -> V_15 & V_16 ) &&
! ( V_13 -> V_15 & V_17 ) )
return;
if ( ! V_6 -> V_18 . V_19 )
V_6 -> V_18 . V_19 =
F_11 ( V_6 ,
F_12 ( V_20 ) | F_12 ( V_21 ) ) ;
if ( V_6 -> V_18 . V_19 )
F_13 ( & V_3 -> V_22 ,
V_6 -> V_18 . V_19 ,
0 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_25 = V_6 -> V_7 ;
struct V_26 * V_27 ;
#define F_15 ( T_1 , T_2 , T_3 , T_4 , ... ) do { \
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
#define F_16 ( T_1 , T_2 , T_5 , T_6 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_range, min, max)
#define F_17 ( T_1 , T_2 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_enum, name##_prop_enum_list, \
ARRAY_SIZE(name##_prop_enum_list))
F_16 ( V_28 , V_29 , 1 , 255 , 1 ) ;
F_10 ( V_6 , V_3 ) ;
#undef F_16
#undef F_17
#undef F_15
}
static int F_18 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_26 * V_30 ,
T_7 V_31 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_32 * V_33 ;
struct V_4 * V_25 = V_6 -> V_7 ;
int V_34 = 0 ;
V_33 = F_19 ( V_10 ) ;
#define F_20 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
pstate->name = (type)val; \
DBG("Set property %s %d", #name, (type)val); \
goto done; \
} \
} while (0)
F_20 ( V_28 , V_29 , V_35 ) ;
F_21 ( V_6 -> V_6 , L_1 ) ;
V_34 = - V_36 ;
V_37:
return V_34 ;
#undef F_20
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_26 * V_30 , T_7 * V_31 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_32 * V_33 ;
struct V_4 * V_25 = V_6 -> V_7 ;
int V_34 = 0 ;
V_33 = F_19 ( V_10 ) ;
#define F_23 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
*val = pstate->name; \
DBG("Get property %s %lld", #name, *val); \
goto done; \
} \
} while (0)
F_23 ( V_28 , V_29 , V_35 ) ;
F_21 ( V_6 -> V_6 , L_1 ) ;
V_34 = - V_36 ;
V_37:
return V_34 ;
#undef F_20
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_32 * V_38 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_25 ( V_3 -> V_10 -> V_11 ) ;
F_9 ( F_19 ( V_3 -> V_10 ) ) ;
V_38 = F_26 ( sizeof( * V_38 ) , V_39 ) ;
V_38 -> V_40 = 255 ;
V_38 -> V_41 = 0 ;
if ( V_3 -> type == V_42 )
V_38 -> V_28 = V_43 ;
else
V_38 -> V_28 = V_44 + F_27 ( V_3 ) ;
V_38 -> V_22 . V_3 = V_3 ;
V_3 -> V_10 = & V_38 -> V_22 ;
}
static struct V_9 *
F_28 ( struct V_2 * V_3 )
{
struct V_32 * V_38 ;
if ( F_29 ( ! V_3 -> V_10 ) )
return NULL ;
V_38 = F_30 ( F_19 ( V_3 -> V_10 ) ,
sizeof( * V_38 ) , V_39 ) ;
if ( V_38 && V_38 -> V_22 . V_11 )
F_31 ( V_38 -> V_22 . V_11 ) ;
V_38 -> V_45 = false ;
V_38 -> V_46 = false ;
return & V_38 -> V_22 ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
F_25 ( V_10 -> V_11 ) ;
F_9 ( F_19 ( V_10 ) ) ;
}
static int F_33 ( struct V_2 * V_3 ,
const struct V_9 * V_47 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_48 * V_11 = V_47 -> V_11 ;
if ( ! V_47 -> V_11 )
return 0 ;
F_34 ( L_2 , V_13 -> T_1 , V_11 -> V_22 . V_49 ) ;
return F_35 ( V_11 , V_1 -> V_49 ) ;
}
static void F_36 ( struct V_2 * V_3 ,
const struct V_9 * V_50 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_48 * V_11 = V_50 -> V_11 ;
if ( ! V_11 )
return;
F_34 ( L_3 , V_13 -> T_1 , V_11 -> V_22 . V_49 ) ;
F_37 ( V_11 , V_1 -> V_49 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_50 = V_3 -> V_10 ;
const struct V_51 * V_52 ;
bool V_53 , V_54 ;
F_34 ( L_4 , V_13 -> T_1 ,
F_4 ( V_50 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) ) {
V_52 = F_39 ( F_40 ( V_10 -> V_11 ) ) ;
if ( F_41 ( V_52 ) &&
! F_42 ( V_13 -> V_15 ) ) {
F_21 ( V_3 -> V_6 -> V_6 ,
L_5 ) ;
return - V_36 ;
}
if ( ! ( V_13 -> V_15 & V_55 ) &&
( ( ( V_10 -> V_56 >> 16 ) != V_10 -> V_57 ) ||
( ( V_10 -> V_58 >> 16 ) != V_10 -> V_59 ) ) ) {
F_21 ( V_3 -> V_6 -> V_6 ,
L_6 ,
V_10 -> V_56 >> 16 , V_10 -> V_58 >> 16 ,
V_10 -> V_57 , V_10 -> V_59 ) ;
return - V_36 ;
}
V_54 = ! ! ( V_10 -> V_60 & F_12 ( V_20 ) ) ;
V_53 = ! ! ( V_10 -> V_60 & F_12 ( V_21 ) ) ;
if ( ( V_53 && ! ( V_13 -> V_15 & V_17 ) ) ||
( V_54 && ! ( V_13 -> V_15 & V_16 ) ) ) {
F_21 ( V_3 -> V_6 -> V_6 ,
L_7 ) ;
return - V_36 ;
}
}
if ( F_4 ( V_10 ) && F_4 ( V_50 ) ) {
bool V_61 = false ;
if ( V_10 -> V_11 -> V_62 != V_50 -> V_11 -> V_62 ) {
F_34 ( L_8 , V_13 -> T_1 ) ;
V_61 = true ;
}
if ( V_10 -> V_56 != V_50 -> V_56 ) {
F_34 ( L_9 , V_13 -> T_1 ) ;
V_61 = true ;
}
if ( F_19 ( V_50 ) -> V_46 ) {
F_34 ( L_10 , V_13 -> T_1 ) ;
V_61 = true ;
}
if ( V_61 ) {
struct V_63 * V_64 =
F_43 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_64 -> V_45 = true ;
F_19 ( V_10 ) -> V_45 = true ;
}
} else {
F_19 ( V_10 ) -> V_45 = true ;
}
return 0 ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_9 * V_50 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_34 ( L_11 , V_13 -> T_1 ) ;
if ( ! F_4 ( V_10 ) ) {
F_19 ( V_10 ) -> V_46 = true ;
} else if ( F_19 ( V_10 ) -> V_45 ) {
int V_34 ;
F_19 ( V_10 ) -> V_46 = true ;
V_34 = F_45 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_65 , V_10 -> V_66 ,
V_10 -> V_57 , V_10 -> V_59 ,
V_10 -> V_67 , V_10 -> V_68 ,
V_10 -> V_56 , V_10 -> V_58 ) ;
F_29 ( V_34 < 0 ) ;
} else {
unsigned long V_69 ;
F_46 ( & V_13 -> V_70 , V_69 ) ;
F_47 ( V_3 , V_10 -> V_11 ) ;
F_48 ( & V_13 -> V_70 , V_69 ) ;
}
}
static void F_47 ( struct V_2 * V_3 ,
struct V_48 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_71 V_72 = V_13 -> V_72 ;
F_49 ( V_1 , F_50 ( V_72 ) ,
F_51 ( V_11 -> V_73 [ 0 ] ) |
F_52 ( V_11 -> V_73 [ 1 ] ) ) ;
F_49 ( V_1 , F_53 ( V_72 ) ,
F_54 ( V_11 -> V_73 [ 2 ] ) |
F_55 ( V_11 -> V_73 [ 3 ] ) ) ;
F_49 ( V_1 , F_56 ( V_72 ) ,
F_57 ( V_11 , V_1 -> V_49 , 0 ) ) ;
F_49 ( V_1 , F_58 ( V_72 ) ,
F_57 ( V_11 , V_1 -> V_49 , 1 ) ) ;
F_49 ( V_1 , F_59 ( V_72 ) ,
F_57 ( V_11 , V_1 -> V_49 , 2 ) ) ;
F_49 ( V_1 , F_60 ( V_72 ) ,
F_57 ( V_11 , V_1 -> V_49 , 3 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_61 ( struct V_1 * V_1 , enum V_71 V_72 )
{
T_8 V_74 = F_62 ( V_1 , F_63 ( V_72 ) ) &
~ V_75 ;
F_49 ( V_1 , F_63 ( V_72 ) , V_74 ) ;
}
static void F_64 ( struct V_1 * V_1 , enum V_71 V_72 ,
struct V_76 * V_77 )
{
T_8 V_78 , V_79 = 0 ;
T_8 * V_80 ;
if ( F_65 ( ! V_77 ) )
return;
if ( ( V_77 -> type == V_81 ) || ( V_82 == V_77 -> type ) )
V_79 |= F_66 ( V_83 ) ;
if ( ( V_77 -> type == V_84 ) || ( V_82 == V_77 -> type ) )
V_79 |= F_67 ( V_83 ) ;
V_79 |= V_75 ;
F_49 ( V_1 , F_63 ( V_72 ) , V_79 ) ;
V_80 = V_77 -> V_80 ;
F_49 ( V_1 , F_68 ( V_72 ) ,
F_69 ( V_80 [ 0 ] ) |
F_70 ( V_80 [ 1 ] ) ) ;
F_49 ( V_1 , F_71 ( V_72 ) ,
F_72 ( V_80 [ 2 ] ) |
F_73 ( V_80 [ 3 ] ) ) ;
F_49 ( V_1 , F_74 ( V_72 ) ,
F_75 ( V_80 [ 4 ] ) |
F_76 ( V_80 [ 5 ] ) ) ;
F_49 ( V_1 , F_77 ( V_72 ) ,
F_78 ( V_80 [ 6 ] ) |
F_79 ( V_80 [ 7 ] ) ) ;
F_49 ( V_1 , F_80 ( V_72 ) ,
F_81 ( V_80 [ 8 ] ) ) ;
for ( V_78 = 0 ; V_78 < F_82 ( V_77 -> V_85 ) ; V_78 ++ ) {
T_8 * V_86 = V_77 -> V_86 ;
T_8 * V_87 = V_77 -> V_87 ;
F_49 ( V_1 , F_83 ( V_72 , V_78 ) ,
F_84 ( V_86 [ 2 * V_78 + 1 ] ) |
F_85 ( V_86 [ 2 * V_78 ] ) ) ;
F_49 ( V_1 , F_86 ( V_72 , V_78 ) ,
F_87 ( V_87 [ 2 * V_78 + 1 ] ) |
F_88 ( V_87 [ 2 * V_78 ] ) ) ;
F_49 ( V_1 , F_89 ( V_72 , V_78 ) ,
F_90 ( V_77 -> V_85 [ V_78 ] ) ) ;
F_49 ( V_1 , F_91 ( V_72 , V_78 ) ,
F_92 ( V_77 -> V_88 [ V_78 ] ) ) ;
}
}
static int F_93 ( T_8 V_89 , T_8 V_90 , T_8 * V_91 )
{
T_8 V_92 ;
if ( V_89 == 0 || V_90 == 0 )
return - V_36 ;
if ( V_89 > ( V_90 * V_93 ) )
return - V_94 ;
V_92 = 1 << V_95 ;
* V_91 = F_94 ( V_92 , V_89 , V_90 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 ,
T_8 V_62 , T_8 V_89 , T_8 V_96 ,
T_8 V_97 [ V_98 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_99 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_100 ;
unsigned int V_101 ;
int V_34 ;
V_34 = F_93 ( V_89 , V_96 , & V_100 ) ;
if ( V_34 ) {
F_21 ( V_6 , L_12 , V_89 , V_96 , V_34 ) ;
return V_34 ;
}
V_101 = F_96 ( V_62 ) ;
V_97 [ V_102 ] = V_100 ;
V_97 [ V_103 ] = V_100 ;
V_97 [ V_104 ] = V_100 / V_101 ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 ,
T_8 V_62 , T_8 V_89 , T_8 V_96 ,
T_8 V_105 [ V_98 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_99 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_106 ;
unsigned int V_107 ;
int V_34 ;
V_34 = F_93 ( V_89 , V_96 , & V_106 ) ;
if ( V_34 ) {
F_21 ( V_6 , L_13 , V_89 , V_96 , V_34 ) ;
return V_34 ;
}
V_107 = F_98 ( V_62 ) ;
V_105 [ V_102 ] = V_106 ;
V_105 [ V_103 ] = V_106 ;
V_105 [ V_104 ] = V_106 / V_107 ;
return 0 ;
}
static T_8 F_99 ( const struct V_51 * V_52 ,
T_8 V_89 , T_8 V_90 , bool V_108 )
{
bool V_109 = V_52 -> V_110 ? true : ( V_89 != V_90 ) ;
T_8 V_111 , V_112 = V_52 -> V_22 . V_62 ;
T_8 V_113 , V_114 ;
bool V_115 = V_52 -> V_110 ;
if ( ! V_109 )
return 0 ;
if ( V_115 ) {
V_111 = V_108 ? F_96 ( V_112 ) :
F_98 ( V_112 ) ;
V_114 = ( ( V_89 / V_111 ) <= V_90 ) ?
V_116 : V_117 ;
}
V_113 = ( V_89 <= V_90 ) ? V_116 : V_117 ;
if ( V_108 )
return V_118 |
F_100 ( V_113 ) |
F_101 ( V_113 ) |
F_102 ( V_115 , F_103 ( V_114 ) ) ;
else
return V_119 |
F_104 ( V_113 ) |
F_105 ( V_113 ) |
F_102 ( V_115 , F_106 ( V_114 ) ) ;
}
static void F_107 ( const struct V_51 * V_52 ,
T_8 V_89 , T_8 V_90 , T_8 V_120 [ 2 ] ,
int V_121 [ V_98 ] , int V_122 [ V_98 ] ,
bool V_108 )
{
bool V_109 = V_52 -> V_110 ? true : ( V_89 != V_90 ) ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_98 ; V_78 ++ ) {
V_121 [ V_78 ] = 0 ;
V_122 [ V_78 ] = V_109 ? 1 : 0 ;
}
}
static void F_108 ( struct V_1 * V_1 , enum V_71 V_72 ,
const struct V_51 * V_52 ,
T_8 V_56 , int V_123 [ V_98 ] , int V_124 [ V_98 ] ,
T_8 V_58 , int V_125 [ V_98 ] , int V_126 [ V_98 ] )
{
T_8 V_112 = V_52 -> V_22 . V_62 ;
T_8 V_127 , V_128 , V_129 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_98 ; V_78 ++ ) {
T_8 V_130 = V_56 ;
T_8 V_131 = V_58 ;
if ( V_52 -> V_110 && V_78 == V_104 ) {
V_130 /= F_96 ( V_112 ) ;
V_131 /= F_98 ( V_112 ) ;
}
V_127 = ( V_123 [ V_78 ] >= 0 ) ?
F_109 ( V_123 [ V_78 ] ) :
F_110 ( V_123 [ V_78 ] ) ;
V_127 |= ( V_124 [ V_78 ] >= 0 ) ?
F_111 ( V_124 [ V_78 ] ) :
F_112 ( V_124 [ V_78 ] ) ;
V_128 = ( V_125 [ V_78 ] >= 0 ) ?
F_113 ( V_125 [ V_78 ] ) :
F_114 ( V_125 [ V_78 ] ) ;
V_128 |= ( V_126 [ V_78 ] >= 0 ) ?
F_115 ( V_126 [ V_78 ] ) :
F_116 ( V_126 [ V_78 ] ) ;
V_129 = F_117 ( V_130 +
V_123 [ V_78 ] + V_124 [ V_78 ] ) ;
V_129 |= F_118 ( V_131 +
V_125 [ V_78 ] + V_126 [ V_78 ] ) ;
F_49 ( V_1 , F_119 ( V_72 , V_78 ) , V_127 ) ;
F_49 ( V_1 , F_120 ( V_72 , V_78 ) , V_128 ) ;
F_49 ( V_1 , F_121 ( V_72 , V_78 ) , V_129 ) ;
F_34 ( L_14 , V_78 ,
F_122 ( V_127 , F_109 ) ,
F_122 ( V_127 , F_111 ) ,
F_122 ( V_127 , F_110 ) ,
F_122 ( V_127 , F_112 ) ,
F_122 ( V_129 , F_117 ) ) ;
F_34 ( L_15 , V_78 ,
F_122 ( V_128 , F_113 ) ,
F_122 ( V_128 , F_115 ) ,
F_122 ( V_128 , F_114 ) ,
F_122 ( V_128 , F_116 ) ,
F_122 ( V_129 , F_118 ) ) ;
}
}
static int F_45 ( struct V_2 * V_3 ,
struct V_132 * V_12 , struct V_48 * V_11 ,
int V_65 , int V_66 ,
unsigned int V_57 , unsigned int V_59 ,
T_8 V_67 , T_8 V_68 ,
T_8 V_56 , T_8 V_58 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_33 = V_3 -> V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_71 V_72 = V_13 -> V_72 ;
const struct V_51 * V_52 ;
T_8 V_133 , V_134 = 0 ;
T_8 V_100 [ V_98 ] = { 0 ,} , V_106 [ V_98 ] = { 0 ,} ;
bool V_135 = V_13 -> V_15 & V_136 ;
int V_123 [ V_98 ] , V_124 [ V_98 ] ;
int V_125 [ V_98 ] , V_126 [ V_98 ] ;
T_8 V_137 = 0 , V_138 = 0 ;
T_8 V_139 ;
bool V_53 , V_54 ;
unsigned long V_69 ;
int V_34 ;
V_133 = F_123 ( V_11 -> V_62 ) ;
if ( F_29 ( V_133 > F_124 ( V_72 ) ) )
return - V_36 ;
V_52 = F_39 ( F_40 ( V_11 ) ) ;
V_139 = V_52 -> V_22 . V_62 ;
V_67 = V_67 >> 16 ;
V_68 = V_68 >> 16 ;
V_56 = V_56 >> 16 ;
V_58 = V_58 >> 16 ;
F_34 ( L_16 , V_13 -> T_1 ,
V_11 -> V_22 . V_49 , V_67 , V_68 , V_56 , V_58 ,
V_12 -> V_22 . V_49 , V_65 , V_66 , V_57 , V_59 ) ;
if ( V_1 -> V_140 ) {
V_34 = F_125 ( V_1 -> V_140 ,
V_13 -> V_72 , V_52 , V_56 , false ) ;
if ( V_34 )
return V_34 ;
}
if ( V_1 -> V_140 )
F_126 ( V_1 -> V_140 , V_72 ) ;
V_34 = F_95 ( V_3 , V_139 , V_56 , V_57 , V_100 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_97 ( V_3 , V_139 , V_58 , V_59 , V_106 ) ;
if ( V_34 )
return V_34 ;
if ( V_13 -> V_15 & V_136 ) {
F_107 ( V_52 , V_56 , V_57 , V_100 ,
V_123 , V_124 , true ) ;
F_107 ( V_52 , V_58 , V_59 , V_106 ,
V_125 , V_126 , false ) ;
}
V_134 |= F_99 ( V_52 , V_56 , V_57 , true ) ;
V_134 |= F_99 ( V_52 , V_58 , V_59 , false ) ;
F_34 ( L_17 , V_134 ) ;
V_54 = ! ! ( V_33 -> V_60 & F_12 ( V_20 ) ) ;
V_53 = ! ! ( V_33 -> V_60 & F_12 ( V_21 ) ) ;
F_46 ( & V_13 -> V_70 , V_69 ) ;
F_49 ( V_1 , F_127 ( V_72 ) ,
F_128 ( V_11 -> V_141 ) |
F_129 ( V_11 -> V_142 ) ) ;
F_49 ( V_1 , F_130 ( V_72 ) ,
F_131 ( V_56 ) |
F_132 ( V_58 ) ) ;
F_49 ( V_1 , F_133 ( V_72 ) ,
F_134 ( V_67 ) |
F_135 ( V_68 ) ) ;
F_49 ( V_1 , F_136 ( V_72 ) ,
F_137 ( V_57 ) |
F_138 ( V_59 ) ) ;
F_49 ( V_1 , F_139 ( V_72 ) ,
F_140 ( V_65 ) |
F_141 ( V_66 ) ) ;
F_49 ( V_1 , F_142 ( V_72 ) ,
F_143 ( V_52 -> V_143 ) |
F_144 ( V_52 -> V_144 ) |
F_145 ( V_52 -> V_145 ) |
F_146 ( V_52 -> V_146 ) |
F_102 ( V_52 -> V_147 , V_148 ) |
F_147 ( V_52 -> V_149 - 1 ) |
F_148 ( V_52 -> V_150 - 1 ) |
F_102 ( V_52 -> V_151 , V_152 ) |
F_149 ( V_52 -> V_153 ) |
F_150 ( V_52 -> V_154 ) ) ;
F_49 ( V_1 , F_151 ( V_72 ) ,
F_152 ( V_52 -> V_155 [ 0 ] ) |
F_153 ( V_52 -> V_155 [ 1 ] ) |
F_154 ( V_52 -> V_155 [ 2 ] ) |
F_155 ( V_52 -> V_155 [ 3 ] ) ) ;
F_49 ( V_1 , F_156 ( V_72 ) ,
( V_54 ? V_156 : 0 ) |
( V_53 ? V_157 : 0 ) |
F_102 ( V_135 , V_158 ) |
F_157 ( V_159 ) ) ;
F_49 ( V_1 , F_158 ( V_72 ) , 0 ) ;
if ( V_13 -> V_15 & V_136 )
F_108 ( V_1 , V_72 , V_52 ,
V_56 , V_123 , V_124 ,
V_58 , V_125 , V_126 ) ;
if ( V_13 -> V_15 & V_55 ) {
F_49 ( V_1 , F_159 ( V_72 ) ,
V_100 [ V_102 ] ) ;
F_49 ( V_1 , F_160 ( V_72 ) ,
V_106 [ V_102 ] ) ;
F_49 ( V_1 , F_161 ( V_72 ) ,
V_100 [ V_104 ] ) ;
F_49 ( V_1 , F_162 ( V_72 ) ,
V_106 [ V_104 ] ) ;
F_49 ( V_1 , F_163 ( V_72 ) ,
F_164 ( V_138 ) |
F_165 ( V_137 ) ) ;
F_49 ( V_1 , F_166 ( V_72 ) , V_134 ) ;
}
if ( V_13 -> V_15 & V_160 ) {
if ( F_41 ( V_52 ) )
F_64 ( V_1 , V_72 ,
F_167 ( V_81 ) ) ;
else
F_61 ( V_1 , V_72 ) ;
}
F_47 ( V_3 , V_11 ) ;
F_48 ( & V_13 -> V_70 , V_69 ) ;
return V_34 ;
}
void F_168 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_71 V_72 = V_13 -> V_72 ;
F_34 ( L_18 , V_13 -> T_1 ) ;
if ( V_1 -> V_140 )
F_169 ( V_1 -> V_140 , V_72 ) ;
F_19 ( V_3 -> V_10 ) -> V_46 = false ;
}
enum V_71 F_170 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_72 ;
}
T_8 F_171 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_161 ;
}
void F_172 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_71 V_72 = V_13 -> V_72 ;
if ( ! F_4 ( V_3 -> V_10 ) && V_1 -> V_140 ) {
F_34 ( L_19 , V_13 -> T_1 ) ;
F_173 ( V_1 -> V_140 , V_72 ) ;
}
}
struct V_2 * F_174 ( struct V_14 * V_6 ,
enum V_71 V_72 , bool V_162 , T_8 V_163 ,
T_8 V_15 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_34 ;
enum V_164 type ;
V_13 = F_26 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 ) {
V_34 = - V_165 ;
goto V_166;
}
V_3 = & V_13 -> V_22 ;
V_13 -> V_72 = V_72 ;
V_13 -> T_1 = F_175 ( V_72 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_167 = F_176 ( V_13 -> V_168 ,
F_82 ( V_13 -> V_168 ) ,
! F_42 ( V_13 -> V_15 ) ) ;
V_13 -> V_161 = F_177 ( V_72 ) ;
V_13 -> V_163 = V_163 ;
F_178 ( & V_13 -> V_70 ) ;
type = V_162 ? V_42 : V_169 ;
V_34 = F_179 ( V_6 , V_3 , 0xff , & V_170 ,
V_13 -> V_168 , V_13 -> V_167 ,
type ) ;
if ( V_34 )
goto V_166;
F_180 ( V_3 , & V_171 ) ;
F_14 ( V_3 , & V_3 -> V_22 ) ;
return V_3 ;
V_166:
if ( V_3 )
F_5 ( V_3 ) ;
return F_181 ( V_34 ) ;
}
