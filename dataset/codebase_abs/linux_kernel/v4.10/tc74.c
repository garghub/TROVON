static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
V_7 = F_3 ( & V_4 -> V_8 ) ;
if ( V_7 )
return V_7 ;
if ( F_4 ( V_9 , V_4 -> V_10 ) || ! V_4 -> V_11 ) {
T_1 V_12 ;
V_12 = F_5 ( V_6 , V_13 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_6 -> V_2 , L_1 ,
( int ) V_12 ) ;
V_7 = V_12 ;
goto V_14;
}
if ( ! ( V_12 & F_7 ( 6 ) ) ) {
V_7 = - V_15 ;
goto V_14;
}
V_12 = F_5 ( V_6 , V_16 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_6 -> V_2 , L_2 ,
( int ) V_12 ) ;
V_7 = V_12 ;
goto V_14;
}
V_4 -> V_17 = V_12 ;
V_4 -> V_10 = V_9 + V_18 / 4 ;
V_4 -> V_11 = true ;
}
V_14:
F_8 ( & V_4 -> V_8 ) ;
return V_7 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_21 , L_3 , V_4 -> V_17 * 1000 ) ;
}
static int F_10 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_3 * V_4 ;
struct V_1 * V_24 ;
T_1 V_25 ;
if ( ! F_11 ( V_6 -> V_26 , V_27 ) )
return - V_28 ;
V_4 = F_12 ( V_2 , sizeof( struct V_3 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_6 = V_6 ;
F_13 ( & V_4 -> V_8 ) ;
V_25 = F_5 ( V_6 , V_13 ) ;
if ( V_25 < 0 ) {
F_14 ( V_2 , L_4 ) ;
return V_25 ;
}
if ( V_25 & 0x3f ) {
F_14 ( V_2 , L_5 ) ;
return - V_31 ;
}
if ( V_25 & F_7 ( 7 ) ) {
T_1 V_7 ;
V_25 &= ~ F_7 ( 7 ) ;
V_7 = F_15 ( V_6 , V_13 , V_25 ) ;
if ( V_7 )
F_16 ( V_2 , L_6 ) ;
}
V_24 = F_17 ( V_2 ,
V_6 -> V_32 ,
V_4 , V_33 ) ;
return F_18 ( V_24 ) ;
}
