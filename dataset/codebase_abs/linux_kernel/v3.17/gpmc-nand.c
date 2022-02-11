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
if ( V_2 == V_7 ||
V_2 == V_8 )
return 1 ;
else
return 0 ;
}
static void F_11 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
if ( V_10 -> V_13 ) {
V_12 -> V_14 = true ;
V_12 -> V_15 = true ;
}
if ( V_10 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_20 ;
}
int F_12 ( struct V_9 * V_10 ,
struct V_21 * V_22 )
{
int V_23 = 0 ;
struct V_11 V_12 ;
struct V_24 * V_25 ;
struct V_26 V_27 [] = {
{ . V_28 = V_29 , } ,
{ . V_28 = V_30 , } ,
{ . V_28 = V_30 , } ,
} ;
F_13 ( V_10 -> V_31 >= V_32 ) ;
V_23 = F_14 ( V_10 -> V_31 , V_33 ,
( unsigned long * ) & V_27 [ 0 ] . V_34 ) ;
if ( V_23 < 0 ) {
F_15 ( L_1 ,
V_10 -> V_31 , V_23 ) ;
return V_23 ;
}
V_27 [ 0 ] . V_35 = V_27 [ 0 ] . V_34 + V_33 - 1 ;
V_27 [ 1 ] . V_34 = F_16 ( V_36 ) ;
V_27 [ 2 ] . V_34 = F_16 ( V_37 ) ;
if ( V_22 ) {
V_23 = F_17 ( V_10 -> V_31 , V_22 ) ;
if ( V_23 < 0 ) {
F_15 ( L_2 , V_23 ) ;
return V_23 ;
}
}
memset ( & V_12 , 0 , sizeof( struct V_11 ) ) ;
if ( V_10 -> V_38 )
F_18 ( V_10 -> V_38 , & V_12 ) ;
else
F_11 ( V_10 , & V_12 ) ;
V_12 . V_39 = true ;
V_23 = F_19 ( V_10 -> V_31 , & V_12 ) ;
if ( V_23 < 0 )
goto V_40;
V_23 = F_20 ( V_41 , 0 ) ;
if ( V_23 < 0 )
goto V_40;
F_21 ( & V_10 -> V_42 , V_10 -> V_31 ) ;
if ( ! F_1 ( V_10 -> V_2 ) ) {
F_15 ( L_3 ) ;
V_23 = - V_43 ;
goto V_40;
}
V_25 = F_22 ( L_4 , V_10 -> V_31 ) ;
if ( V_25 ) {
V_23 = F_23 ( V_25 , V_27 ,
F_24 ( V_27 ) ) ;
if ( ! V_23 )
V_25 -> V_44 . V_45 = V_10 ;
} else {
V_23 = - V_46 ;
}
if ( V_23 )
goto V_47;
V_23 = F_25 ( V_25 ) ;
if ( V_23 ) {
F_26 ( & V_25 -> V_44 , L_5 ) ;
goto V_47;
}
return 0 ;
V_47:
F_27 ( V_25 ) ;
V_40:
F_28 ( V_10 -> V_31 ) ;
return V_23 ;
}
