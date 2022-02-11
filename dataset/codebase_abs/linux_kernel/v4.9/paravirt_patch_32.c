unsigned F_1 ( void * V_1 , unsigned V_2 )
{
return 0 ;
}
unsigned F_2 ( void * V_1 , unsigned V_2 )
{
return 0 ;
}
unsigned F_3 ( T_1 type , T_2 V_3 , void * V_4 ,
unsigned long V_5 , unsigned V_2 )
{
const unsigned char * V_6 , * V_7 ;
unsigned V_8 ;
#define F_4 ( T_3 , T_4 ) \
case PARAVIRT_PATCH(ops.x): \
start = start_##ops##_##x; \
end = end_##ops##_##x; \
goto patch_site
switch ( type ) {
F_4 ( V_9 , V_10 ) ;
F_4 ( V_9 , V_11 ) ;
F_4 ( V_9 , V_12 ) ;
F_4 ( V_9 , V_13 ) ;
F_4 ( V_14 , V_15 ) ;
F_4 ( V_16 , V_17 ) ;
F_4 ( V_16 , V_18 ) ;
F_4 ( V_16 , V_19 ) ;
F_4 ( V_14 , V_20 ) ;
#if F_5 ( V_21 )
case F_6 ( V_22 . V_23 ) :
if ( F_7 () ) {
V_6 = V_24 ;
V_7 = V_25 ;
goto V_26;
}
#endif
default:
V_8 = F_8 ( type , V_3 , V_4 , V_5 , V_2 ) ;
break;
V_26:
V_8 = F_9 ( V_4 , V_2 , V_6 , V_7 ) ;
break;
}
#undef F_4
return V_8 ;
}
