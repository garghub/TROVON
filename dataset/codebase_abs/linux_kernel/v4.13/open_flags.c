static T_1 F_1 ( char * V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = V_4 -> V_7 ;
if ( ! ( V_6 & V_8 ) )
V_4 -> V_9 |= 1 << ( V_4 -> V_10 + 1 ) ;
if ( V_6 == 0 )
return F_2 ( V_1 , V_2 , L_1 ) ;
#define F_3 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
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
#ifdef F_4
F_3 ( V_21 ) ;
#elif V_22
F_3 ( V_23 ) ;
#endif
#ifdef F_5
F_3 ( V_24 ) ;
#endif
F_3 ( V_25 ) ;
#ifdef F_6
if ( ( V_6 & V_26 ) == V_26 )
V_5 += F_2 ( V_1 + V_5 , V_2 - V_5 , L_2 , V_5 ? L_3 : L_4 , L_5 ) ;
else {
F_3 ( V_27 ) ;
}
#else
F_3 ( V_28 ) ;
#endif
F_3 ( V_29 ) ;
F_3 ( V_30 ) ;
#undef F_3
if ( V_6 )
V_5 += F_2 ( V_1 + V_5 , V_2 - V_5 , L_6 , V_5 ? L_3 : L_4 , V_6 ) ;
return V_5 ;
}
