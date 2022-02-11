static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
long V_9 ;
T_2 V_10 ;
T_3 V_11 ;
F_3 ( V_7 , V_12 , & V_10 ) ;
F_4 ( V_7 , V_13 , & V_11 ) ;
V_9 = ( ( long ) V_10 - V_11 ) * 500 ;
return sprintf ( V_5 , L_1 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_14 = F_6 ( V_4 ) -> V_15 ;
long V_9 ;
T_2 V_16 ;
F_3 ( V_7 , V_14 , & V_16 ) ;
V_9 = V_16 * 500 ;
return sprintf ( V_5 , L_1 , V_9 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_17 = F_6 ( V_4 ) -> V_15 ;
T_4 V_18 ;
F_4 ( V_7 , V_19 , & V_18 ) ;
return sprintf ( V_5 , L_2 , ( unsigned int ) V_18 & ( 1 << V_17 ) ) ;
}
static int F_8 ( struct V_6 * V_7 ,
const struct V_20 * V_21 )
{
int V_22 ;
struct V_1 * V_23 ;
T_5 V_24 ;
T_3 V_11 ;
V_22 = F_9 ( V_7 ) ;
if ( V_22 ) {
F_10 ( & V_7 -> V_2 , L_3 ) ;
return V_22 ;
}
F_4 ( V_7 , V_13 , & V_11 ) ;
F_11 ( V_7 , V_25 , & V_24 ) ;
if ( V_11 == 0x7F && V_24 == 0x07D30D40 ) {
F_12 ( & V_7 -> V_2 , L_4 ) ;
return - V_26 ;
}
V_23 = F_13 ( & V_7 -> V_2 ,
L_5 , NULL ,
V_27 ) ;
return F_14 ( V_23 ) ;
}
