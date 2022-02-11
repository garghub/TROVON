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
V_20 | V_21 | V_22 ) ;
if ( V_6 -> V_18 . V_19 )
F_12 ( & V_3 -> V_23 ,
V_6 -> V_18 . V_19 ,
V_20 ) ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_26 = V_6 -> V_7 ;
struct V_27 * V_28 ;
#define F_14 ( T_1 , T_2 , T_3 , T_4 , ... ) do { \
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
#define F_15 ( T_1 , T_2 , T_5 , T_6 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_range, min, max)
#define F_16 ( T_1 , T_2 , T_3 ) \
INSTALL_PROPERTY(name, NAME, init_val, \
create_enum, name##_prop_enum_list, \
ARRAY_SIZE(name##_prop_enum_list))
F_15 ( V_29 , V_30 , 1 , 255 , 1 ) ;
F_10 ( V_6 , V_3 ) ;
#undef F_15
#undef F_16
#undef F_14
}
static int F_17 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_27 * V_31 ,
T_7 V_32 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_33 * V_34 ;
struct V_4 * V_26 = V_6 -> V_7 ;
int V_35 = 0 ;
V_34 = F_18 ( V_10 ) ;
#define F_19 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
pstate->name = (type)val; \
DBG("Set property %s %d", #name, (type)val); \
goto done; \
} \
} while (0)
F_19 ( V_29 , V_30 , V_36 ) ;
F_20 ( V_6 -> V_6 , L_1 ) ;
V_35 = - V_37 ;
V_38:
return V_35 ;
#undef F_19
}
static int F_21 ( struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_27 * V_31 , T_7 * V_32 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_33 * V_34 ;
struct V_4 * V_26 = V_6 -> V_7 ;
int V_35 = 0 ;
V_34 = F_18 ( V_10 ) ;
#define F_22 ( T_1 , T_2 , type ) do { \
if (dev_priv->plane_property[PLANE_PROP_##NAME] == property) { \
*val = pstate->name; \
DBG("Get property %s %lld", #name, *val); \
goto done; \
} \
} while (0)
F_22 ( V_29 , V_30 , V_36 ) ;
F_20 ( V_6 -> V_6 , L_1 ) ;
V_35 = - V_37 ;
V_38:
return V_35 ;
#undef F_19
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_33 * V_39 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_24 ( V_3 -> V_10 -> V_11 ) ;
F_9 ( F_18 ( V_3 -> V_10 ) ) ;
V_39 = F_25 ( sizeof( * V_39 ) , V_40 ) ;
V_39 -> V_41 = 255 ;
V_39 -> V_42 = 0 ;
if ( V_3 -> type == V_43 )
V_39 -> V_29 = V_44 ;
else
V_39 -> V_29 = V_45 + F_26 ( V_3 ) ;
V_39 -> V_23 . V_3 = V_3 ;
V_3 -> V_10 = & V_39 -> V_23 ;
}
static struct V_9 *
F_27 ( struct V_2 * V_3 )
{
struct V_33 * V_39 ;
if ( F_28 ( ! V_3 -> V_10 ) )
return NULL ;
V_39 = F_29 ( F_18 ( V_3 -> V_10 ) ,
sizeof( * V_39 ) , V_40 ) ;
if ( V_39 && V_39 -> V_23 . V_11 )
F_30 ( V_39 -> V_23 . V_11 ) ;
V_39 -> V_46 = false ;
V_39 -> V_47 = false ;
return & V_39 -> V_23 ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
F_24 ( V_10 -> V_11 ) ;
F_9 ( F_18 ( V_10 ) ) ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_9 * V_48 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_49 * V_11 = V_48 -> V_11 ;
if ( ! V_48 -> V_11 )
return 0 ;
F_33 ( L_2 , V_13 -> T_1 , V_11 -> V_23 . V_50 ) ;
return F_34 ( V_11 , V_1 -> V_50 ) ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_9 * V_51 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_49 * V_11 = V_51 -> V_11 ;
if ( ! V_11 )
return;
F_33 ( L_3 , V_13 -> T_1 , V_11 -> V_23 . V_50 ) ;
F_36 ( V_11 , V_1 -> V_50 ) ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_51 = V_3 -> V_10 ;
const struct V_52 * V_53 ;
bool V_54 , V_55 ;
F_33 ( L_4 , V_13 -> T_1 ,
F_4 ( V_51 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) ) {
V_53 = F_38 ( F_39 ( V_10 -> V_11 ) ) ;
if ( F_40 ( V_53 ) &&
! F_41 ( V_13 -> V_15 ) ) {
F_33 ( L_5 ) ;
return - V_37 ;
}
if ( ! ( V_13 -> V_15 & V_56 ) &&
( ( ( V_10 -> V_57 >> 16 ) != V_10 -> V_58 ) ||
( ( V_10 -> V_59 >> 16 ) != V_10 -> V_60 ) ) ) {
F_33 ( L_6 ,
V_10 -> V_57 >> 16 , V_10 -> V_59 >> 16 ,
V_10 -> V_58 , V_10 -> V_60 ) ;
return - V_37 ;
}
V_55 = ! ! ( V_10 -> V_61 & V_21 ) ;
V_54 = ! ! ( V_10 -> V_61 & V_22 ) ;
if ( ( V_54 && ! ( V_13 -> V_15 & V_17 ) ) ||
( V_55 && ! ( V_13 -> V_15 & V_16 ) ) ) {
F_33 ( L_7 ) ;
return - V_37 ;
}
}
if ( F_4 ( V_10 ) && F_4 ( V_51 ) ) {
bool V_62 = false ;
if ( V_10 -> V_11 -> V_63 != V_51 -> V_11 -> V_63 ) {
F_33 ( L_8 , V_13 -> T_1 ) ;
V_62 = true ;
}
if ( V_10 -> V_57 != V_51 -> V_57 ) {
F_33 ( L_9 , V_13 -> T_1 ) ;
V_62 = true ;
}
if ( F_18 ( V_51 ) -> V_47 ) {
F_33 ( L_10 , V_13 -> T_1 ) ;
V_62 = true ;
}
if ( V_62 ) {
struct V_64 * V_65 =
F_42 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_65 -> V_46 = true ;
F_18 ( V_10 ) -> V_46 = true ;
}
} else {
F_18 ( V_10 ) -> V_46 = true ;
}
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_9 * V_51 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_33 ( L_11 , V_13 -> T_1 ) ;
if ( ! F_4 ( V_10 ) ) {
F_18 ( V_10 ) -> V_47 = true ;
} else if ( F_18 ( V_10 ) -> V_46 ) {
int V_35 ;
F_18 ( V_10 ) -> V_47 = true ;
V_35 = F_44 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_66 , V_10 -> V_67 ,
V_10 -> V_58 , V_10 -> V_60 ,
V_10 -> V_68 , V_10 -> V_69 ,
V_10 -> V_57 , V_10 -> V_59 ) ;
F_28 ( V_35 < 0 ) ;
} else {
unsigned long V_70 ;
F_45 ( & V_13 -> V_71 , V_70 ) ;
F_46 ( V_3 , V_10 -> V_11 ) ;
F_47 ( & V_13 -> V_71 , V_70 ) ;
}
}
static void F_46 ( struct V_2 * V_3 ,
struct V_49 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_72 V_73 = V_13 -> V_73 ;
F_48 ( V_1 , F_49 ( V_73 ) ,
F_50 ( V_11 -> V_74 [ 0 ] ) |
F_51 ( V_11 -> V_74 [ 1 ] ) ) ;
F_48 ( V_1 , F_52 ( V_73 ) ,
F_53 ( V_11 -> V_74 [ 2 ] ) |
F_54 ( V_11 -> V_74 [ 3 ] ) ) ;
F_48 ( V_1 , F_55 ( V_73 ) ,
F_56 ( V_11 , V_1 -> V_50 , 0 ) ) ;
F_48 ( V_1 , F_57 ( V_73 ) ,
F_56 ( V_11 , V_1 -> V_50 , 1 ) ) ;
F_48 ( V_1 , F_58 ( V_73 ) ,
F_56 ( V_11 , V_1 -> V_50 , 2 ) ) ;
F_48 ( V_1 , F_59 ( V_73 ) ,
F_56 ( V_11 , V_1 -> V_50 , 3 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_60 ( struct V_1 * V_1 , enum V_72 V_73 )
{
T_8 V_75 = F_61 ( V_1 , F_62 ( V_73 ) ) &
~ V_76 ;
F_48 ( V_1 , F_62 ( V_73 ) , V_75 ) ;
}
static void F_63 ( struct V_1 * V_1 , enum V_72 V_73 ,
struct V_77 * V_78 )
{
T_8 V_79 , V_80 = 0 ;
T_8 * V_81 ;
if ( F_64 ( ! V_78 ) )
return;
if ( ( V_78 -> type == V_82 ) || ( V_83 == V_78 -> type ) )
V_80 |= F_65 ( V_84 ) ;
if ( ( V_78 -> type == V_85 ) || ( V_83 == V_78 -> type ) )
V_80 |= F_66 ( V_84 ) ;
V_80 |= V_76 ;
F_48 ( V_1 , F_62 ( V_73 ) , V_80 ) ;
V_81 = V_78 -> V_81 ;
F_48 ( V_1 , F_67 ( V_73 ) ,
F_68 ( V_81 [ 0 ] ) |
F_69 ( V_81 [ 1 ] ) ) ;
F_48 ( V_1 , F_70 ( V_73 ) ,
F_71 ( V_81 [ 2 ] ) |
F_72 ( V_81 [ 3 ] ) ) ;
F_48 ( V_1 , F_73 ( V_73 ) ,
F_74 ( V_81 [ 4 ] ) |
F_75 ( V_81 [ 5 ] ) ) ;
F_48 ( V_1 , F_76 ( V_73 ) ,
F_77 ( V_81 [ 6 ] ) |
F_78 ( V_81 [ 7 ] ) ) ;
F_48 ( V_1 , F_79 ( V_73 ) ,
F_80 ( V_81 [ 8 ] ) ) ;
for ( V_79 = 0 ; V_79 < F_81 ( V_78 -> V_86 ) ; V_79 ++ ) {
T_8 * V_87 = V_78 -> V_87 ;
T_8 * V_88 = V_78 -> V_88 ;
F_48 ( V_1 , F_82 ( V_73 , V_79 ) ,
F_83 ( V_87 [ 2 * V_79 + 1 ] ) |
F_84 ( V_87 [ 2 * V_79 ] ) ) ;
F_48 ( V_1 , F_85 ( V_73 , V_79 ) ,
F_86 ( V_88 [ 2 * V_79 + 1 ] ) |
F_87 ( V_88 [ 2 * V_79 ] ) ) ;
F_48 ( V_1 , F_88 ( V_73 , V_79 ) ,
F_89 ( V_78 -> V_86 [ V_79 ] ) ) ;
F_48 ( V_1 , F_90 ( V_73 , V_79 ) ,
F_91 ( V_78 -> V_89 [ V_79 ] ) ) ;
}
}
static int F_92 ( T_8 V_90 , T_8 V_91 , T_8 * V_92 )
{
T_8 V_93 ;
if ( V_90 == 0 || V_91 == 0 )
return - V_37 ;
if ( V_90 > ( V_91 * V_94 ) )
return - V_95 ;
V_93 = 1 << V_96 ;
* V_92 = F_93 ( V_93 , V_90 , V_91 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 ,
T_8 V_63 , T_8 V_90 , T_8 V_97 ,
T_8 V_98 [ V_99 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_100 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_101 ;
unsigned int V_102 ;
int V_35 ;
V_35 = F_92 ( V_90 , V_97 , & V_101 ) ;
if ( V_35 ) {
F_20 ( V_6 , L_12 , V_90 , V_97 , V_35 ) ;
return V_35 ;
}
V_102 = F_95 ( V_63 ) ;
V_98 [ V_103 ] = V_101 ;
V_98 [ V_104 ] = V_101 ;
V_98 [ V_105 ] = V_101 / V_102 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 ,
T_8 V_63 , T_8 V_90 , T_8 V_97 ,
T_8 V_106 [ V_99 ] )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_100 * V_6 = V_1 -> V_6 -> V_6 ;
T_8 V_107 ;
unsigned int V_108 ;
int V_35 ;
V_35 = F_92 ( V_90 , V_97 , & V_107 ) ;
if ( V_35 ) {
F_20 ( V_6 , L_13 , V_90 , V_97 , V_35 ) ;
return V_35 ;
}
V_108 = F_97 ( V_63 ) ;
V_106 [ V_103 ] = V_107 ;
V_106 [ V_104 ] = V_107 ;
V_106 [ V_105 ] = V_107 / V_108 ;
return 0 ;
}
static T_8 F_98 ( const struct V_52 * V_53 ,
T_8 V_90 , T_8 V_91 , bool V_109 )
{
bool V_110 = V_53 -> V_111 ? true : ( V_90 != V_91 ) ;
T_8 V_112 , V_113 = V_53 -> V_23 . V_63 ;
T_8 V_114 , V_115 ;
bool V_116 = V_53 -> V_111 ;
if ( ! V_110 )
return 0 ;
if ( V_116 ) {
V_112 = V_109 ? F_95 ( V_113 ) :
F_97 ( V_113 ) ;
V_115 = ( ( V_90 / V_112 ) <= V_91 ) ?
V_117 : V_118 ;
}
V_114 = ( V_90 <= V_91 ) ? V_117 : V_118 ;
if ( V_109 )
return V_119 |
F_99 ( V_114 ) |
F_100 ( V_114 ) |
F_101 ( V_116 , F_102 ( V_115 ) ) ;
else
return V_120 |
F_103 ( V_114 ) |
F_104 ( V_114 ) |
F_101 ( V_116 , F_105 ( V_115 ) ) ;
}
static void F_106 ( const struct V_52 * V_53 ,
T_8 V_90 , T_8 V_91 , T_8 V_121 [ 2 ] ,
int V_122 [ V_99 ] , int V_123 [ V_99 ] ,
bool V_109 )
{
bool V_110 = V_53 -> V_111 ? true : ( V_90 != V_91 ) ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_99 ; V_79 ++ ) {
V_122 [ V_79 ] = 0 ;
V_123 [ V_79 ] = V_110 ? 1 : 0 ;
}
}
static void F_107 ( struct V_1 * V_1 , enum V_72 V_73 ,
const struct V_52 * V_53 ,
T_8 V_57 , int V_124 [ V_99 ] , int V_125 [ V_99 ] ,
T_8 V_59 , int V_126 [ V_99 ] , int V_127 [ V_99 ] )
{
T_8 V_113 = V_53 -> V_23 . V_63 ;
T_8 V_128 , V_129 , V_130 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_99 ; V_79 ++ ) {
T_8 V_131 = V_57 ;
T_8 V_132 = V_59 ;
if ( V_53 -> V_111 && V_79 == V_105 ) {
V_131 /= F_95 ( V_113 ) ;
V_132 /= F_97 ( V_113 ) ;
}
V_128 = ( V_124 [ V_79 ] >= 0 ) ?
F_108 ( V_124 [ V_79 ] ) :
F_109 ( V_124 [ V_79 ] ) ;
V_128 |= ( V_125 [ V_79 ] >= 0 ) ?
F_110 ( V_125 [ V_79 ] ) :
F_111 ( V_125 [ V_79 ] ) ;
V_129 = ( V_126 [ V_79 ] >= 0 ) ?
F_112 ( V_126 [ V_79 ] ) :
F_113 ( V_126 [ V_79 ] ) ;
V_129 |= ( V_127 [ V_79 ] >= 0 ) ?
F_114 ( V_127 [ V_79 ] ) :
F_115 ( V_127 [ V_79 ] ) ;
V_130 = F_116 ( V_131 +
V_124 [ V_79 ] + V_125 [ V_79 ] ) ;
V_130 |= F_117 ( V_132 +
V_126 [ V_79 ] + V_127 [ V_79 ] ) ;
F_48 ( V_1 , F_118 ( V_73 , V_79 ) , V_128 ) ;
F_48 ( V_1 , F_119 ( V_73 , V_79 ) , V_129 ) ;
F_48 ( V_1 , F_120 ( V_73 , V_79 ) , V_130 ) ;
F_33 ( L_14 , V_79 ,
F_121 ( V_128 , F_108 ) ,
F_121 ( V_128 , F_110 ) ,
F_121 ( V_128 , F_109 ) ,
F_121 ( V_128 , F_111 ) ,
F_121 ( V_130 , F_116 ) ) ;
F_33 ( L_15 , V_79 ,
F_121 ( V_129 , F_112 ) ,
F_121 ( V_129 , F_114 ) ,
F_121 ( V_129 , F_113 ) ,
F_121 ( V_129 , F_115 ) ,
F_121 ( V_130 , F_117 ) ) ;
}
}
static int F_44 ( struct V_2 * V_3 ,
struct V_133 * V_12 , struct V_49 * V_11 ,
int V_66 , int V_67 ,
unsigned int V_58 , unsigned int V_60 ,
T_8 V_68 , T_8 V_69 ,
T_8 V_57 , T_8 V_59 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_34 = V_3 -> V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_72 V_73 = V_13 -> V_73 ;
const struct V_52 * V_53 ;
T_8 V_134 , V_135 = 0 ;
T_8 V_101 [ V_99 ] = { 0 ,} , V_107 [ V_99 ] = { 0 ,} ;
bool V_136 = V_13 -> V_15 & V_137 ;
int V_124 [ V_99 ] , V_125 [ V_99 ] ;
int V_126 [ V_99 ] , V_127 [ V_99 ] ;
T_8 V_138 = 0 , V_139 = 0 ;
T_8 V_140 ;
bool V_54 , V_55 ;
unsigned long V_70 ;
int V_35 ;
V_134 = F_122 ( V_11 -> V_63 ) ;
if ( F_28 ( V_134 > F_123 ( V_73 ) ) )
return - V_37 ;
V_53 = F_38 ( F_39 ( V_11 ) ) ;
V_140 = V_53 -> V_23 . V_63 ;
V_68 = V_68 >> 16 ;
V_69 = V_69 >> 16 ;
V_57 = V_57 >> 16 ;
V_59 = V_59 >> 16 ;
F_33 ( L_16 , V_13 -> T_1 ,
V_11 -> V_23 . V_50 , V_68 , V_69 , V_57 , V_59 ,
V_12 -> V_23 . V_50 , V_66 , V_67 , V_58 , V_60 ) ;
if ( V_1 -> V_141 ) {
V_35 = F_124 ( V_1 -> V_141 ,
V_13 -> V_73 , V_53 , V_57 , false ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1 -> V_141 )
F_125 ( V_1 -> V_141 , V_73 ) ;
V_35 = F_94 ( V_3 , V_140 , V_57 , V_58 , V_101 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_96 ( V_3 , V_140 , V_59 , V_60 , V_107 ) ;
if ( V_35 )
return V_35 ;
if ( V_13 -> V_15 & V_137 ) {
F_106 ( V_53 , V_57 , V_58 , V_101 ,
V_124 , V_125 , true ) ;
F_106 ( V_53 , V_59 , V_60 , V_107 ,
V_126 , V_127 , false ) ;
}
V_135 |= F_98 ( V_53 , V_57 , V_58 , true ) ;
V_135 |= F_98 ( V_53 , V_59 , V_60 , false ) ;
F_33 ( L_17 , V_135 ) ;
V_55 = ! ! ( V_34 -> V_61 & V_21 ) ;
V_54 = ! ! ( V_34 -> V_61 & V_22 ) ;
F_45 ( & V_13 -> V_71 , V_70 ) ;
F_48 ( V_1 , F_126 ( V_73 ) ,
F_127 ( V_11 -> V_142 ) |
F_128 ( V_11 -> V_143 ) ) ;
F_48 ( V_1 , F_129 ( V_73 ) ,
F_130 ( V_57 ) |
F_131 ( V_59 ) ) ;
F_48 ( V_1 , F_132 ( V_73 ) ,
F_133 ( V_68 ) |
F_134 ( V_69 ) ) ;
F_48 ( V_1 , F_135 ( V_73 ) ,
F_136 ( V_58 ) |
F_137 ( V_60 ) ) ;
F_48 ( V_1 , F_138 ( V_73 ) ,
F_139 ( V_66 ) |
F_140 ( V_67 ) ) ;
F_48 ( V_1 , F_141 ( V_73 ) ,
F_142 ( V_53 -> V_144 ) |
F_143 ( V_53 -> V_145 ) |
F_144 ( V_53 -> V_146 ) |
F_145 ( V_53 -> V_147 ) |
F_101 ( V_53 -> V_148 , V_149 ) |
F_146 ( V_53 -> V_150 - 1 ) |
F_147 ( V_53 -> V_151 - 1 ) |
F_101 ( V_53 -> V_152 , V_153 ) |
F_148 ( V_53 -> V_154 ) |
F_149 ( V_53 -> V_155 ) ) ;
F_48 ( V_1 , F_150 ( V_73 ) ,
F_151 ( V_53 -> V_156 [ 0 ] ) |
F_152 ( V_53 -> V_156 [ 1 ] ) |
F_153 ( V_53 -> V_156 [ 2 ] ) |
F_154 ( V_53 -> V_156 [ 3 ] ) ) ;
F_48 ( V_1 , F_155 ( V_73 ) ,
( V_55 ? V_157 : 0 ) |
( V_54 ? V_158 : 0 ) |
F_101 ( V_136 , V_159 ) |
F_156 ( V_160 ) ) ;
F_48 ( V_1 , F_157 ( V_73 ) , 0 ) ;
if ( V_13 -> V_15 & V_137 )
F_107 ( V_1 , V_73 , V_53 ,
V_57 , V_124 , V_125 ,
V_59 , V_126 , V_127 ) ;
if ( V_13 -> V_15 & V_56 ) {
F_48 ( V_1 , F_158 ( V_73 ) ,
V_101 [ V_103 ] ) ;
F_48 ( V_1 , F_159 ( V_73 ) ,
V_107 [ V_103 ] ) ;
F_48 ( V_1 , F_160 ( V_73 ) ,
V_101 [ V_105 ] ) ;
F_48 ( V_1 , F_161 ( V_73 ) ,
V_107 [ V_105 ] ) ;
F_48 ( V_1 , F_162 ( V_73 ) ,
F_163 ( V_139 ) |
F_164 ( V_138 ) ) ;
F_48 ( V_1 , F_165 ( V_73 ) , V_135 ) ;
}
if ( V_13 -> V_15 & V_161 ) {
if ( F_40 ( V_53 ) )
F_63 ( V_1 , V_73 ,
F_166 ( V_82 ) ) ;
else
F_60 ( V_1 , V_73 ) ;
}
F_46 ( V_3 , V_11 ) ;
F_47 ( & V_13 -> V_71 , V_70 ) ;
return V_35 ;
}
void F_167 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_72 V_73 = V_13 -> V_73 ;
F_33 ( L_18 , V_13 -> T_1 ) ;
if ( V_1 -> V_141 )
F_168 ( V_1 -> V_141 , V_73 ) ;
F_18 ( V_3 -> V_10 ) -> V_47 = false ;
}
enum V_72 F_169 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_73 ;
}
T_8 F_170 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_162 ;
}
void F_171 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_72 V_73 = V_13 -> V_73 ;
if ( ! F_4 ( V_3 -> V_10 ) && V_1 -> V_141 ) {
F_33 ( L_19 , V_13 -> T_1 ) ;
F_172 ( V_1 -> V_141 , V_73 ) ;
}
}
struct V_2 * F_173 ( struct V_14 * V_6 ,
enum V_72 V_73 , bool V_163 , T_8 V_164 ,
T_8 V_15 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_35 ;
enum V_165 type ;
V_13 = F_25 ( sizeof( * V_13 ) , V_40 ) ;
if ( ! V_13 ) {
V_35 = - V_166 ;
goto V_167;
}
V_3 = & V_13 -> V_23 ;
V_13 -> V_73 = V_73 ;
V_13 -> T_1 = F_174 ( V_73 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_168 = F_175 ( V_13 -> V_169 ,
F_81 ( V_13 -> V_169 ) ,
! F_41 ( V_13 -> V_15 ) ) ;
V_13 -> V_162 = F_176 ( V_73 ) ;
V_13 -> V_164 = V_164 ;
F_177 ( & V_13 -> V_71 ) ;
type = V_163 ? V_43 : V_170 ;
V_35 = F_178 ( V_6 , V_3 , 0xff , & V_171 ,
V_13 -> V_169 , V_13 -> V_168 ,
type , NULL ) ;
if ( V_35 )
goto V_167;
F_179 ( V_3 , & V_172 ) ;
F_13 ( V_3 , & V_3 -> V_23 ) ;
return V_3 ;
V_167:
if ( V_3 )
F_5 ( V_3 ) ;
return F_180 ( V_35 ) ;
}
