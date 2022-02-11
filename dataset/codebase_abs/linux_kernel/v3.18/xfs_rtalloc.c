static int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
int log ,
T_3 V_3 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_6 * V_6 )
{
return F_2 ( V_1 , V_2 , log , V_3 , 0 , V_4 , V_5 , V_6 ) ;
}
STATIC int
F_3 (
T_1 * V_1 ,
T_2 * V_2 ,
int V_7 ,
int V_8 ,
T_3 V_3 ,
T_4 * * V_4 ,
T_5 * V_5 ,
int * V_9 )
{
int error ;
int log ;
T_6 V_6 ;
for ( log = V_7 ; log <= V_8 ; log ++ ) {
error = F_1 ( V_1 , V_2 , log , V_3 , V_4 , V_5 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_6 ) {
* V_9 = 1 ;
return 0 ;
}
}
* V_9 = 0 ;
return 0 ;
}
STATIC int
F_4 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_10 ,
T_7 V_11 ,
T_4 * * V_4 ,
T_5 * V_5 )
{
T_3 V_12 ;
int error ;
T_3 V_13 = 0 ;
T_3 V_14 = 0 ;
V_12 = V_10 + V_11 - 1 ;
error = F_5 ( V_1 , V_2 , V_10 , 0 , & V_14 ) ;
if ( error ) {
return error ;
}
error = F_6 ( V_1 , V_2 , V_12 , V_1 -> V_15 . V_16 - 1 ,
& V_13 ) ;
if ( error ) {
return error ;
}
error = F_7 ( V_1 , V_2 ,
F_8 ( V_13 + 1 - V_14 ) ,
F_9 ( V_1 , V_14 ) , - 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
if ( V_14 < V_10 ) {
error = F_7 ( V_1 , V_2 ,
F_8 ( V_10 - V_14 ) ,
F_9 ( V_1 , V_14 ) , 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
}
if ( V_13 > V_12 ) {
error = F_7 ( V_1 , V_2 ,
F_8 ( V_13 - V_12 ) ,
F_9 ( V_1 , V_12 + 1 ) , 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
}
error = F_10 ( V_1 , V_2 , V_10 , V_11 , 0 ) ;
return error ;
}
STATIC int
F_11 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_3 * V_19 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_20 ,
T_3 * V_21 )
{
T_3 V_22 ;
T_3 V_23 ;
T_3 V_12 ;
int error ;
T_3 V_24 ;
T_3 V_25 ;
int V_9 ;
for ( V_24 = F_12 ( V_1 , V_3 ) , V_22 = - 1 , V_23 = 0 ,
V_12 = F_12 ( V_1 , V_3 + 1 ) - 1 ;
V_24 <= V_12 ;
V_24 ++ ) {
error = F_13 ( V_1 , V_2 , V_24 , V_18 , 1 , & V_25 , & V_9 ) ;
if ( error ) {
return error ;
}
if ( V_9 ) {
error = F_4 ( V_1 , V_2 , V_24 , V_18 , V_4 ,
V_5 ) ;
if ( error ) {
return error ;
}
* V_11 = V_18 ;
* V_21 = V_24 ;
return 0 ;
}
if ( V_17 < V_18 ) {
T_3 V_26 ;
V_26 = V_25 - V_24 ;
if ( V_26 >= V_17 && V_26 > V_23 ) {
V_22 = V_24 ;
V_23 = V_26 ;
}
}
if ( V_25 < V_12 ) {
error = F_6 ( V_1 , V_2 , V_25 , V_12 , & V_24 ) ;
if ( error ) {
return error ;
}
} else
break;
}
if ( V_17 < V_18 && V_22 != - 1 ) {
T_7 V_27 ;
if ( V_20 > 1 && ( V_27 = F_14 ( V_23 , V_20 ) ) )
V_23 -= V_27 ;
error = F_4 ( V_1 , V_2 , V_22 , V_23 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_11 = V_23 ;
* V_21 = V_22 ;
return 0 ;
}
* V_19 = V_25 ;
* V_21 = V_28 ;
return 0 ;
}
STATIC int
F_15 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_29 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_20 ,
T_3 * V_21 )
{
int error ;
T_7 V_24 ;
int V_30 ;
T_3 V_25 ;
ASSERT ( V_17 % V_20 == 0 && V_18 % V_20 == 0 ) ;
error = F_13 ( V_1 , V_2 , V_29 , V_18 , 1 , & V_25 , & V_30 ) ;
if ( error ) {
return error ;
}
if ( V_30 ) {
error = F_4 ( V_1 , V_2 , V_29 , V_18 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_11 = V_18 ;
* V_21 = V_29 ;
return 0 ;
}
V_18 = V_25 - V_29 ;
if ( V_18 < V_17 ) {
* V_21 = V_28 ;
return 0 ;
}
if ( V_20 > 1 && ( V_24 = V_18 % V_20 ) ) {
V_18 -= V_24 ;
if ( V_18 < V_17 ) {
* V_21 = V_28 ;
return 0 ;
}
}
error = F_4 ( V_1 , V_2 , V_29 , V_18 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_11 = V_18 ;
* V_21 = V_29 ;
return 0 ;
}
STATIC int
F_16 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_29 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_20 ,
T_3 * V_21 )
{
int V_31 ;
T_3 V_3 ;
int error ;
int V_24 ;
int V_32 ;
int V_33 ;
T_3 V_34 ;
T_3 V_35 ;
ASSERT ( V_17 % V_20 == 0 && V_18 % V_20 == 0 ) ;
if ( V_29 >= V_1 -> V_15 . V_16 )
V_29 = V_1 -> V_15 . V_16 - 1 ;
error = F_15 ( V_1 , V_2 , V_29 , V_17 , V_18 , V_11 ,
V_4 , V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
V_3 = F_9 ( V_1 , V_29 ) ;
V_24 = 0 ;
ASSERT ( V_17 != 0 ) ;
V_33 = F_17 ( V_17 ) ;
for (; ; ) {
error = F_3 ( V_1 , V_2 , V_33 , V_1 -> V_36 - 1 ,
V_3 + V_24 , V_4 , V_5 , & V_31 ) ;
if ( error ) {
return error ;
}
if ( V_31 ) {
if ( V_24 >= 0 ) {
error = F_11 ( V_1 , V_2 ,
V_3 + V_24 , V_17 , V_18 , V_11 , & V_34 , V_4 ,
V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
}
else {
for ( V_32 = - 1 ; V_32 > V_24 ; V_32 -- ) {
error = F_3 ( V_1 , V_2 ,
V_33 , V_1 -> V_36 - 1 ,
V_3 + V_32 , V_4 , V_5 , & V_31 ) ;
if ( error ) {
return error ;
}
if ( V_31 )
continue;
error = F_11 ( V_1 ,
V_2 , V_3 + V_32 , V_17 , V_18 ,
V_11 , & V_34 , V_4 , V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
}
error = F_11 ( V_1 , V_2 ,
V_3 + V_24 , V_17 , V_18 , V_11 , & V_34 , V_4 ,
V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
}
}
if ( V_24 > 0 && ( int ) V_3 - V_24 >= 0 )
V_24 = - V_24 ;
else if ( V_24 > 0 && ( int ) V_3 + V_24 < V_1 -> V_15 . V_37 - 1 )
V_24 ++ ;
else if ( V_24 <= 0 && ( int ) V_3 - V_24 < V_1 -> V_15 . V_37 - 1 )
V_24 = 1 - V_24 ;
else if ( V_24 <= 0 && ( int ) V_3 + V_24 > 0 )
V_24 -- ;
else
break;
}
* V_21 = V_28 ;
return 0 ;
}
STATIC int
F_18 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_20 ,
T_3 * V_21 )
{
int error ;
int V_24 ;
int V_38 ;
T_3 V_34 ;
T_3 V_35 ;
T_6 V_6 ;
ASSERT ( V_17 % V_20 == 0 && V_18 % V_20 == 0 ) ;
ASSERT ( V_18 != 0 ) ;
for ( V_38 = F_17 ( V_18 ) ; V_38 < V_1 -> V_36 ; V_38 ++ ) {
for ( V_24 = 0 ; V_24 < V_1 -> V_15 . V_37 ; V_24 ++ ) {
error = F_1 ( V_1 , V_2 , V_38 , V_24 , V_4 , V_5 ,
& V_6 ) ;
if ( error ) {
return error ;
}
if ( ! V_6 )
continue;
error = F_11 ( V_1 , V_2 , V_24 , V_18 ,
V_18 , V_11 , & V_34 , V_4 , V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
if ( F_9 ( V_1 , V_34 ) > V_24 + 1 )
V_24 = F_9 ( V_1 , V_34 ) - 1 ;
}
}
if ( V_17 > -- V_18 ) {
* V_21 = V_28 ;
return 0 ;
}
ASSERT ( V_17 != 0 ) ;
ASSERT ( V_18 != 0 ) ;
for ( V_38 = F_17 ( V_18 ) ; V_38 >= F_17 ( V_17 ) ; V_38 -- ) {
for ( V_24 = 0 ; V_24 < V_1 -> V_15 . V_37 ; V_24 ++ ) {
error = F_1 ( V_1 , V_2 , V_38 , V_24 , V_4 , V_5 ,
& V_6 ) ;
if ( error ) {
return error ;
}
if ( ! V_6 )
continue;
error = F_11 ( V_1 , V_2 , V_24 ,
F_19 ( V_17 , 1 << V_38 ) ,
F_20 ( V_18 , ( 1 << ( V_38 + 1 ) ) - 1 ) ,
V_11 , & V_34 , V_4 , V_5 , V_20 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 != V_28 ) {
* V_21 = V_35 ;
return 0 ;
}
if ( F_9 ( V_1 , V_34 ) > V_24 + 1 )
V_24 = F_9 ( V_1 , V_34 ) - 1 ;
}
}
* V_21 = V_28 ;
return 0 ;
}
STATIC int
F_21 (
T_1 * V_1 ,
T_7 V_39 ,
T_7 V_40 ,
T_8 * V_41 )
{
T_9 V_29 ;
T_4 * V_42 ;
int V_43 ;
T_10 V_44 ;
int error ;
T_5 V_45 ;
T_11 V_46 ;
T_5 V_47 ;
T_12 V_48 ;
int V_49 ;
int V_50 ;
while ( V_39 < V_40 ) {
int V_51 = 0 ;
T_2 * V_2 ;
V_2 = F_22 ( V_1 , V_52 ) ;
V_50 = F_23 ( V_1 , V_40 - V_39 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_53 ,
V_50 , 0 ) ;
if ( error )
goto V_54;
V_51 = V_55 ;
F_26 ( V_41 , V_56 ) ;
F_27 ( V_2 , V_41 , V_56 ) ;
F_28 ( & V_46 , & V_45 ) ;
V_49 = 1 ;
V_51 |= V_57 ;
error = F_29 ( V_2 , V_41 , V_39 , V_40 - V_39 ,
V_58 , & V_45 ,
V_50 , & V_48 , & V_49 , & V_46 ) ;
if ( ! error && V_49 < 1 )
error = - V_59 ;
if ( error )
goto V_54;
error = F_30 ( & V_2 , & V_46 , & V_43 ) ;
if ( error )
goto V_54;
error = F_31 ( V_2 , V_55 ) ;
if ( error )
goto error;
V_51 = 0 ;
for ( V_29 = V_48 . V_60 , V_47 = V_48 . V_61 ;
V_29 < V_48 . V_60 + V_48 . V_62 ;
V_29 ++ , V_47 ++ ) {
V_2 = F_22 ( V_1 , V_63 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_64 ,
0 , 0 ) ;
if ( error )
goto V_54;
F_26 ( V_41 , V_56 ) ;
F_27 ( V_2 , V_41 , V_56 ) ;
V_44 = F_32 ( V_1 , V_47 ) ;
V_42 = F_33 ( V_2 , V_1 -> V_65 , V_44 ,
V_1 -> V_66 , 0 ) ;
if ( V_42 == NULL ) {
error = - V_67 ;
V_54:
F_34 ( V_2 , V_51 ) ;
goto error;
}
memset ( V_42 -> V_68 , 0 , V_1 -> V_15 . V_69 ) ;
F_35 ( V_2 , V_42 , 0 , V_1 -> V_15 . V_69 - 1 ) ;
error = F_31 ( V_2 , 0 ) ;
if ( error )
goto error;
}
V_39 = V_48 . V_60 + V_48 . V_62 ;
}
return 0 ;
error:
return error ;
}
int
F_36 (
T_1 * V_1 ,
T_13 * V_70 )
{
T_3 V_71 ;
T_4 * V_42 ;
int error ;
T_1 * V_72 ;
T_14 V_73 ;
T_7 V_74 ;
T_3 V_75 ;
T_15 V_76 ;
T_7 V_77 ;
T_16 V_78 ;
T_16 V_79 ;
T_17 * V_80 ;
T_7 V_81 ;
T_7 V_82 ;
T_17 * V_83 ;
T_5 V_84 ;
V_83 = & V_1 -> V_15 ;
if ( ! F_37 ( V_85 ) )
return - V_86 ;
if ( V_1 -> V_87 == NULL || V_1 -> V_88 == NULL ||
( V_73 = V_70 -> V_89 ) <= V_83 -> V_90 ||
( V_83 -> V_90 && ( V_70 -> V_91 != V_83 -> V_92 ) ) )
return - V_93 ;
if ( ( error = F_38 ( V_83 , V_73 ) ) )
return error ;
error = F_39 ( V_1 -> V_87 ,
F_40 ( V_1 , V_73 - 1 ) ,
F_40 ( V_1 , 1 ) , 0 , & V_42 , NULL ) ;
if ( error )
return error ;
F_41 ( V_42 ) ;
V_75 = V_73 ;
F_42 ( V_75 , V_70 -> V_91 ) ;
V_74 = F_43 ( V_75 , V_94 * V_83 -> V_69 ) ;
V_76 = F_17 ( V_75 ) ;
V_78 = V_76 + 1 ;
V_79 = ( T_16 ) sizeof( T_6 ) * V_78 * V_74 ;
V_77 = F_44 ( V_1 , V_79 ) ;
V_79 = F_45 ( V_1 , V_77 ) ;
if ( V_77 > ( V_1 -> V_15 . V_95 >> 1 ) )
return - V_93 ;
V_81 = F_44 ( V_1 , V_1 -> V_88 -> V_96 . V_97 ) ;
V_82 = F_44 ( V_1 , V_1 -> V_98 -> V_96 . V_97 ) ;
error = F_21 ( V_1 , V_81 , V_74 , V_1 -> V_88 ) ;
if ( error )
return error ;
error = F_21 ( V_1 , V_82 , V_77 , V_1 -> V_98 ) ;
if ( error )
return error ;
V_72 = F_46 ( sizeof( * V_72 ) , V_99 ) ;
for ( V_71 = V_83 -> V_37 -
( ( V_83 -> V_16 & ( ( 1 << V_1 -> V_100 ) - 1 ) ) != 0 ) ;
V_71 < V_74 ;
V_71 ++ ) {
T_2 * V_2 ;
int V_51 = 0 ;
* V_72 = * V_1 ;
V_80 = & V_72 -> V_15 ;
V_80 -> V_92 = V_70 -> V_91 ;
V_80 -> V_37 = V_71 + 1 ;
V_80 -> V_90 =
F_20 ( V_73 ,
V_80 -> V_37 * V_94 *
V_80 -> V_69 * V_80 -> V_92 ) ;
V_80 -> V_16 = V_80 -> V_90 ;
F_42 ( V_80 -> V_16 , V_80 -> V_92 ) ;
ASSERT ( V_80 -> V_16 != 0 ) ;
V_80 -> V_101 = F_17 ( V_80 -> V_16 ) ;
V_78 = V_72 -> V_36 = V_80 -> V_101 + 1 ;
V_79 =
( T_16 ) sizeof( T_6 ) * V_78 *
V_80 -> V_37 ;
V_77 = F_44 ( V_1 , V_79 ) ;
V_72 -> V_102 = V_79 = F_45 ( V_1 , V_77 ) ;
V_2 = F_22 ( V_1 , V_103 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_104 ,
0 , 0 ) ;
if ( error )
goto V_54;
F_26 ( V_1 -> V_88 , V_56 ) ;
F_27 ( V_2 , V_1 -> V_88 , V_56 ) ;
V_1 -> V_88 -> V_96 . V_97 =
V_80 -> V_37 * V_80 -> V_69 ;
F_47 ( V_2 , V_1 -> V_88 , V_105 ) ;
V_51 |= V_57 ;
F_26 ( V_1 -> V_98 , V_56 ) ;
F_27 ( V_2 , V_1 -> V_98 , V_56 ) ;
V_1 -> V_98 -> V_96 . V_97 = V_72 -> V_102 ;
F_47 ( V_2 , V_1 -> V_98 , V_105 ) ;
if ( V_83 -> V_37 != V_80 -> V_37 ||
V_1 -> V_36 != V_72 -> V_36 ) {
error = F_48 ( V_1 , V_72 , V_2 ) ;
if ( error )
goto V_54;
}
if ( V_80 -> V_92 != V_83 -> V_92 )
F_49 ( V_2 , V_106 ,
V_80 -> V_92 - V_83 -> V_92 ) ;
if ( V_80 -> V_37 != V_83 -> V_37 )
F_49 ( V_2 , V_107 ,
V_80 -> V_37 - V_83 -> V_37 ) ;
if ( V_80 -> V_90 != V_83 -> V_90 )
F_49 ( V_2 , V_108 ,
V_80 -> V_90 - V_83 -> V_90 ) ;
if ( V_80 -> V_16 != V_83 -> V_16 )
F_49 ( V_2 , V_109 ,
V_80 -> V_16 - V_83 -> V_16 ) ;
if ( V_80 -> V_101 != V_83 -> V_101 )
F_49 ( V_2 , V_110 ,
V_80 -> V_101 - V_83 -> V_101 ) ;
V_42 = NULL ;
error = F_50 ( V_72 , V_2 , V_83 -> V_16 ,
V_80 -> V_16 - V_83 -> V_16 , & V_42 , & V_84 ) ;
if ( error ) {
V_54:
F_34 ( V_2 , V_51 ) ;
break;
}
F_49 ( V_2 , V_111 ,
V_80 -> V_16 - V_83 -> V_16 ) ;
V_1 -> V_36 = V_78 ;
V_1 -> V_102 = V_79 ;
error = F_31 ( V_2 , 0 ) ;
if ( error )
break;
}
F_51 ( V_72 ) ;
return error ;
}
int
F_52 (
T_2 * V_2 ,
T_3 V_29 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_18 type ,
int V_112 ,
T_7 V_20 ,
T_3 * V_21 )
{
T_1 * V_1 = V_2 -> V_113 ;
int error ;
T_3 V_35 ;
T_5 V_114 ;
T_4 * V_115 ;
ASSERT ( F_53 ( V_1 -> V_88 , V_56 ) ) ;
ASSERT ( V_17 > 0 && V_17 <= V_18 ) ;
if ( V_20 > 1 ) {
T_7 V_24 ;
if ( ( V_24 = V_18 % V_20 ) )
V_18 -= V_24 ;
if ( ( V_24 = V_17 % V_20 ) )
V_17 += V_20 - V_24 ;
if ( V_18 < V_17 ) {
* V_21 = V_28 ;
return 0 ;
}
}
V_115 = NULL ;
switch ( type ) {
case V_116 :
error = F_18 ( V_1 , V_2 , V_17 , V_18 , V_11 ,
& V_115 , & V_114 , V_20 , & V_35 ) ;
break;
case V_117 :
error = F_16 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_115 , & V_114 , V_20 , & V_35 ) ;
break;
case V_118 :
error = F_15 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_115 , & V_114 , V_20 , & V_35 ) ;
break;
default:
error = - V_67 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_35 != V_28 ) {
long V_119 = ( long ) * V_11 ;
ASSERT ( * V_11 >= V_17 && * V_11 <= V_18 ) ;
if ( V_112 )
F_49 ( V_2 , V_120 , - V_119 ) ;
else
F_49 ( V_2 , V_111 , - V_119 ) ;
}
* V_21 = V_35 ;
return 0 ;
}
int
F_54 (
struct V_121 * V_1 )
{
struct V_122 * V_42 ;
struct V_123 * V_83 ;
T_10 V_44 ;
int error ;
V_83 = & V_1 -> V_15 ;
if ( V_83 -> V_90 == 0 )
return 0 ;
if ( V_1 -> V_87 == NULL ) {
F_55 ( V_1 ,
L_1 ) ;
return - V_124 ;
}
V_1 -> V_36 = V_83 -> V_101 + 1 ;
V_1 -> V_102 =
( T_16 ) sizeof( T_6 ) * V_1 -> V_36 *
V_83 -> V_37 ;
V_1 -> V_102 = F_56 ( V_1 -> V_102 , V_83 -> V_69 ) ;
V_1 -> V_88 = V_1 -> V_98 = NULL ;
V_44 = ( T_10 ) F_40 ( V_1 , V_1 -> V_15 . V_90 ) ;
if ( F_57 ( V_1 , V_44 ) != V_1 -> V_15 . V_90 ) {
F_55 ( V_1 , L_2 ,
( unsigned long long ) F_57 ( V_1 , V_44 ) ,
( unsigned long long ) V_1 -> V_15 . V_90 ) ;
return - V_125 ;
}
error = F_39 ( V_1 -> V_87 ,
V_44 - F_40 ( V_1 , 1 ) ,
F_40 ( V_1 , 1 ) , 0 , & V_42 , NULL ) ;
if ( error ) {
F_55 ( V_1 , L_3 ) ;
return error ;
}
F_41 ( V_42 ) ;
return 0 ;
}
int
F_58 (
T_1 * V_1 )
{
int error ;
T_17 * V_83 ;
V_83 = & V_1 -> V_15 ;
if ( V_83 -> V_126 == V_127 )
return 0 ;
error = F_59 ( V_1 , NULL , V_83 -> V_126 , 0 , 0 , & V_1 -> V_88 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_88 != NULL ) ;
ASSERT ( V_83 -> V_128 != V_127 ) ;
error = F_59 ( V_1 , NULL , V_83 -> V_128 , 0 , 0 , & V_1 -> V_98 ) ;
if ( error ) {
F_60 ( V_1 -> V_88 ) ;
return error ;
}
ASSERT ( V_1 -> V_98 != NULL ) ;
return 0 ;
}
void
F_61 (
struct V_121 * V_1 )
{
if ( V_1 -> V_88 )
F_60 ( V_1 -> V_88 ) ;
if ( V_1 -> V_98 )
F_60 ( V_1 -> V_98 ) ;
}
int
F_62 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_11 ,
T_3 * V_129 )
{
T_3 V_130 ;
int V_131 ;
T_19 V_132 ;
T_19 V_133 ;
T_19 * V_134 ;
ASSERT ( F_53 ( V_1 -> V_88 , V_56 ) ) ;
V_134 = ( T_19 * ) & V_1 -> V_88 -> V_96 . V_135 ;
if ( ! ( V_1 -> V_88 -> V_96 . V_136 & V_137 ) ) {
V_1 -> V_88 -> V_96 . V_136 |= V_137 ;
* V_134 = 0 ;
}
V_133 = * V_134 ;
if ( ( V_131 = F_63 ( V_133 ) ) == - 1 )
V_130 = 0 ;
else {
V_132 = V_133 - ( 1ULL << V_131 ) ;
V_130 = ( V_1 -> V_15 . V_16 * ( ( V_132 << 1 ) + 1ULL ) ) >>
( V_131 + 1 ) ;
if ( V_130 >= V_1 -> V_15 . V_16 )
V_130 = F_14 ( V_130 , V_1 -> V_15 . V_16 ) ;
if ( V_130 + V_11 > V_1 -> V_15 . V_16 )
V_130 = V_1 -> V_15 . V_16 - V_11 ;
}
* V_134 = V_133 + 1 ;
F_47 ( V_2 , V_1 -> V_88 , V_105 ) ;
* V_129 = V_130 ;
return 0 ;
}
