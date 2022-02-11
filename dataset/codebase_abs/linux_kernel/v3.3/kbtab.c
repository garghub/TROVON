static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
unsigned char * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
int V_8 ;
switch ( V_1 -> V_9 ) {
case 0 :
break;
case - V_10 :
case - V_11 :
case - V_12 :
F_2 ( L_1 , V_13 , V_1 -> V_9 ) ;
return;
default:
F_2 ( L_2 , V_13 , V_1 -> V_9 ) ;
goto exit;
}
F_3 ( V_6 , V_14 , 1 ) ;
F_4 ( V_6 , V_15 , F_5 ( & V_4 [ 1 ] ) ) ;
F_4 ( V_6 , V_16 , F_5 ( & V_4 [ 3 ] ) ) ;
F_3 ( V_6 , V_17 , V_4 [ 0 ] & 0x02 ) ;
V_7 = V_4 [ 5 ] ;
if ( V_18 == - 1 )
F_4 ( V_6 , V_19 , V_7 ) ;
else
F_3 ( V_6 , V_20 , V_7 > V_18 ? 1 : 0 ) ;
F_6 ( V_6 ) ;
exit:
V_8 = F_7 ( V_1 , V_21 ) ;
if ( V_8 )
F_8 ( L_3 ,
V_13 , V_8 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_2 * V_2 = F_10 ( V_6 ) ;
V_2 -> V_22 -> V_6 = V_2 -> V_23 ;
if ( F_7 ( V_2 -> V_22 , V_24 ) )
return - V_25 ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_2 * V_2 = F_10 ( V_6 ) ;
F_12 ( V_2 -> V_22 ) ;
}
static int F_13 ( struct V_26 * V_27 , const struct V_28 * V_29 )
{
struct V_30 * V_6 = F_14 ( V_27 ) ;
struct V_31 * V_32 ;
struct V_2 * V_2 ;
struct V_5 * V_5 ;
int error = - V_33 ;
V_2 = F_15 ( sizeof( struct V_2 ) , V_24 ) ;
V_5 = F_16 () ;
if ( ! V_2 || ! V_5 )
goto V_34;
V_2 -> V_4 = F_17 ( V_6 , 8 , V_24 , & V_2 -> V_35 ) ;
if ( ! V_2 -> V_4 )
goto V_34;
V_2 -> V_22 = F_18 ( 0 , V_24 ) ;
if ( ! V_2 -> V_22 )
goto V_36;
V_2 -> V_23 = V_6 ;
V_2 -> V_6 = V_5 ;
F_19 ( V_6 , V_2 -> V_37 , sizeof( V_2 -> V_37 ) ) ;
F_20 ( V_2 -> V_37 , L_4 , sizeof( V_2 -> V_37 ) ) ;
V_5 -> V_38 = L_5 ;
V_5 -> V_37 = V_2 -> V_37 ;
F_21 ( V_6 , & V_5 -> V_29 ) ;
V_5 -> V_6 . V_39 = & V_27 -> V_6 ;
F_22 ( V_5 , V_2 ) ;
V_5 -> V_40 = F_9 ;
V_5 -> V_41 = F_11 ;
V_5 -> V_42 [ 0 ] |= F_23 ( V_43 ) | F_23 ( V_44 ) ;
V_5 -> V_45 [ F_24 ( V_20 ) ] |=
F_23 ( V_20 ) | F_23 ( V_17 ) ;
V_5 -> V_45 [ F_24 ( V_46 ) ] |=
F_23 ( V_14 ) | F_23 ( V_47 ) ;
F_25 ( V_5 , V_15 , 0 , 0x2000 , 4 , 0 ) ;
F_25 ( V_5 , V_16 , 0 , 0x1750 , 4 , 0 ) ;
F_25 ( V_5 , V_19 , 0 , 0xff , 0 , 0 ) ;
V_32 = & V_27 -> V_48 -> V_32 [ 0 ] . V_49 ;
F_26 ( V_2 -> V_22 , V_6 ,
F_27 ( V_6 , V_32 -> V_50 ) ,
V_2 -> V_4 , 8 ,
F_1 , V_2 , V_32 -> V_51 ) ;
V_2 -> V_22 -> V_52 = V_2 -> V_35 ;
V_2 -> V_22 -> V_53 |= V_54 ;
error = F_28 ( V_2 -> V_6 ) ;
if ( error )
goto V_55;
F_29 ( V_27 , V_2 ) ;
return 0 ;
V_55: F_30 ( V_2 -> V_22 ) ;
V_36: F_31 ( V_6 , 8 , V_2 -> V_4 , V_2 -> V_35 ) ;
V_34: F_32 ( V_5 ) ;
F_33 ( V_2 ) ;
return error ;
}
static void F_34 ( struct V_26 * V_27 )
{
struct V_2 * V_2 = F_35 ( V_27 ) ;
F_29 ( V_27 , NULL ) ;
F_36 ( V_2 -> V_6 ) ;
F_30 ( V_2 -> V_22 ) ;
F_31 ( V_2 -> V_23 , 8 , V_2 -> V_4 , V_2 -> V_35 ) ;
F_33 ( V_2 ) ;
}
