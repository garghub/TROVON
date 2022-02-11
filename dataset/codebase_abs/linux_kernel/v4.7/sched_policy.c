static T_1 F_1 ( char * V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
const char * V_5 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
} ;
T_1 V_6 ;
int V_7 = V_4 -> V_8 ,
V_9 = V_7 & ~ V_10 ;
V_7 &= V_10 ;
if ( V_7 <= V_11 )
V_6 = F_2 ( V_1 , V_2 , L_8 , V_5 [ V_7 ] ) ;
else
V_6 = F_2 ( V_1 , V_2 , L_9 , V_7 ) ;
#define F_3 ( T_2 ) \
if (flags & SCHED_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SCHED_##n; \
}
F_3 ( V_12 ) ;
#undef F_3
if ( V_9 )
V_6 += F_2 ( V_1 + V_6 , V_2 - V_6 , L_10 , V_9 ) ;
return V_6 ;
}
