static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
V_2 = 0x1fff ^ V_1 >> 16 ;
V_2 = V_2 ^ V_2 >> 3 ^ V_2 >> 6 ;
V_2 = V_2 ^ V_2 >> 9 ;
V_2 = V_2 ^ V_2 << 13 ^ V_1 ;
V_2 = V_2 ^ V_2 >> 3 ^ V_2 >> 6 ;
return V_2 ^ V_2 >> 9 ;
}
static T_1 F_2 ( T_2 V_1 )
{
return V_1 * 2 - 1 ;
}
static enum V_3
F_3 ( const struct V_4 * V_5 )
{
F_4 ( V_6 != ( V_7 >> 2 ) ) ;
F_4 ( V_6 != ( V_8 >> 2 ) ) ;
F_4 ( V_6 != ( V_9 >> 2 ) ) ;
F_4 ( V_6 != ( V_10 >> 2 ) ) ;
F_4 ( V_11 != ( V_12 >> 2 ) ) ;
F_4 ( V_11 != ( V_13 >> 2 ) ) ;
F_4 ( V_14 != V_11 + 2 ) ;
F_5 ( V_5 -> type == V_15 ) ;
return ( V_5 -> type >> 2 ) + ( ( V_5 -> V_16 & V_17 ) ? 2 : 0 ) ;
}
static struct V_18 *
F_6 ( struct V_19 * V_20 ,
const struct V_4 * V_5 )
{
if ( V_5 -> type == V_15 )
return NULL ;
else
return & V_20 -> V_21 [ F_3 ( V_5 ) ] ;
}
static void F_7 ( struct V_18 * V_21 )
{
memset ( V_21 -> V_22 , 0 , sizeof( V_21 -> V_22 ) ) ;
}
static void F_8 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 ;
T_3 V_26 ;
F_9 ( V_24 , & V_26 , V_27 ) ;
V_21 = & V_20 -> V_21 [ V_6 ] ;
F_10 ( V_26 , V_28 ,
V_21 -> V_22 [ V_7 ] +
V_29 ) ;
F_10 ( V_26 , V_30 ,
V_21 -> V_22 [ V_8 ] +
V_31 ) ;
F_10 ( V_26 , V_32 ,
V_21 -> V_22 [ V_9 ] +
V_29 ) ;
F_10 ( V_26 , V_33 ,
V_21 -> V_22 [ V_10 ] +
V_31 ) ;
V_21 = & V_20 -> V_21 [ V_11 ] ;
if ( V_21 -> V_34 ) {
F_10 (
V_26 , V_35 ,
V_21 -> V_22 [ V_12 ] +
V_29 ) ;
F_10 (
V_26 , V_36 ,
V_21 -> V_22 [ V_13 ] +
V_31 ) ;
}
V_21 = & V_20 -> V_21 [ V_37 ] ;
if ( V_21 -> V_34 ) {
F_10 (
V_26 , V_38 ,
V_21 -> V_5 [ V_39 ] . V_40 ) ;
F_10 (
V_26 , V_41 ,
! ! ( V_21 -> V_5 [ V_39 ] . V_16 &
V_42 ) ) ;
F_10 (
V_26 , V_43 ,
V_21 -> V_5 [ V_44 ] . V_40 ) ;
F_10 (
V_26 , V_45 ,
! ! ( V_21 -> V_5 [ V_44 ] . V_16 &
V_42 ) ) ;
F_10 (
V_26 , V_46 ,
! ! ( V_21 -> V_5 [ V_39 ] . V_16 &
V_21 -> V_5 [ V_44 ] . V_16 &
V_47 ) ) ;
} else if ( F_11 ( V_24 ) >= V_48 ) {
F_10 (
V_26 , V_46 ,
V_24 -> V_49 ) ;
}
F_12 ( V_24 , & V_26 , V_27 ) ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 ;
T_3 V_50 ;
F_9 ( V_24 , & V_50 , V_51 ) ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
if ( V_21 -> V_34 ) {
F_10 (
V_50 , V_52 ,
V_21 -> V_22 [ V_12 ] +
V_29 ) ;
F_10 (
V_50 , V_53 ,
V_21 -> V_22 [ V_13 ] +
V_31 ) ;
}
F_12 ( V_24 , & V_50 , V_51 ) ;
}
static inline void F_14 ( struct V_4 * V_5 ,
T_4 V_54 , T_5 V_55 ,
T_4 V_56 , T_5 V_57 )
{
V_5 -> V_58 [ 0 ] = F_15 ( V_54 ) << 16 | F_16 ( V_55 ) ;
V_5 -> V_58 [ 1 ] = F_16 ( V_57 ) << 16 | F_15 ( V_54 ) >> 16 ;
V_5 -> V_58 [ 2 ] = F_15 ( V_56 ) ;
}
static inline void F_17 ( const struct V_4 * V_5 ,
T_4 * V_54 , T_5 * V_55 ,
T_4 * V_56 , T_5 * V_57 )
{
* V_54 = F_18 ( V_5 -> V_58 [ 0 ] >> 16 | V_5 -> V_58 [ 1 ] << 16 ) ;
* V_55 = F_19 ( V_5 -> V_58 [ 0 ] ) ;
* V_56 = F_18 ( V_5 -> V_58 [ 2 ] ) ;
* V_57 = F_19 ( V_5 -> V_58 [ 1 ] >> 16 ) ;
}
int F_20 ( struct V_4 * V_5 , T_6 V_59 ,
T_4 V_60 , T_5 V_61 )
{
T_4 V_54 ;
T_5 V_55 ;
F_5 ( ! ( V_5 -> V_16 & V_62 ) ) ;
if ( V_5 -> type != V_15 )
return - V_63 ;
if ( V_61 == 0 )
return - V_64 ;
switch ( V_59 ) {
case V_65 :
V_5 -> type = V_8 ;
break;
case V_66 :
V_5 -> type = V_10 ;
break;
default:
return - V_63 ;
}
V_54 = 0 ;
if ( V_59 != V_66 ) {
V_55 = 0 ;
} else {
V_55 = V_61 ;
V_61 = 0 ;
}
F_14 ( V_5 , V_54 , V_55 , V_60 , V_61 ) ;
return 0 ;
}
int F_21 ( const struct V_4 * V_5 ,
T_6 * V_59 , T_4 * V_60 , T_5 * V_61 )
{
T_4 V_54 ;
T_5 V_55 ;
switch ( V_5 -> type ) {
case V_8 :
* V_59 = V_65 ;
F_17 ( V_5 , & V_54 , & V_55 , V_60 , V_61 ) ;
return 0 ;
case V_10 :
* V_59 = V_66 ;
F_17 ( V_5 , & V_54 , V_61 , V_60 , & V_55 ) ;
return 0 ;
default:
return - V_64 ;
}
}
int F_22 ( struct V_4 * V_5 , T_6 V_59 ,
T_4 V_60 , T_5 V_61 ,
T_4 V_67 , T_5 V_68 )
{
F_5 ( ! ( V_5 -> V_16 & V_62 ) ) ;
if ( V_5 -> type != V_15 )
return - V_63 ;
if ( V_61 == 0 || V_68 == 0 )
return - V_64 ;
switch ( V_59 ) {
case V_65 :
V_5 -> type = V_7 ;
break;
case V_66 :
V_5 -> type = V_9 ;
break;
default:
return - V_63 ;
}
F_14 ( V_5 , V_67 , V_68 , V_60 , V_61 ) ;
return 0 ;
}
int F_23 ( const struct V_4 * V_5 ,
T_6 * V_59 , T_4 * V_60 , T_5 * V_61 ,
T_4 * V_67 , T_5 * V_68 )
{
switch ( V_5 -> type ) {
case V_7 :
* V_59 = V_65 ;
break;
case V_9 :
* V_59 = V_66 ;
break;
default:
return - V_64 ;
}
F_17 ( V_5 , V_67 , V_68 , V_60 , V_61 ) ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 ,
T_1 V_69 , const T_6 * V_70 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_62 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_63 ;
if ( V_69 == V_71 ) {
V_5 -> type = V_13 ;
V_5 -> V_58 [ 0 ] = 0 ;
} else {
V_5 -> type = V_12 ;
V_5 -> V_58 [ 0 ] = V_69 ;
}
V_5 -> V_58 [ 1 ] = V_70 [ 2 ] << 24 | V_70 [ 3 ] << 16 | V_70 [ 4 ] << 8 | V_70 [ 5 ] ;
V_5 -> V_58 [ 2 ] = V_70 [ 0 ] << 8 | V_70 [ 1 ] ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_62 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_64 ;
V_5 -> type = V_72 ;
memset ( V_5 -> V_58 , 0 , sizeof( V_5 -> V_58 ) ) ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_62 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_64 ;
V_5 -> type = V_73 ;
memset ( V_5 -> V_58 , 0 , sizeof( V_5 -> V_58 ) ) ;
return 0 ;
}
static void F_27 ( struct V_23 * V_24 , unsigned V_74 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_37 ] ;
struct V_4 * V_5 = & V_21 -> V_5 [ V_74 ] ;
enum V_75 V_16 = 0 ;
if ( V_24 -> V_76 > 1 )
V_16 |= V_42 ;
if ( V_24 -> V_49 )
V_16 |= V_47 ;
F_28 ( V_5 , V_77 , V_16 , 0 ) ;
V_5 -> type = V_72 + V_74 ;
V_21 -> V_78 [ 0 ] |= 1 << V_74 ;
}
int F_29 ( const struct V_4 * V_5 ,
T_1 * V_69 , T_6 * V_70 )
{
switch ( V_5 -> type ) {
case V_13 :
* V_69 = V_71 ;
break;
case V_12 :
* V_69 = V_5 -> V_58 [ 0 ] ;
break;
default:
return - V_64 ;
}
V_70 [ 0 ] = V_5 -> V_58 [ 2 ] >> 8 ;
V_70 [ 1 ] = V_5 -> V_58 [ 2 ] ;
V_70 [ 2 ] = V_5 -> V_58 [ 1 ] >> 24 ;
V_70 [ 3 ] = V_5 -> V_58 [ 1 ] >> 16 ;
V_70 [ 4 ] = V_5 -> V_58 [ 1 ] >> 8 ;
V_70 [ 5 ] = V_5 -> V_58 [ 1 ] ;
return 0 ;
}
static T_2 F_30 ( T_3 * V_79 , struct V_4 * V_5 )
{
T_2 V_80 ;
switch ( F_3 ( V_5 ) ) {
case V_6 : {
bool V_81 = ( V_5 -> type == V_9 ||
V_5 -> type == V_10 ) ;
F_31 (
* V_79 ,
V_82 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_83 ,
! ! ( V_5 -> V_16 & V_47 ) ,
V_84 , V_81 ,
V_85 , V_5 -> V_40 ,
V_86 , V_5 -> V_58 [ 2 ] ,
V_87 , V_5 -> V_58 [ 1 ] ,
V_88 , V_5 -> V_58 [ 0 ] ) ;
V_80 = V_81 ;
break;
}
case V_11 : {
bool V_89 = V_5 -> type == V_13 ;
F_31 (
* V_79 ,
V_90 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_91 ,
! ! ( V_5 -> V_16 & V_47 ) ,
V_92 , V_5 -> V_40 ,
V_93 , V_89 ,
V_94 , V_5 -> V_58 [ 2 ] ,
V_95 , V_5 -> V_58 [ 1 ] ,
V_96 , V_5 -> V_58 [ 0 ] ) ;
V_80 = V_89 ;
break;
}
case V_14 : {
bool V_89 = V_5 -> type == V_13 ;
F_32 ( * V_79 ,
V_97 , V_5 -> V_40 ,
V_98 , V_89 ,
V_99 , V_5 -> V_58 [ 2 ] ,
V_100 , V_5 -> V_58 [ 1 ] ,
V_101 , V_5 -> V_58 [ 0 ] ) ;
V_80 = V_89 | V_5 -> V_40 << 1 ;
break;
}
default:
F_33 () ;
}
return V_5 -> V_58 [ 0 ] ^ V_5 -> V_58 [ 1 ] ^ V_5 -> V_58 [ 2 ] ^ V_80 ;
}
static bool F_34 ( const struct V_4 * V_102 ,
const struct V_4 * V_103 )
{
if ( V_102 -> type != V_103 -> type ||
memcmp ( V_102 -> V_58 , V_103 -> V_58 , sizeof( V_102 -> V_58 ) ) )
return false ;
if ( V_102 -> V_16 & V_17 &&
V_102 -> V_40 != V_103 -> V_40 )
return false ;
return true ;
}
static inline T_2
F_35 ( const struct V_4 * V_5 , unsigned int V_104 )
{
unsigned int V_105 ;
V_105 = V_106 [ V_5 -> type ] ;
if ( ! ( V_5 -> V_16 & V_62 ) )
V_105 += V_107 ;
return V_105 << V_108 | V_104 ;
}
static inline enum V_3 F_36 ( T_2 V_109 )
{
unsigned int V_105 = V_109 >> V_108 ;
if ( V_105 < F_37 ( V_110 ) )
return V_110 [ V_105 ] ;
else
return V_111 ;
}
static inline unsigned int F_38 ( T_2 V_109 )
{
return V_109 & V_112 ;
}
static inline T_6 F_39 ( T_2 V_109 )
{
unsigned int V_105 = V_109 >> V_108 ;
if ( V_105 < V_107 )
return V_62 ;
else
return V_17 ;
}
T_2 F_40 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
unsigned int V_105 = V_107 - 1 ;
enum V_3 V_113 ;
do {
V_113 = V_110 [ V_105 ] ;
if ( V_20 -> V_21 [ V_113 ] . V_34 != 0 )
return V_105 << V_108 |
V_20 -> V_21 [ V_113 ] . V_34 ;
} while ( V_105 -- );
return 0 ;
}
T_7 F_41 ( struct V_23 * V_24 , struct V_4 * V_5 ,
bool V_114 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = F_6 ( V_20 , V_5 ) ;
T_3 V_79 ;
int V_115 , V_116 ;
unsigned int V_117 = 0 ;
int V_118 ;
if ( ! V_21 || V_21 -> V_34 == 0 )
return - V_64 ;
F_42 ( V_24 , V_119 , V_24 -> V_120 ,
L_1 , V_121 , V_5 -> type ,
V_21 -> V_22 [ V_5 -> type ] ) ;
if ( V_21 -> V_109 == V_37 ) {
F_4 ( V_39 != 0 ) ;
F_4 ( V_44 !=
V_73 - V_72 ) ;
V_115 = V_5 -> type - V_39 ;
V_116 = V_115 ;
F_43 ( & V_20 -> V_122 ) ;
} else {
T_2 V_1 = F_30 ( & V_79 , V_5 ) ;
unsigned int V_123 = F_1 ( V_1 ) ;
unsigned int V_124 = F_2 ( V_1 ) ;
unsigned int V_125 = V_21 -> V_22 [ V_5 -> type ] ;
unsigned int V_126 =
V_5 -> V_127 <= V_128 ?
V_129 : V_130 ;
unsigned int V_131 = V_123 & ( V_21 -> V_34 - 1 ) ;
V_116 = - 1 ;
V_117 = 1 ;
F_43 ( & V_20 -> V_122 ) ;
for (; ; ) {
if ( ! F_44 ( V_131 , V_21 -> V_78 ) ) {
if ( V_116 < 0 )
V_116 = V_131 ;
} else if ( F_34 ( V_5 , & V_21 -> V_5 [ V_131 ] ) ) {
if ( V_116 < 0 )
V_116 = V_131 ;
V_115 = V_131 ;
break;
}
if ( V_117 >= V_125 &&
( V_116 >= 0 || V_117 >= V_126 ) ) {
if ( V_116 < 0 ) {
V_118 = - V_132 ;
goto V_133;
}
V_115 = - 1 ;
break;
}
V_131 = ( V_131 + V_124 ) & ( V_21 -> V_34 - 1 ) ;
++ V_117 ;
}
}
if ( V_115 >= 0 ) {
struct V_4 * V_134 = & V_21 -> V_5 [ V_115 ] ;
if ( V_5 -> V_127 == V_134 -> V_127 && ! V_114 ) {
V_118 = - V_135 ;
goto V_133;
}
if ( V_5 -> V_127 < V_134 -> V_127 ) {
V_118 = - V_136 ;
goto V_133;
}
}
if ( V_116 != V_115 ) {
F_45 ( V_116 , V_21 -> V_78 ) ;
++ V_21 -> V_137 ;
}
V_21 -> V_5 [ V_116 ] = * V_5 ;
if ( V_21 -> V_109 == V_37 ) {
F_8 ( V_24 ) ;
} else {
if ( V_21 -> V_22 [ V_5 -> type ] < V_117 ) {
V_21 -> V_22 [ V_5 -> type ] = V_117 ;
if ( V_5 -> V_16 & V_17 )
F_13 ( V_24 ) ;
else
F_8 ( V_24 ) ;
}
F_12 ( V_24 , & V_79 ,
V_21 -> V_138 + V_21 -> V_139 * V_116 ) ;
if ( V_116 != V_115 && V_115 >= 0 )
F_46 ( V_24 , V_21 , V_115 ) ;
}
F_42 ( V_24 , V_119 , V_24 -> V_120 ,
L_2 ,
V_121 , V_5 -> type , V_116 , V_5 -> V_40 ) ;
V_118 = F_35 ( V_5 , V_116 ) ;
V_133:
F_47 ( & V_20 -> V_122 ) ;
return V_118 ;
}
static void F_46 ( struct V_23 * V_24 ,
struct V_18 * V_21 ,
unsigned int V_74 )
{
static T_3 V_79 ;
if ( V_21 -> V_109 == V_37 ) {
F_27 ( V_24 , V_74 ) ;
F_8 ( V_24 ) ;
} else if ( F_44 ( V_74 , V_21 -> V_78 ) ) {
F_48 ( V_74 , V_21 -> V_78 ) ;
-- V_21 -> V_137 ;
memset ( & V_21 -> V_5 [ V_74 ] , 0 , sizeof( V_21 -> V_5 [ 0 ] ) ) ;
F_12 ( V_24 , & V_79 ,
V_21 -> V_138 + V_21 -> V_139 * V_74 ) ;
}
}
int F_49 ( struct V_23 * V_24 ,
enum V_140 V_127 ,
T_2 V_141 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
unsigned int V_74 ;
struct V_4 * V_5 ;
T_6 V_142 ;
int V_118 ;
V_113 = F_36 ( V_141 ) ;
if ( ( unsigned int ) V_113 >= V_111 )
return - V_143 ;
V_21 = & V_20 -> V_21 [ V_113 ] ;
V_74 = F_38 ( V_141 ) ;
if ( V_74 >= V_21 -> V_34 )
return - V_143 ;
V_5 = & V_21 -> V_5 [ V_74 ] ;
V_142 = F_39 ( V_141 ) ;
F_43 ( & V_20 -> V_122 ) ;
if ( F_44 ( V_74 , V_21 -> V_78 ) &&
V_5 -> V_127 == V_127 ) {
F_46 ( V_24 , V_21 , V_74 ) ;
if ( V_21 -> V_137 == 0 )
F_7 ( V_21 ) ;
V_118 = 0 ;
} else {
V_118 = - V_143 ;
}
F_47 ( & V_20 -> V_122 ) ;
return V_118 ;
}
int F_50 ( struct V_23 * V_24 ,
enum V_140 V_127 ,
T_2 V_141 , struct V_4 * V_144 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
struct V_4 * V_5 ;
unsigned int V_74 ;
T_6 V_142 ;
int V_118 ;
V_113 = F_36 ( V_141 ) ;
if ( ( unsigned int ) V_113 >= V_111 )
return - V_143 ;
V_21 = & V_20 -> V_21 [ V_113 ] ;
V_74 = F_38 ( V_141 ) ;
if ( V_74 >= V_21 -> V_34 )
return - V_143 ;
V_5 = & V_21 -> V_5 [ V_74 ] ;
V_142 = F_39 ( V_141 ) ;
F_43 ( & V_20 -> V_122 ) ;
if ( F_44 ( V_74 , V_21 -> V_78 ) &&
V_5 -> V_127 == V_127 ) {
* V_144 = * V_5 ;
V_118 = 0 ;
} else {
V_118 = - V_143 ;
}
F_47 ( & V_20 -> V_122 ) ;
return V_118 ;
}
static void F_51 ( struct V_23 * V_24 ,
enum V_3 V_113 ,
enum V_140 V_127 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_113 ] ;
unsigned int V_74 ;
F_43 ( & V_20 -> V_122 ) ;
for ( V_74 = 0 ; V_74 < V_21 -> V_34 ; ++ V_74 )
if ( V_21 -> V_5 [ V_74 ] . V_127 <= V_127 )
F_46 ( V_24 , V_21 , V_74 ) ;
if ( V_21 -> V_137 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_122 ) ;
}
void F_52 ( struct V_23 * V_24 , enum V_140 V_127 )
{
F_51 ( V_24 , V_6 , V_127 ) ;
F_51 ( V_24 , V_11 , V_127 ) ;
}
T_2 F_53 ( struct V_23 * V_24 ,
enum V_140 V_127 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
unsigned int V_74 ;
T_2 V_145 = 0 ;
F_43 ( & V_20 -> V_122 ) ;
for ( V_113 = V_6 ;
V_113 <= V_37 ;
V_113 ++ ) {
V_21 = & V_20 -> V_21 [ V_113 ] ;
for ( V_74 = 0 ; V_74 < V_21 -> V_34 ; V_74 ++ ) {
if ( F_44 ( V_74 , V_21 -> V_78 ) &&
V_21 -> V_5 [ V_74 ] . V_127 == V_127 )
++ V_145 ;
}
}
F_47 ( & V_20 -> V_122 ) ;
return V_145 ;
}
T_7 F_54 ( struct V_23 * V_24 ,
enum V_140 V_127 ,
T_2 * V_146 , T_2 V_34 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
unsigned int V_74 ;
T_7 V_145 = 0 ;
F_43 ( & V_20 -> V_122 ) ;
for ( V_113 = V_6 ;
V_113 <= V_37 ;
V_113 ++ ) {
V_21 = & V_20 -> V_21 [ V_113 ] ;
for ( V_74 = 0 ; V_74 < V_21 -> V_34 ; V_74 ++ ) {
if ( F_44 ( V_74 , V_21 -> V_78 ) &&
V_21 -> V_5 [ V_74 ] . V_127 == V_127 ) {
if ( V_145 == V_34 ) {
V_145 = - V_147 ;
goto V_133;
}
V_146 [ V_145 ++ ] = F_35 (
& V_21 -> V_5 [ V_74 ] , V_74 ) ;
}
}
}
V_133:
F_47 ( & V_20 -> V_122 ) ;
return V_145 ;
}
void F_55 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
T_3 V_79 ;
unsigned int V_74 ;
F_43 ( & V_20 -> V_122 ) ;
for ( V_113 = 0 ; V_113 < V_111 ; V_113 ++ ) {
V_21 = & V_20 -> V_21 [ V_113 ] ;
if ( V_21 -> V_139 == 0 )
continue;
for ( V_74 = 0 ; V_74 < V_21 -> V_34 ; V_74 ++ ) {
if ( ! F_44 ( V_74 , V_21 -> V_78 ) )
continue;
F_30 ( & V_79 , & V_21 -> V_5 [ V_74 ] ) ;
F_12 ( V_24 , & V_79 ,
V_21 -> V_138 + V_21 -> V_139 * V_74 ) ;
}
}
F_8 ( V_24 ) ;
F_13 ( V_24 ) ;
F_47 ( & V_20 -> V_122 ) ;
}
int F_56 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
unsigned V_113 ;
V_20 = F_57 ( sizeof( * V_24 -> V_25 ) , V_148 ) ;
if ( ! V_20 )
return - V_149 ;
V_24 -> V_25 = V_20 ;
F_58 ( & V_20 -> V_122 ) ;
if ( F_11 ( V_24 ) >= V_48 ) {
#ifdef F_59
V_20 -> V_150 = F_60 ( V_151 ,
sizeof( * V_20 -> V_150 ) ,
V_148 ) ;
if ( ! V_20 -> V_150 )
goto V_152;
#endif
V_21 = & V_20 -> V_21 [ V_6 ] ;
V_21 -> V_109 = V_6 ;
V_21 -> V_138 = V_153 ;
V_21 -> V_34 = V_151 ;
V_21 -> V_139 = V_154 ;
}
if ( F_11 ( V_24 ) >= V_155 ) {
V_21 = & V_20 -> V_21 [ V_11 ] ;
V_21 -> V_109 = V_11 ;
V_21 -> V_138 = V_156 ;
V_21 -> V_34 = V_157 ;
V_21 -> V_139 = V_158 ;
V_21 = & V_20 -> V_21 [ V_37 ] ;
V_21 -> V_109 = V_37 ;
V_21 -> V_34 = V_159 ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
V_21 -> V_109 = V_14 ;
V_21 -> V_138 = V_160 ;
V_21 -> V_34 = V_161 ;
V_21 -> V_139 = V_162 ;
}
for ( V_113 = 0 ; V_113 < V_111 ; V_113 ++ ) {
V_21 = & V_20 -> V_21 [ V_113 ] ;
if ( V_21 -> V_34 == 0 )
continue;
V_21 -> V_78 = F_60 ( F_61 ( V_21 -> V_34 ) ,
sizeof( unsigned long ) ,
V_148 ) ;
if ( ! V_21 -> V_78 )
goto V_152;
V_21 -> V_5 = F_62 ( V_21 -> V_34 * sizeof( * V_21 -> V_5 ) ) ;
if ( ! V_21 -> V_5 )
goto V_152;
}
if ( V_20 -> V_21 [ V_37 ] . V_34 ) {
unsigned V_131 ;
for ( V_131 = 0 ; V_131 < V_159 ; V_131 ++ )
F_27 ( V_24 , V_131 ) ;
}
F_8 ( V_24 ) ;
return 0 ;
V_152:
F_63 ( V_24 ) ;
return - V_149 ;
}
void F_63 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
for ( V_113 = 0 ; V_113 < V_111 ; V_113 ++ ) {
F_64 ( V_20 -> V_21 [ V_113 ] . V_78 ) ;
F_65 ( V_20 -> V_21 [ V_113 ] . V_5 ) ;
}
#ifdef F_59
F_64 ( V_20 -> V_150 ) ;
#endif
F_64 ( V_20 ) ;
}
void F_66 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_113 ;
struct V_18 * V_21 ;
T_3 V_79 ;
unsigned int V_74 ;
F_43 ( & V_20 -> V_122 ) ;
for ( V_113 = V_6 ;
V_113 <= V_37 ;
V_113 ++ ) {
V_21 = & V_20 -> V_21 [ V_113 ] ;
for ( V_74 = 0 ; V_74 < V_21 -> V_34 ; V_74 ++ ) {
if ( ! F_44 ( V_74 , V_21 -> V_78 ) ||
V_21 -> V_5 [ V_74 ] . V_40 >=
V_24 -> V_76 )
continue;
if ( V_24 -> V_49 )
V_21 -> V_5 [ V_74 ] . V_16 |=
V_47 ;
else
V_21 -> V_5 [ V_74 ] . V_16 &=
~ V_47 ;
if ( V_113 == V_37 )
continue;
F_30 ( & V_79 , & V_21 -> V_5 [ V_74 ] ) ;
F_12 ( V_24 , & V_79 ,
V_21 -> V_138 + V_21 -> V_139 * V_74 ) ;
}
}
F_8 ( V_24 ) ;
F_47 ( & V_20 -> V_122 ) ;
}
int F_67 ( struct V_163 * V_120 , const struct V_164 * V_165 ,
T_1 V_166 , T_2 V_167 )
{
struct V_23 * V_24 = F_68 ( V_120 ) ;
struct V_168 * V_169 ;
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_4 V_5 ;
const struct V_170 * V_171 ;
const T_5 * V_172 ;
int V_173 ;
int V_118 ;
V_173 = F_69 ( V_165 ) ;
if ( V_165 -> V_174 != F_19 ( V_175 ) )
return - V_63 ;
F_5 ( F_70 ( V_165 ) < V_173 + sizeof( * V_171 ) ) ;
V_171 = ( const struct V_170 * ) ( V_165 -> V_58 + V_173 ) ;
if ( F_71 ( V_171 ) )
return - V_63 ;
F_5 ( F_70 ( V_165 ) < V_173 + 4 * V_171 -> V_176 + 4 ) ;
V_172 = ( const T_5 * ) ( V_165 -> V_58 + V_173 + 4 * V_171 -> V_176 ) ;
F_28 ( & V_5 , V_128 , 0 , V_166 ) ;
V_118 = F_22 ( & V_5 , V_171 -> V_174 ,
V_171 -> V_177 , V_172 [ 1 ] , V_171 -> V_178 , V_172 [ 0 ] ) ;
if ( V_118 )
return V_118 ;
V_118 = F_41 ( V_24 , & V_5 , true ) ;
if ( V_118 < 0 )
return V_118 ;
V_20 -> V_150 [ V_118 ] = V_167 ;
V_169 = F_72 ( V_24 , F_73 ( V_165 ) ) ;
++ V_169 -> V_179 ;
F_74 ( V_24 , V_180 , V_24 -> V_120 ,
L_3 ,
( V_171 -> V_174 == V_65 ) ? L_4 : L_5 ,
& V_171 -> V_178 , F_16 ( V_172 [ 0 ] ) , & V_171 -> V_177 , F_16 ( V_172 [ 1 ] ) ,
V_166 , V_167 , V_118 ) ;
return V_118 ;
}
bool F_75 ( struct V_23 * V_24 , unsigned V_181 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_6 ] ;
unsigned V_182 = V_21 -> V_34 - 1 ;
unsigned V_104 ;
unsigned V_183 ;
if ( ! F_76 ( & V_20 -> V_122 ) )
return false ;
V_104 = V_20 -> V_184 ;
V_183 = ( V_104 + V_181 ) & V_182 ;
while ( V_104 != V_183 ) {
if ( F_44 ( V_104 , V_21 -> V_78 ) &&
V_21 -> V_5 [ V_104 ] . V_127 == V_128 &&
F_77 ( V_24 -> V_120 ,
V_21 -> V_5 [ V_104 ] . V_40 ,
V_20 -> V_150 [ V_104 ] , V_104 ) ) {
F_74 ( V_24 , V_180 , V_24 -> V_120 ,
L_6 ,
V_104 , V_20 -> V_150 [ V_104 ] ) ;
F_46 ( V_24 , V_21 , V_104 ) ;
}
V_104 = ( V_104 + 1 ) & V_182 ;
}
V_20 -> V_184 = V_183 ;
if ( V_21 -> V_137 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_122 ) ;
return true ;
}
