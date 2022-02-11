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
int V_39 ;
int error ;
error = F_10 ( V_2 , 0 ) ;
if ( error )
return error ;
V_33 = F_2 ( V_2 ) ;
V_29 = F_11 ( V_2 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_4 = F_13 ( V_1 , ( ( V_40 ) ( V_22 + V_23 ) ) ) ;
if ( ( V_22 + V_23 ) > F_3 ( V_2 ) ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
} else {
if ( V_24 && ( V_13 -> V_17 == V_41 ) )
V_4 = F_14 ( V_4 , ( T_4 )
V_13 -> V_19 +
V_13 -> V_18 ) ;
}
V_26 = V_4 - V_25 ;
ASSERT ( V_26 > 0 ) ;
V_27 = V_26 ;
if ( F_15 ( V_29 ) ) {
if ( ( V_30 = F_16 ( V_25 , V_29 ) ) )
V_27 += V_30 ;
if ( ( V_30 = F_16 ( V_27 , V_29 ) ) )
V_27 += V_29 - V_30 ;
}
if ( F_15 ( V_33 ) ) {
V_38 = V_36 = V_27 ;
V_38 /= V_1 -> V_42 . V_43 ;
V_37 = F_17 ( V_1 , 0 ) ;
V_32 = V_44 ;
} else {
V_38 = 0 ;
V_37 = V_36 = F_17 ( V_1 , V_27 ) ;
V_32 = V_45 ;
}
V_34 = F_18 ( V_1 , V_46 ) ;
error = F_19 ( V_34 , & F_20 ( V_1 ) -> V_47 ,
V_37 , V_38 ) ;
if ( error ) {
F_21 ( V_34 , 0 ) ;
return error ;
}
F_22 ( V_2 , V_48 ) ;
error = F_23 ( V_34 , V_2 , V_36 , 0 , V_32 ) ;
if ( error )
goto V_49;
F_24 ( V_34 , V_2 , 0 ) ;
F_25 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_26 ( V_34 , V_2 , V_25 , V_26 ,
V_50 , & V_28 , 0 ,
V_13 , & V_31 , & V_35 ) ;
if ( error )
goto V_51;
error = F_27 ( & V_34 , & V_35 , & V_39 ) ;
if ( error )
goto V_51;
error = F_28 ( V_34 , V_52 ) ;
if ( error )
goto V_53;
if ( V_31 == 0 ) {
error = - V_54 ;
goto V_53;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
error = F_7 ( V_2 , V_13 ) ;
V_53:
F_29 ( V_2 , V_48 ) ;
return error ;
V_51:
F_30 ( & V_35 ) ;
F_31 ( V_34 , V_2 , ( long ) V_36 , 0 , V_32 ) ;
V_49:
F_21 ( V_34 , V_52 | V_55 ) ;
goto V_53;
}
STATIC int
F_32 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_31 ,
int * V_56 )
{
T_4 V_57 ;
T_8 V_26 ;
int V_58 , error , V_59 ;
int V_60 = 0 ;
* V_56 = 0 ;
if ( V_22 + V_23 <= F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_1 -> V_8 & V_61 ) &&
F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_62 ) )
return 0 ;
V_57 = F_12 ( V_1 , ( ( V_40 ) ( V_22 + V_23 - 1 ) ) ) ;
V_26 = F_13 ( V_1 , V_1 -> V_63 -> V_64 ) ;
while ( V_26 > 0 ) {
V_59 = V_31 ;
error = F_33 ( V_2 , V_57 , V_26 , V_13 , & V_59 ,
0 ) ;
if ( error )
return error ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( ( V_13 [ V_58 ] . V_17 != V_41 ) &&
( V_13 [ V_58 ] . V_17 != V_65 ) )
return 0 ;
V_57 += V_13 [ V_58 ] . V_19 ;
V_26 -= V_13 [ V_58 ] . V_19 ;
if ( V_13 [ V_58 ] . V_17 == V_65 )
V_60 = 1 ;
}
}
if ( ! V_60 )
* V_56 = 1 ;
return 0 ;
}
STATIC T_9
F_34 (
struct V_66 * V_1 ,
struct V_67 * V_2 ,
T_6 V_22 ,
T_5 * V_13 ,
int V_31 )
{
T_4 V_57 ;
int V_59 = 1 ;
int error ;
ASSERT ( V_31 >= V_59 ) ;
if ( V_1 -> V_8 & V_61 )
return 0 ;
if ( F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_10 ) )
return 0 ;
V_57 = F_13 ( V_1 , V_22 ) ;
if ( V_57 )
V_57 -- ;
error = F_33 ( V_2 , V_57 , 1 , V_13 , & V_59 , V_68 ) ;
if ( error )
return 0 ;
ASSERT ( V_59 == 1 ) ;
if ( V_13 [ 0 ] . V_17 == V_41 )
return 0 ;
if ( V_13 [ 0 ] . V_19 <= ( V_69 >> 1 ) )
return V_13 [ 0 ] . V_19 << 1 ;
return F_13 ( V_1 , V_22 ) ;
}
STATIC bool
F_35 (
struct V_67 * V_2 ,
int type ,
T_9 V_70 )
{
struct V_71 * V_72 = F_36 ( V_2 , type ) ;
if ( ! V_72 || ! F_37 ( V_2 -> V_14 , type ) )
return false ;
if ( ! V_72 -> V_73 )
return false ;
if ( V_72 -> V_74 + V_70 < V_72 -> V_75 )
return false ;
return true ;
}
STATIC void
F_38 (
struct V_67 * V_2 ,
int type ,
T_9 * V_36 ,
int * V_76 ,
T_13 * V_77 )
{
T_13 V_78 ;
int V_79 = 0 ;
struct V_71 * V_72 = F_36 ( V_2 , type ) ;
if ( ! V_72 || V_72 -> V_74 >= V_72 -> V_73 ) {
* V_36 = 0 ;
* V_77 = 0 ;
return;
}
V_78 = V_72 -> V_73 - V_72 -> V_74 ;
if ( V_78 < V_72 -> V_80 [ V_81 ] ) {
V_79 = 2 ;
if ( V_78 < V_72 -> V_80 [ V_82 ] )
V_79 += 2 ;
if ( V_78 < V_72 -> V_80 [ V_83 ] )
V_79 += 2 ;
}
if ( V_78 < * V_77 )
* V_77 = V_78 ;
if ( ( V_78 >> V_79 ) < ( * V_36 >> * V_76 ) ) {
* V_36 = V_78 ;
* V_76 = V_79 ;
}
}
STATIC T_9
F_39 (
struct V_66 * V_1 ,
struct V_67 * V_2 ,
T_6 V_22 ,
struct V_84 * V_13 ,
int V_31 )
{
T_9 V_70 = 0 ;
int V_79 = 0 ;
T_13 V_78 ;
T_9 V_36 ;
int V_76 = 0 ;
V_70 = F_34 ( V_1 , V_2 , V_22 ,
V_13 , V_31 ) ;
if ( ! V_70 )
goto V_85;
V_36 = V_70 ;
V_70 = F_40 ( F_41 ( V_69 ) ,
V_70 ) ;
V_78 = F_42 ( & V_1 -> V_86 ) ;
if ( V_78 < V_1 -> V_87 [ V_88 ] ) {
V_79 = 2 ;
if ( V_78 < V_1 -> V_87 [ V_89 ] )
V_79 ++ ;
if ( V_78 < V_1 -> V_87 [ V_90 ] )
V_79 ++ ;
if ( V_78 < V_1 -> V_87 [ V_91 ] )
V_79 ++ ;
if ( V_78 < V_1 -> V_87 [ V_92 ] )
V_79 ++ ;
}
if ( F_35 ( V_2 , V_93 , V_70 ) )
F_38 ( V_2 , V_93 , & V_36 , & V_76 ,
& V_78 ) ;
if ( F_35 ( V_2 , V_94 , V_70 ) )
F_38 ( V_2 , V_94 , & V_36 , & V_76 ,
& V_78 ) ;
if ( F_35 ( V_2 , V_95 , V_70 ) )
F_38 ( V_2 , V_95 , & V_36 , & V_76 ,
& V_78 ) ;
V_70 = F_14 ( V_70 , V_36 ) ;
V_79 = F_43 ( V_79 , V_76 ) ;
if ( V_79 )
V_70 >>= V_79 ;
if ( V_70 )
V_70 = F_44 ( V_70 ) ;
if ( V_70 > V_69 )
V_70 = V_69 ;
while ( V_70 && V_70 >= V_78 )
V_70 >>= 4 ;
V_85:
if ( V_70 < V_1 -> V_62 )
V_70 = V_1 -> V_62 ;
F_45 ( V_2 , V_70 , V_79 ,
V_1 -> V_62 ) ;
return V_70 ;
}
int
F_46 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_96 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_6 V_97 ;
T_4 V_98 ;
T_3 V_29 ;
int V_31 ;
T_5 V_13 [ V_99 ] ;
int V_56 ;
int error ;
ASSERT ( F_47 ( V_2 , V_48 ) ) ;
error = F_48 ( V_2 , 0 ) ;
if ( error )
return error ;
V_29 = F_11 ( V_2 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
error = F_32 ( V_1 , V_2 , V_22 , V_23 ,
V_13 , V_99 , & V_56 ) ;
if ( error )
return error ;
V_100:
if ( V_56 ) {
T_9 V_70 ;
V_70 = F_39 ( V_1 , V_2 , V_22 , V_13 ,
V_99 ) ;
V_97 = F_49 ( V_1 , ( V_22 + V_23 - 1 ) ) ;
V_98 = F_12 ( V_1 , V_97 ) ;
V_4 = V_98 + V_70 ;
} else {
V_4 = F_13 ( V_1 , ( ( V_40 ) ( V_22 + V_23 ) ) ) ;
}
if ( V_56 || V_29 ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
}
if ( V_4 > F_13 ( V_1 , V_1 -> V_63 -> V_64 ) )
V_4 = F_13 ( V_1 , V_1 -> V_63 -> V_64 ) ;
ASSERT ( V_4 > V_25 ) ;
V_31 = V_99 ;
error = F_50 ( V_2 , V_25 , V_4 - V_25 ,
V_13 , & V_31 , V_68 ) ;
switch ( error ) {
case 0 :
case - V_54 :
case - V_101 :
break;
default:
return error ;
}
if ( V_31 == 0 ) {
F_51 ( V_2 , V_22 , V_23 ) ;
if ( V_56 ) {
V_56 = 0 ;
error = 0 ;
goto V_100;
}
return error ? error : - V_54 ;
}
if ( ! ( V_13 [ 0 ] . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 [ 0 ] ) ;
if ( V_56 )
F_52 ( V_2 ) ;
* V_96 = V_13 [ 0 ] ;
return 0 ;
}
int
F_53 (
T_2 * V_2 ,
T_6 V_22 ,
T_5 * V_13 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 , V_102 ;
T_4 V_103 , V_104 ;
T_9 V_105 ;
T_11 V_35 ;
T_8 V_26 ;
T_10 * V_34 ;
int V_31 , V_39 ;
int error = 0 ;
int V_106 ;
error = F_10 ( V_2 , 0 ) ;
if ( error )
return error ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = V_13 -> V_19 ;
V_104 = V_13 -> V_18 ;
F_54 ( V_107 , F_4 ( V_1 , V_26 ) ) ;
while ( V_26 != 0 ) {
V_31 = 0 ;
while ( V_31 == 0 ) {
V_34 = F_18 ( V_1 , V_108 ) ;
V_34 -> V_109 |= V_110 ;
V_106 = F_55 ( V_1 , V_12 ) ;
error = F_19 ( V_34 , & F_20 ( V_1 ) -> V_47 ,
V_106 , 0 ) ;
if ( error ) {
F_21 ( V_34 , 0 ) ;
return error ;
}
F_22 ( V_2 , V_48 ) ;
F_24 ( V_34 , V_2 , 0 ) ;
F_25 ( & V_35 , & V_105 ) ;
V_31 = 1 ;
V_103 = F_13 ( V_1 , F_3 ( V_2 ) ) ;
error = F_56 ( V_2 , & V_102 ,
V_12 ) ;
if ( error )
goto V_111;
V_102 = F_57 ( V_102 , V_103 ) ;
if ( ( V_104 + V_26 ) > V_102 ) {
V_26 = V_102 - V_104 ;
if ( V_26 == 0 ) {
error = - V_112 ;
goto V_111;
}
}
error = F_26 ( V_34 , V_2 , V_104 ,
V_26 , 0 ,
& V_105 , 1 ,
V_13 , & V_31 , & V_35 ) ;
if ( error )
goto V_111;
error = F_27 ( & V_34 , & V_35 , & V_39 ) ;
if ( error )
goto V_111;
error = F_28 ( V_34 , V_52 ) ;
if ( error )
goto V_113;
F_29 ( V_2 , V_48 ) ;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , V_13 ) ;
if ( ( V_25 >= V_13 -> V_18 ) &&
( V_25 < ( V_13 -> V_18 +
V_13 -> V_19 ) ) ) {
F_58 ( V_114 ) ;
return 0 ;
}
V_26 -= V_13 -> V_19 ;
V_104 = V_13 -> V_18 + V_13 -> V_19 ;
}
V_111:
F_30 ( & V_35 ) ;
F_21 ( V_34 , V_52 | V_55 ) ;
V_113:
F_29 ( V_2 , V_48 ) ;
return error ;
}
int
F_59 (
T_2 * V_2 ,
T_6 V_22 ,
T_6 V_23 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_8 V_26 ;
T_8 V_115 ;
T_9 V_28 ;
int V_31 ;
T_10 * V_34 ;
T_5 V_13 ;
T_11 V_35 ;
T_14 V_116 ;
T_12 V_37 ;
int V_39 ;
int error ;
F_60 ( V_2 , V_22 , V_23 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = F_13 ( V_1 , ( V_40 ) V_22 + V_23 ) ;
V_26 = ( T_8 ) ( V_26 - V_25 ) ;
V_37 = F_17 ( V_1 , 0 ) << 1 ;
do {
F_61 ( V_1 -> V_63 ) ;
V_34 = F_62 ( V_1 , V_108 , V_117 ) ;
V_34 -> V_109 |= V_110 | V_118 ;
error = F_19 ( V_34 , & F_20 ( V_1 ) -> V_47 ,
V_37 , 0 ) ;
if ( error ) {
F_21 ( V_34 , 0 ) ;
return error ;
}
F_22 ( V_2 , V_48 ) ;
F_24 ( V_34 , V_2 , 0 ) ;
F_25 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_26 ( V_34 , V_2 , V_25 , V_26 ,
V_119 , & V_28 ,
1 , & V_13 , & V_31 , & V_35 ) ;
if ( error )
goto V_120;
V_116 = F_4 ( V_1 , V_25 + V_26 ) ;
if ( V_116 > V_22 + V_23 )
V_116 = V_22 + V_23 ;
V_116 = F_63 ( V_2 , V_116 ) ;
if ( V_116 ) {
V_2 -> V_121 . V_122 = V_116 ;
F_64 ( V_34 , V_2 , V_123 ) ;
}
error = F_27 ( & V_34 , & V_35 , & V_39 ) ;
if ( error )
goto V_120;
error = F_28 ( V_34 , V_52 ) ;
F_29 ( V_2 , V_48 ) ;
if ( error )
return error ;
if ( ! ( V_13 . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 ) ;
if ( ( V_115 = V_13 . V_19 ) == 0 ) {
ASSERT ( V_13 . V_19 ) ;
break;
}
V_25 += V_115 ;
V_26 -= V_115 ;
} while ( V_26 > 0 );
return 0 ;
V_120:
F_30 ( & V_35 ) ;
F_21 ( V_34 , ( V_52 | V_55 ) ) ;
F_29 ( V_2 , V_48 ) ;
return error ;
}
