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
T_2 int F_9 ( void )
{
switch ( V_15 . V_16 ) {
case 1 :
case 3 :
case 5 :
case 6 :
case 7 :
case 8 :
case 11 :
case 9 :
case 13 :
break;
default:
F_10 ( L_1 ,
V_15 . V_16 ) ;
return - V_17 ;
}
V_18 = V_19 ;
memcpy ( V_20 , V_21 ,
sizeof( V_20 ) ) ;
return 0 ;
}
