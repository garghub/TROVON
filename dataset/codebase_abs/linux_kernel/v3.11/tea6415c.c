static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_8 = 0 ;
int V_9 ;
F_3 ( 1 , V_10 , V_2 , L_1 , V_3 , V_4 ) ;
if ( 0 == ( ( 1 == V_3 || 3 == V_3 || 5 == V_3 || 6 == V_3 || 8 == V_3 || 10 == V_3 || 20 == V_3 || 11 == V_3 )
&& ( 18 == V_4 || 17 == V_4 || 16 == V_4 || 15 == V_4 || 14 == V_4 || 13 == V_4 ) ) )
return - V_11 ;
switch ( V_4 ) {
case 18 :
V_8 = 0x00 ;
break;
case 14 :
V_8 = 0x20 ;
break;
case 16 :
V_8 = 0x10 ;
break;
case 17 :
V_8 = 0x08 ;
break;
case 15 :
V_8 = 0x18 ;
break;
case 13 :
V_8 = 0x28 ;
break;
}
switch ( V_3 ) {
case 5 :
V_8 |= 0x00 ;
break;
case 8 :
V_8 |= 0x04 ;
break;
case 3 :
V_8 |= 0x02 ;
break;
case 20 :
V_8 |= 0x06 ;
break;
case 6 :
V_8 |= 0x01 ;
break;
case 10 :
V_8 |= 0x05 ;
break;
case 1 :
V_8 |= 0x03 ;
break;
case 11 :
V_8 |= 0x07 ;
break;
}
V_9 = F_4 ( V_7 , V_8 ) ;
if ( V_9 ) {
F_3 ( 1 , V_10 , V_2 ,
L_2 , V_9 ) ;
return - V_12 ;
}
return V_9 ;
}
static int F_5 ( struct V_6 * V_7 ,
const struct V_13 * V_14 )
{
struct V_1 * V_2 ;
if ( ! F_6 ( V_7 -> V_15 , V_16 ) )
return - V_12 ;
F_7 ( V_7 , L_3 ,
V_7 -> V_17 << 1 , V_7 -> V_15 -> V_18 ) ;
V_2 = F_8 ( & V_7 -> V_19 , sizeof( * V_2 ) , V_20 ) ;
if ( V_2 == NULL )
return - V_21 ;
F_9 ( V_2 , V_7 , & V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
