static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . V_4 -> V_5 ) {
case 0x0 :
V_2 -> V_6 . V_7 ++ ;
break;
case 0x10 :
V_2 -> V_6 . V_8 ++ ;
break;
case 0x14 :
V_2 -> V_6 . V_9 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
V_2 -> V_6 . V_11 ++ ;
F_3 ( & V_2 -> V_3 . V_12 . V_13 ) ;
F_4 ( V_2 -> V_3 . V_12 . V_14 ) ;
if ( V_2 -> V_3 . V_12 . V_14 & V_15 ) {
F_5 ( V_16 ,
& V_2 -> V_3 . V_4 -> V_17 ) ;
V_2 -> V_3 . V_12 . V_14 &= ~ V_15 ;
F_6 ( V_2 , 3 , L_1 , L_2 ) ;
V_10 = - V_18 ;
}
if ( V_2 -> V_3 . V_12 . V_14 & V_19 ) {
V_2 -> V_3 . V_12 . V_14 &= ~ V_19 ;
F_7 ( & V_2 -> V_3 . V_12 . V_13 ) ;
V_10 = F_8 ( V_2 ,
V_20 ) ;
if ( V_10 >= 0 )
V_10 = - V_18 ;
} else
F_7 ( & V_2 -> V_3 . V_12 . V_13 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_21 = V_2 -> V_3 . V_4 -> V_22 >> 16 ;
V_2 -> V_6 . V_23 ++ ;
F_10 ( V_2 , V_21 ) ;
F_11 ( true , L_3 , V_21 ) ;
return - V_18 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_24 ;
V_2 -> V_6 . V_25 ++ ;
F_13 ( V_2 ,
V_2 -> V_3 . V_4 -> V_26 ,
V_2 -> V_3 . V_4 -> V_22 ) ;
V_24 = V_27 [ V_2 -> V_3 . V_4 -> V_26 >> 8 ] ;
if ( V_24 )
return V_24 ( V_2 ) ;
return - V_18 ;
}
static int F_14 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_28 ++ ;
if ( F_15 ( V_2 ) &&
! ( V_29 -> V_30 . V_31 & V_32 ) &&
F_16 ( V_2 ) ) {
F_17 ( V_2 , V_33 , V_2 -> V_3 . V_4 -> V_34 ,
sizeof( struct V_35 ) ) ;
memset ( ( void * ) V_2 -> V_3 . V_4 -> V_34 , 0 ,
sizeof( struct V_35 ) ) ;
}
F_18 ( V_2 , V_2 -> V_3 . V_4 -> V_36 ) ;
return F_19 ( V_2 , V_2 -> V_3 . V_4 -> V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_10 , V_37 ;
V_2 -> V_6 . V_38 ++ ;
V_10 = F_12 ( V_2 ) ;
V_37 = F_14 ( V_2 ) ;
if ( V_10 == - V_18 )
V_2 -> V_3 . V_4 -> V_5 = 0x04 ;
if ( V_10 )
return V_10 ;
return V_37 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_1 V_39 ;
T_2 V_40 = V_2 -> V_3 . V_4 -> V_5 ;
if ( V_40 & 3 || ( V_40 >> 2 ) >= F_22 ( V_41 ) )
return - V_18 ;
V_39 = V_41 [ V_40 >> 2 ] ;
if ( V_39 )
return V_39 ( V_2 ) ;
return - V_18 ;
}
