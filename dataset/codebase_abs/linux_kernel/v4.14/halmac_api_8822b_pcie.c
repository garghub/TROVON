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
if ( V_6 == 0xEA )
V_2 -> V_17 . V_18 = V_19 ;
else
V_2 -> V_17 . V_18 = V_20 ;
if ( V_4 == V_20 &&
V_2 -> V_17 . V_18 == V_20 ) {
F_5 (
V_7 , V_13 , V_21 ,
L_2 ) ;
return V_22 ;
}
if ( V_4 == V_19 ) {
if ( F_7 (
V_2 , V_23 ,
V_24 , V_5 ,
V_25 ) !=
V_9 ) {
F_8 ( L_3 ) ;
return V_26 ;
}
V_2 -> V_17 . V_18 = V_19 ;
V_2 -> V_17 . V_27 =
V_28 ;
V_2 -> V_17 . V_29 = V_30 ;
F_9 ( V_2 ) ;
} else {
if ( F_7 (
V_2 , V_23 ,
V_24 , V_5 ,
V_31 ) !=
V_9 ) {
F_8 ( L_4 ) ;
return V_32 ;
}
V_2 -> V_17 . V_18 = V_20 ;
V_2 -> V_17 . V_27 = V_33 ;
}
F_5 ( V_7 , V_13 , V_14 ,
L_5 ) ;
return V_9 ;
}
enum V_1
F_10 ( struct V_2 * V_2 ,
enum V_34 V_35 )
{
void * V_7 = NULL ;
struct V_8 * V_8 ;
T_1 V_36 = 0 ;
T_2 V_37 = 0 ;
if ( F_2 ( V_2 ) != V_9 )
return V_10 ;
if ( F_3 ( V_2 ) != V_9 )
return V_11 ;
F_4 ( V_2 , V_38 ) ;
V_7 = V_2 -> V_7 ;
V_8 = (struct V_8 * ) V_2 -> V_8 ;
F_5 ( V_7 , V_13 , V_14 ,
L_6 , V_39 ) ;
if ( V_35 == V_40 ) {
F_11 (
V_2 , V_41 ,
( F_12 ( V_2 ,
V_41 ) &
0xF0 ) | F_13 ( 0 ) ) ;
F_14 (
V_2 , V_42 ,
F_15 ( V_2 ,
V_42 ) |
F_13 ( 17 ) ) ;
V_36 =
F_12 ( V_2 ,
V_43 ) &
0x0F ;
V_37 = 2000 ;
while ( V_36 != V_44 && V_37 != 0 ) {
F_16 ( 50 , 60 ) ;
V_36 =
F_12 ( V_2 ,
V_43 ) &
0x0F ;
V_37 -- ;
}
if ( V_36 != V_44 ) {
F_8 ( L_7 ) ;
return V_45 ;
}
} else if ( V_35 == V_46 ) {
F_11 (
V_2 , V_41 ,
( F_12 ( V_2 ,
V_41 ) &
0xF0 ) | F_13 ( 1 ) ) ;
F_14 (
V_2 , V_42 ,
F_15 ( V_2 ,
V_42 ) |
F_13 ( 17 ) ) ;
V_36 =
F_12 ( V_2 ,
V_43 ) &
0x0F ;
V_37 = 2000 ;
while ( V_36 != V_47 && V_37 != 0 ) {
F_16 ( 50 , 60 ) ;
V_36 =
F_12 ( V_2 ,
V_43 ) &
0x0F ;
V_37 -- ;
}
if ( V_36 != V_47 ) {
F_8 ( L_7 ) ;
return V_45 ;
}
} else {
F_8 ( L_8 ) ;
return V_45 ;
}
F_5 ( V_7 , V_13 , V_14 ,
L_9 , V_39 ) ;
return V_9 ;
}
enum V_1
F_17 ( struct V_2 * V_2 ,
enum V_34 V_35 )
{
void * V_7 = NULL ;
struct V_8 * V_8 ;
if ( F_2 ( V_2 ) != V_9 )
return V_10 ;
if ( F_3 ( V_2 ) != V_9 )
return V_11 ;
F_4 ( V_2 , V_38 ) ;
V_7 = V_2 -> V_7 ;
V_8 = (struct V_8 * ) V_2 -> V_8 ;
F_5 ( V_7 , V_13 , V_14 ,
L_6 , V_39 ) ;
F_5 ( V_7 , V_13 , V_14 ,
L_9 , V_39 ) ;
return V_9 ;
}
enum V_1
F_18 ( struct V_2 * V_2 ,
enum V_48 V_49 )
{
void * V_7 = NULL ;
enum V_1 V_50 = V_9 ;
struct V_8 * V_8 ;
if ( F_2 ( V_2 ) != V_9 )
return V_10 ;
if ( F_3 ( V_2 ) != V_9 )
return V_11 ;
F_4 ( V_2 , V_51 ) ;
V_7 = V_2 -> V_7 ;
V_8 = (struct V_8 * ) V_2 -> V_8 ;
F_5 ( V_7 , V_13 , V_14 ,
L_10 ) ;
V_50 = F_19 ( V_2 ,
V_52 ,
V_49 , V_53 ) ;
if ( V_50 != V_9 )
return V_50 ;
V_50 = F_19 ( V_2 ,
V_54 ,
V_49 , V_55 ) ;
if ( V_50 != V_9 )
return V_50 ;
F_5 ( V_7 , V_13 , V_14 ,
L_11 ) ;
return V_9 ;
}
enum V_1 F_20 (
struct V_2 * V_2 )
{
return V_9 ;
}
