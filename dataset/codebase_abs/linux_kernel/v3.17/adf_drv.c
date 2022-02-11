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
static T_1 F_13 ( struct V_11 * V_16 )
{
unsigned int V_17 = 0 ;
struct V_18 * V_19 = & F_14 ( F_15 () - 1 ) ;
if ( ! V_19 -> V_20 )
return 0 ;
V_17 = 256 / ( V_19 -> V_20 + 1 ) ;
if ( V_17 != 0 )
return V_16 -> V_21 -> V_22 / V_17 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_23 = F_15 () ;
int V_24 = F_17 ( V_2 ) ;
int V_25 = F_18 ( V_23 , V_24 ) ;
char V_26 [ V_27 ] ;
int V_5 ;
unsigned long V_28 ;
if ( F_19 ( V_2 , V_29 ) )
goto V_30;
if ( F_19 ( V_2 , L_1 ) )
goto V_30;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
V_28 = V_5 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_32 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_34 ,
V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_35 , V_5 ) ;
V_28 = 128 ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 512 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_36 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 0 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_37 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 2 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_38 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 4 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_39 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 8 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_40 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 10 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_41 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = 12 ;
snprintf ( V_26 , sizeof( V_26 ) , V_31 L_2 V_42 , V_5 ) ;
if ( F_20 ( V_2 , V_29 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
V_28 = V_43 ;
snprintf ( V_26 , sizeof( V_26 ) , V_44 , V_5 ) ;
if ( F_20 ( V_2 , L_1 ,
V_26 , ( void * ) & V_28 , V_33 ) )
goto V_30;
}
V_28 = V_5 ;
if ( F_20 ( V_2 , V_29 ,
V_45 , ( void * ) & V_28 , V_33 ) )
goto V_30;
F_21 ( V_46 , & V_2 -> V_47 ) ;
return F_22 ( V_2 ) ;
V_30:
F_23 ( & F_24 ( V_2 ) , L_3 ) ;
return - V_48 ;
}
static int F_25 ( struct V_11 * V_16 , const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
void T_2 * V_53 = NULL ;
char V_54 [ V_55 ] ;
unsigned int V_5 , V_56 ;
T_1 V_57 ;
int V_58 ;
switch ( V_50 -> V_59 ) {
case V_14 :
break;
default:
F_23 ( & V_16 -> V_60 , L_4 , V_50 -> V_59 ) ;
return - V_61 ;
}
V_57 = F_13 ( V_16 ) ;
V_2 = F_26 ( sizeof( * V_2 ) , V_62 , V_57 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_64 = V_57 ;
F_27 ( & V_2 -> V_65 ) ;
if ( F_28 ( V_2 ) ) {
F_23 ( & V_16 -> V_60 , L_5 ) ;
F_7 ( V_2 ) ;
return - V_66 ;
}
V_2 -> V_67 = V_68 ;
V_52 = F_26 ( sizeof( * V_52 ) , V_62 , V_57 ) ;
if ( ! V_52 ) {
V_58 = - V_63 ;
goto V_69;
}
V_2 -> V_12 = V_52 ;
switch ( V_50 -> V_59 ) {
case V_14 :
F_29 ( V_2 -> V_12 ) ;
break;
default:
return - V_61 ;
}
V_4 = & V_2 -> V_4 ;
F_30 ( V_16 , V_70 , & V_4 -> V_71 ) ;
F_31 ( V_16 , V_72 ,
& V_52 -> V_73 ) ;
V_52 -> V_74 = V_52 -> V_75 ( V_52 -> V_73 ) ;
V_52 -> V_76 = V_52 -> V_77 ( V_52 -> V_73 ) ;
V_4 -> V_78 = V_52 -> V_79 ( V_52 ) ;
V_4 -> V_11 = V_16 ;
if ( ! V_52 -> V_74 || ! V_52 -> V_76 ||
( ( ~ V_52 -> V_76 ) & 0x01 ) ) {
F_23 ( & V_16 -> V_60 , L_6 ) ;
V_58 = - V_66 ;
goto V_69;
}
snprintf ( V_54 , sizeof( V_54 ) , L_7 , V_80 ,
V_52 -> V_81 -> V_54 , V_52 -> V_82 ) ;
V_2 -> V_15 = F_32 ( V_54 , NULL ) ;
if ( ! V_2 -> V_15 ) {
F_23 ( & V_16 -> V_60 , L_8 ) ;
V_58 = - V_48 ;
goto V_69;
}
V_58 = F_33 ( V_2 ) ;
if ( V_58 )
goto V_69;
if ( F_34 ( V_16 ) ) {
V_58 = - V_66 ;
goto V_69;
}
if ( F_35 ( V_16 , F_36 ( 64 ) ) ) {
if ( ( F_35 ( V_16 , F_36 ( 32 ) ) ) ) {
F_23 ( & V_16 -> V_60 , L_9 ) ;
V_58 = - V_66 ;
goto V_69;
} else {
F_37 ( V_16 , F_36 ( 32 ) ) ;
}
} else {
F_37 ( V_16 , F_36 ( 64 ) ) ;
}
if ( F_38 ( V_16 , V_83 ) ) {
V_58 = - V_66 ;
goto V_69;
}
F_31 ( V_16 , V_84 ,
& V_52 -> V_85 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
V_56 = V_5 * 2 ;
V_8 -> V_86 = F_39 ( V_16 , V_56 ) ;
if ( ! V_8 -> V_86 )
break;
V_8 -> V_87 = F_40 ( V_16 , V_56 ) ;
V_8 -> V_10 = F_41 ( V_4 -> V_11 , V_56 , 0 ) ;
if ( ! V_8 -> V_10 ) {
F_23 ( & V_16 -> V_60 , L_10 , V_5 ) ;
V_58 = - V_66 ;
goto V_69;
}
if ( V_5 == V_88 )
V_53 = V_8 -> V_10 ;
}
F_42 ( V_16 ) ;
if ( F_43 ( V_2 , & V_89 ) ) {
F_23 ( & V_16 -> V_60 , L_11 ) ;
V_58 = - V_66 ;
goto V_69;
}
if ( F_44 ( V_2 ) ) {
F_23 ( & V_16 -> V_60 , L_12 ) ;
V_58 = - V_66 ;
goto V_69;
}
if ( F_45 ( V_2 ) ) {
F_23 ( & V_16 -> V_60 , L_13 ) ;
V_58 = - V_66 ;
goto V_69;
}
if ( F_46 ( V_2 ) ) {
F_23 ( & V_16 -> V_60 , L_14 ) ;
V_58 = - V_66 ;
goto V_69;
}
if ( F_47 ( V_16 ) ) {
F_23 ( & V_16 -> V_60 , L_15 ) ;
V_58 = - V_63 ;
goto V_69;
}
F_48 ( V_53 , V_90 ,
V_91 ) ;
F_48 ( V_53 , V_92 ,
V_93 ) ;
V_58 = F_16 ( V_2 ) ;
if ( V_58 ) {
F_49 ( V_2 ) ;
goto V_69;
}
return 0 ;
V_69:
F_1 ( V_2 ) ;
return V_58 ;
}
static void T_3 F_50 ( struct V_11 * V_16 )
{
struct V_1 * V_2 = F_51 ( V_16 ) ;
if ( ! V_2 ) {
F_52 ( L_16 ) ;
return;
}
if ( F_49 ( V_2 ) )
F_23 ( & F_24 ( V_2 ) , L_17 ) ;
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int T_4 F_54 ( void )
{
F_55 ( L_18 ) ;
if ( F_56 () )
return - V_66 ;
if ( F_57 ( & V_89 ) ) {
F_52 ( L_19 ) ;
return - V_66 ;
}
return 0 ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_89 ) ;
F_60 () ;
}
