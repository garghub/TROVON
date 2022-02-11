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
static
int F_7 ( struct V_9 * V_10 ,
unsigned long V_11 , void * V_12 )
{
T_1 V_13 ;
F_3 ( & V_13 , V_14 ) ;
F_1 ( V_13 & 0xF0FFFFFF , V_14 ) ;
F_1 ( 1 , V_15 ) ;
return 0 ;
}
void F_8 ( int V_16 )
{
T_1 V_17 ;
F_3 ( & V_17 , V_18 ) ;
V_17 &= ~ ( V_19 << V_16 ) ;
F_1 ( V_17 , V_18 ) ;
V_17 &= ~ ( V_20 << V_16 ) ;
F_1 ( V_17 , V_18 ) ;
F_9 ( V_16 , false ) ;
}
void F_10 ( int V_16 )
{
T_1 V_17 ;
F_3 ( & V_17 , V_18 ) ;
V_17 |= ( V_20 | V_19 ) << V_16 ;
F_1 ( V_17 , V_18 ) ;
}
bool F_11 ( int V_16 )
{
T_1 V_21 ;
V_21 = F_12 ( V_22 + V_14 ) ;
V_21 &= 1 << ( 31 - V_16 ) ;
return ! V_21 ;
}
void F_9 ( int V_16 , bool V_23 )
{
T_1 V_21 , V_24 ;
V_21 = F_12 ( V_22 + V_14 ) ;
V_24 = 1 << ( 31 - V_16 ) ;
if ( V_23 )
V_21 |= V_24 ;
else
V_21 &= ~ V_24 ;
F_13 ( V_21 , V_22 + V_14 ) ;
}
int T_2 F_14 ( void )
{
struct V_25 * V_26 ;
V_26 = F_15 ( NULL , NULL , L_1 ) ;
if ( ! V_26 ) {
F_16 ( L_2 , V_27 ) ;
F_17 () ;
}
V_22 = F_18 ( V_26 , 0 ) ;
if ( ! V_22 ) {
F_16 ( L_3 , V_27 ) ;
F_17 () ;
}
V_26 -> V_12 = ( V_28 void * ) V_22 ;
V_3 = F_19 ( L_1 ) ;
if ( F_20 ( V_3 ) ) {
F_16 ( L_4 , V_27 ) ;
return - V_29 ;
}
F_5 () ;
F_21 ( V_3 , V_30 , 0x70707 , 0x20202 ) ;
F_22 ( & V_31 ) ;
F_23 ( L_5 , V_26 -> V_32 , V_22 ) ;
F_24 ( V_26 ) ;
return 0 ;
}
