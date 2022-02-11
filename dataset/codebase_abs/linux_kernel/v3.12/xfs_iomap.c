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
error = F_20 ( V_35 , & F_21 ( V_1 ) -> V_48 ,
V_38 , V_39 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_49 ) ;
error = F_24 ( V_35 , V_2 , V_37 , 0 , V_33 ) ;
if ( error )
goto V_50;
F_25 ( V_35 , V_2 , 0 ) ;
V_32 = 0 ;
if ( V_22 < F_3 ( V_2 ) || V_29 )
V_32 |= V_51 ;
F_26 ( & V_36 , & V_28 ) ;
V_31 = 1 ;
error = F_27 ( V_35 , V_2 , V_25 , V_26 , V_32 ,
& V_28 , 0 , V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_52;
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_52;
error = F_29 ( V_35 , V_53 ) ;
if ( error )
goto V_54;
if ( V_31 == 0 ) {
error = F_11 ( V_55 ) ;
goto V_54;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
error = F_7 ( V_2 , V_13 ) ;
V_54:
F_30 ( V_2 , V_49 ) ;
return error ;
V_52:
F_31 ( & V_36 ) ;
F_32 ( V_35 , V_2 , ( long ) V_37 , 0 , V_33 ) ;
V_50:
F_22 ( V_35 , V_53 | V_56 ) ;
goto V_54;
}
STATIC int
F_33 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 ,
int V_31 ,
int * V_57 )
{
T_4 V_58 ;
T_8 V_26 ;
T_9 V_59 ;
int V_60 , error , V_61 ;
int V_62 = 0 ;
* V_57 = 0 ;
if ( V_22 + V_23 <= F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_1 -> V_9 & V_63 ) &&
F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_64 ) )
return 0 ;
V_58 = F_13 ( V_1 , ( ( V_41 ) ( V_22 + V_23 - 1 ) ) ) ;
V_26 = F_14 ( V_1 , V_1 -> V_65 -> V_66 ) ;
while ( V_26 > 0 ) {
V_61 = V_31 ;
V_59 = V_67 ;
error = F_34 ( V_2 , V_58 , V_26 , V_13 , & V_61 ,
0 ) ;
if ( error )
return error ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( ( V_13 [ V_60 ] . V_17 != V_42 ) &&
( V_13 [ V_60 ] . V_17 != V_68 ) )
return 0 ;
V_58 += V_13 [ V_60 ] . V_19 ;
V_26 -= V_13 [ V_60 ] . V_19 ;
if ( V_13 [ V_60 ] . V_17 == V_68 )
V_62 = 1 ;
}
}
if ( ! V_62 )
* V_57 = 1 ;
return 0 ;
}
STATIC T_9
F_35 (
struct V_69 * V_1 ,
struct V_70 * V_2 ,
T_6 V_22 ,
T_5 * V_13 ,
int V_31 )
{
T_4 V_58 ;
int V_61 = 1 ;
int error ;
ASSERT ( V_31 >= V_61 ) ;
if ( V_1 -> V_9 & V_63 )
return 0 ;
if ( F_3 ( V_2 ) < F_4 ( V_1 , V_1 -> V_11 ) )
return 0 ;
V_58 = F_14 ( V_1 , V_22 ) ;
if ( V_58 )
V_58 -- ;
error = F_34 ( V_2 , V_58 , 1 , V_13 , & V_61 , V_71 ) ;
if ( error )
return 0 ;
ASSERT ( V_61 == 1 ) ;
if ( V_13 [ 0 ] . V_17 == V_42 )
return 0 ;
if ( V_13 [ 0 ] . V_19 <= ( V_72 >> 1 ) )
return V_13 [ 0 ] . V_19 << 1 ;
return F_14 ( V_1 , V_22 ) ;
}
STATIC bool
F_36 (
struct V_70 * V_2 ,
int type ,
T_9 V_73 )
{
struct V_74 * V_75 = F_37 ( V_2 , type ) ;
if ( ! V_75 || ! F_38 ( V_2 -> V_14 , type ) )
return false ;
if ( ! V_75 -> V_76 )
return false ;
if ( V_75 -> V_77 + V_73 < V_75 -> V_78 )
return false ;
return true ;
}
STATIC void
F_39 (
struct V_70 * V_2 ,
int type ,
T_9 * V_37 ,
int * V_79 )
{
T_13 V_80 ;
int V_81 = 0 ;
struct V_74 * V_75 = F_37 ( V_2 , type ) ;
if ( V_75 -> V_77 >= V_75 -> V_76 ) {
* V_37 = 0 ;
return;
}
V_80 = V_75 -> V_76 - V_75 -> V_77 ;
if ( V_80 < V_75 -> V_82 [ V_83 ] ) {
V_81 = 2 ;
if ( V_80 < V_75 -> V_82 [ V_84 ] )
V_81 += 2 ;
if ( V_80 < V_75 -> V_82 [ V_85 ] )
V_81 += 2 ;
}
if ( ( V_80 >> V_81 ) < ( * V_37 >> * V_79 ) ) {
* V_37 = V_80 ;
* V_79 = V_81 ;
}
}
STATIC T_9
F_40 (
struct V_69 * V_1 ,
struct V_70 * V_2 ,
T_6 V_22 ,
struct V_86 * V_13 ,
int V_31 )
{
T_9 V_73 = 0 ;
int V_81 = 0 ;
T_13 V_80 ;
T_9 V_37 ;
int V_79 = 0 ;
V_73 = F_35 ( V_1 , V_2 , V_22 ,
V_13 , V_31 ) ;
if ( ! V_73 )
goto V_87;
V_37 = V_73 ;
V_73 = F_41 ( F_42 ( V_72 ) ,
V_73 ) ;
F_43 ( V_1 , V_88 ) ;
V_80 = V_1 -> V_43 . V_89 ;
if ( V_80 < V_1 -> V_90 [ V_91 ] ) {
V_81 = 2 ;
if ( V_80 < V_1 -> V_90 [ V_92 ] )
V_81 ++ ;
if ( V_80 < V_1 -> V_90 [ V_93 ] )
V_81 ++ ;
if ( V_80 < V_1 -> V_90 [ V_94 ] )
V_81 ++ ;
if ( V_80 < V_1 -> V_90 [ V_95 ] )
V_81 ++ ;
}
if ( F_36 ( V_2 , V_96 , V_73 ) )
F_39 ( V_2 , V_96 , & V_37 , & V_79 ) ;
if ( F_36 ( V_2 , V_97 , V_73 ) )
F_39 ( V_2 , V_97 , & V_37 , & V_79 ) ;
if ( F_36 ( V_2 , V_98 , V_73 ) )
F_39 ( V_2 , V_98 , & V_37 , & V_79 ) ;
V_73 = F_15 ( V_73 , V_37 ) ;
V_81 = F_44 ( V_81 , V_79 ) ;
if ( V_81 )
V_73 >>= V_81 ;
if ( V_73 )
V_73 = F_45 ( V_73 ) ;
if ( V_73 > V_72 )
V_73 = V_72 ;
while ( V_73 && V_73 >= V_80 )
V_73 >>= 4 ;
V_87:
if ( V_73 < V_1 -> V_64 )
V_73 = V_1 -> V_64 ;
F_46 ( V_2 , V_73 , V_81 ,
V_1 -> V_64 ) ;
return V_73 ;
}
int
F_47 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_99 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_4 V_4 ;
T_6 V_100 ;
T_4 V_101 ;
T_3 V_29 ;
int V_31 ;
T_5 V_13 [ V_102 ] ;
int V_57 ;
int error ;
ASSERT ( F_48 ( V_2 , V_49 ) ) ;
error = F_49 ( V_2 , 0 ) ;
if ( error )
return F_11 ( error ) ;
V_29 = F_12 ( V_2 ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
error = F_33 ( V_1 , V_2 , V_22 , V_23 ,
V_13 , V_102 , & V_57 ) ;
if ( error )
return error ;
V_103:
if ( V_57 ) {
T_9 V_73 ;
V_73 = F_40 ( V_1 , V_2 , V_22 , V_13 ,
V_102 ) ;
V_100 = F_50 ( V_1 , ( V_22 + V_23 - 1 ) ) ;
V_101 = F_13 ( V_1 , V_100 ) ;
V_4 = V_101 + V_73 ;
} else {
V_4 = F_14 ( V_1 , ( ( V_41 ) ( V_22 + V_23 ) ) ) ;
}
if ( V_57 || V_29 ) {
error = F_1 ( V_1 , V_2 , V_29 , & V_4 ) ;
if ( error )
return error ;
}
if ( V_4 > F_14 ( V_1 , V_1 -> V_65 -> V_66 ) )
V_4 = F_14 ( V_1 , V_1 -> V_65 -> V_66 ) ;
ASSERT ( V_4 > V_25 ) ;
V_31 = V_102 ;
error = F_51 ( V_2 , V_25 , V_4 - V_25 ,
V_13 , & V_31 , V_71 ) ;
switch ( error ) {
case 0 :
case V_55 :
case V_104 :
break;
default:
return F_11 ( error ) ;
}
if ( V_31 == 0 ) {
F_52 ( V_2 , V_22 , V_23 ) ;
if ( V_57 ) {
V_57 = 0 ;
error = 0 ;
goto V_103;
}
return F_11 ( error ? error : V_55 ) ;
}
if ( ! ( V_13 [ 0 ] . V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , & V_13 [ 0 ] ) ;
if ( V_57 )
F_53 ( V_2 ) ;
* V_99 = V_13 [ 0 ] ;
return 0 ;
}
int
F_54 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 ,
T_5 * V_13 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 , V_105 ;
T_4 V_106 , V_107 ;
T_9 V_108 ;
T_11 V_36 ;
T_8 V_26 ;
T_10 * V_35 ;
int V_31 , V_40 ;
int error = 0 ;
int V_109 ;
error = F_10 ( V_2 , 0 ) ;
if ( error )
return F_11 ( error ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
V_26 = V_13 -> V_19 ;
V_107 = V_13 -> V_18 ;
F_55 ( V_110 , F_4 ( V_1 , V_26 ) ) ;
while ( V_26 != 0 ) {
V_31 = 0 ;
while ( V_31 == 0 ) {
V_35 = F_19 ( V_1 , V_111 ) ;
V_35 -> V_112 |= V_113 ;
V_109 = F_56 ( V_1 , V_12 ) ;
error = F_20 ( V_35 , & F_21 ( V_1 ) -> V_48 ,
V_109 , 0 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_49 ) ;
F_25 ( V_35 , V_2 , 0 ) ;
F_26 ( & V_36 , & V_108 ) ;
V_31 = 1 ;
V_106 = F_14 ( V_1 , F_3 ( V_2 ) ) ;
error = F_57 ( NULL , V_2 , & V_105 ,
V_12 ) ;
if ( error )
goto V_114;
V_105 = F_58 ( V_105 , V_106 ) ;
if ( ( V_107 + V_26 ) > V_105 ) {
V_26 = V_105 - V_107 ;
if ( V_26 == 0 ) {
error = V_115 ;
goto V_114;
}
}
error = F_27 ( V_35 , V_2 , V_107 ,
V_26 ,
V_116 ,
& V_108 , 1 ,
V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_114;
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_114;
error = F_29 ( V_35 , V_53 ) ;
if ( error )
goto V_117;
F_30 ( V_2 , V_49 ) ;
}
if ( ! ( V_13 -> V_17 || F_2 ( V_2 ) ) )
return F_7 ( V_2 , V_13 ) ;
if ( ( V_25 >= V_13 -> V_18 ) &&
( V_25 < ( V_13 -> V_18 +
V_13 -> V_19 ) ) ) {
F_59 ( V_118 ) ;
return 0 ;
}
V_26 -= V_13 -> V_19 ;
V_107 = V_13 -> V_18 + V_13 -> V_19 ;
}
V_114:
F_31 ( & V_36 ) ;
F_22 ( V_35 , V_53 | V_56 ) ;
V_117:
F_30 ( V_2 , V_49 ) ;
return F_11 ( error ) ;
}
int
F_60 (
T_2 * V_2 ,
T_6 V_22 ,
T_7 V_23 )
{
T_1 * V_1 = V_2 -> V_14 ;
T_4 V_25 ;
T_8 V_26 ;
T_8 V_119 ;
T_9 V_28 ;
int V_31 ;
T_10 * V_35 ;
T_5 V_13 ;
T_11 V_36 ;
T_14 V_120 ;
T_12 V_38 ;
int V_40 ;
int error ;
F_61 ( V_2 , V_22 , V_23 ) ;
V_25 = F_13 ( V_1 , V_22 ) ;
V_26 = F_14 ( V_1 , ( V_41 ) V_22 + V_23 ) ;
V_26 = ( T_8 ) ( V_26 - V_25 ) ;
V_38 = F_18 ( V_1 , 0 ) << 1 ;
do {
F_62 ( V_1 -> V_65 ) ;
V_35 = F_63 ( V_1 , V_111 , V_121 ) ;
V_35 -> V_112 |= V_113 | V_122 ;
error = F_20 ( V_35 , & F_21 ( V_1 ) -> V_48 ,
V_38 , 0 ) ;
if ( error ) {
F_22 ( V_35 , 0 ) ;
return F_11 ( error ) ;
}
F_23 ( V_2 , V_49 ) ;
F_25 ( V_35 , V_2 , 0 ) ;
F_26 ( & V_36 , & V_28 ) ;
V_31 = 1 ;
error = F_27 ( V_35 , V_2 , V_25 , V_26 ,
V_123 , & V_28 ,
1 , & V_13 , & V_31 , & V_36 ) ;
if ( error )
goto V_124;
V_120 = F_4 ( V_1 , V_25 + V_26 ) ;
if ( V_120 > V_22 + V_23 )
V_120 = V_22 + V_23 ;
V_120 = F_64 ( V_2 , V_120 ) ;
if ( V_120 ) {
V_2 -> V_125 . V_126 = V_120 ;
F_65 ( V_35 , V_2 , V_127 ) ;
}
error = F_28 ( & V_35 , & V_36 , & V_40 ) ;
if ( error )
goto V_124;
error = F_29 ( V_35 , V_53 ) ;
F_30 ( V_2 , V_49 ) ;
if ( error )
return F_11 ( error ) ;
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
V_124:
F_31 ( & V_36 ) ;
F_22 ( V_35 , ( V_53 | V_56 ) ) ;
F_30 ( V_2 , V_49 ) ;
return F_11 ( error ) ;
}
