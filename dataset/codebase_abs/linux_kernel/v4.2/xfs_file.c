static inline void
F_1 (
struct V_1 * V_2 ,
int type )
{
if ( type & V_3 )
F_2 ( & F_3 ( V_2 ) -> V_4 ) ;
F_4 ( V_2 , type ) ;
}
static inline void
F_5 (
struct V_1 * V_2 ,
int type )
{
F_6 ( V_2 , type ) ;
if ( type & V_3 )
F_7 ( & F_3 ( V_2 ) -> V_4 ) ;
}
static inline void
F_8 (
struct V_1 * V_2 ,
int type )
{
F_9 ( V_2 , type ) ;
if ( type & V_3 )
F_7 ( & F_3 ( V_2 ) -> V_4 ) ;
}
int
F_10 (
struct V_1 * V_2 ,
T_1 V_5 ,
T_2 V_6 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
V_9 = F_3 ( V_2 ) -> V_11 ;
do {
unsigned V_12 , V_13 ;
void * V_14 ;
V_12 = ( V_5 & ( V_15 - 1 ) ) ;
V_13 = V_15 - V_12 ;
if ( V_13 > V_6 )
V_13 = V_6 ;
if ( F_11 ( F_3 ( V_2 ) ) ) {
V_10 = F_12 ( F_3 ( V_2 ) , V_5 , V_13 ,
V_16 ) ;
if ( V_10 )
break;
} else {
V_10 = F_13 ( NULL , V_9 , V_5 , V_13 ,
V_17 ,
& V_7 , & V_14 ) ;
if ( V_10 )
break;
F_14 ( V_7 , V_12 , V_13 ) ;
V_10 = F_15 ( NULL , V_9 , V_5 , V_13 ,
V_13 , V_7 , V_14 ) ;
F_16 ( V_10 <= 0 ) ;
V_10 = 0 ;
}
V_5 += V_13 ;
V_6 -= V_13 ;
} while ( V_6 );
return V_10 ;
}
int
F_17 (
struct V_1 * V_2 ,
enum V_18 V_19 )
{
struct V_20 * V_21 ;
int error ;
V_21 = F_18 ( V_2 -> V_22 , V_23 ) ;
error = F_19 ( V_21 , & F_20 ( V_2 -> V_22 ) -> V_24 , 0 , 0 ) ;
if ( error ) {
F_21 ( V_21 ) ;
return error ;
}
F_4 ( V_2 , V_25 ) ;
F_22 ( V_21 , V_2 , V_25 ) ;
if ( ! ( V_19 & V_26 ) ) {
V_2 -> V_27 . V_28 &= ~ V_29 ;
if ( V_2 -> V_27 . V_28 & V_30 )
V_2 -> V_27 . V_28 &= ~ V_31 ;
F_23 ( V_21 , V_2 , V_32 | V_33 ) ;
}
if ( V_19 & V_34 )
V_2 -> V_27 . V_35 |= V_36 ;
if ( V_19 & V_37 )
V_2 -> V_27 . V_35 &= ~ V_36 ;
F_24 ( V_21 , V_2 , V_38 ) ;
if ( V_19 & V_39 )
F_25 ( V_21 ) ;
return F_26 ( V_21 ) ;
}
STATIC int
F_27 (
struct V_40 * V_40 ,
T_1 V_41 ,
T_1 V_42 ,
int V_43 )
{
struct V_1 * V_2 = F_28 ( V_40 -> V_44 -> V_45 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
T_3 V_48 = 0 ;
F_29 ( V_2 ) ;
F_4 ( V_2 , V_49 ) ;
if ( F_30 ( V_2 ) )
V_48 = V_2 -> V_50 -> V_51 ;
F_6 ( V_2 , V_49 ) ;
if ( ! V_48 )
return 0 ;
return F_31 ( V_47 , V_48 , V_52 , NULL ) ;
}
STATIC int
F_32 (
struct V_40 * V_40 ,
T_1 V_41 ,
T_1 V_42 ,
int V_43 )
{
struct V_53 * V_53 = V_40 -> V_44 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
int error = 0 ;
int V_54 = 0 ;
T_3 V_48 = 0 ;
F_33 ( V_2 ) ;
error = F_34 ( V_53 -> V_11 , V_41 , V_42 ) ;
if ( error )
return error ;
if ( F_35 ( V_47 ) )
return - V_55 ;
F_36 ( V_2 , V_56 ) ;
if ( V_47 -> V_57 & V_58 ) {
if ( F_37 ( V_2 ) )
F_38 ( V_47 -> V_59 ) ;
else if ( V_47 -> V_60 != V_47 -> V_61 )
F_38 ( V_47 -> V_61 ) ;
}
F_4 ( V_2 , V_49 ) ;
if ( F_30 ( V_2 ) ) {
if ( ! V_43 ||
( V_2 -> V_50 -> V_62 & ~ V_63 ) )
V_48 = V_2 -> V_50 -> V_51 ;
}
F_6 ( V_2 , V_49 ) ;
if ( V_48 )
error = F_31 ( V_47 , V_48 , V_52 , & V_54 ) ;
if ( ( V_47 -> V_57 & V_58 ) &&
V_47 -> V_60 == V_47 -> V_61 &&
! F_37 ( V_2 ) &&
! V_54 )
F_38 ( V_47 -> V_61 ) ;
return error ;
}
STATIC T_4
F_39 (
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_40 * V_40 = V_65 -> V_68 ;
struct V_53 * V_53 = V_40 -> V_44 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
T_2 V_69 = F_40 ( V_67 ) ;
T_4 V_70 = 0 ;
int V_71 = 0 ;
T_5 V_72 ;
T_1 V_5 = V_65 -> V_73 ;
F_41 ( V_74 ) ;
if ( F_42 ( V_65 -> V_75 & V_76 ) )
V_71 |= V_77 ;
if ( V_40 -> V_78 & V_79 )
V_71 |= V_80 ;
if ( ( V_71 & V_77 ) && ! F_11 ( V_53 ) ) {
T_6 * V_81 =
F_37 ( V_2 ) ?
V_47 -> V_59 : V_47 -> V_61 ;
if ( ( V_5 | V_69 ) & V_81 -> V_82 ) {
if ( V_5 == F_43 ( V_53 ) )
return 0 ;
return - V_83 ;
}
}
V_72 = V_47 -> V_84 -> V_85 - V_5 ;
if ( V_72 <= 0 || V_69 == 0 )
return 0 ;
if ( V_72 < V_69 )
V_69 = V_72 ;
if ( F_35 ( V_47 ) )
return - V_55 ;
F_1 ( V_2 , V_86 ) ;
if ( ( V_71 & V_77 ) && V_53 -> V_11 -> V_87 ) {
F_5 ( V_2 , V_86 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_53 -> V_11 -> V_87 ) {
V_70 = F_34 (
F_3 ( V_2 ) -> V_11 ,
V_5 , V_5 + V_69 - 1 ) ;
if ( V_70 ) {
F_5 ( V_2 , V_3 ) ;
return V_70 ;
}
V_70 = F_44 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_88 ,
( V_5 + V_69 - 1 ) >> V_88 ) ;
F_45 ( V_70 ) ;
V_70 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
F_46 ( V_2 , V_69 , V_5 , V_71 ) ;
V_70 = F_47 ( V_65 , V_67 ) ;
if ( V_70 > 0 )
F_48 ( V_89 , V_70 ) ;
F_5 ( V_2 , V_86 ) ;
return V_70 ;
}
STATIC T_4
F_49 (
struct V_40 * V_90 ,
T_1 * V_91 ,
struct V_92 * V_93 ,
T_2 V_6 ,
unsigned int V_19 )
{
struct V_1 * V_2 = F_28 ( V_90 -> V_44 -> V_45 ) ;
int V_71 = 0 ;
T_4 V_70 ;
F_41 ( V_74 ) ;
if ( V_90 -> V_78 & V_79 )
V_71 |= V_80 ;
if ( F_35 ( V_2 -> V_22 ) )
return - V_55 ;
F_1 ( V_2 , V_86 ) ;
F_50 ( V_2 , V_6 , * V_91 , V_71 ) ;
if ( F_11 ( F_3 ( V_2 ) ) )
V_70 = F_51 ( V_90 , V_91 , V_93 , V_6 , V_19 ) ;
else
V_70 = F_52 ( V_90 , V_91 , V_93 , V_6 , V_19 ) ;
if ( V_70 > 0 )
F_48 ( V_89 , V_70 ) ;
F_5 ( V_2 , V_86 ) ;
return V_70 ;
}
STATIC int
F_53 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_94 ,
bool * V_95 )
{
struct V_46 * V_47 = V_2 -> V_22 ;
T_7 V_96 = F_54 ( V_47 , V_94 ) ;
int V_97 = F_55 ( V_47 , V_94 ) ;
int V_98 ;
int V_99 = 1 ;
int error = 0 ;
struct V_100 V_101 ;
F_4 ( V_2 , V_25 ) ;
error = F_56 ( V_2 , V_96 , 1 , & V_101 , & V_99 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
if ( error )
return error ;
ASSERT ( V_99 > 0 ) ;
if ( V_101 . V_102 == V_103 )
return 0 ;
V_98 = V_47 -> V_104 . V_105 - V_97 ;
if ( V_94 + V_98 > V_12 )
V_98 = V_12 - V_94 ;
* V_95 = true ;
return F_10 ( V_2 , V_94 , V_98 ) ;
}
int
F_57 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_94 ,
bool * V_95 )
{
struct V_46 * V_47 = V_2 -> V_22 ;
T_7 V_106 ;
T_7 V_107 ;
T_7 V_108 ;
T_7 V_96 ;
T_7 V_109 ;
T_5 V_98 ;
int V_99 ;
int error = 0 ;
struct V_100 V_101 ;
ASSERT ( F_58 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_94 ) ;
if ( F_55 ( V_47 , V_94 ) != 0 ) {
error = F_53 ( V_2 , V_12 , V_94 , V_95 ) ;
if ( error )
return error ;
}
V_96 = V_94 ? F_54 ( V_47 , V_94 - 1 ) : ( T_7 ) - 1 ;
V_106 = F_59 ( V_47 , ( V_110 ) V_94 ) ;
V_107 = F_54 ( V_47 , V_12 - 1 ) ;
ASSERT ( ( V_111 ) V_96 < ( V_111 ) V_106 ) ;
if ( V_96 == V_107 ) {
return 0 ;
}
ASSERT ( V_106 <= V_107 ) ;
while ( V_106 <= V_107 ) {
V_99 = 1 ;
V_108 = V_107 - V_106 + 1 ;
F_4 ( V_2 , V_25 ) ;
error = F_56 ( V_2 , V_106 , V_108 ,
& V_101 , & V_99 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
if ( error )
return error ;
ASSERT ( V_99 > 0 ) ;
if ( V_101 . V_112 == V_113 ||
V_101 . V_102 == V_103 ) {
V_106 = V_101 . V_114 + V_101 . V_115 ;
ASSERT ( V_106 <= ( V_107 + 1 ) ) ;
continue;
}
V_109 = F_60 ( V_47 , V_106 ) ;
V_98 = F_60 ( V_47 , V_101 . V_115 ) ;
if ( ( V_109 + V_98 ) > V_12 )
V_98 = V_12 - V_109 ;
error = F_10 ( V_2 , V_109 , V_98 ) ;
if ( error )
return error ;
* V_95 = true ;
V_106 = V_101 . V_114 + V_101 . V_115 ;
ASSERT ( V_106 <= ( V_107 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_61 (
struct V_64 * V_65 ,
struct V_66 * V_116 ,
int * V_117 )
{
struct V_40 * V_40 = V_65 -> V_68 ;
struct V_53 * V_53 = V_40 -> V_44 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
T_4 error = 0 ;
T_2 V_6 = F_40 ( V_116 ) ;
V_118:
error = F_62 ( V_65 , V_116 ) ;
if ( error <= 0 )
return error ;
error = F_63 ( V_53 , V_117 , true ) ;
if ( error )
return error ;
if ( * V_117 == V_86 && ! F_64 ( V_53 ) ) {
F_5 ( V_2 , * V_117 ) ;
* V_117 = V_3 ;
F_1 ( V_2 , * V_117 ) ;
goto V_118;
}
F_65 ( & V_2 -> V_119 ) ;
if ( V_65 -> V_73 > F_43 ( V_53 ) ) {
bool V_120 = false ;
F_66 ( & V_2 -> V_119 ) ;
if ( * V_117 == V_86 ) {
F_5 ( V_2 , * V_117 ) ;
* V_117 = V_3 ;
F_1 ( V_2 , * V_117 ) ;
F_67 ( V_116 , V_6 ) ;
F_68 ( V_53 ) ;
goto V_118;
}
error = F_57 ( V_2 , V_65 -> V_73 , F_43 ( V_53 ) , & V_120 ) ;
if ( error )
return error ;
} else
F_66 ( & V_2 -> V_119 ) ;
if ( F_69 ( ! ( V_40 -> V_78 & V_79 ) ) ) {
error = F_70 ( V_40 ) ;
if ( error )
return error ;
}
if ( ! F_64 ( V_53 ) )
return F_71 ( V_40 ) ;
return 0 ;
}
STATIC T_4
F_72 (
struct V_64 * V_65 ,
struct V_66 * V_116 )
{
struct V_40 * V_40 = V_65 -> V_68 ;
struct V_8 * V_9 = V_40 -> V_44 ;
struct V_53 * V_53 = V_9 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
T_4 V_70 = 0 ;
int V_121 = 0 ;
int V_117 ;
T_2 V_6 = F_40 ( V_116 ) ;
T_1 V_5 = V_65 -> V_73 ;
T_1 V_42 ;
struct V_66 V_122 ;
struct V_123 * V_81 = F_37 ( V_2 ) ?
V_47 -> V_59 : V_47 -> V_61 ;
if ( ! F_11 ( V_53 ) && ( ( V_5 | V_6 ) & V_81 -> V_82 ) )
return - V_83 ;
if ( ( V_5 & V_47 -> V_124 ) || ( ( V_5 + V_6 ) & V_47 -> V_124 ) )
V_121 = 1 ;
if ( V_121 || V_9 -> V_87 )
V_117 = V_3 ;
else
V_117 = V_86 ;
F_1 ( V_2 , V_117 ) ;
if ( V_9 -> V_87 && V_117 == V_86 ) {
F_5 ( V_2 , V_117 ) ;
V_117 = V_3 ;
F_1 ( V_2 , V_117 ) ;
}
V_70 = F_61 ( V_65 , V_116 , & V_117 ) ;
if ( V_70 )
goto V_125;
V_6 = F_40 ( V_116 ) ;
V_5 = V_65 -> V_73 ;
V_42 = V_5 + V_6 - 1 ;
if ( V_9 -> V_87 ) {
V_70 = F_34 ( F_3 ( V_2 ) -> V_11 ,
V_5 , V_42 ) ;
if ( V_70 )
goto V_125;
V_70 = F_44 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_88 ,
V_42 >> V_88 ) ;
F_45 ( V_70 ) ;
V_70 = 0 ;
}
if ( V_121 )
F_68 ( V_53 ) ;
else if ( V_117 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_117 = V_86 ;
}
F_73 ( V_2 , V_6 , V_65 -> V_73 , 0 ) ;
V_122 = * V_116 ;
V_70 = V_9 -> V_126 -> V_127 ( V_65 , & V_122 , V_5 ) ;
if ( V_9 -> V_87 ) {
F_44 ( V_9 ,
V_5 >> V_88 ,
V_42 >> V_88 ) ;
}
if ( V_70 > 0 ) {
V_5 += V_70 ;
F_74 ( V_116 , V_70 ) ;
V_65 -> V_73 = V_5 ;
}
V_125:
F_5 ( V_2 , V_117 ) ;
ASSERT ( V_70 < 0 || V_70 == V_6 || F_11 ( F_3 ( V_2 ) ) ) ;
return V_70 ;
}
STATIC T_4
F_75 (
struct V_64 * V_65 ,
struct V_66 * V_116 )
{
struct V_40 * V_40 = V_65 -> V_68 ;
struct V_8 * V_9 = V_40 -> V_44 ;
struct V_53 * V_53 = V_9 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
T_4 V_70 ;
int V_128 = 0 ;
int V_117 = V_3 ;
F_1 ( V_2 , V_117 ) ;
V_70 = F_61 ( V_65 , V_116 , & V_117 ) ;
if ( V_70 )
goto V_125;
V_129 -> V_130 = F_76 ( V_53 ) ;
V_131:
F_77 ( V_2 , F_40 ( V_116 ) ,
V_65 -> V_73 , 0 ) ;
V_70 = F_78 ( V_40 , V_116 , V_65 -> V_73 ) ;
if ( F_69 ( V_70 >= 0 ) )
V_65 -> V_73 += V_70 ;
if ( V_70 == - V_132 && ! V_128 ) {
V_128 = F_79 ( V_2 ) ;
if ( V_128 )
goto V_131;
} else if ( V_70 == - V_133 && ! V_128 ) {
struct V_134 V_135 = { 0 } ;
V_128 = 1 ;
F_80 ( V_2 -> V_22 ) ;
V_135 . V_136 = V_2 -> V_137 ;
V_135 . V_138 = V_139 ;
F_81 ( V_2 -> V_22 , & V_135 ) ;
goto V_131;
}
V_129 -> V_130 = NULL ;
V_125:
F_5 ( V_2 , V_117 ) ;
return V_70 ;
}
STATIC T_4
F_82 (
struct V_64 * V_65 ,
struct V_66 * V_116 )
{
struct V_40 * V_40 = V_65 -> V_68 ;
struct V_8 * V_9 = V_40 -> V_44 ;
struct V_53 * V_53 = V_9 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
T_4 V_70 ;
T_2 V_140 = F_40 ( V_116 ) ;
F_41 ( V_141 ) ;
if ( V_140 == 0 )
return 0 ;
if ( F_35 ( V_2 -> V_22 ) )
return - V_55 ;
if ( ( V_65 -> V_75 & V_76 ) || F_11 ( V_53 ) )
V_70 = F_72 ( V_65 , V_116 ) ;
else
V_70 = F_75 ( V_65 , V_116 ) ;
if ( V_70 > 0 ) {
T_4 V_142 ;
F_48 ( V_143 , V_70 ) ;
V_142 = F_83 ( V_40 , V_65 -> V_73 - V_70 , V_70 ) ;
if ( V_142 < 0 )
V_70 = V_142 ;
}
return V_70 ;
}
STATIC long
F_84 (
struct V_40 * V_40 ,
int V_144 ,
T_1 V_12 ,
T_1 V_145 )
{
struct V_53 * V_53 = F_85 ( V_40 ) ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
long error ;
enum V_18 V_19 = 0 ;
T_9 V_117 = V_3 ;
T_1 V_146 = 0 ;
bool V_147 = 0 ;
if ( ! F_86 ( V_53 -> V_148 ) )
return - V_83 ;
if ( V_144 & ~ V_149 )
return - V_150 ;
F_4 ( V_2 , V_117 ) ;
error = F_63 ( V_53 , & V_117 , false ) ;
if ( error )
goto V_151;
F_4 ( V_2 , V_152 ) ;
V_117 |= V_152 ;
if ( V_144 & V_153 ) {
error = F_87 ( V_2 , V_12 , V_145 ) ;
if ( error )
goto V_151;
} else if ( V_144 & V_154 ) {
unsigned V_155 = ( 1 << V_53 -> V_156 ) - 1 ;
if ( V_12 & V_155 || V_145 & V_155 ) {
error = - V_83 ;
goto V_151;
}
if ( V_12 + V_145 >= F_43 ( V_53 ) ) {
error = - V_83 ;
goto V_151;
}
V_146 = F_43 ( V_53 ) - V_145 ;
error = F_88 ( V_2 , V_12 , V_145 ) ;
if ( error )
goto V_151;
} else if ( V_144 & V_157 ) {
unsigned V_155 = ( 1 << V_53 -> V_156 ) - 1 ;
V_146 = F_43 ( V_53 ) + V_145 ;
if ( V_12 & V_155 || V_145 & V_155 ) {
error = - V_83 ;
goto V_151;
}
if ( V_146 > V_53 -> V_158 -> V_85 ) {
error = - V_159 ;
goto V_151;
}
if ( V_12 >= F_43 ( V_53 ) ) {
error = - V_83 ;
goto V_151;
}
V_147 = 1 ;
} else {
V_19 |= V_34 ;
if ( ! ( V_144 & V_160 ) &&
V_12 + V_145 > F_43 ( V_53 ) ) {
V_146 = V_12 + V_145 ;
error = F_89 ( V_53 , V_146 ) ;
if ( error )
goto V_151;
}
if ( V_144 & V_161 )
error = F_90 ( V_2 , V_12 , V_145 ) ;
else
error = F_91 ( V_2 , V_12 , V_145 ,
V_162 ) ;
if ( error )
goto V_151;
}
if ( V_40 -> V_163 & V_164 )
V_19 |= V_39 ;
error = F_17 ( V_2 , V_19 ) ;
if ( error )
goto V_151;
if ( V_146 ) {
struct V_165 V_165 ;
V_165 . V_166 = V_167 ;
V_165 . V_168 = V_146 ;
error = F_92 ( V_2 , & V_165 ) ;
if ( error )
goto V_151;
}
if ( V_147 )
error = F_93 ( V_2 , V_12 , V_145 ) ;
V_151:
F_6 ( V_2 , V_117 ) ;
return error ;
}
STATIC int
F_94 (
struct V_53 * V_53 ,
struct V_40 * V_40 )
{
if ( ! ( V_40 -> V_163 & V_169 ) && F_43 ( V_53 ) > V_170 )
return - V_159 ;
if ( F_35 ( F_95 ( V_53 -> V_158 ) ) )
return - V_55 ;
return 0 ;
}
STATIC int
F_96 (
struct V_53 * V_53 ,
struct V_40 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_53 ) ;
int V_144 ;
int error ;
error = F_94 ( V_53 , V_40 ) ;
if ( error )
return error ;
V_144 = F_97 ( V_2 ) ;
if ( V_2 -> V_27 . V_171 > 0 )
F_98 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_144 ) ;
return 0 ;
}
STATIC int
F_99 (
struct V_53 * V_53 ,
struct V_40 * V_172 )
{
return F_100 ( F_28 ( V_53 ) ) ;
}
STATIC int
F_101 (
struct V_40 * V_40 ,
struct V_173 * V_174 )
{
struct V_53 * V_53 = F_85 ( V_40 ) ;
T_10 * V_2 = F_28 ( V_53 ) ;
T_2 V_175 ;
V_175 = ( T_2 ) F_102 ( T_1 , 32768 , V_2 -> V_27 . V_176 ) ;
return F_103 ( V_2 , V_174 , V_175 ) ;
}
STATIC bool
F_104 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_177 = F_105 ( V_7 ) ;
bool V_178 = false ;
struct V_179 * V_180 , * V_181 ;
V_180 = V_181 = F_106 ( V_7 ) ;
do {
if ( F_107 ( V_180 ) ||
F_108 ( V_180 ) ) {
if ( type == V_182 )
V_178 = true ;
} else {
if ( type == V_183 )
V_178 = true ;
}
if ( V_178 ) {
* V_12 = V_177 ;
break;
}
V_177 += V_180 -> V_184 ;
} while ( ( V_180 = V_180 -> V_185 ) != V_181 );
return V_178 ;
}
STATIC bool
F_109 (
struct V_53 * V_53 ,
struct V_100 * V_186 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_53 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
struct V_187 V_188 ;
T_11 V_189 ;
T_11 V_42 ;
T_1 V_190 ;
T_1 V_191 = * V_12 ;
T_1 V_177 = V_191 ;
bool V_178 = false ;
F_110 ( & V_188 , 0 ) ;
V_189 = V_191 >> V_88 ;
V_190 = F_60 ( V_47 , V_186 -> V_114 + V_186 -> V_115 ) ;
V_42 = V_190 >> V_88 ;
do {
int V_192 ;
unsigned V_193 ;
unsigned int V_194 ;
V_192 = F_102 ( T_11 , V_42 - V_189 , V_195 ) ;
V_193 = F_111 ( & V_188 , V_53 -> V_11 , V_189 ,
V_192 ) ;
if ( V_193 == 0 ) {
if ( type == V_182 )
break;
ASSERT ( type == V_183 ) ;
if ( V_177 == V_191 || V_177 < V_190 ) {
V_178 = true ;
* V_12 = V_177 ;
}
break;
}
if ( type == V_183 && V_177 == V_191 &&
V_177 < F_105 ( V_188 . V_196 [ 0 ] ) ) {
V_178 = true ;
break;
}
for ( V_194 = 0 ; V_194 < V_193 ; V_194 ++ ) {
struct V_7 * V_7 = V_188 . V_196 [ V_194 ] ;
T_1 V_197 ;
if ( V_7 -> V_189 > V_42 ) {
if ( type == V_183 && V_177 < V_190 ) {
* V_12 = V_177 ;
V_178 = true ;
}
goto V_125;
}
F_112 ( V_7 ) ;
if ( F_42 ( V_7 -> V_9 != V_53 -> V_11 ) ) {
F_113 ( V_7 ) ;
continue;
}
if ( ! F_114 ( V_7 ) ) {
F_113 ( V_7 ) ;
continue;
}
V_178 = F_104 ( V_7 , & V_197 , type ) ;
if ( V_178 ) {
* V_12 = F_115 ( T_1 , V_191 , V_197 ) ;
F_113 ( V_7 ) ;
goto V_125;
}
V_177 = F_105 ( V_7 ) + V_198 ;
F_113 ( V_7 ) ;
}
if ( V_193 < V_192 ) {
if ( type == V_183 ) {
* V_12 = V_177 ;
V_178 = true ;
}
break;
}
V_189 = V_188 . V_196 [ V_194 - 1 ] -> V_189 + 1 ;
F_116 ( & V_188 ) ;
} while ( V_189 <= V_42 );
V_125:
F_116 ( & V_188 ) ;
return V_178 ;
}
STATIC T_1
F_117 (
struct V_40 * V_40 ,
T_1 V_41 ,
int V_199 )
{
struct V_53 * V_53 = V_40 -> V_44 -> V_45 ;
struct V_1 * V_2 = F_28 ( V_53 ) ;
struct V_46 * V_47 = V_2 -> V_22 ;
T_1 V_200 ( V_12 ) ;
T_5 V_94 ;
T_7 V_201 ;
T_12 V_42 ;
T_9 V_202 ;
int error ;
if ( F_35 ( V_47 ) )
return - V_55 ;
V_202 = F_97 ( V_2 ) ;
V_94 = F_43 ( V_53 ) ;
if ( V_41 >= V_94 ) {
error = - V_203 ;
goto V_151;
}
V_201 = F_54 ( V_47 , V_41 ) ;
V_42 = F_59 ( V_47 , V_94 ) ;
for (; ; ) {
struct V_100 V_186 [ 2 ] ;
int V_204 = 2 ;
unsigned int V_194 ;
error = F_56 ( V_2 , V_201 , V_42 - V_201 , V_186 , & V_204 ,
V_205 ) ;
if ( error )
goto V_151;
if ( V_204 == 0 ) {
error = - V_203 ;
goto V_151;
}
for ( V_194 = 0 ; V_194 < V_204 ; V_194 ++ ) {
V_12 = F_115 ( T_1 , V_41 ,
F_60 ( V_47 , V_186 [ V_194 ] . V_114 ) ) ;
if ( V_199 == V_206 &&
V_186 [ V_194 ] . V_102 == V_103 )
goto V_125;
if ( V_199 == V_207 &&
( V_186 [ V_194 ] . V_102 == V_208 ||
( V_186 [ V_194 ] . V_112 == V_209 &&
! F_118 ( V_186 [ V_194 ] . V_102 ) ) ) )
goto V_125;
if ( V_186 [ V_194 ] . V_112 == V_113 ) {
if ( F_109 ( V_53 , & V_186 [ V_194 ] ,
V_199 == V_206 ? V_183 : V_182 ,
& V_12 ) )
goto V_125;
}
}
if ( V_204 == 1 ) {
if ( V_199 == V_206 ) {
V_12 = V_94 ;
break;
}
ASSERT ( V_199 == V_207 ) ;
error = - V_203 ;
goto V_151;
}
ASSERT ( V_194 > 1 ) ;
V_201 = V_186 [ V_194 - 1 ] . V_114 + V_186 [ V_194 - 1 ] . V_115 ;
V_41 = F_60 ( V_47 , V_201 ) ;
if ( V_41 >= V_94 ) {
if ( V_199 == V_206 ) {
V_12 = V_94 ;
break;
}
ASSERT ( V_199 == V_207 ) ;
error = - V_203 ;
goto V_151;
}
}
V_125:
if ( V_199 == V_206 )
V_12 = F_102 ( T_1 , V_12 , V_94 ) ;
V_12 = F_119 ( V_40 , V_12 , V_53 -> V_158 -> V_85 ) ;
V_151:
F_6 ( V_2 , V_202 ) ;
if ( error )
return error ;
return V_12 ;
}
STATIC T_1
F_120 (
struct V_40 * V_40 ,
T_1 V_12 ,
int V_199 )
{
switch ( V_199 ) {
case V_210 :
case V_211 :
case V_212 :
return F_121 ( V_40 , V_12 , V_199 ) ;
case V_206 :
case V_207 :
return F_117 ( V_40 , V_12 , V_199 ) ;
default:
return - V_83 ;
}
}
STATIC int
F_122 (
struct V_213 * V_214 ,
struct V_215 * V_216 )
{
struct V_53 * V_53 = F_85 ( V_214 -> V_217 ) ;
int V_70 ;
F_123 ( F_28 ( V_53 ) ) ;
F_124 ( V_53 -> V_158 ) ;
F_70 ( V_214 -> V_217 ) ;
F_4 ( F_28 ( V_53 ) , V_218 ) ;
if ( F_11 ( V_53 ) ) {
V_70 = F_125 ( V_214 , V_216 , V_16 ,
V_219 ) ;
} else {
V_70 = F_126 ( V_214 , V_216 , V_220 ) ;
V_70 = F_127 ( V_70 ) ;
}
F_6 ( F_28 ( V_53 ) , V_218 ) ;
F_128 ( V_53 -> V_158 ) ;
return V_70 ;
}
STATIC int
F_129 (
struct V_213 * V_214 ,
struct V_215 * V_216 )
{
struct V_53 * V_53 = F_85 ( V_214 -> V_217 ) ;
int V_70 ;
F_130 ( F_28 ( V_53 ) ) ;
if ( ( V_216 -> V_19 & V_221 ) && F_11 ( V_53 ) )
return F_122 ( V_214 , V_216 ) ;
F_4 ( F_28 ( V_53 ) , V_218 ) ;
if ( F_11 ( V_53 ) ) {
V_70 = F_131 ( V_214 , V_216 , V_16 , NULL ) ;
} else
V_70 = F_132 ( V_214 , V_216 ) ;
F_6 ( F_28 ( V_53 ) , V_218 ) ;
return V_70 ;
}
STATIC int
F_133 (
struct V_40 * V_172 ,
struct V_213 * V_214 )
{
F_134 ( V_172 ) ;
V_214 -> V_222 = & V_223 ;
if ( F_11 ( F_85 ( V_172 ) ) )
V_214 -> V_224 |= V_225 ;
return 0 ;
}
