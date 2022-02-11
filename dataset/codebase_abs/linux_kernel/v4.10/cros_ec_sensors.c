static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
T_2 V_11 ;
int V_12 ;
int V_13 ;
int V_14 = V_4 -> V_15 ;
F_3 ( & V_9 -> V_16 . V_17 ) ;
switch ( V_7 ) {
case V_18 :
V_13 = V_9 -> V_16 . V_19 ( V_2 , 1 << V_14 , & V_10 ) ;
if ( V_13 < 0 )
break;
* V_5 = V_10 ;
break;
case V_20 :
V_9 -> V_16 . V_21 . V_22 = V_23 ;
V_9 -> V_16 . V_21 . V_24 . V_25 = 0 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
if ( V_13 < 0 )
break;
for ( V_12 = V_26 ; V_12 < V_27 ; V_12 ++ )
V_9 -> V_16 . V_28 [ V_12 ] =
V_9 -> V_16 . V_29 -> V_24 . V_30 [ V_12 ] ;
* V_5 = V_9 -> V_16 . V_28 [ V_14 ] ;
break;
case V_31 :
V_9 -> V_16 . V_21 . V_22 = V_32 ;
V_9 -> V_16 . V_21 . V_33 . V_10 = V_34 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
if ( V_13 < 0 )
break;
V_11 = V_9 -> V_16 . V_29 -> V_33 . V_13 ;
switch ( V_9 -> V_16 . type ) {
case V_35 :
* V_5 = F_5 ( V_11 * 980665 , 10 ) ;
* V_6 = 10000 << ( V_36 - 1 ) ;
V_13 = V_37 ;
break;
case V_38 :
* V_5 = F_5 ( V_11 * 314159 + 9000000ULL , 1000 ) ;
* V_6 = 18000 << ( V_36 - 1 ) ;
V_13 = V_37 ;
break;
case V_39 :
* V_5 = V_11 ;
* V_6 = 100 << ( V_36 - 1 ) ;
V_13 = V_37 ;
break;
default:
V_13 = - V_40 ;
}
break;
default:
V_13 = F_6 ( & V_9 -> V_16 , V_4 , V_5 , V_6 ,
V_7 ) ;
break;
}
F_7 ( & V_9 -> V_16 . V_17 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_12 ;
int V_13 ;
int V_14 = V_4 -> V_15 ;
F_3 ( & V_9 -> V_16 . V_17 ) ;
switch ( V_7 ) {
case V_20 :
V_9 -> V_16 . V_28 [ V_14 ] = V_5 ;
V_9 -> V_16 . V_21 . V_22 = V_23 ;
V_9 -> V_16 . V_21 . V_24 . V_25 =
V_41 ;
for ( V_12 = V_26 ; V_12 < V_27 ; V_12 ++ )
V_9 -> V_16 . V_21 . V_24 . V_30 [ V_12 ] =
V_9 -> V_16 . V_28 [ V_12 ] ;
V_9 -> V_16 . V_21 . V_24 . V_42 =
V_43 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
break;
case V_31 :
if ( V_9 -> V_16 . type == V_39 ) {
V_13 = - V_40 ;
break;
}
V_9 -> V_16 . V_21 . V_22 = V_32 ;
V_9 -> V_16 . V_21 . V_33 . V_10 = V_5 ;
V_9 -> V_16 . V_21 . V_33 . V_44 = 1 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
break;
default:
V_13 = F_9 (
& V_9 -> V_16 , V_4 , V_5 , V_6 , V_7 ) ;
break;
}
F_7 ( & V_9 -> V_16 . V_17 ) ;
return V_13 ;
}
static int F_10 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_46 -> V_48 ;
struct V_49 * V_50 = F_11 ( V_48 -> V_51 ) ;
struct V_52 * V_53 ;
struct V_1 * V_2 ;
struct V_8 * V_54 ;
struct V_3 * V_55 ;
int V_13 , V_12 ;
if ( ! V_50 || ! V_50 -> V_50 ) {
F_12 ( & V_46 -> V_48 , L_1 ) ;
return - V_40 ;
}
V_53 = V_50 -> V_50 ;
V_2 = F_13 ( & V_46 -> V_48 , sizeof( * V_54 ) ) ;
if ( ! V_2 )
return - V_56 ;
V_13 = F_14 ( V_46 , V_2 , true ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_57 = & V_58 ;
V_54 = F_2 ( V_2 ) ;
for ( V_55 = V_54 -> V_59 , V_12 = V_26 ;
V_12 < V_27 ; V_12 ++ , V_55 ++ ) {
V_55 -> V_60 =
F_15 ( V_18 ) |
F_15 ( V_20 ) ;
V_55 -> V_61 =
F_15 ( V_31 ) |
F_15 ( V_62 ) |
F_15 ( V_63 ) ;
V_55 -> V_64 . V_65 = V_36 ;
V_55 -> V_64 . V_66 = V_36 ;
V_55 -> V_15 = V_12 ;
V_55 -> V_67 = V_68 ;
V_55 -> V_69 = 1 ;
V_55 -> V_70 = V_71 + V_12 ;
V_55 -> V_64 . V_72 = 's' ;
switch ( V_54 -> V_16 . type ) {
case V_35 :
V_55 -> type = V_73 ;
break;
case V_38 :
V_55 -> type = V_74 ;
break;
case V_39 :
V_55 -> type = V_75 ;
break;
default:
F_16 ( & V_46 -> V_48 , L_2 ) ;
return - V_40 ;
}
}
V_55 -> type = V_76 ;
V_55 -> V_55 = - 1 ;
V_55 -> V_15 = V_27 ;
V_55 -> V_64 . V_72 = 's' ;
V_55 -> V_64 . V_65 = 64 ;
V_55 -> V_64 . V_66 = 64 ;
V_2 -> V_59 = V_54 -> V_59 ;
V_2 -> V_77 = V_78 ;
if ( ( V_54 -> V_16 . V_79 -> V_80 != NULL ) &&
( V_54 -> V_16 . type != V_39 ) )
V_54 -> V_16 . V_19 = V_81 ;
else
V_54 -> V_16 . V_19 = V_82 ;
V_13 = F_17 ( V_2 , NULL ,
V_83 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_18 ( V_2 ) ;
if ( V_13 )
goto V_84;
return 0 ;
V_84:
F_19 ( V_2 ) ;
return V_13 ;
}
static int F_20 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_21 ( V_46 ) ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
