static void F_1 ( void * args )
{
F_2 ( & V_1 ) ;
}
static T_1 F_3 ( const unsigned int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
F_4 ( & V_8 ) ;
V_9 . V_10 = V_11 + V_12 + V_2 ;
V_3 = F_5 ( V_13 , & V_9 ) ;
if ( V_3 )
goto V_14;
V_6 = F_6 ( V_13 , V_15 ,
sizeof( T_1 ) , V_16 ,
V_17 | V_18 ) ;
if ( ! V_6 )
goto V_14;
V_6 -> V_19 = F_1 ;
V_6 -> V_20 = NULL ;
F_7 ( & V_1 ) ;
F_8 ( V_21 ) ;
F_9 ( V_6 ) ;
F_10 ( V_13 ) ;
V_7 = F_11 ( & V_1 ,
F_12 ( 50 ) ) ;
if ( F_13 ( V_7 == 0 , L_1 ) )
F_14 ( V_13 ) ;
else
V_4 = * V_22 ;
F_15 ( V_21 ) ;
V_14:
F_16 ( & V_8 ) ;
return V_4 ;
}
static int F_17 ( void )
{
T_2 V_23 ;
F_18 ( V_23 ) ;
F_19 ( V_24 , V_23 ) ;
V_13 = F_20 ( V_23 , NULL , NULL ) ;
if ( ! V_13 )
return - V_25 ;
V_22 = F_21 ( NULL , sizeof( T_1 ) , & V_15 ,
V_26 ) ;
if ( ! V_22 ) {
F_22 ( V_13 ) ;
return - V_27 ;
}
V_9 . V_28 = V_29 ;
V_9 . V_30 = V_29 ;
V_9 . V_31 = 1 ;
V_9 . V_32 = 1 ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
int V_37 ;
V_21 = F_24 ( & V_34 -> V_38 , NULL ) ;
if ( F_25 ( V_21 ) ) {
F_26 ( & V_34 -> V_38 , L_2 ) ;
return F_27 ( V_21 ) ;
}
V_36 = F_28 ( V_34 , V_39 , 0 ) ;
if ( ! V_36 )
return - V_40 ;
V_11 = V_36 -> V_41 ;
V_37 = F_17 () ;
if ( V_37 )
return V_37 ;
if ( F_29 ( & V_34 -> V_38 , V_42 , F_3 ) )
return - V_43 ;
F_30 ( & V_34 -> V_38 , L_3 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_44 ) ;
}
T_1 T_3 F_33 ( const unsigned int V_2 )
{
return F_34 ( V_45 + V_12 + V_2 ) ;
}
bool T_3 F_35 ( int V_46 )
{
T_1 V_2 = V_46 * 4 ;
bool V_47 ;
V_47 = F_33 ( V_2 + 0x100 ) ;
return V_47 ;
}
static void T_3 F_36 ( void )
{
T_1 V_48 [ 7 ] ;
V_48 [ 0 ] = V_49 . V_50 ;
V_48 [ 1 ] = F_37 () ;
V_48 [ 2 ] = F_38 () ;
V_48 [ 3 ] = V_49 . V_51 << 16 ;
V_48 [ 3 ] |= V_49 . V_52 ;
V_48 [ 4 ] = V_49 . V_53 << 16 ;
V_48 [ 4 ] |= V_49 . V_54 ;
V_48 [ 5 ] = F_33 ( V_55 ) ;
V_48 [ 6 ] = F_33 ( V_56 ) ;
F_39 ( V_48 , sizeof( V_48 ) ) ;
}
void T_3 F_40 ( void )
{
V_45 = F_41 ( V_57 , V_58 ) ;
F_42 () ;
F_43 ( & V_49 ) ;
F_36 () ;
F_44 ( V_45 ) ;
}
