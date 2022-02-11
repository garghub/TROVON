void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = F_2 ( V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_9 = F_2 ( V_4 -> V_9 ) ;
V_2 -> V_10 = F_2 ( V_4 -> V_10 ) ;
V_2 -> V_11 [ 0 ] = 0 ;
V_2 -> V_11 [ 1 ] = 0 ;
V_2 -> V_11 [ 2 ] = 0 ;
}
void
F_3 (
struct V_3 * V_2 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = F_4 ( V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_9 = F_4 ( V_4 -> V_9 ) ;
V_2 -> V_10 = F_4 ( V_4 -> V_10 ) ;
}
static int
F_5 (
struct V_12 * V_2 ,
struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_6 & V_13 ) ) {
V_2 -> V_14 = V_4 -> V_8 ;
return 0 ;
}
switch ( V_4 -> V_8 ) {
case 0 :
case - 1ULL :
V_2 -> V_14 = 0 ;
break;
case V_15 :
V_2 -> V_14 = V_16 ;
break;
case V_17 :
V_2 -> V_14 = V_18 ;
break;
case V_19 :
V_2 -> V_14 = V_20 ;
break;
case V_21 :
V_2 -> V_14 = V_22 ;
break;
case V_23 :
V_2 -> V_14 = V_24 ;
break;
case V_25 :
V_2 -> V_14 = V_26 ;
break;
case V_27 :
V_2 -> V_14 = V_28 ;
break;
case V_29 :
V_2 -> V_14 = V_30 ;
break;
case V_31 :
V_2 -> V_14 = V_32 ;
break;
case V_33 :
default:
return - V_34 ;
}
return 0 ;
}
static int
F_6 (
struct V_3 * V_2 ,
struct V_12 * V_4 )
{
V_2 -> V_6 = 0 ;
if ( ! F_7 ( V_4 -> V_14 ) ) {
V_2 -> V_8 = V_4 -> V_14 ;
return 0 ;
}
V_2 -> V_6 |= V_13 ;
switch ( V_4 -> V_14 ) {
case V_20 :
V_2 -> V_8 = V_19 ;
break;
case V_22 :
V_2 -> V_8 = V_21 ;
break;
case V_24 :
V_2 -> V_8 = V_23 ;
break;
case V_26 :
V_2 -> V_8 = V_25 ;
break;
case V_28 :
V_2 -> V_8 = V_27 ;
break;
case V_30 :
V_2 -> V_8 = V_29 ;
break;
case V_32 :
V_2 -> V_8 = V_31 ;
break;
case V_16 :
V_2 -> V_8 = V_15 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int
F_8 (
const void * V_36 ,
const void * V_37 )
{
const struct V_38 * V_39 = V_36 ;
const struct V_38 * V_40 = V_37 ;
return V_39 -> V_41 - V_40 -> V_41 ;
}
STATIC int
F_9 (
struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_12 * V_46 ,
bool * V_47 )
{
struct V_48 * V_49 = V_43 -> V_50 ;
struct V_51 * V_52 ;
T_1 V_53 ;
T_2 V_54 ;
int error ;
* V_47 = false ;
if ( ! F_10 ( & V_49 -> V_55 ) )
return 0 ;
if ( V_45 -> V_56 == V_57 )
return 0 ;
V_54 = 0 ;
V_52 = F_11 ( V_49 , V_43 , V_45 -> V_58 ,
V_45 -> V_56 , NULL ) ;
error = F_12 ( V_52 , V_46 -> V_59 ,
V_46 -> V_60 , & V_53 , & V_54 , false ) ;
F_13 ( V_52 , error ? V_61 : V_62 ) ;
if ( error )
return error ;
* V_47 = V_54 > 0 ;
return 0 ;
}
STATIC int
F_14 (
struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_12 * V_46 ,
T_3 V_63 )
{
struct V_3 V_64 ;
struct V_48 * V_49 = V_43 -> V_50 ;
bool V_65 ;
int error ;
if ( F_15 ( V_66 ) )
return - V_67 ;
if ( F_16 ( V_46 , & V_45 -> V_68 ) < 0 ) {
V_63 += F_17 ( V_49 , V_46 -> V_60 ) ;
if ( V_45 -> V_69 < V_63 )
V_45 -> V_69 = V_63 ;
return V_70 ;
}
if ( V_45 -> V_71 -> V_72 == 0 ) {
if ( V_63 > V_45 -> V_69 )
V_45 -> V_71 -> V_73 ++ ;
if ( V_45 -> V_74 )
return V_70 ;
V_45 -> V_71 -> V_73 ++ ;
V_63 += F_17 ( V_49 , V_46 -> V_60 ) ;
if ( V_45 -> V_69 < V_63 )
V_45 -> V_69 = V_63 ;
return V_70 ;
}
if ( V_63 > V_45 -> V_69 ) {
if ( V_45 -> V_71 -> V_73 >= V_45 -> V_71 -> V_72 )
return V_75 ;
V_64 . V_5 = V_45 -> V_41 ;
V_64 . V_7 = V_45 -> V_69 ;
V_64 . V_8 = V_45 -> V_76 ;
V_64 . V_9 = 0 ;
V_64 . V_10 = V_63 - V_45 -> V_69 ;
V_64 . V_6 = V_13 ;
error = V_45 -> V_77 ( & V_64 , V_45 -> V_78 ) ;
if ( error )
return error ;
V_45 -> V_71 -> V_73 ++ ;
}
if ( V_45 -> V_74 )
goto V_79;
if ( V_45 -> V_71 -> V_73 >= V_45 -> V_71 -> V_72 )
return V_75 ;
F_18 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , V_46 ) ;
V_64 . V_5 = V_45 -> V_41 ;
V_64 . V_7 = V_63 ;
error = F_6 ( & V_64 , V_46 ) ;
if ( error )
return error ;
V_64 . V_9 = F_17 ( V_49 , V_46 -> V_80 ) ;
V_64 . V_10 = F_17 ( V_49 , V_46 -> V_60 ) ;
if ( V_46 -> V_81 & V_82 )
V_64 . V_6 |= V_83 ;
if ( V_46 -> V_81 & V_84 )
V_64 . V_6 |= V_85 ;
if ( V_46 -> V_81 & V_86 )
V_64 . V_6 |= V_87 ;
if ( V_64 . V_6 == 0 ) {
error = F_9 ( V_43 , V_45 , V_46 , & V_65 ) ;
if ( error )
return error ;
if ( V_65 )
V_64 . V_6 |= V_88 ;
}
error = V_45 -> V_77 ( & V_64 , V_45 -> V_78 ) ;
if ( error )
return error ;
V_45 -> V_71 -> V_73 ++ ;
V_79:
V_63 += F_17 ( V_49 , V_46 -> V_60 ) ;
if ( V_45 -> V_69 < V_63 )
V_45 -> V_69 = V_63 ;
return V_70 ;
}
STATIC int
F_19 (
struct V_51 * V_52 ,
struct V_12 * V_46 ,
void * V_89 )
{
struct V_48 * V_49 = V_52 -> V_90 ;
struct V_44 * V_45 = V_89 ;
T_4 V_91 ;
T_3 V_63 ;
V_91 = F_20 ( V_49 , V_52 -> V_92 . V_93 . V_56 , V_46 -> V_59 ) ;
V_63 = F_21 ( V_49 , V_91 ) ;
return F_14 ( V_52 -> V_94 , V_45 , V_46 , V_63 ) ;
}
STATIC int
F_22 (
struct V_42 * V_43 ,
struct V_95 * V_46 ,
void * V_89 )
{
struct V_48 * V_49 = V_43 -> V_50 ;
struct V_44 * V_45 = V_89 ;
struct V_12 V_96 ;
T_3 V_63 ;
V_63 = F_17 ( V_49 , V_46 -> V_97 ) ;
V_96 . V_59 = V_46 -> V_97 ;
V_96 . V_60 = V_46 -> V_98 ;
V_96 . V_14 = V_16 ;
V_96 . V_80 = 0 ;
V_96 . V_81 = 0 ;
return F_14 ( V_43 , V_45 , & V_96 , V_63 ) ;
}
STATIC int
F_23 (
struct V_51 * V_52 ,
struct V_99 * V_46 ,
void * V_89 )
{
struct V_48 * V_49 = V_52 -> V_90 ;
struct V_44 * V_45 = V_89 ;
struct V_12 V_96 ;
T_3 V_63 ;
V_63 = F_24 ( V_49 , V_52 -> V_92 . V_93 . V_56 ,
V_46 -> V_97 ) ;
V_96 . V_59 = V_46 -> V_97 ;
V_96 . V_60 = V_46 -> V_98 ;
V_96 . V_14 = V_16 ;
V_96 . V_80 = 0 ;
V_96 . V_81 = 0 ;
return F_14 ( V_52 -> V_94 , V_45 , & V_96 , V_63 ) ;
}
static void
F_25 (
struct V_12 * V_96 ,
struct V_3 * V_64 )
{
V_96 -> V_81 = 0 ;
if ( V_64 -> V_6 & V_85 )
V_96 -> V_81 |= V_84 ;
if ( V_64 -> V_6 & V_87 )
V_96 -> V_81 |= V_86 ;
if ( V_64 -> V_6 & V_83 )
V_96 -> V_81 |= V_82 ;
}
STATIC int
F_26 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
struct V_44 * V_45 )
{
struct V_48 * V_49 = V_43 -> V_50 ;
struct V_12 V_101 ;
int error ;
V_45 -> V_68 . V_59 = F_27 ( V_49 , V_100 [ 0 ] . V_7 ) ;
V_45 -> V_68 . V_80 = F_27 ( V_49 , V_100 [ 0 ] . V_9 ) ;
error = F_5 ( & V_45 -> V_68 , V_100 ) ;
if ( error )
return error ;
V_45 -> V_68 . V_60 = 0 ;
F_25 ( & V_45 -> V_68 , & V_100 [ 0 ] ) ;
error = F_5 ( & V_45 -> V_102 , V_100 + 1 ) ;
if ( error )
return error ;
V_45 -> V_102 . V_59 = - 1U ;
V_45 -> V_102 . V_14 = V_103 ;
V_45 -> V_102 . V_80 = V_103 ;
V_45 -> V_102 . V_60 = 0 ;
V_45 -> V_102 . V_81 = V_104 | V_105 ;
V_45 -> V_76 = V_15 ;
F_28 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , & V_45 -> V_68 ) ;
F_29 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , & V_45 -> V_102 ) ;
if ( V_100 [ 0 ] . V_7 > 0 )
return 0 ;
V_101 . V_59 = 0 ;
V_101 . V_60 = V_49 -> V_55 . V_106 ;
V_101 . V_14 = V_22 ;
V_101 . V_80 = 0 ;
V_101 . V_81 = 0 ;
return F_14 ( V_43 , V_45 , & V_101 , 0 ) ;
}
STATIC int
F_30 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
int (* F_31)( struct V_42 * ,
struct V_44 * ) ,
struct V_44 * V_45 )
{
struct V_48 * V_49 = V_43 -> V_50 ;
T_4 V_107 ;
T_4 V_108 ;
T_3 V_109 ;
int error = 0 ;
V_109 = F_17 ( V_49 , V_49 -> V_55 . V_110 ) ;
if ( V_100 [ 0 ] . V_7 >= V_109 )
return 0 ;
if ( V_100 [ 1 ] . V_7 >= V_109 )
V_100 [ 1 ] . V_7 = V_109 - 1 ;
V_107 = F_27 ( V_49 , V_100 [ 0 ] . V_7 ) ;
V_108 = F_32 ( V_49 , V_100 [ 1 ] . V_7 ) ;
V_45 -> V_68 . V_59 = V_107 ;
error = F_5 ( & V_45 -> V_68 , & V_100 [ 0 ] ) ;
if ( error )
return error ;
V_45 -> V_68 . V_80 = F_27 ( V_49 , V_100 [ 0 ] . V_9 ) ;
V_45 -> V_68 . V_60 = 0 ;
F_25 ( & V_45 -> V_68 , & V_100 [ 0 ] ) ;
V_45 -> V_102 . V_59 = V_108 ;
error = F_5 ( & V_45 -> V_102 , & V_100 [ 1 ] ) ;
if ( error )
return error ;
V_45 -> V_102 . V_80 = F_27 ( V_49 , V_100 [ 1 ] . V_9 ) ;
V_45 -> V_102 . V_60 = 0 ;
F_25 ( & V_45 -> V_102 , & V_100 [ 1 ] ) ;
F_28 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , & V_45 -> V_68 ) ;
F_29 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , & V_45 -> V_102 ) ;
return F_31 ( V_43 , V_45 ) ;
}
STATIC int
F_33 (
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_95 V_111 ;
struct V_95 V_112 ;
int error ;
F_34 ( V_43 -> V_50 -> V_113 , V_114 ) ;
V_111 . V_97 = V_45 -> V_68 . V_59 ;
V_112 . V_97 = V_45 -> V_102 . V_59 ;
error = F_35 ( V_43 , & V_111 , & V_112 ,
F_22 , V_45 ) ;
if ( error )
goto V_115;
V_45 -> V_74 = true ;
error = F_22 ( V_43 , & V_112 , V_45 ) ;
if ( error )
goto V_115;
V_115:
F_36 ( V_43 -> V_50 -> V_113 , V_114 ) ;
return error ;
}
STATIC int
F_37 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
struct V_44 * V_45 )
{
V_45 -> V_76 = V_17 ;
return F_30 ( V_43 , V_100 , F_33 ,
V_45 ) ;
}
STATIC int
F_38 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
struct V_44 * V_45 ,
int (* F_31)( struct V_42 * ,
struct V_44 * ,
struct V_51 * * ,
void * ) ,
void * V_89 )
{
struct V_48 * V_49 = V_43 -> V_50 ;
struct V_51 * V_116 = NULL ;
T_4 V_107 ;
T_4 V_108 ;
T_5 V_117 ;
T_5 V_118 ;
T_3 V_109 ;
int error = 0 ;
V_109 = F_17 ( V_49 , V_49 -> V_55 . V_119 ) ;
if ( V_100 [ 0 ] . V_7 >= V_109 )
return 0 ;
if ( V_100 [ 1 ] . V_7 >= V_109 )
V_100 [ 1 ] . V_7 = V_109 - 1 ;
V_107 = F_39 ( V_49 , V_100 [ 0 ] . V_7 ) ;
V_108 = F_39 ( V_49 , V_100 [ 1 ] . V_7 ) ;
V_45 -> V_68 . V_59 = F_40 ( V_49 , V_107 ) ;
V_45 -> V_68 . V_80 = F_27 ( V_49 , V_100 [ 0 ] . V_9 ) ;
error = F_5 ( & V_45 -> V_68 , & V_100 [ 0 ] ) ;
if ( error )
return error ;
V_45 -> V_68 . V_60 = 0 ;
F_25 ( & V_45 -> V_68 , & V_100 [ 0 ] ) ;
V_45 -> V_102 . V_59 = - 1U ;
V_45 -> V_102 . V_14 = V_103 ;
V_45 -> V_102 . V_80 = V_103 ;
V_45 -> V_102 . V_60 = 0 ;
V_45 -> V_102 . V_81 = V_104 | V_105 ;
V_117 = F_41 ( V_49 , V_107 ) ;
V_118 = F_41 ( V_49 , V_108 ) ;
for ( V_45 -> V_56 = V_117 ; V_45 -> V_56 <= V_118 ; V_45 -> V_56 ++ ) {
if ( V_45 -> V_56 == V_118 ) {
V_45 -> V_102 . V_59 = F_40 ( V_49 ,
V_108 ) ;
V_45 -> V_102 . V_80 = F_27 ( V_49 ,
V_100 [ 1 ] . V_9 ) ;
error = F_5 ( & V_45 -> V_102 , & V_100 [ 1 ] ) ;
if ( error )
goto V_115;
F_25 ( & V_45 -> V_102 , & V_100 [ 1 ] ) ;
}
if ( V_116 ) {
F_13 ( V_116 , V_62 ) ;
V_116 = NULL ;
F_42 ( V_43 , V_45 -> V_58 ) ;
V_45 -> V_58 = NULL ;
}
error = F_43 ( V_49 , V_43 , V_45 -> V_56 , 0 ,
& V_45 -> V_58 ) ;
if ( error )
goto V_115;
F_28 ( V_49 , V_45 -> V_41 , V_45 -> V_56 , & V_45 -> V_68 ) ;
F_29 ( V_49 , V_45 -> V_41 , V_45 -> V_56 ,
& V_45 -> V_102 ) ;
error = F_31 ( V_43 , V_45 , & V_116 , V_89 ) ;
if ( error )
goto V_115;
if ( V_45 -> V_56 == V_117 ) {
V_45 -> V_68 . V_59 = 0 ;
V_45 -> V_68 . V_14 = 0 ;
V_45 -> V_68 . V_80 = 0 ;
V_45 -> V_68 . V_81 = 0 ;
}
}
V_45 -> V_74 = true ;
error = F_31 ( V_43 , V_45 , & V_116 , V_89 ) ;
if ( error )
goto V_115;
V_115:
if ( V_116 )
F_13 ( V_116 , error < 0 ? V_61 :
V_62 ) ;
if ( V_45 -> V_58 ) {
F_42 ( V_43 , V_45 -> V_58 ) ;
V_45 -> V_58 = NULL ;
}
return error ;
}
STATIC int
F_44 (
struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_51 * * V_120 ,
void * V_89 )
{
if ( V_45 -> V_74 )
return F_19 ( * V_120 , & V_45 -> V_102 , V_45 ) ;
* V_120 = F_45 ( V_43 -> V_50 , V_43 , V_45 -> V_58 ,
V_45 -> V_56 ) ;
return F_46 ( * V_120 , & V_45 -> V_68 , & V_45 -> V_102 ,
F_19 , V_45 ) ;
}
STATIC int
F_47 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
struct V_44 * V_45 )
{
V_45 -> V_76 = V_15 ;
return F_38 ( V_43 , V_100 , V_45 ,
F_44 , NULL ) ;
}
STATIC int
F_48 (
struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_51 * * V_120 ,
void * V_89 )
{
struct V_99 * V_121 = V_89 ;
if ( V_45 -> V_74 )
return F_23 ( * V_120 , & V_121 [ 1 ] , V_45 ) ;
* V_120 = F_49 ( V_43 -> V_50 , V_43 , V_45 -> V_58 ,
V_45 -> V_56 , V_122 ) ;
V_121 -> V_97 = V_45 -> V_68 . V_59 ;
V_121 [ 1 ] . V_97 = V_45 -> V_102 . V_59 ;
return F_50 ( * V_120 , V_121 , & V_121 [ 1 ] ,
F_23 , V_45 ) ;
}
STATIC int
F_51 (
struct V_42 * V_43 ,
struct V_3 * V_100 ,
struct V_44 * V_45 )
{
struct V_99 V_123 [ 2 ] ;
V_45 -> V_76 = V_17 ;
return F_38 ( V_43 , V_100 , V_45 ,
F_48 , & V_123 [ 0 ] ) ;
}
STATIC bool
F_52 (
struct V_48 * V_49 ,
struct V_3 * V_124 )
{
if ( V_124 -> V_5 == 0 || V_124 -> V_5 == V_125 ||
V_124 -> V_5 == F_53 ( V_49 -> V_126 -> V_127 ) )
return true ;
if ( V_49 -> V_128 &&
V_124 -> V_5 == F_53 ( V_49 -> V_128 -> V_127 ) )
return true ;
if ( V_49 -> V_129 &&
V_124 -> V_5 == F_53 ( V_49 -> V_129 -> V_127 ) )
return true ;
return false ;
}
STATIC bool
F_54 (
struct V_3 * V_130 ,
struct V_3 * V_131 )
{
if ( V_130 -> V_5 > V_131 -> V_5 )
return false ;
if ( V_130 -> V_5 < V_131 -> V_5 )
return true ;
if ( V_130 -> V_7 > V_131 -> V_7 )
return false ;
if ( V_130 -> V_7 < V_131 -> V_7 )
return true ;
if ( V_130 -> V_8 > V_131 -> V_8 )
return false ;
if ( V_130 -> V_8 < V_131 -> V_8 )
return true ;
if ( V_130 -> V_9 > V_131 -> V_9 )
return false ;
if ( V_130 -> V_9 < V_131 -> V_9 )
return true ;
return false ;
}
int
F_55 (
struct V_48 * V_49 ,
struct V_132 * V_71 ,
T_6 V_77 ,
void * V_133 )
{
struct V_42 * V_43 = NULL ;
struct V_3 V_134 [ 2 ] ;
struct V_38 V_135 [ V_136 ] ;
struct V_44 V_45 = { NULL } ;
bool V_137 ;
int V_138 ;
int error = 0 ;
if ( V_71 -> V_139 & ~ V_140 )
return - V_34 ;
if ( ! F_52 ( V_49 , & V_71 -> V_141 [ 0 ] ) ||
! F_52 ( V_49 , & V_71 -> V_141 [ 1 ] ) )
return - V_34 ;
V_137 = F_56 ( V_142 ) &&
F_57 ( & V_49 -> V_55 ) ;
V_71 -> V_73 = 0 ;
memset ( V_135 , 0 , sizeof( V_135 ) ) ;
V_135 [ 0 ] . V_41 = F_53 ( V_49 -> V_126 -> V_127 ) ;
if ( V_137 )
V_135 [ 0 ] . V_143 = F_47 ;
else
V_135 [ 0 ] . V_143 = F_51 ;
if ( V_49 -> V_128 != V_49 -> V_126 ) {
V_135 [ 1 ] . V_41 = F_53 ( V_49 -> V_128 -> V_127 ) ;
V_135 [ 1 ] . V_143 = F_26 ;
}
if ( V_49 -> V_129 ) {
V_135 [ 2 ] . V_41 = F_53 ( V_49 -> V_129 -> V_127 ) ;
V_135 [ 2 ] . V_143 = F_37 ;
}
F_58 ( V_135 , V_136 , sizeof( struct V_38 ) ,
F_8 ) ;
V_134 [ 0 ] = V_71 -> V_141 [ 0 ] ;
if ( V_134 [ 0 ] . V_6 & ( V_13 | V_87 ) ) {
V_134 [ 0 ] . V_7 += V_134 [ 0 ] . V_10 ;
V_134 [ 0 ] . V_8 = 0 ;
if ( V_134 [ 0 ] . V_9 )
return - V_34 ;
} else
V_134 [ 0 ] . V_9 += V_134 [ 0 ] . V_10 ;
V_134 [ 0 ] . V_10 = 0 ;
memset ( & V_134 [ 1 ] , 0xFF , sizeof( struct V_3 ) ) ;
if ( ! F_54 ( V_134 , & V_71 -> V_141 [ 1 ] ) )
return - V_34 ;
V_45 . V_69 = V_71 -> V_141 [ 0 ] . V_7 +
V_71 -> V_141 [ 0 ] . V_10 ;
V_45 . V_77 = V_77 ;
V_45 . V_78 = V_133 ;
V_45 . V_71 = V_71 ;
for ( V_138 = 0 ; V_138 < V_136 ; V_138 ++ ) {
if ( ! V_135 [ V_138 ] . V_143 )
continue;
if ( V_71 -> V_141 [ 0 ] . V_5 > V_135 [ V_138 ] . V_41 )
continue;
if ( V_71 -> V_141 [ 1 ] . V_5 < V_135 [ V_138 ] . V_41 )
break;
if ( V_135 [ V_138 ] . V_41 == V_71 -> V_141 [ 1 ] . V_5 )
V_134 [ 1 ] = V_71 -> V_141 [ 1 ] ;
if ( V_135 [ V_138 ] . V_41 > V_71 -> V_141 [ 0 ] . V_5 )
memset ( & V_134 [ 0 ] , 0 , sizeof( struct V_3 ) ) ;
error = F_59 ( V_49 , & V_43 ) ;
if ( error )
break;
V_45 . V_41 = V_135 [ V_138 ] . V_41 ;
V_45 . V_74 = false ;
V_45 . V_56 = V_57 ;
error = V_135 [ V_138 ] . V_143 ( V_43 , V_134 , & V_45 ) ;
if ( error )
break;
F_60 ( V_43 ) ;
V_43 = NULL ;
V_45 . V_69 = 0 ;
}
if ( V_43 )
F_60 ( V_43 ) ;
V_71 -> V_144 = V_145 ;
return error ;
}
