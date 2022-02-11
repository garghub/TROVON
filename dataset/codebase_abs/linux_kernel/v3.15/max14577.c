static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
break;
}
return false ;
}
static int F_2 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_10 ;
struct V_11 * V_12 = F_3 ( & V_7 -> V_2 ) ;
struct V_13 * V_14 = V_7 -> V_2 . V_15 ;
T_1 V_16 ;
int V_17 = 0 ;
if ( V_14 ) {
V_12 = F_4 ( & V_7 -> V_2 , sizeof( * V_12 ) , V_18 ) ;
if ( ! V_12 )
return - V_19 ;
V_7 -> V_2 . V_20 = V_12 ;
}
if ( ! V_12 ) {
F_5 ( & V_7 -> V_2 , L_1 ) ;
return - V_21 ;
}
V_10 = F_4 ( & V_7 -> V_2 , sizeof( * V_10 ) , V_18 ) ;
if ( ! V_10 )
return - V_19 ;
F_6 ( V_7 , V_10 ) ;
V_10 -> V_2 = & V_7 -> V_2 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_22 = V_7 -> V_22 ;
V_10 -> V_23 = F_7 ( V_7 , & V_24 ) ;
if ( F_8 ( V_10 -> V_23 ) ) {
V_17 = F_9 ( V_10 -> V_23 ) ;
F_5 ( V_10 -> V_2 , L_2 ,
V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_10 -> V_23 , V_25 ,
& V_16 ) ;
if ( V_17 ) {
F_5 ( V_10 -> V_2 , L_3 ,
V_17 ) ;
return V_17 ;
}
V_10 -> V_26 = ( ( V_16 & V_27 ) >>
V_28 ) ;
V_10 -> V_29 = ( ( V_16 & V_30 ) >>
V_31 ) ;
F_11 ( V_10 -> V_2 , L_4 ,
V_10 -> V_29 , V_10 -> V_26 ) ;
V_17 = F_12 ( V_10 -> V_23 , V_10 -> V_22 ,
V_32 | V_33 , 0 ,
& V_34 ,
& V_10 -> V_35 ) ;
if ( V_17 != 0 ) {
F_5 ( & V_7 -> V_2 , L_5 ,
V_10 -> V_22 , V_17 ) ;
return V_17 ;
}
V_17 = F_13 ( V_10 -> V_2 , - 1 , V_36 ,
F_14 ( V_36 ) , NULL , 0 ,
F_15 ( V_10 -> V_35 ) ) ;
if ( V_17 < 0 )
goto V_37;
F_16 ( V_10 -> V_2 , 1 ) ;
return 0 ;
V_37:
F_17 ( V_10 -> V_22 , V_10 -> V_35 ) ;
return V_17 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_10 * V_10 = F_19 ( V_7 ) ;
F_20 ( V_10 -> V_2 ) ;
F_17 ( V_10 -> V_22 , V_10 -> V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_22 ( V_2 , struct V_6 , V_2 ) ;
struct V_10 * V_10 = F_19 ( V_7 ) ;
if ( F_23 ( V_2 ) ) {
F_24 ( V_10 -> V_22 ) ;
F_25 ( V_10 -> V_22 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_22 ( V_2 , struct V_6 , V_2 ) ;
struct V_10 * V_10 = F_19 ( V_7 ) ;
if ( F_23 ( V_2 ) ) {
F_27 ( V_10 -> V_22 ) ;
F_28 ( V_10 -> V_22 ) ;
}
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_38 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_38 ) ;
}
