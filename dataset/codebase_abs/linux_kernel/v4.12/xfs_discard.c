STATIC int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_2 V_5 ,
T_2 V_6 ,
T_3 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int error ;
int V_18 ;
V_17 = F_2 ( V_2 , V_3 ) ;
error = F_3 ( V_2 , NULL , V_3 , 0 , & V_15 ) ;
if ( error || ! V_15 )
goto V_19;
V_13 = F_4 ( V_2 , NULL , V_15 , V_3 , V_20 ) ;
F_5 ( V_2 , V_21 ) ;
error = F_6 ( V_13 , 0 ,
F_7 ( F_8 ( V_15 ) -> V_22 ) , & V_18 ) ;
if ( error )
goto V_23;
while ( V_18 ) {
T_4 V_24 ;
T_5 V_25 ;
T_2 V_26 ;
T_5 V_27 ;
error = F_9 ( V_13 , & V_24 , & V_25 , & V_18 ) ;
if ( error )
goto V_23;
F_10 ( V_2 , V_18 == 1 , V_23 ) ;
ASSERT ( V_25 <= F_7 ( F_8 ( V_15 ) -> V_22 ) ) ;
V_26 = F_11 ( V_2 , V_3 , V_24 ) ;
V_27 = F_12 ( V_2 , V_25 ) ;
if ( V_27 < V_6 ) {
F_13 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_23;
}
if ( V_26 + V_27 < V_4 || V_26 > V_5 ) {
F_14 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_28;
}
if ( F_15 ( V_2 , V_3 , V_24 , V_25 ) ) {
F_16 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_28;
}
F_17 ( V_2 , V_3 , V_24 , V_25 ) ;
error = F_18 ( V_9 , V_26 , V_27 , V_29 , 0 ) ;
if ( error )
goto V_23;
* V_7 += V_25 ;
V_28:
error = F_19 ( V_13 , 0 , & V_18 ) ;
if ( error )
goto V_23;
if ( F_20 ( V_30 ) ) {
error = - V_31 ;
goto V_23;
}
}
V_23:
F_21 ( V_13 , error ? V_32 : V_33 ) ;
F_22 ( V_15 ) ;
V_19:
F_23 ( V_17 ) ;
return error ;
}
int
F_24 (
struct V_1 * V_2 ,
struct V_34 T_6 * V_35 )
{
struct V_36 * V_37 = F_25 ( V_2 -> V_10 -> V_11 ) ;
unsigned int V_38 = V_37 -> V_39 . V_40 ;
struct V_34 V_41 ;
T_2 V_4 , V_5 , V_6 ;
T_1 V_42 , V_43 , V_3 ;
T_3 V_7 = 0 ;
int error , V_44 = 0 ;
if ( ! F_26 ( V_45 ) )
return - V_46 ;
if ( ! F_27 ( V_37 ) )
return - V_47 ;
if ( F_28 ( & V_41 , V_35 , sizeof( V_41 ) ) )
return - V_48 ;
if ( V_41 . V_4 >= F_29 ( V_2 , V_2 -> V_49 . V_50 ) ||
V_41 . V_6 > F_29 ( V_2 , V_2 -> V_51 ) ||
V_41 . V_52 < V_2 -> V_49 . V_53 )
return - V_54 ;
V_4 = F_30 ( V_41 . V_4 ) ;
V_5 = V_4 + F_31 ( V_41 . V_52 ) - 1 ;
V_6 = F_30 ( F_32 ( V_55 , V_38 , V_41 . V_6 ) ) ;
if ( V_5 > F_12 ( V_2 , V_2 -> V_49 . V_50 ) - 1 )
V_5 = F_12 ( V_2 , V_2 -> V_49 . V_50 ) - 1 ;
V_42 = F_33 ( V_2 , V_4 ) ;
V_43 = F_33 ( V_2 , V_5 ) ;
for ( V_3 = V_42 ; V_3 <= V_43 ; V_3 ++ ) {
error = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
& V_7 ) ;
if ( error ) {
V_44 = error ;
if ( error == - V_31 )
break;
}
}
if ( V_44 )
return V_44 ;
V_41 . V_52 = F_29 ( V_2 , V_7 ) ;
if ( F_34 ( V_35 , & V_41 , sizeof( V_41 ) ) )
return - V_48 ;
return 0 ;
}
