static T_1 F_1 ( char * V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = V_4 -> V_7 ;
#define F_2 ( T_2 ) \
if (options & W##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
options &= ~W##n; \
}
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
#undef F_2
if ( V_6 )
V_5 += F_3 ( V_1 + V_5 , V_2 - V_5 , L_1 , V_5 ? L_2 : L_3 , V_6 ) ;
return V_5 ;
}
