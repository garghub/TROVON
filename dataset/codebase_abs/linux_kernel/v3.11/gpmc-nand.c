static bool F_1 ( enum V_1 V_2 )
{
if ( ! F_2 () && ! F_3 () ) {
F_4 ( L_1 ) ;
return 0 ;
}
if ( ( V_2 == V_3 ) &&
( ! F_5 () || ( F_6 () == 0 ) ) &&
( ! F_3 () ) ) {
F_4 ( L_2 ) ;
return 0 ;
}
return 1 ;
}
int F_7 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 = 0 ;
struct V_9 V_10 ;
struct V_11 * V_12 = & V_13 . V_12 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_13 . V_12 . V_14 = V_5 ;
V_8 = F_8 ( V_5 -> V_15 , V_16 ,
( unsigned long * ) & V_17 [ 0 ] . V_18 ) ;
if ( V_8 < 0 ) {
F_9 ( V_12 , L_3 ,
V_5 -> V_15 , V_8 ) ;
return V_8 ;
}
V_17 [ 0 ] . V_19 = V_17 [ 0 ] . V_18 +
V_16 - 1 ;
V_17 [ 1 ] . V_18 =
F_10 ( V_20 ) ;
V_17 [ 2 ] . V_18 =
F_10 ( V_21 ) ;
if ( V_7 ) {
V_8 = F_11 ( V_5 -> V_15 , V_7 ) ;
if ( V_8 < 0 ) {
F_9 ( V_12 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_5 -> V_22 ) {
F_12 ( V_5 -> V_22 , & V_10 ) ;
} else {
if ( V_5 -> V_23 ) {
V_10 . V_24 = true ;
V_10 . V_25 = true ;
}
}
V_10 . V_26 = true ;
if ( V_5 -> V_27 == V_28 )
V_10 . V_29 = V_30 ;
else
V_10 . V_29 = V_31 ;
V_8 = F_13 ( V_5 -> V_15 , & V_10 ) ;
if ( V_8 < 0 )
goto V_32;
V_8 = F_14 ( V_33 , 0 ) ;
if ( V_8 < 0 )
goto V_32;
}
F_15 ( & V_5 -> V_34 , V_5 -> V_15 ) ;
if ( ! F_1 ( V_5 -> V_2 ) )
return - V_35 ;
V_8 = F_16 ( & V_13 ) ;
if ( V_8 < 0 ) {
F_9 ( V_12 , L_5 ) ;
goto V_32;
}
return 0 ;
V_32:
F_17 ( V_5 -> V_15 ) ;
return V_8 ;
}
