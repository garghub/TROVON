T_1 F_1 (
T_2 * V_1 ,
T_3 V_2 ,
T_4 V_3 )
{
T_1 V_4 ;
if ( V_1 == NULL || V_2 == NULL ||
V_3 >= V_5 )
return false ;
F_2 ( V_6 ,
L_1 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 = V_1 -> V_8 . V_9 ;
V_2 -> V_10 = V_3 ;
V_2 -> V_11 = V_1 -> V_11 ;
V_4 = F_3 ( V_1 , & ( V_2 -> V_12 ) ) ;
if ( V_4 == false )
return false ;
V_4 = F_4 ( V_1 , false , & ( V_2 -> V_13 ) ) ;
if ( V_4 == false ) {
F_5 ( & V_2 -> V_12 ) ;
return false ;
}
#ifdef F_6
V_2 -> V_14 = V_1 -> V_14 ;
#endif
if ( V_1 -> V_8 . V_9 ) {
V_4 = F_4 ( V_1 , true , & V_2 -> V_15 ) ;
if ( V_4 == false ) {
F_5 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_13 ) ;
return false ;
}
}
F_2 ( V_6 ,
L_2 ) ;
return true ;
}
void F_8 (
T_3 V_2 )
{
F_5 ( & V_2 -> V_12 ) ;
F_7 ( & ( V_2 -> V_13 ) ) ;
if ( V_2 -> V_7 ) {
F_7 ( & V_2 -> V_15 ) ;
}
}
T_1 F_9 (
T_3 V_2 ,
T_2 * V_1 ,
T_5 * V_16 )
{
T_1 V_4 ;
if ( V_16 == NULL ||
V_1 == NULL ||
V_2 == NULL )
return false ;
F_2 ( V_6 ,
L_3 ) ;
V_4 = F_10 (
& ( V_2 -> V_13 ) ,
& ( V_2 -> V_12 ) ,
V_1 ,
& ( V_16 -> V_17 ) ,
false ) ;
if ( V_4 == false )
return false ;
if ( V_1 -> V_8 . V_9 ) {
V_16 -> V_7 = true ;
V_4 = F_10 (
& V_2 -> V_15 ,
& V_2 -> V_12 ,
V_1 ,
& V_16 -> V_18 ,
true ) ;
if ( V_4 == false )
return false ;
}
V_4 = F_11 (
& ( V_2 -> V_13 ) ,
& ( V_2 -> V_12 ) ,
V_1 ,
& ( V_16 -> V_19 ) ) ;
if ( V_4 == false )
return false ;
V_2 -> V_20 = 1 ;
V_16 -> V_20 = 1 ;
F_2 ( V_6 ,
L_4 ) ;
return V_4 ;
}
static bool F_4 (
T_6 * V_21 ,
bool V_8 ,
T_7 * V_22 )
{
bool V_4 = true ;
V_22 -> V_23 = V_24 ;
switch ( V_21 -> V_25 ) {
case V_26 :
case V_27 :
V_22 -> V_28 = V_29 ;
V_22 -> V_30 = V_31 ;
break;
case V_32 :
case V_33 :
V_22 -> V_28 = V_34 ;
V_22 -> V_30 = V_35 ;
break;
case V_36 :
case V_37 :
V_22 -> V_28 = V_38 ;
V_22 -> V_30 = V_39 ;
break;
default:
V_4 = false ;
break;
}
if ( V_4 == false )
return false ;
if ( ! F_12 ( V_22 -> V_28 , & ( V_22 -> V_40 ) ) ) {
return false ;
}
if ( ! F_13 (
V_8 ? V_21 -> V_8 . V_41 : V_21 -> V_42 . V_41 ,
V_8 ? V_21 -> V_8 . V_43 : V_21 -> V_42 . V_43 ,
V_8 ? V_21 -> V_8 . V_44 : V_21 -> V_42 . V_44 ,
V_8 ? V_21 -> V_8 . V_45 : V_21 -> V_42 . V_45 ,
V_21 -> V_46 ,
& ( V_22 -> V_47 ) ) ) {
F_14 ( V_22 -> V_28 , & ( V_22 -> V_40 ) ) ;
return false ;
}
if ( ! F_15 ( V_22 -> V_23 , & ( V_22 -> V_48 ) ) ) {
F_14 ( V_22 -> V_28 , & ( V_22 -> V_40 ) ) ;
F_16 ( & ( V_22 -> V_47 ) ) ;
return false ;
}
return true ;
}
static void F_7 (
T_7 * V_22 )
{
F_14 ( V_22 -> V_28 ,
& ( V_22 -> V_40 ) ) ;
F_16 ( & ( V_22 -> V_47 ) ) ;
F_17 ( V_22 -> V_23 , & ( V_22 -> V_48 ) ) ;
}
static bool F_3 (
T_6 * V_21 ,
T_8 * V_22 )
{
T_9 V_49 ;
bool V_4 = true ;
switch ( V_21 -> V_25 ) {
case V_26 :
V_22 -> V_50 . V_51 = V_52 ;
V_22 -> V_50 . V_53 = V_54 ;
V_49 = F_18 ( V_21 -> V_55 . V_56 ) ;
V_22 -> V_50 . V_49 = V_49 ;
V_4 = F_19 (
V_22 -> V_50 . V_53 ,
V_49 ,
& ( V_22 -> V_50 . V_57 ) ) ;
break;
case V_27 :
V_22 -> V_58 . V_59 = V_60 ;
break;
case V_32 :
V_22 -> V_50 . V_51 = V_61 ;
V_22 -> V_50 . V_53 = V_62 ;
V_49 = F_18 ( V_21 -> V_55 . V_56 ) ;
V_22 -> V_50 . V_49 = V_49 ;
V_4 = F_19 (
V_22 -> V_50 . V_53 ,
V_49 ,
& ( V_22 -> V_50 . V_57 ) ) ;
break;
case V_33 :
V_22 -> V_58 . V_59 = V_63 ;
break;
case V_36 :
V_22 -> V_50 . V_51 = V_64 ;
V_22 -> V_50 . V_53 = V_65 ;
V_49 = F_18 ( V_21 -> V_55 . V_56 ) ;
V_22 -> V_50 . V_49 = V_49 ;
V_4 = F_19 (
V_22 -> V_50 . V_53 ,
V_49 ,
& ( V_22 -> V_50 . V_57 ) ) ;
break;
case V_37 :
V_22 -> V_58 . V_59 = V_66 ;
break;
default:
V_4 = false ;
break;
}
V_22 -> V_67 = V_21 -> V_68 ;
V_22 -> V_8 . V_49 = V_69 ;
if ( V_4 && V_21 -> V_8 . V_9 ) {
V_22 -> V_8 . V_49 = F_18 (
V_21 -> V_8 . V_56 ) ;
V_4 = F_19 (
V_22 -> V_50 . V_53 ,
V_22 -> V_8 . V_49 ,
& V_22 -> V_8 . V_57 ) ;
}
return V_4 ;
}
static void F_5 (
T_8 * V_22 )
{
if ( V_22 -> V_67 == V_70 ) {
F_20 (
V_22 -> V_50 . V_53 ,
V_22 -> V_50 . V_49 ,
& V_22 -> V_50 . V_57 ) ;
}
if ( V_22 -> V_8 . V_49 != V_69 ) {
F_20 (
V_22 -> V_50 . V_53 ,
V_22 -> V_8 . V_49 ,
& V_22 -> V_8 . V_57 ) ;
}
}
static bool F_10 (
T_7 * V_13 ,
T_8 * V_12 ,
T_6 * V_71 ,
T_10 * V_17 ,
bool V_8 )
{
bool V_4 ;
V_4 = F_21 ( V_71 , V_8 ,
& ( V_17 -> V_72 ) ) ;
if ( V_4 == false )
return false ;
V_4 = F_22 (
V_13 ,
V_12 ,
V_71 ,
& ( V_17 -> V_73 ) ) ;
if ( V_4 == false )
return false ;
if ( V_8 )
V_17 -> V_73 . V_74 = V_71 -> V_8 . V_44 ;
V_4 = F_23 (
V_13 ,
V_71 ,
& ( V_17 -> V_75 ) ) ;
if ( V_4 == false )
return false ;
V_4 = F_24 (
V_71 ,
false ,
V_8 ,
& ( V_17 -> V_76 ) ) ;
if ( V_4 == false )
return false ;
V_4 = F_24 (
V_71 ,
V_71 -> V_77 ,
V_8 ,
& ( V_17 -> V_78 ) ) ;
if ( V_4 == false )
return false ;
return true ;
}
static bool F_11 (
T_7 * V_13 ,
T_8 * V_12 ,
T_6 * V_71 ,
T_11 * V_19 )
{
bool V_4 ;
switch ( V_12 -> V_67 ) {
case V_70 :
V_4 = F_25 (
V_71 ,
& ( V_19 -> V_79 . V_80 ) ) ;
V_4 &= F_26 (
V_12 ,
V_71 ,
false ,
& ( V_19 -> V_79 . V_81 ) ) ;
if ( V_4 && V_71 -> V_8 . V_9 )
V_4 &= F_26 ( V_12 , V_71 , true ,
& V_19 -> V_79 . V_82 ) ;
break;
case V_83 :
V_4 = F_27 (
V_13 ,
V_12 ,
V_71 ,
& ( V_19 -> V_84 . V_85 ) ) ;
break;
case V_86 :
V_4 = F_28 (
V_13 ,
V_12 ,
V_71 ,
& ( V_19 -> V_84 . V_87 ) ) ;
break;
default:
V_4 = false ;
break;
}
return V_4 ;
}
static bool F_12 (
T_12 V_88 ,
T_13 * V_89 )
{
return F_29 ( V_88 , V_89 ) ;
}
static void F_14 (
T_12 V_88 ,
T_13 * V_89 )
{
F_30 ( V_88 , V_89 ) ;
}
static T_14 F_31 (
T_14 V_41 ,
T_14 V_43 ,
bool V_77 ,
T_14 V_90 )
{
T_14 V_91 ;
T_14 V_92 ;
T_14 V_93 ;
T_14 V_94 ;
V_94 = F_32 ( V_43 , V_90 ) ;
if ( ! V_77 )
V_41 = F_32 ( V_41 , 8 ) ;
V_92 = V_95 / V_41 ;
V_93 = F_33 ( V_94 , V_92 ) ;
V_91 = V_96 * V_93 ;
return V_91 ;
}
static bool F_13 (
T_14 V_41 ,
T_14 V_43 ,
T_14 V_44 ,
T_14 V_90 ,
bool V_46 ,
T_15 * V_97 )
{
V_97 -> V_98 = F_31 ( V_41 , V_43 , false , V_90 ) ;
if ( V_46 )
V_97 -> V_99 = 4 ;
else
V_97 -> V_99 = 2 ;
( void ) ( V_44 ) ;
return F_34 ( V_97 -> V_98 * V_97 -> V_99 , & V_97 -> V_100 ) ;
}
static void F_16 (
T_15 * V_97 )
{
F_35 ( & V_97 -> V_100 ) ;
}
static bool F_15 (
T_16 V_23 ,
T_17 * V_13 )
{
return F_36 ( V_23 , V_13 ) ;
}
static void F_17 (
T_16 V_23 ,
T_17 * V_13 )
{
F_37 ( V_23 , V_13 ) ;
}
static bool F_19 (
T_18 V_101 ,
T_9 V_49 ,
T_19 * V_102 )
{
return F_38 ( V_101 , V_49 , V_102 ) ;
}
static void F_20 (
T_18 V_101 ,
T_9 V_49 ,
T_19 * V_102 )
{
F_39 ( V_101 , V_49 , V_102 ) ;
}
static bool F_27 (
T_7 * V_13 ,
T_8 * V_12 ,
T_6 * V_71 ,
T_20 * V_21 )
{
( void ) V_13 ;
( void ) V_12 ;
F_40 (
( void * ) V_21 ,
sizeof( T_20 ) ,
( void * ) ( & ( V_71 -> V_103 ) ) ,
sizeof( T_20 ) ) ;
return true ;
}
static bool F_28 (
T_7 * V_13 ,
T_8 * V_12 ,
T_6 * V_71 ,
T_21 * V_21 )
{
( void ) V_13 ;
( void ) V_12 ;
F_40 (
( void * ) V_21 ,
sizeof( T_21 ) ,
( void * ) ( & ( V_71 -> V_104 ) ) ,
sizeof( T_21 ) ) ;
return true ;
}
static bool F_25 (
const T_6 * V_71 ,
T_22 * V_21 )
{
V_21 -> V_105 = V_71 -> V_55 . V_105 ;
return true ;
}
static bool F_26 (
const T_8 * V_12 ,
const T_6 * V_71 ,
bool V_8 ,
T_23 * V_21 )
{
F_40 (
( void * ) ( & V_21 -> V_106 ) ,
sizeof( T_19 ) ,
V_8 ? ( void * ) ( & V_12 -> V_8 . V_57 ) :
( void * ) ( & V_12 -> V_50 . V_57 ) ,
sizeof( T_19 ) ) ;
V_21 -> V_107 . V_108 = V_71 -> V_55 . V_109 ;
if ( V_8 ) {
V_21 -> V_110 = F_18 ( V_71 -> V_8 . V_56 ) ;
V_21 -> V_107 . V_111 = false ;
V_21 -> V_107 . V_112 = V_71 -> V_8 . V_56 ;
}
else {
V_21 -> V_110 = F_18 ( V_71 -> V_55 . V_56 ) ;
V_21 -> V_107 . V_112 = V_71 -> V_55 . V_56 ;
V_21 -> V_107 . V_111 = V_71 -> V_55 . V_111 ;
V_21 -> V_107 . V_113 = V_71 -> V_55 . V_113 ;
V_21 -> V_107 . V_114 = V_71 -> V_55 . V_114 ;
V_21 -> V_107 . V_115 = V_21 -> V_107 . V_112 - V_116 ;
}
return true ;
}
static bool F_21 (
const T_6 * V_71 ,
bool V_8 ,
T_24 * V_21
)
{
V_21 -> V_41 = V_8 ? V_71 -> V_8 . V_41 :
V_71 -> V_42 . V_41 ;
V_21 -> V_117 =
( ( V_71 -> V_68 == V_83 ) ||
( V_71 -> V_68 == V_86 ) ) ;
return true ;
}
static bool F_22 (
const T_7 * V_13 ,
const T_8 * V_12 ,
const T_6 * V_71 ,
T_25 * V_21 )
{
const T_14 V_118 = 8 ;
T_14 V_41 ;
T_14 V_119 ;
T_14 V_120 ;
( void ) V_12 ;
V_41 = V_71 -> V_42 . V_41 ;
V_119 = F_33 ( V_41 , V_118 ) ;
V_120 = F_32 ( V_71 -> V_121 . V_120 , V_122 )
* V_119 ;
V_21 -> V_46 = V_71 -> V_46 ;
V_21 -> V_75 . V_13 = V_13 -> V_48 ;
V_21 -> V_75 . V_123 = V_124 ;
V_21 -> V_75 . V_125 = 0 ;
V_21 -> V_75 . V_126 = 0 ;
V_21 -> V_75 . V_127 = 0 ;
V_21 -> V_47 . V_100 = V_13 -> V_47 . V_100 ;
V_21 -> V_47 . V_98 = V_13 -> V_47 . V_98 ;
V_21 -> V_47 . V_99 = V_13 -> V_47 . V_99 ;
if ( V_21 -> V_46 ) {
V_21 -> V_128 . V_100 = V_129 + V_120 ;
V_21 -> V_128 . V_98 = V_119
* V_71 -> V_121 . V_130 ;
V_21 -> V_128 . V_99 = V_131 ;
} else if ( V_71 -> V_77 ) {
V_21 -> V_128 . V_98 = F_31 ( V_41 ,
V_71 -> V_42 . V_43 ,
V_71 -> V_77 ,
V_71 -> V_42 . V_45 ) ;
} else {
V_21 -> V_128 . V_98 = V_13 -> V_47 . V_98 ;
}
V_21 -> V_132 = 1 ;
V_21 -> V_74 = V_71 -> V_42 . V_44 ;
V_21 -> V_72 . V_133 = V_134 ;
V_21 -> V_72 . V_135 = V_136 ;
return true ;
}
static bool F_23 (
const T_7 * V_13 ,
const T_6 * V_71 ,
T_26 * V_21 )
{
V_21 -> V_13 = V_13 -> V_48 ;
if ( V_71 -> V_46 )
V_21 -> V_137 = V_138 ;
else
V_21 -> V_137 = V_139 ;
V_21 -> V_140 = V_141 ;
V_21 -> V_142 = 1 ;
return true ;
}
static bool F_24 (
const T_6 * V_71 ,
bool V_77 ,
bool V_8 ,
T_27 * V_21 )
{
T_14 V_41 ;
T_14 V_43 ;
T_14 V_45 ;
if ( V_8 ) {
V_41 = V_71 -> V_8 . V_41 ;
V_43 = V_71 -> V_8 . V_43 ;
V_45 = V_71 -> V_8 . V_45 ;
} else {
V_41 = V_71 -> V_42 . V_41 ;
V_43 = V_71 -> V_42 . V_43 ;
V_45 = V_71 -> V_42 . V_45 ;
}
V_21 -> V_98 = F_31 ( V_41 , V_43 , V_77 , V_45 ) ;
if ( ! V_77 )
V_41 = F_32 ( V_41 , 8 ) ;
V_21 -> V_143 = V_95 / V_41 ;
V_21 -> V_144 = 0 ;
V_21 -> V_145 = F_41 ( V_21 -> V_98 , V_96 ) ;
return true ;
}
static T_9 F_18 (
T_14 V_112 )
{
T_9 V_49 ;
V_49 = V_146 ;
if ( V_112 >= 0 && V_112 <= V_147 )
V_49 = V_148 ;
if ( V_112 > V_147 && V_112 <= V_149 )
V_49 = V_150 ;
return V_49 ;
}
