void F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 V_5 ;
if ( ! ( V_3 -> V_6 & V_7 ) )
return;
F_2 ( & V_5 ) ;
V_5 . V_8 = 1 ;
V_5 . V_9 = V_10 | V_11 | V_12 | 0x9f ;
if ( V_1 >= V_13 )
V_5 . V_9 |= V_14 ;
if ( V_1 >= V_15 )
V_5 . V_9 |= V_16 ;
V_5 . V_17 = V_3 -> V_18 ;
F_3 ( & V_5 ) ;
F_4 () ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_19 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memcpy ( V_20 . V_21 . V_22 , V_23 , V_24 ) ;
V_20 . V_21 . V_25 = V_26 ;
V_20 . V_21 . V_27 = V_28 ;
V_20 . V_21 . V_29 = 1 ;
V_20 . V_21 . V_30 = V_31 ;
V_20 . V_21 . V_6 = 0 ;
V_20 . V_21 . V_32 = sizeof( V_20 ) ;
V_20 . V_21 . V_33 = V_34 ;
V_20 . V_21 . V_35 = V_36 ;
V_20 . V_21 . V_37 = F_6 () ;
V_20 . V_21 . V_38 = V_39 ;
V_20 . V_40 . V_41 = ( void * ) & V_20 . V_4 - ( void * ) & V_20 ;
V_20 . V_40 . V_42 = sizeof( V_20 . V_4 ) ;
V_20 . V_40 . V_25 = V_43 ;
V_20 . V_40 . V_6 = 0 ;
V_20 . V_40 . V_38 = V_44 ;
V_20 . V_40 . V_45 = V_46 ;
V_20 . V_40 . V_47 = V_31 ;
memcpy ( & V_20 . V_4 , V_5 , sizeof( * V_5 ) ) ;
return F_7 ( & V_20 . V_21 ) ;
}
T_1 F_8 ( struct V_4 * V_5 , T_2 * V_37 )
{
struct V_19 V_20 ;
int V_48 , V_49 ;
V_48 = F_9 ( & V_49 ) ;
if ( V_48 )
return V_48 ;
V_50:
V_48 = F_10 ( & V_49 , V_37 ) ;
if ( V_48 )
goto V_51;
if ( * V_37 == V_52 )
goto V_51;
V_48 = F_11 ( * V_37 , & V_20 . V_21 , sizeof( V_20 ) ) ;
if ( V_48 == - V_53 )
goto V_50;
else if ( V_48 < 0 )
goto V_51;
else if ( V_48 != sizeof( V_20 ) ||
F_12 ( V_20 . V_21 . V_33 , V_34 ) )
goto V_50;
memcpy ( V_5 , & V_20 . V_4 , sizeof( * V_5 ) ) ;
V_48 = sizeof( * V_5 ) ;
V_51:
F_13 () ;
return V_48 ;
}
int F_14 ( void )
{
return F_15 () ;
}
int F_16 ( T_2 V_37 )
{
return F_17 ( V_37 ) ;
}
