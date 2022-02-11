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
T_12 V_42 = 0 ;
V_33 = F_2 ( V_2 ) ;
V_29 = F_10 ( V_2 ) ;
V_39 = V_43 ;
ASSERT ( F_11 ( V_2 , V_39 ) ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_4 = F_13 ( V_1 , ( ( V_44 ) ( V_22 + V_23 ) ) ) ;
if ( ( V_22 + V_23 ) > F_3 ( V_2 ) ) {
ASSERT ( F_14 ( V_2 , V_12 ) -> V_45 &
V_46 ) ;
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
goto V_47;
} else {
if ( V_24 && ( V_13 -> V_17 == V_48 ) )
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
V_38 /= V_1 -> V_49 . V_50 ;
V_37 = F_18 ( V_1 , 0 ) ;
V_32 = V_51 ;
} else {
V_38 = 0 ;
V_37 = V_36 = F_18 ( V_1 , V_27 ) ;
V_32 = V_52 ;
}
F_19 ( V_2 , V_39 ) ;
error = F_20 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( F_21 ( F_22 ( V_2 ) ) ) {
V_40 = V_53 | V_54 ;
if ( F_23 ( V_13 ) ) {
V_42 |= V_55 ;
V_37 = F_18 ( V_1 , 0 ) << 1 ;
}
}
error = F_24 ( V_1 , & F_25 ( V_1 ) -> V_56 , V_37 , V_38 ,
V_42 , & V_34 ) ;
if ( error )
return error ;
V_39 = V_57 ;
F_26 ( V_2 , V_39 ) ;
error = F_27 ( V_34 , V_2 , V_36 , 0 , V_32 ) ;
if ( error )
goto V_58;
F_28 ( V_34 , V_2 , 0 ) ;
F_29 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_30 ( V_34 , V_2 , V_25 , V_26 ,
V_40 , & V_28 , V_37 , V_13 ,
& V_31 , & V_35 ) ;
if ( error )
goto V_59;
error = F_31 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_59;
error = F_32 ( V_34 ) ;
if ( error )
goto V_47;
if ( V_31 == 0 ) {
error = - V_60 ;
goto V_47;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
error = F_7 ( V_2 , V_13 ) ;
V_47:
F_19 ( V_2 , V_39 ) ;
return error ;
V_59:
F_33 ( & V_35 ) ;
F_34 ( V_34 , V_2 , ( long ) V_36 , 0 , V_32 ) ;
V_58:
F_35 ( V_34 ) ;
goto V_47;
}
STATIC int
F_36 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_31 ,
int * V_61 )
{
T_4 V_62 ;
T_8 V_26 ;
int V_63 , error , V_64 ;
int V_65 = 0 ;
* V_61 = 0 ;
if ( V_22 + V_23 <= F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_1 -> V_8 & V_66 ) &&
F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_67 ) )
return 0 ;
V_62 = F_12 ( V_1 , ( ( V_44 ) ( V_22 + V_23 - 1 ) ) ) ;
V_26 = F_13 ( V_1 , V_1 -> V_68 -> V_69 ) ;
while ( V_26 > 0 ) {
V_64 = V_31 ;
error = F_37 ( V_2 , V_62 , V_26 , V_13 , & V_64 ,
0 ) ;
if ( error )
return error ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( ( V_13 [ V_63 ] . V_17 != V_48 ) &&
( V_13 [ V_63 ] . V_17 != V_70 ) )
return 0 ;
V_62 += V_13 [ V_63 ] . V_19 ;
V_26 -= V_13 [ V_63 ] . V_19 ;
if ( V_13 [ V_63 ] . V_17 == V_70 )
V_65 = 1 ;
}
}
if ( ! V_65 )
* V_61 = 1 ;
return 0 ;
}
STATIC T_9
F_38 (
struct V_71 * V_1 ,
struct V_72 * V_2 ,
T_6 V_22 ,
T_5 * V_13 ,
int V_31 )
{
T_4 V_62 ;
int V_64 = 1 ;
int error ;
ASSERT ( V_31 >= V_64 ) ;
if ( V_1 -> V_8 & V_66 )
return 0 ;
if ( F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_10 ) )
return 0 ;
V_62 = F_13 ( V_1 , V_22 ) ;
if ( V_62 )
V_62 -- ;
error = F_37 ( V_2 , V_62 , 1 , V_13 , & V_64 , V_73 ) ;
if ( error )
return 0 ;
ASSERT ( V_64 == 1 ) ;
if ( V_13 [ 0 ] . V_17 == V_48 )
return 0 ;
if ( V_13 [ 0 ] . V_19 <= ( V_74 >> 1 ) )
return V_13 [ 0 ] . V_19 << 1 ;
return F_13 ( V_1 , V_22 ) ;
}
STATIC bool
F_39 (
struct V_72 * V_2 ,
int type ,
T_9 V_75 )
{
struct V_76 * V_77 = F_40 ( V_2 , type ) ;
if ( ! V_77 || ! F_41 ( V_2 -> V_14 , type ) )
return false ;
if ( ! V_77 -> V_78 )
return false ;
if ( V_77 -> V_79 + V_75 < V_77 -> V_80 )
return false ;
return true ;
}
STATIC void
F_42 (
struct V_72 * V_2 ,
int type ,
T_9 * V_36 ,
int * V_81 ,
T_13 * V_82 )
{
T_13 V_83 ;
int V_84 = 0 ;
struct V_76 * V_77 = F_40 ( V_2 , type ) ;
if ( ! V_77 || V_77 -> V_79 >= V_77 -> V_78 ) {
* V_36 = 0 ;
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
if ( ( V_83 >> V_84 ) < ( * V_36 >> * V_81 ) ) {
* V_36 = V_83 ;
* V_81 = V_84 ;
}
}
STATIC T_9
F_43 (
struct V_71 * V_1 ,
struct V_72 * V_2 ,
T_6 V_22 ,
struct V_89 * V_13 ,
int V_31 )
{
T_9 V_75 = 0 ;
int V_84 = 0 ;
T_13 V_83 ;
T_9 V_36 ;
int V_81 = 0 ;
V_75 = F_38 ( V_1 , V_2 , V_22 ,
V_13 , V_31 ) ;
if ( ! V_75 )
goto V_90;
V_36 = V_75 ;
V_75 = F_44 ( F_45 ( V_74 ) ,
V_75 ) ;
V_83 = F_46 ( & V_1 -> V_91 ) ;
if ( V_83 < V_1 -> V_92 [ V_93 ] ) {
V_84 = 2 ;
if ( V_83 < V_1 -> V_92 [ V_94 ] )
V_84 ++ ;
if ( V_83 < V_1 -> V_92 [ V_95 ] )
V_84 ++ ;
if ( V_83 < V_1 -> V_92 [ V_96 ] )
V_84 ++ ;
if ( V_83 < V_1 -> V_92 [ V_97 ] )
V_84 ++ ;
}
if ( F_39 ( V_2 , V_98 , V_75 ) )
F_42 ( V_2 , V_98 , & V_36 , & V_81 ,
& V_83 ) ;
if ( F_39 ( V_2 , V_99 , V_75 ) )
F_42 ( V_2 , V_99 , & V_36 , & V_81 ,
& V_83 ) ;
if ( F_39 ( V_2 , V_100 , V_75 ) )
F_42 ( V_2 , V_100 , & V_36 , & V_81 ,
& V_83 ) ;
V_75 = F_15 ( V_75 , V_36 ) ;
V_84 = F_47 ( V_84 , V_81 ) ;
if ( V_84 )
V_75 >>= V_84 ;
if ( V_75 )
V_75 = F_48 ( V_75 ) ;
if ( V_75 > V_74 )
V_75 = V_74 ;
while ( V_75 && V_75 >= V_83 )
V_75 >>= 4 ;
V_90:
if ( V_75 < V_1 -> V_67 )
V_75 = V_1 -> V_67 ;
F_49 ( V_2 , V_75 , V_84 ,
V_1 -> V_67 ) ;
return V_75 ;
}
int
F_50 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_101 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_6 V_102 ;
T_4 V_103 ;
T_3 V_29 ;
int V_31 ;
T_5 V_13 [ V_104 ] ;
int V_61 ;
int error ;
ASSERT ( F_11 ( V_2 , V_57 ) ) ;
error = F_51 ( V_2 , 0 ) ;
if ( error )
return error ;
V_29 = F_10 ( V_2 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
error = F_36 ( V_1 , V_2 , V_22 , V_23 ,
V_13 , V_104 , & V_61 ) ;
if ( error )
return error ;
V_105:
if ( V_61 ) {
T_9 V_75 ;
V_75 = F_43 ( V_1 , V_2 , V_22 , V_13 ,
V_104 ) ;
V_102 = F_52 ( V_1 , ( V_22 + V_23 - 1 ) ) ;
V_103 = F_12 ( V_1 , V_102 ) ;
V_4 = V_103 + V_75 ;
} else {
V_4 = F_13 ( V_1 , ( ( V_44 ) ( V_22 + V_23 ) ) ) ;
}
if ( V_61 || V_29 ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
}
if ( V_4 > F_13 ( V_1 , V_1 -> V_68 -> V_69 ) )
V_4 = F_13 ( V_1 , V_1 -> V_68 -> V_69 ) ;
ASSERT ( V_4 > V_25 ) ;
V_31 = V_104 ;
error = F_53 ( V_2 , V_25 , V_4 - V_25 ,
V_13 , & V_31 , V_73 ) ;
switch ( error ) {
case 0 :
case - V_60 :
case - V_106 :
break;
default:
return error ;
}
if ( V_31 == 0 ) {
F_54 ( V_2 , V_22 , V_23 ) ;
if ( V_61 ) {
V_61 = 0 ;
error = 0 ;
goto V_105;
}
return error ? error : - V_60 ;
}
if ( ! ( V_13 [ 0 ] . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 [ 0 ] ) ;
if ( V_61 )
F_55 ( V_2 ) ;
* V_101 = V_13 [ 0 ] ;
return 0 ;
}
int
F_56 (
T_2 * V_2 ,
T_6 V_22 ,
T_5 * V_13 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 , V_107 ;
T_4 V_108 , V_109 ;
T_9 V_110 ;
T_11 V_35 ;
T_8 V_26 ;
T_10 * V_34 ;
int V_31 ;
int error = 0 ;
int V_111 ;
error = F_20 ( V_2 , 0 ) ;
if ( error )
return error ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = V_13 -> V_19 ;
V_109 = V_13 -> V_18 ;
F_57 ( V_1 , V_112 , F_4 ( V_1 , V_26 ) ) ;
while ( V_26 != 0 ) {
V_31 = 0 ;
while ( V_31 == 0 ) {
V_111 = F_58 ( V_1 , V_12 ) ;
error = F_24 ( V_1 , & F_25 ( V_1 ) -> V_56 , V_111 ,
0 , V_55 , & V_34 ) ;
if ( error )
return error ;
F_26 ( V_2 , V_57 ) ;
F_28 ( V_34 , V_2 , 0 ) ;
F_29 ( & V_35 , & V_110 ) ;
V_31 = 1 ;
V_108 = F_13 ( V_1 , F_3 ( V_2 ) ) ;
error = F_59 ( V_2 , & V_107 ,
V_12 ) ;
if ( error )
goto V_113;
V_107 = F_60 ( V_107 , V_108 ) ;
if ( ( V_109 + V_26 ) > V_107 ) {
V_26 = V_107 - V_109 ;
if ( V_26 == 0 ) {
error = - V_114 ;
goto V_113;
}
}
error = F_30 ( V_34 , V_2 , V_109 ,
V_26 , 0 , & V_110 ,
V_111 , V_13 , & V_31 ,
& V_35 ) ;
if ( error )
goto V_113;
error = F_31 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_113;
error = F_32 ( V_34 ) ;
if ( error )
goto V_115;
F_19 ( V_2 , V_57 ) ;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , V_13 ) ;
if ( ( V_25 >= V_13 -> V_18 ) &&
( V_25 < ( V_13 -> V_18 +
V_13 -> V_19 ) ) ) {
F_61 ( V_1 , V_116 ) ;
return 0 ;
}
V_26 -= V_13 -> V_19 ;
V_109 = V_13 -> V_18 + V_13 -> V_19 ;
}
V_113:
F_33 ( & V_35 ) ;
F_35 ( V_34 ) ;
V_115:
F_19 ( V_2 , V_57 ) ;
return error ;
}
int
F_62 (
T_2 * V_2 ,
T_6 V_22 ,
T_6 V_23 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_8 V_26 ;
T_8 V_117 ;
T_9 V_28 ;
int V_31 ;
T_10 * V_34 ;
T_5 V_13 ;
T_11 V_35 ;
T_14 V_118 ;
T_12 V_37 ;
int error ;
F_63 ( V_2 , V_22 , V_23 ) ;
V_25 = F_12 ( V_1 , V_22 ) ;
V_26 = F_13 ( V_1 , ( V_44 ) V_22 + V_23 ) ;
V_26 = ( T_8 ) ( V_26 - V_25 ) ;
V_37 = F_18 ( V_1 , 0 ) << 1 ;
do {
error = F_24 ( V_1 , & F_25 ( V_1 ) -> V_56 , V_37 , 0 ,
V_55 | V_119 , & V_34 ) ;
if ( error )
return error ;
F_26 ( V_2 , V_57 ) ;
F_28 ( V_34 , V_2 , 0 ) ;
F_29 ( & V_35 , & V_28 ) ;
V_31 = 1 ;
error = F_30 ( V_34 , V_2 , V_25 , V_26 ,
V_53 , & V_28 , V_37 ,
& V_13 , & V_31 , & V_35 ) ;
if ( error )
goto V_120;
V_118 = F_4 ( V_1 , V_25 + V_26 ) ;
if ( V_118 > V_22 + V_23 )
V_118 = V_22 + V_23 ;
V_118 = F_64 ( V_2 , V_118 ) ;
if ( V_118 ) {
V_2 -> V_121 . V_122 = V_118 ;
F_65 ( V_34 , V_2 , V_123 ) ;
}
error = F_31 ( & V_34 , & V_35 , NULL ) ;
if ( error )
goto V_120;
error = F_32 ( V_34 ) ;
F_19 ( V_2 , V_57 ) ;
if ( error )
return error ;
if ( ! ( V_13 . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 ) ;
if ( ( V_117 = V_13 . V_19 ) == 0 ) {
ASSERT ( V_13 . V_19 ) ;
break;
}
V_25 += V_117 ;
V_26 -= V_117 ;
} while ( V_26 > 0 );
return 0 ;
V_120:
F_33 ( & V_35 ) ;
F_35 ( V_34 ) ;
F_19 ( V_2 , V_57 ) ;
return error ;
}
