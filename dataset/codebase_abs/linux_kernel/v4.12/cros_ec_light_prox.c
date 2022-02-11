static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
T_2 V_11 ;
int V_12 = V_13 ;
int V_14 = V_4 -> V_15 ;
F_3 ( & V_9 -> V_16 . V_17 ) ;
switch ( V_7 ) {
case V_18 :
if ( V_4 -> type == V_19 ) {
if ( F_4 ( V_2 , 1 << V_14 ,
( V_20 * ) & V_10 ) < 0 ) {
V_12 = - V_21 ;
break;
}
* V_5 = V_10 ;
} else {
V_12 = - V_22 ;
}
break;
case V_23 :
if ( V_4 -> type == V_24 ) {
if ( F_4 ( V_2 , 1 << V_14 ,
( V_20 * ) & V_10 ) < 0 ) {
V_12 = - V_21 ;
break;
}
* V_5 = V_10 ;
V_12 = V_13 ;
} else {
V_12 = - V_22 ;
}
break;
case V_25 :
V_9 -> V_16 . V_26 . V_27 = V_28 ;
V_9 -> V_16 . V_26 . V_29 . V_30 = 0 ;
if ( F_5 ( & V_9 -> V_16 , 0 ) ) {
V_12 = - V_21 ;
break;
}
V_9 -> V_16 . V_31 [ 0 ] = V_9 -> V_16 . V_32 -> V_29 . V_33 [ 0 ] ;
* V_5 = V_9 -> V_16 . V_31 [ V_14 ] ;
break;
case V_34 :
V_9 -> V_16 . V_26 . V_27 = V_35 ;
V_9 -> V_16 . V_26 . V_36 . V_10 = V_37 ;
if ( F_5 ( & V_9 -> V_16 , 0 ) ) {
V_12 = - V_21 ;
break;
}
V_11 = V_9 -> V_16 . V_32 -> V_36 . V_12 ;
* V_5 = V_11 >> 16 ;
* V_6 = ( V_11 & 0xffff ) * 100 ;
V_12 = V_38 ;
break;
default:
V_12 = F_6 ( & V_9 -> V_16 , V_4 , V_5 , V_6 ,
V_7 ) ;
break;
}
F_7 ( & V_9 -> V_16 . V_17 ) ;
return V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_14 = V_4 -> V_15 ;
F_3 ( & V_9 -> V_16 . V_17 ) ;
switch ( V_7 ) {
case V_25 :
V_9 -> V_16 . V_31 [ V_14 ] = V_5 ;
V_9 -> V_16 . V_26 . V_27 = V_28 ;
V_9 -> V_16 . V_26 . V_29 . V_30 = V_39 ;
V_9 -> V_16 . V_26 . V_29 . V_33 [ 0 ] = V_9 -> V_16 . V_31 [ 0 ] ;
V_9 -> V_16 . V_26 . V_29 . V_40 =
V_41 ;
if ( F_5 ( & V_9 -> V_16 , 0 ) )
V_12 = - V_21 ;
break;
case V_34 :
V_9 -> V_16 . V_26 . V_27 = V_35 ;
V_9 -> V_16 . V_26 . V_36 . V_10 = ( V_5 << 16 ) | ( V_6 / 100 ) ;
if ( F_5 ( & V_9 -> V_16 , 0 ) )
V_12 = - V_21 ;
break;
default:
V_12 = F_9 ( & V_9 -> V_16 , V_4 , V_5 , V_6 ,
V_7 ) ;
break;
}
F_7 ( & V_9 -> V_16 . V_17 ) ;
return V_12 ;
}
static int F_10 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = & V_43 -> V_45 ;
struct V_46 * V_47 = F_11 ( V_45 -> V_48 ) ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_8 * V_51 ;
struct V_3 * V_52 ;
int V_12 ;
if ( ! V_47 || ! V_47 -> V_47 ) {
F_12 ( V_45 , L_1 ) ;
return - V_22 ;
}
V_50 = V_47 -> V_47 ;
V_2 = F_13 ( V_45 , sizeof( * V_51 ) ) ;
if ( ! V_2 )
return - V_53 ;
V_12 = F_14 ( V_43 , V_2 , true ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_54 = & V_55 ;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_16 . type = V_51 -> V_16 . V_32 -> V_54 . type ;
V_51 -> V_16 . V_56 = V_51 -> V_16 . V_32 -> V_54 . V_57 ;
V_52 = V_51 -> V_58 ;
V_52 -> V_59 =
F_15 ( V_60 ) |
F_15 ( V_61 ) ;
V_52 -> V_62 . V_63 = V_64 ;
V_52 -> V_62 . V_65 = V_64 ;
V_52 -> V_62 . V_66 = 0 ;
V_52 -> V_15 = 0 ;
V_52 -> V_67 = V_68 ;
V_52 -> V_62 . V_69 = 'u' ;
V_51 -> V_16 . V_31 [ 0 ] = 0 ;
switch ( V_51 -> V_16 . type ) {
case V_70 :
V_52 -> type = V_24 ;
V_52 -> V_71 =
F_15 ( V_23 ) |
F_15 ( V_25 ) |
F_15 ( V_34 ) ;
break;
case V_72 :
V_52 -> type = V_19 ;
V_52 -> V_71 =
F_15 ( V_18 ) |
F_15 ( V_25 ) |
F_15 ( V_34 ) ;
break;
default:
F_12 ( V_45 , L_2 ) ;
return - V_22 ;
}
V_52 ++ ;
V_52 -> type = V_73 ;
V_52 -> V_52 = - 1 ;
V_52 -> V_15 = 1 ;
V_52 -> V_62 . V_69 = 's' ;
V_52 -> V_62 . V_63 = 64 ;
V_52 -> V_62 . V_65 = 64 ;
V_2 -> V_58 = V_51 -> V_58 ;
V_2 -> V_74 = V_75 ;
V_51 -> V_16 . V_76 = F_4 ;
V_12 = F_16 ( V_45 , V_2 , NULL ,
V_77 , NULL ) ;
if ( V_12 )
return V_12 ;
return F_17 ( V_45 , V_2 ) ;
}
