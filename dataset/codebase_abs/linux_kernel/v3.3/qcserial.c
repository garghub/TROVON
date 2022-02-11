static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
int V_11 = - V_12 ;
T_1 V_13 ;
T_1 V_14 ;
F_2 ( L_1 , V_15 ) ;
V_13 = V_2 -> V_16 -> V_17 -> V_18 . V_19 ;
F_2 ( L_2 , V_13 ) ;
V_14 = V_8 -> V_18 . V_20 ;
F_2 ( L_3 , V_14 ) ;
V_6 = F_3 ( sizeof( struct V_5 ) ,
V_21 ) ;
if ( ! V_6 )
return - V_22 ;
F_4 ( & V_6 -> V_23 ) ;
switch ( V_13 ) {
case 1 :
if ( V_2 -> V_9 -> V_24 == 2 )
V_8 = & V_2 -> V_9 -> V_25 [ 1 ] ;
else if ( V_2 -> V_9 -> V_24 > 2 )
break;
if ( V_8 -> V_18 . V_26 == 2 &&
F_5 ( & V_8 -> V_27 [ 0 ] . V_18 ) &&
F_6 ( & V_8 -> V_27 [ 1 ] . V_18 ) ) {
F_2 ( L_4 ) ;
if ( V_2 -> V_9 -> V_24 == 1 ) {
V_11 = 0 ;
break;
}
V_11 = F_7 ( V_2 -> V_16 , V_14 , 1 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_16 -> V_16 ,
L_5 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
}
break;
case 3 :
case 4 :
if ( V_14 == 1 ) {
F_2 ( L_6 ) ;
V_11 = F_7 ( V_2 -> V_16 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_16 -> V_16 ,
L_5 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
} else if ( V_14 == 2 ) {
F_2 ( L_7 ) ;
V_11 = F_7 ( V_2 -> V_16 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_16 -> V_16 ,
L_5 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
} else if ( V_14 == 3 ) {
F_2 ( L_8 ) ;
V_11 = F_7 ( V_2 -> V_16 , V_14 , 0 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_16 -> V_16 ,
L_5 ,
V_11 ) ;
V_11 = - V_12 ;
F_9 ( V_6 ) ;
}
}
break;
default:
F_8 ( & V_2 -> V_16 -> V_16 ,
L_9 , V_13 ) ;
F_9 ( V_6 ) ;
V_11 = - V_12 ;
}
if ( V_11 != - V_12 )
F_10 ( V_2 , V_6 ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_28 = F_12 ( V_2 ) ;
F_2 ( L_1 , V_15 ) ;
F_13 ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_9 ( V_28 ) ;
}
static int T_2 F_14 ( void )
{
int V_11 ;
V_11 = F_15 ( & V_29 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_16 ( & V_30 ) ;
if ( V_11 ) {
F_17 ( & V_29 ) ;
return V_11 ;
}
return 0 ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_30 ) ;
F_17 ( & V_29 ) ;
}
