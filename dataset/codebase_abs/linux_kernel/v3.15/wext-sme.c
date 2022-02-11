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
F_13 ( V_4 ) ;
if ( V_4 -> V_46 ) {
bool V_47 = true ;
if ( V_4 -> V_11 . V_12 . V_48 == V_39 ) {
V_8 = 0 ;
goto V_49;
}
if ( V_4 -> V_11 . V_12 . V_22 )
V_47 = false ;
V_8 = F_14 ( V_2 , V_30 ,
V_50 , V_47 ) ;
if ( V_8 )
goto V_49;
}
V_4 -> V_11 . V_12 . V_48 = V_39 ;
if ( V_39 && ! V_4 -> V_11 . V_12 . V_22 ) {
struct V_51 V_52 = {
. V_53 = V_54 ,
. V_55 = V_40 ,
} ;
V_52 . V_39 = F_12 ( & V_2 -> V_37 , V_40 ) ;
if ( V_52 . V_39 )
V_8 = F_15 ( V_2 , & V_52 ) ;
else
V_8 = - V_43 ;
goto V_49;
}
V_8 = F_1 ( V_2 , V_4 ) ;
V_49:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_40 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_38 * V_39 = NULL ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_56 )
V_39 = V_4 -> V_56 -> V_57 . V_48 ;
else if ( V_4 -> V_11 . V_12 . V_48 )
V_39 = V_4 -> V_11 . V_12 . V_48 ;
F_16 ( V_4 ) ;
if ( V_39 ) {
V_40 -> V_58 = V_39 -> V_59 ;
V_40 -> V_60 = 6 ;
return 0 ;
}
return - V_43 ;
}
int F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_61 * V_27 , char * V_62 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_2 V_63 = V_27 -> V_64 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( ! V_27 -> V_44 )
V_63 = 0 ;
if ( V_63 > 0 && V_62 [ V_63 - 1 ] == '\0' )
V_63 -- ;
F_13 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_46 ) {
bool V_47 = true ;
if ( V_4 -> V_11 . V_12 . V_62 && V_63 &&
V_63 == V_4 -> V_11 . V_12 . V_22 &&
memcmp ( V_4 -> V_11 . V_12 . V_62 , V_62 , V_63 ) == 0 )
goto V_49;
if ( V_63 )
V_47 = false ;
V_8 = F_14 ( V_2 , V_30 ,
V_50 , V_47 ) ;
if ( V_8 )
goto V_49;
}
V_4 -> V_11 . V_28 = false ;
V_4 -> V_11 . V_12 . V_62 = V_4 -> V_11 . V_62 ;
memcpy ( V_4 -> V_11 . V_62 , V_62 , V_63 ) ;
V_4 -> V_11 . V_12 . V_22 = V_63 ;
V_4 -> V_11 . V_12 . V_65 . V_66 = false ;
V_4 -> V_11 . V_12 . V_65 . V_67 =
F_19 ( V_68 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_49:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_61 * V_27 , char * V_62 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_27 -> V_44 = 0 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_56 ) {
const T_1 * V_13 ;
F_21 () ;
V_13 = F_22 ( & V_4 -> V_56 -> V_57 ,
V_69 ) ;
if ( V_13 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_64 = V_13 [ 1 ] ;
memcpy ( V_62 , V_13 + 2 , V_27 -> V_64 ) ;
}
F_23 () ;
} else if ( V_4 -> V_11 . V_12 . V_62 && V_4 -> V_11 . V_12 . V_22 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_64 = V_4 -> V_11 . V_12 . V_22 ;
memcpy ( V_62 , V_4 -> V_11 . V_12 . V_62 , V_27 -> V_64 ) ;
}
F_16 ( V_4 ) ;
return 0 ;
}
int F_24 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_70 * V_71 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_72 = V_71 -> V_73 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( V_71 -> V_74 != V_75 )
return - V_43 ;
if ( F_25 ( V_72 ) || F_26 ( V_72 ) )
V_72 = NULL ;
F_13 ( V_4 ) ;
if ( V_4 -> V_46 ) {
V_8 = 0 ;
if ( ! V_72 && ! V_4 -> V_11 . V_12 . V_72 )
goto V_49;
if ( V_4 -> V_11 . V_12 . V_72 && V_72 &&
F_27 ( V_72 , V_4 -> V_11 . V_12 . V_72 ) )
goto V_49;
V_8 = F_14 ( V_2 , V_30 ,
V_50 , false ) ;
if ( V_8 )
goto V_49;
}
if ( V_72 ) {
memcpy ( V_4 -> V_11 . V_72 , V_72 , V_76 ) ;
V_4 -> V_11 . V_12 . V_72 = V_4 -> V_11 . V_72 ;
} else
V_4 -> V_11 . V_12 . V_72 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_49:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_28 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_70 * V_71 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_71 -> V_74 = V_75 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_56 )
memcpy ( V_71 -> V_73 , V_4 -> V_56 -> V_57 . V_72 , V_76 ) ;
else
memset ( V_71 -> V_73 , 0 , V_76 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
int F_29 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_61 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_13 = V_35 ;
int V_14 = V_27 -> V_64 , V_8 ;
if ( V_4 -> V_41 != V_42 )
return - V_77 ;
if ( ! V_14 )
V_13 = NULL ;
F_13 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_11 . V_14 == V_14 &&
memcmp ( V_4 -> V_11 . V_13 , V_13 , V_14 ) == 0 )
goto V_49;
if ( V_14 ) {
V_13 = F_5 ( V_35 , V_14 , V_23 ) ;
if ( ! V_13 ) {
V_8 = - V_24 ;
goto V_49;
}
} else
V_13 = NULL ;
F_7 ( V_4 -> V_11 . V_13 ) ;
V_4 -> V_11 . V_13 = V_13 ;
V_4 -> V_11 . V_14 = V_14 ;
if ( V_4 -> V_46 ) {
V_8 = F_14 ( V_2 , V_30 ,
V_50 , false ) ;
if ( V_8 )
goto V_49;
}
V_8 = 0 ;
V_49:
F_16 ( V_4 ) ;
return V_8 ;
}
int F_30 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_61 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_78 * V_79 = (struct V_78 * ) V_35 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_77 ;
V_2 = F_9 ( V_4 -> V_37 ) ;
if ( V_4 -> V_41 != V_42 )
return - V_43 ;
if ( V_79 -> V_80 . V_74 != V_75 )
return - V_43 ;
F_13 ( V_4 ) ;
switch ( V_79 -> V_81 ) {
case V_82 :
case V_83 :
V_8 = F_14 ( V_2 , V_30 , V_79 -> V_84 , true ) ;
break;
default:
V_8 = - V_77 ;
break;
}
F_16 ( V_4 ) ;
return V_8 ;
}
