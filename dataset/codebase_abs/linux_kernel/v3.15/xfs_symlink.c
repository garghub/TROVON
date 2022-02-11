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
return F_8 ( V_27 ) ;
error = V_11 -> V_28 ;
if ( error ) {
F_9 ( V_11 , V_29 ) ;
F_10 ( V_11 ) ;
if ( error == V_30 )
error = V_31 ;
goto V_22;
}
V_18 = F_11 ( V_5 , V_18 ) ;
if ( V_14 < V_18 )
V_18 = V_14 ;
V_13 = V_11 -> V_32 ;
if ( F_12 ( & V_5 -> V_33 ) ) {
if ( ! F_13 ( V_5 , V_2 -> V_34 , V_21 ,
V_18 , V_11 ) ) {
error = V_31 ;
F_14 ( V_5 ,
L_1 ,
V_21 , V_18 , V_2 -> V_34 ) ;
F_10 ( V_11 ) ;
goto V_22;
}
V_13 += sizeof( struct V_35 ) ;
}
memcpy ( V_3 + V_21 , V_11 -> V_32 , V_18 ) ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_10 ( V_11 ) ;
}
ASSERT ( V_14 == 0 ) ;
V_3 [ V_2 -> V_15 . V_16 ] = '\0' ;
error = 0 ;
V_22:
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
if ( F_17 ( V_5 ) )
return F_8 ( V_36 ) ;
F_18 ( V_2 , V_37 ) ;
V_14 = V_2 -> V_15 . V_16 ;
if ( ! V_14 )
goto V_22;
if ( V_14 < 0 || V_14 > V_38 ) {
F_14 ( V_5 , L_2 ,
V_29 , ( unsigned long long ) V_2 -> V_34 ,
( long long ) V_14 ) ;
ASSERT ( 0 ) ;
error = F_8 ( V_31 ) ;
goto V_22;
}
if ( V_2 -> V_39 . V_40 & V_41 ) {
memcpy ( V_3 , V_2 -> V_39 . V_42 . V_43 , V_14 ) ;
V_3 [ V_14 ] = '\0' ;
} else {
error = F_1 ( V_2 , V_3 ) ;
}
V_22:
F_19 ( V_2 , V_37 ) ;
return error ;
}
int
F_20 (
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
int V_57 ;
T_6 V_58 ;
T_7 V_59 ;
int V_17 ;
struct V_7 V_8 [ V_9 ] ;
T_1 V_12 ;
const char * V_13 ;
int V_18 ;
int V_19 ;
T_8 * V_11 ;
T_9 V_60 ;
struct V_61 * V_62 = NULL ;
struct V_61 * V_63 = NULL ;
struct V_61 * V_64 = NULL ;
T_5 V_65 ;
* V_49 = NULL ;
F_21 ( V_44 , V_46 ) ;
if ( F_17 ( V_5 ) )
return F_8 ( V_36 ) ;
V_14 = strlen ( V_47 ) ;
if ( V_14 >= V_38 )
return F_8 ( V_66 ) ;
V_62 = V_63 = NULL ;
V_60 = F_22 ( V_44 ) ;
error = F_23 ( V_44 ,
F_24 ( F_25 () ) ,
F_26 ( F_27 () ) , V_60 ,
V_67 | V_68 ,
& V_62 , & V_63 , & V_64 ) ;
if ( error )
goto V_69;
V_51 = F_28 ( V_5 , V_70 ) ;
V_56 = V_71 ;
if ( V_14 <= F_29 ( V_5 , V_44 -> V_15 . V_72 ) )
V_59 = 0 ;
else
V_59 = F_2 ( V_5 , V_14 ) ;
V_65 = F_30 ( V_5 , V_46 -> V_73 , V_59 ) ;
error = F_31 ( V_51 , & F_32 ( V_5 ) -> V_74 , V_65 , 0 ) ;
if ( error == V_75 && V_59 == 0 ) {
V_65 = 0 ;
error = F_31 ( V_51 , & F_32 ( V_5 ) -> V_74 , 0 , 0 ) ;
}
if ( error ) {
V_56 = 0 ;
goto V_76;
}
F_18 ( V_44 , V_77 | V_78 ) ;
V_55 = true ;
if ( V_44 -> V_15 . V_79 & V_80 ) {
error = F_8 ( V_81 ) ;
goto V_76;
}
error = F_33 ( V_51 , V_5 , V_62 , V_63 ,
V_64 , V_65 , 1 , 0 ) ;
if ( error )
goto V_76;
error = F_34 ( V_51 , V_44 , V_46 , V_65 ) ;
if ( error )
goto V_76;
F_35 ( & V_53 , & V_54 ) ;
error = F_36 ( & V_51 , V_44 , V_82 | ( V_48 & ~ V_83 ) , 1 , 0 ,
V_60 , V_65 > 0 , & V_2 , NULL ) ;
if ( error ) {
if ( error == V_75 )
goto V_76;
goto V_84;
}
F_37 ( V_51 , V_44 , V_77 ) ;
V_55 = false ;
F_38 ( V_51 , V_2 , V_62 , V_63 , V_64 ) ;
if ( V_65 )
V_65 -= F_39 ( V_5 ) ;
if ( V_14 <= F_40 ( V_2 ) ) {
F_41 ( V_2 , V_14 , V_85 ) ;
memcpy ( V_2 -> V_39 . V_42 . V_43 , V_47 , V_14 ) ;
V_2 -> V_15 . V_16 = V_14 ;
V_2 -> V_39 . V_40 &= ~ ( V_86 | V_87 ) ;
V_2 -> V_39 . V_40 |= V_41 ;
V_2 -> V_15 . V_88 = V_89 ;
F_42 ( V_51 , V_2 , V_90 | V_91 ) ;
} else {
int V_21 ;
V_58 = 0 ;
V_17 = V_9 ;
error = F_43 ( V_51 , V_2 , V_58 , V_59 ,
V_92 , & V_54 , V_65 ,
V_8 , & V_17 , & V_53 ) ;
if ( error )
goto V_93;
if ( V_65 )
V_65 -= V_59 ;
V_2 -> V_15 . V_16 = V_14 ;
F_42 ( V_51 , V_2 , V_91 ) ;
V_13 = V_47 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
char * V_94 ;
V_12 = F_4 ( V_5 , V_8 [ V_19 ] . V_23 ) ;
V_18 = F_5 ( V_5 , V_8 [ V_19 ] . V_24 ) ;
V_11 = F_44 ( V_51 , V_5 -> V_25 , V_12 ,
F_7 ( V_18 ) , 0 ) ;
if ( ! V_11 ) {
error = V_27 ;
goto V_93;
}
V_11 -> V_95 = & V_26 ;
V_18 = F_11 ( V_5 , V_18 ) ;
V_18 = F_45 ( V_18 , V_14 ) ;
V_94 = V_11 -> V_32 ;
V_94 += F_46 ( V_5 , V_2 -> V_34 , V_21 ,
V_18 , V_11 ) ;
memcpy ( V_94 , V_13 , V_18 ) ;
V_13 += V_18 ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_47 ( V_51 , V_11 , V_96 ) ;
F_48 ( V_51 , V_11 , 0 , ( V_94 + V_18 - 1 ) -
( char * ) V_11 -> V_32 ) ;
}
ASSERT ( V_14 == 0 ) ;
}
error = F_49 ( V_51 , V_44 , V_46 , V_2 -> V_34 ,
& V_54 , & V_53 , V_65 ) ;
if ( error )
goto V_93;
F_50 ( V_51 , V_44 , V_97 | V_98 ) ;
F_42 ( V_51 , V_44 , V_91 ) ;
if ( V_5 -> V_99 & ( V_100 | V_101 ) ) {
F_51 ( V_51 ) ;
}
error = F_52 ( & V_51 , & V_53 , & V_57 ) ;
if ( error ) {
goto V_93;
}
error = F_53 ( V_51 , V_71 ) ;
F_54 ( V_62 ) ;
F_54 ( V_63 ) ;
F_54 ( V_64 ) ;
* V_49 = V_2 ;
return 0 ;
V_93:
F_55 ( V_2 ) ;
V_84:
F_56 ( & V_53 ) ;
V_56 |= V_102 ;
V_76:
F_57 ( V_51 , V_56 ) ;
F_54 ( V_62 ) ;
F_54 ( V_63 ) ;
F_54 ( V_64 ) ;
if ( V_55 )
F_19 ( V_44 , V_77 ) ;
V_69:
return error ;
}
STATIC int
F_58 (
struct V_1 * V_2 )
{
T_8 * V_11 ;
int V_57 ;
int V_103 ;
int error ;
T_4 V_54 ;
T_10 V_53 ;
int V_104 ;
T_11 * V_5 ;
T_12 V_8 [ V_9 ] ;
int V_17 ;
int V_105 ;
T_13 * V_51 ;
V_5 = V_2 -> V_6 ;
ASSERT ( V_2 -> V_39 . V_40 & V_86 ) ;
ASSERT ( V_2 -> V_15 . V_106 > 0 && V_2 -> V_15 . V_106 <= 2 ) ;
V_51 = F_28 ( V_5 , V_107 ) ;
error = F_31 ( V_51 , & F_32 ( V_5 ) -> V_108 , 0 , 0 ) ;
if ( error ) {
F_57 ( V_51 , 0 ) ;
return error ;
}
F_18 ( V_2 , V_77 ) ;
F_37 ( V_51 , V_2 , 0 ) ;
V_105 = ( int ) V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = 0 ;
F_42 ( V_51 , V_2 , V_91 ) ;
V_103 = 0 ;
F_35 ( & V_53 , & V_54 ) ;
V_17 = F_59 ( V_8 ) ;
error = F_3 ( V_2 , 0 , F_2 ( V_5 , V_105 ) ,
V_8 , & V_17 , 0 ) ;
if ( error )
goto V_109;
for ( V_104 = 0 ; V_104 < V_17 ; V_104 ++ ) {
V_11 = F_44 ( V_51 , V_5 -> V_25 ,
F_4 ( V_5 , V_8 [ V_104 ] . V_23 ) ,
F_60 ( V_5 , V_8 [ V_104 ] . V_24 ) , 0 ) ;
if ( ! V_11 ) {
error = V_27 ;
goto V_110;
}
F_61 ( V_51 , V_11 ) ;
}
error = F_62 ( V_51 , V_2 , 0 , V_105 , V_92 , V_17 ,
& V_54 , & V_53 , & V_103 ) ;
if ( error )
goto V_110;
ASSERT ( V_103 ) ;
error = F_52 ( & V_51 , & V_53 , & V_57 ) ;
if ( error )
goto V_110;
ASSERT ( V_57 ) ;
F_37 ( V_51 , V_2 , 0 ) ;
F_42 ( V_51 , V_2 , V_91 ) ;
error = F_53 ( V_51 , V_71 ) ;
if ( error ) {
ASSERT ( F_17 ( V_5 ) ) ;
goto V_111;
}
if ( V_2 -> V_39 . V_112 )
F_41 ( V_2 , - V_2 -> V_39 . V_112 , V_85 ) ;
ASSERT ( V_2 -> V_39 . V_112 == 0 ) ;
F_19 ( V_2 , V_77 ) ;
return 0 ;
V_110:
F_56 ( & V_53 ) ;
V_109:
F_57 ( V_51 , V_71 | V_102 ) ;
V_111:
F_19 ( V_2 , V_77 ) ;
return error ;
}
int
F_63 (
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_14 ;
F_64 ( V_2 ) ;
if ( F_17 ( V_5 ) )
return F_8 ( V_36 ) ;
F_18 ( V_2 , V_77 ) ;
V_14 = ( int ) V_2 -> V_15 . V_16 ;
if ( ! V_14 ) {
F_19 ( V_2 , V_77 ) ;
return 0 ;
}
if ( V_14 < 0 || V_14 > V_38 ) {
F_14 ( V_5 , L_3 ,
V_29 , ( unsigned long long ) V_2 -> V_34 , V_14 ) ;
F_19 ( V_2 , V_77 ) ;
ASSERT ( 0 ) ;
return F_8 ( V_31 ) ;
}
if ( V_2 -> V_39 . V_40 & V_41 ) {
if ( V_2 -> V_39 . V_112 > 0 )
F_41 ( V_2 , - ( V_2 -> V_39 . V_112 ) ,
V_85 ) ;
F_19 ( V_2 , V_77 ) ;
ASSERT ( V_2 -> V_39 . V_112 == 0 ) ;
return 0 ;
}
F_19 ( V_2 , V_77 ) ;
return F_58 ( V_2 ) ;
}
