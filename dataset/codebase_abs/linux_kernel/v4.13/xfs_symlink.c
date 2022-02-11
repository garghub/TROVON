int
F_1 (
struct V_1 * V_2 ,
char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 V_8 [ V_9 ] ;
struct V_10 * V_11 ;
T_1 V_12 ;
char * V_13 ;
int V_14 = V_2 -> V_15 . V_16 ;
int V_17 = V_9 ;
int V_18 ;
int V_19 ;
int error = 0 ;
int V_20 = 0 ;
int V_21 ;
ASSERT ( F_2 ( V_2 , V_22 | V_23 ) ) ;
V_20 = F_3 ( V_5 , V_14 ) ;
error = F_4 ( V_2 , 0 , V_20 , V_8 , & V_17 , 0 ) ;
if ( error )
goto V_24;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
V_12 = F_5 ( V_5 , V_8 [ V_19 ] . V_25 ) ;
V_18 = F_6 ( V_5 , V_8 [ V_19 ] . V_26 ) ;
V_11 = F_7 ( V_5 -> V_27 , V_12 , F_8 ( V_18 ) , 0 ,
& V_28 ) ;
if ( ! V_11 )
return - V_29 ;
error = V_11 -> V_30 ;
if ( error ) {
F_9 ( V_11 , V_31 ) ;
F_10 ( V_11 ) ;
if ( error == - V_32 )
error = - V_33 ;
goto V_24;
}
V_18 = F_11 ( V_5 , V_18 ) ;
if ( V_14 < V_18 )
V_18 = V_14 ;
V_13 = V_11 -> V_34 ;
if ( F_12 ( & V_5 -> V_35 ) ) {
if ( ! F_13 ( V_2 -> V_36 , V_21 ,
V_18 , V_11 ) ) {
error = - V_33 ;
F_14 ( V_5 ,
L_1 ,
V_21 , V_18 , V_2 -> V_36 ) ;
F_10 ( V_11 ) ;
goto V_24;
}
V_13 += sizeof( struct V_37 ) ;
}
memcpy ( V_3 + V_21 , V_13 , V_18 ) ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_10 ( V_11 ) ;
}
ASSERT ( V_14 == 0 ) ;
V_3 [ V_2 -> V_15 . V_16 ] = '\0' ;
error = 0 ;
V_24:
return error ;
}
int
F_15 (
struct V_1 * V_2 ,
char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_14 ;
int error = 0 ;
F_16 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_38 . V_39 & V_40 ) ) ;
if ( F_17 ( V_5 ) )
return - V_41 ;
F_18 ( V_2 , V_22 ) ;
V_14 = V_2 -> V_15 . V_16 ;
if ( ! V_14 )
goto V_24;
if ( V_14 < 0 || V_14 > V_42 ) {
F_14 ( V_5 , L_2 ,
V_31 , ( unsigned long long ) V_2 -> V_36 ,
( long long ) V_14 ) ;
ASSERT ( 0 ) ;
error = - V_33 ;
goto V_24;
}
error = F_1 ( V_2 , V_3 ) ;
V_24:
F_19 ( V_2 , V_22 ) ;
return error ;
}
int
F_20 (
struct V_1 * V_43 ,
struct V_44 * V_45 ,
const char * V_46 ,
T_3 V_47 ,
struct V_1 * * V_48 )
{
struct V_4 * V_5 = V_43 -> V_6 ;
struct V_49 * V_50 = NULL ;
struct V_1 * V_2 = NULL ;
int error = 0 ;
int V_14 ;
struct V_51 V_52 ;
T_4 V_53 ;
bool V_54 = false ;
T_5 V_55 ;
T_6 V_56 ;
int V_17 ;
struct V_7 V_8 [ V_9 ] ;
T_1 V_12 ;
const char * V_13 ;
int V_18 ;
int V_19 ;
T_7 * V_11 ;
T_8 V_57 ;
struct V_58 * V_59 = NULL ;
struct V_58 * V_60 = NULL ;
struct V_58 * V_61 = NULL ;
T_9 V_62 ;
* V_48 = NULL ;
F_21 ( V_43 , V_45 ) ;
if ( F_17 ( V_5 ) )
return - V_41 ;
V_14 = strlen ( V_46 ) ;
if ( V_14 >= V_42 )
return - V_63 ;
V_59 = V_60 = NULL ;
V_57 = F_22 ( V_43 ) ;
error = F_23 ( V_43 ,
F_24 ( F_25 () ) ,
F_26 ( F_27 () ) , V_57 ,
V_64 | V_65 ,
& V_59 , & V_60 , & V_61 ) ;
if ( error )
return error ;
if ( V_14 <= F_28 ( V_5 , V_43 -> V_15 . V_66 ) )
V_56 = 0 ;
else
V_56 = F_3 ( V_5 , V_14 ) ;
V_62 = F_29 ( V_5 , V_45 -> V_67 , V_56 ) ;
error = F_30 ( V_5 , & F_31 ( V_5 ) -> V_68 , V_62 , 0 , 0 , & V_50 ) ;
if ( error == - V_69 && V_56 == 0 ) {
V_62 = 0 ;
error = F_30 ( V_5 , & F_31 ( V_5 ) -> V_68 , 0 , 0 , 0 ,
& V_50 ) ;
}
if ( error )
goto V_70;
F_18 ( V_43 , V_23 | V_71 ) ;
V_54 = true ;
if ( V_43 -> V_15 . V_72 & V_73 ) {
error = - V_74 ;
goto V_75;
}
error = F_32 ( V_50 , V_5 , V_59 , V_60 ,
V_61 , V_62 , 1 , 0 ) ;
if ( error )
goto V_75;
if ( ! V_62 ) {
error = F_33 ( V_50 , V_43 , V_45 ) ;
if ( error )
goto V_75;
}
F_34 ( & V_52 , & V_53 ) ;
error = F_35 ( & V_50 , V_43 , V_76 | ( V_47 & ~ V_77 ) , 1 , 0 ,
V_57 , V_62 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_75;
F_36 ( V_50 , V_43 , V_23 ) ;
V_54 = false ;
F_37 ( V_50 , V_2 , V_59 , V_60 , V_61 ) ;
if ( V_62 )
V_62 -= F_38 ( V_5 ) ;
if ( V_14 <= F_39 ( V_2 ) ) {
F_40 ( V_2 , V_78 , V_46 , V_14 ) ;
V_2 -> V_15 . V_16 = V_14 ;
V_2 -> V_15 . V_79 = V_80 ;
F_41 ( V_50 , V_2 , V_81 | V_82 ) ;
} else {
int V_21 ;
V_55 = 0 ;
V_17 = V_9 ;
error = F_42 ( V_50 , V_2 , V_55 , V_56 ,
V_83 , & V_53 , V_62 ,
V_8 , & V_17 , & V_52 ) ;
if ( error )
goto V_84;
if ( V_62 )
V_62 -= V_56 ;
V_2 -> V_15 . V_16 = V_14 ;
F_41 ( V_50 , V_2 , V_82 ) ;
V_13 = V_46 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
char * V_85 ;
V_12 = F_5 ( V_5 , V_8 [ V_19 ] . V_25 ) ;
V_18 = F_6 ( V_5 , V_8 [ V_19 ] . V_26 ) ;
V_11 = F_43 ( V_50 , V_5 -> V_27 , V_12 ,
F_8 ( V_18 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_29 ;
goto V_84;
}
V_11 -> V_86 = & V_28 ;
V_18 = F_11 ( V_5 , V_18 ) ;
V_18 = F_44 ( V_18 , V_14 ) ;
V_85 = V_11 -> V_34 ;
V_85 += F_45 ( V_5 , V_2 -> V_36 , V_21 ,
V_18 , V_11 ) ;
memcpy ( V_85 , V_13 , V_18 ) ;
V_13 += V_18 ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_46 ( V_50 , V_11 , V_87 ) ;
F_47 ( V_50 , V_11 , 0 , ( V_85 + V_18 - 1 ) -
( char * ) V_11 -> V_34 ) ;
}
ASSERT ( V_14 == 0 ) ;
}
error = F_48 ( V_50 , V_43 , V_45 , V_2 -> V_36 ,
& V_53 , & V_52 , V_62 ) ;
if ( error )
goto V_84;
F_49 ( V_50 , V_43 , V_88 | V_89 ) ;
F_41 ( V_50 , V_43 , V_82 ) ;
if ( V_5 -> V_90 & ( V_91 | V_92 ) ) {
F_50 ( V_50 ) ;
}
error = F_51 ( & V_50 , & V_52 , NULL ) ;
if ( error )
goto V_84;
error = F_52 ( V_50 ) ;
if ( error )
goto V_70;
F_53 ( V_59 ) ;
F_53 ( V_60 ) ;
F_53 ( V_61 ) ;
* V_48 = V_2 ;
return 0 ;
V_84:
F_54 ( & V_52 ) ;
V_75:
F_55 ( V_50 ) ;
V_70:
if ( V_2 ) {
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
}
F_53 ( V_59 ) ;
F_53 ( V_60 ) ;
F_53 ( V_61 ) ;
if ( V_54 )
F_19 ( V_43 , V_23 ) ;
return error ;
}
STATIC int
F_58 (
struct V_1 * V_2 )
{
T_7 * V_11 ;
int V_93 ;
int error ;
T_4 V_53 ;
struct V_51 V_52 ;
int V_94 ;
T_10 * V_5 ;
T_11 V_8 [ V_9 ] ;
int V_17 ;
int V_95 ;
T_12 * V_50 ;
V_5 = V_2 -> V_6 ;
ASSERT ( V_2 -> V_38 . V_39 & V_96 ) ;
ASSERT ( V_2 -> V_15 . V_97 > 0 && V_2 -> V_15 . V_97 <= 2 ) ;
error = F_30 ( V_5 , & F_31 ( V_5 ) -> V_98 , 0 , 0 , 0 , & V_50 ) ;
if ( error )
return error ;
F_18 ( V_2 , V_23 ) ;
F_36 ( V_50 , V_2 , 0 ) ;
V_95 = ( int ) V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = 0 ;
F_41 ( V_50 , V_2 , V_82 ) ;
V_93 = 0 ;
F_34 ( & V_52 , & V_53 ) ;
V_17 = F_59 ( V_8 ) ;
error = F_4 ( V_2 , 0 , F_3 ( V_5 , V_95 ) ,
V_8 , & V_17 , 0 ) ;
if ( error )
goto V_99;
for ( V_94 = 0 ; V_94 < V_17 ; V_94 ++ ) {
V_11 = F_43 ( V_50 , V_5 -> V_27 ,
F_5 ( V_5 , V_8 [ V_94 ] . V_25 ) ,
F_60 ( V_5 , V_8 [ V_94 ] . V_26 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_29 ;
goto V_100;
}
F_61 ( V_50 , V_11 ) ;
}
error = F_62 ( V_50 , V_2 , 0 , V_95 , 0 , V_17 ,
& V_53 , & V_52 , & V_93 ) ;
if ( error )
goto V_100;
ASSERT ( V_93 ) ;
error = F_51 ( & V_50 , & V_52 , V_2 ) ;
if ( error )
goto V_100;
F_36 ( V_50 , V_2 , 0 ) ;
F_41 ( V_50 , V_2 , V_82 ) ;
error = F_52 ( V_50 ) ;
if ( error ) {
ASSERT ( F_17 ( V_5 ) ) ;
goto V_101;
}
if ( V_2 -> V_38 . V_102 )
F_63 ( V_2 , - V_2 -> V_38 . V_102 , V_78 ) ;
ASSERT ( V_2 -> V_38 . V_102 == 0 ) ;
F_19 ( V_2 , V_23 ) ;
return 0 ;
V_100:
F_54 ( & V_52 ) ;
V_99:
F_55 ( V_50 ) ;
V_101:
F_19 ( V_2 , V_23 ) ;
return error ;
}
int
F_64 (
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_14 ;
F_65 ( V_2 ) ;
if ( F_17 ( V_5 ) )
return - V_41 ;
F_18 ( V_2 , V_23 ) ;
V_14 = ( int ) V_2 -> V_15 . V_16 ;
if ( ! V_14 ) {
F_19 ( V_2 , V_23 ) ;
return 0 ;
}
if ( V_14 < 0 || V_14 > V_42 ) {
F_14 ( V_5 , L_3 ,
V_31 , ( unsigned long long ) V_2 -> V_36 , V_14 ) ;
F_19 ( V_2 , V_23 ) ;
ASSERT ( 0 ) ;
return - V_33 ;
}
if ( V_2 -> V_38 . V_39 & V_40 ) {
if ( V_2 -> V_38 . V_102 > 0 )
F_63 ( V_2 , - ( V_2 -> V_38 . V_102 ) ,
V_78 ) ;
F_19 ( V_2 , V_23 ) ;
ASSERT ( V_2 -> V_38 . V_102 == 0 ) ;
return 0 ;
}
F_19 ( V_2 , V_23 ) ;
return F_58 ( V_2 ) ;
}
