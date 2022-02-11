static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 ,
( unsigned long ) F_3 ( V_7 ) ,
( unsigned long ) F_4 ( V_7 ) ,
F_5 ( V_7 ) ) ;
}
static T_1 F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_5 , T_2 V_14 , T_3 V_15 )
{
struct V_6 * V_7 = F_2 ( F_7 ( V_11 , struct V_1 ,
V_11 ) ) ;
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_18 = V_7 -> V_19 ;
V_17 . V_20 = V_7 -> V_21 ;
V_17 . V_22 = V_7 -> V_23 ;
V_17 . V_24 = ( void * ) F_3 ( V_7 ) ;
V_17 . V_25 = F_8 ( V_7 ) ;
return F_9 ( V_5 , V_15 , & V_14 , & V_17 , sizeof( V_17 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , V_26 L_2 , V_7 -> V_27 ) ;
}
int F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int error ;
if ( ( error = F_12 ( V_2 , & V_28 ) ) ||
( error = F_12 ( V_2 , & V_29 ) ) ||
( error = F_12 ( V_2 , & V_30 ) ) ||
( error = F_12 ( V_2 , & V_31 ) ) ||
( error = F_12 ( V_2 , & V_32 ) ) ||
( error = F_12 ( V_2 , & V_33 ) ) ||
( error = F_12 ( V_2 , & V_34 ) ) ||
( error = F_13 ( & V_2 -> V_11 , & V_35 ) ) )
return error ;
return 0 ;
}
