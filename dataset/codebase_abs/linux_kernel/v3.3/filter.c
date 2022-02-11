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
static inline void F_15 ( const struct V_4 * V_5 ,
T_4 * V_34 , T_5 * V_35 ,
T_4 * V_36 , T_5 * V_37 )
{
* V_34 = F_16 ( V_5 -> V_38 [ 0 ] >> 16 | V_5 -> V_38 [ 1 ] << 16 ) ;
* V_35 = F_17 ( V_5 -> V_38 [ 0 ] ) ;
* V_36 = F_16 ( V_5 -> V_38 [ 2 ] ) ;
* V_37 = F_17 ( V_5 -> V_38 [ 1 ] >> 16 ) ;
}
int F_18 ( struct V_4 * V_5 , T_6 V_39 ,
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
int F_19 ( const struct V_4 * V_5 ,
T_6 * V_39 , T_4 * V_40 , T_5 * V_41 )
{
T_4 V_34 ;
T_5 V_35 ;
switch ( V_5 -> type ) {
case V_8 :
* V_39 = V_46 ;
F_15 ( V_5 , & V_34 , & V_35 , V_40 , V_41 ) ;
return 0 ;
case V_10 :
* V_39 = V_47 ;
F_15 ( V_5 , & V_34 , V_41 , V_40 , & V_35 ) ;
return 0 ;
default:
return - V_45 ;
}
}
int F_20 ( struct V_4 * V_5 , T_6 V_39 ,
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
int F_21 ( const struct V_4 * V_5 ,
T_6 * V_39 , T_4 * V_40 , T_5 * V_41 ,
T_4 * V_48 , T_5 * V_49 )
{
switch ( V_5 -> type ) {
case V_7 :
* V_39 = V_46 ;
break;
case V_9 :
* V_39 = V_47 ;
break;
default:
return - V_45 ;
}
F_15 ( V_5 , V_48 , V_49 , V_40 , V_41 ) ;
return 0 ;
}
int F_22 ( struct V_4 * V_5 ,
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
int F_23 ( const struct V_4 * V_5 ,
T_1 * V_50 , T_6 * V_51 )
{
switch ( V_5 -> type ) {
case V_13 :
* V_50 = V_52 ;
break;
case V_12 :
* V_50 = V_5 -> V_38 [ 0 ] ;
break;
default:
return - V_45 ;
}
V_51 [ 0 ] = V_5 -> V_38 [ 2 ] >> 8 ;
V_51 [ 1 ] = V_5 -> V_38 [ 2 ] ;
V_51 [ 2 ] = V_5 -> V_38 [ 1 ] >> 24 ;
V_51 [ 3 ] = V_5 -> V_38 [ 1 ] >> 16 ;
V_51 [ 4 ] = V_5 -> V_38 [ 1 ] >> 8 ;
V_51 [ 5 ] = V_5 -> V_38 [ 1 ] ;
return 0 ;
}
static T_2 F_24 ( T_3 * V_53 , struct V_4 * V_5 )
{
T_2 V_54 ;
switch ( F_3 ( V_5 ) ) {
case V_6 : {
bool V_55 = ( V_5 -> type == V_9 ||
V_5 -> type == V_10 ) ;
F_25 (
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
F_26 (
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
F_27 () ;
}
return V_5 -> V_38 [ 0 ] ^ V_5 -> V_38 [ 1 ] ^ V_5 -> V_38 [ 2 ] ^ V_54 ;
}
static bool F_28 ( const struct V_4 * V_76 ,
const struct V_4 * V_77 )
{
if ( V_76 -> type != V_77 -> type ||
memcmp ( V_76 -> V_38 , V_77 -> V_38 , sizeof( V_76 -> V_38 ) ) )
return false ;
return true ;
}
static int F_29 ( struct V_15 * V_18 ,
struct V_4 * V_5 , T_2 V_1 ,
bool V_78 , unsigned int * V_79 )
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
if ( F_30 ( V_82 , V_18 -> V_89 ) ?
F_28 ( V_5 , & V_18 -> V_5 [ V_82 ] ) :
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
static inline T_2 F_31 ( enum V_3 V_92 ,
unsigned int V_93 , T_6 V_42 )
{
return ( V_92 == V_11 &&
V_42 & V_70 ) ?
V_93 :
( V_92 + 1 ) << V_94 | V_93 ;
}
static inline enum V_3 F_32 ( T_2 V_95 )
{
return ( V_95 <= V_96 ) ?
V_11 :
( V_95 >> V_94 ) - 1 ;
}
static inline unsigned int F_33 ( T_2 V_95 )
{
return V_95 & V_96 ;
}
static inline T_6 F_34 ( T_2 V_95 )
{
return ( V_95 <= V_96 ) ?
V_43 | V_70 :
V_43 ;
}
T_2 F_35 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
if ( V_17 -> V_18 [ V_11 ] . V_31 != 0 )
return ( ( V_11 + 1 ) << V_94 )
+ V_17 -> V_18 [ V_11 ] . V_31 ;
else if ( V_17 -> V_18 [ V_6 ] . V_31 != 0 )
return ( ( V_6 + 1 ) << V_94 )
+ V_17 -> V_18 [ V_6 ] . V_31 ;
else
return 0 ;
}
T_7 F_36 ( struct V_20 * V_21 , struct V_4 * V_5 ,
bool V_97 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = F_6 ( V_17 , V_5 ) ;
struct V_4 * V_98 ;
T_3 V_53 ;
unsigned int V_82 , V_83 ;
T_2 V_1 ;
int V_99 ;
if ( ! V_18 || V_18 -> V_31 == 0 )
return - V_45 ;
V_1 = F_24 ( & V_53 , V_5 ) ;
F_37 ( V_21 , V_100 , V_21 -> V_101 ,
L_1 , V_102 , V_5 -> type ,
V_18 -> V_19 [ V_5 -> type ] ) ;
F_38 ( & V_17 -> V_103 ) ;
V_99 = F_29 ( V_18 , V_5 , V_1 , true , & V_83 ) ;
if ( V_99 < 0 )
goto V_104;
V_82 = V_99 ;
F_39 ( V_82 >= V_18 -> V_31 ) ;
V_98 = & V_18 -> V_5 [ V_82 ] ;
if ( F_30 ( V_82 , V_18 -> V_89 ) ) {
if ( ! V_97 ) {
V_99 = - V_105 ;
goto V_104;
}
if ( V_5 -> V_85 < V_98 -> V_85 ) {
V_99 = - V_106 ;
goto V_104;
}
} else {
F_40 ( V_82 , V_18 -> V_89 ) ;
++ V_18 -> V_107 ;
}
* V_98 = * V_5 ;
if ( V_18 -> V_19 [ V_5 -> type ] < V_83 ) {
V_18 -> V_19 [ V_5 -> type ] = V_83 ;
F_8 ( V_21 ) ;
}
F_11 ( V_21 , & V_53 , V_18 -> V_108 + V_18 -> V_109 * V_82 ) ;
F_37 ( V_21 , V_100 , V_21 -> V_101 ,
L_2 ,
V_102 , V_5 -> type , V_82 , V_5 -> V_62 ) ;
V_99 = F_31 ( V_18 -> V_95 , V_82 , V_5 -> V_42 ) ;
V_104:
F_41 ( & V_17 -> V_103 ) ;
return V_99 ;
}
static void F_42 ( struct V_20 * V_21 ,
struct V_15 * V_18 ,
unsigned int V_82 )
{
static T_3 V_53 ;
if ( F_30 ( V_82 , V_18 -> V_89 ) ) {
F_43 ( V_82 , V_18 -> V_89 ) ;
-- V_18 -> V_107 ;
memset ( & V_18 -> V_5 [ V_82 ] , 0 , sizeof( V_18 -> V_5 [ 0 ] ) ) ;
F_11 ( V_21 , & V_53 ,
V_18 -> V_108 + V_18 -> V_109 * V_82 ) ;
}
}
int F_44 ( struct V_20 * V_21 ,
enum V_110 V_85 ,
T_2 V_111 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
unsigned int V_82 ;
struct V_4 * V_5 ;
T_6 V_112 ;
int V_99 ;
V_92 = F_32 ( V_111 ) ;
if ( ( unsigned int ) V_92 >= V_113 )
return - V_91 ;
V_18 = & V_17 -> V_18 [ V_92 ] ;
V_82 = F_33 ( V_111 ) ;
if ( V_82 >= V_18 -> V_31 )
return - V_91 ;
V_5 = & V_18 -> V_5 [ V_82 ] ;
V_112 = F_34 ( V_111 ) ;
F_38 ( & V_17 -> V_103 ) ;
if ( F_30 ( V_82 , V_18 -> V_89 ) &&
V_5 -> V_85 == V_85 && V_5 -> V_42 == V_112 ) {
F_42 ( V_21 , V_18 , V_82 ) ;
if ( V_18 -> V_107 == 0 )
F_7 ( V_18 ) ;
V_99 = 0 ;
} else {
V_99 = - V_91 ;
}
F_41 ( & V_17 -> V_103 ) ;
return V_99 ;
}
int F_45 ( struct V_20 * V_21 ,
enum V_110 V_85 ,
T_2 V_111 , struct V_4 * V_114 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
struct V_4 * V_5 ;
unsigned int V_82 ;
T_6 V_112 ;
int V_99 ;
V_92 = F_32 ( V_111 ) ;
if ( ( unsigned int ) V_92 >= V_113 )
return - V_91 ;
V_18 = & V_17 -> V_18 [ V_92 ] ;
V_82 = F_33 ( V_111 ) ;
if ( V_82 >= V_18 -> V_31 )
return - V_91 ;
V_5 = & V_18 -> V_5 [ V_82 ] ;
V_112 = F_34 ( V_111 ) ;
F_38 ( & V_17 -> V_103 ) ;
if ( F_30 ( V_82 , V_18 -> V_89 ) &&
V_5 -> V_85 == V_85 && V_5 -> V_42 == V_112 ) {
* V_114 = * V_5 ;
V_99 = 0 ;
} else {
V_99 = - V_91 ;
}
F_41 ( & V_17 -> V_103 ) ;
return V_99 ;
}
static void F_46 ( struct V_20 * V_21 ,
enum V_3 V_92 ,
enum V_110 V_85 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = & V_17 -> V_18 [ V_92 ] ;
unsigned int V_82 ;
F_38 ( & V_17 -> V_103 ) ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; ++ V_82 )
if ( V_18 -> V_5 [ V_82 ] . V_85 <= V_85 )
F_42 ( V_21 , V_18 , V_82 ) ;
if ( V_18 -> V_107 == 0 )
F_7 ( V_18 ) ;
F_41 ( & V_17 -> V_103 ) ;
}
void F_47 ( struct V_20 * V_21 , enum V_110 V_85 )
{
F_46 ( V_21 , V_6 , V_85 ) ;
F_46 ( V_21 , V_11 , V_85 ) ;
}
T_2 F_48 ( struct V_20 * V_21 ,
enum V_110 V_85 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
unsigned int V_82 ;
T_2 V_115 = 0 ;
F_38 ( & V_17 -> V_103 ) ;
for ( V_92 = V_6 ;
V_92 <= V_11 ;
V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; V_82 ++ ) {
if ( F_30 ( V_82 , V_18 -> V_89 ) &&
V_18 -> V_5 [ V_82 ] . V_85 == V_85 )
++ V_115 ;
}
}
F_41 ( & V_17 -> V_103 ) ;
return V_115 ;
}
T_7 F_49 ( struct V_20 * V_21 ,
enum V_110 V_85 ,
T_2 * V_116 , T_2 V_31 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
unsigned int V_82 ;
T_7 V_115 = 0 ;
F_38 ( & V_17 -> V_103 ) ;
for ( V_92 = V_6 ;
V_92 <= V_11 ;
V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; V_82 ++ ) {
if ( F_30 ( V_82 , V_18 -> V_89 ) &&
V_18 -> V_5 [ V_82 ] . V_85 == V_85 ) {
if ( V_115 == V_31 ) {
V_115 = - V_117 ;
goto V_104;
}
V_116 [ V_115 ++ ] = F_31 (
V_92 , V_82 ,
V_18 -> V_5 [ V_82 ] . V_42 ) ;
}
}
}
V_104:
F_41 ( & V_17 -> V_103 ) ;
return V_115 ;
}
void F_50 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
struct V_15 * V_18 ;
T_3 V_53 ;
unsigned int V_82 ;
F_38 ( & V_17 -> V_103 ) ;
for ( V_92 = 0 ; V_92 < V_113 ; V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
for ( V_82 = 0 ; V_82 < V_18 -> V_31 ; V_82 ++ ) {
if ( ! F_30 ( V_82 , V_18 -> V_89 ) )
continue;
F_24 ( & V_53 , & V_18 -> V_5 [ V_82 ] ) ;
F_11 ( V_21 , & V_53 ,
V_18 -> V_108 + V_18 -> V_109 * V_82 ) ;
}
}
F_8 ( V_21 ) ;
F_41 ( & V_17 -> V_103 ) ;
}
int F_51 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
struct V_15 * V_18 ;
unsigned V_92 ;
V_17 = F_52 ( sizeof( * V_21 -> V_22 ) , V_118 ) ;
if ( ! V_17 )
return - V_119 ;
V_21 -> V_22 = V_17 ;
F_53 ( & V_17 -> V_103 ) ;
if ( F_54 ( V_21 ) >= V_120 ) {
#ifdef F_55
V_17 -> V_121 = F_56 ( V_122 ,
sizeof( * V_17 -> V_121 ) ,
V_118 ) ;
if ( ! V_17 -> V_121 )
goto V_123;
#endif
V_18 = & V_17 -> V_18 [ V_6 ] ;
V_18 -> V_95 = V_6 ;
V_18 -> V_108 = V_124 ;
V_18 -> V_31 = V_122 ;
V_18 -> V_109 = V_125 ;
}
if ( F_54 ( V_21 ) >= V_126 ) {
V_18 = & V_17 -> V_18 [ V_11 ] ;
V_18 -> V_95 = V_11 ;
V_18 -> V_108 = V_127 ;
V_18 -> V_31 = V_128 ;
V_18 -> V_109 = V_129 ;
}
for ( V_92 = 0 ; V_92 < V_113 ; V_92 ++ ) {
V_18 = & V_17 -> V_18 [ V_92 ] ;
if ( V_18 -> V_31 == 0 )
continue;
V_18 -> V_89 = F_56 ( F_57 ( V_18 -> V_31 ) ,
sizeof( unsigned long ) ,
V_118 ) ;
if ( ! V_18 -> V_89 )
goto V_123;
V_18 -> V_5 = F_58 ( V_18 -> V_31 * sizeof( * V_18 -> V_5 ) ) ;
if ( ! V_18 -> V_5 )
goto V_123;
}
return 0 ;
V_123:
F_59 ( V_21 ) ;
return - V_119 ;
}
void F_59 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
enum V_3 V_92 ;
for ( V_92 = 0 ; V_92 < V_113 ; V_92 ++ ) {
F_60 ( V_17 -> V_18 [ V_92 ] . V_89 ) ;
F_61 ( V_17 -> V_18 [ V_92 ] . V_5 ) ;
}
#ifdef F_55
F_60 ( V_17 -> V_121 ) ;
#endif
F_60 ( V_17 ) ;
}
int F_62 ( struct V_130 * V_101 , const struct V_131 * V_132 ,
T_1 V_133 , T_2 V_134 )
{
struct V_20 * V_21 = F_63 ( V_101 ) ;
struct V_135 * V_136 ;
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_4 V_5 ;
const struct V_137 * V_138 ;
const T_5 * V_139 ;
int V_140 ;
int V_99 ;
V_140 = F_64 ( V_132 ) ;
if ( V_132 -> V_141 != F_17 ( V_142 ) )
return - V_44 ;
F_5 ( F_65 ( V_132 ) < V_140 + sizeof( * V_138 ) ) ;
V_138 = ( const struct V_137 * ) ( V_132 -> V_38 + V_140 ) ;
if ( F_66 ( V_138 ) )
return - V_44 ;
F_5 ( F_65 ( V_132 ) < V_140 + 4 * V_138 -> V_143 + 4 ) ;
V_139 = ( const T_5 * ) ( V_132 -> V_38 + V_140 + 4 * V_138 -> V_143 ) ;
F_67 ( & V_5 , V_86 , 0 , V_133 ) ;
V_99 = F_20 ( & V_5 , V_138 -> V_141 ,
V_138 -> V_144 , V_139 [ 1 ] , V_138 -> V_145 , V_139 [ 0 ] ) ;
if ( V_99 )
return V_99 ;
V_99 = F_36 ( V_21 , & V_5 , true ) ;
if ( V_99 < 0 )
return V_99 ;
V_17 -> V_121 [ V_99 ] = V_134 ;
V_136 = F_68 ( V_21 , F_69 ( V_132 ) ) ;
++ V_136 -> V_146 ;
F_70 ( V_21 , V_147 , V_21 -> V_101 ,
L_3 ,
( V_138 -> V_141 == V_46 ) ? L_4 : L_5 ,
& V_138 -> V_145 , F_14 ( V_139 [ 0 ] ) , & V_138 -> V_144 , F_14 ( V_139 [ 1 ] ) ,
V_133 , V_134 , V_99 ) ;
return V_99 ;
}
bool F_71 ( struct V_20 * V_21 , unsigned V_148 )
{
struct V_16 * V_17 = V_21 -> V_22 ;
struct V_15 * V_18 = & V_17 -> V_18 [ V_6 ] ;
unsigned V_149 = V_18 -> V_31 - 1 ;
unsigned V_93 ;
unsigned V_150 ;
if ( ! F_72 ( & V_17 -> V_103 ) )
return false ;
V_93 = V_17 -> V_151 ;
V_150 = ( V_93 + V_148 ) & V_149 ;
while ( V_93 != V_150 ) {
if ( F_30 ( V_93 , V_18 -> V_89 ) &&
V_18 -> V_5 [ V_93 ] . V_85 == V_86 &&
F_73 ( V_21 -> V_101 ,
V_18 -> V_5 [ V_93 ] . V_62 ,
V_17 -> V_121 [ V_93 ] , V_93 ) ) {
F_70 ( V_21 , V_147 , V_21 -> V_101 ,
L_6 ,
V_93 , V_17 -> V_121 [ V_93 ] ) ;
F_42 ( V_21 , V_18 , V_93 ) ;
}
V_93 = ( V_93 + 1 ) & V_149 ;
}
V_17 -> V_151 = V_150 ;
if ( V_18 -> V_107 == 0 )
F_7 ( V_18 ) ;
F_41 ( & V_17 -> V_103 ) ;
return true ;
}
