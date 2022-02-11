static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_5 + V_3 ) ;
}
static void F_3 ( void * args )
{
struct V_1 * V_2 = args ;
F_4 ( & V_2 -> V_6 . V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_8 = V_9 | V_10 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
T_1 V_14 = 0 ;
int V_15 ;
F_6 ( & V_2 -> V_6 . V_16 ) ;
V_2 -> V_6 . V_17 . V_18 = V_2 -> V_6 . V_19 + V_5 + V_3 ;
V_15 = F_7 ( V_2 -> V_6 . V_20 , & V_2 -> V_6 . V_17 ) ;
if ( V_15 )
goto V_21;
V_12 = F_8 ( V_2 -> V_6 . V_20 ,
V_2 -> V_6 . V_19 ,
sizeof( T_1 ) , V_22 ,
V_8 ) ;
if ( ! V_12 )
goto V_21;
V_12 -> V_23 = F_3 ;
V_12 -> V_24 = V_2 ;
F_9 ( & V_2 -> V_6 . V_7 ) ;
F_10 ( V_2 -> V_25 ) ;
F_11 ( V_12 ) ;
F_12 ( V_2 -> V_6 . V_20 ) ;
V_13 = F_13 ( & V_2 -> V_6 . V_7 ,
F_14 ( 50 ) ) ;
if ( F_15 ( V_13 == 0 , L_1 ) )
F_16 ( V_2 -> V_6 . V_20 ) ;
else
V_14 = * V_2 -> V_6 . V_26 ;
F_17 ( V_2 -> V_25 ) ;
V_21:
F_18 ( & V_2 -> V_6 . V_16 ) ;
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_2 V_27 ;
F_20 ( V_27 ) ;
F_21 ( V_28 , V_27 ) ;
V_2 -> V_6 . V_20 = F_22 ( V_27 , NULL , NULL ) ;
if ( ! V_2 -> V_6 . V_20 )
return - V_29 ;
V_2 -> V_6 . V_26 = F_23 ( V_2 -> V_30 , sizeof( T_1 ) ,
& V_2 -> V_6 . V_19 ,
V_31 ) ;
if ( ! V_2 -> V_6 . V_26 ) {
F_24 ( V_2 -> V_6 . V_20 ) ;
return - V_32 ;
}
V_2 -> V_6 . V_17 . V_33 = V_34 ;
V_2 -> V_6 . V_17 . V_35 = V_34 ;
V_2 -> V_6 . V_17 . V_36 = 1 ;
V_2 -> V_6 . V_17 . V_37 = 1 ;
F_25 ( & V_2 -> V_6 . V_7 ) ;
F_26 ( & V_2 -> V_6 . V_16 ) ;
V_2 -> V_38 = F_5 ;
return 0 ;
}
static void T_3 F_27 ( void )
{
T_1 V_39 [ 7 ] ;
V_39 [ 0 ] = V_40 . V_41 ;
V_39 [ 1 ] = F_28 () ;
V_39 [ 2 ] = F_29 () ;
V_39 [ 3 ] = V_40 . V_42 << 16 ;
V_39 [ 3 ] |= V_40 . V_43 ;
V_39 [ 4 ] = V_40 . V_44 << 16 ;
V_39 [ 4 ] |= V_40 . V_45 ;
V_39 [ 5 ] = F_30 ( V_46 ) ;
V_39 [ 6 ] = F_30 ( V_47 ) ;
F_31 ( V_39 , sizeof( V_39 ) ) ;
}
static void T_3 F_32 ( struct V_1 * V_2 )
{
V_2 -> V_48 = F_1 ;
F_33 () ;
V_2 -> V_49 -> V_50 ( & V_40 ) ;
F_27 () ;
}
