static inline T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( F_3 ( V_2 + V_1 ) ) ;
}
static inline void F_4 ( T_1 V_3 , unsigned long V_1 )
{
F_5 ( V_3 , F_3 ( V_2 + V_1 ) ) ;
}
void F_6 ( void )
{
T_1 V_4 = F_2 ( F_3 ( V_5 + 0x48 ) ) ;
V_4 |= 1 << 28 ;
F_5 ( V_4 , F_3 ( V_5 + 0x48 ) ) ;
F_7 ( L_1 ,
F_8 () , F_9 () ,
F_10 () ) ;
}
unsigned long long F_11 ( void )
{
unsigned long long V_6 , V_7 ;
V_6 = F_1 ( V_8 ) ;
V_7 = F_1 ( V_9 ) ;
return ( V_7 << 32ull ) | V_6 ;
}
int F_8 ( void )
{
int V_10 ;
T_1 V_4 = F_1 ( V_11 ) ;
V_10 = V_4 & 0xFF ;
return V_10 ;
}
int F_9 ( void )
{
int V_12 ;
T_1 V_4 = F_1 ( V_13 ) ;
V_12 = ( V_4 >> 6 ) & 3 ;
return V_12 ;
}
int F_10 ( void )
{
int V_14 ;
T_1 V_4 = F_1 ( V_13 ) ;
V_14 = ( V_4 >> 12 ) & 3 ;
return V_14 ;
}
