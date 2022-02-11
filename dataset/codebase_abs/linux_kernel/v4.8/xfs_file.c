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
struct V_56 V_62 ;
struct V_63 * V_64 ;
T_4 V_65 = 0 ;
F_35 ( V_2 , V_5 , V_55 -> V_66 ) ;
if ( ! V_5 )
return 0 ;
if ( F_30 ( V_2 ) )
V_64 = V_2 -> V_12 -> V_49 ;
else
V_64 = V_2 -> V_12 -> V_51 ;
if ( ( V_55 -> V_66 | V_5 ) & V_64 -> V_67 ) {
if ( V_55 -> V_66 == V_61 )
return 0 ;
return - V_68 ;
}
F_1 ( V_2 , V_69 ) ;
if ( V_59 -> V_70 ) {
F_5 ( V_2 , V_69 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_59 -> V_70 ) {
V_65 = F_36 ( V_59 ) ;
if ( V_65 ) {
F_5 ( V_2 , V_3 ) ;
return V_65 ;
}
V_65 = F_37 ( V_59 ) ;
F_38 ( V_65 ) ;
V_65 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
V_62 = * V_57 ;
V_65 = F_39 ( V_55 , V_42 , V_64 -> V_71 , & V_62 ,
V_72 , NULL , NULL , 0 ) ;
if ( V_65 > 0 ) {
V_55 -> V_66 += V_65 ;
F_40 ( V_57 , V_65 ) ;
}
F_5 ( V_2 , V_69 ) ;
F_41 ( V_55 -> V_60 ) ;
return V_65 ;
}
static T_6 T_4
F_42 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = V_55 -> V_60 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_56 V_62 = * V_57 ;
T_5 V_5 = F_34 ( V_57 ) ;
T_4 V_65 = 0 ;
F_43 ( V_2 , V_5 , V_55 -> V_66 ) ;
if ( ! V_5 )
return 0 ;
F_1 ( V_2 , V_69 ) ;
V_65 = F_44 ( V_55 , V_42 , & V_62 , V_72 , NULL , 0 ) ;
if ( V_65 > 0 ) {
V_55 -> V_66 += V_65 ;
F_40 ( V_57 , V_65 ) ;
}
F_5 ( V_2 , V_69 ) ;
F_41 ( V_55 -> V_60 ) ;
return V_65 ;
}
STATIC T_4
F_45 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_21 ( F_46 ( V_55 -> V_60 ) ) ;
T_4 V_65 ;
F_47 ( V_2 , F_34 ( V_57 ) , V_55 -> V_66 ) ;
F_1 ( V_2 , V_69 ) ;
V_65 = F_48 ( V_55 , V_57 ) ;
F_5 ( V_2 , V_69 ) ;
return V_65 ;
}
STATIC T_4
F_49 (
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_42 * V_42 = F_46 ( V_55 -> V_60 ) ;
struct V_35 * V_36 = F_21 ( V_42 ) -> V_12 ;
T_4 V_65 = 0 ;
F_50 ( V_36 , V_73 ) ;
if ( F_28 ( V_36 ) )
return - V_45 ;
if ( F_51 ( V_42 ) )
V_65 = F_42 ( V_55 , V_57 ) ;
else if ( V_55 -> V_74 & V_75 )
V_65 = F_32 ( V_55 , V_57 ) ;
else
V_65 = F_45 ( V_55 , V_57 ) ;
if ( V_65 > 0 )
F_52 ( V_36 , V_76 , V_65 ) ;
return V_65 ;
}
STATIC T_4
F_53 (
struct V_29 * V_77 ,
T_2 * V_78 ,
struct V_79 * V_80 ,
T_5 V_5 ,
unsigned int V_9 )
{
struct V_1 * V_2 = F_21 ( V_77 -> V_33 -> V_34 ) ;
T_4 V_65 ;
F_50 ( V_2 -> V_12 , V_73 ) ;
if ( F_28 ( V_2 -> V_12 ) )
return - V_45 ;
F_54 ( V_2 , V_5 , * V_78 ) ;
if ( F_51 ( F_3 ( V_2 ) ) ) {
V_65 = F_55 ( V_77 , V_78 , V_80 , V_5 ,
V_9 ) ;
goto V_81;
}
F_1 ( V_2 , V_69 ) ;
V_65 = F_56 ( V_77 , V_78 , V_80 , V_5 , V_9 ) ;
F_5 ( V_2 , V_69 ) ;
V_81:
if ( V_65 > 0 )
F_52 ( V_2 -> V_12 , V_76 , V_65 ) ;
return V_65 ;
}
int
F_57 (
struct V_1 * V_2 ,
T_1 V_82 ,
T_7 V_61 ,
bool * V_83 )
{
ASSERT ( F_58 ( V_2 , V_3 ) ) ;
ASSERT ( V_82 > V_61 ) ;
F_59 ( V_2 , V_61 , V_82 - V_61 ) ;
return F_10 ( V_2 , V_61 , V_82 - V_61 , V_83 ) ;
}
STATIC T_4
F_60 (
struct V_54 * V_55 ,
struct V_56 * V_84 ,
int * V_85 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_42 * V_42 = V_29 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 error = 0 ;
T_5 V_5 = F_34 ( V_84 ) ;
bool V_86 = false ;
V_87:
error = F_61 ( V_55 , V_84 ) ;
if ( error <= 0 )
return error ;
error = F_62 ( V_42 , V_85 , true ) ;
if ( error )
return error ;
if ( * V_85 == V_69 && ! F_63 ( V_42 ) ) {
F_5 ( V_2 , * V_85 ) ;
* V_85 = V_3 ;
F_1 ( V_2 , * V_85 ) ;
goto V_87;
}
F_64 ( & V_2 -> V_88 ) ;
if ( V_55 -> V_66 > F_33 ( V_42 ) ) {
bool V_89 = false ;
F_65 ( & V_2 -> V_88 ) ;
if ( ! V_86 ) {
if ( * V_85 == V_69 ) {
F_5 ( V_2 , * V_85 ) ;
* V_85 = V_3 ;
F_1 ( V_2 , * V_85 ) ;
F_66 ( V_84 , V_5 ) ;
}
F_67 ( V_42 ) ;
V_86 = true ;
goto V_87;
}
error = F_57 ( V_2 , V_55 -> V_66 , F_33 ( V_42 ) , & V_89 ) ;
if ( error )
return error ;
} else
F_65 ( & V_2 -> V_88 ) ;
if ( F_68 ( ! ( V_29 -> V_90 & V_91 ) ) ) {
error = F_69 ( V_29 ) ;
if ( error )
return error ;
}
if ( ! F_63 ( V_42 ) )
return F_70 ( V_29 ) ;
return 0 ;
}
STATIC T_4
F_71 (
struct V_54 * V_55 ,
struct V_56 * V_84 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_4 V_65 = 0 ;
int V_92 = 0 ;
int V_85 ;
T_5 V_5 = F_34 ( V_84 ) ;
T_2 V_31 ;
struct V_56 V_62 ;
struct V_63 * V_64 = F_30 ( V_2 ) ?
V_36 -> V_49 : V_36 -> V_51 ;
if ( ( V_55 -> V_66 | V_5 ) & V_64 -> V_67 )
return - V_68 ;
if ( ( V_55 -> V_66 & V_36 -> V_93 ) ||
( ( V_55 -> V_66 + V_5 ) & V_36 -> V_93 ) )
V_92 = 1 ;
if ( V_92 || V_59 -> V_70 )
V_85 = V_3 ;
else
V_85 = V_69 ;
F_1 ( V_2 , V_85 ) ;
if ( V_59 -> V_70 && V_85 == V_69 ) {
F_5 ( V_2 , V_85 ) ;
V_85 = V_3 ;
F_1 ( V_2 , V_85 ) ;
}
V_65 = F_60 ( V_55 , V_84 , & V_85 ) ;
if ( V_65 )
goto V_81;
V_5 = F_34 ( V_84 ) ;
V_31 = V_55 -> V_66 + V_5 - 1 ;
if ( V_59 -> V_70 ) {
V_65 = F_36 ( F_3 ( V_2 ) -> V_44 ) ;
if ( V_65 )
goto V_81;
V_65 = F_37 ( F_3 ( V_2 ) -> V_44 ) ;
F_38 ( V_65 ) ;
V_65 = 0 ;
}
if ( V_92 )
F_67 ( V_42 ) ;
else if ( V_85 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_85 = V_69 ;
}
F_72 ( V_2 , V_5 , V_55 -> V_66 ) ;
V_62 = * V_84 ;
V_65 = F_39 ( V_55 , V_42 , V_64 -> V_71 , & V_62 ,
V_72 , V_94 ,
NULL , V_95 ) ;
if ( V_59 -> V_70 ) {
F_73 ( V_59 ,
V_55 -> V_66 >> V_96 ,
V_31 >> V_96 ) ;
}
if ( V_65 > 0 ) {
V_55 -> V_66 += V_65 ;
F_40 ( V_84 , V_65 ) ;
}
V_81:
F_5 ( V_2 , V_85 ) ;
ASSERT ( V_65 < 0 || V_65 == V_5 ) ;
return V_65 ;
}
static T_6 T_4
F_74 (
struct V_54 * V_55 ,
struct V_56 * V_84 )
{
struct V_58 * V_59 = V_55 -> V_60 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_4 V_65 = 0 ;
int V_92 = 0 ;
int V_85 ;
struct V_56 V_62 ;
if ( ( V_55 -> V_66 & V_36 -> V_93 ) ||
( ( V_55 -> V_66 + F_34 ( V_84 ) ) & V_36 -> V_93 ) ) {
V_92 = 1 ;
V_85 = V_3 ;
} else if ( V_59 -> V_70 ) {
V_85 = V_3 ;
} else {
V_85 = V_69 ;
}
F_1 ( V_2 , V_85 ) ;
V_65 = F_60 ( V_55 , V_84 , & V_85 ) ;
if ( V_65 )
goto V_81;
if ( V_59 -> V_70 ) {
T_2 V_31 = V_55 -> V_66 + F_34 ( V_84 ) - 1 ;
V_65 = F_73 ( V_59 ,
V_55 -> V_66 >> V_96 ,
V_31 >> V_96 ) ;
F_38 ( V_65 ) ;
}
if ( V_85 == V_3 && ! V_92 ) {
F_8 ( V_2 , V_3 ) ;
V_85 = V_69 ;
}
F_75 ( V_2 , F_34 ( V_84 ) , V_55 -> V_66 ) ;
V_62 = * V_84 ;
V_65 = F_44 ( V_55 , V_42 , & V_62 , V_72 ,
V_94 , 0 ) ;
if ( V_65 > 0 ) {
V_55 -> V_66 += V_65 ;
F_40 ( V_84 , V_65 ) ;
}
V_81:
F_5 ( V_2 , V_85 ) ;
return V_65 ;
}
STATIC T_4
F_76 (
struct V_54 * V_55 ,
struct V_56 * V_84 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 V_65 ;
int V_97 = 0 ;
int V_85 = V_3 ;
F_1 ( V_2 , V_85 ) ;
V_65 = F_60 ( V_55 , V_84 , & V_85 ) ;
if ( V_65 )
goto V_81;
V_98 -> V_99 = F_77 ( V_42 ) ;
V_100:
F_78 ( V_2 , F_34 ( V_84 ) , V_55 -> V_66 ) ;
V_65 = F_79 ( V_55 , V_84 , & V_7 ) ;
if ( F_68 ( V_65 >= 0 ) )
V_55 -> V_66 += V_65 ;
if ( V_65 == - V_101 && ! V_97 ) {
V_97 = F_80 ( V_2 ) ;
if ( V_97 )
goto V_100;
} else if ( V_65 == - V_102 && ! V_97 ) {
struct V_103 V_104 = { 0 } ;
V_97 = 1 ;
F_81 ( V_2 -> V_12 ) ;
V_104 . V_105 = V_2 -> V_106 ;
V_104 . V_107 = V_108 ;
F_82 ( V_2 -> V_12 , & V_104 ) ;
goto V_100;
}
V_98 -> V_99 = NULL ;
V_81:
F_5 ( V_2 , V_85 ) ;
return V_65 ;
}
STATIC T_4
F_83 (
struct V_54 * V_55 ,
struct V_56 * V_84 )
{
struct V_29 * V_29 = V_55 -> V_60 ;
struct V_58 * V_59 = V_29 -> V_33 ;
struct V_42 * V_42 = V_59 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
T_4 V_65 ;
T_5 V_109 = F_34 ( V_84 ) ;
F_50 ( V_2 -> V_12 , V_110 ) ;
if ( V_109 == 0 )
return 0 ;
if ( F_28 ( V_2 -> V_12 ) )
return - V_45 ;
if ( F_51 ( V_42 ) )
V_65 = F_74 ( V_55 , V_84 ) ;
else if ( V_55 -> V_74 & V_75 )
V_65 = F_71 ( V_55 , V_84 ) ;
else
V_65 = F_76 ( V_55 , V_84 ) ;
if ( V_65 > 0 ) {
F_52 ( V_2 -> V_12 , V_111 , V_65 ) ;
V_65 = F_84 ( V_55 , V_65 ) ;
}
return V_65 ;
}
STATIC long
F_85 (
struct V_29 * V_29 ,
int V_112 ,
T_2 V_82 ,
T_2 V_113 )
{
struct V_42 * V_42 = F_46 ( V_29 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
long error ;
enum V_8 V_9 = 0 ;
T_8 V_85 = V_3 ;
T_2 V_114 = 0 ;
bool V_115 = 0 ;
if ( ! F_86 ( V_42 -> V_16 ) )
return - V_68 ;
if ( V_112 & ~ V_116 )
return - V_117 ;
F_4 ( V_2 , V_85 ) ;
error = F_62 ( V_42 , & V_85 , false ) ;
if ( error )
goto V_118;
F_4 ( V_2 , V_119 ) ;
V_85 |= V_119 ;
if ( V_112 & V_120 ) {
error = F_87 ( V_2 , V_82 , V_113 ) ;
if ( error )
goto V_118;
} else if ( V_112 & V_121 ) {
unsigned V_122 = ( 1 << V_42 -> V_123 ) - 1 ;
if ( V_82 & V_122 || V_113 & V_122 ) {
error = - V_68 ;
goto V_118;
}
if ( V_82 + V_113 >= F_33 ( V_42 ) ) {
error = - V_68 ;
goto V_118;
}
V_114 = F_33 ( V_42 ) - V_113 ;
error = F_88 ( V_2 , V_82 , V_113 ) ;
if ( error )
goto V_118;
} else if ( V_112 & V_124 ) {
unsigned V_122 = ( 1 << V_42 -> V_123 ) - 1 ;
V_114 = F_33 ( V_42 ) + V_113 ;
if ( V_82 & V_122 || V_113 & V_122 ) {
error = - V_68 ;
goto V_118;
}
if ( V_114 > V_42 -> V_125 -> V_126 ) {
error = - V_127 ;
goto V_118;
}
if ( V_82 >= F_33 ( V_42 ) ) {
error = - V_68 ;
goto V_118;
}
V_115 = 1 ;
} else {
V_9 |= V_22 ;
if ( ! ( V_112 & V_128 ) &&
V_82 + V_113 > F_33 ( V_42 ) ) {
V_114 = V_82 + V_113 ;
error = F_89 ( V_42 , V_114 ) ;
if ( error )
goto V_118;
}
if ( V_112 & V_129 )
error = F_90 ( V_2 , V_82 , V_113 ) ;
else
error = F_91 ( V_2 , V_82 , V_113 ,
V_130 ) ;
if ( error )
goto V_118;
}
if ( V_29 -> V_131 & V_132 )
V_9 |= V_28 ;
error = F_12 ( V_2 , V_9 ) ;
if ( error )
goto V_118;
if ( V_114 ) {
struct V_133 V_133 ;
V_133 . V_134 = V_135 ;
V_133 . V_136 = V_114 ;
error = F_92 ( V_2 , & V_133 ) ;
if ( error )
goto V_118;
}
if ( V_115 )
error = F_93 ( V_2 , V_82 , V_113 ) ;
V_118:
F_6 ( V_2 , V_85 ) ;
return error ;
}
STATIC int
F_94 (
struct V_42 * V_42 ,
struct V_29 * V_29 )
{
if ( ! ( V_29 -> V_131 & V_137 ) && F_33 ( V_42 ) > V_138 )
return - V_127 ;
if ( F_28 ( F_95 ( V_42 -> V_125 ) ) )
return - V_45 ;
return 0 ;
}
STATIC int
F_96 (
struct V_42 * V_42 ,
struct V_29 * V_29 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_112 ;
int error ;
error = F_94 ( V_42 , V_29 ) ;
if ( error )
return error ;
V_112 = F_97 ( V_2 ) ;
if ( V_2 -> V_23 . V_139 > 0 )
F_98 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_112 ) ;
return 0 ;
}
STATIC int
F_99 (
struct V_42 * V_42 ,
struct V_29 * V_140 )
{
return F_100 ( F_21 ( V_42 ) ) ;
}
STATIC int
F_101 (
struct V_29 * V_29 ,
struct V_141 * V_142 )
{
struct V_42 * V_42 = F_46 ( V_29 ) ;
T_9 * V_2 = F_21 ( V_42 ) ;
T_5 V_143 ;
V_143 = ( T_5 ) F_102 ( T_2 , 32768 , V_2 -> V_23 . V_144 ) ;
return F_103 ( V_2 , V_142 , V_143 ) ;
}
STATIC bool
F_104 (
struct V_145 * V_145 ,
T_2 * V_82 ,
unsigned int type )
{
T_2 V_146 = F_105 ( V_145 ) ;
bool V_147 = false ;
struct V_148 * V_149 , * V_150 ;
V_149 = V_150 = F_106 ( V_145 ) ;
do {
if ( F_107 ( V_149 ) ||
F_108 ( V_149 ) ) {
if ( type == V_151 )
V_147 = true ;
} else {
if ( type == V_152 )
V_147 = true ;
}
if ( V_147 ) {
* V_82 = V_146 ;
break;
}
V_146 += V_149 -> V_153 ;
} while ( ( V_149 = V_149 -> V_154 ) != V_150 );
return V_147 ;
}
STATIC bool
F_109 (
struct V_42 * V_42 ,
struct V_155 * V_156 ,
unsigned int type ,
T_2 * V_82 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
struct V_157 V_158 ;
T_10 V_159 ;
T_10 V_31 ;
T_2 V_160 ;
T_2 V_161 = * V_82 ;
T_2 V_146 = V_161 ;
bool V_147 = false ;
F_110 ( & V_158 , 0 ) ;
V_159 = V_161 >> V_96 ;
V_160 = F_111 ( V_36 , V_156 -> V_162 + V_156 -> V_163 ) ;
V_31 = V_160 >> V_96 ;
do {
int V_164 ;
unsigned V_165 ;
unsigned int V_166 ;
V_164 = F_102 ( T_10 , V_31 - V_159 , V_167 ) ;
V_165 = F_112 ( & V_158 , V_42 -> V_44 , V_159 ,
V_164 ) ;
if ( V_165 == 0 ) {
if ( type == V_151 )
break;
ASSERT ( type == V_152 ) ;
if ( V_146 == V_161 || V_146 < V_160 ) {
V_147 = true ;
* V_82 = V_146 ;
}
break;
}
if ( type == V_152 && V_146 == V_161 &&
V_146 < F_105 ( V_158 . V_168 [ 0 ] ) ) {
V_147 = true ;
break;
}
for ( V_166 = 0 ; V_166 < V_165 ; V_166 ++ ) {
struct V_145 * V_145 = V_158 . V_168 [ V_166 ] ;
T_2 V_169 ;
if ( V_145 -> V_159 > V_31 ) {
if ( type == V_152 && V_146 < V_160 ) {
* V_82 = V_146 ;
V_147 = true ;
}
goto V_81;
}
F_113 ( V_145 ) ;
if ( F_114 ( V_145 -> V_59 != V_42 -> V_44 ) ) {
F_115 ( V_145 ) ;
continue;
}
if ( ! F_116 ( V_145 ) ) {
F_115 ( V_145 ) ;
continue;
}
V_147 = F_104 ( V_145 , & V_169 , type ) ;
if ( V_147 ) {
* V_82 = F_117 ( T_2 , V_161 , V_169 ) ;
F_115 ( V_145 ) ;
goto V_81;
}
V_146 = F_105 ( V_145 ) + V_170 ;
F_115 ( V_145 ) ;
}
if ( V_165 < V_164 ) {
if ( type == V_152 ) {
* V_82 = V_146 ;
V_147 = true ;
}
break;
}
V_159 = V_158 . V_168 [ V_166 - 1 ] -> V_159 + 1 ;
F_118 ( & V_158 ) ;
} while ( V_159 <= V_31 );
V_81:
F_118 ( & V_158 ) ;
return V_147 ;
}
T_2
F_119 (
struct V_42 * V_42 ,
T_2 V_30 ,
T_2 V_31 ,
int V_171 )
{
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_2 V_172 ( V_82 ) ;
T_11 V_173 ;
T_12 V_174 ;
int error ;
if ( V_30 >= V_31 ) {
error = - V_175 ;
goto V_176;
}
V_173 = F_120 ( V_36 , V_30 ) ;
V_174 = F_121 ( V_36 , V_31 ) ;
for (; ; ) {
struct V_155 V_156 [ 2 ] ;
int V_177 = 2 ;
unsigned int V_166 ;
error = F_122 ( V_2 , V_173 , V_174 - V_173 , V_156 , & V_177 ,
V_178 ) ;
if ( error )
goto V_176;
if ( V_177 == 0 ) {
error = - V_175 ;
goto V_176;
}
for ( V_166 = 0 ; V_166 < V_177 ; V_166 ++ ) {
V_82 = F_117 ( T_2 , V_30 ,
F_111 ( V_36 , V_156 [ V_166 ] . V_162 ) ) ;
if ( V_171 == V_179 &&
V_156 [ V_166 ] . V_180 == V_181 )
goto V_81;
if ( V_171 == V_182 &&
( V_156 [ V_166 ] . V_180 == V_183 ||
( V_156 [ V_166 ] . V_184 == V_185 &&
! F_123 ( V_156 [ V_166 ] . V_180 ) ) ) )
goto V_81;
if ( V_156 [ V_166 ] . V_184 == V_186 ) {
if ( F_109 ( V_42 , & V_156 [ V_166 ] ,
V_171 == V_179 ? V_152 : V_151 ,
& V_82 ) )
goto V_81;
}
}
if ( V_177 == 1 ) {
if ( V_171 == V_179 ) {
V_82 = V_31 ;
break;
}
ASSERT ( V_171 == V_182 ) ;
error = - V_175 ;
goto V_176;
}
ASSERT ( V_166 > 1 ) ;
V_173 = V_156 [ V_166 - 1 ] . V_162 + V_156 [ V_166 - 1 ] . V_163 ;
V_30 = F_111 ( V_36 , V_173 ) ;
if ( V_30 >= V_31 ) {
if ( V_171 == V_179 ) {
V_82 = V_31 ;
break;
}
ASSERT ( V_171 == V_182 ) ;
error = - V_175 ;
goto V_176;
}
}
V_81:
if ( V_171 == V_179 )
V_82 = F_102 ( T_2 , V_82 , V_31 ) ;
return V_82 ;
V_176:
return error ;
}
STATIC T_2
F_124 (
struct V_29 * V_29 ,
T_2 V_30 ,
int V_171 )
{
struct V_42 * V_42 = V_29 -> V_33 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
struct V_35 * V_36 = V_2 -> V_12 ;
T_8 V_187 ;
T_2 V_82 , V_31 ;
int error = 0 ;
if ( F_28 ( V_36 ) )
return - V_45 ;
V_187 = F_97 ( V_2 ) ;
V_31 = F_33 ( V_42 ) ;
V_82 = F_119 ( V_42 , V_30 , V_31 , V_171 ) ;
if ( V_82 < 0 ) {
error = V_82 ;
goto V_118;
}
V_82 = F_125 ( V_29 , V_82 , V_42 -> V_125 -> V_126 ) ;
V_118:
F_6 ( V_2 , V_187 ) ;
if ( error )
return error ;
return V_82 ;
}
STATIC T_2
F_126 (
struct V_29 * V_29 ,
T_2 V_82 ,
int V_171 )
{
switch ( V_171 ) {
case V_188 :
case V_189 :
case V_190 :
return F_127 ( V_29 , V_82 , V_171 ) ;
case V_179 :
case V_182 :
return F_124 ( V_29 , V_82 , V_171 ) ;
default:
return - V_68 ;
}
}
STATIC int
F_128 (
struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_42 * V_42 = F_46 ( V_192 -> V_195 ) ;
int V_65 ;
F_129 ( F_21 ( V_42 ) ) ;
F_130 ( V_42 -> V_125 ) ;
F_69 ( V_192 -> V_195 ) ;
F_4 ( F_21 ( V_42 ) , V_196 ) ;
if ( F_51 ( V_42 ) ) {
V_65 = F_131 ( V_192 , V_194 , V_197 ) ;
} else {
V_65 = F_132 ( V_192 , V_194 , & V_7 ) ;
V_65 = F_133 ( V_65 ) ;
}
F_6 ( F_21 ( V_42 ) , V_196 ) ;
F_134 ( V_42 -> V_125 ) ;
return V_65 ;
}
STATIC int
F_135 (
struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_42 * V_42 = F_46 ( V_192 -> V_195 ) ;
int V_65 ;
F_136 ( F_21 ( V_42 ) ) ;
if ( ( V_194 -> V_9 & V_198 ) && F_51 ( V_42 ) )
return F_128 ( V_192 , V_194 ) ;
F_4 ( F_21 ( V_42 ) , V_196 ) ;
if ( F_51 ( V_42 ) ) {
V_65 = F_137 ( V_192 , V_194 , V_197 ) ;
} else
V_65 = F_138 ( V_192 , V_194 ) ;
F_6 ( F_21 ( V_42 ) , V_196 ) ;
return V_65 ;
}
STATIC int
F_139 (
struct V_191 * V_192 ,
unsigned long V_199 ,
T_13 * V_200 ,
unsigned int V_9 )
{
struct V_42 * V_42 = F_46 ( V_192 -> V_195 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_65 ;
if ( ! F_51 ( V_42 ) )
return V_201 ;
F_140 ( V_2 ) ;
if ( V_9 & V_198 ) {
F_130 ( V_42 -> V_125 ) ;
F_69 ( V_192 -> V_195 ) ;
}
F_4 ( F_21 ( V_42 ) , V_196 ) ;
V_65 = F_141 ( V_192 , V_199 , V_200 , V_9 , V_197 ) ;
F_6 ( F_21 ( V_42 ) , V_196 ) ;
if ( V_9 & V_198 )
F_134 ( V_42 -> V_125 ) ;
return V_65 ;
}
static int
F_142 (
struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_42 * V_42 = F_46 ( V_192 -> V_195 ) ;
struct V_1 * V_2 = F_21 ( V_42 ) ;
int V_65 = V_202 ;
T_2 V_203 ;
F_143 ( V_2 ) ;
F_130 ( V_42 -> V_125 ) ;
F_69 ( V_192 -> V_195 ) ;
F_4 ( V_2 , V_196 ) ;
V_203 = ( F_33 ( V_42 ) + V_170 - 1 ) >> V_96 ;
if ( V_194 -> V_204 >= V_203 )
V_65 = V_205 ;
else if ( F_51 ( V_42 ) )
V_65 = F_144 ( V_192 , V_194 ) ;
F_6 ( V_2 , V_196 ) ;
F_134 ( V_42 -> V_125 ) ;
return V_65 ;
}
STATIC int
F_145 (
struct V_29 * V_140 ,
struct V_191 * V_192 )
{
F_41 ( V_140 ) ;
V_192 -> V_206 = & V_207 ;
if ( F_51 ( F_46 ( V_140 ) ) )
V_192 -> V_208 |= V_209 | V_210 ;
return 0 ;
}
