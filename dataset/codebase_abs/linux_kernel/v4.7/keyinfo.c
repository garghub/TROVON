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
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 * V_32 ,
T_1 * V_33 , int V_34 )
{
T_1 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
const struct V_40 * V_41 ;
int V_42 = V_34 + ( V_43 * 2 ) + 1 ;
int V_8 ;
V_35 = F_19 ( V_42 , V_23 ) ;
if ( ! V_35 )
return - V_24 ;
memcpy ( V_35 , V_33 , V_34 ) ;
sprintf ( V_35 + V_34 ,
L_2 , V_43 ,
V_31 -> V_44 ) ;
V_35 [ V_42 - 1 ] = '\0' ;
V_37 = F_20 ( & V_45 , V_35 , NULL ) ;
F_21 ( V_35 ) ;
if ( F_6 ( V_37 ) )
return F_7 ( V_37 ) ;
if ( V_37 -> type != & V_45 ) {
F_22 ( V_46
L_3 , V_47 ) ;
V_8 = - V_48 ;
goto V_21;
}
F_23 ( & V_37 -> V_49 ) ;
V_41 = V_40 ( V_37 ) ;
if ( V_41 -> V_50 != sizeof( struct V_38 ) ) {
V_8 = - V_51 ;
F_24 ( & V_37 -> V_49 ) ;
goto V_21;
}
V_39 = (struct V_38 * ) V_41 -> V_6 ;
F_25 ( V_11 != V_52 ) ;
if ( V_39 -> V_53 != V_13 ) {
F_22 ( V_46
L_4 ,
V_47 , V_39 -> V_53 ) ;
V_8 = - V_48 ;
F_24 ( & V_37 -> V_49 ) ;
goto V_21;
}
V_8 = F_3 ( V_31 -> V_54 , V_39 -> V_55 , V_32 ) ;
F_24 ( & V_37 -> V_49 ) ;
if ( V_8 )
goto V_21;
V_29 -> V_56 = V_37 ;
return 0 ;
V_21:
F_26 ( V_37 ) ;
return V_8 ;
}
static void F_27 ( struct V_28 * V_57 )
{
if ( ! V_57 )
return;
F_26 ( V_57 -> V_56 ) ;
F_17 ( V_57 -> V_58 ) ;
F_28 ( V_59 , V_57 ) ;
}
int F_29 ( struct V_60 * V_60 )
{
struct V_28 * V_29 ;
struct V_30 V_31 ;
struct V_19 * V_61 ;
const char * V_62 ;
T_1 V_32 [ V_63 ] ;
T_1 V_64 ;
int V_8 ;
V_8 = F_30 () ;
if ( V_8 )
return V_8 ;
if ( ! V_60 -> V_65 -> V_66 -> V_67 )
return - V_68 ;
V_69:
V_29 = F_31 ( V_60 -> V_70 ) ;
if ( V_29 ) {
if ( ! V_29 -> V_56 ||
F_32 ( V_29 -> V_56 ) == 0 )
return 0 ;
F_33 ( V_60 , V_29 ) ;
goto V_69;
}
V_8 = V_60 -> V_65 -> V_66 -> V_67 ( V_60 , & V_31 , sizeof( V_31 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_34 ( V_60 ) )
return V_8 ;
V_31 . V_71 = V_72 ;
V_31 . V_73 = V_74 ;
V_31 . V_75 = 0 ;
} else if ( V_8 != sizeof( V_31 ) ) {
return - V_51 ;
}
V_8 = 0 ;
V_29 = F_35 ( V_59 , V_23 ) ;
if ( ! V_29 )
return - V_24 ;
V_29 -> V_76 = V_31 . V_75 ;
V_29 -> V_77 = V_31 . V_71 ;
V_29 -> V_78 = V_31 . V_73 ;
V_29 -> V_58 = NULL ;
V_29 -> V_56 = NULL ;
memcpy ( V_29 -> V_79 , V_31 . V_44 ,
sizeof( V_29 -> V_79 ) ) ;
if ( F_36 ( V_60 -> V_80 ) )
V_64 = V_29 -> V_77 ;
else if ( F_37 ( V_60 -> V_80 ) || F_38 ( V_60 -> V_80 ) )
V_64 = V_29 -> V_78 ;
else
F_39 () ;
switch ( V_64 ) {
case V_72 :
V_62 = L_5 ;
break;
case V_74 :
V_62 = L_6 ;
break;
default:
F_22 ( V_46
L_7 ,
V_47 , V_64 , ( unsigned ) V_60 -> V_81 ) ;
V_8 = - V_48 ;
goto V_21;
}
if ( F_34 ( V_60 ) ) {
memset ( V_32 , 0x42 , V_13 ) ;
goto V_82;
}
V_8 = F_18 ( V_29 , & V_31 , V_32 ,
V_83 , V_84 ) ;
if ( V_8 && V_60 -> V_65 -> V_66 -> V_85 ) {
T_1 * V_33 = NULL ;
int V_34 , V_86 ;
V_34 = V_60 -> V_65 -> V_66 -> V_85 ( V_60 , & V_33 ) ;
V_86 = F_18 ( V_29 , & V_31 , V_32 ,
V_33 , V_34 ) ;
if ( V_86 ) {
if ( V_86 == - V_48 )
V_8 = - V_48 ;
goto V_21;
}
} else if ( V_8 ) {
goto V_21;
}
V_82:
V_61 = F_5 ( V_62 , 0 , 0 ) ;
if ( ! V_61 || F_6 ( V_61 ) ) {
V_8 = V_61 ? F_7 ( V_61 ) : - V_24 ;
F_40 ( V_87
L_8 ,
V_47 , V_8 , ( unsigned ) V_60 -> V_81 ) ;
goto V_21;
}
V_29 -> V_58 = V_61 ;
F_41 ( V_61 , ~ 0 ) ;
F_8 ( V_61 , V_22 ) ;
V_8 = F_11 ( V_61 , V_32 , F_42 ( V_64 ) ) ;
if ( V_8 )
goto V_21;
F_43 ( V_32 , sizeof( V_32 ) ) ;
if ( F_44 ( & V_60 -> V_70 , NULL , V_29 ) != NULL ) {
F_27 ( V_29 ) ;
goto V_69;
}
return 0 ;
V_21:
if ( V_8 == - V_48 )
V_8 = 0 ;
F_27 ( V_29 ) ;
F_43 ( V_32 , sizeof( V_32 ) ) ;
return V_8 ;
}
void F_33 ( struct V_60 * V_60 , struct V_28 * V_57 )
{
struct V_28 * V_88 ;
if ( V_57 == NULL )
V_57 = F_31 ( V_60 -> V_70 ) ;
if ( V_57 == NULL )
return;
V_88 = F_44 ( & V_60 -> V_70 , V_57 , NULL ) ;
if ( V_88 != V_57 )
return;
F_27 ( V_57 ) ;
}
int F_45 ( struct V_60 * V_60 )
{
struct V_28 * V_57 = V_60 -> V_70 ;
if ( ! V_57 ||
( V_57 -> V_56 &&
( V_57 -> V_56 -> V_75 & ( ( 1 << V_89 ) |
( 1 << V_90 ) |
( 1 << V_91 ) ) ) ) )
return F_29 ( V_60 ) ;
return 0 ;
}
