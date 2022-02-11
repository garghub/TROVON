static int F_1 ( T_1 V_1 , T_2 V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( ! V_6 )
return - V_7 ;
V_4 = (struct V_3 * ) F_2 ( V_8 | V_9 ) ;
if ( ! V_4 )
return - V_10 ;
V_4 -> V_11 . V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = V_2 ;
V_5 = F_3 ( V_1 , V_4 ) ;
if ( V_5 )
goto V_17;
switch ( V_4 -> V_11 . V_18 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_4 ( L_1 ,
V_1 , V_4 -> V_11 . V_18 ) ;
V_5 = - V_19 ;
break;
}
V_17:
F_5 ( ( unsigned long ) V_4 ) ;
return V_5 ;
}
int F_6 ( T_2 V_2 )
{
return F_1 ( V_20 , V_2 ) ;
}
int F_7 ( T_2 V_2 )
{
return F_1 ( V_21 , V_2 ) ;
}
static void F_8 ( struct V_22 * V_23 , void * V_24 )
{
struct V_25 * V_25 = V_24 ;
F_9 ( V_25 ) ;
}
static int F_10 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 != 1 )
return - V_29 ;
if ( V_27 -> V_30 != V_31 &&
V_27 -> V_30 != V_32 )
return - V_29 ;
if ( V_27 -> V_12 > ( V_13 - sizeof( struct V_33 ) ) )
return - V_29 ;
return 0 ;
}
int F_11 ( struct V_26 * V_27 , T_2 V_34 , T_2 V_2 )
{
F_12 ( V_25 ) ;
struct V_33 * V_4 ;
struct V_22 V_23 ;
int V_35 ;
V_35 = F_10 ( V_27 ) ;
if ( V_35 )
return V_35 ;
F_13 ( & V_36 ) ;
V_35 = F_14 ( & V_37 ) ;
if ( V_35 )
goto V_38;
if ( ! ( V_37 . V_39 & V_40 ) ) {
V_35 = - V_7 ;
goto V_41;
}
V_4 = ( void * ) F_2 ( V_8 | V_9 ) ;
if ( ! V_4 ) {
V_35 = - V_10 ;
goto V_41;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_42 = & V_25 ;
V_23 . V_43 = F_8 ;
V_23 . V_44 = V_45 ;
V_23 . V_46 = V_47 ;
V_23 . V_4 = V_4 ;
V_4 -> V_48 . V_11 . V_12 = sizeof( V_4 -> V_48 ) + V_27 -> V_12 ;
V_4 -> V_48 . V_11 . type = V_49 ;
V_4 -> V_11 . V_12 = sizeof( V_4 -> V_11 ) + V_4 -> V_48 . V_11 . V_12 ;
V_4 -> V_48 . V_30 = V_27 -> V_30 ;
V_4 -> V_48 . V_14 = V_15 ;
V_4 -> V_48 . V_34 = V_34 ;
V_4 -> V_48 . V_2 = V_2 ;
memcpy ( V_4 -> V_48 . V_24 , V_27 -> V_24 , V_27 -> V_12 ) ;
V_35 = F_15 ( & V_23 ) ;
if ( V_35 )
goto V_50;
F_16 ( & V_25 ) ;
if ( V_23 . V_46 != V_51 ) {
F_4 ( L_2 ,
V_23 . V_46 ) ;
V_35 = - V_19 ;
goto V_50;
}
if ( V_4 -> V_11 . V_18 != 0x0020 ) {
F_4 ( L_3 ,
V_4 -> V_11 . V_18 ) ;
V_35 = - V_19 ;
}
V_50:
F_5 ( ( unsigned long ) V_4 ) ;
V_41:
F_17 ( & V_37 ) ;
V_38:
F_18 ( & V_36 ) ;
return V_35 ;
}
