static T_1 F_1 ( T_2 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 ) ;
T_3 V_5 ;
T_3 V_6 ;
int V_7 = V_1 -> V_8 ;
T_4 V_9 [ 2 ] ;
F_3 ( V_3 , 0x40 , & V_5 ) ;
if ( V_5 & ( 1 << 23 ) ) {
V_9 [ 0 ] = V_10 ;
V_9 [ 1 ] = V_11 ;
} else {
V_9 [ 0 ] = V_10 ;
V_9 [ 1 ] = V_10 ;
}
F_3 ( V_3 , 0x80 , & V_6 ) ;
if ( V_6 & ( 1 << 24 ) )
V_9 [ 0 ] = V_12 ;
if ( V_5 & ( 1 << 22 ) )
V_7 = V_7 ^ 1 ;
switch ( V_9 [ V_7 ] ) {
case V_11 :
if ( V_5 & ( 1 << 3 ) )
return V_13 ;
return V_14 ;
case V_12 :
if ( V_6 & ( 1 << 19 ) )
return V_13 ;
return V_14 ;
case V_10 :
break;
}
return V_14 ;
}
static void F_4 ( T_2 * V_1 , T_5 * V_15 )
{
}
static void F_5 ( T_2 * V_1 , T_5 * V_15 )
{
}
static int T_6 F_6 ( struct V_2 * V_4 , const struct V_16 * V_17 )
{
return F_7 ( V_4 , & V_18 , NULL ) ;
}
static int T_7 F_8 ( void )
{
return F_9 ( & V_19 ) ;
}
static void T_8 F_10 ( void )
{
F_11 ( & V_19 ) ;
}
