int F_1 ( int V_1 , void * V_2 )
{
struct V_3 V_4 ;
int V_5 ;
V_4 . V_1 = V_1 ;
memcpy ( & V_4 . V_6 , V_2 , sizeof( V_4 . V_6 ) ) ;
V_5 = F_2 ( int , V_7 , & V_4 ) ;
switch ( V_1 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
break;
#define F_3 ( T_1 ) \
case EVTCHNOP_##eop: \
memcpy(arg, &op.u.eop, sizeof(op.u.eop)); \
break
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
#undef F_3
default:
F_4 ( V_5 != - V_18 ) ;
break;
}
return V_5 ;
}
int F_5 ( int V_1 , void * V_2 )
{
struct V_19 V_4 ;
int V_5 ;
V_4 . V_1 = V_1 ;
memcpy ( & V_4 . V_6 , V_2 , sizeof( V_4 . V_6 ) ) ;
V_5 = F_2 ( int , V_20 , & V_4 ) ;
switch ( V_1 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
break;
#define F_3 ( T_2 , T_3 ) \
case PHYSDEVOP_##pop: \
memcpy(arg, &op.u.fld, sizeof(op.u.fld)); \
break
F_3 ( V_25 , V_25 ) ;
F_3 ( V_26 , V_27 ) ;
F_3 ( V_28 , V_29 ) ;
#undef F_3
default:
F_4 ( V_5 != - V_18 ) ;
break;
}
return V_5 ;
}
