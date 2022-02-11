static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , ( V_7 -> V_8 & 0xff ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , ( ( V_7 -> V_8 >> 8 ) & 0xff ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_10 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 ,
( unsigned long ) F_7 ( V_7 ) ,
( unsigned long ) F_8 ( V_7 ) ,
F_9 ( V_7 ) ) ;
}
int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int error ;
if ( ( error = F_11 ( V_2 , & V_11 ) ) ||
( error = F_11 ( V_2 , & V_12 ) ) ||
( error = F_11 ( V_2 , & V_13 ) ) ||
( error = F_11 ( V_2 , & V_14 ) ) ||
( error = F_11 ( V_2 , & V_15 ) ) )
return error ;
return 0 ;
}
