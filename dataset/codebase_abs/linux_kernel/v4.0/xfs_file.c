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
return ( - V_10 ) ;
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
if ( F_40 ( V_39 -> V_74 & V_75 ) )
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
struct V_39 * V_39 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_115 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
int error = 0 ;
V_116:
error = F_59 ( V_39 , V_5 , V_6 , F_60 ( V_52 -> V_117 ) ) ;
if ( error )
return error ;
error = F_61 ( V_52 , V_115 ) ;
if ( error )
return error ;
if ( * V_5 > F_41 ( V_52 ) ) {
bool V_118 = false ;
if ( * V_115 == V_85 ) {
F_5 ( V_2 , * V_115 ) ;
* V_115 = V_3 ;
F_1 ( V_2 , * V_115 ) ;
goto V_116;
}
error = F_54 ( V_2 , * V_5 , F_41 ( V_52 ) , & V_118 ) ;
if ( error )
return error ;
}
if ( F_62 ( ! ( V_39 -> V_77 & V_78 ) ) ) {
error = F_63 ( V_39 ) ;
if ( error )
return error ;
}
return F_64 ( V_39 ) ;
}
STATIC T_4
F_65 (
struct V_63 * V_64 ,
struct V_65 * V_119 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_4 V_69 = 0 ;
int V_120 = 0 ;
int V_115 ;
T_2 V_6 = F_38 ( V_119 ) ;
T_1 V_5 = V_64 -> V_72 ;
struct V_121 * V_80 = F_35 ( V_2 ) ?
V_46 -> V_58 : V_46 -> V_60 ;
if ( ( V_5 | V_6 ) & V_80 -> V_81 )
return - V_82 ;
if ( ( V_5 & V_46 -> V_122 ) || ( ( V_5 + V_6 ) & V_46 -> V_122 ) )
V_120 = 1 ;
if ( V_120 || V_9 -> V_86 )
V_115 = V_3 ;
else
V_115 = V_85 ;
F_1 ( V_2 , V_115 ) ;
if ( V_9 -> V_86 && V_115 == V_85 ) {
F_5 ( V_2 , V_115 ) ;
V_115 = V_3 ;
F_1 ( V_2 , V_115 ) ;
}
V_69 = F_58 ( V_39 , & V_5 , & V_6 , & V_115 ) ;
if ( V_69 )
goto V_123;
F_66 ( V_119 , V_6 ) ;
if ( V_9 -> V_86 ) {
V_69 = F_32 ( F_3 ( V_2 ) -> V_11 ,
V_5 , V_5 + V_6 - 1 ) ;
if ( V_69 )
goto V_123;
V_69 = F_42 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_87 ,
( V_5 + V_6 - 1 ) >> V_87 ) ;
F_43 ( V_69 ) ;
V_69 = 0 ;
}
if ( V_120 )
F_67 ( V_52 ) ;
else if ( V_115 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_115 = V_85 ;
}
F_68 ( V_2 , V_6 , V_64 -> V_72 , 0 ) ;
V_69 = F_69 ( V_64 , V_119 , V_5 ) ;
V_123:
F_5 ( V_2 , V_115 ) ;
ASSERT ( V_69 < 0 || V_69 == V_6 ) ;
return V_69 ;
}
STATIC T_4
F_70 (
struct V_63 * V_64 ,
struct V_65 * V_119 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 V_69 ;
int V_124 = 0 ;
int V_115 = V_3 ;
T_1 V_5 = V_64 -> V_72 ;
T_2 V_6 = F_38 ( V_119 ) ;
F_1 ( V_2 , V_115 ) ;
V_69 = F_58 ( V_39 , & V_5 , & V_6 , & V_115 ) ;
if ( V_69 )
goto V_123;
F_66 ( V_119 , V_6 ) ;
V_125 -> V_126 = F_71 ( V_52 ) ;
V_127:
F_72 ( V_2 , V_6 , V_64 -> V_72 , 0 ) ;
V_69 = F_73 ( V_39 , V_119 , V_5 ) ;
if ( F_62 ( V_69 >= 0 ) )
V_64 -> V_72 = V_5 + V_69 ;
if ( V_69 == - V_128 && ! V_124 ) {
V_124 = F_74 ( V_2 ) ;
if ( V_124 )
goto V_127;
} else if ( V_69 == - V_129 && ! V_124 ) {
struct V_130 V_131 = { 0 } ;
V_124 = 1 ;
F_75 ( V_2 -> V_21 ) ;
V_131 . V_132 = V_2 -> V_133 ;
V_131 . V_134 = V_135 ;
F_76 ( V_2 -> V_21 , & V_131 ) ;
goto V_127;
}
V_125 -> V_126 = NULL ;
V_123:
F_5 ( V_2 , V_115 ) ;
return V_69 ;
}
STATIC T_4
F_77 (
struct V_63 * V_64 ,
struct V_65 * V_119 )
{
struct V_39 * V_39 = V_64 -> V_67 ;
struct V_8 * V_9 = V_39 -> V_43 ;
struct V_52 * V_52 = V_9 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 V_69 ;
T_2 V_136 = F_38 ( V_119 ) ;
F_39 ( V_137 ) ;
if ( V_136 == 0 )
return 0 ;
if ( F_33 ( V_2 -> V_21 ) )
return - V_54 ;
if ( F_40 ( V_39 -> V_74 & V_75 ) )
V_69 = F_65 ( V_64 , V_119 ) ;
else
V_69 = F_70 ( V_64 , V_119 ) ;
if ( V_69 > 0 ) {
T_4 V_138 ;
F_46 ( V_139 , V_69 ) ;
V_138 = F_78 ( V_39 , V_64 -> V_72 - V_69 , V_69 ) ;
if ( V_138 < 0 )
V_69 = V_138 ;
}
return V_69 ;
}
STATIC long
F_79 (
struct V_39 * V_39 ,
int V_140 ,
T_1 V_12 ,
T_1 V_141 )
{
struct V_52 * V_52 = F_80 ( V_39 ) ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
long error ;
enum V_17 V_18 = 0 ;
T_9 V_115 = V_3 ;
T_1 V_142 = 0 ;
if ( ! F_81 ( V_52 -> V_117 ) )
return - V_82 ;
if ( V_140 & ~ ( V_143 | V_144 |
V_145 | V_146 ) )
return - V_147 ;
F_4 ( V_2 , V_115 ) ;
error = F_61 ( V_52 , & V_115 ) ;
if ( error )
goto V_148;
if ( V_140 & V_144 ) {
error = F_82 ( V_2 , V_12 , V_141 ) ;
if ( error )
goto V_148;
} else if ( V_140 & V_145 ) {
unsigned V_149 = ( 1 << V_52 -> V_150 ) - 1 ;
if ( V_12 & V_149 || V_141 & V_149 ) {
error = - V_82 ;
goto V_148;
}
if ( V_12 + V_141 >= F_41 ( V_52 ) ) {
error = - V_82 ;
goto V_148;
}
V_142 = F_41 ( V_52 ) - V_141 ;
error = F_83 ( V_2 , V_12 , V_141 ) ;
if ( error )
goto V_148;
} else {
V_18 |= V_33 ;
if ( ! ( V_140 & V_143 ) &&
V_12 + V_141 > F_41 ( V_52 ) ) {
V_142 = V_12 + V_141 ;
error = F_84 ( V_52 , V_142 ) ;
if ( error )
goto V_148;
}
if ( V_140 & V_146 )
error = F_85 ( V_2 , V_12 , V_141 ) ;
else
error = F_86 ( V_2 , V_12 , V_141 ,
V_151 ) ;
if ( error )
goto V_148;
}
if ( V_39 -> V_74 & V_152 )
V_18 |= V_38 ;
error = F_15 ( V_2 , V_18 ) ;
if ( error )
goto V_148;
if ( V_142 ) {
struct V_153 V_153 ;
V_153 . V_154 = V_155 ;
V_153 . V_156 = V_142 ;
error = F_87 ( V_2 , & V_153 ) ;
}
V_148:
F_6 ( V_2 , V_115 ) ;
return error ;
}
STATIC int
F_88 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
if ( ! ( V_39 -> V_74 & V_157 ) && F_41 ( V_52 ) > V_158 )
return - V_159 ;
if ( F_33 ( F_89 ( V_52 -> V_160 ) ) )
return - V_54 ;
return 0 ;
}
STATIC int
F_90 (
struct V_52 * V_52 ,
struct V_39 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
int V_140 ;
int error ;
error = F_88 ( V_52 , V_39 ) ;
if ( error )
return error ;
V_140 = F_91 ( V_2 ) ;
if ( V_2 -> V_26 . V_161 > 0 )
F_92 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_140 ) ;
return 0 ;
}
STATIC int
F_93 (
struct V_52 * V_52 ,
struct V_39 * V_162 )
{
return F_94 ( F_26 ( V_52 ) ) ;
}
STATIC int
F_95 (
struct V_39 * V_39 ,
struct V_163 * V_164 )
{
struct V_52 * V_52 = F_80 ( V_39 ) ;
T_10 * V_2 = F_26 ( V_52 ) ;
T_2 V_165 ;
V_165 = ( T_2 ) F_96 ( T_1 , 32768 , V_2 -> V_26 . V_166 ) ;
return F_97 ( V_2 , V_164 , V_165 ) ;
}
STATIC int
F_98 (
struct V_39 * V_162 ,
struct V_167 * V_168 )
{
V_168 -> V_169 = & V_170 ;
F_99 ( V_162 ) ;
return 0 ;
}
STATIC int
F_100 (
struct V_167 * V_168 ,
struct V_171 * V_172 )
{
return F_101 ( V_168 , V_172 , V_173 ) ;
}
STATIC bool
F_102 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_174 = F_103 ( V_7 ) ;
bool V_175 = false ;
struct V_176 * V_177 , * V_178 ;
V_177 = V_178 = F_104 ( V_7 ) ;
do {
if ( F_105 ( V_177 ) ||
F_106 ( V_177 ) ) {
if ( type == V_179 )
V_175 = true ;
} else {
if ( type == V_180 )
V_175 = true ;
}
if ( V_175 ) {
* V_12 = V_174 ;
break;
}
V_174 += V_177 -> V_181 ;
} while ( ( V_177 = V_177 -> V_182 ) != V_178 );
return V_175 ;
}
STATIC bool
F_107 (
struct V_52 * V_52 ,
struct V_99 * V_183 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
struct V_184 V_185 ;
T_11 V_186 ;
T_11 V_41 ;
T_1 V_187 ;
T_1 V_188 = * V_12 ;
T_1 V_174 = V_188 ;
bool V_175 = false ;
F_108 ( & V_185 , 0 ) ;
V_186 = V_188 >> V_87 ;
V_187 = F_57 ( V_46 , V_183 -> V_113 + V_183 -> V_114 ) ;
V_41 = V_187 >> V_87 ;
do {
int V_189 ;
unsigned V_190 ;
unsigned int V_191 ;
V_189 = F_96 ( T_11 , V_41 - V_186 , V_192 ) ;
V_190 = F_109 ( & V_185 , V_52 -> V_11 , V_186 ,
V_189 ) ;
if ( V_190 == 0 ) {
if ( type == V_179 )
break;
ASSERT ( type == V_180 ) ;
if ( V_174 == V_188 || V_174 < V_187 ) {
V_175 = true ;
* V_12 = V_174 ;
}
break;
}
if ( type == V_180 && V_174 == V_188 &&
V_174 < F_103 ( V_185 . V_193 [ 0 ] ) ) {
V_175 = true ;
break;
}
for ( V_191 = 0 ; V_191 < V_190 ; V_191 ++ ) {
struct V_7 * V_7 = V_185 . V_193 [ V_191 ] ;
T_1 V_194 ;
if ( V_7 -> V_186 > V_41 ) {
if ( type == V_180 && V_174 < V_187 ) {
* V_12 = V_174 ;
V_175 = true ;
}
goto V_123;
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
V_175 = F_102 ( V_7 , & V_194 , type ) ;
if ( V_175 ) {
* V_12 = F_113 ( T_1 , V_188 , V_194 ) ;
F_111 ( V_7 ) ;
goto V_123;
}
V_174 = F_103 ( V_7 ) + V_195 ;
F_111 ( V_7 ) ;
}
if ( V_190 < V_189 ) {
if ( type == V_180 ) {
* V_12 = V_174 ;
V_175 = true ;
}
break;
}
V_186 = V_185 . V_193 [ V_191 - 1 ] -> V_186 + 1 ;
F_114 ( & V_185 ) ;
} while ( V_186 <= V_41 );
V_123:
F_114 ( & V_185 ) ;
return V_175 ;
}
STATIC T_1
F_115 (
struct V_39 * V_39 ,
T_1 V_40 ,
int V_196 )
{
struct V_52 * V_52 = V_39 -> V_43 -> V_44 ;
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_45 * V_46 = V_2 -> V_21 ;
T_1 V_197 ( V_12 ) ;
T_5 V_93 ;
T_7 V_198 ;
T_12 V_41 ;
T_9 V_199 ;
int error ;
if ( F_33 ( V_46 ) )
return - V_54 ;
V_199 = F_91 ( V_2 ) ;
V_93 = F_41 ( V_52 ) ;
if ( V_40 >= V_93 ) {
error = - V_200 ;
goto V_148;
}
V_198 = F_51 ( V_46 , V_40 ) ;
V_41 = F_56 ( V_46 , V_93 ) ;
for (; ; ) {
struct V_99 V_183 [ 2 ] ;
int V_201 = 2 ;
unsigned int V_191 ;
error = F_53 ( V_2 , V_198 , V_41 - V_198 , V_183 , & V_201 ,
V_202 ) ;
if ( error )
goto V_148;
if ( V_201 == 0 ) {
error = - V_200 ;
goto V_148;
}
for ( V_191 = 0 ; V_191 < V_201 ; V_191 ++ ) {
V_12 = F_113 ( T_1 , V_40 ,
F_57 ( V_46 , V_183 [ V_191 ] . V_113 ) ) ;
if ( V_196 == V_203 &&
V_183 [ V_191 ] . V_101 == V_102 )
goto V_123;
if ( V_196 == V_204 &&
( V_183 [ V_191 ] . V_101 == V_205 ||
( V_183 [ V_191 ] . V_111 == V_206 &&
! F_116 ( V_183 [ V_191 ] . V_101 ) ) ) )
goto V_123;
if ( V_183 [ V_191 ] . V_111 == V_112 ) {
if ( F_107 ( V_52 , & V_183 [ V_191 ] ,
V_196 == V_203 ? V_180 : V_179 ,
& V_12 ) )
goto V_123;
}
}
if ( V_201 == 1 ) {
if ( V_196 == V_203 ) {
V_12 = V_93 ;
break;
}
ASSERT ( V_196 == V_204 ) ;
error = - V_200 ;
goto V_148;
}
ASSERT ( V_191 > 1 ) ;
V_198 = V_183 [ V_191 - 1 ] . V_113 + V_183 [ V_191 - 1 ] . V_114 ;
V_40 = F_57 ( V_46 , V_198 ) ;
if ( V_40 >= V_93 ) {
if ( V_196 == V_203 ) {
V_12 = V_93 ;
break;
}
ASSERT ( V_196 == V_204 ) ;
error = - V_200 ;
goto V_148;
}
}
V_123:
if ( V_196 == V_203 )
V_12 = F_96 ( T_1 , V_12 , V_93 ) ;
V_12 = F_117 ( V_39 , V_12 , V_52 -> V_160 -> V_84 ) ;
V_148:
F_6 ( V_2 , V_199 ) ;
if ( error )
return error ;
return V_12 ;
}
STATIC T_1
F_118 (
struct V_39 * V_39 ,
T_1 V_12 ,
int V_196 )
{
switch ( V_196 ) {
case V_207 :
case V_208 :
case V_209 :
return F_119 ( V_39 , V_12 , V_196 ) ;
case V_203 :
case V_204 :
return F_115 ( V_39 , V_12 , V_196 ) ;
default:
return - V_82 ;
}
}
