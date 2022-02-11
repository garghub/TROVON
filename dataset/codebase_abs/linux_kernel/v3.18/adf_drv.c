static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
if ( V_8 -> V_10 )
F_5 ( V_4 -> V_11 , V_8 -> V_10 ) ;
}
if ( V_2 -> V_12 ) {
switch ( V_2 -> V_12 -> V_13 ) {
case V_14 :
F_6 ( V_2 -> V_12 ) ;
break;
default:
break;
}
F_7 ( V_2 -> V_12 ) ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_15 ) ;
F_10 ( V_2 ) ;
F_11 ( V_4 -> V_11 ) ;
F_12 ( V_4 -> V_11 ) ;
F_7 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_16 = F_14 () ;
int V_17 = F_15 ( V_2 ) ;
int V_18 = F_16 ( V_16 , V_17 ) ;
char V_19 [ V_20 ] ;
int V_5 ;
unsigned long V_21 ;
if ( F_17 ( V_2 , V_22 ) )
goto V_23;
if ( F_17 ( V_2 , L_1 ) )
goto V_23;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ ) {
V_21 = V_5 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_25 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_27 ,
V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_28 , V_5 ) ;
V_21 = 128 ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 512 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_29 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 0 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_30 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 2 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_31 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 4 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_32 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 8 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_33 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 10 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_34 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 12 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_35 , V_5 ) ;
if ( F_18 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = V_36 ;
snprintf ( V_19 , sizeof( V_19 ) , V_37 , V_5 ) ;
if ( F_18 ( V_2 , L_1 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
}
V_21 = V_5 ;
if ( F_18 ( V_2 , V_22 ,
V_38 , ( void * ) & V_21 , V_26 ) )
goto V_23;
F_19 ( V_39 , & V_2 -> V_40 ) ;
return F_20 ( V_2 ) ;
V_23:
F_21 ( & F_22 ( V_2 ) , L_3 ) ;
return - V_41 ;
}
static int F_23 ( struct V_11 * V_42 , const struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
void T_1 * V_47 = NULL ;
char V_48 [ V_49 ] ;
unsigned int V_5 , V_50 ;
int V_51 ;
switch ( V_44 -> V_52 ) {
case V_14 :
break;
default:
F_21 ( & V_42 -> V_53 , L_4 , V_44 -> V_52 ) ;
return - V_54 ;
}
if ( F_24 () > 1 && F_25 ( & V_42 -> V_53 ) < 0 ) {
F_21 ( & V_42 -> V_53 , L_5 ) ;
return - V_41 ;
}
V_2 = F_26 ( sizeof( * V_2 ) , V_55 ,
F_25 ( & V_42 -> V_53 ) ) ;
if ( ! V_2 )
return - V_56 ;
F_27 ( & V_2 -> V_57 ) ;
if ( F_28 ( V_2 ) ) {
F_21 ( & V_42 -> V_53 , L_6 ) ;
F_7 ( V_2 ) ;
return - V_58 ;
}
V_2 -> V_59 = V_60 ;
V_46 = F_26 ( sizeof( * V_46 ) , V_55 ,
F_25 ( & V_42 -> V_53 ) ) ;
if ( ! V_46 ) {
V_51 = - V_56 ;
goto V_61;
}
V_2 -> V_12 = V_46 ;
switch ( V_44 -> V_52 ) {
case V_14 :
F_29 ( V_2 -> V_12 ) ;
break;
default:
return - V_54 ;
}
V_4 = & V_2 -> V_4 ;
F_30 ( V_42 , V_62 , & V_4 -> V_63 ) ;
F_31 ( V_42 , V_64 ,
& V_46 -> V_65 ) ;
V_46 -> V_66 = V_46 -> V_67 ( V_46 -> V_65 ) ;
V_46 -> V_68 = V_46 -> V_69 ( V_46 -> V_65 ) ;
V_4 -> V_70 = V_46 -> V_71 ( V_46 ) ;
V_4 -> V_11 = V_42 ;
if ( ! V_46 -> V_66 || ! V_46 -> V_68 ||
( ( ~ V_46 -> V_68 ) & 0x01 ) ) {
F_21 ( & V_42 -> V_53 , L_7 ) ;
V_51 = - V_58 ;
goto V_61;
}
snprintf ( V_48 , sizeof( V_48 ) , L_8 , V_72 ,
V_46 -> V_73 -> V_48 , V_46 -> V_74 ) ;
V_2 -> V_15 = F_32 ( V_48 , NULL ) ;
if ( ! V_2 -> V_15 ) {
F_21 ( & V_42 -> V_53 , L_9 ) ;
V_51 = - V_41 ;
goto V_61;
}
V_51 = F_33 ( V_2 ) ;
if ( V_51 )
goto V_61;
if ( F_34 ( V_42 ) ) {
V_51 = - V_58 ;
goto V_61;
}
if ( F_35 ( V_42 , F_36 ( 64 ) ) ) {
if ( ( F_35 ( V_42 , F_36 ( 32 ) ) ) ) {
F_21 ( & V_42 -> V_53 , L_10 ) ;
V_51 = - V_58 ;
goto V_61;
} else {
F_37 ( V_42 , F_36 ( 32 ) ) ;
}
} else {
F_37 ( V_42 , F_36 ( 64 ) ) ;
}
if ( F_38 ( V_42 , V_75 ) ) {
V_51 = - V_58 ;
goto V_61;
}
F_31 ( V_42 , V_76 ,
& V_46 -> V_77 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
V_50 = V_5 * 2 ;
V_8 -> V_78 = F_39 ( V_42 , V_50 ) ;
if ( ! V_8 -> V_78 )
break;
V_8 -> V_79 = F_40 ( V_42 , V_50 ) ;
V_8 -> V_10 = F_41 ( V_4 -> V_11 , V_50 , 0 ) ;
if ( ! V_8 -> V_10 ) {
F_21 ( & V_42 -> V_53 , L_11 , V_5 ) ;
V_51 = - V_58 ;
goto V_61;
}
if ( V_5 == V_80 )
V_47 = V_8 -> V_10 ;
}
F_42 ( V_42 ) ;
if ( F_43 ( V_2 , & V_81 ) ) {
F_21 ( & V_42 -> V_53 , L_12 ) ;
V_51 = - V_58 ;
goto V_61;
}
if ( F_44 ( V_2 ) ) {
F_21 ( & V_42 -> V_53 , L_13 ) ;
V_51 = - V_58 ;
goto V_61;
}
if ( F_45 ( V_2 ) ) {
F_21 ( & V_42 -> V_53 , L_14 ) ;
V_51 = - V_58 ;
goto V_61;
}
if ( F_46 ( V_2 ) ) {
F_21 ( & V_42 -> V_53 , L_15 ) ;
V_51 = - V_58 ;
goto V_61;
}
if ( F_47 ( V_42 ) ) {
F_21 ( & V_42 -> V_53 , L_16 ) ;
V_51 = - V_56 ;
goto V_61;
}
F_48 ( V_47 , V_82 ,
V_83 ) ;
F_48 ( V_47 , V_84 ,
V_85 ) ;
V_51 = F_13 ( V_2 ) ;
if ( V_51 ) {
F_49 ( V_2 ) ;
goto V_61;
}
return 0 ;
V_61:
F_1 ( V_2 ) ;
return V_51 ;
}
static void T_2 F_50 ( struct V_11 * V_42 )
{
struct V_1 * V_2 = F_51 ( V_42 ) ;
if ( ! V_2 ) {
F_52 ( L_17 ) ;
return;
}
if ( F_49 ( V_2 ) )
F_21 ( & F_22 ( V_2 ) , L_18 ) ;
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int T_3 F_54 ( void )
{
F_55 ( L_19 ) ;
if ( F_56 () )
return - V_58 ;
if ( F_57 ( & V_81 ) ) {
F_52 ( L_20 ) ;
return - V_58 ;
}
return 0 ;
}
static void T_2 F_58 ( void )
{
F_59 ( & V_81 ) ;
F_60 () ;
}
