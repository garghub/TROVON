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
if ( V_50 -> V_61 == V_2 -> V_73 )
return 0 ;
return - F_24 ( V_70 ) ;
}
}
V_58 = F_39 ( V_24 ) - V_50 -> V_61 ;
if ( V_58 <= 0 || V_55 == 0 )
return 0 ;
if ( V_58 < V_55 )
V_55 = V_58 ;
if ( F_23 ( V_24 ) )
return - V_35 ;
F_1 ( V_2 , V_74 ) ;
if ( ( V_57 & V_64 ) && V_31 -> V_11 -> V_75 ) {
F_5 ( V_2 , V_74 ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_31 -> V_11 -> V_75 ) {
V_56 = - F_40 ( V_2 ,
( V_50 -> V_61 & V_76 ) ,
- 1 , V_77 ) ;
if ( V_56 ) {
F_5 ( V_2 , V_3 ) ;
return V_56 ;
}
}
F_8 ( V_2 , V_3 ) ;
}
F_41 ( V_2 , V_55 , V_50 -> V_61 , V_57 ) ;
V_56 = F_42 ( V_50 , V_52 , V_53 , V_50 -> V_61 ) ;
if ( V_56 > 0 )
F_43 ( V_78 , V_56 ) ;
F_5 ( V_2 , V_74 ) ;
return V_56 ;
}
STATIC T_4
F_44 (
struct V_17 * V_79 ,
T_1 * V_80 ,
struct V_81 * V_82 ,
T_2 V_6 ,
unsigned int V_83 )
{
struct V_1 * V_2 = F_16 ( V_79 -> V_21 -> V_22 ) ;
int V_57 = 0 ;
T_4 V_56 ;
F_36 ( V_60 ) ;
if ( V_79 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
F_1 ( V_2 , V_74 ) ;
F_45 ( V_2 , V_6 , * V_80 , V_57 ) ;
V_56 = F_46 ( V_79 , V_80 , V_82 , V_6 , V_83 ) ;
if ( V_56 > 0 )
F_43 ( V_78 , V_56 ) ;
F_5 ( V_2 , V_74 ) ;
return V_56 ;
}
STATIC void
F_47 (
struct V_31 * V_31 ,
T_1 * V_80 ,
T_4 V_84 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_5 V_85 = F_48 ( V_31 ) ;
if ( V_84 > 0 )
F_43 ( V_86 , V_84 ) ;
if ( F_38 ( V_84 < 0 && V_84 != - V_87 &&
* V_80 > V_85 ) )
* V_80 = V_85 ;
if ( * V_80 > V_2 -> V_73 ) {
F_1 ( V_2 , V_47 ) ;
if ( * V_80 > V_2 -> V_73 )
V_2 -> V_73 = * V_80 ;
F_5 ( V_2 , V_47 ) ;
}
}
STATIC void
F_49 (
struct V_1 * V_2 ,
T_5 V_88 )
{
if ( V_88 == V_2 -> V_89 ) {
F_1 ( V_2 , V_47 ) ;
if ( V_88 == V_2 -> V_89 )
V_2 -> V_89 = 0 ;
if ( V_2 -> V_90 . V_91 > V_2 -> V_73 )
V_2 -> V_90 . V_91 = V_2 -> V_73 ;
F_5 ( V_2 , V_47 ) ;
}
}
STATIC T_4
F_50 (
struct V_81 * V_82 ,
struct V_17 * V_92 ,
T_1 * V_80 ,
T_2 V_6 ,
unsigned int V_83 )
{
struct V_31 * V_31 = V_92 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_5 V_88 ;
int V_57 = 0 ;
T_4 V_56 ;
F_36 ( V_93 ) ;
if ( V_92 -> V_65 & V_66 )
V_57 |= V_67 ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
F_4 ( V_2 , V_3 ) ;
V_88 = * V_80 + V_6 ;
F_4 ( V_2 , V_47 ) ;
if ( V_88 > V_2 -> V_73 )
V_2 -> V_89 = V_88 ;
F_6 ( V_2 , V_47 ) ;
F_51 ( V_2 , V_6 , * V_80 , V_57 ) ;
V_56 = F_52 ( V_82 , V_92 , V_80 , V_6 , V_83 ) ;
F_47 ( V_31 , V_80 , V_56 ) ;
F_49 ( V_2 , V_88 ) ;
F_6 ( V_2 , V_3 ) ;
return V_56 ;
}
STATIC int
F_53 (
T_7 * V_2 ,
T_5 V_12 ,
T_5 V_85 )
{
T_8 V_94 ;
T_9 * V_24 = V_2 -> V_25 ;
int V_95 ;
int V_96 ;
int V_97 ;
int error = 0 ;
T_10 V_98 ;
ASSERT ( F_54 ( V_2 , V_47 ) ) ;
V_96 = F_55 ( V_24 , V_85 ) ;
if ( V_96 == 0 ) {
return 0 ;
}
V_94 = F_56 ( V_24 , V_85 ) ;
V_95 = 1 ;
error = F_57 ( V_2 , V_94 , 1 , & V_98 , & V_95 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_95 > 0 ) ;
if ( V_98 . V_99 == V_100 ) {
return 0 ;
}
F_6 ( V_2 , V_47 ) ;
V_97 = V_24 -> V_101 . V_102 - V_96 ;
if ( V_85 + V_97 > V_12 )
V_97 = V_12 - V_85 ;
error = F_10 ( V_2 , V_85 , V_97 ) ;
F_4 ( V_2 , V_47 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_58 (
T_7 * V_2 ,
T_11 V_12 ,
T_5 V_85 )
{
T_9 * V_24 = V_2 -> V_25 ;
T_8 V_103 ;
T_8 V_104 ;
T_8 V_105 ;
T_8 V_94 ;
T_8 V_106 ;
T_5 V_97 ;
int V_95 ;
int error = 0 ;
T_10 V_98 ;
ASSERT ( F_54 ( V_2 , V_47 | V_3 ) ) ;
ASSERT ( V_12 > V_85 ) ;
error = F_53 ( V_2 , V_12 , V_85 ) ;
if ( error ) {
ASSERT ( F_54 ( V_2 , V_47 | V_3 ) ) ;
return error ;
}
V_94 = V_85 ? F_56 ( V_24 , V_85 - 1 ) : ( T_8 ) - 1 ;
V_103 = F_59 ( V_24 , ( V_107 ) V_85 ) ;
V_104 = F_56 ( V_24 , V_12 - 1 ) ;
ASSERT ( ( V_108 ) V_94 < ( V_108 ) V_103 ) ;
if ( V_94 == V_104 ) {
return 0 ;
}
ASSERT ( V_103 <= V_104 ) ;
while ( V_103 <= V_104 ) {
V_95 = 1 ;
V_105 = V_104 - V_103 + 1 ;
error = F_57 ( V_2 , V_103 , V_105 ,
& V_98 , & V_95 , 0 ) ;
if ( error ) {
ASSERT ( F_54 ( V_2 , V_47 | V_3 ) ) ;
return error ;
}
ASSERT ( V_95 > 0 ) ;
if ( V_98 . V_109 == V_110 ||
V_98 . V_99 == V_100 ) {
V_103 = V_98 . V_111 + V_98 . V_112 ;
ASSERT ( V_103 <= ( V_104 + 1 ) ) ;
continue;
}
F_6 ( V_2 , V_47 ) ;
V_106 = F_60 ( V_24 , V_103 ) ;
V_97 = F_60 ( V_24 , V_98 . V_112 ) ;
if ( ( V_106 + V_97 ) > V_12 )
V_97 = V_12 - V_106 ;
error = F_10 ( V_2 , V_106 , V_97 ) ;
if ( error ) {
goto V_113;
}
V_103 = V_98 . V_111 + V_98 . V_112 ;
ASSERT ( V_103 <= ( V_104 + 1 ) ) ;
F_4 ( V_2 , V_47 ) ;
}
return 0 ;
V_113:
F_4 ( V_2 , V_47 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
STATIC T_4
F_61 (
struct V_17 * V_17 ,
T_1 * V_5 ,
T_2 * V_6 ,
T_5 * V_114 ,
int * V_115 )
{
struct V_31 * V_31 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_5 V_88 ;
int error = 0 ;
F_1 ( V_2 , V_47 ) ;
* V_114 = 0 ;
V_116:
error = F_62 ( V_17 , V_5 , V_6 , F_63 ( V_31 -> V_117 ) ) ;
if ( error ) {
F_5 ( V_2 , V_47 | * V_115 ) ;
* V_115 = 0 ;
return error ;
}
if ( F_64 ( ! ( V_17 -> V_65 & V_66 ) ) )
F_65 ( V_17 ) ;
if ( ( V_2 -> V_89 && * V_5 > V_2 -> V_89 ) ||
( ! V_2 -> V_89 && * V_5 > V_2 -> V_73 ) ) {
if ( * V_115 == V_74 ) {
F_5 ( V_2 , V_47 | * V_115 ) ;
* V_115 = V_3 ;
F_1 ( V_2 , V_47 | * V_115 ) ;
goto V_116;
}
error = - F_58 ( V_2 , * V_5 , V_2 -> V_73 ) ;
}
V_88 = * V_5 + * V_6 ;
if ( V_88 > V_2 -> V_73 ) {
if ( V_88 > V_2 -> V_89 )
V_2 -> V_89 = V_88 ;
* V_114 = V_88 ;
}
F_5 ( V_2 , V_47 ) ;
if ( error )
return error ;
return F_66 ( V_17 ) ;
}
STATIC T_4
F_67 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_118 ,
T_5 * V_88 ,
int * V_115 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_4 V_56 = 0 ;
T_2 V_6 = V_118 ;
int V_119 = 0 ;
struct V_120 * V_71 = F_26 ( V_2 ) ?
V_24 -> V_39 : V_24 -> V_41 ;
* V_115 = 0 ;
if ( ( V_5 & V_71 -> V_72 ) || ( V_6 & V_71 -> V_72 ) )
return - F_24 ( V_70 ) ;
if ( ( V_5 & V_24 -> V_121 ) || ( ( V_5 + V_6 ) & V_24 -> V_121 ) )
V_119 = 1 ;
if ( V_119 || V_9 -> V_75 )
* V_115 = V_3 ;
else
* V_115 = V_74 ;
F_1 ( V_2 , * V_115 ) ;
if ( V_9 -> V_75 && * V_115 == V_74 ) {
F_5 ( V_2 , * V_115 ) ;
* V_115 = V_3 ;
F_1 ( V_2 , * V_115 ) ;
}
V_56 = F_61 ( V_17 , & V_5 , & V_6 , V_88 , V_115 ) ;
if ( V_56 )
return V_56 ;
if ( V_9 -> V_75 ) {
V_56 = - F_40 ( V_2 , ( V_5 & V_76 ) , - 1 ,
V_77 ) ;
if ( V_56 )
return V_56 ;
}
if ( V_119 )
F_68 ( V_31 ) ;
else if ( * V_115 == V_3 ) {
F_8 ( V_2 , V_3 ) ;
* V_115 = V_74 ;
}
F_69 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_70 ( V_50 , V_52 ,
& V_53 , V_5 , & V_50 -> V_61 , V_6 , V_118 ) ;
ASSERT ( V_56 < 0 || V_56 == V_6 ) ;
return V_56 ;
}
STATIC T_4
F_71 (
struct V_49 * V_50 ,
const struct V_51 * V_52 ,
unsigned long V_53 ,
T_1 V_5 ,
T_2 V_118 ,
T_5 * V_88 ,
int * V_115 )
{
struct V_17 * V_17 = V_50 -> V_54 ;
struct V_8 * V_9 = V_17 -> V_21 ;
struct V_31 * V_31 = V_9 -> V_22 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_4 V_56 ;
int V_122 = 0 ;
T_2 V_6 = V_118 ;
* V_115 = V_3 ;
F_1 ( V_2 , * V_115 ) ;
V_56 = F_61 ( V_17 , & V_5 , & V_6 , V_88 , V_115 ) ;
if ( V_56 )
return V_56 ;
V_123 -> V_124 = V_9 -> V_124 ;
V_125:
F_72 ( V_2 , V_6 , V_50 -> V_61 , 0 ) ;
V_56 = F_73 ( V_50 , V_52 , V_53 ,
V_5 , & V_50 -> V_61 , V_6 , V_56 ) ;
if ( V_56 == - V_126 && ! V_122 ) {
V_56 = - F_74 ( V_2 , 0 , - 1 , 0 , V_127 ) ;
if ( V_56 )
return V_56 ;
V_122 = 1 ;
goto V_125;
}
V_123 -> V_124 = NULL ;
return V_56 ;
}
STATIC T_4
F_75 (
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
int V_115 ;
T_2 V_118 = 0 ;
T_5 V_88 = 0 ;
F_36 ( V_93 ) ;
F_37 ( V_50 -> V_61 != V_5 ) ;
V_56 = F_76 ( V_52 , & V_53 , & V_118 , V_128 ) ;
if ( V_56 )
return V_56 ;
if ( V_118 == 0 )
return 0 ;
F_77 ( V_2 -> V_25 , V_129 ) ;
if ( F_23 ( V_2 -> V_25 ) )
return - V_35 ;
if ( F_38 ( V_17 -> V_62 & V_63 ) )
V_56 = F_67 ( V_50 , V_52 , V_53 , V_5 ,
V_118 , & V_88 , & V_115 ) ;
else
V_56 = F_71 ( V_50 , V_52 , V_53 , V_5 ,
V_118 , & V_88 , & V_115 ) ;
F_47 ( V_31 , & V_50 -> V_61 , V_56 ) ;
if ( V_56 <= 0 )
goto V_130;
if ( ( V_17 -> V_62 & V_131 ) || F_78 ( V_31 ) ) {
T_1 V_19 = V_5 + V_56 - 1 ;
int error ;
F_5 ( V_2 , V_115 ) ;
error = F_20 ( V_17 , V_5 , V_19 ,
( V_17 -> V_62 & V_132 ) ? 0 : 1 ) ;
F_1 ( V_2 , V_115 ) ;
if ( error )
V_56 = error ;
}
V_130:
F_49 ( V_2 , V_88 ) ;
F_5 ( V_2 , V_115 ) ;
return V_56 ;
}
STATIC long
F_79 (
struct V_17 * V_17 ,
int V_133 ,
T_1 V_12 ,
T_1 V_134 )
{
struct V_31 * V_31 = V_17 -> V_135 . V_136 -> V_137 ;
long error ;
T_1 V_88 = 0 ;
T_12 V_138 ;
T_7 * V_2 = F_16 ( V_31 ) ;
int V_139 = V_140 ;
int V_141 = V_142 ;
if ( V_133 & ~ ( V_143 | V_144 ) )
return - V_145 ;
V_138 . V_146 = 0 ;
V_138 . V_147 = V_12 ;
V_138 . V_148 = V_134 ;
F_4 ( V_2 , V_3 ) ;
if ( V_133 & V_144 )
V_139 = V_149 ;
if ( ! ( V_133 & V_143 ) &&
V_12 + V_134 > F_48 ( V_31 ) ) {
V_88 = V_12 + V_134 ;
error = F_80 ( V_31 , V_88 ) ;
if ( error )
goto V_130;
}
if ( V_17 -> V_62 & V_131 )
V_141 |= V_150 ;
error = - F_81 ( V_2 , V_139 , & V_138 , 0 , V_141 ) ;
if ( error )
goto V_130;
if ( V_88 ) {
struct V_151 V_151 ;
V_151 . V_152 = V_153 ;
V_151 . V_154 = V_88 ;
error = - F_82 ( V_2 , & V_151 , V_142 ) ;
}
V_130:
F_6 ( V_2 , V_3 ) ;
return error ;
}
STATIC int
F_83 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
if ( ! ( V_17 -> V_62 & V_155 ) && F_48 ( V_31 ) > V_156 )
return - V_157 ;
if ( F_23 ( F_84 ( V_31 -> V_158 ) ) )
return - V_35 ;
return 0 ;
}
STATIC int
F_85 (
struct V_31 * V_31 ,
struct V_17 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_133 ;
int error ;
error = F_83 ( V_31 , V_17 ) ;
if ( error )
return error ;
V_133 = F_86 ( V_2 ) ;
if ( V_2 -> V_90 . V_159 > 0 )
F_87 ( NULL , V_2 , 0 , V_160 ) ;
F_6 ( V_2 , V_133 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_31 * V_31 ,
struct V_17 * V_161 )
{
return - F_89 ( F_16 ( V_31 ) ) ;
}
STATIC int
F_90 (
struct V_17 * V_161 ,
void * V_162 ,
T_13 V_163 )
{
struct V_31 * V_31 = V_161 -> V_135 . V_136 -> V_137 ;
T_7 * V_2 = F_16 ( V_31 ) ;
int error ;
T_2 V_164 ;
V_164 = ( T_2 ) F_91 ( T_1 , 32768 , V_2 -> V_90 . V_91 ) ;
error = F_92 ( V_2 , V_162 , V_164 ,
( T_11 * ) & V_161 -> V_165 , V_163 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC int
F_93 (
struct V_17 * V_161 ,
struct V_166 * V_167 )
{
V_167 -> V_168 = & V_169 ;
V_167 -> V_170 |= V_171 ;
F_94 ( V_161 ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_166 * V_167 ,
struct V_172 * V_173 )
{
return F_96 ( V_167 , V_173 , V_174 ) ;
}
