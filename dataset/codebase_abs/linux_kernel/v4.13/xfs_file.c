int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
bool * V_5 )
{
return F_2 ( F_3 ( V_2 ) , V_3 , V_4 , NULL , & V_6 ) ;
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
if ( ! F_34 ( V_2 , V_57 ) ) {
if ( V_51 -> V_58 & V_59 )
return - V_60 ;
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
F_7 ( V_2 , V_57 ) ;
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
bool V_73 = false ;
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
error = F_43 ( V_2 , V_51 -> V_56 , F_51 ( V_41 ) , & V_73 ) ;
if ( error )
return error ;
} else
F_52 ( & V_2 -> V_72 ) ;
if ( F_55 ( ! ( V_28 -> V_74 & V_75 ) ) ) {
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
T_4 V_76 ,
unsigned V_8 )
{
struct V_41 * V_41 = F_27 ( V_51 -> V_54 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_2 V_64 = V_51 -> V_56 ;
bool V_77 = false ;
int error = 0 ;
F_59 ( V_2 , V_64 , V_76 ) ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_43 ;
if ( V_76 <= 0 )
return V_76 ;
F_50 ( & V_2 -> V_72 ) ;
if ( V_64 + V_76 > F_51 ( V_41 ) ) {
F_60 ( V_41 , V_64 + V_76 ) ;
V_77 = true ;
}
F_52 ( & V_2 -> V_72 ) ;
if ( V_8 & V_78 ) {
error = F_61 ( V_2 , V_64 , V_76 ) ;
if ( error )
return error ;
}
if ( V_8 & V_79 )
error = F_62 ( V_2 , V_64 , V_76 ) ;
else if ( V_77 )
error = F_63 ( V_2 , V_64 , V_76 ) ;
return error ;
}
STATIC T_4
F_64 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_80 * V_81 = V_28 -> V_32 ;
struct V_41 * V_41 = V_81 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_4 V_55 = 0 ;
int V_82 = 0 ;
int V_69 ;
T_5 V_4 = F_28 ( V_68 ) ;
struct V_83 * V_84 = F_24 ( V_2 ) ?
V_35 -> V_45 : V_35 -> V_47 ;
if ( ( V_51 -> V_56 | V_4 ) & V_84 -> V_85 )
return - V_86 ;
if ( ( V_51 -> V_56 & V_35 -> V_87 ) ||
( ( V_51 -> V_56 + V_4 ) & V_35 -> V_87 ) ) {
V_82 = 1 ;
if ( F_65 ( V_2 ) ) {
F_66 ( V_2 , V_51 -> V_56 , V_4 ) ;
return - V_88 ;
}
V_69 = V_67 ;
} else {
V_69 = V_57 ;
}
if ( ! F_34 ( V_2 , V_69 ) ) {
if ( V_51 -> V_58 & V_59 )
return - V_60 ;
F_7 ( V_2 , V_69 ) ;
}
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_89;
V_4 = F_28 ( V_68 ) ;
if ( V_82 ) {
if ( V_51 -> V_58 & V_59 ) {
if ( F_67 ( & V_41 -> V_90 ) )
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
V_89:
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
if ( ! F_34 ( V_2 , V_69 ) ) {
if ( V_51 -> V_58 & V_59 )
return - V_60 ;
F_7 ( V_2 , V_69 ) ;
}
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_89;
V_3 = V_51 -> V_56 ;
V_4 = F_28 ( V_68 ) ;
F_71 ( V_2 , V_4 , V_3 ) ;
V_55 = F_35 ( V_51 , V_68 , & V_6 ) ;
if ( V_55 > 0 && V_51 -> V_56 > F_51 ( V_41 ) ) {
F_60 ( V_41 , V_51 -> V_56 ) ;
error = F_63 ( V_2 , V_3 , V_55 ) ;
}
V_89:
F_17 ( V_2 , V_69 ) ;
return error ? error : V_55 ;
}
STATIC T_4
F_72 (
struct V_50 * V_51 ,
struct V_52 * V_68 )
{
struct V_28 * V_28 = V_51 -> V_54 ;
struct V_80 * V_81 = V_28 -> V_32 ;
struct V_41 * V_41 = V_81 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_55 ;
int V_91 = 0 ;
int V_69 ;
V_92:
V_69 = V_67 ;
F_7 ( V_2 , V_69 ) ;
V_55 = F_46 ( V_51 , V_68 , & V_69 ) ;
if ( V_55 )
goto V_89;
V_93 -> V_94 = F_73 ( V_41 ) ;
F_74 ( V_2 , F_28 ( V_68 ) , V_51 -> V_56 ) ;
V_55 = F_75 ( V_51 , V_68 , & V_6 ) ;
if ( F_55 ( V_55 >= 0 ) )
V_51 -> V_56 += V_55 ;
if ( V_55 == - V_95 && ! V_91 ) {
F_17 ( V_2 , V_69 ) ;
V_91 = F_76 ( V_2 ) ;
if ( V_91 )
goto V_92;
V_91 = F_77 ( V_2 ) ;
if ( V_91 )
goto V_92;
V_69 = 0 ;
} else if ( V_55 == - V_96 && ! V_91 ) {
struct V_97 V_98 = { 0 } ;
V_91 = 1 ;
F_78 ( V_2 -> V_11 ) ;
F_17 ( V_2 , V_69 ) ;
V_98 . V_99 = V_100 ;
F_79 ( V_2 -> V_11 , & V_98 ) ;
F_80 ( V_2 -> V_11 , & V_98 ) ;
goto V_92;
}
V_93 -> V_94 = NULL ;
V_89:
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
struct V_80 * V_81 = V_28 -> V_32 ;
struct V_41 * V_41 = V_81 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_55 ;
T_5 V_101 = F_28 ( V_68 ) ;
F_40 ( V_2 -> V_11 , V_102 ) ;
if ( V_101 == 0 )
return 0 ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_43 ;
if ( F_41 ( V_41 ) )
V_55 = F_70 ( V_51 , V_68 ) ;
else if ( V_51 -> V_58 & V_62 ) {
V_55 = F_64 ( V_51 , V_68 ) ;
if ( V_55 == - V_88 )
goto V_103;
} else {
V_103:
V_55 = F_72 ( V_51 , V_68 ) ;
}
if ( V_55 > 0 ) {
F_42 ( V_2 -> V_11 , V_104 , V_55 ) ;
V_55 = F_82 ( V_51 , V_55 ) ;
}
return V_55 ;
}
STATIC long
F_83 (
struct V_28 * V_28 ,
int V_105 ,
T_2 V_64 ,
T_2 V_106 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
long error ;
enum V_7 V_8 = 0 ;
T_8 V_69 = V_67 ;
T_2 V_107 = 0 ;
bool V_108 = 0 ;
if ( ! F_84 ( V_41 -> V_15 ) )
return - V_86 ;
if ( V_105 & ~ V_109 )
return - V_110 ;
F_7 ( V_2 , V_69 ) ;
error = F_48 ( V_41 , & V_69 ) ;
if ( error )
goto V_111;
F_7 ( V_2 , V_112 ) ;
V_69 |= V_112 ;
if ( V_105 & V_113 ) {
error = F_85 ( V_2 , V_64 , V_106 ) ;
if ( error )
goto V_111;
} else if ( V_105 & V_114 ) {
unsigned int V_115 = F_86 ( V_41 ) - 1 ;
if ( V_64 & V_115 || V_106 & V_115 ) {
error = - V_86 ;
goto V_111;
}
if ( V_64 + V_106 >= F_51 ( V_41 ) ) {
error = - V_86 ;
goto V_111;
}
V_107 = F_51 ( V_41 ) - V_106 ;
error = F_87 ( V_2 , V_64 , V_106 ) ;
if ( error )
goto V_111;
} else if ( V_105 & V_116 ) {
unsigned int V_115 = F_86 ( V_41 ) - 1 ;
V_107 = F_51 ( V_41 ) + V_106 ;
if ( V_64 & V_115 || V_106 & V_115 ) {
error = - V_86 ;
goto V_111;
}
if ( V_107 > V_41 -> V_117 -> V_118 ) {
error = - V_119 ;
goto V_111;
}
if ( V_64 >= F_51 ( V_41 ) ) {
error = - V_86 ;
goto V_111;
}
V_108 = 1 ;
} else {
V_8 |= V_21 ;
if ( ! ( V_105 & V_120 ) &&
V_64 + V_106 > F_51 ( V_41 ) ) {
V_107 = V_64 + V_106 ;
error = F_88 ( V_41 , V_107 ) ;
if ( error )
goto V_111;
}
if ( V_105 & V_121 )
error = F_89 ( V_2 , V_64 , V_106 ) ;
else {
if ( V_105 & V_122 ) {
error = F_90 ( V_2 , V_64 , V_106 ) ;
if ( error )
goto V_111;
}
error = F_91 ( V_2 , V_64 , V_106 ,
V_123 ) ;
}
if ( error )
goto V_111;
}
if ( V_28 -> V_124 & V_125 )
V_8 |= V_27 ;
error = F_4 ( V_2 , V_8 ) ;
if ( error )
goto V_111;
if ( V_107 ) {
struct V_126 V_126 ;
V_126 . V_127 = V_128 ;
V_126 . V_129 = V_107 ;
error = F_92 ( F_93 ( V_28 ) , & V_126 ) ;
if ( error )
goto V_111;
}
if ( V_108 )
error = F_94 ( V_2 , V_64 , V_106 ) ;
V_111:
F_17 ( V_2 , V_69 ) ;
return error ;
}
STATIC int
F_95 (
struct V_28 * V_130 ,
T_2 V_131 ,
struct V_28 * V_132 ,
T_2 V_133 ,
T_9 V_106 )
{
return F_96 ( V_130 , V_131 , V_132 , V_133 ,
V_106 , false ) ;
}
STATIC T_4
F_97 (
struct V_28 * V_134 ,
T_9 V_135 ,
T_9 V_106 ,
struct V_28 * V_136 ,
T_9 V_137 )
{
int error ;
error = F_96 ( V_134 , V_135 , V_136 , V_137 ,
V_106 , true ) ;
if ( error )
return error ;
return V_106 ;
}
STATIC int
F_98 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
if ( ! ( V_28 -> V_124 & V_138 ) && F_51 ( V_41 ) > V_139 )
return - V_119 ;
if ( F_22 ( F_99 ( V_41 -> V_117 ) ) )
return - V_43 ;
V_28 -> V_74 |= V_140 ;
return 0 ;
}
STATIC int
F_100 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_105 ;
int error ;
error = F_98 ( V_41 , V_28 ) ;
if ( error )
return error ;
V_105 = F_101 ( V_2 ) ;
if ( V_2 -> V_22 . V_141 > 0 )
error = F_102 ( V_2 , 0 , - 1 ) ;
F_17 ( V_2 , V_105 ) ;
return error ;
}
STATIC int
F_103 (
struct V_41 * V_41 ,
struct V_28 * V_142 )
{
return F_104 ( F_14 ( V_41 ) ) ;
}
STATIC int
F_105 (
struct V_28 * V_28 ,
struct V_143 * V_144 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
T_10 * V_2 = F_14 ( V_41 ) ;
T_5 V_145 ;
V_145 = ( T_5 ) F_106 ( T_2 , 32768 , V_2 -> V_22 . V_146 ) ;
return F_107 ( NULL , V_2 , V_144 , V_145 ) ;
}
STATIC T_2
F_108 (
struct V_28 * V_28 ,
T_2 V_64 ,
int V_147 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
if ( F_22 ( F_14 ( V_41 ) -> V_11 ) )
return - V_43 ;
switch ( V_147 ) {
default:
return F_109 ( V_28 , V_64 , V_147 ) ;
case V_148 :
V_64 = F_110 ( V_41 , V_64 , & V_6 ) ;
break;
case V_149 :
V_64 = F_111 ( V_41 , V_64 , & V_6 ) ;
break;
}
if ( V_64 < 0 )
return V_64 ;
return F_112 ( V_28 , V_64 , V_41 -> V_117 -> V_118 ) ;
}
STATIC int
F_113 (
struct V_150 * V_151 )
{
struct V_41 * V_41 = F_27 ( V_151 -> V_152 -> V_153 ) ;
int V_55 ;
F_114 ( F_14 ( V_41 ) ) ;
F_115 ( V_41 -> V_117 ) ;
F_56 ( V_151 -> V_152 -> V_153 ) ;
F_7 ( F_14 ( V_41 ) , V_154 ) ;
if ( F_41 ( V_41 ) ) {
V_55 = F_116 ( V_151 , V_155 , & V_6 ) ;
} else {
V_55 = F_117 ( V_151 , & V_6 ) ;
V_55 = F_118 ( V_55 ) ;
}
F_17 ( F_14 ( V_41 ) , V_154 ) ;
F_119 ( V_41 -> V_117 ) ;
return V_55 ;
}
STATIC int
F_120 (
struct V_150 * V_151 )
{
struct V_41 * V_41 = F_27 ( V_151 -> V_152 -> V_153 ) ;
int V_55 ;
F_121 ( F_14 ( V_41 ) ) ;
if ( ( V_151 -> V_8 & V_156 ) && F_41 ( V_41 ) )
return F_113 ( V_151 ) ;
F_7 ( F_14 ( V_41 ) , V_154 ) ;
if ( F_41 ( V_41 ) )
V_55 = F_116 ( V_151 , V_155 , & V_6 ) ;
else
V_55 = F_122 ( V_151 ) ;
F_17 ( F_14 ( V_41 ) , V_154 ) ;
return V_55 ;
}
STATIC int
F_123 (
struct V_150 * V_151 ,
enum V_157 V_158 )
{
struct V_41 * V_41 = F_27 ( V_151 -> V_152 -> V_153 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_55 ;
if ( ! F_41 ( V_41 ) )
return V_159 ;
F_124 ( V_2 ) ;
if ( V_151 -> V_8 & V_156 ) {
F_115 ( V_41 -> V_117 ) ;
F_56 ( V_151 -> V_152 -> V_153 ) ;
}
F_7 ( F_14 ( V_41 ) , V_154 ) ;
V_55 = F_116 ( V_151 , V_158 , & V_6 ) ;
F_17 ( F_14 ( V_41 ) , V_154 ) ;
if ( V_151 -> V_8 & V_156 )
F_119 ( V_41 -> V_117 ) ;
return V_55 ;
}
static int
F_125 (
struct V_150 * V_151 )
{
struct V_41 * V_41 = F_27 ( V_151 -> V_152 -> V_153 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_55 = V_160 ;
T_2 V_76 ;
F_126 ( V_2 ) ;
F_115 ( V_41 -> V_117 ) ;
F_56 ( V_151 -> V_152 -> V_153 ) ;
F_7 ( V_2 , V_154 ) ;
V_76 = ( F_51 ( V_41 ) + V_161 - 1 ) >> V_162 ;
if ( V_151 -> V_163 >= V_76 )
V_55 = V_164 ;
else if ( F_41 ( V_41 ) )
V_55 = F_127 ( V_151 ) ;
F_17 ( V_2 , V_154 ) ;
F_119 ( V_41 -> V_117 ) ;
return V_55 ;
}
STATIC int
F_128 (
struct V_28 * V_142 ,
struct V_165 * V_152 )
{
F_30 ( V_142 ) ;
V_152 -> V_166 = & V_167 ;
if ( F_41 ( F_27 ( V_142 ) ) )
V_152 -> V_168 |= V_169 | V_170 ;
return 0 ;
}
