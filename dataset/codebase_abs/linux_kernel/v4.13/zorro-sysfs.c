static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_3 ( V_7 -> V_8 . V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 ,
( unsigned long ) F_5 ( V_7 ) ,
( unsigned long ) F_6 ( V_7 ) ,
F_7 ( V_7 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , V_10 L_3 , V_7 -> V_11 ) ;
}
static T_1 F_9 ( struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_5 , T_2 V_18 , T_3 V_19 )
{
struct V_6 * V_7 = F_2 ( F_10 ( V_15 ) ) ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_22 = V_7 -> V_8 ;
V_21 . V_23 = F_11 ( V_7 -> V_24 ) ;
V_21 . V_25 = F_11 ( V_7 -> V_26 ) ;
V_21 . V_27 = F_12 ( F_5 ( V_7 ) ) ;
V_21 . V_28 = F_12 ( F_13 ( V_7 ) ) ;
return F_14 ( V_5 , V_19 , & V_18 , & V_21 , sizeof( V_21 ) ) ;
}
