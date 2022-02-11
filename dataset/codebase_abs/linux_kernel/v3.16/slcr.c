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
}
void F_11 ( int V_13 )
{
T_1 V_14 ;
F_4 ( & V_14 , V_15 ) ;
V_14 |= ( V_17 | V_16 ) << V_13 ;
F_1 ( V_14 , V_15 ) ;
}
int T_2 F_12 ( void )
{
V_3 = F_13 ( L_1 ) ;
if ( F_14 ( V_3 ) ) {
F_15 ( L_2 , V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int T_2 F_16 ( void )
{
struct V_20 * V_21 ;
V_21 = F_17 ( NULL , NULL , L_1 ) ;
if ( ! V_21 ) {
F_15 ( L_3 , V_18 ) ;
F_18 () ;
}
V_4 = F_19 ( V_21 , 0 ) ;
if ( ! V_4 ) {
F_15 ( L_4 , V_18 ) ;
F_18 () ;
}
V_21 -> V_22 = ( V_23 void * ) V_4 ;
F_7 () ;
F_20 ( L_5 , V_21 -> V_24 , V_4 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
