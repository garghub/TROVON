static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_5 ;
T_1 V_7 [ 2 ] = {
V_8 | V_9 ,
( V_2 -> V_3 & V_10 ) | V_3
} ;
V_4 = F_2 ( V_6 , & V_7 , sizeof( V_7 ) ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_11 , L_1 ) ;
return V_4 ;
}
V_2 -> V_3 = ( V_2 -> V_3 & V_10 ) | V_3 ;
return 0 ;
}
static T_2 F_4 ( struct V_12 * V_11 ,
struct V_13 * V_14 ,
char * V_7 )
{
T_2 V_4 ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
V_4 = F_6 ( V_2 -> V_5 , V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_7 , L_2 , ( V_16 ) F_7 ( V_4 ) * 125 / 32 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_4 ;
struct V_1 * V_2 ;
V_2 = F_9 ( & V_6 -> V_11 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
F_10 ( V_6 , V_2 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_3 = V_19 | V_20 ;
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_21 = F_11 ( & V_6 -> V_11 ,
V_6 -> V_22 ,
V_2 ,
V_23 ) ;
if ( F_12 ( V_2 -> V_21 ) ) {
F_1 ( V_2 , V_24 ) ;
return F_13 ( V_2 -> V_21 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_15 ( V_6 ) ;
F_16 ( V_2 -> V_21 ) ;
return F_1 ( V_2 , V_24 ) ;
}
static int T_3 F_17 ( struct V_12 * V_11 )
{
struct V_5 * V_5 = F_18 ( V_11 ) ;
struct V_1 * V_2 = F_15 ( V_5 ) ;
return F_1 ( V_2 , V_24 ) ;
}
static int T_3 F_19 ( struct V_12 * V_11 )
{
struct V_5 * V_5 = F_18 ( V_11 ) ;
struct V_1 * V_2 = F_15 ( V_5 ) ;
return F_1 ( V_2 , V_19 ) ;
}
