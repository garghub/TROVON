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
int V_18 )
{
struct V_19 * V_19 = V_17 -> V_20 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 ;
int error = 0 ;
int V_27 = 0 ;
F_17 ( V_2 ) ;
if ( F_18 ( V_23 ) )
return - F_19 ( V_28 ) ;
F_20 ( V_2 , V_29 ) ;
F_21 ( V_2 ) ;
if ( V_23 -> V_30 & V_31 ) {
if ( F_22 ( V_2 ) )
F_23 ( V_23 -> V_32 ) ;
else if ( V_23 -> V_33 != V_23 -> V_34 )
F_23 ( V_23 -> V_34 ) ;
}
F_4 ( V_2 , V_35 ) ;
if ( ( ( V_19 -> V_36 & V_37 ) ||
( ( V_19 -> V_36 & V_38 ) && ! V_18 ) ) &&
V_2 -> V_39 ) {
F_6 ( V_2 , V_35 ) ;
V_26 = F_24 ( V_23 , V_40 ) ;
error = F_25 ( V_26 , 0 ,
F_26 ( V_23 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_27 ( V_26 , 0 ) ;
return - error ;
}
F_4 ( V_2 , V_41 ) ;
F_28 ( V_26 , V_2 ) ;
F_29 ( V_26 , V_2 , V_42 ) ;
F_30 ( V_26 ) ;
error = F_31 ( V_26 , 0 , & V_27 ) ;
F_6 ( V_2 , V_41 ) ;
} else {
if ( F_32 ( V_2 ) ) {
error = F_33 ( V_23 ,
V_2 -> V_43 -> V_44 ,
V_45 , & V_27 ) ;
}
F_6 ( V_2 , V_35 ) ;
}
if ( ( V_23 -> V_30 & V_31 ) &&
V_23 -> V_33 == V_23 -> V_34 &&
! F_22 ( V_2 ) &&
! V_27 )
F_23 ( V_23 -> V_34 ) ;
return - error ;
}
STATIC T_3
F_34 (
struct V_46 * V_47 ,
const struct V_48 * V_49 ,
unsigned long V_50 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_47 -> V_51 ;
struct V_19 * V_19 = V_17 -> V_20 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
T_2 V_52 = 0 ;
T_3 V_53 = 0 ;
int V_54 = 0 ;
T_4 V_55 ;
unsigned long V_56 ;
F_35 ( V_57 ) ;
F_36 ( V_47 -> V_58 != V_5 ) ;
if ( F_37 ( V_17 -> V_59 & V_60 ) )
V_54 |= V_61 ;
if ( V_17 -> V_62 & V_63 )
V_54 |= V_64 ;
for ( V_56 = 0 ; V_56 < V_50 ; V_56 ++ ) {
const struct V_48 * V_65 = & V_49 [ V_56 ] ;
V_52 += V_65 -> V_66 ;
if ( F_37 ( ( T_3 ) ( V_52 | V_65 -> V_66 ) < 0 ) )
return F_19 ( - V_67 ) ;
}
if ( F_37 ( V_54 & V_61 ) ) {
T_5 * V_68 =
F_22 ( V_2 ) ?
V_23 -> V_32 : V_23 -> V_34 ;
if ( ( V_47 -> V_58 & V_68 -> V_69 ) ||
( V_52 & V_68 -> V_69 ) ) {
if ( V_47 -> V_58 == V_2 -> V_70 )
return 0 ;
return - F_19 ( V_67 ) ;
}
}
V_55 = F_38 ( V_23 ) - V_47 -> V_58 ;
if ( V_55 <= 0 || V_52 == 0 )
return 0 ;
if ( V_55 < V_52 )
V_52 = V_55 ;
if ( F_18 ( V_23 ) )
return - V_28 ;
if ( F_37 ( V_54 & V_61 ) ) {
F_1 ( V_2 , V_3 ) ;
if ( V_19 -> V_11 -> V_71 ) {
V_53 = - F_39 ( V_2 ,
( V_47 -> V_58 & V_72 ) ,
- 1 , V_73 ) ;
if ( V_53 ) {
F_5 ( V_2 , V_3 ) ;
return V_53 ;
}
}
F_8 ( V_2 , V_3 ) ;
} else
F_1 ( V_2 , V_74 ) ;
F_40 ( V_2 , V_52 , V_47 -> V_58 , V_54 ) ;
V_53 = F_41 ( V_47 , V_49 , V_50 , V_47 -> V_58 ) ;
if ( V_53 > 0 )
F_42 ( V_75 , V_53 ) ;
F_5 ( V_2 , V_74 ) ;
return V_53 ;
}
STATIC T_3
F_43 (
struct V_17 * V_76 ,
T_1 * V_77 ,
struct V_78 * V_79 ,
T_2 V_6 ,
unsigned int V_80 )
{
struct V_1 * V_2 = F_16 ( V_76 -> V_20 -> V_21 ) ;
int V_54 = 0 ;
T_3 V_53 ;
F_35 ( V_57 ) ;
if ( V_76 -> V_62 & V_63 )
V_54 |= V_64 ;
if ( F_18 ( V_2 -> V_24 ) )
return - V_28 ;
F_1 ( V_2 , V_74 ) ;
F_44 ( V_2 , V_6 , * V_77 , V_54 ) ;
V_53 = F_45 ( V_76 , V_77 , V_79 , V_6 , V_80 ) ;
if ( V_53 > 0 )
F_42 ( V_75 , V_53 ) ;
F_5 ( V_2 , V_74 ) ;
return V_53 ;
}
STATIC void
F_46 (
struct V_19 * V_19 ,
T_1 * V_77 ,
T_3 V_81 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
T_4 V_82 = F_47 ( V_19 ) ;
if ( V_81 > 0 )
F_42 ( V_83 , V_81 ) ;
if ( F_37 ( V_81 < 0 && V_81 != - V_84 &&
* V_77 > V_82 ) )
* V_77 = V_82 ;
if ( * V_77 > V_2 -> V_70 ) {
F_1 ( V_2 , V_41 ) ;
if ( * V_77 > V_2 -> V_70 )
V_2 -> V_70 = * V_77 ;
F_5 ( V_2 , V_41 ) ;
}
}
STATIC void
F_48 (
struct V_1 * V_2 )
{
if ( V_2 -> V_85 ) {
F_1 ( V_2 , V_41 ) ;
V_2 -> V_85 = 0 ;
if ( V_2 -> V_86 . V_87 > V_2 -> V_70 )
V_2 -> V_86 . V_87 = V_2 -> V_70 ;
F_5 ( V_2 , V_41 ) ;
}
}
STATIC T_3
F_49 (
struct V_78 * V_79 ,
struct V_17 * V_88 ,
T_1 * V_77 ,
T_2 V_6 ,
unsigned int V_80 )
{
struct V_19 * V_19 = V_88 -> V_20 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
T_4 V_89 ;
int V_54 = 0 ;
T_3 V_53 ;
F_35 ( V_90 ) ;
if ( V_88 -> V_62 & V_63 )
V_54 |= V_64 ;
if ( F_18 ( V_2 -> V_24 ) )
return - V_28 ;
F_4 ( V_2 , V_3 ) ;
V_89 = * V_77 + V_6 ;
F_4 ( V_2 , V_41 ) ;
if ( V_89 > V_2 -> V_70 )
V_2 -> V_85 = V_89 ;
F_6 ( V_2 , V_41 ) ;
F_50 ( V_2 , V_6 , * V_77 , V_54 ) ;
V_53 = F_51 ( V_79 , V_88 , V_77 , V_6 , V_80 ) ;
F_46 ( V_19 , V_77 , V_53 ) ;
F_48 ( V_2 ) ;
F_6 ( V_2 , V_3 ) ;
return V_53 ;
}
STATIC int
F_52 (
T_6 * V_2 ,
T_4 V_12 ,
T_4 V_82 )
{
T_7 V_91 ;
T_8 * V_23 = V_2 -> V_24 ;
int V_92 ;
int V_93 ;
int V_94 ;
int error = 0 ;
T_9 V_95 ;
ASSERT ( F_53 ( V_2 , V_41 ) ) ;
V_93 = F_54 ( V_23 , V_82 ) ;
if ( V_93 == 0 ) {
return 0 ;
}
V_91 = F_55 ( V_23 , V_82 ) ;
V_92 = 1 ;
error = F_56 ( NULL , V_2 , V_91 , 1 , 0 , NULL , 0 , & V_95 ,
& V_92 , NULL ) ;
if ( error ) {
return error ;
}
ASSERT ( V_92 > 0 ) ;
if ( V_95 . V_96 == V_97 ) {
return 0 ;
}
F_6 ( V_2 , V_41 ) ;
V_94 = V_23 -> V_98 . V_99 - V_93 ;
if ( V_82 + V_94 > V_12 )
V_94 = V_12 - V_82 ;
error = F_10 ( V_2 , V_82 , V_94 ) ;
F_4 ( V_2 , V_41 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_57 (
T_6 * V_2 ,
T_10 V_12 ,
T_4 V_82 )
{
T_8 * V_23 = V_2 -> V_24 ;
T_7 V_100 ;
T_7 V_101 ;
T_7 V_102 ;
T_7 V_91 ;
T_7 V_103 ;
T_4 V_94 ;
int V_92 ;
int error = 0 ;
T_9 V_95 ;
ASSERT ( F_53 ( V_2 , V_41 | V_3 ) ) ;
ASSERT ( V_12 > V_82 ) ;
error = F_52 ( V_2 , V_12 , V_82 ) ;
if ( error ) {
ASSERT ( F_53 ( V_2 , V_41 | V_3 ) ) ;
return error ;
}
V_91 = V_82 ? F_55 ( V_23 , V_82 - 1 ) : ( T_7 ) - 1 ;
V_100 = F_58 ( V_23 , ( V_104 ) V_82 ) ;
V_101 = F_55 ( V_23 , V_12 - 1 ) ;
ASSERT ( ( V_105 ) V_91 < ( V_105 ) V_100 ) ;
if ( V_91 == V_101 ) {
return 0 ;
}
ASSERT ( V_100 <= V_101 ) ;
while ( V_100 <= V_101 ) {
V_92 = 1 ;
V_102 = V_101 - V_100 + 1 ;
error = F_56 ( NULL , V_2 , V_100 , V_102 ,
0 , NULL , 0 , & V_95 , & V_92 , NULL ) ;
if ( error ) {
ASSERT ( F_53 ( V_2 , V_41 | V_3 ) ) ;
return error ;
}
ASSERT ( V_92 > 0 ) ;
if ( V_95 . V_106 == V_107 ||
V_95 . V_96 == V_97 ) {
V_100 = V_95 . V_108 + V_95 . V_109 ;
ASSERT ( V_100 <= ( V_101 + 1 ) ) ;
continue;
}
F_6 ( V_2 , V_41 ) ;
V_103 = F_59 ( V_23 , V_100 ) ;
V_94 = F_59 ( V_23 , V_95 . V_109 ) ;
if ( ( V_103 + V_94 ) > V_12 )
V_94 = V_12 - V_103 ;
error = F_10 ( V_2 , V_103 , V_94 ) ;
if ( error ) {
goto V_110;
}
V_100 = V_95 . V_108 + V_95 . V_109 ;
ASSERT ( V_100 <= ( V_101 + 1 ) ) ;
F_4 ( V_2 , V_41 ) ;
}
return 0 ;
V_110:
F_4 ( V_2 , V_41 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
STATIC T_3
F_60 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
int * V_111 )
{
struct V_19 * V_19 = V_17 -> V_20 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
T_4 V_89 ;
int error = 0 ;
error = F_61 ( V_17 , V_5 , V_6 , F_62 ( V_19 -> V_112 ) ) ;
if ( error ) {
F_5 ( V_2 , V_41 | * V_111 ) ;
* V_111 = 0 ;
return error ;
}
V_89 = * V_5 + * V_6 ;
if ( V_89 > V_2 -> V_70 )
V_2 -> V_85 = V_89 ;
if ( F_63 ( ! ( V_17 -> V_62 & V_63 ) ) )
F_64 ( V_17 ) ;
if ( * V_5 > V_2 -> V_70 )
error = - F_57 ( V_2 , * V_5 , V_2 -> V_70 ) ;
F_5 ( V_2 , V_41 ) ;
if ( error )
return error ;
return F_65 ( V_17 ) ;
}
STATIC T_3
F_66 (
struct V_46 * V_47 ,
const struct V_48 * V_49 ,
unsigned long V_50 ,
T_1 V_5 ,
T_2 V_113 ,
int * V_111 )
{
struct V_17 * V_17 = V_47 -> V_51 ;
struct V_8 * V_9 = V_17 -> V_20 ;
struct V_19 * V_19 = V_9 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
T_3 V_53 = 0 ;
T_2 V_6 = V_113 ;
int V_114 = 0 ;
struct V_115 * V_68 = F_22 ( V_2 ) ?
V_23 -> V_32 : V_23 -> V_34 ;
* V_111 = 0 ;
if ( ( V_5 & V_68 -> V_69 ) || ( V_6 & V_68 -> V_69 ) )
return - F_19 ( V_67 ) ;
if ( ( V_5 & V_23 -> V_116 ) || ( ( V_5 + V_6 ) & V_23 -> V_116 ) )
V_114 = 1 ;
if ( V_114 || V_9 -> V_71 || V_5 > V_2 -> V_70 )
* V_111 = V_3 ;
else
* V_111 = V_74 ;
F_1 ( V_2 , V_41 | * V_111 ) ;
V_53 = F_60 ( V_17 , & V_5 , & V_6 , V_111 ) ;
if ( V_53 )
return V_53 ;
if ( V_9 -> V_71 ) {
F_14 ( * V_111 != V_3 ) ;
V_53 = - F_39 ( V_2 , ( V_5 & V_72 ) , - 1 ,
V_73 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_114 )
F_21 ( V_2 ) ;
else if ( * V_111 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
* V_111 = V_74 ;
}
F_67 ( V_2 , V_6 , V_47 -> V_58 , 0 ) ;
V_53 = F_68 ( V_47 , V_49 ,
& V_50 , V_5 , & V_47 -> V_58 , V_6 , V_113 ) ;
ASSERT ( V_53 < 0 || V_53 == V_6 ) ;
return V_53 ;
}
STATIC T_3
F_69 (
struct V_46 * V_47 ,
const struct V_48 * V_49 ,
unsigned long V_50 ,
T_1 V_5 ,
T_2 V_113 ,
int * V_111 )
{
struct V_17 * V_17 = V_47 -> V_51 ;
struct V_8 * V_9 = V_17 -> V_20 ;
struct V_19 * V_19 = V_9 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
T_3 V_53 ;
int V_117 = 0 ;
T_2 V_6 = V_113 ;
* V_111 = V_3 ;
F_1 ( V_2 , V_41 | * V_111 ) ;
V_53 = F_60 ( V_17 , & V_5 , & V_6 , V_111 ) ;
if ( V_53 )
return V_53 ;
V_118 -> V_119 = V_9 -> V_119 ;
V_120:
F_70 ( V_2 , V_6 , V_47 -> V_58 , 0 ) ;
V_53 = F_71 ( V_47 , V_49 , V_50 ,
V_5 , & V_47 -> V_58 , V_6 , V_53 ) ;
if ( V_53 == - V_121 && ! V_117 ) {
V_53 = - F_72 ( V_2 , 0 , - 1 , 0 , V_122 ) ;
if ( V_53 )
return V_53 ;
V_117 = 1 ;
goto V_120;
}
V_118 -> V_119 = NULL ;
return V_53 ;
}
STATIC T_3
F_73 (
struct V_46 * V_47 ,
const struct V_48 * V_49 ,
unsigned long V_50 ,
T_1 V_5 )
{
struct V_17 * V_17 = V_47 -> V_51 ;
struct V_8 * V_9 = V_17 -> V_20 ;
struct V_19 * V_19 = V_9 -> V_21 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
T_3 V_53 ;
int V_111 ;
T_2 V_113 = 0 ;
F_35 ( V_90 ) ;
F_36 ( V_47 -> V_58 != V_5 ) ;
V_53 = F_74 ( V_49 , & V_50 , & V_113 , V_123 ) ;
if ( V_53 )
return V_53 ;
if ( V_113 == 0 )
return 0 ;
F_75 ( V_2 -> V_24 , V_124 ) ;
if ( F_18 ( V_2 -> V_24 ) )
return - V_28 ;
if ( F_37 ( V_17 -> V_59 & V_60 ) )
V_53 = F_66 ( V_47 , V_49 , V_50 , V_5 ,
V_113 , & V_111 ) ;
else
V_53 = F_69 ( V_47 , V_49 , V_50 , V_5 ,
V_113 , & V_111 ) ;
F_46 ( V_19 , & V_47 -> V_58 , V_53 ) ;
if ( V_53 <= 0 )
goto V_125;
if ( ( V_17 -> V_59 & V_126 ) || F_76 ( V_19 ) ) {
T_1 V_127 = V_5 + V_53 - 1 ;
int error , V_128 ;
F_5 ( V_2 , V_111 ) ;
error = F_77 ( V_9 , V_5 , V_127 ) ;
F_1 ( V_2 , V_111 ) ;
V_128 = - F_15 ( V_17 ,
( V_17 -> V_59 & V_129 ) ? 0 : 1 ) ;
if ( error )
V_53 = error ;
else if ( V_128 )
V_53 = V_128 ;
}
V_125:
F_48 ( V_2 ) ;
F_5 ( V_2 , V_111 ) ;
return V_53 ;
}
STATIC long
F_78 (
struct V_17 * V_17 ,
int V_130 ,
T_1 V_12 ,
T_1 V_131 )
{
struct V_19 * V_19 = V_17 -> V_132 . V_133 -> V_134 ;
long error ;
T_1 V_89 = 0 ;
T_11 V_135 ;
T_6 * V_2 = F_16 ( V_19 ) ;
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
V_12 + V_131 > F_47 ( V_19 ) ) {
V_89 = V_12 + V_131 ;
error = F_79 ( V_19 , V_89 ) ;
if ( error )
goto V_125;
}
if ( V_17 -> V_59 & V_126 )
V_138 |= V_147 ;
error = - F_80 ( V_2 , V_136 , & V_135 , 0 , V_138 ) ;
if ( error )
goto V_125;
if ( V_89 ) {
struct V_148 V_148 ;
V_148 . V_149 = V_150 ;
V_148 . V_151 = V_89 ;
error = - F_81 ( V_2 , & V_148 , V_139 ) ;
}
V_125:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_82 (
struct V_19 * V_19 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_59 & V_152 ) && F_47 ( V_19 ) > V_153 )
return - V_154 ;
if ( F_18 ( F_83 ( V_19 -> V_155 ) ) )
return - V_28 ;
return 0 ;
}
STATIC int
F_84 (
struct V_19 * V_19 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
int V_130 ;
int error ;
error = F_82 ( V_19 , V_17 ) ;
if ( error )
return error ;
V_130 = F_85 ( V_2 ) ;
if ( V_2 -> V_86 . V_156 > 0 )
F_86 ( NULL , V_2 , 0 , V_157 ) ;
F_6 ( V_2 , V_130 ) ;
return 0 ;
}
STATIC int
F_87 (
struct V_19 * V_19 ,
struct V_17 * V_158 )
{
return - F_88 ( F_16 ( V_19 ) ) ;
}
STATIC int
F_89 (
struct V_17 * V_158 ,
void * V_159 ,
T_12 V_160 )
{
struct V_19 * V_19 = V_158 -> V_132 . V_133 -> V_134 ;
T_6 * V_2 = F_16 ( V_19 ) ;
int error ;
T_2 V_161 ;
V_161 = ( T_2 ) F_90 ( T_1 , 32768 , V_2 -> V_86 . V_87 ) ;
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
