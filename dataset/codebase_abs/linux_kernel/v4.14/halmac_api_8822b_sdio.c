enum V_1
F_1 ( struct V_2 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
T_2 V_8 ;
void * V_9 = NULL ;
struct V_10 * V_10 ;
if ( F_2 ( V_2 ) != V_11 )
return V_12 ;
if ( F_3 ( V_2 ) != V_11 )
return V_13 ;
V_9 = V_2 -> V_9 ;
V_10 = (struct V_10 * ) V_2 -> V_10 ;
F_4 (
V_9 , V_14 , V_15 ,
L_1 ) ;
F_4 ( V_9 , V_14 , V_15 ,
L_2 , V_4 ) ;
F_4 ( V_9 , V_14 , V_15 ,
L_3 ,
V_16 ) ;
V_5 = V_17 ;
V_2 -> V_18 =
F_5 ( V_2 , V_19 ) ;
if ( F_6 ( V_2 , V_20 ) == 0xC078 ) {
V_7 = ( T_1 ) ( ( V_2 -> V_18 ^ F_7 ( 7 ) ) & 0x80 ) ;
F_8 ( V_2 , V_19 , V_7 ) ;
}
V_6 = F_5 ( V_2 , V_21 ) ;
if ( V_6 == 0xEA )
V_2 -> V_22 . V_23 = V_24 ;
else
V_2 -> V_22 . V_23 = V_25 ;
if ( V_4 == V_25 &&
V_2 -> V_22 . V_23 == V_25 ) {
F_4 (
V_9 , V_14 , V_26 ,
L_4 ) ;
return V_27 ;
}
V_8 = F_9 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_28 , 0 ) ;
if ( V_4 == V_24 ) {
if ( F_11 (
V_2 , V_29 ,
V_30 , V_5 ,
V_31 ) !=
V_11 ) {
F_12 ( L_5 ) ;
F_10 ( V_2 , V_28 ,
V_8 ) ;
return V_32 ;
}
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_33 =
V_34 ;
V_2 -> V_22 . V_35 = V_36 ;
F_13 ( V_2 ) ;
} else {
if ( F_11 (
V_2 , V_29 ,
V_30 , V_5 ,
V_37 ) !=
V_11 ) {
F_12 ( L_6 ) ;
F_10 ( V_2 , V_28 ,
V_8 ) ;
return V_38 ;
}
V_2 -> V_22 . V_23 = V_25 ;
V_2 -> V_22 . V_33 = V_39 ;
}
F_10 ( V_2 , V_28 , V_8 ) ;
F_4 (
V_9 , V_14 , V_15 ,
L_7 ) ;
return V_11 ;
}
enum V_1
F_14 ( struct V_2 * V_2 ,
enum V_40 V_41 )
{
void * V_9 = NULL ;
struct V_10 * V_10 ;
if ( F_2 ( V_2 ) != V_11 )
return V_12 ;
if ( F_3 ( V_2 ) != V_11 )
return V_13 ;
F_15 ( V_2 , V_42 ) ;
V_9 = V_2 -> V_9 ;
V_10 = (struct V_10 * ) V_2 -> V_10 ;
F_4 ( V_9 , V_14 , V_15 ,
L_8 ) ;
F_4 ( V_9 , V_14 , V_15 ,
L_9 ) ;
F_4 ( V_9 , V_14 , V_15 ,
L_10 ) ;
return V_11 ;
}
enum V_1 F_16 (
struct V_2 * V_2 )
{
return V_11 ;
}
