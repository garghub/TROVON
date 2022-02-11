static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
int V_11 = - V_12 ;
T_1 V_13 ;
T_1 V_14 ;
bool V_15 = V_4 -> V_16 ? true : false ;
F_2 ( L_1 , V_17 ) ;
F_2 ( L_2 , V_15 ) ;
V_13 = V_2 -> V_18 -> V_19 -> V_20 . V_21 ;
F_2 ( L_3 , V_13 ) ;
V_14 = V_8 -> V_20 . V_22 ;
F_2 ( L_4 , V_14 ) ;
V_6 = F_3 ( sizeof( struct V_5 ) ,
V_23 ) ;
if ( ! V_6 )
return - V_24 ;
F_4 ( & V_6 -> V_25 ) ;
switch ( V_13 ) {
case 1 :
if ( V_2 -> V_9 -> V_26 == 2 )
V_8 = & V_2 -> V_9 -> V_27 [ 1 ] ;
else if ( V_2 -> V_9 -> V_26 > 2 )
break;
if ( V_8 -> V_20 . V_28 == 2 &&
F_5 ( & V_8 -> V_29 [ 0 ] . V_20 ) &&
F_6 ( & V_8 -> V_29 [ 1 ] . V_20 ) ) {
F_2 ( L_5 ) ;
if ( V_2 -> V_9 -> V_26 == 1 ) {
V_11 = 0 ;
break;
}
V_11 = F_7 ( V_2 -> V_18 , V_14 , 1 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_18 -> V_18 ,
L_6 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
}
break;
case 3 :
case 4 :
if ( V_14 == 1 && ! V_15 ) {
F_2 ( L_7 ) ;
V_11 = F_7 ( V_2 -> V_18 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_18 -> V_18 ,
L_6 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
} else if ( V_14 == 2 ) {
F_2 ( L_8 ) ;
V_11 = F_7 ( V_2 -> V_18 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_18 -> V_18 ,
L_6 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
} else if ( V_14 == 3 && ! V_15 ) {
F_2 ( L_9 ) ;
V_11 = F_7 ( V_2 -> V_18 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_18 -> V_18 ,
L_6 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
}
break;
default:
F_8 ( & V_2 -> V_18 -> V_18 ,
L_10 , V_13 ) ;
F_9 ( V_6 ) ;
V_11 = - V_12 ;
}
if ( V_11 != - V_12 )
F_10 ( V_2 , V_6 ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_30 = F_12 ( V_2 ) ;
F_2 ( L_1 , V_17 ) ;
F_13 ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_9 ( V_30 ) ;
}
