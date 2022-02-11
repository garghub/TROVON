static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_20 ) )
return - 1 ;
V_14 = V_20 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
case 2 :
if ( V_14 >= F_3 ( V_21 ) )
return - 1 ;
V_14 = V_21 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_23 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_23 ) ;
}
