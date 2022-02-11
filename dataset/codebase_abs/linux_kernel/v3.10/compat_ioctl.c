static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
F_2 ( V_8 , & V_7 ) ;
V_5 . V_9 . V_10 = V_7 . V_9 . V_10 ;
V_5 . V_9 . V_11 = V_7 . V_9 . V_11 ;
V_5 . V_12 = V_7 . V_13 -> V_14 |
( V_7 . V_13 -> V_13 << 16 ) ;
V_5 . V_15 = V_7 . V_16 ;
V_5 . V_17 = ( V_18 ) V_7 . V_17 ;
V_5 . V_19 = V_7 . V_19 ;
V_5 . V_20 = V_5 . V_21 = V_7 . V_22 ;
V_5 . V_23 = V_7 . V_24 ;
if ( F_3 ( V_3 , & V_5 , sizeof( V_5 ) ) )
return - V_25 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_26 V_27 ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_32 ;
F_5 ( L_1 ) ;
if ( F_6 ( & V_27 , V_3 , sizeof( V_27 ) ) )
return - V_25 ;
if ( ( unsigned ) V_27 . V_33 >= ~ 0U / sizeof( struct V_34 ) )
return - V_25 ;
V_29 . V_35 = V_27 . V_35 ;
V_29 . V_33 = V_27 . V_33 ;
V_31 = F_7 ( V_29 . V_35 ) ;
if ( V_29 . V_33 == 0 ) {
V_32 = F_8 ( V_29 . V_35 ) ;
if ( V_32 != NULL ) {
F_9 ( V_36 , & V_32 -> V_37 ) ;
F_9 ( V_38 , & V_32 -> V_37 ) ;
}
if ( V_31 == NULL ) {
return 0 ;
}
return F_10 ( V_29 . V_35 ) ;
} else {
struct V_34 * V_39 ;
struct V_40 * V_41 ;
int V_42 ;
if ( V_27 . V_33 >= 16384 )
return - V_43 ;
V_39 = F_11 ( sizeof( * V_39 ) * V_27 . V_33 , V_44 ) ;
if ( ! V_39 )
return - V_45 ;
V_41 = F_11 ( sizeof( * V_41 ) * V_29 . V_33 , V_44 ) ;
if ( ! V_41 ) {
F_12 ( V_39 ) ;
return - V_45 ;
}
if ( F_6 ( V_39 , ( void T_1 * ) V_27 . V_46 ,
sizeof( * V_39 ) * V_27 . V_33 ) ) {
F_12 ( V_39 ) ;
F_12 ( V_41 ) ;
return - V_25 ;
}
for ( V_42 = 0 ; V_42 < V_27 . V_33 ; V_42 ++ ) {
V_41 [ V_42 ] . V_47 = V_39 [ V_42 ] . V_47 ;
V_41 [ V_42 ] . V_48 = V_39 [ V_42 ] . V_48 ;
V_41 [ V_42 ] . V_49 = V_39 [ V_42 ] . V_49 ;
}
F_12 ( V_39 ) ;
V_29 . V_46 = V_41 ;
if ( V_31 == NULL ) {
V_31 = F_13 ( V_29 . V_35 ) ;
if ( V_31 == NULL ) {
F_12 ( V_41 ) ;
return - V_45 ;
}
V_32 = F_8 ( V_29 . V_35 ) ;
if ( V_32 != NULL ) {
F_9 ( V_36 , & V_32 -> V_37 ) ;
F_9 ( V_38 , & V_32 -> V_37 ) ;
}
}
return F_14 ( V_31 , & V_29 ) ;
}
return - V_43 ;
}
static int F_15 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_50 * V_51 ;
struct V_52 V_53 ;
F_5 ( L_1 ) ;
if ( F_6 ( & V_53 , V_3 , sizeof( V_53 ) ) )
return - V_25 ;
V_51 = F_16 ( V_53 . V_48 , V_53 . type ) ;
if ( V_51 == NULL )
return - V_45 ;
V_53 . V_54 = V_51 -> V_54 ;
V_53 . V_55 = V_51 -> V_55 ;
if ( F_3 ( V_3 , & V_53 , sizeof( V_53 ) ) ) {
F_17 ( V_51 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_56 V_57 ;
struct V_50 * V_51 ;
F_5 ( L_1 ) ;
if ( F_6 ( & V_57 , V_3 , sizeof( V_57 ) ) )
return - V_25 ;
V_51 = F_19 ( V_57 . V_54 ) ;
if ( V_51 == NULL )
return - V_43 ;
return F_20 ( V_51 , V_57 . V_47 ) ;
}
static int F_21 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_50 * V_51 ;
struct V_58 V_59 ;
F_5 ( L_1 ) ;
if ( F_6 ( & V_59 , V_3 , sizeof( V_59 ) ) )
return - V_25 ;
V_51 = F_19 ( V_59 . V_54 ) ;
if ( V_51 == NULL )
return - V_43 ;
return F_22 ( V_51 ) ;
}
long F_23 ( struct V_60 * V_60 , unsigned int V_61 , unsigned long V_3 )
{
struct V_1 * V_62 = V_60 -> V_63 ;
int V_64 = - V_65 ;
F_24 ( & ( V_66 . V_67 ) ) ;
if ( ( V_66 . V_68 == NULL ) &&
( V_61 != V_69 ) ) {
V_64 = - V_43 ;
goto V_70;
}
if ( ( V_66 . V_71 != true ) &&
( V_61 != V_69 ) ) {
V_64 = - V_72 ;
goto V_70;
}
if ( V_61 != V_69 ) {
if ( ! ( F_25 ( V_73 , & V_62 -> V_37 ) ) ) {
V_64 = - V_74 ;
goto V_70;
}
if ( V_66 . V_68 -> V_35 != V_62 -> V_75 ) {
V_64 = - V_72 ;
goto V_70;
}
}
switch ( V_61 ) {
case V_76 :
V_64 = F_1 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_69 :
V_64 = F_26 ( V_62 ) ;
break;
case V_77 :
V_64 = F_27 ( V_62 ) ;
break;
case V_78 :
V_64 = F_28 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_79 :
V_64 = F_4 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_80 :
V_64 = F_29 ( V_62 ) ;
break;
case V_81 :
V_64 = F_15 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_82 :
V_64 = F_30 ( V_62 , ( int ) V_3 ) ;
break;
case V_83 :
V_64 = F_18 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_84 :
V_64 = F_21 ( V_62 , ( void T_1 * ) V_3 ) ;
break;
case V_85 :
break;
}
V_70:
F_5 ( L_2 , V_64 ) ;
F_31 ( & ( V_66 . V_67 ) ) ;
return V_64 ;
}
