void F_1 ( struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
enum V_5 F_3 ( struct V_1 * * V_2 ,
const struct V_6 * V_7 )
{
enum V_5 V_8 = V_9 ;
if ( V_2 == NULL || V_7 == NULL )
return V_10 ;
F_4 ( V_11 ,
L_1 ) ;
V_8 =
F_5 ( V_2 , V_7 -> V_12 . V_13 , V_7 -> V_12 . V_14 ,
V_7 -> V_15 , V_7 -> V_16 ,
V_7 -> V_17 ) ;
F_4 ( V_11 ,
L_2 ) ;
return V_8 ;
}
enum V_5 F_5 ( struct V_1 * * V_2 ,
unsigned int V_13 ,
unsigned int V_14 ,
enum V_18 V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
enum V_5 V_8 = V_9 ;
if ( V_2 == NULL || V_13 == 0 || V_14 == 0 )
return V_10 ;
F_4 ( V_11 ,
#ifndef F_6
L_3 ,
V_13 , V_14 , V_15 ) ;
#else
L_4 ,
V_13 , V_14 , V_15 , V_16 , V_17 ) ;
V_5 F_7 ( struct V_1 * * V_2 ,
const struct V_6 * V_7 ,
const void * V_3 ,
T_1 V_19 ,
void * V_20 )
{
enum V_5 V_8 = V_9 ;
struct V_1 * V_21 ;
assert ( V_2 != NULL ) ;
V_8 = F_8 ( & V_21 , V_7 ) ;
if ( V_8 != V_9 )
return V_8 ;
if ( V_8 == V_9 ) {
V_21 -> V_3 = ( V_22 ) F_9 ( V_3 ,
V_21 -> V_4 ,
V_19 , V_20 ) ;
if ( V_21 -> V_3 == V_23 )
V_8 = V_10 ;
} ;
if ( V_8 != V_9 ) {
F_10 ( V_21 ) ;
#ifndef F_6
return V_8 ;
#else
V_21 = NULL ;
#endif
}
* V_2 = V_21 ;
return V_8 ;
}
enum V_5 F_8 ( struct V_1 * * V_2 ,
const struct V_6 * V_7 )
{
enum V_5 V_8 = V_9 ;
struct V_1 * V_21 ;
F_4 ( V_11 ,
L_5 ) ;
if ( V_2 == NULL || V_7 == NULL ) {
F_4 ( V_11 ,
L_6
L_7 ) ;
return V_10 ;
}
V_21 = F_11 ( V_7 -> V_12 . V_13 ,
V_7 -> V_12 . V_14 ,
V_7 -> V_15 ,
V_7 -> V_16 ,
V_7 -> V_17 ,
false ,
false ) ;
if ( V_21 == NULL ) {
F_4 ( V_11 ,
L_6
L_8 ) ;
return V_24 ;
}
V_8 = F_12 ( V_21 ) ;
#ifndef F_6
if ( V_8 == V_9 )
* V_2 = V_21 ;
else
#else
if ( V_8 != V_9 ) {
#endif
F_10 ( V_21 ) ;
#ifdef F_6
V_21 = NULL ;
}
* V_2 = V_21 ;
#endif
F_4 ( V_11 , L_9 ) ;
return V_8 ;
}
enum V_5 F_13 ( struct V_1 * V_2 ,
const V_22 V_25 ,
T_2 V_4 )
{
enum V_5 V_8 = V_9 ;
F_4 ( V_11 ,
L_10 ) ;
if ( V_2 == NULL ) {
F_4 ( V_11 ,
L_11 ) ;
return V_10 ;
}
if ( ( V_25 != V_23 ) && ( V_2 -> V_4 > V_4 ) ) {
F_4 ( V_11 ,
L_12 ) ;
return V_10 ;
}
V_2 -> V_3 = V_25 ;
F_4 ( V_11 , L_13 ) ;
return V_8 ;
}
enum V_5 F_14 ( struct V_1 * * V_2 ,
unsigned int V_13 ,
unsigned int V_14 ,
enum V_18 V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
enum V_5 V_8 = V_9 ;
F_4 ( V_11 ,
L_14
#ifndef F_6
L_15 ,
V_13 , V_14 , V_15 ) ;
#else
L_16 ,
V_13 , V_14 , V_15 , V_16 , V_17 ) ;
V_5 F_15 (
struct V_1 * * V_2 ,
const struct V_6 * V_7 )
{
enum V_5 V_8 = V_9 ;
assert ( V_2 != NULL ) ;
F_4 ( V_11 ,
L_17 ) ;
V_8 = F_14 ( V_2 ,
V_7 -> V_12 . V_13 ,
V_7 -> V_12 . V_14 ,
V_7 -> V_15 ,
V_7 -> V_16 ,
V_7 -> V_17 ) ;
F_4 ( V_11 ,
L_18 ) ;
return V_8 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( L_19 , V_2 ) ;
if ( V_2 != NULL ) {
F_18 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
}
F_19 ( L_20 ) ;
}
enum V_5 F_20 ( const struct V_6 * V_7 )
{
assert ( V_7 != NULL ) ;
if ( V_7 -> V_12 . V_13 == 0 || V_7 -> V_12 . V_14 == 0 )
return V_10 ;
return V_9 ;
}
enum V_5 F_12 ( struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
switch ( V_2 -> V_7 . V_15 ) {
case V_26 :
F_21 ( V_2 , & V_2 -> V_27 . V_28 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 ,
V_2 -> V_7 . V_17 <= 8 ? 1 : 2 ) ;
break;
case V_29 :
F_22 ( V_2 , & V_2 -> V_27 . V_28 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 ,
V_2 -> V_7 . V_17 ) ;
break;
case V_30 :
F_23 ( V_2 , & V_2 -> V_27 . V_28 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 ,
V_2 -> V_7 . V_17 <= 8 ? 1 : 2 ) ;
break;
case V_31 :
F_23 ( V_2 , & V_2 -> V_27 . V_32 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 , 2 ) ;
break;
case V_33 :
F_23 ( V_2 , & V_2 -> V_27 . V_32 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 * 4 , 1 ) ;
break;
case V_34 :
F_24 ( V_2 , 1 ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_23 ( V_2 , & V_2 -> V_27 . V_39 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 * 2 , 1 ) ;
break;
case V_40 :
F_23 ( V_2 , & V_2 -> V_27 . V_39 ,
V_2 -> V_7 . V_12 . V_14 * 3 / 2 + 3 ,
V_2 -> V_7 . V_16 , 1 ) ;
break;
case V_41 :
F_25 ( V_2 , 4 , 1 , 1 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
F_25 ( V_2 , 2 , 2 , 1 ) ;
break;
case V_45 :
F_25 ( V_2 , 2 , 2 , 2 ) ;
break;
case V_46 :
case V_47 :
F_25 ( V_2 , 2 , 1 , 1 ) ;
break;
case V_48 :
F_26 ( V_2 , 2 , 2 , false , 1 ) ;
break;
case V_49 :
F_26 ( V_2 , 2 , 1 , false , 1 ) ;
break;
case V_50 :
F_26 ( V_2 , 1 , 1 , false , 1 ) ;
break;
case V_51 :
F_26 ( V_2 , 2 , 2 , false , 2 ) ;
break;
case V_52 :
F_26 ( V_2 , 2 , 1 , false , 2 ) ;
break;
case V_53 :
F_26 ( V_2 , 2 , 2 , true , 1 ) ;
break;
case V_54 :
F_26 ( V_2 , 2 , 1 , true , 1 ) ;
break;
case V_55 :
F_27 ( V_2 ) ;
break;
case V_56 :
F_23 ( V_2 , & V_2 -> V_27 . V_57 . V_3 ,
V_2 -> V_7 . V_12 . V_14 ,
V_2 -> V_7 . V_16 , 1 ) ;
V_2 -> V_27 . V_57 . V_58 = 0 ;
break;
default:
return V_10 ;
}
return V_9 ;
}
void F_28 ( struct V_6 * V_7 ,
unsigned int V_13 ,
unsigned int V_59 )
{
unsigned int V_60 ;
F_17 ( L_21 ,
V_7 , V_13 , V_59 ) ;
if ( V_7 == NULL ) {
F_29 ( L_22 ) ;
F_19 ( L_23 ) ;
return;
}
if ( V_59 > V_13 )
V_60 = V_59 ;
else
V_60 = V_13 ;
V_7 -> V_12 . V_13 = V_13 ;
if ( V_7 -> V_15 == V_48 ||
V_7 -> V_15 == V_53 ||
V_7 -> V_15 == V_42 ||
V_7 -> V_15 == V_43 ||
V_7 -> V_15 == V_56 ||
V_7 -> V_15 == V_40 )
V_7 -> V_16 =
F_30 ( V_60 , 2 * V_61 ) ;
else if ( V_7 -> V_15 == V_44 )
V_7 -> V_16 = F_30 ( V_60 , V_62 ) ;
else if ( V_7 -> V_15 == V_30 ||
V_7 -> V_15 == V_29 )
V_7 -> V_16 = F_30 ( V_60 , 2 * V_63 ) ;
else {
V_7 -> V_16 = F_30 ( V_60 , V_61 ) ;
}
F_19 ( L_23 ) ;
}
void F_31 ( struct V_6 * V_7 ,
enum V_18 V_15 )
{
assert ( V_7 != NULL ) ;
F_4 ( V_11 ,
L_24 ) ;
V_7 -> V_15 = V_15 ;
}
void F_32 ( struct V_6 * V_7 ,
unsigned int V_13 ,
unsigned int V_14 ,
enum V_18 V_15 ,
unsigned int V_64 )
{
F_17 ( L_25 ,
V_7 , V_13 , V_14 , V_15 , V_64 ) ;
if ( V_7 == NULL ) {
F_29 ( L_22 ) ;
F_19 ( L_23 ) ;
return;
}
V_7 -> V_12 . V_14 = V_14 ;
V_7 -> V_15 = V_15 ;
F_28 ( V_7 , V_13 , V_64 ) ;
F_19 ( L_23 ) ;
}
void F_33 ( unsigned int V_65 ,
struct V_1 * * V_66 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
if ( V_66 [ V_67 ] ) {
F_16 ( V_66 [ V_67 ] ) ;
V_66 [ V_67 ] = NULL ;
}
}
}
enum V_5 F_34 (
struct V_1 * * V_2 ,
const unsigned int V_68 ,
const bool V_69 )
{
enum V_5 V_8 ;
struct V_1 * V_21 = F_11 ( 0 , 0 ,
V_70 ,
0 , 0 , V_69 , false ) ;
if ( V_21 == NULL )
return V_24 ;
V_21 -> V_4 = V_68 ;
V_8 = F_35 ( V_21 ) ;
if ( V_8 != V_9 ) {
F_10 ( V_21 ) ;
#ifndef F_6
return V_8 ;
#else
V_21 = NULL ;
#endif
}
* V_2 = V_21 ;
return V_8 ;
}
bool F_36 (
const struct V_6 * V_71 ,
const struct V_6 * V_72 )
{
if ( ! V_71 || ! V_72 )
return false ;
return ( V_71 -> V_12 . V_13 == V_72 -> V_12 . V_13 ) &&
( V_71 -> V_12 . V_14 == V_72 -> V_12 . V_14 ) ;
}
bool F_37 ( const struct V_1 * V_73 ,
const struct V_1 * V_74 )
{
bool V_75 = false ;
const struct V_6 * V_71 = & V_73 -> V_7 ,
* V_72 = & V_74 -> V_7 ;
F_4 ( V_11 ,
L_26 ) ;
if ( ! V_71 || ! V_72 )
return false ;
if ( V_71 -> V_15 != V_72 -> V_15 )
return false ;
if ( V_71 -> V_16 != V_72 -> V_16 )
return false ;
V_75 = F_36 ( V_71 , V_72 ) ;
F_4 ( V_11 ,
L_27 ) ;
return V_75 ;
}
void
F_38 (
struct V_76 * V_77 ,
const struct V_6 * V_7 )
{
unsigned V_78 = V_7 -> V_15 == V_29 ;
unsigned V_79 = V_78 ? V_7 -> V_17 : F_39 ( V_7 ) * 8 ;
unsigned V_80 = V_81 / V_79 ;
unsigned V_82 = F_40 ( V_7 -> V_16 , V_80 ) ;
unsigned V_83 = V_80 ;
V_77 -> V_84 = V_61 * V_82 ;
V_77 -> V_85 = ( V_86 ) V_83 ;
V_77 -> V_13 = ( T_1 ) V_7 -> V_12 . V_13 ;
V_77 -> V_87 = 0 ;
assert ( V_77 -> V_13 <= V_7 -> V_16 ) ;
}
static void F_41 ( struct V_88 * V_89 ,
unsigned int V_13 ,
unsigned int V_84 ,
unsigned int V_14 ,
unsigned int V_90 )
{
V_89 -> V_14 = V_14 ;
V_89 -> V_13 = V_13 ;
V_89 -> V_84 = V_84 ;
V_89 -> V_90 = V_90 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
unsigned int V_14 ,
unsigned int V_91 ,
unsigned int V_92 )
{
unsigned int V_84 ;
V_84 = V_91 * V_92 ;
V_2 -> V_4 = V_84 * F_42 ( V_14 , 2 ) ;
F_41 ( V_89 , V_91 , V_84 , V_14 , 0 ) ;
return;
}
static void F_22 (
struct V_1 * V_2 ,
struct V_88 * V_89 ,
unsigned int V_14 ,
unsigned int V_91 ,
unsigned int V_79 )
{
unsigned int V_84 ;
assert ( V_2 != NULL ) ;
V_84 = V_61 *
F_40 ( V_91 ,
V_81 / V_79 ) ;
V_2 -> V_4 = V_84 * V_14 ;
F_41 ( V_89 , V_91 , V_84 , V_14 , 0 ) ;
return;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
unsigned int V_14 ,
unsigned int V_91 ,
unsigned int V_92 )
{
unsigned int V_84 ;
V_84 = V_91 * V_92 ;
V_2 -> V_4 = 8388608 ;
V_2 -> V_93 = false ;
V_2 -> V_69 = true ;
F_41 ( V_89 , V_91 , V_84 , V_14 , 0 ) ;
return;
}
static void F_25 ( struct V_1 * V_2 ,
unsigned int V_94 ,
unsigned int V_95 ,
unsigned int V_96 )
{
unsigned int V_97 = V_2 -> V_7 . V_16 ;
unsigned int V_98 = V_2 -> V_7 . V_12 . V_14 ;
unsigned int V_99 ;
unsigned int V_100 ;
unsigned int V_101 ;
unsigned int V_102 ;
unsigned int V_103 ;
unsigned int V_104 ;
assert ( V_94 != 0 && V_95 != 0 ) ;
V_99 = 2 * ( V_97 / V_94 ) ;
V_100 = V_98 / V_95 ;
if ( V_44 == V_2 -> V_7 . V_15 ) {
V_97 = F_30 ( V_97 , V_62 ) ;
V_99 = F_30 ( V_99 , V_62 ) ;
V_98 = F_30 ( V_98 , V_105 ) ;
V_100 = F_30 ( V_100 , V_105 ) ;
}
V_103 = V_97 * V_96 ;
V_104 = V_99 * V_96 ;
V_101 = V_103 * V_98 ;
V_102 = V_104 * V_100 ;
V_2 -> V_4 = V_101 + V_102 ;
F_41 ( & V_2 -> V_27 . V_106 . V_107 , V_97 , V_103 , V_98 , 0 ) ;
F_41 ( & V_2 -> V_27 . V_106 . V_108 , V_99 ,
V_104 , V_100 , V_101 ) ;
return;
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_94 ,
unsigned int V_95 ,
bool V_109 ,
unsigned int V_96 )
{
unsigned int V_97 = V_2 -> V_7 . V_16 ,
V_98 = V_2 -> V_7 . V_12 . V_14 ,
V_99 = V_97 / V_94 ,
V_100 = V_98 / V_95 ,
V_103 , V_101 , V_102 , V_104 ;
V_103 = V_97 * V_96 ;
V_104 = V_99 * V_96 ;
V_101 = V_103 * V_98 ;
V_102 = V_104 * V_100 ;
V_2 -> V_4 = V_101 + 2 * V_102 ;
F_41 ( & V_2 -> V_27 . V_110 . V_107 , V_97 , V_103 , V_98 , 0 ) ;
if ( V_109 ) {
F_41 ( & V_2 -> V_27 . V_110 . V_111 , V_99 , V_104 ,
V_100 , V_101 ) ;
F_41 ( & V_2 -> V_27 . V_110 . V_112 , V_99 , V_104 ,
V_100 , V_101 + V_102 ) ;
} else {
F_41 ( & V_2 -> V_27 . V_110 . V_112 , V_99 , V_104 ,
V_100 , V_101 ) ;
F_41 ( & V_2 -> V_27 . V_110 . V_111 , V_99 , V_104 ,
V_100 , V_101 + V_102 ) ;
}
return;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_96 )
{
unsigned int V_13 = V_2 -> V_7 . V_12 . V_13 ,
V_14 = V_2 -> V_7 . V_12 . V_14 , V_84 , V_113 ;
V_84 = V_13 * V_96 ;
V_113 = V_84 * V_14 ;
V_2 -> V_4 = 3 * V_113 ;
F_41 ( & V_2 -> V_27 . V_114 . V_115 , V_13 , V_84 , V_14 , 0 ) ;
F_41 ( & V_2 -> V_27 . V_114 . V_116 ,
V_13 , V_84 , V_14 , 1 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_114 . V_117 ,
V_13 , V_84 , V_14 , 2 * V_113 ) ;
return;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_13 = V_2 -> V_7 . V_16 / 2 ,
V_14 = V_2 -> V_7 . V_12 . V_14 / 2 , V_113 , V_84 ;
V_84 = V_13 * 2 ;
V_113 = V_84 * V_14 ;
V_2 -> V_4 = 6 * V_113 ;
F_41 ( & V_2 -> V_27 . V_118 . V_115 ,
V_13 , V_84 , V_14 , 0 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_118 . V_119 ,
V_13 , V_84 , V_14 , 1 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_118 . V_120 ,
V_13 , V_84 , V_14 , 2 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_118 . V_121 ,
V_13 , V_84 , V_14 , 3 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_118 . V_117 ,
V_13 , V_84 , V_14 , 4 * V_113 ) ;
F_41 ( & V_2 -> V_27 . V_118 . V_122 ,
V_13 , V_84 , V_14 , 5 * V_113 ) ;
return;
}
static enum V_5 F_35 ( struct V_1 * V_2 )
{
#ifdef F_6
F_43 ( L_28 , V_2 -> V_4 ) ;
#endif
V_2 -> V_3 = F_44 ( V_2 -> V_4 ,
V_2 -> V_69 ?
V_123 :
V_124 ) ;
if ( V_2 -> V_3 == V_23 )
return V_24 ;
return V_9 ;
}
static enum V_5 F_45 ( struct V_1 * * V_2 ,
unsigned int V_13 ,
unsigned int V_14 ,
enum V_18 V_15 ,
unsigned int V_16 ,
unsigned int V_17 ,
bool V_69 )
{
enum V_5 V_8 ;
struct V_1 * V_21 = F_11 ( V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_17 ,
V_69 ,
true ) ;
if ( V_21 == NULL )
return V_24 ;
V_8 = F_12 ( V_21 ) ;
if ( V_8 == V_9 )
V_8 = F_35 ( V_21 ) ;
if ( V_8 != V_9 ) {
F_10 ( V_21 ) ;
#ifndef F_6
return V_8 ;
#else
V_21 = NULL ;
#endif
}
* V_2 = V_21 ;
return V_8 ;
}
static struct V_1 * F_11 ( unsigned int V_13 ,
unsigned int V_14 ,
enum V_18 V_15 ,
unsigned int V_16 ,
unsigned int V_17 ,
bool V_69 ,
bool V_93 )
{
struct V_1 * V_21 = F_46 ( sizeof( * V_21 ) ) ;
if ( V_21 == NULL )
return NULL ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_7 . V_12 . V_13 = V_13 ;
V_21 -> V_7 . V_12 . V_14 = V_14 ;
V_21 -> V_7 . V_15 = V_15 ;
V_21 -> V_7 . V_16 = V_16 ;
V_21 -> V_7 . V_17 = V_17 ;
V_21 -> V_69 = V_69 ;
V_21 -> V_93 = V_93 ;
V_21 -> V_4 = 0 ;
V_21 -> V_3 = V_23 ;
V_21 -> V_125 = ( int ) V_126 ;
V_21 -> V_127 = V_128 ;
return V_21 ;
}
static unsigned
F_39 ( const struct V_6 * V_7 )
{
if ( V_7 -> V_15 == V_31 )
return 2 ;
if ( V_7 -> V_15 == V_51 )
return 2 ;
if ( V_7 -> V_15 == V_52 )
return 2 ;
if ( V_7 -> V_15 == V_45 )
return 1 ;
if ( V_7 -> V_15 == V_30
|| ( V_7 -> V_15 == V_29 ) ) {
if ( V_7 -> V_17 )
return F_40 ( V_7 -> V_17 , 8 ) ;
else
return 2 ;
}
if ( V_7 -> V_15 == V_34 )
return 3 ;
if ( V_7 -> V_15 == V_33 )
return 4 ;
if ( V_7 -> V_15 == V_55 )
return 2 ;
return 1 ;
}
void F_47 (
struct V_129 * V_130 ,
const struct V_6 * V_131 )
{
F_48 ( & V_130 -> V_12 , & V_131 -> V_12 ) ;
V_130 -> V_16 = ( T_1 ) V_131 -> V_16 ;
V_130 -> V_15 = ( V_86 ) V_131 -> V_15 ;
V_130 -> V_17 = ( V_86 ) V_131 -> V_17 ;
V_130 -> V_132 = V_131 -> V_132 ;
}
void F_48 (
struct V_133 * V_130 ,
const struct V_134 * V_131 )
{
V_130 -> V_13 = ( T_1 ) V_131 -> V_13 ;
V_130 -> V_14 = ( T_1 ) V_131 -> V_14 ;
}
enum V_5
F_49 ( const struct V_134 * V_135 ,
const struct V_134 * V_136 ,
struct V_134 * V_137 )
{
T_3 V_138 , V_139 ;
T_3 V_140 , V_141 ;
if ( ( V_135 == NULL ) || ( V_136 == NULL ) || ( V_137 == NULL ) )
return V_10 ;
F_17 ( L_29 , V_135 -> V_13 ,
V_135 -> V_14 , V_136 -> V_13 , V_136 -> V_14 ) ;
if ( ( V_135 -> V_13 == 0 )
|| ( V_135 -> V_14 == 0 )
|| ( V_136 -> V_13 == 0 )
|| ( V_136 -> V_14 == 0 ) )
return V_10 ;
if ( ( V_136 -> V_13 > V_135 -> V_13 ) ||
( V_136 -> V_14 > V_135 -> V_14 ) )
return V_10 ;
V_140 = V_135 -> V_13 * V_136 -> V_14 ;
V_141 = V_136 -> V_13 * V_135 -> V_14 ;
if ( V_140 == V_141 ) {
V_137 -> V_13 = V_135 -> V_13 ;
V_137 -> V_14 = V_135 -> V_14 ;
} else if ( V_141 > V_140 ) {
V_137 -> V_13 = V_135 -> V_13 ;
V_137 -> V_14 = F_50 ( V_136 -> V_14 * V_137 -> V_13 ,
V_136 -> V_13 ) ;
} else {
V_137 -> V_14 = V_135 -> V_14 ;
V_137 -> V_13 = F_50 ( V_136 -> V_13 * V_137 -> V_14 ,
V_136 -> V_14 ) ;
}
V_138 = F_51 ( V_137 -> V_13 ) ;
V_139 = F_51 ( V_137 -> V_14 ) ;
if ( ( V_138 > V_135 -> V_13 ) || ( V_139 > V_135 -> V_14 ) ) {
V_137 -> V_13 = F_52 ( V_137 -> V_13 ) ;
V_137 -> V_14 = F_52 ( V_137 -> V_14 ) ;
} else {
V_137 -> V_13 = V_138 ;
V_137 -> V_14 = V_139 ;
}
F_19 ( L_29 , V_137 -> V_13 ,
V_137 -> V_14 , V_136 -> V_13 , V_136 -> V_14 ) ;
return V_9 ;
}
