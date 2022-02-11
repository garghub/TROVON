static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_1 V_17 ;
if ( V_2 -> V_4 -> V_18 )
V_12 = F_5 ( V_2 -> V_4 -> V_18 ) ;
if ( V_5 -> V_18 )
V_12 = F_5 ( V_5 -> V_18 ) ;
if ( F_6 ( ! V_12 ) )
return;
if ( V_2 -> V_4 -> V_19 ) {
V_14 = F_7 ( V_2 -> V_4 -> V_19 ) ;
V_16 = F_8 ( V_14 -> V_20 ) ;
V_17 = V_16 -> V_21 ;
if ( V_16 -> V_22 ) {
F_9
( V_9 , V_17 , 0 ,
F_10 ( V_2 -> V_4 -> V_23 >> 16 ) ,
F_10 ( V_2 -> V_4 -> V_24 >> 16 ) ,
V_2 -> V_4 -> V_25 >> 16 ,
V_2 -> V_4 -> V_26 >> 16 , NULL ) ;
}
} else {
V_17 = 0 ;
}
F_11 ( L_1 , V_17 ,
V_2 -> V_4 -> V_27 , V_2 -> V_4 -> V_28 ,
V_2 -> V_4 -> V_29 , V_2 -> V_4 -> V_30 ,
V_2 -> V_4 -> V_23 >> 16 ,
V_2 -> V_4 -> V_24 >> 16 ,
V_2 -> V_4 -> V_25 >> 16 ,
V_2 -> V_4 -> V_26 >> 16 ) ;
F_12 ( V_9 , V_12 -> V_31 , V_17 ,
V_2 -> V_4 -> V_23 >> 16 ,
V_2 -> V_4 -> V_24 >> 16 ,
V_2 -> V_4 -> V_25 >> 16 ,
V_2 -> V_4 -> V_26 >> 16 ) ;
F_13 ( V_9 , V_17 ,
V_2 -> V_4 -> V_25 >> 16 ,
V_2 -> V_4 -> V_26 >> 16 ,
V_2 -> V_4 -> V_23 >> 16 ,
V_2 -> V_4 -> V_24 >> 16 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_32 * V_33 = NULL ;
struct V_15 * V_16 = NULL ;
T_1 V_17 ;
int V_34 = 0 ;
if ( V_2 -> V_4 -> V_18 )
V_12 = F_5 ( V_2 -> V_4 -> V_18 ) ;
if ( V_5 -> V_18 )
V_12 = F_5 ( V_5 -> V_18 ) ;
if ( F_6 ( ! V_12 ) )
return;
if ( V_2 -> V_4 -> V_19 ) {
V_14 = F_7 ( V_2 -> V_4 -> V_19 ) ;
V_16 = F_8 ( V_14 -> V_20 ) ;
V_17 = V_16 -> V_21 ;
} else {
V_17 = 0 ;
}
if ( V_16 && V_16 -> V_22 && ( V_2 -> V_4 -> V_19 != V_5 -> V_19 ) ) {
F_9
( V_9 , V_17 , 0 ,
F_10 ( V_2 -> V_4 -> V_27 ) ,
F_10 ( V_2 -> V_4 -> V_28 ) ,
0 , 0 , & V_33 ) ;
V_34 = F_15 ( V_16 , false ) ;
if ( ! V_34 ) {
F_16 ( V_16 -> V_35 . V_36 ,
& V_33 -> V_37 ) ;
F_17 ( & V_33 -> V_37 ) ;
V_33 = NULL ;
F_18 ( V_16 ) ;
F_19 ( V_16 , false ) ;
}
}
if ( V_2 -> V_4 -> V_19 != V_5 -> V_19 ) {
F_11 ( L_2 , V_17 ,
V_2 -> V_4 -> V_29 ,
V_2 -> V_4 -> V_30 ,
V_2 -> V_4 -> V_19 ? V_2 -> V_4 -> V_19 -> V_38 : 0 ,
V_2 -> V_4 -> V_19 ? V_2 -> V_4 -> V_19 -> V_39 : 0 ) ;
V_12 -> V_40 . V_41 . type =
F_10 ( V_42 ) ;
V_12 -> V_40 . V_43 = F_10 ( V_17 ) ;
if ( V_2 -> V_4 -> V_19 ) {
V_12 -> V_40 . V_38 =
F_10 ( V_2 -> V_4 -> V_19 -> V_38 ) ;
V_12 -> V_40 . V_39 =
F_10 ( V_2 -> V_4 -> V_19 -> V_39 ) ;
} else {
V_12 -> V_40 . V_38 = F_10 ( 0 ) ;
V_12 -> V_40 . V_39 = F_10 ( 0 ) ;
}
} else {
F_11 ( L_3 ,
V_2 -> V_4 -> V_29 ,
V_2 -> V_4 -> V_30 ) ;
V_12 -> V_40 . V_41 . type =
F_10 ( V_44 ) ;
}
V_12 -> V_40 . V_45 . V_46 = F_10 ( V_2 -> V_4 -> V_29 ) ;
V_12 -> V_40 . V_45 . V_47 = F_10 ( V_2 -> V_4 -> V_30 ) ;
F_20 ( V_9 , V_12 ) ;
}
struct V_1 * F_21 ( struct V_8 * V_9 ,
enum V_48 type ,
int V_31 )
{
struct V_6 * V_7 = V_9 -> V_49 ;
const struct V_50 * V_51 ;
struct V_1 * V_2 ;
const T_1 * V_52 ;
int V_34 , V_53 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return F_23 ( - V_55 ) ;
if ( type == V_56 ) {
V_52 = V_57 ;
V_53 = F_24 ( V_57 ) ;
V_51 = & V_58 ;
} else {
V_52 = V_59 ;
V_53 = F_24 ( V_59 ) ;
V_51 = & V_60 ;
}
V_34 = F_25 ( V_7 , V_2 , 1 << V_31 ,
& V_61 ,
V_52 , V_53 ,
type , NULL ) ;
if ( V_34 )
goto V_62;
F_26 ( V_2 , V_51 ) ;
return V_2 ;
V_62:
F_2 ( V_2 ) ;
return F_23 ( V_34 ) ;
}
