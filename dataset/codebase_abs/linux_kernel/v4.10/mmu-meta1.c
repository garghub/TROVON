static unsigned long F_1 ( unsigned long V_1 )
{
static unsigned long V_2 = 0xFFFFFFFF ;
int V_3 ;
V_3 = V_1 - V_2 ;
if ( ( V_3 < 0 ) || ( V_3 >= V_4 ) ) {
V_2 = V_1 & ~ ( V_4 - 1 ) ;
F_2 ( V_2 , V_5 ) ;
V_3 = V_1 - V_2 ;
}
return V_6 + V_3 ;
}
static inline unsigned long F_3 ( void )
{
unsigned long V_7 ;
unsigned int V_8 ;
if ( F_4 ( V_9 ) )
V_8 = 4 ;
else
V_8 = F_5 () ;
V_7 = F_6 ( V_10 ) ;
V_7 += ( 0x800 * V_8 ) ;
return V_7 ;
}
static unsigned long F_7 ( unsigned long V_11 )
{
unsigned long V_12 ;
unsigned long V_13 ;
if ( ! V_14 )
V_14 = F_3 () ;
if ( F_4 ( V_11 ) ) {
V_11 &= ~ 0x80000000 ;
}
V_12 = V_14 + ( ( V_11 >> V_15 ) * 4 ) ;
V_13 = F_1 ( V_12 ) ;
return V_13 ;
}
static unsigned long F_8 ( unsigned long V_11 )
{
unsigned long V_16 ;
unsigned long V_17 , V_18 ;
V_16 = F_6 ( F_7 ( V_11 ) ) & V_19 ;
V_17 = F_1 ( V_16 ) ;
V_18 = V_17 + ( ( V_11 >> V_20 ) & 0x3FF ) * 4 ;
return V_18 ;
}
unsigned long F_9 ( unsigned long V_21 )
{
return F_6 ( F_7 ( V_21 ) ) ;
}
unsigned long F_10 ( unsigned long V_21 )
{
return F_6 ( F_8 ( V_21 ) ) ;
}
unsigned long F_11 ( void )
{
static unsigned long V_22 ;
if ( ! V_22 )
V_22 = F_7 ( 0 ) ;
return V_22 ;
}
void T_1 F_12 ( unsigned long V_23 )
{
unsigned long V_24 , V_25 ;
T_2 * V_26 ;
V_25 = V_9 ;
V_24 = F_13 ( V_9 ) ;
V_26 = F_14 ( 0 ) + V_24 ;
while ( V_25 <= V_27 ) {
unsigned long V_28 ;
V_28 = F_9 ( V_25 ) ;
F_15 ( * V_26 ) = V_28 ;
V_26 ++ ;
V_25 += V_29 ;
V_24 ++ ;
}
}
