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
return - F_19 ( V_24 , V_26 , V_30 , NULL ) ;
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
struct V_44 * V_45 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_2 V_47 = F_29 ( V_45 ) ;
T_4 V_48 = 0 ;
int V_49 = 0 ;
T_5 V_50 ;
T_1 V_5 = V_43 -> V_51 ;
F_30 ( V_52 ) ;
if ( F_31 ( V_17 -> V_53 & V_54 ) )
V_49 |= V_55 ;
if ( V_17 -> V_56 & V_57 )
V_49 |= V_58 ;
if ( F_31 ( V_49 & V_55 ) ) {
T_6 * V_59 =
F_26 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 | V_47 ) & V_59 -> V_60 ) {
if ( V_5 == F_32 ( V_31 ) )
return 0 ;
return - F_24 ( V_61 ) ;
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
V_5 , - 1 ) ;
if ( V_48 ) {
F_5 ( V_2 , V_3 ) ;
return V_48 ;
}
F_33 ( F_3 ( V_2 ) , V_5 , - 1 ) ;
}
F_8 ( V_2 , V_3 ) ;
}
F_34 ( V_2 , V_47 , V_5 , V_49 ) ;
V_48 = F_35 ( V_43 , V_45 ) ;
if ( V_48 > 0 )
F_36 ( V_66 , V_48 ) ;
F_5 ( V_2 , V_64 ) ;
return V_48 ;
}
STATIC T_4
F_37 (
struct V_17 * V_67 ,
T_1 * V_68 ,
struct V_69 * V_70 ,
T_2 V_6 ,
unsigned int V_71 )
{
struct V_1 * V_2 = F_16 ( V_67 -> V_21 -> V_22 ) ;
int V_49 = 0 ;
T_4 V_48 ;
F_30 ( V_52 ) ;
if ( V_67 -> V_56 & V_57 )
V_49 |= V_58 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_1 ( V_2 , V_64 ) ;
F_38 ( V_2 , V_6 , * V_68 , V_49 ) ;
V_48 = F_39 ( V_67 , V_68 , V_70 , V_6 , V_71 ) ;
if ( V_48 > 0 )
F_36 ( V_66 , V_48 ) ;
F_5 ( V_2 , V_64 ) ;
return V_48 ;
}
STATIC int
F_40 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_72 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_73 = F_41 ( V_24 , V_72 ) ;
int V_74 = F_42 ( V_24 , V_72 ) ;
int V_75 ;
int V_76 = 1 ;
int error = 0 ;
struct V_77 V_78 ;
F_4 ( V_2 , V_79 ) ;
error = F_43 ( V_2 , V_73 , 1 , & V_78 , & V_76 , 0 ) ;
F_6 ( V_2 , V_79 ) ;
if ( error )
return error ;
ASSERT ( V_76 > 0 ) ;
if ( V_78 . V_80 == V_81 )
return 0 ;
V_75 = V_24 -> V_82 . V_83 - V_74 ;
if ( V_72 + V_75 > V_12 )
V_75 = V_12 - V_72 ;
return F_10 ( V_2 , V_72 , V_75 ) ;
}
int
F_44 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_72 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_84 ;
T_7 V_85 ;
T_7 V_86 ;
T_7 V_73 ;
T_7 V_87 ;
T_5 V_75 ;
int V_76 ;
int error = 0 ;
struct V_77 V_78 ;
ASSERT ( F_45 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_72 ) ;
if ( F_42 ( V_24 , V_72 ) != 0 ) {
error = F_40 ( V_2 , V_12 , V_72 ) ;
if ( error )
return error ;
}
V_73 = V_72 ? F_41 ( V_24 , V_72 - 1 ) : ( T_7 ) - 1 ;
V_84 = F_46 ( V_24 , ( V_88 ) V_72 ) ;
V_85 = F_41 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_89 ) V_73 < ( V_89 ) V_84 ) ;
if ( V_73 == V_85 ) {
return 0 ;
}
ASSERT ( V_84 <= V_85 ) ;
while ( V_84 <= V_85 ) {
V_76 = 1 ;
V_86 = V_85 - V_84 + 1 ;
F_4 ( V_2 , V_79 ) ;
error = F_43 ( V_2 , V_84 , V_86 ,
& V_78 , & V_76 , 0 ) ;
F_6 ( V_2 , V_79 ) ;
if ( error )
return error ;
ASSERT ( V_76 > 0 ) ;
if ( V_78 . V_90 == V_91 ||
V_78 . V_80 == V_81 ) {
V_84 = V_78 . V_92 + V_78 . V_93 ;
ASSERT ( V_84 <= ( V_85 + 1 ) ) ;
continue;
}
V_87 = F_47 ( V_24 , V_84 ) ;
V_75 = F_47 ( V_24 , V_78 . V_93 ) ;
if ( ( V_87 + V_75 ) > V_12 )
V_75 = V_12 - V_87 ;
error = F_10 ( V_2 , V_87 , V_75 ) ;
if ( error )
return error ;
V_84 = V_78 . V_92 + V_78 . V_93 ;
ASSERT ( V_84 <= ( V_85 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_48 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_94 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int error = 0 ;
V_95:
error = F_49 ( V_17 , V_5 , V_6 , F_50 ( V_31 -> V_96 ) ) ;
if ( error )
return error ;
if ( * V_5 > F_32 ( V_31 ) ) {
if ( * V_94 == V_64 ) {
F_5 ( V_2 , * V_94 ) ;
* V_94 = V_3 ;
F_1 ( V_2 , * V_94 ) ;
goto V_95;
}
error = - F_44 ( V_2 , * V_5 , F_32 ( V_31 ) ) ;
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
struct V_44 * V_97 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_48 = 0 ;
int V_98 = 0 ;
int V_94 ;
T_2 V_6 = F_29 ( V_97 ) ;
T_1 V_5 = V_43 -> V_51 ;
struct V_99 * V_59 = F_26 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 | V_6 ) & V_59 -> V_60 )
return - F_24 ( V_61 ) ;
if ( ( V_5 & V_24 -> V_100 ) || ( ( V_5 + V_6 ) & V_24 -> V_100 ) )
V_98 = 1 ;
if ( V_98 || V_9 -> V_65 )
V_94 = V_3 ;
else
V_94 = V_64 ;
F_1 ( V_2 , V_94 ) ;
if ( V_9 -> V_65 && V_94 == V_64 ) {
F_5 ( V_2 , V_94 ) ;
V_94 = V_3 ;
F_1 ( V_2 , V_94 ) ;
}
V_48 = F_48 ( V_17 , & V_5 , & V_6 , & V_94 ) ;
if ( V_48 )
goto V_101;
F_55 ( V_97 , V_6 ) ;
if ( V_9 -> V_65 ) {
V_48 = F_22 ( F_3 ( V_2 ) -> V_11 ,
V_5 , - 1 ) ;
if ( V_48 )
goto V_101;
F_33 ( F_3 ( V_2 ) , V_5 , - 1 ) ;
}
if ( V_98 )
F_56 ( V_31 ) ;
else if ( V_94 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_94 = V_64 ;
}
F_57 ( V_2 , V_6 , V_43 -> V_51 , 0 ) ;
V_48 = F_58 ( V_43 , V_97 , V_5 ) ;
V_101:
F_5 ( V_2 , V_94 ) ;
ASSERT ( V_48 < 0 || V_48 == V_6 ) ;
return V_48 ;
}
STATIC T_4
F_59 (
struct V_42 * V_43 ,
struct V_44 * V_97 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_48 ;
int V_102 = 0 ;
int V_94 = V_3 ;
T_1 V_5 = V_43 -> V_51 ;
T_2 V_6 = F_29 ( V_97 ) ;
F_1 ( V_2 , V_94 ) ;
V_48 = F_48 ( V_17 , & V_5 , & V_6 , & V_94 ) ;
if ( V_48 )
goto V_101;
F_55 ( V_97 , V_6 ) ;
V_103 -> V_104 = V_9 -> V_104 ;
V_105:
F_60 ( V_2 , V_6 , V_43 -> V_51 , 0 ) ;
V_48 = F_61 ( V_17 , V_97 , V_5 ) ;
if ( F_51 ( V_48 >= 0 ) )
V_43 -> V_51 = V_5 + V_48 ;
if ( V_48 == - V_106 && ! V_102 ) {
V_102 = 1 ;
F_62 ( V_2 -> V_25 ) ;
goto V_105;
}
V_103 -> V_104 = NULL ;
V_101:
F_5 ( V_2 , V_94 ) ;
return V_48 ;
}
STATIC T_4
F_63 (
struct V_42 * V_43 ,
struct V_44 * V_97 )
{
struct V_17 * V_17 = V_43 -> V_46 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_48 ;
T_2 V_107 = F_29 ( V_97 ) ;
F_30 ( V_108 ) ;
if ( V_107 == 0 )
return 0 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
if ( F_31 ( V_17 -> V_53 & V_54 ) )
V_48 = F_54 ( V_43 , V_97 ) ;
else
V_48 = F_59 ( V_43 , V_97 ) ;
if ( V_48 > 0 ) {
T_4 V_109 ;
F_36 ( V_110 , V_48 ) ;
V_109 = F_64 ( V_17 , V_43 -> V_51 - V_48 , V_48 ) ;
if ( V_109 < 0 )
V_48 = V_109 ;
}
return V_48 ;
}
STATIC long
F_65 (
struct V_17 * V_17 ,
int V_111 ,
T_1 V_12 ,
T_1 V_112 )
{
struct V_31 * V_31 = F_66 ( V_17 ) ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_113 * V_114 ;
long error ;
T_1 V_115 = 0 ;
if ( ! F_67 ( V_31 -> V_96 ) )
return - V_61 ;
if ( V_111 & ~ ( V_116 | V_117 |
V_118 | V_119 ) )
return - V_120 ;
F_4 ( V_2 , V_3 ) ;
if ( V_111 & V_117 ) {
error = F_68 ( V_2 , V_12 , V_112 ) ;
if ( error )
goto V_121;
} else if ( V_111 & V_118 ) {
unsigned V_122 = ( 1 << V_31 -> V_123 ) - 1 ;
if ( V_12 & V_122 || V_112 & V_122 ) {
error = V_61 ;
goto V_121;
}
if ( V_12 + V_112 >= F_32 ( V_31 ) ) {
error = V_61 ;
goto V_121;
}
V_115 = F_32 ( V_31 ) - V_112 ;
error = F_69 ( V_2 , V_12 , V_112 ) ;
if ( error )
goto V_121;
} else {
if ( ! ( V_111 & V_116 ) &&
V_12 + V_112 > F_32 ( V_31 ) ) {
V_115 = V_12 + V_112 ;
error = - F_70 ( V_31 , V_115 ) ;
if ( error )
goto V_121;
}
if ( V_111 & V_119 )
error = F_71 ( V_2 , V_12 , V_112 ) ;
else
error = F_72 ( V_2 , V_12 , V_112 ,
V_124 ) ;
if ( error )
goto V_121;
}
V_114 = F_73 ( V_2 -> V_25 , V_125 ) ;
error = F_74 ( V_114 , & F_75 ( V_2 -> V_25 ) -> V_126 , 0 , 0 ) ;
if ( error ) {
F_76 ( V_114 , 0 ) ;
goto V_121;
}
F_4 ( V_2 , V_79 ) ;
F_77 ( V_114 , V_2 , V_79 ) ;
V_2 -> V_127 . V_128 &= ~ V_129 ;
if ( V_2 -> V_127 . V_128 & V_130 )
V_2 -> V_127 . V_128 &= ~ V_131 ;
if ( ! ( V_111 & ( V_117 | V_118 ) ) )
V_2 -> V_127 . V_132 |= V_133 ;
F_78 ( V_114 , V_2 , V_134 | V_135 ) ;
F_79 ( V_114 , V_2 , V_136 ) ;
if ( V_17 -> V_53 & V_137 )
F_80 ( V_114 ) ;
error = F_81 ( V_114 , 0 ) ;
if ( error )
goto V_121;
if ( V_115 ) {
struct V_138 V_138 ;
V_138 . V_139 = V_140 ;
V_138 . V_141 = V_115 ;
error = F_82 ( V_2 , & V_138 ) ;
}
V_121:
F_6 ( V_2 , V_3 ) ;
return - error ;
}
STATIC int
F_83 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_53 & V_142 ) && F_32 ( V_31 ) > V_143 )
return - V_144 ;
if ( F_23 ( F_84 ( V_31 -> V_145 ) ) )
return - V_33 ;
return 0 ;
}
STATIC int
F_85 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_111 ;
int error ;
error = F_83 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_111 = F_86 ( V_2 ) ;
if ( V_2 -> V_127 . V_146 > 0 )
F_87 ( V_2 , 0 , - 1 ) ;
F_6 ( V_2 , V_111 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_31 * V_31 ,
struct V_17 * V_147 )
{
return - F_89 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_90 (
struct V_17 * V_17 ,
struct V_148 * V_149 )
{
struct V_31 * V_31 = F_66 ( V_17 ) ;
T_9 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_150 ;
V_150 = ( T_2 ) F_91 ( T_1 , 32768 , V_2 -> V_127 . V_151 ) ;
error = F_92 ( V_2 , V_149 , V_150 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_93 (
struct V_17 * V_147 ,
struct V_152 * V_153 )
{
V_153 -> V_154 = & V_155 ;
F_94 ( V_147 ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_152 * V_153 ,
struct V_156 * V_157 )
{
return F_96 ( V_153 , V_157 , V_158 ) ;
}
STATIC bool
F_97 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_159 = F_98 ( V_7 ) ;
bool V_160 = false ;
struct V_161 * V_162 , * V_163 ;
V_162 = V_163 = F_99 ( V_7 ) ;
do {
if ( F_100 ( V_162 ) ||
F_101 ( V_162 ) ) {
if ( type == V_164 )
V_160 = true ;
} else {
if ( type == V_165 )
V_160 = true ;
}
if ( V_160 ) {
* V_12 = V_159 ;
break;
}
V_159 += V_162 -> V_166 ;
} while ( ( V_162 = V_162 -> V_167 ) != V_163 );
return V_160 ;
}
STATIC bool
F_102 (
struct V_31 * V_31 ,
struct V_77 * V_168 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_169 V_170 ;
T_10 V_171 ;
T_10 V_19 ;
T_1 V_172 ;
T_1 V_173 = * V_12 ;
T_1 V_159 = V_173 ;
bool V_160 = false ;
F_103 ( & V_170 , 0 ) ;
V_171 = V_173 >> V_174 ;
V_172 = F_47 ( V_24 , V_168 -> V_92 + V_168 -> V_93 ) ;
V_19 = V_172 >> V_174 ;
do {
int V_175 ;
unsigned V_176 ;
unsigned int V_177 ;
V_175 = F_91 ( T_10 , V_19 - V_171 , V_178 ) ;
V_176 = F_104 ( & V_170 , V_31 -> V_11 , V_171 ,
V_175 ) ;
if ( V_176 == 0 ) {
if ( type == V_164 )
break;
ASSERT ( type == V_165 ) ;
if ( V_159 == V_173 || V_159 < V_172 ) {
V_160 = true ;
* V_12 = V_159 ;
}
break;
}
if ( type == V_165 && V_159 == V_173 &&
V_159 < F_98 ( V_170 . V_179 [ 0 ] ) ) {
V_160 = true ;
break;
}
for ( V_177 = 0 ; V_177 < V_176 ; V_177 ++ ) {
struct V_7 * V_7 = V_170 . V_179 [ V_177 ] ;
T_1 V_180 ;
if ( V_7 -> V_171 > V_19 ) {
if ( type == V_165 && V_159 < V_172 ) {
* V_12 = V_159 ;
V_160 = true ;
}
goto V_101;
}
F_105 ( V_7 ) ;
if ( F_31 ( V_7 -> V_9 != V_31 -> V_11 ) ) {
F_106 ( V_7 ) ;
continue;
}
if ( ! F_107 ( V_7 ) ) {
F_106 ( V_7 ) ;
continue;
}
V_160 = F_97 ( V_7 , & V_180 , type ) ;
if ( V_160 ) {
* V_12 = F_108 ( T_1 , V_173 , V_180 ) ;
F_106 ( V_7 ) ;
goto V_101;
}
V_159 = F_98 ( V_7 ) + V_181 ;
F_106 ( V_7 ) ;
}
if ( V_176 < V_175 ) {
if ( type == V_165 ) {
* V_12 = V_159 ;
V_160 = true ;
}
break;
}
V_171 = V_170 . V_179 [ V_177 - 1 ] -> V_171 + 1 ;
F_109 ( & V_170 ) ;
} while ( V_171 <= V_19 );
V_101:
F_109 ( & V_170 ) ;
return V_160 ;
}
STATIC T_1
F_110 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_182 ( V_12 ) ;
T_5 V_72 ;
T_7 V_183 ;
T_11 V_19 ;
T_12 V_184 ;
int error ;
V_184 = F_86 ( V_2 ) ;
V_72 = F_32 ( V_31 ) ;
if ( V_18 >= V_72 ) {
error = V_185 ;
goto V_121;
}
V_183 = F_41 ( V_24 , V_18 ) ;
V_19 = F_46 ( V_24 , V_72 ) ;
for (; ; ) {
struct V_77 V_168 [ 2 ] ;
int V_186 = 2 ;
unsigned int V_177 ;
error = F_43 ( V_2 , V_183 , V_19 - V_183 , V_168 , & V_186 ,
V_187 ) ;
if ( error )
goto V_121;
if ( V_186 == 0 ) {
error = V_185 ;
goto V_121;
}
for ( V_177 = 0 ; V_177 < V_186 ; V_177 ++ ) {
V_12 = F_108 ( T_1 , V_18 ,
F_47 ( V_24 , V_168 [ V_177 ] . V_92 ) ) ;
if ( V_168 [ V_177 ] . V_80 == V_188 ||
( V_168 [ V_177 ] . V_90 == V_189 &&
! F_111 ( V_168 [ V_177 ] . V_80 ) ) )
goto V_101;
if ( V_168 [ V_177 ] . V_90 == V_91 ) {
if ( F_102 ( V_31 , & V_168 [ V_177 ] ,
V_164 , & V_12 ) )
goto V_101;
}
}
if ( V_186 == 1 ) {
error = V_185 ;
goto V_121;
}
ASSERT ( V_177 > 1 ) ;
V_183 = V_168 [ V_177 - 1 ] . V_92 + V_168 [ V_177 - 1 ] . V_93 ;
V_18 = F_47 ( V_24 , V_183 ) ;
if ( V_18 >= V_72 ) {
error = V_185 ;
goto V_121;
}
}
V_101:
V_12 = F_112 ( V_17 , V_12 , V_31 -> V_145 -> V_63 ) ;
V_121:
F_6 ( V_2 , V_184 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_113 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_182 ( V_12 ) ;
T_5 V_72 ;
T_7 V_183 ;
T_11 V_19 ;
T_12 V_184 ;
int error ;
if ( F_23 ( V_24 ) )
return - F_24 ( V_33 ) ;
V_184 = F_86 ( V_2 ) ;
V_72 = F_32 ( V_31 ) ;
if ( V_18 >= V_72 ) {
error = V_185 ;
goto V_121;
}
V_183 = F_41 ( V_24 , V_18 ) ;
V_19 = F_46 ( V_24 , V_72 ) ;
for (; ; ) {
struct V_77 V_168 [ 2 ] ;
int V_186 = 2 ;
unsigned int V_177 ;
error = F_43 ( V_2 , V_183 , V_19 - V_183 , V_168 , & V_186 ,
V_187 ) ;
if ( error )
goto V_121;
if ( V_186 == 0 ) {
error = V_185 ;
goto V_121;
}
for ( V_177 = 0 ; V_177 < V_186 ; V_177 ++ ) {
V_12 = F_108 ( T_1 , V_18 ,
F_47 ( V_24 , V_168 [ V_177 ] . V_92 ) ) ;
if ( V_168 [ V_177 ] . V_80 == V_81 )
goto V_101;
if ( V_168 [ V_177 ] . V_90 == V_91 ) {
if ( F_102 ( V_31 , & V_168 [ V_177 ] ,
V_165 , & V_12 ) )
goto V_101;
}
}
if ( V_186 == 1 ) {
V_12 = V_72 ;
break;
}
ASSERT ( V_177 > 1 ) ;
V_183 = V_168 [ V_177 - 1 ] . V_92 + V_168 [ V_177 - 1 ] . V_93 ;
V_18 = F_47 ( V_24 , V_183 ) ;
if ( V_18 >= V_72 ) {
V_12 = V_72 ;
break;
}
}
V_101:
V_12 = F_91 ( T_1 , V_12 , V_72 ) ;
V_12 = F_112 ( V_17 , V_12 , V_31 -> V_145 -> V_63 ) ;
V_121:
F_6 ( V_2 , V_184 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_114 (
struct V_17 * V_17 ,
T_1 V_12 ,
int V_190 )
{
switch ( V_190 ) {
case V_191 :
case V_192 :
case V_193 :
return F_115 ( V_17 , V_12 , V_190 ) ;
case V_194 :
return F_110 ( V_17 , V_12 ) ;
case V_195 :
return F_113 ( V_17 , V_12 ) ;
default:
return - V_61 ;
}
}
