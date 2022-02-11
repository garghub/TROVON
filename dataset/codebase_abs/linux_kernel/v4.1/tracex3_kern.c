int F_1 ( struct V_1 * V_2 )
{
long V_3 = V_2 -> V_4 ;
T_1 V_5 = F_2 () ;
F_3 ( & V_6 , & V_3 , & V_5 , V_7 ) ;
return 0 ;
}
static unsigned int F_4 ( unsigned long long V_8 )
{
#define F_5 ( T_2 ) if (n >= (1ull << k)) { i += k; n >>= k; }
int V_9 = - ( V_8 == 0 ) ;
F_5 ( 32 ) ; F_5 ( 16 ) ; F_5 ( 8 ) ; F_5 ( 4 ) ; F_5 ( 2 ) ; F_5 ( 1 ) ;
return V_9 ;
#undef F_5
}
int F_6 ( struct V_1 * V_2 )
{
long V_3 = V_2 -> V_4 ;
T_1 * V_10 , V_11 , V_12 ;
T_3 V_13 ;
V_10 = F_7 ( & V_6 , & V_3 ) ;
if ( ! V_10 )
return 0 ;
T_1 V_14 = F_2 () ;
T_1 V_15 = V_14 - * V_10 ;
F_8 ( & V_6 , & V_3 ) ;
V_11 = F_4 ( V_15 ) ;
V_12 = 1ll << V_11 ;
V_13 = ( V_11 * 64 + ( V_15 - V_12 ) * 64 / V_12 ) * 3 / 64 ;
if ( V_13 >= V_16 )
V_13 = V_16 - 1 ;
V_10 = F_7 ( & V_17 , & V_13 ) ;
if ( V_10 )
F_9 ( ( long * ) V_10 , 1 ) ;
return 0 ;
}
