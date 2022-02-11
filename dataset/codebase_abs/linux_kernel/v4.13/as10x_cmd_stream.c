int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_12 . V_13 ) ) ;
V_6 -> V_11 . V_12 . V_13 . V_14 =
F_3 ( V_15 ) ;
V_6 -> V_11 . V_12 . V_13 . V_16 = F_3 ( V_4 -> V_16 ) ;
V_6 -> V_11 . V_12 . V_13 . V_17 = V_4 -> type ;
if ( V_4 -> V_18 < 16 )
V_6 -> V_11 . V_12 . V_13 . V_18 = V_4 -> V_18 ;
else
V_6 -> V_11 . V_12 . V_13 . V_18 = 0xFF ;
if ( V_2 -> V_19 -> V_20 ) {
error = V_2 -> V_19 -> V_20 ( V_2 , ( V_21 * ) V_6 ,
sizeof( V_6 -> V_11 . V_12 . V_13 )
+ V_22 , ( V_21 * ) V_7 ,
sizeof( V_7 -> V_11 . V_12 . V_9 )
+ V_22 ) ;
} else {
error = V_23 ;
}
if ( error < 0 )
goto V_24;
error = F_4 ( V_7 , V_25 ) ;
if ( error == 0 ) {
V_4 -> V_18 = V_7 -> V_11 . V_12 . V_9 . V_26 ;
}
V_24:
return error ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 V_27 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_28 . V_13 ) ) ;
V_6 -> V_11 . V_28 . V_13 . V_14 =
F_3 ( V_29 ) ;
V_6 -> V_11 . V_28 . V_13 . V_16 = F_3 ( V_27 ) ;
if ( V_2 -> V_19 -> V_20 ) {
error = V_2 -> V_19 -> V_20 ( V_2 , ( V_21 * ) V_6 ,
sizeof( V_6 -> V_11 . V_28 . V_13 )
+ V_22 , ( V_21 * ) V_7 ,
sizeof( V_7 -> V_11 . V_28 . V_9 )
+ V_22 ) ;
} else {
error = V_23 ;
}
if ( error < 0 )
goto V_24;
error = F_4 ( V_7 , V_30 ) ;
V_24:
return error ;
}
int F_6 ( struct V_1 * V_2 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_31 . V_13 ) ) ;
V_6 -> V_11 . V_31 . V_13 . V_14 =
F_3 ( V_32 ) ;
if ( V_2 -> V_19 -> V_20 ) {
error = V_2 -> V_19 -> V_20 ( V_2 , ( V_21 * ) V_6 ,
sizeof( V_6 -> V_11 . V_31 . V_13 )
+ V_22 , ( V_21 * ) V_7 ,
sizeof( V_7 -> V_11 . V_31 . V_9 )
+ V_22 ) ;
} else {
error = V_23 ;
}
if ( error < 0 )
goto V_24;
error = F_4 ( V_7 , V_33 ) ;
V_24:
return error ;
}
int F_7 ( struct V_1 * V_2 )
{
T_2 error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_34 . V_13 ) ) ;
V_6 -> V_11 . V_34 . V_13 . V_14 =
F_3 ( V_35 ) ;
if ( V_2 -> V_19 -> V_20 ) {
error = V_2 -> V_19 -> V_20 ( V_2 , ( V_21 * ) V_6 ,
sizeof( V_6 -> V_11 . V_34 . V_13 )
+ V_22 , ( V_21 * ) V_7 ,
sizeof( V_7 -> V_11 . V_34 . V_9 )
+ V_22 ) ;
} else {
error = V_23 ;
}
if ( error < 0 )
goto V_24;
error = F_4 ( V_7 , V_36 ) ;
V_24:
return error ;
}
