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
if ( V_4 -> V_11 . V_15 ) {
V_4 -> V_11 . V_15 -> V_16 = V_4 -> V_11 . V_17 ;
V_4 -> V_11 . V_15 -> V_18 = V_4 -> V_11 . V_19 ;
if ( V_4 -> V_11 . V_17 != - 1 )
V_4 -> V_11 . V_12 . V_20 = true ;
}
if ( ! V_4 -> V_11 . V_12 . V_21 )
return 0 ;
if ( V_4 -> V_11 . V_15 ) {
V_6 = F_5 ( V_4 -> V_11 . V_15 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return - V_23 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
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
V_39 = F_11 ( V_4 -> V_36 , V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 ) {
V_38 = F_12 ( V_4 -> V_36 , V_39 ) ;
if ( ! V_38 )
return - V_42 ;
if ( V_38 -> V_43 & V_44 )
return - V_42 ;
}
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_45 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_46 != V_47 ) {
bool V_48 = true ;
if ( V_4 -> V_11 . V_12 . V_49 == V_38 ) {
V_8 = 0 ;
goto V_50;
}
if ( V_4 -> V_11 . V_12 . V_21 )
V_48 = false ;
V_8 = F_16 ( V_2 , V_29 ,
V_51 , V_48 ) ;
if ( V_8 )
goto V_50;
}
V_4 -> V_11 . V_12 . V_49 = V_38 ;
if ( V_38 && ! V_4 -> V_11 . V_12 . V_21 ) {
V_8 = F_17 ( V_2 , V_4 , V_39 , V_52 ) ;
goto V_50;
}
V_8 = F_1 ( V_2 , V_4 ) ;
V_50:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_45 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_39 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_37 * V_38 = NULL ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_53 )
V_38 = V_4 -> V_53 -> V_54 . V_49 ;
else if ( V_4 -> V_11 . V_12 . V_49 )
V_38 = V_4 -> V_11 . V_12 . V_49 ;
F_18 ( V_4 ) ;
if ( V_38 ) {
V_39 -> V_55 = V_38 -> V_56 ;
V_39 -> V_57 = 6 ;
return 0 ;
}
return - V_42 ;
}
int F_22 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_58 * V_26 , char * V_59 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_2 V_60 = V_26 -> V_61 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( ! V_26 -> V_43 )
V_60 = 0 ;
if ( V_60 > 0 && V_59 [ V_60 - 1 ] == '\0' )
V_60 -- ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_45 ) ;
F_15 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_46 != V_47 ) {
bool V_48 = true ;
if ( V_4 -> V_11 . V_12 . V_59 && V_60 &&
V_60 == V_4 -> V_11 . V_12 . V_21 &&
memcmp ( V_4 -> V_11 . V_12 . V_59 , V_59 , V_60 ) == 0 )
goto V_50;
if ( V_60 )
V_48 = false ;
V_8 = F_16 ( V_2 , V_29 ,
V_51 , V_48 ) ;
if ( V_8 )
goto V_50;
}
V_4 -> V_11 . V_27 = false ;
V_4 -> V_11 . V_12 . V_59 = V_4 -> V_11 . V_59 ;
memcpy ( V_4 -> V_11 . V_59 , V_59 , V_60 ) ;
V_4 -> V_11 . V_12 . V_21 = V_60 ;
V_4 -> V_11 . V_12 . V_62 . V_63 = false ;
V_4 -> V_11 . V_12 . V_62 . V_64 =
F_23 ( V_65 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_50:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_45 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_24 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_58 * V_26 , char * V_59 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_26 -> V_43 = 0 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_53 ) {
const T_1 * V_13 = F_25 ( & V_4 -> V_53 -> V_54 ,
V_66 ) ;
if ( V_13 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_61 = V_13 [ 1 ] ;
memcpy ( V_59 , V_13 + 2 , V_26 -> V_61 ) ;
}
} else if ( V_4 -> V_11 . V_12 . V_59 && V_4 -> V_11 . V_12 . V_21 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_61 = V_4 -> V_11 . V_12 . V_21 ;
memcpy ( V_59 , V_4 -> V_11 . V_12 . V_59 , V_26 -> V_61 ) ;
}
F_18 ( V_4 ) ;
return 0 ;
}
int F_26 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_67 * V_68 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_69 = V_68 -> V_70 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( V_68 -> V_71 != V_72 )
return - V_42 ;
if ( F_27 ( V_69 ) || F_28 ( V_69 ) )
V_69 = NULL ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_45 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_46 != V_47 ) {
V_8 = 0 ;
if ( ! V_69 && ! V_4 -> V_11 . V_12 . V_69 )
goto V_50;
if ( V_4 -> V_11 . V_12 . V_69 && V_69 &&
F_29 ( V_69 , V_4 -> V_11 . V_12 . V_69 ) == 0 )
goto V_50;
V_8 = F_16 ( V_2 , V_29 ,
V_51 , false ) ;
if ( V_8 )
goto V_50;
}
if ( V_69 ) {
memcpy ( V_4 -> V_11 . V_69 , V_69 , V_73 ) ;
V_4 -> V_11 . V_12 . V_69 = V_4 -> V_11 . V_69 ;
} else
V_4 -> V_11 . V_12 . V_69 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_50:
F_18 ( V_4 ) ;
F_19 ( & V_2 -> V_45 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
int F_30 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_67 * V_68 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_68 -> V_71 = V_72 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_53 )
memcpy ( V_68 -> V_70 , V_4 -> V_53 -> V_54 . V_69 , V_73 ) ;
else
memset ( V_68 -> V_70 , 0 , V_73 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int F_31 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_58 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_13 = V_34 ;
int V_14 = V_26 -> V_61 , V_8 ;
if ( V_4 -> V_40 != V_41 )
return - V_74 ;
if ( ! V_14 )
V_13 = NULL ;
F_15 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_11 . V_14 == V_14 &&
memcmp ( V_4 -> V_11 . V_13 , V_13 , V_14 ) == 0 )
goto V_50;
if ( V_14 ) {
V_13 = F_5 ( V_34 , V_14 , V_22 ) ;
if ( ! V_13 ) {
V_8 = - V_23 ;
goto V_50;
}
} else
V_13 = NULL ;
F_7 ( V_4 -> V_11 . V_13 ) ;
V_4 -> V_11 . V_13 = V_13 ;
V_4 -> V_11 . V_14 = V_14 ;
if ( V_4 -> V_46 != V_47 ) {
V_8 = F_16 ( V_2 , V_29 ,
V_51 , false ) ;
if ( V_8 )
goto V_50;
}
V_8 = 0 ;
V_50:
F_18 ( V_4 ) ;
return V_8 ;
}
int F_32 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_58 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_75 * V_76 = (struct V_75 * ) V_34 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_74 ;
V_2 = F_9 ( V_4 -> V_36 ) ;
if ( V_4 -> V_40 != V_41 )
return - V_42 ;
if ( V_76 -> V_77 . V_71 != V_72 )
return - V_42 ;
F_15 ( V_4 ) ;
switch ( V_76 -> V_78 ) {
case V_79 :
case V_80 :
V_8 = F_16 ( V_2 , V_29 , V_76 -> V_81 ,
true ) ;
break;
default:
V_8 = - V_74 ;
break;
}
F_18 ( V_4 ) ;
return V_8 ;
}
