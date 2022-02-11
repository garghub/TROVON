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
T_9 V_46 ;
int error ;
T_5 V_47 ;
struct V_48 V_49 ;
T_5 V_50 ;
struct V_51 V_52 ;
int V_53 ;
int V_54 ;
struct V_55 * V_2 ;
while ( V_40 < V_41 ) {
V_54 = F_22 ( V_1 , V_41 - V_40 ) ;
error = F_23 ( V_1 , & F_24 ( V_1 ) -> V_56 , V_54 ,
0 , 0 , & V_2 ) ;
if ( error )
return error ;
F_25 ( V_43 , V_57 ) ;
F_26 ( V_2 , V_43 , V_57 ) ;
F_27 ( & V_49 , & V_47 ) ;
V_53 = 1 ;
error = F_28 ( V_2 , V_43 , V_40 , V_41 - V_40 ,
V_58 , & V_47 ,
V_54 , & V_52 , & V_53 , & V_49 ) ;
if ( ! error && V_53 < 1 )
error = - V_59 ;
if ( error )
goto V_60;
error = F_29 ( & V_2 , & V_49 , NULL ) ;
if ( error )
goto V_60;
error = F_30 ( V_2 ) ;
if ( error )
return error ;
for ( V_29 = V_52 . V_61 , V_50 = V_52 . V_62 ;
V_29 < V_52 . V_61 + V_52 . V_63 ;
V_29 ++ , V_50 ++ ) {
error = F_23 ( V_1 , & F_24 ( V_1 ) -> V_64 ,
0 , 0 , 0 , & V_2 ) ;
if ( error )
return error ;
F_25 ( V_43 , V_57 ) ;
F_26 ( V_2 , V_43 , V_57 ) ;
V_46 = F_31 ( V_1 , V_50 ) ;
V_45 = F_32 ( V_2 , V_1 -> V_65 , V_46 ,
V_1 -> V_66 , 0 ) ;
if ( V_45 == NULL ) {
error = - V_67 ;
goto V_68;
}
memset ( V_45 -> V_69 , 0 , V_1 -> V_15 . V_70 ) ;
F_33 ( V_2 , V_45 , 0 , V_1 -> V_15 . V_70 - 1 ) ;
error = F_30 ( V_2 ) ;
if ( error )
return error ;
}
V_40 = V_52 . V_61 + V_52 . V_63 ;
}
return 0 ;
V_60:
F_34 ( & V_49 ) ;
V_68:
F_35 ( V_2 ) ;
return error ;
}
int
F_36 (
T_1 * V_1 ,
T_10 * V_71 )
{
T_3 V_72 ;
T_4 * V_45 ;
int error ;
T_1 * V_73 ;
T_11 V_74 ;
T_7 V_75 ;
T_3 V_76 ;
T_12 V_77 ;
T_7 V_78 ;
T_13 V_79 ;
T_13 V_80 ;
T_14 * V_81 ;
T_7 V_82 ;
T_7 V_83 ;
T_14 * V_84 ;
T_5 V_85 ;
V_84 = & V_1 -> V_15 ;
if ( ! F_37 ( V_86 ) )
return - V_87 ;
if ( V_1 -> V_88 == NULL || V_1 -> V_89 == NULL ||
( V_74 = V_71 -> V_90 ) <= V_84 -> V_91 ||
( V_84 -> V_91 && ( V_71 -> V_92 != V_84 -> V_93 ) ) )
return - V_94 ;
if ( ( error = F_38 ( V_84 , V_74 ) ) )
return error ;
error = F_39 ( V_1 -> V_88 ,
F_40 ( V_1 , V_74 - 1 ) ,
F_40 ( V_1 , 1 ) , 0 , & V_45 , NULL ) ;
if ( error )
return error ;
F_41 ( V_45 ) ;
V_76 = V_74 ;
F_42 ( V_76 , V_71 -> V_92 ) ;
V_75 = F_43 ( V_76 , V_95 * V_84 -> V_70 ) ;
V_77 = F_17 ( V_76 ) ;
V_79 = V_77 + 1 ;
V_80 = ( T_13 ) sizeof( T_6 ) * V_79 * V_75 ;
V_78 = F_44 ( V_1 , V_80 ) ;
V_80 = F_45 ( V_1 , V_78 ) ;
if ( V_78 > ( V_1 -> V_15 . V_96 >> 1 ) )
return - V_94 ;
V_82 = F_44 ( V_1 , V_1 -> V_89 -> V_97 . V_98 ) ;
V_83 = F_44 ( V_1 , V_1 -> V_99 -> V_97 . V_98 ) ;
error = F_21 ( V_1 , V_82 , V_75 , V_1 -> V_89 ) ;
if ( error )
return error ;
error = F_21 ( V_1 , V_83 , V_78 , V_1 -> V_99 ) ;
if ( error )
return error ;
V_73 = F_46 ( sizeof( * V_73 ) , V_100 ) ;
for ( V_72 = V_84 -> V_37 -
( ( V_84 -> V_16 & ( ( 1 << V_1 -> V_101 ) - 1 ) ) != 0 ) ;
V_72 < V_75 ;
V_72 ++ ) {
T_2 * V_2 ;
* V_73 = * V_1 ;
V_81 = & V_73 -> V_15 ;
V_81 -> V_93 = V_71 -> V_92 ;
V_81 -> V_37 = V_72 + 1 ;
V_81 -> V_91 =
F_20 ( V_74 ,
V_81 -> V_37 * V_95 *
V_81 -> V_70 * V_81 -> V_93 ) ;
V_81 -> V_16 = V_81 -> V_91 ;
F_42 ( V_81 -> V_16 , V_81 -> V_93 ) ;
ASSERT ( V_81 -> V_16 != 0 ) ;
V_81 -> V_102 = F_17 ( V_81 -> V_16 ) ;
V_79 = V_73 -> V_36 = V_81 -> V_102 + 1 ;
V_80 =
( T_13 ) sizeof( T_6 ) * V_79 *
V_81 -> V_37 ;
V_78 = F_44 ( V_1 , V_80 ) ;
V_73 -> V_103 = V_80 = F_45 ( V_1 , V_78 ) ;
error = F_23 ( V_1 , & F_24 ( V_1 ) -> V_104 , 0 , 0 , 0 ,
& V_2 ) ;
if ( error )
break;
F_25 ( V_1 -> V_89 , V_57 ) ;
F_26 ( V_2 , V_1 -> V_89 , V_57 ) ;
V_1 -> V_89 -> V_97 . V_98 =
V_81 -> V_37 * V_81 -> V_70 ;
F_47 ( V_2 , V_1 -> V_89 , V_105 ) ;
F_25 ( V_1 -> V_99 , V_57 ) ;
F_26 ( V_2 , V_1 -> V_99 , V_57 ) ;
V_1 -> V_99 -> V_97 . V_98 = V_73 -> V_103 ;
F_47 ( V_2 , V_1 -> V_99 , V_105 ) ;
if ( V_84 -> V_37 != V_81 -> V_37 ||
V_1 -> V_36 != V_73 -> V_36 ) {
error = F_48 ( V_1 , V_73 , V_2 ) ;
if ( error )
goto V_106;
}
if ( V_81 -> V_93 != V_84 -> V_93 )
F_49 ( V_2 , V_107 ,
V_81 -> V_93 - V_84 -> V_93 ) ;
if ( V_81 -> V_37 != V_84 -> V_37 )
F_49 ( V_2 , V_108 ,
V_81 -> V_37 - V_84 -> V_37 ) ;
if ( V_81 -> V_91 != V_84 -> V_91 )
F_49 ( V_2 , V_109 ,
V_81 -> V_91 - V_84 -> V_91 ) ;
if ( V_81 -> V_16 != V_84 -> V_16 )
F_49 ( V_2 , V_110 ,
V_81 -> V_16 - V_84 -> V_16 ) ;
if ( V_81 -> V_102 != V_84 -> V_102 )
F_49 ( V_2 , V_111 ,
V_81 -> V_102 - V_84 -> V_102 ) ;
V_45 = NULL ;
error = F_50 ( V_73 , V_2 , V_84 -> V_16 ,
V_81 -> V_16 - V_84 -> V_16 , & V_45 , & V_85 ) ;
if ( error ) {
V_106:
F_35 ( V_2 ) ;
break;
}
F_49 ( V_2 , V_112 ,
V_81 -> V_16 - V_84 -> V_16 ) ;
V_1 -> V_36 = V_79 ;
V_1 -> V_103 = V_80 ;
error = F_30 ( V_2 ) ;
if ( error )
break;
}
F_51 ( V_73 ) ;
return error ;
}
int
F_52 (
T_2 * V_2 ,
T_3 V_29 ,
T_7 V_17 ,
T_7 V_18 ,
T_7 * V_11 ,
int V_113 ,
T_7 V_20 ,
T_3 * V_21 )
{
T_1 * V_1 = V_2 -> V_114 ;
int error ;
T_3 V_35 ;
T_5 V_115 ;
T_4 * V_116 ;
ASSERT ( F_53 ( V_1 -> V_89 , V_57 ) ) ;
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
V_117:
V_116 = NULL ;
if ( V_29 == 0 ) {
error = F_18 ( V_1 , V_2 , V_17 , V_18 , V_11 ,
& V_116 , & V_115 , V_20 , & V_35 ) ;
} else {
error = F_16 ( V_1 , V_2 , V_29 , V_17 , V_18 ,
V_11 , & V_116 , & V_115 , V_20 , & V_35 ) ;
}
if ( error )
return error ;
if ( V_35 != V_28 ) {
long V_118 = ( long ) * V_11 ;
ASSERT ( * V_11 >= V_17 && * V_11 <= V_18 ) ;
if ( V_113 )
F_49 ( V_2 , V_119 , - V_118 ) ;
else
F_49 ( V_2 , V_112 , - V_118 ) ;
} else if ( V_20 > 1 ) {
V_20 = 1 ;
goto V_117;
}
* V_21 = V_35 ;
return 0 ;
}
int
F_54 (
struct V_39 * V_1 )
{
struct V_44 * V_45 ;
struct V_120 * V_84 ;
T_9 V_46 ;
int error ;
V_84 = & V_1 -> V_15 ;
if ( V_84 -> V_91 == 0 )
return 0 ;
if ( V_1 -> V_88 == NULL ) {
F_55 ( V_1 ,
L_1 ) ;
return - V_121 ;
}
V_1 -> V_36 = V_84 -> V_102 + 1 ;
V_1 -> V_103 =
( T_13 ) sizeof( T_6 ) * V_1 -> V_36 *
V_84 -> V_37 ;
V_1 -> V_103 = F_56 ( V_1 -> V_103 , V_84 -> V_70 ) ;
V_1 -> V_89 = V_1 -> V_99 = NULL ;
V_46 = ( T_9 ) F_40 ( V_1 , V_1 -> V_15 . V_91 ) ;
if ( F_57 ( V_1 , V_46 ) != V_1 -> V_15 . V_91 ) {
F_55 ( V_1 , L_2 ,
( unsigned long long ) F_57 ( V_1 , V_46 ) ,
( unsigned long long ) V_1 -> V_15 . V_91 ) ;
return - V_122 ;
}
error = F_39 ( V_1 -> V_88 ,
V_46 - F_40 ( V_1 , 1 ) ,
F_40 ( V_1 , 1 ) , 0 , & V_45 , NULL ) ;
if ( error ) {
F_55 ( V_1 , L_3 ) ;
return error ;
}
F_41 ( V_45 ) ;
return 0 ;
}
int
F_58 (
T_1 * V_1 )
{
int error ;
T_14 * V_84 ;
V_84 = & V_1 -> V_15 ;
if ( V_84 -> V_123 == V_124 )
return 0 ;
error = F_59 ( V_1 , NULL , V_84 -> V_123 , 0 , 0 , & V_1 -> V_89 ) ;
if ( error )
return error ;
ASSERT ( V_1 -> V_89 != NULL ) ;
ASSERT ( V_84 -> V_125 != V_124 ) ;
error = F_59 ( V_1 , NULL , V_84 -> V_125 , 0 , 0 , & V_1 -> V_99 ) ;
if ( error ) {
F_60 ( V_1 -> V_89 ) ;
return error ;
}
ASSERT ( V_1 -> V_99 != NULL ) ;
return 0 ;
}
void
F_61 (
struct V_39 * V_1 )
{
if ( V_1 -> V_89 )
F_60 ( V_1 -> V_89 ) ;
if ( V_1 -> V_99 )
F_60 ( V_1 -> V_99 ) ;
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
T_15 V_129 ;
T_15 V_130 ;
T_15 * V_131 ;
ASSERT ( F_53 ( V_1 -> V_89 , V_57 ) ) ;
V_131 = ( T_15 * ) & F_63 ( V_1 -> V_89 ) -> V_132 ;
if ( ! ( V_1 -> V_89 -> V_97 . V_133 & V_134 ) ) {
V_1 -> V_89 -> V_97 . V_133 |= V_134 ;
* V_131 = 0 ;
}
V_130 = * V_131 ;
if ( ( V_128 = F_64 ( V_130 ) ) == - 1 )
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
F_47 ( V_2 , V_1 -> V_89 , V_105 ) ;
* V_126 = V_127 ;
return 0 ;
}
