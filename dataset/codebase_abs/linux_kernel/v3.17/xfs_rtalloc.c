STATIC int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
int log ,
T_3 V_3 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_6 * V_6 )
{
T_4 * V_7 ;
int error ;
T_5 V_8 ;
int V_9 ;
T_6 * V_10 ;
V_9 = F_2 ( V_1 , log , V_3 ) ;
V_8 = F_3 ( V_1 , V_9 ) ;
if ( V_4 && * V_4 && * V_5 == V_8 )
V_7 = * V_4 ;
else {
if ( V_4 && * V_4 )
F_4 ( V_2 , * V_4 ) ;
error = F_5 ( V_1 , V_2 , V_8 , 1 , & V_7 ) ;
if ( error ) {
return error ;
}
if ( V_4 ) {
* V_4 = V_7 ;
* V_5 = V_8 ;
}
}
V_10 = F_6 ( V_1 , V_7 , V_9 ) ;
* V_6 = * V_10 ;
if ( ! V_4 )
F_4 ( V_2 , V_7 ) ;
return 0 ;
}
STATIC int
F_7 (
T_1 * V_1 ,
T_2 * V_2 ,
int V_11 ,
int V_12 ,
T_3 V_3 ,
T_4 * * V_4 ,
T_5 * V_5 ,
int * V_13 )
{
int error ;
int log ;
T_6 V_6 ;
for ( log = V_11 ; log <= V_12 ; log ++ ) {
error = F_1 ( V_1 , V_2 , log , V_3 , V_4 , V_5 , & V_6 ) ;
if ( error ) {
return error ;
}
if ( V_6 ) {
* V_13 = 1 ;
return 0 ;
}
}
* V_13 = 0 ;
return 0 ;
}
STATIC int
F_8 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_14 ,
T_7 V_15 ,
T_4 * * V_4 ,
T_5 * V_5 )
{
T_3 V_16 ;
int error ;
T_3 V_17 = 0 ;
T_3 V_18 = 0 ;
V_16 = V_14 + V_15 - 1 ;
error = F_9 ( V_1 , V_2 , V_14 , 0 , & V_18 ) ;
if ( error ) {
return error ;
}
error = F_10 ( V_1 , V_2 , V_16 , V_1 -> V_19 . V_20 - 1 ,
& V_17 ) ;
if ( error ) {
return error ;
}
error = F_11 ( V_1 , V_2 ,
F_12 ( V_17 + 1 - V_18 ) ,
F_13 ( V_1 , V_18 ) , - 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
if ( V_18 < V_14 ) {
error = F_11 ( V_1 , V_2 ,
F_12 ( V_14 - V_18 ) ,
F_13 ( V_1 , V_18 ) , 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
}
if ( V_17 > V_16 ) {
error = F_11 ( V_1 , V_2 ,
F_12 ( V_17 - V_16 ) ,
F_13 ( V_1 , V_16 + 1 ) , 1 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
}
error = F_14 ( V_1 , V_2 , V_14 , V_15 , 0 ) ;
return error ;
}
STATIC int
F_15 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
T_7 V_21 ,
T_7 V_22 ,
T_7 * V_15 ,
T_3 * V_23 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_24 ,
T_3 * V_25 )
{
T_3 V_26 ;
T_3 V_27 ;
T_3 V_16 ;
int error ;
T_3 V_28 ;
T_3 V_29 ;
int V_13 ;
for ( V_28 = F_16 ( V_1 , V_3 ) , V_26 = - 1 , V_27 = 0 ,
V_16 = F_16 ( V_1 , V_3 + 1 ) - 1 ;
V_28 <= V_16 ;
V_28 ++ ) {
error = F_17 ( V_1 , V_2 , V_28 , V_22 , 1 , & V_29 , & V_13 ) ;
if ( error ) {
return error ;
}
if ( V_13 ) {
error = F_8 ( V_1 , V_2 , V_28 , V_22 , V_4 ,
V_5 ) ;
if ( error ) {
return error ;
}
* V_15 = V_22 ;
* V_25 = V_28 ;
return 0 ;
}
if ( V_21 < V_22 ) {
T_3 V_30 ;
V_30 = V_29 - V_28 ;
if ( V_30 >= V_21 && V_30 > V_27 ) {
V_26 = V_28 ;
V_27 = V_30 ;
}
}
if ( V_29 < V_16 ) {
error = F_10 ( V_1 , V_2 , V_29 , V_16 , & V_28 ) ;
if ( error ) {
return error ;
}
} else
break;
}
if ( V_21 < V_22 && V_26 != - 1 ) {
T_7 V_31 ;
if ( V_24 > 1 && ( V_31 = F_18 ( V_27 , V_24 ) ) )
V_27 -= V_31 ;
error = F_8 ( V_1 , V_2 , V_26 , V_27 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_15 = V_27 ;
* V_25 = V_26 ;
return 0 ;
}
* V_23 = V_29 ;
* V_25 = V_32 ;
return 0 ;
}
STATIC int
F_19 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_33 ,
T_7 V_21 ,
T_7 V_22 ,
T_7 * V_15 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_24 ,
T_3 * V_25 )
{
int error ;
T_7 V_28 ;
int V_34 ;
T_3 V_29 ;
ASSERT ( V_21 % V_24 == 0 && V_22 % V_24 == 0 ) ;
error = F_17 ( V_1 , V_2 , V_33 , V_22 , 1 , & V_29 , & V_34 ) ;
if ( error ) {
return error ;
}
if ( V_34 ) {
error = F_8 ( V_1 , V_2 , V_33 , V_22 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_15 = V_22 ;
* V_25 = V_33 ;
return 0 ;
}
V_22 = V_29 - V_33 ;
if ( V_22 < V_21 ) {
* V_25 = V_32 ;
return 0 ;
}
if ( V_24 > 1 && ( V_28 = V_22 % V_24 ) ) {
V_22 -= V_28 ;
if ( V_22 < V_21 ) {
* V_25 = V_32 ;
return 0 ;
}
}
error = F_8 ( V_1 , V_2 , V_33 , V_22 , V_4 , V_5 ) ;
if ( error ) {
return error ;
}
* V_15 = V_22 ;
* V_25 = V_33 ;
return 0 ;
}
STATIC int
F_20 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_33 ,
T_7 V_21 ,
T_7 V_22 ,
T_7 * V_15 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_24 ,
T_3 * V_25 )
{
int V_35 ;
T_3 V_3 ;
int error ;
int V_28 ;
int V_36 ;
int V_37 ;
T_3 V_38 ;
T_3 V_39 ;
ASSERT ( V_21 % V_24 == 0 && V_22 % V_24 == 0 ) ;
if ( V_33 >= V_1 -> V_19 . V_20 )
V_33 = V_1 -> V_19 . V_20 - 1 ;
error = F_19 ( V_1 , V_2 , V_33 , V_21 , V_22 , V_15 ,
V_4 , V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
V_3 = F_13 ( V_1 , V_33 ) ;
V_28 = 0 ;
ASSERT ( V_21 != 0 ) ;
V_37 = F_21 ( V_21 ) ;
for (; ; ) {
error = F_7 ( V_1 , V_2 , V_37 , V_1 -> V_40 - 1 ,
V_3 + V_28 , V_4 , V_5 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 ) {
if ( V_28 >= 0 ) {
error = F_15 ( V_1 , V_2 ,
V_3 + V_28 , V_21 , V_22 , V_15 , & V_38 , V_4 ,
V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
}
else {
for ( V_36 = - 1 ; V_36 > V_28 ; V_36 -- ) {
error = F_7 ( V_1 , V_2 ,
V_37 , V_1 -> V_40 - 1 ,
V_3 + V_36 , V_4 , V_5 , & V_35 ) ;
if ( error ) {
return error ;
}
if ( V_35 )
continue;
error = F_15 ( V_1 ,
V_2 , V_3 + V_36 , V_21 , V_22 ,
V_15 , & V_38 , V_4 , V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
}
error = F_15 ( V_1 , V_2 ,
V_3 + V_28 , V_21 , V_22 , V_15 , & V_38 , V_4 ,
V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
}
}
if ( V_28 > 0 && ( int ) V_3 - V_28 >= 0 )
V_28 = - V_28 ;
else if ( V_28 > 0 && ( int ) V_3 + V_28 < V_1 -> V_19 . V_41 - 1 )
V_28 ++ ;
else if ( V_28 <= 0 && ( int ) V_3 - V_28 < V_1 -> V_19 . V_41 - 1 )
V_28 = 1 - V_28 ;
else if ( V_28 <= 0 && ( int ) V_3 + V_28 > 0 )
V_28 -- ;
else
break;
}
* V_25 = V_32 ;
return 0 ;
}
STATIC int
F_22 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_21 ,
T_7 V_22 ,
T_7 * V_15 ,
T_4 * * V_4 ,
T_5 * V_5 ,
T_7 V_24 ,
T_3 * V_25 )
{
int error ;
int V_28 ;
int V_42 ;
T_3 V_38 ;
T_3 V_39 ;
T_6 V_6 ;
ASSERT ( V_21 % V_24 == 0 && V_22 % V_24 == 0 ) ;
ASSERT ( V_22 != 0 ) ;
for ( V_42 = F_21 ( V_22 ) ; V_42 < V_1 -> V_40 ; V_42 ++ ) {
for ( V_28 = 0 ; V_28 < V_1 -> V_19 . V_41 ; V_28 ++ ) {
error = F_1 ( V_1 , V_2 , V_42 , V_28 , V_4 , V_5 ,
& V_6 ) ;
if ( error ) {
return error ;
}
if ( ! V_6 )
continue;
error = F_15 ( V_1 , V_2 , V_28 , V_22 ,
V_22 , V_15 , & V_38 , V_4 , V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
if ( F_13 ( V_1 , V_38 ) > V_28 + 1 )
V_28 = F_13 ( V_1 , V_38 ) - 1 ;
}
}
if ( V_21 > -- V_22 ) {
* V_25 = V_32 ;
return 0 ;
}
ASSERT ( V_21 != 0 ) ;
ASSERT ( V_22 != 0 ) ;
for ( V_42 = F_21 ( V_22 ) ; V_42 >= F_21 ( V_21 ) ; V_42 -- ) {
for ( V_28 = 0 ; V_28 < V_1 -> V_19 . V_41 ; V_28 ++ ) {
error = F_1 ( V_1 , V_2 , V_42 , V_28 , V_4 , V_5 ,
& V_6 ) ;
if ( error ) {
return error ;
}
if ( ! V_6 )
continue;
error = F_15 ( V_1 , V_2 , V_28 ,
F_23 ( V_21 , 1 << V_42 ) ,
F_24 ( V_22 , ( 1 << ( V_42 + 1 ) ) - 1 ) ,
V_15 , & V_38 , V_4 , V_5 , V_24 , & V_39 ) ;
if ( error ) {
return error ;
}
if ( V_39 != V_32 ) {
* V_25 = V_39 ;
return 0 ;
}
if ( F_13 ( V_1 , V_38 ) > V_28 + 1 )
V_28 = F_13 ( V_1 , V_38 ) - 1 ;
}
}
* V_25 = V_32 ;
return 0 ;
}
STATIC int
F_25 (
T_1 * V_1 ,
T_7 V_43 ,
T_7 V_44 ,
T_8 * V_45 )
{
T_9 V_33 ;
T_4 * V_7 ;
int V_46 ;
T_10 V_47 ;
int error ;
T_5 V_48 ;
T_11 V_49 ;
T_5 V_50 ;
T_12 V_51 ;
int V_52 ;
int V_53 ;
while ( V_43 < V_44 ) {
int V_54 = 0 ;
T_2 * V_2 ;
V_2 = F_26 ( V_1 , V_55 ) ;
V_53 = F_27 ( V_1 , V_44 - V_43 ) ;
error = F_28 ( V_2 , & F_29 ( V_1 ) -> V_56 ,
V_53 , 0 ) ;
if ( error )
goto V_57;
V_54 = V_58 ;
F_30 ( V_45 , V_59 ) ;
F_31 ( V_2 , V_45 , V_59 ) ;
F_32 ( & V_49 , & V_48 ) ;
V_52 = 1 ;
V_54 |= V_60 ;
error = F_33 ( V_2 , V_45 , V_43 , V_44 - V_43 ,
V_61 , & V_48 ,
V_53 , & V_51 , & V_52 , & V_49 ) ;
if ( ! error && V_52 < 1 )
error = - V_62 ;
if ( error )
goto V_57;
error = F_34 ( & V_2 , & V_49 , & V_46 ) ;
if ( error )
goto V_57;
error = F_35 ( V_2 , V_58 ) ;
if ( error )
goto error;
V_54 = 0 ;
for ( V_33 = V_51 . V_63 , V_50 = V_51 . V_64 ;
V_33 < V_51 . V_63 + V_51 . V_65 ;
V_33 ++ , V_50 ++ ) {
V_2 = F_26 ( V_1 , V_66 ) ;
error = F_28 ( V_2 , & F_29 ( V_1 ) -> V_67 ,
0 , 0 ) ;
if ( error )
goto V_57;
F_30 ( V_45 , V_59 ) ;
F_31 ( V_2 , V_45 , V_59 ) ;
V_47 = F_36 ( V_1 , V_50 ) ;
V_7 = F_37 ( V_2 , V_1 -> V_68 , V_47 ,
V_1 -> V_69 , 0 ) ;
if ( V_7 == NULL ) {
error = - V_70 ;
V_57:
F_38 ( V_2 , V_54 ) ;
goto error;
}
memset ( V_7 -> V_71 , 0 , V_1 -> V_19 . V_72 ) ;
F_39 ( V_2 , V_7 , 0 , V_1 -> V_19 . V_72 - 1 ) ;
error = F_35 ( V_2 , 0 ) ;
if ( error )
goto error;
}
V_43 = V_51 . V_63 + V_51 . V_65 ;
}
return 0 ;
error:
return error ;
}
int
F_40 (
T_1 * V_1 ,
T_13 * V_73 )
{
T_3 V_74 ;
T_4 * V_7 ;
int error ;
T_1 * V_75 ;
T_14 V_76 ;
T_7 V_77 ;
T_3 V_78 ;
T_15 V_79 ;
T_7 V_80 ;
T_16 V_81 ;
T_16 V_82 ;
T_17 * V_83 ;
T_7 V_84 ;
T_7 V_85 ;
T_17 * V_86 ;
T_5 V_87 ;
V_86 = & V_1 -> V_19 ;
if ( ! F_41 ( V_88 ) )
return - V_89 ;
if ( V_1 -> V_90 == NULL || V_1 -> V_91 == NULL ||
( V_76 = V_73 -> V_92 ) <= V_86 -> V_93 ||
( V_86 -> V_93 && ( V_73 -> V_94 != V_86 -> V_95 ) ) )
return - V_96 ;
if ( ( error = F_42 ( V_86 , V_76 ) ) )
return error ;
V_7 = F_43 ( V_1 -> V_90 ,
F_44 ( V_1 , V_76 - 1 ) ,
F_44 ( V_1 , 1 ) , 0 , NULL ) ;
if ( ! V_7 )
return - V_70 ;
if ( V_7 -> V_97 ) {
error = V_7 -> V_97 ;
F_45 ( V_7 ) ;
return error ;
}
F_45 ( V_7 ) ;
V_78 = V_76 ;
F_46 ( V_78 , V_73 -> V_94 ) ;
V_77 = F_47 ( V_78 , V_98 * V_86 -> V_72 ) ;
V_79 = F_21 ( V_78 ) ;
V_81 = V_79 + 1 ;
V_82 = ( T_16 ) sizeof( T_6 ) * V_81 * V_77 ;
V_80 = F_48 ( V_1 , V_82 ) ;
V_82 = F_49 ( V_1 , V_80 ) ;
if ( V_80 > ( V_1 -> V_19 . V_99 >> 1 ) )
return - V_96 ;
V_84 = F_48 ( V_1 , V_1 -> V_91 -> V_100 . V_101 ) ;
V_85 = F_48 ( V_1 , V_1 -> V_102 -> V_100 . V_101 ) ;
error = F_25 ( V_1 , V_84 , V_77 , V_1 -> V_91 ) ;
if ( error )
return error ;
error = F_25 ( V_1 , V_85 , V_80 , V_1 -> V_102 ) ;
if ( error )
return error ;
V_75 = F_50 ( sizeof( * V_75 ) , V_103 ) ;
for ( V_74 = V_86 -> V_41 -
( ( V_86 -> V_20 & ( ( 1 << V_1 -> V_104 ) - 1 ) ) != 0 ) ;
V_74 < V_77 ;
V_74 ++ ) {
T_2 * V_2 ;
int V_54 = 0 ;
* V_75 = * V_1 ;
V_83 = & V_75 -> V_19 ;
V_83 -> V_95 = V_73 -> V_94 ;
V_83 -> V_41 = V_74 + 1 ;
V_83 -> V_93 =
F_24 ( V_76 ,
V_83 -> V_41 * V_98 *
V_83 -> V_72 * V_83 -> V_95 ) ;
V_83 -> V_20 = V_83 -> V_93 ;
F_46 ( V_83 -> V_20 , V_83 -> V_95 ) ;
ASSERT ( V_83 -> V_20 != 0 ) ;
V_83 -> V_105 = F_21 ( V_83 -> V_20 ) ;
V_81 = V_75 -> V_40 = V_83 -> V_105 + 1 ;
V_82 =
( T_16 ) sizeof( T_6 ) * V_81 *
V_83 -> V_41 ;
V_80 = F_48 ( V_1 , V_82 ) ;
V_75 -> V_106 = V_82 = F_49 ( V_1 , V_80 ) ;
V_2 = F_26 ( V_1 , V_107 ) ;
error = F_28 ( V_2 , & F_29 ( V_1 ) -> V_108 ,
0 , 0 ) ;
if ( error )
goto V_57;
F_30 ( V_1 -> V_91 , V_59 ) ;
F_31 ( V_2 , V_1 -> V_91 , V_59 ) ;
V_1 -> V_91 -> V_100 . V_101 =
V_83 -> V_41 * V_83 -> V_72 ;
F_51 ( V_2 , V_1 -> V_91 , V_109 ) ;
V_54 |= V_60 ;
F_30 ( V_1 -> V_102 , V_59 ) ;
F_31 ( V_2 , V_1 -> V_102 , V_59 ) ;
V_1 -> V_102 -> V_100 . V_101 = V_75 -> V_106 ;
F_51 ( V_2 , V_1 -> V_102 , V_109 ) ;
if ( V_86 -> V_41 != V_83 -> V_41 ||
V_1 -> V_40 != V_75 -> V_40 ) {
error = F_52 ( V_1 , V_75 , V_2 ) ;
if ( error )
goto V_57;
}
if ( V_83 -> V_95 != V_86 -> V_95 )
F_53 ( V_2 , V_110 ,
V_83 -> V_95 - V_86 -> V_95 ) ;
if ( V_83 -> V_41 != V_86 -> V_41 )
F_53 ( V_2 , V_111 ,
V_83 -> V_41 - V_86 -> V_41 ) ;
if ( V_83 -> V_93 != V_86 -> V_93 )
F_53 ( V_2 , V_112 ,
V_83 -> V_93 - V_86 -> V_93 ) ;
if ( V_83 -> V_20 != V_86 -> V_20 )
F_53 ( V_2 , V_113 ,
V_83 -> V_20 - V_86 -> V_20 ) ;
if ( V_83 -> V_105 != V_86 -> V_105 )
F_53 ( V_2 , V_114 ,
V_83 -> V_105 - V_86 -> V_105 ) ;
V_7 = NULL ;
error = F_54 ( V_75 , V_2 , V_86 -> V_20 ,
V_83 -> V_20 - V_86 -> V_20 , & V_7 , & V_87 ) ;
if ( error ) {
V_57:
F_38 ( V_2 , V_54 ) ;
break;
}
F_53 ( V_2 , V_115 ,
V_83 -> V_20 - V_86 -> V_20 ) ;
V_1 -> V_40 = V_81 ;
V_1 -> V_106 = V_82 ;
error = F_35 ( V_2 , 0 ) ;
if ( error )
break;
}
F_55 ( V_75 ) ;
return error ;
}
int
F_56 (
T_2 * V_2 ,
T_3 V_33 ,
T_7 V_21 ,
T_7 V_22 ,
T_7 * V_15 ,
T_18 type ,
int V_116 ,
T_7 V_24 ,
T_3 * V_25 )
{
T_1 * V_1 = V_2 -> V_117 ;
int error ;
T_3 V_39 ;
T_5 V_8 ;
T_4 * V_118 ;
ASSERT ( F_57 ( V_1 -> V_91 , V_59 ) ) ;
ASSERT ( V_21 > 0 && V_21 <= V_22 ) ;
if ( V_24 > 1 ) {
T_7 V_28 ;
if ( ( V_28 = V_22 % V_24 ) )
V_22 -= V_28 ;
if ( ( V_28 = V_21 % V_24 ) )
V_21 += V_24 - V_28 ;
if ( V_22 < V_21 ) {
* V_25 = V_32 ;
return 0 ;
}
}
V_118 = NULL ;
switch ( type ) {
case V_119 :
error = F_22 ( V_1 , V_2 , V_21 , V_22 , V_15 ,
& V_118 , & V_8 , V_24 , & V_39 ) ;
break;
case V_120 :
error = F_20 ( V_1 , V_2 , V_33 , V_21 , V_22 ,
V_15 , & V_118 , & V_8 , V_24 , & V_39 ) ;
break;
case V_121 :
error = F_19 ( V_1 , V_2 , V_33 , V_21 , V_22 ,
V_15 , & V_118 , & V_8 , V_24 , & V_39 ) ;
break;
default:
error = - V_70 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_39 != V_32 ) {
long V_122 = ( long ) * V_15 ;
ASSERT ( * V_15 >= V_21 && * V_15 <= V_22 ) ;
if ( V_116 )
F_53 ( V_2 , V_123 , - V_122 ) ;
else
F_53 ( V_2 , V_115 , - V_122 ) ;
}
* V_25 = V_39 ;
return 0 ;
}
int
F_58 (
T_1 * V_1 )
{
T_4 * V_7 ;
T_10 V_47 ;
T_17 * V_86 ;
V_86 = & V_1 -> V_19 ;
if ( V_86 -> V_93 == 0 )
return 0 ;
if ( V_1 -> V_90 == NULL ) {
F_59 ( V_1 ,
L_1 ) ;
return - V_124 ;
}
V_1 -> V_40 = V_86 -> V_105 + 1 ;
V_1 -> V_106 =
( T_16 ) sizeof( T_6 ) * V_1 -> V_40 *
V_86 -> V_41 ;
V_1 -> V_106 = F_60 ( V_1 -> V_106 , V_86 -> V_72 ) ;
V_1 -> V_91 = V_1 -> V_102 = NULL ;
V_47 = ( T_10 ) F_44 ( V_1 , V_1 -> V_19 . V_93 ) ;
if ( F_61 ( V_1 , V_47 ) != V_1 -> V_19 . V_93 ) {
F_59 ( V_1 , L_2 ,
( unsigned long long ) F_61 ( V_1 , V_47 ) ,
( unsigned long long ) V_1 -> V_19 . V_93 ) ;
return - V_125 ;
}
V_7 = F_43 ( V_1 -> V_90 ,
V_47 - F_44 ( V_1 , 1 ) ,
F_44 ( V_1 , 1 ) , 0 , NULL ) ;
if ( ! V_7 || V_7 -> V_97 ) {
F_59 ( V_1 , L_3 ) ;
if ( V_7 )
F_45 ( V_7 ) ;
return - V_70 ;
}
F_45 ( V_7 ) ;
return 0 ;
}
int
F_62 (
T_1 * V_1 )
{
int error ;
T_17 * V_86 ;
V_86 = & V_1 -> V_19 ;
if ( V_86 -> V_126 == V_127 )
return 0 ;
error = F_63 ( V_1 , NULL , V_86 -> V_126 , 0 , 0 , & V_1 -> V_91 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_91 != NULL ) ;
ASSERT ( V_86 -> V_128 != V_127 ) ;
error = F_63 ( V_1 , NULL , V_86 -> V_128 , 0 , 0 , & V_1 -> V_102 ) ;
if ( error ) {
F_64 ( V_1 -> V_91 ) ;
return error ;
}
ASSERT ( V_1 -> V_102 != NULL ) ;
return 0 ;
}
void
F_65 (
struct V_129 * V_1 )
{
if ( V_1 -> V_91 )
F_64 ( V_1 -> V_91 ) ;
if ( V_1 -> V_102 )
F_64 ( V_1 -> V_102 ) ;
}
int
F_66 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_15 ,
T_3 * V_130 )
{
T_3 V_131 ;
int V_132 ;
T_19 V_133 ;
T_19 V_134 ;
T_19 * V_135 ;
ASSERT ( F_57 ( V_1 -> V_91 , V_59 ) ) ;
V_135 = ( T_19 * ) & V_1 -> V_91 -> V_100 . V_136 ;
if ( ! ( V_1 -> V_91 -> V_100 . V_137 & V_138 ) ) {
V_1 -> V_91 -> V_100 . V_137 |= V_138 ;
* V_135 = 0 ;
}
V_134 = * V_135 ;
if ( ( V_132 = F_67 ( V_134 ) ) == - 1 )
V_131 = 0 ;
else {
V_133 = V_134 - ( 1ULL << V_132 ) ;
V_131 = ( V_1 -> V_19 . V_20 * ( ( V_133 << 1 ) + 1ULL ) ) >>
( V_132 + 1 ) ;
if ( V_131 >= V_1 -> V_19 . V_20 )
V_131 = F_18 ( V_131 , V_1 -> V_19 . V_20 ) ;
if ( V_131 + V_15 > V_1 -> V_19 . V_20 )
V_131 = V_1 -> V_19 . V_20 - V_15 ;
}
* V_135 = V_134 + 1 ;
F_51 ( V_2 , V_1 -> V_91 , V_109 ) ;
* V_130 = V_131 ;
return 0 ;
}
