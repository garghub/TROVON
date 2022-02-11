STATIC int
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
V_20 = F_2 ( V_5 , V_14 ) ;
error = F_3 ( V_2 , 0 , V_20 , V_8 , & V_17 , 0 ) ;
if ( error )
goto V_22;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
V_12 = F_4 ( V_5 , V_8 [ V_19 ] . V_23 ) ;
V_18 = F_5 ( V_5 , V_8 [ V_19 ] . V_24 ) ;
V_11 = F_6 ( V_5 -> V_25 , V_12 , F_7 ( V_18 ) , 0 ,
& V_26 ) ;
if ( ! V_11 )
return - V_27 ;
error = V_11 -> V_28 ;
if ( error ) {
F_8 ( V_11 , V_29 ) ;
F_9 ( V_11 ) ;
if ( error == - V_30 )
error = - V_31 ;
goto V_22;
}
V_18 = F_10 ( V_5 , V_18 ) ;
if ( V_14 < V_18 )
V_18 = V_14 ;
V_13 = V_11 -> V_32 ;
if ( F_11 ( & V_5 -> V_33 ) ) {
if ( ! F_12 ( V_2 -> V_34 , V_21 ,
V_18 , V_11 ) ) {
error = - V_31 ;
F_13 ( V_5 ,
L_1 ,
V_21 , V_18 , V_2 -> V_34 ) ;
F_9 ( V_11 ) ;
goto V_22;
}
V_13 += sizeof( struct V_35 ) ;
}
memcpy ( V_3 + V_21 , V_13 , V_18 ) ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_9 ( V_11 ) ;
}
ASSERT ( V_14 == 0 ) ;
V_3 [ V_2 -> V_15 . V_16 ] = '\0' ;
error = 0 ;
V_22:
return error ;
}
int
F_14 (
struct V_1 * V_2 ,
char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_14 ;
int error = 0 ;
F_15 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_36 . V_37 & V_38 ) ) ;
if ( F_16 ( V_5 ) )
return - V_39 ;
F_17 ( V_2 , V_40 ) ;
V_14 = V_2 -> V_15 . V_16 ;
if ( ! V_14 )
goto V_22;
if ( V_14 < 0 || V_14 > V_41 ) {
F_13 ( V_5 , L_2 ,
V_29 , ( unsigned long long ) V_2 -> V_34 ,
( long long ) V_14 ) ;
ASSERT ( 0 ) ;
error = - V_31 ;
goto V_22;
}
error = F_1 ( V_2 , V_3 ) ;
V_22:
F_18 ( V_2 , V_40 ) ;
return error ;
}
int
F_19 (
struct V_1 * V_42 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_3 V_46 ,
struct V_1 * * V_47 )
{
struct V_4 * V_5 = V_42 -> V_6 ;
struct V_48 * V_49 = NULL ;
struct V_1 * V_2 = NULL ;
int error = 0 ;
int V_14 ;
struct V_50 V_51 ;
T_4 V_52 ;
bool V_53 = false ;
T_5 V_54 ;
T_6 V_55 ;
int V_17 ;
struct V_7 V_8 [ V_9 ] ;
T_1 V_12 ;
const char * V_13 ;
int V_18 ;
int V_19 ;
T_7 * V_11 ;
T_8 V_56 ;
struct V_57 * V_58 = NULL ;
struct V_57 * V_59 = NULL ;
struct V_57 * V_60 = NULL ;
T_9 V_61 ;
* V_47 = NULL ;
F_20 ( V_42 , V_44 ) ;
if ( F_16 ( V_5 ) )
return - V_39 ;
V_14 = strlen ( V_45 ) ;
if ( V_14 >= V_41 )
return - V_62 ;
V_58 = V_59 = NULL ;
V_56 = F_21 ( V_42 ) ;
error = F_22 ( V_42 ,
F_23 ( F_24 () ) ,
F_25 ( F_26 () ) , V_56 ,
V_63 | V_64 ,
& V_58 , & V_59 , & V_60 ) ;
if ( error )
return error ;
if ( V_14 <= F_27 ( V_5 , V_42 -> V_15 . V_65 ) )
V_55 = 0 ;
else
V_55 = F_2 ( V_5 , V_14 ) ;
V_61 = F_28 ( V_5 , V_44 -> V_66 , V_55 ) ;
error = F_29 ( V_5 , & F_30 ( V_5 ) -> V_67 , V_61 , 0 , 0 , & V_49 ) ;
if ( error == - V_68 && V_55 == 0 ) {
V_61 = 0 ;
error = F_29 ( V_5 , & F_30 ( V_5 ) -> V_67 , 0 , 0 , 0 ,
& V_49 ) ;
}
if ( error )
goto V_69;
F_17 ( V_42 , V_70 | V_71 |
V_72 | V_73 ) ;
V_53 = true ;
if ( V_42 -> V_15 . V_74 & V_75 ) {
error = - V_76 ;
goto V_77;
}
error = F_31 ( V_49 , V_5 , V_58 , V_59 ,
V_60 , V_61 , 1 , 0 ) ;
if ( error )
goto V_77;
if ( ! V_61 ) {
error = F_32 ( V_49 , V_42 , V_44 ) ;
if ( error )
goto V_77;
}
F_33 ( & V_51 , & V_52 ) ;
error = F_34 ( & V_49 , V_42 , V_78 | ( V_46 & ~ V_79 ) , 1 , 0 ,
V_56 , V_61 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_77;
F_35 ( V_49 , V_42 , V_70 | V_71 ) ;
V_53 = false ;
F_36 ( V_49 , V_2 , V_58 , V_59 , V_60 ) ;
if ( V_61 )
V_61 -= F_37 ( V_5 ) ;
if ( V_14 <= F_38 ( V_2 ) ) {
F_39 ( V_2 , V_80 , V_45 , V_14 ) ;
V_2 -> V_15 . V_16 = V_14 ;
V_2 -> V_15 . V_81 = V_82 ;
F_40 ( V_49 , V_2 , V_83 | V_84 ) ;
} else {
int V_21 ;
V_54 = 0 ;
V_17 = V_9 ;
error = F_41 ( V_49 , V_2 , V_54 , V_55 ,
V_85 , & V_52 , V_61 ,
V_8 , & V_17 , & V_51 ) ;
if ( error )
goto V_86;
if ( V_61 )
V_61 -= V_55 ;
V_2 -> V_15 . V_16 = V_14 ;
F_40 ( V_49 , V_2 , V_84 ) ;
V_13 = V_45 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
char * V_87 ;
V_12 = F_4 ( V_5 , V_8 [ V_19 ] . V_23 ) ;
V_18 = F_5 ( V_5 , V_8 [ V_19 ] . V_24 ) ;
V_11 = F_42 ( V_49 , V_5 -> V_25 , V_12 ,
F_7 ( V_18 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_27 ;
goto V_86;
}
V_11 -> V_88 = & V_26 ;
V_18 = F_10 ( V_5 , V_18 ) ;
V_18 = F_43 ( V_18 , V_14 ) ;
V_87 = V_11 -> V_32 ;
V_87 += F_44 ( V_5 , V_2 -> V_34 , V_21 ,
V_18 , V_11 ) ;
memcpy ( V_87 , V_13 , V_18 ) ;
V_13 += V_18 ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_45 ( V_49 , V_11 , V_89 ) ;
F_46 ( V_49 , V_11 , 0 , ( V_87 + V_18 - 1 ) -
( char * ) V_11 -> V_32 ) ;
}
ASSERT ( V_14 == 0 ) ;
}
error = F_47 ( V_49 , V_42 , V_44 , V_2 -> V_34 ,
& V_52 , & V_51 , V_61 ) ;
if ( error )
goto V_86;
F_48 ( V_49 , V_42 , V_90 | V_91 ) ;
F_40 ( V_49 , V_42 , V_84 ) ;
if ( V_5 -> V_92 & ( V_93 | V_94 ) ) {
F_49 ( V_49 ) ;
}
error = F_50 ( & V_49 , & V_51 , NULL ) ;
if ( error )
goto V_86;
error = F_51 ( V_49 ) ;
if ( error )
goto V_69;
F_52 ( V_58 ) ;
F_52 ( V_59 ) ;
F_52 ( V_60 ) ;
* V_47 = V_2 ;
return 0 ;
V_86:
F_53 ( & V_51 ) ;
V_77:
F_54 ( V_49 ) ;
V_69:
if ( V_2 ) {
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
}
F_52 ( V_58 ) ;
F_52 ( V_59 ) ;
F_52 ( V_60 ) ;
if ( V_53 )
F_18 ( V_42 , V_70 | V_71 ) ;
return error ;
}
STATIC int
F_57 (
struct V_1 * V_2 )
{
T_7 * V_11 ;
int V_95 ;
int error ;
T_4 V_52 ;
struct V_50 V_51 ;
int V_96 ;
T_10 * V_5 ;
T_11 V_8 [ V_9 ] ;
int V_17 ;
int V_97 ;
T_12 * V_49 ;
V_5 = V_2 -> V_6 ;
ASSERT ( V_2 -> V_36 . V_37 & V_98 ) ;
ASSERT ( V_2 -> V_15 . V_99 > 0 && V_2 -> V_15 . V_99 <= 2 ) ;
error = F_29 ( V_5 , & F_30 ( V_5 ) -> V_100 , 0 , 0 , 0 , & V_49 ) ;
if ( error )
return error ;
F_17 ( V_2 , V_71 ) ;
F_35 ( V_49 , V_2 , 0 ) ;
V_97 = ( int ) V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = 0 ;
F_40 ( V_49 , V_2 , V_84 ) ;
V_95 = 0 ;
F_33 ( & V_51 , & V_52 ) ;
V_17 = F_58 ( V_8 ) ;
error = F_3 ( V_2 , 0 , F_2 ( V_5 , V_97 ) ,
V_8 , & V_17 , 0 ) ;
if ( error )
goto V_101;
for ( V_96 = 0 ; V_96 < V_17 ; V_96 ++ ) {
V_11 = F_42 ( V_49 , V_5 -> V_25 ,
F_4 ( V_5 , V_8 [ V_96 ] . V_23 ) ,
F_59 ( V_5 , V_8 [ V_96 ] . V_24 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_27 ;
goto V_102;
}
F_60 ( V_49 , V_11 ) ;
}
error = F_61 ( V_49 , V_2 , 0 , V_97 , 0 , V_17 ,
& V_52 , & V_51 , & V_95 ) ;
if ( error )
goto V_102;
ASSERT ( V_95 ) ;
error = F_50 ( & V_49 , & V_51 , V_2 ) ;
if ( error )
goto V_102;
F_35 ( V_49 , V_2 , 0 ) ;
F_40 ( V_49 , V_2 , V_84 ) ;
error = F_51 ( V_49 ) ;
if ( error ) {
ASSERT ( F_16 ( V_5 ) ) ;
goto V_103;
}
if ( V_2 -> V_36 . V_104 )
F_62 ( V_2 , - V_2 -> V_36 . V_104 , V_80 ) ;
ASSERT ( V_2 -> V_36 . V_104 == 0 ) ;
F_18 ( V_2 , V_71 ) ;
return 0 ;
V_102:
F_53 ( & V_51 ) ;
V_101:
F_54 ( V_49 ) ;
V_103:
F_18 ( V_2 , V_71 ) ;
return error ;
}
int
F_63 (
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_14 ;
F_64 ( V_2 ) ;
if ( F_16 ( V_5 ) )
return - V_39 ;
F_17 ( V_2 , V_71 ) ;
V_14 = ( int ) V_2 -> V_15 . V_16 ;
if ( ! V_14 ) {
F_18 ( V_2 , V_71 ) ;
return 0 ;
}
if ( V_14 < 0 || V_14 > V_41 ) {
F_13 ( V_5 , L_3 ,
V_29 , ( unsigned long long ) V_2 -> V_34 , V_14 ) ;
F_18 ( V_2 , V_71 ) ;
ASSERT ( 0 ) ;
return - V_31 ;
}
if ( V_2 -> V_36 . V_37 & V_38 ) {
if ( V_2 -> V_36 . V_104 > 0 )
F_62 ( V_2 , - ( V_2 -> V_36 . V_104 ) ,
V_80 ) ;
F_18 ( V_2 , V_71 ) ;
ASSERT ( V_2 -> V_36 . V_104 == 0 ) ;
return 0 ;
}
F_18 ( V_2 , V_71 ) ;
return F_57 ( V_2 ) ;
}
