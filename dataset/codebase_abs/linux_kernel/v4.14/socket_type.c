static T_1 F_1 ( char * V_1 , T_1 V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
int type = V_4 -> V_6 ,
V_7 = type & ~ V_8 ;
type &= V_8 ;
switch ( type ) {
#define F_2 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
#undef F_2
default:
V_5 = F_3 ( V_1 , V_2 , L_1 , type ) ;
}
#define F_4 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_4 ( V_16 ) ;
F_4 ( V_17 ) ;
#undef F_4
if ( V_7 )
V_5 += F_3 ( V_1 + V_5 , V_2 - V_5 , L_2 , V_7 ) ;
return V_5 ;
}
