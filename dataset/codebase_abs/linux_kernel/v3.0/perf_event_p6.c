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
struct V_9 * V_10 = & F_7 ( V_9 ) ;
struct V_11 * V_12 = & V_8 -> V_13 ;
T_1 V_3 = V_14 ;
if ( V_10 -> V_15 )
V_3 |= V_5 ;
( void ) F_8 ( V_12 -> V_16 , V_3 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & F_7 ( V_9 ) ;
struct V_11 * V_12 = & V_8 -> V_13 ;
T_1 V_3 ;
V_3 = V_12 -> V_17 ;
if ( V_10 -> V_15 )
V_3 |= V_5 ;
( void ) F_8 ( V_12 -> V_16 , V_3 ) ;
}
static T_2 int F_10 ( void )
{
switch ( V_18 . V_19 ) {
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
F_11 ( L_1 ,
V_18 . V_19 ) ;
return - V_20 ;
}
V_21 = V_22 ;
return 0 ;
}
