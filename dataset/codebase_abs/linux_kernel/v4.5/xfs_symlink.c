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
if ( F_16 ( V_5 ) )
return - V_36 ;
F_17 ( V_2 , V_37 ) ;
V_14 = V_2 -> V_15 . V_16 ;
if ( ! V_14 )
goto V_22;
if ( V_14 < 0 || V_14 > V_38 ) {
F_13 ( V_5 , L_2 ,
V_29 , ( unsigned long long ) V_2 -> V_34 ,
( long long ) V_14 ) ;
ASSERT ( 0 ) ;
error = - V_31 ;
goto V_22;
}
if ( V_2 -> V_39 . V_40 & V_41 ) {
memcpy ( V_3 , V_2 -> V_39 . V_42 . V_43 , V_14 ) ;
V_3 [ V_14 ] = '\0' ;
} else {
error = F_1 ( V_2 , V_3 ) ;
}
V_22:
F_18 ( V_2 , V_37 ) ;
return error ;
}
int
F_19 (
struct V_1 * V_44 ,
struct V_45 * V_46 ,
const char * V_47 ,
T_3 V_48 ,
struct V_1 * * V_49 )
{
struct V_4 * V_5 = V_44 -> V_6 ;
struct V_50 * V_51 = NULL ;
struct V_1 * V_2 = NULL ;
int error = 0 ;
int V_14 ;
struct V_52 V_53 ;
T_4 V_54 ;
bool V_55 = false ;
T_5 V_56 ;
T_6 V_57 ;
int V_17 ;
struct V_7 V_8 [ V_9 ] ;
T_1 V_12 ;
const char * V_13 ;
int V_18 ;
int V_19 ;
T_7 * V_11 ;
T_8 V_58 ;
struct V_59 * V_60 = NULL ;
struct V_59 * V_61 = NULL ;
struct V_59 * V_62 = NULL ;
T_9 V_63 ;
* V_49 = NULL ;
F_20 ( V_44 , V_46 ) ;
if ( F_16 ( V_5 ) )
return - V_36 ;
V_14 = strlen ( V_47 ) ;
if ( V_14 >= V_38 )
return - V_64 ;
V_60 = V_61 = NULL ;
V_58 = F_21 ( V_44 ) ;
error = F_22 ( V_44 ,
F_23 ( F_24 () ) ,
F_25 ( F_26 () ) , V_58 ,
V_65 | V_66 ,
& V_60 , & V_61 , & V_62 ) ;
if ( error )
return error ;
V_51 = F_27 ( V_5 , V_67 ) ;
if ( V_14 <= F_28 ( V_5 , V_44 -> V_15 . V_68 ) )
V_57 = 0 ;
else
V_57 = F_2 ( V_5 , V_14 ) ;
V_63 = F_29 ( V_5 , V_46 -> V_69 , V_57 ) ;
error = F_30 ( V_51 , & F_31 ( V_5 ) -> V_70 , V_63 , 0 ) ;
if ( error == - V_71 && V_57 == 0 ) {
V_63 = 0 ;
error = F_30 ( V_51 , & F_31 ( V_5 ) -> V_70 , 0 , 0 ) ;
}
if ( error )
goto V_72;
F_17 ( V_44 , V_73 | V_74 |
V_75 | V_76 ) ;
V_55 = true ;
if ( V_44 -> V_15 . V_77 & V_78 ) {
error = - V_79 ;
goto V_72;
}
error = F_32 ( V_51 , V_5 , V_60 , V_61 ,
V_62 , V_63 , 1 , 0 ) ;
if ( error )
goto V_72;
if ( ! V_63 ) {
error = F_33 ( V_51 , V_44 , V_46 ) ;
if ( error )
goto V_72;
}
F_34 ( & V_53 , & V_54 ) ;
error = F_35 ( & V_51 , V_44 , V_80 | ( V_48 & ~ V_81 ) , 1 , 0 ,
V_58 , V_63 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_72;
F_36 ( V_51 , V_44 , V_73 | V_74 ) ;
V_55 = false ;
F_37 ( V_51 , V_2 , V_60 , V_61 , V_62 ) ;
if ( V_63 )
V_63 -= F_38 ( V_5 ) ;
if ( V_14 <= F_39 ( V_2 ) ) {
F_40 ( V_2 , V_14 , V_82 ) ;
memcpy ( V_2 -> V_39 . V_42 . V_43 , V_47 , V_14 ) ;
V_2 -> V_15 . V_16 = V_14 ;
V_2 -> V_39 . V_40 &= ~ ( V_83 | V_84 ) ;
V_2 -> V_39 . V_40 |= V_41 ;
V_2 -> V_15 . V_85 = V_86 ;
F_41 ( V_51 , V_2 , V_87 | V_88 ) ;
} else {
int V_21 ;
V_56 = 0 ;
V_17 = V_9 ;
error = F_42 ( V_51 , V_2 , V_56 , V_57 ,
V_89 , & V_54 , V_63 ,
V_8 , & V_17 , & V_53 ) ;
if ( error )
goto V_90;
if ( V_63 )
V_63 -= V_57 ;
V_2 -> V_15 . V_16 = V_14 ;
F_41 ( V_51 , V_2 , V_88 ) ;
V_13 = V_47 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
char * V_91 ;
V_12 = F_4 ( V_5 , V_8 [ V_19 ] . V_23 ) ;
V_18 = F_5 ( V_5 , V_8 [ V_19 ] . V_24 ) ;
V_11 = F_43 ( V_51 , V_5 -> V_25 , V_12 ,
F_7 ( V_18 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_27 ;
goto V_90;
}
V_11 -> V_92 = & V_26 ;
V_18 = F_10 ( V_5 , V_18 ) ;
V_18 = F_44 ( V_18 , V_14 ) ;
V_91 = V_11 -> V_32 ;
V_91 += F_45 ( V_5 , V_2 -> V_34 , V_21 ,
V_18 , V_11 ) ;
memcpy ( V_91 , V_13 , V_18 ) ;
V_13 += V_18 ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_46 ( V_51 , V_11 , V_93 ) ;
F_47 ( V_51 , V_11 , 0 , ( V_91 + V_18 - 1 ) -
( char * ) V_11 -> V_32 ) ;
}
ASSERT ( V_14 == 0 ) ;
}
error = F_48 ( V_51 , V_44 , V_46 , V_2 -> V_34 ,
& V_54 , & V_53 , V_63 ) ;
if ( error )
goto V_90;
F_49 ( V_51 , V_44 , V_94 | V_95 ) ;
F_41 ( V_51 , V_44 , V_88 ) ;
if ( V_5 -> V_96 & ( V_97 | V_98 ) ) {
F_50 ( V_51 ) ;
}
error = F_51 ( & V_51 , & V_53 , NULL ) ;
if ( error )
goto V_90;
error = F_52 ( V_51 ) ;
if ( error )
goto V_99;
F_53 ( V_60 ) ;
F_53 ( V_61 ) ;
F_53 ( V_62 ) ;
* V_49 = V_2 ;
return 0 ;
V_90:
F_54 ( & V_53 ) ;
V_72:
F_55 ( V_51 ) ;
V_99:
if ( V_2 ) {
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
}
F_53 ( V_60 ) ;
F_53 ( V_61 ) ;
F_53 ( V_62 ) ;
if ( V_55 )
F_18 ( V_44 , V_73 | V_74 ) ;
return error ;
}
STATIC int
F_58 (
struct V_1 * V_2 )
{
T_7 * V_11 ;
int V_100 ;
int error ;
T_4 V_54 ;
T_10 V_53 ;
int V_101 ;
T_11 * V_5 ;
T_12 V_8 [ V_9 ] ;
int V_17 ;
int V_102 ;
T_13 * V_51 ;
V_5 = V_2 -> V_6 ;
ASSERT ( V_2 -> V_39 . V_40 & V_83 ) ;
ASSERT ( V_2 -> V_15 . V_103 > 0 && V_2 -> V_15 . V_103 <= 2 ) ;
V_51 = F_27 ( V_5 , V_104 ) ;
error = F_30 ( V_51 , & F_31 ( V_5 ) -> V_105 , 0 , 0 ) ;
if ( error ) {
F_55 ( V_51 ) ;
return error ;
}
F_17 ( V_2 , V_74 ) ;
F_36 ( V_51 , V_2 , 0 ) ;
V_102 = ( int ) V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = 0 ;
F_41 ( V_51 , V_2 , V_88 ) ;
V_100 = 0 ;
F_34 ( & V_53 , & V_54 ) ;
V_17 = F_59 ( V_8 ) ;
error = F_3 ( V_2 , 0 , F_2 ( V_5 , V_102 ) ,
V_8 , & V_17 , 0 ) ;
if ( error )
goto V_106;
for ( V_101 = 0 ; V_101 < V_17 ; V_101 ++ ) {
V_11 = F_43 ( V_51 , V_5 -> V_25 ,
F_4 ( V_5 , V_8 [ V_101 ] . V_23 ) ,
F_60 ( V_5 , V_8 [ V_101 ] . V_24 ) , 0 ) ;
if ( ! V_11 ) {
error = - V_27 ;
goto V_107;
}
F_61 ( V_51 , V_11 ) ;
}
error = F_62 ( V_51 , V_2 , 0 , V_102 , 0 , V_17 ,
& V_54 , & V_53 , & V_100 ) ;
if ( error )
goto V_107;
ASSERT ( V_100 ) ;
error = F_51 ( & V_51 , & V_53 , V_2 ) ;
if ( error )
goto V_107;
F_36 ( V_51 , V_2 , 0 ) ;
F_41 ( V_51 , V_2 , V_88 ) ;
error = F_52 ( V_51 ) ;
if ( error ) {
ASSERT ( F_16 ( V_5 ) ) ;
goto V_108;
}
if ( V_2 -> V_39 . V_109 )
F_40 ( V_2 , - V_2 -> V_39 . V_109 , V_82 ) ;
ASSERT ( V_2 -> V_39 . V_109 == 0 ) ;
F_18 ( V_2 , V_74 ) ;
return 0 ;
V_107:
F_54 ( & V_53 ) ;
V_106:
F_55 ( V_51 ) ;
V_108:
F_18 ( V_2 , V_74 ) ;
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
return - V_36 ;
F_17 ( V_2 , V_74 ) ;
V_14 = ( int ) V_2 -> V_15 . V_16 ;
if ( ! V_14 ) {
F_18 ( V_2 , V_74 ) ;
return 0 ;
}
if ( V_14 < 0 || V_14 > V_38 ) {
F_13 ( V_5 , L_3 ,
V_29 , ( unsigned long long ) V_2 -> V_34 , V_14 ) ;
F_18 ( V_2 , V_74 ) ;
ASSERT ( 0 ) ;
return - V_31 ;
}
if ( V_2 -> V_39 . V_40 & V_41 ) {
if ( V_2 -> V_39 . V_109 > 0 )
F_40 ( V_2 , - ( V_2 -> V_39 . V_109 ) ,
V_82 ) ;
F_18 ( V_2 , V_74 ) ;
ASSERT ( V_2 -> V_39 . V_109 == 0 ) ;
return 0 ;
}
F_18 ( V_2 , V_74 ) ;
return F_58 ( V_2 ) ;
}
