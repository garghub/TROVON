static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
struct V_6 V_7 = {
. V_8 = V_9 ,
} ;
struct V_6 V_10 = {
. V_8 = V_11 ,
} ;
F_3 ( V_4 -> V_12 , & V_7 ) ;
if ( V_7 . V_13 < 4 )
F_4 ( L_1 ) ;
V_4 -> V_14 = V_7 . V_15 [ 0 ] ;
V_4 -> V_16 = V_7 . V_15 [ 1 ] ;
V_4 -> V_17 = ( ( ( ( unsigned short ) V_7 . V_15 [ 3 ] << 8 ) +
V_7 . V_15 [ 2 ] ) * 5000L ) * 1000 / 1024 ;
V_4 -> V_18 = V_7 . V_15 [ 4 ] ;
if ( V_7 . V_13 == 9 )
F_5 ( L_2 ) ;
F_3 ( V_4 -> V_12 , & V_10 ) ;
V_4 -> V_19 = V_10 . V_15 [ 1 ] << 8 | V_10 . V_15 [ 0 ] ;
F_6 ( V_4 -> V_20 , & V_4 -> V_5 , F_7 ( V_21 ) ) ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_24 . V_25 ) ;
switch ( V_4 -> V_18 & 0x07 ) {
case V_26 :
return 100 ;
break;
case V_27 :
return 50 ;
break;
case V_28 :
return 5 ;
break;
default:
break;
}
return 0 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_24 . V_25 ) ;
if ( V_4 -> V_18 == V_29 )
return V_30 ;
if ( V_4 -> V_18 & V_31 )
return V_32 ;
if ( ( V_4 -> V_18 & V_33 ) ||
( V_4 -> V_18 & V_34 ) )
return V_35 ;
return V_36 ;
}
static int F_11 ( struct V_22 * V_23 ,
enum V_37 V_38 ,
union V_39 * V_40 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_24 . V_25 ) ;
switch ( V_38 ) {
case V_41 :
switch ( V_4 -> V_16 ) {
case V_42 :
V_40 -> V_43 = V_44 ;
break;
case V_45 :
V_40 -> V_43 = V_46 ;
break;
case V_47 :
V_40 -> V_43 = V_48 ;
break;
case V_49 :
V_40 -> V_43 = V_50 ;
break;
default:
V_40 -> V_43 = V_51 ;
break;
} ;
break;
case V_52 :
V_40 -> V_43 = F_10 ( V_23 ) ;
break;
case V_53 :
V_40 -> V_43 = 4700000 ;
break;
case V_54 :
V_40 -> V_43 = F_8 ( V_23 ) ;
break;
case V_55 :
V_40 -> V_43 = V_4 -> V_19 ;
break;
case V_56 :
V_40 -> V_43 = V_4 -> V_17 ;
break;
default:
return - V_57 ;
} ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 ,
enum V_37 V_38 ,
union V_39 * V_40 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_24 . V_25 ) ;
switch ( V_38 ) {
case V_58 :
V_40 -> V_43 = V_4 -> V_14 ;
break;
default:
return - V_57 ;
} ;
return 0 ;
}
static int F_13 ( struct V_59 * V_60 )
{
struct V_3 * V_4 ;
int V_61 ;
V_4 = F_14 ( & V_60 -> V_24 , sizeof( * V_4 ) , V_62 ) ;
if ( ! V_4 )
return - V_63 ;
V_4 -> V_12 = F_9 ( V_60 -> V_24 . V_25 ) ;
V_4 -> V_20 = F_15 ( L_3 ) ;
if ( ! V_4 -> V_20 )
return - V_63 ;
F_16 ( & V_4 -> V_5 , F_1 ) ;
F_17 ( V_60 , V_4 ) ;
F_6 ( V_4 -> V_20 , & V_4 -> V_5 , 1 ) ;
V_64 = F_18 ( & V_60 -> V_24 ,
& V_65 , NULL ) ;
if ( F_19 ( V_64 ) ) {
V_61 = F_20 ( V_64 ) ;
goto V_66;
}
V_67 = F_18 ( & V_60 -> V_24 ,
& V_68 , NULL ) ;
if ( F_19 ( V_67 ) ) {
V_61 = F_20 ( V_67 ) ;
goto V_69;
}
F_21 ( & V_60 -> V_24 , L_4 ) ;
return 0 ;
V_69:
F_22 ( V_67 ) ;
V_66:
F_23 ( & V_4 -> V_5 ) ;
F_24 ( V_4 -> V_20 ) ;
return V_61 ;
}
static int F_25 ( struct V_59 * V_60 )
{
struct V_3 * V_4 = F_26 ( V_60 ) ;
F_22 ( V_67 ) ;
F_22 ( V_64 ) ;
F_23 ( & V_4 -> V_5 ) ;
F_24 ( V_4 -> V_20 ) ;
return 0 ;
}
static int F_27 ( struct V_70 * V_24 )
{
struct V_3 * V_4 = F_9 ( V_24 ) ;
F_23 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_70 * V_24 )
{
struct V_3 * V_4 = F_9 ( V_24 ) ;
F_6 ( V_4 -> V_20 , & V_4 -> V_5 , F_7 ( V_21 ) ) ;
return 0 ;
}
