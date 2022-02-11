STATIC int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
T_4 * V_4 )
{
T_4 V_5 = 0 ;
T_3 V_6 = 0 ;
int V_7 , error ;
if ( ! F_2 ( V_2 ) ) {
if ( V_1 -> V_8 && ( V_1 -> V_9 & V_10 ) )
V_6 = V_1 -> V_8 ;
else if ( V_1 -> V_11 )
V_6 = V_1 -> V_11 ;
if ( V_6 && F_3 ( V_2 ) >= F_4 ( V_1 , V_6 ) )
V_5 = F_5 ( * V_4 , V_6 ) ;
}
if ( V_3 ) {
if ( V_5 )
V_6 = F_5 ( V_5 , V_3 ) ;
else
V_6 = V_3 ;
V_5 = F_5 ( * V_4 , V_6 ) ;
}
if ( V_5 ) {
error = F_6 ( V_2 , V_5 , V_12 , & V_7 ) ;
if ( error )
return error ;
if ( V_7 )
* V_4 = V_5 ;
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
return V_21 ;
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
int V_34 ;
T_10 * V_35 ;
T_11 V_36 ;
T_12 V_37 , V_38 , V_39 ;
int V_40 ;
int error ;
error = F_10 ( V_2 , 0 ) ;
if ( error )
return F_11 ( error ) ;
V_34 = F_2 ( V_2 ) ;
V_29 = F_12 ( V_2 ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
V_4 = F_14 ( V_1 , ( ( V_41 ) ( V_22 + V_23 ) ) ) ;
if ( ( V_22 + V_23 ) > F_3 ( V_2 ) ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return F_11 ( error ) ;
} else {
if ( V_24 && ( V_13 -> V_17 == V_42 ) )
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
if ( F_16 ( V_34 ) ) {
V_39 = V_37 = V_27 ;
V_39 /= V_1 -> V_43 . V_44 ;
V_38 = F_18 ( V_1 , 0 ) ;
V_33 = V_45 ;
} else {
V_39 = 0 ;
V_38 = V_37 = F_18 ( V_1 , V_27 ) ;
V_33 = V_46 ;
}
V_35 = F_19 ( V_1 , V_47 ) ;
error = F_20 ( V_35 , V_38 ,
F_21 ( V_1 ) , V_39 ,
V_48 ,
V_49 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_50 ) ;
error = F_24 ( V_35 , V_2 , V_37 , 0 , V_33 ) ;
if ( error )
goto V_51;
F_25 ( V_35 , V_2 , 0 ) ;
V_32 = 0 ;
if ( V_22 < F_3 ( V_2 ) || V_29 )
V_32 |= V_52 ;
F_26 ( & V_36 , & V_28 ) ;
V_31 = 1 ;
error = F_27 ( V_35 , V_2 , V_25 , V_26 , V_32 ,
& V_28 , 0 , V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_53;
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_53;
error = F_29 ( V_35 , V_54 ) ;
if ( error )
goto V_55;
if ( V_31 == 0 ) {
error = F_11 ( V_56 ) ;
goto V_55;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
error = F_7 ( V_2 , V_13 ) ;
V_55:
F_30 ( V_2 , V_50 ) ;
return error ;
V_53:
F_31 ( & V_36 ) ;
F_32 ( V_35 , V_2 , ( long ) V_37 , 0 , V_33 ) ;
V_51:
F_22 ( V_35 , V_54 | V_57 ) ;
goto V_55;
}
STATIC int
F_33 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_31 ,
int * V_58 )
{
T_4 V_59 ;
T_8 V_26 ;
T_9 V_60 ;
int V_61 , error , V_62 ;
int V_63 = 0 ;
* V_58 = 0 ;
if ( V_22 + V_23 <= F_3 ( V_2 ) )
return 0 ;
V_59 = F_13 ( V_1 , ( ( V_41 ) ( V_22 + V_23 - 1 ) ) ) ;
V_26 = F_14 ( V_1 , V_1 -> V_64 -> V_65 ) ;
while ( V_26 > 0 ) {
V_62 = V_31 ;
V_60 = V_66 ;
error = F_34 ( V_2 , V_59 , V_26 , V_13 , & V_62 ,
0 ) ;
if ( error )
return error ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
if ( ( V_13 [ V_61 ] . V_17 != V_42 ) &&
( V_13 [ V_61 ] . V_17 != V_67 ) )
return 0 ;
V_59 += V_13 [ V_61 ] . V_19 ;
V_26 -= V_13 [ V_61 ] . V_19 ;
if ( V_13 [ V_61 ] . V_17 == V_67 )
V_63 = 1 ;
}
}
if ( ! V_63 )
* V_58 = 1 ;
return 0 ;
}
STATIC T_9
F_35 (
struct V_68 * V_1 ,
struct V_69 * V_2 )
{
T_9 V_70 = 0 ;
if ( ! ( V_1 -> V_9 & V_71 ) ) {
int V_72 = 0 ;
T_13 V_73 ;
V_70 = F_14 ( V_1 , F_3 ( V_2 ) ) + 1 ;
V_70 = F_36 ( V_74 ,
F_37 ( V_70 ) ) ;
F_38 ( V_1 , V_75 ) ;
V_73 = V_1 -> V_43 . V_76 ;
if ( V_73 < V_1 -> V_77 [ V_78 ] ) {
V_72 = 2 ;
if ( V_73 < V_1 -> V_77 [ V_79 ] )
V_72 ++ ;
if ( V_73 < V_1 -> V_77 [ V_80 ] )
V_72 ++ ;
if ( V_73 < V_1 -> V_77 [ V_81 ] )
V_72 ++ ;
if ( V_73 < V_1 -> V_77 [ V_82 ] )
V_72 ++ ;
}
if ( V_72 )
V_70 >>= V_72 ;
}
if ( V_70 < V_1 -> V_83 )
V_70 = V_1 -> V_83 ;
return V_70 ;
}
int
F_39 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_84 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_6 V_85 ;
T_4 V_86 ;
T_3 V_29 ;
int V_31 ;
T_5 V_13 [ V_87 ] ;
int V_58 , V_88 = 0 ;
int error ;
ASSERT ( F_40 ( V_2 , V_50 ) ) ;
error = F_41 ( V_2 , 0 ) ;
if ( error )
return F_11 ( error ) ;
V_29 = F_12 ( V_2 ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
error = F_33 ( V_1 , V_2 , V_22 , V_23 ,
V_13 , V_87 , & V_58 ) ;
if ( error )
return error ;
V_89:
if ( V_58 ) {
T_9 V_70 = F_35 ( V_1 , V_2 ) ;
V_85 = F_42 ( V_1 , ( V_22 + V_23 - 1 ) ) ;
V_86 = F_13 ( V_1 , V_85 ) ;
V_4 = V_86 + V_70 ;
} else {
V_4 = F_14 ( V_1 , ( ( V_41 ) ( V_22 + V_23 ) ) ) ;
}
if ( V_58 || V_29 ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
}
if ( V_4 > F_14 ( V_1 , V_1 -> V_64 -> V_65 ) )
V_4 = F_14 ( V_1 , V_1 -> V_64 -> V_65 ) ;
ASSERT ( V_4 > V_25 ) ;
V_31 = V_87 ;
error = F_43 ( V_2 , V_25 , V_4 - V_25 ,
V_13 , & V_31 , V_90 ) ;
switch ( error ) {
case 0 :
case V_56 :
case V_91 :
break;
default:
return F_11 ( error ) ;
}
if ( V_31 == 0 ) {
F_44 ( V_2 , V_22 , V_23 ) ;
if ( V_88 )
return F_11 ( error ? error : V_56 ) ;
if ( error == V_56 ) {
F_30 ( V_2 , V_50 ) ;
F_45 ( V_2 ) ;
F_23 ( V_2 , V_50 ) ;
}
V_88 = 1 ;
error = 0 ;
V_58 = 0 ;
goto V_89;
}
if ( ! ( V_13 [ 0 ] . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 [ 0 ] ) ;
* V_84 = V_13 [ 0 ] ;
return 0 ;
}
int
F_46 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 , V_92 ;
T_4 V_93 , V_94 ;
T_9 V_95 ;
T_11 V_36 ;
T_8 V_26 ;
T_10 * V_35 ;
int V_31 , V_40 ;
int error = 0 ;
int V_96 ;
error = F_10 ( V_2 , 0 ) ;
if ( error )
return F_11 ( error ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
V_26 = V_13 -> V_19 ;
V_94 = V_13 -> V_18 ;
F_47 ( V_97 , F_4 ( V_1 , V_26 ) ) ;
while ( V_26 != 0 ) {
V_31 = 0 ;
while ( V_31 == 0 ) {
V_35 = F_19 ( V_1 , V_98 ) ;
V_35 -> V_99 |= V_100 ;
V_96 = F_48 ( V_1 , V_12 ) ;
error = F_20 ( V_35 , V_96 ,
F_21 ( V_1 ) ,
0 , V_48 ,
V_49 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_50 ) ;
F_25 ( V_35 , V_2 , 0 ) ;
F_26 ( & V_36 , & V_95 ) ;
V_31 = 1 ;
V_93 = F_14 ( V_1 , F_3 ( V_2 ) ) ;
error = F_49 ( NULL , V_2 , & V_92 ,
V_12 ) ;
if ( error )
goto V_101;
V_92 = F_50 ( V_92 , V_93 ) ;
if ( ( V_94 + V_26 ) > V_92 ) {
V_26 = V_92 - V_94 ;
if ( V_26 == 0 ) {
error = V_102 ;
goto V_101;
}
}
error = F_27 ( V_35 , V_2 , V_94 ,
V_26 , 0 , & V_95 , 1 ,
V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_101;
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_101;
error = F_29 ( V_35 , V_54 ) ;
if ( error )
goto V_103;
F_30 ( V_2 , V_50 ) ;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , V_13 ) ;
if ( ( V_25 >= V_13 -> V_18 ) &&
( V_25 < ( V_13 -> V_18 +
V_13 -> V_19 ) ) ) {
F_51 ( V_104 ) ;
return 0 ;
}
V_26 -= V_13 -> V_19 ;
V_94 = V_13 -> V_18 + V_13 -> V_19 ;
}
V_101:
F_31 ( & V_36 ) ;
F_22 ( V_35 , V_54 | V_57 ) ;
V_103:
F_30 ( V_2 , V_50 ) ;
return F_11 ( error ) ;
}
int
F_52 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_8 V_26 ;
T_8 V_105 ;
T_9 V_28 ;
int V_31 ;
T_10 * V_35 ;
T_5 V_13 ;
T_11 V_36 ;
T_14 V_106 ;
T_12 V_38 ;
int V_40 ;
int error ;
F_53 ( V_2 , V_22 , V_23 ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
V_26 = F_14 ( V_1 , ( V_41 ) V_22 + V_23 ) ;
V_26 = ( T_8 ) ( V_26 - V_25 ) ;
V_38 = F_18 ( V_1 , 0 ) << 1 ;
do {
F_54 ( V_1 -> V_64 ) ;
V_35 = F_55 ( V_1 , V_98 , V_107 ) ;
V_35 -> V_99 |= V_100 | V_108 ;
error = F_20 ( V_35 , V_38 ,
F_21 ( V_1 ) , 0 ,
V_48 ,
V_49 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_50 ) ;
F_25 ( V_35 , V_2 , 0 ) ;
F_26 ( & V_36 , & V_28 ) ;
V_31 = 1 ;
error = F_27 ( V_35 , V_2 , V_25 , V_26 ,
V_109 , & V_28 ,
1 , & V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_110;
V_106 = F_4 ( V_1 , V_25 + V_26 ) ;
if ( V_106 > V_22 + V_23 )
V_106 = V_22 + V_23 ;
V_106 = F_56 ( V_2 , V_106 ) ;
if ( V_106 ) {
V_2 -> V_111 . V_112 = V_106 ;
F_57 ( V_35 , V_2 , V_113 ) ;
}
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_110;
error = F_29 ( V_35 , V_54 ) ;
F_30 ( V_2 , V_50 ) ;
if ( error )
return F_11 ( error ) ;
if ( ! ( V_13 . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 ) ;
if ( ( V_105 = V_13 . V_19 ) == 0 ) {
ASSERT ( V_13 . V_19 ) ;
break;
}
V_25 += V_105 ;
V_26 -= V_105 ;
} while ( V_26 > 0 );
return 0 ;
V_110:
F_31 ( & V_36 ) ;
F_22 ( V_35 , ( V_54 | V_57 ) ) ;
F_30 ( V_2 , V_50 ) ;
return F_11 ( error ) ;
}
