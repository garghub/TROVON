STATIC int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
T_4 * V_4 )
{
T_3 V_5 = 0 ;
int V_6 , error ;
if ( ! F_2 ( V_2 ) ) {
if ( V_1 -> V_7 && ( V_1 -> V_8 & V_9 ) )
V_5 = V_1 -> V_7 ;
else if ( V_1 -> V_10 )
V_5 = V_1 -> V_10 ;
if ( V_5 && F_3 ( V_2 ) < F_4 ( V_1 , V_5 ) )
V_5 = 0 ;
}
if ( V_3 ) {
if ( V_5 )
V_5 = F_5 ( V_5 , V_3 ) ;
else
V_5 = V_3 ;
}
if ( V_5 ) {
T_4 V_11 = F_5 ( * V_4 , V_5 ) ;
error = F_6 ( V_2 , V_11 , V_12 , & V_6 ) ;
if ( error )
return error ;
if ( V_6 )
* V_4 = V_11 ;
}
return 0 ;
}
STATIC int
F_7 (
T_2 * V_2 ,
T_5 * V_13 )
{
F_8 ( V_2 -> V_14 , V_15 ,
L_1
L_2
L_3 ,
( unsigned long long ) V_2 -> V_16 ,
( unsigned long long ) V_13 -> V_17 ,
( unsigned long long ) V_13 -> V_18 ,
( unsigned long long ) V_13 -> V_19 ,
V_13 -> V_20 ) ;
return - V_21 ;
}
int
F_9 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_24 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_8 V_26 , V_27 ;
T_9 V_28 ;
T_3 V_29 , V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
T_10 * V_34 ;
T_11 V_35 ;
T_12 V_36 , V_37 , V_38 ;
int error ;
int V_39 ;
int V_40 = V_41 ;
V_33 = F_2 ( V_2 ) ;
V_29 = F_10 ( V_2 ) ;
V_39 = V_42 ;
ASSERT ( F_11 ( V_2 , V_39 ) ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_4 = F_13 ( V_1 , ( ( V_43 ) ( V_22 + V_23 ) ) ) ;
if ( ( V_22 + V_23 ) > F_3 ( V_2 ) ) {
ASSERT ( F_14 ( V_2 , V_12 ) -> V_44 &
V_45 ) ;
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
goto V_46;
} else {
if ( V_24 && ( V_13 -> V_17 == V_47 ) )
V_4 = F_15 ( V_4 , ( T_4 )
V_13 -> V_19 +
V_13 -> V_18 ) ;
}
V_26 = V_4 - V_25 ;
ASSERT ( V_26 > 0 ) ;
V_27 = V_26 ;
if ( F_16 ( V_29 ) ) {
if ( ( V_30 = F_17 ( V_25 , V_29 ) ) )
V_27 += V_30 ;
if ( ( V_30 = F_17 ( V_27 , V_29 ) ) )
V_27 += V_29 - V_30 ;
}
if ( F_16 ( V_33 ) ) {
V_38 = V_36 = V_27 ;
V_38 /= V_1 -> V_48 . V_49 ;
V_37 = F_18 ( V_1 , 0 ) ;
V_32 = V_50 ;
} else {
V_38 = 0 ;
V_37 = V_36 = F_18 ( V_1 , V_27 ) ;
V_32 = V_51 ;
}
F_19 ( V_2 , V_39 ) ;
error = F_20 ( V_2 , 0 ) ;
if ( error )
return error ;
V_34 = F_21 ( V_1 , V_52 ) ;
if ( F_22 ( F_23 ( V_2 ) ) ) {
V_40 = V_53 | V_54 ;
if ( F_24 ( V_13 ) ) {
V_34 -> V_55 |= V_56 ;
V_37 = F_18 ( V_1 , 0 ) << 1 ;
}
}
error = F_25 ( V_34 , & F_26 ( V_1 ) -> V_57 ,
V_37 , V_38 ) ;
if ( error ) {
F_27 ( V_34 ) ;
return error ;
}
V_39 = V_58 ;
F_28 ( V_2 , V_39 ) ;
error = F_29 ( V_34 , V_2 , V_36 , 0 , V_32 ) ;
if ( error )
goto V_59;
F_30 ( V_34 , V_2 , 0 ) ;
F_31 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_32 ( V_34 , V_2 , V_25 , V_26 ,
V_40 , & V_28 , V_37 , V_13 ,
& V_31 , & V_35 ) ;
if ( error )
goto V_60;
error = F_33 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_60;
error = F_34 ( V_34 ) ;
if ( error )
goto V_46;
if ( V_31 == 0 ) {
error = - V_61 ;
goto V_46;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
error = F_7 ( V_2 , V_13 ) ;
V_46:
F_19 ( V_2 , V_39 ) ;
return error ;
V_60:
F_35 ( & V_35 ) ;
F_36 ( V_34 , V_2 , ( long ) V_36 , 0 , V_32 ) ;
V_59:
F_27 ( V_34 ) ;
goto V_46;
}
STATIC int
F_37 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_31 ,
int * V_62 )
{
T_4 V_63 ;
T_8 V_26 ;
int V_64 , error , V_65 ;
int V_66 = 0 ;
* V_62 = 0 ;
if ( V_22 + V_23 <= F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_1 -> V_8 & V_67 ) &&
F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_68 ) )
return 0 ;
V_63 = F_12 ( V_1 , ( ( V_43 ) ( V_22 + V_23 - 1 ) ) ) ;
V_26 = F_13 ( V_1 , V_1 -> V_69 -> V_70 ) ;
while ( V_26 > 0 ) {
V_65 = V_31 ;
error = F_38 ( V_2 , V_63 , V_26 , V_13 , & V_65 ,
0 ) ;
if ( error )
return error ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
if ( ( V_13 [ V_64 ] . V_17 != V_47 ) &&
( V_13 [ V_64 ] . V_17 != V_71 ) )
return 0 ;
V_63 += V_13 [ V_64 ] . V_19 ;
V_26 -= V_13 [ V_64 ] . V_19 ;
if ( V_13 [ V_64 ] . V_17 == V_71 )
V_66 = 1 ;
}
}
if ( ! V_66 )
* V_62 = 1 ;
return 0 ;
}
STATIC T_9
F_39 (
struct V_72 * V_1 ,
struct V_73 * V_2 ,
T_6 V_22 ,
T_5 * V_13 ,
int V_31 )
{
T_4 V_63 ;
int V_65 = 1 ;
int error ;
ASSERT ( V_31 >= V_65 ) ;
if ( V_1 -> V_8 & V_67 )
return 0 ;
if ( F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_10 ) )
return 0 ;
V_63 = F_13 ( V_1 , V_22 ) ;
if ( V_63 )
V_63 -- ;
error = F_38 ( V_2 , V_63 , 1 , V_13 , & V_65 , V_74 ) ;
if ( error )
return 0 ;
ASSERT ( V_65 == 1 ) ;
if ( V_13 [ 0 ] . V_17 == V_47 )
return 0 ;
if ( V_13 [ 0 ] . V_19 <= ( V_75 >> 1 ) )
return V_13 [ 0 ] . V_19 << 1 ;
return F_13 ( V_1 , V_22 ) ;
}
STATIC bool
F_40 (
struct V_73 * V_2 ,
int type ,
T_9 V_76 )
{
struct V_77 * V_78 = F_41 ( V_2 , type ) ;
if ( ! V_78 || ! F_42 ( V_2 -> V_14 , type ) )
return false ;
if ( ! V_78 -> V_79 )
return false ;
if ( V_78 -> V_80 + V_76 < V_78 -> V_81 )
return false ;
return true ;
}
STATIC void
F_43 (
struct V_73 * V_2 ,
int type ,
T_9 * V_36 ,
int * V_82 ,
T_13 * V_83 )
{
T_13 V_84 ;
int V_85 = 0 ;
struct V_77 * V_78 = F_41 ( V_2 , type ) ;
if ( ! V_78 || V_78 -> V_80 >= V_78 -> V_79 ) {
* V_36 = 0 ;
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
if ( ( V_84 >> V_85 ) < ( * V_36 >> * V_82 ) ) {
* V_36 = V_84 ;
* V_82 = V_85 ;
}
}
STATIC T_9
F_44 (
struct V_72 * V_1 ,
struct V_73 * V_2 ,
T_6 V_22 ,
struct V_90 * V_13 ,
int V_31 )
{
T_9 V_76 = 0 ;
int V_85 = 0 ;
T_13 V_84 ;
T_9 V_36 ;
int V_82 = 0 ;
V_76 = F_39 ( V_1 , V_2 , V_22 ,
V_13 , V_31 ) ;
if ( ! V_76 )
goto V_91;
V_36 = V_76 ;
V_76 = F_45 ( F_46 ( V_75 ) ,
V_76 ) ;
V_84 = F_47 ( & V_1 -> V_92 ) ;
if ( V_84 < V_1 -> V_93 [ V_94 ] ) {
V_85 = 2 ;
if ( V_84 < V_1 -> V_93 [ V_95 ] )
V_85 ++ ;
if ( V_84 < V_1 -> V_93 [ V_96 ] )
V_85 ++ ;
if ( V_84 < V_1 -> V_93 [ V_97 ] )
V_85 ++ ;
if ( V_84 < V_1 -> V_93 [ V_98 ] )
V_85 ++ ;
}
if ( F_40 ( V_2 , V_99 , V_76 ) )
F_43 ( V_2 , V_99 , & V_36 , & V_82 ,
& V_84 ) ;
if ( F_40 ( V_2 , V_100 , V_76 ) )
F_43 ( V_2 , V_100 , & V_36 , & V_82 ,
& V_84 ) ;
if ( F_40 ( V_2 , V_101 , V_76 ) )
F_43 ( V_2 , V_101 , & V_36 , & V_82 ,
& V_84 ) ;
V_76 = F_15 ( V_76 , V_36 ) ;
V_85 = F_48 ( V_85 , V_82 ) ;
if ( V_85 )
V_76 >>= V_85 ;
if ( V_76 )
V_76 = F_49 ( V_76 ) ;
if ( V_76 > V_75 )
V_76 = V_75 ;
while ( V_76 && V_76 >= V_84 )
V_76 >>= 4 ;
V_91:
if ( V_76 < V_1 -> V_68 )
V_76 = V_1 -> V_68 ;
F_50 ( V_2 , V_76 , V_85 ,
V_1 -> V_68 ) ;
return V_76 ;
}
int
F_51 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_102 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_6 V_103 ;
T_4 V_104 ;
T_3 V_29 ;
int V_31 ;
T_5 V_13 [ V_105 ] ;
int V_62 ;
int error ;
ASSERT ( F_11 ( V_2 , V_58 ) ) ;
error = F_52 ( V_2 , 0 ) ;
if ( error )
return error ;
V_29 = F_10 ( V_2 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
error = F_37 ( V_1 , V_2 , V_22 , V_23 ,
V_13 , V_105 , & V_62 ) ;
if ( error )
return error ;
V_106:
if ( V_62 ) {
T_9 V_76 ;
V_76 = F_44 ( V_1 , V_2 , V_22 , V_13 ,
V_105 ) ;
V_103 = F_53 ( V_1 , ( V_22 + V_23 - 1 ) ) ;
V_104 = F_12 ( V_1 , V_103 ) ;
V_4 = V_104 + V_76 ;
} else {
V_4 = F_13 ( V_1 , ( ( V_43 ) ( V_22 + V_23 ) ) ) ;
}
if ( V_62 || V_29 ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
}
if ( V_4 > F_13 ( V_1 , V_1 -> V_69 -> V_70 ) )
V_4 = F_13 ( V_1 , V_1 -> V_69 -> V_70 ) ;
ASSERT ( V_4 > V_25 ) ;
V_31 = V_105 ;
error = F_54 ( V_2 , V_25 , V_4 - V_25 ,
V_13 , & V_31 , V_74 ) ;
switch ( error ) {
case 0 :
case - V_61 :
case - V_107 :
break;
default:
return error ;
}
if ( V_31 == 0 ) {
F_55 ( V_2 , V_22 , V_23 ) ;
if ( V_62 ) {
V_62 = 0 ;
error = 0 ;
goto V_106;
}
return error ? error : - V_61 ;
}
if ( ! ( V_13 [ 0 ] . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 [ 0 ] ) ;
if ( V_62 )
F_56 ( V_2 ) ;
* V_102 = V_13 [ 0 ] ;
return 0 ;
}
int
F_57 (
T_2 * V_2 ,
T_6 V_22 ,
T_5 * V_13 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 , V_108 ;
T_4 V_109 , V_110 ;
T_9 V_111 ;
T_11 V_35 ;
T_8 V_26 ;
T_10 * V_34 ;
int V_31 ;
int error = 0 ;
int V_112 ;
error = F_20 ( V_2 , 0 ) ;
if ( error )
return error ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = V_13 -> V_19 ;
V_110 = V_13 -> V_18 ;
F_58 ( V_1 , V_113 , F_4 ( V_1 , V_26 ) ) ;
while ( V_26 != 0 ) {
V_31 = 0 ;
while ( V_31 == 0 ) {
V_34 = F_21 ( V_1 , V_114 ) ;
V_34 -> V_55 |= V_56 ;
V_112 = F_59 ( V_1 , V_12 ) ;
error = F_25 ( V_34 , & F_26 ( V_1 ) -> V_57 ,
V_112 , 0 ) ;
if ( error ) {
F_27 ( V_34 ) ;
return error ;
}
F_28 ( V_2 , V_58 ) ;
F_30 ( V_34 , V_2 , 0 ) ;
F_31 ( & V_35 , & V_111 ) ;
V_31 = 1 ;
V_109 = F_13 ( V_1 , F_3 ( V_2 ) ) ;
error = F_60 ( V_2 , & V_108 ,
V_12 ) ;
if ( error )
goto V_115;
V_108 = F_61 ( V_108 , V_109 ) ;
if ( ( V_110 + V_26 ) > V_108 ) {
V_26 = V_108 - V_110 ;
if ( V_26 == 0 ) {
error = - V_116 ;
goto V_115;
}
}
error = F_32 ( V_34 , V_2 , V_110 ,
V_26 , 0 , & V_111 ,
V_112 , V_13 , & V_31 ,
& V_35 ) ;
if ( error )
goto V_115;
error = F_33 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_115;
error = F_34 ( V_34 ) ;
if ( error )
goto V_117;
F_19 ( V_2 , V_58 ) ;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , V_13 ) ;
if ( ( V_25 >= V_13 -> V_18 ) &&
( V_25 < ( V_13 -> V_18 +
V_13 -> V_19 ) ) ) {
F_62 ( V_1 , V_118 ) ;
return 0 ;
}
V_26 -= V_13 -> V_19 ;
V_110 = V_13 -> V_18 + V_13 -> V_19 ;
}
V_115:
F_35 ( & V_35 ) ;
F_27 ( V_34 ) ;
V_117:
F_19 ( V_2 , V_58 ) ;
return error ;
}
int
F_63 (
T_2 * V_2 ,
T_6 V_22 ,
T_6 V_23 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_8 V_26 ;
T_8 V_119 ;
T_9 V_28 ;
int V_31 ;
T_10 * V_34 ;
T_5 V_13 ;
T_11 V_35 ;
T_14 V_120 ;
T_12 V_37 ;
int error ;
F_64 ( V_2 , V_22 , V_23 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = F_13 ( V_1 , ( V_43 ) V_22 + V_23 ) ;
V_26 = ( T_8 ) ( V_26 - V_25 ) ;
V_37 = F_18 ( V_1 , 0 ) << 1 ;
do {
F_65 ( V_1 -> V_69 ) ;
V_34 = F_66 ( V_1 , V_114 , V_121 ) ;
V_34 -> V_55 |= V_56 | V_122 ;
error = F_25 ( V_34 , & F_26 ( V_1 ) -> V_57 ,
V_37 , 0 ) ;
if ( error ) {
F_27 ( V_34 ) ;
return error ;
}
F_28 ( V_2 , V_58 ) ;
F_30 ( V_34 , V_2 , 0 ) ;
F_31 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_32 ( V_34 , V_2 , V_25 , V_26 ,
V_53 , & V_28 , V_37 ,
& V_13 , & V_31 , & V_35 ) ;
if ( error )
goto V_123;
V_120 = F_4 ( V_1 , V_25 + V_26 ) ;
if ( V_120 > V_22 + V_23 )
V_120 = V_22 + V_23 ;
V_120 = F_67 ( V_2 , V_120 ) ;
if ( V_120 ) {
V_2 -> V_124 . V_125 = V_120 ;
F_68 ( V_34 , V_2 , V_126 ) ;
}
error = F_33 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_123;
error = F_34 ( V_34 ) ;
F_19 ( V_2 , V_58 ) ;
if ( error )
return error ;
if ( ! ( V_13 . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 ) ;
if ( ( V_119 = V_13 . V_19 ) == 0 ) {
ASSERT ( V_13 . V_19 ) ;
break;
}
V_25 += V_119 ;
V_26 -= V_119 ;
} while ( V_26 > 0 );
return 0 ;
V_123:
F_35 ( & V_35 ) ;
F_27 ( V_34 ) ;
F_19 ( V_2 , V_58 ) ;
return error ;
}
