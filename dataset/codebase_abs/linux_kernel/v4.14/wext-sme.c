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
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_15 ( V_4 ) ;
return V_8 ;
}
int F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_39 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_37 * V_38 = NULL ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_50 )
V_38 = V_4 -> V_50 -> V_51 . V_47 ;
else if ( V_4 -> V_11 . V_12 . V_47 )
V_38 = V_4 -> V_11 . V_12 . V_47 ;
F_15 ( V_4 ) ;
if ( V_38 ) {
V_39 -> V_52 = V_38 -> V_53 ;
V_39 -> V_54 = 6 ;
return 0 ;
}
return - V_42 ;
}
int F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_55 * V_26 , char * V_56 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_2 V_57 = V_26 -> V_58 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( ! V_26 -> V_43 )
V_57 = 0 ;
if ( V_57 > 0 && V_56 [ V_57 - 1 ] == '\0' )
V_57 -- ;
F_13 ( V_4 ) ;
V_8 = 0 ;
if ( V_4 -> V_45 ) {
bool V_46 = true ;
if ( V_4 -> V_11 . V_12 . V_56 && V_57 &&
V_57 == V_4 -> V_11 . V_12 . V_20 &&
memcmp ( V_4 -> V_11 . V_12 . V_56 , V_56 , V_57 ) == 0 )
goto V_48;
if ( V_57 )
V_46 = false ;
V_8 = F_14 ( V_2 , V_29 ,
V_49 , V_46 ) ;
if ( V_8 )
goto V_48;
}
V_4 -> V_11 . V_27 = false ;
V_4 -> V_11 . V_12 . V_56 = V_4 -> V_11 . V_56 ;
memcpy ( V_4 -> V_11 . V_56 , V_56 , V_57 ) ;
V_4 -> V_11 . V_12 . V_20 = V_57 ;
V_4 -> V_11 . V_12 . V_59 . V_60 = false ;
V_4 -> V_11 . V_12 . V_59 . V_61 =
F_18 ( V_62 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_15 ( V_4 ) ;
return V_8 ;
}
int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_55 * V_26 , char * V_56 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_26 -> V_43 = 0 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_50 ) {
const T_1 * V_13 ;
F_20 () ;
V_13 = F_21 ( & V_4 -> V_50 -> V_51 ,
V_63 ) ;
if ( V_13 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_58 = V_13 [ 1 ] ;
memcpy ( V_56 , V_13 + 2 , V_26 -> V_58 ) ;
}
F_22 () ;
} else if ( V_4 -> V_11 . V_12 . V_56 && V_4 -> V_11 . V_12 . V_20 ) {
V_26 -> V_43 = 1 ;
V_26 -> V_58 = V_4 -> V_11 . V_12 . V_20 ;
memcpy ( V_56 , V_4 -> V_11 . V_12 . V_56 , V_26 -> V_58 ) ;
}
F_15 ( V_4 ) ;
return 0 ;
}
int F_23 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_64 * V_65 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_66 = V_65 -> V_67 ;
int V_8 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
if ( V_65 -> V_68 != V_69 )
return - V_42 ;
if ( F_24 ( V_66 ) || F_25 ( V_66 ) )
V_66 = NULL ;
F_13 ( V_4 ) ;
if ( V_4 -> V_45 ) {
V_8 = 0 ;
if ( ! V_66 && ! V_4 -> V_11 . V_12 . V_66 )
goto V_48;
if ( V_4 -> V_11 . V_12 . V_66 && V_66 &&
F_26 ( V_66 , V_4 -> V_11 . V_12 . V_66 ) )
goto V_48;
V_8 = F_14 ( V_2 , V_29 ,
V_49 , false ) ;
if ( V_8 )
goto V_48;
}
if ( V_66 ) {
memcpy ( V_4 -> V_11 . V_66 , V_66 , V_70 ) ;
V_4 -> V_11 . V_12 . V_66 = V_4 -> V_11 . V_66 ;
} else
V_4 -> V_11 . V_12 . V_66 = NULL ;
V_8 = F_1 ( V_2 , V_4 ) ;
V_48:
F_15 ( V_4 ) ;
return V_8 ;
}
int F_27 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_64 * V_65 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
if ( F_10 ( V_4 -> V_40 != V_41 ) )
return - V_42 ;
V_65 -> V_68 = V_69 ;
F_13 ( V_4 ) ;
if ( V_4 -> V_50 )
memcpy ( V_65 -> V_67 , V_4 -> V_50 -> V_51 . V_66 , V_70 ) ;
else
F_28 ( V_65 -> V_67 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
int F_29 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_55 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_1 * V_2 = F_9 ( V_4 -> V_36 ) ;
T_1 * V_13 = V_34 ;
int V_14 = V_26 -> V_58 , V_8 ;
if ( V_4 -> V_40 != V_41 )
return - V_71 ;
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
F_30 ( V_4 -> V_11 . V_13 ) ;
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
F_15 ( V_4 ) ;
return V_8 ;
}
int F_31 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_55 * V_26 , char * V_34 )
{
struct V_3 * V_4 = V_29 -> V_35 ;
struct V_72 * V_73 = (struct V_72 * ) V_34 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_4 )
return - V_71 ;
V_2 = F_9 ( V_4 -> V_36 ) ;
if ( V_4 -> V_40 != V_41 )
return - V_42 ;
if ( V_73 -> V_74 . V_68 != V_69 )
return - V_42 ;
F_13 ( V_4 ) ;
switch ( V_73 -> V_75 ) {
case V_76 :
case V_77 :
V_8 = F_14 ( V_2 , V_29 , V_73 -> V_78 , true ) ;
break;
default:
V_8 = - V_71 ;
break;
}
F_15 ( V_4 ) ;
return V_8 ;
}
