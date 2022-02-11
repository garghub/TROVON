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
V_20 = F_18 ( V_2 -> V_21 , V_22 ) ;
error = F_19 ( V_20 , & F_20 ( V_2 -> V_21 ) -> V_23 , 0 , 0 ) ;
if ( error ) {
F_21 ( V_20 ) ;
return error ;
}
F_4 ( V_2 , V_24 ) ;
F_22 ( V_20 , V_2 , V_24 ) ;
if ( ! ( V_18 & V_25 ) ) {
F_3 ( V_2 ) -> V_26 &= ~ V_27 ;
if ( F_3 ( V_2 ) -> V_26 & V_28 )
F_3 ( V_2 ) -> V_26 &= ~ V_29 ;
F_23 ( V_20 , V_2 , V_30 | V_31 ) ;
}
if ( V_18 & V_32 )
V_2 -> V_33 . V_34 |= V_35 ;
if ( V_18 & V_36 )
V_2 -> V_33 . V_34 &= ~ V_35 ;
F_24 ( V_20 , V_2 , V_37 ) ;
if ( V_18 & V_38 )
F_25 ( V_20 ) ;
return F_26 ( V_20 ) ;
}
STATIC int
F_27 (
struct V_39 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
int V_42 )
{
struct V_1 * V_2 = F_28 ( V_39 -> V_43 -> V_44 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_3 V_47 = 0 ;
F_29 ( V_2 ) ;
F_4 ( V_2 , V_48 ) ;
if ( F_30 ( V_2 ) )
V_47 = V_2 -> V_49 -> V_50 ;
F_6 ( V_2 , V_48 ) ;
if ( ! V_47 )
return 0 ;
return F_31 ( V_46 , V_47 , V_51 , NULL ) ;
}
STATIC int
F_32 (
struct V_39 * V_39 ,
T_1 V_40 ,
T_1 V_41 ,
int V_42 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
int error = 0 ;
int V_53 = 0 ;
T_3 V_47 = 0 ;
F_33 ( V_2 ) ;
error = F_34 ( V_52 -> V_10 , V_40 , V_41 ) ;
if ( error )
return error ;
if ( F_35 ( V_46 ) )
return - V_54 ;
F_36 ( V_2 , V_55 ) ;
if ( V_46 -> V_56 & V_57 ) {
if ( F_37 ( V_2 ) )
F_38 ( V_46 -> V_58 ) ;
else if ( V_46 -> V_59 != V_46 -> V_60 )
F_38 ( V_46 -> V_60 ) ;
}
F_4 ( V_2 , V_48 ) ;
if ( F_30 ( V_2 ) ) {
if ( ! V_42 ||
( V_2 -> V_49 -> V_61 & ~ V_62 ) )
V_47 = V_2 -> V_49 -> V_50 ;
}
if ( V_47 ) {
error = F_31 ( V_46 , V_47 , V_51 , & V_53 ) ;
V_2 -> V_49 -> V_61 = 0 ;
}
F_6 ( V_2 , V_48 ) ;
if ( ( V_46 -> V_56 & V_57 ) &&
V_46 -> V_59 == V_46 -> V_60 &&
! F_37 ( V_2 ) &&
! V_53 )
F_38 ( V_46 -> V_60 ) ;
return error ;
}
STATIC T_4
F_39 (
struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_2 V_68 = F_40 ( V_66 ) ;
T_4 V_69 = 0 ;
int V_70 = 0 ;
T_5 V_71 ;
T_1 V_4 = V_64 -> V_72 ;
F_41 ( V_46 , V_73 ) ;
if ( F_42 ( V_64 -> V_74 & V_75 ) )
V_70 |= V_76 ;
if ( V_39 -> V_77 & V_78 )
V_70 |= V_79 ;
if ( ( V_70 & V_76 ) && ! F_11 ( V_52 ) ) {
T_6 * V_80 =
F_37 ( V_2 ) ?
V_46 -> V_58 : V_46 -> V_60 ;
if ( ( V_4 | V_68 ) & V_80 -> V_81 ) {
if ( V_4 == F_43 ( V_52 ) )
return 0 ;
return - V_82 ;
}
}
V_71 = V_46 -> V_83 -> V_84 - V_4 ;
if ( V_71 <= 0 || V_68 == 0 )
return 0 ;
if ( V_71 < V_68 )
V_68 = V_71 ;
if ( F_35 ( V_46 ) )
return - V_54 ;
F_1 ( V_2 , V_85 ) ;
if ( ( V_70 & V_76 ) && V_52 -> V_10 -> V_86 ) {
F_5 ( V_2 , V_85 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_52 -> V_10 -> V_86 ) {
V_69 = F_44 ( F_3 ( V_2 ) -> V_10 ) ;
if ( V_69 ) {
F_5 ( V_2 , V_3 ) ;
return V_69 ;
}
V_69 = F_45 ( F_3 ( V_2 ) -> V_10 ) ;
F_46 ( V_69 ) ;
V_69 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
F_47 ( V_2 , V_68 , V_4 , V_70 ) ;
V_69 = F_48 ( V_64 , V_66 ) ;
if ( V_69 > 0 )
F_49 ( V_46 , V_87 , V_69 ) ;
F_5 ( V_2 , V_85 ) ;
return V_69 ;
}
STATIC T_4
F_50 (
struct V_39 * V_88 ,
T_1 * V_89 ,
struct V_90 * V_91 ,
T_2 V_5 ,
unsigned int V_18 )
{
struct V_1 * V_2 = F_28 ( V_88 -> V_43 -> V_44 ) ;
int V_70 = 0 ;
T_4 V_69 ;
F_41 ( V_2 -> V_21 , V_73 ) ;
if ( V_88 -> V_77 & V_78 )
V_70 |= V_79 ;
if ( F_35 ( V_2 -> V_21 ) )
return - V_54 ;
F_51 ( V_2 , V_5 , * V_89 , V_70 ) ;
if ( F_11 ( F_3 ( V_2 ) ) ) {
V_69 = F_52 ( V_88 , V_89 , V_91 , V_5 ,
V_18 ) ;
goto V_92;
}
F_1 ( V_2 , V_85 ) ;
V_69 = F_53 ( V_88 , V_89 , V_91 , V_5 , V_18 ) ;
F_5 ( V_2 , V_85 ) ;
V_92:
if ( V_69 > 0 )
F_49 ( V_2 -> V_21 , V_87 , V_69 ) ;
return V_69 ;
}
STATIC int
F_54 (
struct V_1 * V_2 ,
T_5 V_11 ,
T_5 V_93 ,
bool * V_94 )
{
struct V_45 * V_46 = V_2 -> V_21 ;
T_7 V_95 = F_55 ( V_46 , V_93 ) ;
int V_96 = F_56 ( V_46 , V_93 ) ;
int V_97 ;
int V_98 = 1 ;
int error = 0 ;
struct V_99 V_100 ;
F_4 ( V_2 , V_24 ) ;
error = F_57 ( V_2 , V_95 , 1 , & V_100 , & V_98 , 0 ) ;
F_6 ( V_2 , V_24 ) ;
if ( error )
return error ;
ASSERT ( V_98 > 0 ) ;
if ( V_100 . V_101 == V_102 )
return 0 ;
V_97 = V_46 -> V_103 . V_104 - V_96 ;
if ( V_93 + V_97 > V_11 )
V_97 = V_11 - V_93 ;
* V_94 = true ;
return F_10 ( V_2 , V_93 , V_97 ) ;
}
int
F_58 (
struct V_1 * V_2 ,
T_8 V_11 ,
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
ASSERT ( F_59 ( V_2 , V_3 ) ) ;
ASSERT ( V_11 > V_93 ) ;
F_60 ( V_2 , V_93 , V_11 - V_93 ) ;
if ( F_56 ( V_46 , V_93 ) != 0 ) {
error = F_54 ( V_2 , V_11 , V_93 , V_94 ) ;
if ( error )
return error ;
}
V_95 = V_93 ? F_55 ( V_46 , V_93 - 1 ) : ( T_7 ) - 1 ;
V_105 = F_61 ( V_46 , ( V_109 ) V_93 ) ;
V_106 = F_55 ( V_46 , V_11 - 1 ) ;
ASSERT ( ( V_110 ) V_95 < ( V_110 ) V_105 ) ;
if ( V_95 == V_106 ) {
return 0 ;
}
ASSERT ( V_105 <= V_106 ) ;
while ( V_105 <= V_106 ) {
V_98 = 1 ;
V_107 = V_106 - V_105 + 1 ;
F_4 ( V_2 , V_24 ) ;
error = F_57 ( V_2 , V_105 , V_107 ,
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
V_108 = F_62 ( V_46 , V_105 ) ;
V_97 = F_62 ( V_46 , V_100 . V_114 ) ;
if ( ( V_108 + V_97 ) > V_11 )
V_97 = V_11 - V_108 ;
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
F_63 (
struct V_63 * V_64 ,
struct V_65 * V_115 ,
int * V_116 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
T_4 error = 0 ;
T_2 V_5 = F_40 ( V_115 ) ;
bool V_117 = false ;
V_118:
error = F_64 ( V_64 , V_115 ) ;
if ( error <= 0 )
return error ;
error = F_65 ( V_52 , V_116 , true ) ;
if ( error )
return error ;
if ( * V_116 == V_85 && ! F_66 ( V_52 ) ) {
F_5 ( V_2 , * V_116 ) ;
* V_116 = V_3 ;
F_1 ( V_2 , * V_116 ) ;
goto V_118;
}
F_67 ( & V_2 -> V_119 ) ;
if ( V_64 -> V_72 > F_43 ( V_52 ) ) {
bool V_120 = false ;
F_68 ( & V_2 -> V_119 ) ;
if ( ! V_117 ) {
if ( * V_116 == V_85 ) {
F_5 ( V_2 , * V_116 ) ;
* V_116 = V_3 ;
F_1 ( V_2 , * V_116 ) ;
F_69 ( V_115 , V_5 ) ;
}
F_70 ( V_52 ) ;
V_117 = true ;
goto V_118;
}
error = F_58 ( V_2 , V_64 -> V_72 , F_43 ( V_52 ) , & V_120 ) ;
if ( error )
return error ;
} else
F_68 ( & V_2 -> V_119 ) ;
if ( F_71 ( ! ( V_39 -> V_77 & V_78 ) ) ) {
error = F_72 ( V_39 ) ;
if ( error )
return error ;
}
if ( ! F_66 ( V_52 ) )
return F_73 ( V_39 ) ;
return 0 ;
}
STATIC T_4
F_74 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_7 * V_8 = V_39 -> V_43 ;
struct V_52 * V_52 = V_8 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_4 V_69 = 0 ;
int V_121 = 0 ;
int V_116 ;
T_2 V_5 = F_40 ( V_115 ) ;
T_1 V_4 = V_64 -> V_72 ;
T_1 V_41 ;
struct V_65 V_122 ;
struct V_123 * V_80 = F_37 ( V_2 ) ?
V_46 -> V_58 : V_46 -> V_60 ;
if ( ! F_11 ( V_52 ) && ( ( V_4 | V_5 ) & V_80 -> V_81 ) )
return - V_82 ;
if ( ( V_4 & V_46 -> V_124 ) || ( ( V_4 + V_5 ) & V_46 -> V_124 ) )
V_121 = 1 ;
if ( V_121 || V_8 -> V_86 )
V_116 = V_3 ;
else
V_116 = V_85 ;
F_1 ( V_2 , V_116 ) ;
if ( V_8 -> V_86 && V_116 == V_85 ) {
F_5 ( V_2 , V_116 ) ;
V_116 = V_3 ;
F_1 ( V_2 , V_116 ) ;
}
V_69 = F_63 ( V_64 , V_115 , & V_116 ) ;
if ( V_69 )
goto V_92;
V_5 = F_40 ( V_115 ) ;
V_4 = V_64 -> V_72 ;
V_41 = V_4 + V_5 - 1 ;
if ( V_8 -> V_86 ) {
V_69 = F_44 ( F_3 ( V_2 ) -> V_10 ) ;
if ( V_69 )
goto V_92;
V_69 = F_45 ( F_3 ( V_2 ) -> V_10 ) ;
F_46 ( V_69 ) ;
V_69 = 0 ;
}
if ( V_121 )
F_70 ( V_52 ) ;
else if ( V_116 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_116 = V_85 ;
}
F_75 ( V_2 , V_5 , V_64 -> V_72 , 0 ) ;
V_122 = * V_115 ;
V_69 = V_8 -> V_125 -> V_126 ( V_64 , & V_122 , V_4 ) ;
if ( V_8 -> V_86 ) {
F_76 ( V_8 ,
V_4 >> V_127 ,
V_41 >> V_127 ) ;
}
if ( V_69 > 0 ) {
V_4 += V_69 ;
F_77 ( V_115 , V_69 ) ;
V_64 -> V_72 = V_4 ;
}
V_92:
F_5 ( V_2 , V_116 ) ;
ASSERT ( V_69 < 0 || V_69 == V_5 || F_11 ( F_3 ( V_2 ) ) ) ;
return V_69 ;
}
STATIC T_4
F_78 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_7 * V_8 = V_39 -> V_43 ;
struct V_52 * V_52 = V_8 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
T_4 V_69 ;
int V_128 = 0 ;
int V_116 = V_3 ;
F_1 ( V_2 , V_116 ) ;
V_69 = F_63 ( V_64 , V_115 , & V_116 ) ;
if ( V_69 )
goto V_92;
V_129 -> V_130 = F_79 ( V_52 ) ;
V_131:
F_80 ( V_2 , F_40 ( V_115 ) ,
V_64 -> V_72 , 0 ) ;
V_69 = F_81 ( V_39 , V_115 , V_64 -> V_72 ) ;
if ( F_71 ( V_69 >= 0 ) )
V_64 -> V_72 += V_69 ;
if ( V_69 == - V_132 && ! V_128 ) {
V_128 = F_82 ( V_2 ) ;
if ( V_128 )
goto V_131;
} else if ( V_69 == - V_133 && ! V_128 ) {
struct V_134 V_135 = { 0 } ;
V_128 = 1 ;
F_83 ( V_2 -> V_21 ) ;
V_135 . V_136 = V_2 -> V_137 ;
V_135 . V_138 = V_139 ;
F_84 ( V_2 -> V_21 , & V_135 ) ;
goto V_131;
}
V_129 -> V_130 = NULL ;
V_92:
F_5 ( V_2 , V_116 ) ;
return V_69 ;
}
STATIC T_4
F_85 (
struct V_63 * V_64 ,
struct V_65 * V_115 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_7 * V_8 = V_39 -> V_43 ;
struct V_52 * V_52 = V_8 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
T_4 V_69 ;
T_2 V_140 = F_40 ( V_115 ) ;
F_41 ( V_2 -> V_21 , V_141 ) ;
if ( V_140 == 0 )
return 0 ;
if ( F_35 ( V_2 -> V_21 ) )
return - V_54 ;
if ( ( V_64 -> V_74 & V_75 ) || F_11 ( V_52 ) )
V_69 = F_74 ( V_64 , V_115 ) ;
else
V_69 = F_78 ( V_64 , V_115 ) ;
if ( V_69 > 0 ) {
T_4 V_142 ;
F_49 ( V_2 -> V_21 , V_143 , V_69 ) ;
V_142 = F_86 ( V_39 , V_64 -> V_72 - V_69 , V_69 ) ;
if ( V_142 < 0 )
V_69 = V_142 ;
}
return V_69 ;
}
STATIC long
F_87 (
struct V_39 * V_39 ,
int V_144 ,
T_1 V_11 ,
T_1 V_145 )
{
struct V_52 * V_52 = F_88 ( V_39 ) ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
long error ;
enum V_17 V_18 = 0 ;
T_9 V_116 = V_3 ;
T_1 V_146 = 0 ;
bool V_147 = 0 ;
if ( ! F_89 ( V_52 -> V_26 ) )
return - V_82 ;
if ( V_144 & ~ V_148 )
return - V_149 ;
F_4 ( V_2 , V_116 ) ;
error = F_65 ( V_52 , & V_116 , false ) ;
if ( error )
goto V_150;
F_4 ( V_2 , V_151 ) ;
V_116 |= V_151 ;
if ( V_144 & V_152 ) {
error = F_90 ( V_2 , V_11 , V_145 ) ;
if ( error )
goto V_150;
} else if ( V_144 & V_153 ) {
unsigned V_154 = ( 1 << V_52 -> V_155 ) - 1 ;
if ( V_11 & V_154 || V_145 & V_154 ) {
error = - V_82 ;
goto V_150;
}
if ( V_11 + V_145 >= F_43 ( V_52 ) ) {
error = - V_82 ;
goto V_150;
}
V_146 = F_43 ( V_52 ) - V_145 ;
error = F_91 ( V_2 , V_11 , V_145 ) ;
if ( error )
goto V_150;
} else if ( V_144 & V_156 ) {
unsigned V_154 = ( 1 << V_52 -> V_155 ) - 1 ;
V_146 = F_43 ( V_52 ) + V_145 ;
if ( V_11 & V_154 || V_145 & V_154 ) {
error = - V_82 ;
goto V_150;
}
if ( V_146 > V_52 -> V_157 -> V_84 ) {
error = - V_158 ;
goto V_150;
}
if ( V_11 >= F_43 ( V_52 ) ) {
error = - V_82 ;
goto V_150;
}
V_147 = 1 ;
} else {
V_18 |= V_32 ;
if ( ! ( V_144 & V_159 ) &&
V_11 + V_145 > F_43 ( V_52 ) ) {
V_146 = V_11 + V_145 ;
error = F_92 ( V_52 , V_146 ) ;
if ( error )
goto V_150;
}
if ( V_144 & V_160 )
error = F_93 ( V_2 , V_11 , V_145 ) ;
else
error = F_94 ( V_2 , V_11 , V_145 ,
V_161 ) ;
if ( error )
goto V_150;
}
if ( V_39 -> V_162 & V_163 )
V_18 |= V_38 ;
error = F_17 ( V_2 , V_18 ) ;
if ( error )
goto V_150;
if ( V_146 ) {
struct V_164 V_164 ;
V_164 . V_165 = V_166 ;
V_164 . V_167 = V_146 ;
error = F_95 ( V_2 , & V_164 ) ;
if ( error )
goto V_150;
}
if ( V_147 )
error = F_96 ( V_2 , V_11 , V_145 ) ;
V_150:
F_6 ( V_2 , V_116 ) ;
return error ;
}
STATIC int
F_97 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
if ( ! ( V_39 -> V_162 & V_168 ) && F_43 ( V_52 ) > V_169 )
return - V_158 ;
if ( F_35 ( F_98 ( V_52 -> V_157 ) ) )
return - V_54 ;
return 0 ;
}
STATIC int
F_99 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
struct V_1 * V_2 = F_28 ( V_52 ) ;
int V_144 ;
int error ;
error = F_97 ( V_52 , V_39 ) ;
if ( error )
return error ;
V_144 = F_100 ( V_2 ) ;
if ( V_2 -> V_33 . V_170 > 0 )
F_101 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_144 ) ;
return 0 ;
}
STATIC int
F_102 (
struct V_52 * V_52 ,
struct V_39 * V_171 )
{
return F_103 ( F_28 ( V_52 ) ) ;
}
STATIC int
F_104 (
struct V_39 * V_39 ,
struct V_172 * V_173 )
{
struct V_52 * V_52 = F_88 ( V_39 ) ;
T_10 * V_2 = F_28 ( V_52 ) ;
T_2 V_174 ;
V_174 = ( T_2 ) F_105 ( T_1 , 32768 , V_2 -> V_33 . V_175 ) ;
return F_106 ( V_2 , V_173 , V_174 ) ;
}
STATIC bool
F_107 (
struct V_6 * V_6 ,
T_1 * V_11 ,
unsigned int type )
{
T_1 V_176 = F_108 ( V_6 ) ;
bool V_177 = false ;
struct V_178 * V_179 , * V_180 ;
V_179 = V_180 = F_109 ( V_6 ) ;
do {
if ( F_110 ( V_179 ) ||
F_111 ( V_179 ) ) {
if ( type == V_181 )
V_177 = true ;
} else {
if ( type == V_182 )
V_177 = true ;
}
if ( V_177 ) {
* V_11 = V_176 ;
break;
}
V_176 += V_179 -> V_183 ;
} while ( ( V_179 = V_179 -> V_184 ) != V_180 );
return V_177 ;
}
STATIC bool
F_112 (
struct V_52 * V_52 ,
struct V_99 * V_185 ,
unsigned int type ,
T_1 * V_11 )
{
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
struct V_186 V_187 ;
T_11 V_188 ;
T_11 V_41 ;
T_1 V_189 ;
T_1 V_190 = * V_11 ;
T_1 V_176 = V_190 ;
bool V_177 = false ;
F_113 ( & V_187 , 0 ) ;
V_188 = V_190 >> V_127 ;
V_189 = F_62 ( V_46 , V_185 -> V_113 + V_185 -> V_114 ) ;
V_41 = V_189 >> V_127 ;
do {
int V_191 ;
unsigned V_192 ;
unsigned int V_193 ;
V_191 = F_105 ( T_11 , V_41 - V_188 , V_194 ) ;
V_192 = F_114 ( & V_187 , V_52 -> V_10 , V_188 ,
V_191 ) ;
if ( V_192 == 0 ) {
if ( type == V_181 )
break;
ASSERT ( type == V_182 ) ;
if ( V_176 == V_190 || V_176 < V_189 ) {
V_177 = true ;
* V_11 = V_176 ;
}
break;
}
if ( type == V_182 && V_176 == V_190 &&
V_176 < F_108 ( V_187 . V_195 [ 0 ] ) ) {
V_177 = true ;
break;
}
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ ) {
struct V_6 * V_6 = V_187 . V_195 [ V_193 ] ;
T_1 V_196 ;
if ( V_6 -> V_188 > V_41 ) {
if ( type == V_182 && V_176 < V_189 ) {
* V_11 = V_176 ;
V_177 = true ;
}
goto V_92;
}
F_115 ( V_6 ) ;
if ( F_42 ( V_6 -> V_8 != V_52 -> V_10 ) ) {
F_116 ( V_6 ) ;
continue;
}
if ( ! F_117 ( V_6 ) ) {
F_116 ( V_6 ) ;
continue;
}
V_177 = F_107 ( V_6 , & V_196 , type ) ;
if ( V_177 ) {
* V_11 = F_118 ( T_1 , V_190 , V_196 ) ;
F_116 ( V_6 ) ;
goto V_92;
}
V_176 = F_108 ( V_6 ) + V_14 ;
F_116 ( V_6 ) ;
}
if ( V_192 < V_191 ) {
if ( type == V_182 ) {
* V_11 = V_176 ;
V_177 = true ;
}
break;
}
V_188 = V_187 . V_195 [ V_193 - 1 ] -> V_188 + 1 ;
F_119 ( & V_187 ) ;
} while ( V_188 <= V_41 );
V_92:
F_119 ( & V_187 ) ;
return V_177 ;
}
T_1
F_120 (
struct V_52 * V_52 ,
T_1 V_40 ,
T_1 V_41 ,
int V_197 )
{
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_1 V_198 ( V_11 ) ;
T_7 V_199 ;
T_12 V_200 ;
int error ;
if ( V_40 >= V_41 ) {
error = - V_201 ;
goto V_202;
}
V_199 = F_55 ( V_46 , V_40 ) ;
V_200 = F_61 ( V_46 , V_41 ) ;
for (; ; ) {
struct V_99 V_185 [ 2 ] ;
int V_203 = 2 ;
unsigned int V_193 ;
error = F_57 ( V_2 , V_199 , V_200 - V_199 , V_185 , & V_203 ,
V_204 ) ;
if ( error )
goto V_202;
if ( V_203 == 0 ) {
error = - V_201 ;
goto V_202;
}
for ( V_193 = 0 ; V_193 < V_203 ; V_193 ++ ) {
V_11 = F_118 ( T_1 , V_40 ,
F_62 ( V_46 , V_185 [ V_193 ] . V_113 ) ) ;
if ( V_197 == V_205 &&
V_185 [ V_193 ] . V_101 == V_102 )
goto V_92;
if ( V_197 == V_206 &&
( V_185 [ V_193 ] . V_101 == V_207 ||
( V_185 [ V_193 ] . V_111 == V_208 &&
! F_121 ( V_185 [ V_193 ] . V_101 ) ) ) )
goto V_92;
if ( V_185 [ V_193 ] . V_111 == V_112 ) {
if ( F_112 ( V_52 , & V_185 [ V_193 ] ,
V_197 == V_205 ? V_182 : V_181 ,
& V_11 ) )
goto V_92;
}
}
if ( V_203 == 1 ) {
if ( V_197 == V_205 ) {
V_11 = V_41 ;
break;
}
ASSERT ( V_197 == V_206 ) ;
error = - V_201 ;
goto V_202;
}
ASSERT ( V_193 > 1 ) ;
V_199 = V_185 [ V_193 - 1 ] . V_113 + V_185 [ V_193 - 1 ] . V_114 ;
V_40 = F_62 ( V_46 , V_199 ) ;
if ( V_40 >= V_41 ) {
if ( V_197 == V_205 ) {
V_11 = V_41 ;
break;
}
ASSERT ( V_197 == V_206 ) ;
error = - V_201 ;
goto V_202;
}
}
V_92:
if ( V_197 == V_205 )
V_11 = F_105 ( T_1 , V_11 , V_41 ) ;
return V_11 ;
V_202:
return error ;
}
STATIC T_1
F_122 (
struct V_39 * V_39 ,
T_1 V_40 ,
int V_197 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_9 V_209 ;
T_1 V_11 , V_41 ;
int error = 0 ;
if ( F_35 ( V_46 ) )
return - V_54 ;
V_209 = F_100 ( V_2 ) ;
V_41 = F_43 ( V_52 ) ;
V_11 = F_120 ( V_52 , V_40 , V_41 , V_197 ) ;
if ( V_11 < 0 ) {
error = V_11 ;
goto V_150;
}
V_11 = F_123 ( V_39 , V_11 , V_52 -> V_157 -> V_84 ) ;
V_150:
F_6 ( V_2 , V_209 ) ;
if ( error )
return error ;
return V_11 ;
}
STATIC T_1
F_124 (
struct V_39 * V_39 ,
T_1 V_11 ,
int V_197 )
{
switch ( V_197 ) {
case V_210 :
case V_211 :
case V_212 :
return F_125 ( V_39 , V_11 , V_197 ) ;
case V_205 :
case V_206 :
return F_122 ( V_39 , V_11 , V_197 ) ;
default:
return - V_82 ;
}
}
STATIC int
F_126 (
struct V_213 * V_214 ,
struct V_215 * V_216 )
{
struct V_52 * V_52 = F_88 ( V_214 -> V_217 ) ;
int V_69 ;
F_127 ( F_28 ( V_52 ) ) ;
F_128 ( V_52 -> V_157 ) ;
F_72 ( V_214 -> V_217 ) ;
F_4 ( F_28 ( V_52 ) , V_218 ) ;
if ( F_11 ( V_52 ) ) {
V_69 = F_129 ( V_214 , V_216 , V_219 , NULL ) ;
} else {
V_69 = F_130 ( V_214 , V_216 , V_220 ) ;
V_69 = F_131 ( V_69 ) ;
}
F_6 ( F_28 ( V_52 ) , V_218 ) ;
F_132 ( V_52 -> V_157 ) ;
return V_69 ;
}
STATIC int
F_133 (
struct V_213 * V_214 ,
struct V_215 * V_216 )
{
struct V_52 * V_52 = F_88 ( V_214 -> V_217 ) ;
int V_69 ;
F_134 ( F_28 ( V_52 ) ) ;
if ( ( V_216 -> V_18 & V_221 ) && F_11 ( V_52 ) )
return F_126 ( V_214 , V_216 ) ;
F_4 ( F_28 ( V_52 ) , V_218 ) ;
if ( F_11 ( V_52 ) ) {
V_69 = F_135 ( V_214 , V_216 , V_219 , NULL ) ;
} else
V_69 = F_136 ( V_214 , V_216 ) ;
F_6 ( F_28 ( V_52 ) , V_218 ) ;
return V_69 ;
}
STATIC int
F_137 (
struct V_213 * V_214 ,
unsigned long V_222 ,
T_13 * V_223 ,
unsigned int V_18 )
{
struct V_52 * V_52 = F_88 ( V_214 -> V_217 ) ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
int V_69 ;
if ( ! F_11 ( V_52 ) )
return V_224 ;
F_138 ( V_2 ) ;
if ( V_18 & V_221 ) {
F_128 ( V_52 -> V_157 ) ;
F_72 ( V_214 -> V_217 ) ;
}
F_4 ( F_28 ( V_52 ) , V_218 ) ;
V_69 = F_139 ( V_214 , V_222 , V_223 , V_18 , V_219 ,
NULL ) ;
F_6 ( F_28 ( V_52 ) , V_218 ) ;
if ( V_18 & V_221 )
F_132 ( V_52 -> V_157 ) ;
return V_69 ;
}
static int
F_140 (
struct V_213 * V_214 ,
struct V_215 * V_216 )
{
struct V_52 * V_52 = F_88 ( V_214 -> V_217 ) ;
struct V_1 * V_2 = F_28 ( V_52 ) ;
int V_69 = V_225 ;
T_1 V_68 ;
F_141 ( V_2 ) ;
F_128 ( V_52 -> V_157 ) ;
F_72 ( V_214 -> V_217 ) ;
F_4 ( V_2 , V_218 ) ;
V_68 = ( F_43 ( V_52 ) + V_14 - 1 ) >> V_127 ;
if ( V_216 -> V_226 >= V_68 )
V_69 = V_227 ;
else if ( F_11 ( V_52 ) )
V_69 = F_142 ( V_214 , V_216 ) ;
F_6 ( V_2 , V_218 ) ;
F_132 ( V_52 -> V_157 ) ;
return V_69 ;
}
STATIC int
F_143 (
struct V_39 * V_171 ,
struct V_213 * V_214 )
{
F_144 ( V_171 ) ;
V_214 -> V_228 = & V_229 ;
if ( F_11 ( F_88 ( V_171 ) ) )
V_214 -> V_230 |= V_231 | V_232 ;
return 0 ;
}
