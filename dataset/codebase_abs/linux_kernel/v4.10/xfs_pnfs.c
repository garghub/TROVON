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
int
F_11 (
struct V_1 * V_1 ,
T_5 V_12 ,
T_4 V_22 ,
struct V_23 * V_23 ,
bool V_24 ,
T_3 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_13 * V_14 = V_4 -> V_26 ;
struct V_27 V_28 ;
T_6 V_29 , V_30 ;
T_5 V_31 ;
int V_32 = V_33 ;
int V_34 = 1 ;
T_1 V_35 ;
int error = 0 ;
if ( F_12 ( V_14 ) )
return - V_36 ;
if ( F_13 ( V_4 ) )
return - V_37 ;
if ( F_14 ( V_4 ) )
return - V_37 ;
F_6 ( V_4 , V_6 ) ;
error = - V_18 ;
V_31 = V_14 -> V_38 -> V_39 ;
if ( ! V_24 )
V_31 = F_15 ( V_31 , F_16 ( F_17 ( V_1 ) ,
V_1 -> V_40 -> V_41 ) ) ;
if ( V_12 > V_31 )
goto V_42;
if ( V_12 > V_31 - V_22 )
V_22 = V_31 - V_12 ;
error = F_18 ( V_1 -> V_43 ) ;
if ( error )
goto V_42;
error = F_19 ( V_1 -> V_43 ) ;
if ( F_20 ( error ) )
return error ;
V_30 = F_21 ( V_14 , ( V_44 ) V_12 + V_22 ) ;
V_29 = F_22 ( V_14 , V_12 ) ;
V_35 = F_23 ( V_4 ) ;
error = F_24 ( V_4 , V_29 , V_30 - V_29 ,
& V_28 , & V_34 , V_32 ) ;
F_5 ( V_4 , V_35 ) ;
if ( error )
goto V_42;
if ( V_24 ) {
enum V_45 V_46 = 0 ;
ASSERT ( V_28 . V_47 != V_48 ) ;
if ( ! V_34 || V_28 . V_47 == V_49 ) {
F_6 ( V_4 , V_50 ) ;
error = F_25 ( V_4 , V_12 , V_22 ,
& V_28 , V_34 ) ;
if ( error )
goto V_42;
V_46 |= V_51 | V_52 ;
}
error = F_26 ( V_4 , V_46 ) ;
if ( error )
goto V_42;
}
F_5 ( V_4 , V_6 ) ;
F_27 ( V_4 , V_23 , & V_28 ) ;
* V_25 = V_14 -> V_53 ;
return error ;
V_42:
F_5 ( V_4 , V_6 ) ;
return error ;
}
static int
F_28 (
struct V_3 * V_4 ,
T_7 V_54 )
{
struct V_27 V_28 ;
int V_34 = 1 ;
int error = 0 ;
F_6 ( V_4 , V_50 ) ;
error = F_24 ( V_4 , F_22 ( V_4 -> V_26 , V_54 - 1 ) , 1 ,
& V_28 , & V_34 , 0 ) ;
F_5 ( V_4 , V_50 ) ;
if ( error )
return error ;
if ( V_28 . V_47 == V_49 ||
V_28 . V_47 == V_48 ||
V_28 . V_55 == V_56 )
return - V_36 ;
return 0 ;
}
int
F_29 (
struct V_1 * V_1 ,
struct V_23 * V_57 ,
int V_58 ,
struct V_59 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_13 * V_14 = V_4 -> V_26 ;
struct V_60 * V_61 ;
bool V_62 = false ;
int error , V_63 ;
T_5 V_64 ;
ASSERT ( V_59 -> V_65 & ( V_66 | V_67 | V_68 ) ) ;
F_6 ( V_4 , V_6 ) ;
V_64 = F_17 ( V_1 ) ;
if ( ( V_59 -> V_65 & V_69 ) && V_59 -> V_70 > V_64 ) {
V_62 = true ;
V_64 = V_59 -> V_70 ;
}
for ( V_63 = 0 ; V_63 < V_58 ; V_63 ++ ) {
T_4 V_71 , V_22 , V_72 ;
V_71 = V_57 [ V_63 ] . V_12 ;
if ( V_71 > V_64 )
continue;
V_72 = V_71 + V_57 [ V_63 ] . V_22 ;
if ( V_72 > V_64 )
V_72 = V_64 ;
V_22 = V_72 - V_71 ;
if ( ! V_22 )
continue;
error = F_30 ( V_1 -> V_43 ,
V_71 >> V_73 ,
( V_72 - 1 ) >> V_73 ) ;
F_20 ( error ) ;
error = F_31 ( V_4 , V_71 , V_22 ) ;
if ( error )
goto V_74;
}
if ( V_62 ) {
error = F_28 ( V_4 , V_64 ) ;
if ( error )
goto V_74;
}
error = F_32 ( V_14 , & F_33 ( V_14 ) -> V_75 , 0 , 0 , 0 , & V_61 ) ;
if ( error )
goto V_74;
F_6 ( V_4 , V_76 ) ;
F_34 ( V_61 , V_4 , V_76 ) ;
F_35 ( V_61 , V_4 , V_77 ) ;
F_36 ( V_4 , V_59 ) ;
if ( V_62 ) {
F_37 ( V_1 , V_59 -> V_70 ) ;
V_4 -> V_78 . V_79 = V_59 -> V_70 ;
}
F_38 ( V_61 ) ;
error = F_39 ( V_61 ) ;
V_74:
F_5 ( V_4 , V_6 ) ;
return error ;
}
