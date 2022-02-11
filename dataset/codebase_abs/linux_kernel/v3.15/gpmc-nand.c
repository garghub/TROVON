static bool F_1 ( enum V_1 V_2 )
{
if ( F_2 () || F_3 () ||
F_4 () || F_5 () )
return 1 ;
if ( ( F_6 () || F_7 () ) &&
( ( V_2 == V_3 ) ||
( V_2 == V_4 ) ) )
return 0 ;
if ( ( V_2 == V_5 ) &&
( ! F_7 () || ( F_8 () == 0 ) ) )
return 0 ;
if ( V_2 == V_6 )
return 1 ;
else
return 0 ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
V_10 -> V_12 = true ;
V_10 -> V_13 = true ;
}
if ( V_8 -> V_14 == V_15 )
V_10 -> V_16 = V_17 ;
else
V_10 -> V_16 = V_18 ;
}
int F_10 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
struct V_9 V_10 ;
struct V_22 * V_23 = & V_24 . V_23 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_24 . V_23 . V_25 = V_8 ;
V_21 = F_11 ( V_8 -> V_26 , V_27 ,
( unsigned long * ) & V_28 [ 0 ] . V_29 ) ;
if ( V_21 < 0 ) {
F_12 ( V_23 , L_1 ,
V_8 -> V_26 , V_21 ) ;
return V_21 ;
}
V_28 [ 0 ] . V_30 = V_28 [ 0 ] . V_29 +
V_27 - 1 ;
V_28 [ 1 ] . V_29 =
F_13 ( V_31 ) ;
V_28 [ 2 ] . V_29 =
F_13 ( V_32 ) ;
if ( V_20 ) {
V_21 = F_14 ( V_8 -> V_26 , V_20 ) ;
if ( V_21 < 0 ) {
F_12 ( V_23 , L_2 , V_21 ) ;
return V_21 ;
}
}
if ( V_8 -> V_33 )
F_15 ( V_8 -> V_33 , & V_10 ) ;
else
F_9 ( V_8 , & V_10 ) ;
V_10 . V_34 = true ;
V_21 = F_16 ( V_8 -> V_26 , & V_10 ) ;
if ( V_21 < 0 )
goto V_35;
V_21 = F_17 ( V_36 , 0 ) ;
if ( V_21 < 0 )
goto V_35;
F_18 ( & V_8 -> V_37 , V_8 -> V_26 ) ;
if ( ! F_1 ( V_8 -> V_2 ) ) {
F_12 ( V_23 , L_3 ) ;
return - V_38 ;
}
V_21 = F_19 ( & V_24 ) ;
if ( V_21 < 0 ) {
F_12 ( V_23 , L_4 ) ;
goto V_35;
}
return 0 ;
V_35:
F_20 ( V_8 -> V_26 ) ;
return V_21 ;
}
