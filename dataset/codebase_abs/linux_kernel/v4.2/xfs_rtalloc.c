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
T_2 * V_2 ;
V_2 = F_22 ( V_1 , V_51 ) ;
V_50 = F_23 ( V_1 , V_40 - V_39 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_52 ,
V_50 , 0 ) ;
if ( error )
goto V_53;
F_26 ( V_41 , V_54 ) ;
F_27 ( V_2 , V_41 , V_54 ) ;
F_28 ( & V_46 , & V_45 ) ;
V_49 = 1 ;
error = F_29 ( V_2 , V_41 , V_39 , V_40 - V_39 ,
V_55 , & V_45 ,
V_50 , & V_48 , & V_49 , & V_46 ) ;
if ( ! error && V_49 < 1 )
error = - V_56 ;
if ( error )
goto V_53;
error = F_30 ( & V_2 , & V_46 , & V_43 ) ;
if ( error )
goto V_53;
error = F_31 ( V_2 ) ;
if ( error )
goto error;
for ( V_29 = V_48 . V_57 , V_47 = V_48 . V_58 ;
V_29 < V_48 . V_57 + V_48 . V_59 ;
V_29 ++ , V_47 ++ ) {
V_2 = F_22 ( V_1 , V_60 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_61 ,
0 , 0 ) ;
if ( error )
goto V_53;
F_26 ( V_41 , V_54 ) ;
F_27 ( V_2 , V_41 , V_54 ) ;
V_44 = F_32 ( V_1 , V_47 ) ;
V_42 = F_33 ( V_2 , V_1 -> V_62 , V_44 ,
V_1 -> V_63 , 0 ) ;
if ( V_42 == NULL ) {
error = - V_64 ;
V_53:
F_34 ( V_2 ) ;
goto error;
}
memset ( V_42 -> V_65 , 0 , V_1 -> V_15 . V_66 ) ;
F_35 ( V_2 , V_42 , 0 , V_1 -> V_15 . V_66 - 1 ) ;
error = F_31 ( V_2 ) ;
if ( error )
goto error;
}
V_39 = V_48 . V_57 + V_48 . V_59 ;
}
return 0 ;
error:
return error ;
}
int
F_36 (
T_1 * V_1 ,
T_13 * V_67 )
{
T_3 V_68 ;
T_4 * V_42 ;
int error ;
T_1 * V_69 ;
T_14 V_70 ;
T_7 V_71 ;
T_3 V_72 ;
T_15 V_73 ;
T_7 V_74 ;
T_16 V_75 ;
T_16 V_76 ;
T_17 * V_77 ;
T_7 V_78 ;
T_7 V_79 ;
T_17 * V_80 ;
T_5 V_81 ;
V_80 = & V_1 -> V_15 ;
if ( ! F_37 ( V_82 ) )
return - V_83 ;
if ( V_1 -> V_84 == NULL || V_1 -> V_85 == NULL ||
( V_70 = V_67 -> V_86 ) <= V_80 -> V_87 ||
( V_80 -> V_87 && ( V_67 -> V_88 != V_80 -> V_89 ) ) )
return - V_90 ;
if ( ( error = F_38 ( V_80 , V_70 ) ) )
return error ;
error = F_39 ( V_1 -> V_84 ,
F_40 ( V_1 , V_70 - 1 ) ,
F_40 ( V_1 , 1 ) , 0 , & V_42 , NULL ) ;
if ( error )
return error ;
F_41 ( V_42 ) ;
V_72 = V_70 ;
F_42 ( V_72 , V_67 -> V_88 ) ;
V_71 = F_43 ( V_72 , V_91 * V_80 -> V_66 ) ;
V_73 = F_17 ( V_72 ) ;
V_75 = V_73 + 1 ;
V_76 = ( T_16 ) sizeof( T_6 ) * V_75 * V_71 ;
V_74 = F_44 ( V_1 , V_76 ) ;
V_76 = F_45 ( V_1 , V_74 ) ;
if ( V_74 > ( V_1 -> V_15 . V_92 >> 1 ) )
return - V_90 ;
V_78 = F_44 ( V_1 , V_1 -> V_85 -> V_93 . V_94 ) ;
V_79 = F_44 ( V_1 , V_1 -> V_95 -> V_93 . V_94 ) ;
error = F_21 ( V_1 , V_78 , V_71 , V_1 -> V_85 ) ;
if ( error )
return error ;
error = F_21 ( V_1 , V_79 , V_74 , V_1 -> V_95 ) ;
if ( error )
return error ;
V_69 = F_46 ( sizeof( * V_69 ) , V_96 ) ;
for ( V_68 = V_80 -> V_37 -
( ( V_80 -> V_16 & ( ( 1 << V_1 -> V_97 ) - 1 ) ) != 0 ) ;
V_68 < V_71 ;
V_68 ++ ) {
T_2 * V_2 ;
* V_69 = * V_1 ;
V_77 = & V_69 -> V_15 ;
V_77 -> V_89 = V_67 -> V_88 ;
V_77 -> V_37 = V_68 + 1 ;
V_77 -> V_87 =
F_20 ( V_70 ,
V_77 -> V_37 * V_91 *
V_77 -> V_66 * V_77 -> V_89 ) ;
V_77 -> V_16 = V_77 -> V_87 ;
F_42 ( V_77 -> V_16 , V_77 -> V_89 ) ;
ASSERT ( V_77 -> V_16 != 0 ) ;
V_77 -> V_98 = F_17 ( V_77 -> V_16 ) ;
V_75 = V_69 -> V_36 = V_77 -> V_98 + 1 ;
V_76 =
( T_16 ) sizeof( T_6 ) * V_75 *
V_77 -> V_37 ;
V_74 = F_44 ( V_1 , V_76 ) ;
V_69 -> V_99 = V_76 = F_45 ( V_1 , V_74 ) ;
V_2 = F_22 ( V_1 , V_100 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_101 ,
0 , 0 ) ;
if ( error )
goto V_53;
F_26 ( V_1 -> V_85 , V_54 ) ;
F_27 ( V_2 , V_1 -> V_85 , V_54 ) ;
V_1 -> V_85 -> V_93 . V_94 =
V_77 -> V_37 * V_77 -> V_66 ;
F_47 ( V_2 , V_1 -> V_85 , V_102 ) ;
F_26 ( V_1 -> V_95 , V_54 ) ;
F_27 ( V_2 , V_1 -> V_95 , V_54 ) ;
V_1 -> V_95 -> V_93 . V_94 = V_69 -> V_99 ;
F_47 ( V_2 , V_1 -> V_95 , V_102 ) ;
if ( V_80 -> V_37 != V_77 -> V_37 ||
V_1 -> V_36 != V_69 -> V_36 ) {
error = F_48 ( V_1 , V_69 , V_2 ) ;
if ( error )
goto V_53;
}
if ( V_77 -> V_89 != V_80 -> V_89 )
F_49 ( V_2 , V_103 ,
V_77 -> V_89 - V_80 -> V_89 ) ;
if ( V_77 -> V_37 != V_80 -> V_37 )
F_49 ( V_2 , V_104 ,
V_77 -> V_37 - V_80 -> V_37 ) ;
if ( V_77 -> V_87 != V_80 -> V_87 )
F_49 ( V_2 , V_105 ,
V_77 -> V_87 - V_80 -> V_87 ) ;
if ( V_77 -> V_16 != V_80 -> V_16 )
F_49 ( V_2 , V_106 ,
V_77 -> V_16 - V_80 -> V_16 ) ;
if ( V_77 -> V_98 != V_80 -> V_98 )
F_49 ( V_2 , V_107 ,
V_77 -> V_98 - V_80 -> V_98 ) ;
V_42 = NULL ;
error = F_50 ( V_69 , V_2 , V_80 -> V_16 ,
V_77 -> V_16 - V_80 -> V_16 , & V_42 , & V_81 ) ;
if ( error ) {
V_53:
F_34 ( V_2 ) ;
break;
}
F_49 ( V_2 , V_108 ,
V_77 -> V_16 - V_80 -> V_16 ) ;
V_1 -> V_36 = V_75 ;
V_1 -> V_99 = V_76 ;
error = F_31 ( V_2 ) ;
if ( error )
break;
}
F_51 ( V_69 ) ;
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
int V_109 ,
T_7 V_20 ,
T_3 * V_21 )
{
T_1 * V_1 = V_2 -> V_110 ;
int error ;
T_3 V_35 ;
T_5 V_111 ;
T_4 * V_112 ;
ASSERT ( F_53 ( V_1 -> V_85 , V_54 ) ) ;
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
V_112 = NULL ;
switch ( type ) {
case V_113 :
error = F_18 ( V_1 , V_2 , V_17 , V_18 , V_11 ,
& V_112 , & V_111 , V_20 , & V_35 ) ;
break;
case V_114 :
error = F_16 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_112 , & V_111 , V_20 , & V_35 ) ;
break;
case V_115 :
error = F_15 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_112 , & V_111 , V_20 , & V_35 ) ;
break;
default:
error = - V_64 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_35 != V_28 ) {
long V_116 = ( long ) * V_11 ;
ASSERT ( * V_11 >= V_17 && * V_11 <= V_18 ) ;
if ( V_109 )
F_49 ( V_2 , V_117 , - V_116 ) ;
else
F_49 ( V_2 , V_108 , - V_116 ) ;
}
* V_21 = V_35 ;
return 0 ;
}
int
F_54 (
struct V_118 * V_1 )
{
struct V_119 * V_42 ;
struct V_120 * V_80 ;
T_10 V_44 ;
int error ;
V_80 = & V_1 -> V_15 ;
if ( V_80 -> V_87 == 0 )
return 0 ;
if ( V_1 -> V_84 == NULL ) {
F_55 ( V_1 ,
L_1 ) ;
return - V_121 ;
}
V_1 -> V_36 = V_80 -> V_98 + 1 ;
V_1 -> V_99 =
( T_16 ) sizeof( T_6 ) * V_1 -> V_36 *
V_80 -> V_37 ;
V_1 -> V_99 = F_56 ( V_1 -> V_99 , V_80 -> V_66 ) ;
V_1 -> V_85 = V_1 -> V_95 = NULL ;
V_44 = ( T_10 ) F_40 ( V_1 , V_1 -> V_15 . V_87 ) ;
if ( F_57 ( V_1 , V_44 ) != V_1 -> V_15 . V_87 ) {
F_55 ( V_1 , L_2 ,
( unsigned long long ) F_57 ( V_1 , V_44 ) ,
( unsigned long long ) V_1 -> V_15 . V_87 ) ;
return - V_122 ;
}
error = F_39 ( V_1 -> V_84 ,
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
T_17 * V_80 ;
V_80 = & V_1 -> V_15 ;
if ( V_80 -> V_123 == V_124 )
return 0 ;
error = F_59 ( V_1 , NULL , V_80 -> V_123 , 0 , 0 , & V_1 -> V_85 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_85 != NULL ) ;
ASSERT ( V_80 -> V_125 != V_124 ) ;
error = F_59 ( V_1 , NULL , V_80 -> V_125 , 0 , 0 , & V_1 -> V_95 ) ;
if ( error ) {
F_60 ( V_1 -> V_85 ) ;
return error ;
}
ASSERT ( V_1 -> V_95 != NULL ) ;
return 0 ;
}
void
F_61 (
struct V_118 * V_1 )
{
if ( V_1 -> V_85 )
F_60 ( V_1 -> V_85 ) ;
if ( V_1 -> V_95 )
F_60 ( V_1 -> V_95 ) ;
}
int
F_62 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_11 ,
T_3 * V_126 )
{
T_3 V_127 ;
int V_128 ;
T_19 V_129 ;
T_19 V_130 ;
T_19 * V_131 ;
ASSERT ( F_53 ( V_1 -> V_85 , V_54 ) ) ;
V_131 = ( T_19 * ) & V_1 -> V_85 -> V_93 . V_132 ;
if ( ! ( V_1 -> V_85 -> V_93 . V_133 & V_134 ) ) {
V_1 -> V_85 -> V_93 . V_133 |= V_134 ;
* V_131 = 0 ;
}
V_130 = * V_131 ;
if ( ( V_128 = F_63 ( V_130 ) ) == - 1 )
V_127 = 0 ;
else {
V_129 = V_130 - ( 1ULL << V_128 ) ;
V_127 = ( V_1 -> V_15 . V_16 * ( ( V_129 << 1 ) + 1ULL ) ) >>
( V_128 + 1 ) ;
if ( V_127 >= V_1 -> V_15 . V_16 )
V_127 = F_14 ( V_127 , V_1 -> V_15 . V_16 ) ;
if ( V_127 + V_11 > V_1 -> V_15 . V_16 )
V_127 = V_1 -> V_15 . V_16 - V_11 ;
}
* V_131 = V_130 + 1 ;
F_47 ( V_2 , V_1 -> V_85 , V_102 ) ;
* V_126 = V_127 ;
return 0 ;
}
