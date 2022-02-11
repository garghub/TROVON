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
T_1 V_44 ;
int V_45 ;
int V_46 ;
int V_47 ;
T_10 * V_48 ;
struct V_49 V_50 ;
T_11 V_51 , V_52 , V_53 ;
int error ;
int V_54 ;
int V_55 = V_56 ;
T_11 V_57 = 0 ;
V_47 = F_7 ( V_2 ) ;
V_44 = F_15 ( V_2 ) ;
V_54 = V_58 ;
ASSERT ( F_16 ( V_2 , V_54 ) ) ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_31 = F_18 ( V_7 , ( ( V_59 ) ( V_20 + V_38 ) ) ) ;
if ( ( V_20 + V_38 ) > F_8 ( V_2 ) ) {
ASSERT ( F_19 ( V_2 , V_34 ) -> V_60 &
V_61 ) ;
error = F_10 ( V_2 , V_44 , & V_31 ) ;
if ( error )
goto V_62;
} else {
if ( V_39 && ( V_5 -> V_9 == V_10 ) )
V_31 = F_20 ( V_31 , ( T_2 )
V_5 -> V_23 +
V_5 -> V_21 ) ;
}
V_41 = V_31 - V_40 ;
ASSERT ( V_41 > 0 ) ;
V_42 = F_21 ( V_40 , V_41 , V_44 ) ;
if ( F_22 ( V_47 ) ) {
V_53 = V_51 = V_42 ;
V_53 /= V_7 -> V_63 . V_64 ;
V_52 = F_23 ( V_7 , 0 ) ;
V_46 = V_65 ;
} else {
V_53 = 0 ;
V_52 = V_51 = F_23 ( V_7 , V_42 ) ;
V_46 = V_66 ;
}
F_24 ( V_2 , V_54 ) ;
error = F_25 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( F_26 ( F_5 ( V_2 ) ) ) {
V_55 = V_67 | V_68 ;
if ( V_5 -> V_16 == V_17 ) {
V_57 |= V_69 ;
V_52 = F_23 ( V_7 , 0 ) << 1 ;
}
}
error = F_27 ( V_7 , & F_28 ( V_7 ) -> V_70 , V_52 , V_53 ,
V_57 , & V_48 ) ;
if ( error )
return error ;
V_54 = V_71 ;
F_29 ( V_2 , V_54 ) ;
error = F_30 ( V_48 , V_2 , V_51 , 0 , V_46 ) ;
if ( error )
goto V_72;
F_31 ( V_48 , V_2 , 0 ) ;
F_32 ( & V_50 , & V_43 ) ;
V_45 = 1 ;
error = F_33 ( V_48 , V_2 , V_40 , V_41 ,
V_55 , & V_43 , V_52 , V_5 ,
& V_45 , & V_50 ) ;
if ( error )
goto V_73;
error = F_34 ( & V_48 , & V_50 , NULL ) ;
if ( error )
goto V_73;
error = F_35 ( V_48 ) ;
if ( error )
goto V_62;
if ( V_45 == 0 ) {
error = - V_74 ;
goto V_62;
}
if ( ! ( V_5 -> V_9 || F_7 ( V_2 ) ) )
error = F_12 ( V_2 , V_5 ) ;
V_62:
F_24 ( V_2 , V_54 ) ;
return error ;
V_73:
F_36 ( & V_50 ) ;
F_37 ( V_48 , V_2 , ( long ) V_51 , 0 , V_46 ) ;
V_72:
F_38 ( V_48 ) ;
goto V_62;
}
STATIC bool
F_39 (
struct V_1 * V_2 ,
int type ,
T_9 V_75 )
{
struct V_76 * V_77 = F_40 ( V_2 , type ) ;
if ( ! V_77 || ! F_41 ( V_2 -> V_8 , type ) )
return false ;
if ( ! V_77 -> V_78 )
return false ;
if ( V_77 -> V_79 + V_75 < V_77 -> V_80 )
return false ;
return true ;
}
STATIC void
F_42 (
struct V_1 * V_2 ,
int type ,
T_9 * V_51 ,
int * V_81 ,
T_12 * V_82 )
{
T_12 V_83 ;
int V_84 = 0 ;
struct V_76 * V_77 = F_40 ( V_2 , type ) ;
if ( ! V_77 || V_77 -> V_79 >= V_77 -> V_78 ) {
* V_51 = 0 ;
* V_82 = 0 ;
return;
}
V_83 = V_77 -> V_78 - V_77 -> V_79 ;
if ( V_83 < V_77 -> V_85 [ V_86 ] ) {
V_84 = 2 ;
if ( V_83 < V_77 -> V_85 [ V_87 ] )
V_84 += 2 ;
if ( V_83 < V_77 -> V_85 [ V_88 ] )
V_84 += 2 ;
}
if ( V_83 < * V_82 )
* V_82 = V_83 ;
if ( ( V_83 >> V_84 ) < ( * V_51 >> * V_81 ) ) {
* V_51 = V_83 ;
* V_81 = V_84 ;
}
}
STATIC T_9
F_43 (
struct V_1 * V_2 ,
T_13 V_20 ,
T_13 V_38 ,
T_14 V_89 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_91 = F_19 ( V_2 , V_34 ) ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
struct V_4 V_92 ;
int V_84 = 0 ;
T_12 V_83 ;
T_9 V_51 ;
int V_81 = 0 ;
T_9 V_75 = 0 ;
if ( V_20 + V_38 <= F_8 ( V_2 ) )
return 0 ;
if ( ! ( V_7 -> V_28 & V_93 ) &&
( F_8 ( V_2 ) < F_3 ( V_7 , V_7 -> V_94 ) ) )
return 0 ;
if ( ( V_7 -> V_28 & V_93 ) ||
F_8 ( V_2 ) < F_3 ( V_7 , V_7 -> V_30 ) ||
! F_44 ( V_91 , V_89 - 1 , & V_92 ) ||
V_92 . V_21 + V_92 . V_23 < V_40 )
return V_7 -> V_94 ;
if ( V_92 . V_23 <= ( V_95 >> 1 ) )
V_75 = V_92 . V_23 << 1 ;
else
V_75 = F_18 ( V_7 , V_20 ) ;
if ( ! V_75 )
goto V_96;
V_51 = V_75 ;
V_75 = F_45 ( F_46 ( V_95 ) ,
V_75 ) ;
V_83 = F_47 ( & V_7 -> V_97 ) ;
if ( V_83 < V_7 -> V_98 [ V_99 ] ) {
V_84 = 2 ;
if ( V_83 < V_7 -> V_98 [ V_100 ] )
V_84 ++ ;
if ( V_83 < V_7 -> V_98 [ V_101 ] )
V_84 ++ ;
if ( V_83 < V_7 -> V_98 [ V_102 ] )
V_84 ++ ;
if ( V_83 < V_7 -> V_98 [ V_103 ] )
V_84 ++ ;
}
if ( F_39 ( V_2 , V_104 , V_75 ) )
F_42 ( V_2 , V_104 , & V_51 , & V_81 ,
& V_83 ) ;
if ( F_39 ( V_2 , V_105 , V_75 ) )
F_42 ( V_2 , V_105 , & V_51 , & V_81 ,
& V_83 ) ;
if ( F_39 ( V_2 , V_106 , V_75 ) )
F_42 ( V_2 , V_106 , & V_51 , & V_81 ,
& V_83 ) ;
V_75 = F_20 ( V_75 , V_51 ) ;
V_84 = F_48 ( V_84 , V_81 ) ;
if ( V_84 )
V_75 >>= V_84 ;
if ( V_75 )
V_75 = F_49 ( V_75 ) ;
if ( V_75 > V_95 )
V_75 = V_95 ;
while ( V_75 && V_75 >= V_83 )
V_75 >>= 4 ;
V_96:
if ( V_75 < V_7 -> V_94 )
V_75 = V_7 -> V_94 ;
F_50 ( V_2 , V_75 , V_84 ,
V_7 -> V_94 ) ;
return V_75 ;
}
static int
F_51 (
struct V_107 * V_107 ,
T_13 V_20 ,
T_13 V_38 ,
unsigned V_108 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_91 = F_19 ( V_2 , V_34 ) ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
T_2 V_109 =
F_18 ( V_7 , V_7 -> V_110 -> V_111 ) ;
T_2 V_112 ;
int error = 0 , V_33 = 0 ;
struct V_4 V_113 ;
T_14 V_89 ;
T_9 V_114 = 0 ;
ASSERT ( ! F_7 ( V_2 ) ) ;
ASSERT ( ! F_15 ( V_2 ) ) ;
F_29 ( V_2 , V_71 ) ;
if ( F_22 ( F_53 (
( F_54 ( V_2 , V_34 ) != V_115 &&
F_54 ( V_2 , V_34 ) != V_116 ) ,
V_7 , V_117 , V_118 ) ) ) {
F_55 ( V_119 , V_120 , V_7 ) ;
error = - V_37 ;
goto V_62;
}
F_56 ( V_7 , V_121 ) ;
if ( ! ( V_91 -> V_60 & V_61 ) ) {
error = F_57 ( NULL , V_2 , V_34 ) ;
if ( error )
goto V_62;
}
V_33 = ! F_58 ( V_2 , V_91 , V_40 , & V_89 , & V_113 ) ;
if ( ! V_33 && V_113 . V_21 <= V_40 ) {
if ( F_59 ( V_2 ) ) {
bool V_122 ;
V_112 = F_60 ( F_18 ( V_7 , V_20 + V_38 ) ,
V_109 ) ;
F_61 ( & V_113 , V_40 , V_112 - V_40 ) ;
error = F_62 ( V_2 , & V_113 , & V_122 ) ;
if ( error )
goto V_62;
}
F_63 ( V_2 , V_20 , V_38 , 0 , & V_113 ) ;
goto V_123;
}
error = F_64 ( V_2 , 0 ) ;
if ( error )
goto V_62;
V_38 = F_65 ( T_13 , V_38 , 1024 * V_124 ) ;
V_112 = F_60 ( F_18 ( V_7 , V_20 + V_38 ) , V_109 ) ;
if ( V_33 ) {
V_114 = F_43 ( V_2 , V_20 , V_38 , V_89 ) ;
if ( V_114 ) {
T_1 V_26 ;
T_5 V_125 ;
T_2 V_126 ;
V_125 = F_66 ( V_7 , V_20 + V_38 - 1 ) ;
V_126 = F_17 ( V_7 , V_125 ) +
V_114 ;
V_26 = F_6 ( V_2 , 0 ) ;
if ( V_26 )
V_126 = F_9 ( V_126 , V_26 ) ;
V_126 = F_60 ( V_126 , V_109 ) ;
ASSERT ( V_126 > V_40 ) ;
V_114 = V_126 - V_112 ;
}
}
V_127:
error = F_67 ( V_2 , V_34 , V_40 ,
V_112 - V_40 , V_114 , & V_113 , & V_89 , V_33 ) ;
switch ( error ) {
case 0 :
break;
case - V_74 :
case - V_128 :
F_68 ( V_2 , V_20 , V_38 ) ;
if ( V_114 ) {
V_114 = 0 ;
goto V_127;
}
default:
goto V_62;
}
V_3 -> V_108 = V_129 ;
F_69 ( V_2 , V_20 , V_38 , 0 , & V_113 ) ;
V_123:
if ( F_70 ( V_113 . V_9 ) )
V_113 . V_9 = V_14 ;
if ( ! V_113 . V_9 ) {
error = F_12 ( V_2 , & V_113 ) ;
if ( error )
goto V_62;
}
F_1 ( V_2 , V_3 , & V_113 ) ;
V_62:
F_24 ( V_2 , V_71 ) ;
return error ;
}
int
F_71 (
T_3 * V_2 ,
int V_130 ,
T_5 V_20 ,
T_4 * V_5 )
{
T_7 * V_7 = V_2 -> V_8 ;
T_2 V_40 , V_131 ;
T_2 V_112 , V_132 ;
T_9 V_133 ;
struct V_49 V_50 ;
T_8 V_41 ;
T_10 * V_48 ;
int V_45 ;
int error = 0 ;
int V_108 = V_134 ;
int V_135 ;
if ( V_130 == V_136 )
V_108 |= V_137 | V_56 ;
error = F_25 ( V_2 , 0 ) ;
if ( error )
return error ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_41 = V_5 -> V_23 ;
V_132 = V_5 -> V_21 ;
F_72 ( V_7 , V_138 , F_3 ( V_7 , V_41 ) ) ;
while ( V_41 != 0 ) {
V_45 = 0 ;
while ( V_45 == 0 ) {
V_135 = F_73 ( V_7 , V_34 ) ;
error = F_27 ( V_7 , & F_28 ( V_7 ) -> V_70 , 0 ,
0 , V_69 , & V_48 ) ;
if ( error )
return error ;
F_29 ( V_2 , V_71 ) ;
F_31 ( V_48 , V_2 , 0 ) ;
F_32 ( & V_50 , & V_133 ) ;
V_45 = 1 ;
V_112 = F_18 ( V_7 , F_8 ( V_2 ) ) ;
error = F_74 ( V_2 , & V_131 ,
V_34 ) ;
if ( error )
goto V_139;
V_131 = F_75 ( V_131 , V_112 ) ;
if ( ( V_132 + V_41 ) > V_131 ) {
V_41 = V_131 - V_132 ;
if ( V_41 == 0 ) {
error = - V_140 ;
goto V_139;
}
}
error = F_33 ( V_48 , V_2 , V_132 ,
V_41 , V_108 , & V_133 ,
V_135 , V_5 , & V_45 ,
& V_50 ) ;
if ( error )
goto V_139;
error = F_34 ( & V_48 , & V_50 , NULL ) ;
if ( error )
goto V_139;
error = F_35 ( V_48 ) ;
if ( error )
goto V_141;
F_24 ( V_2 , V_71 ) ;
}
if ( ! ( V_5 -> V_9 || F_7 ( V_2 ) ) )
return F_12 ( V_2 , V_5 ) ;
if ( ( V_40 >= V_5 -> V_21 ) &&
( V_40 < ( V_5 -> V_21 +
V_5 -> V_23 ) ) ) {
F_56 ( V_7 , V_142 ) ;
return 0 ;
}
V_41 -= V_5 -> V_23 ;
V_132 = V_5 -> V_21 + V_5 -> V_23 ;
}
V_139:
F_36 ( & V_50 ) ;
F_38 ( V_48 ) ;
V_141:
F_24 ( V_2 , V_71 ) ;
return error ;
}
int
F_76 (
T_3 * V_2 ,
T_5 V_20 ,
T_5 V_38 )
{
T_7 * V_7 = V_2 -> V_8 ;
T_2 V_40 ;
T_8 V_41 ;
T_8 V_143 ;
T_9 V_43 ;
int V_45 ;
T_10 * V_48 ;
T_4 V_5 ;
struct V_49 V_50 ;
T_15 V_144 ;
T_11 V_52 ;
int error ;
F_77 ( V_2 , V_20 , V_38 ) ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_41 = F_18 ( V_7 , ( V_59 ) V_20 + V_38 ) ;
V_41 = ( T_8 ) ( V_41 - V_40 ) ;
V_52 = F_23 ( V_7 , 0 ) << 1 ;
do {
error = F_27 ( V_7 , & F_28 ( V_7 ) -> V_70 , V_52 , 0 ,
V_69 | V_145 , & V_48 ) ;
if ( error )
return error ;
F_29 ( V_2 , V_71 ) ;
F_31 ( V_48 , V_2 , 0 ) ;
F_32 ( & V_50 , & V_43 ) ;
V_45 = 1 ;
error = F_33 ( V_48 , V_2 , V_40 , V_41 ,
V_67 , & V_43 , V_52 ,
& V_5 , & V_45 , & V_50 ) ;
if ( error )
goto V_146;
V_144 = F_3 ( V_7 , V_40 + V_41 ) ;
if ( V_144 > V_20 + V_38 )
V_144 = V_20 + V_38 ;
V_144 = F_78 ( V_2 , V_144 ) ;
if ( V_144 ) {
V_2 -> V_147 . V_148 = V_144 ;
F_79 ( V_48 , V_2 , V_149 ) ;
}
error = F_34 ( & V_48 , & V_50 , NULL ) ;
if ( error )
goto V_146;
error = F_35 ( V_48 ) ;
F_24 ( V_2 , V_71 ) ;
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
F_36 ( & V_50 ) ;
F_38 ( V_48 ) ;
F_24 ( V_2 , V_71 ) ;
return error ;
}
static inline bool F_80 ( struct V_107 * V_107 ,
struct V_4 * V_5 , int V_45 )
{
return ! V_45 ||
V_5 -> V_9 == V_10 ||
V_5 -> V_9 == V_14 ||
( F_26 ( V_107 ) && V_5 -> V_16 == V_17 ) ;
}
static inline bool F_81 ( struct V_1 * V_2 , unsigned V_108 )
{
if ( F_59 ( V_2 ) && ( V_108 & ( V_150 | V_151 ) ) )
return true ;
if ( ( V_108 & V_152 ) && ( V_108 & V_150 ) )
return true ;
return false ;
}
static int
F_82 (
struct V_107 * V_107 ,
T_13 V_20 ,
T_13 V_22 ,
unsigned V_108 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 V_5 ;
T_2 V_40 , V_112 ;
int V_45 = 1 , error = 0 ;
bool V_122 = false , V_153 = false ;
unsigned V_54 ;
struct V_154 * V_24 ;
if ( F_83 ( V_7 ) )
return - V_155 ;
if ( ( ( V_108 & ( V_150 | V_152 ) ) == V_150 ) &&
! F_26 ( V_107 ) && ! F_15 ( V_2 ) ) {
return F_51 ( V_107 , V_20 , V_22 , V_108 ,
V_3 ) ;
}
if ( F_81 ( V_2 , V_108 ) ) {
V_54 = V_71 ;
F_29 ( V_2 , V_71 ) ;
} else {
V_54 = F_84 ( V_2 ) ;
}
ASSERT ( V_20 <= V_7 -> V_110 -> V_111 ) ;
if ( ( T_15 ) V_20 + V_22 > V_7 -> V_110 -> V_111 )
V_22 = V_7 -> V_110 -> V_111 - V_20 ;
V_40 = F_17 ( V_7 , V_20 ) ;
V_112 = F_18 ( V_7 , V_20 + V_22 ) ;
error = F_85 ( V_2 , V_40 , V_112 - V_40 , & V_5 ,
& V_45 , 0 ) ;
if ( error )
goto V_62;
if ( V_108 & V_156 ) {
error = F_86 ( V_2 , & V_5 , & V_122 ,
& V_153 ) ;
if ( error )
goto V_62;
}
if ( ( V_108 & ( V_150 | V_151 ) ) && F_59 ( V_2 ) ) {
if ( V_108 & V_152 ) {
error = F_87 ( V_2 , & V_5 , & V_122 ,
& V_54 ) ;
if ( error )
goto V_62;
} else {
error = F_62 ( V_2 , & V_5 , & V_122 ) ;
if ( error )
goto V_62;
}
V_112 = V_5 . V_21 + V_5 . V_23 ;
V_22 = F_3 ( V_7 , V_112 ) - V_20 ;
}
if ( ( V_108 & V_150 ) && F_80 ( V_107 , & V_5 , V_45 ) ) {
V_22 = F_65 ( T_13 , V_22 , 1024 * V_124 ) ;
if ( V_54 == V_71 )
F_88 ( V_2 , V_54 ) ;
error = F_14 ( V_2 , V_20 , V_22 , & V_5 ,
V_45 ) ;
if ( error )
return error ;
V_3 -> V_108 = V_129 ;
F_69 ( V_2 , V_20 , V_22 , 0 , & V_5 ) ;
} else {
ASSERT ( V_45 ) ;
F_24 ( V_2 , V_54 ) ;
F_63 ( V_2 , V_20 , V_22 , 0 , & V_5 ) ;
}
F_1 ( V_2 , V_3 , & V_5 ) ;
V_24 = V_3 -> V_24 ;
if ( F_89 ( V_24 -> V_157 ) )
V_3 -> V_158 = F_90 ( V_24 -> V_159 -> V_160 ) ;
else
V_3 -> V_158 = NULL ;
if ( V_122 )
V_3 -> V_108 |= V_161 ;
return 0 ;
V_62:
F_24 ( V_2 , V_54 ) ;
return error ;
}
static int
F_91 (
struct V_1 * V_2 ,
T_13 V_20 ,
T_13 V_22 ,
T_16 V_162 ,
struct V_3 * V_3 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_163 ;
T_2 V_112 ;
int error = 0 ;
if ( F_92 ( V_7 ) ) {
V_3 -> V_108 |= V_129 ;
V_162 = 0 ;
}
if ( F_22 ( ! V_162 ) )
V_163 = F_17 ( V_7 , V_20 ) ;
else
V_163 = F_18 ( V_7 , V_20 + V_162 ) ;
V_112 = F_18 ( V_7 , V_20 + V_22 ) ;
if ( ( V_3 -> V_108 & V_129 ) && V_163 < V_112 ) {
F_93 ( F_5 ( V_2 ) , F_3 ( V_7 , V_163 ) ,
F_3 ( V_7 , V_112 ) - 1 ) ;
F_29 ( V_2 , V_71 ) ;
error = F_94 ( V_2 , V_163 ,
V_112 - V_163 ) ;
F_24 ( V_2 , V_71 ) ;
if ( error && ! F_83 ( V_7 ) ) {
F_95 ( V_7 , L_4 ,
V_119 , V_2 -> V_36 ) ;
return error ;
}
}
return 0 ;
}
static int
F_96 (
struct V_107 * V_107 ,
T_13 V_20 ,
T_13 V_22 ,
T_16 V_162 ,
unsigned V_108 ,
struct V_3 * V_3 )
{
F_97 ( V_3 -> V_158 ) ;
if ( ( V_108 & V_150 ) && V_3 -> type == V_15 )
return F_91 ( F_52 ( V_107 ) , V_20 ,
V_22 , V_162 , V_3 ) ;
return 0 ;
}
static int
F_98 (
struct V_107 * V_107 ,
T_13 V_20 ,
T_13 V_22 ,
unsigned V_108 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_40 = F_17 ( V_7 , V_20 ) ;
T_2 V_112 = F_18 ( V_7 , V_20 + V_22 ) ;
struct V_4 V_5 ;
int V_45 = 1 , error = 0 ;
unsigned V_54 ;
if ( F_83 ( V_7 ) )
return - V_155 ;
V_54 = F_99 ( V_2 ) ;
if ( ! F_100 ( V_2 ) || ! V_2 -> V_147 . V_164 ) {
error = - V_165 ;
goto V_62;
}
ASSERT ( V_2 -> V_147 . V_166 != V_167 ) ;
error = F_85 ( V_2 , V_40 , V_112 - V_40 , & V_5 ,
& V_45 , V_168 | V_169 ) ;
V_62:
F_24 ( V_2 , V_54 ) ;
if ( ! error ) {
ASSERT ( V_45 ) ;
F_1 ( V_2 , V_3 , & V_5 ) ;
}
return error ;
}
