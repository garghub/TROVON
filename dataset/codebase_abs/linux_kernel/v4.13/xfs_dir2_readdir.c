static unsigned char
F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
if ( ! F_2 ( & V_2 -> V_4 ) )
return V_5 ;
if ( V_3 >= V_6 )
return V_5 ;
return V_7 [ V_3 ] ;
}
STATIC int
F_3 (
struct V_8 * args ,
struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_13 = args -> V_13 ;
T_2 V_14 ;
T_3 * V_15 ;
T_4 * V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_5 V_19 ;
struct V_20 * V_21 = args -> V_21 ;
ASSERT ( V_13 -> V_22 . V_23 & V_24 ) ;
ASSERT ( V_13 -> V_22 . V_25 == V_13 -> V_26 . V_27 ) ;
ASSERT ( V_13 -> V_22 . V_28 . V_29 != NULL ) ;
V_16 = ( T_4 * ) V_13 -> V_22 . V_28 . V_29 ;
if ( F_4 ( V_21 , V_10 -> V_30 ) > V_21 -> V_31 )
return 0 ;
V_17 = F_5 ( V_21 , V_21 -> V_31 ,
V_13 -> V_32 -> V_33 ) ;
V_18 = F_5 ( V_21 , V_21 -> V_31 ,
V_13 -> V_32 -> V_34 ) ;
if ( V_10 -> V_30 <= V_17 ) {
V_10 -> V_30 = V_17 & 0x7fffffff ;
if ( ! F_6 ( V_10 , L_1 , 1 , V_13 -> V_35 , V_36 ) )
return 0 ;
}
if ( V_10 -> V_30 <= V_18 ) {
V_19 = V_13 -> V_32 -> V_37 ( V_16 ) ;
V_10 -> V_30 = V_18 & 0x7fffffff ;
if ( ! F_6 ( V_10 , L_2 , 2 , V_19 , V_36 ) )
return 0 ;
}
V_15 = F_7 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_38 ; V_11 ++ ) {
T_1 V_3 ;
V_14 = F_5 ( V_21 , V_21 -> V_31 ,
F_8 ( V_15 ) ) ;
if ( V_10 -> V_30 > V_14 ) {
V_15 = V_13 -> V_32 -> V_39 ( V_16 , V_15 ) ;
continue;
}
V_19 = V_13 -> V_32 -> V_40 ( V_16 , V_15 ) ;
V_3 = V_13 -> V_32 -> V_41 ( V_15 ) ;
V_10 -> V_30 = V_14 & 0x7fffffff ;
if ( ! F_6 ( V_10 , ( char * ) V_15 -> V_42 , V_15 -> V_43 , V_19 ,
F_1 ( V_13 -> V_44 , V_3 ) ) )
return 0 ;
V_15 = V_13 -> V_32 -> V_39 ( V_16 , V_15 ) ;
}
V_10 -> V_30 = F_5 ( V_21 , V_21 -> V_31 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_9 (
struct V_8 * args ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = args -> V_13 ;
T_6 * V_45 ;
struct V_46 * V_47 ;
T_7 * V_48 ;
T_8 * V_49 ;
T_9 * V_50 ;
char * V_51 ;
int error ;
char * V_52 ;
int V_53 ;
T_10 V_54 ;
struct V_20 * V_21 = args -> V_21 ;
int V_55 ;
if ( F_4 ( V_21 , V_10 -> V_30 ) > V_21 -> V_31 )
return 0 ;
V_55 = F_10 ( V_13 ) ;
error = F_11 ( args -> V_56 , V_13 , & V_47 ) ;
F_12 ( V_13 , V_55 ) ;
if ( error )
return error ;
V_53 = F_13 ( V_21 , V_10 -> V_30 ) ;
V_45 = V_47 -> V_57 ;
F_14 ( V_13 , V_47 ) ;
V_48 = F_15 ( V_21 , V_45 ) ;
V_52 = ( char * ) V_13 -> V_32 -> V_58 ( V_45 ) ;
V_51 = ( char * ) F_16 ( V_48 ) ;
while ( V_52 < V_51 ) {
T_1 V_3 ;
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_59 ) == V_60 ) {
V_52 += F_17 ( V_50 -> V_61 ) ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_52 += V_13 -> V_32 -> V_62 ( V_49 -> V_43 ) ;
if ( ( char * ) V_49 - ( char * ) V_45 < V_53 )
continue;
V_54 = F_5 ( V_21 , V_21 -> V_31 ,
( char * ) V_49 - ( char * ) V_45 ) ;
V_10 -> V_30 = V_54 & 0x7fffffff ;
V_3 = V_13 -> V_32 -> V_63 ( V_49 ) ;
if ( ! F_6 ( V_10 , ( char * ) V_49 -> V_42 , V_49 -> V_43 ,
F_18 ( V_49 -> V_64 ) ,
F_1 ( V_13 -> V_44 , V_3 ) ) ) {
F_19 ( args -> V_56 , V_47 ) ;
return 0 ;
}
}
V_10 -> V_30 = F_5 ( V_21 , V_21 -> V_31 + 1 , 0 ) &
0x7fffffff ;
F_19 ( args -> V_56 , V_47 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_8 * args ,
T_11 V_65 ,
T_12 * V_66 ,
T_13 * V_67 ,
struct V_46 * * V_68 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_46 * V_47 = NULL ;
struct V_20 * V_21 = args -> V_21 ;
struct V_69 * V_70 = F_21 ( V_13 , V_71 ) ;
struct V_72 V_73 ;
struct V_74 V_75 ;
T_12 V_76 ;
T_13 V_77 ;
T_13 V_78 ;
T_13 V_79 ;
T_14 V_80 ;
int V_81 ;
int error = 0 ;
if ( ! ( V_70 -> V_23 & V_82 ) ) {
error = F_22 ( args -> V_56 , V_13 , V_71 ) ;
if ( error )
goto V_83;
}
V_79 = F_23 ( V_21 , V_84 ) ;
V_78 = F_24 ( V_21 , F_25 ( V_21 , * V_66 ) ) ;
if ( ! F_26 ( V_13 , V_70 , V_78 , & V_80 , & V_73 ) )
goto V_83;
if ( V_73 . V_85 >= V_79 )
goto V_83;
F_27 ( & V_73 , V_78 , V_79 - V_78 ) ;
V_76 = F_28 ( V_21 , V_73 . V_85 ) ;
if ( V_76 > * V_66 )
* V_66 = V_76 ;
error = F_29 ( args -> V_56 , V_13 , V_73 . V_85 , - 1 , & V_47 ) ;
if ( error )
goto V_83;
V_81 = F_30 ( V_65 + V_21 -> V_86 , ( 1 << V_21 -> V_87 ) ) ;
if ( * V_67 >= V_79 )
goto V_83;
else if ( * V_67 == 0 )
* V_67 = V_73 . V_85 ;
V_77 = V_73 . V_85 + V_21 -> V_88 ;
if ( V_77 >= V_79 )
goto V_89;
if ( V_73 . V_90 < V_21 -> V_88 &&
! F_31 ( V_70 , ++ V_80 , & V_73 ) )
goto V_89;
if ( V_73 . V_85 >= V_79 )
goto V_89;
F_27 ( & V_73 , V_77 , V_79 - V_77 ) ;
F_32 ( & V_75 ) ;
while ( V_81 > 0 ) {
V_77 = F_33 ( ( T_13 ) V_73 . V_85 , V_21 -> V_88 ) ;
while ( V_81 > 0 &&
V_77 < V_73 . V_85 + V_73 . V_90 ) {
if ( V_77 >= V_79 ) {
* V_67 = V_79 ;
break;
}
if ( V_77 > * V_67 ) {
F_34 ( V_13 , V_77 , - 2 ) ;
* V_67 = V_77 ;
}
V_81 -= V_21 -> V_88 ;
V_77 += V_21 -> V_88 ;
}
if ( ! F_31 ( V_70 , ++ V_80 , & V_73 ) ) {
* V_67 = V_79 ;
break;
}
}
F_35 ( & V_75 ) ;
V_83:
* V_68 = V_47 ;
return error ;
V_89:
* V_67 = V_79 ;
goto V_83;
}
STATIC int
F_36 (
struct V_8 * args ,
struct V_9 * V_10 ,
T_11 V_65 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_46 * V_47 = NULL ;
T_6 * V_45 ;
T_8 * V_49 ;
T_9 * V_50 ;
char * V_52 = NULL ;
struct V_20 * V_21 = args -> V_21 ;
T_13 V_91 = 0 ;
T_12 V_92 ;
int V_61 ;
int V_93 ;
int V_55 ;
int error = 0 ;
if ( V_10 -> V_30 >= V_94 )
return 0 ;
V_92 = F_37 ( V_10 -> V_30 ) ;
while ( V_92 < V_84 ) {
T_1 V_3 ;
if ( ! V_47 || V_52 >= ( char * ) V_47 -> V_57 + V_21 -> V_86 ) {
if ( V_47 ) {
F_19 ( args -> V_56 , V_47 ) ;
V_47 = NULL ;
}
V_55 = F_10 ( V_13 ) ;
error = F_20 ( args , V_65 , & V_92 ,
& V_91 , & V_47 ) ;
F_12 ( V_13 , V_55 ) ;
if ( error || ! V_47 )
break;
V_45 = V_47 -> V_57 ;
F_14 ( V_13 , V_47 ) ;
V_52 = ( char * ) V_13 -> V_32 -> V_58 ( V_45 ) ;
V_93 = F_38 ( V_21 , V_92 ) ;
if ( V_93 == 0 )
V_92 += V_13 -> V_32 -> V_95 ;
else {
while ( ( char * ) V_52 - ( char * ) V_45 < V_93 ) {
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_59 )
== V_60 ) {
V_61 = F_17 ( V_50 -> V_61 ) ;
V_52 += V_61 ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_61 =
V_13 -> V_32 -> V_62 ( V_49 -> V_43 ) ;
V_52 += V_61 ;
}
V_92 =
F_39 ( V_21 ,
F_25 ( V_21 , V_92 ) ,
( char * ) V_52 - ( char * ) V_45 ) ;
if ( V_52 >= ( char * ) V_45 + V_21 -> V_86 ) {
continue;
}
}
}
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_59 ) == V_60 ) {
V_61 = F_17 ( V_50 -> V_61 ) ;
V_52 += V_61 ;
V_92 += V_61 ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_61 = V_13 -> V_32 -> V_62 ( V_49 -> V_43 ) ;
V_3 = V_13 -> V_32 -> V_63 ( V_49 ) ;
V_10 -> V_30 = F_40 ( V_92 ) & 0x7fffffff ;
if ( ! F_6 ( V_10 , ( char * ) V_49 -> V_42 , V_49 -> V_43 ,
F_18 ( V_49 -> V_64 ) ,
F_1 ( V_13 -> V_44 , V_3 ) ) )
break;
V_52 += V_61 ;
V_92 += V_61 ;
V_65 = V_65 > V_61 ? V_65 - V_61 : 0 ;
}
if ( V_92 > F_37 ( V_94 ) )
V_10 -> V_30 = V_94 & 0x7fffffff ;
else
V_10 -> V_30 = F_40 ( V_92 ) & 0x7fffffff ;
if ( V_47 )
F_19 ( args -> V_56 , V_47 ) ;
return error ;
}
int
F_41 (
struct V_96 * V_97 ,
struct V_12 * V_13 ,
struct V_9 * V_10 ,
T_11 V_65 )
{
struct V_8 args = { NULL } ;
int V_98 ;
int V_99 ;
F_42 ( V_13 ) ;
if ( F_43 ( V_13 -> V_44 ) )
return - V_100 ;
ASSERT ( F_44 ( F_45 ( V_13 ) -> V_101 ) ) ;
F_46 ( V_13 -> V_44 , V_102 ) ;
args . V_13 = V_13 ;
args . V_21 = V_13 -> V_44 -> V_103 ;
args . V_56 = V_97 ;
if ( V_13 -> V_26 . V_104 == V_105 )
V_98 = F_3 ( & args , V_10 ) ;
else if ( ( V_98 = F_47 ( & args , & V_99 ) ) )
;
else if ( V_99 )
V_98 = F_9 ( & args , V_10 ) ;
else
V_98 = F_36 ( & args , V_10 , V_65 ) ;
return V_98 ;
}
