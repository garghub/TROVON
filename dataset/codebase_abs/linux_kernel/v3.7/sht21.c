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
F_5 ( & V_5 -> V_6 ) ;
if ( F_6 ( V_7 , V_5 -> V_8 + V_9 / 2 ) || ! V_5 -> V_10 ) {
V_4 = F_7 ( V_3 ,
V_11 ) ;
if ( V_4 < 0 )
goto V_12;
V_5 -> V_13 = F_1 ( V_4 ) ;
V_4 = F_7 ( V_3 ,
V_14 ) ;
if ( V_4 < 0 )
goto V_12;
V_5 -> V_15 = F_2 ( V_4 ) ;
V_5 -> V_8 = V_7 ;
V_5 -> V_10 = 1 ;
}
V_12:
F_8 ( & V_5 -> V_6 ) ;
return V_4 >= 0 ? 0 : V_4 ;
}
static T_1 F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_2 * V_3 = F_10 ( V_17 ) ;
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_13 ) ;
}
static T_1 F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_2 * V_3 = F_10 ( V_17 ) ;
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_15 ) ;
}
static int T_2 F_12 ( struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
struct V_5 * V_5 ;
int V_23 ;
if ( ! F_13 ( V_3 -> V_24 ,
V_25 ) ) {
F_14 ( & V_3 -> V_17 ,
L_2 ) ;
return - V_26 ;
}
V_5 = F_15 ( & V_3 -> V_17 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
F_16 ( V_3 , V_5 ) ;
F_17 ( & V_5 -> V_6 ) ;
V_23 = F_18 ( & V_3 -> V_17 . V_29 , & V_30 ) ;
if ( V_23 ) {
F_19 ( & V_3 -> V_17 , L_3 ) ;
return V_23 ;
}
V_5 -> V_31 = F_20 ( & V_3 -> V_17 ) ;
if ( F_21 ( V_5 -> V_31 ) ) {
F_19 ( & V_3 -> V_17 , L_4 ) ;
V_23 = F_22 ( V_5 -> V_31 ) ;
goto V_32;
}
F_23 ( & V_3 -> V_17 , L_5 ) ;
return 0 ;
V_32:
F_24 ( & V_3 -> V_17 . V_29 , & V_30 ) ;
return V_23 ;
}
static int T_3 F_25 ( struct V_2 * V_3 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
F_26 ( V_5 -> V_31 ) ;
F_24 ( & V_3 -> V_17 . V_29 , & V_30 ) ;
return 0 ;
}
