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
int V_10 ;
V_9 = F_3 ( V_2 ) -> V_11 ;
do {
unsigned V_12 , V_13 ;
void * V_14 ;
V_12 = ( V_5 & ( V_15 - 1 ) ) ;
V_13 = V_15 - V_12 ;
if ( V_13 > V_6 )
V_13 = V_6 ;
V_10 = F_11 ( NULL , V_9 , V_5 , V_13 ,
V_16 ,
& V_7 , & V_14 ) ;
if ( V_10 )
break;
F_12 ( V_7 , V_12 , V_13 ) ;
V_10 = F_13 ( NULL , V_9 , V_5 , V_13 , V_13 ,
V_7 , V_14 ) ;
F_14 ( V_10 <= 0 ) ;
V_5 += V_13 ;
V_6 -= V_13 ;
V_10 = 0 ;
} while ( V_6 );
return V_10 ;
}
int
F_15 (
struct V_1 * V_2 ,
enum V_17 V_18 )
{
struct V_19 * V_20 ;
int error ;
V_20 = F_16 ( V_2 -> V_21 , V_22 ) ;
error = F_17 ( V_20 , & F_18 ( V_2 -> V_21 ) -> V_23 , 0 , 0 ) ;
if ( error ) {
F_19 ( V_20 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_24 ) ;
F_20 ( V_20 , V_2 , V_24 ) ;
if ( ! ( V_18 & V_25 ) ) {
V_2 -> V_26 . V_27 &= ~ V_28 ;
if ( V_2 -> V_26 . V_27 & V_29 )
V_2 -> V_26 . V_27 &= ~ V_30 ;
F_21 ( V_20 , V_2 , V_31 | V_32 ) ;
}
if ( V_18 & V_33 )
V_2 -> V_26 . V_34 |= V_35 ;
if ( V_18 & V_36 )
V_2 -> V_26 . V_34 &= ~ V_35 ;
F_22 ( V_20 , V_2 , V_37 ) ;
if ( V_18 & V_38 )
F_23 ( V_20 ) ;
return F_24 ( V_20 , 0 ) ;
}
STATIC int
F_25 (
struct V_39 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
int V_42 )
{
struct V_1 * V_2 = F_26 ( V_39 -> V_43 -> V_44 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_3 V_47 = 0 ;
F_27 ( V_2 ) ;
F_4 ( V_2 , V_48 ) ;
if ( F_28 ( V_2 ) )
V_47 = V_2 -> V_49 -> V_50 ;
F_6 ( V_2 , V_48 ) ;
if ( ! V_47 )
return 0 ;
return F_29 ( V_46 , V_47 , V_51 , NULL ) ;
}
STATIC int
F_30 (
struct V_39 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
int V_42 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
int error = 0 ;
int V_53 = 0 ;
T_3 V_47 = 0 ;
F_31 ( V_2 ) ;
error = F_32 ( V_52 -> V_11 , V_40 , V_41 ) ;
if ( error )
return error ;
if ( F_33 ( V_46 ) )
return - V_54 ;
F_34 ( V_2 , V_55 ) ;
if ( V_46 -> V_56 & V_57 ) {
if ( F_35 ( V_2 ) )
F_36 ( V_46 -> V_58 ) ;
else if ( V_46 -> V_59 != V_46 -> V_60 )
F_36 ( V_46 -> V_60 ) ;
}
F_4 ( V_2 , V_48 ) ;
if ( F_28 ( V_2 ) ) {
if ( ! V_42 ||
( V_2 -> V_49 -> V_61 & ~ V_62 ) )
V_47 = V_2 -> V_49 -> V_50 ;
}
F_6 ( V_2 , V_48 ) ;
if ( V_47 )
error = F_29 ( V_46 , V_47 , V_51 , & V_53 ) ;
if ( ( V_46 -> V_56 & V_57 ) &&
V_46 -> V_59 == V_46 -> V_60 &&
! F_35 ( V_2 ) &&
! V_53 )
F_36 ( V_46 -> V_60 ) ;
return error ;
}
STATIC T_4
F_37 (
struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_2 V_68 = F_38 ( V_66 ) ;
T_4 V_69 = 0 ;
int V_70 = 0 ;
T_5 V_71 ;
T_1 V_5 = V_64 -> V_72 ;
F_39 ( V_73 ) ;
if ( F_40 ( V_64 -> V_74 & V_75 ) )
V_70 |= V_76 ;
if ( V_39 -> V_77 & V_78 )
V_70 |= V_79 ;
if ( F_40 ( V_70 & V_76 ) ) {
T_6 * V_80 =
F_35 ( V_2 ) ?
V_46 -> V_58 : V_46 -> V_60 ;
if ( ( V_5 | V_68 ) & V_80 -> V_81 ) {
if ( V_5 == F_41 ( V_52 ) )
return 0 ;
return - V_82 ;
}
}
V_71 = V_46 -> V_83 -> V_84 - V_5 ;
if ( V_71 <= 0 || V_68 == 0 )
return 0 ;
if ( V_71 < V_68 )
V_68 = V_71 ;
if ( F_33 ( V_46 ) )
return - V_54 ;
F_1 ( V_2 , V_85 ) ;
if ( ( V_70 & V_76 ) && V_52 -> V_11 -> V_86 ) {
F_5 ( V_2 , V_85 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_52 -> V_11 -> V_86 ) {
V_69 = F_32 (
F_3 ( V_2 ) -> V_11 ,
V_5 , V_5 + V_68 - 1 ) ;
if ( V_69 ) {
F_5 ( V_2 , V_3 ) ;
return V_69 ;
}
V_69 = F_42 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_87 ,
( V_5 + V_68 - 1 ) >> V_87 ) ;
F_43 ( V_69 ) ;
V_69 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
F_44 ( V_2 , V_68 , V_5 , V_70 ) ;
V_69 = F_45 ( V_64 , V_66 ) ;
if ( V_69 > 0 )
F_46 ( V_88 , V_69 ) ;
F_5 ( V_2 , V_85 ) ;
return V_69 ;
}
STATIC T_4
F_47 (
struct V_39 * V_89 ,
T_1 * V_90 ,
struct V_91 * V_92 ,
T_2 V_6 ,
unsigned int V_18 )
{
struct V_1 * V_2 = F_26 ( V_89 -> V_43 -> V_44 ) ;
int V_70 = 0 ;
T_4 V_69 ;
F_39 ( V_73 ) ;
if ( V_89 -> V_77 & V_78 )
V_70 |= V_79 ;
if ( F_33 ( V_2 -> V_21 ) )
return - V_54 ;
F_1 ( V_2 , V_85 ) ;
F_48 ( V_2 , V_6 , * V_90 , V_70 ) ;
V_69 = F_49 ( V_89 , V_90 , V_92 , V_6 , V_18 ) ;
if ( V_69 > 0 )
F_46 ( V_88 , V_69 ) ;
F_5 ( V_2 , V_85 ) ;
return V_69 ;
}
STATIC int
F_50 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_93 ,
bool * V_94 )
{
struct V_45 * V_46 = V_2 -> V_21 ;
T_7 V_95 = F_51 ( V_46 , V_93 ) ;
int V_96 = F_52 ( V_46 , V_93 ) ;
int V_97 ;
int V_98 = 1 ;
int error = 0 ;
struct V_99 V_100 ;
F_4 ( V_2 , V_24 ) ;
error = F_53 ( V_2 , V_95 , 1 , & V_100 , & V_98 , 0 ) ;
F_6 ( V_2 , V_24 ) ;
if ( error )
return error ;
ASSERT ( V_98 > 0 ) ;
if ( V_100 . V_101 == V_102 )
return 0 ;
V_97 = V_46 -> V_103 . V_104 - V_96 ;
if ( V_93 + V_97 > V_12 )
V_97 = V_12 - V_93 ;
* V_94 = true ;
return F_10 ( V_2 , V_93 , V_97 ) ;
}
int
F_54 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_93 ,
bool * V_94 )
{
struct V_45 * V_46 = V_2 -> V_21 ;
T_7 V_105 ;
T_7 V_106 ;
T_7 V_107 ;
T_7 V_95 ;
T_7 V_108 ;
T_5 V_97 ;
int V_98 ;
int error = 0 ;
struct V_99 V_100 ;
ASSERT ( F_55 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_93 ) ;
if ( F_52 ( V_46 , V_93 ) != 0 ) {
error = F_50 ( V_2 , V_12 , V_93 , V_94 ) ;
if ( error )
return error ;
}
V_95 = V_93 ? F_51 ( V_46 , V_93 - 1 ) : ( T_7 ) - 1 ;
V_105 = F_56 ( V_46 , ( V_109 ) V_93 ) ;
V_106 = F_51 ( V_46 , V_12 - 1 ) ;
ASSERT ( ( V_110 ) V_95 < ( V_110 ) V_105 ) ;
if ( V_95 == V_106 ) {
return 0 ;
}
ASSERT ( V_105 <= V_106 ) ;
while ( V_105 <= V_106 ) {
V_98 = 1 ;
V_107 = V_106 - V_105 + 1 ;
F_4 ( V_2 , V_24 ) ;
error = F_53 ( V_2 , V_105 , V_107 ,
& V_100 , & V_98 , 0 ) ;
F_6 ( V_2 , V_24 ) ;
if ( error )
return error ;
ASSERT ( V_98 > 0 ) ;
if ( V_100 . V_111 == V_112 ||
V_100 . V_101 == V_102 ) {
V_105 = V_100 . V_113 + V_100 . V_114 ;
ASSERT ( V_105 <= ( V_106 + 1 ) ) ;
continue;
}
V_108 = F_57 ( V_46 , V_105 ) ;
V_97 = F_57 ( V_46 , V_100 . V_114 ) ;
if ( ( V_108 + V_97 ) > V_12 )
V_97 = V_12 - V_108 ;
error = F_10 ( V_2 , V_108 , V_97 ) ;
if ( error )
return error ;
* V_94 = true ;
V_105 = V_100 . V_113 + V_100 . V_114 ;
ASSERT ( V_105 <= ( V_106 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_58 (
struct V_63 * V_64 ,
struct V_65 * V_115 ,
int * V_116 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 error = 0 ;
T_2 V_6 = F_38 ( V_115 ) ;
V_117:
error = F_59 ( V_64 , V_115 ) ;
if ( error <= 0 )
return error ;
error = F_60 ( V_52 , V_116 , true ) ;
if ( error )
return error ;
F_61 ( & V_2 -> V_118 ) ;
if ( V_64 -> V_72 > F_41 ( V_52 ) ) {
bool V_119 = false ;
F_62 ( & V_2 -> V_118 ) ;
if ( * V_116 == V_85 ) {
F_5 ( V_2 , * V_116 ) ;
* V_116 = V_3 ;
F_1 ( V_2 , * V_116 ) ;
F_63 ( V_115 , V_6 ) ;
F_64 ( V_52 ) ;
goto V_117;
}
error = F_54 ( V_2 , V_64 -> V_72 , F_41 ( V_52 ) , & V_119 ) ;
if ( error )
return error ;
} else
F_62 ( & V_2 -> V_118 ) ;
if ( F_65 ( ! ( V_39 -> V_77 & V_78 ) ) ) {
error = F_66 ( V_39 ) ;
if ( error )
return error ;
}
return F_67 ( V_39 ) ;
}
STATIC T_4
F_68 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_4 V_69 = 0 ;
int V_120 = 0 ;
int V_116 ;
T_2 V_6 = F_38 ( V_115 ) ;
T_1 V_5 = V_64 -> V_72 ;
T_1 V_41 ;
struct V_65 V_121 ;
struct V_122 * V_80 = F_35 ( V_2 ) ?
V_46 -> V_58 : V_46 -> V_60 ;
if ( ( V_5 | V_6 ) & V_80 -> V_81 )
return - V_82 ;
if ( ( V_5 & V_46 -> V_123 ) || ( ( V_5 + V_6 ) & V_46 -> V_123 ) )
V_120 = 1 ;
if ( V_120 || V_9 -> V_86 )
V_116 = V_3 ;
else
V_116 = V_85 ;
F_1 ( V_2 , V_116 ) ;
if ( V_9 -> V_86 && V_116 == V_85 ) {
F_5 ( V_2 , V_116 ) ;
V_116 = V_3 ;
F_1 ( V_2 , V_116 ) ;
}
V_69 = F_58 ( V_64 , V_115 , & V_116 ) ;
if ( V_69 )
goto V_124;
V_6 = F_38 ( V_115 ) ;
V_5 = V_64 -> V_72 ;
V_41 = V_5 + V_6 - 1 ;
if ( V_9 -> V_86 ) {
V_69 = F_32 ( F_3 ( V_2 ) -> V_11 ,
V_5 , V_41 ) ;
if ( V_69 )
goto V_124;
V_69 = F_42 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_87 ,
V_41 >> V_87 ) ;
F_43 ( V_69 ) ;
V_69 = 0 ;
}
if ( V_120 )
F_64 ( V_52 ) ;
else if ( V_116 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_116 = V_85 ;
}
F_69 ( V_2 , V_6 , V_64 -> V_72 , 0 ) ;
V_121 = * V_115 ;
V_69 = V_9 -> V_125 -> V_126 ( V_64 , & V_121 , V_5 ) ;
if ( V_9 -> V_86 ) {
F_42 ( V_9 ,
V_5 >> V_87 ,
V_41 >> V_87 ) ;
}
if ( V_69 > 0 ) {
V_5 += V_69 ;
F_70 ( V_115 , V_69 ) ;
V_64 -> V_72 = V_5 ;
}
V_124:
F_5 ( V_2 , V_116 ) ;
ASSERT ( V_69 < 0 || V_69 == V_6 ) ;
return V_69 ;
}
STATIC T_4
F_71 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 V_69 ;
int V_127 = 0 ;
int V_116 = V_3 ;
F_1 ( V_2 , V_116 ) ;
V_69 = F_58 ( V_64 , V_115 , & V_116 ) ;
if ( V_69 )
goto V_124;
V_128 -> V_129 = F_72 ( V_52 ) ;
V_130:
F_73 ( V_2 , F_38 ( V_115 ) ,
V_64 -> V_72 , 0 ) ;
V_69 = F_74 ( V_39 , V_115 , V_64 -> V_72 ) ;
if ( F_65 ( V_69 >= 0 ) )
V_64 -> V_72 += V_69 ;
if ( V_69 == - V_131 && ! V_127 ) {
V_127 = F_75 ( V_2 ) ;
if ( V_127 )
goto V_130;
} else if ( V_69 == - V_132 && ! V_127 ) {
struct V_133 V_134 = { 0 } ;
V_127 = 1 ;
F_76 ( V_2 -> V_21 ) ;
V_134 . V_135 = V_2 -> V_136 ;
V_134 . V_137 = V_138 ;
F_77 ( V_2 -> V_21 , & V_134 ) ;
goto V_130;
}
V_128 -> V_129 = NULL ;
V_124:
F_5 ( V_2 , V_116 ) ;
return V_69 ;
}
STATIC T_4
F_78 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 V_69 ;
T_2 V_139 = F_38 ( V_115 ) ;
F_39 ( V_140 ) ;
if ( V_139 == 0 )
return 0 ;
if ( F_33 ( V_2 -> V_21 ) )
return - V_54 ;
if ( F_40 ( V_64 -> V_74 & V_75 ) )
V_69 = F_68 ( V_64 , V_115 ) ;
else
V_69 = F_71 ( V_64 , V_115 ) ;
if ( V_69 > 0 ) {
T_4 V_141 ;
F_46 ( V_142 , V_69 ) ;
V_141 = F_79 ( V_39 , V_64 -> V_72 - V_69 , V_69 ) ;
if ( V_141 < 0 )
V_69 = V_141 ;
}
return V_69 ;
}
STATIC long
F_80 (
struct V_39 * V_39 ,
int V_143 ,
T_1 V_12 ,
T_1 V_144 )
{
struct V_52 * V_52 = F_81 ( V_39 ) ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
long error ;
enum V_17 V_18 = 0 ;
T_9 V_116 = V_3 ;
T_1 V_145 = 0 ;
bool V_146 = 0 ;
if ( ! F_82 ( V_52 -> V_147 ) )
return - V_82 ;
if ( V_143 & ~ V_148 )
return - V_149 ;
F_4 ( V_2 , V_116 ) ;
error = F_60 ( V_52 , & V_116 , false ) ;
if ( error )
goto V_150;
F_4 ( V_2 , V_151 ) ;
V_116 |= V_151 ;
if ( V_143 & V_152 ) {
error = F_83 ( V_2 , V_12 , V_144 ) ;
if ( error )
goto V_150;
} else if ( V_143 & V_153 ) {
unsigned V_154 = ( 1 << V_52 -> V_155 ) - 1 ;
if ( V_12 & V_154 || V_144 & V_154 ) {
error = - V_82 ;
goto V_150;
}
if ( V_12 + V_144 >= F_41 ( V_52 ) ) {
error = - V_82 ;
goto V_150;
}
V_145 = F_41 ( V_52 ) - V_144 ;
error = F_84 ( V_2 , V_12 , V_144 ) ;
if ( error )
goto V_150;
} else if ( V_143 & V_156 ) {
unsigned V_154 = ( 1 << V_52 -> V_155 ) - 1 ;
V_145 = F_41 ( V_52 ) + V_144 ;
if ( V_12 & V_154 || V_144 & V_154 ) {
error = - V_82 ;
goto V_150;
}
if ( V_145 > V_52 -> V_157 -> V_84 ) {
error = - V_158 ;
goto V_150;
}
if ( V_12 >= F_41 ( V_52 ) ) {
error = - V_82 ;
goto V_150;
}
V_146 = 1 ;
} else {
V_18 |= V_33 ;
if ( ! ( V_143 & V_159 ) &&
V_12 + V_144 > F_41 ( V_52 ) ) {
V_145 = V_12 + V_144 ;
error = F_85 ( V_52 , V_145 ) ;
if ( error )
goto V_150;
}
if ( V_143 & V_160 )
error = F_86 ( V_2 , V_12 , V_144 ) ;
else
error = F_87 ( V_2 , V_12 , V_144 ,
V_161 ) ;
if ( error )
goto V_150;
}
if ( V_39 -> V_162 & V_163 )
V_18 |= V_38 ;
error = F_15 ( V_2 , V_18 ) ;
if ( error )
goto V_150;
if ( V_145 ) {
struct V_164 V_164 ;
V_164 . V_165 = V_166 ;
V_164 . V_167 = V_145 ;
error = F_88 ( V_2 , & V_164 ) ;
if ( error )
goto V_150;
}
if ( V_146 )
error = F_89 ( V_2 , V_12 , V_144 ) ;
V_150:
F_6 ( V_2 , V_116 ) ;
return error ;
}
STATIC int
F_90 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
if ( ! ( V_39 -> V_162 & V_168 ) && F_41 ( V_52 ) > V_169 )
return - V_158 ;
if ( F_33 ( F_91 ( V_52 -> V_157 ) ) )
return - V_54 ;
return 0 ;
}
STATIC int
F_92 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
int V_143 ;
int error ;
error = F_90 ( V_52 , V_39 ) ;
if ( error )
return error ;
V_143 = F_93 ( V_2 ) ;
if ( V_2 -> V_26 . V_170 > 0 )
F_94 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_143 ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_52 * V_52 ,
struct V_39 * V_171 )
{
return F_96 ( F_26 ( V_52 ) ) ;
}
STATIC int
F_97 (
struct V_39 * V_39 ,
struct V_172 * V_173 )
{
struct V_52 * V_52 = F_81 ( V_39 ) ;
T_10 * V_2 = F_26 ( V_52 ) ;
T_2 V_174 ;
V_174 = ( T_2 ) F_98 ( T_1 , 32768 , V_2 -> V_26 . V_175 ) ;
return F_99 ( V_2 , V_173 , V_174 ) ;
}
STATIC int
F_100 (
struct V_39 * V_171 ,
struct V_176 * V_177 )
{
V_177 -> V_178 = & V_179 ;
F_101 ( V_171 ) ;
return 0 ;
}
STATIC bool
F_102 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_180 = F_103 ( V_7 ) ;
bool V_181 = false ;
struct V_182 * V_183 , * V_184 ;
V_183 = V_184 = F_104 ( V_7 ) ;
do {
if ( F_105 ( V_183 ) ||
F_106 ( V_183 ) ) {
if ( type == V_185 )
V_181 = true ;
} else {
if ( type == V_186 )
V_181 = true ;
}
if ( V_181 ) {
* V_12 = V_180 ;
break;
}
V_180 += V_183 -> V_187 ;
} while ( ( V_183 = V_183 -> V_188 ) != V_184 );
return V_181 ;
}
STATIC bool
F_107 (
struct V_52 * V_52 ,
struct V_99 * V_189 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
struct V_190 V_191 ;
T_11 V_192 ;
T_11 V_41 ;
T_1 V_193 ;
T_1 V_194 = * V_12 ;
T_1 V_180 = V_194 ;
bool V_181 = false ;
F_108 ( & V_191 , 0 ) ;
V_192 = V_194 >> V_87 ;
V_193 = F_57 ( V_46 , V_189 -> V_113 + V_189 -> V_114 ) ;
V_41 = V_193 >> V_87 ;
do {
int V_195 ;
unsigned V_196 ;
unsigned int V_197 ;
V_195 = F_98 ( T_11 , V_41 - V_192 , V_198 ) ;
V_196 = F_109 ( & V_191 , V_52 -> V_11 , V_192 ,
V_195 ) ;
if ( V_196 == 0 ) {
if ( type == V_185 )
break;
ASSERT ( type == V_186 ) ;
if ( V_180 == V_194 || V_180 < V_193 ) {
V_181 = true ;
* V_12 = V_180 ;
}
break;
}
if ( type == V_186 && V_180 == V_194 &&
V_180 < F_103 ( V_191 . V_199 [ 0 ] ) ) {
V_181 = true ;
break;
}
for ( V_197 = 0 ; V_197 < V_196 ; V_197 ++ ) {
struct V_7 * V_7 = V_191 . V_199 [ V_197 ] ;
T_1 V_200 ;
if ( V_7 -> V_192 > V_41 ) {
if ( type == V_186 && V_180 < V_193 ) {
* V_12 = V_180 ;
V_181 = true ;
}
goto V_124;
}
F_110 ( V_7 ) ;
if ( F_40 ( V_7 -> V_9 != V_52 -> V_11 ) ) {
F_111 ( V_7 ) ;
continue;
}
if ( ! F_112 ( V_7 ) ) {
F_111 ( V_7 ) ;
continue;
}
V_181 = F_102 ( V_7 , & V_200 , type ) ;
if ( V_181 ) {
* V_12 = F_113 ( T_1 , V_194 , V_200 ) ;
F_111 ( V_7 ) ;
goto V_124;
}
V_180 = F_103 ( V_7 ) + V_201 ;
F_111 ( V_7 ) ;
}
if ( V_196 < V_195 ) {
if ( type == V_186 ) {
* V_12 = V_180 ;
V_181 = true ;
}
break;
}
V_192 = V_191 . V_199 [ V_197 - 1 ] -> V_192 + 1 ;
F_114 ( & V_191 ) ;
} while ( V_192 <= V_41 );
V_124:
F_114 ( & V_191 ) ;
return V_181 ;
}
STATIC T_1
F_115 (
struct V_39 * V_39 ,
T_1 V_40 ,
int V_202 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_1 V_203 ( V_12 ) ;
T_5 V_93 ;
T_7 V_204 ;
T_12 V_41 ;
T_9 V_205 ;
int error ;
if ( F_33 ( V_46 ) )
return - V_54 ;
V_205 = F_93 ( V_2 ) ;
V_93 = F_41 ( V_52 ) ;
if ( V_40 >= V_93 ) {
error = - V_206 ;
goto V_150;
}
V_204 = F_51 ( V_46 , V_40 ) ;
V_41 = F_56 ( V_46 , V_93 ) ;
for (; ; ) {
struct V_99 V_189 [ 2 ] ;
int V_207 = 2 ;
unsigned int V_197 ;
error = F_53 ( V_2 , V_204 , V_41 - V_204 , V_189 , & V_207 ,
V_208 ) ;
if ( error )
goto V_150;
if ( V_207 == 0 ) {
error = - V_206 ;
goto V_150;
}
for ( V_197 = 0 ; V_197 < V_207 ; V_197 ++ ) {
V_12 = F_113 ( T_1 , V_40 ,
F_57 ( V_46 , V_189 [ V_197 ] . V_113 ) ) ;
if ( V_202 == V_209 &&
V_189 [ V_197 ] . V_101 == V_102 )
goto V_124;
if ( V_202 == V_210 &&
( V_189 [ V_197 ] . V_101 == V_211 ||
( V_189 [ V_197 ] . V_111 == V_212 &&
! F_116 ( V_189 [ V_197 ] . V_101 ) ) ) )
goto V_124;
if ( V_189 [ V_197 ] . V_111 == V_112 ) {
if ( F_107 ( V_52 , & V_189 [ V_197 ] ,
V_202 == V_209 ? V_186 : V_185 ,
& V_12 ) )
goto V_124;
}
}
if ( V_207 == 1 ) {
if ( V_202 == V_209 ) {
V_12 = V_93 ;
break;
}
ASSERT ( V_202 == V_210 ) ;
error = - V_206 ;
goto V_150;
}
ASSERT ( V_197 > 1 ) ;
V_204 = V_189 [ V_197 - 1 ] . V_113 + V_189 [ V_197 - 1 ] . V_114 ;
V_40 = F_57 ( V_46 , V_204 ) ;
if ( V_40 >= V_93 ) {
if ( V_202 == V_209 ) {
V_12 = V_93 ;
break;
}
ASSERT ( V_202 == V_210 ) ;
error = - V_206 ;
goto V_150;
}
}
V_124:
if ( V_202 == V_209 )
V_12 = F_98 ( T_1 , V_12 , V_93 ) ;
V_12 = F_117 ( V_39 , V_12 , V_52 -> V_157 -> V_84 ) ;
V_150:
F_6 ( V_2 , V_205 ) ;
if ( error )
return error ;
return V_12 ;
}
STATIC T_1
F_118 (
struct V_39 * V_39 ,
T_1 V_12 ,
int V_202 )
{
switch ( V_202 ) {
case V_213 :
case V_214 :
case V_215 :
return F_119 ( V_39 , V_12 , V_202 ) ;
case V_209 :
case V_210 :
return F_115 ( V_39 , V_12 , V_202 ) ;
default:
return - V_82 ;
}
}
STATIC int
F_120 (
struct V_176 * V_177 ,
struct V_216 * V_217 )
{
struct V_1 * V_2 = F_26 ( V_177 -> V_218 -> V_43 -> V_44 ) ;
int error ;
F_121 ( V_2 ) ;
F_4 ( V_2 , V_219 ) ;
error = F_122 ( V_177 , V_217 ) ;
F_6 ( V_2 , V_219 ) ;
return error ;
}
STATIC int
F_123 (
struct V_176 * V_177 ,
struct V_216 * V_217 )
{
struct V_1 * V_2 = F_26 ( V_177 -> V_218 -> V_43 -> V_44 ) ;
int error ;
F_124 ( V_2 ) ;
F_4 ( V_2 , V_219 ) ;
error = F_125 ( V_177 , V_217 , V_220 ) ;
F_6 ( V_2 , V_219 ) ;
return error ;
}
