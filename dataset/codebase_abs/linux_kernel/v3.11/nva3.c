static int
F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
struct V_6 * V_7 = V_6 ( V_5 ) ;
struct V_8 V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
int V_14 ;
V_14 = F_2 ( V_7 , type , & V_9 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_3 ( F_4 ( V_2 ) , & V_9 , V_3 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_9 . type ) {
case V_15 :
case V_16 :
F_5 ( V_5 , V_9 . V_17 + 0 , 0x50000610 ) ;
F_6 ( V_5 , V_9 . V_17 + 4 , 0x003fffff ,
( V_13 << 16 ) | ( V_12 << 8 ) | V_10 ) ;
F_5 ( V_5 , V_9 . V_17 + 8 , V_11 ) ;
break;
default:
F_7 ( V_5 , L_1 , type , V_3 ) ;
V_14 = - V_18 ;
break;
}
return V_14 ;
}
static int
F_8 ( struct V_19 * V_20 , struct V_19 * V_21 ,
struct V_22 * V_23 , void * V_24 , T_1 V_25 ,
struct V_19 * * V_26 )
{
struct V_27 * V_5 ;
int V_14 ;
V_14 = F_9 ( V_20 , V_21 , V_23 , & V_5 ) ;
* V_26 = F_10 ( V_5 ) ;
if ( V_14 )
return V_14 ;
V_5 -> V_28 . V_29 = F_1 ;
return 0 ;
}
