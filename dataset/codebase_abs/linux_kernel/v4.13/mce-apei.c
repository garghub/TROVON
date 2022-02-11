void F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 V_5 ;
if ( ! ( V_3 -> V_6 & V_7 ) )
return;
F_2 ( & V_5 ) ;
V_5 . V_8 = - 1 ;
V_5 . V_9 = V_10 | V_11 | V_12 | 0x9f ;
if ( V_1 >= V_13 )
V_5 . V_9 |= V_14 ;
if ( V_1 >= V_15 ) {
V_5 . V_9 |= V_16 ;
V_5 . V_17 = F_3 () ;
}
V_5 . V_18 = V_3 -> V_19 ;
F_4 ( & V_5 ) ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memcpy ( V_21 . V_22 . V_23 , V_24 , V_25 ) ;
V_21 . V_22 . V_26 = V_27 ;
V_21 . V_22 . V_28 = V_29 ;
V_21 . V_22 . V_30 = 1 ;
V_21 . V_22 . V_31 = V_32 ;
V_21 . V_22 . V_6 = 0 ;
V_21 . V_22 . V_33 = sizeof( V_21 ) ;
V_21 . V_22 . V_34 = V_35 ;
V_21 . V_22 . V_36 = V_37 ;
V_21 . V_22 . V_38 = F_6 () ;
V_21 . V_22 . V_39 = V_40 ;
V_21 . V_41 . V_42 = ( void * ) & V_21 . V_4 - ( void * ) & V_21 ;
V_21 . V_41 . V_43 = sizeof( V_21 . V_4 ) ;
V_21 . V_41 . V_26 = V_44 ;
V_21 . V_41 . V_6 = 0 ;
V_21 . V_41 . V_39 = V_45 ;
V_21 . V_41 . V_46 = V_47 ;
V_21 . V_41 . V_48 = V_32 ;
memcpy ( & V_21 . V_4 , V_5 , sizeof( * V_5 ) ) ;
return F_7 ( & V_21 . V_22 ) ;
}
T_1 F_8 ( struct V_4 * V_5 , T_2 * V_38 )
{
struct V_20 V_21 ;
int V_49 , V_50 ;
V_49 = F_9 ( & V_50 ) ;
if ( V_49 )
return V_49 ;
V_51:
V_49 = F_10 ( & V_50 , V_38 ) ;
if ( V_49 )
goto V_52;
if ( * V_38 == V_53 )
goto V_52;
V_49 = F_11 ( * V_38 , & V_21 . V_22 , sizeof( V_21 ) ) ;
if ( V_49 == - V_54 )
goto V_51;
else if ( V_49 < 0 )
goto V_52;
else if ( V_49 != sizeof( V_21 ) ||
F_12 ( V_21 . V_22 . V_34 , V_35 ) )
goto V_51;
memcpy ( V_5 , & V_21 . V_4 , sizeof( * V_5 ) ) ;
V_49 = sizeof( * V_5 ) ;
V_52:
F_13 () ;
return V_49 ;
}
int F_14 ( void )
{
return F_15 () ;
}
int F_16 ( T_2 V_38 )
{
return F_17 ( V_38 ) ;
}
