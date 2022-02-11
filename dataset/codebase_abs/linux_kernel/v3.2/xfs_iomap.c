STATIC int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
T_4 * V_4 )
{
T_4 V_5 = 0 ;
T_3 V_6 ;
int V_7 , error ;
if ( F_2 ( V_2 ) )
;
else if ( V_1 -> V_8 && ( V_1 -> V_9 & V_10 ) &&
( V_2 -> V_11 >= F_3 ( V_1 , V_1 -> V_8 ) ) )
V_5 = F_4 ( * V_4 , V_1 -> V_8 ) ;
else if ( V_1 -> V_12 && ( V_2 -> V_11 >= F_3 ( V_1 , V_1 -> V_12 ) ) )
V_5 = F_4 ( * V_4 , V_1 -> V_12 ) ;
if ( V_3 ) {
if ( V_5 )
V_6 = F_4 ( V_5 , V_3 ) ;
else
V_6 = V_3 ;
V_5 = F_4 ( * V_4 , V_6 ) ;
}
if ( V_5 ) {
error = F_5 ( V_2 , V_5 , V_13 , & V_7 ) ;
if ( error )
return error ;
if ( V_7 )
* V_4 = V_5 ;
}
return 0 ;
}
STATIC int
F_6 (
T_2 * V_2 ,
T_5 * V_14 )
{
F_7 ( V_2 -> V_15 , V_16 ,
L_1
L_2
L_3 ,
( unsigned long long ) V_2 -> V_17 ,
( unsigned long long ) V_14 -> V_18 ,
( unsigned long long ) V_14 -> V_19 ,
( unsigned long long ) V_14 -> V_20 ,
V_14 -> V_21 ) ;
return V_22 ;
}
int
F_8 (
T_2 * V_2 ,
T_6 V_23 ,
T_7 V_24 ,
T_5 * V_14 ,
int V_25 )
{
T_1 * V_1 = V_2 -> V_15 ;
T_4 V_26 ;
T_4 V_4 ;
T_8 V_27 , V_28 ;
T_9 V_29 ;
T_3 V_30 , V_31 ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
T_10 * V_36 ;
T_11 V_37 ;
T_12 V_38 , V_39 , V_40 ;
int V_41 ;
int error ;
error = F_9 ( V_2 , 0 ) ;
if ( error )
return F_10 ( error ) ;
V_35 = F_2 ( V_2 ) ;
V_30 = F_11 ( V_2 ) ;
V_26 = F_12 ( V_1 , V_23 ) ;
V_4 = F_13 ( V_1 , ( ( V_42 ) ( V_23 + V_24 ) ) ) ;
if ( ( V_23 + V_24 ) > V_2 -> V_11 ) {
error = F_1 ( V_1 , V_2 , V_30 , & V_4 ) ;
if ( error )
goto V_43;
} else {
if ( V_25 && ( V_14 -> V_18 == V_44 ) )
V_4 = F_14 ( V_4 , ( T_4 )
V_14 -> V_20 +
V_14 -> V_19 ) ;
}
V_27 = V_4 - V_26 ;
ASSERT ( V_27 > 0 ) ;
V_28 = V_27 ;
if ( F_15 ( V_30 ) ) {
if ( ( V_31 = F_16 ( V_26 , V_30 ) ) )
V_28 += V_31 ;
if ( ( V_31 = F_16 ( V_28 , V_30 ) ) )
V_28 += V_30 - V_31 ;
}
if ( F_15 ( V_35 ) ) {
V_40 = V_38 = V_28 ;
V_40 /= V_1 -> V_45 . V_46 ;
V_39 = F_17 ( V_1 , 0 ) ;
V_34 = V_47 ;
} else {
V_40 = 0 ;
V_39 = V_38 = F_17 ( V_1 , V_28 ) ;
V_34 = V_48 ;
}
F_18 ( V_2 , V_49 ) ;
V_36 = F_19 ( V_1 , V_50 ) ;
error = F_20 ( V_36 , V_39 ,
F_21 ( V_1 ) , V_40 ,
V_51 ,
V_52 ) ;
if ( error )
F_22 ( V_36 , 0 ) ;
F_23 ( V_2 , V_49 ) ;
if ( error )
goto V_43;
error = F_24 ( V_36 , V_2 , V_38 , 0 , V_34 ) ;
if ( error )
goto V_53;
F_25 ( V_36 , V_2 , 0 ) ;
V_33 = 0 ;
if ( V_23 < V_2 -> V_11 || V_30 )
V_33 |= V_54 ;
F_26 ( & V_37 , & V_29 ) ;
V_32 = 1 ;
error = F_27 ( V_36 , V_2 , V_26 , V_27 , V_33 ,
& V_29 , 0 , V_14 , & V_32 , & V_37 ) ;
if ( error )
goto V_55;
error = F_28 ( & V_36 , & V_37 , & V_41 ) ;
if ( error )
goto V_55;
error = F_29 ( V_36 , V_56 ) ;
if ( error )
goto V_43;
if ( V_32 == 0 ) {
error = V_57 ;
goto V_43;
}
if ( ! ( V_14 -> V_18 || F_2 ( V_2 ) ) ) {
error = F_6 ( V_2 , V_14 ) ;
goto V_43;
}
return 0 ;
V_55:
F_30 ( & V_37 ) ;
F_31 ( V_36 , V_2 , V_38 , 0 , V_34 ) ;
V_53:
F_22 ( V_36 , V_56 | V_58 ) ;
V_43:
return F_10 ( error ) ;
}
STATIC int
F_32 (
T_1 * V_1 ,
T_2 * V_2 ,
T_6 V_23 ,
T_7 V_24 ,
T_5 * V_14 ,
int V_32 ,
int * V_59 )
{
T_4 V_60 ;
T_8 V_27 ;
T_9 V_61 ;
int V_62 , error , V_63 ;
int V_64 = 0 ;
* V_59 = 0 ;
if ( ( V_23 + V_24 ) <= V_2 -> V_11 )
return 0 ;
V_60 = F_12 ( V_1 , ( ( V_42 ) ( V_23 + V_24 - 1 ) ) ) ;
V_27 = F_13 ( V_1 , ( V_42 ) F_33 ( V_1 ) ) ;
while ( V_27 > 0 ) {
V_63 = V_32 ;
V_61 = V_65 ;
error = F_34 ( V_2 , V_60 , V_27 , V_14 , & V_63 ,
0 ) ;
if ( error )
return error ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
if ( ( V_14 [ V_62 ] . V_18 != V_44 ) &&
( V_14 [ V_62 ] . V_18 != V_66 ) )
return 0 ;
V_60 += V_14 [ V_62 ] . V_20 ;
V_27 -= V_14 [ V_62 ] . V_20 ;
if ( V_14 [ V_62 ] . V_18 == V_66 )
V_64 = 1 ;
}
}
if ( ! V_64 )
* V_59 = 1 ;
return 0 ;
}
STATIC T_9
F_35 (
struct V_67 * V_1 ,
struct V_68 * V_2 )
{
T_9 V_69 = 0 ;
if ( ! ( V_1 -> V_9 & V_70 ) ) {
int V_71 = 0 ;
T_13 V_72 ;
V_69 = F_13 ( V_1 , V_2 -> V_11 ) + 1 ;
V_69 = F_36 ( V_73 ,
F_37 ( V_69 ) ) ;
F_38 ( V_1 , V_74 ) ;
V_72 = V_1 -> V_45 . V_75 ;
if ( V_72 < V_1 -> V_76 [ V_77 ] ) {
V_71 = 2 ;
if ( V_72 < V_1 -> V_76 [ V_78 ] )
V_71 ++ ;
if ( V_72 < V_1 -> V_76 [ V_79 ] )
V_71 ++ ;
if ( V_72 < V_1 -> V_76 [ V_80 ] )
V_71 ++ ;
if ( V_72 < V_1 -> V_76 [ V_81 ] )
V_71 ++ ;
}
if ( V_71 )
V_69 >>= V_71 ;
}
if ( V_69 < V_1 -> V_82 )
V_69 = V_1 -> V_82 ;
return V_69 ;
}
int
F_39 (
T_2 * V_2 ,
T_6 V_23 ,
T_7 V_24 ,
T_5 * V_83 )
{
T_1 * V_1 = V_2 -> V_15 ;
T_4 V_26 ;
T_4 V_4 ;
T_6 V_84 ;
T_4 V_85 ;
T_3 V_30 ;
int V_32 ;
T_5 V_14 [ V_86 ] ;
int V_59 , V_87 = 0 ;
int error ;
ASSERT ( F_40 ( V_2 , V_49 ) ) ;
error = F_9 ( V_2 , 0 ) ;
if ( error )
return F_10 ( error ) ;
V_30 = F_11 ( V_2 ) ;
V_26 = F_12 ( V_1 , V_23 ) ;
error = F_32 ( V_1 , V_2 , V_23 , V_24 ,
V_14 , V_86 , & V_59 ) ;
if ( error )
return error ;
V_88:
if ( V_59 ) {
T_9 V_69 = F_35 ( V_1 , V_2 ) ;
V_84 = F_41 ( V_1 , ( V_23 + V_24 - 1 ) ) ;
V_85 = F_12 ( V_1 , V_84 ) ;
V_4 = V_85 + V_69 ;
} else {
V_4 = F_13 ( V_1 , ( ( V_42 ) ( V_23 + V_24 ) ) ) ;
}
if ( V_59 || V_30 ) {
error = F_1 ( V_1 , V_2 , V_30 , & V_4 ) ;
if ( error )
return error ;
}
V_32 = V_86 ;
error = F_42 ( V_2 , V_26 , V_4 - V_26 ,
V_14 , & V_32 , V_89 ) ;
switch ( error ) {
case 0 :
case V_57 :
case V_90 :
break;
default:
return F_10 ( error ) ;
}
if ( V_32 == 0 ) {
F_43 ( V_2 , V_23 , V_24 ) ;
if ( V_87 )
return F_10 ( error ? error : V_57 ) ;
if ( error == V_57 ) {
F_18 ( V_2 , V_49 ) ;
F_44 ( V_2 ) ;
F_23 ( V_2 , V_49 ) ;
}
V_87 = 1 ;
error = 0 ;
V_59 = 0 ;
goto V_88;
}
if ( ! ( V_14 [ 0 ] . V_18 || F_2 ( V_2 ) ) )
return F_6 ( V_2 , & V_14 [ 0 ] ) ;
* V_83 = V_14 [ 0 ] ;
return 0 ;
}
int
F_45 (
T_2 * V_2 ,
T_6 V_23 ,
T_7 V_24 ,
T_5 * V_14 )
{
T_1 * V_1 = V_2 -> V_15 ;
T_4 V_26 , V_91 ;
T_4 V_92 , V_93 ;
T_9 V_94 ;
T_11 V_37 ;
T_8 V_27 ;
T_10 * V_36 ;
int V_32 , V_41 ;
int error = 0 ;
int V_95 ;
error = F_46 ( V_2 , 0 ) ;
if ( error )
return F_10 ( error ) ;
V_26 = F_12 ( V_1 , V_23 ) ;
V_27 = V_14 -> V_20 ;
V_93 = V_14 -> V_19 ;
F_47 ( V_96 , F_3 ( V_1 , V_27 ) ) ;
while ( V_27 != 0 ) {
V_32 = 0 ;
while ( V_32 == 0 ) {
V_36 = F_19 ( V_1 , V_97 ) ;
V_36 -> V_98 |= V_99 ;
V_95 = F_48 ( V_1 , V_13 ) ;
error = F_20 ( V_36 , V_95 ,
F_21 ( V_1 ) ,
0 , V_51 ,
V_52 ) ;
if ( error ) {
F_22 ( V_36 , 0 ) ;
return F_10 ( error ) ;
}
F_23 ( V_2 , V_49 ) ;
F_25 ( V_36 , V_2 , 0 ) ;
F_26 ( & V_37 , & V_94 ) ;
V_32 = 1 ;
V_92 = F_13 ( V_1 , V_2 -> V_11 ) ;
error = F_49 ( NULL , V_2 , & V_91 ,
V_13 ) ;
if ( error )
goto V_100;
V_91 = F_50 ( V_91 , V_92 ) ;
if ( ( V_93 + V_27 ) > V_91 ) {
V_27 = V_91 - V_93 ;
if ( V_27 == 0 ) {
error = V_101 ;
goto V_100;
}
}
error = F_27 ( V_36 , V_2 , V_93 ,
V_27 , 0 , & V_94 , 1 ,
V_14 , & V_32 , & V_37 ) ;
if ( error )
goto V_100;
error = F_28 ( & V_36 , & V_37 , & V_41 ) ;
if ( error )
goto V_100;
error = F_29 ( V_36 , V_56 ) ;
if ( error )
goto V_55;
F_18 ( V_2 , V_49 ) ;
}
if ( ! ( V_14 -> V_18 || F_2 ( V_2 ) ) )
return F_6 ( V_2 , V_14 ) ;
if ( ( V_26 >= V_14 -> V_19 ) &&
( V_26 < ( V_14 -> V_19 +
V_14 -> V_20 ) ) ) {
F_51 ( V_102 ) ;
return 0 ;
}
V_27 -= V_14 -> V_20 ;
V_93 = V_14 -> V_19 + V_14 -> V_20 ;
}
V_100:
F_30 ( & V_37 ) ;
F_22 ( V_36 , V_56 | V_58 ) ;
V_55:
F_18 ( V_2 , V_49 ) ;
return F_10 ( error ) ;
}
int
F_52 (
T_2 * V_2 ,
T_6 V_23 ,
T_7 V_24 )
{
T_1 * V_1 = V_2 -> V_15 ;
T_4 V_26 ;
T_8 V_27 ;
T_8 V_103 ;
T_9 V_29 ;
int V_32 ;
T_10 * V_36 ;
T_5 V_14 ;
T_11 V_37 ;
T_12 V_39 ;
int V_41 ;
int error ;
F_53 ( V_2 , V_23 , V_24 ) ;
V_26 = F_12 ( V_1 , V_23 ) ;
V_27 = F_13 ( V_1 , ( V_42 ) V_23 + V_24 ) ;
V_27 = ( T_8 ) ( V_27 - V_26 ) ;
V_39 = F_17 ( V_1 , 0 ) << 1 ;
do {
F_54 ( V_1 , V_104 ) ;
V_36 = F_55 ( V_1 , V_97 , V_105 ) ;
V_36 -> V_98 |= V_99 ;
error = F_20 ( V_36 , V_39 ,
F_21 ( V_1 ) , 0 ,
V_51 ,
V_52 ) ;
if ( error ) {
F_22 ( V_36 , 0 ) ;
return F_10 ( error ) ;
}
F_23 ( V_2 , V_49 ) ;
F_25 ( V_36 , V_2 , 0 ) ;
F_26 ( & V_37 , & V_29 ) ;
V_32 = 1 ;
error = F_27 ( V_36 , V_2 , V_26 , V_27 ,
V_106 , & V_29 ,
1 , & V_14 , & V_32 , & V_37 ) ;
if ( error )
goto V_107;
error = F_28 ( & ( V_36 ) , & ( V_37 ) , & V_41 ) ;
if ( error )
goto V_107;
error = F_29 ( V_36 , V_56 ) ;
F_18 ( V_2 , V_49 ) ;
if ( error )
return F_10 ( error ) ;
if ( ! ( V_14 . V_18 || F_2 ( V_2 ) ) )
return F_6 ( V_2 , & V_14 ) ;
if ( ( V_103 = V_14 . V_20 ) == 0 ) {
ASSERT ( V_14 . V_20 ) ;
break;
}
V_26 += V_103 ;
V_27 -= V_103 ;
} while ( V_27 > 0 );
return 0 ;
V_107:
F_30 ( & V_37 ) ;
F_22 ( V_36 , ( V_56 | V_58 ) ) ;
F_18 ( V_2 , V_49 ) ;
return F_10 ( error ) ;
}
