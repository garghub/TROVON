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
STATIC int
F_15 (
struct V_17 * V_17 ,
T_1 V_18 ,
T_1 V_19 ,
int V_20 )
{
struct V_1 * V_2 = F_16 ( V_17 -> V_21 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_3 V_26 = 0 ;
F_17 ( V_2 ) ;
F_4 ( V_2 , V_27 ) ;
if ( F_18 ( V_2 ) )
V_26 = V_2 -> V_28 -> V_29 ;
F_6 ( V_2 , V_27 ) ;
if ( ! V_26 )
return 0 ;
return F_19 ( V_24 , V_26 , V_30 , NULL ) ;
}
STATIC int
F_20 (
struct V_17 * V_17 ,
T_1 V_18 ,
T_1 V_19 ,
int V_20 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int error = 0 ;
int V_32 = 0 ;
T_3 V_26 = 0 ;
F_21 ( V_2 ) ;
error = F_22 ( V_31 -> V_11 , V_18 , V_19 ) ;
if ( error )
return error ;
if ( F_23 ( V_24 ) )
return - V_33 ;
F_24 ( V_2 , V_34 ) ;
if ( V_24 -> V_35 & V_36 ) {
if ( F_25 ( V_2 ) )
F_26 ( V_24 -> V_37 ) ;
else if ( V_24 -> V_38 != V_24 -> V_39 )
F_26 ( V_24 -> V_39 ) ;
}
F_4 ( V_2 , V_27 ) ;
if ( F_18 ( V_2 ) ) {
if ( ! V_20 ||
( V_2 -> V_28 -> V_40 & ~ V_41 ) )
V_26 = V_2 -> V_28 -> V_29 ;
}
F_6 ( V_2 , V_27 ) ;
if ( V_26 )
error = F_19 ( V_24 , V_26 , V_30 , & V_32 ) ;
if ( ( V_24 -> V_35 & V_36 ) &&
V_24 -> V_38 == V_24 -> V_39 &&
! F_25 ( V_2 ) &&
! V_32 )
F_26 ( V_24 -> V_39 ) ;
return error ;
}
STATIC T_4
F_27 (
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_2 V_47 = F_28 ( V_45 ) ;
T_4 V_48 = 0 ;
int V_49 = 0 ;
T_5 V_50 ;
T_1 V_5 = V_43 -> V_51 ;
F_29 ( V_52 ) ;
if ( F_30 ( V_17 -> V_53 & V_54 ) )
V_49 |= V_55 ;
if ( V_17 -> V_56 & V_57 )
V_49 |= V_58 ;
if ( F_30 ( V_49 & V_55 ) ) {
T_6 * V_59 =
F_25 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 | V_47 ) & V_59 -> V_60 ) {
if ( V_5 == F_31 ( V_31 ) )
return 0 ;
return - V_61 ;
}
}
V_50 = V_24 -> V_62 -> V_63 - V_5 ;
if ( V_50 <= 0 || V_47 == 0 )
return 0 ;
if ( V_50 < V_47 )
V_47 = V_50 ;
if ( F_23 ( V_24 ) )
return - V_33 ;
F_1 ( V_2 , V_64 ) ;
if ( ( V_49 & V_55 ) && V_31 -> V_11 -> V_65 ) {
F_5 ( V_2 , V_64 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_31 -> V_11 -> V_65 ) {
V_48 = F_22 (
F_3 ( V_2 ) -> V_11 ,
V_5 , V_5 + V_47 - 1 ) ;
if ( V_48 ) {
F_5 ( V_2 , V_3 ) ;
return V_48 ;
}
V_48 = F_32 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_66 ,
( V_5 + V_47 - 1 ) >> V_66 ) ;
F_33 ( V_48 ) ;
V_48 = 0 ;
}
F_8 ( V_2 , V_3 ) ;
}
F_34 ( V_2 , V_47 , V_5 , V_49 ) ;
V_48 = F_35 ( V_43 , V_45 ) ;
if ( V_48 > 0 )
F_36 ( V_67 , V_48 ) ;
F_5 ( V_2 , V_64 ) ;
return V_48 ;
}
STATIC T_4
F_37 (
struct V_17 * V_68 ,
T_1 * V_69 ,
struct V_70 * V_71 ,
T_2 V_6 ,
unsigned int V_72 )
{
struct V_1 * V_2 = F_16 ( V_68 -> V_21 -> V_22 ) ;
int V_49 = 0 ;
T_4 V_48 ;
F_29 ( V_52 ) ;
if ( V_68 -> V_56 & V_57 )
V_49 |= V_58 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_1 ( V_2 , V_64 ) ;
F_38 ( V_2 , V_6 , * V_69 , V_49 ) ;
V_48 = F_39 ( V_68 , V_69 , V_71 , V_6 , V_72 ) ;
if ( V_48 > 0 )
F_36 ( V_67 , V_48 ) ;
F_5 ( V_2 , V_64 ) ;
return V_48 ;
}
STATIC int
F_40 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_73 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_74 = F_41 ( V_24 , V_73 ) ;
int V_75 = F_42 ( V_24 , V_73 ) ;
int V_76 ;
int V_77 = 1 ;
int error = 0 ;
struct V_78 V_79 ;
F_4 ( V_2 , V_80 ) ;
error = F_43 ( V_2 , V_74 , 1 , & V_79 , & V_77 , 0 ) ;
F_6 ( V_2 , V_80 ) ;
if ( error )
return error ;
ASSERT ( V_77 > 0 ) ;
if ( V_79 . V_81 == V_82 )
return 0 ;
V_76 = V_24 -> V_83 . V_84 - V_75 ;
if ( V_73 + V_76 > V_12 )
V_76 = V_12 - V_73 ;
return F_10 ( V_2 , V_73 , V_76 ) ;
}
int
F_44 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_73 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_85 ;
T_7 V_86 ;
T_7 V_87 ;
T_7 V_74 ;
T_7 V_88 ;
T_5 V_76 ;
int V_77 ;
int error = 0 ;
struct V_78 V_79 ;
ASSERT ( F_45 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_73 ) ;
if ( F_42 ( V_24 , V_73 ) != 0 ) {
error = F_40 ( V_2 , V_12 , V_73 ) ;
if ( error )
return error ;
}
V_74 = V_73 ? F_41 ( V_24 , V_73 - 1 ) : ( T_7 ) - 1 ;
V_85 = F_46 ( V_24 , ( V_89 ) V_73 ) ;
V_86 = F_41 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_90 ) V_74 < ( V_90 ) V_85 ) ;
if ( V_74 == V_86 ) {
return 0 ;
}
ASSERT ( V_85 <= V_86 ) ;
while ( V_85 <= V_86 ) {
V_77 = 1 ;
V_87 = V_86 - V_85 + 1 ;
F_4 ( V_2 , V_80 ) ;
error = F_43 ( V_2 , V_85 , V_87 ,
& V_79 , & V_77 , 0 ) ;
F_6 ( V_2 , V_80 ) ;
if ( error )
return error ;
ASSERT ( V_77 > 0 ) ;
if ( V_79 . V_91 == V_92 ||
V_79 . V_81 == V_82 ) {
V_85 = V_79 . V_93 + V_79 . V_94 ;
ASSERT ( V_85 <= ( V_86 + 1 ) ) ;
continue;
}
V_88 = F_47 ( V_24 , V_85 ) ;
V_76 = F_47 ( V_24 , V_79 . V_94 ) ;
if ( ( V_88 + V_76 ) > V_12 )
V_76 = V_12 - V_88 ;
error = F_10 ( V_2 , V_88 , V_76 ) ;
if ( error )
return error ;
V_85 = V_79 . V_93 + V_79 . V_94 ;
ASSERT ( V_85 <= ( V_86 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_48 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_95 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int error = 0 ;
V_96:
error = F_49 ( V_17 , V_5 , V_6 , F_50 ( V_31 -> V_97 ) ) ;
if ( error )
return error ;
if ( * V_5 > F_31 ( V_31 ) ) {
if ( * V_95 == V_64 ) {
F_5 ( V_2 , * V_95 ) ;
* V_95 = V_3 ;
F_1 ( V_2 , * V_95 ) ;
goto V_96;
}
error = F_44 ( V_2 , * V_5 , F_31 ( V_31 ) ) ;
if ( error )
return error ;
}
if ( F_51 ( ! ( V_17 -> V_56 & V_57 ) ) ) {
error = F_52 ( V_17 ) ;
if ( error )
return error ;
}
return F_53 ( V_17 ) ;
}
STATIC T_4
F_54 (
struct V_42 * V_43 ,
struct V_44 * V_98 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_48 = 0 ;
int V_99 = 0 ;
int V_95 ;
T_2 V_6 = F_28 ( V_98 ) ;
T_1 V_5 = V_43 -> V_51 ;
struct V_100 * V_59 = F_25 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 | V_6 ) & V_59 -> V_60 )
return - V_61 ;
if ( ( V_5 & V_24 -> V_101 ) || ( ( V_5 + V_6 ) & V_24 -> V_101 ) )
V_99 = 1 ;
if ( V_99 || V_9 -> V_65 )
V_95 = V_3 ;
else
V_95 = V_64 ;
F_1 ( V_2 , V_95 ) ;
if ( V_9 -> V_65 && V_95 == V_64 ) {
F_5 ( V_2 , V_95 ) ;
V_95 = V_3 ;
F_1 ( V_2 , V_95 ) ;
}
V_48 = F_48 ( V_17 , & V_5 , & V_6 , & V_95 ) ;
if ( V_48 )
goto V_102;
F_55 ( V_98 , V_6 ) ;
if ( V_9 -> V_65 ) {
V_48 = F_22 ( F_3 ( V_2 ) -> V_11 ,
V_5 , V_5 + V_6 - 1 ) ;
if ( V_48 )
goto V_102;
V_48 = F_32 ( F_3 ( V_2 ) -> V_11 ,
V_5 >> V_66 ,
( V_5 + V_6 - 1 ) >> V_66 ) ;
F_33 ( V_48 ) ;
V_48 = 0 ;
}
if ( V_99 )
F_56 ( V_31 ) ;
else if ( V_95 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_95 = V_64 ;
}
F_57 ( V_2 , V_6 , V_43 -> V_51 , 0 ) ;
V_48 = F_58 ( V_43 , V_98 , V_5 ) ;
V_102:
F_5 ( V_2 , V_95 ) ;
ASSERT ( V_48 < 0 || V_48 == V_6 ) ;
return V_48 ;
}
STATIC T_4
F_59 (
struct V_42 * V_43 ,
struct V_44 * V_98 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_48 ;
int V_103 = 0 ;
int V_95 = V_3 ;
T_1 V_5 = V_43 -> V_51 ;
T_2 V_6 = F_28 ( V_98 ) ;
F_1 ( V_2 , V_95 ) ;
V_48 = F_48 ( V_17 , & V_5 , & V_6 , & V_95 ) ;
if ( V_48 )
goto V_102;
F_55 ( V_98 , V_6 ) ;
V_104 -> V_105 = V_9 -> V_105 ;
V_106:
F_60 ( V_2 , V_6 , V_43 -> V_51 , 0 ) ;
V_48 = F_61 ( V_17 , V_98 , V_5 ) ;
if ( F_51 ( V_48 >= 0 ) )
V_43 -> V_51 = V_5 + V_48 ;
if ( V_48 == - V_107 && ! V_103 ) {
V_103 = F_62 ( V_2 ) ;
if ( V_103 )
goto V_106;
} else if ( V_48 == - V_108 && ! V_103 ) {
struct V_109 V_110 = { 0 } ;
V_103 = 1 ;
F_63 ( V_2 -> V_25 ) ;
V_110 . V_111 = V_2 -> V_112 ;
V_110 . V_113 = V_114 ;
F_64 ( V_2 -> V_25 , & V_110 ) ;
goto V_106;
}
V_104 -> V_105 = NULL ;
V_102:
F_5 ( V_2 , V_95 ) ;
return V_48 ;
}
STATIC T_4
F_65 (
struct V_42 * V_43 ,
struct V_44 * V_98 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_48 ;
T_2 V_115 = F_28 ( V_98 ) ;
F_29 ( V_116 ) ;
if ( V_115 == 0 )
return 0 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
if ( F_30 ( V_17 -> V_53 & V_54 ) )
V_48 = F_54 ( V_43 , V_98 ) ;
else
V_48 = F_59 ( V_43 , V_98 ) ;
if ( V_48 > 0 ) {
T_4 V_117 ;
F_36 ( V_118 , V_48 ) ;
V_117 = F_66 ( V_17 , V_43 -> V_51 - V_48 , V_48 ) ;
if ( V_117 < 0 )
V_48 = V_117 ;
}
return V_48 ;
}
STATIC long
F_67 (
struct V_17 * V_17 ,
int V_119 ,
T_1 V_12 ,
T_1 V_120 )
{
struct V_31 * V_31 = F_68 ( V_17 ) ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_121 * V_122 ;
long error ;
T_1 V_123 = 0 ;
if ( ! F_69 ( V_31 -> V_97 ) )
return - V_61 ;
if ( V_119 & ~ ( V_124 | V_125 |
V_126 | V_127 ) )
return - V_128 ;
F_4 ( V_2 , V_3 ) ;
if ( V_119 & V_125 ) {
error = F_70 ( V_2 , V_12 , V_120 ) ;
if ( error )
goto V_129;
} else if ( V_119 & V_126 ) {
unsigned V_130 = ( 1 << V_31 -> V_131 ) - 1 ;
if ( V_12 & V_130 || V_120 & V_130 ) {
error = - V_61 ;
goto V_129;
}
if ( V_12 + V_120 >= F_31 ( V_31 ) ) {
error = - V_61 ;
goto V_129;
}
V_123 = F_31 ( V_31 ) - V_120 ;
error = F_71 ( V_2 , V_12 , V_120 ) ;
if ( error )
goto V_129;
} else {
if ( ! ( V_119 & V_124 ) &&
V_12 + V_120 > F_31 ( V_31 ) ) {
V_123 = V_12 + V_120 ;
error = F_72 ( V_31 , V_123 ) ;
if ( error )
goto V_129;
}
if ( V_119 & V_127 )
error = F_73 ( V_2 , V_12 , V_120 ) ;
else
error = F_74 ( V_2 , V_12 , V_120 ,
V_132 ) ;
if ( error )
goto V_129;
}
V_122 = F_75 ( V_2 -> V_25 , V_133 ) ;
error = F_76 ( V_122 , & F_77 ( V_2 -> V_25 ) -> V_134 , 0 , 0 ) ;
if ( error ) {
F_78 ( V_122 , 0 ) ;
goto V_129;
}
F_4 ( V_2 , V_80 ) ;
F_79 ( V_122 , V_2 , V_80 ) ;
V_2 -> V_135 . V_136 &= ~ V_137 ;
if ( V_2 -> V_135 . V_136 & V_138 )
V_2 -> V_135 . V_136 &= ~ V_139 ;
if ( ! ( V_119 & ( V_125 | V_126 ) ) )
V_2 -> V_135 . V_140 |= V_141 ;
F_80 ( V_122 , V_2 , V_142 | V_143 ) ;
F_81 ( V_122 , V_2 , V_144 ) ;
if ( V_17 -> V_53 & V_145 )
F_82 ( V_122 ) ;
error = F_83 ( V_122 , 0 ) ;
if ( error )
goto V_129;
if ( V_123 ) {
struct V_146 V_146 ;
V_146 . V_147 = V_148 ;
V_146 . V_149 = V_123 ;
error = F_84 ( V_2 , & V_146 ) ;
}
V_129:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_85 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_53 & V_150 ) && F_31 ( V_31 ) > V_151 )
return - V_152 ;
if ( F_23 ( F_86 ( V_31 -> V_153 ) ) )
return - V_33 ;
return 0 ;
}
STATIC int
F_87 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_119 ;
int error ;
error = F_85 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_119 = F_88 ( V_2 ) ;
if ( V_2 -> V_135 . V_154 > 0 )
F_89 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_119 ) ;
return 0 ;
}
STATIC int
F_90 (
struct V_31 * V_31 ,
struct V_17 * V_155 )
{
return F_91 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_92 (
struct V_17 * V_17 ,
struct V_156 * V_157 )
{
struct V_31 * V_31 = F_68 ( V_17 ) ;
T_9 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_158 ;
V_158 = ( T_2 ) F_93 ( T_1 , 32768 , V_2 -> V_135 . V_159 ) ;
error = F_94 ( V_2 , V_157 , V_158 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_95 (
struct V_17 * V_155 ,
struct V_160 * V_161 )
{
V_161 -> V_162 = & V_163 ;
F_96 ( V_155 ) ;
return 0 ;
}
STATIC int
F_97 (
struct V_160 * V_161 ,
struct V_164 * V_165 )
{
return F_98 ( V_161 , V_165 , V_166 ) ;
}
STATIC bool
F_99 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_167 = F_100 ( V_7 ) ;
bool V_168 = false ;
struct V_169 * V_170 , * V_171 ;
V_170 = V_171 = F_101 ( V_7 ) ;
do {
if ( F_102 ( V_170 ) ||
F_103 ( V_170 ) ) {
if ( type == V_172 )
V_168 = true ;
} else {
if ( type == V_173 )
V_168 = true ;
}
if ( V_168 ) {
* V_12 = V_167 ;
break;
}
V_167 += V_170 -> V_174 ;
} while ( ( V_170 = V_170 -> V_175 ) != V_171 );
return V_168 ;
}
STATIC bool
F_104 (
struct V_31 * V_31 ,
struct V_78 * V_176 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_177 V_178 ;
T_10 V_179 ;
T_10 V_19 ;
T_1 V_180 ;
T_1 V_181 = * V_12 ;
T_1 V_167 = V_181 ;
bool V_168 = false ;
F_105 ( & V_178 , 0 ) ;
V_179 = V_181 >> V_66 ;
V_180 = F_47 ( V_24 , V_176 -> V_93 + V_176 -> V_94 ) ;
V_19 = V_180 >> V_66 ;
do {
int V_182 ;
unsigned V_183 ;
unsigned int V_184 ;
V_182 = F_93 ( T_10 , V_19 - V_179 , V_185 ) ;
V_183 = F_106 ( & V_178 , V_31 -> V_11 , V_179 ,
V_182 ) ;
if ( V_183 == 0 ) {
if ( type == V_172 )
break;
ASSERT ( type == V_173 ) ;
if ( V_167 == V_181 || V_167 < V_180 ) {
V_168 = true ;
* V_12 = V_167 ;
}
break;
}
if ( type == V_173 && V_167 == V_181 &&
V_167 < F_100 ( V_178 . V_186 [ 0 ] ) ) {
V_168 = true ;
break;
}
for ( V_184 = 0 ; V_184 < V_183 ; V_184 ++ ) {
struct V_7 * V_7 = V_178 . V_186 [ V_184 ] ;
T_1 V_187 ;
if ( V_7 -> V_179 > V_19 ) {
if ( type == V_173 && V_167 < V_180 ) {
* V_12 = V_167 ;
V_168 = true ;
}
goto V_102;
}
F_107 ( V_7 ) ;
if ( F_30 ( V_7 -> V_9 != V_31 -> V_11 ) ) {
F_108 ( V_7 ) ;
continue;
}
if ( ! F_109 ( V_7 ) ) {
F_108 ( V_7 ) ;
continue;
}
V_168 = F_99 ( V_7 , & V_187 , type ) ;
if ( V_168 ) {
* V_12 = F_110 ( T_1 , V_181 , V_187 ) ;
F_108 ( V_7 ) ;
goto V_102;
}
V_167 = F_100 ( V_7 ) + V_188 ;
F_108 ( V_7 ) ;
}
if ( V_183 < V_182 ) {
if ( type == V_173 ) {
* V_12 = V_167 ;
V_168 = true ;
}
break;
}
V_179 = V_178 . V_186 [ V_184 - 1 ] -> V_179 + 1 ;
F_111 ( & V_178 ) ;
} while ( V_179 <= V_19 );
V_102:
F_111 ( & V_178 ) ;
return V_168 ;
}
STATIC T_1
F_112 (
struct V_17 * V_17 ,
T_1 V_18 ,
int V_189 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_190 ( V_12 ) ;
T_5 V_73 ;
T_7 V_191 ;
T_11 V_19 ;
T_12 V_192 ;
int error ;
if ( F_23 ( V_24 ) )
return - V_33 ;
V_192 = F_88 ( V_2 ) ;
V_73 = F_31 ( V_31 ) ;
if ( V_18 >= V_73 ) {
error = - V_193 ;
goto V_129;
}
V_191 = F_41 ( V_24 , V_18 ) ;
V_19 = F_46 ( V_24 , V_73 ) ;
for (; ; ) {
struct V_78 V_176 [ 2 ] ;
int V_194 = 2 ;
unsigned int V_184 ;
error = F_43 ( V_2 , V_191 , V_19 - V_191 , V_176 , & V_194 ,
V_195 ) ;
if ( error )
goto V_129;
if ( V_194 == 0 ) {
error = - V_193 ;
goto V_129;
}
for ( V_184 = 0 ; V_184 < V_194 ; V_184 ++ ) {
V_12 = F_110 ( T_1 , V_18 ,
F_47 ( V_24 , V_176 [ V_184 ] . V_93 ) ) ;
if ( V_189 == V_196 &&
V_176 [ V_184 ] . V_81 == V_82 )
goto V_102;
if ( V_189 == V_197 &&
( V_176 [ V_184 ] . V_81 == V_198 ||
( V_176 [ V_184 ] . V_91 == V_199 &&
! F_113 ( V_176 [ V_184 ] . V_81 ) ) ) )
goto V_102;
if ( V_176 [ V_184 ] . V_91 == V_92 ) {
if ( F_104 ( V_31 , & V_176 [ V_184 ] ,
V_189 == V_196 ? V_173 : V_172 ,
& V_12 ) )
goto V_102;
}
}
if ( V_194 == 1 ) {
if ( V_189 == V_196 ) {
V_12 = V_73 ;
break;
}
ASSERT ( V_189 == V_197 ) ;
error = - V_193 ;
goto V_129;
}
ASSERT ( V_184 > 1 ) ;
V_191 = V_176 [ V_184 - 1 ] . V_93 + V_176 [ V_184 - 1 ] . V_94 ;
V_18 = F_47 ( V_24 , V_191 ) ;
if ( V_18 >= V_73 ) {
if ( V_189 == V_196 ) {
V_12 = V_73 ;
break;
}
ASSERT ( V_189 == V_197 ) ;
error = - V_193 ;
goto V_129;
}
}
V_102:
if ( V_189 == V_196 )
V_12 = F_93 ( T_1 , V_12 , V_73 ) ;
V_12 = F_114 ( V_17 , V_12 , V_31 -> V_153 -> V_63 ) ;
V_129:
F_6 ( V_2 , V_192 ) ;
if ( error )
return error ;
return V_12 ;
}
STATIC T_1
F_115 (
struct V_17 * V_17 ,
T_1 V_12 ,
int V_189 )
{
switch ( V_189 ) {
case V_200 :
case V_201 :
case V_202 :
return F_116 ( V_17 , V_12 , V_189 ) ;
case V_196 :
case V_197 :
return F_112 ( V_17 , V_12 , V_189 ) ;
default:
return - V_61 ;
}
}
