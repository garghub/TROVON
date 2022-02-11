static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 & V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_11 ;
unsigned char * V_12 = F_4 ( V_6 , V_2 -> V_13 ) + V_2 -> V_14 ;
T_1 V_15 = 0 ;
if ( ! F_5 ( V_6 , V_12 , V_2 -> V_16 ) )
return 0 ;
switch ( V_2 -> V_16 ) {
case V_17 :
V_15 = * V_12 ;
break;
case V_18 :
V_15 = F_6 ( V_12 ) ;
if ( F_1 ( V_2 ) )
V_15 = F_7 ( V_15 ) ;
break;
case V_19 :
V_15 = F_8 ( V_12 ) ;
if ( F_1 ( V_2 ) )
V_15 = F_9 ( V_15 ) ;
break;
default:
return 0 ;
}
if ( V_2 -> V_20 )
V_15 &= V_2 -> V_20 ;
switch ( V_2 -> V_21 ) {
case V_22 :
return V_15 == V_2 -> V_15 ;
case V_23 :
return V_15 < V_2 -> V_15 ;
case V_24 :
return V_15 > V_2 -> V_15 ;
}
return 0 ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_25 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_25 ) ;
}
