int F_1 ( void )
{
return ( F_2 ( V_1 ) & V_2 ) != 0 ;
}
int F_3 ( unsigned int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case 128 :
V_4 = 0x9 ;
break;
case 256 :
V_4 = 0x8 ;
break;
case 1024 :
V_4 = 0x6 ;
break;
default:
return - V_5 ;
}
F_4 ( V_6 | V_4 , V_7 ) ;
return 0 ;
}
static int F_5 ( unsigned long V_8 ,
struct V_9 * V_10 )
{
return - V_5 ;
}
static void F_6 ( enum V_11 V_12 ,
struct V_9 * V_10 )
{
T_1 V_13 ;
F_7 ( & V_14 ) ;
V_13 = F_2 ( V_15 ) ;
switch ( V_12 ) {
case V_16 :
V_13 |= V_17 ;
break;
default:
V_13 &= ~ V_17 ;
break;
}
F_4 ( V_13 , V_15 ) ;
F_8 ( & V_14 ) ;
}
static void F_9 ( struct V_9 * V_18 )
{
}
static T_2 F_10 ( int V_19 , void * V_20 )
{
struct V_9 * V_21 = & V_22 ;
F_2 ( V_1 ) ;
V_21 -> V_23 ( V_21 ) ;
return V_24 ;
}
int T_3 F_11 ( int V_19 )
{
struct V_9 * V_21 ;
V_21 = & V_22 ;
V_21 -> V_25 = 100 ;
V_21 -> V_19 = V_19 ;
F_12 ( V_21 , 32768 ) ;
V_21 -> V_26 = F_13 ( 0x7fffffff , V_21 ) ;
V_21 -> V_27 = F_13 ( 0x300 , V_21 ) ;
V_21 -> V_28 = F_14 ( 0 ) ;
F_15 ( & V_22 ) ;
return F_16 ( V_19 , & V_29 ) ;
}
