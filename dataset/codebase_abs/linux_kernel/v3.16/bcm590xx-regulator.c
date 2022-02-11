static int F_1 ( int V_1 )
{
if ( F_2 ( V_1 ) )
return V_2 + V_1 ;
else if ( F_3 ( V_1 ) )
return V_3 + V_1 ;
else
return V_4 + ( V_1 - V_5 ) * 3 ;
}
static int F_4 ( int V_1 )
{
int V_6 = 0 ;
if ( F_2 ( V_1 ) )
V_6 = V_7 + V_1 * 2 ;
else if ( F_3 ( V_1 ) )
V_6 = V_8 + V_1 * 2 ;
else
switch ( V_1 ) {
case V_5 :
V_6 = V_9 ;
break;
case V_10 :
V_6 = V_11 ;
break;
case V_12 :
V_6 = V_13 ;
break;
case V_14 :
V_6 = V_15 ;
break;
case V_16 :
V_6 = V_17 ;
break;
case V_18 :
V_6 = V_19 ;
break;
case V_20 :
V_6 = V_21 ;
} ;
return V_6 ;
}
static struct V_22 * F_5 (
struct V_23 * V_24 ,
struct V_25 * * V_26 )
{
struct V_22 * V_27 ;
struct V_28 * V_29 = V_24 -> V_30 . V_31 -> V_32 ;
struct V_28 * V_33 ;
struct V_25 * V_34 = V_35 ;
int V_36 = F_6 ( V_35 ) ;
int V_37 = 0 ;
int V_38 ;
if ( ! V_29 ) {
F_7 ( & V_24 -> V_30 , L_1 ) ;
return NULL ;
}
V_27 = F_8 ( & V_24 -> V_30 , sizeof( * V_27 ) , V_39 ) ;
if ( ! V_27 ) {
F_7 ( & V_24 -> V_30 , L_2 ) ;
return NULL ;
}
V_29 = F_9 ( V_29 ) ;
V_33 = F_10 ( V_29 , L_3 ) ;
if ( ! V_33 ) {
F_11 ( & V_24 -> V_30 , L_4 ) ;
return NULL ;
}
V_38 = V_25 ( & V_24 -> V_30 , V_33 , V_34 , V_36 ) ;
F_12 ( V_33 ) ;
if ( V_38 < 0 ) {
F_7 ( & V_24 -> V_30 , L_5 ,
V_38 ) ;
return NULL ;
}
* V_26 = V_34 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( ! V_34 [ V_37 ] . V_40 || ! V_34 [ V_37 ] . V_32 )
continue;
V_27 -> V_41 [ V_37 ] = V_34 [ V_37 ] . V_40 ;
}
return V_27 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_42 * V_42 = F_14 ( V_24 -> V_30 . V_31 ) ;
struct V_22 * V_43 = NULL ;
struct V_44 * V_45 ;
struct V_46 V_47 = { } ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_25 * V_26 = NULL ;
int V_54 ;
V_43 = F_5 ( V_24 ,
& V_26 ) ;
V_45 = F_8 ( & V_24 -> V_30 , sizeof( * V_45 ) , V_39 ) ;
if ( ! V_45 ) {
F_7 ( & V_24 -> V_30 , L_6 ) ;
return - V_55 ;
}
V_45 -> V_56 = V_42 ;
F_15 ( V_24 , V_45 ) ;
V_45 -> V_57 = F_8 ( & V_24 -> V_30 , V_58 *
sizeof( struct V_59 ) , V_39 ) ;
if ( ! V_45 -> V_57 ) {
F_7 ( & V_24 -> V_30 , L_7 ) ;
return - V_55 ;
}
V_45 -> V_49 = F_8 ( & V_24 -> V_30 , V_58 *
sizeof( struct V_48 * ) , V_39 ) ;
if ( ! V_45 -> V_49 ) {
F_7 ( & V_24 -> V_30 , L_8 ) ;
return - V_55 ;
}
V_49 = V_60 ;
for ( V_54 = 0 ; V_54 < V_58 ; V_54 ++ , V_49 ++ ) {
if ( V_43 )
V_51 = V_43 -> V_41 [ V_54 ] ;
else
V_51 = NULL ;
V_45 -> V_49 [ V_54 ] = V_49 ;
V_45 -> V_57 [ V_54 ] . V_61 = V_49 -> V_61 ;
V_45 -> V_57 [ V_54 ] . V_62 = V_49 -> V_63 ;
V_45 -> V_57 [ V_54 ] . V_1 = V_54 ;
V_45 -> V_57 [ V_54 ] . V_64 = V_49 -> V_64 ;
V_45 -> V_57 [ V_54 ] . V_65 = V_49 -> V_65 ;
V_45 -> V_57 [ V_54 ] . V_66 = V_49 -> V_66 ;
V_45 -> V_57 [ V_54 ] . V_67 = V_49 -> V_67 ;
if ( ( F_2 ( V_54 ) ) || ( F_3 ( V_54 ) ) ) {
V_45 -> V_57 [ V_54 ] . V_68 = & V_69 ;
V_45 -> V_57 [ V_54 ] . V_70 = V_71 ;
} else if ( F_16 ( V_54 ) )
V_45 -> V_57 [ V_54 ] . V_68 = & V_72 ;
else {
V_45 -> V_57 [ V_54 ] . V_68 = & V_73 ;
V_45 -> V_57 [ V_54 ] . V_70 = V_74 ;
}
if ( F_16 ( V_54 ) )
V_45 -> V_57 [ V_54 ] . V_75 = V_76 ;
else {
V_45 -> V_57 [ V_54 ] . V_77 = F_1 ( V_54 ) ;
V_45 -> V_57 [ V_54 ] . V_78 = true ;
V_45 -> V_57 [ V_54 ] . V_75 = V_79 ;
}
V_45 -> V_57 [ V_54 ] . V_80 = F_4 ( V_54 ) ;
V_45 -> V_57 [ V_54 ] . type = V_81 ;
V_45 -> V_57 [ V_54 ] . V_82 = V_83 ;
V_47 . V_30 = V_42 -> V_30 ;
V_47 . V_40 = V_51 ;
V_47 . V_84 = V_45 ;
if ( F_3 ( V_54 ) || F_16 ( V_54 ) )
V_47 . V_85 = V_42 -> V_86 ;
else
V_47 . V_85 = V_42 -> V_87 ;
if ( V_26 )
V_47 . V_32 = V_26 [ V_54 ] . V_32 ;
V_53 = F_17 ( & V_24 -> V_30 , & V_45 -> V_57 [ V_54 ] ,
& V_47 ) ;
if ( F_18 ( V_53 ) ) {
F_7 ( V_42 -> V_30 ,
L_9 ,
V_24 -> V_61 ) ;
return F_19 ( V_53 ) ;
}
}
return 0 ;
}
