static void F_1 ( void * args )
{
F_2 ( & V_1 ) ;
}
static T_1 F_3 ( const unsigned int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
struct V_5 * V_6 ;
F_4 ( & V_7 ) ;
V_8 . V_9 = V_10 + V_11 + V_2 ;
V_3 = F_5 ( V_12 , & V_8 ) ;
if ( V_3 )
goto V_13;
V_6 = F_6 ( V_12 , V_14 ,
sizeof( T_1 ) , V_15 ,
V_16 | V_17 ) ;
if ( ! V_6 )
goto V_13;
V_6 -> V_18 = F_1 ;
V_6 -> V_19 = NULL ;
F_7 ( & V_1 ) ;
F_8 ( V_20 ) ;
F_9 ( V_6 ) ;
F_10 ( V_12 ) ;
V_3 = F_11 ( & V_1 , F_12 ( 50 ) ) ;
if ( F_13 ( V_3 == 0 , L_1 ) )
F_14 ( V_12 ) ;
else
V_4 = * V_21 ;
F_15 ( V_20 ) ;
V_13:
F_16 ( & V_7 ) ;
return V_4 ;
}
static int F_17 ( void )
{
T_2 V_22 ;
F_18 ( V_22 ) ;
F_19 ( V_23 , V_22 ) ;
V_12 = F_20 ( V_22 , NULL , NULL ) ;
if ( ! V_12 )
return - V_24 ;
V_21 = F_21 ( NULL , sizeof( T_1 ) , & V_14 ,
V_25 ) ;
if ( ! V_21 ) {
F_22 ( V_12 ) ;
return - V_26 ;
}
V_8 . V_27 = V_28 ;
V_8 . V_29 = V_28 ;
V_8 . V_30 = 1 ;
V_8 . V_31 = 1 ;
return 0 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
int V_36 ;
V_20 = F_24 ( & V_33 -> V_37 , NULL ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( & V_33 -> V_37 , L_2 ) ;
return F_27 ( V_20 ) ;
}
V_35 = F_28 ( V_33 , V_38 , 0 ) ;
if ( ! V_35 )
return - V_39 ;
V_10 = V_35 -> V_40 ;
V_36 = F_17 () ;
if ( V_36 )
return V_36 ;
if ( F_29 ( & V_33 -> V_37 , V_41 , F_3 ) )
return - V_42 ;
F_30 ( & V_33 -> V_37 , L_3 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_43 ) ;
}
T_1 T_3 F_33 ( const unsigned int V_2 )
{
return F_34 ( V_44 + V_11 + V_2 ) ;
}
bool T_3 F_35 ( int V_45 )
{
T_1 V_2 = V_45 * 4 ;
bool V_46 ;
V_46 = F_33 ( V_2 + 0x100 ) ;
return V_46 ;
}
static void T_3 F_36 ( void )
{
T_1 V_47 [ 7 ] ;
V_47 [ 0 ] = V_48 . V_49 ;
V_47 [ 1 ] = F_37 () ;
V_47 [ 2 ] = F_38 () ;
V_47 [ 3 ] = V_48 . V_50 << 16 ;
V_47 [ 3 ] |= V_48 . V_51 ;
V_47 [ 4 ] = V_48 . V_52 << 16 ;
V_47 [ 4 ] |= V_48 . V_53 ;
V_47 [ 5 ] = F_33 ( V_54 ) ;
V_47 [ 6 ] = F_33 ( V_55 ) ;
F_39 ( V_47 , sizeof( V_47 ) ) ;
}
void T_3 F_40 ( void )
{
V_44 = F_41 ( V_56 , V_57 ) ;
F_42 () ;
F_43 ( & V_48 ) ;
F_36 () ;
F_44 ( V_44 ) ;
}
