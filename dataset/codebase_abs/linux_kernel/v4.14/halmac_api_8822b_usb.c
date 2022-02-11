enum V_1
F_1 ( struct V_2 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
void * V_7 = NULL ;
struct V_8 * V_8 ;
if ( F_2 ( V_2 ) != V_9 )
return V_10 ;
if ( F_3 ( V_2 ) != V_9 )
return V_11 ;
F_4 ( V_2 , V_12 ) ;
V_7 = V_2 -> V_7 ;
V_8 = (struct V_8 * ) V_2 -> V_8 ;
F_5 (
V_7 , V_13 , V_14 ,
L_1 ,
V_4 ) ;
V_5 = V_15 ;
V_6 = F_6 ( V_2 , V_16 ) ;
if ( V_6 == 0xEA ) {
V_2 -> V_17 . V_18 = V_19 ;
} else {
if ( F_7 ( 0 ) ==
( F_6 ( V_2 , V_20 + 1 ) &
F_7 ( 0 ) ) )
V_2 -> V_17 . V_18 =
V_19 ;
else
V_2 -> V_17 . V_18 =
V_21 ;
}
if ( V_4 == V_21 &&
V_2 -> V_17 . V_18 == V_21 ) {
F_5 (
V_7 , V_13 , V_22 ,
L_2 ) ;
return V_23 ;
}
if ( V_4 == V_19 ) {
if ( F_8 (
V_2 , V_24 ,
V_25 , V_5 ,
V_26 ) !=
V_9 ) {
F_9 ( L_3 ) ;
return V_27 ;
}
V_2 -> V_17 . V_18 = V_19 ;
V_2 -> V_17 . V_28 =
V_29 ;
V_2 -> V_17 . V_30 = V_31 ;
F_10 ( V_2 ) ;
} else {
if ( F_8 (
V_2 , V_24 ,
V_25 , V_5 ,
V_32 ) !=
V_9 ) {
F_9 ( L_4 ) ;
return V_33 ;
}
F_11 (
V_2 , V_20 + 1 ,
F_6 ( V_2 , V_20 + 1 ) &
~ ( F_7 ( 0 ) ) ) ;
V_2 -> V_17 . V_18 = V_21 ;
V_2 -> V_17 . V_28 = V_34 ;
}
F_5 ( V_7 , V_13 , V_14 ,
L_5 ) ;
return V_9 ;
}
enum V_1
F_12 ( struct V_2 * V_2 ,
enum V_35 V_36 )
{
void * V_7 = NULL ;
enum V_1 V_37 = V_9 ;
struct V_8 * V_8 ;
if ( F_2 ( V_2 ) != V_9 )
return V_10 ;
if ( F_3 ( V_2 ) != V_9 )
return V_11 ;
F_4 ( V_2 , V_38 ) ;
V_7 = V_2 -> V_7 ;
V_8 = (struct V_8 * ) V_2 -> V_8 ;
F_5 ( V_7 , V_13 , V_14 ,
L_6 ) ;
V_37 = F_13 ( V_2 ,
V_39 , V_36 ,
V_40 ) ;
if ( V_37 != V_9 )
return V_37 ;
V_37 = F_13 ( V_2 ,
V_41 , V_36 ,
V_42 ) ;
if ( V_37 != V_9 )
return V_37 ;
F_5 ( V_7 , V_13 , V_14 ,
L_7 ) ;
return V_9 ;
}
enum V_1 F_14 (
struct V_2 * V_2 )
{
return V_9 ;
}
