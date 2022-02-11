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
V_13 = V_20 ;
* V_5 = V_10 ;
break;
case V_21 :
V_9 -> V_16 . V_22 . V_23 = V_24 ;
V_9 -> V_16 . V_22 . V_25 . V_26 = 0 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
if ( V_13 < 0 )
break;
for ( V_12 = V_27 ; V_12 < V_28 ; V_12 ++ )
V_9 -> V_16 . V_29 [ V_12 ] =
V_9 -> V_16 . V_30 -> V_25 . V_31 [ V_12 ] ;
V_13 = V_20 ;
* V_5 = V_9 -> V_16 . V_29 [ V_14 ] ;
break;
case V_32 :
V_9 -> V_16 . V_22 . V_23 = V_33 ;
V_9 -> V_16 . V_22 . V_34 . V_10 = V_35 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
if ( V_13 < 0 )
break;
V_11 = V_9 -> V_16 . V_30 -> V_34 . V_13 ;
switch ( V_9 -> V_16 . type ) {
case V_36 :
* V_5 = F_5 ( V_11 * 980665 , 10 ) ;
* V_6 = 10000 << ( V_37 - 1 ) ;
V_13 = V_38 ;
break;
case V_39 :
* V_5 = F_5 ( V_11 * 314159 + 9000000ULL , 1000 ) ;
* V_6 = 18000 << ( V_37 - 1 ) ;
V_13 = V_38 ;
break;
case V_40 :
* V_5 = V_11 ;
* V_6 = 100 << ( V_37 - 1 ) ;
V_13 = V_38 ;
break;
default:
V_13 = - V_41 ;
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
case V_21 :
V_9 -> V_16 . V_29 [ V_14 ] = V_5 ;
V_9 -> V_16 . V_22 . V_23 = V_24 ;
V_9 -> V_16 . V_22 . V_25 . V_26 =
V_42 ;
for ( V_12 = V_27 ; V_12 < V_28 ; V_12 ++ )
V_9 -> V_16 . V_22 . V_25 . V_31 [ V_12 ] =
V_9 -> V_16 . V_29 [ V_12 ] ;
V_9 -> V_16 . V_22 . V_25 . V_43 =
V_44 ;
V_13 = F_4 ( & V_9 -> V_16 , 0 ) ;
break;
case V_32 :
if ( V_9 -> V_16 . type == V_40 ) {
V_13 = - V_41 ;
break;
}
V_9 -> V_16 . V_22 . V_23 = V_33 ;
V_9 -> V_16 . V_22 . V_34 . V_10 = V_5 ;
V_9 -> V_16 . V_22 . V_34 . V_45 = 1 ;
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
static int F_10 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_47 -> V_49 ;
struct V_50 * V_51 = F_11 ( V_49 -> V_52 ) ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_8 * V_55 ;
struct V_3 * V_56 ;
int V_13 , V_12 ;
if ( ! V_51 || ! V_51 -> V_51 ) {
F_12 ( & V_47 -> V_49 , L_1 ) ;
return - V_41 ;
}
V_54 = V_51 -> V_51 ;
V_2 = F_13 ( & V_47 -> V_49 , sizeof( * V_55 ) ) ;
if ( ! V_2 )
return - V_57 ;
V_13 = F_14 ( V_47 , V_2 , true ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_58 = & V_59 ;
V_55 = F_2 ( V_2 ) ;
for ( V_56 = V_55 -> V_60 , V_12 = V_27 ;
V_12 < V_28 ; V_12 ++ , V_56 ++ ) {
V_56 -> V_61 =
F_15 ( V_18 ) |
F_15 ( V_21 ) ;
V_56 -> V_62 =
F_15 ( V_32 ) |
F_15 ( V_63 ) |
F_15 ( V_64 ) ;
V_56 -> V_65 . V_66 = V_37 ;
V_56 -> V_65 . V_67 = V_37 ;
V_56 -> V_15 = V_12 ;
V_56 -> V_68 = V_69 ;
V_56 -> V_70 = 1 ;
V_56 -> V_71 = V_72 + V_12 ;
V_56 -> V_65 . V_73 = 's' ;
switch ( V_55 -> V_16 . type ) {
case V_36 :
V_56 -> type = V_74 ;
break;
case V_39 :
V_56 -> type = V_75 ;
break;
case V_40 :
V_56 -> type = V_76 ;
break;
default:
F_16 ( & V_47 -> V_49 , L_2 ) ;
return - V_41 ;
}
}
V_56 -> type = V_77 ;
V_56 -> V_56 = - 1 ;
V_56 -> V_15 = V_28 ;
V_56 -> V_65 . V_73 = 's' ;
V_56 -> V_65 . V_66 = 64 ;
V_56 -> V_65 . V_67 = 64 ;
V_2 -> V_60 = V_55 -> V_60 ;
V_2 -> V_78 = V_79 ;
if ( ( V_55 -> V_16 . V_80 -> V_81 != NULL ) &&
( V_55 -> V_16 . type != V_40 ) )
V_55 -> V_16 . V_19 = V_82 ;
else
V_55 -> V_16 . V_19 = V_83 ;
V_13 = F_17 ( V_2 , NULL ,
V_84 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_18 ( V_2 ) ;
if ( V_13 )
goto V_85;
return 0 ;
V_85:
F_19 ( V_2 ) ;
return V_13 ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
