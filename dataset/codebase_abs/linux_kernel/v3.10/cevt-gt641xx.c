void F_1 ( unsigned int clock )
{
V_1 = clock ;
}
int F_2 ( void )
{
if ( F_3 ( V_2 ) )
return 0 ;
F_4 ( V_2 , V_1 / V_3 ) ;
F_4 ( V_4 , V_5 ) ;
return 1 ;
}
static int F_5 ( unsigned long V_6 ,
struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 &= ~ ( V_5 | V_11 ) ;
V_9 |= V_5 ;
F_4 ( V_2 , V_6 ) ;
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static void F_8 ( enum V_12 V_13 ,
struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 &= ~ ( V_5 | V_11 ) ;
switch ( V_13 ) {
case V_14 :
V_9 |= V_5 | V_11 ;
break;
case V_15 :
V_9 |= V_5 ;
break;
default:
break;
}
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
}
static void F_9 ( struct V_7 * V_16 )
{
}
static T_2 F_10 ( int V_17 , void * V_18 )
{
struct V_7 * V_19 = & V_20 ;
V_19 -> V_21 ( V_19 ) ;
return V_22 ;
}
static int T_3 F_11 ( void )
{
struct V_7 * V_19 ;
if ( ! V_1 )
return 0 ;
F_4 ( V_2 , V_1 / V_3 ) ;
V_19 = & V_20 ;
V_19 -> V_23 = 200 + V_1 / 10000000 ;
F_12 ( V_19 , V_1 ) ;
V_19 -> V_24 = F_13 ( 0x7fffffff , V_19 ) ;
V_19 -> V_25 = F_13 ( 0x300 , V_19 ) ;
V_19 -> V_26 = F_14 ( 0 ) ;
F_15 ( & V_20 ) ;
return F_16 ( V_27 , & V_28 ) ;
}
