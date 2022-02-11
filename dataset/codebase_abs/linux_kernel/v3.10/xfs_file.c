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
return - F_24 ( V_33 ) ;
F_25 ( V_2 , V_34 ) ;
if ( V_24 -> V_35 & V_36 ) {
if ( F_26 ( V_2 ) )
F_27 ( V_24 -> V_37 ) ;
else if ( V_24 -> V_38 != V_24 -> V_39 )
F_27 ( V_24 -> V_39 ) ;
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
! F_26 ( V_2 ) &&
! V_32 )
F_27 ( V_24 -> V_39 ) ;
return - error ;
}
STATIC T_4
F_28 (
struct V_42 * V_43 ,
const struct V_44 * V_45 ,
unsigned long V_46 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_2 V_48 = 0 ;
T_4 V_49 = 0 ;
int V_50 = 0 ;
T_5 V_51 ;
F_29 ( V_52 ) ;
F_30 ( V_43 -> V_53 != V_5 ) ;
if ( F_31 ( V_17 -> V_54 & V_55 ) )
V_50 |= V_56 ;
if ( V_17 -> V_57 & V_58 )
V_50 |= V_59 ;
V_49 = F_32 ( V_45 , & V_46 , & V_48 , V_60 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( F_31 ( V_50 & V_56 ) ) {
T_6 * V_61 =
F_26 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 & V_61 -> V_62 ) || ( V_48 & V_61 -> V_62 ) ) {
if ( V_5 == F_33 ( V_31 ) )
return 0 ;
return - F_24 ( V_63 ) ;
}
}
V_51 = V_24 -> V_64 -> V_65 - V_5 ;
if ( V_51 <= 0 || V_48 == 0 )
return 0 ;
if ( V_51 < V_48 )
V_48 = V_51 ;
if ( F_23 ( V_24 ) )
return - V_33 ;
F_1 ( V_2 , V_66 ) ;
if ( ( V_50 & V_56 ) && V_31 -> V_11 -> V_67 ) {
F_5 ( V_2 , V_66 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_31 -> V_11 -> V_67 ) {
V_49 = - F_22 (
F_3 ( V_2 ) -> V_11 ,
V_5 , - 1 ) ;
if ( V_49 ) {
F_5 ( V_2 , V_3 ) ;
return V_49 ;
}
F_34 ( F_3 ( V_2 ) , V_5 , - 1 ) ;
}
F_8 ( V_2 , V_3 ) ;
}
F_35 ( V_2 , V_48 , V_5 , V_50 ) ;
V_49 = F_36 ( V_43 , V_45 , V_46 , V_5 ) ;
if ( V_49 > 0 )
F_37 ( V_68 , V_49 ) ;
F_5 ( V_2 , V_66 ) ;
return V_49 ;
}
STATIC T_4
F_38 (
struct V_17 * V_69 ,
T_1 * V_70 ,
struct V_71 * V_72 ,
T_2 V_6 ,
unsigned int V_73 )
{
struct V_1 * V_2 = F_16 ( V_69 -> V_21 -> V_22 ) ;
int V_50 = 0 ;
T_4 V_49 ;
F_29 ( V_52 ) ;
if ( V_69 -> V_57 & V_58 )
V_50 |= V_59 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_1 ( V_2 , V_66 ) ;
F_39 ( V_2 , V_6 , * V_70 , V_50 ) ;
V_49 = F_40 ( V_69 , V_70 , V_72 , V_6 , V_73 ) ;
if ( V_49 > 0 )
F_37 ( V_68 , V_49 ) ;
F_5 ( V_2 , V_66 ) ;
return V_49 ;
}
STATIC T_4
F_41 (
struct V_71 * V_72 ,
struct V_17 * V_74 ,
T_1 * V_70 ,
T_2 V_6 ,
unsigned int V_73 )
{
struct V_31 * V_31 = V_74 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_50 = 0 ;
T_4 V_49 ;
F_29 ( V_75 ) ;
if ( V_74 -> V_57 & V_58 )
V_50 |= V_59 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_4 ( V_2 , V_3 ) ;
F_42 ( V_2 , V_6 , * V_70 , V_50 ) ;
V_49 = F_43 ( V_72 , V_74 , V_70 , V_6 , V_73 ) ;
if ( V_49 > 0 )
F_37 ( V_76 , V_49 ) ;
F_6 ( V_2 , V_3 ) ;
return V_49 ;
}
STATIC int
F_44 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_77 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_78 = F_45 ( V_24 , V_77 ) ;
int V_79 = F_46 ( V_24 , V_77 ) ;
int V_80 ;
int V_81 = 1 ;
int error = 0 ;
struct V_82 V_83 ;
F_4 ( V_2 , V_84 ) ;
error = F_47 ( V_2 , V_78 , 1 , & V_83 , & V_81 , 0 ) ;
F_6 ( V_2 , V_84 ) ;
if ( error )
return error ;
ASSERT ( V_81 > 0 ) ;
if ( V_83 . V_85 == V_86 )
return 0 ;
V_80 = V_24 -> V_87 . V_88 - V_79 ;
if ( V_77 + V_80 > V_12 )
V_80 = V_12 - V_77 ;
return F_10 ( V_2 , V_77 , V_80 ) ;
}
int
F_48 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_77 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_89 ;
T_7 V_90 ;
T_7 V_91 ;
T_7 V_78 ;
T_7 V_92 ;
T_5 V_80 ;
int V_81 ;
int error = 0 ;
struct V_82 V_83 ;
ASSERT ( F_49 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_77 ) ;
if ( F_46 ( V_24 , V_77 ) != 0 ) {
error = F_44 ( V_2 , V_12 , V_77 ) ;
if ( error )
return error ;
}
V_78 = V_77 ? F_45 ( V_24 , V_77 - 1 ) : ( T_7 ) - 1 ;
V_89 = F_50 ( V_24 , ( V_93 ) V_77 ) ;
V_90 = F_45 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_94 ) V_78 < ( V_94 ) V_89 ) ;
if ( V_78 == V_90 ) {
return 0 ;
}
ASSERT ( V_89 <= V_90 ) ;
while ( V_89 <= V_90 ) {
V_81 = 1 ;
V_91 = V_90 - V_89 + 1 ;
F_4 ( V_2 , V_84 ) ;
error = F_47 ( V_2 , V_89 , V_91 ,
& V_83 , & V_81 , 0 ) ;
F_6 ( V_2 , V_84 ) ;
if ( error )
return error ;
ASSERT ( V_81 > 0 ) ;
if ( V_83 . V_95 == V_96 ||
V_83 . V_85 == V_86 ) {
V_89 = V_83 . V_97 + V_83 . V_98 ;
ASSERT ( V_89 <= ( V_90 + 1 ) ) ;
continue;
}
V_92 = F_51 ( V_24 , V_89 ) ;
V_80 = F_51 ( V_24 , V_83 . V_98 ) ;
if ( ( V_92 + V_80 ) > V_12 )
V_80 = V_12 - V_92 ;
error = F_10 ( V_2 , V_92 , V_80 ) ;
if ( error )
return error ;
V_89 = V_83 . V_97 + V_83 . V_98 ;
ASSERT ( V_89 <= ( V_90 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_52 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_99 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int error = 0 ;
V_100:
error = F_53 ( V_17 , V_5 , V_6 , F_54 ( V_31 -> V_101 ) ) ;
if ( error )
return error ;
if ( * V_5 > F_33 ( V_31 ) ) {
if ( * V_99 == V_66 ) {
F_5 ( V_2 , * V_99 ) ;
* V_99 = V_3 ;
F_1 ( V_2 , * V_99 ) ;
goto V_100;
}
error = - F_48 ( V_2 , * V_5 , F_33 ( V_31 ) ) ;
if ( error )
return error ;
}
if ( F_55 ( ! ( V_17 -> V_57 & V_58 ) ) ) {
error = F_56 ( V_17 ) ;
if ( error )
return error ;
}
return F_57 ( V_17 ) ;
}
STATIC T_4
F_58 (
struct V_42 * V_43 ,
const struct V_44 * V_45 ,
unsigned long V_46 ,
T_1 V_5 ,
T_2 V_102 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_49 = 0 ;
T_2 V_6 = V_102 ;
int V_103 = 0 ;
int V_99 ;
struct V_104 * V_61 = F_26 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 & V_61 -> V_62 ) || ( V_6 & V_61 -> V_62 ) )
return - F_24 ( V_63 ) ;
if ( ( V_5 & V_24 -> V_105 ) || ( ( V_5 + V_6 ) & V_24 -> V_105 ) )
V_103 = 1 ;
if ( V_103 || V_9 -> V_67 )
V_99 = V_3 ;
else
V_99 = V_66 ;
F_1 ( V_2 , V_99 ) ;
if ( V_9 -> V_67 && V_99 == V_66 ) {
F_5 ( V_2 , V_99 ) ;
V_99 = V_3 ;
F_1 ( V_2 , V_99 ) ;
}
V_49 = F_52 ( V_17 , & V_5 , & V_6 , & V_99 ) ;
if ( V_49 )
goto V_106;
if ( V_9 -> V_67 ) {
V_49 = - F_22 ( F_3 ( V_2 ) -> V_11 ,
V_5 , - 1 ) ;
if ( V_49 )
goto V_106;
F_34 ( F_3 ( V_2 ) , V_5 , - 1 ) ;
}
if ( V_103 )
F_59 ( V_31 ) ;
else if ( V_99 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_99 = V_66 ;
}
F_60 ( V_2 , V_6 , V_43 -> V_53 , 0 ) ;
V_49 = F_61 ( V_43 , V_45 ,
& V_46 , V_5 , & V_43 -> V_53 , V_6 , V_102 ) ;
V_106:
F_5 ( V_2 , V_99 ) ;
ASSERT ( V_49 < 0 || V_49 == V_6 ) ;
return V_49 ;
}
STATIC T_4
F_62 (
struct V_42 * V_43 ,
const struct V_44 * V_45 ,
unsigned long V_46 ,
T_1 V_5 ,
T_2 V_102 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_49 ;
int V_107 = 0 ;
int V_99 = V_3 ;
T_2 V_6 = V_102 ;
F_1 ( V_2 , V_99 ) ;
V_49 = F_52 ( V_17 , & V_5 , & V_6 , & V_99 ) ;
if ( V_49 )
goto V_106;
V_108 -> V_109 = V_9 -> V_109 ;
V_110:
F_63 ( V_2 , V_6 , V_43 -> V_53 , 0 ) ;
V_49 = F_64 ( V_43 , V_45 , V_46 ,
V_5 , & V_43 -> V_53 , V_6 , 0 ) ;
if ( V_49 == - V_111 && ! V_107 ) {
V_107 = 1 ;
F_65 ( V_2 -> V_25 ) ;
goto V_110;
}
V_108 -> V_109 = NULL ;
V_106:
F_5 ( V_2 , V_99 ) ;
return V_49 ;
}
STATIC T_4
F_66 (
struct V_42 * V_43 ,
const struct V_44 * V_45 ,
unsigned long V_46 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_49 ;
T_2 V_102 = 0 ;
F_29 ( V_75 ) ;
F_30 ( V_43 -> V_53 != V_5 ) ;
V_49 = F_32 ( V_45 , & V_46 , & V_102 , V_112 ) ;
if ( V_49 )
return V_49 ;
if ( V_102 == 0 )
return 0 ;
if ( F_23 ( V_2 -> V_25 ) ) {
V_49 = - V_33 ;
goto V_106;
}
if ( F_31 ( V_17 -> V_54 & V_55 ) )
V_49 = F_58 ( V_43 , V_45 , V_46 , V_5 , V_102 ) ;
else
V_49 = F_62 ( V_43 , V_45 , V_46 , V_5 ,
V_102 ) ;
if ( V_49 > 0 ) {
T_4 V_113 ;
F_37 ( V_76 , V_49 ) ;
V_113 = F_67 ( V_17 , V_5 , V_49 ) ;
if ( V_113 < 0 )
V_49 = V_113 ;
}
V_106:
return V_49 ;
}
STATIC long
F_68 (
struct V_17 * V_17 ,
int V_114 ,
T_1 V_12 ,
T_1 V_115 )
{
struct V_31 * V_31 = F_69 ( V_17 ) ;
long error ;
T_1 V_116 = 0 ;
T_9 V_117 ;
T_10 * V_2 = F_16 ( V_31 ) ;
int V_118 = V_119 ;
int V_120 = V_121 ;
if ( V_114 & ~ ( V_122 | V_123 ) )
return - V_124 ;
V_117 . V_125 = 0 ;
V_117 . V_126 = V_12 ;
V_117 . V_127 = V_115 ;
F_4 ( V_2 , V_3 ) ;
if ( V_114 & V_123 )
V_118 = V_128 ;
if ( ! ( V_114 & V_122 ) &&
V_12 + V_115 > F_33 ( V_31 ) ) {
V_116 = V_12 + V_115 ;
error = F_70 ( V_31 , V_116 ) ;
if ( error )
goto V_129;
}
if ( V_17 -> V_54 & V_130 )
V_120 |= V_131 ;
error = - F_71 ( V_2 , V_118 , & V_117 , 0 , V_120 ) ;
if ( error )
goto V_129;
if ( V_116 ) {
struct V_132 V_132 ;
V_132 . V_133 = V_134 ;
V_132 . V_135 = V_116 ;
error = - F_72 ( V_2 , & V_132 , V_121 ) ;
}
V_129:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_73 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_54 & V_136 ) && F_33 ( V_31 ) > V_137 )
return - V_138 ;
if ( F_23 ( F_74 ( V_31 -> V_139 ) ) )
return - V_33 ;
return 0 ;
}
STATIC int
F_75 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_114 ;
int error ;
error = F_73 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_114 = F_76 ( V_2 ) ;
if ( V_2 -> V_140 . V_141 > 0 )
F_77 ( NULL , V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_114 ) ;
return 0 ;
}
STATIC int
F_78 (
struct V_31 * V_31 ,
struct V_17 * V_142 )
{
return - F_79 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_80 (
struct V_17 * V_142 ,
void * V_143 ,
T_11 V_144 )
{
struct V_31 * V_31 = F_69 ( V_142 ) ;
T_10 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_145 ;
V_145 = ( T_2 ) F_81 ( T_1 , 32768 , V_2 -> V_140 . V_146 ) ;
error = F_82 ( V_2 , V_143 , V_145 ,
( T_8 * ) & V_142 -> V_147 , V_144 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_83 (
struct V_17 * V_142 ,
struct V_148 * V_149 )
{
V_149 -> V_150 = & V_151 ;
F_84 ( V_142 ) ;
return 0 ;
}
STATIC int
F_85 (
struct V_148 * V_149 ,
struct V_152 * V_153 )
{
return F_86 ( V_149 , V_153 , V_154 ) ;
}
STATIC bool
F_87 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_155 = F_88 ( V_7 ) ;
bool V_156 = false ;
struct V_157 * V_158 , * V_159 ;
V_158 = V_159 = F_89 ( V_7 ) ;
do {
if ( F_90 ( V_158 ) ||
F_91 ( V_158 ) ) {
if ( type == V_160 )
V_156 = true ;
} else {
if ( type == V_161 )
V_156 = true ;
}
if ( V_156 ) {
* V_12 = V_155 ;
break;
}
V_155 += V_158 -> V_162 ;
} while ( ( V_158 = V_158 -> V_163 ) != V_159 );
return V_156 ;
}
STATIC bool
F_92 (
struct V_31 * V_31 ,
struct V_82 * V_164 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_165 V_166 ;
T_12 V_167 ;
T_12 V_19 ;
T_1 V_168 ;
T_1 V_169 = * V_12 ;
T_1 V_155 = V_169 ;
bool V_156 = false ;
F_93 ( & V_166 , 0 ) ;
V_167 = V_169 >> V_170 ;
V_168 = F_51 ( V_24 , V_164 -> V_97 + V_164 -> V_98 ) ;
V_19 = V_168 >> V_170 ;
do {
int V_171 ;
unsigned V_172 ;
unsigned int V_173 ;
V_171 = F_81 ( T_12 , V_19 - V_167 , V_174 ) ;
V_172 = F_94 ( & V_166 , V_31 -> V_11 , V_167 ,
V_171 ) ;
if ( V_172 == 0 ) {
if ( type == V_160 )
break;
ASSERT ( type == V_161 ) ;
if ( V_155 == V_169 || V_155 < V_168 ) {
V_156 = true ;
* V_12 = V_155 ;
}
break;
}
if ( type == V_161 && V_155 == V_169 &&
V_155 < F_88 ( V_166 . V_175 [ 0 ] ) ) {
V_156 = true ;
break;
}
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ ) {
struct V_7 * V_7 = V_166 . V_175 [ V_173 ] ;
T_1 V_176 ;
if ( V_7 -> V_167 > V_19 ) {
if ( type == V_161 && V_155 < V_168 ) {
* V_12 = V_155 ;
V_156 = true ;
}
goto V_106;
}
F_95 ( V_7 ) ;
if ( F_31 ( V_7 -> V_9 != V_31 -> V_11 ) ) {
F_96 ( V_7 ) ;
continue;
}
if ( ! F_97 ( V_7 ) ) {
F_96 ( V_7 ) ;
continue;
}
V_156 = F_87 ( V_7 , & V_176 , type ) ;
if ( V_156 ) {
* V_12 = F_98 ( T_1 , V_169 , V_176 ) ;
F_96 ( V_7 ) ;
goto V_106;
}
V_155 = F_88 ( V_7 ) + V_177 ;
F_96 ( V_7 ) ;
}
if ( V_172 < V_171 ) {
if ( type == V_161 ) {
* V_12 = V_155 ;
V_156 = true ;
}
break;
}
V_167 = V_166 . V_175 [ V_173 - 1 ] -> V_167 + 1 ;
F_99 ( & V_166 ) ;
} while ( V_167 <= V_19 );
V_106:
F_99 ( & V_166 ) ;
return V_156 ;
}
STATIC T_1
F_100 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_178 ( V_12 ) ;
T_5 V_77 ;
T_7 V_179 ;
T_13 V_19 ;
T_14 V_180 ;
int error ;
V_180 = F_76 ( V_2 ) ;
V_77 = F_33 ( V_31 ) ;
if ( V_18 >= V_77 ) {
error = V_181 ;
goto V_129;
}
V_179 = F_45 ( V_24 , V_18 ) ;
V_19 = F_50 ( V_24 , V_77 ) ;
for (; ; ) {
struct V_82 V_164 [ 2 ] ;
int V_182 = 2 ;
unsigned int V_173 ;
error = F_47 ( V_2 , V_179 , V_19 - V_179 , V_164 , & V_182 ,
V_183 ) ;
if ( error )
goto V_129;
if ( V_182 == 0 ) {
error = V_181 ;
goto V_129;
}
for ( V_173 = 0 ; V_173 < V_182 ; V_173 ++ ) {
V_12 = F_98 ( T_1 , V_18 ,
F_51 ( V_24 , V_164 [ V_173 ] . V_97 ) ) ;
if ( V_164 [ V_173 ] . V_85 == V_184 ||
( V_164 [ V_173 ] . V_95 == V_185 &&
! F_101 ( V_164 [ V_173 ] . V_85 ) ) )
goto V_106;
if ( V_164 [ V_173 ] . V_95 == V_96 ) {
if ( F_92 ( V_31 , & V_164 [ V_173 ] ,
V_160 , & V_12 ) )
goto V_106;
}
}
if ( V_182 == 1 ) {
error = V_181 ;
goto V_129;
}
ASSERT ( V_173 > 1 ) ;
V_179 = V_164 [ V_173 - 1 ] . V_97 + V_164 [ V_173 - 1 ] . V_98 ;
V_18 = F_51 ( V_24 , V_179 ) ;
if ( V_18 >= V_77 ) {
error = V_181 ;
goto V_129;
}
}
V_106:
if ( V_12 != V_17 -> V_147 )
V_17 -> V_147 = V_12 ;
V_129:
F_102 ( V_2 , V_180 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_103 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_178 ( V_12 ) ;
T_5 V_77 ;
T_7 V_179 ;
T_13 V_19 ;
T_14 V_180 ;
int error ;
if ( F_23 ( V_24 ) )
return - F_24 ( V_33 ) ;
V_180 = F_76 ( V_2 ) ;
V_77 = F_33 ( V_31 ) ;
if ( V_18 >= V_77 ) {
error = V_181 ;
goto V_129;
}
V_179 = F_45 ( V_24 , V_18 ) ;
V_19 = F_50 ( V_24 , V_77 ) ;
for (; ; ) {
struct V_82 V_164 [ 2 ] ;
int V_182 = 2 ;
unsigned int V_173 ;
error = F_47 ( V_2 , V_179 , V_19 - V_179 , V_164 , & V_182 ,
V_183 ) ;
if ( error )
goto V_129;
if ( V_182 == 0 ) {
error = V_181 ;
goto V_129;
}
for ( V_173 = 0 ; V_173 < V_182 ; V_173 ++ ) {
V_12 = F_98 ( T_1 , V_18 ,
F_51 ( V_24 , V_164 [ V_173 ] . V_97 ) ) ;
if ( V_164 [ V_173 ] . V_85 == V_86 )
goto V_106;
if ( V_164 [ V_173 ] . V_95 == V_96 ) {
if ( F_92 ( V_31 , & V_164 [ V_173 ] ,
V_161 , & V_12 ) )
goto V_106;
}
}
if ( V_182 == 1 ) {
V_12 = V_77 ;
break;
}
ASSERT ( V_173 > 1 ) ;
V_179 = V_164 [ V_173 - 1 ] . V_97 + V_164 [ V_173 - 1 ] . V_98 ;
V_18 = F_51 ( V_24 , V_179 ) ;
if ( V_18 >= V_77 ) {
V_12 = V_77 ;
break;
}
}
V_106:
V_12 = F_81 ( T_1 , V_12 , V_77 ) ;
if ( V_12 != V_17 -> V_147 )
V_17 -> V_147 = V_12 ;
V_129:
F_102 ( V_2 , V_180 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_104 (
struct V_17 * V_17 ,
T_1 V_12 ,
int V_186 )
{
switch ( V_186 ) {
case V_187 :
case V_188 :
case V_189 :
return F_105 ( V_17 , V_12 , V_186 ) ;
case V_190 :
return F_100 ( V_17 , V_12 ) ;
case V_191 :
return F_103 ( V_17 , V_12 ) ;
default:
return - V_63 ;
}
}
