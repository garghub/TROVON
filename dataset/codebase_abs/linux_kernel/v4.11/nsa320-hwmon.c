static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
T_2 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_3 = V_6 -> V_3 ;
if ( F_4 ( V_8 , V_6 -> V_9 + V_10 ) || V_3 == 0 ) {
F_5 ( V_6 -> V_11 , 1 ) ;
F_6 ( 100 ) ;
V_3 = 0 ;
for ( V_4 = F_7 ( 31 ) ; V_4 ; V_4 >>= 1 ) {
F_5 ( V_6 -> V_12 , 0 ) ;
F_8 ( 100 , 200 ) ;
F_5 ( V_6 -> V_12 , 1 ) ;
F_8 ( 100 , 200 ) ;
if ( F_9 ( V_6 -> V_13 ) )
V_3 |= V_4 ;
}
F_5 ( V_6 -> V_11 , 0 ) ;
F_10 ( V_2 , L_1 , V_3 ) ;
if ( ( V_3 >> 24 ) != V_14 ) {
F_10 ( V_2 , L_2 , V_3 ) ;
V_3 = - V_15 ;
} else {
V_6 -> V_3 = V_3 ;
V_6 -> V_9 = V_8 ;
}
}
F_11 ( & V_6 -> V_7 ) ;
return V_3 ;
}
static T_3 F_12 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
int V_19 = F_13 ( V_17 ) -> V_20 ;
return sprintf ( V_18 , L_3 , V_21 [ V_19 ] ) ;
}
static T_3 F_14 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
T_1 V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_18 , L_4 , ( V_3 & 0xffff ) * 100 ) ;
}
static T_3 F_15 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
T_1 V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return sprintf ( V_18 , L_4 , ( ( V_3 & 0xff0000 ) >> 16 ) * 100 ) ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_24 ;
V_6 = F_17 ( & V_23 -> V_2 , sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_11 = F_18 ( & V_23 -> V_2 , L_5 , V_27 ) ;
if ( F_19 ( V_6 -> V_11 ) )
return F_20 ( V_6 -> V_11 ) ;
V_6 -> V_12 = F_18 ( & V_23 -> V_2 , L_6 , V_28 ) ;
if ( F_19 ( V_6 -> V_12 ) )
return F_20 ( V_6 -> V_12 ) ;
V_6 -> V_13 = F_18 ( & V_23 -> V_2 , L_7 , V_29 ) ;
if ( F_19 ( V_6 -> V_13 ) )
return F_20 ( V_6 -> V_13 ) ;
F_21 ( & V_6 -> V_7 ) ;
V_24 = F_22 ( & V_23 -> V_2 ,
L_8 , V_6 , V_30 ) ;
return F_23 ( V_24 ) ;
}
