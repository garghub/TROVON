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
static int F_6 ( struct V_9 * V_10 )
{
T_1 V_11 ;
F_7 ( & V_12 ) ;
V_11 = F_2 ( V_13 ) ;
V_11 &= ~ V_14 ;
F_4 ( V_11 , V_13 ) ;
F_8 ( & V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
T_1 V_11 ;
F_7 ( & V_12 ) ;
V_11 = F_2 ( V_13 ) ;
V_11 |= V_14 ;
F_4 ( V_11 , V_13 ) ;
F_8 ( & V_12 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_15 )
{
}
static T_2 F_11 ( int V_16 , void * V_17 )
{
struct V_9 * V_18 = & V_19 ;
F_2 ( V_1 ) ;
V_18 -> V_20 ( V_18 ) ;
return V_21 ;
}
int T_3 F_12 ( int V_16 )
{
struct V_9 * V_18 ;
V_18 = & V_19 ;
V_18 -> V_22 = 100 ;
V_18 -> V_16 = V_16 ;
F_13 ( V_18 , 32768 ) ;
V_18 -> V_23 = F_14 ( 0x7fffffff , V_18 ) ;
V_18 -> V_24 = F_14 ( 0x300 , V_18 ) ;
V_18 -> V_25 = F_15 ( 0 ) ;
F_16 ( & V_19 ) ;
return F_17 ( V_16 , & V_26 ) ;
}
