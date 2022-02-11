int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
const T_1 * V_7 = NULL ;
int V_8 , V_9 ;
F_2 () ;
F_3 ( V_4 ) ;
if ( ! F_4 ( V_4 -> V_10 ) )
return 0 ;
V_4 -> V_11 . V_12 . V_13 = V_4 -> V_11 . V_13 ;
V_4 -> V_11 . V_12 . V_14 = V_4 -> V_11 . V_14 ;
V_4 -> V_11 . V_12 . V_15 = - 1 ;
if ( V_4 -> V_11 . V_16 ) {
V_4 -> V_11 . V_16 -> V_17 = V_4 -> V_11 . V_18 ;
if ( V_4 -> V_11 . V_18 != - 1 )
V_4 -> V_11 . V_12 . V_19 = true ;
}
if ( ! V_4 -> V_11 . V_12 . V_20 )
return 0 ;
if ( V_4 -> V_11 . V_16 && V_4 -> V_11 . V_16 -> V_17 != - 1 ) {
V_6 = F_5 ( V_4 -> V_11 . V_16 , sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ )
V_6 -> V_24 [ V_9 ] . V_25 = V_6 -> V_26 [ V_9 ] ;
}
if ( V_4 -> V_11 . V_27 )
V_7 = V_4 -> V_11 . V_7 ;
V_8 = F_6 ( V_2 , V_4 -> V_10 ,
& V_4 -> V_11 . V_12 , V_6 , V_7 ) ;
if ( V_8 )
F_7 ( V_6 ) ;
return V_8 ;
}
int F_8 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
struct V_37 * V_38 = NULL ;
int V_8 , V_39 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_39 = F_11 ( V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 ) {
V_38 = F_12 ( V_4 -> V_36 , V_39 ) ;
if ( ! V_38 )
return - V_42 ;
if ( V_38 -> V_43 & V_44 )
return - V_42 ;
}
F_13 ( V_4 ) ;
if ( V_4 -> V_45 ) {
bool V_46 = true ;
if ( V_4 -> V_11 . V_12 . V_47 == V_38 ) {
V_8 = 0 ;
goto V_48;
}
if ( V_4 -> V_11 . V_12 . V_20 )
V_46 = false ;
V_8 = F_14 ( V_2 , V_29 ,
V_49 , V_46 ) ;
if ( V_8 )
goto V_48;
}
V_4 -> V_11 . V_12 . V_47 = V_38 ;
if ( V_38 && ! V_4 -> V_11 . V_12 . V_20 ) {
struct V_50 V_51 = {
. V_52 = V_53 ,
. V_54 = V_39 ,
} ;
V_51 . V_38 = F_12 ( & V_2 -> V_36 , V_39 ) ;
if ( V_51 . V_38 )
V_8 = F_15 ( V_2 , & V_51 ) ;
else
V_8 = - V_42 ;
goto V_48;
}
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_39 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_37 * V_38 = NULL ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_55 )
V_38 = V_4 -> V_55 -> V_56 . V_47 ;
else if ( V_4 -> V_11 . V_12 . V_47 )
V_38 = V_4 -> V_11 . V_12 . V_47 ;
F_16 ( V_4 ) ;
if ( V_38 ) {
V_39 -> V_57 = V_38 -> V_58 ;
V_39 -> V_59 = 6 ;
return 0 ;
}
return - V_42 ;
}
int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_60 * V_26 , char * V_61 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_2 V_62 = V_26 -> V_63 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( ! V_26 -> V_43 )
V_62 = 0 ;
if ( V_62 > 0 && V_61 [ V_62 - 1 ] == '\0' )
V_62 -- ;
F_13 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_45 ) {
bool V_46 = true ;
if ( V_4 -> V_11 . V_12 . V_61 && V_62 &&
V_62 == V_4 -> V_11 . V_12 . V_20 &&
memcmp ( V_4 -> V_11 . V_12 . V_61 , V_61 , V_62 ) == 0 )
goto V_48;
if ( V_62 )
V_46 = false ;
V_8 = F_14 ( V_2 , V_29 ,
V_49 , V_46 ) ;
if ( V_8 )
goto V_48;
}
V_4 -> V_11 . V_27 = false ;
V_4 -> V_11 . V_12 . V_61 = V_4 -> V_11 . V_61 ;
memcpy ( V_4 -> V_11 . V_61 , V_61 , V_62 ) ;
V_4 -> V_11 . V_12 . V_20 = V_62 ;
V_4 -> V_11 . V_12 . V_64 . V_65 = false ;
V_4 -> V_11 . V_12 . V_64 . V_66 =
F_19 ( V_67 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_60 * V_26 , char * V_61 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_26 -> V_43 = 0 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_55 ) {
const T_1 * V_13 ;
F_21 () ;
V_13 = F_22 ( & V_4 -> V_55 -> V_56 ,
V_68 ) ;
if ( V_13 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_63 = V_13 [ 1 ] ;
memcpy ( V_61 , V_13 + 2 , V_26 -> V_63 ) ;
}
F_23 () ;
} else if ( V_4 -> V_11 . V_12 . V_61 && V_4 -> V_11 . V_12 . V_20 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_63 = V_4 -> V_11 . V_12 . V_20 ;
memcpy ( V_61 , V_4 -> V_11 . V_12 . V_61 , V_26 -> V_63 ) ;
}
F_16 ( V_4 ) ;
return 0 ;
}
int F_24 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_69 * V_70 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_71 = V_70 -> V_72 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( V_70 -> V_73 != V_74 )
return - V_42 ;
if ( F_25 ( V_71 ) || F_26 ( V_71 ) )
V_71 = NULL ;
F_13 ( V_4 ) ;
if ( V_4 -> V_45 ) {
V_8 = 0 ;
if ( ! V_71 && ! V_4 -> V_11 . V_12 . V_71 )
goto V_48;
if ( V_4 -> V_11 . V_12 . V_71 && V_71 &&
F_27 ( V_71 , V_4 -> V_11 . V_12 . V_71 ) )
goto V_48;
V_8 = F_14 ( V_2 , V_29 ,
V_49 , false ) ;
if ( V_8 )
goto V_48;
}
if ( V_71 ) {
memcpy ( V_4 -> V_11 . V_71 , V_71 , V_75 ) ;
V_4 -> V_11 . V_12 . V_71 = V_4 -> V_11 . V_71 ;
} else
V_4 -> V_11 . V_12 . V_71 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_28 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_69 * V_70 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_70 -> V_73 = V_74 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_55 )
memcpy ( V_70 -> V_72 , V_4 -> V_55 -> V_56 . V_71 , V_75 ) ;
else
F_29 ( V_70 -> V_72 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
int F_30 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_60 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_13 = V_34 ;
int V_14 = V_26 -> V_63 , V_8 ;
if ( V_4 -> V_40 != V_41 )
return - V_76 ;
if ( ! V_14 )
V_13 = NULL ;
F_13 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_11 . V_14 == V_14 &&
memcmp ( V_4 -> V_11 . V_13 , V_13 , V_14 ) == 0 )
goto V_48;
if ( V_14 ) {
V_13 = F_5 ( V_34 , V_14 , V_21 ) ;
if ( ! V_13 ) {
V_8 = - V_22 ;
goto V_48;
}
} else
V_13 = NULL ;
F_31 ( V_4 -> V_11 . V_13 ) ;
V_4 -> V_11 . V_13 = V_13 ;
V_4 -> V_11 . V_14 = V_14 ;
if ( V_4 -> V_45 ) {
V_8 = F_14 ( V_2 , V_29 ,
V_49 , false ) ;
if ( V_8 )
goto V_48;
}
V_8 = 0 ;
V_48:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_32 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_60 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_77 * V_78 = (struct V_77 * ) V_34 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_76 ;
V_2 = F_9 ( V_4 -> V_36 ) ;
if ( V_4 -> V_40 != V_41 )
return - V_42 ;
if ( V_78 -> V_79 . V_73 != V_74 )
return - V_42 ;
F_13 ( V_4 ) ;
switch ( V_78 -> V_80 ) {
case V_81 :
case V_82 :
V_8 = F_14 ( V_2 , V_29 , V_78 -> V_83 , true ) ;
break;
default:
V_8 = - V_76 ;
break;
}
F_16 ( V_4 ) ;
return V_8 ;
}
