static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 = 0 ;
int V_6 ;
int V_7 ;
for ( V_4 = 0 ; ( ! V_5 ) && ( V_4 < V_3 ) ; V_4 ++ ) {
V_6 = V_2 [ V_4 ] . V_6 ;
V_7 = V_2 [ V_4 ] . V_7 ;
V_5 = F_2 ( V_6 , V_2 [ V_4 ] . V_8 ) ;
if ( V_5 ) {
F_3 ( V_9 L_1 ,
V_6 , V_2 [ V_4 ] . V_8 , V_5 ) ;
continue;
}
if ( V_7 )
F_4 ( V_6 , V_2 [ V_4 ] . V_10 ) ;
else
F_5 ( V_6 ) ;
}
while ( ( V_5 ) && ( -- V_4 >= 0 ) )
F_6 ( V_2 [ V_4 ] . V_6 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_6 ( V_2 [ V_4 ] . V_6 ) ;
}
static void F_8 ( int V_11 , struct V_12 * V_13 )
{
F_9 ( V_14 , V_11 ) ;
}
static int F_10 ( void )
{
int V_15 ;
V_15 = ! ! F_11 ( V_16 ) ;
return V_15 ;
}
T_1 F_12 ( int V_17 , void * V_18 )
{
F_3 ( V_19 L_2 ,
F_10 () ? L_3 : L_4 ) ;
return V_20 ;
}
static int T_2 F_13 ( void )
{
int V_5 ;
V_5 = F_1 ( F_14 ( V_21 ) ) ;
if ( V_5 )
goto V_22;
V_5 = F_15 ( F_16 ( V_16 ) , F_12 ,
V_23 | V_24 ,
L_5 , NULL ) ;
if ( V_5 )
goto V_25;
F_17 ( V_26 , 1 ) ;
return 0 ;
V_25:
F_3 ( V_9 L_6 ) ;
F_7 ( F_14 ( V_21 ) ) ;
V_22:
F_3 ( V_9 L_7 ) ;
return V_5 ;
}
static void F_18 ( void )
{
F_19 ( F_16 ( V_16 ) , NULL ) ;
F_7 ( F_14 ( V_21 ) ) ;
}
static int F_20 ( void )
{
return ! F_11 ( V_27 ) ;
}
static void F_21 ( void )
{
int V_4 ;
T_3 * V_28 = F_22 ( V_29 ) ;
T_3 * V_30 = & V_31 ;
for ( V_4 = 0 ; V_4 < V_32 ; V_4 ++ )
V_28 [ V_4 ] = V_30 [ V_4 ] ;
}
static int F_23 ( void )
{
int V_4 = 0 , V_33 ;
T_3 * V_34 = F_22 ( V_29 ) ;
T_3 * V_35 = F_22 ( V_36 ) ;
T_3 * V_37 = F_22 ( V_38 ) ;
T_3 * V_39 = F_22 ( V_40 ) ;
V_33 = ! ! F_11 ( V_41 ) ;
F_24 ( V_41 ,
V_33 ? V_42 : V_43 ) ;
for ( V_4 = 0 ; V_4 < V_32 ; V_4 ++ )
V_44 [ V_4 ] = V_34 [ V_4 ] ;
V_44 [ V_4 ++ ] = * V_35 ;
V_44 [ V_4 ++ ] = * V_37 ;
V_44 [ V_4 ++ ] = * V_39 ;
* V_35 = V_45 ;
* V_37 = V_33 ;
F_21 () ;
return 0 ;
}
static void F_25 ( void )
{
int V_4 = 0 ;
T_3 * V_34 = F_22 ( V_29 ) ;
T_3 * V_35 = F_22 ( V_36 ) ;
T_3 * V_37 = F_22 ( V_38 ) ;
T_3 * V_39 = F_22 ( V_40 ) ;
for ( V_4 = 0 ; V_4 < V_32 ; V_4 ++ )
V_34 [ V_4 ] = V_44 [ V_4 ] ;
* V_35 = V_44 [ V_4 ++ ] ;
* V_37 = V_44 [ V_4 ++ ] ;
* V_39 = V_44 [ V_4 ++ ] ;
}
static int T_2 F_26 ( void )
{
int V_46 = V_47 + ( sizeof( T_3 ) * 3 ) ;
F_27 ( & V_48 ) ;
V_44 = F_28 ( V_46 , V_49 ) ;
if ( ! V_44 )
return - V_50 ;
F_3 ( V_51 L_8 ,
V_46 ) ;
return 0 ;
}
static void F_29 ( void )
{
F_30 ( V_44 ) ;
F_31 ( & V_48 ) ;
F_3 ( V_52 L_9
L_10 ) ;
}
static int F_32 ( void )
{
return F_11 ( V_53 ) ;
}
static void F_33 ( int V_54 )
{
F_9 ( V_55 , ( V_54 == V_56 ) ) ;
}
static void F_34 ( void )
{
F_35 () ;
F_36 ( 's' , NULL ) ;
}
static void F_37 ( char V_57 , const char * V_58 )
{
F_35 () ;
F_36 ( 's' , V_58 ) ;
}
static void T_2 F_38 ( void )
{
V_59 = 0xff100000 ;
V_60 = V_61 | V_62 | V_63 ;
V_64 = 32768 - 1 ;
V_65 = V_66 ;
F_39 ( F_14 ( V_67 ) ) ;
F_40 ( NULL ) ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
F_1 ( F_14 ( V_68 ) ) ;
F_26 () ;
F_43 ( NULL , & V_69 ) ;
F_44 ( & V_70 ) ;
F_45 ( & V_71 ) ;
F_46 ( & V_72 ) ;
F_47 ( & V_73 ) ;
V_74 = F_34 ;
V_75 = F_37 ;
F_48 ( V_76 , F_49 ( V_76 ) ) ;
F_13 () ;
F_50 ( 1 , F_14 ( V_77 ) ) ;
F_51 ( & V_78 ) ;
F_52 ( NULL ) ;
F_53 ( & V_79 ) ;
}
static void F_35 ( void )
{
F_29 () ;
F_18 () ;
}
