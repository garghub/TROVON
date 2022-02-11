static inline void
F_1 (
struct V_1 * V_2 ,
int type )
{
if ( type & V_3 )
F_2 ( F_3 ( V_2 ) ) ;
F_4 ( V_2 , type ) ;
}
static inline void
F_5 (
struct V_1 * V_2 ,
int type )
{
F_6 ( V_2 , type ) ;
if ( type & V_3 )
F_7 ( F_3 ( V_2 ) ) ;
}
static inline void
F_8 (
struct V_1 * V_2 ,
int type )
{
F_9 ( V_2 , type ) ;
if ( type & V_3 )
F_7 ( F_3 ( V_2 ) ) ;
}
int
F_10 (
struct V_1 * V_2 ,
T_1 V_4 ,
T_1 V_5 ,
bool * V_6 )
{
return F_11 ( F_3 ( V_2 ) , V_4 , V_5 , NULL , & V_7 ) ;
}
int
F_12 (
struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
int error ;
error = F_13 ( V_2 -> V_12 , & F_14 ( V_2 -> V_12 ) -> V_13 ,
0 , 0 , 0 , & V_11 ) ;
if ( error )
return error ;
F_4 ( V_2 , V_14 ) ;
F_15 ( V_11 , V_2 , V_14 ) ;
if ( ! ( V_9 & V_15 ) ) {
F_3 ( V_2 ) -> V_16 &= ~ V_17 ;
if ( F_3 ( V_2 ) -> V_16 & V_18 )
F_3 ( V_2 ) -> V_16 &= ~ V_19 ;
F_16 ( V_11 , V_2 , V_20 | V_21 ) ;
}
if ( V_9 & V_22 )
V_2 -> V_23 . V_24 |= V_25 ;
if ( V_9 & V_26 )
V_2 -> V_23 . V_24 &= ~ V_25 ;
F_17 ( V_11 , V_2 , V_27 ) ;
if ( V_9 & V_28 )
F_18 ( V_11 ) ;
return F_19 ( V_11 ) ;
}
STATIC int
F_20 (
struct V_29 * V_29 ,
T_2 V_30 ,
T_2 V_31 ,
int V_32 )
{
struct V_1 * V_2 = F_21 ( V_29 -> V_33 -> V_34 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_3 V_37 = 0 ;
F_22 ( V_2 ) ;
F_4 ( V_2 , V_38 ) ;
if ( F_23 ( V_2 ) )
V_37 = V_2 -> V_39 -> V_40 ;
F_6 ( V_2 , V_38 ) ;
if ( ! V_37 )
return 0 ;
return F_24 ( V_36 , V_37 , V_41 , NULL ) ;
}
STATIC int
F_25 (
struct V_29 * V_29 ,
T_2 V_30 ,
T_2 V_31 ,
int V_32 )
{
struct V_42 * V_42 = V_29 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
int error = 0 ;
int V_43 = 0 ;
T_3 V_37 = 0 ;
F_26 ( V_2 ) ;
error = F_27 ( V_42 -> V_44 , V_30 , V_31 ) ;
if ( error )
return error ;
if ( F_28 ( V_36 ) )
return - V_45 ;
F_29 ( V_2 , V_46 ) ;
if ( V_36 -> V_47 & V_48 ) {
if ( F_30 ( V_2 ) )
F_31 ( V_36 -> V_49 ) ;
else if ( V_36 -> V_50 != V_36 -> V_51 )
F_31 ( V_36 -> V_51 ) ;
}
F_4 ( V_2 , V_38 ) ;
if ( F_23 ( V_2 ) ) {
if ( ! V_32 ||
( V_2 -> V_39 -> V_52 & ~ V_53 ) )
V_37 = V_2 -> V_39 -> V_40 ;
}
if ( V_37 ) {
error = F_24 ( V_36 , V_37 , V_41 , & V_43 ) ;
V_2 -> V_39 -> V_52 = 0 ;
}
F_6 ( V_2 , V_38 ) ;
if ( ( V_36 -> V_47 & V_48 ) &&
V_36 -> V_50 == V_36 -> V_51 &&
! F_30 ( V_2 ) &&
! V_43 )
F_31 ( V_36 -> V_51 ) ;
return error ;
}
STATIC T_4
F_32 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = V_55 -> V_60 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_2 V_61 = F_33 ( V_42 ) ;
T_5 V_5 = F_34 ( V_57 ) ;
T_2 V_31 = V_55 -> V_62 + V_5 - 1 ;
struct V_56 V_63 ;
struct V_64 * V_65 ;
T_4 V_66 = 0 ;
F_35 ( V_2 , V_5 , V_55 -> V_62 ) ;
if ( ! V_5 )
return 0 ;
if ( F_30 ( V_2 ) )
V_65 = V_2 -> V_12 -> V_49 ;
else
V_65 = V_2 -> V_12 -> V_51 ;
if ( ( V_55 -> V_62 | V_5 ) & V_65 -> V_67 ) {
if ( V_55 -> V_62 == V_61 )
return 0 ;
return - V_68 ;
}
F_36 ( V_55 -> V_60 ) ;
F_1 ( V_2 , V_69 ) ;
if ( V_59 -> V_70 ) {
V_66 = F_27 ( V_59 , V_55 -> V_62 , V_31 ) ;
if ( V_66 )
goto V_71;
V_66 = F_37 ( V_59 ,
V_55 -> V_62 >> V_72 , V_31 >> V_72 ) ;
F_38 ( V_66 ) ;
V_66 = 0 ;
}
V_63 = * V_57 ;
V_66 = F_39 ( V_55 , V_42 , V_65 -> V_73 , & V_63 ,
V_74 , NULL , NULL , 0 ) ;
if ( V_66 >= 0 ) {
V_55 -> V_62 += V_66 ;
F_40 ( V_57 , V_66 ) ;
}
V_71:
F_5 ( V_2 , V_69 ) ;
return V_66 ;
}
static T_6 T_4
F_41 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_21 ( V_55 -> V_60 -> V_33 -> V_34 ) ;
T_5 V_5 = F_34 ( V_57 ) ;
T_4 V_66 = 0 ;
F_42 ( V_2 , V_5 , V_55 -> V_62 ) ;
if ( ! V_5 )
return 0 ;
F_1 ( V_2 , V_69 ) ;
V_66 = F_43 ( V_55 , V_57 , & V_7 ) ;
F_5 ( V_2 , V_69 ) ;
F_36 ( V_55 -> V_60 ) ;
return V_66 ;
}
STATIC T_4
F_44 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_21 ( F_45 ( V_55 -> V_60 ) ) ;
T_4 V_66 ;
F_46 ( V_2 , F_34 ( V_57 ) , V_55 -> V_62 ) ;
F_1 ( V_2 , V_69 ) ;
V_66 = F_47 ( V_55 , V_57 ) ;
F_5 ( V_2 , V_69 ) ;
return V_66 ;
}
STATIC T_4
F_48 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_42 * V_42 = F_45 ( V_55 -> V_60 ) ;
struct V_35 * V_36 = F_21 ( V_42 ) -> V_12 ;
T_4 V_66 = 0 ;
F_49 ( V_36 , V_75 ) ;
if ( F_28 ( V_36 ) )
return - V_45 ;
if ( F_50 ( V_42 ) )
V_66 = F_41 ( V_55 , V_57 ) ;
else if ( V_55 -> V_76 & V_77 )
V_66 = F_32 ( V_55 , V_57 ) ;
else
V_66 = F_44 ( V_55 , V_57 ) ;
if ( V_66 > 0 )
F_51 ( V_36 , V_78 , V_66 ) ;
return V_66 ;
}
int
F_52 (
struct V_1 * V_2 ,
T_1 V_79 ,
T_7 V_61 ,
bool * V_80 )
{
ASSERT ( F_53 ( V_2 , V_3 ) ) ;
ASSERT ( V_79 > V_61 ) ;
F_54 ( V_2 , V_61 , V_79 - V_61 ) ;
return F_10 ( V_2 , V_61 , V_79 - V_61 , V_80 ) ;
}
STATIC T_4
F_55 (
struct V_54 * V_55 ,
struct V_56 * V_81 ,
int * V_82 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_42 * V_42 = V_29 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 error = 0 ;
T_5 V_5 = F_34 ( V_81 ) ;
bool V_83 = false ;
V_84:
error = F_56 ( V_55 , V_81 ) ;
if ( error <= 0 )
return error ;
error = F_57 ( V_42 , V_82 , true ) ;
if ( error )
return error ;
if ( * V_82 == V_69 && ! F_58 ( V_42 ) ) {
F_5 ( V_2 , * V_82 ) ;
* V_82 = V_3 ;
F_1 ( V_2 , * V_82 ) ;
goto V_84;
}
F_59 ( & V_2 -> V_85 ) ;
if ( V_55 -> V_62 > F_33 ( V_42 ) ) {
bool V_86 = false ;
F_60 ( & V_2 -> V_85 ) ;
if ( ! V_83 ) {
if ( * V_82 == V_69 ) {
F_5 ( V_2 , * V_82 ) ;
* V_82 = V_3 ;
F_1 ( V_2 , * V_82 ) ;
F_61 ( V_81 , V_5 ) ;
}
F_62 ( V_42 ) ;
V_83 = true ;
goto V_84;
}
error = F_52 ( V_2 , V_55 -> V_62 , F_33 ( V_42 ) , & V_86 ) ;
if ( error )
return error ;
} else
F_60 ( & V_2 -> V_85 ) ;
if ( F_63 ( ! ( V_29 -> V_87 & V_88 ) ) ) {
error = F_64 ( V_29 ) ;
if ( error )
return error ;
}
if ( ! F_58 ( V_42 ) )
return F_65 ( V_29 ) ;
return 0 ;
}
STATIC T_4
F_66 (
struct V_54 * V_55 ,
struct V_56 * V_81 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_4 V_66 = 0 ;
int V_89 = 0 ;
int V_82 ;
T_5 V_5 = F_34 ( V_81 ) ;
T_2 V_31 ;
struct V_56 V_63 ;
struct V_64 * V_65 = F_30 ( V_2 ) ?
V_36 -> V_49 : V_36 -> V_51 ;
if ( ( V_55 -> V_62 | V_5 ) & V_65 -> V_67 )
return - V_68 ;
if ( ( V_55 -> V_62 & V_36 -> V_90 ) ||
( ( V_55 -> V_62 + V_5 ) & V_36 -> V_90 ) ) {
V_89 = 1 ;
V_82 = V_3 ;
} else {
V_82 = V_69 ;
}
F_1 ( V_2 , V_82 ) ;
V_66 = F_55 ( V_55 , V_81 , & V_82 ) ;
if ( V_66 )
goto V_91;
V_5 = F_34 ( V_81 ) ;
V_31 = V_55 -> V_62 + V_5 - 1 ;
if ( V_59 -> V_70 ) {
V_66 = F_27 ( V_59 , V_55 -> V_62 , V_31 ) ;
if ( V_66 )
goto V_91;
V_66 = F_37 ( V_59 ,
V_55 -> V_62 >> V_72 , V_31 >> V_72 ) ;
F_38 ( V_66 ) ;
V_66 = 0 ;
}
if ( V_89 )
F_62 ( V_42 ) ;
else if ( V_82 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_82 = V_69 ;
}
F_67 ( V_2 , V_5 , V_55 -> V_62 ) ;
if ( F_68 ( V_2 ) && ! V_89 ) {
V_66 = F_69 ( V_2 , V_55 -> V_62 , V_5 ) ;
if ( V_66 )
goto V_91;
}
V_63 = * V_81 ;
V_66 = F_39 ( V_55 , V_42 , V_65 -> V_73 , & V_63 ,
V_74 , V_92 ,
NULL , V_93 ) ;
if ( V_59 -> V_70 ) {
F_37 ( V_59 ,
V_55 -> V_62 >> V_72 ,
V_31 >> V_72 ) ;
}
if ( V_66 > 0 ) {
V_55 -> V_62 += V_66 ;
F_40 ( V_81 , V_66 ) ;
}
V_91:
F_5 ( V_2 , V_82 ) ;
ASSERT ( V_66 < 0 || V_66 == V_5 ) ;
return V_66 ;
}
static T_6 T_4
F_70 (
struct V_54 * V_55 ,
struct V_56 * V_81 )
{
struct V_42 * V_42 = V_55 -> V_60 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_82 = V_3 ;
T_4 V_66 , error = 0 ;
T_5 V_5 ;
T_2 V_4 ;
F_1 ( V_2 , V_82 ) ;
V_66 = F_55 ( V_55 , V_81 , & V_82 ) ;
if ( V_66 )
goto V_91;
V_4 = V_55 -> V_62 ;
V_5 = F_34 ( V_81 ) ;
F_71 ( V_2 , V_5 , V_4 ) ;
V_66 = F_43 ( V_55 , V_81 , & V_7 ) ;
if ( V_66 > 0 && V_55 -> V_62 > F_33 ( V_42 ) ) {
F_72 ( V_42 , V_55 -> V_62 ) ;
error = F_73 ( V_2 , V_4 , V_66 ) ;
}
V_91:
F_5 ( V_2 , V_82 ) ;
return error ? error : V_66 ;
}
STATIC T_4
F_74 (
struct V_54 * V_55 ,
struct V_56 * V_81 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 V_66 ;
int V_94 = 0 ;
int V_82 = V_3 ;
F_1 ( V_2 , V_82 ) ;
V_66 = F_55 ( V_55 , V_81 , & V_82 ) ;
if ( V_66 )
goto V_91;
V_95 -> V_96 = F_75 ( V_42 ) ;
V_97:
F_76 ( V_2 , F_34 ( V_81 ) , V_55 -> V_62 ) ;
V_66 = F_77 ( V_55 , V_81 , & V_7 ) ;
if ( F_63 ( V_66 >= 0 ) )
V_55 -> V_62 += V_66 ;
if ( V_66 == - V_98 && ! V_94 ) {
V_94 = F_78 ( V_2 ) ;
if ( V_94 )
goto V_97;
V_94 = F_79 ( V_2 ) ;
if ( V_94 )
goto V_97;
} else if ( V_66 == - V_99 && ! V_94 ) {
struct V_100 V_101 = { 0 } ;
V_94 = 1 ;
F_80 ( V_2 -> V_12 ) ;
V_101 . V_102 = V_2 -> V_103 ;
V_101 . V_104 = V_105 ;
F_81 ( V_2 -> V_12 , & V_101 ) ;
goto V_97;
}
V_95 -> V_96 = NULL ;
V_91:
F_5 ( V_2 , V_82 ) ;
return V_66 ;
}
STATIC T_4
F_82 (
struct V_54 * V_55 ,
struct V_56 * V_81 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 V_66 ;
T_5 V_106 = F_34 ( V_81 ) ;
F_49 ( V_2 -> V_12 , V_107 ) ;
if ( V_106 == 0 )
return 0 ;
if ( F_28 ( V_2 -> V_12 ) )
return - V_45 ;
if ( F_50 ( V_42 ) )
V_66 = F_70 ( V_55 , V_81 ) ;
else if ( V_55 -> V_76 & V_77 ) {
V_66 = F_66 ( V_55 , V_81 ) ;
if ( V_66 == - V_108 )
goto V_109;
} else {
V_109:
V_66 = F_74 ( V_55 , V_81 ) ;
}
if ( V_66 > 0 ) {
F_51 ( V_2 -> V_12 , V_110 , V_66 ) ;
V_66 = F_83 ( V_55 , V_66 ) ;
}
return V_66 ;
}
STATIC long
F_84 (
struct V_29 * V_29 ,
int V_111 ,
T_2 V_79 ,
T_2 V_112 )
{
struct V_42 * V_42 = F_45 ( V_29 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
long error ;
enum V_8 V_9 = 0 ;
T_8 V_82 = V_3 ;
T_2 V_113 = 0 ;
bool V_114 = 0 ;
if ( ! F_85 ( V_42 -> V_16 ) )
return - V_68 ;
if ( V_111 & ~ V_115 )
return - V_116 ;
F_4 ( V_2 , V_82 ) ;
error = F_57 ( V_42 , & V_82 , false ) ;
if ( error )
goto V_71;
F_4 ( V_2 , V_117 ) ;
V_82 |= V_117 ;
if ( V_111 & V_118 ) {
error = F_86 ( V_2 , V_79 , V_112 ) ;
if ( error )
goto V_71;
} else if ( V_111 & V_119 ) {
unsigned V_120 = ( 1 << V_42 -> V_121 ) - 1 ;
if ( V_79 & V_120 || V_112 & V_120 ) {
error = - V_68 ;
goto V_71;
}
if ( V_79 + V_112 >= F_33 ( V_42 ) ) {
error = - V_68 ;
goto V_71;
}
V_113 = F_33 ( V_42 ) - V_112 ;
error = F_87 ( V_2 , V_79 , V_112 ) ;
if ( error )
goto V_71;
} else if ( V_111 & V_122 ) {
unsigned V_120 = ( 1 << V_42 -> V_121 ) - 1 ;
V_113 = F_33 ( V_42 ) + V_112 ;
if ( V_79 & V_120 || V_112 & V_120 ) {
error = - V_68 ;
goto V_71;
}
if ( V_113 > V_42 -> V_123 -> V_124 ) {
error = - V_125 ;
goto V_71;
}
if ( V_79 >= F_33 ( V_42 ) ) {
error = - V_68 ;
goto V_71;
}
V_114 = 1 ;
} else {
V_9 |= V_22 ;
if ( ! ( V_111 & V_126 ) &&
V_79 + V_112 > F_33 ( V_42 ) ) {
V_113 = V_79 + V_112 ;
error = F_88 ( V_42 , V_113 ) ;
if ( error )
goto V_71;
}
if ( V_111 & V_127 )
error = F_89 ( V_2 , V_79 , V_112 ) ;
else {
if ( V_111 & V_128 ) {
error = F_90 ( V_2 , V_79 , V_112 ) ;
if ( error )
goto V_71;
}
error = F_91 ( V_2 , V_79 , V_112 ,
V_129 ) ;
}
if ( error )
goto V_71;
}
if ( V_29 -> V_130 & V_131 )
V_9 |= V_28 ;
error = F_12 ( V_2 , V_9 ) ;
if ( error )
goto V_71;
if ( V_113 ) {
struct V_132 V_132 ;
V_132 . V_133 = V_134 ;
V_132 . V_135 = V_113 ;
error = F_92 ( F_93 ( V_29 ) , & V_132 ) ;
if ( error )
goto V_71;
}
if ( V_114 )
error = F_94 ( V_2 , V_79 , V_112 ) ;
V_71:
F_6 ( V_2 , V_82 ) ;
return error ;
}
STATIC T_4
F_95 (
struct V_29 * V_136 ,
T_2 V_137 ,
struct V_29 * V_138 ,
T_2 V_139 ,
T_5 V_112 ,
unsigned int V_9 )
{
int error ;
error = F_96 ( V_136 , V_137 , V_138 , V_139 ,
V_112 , false ) ;
if ( error )
return error ;
return V_112 ;
}
STATIC int
F_97 (
struct V_29 * V_136 ,
T_2 V_137 ,
struct V_29 * V_138 ,
T_2 V_139 ,
T_9 V_112 )
{
return F_96 ( V_136 , V_137 , V_138 , V_139 ,
V_112 , false ) ;
}
STATIC T_4
F_98 (
struct V_29 * V_140 ,
T_9 V_141 ,
T_9 V_112 ,
struct V_29 * V_142 ,
T_9 V_143 )
{
int error ;
if ( V_112 > V_144 )
V_112 = V_144 ;
error = F_96 ( V_140 , V_141 , V_142 , V_143 ,
V_112 , true ) ;
if ( error )
return error ;
return V_112 ;
}
STATIC int
F_99 (
struct V_42 * V_42 ,
struct V_29 * V_29 )
{
if ( ! ( V_29 -> V_130 & V_145 ) && F_33 ( V_42 ) > V_146 )
return - V_125 ;
if ( F_28 ( F_100 ( V_42 -> V_123 ) ) )
return - V_45 ;
return 0 ;
}
STATIC int
F_101 (
struct V_42 * V_42 ,
struct V_29 * V_29 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_111 ;
int error ;
error = F_99 ( V_42 , V_29 ) ;
if ( error )
return error ;
V_111 = F_102 ( V_2 ) ;
if ( V_2 -> V_23 . V_147 > 0 )
F_103 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_111 ) ;
return 0 ;
}
STATIC int
F_104 (
struct V_42 * V_42 ,
struct V_29 * V_148 )
{
return F_105 ( F_21 ( V_42 ) ) ;
}
STATIC int
F_106 (
struct V_29 * V_29 ,
struct V_149 * V_150 )
{
struct V_42 * V_42 = F_45 ( V_29 ) ;
T_10 * V_2 = F_21 ( V_42 ) ;
T_5 V_151 ;
V_151 = ( T_5 ) F_107 ( T_2 , 32768 , V_2 -> V_23 . V_152 ) ;
return F_108 ( V_2 , V_150 , V_151 ) ;
}
STATIC bool
F_109 (
struct V_153 * V_153 ,
T_2 * V_79 ,
unsigned int type )
{
T_2 V_154 = F_110 ( V_153 ) ;
bool V_155 = false ;
struct V_156 * V_157 , * V_158 ;
V_157 = V_158 = F_111 ( V_153 ) ;
do {
if ( F_112 ( V_157 ) ||
F_113 ( V_157 ) ) {
if ( type == V_159 )
V_155 = true ;
} else {
if ( type == V_160 )
V_155 = true ;
}
if ( V_155 ) {
* V_79 = V_154 ;
break;
}
V_154 += V_157 -> V_161 ;
} while ( ( V_157 = V_157 -> V_162 ) != V_158 );
return V_155 ;
}
STATIC bool
F_114 (
struct V_42 * V_42 ,
struct V_163 * V_164 ,
unsigned int type ,
T_2 * V_79 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
struct V_165 V_166 ;
T_11 V_167 ;
T_11 V_31 ;
T_2 V_168 ;
T_2 V_169 = * V_79 ;
T_2 V_154 = V_169 ;
bool V_155 = false ;
F_115 ( & V_166 , 0 ) ;
V_167 = V_169 >> V_72 ;
V_168 = F_116 ( V_36 , V_164 -> V_170 + V_164 -> V_171 ) ;
V_31 = V_168 >> V_72 ;
do {
int V_172 ;
unsigned V_173 ;
unsigned int V_174 ;
V_172 = F_107 ( T_11 , V_31 - V_167 , V_175 ) ;
V_173 = F_117 ( & V_166 , V_42 -> V_44 , V_167 ,
V_172 ) ;
if ( V_173 == 0 ) {
if ( type == V_159 )
break;
ASSERT ( type == V_160 ) ;
if ( V_154 == V_169 || V_154 < V_168 ) {
V_155 = true ;
* V_79 = V_154 ;
}
break;
}
if ( type == V_160 && V_154 == V_169 &&
V_154 < F_110 ( V_166 . V_176 [ 0 ] ) ) {
V_155 = true ;
break;
}
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
struct V_153 * V_153 = V_166 . V_176 [ V_174 ] ;
T_2 V_177 ;
if ( V_153 -> V_167 > V_31 ) {
if ( type == V_160 && V_154 < V_168 ) {
* V_79 = V_154 ;
V_155 = true ;
}
goto V_91;
}
F_118 ( V_153 ) ;
if ( F_119 ( V_153 -> V_59 != V_42 -> V_44 ) ) {
F_120 ( V_153 ) ;
continue;
}
if ( ! F_121 ( V_153 ) ) {
F_120 ( V_153 ) ;
continue;
}
V_155 = F_109 ( V_153 , & V_177 , type ) ;
if ( V_155 ) {
* V_79 = F_122 ( T_2 , V_169 , V_177 ) ;
F_120 ( V_153 ) ;
goto V_91;
}
V_154 = F_110 ( V_153 ) + V_178 ;
F_120 ( V_153 ) ;
}
if ( V_173 < V_172 ) {
if ( type == V_160 ) {
* V_79 = V_154 ;
V_155 = true ;
}
break;
}
V_167 = V_166 . V_176 [ V_174 - 1 ] -> V_167 + 1 ;
F_123 ( & V_166 ) ;
} while ( V_167 <= V_31 );
V_91:
F_123 ( & V_166 ) ;
return V_155 ;
}
T_2
F_124 (
struct V_42 * V_42 ,
T_2 V_30 ,
T_2 V_31 ,
int V_179 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_2 V_180 ( V_79 ) ;
T_12 V_181 ;
T_13 V_182 ;
int error ;
if ( V_30 >= V_31 ) {
error = - V_183 ;
goto V_184;
}
V_181 = F_125 ( V_36 , V_30 ) ;
V_182 = F_126 ( V_36 , V_31 ) ;
for (; ; ) {
struct V_163 V_164 [ 2 ] ;
int V_185 = 2 ;
unsigned int V_174 ;
error = F_127 ( V_2 , V_181 , V_182 - V_181 , V_164 , & V_185 ,
V_186 ) ;
if ( error )
goto V_184;
if ( V_185 == 0 ) {
error = - V_183 ;
goto V_184;
}
for ( V_174 = 0 ; V_174 < V_185 ; V_174 ++ ) {
V_79 = F_122 ( T_2 , V_30 ,
F_116 ( V_36 , V_164 [ V_174 ] . V_170 ) ) ;
if ( V_179 == V_187 &&
V_164 [ V_174 ] . V_188 == V_189 )
goto V_91;
if ( V_179 == V_190 &&
( V_164 [ V_174 ] . V_188 == V_191 ||
( V_164 [ V_174 ] . V_192 == V_193 &&
! F_128 ( V_164 [ V_174 ] . V_188 ) ) ) )
goto V_91;
if ( V_164 [ V_174 ] . V_192 == V_194 ) {
if ( F_114 ( V_42 , & V_164 [ V_174 ] ,
V_179 == V_187 ? V_160 : V_159 ,
& V_79 ) )
goto V_91;
}
}
if ( V_185 == 1 ) {
if ( V_179 == V_187 ) {
V_79 = V_31 ;
break;
}
ASSERT ( V_179 == V_190 ) ;
error = - V_183 ;
goto V_184;
}
ASSERT ( V_174 > 1 ) ;
V_181 = V_164 [ V_174 - 1 ] . V_170 + V_164 [ V_174 - 1 ] . V_171 ;
V_30 = F_116 ( V_36 , V_181 ) ;
if ( V_30 >= V_31 ) {
if ( V_179 == V_187 ) {
V_79 = V_31 ;
break;
}
ASSERT ( V_179 == V_190 ) ;
error = - V_183 ;
goto V_184;
}
}
V_91:
if ( V_179 == V_187 )
V_79 = F_107 ( T_2 , V_79 , V_31 ) ;
return V_79 ;
V_184:
return error ;
}
STATIC T_2
F_129 (
struct V_29 * V_29 ,
T_2 V_30 ,
int V_179 )
{
struct V_42 * V_42 = V_29 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_8 V_195 ;
T_2 V_79 , V_31 ;
int error = 0 ;
if ( F_28 ( V_36 ) )
return - V_45 ;
V_195 = F_102 ( V_2 ) ;
V_31 = F_33 ( V_42 ) ;
V_79 = F_124 ( V_42 , V_30 , V_31 , V_179 ) ;
if ( V_79 < 0 ) {
error = V_79 ;
goto V_71;
}
V_79 = F_130 ( V_29 , V_79 , V_42 -> V_123 -> V_124 ) ;
V_71:
F_6 ( V_2 , V_195 ) ;
if ( error )
return error ;
return V_79 ;
}
STATIC T_2
F_131 (
struct V_29 * V_29 ,
T_2 V_79 ,
int V_179 )
{
switch ( V_179 ) {
case V_196 :
case V_197 :
case V_198 :
return F_132 ( V_29 , V_79 , V_179 ) ;
case V_187 :
case V_190 :
return F_129 ( V_29 , V_79 , V_179 ) ;
default:
return - V_68 ;
}
}
STATIC int
F_133 (
struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_42 * V_42 = F_45 ( V_200 -> V_203 ) ;
int V_66 ;
F_134 ( F_21 ( V_42 ) ) ;
F_135 ( V_42 -> V_123 ) ;
F_64 ( V_200 -> V_203 ) ;
F_4 ( F_21 ( V_42 ) , V_204 ) ;
if ( F_50 ( V_42 ) ) {
V_66 = F_136 ( V_200 , V_202 , & V_7 ) ;
} else {
V_66 = F_137 ( V_200 , V_202 , & V_7 ) ;
V_66 = F_138 ( V_66 ) ;
}
F_6 ( F_21 ( V_42 ) , V_204 ) ;
F_139 ( V_42 -> V_123 ) ;
return V_66 ;
}
STATIC int
F_140 (
struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_42 * V_42 = F_45 ( V_200 -> V_203 ) ;
int V_66 ;
F_141 ( F_21 ( V_42 ) ) ;
if ( ( V_202 -> V_9 & V_205 ) && F_50 ( V_42 ) )
return F_133 ( V_200 , V_202 ) ;
F_4 ( F_21 ( V_42 ) , V_204 ) ;
if ( F_50 ( V_42 ) ) {
V_66 = F_136 ( V_200 , V_202 , & V_7 ) ;
} else
V_66 = F_142 ( V_200 , V_202 ) ;
F_6 ( F_21 ( V_42 ) , V_204 ) ;
return V_66 ;
}
STATIC int
F_143 (
struct V_199 * V_200 ,
unsigned long V_206 ,
T_14 * V_207 ,
unsigned int V_9 )
{
struct V_42 * V_42 = F_45 ( V_200 -> V_203 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_66 ;
if ( ! F_50 ( V_42 ) )
return V_208 ;
F_144 ( V_2 ) ;
if ( V_9 & V_205 ) {
F_135 ( V_42 -> V_123 ) ;
F_64 ( V_200 -> V_203 ) ;
}
F_4 ( F_21 ( V_42 ) , V_204 ) ;
V_66 = F_145 ( V_200 , V_206 , V_207 , V_9 , V_209 ) ;
F_6 ( F_21 ( V_42 ) , V_204 ) ;
if ( V_9 & V_205 )
F_139 ( V_42 -> V_123 ) ;
return V_66 ;
}
static int
F_146 (
struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_42 * V_42 = F_45 ( V_200 -> V_203 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_66 = V_210 ;
T_2 V_211 ;
F_147 ( V_2 ) ;
F_135 ( V_42 -> V_123 ) ;
F_64 ( V_200 -> V_203 ) ;
F_4 ( V_2 , V_204 ) ;
V_211 = ( F_33 ( V_42 ) + V_178 - 1 ) >> V_72 ;
if ( V_202 -> V_212 >= V_211 )
V_66 = V_213 ;
else if ( F_50 ( V_42 ) )
V_66 = F_148 ( V_200 , V_202 ) ;
F_6 ( V_2 , V_204 ) ;
F_139 ( V_42 -> V_123 ) ;
return V_66 ;
}
STATIC int
F_149 (
struct V_29 * V_148 ,
struct V_199 * V_200 )
{
F_36 ( V_148 ) ;
V_200 -> V_214 = & V_215 ;
if ( F_50 ( F_45 ( V_148 ) ) )
V_200 -> V_216 |= V_217 | V_218 ;
return 0 ;
}
