static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_3 ( V_7 -> V_8 . V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 ,
( unsigned long ) F_5 ( V_7 ) ,
( unsigned long ) F_6 ( V_7 ) ,
F_7 ( V_7 ) ) ;
}
static T_1 F_8 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_5 , T_2 V_16 , T_3 V_17 )
{
struct V_6 * V_7 = F_2 ( F_9 ( V_13 ) ) ;
struct V_18 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_20 = V_7 -> V_8 ;
V_19 . V_21 = F_10 ( V_7 -> V_22 ) ;
V_19 . V_23 = F_10 ( V_7 -> V_24 ) ;
V_19 . V_25 = F_11 ( F_5 ( V_7 ) ) ;
V_19 . V_26 = F_11 ( F_12 ( V_7 ) ) ;
return F_13 ( V_5 , V_17 , & V_16 , & V_19 , sizeof( V_19 ) ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , V_27 L_3 , V_7 -> V_28 ) ;
}
int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int error ;
if ( ( error = F_16 ( V_2 , & V_29 ) ) ||
( error = F_16 ( V_2 , & V_30 ) ) ||
( error = F_16 ( V_2 , & V_31 ) ) ||
( error = F_16 ( V_2 , & V_32 ) ) ||
( error = F_16 ( V_2 , & V_33 ) ) ||
( error = F_16 ( V_2 , & V_34 ) ) ||
( error = F_16 ( V_2 , & V_35 ) ) ||
( error = F_17 ( & V_2 -> V_13 , & V_36 ) ) )
return error ;
return 0 ;
}
