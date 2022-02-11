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
struct V_19 * V_20 = F_5 ( L_1 , 0 ,
0 ) ;
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
F_15 ( V_2 -> V_28 . V_6 != & V_5 ) ;
F_16 ( & V_5 . V_9 ) ;
V_8 = V_5 . V_8 ;
}
V_21:
if ( V_2 )
F_17 ( V_2 ) ;
if ( V_20 )
F_18 ( V_20 ) ;
return V_8 ;
}
static void F_19 ( struct V_29 * V_30 )
{
if ( ! V_30 )
return;
F_20 ( V_30 -> V_31 ) ;
F_18 ( V_30 -> V_32 ) ;
F_21 ( V_33 , V_30 ) ;
}
void F_22 ( struct V_34 * V_34 , struct V_29 * V_30 )
{
struct V_35 * V_36 = F_23 ( V_34 ) ;
struct V_29 * V_37 ;
if ( V_30 == NULL )
V_30 = F_24 ( V_36 -> V_38 ) ;
if ( V_30 == NULL )
return;
V_37 = F_25 ( & V_36 -> V_38 , V_30 , NULL ) ;
if ( V_37 != V_30 )
return;
F_19 ( V_30 ) ;
}
int F_26 ( struct V_34 * V_34 )
{
struct V_35 * V_36 = F_23 ( V_34 ) ;
struct V_29 * V_39 ;
char V_40 [ V_41 +
( V_42 * 2 ) + 1 ] ;
struct V_43 * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
struct V_49 * V_50 ;
struct V_19 * V_51 ;
const char * V_52 ;
char V_53 [ V_54 ] ;
char V_55 ;
int V_8 ;
V_8 = F_27 () ;
if ( V_8 )
return V_8 ;
V_56:
V_39 = F_24 ( V_36 -> V_38 ) ;
if ( V_39 ) {
if ( ! V_39 -> V_31 ||
F_28 ( V_39 -> V_31 ) == 0 )
return 0 ;
F_22 ( V_34 , V_39 ) ;
goto V_56;
}
V_8 = F_29 ( V_34 , V_57 ,
V_58 ,
& V_48 , sizeof( V_48 ) , NULL ) ;
if ( V_8 < 0 )
return V_8 ;
else if ( V_8 != sizeof( V_48 ) )
return - V_59 ;
V_8 = 0 ;
V_39 = F_30 ( V_33 , V_23 ) ;
if ( ! V_39 )
return - V_24 ;
V_39 -> V_60 = V_48 . V_61 ;
V_39 -> V_62 = V_48 . V_63 ;
V_39 -> V_64 = V_48 . V_65 ;
V_39 -> V_32 = NULL ;
V_39 -> V_31 = NULL ;
memcpy ( V_39 -> V_66 , V_48 . V_67 ,
sizeof( V_39 -> V_66 ) ) ;
if ( F_31 ( V_34 -> V_68 ) )
V_55 = V_39 -> V_62 ;
else if ( F_32 ( V_34 -> V_68 ) || F_33 ( V_34 -> V_68 ) )
V_55 = V_39 -> V_64 ;
else
F_34 () ;
switch ( V_55 ) {
case V_69 :
V_52 = L_2 ;
break;
case V_70 :
V_52 = L_3 ;
break;
default:
F_35 ( V_71
L_4 ,
V_55 , ( unsigned ) V_34 -> V_72 ) ;
V_8 = - V_73 ;
goto V_21;
}
memcpy ( V_40 , V_74 ,
V_41 ) ;
sprintf ( V_40 + V_41 ,
L_5 , V_42 ,
V_48 . V_67 ) ;
V_40 [ V_41 +
( 2 * V_42 ) ] = '\0' ;
V_44 = F_36 ( & V_75 , V_40 , NULL ) ;
if ( F_6 ( V_44 ) ) {
V_8 = F_7 ( V_44 ) ;
V_44 = NULL ;
goto V_21;
}
V_39 -> V_31 = V_44 ;
F_15 ( V_44 -> type != & V_75 ) ;
V_50 = ( (struct V_49 * ) V_44 -> V_76 . V_6 ) ;
if ( V_50 -> V_77 != sizeof( struct V_45 ) ) {
V_8 = - V_59 ;
goto V_21;
}
V_46 = (struct V_45 * ) V_50 -> V_6 ;
F_37 ( V_11 !=
V_78 ) ;
F_15 ( V_46 -> V_79 != V_13 ) ;
V_8 = F_3 ( V_48 . V_80 , V_46 -> V_81 ,
V_53 ) ;
if ( V_8 )
goto V_21;
V_51 = F_5 ( V_52 , 0 , 0 ) ;
if ( ! V_51 || F_6 ( V_51 ) ) {
V_8 = V_51 ? F_7 ( V_51 ) : - V_24 ;
F_38 ( V_82
L_6 ,
V_83 , V_8 , ( unsigned ) V_34 -> V_72 ) ;
goto V_21;
}
V_39 -> V_32 = V_51 ;
F_39 ( V_51 , ~ 0 ) ;
F_40 ( F_41 ( V_51 ) ,
V_22 ) ;
V_8 = F_11 ( V_51 , V_53 ,
F_42 ( V_55 ) ) ;
if ( V_8 )
goto V_21;
F_43 ( V_53 , sizeof( V_53 ) ) ;
if ( F_25 ( & V_36 -> V_38 , NULL , V_39 ) != NULL ) {
F_19 ( V_39 ) ;
goto V_56;
}
return 0 ;
V_21:
if ( V_8 == - V_73 && ! F_31 ( V_34 -> V_68 ) )
V_8 = 0 ;
F_19 ( V_39 ) ;
F_43 ( V_53 , sizeof( V_53 ) ) ;
return V_8 ;
}
int F_44 ( struct V_34 * V_34 )
{
struct V_35 * V_36 = F_23 ( V_34 ) ;
return ( V_36 -> V_38 != NULL ) ;
}
