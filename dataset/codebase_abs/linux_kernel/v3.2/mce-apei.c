void F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 V_5 ;
if ( ! V_1 )
return;
F_2 ( & V_5 ) ;
V_5 . V_6 = 1 ;
V_5 . V_7 = V_8 | V_9 | V_10 | 0x9f ;
V_5 . V_11 = V_3 -> V_12 ;
F_3 ( & V_5 ) ;
F_4 () ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_13 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_15 . V_16 , V_17 , V_18 ) ;
V_14 . V_15 . V_19 = V_20 ;
V_14 . V_15 . V_21 = V_22 ;
V_14 . V_15 . V_23 = 1 ;
V_14 . V_15 . V_24 = V_25 ;
V_14 . V_15 . V_26 = 0 ;
V_14 . V_15 . V_27 = sizeof( V_14 ) ;
V_14 . V_15 . V_28 = V_29 ;
V_14 . V_15 . V_30 = V_31 ;
V_14 . V_15 . V_32 = F_6 () ;
V_14 . V_15 . V_33 = V_34 ;
V_14 . V_35 . V_36 = ( void * ) & V_14 . V_4 - ( void * ) & V_14 ;
V_14 . V_35 . V_37 = sizeof( V_14 . V_4 ) ;
V_14 . V_35 . V_19 = V_38 ;
V_14 . V_35 . V_26 = 0 ;
V_14 . V_35 . V_33 = V_39 ;
V_14 . V_35 . V_40 = V_41 ;
V_14 . V_35 . V_42 = V_25 ;
memcpy ( & V_14 . V_4 , V_5 , sizeof( * V_5 ) ) ;
return F_7 ( & V_14 . V_15 ) ;
}
T_1 F_8 ( struct V_4 * V_5 , T_2 * V_32 )
{
struct V_13 V_14 ;
int V_43 , V_44 ;
V_43 = F_9 ( & V_44 ) ;
if ( V_43 )
return V_43 ;
V_45:
V_43 = F_10 ( & V_44 , V_32 ) ;
if ( V_43 )
goto V_46;
if ( * V_32 == V_47 )
goto V_46;
V_43 = F_11 ( * V_32 , & V_14 . V_15 , sizeof( V_14 ) ) ;
if ( V_43 == - V_48 )
goto V_45;
else if ( V_43 < 0 )
goto V_46;
else if ( V_43 != sizeof( V_14 ) ||
F_12 ( V_14 . V_15 . V_28 , V_29 ) )
goto V_45;
memcpy ( V_5 , & V_14 . V_4 , sizeof( * V_5 ) ) ;
V_43 = sizeof( * V_5 ) ;
V_46:
F_13 () ;
return V_43 ;
}
int F_14 ( void )
{
return F_15 () ;
}
int F_16 ( T_2 V_32 )
{
return F_17 ( V_32 ) ;
}
