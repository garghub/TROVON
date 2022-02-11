static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_8 = V_3 ;
F_2 ( & V_5 -> V_9 ) ;
}
static int F_3 ( char V_10 [ V_11 ] ,
char V_12 [ V_13 ] ,
char V_14 [ V_13 ] )
{
int V_8 = 0 ;
struct V_15 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_16 V_17 , V_18 ;
struct V_19 * V_20 = F_5 ( L_1 , 0 , 0 ) ;
if ( F_6 ( V_20 ) ) {
V_8 = F_7 ( V_20 ) ;
V_20 = NULL ;
goto V_21;
}
F_8 ( V_20 , V_22 ) ;
V_2 = F_9 ( V_20 , V_23 ) ;
if ( ! V_2 ) {
V_8 = - V_24 ;
goto V_21;
}
F_10 ( V_2 ,
V_25 | V_26 ,
F_1 , & V_5 ) ;
V_8 = F_11 ( V_20 , V_10 ,
V_11 ) ;
if ( V_8 < 0 )
goto V_21;
F_12 ( & V_17 , V_12 , V_13 ) ;
F_12 ( & V_18 , V_14 , V_13 ) ;
F_13 ( V_2 , & V_17 , & V_18 ,
V_13 , NULL ) ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 == - V_7 || V_8 == - V_27 ) {
F_15 ( & V_5 . V_9 ) ;
V_8 = V_5 . V_8 ;
}
V_21:
F_16 ( V_2 ) ;
F_17 ( V_20 ) ;
return V_8 ;
}
void F_18 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
if ( V_29 -> V_30 )
F_19 ( V_29 -> V_30 ) ;
F_17 ( V_29 -> V_31 ) ;
F_20 ( V_32 , V_29 ) ;
}
void F_21 ( struct V_33 * V_33 ,
struct V_28 * V_29 )
{
struct V_34 * V_35 = F_22 ( V_33 ) ;
struct V_28 * V_36 ;
if ( V_29 == NULL )
V_29 = F_23 ( V_35 -> V_37 ) ;
if ( V_29 == NULL )
return;
V_36 = F_24 ( & V_35 -> V_37 , V_29 , NULL ) ;
if ( V_36 != V_29 )
return;
F_18 ( V_29 ) ;
}
int F_25 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = F_22 ( V_33 ) ;
struct V_28 * V_38 ;
char V_39 [ V_40 +
( V_41 * 2 ) + 1 ] ;
struct V_42 * V_43 = NULL ;
struct V_44 * V_45 ;
struct V_46 V_47 ;
const struct V_48 * V_49 ;
struct V_50 * V_51 = F_26 ( V_33 -> V_52 ) ;
struct V_19 * V_53 ;
const char * V_54 ;
char V_55 [ V_56 ] ;
char V_57 ;
int V_8 ;
if ( ! V_58 ) {
V_8 = F_27 () ;
if ( V_8 )
return V_8 ;
}
V_59:
V_38 = F_23 ( V_35 -> V_37 ) ;
if ( V_38 ) {
if ( ! V_38 -> V_30 ||
F_28 ( V_38 -> V_30 ) == 0 )
return 0 ;
F_21 ( V_33 , V_38 ) ;
goto V_59;
}
V_8 = F_29 ( V_33 , V_60 ,
V_61 ,
& V_47 , sizeof( V_47 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_30 ( V_51 ) )
return V_8 ;
V_47 . V_62 = V_63 ;
V_47 . V_64 =
V_65 ;
V_47 . V_66 = 0 ;
} else if ( V_8 != sizeof( V_47 ) )
return - V_67 ;
V_8 = 0 ;
V_38 = F_31 ( V_32 , V_68 ) ;
if ( ! V_38 )
return - V_24 ;
V_38 -> V_69 = V_47 . V_66 ;
V_38 -> V_70 = V_47 . V_62 ;
V_38 -> V_71 = V_47 . V_64 ;
V_38 -> V_31 = NULL ;
V_38 -> V_30 = NULL ;
memcpy ( V_38 -> V_72 , V_47 . V_73 ,
sizeof( V_38 -> V_72 ) ) ;
if ( F_32 ( V_33 -> V_74 ) )
V_57 = V_38 -> V_70 ;
else if ( F_33 ( V_33 -> V_74 ) || F_34 ( V_33 -> V_74 ) )
V_57 = V_38 -> V_71 ;
else
F_35 () ;
switch ( V_57 ) {
case V_63 :
V_54 = L_2 ;
break;
case V_65 :
V_54 = L_3 ;
break;
default:
F_36 ( V_75
L_4 ,
V_57 , ( unsigned ) V_33 -> V_76 ) ;
V_8 = - V_77 ;
goto V_21;
}
if ( F_30 ( V_51 ) ) {
memset ( V_55 , 0x42 , V_13 ) ;
goto V_78;
}
memcpy ( V_39 , V_79 ,
V_40 ) ;
sprintf ( V_39 + V_40 ,
L_5 , V_41 ,
V_47 . V_73 ) ;
V_39 [ V_40 +
( 2 * V_41 ) ] = '\0' ;
V_43 = F_37 ( & V_80 , V_39 , NULL ) ;
if ( F_6 ( V_43 ) ) {
V_8 = F_7 ( V_43 ) ;
V_43 = NULL ;
goto V_21;
}
V_38 -> V_30 = V_43 ;
if ( V_43 -> type != & V_80 ) {
F_36 ( V_75
L_6 ) ;
V_8 = - V_77 ;
goto V_21;
}
F_38 ( & V_43 -> V_81 ) ;
V_49 = V_48 ( V_43 ) ;
if ( V_49 -> V_82 != sizeof( struct V_44 ) ) {
V_8 = - V_67 ;
F_39 ( & V_43 -> V_81 ) ;
goto V_21;
}
V_45 = (struct V_44 * ) V_49 -> V_6 ;
F_40 ( V_11 !=
V_83 ) ;
if ( V_45 -> V_84 != V_13 ) {
F_36 ( V_75
L_7 ,
V_45 -> V_84 ) ;
V_8 = - V_77 ;
F_39 ( & V_43 -> V_81 ) ;
goto V_21;
}
V_8 = F_3 ( V_47 . V_85 , V_45 -> V_86 ,
V_55 ) ;
F_39 ( & V_43 -> V_81 ) ;
if ( V_8 )
goto V_21;
V_78:
V_53 = F_5 ( V_54 , 0 , 0 ) ;
if ( ! V_53 || F_6 ( V_53 ) ) {
V_8 = V_53 ? F_7 ( V_53 ) : - V_24 ;
F_41 ( V_87
L_8 ,
V_88 , V_8 , ( unsigned ) V_33 -> V_76 ) ;
goto V_21;
}
V_38 -> V_31 = V_53 ;
F_42 ( V_53 , ~ 0 ) ;
F_43 ( F_44 ( V_53 ) ,
V_22 ) ;
V_8 = F_11 ( V_53 , V_55 ,
F_45 ( V_57 ) ) ;
if ( V_8 )
goto V_21;
F_46 ( V_55 , sizeof( V_55 ) ) ;
if ( F_24 ( & V_35 -> V_37 , NULL , V_38 ) != NULL ) {
F_18 ( V_38 ) ;
goto V_59;
}
return 0 ;
V_21:
if ( V_8 == - V_77 )
V_8 = 0 ;
F_18 ( V_38 ) ;
F_46 ( V_55 , sizeof( V_55 ) ) ;
return V_8 ;
}
int F_47 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = F_22 ( V_33 ) ;
return ( V_35 -> V_37 != NULL ) ;
}
