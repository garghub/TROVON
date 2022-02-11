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
int
F_13 (
struct V_1 * V_1 ,
T_5 V_13 ,
T_4 V_23 ,
struct V_24 * V_24 ,
bool V_25 ,
T_3 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_14 * V_15 = V_5 -> V_27 ;
struct V_28 V_29 ;
T_6 V_30 , V_31 ;
T_5 V_32 ;
int V_33 = V_34 ;
int V_35 = 1 ;
T_1 V_36 ;
int error = 0 ;
if ( F_14 ( V_15 ) )
return - V_37 ;
if ( F_15 ( V_5 ) )
return - V_38 ;
if ( F_16 ( V_5 ) )
return - V_38 ;
F_8 ( V_5 , V_7 ) ;
error = - V_19 ;
V_32 = V_15 -> V_39 -> V_40 ;
if ( ! V_25 )
V_32 = F_17 ( V_32 , F_18 ( F_19 ( V_1 ) ,
V_1 -> V_41 -> V_42 ) ) ;
if ( V_13 > V_32 )
goto V_43;
if ( V_13 > V_32 - V_23 )
V_23 = V_32 - V_13 ;
error = F_20 ( V_1 -> V_44 ) ;
if ( error )
goto V_43;
error = F_21 ( V_1 -> V_44 ) ;
if ( F_22 ( error ) )
return error ;
V_31 = F_23 ( V_15 , ( V_45 ) V_13 + V_23 ) ;
V_30 = F_24 ( V_15 , V_13 ) ;
V_36 = F_25 ( V_5 ) ;
error = F_26 ( V_5 , V_30 , V_31 - V_30 ,
& V_29 , & V_35 , V_33 ) ;
F_5 ( V_5 , V_36 ) ;
if ( error )
goto V_43;
if ( V_25 ) {
enum V_46 V_47 = 0 ;
ASSERT ( V_29 . V_48 != V_49 ) ;
if ( ! V_35 || V_29 . V_48 == V_50 ) {
F_8 ( V_5 , V_51 ) ;
error = F_27 ( V_5 , V_13 , V_23 ,
& V_29 , V_35 ) ;
if ( error )
goto V_43;
V_47 |= V_52 | V_53 ;
}
error = F_28 ( V_5 , V_47 ) ;
if ( error )
goto V_43;
}
F_5 ( V_5 , V_7 ) ;
F_29 ( V_5 , V_24 , & V_29 ) ;
* V_26 = V_15 -> V_54 ;
return error ;
V_43:
F_5 ( V_5 , V_7 ) ;
return error ;
}
static int
F_30 (
struct V_4 * V_5 ,
T_7 V_55 )
{
struct V_28 V_29 ;
int V_35 = 1 ;
int error = 0 ;
F_8 ( V_5 , V_51 ) ;
error = F_26 ( V_5 , F_24 ( V_5 -> V_27 , V_55 - 1 ) , 1 ,
& V_29 , & V_35 , 0 ) ;
F_5 ( V_5 , V_51 ) ;
if ( error )
return error ;
if ( V_29 . V_48 == V_50 ||
V_29 . V_48 == V_49 ||
V_29 . V_56 == V_57 )
return - V_37 ;
return 0 ;
}
int
F_31 (
struct V_1 * V_1 ,
struct V_24 * V_58 ,
int V_59 ,
struct V_60 * V_60 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_14 * V_15 = V_5 -> V_27 ;
struct V_61 * V_62 ;
bool V_63 = false ;
int error , V_64 ;
T_5 V_65 ;
ASSERT ( V_60 -> V_66 & ( V_67 | V_68 | V_69 ) ) ;
F_8 ( V_5 , V_7 ) ;
V_65 = F_19 ( V_1 ) ;
if ( ( V_60 -> V_66 & V_70 ) && V_60 -> V_71 > V_65 ) {
V_63 = true ;
V_65 = V_60 -> V_71 ;
}
for ( V_64 = 0 ; V_64 < V_59 ; V_64 ++ ) {
T_4 V_72 , V_23 , V_73 ;
V_72 = V_58 [ V_64 ] . V_13 ;
if ( V_72 > V_65 )
continue;
V_73 = V_72 + V_58 [ V_64 ] . V_23 ;
if ( V_73 > V_65 )
V_73 = V_65 ;
V_23 = V_73 - V_72 ;
if ( ! V_23 )
continue;
error = F_32 ( V_1 -> V_44 ,
V_72 >> V_74 ,
( V_73 - 1 ) >> V_74 ) ;
F_22 ( error ) ;
error = F_33 ( V_5 , V_72 , V_23 ) ;
if ( error )
goto V_75;
}
if ( V_63 ) {
error = F_30 ( V_5 , V_65 ) ;
if ( error )
goto V_75;
}
error = F_34 ( V_15 , & F_35 ( V_15 ) -> V_76 , 0 , 0 , 0 , & V_62 ) ;
if ( error )
goto V_75;
F_8 ( V_5 , V_77 ) ;
F_36 ( V_62 , V_5 , V_77 ) ;
F_37 ( V_62 , V_5 , V_78 ) ;
F_38 ( V_5 , V_60 ) ;
if ( V_63 ) {
F_39 ( V_1 , V_60 -> V_71 ) ;
V_5 -> V_79 . V_80 = V_60 -> V_71 ;
}
F_40 ( V_62 ) ;
error = F_41 ( V_62 ) ;
V_75:
F_5 ( V_5 , V_7 ) ;
return error ;
}
