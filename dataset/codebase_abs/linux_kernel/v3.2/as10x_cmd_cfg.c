int F_1 ( T_1 * V_1 , T_2 V_2 ,
T_3 * V_3 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
V_5 -> V_10 . V_11 . V_12 . V_13 = F_4 ( V_14 ) ;
V_5 -> V_10 . V_11 . V_12 . V_2 = F_4 ( V_2 ) ;
V_5 -> V_10 . V_11 . V_12 . type = F_4 ( V_15 ) ;
if ( V_1 -> V_16 -> V_17 ) {
error = V_1 -> V_16 -> V_17 ( V_1 ,
( V_18 * ) V_5 ,
sizeof( V_5 -> V_10 . V_11 . V_12 )
+ V_19 ,
( V_18 * ) V_6 ,
sizeof( V_6 -> V_10 . V_11 . V_8 )
+ V_19 ) ;
} else {
error = V_20 ;
}
if ( error < 0 )
goto V_21;
error = F_5 ( V_6 , V_22 ) ;
if ( error == 0 ) {
* V_3 = F_6 ( V_6 -> V_10 . V_11 . V_8 . V_23 . V_24 . V_25 ) ;
}
V_21:
F_7 () ;
return error ;
}
int F_8 ( T_1 * V_1 , T_2 V_2 ,
T_3 V_26 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
V_5 -> V_10 . V_11 . V_12 . V_13 = F_4 ( V_14 ) ;
V_5 -> V_10 . V_11 . V_12 . V_23 . V_24 . V_25 = F_9 ( V_26 ) ;
V_5 -> V_10 . V_11 . V_12 . V_2 = F_4 ( V_2 ) ;
V_5 -> V_10 . V_11 . V_12 . type = F_4 ( V_27 ) ;
if ( V_1 -> V_16 -> V_17 ) {
error = V_1 -> V_16 -> V_17 ( V_1 ,
( V_18 * ) V_5 ,
sizeof( V_5 -> V_10 . V_11 . V_12 )
+ V_19 ,
( V_18 * ) V_6 ,
sizeof( V_6 -> V_10 . V_11 . V_8 )
+ V_19 ) ;
} else {
error = V_20 ;
}
if ( error < 0 )
goto V_21;
error = F_5 ( V_6 , V_22 ) ;
V_21:
F_7 () ;
return error ;
}
int F_10 ( T_1 * V_1 , V_18 V_28 )
{
int error ;
struct V_4 * V_5 , * V_6 ;
F_2 () ;
V_5 = V_1 -> V_7 ;
V_6 = V_1 -> V_8 ;
F_3 ( V_5 , ( ++ V_1 -> V_9 ) ,
sizeof( V_5 -> V_10 . V_29 . V_12 ) ) ;
V_5 -> V_10 . V_29 . V_12 . V_13 =
F_4 ( V_30 ) ;
V_5 -> V_10 . V_29 . V_12 . V_28 = V_28 ;
if ( V_1 -> V_16 -> V_17 ) {
error = V_1 -> V_16 -> V_17 ( V_1 , ( V_18 * ) V_5 ,
sizeof( V_5 -> V_10 . V_29 . V_12 )
+ V_19 , ( V_18 * ) V_6 ,
sizeof( V_6 -> V_10 . V_29 . V_8 )
+ V_19 ) ;
} else {
error = V_20 ;
}
if ( error < 0 )
goto V_21;
error = F_11 ( V_6 , V_31 ) ;
V_21:
F_7 () ;
return error ;
}
int F_5 ( struct V_4 * V_6 , T_2 V_13 )
{
int V_32 ;
V_32 = V_6 -> V_10 . V_11 . V_8 . error ;
if ( ( V_32 == 0 ) &&
( F_12 ( V_6 -> V_10 . V_11 . V_8 . V_13 ) == V_13 ) ) {
return 0 ;
}
return V_20 ;
}
