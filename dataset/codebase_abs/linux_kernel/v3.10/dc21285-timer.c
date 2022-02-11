static T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - * V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
* V_5 = V_2 -> V_3 ;
* V_6 = 0 ;
* V_7 = V_8 | V_9 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
* V_7 = 0 ;
}
static void F_4 ( enum V_10 V_11 ,
struct V_12 * V_13 )
{
switch ( V_11 ) {
case V_14 :
case V_15 :
* V_16 = 0 ;
* V_17 = ( V_18 + 8 * V_19 ) / ( 16 * V_19 ) ;
* V_20 = V_8 | V_21 |
V_9 ;
break;
default:
* V_20 = 0 ;
break;
}
}
static T_2 F_5 ( int V_22 , void * V_23 )
{
struct V_12 * V_24 = V_23 ;
* V_16 = 0 ;
V_24 -> V_25 ( V_24 ) ;
return V_26 ;
}
void T_3 F_6 ( void )
{
struct V_12 * V_24 = & V_27 ;
F_7 ( & V_28 , ( V_18 + 8 ) / 16 ) ;
F_8 ( V_24 -> V_22 , & V_29 ) ;
V_24 -> V_30 = F_9 ( F_10 () ) ;
F_11 ( V_24 , V_18 , 0x4 , 0xffffff ) ;
}
