static int F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( ! V_3 ) {
F_2 ( V_1 , V_4 + V_2 ) ;
return 0 ;
}
return F_3 ( V_3 , V_2 , V_1 ) ;
}
static int F_4 ( T_1 * V_1 , T_1 V_2 )
{
if ( V_3 )
return F_5 ( V_3 , V_2 , V_1 ) ;
* V_1 = F_6 ( V_4 + V_2 ) ;
return 0 ;
}
static inline int F_7 ( void )
{
F_1 ( V_5 , V_6 ) ;
return 0 ;
}
T_1 F_8 ( void )
{
T_1 V_1 ;
F_4 ( & V_1 , V_7 ) ;
V_1 >>= V_8 ;
V_1 &= V_9 ;
return V_1 ;
}
void F_9 ( void )
{
T_1 V_10 ;
F_7 () ;
F_4 ( & V_10 , V_11 ) ;
F_1 ( V_10 & 0xF0FFFFFF , V_11 ) ;
F_1 ( 1 , V_12 ) ;
}
void F_10 ( int V_13 )
{
T_1 V_14 ;
F_4 ( & V_14 , V_15 ) ;
V_14 &= ~ ( V_16 << V_13 ) ;
F_1 ( V_14 , V_15 ) ;
V_14 &= ~ ( V_17 << V_13 ) ;
F_1 ( V_14 , V_15 ) ;
F_11 ( V_13 , false ) ;
}
void F_12 ( int V_13 )
{
T_1 V_14 ;
F_4 ( & V_14 , V_15 ) ;
V_14 |= ( V_17 | V_16 ) << V_13 ;
F_1 ( V_14 , V_15 ) ;
}
bool F_13 ( int V_13 )
{
T_1 V_18 ;
V_18 = F_6 ( V_4 + V_11 ) ;
V_18 &= 1 << ( 31 - V_13 ) ;
return ! V_18 ;
}
void F_11 ( int V_13 , bool V_19 )
{
T_1 V_18 , V_20 ;
V_18 = F_6 ( V_4 + V_11 ) ;
V_20 = 1 << ( 31 - V_13 ) ;
if ( V_19 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
F_2 ( V_18 , V_4 + V_11 ) ;
}
int T_2 F_14 ( void )
{
V_3 = F_15 ( L_1 ) ;
if ( F_16 ( V_3 ) ) {
F_17 ( L_2 , V_21 ) ;
return - V_22 ;
}
return 0 ;
}
int T_2 F_18 ( void )
{
struct V_23 * V_24 ;
V_24 = F_19 ( NULL , NULL , L_1 ) ;
if ( ! V_24 ) {
F_17 ( L_3 , V_21 ) ;
F_20 () ;
}
V_4 = F_21 ( V_24 , 0 ) ;
if ( ! V_4 ) {
F_17 ( L_4 , V_21 ) ;
F_20 () ;
}
V_24 -> V_25 = ( V_26 void * ) V_4 ;
F_7 () ;
F_22 ( L_5 , V_24 -> V_27 , V_4 ) ;
F_23 ( V_24 ) ;
return 0 ;
}
