static inline void F_1 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_2 ) ;
F_2 ( 0 , V_1 + V_3 ) ;
F_2 ( 0 , V_1 + V_4 ) ;
}
static inline void F_3 ( void T_1 * V_1 , bool V_5 )
{
T_2 V_6 = F_4 ( V_1 + V_2 ) ;
V_6 &= ~ V_7 ;
if ( V_5 )
V_6 |= V_8 ;
else
V_6 &= ~ V_8 ;
F_2 ( V_6 , V_1 + V_2 ) ;
}
static T_3 T_4 F_5 ( void )
{
return ( T_3 ) F_4 ( V_9 + V_3 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
F_3 ( V_12 , false ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
F_1 ( V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_9 ( unsigned long V_11 ,
struct V_10 * V_13 )
{
void T_1 * V_1 = V_12 ;
F_3 ( V_1 , false ) ;
F_2 ( V_14 , V_1 + V_2 ) ;
F_2 ( 0 , V_1 + V_3 ) ;
F_2 ( V_11 , V_1 + V_4 ) ;
F_3 ( V_1 , true ) ;
return 0 ;
}
static T_5 F_10 ( int V_15 , void * V_16 )
{
struct V_10 * V_11 = (struct V_10 * ) V_16 ;
F_2 ( V_7 , V_12 + V_2 ) ;
V_11 -> V_17 ( V_11 ) ;
return V_18 ;
}
static int T_6 F_11 ( struct V_19 * V_20 )
{
struct V_21 * V_21 ;
unsigned long V_22 ;
int V_23 , V_24 ;
V_25 = F_12 ( V_20 , 0 , L_1 ) ;
if ( F_13 ( V_25 ) ) {
F_14 ( L_2 ) ;
return F_15 ( V_25 ) ;
}
V_9 = V_25 + 0x08 ;
V_12 = V_25 + 0x14 ;
V_23 = F_16 ( V_20 , L_3 ) ;
if ( V_23 <= 0 ) {
F_14 ( L_4 ) ;
return - V_26 ;
}
V_21 = F_17 ( V_20 , 0 ) ;
if ( F_13 ( V_21 ) )
return F_15 ( V_21 ) ;
V_22 = F_18 ( V_21 ) ;
F_1 ( V_9 ) ;
F_3 ( V_9 , true ) ;
F_19 ( F_5 , 32 , V_22 ) ;
F_20 ( V_9 + V_3 , V_20 -> V_27 ,
V_22 , 200 , 32 , V_28 ) ;
F_1 ( V_12 ) ;
V_24 = F_21 ( V_23 , F_10 , V_29 ,
L_1 , & V_30 ) ;
if ( V_24 ) {
F_14 ( L_5 , V_23 ) ;
return V_24 ;
}
V_30 . V_31 = F_22 ( 0 ) ;
V_30 . V_15 = V_23 ;
F_23 ( & V_30 , V_22 ,
0xf , 0xffffffff ) ;
return 0 ;
}
