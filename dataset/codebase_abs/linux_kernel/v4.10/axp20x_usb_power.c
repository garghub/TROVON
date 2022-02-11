static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 , union V_11 * V_12 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
unsigned int V_13 , V_14 ;
int V_15 ;
switch ( V_10 ) {
case V_16 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_19 = F_6 ( V_14 ) ;
return 0 ;
case V_20 :
V_15 = F_7 ( V_4 -> V_17 ,
V_21 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 1700 ;
return 0 ;
case V_22 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
switch ( V_14 & V_23 ) {
case V_24 :
if ( F_8 ( V_4 -> V_25 ,
L_1 ) ) {
V_12 -> V_19 = 100000 ;
} else {
V_12 -> V_19 = - 1 ;
}
break;
case V_26 :
V_12 -> V_19 = 500000 ;
break;
case V_27 :
V_12 -> V_19 = 900000 ;
break;
case V_28 :
V_12 -> V_19 = - 1 ;
break;
}
return 0 ;
case V_29 :
V_15 = F_7 ( V_4 -> V_17 ,
V_30 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 375 ;
return 0 ;
default:
break;
}
V_15 = F_5 ( V_4 -> V_17 , V_31 , & V_13 ) ;
if ( V_15 )
return V_15 ;
switch ( V_10 ) {
case V_32 :
if ( ! ( V_13 & V_33 ) ) {
V_12 -> V_19 = V_34 ;
break;
}
V_12 -> V_19 = V_35 ;
if ( F_8 ( V_4 -> V_25 ,
L_1 ) ) {
V_15 = F_5 ( V_4 -> V_17 ,
V_36 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( ! ( V_14 & V_37 ) )
V_12 -> V_19 =
V_38 ;
}
break;
case V_39 :
V_12 -> V_19 = ! ! ( V_13 & V_33 ) ;
break;
case V_40 :
V_12 -> V_19 = ! ! ( V_13 & V_41 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_9 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_10 ( V_44 -> V_47 . V_48 ) ;
struct V_49 V_50 = {} ;
struct V_3 * V_4 ;
static const char * const V_51 [] = { L_2 ,
L_3 , L_4 , L_5 , NULL } ;
static const char * const V_52 [] = {
L_2 , L_3 , NULL } ;
static const char * const * V_53 ;
const struct V_54 * V_55 ;
int V_56 , V_1 , V_15 ;
if ( ! F_11 ( V_44 -> V_47 . V_57 ) )
return - V_58 ;
if ( ! V_46 ) {
F_12 ( & V_44 -> V_47 , L_6 ) ;
return - V_42 ;
}
V_4 = F_13 ( & V_44 -> V_47 , sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return - V_60 ;
V_4 -> V_25 = V_44 -> V_47 . V_57 ;
V_4 -> V_17 = V_46 -> V_17 ;
if ( F_8 ( V_4 -> V_25 ,
L_1 ) ) {
V_15 = F_14 ( V_4 -> V_17 , V_61 ,
V_62 ,
V_62 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_14 ( V_4 -> V_17 , V_63 ,
V_64 | V_65 ,
V_64 | V_65 ) ;
if ( V_15 )
return V_15 ;
V_55 = & V_66 ;
V_53 = V_51 ;
} else if ( F_8 ( V_4 -> V_25 ,
L_7 ) ) {
V_55 = & V_67 ;
V_53 = V_52 ;
} else {
F_12 ( & V_44 -> V_47 , L_8 ,
V_46 -> V_68 ) ;
return - V_42 ;
}
V_50 . V_57 = V_44 -> V_47 . V_57 ;
V_50 . V_69 = V_4 ;
V_4 -> V_5 = F_15 ( & V_44 -> V_47 , V_55 ,
& V_50 ) ;
if ( F_16 ( V_4 -> V_5 ) )
return F_17 ( V_4 -> V_5 ) ;
for ( V_56 = 0 ; V_53 [ V_56 ] ; V_56 ++ ) {
V_1 = F_18 ( V_44 , V_53 [ V_56 ] ) ;
if ( V_1 < 0 ) {
F_19 ( & V_44 -> V_47 , L_9 ,
V_53 [ V_56 ] , V_1 ) ;
continue;
}
V_1 = F_20 ( V_46 -> V_70 , V_1 ) ;
V_15 = F_21 ( & V_44 -> V_47 , V_1 ,
F_1 , 0 , V_71 , V_4 ) ;
if ( V_15 < 0 )
F_19 ( & V_44 -> V_47 , L_10 ,
V_53 [ V_56 ] , V_15 ) ;
}
return 0 ;
}
