static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_7 = V_8 ;
unsigned long V_9 = 0 ;
if ( F_2 ( V_10 ) ) {
F_3 ( V_3 , V_8 ) ;
return;
}
switch ( V_5 -> V_11 ) {
case 0 :
V_5 -> V_12 = 300 +
( 6720 << V_13 ) / ( 5 * V_14 [ 0 ] + ( 7 << V_13 ) ) ;
V_5 -> V_12 =
F_4 ( V_5 -> V_12 ) ;
V_9 = F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
V_7 = V_3 -> V_15 ;
break;
case 1 :
V_9 = V_5 -> V_12 / 4 - F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
break;
case 2 :
V_9 = F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
V_7 = V_3 -> V_15 ;
break;
default:
V_9 = V_5 -> V_12 - V_5 -> V_12 / 4 -
F_4 ( 70 ) ;
V_5 -> V_11 = 0 ;
break;
}
F_3 ( V_3 , V_7 ) ;
F_5 ( & V_5 -> V_16 , V_17 + V_9 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return;
V_3 -> V_6 = V_5 ;
F_8 ( & V_5 -> V_16 ,
F_1 , ( unsigned long ) V_3 ) ;
V_5 -> V_11 = 0 ;
F_1 ( V_5 -> V_16 . V_1 ) ;
V_3 -> V_19 = true ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_19 ) {
F_10 ( & V_5 -> V_16 ) ;
F_11 ( V_5 ) ;
V_3 -> V_19 = false ;
}
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
F_13 ( & V_24 ) ;
return V_25 ;
}
static int F_14 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
V_10 = 1 ;
return V_25 ;
}
static int T_1 F_15 ( void )
{
int V_26 = F_16 ( & V_24 ) ;
if ( ! V_26 ) {
F_17 ( & V_27 ,
& V_28 ) ;
F_18 ( & V_29 ) ;
}
return V_26 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_29 ) ;
F_21 ( & V_27 ,
& V_28 ) ;
F_13 ( & V_24 ) ;
}
