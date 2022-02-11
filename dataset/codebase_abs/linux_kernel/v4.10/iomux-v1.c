static inline unsigned long F_1 ( unsigned V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned long V_3 , unsigned V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline void F_5 ( unsigned V_1 ,
unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_6 = F_1 ( V_1 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_3 ( V_6 , V_1 ) ;
}
static inline void F_6 (
unsigned int V_7 , unsigned int V_8 , int V_9 )
{
unsigned long V_4 = 1 << V_8 ;
F_5 ( F_7 ( V_7 ) , V_4 , V_9 ? V_4 : 0 ) ;
}
static inline void F_8 (
unsigned int V_7 , unsigned int V_8 , int V_10 )
{
unsigned long V_4 = 1 << V_8 ;
F_5 ( F_9 ( V_7 ) , V_4 , V_10 ? V_4 : 0 ) ;
}
static inline void F_10 (
unsigned int V_7 , unsigned int V_8 , int V_11 )
{
unsigned long V_4 = 1 << V_8 ;
F_5 ( F_11 ( V_7 ) , V_4 , V_11 ? V_4 : 0 ) ;
}
static inline void F_12 (
unsigned int V_7 , unsigned int V_8 , int V_12 )
{
unsigned long V_4 = 1 << V_8 ;
F_5 ( F_13 ( V_7 ) , V_4 , V_12 ? V_4 : 0 ) ;
}
static inline void F_14 (
unsigned int V_7 , unsigned int V_8 , unsigned int V_13 )
{
unsigned long V_14 = ( V_8 & 0xf ) << 1 ;
unsigned long V_4 = 3 << V_14 ;
unsigned long V_5 = V_13 << V_14 ;
unsigned long V_1 = V_8 < 16 ? F_15 ( V_7 ) : F_16 ( V_7 ) ;
F_5 ( V_1 , V_4 , V_5 ) ;
}
static inline void F_17 (
unsigned int V_7 , unsigned int V_8 , unsigned int V_15 )
{
unsigned long V_14 = ( V_8 & 0xf ) << 1 ;
unsigned long V_4 = 3 << V_14 ;
unsigned long V_5 = V_15 << V_14 ;
unsigned long V_1 = V_8 < 16 ? F_18 ( V_7 ) : F_19 ( V_7 ) ;
F_5 ( V_1 , V_4 , V_5 ) ;
}
static inline void F_20 (
unsigned int V_7 , unsigned int V_8 , unsigned int V_16 )
{
unsigned long V_14 = ( V_8 & 0xf ) << 1 ;
unsigned long V_4 = 3 << V_14 ;
unsigned long V_5 = V_16 << V_14 ;
unsigned long V_1 = V_8 < 16 ? F_21 ( V_7 ) : F_22 ( V_7 ) ;
F_5 ( V_1 , V_4 , V_5 ) ;
}
int F_23 ( int V_17 )
{
unsigned int V_8 = V_17 & V_18 ;
unsigned int V_7 = ( V_17 & V_19 ) >> V_20 ;
unsigned int V_13 = ( V_17 & V_21 ) >> V_22 ;
unsigned int V_15 = ( V_17 >> V_23 ) & 3 ;
unsigned int V_16 = ( V_17 >> V_24 ) & 3 ;
if ( V_7 >= V_25 )
return - V_26 ;
F_6 ( V_7 , V_8 , V_17 & V_27 ) ;
F_8 ( V_7 , V_8 , V_17 & V_28 ) ;
F_10 ( V_7 , V_8 , V_17 & V_29 ) ;
F_12 ( V_7 , V_8 , ! ( V_17 & ( V_30 | V_29 ) ) ) ;
F_14 ( V_7 , V_8 , V_13 ) ;
F_17 ( V_7 , V_8 , V_15 ) ;
F_20 ( V_7 , V_8 , V_16 ) ;
return 0 ;
}
static int F_24 ( const int * V_31 , unsigned V_32 )
{
T_1 V_33 ;
int V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 ) {
V_34 = F_23 ( V_31 [ V_33 ] ) ;
if ( V_34 )
return V_34 ;
}
return V_34 ;
}
int F_25 ( const int * V_35 , unsigned V_32 ,
const char * V_36 )
{
int V_34 ;
V_34 = F_24 ( V_35 , V_32 ) ;
return V_34 ;
}
int T_2 F_26 ( void T_3 * V_37 , int V_38 )
{
V_2 = V_37 ;
V_25 = V_38 ;
return 0 ;
}
