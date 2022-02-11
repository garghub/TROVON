static T_1 F_1 ( char * V_1 , T_1 V_2 , struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = V_4 -> V_7 ;
#define F_2 ( T_2 ) \
if ((mode & S_##n) == S_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
mode &= ~S_##n; \
}
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
F_2 ( V_21 ) ;
F_2 ( V_22 ) ;
F_2 ( V_23 ) ;
F_2 ( V_24 ) ;
F_2 ( V_25 ) ;
F_2 ( V_26 ) ;
F_2 ( V_27 ) ;
F_2 ( V_28 ) ;
F_2 ( V_29 ) ;
F_2 ( V_30 ) ;
F_2 ( V_31 ) ;
F_2 ( V_32 ) ;
F_2 ( V_33 ) ;
F_2 ( V_34 ) ;
F_2 ( V_35 ) ;
#undef F_2
if ( V_6 )
V_5 += F_3 ( V_1 + V_5 , V_2 - V_5 , L_1 , V_5 ? L_2 : L_3 , V_6 ) ;
return V_5 ;
}
