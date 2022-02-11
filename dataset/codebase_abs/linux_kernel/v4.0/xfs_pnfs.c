int
F_1 (
struct V_1 * V_1 ,
T_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int error ;
ASSERT ( F_3 ( V_4 , V_5 | V_6 ) ) ;
while ( ( error = F_4 ( V_1 , false ) == - V_7 ) ) {
F_5 ( V_4 , * V_2 ) ;
error = F_4 ( V_1 , true ) ;
* V_2 = V_6 ;
F_6 ( V_4 , * V_2 ) ;
}
return error ;
}
int
F_7 (
struct V_8 * V_9 ,
T_2 * V_10 ,
T_3 * V_11 ,
T_4 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
F_9 ( V_15
L_1 ,
V_14 -> V_16 ) ;
if ( * V_11 < sizeof( V_17 ) )
return - V_18 ;
memcpy ( V_10 , & V_14 -> V_19 . V_20 , sizeof( V_17 ) ) ;
* V_11 = sizeof( V_17 ) ;
* V_12 = F_10 ( struct V_21 , V_20 ) ;
return 0 ;
}
static void
F_11 (
struct V_3 * V_4 ,
struct V_22 * V_22 ,
struct V_23 * V_24 )
{
struct V_13 * V_14 = V_4 -> V_25 ;
if ( V_24 -> V_26 == V_27 ) {
V_22 -> V_28 = V_29 ;
V_22 -> type = V_30 ;
} else if ( V_24 -> V_26 == V_31 ) {
V_22 -> V_28 = V_29 ;
V_22 -> type = V_32 ;
} else {
V_22 -> V_28 =
F_12 ( V_4 -> V_25 , V_24 -> V_26 ) ;
if ( V_24 -> V_33 == V_34 )
V_22 -> type = V_35 ;
else
V_22 -> type = V_36 ;
}
V_22 -> V_12 = F_13 ( V_14 , V_24 -> V_37 ) ;
V_22 -> V_38 = F_13 ( V_14 , V_24 -> V_39 ) ;
}
int
F_14 (
struct V_1 * V_1 ,
T_5 V_12 ,
T_4 V_38 ,
struct V_22 * V_22 ,
bool V_40 ,
T_3 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_13 * V_14 = V_4 -> V_25 ;
struct V_23 V_24 ;
T_6 V_42 , V_43 ;
T_5 V_44 ;
int V_45 = V_46 ;
int V_47 = 1 ;
T_1 V_48 ;
int error = 0 ;
if ( F_15 ( V_14 ) )
return - V_49 ;
if ( F_16 ( V_4 ) )
return - V_50 ;
F_6 ( V_4 , V_6 ) ;
error = - V_18 ;
V_44 = V_14 -> V_51 -> V_52 ;
if ( ! V_40 )
V_44 = F_17 ( V_44 , F_18 ( F_19 ( V_1 ) ,
V_1 -> V_53 -> V_54 ) ) ;
if ( V_12 > V_44 )
goto V_55;
if ( V_12 > V_44 - V_38 )
V_38 = V_44 - V_12 ;
error = F_20 ( V_1 -> V_56 ) ;
if ( error )
goto V_55;
error = F_21 ( V_1 -> V_56 ) ;
if ( F_22 ( error ) )
return error ;
V_43 = F_23 ( V_14 , ( V_57 ) V_12 + V_38 ) ;
V_42 = F_24 ( V_14 , V_12 ) ;
V_48 = F_25 ( V_4 ) ;
error = F_26 ( V_4 , V_42 , V_43 - V_42 ,
& V_24 , & V_47 , V_45 ) ;
F_5 ( V_4 , V_48 ) ;
if ( error )
goto V_55;
if ( V_40 ) {
enum V_58 V_59 = 0 ;
ASSERT ( V_24 . V_26 != V_31 ) ;
if ( ! V_47 || V_24 . V_26 == V_27 ) {
error = F_27 ( V_4 , V_12 , V_38 ,
& V_24 , V_47 ) ;
if ( error )
goto V_55;
V_59 |= V_60 | V_61 ;
}
error = F_28 ( V_4 , V_59 ) ;
if ( error )
goto V_55;
}
F_5 ( V_4 , V_6 ) ;
F_11 ( V_4 , V_22 , & V_24 ) ;
* V_41 = V_14 -> V_62 ;
return error ;
V_55:
F_5 ( V_4 , V_6 ) ;
return error ;
}
static int
F_29 (
struct V_3 * V_4 ,
T_7 V_63 )
{
struct V_23 V_24 ;
int V_47 = 1 ;
int error = 0 ;
F_6 ( V_4 , V_64 ) ;
error = F_26 ( V_4 , F_24 ( V_4 -> V_25 , V_63 - 1 ) , 1 ,
& V_24 , & V_47 , 0 ) ;
F_5 ( V_4 , V_64 ) ;
if ( error )
return error ;
if ( V_24 . V_26 == V_27 ||
V_24 . V_26 == V_31 ||
V_24 . V_33 == V_34 )
return - V_49 ;
return 0 ;
}
int
F_30 (
struct V_1 * V_1 ,
struct V_22 * V_65 ,
int V_66 ,
struct V_67 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_13 * V_14 = V_4 -> V_25 ;
struct V_68 * V_69 ;
bool V_70 = false ;
int error , V_71 ;
T_5 V_72 ;
ASSERT ( V_67 -> V_73 & ( V_74 | V_75 | V_76 ) ) ;
F_6 ( V_4 , V_6 ) ;
V_72 = F_19 ( V_1 ) ;
if ( ( V_67 -> V_73 & V_77 ) && V_67 -> V_78 > V_72 ) {
V_70 = true ;
V_72 = V_67 -> V_78 ;
}
for ( V_71 = 0 ; V_71 < V_66 ; V_71 ++ ) {
T_4 V_79 , V_38 , V_80 ;
V_79 = V_65 [ V_71 ] . V_12 ;
if ( V_79 > V_72 )
continue;
V_80 = V_79 + V_65 [ V_71 ] . V_38 ;
if ( V_80 > V_72 )
V_80 = V_72 ;
V_38 = V_80 - V_79 ;
if ( ! V_38 )
continue;
error = F_31 ( V_1 -> V_56 ,
V_79 >> V_81 ,
( V_80 - 1 ) >> V_81 ) ;
F_22 ( error ) ;
error = F_32 ( V_4 , V_79 , V_38 ) ;
if ( error )
goto V_82;
}
if ( V_70 ) {
error = F_29 ( V_4 , V_72 ) ;
if ( error )
goto V_82;
}
V_69 = F_33 ( V_14 , V_83 ) ;
error = F_34 ( V_69 , & F_35 ( V_14 ) -> V_84 , 0 , 0 ) ;
if ( error ) {
F_36 ( V_69 , 0 ) ;
goto V_82;
}
F_6 ( V_4 , V_85 ) ;
F_37 ( V_69 , V_4 , V_85 ) ;
F_38 ( V_69 , V_4 , V_86 ) ;
F_39 ( V_4 , V_67 ) ;
if ( V_70 ) {
F_40 ( V_1 , V_67 -> V_78 ) ;
V_4 -> V_87 . V_88 = V_67 -> V_78 ;
}
F_41 ( V_69 ) ;
error = F_42 ( V_69 , 0 ) ;
V_82:
F_5 ( V_4 , V_6 ) ;
return error ;
}
