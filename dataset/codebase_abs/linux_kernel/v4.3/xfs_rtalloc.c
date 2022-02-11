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
struct V_39 * V_1 ,
T_7 V_40 ,
T_7 V_41 ,
struct V_42 * V_43 )
{
T_8 V_29 ;
struct V_44 * V_45 ;
int V_46 ;
T_9 V_47 ;
int error ;
T_5 V_48 ;
struct V_49 V_50 ;
T_5 V_51 ;
struct V_52 V_53 ;
int V_54 ;
int V_55 ;
struct V_56 * V_2 ;
while ( V_40 < V_41 ) {
V_2 = F_22 ( V_1 , V_57 ) ;
V_55 = F_23 ( V_1 , V_41 - V_40 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_58 ,
V_55 , 0 ) ;
if ( error )
goto V_59;
F_26 ( V_43 , V_60 ) ;
F_27 ( V_2 , V_43 , V_60 ) ;
F_28 ( & V_50 , & V_48 ) ;
V_54 = 1 ;
error = F_29 ( V_2 , V_43 , V_40 , V_41 - V_40 ,
V_61 , & V_48 ,
V_55 , & V_53 , & V_54 , & V_50 ) ;
if ( ! error && V_54 < 1 )
error = - V_62 ;
if ( error )
goto V_63;
error = F_30 ( & V_2 , & V_50 , & V_46 ) ;
if ( error )
goto V_63;
error = F_31 ( V_2 ) ;
if ( error )
return error ;
for ( V_29 = V_53 . V_64 , V_51 = V_53 . V_65 ;
V_29 < V_53 . V_64 + V_53 . V_66 ;
V_29 ++ , V_51 ++ ) {
V_2 = F_22 ( V_1 , V_67 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_68 ,
0 , 0 ) ;
if ( error )
goto V_59;
F_26 ( V_43 , V_60 ) ;
F_27 ( V_2 , V_43 , V_60 ) ;
V_47 = F_32 ( V_1 , V_51 ) ;
V_45 = F_33 ( V_2 , V_1 -> V_69 , V_47 ,
V_1 -> V_70 , 0 ) ;
if ( V_45 == NULL ) {
error = - V_71 ;
goto V_59;
}
memset ( V_45 -> V_72 , 0 , V_1 -> V_15 . V_73 ) ;
F_34 ( V_2 , V_45 , 0 , V_1 -> V_15 . V_73 - 1 ) ;
error = F_31 ( V_2 ) ;
if ( error )
return error ;
}
V_40 = V_53 . V_64 + V_53 . V_66 ;
}
return 0 ;
V_63:
F_35 ( & V_50 ) ;
V_59:
F_36 ( V_2 ) ;
return error ;
}
int
F_37 (
T_1 * V_1 ,
T_10 * V_74 )
{
T_3 V_75 ;
T_4 * V_45 ;
int error ;
T_1 * V_76 ;
T_11 V_77 ;
T_7 V_78 ;
T_3 V_79 ;
T_12 V_80 ;
T_7 V_81 ;
T_13 V_82 ;
T_13 V_83 ;
T_14 * V_84 ;
T_7 V_85 ;
T_7 V_86 ;
T_14 * V_87 ;
T_5 V_88 ;
V_87 = & V_1 -> V_15 ;
if ( ! F_38 ( V_89 ) )
return - V_90 ;
if ( V_1 -> V_91 == NULL || V_1 -> V_92 == NULL ||
( V_77 = V_74 -> V_93 ) <= V_87 -> V_94 ||
( V_87 -> V_94 && ( V_74 -> V_95 != V_87 -> V_96 ) ) )
return - V_97 ;
if ( ( error = F_39 ( V_87 , V_77 ) ) )
return error ;
error = F_40 ( V_1 -> V_91 ,
F_41 ( V_1 , V_77 - 1 ) ,
F_41 ( V_1 , 1 ) , 0 , & V_45 , NULL ) ;
if ( error )
return error ;
F_42 ( V_45 ) ;
V_79 = V_77 ;
F_43 ( V_79 , V_74 -> V_95 ) ;
V_78 = F_44 ( V_79 , V_98 * V_87 -> V_73 ) ;
V_80 = F_17 ( V_79 ) ;
V_82 = V_80 + 1 ;
V_83 = ( T_13 ) sizeof( T_6 ) * V_82 * V_78 ;
V_81 = F_45 ( V_1 , V_83 ) ;
V_83 = F_46 ( V_1 , V_81 ) ;
if ( V_81 > ( V_1 -> V_15 . V_99 >> 1 ) )
return - V_97 ;
V_85 = F_45 ( V_1 , V_1 -> V_92 -> V_100 . V_101 ) ;
V_86 = F_45 ( V_1 , V_1 -> V_102 -> V_100 . V_101 ) ;
error = F_21 ( V_1 , V_85 , V_78 , V_1 -> V_92 ) ;
if ( error )
return error ;
error = F_21 ( V_1 , V_86 , V_81 , V_1 -> V_102 ) ;
if ( error )
return error ;
V_76 = F_47 ( sizeof( * V_76 ) , V_103 ) ;
for ( V_75 = V_87 -> V_37 -
( ( V_87 -> V_16 & ( ( 1 << V_1 -> V_104 ) - 1 ) ) != 0 ) ;
V_75 < V_78 ;
V_75 ++ ) {
T_2 * V_2 ;
* V_76 = * V_1 ;
V_84 = & V_76 -> V_15 ;
V_84 -> V_96 = V_74 -> V_95 ;
V_84 -> V_37 = V_75 + 1 ;
V_84 -> V_94 =
F_20 ( V_77 ,
V_84 -> V_37 * V_98 *
V_84 -> V_73 * V_84 -> V_96 ) ;
V_84 -> V_16 = V_84 -> V_94 ;
F_43 ( V_84 -> V_16 , V_84 -> V_96 ) ;
ASSERT ( V_84 -> V_16 != 0 ) ;
V_84 -> V_105 = F_17 ( V_84 -> V_16 ) ;
V_82 = V_76 -> V_36 = V_84 -> V_105 + 1 ;
V_83 =
( T_13 ) sizeof( T_6 ) * V_82 *
V_84 -> V_37 ;
V_81 = F_45 ( V_1 , V_83 ) ;
V_76 -> V_106 = V_83 = F_46 ( V_1 , V_81 ) ;
V_2 = F_22 ( V_1 , V_107 ) ;
error = F_24 ( V_2 , & F_25 ( V_1 ) -> V_108 ,
0 , 0 ) ;
if ( error )
goto V_109;
F_26 ( V_1 -> V_92 , V_60 ) ;
F_27 ( V_2 , V_1 -> V_92 , V_60 ) ;
V_1 -> V_92 -> V_100 . V_101 =
V_84 -> V_37 * V_84 -> V_73 ;
F_48 ( V_2 , V_1 -> V_92 , V_110 ) ;
F_26 ( V_1 -> V_102 , V_60 ) ;
F_27 ( V_2 , V_1 -> V_102 , V_60 ) ;
V_1 -> V_102 -> V_100 . V_101 = V_76 -> V_106 ;
F_48 ( V_2 , V_1 -> V_102 , V_110 ) ;
if ( V_87 -> V_37 != V_84 -> V_37 ||
V_1 -> V_36 != V_76 -> V_36 ) {
error = F_49 ( V_1 , V_76 , V_2 ) ;
if ( error )
goto V_109;
}
if ( V_84 -> V_96 != V_87 -> V_96 )
F_50 ( V_2 , V_111 ,
V_84 -> V_96 - V_87 -> V_96 ) ;
if ( V_84 -> V_37 != V_87 -> V_37 )
F_50 ( V_2 , V_112 ,
V_84 -> V_37 - V_87 -> V_37 ) ;
if ( V_84 -> V_94 != V_87 -> V_94 )
F_50 ( V_2 , V_113 ,
V_84 -> V_94 - V_87 -> V_94 ) ;
if ( V_84 -> V_16 != V_87 -> V_16 )
F_50 ( V_2 , V_114 ,
V_84 -> V_16 - V_87 -> V_16 ) ;
if ( V_84 -> V_105 != V_87 -> V_105 )
F_50 ( V_2 , V_115 ,
V_84 -> V_105 - V_87 -> V_105 ) ;
V_45 = NULL ;
error = F_51 ( V_76 , V_2 , V_87 -> V_16 ,
V_84 -> V_16 - V_87 -> V_16 , & V_45 , & V_88 ) ;
if ( error ) {
V_109:
F_36 ( V_2 ) ;
break;
}
F_50 ( V_2 , V_116 ,
V_84 -> V_16 - V_87 -> V_16 ) ;
V_1 -> V_36 = V_82 ;
V_1 -> V_106 = V_83 ;
error = F_31 ( V_2 ) ;
if ( error )
break;
}
F_52 ( V_76 ) ;
return error ;
}
int
F_53 (
T_2 * V_2 ,
T_3 V_29 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
T_15 type ,
int V_117 ,
T_7 V_20 ,
T_3 * V_21 )
{
T_1 * V_1 = V_2 -> V_118 ;
int error ;
T_3 V_35 ;
T_5 V_119 ;
T_4 * V_120 ;
ASSERT ( F_54 ( V_1 -> V_92 , V_60 ) ) ;
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
V_120 = NULL ;
switch ( type ) {
case V_121 :
error = F_18 ( V_1 , V_2 , V_17 , V_18 , V_11 ,
& V_120 , & V_119 , V_20 , & V_35 ) ;
break;
case V_122 :
error = F_16 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_120 , & V_119 , V_20 , & V_35 ) ;
break;
case V_123 :
error = F_15 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_120 , & V_119 , V_20 , & V_35 ) ;
break;
default:
error = - V_71 ;
ASSERT ( 0 ) ;
}
if ( error )
return error ;
if ( V_35 != V_28 ) {
long V_124 = ( long ) * V_11 ;
ASSERT ( * V_11 >= V_17 && * V_11 <= V_18 ) ;
if ( V_117 )
F_50 ( V_2 , V_125 , - V_124 ) ;
else
F_50 ( V_2 , V_116 , - V_124 ) ;
}
* V_21 = V_35 ;
return 0 ;
}
int
F_55 (
struct V_39 * V_1 )
{
struct V_44 * V_45 ;
struct V_126 * V_87 ;
T_9 V_47 ;
int error ;
V_87 = & V_1 -> V_15 ;
if ( V_87 -> V_94 == 0 )
return 0 ;
if ( V_1 -> V_91 == NULL ) {
F_56 ( V_1 ,
L_1 ) ;
return - V_127 ;
}
V_1 -> V_36 = V_87 -> V_105 + 1 ;
V_1 -> V_106 =
( T_13 ) sizeof( T_6 ) * V_1 -> V_36 *
V_87 -> V_37 ;
V_1 -> V_106 = F_57 ( V_1 -> V_106 , V_87 -> V_73 ) ;
V_1 -> V_92 = V_1 -> V_102 = NULL ;
V_47 = ( T_9 ) F_41 ( V_1 , V_1 -> V_15 . V_94 ) ;
if ( F_58 ( V_1 , V_47 ) != V_1 -> V_15 . V_94 ) {
F_56 ( V_1 , L_2 ,
( unsigned long long ) F_58 ( V_1 , V_47 ) ,
( unsigned long long ) V_1 -> V_15 . V_94 ) ;
return - V_128 ;
}
error = F_40 ( V_1 -> V_91 ,
V_47 - F_41 ( V_1 , 1 ) ,
F_41 ( V_1 , 1 ) , 0 , & V_45 , NULL ) ;
if ( error ) {
F_56 ( V_1 , L_3 ) ;
return error ;
}
F_42 ( V_45 ) ;
return 0 ;
}
int
F_59 (
T_1 * V_1 )
{
int error ;
T_14 * V_87 ;
V_87 = & V_1 -> V_15 ;
if ( V_87 -> V_129 == V_130 )
return 0 ;
error = F_60 ( V_1 , NULL , V_87 -> V_129 , 0 , 0 , & V_1 -> V_92 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_92 != NULL ) ;
ASSERT ( V_87 -> V_131 != V_130 ) ;
error = F_60 ( V_1 , NULL , V_87 -> V_131 , 0 , 0 , & V_1 -> V_102 ) ;
if ( error ) {
F_61 ( V_1 -> V_92 ) ;
return error ;
}
ASSERT ( V_1 -> V_102 != NULL ) ;
return 0 ;
}
void
F_62 (
struct V_39 * V_1 )
{
if ( V_1 -> V_92 )
F_61 ( V_1 -> V_92 ) ;
if ( V_1 -> V_102 )
F_61 ( V_1 -> V_102 ) ;
}
int
F_63 (
T_1 * V_1 ,
T_2 * V_2 ,
T_7 V_11 ,
T_3 * V_132 )
{
T_3 V_133 ;
int V_134 ;
T_16 V_135 ;
T_16 V_136 ;
T_16 * V_137 ;
ASSERT ( F_54 ( V_1 -> V_92 , V_60 ) ) ;
V_137 = ( T_16 * ) & V_1 -> V_92 -> V_100 . V_138 ;
if ( ! ( V_1 -> V_92 -> V_100 . V_139 & V_140 ) ) {
V_1 -> V_92 -> V_100 . V_139 |= V_140 ;
* V_137 = 0 ;
}
V_136 = * V_137 ;
if ( ( V_134 = F_64 ( V_136 ) ) == - 1 )
V_133 = 0 ;
else {
V_135 = V_136 - ( 1ULL << V_134 ) ;
V_133 = ( V_1 -> V_15 . V_16 * ( ( V_135 << 1 ) + 1ULL ) ) >>
( V_134 + 1 ) ;
if ( V_133 >= V_1 -> V_15 . V_16 )
V_133 = F_14 ( V_133 , V_1 -> V_15 . V_16 ) ;
if ( V_133 + V_11 > V_1 -> V_15 . V_16 )
V_133 = V_1 -> V_15 . V_16 - V_11 ;
}
* V_137 = V_136 + 1 ;
F_48 ( V_2 , V_1 -> V_92 , V_110 ) ;
* V_132 = V_133 ;
return 0 ;
}
