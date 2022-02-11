static T_1 F_1 ( T_2 V_1 )
{
if ( V_1 < V_2 )
V_1 = V_2 ;
return ( V_1 - V_2 ) / V_3 ;
}
static T_1 F_2 ( T_2 V_4 )
{
return ( V_4 - V_5 ) / V_6 ;
}
static inline struct V_7 * F_3 (
struct V_8 * V_9 )
{
return F_4 ( V_9 , struct V_7 , V_9 ) ;
}
static inline struct V_10 * F_5 (
struct V_7 * V_11 )
{
return F_4 ( V_11 , struct V_10 ,
V_12 [ V_11 -> V_13 ] ) ;
}
static inline T_1 F_6 ( T_2 V_14 )
{
return ( ( V_14 - V_15 ) / V_16 ) << 2 ;
}
static inline T_1 F_7 ( T_2 V_14 )
{
return ( V_14 - V_17 ) / V_18 + V_19 ;
}
static inline bool F_8 ( struct V_10 * V_20 ,
int V_13 )
{
T_1 V_21 = ( V_13 == V_22 ) ? V_23 : V_24 ;
return V_20 -> V_25 & V_21 ;
}
static int F_9 ( struct V_10 * V_20 , T_1 V_26 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
int V_29 , V_30 = 0 , V_31 ;
for ( V_31 = V_22 ; V_31 <= V_32 ; ++ V_31 ) {
if ( V_26 & F_10 ( V_31 ) )
V_30 |= V_33 << F_11 ( V_31 ) ;
if ( V_26 & F_12 ( V_31 ) ) {
V_30 |= V_33 << F_13 ( V_31 ) ;
} else if ( V_26 & F_14 ( V_31 ) ) {
V_30 |= V_34 << F_13 ( V_31 ) ;
V_30 |= V_35 << F_11 ( V_31 ) ;
}
}
if ( V_26 & ~ ( F_10 ( V_22 ) | F_10 ( V_32 ) ) ) {
V_29 = F_15 ( V_28 , V_36 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return F_15 ( V_28 , V_36 , V_30 ) ;
}
static int F_16 ( struct V_10 * V_20 , T_1 V_26 )
{
T_1 V_37 ;
int V_31 , V_29 ;
if ( V_20 -> V_38 )
V_26 |= ( V_26 << 1 ) ;
for ( V_31 = V_22 ; V_31 <= V_32 ; ++ V_31 )
if ( V_26 & F_14 ( V_31 ) )
V_20 -> V_39 &= ( ~ F_10 ( V_31 ) & ~ F_12 ( V_31 ) ) ;
V_37 = V_26 | V_20 -> V_39 ;
V_37 &= V_20 -> V_40 ;
if ( V_37 ^ V_20 -> V_39 )
V_20 -> V_39 = V_37 ;
else
return 0 ;
V_29 = F_9 ( V_20 , V_20 -> V_39 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_26 & V_41 )
V_20 -> V_39 &= ~ V_26 ;
return V_29 ;
}
static int F_17 ( struct V_10 * V_20 ,
T_1 V_26 )
{
if ( V_20 -> V_38 )
V_26 |= ( V_26 << 1 ) ;
V_20 -> V_39 &= ~ V_26 ;
return F_9 ( V_20 , V_20 -> V_39 ) ;
}
static void F_18 ( struct V_10 * V_20 ,
int V_13 , enum V_42 V_26 )
{
if ( V_26 == V_43 )
V_20 -> V_40 |= ( F_12 ( V_13 ) |
F_14 ( V_13 ) ) ;
else
V_20 -> V_40 |= F_10 ( V_13 ) ;
}
static void F_19 ( struct V_10 * V_20 ,
int V_13 , enum V_42 V_26 ,
T_2 V_44 , T_2 V_45 [ 2 ] , T_2 V_46 [ 2 ] )
{
if ( ! V_20 -> V_38 ) {
V_46 [ V_13 ] = V_44 ;
F_18 ( V_20 , V_13 , V_26 ) ;
return;
}
V_46 [ V_22 ] = F_20 ( V_44 , V_45 [ V_22 ] ) ;
V_46 [ V_32 ] = V_44 - V_46 [ V_22 ] ;
if ( V_26 == V_43 )
V_20 -> V_40 &= ~ V_41 ;
else
V_20 -> V_40 &= ~ V_47 ;
F_18 ( V_20 , V_22 , V_26 ) ;
if ( V_46 [ V_32 ] )
F_18 ( V_20 , V_32 , V_26 ) ;
}
static int F_21 ( struct V_10 * V_20 ,
int V_13 , T_2 V_44 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
T_1 V_48 = 0 , V_49 = 0 ;
T_2 V_46 [ 2 ] ;
F_19 ( V_20 , V_13 , V_50 , V_44 ,
V_20 -> V_51 , V_46 ) ;
if ( V_13 == V_22 || V_20 -> V_38 ) {
V_48 = F_1 ( V_46 [ V_22 ] ) ;
V_20 -> V_52 &= F_22 ( V_53 ) ;
}
if ( V_13 == V_32 || V_20 -> V_38 ) {
V_49 = F_1 ( V_46 [ V_32 ] ) ;
V_20 -> V_52 &= F_22 ( V_54 ) ;
}
V_20 -> V_52 |= ( ( V_48 << V_54 ) |
( V_49 << V_53 ) ) ;
return F_15 ( V_28 , V_55 ,
V_20 -> V_52 ) ;
}
static int F_23 ( struct V_10 * V_20 ,
int V_13 ,
T_2 V_44 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
T_1 V_48 , V_49 ;
T_2 V_46 [ 2 ] ;
int V_29 = - V_56 ;
F_19 ( V_20 , V_13 , V_43 , V_44 ,
V_20 -> V_57 , V_46 ) ;
if ( V_13 == V_22 || V_20 -> V_38 ) {
V_48 = F_1 ( V_46 [ V_22 ] ) ;
V_29 = F_15 ( V_28 , V_58 ,
V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_13 == V_32 || V_20 -> V_38 ) {
V_49 = F_1 ( V_46 [ V_32 ] ) ;
V_29 = F_15 ( V_28 , V_59 ,
V_49 ) ;
}
return V_29 ;
}
static int F_24 ( struct V_10 * V_20 , T_2 V_60 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
T_1 V_30 ;
int V_29 ;
V_30 = F_2 ( V_60 ) | V_61 ;
V_29 = F_15 ( V_28 , V_62 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_20 -> V_63 = V_60 ;
return 0 ;
}
static int F_25 ( struct V_10 * V_20 ,
bool * V_64 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
unsigned int V_30 ;
int V_29 ;
V_29 = F_26 ( V_28 , V_65 , & V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
* V_64 = V_30 & V_66 ;
return V_29 ;
}
static int F_27 ( struct V_7 * V_11 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
struct V_27 * V_28 = V_20 -> V_27 ;
unsigned int V_30 ;
T_1 V_67 , V_68 ;
int V_29 ;
V_11 -> V_69 = 0 ;
if ( V_20 -> V_38 ) {
V_67 = V_70 | V_71 ;
V_68 = V_72 |
V_73 ;
} else {
V_67 = ( V_11 -> V_13 == V_22 ) ?
V_70 :
V_71 ;
V_68 = ( V_11 -> V_13 == V_22 ) ?
V_72 :
V_73 ;
}
V_29 = F_26 ( V_28 , V_74 , & V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_30 & V_67 )
V_11 -> V_69 |= V_75 ;
if ( V_30 & V_68 )
V_11 -> V_69 |= V_76 ;
if ( V_30 & V_77 )
V_11 -> V_69 |= V_78 ;
return 0 ;
}
static int F_28 ( struct V_10 * V_20 ,
struct V_79 * V_80 )
{
struct V_27 * V_28 = V_20 -> V_27 ;
int V_31 , V_81 , V_82 , V_29 ;
T_2 V_83 [ 2 ] ;
T_1 V_30 ;
if ( V_20 -> V_38 ) {
V_81 = V_22 ;
V_82 = V_22 ;
V_83 [ V_22 ] = V_80 -> V_57 [ V_22 ] +
V_80 -> V_57 [ V_32 ] ;
} else {
V_81 = F_8 ( V_20 , V_22 ) ? V_22 : V_32 ;
V_82 = F_8 ( V_20 , V_32 ) ? V_32 : V_22 ;
V_83 [ V_22 ] = V_80 -> V_57 [ V_22 ] ;
V_83 [ V_32 ] = V_80 -> V_57 [ V_32 ] ;
}
for ( V_31 = V_81 ; V_31 <= V_82 ; ++ V_31 ) {
V_29 = F_23 ( V_20 , V_31 ,
V_83 [ V_31 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_30 = V_84 | V_85 ;
V_29 = F_15 ( V_28 , V_86 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_80 -> V_87 > 0 )
V_30 = F_6 ( V_80 -> V_87 ) |
V_88 ;
else
V_30 = 0 ;
V_29 = F_15 ( V_28 , V_89 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_15 ( V_28 , V_90 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_80 -> V_91 == V_92 )
V_30 = V_93 ;
else
V_30 = V_80 -> V_91 | V_80 -> V_91 << 1 ;
if ( F_8 ( V_20 , V_22 ) && F_8 ( V_20 , V_32 ) )
V_30 |= V_94 ;
V_29 = F_15 ( V_28 , V_95 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_30 = F_7 ( V_80 -> V_96 ) ;
V_29 = F_15 ( V_28 , V_97 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_9 ( V_20 , V_98 ) ;
}
static int F_29 ( struct V_10 * V_20 ,
int V_13 , enum V_99 V_100 )
{
int V_29 ;
F_30 ( & V_20 -> V_101 ) ;
if ( V_100 == 0 ) {
V_29 = F_17 ( V_20 , F_10 ( V_13 ) ) ;
if ( V_29 < 0 )
F_31 ( & V_20 -> V_102 -> V_103 ,
L_1 ,
V_29 ) ;
goto V_104;
}
V_29 = F_21 ( V_20 , V_13 , V_100 * V_105 ) ;
if ( V_29 < 0 ) {
F_31 ( & V_20 -> V_102 -> V_103 ,
L_2 ,
V_29 ) ;
goto V_104;
}
V_29 = F_16 ( V_20 , F_10 ( V_13 ) ) ;
if ( V_29 < 0 )
F_31 ( & V_20 -> V_102 -> V_103 ,
L_3 ,
V_29 ) ;
V_104:
F_32 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static void F_33 (
struct V_106 * V_107 )
{
struct V_7 * V_11 =
F_4 ( V_107 , struct V_7 ,
V_108 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
F_29 ( V_20 , V_11 -> V_13 ,
V_11 -> V_109 ) ;
}
static int F_34 (
struct V_110 * V_111 ,
enum V_99 V_100 )
{
struct V_8 * V_9 = F_35 ( V_111 ) ;
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
return F_29 ( V_20 , V_11 -> V_13 , V_100 ) ;
}
static void F_36 (
struct V_110 * V_111 ,
enum V_99 V_100 )
{
struct V_8 * V_9 = F_35 ( V_111 ) ;
struct V_7 * V_11 = F_3 ( V_9 ) ;
V_11 -> V_109 = V_100 ;
F_37 ( & V_11 -> V_108 ) ;
}
static int F_38 (
struct V_8 * V_9 ,
T_2 V_112 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_29 ;
F_30 ( & V_20 -> V_101 ) ;
V_29 = F_23 ( V_20 , V_11 -> V_13 , V_112 ) ;
F_32 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static int F_39 (
struct V_8 * V_9 ,
bool V_64 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
int V_29 ;
F_30 ( & V_20 -> V_101 ) ;
if ( ! V_64 ) {
V_29 = F_17 ( V_20 , F_12 ( V_13 ) ) ;
goto V_104;
}
if ( V_11 -> V_113 != V_20 -> V_63 ) {
V_29 = F_24 ( V_20 , V_11 -> V_113 ) ;
if ( V_29 < 0 )
goto V_104;
}
V_20 -> V_114 = V_13 ;
V_29 = F_16 ( V_20 , F_12 ( V_13 ) ) ;
if ( V_29 < 0 )
goto V_104;
V_29 = F_27 ( V_11 ) ;
V_104:
F_32 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static int F_40 (
struct V_8 * V_9 ,
T_2 * V_115 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
* V_115 = V_11 -> V_69 ;
return 0 ;
}
static int F_41 (
struct V_8 * V_9 ,
bool * V_64 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_29 ;
if ( ! V_64 )
return - V_56 ;
F_30 ( & V_20 -> V_101 ) ;
V_29 = F_25 ( V_20 , V_64 ) ;
* V_64 = ! ! ( * V_64 && ( V_20 -> V_114 == V_11 -> V_13 ) ) ;
F_32 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static int F_42 (
struct V_8 * V_9 ,
T_2 V_116 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
F_30 ( & V_20 -> V_101 ) ;
V_11 -> V_113 = V_116 ;
F_32 ( & V_20 -> V_101 ) ;
return 0 ;
}
static int F_43 ( struct V_10 * V_20 ,
struct V_79 * V_117 ,
struct V_118 * * V_119 )
{
struct V_120 * V_103 = & V_20 -> V_102 -> V_103 ;
struct V_7 * V_12 = V_20 -> V_12 ;
struct V_118 * V_121 = V_103 -> V_122 , * V_123 ;
struct V_124 * V_125 ;
T_2 V_126 [ 2 ] ;
int V_31 , V_29 , V_13 ;
F_44 ( V_121 , L_4 , & V_117 -> V_91 ) ;
F_44 ( V_121 , L_5 , & V_117 -> V_96 ) ;
F_44 ( V_121 , L_6 , & V_117 -> V_87 ) ;
F_45 (node, child_node) {
V_125 = F_46 ( V_123 , L_7 , NULL ) ;
if ( V_125 ) {
const T_3 * V_127 = NULL ;
for ( V_31 = 0 ; V_31 < F_47 ( V_126 ) ; ++ V_31 ) {
V_127 = F_48 ( V_125 , V_127 ,
& V_126 [ V_31 ] ) ;
if ( ! V_127 )
break;
}
} else {
F_49 ( V_103 ,
L_8 ) ;
F_50 ( V_123 ) ;
return - V_56 ;
}
if ( V_31 == 2 ) {
V_13 = V_22 ;
V_20 -> V_25 = V_23 | V_24 ;
} else if ( V_126 [ 0 ] == V_22 ) {
V_13 = V_22 ;
V_20 -> V_25 |= V_23 ;
} else if ( V_126 [ 0 ] == V_32 ) {
V_13 = V_32 ;
V_20 -> V_25 |= V_24 ;
} else {
F_49 ( V_103 ,
L_9 ) ;
F_50 ( V_123 ) ;
return - V_56 ;
}
if ( V_119 [ V_13 ] ) {
F_49 ( V_103 ,
L_10 ) ;
return - V_56 ;
}
V_119 [ V_13 ] = V_123 ;
V_12 [ V_13 ] . V_13 = V_13 ;
V_117 -> V_128 [ V_13 ] =
F_51 ( V_123 , L_11 , NULL ) ? :
V_123 -> V_129 ;
V_29 = F_44 ( V_123 , L_12 ,
& V_117 -> V_51 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_117 -> V_51 [ V_13 ] = V_130 ;
F_52 ( V_103 , L_13 ) ;
}
V_29 = F_44 ( V_123 , L_14 ,
& V_117 -> V_57 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_117 -> V_57 [ V_13 ] = V_2 ;
F_52 ( V_103 ,
L_15 ) ;
}
V_29 = F_44 ( V_123 , L_16 ,
& V_117 -> V_131 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_117 -> V_131 [ V_13 ] = V_5 ;
F_52 ( V_103 ,
L_17 ) ;
}
if ( ++ V_117 -> V_132 == 2 ||
( F_8 ( V_20 , V_22 ) &&
F_8 ( V_20 , V_32 ) ) ) {
F_50 ( V_123 ) ;
break;
}
}
if ( V_117 -> V_132 == 0 ) {
F_49 ( V_103 , L_18 ) ;
return - V_56 ;
}
return 0 ;
}
static void F_53 ( T_2 * V_30 , T_2 F_20 , T_2 V_133 , T_2 V_134 )
{
* V_30 = F_54 ( * V_30 , F_20 , V_133 ) ;
if ( V_134 > 1 )
* V_30 = ( * V_30 - F_20 ) / V_134 * V_134 + F_20 ;
}
static void F_55 ( struct V_10 * V_20 ,
T_2 * V_46 , T_2 F_20 , T_2 V_133 , T_2 V_134 )
{
int V_31 ;
if ( V_20 -> V_38 ) {
if ( V_46 [ V_22 ] > F_20 ) {
V_46 [ V_22 ] /= 2 ;
V_46 [ V_32 ] = V_46 [ V_22 ] ;
} else {
V_46 [ V_22 ] = F_20 ;
V_46 [ V_32 ] = 0 ;
return;
}
}
for ( V_31 = V_22 ; V_31 <= V_32 ; ++ V_31 )
if ( F_8 ( V_20 , V_31 ) )
F_53 ( & V_46 [ V_31 ] , F_20 , V_133 , V_134 ) ;
else
V_46 [ V_31 ] = 0 ;
}
static void F_56 ( struct V_10 * V_20 ,
struct V_79 * V_117 )
{
T_2 V_135 = V_117 -> V_91 ? V_136 :
V_137 ;
int V_31 ;
if ( V_117 -> V_132 == 1 &&
F_8 ( V_20 , V_22 ) && F_8 ( V_20 , V_32 ) )
V_20 -> V_38 = true ;
V_117 -> V_91 = F_54 ( V_117 -> V_91 , V_138 ,
V_92 ) ;
if ( ( V_117 -> V_91 == V_138 ) && V_20 -> V_38 )
V_117 -> V_91 = V_92 ;
F_55 ( V_20 , V_117 -> V_51 ,
V_130 , V_139 , V_105 ) ;
F_55 ( V_20 , V_117 -> V_57 ,
V_2 , V_135 , V_3 ) ;
for ( V_31 = 0 ; V_31 < F_47 ( V_117 -> V_131 ) ; ++ V_31 )
F_53 ( & V_117 -> V_131 [ V_31 ] , V_5 ,
V_140 , V_6 ) ;
F_53 ( & V_117 -> V_96 , V_17 , V_141 ,
V_18 ) ;
if ( V_117 -> V_87 )
F_53 ( & V_117 -> V_87 , V_15 ,
V_142 , V_16 ) ;
}
static int F_57 ( struct V_10 * V_20 ,
struct V_79 * V_117 ,
struct V_118 * * V_119 )
{
int V_29 ;
V_29 = F_43 ( V_20 , V_117 , V_119 ) ;
if ( V_29 < 0 )
return V_29 ;
F_56 ( V_20 , V_117 ) ;
memcpy ( V_20 -> V_51 , V_117 -> V_51 ,
sizeof( V_20 -> V_51 ) ) ;
memcpy ( V_20 -> V_57 , V_117 -> V_57 ,
sizeof( V_20 -> V_57 ) ) ;
return 0 ;
}
static void F_58 ( struct V_7 * V_11 ,
struct V_79 * V_80 )
{
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
struct V_143 * V_144 ;
V_144 = & V_9 -> V_112 ;
V_144 -> F_20 = V_2 ;
V_144 -> V_133 = V_20 -> V_38 ?
V_80 -> V_57 [ V_22 ] +
V_80 -> V_57 [ V_32 ] :
V_80 -> V_57 [ V_13 ] ;
V_144 -> V_134 = V_3 ;
V_144 -> V_145 = V_144 -> V_133 ;
V_144 = & V_9 -> V_116 ;
V_144 -> F_20 = V_5 ;
V_144 -> V_133 = V_80 -> V_131 [ V_13 ] ;
V_144 -> V_134 = V_6 ;
V_144 -> V_145 = V_144 -> V_133 ;
}
static int F_59 (
struct V_146 * V_146 ,
bool V_147 )
{
struct V_7 * V_11 =
F_3 ( V_146 -> V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
int V_29 ;
F_30 ( & V_20 -> V_101 ) ;
if ( V_147 )
V_29 = F_16 ( V_20 , F_14 ( V_13 ) ) ;
else
V_29 = F_17 ( V_20 , F_14 ( V_13 ) ) ;
F_32 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static void F_60 ( struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_148 * V_149 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
struct V_120 * V_103 = & V_20 -> V_102 -> V_103 ;
struct V_150 * V_151 = F_61 ( V_103 -> V_152 ) ;
struct V_153 * V_154 = V_151 -> V_154 ;
struct V_143 * V_155 ;
snprintf ( V_149 -> V_156 , sizeof( V_149 -> V_156 ) ,
L_19 , V_11 -> V_9 . V_111 . V_129 ,
F_62 ( V_154 -> V_157 ) , V_154 -> V_158 ) ;
V_155 = & V_149 -> V_159 ;
V_155 -> F_20 = V_130 ;
V_155 -> V_133 = V_11 -> V_9 . V_111 . V_160 * V_105 ;
V_155 -> V_134 = V_105 ;
V_155 -> V_145 = V_155 -> V_133 ;
V_149 -> V_69 = V_75 |
V_76 |
V_78 ;
V_149 -> V_161 = true ;
}
static inline void F_60 (
struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_148 * V_149 )
{
}
static void F_63 ( struct V_7 * V_11 ,
struct V_79 * V_80 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
struct V_8 * V_9 ;
struct V_110 * V_111 ;
V_9 = & V_11 -> V_9 ;
V_9 -> V_162 = & V_163 ;
V_111 = & V_9 -> V_111 ;
V_111 -> V_129 = V_80 -> V_128 [ V_13 ] ;
V_111 -> V_164 = F_36 ;
V_111 -> V_165 = F_34 ;
V_111 -> V_160 = ( V_20 -> V_38 ?
V_80 -> V_51 [ V_22 ] +
V_80 -> V_51 [ V_32 ] :
V_80 -> V_51 [ V_13 ] ) /
V_105 ;
V_111 -> V_166 |= V_167 ;
F_64 ( & V_11 -> V_108 ,
F_33 ) ;
F_58 ( V_11 , V_80 ) ;
V_11 -> V_113 = V_9 -> V_116 . V_145 ;
}
static int F_65 ( struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_118 * V_168 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_120 * V_103 = & V_20 -> V_102 -> V_103 ;
struct V_148 V_149 = {} ;
int V_29 ;
V_29 = F_66 ( V_103 , V_9 ) ;
if ( V_29 < 0 )
return V_29 ;
F_60 ( V_11 , V_80 , & V_149 ) ;
V_11 -> V_146 = F_67 ( V_103 , V_168 , V_9 , NULL ,
& V_169 , & V_149 ) ;
if ( F_68 ( V_11 -> V_146 ) ) {
V_29 = F_69 ( V_11 -> V_146 ) ;
goto V_170;
}
return 0 ;
V_170:
F_70 ( V_9 ) ;
return V_29 ;
}
static int F_71 ( struct V_171 * V_102 )
{
struct V_120 * V_103 = & V_102 -> V_103 ;
struct V_150 * V_151 = F_61 ( V_103 -> V_152 ) ;
struct V_10 * V_20 ;
struct V_7 * V_12 ;
struct V_118 * V_119 [ 2 ] = {} ;
struct V_79 V_80 = {} ;
int V_172 [ 2 ] , V_31 , V_29 ;
V_20 = F_72 ( V_103 , sizeof( * V_20 ) , V_173 ) ;
if ( ! V_20 )
return - V_174 ;
V_20 -> V_102 = V_102 ;
V_20 -> V_27 = V_151 -> V_27 ;
V_20 -> V_40 = V_41 ;
V_12 = V_20 -> V_12 ;
F_73 ( V_102 , V_20 ) ;
V_29 = F_57 ( V_20 , & V_80 , V_119 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_28 ( V_20 , & V_80 ) ;
if ( V_29 < 0 )
return V_29 ;
F_74 ( & V_20 -> V_101 ) ;
V_172 [ V_22 ] =
V_20 -> V_38 || F_8 ( V_20 , V_22 ) ;
V_172 [ V_32 ] =
! V_20 -> V_38 && F_8 ( V_20 , V_32 ) ;
for ( V_31 = V_22 ; V_31 <= V_32 ; ++ V_31 ) {
if ( ! V_172 [ V_31 ] )
continue;
F_63 ( & V_12 [ V_31 ] , & V_80 ) ;
V_29 = F_65 ( & V_12 [ V_31 ] , & V_80 ,
V_119 [ V_31 ] ) ;
if ( V_29 < 0 ) {
if ( V_31 == V_32 )
goto V_175;
else
goto V_176;
}
}
return 0 ;
V_175:
if ( ! V_172 [ V_22 ] )
goto V_176;
F_75 ( V_12 [ V_22 ] . V_146 ) ;
F_70 ( & V_12 [ V_22 ] . V_9 ) ;
V_176:
F_76 ( & V_20 -> V_101 ) ;
return V_29 ;
}
static int F_77 ( struct V_171 * V_102 )
{
struct V_10 * V_20 = F_78 ( V_102 ) ;
struct V_7 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_38 || F_8 ( V_20 , V_22 ) ) {
F_75 ( V_12 [ V_22 ] . V_146 ) ;
F_70 ( & V_12 [ V_22 ] . V_9 ) ;
F_79 ( & V_12 [ V_22 ] . V_108 ) ;
}
if ( ! V_20 -> V_38 && F_8 ( V_20 , V_32 ) ) {
F_75 ( V_12 [ V_32 ] . V_146 ) ;
F_70 ( & V_12 [ V_32 ] . V_9 ) ;
F_79 ( & V_12 [ V_32 ] . V_108 ) ;
}
F_76 ( & V_20 -> V_101 ) ;
return 0 ;
}
