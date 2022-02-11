static inline int F_1 ( int V_1 )
{
V_1 &= ~ 0x0003 ;
return ( ( 21965 * V_1 ) >> 13 ) - 46850 ;
}
static inline int F_2 ( int V_1 )
{
V_1 &= ~ 0x0003 ;
return ( ( 15625 * V_1 ) >> 13 ) - 6000 ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_4 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
F_5 ( & V_4 -> V_8 ) ;
if ( F_6 ( V_9 , V_4 -> V_10 + V_11 / 2 ) ||
! V_4 -> V_12 ) {
V_7 = F_7 ( V_6 ,
V_13 ) ;
if ( V_7 < 0 )
goto V_14;
V_4 -> V_15 = F_1 ( V_7 ) ;
V_7 = F_7 ( V_6 ,
V_16 ) ;
if ( V_7 < 0 )
goto V_14;
V_4 -> V_17 = F_2 ( V_7 ) ;
V_4 -> V_10 = V_9 ;
V_4 -> V_12 = true ;
}
V_14:
F_8 ( & V_4 -> V_8 ) ;
return V_7 >= 0 ? 0 : V_7 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_4 * V_4 = F_4 ( V_3 ) ;
int V_7 ;
V_7 = F_3 ( V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_20 , L_1 , V_4 -> V_15 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_4 * V_4 = F_4 ( V_3 ) ;
int V_7 ;
V_7 = F_3 ( V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_20 , L_1 , V_4 -> V_17 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_21 * V_22 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_4 * V_4 ;
struct V_2 * V_23 ;
if ( ! F_12 ( V_6 -> V_24 ,
V_25 ) ) {
F_13 ( & V_6 -> V_3 ,
L_2 ) ;
return - V_26 ;
}
V_4 = F_14 ( V_3 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_6 = V_6 ;
F_15 ( & V_4 -> V_8 ) ;
V_23 = F_16 ( V_3 , V_6 -> V_29 ,
V_4 ,
V_30 ) ;
return F_17 ( V_23 ) ;
}
