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
static inline int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_5 = F_4 ( V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_5 ( V_5 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
int V_5 = 0 ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
F_8 ( & V_6 -> V_7 ) ;
if ( F_9 ( V_8 , V_6 -> V_9 + V_10 / 2 ) || ! V_6 -> V_11 ) {
V_5 = F_3 ( V_3 , V_12 ) ;
if ( V_5 < 0 )
goto V_13;
V_6 -> V_14 = F_1 ( V_5 ) ;
V_5 = F_3 ( V_3 ,
V_15 ) ;
if ( V_5 < 0 )
goto V_13;
V_6 -> V_16 = F_2 ( V_5 ) ;
V_6 -> V_9 = V_8 ;
V_6 -> V_11 = 1 ;
}
V_13:
F_10 ( & V_6 -> V_7 ) ;
return V_5 >= 0 ? 0 : V_5 ;
}
static T_2 F_11 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
int V_5 = F_6 ( V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
return sprintf ( V_21 , L_1 , V_6 -> V_14 ) ;
}
static T_2 F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
int V_5 = F_6 ( V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
return sprintf ( V_21 , L_1 , V_6 -> V_16 ) ;
}
static int T_3 F_14 ( struct V_2 * V_3 ,
const struct V_22 * V_23 )
{
struct V_6 * V_6 ;
int V_24 ;
if ( ! F_15 ( V_3 -> V_25 ,
V_26 ) ) {
F_16 ( & V_3 -> V_18 ,
L_2 ) ;
return - V_27 ;
}
V_6 = F_17 ( sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 ) {
F_18 ( & V_3 -> V_18 , L_3 ) ;
return - V_29 ;
}
F_19 ( V_3 , V_6 ) ;
F_20 ( & V_6 -> V_7 ) ;
V_24 = F_21 ( & V_3 -> V_18 . V_30 , & V_31 ) ;
if ( V_24 ) {
F_18 ( & V_3 -> V_18 , L_4 ) ;
goto V_32;
}
V_6 -> V_33 = F_22 ( & V_3 -> V_18 ) ;
if ( F_23 ( V_6 -> V_33 ) ) {
F_18 ( & V_3 -> V_18 , L_5 ) ;
V_24 = F_24 ( V_6 -> V_33 ) ;
goto V_34;
}
F_25 ( & V_3 -> V_18 , L_6 ) ;
return 0 ;
V_34:
F_26 ( & V_3 -> V_18 . V_30 , & V_31 ) ;
V_32:
F_27 ( V_6 ) ;
return V_24 ;
}
static int T_4 F_28 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
F_29 ( V_6 -> V_33 ) ;
F_26 ( & V_3 -> V_18 . V_30 , & V_31 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int T_5 F_30 ( void )
{
return F_31 ( & V_35 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_35 ) ;
}
