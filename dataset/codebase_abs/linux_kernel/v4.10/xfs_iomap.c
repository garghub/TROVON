void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_5 -> V_9 == V_10 ) {
V_3 -> V_11 = V_12 ;
V_3 -> type = V_13 ;
} else if ( V_5 -> V_9 == V_14 ) {
V_3 -> V_11 = V_12 ;
V_3 -> type = V_15 ;
} else {
V_3 -> V_11 = F_2 ( V_2 , V_5 -> V_9 ) ;
if ( V_5 -> V_16 == V_17 )
V_3 -> type = V_18 ;
else
V_3 -> type = V_19 ;
}
V_3 -> V_20 = F_3 ( V_7 , V_5 -> V_21 ) ;
V_3 -> V_22 = F_3 ( V_7 , V_5 -> V_23 ) ;
V_3 -> V_24 = F_4 ( F_5 ( V_2 ) ) ;
}
T_1
F_6 (
struct V_1 * V_2 ,
T_1 V_25 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_26 = 0 ;
if ( ! F_7 ( V_2 ) ) {
if ( V_7 -> V_27 && ( V_7 -> V_28 & V_29 ) )
V_26 = V_7 -> V_27 ;
else if ( V_7 -> V_30 )
V_26 = V_7 -> V_30 ;
if ( V_26 && F_8 ( V_2 ) < F_3 ( V_7 , V_26 ) )
V_26 = 0 ;
}
if ( V_25 ) {
if ( V_26 )
V_26 = F_9 ( V_26 , V_25 ) ;
else
V_26 = V_25 ;
}
return V_26 ;
}
STATIC int
F_10 (
struct V_1 * V_2 ,
T_1 V_25 ,
T_2 * V_31 )
{
T_1 V_26 = F_6 ( V_2 , V_25 ) ;
if ( V_26 ) {
T_2 V_32 = F_9 ( * V_31 , V_26 ) ;
int V_33 , error ;
error = F_11 ( V_2 , V_32 , V_34 , & V_33 ) ;
if ( error )
return error ;
if ( V_33 )
* V_31 = V_32 ;
}
return 0 ;
}
STATIC int
F_12 (
T_3 * V_2 ,
T_4 * V_5 )
{
F_13 ( V_2 -> V_8 , V_35 ,
L_1
L_2
L_3 ,
( unsigned long long ) V_2 -> V_36 ,
( unsigned long long ) V_5 -> V_9 ,
( unsigned long long ) V_5 -> V_21 ,
( unsigned long long ) V_5 -> V_23 ,
V_5 -> V_16 ) ;
return - V_37 ;
}
int
F_14 (
T_3 * V_2 ,
T_5 V_20 ,
T_6 V_38 ,
T_4 * V_5 ,
int V_39 )
{
T_7 * V_7 = V_2 -> V_8 ;
T_2 V_40 ;
T_2 V_31 ;
T_8 V_41 , V_42 ;
T_9 V_43 ;
T_1 V_44 , V_45 ;
int V_46 ;
int V_47 ;
int V_48 ;
T_10 * V_49 ;
struct V_50 V_51 ;
T_11 V_52 , V_53 , V_54 ;
int error ;
int V_55 ;
int V_56 = V_57 ;
T_11 V_58 = 0 ;
V_48 = F_7 ( V_2 ) ;
V_44 = F_15 ( V_2 ) ;
V_55 = V_59 ;
ASSERT ( F_16 ( V_2 , V_55 ) ) ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_31 = F_18 ( V_7 , ( ( V_60 ) ( V_20 + V_38 ) ) ) ;
if ( ( V_20 + V_38 ) > F_8 ( V_2 ) ) {
ASSERT ( F_19 ( V_2 , V_34 ) -> V_61 &
V_62 ) ;
error = F_10 ( V_2 , V_44 , & V_31 ) ;
if ( error )
goto V_63;
} else {
if ( V_39 && ( V_5 -> V_9 == V_10 ) )
V_31 = F_20 ( V_31 , ( T_2 )
V_5 -> V_23 +
V_5 -> V_21 ) ;
}
V_41 = V_31 - V_40 ;
ASSERT ( V_41 > 0 ) ;
V_42 = V_41 ;
if ( F_21 ( V_44 ) ) {
if ( ( V_45 = F_22 ( V_40 , V_44 ) ) )
V_42 += V_45 ;
if ( ( V_45 = F_22 ( V_42 , V_44 ) ) )
V_42 += V_44 - V_45 ;
}
if ( F_21 ( V_48 ) ) {
V_54 = V_52 = V_42 ;
V_54 /= V_7 -> V_64 . V_65 ;
V_53 = F_23 ( V_7 , 0 ) ;
V_47 = V_66 ;
} else {
V_54 = 0 ;
V_53 = V_52 = F_23 ( V_7 , V_42 ) ;
V_47 = V_67 ;
}
F_24 ( V_2 , V_55 ) ;
error = F_25 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( F_26 ( F_5 ( V_2 ) ) ) {
V_56 = V_68 | V_69 ;
if ( F_27 ( V_5 ) ) {
V_58 |= V_70 ;
V_53 = F_23 ( V_7 , 0 ) << 1 ;
}
}
error = F_28 ( V_7 , & F_29 ( V_7 ) -> V_71 , V_53 , V_54 ,
V_58 , & V_49 ) ;
if ( error )
return error ;
V_55 = V_72 ;
F_30 ( V_2 , V_55 ) ;
error = F_31 ( V_49 , V_2 , V_52 , 0 , V_47 ) ;
if ( error )
goto V_73;
F_32 ( V_49 , V_2 , 0 ) ;
F_33 ( & V_51 , & V_43 ) ;
V_46 = 1 ;
error = F_34 ( V_49 , V_2 , V_40 , V_41 ,
V_56 , & V_43 , V_53 , V_5 ,
& V_46 , & V_51 ) ;
if ( error )
goto V_74;
error = F_35 ( & V_49 , & V_51 , NULL ) ;
if ( error )
goto V_74;
error = F_36 ( V_49 ) ;
if ( error )
goto V_63;
if ( V_46 == 0 ) {
error = - V_75 ;
goto V_63;
}
if ( ! ( V_5 -> V_9 || F_7 ( V_2 ) ) )
error = F_12 ( V_2 , V_5 ) ;
V_63:
F_24 ( V_2 , V_55 ) ;
return error ;
V_74:
F_37 ( & V_51 ) ;
F_38 ( V_49 , V_2 , ( long ) V_52 , 0 , V_47 ) ;
V_73:
F_39 ( V_49 ) ;
goto V_63;
}
STATIC bool
F_40 (
struct V_1 * V_2 ,
int type ,
T_9 V_76 )
{
struct V_77 * V_78 = F_41 ( V_2 , type ) ;
if ( ! V_78 || ! F_42 ( V_2 -> V_8 , type ) )
return false ;
if ( ! V_78 -> V_79 )
return false ;
if ( V_78 -> V_80 + V_76 < V_78 -> V_81 )
return false ;
return true ;
}
STATIC void
F_43 (
struct V_1 * V_2 ,
int type ,
T_9 * V_52 ,
int * V_82 ,
T_12 * V_83 )
{
T_12 V_84 ;
int V_85 = 0 ;
struct V_77 * V_78 = F_41 ( V_2 , type ) ;
if ( ! V_78 || V_78 -> V_80 >= V_78 -> V_79 ) {
* V_52 = 0 ;
* V_83 = 0 ;
return;
}
V_84 = V_78 -> V_79 - V_78 -> V_80 ;
if ( V_84 < V_78 -> V_86 [ V_87 ] ) {
V_85 = 2 ;
if ( V_84 < V_78 -> V_86 [ V_88 ] )
V_85 += 2 ;
if ( V_84 < V_78 -> V_86 [ V_89 ] )
V_85 += 2 ;
}
if ( V_84 < * V_83 )
* V_83 = V_84 ;
if ( ( V_84 >> V_85 ) < ( * V_52 >> * V_82 ) ) {
* V_52 = V_84 ;
* V_82 = V_85 ;
}
}
STATIC T_9
F_44 (
struct V_1 * V_2 ,
T_13 V_20 ,
T_13 V_38 ,
T_14 V_90 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_92 = F_19 ( V_2 , V_34 ) ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
struct V_4 V_93 ;
int V_85 = 0 ;
T_12 V_84 ;
T_9 V_52 ;
int V_82 = 0 ;
T_9 V_76 = 0 ;
if ( V_20 + V_38 <= F_8 ( V_2 ) )
return 0 ;
if ( ! ( V_7 -> V_28 & V_94 ) &&
( F_8 ( V_2 ) < F_3 ( V_7 , V_7 -> V_95 ) ) )
return 0 ;
if ( ( V_7 -> V_28 & V_94 ) ||
F_8 ( V_2 ) < F_3 ( V_7 , V_7 -> V_30 ) ||
! F_45 ( V_92 , V_90 - 1 , & V_93 ) ||
V_93 . V_21 + V_93 . V_23 < V_40 )
return V_7 -> V_95 ;
if ( V_93 . V_23 <= ( V_96 >> 1 ) )
V_76 = V_93 . V_23 << 1 ;
else
V_76 = F_18 ( V_7 , V_20 ) ;
if ( ! V_76 )
goto V_97;
V_52 = V_76 ;
V_76 = F_46 ( F_47 ( V_96 ) ,
V_76 ) ;
V_84 = F_48 ( & V_7 -> V_98 ) ;
if ( V_84 < V_7 -> V_99 [ V_100 ] ) {
V_85 = 2 ;
if ( V_84 < V_7 -> V_99 [ V_101 ] )
V_85 ++ ;
if ( V_84 < V_7 -> V_99 [ V_102 ] )
V_85 ++ ;
if ( V_84 < V_7 -> V_99 [ V_103 ] )
V_85 ++ ;
if ( V_84 < V_7 -> V_99 [ V_104 ] )
V_85 ++ ;
}
if ( F_40 ( V_2 , V_105 , V_76 ) )
F_43 ( V_2 , V_105 , & V_52 , & V_82 ,
& V_84 ) ;
if ( F_40 ( V_2 , V_106 , V_76 ) )
F_43 ( V_2 , V_106 , & V_52 , & V_82 ,
& V_84 ) ;
if ( F_40 ( V_2 , V_107 , V_76 ) )
F_43 ( V_2 , V_107 , & V_52 , & V_82 ,
& V_84 ) ;
V_76 = F_20 ( V_76 , V_52 ) ;
V_85 = F_49 ( V_85 , V_82 ) ;
if ( V_85 )
V_76 >>= V_85 ;
if ( V_76 )
V_76 = F_50 ( V_76 ) ;
if ( V_76 > V_96 )
V_76 = V_96 ;
while ( V_76 && V_76 >= V_84 )
V_76 >>= 4 ;
V_97:
if ( V_76 < V_7 -> V_95 )
V_76 = V_7 -> V_95 ;
F_51 ( V_2 , V_76 , V_85 ,
V_7 -> V_95 ) ;
return V_76 ;
}
static int
F_52 (
struct V_108 * V_108 ,
T_13 V_20 ,
T_13 V_38 ,
unsigned V_109 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_53 ( V_108 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_92 = F_19 ( V_2 , V_34 ) ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
T_2 V_110 =
F_18 ( V_7 , V_7 -> V_111 -> V_112 ) ;
T_2 V_113 ;
int error = 0 , V_33 = 0 ;
struct V_4 V_114 ;
T_14 V_90 ;
T_9 V_115 = 0 ;
ASSERT ( ! F_7 ( V_2 ) ) ;
ASSERT ( ! F_15 ( V_2 ) ) ;
F_30 ( V_2 , V_72 ) ;
if ( F_21 ( F_54 (
( F_55 ( V_2 , V_34 ) != V_116 &&
F_55 ( V_2 , V_34 ) != V_117 ) ,
V_7 , V_118 , V_119 ) ) ) {
F_56 ( V_120 , V_121 , V_7 ) ;
error = - V_37 ;
goto V_63;
}
F_57 ( V_7 , V_122 ) ;
if ( ! ( V_92 -> V_61 & V_62 ) ) {
error = F_58 ( NULL , V_2 , V_34 ) ;
if ( error )
goto V_63;
}
V_33 = ! F_59 ( V_2 , V_92 , V_40 , & V_90 , & V_114 ) ;
if ( ! V_33 && V_114 . V_21 <= V_40 ) {
if ( F_60 ( V_2 ) ) {
bool V_123 ;
V_113 = F_61 ( F_18 ( V_7 , V_20 + V_38 ) ,
V_110 ) ;
F_62 ( & V_114 , V_40 , V_113 - V_40 ) ;
error = F_63 ( V_2 , & V_114 , & V_123 ) ;
if ( error )
goto V_63;
}
F_64 ( V_2 , V_20 , V_38 , 0 , & V_114 ) ;
goto V_124;
}
error = F_65 ( V_2 , 0 ) ;
if ( error )
goto V_63;
V_38 = F_66 ( T_13 , V_38 , 1024 * V_125 ) ;
V_113 = F_61 ( F_18 ( V_7 , V_20 + V_38 ) , V_110 ) ;
if ( V_33 ) {
V_115 = F_44 ( V_2 , V_20 , V_38 , V_90 ) ;
if ( V_115 ) {
T_1 V_26 ;
T_5 V_126 ;
T_2 V_127 ;
V_126 = F_67 ( V_7 , V_20 + V_38 - 1 ) ;
V_127 = F_17 ( V_7 , V_126 ) +
V_115 ;
V_26 = F_6 ( V_2 , 0 ) ;
if ( V_26 )
V_127 = F_9 ( V_127 , V_26 ) ;
V_127 = F_61 ( V_127 , V_110 ) ;
ASSERT ( V_127 > V_40 ) ;
V_115 = V_127 - V_113 ;
}
}
V_128:
error = F_68 ( V_2 , V_34 , V_40 ,
V_113 - V_40 , V_115 , & V_114 , & V_90 , V_33 ) ;
switch ( error ) {
case 0 :
break;
case - V_75 :
case - V_129 :
F_69 ( V_2 , V_20 , V_38 ) ;
if ( V_115 ) {
V_115 = 0 ;
goto V_128;
}
default:
goto V_63;
}
F_70 ( V_2 , V_20 , V_38 , 0 , & V_114 ) ;
V_124:
if ( F_71 ( V_114 . V_9 ) )
V_114 . V_9 = V_14 ;
if ( ! V_114 . V_9 ) {
error = F_12 ( V_2 , & V_114 ) ;
if ( error )
goto V_63;
}
F_1 ( V_2 , V_3 , & V_114 ) ;
V_63:
F_24 ( V_2 , V_72 ) ;
return error ;
}
int
F_72 (
T_3 * V_2 ,
int V_130 ,
T_5 V_20 ,
T_4 * V_5 )
{
T_7 * V_7 = V_2 -> V_8 ;
T_2 V_40 , V_131 ;
T_2 V_113 , V_132 ;
T_9 V_133 ;
struct V_50 V_51 ;
T_8 V_41 ;
T_10 * V_49 ;
int V_46 ;
int error = 0 ;
int V_109 = V_134 ;
int V_135 ;
if ( V_130 == V_136 )
V_109 |= V_137 ;
error = F_25 ( V_2 , 0 ) ;
if ( error )
return error ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_41 = V_5 -> V_23 ;
V_132 = V_5 -> V_21 ;
F_73 ( V_7 , V_138 , F_3 ( V_7 , V_41 ) ) ;
while ( V_41 != 0 ) {
V_46 = 0 ;
while ( V_46 == 0 ) {
V_135 = F_74 ( V_7 , V_34 ) ;
error = F_28 ( V_7 , & F_29 ( V_7 ) -> V_71 , 0 ,
0 , V_70 , & V_49 ) ;
if ( error )
return error ;
F_30 ( V_2 , V_72 ) ;
F_32 ( V_49 , V_2 , 0 ) ;
F_33 ( & V_51 , & V_133 ) ;
V_46 = 1 ;
V_113 = F_18 ( V_7 , F_8 ( V_2 ) ) ;
error = F_75 ( V_2 , & V_131 ,
V_34 ) ;
if ( error )
goto V_139;
V_131 = F_76 ( V_131 , V_113 ) ;
if ( ( V_132 + V_41 ) > V_131 ) {
V_41 = V_131 - V_132 ;
if ( V_41 == 0 ) {
error = - V_140 ;
goto V_139;
}
}
error = F_34 ( V_49 , V_2 , V_132 ,
V_41 , V_109 , & V_133 ,
V_135 , V_5 , & V_46 ,
& V_51 ) ;
if ( error )
goto V_139;
error = F_35 ( & V_49 , & V_51 , NULL ) ;
if ( error )
goto V_139;
error = F_36 ( V_49 ) ;
if ( error )
goto V_141;
F_24 ( V_2 , V_72 ) ;
}
if ( ! ( V_5 -> V_9 || F_7 ( V_2 ) ) )
return F_12 ( V_2 , V_5 ) ;
if ( ( V_40 >= V_5 -> V_21 ) &&
( V_40 < ( V_5 -> V_21 +
V_5 -> V_23 ) ) ) {
F_57 ( V_7 , V_142 ) ;
return 0 ;
}
V_41 -= V_5 -> V_23 ;
V_132 = V_5 -> V_21 + V_5 -> V_23 ;
}
V_139:
F_37 ( & V_51 ) ;
F_39 ( V_49 ) ;
V_141:
F_24 ( V_2 , V_72 ) ;
return error ;
}
int
F_77 (
T_3 * V_2 ,
T_5 V_20 ,
T_5 V_38 )
{
T_7 * V_7 = V_2 -> V_8 ;
T_2 V_40 ;
T_8 V_41 ;
T_8 V_143 ;
T_9 V_43 ;
int V_46 ;
T_10 * V_49 ;
T_4 V_5 ;
struct V_50 V_51 ;
T_15 V_144 ;
T_11 V_53 ;
int error ;
F_78 ( V_2 , V_20 , V_38 ) ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_41 = F_18 ( V_7 , ( V_60 ) V_20 + V_38 ) ;
V_41 = ( T_8 ) ( V_41 - V_40 ) ;
V_53 = F_23 ( V_7 , 0 ) << 1 ;
do {
error = F_28 ( V_7 , & F_29 ( V_7 ) -> V_71 , V_53 , 0 ,
V_70 | V_145 , & V_49 ) ;
if ( error )
return error ;
F_30 ( V_2 , V_72 ) ;
F_32 ( V_49 , V_2 , 0 ) ;
F_33 ( & V_51 , & V_43 ) ;
V_46 = 1 ;
error = F_34 ( V_49 , V_2 , V_40 , V_41 ,
V_68 , & V_43 , V_53 ,
& V_5 , & V_46 , & V_51 ) ;
if ( error )
goto V_146;
V_144 = F_3 ( V_7 , V_40 + V_41 ) ;
if ( V_144 > V_20 + V_38 )
V_144 = V_20 + V_38 ;
V_144 = F_79 ( V_2 , V_144 ) ;
if ( V_144 ) {
V_2 -> V_147 . V_148 = V_144 ;
F_80 ( V_49 , V_2 , V_149 ) ;
}
error = F_35 ( & V_49 , & V_51 , NULL ) ;
if ( error )
goto V_146;
error = F_36 ( V_49 ) ;
F_24 ( V_2 , V_72 ) ;
if ( error )
return error ;
if ( ! ( V_5 . V_9 || F_7 ( V_2 ) ) )
return F_12 ( V_2 , & V_5 ) ;
if ( ( V_143 = V_5 . V_23 ) == 0 ) {
ASSERT ( V_5 . V_23 ) ;
break;
}
V_40 += V_143 ;
V_41 -= V_143 ;
} while ( V_41 > 0 );
return 0 ;
V_146:
F_37 ( & V_51 ) ;
F_39 ( V_49 ) ;
F_24 ( V_2 , V_72 ) ;
return error ;
}
static inline bool F_81 ( struct V_108 * V_108 ,
struct V_4 * V_5 , int V_46 )
{
return ! V_46 ||
V_5 -> V_9 == V_10 ||
V_5 -> V_9 == V_14 ||
( F_26 ( V_108 ) && F_27 ( V_5 ) ) ;
}
static inline bool F_82 ( struct V_1 * V_2 , unsigned V_109 )
{
if ( F_60 ( V_2 ) && ( V_109 & ( V_150 | V_151 ) ) )
return true ;
if ( ( V_109 & V_152 ) && ( V_109 & V_150 ) )
return true ;
return false ;
}
static int
F_83 (
struct V_108 * V_108 ,
T_13 V_20 ,
T_13 V_22 ,
unsigned V_109 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_53 ( V_108 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 V_5 ;
T_2 V_40 , V_113 ;
int V_46 = 1 , error = 0 ;
bool V_123 = false , V_153 = false ;
unsigned V_55 ;
if ( F_84 ( V_7 ) )
return - V_154 ;
if ( ( ( V_109 & ( V_150 | V_152 ) ) == V_150 ) &&
! F_26 ( V_108 ) && ! F_15 ( V_2 ) ) {
return F_52 ( V_108 , V_20 , V_22 , V_109 ,
V_3 ) ;
}
if ( F_82 ( V_2 , V_109 ) ) {
V_55 = V_72 ;
F_30 ( V_2 , V_72 ) ;
} else {
V_55 = F_85 ( V_2 ) ;
}
ASSERT ( V_20 <= V_7 -> V_111 -> V_112 ) ;
if ( ( T_15 ) V_20 + V_22 > V_7 -> V_111 -> V_112 )
V_22 = V_7 -> V_111 -> V_112 - V_20 ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_113 = F_18 ( V_7 , V_20 + V_22 ) ;
if ( F_60 ( V_2 ) &&
( V_109 & V_150 ) && ( V_109 & V_152 ) ) {
V_123 = F_86 ( V_2 , V_20 , & V_5 ) ;
if ( V_123 ) {
F_24 ( V_2 , V_55 ) ;
goto V_155;
}
ASSERT ( ! F_71 ( V_5 . V_9 ) ) ;
}
error = F_87 ( V_2 , V_40 , V_113 - V_40 , & V_5 ,
& V_46 , 0 ) ;
if ( error )
goto V_63;
if ( ( V_109 & V_156 ) ||
( F_60 ( V_2 ) &&
( V_109 & V_150 ) && ( V_109 & V_152 ) ) ) {
error = F_88 ( V_2 , & V_5 , & V_123 ,
& V_153 ) ;
if ( error )
goto V_63;
if ( ! ( V_109 & V_156 ) && V_123 ) {
F_89 ( V_2 , & V_5 ) ;
error = - V_157 ;
goto V_63;
}
}
if ( ( V_109 & ( V_150 | V_151 ) ) && F_60 ( V_2 ) ) {
error = F_63 ( V_2 , & V_5 , & V_123 ) ;
if ( error )
goto V_63;
V_113 = V_5 . V_21 + V_5 . V_23 ;
V_22 = F_3 ( V_7 , V_113 ) - V_20 ;
}
if ( ( V_109 & V_150 ) && F_81 ( V_108 , & V_5 , V_46 ) ) {
V_22 = F_66 ( T_13 , V_22 , 1024 * V_125 ) ;
if ( V_55 == V_72 )
F_90 ( V_2 , V_55 ) ;
error = F_14 ( V_2 , V_20 , V_22 , & V_5 ,
V_46 ) ;
if ( error )
return error ;
V_155:
V_3 -> V_109 = V_158 ;
F_70 ( V_2 , V_20 , V_22 , 0 , & V_5 ) ;
} else {
ASSERT ( V_46 ) ;
F_24 ( V_2 , V_55 ) ;
F_64 ( V_2 , V_20 , V_22 , 0 , & V_5 ) ;
}
F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_123 )
V_3 -> V_109 |= V_159 ;
return 0 ;
V_63:
F_24 ( V_2 , V_55 ) ;
return error ;
}
static int
F_91 (
struct V_1 * V_2 ,
T_13 V_20 ,
T_13 V_22 ,
T_16 V_160 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_161 ;
T_2 V_113 ;
int error = 0 ;
V_161 = F_18 ( V_7 , V_20 + V_160 ) ;
V_113 = F_18 ( V_7 , V_20 + V_22 ) ;
if ( V_161 < V_113 ) {
F_30 ( V_2 , V_72 ) ;
error = F_92 ( V_2 , V_161 ,
V_113 - V_161 ) ;
F_24 ( V_2 , V_72 ) ;
if ( error && ! F_84 ( V_7 ) ) {
F_93 ( V_7 , L_4 ,
V_120 , V_2 -> V_36 ) ;
return error ;
}
}
return 0 ;
}
static int
F_94 (
struct V_108 * V_108 ,
T_13 V_20 ,
T_13 V_22 ,
T_16 V_160 ,
unsigned V_109 ,
struct V_3 * V_3 )
{
if ( ( V_109 & V_150 ) && V_3 -> type == V_15 )
return F_91 ( F_53 ( V_108 ) , V_20 ,
V_22 , V_160 ) ;
return 0 ;
}
static int
F_95 (
struct V_108 * V_108 ,
T_13 V_20 ,
T_13 V_22 ,
unsigned V_109 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_53 ( V_108 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
T_2 V_113 = F_18 ( V_7 , V_20 + V_22 ) ;
struct V_4 V_5 ;
int V_46 = 1 , error = 0 ;
unsigned V_55 ;
if ( F_84 ( V_7 ) )
return - V_154 ;
V_55 = F_85 ( V_2 ) ;
if ( F_96 ( V_2 ) || ! V_2 -> V_147 . V_162 ) {
error = - V_163 ;
goto V_63;
}
ASSERT ( V_2 -> V_147 . V_164 != V_165 ) ;
error = F_87 ( V_2 , V_40 , V_113 - V_40 , & V_5 ,
& V_46 , V_166 | V_167 ) ;
V_63:
F_24 ( V_2 , V_55 ) ;
if ( ! error ) {
ASSERT ( V_46 ) ;
F_1 ( V_2 , V_3 , & V_5 ) ;
}
return error ;
}
