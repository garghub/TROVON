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
F_5 ( V_5 -> type == V_14 ) ;
return V_5 -> type >> 2 ;
}
static struct V_15 *
F_6 ( struct V_16 * V_17 ,
const struct V_4 * V_5 )
{
if ( V_5 -> type == V_14 )
return NULL ;
else
return & V_17 -> V_18 [ F_3 ( V_5 ) ] ;
}
static void F_7 ( struct V_15 * V_18 )
{
memset ( V_18 -> V_19 , 0 , sizeof( V_18 -> V_19 ) ) ;
}
static void F_8 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 ;
T_3 V_23 ;
F_9 ( V_21 , & V_23 , V_24 ) ;
V_18 = & V_17 -> V_18 [ V_6 ] ;
F_10 ( V_23 , V_25 ,
V_18 -> V_19 [ V_7 ] +
V_26 ) ;
F_10 ( V_23 , V_27 ,
V_18 -> V_19 [ V_8 ] +
V_28 ) ;
F_10 ( V_23 , V_29 ,
V_18 -> V_19 [ V_9 ] +
V_26 ) ;
F_10 ( V_23 , V_30 ,
V_18 -> V_19 [ V_10 ] +
V_28 ) ;
V_18 = & V_17 -> V_18 [ V_11 ] ;
if ( V_18 -> V_31 ) {
F_10 (
V_23 , V_32 ,
V_18 -> V_19 [ V_12 ] +
V_26 ) ;
F_10 (
V_23 , V_33 ,
V_18 -> V_19 [ V_13 ] +
V_28 ) ;
}
F_11 ( V_21 , & V_23 , V_24 ) ;
}
static inline void F_12 ( struct V_4 * V_5 ,
T_4 V_34 , T_5 V_35 ,
T_4 V_36 , T_5 V_37 )
{
V_5 -> V_38 [ 0 ] = F_13 ( V_34 ) << 16 | F_14 ( V_35 ) ;
V_5 -> V_38 [ 1 ] = F_14 ( V_37 ) << 16 | F_13 ( V_34 ) >> 16 ;
V_5 -> V_38 [ 2 ] = F_13 ( V_36 ) ;
}
int F_15 ( struct V_4 * V_5 , T_6 V_39 ,
T_4 V_40 , T_5 V_41 )
{
T_4 V_34 ;
T_5 V_35 ;
F_5 ( ! ( V_5 -> V_42 & V_43 ) ) ;
if ( V_5 -> type != V_14 )
return - V_44 ;
if ( V_41 == 0 )
return - V_45 ;
switch ( V_39 ) {
case V_46 :
V_5 -> type = V_8 ;
break;
case V_47 :
V_5 -> type = V_10 ;
break;
default:
return - V_44 ;
}
V_34 = 0 ;
if ( V_39 != V_47 ) {
V_35 = 0 ;
} else {
V_35 = V_41 ;
V_41 = 0 ;
}
F_12 ( V_5 , V_34 , V_35 , V_40 , V_41 ) ;
return 0 ;
}
int F_16 ( struct V_4 * V_5 , T_6 V_39 ,
T_4 V_40 , T_5 V_41 ,
T_4 V_48 , T_5 V_49 )
{
F_5 ( ! ( V_5 -> V_42 & V_43 ) ) ;
if ( V_5 -> type != V_14 )
return - V_44 ;
if ( V_41 == 0 || V_49 == 0 )
return - V_45 ;
switch ( V_39 ) {
case V_46 :
V_5 -> type = V_7 ;
break;
case V_47 :
V_5 -> type = V_9 ;
break;
default:
return - V_44 ;
}
F_12 ( V_5 , V_48 , V_49 , V_40 , V_41 ) ;
return 0 ;
}
int F_17 ( struct V_4 * V_5 ,
T_1 V_50 , const T_6 * V_51 )
{
F_5 ( ! ( V_5 -> V_42 & V_43 ) ) ;
if ( V_5 -> type != V_14 )
return - V_44 ;
if ( V_50 == V_52 ) {
V_5 -> type = V_13 ;
V_5 -> V_38 [ 0 ] = 0 ;
} else {
V_5 -> type = V_12 ;
V_5 -> V_38 [ 0 ] = V_50 ;
}
V_5 -> V_38 [ 1 ] = V_51 [ 2 ] << 24 | V_51 [ 3 ] << 16 | V_51 [ 4 ] << 8 | V_51 [ 5 ] ;
V_5 -> V_38 [ 2 ] = V_51 [ 0 ] << 8 | V_51 [ 1 ] ;
return 0 ;
}
static T_2 F_18 ( T_3 * V_53 , struct V_4 * V_5 )
{
T_2 V_54 ;
switch ( F_3 ( V_5 ) ) {
case V_6 : {
bool V_55 = ( V_5 -> type == V_9 ||
V_5 -> type == V_10 ) ;
F_19 (
* V_53 ,
V_56 ,
! ! ( V_5 -> V_42 & V_57 ) ,
V_58 ,
! ! ( V_5 -> V_42 & V_59 ) ,
V_60 , V_55 ,
V_61 , V_5 -> V_62 ,
V_63 , V_5 -> V_38 [ 2 ] ,
V_64 , V_5 -> V_38 [ 1 ] ,
V_65 , V_5 -> V_38 [ 0 ] ) ;
V_54 = V_55 ;
break;
}
case V_11 : {
bool V_66 = V_5 -> type == V_13 ;
F_20 (
* V_53 ,
V_67 ,
! ! ( V_5 -> V_42 & V_57 ) ,
V_68 ,
! ! ( V_5 -> V_42 & V_59 ) ,
V_69 ,
! ! ( V_5 -> V_42 & V_70 ) ,
V_71 , V_5 -> V_62 ,
V_72 , V_66 ,
V_73 , V_5 -> V_38 [ 2 ] ,
V_74 , V_5 -> V_38 [ 1 ] ,
V_75 , V_5 -> V_38 [ 0 ] ) ;
V_54 = V_66 ;
break;
}
default:
F_21 () ;
}
return V_5 -> V_38 [ 0 ] ^ V_5 -> V_38 [ 1 ] ^ V_5 -> V_38 [ 2 ] ^ V_54 ;
}
static bool F_22 ( const struct V_4 * V_76 ,
const struct V_4 * V_77 )
{
if ( V_76 -> type != V_77 -> type ||
memcmp ( V_76 -> V_38 , V_77 -> V_38 , sizeof( V_76 -> V_38 ) ) )
return false ;
return true ;
}
static int F_23 ( struct V_15 * V_18 ,
struct V_4 * V_5 , T_2 V_1 ,
bool V_78 , int * V_79 )
{
unsigned V_80 , V_81 , V_82 , V_83 , V_84 ;
V_80 = F_1 ( V_1 ) ;
V_81 = F_2 ( V_1 ) ;
V_82 = V_80 & ( V_18 -> V_31 - 1 ) ;
V_83 = 1 ;
V_84 = ( V_78 ?
( V_5 -> V_85 <= V_86 ?
V_87 : V_88 ) :
V_18 -> V_19 [ V_5 -> type ] ) ;
for (; ; ) {
if ( F_24 ( V_82 , V_18 -> V_89 ) ?
F_22 ( V_5 , & V_18 -> V_5 [ V_82 ] ) :
V_78 ) {
* V_79 = V_83 ;
return V_82 ;
}
if ( V_83 == V_84 )
return V_78 ? - V_90 : - V_91 ;
V_82 = ( V_82 + V_81 ) & ( V_18 -> V_31 - 1 ) ;
++ V_83 ;
}
}
static inline int
F_25 ( enum V_3 V_92 , unsigned V_93 )
{
return V_92 << 16 | V_93 ;
}
int F_26 ( struct V_20 * V_21 , struct V_4 * V_5 ,
bool V_94 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = F_6 ( V_17 , V_5 ) ;
struct V_4 * V_95 ;
T_3 V_53 ;
int V_82 , V_83 ;
T_2 V_1 ;
int V_96 ;
if ( ! V_18 || V_18 -> V_31 == 0 )
return - V_45 ;
V_1 = F_18 ( & V_53 , V_5 ) ;
F_27 ( V_21 , V_97 , V_21 -> V_98 ,
L_1 , V_99 , V_5 -> type ,
V_18 -> V_19 [ V_5 -> type ] ) ;
F_28 ( & V_17 -> V_100 ) ;
V_96 = F_23 ( V_18 , V_5 , V_1 , true , & V_83 ) ;
if ( V_96 < 0 )
goto V_101;
V_82 = V_96 ;
F_29 ( V_82 >= V_18 -> V_31 ) ;
V_95 = & V_18 -> V_5 [ V_82 ] ;
if ( F_24 ( V_82 , V_18 -> V_89 ) ) {
if ( ! V_94 ) {
V_96 = - V_102 ;
goto V_101;
}
if ( V_5 -> V_85 < V_95 -> V_85 ) {
V_96 = - V_103 ;
goto V_101;
}
} else {
F_30 ( V_82 , V_18 -> V_89 ) ;
++ V_18 -> V_104 ;
}
* V_95 = * V_5 ;
if ( V_18 -> V_19 [ V_5 -> type ] < V_83 ) {
V_18 -> V_19 [ V_5 -> type ] = V_83 ;
F_8 ( V_21 ) ;
}
F_11 ( V_21 , & V_53 , V_18 -> V_105 + V_18 -> V_106 * V_82 ) ;
F_27 ( V_21 , V_97 , V_21 -> V_98 ,
L_2 ,
V_99 , V_5 -> type , V_82 , V_5 -> V_62 ) ;
V_96 = F_25 ( V_18 -> V_107 , V_82 ) ;
V_101:
F_31 ( & V_17 -> V_100 ) ;
return V_96 ;
}
static void F_32 ( struct V_20 * V_21 ,
struct V_15 * V_18 ,
int V_82 )
{
static T_3 V_53 ;
if ( F_24 ( V_82 , V_18 -> V_89 ) ) {
F_33 ( V_82 , V_18 -> V_89 ) ;
-- V_18 -> V_104 ;
memset ( & V_18 -> V_5 [ V_82 ] , 0 , sizeof( V_18 -> V_5 [ 0 ] ) ) ;
F_11 ( V_21 , & V_53 ,
V_18 -> V_105 + V_18 -> V_106 * V_82 ) ;
}
}
int F_34 ( struct V_20 * V_21 , struct V_4 * V_5 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = F_6 ( V_17 , V_5 ) ;
struct V_4 * V_95 ;
T_3 V_53 ;
int V_82 , V_83 ;
T_2 V_1 ;
int V_96 ;
if ( ! V_18 )
return - V_45 ;
V_1 = F_18 ( & V_53 , V_5 ) ;
F_28 ( & V_17 -> V_100 ) ;
V_96 = F_23 ( V_18 , V_5 , V_1 , false , & V_83 ) ;
if ( V_96 < 0 )
goto V_101;
V_82 = V_96 ;
V_95 = & V_18 -> V_5 [ V_82 ] ;
if ( V_5 -> V_85 < V_95 -> V_85 ) {
V_96 = - V_103 ;
goto V_101;
}
F_32 ( V_21 , V_18 , V_82 ) ;
if ( V_18 -> V_104 == 0 )
F_7 ( V_18 ) ;
V_96 = 0 ;
V_101:
F_31 ( & V_17 -> V_100 ) ;
return V_96 ;
}
static void F_35 ( struct V_20 * V_21 ,
enum V_3 V_92 ,
enum V_108 V_85 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = & V_17 -> V_18 [ V_92 ] ;
int V_82 ;
F_28 ( & V_17 -> V_100 ) ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; ++ V_82 )
if ( V_18 -> V_5 [ V_82 ] . V_85 <= V_85 )
F_32 ( V_21 , V_18 , V_82 ) ;
if ( V_18 -> V_104 == 0 )
F_7 ( V_18 ) ;
F_31 ( & V_17 -> V_100 ) ;
}
void F_36 ( struct V_20 * V_21 , enum V_108 V_85 )
{
F_35 ( V_21 , V_6 , V_85 ) ;
F_35 ( V_21 , V_11 , V_85 ) ;
}
void F_37 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
T_3 V_53 ;
int V_82 ;
F_28 ( & V_17 -> V_100 ) ;
for ( V_92 = 0 ; V_92 < V_109 ; V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; V_82 ++ ) {
if ( ! F_24 ( V_82 , V_18 -> V_89 ) )
continue;
F_18 ( & V_53 , & V_18 -> V_5 [ V_82 ] ) ;
F_11 ( V_21 , & V_53 ,
V_18 -> V_105 + V_18 -> V_106 * V_82 ) ;
}
}
F_8 ( V_21 ) ;
F_31 ( & V_17 -> V_100 ) ;
}
int F_38 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
struct V_15 * V_18 ;
unsigned V_92 ;
V_17 = F_39 ( sizeof( * V_21 -> V_22 ) , V_110 ) ;
if ( ! V_17 )
return - V_111 ;
V_21 -> V_22 = V_17 ;
F_40 ( & V_17 -> V_100 ) ;
if ( F_41 ( V_21 ) >= V_112 ) {
#ifdef F_42
V_17 -> V_113 = F_43 ( V_114 ,
sizeof( * V_17 -> V_113 ) ,
V_110 ) ;
if ( ! V_17 -> V_113 )
goto V_115;
#endif
V_18 = & V_17 -> V_18 [ V_6 ] ;
V_18 -> V_107 = V_6 ;
V_18 -> V_105 = V_116 ;
V_18 -> V_31 = V_114 ;
V_18 -> V_106 = V_117 ;
}
if ( F_41 ( V_21 ) >= V_118 ) {
V_18 = & V_17 -> V_18 [ V_11 ] ;
V_18 -> V_107 = V_11 ;
V_18 -> V_105 = V_119 ;
V_18 -> V_31 = V_120 ;
V_18 -> V_106 = V_121 ;
}
for ( V_92 = 0 ; V_92 < V_109 ; V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
if ( V_18 -> V_31 == 0 )
continue;
V_18 -> V_89 = F_43 ( F_44 ( V_18 -> V_31 ) ,
sizeof( unsigned long ) ,
V_110 ) ;
if ( ! V_18 -> V_89 )
goto V_115;
V_18 -> V_5 = F_45 ( V_18 -> V_31 * sizeof( * V_18 -> V_5 ) ) ;
if ( ! V_18 -> V_5 )
goto V_115;
}
return 0 ;
V_115:
F_46 ( V_21 ) ;
return - V_111 ;
}
void F_46 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
for ( V_92 = 0 ; V_92 < V_109 ; V_92 ++ ) {
F_47 ( V_17 -> V_18 [ V_92 ] . V_89 ) ;
F_48 ( V_17 -> V_18 [ V_92 ] . V_5 ) ;
}
#ifdef F_42
F_47 ( V_17 -> V_113 ) ;
#endif
F_47 ( V_17 ) ;
}
int F_49 ( struct V_122 * V_98 , const struct V_123 * V_124 ,
T_1 V_125 , T_2 V_126 )
{
struct V_20 * V_21 = F_50 ( V_98 ) ;
struct V_127 * V_128 ;
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_4 V_5 ;
const struct V_129 * V_130 ;
const T_5 * V_131 ;
int V_132 ;
int V_96 ;
V_132 = F_51 ( V_124 ) ;
if ( V_124 -> V_133 != F_52 ( V_134 ) )
return - V_44 ;
F_5 ( F_53 ( V_124 ) < V_132 + sizeof( * V_130 ) ) ;
V_130 = ( const struct V_129 * ) ( V_124 -> V_38 + V_132 ) ;
if ( F_54 ( V_130 ) )
return - V_44 ;
F_5 ( F_53 ( V_124 ) < V_132 + 4 * V_130 -> V_135 + 4 ) ;
V_131 = ( const T_5 * ) ( V_124 -> V_38 + V_132 + 4 * V_130 -> V_135 ) ;
F_55 ( & V_5 , V_86 , 0 , V_125 ) ;
V_96 = F_16 ( & V_5 , V_130 -> V_133 ,
V_130 -> V_136 , V_131 [ 1 ] , V_130 -> V_137 , V_131 [ 0 ] ) ;
if ( V_96 )
return V_96 ;
V_96 = F_26 ( V_21 , & V_5 , true ) ;
if ( V_96 < 0 )
return V_96 ;
V_17 -> V_113 [ V_96 ] = V_126 ;
V_128 = F_56 ( V_21 , F_57 ( V_124 ) ) ;
++ V_128 -> V_138 ;
F_58 ( V_21 , V_139 , V_21 -> V_98 ,
L_3 ,
( V_130 -> V_133 == V_46 ) ? L_4 : L_5 ,
& V_130 -> V_137 , F_14 ( V_131 [ 0 ] ) , & V_130 -> V_136 , F_14 ( V_131 [ 1 ] ) ,
V_125 , V_126 , V_96 ) ;
return V_96 ;
}
bool F_59 ( struct V_20 * V_21 , unsigned V_140 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = & V_17 -> V_18 [ V_6 ] ;
unsigned V_141 = V_18 -> V_31 - 1 ;
unsigned V_93 ;
unsigned V_142 ;
if ( ! F_60 ( & V_17 -> V_100 ) )
return false ;
V_93 = V_17 -> V_143 ;
V_142 = ( V_93 + V_140 ) & V_141 ;
while ( V_93 != V_142 ) {
if ( F_24 ( V_93 , V_18 -> V_89 ) &&
V_18 -> V_5 [ V_93 ] . V_85 == V_86 &&
F_61 ( V_21 -> V_98 ,
V_18 -> V_5 [ V_93 ] . V_62 ,
V_17 -> V_113 [ V_93 ] , V_93 ) ) {
F_58 ( V_21 , V_139 , V_21 -> V_98 ,
L_6 ,
V_93 , V_17 -> V_113 [ V_93 ] ) ;
F_32 ( V_21 , V_18 , V_93 ) ;
}
V_93 = ( V_93 + 1 ) & V_141 ;
}
V_17 -> V_143 = V_142 ;
if ( V_18 -> V_104 == 0 )
F_7 ( V_18 ) ;
F_31 ( & V_17 -> V_100 ) ;
return true ;
}
