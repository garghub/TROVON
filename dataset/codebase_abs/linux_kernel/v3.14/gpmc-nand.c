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
static void F_7 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( V_5 -> V_8 ) {
V_7 -> V_9 = true ;
V_7 -> V_10 = true ;
}
if ( V_5 -> V_11 == V_12 )
V_7 -> V_13 = V_14 ;
else
V_7 -> V_13 = V_15 ;
}
int F_8 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
int V_18 = 0 ;
struct V_6 V_7 ;
struct V_19 * V_20 = & V_21 . V_20 ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_21 . V_20 . V_22 = V_5 ;
V_18 = F_9 ( V_5 -> V_23 , V_24 ,
( unsigned long * ) & V_25 [ 0 ] . V_26 ) ;
if ( V_18 < 0 ) {
F_10 ( V_20 , L_3 ,
V_5 -> V_23 , V_18 ) ;
return V_18 ;
}
V_25 [ 0 ] . V_27 = V_25 [ 0 ] . V_26 +
V_24 - 1 ;
V_25 [ 1 ] . V_26 =
F_11 ( V_28 ) ;
V_25 [ 2 ] . V_26 =
F_11 ( V_29 ) ;
if ( V_17 ) {
V_18 = F_12 ( V_5 -> V_23 , V_17 ) ;
if ( V_18 < 0 ) {
F_10 ( V_20 , L_4 , V_18 ) ;
return V_18 ;
}
}
if ( V_5 -> V_30 )
F_13 ( V_5 -> V_30 , & V_7 ) ;
else
F_7 ( V_5 , & V_7 ) ;
V_7 . V_31 = true ;
V_18 = F_14 ( V_5 -> V_23 , & V_7 ) ;
if ( V_18 < 0 )
goto V_32;
V_18 = F_15 ( V_33 , 0 ) ;
if ( V_18 < 0 )
goto V_32;
F_16 ( & V_5 -> V_34 , V_5 -> V_23 ) ;
if ( ! F_1 ( V_5 -> V_2 ) )
return - V_35 ;
V_18 = F_17 ( & V_21 ) ;
if ( V_18 < 0 ) {
F_10 ( V_20 , L_5 ) ;
goto V_32;
}
return 0 ;
V_32:
F_18 ( V_5 -> V_23 ) ;
return V_18 ;
}
