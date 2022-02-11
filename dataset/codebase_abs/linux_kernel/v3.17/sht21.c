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
int V_4 = 0 ;
struct V_5 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_5 ( & V_5 -> V_8 ) ;
if ( F_6 ( V_9 , V_5 -> V_10 + V_11 / 2 ) || ! V_5 -> V_12 ) {
V_4 = F_7 ( V_7 ,
V_13 ) ;
if ( V_4 < 0 )
goto V_14;
V_5 -> V_15 = F_1 ( V_4 ) ;
V_4 = F_7 ( V_7 ,
V_16 ) ;
if ( V_4 < 0 )
goto V_14;
V_5 -> V_17 = F_2 ( V_4 ) ;
V_5 -> V_10 = V_9 ;
V_5 -> V_12 = 1 ;
}
V_14:
F_8 ( & V_5 -> V_8 ) ;
return V_4 >= 0 ? 0 : V_4 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_15 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_17 ) ;
}
static int F_11 ( struct V_6 * V_7 ,
const struct V_21 * V_22 )
{
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_2 * V_23 ;
struct V_5 * V_5 ;
if ( ! F_12 ( V_7 -> V_24 ,
V_25 ) ) {
F_13 ( & V_7 -> V_3 ,
L_2 ) ;
return - V_26 ;
}
V_5 = F_14 ( V_3 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
V_5 -> V_7 = V_7 ;
F_15 ( & V_5 -> V_8 ) ;
V_23 = F_16 ( V_3 , V_7 -> V_29 ,
V_5 , V_30 ) ;
return F_17 ( V_23 ) ;
}
