int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
const T_1 * V_7 = NULL ;
int V_8 , V_9 ;
F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
if ( ! F_4 ( V_4 -> V_10 ) )
return 0 ;
V_4 -> V_11 . V_12 . V_13 = V_4 -> V_11 . V_13 ;
V_4 -> V_11 . V_12 . V_14 = V_4 -> V_11 . V_14 ;
V_4 -> V_11 . V_12 . V_15 = - 1 ;
if ( V_4 -> V_11 . V_16 ) {
V_4 -> V_11 . V_16 -> V_17 = V_4 -> V_11 . V_18 ;
V_4 -> V_11 . V_16 -> V_19 = V_4 -> V_11 . V_20 ;
if ( V_4 -> V_11 . V_18 != - 1 )
V_4 -> V_11 . V_12 . V_21 = true ;
}
if ( ! V_4 -> V_11 . V_12 . V_22 )
return 0 ;
if ( V_4 -> V_11 . V_16 ) {
V_6 = F_5 ( V_4 -> V_11 . V_16 , sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
return - V_24 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
V_6 -> V_25 [ V_9 ] . V_26 = V_6 -> V_27 [ V_9 ] ;
}
if ( V_4 -> V_11 . V_28 )
V_7 = V_4 -> V_11 . V_7 ;
V_8 = F_6 ( V_2 , V_4 -> V_10 ,
& V_4 -> V_11 . V_12 , V_6 , V_7 ) ;
if ( V_8 )
F_7 ( V_6 ) ;
return V_8 ;
}
int F_8 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
struct V_38 * V_39 = NULL ;
int V_8 , V_40 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_40 = F_11 ( V_4 -> V_37 , V_34 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_40 ) {
V_39 = F_12 ( V_4 -> V_37 , V_40 ) ;
if ( ! V_39 )
return - V_43 ;
if ( V_39 -> V_44 & V_45 )
return - V_43 ;
}
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_46 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_47 != V_48 ) {
bool V_49 = true ;
if ( V_4 -> V_11 . V_12 . V_50 == V_39 ) {
V_8 = 0 ;
goto V_51;
}
if ( V_4 -> V_11 . V_12 . V_22 )
V_49 = false ;
V_8 = F_16 ( V_2 , V_30 ,
V_52 , V_49 ) ;
if ( V_8 )
goto V_51;
}
V_4 -> V_11 . V_12 . V_50 = V_39 ;
if ( V_39 && ! V_4 -> V_11 . V_12 . V_22 ) {
struct V_53 V_54 = {
. V_55 = V_56 ,
. V_57 = V_40 ,
} ;
V_54 . V_39 = F_12 ( & V_2 -> V_37 , V_40 ) ;
if ( V_54 . V_39 )
V_8 = F_17 ( V_2 , & V_54 ) ;
else
V_8 = - V_43 ;
goto V_51;
}
V_8 = F_1 ( V_2 , V_4 ) ;
V_51:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_46 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_21 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_40 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_38 * V_39 = NULL ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_58 )
V_39 = V_4 -> V_58 -> V_59 . V_50 ;
else if ( V_4 -> V_11 . V_12 . V_50 )
V_39 = V_4 -> V_11 . V_12 . V_50 ;
F_18 ( V_4 ) ;
if ( V_39 ) {
V_40 -> V_60 = V_39 -> V_61 ;
V_40 -> V_62 = 6 ;
return 0 ;
}
return - V_43 ;
}
int F_22 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_63 * V_27 , char * V_64 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_2 V_65 = V_27 -> V_66 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( ! V_27 -> V_44 )
V_65 = 0 ;
if ( V_65 > 0 && V_64 [ V_65 - 1 ] == '\0' )
V_65 -- ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_46 ) ;
F_15 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_47 != V_48 ) {
bool V_49 = true ;
if ( V_4 -> V_11 . V_12 . V_64 && V_65 &&
V_65 == V_4 -> V_11 . V_12 . V_22 &&
memcmp ( V_4 -> V_11 . V_12 . V_64 , V_64 , V_65 ) == 0 )
goto V_51;
if ( V_65 )
V_49 = false ;
V_8 = F_16 ( V_2 , V_30 ,
V_52 , V_49 ) ;
if ( V_8 )
goto V_51;
}
V_4 -> V_11 . V_28 = false ;
V_4 -> V_11 . V_12 . V_64 = V_4 -> V_11 . V_64 ;
memcpy ( V_4 -> V_11 . V_64 , V_64 , V_65 ) ;
V_4 -> V_11 . V_12 . V_22 = V_65 ;
V_4 -> V_11 . V_12 . V_67 . V_68 = false ;
V_4 -> V_11 . V_12 . V_67 . V_69 =
F_23 ( V_70 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_51:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_46 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_24 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_63 * V_27 , char * V_64 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_27 -> V_44 = 0 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_58 ) {
const T_1 * V_13 ;
F_25 () ;
V_13 = F_26 ( & V_4 -> V_58 -> V_59 ,
V_71 ) ;
if ( V_13 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_66 = V_13 [ 1 ] ;
memcpy ( V_64 , V_13 + 2 , V_27 -> V_66 ) ;
}
F_27 () ;
} else if ( V_4 -> V_11 . V_12 . V_64 && V_4 -> V_11 . V_12 . V_22 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_66 = V_4 -> V_11 . V_12 . V_22 ;
memcpy ( V_64 , V_4 -> V_11 . V_12 . V_64 , V_27 -> V_66 ) ;
}
F_18 ( V_4 ) ;
return 0 ;
}
int F_28 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_72 * V_73 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_74 = V_73 -> V_75 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( V_73 -> V_76 != V_77 )
return - V_43 ;
if ( F_29 ( V_74 ) || F_30 ( V_74 ) )
V_74 = NULL ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_46 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_47 != V_48 ) {
V_8 = 0 ;
if ( ! V_74 && ! V_4 -> V_11 . V_12 . V_74 )
goto V_51;
if ( V_4 -> V_11 . V_12 . V_74 && V_74 &&
F_31 ( V_74 , V_4 -> V_11 . V_12 . V_74 ) )
goto V_51;
V_8 = F_16 ( V_2 , V_30 ,
V_52 , false ) ;
if ( V_8 )
goto V_51;
}
if ( V_74 ) {
memcpy ( V_4 -> V_11 . V_74 , V_74 , V_78 ) ;
V_4 -> V_11 . V_12 . V_74 = V_4 -> V_11 . V_74 ;
} else
V_4 -> V_11 . V_12 . V_74 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_51:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_46 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_32 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_72 * V_73 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_73 -> V_76 = V_77 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_58 )
memcpy ( V_73 -> V_75 , V_4 -> V_58 -> V_59 . V_74 , V_78 ) ;
else
memset ( V_73 -> V_75 , 0 , V_78 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int F_33 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_63 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_13 = V_35 ;
int V_14 = V_27 -> V_66 , V_8 ;
if ( V_4 -> V_41 != V_42 )
return - V_79 ;
if ( ! V_14 )
V_13 = NULL ;
F_15 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_11 . V_14 == V_14 &&
memcmp ( V_4 -> V_11 . V_13 , V_13 , V_14 ) == 0 )
goto V_51;
if ( V_14 ) {
V_13 = F_5 ( V_35 , V_14 , V_23 ) ;
if ( ! V_13 ) {
V_8 = - V_24 ;
goto V_51;
}
} else
V_13 = NULL ;
F_7 ( V_4 -> V_11 . V_13 ) ;
V_4 -> V_11 . V_13 = V_13 ;
V_4 -> V_11 . V_14 = V_14 ;
if ( V_4 -> V_47 != V_48 ) {
V_8 = F_16 ( V_2 , V_30 ,
V_52 , false ) ;
if ( V_8 )
goto V_51;
}
V_8 = 0 ;
V_51:
F_18 ( V_4 ) ;
return V_8 ;
}
int F_34 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_63 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_80 * V_81 = (struct V_80 * ) V_35 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_79 ;
V_2 = F_9 ( V_4 -> V_37 ) ;
if ( V_4 -> V_41 != V_42 )
return - V_43 ;
if ( V_81 -> V_82 . V_76 != V_77 )
return - V_43 ;
F_15 ( V_4 ) ;
switch ( V_81 -> V_83 ) {
case V_84 :
case V_85 :
V_8 = F_16 ( V_2 , V_30 , V_81 -> V_86 ,
true ) ;
break;
default:
V_8 = - V_79 ;
break;
}
F_18 ( V_4 ) ;
return V_8 ;
}
