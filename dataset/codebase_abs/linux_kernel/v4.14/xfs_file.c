int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
bool * V_5 )
{
return F_2 ( F_3 ( V_2 ) , V_3 , V_4 , V_5 , & V_6 ) ;
}
int
F_4 (
struct V_1 * V_2 ,
enum V_7 V_8 )
{
struct V_9 * V_10 ;
int error ;
error = F_5 ( V_2 -> V_11 , & F_6 ( V_2 -> V_11 ) -> V_12 ,
0 , 0 , 0 , & V_10 ) ;
if ( error )
return error ;
F_7 ( V_2 , V_13 ) ;
F_8 ( V_10 , V_2 , V_13 ) ;
if ( ! ( V_8 & V_14 ) ) {
F_3 ( V_2 ) -> V_15 &= ~ V_16 ;
if ( F_3 ( V_2 ) -> V_15 & V_17 )
F_3 ( V_2 ) -> V_15 &= ~ V_18 ;
F_9 ( V_10 , V_2 , V_19 | V_20 ) ;
}
if ( V_8 & V_21 )
V_2 -> V_22 . V_23 |= V_24 ;
if ( V_8 & V_25 )
V_2 -> V_22 . V_23 &= ~ V_24 ;
F_10 ( V_10 , V_2 , V_26 ) ;
if ( V_8 & V_27 )
F_11 ( V_10 ) ;
return F_12 ( V_10 ) ;
}
STATIC int
F_13 (
struct V_28 * V_28 ,
T_2 V_29 ,
T_2 V_30 ,
int V_31 )
{
struct V_1 * V_2 = F_14 ( V_28 -> V_32 -> V_33 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_3 V_36 = 0 ;
F_15 ( V_2 ) ;
F_7 ( V_2 , V_37 ) ;
if ( F_16 ( V_2 ) )
V_36 = V_2 -> V_38 -> V_39 ;
F_17 ( V_2 , V_37 ) ;
if ( ! V_36 )
return 0 ;
return F_18 ( V_35 , V_36 , V_40 , NULL ) ;
}
STATIC int
F_19 (
struct V_28 * V_28 ,
T_2 V_29 ,
T_2 V_30 ,
int V_31 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
int error = 0 ;
int V_42 = 0 ;
T_3 V_36 = 0 ;
F_20 ( V_2 ) ;
error = F_21 ( V_28 , V_29 , V_30 ) ;
if ( error )
return error ;
if ( F_22 ( V_35 ) )
return - V_43 ;
F_23 ( V_2 , V_44 ) ;
if ( F_24 ( V_2 ) )
F_25 ( V_35 -> V_45 ) ;
else if ( V_35 -> V_46 != V_35 -> V_47 )
F_25 ( V_35 -> V_47 ) ;
F_7 ( V_2 , V_37 ) ;
if ( F_16 ( V_2 ) ) {
if ( ! V_31 ||
( V_2 -> V_38 -> V_48 & ~ V_49 ) )
V_36 = V_2 -> V_38 -> V_39 ;
}
if ( V_36 ) {
error = F_18 ( V_35 , V_36 , V_40 , & V_42 ) ;
V_2 -> V_38 -> V_48 = 0 ;
}
F_17 ( V_2 , V_37 ) ;
if ( ! V_42 && ! F_24 ( V_2 ) &&
V_35 -> V_46 == V_35 -> V_47 )
F_25 ( V_35 -> V_47 ) ;
return error ;
}
STATIC T_4
F_26 (
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_14 ( F_27 ( V_51 -> V_54 ) ) ;
T_5 V_4 = F_28 ( V_53 ) ;
T_4 V_55 ;
F_29 ( V_2 , V_4 , V_51 -> V_56 ) ;
if ( ! V_4 )
return 0 ;
F_30 ( V_51 -> V_54 ) ;
F_7 ( V_2 , V_57 ) ;
V_55 = F_31 ( V_51 , V_53 , & V_6 , NULL ) ;
F_17 ( V_2 , V_57 ) ;
return V_55 ;
}
static T_6 T_4
F_32 (
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_14 ( V_51 -> V_54 -> V_32 -> V_33 ) ;
T_5 V_4 = F_28 ( V_53 ) ;
T_4 V_55 = 0 ;
F_33 ( V_2 , V_4 , V_51 -> V_56 ) ;
if ( ! V_4 )
return 0 ;
if ( V_51 -> V_58 & V_59 ) {
if ( ! F_34 ( V_2 , V_57 ) )
return - V_60 ;
} else {
F_7 ( V_2 , V_57 ) ;
}
V_55 = F_35 ( V_51 , V_53 , & V_6 ) ;
F_17 ( V_2 , V_57 ) ;
F_30 ( V_51 -> V_54 ) ;
return V_55 ;
}
STATIC T_4
F_36 (
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_14 ( F_27 ( V_51 -> V_54 ) ) ;
T_4 V_55 ;
F_37 ( V_2 , F_28 ( V_53 ) , V_51 -> V_56 ) ;
if ( V_51 -> V_58 & V_59 ) {
if ( ! F_34 ( V_2 , V_57 ) )
return - V_60 ;
} else {
F_7 ( V_2 , V_57 ) ;
}
V_55 = F_38 ( V_51 , V_53 ) ;
F_17 ( V_2 , V_57 ) ;
return V_55 ;
}
STATIC T_4
F_39 (
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_41 * V_41 = F_27 ( V_51 -> V_54 ) ;
struct V_34 * V_35 = F_14 ( V_41 ) -> V_11 ;
T_4 V_55 = 0 ;
F_40 ( V_35 , V_61 ) ;
if ( F_22 ( V_35 ) )
return - V_43 ;
if ( F_41 ( V_41 ) )
V_55 = F_32 ( V_51 , V_53 ) ;
else if ( V_51 -> V_58 & V_62 )
V_55 = F_26 ( V_51 , V_53 ) ;
else
V_55 = F_36 ( V_51 , V_53 ) ;
if ( V_55 > 0 )
F_42 ( V_35 , V_63 , V_55 ) ;
return V_55 ;
}
int
F_43 (
struct V_1 * V_2 ,
T_1 V_64 ,
T_7 V_65 ,
bool * V_66 )
{
ASSERT ( F_44 ( V_2 , V_67 ) ) ;
ASSERT ( V_64 > V_65 ) ;
F_45 ( V_2 , V_65 , V_64 - V_65 ) ;
return F_1 ( V_2 , V_65 , V_64 - V_65 , V_66 ) ;
}
STATIC T_4
F_46 (
struct V_50 * V_51 ,
struct V_52 * V_68 ,
int * V_69 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 error = 0 ;
T_5 V_4 = F_28 ( V_68 ) ;
bool V_70 = false ;
V_71:
error = F_47 ( V_51 , V_68 ) ;
if ( error <= 0 )
return error ;
error = F_48 ( V_41 , V_69 ) ;
if ( error )
return error ;
if ( * V_69 == V_57 && ! F_49 ( V_41 ) ) {
F_17 ( V_2 , * V_69 ) ;
* V_69 = V_67 ;
F_7 ( V_2 , * V_69 ) ;
goto V_71;
}
F_50 ( & V_2 -> V_72 ) ;
if ( V_51 -> V_56 > F_51 ( V_41 ) ) {
F_52 ( & V_2 -> V_72 ) ;
if ( ! V_70 ) {
if ( * V_69 == V_57 ) {
F_17 ( V_2 , * V_69 ) ;
* V_69 = V_67 ;
F_7 ( V_2 , * V_69 ) ;
F_53 ( V_68 , V_4 ) ;
}
F_54 ( V_41 ) ;
V_70 = true ;
goto V_71;
}
error = F_43 ( V_2 , V_51 -> V_56 , F_51 ( V_41 ) , NULL ) ;
if ( error )
return error ;
} else
F_52 ( & V_2 -> V_72 ) ;
if ( F_55 ( ! ( V_28 -> V_73 & V_74 ) ) ) {
error = F_56 ( V_28 ) ;
if ( error )
return error ;
}
if ( ! F_49 ( V_41 ) )
return F_57 ( V_28 ) ;
return 0 ;
}
static int
F_58 (
struct V_50 * V_51 ,
T_4 V_75 ,
unsigned V_8 )
{
struct V_41 * V_41 = F_27 ( V_51 -> V_54 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_2 V_64 = V_51 -> V_56 ;
int error = 0 ;
F_59 ( V_2 , V_64 , V_75 ) ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_43 ;
if ( V_75 <= 0 )
return V_75 ;
if ( V_8 & V_76 ) {
error = F_60 ( V_2 , V_64 , V_75 ) ;
if ( error )
return error ;
}
if ( V_8 & V_77 )
return F_61 ( V_2 , V_64 , V_75 , true ) ;
F_50 ( & V_2 -> V_72 ) ;
if ( V_64 + V_75 > F_51 ( V_41 ) ) {
F_62 ( V_41 , V_64 + V_75 ) ;
F_52 ( & V_2 -> V_72 ) ;
error = F_63 ( V_2 , V_64 , V_75 ) ;
} else {
F_52 ( & V_2 -> V_72 ) ;
}
return error ;
}
STATIC T_4
F_64 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_78 * V_79 = V_28 -> V_32 ;
struct V_41 * V_41 = V_79 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_4 V_55 = 0 ;
int V_80 = 0 ;
int V_69 ;
T_5 V_4 = F_28 ( V_68 ) ;
struct V_81 * V_82 = F_24 ( V_2 ) ?
V_35 -> V_45 : V_35 -> V_47 ;
if ( ( V_51 -> V_56 | V_4 ) & V_82 -> V_83 )
return - V_84 ;
if ( ( V_51 -> V_56 & V_35 -> V_85 ) ||
( ( V_51 -> V_56 + V_4 ) & V_35 -> V_85 ) ) {
V_80 = 1 ;
if ( F_65 ( V_2 ) ) {
F_66 ( V_2 , V_51 -> V_56 , V_4 ) ;
return - V_86 ;
}
V_69 = V_67 ;
} else {
V_69 = V_57 ;
}
if ( V_51 -> V_58 & V_59 ) {
if ( ! F_34 ( V_2 , V_69 ) )
return - V_60 ;
} else {
F_7 ( V_2 , V_69 ) ;
}
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_87;
V_4 = F_28 ( V_68 ) ;
if ( V_80 ) {
if ( V_51 -> V_58 & V_59 ) {
if ( F_67 ( & V_41 -> V_88 ) )
return - V_60 ;
} else {
F_54 ( V_41 ) ;
}
} else if ( V_69 == V_67 ) {
F_68 ( V_2 , V_67 ) ;
V_69 = V_57 ;
}
F_69 ( V_2 , V_4 , V_51 -> V_56 ) ;
V_55 = F_31 ( V_51 , V_68 , & V_6 , F_58 ) ;
V_87:
F_17 ( V_2 , V_69 ) ;
ASSERT ( V_55 < 0 || V_55 == V_4 ) ;
return V_55 ;
}
static T_6 T_4
F_70 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_41 * V_41 = V_51 -> V_54 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_69 = V_67 ;
T_4 V_55 , error = 0 ;
T_5 V_4 ;
T_2 V_3 ;
if ( V_51 -> V_58 & V_59 ) {
if ( ! F_34 ( V_2 , V_69 ) )
return - V_60 ;
} else {
F_7 ( V_2 , V_69 ) ;
}
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_87;
V_3 = V_51 -> V_56 ;
V_4 = F_28 ( V_68 ) ;
F_71 ( V_2 , V_4 , V_3 ) ;
V_55 = F_35 ( V_51 , V_68 , & V_6 ) ;
if ( V_55 > 0 && V_51 -> V_56 > F_51 ( V_41 ) ) {
F_62 ( V_41 , V_51 -> V_56 ) ;
error = F_63 ( V_2 , V_3 , V_55 ) ;
}
V_87:
F_17 ( V_2 , V_69 ) ;
return error ? error : V_55 ;
}
STATIC T_4
F_72 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_78 * V_79 = V_28 -> V_32 ;
struct V_41 * V_41 = V_79 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_55 ;
int V_89 = 0 ;
int V_69 ;
if ( V_51 -> V_58 & V_59 )
return - V_90 ;
V_91:
V_69 = V_67 ;
F_7 ( V_2 , V_69 ) ;
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_87;
V_92 -> V_93 = F_73 ( V_41 ) ;
F_74 ( V_2 , F_28 ( V_68 ) , V_51 -> V_56 ) ;
V_55 = F_75 ( V_51 , V_68 , & V_6 ) ;
if ( F_55 ( V_55 >= 0 ) )
V_51 -> V_56 += V_55 ;
if ( V_55 == - V_94 && ! V_89 ) {
F_17 ( V_2 , V_69 ) ;
V_89 = F_76 ( V_2 ) ;
if ( V_89 )
goto V_91;
V_89 = F_77 ( V_2 ) ;
if ( V_89 )
goto V_91;
V_69 = 0 ;
} else if ( V_55 == - V_95 && ! V_89 ) {
struct V_96 V_97 = { 0 } ;
V_89 = 1 ;
F_78 ( V_2 -> V_11 ) ;
F_17 ( V_2 , V_69 ) ;
V_97 . V_98 = V_99 ;
F_79 ( V_2 -> V_11 , & V_97 ) ;
F_80 ( V_2 -> V_11 , & V_97 ) ;
goto V_91;
}
V_92 -> V_93 = NULL ;
V_87:
if ( V_69 )
F_17 ( V_2 , V_69 ) ;
return V_55 ;
}
STATIC T_4
F_81 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_78 * V_79 = V_28 -> V_32 ;
struct V_41 * V_41 = V_79 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_55 ;
T_5 V_100 = F_28 ( V_68 ) ;
F_40 ( V_2 -> V_11 , V_101 ) ;
if ( V_100 == 0 )
return 0 ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_43 ;
if ( F_41 ( V_41 ) )
V_55 = F_70 ( V_51 , V_68 ) ;
else if ( V_51 -> V_58 & V_62 ) {
V_55 = F_64 ( V_51 , V_68 ) ;
if ( V_55 == - V_86 )
goto V_102;
} else {
V_102:
V_55 = F_72 ( V_51 , V_68 ) ;
}
if ( V_55 > 0 ) {
F_42 ( V_2 -> V_11 , V_103 , V_55 ) ;
V_55 = F_82 ( V_51 , V_55 ) ;
}
return V_55 ;
}
STATIC long
F_83 (
struct V_28 * V_28 ,
int V_104 ,
T_2 V_64 ,
T_2 V_105 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
long error ;
enum V_7 V_8 = 0 ;
T_8 V_69 = V_67 ;
T_2 V_106 = 0 ;
bool V_107 = false ;
if ( ! F_84 ( V_41 -> V_15 ) )
return - V_84 ;
if ( V_104 & ~ V_108 )
return - V_90 ;
F_7 ( V_2 , V_69 ) ;
error = F_48 ( V_41 , & V_69 ) ;
if ( error )
goto V_109;
F_7 ( V_2 , V_110 ) ;
V_69 |= V_110 ;
if ( V_104 & V_111 ) {
error = F_85 ( V_2 , V_64 , V_105 ) ;
if ( error )
goto V_109;
} else if ( V_104 & V_112 ) {
unsigned int V_113 = F_86 ( V_41 ) - 1 ;
if ( V_64 & V_113 || V_105 & V_113 ) {
error = - V_84 ;
goto V_109;
}
if ( V_64 + V_105 >= F_51 ( V_41 ) ) {
error = - V_84 ;
goto V_109;
}
V_106 = F_51 ( V_41 ) - V_105 ;
error = F_87 ( V_2 , V_64 , V_105 ) ;
if ( error )
goto V_109;
} else if ( V_104 & V_114 ) {
unsigned int V_113 = F_86 ( V_41 ) - 1 ;
V_106 = F_51 ( V_41 ) + V_105 ;
if ( V_64 & V_113 || V_105 & V_113 ) {
error = - V_84 ;
goto V_109;
}
if ( V_106 > V_41 -> V_115 -> V_116 ) {
error = - V_117 ;
goto V_109;
}
if ( V_64 >= F_51 ( V_41 ) ) {
error = - V_84 ;
goto V_109;
}
V_107 = true ;
} else {
V_8 |= V_21 ;
if ( ! ( V_104 & V_118 ) &&
V_64 + V_105 > F_51 ( V_41 ) ) {
V_106 = V_64 + V_105 ;
error = F_88 ( V_41 , V_106 ) ;
if ( error )
goto V_109;
}
if ( V_104 & V_119 )
error = F_89 ( V_2 , V_64 , V_105 ) ;
else {
if ( V_104 & V_120 ) {
error = F_90 ( V_2 , V_64 , V_105 ) ;
if ( error )
goto V_109;
}
error = F_91 ( V_2 , V_64 , V_105 ,
V_121 ) ;
}
if ( error )
goto V_109;
}
if ( V_28 -> V_122 & V_123 )
V_8 |= V_27 ;
error = F_4 ( V_2 , V_8 ) ;
if ( error )
goto V_109;
if ( V_106 ) {
struct V_124 V_124 ;
V_124 . V_125 = V_126 ;
V_124 . V_127 = V_106 ;
error = F_92 ( F_93 ( V_28 ) , & V_124 ) ;
if ( error )
goto V_109;
}
if ( V_107 )
error = F_94 ( V_2 , V_64 , V_105 ) ;
V_109:
F_17 ( V_2 , V_69 ) ;
return error ;
}
STATIC int
F_95 (
struct V_28 * V_128 ,
T_2 V_129 ,
struct V_28 * V_130 ,
T_2 V_131 ,
T_9 V_105 )
{
return F_96 ( V_128 , V_129 , V_130 , V_131 ,
V_105 , false ) ;
}
STATIC T_4
F_97 (
struct V_28 * V_132 ,
T_9 V_133 ,
T_9 V_105 ,
struct V_28 * V_134 ,
T_9 V_135 )
{
int error ;
error = F_96 ( V_132 , V_133 , V_134 , V_135 ,
V_105 , true ) ;
if ( error )
return error ;
return V_105 ;
}
STATIC int
F_98 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
if ( ! ( V_28 -> V_122 & V_136 ) && F_51 ( V_41 ) > V_137 )
return - V_117 ;
if ( F_22 ( F_99 ( V_41 -> V_115 ) ) )
return - V_43 ;
V_28 -> V_73 |= V_138 ;
return 0 ;
}
STATIC int
F_100 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_104 ;
int error ;
error = F_98 ( V_41 , V_28 ) ;
if ( error )
return error ;
V_104 = F_101 ( V_2 ) ;
if ( V_2 -> V_22 . V_139 > 0 )
error = F_102 ( V_2 , 0 , - 1 ) ;
F_17 ( V_2 , V_104 ) ;
return error ;
}
STATIC int
F_103 (
struct V_41 * V_41 ,
struct V_28 * V_140 )
{
return F_104 ( F_14 ( V_41 ) ) ;
}
STATIC int
F_105 (
struct V_28 * V_28 ,
struct V_141 * V_142 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
T_10 * V_2 = F_14 ( V_41 ) ;
T_5 V_143 ;
V_143 = ( T_5 ) F_106 ( T_2 , 32768 , V_2 -> V_22 . V_144 ) ;
return F_107 ( NULL , V_2 , V_142 , V_143 ) ;
}
STATIC T_2
F_108 (
struct V_28 * V_28 ,
T_2 V_64 ,
int V_145 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
if ( F_22 ( F_14 ( V_41 ) -> V_11 ) )
return - V_43 ;
switch ( V_145 ) {
default:
return F_109 ( V_28 , V_64 , V_145 ) ;
case V_146 :
V_64 = F_110 ( V_41 , V_64 , & V_6 ) ;
break;
case V_147 :
V_64 = F_111 ( V_41 , V_64 , & V_6 ) ;
break;
}
if ( V_64 < 0 )
return V_64 ;
return F_112 ( V_28 , V_64 , V_41 -> V_115 -> V_116 ) ;
}
static int
F_113 (
struct V_148 * V_149 ,
enum V_150 V_151 ,
bool V_152 )
{
struct V_41 * V_41 = F_27 ( V_149 -> V_153 -> V_154 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_55 ;
F_114 ( V_2 , V_151 , V_152 ) ;
if ( V_152 ) {
F_115 ( V_41 -> V_115 ) ;
F_56 ( V_149 -> V_153 -> V_154 ) ;
}
F_7 ( F_14 ( V_41 ) , V_155 ) ;
if ( F_41 ( V_41 ) ) {
V_55 = F_116 ( V_149 , V_151 , & V_6 ) ;
} else {
if ( V_152 )
V_55 = F_117 ( V_149 , & V_6 ) ;
else
V_55 = F_118 ( V_149 ) ;
}
F_17 ( F_14 ( V_41 ) , V_155 ) ;
if ( V_152 )
F_119 ( V_41 -> V_115 ) ;
return V_55 ;
}
static int
F_120 (
struct V_148 * V_149 )
{
return F_113 ( V_149 , V_156 ,
F_41 ( F_27 ( V_149 -> V_153 -> V_154 ) ) &&
( V_149 -> V_8 & V_157 ) ) ;
}
static int
F_121 (
struct V_148 * V_149 ,
enum V_150 V_151 )
{
if ( ! F_41 ( F_27 ( V_149 -> V_153 -> V_154 ) ) )
return V_158 ;
return F_113 ( V_149 , V_151 ,
( V_149 -> V_8 & V_157 ) ) ;
}
static int
F_122 (
struct V_148 * V_149 )
{
return F_113 ( V_149 , V_156 , true ) ;
}
static int
F_123 (
struct V_148 * V_149 )
{
struct V_41 * V_41 = F_27 ( V_149 -> V_153 -> V_154 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_55 = V_159 ;
T_2 V_75 ;
F_124 ( V_2 ) ;
F_115 ( V_41 -> V_115 ) ;
F_56 ( V_149 -> V_153 -> V_154 ) ;
F_7 ( V_2 , V_155 ) ;
V_75 = ( F_51 ( V_41 ) + V_160 - 1 ) >> V_161 ;
if ( V_149 -> V_162 >= V_75 )
V_55 = V_163 ;
else if ( F_41 ( V_41 ) )
V_55 = F_116 ( V_149 , V_156 , & V_6 ) ;
F_17 ( V_2 , V_155 ) ;
F_119 ( V_41 -> V_115 ) ;
return V_55 ;
}
STATIC int
F_125 (
struct V_28 * V_140 ,
struct V_164 * V_153 )
{
F_30 ( V_140 ) ;
V_153 -> V_165 = & V_166 ;
if ( F_41 ( F_27 ( V_140 ) ) )
V_153 -> V_167 |= V_168 | V_169 ;
return 0 ;
}
