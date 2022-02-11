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
}
F_11 ( V_24 , & V_26 , V_27 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 ;
T_3 V_46 ;
F_9 ( V_24 , & V_46 , V_47 ) ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
if ( V_21 -> V_34 ) {
F_10 (
V_46 , V_48 ,
V_21 -> V_22 [ V_12 ] +
V_29 ) ;
F_10 (
V_46 , V_49 ,
V_21 -> V_22 [ V_13 ] +
V_31 ) ;
}
F_11 ( V_24 , & V_46 , V_47 ) ;
}
static inline void F_13 ( struct V_4 * V_5 ,
T_4 V_50 , T_5 V_51 ,
T_4 V_52 , T_5 V_53 )
{
V_5 -> V_54 [ 0 ] = F_14 ( V_50 ) << 16 | F_15 ( V_51 ) ;
V_5 -> V_54 [ 1 ] = F_15 ( V_53 ) << 16 | F_14 ( V_50 ) >> 16 ;
V_5 -> V_54 [ 2 ] = F_14 ( V_52 ) ;
}
static inline void F_16 ( const struct V_4 * V_5 ,
T_4 * V_50 , T_5 * V_51 ,
T_4 * V_52 , T_5 * V_53 )
{
* V_50 = F_17 ( V_5 -> V_54 [ 0 ] >> 16 | V_5 -> V_54 [ 1 ] << 16 ) ;
* V_51 = F_18 ( V_5 -> V_54 [ 0 ] ) ;
* V_52 = F_17 ( V_5 -> V_54 [ 2 ] ) ;
* V_53 = F_18 ( V_5 -> V_54 [ 1 ] >> 16 ) ;
}
int F_19 ( struct V_4 * V_5 , T_6 V_55 ,
T_4 V_56 , T_5 V_57 )
{
T_4 V_50 ;
T_5 V_51 ;
F_5 ( ! ( V_5 -> V_16 & V_58 ) ) ;
if ( V_5 -> type != V_15 )
return - V_59 ;
if ( V_57 == 0 )
return - V_60 ;
switch ( V_55 ) {
case V_61 :
V_5 -> type = V_8 ;
break;
case V_62 :
V_5 -> type = V_10 ;
break;
default:
return - V_59 ;
}
V_50 = 0 ;
if ( V_55 != V_62 ) {
V_51 = 0 ;
} else {
V_51 = V_57 ;
V_57 = 0 ;
}
F_13 ( V_5 , V_50 , V_51 , V_56 , V_57 ) ;
return 0 ;
}
int F_20 ( const struct V_4 * V_5 ,
T_6 * V_55 , T_4 * V_56 , T_5 * V_57 )
{
T_4 V_50 ;
T_5 V_51 ;
switch ( V_5 -> type ) {
case V_8 :
* V_55 = V_61 ;
F_16 ( V_5 , & V_50 , & V_51 , V_56 , V_57 ) ;
return 0 ;
case V_10 :
* V_55 = V_62 ;
F_16 ( V_5 , & V_50 , V_57 , V_56 , & V_51 ) ;
return 0 ;
default:
return - V_60 ;
}
}
int F_21 ( struct V_4 * V_5 , T_6 V_55 ,
T_4 V_56 , T_5 V_57 ,
T_4 V_63 , T_5 V_64 )
{
F_5 ( ! ( V_5 -> V_16 & V_58 ) ) ;
if ( V_5 -> type != V_15 )
return - V_59 ;
if ( V_57 == 0 || V_64 == 0 )
return - V_60 ;
switch ( V_55 ) {
case V_61 :
V_5 -> type = V_7 ;
break;
case V_62 :
V_5 -> type = V_9 ;
break;
default:
return - V_59 ;
}
F_13 ( V_5 , V_63 , V_64 , V_56 , V_57 ) ;
return 0 ;
}
int F_22 ( const struct V_4 * V_5 ,
T_6 * V_55 , T_4 * V_56 , T_5 * V_57 ,
T_4 * V_63 , T_5 * V_64 )
{
switch ( V_5 -> type ) {
case V_7 :
* V_55 = V_61 ;
break;
case V_9 :
* V_55 = V_62 ;
break;
default:
return - V_60 ;
}
F_16 ( V_5 , V_63 , V_64 , V_56 , V_57 ) ;
return 0 ;
}
int F_23 ( struct V_4 * V_5 ,
T_1 V_65 , const T_6 * V_66 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_58 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_59 ;
if ( V_65 == V_67 ) {
V_5 -> type = V_13 ;
V_5 -> V_54 [ 0 ] = 0 ;
} else {
V_5 -> type = V_12 ;
V_5 -> V_54 [ 0 ] = V_65 ;
}
V_5 -> V_54 [ 1 ] = V_66 [ 2 ] << 24 | V_66 [ 3 ] << 16 | V_66 [ 4 ] << 8 | V_66 [ 5 ] ;
V_5 -> V_54 [ 2 ] = V_66 [ 0 ] << 8 | V_66 [ 1 ] ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_58 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_60 ;
V_5 -> type = V_68 ;
memset ( V_5 -> V_54 , 0 , sizeof( V_5 -> V_54 ) ) ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
F_5 ( ! ( V_5 -> V_16 &
( V_58 | V_17 ) ) ) ;
if ( V_5 -> type != V_15 )
return - V_60 ;
V_5 -> type = V_69 ;
memset ( V_5 -> V_54 , 0 , sizeof( V_5 -> V_54 ) ) ;
return 0 ;
}
static void F_26 ( struct V_23 * V_24 , unsigned V_70 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_37 ] ;
struct V_4 * V_5 = & V_21 -> V_5 [ V_70 ] ;
F_27 ( V_5 , V_71 ,
V_42 , 0 ) ;
V_5 -> type = V_68 + V_70 ;
V_21 -> V_72 [ 0 ] |= 1 << V_70 ;
}
int F_28 ( const struct V_4 * V_5 ,
T_1 * V_65 , T_6 * V_66 )
{
switch ( V_5 -> type ) {
case V_13 :
* V_65 = V_67 ;
break;
case V_12 :
* V_65 = V_5 -> V_54 [ 0 ] ;
break;
default:
return - V_60 ;
}
V_66 [ 0 ] = V_5 -> V_54 [ 2 ] >> 8 ;
V_66 [ 1 ] = V_5 -> V_54 [ 2 ] ;
V_66 [ 2 ] = V_5 -> V_54 [ 1 ] >> 24 ;
V_66 [ 3 ] = V_5 -> V_54 [ 1 ] >> 16 ;
V_66 [ 4 ] = V_5 -> V_54 [ 1 ] >> 8 ;
V_66 [ 5 ] = V_5 -> V_54 [ 1 ] ;
return 0 ;
}
static T_2 F_29 ( T_3 * V_73 , struct V_4 * V_5 )
{
T_2 V_74 ;
switch ( F_3 ( V_5 ) ) {
case V_6 : {
bool V_75 = ( V_5 -> type == V_9 ||
V_5 -> type == V_10 ) ;
F_30 (
* V_73 ,
V_76 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_77 ,
! ! ( V_5 -> V_16 & V_78 ) ,
V_79 , V_75 ,
V_80 , V_5 -> V_40 ,
V_81 , V_5 -> V_54 [ 2 ] ,
V_82 , V_5 -> V_54 [ 1 ] ,
V_83 , V_5 -> V_54 [ 0 ] ) ;
V_74 = V_75 ;
break;
}
case V_37 :
F_4 ( V_39 != 0 ) ;
F_4 ( V_44 !=
V_69 - V_68 ) ;
return V_5 -> type - V_68 ;
case V_11 : {
bool V_84 = V_5 -> type == V_13 ;
F_30 (
* V_73 ,
V_85 ,
! ! ( V_5 -> V_16 & V_42 ) ,
V_86 ,
! ! ( V_5 -> V_16 & V_78 ) ,
V_87 , V_5 -> V_40 ,
V_88 , V_84 ,
V_89 , V_5 -> V_54 [ 2 ] ,
V_90 , V_5 -> V_54 [ 1 ] ,
V_91 , V_5 -> V_54 [ 0 ] ) ;
V_74 = V_84 ;
break;
}
case V_14 : {
bool V_84 = V_5 -> type == V_13 ;
F_31 ( * V_73 ,
V_92 , V_5 -> V_40 ,
V_93 , V_84 ,
V_94 , V_5 -> V_54 [ 2 ] ,
V_95 , V_5 -> V_54 [ 1 ] ,
V_96 , V_5 -> V_54 [ 0 ] ) ;
V_74 = V_84 | V_5 -> V_40 << 1 ;
break;
}
default:
F_32 () ;
}
return V_5 -> V_54 [ 0 ] ^ V_5 -> V_54 [ 1 ] ^ V_5 -> V_54 [ 2 ] ^ V_74 ;
}
static bool F_33 ( const struct V_4 * V_97 ,
const struct V_4 * V_98 )
{
if ( V_97 -> type != V_98 -> type ||
memcmp ( V_97 -> V_54 , V_98 -> V_54 , sizeof( V_97 -> V_54 ) ) )
return false ;
if ( V_97 -> V_16 & V_17 &&
V_97 -> V_40 != V_98 -> V_40 )
return false ;
return true ;
}
static int F_34 ( struct V_18 * V_21 ,
struct V_4 * V_5 , T_2 V_1 ,
bool V_99 , unsigned int * V_100 )
{
unsigned V_101 , V_102 , V_70 , V_103 , V_104 ;
V_101 = F_1 ( V_1 ) ;
V_102 = F_2 ( V_1 ) ;
V_70 = V_101 & ( V_21 -> V_34 - 1 ) ;
V_103 = 1 ;
V_104 = ( V_99 ?
( V_5 -> V_105 <= V_106 ?
V_107 : V_108 ) :
V_21 -> V_22 [ V_5 -> type ] ) ;
for (; ; ) {
if ( F_35 ( V_70 , V_21 -> V_72 ) ?
F_33 ( V_5 , & V_21 -> V_5 [ V_70 ] ) :
V_99 ) {
* V_100 = V_103 ;
return V_70 ;
}
if ( V_103 == V_104 )
return V_99 ? - V_109 : - V_110 ;
V_70 = ( V_70 + V_102 ) & ( V_21 -> V_34 - 1 ) ;
++ V_103 ;
}
}
static inline T_2
F_36 ( const struct V_4 * V_5 , unsigned int V_111 )
{
unsigned int V_112 ;
V_112 = V_113 [ V_5 -> type ] ;
if ( ! ( V_5 -> V_16 & V_58 ) )
V_112 += V_114 ;
return V_112 << V_115 | V_111 ;
}
static inline enum V_3 F_37 ( T_2 V_116 )
{
unsigned int V_112 = V_116 >> V_115 ;
if ( V_112 < F_38 ( V_117 ) )
return V_117 [ V_112 ] ;
else
return V_118 ;
}
static inline unsigned int F_39 ( T_2 V_116 )
{
return V_116 & V_119 ;
}
static inline T_6 F_40 ( T_2 V_116 )
{
unsigned int V_112 = V_116 >> V_115 ;
if ( V_112 < V_114 )
return V_58 ;
else
return V_17 ;
}
T_2 F_41 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
unsigned int V_112 = V_114 - 1 ;
enum V_3 V_120 ;
do {
V_120 = V_117 [ V_112 ] ;
if ( V_20 -> V_21 [ V_120 ] . V_34 != 0 )
return V_112 << V_115 |
V_20 -> V_21 [ V_120 ] . V_34 ;
} while ( V_112 -- );
return 0 ;
}
T_7 F_42 ( struct V_23 * V_24 , struct V_4 * V_5 ,
bool V_121 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = F_6 ( V_20 , V_5 ) ;
struct V_4 * V_122 ;
T_3 V_73 ;
unsigned int V_70 , V_103 = 0 ;
T_2 V_1 ;
int V_123 ;
if ( ! V_21 || V_21 -> V_34 == 0 )
return - V_60 ;
V_1 = F_29 ( & V_73 , V_5 ) ;
F_43 ( V_24 , V_124 , V_24 -> V_125 ,
L_1 , V_126 , V_5 -> type ,
V_21 -> V_22 [ V_5 -> type ] ) ;
F_44 ( & V_20 -> V_127 ) ;
V_123 = F_34 ( V_21 , V_5 , V_1 , true , & V_103 ) ;
if ( V_123 < 0 )
goto V_128;
V_70 = V_123 ;
F_45 ( V_70 >= V_21 -> V_34 ) ;
V_122 = & V_21 -> V_5 [ V_70 ] ;
if ( F_35 ( V_70 , V_21 -> V_72 ) ) {
if ( ! V_121 ) {
V_123 = - V_129 ;
goto V_128;
}
if ( V_5 -> V_105 < V_122 -> V_105 ) {
V_123 = - V_130 ;
goto V_128;
}
} else {
F_46 ( V_70 , V_21 -> V_72 ) ;
++ V_21 -> V_131 ;
}
* V_122 = * V_5 ;
if ( V_21 -> V_116 == V_37 ) {
F_8 ( V_24 ) ;
} else {
if ( V_21 -> V_22 [ V_5 -> type ] < V_103 ) {
V_21 -> V_22 [ V_5 -> type ] = V_103 ;
if ( V_5 -> V_16 & V_17 )
F_12 ( V_24 ) ;
else
F_8 ( V_24 ) ;
}
F_11 ( V_24 , & V_73 ,
V_21 -> V_132 + V_21 -> V_133 * V_70 ) ;
}
F_43 ( V_24 , V_124 , V_24 -> V_125 ,
L_2 ,
V_126 , V_5 -> type , V_70 , V_5 -> V_40 ) ;
V_123 = F_36 ( V_5 , V_70 ) ;
V_128:
F_47 ( & V_20 -> V_127 ) ;
return V_123 ;
}
static void F_48 ( struct V_23 * V_24 ,
struct V_18 * V_21 ,
unsigned int V_70 )
{
static T_3 V_73 ;
if ( V_21 -> V_116 == V_37 ) {
F_26 ( V_24 , V_70 ) ;
F_8 ( V_24 ) ;
} else if ( F_35 ( V_70 , V_21 -> V_72 ) ) {
F_49 ( V_70 , V_21 -> V_72 ) ;
-- V_21 -> V_131 ;
memset ( & V_21 -> V_5 [ V_70 ] , 0 , sizeof( V_21 -> V_5 [ 0 ] ) ) ;
F_11 ( V_24 , & V_73 ,
V_21 -> V_132 + V_21 -> V_133 * V_70 ) ;
}
}
int F_50 ( struct V_23 * V_24 ,
enum V_134 V_105 ,
T_2 V_135 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
struct V_18 * V_21 ;
unsigned int V_70 ;
struct V_4 * V_5 ;
T_6 V_136 ;
int V_123 ;
V_120 = F_37 ( V_135 ) ;
if ( ( unsigned int ) V_120 >= V_118 )
return - V_110 ;
V_21 = & V_20 -> V_21 [ V_120 ] ;
V_70 = F_39 ( V_135 ) ;
if ( V_70 >= V_21 -> V_34 )
return - V_110 ;
V_5 = & V_21 -> V_5 [ V_70 ] ;
V_136 = F_40 ( V_135 ) ;
F_44 ( & V_20 -> V_127 ) ;
if ( F_35 ( V_70 , V_21 -> V_72 ) &&
V_5 -> V_105 == V_105 ) {
F_48 ( V_24 , V_21 , V_70 ) ;
if ( V_21 -> V_131 == 0 )
F_7 ( V_21 ) ;
V_123 = 0 ;
} else {
V_123 = - V_110 ;
}
F_47 ( & V_20 -> V_127 ) ;
return V_123 ;
}
int F_51 ( struct V_23 * V_24 ,
enum V_134 V_105 ,
T_2 V_135 , struct V_4 * V_137 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
struct V_18 * V_21 ;
struct V_4 * V_5 ;
unsigned int V_70 ;
T_6 V_136 ;
int V_123 ;
V_120 = F_37 ( V_135 ) ;
if ( ( unsigned int ) V_120 >= V_118 )
return - V_110 ;
V_21 = & V_20 -> V_21 [ V_120 ] ;
V_70 = F_39 ( V_135 ) ;
if ( V_70 >= V_21 -> V_34 )
return - V_110 ;
V_5 = & V_21 -> V_5 [ V_70 ] ;
V_136 = F_40 ( V_135 ) ;
F_44 ( & V_20 -> V_127 ) ;
if ( F_35 ( V_70 , V_21 -> V_72 ) &&
V_5 -> V_105 == V_105 ) {
* V_137 = * V_5 ;
V_123 = 0 ;
} else {
V_123 = - V_110 ;
}
F_47 ( & V_20 -> V_127 ) ;
return V_123 ;
}
static void F_52 ( struct V_23 * V_24 ,
enum V_3 V_120 ,
enum V_134 V_105 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_120 ] ;
unsigned int V_70 ;
F_44 ( & V_20 -> V_127 ) ;
for ( V_70 = 0 ; V_70 < V_21 -> V_34 ; ++ V_70 )
if ( V_21 -> V_5 [ V_70 ] . V_105 <= V_105 )
F_48 ( V_24 , V_21 , V_70 ) ;
if ( V_21 -> V_131 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_127 ) ;
}
void F_53 ( struct V_23 * V_24 , enum V_134 V_105 )
{
F_52 ( V_24 , V_6 , V_105 ) ;
F_52 ( V_24 , V_11 , V_105 ) ;
}
T_2 F_54 ( struct V_23 * V_24 ,
enum V_134 V_105 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
struct V_18 * V_21 ;
unsigned int V_70 ;
T_2 V_138 = 0 ;
F_44 ( & V_20 -> V_127 ) ;
for ( V_120 = V_6 ;
V_120 <= V_37 ;
V_120 ++ ) {
V_21 = & V_20 -> V_21 [ V_120 ] ;
for ( V_70 = 0 ; V_70 < V_21 -> V_34 ; V_70 ++ ) {
if ( F_35 ( V_70 , V_21 -> V_72 ) &&
V_21 -> V_5 [ V_70 ] . V_105 == V_105 )
++ V_138 ;
}
}
F_47 ( & V_20 -> V_127 ) ;
return V_138 ;
}
T_7 F_55 ( struct V_23 * V_24 ,
enum V_134 V_105 ,
T_2 * V_139 , T_2 V_34 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
struct V_18 * V_21 ;
unsigned int V_70 ;
T_7 V_138 = 0 ;
F_44 ( & V_20 -> V_127 ) ;
for ( V_120 = V_6 ;
V_120 <= V_37 ;
V_120 ++ ) {
V_21 = & V_20 -> V_21 [ V_120 ] ;
for ( V_70 = 0 ; V_70 < V_21 -> V_34 ; V_70 ++ ) {
if ( F_35 ( V_70 , V_21 -> V_72 ) &&
V_21 -> V_5 [ V_70 ] . V_105 == V_105 ) {
if ( V_138 == V_34 ) {
V_138 = - V_140 ;
goto V_128;
}
V_139 [ V_138 ++ ] = F_36 (
& V_21 -> V_5 [ V_70 ] , V_70 ) ;
}
}
}
V_128:
F_47 ( & V_20 -> V_127 ) ;
return V_138 ;
}
void F_56 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
struct V_18 * V_21 ;
T_3 V_73 ;
unsigned int V_70 ;
F_44 ( & V_20 -> V_127 ) ;
for ( V_120 = 0 ; V_120 < V_118 ; V_120 ++ ) {
V_21 = & V_20 -> V_21 [ V_120 ] ;
if ( V_21 -> V_133 == 0 )
continue;
for ( V_70 = 0 ; V_70 < V_21 -> V_34 ; V_70 ++ ) {
if ( ! F_35 ( V_70 , V_21 -> V_72 ) )
continue;
F_29 ( & V_73 , & V_21 -> V_5 [ V_70 ] ) ;
F_11 ( V_24 , & V_73 ,
V_21 -> V_132 + V_21 -> V_133 * V_70 ) ;
}
}
F_8 ( V_24 ) ;
F_12 ( V_24 ) ;
F_47 ( & V_20 -> V_127 ) ;
}
int F_57 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
unsigned V_120 ;
V_20 = F_58 ( sizeof( * V_24 -> V_25 ) , V_141 ) ;
if ( ! V_20 )
return - V_142 ;
V_24 -> V_25 = V_20 ;
F_59 ( & V_20 -> V_127 ) ;
if ( F_60 ( V_24 ) >= V_143 ) {
#ifdef F_61
V_20 -> V_144 = F_62 ( V_145 ,
sizeof( * V_20 -> V_144 ) ,
V_141 ) ;
if ( ! V_20 -> V_144 )
goto V_146;
#endif
V_21 = & V_20 -> V_21 [ V_6 ] ;
V_21 -> V_116 = V_6 ;
V_21 -> V_132 = V_147 ;
V_21 -> V_34 = V_145 ;
V_21 -> V_133 = V_148 ;
}
if ( F_60 ( V_24 ) >= V_149 ) {
V_21 = & V_20 -> V_21 [ V_11 ] ;
V_21 -> V_116 = V_11 ;
V_21 -> V_132 = V_150 ;
V_21 -> V_34 = V_151 ;
V_21 -> V_133 = V_152 ;
V_21 = & V_20 -> V_21 [ V_37 ] ;
V_21 -> V_116 = V_37 ;
V_21 -> V_34 = V_153 ;
V_21 = & V_20 -> V_21 [ V_14 ] ;
V_21 -> V_116 = V_14 ;
V_21 -> V_132 = V_154 ;
V_21 -> V_34 = V_155 ;
V_21 -> V_133 = V_156 ;
}
for ( V_120 = 0 ; V_120 < V_118 ; V_120 ++ ) {
V_21 = & V_20 -> V_21 [ V_120 ] ;
if ( V_21 -> V_34 == 0 )
continue;
V_21 -> V_72 = F_62 ( F_63 ( V_21 -> V_34 ) ,
sizeof( unsigned long ) ,
V_141 ) ;
if ( ! V_21 -> V_72 )
goto V_146;
V_21 -> V_5 = F_64 ( V_21 -> V_34 * sizeof( * V_21 -> V_5 ) ) ;
if ( ! V_21 -> V_5 )
goto V_146;
}
if ( V_20 -> V_21 [ V_37 ] . V_34 ) {
unsigned V_157 ;
for ( V_157 = 0 ; V_157 < V_153 ; V_157 ++ )
F_26 ( V_24 , V_157 ) ;
}
F_8 ( V_24 ) ;
return 0 ;
V_146:
F_65 ( V_24 ) ;
return - V_142 ;
}
void F_65 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
enum V_3 V_120 ;
for ( V_120 = 0 ; V_120 < V_118 ; V_120 ++ ) {
F_66 ( V_20 -> V_21 [ V_120 ] . V_72 ) ;
F_67 ( V_20 -> V_21 [ V_120 ] . V_5 ) ;
}
#ifdef F_61
F_66 ( V_20 -> V_144 ) ;
#endif
F_66 ( V_20 ) ;
}
int F_68 ( struct V_158 * V_125 , const struct V_159 * V_160 ,
T_1 V_161 , T_2 V_162 )
{
struct V_23 * V_24 = F_69 ( V_125 ) ;
struct V_163 * V_164 ;
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_4 V_5 ;
const struct V_165 * V_166 ;
const T_5 * V_167 ;
int V_168 ;
int V_123 ;
V_168 = F_70 ( V_160 ) ;
if ( V_160 -> V_169 != F_18 ( V_170 ) )
return - V_59 ;
F_5 ( F_71 ( V_160 ) < V_168 + sizeof( * V_166 ) ) ;
V_166 = ( const struct V_165 * ) ( V_160 -> V_54 + V_168 ) ;
if ( F_72 ( V_166 ) )
return - V_59 ;
F_5 ( F_71 ( V_160 ) < V_168 + 4 * V_166 -> V_171 + 4 ) ;
V_167 = ( const T_5 * ) ( V_160 -> V_54 + V_168 + 4 * V_166 -> V_171 ) ;
F_27 ( & V_5 , V_106 , 0 , V_161 ) ;
V_123 = F_21 ( & V_5 , V_166 -> V_169 ,
V_166 -> V_172 , V_167 [ 1 ] , V_166 -> V_173 , V_167 [ 0 ] ) ;
if ( V_123 )
return V_123 ;
V_123 = F_42 ( V_24 , & V_5 , true ) ;
if ( V_123 < 0 )
return V_123 ;
V_20 -> V_144 [ V_123 ] = V_162 ;
V_164 = F_73 ( V_24 , F_74 ( V_160 ) ) ;
++ V_164 -> V_174 ;
F_75 ( V_24 , V_175 , V_24 -> V_125 ,
L_3 ,
( V_166 -> V_169 == V_61 ) ? L_4 : L_5 ,
& V_166 -> V_173 , F_15 ( V_167 [ 0 ] ) , & V_166 -> V_172 , F_15 ( V_167 [ 1 ] ) ,
V_161 , V_162 , V_123 ) ;
return V_123 ;
}
bool F_76 ( struct V_23 * V_24 , unsigned V_176 )
{
struct V_19 * V_20 = V_24 -> V_25 ;
struct V_18 * V_21 = & V_20 -> V_21 [ V_6 ] ;
unsigned V_177 = V_21 -> V_34 - 1 ;
unsigned V_111 ;
unsigned V_178 ;
if ( ! F_77 ( & V_20 -> V_127 ) )
return false ;
V_111 = V_20 -> V_179 ;
V_178 = ( V_111 + V_176 ) & V_177 ;
while ( V_111 != V_178 ) {
if ( F_35 ( V_111 , V_21 -> V_72 ) &&
V_21 -> V_5 [ V_111 ] . V_105 == V_106 &&
F_78 ( V_24 -> V_125 ,
V_21 -> V_5 [ V_111 ] . V_40 ,
V_20 -> V_144 [ V_111 ] , V_111 ) ) {
F_75 ( V_24 , V_175 , V_24 -> V_125 ,
L_6 ,
V_111 , V_20 -> V_144 [ V_111 ] ) ;
F_48 ( V_24 , V_21 , V_111 ) ;
}
V_111 = ( V_111 + 1 ) & V_177 ;
}
V_20 -> V_179 = V_178 ;
if ( V_21 -> V_131 == 0 )
F_7 ( V_21 ) ;
F_47 ( & V_20 -> V_127 ) ;
return true ;
}
