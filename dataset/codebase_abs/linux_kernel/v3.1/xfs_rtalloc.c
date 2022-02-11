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
memset ( V_6 -> V_34 , 0 , V_1 -> V_35 . V_36 ) ;
F_17 ( V_16 , V_6 , 0 , V_1 -> V_35 . V_36 - 1 ) ;
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
F_18 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_37 ,
T_2 V_38 ,
T_2 V_39 ,
T_2 * V_40 ,
T_11 * V_41 ,
T_5 * * V_42 ,
T_7 * V_43 ,
T_2 V_44 ,
T_11 * V_45 )
{
T_11 V_46 ;
T_11 V_47 ;
T_11 V_48 ;
int error ;
T_11 V_49 ;
T_11 V_50 ;
int V_51 ;
for ( V_49 = F_19 ( V_1 , V_37 ) , V_46 = - 1 , V_47 = 0 ,
V_48 = F_19 ( V_1 , V_37 + 1 ) - 1 ;
V_49 <= V_48 ;
V_49 ++ ) {
error = F_20 ( V_1 , V_16 , V_49 , V_39 , 1 , & V_50 , & V_51 ) ;
if ( error ) {
return error ;
}
if ( V_51 ) {
error = F_21 ( V_1 , V_16 , V_49 , V_39 , V_42 ,
V_43 ) ;
if ( error ) {
return error ;
}
* V_40 = V_39 ;
* V_45 = V_49 ;
return 0 ;
}
if ( V_38 < V_39 ) {
T_11 V_52 ;
V_52 = V_50 - V_49 ;
if ( V_52 >= V_38 && V_52 > V_47 ) {
V_46 = V_49 ;
V_47 = V_52 ;
}
}
if ( V_50 < V_48 ) {
error = F_22 ( V_1 , V_16 , V_50 , V_48 , & V_49 ) ;
if ( error ) {
return error ;
}
} else
break;
}
if ( V_38 < V_39 && V_46 != - 1 ) {
T_2 V_53 ;
if ( V_44 > 1 && ( V_53 = F_23 ( V_47 , V_44 ) ) )
V_47 -= V_53 ;
error = F_21 ( V_1 , V_16 , V_46 , V_47 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
* V_40 = V_47 ;
* V_45 = V_46 ;
return 0 ;
}
* V_41 = V_50 ;
* V_45 = V_54 ;
return 0 ;
}
STATIC int
F_24 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_38 ,
T_2 V_39 ,
T_2 * V_40 ,
T_5 * * V_42 ,
T_7 * V_43 ,
T_2 V_44 ,
T_11 * V_45 )
{
int error ;
T_2 V_49 ;
int V_55 ;
T_11 V_50 ;
ASSERT ( V_38 % V_44 == 0 && V_39 % V_44 == 0 ) ;
error = F_20 ( V_1 , V_16 , V_5 , V_39 , 1 , & V_50 , & V_55 ) ;
if ( error ) {
return error ;
}
if ( V_55 ) {
error = F_21 ( V_1 , V_16 , V_5 , V_39 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
* V_40 = V_39 ;
* V_45 = V_5 ;
return 0 ;
}
V_39 = V_50 - V_5 ;
if ( V_39 < V_38 ) {
* V_45 = V_54 ;
return 0 ;
}
if ( V_44 > 1 && ( V_49 = V_39 % V_44 ) ) {
V_39 -= V_49 ;
if ( V_39 < V_38 ) {
* V_45 = V_54 ;
return 0 ;
}
}
error = F_21 ( V_1 , V_16 , V_5 , V_39 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
* V_40 = V_39 ;
* V_45 = V_5 ;
return 0 ;
}
STATIC int
F_25 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_38 ,
T_2 V_39 ,
T_2 * V_40 ,
T_5 * * V_42 ,
T_7 * V_43 ,
T_2 V_44 ,
T_11 * V_45 )
{
int V_56 ;
T_11 V_37 ;
int error ;
int V_49 ;
int V_57 ;
int V_58 ;
T_11 V_59 ;
T_11 V_60 ;
ASSERT ( V_38 % V_44 == 0 && V_39 % V_44 == 0 ) ;
if ( V_5 >= V_1 -> V_35 . V_61 )
V_5 = V_1 -> V_35 . V_61 - 1 ;
error = F_24 ( V_1 , V_16 , V_5 , V_38 , V_39 , V_40 ,
V_42 , V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
V_37 = F_26 ( V_1 , V_5 ) ;
V_49 = 0 ;
ASSERT ( V_38 != 0 ) ;
V_58 = F_27 ( V_38 ) ;
for (; ; ) {
error = F_28 ( V_1 , V_16 , V_58 , V_1 -> V_62 - 1 ,
V_37 + V_49 , V_42 , V_43 , & V_56 ) ;
if ( error ) {
return error ;
}
if ( V_56 ) {
if ( V_49 >= 0 ) {
error = F_18 ( V_1 , V_16 ,
V_37 + V_49 , V_38 , V_39 , V_40 , & V_59 , V_42 ,
V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
}
else {
for ( V_57 = - 1 ; V_57 > V_49 ; V_57 -- ) {
error = F_28 ( V_1 , V_16 ,
V_58 , V_1 -> V_62 - 1 ,
V_37 + V_57 , V_42 , V_43 , & V_56 ) ;
if ( error ) {
return error ;
}
if ( V_56 )
continue;
error = F_18 ( V_1 ,
V_16 , V_37 + V_57 , V_38 , V_39 ,
V_40 , & V_59 , V_42 , V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
}
error = F_18 ( V_1 , V_16 ,
V_37 + V_49 , V_38 , V_39 , V_40 , & V_59 , V_42 ,
V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
}
}
if ( V_49 > 0 && ( int ) V_37 - V_49 >= 0 )
V_49 = - V_49 ;
else if ( V_49 > 0 && ( int ) V_37 + V_49 < V_1 -> V_35 . V_63 - 1 )
V_49 ++ ;
else if ( V_49 <= 0 && ( int ) V_37 - V_49 < V_1 -> V_35 . V_63 - 1 )
V_49 = 1 - V_49 ;
else if ( V_49 <= 0 && ( int ) V_37 + V_49 > 0 )
V_49 -- ;
else
break;
}
* V_45 = V_54 ;
return 0 ;
}
STATIC int
F_29 (
T_1 * V_1 ,
T_10 * V_16 ,
T_2 V_38 ,
T_2 V_39 ,
T_2 * V_40 ,
T_5 * * V_42 ,
T_7 * V_43 ,
T_2 V_44 ,
T_11 * V_45 )
{
int error ;
int V_49 ;
int V_64 ;
T_11 V_59 ;
T_11 V_60 ;
T_12 V_65 ;
ASSERT ( V_38 % V_44 == 0 && V_39 % V_44 == 0 ) ;
ASSERT ( V_39 != 0 ) ;
for ( V_64 = F_27 ( V_39 ) ; V_64 < V_1 -> V_62 ; V_64 ++ ) {
for ( V_49 = 0 ; V_49 < V_1 -> V_35 . V_63 ; V_49 ++ ) {
error = F_30 ( V_1 , V_16 , V_64 , V_49 , V_42 , V_43 ,
& V_65 ) ;
if ( error ) {
return error ;
}
if ( ! V_65 )
continue;
error = F_18 ( V_1 , V_16 , V_49 , V_39 ,
V_39 , V_40 , & V_59 , V_42 , V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
if ( F_26 ( V_1 , V_59 ) > V_49 + 1 )
V_49 = F_26 ( V_1 , V_59 ) - 1 ;
}
}
if ( V_38 > -- V_39 ) {
* V_45 = V_54 ;
return 0 ;
}
ASSERT ( V_38 != 0 ) ;
ASSERT ( V_39 != 0 ) ;
for ( V_64 = F_27 ( V_39 ) ; V_64 >= F_27 ( V_38 ) ; V_64 -- ) {
for ( V_49 = 0 ; V_49 < V_1 -> V_35 . V_63 ; V_49 ++ ) {
error = F_30 ( V_1 , V_16 , V_64 , V_49 , V_42 , V_43 ,
& V_65 ) ;
if ( error ) {
return error ;
}
if ( ! V_65 )
continue;
error = F_18 ( V_1 , V_16 , V_49 ,
F_31 ( V_38 , 1 << V_64 ) ,
F_32 ( V_39 , ( 1 << ( V_64 + 1 ) ) - 1 ) ,
V_40 , & V_59 , V_42 , V_43 , V_44 , & V_60 ) ;
if ( error ) {
return error ;
}
if ( V_60 != V_54 ) {
* V_45 = V_60 ;
return 0 ;
}
if ( F_26 ( V_1 , V_59 ) > V_49 + 1 )
V_49 = F_26 ( V_1 , V_59 ) - 1 ;
}
}
* V_45 = V_54 ;
return 0 ;
}
STATIC int
F_21 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_2 V_40 ,
T_5 * * V_42 ,
T_7 * V_43 )
{
T_11 V_48 ;
int error ;
T_11 V_67 ;
T_11 V_68 ;
V_48 = V_66 + V_40 - 1 ;
error = F_33 ( V_1 , V_16 , V_66 , 0 , & V_68 ) ;
if ( error ) {
return error ;
}
error = F_22 ( V_1 , V_16 , V_48 , V_1 -> V_35 . V_61 - 1 ,
& V_67 ) ;
if ( error ) {
return error ;
}
error = F_34 ( V_1 , V_16 ,
F_35 ( V_67 + 1 - V_68 ) ,
F_26 ( V_1 , V_68 ) , - 1 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
if ( V_68 < V_66 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 - V_68 ) ,
F_26 ( V_1 , V_68 ) , 1 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
}
if ( V_67 > V_48 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_67 - V_48 ) ,
F_26 ( V_1 , V_48 + 1 ) , 1 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
}
error = F_36 ( V_1 , V_16 , V_66 , V_40 , 0 ) ;
return error ;
}
STATIC int
F_28 (
T_1 * V_1 ,
T_10 * V_16 ,
int V_69 ,
int V_70 ,
T_11 V_37 ,
T_5 * * V_42 ,
T_7 * V_43 ,
int * V_51 )
{
int error ;
int log ;
T_12 V_65 ;
for ( log = V_69 ; log <= V_70 ; log ++ ) {
error = F_30 ( V_1 , V_16 , log , V_37 , V_42 , V_43 , & V_65 ) ;
if ( error ) {
return error ;
}
if ( V_65 ) {
* V_51 = 1 ;
return 0 ;
}
}
* V_51 = 0 ;
return 0 ;
}
STATIC int
F_37 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_71 ,
int V_72 ,
T_5 * * V_73 )
{
T_5 * V_6 ;
T_6 V_8 ;
int error ;
T_7 V_74 ;
T_3 * V_4 ;
V_4 = V_72 ? V_1 -> V_75 : V_1 -> V_76 ;
error = F_38 ( V_16 , V_4 , V_77 , & V_74 , V_71 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_74 != V_78 ) ;
V_8 = F_14 ( V_1 , V_74 ) ;
error = F_39 ( V_1 , V_16 , V_1 -> V_31 , V_8 ,
V_1 -> V_32 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
ASSERT ( ! F_40 ( V_6 ) ) ;
* V_73 = V_6 ;
return 0 ;
}
STATIC int
F_41 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_40 ,
int * V_51 )
{
T_11 V_79 ;
return F_20 ( V_1 , V_16 , V_5 , V_40 , 0 , & V_79 , V_51 ) ;
}
STATIC int
F_20 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_2 V_40 ,
int V_80 ,
T_11 * V_79 ,
int * V_51 )
{
T_13 * V_81 ;
int V_82 ;
T_11 V_71 ;
T_5 * V_6 ;
T_13 * V_83 ;
int error ;
T_11 V_49 ;
T_11 V_84 ;
T_13 V_85 ;
T_13 V_86 ;
int V_87 ;
V_71 = F_26 ( V_1 , V_66 ) ;
error = F_37 ( V_1 , V_16 , V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_42 ( V_1 , V_66 ) ;
V_81 = & V_83 [ V_87 ] ;
V_82 = ( int ) ( V_66 & ( V_88 - 1 ) ) ;
V_80 = - V_80 ;
if ( V_82 ) {
V_84 = F_32 ( V_82 + V_40 , V_88 ) ;
V_85 = ( ( ( T_13 ) 1 << ( V_84 - V_82 ) ) - 1 ) << V_82 ;
if ( ( V_86 = ( * V_81 ^ V_80 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 = F_44 ( V_86 ) - V_82 ;
* V_79 = V_66 + V_49 ;
* V_51 = 0 ;
return 0 ;
}
V_49 = V_84 - V_82 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
} else {
V_49 = 0 ;
}
while ( V_40 - V_49 >= V_88 ) {
if ( ( V_86 = * V_81 ^ V_80 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += F_44 ( V_86 ) ;
* V_79 = V_66 + V_49 ;
* V_51 = 0 ;
return 0 ;
}
V_49 += V_88 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
}
if ( ( V_84 = V_40 - V_49 ) ) {
V_85 = ( ( T_13 ) 1 << V_84 ) - 1 ;
if ( ( V_86 = ( * V_81 ^ V_80 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += F_44 ( V_86 ) ;
* V_79 = V_66 + V_49 ;
* V_51 = 0 ;
return 0 ;
} else
V_49 = V_40 ;
}
F_43 ( V_16 , V_6 ) ;
* V_79 = V_66 + V_49 ;
* V_51 = 1 ;
return 0 ;
}
STATIC int
F_33 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_11 V_89 ,
T_11 * V_45 )
{
T_13 * V_81 ;
int V_82 ;
T_11 V_71 ;
T_5 * V_6 ;
T_13 * V_83 ;
int error ;
T_11 V_90 ;
T_11 V_49 ;
T_11 V_40 ;
T_13 V_85 ;
T_13 V_91 ;
T_13 V_86 ;
int V_87 ;
V_71 = F_26 ( V_1 , V_66 ) ;
error = F_37 ( V_1 , V_16 , V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_42 ( V_1 , V_66 ) ;
V_81 = & V_83 [ V_87 ] ;
V_82 = ( int ) ( V_66 & ( V_88 - 1 ) ) ;
V_40 = V_66 - V_89 + 1 ;
V_91 = ( * V_81 & ( ( T_13 ) 1 << V_82 ) ) ? - 1 : 0 ;
if ( V_82 < V_88 - 1 ) {
V_90 = F_31 ( ( V_92 ) ( V_82 - V_40 + 1 ) , 0 ) ;
V_85 = ( ( ( T_13 ) 1 << ( V_82 - V_90 + 1 ) ) - 1 ) <<
V_90 ;
if ( ( V_86 = ( * V_81 ^ V_91 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 = V_82 - F_46 ( V_86 ) ;
* V_45 = V_66 - V_49 + 1 ;
return 0 ;
}
V_49 = V_82 - V_90 + 1 ;
if ( -- V_87 == - 1 && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , -- V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_47 ( V_1 ) ;
V_81 = & V_83 [ V_87 ] ;
} else {
V_81 -- ;
}
} else {
V_49 = 0 ;
}
while ( V_40 - V_49 >= V_88 ) {
if ( ( V_86 = * V_81 ^ V_91 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += V_88 - 1 - F_46 ( V_86 ) ;
* V_45 = V_66 - V_49 + 1 ;
return 0 ;
}
V_49 += V_88 ;
if ( -- V_87 == - 1 && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , -- V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_47 ( V_1 ) ;
V_81 = & V_83 [ V_87 ] ;
} else {
V_81 -- ;
}
}
if ( V_40 - V_49 ) {
V_90 = V_88 - ( V_40 - V_49 ) ;
V_85 = ( ( ( T_13 ) 1 << ( V_40 - V_49 ) ) - 1 ) << V_90 ;
if ( ( V_86 = ( * V_81 ^ V_91 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += V_88 - 1 - F_46 ( V_86 ) ;
* V_45 = V_66 - V_49 + 1 ;
return 0 ;
} else
V_49 = V_40 ;
}
F_43 ( V_16 , V_6 ) ;
* V_45 = V_66 - V_49 + 1 ;
return 0 ;
}
STATIC int
F_22 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_11 V_89 ,
T_11 * V_45 )
{
T_13 * V_81 ;
int V_82 ;
T_11 V_71 ;
T_5 * V_6 ;
T_13 * V_83 ;
int error ;
T_11 V_49 ;
T_11 V_84 ;
T_11 V_40 ;
T_13 V_85 ;
T_13 V_91 ;
T_13 V_86 ;
int V_87 ;
V_71 = F_26 ( V_1 , V_66 ) ;
error = F_37 ( V_1 , V_16 , V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_42 ( V_1 , V_66 ) ;
V_81 = & V_83 [ V_87 ] ;
V_82 = ( int ) ( V_66 & ( V_88 - 1 ) ) ;
V_40 = V_89 - V_66 + 1 ;
V_91 = ( * V_81 & ( ( T_13 ) 1 << V_82 ) ) ? - 1 : 0 ;
if ( V_82 ) {
V_84 = F_32 ( V_82 + V_40 , V_88 ) ;
V_85 = ( ( ( T_13 ) 1 << ( V_84 - V_82 ) ) - 1 ) << V_82 ;
if ( ( V_86 = ( * V_81 ^ V_91 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 = F_44 ( V_86 ) - V_82 ;
* V_45 = V_66 + V_49 - 1 ;
return 0 ;
}
V_49 = V_84 - V_82 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
} else {
V_49 = 0 ;
}
while ( V_40 - V_49 >= V_88 ) {
if ( ( V_86 = * V_81 ^ V_91 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += F_44 ( V_86 ) ;
* V_45 = V_66 + V_49 - 1 ;
return 0 ;
}
V_49 += V_88 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_43 ( V_16 , V_6 ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
}
if ( ( V_84 = V_40 - V_49 ) ) {
V_85 = ( ( T_13 ) 1 << V_84 ) - 1 ;
if ( ( V_86 = ( * V_81 ^ V_91 ) & V_85 ) ) {
F_43 ( V_16 , V_6 ) ;
V_49 += F_44 ( V_86 ) ;
* V_45 = V_66 + V_49 - 1 ;
return 0 ;
} else
V_49 = V_40 ;
}
F_43 ( V_16 , V_6 ) ;
* V_45 = V_66 + V_49 - 1 ;
return 0 ;
}
STATIC int
F_48 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_2 V_40 ,
T_5 * * V_42 ,
T_7 * V_43 )
{
T_11 V_48 ;
int error ;
T_11 V_67 ;
T_11 V_68 ;
V_48 = V_66 + V_40 - 1 ;
error = F_36 ( V_1 , V_16 , V_66 , V_40 , 1 ) ;
if ( error ) {
return error ;
}
error = F_33 ( V_1 , V_16 , V_66 , 0 , & V_68 ) ;
if ( error ) {
return error ;
}
error = F_22 ( V_1 , V_16 , V_48 , V_1 -> V_35 . V_61 - 1 ,
& V_67 ) ;
if ( error )
return error ;
if ( V_68 < V_66 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_66 - V_68 ) ,
F_26 ( V_1 , V_68 ) , - 1 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
}
if ( V_67 > V_48 ) {
error = F_34 ( V_1 , V_16 ,
F_35 ( V_67 - V_48 ) ,
F_26 ( V_1 , V_48 + 1 ) , - 1 , V_42 , V_43 ) ;
if ( error ) {
return error ;
}
}
error = F_34 ( V_1 , V_16 ,
F_35 ( V_67 + 1 - V_68 ) ,
F_26 ( V_1 , V_68 ) , 1 , V_42 , V_43 ) ;
return error ;
}
STATIC int
F_30 (
T_1 * V_1 ,
T_10 * V_16 ,
int log ,
T_11 V_37 ,
T_5 * * V_42 ,
T_7 * V_43 ,
T_12 * V_65 )
{
T_5 * V_6 ;
int error ;
T_7 V_93 ;
int V_94 ;
T_12 * V_95 ;
V_94 = F_49 ( V_1 , log , V_37 ) ;
V_93 = F_50 ( V_1 , V_94 ) ;
if ( V_42 && * V_42 && * V_43 == V_93 )
V_6 = * V_42 ;
else {
if ( V_42 && * V_42 )
F_43 ( V_16 , * V_42 ) ;
error = F_37 ( V_1 , V_16 , V_93 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_42 ) {
* V_42 = V_6 ;
* V_43 = V_93 ;
}
}
V_95 = F_51 ( V_1 , V_6 , V_94 ) ;
* V_65 = * V_95 ;
if ( ! V_42 )
F_43 ( V_16 , V_6 ) ;
return 0 ;
}
STATIC int
F_36 (
T_1 * V_1 ,
T_10 * V_16 ,
T_11 V_66 ,
T_2 V_40 ,
int V_80 )
{
T_13 * V_81 ;
int V_82 ;
T_11 V_71 ;
T_5 * V_6 ;
T_13 * V_83 ;
int error ;
T_13 * V_96 ;
int V_49 ;
int V_84 ;
T_13 V_85 ;
int V_87 ;
V_71 = F_26 ( V_1 , V_66 ) ;
error = F_37 ( V_1 , V_16 , V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_83 = V_6 -> V_34 ;
V_87 = F_42 ( V_1 , V_66 ) ;
V_96 = V_81 = & V_83 [ V_87 ] ;
V_82 = ( int ) ( V_66 & ( V_88 - 1 ) ) ;
V_80 = - V_80 ;
if ( V_82 ) {
V_84 = F_32 ( V_82 + V_40 , V_88 ) ;
V_85 = ( ( ( T_13 ) 1 << ( V_84 - V_82 ) ) - 1 ) << V_82 ;
if ( V_80 )
* V_81 |= V_85 ;
else
* V_81 &= ~ V_85 ;
V_49 = V_84 - V_82 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_17 ( V_16 , V_6 ,
( V_97 ) ( ( char * ) V_96 - ( char * ) V_83 ) ,
( V_97 ) ( ( char * ) V_81 - ( char * ) V_83 ) ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_96 = V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
} else {
V_49 = 0 ;
}
while ( V_40 - V_49 >= V_88 ) {
* V_81 = V_80 ;
V_49 += V_88 ;
if ( ++ V_87 == F_45 ( V_1 ) && V_49 < V_40 ) {
F_17 ( V_16 , V_6 ,
( V_97 ) ( ( char * ) V_96 - ( char * ) V_83 ) ,
( V_97 ) ( ( char * ) V_81 - ( char * ) V_83 ) ) ;
error = F_37 ( V_1 , V_16 , ++ V_71 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_96 = V_81 = V_83 = V_6 -> V_34 ;
V_87 = 0 ;
} else {
V_81 ++ ;
}
}
if ( ( V_84 = V_40 - V_49 ) ) {
V_82 = 0 ;
V_85 = ( ( T_13 ) 1 << V_84 ) - 1 ;
if ( V_80 )
* V_81 |= V_85 ;
else
* V_81 &= ~ V_85 ;
V_81 ++ ;
}
if ( V_81 > V_96 )
F_17 ( V_16 , V_6 , ( V_97 ) ( ( char * ) V_96 - ( char * ) V_83 ) ,
( V_97 ) ( ( char * ) V_81 - ( char * ) V_83 - 1 ) ) ;
return 0 ;
}
STATIC int
F_34 (
T_1 * V_1 ,
T_10 * V_16 ,
int log ,
T_11 V_37 ,
int V_98 ,
T_5 * * V_42 ,
T_7 * V_43 )
{
T_5 * V_6 ;
int error ;
T_7 V_93 ;
int V_94 ;
T_12 * V_95 ;
V_94 = F_49 ( V_1 , log , V_37 ) ;
V_93 = F_50 ( V_1 , V_94 ) ;
if ( V_42 && * V_42 && * V_43 == V_93 )
V_6 = * V_42 ;
else {
if ( V_42 && * V_42 )
F_43 ( V_16 , * V_42 ) ;
error = F_37 ( V_1 , V_16 , V_93 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_42 ) {
* V_42 = V_6 ;
* V_43 = V_93 ;
}
}
V_95 = F_51 ( V_1 , V_6 , V_94 ) ;
* V_95 += V_98 ;
F_17 ( V_16 , V_6 , ( V_97 ) ( ( char * ) V_95 - ( char * ) V_6 -> V_34 ) ,
( V_97 ) ( ( char * ) V_95 - ( char * ) V_6 -> V_34 + sizeof( * V_95 ) - 1 ) ) ;
return 0 ;
}
int
F_52 (
T_1 * V_1 ,
T_14 * V_99 )
{
T_11 V_100 ;
T_5 * V_6 ;
int error ;
T_1 * V_101 ;
T_15 V_102 ;
T_2 V_103 ;
T_16 V_104 ;
T_17 V_105 ;
T_2 V_106 ;
V_97 V_107 ;
V_97 V_108 ;
T_18 * V_109 ;
T_2 V_110 ;
T_2 V_111 ;
T_18 * V_112 ;
T_7 V_113 ;
V_112 = & V_1 -> V_35 ;
if ( ! F_53 ( V_114 ) )
return F_10 ( V_115 ) ;
if ( V_1 -> V_116 == NULL || V_1 -> V_76 == NULL ||
( V_102 = V_99 -> V_117 ) <= V_112 -> V_118 ||
( V_112 -> V_118 && ( V_99 -> V_119 != V_112 -> V_120 ) ) )
return F_10 ( V_121 ) ;
if ( ( error = F_54 ( V_112 , V_102 ) ) )
return error ;
V_6 = F_55 ( V_1 , V_1 -> V_116 ,
F_56 ( V_1 , V_102 - 1 ) ,
F_57 ( V_1 , 1 ) , 0 ) ;
if ( ! V_6 )
return V_33 ;
F_58 ( V_6 ) ;
V_104 = V_102 ;
F_59 ( V_104 , V_99 -> V_119 ) ;
V_103 = F_60 ( V_104 , V_122 * V_112 -> V_36 ) ;
V_105 = F_27 ( V_104 ) ;
V_107 = V_105 + 1 ;
V_108 = ( V_97 ) sizeof( T_12 ) * V_107 * V_103 ;
V_106 = F_61 ( V_1 , V_108 ) ;
V_108 = F_57 ( V_1 , V_106 ) ;
if ( V_106 > ( V_1 -> V_35 . V_123 >> 1 ) )
return F_10 ( V_121 ) ;
V_110 = F_61 ( V_1 , V_1 -> V_76 -> V_124 . V_125 ) ;
V_111 = F_61 ( V_1 , V_1 -> V_75 -> V_124 . V_125 ) ;
error = F_1 ( V_1 , V_110 , V_103 , V_1 -> V_76 ) ;
if ( error )
return error ;
error = F_1 ( V_1 , V_111 , V_106 , V_1 -> V_75 ) ;
if ( error )
return error ;
V_101 = F_62 ( sizeof( * V_101 ) , V_126 ) ;
for ( V_100 = V_112 -> V_63 -
( ( V_112 -> V_61 & ( ( 1 << V_1 -> V_127 ) - 1 ) ) != 0 ) ;
V_100 < V_103 ;
V_100 ++ ) {
T_10 * V_16 ;
int V_15 = 0 ;
* V_101 = * V_1 ;
V_109 = & V_101 -> V_35 ;
V_109 -> V_120 = V_99 -> V_119 ;
V_109 -> V_63 = V_100 + 1 ;
V_109 -> V_118 =
F_32 ( V_102 ,
V_109 -> V_63 * V_122 *
V_109 -> V_36 * V_109 -> V_120 ) ;
V_109 -> V_61 = V_109 -> V_118 ;
F_59 ( V_109 -> V_61 , V_109 -> V_120 ) ;
ASSERT ( V_109 -> V_61 != 0 ) ;
V_109 -> V_128 = F_27 ( V_109 -> V_61 ) ;
V_107 = V_101 -> V_62 = V_109 -> V_128 + 1 ;
V_108 =
( V_97 ) sizeof( T_12 ) * V_107 *
V_109 -> V_63 ;
V_106 = F_61 ( V_1 , V_108 ) ;
V_101 -> V_129 = V_108 = F_57 ( V_1 , V_106 ) ;
V_16 = F_2 ( V_1 , V_130 ) ;
if ( ( error = F_4 ( V_16 , 0 ,
F_63 ( V_101 ) , 0 , 0 , 0 ) ) )
goto V_20;
F_6 ( V_1 -> V_76 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_76 , V_22 ) ;
V_1 -> V_76 -> V_124 . V_125 =
V_109 -> V_63 * V_109 -> V_36 ;
F_64 ( V_16 , V_1 -> V_76 , V_131 ) ;
V_15 |= V_23 ;
F_6 ( V_1 -> V_75 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_75 , V_22 ) ;
V_1 -> V_75 -> V_124 . V_125 = V_101 -> V_129 ;
F_64 ( V_16 , V_1 -> V_75 , V_131 ) ;
if ( V_112 -> V_63 != V_109 -> V_63 ||
V_1 -> V_62 != V_101 -> V_62 ) {
error = F_65 ( V_1 , V_101 , V_16 ) ;
if ( error )
goto V_20;
}
if ( V_109 -> V_120 != V_112 -> V_120 )
F_66 ( V_16 , V_132 ,
V_109 -> V_120 - V_112 -> V_120 ) ;
if ( V_109 -> V_63 != V_112 -> V_63 )
F_66 ( V_16 , V_133 ,
V_109 -> V_63 - V_112 -> V_63 ) ;
if ( V_109 -> V_118 != V_112 -> V_118 )
F_66 ( V_16 , V_134 ,
V_109 -> V_118 - V_112 -> V_118 ) ;
if ( V_109 -> V_61 != V_112 -> V_61 )
F_66 ( V_16 , V_135 ,
V_109 -> V_61 - V_112 -> V_61 ) ;
if ( V_109 -> V_128 != V_112 -> V_128 )
F_66 ( V_16 , V_136 ,
V_109 -> V_128 - V_112 -> V_128 ) ;
V_6 = NULL ;
error = F_48 ( V_101 , V_16 , V_112 -> V_61 ,
V_109 -> V_61 - V_112 -> V_61 , & V_6 , & V_113 ) ;
if ( error ) {
V_20:
F_16 ( V_16 , V_15 ) ;
break;
}
F_66 ( V_16 , V_137 ,
V_109 -> V_61 - V_112 -> V_61 ) ;
V_1 -> V_62 = V_107 ;
V_1 -> V_129 = V_108 ;
error = F_12 ( V_16 , 0 ) ;
if ( error )
break;
}
F_67 ( V_101 ) ;
return error ;
}
int
F_68 (
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_38 ,
T_2 V_39 ,
T_2 * V_40 ,
T_19 type ,
int V_138 ,
T_2 V_44 ,
T_11 * V_45 )
{
T_1 * V_1 = V_16 -> V_139 ;
int error ;
T_11 V_60 ;
T_7 V_93 ;
T_5 * V_140 ;
ASSERT ( F_69 ( V_1 -> V_76 , V_22 ) ) ;
ASSERT ( V_38 > 0 && V_38 <= V_39 ) ;
if ( V_44 > 1 ) {
T_2 V_49 ;
if ( ( V_49 = V_39 % V_44 ) )
V_39 -= V_49 ;
if ( ( V_49 = V_38 % V_44 ) )
V_38 += V_44 - V_49 ;
if ( V_39 < V_38 ) {
* V_45 = V_54 ;
return 0 ;
}
}
V_140 = NULL ;
switch ( type ) {
case V_141 :
error = F_29 ( V_1 , V_16 , V_38 , V_39 , V_40 ,
& V_140 , & V_93 , V_44 , & V_60 ) ;
break;
case V_142 :
error = F_25 ( V_1 , V_16 , V_5 , V_38 , V_39 ,
V_40 , & V_140 , & V_93 , V_44 , & V_60 ) ;
break;
case V_143 :
error = F_24 ( V_1 , V_16 , V_5 , V_38 , V_39 ,
V_40 , & V_140 , & V_93 , V_44 , & V_60 ) ;
break;
default:
error = V_33 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_60 != V_54 ) {
long V_144 = ( long ) * V_40 ;
ASSERT ( * V_40 >= V_38 && * V_40 <= V_39 ) ;
if ( V_138 )
F_66 ( V_16 , V_145 , - V_144 ) ;
else
F_66 ( V_16 , V_137 , - V_144 ) ;
}
* V_45 = V_60 ;
return 0 ;
}
int
F_70 (
T_10 * V_16 ,
T_11 V_5 ,
T_2 V_40 )
{
int error ;
T_1 * V_1 ;
T_7 V_93 ;
T_5 * V_140 ;
V_1 = V_16 -> V_139 ;
F_6 ( V_1 -> V_76 , V_22 ) ;
F_7 ( V_16 , V_1 -> V_76 , V_22 ) ;
#if F_71 ( V_146 ) && F_71 ( V_147 )
{
int V_51 ;
error = F_41 ( V_1 , V_16 , V_5 , V_40 , & V_51 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_51 ) ;
}
#endif
V_140 = NULL ;
error = F_48 ( V_1 , V_16 , V_5 , V_40 , & V_140 , & V_93 ) ;
if ( error ) {
return error ;
}
F_66 ( V_16 , V_137 , ( long ) V_40 ) ;
if ( V_16 -> V_148 + V_1 -> V_35 . V_149 ==
V_1 -> V_35 . V_61 ) {
if ( ! ( V_1 -> V_76 -> V_124 . V_150 & V_151 ) )
V_1 -> V_76 -> V_124 . V_150 |= V_151 ;
* ( V_152 * ) & V_1 -> V_76 -> V_124 . V_153 = 0 ;
F_64 ( V_16 , V_1 -> V_76 , V_131 ) ;
}
return 0 ;
}
int
F_72 (
T_1 * V_1 )
{
T_5 * V_6 ;
T_6 V_8 ;
T_18 * V_112 ;
V_112 = & V_1 -> V_35 ;
if ( V_112 -> V_118 == 0 )
return 0 ;
if ( V_1 -> V_116 == NULL ) {
F_73 ( V_1 ,
L_1 ) ;
return F_10 ( V_154 ) ;
}
V_1 -> V_62 = V_112 -> V_128 + 1 ;
V_1 -> V_129 =
( V_97 ) sizeof( T_12 ) * V_1 -> V_62 *
V_112 -> V_63 ;
V_1 -> V_129 = F_74 ( V_1 -> V_129 , V_112 -> V_36 ) ;
V_1 -> V_76 = V_1 -> V_75 = NULL ;
V_8 = ( T_6 ) F_56 ( V_1 , V_1 -> V_35 . V_118 ) ;
if ( F_75 ( V_1 , V_8 ) != V_1 -> V_35 . V_118 ) {
F_73 ( V_1 , L_2 ,
( unsigned long long ) F_75 ( V_1 , V_8 ) ,
( unsigned long long ) V_1 -> V_35 . V_118 ) ;
return F_10 ( V_155 ) ;
}
V_6 = F_55 ( V_1 , V_1 -> V_116 ,
V_8 - F_56 ( V_1 , 1 ) ,
F_57 ( V_1 , 1 ) , 0 ) ;
if ( ! V_6 ) {
F_73 ( V_1 , L_3 ) ;
return V_33 ;
}
F_58 ( V_6 ) ;
return 0 ;
}
int
F_76 (
T_1 * V_1 )
{
int error ;
T_18 * V_112 ;
V_112 = & V_1 -> V_35 ;
if ( V_112 -> V_156 == V_157 )
return 0 ;
error = F_77 ( V_1 , NULL , V_112 -> V_156 , 0 , 0 , & V_1 -> V_76 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_76 != NULL ) ;
ASSERT ( V_112 -> V_158 != V_157 ) ;
error = F_77 ( V_1 , NULL , V_112 -> V_158 , 0 , 0 , & V_1 -> V_75 ) ;
if ( error ) {
F_78 ( V_1 -> V_76 ) ;
return error ;
}
ASSERT ( V_1 -> V_75 != NULL ) ;
return 0 ;
}
void
F_79 (
struct V_159 * V_1 )
{
if ( V_1 -> V_76 )
F_78 ( V_1 -> V_76 ) ;
if ( V_1 -> V_75 )
F_78 ( V_1 -> V_75 ) ;
}
int
F_80 (
T_1 * V_1 ,
T_10 * V_16 ,
T_2 V_40 ,
T_11 * V_160 )
{
T_11 V_81 ;
int V_161 ;
V_152 V_162 ;
V_152 V_163 ;
V_152 * V_164 ;
ASSERT ( F_69 ( V_1 -> V_76 , V_22 ) ) ;
V_164 = ( V_152 * ) & V_1 -> V_76 -> V_124 . V_153 ;
if ( ! ( V_1 -> V_76 -> V_124 . V_150 & V_151 ) ) {
V_1 -> V_76 -> V_124 . V_150 |= V_151 ;
* V_164 = 0 ;
}
V_163 = * V_164 ;
if ( ( V_161 = F_81 ( V_163 ) ) == - 1 )
V_81 = 0 ;
else {
V_162 = V_163 - ( 1ULL << V_161 ) ;
V_81 = ( V_1 -> V_35 . V_61 * ( ( V_162 << 1 ) + 1ULL ) ) >>
( V_161 + 1 ) ;
if ( V_81 >= V_1 -> V_35 . V_61 )
V_81 = F_23 ( V_81 , V_1 -> V_35 . V_61 ) ;
if ( V_81 + V_40 > V_1 -> V_35 . V_61 )
V_81 = V_1 -> V_35 . V_61 - V_40 ;
}
* V_164 = V_163 + 1 ;
F_64 ( V_16 , V_1 -> V_76 , V_131 ) ;
* V_160 = V_81 ;
return 0 ;
}
