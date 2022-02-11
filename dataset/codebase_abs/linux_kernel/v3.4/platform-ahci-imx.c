static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
T_2 V_4 ;
int V_5 = 0 ;
struct V_6 * V_6 ;
V_7 = F_2 ( V_2 , L_1 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( V_2 , L_2 ) ;
return F_5 ( V_7 ) ;
}
V_5 = F_6 ( V_7 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_3 ) ;
goto V_8;
}
V_9 = F_2 ( V_2 , L_4 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( V_2 , L_5 ) ;
V_5 = F_5 ( V_9 ) ;
goto V_10;
}
V_5 = F_6 ( V_9 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_6 ) ;
goto V_11;
}
V_6 = F_2 ( V_2 , L_7 ) ;
if ( F_3 ( V_6 ) ) {
F_4 ( V_2 , L_8 ) ;
V_5 = F_5 ( V_6 ) ;
goto V_12;
}
V_4 = F_7 ( V_6 ) / 1000 ;
F_8 ( V_6 ) ;
F_9 ( V_4 , V_3 + V_13 ) ;
V_4 = F_10 ( V_3 + V_14 ) ;
if ( ! ( V_4 & V_15 ) ) {
V_4 |= V_15 ;
F_9 ( V_4 , V_3 + V_14 ) ;
}
if ( ! ( F_10 ( V_3 + V_16 ) & 0x1 ) )
F_9 ( ( F_10 ( V_3 + V_16 ) | 0x1 ) ,
V_3 + V_16 ) ;
return 0 ;
V_12:
F_11 ( V_9 ) ;
V_11:
F_8 ( V_9 ) ;
V_10:
F_11 ( V_7 ) ;
V_8:
F_8 ( V_7 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_9 ) ;
F_8 ( V_9 ) ;
F_11 ( V_7 ) ;
F_8 ( V_7 ) ;
}
struct V_17 * T_3 F_13 (
const struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_22 V_23 [] = {
{
. V_24 = V_19 -> V_25 ,
. V_26 = V_19 -> V_25 + V_27 - 1 ,
. V_28 = V_29 ,
} , {
. V_24 = V_19 -> V_30 ,
. V_26 = V_19 -> V_30 ,
. V_28 = V_31 ,
} ,
} ;
return F_14 ( V_19 -> V_32 , 0 ,
V_23 , F_15 ( V_23 ) ,
V_21 , sizeof( * V_21 ) , F_16 ( 32 ) ) ;
}
struct V_17 * T_3 F_17 ( void )
{
struct V_20 V_21 = {
. V_33 = F_1 ,
. exit = F_12 ,
} ;
return F_13 ( & V_34 , & V_21 ) ;
}
