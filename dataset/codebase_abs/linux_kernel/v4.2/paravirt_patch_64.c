unsigned F_1 ( void * V_1 , unsigned V_2 )
{
return F_2 ( V_1 , V_2 ,
V_3 , V_4 ) ;
}
unsigned F_3 ( void * V_1 , unsigned V_2 )
{
return F_2 ( V_1 , V_2 ,
V_5 , V_6 ) ;
}
unsigned F_4 ( T_1 type , T_2 V_7 , void * V_8 ,
unsigned long V_9 , unsigned V_2 )
{
const unsigned char * V_10 , * V_11 ;
unsigned V_12 ;
#define F_5 ( T_3 , T_4 ) \
case PARAVIRT_PATCH(ops.x): \
start = start_##ops##_##x; \
end = end_##ops##_##x; \
goto patch_site
switch( type ) {
F_5 ( V_13 , V_14 ) ;
F_5 ( V_13 , V_15 ) ;
F_5 ( V_13 , V_16 ) ;
F_5 ( V_13 , V_17 ) ;
F_5 ( V_18 , V_19 ) ;
F_5 ( V_18 , V_20 ) ;
F_5 ( V_18 , V_21 ) ;
F_5 ( V_22 , V_23 ) ;
F_5 ( V_22 , V_24 ) ;
F_5 ( V_22 , V_25 ) ;
F_5 ( V_18 , V_26 ) ;
F_5 ( V_22 , V_27 ) ;
F_5 ( V_18 , V_28 ) ;
#if F_6 ( V_29 ) && F_6 ( V_30 )
case F_7 ( V_31 . V_32 ) :
if ( F_8 () ) {
V_10 = V_33 ;
V_11 = V_34 ;
goto V_35;
}
#endif
default:
V_12 = F_9 ( type , V_7 , V_8 , V_9 , V_2 ) ;
break;
V_35:
V_12 = F_2 ( V_8 , V_2 , V_10 , V_11 ) ;
break;
}
#undef F_5
return V_12 ;
}
