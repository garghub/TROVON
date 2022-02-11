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
goto V_22;
}
V_18 = F_11 ( V_5 , V_18 ) ;
if ( V_14 < V_18 )
V_18 = V_14 ;
V_13 = V_11 -> V_30 ;
if ( F_12 ( & V_5 -> V_31 ) ) {
if ( ! F_13 ( V_5 , V_2 -> V_32 , V_21 ,
V_18 , V_11 ) ) {
error = V_33 ;
F_14 ( V_5 ,
L_1 ,
V_21 , V_18 , V_2 -> V_32 ) ;
F_10 ( V_11 ) ;
goto V_22;
}
V_13 += sizeof( struct V_34 ) ;
}
memcpy ( V_3 + V_21 , V_11 -> V_30 , V_18 ) ;
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
return F_8 ( V_35 ) ;
F_18 ( V_2 , V_36 ) ;
V_14 = V_2 -> V_15 . V_16 ;
if ( ! V_14 )
goto V_22;
if ( V_14 < 0 || V_14 > V_37 ) {
F_14 ( V_5 , L_2 ,
V_29 , ( unsigned long long ) V_2 -> V_32 ,
( long long ) V_14 ) ;
ASSERT ( 0 ) ;
error = F_8 ( V_33 ) ;
goto V_22;
}
if ( V_2 -> V_38 . V_39 & V_40 ) {
memcpy ( V_3 , V_2 -> V_38 . V_41 . V_42 , V_14 ) ;
V_3 [ V_14 ] = '\0' ;
} else {
error = F_1 ( V_2 , V_3 ) ;
}
V_22:
F_19 ( V_2 , V_36 ) ;
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
int V_56 ;
T_6 V_57 ;
T_7 V_58 ;
int V_17 ;
struct V_7 V_8 [ V_9 ] ;
T_1 V_12 ;
const char * V_13 ;
int V_18 ;
int V_19 ;
T_8 * V_11 ;
T_9 V_59 ;
struct V_60 * V_61 = NULL ;
struct V_60 * V_62 = NULL ;
struct V_60 * V_63 = NULL ;
T_5 V_64 ;
* V_48 = NULL ;
F_21 ( V_43 , V_45 ) ;
if ( F_17 ( V_5 ) )
return F_8 ( V_35 ) ;
V_14 = strlen ( V_46 ) ;
if ( V_14 >= V_37 )
return F_8 ( V_65 ) ;
V_61 = V_62 = NULL ;
if ( V_43 -> V_15 . V_66 & V_67 )
V_59 = F_22 ( V_43 ) ;
else
V_59 = V_68 ;
error = F_23 ( V_43 ,
F_24 ( F_25 () ) ,
F_26 ( F_27 () ) , V_59 ,
V_69 | V_70 ,
& V_61 , & V_62 , & V_63 ) ;
if ( error )
goto V_71;
V_50 = F_28 ( V_5 , V_72 ) ;
V_55 = V_73 ;
if ( V_14 <= F_29 ( V_5 , V_43 -> V_15 . V_74 ) )
V_58 = 0 ;
else
V_58 = F_2 ( V_5 , V_14 ) ;
V_64 = F_30 ( V_5 , V_45 -> V_75 , V_58 ) ;
error = F_31 ( V_50 , & F_32 ( V_5 ) -> V_76 , V_64 , 0 ) ;
if ( error == V_77 && V_58 == 0 ) {
V_64 = 0 ;
error = F_31 ( V_50 , & F_32 ( V_5 ) -> V_76 , 0 , 0 ) ;
}
if ( error ) {
V_55 = 0 ;
goto V_78;
}
F_18 ( V_43 , V_79 | V_80 ) ;
V_54 = true ;
if ( V_43 -> V_15 . V_66 & V_81 ) {
error = F_8 ( V_82 ) ;
goto V_78;
}
error = F_33 ( V_50 , V_5 , V_61 , V_62 ,
V_63 , V_64 , 1 , 0 ) ;
if ( error )
goto V_78;
error = F_34 ( V_50 , V_43 , V_45 , V_64 ) ;
if ( error )
goto V_78;
F_35 ( & V_52 , & V_53 ) ;
error = F_36 ( & V_50 , V_43 , V_83 | ( V_47 & ~ V_84 ) , 1 , 0 ,
V_59 , V_64 > 0 , & V_2 , NULL ) ;
if ( error ) {
if ( error == V_77 )
goto V_78;
goto V_85;
}
F_37 ( V_50 , V_43 , V_79 ) ;
V_54 = false ;
F_38 ( V_50 , V_2 , V_61 , V_62 , V_63 ) ;
if ( V_64 )
V_64 -= F_39 ( V_5 ) ;
if ( V_14 <= F_40 ( V_2 ) ) {
F_41 ( V_2 , V_14 , V_86 ) ;
memcpy ( V_2 -> V_38 . V_41 . V_42 , V_46 , V_14 ) ;
V_2 -> V_15 . V_16 = V_14 ;
V_2 -> V_38 . V_39 &= ~ ( V_87 | V_88 ) ;
V_2 -> V_38 . V_39 |= V_40 ;
V_2 -> V_15 . V_89 = V_90 ;
F_42 ( V_50 , V_2 , V_91 | V_92 ) ;
} else {
int V_21 ;
V_57 = 0 ;
V_17 = V_9 ;
error = F_43 ( V_50 , V_2 , V_57 , V_58 ,
V_93 , & V_53 , V_64 ,
V_8 , & V_17 , & V_52 ) ;
if ( error )
goto V_94;
if ( V_64 )
V_64 -= V_58 ;
V_2 -> V_15 . V_16 = V_14 ;
F_42 ( V_50 , V_2 , V_92 ) ;
V_13 = V_46 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
char * V_95 ;
V_12 = F_4 ( V_5 , V_8 [ V_19 ] . V_23 ) ;
V_18 = F_5 ( V_5 , V_8 [ V_19 ] . V_24 ) ;
V_11 = F_44 ( V_50 , V_5 -> V_25 , V_12 ,
F_7 ( V_18 ) , 0 ) ;
if ( ! V_11 ) {
error = V_27 ;
goto V_94;
}
V_11 -> V_96 = & V_26 ;
V_18 = F_11 ( V_5 , V_18 ) ;
V_18 = F_45 ( V_18 , V_14 ) ;
V_95 = V_11 -> V_30 ;
V_95 += F_46 ( V_5 , V_2 -> V_32 , V_21 ,
V_18 , V_11 ) ;
memcpy ( V_95 , V_13 , V_18 ) ;
V_13 += V_18 ;
V_14 -= V_18 ;
V_21 += V_18 ;
F_47 ( V_50 , V_11 , V_97 ) ;
F_48 ( V_50 , V_11 , 0 , ( V_95 + V_18 - 1 ) -
( char * ) V_11 -> V_30 ) ;
}
ASSERT ( V_14 == 0 ) ;
}
error = F_49 ( V_50 , V_43 , V_45 , V_2 -> V_32 ,
& V_53 , & V_52 , V_64 ) ;
if ( error )
goto V_94;
F_50 ( V_50 , V_43 , V_98 | V_99 ) ;
F_42 ( V_50 , V_43 , V_92 ) ;
if ( V_5 -> V_100 & ( V_101 | V_102 ) ) {
F_51 ( V_50 ) ;
}
error = F_52 ( & V_50 , & V_52 , & V_56 ) ;
if ( error ) {
goto V_94;
}
error = F_53 ( V_50 , V_73 ) ;
F_54 ( V_61 ) ;
F_54 ( V_62 ) ;
F_54 ( V_63 ) ;
* V_48 = V_2 ;
return 0 ;
V_94:
F_55 ( V_2 ) ;
V_85:
F_56 ( & V_52 ) ;
V_55 |= V_103 ;
V_78:
F_57 ( V_50 , V_55 ) ;
F_54 ( V_61 ) ;
F_54 ( V_62 ) ;
F_54 ( V_63 ) ;
if ( V_54 )
F_19 ( V_43 , V_79 ) ;
V_71:
return error ;
}
STATIC int
F_58 (
struct V_1 * V_2 )
{
T_8 * V_11 ;
int V_56 ;
int V_104 ;
int error ;
T_4 V_53 ;
T_10 V_52 ;
int V_105 ;
T_11 * V_5 ;
T_12 V_8 [ V_9 ] ;
int V_17 ;
int V_106 ;
T_13 * V_50 ;
V_5 = V_2 -> V_6 ;
ASSERT ( V_2 -> V_38 . V_39 & V_87 ) ;
ASSERT ( V_2 -> V_15 . V_107 > 0 && V_2 -> V_15 . V_107 <= 2 ) ;
V_50 = F_28 ( V_5 , V_108 ) ;
error = F_31 ( V_50 , & F_32 ( V_5 ) -> V_109 , 0 , 0 ) ;
if ( error ) {
F_57 ( V_50 , 0 ) ;
return error ;
}
F_18 ( V_2 , V_79 ) ;
F_37 ( V_50 , V_2 , 0 ) ;
V_106 = ( int ) V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = 0 ;
F_42 ( V_50 , V_2 , V_92 ) ;
V_104 = 0 ;
F_35 ( & V_52 , & V_53 ) ;
V_17 = F_59 ( V_8 ) ;
error = F_3 ( V_2 , 0 , F_2 ( V_5 , V_106 ) ,
V_8 , & V_17 , 0 ) ;
if ( error )
goto V_110;
for ( V_105 = 0 ; V_105 < V_17 ; V_105 ++ ) {
V_11 = F_44 ( V_50 , V_5 -> V_25 ,
F_4 ( V_5 , V_8 [ V_105 ] . V_23 ) ,
F_60 ( V_5 , V_8 [ V_105 ] . V_24 ) , 0 ) ;
if ( ! V_11 ) {
error = V_27 ;
goto V_111;
}
F_61 ( V_50 , V_11 ) ;
}
error = F_62 ( V_50 , V_2 , 0 , V_106 , V_93 , V_17 ,
& V_53 , & V_52 , & V_104 ) ;
if ( error )
goto V_111;
ASSERT ( V_104 ) ;
error = F_52 ( & V_50 , & V_52 , & V_56 ) ;
if ( error )
goto V_111;
ASSERT ( V_56 ) ;
F_37 ( V_50 , V_2 , 0 ) ;
F_42 ( V_50 , V_2 , V_92 ) ;
error = F_53 ( V_50 , V_73 ) ;
if ( error ) {
ASSERT ( F_17 ( V_5 ) ) ;
goto V_112;
}
if ( V_2 -> V_38 . V_113 )
F_41 ( V_2 , - V_2 -> V_38 . V_113 , V_86 ) ;
ASSERT ( V_2 -> V_38 . V_113 == 0 ) ;
F_19 ( V_2 , V_79 ) ;
return 0 ;
V_111:
F_56 ( & V_52 ) ;
V_110:
F_57 ( V_50 , V_73 | V_103 ) ;
V_112:
F_19 ( V_2 , V_79 ) ;
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
return F_8 ( V_35 ) ;
F_18 ( V_2 , V_79 ) ;
V_14 = ( int ) V_2 -> V_15 . V_16 ;
if ( ! V_14 ) {
F_19 ( V_2 , V_79 ) ;
return 0 ;
}
if ( V_14 < 0 || V_14 > V_37 ) {
F_14 ( V_5 , L_3 ,
V_29 , ( unsigned long long ) V_2 -> V_32 , V_14 ) ;
F_19 ( V_2 , V_79 ) ;
ASSERT ( 0 ) ;
return F_8 ( V_33 ) ;
}
if ( V_2 -> V_38 . V_39 & V_40 ) {
if ( V_2 -> V_38 . V_113 > 0 )
F_41 ( V_2 , - ( V_2 -> V_38 . V_113 ) ,
V_86 ) ;
F_19 ( V_2 , V_79 ) ;
ASSERT ( V_2 -> V_38 . V_113 == 0 ) ;
return 0 ;
}
F_19 ( V_2 , V_79 ) ;
return F_58 ( V_2 ) ;
}
