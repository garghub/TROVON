int F_1 ( T_1 * V_1 ,
struct V_2 * V_3 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
V_5 -> V_10 . V_11 . V_12 . V_13 =
F_4 ( V_14 ) ;
V_5 -> V_10 . V_11 . V_12 . V_15 = F_4 ( V_3 -> V_15 ) ;
V_5 -> V_10 . V_11 . V_12 . V_16 = V_3 -> type ;
if ( V_3 -> V_17 < 16 )
V_5 -> V_10 . V_11 . V_12 . V_17 = V_3 -> V_17 ;
else
V_5 -> V_10 . V_11 . V_12 . V_17 = 0xFF ;
if ( V_1 -> V_18 -> V_19 ) {
error = V_1 -> V_18 -> V_19 ( V_1 , ( V_20 * ) V_5 ,
sizeof( V_5 -> V_10 . V_11 . V_12 )
+ V_21 , ( V_20 * ) V_6 ,
sizeof( V_6 -> V_10 . V_11 . V_8 )
+ V_21 ) ;
} else {
error = V_22 ;
}
if ( error < 0 )
goto V_23;
error = F_5 ( V_6 , V_24 ) ;
if ( error == 0 ) {
V_3 -> V_17 = V_6 -> V_10 . V_11 . V_8 . V_25 ;
}
V_23:
F_6 () ;
return error ;
}
int F_7 ( T_1 * V_1 ,
T_2 V_26 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_27 . V_12 ) ) ;
V_5 -> V_10 . V_27 . V_12 . V_13 =
F_4 ( V_28 ) ;
V_5 -> V_10 . V_27 . V_12 . V_15 = F_4 ( V_26 ) ;
if ( V_1 -> V_18 -> V_19 ) {
error = V_1 -> V_18 -> V_19 ( V_1 , ( V_20 * ) V_5 ,
sizeof( V_5 -> V_10 . V_27 . V_12 )
+ V_21 , ( V_20 * ) V_6 ,
sizeof( V_6 -> V_10 . V_27 . V_8 )
+ V_21 ) ;
} else {
error = V_22 ;
}
if ( error < 0 )
goto V_23;
error = F_5 ( V_6 , V_29 ) ;
V_23:
F_6 () ;
return error ;
}
int F_8 ( T_1 * V_1 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_30 . V_12 ) ) ;
V_5 -> V_10 . V_30 . V_12 . V_13 =
F_4 ( V_31 ) ;
if ( V_1 -> V_18 -> V_19 ) {
error = V_1 -> V_18 -> V_19 ( V_1 , ( V_20 * ) V_5 ,
sizeof( V_5 -> V_10 . V_30 . V_12 )
+ V_21 , ( V_20 * ) V_6 ,
sizeof( V_6 -> V_10 . V_30 . V_8 )
+ V_21 ) ;
} else {
error = V_22 ;
}
if ( error < 0 )
goto V_23;
error = F_5 ( V_6 , V_32 ) ;
V_23:
F_6 () ;
return error ;
}
int F_9 ( T_1 * V_1 )
{
T_3 error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_33 . V_12 ) ) ;
V_5 -> V_10 . V_33 . V_12 . V_13 =
F_4 ( V_34 ) ;
if ( V_1 -> V_18 -> V_19 ) {
error = V_1 -> V_18 -> V_19 ( V_1 , ( V_20 * ) V_5 ,
sizeof( V_5 -> V_10 . V_33 . V_12 )
+ V_21 , ( V_20 * ) V_6 ,
sizeof( V_6 -> V_10 . V_33 . V_8 )
+ V_21 ) ;
} else {
error = V_22 ;
}
if ( error < 0 )
goto V_23;
error = F_5 ( V_6 , V_35 ) ;
V_23:
F_6 () ;
return error ;
}
