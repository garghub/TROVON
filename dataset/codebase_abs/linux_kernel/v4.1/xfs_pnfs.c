int
F_1 (
struct V_1 * V_1 ,
T_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
int error ;
ASSERT ( F_3 ( V_5 , V_6 | V_7 ) ) ;
while ( ( error = F_4 ( V_1 , false ) == - V_8 ) ) {
F_5 ( V_5 , * V_2 ) ;
if ( V_3 && ( * V_2 & V_7 ) )
F_6 ( & V_1 -> V_9 ) ;
error = F_4 ( V_1 , true ) ;
* V_2 = V_7 ;
if ( V_3 )
F_7 ( & V_1 -> V_9 ) ;
F_8 ( V_5 , * V_2 ) ;
}
return error ;
}
int
F_9 (
struct V_10 * V_11 ,
T_2 * V_12 ,
T_3 * V_13 ,
T_4 * V_14 )
{
struct V_15 * V_16 = F_10 ( V_11 ) ;
F_11 ( V_17
L_1 ,
V_16 -> V_18 ) ;
if ( * V_13 < sizeof( V_19 ) )
return - V_20 ;
memcpy ( V_12 , & V_16 -> V_21 . V_22 , sizeof( V_19 ) ) ;
* V_13 = sizeof( V_19 ) ;
* V_14 = F_12 ( struct V_23 , V_22 ) ;
return 0 ;
}
static void
F_13 (
struct V_4 * V_5 ,
struct V_24 * V_24 ,
struct V_25 * V_26 )
{
struct V_15 * V_16 = V_5 -> V_27 ;
if ( V_26 -> V_28 == V_29 ) {
V_24 -> V_30 = V_31 ;
V_24 -> type = V_32 ;
} else if ( V_26 -> V_28 == V_33 ) {
V_24 -> V_30 = V_31 ;
V_24 -> type = V_34 ;
} else {
V_24 -> V_30 =
F_14 ( V_5 -> V_27 , V_26 -> V_28 ) ;
if ( V_26 -> V_35 == V_36 )
V_24 -> type = V_37 ;
else
V_24 -> type = V_38 ;
}
V_24 -> V_14 = F_15 ( V_16 , V_26 -> V_39 ) ;
V_24 -> V_40 = F_15 ( V_16 , V_26 -> V_41 ) ;
}
int
F_16 (
struct V_1 * V_1 ,
T_5 V_14 ,
T_4 V_40 ,
struct V_24 * V_24 ,
bool V_42 ,
T_3 * V_43 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_15 * V_16 = V_5 -> V_27 ;
struct V_25 V_26 ;
T_6 V_44 , V_45 ;
T_5 V_46 ;
int V_47 = V_48 ;
int V_49 = 1 ;
T_1 V_50 ;
int error = 0 ;
if ( F_17 ( V_16 ) )
return - V_51 ;
if ( F_18 ( V_5 ) )
return - V_52 ;
F_8 ( V_5 , V_7 ) ;
error = - V_20 ;
V_46 = V_16 -> V_53 -> V_54 ;
if ( ! V_42 )
V_46 = F_19 ( V_46 , F_20 ( F_21 ( V_1 ) ,
V_1 -> V_55 -> V_56 ) ) ;
if ( V_14 > V_46 )
goto V_57;
if ( V_14 > V_46 - V_40 )
V_40 = V_46 - V_14 ;
error = F_22 ( V_1 -> V_58 ) ;
if ( error )
goto V_57;
error = F_23 ( V_1 -> V_58 ) ;
if ( F_24 ( error ) )
return error ;
V_45 = F_25 ( V_16 , ( V_59 ) V_14 + V_40 ) ;
V_44 = F_26 ( V_16 , V_14 ) ;
V_50 = F_27 ( V_5 ) ;
error = F_28 ( V_5 , V_44 , V_45 - V_44 ,
& V_26 , & V_49 , V_47 ) ;
F_5 ( V_5 , V_50 ) ;
if ( error )
goto V_57;
if ( V_42 ) {
enum V_60 V_61 = 0 ;
ASSERT ( V_26 . V_28 != V_33 ) ;
if ( ! V_49 || V_26 . V_28 == V_29 ) {
error = F_29 ( V_5 , V_14 , V_40 ,
& V_26 , V_49 ) ;
if ( error )
goto V_57;
V_61 |= V_62 | V_63 ;
}
error = F_30 ( V_5 , V_61 ) ;
if ( error )
goto V_57;
}
F_5 ( V_5 , V_7 ) ;
F_13 ( V_5 , V_24 , & V_26 ) ;
* V_43 = V_16 -> V_64 ;
return error ;
V_57:
F_5 ( V_5 , V_7 ) ;
return error ;
}
static int
F_31 (
struct V_4 * V_5 ,
T_7 V_65 )
{
struct V_25 V_26 ;
int V_49 = 1 ;
int error = 0 ;
F_8 ( V_5 , V_66 ) ;
error = F_28 ( V_5 , F_26 ( V_5 -> V_27 , V_65 - 1 ) , 1 ,
& V_26 , & V_49 , 0 ) ;
F_5 ( V_5 , V_66 ) ;
if ( error )
return error ;
if ( V_26 . V_28 == V_29 ||
V_26 . V_28 == V_33 ||
V_26 . V_35 == V_36 )
return - V_51 ;
return 0 ;
}
int
F_32 (
struct V_1 * V_1 ,
struct V_24 * V_67 ,
int V_68 ,
struct V_69 * V_69 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_15 * V_16 = V_5 -> V_27 ;
struct V_70 * V_71 ;
bool V_72 = false ;
int error , V_73 ;
T_5 V_74 ;
ASSERT ( V_69 -> V_75 & ( V_76 | V_77 | V_78 ) ) ;
F_8 ( V_5 , V_7 ) ;
V_74 = F_21 ( V_1 ) ;
if ( ( V_69 -> V_75 & V_79 ) && V_69 -> V_80 > V_74 ) {
V_72 = true ;
V_74 = V_69 -> V_80 ;
}
for ( V_73 = 0 ; V_73 < V_68 ; V_73 ++ ) {
T_4 V_81 , V_40 , V_82 ;
V_81 = V_67 [ V_73 ] . V_14 ;
if ( V_81 > V_74 )
continue;
V_82 = V_81 + V_67 [ V_73 ] . V_40 ;
if ( V_82 > V_74 )
V_82 = V_74 ;
V_40 = V_82 - V_81 ;
if ( ! V_40 )
continue;
error = F_33 ( V_1 -> V_58 ,
V_81 >> V_83 ,
( V_82 - 1 ) >> V_83 ) ;
F_24 ( error ) ;
error = F_34 ( V_5 , V_81 , V_40 ) ;
if ( error )
goto V_84;
}
if ( V_72 ) {
error = F_31 ( V_5 , V_74 ) ;
if ( error )
goto V_84;
}
V_71 = F_35 ( V_16 , V_85 ) ;
error = F_36 ( V_71 , & F_37 ( V_16 ) -> V_86 , 0 , 0 ) ;
if ( error ) {
F_38 ( V_71 , 0 ) ;
goto V_84;
}
F_8 ( V_5 , V_87 ) ;
F_39 ( V_71 , V_5 , V_87 ) ;
F_40 ( V_71 , V_5 , V_88 ) ;
F_41 ( V_5 , V_69 ) ;
if ( V_72 ) {
F_42 ( V_1 , V_69 -> V_80 ) ;
V_5 -> V_89 . V_90 = V_69 -> V_80 ;
}
F_43 ( V_71 ) ;
error = F_44 ( V_71 , 0 ) ;
V_84:
F_5 ( V_5 , V_7 ) ;
return error ;
}
