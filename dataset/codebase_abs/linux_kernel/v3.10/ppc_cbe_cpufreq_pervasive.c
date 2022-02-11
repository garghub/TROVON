int F_1 ( int V_1 , unsigned int V_2 )
{
struct V_3 T_1 * V_4 ;
struct V_5 T_1 * V_6 ;
unsigned long V_7 ;
T_2 V_8 ;
#ifdef F_2
long time ;
#endif
F_3 ( V_7 ) ;
V_6 = F_4 ( V_1 ) ;
V_4 = F_5 ( V_1 ) ;
#ifdef F_2
time = V_9 ;
#endif
F_6 ( & V_6 -> V_10 , V_11 [ V_2 ] ) ;
F_6 ( & V_6 -> V_12 , V_11 [ V_2 ] ) ;
F_6 ( & V_6 -> V_13 , V_14 [ V_2 ] ) ;
F_6 ( & V_6 -> V_15 , V_14 [ V_2 ] ) ;
V_8 = F_7 ( & V_4 -> V_16 ) ;
V_8 &= 0xFFFFFFFFFFFFFFF8ull ;
V_8 |= V_2 ;
F_6 ( & V_4 -> V_16 , V_8 ) ;
#ifdef F_2
V_8 = F_7 ( & V_4 -> V_17 ) & 0x07 ;
while ( V_8 != V_2 ) {
F_8 () ;
V_8 = F_7 ( & V_4 -> V_17 ) & 0x07 ;
}
time = V_9 - time ;
time = F_9 ( time ) ;
F_10 ( L_1 \
L_2 , time ) ;
#endif
F_11 ( V_7 ) ;
return 0 ;
}
int F_12 ( int V_1 )
{
int V_18 ;
struct V_3 T_1 * V_4 ;
V_4 = F_5 ( V_1 ) ;
V_18 = F_7 ( & V_4 -> V_17 ) & 0x07 ;
return V_18 ;
}
