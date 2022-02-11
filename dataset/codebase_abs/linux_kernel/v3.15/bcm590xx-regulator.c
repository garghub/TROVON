static int F_1 ( int V_1 )
{
if ( F_2 ( V_1 ) )
return V_2 + V_1 ;
else
return V_3 + ( V_1 - V_4 ) * 3 ;
}
static int F_3 ( int V_1 )
{
int V_5 = 0 ;
if ( F_2 ( V_1 ) )
V_5 = V_6 + V_1 * 2 ;
else
switch ( V_1 ) {
case V_4 :
V_5 = V_7 ;
break;
case V_8 :
V_5 = V_9 ;
break;
case V_10 :
V_5 = V_11 ;
break;
case V_12 :
V_5 = V_13 ;
break;
case V_14 :
V_5 = V_15 ;
break;
case V_16 :
V_5 = V_17 ;
break;
} ;
return V_5 ;
}
static struct V_18 * F_4 (
struct V_19 * V_20 ,
struct V_21 * * V_22 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 = V_20 -> V_26 . V_27 -> V_28 ;
struct V_24 * V_29 ;
struct V_21 * V_30 = V_31 ;
int V_32 = F_5 ( V_31 ) ;
int V_33 = 0 ;
int V_34 ;
if ( ! V_25 ) {
F_6 ( & V_20 -> V_26 , L_1 ) ;
return NULL ;
}
V_23 = F_7 ( & V_20 -> V_26 , sizeof( * V_23 ) , V_35 ) ;
if ( ! V_23 ) {
F_6 ( & V_20 -> V_26 , L_2 ) ;
return NULL ;
}
V_25 = F_8 ( V_25 ) ;
V_29 = F_9 ( V_25 , L_3 ) ;
if ( ! V_29 ) {
F_10 ( & V_20 -> V_26 , L_4 ) ;
return NULL ;
}
V_34 = V_21 ( & V_20 -> V_26 , V_29 , V_30 , V_32 ) ;
F_11 ( V_29 ) ;
if ( V_34 < 0 ) {
F_6 ( & V_20 -> V_26 , L_5 ,
V_34 ) ;
return NULL ;
}
* V_22 = V_30 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( ! V_30 [ V_33 ] . V_36 || ! V_30 [ V_33 ] . V_28 )
continue;
V_23 -> V_37 [ V_33 ] = V_30 [ V_33 ] . V_36 ;
}
return V_23 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_38 * V_38 = F_13 ( V_20 -> V_26 . V_27 ) ;
struct V_18 * V_39 = NULL ;
struct V_40 * V_41 ;
struct V_42 V_43 = { } ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_21 * V_22 = NULL ;
int V_50 ;
V_39 = F_4 ( V_20 ,
& V_22 ) ;
V_41 = F_7 ( & V_20 -> V_26 , sizeof( * V_41 ) , V_35 ) ;
if ( ! V_41 ) {
F_6 ( & V_20 -> V_26 , L_6 ) ;
return - V_51 ;
}
V_41 -> V_52 = V_38 ;
F_14 ( V_20 , V_41 ) ;
V_41 -> V_53 = F_7 ( & V_20 -> V_26 , V_54 *
sizeof( struct V_55 ) , V_35 ) ;
if ( ! V_41 -> V_53 ) {
F_6 ( & V_20 -> V_26 , L_7 ) ;
return - V_51 ;
}
V_41 -> V_45 = F_7 ( & V_20 -> V_26 , V_54 *
sizeof( struct V_44 * ) , V_35 ) ;
if ( ! V_41 -> V_45 ) {
F_6 ( & V_20 -> V_26 , L_8 ) ;
return - V_51 ;
}
V_45 = V_56 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ , V_45 ++ ) {
if ( V_39 )
V_47 = V_39 -> V_37 [ V_50 ] ;
else
V_47 = NULL ;
V_41 -> V_45 [ V_50 ] = V_45 ;
V_41 -> V_53 [ V_50 ] . V_57 = V_45 -> V_57 ;
V_41 -> V_53 [ V_50 ] . V_58 = V_45 -> V_59 ;
V_41 -> V_53 [ V_50 ] . V_1 = V_50 ;
V_41 -> V_53 [ V_50 ] . V_60 = V_45 -> V_60 ;
V_41 -> V_53 [ V_50 ] . V_61 = V_45 -> V_61 ;
V_41 -> V_53 [ V_50 ] . V_62 = V_45 -> V_62 ;
V_41 -> V_53 [ V_50 ] . V_63 = V_45 -> V_63 ;
if ( F_2 ( V_50 ) ) {
V_41 -> V_53 [ V_50 ] . V_64 = & V_65 ;
V_41 -> V_53 [ V_50 ] . V_66 = V_67 ;
} else {
V_41 -> V_53 [ V_50 ] . V_64 = & V_68 ;
V_41 -> V_53 [ V_50 ] . V_66 = V_69 ;
}
V_41 -> V_53 [ V_50 ] . V_70 = F_1 ( V_50 ) ;
V_41 -> V_53 [ V_50 ] . V_71 = true ;
V_41 -> V_53 [ V_50 ] . V_72 = V_73 ;
V_41 -> V_53 [ V_50 ] . V_74 = F_3 ( V_50 ) ;
V_41 -> V_53 [ V_50 ] . type = V_75 ;
V_41 -> V_53 [ V_50 ] . V_76 = V_77 ;
V_43 . V_26 = V_38 -> V_26 ;
V_43 . V_36 = V_47 ;
V_43 . V_78 = V_41 ;
V_43 . V_79 = V_38 -> V_79 ;
if ( V_22 )
V_43 . V_28 = V_22 [ V_50 ] . V_28 ;
V_49 = F_15 ( & V_20 -> V_26 , & V_41 -> V_53 [ V_50 ] ,
& V_43 ) ;
if ( F_16 ( V_49 ) ) {
F_6 ( V_38 -> V_26 ,
L_9 ,
V_20 -> V_57 ) ;
return F_17 ( V_49 ) ;
}
}
return 0 ;
}
