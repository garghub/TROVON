static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
int V_11 = V_12 ;
int V_13 = V_4 -> V_14 ;
F_3 ( & V_9 -> V_15 . V_16 ) ;
switch ( V_7 ) {
case V_17 :
if ( F_4 ( V_2 , 1 << V_13 ,
( V_18 * ) & V_10 ) < 0 )
V_11 = - V_19 ;
* V_5 = V_10 ;
break;
case V_20 :
V_9 -> V_15 . V_21 . V_22 = V_23 ;
V_9 -> V_15 . V_21 . V_24 . V_10 = V_25 ;
if ( F_5 ( & V_9 -> V_15 , 0 ) ) {
V_11 = - V_19 ;
break;
}
* V_5 = V_9 -> V_15 . V_26 -> V_24 . V_11 ;
* V_6 = 10 << V_27 ;
V_11 = V_28 ;
break;
default:
V_11 = F_6 ( & V_9 -> V_15 , V_4 , V_5 , V_6 ,
V_7 ) ;
break;
}
F_7 ( & V_9 -> V_15 . V_16 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_11 = 0 ;
F_3 ( & V_9 -> V_15 . V_16 ) ;
switch ( V_7 ) {
case V_20 :
V_9 -> V_15 . V_21 . V_22 = V_23 ;
V_9 -> V_15 . V_21 . V_24 . V_10 = V_5 ;
V_9 -> V_15 . V_21 . V_24 . V_29 = 1 ;
if ( F_5 ( & V_9 -> V_15 , 0 ) )
V_11 = - V_19 ;
break;
default:
V_11 = F_9 ( & V_9 -> V_15 , V_4 , V_5 , V_6 ,
V_7 ) ;
break;
}
F_7 ( & V_9 -> V_15 . V_16 ) ;
return V_11 ;
}
static int F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_34 * V_35 = F_11 ( V_33 -> V_36 ) ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
struct V_8 * V_39 ;
struct V_3 * V_40 ;
int V_11 ;
if ( ! V_35 || ! V_35 -> V_35 ) {
F_12 ( V_33 , L_1 ) ;
return - V_41 ;
}
V_38 = V_35 -> V_35 ;
V_2 = F_13 ( V_33 , sizeof( * V_39 ) ) ;
if ( ! V_2 )
return - V_42 ;
V_11 = F_14 ( V_31 , V_2 , true ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_43 = & V_44 ;
V_39 = F_2 ( V_2 ) ;
V_39 -> V_15 . type = V_39 -> V_15 . V_26 -> V_43 . type ;
V_39 -> V_15 . V_45 = V_39 -> V_15 . V_26 -> V_43 . V_46 ;
V_40 = V_39 -> V_47 ;
V_40 -> V_48 = F_15 ( V_17 ) ;
V_40 -> V_49 =
F_15 ( V_20 ) |
F_15 ( V_50 ) |
F_15 ( V_51 ) ;
V_40 -> V_52 . V_53 = V_27 ;
V_40 -> V_52 . V_54 = V_27 ;
V_40 -> V_52 . V_55 = 0 ;
V_40 -> V_14 = 0 ;
V_40 -> V_56 = V_57 ;
V_40 -> V_52 . V_58 = 'u' ;
V_39 -> V_15 . V_59 [ 0 ] = 0 ;
switch ( V_39 -> V_15 . type ) {
case V_60 :
V_40 -> type = V_61 ;
break;
default:
F_12 ( V_33 , L_2 ) ;
return - V_41 ;
}
V_40 ++ ;
V_40 -> type = V_62 ;
V_40 -> V_40 = - 1 ;
V_40 -> V_14 = 1 ;
V_40 -> V_52 . V_58 = 's' ;
V_40 -> V_52 . V_53 = 64 ;
V_40 -> V_52 . V_54 = 64 ;
V_2 -> V_47 = V_39 -> V_47 ;
V_2 -> V_63 = V_64 ;
V_39 -> V_15 . V_65 = F_4 ;
V_11 = F_16 ( V_33 , V_2 , NULL ,
V_66 , NULL ) ;
if ( V_11 )
return V_11 ;
return F_17 ( V_33 , V_2 ) ;
}
