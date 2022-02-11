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
STATIC int
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
if ( ( V_43 -> V_53 & V_61 -> V_62 ) ||
( V_48 & V_61 -> V_62 ) ) {
if ( V_43 -> V_53 == F_33 ( V_31 ) )
return 0 ;
return - F_24 ( V_63 ) ;
}
}
V_51 = V_24 -> V_64 -> V_65 - V_43 -> V_53 ;
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
V_49 = - F_34 ( V_2 ,
( V_43 -> V_53 & V_68 ) ,
- 1 , V_69 ) ;
if ( V_49 ) {
F_5 ( V_2 , V_3 ) ;
return V_49 ;
}
}
F_8 ( V_2 , V_3 ) ;
}
F_35 ( V_2 , V_48 , V_43 -> V_53 , V_50 ) ;
V_49 = F_36 ( V_43 , V_45 , V_46 , V_43 -> V_53 ) ;
if ( V_49 > 0 )
F_37 ( V_70 , V_49 ) ;
F_5 ( V_2 , V_66 ) ;
return V_49 ;
}
STATIC T_4
F_38 (
struct V_17 * V_71 ,
T_1 * V_72 ,
struct V_73 * V_74 ,
T_2 V_6 ,
unsigned int V_75 )
{
struct V_1 * V_2 = F_16 ( V_71 -> V_21 -> V_22 ) ;
int V_50 = 0 ;
T_4 V_49 ;
F_29 ( V_52 ) ;
if ( V_71 -> V_57 & V_58 )
V_50 |= V_59 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_1 ( V_2 , V_66 ) ;
F_39 ( V_2 , V_6 , * V_72 , V_50 ) ;
V_49 = F_40 ( V_71 , V_72 , V_74 , V_6 , V_75 ) ;
if ( V_49 > 0 )
F_37 ( V_70 , V_49 ) ;
F_5 ( V_2 , V_66 ) ;
return V_49 ;
}
STATIC T_4
F_41 (
struct V_73 * V_74 ,
struct V_17 * V_76 ,
T_1 * V_72 ,
T_2 V_6 ,
unsigned int V_75 )
{
struct V_31 * V_31 = V_76 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_50 = 0 ;
T_4 V_49 ;
F_29 ( V_77 ) ;
if ( V_76 -> V_57 & V_58 )
V_50 |= V_59 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_33 ;
F_4 ( V_2 , V_3 ) ;
F_42 ( V_2 , V_6 , * V_72 , V_50 ) ;
V_49 = F_43 ( V_74 , V_76 , V_72 , V_6 , V_75 ) ;
if ( V_49 > 0 )
F_37 ( V_78 , V_49 ) ;
F_6 ( V_2 , V_3 ) ;
return V_49 ;
}
STATIC int
F_44 (
struct V_1 * V_2 ,
T_5 V_12 ,
T_5 V_79 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_80 = F_45 ( V_24 , V_79 ) ;
int V_81 = F_46 ( V_24 , V_79 ) ;
int V_82 ;
int V_83 = 1 ;
int error = 0 ;
struct V_84 V_85 ;
F_4 ( V_2 , V_86 ) ;
error = F_47 ( V_2 , V_80 , 1 , & V_85 , & V_83 , 0 ) ;
F_6 ( V_2 , V_86 ) ;
if ( error )
return error ;
ASSERT ( V_83 > 0 ) ;
if ( V_85 . V_87 == V_88 )
return 0 ;
V_82 = V_24 -> V_89 . V_90 - V_81 ;
if ( V_79 + V_82 > V_12 )
V_82 = V_12 - V_79 ;
return F_10 ( V_2 , V_79 , V_82 ) ;
}
int
F_48 (
struct V_1 * V_2 ,
T_8 V_12 ,
T_5 V_79 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
T_7 V_91 ;
T_7 V_92 ;
T_7 V_93 ;
T_7 V_80 ;
T_7 V_94 ;
T_5 V_82 ;
int V_83 ;
int error = 0 ;
struct V_84 V_85 ;
ASSERT ( F_49 ( V_2 , V_3 ) ) ;
ASSERT ( V_12 > V_79 ) ;
if ( F_46 ( V_24 , V_79 ) != 0 ) {
error = F_44 ( V_2 , V_12 , V_79 ) ;
if ( error )
return error ;
}
V_80 = V_79 ? F_45 ( V_24 , V_79 - 1 ) : ( T_7 ) - 1 ;
V_91 = F_50 ( V_24 , ( V_95 ) V_79 ) ;
V_92 = F_45 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_96 ) V_80 < ( V_96 ) V_91 ) ;
if ( V_80 == V_92 ) {
return 0 ;
}
ASSERT ( V_91 <= V_92 ) ;
while ( V_91 <= V_92 ) {
V_83 = 1 ;
V_93 = V_92 - V_91 + 1 ;
F_4 ( V_2 , V_86 ) ;
error = F_47 ( V_2 , V_91 , V_93 ,
& V_85 , & V_83 , 0 ) ;
F_6 ( V_2 , V_86 ) ;
if ( error )
return error ;
ASSERT ( V_83 > 0 ) ;
if ( V_85 . V_97 == V_98 ||
V_85 . V_87 == V_88 ) {
V_91 = V_85 . V_99 + V_85 . V_100 ;
ASSERT ( V_91 <= ( V_92 + 1 ) ) ;
continue;
}
V_94 = F_51 ( V_24 , V_91 ) ;
V_82 = F_51 ( V_24 , V_85 . V_100 ) ;
if ( ( V_94 + V_82 ) > V_12 )
V_82 = V_12 - V_94 ;
error = F_10 ( V_2 , V_94 , V_82 ) ;
if ( error )
return error ;
V_91 = V_85 . V_99 + V_85 . V_100 ;
ASSERT ( V_91 <= ( V_92 + 1 ) ) ;
}
return 0 ;
}
STATIC T_4
F_52 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_101 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int error = 0 ;
V_102:
error = F_53 ( V_17 , V_5 , V_6 , F_54 ( V_31 -> V_103 ) ) ;
if ( error )
return error ;
if ( * V_5 > F_33 ( V_31 ) ) {
if ( * V_101 == V_66 ) {
F_5 ( V_2 , * V_101 ) ;
* V_101 = V_3 ;
F_1 ( V_2 , * V_101 ) ;
goto V_102;
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
T_2 V_104 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_49 = 0 ;
T_2 V_6 = V_104 ;
int V_105 = 0 ;
int V_101 ;
struct V_106 * V_61 = F_26 ( V_2 ) ?
V_24 -> V_37 : V_24 -> V_39 ;
if ( ( V_5 & V_61 -> V_62 ) || ( V_6 & V_61 -> V_62 ) )
return - F_24 ( V_63 ) ;
if ( ( V_5 & V_24 -> V_107 ) || ( ( V_5 + V_6 ) & V_24 -> V_107 ) )
V_105 = 1 ;
if ( V_105 || V_9 -> V_67 )
V_101 = V_3 ;
else
V_101 = V_66 ;
F_1 ( V_2 , V_101 ) ;
if ( V_9 -> V_67 && V_101 == V_66 ) {
F_5 ( V_2 , V_101 ) ;
V_101 = V_3 ;
F_1 ( V_2 , V_101 ) ;
}
V_49 = F_52 ( V_17 , & V_5 , & V_6 , & V_101 ) ;
if ( V_49 )
goto V_108;
if ( V_9 -> V_67 ) {
V_49 = - F_34 ( V_2 , ( V_5 & V_68 ) , - 1 ,
V_69 ) ;
if ( V_49 )
goto V_108;
}
if ( V_105 )
F_59 ( V_31 ) ;
else if ( V_101 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_101 = V_66 ;
}
F_60 ( V_2 , V_6 , V_43 -> V_53 , 0 ) ;
V_49 = F_61 ( V_43 , V_45 ,
& V_46 , V_5 , & V_43 -> V_53 , V_6 , V_104 ) ;
V_108:
F_5 ( V_2 , V_101 ) ;
ASSERT ( V_49 < 0 || V_49 == V_6 ) ;
return V_49 ;
}
STATIC T_4
F_62 (
struct V_42 * V_43 ,
const struct V_44 * V_45 ,
unsigned long V_46 ,
T_1 V_5 ,
T_2 V_104 )
{
struct V_17 * V_17 = V_43 -> V_47 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_49 ;
int V_109 = 0 ;
int V_101 = V_3 ;
T_2 V_6 = V_104 ;
F_1 ( V_2 , V_101 ) ;
V_49 = F_52 ( V_17 , & V_5 , & V_6 , & V_101 ) ;
if ( V_49 )
goto V_108;
V_110 -> V_111 = V_9 -> V_111 ;
V_112:
F_63 ( V_2 , V_6 , V_43 -> V_53 , 0 ) ;
V_49 = F_64 ( V_43 , V_45 , V_46 ,
V_5 , & V_43 -> V_53 , V_6 , V_49 ) ;
if ( V_49 == - V_113 && ! V_109 ) {
V_109 = 1 ;
V_49 = - F_65 ( V_2 , 0 , - 1 , 0 , V_114 ) ;
if ( ! V_49 )
goto V_112;
}
V_110 -> V_111 = NULL ;
V_108:
F_5 ( V_2 , V_101 ) ;
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
T_2 V_104 = 0 ;
F_29 ( V_77 ) ;
F_30 ( V_43 -> V_53 != V_5 ) ;
V_49 = F_32 ( V_45 , & V_46 , & V_104 , V_115 ) ;
if ( V_49 )
return V_49 ;
if ( V_104 == 0 )
return 0 ;
F_67 ( V_31 -> V_116 ) ;
if ( F_23 ( V_2 -> V_25 ) ) {
V_49 = - V_33 ;
goto V_108;
}
if ( F_31 ( V_17 -> V_54 & V_55 ) )
V_49 = F_58 ( V_43 , V_45 , V_46 , V_5 , V_104 ) ;
else
V_49 = F_62 ( V_43 , V_45 , V_46 , V_5 ,
V_104 ) ;
if ( V_49 > 0 ) {
T_4 V_117 ;
F_37 ( V_78 , V_49 ) ;
V_117 = F_68 ( V_17 , V_5 , V_49 ) ;
if ( V_117 < 0 )
V_49 = V_117 ;
}
V_108:
F_69 ( V_31 -> V_116 ) ;
return V_49 ;
}
STATIC long
F_70 (
struct V_17 * V_17 ,
int V_118 ,
T_1 V_12 ,
T_1 V_119 )
{
struct V_31 * V_31 = V_17 -> V_120 . V_121 -> V_122 ;
long error ;
T_1 V_123 = 0 ;
T_9 V_124 ;
T_10 * V_2 = F_16 ( V_31 ) ;
int V_125 = V_126 ;
int V_127 = V_128 ;
if ( V_118 & ~ ( V_129 | V_130 ) )
return - V_131 ;
V_124 . V_132 = 0 ;
V_124 . V_133 = V_12 ;
V_124 . V_134 = V_119 ;
F_4 ( V_2 , V_3 ) ;
if ( V_118 & V_130 )
V_125 = V_135 ;
if ( ! ( V_118 & V_129 ) &&
V_12 + V_119 > F_33 ( V_31 ) ) {
V_123 = V_12 + V_119 ;
error = F_71 ( V_31 , V_123 ) ;
if ( error )
goto V_136;
}
if ( V_17 -> V_54 & V_137 )
V_127 |= V_138 ;
error = - F_72 ( V_2 , V_125 , & V_124 , 0 , V_127 ) ;
if ( error )
goto V_136;
if ( V_123 ) {
struct V_139 V_139 ;
V_139 . V_140 = V_141 ;
V_139 . V_142 = V_123 ;
error = - F_73 ( V_2 , & V_139 , V_128 ) ;
}
V_136:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_74 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_54 & V_143 ) && F_33 ( V_31 ) > V_144 )
return - V_145 ;
if ( F_23 ( F_75 ( V_31 -> V_116 ) ) )
return - V_33 ;
return 0 ;
}
STATIC int
F_76 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_118 ;
int error ;
error = F_74 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_118 = F_77 ( V_2 ) ;
if ( V_2 -> V_146 . V_147 > 0 )
F_78 ( NULL , V_2 , 0 , V_148 ) ;
F_6 ( V_2 , V_118 ) ;
return 0 ;
}
STATIC int
F_79 (
struct V_31 * V_31 ,
struct V_17 * V_149 )
{
return - F_80 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_81 (
struct V_17 * V_149 ,
void * V_150 ,
T_11 V_151 )
{
struct V_31 * V_31 = V_149 -> V_120 . V_121 -> V_122 ;
T_10 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_152 ;
V_152 = ( T_2 ) F_82 ( T_1 , 32768 , V_2 -> V_146 . V_153 ) ;
error = F_83 ( V_2 , V_150 , V_152 ,
( T_8 * ) & V_149 -> V_154 , V_151 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_84 (
struct V_17 * V_149 ,
struct V_155 * V_156 )
{
V_156 -> V_157 = & V_158 ;
F_85 ( V_149 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_155 * V_156 ,
struct V_159 * V_160 )
{
return F_87 ( V_156 , V_160 , V_161 ) ;
}
STATIC bool
F_88 (
struct V_7 * V_7 ,
T_1 * V_12 ,
unsigned int type )
{
T_1 V_162 = F_89 ( V_7 ) ;
bool V_163 = false ;
struct V_164 * V_165 , * V_166 ;
V_165 = V_166 = F_90 ( V_7 ) ;
do {
if ( F_91 ( V_165 ) ||
F_92 ( V_165 ) ) {
if ( type == V_167 )
V_163 = true ;
} else {
if ( type == V_168 )
V_163 = true ;
}
if ( V_163 ) {
* V_12 = V_162 ;
break;
}
V_162 += V_165 -> V_169 ;
} while ( ( V_165 = V_165 -> V_170 ) != V_166 );
return V_163 ;
}
STATIC bool
F_93 (
struct V_31 * V_31 ,
struct V_84 * V_171 ,
unsigned int type ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_172 V_173 ;
T_12 V_174 ;
T_12 V_19 ;
T_1 V_175 ;
T_1 V_176 = * V_12 ;
T_1 V_162 = V_176 ;
bool V_163 = false ;
F_94 ( & V_173 , 0 ) ;
V_174 = V_176 >> V_177 ;
V_175 = F_51 ( V_24 , V_171 -> V_99 + V_171 -> V_100 ) ;
V_19 = V_175 >> V_177 ;
do {
int V_178 ;
unsigned V_179 ;
unsigned int V_180 ;
V_178 = F_82 ( T_12 , V_19 - V_174 , V_181 ) ;
V_179 = F_95 ( & V_173 , V_31 -> V_11 , V_174 ,
V_178 ) ;
if ( V_179 == 0 ) {
if ( type == V_167 )
break;
ASSERT ( type == V_168 ) ;
if ( V_162 == V_176 || V_162 < V_175 ) {
V_163 = true ;
* V_12 = V_162 ;
}
break;
}
if ( type == V_168 && V_162 == V_176 &&
V_162 < F_89 ( V_173 . V_182 [ 0 ] ) ) {
V_163 = true ;
break;
}
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
struct V_7 * V_7 = V_173 . V_182 [ V_180 ] ;
T_1 V_183 ;
if ( V_7 -> V_174 > V_19 ) {
if ( type == V_168 && V_162 < V_175 ) {
* V_12 = V_162 ;
V_163 = true ;
}
goto V_108;
}
F_96 ( V_7 ) ;
if ( F_31 ( V_7 -> V_9 != V_31 -> V_11 ) ) {
F_97 ( V_7 ) ;
continue;
}
if ( ! F_98 ( V_7 ) ) {
F_97 ( V_7 ) ;
continue;
}
V_163 = F_88 ( V_7 , & V_183 , type ) ;
if ( V_163 ) {
* V_12 = F_99 ( T_1 , V_176 , V_183 ) ;
F_97 ( V_7 ) ;
goto V_108;
}
V_162 = F_89 ( V_7 ) + V_184 ;
F_97 ( V_7 ) ;
}
if ( V_179 < V_178 ) {
if ( type == V_168 ) {
* V_12 = V_162 ;
V_163 = true ;
}
break;
}
V_174 = V_173 . V_182 [ V_180 - 1 ] -> V_174 + 1 ;
F_100 ( & V_173 ) ;
} while ( V_174 <= V_19 );
V_108:
F_100 ( & V_173 ) ;
return V_163 ;
}
STATIC T_1
F_101 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_185 ( V_12 ) ;
T_5 V_79 ;
T_7 V_186 ;
T_13 V_19 ;
T_14 V_187 ;
int error ;
V_187 = F_77 ( V_2 ) ;
V_79 = F_33 ( V_31 ) ;
if ( V_18 >= V_79 ) {
error = V_188 ;
goto V_136;
}
V_186 = F_45 ( V_24 , V_18 ) ;
V_19 = F_50 ( V_24 , V_79 ) ;
for (; ; ) {
struct V_84 V_171 [ 2 ] ;
int V_189 = 2 ;
unsigned int V_180 ;
error = F_47 ( V_2 , V_186 , V_19 - V_186 , V_171 , & V_189 ,
V_190 ) ;
if ( error )
goto V_136;
if ( V_189 == 0 ) {
error = V_188 ;
goto V_136;
}
for ( V_180 = 0 ; V_180 < V_189 ; V_180 ++ ) {
V_12 = F_99 ( T_1 , V_18 ,
F_51 ( V_24 , V_171 [ V_180 ] . V_99 ) ) ;
if ( V_171 [ V_180 ] . V_87 == V_191 ||
( V_171 [ V_180 ] . V_97 == V_192 &&
! F_102 ( V_171 [ V_180 ] . V_87 ) ) )
goto V_108;
if ( V_171 [ V_180 ] . V_97 == V_98 ) {
if ( F_93 ( V_31 , & V_171 [ V_180 ] ,
V_167 , & V_12 ) )
goto V_108;
}
}
if ( V_189 == 1 ) {
error = V_188 ;
goto V_136;
}
ASSERT ( V_180 > 1 ) ;
V_186 = V_171 [ V_180 - 1 ] . V_99 + V_171 [ V_180 - 1 ] . V_100 ;
V_18 = F_51 ( V_24 , V_186 ) ;
if ( V_18 >= V_79 ) {
error = V_188 ;
goto V_136;
}
}
V_108:
if ( V_12 != V_17 -> V_154 )
V_17 -> V_154 = V_12 ;
V_136:
F_103 ( V_2 , V_187 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_104 (
struct V_17 * V_17 ,
T_1 V_18 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_1 V_185 ( V_12 ) ;
T_5 V_79 ;
T_7 V_186 ;
T_13 V_19 ;
T_14 V_187 ;
int error ;
if ( F_23 ( V_24 ) )
return - F_24 ( V_33 ) ;
V_187 = F_77 ( V_2 ) ;
V_79 = F_33 ( V_31 ) ;
if ( V_18 >= V_79 ) {
error = V_188 ;
goto V_136;
}
V_186 = F_45 ( V_24 , V_18 ) ;
V_19 = F_50 ( V_24 , V_79 ) ;
for (; ; ) {
struct V_84 V_171 [ 2 ] ;
int V_189 = 2 ;
unsigned int V_180 ;
error = F_47 ( V_2 , V_186 , V_19 - V_186 , V_171 , & V_189 ,
V_190 ) ;
if ( error )
goto V_136;
if ( V_189 == 0 ) {
error = V_188 ;
goto V_136;
}
for ( V_180 = 0 ; V_180 < V_189 ; V_180 ++ ) {
V_12 = F_99 ( T_1 , V_18 ,
F_51 ( V_24 , V_171 [ V_180 ] . V_99 ) ) ;
if ( V_171 [ V_180 ] . V_87 == V_88 )
goto V_108;
if ( V_171 [ V_180 ] . V_97 == V_98 ) {
if ( F_93 ( V_31 , & V_171 [ V_180 ] ,
V_168 , & V_12 ) )
goto V_108;
}
}
if ( V_189 == 1 ) {
V_12 = V_79 ;
break;
}
ASSERT ( V_180 > 1 ) ;
V_186 = V_171 [ V_180 - 1 ] . V_99 + V_171 [ V_180 - 1 ] . V_100 ;
V_18 = F_51 ( V_24 , V_186 ) ;
if ( V_18 >= V_79 ) {
V_12 = V_79 ;
break;
}
}
V_108:
V_12 = F_82 ( T_1 , V_12 , V_79 ) ;
if ( V_12 != V_17 -> V_154 )
V_17 -> V_154 = V_12 ;
V_136:
F_103 ( V_2 , V_187 ) ;
if ( error )
return - error ;
return V_12 ;
}
STATIC T_1
F_105 (
struct V_17 * V_17 ,
T_1 V_12 ,
int V_193 )
{
switch ( V_193 ) {
case V_194 :
case V_195 :
case V_196 :
return F_106 ( V_17 , V_12 , V_193 ) ;
case V_197 :
return F_101 ( V_17 , V_12 ) ;
case V_198 :
return F_104 ( V_17 , V_12 ) ;
default:
return - V_63 ;
}
}
