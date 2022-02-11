static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
V_4 -> V_2 [ V_4 -> V_7 ] = V_2 ;
switch ( V_4 -> V_7 ++ ) {
case 0 :
if ( ( V_4 -> V_2 [ 0 ] & V_8 ) !=
V_9 ) {
F_3 ( L_1 , V_2 ) ;
V_4 -> V_7 = 0 ;
}
break;
case 4 :
V_4 -> V_7 = 0 ;
F_4 ( V_6 , V_10 ,
( V_4 -> V_2 [ 1 ] << 7 ) | V_4 -> V_2 [ 2 ] ) ;
F_4 ( V_6 , V_11 ,
( V_4 -> V_2 [ 3 ] << 7 ) | V_4 -> V_2 [ 4 ] ) ;
F_5 ( V_6 , V_12 ,
V_4 -> V_2 [ 0 ] & V_13 ) ;
F_6 ( V_6 ) ;
break;
}
return V_14 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_8 ( V_4 -> V_6 ) ;
F_9 ( V_4 -> V_6 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 , NULL ) ;
F_12 ( V_4 -> V_6 ) ;
F_13 ( V_4 ) ;
}
static int F_14 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
int V_17 ;
V_4 = F_15 ( sizeof( struct V_4 ) , V_18 ) ;
V_5 = F_16 () ;
if ( ! V_4 || ! V_5 ) {
V_17 = - V_19 ;
goto V_20;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_5 ;
snprintf ( V_4 -> V_21 , sizeof( V_4 -> V_21 ) ,
L_2 , V_1 -> V_21 ) ;
V_5 -> V_22 = L_3 ;
V_5 -> V_21 = V_4 -> V_21 ;
V_5 -> V_23 . V_24 = V_25 ;
V_5 -> V_23 . V_26 = V_27 ;
V_5 -> V_23 . V_28 = 0 ;
V_5 -> V_23 . V_29 = 0x0100 ;
V_5 -> V_6 . V_30 = & V_1 -> V_6 ;
V_5 -> V_31 [ 0 ] = F_17 ( V_32 ) | F_17 ( V_33 ) ;
V_5 -> V_34 [ F_18 ( V_12 ) ] = F_17 ( V_12 ) ;
F_19 ( V_4 -> V_6 , V_10 ,
V_35 , V_36 , 0 , 0 ) ;
F_19 ( V_4 -> V_6 , V_11 ,
V_37 , V_38 , 0 , 0 ) ;
F_11 ( V_1 , V_4 ) ;
V_17 = F_20 ( V_1 , V_16 ) ;
if ( V_17 )
goto V_39;
V_17 = F_21 ( V_4 -> V_6 ) ;
if ( V_17 )
goto V_40;
return 0 ;
V_40: F_10 ( V_1 ) ;
V_39: F_11 ( V_1 , NULL ) ;
V_20: F_22 ( V_5 ) ;
F_13 ( V_4 ) ;
return V_17 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_41 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_41 ) ;
}
