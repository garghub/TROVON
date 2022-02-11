static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ) ;
F_3 ( V_2 -> V_3 . V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = & V_2 -> V_3 ;
struct V_1 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_10 = & V_3 -> V_11 [ V_7 ] ;
if ( V_10 -> V_12 )
F_5 ( V_3 -> V_4 , V_10 -> V_12 ) ;
}
if ( V_2 -> V_13 ) {
switch ( V_3 -> V_4 -> V_14 ) {
case V_15 :
F_6 ( V_2 -> V_13 ) ;
break;
default:
break;
}
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_16 ) ;
V_6 = F_10 ( V_3 -> V_4 -> V_17 ) ;
F_11 ( V_2 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
char V_18 [ V_19 ] ;
unsigned long V_20 , V_21 = 0 ;
if ( F_13 ( V_2 , V_22 ) )
goto V_23;
if ( F_13 ( V_2 , L_1 ) )
goto V_23;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_25 , 0 ) ;
if ( F_14 ( V_2 , V_22 , V_18 ,
( void * ) & V_21 , V_26 ) )
goto V_23;
V_20 = V_21 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_27 , 0 ) ;
if ( F_14 ( V_2 , V_22 , V_18 ,
( void * ) & V_20 , V_26 ) )
goto V_23;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_28 , 0 ) ;
V_20 = 128 ;
if ( F_14 ( V_2 , V_22 , V_18 ,
( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 512 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_29 , 0 ) ;
if ( F_14 ( V_2 , V_22 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 0 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_30 , 0 ) ;
if ( F_14 ( V_2 , V_22 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 2 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_31 , 0 ) ;
if ( F_14 ( V_2 , V_22 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 8 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_32 , 0 ) ;
if ( F_14 ( V_2 , V_22 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 10 ;
snprintf ( V_18 , sizeof( V_18 ) , V_24 L_2 V_33 , 0 ) ;
if ( F_14 ( V_2 , V_22 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = V_34 ;
snprintf ( V_18 , sizeof( V_18 ) , V_35 ,
( int ) V_21 ) ;
if ( F_14 ( V_2 , L_1 ,
V_18 , ( void * ) & V_20 , V_26 ) )
goto V_23;
V_20 = 1 ;
if ( F_14 ( V_2 , V_22 ,
V_36 , ( void * ) & V_20 , V_26 ) )
goto V_23;
F_15 ( V_37 , & V_2 -> V_38 ) ;
return 0 ;
V_23:
F_16 ( & F_17 ( V_2 ) , L_3 ) ;
return - V_39 ;
}
static int F_18 ( struct V_4 * V_40 , const struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_1 * V_6 ;
struct V_5 * V_3 ;
struct V_43 * V_44 ;
char V_45 [ V_46 ] ;
unsigned int V_7 , V_47 ;
int V_48 , V_49 ;
switch ( V_42 -> V_14 ) {
case V_15 :
break;
default:
F_16 ( & V_40 -> V_50 , L_4 , V_42 -> V_14 ) ;
return - V_51 ;
}
V_2 = F_19 ( sizeof( * V_2 ) , V_52 ,
F_20 ( & V_40 -> V_50 ) ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_54 = true ;
V_6 = F_10 ( V_40 -> V_17 ) ;
V_3 = & V_2 -> V_3 ;
V_3 -> V_4 = V_40 ;
if ( F_21 ( V_2 , V_6 ) ) {
F_16 ( & V_40 -> V_50 , L_5 ) ;
F_7 ( V_2 ) ;
return - V_55 ;
}
F_22 ( & V_2 -> V_56 ) ;
V_2 -> V_57 = V_58 ;
V_44 = F_19 ( sizeof( * V_44 ) , V_52 ,
F_20 ( & V_40 -> V_50 ) ) ;
if ( ! V_44 ) {
V_48 = - V_53 ;
goto V_59;
}
V_2 -> V_13 = V_44 ;
switch ( V_42 -> V_14 ) {
case V_15 :
F_23 ( V_2 -> V_13 ) ;
break;
default:
V_48 = - V_51 ;
goto V_59;
}
V_44 -> V_60 = V_44 -> V_61 ( V_44 -> V_62 ) ;
V_44 -> V_63 = V_44 -> V_64 ( V_44 -> V_62 ) ;
V_3 -> V_65 = V_44 -> V_66 ( V_44 ) ;
snprintf ( V_45 , sizeof( V_45 ) , L_6 ,
V_67 , V_44 -> V_68 -> V_45 ,
V_40 -> V_69 -> V_70 , F_24 ( V_40 -> V_71 ) ,
F_25 ( V_40 -> V_71 ) ) ;
V_2 -> V_16 = F_26 ( V_45 , NULL ) ;
if ( ! V_2 -> V_16 ) {
F_16 ( & V_40 -> V_50 , L_7 , V_45 ) ;
V_48 = - V_39 ;
goto V_59;
}
V_48 = F_27 ( V_2 ) ;
if ( V_48 )
goto V_59;
if ( F_28 ( V_40 ) ) {
V_48 = - V_55 ;
goto V_59;
}
if ( F_29 ( V_40 , F_30 ( 64 ) ) ) {
if ( ( F_29 ( V_40 , F_30 ( 32 ) ) ) ) {
F_16 ( & V_40 -> V_50 , L_8 ) ;
V_48 = - V_55 ;
goto V_72;
} else {
F_31 ( V_40 , F_30 ( 32 ) ) ;
}
} else {
F_31 ( V_40 , F_30 ( 64 ) ) ;
}
if ( F_32 ( V_40 , V_73 ) ) {
V_48 = - V_55 ;
goto V_72;
}
V_7 = 0 ;
V_49 = F_33 ( V_40 , V_74 ) ;
F_34 (bar_nr, (const unsigned long *)&bar_mask,
ADF_PCI_MAX_BARS * 2 ) {
struct V_9 * V_10 = & V_3 -> V_11 [ V_7 ++ ] ;
V_10 -> V_75 = F_35 ( V_40 , V_47 ) ;
if ( ! V_10 -> V_75 )
break;
V_10 -> V_76 = F_36 ( V_40 , V_47 ) ;
V_10 -> V_12 = F_37 ( V_3 -> V_4 , V_47 , 0 ) ;
if ( ! V_10 -> V_12 ) {
F_16 ( & V_40 -> V_50 , L_9 , V_47 ) ;
V_48 = - V_55 ;
goto V_77;
}
}
F_38 ( V_40 ) ;
F_39 ( & V_2 -> V_78 . V_79 ) ;
V_48 = F_12 ( V_2 ) ;
if ( V_48 )
goto V_77;
V_48 = F_40 ( V_2 ) ;
if ( V_48 )
goto V_80;
V_48 = F_41 ( V_2 ) ;
if ( V_48 )
goto V_81;
return V_48 ;
V_81:
F_42 ( V_2 ) ;
V_80:
F_43 ( V_2 ) ;
V_77:
F_2 ( V_3 -> V_4 ) ;
V_72:
F_3 ( V_3 -> V_4 ) ;
V_59:
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
return V_48 ;
}
static void F_44 ( struct V_4 * V_40 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
if ( ! V_2 ) {
F_45 ( L_10 ) ;
return;
}
if ( F_42 ( V_2 ) )
F_16 ( & F_17 ( V_2 ) , L_11 ) ;
F_43 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int T_1 F_46 ( void )
{
F_47 ( L_12 ) ;
if ( F_48 ( & V_82 ) ) {
F_45 ( L_13 ) ;
return - V_55 ;
}
return 0 ;
}
static void T_2 F_49 ( void )
{
F_50 ( & V_82 ) ;
F_51 ( true ) ;
}
