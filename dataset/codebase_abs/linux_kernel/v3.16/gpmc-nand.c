static bool F_1 ( enum V_1 V_2 )
{
if ( F_2 () || F_3 () || F_4 () ||
F_5 () || F_6 () )
return 1 ;
if ( V_2 == V_3 ||
V_2 == V_4 ) {
if ( F_7 () )
return 0 ;
else if ( F_8 () && ( F_9 () == 0 ) )
return 0 ;
else
return 1 ;
}
if ( ( F_10 () || F_8 () ) &&
( ( V_2 == V_5 ) ||
( V_2 == V_6 ) ) )
return 0 ;
if ( V_2 == V_7 )
return 1 ;
else
return 0 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
V_11 -> V_13 = true ;
V_11 -> V_14 = true ;
}
if ( V_9 -> V_15 == V_16 )
V_11 -> V_17 = V_18 ;
else
V_11 -> V_17 = V_19 ;
}
int F_12 ( struct V_8 * V_9 ,
struct V_20 * V_21 )
{
int V_22 = 0 ;
struct V_10 V_11 ;
struct V_23 * V_24 = & V_25 . V_24 ;
memset ( & V_11 , 0 , sizeof( struct V_10 ) ) ;
V_25 . V_24 . V_26 = V_9 ;
V_22 = F_13 ( V_9 -> V_27 , V_28 ,
( unsigned long * ) & V_29 [ 0 ] . V_30 ) ;
if ( V_22 < 0 ) {
F_14 ( V_24 , L_1 ,
V_9 -> V_27 , V_22 ) ;
return V_22 ;
}
V_29 [ 0 ] . V_31 = V_29 [ 0 ] . V_30 +
V_28 - 1 ;
V_29 [ 1 ] . V_30 =
F_15 ( V_32 ) ;
V_29 [ 2 ] . V_30 =
F_15 ( V_33 ) ;
if ( V_21 ) {
V_22 = F_16 ( V_9 -> V_27 , V_21 ) ;
if ( V_22 < 0 ) {
F_14 ( V_24 , L_2 , V_22 ) ;
return V_22 ;
}
}
if ( V_9 -> V_34 )
F_17 ( V_9 -> V_34 , & V_11 ) ;
else
F_11 ( V_9 , & V_11 ) ;
V_11 . V_35 = true ;
V_22 = F_18 ( V_9 -> V_27 , & V_11 ) ;
if ( V_22 < 0 )
goto V_36;
V_22 = F_19 ( V_37 , 0 ) ;
if ( V_22 < 0 )
goto V_36;
F_20 ( & V_9 -> V_38 , V_9 -> V_27 ) ;
if ( ! F_1 ( V_9 -> V_2 ) ) {
F_14 ( V_24 , L_3 ) ;
return - V_39 ;
}
V_22 = F_21 ( & V_25 ) ;
if ( V_22 < 0 ) {
F_14 ( V_24 , L_4 ) ;
goto V_36;
}
return 0 ;
V_36:
F_22 ( V_9 -> V_27 ) ;
return V_22 ;
}
