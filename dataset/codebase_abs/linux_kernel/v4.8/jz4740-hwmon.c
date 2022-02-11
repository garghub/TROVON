static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_14 * V_14 = & V_4 -> V_5 ;
long V_15 ;
unsigned long V_16 ;
int V_17 ;
F_5 ( & V_4 -> V_18 ) ;
F_6 ( V_14 ) ;
F_7 ( V_4 -> V_1 ) ;
V_4 -> V_19 -> V_20 ( V_13 ) ;
V_15 = F_8 ( V_14 , V_21 ) ;
if ( V_15 > 0 ) {
V_16 = F_9 ( V_4 -> V_22 ) & 0xfff ;
V_16 = ( V_16 * 3300 ) >> 12 ;
V_17 = sprintf ( V_11 , L_1 , V_16 ) ;
} else {
V_17 = V_15 ? V_15 : - V_23 ;
}
V_4 -> V_19 -> V_24 ( V_13 ) ;
F_10 ( V_4 -> V_1 ) ;
F_11 ( & V_4 -> V_18 ) ;
return V_17 ;
}
static int F_12 ( struct V_12 * V_13 )
{
int V_17 ;
struct V_7 * V_8 = & V_13 -> V_8 ;
struct V_3 * V_4 ;
struct V_7 * V_25 ;
struct V_26 * V_27 ;
V_4 = F_13 ( V_8 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
V_4 -> V_19 = F_14 ( V_13 ) ;
V_4 -> V_1 = F_15 ( V_13 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_16 ( & V_13 -> V_8 , L_2 ,
V_4 -> V_1 ) ;
return V_4 -> V_1 ;
}
V_27 = F_17 ( V_13 , V_30 , 0 ) ;
V_4 -> V_22 = F_18 ( & V_13 -> V_8 , V_27 ) ;
if ( F_19 ( V_4 -> V_22 ) )
return F_20 ( V_4 -> V_22 ) ;
V_4 -> V_13 = V_13 ;
F_21 ( & V_4 -> V_5 ) ;
F_22 ( & V_4 -> V_18 ) ;
V_17 = F_23 ( V_8 , V_4 -> V_1 , F_1 , 0 ,
V_13 -> V_31 , V_4 ) ;
if ( V_17 ) {
F_16 ( & V_13 -> V_8 , L_3 , V_17 ) ;
return V_17 ;
}
F_10 ( V_4 -> V_1 ) ;
V_25 = F_24 ( V_8 , L_4 , V_4 ,
V_32 ) ;
return F_25 ( V_25 ) ;
}
