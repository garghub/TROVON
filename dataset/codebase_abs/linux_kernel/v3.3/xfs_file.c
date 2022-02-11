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
struct V_32 * V_33 ;
int error = 0 ;
int V_34 = 0 ;
T_3 V_26 = 0 ;
F_21 ( V_2 ) ;
error = F_22 ( V_31 -> V_11 , V_18 , V_19 ) ;
if ( error )
return error ;
if ( F_23 ( V_24 ) )
return - F_24 ( V_35 ) ;
F_25 ( V_2 , V_36 ) ;
if ( V_24 -> V_37 & V_38 ) {
if ( F_26 ( V_2 ) )
F_27 ( V_24 -> V_39 ) ;
else if ( V_24 -> V_40 != V_24 -> V_41 )
F_27 ( V_24 -> V_41 ) ;
}
F_4 ( V_2 , V_27 ) ;
if ( ( ( V_31 -> V_42 & V_43 ) ||
( ( V_31 -> V_42 & V_44 ) && ! V_20 ) ) &&
V_2 -> V_45 ) {
F_6 ( V_2 , V_27 ) ;
V_33 = F_28 ( V_24 , V_46 ) ;
error = F_29 ( V_33 , 0 ,
F_30 ( V_24 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_31 ( V_33 , 0 ) ;
return - error ;
}
F_4 ( V_2 , V_47 ) ;
F_32 ( V_33 , V_2 , 0 ) ;
F_33 ( V_33 , V_2 , V_48 ) ;
error = F_34 ( V_33 , 0 ) ;
V_26 = V_2 -> V_28 -> V_29 ;
F_6 ( V_2 , V_47 ) ;
} else {
if ( F_18 ( V_2 ) )
V_26 = V_2 -> V_28 -> V_29 ;
F_6 ( V_2 , V_27 ) ;
}
if ( ! error && V_26 )
error = F_19 ( V_24 , V_26 , V_30 , & V_34 ) ;
if ( ( V_24 -> V_37 & V_38 ) &&
V_24 -> V_40 == V_24 -> V_41 &&
! F_26 ( V_2 ) &&
! V_34 )
F_27 ( V_24 -> V_41 ) ;
return - error ;
}
STATIC T_4
F_35 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_2 V_55 = 0 ;
T_4 V_56 = 0 ;
int V_57 = 0 ;
T_5 V_58 ;
unsigned long V_59 ;
F_36 ( V_60 ) ;
F_37 ( V_50 -> V_61 != V_5 ) ;
if ( F_38 ( V_17 -> V_62 & V_63 ) )
V_57 |= V_64 ;
if ( V_17 -> V_65 & V_66 )
V_57 |= V_67 ;
for ( V_59 = 0 ; V_59 < V_53 ; V_59 ++ ) {
const struct V_51 * V_68 = & V_52 [ V_59 ] ;
V_55 += V_68 -> V_69 ;
if ( F_38 ( ( T_4 ) ( V_55 | V_68 -> V_69 ) < 0 ) )
return F_24 ( - V_70 ) ;
}
if ( F_38 ( V_57 & V_64 ) ) {
T_6 * V_71 =
F_26 ( V_2 ) ?
V_24 -> V_39 : V_24 -> V_41 ;
if ( ( V_50 -> V_61 & V_71 -> V_72 ) ||
( V_55 & V_71 -> V_72 ) ) {
if ( V_50 -> V_61 == F_39 ( V_31 ) )
return 0 ;
return - F_24 ( V_70 ) ;
}
}
V_58 = F_40 ( V_24 ) - V_50 -> V_61 ;
if ( V_58 <= 0 || V_55 == 0 )
return 0 ;
if ( V_58 < V_55 )
V_55 = V_58 ;
if ( F_23 ( V_24 ) )
return - V_35 ;
F_1 ( V_2 , V_73 ) ;
if ( ( V_57 & V_64 ) && V_31 -> V_11 -> V_74 ) {
F_5 ( V_2 , V_73 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_31 -> V_11 -> V_74 ) {
V_56 = - F_41 ( V_2 ,
( V_50 -> V_61 & V_75 ) ,
- 1 , V_76 ) ;
if ( V_56 ) {
F_5 ( V_2 , V_3 ) ;
return V_56 ;
}
}
F_8 ( V_2 , V_3 ) ;
}
F_42 ( V_2 , V_55 , V_50 -> V_61 , V_57 ) ;
V_56 = F_43 ( V_50 , V_52 , V_53 , V_50 -> V_61 ) ;
if ( V_56 > 0 )
F_44 ( V_77 , V_56 ) ;
F_5 ( V_2 , V_73 ) ;
return V_56 ;
}
STATIC T_4
F_45 (
struct V_17 * V_78 ,
T_1 * V_79 ,
struct V_80 * V_81 ,
T_2 V_6 ,
unsigned int V_82 )
{
struct V_1 * V_2 = F_16 ( V_78 -> V_21 -> V_22 ) ;
int V_57 = 0 ;
T_4 V_56 ;
F_36 ( V_60 ) ;
if ( V_78 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
F_1 ( V_2 , V_73 ) ;
F_46 ( V_2 , V_6 , * V_79 , V_57 ) ;
V_56 = F_47 ( V_78 , V_79 , V_81 , V_6 , V_82 ) ;
if ( V_56 > 0 )
F_44 ( V_77 , V_56 ) ;
F_5 ( V_2 , V_73 ) ;
return V_56 ;
}
STATIC T_4
F_48 (
struct V_80 * V_81 ,
struct V_17 * V_83 ,
T_1 * V_79 ,
T_2 V_6 ,
unsigned int V_82 )
{
struct V_31 * V_31 = V_83 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_57 = 0 ;
T_4 V_56 ;
F_36 ( V_84 ) ;
if ( V_83 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
F_4 ( V_2 , V_3 ) ;
F_49 ( V_2 , V_6 , * V_79 , V_57 ) ;
V_56 = F_50 ( V_81 , V_83 , V_79 , V_6 , V_82 ) ;
if ( V_56 > 0 )
F_44 ( V_85 , V_56 ) ;
F_6 ( V_2 , V_3 ) ;
return V_56 ;
}
STATIC int
F_51 (
T_7 * V_2 ,
T_5 V_12 ,
T_5 V_86 )
{
T_8 V_87 ;
T_9 * V_24 = V_2 -> V_25 ;
int V_88 ;
int V_89 ;
int V_90 ;
int error = 0 ;
T_10 V_91 ;
ASSERT ( F_52 ( V_2 , V_47 ) ) ;
V_89 = F_53 ( V_24 , V_86 ) ;
if ( V_89 == 0 ) {
return 0 ;
}
V_87 = F_54 ( V_24 , V_86 ) ;
V_88 = 1 ;
error = F_55 ( V_2 , V_87 , 1 , & V_91 , & V_88 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_88 > 0 ) ;
if ( V_91 . V_92 == V_93 ) {
return 0 ;
}
F_6 ( V_2 , V_47 ) ;
V_90 = V_24 -> V_94 . V_95 - V_89 ;
if ( V_86 + V_90 > V_12 )
V_90 = V_12 - V_86 ;
error = F_10 ( V_2 , V_86 , V_90 ) ;
F_4 ( V_2 , V_47 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_56 (
T_7 * V_2 ,
T_11 V_12 ,
T_5 V_86 )
{
T_9 * V_24 = V_2 -> V_25 ;
T_8 V_96 ;
T_8 V_97 ;
T_8 V_98 ;
T_8 V_87 ;
T_8 V_99 ;
T_5 V_90 ;
int V_88 ;
int error = 0 ;
T_10 V_91 ;
ASSERT ( F_52 ( V_2 , V_47 | V_3 ) ) ;
ASSERT ( V_12 > V_86 ) ;
error = F_51 ( V_2 , V_12 , V_86 ) ;
if ( error ) {
ASSERT ( F_52 ( V_2 , V_47 | V_3 ) ) ;
return error ;
}
V_87 = V_86 ? F_54 ( V_24 , V_86 - 1 ) : ( T_8 ) - 1 ;
V_96 = F_57 ( V_24 , ( V_100 ) V_86 ) ;
V_97 = F_54 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_101 ) V_87 < ( V_101 ) V_96 ) ;
if ( V_87 == V_97 ) {
return 0 ;
}
ASSERT ( V_96 <= V_97 ) ;
while ( V_96 <= V_97 ) {
V_88 = 1 ;
V_98 = V_97 - V_96 + 1 ;
error = F_55 ( V_2 , V_96 , V_98 ,
& V_91 , & V_88 , 0 ) ;
if ( error ) {
ASSERT ( F_52 ( V_2 , V_47 | V_3 ) ) ;
return error ;
}
ASSERT ( V_88 > 0 ) ;
if ( V_91 . V_102 == V_103 ||
V_91 . V_92 == V_93 ) {
V_96 = V_91 . V_104 + V_91 . V_105 ;
ASSERT ( V_96 <= ( V_97 + 1 ) ) ;
continue;
}
F_6 ( V_2 , V_47 ) ;
V_99 = F_58 ( V_24 , V_96 ) ;
V_90 = F_58 ( V_24 , V_91 . V_105 ) ;
if ( ( V_99 + V_90 ) > V_12 )
V_90 = V_12 - V_99 ;
error = F_10 ( V_2 , V_99 , V_90 ) ;
if ( error ) {
goto V_106;
}
V_96 = V_91 . V_104 + V_91 . V_105 ;
ASSERT ( V_96 <= ( V_97 + 1 ) ) ;
F_4 ( V_2 , V_47 ) ;
}
return 0 ;
V_106:
F_4 ( V_2 , V_47 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
STATIC T_4
F_59 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_107 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int error = 0 ;
F_1 ( V_2 , V_47 ) ;
V_108:
error = F_60 ( V_17 , V_5 , V_6 , F_61 ( V_31 -> V_109 ) ) ;
if ( error ) {
F_5 ( V_2 , V_47 ) ;
return error ;
}
if ( F_62 ( ! ( V_17 -> V_65 & V_66 ) ) )
F_63 ( V_17 ) ;
if ( * V_5 > F_39 ( V_31 ) ) {
if ( * V_107 == V_73 ) {
F_5 ( V_2 , V_47 | * V_107 ) ;
* V_107 = V_3 ;
F_1 ( V_2 , V_47 | * V_107 ) ;
goto V_108;
}
error = - F_56 ( V_2 , * V_5 , F_39 ( V_31 ) ) ;
}
F_5 ( V_2 , V_47 ) ;
if ( error )
return error ;
return F_64 ( V_17 ) ;
}
STATIC T_4
F_65 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_110 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_56 = 0 ;
T_2 V_6 = V_110 ;
int V_111 = 0 ;
int V_107 ;
struct V_112 * V_71 = F_26 ( V_2 ) ?
V_24 -> V_39 : V_24 -> V_41 ;
if ( ( V_5 & V_71 -> V_72 ) || ( V_6 & V_71 -> V_72 ) )
return - F_24 ( V_70 ) ;
if ( ( V_5 & V_24 -> V_113 ) || ( ( V_5 + V_6 ) & V_24 -> V_113 ) )
V_111 = 1 ;
if ( V_111 || V_9 -> V_74 )
V_107 = V_3 ;
else
V_107 = V_73 ;
F_1 ( V_2 , V_107 ) ;
if ( V_9 -> V_74 && V_107 == V_73 ) {
F_5 ( V_2 , V_107 ) ;
V_107 = V_3 ;
F_1 ( V_2 , V_107 ) ;
}
V_56 = F_59 ( V_17 , & V_5 , & V_6 , & V_107 ) ;
if ( V_56 )
goto V_114;
if ( V_9 -> V_74 ) {
V_56 = - F_41 ( V_2 , ( V_5 & V_75 ) , - 1 ,
V_76 ) ;
if ( V_56 )
goto V_114;
}
if ( V_111 )
F_66 ( V_31 ) ;
else if ( V_107 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
V_107 = V_73 ;
}
F_67 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_68 ( V_50 , V_52 ,
& V_53 , V_5 , & V_50 -> V_61 , V_6 , V_110 ) ;
V_114:
F_5 ( V_2 , V_107 ) ;
ASSERT ( V_56 < 0 || V_56 == V_6 ) ;
return V_56 ;
}
STATIC T_4
F_69 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_110 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_56 ;
int V_115 = 0 ;
int V_107 = V_3 ;
T_2 V_6 = V_110 ;
F_1 ( V_2 , V_107 ) ;
V_56 = F_59 ( V_17 , & V_5 , & V_6 , & V_107 ) ;
if ( V_56 )
goto V_114;
V_116 -> V_117 = V_9 -> V_117 ;
V_118:
F_70 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_71 ( V_50 , V_52 , V_53 ,
V_5 , & V_50 -> V_61 , V_6 , V_56 ) ;
if ( V_56 == - V_119 && ! V_115 ) {
V_115 = 1 ;
V_56 = - F_72 ( V_2 , 0 , - 1 , 0 , V_120 ) ;
if ( ! V_56 )
goto V_118;
}
V_116 -> V_117 = NULL ;
V_114:
F_5 ( V_2 , V_107 ) ;
return V_56 ;
}
STATIC T_4
F_73 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_56 ;
T_2 V_110 = 0 ;
F_36 ( V_84 ) ;
F_37 ( V_50 -> V_61 != V_5 ) ;
V_56 = F_74 ( V_52 , & V_53 , & V_110 , V_121 ) ;
if ( V_56 )
return V_56 ;
if ( V_110 == 0 )
return 0 ;
F_75 ( V_2 -> V_25 , V_122 ) ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
if ( F_38 ( V_17 -> V_62 & V_63 ) )
V_56 = F_65 ( V_50 , V_52 , V_53 , V_5 , V_110 ) ;
else
V_56 = F_69 ( V_50 , V_52 , V_53 , V_5 ,
V_110 ) ;
if ( V_56 > 0 ) {
T_4 V_123 ;
F_44 ( V_85 , V_56 ) ;
V_123 = F_76 ( V_17 , V_5 , V_56 ) ;
if ( V_123 < 0 )
V_56 = V_123 ;
}
return V_56 ;
}
STATIC long
F_77 (
struct V_17 * V_17 ,
int V_124 ,
T_1 V_12 ,
T_1 V_125 )
{
struct V_31 * V_31 = V_17 -> V_126 . V_127 -> V_128 ;
long error ;
T_1 V_129 = 0 ;
T_12 V_130 ;
T_7 * V_2 = F_16 ( V_31 ) ;
int V_131 = V_132 ;
int V_133 = V_134 ;
if ( V_124 & ~ ( V_135 | V_136 ) )
return - V_137 ;
V_130 . V_138 = 0 ;
V_130 . V_139 = V_12 ;
V_130 . V_140 = V_125 ;
F_4 ( V_2 , V_3 ) ;
if ( V_124 & V_136 )
V_131 = V_141 ;
if ( ! ( V_124 & V_135 ) &&
V_12 + V_125 > F_39 ( V_31 ) ) {
V_129 = V_12 + V_125 ;
error = F_78 ( V_31 , V_129 ) ;
if ( error )
goto V_142;
}
if ( V_17 -> V_62 & V_143 )
V_133 |= V_144 ;
error = - F_79 ( V_2 , V_131 , & V_130 , 0 , V_133 ) ;
if ( error )
goto V_142;
if ( V_129 ) {
struct V_145 V_145 ;
V_145 . V_146 = V_147 ;
V_145 . V_148 = V_129 ;
error = - F_80 ( V_2 , & V_145 , V_134 ) ;
}
V_142:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_81 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_62 & V_149 ) && F_39 ( V_31 ) > V_150 )
return - V_151 ;
if ( F_23 ( F_82 ( V_31 -> V_152 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_83 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_124 ;
int error ;
error = F_81 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_124 = F_84 ( V_2 ) ;
if ( V_2 -> V_153 . V_154 > 0 )
F_85 ( NULL , V_2 , 0 , V_155 ) ;
F_6 ( V_2 , V_124 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_31 * V_31 ,
struct V_17 * V_156 )
{
return - F_87 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_88 (
struct V_17 * V_156 ,
void * V_157 ,
T_13 V_158 )
{
struct V_31 * V_31 = V_156 -> V_126 . V_127 -> V_128 ;
T_7 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_159 ;
V_159 = ( T_2 ) F_89 ( T_1 , 32768 , V_2 -> V_153 . V_160 ) ;
error = F_90 ( V_2 , V_157 , V_159 ,
( T_11 * ) & V_156 -> V_161 , V_158 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_91 (
struct V_17 * V_156 ,
struct V_162 * V_163 )
{
V_163 -> V_164 = & V_165 ;
V_163 -> V_166 |= V_167 ;
F_92 ( V_156 ) ;
return 0 ;
}
STATIC int
F_93 (
struct V_162 * V_163 ,
struct V_168 * V_169 )
{
return F_94 ( V_163 , V_169 , V_170 ) ;
}
