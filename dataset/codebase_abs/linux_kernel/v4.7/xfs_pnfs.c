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
F_6 ( V_1 ) ;
error = F_4 ( V_1 , true ) ;
* V_2 = V_7 ;
if ( V_3 )
F_7 ( V_1 ) ;
F_8 ( V_5 , * V_2 ) ;
}
return error ;
}
int
F_9 (
struct V_9 * V_10 ,
T_2 * V_11 ,
T_3 * V_12 ,
T_4 * V_13 )
{
struct V_14 * V_15 = F_10 ( V_10 ) ;
F_11 ( V_16
L_1 ,
V_15 -> V_17 ) ;
if ( * V_12 < sizeof( V_18 ) )
return - V_19 ;
memcpy ( V_11 , & V_15 -> V_20 . V_21 , sizeof( V_18 ) ) ;
* V_12 = sizeof( V_18 ) ;
* V_13 = F_12 ( struct V_22 , V_21 ) ;
return 0 ;
}
static void
F_13 (
struct V_4 * V_5 ,
struct V_23 * V_23 ,
struct V_24 * V_25 )
{
struct V_14 * V_15 = V_5 -> V_26 ;
if ( V_25 -> V_27 == V_28 ) {
V_23 -> V_29 = V_30 ;
V_23 -> type = V_31 ;
} else if ( V_25 -> V_27 == V_32 ) {
V_23 -> V_29 = V_30 ;
V_23 -> type = V_33 ;
} else {
V_23 -> V_29 =
F_14 ( V_5 -> V_26 , V_25 -> V_27 ) ;
if ( V_25 -> V_34 == V_35 )
V_23 -> type = V_36 ;
else
V_23 -> type = V_37 ;
}
V_23 -> V_13 = F_15 ( V_15 , V_25 -> V_38 ) ;
V_23 -> V_39 = F_15 ( V_15 , V_25 -> V_40 ) ;
}
int
F_16 (
struct V_1 * V_1 ,
T_5 V_13 ,
T_4 V_39 ,
struct V_23 * V_23 ,
bool V_41 ,
T_3 * V_42 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_14 * V_15 = V_5 -> V_26 ;
struct V_24 V_25 ;
T_6 V_43 , V_44 ;
T_5 V_45 ;
int V_46 = V_47 ;
int V_48 = 1 ;
T_1 V_49 ;
int error = 0 ;
if ( F_17 ( V_15 ) )
return - V_50 ;
if ( F_18 ( V_5 ) )
return - V_51 ;
F_8 ( V_5 , V_7 ) ;
error = - V_19 ;
V_45 = V_15 -> V_52 -> V_53 ;
if ( ! V_41 )
V_45 = F_19 ( V_45 , F_20 ( F_21 ( V_1 ) ,
V_1 -> V_54 -> V_55 ) ) ;
if ( V_13 > V_45 )
goto V_56;
if ( V_13 > V_45 - V_39 )
V_39 = V_45 - V_13 ;
error = F_22 ( V_1 -> V_57 ) ;
if ( error )
goto V_56;
error = F_23 ( V_1 -> V_57 ) ;
if ( F_24 ( error ) )
return error ;
V_44 = F_25 ( V_15 , ( V_58 ) V_13 + V_39 ) ;
V_43 = F_26 ( V_15 , V_13 ) ;
V_49 = F_27 ( V_5 ) ;
error = F_28 ( V_5 , V_43 , V_44 - V_43 ,
& V_25 , & V_48 , V_46 ) ;
F_5 ( V_5 , V_49 ) ;
if ( error )
goto V_56;
if ( V_41 ) {
enum V_59 V_60 = 0 ;
ASSERT ( V_25 . V_27 != V_32 ) ;
if ( ! V_48 || V_25 . V_27 == V_28 ) {
F_8 ( V_5 , V_61 ) ;
error = F_29 ( V_5 , V_13 , V_39 ,
& V_25 , V_48 ) ;
if ( error )
goto V_56;
V_60 |= V_62 | V_63 ;
}
error = F_30 ( V_5 , V_60 ) ;
if ( error )
goto V_56;
}
F_5 ( V_5 , V_7 ) ;
F_13 ( V_5 , V_23 , & V_25 ) ;
* V_42 = V_15 -> V_64 ;
return error ;
V_56:
F_5 ( V_5 , V_7 ) ;
return error ;
}
static int
F_31 (
struct V_4 * V_5 ,
T_7 V_65 )
{
struct V_24 V_25 ;
int V_48 = 1 ;
int error = 0 ;
F_8 ( V_5 , V_61 ) ;
error = F_28 ( V_5 , F_26 ( V_5 -> V_26 , V_65 - 1 ) , 1 ,
& V_25 , & V_48 , 0 ) ;
F_5 ( V_5 , V_61 ) ;
if ( error )
return error ;
if ( V_25 . V_27 == V_28 ||
V_25 . V_27 == V_32 ||
V_25 . V_34 == V_35 )
return - V_50 ;
return 0 ;
}
int
F_32 (
struct V_1 * V_1 ,
struct V_23 * V_66 ,
int V_67 ,
struct V_68 * V_68 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_14 * V_15 = V_5 -> V_26 ;
struct V_69 * V_70 ;
bool V_71 = false ;
int error , V_72 ;
T_5 V_73 ;
ASSERT ( V_68 -> V_74 & ( V_75 | V_76 | V_77 ) ) ;
F_8 ( V_5 , V_7 ) ;
V_73 = F_21 ( V_1 ) ;
if ( ( V_68 -> V_74 & V_78 ) && V_68 -> V_79 > V_73 ) {
V_71 = true ;
V_73 = V_68 -> V_79 ;
}
for ( V_72 = 0 ; V_72 < V_67 ; V_72 ++ ) {
T_4 V_80 , V_39 , V_81 ;
V_80 = V_66 [ V_72 ] . V_13 ;
if ( V_80 > V_73 )
continue;
V_81 = V_80 + V_66 [ V_72 ] . V_39 ;
if ( V_81 > V_73 )
V_81 = V_73 ;
V_39 = V_81 - V_80 ;
if ( ! V_39 )
continue;
error = F_33 ( V_1 -> V_57 ,
V_80 >> V_82 ,
( V_81 - 1 ) >> V_82 ) ;
F_24 ( error ) ;
error = F_34 ( V_5 , V_80 , V_39 ) ;
if ( error )
goto V_83;
}
if ( V_71 ) {
error = F_31 ( V_5 , V_73 ) ;
if ( error )
goto V_83;
}
error = F_35 ( V_15 , & F_36 ( V_15 ) -> V_84 , 0 , 0 , 0 , & V_70 ) ;
if ( error )
goto V_83;
F_8 ( V_5 , V_85 ) ;
F_37 ( V_70 , V_5 , V_85 ) ;
F_38 ( V_70 , V_5 , V_86 ) ;
F_39 ( V_5 , V_68 ) ;
if ( V_71 ) {
F_40 ( V_1 , V_68 -> V_79 ) ;
V_5 -> V_87 . V_88 = V_68 -> V_79 ;
}
F_41 ( V_70 ) ;
error = F_42 ( V_70 ) ;
V_83:
F_5 ( V_5 , V_7 ) ;
return error ;
}
