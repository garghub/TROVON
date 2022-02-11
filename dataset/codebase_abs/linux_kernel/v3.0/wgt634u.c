static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 ;
if ( ! F_2 ( & V_4 . V_5 ,
V_6 ) )
return V_7 ;
V_3 = F_3 ( V_8 ) ;
F_4 ( V_8 , V_3 ) ;
if ( ! V_3 ) {
F_5 ( V_9 L_1 ) ;
F_6 () ;
}
return V_10 ;
}
static int T_2 F_7 ( void )
{
T_3 * V_11 = V_4 . V_12 . V_11 ;
if ( V_11 [ 0 ] == 0x00 &&
( ( V_11 [ 1 ] == 0x09 && V_11 [ 2 ] == 0x5b ) ||
( V_11 [ 1 ] == 0x0f && V_11 [ 2 ] == 0xb5 ) ) ) {
struct V_13 * V_14 = & V_4 . V_15 ;
F_5 ( V_9 L_2 ) ;
if ( ! F_8 ( F_9 ( V_8 ) ,
F_1 , V_16 ,
L_3 , & V_4 . V_5 ) ) {
F_10 ( V_8 ) ;
F_11 ( V_8 , 1 ) ;
F_12 ( & V_4 . V_5 ,
V_6 ,
V_6 ) ;
}
V_17 . V_18 = V_14 -> V_19 ;
V_20 . V_21 = V_14 -> V_22 ;
V_20 . V_23 = V_14 -> V_22
+ V_14 -> V_24
- 1 ;
return F_13 ( V_25 ,
F_14 ( V_25 ) ) ;
} else
return - V_26 ;
}
