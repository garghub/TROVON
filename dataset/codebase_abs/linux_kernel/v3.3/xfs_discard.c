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
error = F_9 ( V_13 , & V_24 , & V_25 , & V_18 ) ;
if ( error )
goto V_23;
F_10 ( V_18 == 1 , V_23 ) ;
ASSERT ( V_25 <= F_7 ( F_8 ( V_15 ) -> V_22 ) ) ;
if ( V_25 < V_6 ) {
F_11 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_23;
}
if ( F_12 ( V_2 , V_3 , V_24 ) + V_25 < V_4 ||
F_12 ( V_2, V_3, V_24 ) > V_5 ) {
F_13 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_26;
}
if ( F_14 ( V_2 , V_3 , V_24 , V_25 ) ) {
F_15 ( V_2 , V_3 , V_24 , V_25 ) ;
goto V_26;
}
F_16 ( V_2 , V_3 , V_24 , V_25 ) ;
error = - F_17 ( V_9 ,
F_18 ( V_2 , V_3 , V_24 ) ,
F_19 ( V_2 , V_25 ) ,
V_27 , 0 ) ;
if ( error )
goto V_23;
* V_7 += V_25 ;
V_26:
error = F_20 ( V_13 , 0 , & V_18 ) ;
if ( error )
goto V_23;
}
V_23:
F_21 ( V_13 , error ? V_28 : V_29 ) ;
F_22 ( V_15 ) ;
V_19:
F_23 ( V_17 ) ;
return error ;
}
int
F_24 (
struct V_1 * V_2 ,
struct V_30 T_6 * V_31 )
{
struct V_32 * V_33 = V_2 -> V_10 -> V_11 -> V_34 -> V_35 ;
unsigned int V_36 = V_33 -> V_37 . V_38 ;
struct V_30 V_39 ;
T_2 V_4 , V_5 , V_6 ;
T_1 V_40 , V_41 , V_3 ;
T_3 V_7 = 0 ;
int error , V_42 = 0 ;
if ( ! F_25 ( V_43 ) )
return - F_26 ( V_44 ) ;
if ( ! F_27 ( V_33 ) )
return - F_26 ( V_45 ) ;
if ( F_28 ( & V_39 , V_31 , sizeof( V_39 ) ) )
return - F_26 ( V_46 ) ;
V_4 = F_29 ( V_2 , V_39 . V_4 ) ;
V_5 = V_4 + F_29 ( V_2 , V_39 . V_47 ) - 1 ;
V_6 = F_30 ( V_2 , F_31 ( V_48 , V_36 , V_39 . V_6 ) ) ;
if ( V_4 >= V_2 -> V_49 . V_50 )
return - F_26 ( V_51 ) ;
if ( V_5 > V_2 -> V_49 . V_50 - 1 )
V_5 = V_2 -> V_49 . V_50 - 1 ;
V_40 = F_32 ( V_2 , V_4 ) ;
V_41 = F_32 ( V_2 , V_5 ) ;
for ( V_3 = V_40 ; V_3 <= V_41 ; V_3 ++ ) {
error = - F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
& V_7 ) ;
if ( error )
V_42 = error ;
}
if ( V_42 )
return V_42 ;
V_39 . V_47 = F_33 ( V_2 , V_7 ) ;
if ( F_34 ( V_31 , & V_39 , sizeof( V_39 ) ) )
return - F_26 ( V_46 ) ;
return 0 ;
}
int
F_35 (
struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 ;
int error = 0 ;
F_36 (busyp, list, list) {
F_16 ( V_2 , V_55 -> V_3 , V_55 -> V_56 ,
V_55 -> V_57 ) ;
error = - F_17 ( V_2 -> V_10 -> V_11 ,
F_18 ( V_2 , V_55 -> V_3 , V_55 -> V_56 ) ,
F_19 ( V_2 , V_55 -> V_57 ) ,
V_27 , 0 ) ;
if ( error && error != V_45 ) {
F_37 ( V_2 ,
L_1 ,
( unsigned long long ) V_55 -> V_56 ,
V_55 -> V_57 ,
error ) ;
return error ;
}
}
return 0 ;
}
