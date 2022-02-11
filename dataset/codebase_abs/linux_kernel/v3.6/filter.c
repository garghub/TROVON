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
! ! ( V_21 -> V_5 [ V_39 ] . V_16 &
V_44 ) ) ;
F_10 (
V_26 , V_45 ,
V_21 -> V_5 [ V_46 ] . V_40 ) ;
F_10 (
V_26 , V_47 ,
! ! ( V_21 -> V_5 [ V_46 ] . V_16 &
V_42 ) ) ;
F_10 (
V_26 , V_48 ,
! ! ( V_21 -> V_5 [ V_46 ] . V_16 &
V_44 ) ) ;
}
F_11 ( V_24 , & V_26 , V_27 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 ;
T_3 V_49 ;
F_9 ( V_24 , & V_49 , V_50 ) ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
if ( V_21 -> V_34 ) {
F_10 (
V_49 , V_51 ,
V_21 -> V_22 [ V_12 ] +
V_29 ) ;
F_10 (
V_49 , V_52 ,
V_21 -> V_22 [ V_13 ] +
V_31 ) ;
}
F_11 ( V_24 , & V_49 , V_50 ) ;
}
static inline void F_13 ( struct V_4 * V_5 ,
T_4 V_53 , T_5 V_54 ,
T_4 V_55 , T_5 V_56 )
{
V_5 -> V_57 [ 0 ] = F_14 ( V_53 ) << 16 | F_15 ( V_54 ) ;
V_5 -> V_57 [ 1 ] = F_15 ( V_56 ) << 16 | F_14 ( V_53 ) >> 16 ;
V_5 -> V_57 [ 2 ] = F_14 ( V_55 ) ;
}
static inline void F_16 ( const struct V_4 * V_5 ,
T_4 * V_53 , T_5 * V_54 ,
T_4 * V_55 , T_5 * V_56 )
{
* V_53 = F_17 ( V_5 -> V_57 [ 0 ] >> 16 | V_5 -> V_57 [ 1 ] << 16 ) ;
* V_54 = F_18 ( V_5 -> V_57 [ 0 ] ) ;
* V_55 = F_17 ( V_5 -> V_57 [ 2 ] ) ;
* V_56 = F_18 ( V_5 -> V_57 [ 1 ] >> 16 ) ;
}
int F_19 ( struct V_4 * V_5 , T_6 V_58 ,
T_4 V_59 , T_5 V_60 )
{
T_4 V_53 ;
T_5 V_54 ;
F_5 ( ! ( V_5 -> V_16 & V_61 ) ) ;
if ( V_5 -> type != V_15 )
return - V_62 ;
if ( V_60 == 0 )
return - V_63 ;
switch ( V_58 ) {
case V_64 :
V_5 -> type = V_8 ;
break;
case V_65 :
V_5 -> type = V_10 ;
break;
default:
return - V_62 ;
}
V_53 = 0 ;
if ( V_58 != V_65 ) {
V_54 = 0 ;
} else {
V_54 = V_60 ;
V_60 = 0 ;
}
F_13 ( V_5 , V_53 , V_54 , V_59 , V_60 ) ;
return 0 ;
}
int F_20 ( const struct V_4 * V_5 ,
T_6 * V_58 , T_4 * V_59 , T_5 * V_60 )
{
T_4 V_53 ;
T_5 V_54 ;
switch ( V_5 -> type ) {
case V_8 :
* V_58 = V_64 ;
F_16 ( V_5 , & V_53 , & V_54 , V_59 , V_60 ) ;
return 0 ;
case V_10 :
* V_58 = V_65 ;
F_16 ( V_5 , & V_53 , V_60 , V_59 , & V_54 ) ;
return 0 ;
default:
return - V_63 ;
}
}
int F_21 ( struct V_4 * V_5 , T_6 V_58 ,
T_4 V_59 , T_5 V_60 ,
T_4 V_66 , T_5 V_67 )
{
F_5 ( ! ( V_5 -> V_16 & V_61 ) ) ;
if ( V_5 -> type != V_15 )
return - V_62 ;
if ( V_60 == 0 || V_67 == 0 )
return - V_63 ;
switch ( V_58 ) {
case V_64 :
V_5 -> type = V_7 ;
break;
case V_65 :
V_5 -> type = V_9 ;
break;
default:
return - V_62 ;
}
F_13 ( V_5 , V_66 , V_67 , V_59 , V_60 ) ;
return 0 ;
}
int F_22 ( const struct V_4 * V_5 ,
T_6 * V_58 , T_4 * V_59 , T_5 * V_60 ,
T_4 * V_66 , T_5 * V_67 )
{
switch ( V_5 -> type ) {
case V_7 :
* V_58 = V_64 ;
break;
case V_9 :
* V_58 = V_65 ;
break;
default:
return - V_63 ;
}
F_16 ( V_5 , V_66 , V_67 , V_59 , V_60 ) ;
return 0 ;
}
int F_23 ( struct V_4 * V_5 ,
T_1 V_68 , const T_6 * V_69 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_61 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_62 ;
if ( V_68 == V_70 ) {
V_5 -> type = V_13 ;
V_5 -> V_57 [ 0 ] = 0 ;
} else {
V_5 -> type = V_12 ;
V_5 -> V_57 [ 0 ] = V_68 ;
}
V_5 -> V_57 [ 1 ] = V_69 [ 2 ] << 24 | V_69 [ 3 ] << 16 | V_69 [ 4 ] << 8 | V_69 [ 5 ] ;
V_5 -> V_57 [ 2 ] = V_69 [ 0 ] << 8 | V_69 [ 1 ] ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_61 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_63 ;
V_5 -> type = V_71 ;
memset ( V_5 -> V_57 , 0 , sizeof( V_5 -> V_57 ) ) ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_61 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_63 ;
V_5 -> type = V_72 ;
memset ( V_5 -> V_57 , 0 , sizeof( V_5 -> V_57 ) ) ;
return 0 ;
}
static void F_26 ( struct V_23 * V_24 , unsigned V_73 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_37 ] ;
struct V_4 * V_5 = & V_21 -> V_5 [ V_73 ] ;
F_27 ( V_5 , V_74 ,
V_42 , 0 ) ;
V_5 -> type = V_71 + V_73 ;
V_21 -> V_75 [ 0 ] |= 1 << V_73 ;
}
int F_28 ( const struct V_4 * V_5 ,
T_1 * V_68 , T_6 * V_69 )
{
switch ( V_5 -> type ) {
case V_13 :
* V_68 = V_70 ;
break;
case V_12 :
* V_68 = V_5 -> V_57 [ 0 ] ;
break;
default:
return - V_63 ;
}
V_69 [ 0 ] = V_5 -> V_57 [ 2 ] >> 8 ;
V_69 [ 1 ] = V_5 -> V_57 [ 2 ] ;
V_69 [ 2 ] = V_5 -> V_57 [ 1 ] >> 24 ;
V_69 [ 3 ] = V_5 -> V_57 [ 1 ] >> 16 ;
V_69 [ 4 ] = V_5 -> V_57 [ 1 ] >> 8 ;
V_69 [ 5 ] = V_5 -> V_57 [ 1 ] ;
return 0 ;
}
static T_2 F_29 ( T_3 * V_76 , struct V_4 * V_5 )
{
T_2 V_77 ;
switch ( F_3 ( V_5 ) ) {
case V_6 : {
bool V_78 = ( V_5 -> type == V_9 ||
V_5 -> type == V_10 ) ;
F_30 (
* V_76 ,
V_79 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_80 ,
! ! ( V_5 -> V_16 & V_81 ) ,
V_82 , V_78 ,
V_83 , V_5 -> V_40 ,
V_84 , V_5 -> V_57 [ 2 ] ,
V_85 , V_5 -> V_57 [ 1 ] ,
V_86 , V_5 -> V_57 [ 0 ] ) ;
V_77 = V_78 ;
break;
}
case V_37 :
F_4 ( V_39 != 0 ) ;
F_4 ( V_46 !=
V_72 - V_71 ) ;
return V_5 -> type - V_71 ;
case V_11 : {
bool V_87 = V_5 -> type == V_13 ;
F_31 (
* V_76 ,
V_88 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_89 ,
! ! ( V_5 -> V_16 & V_81 ) ,
V_90 ,
! ! ( V_5 -> V_16 & V_44 ) ,
V_91 , V_5 -> V_40 ,
V_92 , V_87 ,
V_93 , V_5 -> V_57 [ 2 ] ,
V_94 , V_5 -> V_57 [ 1 ] ,
V_95 , V_5 -> V_57 [ 0 ] ) ;
V_77 = V_87 ;
break;
}
case V_14 : {
bool V_87 = V_5 -> type == V_13 ;
F_32 ( * V_76 ,
V_96 , V_5 -> V_40 ,
V_97 , V_87 ,
V_98 , V_5 -> V_57 [ 2 ] ,
V_99 , V_5 -> V_57 [ 1 ] ,
V_100 , V_5 -> V_57 [ 0 ] ) ;
V_77 = V_87 | V_5 -> V_40 << 1 ;
break;
}
default:
F_33 () ;
}
return V_5 -> V_57 [ 0 ] ^ V_5 -> V_57 [ 1 ] ^ V_5 -> V_57 [ 2 ] ^ V_77 ;
}
static bool F_34 ( const struct V_4 * V_101 ,
const struct V_4 * V_102 )
{
if ( V_101 -> type != V_102 -> type ||
memcmp ( V_101 -> V_57 , V_102 -> V_57 , sizeof( V_101 -> V_57 ) ) )
return false ;
if ( V_101 -> V_16 & V_17 &&
V_101 -> V_40 != V_102 -> V_40 )
return false ;
return true ;
}
static int F_35 ( struct V_18 * V_21 ,
struct V_4 * V_5 , T_2 V_1 ,
bool V_103 , unsigned int * V_104 )
{
unsigned V_105 , V_106 , V_73 , V_107 , V_108 ;
V_105 = F_1 ( V_1 ) ;
V_106 = F_2 ( V_1 ) ;
V_73 = V_105 & ( V_21 -> V_34 - 1 ) ;
V_107 = 1 ;
V_108 = ( V_103 ?
( V_5 -> V_109 <= V_110 ?
V_111 : V_112 ) :
V_21 -> V_22 [ V_5 -> type ] ) ;
for (; ; ) {
if ( F_36 ( V_73 , V_21 -> V_75 ) ?
F_34 ( V_5 , & V_21 -> V_5 [ V_73 ] ) :
V_103 ) {
* V_104 = V_107 ;
return V_73 ;
}
if ( V_107 == V_108 )
return V_103 ? - V_113 : - V_114 ;
V_73 = ( V_73 + V_106 ) & ( V_21 -> V_34 - 1 ) ;
++ V_107 ;
}
}
static inline T_2 F_37 ( enum V_3 V_115 ,
unsigned int V_116 , T_6 V_16 )
{
unsigned int V_117 = V_118 + V_115 ;
if ( V_16 & V_44 ) {
if ( V_115 == V_11 )
V_117 = V_119 ;
else if ( V_115 == V_37 )
V_117 = V_120 ;
}
return V_117 << V_121 | V_116 ;
}
static inline enum V_3 F_38 ( T_2 V_122 )
{
unsigned int V_117 = V_122 >> V_121 ;
switch ( V_117 ) {
case V_119 :
return V_11 ;
case V_120 :
return V_37 ;
default:
return V_117 - V_118 ;
}
}
static inline unsigned int F_39 ( T_2 V_122 )
{
return V_122 & V_123 ;
}
static inline T_6 F_40 ( T_2 V_122 )
{
unsigned int V_117 = V_122 >> V_121 ;
if ( V_117 < V_118 )
return V_61 | V_44 ;
else if ( V_117 <=
V_118 + V_37 )
return V_61 ;
else
return V_17 ;
}
T_2 F_41 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
unsigned int V_115 = V_37 ;
do {
if ( V_20 -> V_21 [ V_115 ] . V_34 != 0 )
return ( ( V_118 + V_115 )
<< V_121 ) +
V_20 -> V_21 [ V_115 ] . V_34 ;
} while ( V_115 -- );
return 0 ;
}
T_7 F_42 ( struct V_23 * V_24 , struct V_4 * V_5 ,
bool V_124 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = F_6 ( V_20 , V_5 ) ;
struct V_4 * V_125 ;
T_3 V_76 ;
unsigned int V_73 , V_107 = 0 ;
T_2 V_1 ;
int V_126 ;
if ( ! V_21 || V_21 -> V_34 == 0 )
return - V_63 ;
V_1 = F_29 ( & V_76 , V_5 ) ;
F_43 ( V_24 , V_127 , V_24 -> V_128 ,
L_1 , V_129 , V_5 -> type ,
V_21 -> V_22 [ V_5 -> type ] ) ;
F_44 ( & V_20 -> V_130 ) ;
V_126 = F_35 ( V_21 , V_5 , V_1 , true , & V_107 ) ;
if ( V_126 < 0 )
goto V_131;
V_73 = V_126 ;
F_45 ( V_73 >= V_21 -> V_34 ) ;
V_125 = & V_21 -> V_5 [ V_73 ] ;
if ( F_36 ( V_73 , V_21 -> V_75 ) ) {
if ( ! V_124 ) {
V_126 = - V_132 ;
goto V_131;
}
if ( V_5 -> V_109 < V_125 -> V_109 ) {
V_126 = - V_133 ;
goto V_131;
}
} else {
F_46 ( V_73 , V_21 -> V_75 ) ;
++ V_21 -> V_134 ;
}
* V_125 = * V_5 ;
if ( V_21 -> V_122 == V_37 ) {
F_8 ( V_24 ) ;
} else {
if ( V_21 -> V_22 [ V_5 -> type ] < V_107 ) {
V_21 -> V_22 [ V_5 -> type ] = V_107 ;
if ( V_5 -> V_16 & V_17 )
F_12 ( V_24 ) ;
else
F_8 ( V_24 ) ;
}
F_11 ( V_24 , & V_76 ,
V_21 -> V_135 + V_21 -> V_136 * V_73 ) ;
}
F_43 ( V_24 , V_127 , V_24 -> V_128 ,
L_2 ,
V_129 , V_5 -> type , V_73 , V_5 -> V_40 ) ;
V_126 = F_37 ( V_21 -> V_122 , V_73 , V_5 -> V_16 ) ;
V_131:
F_47 ( & V_20 -> V_130 ) ;
return V_126 ;
}
static void F_48 ( struct V_23 * V_24 ,
struct V_18 * V_21 ,
unsigned int V_73 )
{
static T_3 V_76 ;
if ( V_21 -> V_122 == V_37 ) {
F_26 ( V_24 , V_73 ) ;
F_8 ( V_24 ) ;
} else if ( F_36 ( V_73 , V_21 -> V_75 ) ) {
F_49 ( V_73 , V_21 -> V_75 ) ;
-- V_21 -> V_134 ;
memset ( & V_21 -> V_5 [ V_73 ] , 0 , sizeof( V_21 -> V_5 [ 0 ] ) ) ;
F_11 ( V_24 , & V_76 ,
V_21 -> V_135 + V_21 -> V_136 * V_73 ) ;
}
}
int F_50 ( struct V_23 * V_24 ,
enum V_137 V_109 ,
T_2 V_138 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
struct V_18 * V_21 ;
unsigned int V_73 ;
struct V_4 * V_5 ;
T_6 V_139 ;
int V_126 ;
V_115 = F_38 ( V_138 ) ;
if ( ( unsigned int ) V_115 >= V_140 )
return - V_114 ;
V_21 = & V_20 -> V_21 [ V_115 ] ;
V_73 = F_39 ( V_138 ) ;
if ( V_73 >= V_21 -> V_34 )
return - V_114 ;
V_5 = & V_21 -> V_5 [ V_73 ] ;
V_139 = F_40 ( V_138 ) ;
F_44 ( & V_20 -> V_130 ) ;
if ( F_36 ( V_73 , V_21 -> V_75 ) &&
V_5 -> V_109 == V_109 &&
! ( ( V_5 -> V_16 ^ V_139 ) & V_44 ) ) {
F_48 ( V_24 , V_21 , V_73 ) ;
if ( V_21 -> V_134 == 0 )
F_7 ( V_21 ) ;
V_126 = 0 ;
} else {
V_126 = - V_114 ;
}
F_47 ( & V_20 -> V_130 ) ;
return V_126 ;
}
int F_51 ( struct V_23 * V_24 ,
enum V_137 V_109 ,
T_2 V_138 , struct V_4 * V_141 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
struct V_18 * V_21 ;
struct V_4 * V_5 ;
unsigned int V_73 ;
T_6 V_139 ;
int V_126 ;
V_115 = F_38 ( V_138 ) ;
if ( ( unsigned int ) V_115 >= V_140 )
return - V_114 ;
V_21 = & V_20 -> V_21 [ V_115 ] ;
V_73 = F_39 ( V_138 ) ;
if ( V_73 >= V_21 -> V_34 )
return - V_114 ;
V_5 = & V_21 -> V_5 [ V_73 ] ;
V_139 = F_40 ( V_138 ) ;
F_44 ( & V_20 -> V_130 ) ;
if ( F_36 ( V_73 , V_21 -> V_75 ) &&
V_5 -> V_109 == V_109 &&
! ( ( V_5 -> V_16 ^ V_139 ) & V_44 ) ) {
* V_141 = * V_5 ;
V_126 = 0 ;
} else {
V_126 = - V_114 ;
}
F_47 ( & V_20 -> V_130 ) ;
return V_126 ;
}
static void F_52 ( struct V_23 * V_24 ,
enum V_3 V_115 ,
enum V_137 V_109 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_115 ] ;
unsigned int V_73 ;
F_44 ( & V_20 -> V_130 ) ;
for ( V_73 = 0 ; V_73 < V_21 -> V_34 ; ++ V_73 )
if ( V_21 -> V_5 [ V_73 ] . V_109 <= V_109 )
F_48 ( V_24 , V_21 , V_73 ) ;
if ( V_21 -> V_134 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_130 ) ;
}
void F_53 ( struct V_23 * V_24 , enum V_137 V_109 )
{
F_52 ( V_24 , V_6 , V_109 ) ;
F_52 ( V_24 , V_11 , V_109 ) ;
}
T_2 F_54 ( struct V_23 * V_24 ,
enum V_137 V_109 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
struct V_18 * V_21 ;
unsigned int V_73 ;
T_2 V_142 = 0 ;
F_44 ( & V_20 -> V_130 ) ;
for ( V_115 = V_6 ;
V_115 <= V_37 ;
V_115 ++ ) {
V_21 = & V_20 -> V_21 [ V_115 ] ;
for ( V_73 = 0 ; V_73 < V_21 -> V_34 ; V_73 ++ ) {
if ( F_36 ( V_73 , V_21 -> V_75 ) &&
V_21 -> V_5 [ V_73 ] . V_109 == V_109 )
++ V_142 ;
}
}
F_47 ( & V_20 -> V_130 ) ;
return V_142 ;
}
T_7 F_55 ( struct V_23 * V_24 ,
enum V_137 V_109 ,
T_2 * V_143 , T_2 V_34 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
struct V_18 * V_21 ;
unsigned int V_73 ;
T_7 V_142 = 0 ;
F_44 ( & V_20 -> V_130 ) ;
for ( V_115 = V_6 ;
V_115 <= V_37 ;
V_115 ++ ) {
V_21 = & V_20 -> V_21 [ V_115 ] ;
for ( V_73 = 0 ; V_73 < V_21 -> V_34 ; V_73 ++ ) {
if ( F_36 ( V_73 , V_21 -> V_75 ) &&
V_21 -> V_5 [ V_73 ] . V_109 == V_109 ) {
if ( V_142 == V_34 ) {
V_142 = - V_144 ;
goto V_131;
}
V_143 [ V_142 ++ ] = F_37 (
V_115 , V_73 ,
V_21 -> V_5 [ V_73 ] . V_16 ) ;
}
}
}
V_131:
F_47 ( & V_20 -> V_130 ) ;
return V_142 ;
}
void F_56 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
struct V_18 * V_21 ;
T_3 V_76 ;
unsigned int V_73 ;
F_44 ( & V_20 -> V_130 ) ;
for ( V_115 = 0 ; V_115 < V_140 ; V_115 ++ ) {
V_21 = & V_20 -> V_21 [ V_115 ] ;
if ( V_21 -> V_136 == 0 )
continue;
for ( V_73 = 0 ; V_73 < V_21 -> V_34 ; V_73 ++ ) {
if ( ! F_36 ( V_73 , V_21 -> V_75 ) )
continue;
F_29 ( & V_76 , & V_21 -> V_5 [ V_73 ] ) ;
F_11 ( V_24 , & V_76 ,
V_21 -> V_135 + V_21 -> V_136 * V_73 ) ;
}
}
F_8 ( V_24 ) ;
F_12 ( V_24 ) ;
F_47 ( & V_20 -> V_130 ) ;
}
int F_57 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
unsigned V_115 ;
V_20 = F_58 ( sizeof( * V_24 -> V_25 ) , V_145 ) ;
if ( ! V_20 )
return - V_146 ;
V_24 -> V_25 = V_20 ;
F_59 ( & V_20 -> V_130 ) ;
if ( F_60 ( V_24 ) >= V_147 ) {
#ifdef F_61
V_20 -> V_148 = F_62 ( V_149 ,
sizeof( * V_20 -> V_148 ) ,
V_145 ) ;
if ( ! V_20 -> V_148 )
goto V_150;
#endif
V_21 = & V_20 -> V_21 [ V_6 ] ;
V_21 -> V_122 = V_6 ;
V_21 -> V_135 = V_151 ;
V_21 -> V_34 = V_149 ;
V_21 -> V_136 = V_152 ;
}
if ( F_60 ( V_24 ) >= V_153 ) {
V_21 = & V_20 -> V_21 [ V_11 ] ;
V_21 -> V_122 = V_11 ;
V_21 -> V_135 = V_154 ;
V_21 -> V_34 = V_155 ;
V_21 -> V_136 = V_156 ;
V_21 = & V_20 -> V_21 [ V_37 ] ;
V_21 -> V_122 = V_37 ;
V_21 -> V_34 = V_157 ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
V_21 -> V_122 = V_14 ;
V_21 -> V_135 = V_158 ;
V_21 -> V_34 = V_159 ;
V_21 -> V_136 = V_160 ;
}
for ( V_115 = 0 ; V_115 < V_140 ; V_115 ++ ) {
V_21 = & V_20 -> V_21 [ V_115 ] ;
if ( V_21 -> V_34 == 0 )
continue;
V_21 -> V_75 = F_62 ( F_63 ( V_21 -> V_34 ) ,
sizeof( unsigned long ) ,
V_145 ) ;
if ( ! V_21 -> V_75 )
goto V_150;
V_21 -> V_5 = F_64 ( V_21 -> V_34 * sizeof( * V_21 -> V_5 ) ) ;
if ( ! V_21 -> V_5 )
goto V_150;
}
if ( V_20 -> V_21 [ V_37 ] . V_34 ) {
unsigned V_161 ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ )
F_26 ( V_24 , V_161 ) ;
}
F_8 ( V_24 ) ;
return 0 ;
V_150:
F_65 ( V_24 ) ;
return - V_146 ;
}
void F_65 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_115 ;
for ( V_115 = 0 ; V_115 < V_140 ; V_115 ++ ) {
F_66 ( V_20 -> V_21 [ V_115 ] . V_75 ) ;
F_67 ( V_20 -> V_21 [ V_115 ] . V_5 ) ;
}
#ifdef F_61
F_66 ( V_20 -> V_148 ) ;
#endif
F_66 ( V_20 ) ;
}
int F_68 ( struct V_162 * V_128 , const struct V_163 * V_164 ,
T_1 V_165 , T_2 V_166 )
{
struct V_23 * V_24 = F_69 ( V_128 ) ;
struct V_167 * V_168 ;
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_4 V_5 ;
const struct V_169 * V_170 ;
const T_5 * V_171 ;
int V_172 ;
int V_126 ;
V_172 = F_70 ( V_164 ) ;
if ( V_164 -> V_173 != F_18 ( V_174 ) )
return - V_62 ;
F_5 ( F_71 ( V_164 ) < V_172 + sizeof( * V_170 ) ) ;
V_170 = ( const struct V_169 * ) ( V_164 -> V_57 + V_172 ) ;
if ( F_72 ( V_170 ) )
return - V_62 ;
F_5 ( F_71 ( V_164 ) < V_172 + 4 * V_170 -> V_175 + 4 ) ;
V_171 = ( const T_5 * ) ( V_164 -> V_57 + V_172 + 4 * V_170 -> V_175 ) ;
F_27 ( & V_5 , V_110 , 0 , V_165 ) ;
V_126 = F_21 ( & V_5 , V_170 -> V_173 ,
V_170 -> V_176 , V_171 [ 1 ] , V_170 -> V_177 , V_171 [ 0 ] ) ;
if ( V_126 )
return V_126 ;
V_126 = F_42 ( V_24 , & V_5 , true ) ;
if ( V_126 < 0 )
return V_126 ;
V_20 -> V_148 [ V_126 ] = V_166 ;
V_168 = F_73 ( V_24 , F_74 ( V_164 ) ) ;
++ V_168 -> V_178 ;
F_75 ( V_24 , V_179 , V_24 -> V_128 ,
L_3 ,
( V_170 -> V_173 == V_64 ) ? L_4 : L_5 ,
& V_170 -> V_177 , F_15 ( V_171 [ 0 ] ) , & V_170 -> V_176 , F_15 ( V_171 [ 1 ] ) ,
V_165 , V_166 , V_126 ) ;
return V_126 ;
}
bool F_76 ( struct V_23 * V_24 , unsigned V_180 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_6 ] ;
unsigned V_181 = V_21 -> V_34 - 1 ;
unsigned V_116 ;
unsigned V_182 ;
if ( ! F_77 ( & V_20 -> V_130 ) )
return false ;
V_116 = V_20 -> V_183 ;
V_182 = ( V_116 + V_180 ) & V_181 ;
while ( V_116 != V_182 ) {
if ( F_36 ( V_116 , V_21 -> V_75 ) &&
V_21 -> V_5 [ V_116 ] . V_109 == V_110 &&
F_78 ( V_24 -> V_128 ,
V_21 -> V_5 [ V_116 ] . V_40 ,
V_20 -> V_148 [ V_116 ] , V_116 ) ) {
F_75 ( V_24 , V_179 , V_24 -> V_128 ,
L_6 ,
V_116 , V_20 -> V_148 [ V_116 ] ) ;
F_48 ( V_24 , V_21 , V_116 ) ;
}
V_116 = ( V_116 + 1 ) & V_181 ;
}
V_20 -> V_183 = V_182 ;
if ( V_21 -> V_134 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_130 ) ;
return true ;
}
