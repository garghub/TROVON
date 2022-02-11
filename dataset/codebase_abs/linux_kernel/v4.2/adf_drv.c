static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
F_2 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
if ( V_8 -> V_10 )
F_3 ( V_4 -> V_11 , V_8 -> V_10 ) ;
}
if ( V_2 -> V_12 ) {
switch ( V_2 -> V_12 -> V_13 ) {
case V_14 :
F_4 ( V_2 -> V_12 ) ;
break;
default:
break;
}
F_5 ( V_2 -> V_12 ) ;
}
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_15 ) ;
F_8 ( V_2 ) ;
F_9 ( V_4 -> V_11 ) ;
F_10 ( V_4 -> V_11 ) ;
F_5 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_16 = F_12 () ;
int V_17 = F_13 ( V_2 ) ;
int V_18 = F_14 ( V_16 , V_17 ) ;
char V_19 [ V_20 ] ;
int V_5 ;
unsigned long V_21 ;
if ( F_15 ( V_2 , V_22 ) )
goto V_23;
if ( F_15 ( V_2 , L_1 ) )
goto V_23;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ ) {
V_21 = V_5 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_25 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_27 ,
V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_28 , V_5 ) ;
V_21 = 128 ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 512 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_29 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 0 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_30 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 2 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_31 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 4 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_32 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 8 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_33 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 10 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_34 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = 12 ;
snprintf ( V_19 , sizeof( V_19 ) , V_24 L_2 V_35 , V_5 ) ;
if ( F_16 ( V_2 , V_22 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
V_21 = V_36 ;
snprintf ( V_19 , sizeof( V_19 ) , V_37 , V_5 ) ;
if ( F_16 ( V_2 , L_1 ,
V_19 , ( void * ) & V_21 , V_26 ) )
goto V_23;
}
V_21 = V_5 ;
if ( F_16 ( V_2 , V_22 ,
V_38 , ( void * ) & V_21 , V_26 ) )
goto V_23;
F_17 ( V_39 , & V_2 -> V_40 ) ;
return 0 ;
V_23:
F_18 ( & F_19 ( V_2 ) , L_3 ) ;
return - V_41 ;
}
static int F_20 ( struct V_11 * V_42 , const struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
char V_47 [ V_48 ] ;
unsigned int V_5 , V_49 ;
int V_50 ;
switch ( V_44 -> V_51 ) {
case V_14 :
break;
default:
F_18 ( & V_42 -> V_52 , L_4 , V_44 -> V_51 ) ;
return - V_53 ;
}
if ( F_21 () > 1 && F_22 ( & V_42 -> V_52 ) < 0 ) {
F_18 ( & V_42 -> V_52 , L_5 ) ;
return - V_41 ;
}
V_2 = F_23 ( sizeof( * V_2 ) , V_54 ,
F_22 ( & V_42 -> V_52 ) ) ;
if ( ! V_2 )
return - V_55 ;
F_24 ( & V_2 -> V_56 ) ;
if ( F_25 ( V_2 ) ) {
F_18 ( & V_42 -> V_52 , L_6 ) ;
F_5 ( V_2 ) ;
return - V_57 ;
}
V_2 -> V_58 = V_59 ;
V_46 = F_23 ( sizeof( * V_46 ) , V_54 ,
F_22 ( & V_42 -> V_52 ) ) ;
if ( ! V_46 ) {
V_50 = - V_55 ;
goto V_60;
}
V_2 -> V_12 = V_46 ;
switch ( V_44 -> V_51 ) {
case V_14 :
F_26 ( V_2 -> V_12 ) ;
break;
default:
return - V_53 ;
}
V_4 = & V_2 -> V_4 ;
F_27 ( V_42 , V_61 , & V_4 -> V_62 ) ;
F_28 ( V_42 , V_63 ,
& V_46 -> V_64 ) ;
V_46 -> V_65 = V_46 -> V_66 ( V_46 -> V_64 ) ;
V_46 -> V_67 = V_46 -> V_68 ( V_46 -> V_64 ) ;
V_4 -> V_69 = V_46 -> V_70 ( V_46 ) ;
V_4 -> V_11 = V_42 ;
if ( ! V_46 -> V_65 || ! V_46 -> V_67 ||
( ( ~ V_46 -> V_67 ) & 0x01 ) ) {
F_18 ( & V_42 -> V_52 , L_7 ) ;
V_50 = - V_57 ;
goto V_60;
}
snprintf ( V_47 , sizeof( V_47 ) , L_8 , V_71 ,
V_46 -> V_72 -> V_47 , V_46 -> V_73 ) ;
V_2 -> V_15 = F_29 ( V_47 , NULL ) ;
if ( ! V_2 -> V_15 ) {
F_18 ( & V_42 -> V_52 , L_9 ) ;
V_50 = - V_41 ;
goto V_60;
}
V_50 = F_30 ( V_2 ) ;
if ( V_50 )
goto V_60;
F_31 ( V_42 , 1024 ) ;
if ( F_32 ( V_42 ) ) {
V_50 = - V_57 ;
goto V_60;
}
if ( F_33 ( V_42 , F_34 ( 64 ) ) ) {
if ( ( F_33 ( V_42 , F_34 ( 32 ) ) ) ) {
F_18 ( & V_42 -> V_52 , L_10 ) ;
V_50 = - V_57 ;
goto V_60;
} else {
F_35 ( V_42 , F_34 ( 32 ) ) ;
}
} else {
F_35 ( V_42 , F_34 ( 64 ) ) ;
}
if ( F_36 ( V_42 , V_74 ) ) {
V_50 = - V_57 ;
goto V_60;
}
F_28 ( V_42 , V_75 ,
& V_46 -> V_76 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
V_49 = V_5 * 2 ;
V_8 -> V_77 = F_37 ( V_42 , V_49 ) ;
if ( ! V_8 -> V_77 )
break;
V_8 -> V_78 = F_38 ( V_42 , V_49 ) ;
V_8 -> V_10 = F_39 ( V_4 -> V_11 , V_49 , 0 ) ;
if ( ! V_8 -> V_10 ) {
F_18 ( & V_42 -> V_52 , L_11 , V_5 ) ;
V_50 = - V_57 ;
goto V_60;
}
}
F_40 ( V_42 ) ;
if ( F_41 ( V_2 , & V_79 ) ) {
F_18 ( & V_42 -> V_52 , L_12 ) ;
V_50 = - V_57 ;
goto V_60;
}
if ( F_42 ( V_42 ) ) {
F_18 ( & V_42 -> V_52 , L_13 ) ;
V_50 = - V_55 ;
goto V_60;
}
V_50 = F_11 ( V_2 ) ;
if ( V_50 )
goto V_60;
V_50 = F_43 ( V_2 ) ;
if ( V_50 )
goto V_60;
V_50 = F_44 ( V_2 ) ;
if ( V_50 ) {
F_45 ( V_2 ) ;
goto V_60;
}
return 0 ;
V_60:
F_1 ( V_2 ) ;
return V_50 ;
}
static void F_46 ( struct V_11 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
if ( ! V_2 ) {
F_48 ( L_14 ) ;
return;
}
if ( F_45 ( V_2 ) )
F_18 ( & F_19 ( V_2 ) , L_15 ) ;
F_49 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int T_1 F_50 ( void )
{
F_51 ( L_16 ) ;
if ( F_52 () )
return - V_57 ;
if ( F_53 ( & V_79 ) ) {
F_48 ( L_17 ) ;
return - V_57 ;
}
return 0 ;
}
static void T_2 F_54 ( void )
{
F_55 ( & V_79 ) ;
F_56 () ;
}
