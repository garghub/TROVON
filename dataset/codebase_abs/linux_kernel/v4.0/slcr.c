static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( V_3 , V_2 , V_1 ) ;
}
static int F_3 ( T_1 * V_1 , T_1 V_2 )
{
return F_4 ( V_3 , V_2 , V_1 ) ;
}
static inline int F_5 ( void )
{
F_1 ( V_4 , V_5 ) ;
return 0 ;
}
T_1 F_6 ( void )
{
T_1 V_1 ;
F_3 ( & V_1 , V_6 ) ;
V_1 >>= V_7 ;
V_1 &= V_8 ;
return V_1 ;
}
void F_7 ( void )
{
T_1 V_9 ;
F_5 () ;
F_3 ( & V_9 , V_10 ) ;
F_1 ( V_9 & 0xF0FFFFFF , V_10 ) ;
F_1 ( 1 , V_11 ) ;
}
void F_8 ( int V_12 )
{
T_1 V_13 ;
F_3 ( & V_13 , V_14 ) ;
V_13 &= ~ ( V_15 << V_12 ) ;
F_1 ( V_13 , V_14 ) ;
V_13 &= ~ ( V_16 << V_12 ) ;
F_1 ( V_13 , V_14 ) ;
F_9 ( V_12 , false ) ;
}
void F_10 ( int V_12 )
{
T_1 V_13 ;
F_3 ( & V_13 , V_14 ) ;
V_13 |= ( V_16 | V_15 ) << V_12 ;
F_1 ( V_13 , V_14 ) ;
}
bool F_11 ( int V_12 )
{
T_1 V_17 ;
V_17 = F_12 ( V_18 + V_10 ) ;
V_17 &= 1 << ( 31 - V_12 ) ;
return ! V_17 ;
}
void F_9 ( int V_12 , bool V_19 )
{
T_1 V_17 , V_20 ;
V_17 = F_12 ( V_18 + V_10 ) ;
V_20 = 1 << ( 31 - V_12 ) ;
if ( V_19 )
V_17 |= V_20 ;
else
V_17 &= ~ V_20 ;
F_13 ( V_17 , V_18 + V_10 ) ;
}
int T_2 F_14 ( void )
{
struct V_21 * V_22 ;
V_22 = F_15 ( NULL , NULL , L_1 ) ;
if ( ! V_22 ) {
F_16 ( L_2 , V_23 ) ;
F_17 () ;
}
V_18 = F_18 ( V_22 , 0 ) ;
if ( ! V_18 ) {
F_16 ( L_3 , V_23 ) ;
F_17 () ;
}
V_22 -> V_24 = ( V_25 void * ) V_18 ;
V_3 = F_19 ( L_1 ) ;
if ( F_20 ( V_3 ) ) {
F_16 ( L_4 , V_23 ) ;
return - V_26 ;
}
F_5 () ;
F_21 ( L_5 , V_22 -> V_27 , V_18 ) ;
F_22 ( V_22 ) ;
return 0 ;
}
