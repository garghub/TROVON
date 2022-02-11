T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
switch ( V_1 ) {
#ifdef F_2
case V_3 :
V_2 = V_4 ;
break;
case V_5 :
V_2 = V_6 ;
break;
case V_7 :
V_2 = V_8 ;
break;
case V_9 :
V_2 = V_10 ;
break;
case V_11 :
V_2 = V_12 ;
break;
case V_13 :
V_2 = V_14 ;
break;
case V_15 :
V_2 = V_16 ;
break;
case V_17 :
V_2 = V_18 ;
break;
#else
case V_3 :
V_2 = V_8 ;
break;
case V_5 :
V_2 = V_10 ;
break;
case V_7 :
V_2 = V_4 ;
break;
case V_9 :
V_2 = V_6 ;
break;
case V_11 :
V_2 = V_16 ;
break;
case V_13 :
V_2 = V_18 ;
break;
case V_15 :
V_2 = V_12 ;
break;
case V_17 :
V_2 = V_14 ;
break;
#endif
default:
V_2 = 0 ;
break;
}
F_3 ( V_2 == 0 ) ;
return V_2 ;
}
static void F_4 ( struct V_19 * V_20 )
{
F_5 ( V_20 ) ;
F_6 ( V_20 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
return 0 ;
}
static void F_8 ( struct V_19 * V_20 ,
struct V_21 * V_23 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 V_35 ;
if ( V_20 -> V_22 -> V_36 )
V_30 = F_9 ( V_20 -> V_22 -> V_36 ) ;
if ( V_23 -> V_36 )
V_30 = F_9 ( V_23 -> V_36 ) ;
if ( F_3 ( ! V_30 ) )
return;
if ( V_20 -> V_22 -> V_37 ) {
V_32 = F_10 ( V_20 -> V_22 -> V_37 ) ;
V_34 = F_11 ( V_32 -> V_38 ) ;
V_35 = V_34 -> V_39 ;
if ( V_34 -> V_40 ) {
F_12
( V_27 , V_35 , 0 ,
F_13 ( V_20 -> V_22 -> V_41 >> 16 ) ,
F_13 ( V_20 -> V_22 -> V_42 >> 16 ) ,
F_13 ( V_20 -> V_22 -> V_43 >> 16 ) ,
F_13 ( V_20 -> V_22 -> V_44 >> 16 ) , NULL ) ;
}
} else {
V_35 = 0 ;
}
F_14 ( L_1 , V_35 ,
V_20 -> V_22 -> V_45 , V_20 -> V_22 -> V_46 ,
V_20 -> V_22 -> V_47 , V_20 -> V_22 -> V_48 ,
V_20 -> V_22 -> V_41 >> 16 ,
V_20 -> V_22 -> V_42 >> 16 ,
V_20 -> V_22 -> V_43 >> 16 ,
V_20 -> V_22 -> V_44 >> 16 ) ;
F_15 ( V_27 , V_30 -> V_49 , V_35 ,
V_20 -> V_22 -> V_41 >> 16 ,
V_20 -> V_22 -> V_42 >> 16 ,
V_20 -> V_22 -> V_43 >> 16 ,
V_20 -> V_22 -> V_44 >> 16 ) ;
F_16 ( V_27 , V_35 ,
V_20 -> V_22 -> V_43 >> 16 ,
V_20 -> V_22 -> V_44 >> 16 ,
V_20 -> V_22 -> V_41 >> 16 ,
V_20 -> V_22 -> V_42 >> 16 ) ;
}
static void F_17 ( struct V_19 * V_20 ,
struct V_21 * V_23 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_50 * V_51 = NULL ;
struct V_33 * V_34 = NULL ;
T_1 V_35 ;
int V_52 = 0 ;
if ( V_20 -> V_22 -> V_36 )
V_30 = F_9 ( V_20 -> V_22 -> V_36 ) ;
if ( V_23 -> V_36 )
V_30 = F_9 ( V_23 -> V_36 ) ;
if ( F_3 ( ! V_30 ) )
return;
if ( V_20 -> V_22 -> V_37 ) {
V_32 = F_10 ( V_20 -> V_22 -> V_37 ) ;
V_34 = F_11 ( V_32 -> V_38 ) ;
V_35 = V_34 -> V_39 ;
} else {
V_35 = 0 ;
}
if ( V_34 && V_34 -> V_40 && ( V_20 -> V_22 -> V_37 != V_23 -> V_37 ) ) {
F_12
( V_27 , V_35 , 0 ,
F_13 ( V_20 -> V_22 -> V_45 ) ,
F_13 ( V_20 -> V_22 -> V_46 ) ,
0 , 0 , & V_51 ) ;
V_52 = F_18 ( V_34 , false ) ;
if ( ! V_52 ) {
F_19 ( V_34 -> V_53 . V_54 ,
& V_51 -> V_55 ) ;
F_20 ( & V_51 -> V_55 ) ;
V_51 = NULL ;
F_21 ( V_34 ) ;
F_22 ( V_34 , false ) ;
}
}
if ( V_20 -> V_22 -> V_37 != V_23 -> V_37 ) {
F_14 ( L_2 , V_35 ,
V_20 -> V_22 -> V_47 ,
V_20 -> V_22 -> V_48 ,
V_20 -> V_22 -> V_37 ? V_20 -> V_22 -> V_37 -> V_56 : 0 ,
V_20 -> V_22 -> V_37 ? V_20 -> V_22 -> V_37 -> V_57 : 0 ) ;
V_30 -> V_58 . V_59 . type =
F_13 ( V_60 ) ;
V_30 -> V_58 . V_61 = F_13 ( V_35 ) ;
if ( V_20 -> V_22 -> V_37 ) {
V_30 -> V_58 . V_56 =
F_13 ( V_20 -> V_22 -> V_37 -> V_56 ) ;
V_30 -> V_58 . V_57 =
F_13 ( V_20 -> V_22 -> V_37 -> V_57 ) ;
} else {
V_30 -> V_58 . V_56 = F_13 ( 0 ) ;
V_30 -> V_58 . V_57 = F_13 ( 0 ) ;
}
} else {
F_14 ( L_3 ,
V_20 -> V_22 -> V_47 ,
V_20 -> V_22 -> V_48 ) ;
V_30 -> V_58 . V_59 . type =
F_13 ( V_62 ) ;
}
V_30 -> V_58 . V_63 . V_64 = F_13 ( V_20 -> V_22 -> V_47 ) ;
V_30 -> V_58 . V_63 . V_65 = F_13 ( V_20 -> V_22 -> V_48 ) ;
F_23 ( V_27 , V_30 ) ;
}
struct V_19 * F_24 ( struct V_26 * V_27 ,
enum V_66 type ,
int V_49 )
{
struct V_24 * V_25 = V_27 -> V_67 ;
const struct V_68 * V_69 ;
struct V_19 * V_20 ;
const T_1 * V_70 ;
int V_52 , V_71 ;
V_20 = F_25 ( sizeof( * V_20 ) , V_72 ) ;
if ( ! V_20 )
return F_26 ( - V_73 ) ;
if ( type == V_74 ) {
V_70 = V_75 ;
V_71 = F_27 ( V_75 ) ;
V_69 = & V_76 ;
} else {
V_70 = V_77 ;
V_71 = F_27 ( V_77 ) ;
V_69 = & V_78 ;
}
V_52 = F_28 ( V_25 , V_20 , 1 << V_49 ,
& V_79 ,
V_70 , V_71 ,
type , NULL ) ;
if ( V_52 )
goto V_80;
F_29 ( V_20 , V_69 ) ;
return V_20 ;
V_80:
F_6 ( V_20 ) ;
return F_26 ( V_52 ) ;
}
