static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_7 = V_8 ;
unsigned long V_9 = 0 ;
switch ( V_5 -> V_10 ) {
case 0 :
V_5 -> V_11 = 300 +
( 6720 << V_12 ) / ( 5 * V_13 [ 0 ] + ( 7 << V_12 ) ) ;
V_5 -> V_11 =
F_2 ( V_5 -> V_11 ) ;
V_9 = F_2 ( 70 ) ;
V_5 -> V_10 ++ ;
V_7 = V_3 -> V_14 ;
break;
case 1 :
V_9 = V_5 -> V_11 / 4 - F_2 ( 70 ) ;
V_5 -> V_10 ++ ;
break;
case 2 :
V_9 = F_2 ( 70 ) ;
V_5 -> V_10 ++ ;
V_7 = V_3 -> V_14 ;
break;
default:
V_9 = V_5 -> V_11 - V_5 -> V_11 / 4 -
F_2 ( 70 ) ;
V_5 -> V_10 = 0 ;
break;
}
F_3 ( V_3 , V_7 ) ;
F_4 ( & V_5 -> V_15 , V_16 + V_9 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return;
V_3 -> V_6 = V_5 ;
F_7 ( & V_5 -> V_15 ,
F_1 , ( unsigned long ) V_3 ) ;
V_5 -> V_10 = 0 ;
F_1 ( V_5 -> V_15 . V_1 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 ) {
F_9 ( & V_5 -> V_15 ) ;
F_10 ( V_5 ) ;
}
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_18 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_18 ) ;
}
