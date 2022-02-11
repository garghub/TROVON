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
V_14 = F_3 ( V_2 , & V_9 , V_3 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_9 . type ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_4 ( V_5 , V_9 . V_19 + 0x0c , 0x00000000 , 0x00000100 ) ;
F_5 ( V_5 , V_9 . V_19 + 0x04 , ( V_13 << 16 ) | ( V_10 << 8 ) | V_12 ) ;
F_5 ( V_5 , V_9 . V_19 + 0x10 , V_11 << 16 ) ;
break;
default:
F_6 ( V_5 , L_1 , type , V_3 ) ;
V_14 = - V_20 ;
break;
}
return V_14 ;
}
static int
F_7 ( struct V_21 * V_22 , struct V_21 * V_23 ,
struct V_24 * V_25 , void * V_26 , T_1 V_27 ,
struct V_21 * * V_28 )
{
struct V_4 * V_5 ;
int V_14 ;
V_14 = F_8 ( V_22 , V_23 , V_25 , & V_5 ) ;
* V_28 = F_9 ( V_5 ) ;
if ( V_14 )
return V_14 ;
V_5 -> V_29 . V_30 = F_1 ;
V_5 -> V_29 . V_31 = V_32 ;
return 0 ;
}
