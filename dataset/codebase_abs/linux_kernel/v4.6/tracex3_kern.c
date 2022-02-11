int F_1 ( struct V_1 * V_2 )
{
long V_3 = F_2 ( V_2 ) ;
T_1 V_4 = F_3 () ;
F_4 ( & V_5 , & V_3 , & V_4 , V_6 ) ;
return 0 ;
}
static unsigned int F_5 ( unsigned long long V_7 )
{
#define F_6 ( T_2 ) if (n >= (1ull << k)) { i += k; n >>= k; }
int V_8 = - ( V_7 == 0 ) ;
F_6 ( 32 ) ; F_6 ( 16 ) ; F_6 ( 8 ) ; F_6 ( 4 ) ; F_6 ( 2 ) ; F_6 ( 1 ) ;
return V_8 ;
#undef F_6
}
int F_7 ( struct V_1 * V_2 )
{
long V_3 = F_2 ( V_2 ) ;
T_1 * V_9 , V_10 , V_11 ;
T_3 V_12 ;
V_9 = F_8 ( & V_5 , & V_3 ) ;
if ( ! V_9 )
return 0 ;
T_1 V_13 = F_3 () ;
T_1 V_14 = V_13 - * V_9 ;
F_9 ( & V_5 , & V_3 ) ;
V_10 = F_5 ( V_14 ) ;
V_11 = 1ll << V_10 ;
V_12 = ( V_10 * 64 + ( V_14 - V_11 ) * 64 / V_11 ) * 3 / 64 ;
if ( V_12 >= V_15 )
V_12 = V_15 - 1 ;
V_9 = F_8 ( & V_16 , & V_12 ) ;
if ( V_9 )
* V_9 += 1 ;
return 0 ;
}
