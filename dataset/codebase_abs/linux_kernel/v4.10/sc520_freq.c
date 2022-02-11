static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 = * V_3 ;
switch ( V_2 & 0x03 ) {
default:
F_2 ( L_1 ,
V_2 ) ;
case 0x01 :
return 100000 ;
case 0x02 :
return 133000 ;
}
}
static int F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
T_1 V_2 ;
F_4 () ;
V_2 = * V_3 & ~ 0x03 ;
* V_3 = V_2 | V_7 [ V_6 ] . V_8 ;
F_5 () ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = & F_7 ( 0 ) ;
if ( V_10 -> V_11 != V_12 ||
V_10 -> V_13 != 4 || V_10 -> V_14 != 9 )
return - V_15 ;
V_5 -> V_16 . V_17 = 1000000 ;
return F_8 ( V_5 , V_7 ) ;
}
static int T_2 F_9 ( void )
{
int V_18 ;
if ( ! F_10 ( V_19 ) )
return - V_15 ;
V_3 = F_11 ( ( unsigned long ) ( V_20 + V_21 ) , 1 ) ;
if ( ! V_3 ) {
F_2 ( L_2 ) ;
return - V_22 ;
}
V_18 = F_12 ( & V_23 ) ;
if ( V_18 )
F_13 ( V_3 ) ;
return V_18 ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_23 ) ;
F_13 ( V_3 ) ;
}
