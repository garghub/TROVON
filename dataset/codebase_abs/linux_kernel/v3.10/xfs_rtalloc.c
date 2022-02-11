STATIC int
F_1 (
T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 ,
T_3 * V_4 )
{
T_4 V_5 ;
T_5 * V_6 ;
int V_7 ;
T_6 V_8 ;
int error ;
T_7 V_9 ;
T_8 V_10 ;
T_7 V_11 ;
T_9 V_12 ;
int V_13 ;
int V_14 ;
while ( V_2 < V_3 ) {
int V_15 = 0 ;
T_10 * V_16 ;
V_16 = F_2 ( V_1 , V_17 ) ;
V_14 = F_3 ( V_1 , V_3 - V_2 ) ;
if ( ( error = F_4 ( V_16 , V_14 ,
F_5 ( V_1 ) , 0 ,
V_18 ,
V_19 ) ) )
goto V_20;
V_15 = V_21 ;
F_6 ( V_4 , V_22 ) ;
F_7 ( V_16 , V_4 , V_22 ) ;
F_8 ( & V_10 , & V_9 ) ;
V_13 = 1 ;
V_15 |= V_23 ;
error = F_9 ( V_16 , V_4 , V_2 , V_3 - V_2 ,
V_24 , & V_9 ,
V_14 , & V_12 , & V_13 , & V_10 ) ;
if ( ! error && V_13 < 1 )
error = F_10 ( V_25 ) ;
if ( error )
goto V_20;
error = F_11 ( & V_16 , & V_10 , & V_7 ) ;
if ( error )
goto V_20;
error = F_12 ( V_16 , V_21 ) ;
if ( error )
goto error;
V_15 = 0 ;
for ( V_5 = V_12 . V_26 , V_11 = V_12 . V_27 ;
V_5 < V_12 . V_26 + V_12 . V_28 ;
V_5 ++ , V_11 ++ ) {
V_16 = F_2 ( V_1 , V_29 ) ;
if ( ( error = F_4 ( V_16 , 0 ,
F_13 ( V_1 ) , 0 , 0 , 0 ) ) )
goto V_20;
F_6 ( V_4 , V_22 ) ;
F_7 ( V_16 , V_4 , V_22 ) ;
V_8 = F_14 ( V_1 , V_11 ) ;
V_6 = F_15 ( V_16 , V_1 -> V_30 , V_8 ,
V_1 -> V_31 , 0 ) ;
if ( V_6 == NULL ) {
error = F_10 ( V_32 ) ;
V_20:
F_16 ( V_16 , V_15 ) ;
goto error;
}
memset ( V_6 -> V_33 , 0 , V_1 -> V_34 . V_35 ) ;
F_17 ( V_16 , V_6 , 0 , V_1 -> V_34 . V_35 - 1 ) ;
error = F_12 ( V_16 , 0 ) ;
if ( error )
goto error;
}
V_2 = V_12 . V_26 + V_12 . V_28 ;
}
return 0 ;
error:
return error ;
}
STATIC int
F_18 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_36 ,
T_2 V_37 ,
T_2 V_38 ,
T_2 * V_39 ,
T_11 * V_40 ,
T_5 * * V_41 ,
T_7 * V_42 ,
T_2 V_43 ,
T_11 * V_44 )
{
T_11 V_45 ;
T_11 V_46 ;
T_11 V_47 ;
int error ;
T_11 V_48 ;
T_11 V_49 ;
int V_50 ;
for ( V_48 = F_19 ( V_1 , V_36 ) , V_45 = - 1 , V_46 = 0 ,
V_47 = F_19 ( V_1 , V_36 + 1 ) - 1 ;
V_48 <= V_47 ;
V_48 ++ ) {
error = F_20 ( V_1 , V_16 , V_48 , V_38 , 1 , & V_49 , & V_50 ) ;
if ( error ) {
return error ;
}
if ( V_50 ) {
error = F_21 ( V_1 , V_16 , V_48 , V_38 , V_41 ,
V_42 ) ;
if ( error ) {
return error ;
}
* V_39 = V_38 ;
* V_44 = V_48 ;
return 0 ;
}
if ( V_37 < V_38 ) {
T_11 V_51 ;
V_51 = V_49 - V_48 ;
if ( V_51 >= V_37 && V_51 > V_46 ) {
V_45 = V_48 ;
V_46 = V_51 ;
}
}
if ( V_49 < V_47 ) {
error = F_22 ( V_1 , V_16 , V_49 , V_47 , & V_48 ) ;
if ( error ) {
return error ;
}
} else
break;
}
if ( V_37 < V_38 && V_45 != - 1 ) {
T_2 V_52 ;
if ( V_43 > 1 && ( V_52 = F_23 ( V_46 , V_43 ) ) )
V_46 -= V_52 ;
error = F_21 ( V_1 , V_16 , V_45 , V_46 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
* V_39 = V_46 ;
* V_44 = V_45 ;
return 0 ;
}
* V_40 = V_49 ;
* V_44 = V_53 ;
return 0 ;
}
STATIC int
F_24 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_37 ,
T_2 V_38 ,
T_2 * V_39 ,
T_5 * * V_41 ,
T_7 * V_42 ,
T_2 V_43 ,
T_11 * V_44 )
{
int error ;
T_2 V_48 ;
int V_54 ;
T_11 V_49 ;
ASSERT ( V_37 % V_43 == 0 && V_38 % V_43 == 0 ) ;
error = F_20 ( V_1 , V_16 , V_5 , V_38 , 1 , & V_49 , & V_54 ) ;
if ( error ) {
return error ;
}
if ( V_54 ) {
error = F_21 ( V_1 , V_16 , V_5 , V_38 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
* V_39 = V_38 ;
* V_44 = V_5 ;
return 0 ;
}
V_38 = V_49 - V_5 ;
if ( V_38 < V_37 ) {
* V_44 = V_53 ;
return 0 ;
}
if ( V_43 > 1 && ( V_48 = V_38 % V_43 ) ) {
V_38 -= V_48 ;
if ( V_38 < V_37 ) {
* V_44 = V_53 ;
return 0 ;
}
}
error = F_21 ( V_1 , V_16 , V_5 , V_38 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
* V_39 = V_38 ;
* V_44 = V_5 ;
return 0 ;
}
STATIC int
F_25 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_37 ,
T_2 V_38 ,
T_2 * V_39 ,
T_5 * * V_41 ,
T_7 * V_42 ,
T_2 V_43 ,
T_11 * V_44 )
{
int V_55 ;
T_11 V_36 ;
int error ;
int V_48 ;
int V_56 ;
int V_57 ;
T_11 V_58 ;
T_11 V_59 ;
ASSERT ( V_37 % V_43 == 0 && V_38 % V_43 == 0 ) ;
if ( V_5 >= V_1 -> V_34 . V_60 )
V_5 = V_1 -> V_34 . V_60 - 1 ;
error = F_24 ( V_1 , V_16 , V_5 , V_37 , V_38 , V_39 ,
V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
V_36 = F_26 ( V_1 , V_5 ) ;
V_48 = 0 ;
ASSERT ( V_37 != 0 ) ;
V_57 = F_27 ( V_37 ) ;
for (; ; ) {
error = F_28 ( V_1 , V_16 , V_57 , V_1 -> V_61 - 1 ,
V_36 + V_48 , V_41 , V_42 , & V_55 ) ;
if ( error ) {
return error ;
}
if ( V_55 ) {
if ( V_48 >= 0 ) {
error = F_18 ( V_1 , V_16 ,
V_36 + V_48 , V_37 , V_38 , V_39 , & V_58 , V_41 ,
V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
}
else {
for ( V_56 = - 1 ; V_56 > V_48 ; V_56 -- ) {
error = F_28 ( V_1 , V_16 ,
V_57 , V_1 -> V_61 - 1 ,
V_36 + V_56 , V_41 , V_42 , & V_55 ) ;
if ( error ) {
return error ;
}
if ( V_55 )
continue;
error = F_18 ( V_1 ,
V_16 , V_36 + V_56 , V_37 , V_38 ,
V_39 , & V_58 , V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
}
error = F_18 ( V_1 , V_16 ,
V_36 + V_48 , V_37 , V_38 , V_39 , & V_58 , V_41 ,
V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
}
}
if ( V_48 > 0 && ( int ) V_36 - V_48 >= 0 )
V_48 = - V_48 ;
else if ( V_48 > 0 && ( int ) V_36 + V_48 < V_1 -> V_34 . V_62 - 1 )
V_48 ++ ;
else if ( V_48 <= 0 && ( int ) V_36 - V_48 < V_1 -> V_34 . V_62 - 1 )
V_48 = 1 - V_48 ;
else if ( V_48 <= 0 && ( int ) V_36 + V_48 > 0 )
V_48 -- ;
else
break;
}
* V_44 = V_53 ;
return 0 ;
}
STATIC int
F_29 (
T_1 * V_1 ,
T_10 * V_16 ,
T_2 V_37 ,
T_2 V_38 ,
T_2 * V_39 ,
T_5 * * V_41 ,
T_7 * V_42 ,
T_2 V_43 ,
T_11 * V_44 )
{
int error ;
int V_48 ;
int V_63 ;
T_11 V_58 ;
T_11 V_59 ;
T_12 V_64 ;
ASSERT ( V_37 % V_43 == 0 && V_38 % V_43 == 0 ) ;
ASSERT ( V_38 != 0 ) ;
for ( V_63 = F_27 ( V_38 ) ; V_63 < V_1 -> V_61 ; V_63 ++ ) {
for ( V_48 = 0 ; V_48 < V_1 -> V_34 . V_62 ; V_48 ++ ) {
error = F_30 ( V_1 , V_16 , V_63 , V_48 , V_41 , V_42 ,
& V_64 ) ;
if ( error ) {
return error ;
}
if ( ! V_64 )
continue;
error = F_18 ( V_1 , V_16 , V_48 , V_38 ,
V_38 , V_39 , & V_58 , V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
if ( F_26 ( V_1 , V_58 ) > V_48 + 1 )
V_48 = F_26 ( V_1 , V_58 ) - 1 ;
}
}
if ( V_37 > -- V_38 ) {
* V_44 = V_53 ;
return 0 ;
}
ASSERT ( V_37 != 0 ) ;
ASSERT ( V_38 != 0 ) ;
for ( V_63 = F_27 ( V_38 ) ; V_63 >= F_27 ( V_37 ) ; V_63 -- ) {
for ( V_48 = 0 ; V_48 < V_1 -> V_34 . V_62 ; V_48 ++ ) {
error = F_30 ( V_1 , V_16 , V_63 , V_48 , V_41 , V_42 ,
& V_64 ) ;
if ( error ) {
return error ;
}
if ( ! V_64 )
continue;
error = F_18 ( V_1 , V_16 , V_48 ,
F_31 ( V_37 , 1 << V_63 ) ,
F_32 ( V_38 , ( 1 << ( V_63 + 1 ) ) - 1 ) ,
V_39 , & V_58 , V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
if ( F_26 ( V_1 , V_58 ) > V_48 + 1 )
V_48 = F_26 ( V_1 , V_58 ) - 1 ;
}
}
* V_44 = V_53 ;
return 0 ;
}
STATIC int
F_21 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
T_5 * * V_41 ,
T_7 * V_42 )
{
T_11 V_47 ;
int error ;
T_11 V_66 ;
T_11 V_67 ;
V_47 = V_65 + V_39 - 1 ;
error = F_33 ( V_1 , V_16 , V_65 , 0 , & V_67 ) ;
if ( error ) {
return error ;
}
error = F_22 ( V_1 , V_16 , V_47 , V_1 -> V_34 . V_60 - 1 ,
& V_66 ) ;
if ( error ) {
return error ;
}
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 + 1 - V_67 ) ,
F_26 ( V_1 , V_67 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
if ( V_67 < V_65 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_65 - V_67 ) ,
F_26 ( V_1 , V_67 ) , 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
if ( V_66 > V_47 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 - V_47 ) ,
F_26 ( V_1 , V_47 + 1 ) , 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
error = F_36 ( V_1 , V_16 , V_65 , V_39 , 0 ) ;
return error ;
}
STATIC int
F_28 (
T_1 * V_1 ,
T_10 * V_16 ,
int V_68 ,
int V_69 ,
T_11 V_36 ,
T_5 * * V_41 ,
T_7 * V_42 ,
int * V_50 )
{
int error ;
int log ;
T_12 V_64 ;
for ( log = V_68 ; log <= V_69 ; log ++ ) {
error = F_30 ( V_1 , V_16 , log , V_36 , V_41 , V_42 , & V_64 ) ;
if ( error ) {
return error ;
}
if ( V_64 ) {
* V_50 = 1 ;
return 0 ;
}
}
* V_50 = 0 ;
return 0 ;
}
STATIC int
F_37 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_70 ,
int V_71 ,
T_5 * * V_72 )
{
T_5 * V_6 ;
T_3 * V_4 ;
T_9 V_12 ;
int V_13 = 1 ;
int error ;
V_4 = V_71 ? V_1 -> V_73 : V_1 -> V_74 ;
error = F_38 ( V_4 , V_70 , 1 , & V_12 , & V_13 , V_75 ) ;
if ( error )
return error ;
ASSERT ( V_12 . V_27 != V_76 ) ;
error = F_39 ( V_1 , V_16 , V_1 -> V_30 ,
F_14 ( V_1 , V_12 . V_27 ) ,
V_1 -> V_31 , 0 , & V_6 , NULL ) ;
if ( error )
return error ;
ASSERT ( ! F_40 ( V_6 ) ) ;
* V_72 = V_6 ;
return 0 ;
}
STATIC int
F_41 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_39 ,
int * V_50 )
{
T_11 V_77 ;
return F_20 ( V_1 , V_16 , V_5 , V_39 , 0 , & V_77 , V_50 ) ;
}
STATIC int
F_20 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
int V_78 ,
T_11 * V_77 ,
int * V_50 )
{
T_13 * V_79 ;
int V_80 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_81 ;
int error ;
T_11 V_48 ;
T_11 V_82 ;
T_13 V_83 ;
T_13 V_84 ;
int V_85 ;
V_70 = F_26 ( V_1 , V_65 ) ;
error = F_37 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_42 ( V_1 , V_65 ) ;
V_79 = & V_81 [ V_85 ] ;
V_80 = ( int ) ( V_65 & ( V_86 - 1 ) ) ;
V_78 = - V_78 ;
if ( V_80 ) {
V_82 = F_32 ( V_80 + V_39 , V_86 ) ;
V_83 = ( ( ( T_13 ) 1 << ( V_82 - V_80 ) ) - 1 ) << V_80 ;
if ( ( V_84 = ( * V_79 ^ V_78 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 = F_44 ( V_84 ) - V_80 ;
* V_77 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
}
V_48 = V_82 - V_80 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_86 ) {
if ( ( V_84 = * V_79 ^ V_78 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += F_44 ( V_84 ) ;
* V_77 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
}
V_48 += V_86 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
}
if ( ( V_82 = V_39 - V_48 ) ) {
V_83 = ( ( T_13 ) 1 << V_82 ) - 1 ;
if ( ( V_84 = ( * V_79 ^ V_78 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += F_44 ( V_84 ) ;
* V_77 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_43 ( V_16 , V_6 ) ;
* V_77 = V_65 + V_48 ;
* V_50 = 1 ;
return 0 ;
}
STATIC int
F_33 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_11 V_87 ,
T_11 * V_44 )
{
T_13 * V_79 ;
int V_80 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_81 ;
int error ;
T_11 V_88 ;
T_11 V_48 ;
T_11 V_39 ;
T_13 V_83 ;
T_13 V_89 ;
T_13 V_84 ;
int V_85 ;
V_70 = F_26 ( V_1 , V_65 ) ;
error = F_37 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_42 ( V_1 , V_65 ) ;
V_79 = & V_81 [ V_85 ] ;
V_80 = ( int ) ( V_65 & ( V_86 - 1 ) ) ;
V_39 = V_65 - V_87 + 1 ;
V_89 = ( * V_79 & ( ( T_13 ) 1 << V_80 ) ) ? - 1 : 0 ;
if ( V_80 < V_86 - 1 ) {
V_88 = F_31 ( ( V_90 ) ( V_80 - V_39 + 1 ) , 0 ) ;
V_83 = ( ( ( T_13 ) 1 << ( V_80 - V_88 + 1 ) ) - 1 ) <<
V_88 ;
if ( ( V_84 = ( * V_79 ^ V_89 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 = V_80 - F_46 ( V_84 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
V_48 = V_80 - V_88 + 1 ;
if ( -- V_85 == - 1 && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , -- V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_47 ( V_1 ) ;
V_79 = & V_81 [ V_85 ] ;
} else {
V_79 -- ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_86 ) {
if ( ( V_84 = * V_79 ^ V_89 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += V_86 - 1 - F_46 ( V_84 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
V_48 += V_86 ;
if ( -- V_85 == - 1 && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , -- V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_47 ( V_1 ) ;
V_79 = & V_81 [ V_85 ] ;
} else {
V_79 -- ;
}
}
if ( V_39 - V_48 ) {
V_88 = V_86 - ( V_39 - V_48 ) ;
V_83 = ( ( ( T_13 ) 1 << ( V_39 - V_48 ) ) - 1 ) << V_88 ;
if ( ( V_84 = ( * V_79 ^ V_89 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += V_86 - 1 - F_46 ( V_84 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_43 ( V_16 , V_6 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
STATIC int
F_22 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_11 V_87 ,
T_11 * V_44 )
{
T_13 * V_79 ;
int V_80 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_81 ;
int error ;
T_11 V_48 ;
T_11 V_82 ;
T_11 V_39 ;
T_13 V_83 ;
T_13 V_89 ;
T_13 V_84 ;
int V_85 ;
V_70 = F_26 ( V_1 , V_65 ) ;
error = F_37 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_42 ( V_1 , V_65 ) ;
V_79 = & V_81 [ V_85 ] ;
V_80 = ( int ) ( V_65 & ( V_86 - 1 ) ) ;
V_39 = V_87 - V_65 + 1 ;
V_89 = ( * V_79 & ( ( T_13 ) 1 << V_80 ) ) ? - 1 : 0 ;
if ( V_80 ) {
V_82 = F_32 ( V_80 + V_39 , V_86 ) ;
V_83 = ( ( ( T_13 ) 1 << ( V_82 - V_80 ) ) - 1 ) << V_80 ;
if ( ( V_84 = ( * V_79 ^ V_89 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 = F_44 ( V_84 ) - V_80 ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
V_48 = V_82 - V_80 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_86 ) {
if ( ( V_84 = * V_79 ^ V_89 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += F_44 ( V_84 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
V_48 += V_86 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
}
if ( ( V_82 = V_39 - V_48 ) ) {
V_83 = ( ( T_13 ) 1 << V_82 ) - 1 ;
if ( ( V_84 = ( * V_79 ^ V_89 ) & V_83 ) ) {
F_43 ( V_16 , V_6 ) ;
V_48 += F_44 ( V_84 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_43 ( V_16 , V_6 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
STATIC int
F_48 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
T_5 * * V_41 ,
T_7 * V_42 )
{
T_11 V_47 ;
int error ;
T_11 V_66 ;
T_11 V_67 ;
V_47 = V_65 + V_39 - 1 ;
error = F_36 ( V_1 , V_16 , V_65 , V_39 , 1 ) ;
if ( error ) {
return error ;
}
error = F_33 ( V_1 , V_16 , V_65 , 0 , & V_67 ) ;
if ( error ) {
return error ;
}
error = F_22 ( V_1 , V_16 , V_47 , V_1 -> V_34 . V_60 - 1 ,
& V_66 ) ;
if ( error )
return error ;
if ( V_67 < V_65 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_65 - V_67 ) ,
F_26 ( V_1 , V_67 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
if ( V_66 > V_47 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 - V_47 ) ,
F_26 ( V_1 , V_47 + 1 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 + 1 - V_67 ) ,
F_26 ( V_1 , V_67 ) , 1 , V_41 , V_42 ) ;
return error ;
}
STATIC int
F_30 (
T_1 * V_1 ,
T_10 * V_16 ,
int log ,
T_11 V_36 ,
T_5 * * V_41 ,
T_7 * V_42 ,
T_12 * V_64 )
{
T_5 * V_6 ;
int error ;
T_7 V_91 ;
int V_92 ;
T_12 * V_93 ;
V_92 = F_49 ( V_1 , log , V_36 ) ;
V_91 = F_50 ( V_1 , V_92 ) ;
if ( V_41 && * V_41 && * V_42 == V_91 )
V_6 = * V_41 ;
else {
if ( V_41 && * V_41 )
F_43 ( V_16 , * V_41 ) ;
error = F_37 ( V_1 , V_16 , V_91 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_41 ) {
* V_41 = V_6 ;
* V_42 = V_91 ;
}
}
V_93 = F_51 ( V_1 , V_6 , V_92 ) ;
* V_64 = * V_93 ;
if ( ! V_41 )
F_43 ( V_16 , V_6 ) ;
return 0 ;
}
STATIC int
F_36 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
int V_78 )
{
T_13 * V_79 ;
int V_80 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_81 ;
int error ;
T_13 * V_94 ;
int V_48 ;
int V_82 ;
T_13 V_83 ;
int V_85 ;
V_70 = F_26 ( V_1 , V_65 ) ;
error = F_37 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_6 -> V_33 ;
V_85 = F_42 ( V_1 , V_65 ) ;
V_94 = V_79 = & V_81 [ V_85 ] ;
V_80 = ( int ) ( V_65 & ( V_86 - 1 ) ) ;
V_78 = - V_78 ;
if ( V_80 ) {
V_82 = F_32 ( V_80 + V_39 , V_86 ) ;
V_83 = ( ( ( T_13 ) 1 << ( V_82 - V_80 ) ) - 1 ) << V_80 ;
if ( V_78 )
* V_79 |= V_83 ;
else
* V_79 &= ~ V_83 ;
V_48 = V_82 - V_80 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_17 ( V_16 , V_6 ,
( V_95 ) ( ( char * ) V_94 - ( char * ) V_81 ) ,
( V_95 ) ( ( char * ) V_79 - ( char * ) V_81 ) ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_94 = V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_86 ) {
* V_79 = V_78 ;
V_48 += V_86 ;
if ( ++ V_85 == F_45 ( V_1 ) && V_48 < V_39 ) {
F_17 ( V_16 , V_6 ,
( V_95 ) ( ( char * ) V_94 - ( char * ) V_81 ) ,
( V_95 ) ( ( char * ) V_79 - ( char * ) V_81 ) ) ;
error = F_37 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_94 = V_79 = V_81 = V_6 -> V_33 ;
V_85 = 0 ;
} else {
V_79 ++ ;
}
}
if ( ( V_82 = V_39 - V_48 ) ) {
V_80 = 0 ;
V_83 = ( ( T_13 ) 1 << V_82 ) - 1 ;
if ( V_78 )
* V_79 |= V_83 ;
else
* V_79 &= ~ V_83 ;
V_79 ++ ;
}
if ( V_79 > V_94 )
F_17 ( V_16 , V_6 , ( V_95 ) ( ( char * ) V_94 - ( char * ) V_81 ) ,
( V_95 ) ( ( char * ) V_79 - ( char * ) V_81 - 1 ) ) ;
return 0 ;
}
STATIC int
F_34 (
T_1 * V_1 ,
T_10 * V_16 ,
int log ,
T_11 V_36 ,
int V_96 ,
T_5 * * V_41 ,
T_7 * V_42 )
{
T_5 * V_6 ;
int error ;
T_7 V_91 ;
int V_92 ;
T_12 * V_93 ;
V_92 = F_49 ( V_1 , log , V_36 ) ;
V_91 = F_50 ( V_1 , V_92 ) ;
if ( V_41 && * V_41 && * V_42 == V_91 )
V_6 = * V_41 ;
else {
if ( V_41 && * V_41 )
F_43 ( V_16 , * V_41 ) ;
error = F_37 ( V_1 , V_16 , V_91 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_41 ) {
* V_41 = V_6 ;
* V_42 = V_91 ;
}
}
V_93 = F_51 ( V_1 , V_6 , V_92 ) ;
* V_93 += V_96 ;
F_17 ( V_16 , V_6 , ( V_95 ) ( ( char * ) V_93 - ( char * ) V_6 -> V_33 ) ,
( V_95 ) ( ( char * ) V_93 - ( char * ) V_6 -> V_33 + sizeof( * V_93 ) - 1 ) ) ;
return 0 ;
}
int
F_52 (
T_1 * V_1 ,
T_14 * V_97 )
{
T_11 V_98 ;
T_5 * V_6 ;
int error ;
T_1 * V_99 ;
T_15 V_100 ;
T_2 V_101 ;
T_16 V_102 ;
T_17 V_103 ;
T_2 V_104 ;
V_95 V_105 ;
V_95 V_106 ;
T_18 * V_107 ;
T_2 V_108 ;
T_2 V_109 ;
T_18 * V_110 ;
T_7 V_111 ;
V_110 = & V_1 -> V_34 ;
if ( ! F_53 ( V_112 ) )
return F_10 ( V_113 ) ;
if ( V_1 -> V_114 == NULL || V_1 -> V_74 == NULL ||
( V_100 = V_97 -> V_115 ) <= V_110 -> V_116 ||
( V_110 -> V_116 && ( V_97 -> V_117 != V_110 -> V_118 ) ) )
return F_10 ( V_119 ) ;
if ( ( error = F_54 ( V_110 , V_100 ) ) )
return error ;
V_6 = F_55 ( V_1 -> V_114 ,
F_56 ( V_1 , V_100 - 1 ) ,
F_56 ( V_1 , 1 ) , 0 , NULL ) ;
if ( ! V_6 )
return V_32 ;
if ( V_6 -> V_120 ) {
error = V_6 -> V_120 ;
F_57 ( V_6 ) ;
return error ;
}
F_57 ( V_6 ) ;
V_102 = V_100 ;
F_58 ( V_102 , V_97 -> V_117 ) ;
V_101 = F_59 ( V_102 , V_121 * V_110 -> V_35 ) ;
V_103 = F_27 ( V_102 ) ;
V_105 = V_103 + 1 ;
V_106 = ( V_95 ) sizeof( T_12 ) * V_105 * V_101 ;
V_104 = F_60 ( V_1 , V_106 ) ;
V_106 = F_61 ( V_1 , V_104 ) ;
if ( V_104 > ( V_1 -> V_34 . V_122 >> 1 ) )
return F_10 ( V_119 ) ;
V_108 = F_60 ( V_1 , V_1 -> V_74 -> V_123 . V_124 ) ;
V_109 = F_60 ( V_1 , V_1 -> V_73 -> V_123 . V_124 ) ;
error = F_1 ( V_1 , V_108 , V_101 , V_1 -> V_74 ) ;
if ( error )
return error ;
error = F_1 ( V_1 , V_109 , V_104 , V_1 -> V_73 ) ;
if ( error )
return error ;
V_99 = F_62 ( sizeof( * V_99 ) , V_125 ) ;
for ( V_98 = V_110 -> V_62 -
( ( V_110 -> V_60 & ( ( 1 << V_1 -> V_126 ) - 1 ) ) != 0 ) ;
V_98 < V_101 ;
V_98 ++ ) {
T_10 * V_16 ;
int V_15 = 0 ;
* V_99 = * V_1 ;
V_107 = & V_99 -> V_34 ;
V_107 -> V_118 = V_97 -> V_117 ;
V_107 -> V_62 = V_98 + 1 ;
V_107 -> V_116 =
F_32 ( V_100 ,
V_107 -> V_62 * V_121 *
V_107 -> V_35 * V_107 -> V_118 ) ;
V_107 -> V_60 = V_107 -> V_116 ;
F_58 ( V_107 -> V_60 , V_107 -> V_118 ) ;
ASSERT ( V_107 -> V_60 != 0 ) ;
V_107 -> V_127 = F_27 ( V_107 -> V_60 ) ;
V_105 = V_99 -> V_61 = V_107 -> V_127 + 1 ;
V_106 =
( V_95 ) sizeof( T_12 ) * V_105 *
V_107 -> V_62 ;
V_104 = F_60 ( V_1 , V_106 ) ;
V_99 -> V_128 = V_106 = F_61 ( V_1 , V_104 ) ;
V_16 = F_2 ( V_1 , V_129 ) ;
if ( ( error = F_4 ( V_16 , 0 ,
F_63 ( V_99 ) , 0 , 0 , 0 ) ) )
goto V_20;
F_6 ( V_1 -> V_74 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_74 , V_22 ) ;
V_1 -> V_74 -> V_123 . V_124 =
V_107 -> V_62 * V_107 -> V_35 ;
F_64 ( V_16 , V_1 -> V_74 , V_130 ) ;
V_15 |= V_23 ;
F_6 ( V_1 -> V_73 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_73 , V_22 ) ;
V_1 -> V_73 -> V_123 . V_124 = V_99 -> V_128 ;
F_64 ( V_16 , V_1 -> V_73 , V_130 ) ;
if ( V_110 -> V_62 != V_107 -> V_62 ||
V_1 -> V_61 != V_99 -> V_61 ) {
error = F_65 ( V_1 , V_99 , V_16 ) ;
if ( error )
goto V_20;
}
if ( V_107 -> V_118 != V_110 -> V_118 )
F_66 ( V_16 , V_131 ,
V_107 -> V_118 - V_110 -> V_118 ) ;
if ( V_107 -> V_62 != V_110 -> V_62 )
F_66 ( V_16 , V_132 ,
V_107 -> V_62 - V_110 -> V_62 ) ;
if ( V_107 -> V_116 != V_110 -> V_116 )
F_66 ( V_16 , V_133 ,
V_107 -> V_116 - V_110 -> V_116 ) ;
if ( V_107 -> V_60 != V_110 -> V_60 )
F_66 ( V_16 , V_134 ,
V_107 -> V_60 - V_110 -> V_60 ) ;
if ( V_107 -> V_127 != V_110 -> V_127 )
F_66 ( V_16 , V_135 ,
V_107 -> V_127 - V_110 -> V_127 ) ;
V_6 = NULL ;
error = F_48 ( V_99 , V_16 , V_110 -> V_60 ,
V_107 -> V_60 - V_110 -> V_60 , & V_6 , & V_111 ) ;
if ( error ) {
V_20:
F_16 ( V_16 , V_15 ) ;
break;
}
F_66 ( V_16 , V_136 ,
V_107 -> V_60 - V_110 -> V_60 ) ;
V_1 -> V_61 = V_105 ;
V_1 -> V_128 = V_106 ;
error = F_12 ( V_16 , 0 ) ;
if ( error )
break;
}
F_67 ( V_99 ) ;
return error ;
}
int
F_68 (
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_37 ,
T_2 V_38 ,
T_2 * V_39 ,
T_19 type ,
int V_137 ,
T_2 V_43 ,
T_11 * V_44 )
{
T_1 * V_1 = V_16 -> V_138 ;
int error ;
T_11 V_59 ;
T_7 V_91 ;
T_5 * V_139 ;
ASSERT ( F_69 ( V_1 -> V_74 , V_22 ) ) ;
ASSERT ( V_37 > 0 && V_37 <= V_38 ) ;
if ( V_43 > 1 ) {
T_2 V_48 ;
if ( ( V_48 = V_38 % V_43 ) )
V_38 -= V_48 ;
if ( ( V_48 = V_37 % V_43 ) )
V_37 += V_43 - V_48 ;
if ( V_38 < V_37 ) {
* V_44 = V_53 ;
return 0 ;
}
}
V_139 = NULL ;
switch ( type ) {
case V_140 :
error = F_29 ( V_1 , V_16 , V_37 , V_38 , V_39 ,
& V_139 , & V_91 , V_43 , & V_59 ) ;
break;
case V_141 :
error = F_25 ( V_1 , V_16 , V_5 , V_37 , V_38 ,
V_39 , & V_139 , & V_91 , V_43 , & V_59 ) ;
break;
case V_142 :
error = F_24 ( V_1 , V_16 , V_5 , V_37 , V_38 ,
V_39 , & V_139 , & V_91 , V_43 , & V_59 ) ;
break;
default:
error = V_32 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_59 != V_53 ) {
long V_143 = ( long ) * V_39 ;
ASSERT ( * V_39 >= V_37 && * V_39 <= V_38 ) ;
if ( V_137 )
F_66 ( V_16 , V_144 , - V_143 ) ;
else
F_66 ( V_16 , V_136 , - V_143 ) ;
}
* V_44 = V_59 ;
return 0 ;
}
int
F_70 (
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_39 )
{
int error ;
T_1 * V_1 ;
T_7 V_91 ;
T_5 * V_139 ;
V_1 = V_16 -> V_138 ;
ASSERT ( V_1 -> V_74 -> V_145 != NULL ) ;
ASSERT ( F_69 ( V_1 -> V_74 , V_22 ) ) ;
#if F_71 ( V_146 ) && F_71 ( V_147 )
{
int V_50 ;
error = F_41 ( V_1 , V_16 , V_5 , V_39 , & V_50 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_50 ) ;
}
#endif
V_139 = NULL ;
error = F_48 ( V_1 , V_16 , V_5 , V_39 , & V_139 , & V_91 ) ;
if ( error ) {
return error ;
}
F_66 ( V_16 , V_136 , ( long ) V_39 ) ;
if ( V_16 -> V_148 + V_1 -> V_34 . V_149 ==
V_1 -> V_34 . V_60 ) {
if ( ! ( V_1 -> V_74 -> V_123 . V_150 & V_151 ) )
V_1 -> V_74 -> V_123 . V_150 |= V_151 ;
* ( V_152 * ) & V_1 -> V_74 -> V_123 . V_153 = 0 ;
F_64 ( V_16 , V_1 -> V_74 , V_130 ) ;
}
return 0 ;
}
int
F_72 (
T_1 * V_1 )
{
T_5 * V_6 ;
T_6 V_8 ;
T_18 * V_110 ;
V_110 = & V_1 -> V_34 ;
if ( V_110 -> V_116 == 0 )
return 0 ;
if ( V_1 -> V_114 == NULL ) {
F_73 ( V_1 ,
L_1 ) ;
return F_10 ( V_154 ) ;
}
V_1 -> V_61 = V_110 -> V_127 + 1 ;
V_1 -> V_128 =
( V_95 ) sizeof( T_12 ) * V_1 -> V_61 *
V_110 -> V_62 ;
V_1 -> V_128 = F_74 ( V_1 -> V_128 , V_110 -> V_35 ) ;
V_1 -> V_74 = V_1 -> V_73 = NULL ;
V_8 = ( T_6 ) F_56 ( V_1 , V_1 -> V_34 . V_116 ) ;
if ( F_75 ( V_1 , V_8 ) != V_1 -> V_34 . V_116 ) {
F_73 ( V_1 , L_2 ,
( unsigned long long ) F_75 ( V_1 , V_8 ) ,
( unsigned long long ) V_1 -> V_34 . V_116 ) ;
return F_10 ( V_155 ) ;
}
V_6 = F_55 ( V_1 -> V_114 ,
V_8 - F_56 ( V_1 , 1 ) ,
F_56 ( V_1 , 1 ) , 0 , NULL ) ;
if ( ! V_6 || V_6 -> V_120 ) {
F_73 ( V_1 , L_3 ) ;
if ( V_6 )
F_57 ( V_6 ) ;
return V_32 ;
}
F_57 ( V_6 ) ;
return 0 ;
}
int
F_76 (
T_1 * V_1 )
{
int error ;
T_18 * V_110 ;
V_110 = & V_1 -> V_34 ;
if ( V_110 -> V_156 == V_157 )
return 0 ;
error = F_77 ( V_1 , NULL , V_110 -> V_156 , 0 , 0 , & V_1 -> V_74 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_74 != NULL ) ;
ASSERT ( V_110 -> V_158 != V_157 ) ;
error = F_77 ( V_1 , NULL , V_110 -> V_158 , 0 , 0 , & V_1 -> V_73 ) ;
if ( error ) {
F_78 ( V_1 -> V_74 ) ;
return error ;
}
ASSERT ( V_1 -> V_73 != NULL ) ;
return 0 ;
}
void
F_79 (
struct V_159 * V_1 )
{
if ( V_1 -> V_74 )
F_78 ( V_1 -> V_74 ) ;
if ( V_1 -> V_73 )
F_78 ( V_1 -> V_73 ) ;
}
int
F_80 (
T_1 * V_1 ,
T_10 * V_16 ,
T_2 V_39 ,
T_11 * V_160 )
{
T_11 V_79 ;
int V_161 ;
V_152 V_162 ;
V_152 V_163 ;
V_152 * V_164 ;
ASSERT ( F_69 ( V_1 -> V_74 , V_22 ) ) ;
V_164 = ( V_152 * ) & V_1 -> V_74 -> V_123 . V_153 ;
if ( ! ( V_1 -> V_74 -> V_123 . V_150 & V_151 ) ) {
V_1 -> V_74 -> V_123 . V_150 |= V_151 ;
* V_164 = 0 ;
}
V_163 = * V_164 ;
if ( ( V_161 = F_81 ( V_163 ) ) == - 1 )
V_79 = 0 ;
else {
V_162 = V_163 - ( 1ULL << V_161 ) ;
V_79 = ( V_1 -> V_34 . V_60 * ( ( V_162 << 1 ) + 1ULL ) ) >>
( V_161 + 1 ) ;
if ( V_79 >= V_1 -> V_34 . V_60 )
V_79 = F_23 ( V_79 , V_1 -> V_34 . V_60 ) ;
if ( V_79 + V_39 > V_1 -> V_34 . V_60 )
V_79 = V_1 -> V_34 . V_60 - V_39 ;
}
* V_164 = V_163 + 1 ;
F_64 ( V_16 , V_1 -> V_74 , V_130 ) ;
* V_160 = V_79 ;
return 0 ;
}
