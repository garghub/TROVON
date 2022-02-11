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
T_2 V_5 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
V_8 = F_3 ( V_2 ) -> V_10 ;
do {
unsigned V_11 , V_12 ;
void * V_13 ;
V_11 = ( V_4 & ( V_14 - 1 ) ) ;
V_12 = V_14 - V_11 ;
if ( V_12 > V_5 )
V_12 = V_5 ;
if ( F_11 ( F_3 ( V_2 ) ) ) {
V_9 = F_12 ( F_3 ( V_2 ) , V_4 , V_12 ,
V_15 ) ;
if ( V_9 )
break;
} else {
V_9 = F_13 ( NULL , V_8 , V_4 , V_12 ,
V_16 ,
& V_6 , & V_13 ) ;
if ( V_9 )
break;
F_14 ( V_6 , V_11 , V_12 ) ;
V_9 = F_15 ( NULL , V_8 , V_4 , V_12 ,
V_12 , V_6 , V_13 ) ;
F_16 ( V_9 <= 0 ) ;
V_9 = 0 ;
}
V_4 += V_12 ;
V_5 -= V_12 ;
} while ( V_5 );
return V_9 ;
}
int
F_17 (
struct V_1 * V_2 ,
enum V_17 V_18 )
{
struct V_19 * V_20 ;
int error ;
error = F_18 ( V_2 -> V_21 , & F_19 ( V_2 -> V_21 ) -> V_22 ,
0 , 0 , 0 , & V_20 ) ;
if ( error )
return error ;
F_4 ( V_2 , V_23 ) ;
F_20 ( V_20 , V_2 , V_23 ) ;
if ( ! ( V_18 & V_24 ) ) {
F_3 ( V_2 ) -> V_25 &= ~ V_26 ;
if ( F_3 ( V_2 ) -> V_25 & V_27 )
F_3 ( V_2 ) -> V_25 &= ~ V_28 ;
F_21 ( V_20 , V_2 , V_29 | V_30 ) ;
}
if ( V_18 & V_31 )
V_2 -> V_32 . V_33 |= V_34 ;
if ( V_18 & V_35 )
V_2 -> V_32 . V_33 &= ~ V_34 ;
F_22 ( V_20 , V_2 , V_36 ) ;
if ( V_18 & V_37 )
F_23 ( V_20 ) ;
return F_24 ( V_20 ) ;
}
STATIC int
F_25 (
struct V_38 * V_38 ,
T_1 V_39 ,
T_1 V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_26 ( V_38 -> V_42 -> V_43 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
T_3 V_46 = 0 ;
F_27 ( V_2 ) ;
F_4 ( V_2 , V_47 ) ;
if ( F_28 ( V_2 ) )
V_46 = V_2 -> V_48 -> V_49 ;
F_6 ( V_2 , V_47 ) ;
if ( ! V_46 )
return 0 ;
return F_29 ( V_45 , V_46 , V_50 , NULL ) ;
}
STATIC int
F_30 (
struct V_38 * V_38 ,
T_1 V_39 ,
T_1 V_40 ,
int V_41 )
{
struct V_51 * V_51 = V_38 -> V_42 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
int error = 0 ;
int V_52 = 0 ;
T_3 V_46 = 0 ;
F_31 ( V_2 ) ;
error = F_32 ( V_51 -> V_10 , V_39 , V_40 ) ;
if ( error )
return error ;
if ( F_33 ( V_45 ) )
return - V_53 ;
F_34 ( V_2 , V_54 ) ;
if ( V_45 -> V_55 & V_56 ) {
if ( F_35 ( V_2 ) )
F_36 ( V_45 -> V_57 ) ;
else if ( V_45 -> V_58 != V_45 -> V_59 )
F_36 ( V_45 -> V_59 ) ;
}
F_4 ( V_2 , V_47 ) ;
if ( F_28 ( V_2 ) ) {
if ( ! V_41 ||
( V_2 -> V_48 -> V_60 & ~ V_61 ) )
V_46 = V_2 -> V_48 -> V_49 ;
}
if ( V_46 ) {
error = F_29 ( V_45 , V_46 , V_50 , & V_52 ) ;
V_2 -> V_48 -> V_60 = 0 ;
}
F_6 ( V_2 , V_47 ) ;
if ( ( V_45 -> V_55 & V_56 ) &&
V_45 -> V_58 == V_45 -> V_59 &&
! F_35 ( V_2 ) &&
! V_52 )
F_36 ( V_45 -> V_59 ) ;
return error ;
}
STATIC T_4
F_37 (
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_38 * V_38 = V_63 -> V_66 ;
struct V_51 * V_51 = V_38 -> V_42 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
T_2 V_67 = F_38 ( V_65 ) ;
T_4 V_68 = 0 ;
int V_69 = 0 ;
T_5 V_70 ;
T_1 V_4 = V_63 -> V_71 ;
F_39 ( V_45 , V_72 ) ;
if ( F_40 ( V_63 -> V_73 & V_74 ) )
V_69 |= V_75 ;
if ( V_38 -> V_76 & V_77 )
V_69 |= V_78 ;
if ( ( V_69 & V_75 ) && ! F_11 ( V_51 ) ) {
T_6 * V_79 =
F_35 ( V_2 ) ?
V_45 -> V_57 : V_45 -> V_59 ;
if ( ( V_4 | V_67 ) & V_79 -> V_80 ) {
if ( V_4 == F_41 ( V_51 ) )
return 0 ;
return - V_81 ;
}
}
V_70 = V_45 -> V_82 -> V_83 - V_4 ;
if ( V_70 <= 0 || V_67 == 0 )
return 0 ;
if ( V_70 < V_67 )
V_67 = V_70 ;
if ( F_33 ( V_45 ) )
return - V_53 ;
F_1 ( V_2 , V_84 ) ;
if ( ( V_69 & V_75 ) && V_51 -> V_10 -> V_85 ) {
F_5 ( V_2 , V_84 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_51 -> V_10 -> V_85 ) {
V_68 = F_42 ( F_3 ( V_2 ) -> V_10 ) ;
if ( V_68 ) {
F_5 ( V_2 , V_3 ) ;
return V_68 ;
}
V_68 = F_43 ( F_3 ( V_2 ) -> V_10 ) ;
F_44 ( V_68 ) ;
V_68 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
F_45 ( V_2 , V_67 , V_4 , V_69 ) ;
V_68 = F_46 ( V_63 , V_65 ) ;
if ( V_68 > 0 )
F_47 ( V_45 , V_86 , V_68 ) ;
F_5 ( V_2 , V_84 ) ;
return V_68 ;
}
STATIC T_4
F_48 (
struct V_38 * V_87 ,
T_1 * V_88 ,
struct V_89 * V_90 ,
T_2 V_5 ,
unsigned int V_18 )
{
struct V_1 * V_2 = F_26 ( V_87 -> V_42 -> V_43 ) ;
int V_69 = 0 ;
T_4 V_68 ;
F_39 ( V_2 -> V_21 , V_72 ) ;
if ( V_87 -> V_76 & V_77 )
V_69 |= V_78 ;
if ( F_33 ( V_2 -> V_21 ) )
return - V_53 ;
F_49 ( V_2 , V_5 , * V_88 , V_69 ) ;
if ( F_11 ( F_3 ( V_2 ) ) ) {
V_68 = F_50 ( V_87 , V_88 , V_90 , V_5 ,
V_18 ) ;
goto V_91;
}
F_1 ( V_2 , V_84 ) ;
V_68 = F_51 ( V_87 , V_88 , V_90 , V_5 , V_18 ) ;
F_5 ( V_2 , V_84 ) ;
V_91:
if ( V_68 > 0 )
F_47 ( V_2 -> V_21 , V_86 , V_68 ) ;
return V_68 ;
}
STATIC int
F_52 (
struct V_1 * V_2 ,
T_5 V_11 ,
T_5 V_92 ,
bool * V_93 )
{
struct V_44 * V_45 = V_2 -> V_21 ;
T_7 V_94 = F_53 ( V_45 , V_92 ) ;
int V_95 = F_54 ( V_45 , V_92 ) ;
int V_96 ;
int V_97 = 1 ;
int error = 0 ;
struct V_98 V_99 ;
F_4 ( V_2 , V_23 ) ;
error = F_55 ( V_2 , V_94 , 1 , & V_99 , & V_97 , 0 ) ;
F_6 ( V_2 , V_23 ) ;
if ( error )
return error ;
ASSERT ( V_97 > 0 ) ;
if ( V_99 . V_100 == V_101 )
return 0 ;
V_96 = V_45 -> V_102 . V_103 - V_95 ;
if ( V_92 + V_96 > V_11 )
V_96 = V_11 - V_92 ;
* V_93 = true ;
return F_10 ( V_2 , V_92 , V_96 ) ;
}
int
F_56 (
struct V_1 * V_2 ,
T_8 V_11 ,
T_5 V_92 ,
bool * V_93 )
{
struct V_44 * V_45 = V_2 -> V_21 ;
T_7 V_104 ;
T_7 V_105 ;
T_7 V_106 ;
T_7 V_94 ;
T_7 V_107 ;
T_5 V_96 ;
int V_97 ;
int error = 0 ;
struct V_98 V_99 ;
ASSERT ( F_57 ( V_2 , V_3 ) ) ;
ASSERT ( V_11 > V_92 ) ;
F_58 ( V_2 , V_92 , V_11 - V_92 ) ;
if ( F_54 ( V_45 , V_92 ) != 0 ) {
error = F_52 ( V_2 , V_11 , V_92 , V_93 ) ;
if ( error )
return error ;
}
V_94 = V_92 ? F_53 ( V_45 , V_92 - 1 ) : ( T_7 ) - 1 ;
V_104 = F_59 ( V_45 , ( V_108 ) V_92 ) ;
V_105 = F_53 ( V_45 , V_11 - 1 ) ;
ASSERT ( ( V_109 ) V_94 < ( V_109 ) V_104 ) ;
if ( V_94 == V_105 ) {
return 0 ;
}
ASSERT ( V_104 <= V_105 ) ;
while ( V_104 <= V_105 ) {
V_97 = 1 ;
V_106 = V_105 - V_104 + 1 ;
F_4 ( V_2 , V_23 ) ;
error = F_55 ( V_2 , V_104 , V_106 ,
& V_99 , & V_97 , 0 ) ;
F_6 ( V_2 , V_23 ) ;
if ( error )
return error ;
ASSERT ( V_97 > 0 ) ;
if ( V_99 . V_110 == V_111 ||
V_99 . V_100 == V_101 ) {
V_104 = V_99 . V_112 + V_99 . V_113 ;
ASSERT ( V_104 <= ( V_105 + 1 ) ) ;
continue;
}
V_107 = F_60 ( V_45 , V_104 ) ;
V_96 = F_60 ( V_45 , V_99 . V_113 ) ;
if ( ( V_107 + V_96 ) > V_11 )
V_96 = V_11 - V_107 ;
error = F_10 ( V_2 , V_107 , V_96 ) ;
if ( error )
return error ;
* V_93 = true ;
V_104 = V_99 . V_112 + V_99 . V_113 ;
ASSERT ( V_104 <= ( V_105 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_61 (
struct V_62 * V_63 ,
struct V_64 * V_114 ,
int * V_115 )
{
struct V_38 * V_38 = V_63 -> V_66 ;
struct V_51 * V_51 = V_38 -> V_42 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
T_4 error = 0 ;
T_2 V_5 = F_38 ( V_114 ) ;
bool V_116 = false ;
V_117:
error = F_62 ( V_63 , V_114 ) ;
if ( error <= 0 )
return error ;
error = F_63 ( V_51 , V_115 , true ) ;
if ( error )
return error ;
if ( * V_115 == V_84 && ! F_64 ( V_51 ) ) {
F_5 ( V_2 , * V_115 ) ;
* V_115 = V_3 ;
F_1 ( V_2 , * V_115 ) ;
goto V_117;
}
F_65 ( & V_2 -> V_118 ) ;
if ( V_63 -> V_71 > F_41 ( V_51 ) ) {
bool V_119 = false ;
F_66 ( & V_2 -> V_118 ) ;
if ( ! V_116 ) {
if ( * V_115 == V_84 ) {
F_5 ( V_2 , * V_115 ) ;
* V_115 = V_3 ;
F_1 ( V_2 , * V_115 ) ;
F_67 ( V_114 , V_5 ) ;
}
F_68 ( V_51 ) ;
V_116 = true ;
goto V_117;
}
error = F_56 ( V_2 , V_63 -> V_71 , F_41 ( V_51 ) , & V_119 ) ;
if ( error )
return error ;
} else
F_66 ( & V_2 -> V_118 ) ;
if ( F_69 ( ! ( V_38 -> V_76 & V_77 ) ) ) {
error = F_70 ( V_38 ) ;
if ( error )
return error ;
}
if ( ! F_64 ( V_51 ) )
return F_71 ( V_38 ) ;
return 0 ;
}
STATIC T_4
F_72 (
struct V_62 * V_63 ,
struct V_64 * V_114 )
{
struct V_38 * V_38 = V_63 -> V_66 ;
struct V_7 * V_8 = V_38 -> V_42 ;
struct V_51 * V_51 = V_8 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
T_4 V_68 = 0 ;
int V_120 = 0 ;
int V_115 ;
T_2 V_5 = F_38 ( V_114 ) ;
T_1 V_40 ;
struct V_64 V_121 ;
struct V_122 * V_79 = F_35 ( V_2 ) ?
V_45 -> V_57 : V_45 -> V_59 ;
if ( ! F_11 ( V_51 ) &&
( ( V_63 -> V_71 | V_5 ) & V_79 -> V_80 ) )
return - V_81 ;
if ( ( V_63 -> V_71 & V_45 -> V_123 ) ||
( ( V_63 -> V_71 + V_5 ) & V_45 -> V_123 ) )
V_120 = 1 ;
if ( V_120 || V_8 -> V_85 )
V_115 = V_3 ;
else
V_115 = V_84 ;
F_1 ( V_2 , V_115 ) ;
if ( V_8 -> V_85 && V_115 == V_84 ) {
F_5 ( V_2 , V_115 ) ;
V_115 = V_3 ;
F_1 ( V_2 , V_115 ) ;
}
V_68 = F_61 ( V_63 , V_114 , & V_115 ) ;
if ( V_68 )
goto V_91;
V_5 = F_38 ( V_114 ) ;
V_40 = V_63 -> V_71 + V_5 - 1 ;
if ( V_8 -> V_85 ) {
V_68 = F_42 ( F_3 ( V_2 ) -> V_10 ) ;
if ( V_68 )
goto V_91;
V_68 = F_43 ( F_3 ( V_2 ) -> V_10 ) ;
F_44 ( V_68 ) ;
V_68 = 0 ;
}
if ( V_120 )
F_68 ( V_51 ) ;
else if ( V_115 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_115 = V_84 ;
}
F_73 ( V_2 , V_5 , V_63 -> V_71 , 0 ) ;
V_121 = * V_114 ;
V_68 = V_8 -> V_124 -> V_125 ( V_63 , & V_121 ) ;
if ( V_8 -> V_85 ) {
F_74 ( V_8 ,
V_63 -> V_71 >> V_126 ,
V_40 >> V_126 ) ;
}
if ( V_68 > 0 ) {
V_63 -> V_71 += V_68 ;
F_75 ( V_114 , V_68 ) ;
}
V_91:
F_5 ( V_2 , V_115 ) ;
ASSERT ( V_68 < 0 || V_68 == V_5 || F_11 ( F_3 ( V_2 ) ) ) ;
return V_68 ;
}
STATIC T_4
F_76 (
struct V_62 * V_63 ,
struct V_64 * V_114 )
{
struct V_38 * V_38 = V_63 -> V_66 ;
struct V_7 * V_8 = V_38 -> V_42 ;
struct V_51 * V_51 = V_8 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
T_4 V_68 ;
int V_127 = 0 ;
int V_115 = V_3 ;
F_1 ( V_2 , V_115 ) ;
V_68 = F_61 ( V_63 , V_114 , & V_115 ) ;
if ( V_68 )
goto V_91;
V_128 -> V_129 = F_77 ( V_51 ) ;
V_130:
F_78 ( V_2 , F_38 ( V_114 ) ,
V_63 -> V_71 , 0 ) ;
V_68 = F_79 ( V_38 , V_114 , V_63 -> V_71 ) ;
if ( F_69 ( V_68 >= 0 ) )
V_63 -> V_71 += V_68 ;
if ( V_68 == - V_131 && ! V_127 ) {
V_127 = F_80 ( V_2 ) ;
if ( V_127 )
goto V_130;
} else if ( V_68 == - V_132 && ! V_127 ) {
struct V_133 V_134 = { 0 } ;
V_127 = 1 ;
F_81 ( V_2 -> V_21 ) ;
V_134 . V_135 = V_2 -> V_136 ;
V_134 . V_137 = V_138 ;
F_82 ( V_2 -> V_21 , & V_134 ) ;
goto V_130;
}
V_128 -> V_129 = NULL ;
V_91:
F_5 ( V_2 , V_115 ) ;
return V_68 ;
}
STATIC T_4
F_83 (
struct V_62 * V_63 ,
struct V_64 * V_114 )
{
struct V_38 * V_38 = V_63 -> V_66 ;
struct V_7 * V_8 = V_38 -> V_42 ;
struct V_51 * V_51 = V_8 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
T_4 V_68 ;
T_2 V_139 = F_38 ( V_114 ) ;
F_39 ( V_2 -> V_21 , V_140 ) ;
if ( V_139 == 0 )
return 0 ;
if ( F_33 ( V_2 -> V_21 ) )
return - V_53 ;
if ( ( V_63 -> V_73 & V_74 ) || F_11 ( V_51 ) )
V_68 = F_72 ( V_63 , V_114 ) ;
else
V_68 = F_76 ( V_63 , V_114 ) ;
if ( V_68 > 0 ) {
F_47 ( V_2 -> V_21 , V_141 , V_68 ) ;
V_68 = F_84 ( V_63 , V_68 ) ;
}
return V_68 ;
}
STATIC long
F_85 (
struct V_38 * V_38 ,
int V_142 ,
T_1 V_11 ,
T_1 V_143 )
{
struct V_51 * V_51 = F_86 ( V_38 ) ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
long error ;
enum V_17 V_18 = 0 ;
T_9 V_115 = V_3 ;
T_1 V_144 = 0 ;
bool V_145 = 0 ;
if ( ! F_87 ( V_51 -> V_25 ) )
return - V_81 ;
if ( V_142 & ~ V_146 )
return - V_147 ;
F_4 ( V_2 , V_115 ) ;
error = F_63 ( V_51 , & V_115 , false ) ;
if ( error )
goto V_148;
F_4 ( V_2 , V_149 ) ;
V_115 |= V_149 ;
if ( V_142 & V_150 ) {
error = F_88 ( V_2 , V_11 , V_143 ) ;
if ( error )
goto V_148;
} else if ( V_142 & V_151 ) {
unsigned V_152 = ( 1 << V_51 -> V_153 ) - 1 ;
if ( V_11 & V_152 || V_143 & V_152 ) {
error = - V_81 ;
goto V_148;
}
if ( V_11 + V_143 >= F_41 ( V_51 ) ) {
error = - V_81 ;
goto V_148;
}
V_144 = F_41 ( V_51 ) - V_143 ;
error = F_89 ( V_2 , V_11 , V_143 ) ;
if ( error )
goto V_148;
} else if ( V_142 & V_154 ) {
unsigned V_152 = ( 1 << V_51 -> V_153 ) - 1 ;
V_144 = F_41 ( V_51 ) + V_143 ;
if ( V_11 & V_152 || V_143 & V_152 ) {
error = - V_81 ;
goto V_148;
}
if ( V_144 > V_51 -> V_155 -> V_83 ) {
error = - V_156 ;
goto V_148;
}
if ( V_11 >= F_41 ( V_51 ) ) {
error = - V_81 ;
goto V_148;
}
V_145 = 1 ;
} else {
V_18 |= V_31 ;
if ( ! ( V_142 & V_157 ) &&
V_11 + V_143 > F_41 ( V_51 ) ) {
V_144 = V_11 + V_143 ;
error = F_90 ( V_51 , V_144 ) ;
if ( error )
goto V_148;
}
if ( V_142 & V_158 )
error = F_91 ( V_2 , V_11 , V_143 ) ;
else
error = F_92 ( V_2 , V_11 , V_143 ,
V_159 ) ;
if ( error )
goto V_148;
}
if ( V_38 -> V_160 & V_161 )
V_18 |= V_37 ;
error = F_17 ( V_2 , V_18 ) ;
if ( error )
goto V_148;
if ( V_144 ) {
struct V_162 V_162 ;
V_162 . V_163 = V_164 ;
V_162 . V_165 = V_144 ;
error = F_93 ( V_2 , & V_162 ) ;
if ( error )
goto V_148;
}
if ( V_145 )
error = F_94 ( V_2 , V_11 , V_143 ) ;
V_148:
F_6 ( V_2 , V_115 ) ;
return error ;
}
STATIC int
F_95 (
struct V_51 * V_51 ,
struct V_38 * V_38 )
{
if ( ! ( V_38 -> V_160 & V_166 ) && F_41 ( V_51 ) > V_167 )
return - V_156 ;
if ( F_33 ( F_96 ( V_51 -> V_155 ) ) )
return - V_53 ;
return 0 ;
}
STATIC int
F_97 (
struct V_51 * V_51 ,
struct V_38 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_51 ) ;
int V_142 ;
int error ;
error = F_95 ( V_51 , V_38 ) ;
if ( error )
return error ;
V_142 = F_98 ( V_2 ) ;
if ( V_2 -> V_32 . V_168 > 0 )
F_99 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_142 ) ;
return 0 ;
}
STATIC int
F_100 (
struct V_51 * V_51 ,
struct V_38 * V_169 )
{
return F_101 ( F_26 ( V_51 ) ) ;
}
STATIC int
F_102 (
struct V_38 * V_38 ,
struct V_170 * V_171 )
{
struct V_51 * V_51 = F_86 ( V_38 ) ;
T_10 * V_2 = F_26 ( V_51 ) ;
T_2 V_172 ;
V_172 = ( T_2 ) F_103 ( T_1 , 32768 , V_2 -> V_32 . V_173 ) ;
return F_104 ( V_2 , V_171 , V_172 ) ;
}
STATIC bool
F_105 (
struct V_6 * V_6 ,
T_1 * V_11 ,
unsigned int type )
{
T_1 V_174 = F_106 ( V_6 ) ;
bool V_175 = false ;
struct V_176 * V_177 , * V_178 ;
V_177 = V_178 = F_107 ( V_6 ) ;
do {
if ( F_108 ( V_177 ) ||
F_109 ( V_177 ) ) {
if ( type == V_179 )
V_175 = true ;
} else {
if ( type == V_180 )
V_175 = true ;
}
if ( V_175 ) {
* V_11 = V_174 ;
break;
}
V_174 += V_177 -> V_181 ;
} while ( ( V_177 = V_177 -> V_182 ) != V_178 );
return V_175 ;
}
STATIC bool
F_110 (
struct V_51 * V_51 ,
struct V_98 * V_183 ,
unsigned int type ,
T_1 * V_11 )
{
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
struct V_184 V_185 ;
T_11 V_186 ;
T_11 V_40 ;
T_1 V_187 ;
T_1 V_188 = * V_11 ;
T_1 V_174 = V_188 ;
bool V_175 = false ;
F_111 ( & V_185 , 0 ) ;
V_186 = V_188 >> V_126 ;
V_187 = F_60 ( V_45 , V_183 -> V_112 + V_183 -> V_113 ) ;
V_40 = V_187 >> V_126 ;
do {
int V_189 ;
unsigned V_190 ;
unsigned int V_191 ;
V_189 = F_103 ( T_11 , V_40 - V_186 , V_192 ) ;
V_190 = F_112 ( & V_185 , V_51 -> V_10 , V_186 ,
V_189 ) ;
if ( V_190 == 0 ) {
if ( type == V_179 )
break;
ASSERT ( type == V_180 ) ;
if ( V_174 == V_188 || V_174 < V_187 ) {
V_175 = true ;
* V_11 = V_174 ;
}
break;
}
if ( type == V_180 && V_174 == V_188 &&
V_174 < F_106 ( V_185 . V_193 [ 0 ] ) ) {
V_175 = true ;
break;
}
for ( V_191 = 0 ; V_191 < V_190 ; V_191 ++ ) {
struct V_6 * V_6 = V_185 . V_193 [ V_191 ] ;
T_1 V_194 ;
if ( V_6 -> V_186 > V_40 ) {
if ( type == V_180 && V_174 < V_187 ) {
* V_11 = V_174 ;
V_175 = true ;
}
goto V_91;
}
F_113 ( V_6 ) ;
if ( F_40 ( V_6 -> V_8 != V_51 -> V_10 ) ) {
F_114 ( V_6 ) ;
continue;
}
if ( ! F_115 ( V_6 ) ) {
F_114 ( V_6 ) ;
continue;
}
V_175 = F_105 ( V_6 , & V_194 , type ) ;
if ( V_175 ) {
* V_11 = F_116 ( T_1 , V_188 , V_194 ) ;
F_114 ( V_6 ) ;
goto V_91;
}
V_174 = F_106 ( V_6 ) + V_14 ;
F_114 ( V_6 ) ;
}
if ( V_190 < V_189 ) {
if ( type == V_180 ) {
* V_11 = V_174 ;
V_175 = true ;
}
break;
}
V_186 = V_185 . V_193 [ V_191 - 1 ] -> V_186 + 1 ;
F_117 ( & V_185 ) ;
} while ( V_186 <= V_40 );
V_91:
F_117 ( & V_185 ) ;
return V_175 ;
}
T_1
F_118 (
struct V_51 * V_51 ,
T_1 V_39 ,
T_1 V_40 ,
int V_195 )
{
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
T_1 V_196 ( V_11 ) ;
T_7 V_197 ;
T_12 V_198 ;
int error ;
if ( V_39 >= V_40 ) {
error = - V_199 ;
goto V_200;
}
V_197 = F_53 ( V_45 , V_39 ) ;
V_198 = F_59 ( V_45 , V_40 ) ;
for (; ; ) {
struct V_98 V_183 [ 2 ] ;
int V_201 = 2 ;
unsigned int V_191 ;
error = F_55 ( V_2 , V_197 , V_198 - V_197 , V_183 , & V_201 ,
V_202 ) ;
if ( error )
goto V_200;
if ( V_201 == 0 ) {
error = - V_199 ;
goto V_200;
}
for ( V_191 = 0 ; V_191 < V_201 ; V_191 ++ ) {
V_11 = F_116 ( T_1 , V_39 ,
F_60 ( V_45 , V_183 [ V_191 ] . V_112 ) ) ;
if ( V_195 == V_203 &&
V_183 [ V_191 ] . V_100 == V_101 )
goto V_91;
if ( V_195 == V_204 &&
( V_183 [ V_191 ] . V_100 == V_205 ||
( V_183 [ V_191 ] . V_110 == V_206 &&
! F_119 ( V_183 [ V_191 ] . V_100 ) ) ) )
goto V_91;
if ( V_183 [ V_191 ] . V_110 == V_111 ) {
if ( F_110 ( V_51 , & V_183 [ V_191 ] ,
V_195 == V_203 ? V_180 : V_179 ,
& V_11 ) )
goto V_91;
}
}
if ( V_201 == 1 ) {
if ( V_195 == V_203 ) {
V_11 = V_40 ;
break;
}
ASSERT ( V_195 == V_204 ) ;
error = - V_199 ;
goto V_200;
}
ASSERT ( V_191 > 1 ) ;
V_197 = V_183 [ V_191 - 1 ] . V_112 + V_183 [ V_191 - 1 ] . V_113 ;
V_39 = F_60 ( V_45 , V_197 ) ;
if ( V_39 >= V_40 ) {
if ( V_195 == V_203 ) {
V_11 = V_40 ;
break;
}
ASSERT ( V_195 == V_204 ) ;
error = - V_199 ;
goto V_200;
}
}
V_91:
if ( V_195 == V_203 )
V_11 = F_103 ( T_1 , V_11 , V_40 ) ;
return V_11 ;
V_200:
return error ;
}
STATIC T_1
F_120 (
struct V_38 * V_38 ,
T_1 V_39 ,
int V_195 )
{
struct V_51 * V_51 = V_38 -> V_42 -> V_43 ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
struct V_44 * V_45 = V_2 -> V_21 ;
T_9 V_207 ;
T_1 V_11 , V_40 ;
int error = 0 ;
if ( F_33 ( V_45 ) )
return - V_53 ;
V_207 = F_98 ( V_2 ) ;
V_40 = F_41 ( V_51 ) ;
V_11 = F_118 ( V_51 , V_39 , V_40 , V_195 ) ;
if ( V_11 < 0 ) {
error = V_11 ;
goto V_148;
}
V_11 = F_121 ( V_38 , V_11 , V_51 -> V_155 -> V_83 ) ;
V_148:
F_6 ( V_2 , V_207 ) ;
if ( error )
return error ;
return V_11 ;
}
STATIC T_1
F_122 (
struct V_38 * V_38 ,
T_1 V_11 ,
int V_195 )
{
switch ( V_195 ) {
case V_208 :
case V_209 :
case V_210 :
return F_123 ( V_38 , V_11 , V_195 ) ;
case V_203 :
case V_204 :
return F_120 ( V_38 , V_11 , V_195 ) ;
default:
return - V_81 ;
}
}
STATIC int
F_124 (
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_51 * V_51 = F_86 ( V_212 -> V_215 ) ;
int V_68 ;
F_125 ( F_26 ( V_51 ) ) ;
F_126 ( V_51 -> V_155 ) ;
F_70 ( V_212 -> V_215 ) ;
F_4 ( F_26 ( V_51 ) , V_216 ) ;
if ( F_11 ( V_51 ) ) {
V_68 = F_127 ( V_212 , V_214 , V_217 ) ;
} else {
V_68 = F_128 ( V_212 , V_214 , V_218 ) ;
V_68 = F_129 ( V_68 ) ;
}
F_6 ( F_26 ( V_51 ) , V_216 ) ;
F_130 ( V_51 -> V_155 ) ;
return V_68 ;
}
STATIC int
F_131 (
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_51 * V_51 = F_86 ( V_212 -> V_215 ) ;
int V_68 ;
F_132 ( F_26 ( V_51 ) ) ;
if ( ( V_214 -> V_18 & V_219 ) && F_11 ( V_51 ) )
return F_124 ( V_212 , V_214 ) ;
F_4 ( F_26 ( V_51 ) , V_216 ) ;
if ( F_11 ( V_51 ) ) {
V_68 = F_133 ( V_212 , V_214 , V_217 ) ;
} else
V_68 = F_134 ( V_212 , V_214 ) ;
F_6 ( F_26 ( V_51 ) , V_216 ) ;
return V_68 ;
}
STATIC int
F_135 (
struct V_211 * V_212 ,
unsigned long V_220 ,
T_13 * V_221 ,
unsigned int V_18 )
{
struct V_51 * V_51 = F_86 ( V_212 -> V_215 ) ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
int V_68 ;
if ( ! F_11 ( V_51 ) )
return V_222 ;
F_136 ( V_2 ) ;
if ( V_18 & V_219 ) {
F_126 ( V_51 -> V_155 ) ;
F_70 ( V_212 -> V_215 ) ;
}
F_4 ( F_26 ( V_51 ) , V_216 ) ;
V_68 = F_137 ( V_212 , V_220 , V_221 , V_18 , V_217 ) ;
F_6 ( F_26 ( V_51 ) , V_216 ) ;
if ( V_18 & V_219 )
F_130 ( V_51 -> V_155 ) ;
return V_68 ;
}
static int
F_138 (
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_51 * V_51 = F_86 ( V_212 -> V_215 ) ;
struct V_1 * V_2 = F_26 ( V_51 ) ;
int V_68 = V_223 ;
T_1 V_67 ;
F_139 ( V_2 ) ;
F_126 ( V_51 -> V_155 ) ;
F_70 ( V_212 -> V_215 ) ;
F_4 ( V_2 , V_216 ) ;
V_67 = ( F_41 ( V_51 ) + V_14 - 1 ) >> V_126 ;
if ( V_214 -> V_224 >= V_67 )
V_68 = V_225 ;
else if ( F_11 ( V_51 ) )
V_68 = F_140 ( V_212 , V_214 ) ;
F_6 ( V_2 , V_216 ) ;
F_130 ( V_51 -> V_155 ) ;
return V_68 ;
}
STATIC int
F_141 (
struct V_38 * V_169 ,
struct V_211 * V_212 )
{
F_142 ( V_169 ) ;
V_212 -> V_226 = & V_227 ;
if ( F_11 ( F_86 ( V_169 ) ) )
V_212 -> V_228 |= V_229 | V_230 ;
return 0 ;
}
