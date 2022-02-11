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
struct V_21 * V_21 = V_17 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 ;
int error = 0 ;
int V_29 = 0 ;
F_17 ( V_2 ) ;
error = F_18 ( V_21 -> V_11 , V_18 , V_19 ) ;
if ( error )
return error ;
if ( F_19 ( V_25 ) )
return - F_20 ( V_30 ) ;
F_21 ( V_2 , V_31 ) ;
F_4 ( V_2 , V_32 ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 , V_32 ) ;
if ( V_25 -> V_33 & V_34 ) {
if ( F_23 ( V_2 ) )
F_24 ( V_25 -> V_35 ) ;
else if ( V_25 -> V_36 != V_25 -> V_37 )
F_24 ( V_25 -> V_37 ) ;
}
F_4 ( V_2 , V_38 ) ;
if ( ( ( V_21 -> V_39 & V_40 ) ||
( ( V_21 -> V_39 & V_41 ) && ! V_20 ) ) &&
V_2 -> V_42 ) {
F_6 ( V_2 , V_38 ) ;
V_28 = F_25 ( V_25 , V_43 ) ;
error = F_26 ( V_28 , 0 ,
F_27 ( V_25 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_28 ( V_28 , 0 ) ;
return - error ;
}
F_4 ( V_2 , V_44 ) ;
F_29 ( V_28 , V_2 ) ;
F_30 ( V_28 , V_2 , V_45 ) ;
F_31 ( V_28 ) ;
error = F_32 ( V_28 , 0 , & V_29 ) ;
F_6 ( V_2 , V_44 ) ;
} else {
if ( F_33 ( V_2 ) ) {
error = F_34 ( V_25 ,
V_2 -> V_46 -> V_47 ,
V_48 , & V_29 ) ;
}
F_6 ( V_2 , V_38 ) ;
}
if ( ( V_25 -> V_33 & V_34 ) &&
V_25 -> V_36 == V_25 -> V_37 &&
! F_23 ( V_2 ) &&
! V_29 )
F_24 ( V_25 -> V_37 ) ;
return - error ;
}
STATIC T_3
F_35 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_21 * V_21 = V_17 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_2 V_55 = 0 ;
T_3 V_56 = 0 ;
int V_57 = 0 ;
T_4 V_58 ;
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
if ( F_38 ( ( T_3 ) ( V_55 | V_68 -> V_69 ) < 0 ) )
return F_20 ( - V_70 ) ;
}
if ( F_38 ( V_57 & V_64 ) ) {
T_5 * V_71 =
F_23 ( V_2 ) ?
V_25 -> V_35 : V_25 -> V_37 ;
if ( ( V_50 -> V_61 & V_71 -> V_72 ) ||
( V_55 & V_71 -> V_72 ) ) {
if ( V_50 -> V_61 == V_2 -> V_73 )
return 0 ;
return - F_20 ( V_70 ) ;
}
}
V_58 = F_39 ( V_25 ) - V_50 -> V_61 ;
if ( V_58 <= 0 || V_55 == 0 )
return 0 ;
if ( V_58 < V_55 )
V_55 = V_58 ;
if ( F_19 ( V_25 ) )
return - V_30 ;
if ( F_38 ( V_57 & V_64 ) ) {
F_1 ( V_2 , V_3 ) ;
if ( V_21 -> V_11 -> V_74 ) {
V_56 = - F_40 ( V_2 ,
( V_50 -> V_61 & V_75 ) ,
- 1 , V_76 ) ;
if ( V_56 ) {
F_5 ( V_2 , V_3 ) ;
return V_56 ;
}
}
F_8 ( V_2 , V_3 ) ;
} else
F_1 ( V_2 , V_32 ) ;
F_41 ( V_2 , V_55 , V_50 -> V_61 , V_57 ) ;
V_56 = F_42 ( V_50 , V_52 , V_53 , V_50 -> V_61 ) ;
if ( V_56 > 0 )
F_43 ( V_77 , V_56 ) ;
F_5 ( V_2 , V_32 ) ;
return V_56 ;
}
STATIC T_3
F_44 (
struct V_17 * V_78 ,
T_1 * V_79 ,
struct V_80 * V_81 ,
T_2 V_6 ,
unsigned int V_82 )
{
struct V_1 * V_2 = F_16 ( V_78 -> V_22 -> V_23 ) ;
int V_57 = 0 ;
T_3 V_56 ;
F_36 ( V_60 ) ;
if ( V_78 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_19 ( V_2 -> V_26 ) )
return - V_30 ;
F_1 ( V_2 , V_32 ) ;
F_45 ( V_2 , V_6 , * V_79 , V_57 ) ;
V_56 = F_46 ( V_78 , V_79 , V_81 , V_6 , V_82 ) ;
if ( V_56 > 0 )
F_43 ( V_77 , V_56 ) ;
F_5 ( V_2 , V_32 ) ;
return V_56 ;
}
STATIC void
F_47 (
struct V_21 * V_21 ,
T_1 * V_79 ,
T_3 V_83 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_4 V_84 = F_48 ( V_21 ) ;
if ( V_83 > 0 )
F_43 ( V_85 , V_83 ) ;
if ( F_38 ( V_83 < 0 && V_83 != - V_86 &&
* V_79 > V_84 ) )
* V_79 = V_84 ;
if ( * V_79 > V_2 -> V_73 ) {
F_1 ( V_2 , V_44 ) ;
if ( * V_79 > V_2 -> V_73 )
V_2 -> V_73 = * V_79 ;
F_5 ( V_2 , V_44 ) ;
}
}
STATIC void
F_49 (
struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_1 ( V_2 , V_44 ) ;
V_2 -> V_87 = 0 ;
if ( V_2 -> V_88 . V_89 > V_2 -> V_73 )
V_2 -> V_88 . V_89 = V_2 -> V_73 ;
F_5 ( V_2 , V_44 ) ;
}
}
STATIC T_3
F_50 (
struct V_80 * V_81 ,
struct V_17 * V_90 ,
T_1 * V_79 ,
T_2 V_6 ,
unsigned int V_82 )
{
struct V_21 * V_21 = V_90 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_4 V_91 ;
int V_57 = 0 ;
T_3 V_56 ;
F_36 ( V_92 ) ;
if ( V_90 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_19 ( V_2 -> V_26 ) )
return - V_30 ;
F_4 ( V_2 , V_3 ) ;
V_91 = * V_79 + V_6 ;
F_4 ( V_2 , V_44 ) ;
if ( V_91 > V_2 -> V_73 )
V_2 -> V_87 = V_91 ;
F_6 ( V_2 , V_44 ) ;
F_51 ( V_2 , V_6 , * V_79 , V_57 ) ;
V_56 = F_52 ( V_81 , V_90 , V_79 , V_6 , V_82 ) ;
F_47 ( V_21 , V_79 , V_56 ) ;
F_49 ( V_2 ) ;
F_6 ( V_2 , V_3 ) ;
return V_56 ;
}
STATIC int
F_53 (
T_6 * V_2 ,
T_4 V_12 ,
T_4 V_84 )
{
T_7 V_93 ;
T_8 * V_25 = V_2 -> V_26 ;
int V_94 ;
int V_95 ;
int V_96 ;
int error = 0 ;
T_9 V_97 ;
ASSERT ( F_54 ( V_2 , V_44 ) ) ;
V_95 = F_55 ( V_25 , V_84 ) ;
if ( V_95 == 0 ) {
return 0 ;
}
V_93 = F_56 ( V_25 , V_84 ) ;
V_94 = 1 ;
error = F_57 ( NULL , V_2 , V_93 , 1 , 0 , NULL , 0 , & V_97 ,
& V_94 , NULL ) ;
if ( error ) {
return error ;
}
ASSERT ( V_94 > 0 ) ;
if ( V_97 . V_98 == V_99 ) {
return 0 ;
}
F_6 ( V_2 , V_44 ) ;
V_96 = V_25 -> V_100 . V_101 - V_95 ;
if ( V_84 + V_96 > V_12 )
V_96 = V_12 - V_84 ;
error = F_10 ( V_2 , V_84 , V_96 ) ;
F_4 ( V_2 , V_44 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_58 (
T_6 * V_2 ,
T_10 V_12 ,
T_4 V_84 )
{
T_8 * V_25 = V_2 -> V_26 ;
T_7 V_102 ;
T_7 V_103 ;
T_7 V_104 ;
T_7 V_93 ;
T_7 V_105 ;
T_4 V_96 ;
int V_94 ;
int error = 0 ;
T_9 V_97 ;
ASSERT ( F_54 ( V_2 , V_44 | V_3 ) ) ;
ASSERT ( V_12 > V_84 ) ;
error = F_53 ( V_2 , V_12 , V_84 ) ;
if ( error ) {
ASSERT ( F_54 ( V_2 , V_44 | V_3 ) ) ;
return error ;
}
V_93 = V_84 ? F_56 ( V_25 , V_84 - 1 ) : ( T_7 ) - 1 ;
V_102 = F_59 ( V_25 , ( V_106 ) V_84 ) ;
V_103 = F_56 ( V_25 , V_12 - 1 ) ;
ASSERT ( ( V_107 ) V_93 < ( V_107 ) V_102 ) ;
if ( V_93 == V_103 ) {
return 0 ;
}
ASSERT ( V_102 <= V_103 ) ;
while ( V_102 <= V_103 ) {
V_94 = 1 ;
V_104 = V_103 - V_102 + 1 ;
error = F_57 ( NULL , V_2 , V_102 , V_104 ,
0 , NULL , 0 , & V_97 , & V_94 , NULL ) ;
if ( error ) {
ASSERT ( F_54 ( V_2 , V_44 | V_3 ) ) ;
return error ;
}
ASSERT ( V_94 > 0 ) ;
if ( V_97 . V_108 == V_109 ||
V_97 . V_98 == V_99 ) {
V_102 = V_97 . V_110 + V_97 . V_111 ;
ASSERT ( V_102 <= ( V_103 + 1 ) ) ;
continue;
}
F_6 ( V_2 , V_44 ) ;
V_105 = F_60 ( V_25 , V_102 ) ;
V_96 = F_60 ( V_25 , V_97 . V_111 ) ;
if ( ( V_105 + V_96 ) > V_12 )
V_96 = V_12 - V_105 ;
error = F_10 ( V_2 , V_105 , V_96 ) ;
if ( error ) {
goto V_112;
}
V_102 = V_97 . V_110 + V_97 . V_111 ;
ASSERT ( V_102 <= ( V_103 + 1 ) ) ;
F_4 ( V_2 , V_44 ) ;
}
return 0 ;
V_112:
F_4 ( V_2 , V_44 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
STATIC T_3
F_61 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_113 )
{
struct V_21 * V_21 = V_17 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_4 V_91 ;
int error = 0 ;
error = F_62 ( V_17 , V_5 , V_6 , F_63 ( V_21 -> V_114 ) ) ;
if ( error ) {
F_5 ( V_2 , V_44 | * V_113 ) ;
* V_113 = 0 ;
return error ;
}
V_91 = * V_5 + * V_6 ;
if ( V_91 > V_2 -> V_73 )
V_2 -> V_87 = V_91 ;
if ( F_64 ( ! ( V_17 -> V_65 & V_66 ) ) )
F_65 ( V_17 ) ;
if ( * V_5 > V_2 -> V_73 )
error = - F_58 ( V_2 , * V_5 , V_2 -> V_73 ) ;
F_5 ( V_2 , V_44 ) ;
if ( error )
return error ;
return F_66 ( V_17 ) ;
}
STATIC T_3
F_67 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_115 ,
int * V_113 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_22 ;
struct V_21 * V_21 = V_9 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_3 V_56 = 0 ;
T_2 V_6 = V_115 ;
int V_116 = 0 ;
struct V_117 * V_71 = F_23 ( V_2 ) ?
V_25 -> V_35 : V_25 -> V_37 ;
* V_113 = 0 ;
if ( ( V_5 & V_71 -> V_72 ) || ( V_6 & V_71 -> V_72 ) )
return - F_20 ( V_70 ) ;
if ( ( V_5 & V_25 -> V_118 ) || ( ( V_5 + V_6 ) & V_25 -> V_118 ) )
V_116 = 1 ;
if ( V_116 || V_9 -> V_74 || V_5 > V_2 -> V_73 )
* V_113 = V_3 ;
else
* V_113 = V_32 ;
F_1 ( V_2 , V_44 | * V_113 ) ;
V_56 = F_61 ( V_17 , & V_5 , & V_6 , V_113 ) ;
if ( V_56 )
return V_56 ;
if ( V_9 -> V_74 ) {
F_14 ( * V_113 != V_3 ) ;
V_56 = - F_40 ( V_2 , ( V_5 & V_75 ) , - 1 ,
V_76 ) ;
if ( V_56 )
return V_56 ;
}
if ( V_116 )
F_22 ( V_2 ) ;
else if ( * V_113 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
* V_113 = V_32 ;
}
F_68 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_69 ( V_50 , V_52 ,
& V_53 , V_5 , & V_50 -> V_61 , V_6 , V_115 ) ;
ASSERT ( V_56 < 0 || V_56 == V_6 ) ;
return V_56 ;
}
STATIC T_3
F_70 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_115 ,
int * V_113 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_22 ;
struct V_21 * V_21 = V_9 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_3 V_56 ;
int V_119 = 0 ;
T_2 V_6 = V_115 ;
* V_113 = V_3 ;
F_1 ( V_2 , V_44 | * V_113 ) ;
V_56 = F_61 ( V_17 , & V_5 , & V_6 , V_113 ) ;
if ( V_56 )
return V_56 ;
V_120 -> V_121 = V_9 -> V_121 ;
V_122:
F_71 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_72 ( V_50 , V_52 , V_53 ,
V_5 , & V_50 -> V_61 , V_6 , V_56 ) ;
if ( V_56 == - V_123 && ! V_119 ) {
V_56 = - F_73 ( V_2 , 0 , - 1 , 0 , V_124 ) ;
if ( V_56 )
return V_56 ;
V_119 = 1 ;
goto V_122;
}
V_120 -> V_121 = NULL ;
return V_56 ;
}
STATIC T_3
F_74 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_22 ;
struct V_21 * V_21 = V_9 -> V_23 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_3 V_56 ;
int V_113 ;
T_2 V_115 = 0 ;
F_36 ( V_92 ) ;
F_37 ( V_50 -> V_61 != V_5 ) ;
V_56 = F_75 ( V_52 , & V_53 , & V_115 , V_125 ) ;
if ( V_56 )
return V_56 ;
if ( V_115 == 0 )
return 0 ;
F_76 ( V_2 -> V_26 , V_126 ) ;
if ( F_19 ( V_2 -> V_26 ) )
return - V_30 ;
if ( F_38 ( V_17 -> V_62 & V_63 ) )
V_56 = F_67 ( V_50 , V_52 , V_53 , V_5 ,
V_115 , & V_113 ) ;
else
V_56 = F_70 ( V_50 , V_52 , V_53 , V_5 ,
V_115 , & V_113 ) ;
F_47 ( V_21 , & V_50 -> V_61 , V_56 ) ;
if ( V_56 <= 0 )
goto V_127;
if ( ( V_17 -> V_62 & V_128 ) || F_77 ( V_21 ) ) {
T_1 V_19 = V_5 + V_56 - 1 ;
int error ;
F_5 ( V_2 , V_113 ) ;
error = F_15 ( V_17 , V_5 , V_19 ,
( V_17 -> V_62 & V_129 ) ? 0 : 1 ) ;
F_1 ( V_2 , V_113 ) ;
if ( error )
V_56 = error ;
}
V_127:
F_49 ( V_2 ) ;
F_5 ( V_2 , V_113 ) ;
return V_56 ;
}
STATIC long
F_78 (
struct V_17 * V_17 ,
int V_130 ,
T_1 V_12 ,
T_1 V_131 )
{
struct V_21 * V_21 = V_17 -> V_132 . V_133 -> V_134 ;
long error ;
T_1 V_91 = 0 ;
T_11 V_135 ;
T_6 * V_2 = F_16 ( V_21 ) ;
int V_136 = V_137 ;
int V_138 = V_139 ;
if ( V_130 & ~ ( V_140 | V_141 ) )
return - V_142 ;
V_135 . V_143 = 0 ;
V_135 . V_144 = V_12 ;
V_135 . V_145 = V_131 ;
F_4 ( V_2 , V_3 ) ;
if ( V_130 & V_141 )
V_136 = V_146 ;
if ( ! ( V_130 & V_140 ) &&
V_12 + V_131 > F_48 ( V_21 ) ) {
V_91 = V_12 + V_131 ;
error = F_79 ( V_21 , V_91 ) ;
if ( error )
goto V_127;
}
if ( V_17 -> V_62 & V_128 )
V_138 |= V_147 ;
error = - F_80 ( V_2 , V_136 , & V_135 , 0 , V_138 ) ;
if ( error )
goto V_127;
if ( V_91 ) {
struct V_148 V_148 ;
V_148 . V_149 = V_150 ;
V_148 . V_151 = V_91 ;
error = - F_81 ( V_2 , & V_148 , V_139 ) ;
}
V_127:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_82 (
struct V_21 * V_21 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_62 & V_152 ) && F_48 ( V_21 ) > V_153 )
return - V_154 ;
if ( F_19 ( F_83 ( V_21 -> V_155 ) ) )
return - V_30 ;
return 0 ;
}
STATIC int
F_84 (
struct V_21 * V_21 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
int V_130 ;
int error ;
error = F_82 ( V_21 , V_17 ) ;
if ( error )
return error ;
V_130 = F_85 ( V_2 ) ;
if ( V_2 -> V_88 . V_156 > 0 )
F_86 ( NULL , V_2 , 0 , V_157 ) ;
F_6 ( V_2 , V_130 ) ;
return 0 ;
}
STATIC int
F_87 (
struct V_21 * V_21 ,
struct V_17 * V_158 )
{
return - F_88 ( F_16 ( V_21 ) ) ;
}
STATIC int
F_89 (
struct V_17 * V_158 ,
void * V_159 ,
T_12 V_160 )
{
struct V_21 * V_21 = V_158 -> V_132 . V_133 -> V_134 ;
T_6 * V_2 = F_16 ( V_21 ) ;
int error ;
T_2 V_161 ;
V_161 = ( T_2 ) F_90 ( T_1 , 32768 , V_2 -> V_88 . V_89 ) ;
error = F_91 ( V_2 , V_159 , V_161 ,
( T_10 * ) & V_158 -> V_162 , V_160 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_92 (
struct V_17 * V_158 ,
struct V_163 * V_164 )
{
V_164 -> V_165 = & V_166 ;
V_164 -> V_167 |= V_168 ;
F_93 ( V_158 ) ;
return 0 ;
}
STATIC int
F_94 (
struct V_163 * V_164 ,
struct V_169 * V_170 )
{
return F_95 ( V_164 , V_170 , V_171 ) ;
}
