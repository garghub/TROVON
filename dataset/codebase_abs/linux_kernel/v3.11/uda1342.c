static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( V_2 , V_3 , F_3 ( V_4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
switch ( V_7 ) {
case V_10 :
F_1 ( V_2 , 0x00 , 0x1241 ) ;
break;
case V_11 :
F_1 ( V_2 , 0x00 , 0x1441 ) ;
break;
default:
F_6 ( V_6 , L_1 , V_7 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_5 * V_6 ;
if ( ! F_8 ( V_15 , V_16 ) )
return - V_17 ;
F_9 ( & V_2 -> V_18 , L_2 ,
V_2 -> V_19 , V_15 -> V_20 ) ;
V_6 = F_10 ( & V_2 -> V_18 , sizeof( * V_6 ) , V_21 ) ;
if ( V_6 == NULL )
return - V_22 ;
F_11 ( V_6 , V_2 , & V_23 ) ;
F_1 ( V_2 , 0x00 , 0x8000 ) ;
F_1 ( V_2 , 0x00 , 0x1241 ) ;
F_12 ( V_2 , L_3 ,
V_2 -> V_19 << 1 , V_2 -> V_15 -> V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
