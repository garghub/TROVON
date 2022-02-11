static void F_1 ( int V_1 , struct V_2 * V_3 )
{
F_2 ( V_4 , V_1 ) ;
}
static int F_3 ( void )
{
int V_5 ;
V_5 = ! ! F_4 ( V_6 ) ;
return V_5 ;
}
T_1 F_5 ( int V_7 , void * V_8 )
{
F_6 ( V_9 L_1 ,
F_3 () ? L_2 : L_3 ) ;
return V_10 ;
}
static int T_2 F_7 ( void )
{
int V_11 ;
V_11 = F_8 ( F_9 ( V_12 ) ) ;
if ( V_11 )
goto V_13;
V_11 = F_10 ( F_11 ( V_6 ) , F_5 ,
V_14 | V_15 ,
L_4 , NULL ) ;
if ( V_11 )
goto V_16;
F_12 ( V_17 , 1 ) ;
return 0 ;
V_16:
F_6 ( V_18 L_5 ) ;
F_13 ( F_9 ( V_12 ) ) ;
V_13:
F_6 ( V_18 L_6 ) ;
return V_11 ;
}
static void F_14 ( void )
{
F_15 ( F_11 ( V_6 ) , NULL ) ;
F_13 ( F_9 ( V_12 ) ) ;
}
static int F_16 ( void )
{
return ! F_4 ( V_19 ) ;
}
static void F_17 ( void )
{
int V_20 ;
T_3 * V_21 = F_18 ( V_22 ) ;
T_3 * V_23 = & V_24 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_21 [ V_20 ] = V_23 [ V_20 ] ;
}
static int F_19 ( void )
{
int V_20 = 0 , V_26 ;
T_3 * V_27 = F_18 ( V_22 ) ;
T_3 * V_28 = F_18 ( V_29 ) ;
T_3 * V_30 = F_18 ( V_31 ) ;
T_3 * V_32 = F_18 ( V_33 ) ;
V_26 = ! ! F_4 ( V_34 ) ;
F_20 ( V_34 ,
V_26 ? V_35 : V_36 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_37 [ V_20 ] = V_27 [ V_20 ] ;
V_37 [ V_20 ++ ] = * V_28 ;
V_37 [ V_20 ++ ] = * V_30 ;
V_37 [ V_20 ++ ] = * V_32 ;
* V_28 = V_38 ;
* V_30 = V_26 ;
F_17 () ;
return 0 ;
}
static void F_21 ( void )
{
int V_20 = 0 ;
T_3 * V_27 = F_18 ( V_22 ) ;
T_3 * V_28 = F_18 ( V_29 ) ;
T_3 * V_30 = F_18 ( V_31 ) ;
T_3 * V_32 = F_18 ( V_33 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_27 [ V_20 ] = V_37 [ V_20 ] ;
* V_28 = V_37 [ V_20 ++ ] ;
* V_30 = V_37 [ V_20 ++ ] ;
* V_32 = V_37 [ V_20 ++ ] ;
}
static int T_2 F_22 ( void )
{
int V_39 = V_40 + ( sizeof( T_3 ) * 3 ) ;
F_23 ( & V_41 ) ;
V_37 = F_24 ( V_39 , V_42 ) ;
if ( ! V_37 )
return - V_43 ;
F_6 ( V_44 L_7 ,
V_39 ) ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( V_37 ) ;
F_27 ( & V_41 ) ;
F_6 ( V_45 L_8
L_9 ) ;
}
static int F_28 ( void )
{
return F_4 ( V_46 ) ;
}
static void F_29 ( int V_47 )
{
F_2 ( V_48 , ( V_47 == V_49 ) ) ;
}
static void F_30 ( void )
{
F_31 () ;
F_32 ( V_50 , NULL ) ;
}
static void F_33 ( enum V_51 V_52 , const char * V_53 )
{
F_31 () ;
F_32 ( V_50 , V_53 ) ;
}
static void T_2 F_34 ( void )
{
int V_11 ;
V_54 = 0xff100000 ;
V_55 = V_56 | V_57 | V_58 ;
V_59 = 32768 - 1 ;
V_60 = V_61 ;
F_35 ( 0x7ff02dd8 , V_62 ) ;
F_35 ( 0x0001c391 , V_63 ) ;
F_35 ( 0x0001c391 , V_64 ) ;
F_35 ( 0x0001c391 , V_65 ) ;
F_36 ( F_9 ( V_66 ) ) ;
F_37 ( NULL ) ;
F_38 ( NULL ) ;
F_39 ( NULL ) ;
V_11 = F_8 ( F_9 ( V_67 ) ) ;
if ( V_11 )
F_40 ( L_10 , V_11 ) ;
F_22 () ;
F_41 ( NULL , & V_68 ) ;
F_42 ( & V_69 ) ;
F_43 ( & V_70 ) ;
F_44 ( & V_71 ) ;
F_45 ( & V_72 ) ;
V_73 = F_30 ;
F_46 ( V_74 , F_47 ( V_74 ) ) ;
F_48 ( V_75 , F_47 ( V_75 ) ) ;
F_7 () ;
F_49 ( 0 , F_9 ( V_76 ) ) ;
F_49 ( 1 , F_9 ( V_77 ) ) ;
F_50 ( & V_78 ) ;
F_51 ( NULL ) ;
F_52 ( & V_79 ) ;
F_53 ( 0 , L_11 , V_80 ,
F_47 ( V_80 ) ,
5000000 ) ;
F_54 () ;
}
static void F_31 ( void )
{
F_25 () ;
F_14 () ;
}
