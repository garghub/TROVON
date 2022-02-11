static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( void )
{
T_1 V_3 ;
F_3 ( V_4 , V_3 ) ;
V_3 &= ~ V_5 ;
F_4 ( V_4 , V_3 ) ;
}
static void F_5 ( int V_6 )
{
unsigned long V_3 ;
F_3 ( V_4 , V_3 ) ;
V_3 |= V_5 ;
F_4 ( V_4 , V_3 ) ;
}
static inline void
F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_11 ;
T_1 V_3 = V_12 ;
( void ) F_7 ( V_10 -> V_13 , V_3 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_11 ;
T_1 V_3 ;
V_3 = V_10 -> V_14 ;
( void ) F_7 ( V_10 -> V_13 , V_3 ) ;
}
static T_2 void F_9 ( void )
{
if ( V_15 . V_16 < 9 ) {
F_10 ( L_1 ) ;
V_17 . V_18 = 1 ;
V_17 . V_19 = 0 ;
}
}
T_2 int F_11 ( void )
{
V_17 = V_20 ;
switch ( V_15 . V_21 ) {
case 1 :
F_12 ( F_9 ) ;
break;
case 3 :
case 5 :
case 6 :
break;
case 7 :
case 8 :
case 10 :
case 11 :
break;
case 9 :
case 13 :
break;
default:
F_13 ( L_2 , V_15 . V_21 ) ;
return - V_22 ;
}
memcpy ( V_23 , V_24 ,
sizeof( V_23 ) ) ;
return 0 ;
}
