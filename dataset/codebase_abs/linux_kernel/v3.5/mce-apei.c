void F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 V_5 ;
if ( ! V_1 || ! ( V_3 -> V_6 &
V_7 ) )
return;
F_2 ( & V_5 ) ;
V_5 . V_8 = 1 ;
V_5 . V_9 = V_10 | V_11 | V_12 | 0x9f ;
V_5 . V_13 = V_3 -> V_14 ;
F_3 ( & V_5 ) ;
F_4 () ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memcpy ( V_16 . V_17 . V_18 , V_19 , V_20 ) ;
V_16 . V_17 . V_21 = V_22 ;
V_16 . V_17 . V_23 = V_24 ;
V_16 . V_17 . V_25 = 1 ;
V_16 . V_17 . V_26 = V_27 ;
V_16 . V_17 . V_6 = 0 ;
V_16 . V_17 . V_28 = sizeof( V_16 ) ;
V_16 . V_17 . V_29 = V_30 ;
V_16 . V_17 . V_31 = V_32 ;
V_16 . V_17 . V_33 = F_6 () ;
V_16 . V_17 . V_34 = V_35 ;
V_16 . V_36 . V_37 = ( void * ) & V_16 . V_4 - ( void * ) & V_16 ;
V_16 . V_36 . V_38 = sizeof( V_16 . V_4 ) ;
V_16 . V_36 . V_21 = V_39 ;
V_16 . V_36 . V_6 = 0 ;
V_16 . V_36 . V_34 = V_40 ;
V_16 . V_36 . V_41 = V_42 ;
V_16 . V_36 . V_43 = V_27 ;
memcpy ( & V_16 . V_4 , V_5 , sizeof( * V_5 ) ) ;
return F_7 ( & V_16 . V_17 ) ;
}
T_1 F_8 ( struct V_4 * V_5 , T_2 * V_33 )
{
struct V_15 V_16 ;
int V_44 , V_45 ;
V_44 = F_9 ( & V_45 ) ;
if ( V_44 )
return V_44 ;
V_46:
V_44 = F_10 ( & V_45 , V_33 ) ;
if ( V_44 )
goto V_47;
if ( * V_33 == V_48 )
goto V_47;
V_44 = F_11 ( * V_33 , & V_16 . V_17 , sizeof( V_16 ) ) ;
if ( V_44 == - V_49 )
goto V_46;
else if ( V_44 < 0 )
goto V_47;
else if ( V_44 != sizeof( V_16 ) ||
F_12 ( V_16 . V_17 . V_29 , V_30 ) )
goto V_46;
memcpy ( V_5 , & V_16 . V_4 , sizeof( * V_5 ) ) ;
V_44 = sizeof( * V_5 ) ;
V_47:
F_13 () ;
return V_44 ;
}
int F_14 ( void )
{
return F_15 () ;
}
int F_16 ( T_2 V_33 )
{
return F_17 ( V_33 ) ;
}
