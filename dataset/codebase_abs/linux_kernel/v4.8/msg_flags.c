static T_1 F_1 ( char * V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = V_4 -> V_7 ;
if ( V_6 == 0 )
return F_2 ( V_1 , V_2 , L_1 ) ;
#define F_3 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_3 ( V_8 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
F_3 ( V_18 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
F_3 ( V_21 ) ;
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
F_3 ( V_26 ) ;
F_3 ( V_27 ) ;
#undef F_3
if ( V_6 )
V_5 += F_2 ( V_1 + V_5 , V_2 - V_5 , L_2 , V_5 ? L_3 : L_4 , V_6 ) ;
return V_5 ;
}
