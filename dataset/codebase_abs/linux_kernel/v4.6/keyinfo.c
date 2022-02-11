static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_8 = V_3 ;
F_2 ( & V_5 -> V_9 ) ;
}
static int F_3 ( T_1 V_10 [ V_11 ] ,
T_1 V_12 [ V_13 ] ,
T_1 V_14 [ V_13 ] )
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
static void F_18 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_19 ( V_29 -> V_30 ) ;
F_17 ( V_29 -> V_31 ) ;
F_20 ( V_32 , V_29 ) ;
}
int F_21 ( struct V_33 * V_33 )
{
struct V_28 * V_34 ;
T_1 V_35 [ V_36 +
( V_37 * 2 ) + 1 ] ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
struct V_42 V_43 ;
const struct V_44 * V_45 ;
struct V_19 * V_46 ;
const char * V_47 ;
T_1 V_48 [ V_49 ] ;
T_1 V_50 ;
int V_8 ;
V_8 = F_22 () ;
if ( V_8 )
return V_8 ;
if ( ! V_33 -> V_51 -> V_52 -> V_53 )
return - V_54 ;
V_55:
V_34 = F_23 ( V_33 -> V_56 ) ;
if ( V_34 ) {
if ( ! V_34 -> V_30 ||
F_24 ( V_34 -> V_30 ) == 0 )
return 0 ;
F_25 ( V_33 , V_34 ) ;
goto V_55;
}
V_8 = V_33 -> V_51 -> V_52 -> V_53 ( V_33 , & V_43 , sizeof( V_43 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_26 ( V_33 ) )
return V_8 ;
V_43 . V_57 = V_58 ;
V_43 . V_59 = V_60 ;
V_43 . V_61 = 0 ;
} else if ( V_8 != sizeof( V_43 ) ) {
return - V_62 ;
}
V_8 = 0 ;
V_34 = F_27 ( V_32 , V_23 ) ;
if ( ! V_34 )
return - V_24 ;
V_34 -> V_63 = V_43 . V_61 ;
V_34 -> V_64 = V_43 . V_57 ;
V_34 -> V_65 = V_43 . V_59 ;
V_34 -> V_31 = NULL ;
V_34 -> V_30 = NULL ;
memcpy ( V_34 -> V_66 , V_43 . V_67 ,
sizeof( V_34 -> V_66 ) ) ;
if ( F_28 ( V_33 -> V_68 ) )
V_50 = V_34 -> V_64 ;
else if ( F_29 ( V_33 -> V_68 ) || F_30 ( V_33 -> V_68 ) )
V_50 = V_34 -> V_65 ;
else
F_31 () ;
switch ( V_50 ) {
case V_58 :
V_47 = L_2 ;
break;
case V_60 :
V_47 = L_3 ;
break;
default:
F_32 ( V_69
L_4 ,
V_70 , V_50 , ( unsigned ) V_33 -> V_71 ) ;
V_8 = - V_72 ;
goto V_21;
}
if ( F_26 ( V_33 ) ) {
memset ( V_48 , 0x42 , V_13 ) ;
goto V_73;
}
memcpy ( V_35 , V_74 ,
V_36 ) ;
sprintf ( V_35 + V_36 ,
L_5 , V_37 ,
V_43 . V_67 ) ;
V_35 [ V_36 +
( 2 * V_37 ) ] = '\0' ;
V_39 = F_33 ( & V_75 , V_35 , NULL ) ;
if ( F_6 ( V_39 ) ) {
V_8 = F_7 ( V_39 ) ;
V_39 = NULL ;
goto V_21;
}
V_34 -> V_30 = V_39 ;
if ( V_39 -> type != & V_75 ) {
F_32 ( V_69
L_6 , V_70 ) ;
V_8 = - V_72 ;
goto V_21;
}
F_34 ( & V_39 -> V_76 ) ;
V_45 = V_44 ( V_39 ) ;
if ( V_45 -> V_77 != sizeof( struct V_40 ) ) {
V_8 = - V_62 ;
F_35 ( & V_39 -> V_76 ) ;
goto V_21;
}
V_41 = (struct V_40 * ) V_45 -> V_6 ;
F_36 ( V_11 != V_78 ) ;
if ( V_41 -> V_79 != V_13 ) {
F_32 ( V_69
L_7 ,
V_70 , V_41 -> V_79 ) ;
V_8 = - V_72 ;
F_35 ( & V_39 -> V_76 ) ;
goto V_21;
}
V_8 = F_3 ( V_43 . V_80 , V_41 -> V_81 , V_48 ) ;
F_35 ( & V_39 -> V_76 ) ;
if ( V_8 )
goto V_21;
V_73:
V_46 = F_5 ( V_47 , 0 , 0 ) ;
if ( ! V_46 || F_6 ( V_46 ) ) {
V_8 = V_46 ? F_7 ( V_46 ) : - V_24 ;
F_37 ( V_82
L_8 ,
V_70 , V_8 , ( unsigned ) V_33 -> V_71 ) ;
goto V_21;
}
V_34 -> V_31 = V_46 ;
F_38 ( V_46 , ~ 0 ) ;
F_8 ( V_46 , V_22 ) ;
V_8 = F_11 ( V_46 , V_48 , F_39 ( V_50 ) ) ;
if ( V_8 )
goto V_21;
F_40 ( V_48 , sizeof( V_48 ) ) ;
if ( F_41 ( & V_33 -> V_56 , NULL , V_34 ) != NULL ) {
F_18 ( V_34 ) ;
goto V_55;
}
return 0 ;
V_21:
if ( V_8 == - V_72 )
V_8 = 0 ;
F_18 ( V_34 ) ;
F_40 ( V_48 , sizeof( V_48 ) ) ;
return V_8 ;
}
void F_25 ( struct V_33 * V_33 , struct V_28 * V_29 )
{
struct V_28 * V_83 ;
if ( V_29 == NULL )
V_29 = F_23 ( V_33 -> V_56 ) ;
if ( V_29 == NULL )
return;
V_83 = F_41 ( & V_33 -> V_56 , V_29 , NULL ) ;
if ( V_83 != V_29 )
return;
F_18 ( V_29 ) ;
}
int F_42 ( struct V_33 * V_33 )
{
struct V_28 * V_29 = V_33 -> V_56 ;
if ( ! V_29 ||
( V_29 -> V_30 &&
( V_29 -> V_30 -> V_61 & ( ( 1 << V_84 ) |
( 1 << V_85 ) |
( 1 << V_86 ) ) ) ) )
return F_21 ( V_33 ) ;
return 0 ;
}
