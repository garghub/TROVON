static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_11 * V_12 ,
enum V_13 V_14 )
{
unsigned int V_15 ;
int V_16 ;
if ( V_14 != V_17 ) {
V_16 = F_3 ( V_12 -> V_18 , V_4 ,
& V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_19 [ V_14 ] . V_20 & V_21 ) !=
( V_15 & V_21 ) ) {
V_16 = F_4 ( V_12 -> V_18 ,
V_4 , V_22 ,
V_23 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_16 = F_4 ( V_12 -> V_18 , V_24 ,
V_25 , V_19 [ V_14 ]
. V_26 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_12 -> V_18 , V_27 ,
V_28 , V_19 [ V_14 ]
. V_29 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_12 -> V_18 , V_30 ,
V_31 , V_19 [ V_14 ]
. V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_16 = F_4 ( V_12 -> V_18 ,
V_4 ,
V_21 | V_33 |
V_22 | V_34 ,
V_19 [ V_14 ] . V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_12 -> V_35 = V_14 ;
return 0 ;
}
static bool F_5 ( struct V_11 * V_12 )
{
return F_6 ( V_36 , & V_12 -> V_37 ) ||
F_6 ( V_38 , & V_12 -> V_37 ) ||
F_6 ( V_39 , & V_12 -> V_37 ) ||
F_6 ( V_40 , & V_12 -> V_37 ) ;
}
static bool F_7 ( struct V_11 * V_12 )
{
return F_6 ( V_41 , & V_12 -> V_37 ) ||
F_6 ( V_42 , & V_12 -> V_37 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
enum V_43 V_44 ,
bool V_45 )
{
T_1 V_46 = 0 ;
unsigned int V_47 ;
if ( ! V_45 )
V_47 = 0 ;
else if ( F_6 ( V_48 , & V_12 -> V_37 ) &&
V_44 != V_49 &&
V_44 != V_50 )
V_47 = V_12 -> V_51 [ V_44 ] / 16 ;
else
V_47 = V_12 -> V_51 [ V_44 ] > 16000 ?
16000 :
V_12 -> V_51 [ V_44 ] ;
V_46 = F_9 ( V_47 ) ;
return F_10 ( V_12 -> V_18 ,
F_11 ( V_44 ) ,
( V_52 * ) & V_46 , 2 ) ;
}
static int F_12 ( struct V_11 * V_12 ,
enum V_13 V_53 , int V_54 )
{
enum V_13 V_55 ;
if ( V_53 != V_56 &&
V_53 != V_57 )
return - V_58 ;
if ( V_54 == V_59 ) {
if ( V_12 -> V_35 == V_17 )
V_55 = V_53 ;
else
V_55 = V_60 ;
} else {
if ( V_12 -> V_35 == V_60 )
V_55 = ( V_53 == V_56 ) ?
V_57 :
V_56 ;
else
V_55 = V_17 ;
}
return F_2 ( V_12 , V_55 ) ;
}
static int F_13 ( struct V_11 * V_12 ,
enum V_61 V_62 )
{
int V_16 = 0 ;
switch ( V_62 ) {
case V_63 :
if ( V_12 -> V_35 != V_17 )
return - V_64 ;
V_16 = F_2 ( V_12 ,
V_65 ) ;
break;
case V_66 :
if ( V_12 -> V_35 != V_17 )
return - V_64 ;
V_16 = F_2 ( V_12 ,
V_67 ) ;
break;
case V_68 :
if ( V_12 -> V_35 != V_17 )
return - V_64 ;
V_16 = F_2 ( V_12 ,
V_69 ) ;
break;
case V_70 :
if ( V_12 -> V_35 == V_71 )
return - V_64 ;
if ( ! F_5 ( V_12 ) )
V_16 = F_12 ( V_12 ,
V_56 ,
V_59 ) ;
F_14 ( V_36 , & V_12 -> V_37 ) ;
break;
case V_72 :
F_15 ( V_36 , & V_12 -> V_37 ) ;
if ( F_5 ( V_12 ) )
break;
V_16 = F_12 ( V_12 ,
V_56 ,
V_73 ) ;
break;
case V_74 :
if ( V_12 -> V_35 == V_71 )
return - V_64 ;
if ( ! F_5 ( V_12 ) )
V_16 = F_12 ( V_12 ,
V_56 ,
V_59 ) ;
F_14 ( V_38 , & V_12 -> V_37 ) ;
break;
case V_75 :
F_15 ( V_38 , & V_12 -> V_37 ) ;
if ( F_5 ( V_12 ) )
break;
V_16 = F_12 ( V_12 ,
V_56 ,
V_73 ) ;
break;
case V_76 :
if ( V_12 -> V_35 == V_71 )
return - V_64 ;
V_16 = F_12 ( V_12 ,
V_57 ,
V_59 ) ;
F_14 ( V_77 , & V_12 -> V_37 ) ;
break;
case V_78 :
F_15 ( V_77 , & V_12 -> V_37 ) ;
V_16 = F_12 ( V_12 ,
V_57 ,
V_73 ) ;
break;
case V_79 :
if ( F_6 ( V_39 , & V_12 -> V_37 ) )
return 0 ;
if ( V_12 -> V_35 == V_71 )
return - V_64 ;
if ( ! F_5 ( V_12 ) ) {
V_16 = F_12 ( V_12 ,
V_56 ,
V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_14 ( V_39 , & V_12 -> V_37 ) ;
V_16 = F_8 ( V_12 ,
V_80 , true ) ;
break;
case V_81 :
if ( ! F_6 ( V_39 , & V_12 -> V_37 ) )
return 0 ;
F_15 ( V_39 , & V_12 -> V_37 ) ;
if ( ! F_5 ( V_12 ) ) {
V_16 = F_12 ( V_12 ,
V_56 ,
V_73 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_16 = F_8 ( V_12 ,
V_80 , false ) ;
break;
case V_82 :
if ( F_6 ( V_40 , & V_12 -> V_37 ) )
return 0 ;
if ( V_12 -> V_35 == V_71 )
return - V_64 ;
if ( ! F_5 ( V_12 ) ) {
V_16 = F_12 ( V_12 ,
V_56 ,
V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_14 ( V_40 , & V_12 -> V_37 ) ;
V_16 = F_8 ( V_12 ,
V_83 , true ) ;
break;
case V_84 :
if ( ! F_6 ( V_40 , & V_12 -> V_37 ) )
return 0 ;
F_15 ( V_40 , & V_12 -> V_37 ) ;
if ( ! F_5 ( V_12 ) ) {
V_16 = F_12 ( V_12 ,
V_56 ,
V_73 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_16 = F_8 ( V_12 ,
V_83 , false ) ;
break;
case V_85 :
if ( F_6 ( V_41 , & V_12 -> V_37 ) )
return 0 ;
if ( F_5 ( V_12 ) ||
V_12 -> V_35 == V_57 )
return - V_64 ;
if ( ! F_7 ( V_12 ) ) {
V_16 = F_2 ( V_12 ,
V_71 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_14 ( V_41 , & V_12 -> V_37 ) ;
V_16 = F_8 ( V_12 ,
V_50 , true ) ;
break;
case V_86 :
if ( ! F_6 ( V_41 , & V_12 -> V_37 ) )
return 0 ;
F_15 ( V_41 , & V_12 -> V_37 ) ;
V_16 = F_2 ( V_12 ,
V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_12 ,
V_50 , false ) ;
break;
case V_87 :
if ( F_6 ( V_42 , & V_12 -> V_37 ) )
return 0 ;
if ( F_5 ( V_12 ) ||
V_12 -> V_35 == V_57 )
return - V_64 ;
if ( ! F_7 ( V_12 ) ) {
V_16 = F_2 ( V_12 ,
V_71 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_14 ( V_42 , & V_12 -> V_37 ) ;
V_16 = F_8 ( V_12 ,
V_49 , true ) ;
break;
case V_88 :
if ( ! F_6 ( V_42 , & V_12 -> V_37 ) )
return 0 ;
F_15 ( V_42 , & V_12 -> V_37 ) ;
V_16 = F_2 ( V_12 ,
V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_12 ,
V_49 , false ) ;
break;
}
return V_16 ;
}
static int F_16 ( struct V_11 * V_12 )
{
int V_89 ;
V_89 = F_17 ( V_12 -> V_90 ,
F_6 ( V_91 ,
& V_12 -> V_37 ) ,
V_92 ) ;
F_15 ( V_91 , & V_12 -> V_37 ) ;
return V_89 > 0 ? 0 : - V_93 ;
}
static int F_18 ( struct V_11 * V_12 ,
unsigned int V_94 , int * V_95 )
{
V_52 V_96 [ 2 ] ;
int V_16 ;
V_16 = F_16 ( V_12 ) ;
if ( V_16 < 0 )
F_19 ( & V_12 -> V_97 -> V_2 , L_1 ) ;
V_16 = F_20 ( V_12 -> V_18 , V_94 , V_96 , 2 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_95 = F_21 ( ( T_1 * ) V_96 ) ;
return V_16 ;
}
static bool F_22 ( struct V_11 * V_12 ,
int V_98 )
{
V_52 V_99 = 0xff ;
int V_16 ;
if ( ! F_6 ( V_48 , & V_12 -> V_37 ) ) {
if ( V_98 > 16000 ) {
F_14 ( V_48 , & V_12 -> V_37 ) ;
V_99 = V_100 ;
}
} else {
if ( V_98 < 1000 ) {
F_15 ( V_48 , & V_12 -> V_37 ) ;
V_99 = V_101 ;
}
}
if ( V_99 != 0xff ) {
V_16 = F_8 ( V_12 ,
V_80 , false ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_2 ) ;
return false ;
}
V_16 = F_8 ( V_12 ,
V_83 , false ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_2 ) ;
return false ;
}
V_16 = F_4 ( V_12 -> V_18 ,
V_4 ,
V_22 ,
V_23 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_3 ) ;
return false ;
}
V_16 = F_4 ( V_12 -> V_18 ,
V_24 ,
V_102 ,
V_99 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_4 ) ;
return false ;
}
V_16 = F_4 ( V_12 -> V_18 ,
V_4 ,
V_22 ,
V_103 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_5 ) ;
return false ;
}
if ( F_6 ( V_39 , & V_12 -> V_37 ) ) {
V_16 = F_8 ( V_12 ,
V_80 , true ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_6 ) ;
return false ;
}
}
if ( F_6 ( V_40 , & V_12 -> V_37 ) ) {
V_16 = F_8 ( V_12 ,
V_83 , true ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_6 ) ;
return false ;
}
}
return true ;
}
return false ;
}
static void F_24 ( struct V_11 * V_12 ,
int * V_98 )
{
if ( F_6 ( V_48 , & V_12 -> V_37 ) )
* V_98 *= 16 ;
}
static void F_25 ( struct V_104 * V_105 )
{
struct V_11 * V_12 =
F_26 ( V_105 , struct V_11 , V_105 ) ;
F_27 ( V_12 -> V_106 ) ;
}
static T_2 F_28 ( int V_107 , void * V_12 )
{
struct V_108 * V_109 = V_12 ;
struct V_11 * V_110 = F_29 ( V_109 ) ;
unsigned int V_15 ;
int V_89 ;
V_89 = F_3 ( V_110 -> V_18 , V_4 , & V_15 ) ;
if ( V_89 < 0 )
return V_111 ;
if ( F_7 ( V_110 ) ) {
if ( V_15 & V_112 ) {
F_30 ( V_109 ,
F_31 (
V_113 ,
V_114 ,
V_115 ,
V_116 ) ,
F_32 () ) ;
} else {
F_30 ( V_109 ,
F_31 (
V_113 ,
V_114 ,
V_115 ,
V_117 ) ,
F_32 () ) ;
}
}
return V_111 ;
}
static T_2 F_33 ( int V_107 , void * V_12 )
{
struct V_108 * V_109 = V_12 ;
struct V_11 * V_110 = F_29 ( V_109 ) ;
V_52 V_118 , V_119 [ 2 ] ;
unsigned int V_98 , V_15 ;
int V_120 , V_89 ;
V_89 = F_3 ( V_110 -> V_18 , V_4 ,
& V_15 ) ;
if ( V_89 < 0 )
goto V_121;
V_118 = V_15 & ( V_122 | V_123
| V_112 ) ;
V_15 &= ( ~ V_122 & ~ V_123
& ~ V_112 ) ;
if ( V_110 -> V_35 != V_71 ) {
V_89 = F_34 ( V_110 -> V_18 , V_4 ,
V_15 ) ;
if ( V_89 < 0 )
goto V_121;
}
if ( V_118 & V_122 ) {
V_89 = F_20 ( V_110 -> V_18 , V_5 ,
V_119 , 2 ) ;
if ( V_89 < 0 )
goto V_121;
V_98 = F_21 ( ( T_1 * ) V_119 ) ;
if ( F_22 ( V_110 , V_98 ) )
goto V_121;
F_24 ( V_110 , & V_98 ) ;
if ( F_6 ( V_39 , & V_110 -> V_37 ) ) {
V_120 =
F_35 ( V_124 ) ;
if ( V_98 > V_110 -> V_51 [ V_120 ] )
F_30 ( V_109 ,
F_36 (
V_125 ,
V_126 ,
V_127 ,
V_128 ,
V_116 ) ,
F_32 () ) ;
}
if ( F_6 ( V_40 , & V_110 -> V_37 ) ) {
V_120 =
F_35 ( V_129 ) ;
if ( V_98 < V_110 -> V_51 [ V_120 ] )
F_30 ( V_109 ,
F_36 (
V_125 ,
V_126 ,
V_127 ,
V_128 ,
V_117 ) ,
F_32 () ) ;
}
}
if ( V_110 -> V_35 == V_65 ||
V_110 -> V_35 == V_67 ||
V_110 -> V_35 == V_69 ) {
F_14 ( V_91 , & V_110 -> V_37 ) ;
F_37 ( & V_110 -> V_90 ) ;
goto V_121;
}
if ( F_6 ( V_36 , & V_110 -> V_37 ) ||
F_6 ( V_38 , & V_110 -> V_37 ) ||
F_6 ( V_77 , & V_110 -> V_37 ) )
F_38 ( & V_110 -> V_105 ) ;
V_121:
return V_111 ;
}
static T_2 F_39 ( int V_107 , void * V_12 )
{
struct V_130 * V_131 = V_12 ;
struct V_108 * V_109 = V_131 -> V_109 ;
struct V_11 * V_110 = F_29 ( V_109 ) ;
T_3 V_132 = 0 ;
T_4 V_133 ;
int V_134 , V_135 , V_89 ;
F_40 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_89 = F_20 ( V_110 -> V_18 ,
F_41 ( V_134 ) ,
& V_110 -> V_136 [ V_132 ] , 2 ) ;
if ( V_89 < 0 )
goto V_121;
if ( V_134 == V_126 ||
V_134 == V_137 ) {
V_135 = F_21 ( ( T_1 * ) & V_110 -> V_136 [ V_132 ] ) ;
F_24 ( V_110 , & V_135 ) ;
V_133 = F_42 ( V_135 ) ;
memcpy ( & V_110 -> V_136 [ V_132 ] , ( V_52 * ) & V_133 , 4 ) ;
V_132 += 4 ;
} else {
V_132 += 2 ;
}
}
F_43 ( V_109 , V_110 -> V_136 ,
V_131 -> V_138 ) ;
V_121:
F_44 ( V_109 -> V_106 ) ;
return V_111 ;
}
static V_52 F_45 ( const struct V_139 * V_140 ,
enum V_141 V_142 )
{
switch ( V_140 -> type ) {
case V_113 :
if ( V_142 == V_116 )
return V_143 ;
else
return V_144 ;
case V_125 :
if ( V_142 == V_116 )
return V_124 ;
else
return V_129 ;
default:
break;
}
return - V_58 ;
}
static int F_46 ( struct V_108 * V_109 ,
const struct V_139 * V_140 ,
enum V_145 type ,
enum V_141 V_146 ,
enum V_147 V_148 ,
int V_95 , int V_149 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
bool V_150 = false ;
V_52 V_120 ;
V_52 V_151 ;
int V_16 = 0 ;
F_47 ( & V_12 -> V_152 ) ;
V_151 = F_45 ( V_140 , V_146 ) ;
V_120 = F_35 ( V_151 ) ;
if ( V_120 > V_50 ) {
V_16 = - V_58 ;
goto V_153;
}
switch ( V_151 ) {
case V_124 :
V_150 = F_6 ( V_39 ,
& V_12 -> V_37 ) ;
break;
case V_129 :
V_150 = F_6 ( V_40 ,
& V_12 -> V_37 ) ;
break;
case V_143 :
if ( V_95 == 0 ) {
V_16 = - V_58 ;
goto V_153;
}
V_150 = F_6 ( V_41 ,
& V_12 -> V_37 ) ;
break;
case V_144 :
if ( V_95 == 0 ) {
V_16 = - V_58 ;
goto V_153;
}
V_150 = F_6 ( V_42 ,
& V_12 -> V_37 ) ;
break;
}
V_12 -> V_51 [ V_120 ] = V_95 ;
V_16 = F_8 ( V_12 , V_120 ,
V_150 ) ;
V_153:
F_48 ( & V_12 -> V_152 ) ;
return V_16 ;
}
static int F_49 ( struct V_108 * V_109 ,
const struct V_139 * V_140 ,
enum V_145 type ,
enum V_141 V_146 ,
enum V_147 V_148 ,
int * V_95 , int * V_149 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
V_52 V_151 ;
int V_16 = V_154 ;
F_47 ( & V_12 -> V_152 ) ;
V_151 = F_45 ( V_140 , V_146 ) ;
if ( V_151 > V_143 ) {
V_16 = - V_58 ;
goto V_153;
}
* V_95 = V_12 -> V_51 [ F_35 ( V_151 ) ] ;
V_153:
F_48 ( & V_12 -> V_152 ) ;
return V_16 ;
}
static int F_50 ( struct V_108 * V_109 ,
int V_155 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
enum V_61 V_156 , V_157 ;
int V_16 ;
V_156 = V_155 ? V_85 :
V_86 ;
V_157 = V_155 ? V_87 :
V_88 ;
if ( V_155 ) {
if ( V_12 -> V_51 [ V_49 ] == 0 )
return - V_58 ;
if ( V_12 -> V_51 [ V_50 ] == 0 )
return - V_58 ;
}
V_16 = F_13 ( V_12 , V_156 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_13 ( V_12 , V_157 ) ;
if ( V_16 < 0 )
return V_16 ;
F_51 ( V_12 -> V_97 -> V_107 , V_109 ) ;
if ( V_155 )
V_16 = F_52 ( V_12 -> V_97 -> V_107 , NULL ,
& F_28 ,
V_158 |
V_159 |
V_160 ,
L_7 ,
V_109 ) ;
else {
V_16 = F_52 ( V_12 -> V_97 -> V_107 , NULL ,
& F_33 ,
V_159 |
V_160 ,
L_8 ,
V_109 ) ;
}
return V_16 ;
}
static int F_53 ( struct V_108 * V_109 ,
const struct V_139 * V_140 ,
enum V_145 type ,
enum V_141 V_146 ,
int V_155 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
enum V_61 V_62 ;
int V_16 ;
F_47 ( & V_12 -> V_152 ) ;
switch ( V_140 -> type ) {
case V_113 :
V_16 = F_50 ( V_109 , V_155 ) ;
break;
case V_125 :
if ( V_146 == V_116 ) {
V_62 = V_155 ? V_79 :
V_81 ;
V_16 = F_13 ( V_12 , V_62 ) ;
} else {
V_62 = V_155 ? V_82 :
V_84 ;
V_16 = F_13 ( V_12 , V_62 ) ;
}
break;
default:
V_16 = - V_58 ;
}
F_48 ( & V_12 -> V_152 ) ;
return V_16 ;
}
static int F_54 ( struct V_108 * V_109 ,
const struct V_139 * V_140 ,
enum V_145 type ,
enum V_141 V_146 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
int V_150 = 0 ;
F_47 ( & V_12 -> V_152 ) ;
switch ( V_140 -> type ) {
case V_113 :
if ( V_146 == V_116 )
V_150 = F_6 ( V_41 ,
& V_12 -> V_37 ) ;
else
V_150 = F_6 ( V_42 ,
& V_12 -> V_37 ) ;
break;
case V_125 :
if ( V_146 == V_116 )
V_150 = F_6 ( V_39 ,
& V_12 -> V_37 ) ;
else
V_150 = F_6 ( V_40 ,
& V_12 -> V_37 ) ;
break;
default:
V_150 = - V_58 ;
break;
}
F_48 ( & V_12 -> V_152 ) ;
return V_150 ;
}
static int F_55 ( struct V_11 * V_12 ,
struct V_139 const * V_140 , int * V_95 )
{
enum V_61 V_62 ;
int V_16 ;
switch ( V_140 -> V_161 ) {
case V_126 :
V_62 = V_63 ;
break;
case V_137 :
V_62 = V_66 ;
break;
case V_114 :
V_62 = V_68 ;
break;
default:
return - V_58 ;
}
V_16 = F_13 ( V_12 , V_62 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_12 -> V_97 -> V_2 ,
L_9 ) ;
goto V_162;
}
V_16 = F_18 ( V_12 , V_140 -> V_163 , V_95 ) ;
if ( V_16 < 0 )
F_23 ( & V_12 -> V_97 -> V_2 ,
L_10 ) ;
V_16 = F_2 ( V_12 ,
V_17 ) ;
if ( V_16 < 0 )
F_23 ( & V_12 -> V_97 -> V_2 ,
L_11 ) ;
if ( V_62 == V_63 ||
V_62 == V_66 )
F_24 ( V_12 , V_95 ) ;
V_162:
return V_16 ;
}
static int F_56 ( struct V_108 * V_109 ,
struct V_139 const * V_140 ,
int * V_95 , int * V_149 ,
long V_164 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
int V_16 = - V_58 ;
F_47 ( & V_12 -> V_152 ) ;
switch ( V_164 ) {
case V_165 :
if ( F_57 ( V_109 ) ) {
V_16 = - V_64 ;
goto V_153;
}
V_16 = F_55 ( V_12 , V_140 , V_95 ) ;
break;
}
V_153:
F_48 ( & V_12 -> V_152 ) ;
return V_16 < 0 ? V_16 : V_154 ;
}
static int F_58 ( struct V_108 * V_109 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
int V_134 , V_16 = 0 ;
F_47 ( & V_12 -> V_152 ) ;
F_40 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
switch ( V_134 ) {
case V_126 :
V_16 = F_13 ( V_12 ,
V_70 ) ;
break;
case V_137 :
V_16 = F_13 ( V_12 ,
V_74 ) ;
break;
case V_114 :
V_16 = F_13 ( V_12 ,
V_76 ) ;
break;
}
}
if ( V_16 < 0 )
goto V_153;
V_12 -> V_136 = F_59 ( V_109 -> V_166 , V_167 ) ;
if ( ! V_12 -> V_136 ) {
V_16 = - V_168 ;
goto V_153;
}
V_16 = F_60 ( V_109 ) ;
V_153:
F_48 ( & V_12 -> V_152 ) ;
return V_16 ;
}
static int F_61 ( struct V_108 * V_109 )
{
struct V_11 * V_12 = F_29 ( V_109 ) ;
int V_134 , V_16 ;
F_47 ( & V_12 -> V_152 ) ;
V_16 = F_62 ( V_109 ) ;
if ( V_16 < 0 )
goto V_153;
F_40 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
switch ( V_134 ) {
case V_126 :
V_16 = F_13 ( V_12 ,
V_72 ) ;
break;
case V_137 :
V_16 = F_13 ( V_12 ,
V_75 ) ;
break;
case V_114 :
V_16 = F_13 ( V_12 ,
V_78 ) ;
break;
}
}
if ( V_16 == 0 )
F_63 ( V_12 -> V_136 ) ;
V_153:
F_48 ( & V_12 -> V_152 ) ;
return V_16 ;
}
static int F_64 ( struct V_169 * V_97 ,
const struct V_170 * V_171 )
{
struct V_11 * V_12 ;
struct V_108 * V_109 ;
struct V_18 * V_18 ;
int V_16 ;
V_109 = F_65 ( & V_97 -> V_2 , sizeof( * V_12 ) ) ;
if ( ! V_109 )
return - V_168 ;
V_12 = F_29 ( V_109 ) ;
V_12 -> V_172 = F_66 ( & V_97 -> V_2 , L_12 ) ;
if ( F_67 ( V_12 -> V_172 ) )
return F_68 ( V_12 -> V_172 ) ;
V_16 = F_69 ( V_12 -> V_172 ) ;
if ( V_16 )
return V_16 ;
V_18 = F_70 ( V_97 , & V_173 ) ;
if ( F_67 ( V_18 ) ) {
F_23 ( & V_97 -> V_2 , L_13 ) ;
V_16 = F_68 ( V_18 ) ;
goto V_174;
}
V_16 = F_10 ( V_18 , V_4 ,
V_175 ,
F_71 ( V_175 ) ) ;
if ( V_16 < 0 ) {
F_23 ( & V_97 -> V_2 , L_14 ) ;
goto V_174;
}
F_72 ( V_97 , V_109 ) ;
V_12 -> V_97 = V_97 ;
V_12 -> V_35 = V_17 ;
V_12 -> V_18 = V_18 ;
F_73 ( & V_12 -> V_90 ) ;
F_74 ( & V_12 -> V_152 ) ;
V_109 -> V_2 . V_176 = & V_97 -> V_2 ;
V_109 -> V_177 = V_178 ;
V_109 -> V_179 = F_71 ( V_178 ) ;
V_109 -> V_148 = & V_180 ;
V_109 -> V_181 = V_171 -> V_181 ;
V_109 -> V_182 = V_183 ;
V_16 = F_75 ( V_109 , & V_184 ,
& F_39 , & V_185 ) ;
if ( V_16 < 0 )
goto V_174;
V_12 -> V_106 = F_76 ( & V_97 -> V_2 , L_15 ,
V_109 -> V_181 ) ;
if ( V_12 -> V_106 == NULL ) {
V_16 = - V_168 ;
F_23 ( & V_109 -> V_2 , L_16 ) ;
goto V_186;
}
V_16 = F_52 ( V_97 -> V_107 , NULL ,
& F_33 ,
V_159 |
V_160 ,
L_17 ,
V_109 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_97 -> V_2 , L_18 ) ;
goto V_186;
}
V_12 -> V_106 -> V_187 = & V_188 ;
V_12 -> V_106 -> V_2 . V_176 = & V_12 -> V_97 -> V_2 ;
F_77 ( & V_12 -> V_105 , F_25 ) ;
V_16 = F_78 ( V_12 -> V_106 ) ;
if ( V_16 < 0 ) {
F_23 ( & V_97 -> V_2 , L_19 ) ;
goto V_189;
}
V_16 = F_79 ( V_109 ) ;
if ( V_16 < 0 )
goto V_190;
return 0 ;
V_190:
F_80 ( V_12 -> V_106 ) ;
V_189:
F_51 ( V_97 -> V_107 , V_109 ) ;
V_186:
F_81 ( V_109 ) ;
V_174:
F_82 ( V_12 -> V_172 ) ;
return V_16 ;
}
static int F_83 ( struct V_169 * V_97 )
{
struct V_108 * V_109 = F_84 ( V_97 ) ;
struct V_11 * V_12 = F_29 ( V_109 ) ;
int V_16 ;
V_16 = F_2 ( V_12 ,
V_17 ) ;
if ( V_16 < 0 )
F_23 ( & V_109 -> V_2 , L_20 ) ;
F_85 ( V_109 ) ;
F_80 ( V_12 -> V_106 ) ;
F_51 ( V_97 -> V_107 , V_109 ) ;
F_81 ( V_109 ) ;
F_82 ( V_12 -> V_172 ) ;
return 0 ;
}
