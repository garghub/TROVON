bool F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 ,
V_5 ) ;
T_1 V_6 ;
if ( F_3 ( V_2 -> V_7 . V_8 , V_3 , NULL ,
NULL , NULL , & V_6 ) ) {
struct V_9 * V_10 =
(struct V_9 * ) ( V_2 -> V_7 . V_8 -> V_11 +
V_6 ) ;
if ( F_4 ( V_10 -> V_12 ) &
V_13 )
return true ;
}
return false ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 ,
V_5 ) ;
T_1 V_6 ;
if ( F_3 ( V_2 -> V_7 . V_8 , V_3 , NULL ,
NULL , NULL , & V_6 ) ) {
struct V_9 * V_10 =
(struct V_9 * ) ( V_2 -> V_7 . V_8 -> V_11 +
V_6 ) ;
V_2 -> V_14 =
F_4 ( V_10 -> V_15 ) ;
}
}
int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_16 = V_2 -> V_7 . V_8 ;
int V_3 = F_2 ( V_4 ,
V_17 ) ;
T_1 V_6 ;
int V_18 = 0 ;
if ( F_3 ( V_16 , V_3 , NULL , NULL , NULL , & V_6 ) ) {
struct V_19 * V_20 =
(struct V_19 * ) ( V_16 -> V_11 + V_6 ) ;
F_7 ( L_1 ,
F_4 ( V_20 -> V_21 ) ,
F_8 ( V_20 -> V_22 ) ,
F_8 ( V_20 -> V_23 ) ) ;
V_18 = F_8 ( V_20 -> V_23 ) * 1024 ;
}
V_16 -> V_24 = 0 ;
if ( V_18 == 0 )
V_18 = 20 * 1024 ;
V_16 -> V_25 = F_9 ( V_18 , V_26 ) ;
if ( ! V_16 -> V_25 )
return - V_27 ;
V_16 -> V_24 = V_18 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = & V_2 -> V_7 ;
int V_3 = F_2 ( V_4 ,
V_29 ) ;
T_2 V_6 , V_30 ;
union V_31 * V_31 ;
T_3 V_32 , V_33 ;
if ( F_3 ( V_7 -> V_8 , V_3 , & V_30 ,
& V_32 , & V_33 , & V_6 ) ) {
V_31 = (union V_31 * )
( V_7 -> V_8 -> V_11 + V_6 ) ;
switch ( V_33 ) {
case 11 :
return V_31 -> V_34 . V_35 * 64 ;
default:
return 0 ;
}
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = & V_2 -> V_7 ;
struct V_36 * V_37 = & V_2 -> clock . V_37 ;
struct V_36 * V_38 = & V_2 -> clock . V_38 ;
T_4 V_32 , V_33 ;
T_1 V_6 ;
int V_39 = - V_40 , V_3 ;
V_3 = F_2 ( V_4 ,
V_5 ) ;
if ( F_3 ( V_7 -> V_8 , V_3 , NULL ,
& V_32 , & V_33 , & V_6 ) ) {
union V_10 * V_10 =
(union V_10 * ) ( V_7 -> V_8 -> V_11 +
V_6 ) ;
V_2 -> clock . V_41 =
F_4 ( V_10 -> V_42 . V_43 ) ;
V_2 -> clock . V_44 =
F_4 ( V_10 -> V_42 . V_45 ) ;
V_2 -> V_46 . V_47 = V_2 -> clock . V_41 ;
V_2 -> V_46 . V_48 = V_2 -> clock . V_44 ;
V_2 -> V_7 . V_49 =
F_4 ( V_10 -> V_42 . V_12 ) ;
V_39 = 0 ;
}
V_3 = F_2 ( V_4 ,
V_50 ) ;
if ( F_3 ( V_7 -> V_8 , V_3 , NULL ,
& V_32 , & V_33 , & V_6 ) ) {
union V_50 * V_50 =
(union V_50 * ) ( V_7 -> V_8 -> V_11 +
V_6 ) ;
V_37 -> V_51 = F_4 ( V_50 -> V_42 . V_52 ) ;
V_37 -> V_53 = 0 ;
V_37 -> V_54 = 1 ;
V_37 -> V_55 = 1 ;
V_37 -> V_56 = 2 ;
V_37 -> V_57 = 0xff ;
V_37 -> V_58 = 4 ;
V_37 -> V_59 = 0xff ;
V_37 -> V_60 = 0 ;
V_39 = 0 ;
}
V_3 = F_2 ( V_4 ,
V_61 ) ;
if ( F_3 ( V_7 -> V_8 , V_3 , NULL ,
& V_32 , & V_33 , & V_6 ) ) {
union V_61 * V_61 =
(union V_61 * ) ( V_7 -> V_8 -> V_11 +
V_6 ) ;
V_38 -> V_51 = F_4 ( V_61 -> V_42 . V_62 ) ;
V_38 -> V_53 = 0 ;
V_38 -> V_54 = 1 ;
V_38 -> V_55 = 1 ;
V_38 -> V_56 = 2 ;
V_38 -> V_57 = 0xff ;
V_38 -> V_58 = 4 ;
V_38 -> V_59 = 0xff ;
V_38 -> V_60 = 0 ;
V_39 = 0 ;
}
return V_39 ;
}
