T_1 F_1 ( unsigned long V_1 , char * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
if ( V_1 == 0 )
return F_2 ( V_2 , V_3 , L_1 ) ;
#define F_3 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_3 ( V_5 ) ;
F_3 ( V_6 ) ;
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( TMPFILE ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
#ifdef F_4
F_3 ( V_17 ) ;
#elif V_18
F_3 ( V_19 ) ;
#endif
#ifdef F_5
F_3 ( V_20 ) ;
#endif
#ifdef F_6
if ( ( V_1 & V_21 ) == V_21 )
V_4 += F_2 ( V_2 + V_4 , V_3 - V_4 , L_2 , V_4 ? L_3 : L_4 , L_5 ) ;
else {
F_3 ( V_22 ) ;
}
#else
F_3 ( V_23 ) ;
#endif
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
#undef F_3
if ( V_1 )
V_4 += F_2 ( V_2 + V_4 , V_3 - V_4 , L_6 , V_4 ? L_3 : L_4 , V_1 ) ;
return V_4 ;
}
T_1 F_7 ( char * V_2 , T_1 V_3 , struct V_26 * V_27 )
{
int V_1 = V_27 -> V_28 ;
if ( ! ( V_1 & V_29 ) )
V_27 -> V_30 |= 1 << ( V_27 -> V_31 + 1 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
