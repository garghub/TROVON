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
V_8 = F_17 ( V_2 , V_4 , V_40 , V_53 ) ;
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
if ( V_4 -> V_54 )
V_39 = V_4 -> V_54 -> V_55 . V_50 ;
else if ( V_4 -> V_11 . V_12 . V_50 )
V_39 = V_4 -> V_11 . V_12 . V_50 ;
F_18 ( V_4 ) ;
if ( V_39 ) {
V_40 -> V_56 = V_39 -> V_57 ;
V_40 -> V_58 = 6 ;
return 0 ;
}
return - V_43 ;
}
int F_22 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_59 * V_27 , char * V_60 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_2 V_61 = V_27 -> V_62 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( ! V_27 -> V_44 )
V_61 = 0 ;
if ( V_61 > 0 && V_60 [ V_61 - 1 ] == '\0' )
V_61 -- ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_46 ) ;
F_15 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_47 != V_48 ) {
bool V_49 = true ;
if ( V_4 -> V_11 . V_12 . V_60 && V_61 &&
V_61 == V_4 -> V_11 . V_12 . V_22 &&
memcmp ( V_4 -> V_11 . V_12 . V_60 , V_60 , V_61 ) == 0 )
goto V_51;
if ( V_61 )
V_49 = false ;
V_8 = F_16 ( V_2 , V_30 ,
V_52 , V_49 ) ;
if ( V_8 )
goto V_51;
}
V_4 -> V_11 . V_28 = false ;
V_4 -> V_11 . V_12 . V_60 = V_4 -> V_11 . V_60 ;
memcpy ( V_4 -> V_11 . V_60 , V_60 , V_61 ) ;
V_4 -> V_11 . V_12 . V_22 = V_61 ;
V_4 -> V_11 . V_12 . V_63 . V_64 = false ;
V_4 -> V_11 . V_12 . V_63 . V_65 =
F_23 ( V_66 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_51:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_46 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_24 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_59 * V_27 , char * V_60 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_27 -> V_44 = 0 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_54 ) {
const T_1 * V_13 = F_25 ( & V_4 -> V_54 -> V_55 ,
V_67 ) ;
if ( V_13 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_62 = V_13 [ 1 ] ;
memcpy ( V_60 , V_13 + 2 , V_27 -> V_62 ) ;
}
} else if ( V_4 -> V_11 . V_12 . V_60 && V_4 -> V_11 . V_12 . V_22 ) {
V_27 -> V_44 = 1 ;
V_27 -> V_62 = V_4 -> V_11 . V_12 . V_22 ;
memcpy ( V_60 , V_4 -> V_11 . V_12 . V_60 , V_27 -> V_62 ) ;
}
F_18 ( V_4 ) ;
return 0 ;
}
int F_26 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_68 * V_69 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_70 = V_69 -> V_71 ;
int V_8 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
if ( V_69 -> V_72 != V_73 )
return - V_43 ;
if ( F_27 ( V_70 ) || F_28 ( V_70 ) )
V_70 = NULL ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_46 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_47 != V_48 ) {
V_8 = 0 ;
if ( ! V_70 && ! V_4 -> V_11 . V_12 . V_70 )
goto V_51;
if ( V_4 -> V_11 . V_12 . V_70 && V_70 &&
F_29 ( V_70 , V_4 -> V_11 . V_12 . V_70 ) )
goto V_51;
V_8 = F_16 ( V_2 , V_30 ,
V_52 , false ) ;
if ( V_8 )
goto V_51;
}
if ( V_70 ) {
memcpy ( V_4 -> V_11 . V_70 , V_70 , V_74 ) ;
V_4 -> V_11 . V_12 . V_70 = V_4 -> V_11 . V_70 ;
} else
V_4 -> V_11 . V_12 . V_70 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_51:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_46 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_30 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_68 * V_69 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
if ( F_10 ( V_4 -> V_41 != V_42 ) )
return - V_43 ;
V_69 -> V_72 = V_73 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_54 )
memcpy ( V_69 -> V_71 , V_4 -> V_54 -> V_55 . V_70 , V_74 ) ;
else
memset ( V_69 -> V_71 , 0 , V_74 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int F_31 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_59 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_37 ) ;
T_1 * V_13 = V_35 ;
int V_14 = V_27 -> V_62 , V_8 ;
if ( V_4 -> V_41 != V_42 )
return - V_75 ;
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
int F_32 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_59 * V_27 , char * V_35 )
{
struct V_3 * V_4 = V_30 -> V_36 ;
struct V_76 * V_77 = (struct V_76 * ) V_35 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_75 ;
V_2 = F_9 ( V_4 -> V_37 ) ;
if ( V_4 -> V_41 != V_42 )
return - V_43 ;
if ( V_77 -> V_78 . V_72 != V_73 )
return - V_43 ;
F_15 ( V_4 ) ;
switch ( V_77 -> V_79 ) {
case V_80 :
case V_81 :
V_8 = F_16 ( V_2 , V_30 , V_77 -> V_82 ,
true ) ;
break;
default:
V_8 = - V_75 ;
break;
}
F_18 ( V_4 ) ;
return V_8 ;
}
