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
V_24 | V_25 , & V_9 ,
V_14 , & V_12 , & V_13 , & V_10 ) ;
if ( ! error && V_13 < 1 )
error = F_10 ( V_26 ) ;
if ( error )
goto V_20;
error = F_11 ( & V_16 , & V_10 , & V_7 ) ;
if ( error )
goto V_20;
error = F_12 ( V_16 , V_21 ) ;
if ( error )
goto error;
V_15 = 0 ;
for ( V_5 = V_12 . V_27 , V_11 = V_12 . V_28 ;
V_5 < V_12 . V_27 + V_12 . V_29 ;
V_5 ++ , V_11 ++ ) {
V_16 = F_2 ( V_1 , V_30 ) ;
if ( ( error = F_4 ( V_16 , 0 ,
F_13 ( V_1 ) , 0 , 0 , 0 ) ) )
goto V_20;
F_6 ( V_4 , V_22 ) ;
F_7 ( V_16 , V_4 , V_22 ) ;
V_8 = F_14 ( V_1 , V_11 ) ;
V_6 = F_15 ( V_16 , V_1 -> V_31 , V_8 ,
V_1 -> V_32 , 0 ) ;
if ( V_6 == NULL ) {
error = F_10 ( V_33 ) ;
V_20:
F_16 ( V_16 , V_15 ) ;
goto error;
}
memset ( F_17 ( V_6 ) , 0 , V_1 -> V_34 . V_35 ) ;
F_18 ( V_16 , V_6 , 0 , V_1 -> V_34 . V_35 - 1 ) ;
error = F_12 ( V_16 , 0 ) ;
if ( error )
goto error;
}
V_2 = V_12 . V_27 + V_12 . V_29 ;
}
return 0 ;
error:
return error ;
}
STATIC int
F_19 (
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
for ( V_48 = F_20 ( V_1 , V_36 ) , V_45 = - 1 , V_46 = 0 ,
V_47 = F_20 ( V_1 , V_36 + 1 ) - 1 ;
V_48 <= V_47 ;
V_48 ++ ) {
error = F_21 ( V_1 , V_16 , V_48 , V_38 , 1 , & V_49 , & V_50 ) ;
if ( error ) {
return error ;
}
if ( V_50 ) {
error = F_22 ( V_1 , V_16 , V_48 , V_38 , V_41 ,
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
error = F_23 ( V_1 , V_16 , V_49 , V_47 , & V_48 ) ;
if ( error ) {
return error ;
}
} else
break;
}
if ( V_37 < V_38 && V_45 != - 1 ) {
T_2 V_52 ;
if ( V_43 > 1 && ( V_52 = F_24 ( V_46 , V_43 ) ) )
V_46 -= V_52 ;
error = F_22 ( V_1 , V_16 , V_45 , V_46 , V_41 , V_42 ) ;
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
int error ;
T_2 V_48 ;
int V_54 ;
T_11 V_49 ;
ASSERT ( V_37 % V_43 == 0 && V_38 % V_43 == 0 ) ;
error = F_21 ( V_1 , V_16 , V_5 , V_38 , 1 , & V_49 , & V_54 ) ;
if ( error ) {
return error ;
}
if ( V_54 ) {
error = F_22 ( V_1 , V_16 , V_5 , V_38 , V_41 , V_42 ) ;
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
error = F_22 ( V_1 , V_16 , V_5 , V_38 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
* V_39 = V_38 ;
* V_44 = V_5 ;
return 0 ;
}
STATIC int
F_26 (
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
error = F_25 ( V_1 , V_16 , V_5 , V_37 , V_38 , V_39 ,
V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
V_36 = F_27 ( V_1 , V_5 ) ;
V_48 = 0 ;
ASSERT ( V_37 != 0 ) ;
V_57 = F_28 ( V_37 ) ;
for (; ; ) {
error = F_29 ( V_1 , V_16 , V_57 , V_1 -> V_61 - 1 ,
V_36 + V_48 , V_41 , V_42 , & V_55 ) ;
if ( error ) {
return error ;
}
if ( V_55 ) {
if ( V_48 >= 0 ) {
error = F_19 ( V_1 , V_16 ,
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
error = F_29 ( V_1 , V_16 ,
V_57 , V_1 -> V_61 - 1 ,
V_36 + V_56 , V_41 , V_42 , & V_55 ) ;
if ( error ) {
return error ;
}
if ( V_55 )
continue;
error = F_19 ( V_1 ,
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
error = F_19 ( V_1 , V_16 ,
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
F_30 (
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
for ( V_63 = F_28 ( V_38 ) ; V_63 < V_1 -> V_61 ; V_63 ++ ) {
for ( V_48 = 0 ; V_48 < V_1 -> V_34 . V_62 ; V_48 ++ ) {
error = F_31 ( V_1 , V_16 , V_63 , V_48 , V_41 , V_42 ,
& V_64 ) ;
if ( error ) {
return error ;
}
if ( ! V_64 )
continue;
error = F_19 ( V_1 , V_16 , V_48 , V_38 ,
V_38 , V_39 , & V_58 , V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
if ( F_27 ( V_1 , V_58 ) > V_48 + 1 )
V_48 = F_27 ( V_1 , V_58 ) - 1 ;
}
}
if ( V_37 > -- V_38 ) {
* V_44 = V_53 ;
return 0 ;
}
ASSERT ( V_37 != 0 ) ;
ASSERT ( V_38 != 0 ) ;
for ( V_63 = F_28 ( V_38 ) ; V_63 >= F_28 ( V_37 ) ; V_63 -- ) {
for ( V_48 = 0 ; V_48 < V_1 -> V_34 . V_62 ; V_48 ++ ) {
error = F_31 ( V_1 , V_16 , V_63 , V_48 , V_41 , V_42 ,
& V_64 ) ;
if ( error ) {
return error ;
}
if ( ! V_64 )
continue;
error = F_19 ( V_1 , V_16 , V_48 ,
F_32 ( V_37 , 1 << V_63 ) ,
F_33 ( V_38 , ( 1 << ( V_63 + 1 ) ) - 1 ) ,
V_39 , & V_58 , V_41 , V_42 , V_43 , & V_59 ) ;
if ( error ) {
return error ;
}
if ( V_59 != V_53 ) {
* V_44 = V_59 ;
return 0 ;
}
if ( F_27 ( V_1 , V_58 ) > V_48 + 1 )
V_48 = F_27 ( V_1 , V_58 ) - 1 ;
}
}
* V_44 = V_53 ;
return 0 ;
}
STATIC int
F_22 (
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
error = F_34 ( V_1 , V_16 , V_65 , 0 , & V_67 ) ;
if ( error ) {
return error ;
}
error = F_23 ( V_1 , V_16 , V_47 , V_1 -> V_34 . V_60 - 1 ,
& V_66 ) ;
if ( error ) {
return error ;
}
error = F_35 ( V_1 , V_16 ,
F_36 ( V_66 + 1 - V_67 ) ,
F_27 ( V_1 , V_67 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
if ( V_67 < V_65 ) {
error = F_35 ( V_1 , V_16 ,
F_36 ( V_65 - V_67 ) ,
F_27 ( V_1 , V_67 ) , 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
if ( V_66 > V_47 ) {
error = F_35 ( V_1 , V_16 ,
F_36 ( V_66 - V_47 ) ,
F_27 ( V_1 , V_47 + 1 ) , 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
error = F_37 ( V_1 , V_16 , V_65 , V_39 , 0 ) ;
return error ;
}
STATIC int
F_29 (
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
error = F_31 ( V_1 , V_16 , log , V_36 , V_41 , V_42 , & V_64 ) ;
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
F_38 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_70 ,
int V_71 ,
T_5 * * V_72 )
{
T_5 * V_6 ;
T_6 V_8 ;
int error ;
T_7 V_73 ;
T_3 * V_4 ;
V_4 = V_71 ? V_1 -> V_74 : V_1 -> V_75 ;
error = F_39 ( V_16 , V_4 , V_76 , & V_73 , V_70 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_73 != V_77 ) ;
V_8 = F_14 ( V_1 , V_73 ) ;
error = F_40 ( V_1 , V_16 , V_1 -> V_31 , V_8 ,
V_1 -> V_32 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_6 && ! F_41 ( V_6 ) ) ;
* V_72 = V_6 ;
return 0 ;
}
STATIC int
F_42 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_39 ,
int * V_50 )
{
T_11 V_78 ;
return F_21 ( V_1 , V_16 , V_5 , V_39 , 0 , & V_78 , V_50 ) ;
}
STATIC int
F_21 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
int V_79 ,
T_11 * V_78 ,
int * V_50 )
{
T_13 * V_80 ;
int V_81 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_82 ;
int error ;
T_11 V_48 ;
T_11 V_83 ;
T_13 V_84 ;
T_13 V_85 ;
int V_86 ;
V_70 = F_27 ( V_1 , V_65 ) ;
error = F_38 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_43 ( V_1 , V_65 ) ;
V_80 = & V_82 [ V_86 ] ;
V_81 = ( int ) ( V_65 & ( V_87 - 1 ) ) ;
V_79 = - V_79 ;
if ( V_81 ) {
V_83 = F_33 ( V_81 + V_39 , V_87 ) ;
V_84 = ( ( ( T_13 ) 1 << ( V_83 - V_81 ) ) - 1 ) << V_81 ;
if ( ( V_85 = ( * V_80 ^ V_79 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 = F_45 ( V_85 ) - V_81 ;
* V_78 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
}
V_48 = V_83 - V_81 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_87 ) {
if ( ( V_85 = * V_80 ^ V_79 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += F_45 ( V_85 ) ;
* V_78 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
}
V_48 += V_87 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
}
if ( ( V_83 = V_39 - V_48 ) ) {
V_84 = ( ( T_13 ) 1 << V_83 ) - 1 ;
if ( ( V_85 = ( * V_80 ^ V_79 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += F_45 ( V_85 ) ;
* V_78 = V_65 + V_48 ;
* V_50 = 0 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_44 ( V_16 , V_6 ) ;
* V_78 = V_65 + V_48 ;
* V_50 = 1 ;
return 0 ;
}
STATIC int
F_34 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_11 V_88 ,
T_11 * V_44 )
{
T_13 * V_80 ;
int V_81 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_82 ;
int error ;
T_11 V_89 ;
T_11 V_48 ;
T_11 V_39 ;
T_13 V_84 ;
T_13 V_90 ;
T_13 V_85 ;
int V_86 ;
V_70 = F_27 ( V_1 , V_65 ) ;
error = F_38 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_43 ( V_1 , V_65 ) ;
V_80 = & V_82 [ V_86 ] ;
V_81 = ( int ) ( V_65 & ( V_87 - 1 ) ) ;
V_39 = V_65 - V_88 + 1 ;
V_90 = ( * V_80 & ( ( T_13 ) 1 << V_81 ) ) ? - 1 : 0 ;
if ( V_81 < V_87 - 1 ) {
V_89 = F_32 ( ( V_91 ) ( V_81 - V_39 + 1 ) , 0 ) ;
V_84 = ( ( ( T_13 ) 1 << ( V_81 - V_89 + 1 ) ) - 1 ) <<
V_89 ;
if ( ( V_85 = ( * V_80 ^ V_90 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 = V_81 - F_47 ( V_85 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
V_48 = V_81 - V_89 + 1 ;
if ( -- V_86 == - 1 && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , -- V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_48 ( V_1 ) ;
V_80 = & V_82 [ V_86 ] ;
} else {
V_80 -- ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_87 ) {
if ( ( V_85 = * V_80 ^ V_90 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += V_87 - 1 - F_47 ( V_85 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
V_48 += V_87 ;
if ( -- V_86 == - 1 && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , -- V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_48 ( V_1 ) ;
V_80 = & V_82 [ V_86 ] ;
} else {
V_80 -- ;
}
}
if ( V_39 - V_48 ) {
V_89 = V_87 - ( V_39 - V_48 ) ;
V_84 = ( ( ( T_13 ) 1 << ( V_39 - V_48 ) ) - 1 ) << V_89 ;
if ( ( V_85 = ( * V_80 ^ V_90 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += V_87 - 1 - F_47 ( V_85 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_44 ( V_16 , V_6 ) ;
* V_44 = V_65 - V_48 + 1 ;
return 0 ;
}
STATIC int
F_23 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_11 V_88 ,
T_11 * V_44 )
{
T_13 * V_80 ;
int V_81 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_82 ;
int error ;
T_11 V_48 ;
T_11 V_83 ;
T_11 V_39 ;
T_13 V_84 ;
T_13 V_90 ;
T_13 V_85 ;
int V_86 ;
V_70 = F_27 ( V_1 , V_65 ) ;
error = F_38 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_43 ( V_1 , V_65 ) ;
V_80 = & V_82 [ V_86 ] ;
V_81 = ( int ) ( V_65 & ( V_87 - 1 ) ) ;
V_39 = V_88 - V_65 + 1 ;
V_90 = ( * V_80 & ( ( T_13 ) 1 << V_81 ) ) ? - 1 : 0 ;
if ( V_81 ) {
V_83 = F_33 ( V_81 + V_39 , V_87 ) ;
V_84 = ( ( ( T_13 ) 1 << ( V_83 - V_81 ) ) - 1 ) << V_81 ;
if ( ( V_85 = ( * V_80 ^ V_90 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 = F_45 ( V_85 ) - V_81 ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
V_48 = V_83 - V_81 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_87 ) {
if ( ( V_85 = * V_80 ^ V_90 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += F_45 ( V_85 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
V_48 += V_87 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_44 ( V_16 , V_6 ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
}
if ( ( V_83 = V_39 - V_48 ) ) {
V_84 = ( ( T_13 ) 1 << V_83 ) - 1 ;
if ( ( V_85 = ( * V_80 ^ V_90 ) & V_84 ) ) {
F_44 ( V_16 , V_6 ) ;
V_48 += F_45 ( V_85 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
} else
V_48 = V_39 ;
}
F_44 ( V_16 , V_6 ) ;
* V_44 = V_65 + V_48 - 1 ;
return 0 ;
}
STATIC int
F_49 (
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
error = F_37 ( V_1 , V_16 , V_65 , V_39 , 1 ) ;
if ( error ) {
return error ;
}
error = F_34 ( V_1 , V_16 , V_65 , 0 , & V_67 ) ;
if ( error ) {
return error ;
}
error = F_23 ( V_1 , V_16 , V_47 , V_1 -> V_34 . V_60 - 1 ,
& V_66 ) ;
if ( error )
return error ;
if ( V_67 < V_65 ) {
error = F_35 ( V_1 , V_16 ,
F_36 ( V_65 - V_67 ) ,
F_27 ( V_1 , V_67 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
if ( V_66 > V_47 ) {
error = F_35 ( V_1 , V_16 ,
F_36 ( V_66 - V_47 ) ,
F_27 ( V_1 , V_47 + 1 ) , - 1 , V_41 , V_42 ) ;
if ( error ) {
return error ;
}
}
error = F_35 ( V_1 , V_16 ,
F_36 ( V_66 + 1 - V_67 ) ,
F_27 ( V_1 , V_67 ) , 1 , V_41 , V_42 ) ;
return error ;
}
STATIC int
F_31 (
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
T_7 V_92 ;
int V_93 ;
T_12 * V_94 ;
V_93 = F_50 ( V_1 , log , V_36 ) ;
V_92 = F_51 ( V_1 , V_93 ) ;
if ( V_41 && * V_41 && * V_42 == V_92 )
V_6 = * V_41 ;
else {
if ( V_41 && * V_41 )
F_44 ( V_16 , * V_41 ) ;
error = F_38 ( V_1 , V_16 , V_92 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_41 ) {
* V_41 = V_6 ;
* V_42 = V_92 ;
}
}
V_94 = F_52 ( V_1 , V_6 , V_93 ) ;
* V_64 = * V_94 ;
if ( ! V_41 )
F_44 ( V_16 , V_6 ) ;
return 0 ;
}
STATIC int
F_37 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_65 ,
T_2 V_39 ,
int V_79 )
{
T_13 * V_80 ;
int V_81 ;
T_11 V_70 ;
T_5 * V_6 ;
T_13 * V_82 ;
int error ;
T_13 * V_95 ;
int V_48 ;
int V_83 ;
T_13 V_84 ;
int V_86 ;
V_70 = F_27 ( V_1 , V_65 ) ;
error = F_38 ( V_1 , V_16 , V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = F_43 ( V_1 , V_65 ) ;
V_95 = V_80 = & V_82 [ V_86 ] ;
V_81 = ( int ) ( V_65 & ( V_87 - 1 ) ) ;
V_79 = - V_79 ;
if ( V_81 ) {
V_83 = F_33 ( V_81 + V_39 , V_87 ) ;
V_84 = ( ( ( T_13 ) 1 << ( V_83 - V_81 ) ) - 1 ) << V_81 ;
if ( V_79 )
* V_80 |= V_84 ;
else
* V_80 &= ~ V_84 ;
V_48 = V_83 - V_81 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_18 ( V_16 , V_6 ,
( V_96 ) ( ( char * ) V_95 - ( char * ) V_82 ) ,
( V_96 ) ( ( char * ) V_80 - ( char * ) V_82 ) ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_95 = V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
} else {
V_48 = 0 ;
}
while ( V_39 - V_48 >= V_87 ) {
* V_80 = V_79 ;
V_48 += V_87 ;
if ( ++ V_86 == F_46 ( V_1 ) && V_48 < V_39 ) {
F_18 ( V_16 , V_6 ,
( V_96 ) ( ( char * ) V_95 - ( char * ) V_82 ) ,
( V_96 ) ( ( char * ) V_80 - ( char * ) V_82 ) ) ;
error = F_38 ( V_1 , V_16 , ++ V_70 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_95 = V_80 = V_82 = ( T_13 * ) F_17 ( V_6 ) ;
V_86 = 0 ;
} else {
V_80 ++ ;
}
}
if ( ( V_83 = V_39 - V_48 ) ) {
V_81 = 0 ;
V_84 = ( ( T_13 ) 1 << V_83 ) - 1 ;
if ( V_79 )
* V_80 |= V_84 ;
else
* V_80 &= ~ V_84 ;
V_80 ++ ;
}
if ( V_80 > V_95 )
F_18 ( V_16 , V_6 , ( V_96 ) ( ( char * ) V_95 - ( char * ) V_82 ) ,
( V_96 ) ( ( char * ) V_80 - ( char * ) V_82 - 1 ) ) ;
return 0 ;
}
STATIC int
F_35 (
T_1 * V_1 ,
T_10 * V_16 ,
int log ,
T_11 V_36 ,
int V_97 ,
T_5 * * V_41 ,
T_7 * V_42 )
{
T_5 * V_6 ;
int error ;
T_7 V_92 ;
int V_93 ;
T_12 * V_94 ;
V_93 = F_50 ( V_1 , log , V_36 ) ;
V_92 = F_51 ( V_1 , V_93 ) ;
if ( V_41 && * V_41 && * V_42 == V_92 )
V_6 = * V_41 ;
else {
if ( V_41 && * V_41 )
F_44 ( V_16 , * V_41 ) ;
error = F_38 ( V_1 , V_16 , V_92 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_41 ) {
* V_41 = V_6 ;
* V_42 = V_92 ;
}
}
V_94 = F_52 ( V_1 , V_6 , V_93 ) ;
* V_94 += V_97 ;
F_18 ( V_16 , V_6 , ( V_96 ) ( ( char * ) V_94 - ( char * ) F_17 ( V_6 ) ) ,
( V_96 ) ( ( char * ) V_94 - ( char * ) F_17 ( V_6 ) + sizeof( * V_94 ) - 1 ) ) ;
return 0 ;
}
int
F_53 (
T_1 * V_1 ,
T_14 * V_98 )
{
T_11 V_99 ;
T_5 * V_6 ;
int error ;
T_1 * V_100 ;
T_15 V_101 ;
T_2 V_102 ;
T_16 V_103 ;
T_17 V_104 ;
T_2 V_105 ;
V_96 V_106 ;
V_96 V_107 ;
T_18 * V_108 ;
T_2 V_109 ;
T_2 V_110 ;
T_18 * V_111 ;
T_7 V_112 ;
V_111 = & V_1 -> V_34 ;
if ( ! F_54 ( V_113 ) )
return F_10 ( V_114 ) ;
if ( V_1 -> V_115 == NULL || V_1 -> V_75 == NULL ||
( V_101 = V_98 -> V_116 ) <= V_111 -> V_117 ||
( V_111 -> V_117 && ( V_98 -> V_118 != V_111 -> V_119 ) ) )
return F_10 ( V_120 ) ;
if ( ( error = F_55 ( V_111 , V_101 ) ) )
return error ;
V_6 = F_56 ( V_1 , V_1 -> V_115 ,
F_57 ( V_1 , V_101 - 1 ) ,
F_58 ( V_1 , 1 ) , 0 ) ;
if ( ! V_6 )
return V_33 ;
F_59 ( V_6 ) ;
V_103 = V_101 ;
F_60 ( V_103 , V_98 -> V_118 ) ;
V_102 = F_61 ( V_103 , V_121 * V_111 -> V_35 ) ;
V_104 = F_28 ( V_103 ) ;
V_106 = V_104 + 1 ;
V_107 = ( V_96 ) sizeof( T_12 ) * V_106 * V_102 ;
V_105 = F_62 ( V_1 , V_107 ) ;
V_107 = F_58 ( V_1 , V_105 ) ;
if ( V_105 > ( V_1 -> V_34 . V_122 >> 1 ) )
return F_10 ( V_120 ) ;
V_109 = F_62 ( V_1 , V_1 -> V_75 -> V_123 . V_124 ) ;
V_110 = F_62 ( V_1 , V_1 -> V_74 -> V_123 . V_124 ) ;
error = F_1 ( V_1 , V_109 , V_102 , V_1 -> V_75 ) ;
if ( error )
return error ;
error = F_1 ( V_1 , V_110 , V_105 , V_1 -> V_74 ) ;
if ( error )
return error ;
V_100 = F_63 ( sizeof( * V_100 ) , V_125 ) ;
for ( V_99 = V_111 -> V_62 -
( ( V_111 -> V_60 & ( ( 1 << V_1 -> V_126 ) - 1 ) ) != 0 ) ;
V_99 < V_102 ;
V_99 ++ ) {
T_10 * V_16 ;
int V_15 = 0 ;
* V_100 = * V_1 ;
V_108 = & V_100 -> V_34 ;
V_108 -> V_119 = V_98 -> V_118 ;
V_108 -> V_62 = V_99 + 1 ;
V_108 -> V_117 =
F_33 ( V_101 ,
V_108 -> V_62 * V_121 *
V_108 -> V_35 * V_108 -> V_119 ) ;
V_108 -> V_60 = V_108 -> V_117 ;
F_60 ( V_108 -> V_60 , V_108 -> V_119 ) ;
ASSERT ( V_108 -> V_60 != 0 ) ;
V_108 -> V_127 = F_28 ( V_108 -> V_60 ) ;
V_106 = V_100 -> V_61 = V_108 -> V_127 + 1 ;
V_107 =
( V_96 ) sizeof( T_12 ) * V_106 *
V_108 -> V_62 ;
V_105 = F_62 ( V_1 , V_107 ) ;
V_100 -> V_128 = V_107 = F_58 ( V_1 , V_105 ) ;
V_16 = F_2 ( V_1 , V_129 ) ;
if ( ( error = F_4 ( V_16 , 0 ,
F_64 ( V_100 ) , 0 , 0 , 0 ) ) )
goto V_20;
F_6 ( V_1 -> V_75 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_75 , V_22 ) ;
V_1 -> V_75 -> V_123 . V_124 =
V_108 -> V_62 * V_108 -> V_35 ;
F_65 ( V_16 , V_1 -> V_75 , V_130 ) ;
V_15 |= V_23 ;
F_6 ( V_1 -> V_74 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_74 , V_22 ) ;
V_1 -> V_74 -> V_123 . V_124 = V_100 -> V_128 ;
F_65 ( V_16 , V_1 -> V_74 , V_130 ) ;
if ( V_111 -> V_62 != V_108 -> V_62 ||
V_1 -> V_61 != V_100 -> V_61 ) {
error = F_66 ( V_1 , V_100 , V_16 ) ;
if ( error )
goto V_20;
}
if ( V_108 -> V_119 != V_111 -> V_119 )
F_67 ( V_16 , V_131 ,
V_108 -> V_119 - V_111 -> V_119 ) ;
if ( V_108 -> V_62 != V_111 -> V_62 )
F_67 ( V_16 , V_132 ,
V_108 -> V_62 - V_111 -> V_62 ) ;
if ( V_108 -> V_117 != V_111 -> V_117 )
F_67 ( V_16 , V_133 ,
V_108 -> V_117 - V_111 -> V_117 ) ;
if ( V_108 -> V_60 != V_111 -> V_60 )
F_67 ( V_16 , V_134 ,
V_108 -> V_60 - V_111 -> V_60 ) ;
if ( V_108 -> V_127 != V_111 -> V_127 )
F_67 ( V_16 , V_135 ,
V_108 -> V_127 - V_111 -> V_127 ) ;
V_6 = NULL ;
error = F_49 ( V_100 , V_16 , V_111 -> V_60 ,
V_108 -> V_60 - V_111 -> V_60 , & V_6 , & V_112 ) ;
if ( error ) {
V_20:
F_16 ( V_16 , V_15 ) ;
break;
}
F_67 ( V_16 , V_136 ,
V_108 -> V_60 - V_111 -> V_60 ) ;
V_1 -> V_61 = V_106 ;
V_1 -> V_128 = V_107 ;
error = F_12 ( V_16 , 0 ) ;
if ( error )
break;
}
F_68 ( V_100 ) ;
return error ;
}
int
F_69 (
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
T_7 V_92 ;
T_5 * V_139 ;
ASSERT ( F_70 ( V_1 -> V_75 , V_22 ) ) ;
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
error = F_30 ( V_1 , V_16 , V_37 , V_38 , V_39 ,
& V_139 , & V_92 , V_43 , & V_59 ) ;
break;
case V_141 :
error = F_26 ( V_1 , V_16 , V_5 , V_37 , V_38 ,
V_39 , & V_139 , & V_92 , V_43 , & V_59 ) ;
break;
case V_142 :
error = F_25 ( V_1 , V_16 , V_5 , V_37 , V_38 ,
V_39 , & V_139 , & V_92 , V_43 , & V_59 ) ;
break;
default:
error = V_33 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_59 != V_53 ) {
long V_143 = ( long ) * V_39 ;
ASSERT ( * V_39 >= V_37 && * V_39 <= V_38 ) ;
if ( V_137 )
F_67 ( V_16 , V_144 , - V_143 ) ;
else
F_67 ( V_16 , V_136 , - V_143 ) ;
}
* V_44 = V_59 ;
return 0 ;
}
int
F_71 (
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_39 )
{
int error ;
T_1 * V_1 ;
T_7 V_92 ;
T_5 * V_139 ;
V_1 = V_16 -> V_138 ;
F_6 ( V_1 -> V_75 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_75 , V_22 ) ;
#if F_72 ( V_145 ) && F_72 ( V_146 )
{
int V_50 ;
error = F_42 ( V_1 , V_16 , V_5 , V_39 , & V_50 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_50 ) ;
}
#endif
V_139 = NULL ;
error = F_49 ( V_1 , V_16 , V_5 , V_39 , & V_139 , & V_92 ) ;
if ( error ) {
return error ;
}
F_67 ( V_16 , V_136 , ( long ) V_39 ) ;
if ( V_16 -> V_147 + V_1 -> V_34 . V_148 ==
V_1 -> V_34 . V_60 ) {
if ( ! ( V_1 -> V_75 -> V_123 . V_149 & V_150 ) )
V_1 -> V_75 -> V_123 . V_149 |= V_150 ;
* ( V_151 * ) & V_1 -> V_75 -> V_123 . V_152 = 0 ;
F_65 ( V_16 , V_1 -> V_75 , V_130 ) ;
}
return 0 ;
}
int
F_73 (
T_1 * V_1 )
{
T_5 * V_6 ;
T_6 V_8 ;
T_18 * V_111 ;
V_111 = & V_1 -> V_34 ;
if ( V_111 -> V_117 == 0 )
return 0 ;
if ( V_1 -> V_115 == NULL ) {
F_74 ( V_1 ,
L_1 ) ;
return F_10 ( V_153 ) ;
}
V_1 -> V_61 = V_111 -> V_127 + 1 ;
V_1 -> V_128 =
( V_96 ) sizeof( T_12 ) * V_1 -> V_61 *
V_111 -> V_62 ;
V_1 -> V_128 = F_75 ( V_1 -> V_128 , V_111 -> V_35 ) ;
V_1 -> V_75 = V_1 -> V_74 = NULL ;
V_8 = ( T_6 ) F_57 ( V_1 , V_1 -> V_34 . V_117 ) ;
if ( F_76 ( V_1 , V_8 ) != V_1 -> V_34 . V_117 ) {
F_74 ( V_1 , L_2 ,
( unsigned long long ) F_76 ( V_1 , V_8 ) ,
( unsigned long long ) V_1 -> V_34 . V_117 ) ;
return F_10 ( V_154 ) ;
}
V_6 = F_56 ( V_1 , V_1 -> V_115 ,
V_8 - F_57 ( V_1 , 1 ) ,
F_58 ( V_1 , 1 ) , 0 ) ;
if ( ! V_6 ) {
F_74 ( V_1 , L_3 ) ;
return V_33 ;
}
F_59 ( V_6 ) ;
return 0 ;
}
int
F_77 (
T_1 * V_1 )
{
int error ;
T_18 * V_111 ;
V_111 = & V_1 -> V_34 ;
if ( V_111 -> V_155 == V_156 )
return 0 ;
error = F_78 ( V_1 , NULL , V_111 -> V_155 , 0 , 0 , & V_1 -> V_75 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_75 != NULL ) ;
ASSERT ( V_111 -> V_157 != V_156 ) ;
error = F_78 ( V_1 , NULL , V_111 -> V_157 , 0 , 0 , & V_1 -> V_74 ) ;
if ( error ) {
F_79 ( V_1 -> V_75 ) ;
return error ;
}
ASSERT ( V_1 -> V_74 != NULL ) ;
return 0 ;
}
void
F_80 (
struct V_158 * V_1 )
{
if ( V_1 -> V_75 )
F_79 ( V_1 -> V_75 ) ;
if ( V_1 -> V_74 )
F_79 ( V_1 -> V_74 ) ;
}
int
F_81 (
T_1 * V_1 ,
T_10 * V_16 ,
T_2 V_39 ,
T_11 * V_159 )
{
T_11 V_80 ;
int V_160 ;
V_151 V_161 ;
V_151 V_162 ;
V_151 * V_163 ;
ASSERT ( F_70 ( V_1 -> V_75 , V_22 ) ) ;
V_163 = ( V_151 * ) & V_1 -> V_75 -> V_123 . V_152 ;
if ( ! ( V_1 -> V_75 -> V_123 . V_149 & V_150 ) ) {
V_1 -> V_75 -> V_123 . V_149 |= V_150 ;
* V_163 = 0 ;
}
V_162 = * V_163 ;
if ( ( V_160 = F_82 ( V_162 ) ) == - 1 )
V_80 = 0 ;
else {
V_161 = V_162 - ( 1ULL << V_160 ) ;
V_80 = ( V_1 -> V_34 . V_60 * ( ( V_161 << 1 ) + 1ULL ) ) >>
( V_160 + 1 ) ;
if ( V_80 >= V_1 -> V_34 . V_60 )
V_80 = F_24 ( V_80 , V_1 -> V_34 . V_60 ) ;
if ( V_80 + V_39 > V_1 -> V_34 . V_60 )
V_80 = V_1 -> V_34 . V_60 - V_39 ;
}
* V_163 = V_162 + 1 ;
F_65 ( V_16 , V_1 -> V_75 , V_130 ) ;
* V_159 = V_80 ;
return 0 ;
}
