int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_12 . V_13 ) ) ;
V_6 -> V_11 . V_12 . V_13 . V_14 = F_3 ( V_15 ) ;
V_6 -> V_11 . V_12 . V_13 . V_3 = F_3 ( V_3 ) ;
V_6 -> V_11 . V_12 . V_13 . type = F_3 ( V_16 ) ;
if ( V_2 -> V_17 -> V_18 ) {
error = V_2 -> V_17 -> V_18 ( V_2 ,
( V_19 * ) V_6 ,
sizeof( V_6 -> V_11 . V_12 . V_13 )
+ V_20 ,
( V_19 * ) V_7 ,
sizeof( V_7 -> V_11 . V_12 . V_9 )
+ V_20 ) ;
} else {
error = V_21 ;
}
if ( error < 0 )
goto V_22;
error = F_4 ( V_7 , V_23 ) ;
if ( error == 0 ) {
* V_4 = F_5 ( ( V_24 V_25 ) V_7 -> V_11 . V_12 . V_9 . V_26 . V_27 . V_28 ) ;
}
V_22:
return error ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_29 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_12 . V_13 ) ) ;
V_6 -> V_11 . V_12 . V_13 . V_14 = F_3 ( V_15 ) ;
V_6 -> V_11 . V_12 . V_13 . V_26 . V_27 . V_28 = ( V_24 V_30 ) F_7 ( V_29 ) ;
V_6 -> V_11 . V_12 . V_13 . V_3 = F_3 ( V_3 ) ;
V_6 -> V_11 . V_12 . V_13 . type = F_3 ( V_31 ) ;
if ( V_2 -> V_17 -> V_18 ) {
error = V_2 -> V_17 -> V_18 ( V_2 ,
( V_19 * ) V_6 ,
sizeof( V_6 -> V_11 . V_12 . V_13 )
+ V_20 ,
( V_19 * ) V_7 ,
sizeof( V_7 -> V_11 . V_12 . V_9 )
+ V_20 ) ;
} else {
error = V_21 ;
}
if ( error < 0 )
goto V_22;
error = F_4 ( V_7 , V_23 ) ;
V_22:
return error ;
}
int F_8 ( struct V_1 * V_2 , V_19 V_32 )
{
int error ;
struct V_5 * V_6 , * V_7 ;
V_6 = V_2 -> V_8 ;
V_7 = V_2 -> V_9 ;
F_2 ( V_6 , ( ++ V_2 -> V_10 ) ,
sizeof( V_6 -> V_11 . V_33 . V_13 ) ) ;
V_6 -> V_11 . V_33 . V_13 . V_14 =
F_3 ( V_34 ) ;
V_6 -> V_11 . V_33 . V_13 . V_32 = V_32 ;
if ( V_2 -> V_17 -> V_18 ) {
error = V_2 -> V_17 -> V_18 ( V_2 , ( V_19 * ) V_6 ,
sizeof( V_6 -> V_11 . V_33 . V_13 )
+ V_20 , ( V_19 * ) V_7 ,
sizeof( V_7 -> V_11 . V_33 . V_9 )
+ V_20 ) ;
} else {
error = V_21 ;
}
if ( error < 0 )
goto V_22;
error = F_9 ( V_7 , V_35 ) ;
V_22:
return error ;
}
int F_4 ( struct V_5 * V_7 , T_1 V_14 )
{
int V_36 ;
V_36 = V_7 -> V_11 . V_12 . V_9 . error ;
if ( ( V_36 == 0 ) &&
( F_10 ( V_7 -> V_11 . V_12 . V_9 . V_14 ) == V_14 ) ) {
return 0 ;
}
return V_21 ;
}
