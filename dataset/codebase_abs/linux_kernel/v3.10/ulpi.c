static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = 10000 ;
while ( V_3 -- ) {
T_2 V_4 = F_2 ( V_1 ) ;
if ( ! ( V_4 & V_2 ) )
return 0 ;
F_3 () ;
} ;
F_4 ( V_5 L_1 ) ;
return - V_6 ;
}
static int F_5 ( struct V_7 * V_8 , T_2 V_9 )
{
int V_10 ;
void T_1 * V_1 = V_8 -> V_11 ;
if ( ! ( F_2 ( V_1 ) & V_12 ) ) {
F_6 ( V_13 , V_1 ) ;
V_10 = F_1 ( V_1 , V_13 ) ;
if ( V_10 )
return V_10 ;
}
F_6 ( ( V_14 | ( V_9 << V_15 ) ) , V_1 ) ;
V_10 = F_1 ( V_1 , V_14 ) ;
if ( V_10 )
return V_10 ;
return ( F_2 ( V_1 ) >> V_16 ) & V_17 ;
}
static int F_7 ( struct V_7 * V_8 , T_2 V_18 , T_2 V_9 )
{
int V_10 ;
void T_1 * V_1 = V_8 -> V_11 ;
if ( ! ( F_2 ( V_1 ) & V_12 ) ) {
F_6 ( V_13 , V_1 ) ;
V_10 = F_1 ( V_1 , V_13 ) ;
if ( V_10 )
return V_10 ;
}
F_6 ( ( V_14 | V_19 |
( V_9 << V_15 ) |
( ( V_18 & V_20 ) << V_21 ) ) , V_1 ) ;
return F_1 ( V_1 , V_14 ) ;
}
struct V_7 * F_8 ( unsigned int V_22 )
{
return F_9 ( & V_23 , V_22 ) ;
}
