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
static int F_29 ( struct V_99 * V_100 ,
enum V_101 V_102 )
{
struct V_8 * V_9 = F_30 ( V_100 ) ;
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 , V_29 ;
F_31 ( & V_20 -> V_103 ) ;
if ( V_102 == 0 ) {
V_29 = F_17 ( V_20 , F_10 ( V_13 ) ) ;
if ( V_29 < 0 )
F_32 ( & V_20 -> V_104 -> V_105 ,
L_1 ,
V_29 ) ;
goto V_106;
}
V_29 = F_21 ( V_20 , V_13 , V_102 * V_107 ) ;
if ( V_29 < 0 ) {
F_32 ( & V_20 -> V_104 -> V_105 ,
L_2 ,
V_29 ) ;
goto V_106;
}
V_29 = F_16 ( V_20 , F_10 ( V_13 ) ) ;
if ( V_29 < 0 )
F_32 ( & V_20 -> V_104 -> V_105 ,
L_3 ,
V_29 ) ;
V_106:
F_33 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static int F_34 (
struct V_8 * V_9 ,
T_2 V_108 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_29 ;
F_31 ( & V_20 -> V_103 ) ;
V_29 = F_23 ( V_20 , V_11 -> V_13 , V_108 ) ;
F_33 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static int F_35 (
struct V_8 * V_9 ,
bool V_64 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
int V_29 ;
F_31 ( & V_20 -> V_103 ) ;
if ( ! V_64 ) {
V_29 = F_17 ( V_20 , F_12 ( V_13 ) ) ;
goto V_106;
}
if ( V_11 -> V_109 != V_20 -> V_63 ) {
V_29 = F_24 ( V_20 , V_11 -> V_109 ) ;
if ( V_29 < 0 )
goto V_106;
}
V_20 -> V_110 = V_13 ;
V_29 = F_16 ( V_20 , F_12 ( V_13 ) ) ;
if ( V_29 < 0 )
goto V_106;
V_29 = F_27 ( V_11 ) ;
V_106:
F_33 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static int F_36 (
struct V_8 * V_9 ,
T_2 * V_111 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
* V_111 = V_11 -> V_69 ;
return 0 ;
}
static int F_37 (
struct V_8 * V_9 ,
bool * V_64 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_29 ;
if ( ! V_64 )
return - V_56 ;
F_31 ( & V_20 -> V_103 ) ;
V_29 = F_25 ( V_20 , V_64 ) ;
* V_64 = ! ! ( * V_64 && ( V_20 -> V_110 == V_11 -> V_13 ) ) ;
F_33 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static int F_38 (
struct V_8 * V_9 ,
T_2 V_112 )
{
struct V_7 * V_11 = F_3 ( V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
F_31 ( & V_20 -> V_103 ) ;
V_11 -> V_109 = V_112 ;
F_33 ( & V_20 -> V_103 ) ;
return 0 ;
}
static int F_39 ( struct V_10 * V_20 ,
struct V_79 * V_113 ,
struct V_114 * * V_115 )
{
struct V_116 * V_105 = & V_20 -> V_104 -> V_105 ;
struct V_7 * V_12 = V_20 -> V_12 ;
struct V_114 * V_117 = V_105 -> V_118 , * V_119 ;
struct V_120 * V_121 ;
T_2 V_122 [ 2 ] ;
int V_31 , V_29 , V_13 ;
F_40 ( V_117 , L_4 , & V_113 -> V_91 ) ;
F_40 ( V_117 , L_5 , & V_113 -> V_96 ) ;
F_40 ( V_117 , L_6 , & V_113 -> V_87 ) ;
F_41 (node, child_node) {
V_121 = F_42 ( V_119 , L_7 , NULL ) ;
if ( V_121 ) {
const T_3 * V_123 = NULL ;
for ( V_31 = 0 ; V_31 < F_43 ( V_122 ) ; ++ V_31 ) {
V_123 = F_44 ( V_121 , V_123 ,
& V_122 [ V_31 ] ) ;
if ( ! V_123 )
break;
}
} else {
F_45 ( V_105 ,
L_8 ) ;
F_46 ( V_119 ) ;
return - V_56 ;
}
if ( V_31 == 2 ) {
V_13 = V_22 ;
V_20 -> V_25 = V_23 | V_24 ;
} else if ( V_122 [ 0 ] == V_22 ) {
V_13 = V_22 ;
V_20 -> V_25 |= V_23 ;
} else if ( V_122 [ 0 ] == V_32 ) {
V_13 = V_32 ;
V_20 -> V_25 |= V_24 ;
} else {
F_45 ( V_105 ,
L_9 ) ;
F_46 ( V_119 ) ;
return - V_56 ;
}
if ( V_115 [ V_13 ] ) {
F_45 ( V_105 ,
L_10 ) ;
F_46 ( V_119 ) ;
return - V_56 ;
}
V_115 [ V_13 ] = V_119 ;
V_12 [ V_13 ] . V_13 = V_13 ;
V_113 -> V_124 [ V_13 ] =
F_47 ( V_119 , L_11 , NULL ) ? :
V_119 -> V_125 ;
V_29 = F_40 ( V_119 , L_12 ,
& V_113 -> V_51 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_113 -> V_51 [ V_13 ] = V_126 ;
F_48 ( V_105 , L_13 ) ;
}
V_29 = F_40 ( V_119 , L_14 ,
& V_113 -> V_57 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_113 -> V_57 [ V_13 ] = V_2 ;
F_48 ( V_105 ,
L_15 ) ;
}
V_29 = F_40 ( V_119 , L_16 ,
& V_113 -> V_127 [ V_13 ] ) ;
if ( V_29 < 0 ) {
V_113 -> V_127 [ V_13 ] = V_5 ;
F_48 ( V_105 ,
L_17 ) ;
}
if ( ++ V_113 -> V_128 == 2 ||
( F_8 ( V_20 , V_22 ) &&
F_8 ( V_20 , V_32 ) ) ) {
F_46 ( V_119 ) ;
break;
}
}
if ( V_113 -> V_128 == 0 ) {
F_45 ( V_105 , L_18 ) ;
return - V_56 ;
}
return 0 ;
}
static void F_49 ( T_2 * V_30 , T_2 F_20 , T_2 V_129 , T_2 V_130 )
{
* V_30 = F_50 ( * V_30 , F_20 , V_129 ) ;
if ( V_130 > 1 )
* V_30 = ( * V_30 - F_20 ) / V_130 * V_130 + F_20 ;
}
static void F_51 ( struct V_10 * V_20 ,
T_2 * V_46 , T_2 F_20 , T_2 V_129 , T_2 V_130 )
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
F_49 ( & V_46 [ V_31 ] , F_20 , V_129 , V_130 ) ;
else
V_46 [ V_31 ] = 0 ;
}
static void F_52 ( struct V_10 * V_20 ,
struct V_79 * V_113 )
{
T_2 V_131 = V_113 -> V_91 ? V_132 :
V_133 ;
int V_31 ;
if ( V_113 -> V_128 == 1 &&
F_8 ( V_20 , V_22 ) && F_8 ( V_20 , V_32 ) )
V_20 -> V_38 = true ;
V_113 -> V_91 = F_50 ( V_113 -> V_91 , V_134 ,
V_92 ) ;
if ( ( V_113 -> V_91 == V_134 ) && V_20 -> V_38 )
V_113 -> V_91 = V_92 ;
F_51 ( V_20 , V_113 -> V_51 ,
V_126 , V_135 , V_107 ) ;
F_51 ( V_20 , V_113 -> V_57 ,
V_2 , V_131 , V_3 ) ;
for ( V_31 = 0 ; V_31 < F_43 ( V_113 -> V_127 ) ; ++ V_31 )
F_49 ( & V_113 -> V_127 [ V_31 ] , V_5 ,
V_136 , V_6 ) ;
F_49 ( & V_113 -> V_96 , V_17 , V_137 ,
V_18 ) ;
if ( V_113 -> V_87 )
F_49 ( & V_113 -> V_87 , V_15 ,
V_138 , V_16 ) ;
}
static int F_53 ( struct V_10 * V_20 ,
struct V_79 * V_113 ,
struct V_114 * * V_115 )
{
int V_29 ;
V_29 = F_39 ( V_20 , V_113 , V_115 ) ;
if ( V_29 < 0 )
return V_29 ;
F_52 ( V_20 , V_113 ) ;
memcpy ( V_20 -> V_51 , V_113 -> V_51 ,
sizeof( V_20 -> V_51 ) ) ;
memcpy ( V_20 -> V_57 , V_113 -> V_57 ,
sizeof( V_20 -> V_57 ) ) ;
return 0 ;
}
static void F_54 ( struct V_7 * V_11 ,
struct V_79 * V_80 )
{
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
struct V_139 * V_140 ;
V_140 = & V_9 -> V_108 ;
V_140 -> F_20 = V_2 ;
V_140 -> V_129 = V_20 -> V_38 ?
V_80 -> V_57 [ V_22 ] +
V_80 -> V_57 [ V_32 ] :
V_80 -> V_57 [ V_13 ] ;
V_140 -> V_130 = V_3 ;
V_140 -> V_141 = V_140 -> V_129 ;
V_140 = & V_9 -> V_112 ;
V_140 -> F_20 = V_5 ;
V_140 -> V_129 = V_80 -> V_127 [ V_13 ] ;
V_140 -> V_130 = V_6 ;
V_140 -> V_141 = V_140 -> V_129 ;
}
static int F_55 (
struct V_142 * V_142 ,
bool V_143 )
{
struct V_7 * V_11 =
F_3 ( V_142 -> V_9 ) ;
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
int V_29 ;
F_31 ( & V_20 -> V_103 ) ;
if ( V_143 )
V_29 = F_16 ( V_20 , F_14 ( V_13 ) ) ;
else
V_29 = F_17 ( V_20 , F_14 ( V_13 ) ) ;
F_33 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static void F_56 ( struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_144 * V_145 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
struct V_116 * V_105 = & V_20 -> V_104 -> V_105 ;
struct V_146 * V_147 = F_57 ( V_105 -> V_148 ) ;
struct V_149 * V_150 = V_147 -> V_150 ;
struct V_139 * V_151 ;
snprintf ( V_145 -> V_152 , sizeof( V_145 -> V_152 ) ,
L_19 , V_11 -> V_9 . V_100 . V_125 ,
F_58 ( V_150 -> V_153 ) , V_150 -> V_154 ) ;
V_151 = & V_145 -> V_155 ;
V_151 -> F_20 = V_126 ;
V_151 -> V_129 = V_11 -> V_9 . V_100 . V_156 * V_107 ;
V_151 -> V_130 = V_107 ;
V_151 -> V_141 = V_151 -> V_129 ;
V_145 -> V_69 = V_75 |
V_76 |
V_78 ;
V_145 -> V_157 = true ;
}
static inline void F_56 (
struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_144 * V_145 )
{
}
static void F_59 ( struct V_7 * V_11 ,
struct V_79 * V_80 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
int V_13 = V_11 -> V_13 ;
struct V_8 * V_9 ;
struct V_99 * V_100 ;
V_9 = & V_11 -> V_9 ;
V_9 -> V_158 = & V_159 ;
V_100 = & V_9 -> V_100 ;
V_100 -> V_125 = V_80 -> V_124 [ V_13 ] ;
V_100 -> V_160 = F_29 ;
V_100 -> V_156 = ( V_20 -> V_38 ?
V_80 -> V_51 [ V_22 ] +
V_80 -> V_51 [ V_32 ] :
V_80 -> V_51 [ V_13 ] ) /
V_107 ;
V_100 -> V_161 |= V_162 ;
F_54 ( V_11 , V_80 ) ;
V_11 -> V_109 = V_9 -> V_112 . V_141 ;
}
static int F_60 ( struct V_7 * V_11 ,
struct V_79 * V_80 ,
struct V_114 * V_163 )
{
struct V_10 * V_20 = F_5 ( V_11 ) ;
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_116 * V_105 = & V_20 -> V_104 -> V_105 ;
struct V_144 V_145 = {} ;
int V_29 ;
V_29 = F_61 ( V_105 , V_9 ) ;
if ( V_29 < 0 )
return V_29 ;
F_56 ( V_11 , V_80 , & V_145 ) ;
V_11 -> V_142 = F_62 ( V_105 , F_63 ( V_163 ) ,
V_9 , & V_164 ,
& V_145 ) ;
if ( F_64 ( V_11 -> V_142 ) ) {
V_29 = F_65 ( V_11 -> V_142 ) ;
goto V_165;
}
return 0 ;
V_165:
F_66 ( V_9 ) ;
return V_29 ;
}
static int F_67 ( struct V_166 * V_104 )
{
struct V_116 * V_105 = & V_104 -> V_105 ;
struct V_146 * V_147 = F_57 ( V_105 -> V_148 ) ;
struct V_10 * V_20 ;
struct V_7 * V_12 ;
struct V_114 * V_115 [ 2 ] = {} ;
struct V_79 V_80 = {} ;
int V_167 [ 2 ] , V_31 , V_29 ;
V_20 = F_68 ( V_105 , sizeof( * V_20 ) , V_168 ) ;
if ( ! V_20 )
return - V_169 ;
V_20 -> V_104 = V_104 ;
V_20 -> V_27 = V_147 -> V_27 ;
V_20 -> V_40 = V_41 ;
V_12 = V_20 -> V_12 ;
F_69 ( V_104 , V_20 ) ;
V_29 = F_53 ( V_20 , & V_80 , V_115 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_28 ( V_20 , & V_80 ) ;
if ( V_29 < 0 )
return V_29 ;
F_70 ( & V_20 -> V_103 ) ;
V_167 [ V_22 ] =
V_20 -> V_38 || F_8 ( V_20 , V_22 ) ;
V_167 [ V_32 ] =
! V_20 -> V_38 && F_8 ( V_20 , V_32 ) ;
for ( V_31 = V_22 ; V_31 <= V_32 ; ++ V_31 ) {
if ( ! V_167 [ V_31 ] )
continue;
F_59 ( & V_12 [ V_31 ] , & V_80 ) ;
V_29 = F_60 ( & V_12 [ V_31 ] , & V_80 ,
V_115 [ V_31 ] ) ;
if ( V_29 < 0 ) {
if ( V_31 == V_32 )
goto V_170;
else
goto V_171;
}
}
return 0 ;
V_170:
if ( ! V_167 [ V_22 ] )
goto V_171;
F_71 ( V_12 [ V_22 ] . V_142 ) ;
F_66 ( & V_12 [ V_22 ] . V_9 ) ;
V_171:
F_72 ( & V_20 -> V_103 ) ;
return V_29 ;
}
static int F_73 ( struct V_166 * V_104 )
{
struct V_10 * V_20 = F_74 ( V_104 ) ;
struct V_7 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_38 || F_8 ( V_20 , V_22 ) ) {
F_71 ( V_12 [ V_22 ] . V_142 ) ;
F_66 ( & V_12 [ V_22 ] . V_9 ) ;
}
if ( ! V_20 -> V_38 && F_8 ( V_20 , V_32 ) ) {
F_71 ( V_12 [ V_32 ] . V_142 ) ;
F_66 ( & V_12 [ V_32 ] . V_9 ) ;
}
F_72 ( & V_20 -> V_103 ) ;
return 0 ;
}
