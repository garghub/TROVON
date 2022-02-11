static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_1 V_5 , T_1 * V_6 , T_1 V_7 , int V_8 )
{
struct V_9 V_10 ;
V_10 . V_11 . V_12 . V_13 = V_14 ;
V_10 . V_11 . V_12 . V_15 = V_5 + 3 ;
V_10 . V_11 . V_16 . V_17 = V_3 << 1 ;
memcpy ( V_10 . V_11 . V_16 . V_18 , V_4 , V_5 ) ;
V_10 . V_11 . V_16 . V_18 [ V_5 ] = V_7 ;
V_10 . V_11 . V_16 . V_18 [ V_5 + 1 ] = 0 ;
V_10 . V_19 = V_5 + 3 ;
V_10 . V_20 = V_7 + 1 ;
if ( V_9 ( V_2 , & V_10 ) < 0 )
return - V_21 ;
if ( ( V_10 . V_11 . V_22 [ 0 ] >> 1 ) != V_3 )
return - V_21 ;
if ( V_8 )
memcpy ( V_6 , V_10 . V_11 . V_22 , V_7 + 1 ) ;
else
memcpy ( V_6 , V_10 . V_11 . V_22 + 1 , V_7 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_1 V_5 )
{
struct V_9 V_10 ;
V_10 . V_11 . V_12 . V_13 = V_23 ;
V_10 . V_11 . V_12 . V_15 = V_5 + 1 ;
V_10 . V_11 . V_16 . V_17 = V_3 << 1 ;
memcpy ( V_10 . V_11 . V_16 . V_18 , V_4 , V_5 ) ;
V_10 . V_19 = V_5 + 1 ;
V_10 . V_20 = 1 ;
if ( V_9 ( V_2 , & V_10 ) < 0 )
return - V_21 ;
if ( V_10 . V_11 . V_22 [ 0 ] == 1 )
return - V_21 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_24 )
{
if ( ! ( V_2 -> V_25 -> V_26 & 2 ) )
return;
if ( V_2 -> V_27 == V_24 )
return;
switch ( V_24 ) {
case 0 :
F_4 ( V_2 , 3 , 0 ) ;
F_4 ( V_2 , 2 , 1 ) ;
break;
case 1 :
F_4 ( V_2 , 2 , 0 ) ;
F_4 ( V_2 , 3 , 1 ) ;
break;
}
V_2 -> V_27 = V_24 ;
}
static int F_5 ( struct V_28 * V_29 ,
struct V_30 V_31 [] , int V_32 )
{
struct V_33 * V_34 =
(struct V_33 * ) F_6 ( V_29 ) ;
struct V_1 * V_2 = V_34 -> V_2 ;
F_7 ( & V_2 -> V_35 ) ;
F_3 ( V_2 , V_34 -> V_36 ) ;
if ( V_32 == 2 && V_31 [ 1 ] . V_37 & V_38 && ! ( V_31 [ 0 ] . V_37 & V_38 ) )
if ( ! F_1 ( V_2 , V_31 [ 0 ] . V_39 ,
V_31 [ 0 ] . V_40 , V_31 [ 0 ] . V_41 ,
V_31 [ 1 ] . V_40 , V_31 [ 1 ] . V_41 , 0 ) )
goto V_42;
if ( V_32 == 1 && ! ( V_31 [ 0 ] . V_37 & V_38 ) )
if ( ! F_2 ( V_2 , V_31 [ 0 ] . V_39 ,
V_31 [ 0 ] . V_40 , V_31 [ 0 ] . V_41 ) )
goto V_42;
if ( V_32 == 1 && ( V_31 [ 0 ] . V_37 & V_38 ) )
if ( ! F_1 ( V_2 , V_31 [ 0 ] . V_39 , NULL , 0 ,
V_31 [ 0 ] . V_40 , V_31 [ 0 ] . V_41 , 0 ) )
goto V_42;
F_8 ( & V_2 -> V_35 ) ;
return - V_21 ;
V_42:
F_8 ( & V_2 -> V_35 ) ;
return V_32 ;
}
static T_2 F_9 ( struct V_28 * V_43 )
{
return V_44 ;
}
int F_10 ( struct V_1 * V_2 , int V_45 )
{
struct V_28 * V_43 = & ( V_2 -> V_46 [ V_45 ] . V_28 ) ;
F_11 ( V_43 , & ( V_2 -> V_46 [ V_45 ] ) ) ;
strcpy ( V_43 -> V_47 , L_1 ) ;
V_43 -> V_48 = & V_49 ;
V_43 -> V_50 = ( void * ) & ( V_2 -> V_46 [ V_45 ] ) ;
V_43 -> V_2 . V_51 = & V_2 -> V_52 -> V_2 ;
return F_12 ( V_43 ) ;
}
