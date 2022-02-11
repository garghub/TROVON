static T_1 F_1 ( int V_1 , void * V_2 )
{
static T_2 V_3 ;
struct V_4 * V_5 = V_2 ;
const struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
T_2 V_10 ;
for (; ; ) {
V_9 = F_2 ( V_11 ) ;
if ( V_9 < 0 ) {
F_3 ( V_5 -> V_12 , L_1 ,
V_9 ) ;
break;
}
V_10 = V_9 << 8 ;
V_9 = F_2 ( V_13 ) ;
if ( V_9 < 0 ) {
F_3 ( V_5 -> V_12 , L_2 ,
V_9 ) ;
break;
}
V_10 |= V_9 ;
if ( V_10 == 0xdead )
break;
if ( V_10 == V_3 ) {
V_3 = 0 ;
continue;
}
V_3 = V_10 ;
V_10 &= ~ 0x0800 ;
V_7 = F_4 ( V_5 -> V_14 , V_10 ) ;
V_8 = V_7 ? V_7 -> V_8 : V_15 ;
F_3 ( V_5 -> V_12 ,
L_3 ,
V_10 , V_8 ) ;
F_5 ( V_5 -> V_14 , V_8 , 1 ) ;
F_6 ( V_5 -> V_14 ) ;
F_5 ( V_5 -> V_14 , V_8 , 0 ) ;
F_6 ( V_5 -> V_14 ) ;
}
return V_16 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_4 * V_5 ;
struct V_19 * V_14 ;
int V_1 ;
int error ;
V_5 = F_8 ( & V_18 -> V_12 , sizeof ( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
V_14 = F_9 ( & V_18 -> V_12 ) ;
if ( ! V_14 )
return - V_21 ;
V_5 -> V_12 = & V_18 -> V_12 ;
V_5 -> V_14 = V_14 ;
V_14 -> V_22 = L_4 ;
V_14 -> V_23 = L_5 ;
V_14 -> V_24 . V_25 = V_26 ;
V_14 -> V_24 . V_27 = 0x0355 ;
V_14 -> V_24 . V_28 = F_2 ( V_29 ) ;
error = F_10 ( V_14 , V_4 , NULL ) ;
if ( error )
return error ;
V_1 = F_11 ( V_18 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
error = F_12 ( & V_18 -> V_12 , V_1 ,
NULL , F_1 ,
V_30 | V_31 ,
F_13 ( & V_18 -> V_12 ) , V_5 ) ;
if ( error )
return error ;
error = F_14 ( V_14 ) ;
if ( error )
return error ;
return 0 ;
}
